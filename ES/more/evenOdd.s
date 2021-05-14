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
	ldr r1,=even
	ldr r2,=odd
	mov r3,#5
	mov r5,#0
	mov r6,#0
loop CMP r3,#0
	beq store
	ldr r4,[r0],#4
	tst r4,#2_01
	beq eeven
	add r5,#1
	subs r3,#1
	b loop
eeven  add r6,#1
	subs r3,#1
	b loop
store str r6,[r1]
	str r5,[r2]
	
stop b stop
src dcd 1,2,3,4,5
	area mydata,data,readwrite
even dcd 0
odd dcd 0
		end