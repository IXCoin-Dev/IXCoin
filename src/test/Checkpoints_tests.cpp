// Copyright (c) 2011-2013 The IXCoin Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p4500 = uint256("0x00000000de37be98ca45cf0613fa2a321eba28e237543f9fee9b6a7605d03a94");
    uint256 p198007 = uint256("0x00fdfc9130416482887e4d56f89f4568c2f4d7764d14cc66833503f31a6ac73d");
    BOOST_CHECK(Checkpoints::CheckBlock(4500, p4500));
    BOOST_CHECK(Checkpoints::CheckBlock(198007, p198007));


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(4500, p198007));
    BOOST_CHECK(!Checkpoints::CheckBlock(198007, p4500));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(4500+1, p198007));
    BOOST_CHECK(Checkpoints::CheckBlock(198007+1, p4500));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 198007);
}

BOOST_AUTO_TEST_SUITE_END()
