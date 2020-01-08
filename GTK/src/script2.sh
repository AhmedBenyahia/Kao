#!/bin/sh
gcc `pkg-config --cflags gtk+-2.0` -o multiple.c mult `pkg-config --libs gtk+-2.0`

