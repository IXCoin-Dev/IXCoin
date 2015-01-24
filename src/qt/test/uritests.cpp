// Copyright (c) 2011-2014 The Ixcoin Core developers
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?req-dontexist="));
    QVERIFY(!GUIUtil::parseIXCoinURI(uri, &rv));

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?dontexist="));
    QVERIFY(GUIUtil::parseIXCoinURI(uri, &rv));
    QVERIFY(rv.address == QString("xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?label=GroundRod Development Fund"));
    QVERIFY(GUIUtil::parseIXCoinURI(uri, &rv));
    QVERIFY(rv.address == QString("xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC"));
    QVERIFY(rv.label == QString("GroundRod Development Fund"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?amount=0.001"));
    QVERIFY(GUIUtil::parseIXCoinURI(uri, &rv));
    QVERIFY(rv.address == QString("xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?amount=1.001"));
    QVERIFY(GUIUtil::parseIXCoinURI(uri, &rv));
    QVERIFY(rv.address == QString("xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?amount=100&label=GroundRod Example"));
    QVERIFY(GUIUtil::parseIXCoinURI(uri, &rv));
    QVERIFY(rv.address == QString("xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("GroundRod Example"));

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?message=GroundRod Development Fund"));
    QVERIFY(GUIUtil::parseIXCoinURI(uri, &rv));
    QVERIFY(rv.address == QString("xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseIXCoinURI("ixcoin://xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?message=GroundRod Development Address", &rv));
    QVERIFY(rv.address == QString("xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?req-message=GroundRod Development"));
    QVERIFY(GUIUtil::parseIXCoinURI(uri, &rv));

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?amount=1,000&label=GroundRod Example"));
    QVERIFY(!GUIUtil::parseIXCoinURI(uri, &rv));

    uri.setUrl(QString("ixcoin:xnxZzr7KU1U6BRBqvtpdrMKv9PCMd7z2NC?amount=1,000.0&label=GroundRod Example"));
    QVERIFY(!GUIUtil::parseIXCoinURI(uri, &rv));
}
