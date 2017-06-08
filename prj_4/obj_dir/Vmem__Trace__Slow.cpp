// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmem__Syms.h"


//======================

void Vmem::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vmem::traceInit, &Vmem::traceFull, &Vmem::traceChg, this);
}
void Vmem::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vmem* t=(Vmem*)userthis;
    Vmem__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vmem::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmem* t=(Vmem*)userthis;
    Vmem__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vmem::traceInitThis(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vmem::traceFullThis(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmem::traceInitThis__1(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+18,"clk",-1);
	vcdp->declBus  (c+19,"dina",-1,31,0);
	vcdp->declBus  (c+20,"addra",-1,13,0);
	vcdp->declBus  (c+21,"wea",-1,0,0);
	vcdp->declBus  (c+22,"ena",-1,3,0);
	vcdp->declBus  (c+23,"douta",-1,31,0);
	vcdp->declBus  (c+24,"dinb",-1,31,0);
	vcdp->declBus  (c+25,"addrb",-1,13,0);
	vcdp->declBus  (c+26,"web",-1,0,0);
	vcdp->declBus  (c+27,"enb",-1,3,0);
	vcdp->declBus  (c+28,"doutb",-1,31,0);
	vcdp->declBit  (c+18,"datamem clk",-1);
	vcdp->declBus  (c+19,"datamem dina",-1,31,0);
	vcdp->declBus  (c+20,"datamem addra",-1,13,0);
	vcdp->declBus  (c+21,"datamem wea",-1,0,0);
	vcdp->declBus  (c+22,"datamem ena",-1,3,0);
	vcdp->declBus  (c+23,"datamem douta",-1,31,0);
	vcdp->declBus  (c+24,"datamem dinb",-1,31,0);
	vcdp->declBus  (c+25,"datamem addrb",-1,13,0);
	vcdp->declBus  (c+26,"datamem web",-1,0,0);
	vcdp->declBus  (c+27,"datamem enb",-1,3,0);
	vcdp->declBus  (c+28,"datamem doutb",-1,31,0);
	{int i; for (i=0; i<16; i++) {
		vcdp->declBus  (c+1+i*1,"datamem mem",(i+0),31,0);}}
	vcdp->declBus  (c+17,"datamem mask",-1,31,0);
    }
}

void Vmem::traceFullThis__1(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->datamem__DOT__mem[0]),32);
	vcdp->fullBus  (c+2,(vlTOPp->datamem__DOT__mem[1]),32);
	vcdp->fullBus  (c+3,(vlTOPp->datamem__DOT__mem[2]),32);
	vcdp->fullBus  (c+4,(vlTOPp->datamem__DOT__mem[3]),32);
	vcdp->fullBus  (c+5,(vlTOPp->datamem__DOT__mem[4]),32);
	vcdp->fullBus  (c+6,(vlTOPp->datamem__DOT__mem[5]),32);
	vcdp->fullBus  (c+7,(vlTOPp->datamem__DOT__mem[6]),32);
	vcdp->fullBus  (c+8,(vlTOPp->datamem__DOT__mem[7]),32);
	vcdp->fullBus  (c+9,(vlTOPp->datamem__DOT__mem[8]),32);
	vcdp->fullBus  (c+10,(vlTOPp->datamem__DOT__mem[9]),32);
	vcdp->fullBus  (c+11,(vlTOPp->datamem__DOT__mem[10]),32);
	vcdp->fullBus  (c+12,(vlTOPp->datamem__DOT__mem[11]),32);
	vcdp->fullBus  (c+13,(vlTOPp->datamem__DOT__mem[12]),32);
	vcdp->fullBus  (c+14,(vlTOPp->datamem__DOT__mem[13]),32);
	vcdp->fullBus  (c+15,(vlTOPp->datamem__DOT__mem[14]),32);
	vcdp->fullBus  (c+16,(vlTOPp->datamem__DOT__mem[15]),32);
	vcdp->fullBus  (c+17,(vlTOPp->datamem__DOT__mask),32);
	vcdp->fullBit  (c+18,(vlTOPp->clk));
	vcdp->fullBus  (c+19,(vlTOPp->dina),32);
	vcdp->fullBus  (c+20,(vlTOPp->addra),14);
	vcdp->fullBus  (c+21,(vlTOPp->wea),1);
	vcdp->fullBus  (c+22,(vlTOPp->ena),4);
	vcdp->fullBus  (c+23,(vlTOPp->douta),32);
	vcdp->fullBus  (c+24,(vlTOPp->dinb),32);
	vcdp->fullBus  (c+25,(vlTOPp->addrb),14);
	vcdp->fullBus  (c+26,(vlTOPp->web),1);
	vcdp->fullBus  (c+27,(vlTOPp->enb),4);
	vcdp->fullBus  (c+28,(vlTOPp->doutb),32);
    }
}
