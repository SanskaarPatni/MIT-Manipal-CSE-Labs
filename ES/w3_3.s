	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=VAL1
	LDR R1,=VAL2
	LDR R2,=RES
	LDR R3,[R0]
	LDR R4,[R1]
	LDR R5,=0
LOOP CMP R3,R4
	BCC NEXT 
	SUB R3,R4
	ADD R5,R5,#1
	B LOOP
NEXT STR R3,[R2],#4
	STR R5,[R2]
STOP
	B STOP
VAL1 DCD 10
VAL2 DCD 3
	AREA mydata,DATA,READWRITE
RES DCD 0
	END