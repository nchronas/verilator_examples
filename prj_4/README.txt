verilator -Wno-fatal --trace -Wall --cc mem.v --exe sim_main.cpp
make -j -C obj_dir -f Vmem.mk Vmem
./obj_dir/Vmem

gtkwave mem.vcd mem.sav
