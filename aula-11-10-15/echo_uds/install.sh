#!/bin/bash

ECHOD_EXE=./echod
ECHOD_SRC=./echo_srv.c

if [ ! -x $ECHOD_EXE ]; then
	if [ ! -f $ECHOD_SRC ]; then
		echo wromg directory!
	else
		echo make before install!
	fi
	exit
fi

ECHOD_DIR=/opt/echod
SYSTD_DIR=/etc/systemd/system

mkdir -p $ECHOD_DIR

if [ ! -d $ECHOD_DIR ]; then
	echo Failed to create $ECHOD_DIR
	exit
fi	

cp $ECHOD_EXE $ECHOD_DIR

echo echod install done!

