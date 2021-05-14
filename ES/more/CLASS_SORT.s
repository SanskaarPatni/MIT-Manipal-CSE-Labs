;Write an assembly program to sort an array using selection sort

	AREA    RESET, DATA, READONLY
     	EXPORT  __Vectors

__Vectors 
	DCD  0x40001000     ; stack pointer value when stack is empty
      DCD  Reset_Handler  ; reset vector
  
    	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
		
Reset_Handler
	LDR R0, =LIST
	LDR R2, =RESULT
	MOV R3, #5
UP	LDR R1, [R0], #4
	STR R1, [R2], #4
	SUBS R3, R3, #1
	BNE UP
	LDR R2, =RESULT
	LDR R4, [R2]
	MOV R5, #1 ; I COUNTER
	MOV R6, #4
ABOVE	CMP R5, R6
	BHI LAST
	MOV R7, R2; MIN
	MOV R8, #5
	ADD R9, R5, #1 ;J COUNTER
	MOV R3, R7
L3	CMP R9, R8
	BHI L2
	
	LDR R10, [R7]
	ADD R3, R3,#4
	;MOV R12, R3
	LDR R11, [R3]
	CMP R10, R11
	MOVCS R7, R3
	ADD R9, #1
	B L3
L2	LDR R0, [R7]
	LDR R1, [R2]
	STR R0, [R2]
	STR R1, [R7]
	ADD R2, #4
	ADD R5, #1
	B ABOVE
LAST B LAST
LIST DCD 30,20,1,4,2
		AREA MYDATA, DATA, READWRITE
RESULT DCD 0
	END