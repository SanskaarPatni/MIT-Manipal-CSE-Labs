module prior(W,O,Z);
  input [3:0]W;
  output Z;
  output [1:0]O;
  reg [1:0]O;
  integer k;
  reg Z;
  always @(W)
  begin
    O=2'bxx;
    Z=0;
    for(k=0;k<=3;k=k+1)
    begin
      if(W[k])
        begin
        O=k;
        Z=1;
      end
      end
  end
endmodule
