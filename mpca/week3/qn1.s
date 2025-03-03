.data
A: .WORD 10
B: .WORD 3

.text

ldr r0,=A;
ldr r0,[r0];
ldr r1,=B;
ldr r1,[r1];

loop:
  sub r0, r0, r1
  cmp r0, r1
  blt end
  b loop

end:
  swi 0x011


