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
	MOV R0, #3
	MOV R1, #5
	MOV R2, #4
	MOV R3, #1
	MOV R4, #2
	STM R13!, {R0-R4}
	MOV R5, #4
	MOV R6, #1
	MOV R12, R13
	MOV R2, R12
AB	CMP R6, R5
	BHI L1
	MOV R7, R2; MAX
	MOV R10, R2
	
	MOV R8, #5
	ADD R9, R6, #1
UP	CMP R9, R8
	BHI L2
	SUB R10, R10, #4
	LDMDB R7, {R0}
	LDMDB R10, {R1}
	CMP R1, R0
	MOVCS R7, R10
	ADD R9, #1
	B UP
L2	LDMDB R7!, {R3}
	LDMDB R2!, {R4}
	STM R2, {R3}
	STM R7, {R4}
	ADD R6, #1
	;SUB R2, #4
	B AB
	
	
L1 LDMDB R13!, {R0-R9}
	 
	END