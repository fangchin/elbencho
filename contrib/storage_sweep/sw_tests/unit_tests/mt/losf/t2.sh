#!/bin/bash

echo "A. Use the structure of the wrapper ..."
cmd="elbencho --dirsharing -w -t 56 --nolive "
cmd+="-F -d -n 1 -N 18725 "
cmd+="-s 512k --trunctosize "
cmd+="-b 16m --direct --dropcache --nodelerr ./1048576x512KiB"
$cmd

echo "B. Run the command directly ..."
echo "The command to execute..."
echo "elbencho --dirsharing -w -t 56 --nolive -F -d -n 1 -N 18725 -s 512k --trunctosize -b 16m --direct --dropcache --nodelerr  ./1048576x512KiB"
elbencho --dirsharing -w -t 56 --nolive -F -d -n 1 -N 18725 -s 512k --trunctosize -b 16m --direct --dropcache --nodelerr  ./1048576x512KiB
