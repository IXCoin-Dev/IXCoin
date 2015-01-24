#!/bin/sh
set -e
srcdir="$(dirname $0)"
cd "$srcdir"
if [ -z ${LIBTOOLIZE} ] && GLIBTOOLIZE="`which glibtoolize 2>/dev/null`"; then
  LIBTOOLIZE="${GLIBTOOLIZE}"
  export LIBTOOLIZE
fi
# This command has been known to clear out problems
# autoreconf --install --force --symlink --warnings=all
autoreconf --install --force --warnings=all

