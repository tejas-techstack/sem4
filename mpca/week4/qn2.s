.data
A:.word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16

.text
LDR R1, =A;
MOV R2, #16;
MOV R3, #1;
MOV R4, #1;
MOV R6, #5;
MOV R7, #0;

outer_loop:
  BL inner_loop;
  MOV R4, #1;
  ADD R3, R3, #1;
  CMP R3, #5;
  BNE outer_loop;
  B end;


inner_loop:
  CMP R3, R4;
  STREQ R6, [R1];
  STRNE R7, [R1];
  ADD R1, R1, #4;
  ADD R4, R4, #1;
  CMP R4, #5;
  BNE inner_loop;
  BX lr;

end:
  SWI 0x011

