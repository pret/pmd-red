	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801203C
sub_801203C:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _08012078
	movs r1, 0x5
	bl MemoryAlloc
	adds r6, r0, 0
	movs r0, 0x89
	lsls r0, 3
	adds r5, r6, r0
	ldr r0, _0801207C
	ldr r2, [r0]
	cmp r2, 0
	bne _08012084
	ldr r1, _08012080
	adds r0, r6, r1
	str r4, [r0]
	bl sub_8011C34
	movs r2, 0x83
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	bl GetRngState
	movs r2, 0x84
	lsls r2, 3
	adds r1, r6, r2
	b _0801209E
	.align 2, 0
_08012078: .4byte 0x000057d4
_0801207C: .4byte gUnknown_203B184
_08012080: .4byte 0x0000041c
_08012084:
	ldr r0, _080120C8
	adds r1, r6, r0
	ldr r0, [r2, 0x54]
	str r0, [r1]
	movs r0, 0x83
	lsls r0, 3
	adds r1, r6, r0
	ldr r0, [r2, 0x50]
	str r0, [r1]
	movs r0, 0x84
	lsls r0, 3
	adds r1, r6, r0
	ldr r0, [r2, 0x58]
_0801209E:
	str r0, [r1]
	ldr r2, _080120CC
	adds r1, r6, r2
	ldr r0, _080120D0
	str r0, [r1]
	bl sub_8011C4C
	adds r1, r0, 0
	ldr r2, _080120D4
	adds r0, r6, r2
	movs r2, 0x10
	bl strncpy
	ldr r0, _080120D8
	ldr r1, [r0]
	cmp r1, 0
	bne _080120DC
	adds r0, r6, 0x4
	bl sub_8002700
	b _080120E8
	.align 2, 0
_080120C8: .4byte 0x0000041c
_080120CC: .4byte 0x00000414
_080120D0: .4byte 0x05071412
_080120D4: .4byte 0x00000404
_080120D8: .4byte gUnknown_203B184
_080120DC:
	adds r0, r6, 0x4
	ldr r1, [r1, 0x4C]
	movs r2, 0x80
	lsls r2, 3
	bl MemoryCopy8
_080120E8:
	ldr r4, _080121A4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808ED78
	ldr r2, _080121A8
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	movs r4, 0x96
	lsls r4, 2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808F154
	movs r2, 0x85
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	subs r4, 0x80
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8091C68
	movs r2, 0x86
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	adds r0, r5, 0
	movs r1, 0x10
	bl sub_80921C4
	ldr r2, _080121AC
	adds r1, r6, r2
	str r0, [r1]
	adds r5, 0x10
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_80927A8
	movs r2, 0x87
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, 0x8
	subs r4, 0xD8
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8097D60
	ldr r2, _080121B0
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	ldr r4, _080121B4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8095624
	movs r2, 0x88
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	ldr r1, _080121B8
	adds r0, r5, 0
	bl sub_80970D8
	ldr r2, _080121BC
	adds r1, r6, r2
	str r0, [r1]
	ldr r4, _080121C0
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl WriteSaveSector
	adds r5, r0, 0
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl WriteSaveSector
	adds r4, r0, 0
	adds r0, r6, 0
	bl MemoryFree
	cmp r5, 0
	beq _080121C4
	adds r0, r5, 0
	b _080121CE
	.align 2, 0
_080121A4: .4byte 0x00004650
_080121A8: .4byte 0x00000424
_080121AC: .4byte 0x00000434
_080121B0: .4byte 0x0000043c
_080121B4: .4byte 0x00000594
_080121B8: .4byte 0x00000221
_080121BC: .4byte 0x00000444
_080121C0: .4byte 0x000057d4
_080121C4:
	cmp r4, 0
	bne _080121CC
	movs r0, 0
	b _080121CE
_080121CC:
	adds r0, r4, 0
_080121CE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801203C

	.align 2, 0 @ Don't pad with nop.
