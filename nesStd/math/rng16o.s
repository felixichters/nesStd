.include "../MACROS.s"
.reszp seed,2
seed16o = seed 
.exportzp seed16o 
.export rng16o_f

.code 
.proc rng16o_f
	tay 
	lsr 
	lsr
	lsr
	sta seed+1 
	lsr
	eor seed+1
	lsr
	eor seed+1
	eor seed+0 
	sta seed+1
	tya 
	sta seed+0
	asl
	eor seed+0
	asl
	eor seed+0
	asl
	asl
	asl
	eor seed+0
	rts
.endproc 