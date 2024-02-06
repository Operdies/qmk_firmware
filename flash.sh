#!/bin/sh

set -e

make splitkb/aurora/sweep/rev1:other
udisksctl mount -b /dev/disk/by-id/usb-RPI_RP2_E0C9125B0D9B-0:0-part1
make splitkb/aurora/sweep/rev1:other:flash
