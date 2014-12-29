// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin Core developers
// Copyright (c) 2011-2014 The Ixcoin Core developers

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
    0xb10f5442, 0x99e16042, 0xaac76a26, 0xb20f5442, 0x74B347CE, 0x90ccc780, 0x1586c780, 0x82153eb2,
    0xb73c9ac6, 0x4924a0a7, 0xe8b1e2bc, 0x1608b8d5, 0x0a68a844, 0xe06b9f55, 0x54c0ae4c, 0x73589bc0,
    0xd667008d, 0x989eb643, 0xcdaa3d6c, 0x593bd162, 0x22550905, 0x0ee8b849, 0x7225aa6c, 0xeb14f8b4,
    0x83440e74, 0xbe2bf3a2, 0xb10f5442, 0x99e16042, 0xaac76a26, 0xb20f5442, 0x74B347CE, 0xaf282218, 
    0x47d0048e, 0x35942a18, 0x59d74eb8, 0x30a74b3e, 0xb078a353, 0x2254cb7b, 0xc1d05d56, 0x07f01f3e,
    0xd712a246, 0xd820c3d2, 0x7d98154c, 0xe9897f2e, 0xe06b9f55, 0xc5da47c0, 0xd6814bbb, 0xa0cc317a,
    0xa4d33c50, 0x641f664d, 0xd6a14952, 0xed0b95c1, 0x59d74eb8, 0x74b347ce, 0x0a68a844, 0xcd717b80,
    0x22550905, 0x4924a0a7, 0xc8fed536, 0xe8b1e2bc, 0x4e59a263, 0x07f01f3e, 0x4adba445, 0xc1d05d56,
    0x0f2f916d, 0x67d51955, 0x61a8de9e, 0x09a16265, 0x8706cf45, 0x7225aa6c, 0xaf282218, 0x47d0048e,
    0x35942a18, 0x59d74eb8, 0x30a74b3e, 0xb078a353, 0x2254cb7b, 

};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        // They are the same 4 bytes used in previous Ixcoin 0.3.24 and 0.8.6 versions
        // MessageStart values from before 9/1/2011 were the same as Bitcoin, and are no longer needed between nodes to communicate.
        pchMessageStart[0] = 0xf1;
        pchMessageStart[1] = 0xba;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;
        //
        // Starting with Ixcoin v0.9.2.1, the following vAlertPubKey ECDSA (Ecliptical Curve DSA) hex value will be used
        // The private key is not publicly available. This allows only a small group to generate Alert messages on the IXCoin Network:  
        // As of 10/10/2014  Holders of the private key are: AhmedBodi, GroundRod & Cinnamon_Carter representing the IXCoin Foundation.
        // If an alert is necessary or desired, it can be used to inform all nodes of an important chain development or software upgrade
        //
        vAlertPubKey = ParseHex("046bcc6984f841c35686e7b9ed7b2ce5b2f4cc8b8a5ef314870e623566f8b8f9d0d7b906c4537c0d5ca55c53b9e2d38834d7c5e5846c50bdced192c105cc83a589");
        
        nDefaultPort = 8337;
        nRPCPort = 8338;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 32);
        nSubsidyHalvingInterval = 210000;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        // Genesis Block:
        // CBlock(hash=00000000de13b7f748fb, ver=1, hashPrevBlock=00000000000000000000, hashMerkleRoot=764fc5f8e5, nTime=1313457620, nBits=1d00ffff, nNonce=2831549010, vtx=1)
        // CTransaction(hash=764fc5f8e5, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        // CTxIn(COutPoint(0000000000, -1), coinbase 04ffff001d01044931352f41676f2f32303131202d2044696172696f20456c20446961202d204f62616d612063616520616c2033392520656e206c61206170726f62616369f36e20636975646164616e61)
        // CTxOut(nValue=48.00000000, scriptPubKey=04678afdb0fe5548271967f1a67130)
        // vMerkleTree: 764fc5f8e5
        //
        const char* pszTimestamp = "To see the farm is to leave it";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
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
// Testnet (v1) for Ixcoin
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // They are the same 4 bytes that were used in previous Ixcoin 0.3.24 and 0.8.6 versions
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;

        vAlertPubKey = ParseHex("04de6b00e3294afc25e03eead3fdb7b0dc9ebdf972625e40d79df84766c96a6ddfe8ae702c71f073ffa74fe69effd61ff7b27e8ceae2ac780cc786c278b270cffc");
        // Use this Private key for testnet 'sendalert' commands
        // "308201130201010420792aeda8e312f4e1b26861e3d16a19cd01b45c5531c1d90a9d180335a28d3bc0a081a53081a2020101302c06072a8648ce3d0101022100fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f300604010004010704410479be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8022100fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141020101a14403420004de6b00e3294afc25e03eead3fdb7b0dc9ebdf972625e40d79df84766c96a6ddfe8ae702c71f073ffa74fe69effd61ff7b27e8ceae2ac780cc786c278b270cffc"
        
        nDefaultPort = 18337;                           // Same port as previous Ixcoin versions
        nRPCPort = 18336;
        strDataDir = "testnet";
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 30);
        nSubsidyHalvingInterval = 210000;

        hashGenesisBlock = genesis.GetHash();
        //genesis.print();        
        assert(hashGenesisBlock == uint256("0x0000000001534ef8893b025b9c1da67250285e35c9f76cae36a4904fdf72c591"));

        vFixedSeeds.clear();
        vSeeds.clear();
        // vSeeds.push_back(CDNSSeedData("ixcoin.co", "uk.ixcoin.co"));
        // vSeeds.push_back(CDNSSeedData("ixcoin.co", "nyc.ixcoin.co"));
        // vSeeds.push_back(CDNSSeedData("ixcoin.co", "sgp.ixcoin.co"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(111);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        base58Prefixes[SECRET_KEY] =     list_of(239);
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
        // The message start string is designed to be unlikely to occur in normal data.
        // They are new, starting with version 0.9.3 builds, before than this test did not exist.
        pchMessageStart[0] = 0xfb;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;

        nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1296688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18447;
        strDataDir = "regtest";
        // genesis.print();
        assert(hashGenesisBlock == uint256("0x1e2749a69baaf13a0421321e109c3873e4f90690bec49f80a6dae39fc0f35d26"));
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
