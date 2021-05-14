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
	LDR R1,=SRC
	MOV R0,#0
	MOV R3,#0
	MOV R4,#10
	LDR R5,=DST
LOOP LDR R2,[R1]
	ADDS R0,R0,R2
	ADC R3,#0
	ADD R1,#4
	SUBS R4,#1
	BNE LOOP
	STR R0,[R5]
	STR R3,[R5,#4]
STOP
	B STOP
SRC DCD 1,2,1,2,1,2,1,2,1,2
	AREA mydata,DATA,READWRITE	
DST DCD 0
	END
	
	