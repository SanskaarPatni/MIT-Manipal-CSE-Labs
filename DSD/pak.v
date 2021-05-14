module dfpp(D,Q,clk);
  input D;
  input clk;
  output Q;
  reg Q;
  always @(posedge clk)
  Q<=D;
endmodule

module pak(Clock,q,H);
  input Clock;
  output H;
  output [2:0]q;
  dfpp stage0(~q[0],Clock,q[2]);
  dfpp stage1(q[2],Clock,q[1]);
  dfpp stage2(q[1],Clock,q[0]);
  assign H=q[2]&~q[1];
endmodule
