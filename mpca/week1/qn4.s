MOV R1, #5
MOV R0, #5
CMP R0, R1
BEQ loc1
B loc2

loc1:
  ADD R2, R0, R1
  SWI 0x11

loc2:
  SUB R2, R1, R0
  SWI 0x11

