#!/bin/bash

# Default configuration
CONFIG="openocd.genesys2.tcl"

# Check user input
case "$1" in
    ""|genesys2)
        CONFIG="openocd.genesys2.tcl"
        ;;
    jlink)
        CONFIG="openocd.jlink.tcl"
        ;;
    *)
        echo "Unknown option: $1"
        echo "Usage: $0 
        - genesys2  :   using digilent HS-2
        - jlink     :   using Jlink JTAG"
        exit 1
        ;;
esac

# Run OpenOCD with the chosen configuration
echo "Running OpenOCD with $CONFIG"
openocd -f "./$CONFIG"