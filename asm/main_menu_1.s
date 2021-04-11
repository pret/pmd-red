        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start UpdateMainMenu
UpdateMainMenu:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, _08035F64
	str r6, [sp]
	ldr r4, _08035F68
	ldr r0, [r4]
	ldr r5, [r0]
	cmp r5, 0xC
	beq _08035FB8
	cmp r5, 0xC
	bls _08035F04
	b _0803601A
_08035F04:
	cmp r5, 0x1
	beq _08035F0A
	b _0803601A
_08035F0A:
	adds r0, 0xA4
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x4
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08035F28
	ldr r0, [r4]
	adds r0, 0x4
	mov r1, sp
	bl sub_8013114
_08035F28:
	bl SetMainMenuText
	lsls r0, 24
	cmp r0, 0
	beq _08035F4A
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
_08035F4A:
	ldr r1, [sp]
	cmp r1, 0xC
	beq _08035FA8
	cmp r1, 0xC
	bhi _08035F6C
	cmp r1, 0x3
	beq _08035FAC
	cmp r1, 0x3
	bcc _0803601A
	cmp r1, 0x6
	bcc _0803601A
	b _08035FAC
	.align 2, 0
_08035F64: .4byte 0x0000ffdc
_08035F68: .4byte gUnknown_203B34C
_08035F6C:
	cmp r1, r6
	beq _08035FF2
	cmp r1, r6
	bhi _08035F7A
	cmp r1, 0x10
	bhi _0803601A
	b _08035FAC
_08035F7A:
	ldr r0, _08035FA4
	cmp r1, r0
	bne _0803601A
	ldr r0, [r4]
	str r5, [r0]
	str r6, [sp]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
	b _0803601A
	.align 2, 0
_08035FA4: .4byte 0x0000ffdd
_08035FA8:
	bl sub_8035DA0
_08035FAC:
	ldr r1, _08035FB4
	ldr r0, [sp]
	str r0, [r1]
	b _0803601A
	.align 2, 0
_08035FB4: .4byte gUnknown_203B350
_08035FB8:
	adds r0, 0x54
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08035FCE
	ldr r0, [r4]
	adds r0, 0x54
	mov r1, sp
	bl sub_8013114
_08035FCE:
	ldr r1, [sp]
	cmp r1, 0x12
	beq _08036008
	cmp r1, 0x12
	bhi _08035FDE
	cmp r1, 0x11
	beq _08035FFC
	b _0803601A
_08035FDE:
	cmp r1, r6
	beq _08036018
	ldr r0, _08035FF8
	cmp r1, r0
	bne _0803601A
	bl sub_803623C
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
_08035FF2:
	str r6, [sp]
	b _0803601A
	.align 2, 0
_08035FF8: .4byte 0x0000ffdd
_08035FFC:
	ldr r0, _08036004
	str r1, [r0]
	str r5, [sp]
	b _0803601A
	.align 2, 0
_08036004: .4byte gUnknown_203B354
_08036008:
	ldr r0, _08036014
	str r1, [r0]
	movs r0, 0x14
	str r0, [sp]
	b _0803601A
	.align 2, 0
_08036014: .4byte gUnknown_203B354
_08036018:
	str r1, [sp]
_0803601A:
	ldr r0, [sp]
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end UpdateMainMenu

        .align 2,0
