module FullAddee(x,y,z,s,C);
input x,y,z;
output s,C;
mux2to1 stage0({y^z,~(y^z)},x,s);
mux2to1 stage1({y&z,y|z},x,C);
endmodule


module mux2to1(W,S,F);
input [1:0]W;
input S;
output F;
reg F;
always @(W or S)
begin
if(S==0)
F=W[0];
else
F=W[1];
end
endmodule
