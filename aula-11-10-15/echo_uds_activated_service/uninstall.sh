#!/bin/bash

ECHOD=echod
ECHOD_DIR=/opt/$ECHOD
SYSTD_DIR=/etc/systemd/system
 
if [ ! -d $ECHOD_DIR ]; then
	echo Inexistent $ECHOD_DIR
	exit
fi	


#terminate server if exists

if systemctl is-active $ECHOD ; then
	systemctl stop echod
fi	

systemctl disable $ECHOD.socket
 

rm -rf $ECHOD_DIR
rm -f  $SYSTD_DIR/$ECHOD.service  
rm -f  $SYSTD_DIR/$ECHOD.socket
  
echo echod uninstall done!

 
