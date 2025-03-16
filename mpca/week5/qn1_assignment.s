.data
A:  .asciz "dog"
B:  .asciz "The swapped string is"

.text
LDR R0, =A
SWI 0x02

MOV R1, #3
SUB R1, R1, #1
MOV R4, #0

LDRB R2, [R0, R4]
LDRB R3, [R0, R1]

STRB R3, [R0, R4]
STRB R2, [R0, R1]

LDR R0, =B
SWI 0x02 

LDR R0, =A
SWI 0x02

SWI 0x011
