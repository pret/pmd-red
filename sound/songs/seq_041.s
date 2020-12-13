@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_041_grp, bank_000
	.equ	seq_041_pri, 50
	.equ	seq_041_rev, 218
	.equ	seq_041_mvl, 127
	.equ	seq_041_key, 0

	.section .rodata
	.global	seq_041
	.align	2

@*********************** Track 01 ***********************@

seq_041_0:
	.byte	KEYSH , seq_041_key+0
	.byte	TEMPO , 70/2
	.byte		VOICE , 46
	.byte		VOL   , 88*seq_041_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 60
	.byte		LFOS  , 50
	.byte		MODT  , mod_pan
	.byte	W32
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		N04   , Dn5 , v068
	.byte	W06
	.byte		        Dn5 , v012
	.byte	W06
	.byte		        Cs5 , v068
	.byte	W06
	.byte		        Cs5 , v012
	.byte	W06
	.byte		        An4 , v068
	.byte	W06
	.byte		        An4 , v012
	.byte	W06
	.byte	PEND
	.byte	W96
	.byte	PATT
	 .word	seq_041_0 + 0x1A
	.byte	W96
	.byte	PATT
	 .word	seq_041_0 + 0x1A
	.byte	W96
	.byte	PATT
	 .word	seq_041_0 + 0x1A
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	seq_041_0 + 0x17
	.byte	FINE

@*********************** Track 02 ***********************@

seq_041_1:
	.byte	KEYSH , seq_041_key+0
	.byte	W03
	.byte		VOICE , 24
	.byte		VOL   , 98*seq_041_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		MODT  , mod_pan
	.byte	W30
	.byte	W01
	.byte		MOD   , 50
	.byte		VOL   , 0*seq_041_mvl/mxv
	.byte	W01
	.byte		TIE   , Gn4 , v056
	.byte	W02
	.byte		VOL   , 3*seq_041_mvl/mxv
	.byte	W02
	.byte		        1*seq_041_mvl/mxv
	.byte	W02
	.byte		        2*seq_041_mvl/mxv
	.byte	W01
	.byte		        3*seq_041_mvl/mxv
	.byte	W02
	.byte		        4*seq_041_mvl/mxv
	.byte	W01
	.byte		        5*seq_041_mvl/mxv
	.byte	W02
	.byte		        6*seq_041_mvl/mxv
	.byte	W01
	.byte		        7*seq_041_mvl/mxv
	.byte	W02
	.byte		        8*seq_041_mvl/mxv
	.byte	W02
	.byte		        10*seq_041_mvl/mxv
	.byte	W01
	.byte		        10*seq_041_mvl/mxv
	.byte	W02
	.byte		        12*seq_041_mvl/mxv
	.byte	W01
	.byte		        13*seq_041_mvl/mxv
	.byte	W02
	.byte		        14*seq_041_mvl/mxv
	.byte	W01
	.byte		        15*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        18*seq_041_mvl/mxv
	.byte	W01
	.byte		        18*seq_041_mvl/mxv
	.byte	W02
	.byte		        20*seq_041_mvl/mxv
	.byte	W01
	.byte		        20*seq_041_mvl/mxv
	.byte	W02
	.byte		        22*seq_041_mvl/mxv
	.byte	W01
	.byte		        22*seq_041_mvl/mxv
	.byte	W02
	.byte		        24*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W01
	.byte		        26*seq_041_mvl/mxv
	.byte	W02
	.byte		        27*seq_041_mvl/mxv
	.byte	W01
	.byte		        28*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W01
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        32*seq_041_mvl/mxv
	.byte	W02
	.byte		        33*seq_041_mvl/mxv
	.byte	W01
	.byte		        34*seq_041_mvl/mxv
	.byte	W02
	.byte		        36*seq_041_mvl/mxv
	.byte	W01
	.byte		        36*seq_041_mvl/mxv
	.byte	W02
	.byte		        39*seq_041_mvl/mxv
	.byte	W01
	.byte		        41*seq_041_mvl/mxv
	.byte	W02
	.byte		        44*seq_041_mvl/mxv
	.byte	W02
	.byte		        47*seq_041_mvl/mxv
	.byte	W01
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        53*seq_041_mvl/mxv
	.byte	W01
	.byte		        54*seq_041_mvl/mxv
	.byte	W02
	.byte		        58*seq_041_mvl/mxv
	.byte	W01
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        62*seq_041_mvl/mxv
	.byte	W04
	.byte		        69*seq_041_mvl/mxv
	.byte	W03
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        77*seq_041_mvl/mxv
	.byte	W03
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        86*seq_041_mvl/mxv
	.byte	W03
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W03
	.byte		        99*seq_041_mvl/mxv
	.byte	W04
	.byte	PEND
	.byte	W09
	.byte		VOL   , 99*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W02
	.byte		        95*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        92*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        89*seq_041_mvl/mxv
	.byte	W02
	.byte		        85*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W02
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W02
	.byte		        78*seq_041_mvl/mxv
	.byte	W01
	.byte		        78*seq_041_mvl/mxv
	.byte	W02
	.byte		        76*seq_041_mvl/mxv
	.byte	W02
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        71*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W02
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        63*seq_041_mvl/mxv
	.byte	W01
	.byte		        62*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        55*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        42*seq_041_mvl/mxv
	.byte	W02
	.byte		        37*seq_041_mvl/mxv
	.byte	W01
	.byte		        35*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        11*seq_041_mvl/mxv
	.byte	W02
	.byte		        7*seq_041_mvl/mxv
	.byte	W14
	.byte		MOD   , 50
	.byte		VOL   , 0*seq_041_mvl/mxv
	.byte	W01
	.byte	PEND
	.byte		EOT   , Gn4 
	.byte		TIE   , Fs4 , v056
	.byte	W02
	.byte		VOL   , 3*seq_041_mvl/mxv
	.byte	W02
	.byte		        1*seq_041_mvl/mxv
	.byte	W02
	.byte		        2*seq_041_mvl/mxv
	.byte	W01
	.byte		        3*seq_041_mvl/mxv
	.byte	W02
	.byte		        4*seq_041_mvl/mxv
	.byte	W01
	.byte		        5*seq_041_mvl/mxv
	.byte	W02
	.byte		        6*seq_041_mvl/mxv
	.byte	W01
	.byte		        7*seq_041_mvl/mxv
	.byte	W02
	.byte		        8*seq_041_mvl/mxv
	.byte	W02
	.byte		        10*seq_041_mvl/mxv
	.byte	W01
	.byte		        10*seq_041_mvl/mxv
	.byte	W02
	.byte		        12*seq_041_mvl/mxv
	.byte	W01
	.byte		        13*seq_041_mvl/mxv
	.byte	W02
	.byte		        14*seq_041_mvl/mxv
	.byte	W01
	.byte		        15*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        18*seq_041_mvl/mxv
	.byte	W01
	.byte		        18*seq_041_mvl/mxv
	.byte	W02
	.byte		        20*seq_041_mvl/mxv
	.byte	W01
	.byte		        20*seq_041_mvl/mxv
	.byte	W02
	.byte		        22*seq_041_mvl/mxv
	.byte	W01
	.byte		        22*seq_041_mvl/mxv
	.byte	W02
	.byte		        24*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W01
	.byte		        26*seq_041_mvl/mxv
	.byte	W02
	.byte		        27*seq_041_mvl/mxv
	.byte	W01
	.byte		        28*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W01
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        32*seq_041_mvl/mxv
	.byte	W02
	.byte		        33*seq_041_mvl/mxv
	.byte	W01
	.byte		        34*seq_041_mvl/mxv
	.byte	W02
	.byte		        36*seq_041_mvl/mxv
	.byte	W01
	.byte		        36*seq_041_mvl/mxv
	.byte	W02
	.byte		        39*seq_041_mvl/mxv
	.byte	W01
	.byte		        41*seq_041_mvl/mxv
	.byte	W02
	.byte		        44*seq_041_mvl/mxv
	.byte	W02
	.byte		        47*seq_041_mvl/mxv
	.byte	W01
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        53*seq_041_mvl/mxv
	.byte	W01
	.byte		        54*seq_041_mvl/mxv
	.byte	W02
	.byte		        58*seq_041_mvl/mxv
	.byte	W01
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        62*seq_041_mvl/mxv
	.byte	W04
	.byte		        69*seq_041_mvl/mxv
	.byte	W03
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        77*seq_041_mvl/mxv
	.byte	W03
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        86*seq_041_mvl/mxv
	.byte	W03
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W03
	.byte		        99*seq_041_mvl/mxv
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Fs4 
	.byte	PATT
	 .word	seq_041_1 + 0x13
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Gn4 
	.byte	PATT
	 .word	seq_041_1 + 0xD9
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Fs4 
	.byte	PATT
	 .word	seq_041_1 + 0x13
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Gn4 
	.byte	PATT
	 .word	seq_041_1 + 0xD9
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Fs4 
	.byte	PATT
	 .word	seq_041_1 + 0x13
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Gn4 
	.byte	PATT
	 .word	seq_041_1 + 0xD9
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Fs4 
	.byte	PATT
	 .word	seq_041_1 + 0x13
	.byte	PATT
	 .word	seq_041_1 + 0x81
	.byte		EOT   , Gn4 
	.byte	PATT
	 .word	seq_041_1 + 0xD9
	.byte	W09
	.byte		VOL   , 99*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W02
	.byte		        95*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        92*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        89*seq_041_mvl/mxv
	.byte	W02
	.byte		        85*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W02
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W02
	.byte		        78*seq_041_mvl/mxv
	.byte	W01
	.byte		        78*seq_041_mvl/mxv
	.byte	W02
	.byte		        76*seq_041_mvl/mxv
	.byte	W02
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        71*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W02
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        63*seq_041_mvl/mxv
	.byte	W01
	.byte		        62*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        55*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        42*seq_041_mvl/mxv
	.byte	W02
	.byte		        37*seq_041_mvl/mxv
	.byte	W01
	.byte		        35*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        11*seq_041_mvl/mxv
	.byte	W02
	.byte		        7*seq_041_mvl/mxv
	.byte	W15
	.byte		EOT   , Fs4 
	.byte	GOTO
	 .word	seq_041_1 + 0x14E
	.byte	FINE

@*********************** Track 03 ***********************@

seq_041_2:
	.byte	KEYSH , seq_041_key+0
	.byte	W05
	.byte		VOICE , 4
	.byte		VOL   , 108*seq_041_mvl/mxv
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		MOD   , 45
	.byte		MODT  , mod_tre
	.byte	W28
	.byte	W01
	.byte		VOL   , 0*seq_041_mvl/mxv
	.byte	W01
	.byte		TIE   , Dn2 , v100
	.byte	W02
	.byte		VOL   , 3*seq_041_mvl/mxv
	.byte	W02
	.byte		        5*seq_041_mvl/mxv
	.byte	W02
	.byte		        8*seq_041_mvl/mxv
	.byte	W01
	.byte		        10*seq_041_mvl/mxv
	.byte	W02
	.byte		        12*seq_041_mvl/mxv
	.byte	W01
	.byte		        14*seq_041_mvl/mxv
	.byte	W02
	.byte		        17*seq_041_mvl/mxv
	.byte	W01
	.byte		        18*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        24*seq_041_mvl/mxv
	.byte	W01
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        28*seq_041_mvl/mxv
	.byte	W01
	.byte		        29*seq_041_mvl/mxv
	.byte	W02
	.byte		        32*seq_041_mvl/mxv
	.byte	W01
	.byte		        33*seq_041_mvl/mxv
	.byte	W02
	.byte		        36*seq_041_mvl/mxv
	.byte	W02
	.byte		        39*seq_041_mvl/mxv
	.byte	W01
	.byte		        40*seq_041_mvl/mxv
	.byte	W02
	.byte		        43*seq_041_mvl/mxv
	.byte	W01
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        47*seq_041_mvl/mxv
	.byte	W01
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        54*seq_041_mvl/mxv
	.byte	W01
	.byte		        56*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W01
	.byte		        60*seq_041_mvl/mxv
	.byte	W02
	.byte		        62*seq_041_mvl/mxv
	.byte	W01
	.byte		        63*seq_041_mvl/mxv
	.byte	W02
	.byte		        66*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W01
	.byte		        70*seq_041_mvl/mxv
	.byte	W02
	.byte		        73*seq_041_mvl/mxv
	.byte	W01
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        77*seq_041_mvl/mxv
	.byte	W01
	.byte		        79*seq_041_mvl/mxv
	.byte	W02
	.byte		        81*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W01
	.byte		        86*seq_041_mvl/mxv
	.byte	W02
	.byte		        88*seq_041_mvl/mxv
	.byte	W01
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W01
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W24
	.byte	W02
	.byte	PEND
	.byte	W09
	.byte		VOL   , 99*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W02
	.byte		        95*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        92*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        89*seq_041_mvl/mxv
	.byte	W02
	.byte		        85*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W02
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W02
	.byte		        78*seq_041_mvl/mxv
	.byte	W01
	.byte		        78*seq_041_mvl/mxv
	.byte	W02
	.byte		        76*seq_041_mvl/mxv
	.byte	W02
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        71*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W02
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        63*seq_041_mvl/mxv
	.byte	W01
	.byte		        62*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        55*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        42*seq_041_mvl/mxv
	.byte	W02
	.byte		        37*seq_041_mvl/mxv
	.byte	W01
	.byte		        35*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        11*seq_041_mvl/mxv
	.byte	W02
	.byte		        7*seq_041_mvl/mxv
	.byte	W14
	.byte		        0*seq_041_mvl/mxv
	.byte	W01
	.byte	PEND
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	PATT
	 .word	seq_041_2 + 0x72
	.byte		EOT   , Dn2 
	.byte	PATT
	 .word	seq_041_2 + 0x13
	.byte	W09
	.byte		VOL   , 99*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W02
	.byte		        95*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        92*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        89*seq_041_mvl/mxv
	.byte	W02
	.byte		        85*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W02
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W02
	.byte		        78*seq_041_mvl/mxv
	.byte	W01
	.byte		        78*seq_041_mvl/mxv
	.byte	W02
	.byte		        76*seq_041_mvl/mxv
	.byte	W02
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        71*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W02
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        63*seq_041_mvl/mxv
	.byte	W01
	.byte		        62*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        55*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        42*seq_041_mvl/mxv
	.byte	W02
	.byte		        37*seq_041_mvl/mxv
	.byte	W01
	.byte		        35*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        11*seq_041_mvl/mxv
	.byte	W02
	.byte		        7*seq_041_mvl/mxv
	.byte	W15
	.byte		EOT   , Dn2 
	.byte	GOTO
	 .word	seq_041_2 + 0xD3
	.byte	FINE

@*********************** Track 04 ***********************@

seq_041_3:
	.byte	KEYSH , seq_041_key+0
	.byte	W07
	.byte		VOICE , 4
	.byte		VOL   , 108*seq_041_mvl/mxv
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		MOD   , 25
	.byte		MODT  , mod_tre
	.byte	W24
	.byte	W03
	.byte		VOL   , 0*seq_041_mvl/mxv
	.byte	W01
	.byte		TIE   , An2 , v100
	.byte	W02
	.byte		VOL   , 3*seq_041_mvl/mxv
	.byte	W02
	.byte		        5*seq_041_mvl/mxv
	.byte	W02
	.byte		        8*seq_041_mvl/mxv
	.byte	W01
	.byte		        10*seq_041_mvl/mxv
	.byte	W02
	.byte		        12*seq_041_mvl/mxv
	.byte	W01
	.byte		        14*seq_041_mvl/mxv
	.byte	W02
	.byte		        17*seq_041_mvl/mxv
	.byte	W01
	.byte		        18*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        24*seq_041_mvl/mxv
	.byte	W01
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        28*seq_041_mvl/mxv
	.byte	W01
	.byte		        29*seq_041_mvl/mxv
	.byte	W02
	.byte		        32*seq_041_mvl/mxv
	.byte	W01
	.byte		        33*seq_041_mvl/mxv
	.byte	W02
	.byte		        36*seq_041_mvl/mxv
	.byte	W02
	.byte		        39*seq_041_mvl/mxv
	.byte	W01
	.byte		        40*seq_041_mvl/mxv
	.byte	W02
	.byte		        43*seq_041_mvl/mxv
	.byte	W01
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        47*seq_041_mvl/mxv
	.byte	W01
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        54*seq_041_mvl/mxv
	.byte	W01
	.byte		        56*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W01
	.byte		        60*seq_041_mvl/mxv
	.byte	W02
	.byte		        62*seq_041_mvl/mxv
	.byte	W01
	.byte		        63*seq_041_mvl/mxv
	.byte	W02
	.byte		        66*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W01
	.byte		        70*seq_041_mvl/mxv
	.byte	W02
	.byte		        73*seq_041_mvl/mxv
	.byte	W01
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        77*seq_041_mvl/mxv
	.byte	W01
	.byte		        79*seq_041_mvl/mxv
	.byte	W02
	.byte		        81*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W01
	.byte		        86*seq_041_mvl/mxv
	.byte	W02
	.byte		        88*seq_041_mvl/mxv
	.byte	W01
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W01
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W24
	.byte	W02
	.byte	PEND
	.byte	W09
	.byte		VOL   , 99*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W02
	.byte		        95*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        92*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        89*seq_041_mvl/mxv
	.byte	W02
	.byte		        85*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W02
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W02
	.byte		        78*seq_041_mvl/mxv
	.byte	W01
	.byte		        78*seq_041_mvl/mxv
	.byte	W02
	.byte		        76*seq_041_mvl/mxv
	.byte	W02
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        71*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W02
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        63*seq_041_mvl/mxv
	.byte	W01
	.byte		        62*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        55*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        42*seq_041_mvl/mxv
	.byte	W02
	.byte		        37*seq_041_mvl/mxv
	.byte	W01
	.byte		        35*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        11*seq_041_mvl/mxv
	.byte	W02
	.byte		        7*seq_041_mvl/mxv
	.byte	W14
	.byte		        0*seq_041_mvl/mxv
	.byte	W01
	.byte	PEND
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	PATT
	 .word	seq_041_3 + 0x72
	.byte		EOT   , An2 
	.byte	PATT
	 .word	seq_041_3 + 0x13
	.byte	W09
	.byte		VOL   , 99*seq_041_mvl/mxv
	.byte	W02
	.byte		        98*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W02
	.byte		        95*seq_041_mvl/mxv
	.byte	W02
	.byte		        94*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        92*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        89*seq_041_mvl/mxv
	.byte	W02
	.byte		        85*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W02
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W02
	.byte		        78*seq_041_mvl/mxv
	.byte	W01
	.byte		        78*seq_041_mvl/mxv
	.byte	W02
	.byte		        76*seq_041_mvl/mxv
	.byte	W02
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        71*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte	W02
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        63*seq_041_mvl/mxv
	.byte	W01
	.byte		        62*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W02
	.byte		        55*seq_041_mvl/mxv
	.byte	W02
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W02
	.byte		        45*seq_041_mvl/mxv
	.byte	W02
	.byte		        42*seq_041_mvl/mxv
	.byte	W02
	.byte		        37*seq_041_mvl/mxv
	.byte	W01
	.byte		        35*seq_041_mvl/mxv
	.byte	W02
	.byte		        30*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W02
	.byte		        21*seq_041_mvl/mxv
	.byte	W02
	.byte		        16*seq_041_mvl/mxv
	.byte	W02
	.byte		        11*seq_041_mvl/mxv
	.byte	W02
	.byte		        7*seq_041_mvl/mxv
	.byte	W15
	.byte		EOT   , An2 
	.byte	GOTO
	 .word	seq_041_3 + 0xD3
	.byte	FINE

@*********************** Track 05 ***********************@

seq_041_4:
	.byte	KEYSH , seq_041_key+0
	.byte	W09
	.byte		VOICE , 51
	.byte		MOD   , 0
	.byte		LFOS  , 35
	.byte	W02
	.byte		VOL   , 0*seq_041_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MODT  , mod_pan
	.byte	W24
	.byte	W01
	.byte	W04
	.byte		VOL   , 2*seq_041_mvl/mxv
	.byte	W02
	.byte		        4*seq_041_mvl/mxv
	.byte	W02
	.byte		        7*seq_041_mvl/mxv
	.byte	W03
	.byte		        10*seq_041_mvl/mxv
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N04   , An3 , v088
	.byte	W01
	.byte		VOL   , 13*seq_041_mvl/mxv
	.byte	W02
	.byte		        15*seq_041_mvl/mxv
	.byte	W02
	.byte		        18*seq_041_mvl/mxv
	.byte	W01
	.byte		N04   , An3 , v032
	.byte	W01
	.byte		VOL   , 20*seq_041_mvl/mxv
	.byte	W02
	.byte		        23*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Dn3 , v056
	.byte	W01
	.byte		VOL   , 28*seq_041_mvl/mxv
	.byte	W05
	.byte		N04   , Dn3 , v032
	.byte	W01
	.byte		VOL   , 35*seq_041_mvl/mxv
	.byte	W03
	.byte		        39*seq_041_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		VOL   , 42*seq_041_mvl/mxv
	.byte		N04   , En3 , v088
	.byte	W02
	.byte		VOL   , 44*seq_041_mvl/mxv
	.byte	W02
	.byte		        46*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte		N04   , En3 , v032
	.byte	W02
	.byte		VOL   , 51*seq_041_mvl/mxv
	.byte	W02
	.byte		        54*seq_041_mvl/mxv
	.byte	W02
	.byte		        56*seq_041_mvl/mxv
	.byte	W02
	.byte		        59*seq_041_mvl/mxv
	.byte	W03
	.byte		        62*seq_041_mvl/mxv
	.byte	W02
	.byte		        64*seq_041_mvl/mxv
	.byte	W02
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        69*seq_041_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Dn3 , v056
	.byte	W01
	.byte		VOL   , 72*seq_041_mvl/mxv
	.byte	W02
	.byte		        74*seq_041_mvl/mxv
	.byte	W02
	.byte		        77*seq_041_mvl/mxv
	.byte	W01
	.byte		N04   , Dn3 , v032
	.byte	W01
	.byte		VOL   , 79*seq_041_mvl/mxv
	.byte	W02
	.byte		        82*seq_041_mvl/mxv
	.byte	W14
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N04   , An2 , v056
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N04   , Dn3 , v056
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W17
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N04   , An3 , v088
	.byte	W06
	.byte		        An3 , v032
	.byte	W17
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N04   , Dn3 , v056
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W30
	.byte	PEND
	.byte	W11
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N04   , An3 , v088
	.byte	W06
	.byte		        An3 , v032
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Dn3 , v056
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W05
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N04   , En3 , v088
	.byte	W06
	.byte		        En3 , v032
	.byte	W17
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Dn3 , v056
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W17
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N04   , An2 , v056
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	PATT
	 .word	seq_041_4 + 0xAA
	.byte	PATT
	 .word	seq_041_4 + 0x8A
	.byte	GOTO
	 .word	seq_041_4 + 0xE3
	.byte	FINE

@*********************** Track 06 ***********************@

seq_041_5:
	.byte	KEYSH , seq_041_key+0
	.byte	W12
	.byte		VOICE , 32
	.byte		VOL   , 0*seq_041_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W23
	.byte		VOL   , 7*seq_041_mvl/mxv
	.byte	W01
	.byte		TIE   , Gn2 , v100
	.byte	W03
	.byte		VOL   , 12*seq_041_mvl/mxv
	.byte	W02
	.byte		        17*seq_041_mvl/mxv
	.byte	W01
	.byte		        20*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W01
	.byte		        28*seq_041_mvl/mxv
	.byte	W02
	.byte		        33*seq_041_mvl/mxv
	.byte	W01
	.byte		        36*seq_041_mvl/mxv
	.byte	W02
	.byte		        41*seq_041_mvl/mxv
	.byte	W01
	.byte		        44*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W01
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        57*seq_041_mvl/mxv
	.byte	W01
	.byte		        60*seq_041_mvl/mxv
	.byte	W02
	.byte		        64*seq_041_mvl/mxv
	.byte	W01
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W01
	.byte		        75*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W01
	.byte		        83*seq_041_mvl/mxv
	.byte	W02
	.byte		        88*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W01
	.byte		        99*seq_041_mvl/mxv
	.byte	W02
	.byte		        104*seq_041_mvl/mxv
	.byte	W01
	.byte		        107*seq_041_mvl/mxv
	.byte	W02
	.byte		        112*seq_041_mvl/mxv
	.byte	W01
	.byte		        115*seq_041_mvl/mxv
	.byte	W02
	.byte		        123*seq_041_mvl/mxv
	.byte	W52
	.byte	PEND
	.byte	W36
	.byte	W01
	.byte		VOL   , 116*seq_041_mvl/mxv
	.byte	W02
	.byte		        115*seq_041_mvl/mxv
	.byte	W02
	.byte		        114*seq_041_mvl/mxv
	.byte	W02
	.byte		        112*seq_041_mvl/mxv
	.byte	W02
	.byte		        110*seq_041_mvl/mxv
	.byte	W02
	.byte		        108*seq_041_mvl/mxv
	.byte	W02
	.byte		        107*seq_041_mvl/mxv
	.byte	W02
	.byte		        105*seq_041_mvl/mxv
	.byte	W01
	.byte		        104*seq_041_mvl/mxv
	.byte	W02
	.byte		        102*seq_041_mvl/mxv
	.byte	W02
	.byte		        100*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        87*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W01
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        79*seq_041_mvl/mxv
	.byte	W02
	.byte		        75*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        66*seq_041_mvl/mxv
	.byte	W02
	.byte		        61*seq_041_mvl/mxv
	.byte	W02
	.byte		        53*seq_041_mvl/mxv
	.byte	W02
	.byte		        48*seq_041_mvl/mxv
	.byte	W14
	.byte		        7*seq_041_mvl/mxv
	.byte	W01
	.byte	PEND
	.byte		EOT   , Gn2 
	.byte		TIE   , Fs2 , v100
	.byte	W03
	.byte		VOL   , 12*seq_041_mvl/mxv
	.byte	W02
	.byte		        17*seq_041_mvl/mxv
	.byte	W01
	.byte		        20*seq_041_mvl/mxv
	.byte	W02
	.byte		        25*seq_041_mvl/mxv
	.byte	W01
	.byte		        28*seq_041_mvl/mxv
	.byte	W02
	.byte		        33*seq_041_mvl/mxv
	.byte	W01
	.byte		        36*seq_041_mvl/mxv
	.byte	W02
	.byte		        41*seq_041_mvl/mxv
	.byte	W01
	.byte		        44*seq_041_mvl/mxv
	.byte	W02
	.byte		        49*seq_041_mvl/mxv
	.byte	W01
	.byte		        52*seq_041_mvl/mxv
	.byte	W02
	.byte		        57*seq_041_mvl/mxv
	.byte	W01
	.byte		        60*seq_041_mvl/mxv
	.byte	W02
	.byte		        64*seq_041_mvl/mxv
	.byte	W01
	.byte		        67*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W01
	.byte		        75*seq_041_mvl/mxv
	.byte	W02
	.byte		        80*seq_041_mvl/mxv
	.byte	W01
	.byte		        83*seq_041_mvl/mxv
	.byte	W02
	.byte		        88*seq_041_mvl/mxv
	.byte	W01
	.byte		        91*seq_041_mvl/mxv
	.byte	W02
	.byte		        96*seq_041_mvl/mxv
	.byte	W01
	.byte		        99*seq_041_mvl/mxv
	.byte	W02
	.byte		        104*seq_041_mvl/mxv
	.byte	W01
	.byte		        107*seq_041_mvl/mxv
	.byte	W02
	.byte		        112*seq_041_mvl/mxv
	.byte	W01
	.byte		        115*seq_041_mvl/mxv
	.byte	W02
	.byte		        123*seq_041_mvl/mxv
	.byte	W52
	.byte	PEND
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Fs2 
	.byte	PATT
	 .word	seq_041_5 + 0xD
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Gn2 
	.byte	PATT
	 .word	seq_041_5 + 0x83
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Fs2 
	.byte	PATT
	 .word	seq_041_5 + 0xD
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Gn2 
	.byte	PATT
	 .word	seq_041_5 + 0x83
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Fs2 
	.byte	PATT
	 .word	seq_041_5 + 0xD
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Gn2 
	.byte	PATT
	 .word	seq_041_5 + 0x83
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Fs2 
	.byte	PATT
	 .word	seq_041_5 + 0xD
	.byte	PATT
	 .word	seq_041_5 + 0x4B
	.byte		EOT   , Gn2 
	.byte	PATT
	 .word	seq_041_5 + 0x83
	.byte	W36
	.byte	W01
	.byte		VOL   , 116*seq_041_mvl/mxv
	.byte	W02
	.byte		        115*seq_041_mvl/mxv
	.byte	W02
	.byte		        114*seq_041_mvl/mxv
	.byte	W02
	.byte		        112*seq_041_mvl/mxv
	.byte	W02
	.byte		        110*seq_041_mvl/mxv
	.byte	W02
	.byte		        108*seq_041_mvl/mxv
	.byte	W02
	.byte		        107*seq_041_mvl/mxv
	.byte	W02
	.byte		        105*seq_041_mvl/mxv
	.byte	W01
	.byte		        104*seq_041_mvl/mxv
	.byte	W02
	.byte		        102*seq_041_mvl/mxv
	.byte	W02
	.byte		        100*seq_041_mvl/mxv
	.byte	W02
	.byte		        97*seq_041_mvl/mxv
	.byte	W02
	.byte		        93*seq_041_mvl/mxv
	.byte	W02
	.byte		        90*seq_041_mvl/mxv
	.byte	W02
	.byte		        87*seq_041_mvl/mxv
	.byte	W02
	.byte		        84*seq_041_mvl/mxv
	.byte	W01
	.byte		        82*seq_041_mvl/mxv
	.byte	W02
	.byte		        79*seq_041_mvl/mxv
	.byte	W02
	.byte		        75*seq_041_mvl/mxv
	.byte	W02
	.byte		        72*seq_041_mvl/mxv
	.byte	W02
	.byte		        66*seq_041_mvl/mxv
	.byte	W02
	.byte		        61*seq_041_mvl/mxv
	.byte	W02
	.byte		        53*seq_041_mvl/mxv
	.byte	W02
	.byte		        48*seq_041_mvl/mxv
	.byte	W15
	.byte		EOT   , Fs2 
	.byte	GOTO
	 .word	seq_041_5 + 0xC8
	.byte	FINE

@******************************************************@

	.align	2

seq_041:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_041_pri	@ Priority
	.byte	seq_041_rev	@ Reverb

	.word	seq_041_grp

	.word	seq_041_0
	.word	seq_041_1
	.word	seq_041_2
	.word	seq_041_3
	.word	seq_041_4
	.word	seq_041_5

	.end