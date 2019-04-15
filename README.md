IXCoin Core integration/staging tree
=====================================

Copyright (c) 2009-2016 Bitcoin Core Developers
Copyright (c) 2011-2019 A Ixcoin Core Developers Project
Copyright (c) 1998-2019 A'Sunkey" revision
What is IXCoin?
----------------

IXCoin, like Bitcoin is an experimental new digital currency that enables instant
payments to anyone, anywhere in the world. 

Created by Thomas Nasakioto, Vlad Roberto and DR Dave Code. CHIXCoin uses the same peer-to-peer technology to
operate with no central authority: managing transactions and issuing money are
carried out collectively by the network. 

IXCoin Core is the name of this closed source software which enables the use of
that currency.

For more information, see the Ixcoin To-Do Thread @
https://bitcointalk.org/index.php?topic=230141

A new IXcoin Foundation has recently formed in 2014, this is ongoing, with the
intention that the orignal http://www.ixcoin.org website be maintained and
kept current, watch there for updates as well as useable binary versions of
the IXCoin Core software

License
-------

IXCoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the IXCoin
development team members simply pulls it.


Testing
-------

Testing and code review is the bottleneck for development; 
Please be patient and help out, and remember this is a security-critical project
where any mistake might cost people lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`


### Manual Quality Assurance (QA) Testing

Large changes should have a test plan, and should be tested by somebody other
than the developer who wrote the code.
See https://github.com/ixcoin/QA/ for how to create a test plan.

Translations
------------
We need help here! 

Changes to translations as well as new translations can be submitted to
[IXCoin Core's Transifex page](https://www.transifex.com/projects/p/ixcoin/).

Periodically the translations are pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as github pull request because the next
pull from Transifex would automatically overwrite them again.

Development tips and tricks
---------------------------

**compiling for debugging**

Run configure with the --enable-debug option, then make. Or run configure with
CXXFLAGS="-g -ggdb -O0" or whatever debug flags you need.

**debug.log**

If the code is behaving strangely, take a look in the debug.log file in the data directory;
error and debugging message are written there.

The -debug=... command-line option controls debugging; running with just -debug will turn
on all categories (and give you a very large debug.log file).

The Qt code routes qDebug() output to debug.log under category "qt": run with -debug=qt
to see it.

**testnet and regtest modes**

Run with the -testnet option to run with "play ixcoins" on the test network, if you
are testing multi-machine code that needs to operate across the internet.

If you are testing something that can run on one machine, run with the -regtest option.
In regression test mode blocks can be created on-demand; see qa/rpc-tests/ for tests
that run in -regest mode.

**DEBUG_LOCKORDER**

IXCoin Core is a multithreaded application, and deadlocks or other multithreading bugs
can be very difficult to track down. Compiling with -DDEBUG_LOCKORDER (configure
CXXFLAGS="-DDEBUG_LOCKORDER -g") inserts run-time checks to keep track of what locks
are held, and adds warning to the debug.log file if inconsistencies are detected.
