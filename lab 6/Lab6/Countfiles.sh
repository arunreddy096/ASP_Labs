#!/bin/bash

if [ -z "$2" ];
  then
    ls -l . | egrep -c '^-'
else
    ls -l $1 | grep $2 | wc -l
fi
