verilator -Wno-fatal --trace -Wall --cc uart.v --exe sim_main_vcd.cpp
make -j -C obj_dir -f Vuart.mk Vuart
./obj_dir/Vuart 

gtkwave uart.vcd uart.sav

