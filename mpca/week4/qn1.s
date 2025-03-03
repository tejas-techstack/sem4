.data 
A:  .byte 1,2,3,4,5,6,7,8,9,10

.text
  LDR R4, =A 
  MOV R2, #10
  MOV R3, #0

loop:
  LDRB R1, [R4]
  ADD R3, R3, R1
  ADD R4, R4, #1
  SUBS R2, R2, #1
  BNE loop

.end:
  SWI 0x011


