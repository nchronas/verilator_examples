// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmem_H_
#define _Vmem_H_

#include "verilated_heavy.h"
class Vmem__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vmem) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(wea,0,0);
    VL_IN8(ena,3,0);
    VL_IN8(web,0,0);
    VL_IN8(enb,3,0);
    //char	__VpadToAlign5[1];
    VL_IN16(addra,13,0);
    VL_IN16(addrb,13,0);
    //char	__VpadToAlign10[2];
    VL_IN(dina,31,0);
    VL_OUT(douta,31,0);
    VL_IN(dinb,31,0);
    VL_OUT(doutb,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(datamem__DOT__mask,31,0);
    //char	__VpadToAlign36[4];
    VL_SIG(datamem__DOT__mem[16],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign109[3];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmem__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vmem& operator= (const Vmem&);	///< Copying not allowed
    Vmem(const Vmem&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vmem(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmem();
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
    static void _eval_initial_loop(Vmem__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmem__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vmem__Syms* __restrict vlSymsp);
    void	_configure_coverage(Vmem__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vmem__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vmem__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vmem__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vmem__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vmem__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
