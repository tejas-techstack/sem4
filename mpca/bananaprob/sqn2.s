.data
prefix_expr: .asciz "+34"

.text
    LDR R0, =prefix_expr
    MOV R2, #0

find_end:
    LDRB R1, [R0, R2]
    CMP R1, #0
    BEQ eval_loop
    ADD R2, R2, #1
    B find_end

eval_loop:
    SUB R2, R2, #1
    CMP R2, #0
    BLT done

    LDRB R1, [R0, R2]
    SUB R1, R1, #'0'
    CMP R1, #0
    BLT operator_found

    STR R1, [SP, #-4]!
    B eval_loop

operator_found:
    LDR R3, [SP], #4
    LDR R4, [SP], #4

    CMP R1, #('+' - '0')
    BEQ add_operands
    CMP R1, #('-' - '0')
    BEQ subtract_operands

add_operands:
    ADD R5, R4, R3
    STR R5, [SP, #-4]!
    B eval_loop

subtract_operands:
    SUB R5, R4, R3
    STR R5, [SP, #-4]!
    B eval_loop

done:
    LDR R0, [SP], #4
    MOV R1, #1
    MOV R7, #1
    SWI 0

