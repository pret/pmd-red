        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8035D80
sub_8035D80:
	ldr r1, _08035D90
	ldr r2, [r1]
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	bx lr
	.align 2, 0
_08035D90: .4byte gMainMenu
	thumb_func_end sub_8035D80

	thumb_func_start sub_8035D94
sub_8035D94:
	ldr r0, _08035D9C
	ldr r0, [r0]
	adds r0, 0x30
	bx lr
	.align 2, 0
_08035D9C: .4byte gMainMenu
	thumb_func_end sub_8035D94

	thumb_func_start sub_8035DA0
sub_8035DA0:
	ldr r2, _08035DB0
	ldr r0, [r2]
	adds r0, 0x30
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	str r1, [r0, 0x34]
	bx lr
	.align 2, 0
_08035DB0: .4byte gMainMenu
	thumb_func_end sub_8035DA0

	thumb_func_start sub_8035DB4
sub_8035DB4:
	push {lr}
	movs r1, 0x8
	subs r0, 0x13
	cmp r0, 0x7
	bhi _08035E0A
	lsls r0, 2
	ldr r1, _08035DC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08035DC8: .4byte _08035DCC
	.align 2, 0
_08035DCC:
	.4byte _08035DEC
	.4byte _08035DF0
	.4byte _08035DF4
	.4byte _08035DF8
	.4byte _08035DFC
	.4byte _08035E00
	.4byte _08035E04
	.4byte _08035E08
_08035DEC:
	movs r1, 0
	b _08035E0A
_08035DF0:
	movs r1, 0x1
	b _08035E0A
_08035DF4:
	movs r1, 0x2
	b _08035E0A
_08035DF8:
	movs r1, 0x3
	b _08035E0A
_08035DFC:
	movs r1, 0x4
	b _08035E0A
_08035E00:
	movs r1, 0x5
	b _08035E0A
_08035E04:
	movs r1, 0x6
	b _08035E0A
_08035E08:
	movs r1, 0x7
_08035E0A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8035DB4

        thumb_func_start DrawMainMenu
DrawMainMenu:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, _08035EB8
	ldr r0, [r5]
	cmp r0, 0
	bne _08035E34
	movs r4, 0xD4
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08035E34:
	mov r12, r5
	movs r0, 0xA2
	lsls r0, 1
	mov r8, r0
	ldr r4, _08035EBC
	movs r3, 0
	movs r2, 0x3
_08035E42:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08035E42
	bl ResetUnusedInputStruct
	ldr r4, _08035EB8
	ldr r0, [r4]
	movs r6, 0xA2
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl SetMainMenuItems
	ldr r0, [r4]
	movs r7, 0xD2
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl SetMainMenuText
	lsls r0, 24
	cmp r0, 0
	beq _08035E9A
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
_08035E9A:
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035EB8: .4byte gUnknown_203B34C
_08035EBC: .4byte gUnknown_80E59C8
	thumb_func_end DrawMainMenu

	thumb_func_start CleanMainMenu
CleanMainMenu:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08035EE8
	ldr r0, [r4]
	cmp r0, 0
	beq _08035EE0
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08035EE0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035EE8: .4byte gUnknown_203B34C
	thumb_func_end CleanMainMenu

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
