#include "Vuart.h"
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    int i, clk;
    // init top verilog instance
    Vuart* top = new Vuart;

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 1;

    top->rx = 1;
    top->recv_ack = 0;
    top->baud = 32700;
    top->tx_byte = 0xDE;

    top->transmit = 0;

    // run simulation for 100 clock periods
    for (i=0; i<20; i++) {
        top->rst = (i < 2);
        // toggle clock
        for (clk=0; clk<2; clk++) {
            top->clk = !top->clk;
            top->eval ();
        }

        if (Verilated::gotFinish())  exit(0);
    }

    top->transmit = 1;
  //  for (i=0; i<20; i++) {
  //      for (clk=0; clk<2; clk++) {
  //          top->clk = !top->clk;
  //          top->eval ();
  //      }

  //      if (Verilated::gotFinish())  exit(0);
  //  }
    //top->transmit = 0;

    while (!Verilated::gotFinish()) {
        for (clk=0; clk<2; clk++) {
            top->clk = !top->clk;
            top->eval ();
        }
    }
    delete top;

    exit(0);
}
