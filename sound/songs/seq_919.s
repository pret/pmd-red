@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_919_grp, bank_028
	.equ	seq_919_pri, 127
	.equ	seq_919_rev, 0
	.equ	seq_919_mvl, 127
	.equ	seq_919_key, 0

	.section .rodata
	.global	seq_919
	.align	2

@*********************** Track 01 ***********************@

seq_919_0:
	.byte	KEYSH , seq_919_key+0
	.byte	TEMPO , 190/2
	.byte		VOICE , 6
	.byte		VOL   , 95*seq_919_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 60
	.byte		MODT  , mod_pan
	.byte	W01
	.byte		N06   , Ds2 , v120
	.byte	W06
	.byte		        Gn3 
	.byte	W05
	.byte		VOICE , 13
	.byte	W01
	.byte		N03   , Cs2 
	.byte	W03
	.byte		N06   , As2 
	.byte	W06
	.byte		        As2 , v040
	.byte	W06
	.byte		        As2 , v020
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

seq_919:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_919_pri	@ Priority
	.byte	seq_919_rev	@ Reverb

	.word	seq_919_grp

	.word	seq_919_0

	.end
