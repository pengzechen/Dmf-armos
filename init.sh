#!/bin/sh

echo "Loading, please wait..."

export PATH="/bin:/sbin"

[ -d /dev ] || mkdir -m 0755 /dev
[ -d /root ] || mkdir --mode=0700 /root
[ -d /sys ] || mkdir /sys
[ -d /proc ] || mkdir /proc
[ -d /tmp ] || mkdir /tmp
[ -d /mnt ] || mkdir /mnt

# Mount /proc and /sys:
mount -n proc /proc -t proc
mount -n sysfs /sys -t sysfs

# Note that this only becomes /dev on the real filesystem if udev's scripts
# are used; which they will be, but it's worth pointing out
#mount -t tmpfs -o mode=0755 udev /dev
[ -e /dev/console ] || mknod /dev/console c 5 1
[ -e /dev/null ] || mknod /dev/null c 1 3

# echo /sbin/mdev >/proc/sys/kernel/hotplug
# mdev -s

# Get real root device by LABEL or UUID
get_root() {
    if [ ! -z "$LABEL" ]; then
        ROOT=`blkid | sed -n "/$LABEL/p" | cut -d: -f 1`
    fi
    if [ ! -z "$UUID" ]; then
        ROOT=`blkid | sed -n "/$UUID/p" | cut -d: -f 1`
    fi
}

if [ -e /mnt/sbin/init ] ;
then
    umount /proc
    umount /sys
    exec switch_root /mnt /sbin/init $RUNLEVEL
fi

/bin/sh -i