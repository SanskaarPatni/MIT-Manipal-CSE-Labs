module fourtwo16(W,En,F);
input [3:0]W;
input En;
output [0:15]F;
wire [0:3]c;
dec2to4 stage0(W[3:2],En,c);
dec2to4 stage1(W[1:0],~c[0],F[0:3]);
dec2to4 stage2(W[1:0],~c[1],F[4:7]);
dec2to4 stage3(W[1:0],~c[2],F[8:11]);
dec2to4 stage4(W[1:0],~c[3],F[12:15]);
endmodule

module dec2to4(w,e,f);
  input [1:0]w;
  input e;
  output [0:3]f;
  reg [0:3]f;
  
  always @(w or e)
  begin 
    if(e==0)
      f=4'b1111;
  else
    begin
    case(w)
      0:f=4'b0111;
      1:f=4'b1011;
      2:f=4'b1101;
      3:f=4'b1110;
    endcase
    end
  end
endmodule
