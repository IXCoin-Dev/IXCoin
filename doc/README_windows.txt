IXCoin 0.9.2.1 Pre-Release Test Build

Copyright (c) 2011-2014 IXCoin Core Developers

Distributed under the MIT/X11 software license, see the accompanying
file COPYING or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).  This product includes
cryptographic software written by Eric Young (eay@cryptsoft.com).


Intro
-----
IXCoin is a free open source peer-to-peer electronic cash system that is
completely decentralized, without the need for a central server or trusted
parties.  Users hold the crypto keys to their own money and transact directly
with each other, with the help of a P2P network to check for double-spending.


Setup
-----
Either via an ixcoin-win32-setup installer or by manually doing the
following steps, you will need to Unpack the files into a directory and create
a simple set of shortcuts in your START menu, on your desktop or in your toolbar,
in order to run ixcoin-qt.exe whenever you need to use the network.  The
installer also adds an uninstaller shortcut to your START menu list.

IXCoin Core is the updated version of the original IXCoin client, it builds
the backbone of the network, and now has many advanced features.  It does
however, need to download and stores the entire history of IXCoin transactions;
depending on the speed of your computer and network connection, that
synchronization process can take anywhere from a few hours to a day or more.
In order to expedite this process, we've created a current bootstrap.dat file,
which when compressed, is a relatively small file of just over 150MB's in
size.  For over 3 years/15 weeks of transaction history, that is really small.
Place that in your newly initialized Ixcoin data directory and it will import
nearly all the past transaction history in just a few minutes.

As Ixcoin is very similar, the Best source of information can be found on the
Bitcoin wiki at:
  https://en.Bitcoin.it/wiki/Main_Page
for more help and information.
