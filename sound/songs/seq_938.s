@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_938_grp, bank_026
	.equ	seq_938_pri, 127
	.equ	seq_938_rev, 0
	.equ	seq_938_mvl, 127
	.equ	seq_938_key, 0

	.section .rodata
	.global	seq_938
	.align	2

@*********************** Track 01 ***********************@

seq_938_0:
	.byte	KEYSH , seq_938_key+0
	.byte	TEMPO , 200/2
	.byte		VOICE , 6
	.byte		VOL   , 127*seq_938_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 20
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N05   , Fn3 , v120
	.byte	W06
	.byte		N10   , Fn3 , v080
	.byte	W10
	.byte		N12   , En3 , v020
	.byte	W01
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v-23
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

seq_938:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_938_pri	@ Priority
	.byte	seq_938_rev	@ Reverb

	.word	seq_938_grp

	.word	seq_938_0

	.end
