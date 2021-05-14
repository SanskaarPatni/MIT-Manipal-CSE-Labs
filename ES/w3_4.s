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
	LDR R2,=GCD
	LDR R3,=LCM
	LDR R4,[R0]
	LDR R5,[R1]
	MUL R6,R4,R5
	MOV R10,#0
LOOP CMP R4,R5
	BEQ STORE
	BCS NEXT 
	SUB R5,R5,R4
	B LOOP
NEXT SUB R4,R4,R5
	B LOOP
STORE STR R4,[R2]
	B FINDLCM
FINDLCM CMP R6,R4
	BCC PEXT 
	SUB R6,R4
	ADD R10,R10,#1
	B FINDLCM

PEXT STR R10,[R3],#4
	STR R6,[R3]

STOP
	B STOP
VAL1 DCD 3
VAL2 DCD 2
	AREA mydata,DATA,READWRITE
GCD DCD 0
LCM DCD 0
	END