#!/bin/bash


if [ $1 ]
then
    hexdump -e "16 \"%_p\" \"\\n\"" $1 | head -424242 -z
fi
