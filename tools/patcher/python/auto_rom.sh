#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Usage:\t <.PG4 file> <ROM NAME>"
    exit 1
fi

python3 ./pgt_replacer.py ./rom.nds $1 $2

if [ $? -ne 0 ]
then
    echo "Failed to change the rom file"
    exit 1
fi

foo="$2.nds"

./send_to_sd.sh $foo

if [ $? -ne 0 ]
then
    echo "Failed to move the rom"
    rm $foo
    exit 1
fi

echo "Succesfully moved rom to SD card"
