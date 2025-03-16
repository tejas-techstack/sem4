.data
str: .asciz "CROCODILE"

.text
	LDR R0, =str
	MOV R1, #0
loop:
	LDRB R2, [R0]
	
	CMP R2, #0
	BEQ DONE
	ADDNE R1, R1, #1
	ADD R0, R0, #1
	B loop
	
DONE: 
	SWI 0X011
