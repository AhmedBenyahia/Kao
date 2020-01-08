#!/bin/sh
gcc `pkg-config --cflags gtk+-2.0` -o multi multiple.c `pkg-config --libs gtk+-2.0`

