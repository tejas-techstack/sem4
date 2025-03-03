    .DATA
    NUM: .word 0x17845374

    .text

            LDR R1, =NUM    
            LDR R1, [R1]    
            MOV R2, #0          
            MOV R3, #8          

    FIND_MAX_LOOP:
            AND R4, R1, #0xF    
            CMP R4, R2          
            BLS SKIP_UPDATE     
            MOV R2, R4          

    SKIP_UPDATE:
            MOV R1, R1, LSR #4      
            SUBS R3, R3, #1     
            BNE FIND_MAX_LOOP   

    SWI 0x011
