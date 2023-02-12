        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8038830
sub_8038830:
	push {r4,r5,lr}
	movs r5, 0
	ldr r0, _080388A4
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0xD4
	lsls r3, 1
	add r3, r12
	ldrh r1, [r3]
	ldr r0, _080388A8
	ands r0, r1
	ldr r1, _080388AC
	ands r0, r1
	ldr r4, _080388B0
	ands r0, r4
	ldr r1, _080388B4
	ands r0, r1
	ldr r1, _080388B8
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _080388BC
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
	ldr r1, _080388C0
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x4]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0xD0
	lsls r1, 3
	ldrh r0, [r3, 0x6]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x6]
	movs r0, 0xD8
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	movs r0, 0
	bl ResetSprites
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080388A4: .4byte gUnknown_203B364
_080388A8: .4byte 0x0000feff
_080388AC: .4byte 0x0000fdff
_080388B0: .4byte 0x0000f3ff
_080388B4: .4byte 0x0000efff
_080388B8: .4byte 0x0000dfff
_080388BC: .4byte 0x00003fff
_080388C0: .4byte 0x00000fff
	thumb_func_end sub_8038830

	thumb_func_start sub_80388C4
sub_80388C4:
	push {r4,r5,lr}
	ldr r5, _080388FC
	ldr r2, [r5]
	movs r4, 0xD8
	lsls r4, 1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080388EA
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r2, r1
	subs r1, 0xA8
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080388EA:
	ldr r1, [r5]
	adds r1, r4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080388FC: .4byte gUnknown_203B364
	thumb_func_end sub_80388C4

        .align 2,0
