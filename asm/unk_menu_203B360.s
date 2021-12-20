        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8038440
sub_8038440:
	push {r4,r5,lr}
	movs r5, 0
	ldr r0, _080384B0
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0xD4
	lsls r3, 1
	add r3, r12
	ldrh r1, [r3]
	ldr r0, _080384B4
	ands r0, r1
	ldr r1, _080384B8
	ands r0, r1
	ldr r4, _080384BC
	ands r0, r4
	ldr r1, _080384C0
	ands r0, r1
	ldr r1, _080384C4
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _080384C8
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
	ldr r1, _080384CC
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x4]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0xE0
	lsls r1, 3
	ldrh r0, [r3, 0x6]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x6]
	movs r0, 0xD8
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080384B0: .4byte gUnknown_203B360
_080384B4: .4byte 0x0000feff
_080384B8: .4byte 0x0000fdff
_080384BC: .4byte 0x0000f3ff
_080384C0: .4byte 0x0000efff
_080384C4: .4byte 0x0000dfff
_080384C8: .4byte 0x00003fff
_080384CC: .4byte 0x00000fff
	thumb_func_end sub_8038440

        .align 2,0
