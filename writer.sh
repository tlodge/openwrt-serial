#!/bin/bash
input="./test.txt"
while IFS= read -r line
do
  echo "$line"
  echo -e "$line" > /dev/ttyS0
done < "$input"
