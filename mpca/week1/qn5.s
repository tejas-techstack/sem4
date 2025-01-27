MOV R0, #7
ANDS R2, R0, #1
CMP R2, #0
BEQ loc1
BNE loc2

loc1:
  MOV R0, #0x00
  SWI 0x11
loc2:
  MOV R0, #0xFF
  SWI 0x11
