
Debian
====================
This directory contains files used to package ixcoind/ixcoin-qt
for Debian-based Linux systems. If you compile ixcoind/ixcoin-qt yourself, there are some useful files here.

## ixcoin: URI support ##


ixcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ixcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ixcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/ixcoin128.png` to `/usr/share/pixmaps`

ixcoin-qt.protocol (KDE)

