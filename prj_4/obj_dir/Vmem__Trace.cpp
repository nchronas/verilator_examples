// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmem__Syms.h"


//======================

void Vmem::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmem* t=(Vmem*)userthis;
    Vmem__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vmem::traceChgThis(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmem::traceChgThis__2(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->datamem__DOT__mem[0]),32);
	vcdp->chgBus  (c+2,(vlTOPp->datamem__DOT__mem[1]),32);
	vcdp->chgBus  (c+3,(vlTOPp->datamem__DOT__mem[2]),32);
	vcdp->chgBus  (c+4,(vlTOPp->datamem__DOT__mem[3]),32);
	vcdp->chgBus  (c+5,(vlTOPp->datamem__DOT__mem[4]),32);
	vcdp->chgBus  (c+6,(vlTOPp->datamem__DOT__mem[5]),32);
	vcdp->chgBus  (c+7,(vlTOPp->datamem__DOT__mem[6]),32);
	vcdp->chgBus  (c+8,(vlTOPp->datamem__DOT__mem[7]),32);
	vcdp->chgBus  (c+9,(vlTOPp->datamem__DOT__mem[8]),32);
	vcdp->chgBus  (c+10,(vlTOPp->datamem__DOT__mem[9]),32);
	vcdp->chgBus  (c+11,(vlTOPp->datamem__DOT__mem[10]),32);
	vcdp->chgBus  (c+12,(vlTOPp->datamem__DOT__mem[11]),32);
	vcdp->chgBus  (c+13,(vlTOPp->datamem__DOT__mem[12]),32);
	vcdp->chgBus  (c+14,(vlTOPp->datamem__DOT__mem[13]),32);
	vcdp->chgBus  (c+15,(vlTOPp->datamem__DOT__mem[14]),32);
	vcdp->chgBus  (c+16,(vlTOPp->datamem__DOT__mem[15]),32);
	vcdp->chgBus  (c+17,(vlTOPp->datamem__DOT__mask),32);
    }
}

void Vmem::traceChgThis__3(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+18,(vlTOPp->clk));
	vcdp->chgBus  (c+19,(vlTOPp->dina),32);
	vcdp->chgBus  (c+20,(vlTOPp->addra),14);
	vcdp->chgBus  (c+21,(vlTOPp->wea),1);
	vcdp->chgBus  (c+22,(vlTOPp->ena),4);
	vcdp->chgBus  (c+23,(vlTOPp->douta),32);
	vcdp->chgBus  (c+24,(vlTOPp->dinb),32);
	vcdp->chgBus  (c+25,(vlTOPp->addrb),14);
	vcdp->chgBus  (c+26,(vlTOPp->web),1);
	vcdp->chgBus  (c+27,(vlTOPp->enb),4);
	vcdp->chgBus  (c+28,(vlTOPp->doutb),32);
    }
}
