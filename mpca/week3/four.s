.data
A: .word 1,2,3
    .word 4,5,6
    .word 7,8,9

.text

LDR R2, = A
MOV R3, #3
MOV R0, #1
MOV R1, #2

MLA R4, R0, R3, R1
MOV R5, R4, LSL #2
ADD R6, R5, R2

SWI 0x011
