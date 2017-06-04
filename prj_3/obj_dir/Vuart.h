// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vuart_H_
#define _Vuart_H_

#include "verilated_heavy.h"
class Vuart__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vuart) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(rx,0,0);
    VL_OUT8(tx,0,0);
    VL_IN8(transmit,0,0);
    VL_IN8(tx_byte,7,0);
    VL_OUT8(received,0,0);
    VL_OUT8(rx_byte,7,0);
    VL_OUT8(is_receiving,0,0);
    VL_OUT8(is_transmitting,0,0);
    VL_OUT8(recv_error,0,0);
    VL_IN8(recv_ack,0,0);
    VL_IN16(baud,15,0);
    //char	__VpadToAlign14[2];
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(uart__DOT__recv_state,2,0);
    VL_SIG8(uart__DOT__rx_countdown,5,0);
    VL_SIG8(uart__DOT__rx_bits_remaining,3,0);
    VL_SIG8(uart__DOT__rx_data,7,0);
    VL_SIG8(uart__DOT__tx_state,1,0);
    VL_SIG8(uart__DOT__tx_countdown,5,0);
    VL_SIG8(uart__DOT__tx_bits_remaining,3,0);
    VL_SIG8(uart__DOT__tx_data,7,0);
    VL_SIG16(uart__DOT__rx_clk_divider,10,0);
    VL_SIG16(uart__DOT__tx_clk_divider,10,0);
    VL_SIG16(uart__DOT__tx_out,8,0);
    //char	__VpadToAlign34[2];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign41[3];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign52[4];
    Vuart__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vuart& operator= (const Vuart&);	///< Copying not allowed
    Vuart(const Vuart&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vuart(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vuart();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vuart__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vuart__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vuart__Syms* __restrict vlSymsp);
    void	_configure_coverage(Vuart__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vuart__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vuart__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vuart__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vuart__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(Vuart__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vuart__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
