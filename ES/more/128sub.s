	AREA    RESET, DATA, READONLY
    EXPORT  __Vectors

__Vectors 
      DCD  0x10001000     ; stack pointer value when stack is empty
      DCD  Reset_Handler  ; reset vector
      ALIGN
      AREA mycode, CODE, READONLY
      ENTRY
      EXPORT Reset_Handler
		
Reset_Handler
	LDR R0, =N1        
	LDR r1, =N2
	ldr r4, =dst
	mov r5, #4
	ldr r6, =0xffffffff
	msr xpsr, r6
	mov r8, #0
    ldr r2, [r0], #4
	ldr r3, [r1], #4
up	sbcs r7, r2, r3
	adc r8, #0
 	str r7, [r4], #4
	ldr r2, [r0], #4
	ldr r3, [r1], #4
	cmp R8, #0
	beq reset
	subs r5, #1
	mrs r9, xpsr
	orr r9, #0x20000000
	msr xpsr, r9
	bne up
	b STOP
reset	  
	subs r5, #1
	mrs r9, xpsr
	and r9, #0xdfffffff
	msr xpsr, r9
	bne up
STOP
	B STOP          ; Be there
N1 dcd 8,7,6,5	
N2 dcd 4,3,2,1	
	AREA mydata, DATA, READWRITE
dst DCD 0		 
	END