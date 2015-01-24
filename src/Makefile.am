# Ixcoin edits as required to build 9.4 code,
# we don't use secp256k1 nor build univalue/ crypto/ and core/ subdirectories seperately at this time.
# As much stuff as possible commented out for now, make future upgrades easier when we go to those changes.
#
# DIST_SUBDIRS = secp256k1
DIST_SUBDIRS=
AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS)


if EMBEDDED_LEVELDB
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/include
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/helpers/memenv
LIBLEVELDB += $(builddir)/leveldb/libleveldb.a
LIBMEMENV  += $(builddir)/leveldb/libmemenv.a

# NOTE: This dependency is not strictly necessary, but without it make may try to build both in parallel, which breaks the LevelDB build system in a race
$(LIBLEVELDB): $(LIBMEMENV)

$(LIBLEVELDB) $(LIBMEMENV):
	@echo "Building LevelDB ..." && $(MAKE) -C $(@D) $(@F) CXX="$(CXX)" \
	  CC="$(CC)" PLATFORM=$(TARGET_OS) AR="$(AR)" $(LEVELDB_TARGET_FLAGS) \
          OPT="$(CXXFLAGS) $(CPPFLAGS)"
endif

IXCOIN_CONFIG_INCLUDES=-I$(builddir)/config
IXCOIN_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

#IXCOIN_INCLUDES += -I$(srcdir)/secp256k1/include

LIBIXCOIN_SERVER=libixcoin_server.a
LIBIXCOIN_WALLET=libixcoin_wallet.a
LIBIXCOIN_COMMON=libixcoin_common.a
LIBIXCOIN_CLI=libixcoin_cli.a
LIBIXCOIN_UTIL=libixcoin_util.a
#LIBIXCOIN_CRYPTO=crypto/libixcoin_crypto.a
#LIBIXCOIN_UNIVALUE=univalue/libixcoin_univalue.a
LIBIXCOINQT=qt/libixcoinqt.a
#LIBSECP256K1=secp256k1/libsecp256k1.la

#$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
#	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
noinst_LIBRARIES = \
  libixcoin_util.a \
  libixcoin_common.a \
  libixcoin_server.a \
  libixcoin_cli.a
if ENABLE_WALLET
IXCOIN_INCLUDES += $(BDB_CPPFLAGS)
noinst_LIBRARIES += libixcoin_wallet.a
endif

#if BUILD_IXCOIN_LIBS
#lib_LTLIBRARIES = libixcoinconsensus.la
#LIBIXCOIN_CONSENSUS=libixcoinconsensus.la
#else
LIBIXCOIN_CONSENSUS=
#endif

bin_PROGRAMS =
TESTS =

if BUILD_IXCOIND
  bin_PROGRAMS += ixcoind
endif

if BUILD_IXCOIN_UTILS
#  bin_PROGRAMS += ixcoin-cli ixcoin-tx
  bin_PROGRAMS += ixcoin-cli
endif

.PHONY: FORCE
# ixcoin core #
IXCOIN_CORE_H = \
  addrman.h \
  alert.h \
  allocators.h \
  base58.h \
  bignum.h \
  bloom.h \
  chainparams.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  core.h \
  crypter.h \
  db.h \
  hash.h \
  init.h \
  key.h \
  keystore.h \
  leveldbwrapper.h \
  limitedmap.h \
  main.h \
  miner.h \
  mruset.h \
  netbase.h \
  net.h \
  noui.h \
  protocol.h \
  rpcclient.h \
  rpcprotocol.h \
  rpcserver.h \
  script.h \
  serialize.h \
  sync.h \
  threadsafety.h \
  tinyformat.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  uint256.h \
  util.h \
  version.h \
  wallet.h \
  walletdb.h

JSON_H = \
  json/json_spirit.h \
  json/json_spirit_error_position.h \
  json/json_spirit_reader.h \
  json/json_spirit_reader_template.h \
  json/json_spirit_stream_reader.h \
  json/json_spirit_utils.h \
  json/json_spirit_value.h \
  json/json_spirit_writer.h \
  json/json_spirit_writer_template.h

obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
libixcoin_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between ixcoind and ixcoin-qt
libixcoin_server_a_CPPFLAGS = $(IXCOIN_INCLUDES) $(MINIUPNPC_CPPFLAGS)
libixcoin_server_a_SOURCES = \
  addrman.cpp \
  alert.cpp \
  auxpow.cpp \
  bloom.cpp \
  checkpoints.cpp \
  init.cpp \
  leveldbwrapper.cpp \
  main.cpp \
  miner.cpp \
  net.cpp \
  noui.cpp \
  rpcblockchain.cpp \
  rpcmining.cpp \
  rpcmisc.cpp \
  rpcnet.cpp \
  rpcrawtransaction.cpp \
  rpcserver.cpp \
  txdb.cpp \
  txmempool.cpp \
  $(JSON_H) \
  $(IXCOIN_CORE_H)

# wallet: shared between ixcoind and ixcoin-qt, but only linked
# when wallet enabled
libixcoin_wallet_a_CPPFLAGS = $(IXCOIN_INCLUDES)
libixcoin_wallet_a_SOURCES = \
  db.cpp \
  crypter.cpp \
  rpcdump.cpp \
  rpcwallet.cpp \
  wallet.cpp \
  walletdb.cpp \
  $(IXCOIN_CORE_H)

# crypto primitives library
#crypto_libixcoin_crypto_a_CPPFLAGS = $(IXCOIN_CONFIG_INCLUDES)
#crypto_libixcoin_crypto_a_SOURCES = \
#  crypto/sha1.cpp \
#  crypto/sha2.cpp \
#  crypto/ripemd160.cpp \
#  crypto/common.h \
#  crypto/sha2.h \
#  crypto/sha1.h \
#  crypto/ripemd160.h

# univalue JSON library
#univalue_libixcoin_univalue_a_SOURCES = \
#  univalue/univalue.cpp \
#  univalue/univalue_read.cpp \
#  univalue/univalue_write.cpp \
#  univalue/univalue_escapes.h \
#  univalue/univalue.h

# common: shared between ixcoind, and ixcoin-qt and non-server tools
libixcoin_common_a_CPPFLAGS = $(IXCOIN_INCLUDES)
libixcoin_common_a_SOURCES = \
  allocators.cpp \
  auxpow.cpp \
  base58.cpp \
  chainparams.cpp \
  coins.cpp \
  core.cpp \
  hash.cpp \
  key.cpp \
  keystore.cpp \
  netbase.cpp \
  protocol.cpp \
  script.cpp \
  $(IXCOIN_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libixcoin_util_a_CPPFLAGS = $(IXCOIN_INCLUDES)
libixcoin_util_a_SOURCES = \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  clientversion.cpp \
  rpcprotocol.cpp \
  sync.cpp \
  util.cpp \
  $(IXCOIN_CORE_H)

if GLIBC_BACK_COMPAT
libixcoin_util_a_SOURCES += compat/glibc_compat.cpp
libixcoin_util_a_SOURCES += compat/glibcxx_compat.cpp
endif

# cli: shared between ixcoin-cli and ixcoin-qt
libixcoin_cli_a_CPPFLAGS = $(IXCOIN_INCLUDES)
libixcoin_cli_a_SOURCES = \
  rpcclient.cpp \
  $(IXCOIN_CORE_H)

nodist_libixcoin_util_a_SOURCES = $(srcdir)/obj/build.h
#

# ixcoind binary #
ixcoind_LDADD = \
  $(LIBIXCOIN_CLI) \
  $(LIBIXCOIN_SERVER) \
  $(LIBIXCOIN_COMMON) \
  $(LIBIXCOIN_UTIL) \
  $(LIBLEVELDB) \
  $(LIBMEMENV)

if ENABLE_WALLET
ixcoind_LDADD += libixcoin_wallet.a
endif
ixcoind_SOURCES = ixcoind.cpp
#

if TARGET_WINDOWS
ixcoind_SOURCES += ixcoind-res.rc
endif

ixcoind_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS)
ixcoind_CPPFLAGS = $(IXCOIN_INCLUDES)
ixcoind_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

# ixcoin-cli binary #
ixcoin_cli_LDADD = \
  $(LIBIXCOIN_CLI) \
  $(LIBIXCOIN_COMMON) \
  $(LIBIXCOIN_UTIL) \
  $(BOOST_LIBS) \
  $(SSL_LIBS) \
  $(CRYPTO_LIBS)

ixcoin_cli_SOURCES = \
  ixcoin-cli.cpp

ixcoin_cli_CPPFLAGS = $(IXCOIN_INCLUDES)
#

# ixcoin-tx binary #
#ixcoin_tx_LDADD = \
#  $(LIBBITCOIN_UNIVALUE) \
#  $(LIBBITCOIN_COMMON) \
#  $(LIBBITCOIN_UTIL) \
#  $(LIBBITCOIN_CRYPTO) \
#  $(LIBSECP256K1) \
#  $(BOOST_LIBS) \
#  $(CRYPTO_LIBS)

#ixcoin_tx_SOURCES = ixcoin-tx.cpp
#ixcoin_tx_CPPFLAGS = $(IXCOIN_INCLUDES)
#
#ixcoin_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
ixcoin_cli_SOURCES += ixcoin-cli-res.rc
endif
ixcoin_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

#if BUILD_IXCOIN_LIBS
#include_HEADERS = script/ixcoinconsensus.h
#libixcoinconsensus_la_SOURCES = \
#  core/transaction.cpp \
#  crypto/sha1.cpp \
#  crypto/sha2.cpp \
#  crypto/ripemd160.cpp \
#  eccryptoverify.cpp \
#  ecwrapper.cpp \
#  hash.cpp \
#  pubkey.cpp \
#  script/script.cpp \
#  script/interpreter.cpp \
#  script/ixcoinconsensus.cpp \
#  uint256.cpp \
#  utilstrencodings.cpp

#if GLIBC_BACK_COMPAT
#  libixcoinconsensus_la_SOURCES += compat/glibc_compat.cpp
#  libixcoinconsensus_la_SOURCES += compat/glibcxx_compat.cpp
#endif

#libixcoinconsensus_la_LDFLAGS = -no-undefined $(RELDFLAGS)
#libixcoinconsensus_la_LIBADD = $(CRYPTO_LIBS)
#libixcoinconsensus_la_CPPFLAGS = $(CRYPTO_CFLAGS) -I$(builddir)/obj -DBUILD_IXCOIN_INTERNAL
#if USE_LIBSECP256K1
#libixcoinconsensus_la_LIBADD += secp256k1/libsecp256k1.la
#endif
#endif

CLEANFILES = leveldb/libleveldb.a leveldb/libmemenv.a *.gcda *.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb

clean-local:
	-$(MAKE) -C leveldb clean
#	-$(MAKE) -C secp256k1 clean
	rm -f leveldb/*/*.gcno leveldb/helpers/memenv/*.gcno
	-rm -f config.h

.rc.o:
	@test -f $(WINDRES)
	$(AM_V_GEN) $(WINDRES) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(CXXFLAGS)  -c -o $@ $<

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
#include Makefile.qttest.include
endif
