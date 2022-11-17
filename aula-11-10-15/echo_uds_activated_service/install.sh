#!/bin/bash

ECHOD=echod_auto
ECHOD_SRC=./echo_srv.c

if [ ! -x $ECHOD ]; then
	if [ -f $ECHOD_SRC ]; then
		echo make before install!
	else
		echo wrong dir!
	fi
	exit
fi

ECHOD_DIR=/opt/$ECHOD
SYSTD_DIR=/etc/systemd/system



if [ ! -d $ECHOD_DIR ]; then
	if ! mkdir -p $ECHOD_DIR ; then
		echo Failed to create $ECHOD_DIR
		exit
	fi
fi	

cp $ECHOD $ECHOD_DIR
cp $ECHOD.service $SYSTD_DIR 
cp $ECHOD.socket $SYSTD_DIR

systemctl daemon-reload
systemctl enable $ECHOD.socket 

echo echod install done!

