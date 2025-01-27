MOV R0, #0x0A
MOV R1, #0x0F
gcd:
    CMP R0, R1
    BEQ end
    CMP R0, R1
    BGT firstgreater
    SUB R1, R1, R0
    B gcd
firstgreater:
    SUB R0, R0, R1
    B gcd
end:
  MOV R2, R0
  SWI 0x11
