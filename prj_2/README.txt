
Running with the following cmds:

verilator -Wno-fatal -Wall --cc uart.v --exe sim_main.cpp
make -j -C obj_dir -f Vuart.mk Vuart
./obj_dir/Vuart 
