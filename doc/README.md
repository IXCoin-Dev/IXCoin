IXCoin 0.9.2 BETA
=====================

Copyright (c) 2009-2014 Bitcoin Developers


Setup
---------------------
[IXCoin Core](http://bitcoin.org/en/download) is the original IXCoin client and it builds the backbone of the network. However, it downloads and stores the entire history of IXCoin transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. If you would like the process to go faster you can [download the blockchain directly](bootstrap.md).

Running
---------------------
The following are some helpful notes on how to run IXCoin on your native platform. 

### Unix

You need the Qt4 run-time libraries to run IXCoin-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/ixcoin-qt (GUI, 32-bit) or bin/32/ixcoind (headless, 32-bit)
- bin/64/ixcoin-qt (GUI, 64-bit) or bin/64/ixcoind (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run ixcoin-qt.exe.

### OSX

Drag IXCoin-Qt to your applications folder, and then run IXCoin-Qt.

### Need Help?

* See the documentation at the [IXCoin Wiki](https://en.ixcoin.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#ixcoin](http://webchat.freenode.net?channels=ixcoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=ixcoin).
* Ask for help on the [IXCoinTalk](https://ixcointalk.org/) forums, in the [Technical Support board](https://ixcointalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build IXCoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------
The IXCoin repo's [root README](https://github.com/ixcoin/ixcoin/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/ixcoin/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [IXCoinTalk](https://ixcointalk.org/) forums, in the [Development & Technical Discussion board](https://ixcointalk.org/index.php?board=6.0).
* Discuss on [#ixcoin-dev](http://webchat.freenode.net/?channels=ixcoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=ixcoin-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
