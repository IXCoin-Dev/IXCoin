include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = ixcoin-qt
noinst_LIBRARIES = libixcoinqt.a
SUBDIRS = . $(BUILD_TEST_QT)
DIST_SUBDIRS = . test

# ixcoin qt core #
QT_TS = \
  locale/ixcoin_ach.ts \
  locale/ixcoin_af_ZA.ts \
  locale/ixcoin_ar.ts \
  locale/ixcoin_be_BY.ts \
  locale/ixcoin_bg.ts \
  locale/ixcoin_bs.ts \
  locale/ixcoin_ca_ES.ts \
  locale/ixcoin_ca.ts \
  locale/ixcoin_ca@valencia.ts \
  locale/ixcoin_cmn.ts \
  locale/ixcoin_cs.ts \
  locale/ixcoin_cy.ts \
  locale/ixcoin_da.ts \
  locale/ixcoin_de.ts \
  locale/ixcoin_el_GR.ts \
  locale/ixcoin_en.ts \
  locale/ixcoin_eo.ts \
  locale/ixcoin_es_CL.ts \
  locale/ixcoin_es_DO.ts \
  locale/ixcoin_es_MX.ts \
  locale/ixcoin_es.ts \
  locale/ixcoin_es_UY.ts \
  locale/ixcoin_et.ts \
  locale/ixcoin_eu_ES.ts \
  locale/ixcoin_fa_IR.ts \
  locale/ixcoin_fa.ts \
  locale/ixcoin_fi.ts \
  locale/ixcoin_fr_CA.ts \
  locale/ixcoin_fr.ts \
  locale/ixcoin_gl.ts \
  locale/ixcoin_gu_IN.ts \
  locale/ixcoin_he.ts \
  locale/ixcoin_hi_IN.ts \
  locale/ixcoin_hr.ts \
  locale/ixcoin_hu.ts \
  locale/ixcoin_id_ID.ts \
  locale/ixcoin_it.ts \
  locale/ixcoin_ja.ts \
  locale/ixcoin_ka.ts \
  locale/ixcoin_kk_KZ.ts \
  locale/ixcoin_ko_KR.ts \
  locale/ixcoin_ky.ts \
  locale/ixcoin_la.ts \
  locale/ixcoin_lt.ts \
  locale/ixcoin_lv_LV.ts \
  locale/ixcoin_mn.ts \
  locale/ixcoin_ms_MY.ts \
  locale/ixcoin_nb.ts \
  locale/ixcoin_nl.ts \
  locale/ixcoin_pam.ts \
  locale/ixcoin_pl.ts \
  locale/ixcoin_pt_BR.ts \
  locale/ixcoin_pt_PT.ts \
  locale/ixcoin_ro_RO.ts \
  locale/ixcoin_ru.ts \
  locale/ixcoin_sah.ts \
  locale/ixcoin_sk.ts \
  locale/ixcoin_sl_SI.ts \
  locale/ixcoin_sq.ts \
  locale/ixcoin_sr.ts \
  locale/ixcoin_sv.ts \
  locale/ixcoin_th_TH.ts \
  locale/ixcoin_tr.ts \
  locale/ixcoin_uk.ts \
  locale/ixcoin_ur_PK.ts \
  locale/ixcoin_uz@Cyrl.ts \
  locale/ixcoin_vi.ts \
  locale/ixcoin_vi_VN.ts \
  locale/ixcoin_zh_CN.ts \
  locale/ixcoin_zh_HK.ts \
  locale/ixcoin_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_ixcoinaddressvalidator.cpp \
  moc_ixcoinamountfield.cpp \
  moc_ixcoingui.cpp \
  moc_ixcoinunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp

IXCOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  ixcoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_ixcoin.cpp
QT_QRC = ixcoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

IXCOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  ixcoinaddressvalidator.h \
  ixcoinamountfield.h \
  ixcoingui.h \
  ixcoinunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h \
  winshutdownmonitor.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/ixcoin.ico \
  res/icons/ixcoin.png \
  res/icons/ixcoin_testnet.ico \
  res/icons/ixcoin_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png

IXCOIN_QT_CPP = \
  ixcoin.cpp \
  ixcoinaddressvalidator.cpp \
  ixcoinamountfield.cpp \
  ixcoingui.cpp \
  ixcoinunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp \
  winshutdownmonitor.cpp

if ENABLE_WALLET
IXCOIN_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  paymentserver.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsdialog.cpp \
  sendcoinsentry.cpp \
  signverifymessagedialog.cpp \
  transactiondesc.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactionrecord.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  walletframe.cpp \
  walletmodel.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

IXCOIN_RC = res/ixcoin-qt-res.rc

libixcoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libixcoinqt_a_SOURCES = $(IXCOIN_QT_CPP) $(IXCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libixcoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libixcoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# ixcoin-qt binary #
ixcoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
ixcoin_qt_SOURCES = ixcoin.cpp
if TARGET_DARWIN
  ixcoin_qt_SOURCES += $(IXCOIN_MM)
endif
if TARGET_WINDOWS
  ixcoin_qt_SOURCES += $(IXCOIN_RC)
endif
ixcoin_qt_LDADD = libixcoinqt.a $(LIBIXCOIN_SERVER)
if ENABLE_WALLET
ixcoin_qt_LDADD += $(LIBIXCOIN_WALLET)
endif
ixcoin_qt_LDADD += $(LIBIXCOIN_CLI) $(LIBIXCOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
ixcoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

ixcoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/ixcoinstrings.cpp

translate: ixcoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(IXCOIN_QT_CPP) $(IXCOIN_QT_H) $(IXCOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/ixcoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name ixcoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -e '/^\*\*.*Created:/d' $@ > $@.n && mv $@{.n,}
	$(SED) -e '/^\*\*.*by:/d' $@  > $@.n && mv $@{.n,}

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
