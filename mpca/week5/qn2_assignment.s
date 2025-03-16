.data
mainString: .asciz "This is a test string"    
subString:  .asciz "test"


.text

LDR R1, =mainString
LDR R2, =subString
MOV R0, #0

searchLoop:
   MOV R3, R1
   MOV R4, R2

compareLoop:
   LDRB R5, [R4], #1
   CMP R5, #0
   BEQ found

   LDRB R6, [R3], #1
   CMP R6, #0
   BEQ notFound

   CMP R5, R6
   BEQ compareLoop

   ADD R1, R1, #1
   LDRB R6, [R1]
   CMP R6, #0
   BEQ notFound
   B searchLoop

found:
   MOV R0, #1
   B end

notFound:
   MOV R0, #0

end:
   SWI 0x11

