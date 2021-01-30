#!/bin/bash
f=`ls |grep *\$1`
cp $f -t "$2"
