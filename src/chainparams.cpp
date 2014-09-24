// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
    0xb10f5442, 0x99e16042, 0xaac76a26, 0xb20f5442, 0x74B347CE, 0x90ccc780, 0x1586c780, 0x82153eb2, 0xbe2bf3a2
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xf9;
        pchMessageStart[1] = 0xbe;
        pchMessageStart[2] = 0xb4;
	pchMessageStart[3] = 0xd9;
	pchMessageStart2[0] = 0xf1;
	pchMessageStart2[1] = 0xba;
	pchMessageStart2[2] = 0xb6;
	pchMessageStart2[3] = 0xdb;
        vAlertPubKey = ParseHex("02a9e38d69128d1e9b689a02bb0e67927ef9aff27b62e7b0ecddec2a07ad587ad6");
        nDefaultPort = 8337;
        nRPCPort = 8338;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 32);
        nSubsidyHalvingInterval = 210000;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
		// Genesis Block:
		// CBlock(hash=00000000de13b7f748fb, ver=1, hashPrevBlock=00000000000000000000, hashMerkleRoot=764fc5f8e5, nTime=1313457620, nBits=1d00ffff, nNonce=2831549010, vtx=1)
		//   CTransaction(hash=764fc5f8e5, ver=1, vin.size=1, vout.size=1, nLockTime=0)
		//    CTxIn(COutPoint(0000000000, -1), coinbase 04ffff001d01044931352f41676f2f32303131202d2044696172696f20456c20446961202d204f62616d612063616520616c2033392520656e206c61206170726f62616369f36e20636975646164616e61)
		//    CTxOut(nValue=48.00000000, scriptPubKey=04678afdb0fe5548271967f1a67130)
		//  vMerkleTree: 764fc5f8e5
        const char* pszTimestamp = "To see the farm is to leave it";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11984") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1304113447;
        genesis.nBits    = 0x1d00ffff;
        genesis.nNonce   = 2245271137;

	hashGenesisBlock = genesis.GetHash();

	assert(hashGenesisBlock == uint256("0x0000000001534ef8893b025b9c1da67250285e35c9f76cae36a4904fdf72c591"));
        assert(genesis.hashMerkleRoot == uint256("0xcb3ae7b867c97ceb834c5d131355cd4bc176a44360fede9ed6d47b897397ba3f"));

        vSeeds.push_back(CDNSSeedData("ixcoin.co", "uk.ixcoin.co"));
	vSeeds.push_back(CDNSSeedData("ixcoin.co", "nyc.ixcoin.co"));
	vSeeds.push_back(CDNSSeedData("ixcoin.co", "sgp.ixcoin.co"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(138);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY] =     list_of(128);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("");
        nDefaultPort = 53333;
        nRPCPort = 53334;
	strDataDir = "testnet";
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 30);
        nSubsidyHalvingInterval = 210000;

        hashGenesisBlock = genesis.GetHash();
        //genesis.print();
        //assert(hashGenesisBlock == uint256("0x0000000e266692d6c16814490ca60acda9398727680325386bbdd98c61457a48")); //Old
	assert(hashGenesisBlock == uint256("0x0000000001534ef8893b025b9c1da67250285e35c9f76cae36a4904fdf72c591"));

        vSeeds.push_back(CDNSSeedData("ixcoin.co", "uk.ixcoin.co"));
        vSeeds.push_back(CDNSSeedData("ixcoin.co", "nyc.ixcoin.co"));
        vSeeds.push_back(CDNSSeedData("ixcoin.co", "sgp.ixcoin.co"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(0);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY] =     list_of(128);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;
        pchMessageStart2[0] = 0xfa;
        pchMessageStart2[1] = 0xbf;
        pchMessageStart2[2] = 0xb6;
        pchMessageStart2[3] = 0xdb;
        nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1296688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 52444;
        strDataDir = "regtest";
        //assert(hashGenesisBlock == uint256("0x0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
