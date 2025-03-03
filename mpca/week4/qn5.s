.DATA
     
A:       .word 1,2,3,4,5,6,7,8,9,10 
B:       .word 0,0,0,0,0,0,0,0,0,0             

.TEXT
        LDR R0, =A         
        LDR R1, =B         
        MOV R2, #10        

COPY_LOOP:
        LDR R3, [R0], #4
        STR R3, [R1], #4   
        SUBS R2, R2, #1   
        BNE COPY_LOOP      
        LDR R0, =A        
        LDR R1, =B        
        ADD R1, R1, #36   
        MOV R2, #10      
REVERSE_LOOP:
        LDR R3, [R1], #-4  
        STR R3, [R0], #4  
        SUBS R2, R2, #1    
        BNE REVERSE_LOOP   
SWI 0x011
