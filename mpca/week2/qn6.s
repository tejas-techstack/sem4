.data
number:  .WORD 0x7E
result:  .WORD 0

.text
    LDR R0, =number
    LDR R1, [R0]
    MOV R2, #0
    MOV R3, #32

check_parity:
    AND R4, R1, #1
    ADD R2, R2, R4
    LSR R1, R1, #1
    SUBS R3, R3, #1
    BNE check_parity

    AND R2, R2, #1
    EOR R2, R2, #1

    LDR R0, =result
    STR R2, [R0]

    SWI 0x11
