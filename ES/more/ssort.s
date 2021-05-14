AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=VAL1
	LDR R5,[R0]
	LDR R1,=FIB
	MOV R3,#0
	MOV R4,#1
	STRB R3,[R1],#1
	
UP SUBS R5,#1
	BNE DOWN
	B STOP
	
DOWN STRB R4,[R1],#1
	MOV R6,R4
	ADD R4,R3
	MOV R3,R6
	B UP
	
STOP B STOP

VAL1 DCD 6
	
	AREA mydata,DATA,READWRITE
FIB DCD 0
	END