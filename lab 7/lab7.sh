#!/bin/bash
echo "" > output.txt
if [ $# -eq 0 ]; then
echo " No files"
elif [ $# -gt 9 ]; then
echo " Too many arguments"
else
    for i in "$@"
    do
        if [ ! -e $i ] || [[ $i != *.txt ]]; then
            echo "invalid file extintion or file name :$i"
            exit 0
        fi
    done
fi


# PART A
no_args=0
until [ $no_args == $# ]
do
    no_args=$(( $no_args + 1 ))
    cat ${!no_args} >> output.txt
done

# PART B
no_args=$#
for i in $(seq $# -1 1);
do
    cat ${!i} >> output_rev.txt
done

