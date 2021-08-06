.export rng8_f
.code 						
.proc rng8_f			 
	beq @xor	
	asl 						
	beq @end				
	bcc @end 				  
	@xor: eor #$1d 			
	@end: rts   			
.endproc 