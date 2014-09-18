#!/usr/bin/python
#
# linearize.py:  Construct a linear, no-fork, best version of the blockchain.
#
#
# Copyright (c) 2013 The Bitcoin developers
# Copyright (c) 2014 The Ixcoin developers
# Distributed under the MIT/X11 software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
#
# A really nice aspect to this version of the linearizer, which builds your bootstrap.dat file, is that no
# knowledge of the particulars about any given coin are required.  Only that it responds on the correct port
# to getblockhash() and getblock() requests.  So it does require you have a working and running coin daemon
# such as ixcoind.exe or ixcoin-qt -server or bitcoind.exe or whatever xcoind.exe you care to use.
#
# NOTE: 9/17/2014 - This code has been ported & now runs within Python 3+ environments, originally coded for Python 2
#                   for bitcoin, and has now been upgraded for use with Ixcoin builds & releases.
#                   Allot of work 'needs' to be done, in order to have even the most elementary error handling.
#                   However, once setup correctly it will get the job done!
#

import json
import struct
import re
import base64
import http.client
import sys
import codecs

decode_hex = codecs.getdecoder("hex_codec")

ERR_SLEEP = 15
MAX_NONCE = 1000000
settings = {}


class IXCoinRPC:
    OBJID = 1

    def __init__(self, host, port, username, password):
        authpair = "%s:%s" % (username, password)
        encodeNamePass = base64.b64encode(authpair.encode('UTF-8'))
        self.authhdr = "Basic %s" % encodeNamePass.decode('UTF-8')
        self.conn = http.client.HTTPConnection(host, port, 30)

    def rpc(self, method, params = None):
        self.OBJID += 1
        obj = {'version': '1.1',
               'method': method,
               'id': self.OBJID}
        if params is None:
            obj['params'] = []
        else:
            obj['params'] = params

        jsd = json.dumps(obj)
        self.conn.request('POST', '/', jsd, {'authorization' : self.authhdr, 'Content-type' : 'application/json'})
        resp = self.conn.getresponse()
        if resp is None:
            print("JSON-RPC: no response")
            return None

        body = resp.read()
        resp_obj = json.loads(body.decode('UTF-8'))
        if resp_obj is None:
            print ("JSON-RPC: cannot JSON-decode body")
            return None
        if 'error' in resp_obj and resp_obj['error'] != None:
            return resp_obj['error']
        if 'result' not in resp_obj:
            print("JSON-RPC: no result in object")
            return None

        return resp_obj['result']

    def getblock(self, hash, verbose=True):
        return self.rpc('getblock', [hash, verbose])

    def getblockhash(self, index):
        return self.rpc('getblockhash', [index])


def getblock(rpc, settings, n):
    hash = rpc.getblockhash(n)
    hexdata = rpc.getblock(hash, False)
    return decode_hex(hexdata)[0]


def get_blocks(settings):
    rpc = IXCoinRPC(settings['host'], settings['port'],
                    settings['rpcuser'], settings['rpcpassword'])

    outf = open(settings['output'], 'ab')

    for height in range(settings['min_height'], settings['max_height'] + 1):
        data = getblock(rpc, settings, height)

        outhdr = settings['netmagic']
        outhdr += struct.pack("<i", len(data))

        outf.write(outhdr)
        outf.write(data)

        if (height % 1000) == 0:
            sys.stdout.write("Wrote block " + str(height) + "\n")


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: linearize.py CONFIG-FILE")
        sys.exit(1)

    f = open(sys.argv[1])
    for line in f:
        # skip comment lines
        m = re.search('^\s*#', line)
        if m:
            continue

        # parse key=value lines
        m = re.search('^(\w+)\s*=\s*(\S.*)$', line)
        if m is None:
            continue
        settings[m.group(1)] = m.group(2)
    f.close()

    if 'netmagic' not in settings:
        settings['netmagic'] = 'f1bab6db'
    if 'output' not in settings:
        settings['output'] = 'bootstrap.dat'
    if 'host' not in settings:
        settings['host'] = '127.0.0.1'
    if 'port' not in settings:
        settings['port'] = 8338
    if 'min_height' not in settings:
        settings['min_height'] = 0
    # max_height is set to include the 1st block after the last mined Ixcoin block has been saved.
    # As we still have 20+ days to go, this would generate an error and must be reduced until then.
    if 'max_height' not in settings:
        # settings['max_height'] = 227499
        settings['max_height'] = 223240
    if 'rpcuser' not in settings or 'rpcpassword' not in settings:
        print("Missing username and/or password in cfg file")
        sys.exit(1)

settings['netmagic'] = decode_hex(settings['netmagic'])[0]
settings['port'] = int(settings['port'])
settings['min_height'] = int(settings['min_height'])
settings['max_height'] = int(settings['max_height'])

get_blocks(settings)


