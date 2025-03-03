.data
A:  .WORD 1, 2, 3, 4, 5
B:  .WORD 6, 7, 8, 9, 10
SUM: .WORD 0

    .text
    LDR R1, =A
    LDR R2, =B
    MOV R0, #5
    MOV R3, #0

loop:
    LDR R4, [R1], #4
    LDR R5, [R2], #4
    MLA R3, R4, R5, R3
    SUBS R0, R0, #1
    BNE loop

    LDR R0, =SUM
    STR R3, [R0]

    SWI 0x11


