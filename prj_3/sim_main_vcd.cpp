#include "Vuart.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    int i, clk;
    // init top verilog instance
    Vuart* top = new Vuart;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("uart.vcd");
    // initialize simulation inputs
    top->clk = 1;
    top->rst = 1;

    top->rx = 1;
    top->recv_ack = 0;
    top->baud = 32700;
    top->tx_byte = 0xDE;

    top->transmit = 0;

    i = 0;
    while (!Verilated::gotFinish()) {

        top->rst = (i < 2);
        top->transmit = (i > 200);

        for (clk=0; clk<2; clk++) {
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }

        i++;
    }
    delete top;

    tfp->close();
    exit(0);
}
