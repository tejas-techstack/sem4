.data 
A: .word 5,1,3,2,4

.text
LDR R1, =A
LDR R7, =A; store
MOV R2, #5
MOV R3, #0; elements in the inner list.
MOV R4, #0; minimum in the inner list.

loop:
  BL inner_loop
  SUB R2, R2, #1
  CMP R2, #1
  BNE loop
  B end

inner_loop:
  LDR R6, [R1], R3, LSL #2; load from inner array start.
  ADD R3, R3, #1
  CMP R3, #5
  BNE inner_loop
  BX lr

end: 0x011
