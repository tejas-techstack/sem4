.data
A: .word 1,2,3,4,5,6,7,8

.text
LDR R3, =A
MOV R4, #1
MOV R1, #0
MOV R2, #5

loop:
  LDR R5, [R3], #4
  ADD R1, R2, R3
  ADD R4, R4, #1
  CMP R4, #8
  BNE loop

SWI 0x11
