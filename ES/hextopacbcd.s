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
	LDR R0,=HEXSIX
	LDR R1,[R0]
	LDR R3,=UNPACK
	LDR R4,=PACKED
	MOV R9,#3
	MOV R7,#0
	MOV R6,#0
	
LOOP CMP R1,#0XA
	BCC STORE
	SUB R1,#0XA
	ADD R2,R2,#1
	B LOOP

STORE 
	STRB R1,[R3],#1
	MOV R1,R2
	MOV R2,#0
	CMP R1,#0XA
	BCS LOOP
	STRB R1,[R3]
	LDR R3,=UNPACK

LOOPS LDRB R6,[R3],#1
	LSL R7,R7,#4
	ORR R7,R7,R6
	SUBS R9,#1
	BNE LOOPS
	
	STR R7,[R4]
	
	
STOP B STOP

HEXSIX DCD 0XFF
	AREA MYDATA,DATA,READWRITE
UNPACK DCD 0
PACKED DCD 0
	END