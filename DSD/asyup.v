module asyup(Clock,q);
  input Clock;
  output [3:0]q;
  jkfff stage0(1'b1,1'b1,Clock,q[0]);
  jkfff stage1(1'b1,1'b1,q[0],q[1]);
  jkfff stage2(1'b1,1'b1,q[1],q[2]);
  jkfff stage3(1'b1,1'b1,q[2],q[3]);
endmodule
module jkfff(J,K,clock,Q);
  input J,K;
  input clock;
  output Q;
  reg Q;
  always @(negedge clock)
  begin
        case({J,K})
          0:Q<=Q;
          1:Q<=0;
          2:Q<=1;
          3:Q<=~Q;
        endcase
    end
endmodule

