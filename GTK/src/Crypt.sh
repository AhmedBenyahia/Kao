#!/bin/bash
function crypt(){
if [ -e ../Data.txt ];
then
	gpg -c Data.txt
	mv Data.txt .Data.txt
fi

}

crypt
