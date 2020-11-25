#!/bin/bash

CRC=0xFFFF
for ((X=0; X<${#1}; X++)); do
    CHAR=$(printf '%d' "'${1:$X:1}")
    E=$(((CRC ^ CHAR) & 0xFF))
    S=$(((E << 4)     & 0xFF))
    F=$(((E ^ S)      & 0xFF))
    CRC=$(((CRC >> 8) ^ (F << 8) ^ (F << 3) ^ (F >> 4)))
done

let CRC^=0xFFFF
#printf "0x%X\n" $CRC
printf "%d\n" $CRC
