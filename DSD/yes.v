module tff1(T,Clock,Q);
  input T;
  input Clock;
  output Q;
  reg Q;
  always @(negedge Clock)
  begin
    if(!T)
      Q<=Q;
    else
      Q<=~Q;
  end
endmodule


module counter1(clock,q);
  input clock;
  output [1:0]q;
  tff1 stage0(1'b1,clock,q[0]);
  tff2 stage1(1'b1,q[0],q[1]);
endmodule

module decoder2to4(en,x,y,p);
  input en;
  input [1:0]x;
  input [3:0]p;
  output [3:0]y;
  reg [3:0]y;
  always @(en or x)
  begin
    case(x)
      0:y={p[2],p[1],p[0],p[3]};
      1:y={p[1],p[0],p[3],p[2]};
      2:y={p[0],p[3],p[2],p[1]};
      3:y={~p[3],~p[2],~p[1],~p[0]};
  endcase
  end
endmodule

module yes(X,Y,clk);
  input [3:0]X;
  input clk;
  output [3:0]Y;
  wire [1:0]a;
  counter1 stage0(clk,a);
  decoder2to4 stageq(1'b1,a,Y,X);
endmodule