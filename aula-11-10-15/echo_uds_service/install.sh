#!/bin/bash

ECHOD=./echod
ECHOD_SRC=./echo_srv.c

if [ ! -x $ECHOD ]; then
	if [ -f $ECHOD_SRC ]; then
		echo make before install!
	else
		echo wrong dir!
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

cp $ECHOD $ECHOD_DIR
cp $ECHOD.service $SYSTD_DIR 

#force systemd update state
systemctl daemon-reload

echo echod install done!

