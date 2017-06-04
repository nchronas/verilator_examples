// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vuart__Syms.h"


//======================

void Vuart::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vuart* t=(Vuart*)userthis;
    Vuart__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vuart::traceChgThis(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vuart::traceChgThis__2(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->uart__DOT__rx_clk_divider),11);
	vcdp->chgBus  (c+2,(vlTOPp->uart__DOT__tx_clk_divider),11);
	vcdp->chgBus  (c+3,(vlTOPp->uart__DOT__recv_state),3);
	vcdp->chgBus  (c+4,(vlTOPp->uart__DOT__rx_countdown),6);
	vcdp->chgBus  (c+5,(vlTOPp->uart__DOT__rx_bits_remaining),4);
	vcdp->chgBus  (c+6,(vlTOPp->uart__DOT__rx_data),8);
	vcdp->chgBus  (c+7,(vlTOPp->uart__DOT__tx_out),9);
	vcdp->chgBus  (c+8,(vlTOPp->uart__DOT__tx_state),2);
	vcdp->chgBus  (c+9,(vlTOPp->uart__DOT__tx_countdown),6);
	vcdp->chgBus  (c+10,(vlTOPp->uart__DOT__tx_bits_remaining),4);
	vcdp->chgBus  (c+11,(vlTOPp->uart__DOT__tx_data),8);
    }
}

void Vuart::traceChgThis__3(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+12,(vlTOPp->clk));
	vcdp->chgBit  (c+13,(vlTOPp->rst));
	vcdp->chgBit  (c+14,(vlTOPp->rx));
	vcdp->chgBit  (c+15,(vlTOPp->tx));
	vcdp->chgBit  (c+16,(vlTOPp->transmit));
	vcdp->chgBus  (c+17,(vlTOPp->tx_byte),8);
	vcdp->chgBit  (c+18,(vlTOPp->received));
	vcdp->chgBus  (c+19,(vlTOPp->rx_byte),8);
	vcdp->chgBit  (c+20,(vlTOPp->is_receiving));
	vcdp->chgBit  (c+21,(vlTOPp->is_transmitting));
	vcdp->chgBit  (c+22,(vlTOPp->recv_error));
	vcdp->chgBus  (c+23,(vlTOPp->baud),16);
	vcdp->chgBit  (c+24,(vlTOPp->recv_ack));
    }
}
