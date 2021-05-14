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
	LDR R1,=RESULT
	MOV R2,#10

UP 	LDR R3,[R0],#4
	STR R3,[R1],#4
	SUBS R2,#1
	BNE UP
	
	LDR R1,=RESULT
	MOV R2,#9
	MOV R3,#1
	
L3	CMP R3,R2
	BHI STOP
	
	MOV R4,R1
	MOV R5,R1
	
	MOV R6,#10
	ADD R7,R3,#1

L2 CMP R7,R6
	BHI SWAP
	LDR R8,[R4]
	ADD R5,#4
	LDR R9,[R5]
	CMP R8,R9
	MOVCS R4,R5
	ADD R7,#1
	B L2


SWAP LDR R10,[R4]
	LDR R11,[R1]
	STR R10,[R1]
	STR R11,[R4]
	ADD R3,#1
	ADD R1,#4
	B L3
	
STOP B STOP

VAL1 DCD 9,8,7,6,5,4,3,2,1,0

	AREA MYDATA,DATA,READWRITE

RESULT DCD 0
	END 