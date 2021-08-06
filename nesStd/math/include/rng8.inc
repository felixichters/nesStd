.ifndef RNG8_H 
RNG8_H = 1 
.include "../../MACROS.s"
.import rng8_f 
.macro rng8 seed, out
	lda seed  
	jsr rng8_f
	.ifnblank out 
		sta out 
	.endif 
.endmacro 
.endif 