#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/ixcoin.png
ICON_DST=../../src/qt/res/icons/ixcoin.ico
convert ${ICON_SRC} -resize 16x16 ixcoin-16.png
convert ${ICON_SRC} -resize 32x32 ixcoin-32.png
convert ${ICON_SRC} -resize 48x48 ixcoin-48.png
convert ixcoin-16.png ixcoin-32.png ixcoin-48.png ${ICON_DST}

