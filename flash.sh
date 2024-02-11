#!/bin/sh

set -e

make splitkb/aurora/sweep/rev1:other
for i in $(seq 1 100); do
    if udisksctl mount -b /dev/disk/by-id/usb-RPI_RP2_E0C9125B0D9B-0:0-part1 ; then
        break
    fi
    echo "Mount fail $i / 100"
    sleep 1
done

make splitkb/aurora/sweep/rev1:other:flash
