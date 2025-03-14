@ File generated by m4a2s Voicegroup-Module
	.include "VoiceDef.s"

	.section .rodata
	.global	drums_001
	.align	2
	
	.equ	_c_v_,	0xC0 @ c_v from MPlayDef.s does not match

drums_001:

@**************** Voice 000 ****************@

	.byte	AProgWave
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	gbwave_017
	.byte	0, 0, 15, 0

@**************** Voice 001 ****************@

	.byte	ASquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 002 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	bank_013
	.word	map_005

@**************** Voice 003 ****************@

	.byte	DirectSound
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	wave_043
	.byte	29, 204, 154, 204

@**************** Voice 004 ****************@

	.byte	DirectSound
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	wave_054
	.byte	255, 249, 25, 226

@**************** Voice 005 ****************@

	.byte	DirectSound
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	wave_054
	.byte	255, 0, 255, 0

@**************** Voice 006 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 007 ****************@

	.byte	DirectSound
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	wave_055
	.byte	255, 0, 255, 0

@**************** Voice 008 ****************@

	.byte	DirectSound
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	wave_056
	.byte	255, 0, 255, 216

@**************** Voice 009 ****************@

	.byte	DirectSound
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	wave_057
	.byte	255, 0, 255, 127

@**************** Voice 010 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 011 ****************@

	.byte	DrumTable
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	drums_000
	.byte	0x0, 0x0, 0x0, 0x0

@**************** Voice 012 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_058
	.byte	255, 0, 255, 216

@**************** Voice 013 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_059
	.byte	255, 0, 255, 216

@**************** Voice 014 ****************@

	.byte	DirectSound
	.byte	Fs3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_060
	.byte	255, 0, 255, 216

@**************** Voice 015 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_061
	.byte	255, 0, 255, 216

@**************** Voice 016 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_062
	.byte	255, 0, 255, 216

@**************** Voice 017 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_063
	.byte	255, 0, 255, 216

@**************** Voice 018 ****************@

	.byte	AProgNoise
	.byte	Gs4 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 1, 0, 0

@**************** Voice 019 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_064
	.byte	255, 0, 255, 127

@**************** Voice 020 ****************@

	.byte	AProgNoise
	.byte	Fs4 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 1, 0, 0

@**************** Voice 021 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_065
	.byte	255, 0, 255, 165

@**************** Voice 022 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 023 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 024 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 025 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 026 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 027 ****************@

	.byte	AProgNoise
	.byte	En6 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 2, 0, 0

@**************** Voice 028 ****************@

	.byte	AProgNoise
	.byte	En6 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 2, 6, 0

@**************** Voice 029 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 030 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_066
	.byte	255, 0, 255, 216

@**************** Voice 031 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 032 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 033 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 034 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 035 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 036 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 037 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_-20
	.word	wave_067
	.byte	255, 0, 255, 204

@**************** Voice 038 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+20
	.word	wave_068
	.byte	255, 0, 255, 204

@**************** Voice 039 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_-20
	.word	wave_069
	.byte	255, 0, 255, 204

@**************** Voice 040 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+20
	.word	wave_070
	.byte	255, 0, 255, 204

@**************** Voice 041 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+20
	.word	wave_071
	.byte	255, 0, 255, 216

@**************** Voice 042 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_055
	.byte	255, 0, 255, 216

@**************** Voice 043 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+20
	.word	wave_072
	.byte	255, 0, 255, 216

@**************** Voice 044 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_-20
	.word	wave_073
	.byte	255, 0, 255, 216

@**************** Voice 045 ****************@

	.byte	AProgNoise
	.byte	Gs4 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 1, 0, 0

@**************** Voice 046 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_074
	.byte	255, 0, 255, 216

@**************** Voice 047 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_-20
	.word	wave_075
	.byte	255, 0, 255, 216

@**************** Voice 048 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 049 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 050 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 051 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 052 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 053 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 054 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 055 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 056 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_076
	.byte	255, 249, 0, 216

@**************** Voice 057 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_077
	.byte	255, 226, 0, 216

@**************** Voice 058 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 059 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 060 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 061 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 062 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 063 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 064 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 065 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 066 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 067 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 068 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 069 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 070 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 071 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 072 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_058
	.byte	255, 0, 255, 216

@**************** Voice 073 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_059
	.byte	255, 0, 255, 216

@**************** Voice 074 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_078
	.byte	255, 0, 255, 216

@**************** Voice 075 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_064
	.byte	255, 0, 255, 127

@**************** Voice 076 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_079
	.byte	255, 0, 255, 216

@**************** Voice 077 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_080
	.byte	255, 0, 255, 216

@**************** Voice 078 ****************@

	.byte	AProgNoise
	.byte	Gs4 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 1, 0, 0

@**************** Voice 079 ****************@

	.byte	DirectSoundFix
	.byte	Gs3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_081
	.byte	255, 0, 255, 216

@**************** Voice 080 ****************@

	.byte	AProgNoise
	.byte	Fs4 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 1, 0, 0

@**************** Voice 081 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 082 ****************@

	.byte	DirectSoundFix
	.byte	Gs3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_061
	.byte	255, 0, 255, 216

@**************** Voice 083 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 084 ****************@

	.byte	DirectSoundFix
	.byte	Gs3 
	.byte	0x00
	.byte	_c_v_-30
	.word	wave_082
	.byte	64, 226, 0, 0

@**************** Voice 085 ****************@

	.byte	DirectSoundFix
	.byte	Gs3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_082
	.byte	255, 226, 0, 0

@**************** Voice 086 ****************@

	.byte	DirectSoundFix
	.byte	Gs3 
	.byte	0x00
	.byte	_c_v_+30
	.word	wave_082
	.byte	64, 226, 0, 0

@**************** Voice 087 ****************@

	.byte	AProgNoise
	.byte	En6 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 2, 0, 0

@**************** Voice 088 ****************@

	.byte	AProgNoise
	.byte	En6 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 2, 6, 0

@**************** Voice 089 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 090 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_066
	.byte	255, 0, 255, 216

@**************** Voice 091 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 092 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_083
	.byte	255, 0, 255, 216

@**************** Voice 093 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 094 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_071
	.byte	255, 0, 255, 216

@**************** Voice 095 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 096 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 097 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_-20
	.word	wave_067
	.byte	255, 0, 255, 204

@**************** Voice 098 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+20
	.word	wave_068
	.byte	255, 0, 255, 204

@**************** Voice 099 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_-20
	.word	wave_069
	.byte	255, 0, 255, 204

@**************** Voice 100 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+20
	.word	wave_070
	.byte	255, 0, 255, 204

@**************** Voice 101 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_056
	.byte	255, 0, 255, 216

@**************** Voice 102 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_057
	.byte	255, 0, 255, 127

@**************** Voice 103 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_084
	.byte	255, 0, 255, 0

@**************** Voice 104 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 105 ****************@

	.byte	AProgNoise
	.byte	Gs4 
	.byte	0x00
	.byte	0xC0
	.word	FineNoise
	.byte	0, 1, 0, 0

@**************** Voice 106 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 107 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_055
	.byte	255, 0, 255, 216

@**************** Voice 108 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_-20
	.word	wave_072
	.byte	255, 0, 255, 216

@**************** Voice 109 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 110 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 111 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+20
	.word	wave_073
	.byte	255, 0, 255, 216

@**************** Voice 112 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 113 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_074
	.byte	255, 0, 255, 216

@**************** Voice 114 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 115 ****************@

	.byte	SquareWave1
	.byte	Cn3 
	.byte	0x00
	.byte	0x00
	.word	WaveDuty50
	.byte	0, 0, 15, 0

@**************** Voice 116 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_076
	.byte	255, 249, 0, 165

@**************** Voice 117 ****************@

	.byte	DirectSoundFix
	.byte	Cn3 
	.byte	0x00
	.byte	_c_v_+0
	.word	wave_077
	.byte	255, 226, 0, 165
