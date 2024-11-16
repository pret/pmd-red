#!/bin/bash

OBJDUMP_BIN="arm-none-eabi-objdump"

OBJDUMP="$OBJDUMP_BIN -D -bbinary -marmv4t -Mforce-thumb"

if [ $(($1)) -ge $((0x8000000)) ]; then
    OPTIONS="--adjust-vma=0x8000000 --start-address=$(($1)) --stop-address=$(($1 + $2))"
else
    OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
fi

$OBJDUMP $OPTIONS baserom.gba > baserom.dump
$OBJDUMP $OPTIONS pmd_red.gba > pmd_red.dump
diff -u baserom.dump pmd_red.dump
