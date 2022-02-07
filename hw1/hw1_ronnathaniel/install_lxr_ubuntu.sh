#!/bin/sh

# Author: Ron Nathaniel
# Course: CS 433 "Linux Kernel Programming"
# Date: Jan 27 2022


# Installing Dependencies
sudo apt update
sudo apt install -y \
  apache2 \
  ctags \
  curl \
  git-core \
  glimpse \
  libdbi-perl \
  libfile-mmagic-perl \
  libxapian15 \
  libsearch-xapian-perl \
  perl \
  postgresql-8.4 \
  postgresql-client-8.4 \

# Global Vars
LXR_V=${1:-2.0.0}
LXR_TAR_DNAME="lxr-${LXR_V}"
LXR_TAR_FNAME="${LXR_TAR_DNAME}.tgz"
LXR_TAR_URI="https://master.dl.sourceforge.net/project/lxr/stable/${LXR_TAR_FNAME}?viasf=1"

# Sequential Installation
curl -o "$LXR_TAR_FNAME" "$LXR_TAR_URI"
tar -zxf "$LXR_TAR_FNAME"
cd "$LXR_TAR_DNAME"
./genxref --checkonly
./scripts/configure-lxr.pl -vv
# Unfortunately no default option is allowed. Please follow these instructions:
# press `enter` 5x
# input `sqlite`
# input `/home/glimpse`
# press `enter` 2x
# input `CS 433 LXR`
# press `enter` 2x
# input `/home/store/src`
# press `enter` 3x
# input `v_genesis`
# press `enter` 2x
# input `lxr_master`
# input `lxrUser`
# input `lxrPass`
# press `enter`
./custom.d/initdb.sh
cp custom.d/lxr.conf .
./genxref --url=http://localhost/lxr --allversions
cp custom.d/apache-lxrserver.conf /etc/httpd/conf.d
chcon --reference /var/www/cgi-bin -R ./
echo "done."
