		.global _start
	.section .data
expr:   .ascii "-+92+34\0"
	.section .text
_start:
	LDR R0, =expr
	BL evaluate
	B end

evaluate:
	MOV R3, #0
	MOV SP, #0x5400
loop:
	LDRB R4, [R0, R3]
	CMP R4, #0
	BEQ done
	ADD R3, R3, #1
	CMP R4, #'0'
	BLT is_operator
	CMP R4, #'9'
	BGT is_operator
	SUB R4, R4, #'0'
	STR R4, [SP, #-4]!
	B loop

is_operator:
	LDR R5, [SP], #4
	LDR R6, [SP], #4
	CMP R4, #'+'
	BEQ do_add
	CMP R4, #'-'
	BEQ do_sub
	B loop

do_add:
	ADD R0, R5, R6
	B push_result

do_sub:
	SUB R0, R6, R5
	B push_result

push_result:
	STR R0, [SP, #-4]!
	B loop

done:
	LDR R0, [SP], #4
	B end

end:
	MOV R7, #1
	swi 0
