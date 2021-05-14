module shiftusingmux(A,Shift,Y);
input [3:0]A;
input [1:0]Shift;
output [3:0]Y;
muxx stage0({A[3],A[0],A[1],A[2]},Shift,Y[3]);
muxx stage1({A[2],A[3],A[0],A[1]},Shift,Y[2]);
muxx stage2({A[1],A[2],A[3],A[0]},Shift,Y[1]);
muxx stage3({A[0],A[1],A[2],A[3]},Shift,Y[0]);
endmodule


module muxx(w,S,f);
input [0:3]w;
input [1:0]S;
output f;
reg f;
always @(w or S)
begin
if(S==0)
f=w[0];
else if(S==1)
f=w[1];
else if(S==2)
f=w[2];
else
f=w[3];
end
endmodule
