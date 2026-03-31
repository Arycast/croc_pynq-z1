#!/bin/bash

# Path to your GDB binary
GDB_BIN_PATH="/home/fauzan/pau/riscv-gnu-toolchain/bin"

# Name of the program to debug (pass as first argument)
TARGET="$1"

# Check if a target was provided
if [ -z "$TARGET" ]; then
    echo "Usage: $0 <program>"
    exit 1
fi

# Run GDB
"$GDB_BIN_PATH"/riscv32-unknown-elf-gdb \
    --ex "target remote localhost:3333" \
    --ex "load" \
    --ex "monitor reset halt" \
    --ex "continue" \
    "$TARGET"