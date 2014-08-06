// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef IXCOINADDRESSVALIDATOR_H
#define IXCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class IXCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IXCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** IXCoin address widget validator, checks for a valid ixcoin address.
 */
class IXCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IXCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // IXCOINADDRESSVALIDATOR_H
