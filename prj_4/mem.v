`timescale 1ns / 1ps

module datamem(
                input clk,
                input [31:0] dina,
                input [13:0] addra,
                input [0:0] wea,
                input [3:0] ena,
                output [31:0] douta,
                input [31:0] dinb,
                input [13:0] addrb,
                input [0:0] web,
                input [3:0] enb,
                output [31:0] doutb
                );

    reg[31:0] mem [15:0];

    always @(posedge clk)
       if (ena)
          if (wea)
              mem[addra] = dina;
          else
              douta = mem[addra];
              //$display("Reset received");

endmodule
