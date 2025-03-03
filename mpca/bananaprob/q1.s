.data
    array:  .word 5, 1, 2, 3, 4

.text

    LDR R4, =array
    MOV R6, #5
    MOV R0, #0

outer_loop:
    CMP R0, R6
    BEQ done

    MOV R1, R0
    ADD R2, R0, #1

inner_loop:
    CMP R2, R6
    BEQ swap

    LDR R7, [R4, R1, LSL #2]
    LDR R8, [R4, R2, LSL #2]

    CMP R8, R7
    BGE skip
    MOV R1, R2

skip:
    ADD R2, R2, #1
    B inner_loop

swap:
    CMP R1, R0
    BEQ continue_outer

    LDR R7, [R4, R0, LSL #2]
    LDR R8, [R4, R1, LSL #2]
    STR R8, [R4, R0, LSL #2]
    STR R7, [R4, R1, LSL #2]

continue_outer:
    ADD R0, R0, #1
    B outer_loop

done:
    MOV R7, #1
    SWI 0x11
