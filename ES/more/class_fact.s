;Write an assembly program to find the factorial of a unsigned number using recursion

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
	LDR R0, =NUM
	LDR R1, =RESULT
	LDR R2, [R0]
	BL FACT
	STR R2, [R1]
B HERE B
FACT CMP R2, #0
	MOVEQ R2, #1
	BEQ L1
	PUSH {R2, LR}
	SUB R2, #1
	BL	FACT 
L1 POP {R3, LR}
	MUL R2, R3
	BX LR
NUM DCD 0X3
	AREA MYDATA, DATA, READWRITE
RESULT DCD 0
	END