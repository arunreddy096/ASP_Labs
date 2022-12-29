#!/bin/bash
file="sample.txt"
if [ ! -e $file ]; then
    echo "Sorry, $file does not exist."
    touch $file
elif [ -O $file ]; then
    if [ ! -w $file ]; then
        echo "no write permission on $file"
        chmod u+w $file #(grant write permission)
        echo " write permission granted"
        ls >> $file
        echo "input appended"
    else
        ls >> $file
        echo "input appended"

    fi
else
    echo "you don't own this file, so Write permission cannot be granted "
fi
