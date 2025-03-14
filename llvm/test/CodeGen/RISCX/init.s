	.attribute	4, 16
	.attribute	5, "rv32i2p1"
	.file	"init.ll"
	.text
	.globl	add                             # -- Begin function add
	.p2align	2
	.type	add,@function
add:                                    # @add
	.cfi_startproc
# %bb.0:
	add	a0, a0, a1
	ret
.Lfunc_end0:
	.size	add, .Lfunc_end0-add
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
