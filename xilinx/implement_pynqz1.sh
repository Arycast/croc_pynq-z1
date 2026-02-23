#!/bin/bash

# bender script vivado -t fpga -t rtl -t pynqz1 > scripts/add_sources.pynqz1.tcl
mkdir -p build/pynqz1.clkwiz
cd build/pynqz1.clkwiz && \
    vivado -mode batch -log ../pynqz1.clkwiz.log -jou ../pynqz1.clkwiz.jou \
    -source ../../scripts/impl_ip_pynqz1.tcl \
    -tclargs pynqz1 clkwiz \
    && cd ../..
mkdir -p build/pynqz1.vio
cd build/pynqz1.vio &&
    vivado -mode batch -log ../pynqz1.vio.log -jou ../pynqz1.vio.jou \
    -source ../../scripts/impl_ip_pynqz1.tcl \
    -tclargs pynqz1 vio\
    && cd ../..
mkdir -p build/pynqz1.croc
cd build/pynqz1.croc && \
    vivado -mode batch -log ../croc.pynqz1.log -jou ../croc.pynqz1.jou \
    -source ../../scripts/impl_sys.tcl \
    -tclargs pynqz1 croc \
    ../pynqz1.clkwiz/out.xci \
    ../pynqz1.vio/out.xci
