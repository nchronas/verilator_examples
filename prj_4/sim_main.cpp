#include "Vmem.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    int i, clk;
    // init top verilog instance
    Vmem* top = new Vmem;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("mem.vcd");
    // initialize simulation inputs
    top->clk = 1;

    i = 0;

    top->ena = 0x0;
    top->wea = 0;
    top->addra = 0;
    top->dina = 0x00000000;

    for (clk=0; clk<2; clk++) {
        tfp->dump (2*i+clk);
        top->clk = !top->clk;
        top->eval ();
    }
    i++;

    top->ena = 0xF;
    top->wea = 1;
    top->addra = 0;
    top->dina = 0xDEADBEAF;

    for (clk=0; clk<2; clk++) {
        tfp->dump (2*i+clk);
        top->clk = !top->clk;
        top->eval ();
    }
    i++;

    top->ena = 0xF;
    top->wea = 0;
    top->addra = 0;
    top->dina = 0xDEADBEAF;

    for (clk=0; clk<2; clk++) {
        tfp->dump (2*i+clk);
        top->clk = !top->clk;
        top->eval ();
    }
    i++;

    top->ena = 0xF;
    top->wea = 1;
    top->addra = 1;
    top->dina = 0xABCD0987;

    for (clk=0; clk<2; clk++) {
        tfp->dump (2*i+clk);
        top->clk = !top->clk;
        top->eval ();
    }
    i++;

    top->ena = 0xF;
    top->wea = 0;
    top->addra = 1;
    top->dina = 0xABCD0987;

    for (clk=0; clk<2; clk++) {
        tfp->dump (2*i+clk);
        top->clk = !top->clk;
        top->eval ();
    }
    i++;



    for (clk=0; clk<2; clk++) {
        tfp->dump (2*i+clk);
        top->clk = !top->clk;
        top->eval ();
    }

    i++;

    for (clk=0; clk<2; clk++) {
        tfp->dump (2*i+clk);
        top->clk = !top->clk;
        top->eval ();
    }

    i++;

    delete top;

    tfp->close();
    exit(0);
}
