.ifndef RNG16O_H
RNG16O_H = 1 
.include "../../MACROS.s"
.importzp seed16o 
.import rng16o_f 
.macro rng16o seed, out0, out1
    .if (.match (.left (1, {seed}), #))
		lda #<(.right (.tcount ({seed})-1, {seed}))
		sta seed16o+0
		lda #>(.right (.tcount ({seed})-1, {seed}))
		jsr rng16o_f
	.else
		lda seed
		sta seed16o 
		lda 1+(seed)
		jsr rng16o_f
    .endif
	.ifnblank out0 
		sta out0 
	.endif
	.ifnblank out1 
		lda seed16o+1 
		sta out1
	.endif 
.endmacro 
.endif 
;eof