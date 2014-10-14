#ifndef CLIENTVERSION_H
#define CLIENTVERSION_H

#if defined(HAVE_CONFIG_H)
#include "ixcoin-config.h"

// GR Note: These are needed to build the ixcoind-res.rc object file,
// manually keep these the same as the rest of your build process!
// See configure.ac, to set these values up, as the ixcoin-config.h
// file, used in compiling the source files, is built with the values
// defined there, not here.
//
#else
//
// client versioning and copyright year
//

// These need to be macros, as version.cpp's and ixcoin-qt.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR       0
#define CLIENT_VERSION_MINOR       9
#define CLIENT_VERSION_REVISION    3
#define CLIENT_VERSION_BUILD       0

// Set to true for release, false for prerelease or test build
#define CLIENT_VERSION_IS_RELEASE  false

// Copyright year (2011-this)
// Todo: update this when changing our copyright comments in the source
#define COPYRIGHT_YEAR 2014

#endif //HAVE_CONFIG_H

// Converts the parameter X to a string after macro replacement on X has been performed.
// Don't merge these into one macro!
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

#endif // CLIENTVERSION_H
