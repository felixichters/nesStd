.ifndef RNG16_H
RNG16_H = 1 
.include "../../MACROS.s"
	.import rng16_f
	.macro rng16 seed, out0, out1
        .if (.match (.left (1, {seed}), #))
			lda #<(.right (.tcount ({seed})-1, {seed}))
			ldx #>(.right (.tcount ({seed})-1, {seed}))
			jsr rng16_f
		.else
			lda seed 
			ldx 1+(seed)
			jsr rng16_f
        .endif
		.ifnblank out0 
			sta out0 
		.endif
		.ifnblank out1 
			stx out1 
		.endif 
	.endmacro 
.endif