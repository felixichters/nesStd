.feature leading_dot_in_identifiers

.ifndef MAC 
MAC = 1 

.macro .pushreg reg 
.ifblank reg 
	pha 
	txa 
	pha 
	tya 
	pha 
.else 
	lda reg 
	pha 
.endif 
.endmacro

.macro .popreg reg 
.ifblank reg 
	pla 
	tay 
	pla 
	tax 
	pla 
.else 
	pla  
.endif 
.endmacro 

.macro .reszp label, size 
	.pushseg 
		.zeropage 
			label: .res size 
	.popseg 
.endmacro  

.endif 