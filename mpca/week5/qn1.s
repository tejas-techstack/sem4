.DATA 
A: .word 1, 2, 3, 4, 5, 6, 7, 8, 9
B: .word 1, 1, 2, 2, 3, 3, 4 ,4 ,5
C: .word 0, 0 ,0, 0, 0, 0, 0 ,0 ,0

.TEXT 

LDR R0, =A;
LDR R1, =B;
LDR R2, =C;

MOV R3, #0; i
MOV R4, #0; j
MOV R8, #0; k
MOV R10, #3;
MOV R9, #0; sum

outer_loop:
  MOV R4, #0
  B middle_loop
outer_loop_return:
  ADD R3, R3, #1
  CMP R3, #3
  BNE outer_loop
  B finish

middle_loop:
  MOV R8, #0
  MOV R9, #0
  B inner_loop
middle_loop_return:
  ADD R4, R4, #1
  CMP R4, #3
  BNE middle_loop
  B outer_loop_return

inner_loop:
  MLA R5, R3, R10, R8
  MOV R5, R5, LSL #2
  LDR R5, [R0, R5]

  MLA R6, R8, R10, R4
  MOV R6, R6, LSL #2
  LDR R6, [R1, R6]

  MLA R9, R5, R6, R9

  ADD R8, R8, #1;
  CMP R8, #3;

  BNE inner_loop

  MLA R5, R3, R10, R4
  MOV R5, R5, LSL #2
  STR R9, [R2, R5]

  B middle_loop_return;

finish:
  SWI 0x011
