#!/usr/bin/sh

x=0

cat empids | while read line; do
  x=$(( x+1 ))
  # echo $line
  mkdir $line
  touch $line/readme.txt
done