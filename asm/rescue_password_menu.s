        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8039174
sub_8039174:
	push {r4,lr}
	ldr r0, _080391D8
	ldr r3, [r0]
	movs r0, 0x82
	lsls r0, 2
	adds r3, r0
	ldrh r1, [r3]
	ldr r0, _080391DC
	ands r0, r1
	ldr r1, _080391E0
	ands r0, r1
	ldr r4, _080391E4
	ands r0, r4
	ldr r1, _080391E8
	ands r0, r1
	ldr r1, _080391EC
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _080391F0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r2, 0xF
	movs r4, 0xF0
	lsls r4, 8
	ldr r1, _080391F4
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x4]
	movs r0, 0
	strh r0, [r3, 0x2]
	movs r1, 0xC0
	lsls r1, 4
	ldrh r0, [r3, 0x6]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080391D8: .4byte gRescuePasswordMenu
_080391DC: .4byte 0x0000feff
_080391E0: .4byte 0x0000fdff
_080391E4: .4byte 0x0000f3ff
_080391E8: .4byte 0x0000efff
_080391EC: .4byte 0x0000dfff
_080391F0: .4byte 0x00003fff
_080391F4: .4byte 0x00000fff
	thumb_func_end sub_8039174

        .align 2,0
