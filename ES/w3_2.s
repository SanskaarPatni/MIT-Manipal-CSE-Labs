	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	AREA Mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=VAL1
	LDR R1,=VAL2
	LDR R6,=QU
	LDR R7,=REM
	MOV R2,#0
	LDR R3,[R0]
	LDR R4,[R1]
LOOP
	CMP R3,R4
	BCS SKIP
	MOV R5,R3
	B STORE
SKIP
	SUB R3,R3,R4
	ADD R2,#1
	B LOOP
STORE
	STR R2,[R6]
	STR R5,[R7]
STOP
	B STOP
VAL1 DCD 20
VAL2 DCD 5
	AREA mydata,DATA,READWRITE
QU DCD 0
REM DCD 0
	END
	