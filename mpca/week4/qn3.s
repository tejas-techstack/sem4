.data
A:.word 10,20,30,40,50,60,70,80,90
B:.word 1,2,3,4,5,6,7,8,9
C:.word 0,0,0,0,0,0,0,0,0

.text
LDR R0, =A;
LDR R1, =B;
LDR R2, =C;

MOV R3, #1;
MOV R4, #1;

outer_loop:
  BL inner_loop
  MOV R3, #1;
  ADD R4, R4, #1;
  CMP R4, #4;
  BNE outer_loop;
  B end;

inner_loop:
  LDR R7, [R0], #4;
  LDR R8, [R1], #4;
  ADD R5, R7, R8;
  STR R5, [R2], #4;
  ADD R3, R3, #1;
  CMP R3, #4;
  BNE inner_loop;
  BX lr;

end:
  SWI 0x011


