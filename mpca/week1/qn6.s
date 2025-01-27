MOV R0, #0x05
MOV R1, #0x01

fact:
    CMP R0, #0
    BEQ end
    MUL R1, R0, R1
    SUB R0, R0, #1
    B fact
end:
    SWI 0x11
