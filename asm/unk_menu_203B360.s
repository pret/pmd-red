        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start sub_80382E4
sub_80382E4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	ldr r5, _08038398
	ldr r0, [r5]
	cmp r0, 0
	bne _0803830E
	movs r4, 0xDA
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_0803830E:
	mov r12, r5
	movs r0, 0xA4
	lsls r0, 1
	mov r9, r0
	ldr r4, _0803839C
	movs r3, 0
	movs r2, 0x3
_0803831C:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0803831C
	bl ResetUnusedInputStruct
	ldr r5, _08038398
	ldr r0, [r5]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	mov r7, r8
	cmp r7, 0x25
	bne _08038370
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x8
	adds r1, r6
	ldr r3, _080383A0
	ldr r2, _080383A4
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x4
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08038370:
	ldr r0, [r5]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r5]
	mov r0, r8
	str r0, [r1]
	movs r0, 0
	str r0, [r1, 0x4]
	bl sub_8038440
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038398: .4byte gUnknown_203B360
_0803839C: .4byte gUnknown_80E6E7C
_080383A0: .4byte gUnknown_80E6E94
_080383A4: .4byte gUnknown_80E6EAC
	thumb_func_end sub_80382E4

	thumb_func_start sub_80383A8
sub_80383A8:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _080383D0
	ldr r0, [r4]
	cmp r0, 0
	beq _080383C8
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080383C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080383D0: .4byte gUnknown_203B360
	thumb_func_end sub_80383A8

	thumb_func_start sub_80383D4
sub_80383D4:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x2
	str r0, [sp]
	ldr r6, _08038410
	ldr r4, _08038414
	ldr r0, [r4]
	ldr r5, [r0, 0x4]
	cmp r5, 0
	bne _08038434
	adds r0, 0x8
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _080383FE
	ldr r0, [r4]
	adds r0, 0x8
	mov r1, sp
	bl sub_8013114
_080383FE:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803842C
	cmp r0, 0x2
	bhi _08038418
	cmp r0, 0x1
	beq _0803841C
	b _08038430
	.align 2, 0
_08038410: .4byte 0x0000ffdc
_08038414: .4byte gUnknown_203B360
_08038418:
	cmp r0, 0x3
	bne _08038430
_0803841C:
	ldr r0, _08038428
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x4]
	movs r6, 0x1
	b _08038430
	.align 2, 0
_08038428: .4byte gUnknown_203B360
_0803842C:
	ldr r0, [r4]
	str r5, [r0, 0x4]
_08038430:
	bl sub_80384D0
_08038434:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80383D4

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

	thumb_func_start sub_80384D0
sub_80384D0:
	push {r4,r5,lr}
	ldr r5, _08038508
	ldr r2, [r5]
	movs r4, 0xD8
	lsls r4, 1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080384F6
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r2, r1
	subs r1, 0xA8
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080384F6:
	ldr r1, [r5]
	adds r1, r4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038508: .4byte gUnknown_203B360
	thumb_func_end sub_80384D0

        .align 2,0
