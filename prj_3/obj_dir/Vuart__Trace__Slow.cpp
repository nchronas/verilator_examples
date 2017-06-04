// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vuart__Syms.h"


//======================

void Vuart::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vuart::traceInit, &Vuart::traceFull, &Vuart::traceChg, this);
}
void Vuart::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vuart* t=(Vuart*)userthis;
    Vuart__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vuart::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vuart* t=(Vuart*)userthis;
    Vuart__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vuart::traceInitThis(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vuart::traceFullThis(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vuart::traceInitThis__1(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+12,"clk",-1);
	vcdp->declBit  (c+13,"rst",-1);
	vcdp->declBit  (c+14,"rx",-1);
	vcdp->declBit  (c+15,"tx",-1);
	vcdp->declBit  (c+16,"transmit",-1);
	vcdp->declBus  (c+17,"tx_byte",-1,7,0);
	vcdp->declBit  (c+18,"received",-1);
	vcdp->declBus  (c+19,"rx_byte",-1,7,0);
	vcdp->declBit  (c+20,"is_receiving",-1);
	vcdp->declBit  (c+21,"is_transmitting",-1);
	vcdp->declBit  (c+22,"recv_error",-1);
	vcdp->declBus  (c+23,"baud",-1,15,0);
	vcdp->declBit  (c+24,"recv_ack",-1);
	vcdp->declBit  (c+12,"uart clk",-1);
	vcdp->declBit  (c+13,"uart rst",-1);
	vcdp->declBit  (c+14,"uart rx",-1);
	vcdp->declBit  (c+15,"uart tx",-1);
	vcdp->declBit  (c+16,"uart transmit",-1);
	vcdp->declBus  (c+17,"uart tx_byte",-1,7,0);
	vcdp->declBit  (c+18,"uart received",-1);
	vcdp->declBus  (c+19,"uart rx_byte",-1,7,0);
	vcdp->declBit  (c+20,"uart is_receiving",-1);
	vcdp->declBit  (c+21,"uart is_transmitting",-1);
	vcdp->declBit  (c+22,"uart recv_error",-1);
	vcdp->declBus  (c+23,"uart baud",-1,15,0);
	vcdp->declBit  (c+24,"uart recv_ack",-1);
	vcdp->declBus  (c+25,"uart RX_IDLE",-1,31,0);
	vcdp->declBus  (c+26,"uart RX_CHECK_START",-1,31,0);
	vcdp->declBus  (c+27,"uart RX_READ_BITS",-1,31,0);
	vcdp->declBus  (c+28,"uart RX_CHECK_STOP",-1,31,0);
	vcdp->declBus  (c+29,"uart RX_DELAY_RESTART",-1,31,0);
	vcdp->declBus  (c+30,"uart RX_ERROR",-1,31,0);
	vcdp->declBus  (c+31,"uart RX_RECEIVED",-1,31,0);
	vcdp->declBus  (c+25,"uart TX_IDLE",-1,31,0);
	vcdp->declBus  (c+26,"uart TX_SENDING",-1,31,0);
	vcdp->declBus  (c+27,"uart TX_DELAY_RESTART",-1,31,0);
	vcdp->declBus  (c+1,"uart rx_clk_divider",-1,10,0);
	vcdp->declBus  (c+2,"uart tx_clk_divider",-1,10,0);
	vcdp->declBus  (c+3,"uart recv_state",-1,2,0);
	vcdp->declBus  (c+4,"uart rx_countdown",-1,5,0);
	vcdp->declBus  (c+5,"uart rx_bits_remaining",-1,3,0);
	vcdp->declBus  (c+6,"uart rx_data",-1,7,0);
	vcdp->declBus  (c+7,"uart tx_out",-1,8,0);
	vcdp->declBus  (c+8,"uart tx_state",-1,1,0);
	vcdp->declBus  (c+9,"uart tx_countdown",-1,5,0);
	vcdp->declBus  (c+10,"uart tx_bits_remaining",-1,3,0);
	vcdp->declBus  (c+11,"uart tx_data",-1,7,0);
    }
}

void Vuart::traceFullThis__1(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->uart__DOT__rx_clk_divider),11);
	vcdp->fullBus  (c+2,(vlTOPp->uart__DOT__tx_clk_divider),11);
	vcdp->fullBus  (c+3,(vlTOPp->uart__DOT__recv_state),3);
	vcdp->fullBus  (c+4,(vlTOPp->uart__DOT__rx_countdown),6);
	vcdp->fullBus  (c+5,(vlTOPp->uart__DOT__rx_bits_remaining),4);
	vcdp->fullBus  (c+6,(vlTOPp->uart__DOT__rx_data),8);
	vcdp->fullBus  (c+7,(vlTOPp->uart__DOT__tx_out),9);
	vcdp->fullBus  (c+8,(vlTOPp->uart__DOT__tx_state),2);
	vcdp->fullBus  (c+9,(vlTOPp->uart__DOT__tx_countdown),6);
	vcdp->fullBus  (c+10,(vlTOPp->uart__DOT__tx_bits_remaining),4);
	vcdp->fullBus  (c+11,(vlTOPp->uart__DOT__tx_data),8);
	vcdp->fullBit  (c+12,(vlTOPp->clk));
	vcdp->fullBit  (c+13,(vlTOPp->rst));
	vcdp->fullBit  (c+14,(vlTOPp->rx));
	vcdp->fullBit  (c+15,(vlTOPp->tx));
	vcdp->fullBit  (c+16,(vlTOPp->transmit));
	vcdp->fullBus  (c+17,(vlTOPp->tx_byte),8);
	vcdp->fullBit  (c+18,(vlTOPp->received));
	vcdp->fullBus  (c+19,(vlTOPp->rx_byte),8);
	vcdp->fullBit  (c+20,(vlTOPp->is_receiving));
	vcdp->fullBit  (c+21,(vlTOPp->is_transmitting));
	vcdp->fullBit  (c+22,(vlTOPp->recv_error));
	vcdp->fullBus  (c+23,(vlTOPp->baud),16);
	vcdp->fullBit  (c+24,(vlTOPp->recv_ack));
	vcdp->fullBus  (c+25,(0U),32);
	vcdp->fullBus  (c+26,(1U),32);
	vcdp->fullBus  (c+27,(2U),32);
	vcdp->fullBus  (c+28,(3U),32);
	vcdp->fullBus  (c+29,(4U),32);
	vcdp->fullBus  (c+30,(5U),32);
	vcdp->fullBus  (c+31,(6U),32);
    }
}
