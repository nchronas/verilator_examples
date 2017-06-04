// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart.h for the primary calling header

#include "Vuart.h"             // For This
#include "Vuart__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vuart) {
    Vuart__Syms* __restrict vlSymsp = __VlSymsp = new Vuart__Syms(this, name());
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vuart::__Vconfigure(Vuart__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vuart::~Vuart() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vuart::eval() {
    Vuart__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vuart::eval\n"); );
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

void Vuart::_eval_initial_loop(Vuart__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vuart::_sequent__TOP__1(Vuart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_sequent__TOP__1\n"); );
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at uart.v:77
    if (VL_UNLIKELY(vlTOPp->rst)) {
	vlTOPp->received = 0U;
	vlTOPp->uart__DOT__recv_state = 0U;
	vlTOPp->uart__DOT__tx_state = 2U;
	vlTOPp->uart__DOT__tx_out = 0x1ffU;
	vlTOPp->uart__DOT__tx_countdown = 0xfU;
	vlTOPp->uart__DOT__rx_data = 0U;
	vlTOPp->uart__DOT__tx_data = 0U;
	vlTOPp->uart__DOT__tx_bits_remaining = 0U;
	vlTOPp->recv_error = 0U;
	vlTOPp->uart__DOT__rx_clk_divider = (0x7ffU 
					     & (IData)(vlTOPp->baud));
	vlTOPp->uart__DOT__tx_clk_divider = (0x7ffU 
					     & (IData)(vlTOPp->baud));
	vlTOPp->rx_byte = 0U;
	VL_WRITEF("Reset received\n");
    }
    if (vlTOPp->recv_ack) {
	vlTOPp->received = 0U;
	vlTOPp->recv_error = 0U;
    }
    vlTOPp->uart__DOT__rx_clk_divider = (0x7ffU & ((IData)(vlTOPp->uart__DOT__rx_clk_divider) 
						   - (IData)(1U)));
    if ((1U & (~ (IData)((0U != (IData)(vlTOPp->uart__DOT__rx_clk_divider)))))) {
	vlTOPp->uart__DOT__rx_clk_divider = (0x7ffU 
					     & (IData)(vlTOPp->baud));
	vlTOPp->uart__DOT__rx_countdown = (0x3fU & 
					   ((IData)(vlTOPp->uart__DOT__rx_countdown) 
					    - (IData)(1U)));
    }
    vlTOPp->uart__DOT__tx_clk_divider = (0x7ffU & ((IData)(vlTOPp->uart__DOT__tx_clk_divider) 
						   - (IData)(1U)));
    if ((1U & (~ (IData)((0U != (IData)(vlTOPp->uart__DOT__tx_clk_divider)))))) {
	vlTOPp->uart__DOT__tx_countdown = (0x3fU & 
					   ((IData)(vlTOPp->uart__DOT__tx_countdown) 
					    - (IData)(1U)));
	vlTOPp->uart__DOT__tx_clk_divider = (0x7ffU 
					     & (IData)(vlTOPp->baud));
    }
    if ((0U == (IData)(vlTOPp->uart__DOT__recv_state))) {
	if ((1U & (~ (IData)(vlTOPp->rx)))) {
	    vlTOPp->uart__DOT__rx_clk_divider = (0x7ffU 
						 & (IData)(vlTOPp->baud));
	    vlTOPp->uart__DOT__rx_countdown = 2U;
	    vlTOPp->uart__DOT__recv_state = 1U;
	}
    } else {
	if ((1U == (IData)(vlTOPp->uart__DOT__recv_state))) {
	    if ((1U & (~ (IData)((0U != (IData)(vlTOPp->uart__DOT__rx_countdown)))))) {
		if (vlTOPp->rx) {
		    vlTOPp->uart__DOT__recv_state = 5U;
		} else {
		    vlTOPp->uart__DOT__rx_countdown = 4U;
		    vlTOPp->uart__DOT__rx_bits_remaining = 8U;
		    vlTOPp->uart__DOT__recv_state = 2U;
		}
	    }
	} else {
	    if ((2U == (IData)(vlTOPp->uart__DOT__recv_state))) {
		if ((1U & (~ (IData)((0U != (IData)(vlTOPp->uart__DOT__rx_countdown)))))) {
		    vlTOPp->uart__DOT__rx_data = (((IData)(vlTOPp->rx) 
						   << 7U) 
						  | (0x7fU 
						     & ((IData)(vlTOPp->uart__DOT__rx_data) 
							>> 1U)));
		    vlTOPp->uart__DOT__rx_bits_remaining 
			= (0xfU & ((IData)(vlTOPp->uart__DOT__rx_bits_remaining) 
				   - (IData)(1U)));
		    vlTOPp->uart__DOT__rx_countdown = 4U;
		    vlTOPp->uart__DOT__recv_state = 
			(7U & ((0U != (IData)(vlTOPp->uart__DOT__rx_bits_remaining))
			        ? 2U : 3U));
		}
	    } else {
		if ((3U == (IData)(vlTOPp->uart__DOT__recv_state))) {
		    if ((1U & (~ (IData)((0U != (IData)(vlTOPp->uart__DOT__rx_countdown)))))) {
			vlTOPp->uart__DOT__recv_state 
			    = (7U & ((IData)(vlTOPp->rx)
				      ? 6U : 5U));
		    }
		} else {
		    if ((4U == (IData)(vlTOPp->uart__DOT__recv_state))) {
			vlTOPp->uart__DOT__recv_state 
			    = (7U & ((0U != (IData)(vlTOPp->uart__DOT__rx_countdown))
				      ? 4U : 0U));
		    } else {
			if ((5U == (IData)(vlTOPp->uart__DOT__recv_state))) {
			    vlTOPp->uart__DOT__rx_countdown = 8U;
			    vlTOPp->recv_error = 1U;
			    vlTOPp->uart__DOT__recv_state = 4U;
			} else {
			    if ((6U == (IData)(vlTOPp->uart__DOT__recv_state))) {
				vlTOPp->received = 1U;
				vlTOPp->uart__DOT__recv_state = 0U;
				vlTOPp->rx_byte = vlTOPp->uart__DOT__rx_data;
			    }
			}
		    }
		}
	    }
	}
    }
    if ((0U == (IData)(vlTOPp->uart__DOT__tx_state))) {
	if (VL_UNLIKELY(vlTOPp->transmit)) {
	    vlTOPp->uart__DOT__tx_data = vlTOPp->tx_byte;
	    vlTOPp->uart__DOT__tx_countdown = 4U;
	    vlTOPp->uart__DOT__tx_bits_remaining = 9U;
	    vlTOPp->uart__DOT__tx_state = 1U;
	    vlTOPp->uart__DOT__tx_out = ((IData)(vlTOPp->uart__DOT__tx_data) 
					 << 1U);
	    vlTOPp->uart__DOT__tx_clk_divider = (0x7ffU 
						 & (IData)(vlTOPp->baud));
	    VL_WRITEF("Sending byte %3#\n",8,vlTOPp->uart__DOT__tx_data);
	}
    } else {
	if ((1U == (IData)(vlTOPp->uart__DOT__tx_state))) {
	    if ((1U & (~ (IData)((0U != (IData)(vlTOPp->uart__DOT__tx_countdown)))))) {
		if (VL_LIKELY((0U != (IData)(vlTOPp->uart__DOT__tx_bits_remaining)))) {
		    vlTOPp->uart__DOT__tx_bits_remaining 
			= (0xfU & ((IData)(vlTOPp->uart__DOT__tx_bits_remaining) 
				   - (IData)(1U)));
		    vlTOPp->uart__DOT__tx_out = (0x100U 
						 | (0xffU 
						    & ((IData)(vlTOPp->uart__DOT__tx_out) 
						       >> 1U)));
		    vlTOPp->uart__DOT__tx_countdown = 4U;
		    vlTOPp->uart__DOT__tx_state = 1U;
		} else {
		    vlTOPp->uart__DOT__tx_countdown = 8U;
		    vlTOPp->uart__DOT__tx_state = 2U;
		    VL_WRITEF("Finished sending\n");
		    vl_finish("uart.v",218,"");
		}
	    }
	} else {
	    if ((2U == (IData)(vlTOPp->uart__DOT__tx_state))) {
		vlTOPp->uart__DOT__tx_state = (3U & 
					       ((0U 
						 != (IData)(vlTOPp->uart__DOT__tx_countdown))
						 ? 2U
						 : 0U));
	    }
	}
    }
    vlTOPp->is_receiving = (0U != (IData)(vlTOPp->uart__DOT__recv_state));
    vlTOPp->is_transmitting = (0U != (IData)(vlTOPp->uart__DOT__tx_state));
    vlTOPp->tx = (1U & (IData)(vlTOPp->uart__DOT__tx_out));
}

void Vuart::_settle__TOP__2(Vuart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_settle__TOP__2\n"); );
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->is_receiving = (0U != (IData)(vlTOPp->uart__DOT__recv_state));
    vlTOPp->is_transmitting = (0U != (IData)(vlTOPp->uart__DOT__tx_state));
    vlTOPp->tx = (1U & (IData)(vlTOPp->uart__DOT__tx_out));
}

void Vuart::_eval(Vuart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_eval\n"); );
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vuart::_eval_initial(Vuart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_eval_initial\n"); );
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vuart::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::final\n"); );
    // Variables
    Vuart__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vuart::_eval_settle(Vuart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_eval_settle\n"); );
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vuart::_change_request(Vuart__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_change_request\n"); );
    Vuart* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void Vuart::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    rx = VL_RAND_RESET_I(1);
    tx = VL_RAND_RESET_I(1);
    transmit = VL_RAND_RESET_I(1);
    tx_byte = VL_RAND_RESET_I(8);
    received = VL_RAND_RESET_I(1);
    rx_byte = VL_RAND_RESET_I(8);
    is_receiving = VL_RAND_RESET_I(1);
    is_transmitting = VL_RAND_RESET_I(1);
    recv_error = VL_RAND_RESET_I(1);
    baud = VL_RAND_RESET_I(16);
    recv_ack = VL_RAND_RESET_I(1);
    uart__DOT__rx_clk_divider = VL_RAND_RESET_I(11);
    uart__DOT__tx_clk_divider = VL_RAND_RESET_I(11);
    uart__DOT__recv_state = VL_RAND_RESET_I(3);
    uart__DOT__rx_countdown = VL_RAND_RESET_I(6);
    uart__DOT__rx_bits_remaining = VL_RAND_RESET_I(4);
    uart__DOT__rx_data = VL_RAND_RESET_I(8);
    uart__DOT__tx_out = VL_RAND_RESET_I(9);
    uart__DOT__tx_state = VL_RAND_RESET_I(2);
    uart__DOT__tx_countdown = VL_RAND_RESET_I(6);
    uart__DOT__tx_bits_remaining = VL_RAND_RESET_I(4);
    uart__DOT__tx_data = VL_RAND_RESET_I(8);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}

void Vuart::_configure_coverage(Vuart__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Vuart::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
