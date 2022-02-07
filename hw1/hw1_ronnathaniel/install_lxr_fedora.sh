#!/bin/sh

# Author: Ron Nathaniel
# Course: CS 433 "Linux Kernel Programming"
# Date: Jan 27 2022


sudo su
# enter pass

# Installing Dependencies fit to Fedora 15 x86-64
dnf update
dnf install -y \
  curl \
  ctags \
  git \
  libfl-dev \
  perl-DBI \
  perl-DBD-Pg \
  perl-File-MMagic-XS \
  https://download.postgresql.org/pub/repos/yum/reporpms/F-35-x86_64/pgdg-fedora-repo-latest.noarch.rpm \
  postgresql12-server \
  postgresql12


yum install -y \
  gcc \
  flex \
  kernel-devel \
  kernel-headers

git clone https://github.com/gvelez17/glimpse.git
cd glimpse
sh configure
make
make install

/usr/pgsql-12/bin/postgresql-12-setup initdb
systemctl enable --now postgresql-12
systemctl status postgresql-12
sudo su - postgres


LXR_V=${1:-2.0.0}
LXR_TAR_DNAME="lxr-${LXR_V}"
LXR_TAR_FNAME="${LXR_TAR_DNAME}.tgz"
LXR_TAR_URI="https://master.dl.sourceforge.net/project/lxr/stable/${LXR_TAR_FNAME}?viasf=1"
KERNEL_V=${2:-5.16.5}
KERNEL_TAR_DNAME="linux-${KERNEL_V}"
KERNEL_TAR_FNAME="${KERNEL_TAR_DNAME}.tar.gz"
KERNEL_DNAME="kern"
KERNEL_DPATH="/home/$(whoami)/${KERNEL_DNAME}"


# Sequential Installation
wget "https://cdn.kernel.org/pub/linux/kernel/v5.x/${KERNEL_TAR_FNAME}"
tar xJf "$KERNEL_TAR_FNAME"
mkdir -p "${KERNEL_DPATH}/v1"
mv
curl -o "$LXR_TAR_FNAME" "$LXR_TAR_URI"
tar -zxf "$LXR_TAR_FNAME"
cd "$LXR_TAR_DNAME"
./genxref --checkonly
./scripts/configure-lxr.pl -vv
cp "custom.d/lxr.conf" .

vim "/var/lib/pgsql/12/data/pg_hba.conf"
# CHANGE TOP 3 TO "md5" on right-side
sudo service postgresql-12 restart
./custom.d/initdb.sh

vim "lxr.conf"
# ADD baseurl => (the url youre passing in anyway)
# in the form of protocol://domain/path
# ADD sourceroot => $KERNEL_DPATH (paste it in from above)
./genxref --url=http://localhost/lxr --allversions --checkonly
./genxref --url=http://localhost/lxr --allversions

