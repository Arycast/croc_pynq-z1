#!/bin/bash

# Arguments
GDB_BIN_PATH="$1"
TARGET="$2"

# Check arguments
if [ -z "$TARGET" ] || [ -z "$GDB_BIN_PATH" ]; then
    echo "Usage: $0 <gdb_bin_path> <program>"
    exit 1
fi

# Full path to GDB executable
GDB_EXEC="$GDB_BIN_PATH/riscv32-unknown-elf-gdb"

# Validate GDB exists
if [ ! -x "$GDB_EXEC" ]; then
    echo "Error: GDB not found or not executable at $GDB_EXEC"
    exit 1
fi

# Run GDB
"$GDB_EXEC" \
    --ex "target remote localhost:3333" \
    --ex "load" \
    --ex "monitor reset halt" \
    --ex "continue" \
    "$TARGET"
