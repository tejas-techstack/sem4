.DATA
A:.hword 1,2,3,4,5,6,7,8,9

.text

ldr r3,=A;
ldrh r1,[r3];
mov r2,#9;

loop:
  cmp r1, #12
  beq endFound
  add r1, r1, #1
  subs r2, r2, #1
  beq endNotFound
  b loop

endFound:
  mov r5, #1
  swi 0x011

endNotFound:
  mov r5, #-1
  swi 0x011


