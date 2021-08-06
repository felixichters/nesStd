.export rng16_f
.code 						
.proc rng16_f		    
	ldy #$08		 					
    @iterate:		
        asl    		
		pha			  
		txa 		
        rol 		
		tax 
		pla 
        bcc @no_xor			
        eor #$39   			
    @no_xor: 				
        dey					
        bne @iterate 
    rts						
.endproc