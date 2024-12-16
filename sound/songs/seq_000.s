	.section .rodata
	.global	seq_000
	.align	2
	
seq_000:
	.byte	0	@ NumTrks
	.byte	0	@ NumBlks
	.byte	50	@ Priority
	.byte	128	@ Reverb

	.word	bank_000
	