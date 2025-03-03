.data
NUM: .WORD 0x788

    .text
    LDR R0, =NUM
    LDR R1, [R0]
    MOV R2, #0

loop:
    AND R3, R1, #0xF
    ADD R2, R2, R3
    MOV R1, R1, LSR #4
    CMP R1, #0
    BNE loop

    SWI 0x11

