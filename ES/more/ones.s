	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	dcd Reset_Handler
	ALIGN 
	AREA MYDATA,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR r0,=src
	ldr r3,[r0]
	ldr r1,=ans
	mov r4,#0
loop CMP r3,#0
	beq store
	tst r3,#2_01
	bne eone
	lsr r3,#1
	b loop
eone add r4,#1
	lsr r3,#1
	b loop
	
	
store str r4,[r1]
stop b stop
src dcd 0x10
	area mydata,data,readwrite
ans dcd 0
		end