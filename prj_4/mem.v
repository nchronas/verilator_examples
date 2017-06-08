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

    reg [31:0] mem [15:0];
    wire [31:0] mask;

    always @(posedge clk) begin
       mask = { {8{ena[3]}}, {8{ena[2]}}, {8{ena[1]}}, {8{ena[0]}} };
       if (ena) begin
          if (wea) begin
              mem[addra] = dina & mask;
              $display("Clk: addr: %d en:  %d we:  %d din:  %d dout:  %d mask:  %d mem: ", addra, ena, wea, dina, douta, mask );
          end else begin
              douta = mem[addra] & mask;
              $display("Clk: addr: %d en:  %d we:  %d din:  %d dout:  %d mask:  %d mem: ", addra, ena, wea, dina, douta, mask );
          end
       end
    end
endmodule
