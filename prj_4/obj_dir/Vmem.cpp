// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmem.h for the primary calling header

#include "Vmem.h"              // For This
#include "Vmem__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmem) {
    Vmem__Syms* __restrict vlSymsp = __VlSymsp = new Vmem__Syms(this, name());
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmem::__Vconfigure(Vmem__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmem::~Vmem() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmem::eval() {
    Vmem__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vmem::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vmem::_eval_initial_loop(Vmem__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vmem::_sequent__TOP__1(Vmem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::_sequent__TOP__1\n"); );
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at mem.v:20
    vlTOPp->datamem__DOT__mask = ((0xff000000U & (VL_NEGATE_I((IData)(
								      (1U 
								       & ((IData)(vlTOPp->ena) 
									  >> 3U)))) 
						  << 0x18U)) 
				  | ((0xff0000U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& ((IData)(vlTOPp->ena) 
									   >> 2U)))) 
						   << 0x10U)) 
				     | ((0xff00U & 
					 (VL_NEGATE_I((IData)(
							      (1U 
							       & ((IData)(vlTOPp->ena) 
								  >> 1U)))) 
					  << 8U)) | 
					(0xffU & VL_NEGATE_I((IData)(
								     (1U 
								      & (IData)(vlTOPp->ena))))))));
    if ((0U != (IData)(vlTOPp->ena))) {
	if (vlTOPp->wea) {
	    vlTOPp->datamem__DOT__mem[(0xfU & (IData)(vlTOPp->addra))] 
		= (vlTOPp->dina & vlTOPp->datamem__DOT__mask);
	    VL_WRITEF("Clk: addr: %5# en:  %2# we:  %1# din:  %10# dout:  %10# mask:  %10# mem: \n",
		      14,vlTOPp->addra,4,(IData)(vlTOPp->ena),
		      1,vlTOPp->wea,32,vlTOPp->dina,
		      32,vlTOPp->douta,32,vlTOPp->datamem__DOT__mask);
	} else {
	    vlTOPp->douta = (vlTOPp->datamem__DOT__mem
			     [(0xfU & (IData)(vlTOPp->addra))] 
			     & vlTOPp->datamem__DOT__mask);
	    VL_WRITEF("Clk: addr: %5# en:  %2# we:  %1# din:  %10# dout:  %10# mask:  %10# mem: \n",
		      14,vlTOPp->addra,4,(IData)(vlTOPp->ena),
		      1,vlTOPp->wea,32,vlTOPp->dina,
		      32,vlTOPp->douta,32,vlTOPp->datamem__DOT__mask);
	}
    }
}

void Vmem::_eval(Vmem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::_eval\n"); );
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmem::_eval_initial(Vmem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::_eval_initial\n"); );
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmem::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::final\n"); );
    // Variables
    Vmem__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmem::_eval_settle(Vmem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::_eval_settle\n"); );
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vmem::_change_request(Vmem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::_change_request\n"); );
    Vmem* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void Vmem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    dina = VL_RAND_RESET_I(32);
    addra = VL_RAND_RESET_I(14);
    wea = VL_RAND_RESET_I(1);
    ena = VL_RAND_RESET_I(4);
    douta = VL_RAND_RESET_I(32);
    dinb = VL_RAND_RESET_I(32);
    addrb = VL_RAND_RESET_I(14);
    web = VL_RAND_RESET_I(1);
    enb = VL_RAND_RESET_I(4);
    doutb = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    datamem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    datamem__DOT__mask = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Vmem::_configure_coverage(Vmem__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Vmem::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
