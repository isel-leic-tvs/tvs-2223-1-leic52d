#!/bin/bash

ECHOD=echod
ECHOD_DIR=/opt/$ECHOD
SYSTD_DIR=/etc/systemd/system
 
if [ ! -d $ECHOD_DIR ]; then
	echo Inexistent $ECHOD_DIR
	exit
fi	


#terminate server if it is active

if [ -f $ECHOD_DIR/$ECHOD.pid ]
then
	PID=`cat $ECHOD_DIR/$ECHOD.pid`
	if ps -p $PID > /dev/null ; then	
		kill $PID
		while ps -p $PID > /dev/null 
		do
			sleep 1
		done
	fi
fi
	

rm -rf $ECHOD_DIR

#force systemd update state
systemctl daemon-reload

echo echod uninstall done!

