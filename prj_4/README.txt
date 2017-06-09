verilator -Wno-fatal --trace --trace-max-array 17000 -Wall --cc mem.v --exe sim_main.cpp
make -j -C obj_dir -f Vmem.mk Vmem
./obj_dir/Vmem

gtkwave mem.vcd mem.sav

riscv32-unknown-elf-as -march=IXpulpv2 test.asm
riscv32-unknown-elf-objdump -d a.out
