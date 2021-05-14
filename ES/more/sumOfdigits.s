	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	dcd 0x10001000
	dcd Reset_Handler
	Align
	Area mycode,CODE,READONLY
	ENTRY
	Export Reset_Handler
Reset_Handler
	ldr r0,=src
	ldr r1,[r0]
	
loop cmp r1,#0
	subs r1,#0xA
	
	

	
	
src dcd 0xff
	Area mycode,CODE,READWRITE
dst dcd 0
	END