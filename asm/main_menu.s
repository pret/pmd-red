        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start SetMenuItems
SetMenuItems:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r0, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	adds r0, r4
	ldm r3!, {r1,r2,r7}
	stm r0!, {r1,r2,r7}
	ldm r3!, {r1,r2,r7}
	stm r0!, {r1,r2,r7}
	bl ResetUnusedInputStruct
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	mov r0, r8
	cmp r0, 0
	beq _08035C90
	lsls r4, r5, 2
	adds r0, r4, r5
	lsls r0, 4
	adds r0, r6, r0
	ldr r1, [sp, 0x28]
	str r1, [sp]
	str r5, [sp, 0x4]
	ldr r1, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _08035CA8
_08035C90:
	lsls r4, r5, 2
	adds r0, r4, r5
	lsls r0, 4
	adds r0, r6, r0
	mov r1, r8
	str r1, [sp]
	str r5, [sp, 0x4]
	ldr r1, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl sub_8012E04
_08035CA8:
	adds r0, r4, r5
	lsls r0, 4
	adds r0, r6
	adds r0, 0x4C
	movs r1, 0x1
	strb r1, [r0]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end SetMenuItems

	thumb_func_start sub_8035CC0
sub_8035CC0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_8006518
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, r5
	ldr r0, _08035CF0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl ResetUnusedInputStruct
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08035CF0: .4byte gUnknown_80E59A8
	thumb_func_end sub_8035CC0

	thumb_func_start sub_8035CF4
sub_8035CF4:
	push {lr}
	adds r3, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r0, r3
	adds r1, r0, 0
	adds r1, 0x4C
	strb r2, [r1]
	adds r2, r0, 0
	adds r2, 0x4D
	movs r1, 0x1
	strb r1, [r2]
	subs r1, 0x2
	str r1, [r0, 0x48]
	bl sub_8012EBC
	pop {r0}
	bx r0
	thumb_func_end sub_8035CF4

	thumb_func_start sub_8035D1C
sub_8035D1C:
	ldr r0, _08035D28
	ldr r1, [r0]
	ldr r0, _08035D2C
	strh r0, [r1, 0x38]
	bx lr
	.align 2, 0
_08035D28: .4byte gUnknown_203B348
_08035D2C: .4byte 0x0000ffff
	thumb_func_end sub_8035D1C

	thumb_func_start sub_8035D30
sub_8035D30:
	ldr r1, _08035D38
	ldr r1, [r1]
	strh r0, [r1, 0x38]
	bx lr
	.align 2, 0
_08035D38: .4byte gUnknown_203B348
	thumb_func_end sub_8035D30

	thumb_func_start sub_8035D3C
sub_8035D3C:
	ldr r0, _08035D48
	ldr r0, [r0]
	movs r1, 0x38
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08035D48: .4byte gUnknown_203B348
	thumb_func_end sub_8035D3C

	thumb_func_start sub_8035D4C
sub_8035D4C:
	ldr r0, _08035D54
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08035D54: .4byte gUnknown_203B348
	thumb_func_end sub_8035D4C

	thumb_func_start sub_8035D58
sub_8035D58:
	ldr r0, _08035D64
	ldr r1, [r0]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x3C]
	bx lr
	.align 2, 0
_08035D64: .4byte gUnknown_203B348
	thumb_func_end sub_8035D58

	thumb_func_start sub_8035D68
sub_8035D68:
	ldr r1, _08035D70
	ldr r1, [r1]
	str r0, [r1, 0x3C]
	bx lr
	.align 2, 0
_08035D70: .4byte gUnknown_203B348
	thumb_func_end sub_8035D68

	thumb_func_start sub_8035D74
sub_8035D74:
	ldr r0, _08035D7C
	ldr r0, [r0]
	ldr r0, [r0, 0x3C]
	bx lr
	.align 2, 0
_08035D7C: .4byte gUnknown_203B348
	thumb_func_end sub_8035D74

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
_08035D90: .4byte gUnknown_203B348
	thumb_func_end sub_8035D80

	thumb_func_start sub_8035D94
sub_8035D94:
	ldr r0, _08035D9C
	ldr r0, [r0]
	adds r0, 0x30
	bx lr
	.align 2, 0
_08035D9C: .4byte gUnknown_203B348
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
_08035DB0: .4byte gUnknown_203B348
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

        thumb_func_start sub_8035E10
sub_8035E10:
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
	bl sub_803628C
	ldr r0, [r4]
	movs r7, 0xD2
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl SetMainMenuType
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
	thumb_func_end sub_8035E10

	thumb_func_start sub_8035EC0
sub_8035EC0:
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
	thumb_func_end sub_8035EC0

	thumb_func_start sub_8035EEC
sub_8035EEC:
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
	bl SetMainMenuType
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
	thumb_func_end sub_8035EEC

	thumb_func_start SetMainMenuType
SetMainMenuType:
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r6, _08036048
	ldr r2, [r6]
	ldr r0, [r2, 0x8]
	movs r3, 0x30
	ldrsh r1, [r2, r3]
	lsls r1, 3
	adds r1, r0
	ldr r5, [r1, 0x4]
	movs r0, 0xD2
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, r5
	bne _0803604C
	movs r0, 0
	b _08036226
	.align 2, 0
_08036048: .4byte gUnknown_203B34C
_0803604C:
	str r5, [r1]
	movs r4, 0xA2
	lsls r4, 1
	adds r0, r2, r4
	movs r1, 0x2
	bl sub_8035CC0
	ldr r0, [r6]
	adds r0, r4
	movs r1, 0x3
	bl sub_8035CC0
	subs r0, r5, 0x3
	cmp r0, 0xD
	bls _0803606C
	b _08036224
_0803606C:
	lsls r0, 2
	ldr r1, _08036078
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036078: .4byte _0803607C
	.align 2, 0
_0803607C:
	.4byte _08036114
	.4byte _08036224
	.4byte _08036224
	.4byte _080360F4
	.4byte _08036134
	.4byte _08036154
	.4byte _08036224
	.4byte _08036174
	.4byte _08036194
	.4byte _080361B4
	.4byte _080360D4
	.4byte _080361D4
	.4byte _080360B4
	.4byte _08036204
_080360B4:
	ldr r0, _080360C8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080360CC
	ldr r2, _080360D0
	b _080361E4
	.align 2, 0
_080360C8: .4byte gUnknown_203B34C
_080360CC: .4byte gUnknown_80E5CB4
_080360D0: .4byte gUnknown_80E6030
_080360D4:
	ldr r0, _080360E8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _080360EC
	ldr r2, _080360F0
	b _080361E4
	.align 2, 0
_080360E8: .4byte gUnknown_203B34C
_080360EC: .4byte gUnknown_80E5CB4
_080360F0: .4byte gUnknown_80E5F80
_080360F4:
	ldr r0, _08036108
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803610C
	ldr r2, _08036110
	b _080361E4
	.align 2, 0
_08036108: .4byte gUnknown_203B34C
_0803610C: .4byte gUnknown_80E5CB4
_08036110: .4byte gUnknown_80E5F1C
_08036114:
	ldr r0, _08036128
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _0803612C
	ldr r2, _08036130
	b _080361E4
	.align 2, 0
_08036128: .4byte gUnknown_203B34C
_0803612C: .4byte gUnknown_80E5CB4
_08036130: .4byte gUnknown_80E5CCC
_08036134:
	ldr r0, _08036148
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803614C
	ldr r2, _08036150
	b _080361E4
	.align 2, 0
_08036148: .4byte gUnknown_203B34C
_0803614C: .4byte gUnknown_80E5CB4
_08036150: .4byte gUnknown_80E5DA0
_08036154:
	ldr r0, _08036168
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _0803616C
	ldr r2, _08036170
	b _080361E4
	.align 2, 0
_08036168: .4byte gUnknown_203B34C
_0803616C: .4byte gUnknown_80E5CB4
_08036170: .4byte gUnknown_80E5DF0
_08036174:
	ldr r0, _08036188
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803618C
	ldr r2, _08036190
	b _080361E4
	.align 2, 0
_08036188: .4byte gUnknown_203B34C
_0803618C: .4byte gUnknown_80E5CB4
_08036190: .4byte gUnknown_80E5D0C
_08036194:
	ldr r0, _080361A8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _080361AC
	ldr r2, _080361B0
	b _080361E4
	.align 2, 0
_080361A8: .4byte gUnknown_203B34C
_080361AC: .4byte gUnknown_80E5CB4
_080361B0: .4byte gUnknown_80E5E5C
_080361B4:
	ldr r0, _080361C8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080361CC
	ldr r2, _080361D0
	b _080361E4
	.align 2, 0
_080361C8: .4byte gUnknown_203B34C
_080361CC: .4byte gUnknown_80E5CB4
_080361D0: .4byte gUnknown_80E5EBC
_080361D4:
	ldr r0, _080361F8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _080361FC
	ldr r2, _08036200
_080361E4:
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x2
	bl SetMenuItems
	b _08036224
	.align 2, 0
_080361F8: .4byte gUnknown_203B34C
_080361FC: .4byte gUnknown_80E5CB4
_08036200: .4byte gUnknown_80E5FCC
_08036204:
	ldr r0, _08036230
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _08036234
	ldr r2, _08036238
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x2
	bl SetMenuItems
_08036224:
	movs r0, 0x1
_08036226:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08036230: .4byte gUnknown_203B34C
_08036234: .4byte gUnknown_80E5CB4
_08036238: .4byte gUnknown_80E5D48
	thumb_func_end SetMainMenuType

	thumb_func_start sub_803623C
sub_803623C:
	push {r4,lr}
	ldr r4, _08036288
	ldr r0, [r4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	bl sub_8035CC0
	bl sub_803628C
	ldr r0, [r4]
	movs r1, 0xD2
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl SetMainMenuType
	lsls r0, 24
	cmp r0, 0
	beq _08036276
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
_08036276:
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036288: .4byte gUnknown_203B34C
	thumb_func_end sub_803623C

	thumb_func_start sub_803628C
sub_803628C:
	push {r4,lr}
	sub sp, 0x10
	bl sub_8011C34
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803629E
	b _080363A4
_0803629E:
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _08036344
	movs r0, 0x7
	bl sub_8095324
	cmp r0, 0
	beq _080362FC
	bl sub_803D0D8
	lsls r0, 24
	cmp r0, 0
	beq _080362DC
	ldr r0, _080362D0
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080362D4
	ldr r2, _080362D8
	b _0803637C
	.align 2, 0
_080362D0: .4byte gUnknown_203B34C
_080362D4: .4byte gUnknown_80E5A78
_080362D8: .4byte gUnknown_80E5C18
_080362DC:
	ldr r0, _080362F0
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080362F4
	ldr r2, _080362F8
	b _0803637C
	.align 2, 0
_080362F0: .4byte gUnknown_203B34C
_080362F4: .4byte gUnknown_80E5BC4
_080362F8: .4byte gUnknown_80E5BDC
_080362FC:
	bl sub_803D0D8
	lsls r0, 24
	cmp r0, 0
	beq _08036324
	ldr r0, _08036318
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803631C
	ldr r2, _08036320
	b _0803637C
	.align 2, 0
_08036318: .4byte gUnknown_203B34C
_0803631C: .4byte gUnknown_80E5A78
_08036320: .4byte gUnknown_80E5AFC
_08036324:
	ldr r0, _08036338
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803633C
	ldr r2, _08036340
	b _0803637C
	.align 2, 0
_08036338: .4byte gUnknown_203B34C
_0803633C: .4byte gUnknown_80E5A60
_08036340: .4byte gUnknown_80E5A90
_08036344:
	bl sub_803D0D8
	lsls r0, 24
	cmp r0, 0
	beq _0803636C
	ldr r0, _08036360
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _08036364
	ldr r2, _08036368
	b _0803637C
	.align 2, 0
_08036360: .4byte gUnknown_203B34C
_08036364: .4byte gUnknown_80E5A78
_08036368: .4byte gUnknown_80E5B8C
_0803636C:
	ldr r0, _08036394
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _08036398
	ldr r2, _0803639C
_0803637C:
	str r2, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	ldr r2, _080363A0
	ldr r2, [r2]
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _080363C8
	.align 2, 0
_08036394: .4byte gUnknown_203B34C
_08036398: .4byte gUnknown_80E5B34
_0803639C: .4byte gUnknown_80E5B4C
_080363A0: .4byte gUnknown_203B350
_080363A4:
	ldr r0, _080363D0
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080363D4
	ldr r2, _080363D8
	str r2, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	ldr r2, _080363DC
	ldr r2, [r2]
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_080363C8:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080363D0: .4byte gUnknown_203B34C
_080363D4: .4byte gUnknown_80E59E0
_080363D8: .4byte gUnknown_80E59F8
_080363DC: .4byte gUnknown_203B350
	thumb_func_end sub_803628C

	thumb_func_start sub_80363E0
sub_80363E0:
	push {lr}
	ldr r0, _080363F4
	ldr r0, [r0]
	cmp r0, 0
	beq _080363F8
	ldr r0, [r0]
	cmp r0, 0xC
	beq _080363F8
	movs r0, 0x1
	b _080363FA
	.align 2, 0
_080363F4: .4byte gUnknown_203B34C
_080363F8:
	movs r0, 0
_080363FA:
	pop {r1}
	bx r1
	thumb_func_end sub_80363E0

	thumb_func_start sub_8036400
sub_8036400:
	push {r4,r5,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08036444
	movs r4, 0xE8
	lsls r4, 2
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
	bl sub_8035C1C
	bl sub_8035DA0
	ldr r1, [r5]
	movs r0, 0x13
	str r0, [r1, 0x4]
	movs r0, 0
	bl sub_8036FC4
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08036444: .4byte gUnknown_203B358
	thumb_func_end sub_8036400

	thumb_func_start sub_8036448
sub_8036448:
	push {lr}
	ldr r0, _08036460
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x12
	bhi _08036524
	lsls r0, 2
	ldr r1, _08036464
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036460: .4byte gUnknown_203B358
_08036464: .4byte _08036468
	.align 2, 0
_08036468:
	.4byte _080364B4
	.4byte _080364BA
	.4byte _080364C0
	.4byte _080364C6
	.4byte _080364D2
	.4byte _080364CC
	.4byte _080364D8
	.4byte _080364DE
	.4byte _080364E4
	.4byte _080364F0
	.4byte _080364F6
	.4byte _080364FC
	.4byte _08036502
	.4byte _08036514
	.4byte _08036508
	.4byte _080364EA
	.4byte _0803650E
	.4byte _0803651A
	.4byte _08036520
_080364B4:
	bl sub_803652C
	b _08036524
_080364BA:
	bl sub_8036590
	b _08036524
_080364C0:
	bl sub_80365AC
	b _08036524
_080364C6:
	bl sub_8036674
	b _08036524
_080364CC:
	bl sub_8036728
	b _08036524
_080364D2:
	bl sub_8036788
	b _08036524
_080364D8:
	bl sub_8036830
	b _08036524
_080364DE:
	bl sub_803689C
	b _08036524
_080364E4:
	bl sub_80368D4
	b _08036524
_080364EA:
	bl sub_8036A7C
	b _08036524
_080364F0:
	bl sub_8036934
	b _08036524
_080364F6:
	bl sub_8036950
	b _08036524
_080364FC:
	bl sub_8036AA4
	b _08036524
_08036502:
	bl sub_80369FC
	b _08036524
_08036508:
	bl sub_8036A34
	b _08036524
_0803650E:
	bl sub_8036A54
	b _08036524
_08036514:
	bl sub_8036A18
	b _08036524
_0803651A:
	bl sub_8036ADC
	b _08036524
_08036520:
	movs r0, 0x3
	b _08036526
_08036524:
	movs r0, 0
_08036526:
	pop {r1}
	bx r1
	thumb_func_end sub_8036448

	thumb_func_start sub_803652C
sub_803652C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	adds r1, r0, 0
	cmp r1, 0
	bne _0803658A
	ldr r2, [sp]
	cmp r2, 0x1
	beq _08036556
	cmp r2, 0x1
	bgt _0803654C
	cmp r2, 0
	beq _08036584
	b _0803658A
_0803654C:
	cmp r2, 0x2
	beq _0803656C
	cmp r2, 0x7
	beq _08036584
	b _0803658A
_08036556:
	ldr r0, _08036568
	ldr r0, [r0]
	str r1, [r0, 0x8]
	str r2, [r0, 0x10]
	movs r0, 0x1
	bl sub_8036FC4
	b _0803658A
	.align 2, 0
_08036568: .4byte gUnknown_203B358
_0803656C:
	ldr r0, _08036580
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1, 0x8]
	str r2, [r1, 0x10]
	movs r0, 0x7
	bl sub_8036FC4
	b _0803658A
	.align 2, 0
_08036580: .4byte gUnknown_203B358
_08036584:
	movs r0, 0x12
	bl sub_8036FC4
_0803658A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803652C

	thumb_func_start sub_8036590
sub_8036590:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080365A4
	movs r0, 0x2
	bl sub_8036FC4
_080365A4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036590

	thumb_func_start sub_80365AC
sub_80365AC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _080365E8
	ldr r0, [r4]
	ldr r7, _080365EC
	adds r0, r7
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r6, _080365F0
	adds r0, r6
	movs r5, 0x1
	strb r5, [r0]
	ldr r0, [r4]
	movs r2, 0x97
	lsls r2, 2
	mov r8, r2
	add r0, r8
	strb r1, [r0]
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x3
	beq _08036606
	cmp r0, 0x3
	bhi _080365F4
	cmp r0, 0x2
	beq _080365FA
	b _0803666A
	.align 2, 0
_080365E8: .4byte gUnknown_203B358
_080365EC: .4byte 0x0000025e
_080365F0: .4byte 0x0000025d
_080365F4:
	cmp r0, 0x4
	beq _0803662C
	b _0803666A
_080365FA:
	bl sub_801CBB8
	movs r0, 0
	bl sub_8036FC4
	b _0803666A
_08036606:
	bl sub_801CB24
	ldr r1, [r4]
	ldr r2, _08036624
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _08036628
	adds r0, r1
	strb r5, [r0]
	movs r0, 0x3
	bl sub_8036FC4
	b _0803666A
	.align 2, 0
_08036624: .4byte 0x0000025e
_08036628: .4byte 0x0000025d
_0803662C:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	bl sub_801CB24
	ldr r1, [r4]
	adds r1, r7
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r6
	strb r5, [r0]
	ldr r0, [r4]
	movs r2, 0xF2
	lsls r2, 1
	adds r0, r2
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	add r0, r8
	bl sub_801B3C0
	movs r0, 0x5
	bl sub_8036FC4
_0803666A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80365AC

	thumb_func_start sub_8036674
sub_8036674:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_801CA08
	ldr r4, _080366B8
	ldr r0, [r4]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080366A6
	ldr r0, [r4]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_080366A6:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _080366C6
	cmp r0, 0x3
	bgt _080366BC
	cmp r0, 0
	beq _08036700
	b _0803671A
	.align 2, 0
_080366B8: .4byte gUnknown_203B358
_080366BC:
	cmp r0, 0x4
	beq _080366CE
	cmp r0, 0x7
	beq _08036700
	b _0803671A
_080366C6:
	movs r0, 0x4
	bl sub_8036FC4
	b _0803671A
_080366CE:
	ldr r0, [r4]
	movs r1, 0x13
	str r1, [r0, 0x4]
	movs r1, 0xF2
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x97
	lsls r1, 2
	adds r0, r1
	bl sub_801B3C0
	movs r0, 0x5
	bl sub_8036FC4
	b _0803671A
_08036700:
	ldr r0, _08036724
	ldr r0, [r0]
	movs r1, 0xC2
	lsls r1, 1
	adds r0, r1
	movs r1, 0x3
	bl sub_8035CC0
	bl sub_801CCD8
	movs r0, 0x2
	bl sub_8036FC4
_0803671A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036724: .4byte gUnknown_203B358
	thumb_func_end sub_8036674

	thumb_func_start sub_8036728
sub_8036728:
	push {r4,lr}
	bl sub_801B410
	cmp r0, 0x1
	beq _08036780
	cmp r0, 0x1
	bcc _08036780
	cmp r0, 0x3
	bhi _08036780
	bl sub_801B450
	bl ResetUnusedInputStruct
	ldr r4, _08036778
	ldr r0, [r4]
	movs r1, 0xF2
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_801CB5C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x13
	bne _0803677C
	adds r0, r4, 0
	adds r0, 0x44
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x3
	bl sub_8036FC4
	b _08036780
	.align 2, 0
_08036778: .4byte gUnknown_203B358
_0803677C:
	bl sub_8036FC4
_08036780:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8036728

	thumb_func_start sub_8036788
sub_8036788:
	push {r4,lr}
	ldr r4, _080367B8
	ldr r0, [r4]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r1
	bl sub_8012FD8
	movs r0, 0
	bl sub_801CA08
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_8013BBC
	cmp r0, 0x1
	beq _080367BC
	cmp r0, 0x1
	bcc _08036824
	cmp r0, 0x2
	beq _080367D2
	cmp r0, 0x3
	beq _080367F8
	b _08036824
	.align 2, 0
_080367B8: .4byte gUnknown_203B358
_080367BC:
	bl sub_801CCD8
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x3
	movs r2, 0
	bl sub_8035CF4
	bl sub_8036F30
	b _08036824
_080367D2:
	ldr r0, [r4]
	movs r2, 0xC2
	lsls r2, 1
	adds r0, r2
	movs r1, 0x2
	bl sub_8035CC0
	bl sub_801CCD8
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x3
	bl sub_8036FC4
	b _08036824
_080367F8:
	ldr r0, [r4]
	ldr r1, [r0, 0x14]
	ldr r2, _0803682C
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, 0x1
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0xA
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, 0x4
	adds r1, r0, r2
	ldr r0, [r0, 0x14]
	str r0, [r1]
	bl sub_801CBB8
	movs r0, 0x6
	bl sub_8036FC4
_08036824:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803682C: .4byte 0x0000025d
	thumb_func_end sub_8036788

	thumb_func_start sub_8036830
sub_8036830:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036896
	ldr r0, [sp]
	cmp r0, 0x5
	beq _08036854
	cmp r0, 0x5
	bgt _0803684E
	cmp r0, 0
	beq _08036890
	b _08036896
_0803684E:
	cmp r0, 0x6
	beq _08036890
	b _08036896
_08036854:
	bl sub_801CBB8
	ldr r0, _08036884
	ldr r2, [r0]
	ldr r0, _08036888
	ldr r1, [r0]
	ldr r3, _0803688C
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r2, 0x50
	adds r2, r0
	ldrh r0, [r2]
	ldr r1, [r1, 0x14]
	subs r0, r1
	strh r0, [r2]
	movs r0, 0xF
	bl sub_8036FC4
	movs r0, 0
	bl sub_8012574
	b _08036896
	.align 2, 0
_08036884: .4byte gUnknown_203B460
_08036888: .4byte gUnknown_203B358
_0803688C: .4byte 0x0000025e
_08036890:
	movs r0, 0
	bl sub_8036FC4
_08036896:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036830

	thumb_func_start sub_803689C
sub_803689C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080368CE
	ldr r0, [sp]
	cmp r0, 0x5
	beq _080368C0
	cmp r0, 0x5
	bgt _080368BA
	cmp r0, 0
	beq _080368C8
	b _080368CE
_080368BA:
	cmp r0, 0x7
	beq _080368C8
	b _080368CE
_080368C0:
	movs r0, 0x9
	bl sub_8036FC4
	b _080368CE
_080368C8:
	movs r0, 0x12
	bl sub_8036FC4
_080368CE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803689C

	thumb_func_start sub_80368D4
sub_80368D4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803692A
	ldr r0, [sp]
	cmp r0, 0x5
	beq _080368F8
	cmp r0, 0x5
	bgt _080368F2
	cmp r0, 0
	beq _08036900
	b _0803692A
_080368F2:
	cmp r0, 0x7
	beq _08036900
	b _0803692A
_080368F8:
	movs r0, 0x9
	bl sub_8036FC4
	b _0803692A
_08036900:
	ldr r0, _08036930
	ldr r1, [r0]
	movs r2, 0x95
	lsls r2, 2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803692A
	adds r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0803692A
	bl sub_80369D0
	movs r0, 0x11
	bl sub_8036FC4
	movs r0, 0
	bl sub_8012574
_0803692A:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08036930: .4byte gUnknown_203B358
	thumb_func_end sub_80368D4

	thumb_func_start sub_8036934
sub_8036934:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036948
	movs r0, 0xA
	bl sub_8036FC4
_08036948:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036934

	thumb_func_start sub_8036950
sub_8036950:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080369C8
	ldr r0, _08036978
	ldr r2, [r0]
	ldr r1, [r2, 0xC]
	adds r3, r0, 0
	cmp r1, 0
	bne _0803698C
	ldr r0, [r2, 0x8]
	cmp r0, 0
	beq _0803697C
	cmp r0, 0x1
	beq _08036984
	b _080369C8
	.align 2, 0
_08036978: .4byte gUnknown_203B358
_0803697C:
	movs r0, 0xD
	bl sub_8036FC4
	b _080369C8
_08036984:
	movs r0, 0xE
	bl sub_8036FC4
	b _080369C8
_0803698C:
	ldr r0, [r2, 0x8]
	cmp r0, 0
	bne _080369BA
	movs r1, 0x95
	lsls r1, 2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080369BA
	adds r1, 0x4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080369BA
	bl sub_80369D0
	movs r0, 0xB
	bl sub_8036FC4
	movs r0, 0
	bl sub_8012574
	b _080369C8
_080369BA:
	ldr r0, [r3]
	ldr r0, [r0, 0xC]
	bl sub_8036E18
	movs r0, 0xC
	bl sub_8036FC4
_080369C8:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036950

	thumb_func_start sub_80369D0
sub_80369D0:
	ldr r0, _080369F4
	ldr r2, [r0]
	ldr r0, _080369F8
	ldr r1, [r0]
	movs r3, 0x95
	lsls r3, 2
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r2, 0x50
	adds r2, r0
	ldrh r0, [r2]
	adds r3, 0x4
	adds r1, r3
	ldr r1, [r1]
	adds r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_080369F4: .4byte gUnknown_203B460
_080369F8: .4byte gUnknown_203B358
	thumb_func_end sub_80369D0

	thumb_func_start sub_80369FC
sub_80369FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A10
	movs r0, 0
	bl sub_8036FC4
_08036A10:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80369FC

	thumb_func_start sub_8036A18
sub_8036A18:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A2C
	movs r0, 0x12
	bl sub_8036FC4
_08036A2C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A18

	thumb_func_start sub_8036A34
sub_8036A34:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A4E
	movs r0, 0x10
	bl sub_8036FC4
	movs r0, 0
	bl sub_8012574
_08036A4E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A34

	thumb_func_start sub_8036A54
sub_8036A54:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A76
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036A76
	bl sub_8012750
	movs r0, 0x12
	bl sub_8036FC4
_08036A76:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A54

	thumb_func_start sub_8036A7C
sub_8036A7C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A9E
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036A9E
	bl sub_8012750
	movs r0, 0x8
	bl sub_8036FC4
_08036A9E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A7C

	thumb_func_start sub_8036AA4
sub_8036AA4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036AD0
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036AD0
	bl sub_8012750
	ldr r0, _08036AD8
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bl sub_8036E18
	movs r0, 0xC
	bl sub_8036FC4
_08036AD0:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08036AD8: .4byte gUnknown_203B358
	thumb_func_end sub_8036AA4

	thumb_func_start sub_8036ADC
sub_8036ADC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036AFE
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036AFE
	bl sub_8012750
	movs r0, 0x12
	bl sub_8036FC4
_08036AFE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036ADC

	thumb_func_start sub_8036B04
sub_8036B04:
	push {r4,lr}
	ldr r4, _08036B20
	ldr r0, [r4]
	cmp r0, 0
	beq _08036B1A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	bl sub_801CBB8
_08036B1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036B20: .4byte gUnknown_203B358
	thumb_func_end sub_8036B04

	thumb_func_start nullsub_52
nullsub_52:
	bx lr
	thumb_func_end nullsub_52

	thumb_func_start sub_8036B28
sub_8036B28:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _08036B44
	ldr r0, [r1]
	ldr r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x12
	bls _08036B3A
	b _08036DFA
_08036B3A:
	lsls r0, 2
	ldr r1, _08036B48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036B44: .4byte gUnknown_203B358
_08036B48: .4byte _08036B4C
	.align 2, 0
_08036B4C:
	.4byte _08036B98
	.4byte _08036BDC
	.4byte _08036BE4
	.4byte _08036C14
	.4byte _08036C58
	.4byte _08036DFA
	.4byte _08036C5E
	.4byte _08036C90
	.4byte _08036C98
	.4byte _08036CC0
	.4byte _08036CD8
	.4byte _08036DFA
	.4byte _08036DFA
	.4byte _08036DD8
	.4byte _08036D70
	.4byte _08036DFA
	.4byte _08036DFA
	.4byte _08036DFA
	.4byte _08036DFA
_08036B98:
	movs r0, 0
	bl sub_801CF14
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08036BB8
	ldr r0, _08036BB0
	ldr r3, _08036BB4
	movs r2, 0
	b _08036BBC
	.align 2, 0
_08036BB0: .4byte gUnknown_80E61A4
_08036BB4: .4byte gUnknown_80E60D4
_08036BB8:
	ldr r0, _08036BD4
	ldr r3, _08036BD8
_08036BBC:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x1
	bl sub_8014248
	b _08036DFA
	.align 2, 0
_08036BD4: .4byte gUnknown_80E61A4
_08036BD8: .4byte gUnknown_80E60A0
_08036BDC:
	ldr r0, _08036BE0
	b _08036DBA
	.align 2, 0
_08036BE0: .4byte gUnknown_80E61C0
_08036BE4:
	bl sub_801D008
	cmp r0, 0
	beq _08036BEE
	b _08036DFA
_08036BEE:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _08036C10
	str r0, [sp, 0x14]
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0x14
	movs r3, 0x9
	bl sub_801C8C4
	b _08036DFA
	.align 2, 0
_08036C10: .4byte 0x00020003
_08036C14:
	ldr r0, [r5]
	movs r4, 0xC2
	lsls r4, 1
	adds r0, r4
	bl sub_8006518
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x44
	adds r1, r4
	ldr r3, _08036C50
	ldr r2, _08036C54
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_801CCD8
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	b _08036DFA
	.align 2, 0
_08036C50: .4byte gUnknown_80E60EC
_08036C54: .4byte gUnknown_80E6104
_08036C58:
	bl sub_8036F74
	b _08036DFA
_08036C5E:
	ldr r2, _08036C7C
	ldr r1, [r5]
	ldr r0, [r1, 0x14]
	str r0, [r2]
	ldr r0, _08036C80
	ldr r2, _08036C84
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
	ldr r0, _08036C88
	ldr r3, _08036C8C
	b _08036C9C
	.align 2, 0
_08036C7C: .4byte gUnknown_202DE30
_08036C80: .4byte gUnknown_202DE58
_08036C84: .4byte 0x0000025e
_08036C88: .4byte gUnknown_80E61E4
_08036C8C: .4byte gUnknown_80E6154
_08036C90:
	ldr r0, _08036C94
	b _08036C9A
	.align 2, 0
_08036C94: .4byte gUnknown_80E6214
_08036C98:
	ldr r0, _08036CB8
_08036C9A:
	ldr r3, _08036CBC
_08036C9C:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _08036DFA
	.align 2, 0
_08036CB8: .4byte gUnknown_80E6268
_08036CBC: .4byte gUnknown_80E618C
_08036CC0:
	movs r0, 0
	bl nullsub_23
	ldr r0, _08036CD4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _08036DFA
	.align 2, 0
_08036CD4: .4byte gUnknown_80E62C4
_08036CD8:
	ldr r4, _08036D18
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0xC]
	movs r2, 0
	movs r3, 0
	movs r5, 0x91
	lsls r5, 2
	adds r0, r1, r5
	str r2, [r0]
	str r3, [r0, 0x4]
	movs r0, 0x93
	lsls r0, 2
	adds r1, r0
	str r2, [r1]
	str r3, [r1, 0x4]
	bl sub_8011830
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	bl sub_8037B28
	ldr r4, [r4]
	str r0, [r4, 0xC]
	cmp r0, 0
	bne _08036D44
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _08036D1C
	cmp r0, 0x1
	beq _08036D2C
	b _08036D44
	.align 2, 0
_08036D18: .4byte gUnknown_203B358
_08036D1C:
	adds r2, r4, r5
	movs r1, 0x95
	lsls r1, 2
	adds r0, r4, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
_08036D2C:
	ldr r4, _08036D6C
	ldr r2, [r4]
	ldr r0, [r2, 0x8]
	movs r3, 0x91
	lsls r3, 2
	adds r1, r2, r3
	adds r3, 0x8
	adds r2, r3
	bl sub_8037D64
	ldr r1, [r4]
	str r0, [r1, 0xC]
_08036D44:
	ldr r4, _08036D6C
	ldr r2, [r4]
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _08036D66
	ldr r0, [r2, 0x8]
	cmp r0, 0x1
	bhi _08036D66
	movs r3, 0x91
	lsls r3, 2
	adds r1, r2, r3
	adds r3, 0x8
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0xC]
_08036D66:
	bl xxx_call_start_bg_music
	b _08036DFA
	.align 2, 0
_08036D6C: .4byte gUnknown_203B358
_08036D70:
	ldr r2, [r5]
	movs r1, 0x94
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08036DA4
	ldr r1, _08036D9C
	movs r3, 0x92
	lsls r3, 2
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08036DA0
	subs r3, 0x4
	adds r1, r2, r3
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
	b _08036DB8
	.align 2, 0
_08036D9C: .4byte gUnknown_202DE30
_08036DA0: .4byte gUnknown_202DE58
_08036DA4:
	ldr r0, _08036DC8
	str r1, [r0]
	ldr r0, _08036DCC
	movs r3, 0x93
	lsls r3, 2
	adds r1, r2, r3
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
_08036DB8:
	ldr r0, _08036DD0
_08036DBA:
	ldr r3, _08036DD4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08036DFA
	.align 2, 0
_08036DC8: .4byte gUnknown_202DE30
_08036DCC: .4byte gUnknown_202DE58
_08036DD0: .4byte gUnknown_80E6314
_08036DD4: .4byte 0x00000101
_08036DD8:
	ldr r2, _08036E04
	ldr r1, [r5]
	ldr r0, [r1, 0x14]
	str r0, [r2]
	ldr r0, _08036E08
	ldr r2, _08036E0C
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
	ldr r0, _08036E10
	ldr r3, _08036E14
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08036DFA:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036E04: .4byte gUnknown_202DE30
_08036E08: .4byte gUnknown_202DE58
_08036E0C: .4byte 0x0000025e
_08036E10: .4byte gUnknown_80E6358
_08036E14: .4byte 0x00000101
	thumb_func_end sub_8036B28

	thumb_func_start sub_8036E18
sub_8036E18:
	push {lr}
	cmp r0, 0xF
	bhi _08036EB4
	lsls r0, 2
	ldr r1, _08036E28
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036E28: .4byte _08036E2C
	.align 2, 0
_08036E2C:
	.4byte _08036EC0
	.4byte _08036E6C
	.4byte _08036E7C
	.4byte _08036E74
	.4byte _08036E84
	.4byte _08036E8C
	.4byte _08036EB4
	.4byte _08036EB4
	.4byte _08036EB4
	.4byte _08036EB4
	.4byte _08036EB4
	.4byte _08036EB4
	.4byte _08036EB4
	.4byte _08036EB4
	.4byte _08036E94
	.4byte _08036E9C
_08036E6C:
	ldr r0, _08036E70
	b _08036E9E
	.align 2, 0
_08036E70: .4byte gUnknown_80E6378
_08036E74:
	ldr r0, _08036E78
	b _08036E9E
	.align 2, 0
_08036E78: .4byte gUnknown_80E639C
_08036E7C:
	ldr r0, _08036E80
	b _08036E9E
	.align 2, 0
_08036E80: .4byte gUnknown_80E63F8
_08036E84:
	ldr r0, _08036E88
	b _08036E9E
	.align 2, 0
_08036E88: .4byte gUnknown_80E6448
_08036E8C:
	ldr r0, _08036E90
	b _08036E9E
	.align 2, 0
_08036E90: .4byte gUnknown_80E6378
_08036E94:
	ldr r0, _08036E98
	b _08036E9E
	.align 2, 0
_08036E98: .4byte gUnknown_80E6378
_08036E9C:
	ldr r0, _08036EAC
_08036E9E:
	ldr r3, _08036EB0
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08036EC0
	.align 2, 0
_08036EAC: .4byte gUnknown_80E64AC
_08036EB0: .4byte 0x00000101
_08036EB4:
	ldr r0, _08036EC4
	ldr r3, _08036EC8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08036EC0:
	pop {r0}
	bx r0
	.align 2, 0
_08036EC4: .4byte gUnknown_80E6378
_08036EC8: .4byte 0x00000101
	thumb_func_end sub_8036E18

	thumb_func_start sub_8036ECC
sub_8036ECC:
	push {r4-r6,lr}
	adds r3, r0, 0
	ldr r6, _08036F28
	ldr r0, [r6]
	movs r2, 0x3
	str r2, [r0, 0x24]
	movs r2, 0x1
	str r2, [r0, 0x18]
	str r2, [r0, 0x1C]
	str r1, [r0, 0x20]
	movs r1, 0x2C
	str r1, [r0, 0x30]
	movs r1, 0x12
	str r1, [r0, 0x34]
	str r3, [r0, 0x28]
	lsls r4, r3, 1
	adds r4, r3
	lsls r4, 3
	movs r5, 0xC2
	lsls r5, 1
	adds r1, r4, r5
	adds r1, r0, r1
	str r1, [r0, 0x2C]
	adds r0, 0x14
	bl sub_8013AA0
	ldr r1, [r6]
	adds r1, r4
	adds r1, r5
	ldr r0, _08036F2C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036F28: .4byte gUnknown_203B358
_08036F2C: .4byte gUnknown_80E6174
	thumb_func_end sub_8036ECC

	thumb_func_start sub_8036F30
sub_8036F30:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _08036F6C
	ldr r0, [r5]
	ldr r4, [r0, 0x28]
	adds r0, r4, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _08036F70
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	adds r0, 0x14
	bl sub_8013C68
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036F6C: .4byte gUnknown_203B358
_08036F70: .4byte gUnknown_80E6528
	thumb_func_end sub_8036F30

	thumb_func_start sub_8036F74
sub_8036F74:
	push {r4,lr}
	ldr r4, _08036FB8
	ldr r0, [r4]
	movs r1, 0xC2
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r0, _08036FBC
	ldr r1, [r0]
	ldr r0, [r4]
	ldr r2, _08036FC0
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x2
	bl sub_8036ECC
	bl sub_801CCD8
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x3
	movs r2, 0
	bl sub_8035CF4
	bl sub_8036F30
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036FB8: .4byte gUnknown_203B358
_08036FBC: .4byte gUnknown_203B460
_08036FC0: .4byte 0x0000025e
	thumb_func_end sub_8036F74

	thumb_func_start sub_8036FC4
sub_8036FC4:
	push {lr}
	ldr r1, _08036FD8
	ldr r1, [r1]
	str r0, [r1]
	bl nullsub_52
	bl sub_8036B28
	pop {r0}
	bx r0
	.align 2, 0
_08036FD8: .4byte gUnknown_203B358
	thumb_func_end sub_8036FC4

	thumb_func_start sub_8036FDC
sub_8036FDC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r6, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl ResetSprites
	ldr r5, _080370C0
	ldr r0, [r5]
	cmp r0, 0
	bne _08037016
	ldr r4, _080370C4
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08037016:
	ldr r0, [r5]
	str r6, [r0]
	movs r1, 0
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	movs r3, 0
	adds r7, r5, 0
	movs r6, 0xE0
	lsls r6, 1
	movs r4, 0
	movs r5, 0xDE
	lsls r5, 1
_0803702E:
	ldr r0, [r7]
	lsls r2, r3, 3
	adds r1, r0, r6
	adds r1, r2
	str r4, [r1]
	adds r0, r2
	adds r0, r5
	strb r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0803702E
	ldr r0, _080370C0
	mov r12, r0
	movs r5, 0xAE
	lsls r5, 1
	mov r8, r5
	ldr r4, _080370C8
	movs r3, 0
	movs r2, 0x3
_08037054:
	mov r6, r12
	ldr r1, [r6]
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
	bge _08037054
	movs r6, 0
	bl ResetUnusedInputStruct
	ldr r5, _080370C0
	ldr r0, [r5]
	movs r4, 0xAE
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x1C
	adds r1, r4
	ldr r3, _080370CC
	ldr r2, _080370D0
	str r2, [sp]
	str r6, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r6, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r0, [r5]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	bl sub_80376CC
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080370C0: .4byte gUnknown_203B35C
_080370C4: .4byte 0x00000504
_080370C8: .4byte gUnknown_80E653C
_080370CC: .4byte gUnknown_80E6CD0
_080370D0: .4byte gUnknown_80E6CE8
	thumb_func_end sub_8036FDC

	thumb_func_start sub_80370D4
sub_80370D4:
	push {r4,lr}
	ldr r4, _080370EC
	ldr r0, [r4]
	cmp r0, 0
	beq _080370E6
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080370E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080370EC: .4byte gUnknown_203B35C
	thumb_func_end sub_80370D4

	thumb_func_start sub_80370F0
sub_80370F0:
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0x4
	str r0, [sp]
	ldr r5, _08037110
	ldr r4, _08037114
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	cmp r0, 0x1
	beq _08037148
	cmp r0, 0x1
	bcc _08037118
	cmp r0, 0x2
	beq _08037158
	b _080371A8
	.align 2, 0
_08037110: .4byte 0x0000ffdc
_08037114: .4byte gUnknown_203B35C
_08037118:
	adds r0, r1, 0
	adds r0, 0x1C
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _08037130
	ldr r0, [r4]
	adds r0, 0x1C
	mov r1, sp
	bl sub_8013114
_08037130:
	ldr r0, [sp]
	cmp r0, 0x4
	bne _0803713C
	bl sub_8037748
	b _080371A8
_0803713C:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0x8]
	bl sub_8037900
	b _080371A8
_08037148:
	bl sub_80376CC
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x8]
	bl sub_80371B8
	b _080371A8
_08037158:
	ldr r0, [r1]
	cmp r0, 0x1
	bhi _08037172
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _08037172
	movs r0, 0
	bl sub_8037C10
	cmp r0, 0
	bne _08037172
	movs r0, 0x29
	b _080371AA
_08037172:
	ldr r4, _080371B4
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _0803718C
	ldr r0, [r4]
	adds r0, 0x1C
	mov r1, sp
	bl sub_8013114
_0803718C:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080371A4
	movs r0, 0x3
	bl sub_80119D4
	bl sub_8037798
	adds r5, r0, 0
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0x8]
_080371A4:
	bl sub_8037748
_080371A8:
	adds r0, r5, 0
_080371AA:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080371B4: .4byte gUnknown_203B35C
	thumb_func_end sub_80370F0

	thumb_func_start sub_80371B8
sub_80371B8:
	push {r4-r7,lr}
	sub sp, 0x10
	movs r6, 0
	movs r5, 0
	bl sub_8037400
	ldr r7, _0803721C
	ldr r1, [r7]
	ldr r0, [r1]
	cmp r0, 0x1
	bhi _08037228
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _08037228
	movs r0, 0
	bl sub_8037C10
	cmp r0, 0
	bne _080371E0
	b _080373AC
_080371E0:
	bl sub_80376CC
	ldr r0, [r7]
	movs r4, 0xAE
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	bl sub_8035CC0
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x1C
	adds r1, r4
	ldr r3, _08037220
	ldr r2, _08037224
	str r2, [sp]
	str r6, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r6, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r0, [r7]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	b _080373AC
	.align 2, 0
_0803721C: .4byte gUnknown_203B35C
_08037220: .4byte gUnknown_80E6C50
_08037224: .4byte gUnknown_80E6C68
_08037228:
	bl sub_80376CC
	ldr r4, _08037250
	ldr r0, [r4]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	cmp r0, 0xF
	bls _08037246
	b _0803734C
_08037246:
	lsls r0, 2
	ldr r1, _08037254
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037250: .4byte gUnknown_203B35C
_08037254: .4byte _08037258
	.align 2, 0
_08037258:
	.4byte _08037298
	.4byte _080372D8
	.4byte _080372B8
	.4byte _080372A8
	.4byte _080372C8
	.4byte _080372D8
	.4byte _080372E8
	.4byte _080372F8
	.4byte _0803734C
	.4byte _08037308
	.4byte _0803734C
	.4byte _08037318
	.4byte _0803734C
	.4byte _08037328
	.4byte _08037338
	.4byte _08037348
_08037298:
	ldr r6, _080372A0
	ldr r5, _080372A4
	b _0803734C
	.align 2, 0
_080372A0: .4byte gUnknown_80E66BC
_080372A4: .4byte gUnknown_80E66D4
_080372A8:
	ldr r6, _080372B0
	ldr r5, _080372B4
	b _0803734C
	.align 2, 0
_080372B0: .4byte gUnknown_80E6D54
_080372B4: .4byte gUnknown_80E6D6C
_080372B8:
	ldr r6, _080372C0
	ldr r5, _080372C4
	b _0803734C
	.align 2, 0
_080372C0: .4byte gUnknown_80E6DDC
_080372C4: .4byte gUnknown_80E6DF4
_080372C8:
	ldr r6, _080372D0
	ldr r5, _080372D4
	b _0803734C
	.align 2, 0
_080372D0: .4byte gUnknown_80E67D4
_080372D4: .4byte gUnknown_80E67EC
_080372D8:
	ldr r6, _080372E0
	ldr r5, _080372E4
	b _0803734C
	.align 2, 0
_080372E0: .4byte gUnknown_80E6748
_080372E4: .4byte gUnknown_80E6760
_080372E8:
	ldr r6, _080372F0
	ldr r5, _080372F4
	b _0803734C
	.align 2, 0
_080372F0: .4byte gUnknown_80E689C
_080372F4: .4byte gUnknown_80E68B4
_080372F8:
	ldr r6, _08037300
	ldr r5, _08037304
	b _0803734C
	.align 2, 0
_08037300: .4byte gUnknown_80E6938
_08037304: .4byte gUnknown_80E6950
_08037308:
	ldr r6, _08037310
	ldr r5, _08037314
	b _0803734C
	.align 2, 0
_08037310: .4byte gUnknown_80E69B0
_08037314: .4byte gUnknown_80E69C8
_08037318:
	ldr r6, _08037320
	ldr r5, _08037324
	b _0803734C
	.align 2, 0
_08037320: .4byte gUnknown_80E6A10
_08037324: .4byte gUnknown_80E6A28
_08037328:
	ldr r6, _08037330
	ldr r5, _08037334
	b _0803734C
	.align 2, 0
_08037330: .4byte gUnknown_80E6A74
_08037334: .4byte gUnknown_80E6A8C
_08037338:
	ldr r6, _08037340
	ldr r5, _08037344
	b _0803734C
	.align 2, 0
_08037340: .4byte gUnknown_80E6B78
_08037344: .4byte gUnknown_80E6B90
_08037348:
	ldr r6, _080373B4
	ldr r5, _080373B8
_0803734C:
	ldr r4, _080373BC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	str r5, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	movs r2, 0
	adds r3, r6, 0
	bl SetMenuItems
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _080373AC
	ldr r0, [r4]
	cmp r0, 0
	bne _080373AC
	bl sub_8035D94
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080373AC
	ldr r3, [r2, 0x4]
	cmp r3, 0
	beq _080373AC
	ldr r0, _080373C0
	ldr r1, [r0]
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, r3
	strh r0, [r1]
_080373AC:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080373B4: .4byte gUnknown_80E6BF4
_080373B8: .4byte gUnknown_80E6C0C
_080373BC: .4byte gUnknown_203B35C
_080373C0: .4byte gUnknown_203B460
	thumb_func_end sub_80371B8

	thumb_func_start sub_80373C4
sub_80373C4:
	push {lr}
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	bl sub_800CB20
	bl LoadBufferedInputs
	bl TransferBGPaletteBuffer
	bl xxx_call_update_bg_vram
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	movs r0, 0
	bl ResetSprites
	pop {r0}
	bx r0
	thumb_func_end sub_80373C4

	thumb_func_start sub_80373F4
sub_80373F4:
	ldr r0, _080373FC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080373FC: .4byte gUnknown_203B35C
	thumb_func_end sub_80373F4

	thumb_func_start sub_8037400
sub_8037400:
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	bl sub_8037810
	bl sub_8011830
	ldr r4, _08037434
	ldr r0, [r4]
	ldr r0, [r0]
	bl sub_8037B28
	ldr r4, [r4]
	str r0, [r4, 0x4]
	cmp r0, 0
	beq _08037422
	b _080376BE
_08037422:
	ldr r0, [r4]
	cmp r0, 0xA
	bls _0803742A
	b _080375E8
_0803742A:
	lsls r0, 2
	ldr r1, _08037438
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037434: .4byte gUnknown_203B35C
_08037438: .4byte _0803743C
	.align 2, 0
_0803743C:
	.4byte _08037494
	.4byte _080374B8
	.4byte _08037534
	.4byte _0803751C
	.4byte _0803756C
	.4byte _080375D8
	.4byte _080374E4
	.4byte _080374D0
	.4byte _080375E8
	.4byte _08037480
	.4byte _08037468
_08037468:
	ldr r0, _0803747C
	ldr r0, [r0]
	movs r1, 0xE7
	lsls r1, 2
	adds r6, r0, r1
	movs r2, 0x8A
	lsls r2, 3
	adds r5, r0, r2
	b _080375E8
	.align 2, 0
_0803747C: .4byte gUnknown_203B35C
_08037480:
	ldr r0, _08037490
	ldr r0, [r0]
	movs r3, 0xE7
	lsls r3, 2
	adds r6, r0, r3
	movs r4, 0x8A
	lsls r4, 3
	b _080375E6
	.align 2, 0
_08037490: .4byte gUnknown_203B35C
_08037494:
	bl sub_8035D94
	ldr r1, _080374B4
	ldr r3, [r1]
	movs r5, 0xDE
	lsls r5, 1
	adds r2, r3, r5
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r6, r2, 0
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r3, r0
	b _080375E8
	.align 2, 0
_080374B4: .4byte gUnknown_203B35C
_080374B8:
	ldr r0, _080374CC
	ldr r0, [r0]
	movs r1, 0xDE
	lsls r1, 1
	adds r6, r0, r1
	movs r2, 0xE2
	lsls r2, 1
	adds r5, r0, r2
	b _080375E8
	.align 2, 0
_080374CC: .4byte gUnknown_203B35C
_080374D0:
	ldr r0, _080374E0
	ldr r0, [r0]
	movs r3, 0xE6
	lsls r3, 1
	adds r6, r0, r3
	movs r4, 0xFE
	lsls r4, 1
	b _080375E6
	.align 2, 0
_080374E0: .4byte gUnknown_203B35C
_080374E4:
	bl sub_8035D74
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	ldr r3, _08037518
	ldr r1, [r3]
	movs r2, 0xE6
	lsls r2, 1
	adds r1, r2
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r6, r0, r2
	movs r1, 0xFE
	lsls r1, 1
	adds r5, r0, r1
	b _080375E8
	.align 2, 0
_08037518: .4byte gUnknown_203B35C
_0803751C:
	ldr r0, _08037530
	ldr r0, [r0]
	movs r2, 0x8B
	lsls r2, 2
	adds r6, r0, r2
	movs r3, 0x97
	lsls r3, 2
	adds r5, r0, r3
	b _080375E8
	.align 2, 0
_08037530: .4byte gUnknown_203B35C
_08037534:
	bl sub_8035D74
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	ldr r3, _08037568
	ldr r1, [r3]
	movs r2, 0x8B
	lsls r2, 2
	adds r1, r2
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r6, r0, r2
	movs r1, 0x97
	lsls r1, 2
	adds r5, r0, r1
	b _080375E8
	.align 2, 0
_08037568: .4byte gUnknown_203B35C
_0803756C:
	bl sub_8035D74
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	ldr r4, _080375CC
	ldr r1, [r4]
	movs r5, 0xA3
	lsls r5, 2
	adds r1, r5
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl sub_8035D3C
	lsls r0, 16
	ldr r1, _080375D0
	cmp r0, r1
	beq _080375BE
	bl sub_8035D3C
	ldr r3, [r4]
	movs r1, 0xAF
	lsls r1, 2
	adds r3, r1
	ldr r1, _080375D4
	ldr r1, [r1]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x58
	muls r0, r2
	adds r1, r0
	adds r0, r3, 0
	bl memcpy
_080375BE:
	ldr r0, [r4]
	adds r6, r0, r5
	movs r2, 0xC5
	lsls r2, 2
	adds r5, r0, r2
	b _080375E8
	.align 2, 0
_080375CC: .4byte gUnknown_203B35C
_080375D0: .4byte 0xffff0000
_080375D4: .4byte gUnknown_203B45C
_080375D8:
	ldr r0, _08037610
	ldr r0, [r0]
	movs r3, 0xA3
	lsls r3, 2
	adds r6, r0, r3
	movs r4, 0xC5
	lsls r4, 2
_080375E6:
	adds r5, r0, r4
_080375E8:
	ldr r4, _08037610
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_8037D64
	ldr r1, [r4]
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _080376BE
	ldr r0, [r1]
	cmp r0, 0xA
	bhi _080376AE
	lsls r0, 2
	ldr r1, _08037614
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037610: .4byte gUnknown_203B35C
_08037614: .4byte _08037618
	.align 2, 0
_08037618:
	.4byte _08037644
	.4byte _08037644
	.4byte _08037658
	.4byte _08037658
	.4byte _0803766C
	.4byte _0803766C
	.4byte _08037684
	.4byte _08037684
	.4byte _080376AE
	.4byte _0803769C
	.4byte _0803769C
_08037644:
	ldr r0, _08037654
	ldr r2, [r0]
	movs r5, 0xDE
	lsls r5, 1
	adds r6, r2, r5
	movs r1, 0xE2
	lsls r1, 1
	b _0803767A
	.align 2, 0
_08037654: .4byte gUnknown_203B35C
_08037658:
	ldr r0, _08037668
	ldr r2, [r0]
	movs r3, 0x8B
	lsls r3, 2
	adds r6, r2, r3
	movs r4, 0x97
	lsls r4, 2
	b _08037692
	.align 2, 0
_08037668: .4byte gUnknown_203B35C
_0803766C:
	ldr r0, _08037680
	ldr r2, [r0]
	movs r5, 0xA3
	lsls r5, 2
	adds r6, r2, r5
	movs r1, 0xC5
	lsls r1, 2
_0803767A:
	adds r5, r2, r1
	adds r4, r0, 0
	b _080376AE
	.align 2, 0
_08037680: .4byte gUnknown_203B35C
_08037684:
	ldr r0, _08037698
	ldr r2, [r0]
	movs r3, 0xE6
	lsls r3, 1
	adds r6, r2, r3
	movs r4, 0xFE
	lsls r4, 1
_08037692:
	adds r5, r2, r4
	adds r4, r0, 0
	b _080376AE
	.align 2, 0
_08037698: .4byte gUnknown_203B35C
_0803769C:
	ldr r1, _080376C8
	ldr r0, [r1]
	movs r5, 0xE7
	lsls r5, 2
	adds r6, r0, r5
	movs r2, 0x8A
	lsls r2, 3
	adds r5, r0, r2
	adds r4, r1, 0
_080376AE:
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x4]
_080376BE:
	bl xxx_call_start_bg_music
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080376C8: .4byte gUnknown_203B35C
	thumb_func_end sub_8037400

	thumb_func_start sub_80376CC
sub_80376CC:
	push {r4,lr}
	ldr r0, _08037728
	ldr r3, [r0]
	ldrh r1, [r3, 0xC]
	ldr r0, _0803772C
	ands r0, r1
	ldr r1, _08037730
	ands r0, r1
	ldr r4, _08037734
	ands r0, r4
	ldr r1, _08037738
	ands r0, r1
	ldr r1, _0803773C
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _08037740
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0xC]
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x10]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r2, 0xF
	movs r4, 0xF0
	lsls r4, 8
	ldr r1, _08037744
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x10]
	movs r0, 0
	strh r0, [r3, 0xE]
	movs r1, 0xC0
	lsls r1, 4
	ldrh r0, [r3, 0x12]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x12]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037728: .4byte gUnknown_203B35C
_0803772C: .4byte 0x0000feff
_08037730: .4byte 0x0000fdff
_08037734: .4byte 0x0000f3ff
_08037738: .4byte 0x0000efff
_0803773C: .4byte 0x0000dfff
_08037740: .4byte 0x00003fff
_08037744: .4byte 0x00000fff
	thumb_func_end sub_80376CC

	thumb_func_start sub_8037748
sub_8037748:
	push {r4,lr}
	ldr r4, _08037794
	ldr r3, [r4]
	ldrh r1, [r3, 0xE]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r1
	movs r1, 0x70
	orrs r0, r1
	strh r0, [r3, 0xE]
	movs r2, 0xD0
	lsls r2, 3
	ldrh r1, [r3, 0x12]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0x12]
	ldr r0, [r3, 0x14]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08037782
	adds r0, r3, 0
	adds r0, 0xC
	adds r1, 0xF8
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08037782:
	bl xxx_draw_string_80144C4
	ldr r1, [r4]
	ldr r0, [r1, 0x14]
	adds r0, 0x1
	str r0, [r1, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037794: .4byte gUnknown_203B35C
	thumb_func_end sub_8037748

	thumb_func_start sub_8037798
sub_8037798:
	push {lr}
	ldr r2, _080377B4
	ldr r1, _080377B8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r3, r1, 0
	cmp r0, 0xA
	bhi _0803780A
	lsls r0, 2
	ldr r1, _080377BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080377B4: .4byte 0x0000ffdc
_080377B8: .4byte gUnknown_203B35C
_080377BC: .4byte _080377C0
	.align 2, 0
_080377C0:
	.4byte _080377EC
	.4byte _080377EC
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _0803780A
	.4byte _080377FE
	.4byte _080377FE
_080377EC:
	movs r2, 0x1
	b _0803780A
_080377F0:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	movs r2, 0x1
	cmp r0, 0
	bne _0803780A
	movs r2, 0x2A
	b _0803780A
_080377FE:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	movs r2, 0xD
	cmp r0, 0
	bne _0803780A
	movs r2, 0x2B
_0803780A:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8037798

	thumb_func_start sub_8037810
sub_8037810:
	push {r4-r6,lr}
	ldr r6, _080378FC
	ldr r0, [r6]
	movs r5, 0xDE
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	movs r4, 0xE2
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	adds r5, r0, r5
	movs r1, 0
	movs r2, 0
	str r1, [r5]
	str r2, [r5, 0x4]
	adds r4, r0, r4
	str r1, [r4]
	str r2, [r4, 0x4]
	movs r2, 0xE6
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xFE
	lsls r3, 1
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0x8B
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x97
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xA3
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xC5
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0xAF
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xD1
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xE7
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x8A
	lsls r2, 3
	adds r0, r2
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r2, [r6]
	movs r3, 0xB1
	lsls r3, 2
	adds r0, r2, r3
	movs r1, 0
	strh r1, [r0]
	adds r3, 0x88
	adds r0, r2, r3
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080378FC: .4byte gUnknown_203B35C
	thumb_func_end sub_8037810

	thumb_func_start sub_8037900
sub_8037900:
	push {r4,lr}
	sub sp, 0x10
	ldr r4, _08037928
	ldr r0, [r4]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xA
	bls _0803791E
	b _08037A14
_0803791E:
	lsls r0, 2
	ldr r1, _0803792C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037928: .4byte gUnknown_203B35C
_0803792C: .4byte _08037930
	.align 2, 0
_08037930:
	.4byte _0803795C
	.4byte _0803795C
	.4byte _0803797C
	.4byte _0803797C
	.4byte _0803799C
	.4byte _0803799C
	.4byte _080379BC
	.4byte _080379BC
	.4byte _08037A14
	.4byte _080379F0
	.4byte _080379F0
_0803795C:
	ldr r0, _08037970
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037974
	ldr r2, _08037978
	b _080379CE
	.align 2, 0
_08037970: .4byte gUnknown_203B35C
_08037974: .4byte gUnknown_80E6554
_08037978: .4byte gUnknown_80E656C
_0803797C:
	ldr r0, _08037990
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037994
	ldr r2, _08037998
	b _080379CE
	.align 2, 0
_08037990: .4byte gUnknown_203B35C
_08037994: .4byte gUnknown_80E6554
_08037998: .4byte gUnknown_80E65D8
_0803799C:
	ldr r0, _080379B0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379B4
	ldr r2, _080379B8
	b _080379CE
	.align 2, 0
_080379B0: .4byte gUnknown_203B35C
_080379B4: .4byte gUnknown_80E6554
_080379B8: .4byte gUnknown_80E661C
_080379BC:
	ldr r0, _080379E4
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379E8
	ldr r2, _080379EC
_080379CE:
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08037A14
	.align 2, 0
_080379E4: .4byte gUnknown_203B35C
_080379E8: .4byte gUnknown_80E6554
_080379EC: .4byte gUnknown_80E665C
_080379F0:
	ldr r0, _08037A38
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037A3C
	ldr r2, _08037A40
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08037A14:
	ldr r4, _08037A38
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	bl sub_80373C4
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_80130A8
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037A38: .4byte gUnknown_203B35C
_08037A3C: .4byte gUnknown_80E6554
_08037A40: .4byte gUnknown_80E667C
	thumb_func_end sub_8037900

	thumb_func_start nullsub_202
nullsub_202:
	bx lr
	thumb_func_end nullsub_202

	thumb_func_start sub_8037A48
sub_8037A48:
	push {r4-r6,lr}
	sub sp, 0x28
	movs r6, 0x1
	movs r0, 0
	mov r1, sp
	movs r2, 0x14
	bl sub_800D670
	add r4, sp, 0x14
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x14
	bl sub_800D670
	ldr r1, _08037AAC
	movs r3, 0x8
	adds r2, r1, 0
	adds r0, r2, 0x4
_08037A6C:
	str r3, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _08037A6C
	ldr r0, [sp, 0x10]
	str r0, [r2]
	ldr r0, [r4, 0x10]
	str r0, [r2, 0x4]
	ldr r5, _08037AB0
	mov r0, sp
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037A8C
	movs r0, 0x1
_08037A8C:
	lsls r0, 24
	cmp r0, 0
	bne _08037AA6
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037AA0
	movs r0, 0x1
_08037AA0:
	lsls r0, 24
	cmp r0, 0
	beq _08037AB4
_08037AA6:
	movs r0, 0
	b _08037B1E
	.align 2, 0
_08037AAC: .4byte gUnknown_202EC40
_08037AB0: .4byte gUnknown_80E6E50
_08037AB4:
	ldr r1, [sp, 0x10]
	cmp r1, 0
	bne _08037AC0
	ldr r0, [r4, 0x10]
	cmp r0, 0x1
	beq _08037B1C
_08037AC0:
	cmp r1, 0x1
	bne _08037ACA
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _08037B1C
_08037ACA:
	cmp r1, 0x2
	bne _08037AD4
	ldr r0, [r4, 0x10]
	cmp r0, 0x3
	beq _08037B1C
_08037AD4:
	cmp r1, 0x3
	bne _08037ADE
	ldr r0, [r4, 0x10]
	cmp r0, 0x2
	beq _08037B1C
_08037ADE:
	cmp r1, 0x9
	bne _08037AE8
	ldr r0, [r4, 0x10]
	cmp r0, 0xA
	beq _08037B1C
_08037AE8:
	cmp r1, 0xA
	bne _08037AF2
	ldr r0, [r4, 0x10]
	cmp r0, 0x9
	beq _08037B1C
_08037AF2:
	cmp r1, 0x4
	bne _08037AFC
	ldr r0, [r4, 0x10]
	cmp r0, 0x5
	beq _08037B1C
_08037AFC:
	cmp r1, 0x5
	bne _08037B06
	ldr r0, [r4, 0x10]
	cmp r0, 0x4
	beq _08037B1C
_08037B06:
	cmp r1, 0x6
	bne _08037B10
	ldr r0, [r4, 0x10]
	cmp r0, 0x7
	beq _08037B1C
_08037B10:
	cmp r1, 0x7
	bne _08037B1A
	ldr r0, [r4, 0x10]
	cmp r0, 0x6
	beq _08037B1C
_08037B1A:
	movs r6, 0
_08037B1C:
	adds r0, r6, 0
_08037B1E:
	add sp, 0x28
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8037A48

	thumb_func_start sub_8037B28
sub_8037B28:
	push {r4,r5,lr}
	sub sp, 0x14
	adds r4, r0, 0
	movs r5, 0
	bl sub_800D414
	ldr r0, _08037B58
	str r5, [r0]
	ldr r5, _08037B5C
	mov r0, sp
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill8
	mov r0, sp
	adds r1, r5, 0
	bl strcpy
	str r4, [sp, 0x10]
	mov r0, sp
	movs r1, 0x14
	bl sub_800D59C
	b _08037B7A
	.align 2, 0
_08037B58: .4byte gUnknown_202EC38
_08037B5C: .4byte gUnknown_80E6E50
_08037B60:
	cmp r5, 0x3
	beq _08037BCC
	cmp r5, 0x4
	beq _08037BD8
	cmp r5, 0x5
	beq _08037BF0
	ldr r2, _08037BC0
	ldr r1, [r2]
	ldr r0, _08037BC4
	cmp r1, r0
	bgt _08037BE4
	adds r0, r1, 0x1
	str r0, [r2]
_08037B7A:
	movs r4, 0
_08037B7C:
	bl sub_80373C4
	bl sub_8012AE8
	cmp r0, 0x3
	bgt _08037B8C
	cmp r0, 0x2
	bge _08037BF0
_08037B8C:
	adds r4, 0x1
	cmp r4, 0
	ble _08037B7C
	bl sub_800D33C
	adds r5, r0, 0
	bl sub_800D570
	cmp r5, 0x2
	bne _08037B60
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08037BFC
	bl sub_8037A48
	lsls r0, 24
	cmp r0, 0
	bne _08037BC8
	movs r4, 0x4
	bl sub_800D520
	bl sub_800D510
	b _08037C06
	.align 2, 0
_08037BC0: .4byte gUnknown_202EC38
_08037BC4: .4byte 0x00000707
_08037BC8:
	movs r4, 0
	b _08037C06
_08037BCC:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x2
	b _08037C08
_08037BD8:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x3
	b _08037C08
_08037BE4:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08037C08
_08037BF0:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08037C08
_08037BFC:
	movs r4, 0x5
	bl sub_800D520
	bl sub_800D510
_08037C06:
	adds r0, r4, 0
_08037C08:
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8037B28

	thumb_func_start sub_8037C10
sub_8037C10:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _08037C24
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037C38
	b _08037C2E
_08037C24:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _08037C38
_08037C2E:
	ldr r0, _08037C34
	ldr r0, [r0, 0x4]
	b _08037C3C
	.align 2, 0
_08037C34: .4byte gUnknown_202EC40
_08037C38:
	ldr r0, _08037C40
	ldr r0, [r0]
_08037C3C:
	pop {r1}
	bx r1
	.align 2, 0
_08037C40: .4byte gUnknown_202EC40
	thumb_func_end sub_8037C10

	thumb_func_start sub_8037C44
sub_8037C44:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r4, 0
_08037C4C:
	adds r0, r4, 0
	bl sub_800D68C
	adds r4, 0x1
	cmp r4, 0x1
	ble _08037C4C
	cmp r6, 0xA
	bhi _08037CBE
	lsls r0, r6, 2
	ldr r1, _08037C68
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037C68: .4byte _08037C6C
	.align 2, 0
_08037C6C:
	.4byte _08037C98
	.4byte _08037C98
	.4byte _08037CA2
	.4byte _08037CA2
	.4byte _08037CAC
	.4byte _08037CAC
	.4byte _08037CA2
	.4byte _08037CA2
	.4byte _08037CBE
	.4byte _08037CB6
	.4byte _08037CB6
_08037C98:
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_800D59C
	b _08037CBE
_08037CA2:
	adds r0, r5, 0
	movs r1, 0x30
	bl sub_800D59C
	b _08037CBE
_08037CAC:
	adds r0, r5, 0
	movs r1, 0x88
	bl sub_800D59C
	b _08037CBE
_08037CB6:
	adds r0, r5, 0
	movs r1, 0xB4
	bl sub_800D59C
_08037CBE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8037C44

	thumb_func_start sub_8037CC4
sub_8037CC4:
	push {r4,lr}
	adds r3, r1, 0
	adds r4, r2, 0
	cmp r0, 0xA
	bhi _08037D5E
	lsls r0, 2
	ldr r1, _08037CD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037CD8: .4byte _08037CDC
	.align 2, 0
_08037CDC:
	.4byte _08037D08
	.4byte _08037D08
	.4byte _08037D1E
	.4byte _08037D1E
	.4byte _08037D34
	.4byte _08037D34
	.4byte _08037D1E
	.4byte _08037D1E
	.4byte _08037D5E
	.4byte _08037D4A
	.4byte _08037D4A
_08037D08:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x8
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x8
	bl sub_800D670
	b _08037D5E
_08037D1E:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x30
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x30
	bl sub_800D670
	b _08037D5E
_08037D34:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x88
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x88
	bl sub_800D670
	b _08037D5E
_08037D4A:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0xB4
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xB4
	bl sub_800D670
_08037D5E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8037CC4

	thumb_func_start sub_8037D64
sub_8037D64:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r4, 0
	ldr r0, _08037D80
	str r4, [r0]
	bl sub_800D494
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8037C44
	b _08037D96
	.align 2, 0
_08037D80: .4byte gUnknown_202EC48
_08037D84:
	subs r0, r4, 0x3
	cmp r0, 0x2
	bls _08037DBC
	ldr r1, _08037DB8
	ldr r0, [r1]
	cmp r0, 0x63
	bgt _08037DC8
	adds r0, 0x1
	str r0, [r1]
_08037D96:
	bl sub_80373C4
	bl sub_800D33C
	adds r4, r0, 0
	bl sub_800D570
	cmp r4, 0x2
	bne _08037D84
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08037DD4
	movs r4, 0
	b _08037DDE
	.align 2, 0
_08037DB8: .4byte gUnknown_202EC48
_08037DBC:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08037DEA
_08037DC8:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08037DEA
_08037DD4:
	bl sub_800D520
	bl sub_800D510
	movs r4, 0x5
_08037DDE:
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8037CC4
	adds r0, r4, 0
_08037DEA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8037D64

	thumb_func_start sub_8037DF0
sub_8037DF0:
	push {r4,lr}
	sub sp, 0x8
	movs r4, 0
	movs r0, 0
	mov r1, sp
	movs r2, 0x4
	bl sub_800D670
	add r1, sp, 0x4
	movs r0, 0x1
	movs r2, 0x4
	bl sub_800D670
	ldr r0, [sp]
	cmp r0, 0
	bne _08037E16
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _08037E2C
_08037E16:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037E24
	ldr r4, [sp, 0x4]
	b _08037E26
_08037E24:
	ldr r4, [sp]
_08037E26:
	cmp r4, 0
	bne _08037E2C
	movs r4, 0xE
_08037E2C:
	adds r0, r4, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8037DF0

	thumb_func_start sub_8037E38
sub_8037E38:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r4, r6, 0
	cmp r0, 0
	bne _08037E4C
	adds r4, r5, 0
_08037E4C:
	bl sub_800D588
	lsls r0, 24
	adds r3, r5, 0
	cmp r0, 0
	bne _08037E5A
	adds r3, r6, 0
_08037E5A:
	ldrb r0, [r4]
	ldrb r1, [r3]
	cmp r0, r1
	bne _08037E70
	ldr r0, _08037E6C
	ldr r1, [r0]
	ldrb r0, [r4]
	b _08037E76
	.align 2, 0
_08037E6C: .4byte gUnknown_203B460
_08037E70:
	ldr r0, _08037E8C
	ldr r1, [r0]
	ldrb r0, [r3]
_08037E76:
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [r3, 0x4]
	adds r2, r0
	strh r2, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037E8C: .4byte gUnknown_203B460
	thumb_func_end sub_8037E38

	thumb_func_start sub_8037E90
sub_8037E90:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037EA2
	adds r4, r5, 0
_08037EA2:
	movs r0, 0x2
	strb r0, [r4]
	adds r0, r4, 0
	bl sub_80951BC
	ldr r0, [r4, 0x10]
	bl sub_8095274
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8037E90

	thumb_func_start nullsub_53
nullsub_53:
	bx lr
	thumb_func_end nullsub_53

	thumb_func_start sub_8037EBC
sub_8037EBC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r5, r4, 0
	cmp r0, 0
	bne _08037ED0
	adds r5, r6, 0
_08037ED0:
	ldr r1, [r5, 0x10]
	movs r0, 0x1
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r4, r0, 0
	adds r1, r4, 0
	adds r0, r5, 0
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	movs r0, 0x5
	strb r0, [r4]
	adds r0, r4, 0
	bl sub_80951FC
	movs r0, 0x7
	strb r0, [r4]
	movs r0, 0x38
	ldrsh r6, [r5, r0]
	cmp r6, 0
	beq _08037F30
	ldr r4, _08037F2C
	ldr r0, [r4]
	ldr r1, [r5, 0x10]
	stm r0!, {r1}
	adds r1, r5, 0
	adds r1, 0x30
	movs r2, 0x58
	bl memcpy
	ldr r1, [r4]
	movs r0, 0x42
	strb r0, [r1, 0x8]
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	b _08037F40
	.align 2, 0
_08037F2C: .4byte gUnknown_203B484
_08037F30:
	ldr r4, _08037F48
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	ldr r0, [r4]
	strh r6, [r0, 0xC]
_08037F40:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037F48: .4byte gUnknown_203B484
	thumb_func_end sub_8037EBC

	thumb_func_start sub_8037F4C
sub_8037F4C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037F5E
	adds r4, r5, 0
_08037F5E:
	ldr r1, [r4, 0x10]
	movs r0, 0x4
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	adds r1, r4, 0
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	movs r1, 0x6
	strb r1, [r0]
	bl sub_8035D4C
	cmp r0, 0
	beq _08037F96
	adds r1, r0, 0
	adds r1, 0x3A
	movs r0, 0x1
	strb r0, [r1]
_08037F96:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8037F4C

	thumb_func_start sub_8037F9C
sub_8037F9C:
	push {lr}
	adds r3, r1, 0
	cmp r0, 0xA
	bhi _08038010
	lsls r0, 2
	ldr r1, _08037FB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037FB0: .4byte _08037FB4
	.align 2, 0
_08037FB4:
	.4byte _08037FE0
	.4byte _08037FE0
	.4byte _08038010
	.4byte _08037FF4
	.4byte _08038010
	.4byte _08037FFE
	.4byte _08038010
	.4byte _08037FEA
	.4byte _08038010
	.4byte _08038010
	.4byte _08038008
_08037FE0:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037E38
	b _08038010
_08037FEA:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037F4C
	b _08038010
_08037FF4:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037E90
	b _08038010
_08037FFE:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037EBC
	b _08038010
_08038008:
	adds r0, r3, 0
	adds r1, r2, 0
	bl nullsub_53
_08038010:
	pop {r0}
	bx r0
	thumb_func_end sub_8037F9C

	thumb_func_start sub_8038014
sub_8038014:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r4, r6, 0
	cmp r0, 0
	bne _08038028
	adds r4, r5, 0
_08038028:
	bl sub_800D588
	lsls r0, 24
	adds r3, r5, 0
	cmp r0, 0
	bne _08038036
	adds r3, r6, 0
_08038036:
	ldrb r0, [r4]
	ldrb r1, [r3]
	cmp r0, r1
	bne _0803804C
	ldr r0, _08038048
	ldr r1, [r0]
	ldrb r0, [r4]
	b _08038052
	.align 2, 0
_08038048: .4byte gUnknown_203B460
_0803804C:
	ldr r0, _08038070
	ldr r1, [r0]
	ldrb r0, [r3]
_08038052:
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [r3, 0x4]
	adds r2, r0
	ldr r0, _08038074
	movs r1, 0
	cmp r2, r0
	ble _08038068
	movs r1, 0x6
_08038068:
	adds r0, r1, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08038070: .4byte gUnknown_203B460
_08038074: .4byte 0x000003e7
	thumb_func_end sub_8038014

	thumb_func_start sub_8038078
sub_8038078:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _0803808A
	adds r4, r5, 0
_0803808A:
	ldr r6, [r4, 0x10]
	ldr r0, _08038098
	ldr r0, [r0]
	cmp r0, 0
	beq _0803809C
	ldr r5, [r0, 0x50]
	b _080380A2
	.align 2, 0
_08038098: .4byte gUnknown_203B184
_0803809C:
	bl sub_8011C34
	adds r5, r0, 0
_080380A2:
	movs r0, 0x4
	adds r1, r6, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	beq _080380BA
	ldr r0, [r4, 0x28]
	cmp r0, r5
	bne _080380BA
	movs r0, 0
	b _080380BC
_080380BA:
	movs r0, 0xB
_080380BC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8038078

	thumb_func_start sub_80380C4
sub_80380C4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r5, r4, 0
	cmp r0, 0
	bne _080380D8
	adds r5, r6, 0
_080380D8:
	ldr r4, [r5, 0x10]
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038110
	movs r0, 0x4
	adds r1, r4, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038110
	movs r0, 0x6
	adds r1, r4, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038110
	ldr r0, [r5, 0x10]
	bl sub_8095298
	lsls r0, 24
	cmp r0, 0
	beq _08038114
_08038110:
	movs r0, 0x7
	b _08038126
_08038114:
	bl sub_8095190
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _08038124
	movs r0, 0
	b _08038126
_08038124:
	movs r0, 0xD
_08038126:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80380C4

	thumb_func_start sub_803812C
sub_803812C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _0803813E
	adds r4, r5, 0
_0803813E:
	ldr r1, [r4, 0x10]
	movs r0, 0x1
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038150
	movs r0, 0x9
	b _08038152
_08038150:
	movs r0, 0
_08038152:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803812C

	thumb_func_start sub_8038158
sub_8038158:
	movs r0, 0
	bx lr
	thumb_func_end sub_8038158

	thumb_func_start sub_803815C
sub_803815C:
	push {r4,lr}
	adds r3, r1, 0
	movs r4, 0
	cmp r0, 0xA
	bhi _080381D2
	lsls r0, 2
	ldr r1, _08038170
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038170: .4byte _08038174
	.align 2, 0
_08038174:
	.4byte _080381A0
	.4byte _080381A0
	.4byte _080381D2
	.4byte _080381B4
	.4byte _080381D2
	.4byte _080381BE
	.4byte _080381D2
	.4byte _080381AA
	.4byte _080381D2
	.4byte _080381D2
	.4byte _080381C8
_080381A0:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8038014
	b _080381D0
_080381AA:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8038078
	b _080381D0
_080381B4:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_80380C4
	b _080381D0
_080381BE:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_803812C
	b _080381D0
_080381C8:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8038158
_080381D0:
	adds r4, r0, 0
_080381D2:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_803815C

	thumb_func_start sub_80381DC
sub_80381DC:
	push {lr}
	bl sub_8037F9C
	pop {r0}
	bx r0
	thumb_func_end sub_80381DC

	thumb_func_start sub_80381E8
sub_80381E8:
	push {lr}
	bl sub_803815C
	pop {r1}
	bx r1
	thumb_func_end sub_80381E8

	thumb_func_start sub_80381F4
sub_80381F4:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r4, 0
	bl sub_803815C
	str r0, [sp]
	ldr r0, _08038218
	str r4, [r0]
	bl sub_800D494
	mov r0, sp
	movs r1, 0x4
	bl sub_800D59C
	b _0803822E
	.align 2, 0
_08038218: .4byte gUnknown_202EC4C
_0803821C:
	subs r0, r4, 0x3
	cmp r0, 0x2
	bls _08038272
	ldr r1, _08038250
	ldr r0, [r1]
	cmp r0, 0x63
	bgt _0803827E
	adds r0, 0x1
	str r0, [r1]
_0803822E:
	bl sub_80373C4
	bl sub_800D33C
	adds r4, r0, 0
	bl sub_800D570
	cmp r4, 0x2
	bne _0803821C
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08038254
	bl sub_8037DF0
	b _0803825E
	.align 2, 0
_08038250: .4byte gUnknown_202EC4C
_08038254:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x5
_0803825E:
	str r0, [sp]
	ldr r0, [sp]
	cmp r0, 0
	bne _0803828A
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8037F9C
	b _08038292
_08038272:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08038298
_0803827E:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08038298
_0803828A:
	bl sub_800D520
	bl sub_800D510
_08038292:
	bl sub_800D520
	ldr r0, [sp]
_08038298:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80381F4

	thumb_func_start sub_80382A0
sub_80382A0:
	push {lr}
	movs r0, 0
	bl sub_8031F60
	pop {r0}
	bx r0
	thumb_func_end sub_80382A0

	thumb_func_start sub_80382AC
sub_80382AC:
	push {lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	thumb_func_end sub_80382AC

	thumb_func_start sub_80382C0
sub_80382C0:
	push {r4,lr}
	ldr r4, _080382E0
	movs r0, 0x1
	bl sub_8031FD8
	cmp r0, 0x1
	bls _080382D8
	cmp r0, 0x3
	bhi _080382D8
	bl sub_803203C
	movs r4, 0x1
_080382D8:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080382E0: .4byte 0x0000ffdc
	thumb_func_end sub_80382C0

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

	thumb_func_start sub_803850C
sub_803850C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	ldr r5, _0803859C
	ldr r0, [r5]
	cmp r0, 0
	bne _08038536
	movs r4, 0xDA
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08038536:
	mov r12, r5
	movs r0, 0xA4
	lsls r0, 1
	mov r9, r0
	ldr r4, _080385A0
	movs r3, 0
	movs r2, 0x3
_08038544:
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
	bge _08038544
	bl ResetUnusedInputStruct
	ldr r4, _0803859C
	ldr r0, [r4]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	mov r7, r8
	cmp r7, 0x2E
	bne _080385AC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	adds r1, r6
	ldr r3, _080385A4
	ldr r2, _080385A8
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _080385CE
	.align 2, 0
_0803859C: .4byte gUnknown_203B364
_080385A0: .4byte gUnknown_80E6F20
_080385A4: .4byte gUnknown_80E6F38
_080385A8: .4byte gUnknown_80E7090
_080385AC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _080385F8
	ldr r2, _080385FC
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_080385CE:
	ldr r4, _08038600
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x4]
	mov r5, r8
	str r5, [r1]
	bl sub_8038830
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080385F8: .4byte gUnknown_80E6F38
_080385FC: .4byte gUnknown_80E6F50
_08038600: .4byte gUnknown_203B364
	thumb_func_end sub_803850C

	thumb_func_start sub_8038604
sub_8038604:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0803862C
	ldr r0, [r4]
	cmp r0, 0
	beq _08038624
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08038624:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803862C: .4byte gUnknown_203B364
	thumb_func_end sub_8038604

	thumb_func_start sub_8038630
sub_8038630:
	push {r4-r6,lr}
	sub sp, 0x18
	ldr r5, _080386A8
	movs r0, 0x3
	str r0, [sp, 0x14]
	ldr r6, _080386AC
	ldr r0, [r6]
	ldr r4, [r0, 0x4]
	cmp r4, 0x1
	bne _08038646
	b _08038798
_08038646:
	cmp r4, 0x1
	bcc _0803864C
	b _08038824
_0803864C:
	adds r0, 0x8
	bl sub_8012FD8
	movs r5, 0
	str r5, [sp, 0x10]
	bl sub_80140F8
	bl sub_8011C1C
	adds r1, r0, 0
	add r0, sp, 0x10
	bl sub_801203C
	adds r4, r0, 0
	bl sub_8014114
	cmp r4, 0
	beq _080386B8
	cmp r4, 0x1
	beq _08038738
	ldr r0, [r6]
	movs r4, 0xA4
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	bl sub_8035CC0
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x2E
	bne _08038750
	adds r0, r1, 0
	adds r0, 0x8
	adds r1, r4
	ldr r3, _080386B0
	ldr r2, _080386B4
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _0803876E
	.align 2, 0
_080386A8: .4byte 0x0000ffdc
_080386AC: .4byte gUnknown_203B364
_080386B0: .4byte gUnknown_80E6F38
_080386B4: .4byte gUnknown_80E7114
_080386B8:
	ldr r0, [r6]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x2E
	bne _080386F8
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _080386F0
	ldr r2, _080386F4
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08038716
	.align 2, 0
_080386F0: .4byte gUnknown_80E6F38
_080386F4: .4byte gUnknown_80E70CC
_080386F8:
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038728
	ldr r2, _0803872C
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08038716:
	ldr r4, _08038730
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2D
	bne _08038734
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r0, 0x13
	b _08038826
	.align 2, 0
_08038728: .4byte gUnknown_80E6F38
_0803872C: .4byte gUnknown_80E6FBC
_08038730: .4byte gUnknown_203B364
_08038734:
	adds r0, r1, 0
	b _08038772
_08038738:
	ldr r0, _0803874C
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	ldr r1, [r6]
	movs r0, 0x5
	b _08038780
	.align 2, 0
_0803874C: .4byte gUnknown_80E7178
_08038750:
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038788
	ldr r2, _0803878C
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_0803876E:
	ldr r4, _08038790
	ldr r0, [r4]
_08038772:
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r4]
	movs r0, 0x1
_08038780:
	str r0, [r1, 0x4]
	ldr r5, _08038794
	b _08038824
	.align 2, 0
_08038788: .4byte gUnknown_80E6F38
_0803878C: .4byte gUnknown_80E701C
_08038790: .4byte gUnknown_203B364
_08038794: .4byte 0x0000ffdc
_08038798:
	adds r0, 0x8
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _080387AE
	ldr r0, [r6]
	adds r0, 0x8
	add r1, sp, 0x14
	bl sub_8013114
_080387AE:
	ldr r0, [sp, 0x14]
	cmp r0, 0x3
	beq _0803881C
	cmp r0, 0x3
	bhi _080387BE
	cmp r0, 0x2
	beq _080387C2
	b _08038820
_080387BE:
	cmp r0, 0x4
	bne _08038820
_080387C2:
	ldr r4, _080387D8
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x29
	beq _080387D0
	cmp r0, 0x2E
	bne _080387DC
_080387D0:
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x1
	b _08038820
	.align 2, 0
_080387D8: .4byte gUnknown_203B364
_080387DC:
	cmp r0, 0x2D
	bne _080387E8
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x13
	b _08038820
_080387E8:
	cmp r0, 0x2C
	bne _080387F4
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x1F
	b _08038820
_080387F4:
	bl sub_8035D4C
	adds r0, 0x3A
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803880A
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x35
	b _08038820
_0803880A:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x4]
	ldr r0, [r0]
	movs r5, 0xB
	cmp r0, 0x2B
	bne _08038820
	movs r5, 0xD
	b _08038820
_0803881C:
	ldr r0, [r6]
	str r4, [r0, 0x4]
_08038820:
	bl sub_80388C4
_08038824:
	adds r0, r5, 0
_08038826:
	add sp, 0x18
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8038630

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

	thumb_func_start sub_8038900
sub_8038900:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	ldr r5, _080389B8
	ldr r0, [r5]
	cmp r0, 0
	bne _0803892A
	movs r4, 0x85
	lsls r4, 2
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_0803892A:
	movs r0, 0x1B
	negs r0, r0
	adds r0, r6
	mov r8, r0
	mov r12, r5
	movs r1, 0xA4
	lsls r1, 1
	mov r9, r1
	ldr r4, _080389BC
	mov r10, r4
	movs r3, 0
	movs r2, 0x3
_08038942:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	mov r0, r10
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08038942
	bl ResetUnusedInputStruct
	ldr r4, _080389B8
	ldr r0, [r4]
	movs r7, 0xA4
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r2, _080389C0
	ldrb r0, [r2]
	cmp r0, 0
	bne _08038986
	ldr r0, _080389C4
	ldr r1, [r0]
	adds r7, r4, 0
	adds r5, r0, 0
	cmp r1, r6
	beq _080389A0
_08038986:
	adds r7, r4, 0
	adds r3, r2, 0
	ldr r5, _080389C4
	ldr r1, _080389C8
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x35
_08038994:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08038994
	movs r0, 0
	strb r0, [r3]
_080389A0:
	ldr r0, [r7]
	str r6, [r0]
	str r6, [r5]
	mov r0, r8
	cmp r0, 0x7
	bhi _08038A36
	lsls r0, 2
	ldr r1, _080389CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080389B8: .4byte gUnknown_203B370
_080389BC: .4byte gUnknown_80E71E4
_080389C0: .4byte gUnknown_203B368
_080389C4: .4byte gUnknown_203B36C
_080389C8: .4byte gUnknown_202EC50
_080389CC: .4byte _080389D0
	.align 2, 0
_080389D0:
	.4byte _080389F0
	.4byte _080389FC
	.4byte _080389F0
	.4byte _080389FC
	.4byte _080389F0
	.4byte _080389FC
	.4byte _08038A0C
	.4byte _08038A2E
_080389F0:
	bl sub_8035D74
	movs r1, 0
	bl sub_8031D70
	b _08038A36
_080389FC:
	ldr r1, _08038A08
	movs r0, 0x4
	bl sub_80151C0
	b _08038A36
	.align 2, 0
_08038A08: .4byte gUnknown_202EC50
_08038A0C:
	movs r0, 0x1F
	bl sub_8095228
	adds r4, r0, 0
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	movs r1, 0
	movs r0, 0x2
	strb r0, [r4]
	adds r4, 0x22
	strb r1, [r4]
	movs r0, 0x1F
	bl sub_8031D70
	b _08038A36
_08038A2E:
	ldr r1, _08038A54
	movs r0, 0x4
	bl sub_80151C0
_08038A36:
	adds r0, r6, 0
	bl sub_8039000
	ldr r1, _08038A58
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_8039174
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038A54: .4byte gUnknown_202EC50
_08038A58: .4byte gUnknown_203B370
	thumb_func_end sub_8038900

	thumb_func_start sub_8038A5C
sub_8038A5C:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08038A8C
	ldr r0, [r4]
	cmp r0, 0
	beq _08038A86
	bl sub_80155F0
	bl sub_8031E10
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08038A86:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038A8C: .4byte gUnknown_203B370
	thumb_func_end sub_8038A5C

	thumb_func_start sub_8038A90
sub_8038A90:
	push {r4-r6,lr}
	sub sp, 0x34
	movs r0, 0xB
	str r0, [sp, 0x30]
	ldr r5, _08038AB4
	ldr r1, _08038AB8
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r6, r1, 0
	cmp r0, 0x9
	bls _08038AA8
	b _08038DB0
_08038AA8:
	lsls r0, 2
	ldr r1, _08038ABC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038AB4: .4byte 0x0000ffdc
_08038AB8: .4byte gUnknown_203B370
_08038ABC: .4byte _08038AC0
	.align 2, 0
_08038AC0:
	.4byte _08038AE8
	.4byte _08038AFC
	.4byte _08038AE8
	.4byte _08038AFC
	.4byte _08038AE8
	.4byte _08038AFC
	.4byte _08038C78
	.4byte _08038C8C
	.4byte _08038CC2
	.4byte _08038D38
_08038AE8:
	bl sub_8031DCC
	ldr r5, _08038AF8
	cmp r0, 0
	bne _08038AF4
	b _08038DB0
_08038AF4:
	movs r5, 0xB
	b _08038DB0
	.align 2, 0
_08038AF8: .4byte 0x0000ffdc
_08038AFC:
	bl sub_80154F0
	adds r4, r0, 0
	mov r0, sp
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x1
	bne _08038B12
	b _08038CBC
_08038B12:
	cmp r4, 0x1
	bcs _08038B18
	b _08038CB0
_08038B18:
	cmp r4, 0x2
	beq _08038AF4
	cmp r4, 0x3
	beq _08038B22
	b _08038DB0
_08038B22:
	ldr r0, _08038B44
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, _08038B48
	mov r2, sp
	bl sub_8039068
	subs r0, 0x7
	cmp r0, 0x11
	bls _08038B38
	b _08038DB0
_08038B38:
	lsls r0, 2
	ldr r1, _08038B4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038B44: .4byte gUnknown_203B370
_08038B48: .4byte gUnknown_202EC50
_08038B4C: .4byte _08038B50
	.align 2, 0
_08038B50:
	.4byte _08038BA4
	.4byte _08038DB0
	.4byte _08038BD8
	.4byte _08038DB0
	.4byte _08038C28
	.4byte _08038DB0
	.4byte _08038B9C
	.4byte _08038DB0
	.4byte _08038DB0
	.4byte _08038DB0
	.4byte _08038B98
	.4byte _08038BA0
	.4byte _08038BD4
	.4byte _08038C24
	.4byte _08038DB0
	.4byte _08038BA8
	.4byte _08038BDC
	.4byte _08038C2C
_08038B98:
	movs r0, 0x11
	b _08038CA4
_08038B9C:
	movs r0, 0xD
	b _08038CA4
_08038BA0:
	movs r0, 0x12
	b _08038CA4
_08038BA4:
	movs r0, 0x7
	b _08038CA4
_08038BA8:
	ldr r0, [sp, 0x10]
	bl sub_8095274
	bl sub_8038F98
	ldr r0, _08038BCC
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038BD0
	mov r1, sp
	movs r0, 0x2
	strb r0, [r1]
	mov r0, sp
	bl sub_80951BC
	b _08038DB0
	.align 2, 0
_08038BCC: .4byte gUnknown_203B370
_08038BD0: .4byte 0x0000ffdc
_08038BD4:
	movs r0, 0x13
	b _08038CA4
_08038BD8:
	movs r0, 0x9
	b _08038CA4
_08038BDC:
	bl sub_8038F98
	ldr r0, _08038C18
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038C1C
	mov r1, sp
	movs r0, 0x5
	strb r0, [r1]
	mov r0, sp
	bl sub_80951FC
	ldr r1, [sp, 0x10]
	movs r0, 0x1
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	movs r1, 0x7
	strb r1, [r0]
	ldr r0, _08038C20
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	b _08038DB0
	.align 2, 0
_08038C18: .4byte gUnknown_203B370
_08038C1C: .4byte 0x0000ffdc
_08038C20: .4byte gUnknown_203B484
_08038C24:
	movs r0, 0x14
	b _08038CA4
_08038C28:
	movs r0, 0xB
	b _08038CA4
_08038C2C:
	bl sub_8038F98
	ldr r0, _08038C70
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038C74
	ldr r1, [sp, 0x10]
	movs r0, 0x4
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	mov r1, sp
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	movs r1, 0x6
	strb r1, [r0]
	bl sub_8035D4C
	adds r0, 0x3A
	movs r1, 0x1
	strb r1, [r0]
	b _08038DB0
	.align 2, 0
_08038C70: .4byte gUnknown_203B370
_08038C74: .4byte 0x0000ffdc
_08038C78:
	bl sub_8031DCC
	ldr r5, _08038C88
	cmp r0, 0
	bne _08038C84
	b _08038DB0
_08038C84:
	movs r5, 0xD
	b _08038DB0
	.align 2, 0
_08038C88: .4byte 0x0000ffdc
_08038C8C:
	bl sub_80154F0
	cmp r0, 0x1
	beq _08038CBC
	cmp r0, 0x1
	bcc _08038CB0
	cmp r0, 0x2
	beq _08038C84
	cmp r0, 0x3
	beq _08038CA2
	b _08038DB0
_08038CA2:
	movs r0, 0x15
_08038CA4:
	bl sub_8038DC0
	ldr r0, _08038CB4
	ldr r1, [r0]
	movs r0, 0x8
	str r0, [r1, 0x4]
_08038CB0:
	ldr r5, _08038CB8
	b _08038DB0
	.align 2, 0
_08038CB4: .4byte gUnknown_203B370
_08038CB8: .4byte 0x0000ffdc
_08038CBC:
	bl sub_8031E00
	b _08038CB0
_08038CC2:
	ldr r0, [r6]
	adds r0, 0x8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08038CDA
	ldr r0, [r6]
	adds r0, 0x8
	add r1, sp, 0x30
	bl sub_8013114
_08038CDA:
	ldr r0, [sp, 0x30]
	cmp r0, 0xB
	beq _08038D24
	cmp r0, 0xB
	bhi _08038CEA
	cmp r0, 0xA
	beq _08038CEE
	b _08038DB0
_08038CEA:
	cmp r0, 0xC
	bne _08038DB0
_08038CEE:
	bl sub_8039174
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, _08038D1C
	movs r0, 0x4
	bl sub_80151C0
	ldr r0, _08038D20
	ldr r1, [r0]
	movs r0, 0x8
	str r0, [r1, 0x4]
	ldr r0, [r1]
	subs r0, 0x21
	movs r5, 0xB
	cmp r0, 0x1
	bhi _08038DB0
	b _08038C84
	.align 2, 0
_08038D1C: .4byte gUnknown_202EC50
_08038D20: .4byte gUnknown_203B370
_08038D24:
	ldr r1, [r6]
	movs r0, 0x8
	str r0, [r1, 0x4]
	ldr r5, _08038D34
	bl sub_80391F8
	b _08038DB0
	.align 2, 0
_08038D34: .4byte 0x0000ffdc
_08038D38:
	adds r4, r6, 0
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08038D52
	ldr r0, [r4]
	adds r0, 0x8
	add r1, sp, 0x30
	bl sub_8013114
_08038D52:
	ldr r0, [sp, 0x30]
	cmp r0, 0xB
	beq _08038DA4
	cmp r0, 0xB
	bhi _08038D62
	cmp r0, 0xA
	beq _08038D66
	b _08038DB0
_08038D62:
	cmp r0, 0xC
	bne _08038DB0
_08038D66:
	bl sub_8039174
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, _08038D9C
	movs r0, 0x4
	bl sub_80151C0
	ldr r4, _08038DA0
	ldr r0, [r4]
	ldr r0, [r0]
	bl sub_8039000
	ldr r1, [r4]
	str r0, [r1, 0x4]
	ldr r0, [r1]
	subs r0, 0x21
	movs r5, 0x2A
	cmp r0, 0x1
	bhi _08038DB0
	movs r5, 0x2B
	b _08038DB0
	.align 2, 0
_08038D9C: .4byte gUnknown_202EC50
_08038DA0: .4byte gUnknown_203B370
_08038DA4:
	ldr r1, [r6]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038DBC
	bl sub_80391F8
_08038DB0:
	adds r0, r5, 0
	add sp, 0x34
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08038DBC: .4byte 0x0000ffdc
	thumb_func_end sub_8038A90

	thumb_func_start sub_8038DC0
sub_8038DC0:
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r0, _08038DF8
	ldr r0, [r0]
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_80155F0
	subs r0, r4, 0x7
	cmp r0, 0xE
	bls _08038DEE
	b _08038F74
_08038DEE:
	lsls r0, 2
	ldr r1, _08038DFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038DF8: .4byte gUnknown_203B370
_08038DFC: .4byte _08038E00
	.align 2, 0
_08038E00:
	.4byte _08038E7C
	.4byte _08038F74
	.4byte _08038EDC
	.4byte _08038F74
	.4byte _08038F1C
	.4byte _08038F74
	.4byte _08038E9C
	.4byte _08038F74
	.4byte _08038F74
	.4byte _08038F74
	.4byte _08038E3C
	.4byte _08038E5C
	.4byte _08038EBC
	.4byte _08038EFC
	.4byte _08038F50
_08038E3C:
	ldr r0, _08038E50
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038E54
	ldr r2, _08038E58
	b _08038F2E
	.align 2, 0
_08038E50: .4byte gUnknown_203B370
_08038E54: .4byte gUnknown_80E71FC
_08038E58: .4byte gUnknown_80E7214
_08038E5C:
	ldr r0, _08038E70
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038E74
	ldr r2, _08038E78
	b _08038F2E
	.align 2, 0
_08038E70: .4byte gUnknown_203B370
_08038E74: .4byte gUnknown_80E72EC
_08038E78: .4byte gUnknown_80E7304
_08038E7C:
	ldr r0, _08038E90
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038E94
	ldr r2, _08038E98
	b _08038F2E
	.align 2, 0
_08038E90: .4byte gUnknown_203B370
_08038E94: .4byte gUnknown_80E7344
_08038E98: .4byte gUnknown_80E735C
_08038E9C:
	ldr r0, _08038EB0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038EB4
	ldr r2, _08038EB8
	b _08038F2E
	.align 2, 0
_08038EB0: .4byte gUnknown_203B370
_08038EB4: .4byte gUnknown_80E7588
_08038EB8: .4byte gUnknown_80E75A0
_08038EBC:
	ldr r0, _08038ED0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038ED4
	ldr r2, _08038ED8
	b _08038F2E
	.align 2, 0
_08038ED0: .4byte gUnknown_203B370
_08038ED4: .4byte gUnknown_80E73AC
_08038ED8: .4byte gUnknown_80E73C4
_08038EDC:
	ldr r0, _08038EF0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038EF4
	ldr r2, _08038EF8
	b _08038F2E
	.align 2, 0
_08038EF0: .4byte gUnknown_203B370
_08038EF4: .4byte gUnknown_80E7408
_08038EF8: .4byte gUnknown_80E7420
_08038EFC:
	ldr r0, _08038F10
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038F14
	ldr r2, _08038F18
	b _08038F2E
	.align 2, 0
_08038F10: .4byte gUnknown_203B370
_08038F14: .4byte gUnknown_80E7468
_08038F18: .4byte gUnknown_80E7480
_08038F1C:
	ldr r0, _08038F44
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038F48
	ldr r2, _08038F4C
_08038F2E:
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08038F74
	.align 2, 0
_08038F44: .4byte gUnknown_203B370
_08038F48: .4byte gUnknown_80E74C8
_08038F4C: .4byte gUnknown_80E74E0
_08038F50:
	ldr r0, _08038F8C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038F90
	ldr r2, _08038F94
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08038F74:
	ldr r0, _08038F8C
	ldr r0, [r0]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038F8C: .4byte gUnknown_203B370
_08038F90: .4byte gUnknown_80E752C
_08038F94: .4byte gUnknown_80E7544
	thumb_func_end sub_8038DC0

	thumb_func_start sub_8038F98
sub_8038F98:
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r5, _08038FF4
	ldr r0, [r5]
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_80155F0
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038FF8
	ldr r2, _08038FFC
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r0, [r5]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038FF4: .4byte gUnknown_203B370
_08038FF8: .4byte gUnknown_80E7278
_08038FFC: .4byte gUnknown_80E7290
	thumb_func_end sub_8038F98

	thumb_func_start sub_8039000
sub_8039000:
	push {lr}
	movs r1, 0xB
	ldr r0, _0803901C
	ldr r0, [r0]
	ldr r0, [r0]
	subs r0, 0x1B
	cmp r0, 0x7
	bhi _08039062
	lsls r0, 2
	ldr r1, _08039020
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803901C: .4byte gUnknown_203B370
_08039020: .4byte _08039024
	.align 2, 0
_08039024:
	.4byte _08039044
	.4byte _08039054
	.4byte _0803904C
	.4byte _0803905C
	.4byte _08039048
	.4byte _08039058
	.4byte _08039050
	.4byte _08039060
_08039044:
	movs r1, 0
	b _08039062
_08039048:
	movs r1, 0x4
	b _08039062
_0803904C:
	movs r1, 0x2
	b _08039062
_08039050:
	movs r1, 0x6
	b _08039062
_08039054:
	movs r1, 0x1
	b _08039062
_08039058:
	movs r1, 0x5
	b _08039062
_0803905C:
	movs r1, 0x3
	b _08039062
_08039060:
	movs r1, 0x7
_08039062:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8039000

	thumb_func_start sub_8039068
sub_8039068:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r0, r1, 0
	adds r5, r2, 0
	adds r1, r5, 0
	bl sub_803D204
	lsls r0, 24
	cmp r0, 0
	beq _080390AC
	ldrb r0, [r5]
	cmp r0, 0x7
	bhi _080390AC
	ldrb r4, [r5, 0x5]
	ldrb r0, [r5, 0x4]
	bl sub_8090298
	cmp r4, r0
	bge _080390AC
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	cmp r1, 0
	beq _080390AC
	ldr r0, _080390B0
	cmp r1, r0
	bgt _080390AC
	adds r0, r5, 0
	adds r0, 0x22
	ldrb r0, [r0]
	bl sub_8092040
	lsls r0, 24
	cmp r0, 0
	beq _080390B4
_080390AC:
	movs r0, 0x11
	b _0803916E
	.align 2, 0
_080390B0: .4byte 0x000001a7
_080390B4:
	cmp r6, 0x1E
	beq _08039120
	cmp r6, 0x1E
	bhi _080390C2
	cmp r6, 0x1C
	beq _080390C8
	b _0803916A
_080390C2:
	cmp r6, 0x20
	beq _08039140
	b _0803916A
_080390C8:
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _080390D2
	movs r0, 0x12
	b _0803916E
_080390D2:
	ldr r1, [r5, 0x10]
	movs r0, 0x2
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08039108
	ldr r1, [r5, 0x10]
	movs r0, 0x4
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08039108
	ldr r1, [r5, 0x10]
	movs r0, 0x6
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08039108
	ldr r0, [r5, 0x10]
	bl sub_8095298
	lsls r0, 24
	cmp r0, 0
	beq _0803910C
_08039108:
	movs r0, 0x7
	b _0803916E
_0803910C:
	bl sub_8095190
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803911C
	movs r0, 0xD
	b _0803916E
_0803911C:
	movs r0, 0x16
	b _0803916E
_08039120:
	ldrb r0, [r5]
	cmp r0, 0x4
	beq _0803912A
	movs r0, 0x13
	b _0803916E
_0803912A:
	ldr r1, [r5, 0x10]
	movs r0, 0x1
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _0803913C
	movs r0, 0x9
	b _0803916E
_0803913C:
	movs r0, 0x17
	b _0803916E
_08039140:
	ldrb r0, [r5]
	cmp r0, 0x5
	beq _0803914A
	movs r0, 0x14
	b _0803916E
_0803914A:
	ldr r1, [r5, 0x10]
	movs r0, 0x4
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	beq _08039162
	bl sub_8011C34
	ldr r1, [r5, 0x28]
	cmp r1, r0
	beq _08039166
_08039162:
	movs r0, 0xB
	b _0803916E
_08039166:
	movs r0, 0x18
	b _0803916E
_0803916A:
	movs r0, 0x1
	negs r0, r0
_0803916E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8039068

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
_080391D8: .4byte gUnknown_203B370
_080391DC: .4byte 0x0000feff
_080391E0: .4byte 0x0000fdff
_080391E4: .4byte 0x0000f3ff
_080391E8: .4byte 0x0000efff
_080391EC: .4byte 0x0000dfff
_080391F0: .4byte 0x00003fff
_080391F4: .4byte 0x00000fff
	thumb_func_end sub_8039174

	thumb_func_start sub_80391F8
sub_80391F8:
	push {r4-r6,lr}
	ldr r6, _08039250
	ldr r2, [r6]
	movs r0, 0x82
	lsls r0, 2
	adds r4, r2, r0
	ldrh r1, [r4, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r1
	movs r1, 0x70
	orrs r0, r1
	strh r0, [r4, 0x2]
	movs r3, 0xE0
	lsls r3, 3
	ldrh r1, [r4, 0x6]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r3
	strh r0, [r4, 0x6]
	movs r5, 0x84
	lsls r5, 2
	adds r2, r5
	ldr r0, [r2]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0803923C
	adds r1, 0xF8
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0803923C:
	bl xxx_draw_string_80144C4
	ldr r1, [r6]
	adds r1, r5
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08039250: .4byte gUnknown_203B370
	thumb_func_end sub_80391F8

	thumb_func_start sub_8039254
sub_8039254:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r5, _080392EC
	ldr r0, [r5]
	cmp r0, 0
	bne _0803927C
	movs r4, 0x9F
	lsls r4, 2
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_0803927C:
	ldr r0, [r5]
	str r6, [r0]
	mov r12, r5
	movs r0, 0xA2
	lsls r0, 1
	mov r8, r0
	ldr r4, _080392F0
	movs r3, 0
	movs r2, 0x3
_0803928E:
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
	bge _0803928E
	bl ResetUnusedInputStruct
	ldr r6, _080392EC
	ldr r0, [r6]
	movs r5, 0xA2
	lsls r5, 1
	adds r0, r5
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _080392F4
	ldr r2, _080392F8
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r7, 0x6
	str r7, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x7
	beq _08039306
	cmp r0, 0x7
	bhi _080392FC
	cmp r0, 0x6
	beq _08039338
	b _08039382
	.align 2, 0
_080392EC: .4byte gUnknown_203B374
_080392F0: .4byte gUnknown_80E75F8
_080392F4: .4byte gUnknown_80E7610
_080392F8: .4byte gUnknown_203B378
_080392FC:
	cmp r0, 0x8
	beq _0803934C
	cmp r0, 0x9
	beq _0803936C
	b _08039382
_08039306:
	bl sub_8039844
	lsls r0, 24
	cmp r0, 0
	beq _08039324
	ldr r1, [r6]
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _0803931C
	ldr r2, _08039320
	b _08039354
	.align 2, 0
_0803931C: .4byte gUnknown_80E762C
_08039320: .4byte gUnknown_80E7644
_08039324:
	ldr r1, [r6]
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _08039330
	ldr r2, _08039334
	b _08039354
	.align 2, 0
_08039330: .4byte gUnknown_80E762C
_08039334: .4byte gUnknown_80E7684
_08039338:
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _08039344
	ldr r2, _08039348
	b _08039354
	.align 2, 0
_08039344: .4byte gUnknown_80E762C
_08039348: .4byte gUnknown_80E76B8
_0803934C:
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _08039364
	ldr r2, _08039368
_08039354:
	str r2, [sp]
	str r4, [sp, 0x4]
	str r7, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0x1
	bl SetMenuItems
	b _08039382
	.align 2, 0
_08039364: .4byte gUnknown_80E762C
_08039368: .4byte gUnknown_80E76E8
_0803936C:
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _080393DC
	ldr r2, _080393E0
	str r2, [sp]
	str r4, [sp, 0x4]
	str r7, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0x1
	bl SetMenuItems
_08039382:
	ldr r4, _080393E4
	ldr r1, [r4]
	adds r0, r1, 0x4
	movs r6, 0xA2
	lsls r6, 1
	adds r1, r6
	ldr r3, _080393E8
	ldr r2, _080393EC
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0x2
	str r2, [sp, 0x8]
	movs r2, 0
	str r2, [sp, 0xC]
	movs r2, 0x2
	bl SetMenuItems
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x1
	movs r2, 0
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0x1
	bl sub_8035CF4
	bl sub_80394A4
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080393DC: .4byte gUnknown_80E762C
_080393E0: .4byte gUnknown_80E7730
_080393E4: .4byte gUnknown_203B374
_080393E8: .4byte gUnknown_80E7784
_080393EC: .4byte gUnknown_80E779C
	thumb_func_end sub_8039254

	thumb_func_start sub_80393F0
sub_80393F0:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08039418
	ldr r0, [r4]
	cmp r0, 0
	beq _08039410
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08039410:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039418: .4byte gUnknown_203B374
	thumb_func_end sub_80393F0

	thumb_func_start sub_803941C
sub_803941C:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _08039458
	movs r0, 0x4
	str r0, [sp]
	ldr r4, _0803945C
	ldr r0, [r4]
	adds r0, 0x54
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xA4
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08039448
	ldr r0, [r4]
	adds r0, 0xA4
	mov r1, sp
	bl sub_8013114
_08039448:
	ldr r0, [sp]
	cmp r0, 0x3
	bhi _08039498
	cmp r0, 0x2
	bcs _08039460
	cmp r0, 0x1
	beq _08039464
	b _08039498
	.align 2, 0
_08039458: .4byte 0x0000ffdc
_0803945C: .4byte gUnknown_203B374
_08039460:
	movs r5, 0x1
	b _08039498
_08039464:
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x7
	beq _08039480
	cmp r0, 0x7
	bhi _08039476
	cmp r0, 0x6
	beq _08039484
	b _08039498
_08039476:
	cmp r0, 0x8
	beq _0803948E
	cmp r0, 0x9
	beq _08039492
	b _08039498
_08039480:
	movs r5, 0x2
	b _08039498
_08039484:
	movs r0, 0
	bl sub_8095240
	movs r5, 0x4
	b _08039498
_0803948E:
	movs r5, 0x9
	b _08039498
_08039492:
	bl sub_80122A8
	movs r5, 0x2E
_08039498:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803941C

	thumb_func_start sub_80394A4
sub_80394A4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x150
	bl sub_8011FA8
	mov r8, r0
	movs r0, 0
	bl sub_8008C54
	movs r0, 0
	bl sub_80073B8
	ldr r2, _0803952C
	movs r4, 0
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039530
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0xC
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039534
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x18
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039538
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x24
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _0803953C
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x30
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039540
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x3C
	movs r3, 0
	bl xxx_call_draw_string
	movs r0, 0
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08039544
	add r4, sp, 0x68
	adds r0, r4, 0
	bl sub_80920D8
	adds r2, r4, 0
	b _0803954E
	.align 2, 0
_0803952C: .4byte gUnknown_80E77BC
_08039530: .4byte gUnknown_80E77C4
_08039534: .4byte gUnknown_80E77CC
_08039538: .4byte gUnknown_80E77D8
_0803953C: .4byte gUnknown_80E77E4
_08039540: .4byte gUnknown_80E77F0
_08039544:
	ldr r1, _08039588
	add r0, sp, 0x68
	bl strcpy
	add r2, sp, 0x68
_0803954E:
	ldr r5, _0803958C
	ldr r0, [r5]
	movs r4, 0xD2
	lsls r4, 1
	adds r0, r4
	ldr r1, _08039590
	bl sub_800D158
	ldr r2, [r5]
	adds r2, r4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x40
	movs r1, 0
	movs r3, 0
	bl xxx_call_draw_string
	bl sub_808D33C
	cmp r0, 0
	bne _08039598
	add r4, sp, 0x90
	ldr r1, _08039594
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	b _080395A6
	.align 2, 0
_08039588: .4byte gUnknown_80E77F8
_0803958C: .4byte gUnknown_203B374
_08039590: .4byte gUnknown_80E7804
_08039594: .4byte gUnknown_80E7808
_08039598:
	add r4, sp, 0x90
	adds r1, r0, 0
	adds r1, 0x4C
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
_080395A6:
	adds r2, r4, 0
	ldr r5, _080395F0
	ldr r0, [r5]
	movs r4, 0xE4
	lsls r4, 1
	adds r0, r4
	ldr r6, _080395F4
	adds r1, r6, 0
	bl sub_800D158
	ldr r2, [r5]
	adds r2, r4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x40
	movs r1, 0xC
	movs r3, 0
	bl xxx_call_draw_string
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _080395E0
	movs r0, 0x7
	bl sub_8095324
	cmp r0, 0
	beq _08039606
_080395E0:
	ldr r0, _080395F8
	cmp r8, r0
	bne _080395FC
	ldr r4, [r5]
	movs r0, 0xF6
	lsls r0, 1
	adds r4, r0
	b _08039676
	.align 2, 0
_080395F0: .4byte gUnknown_203B374
_080395F4: .4byte gUnknown_80E7804
_080395F8: .4byte 0x000f1207
_080395FC:
	ldr r0, [r5]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	b _08039690
_08039606:
	bl sub_8011C1C
	cmp r0, 0x1
	beq _08039624
	cmp r0, 0x2
	beq _08039668
	ldr r0, [r5]
	movs r2, 0xF6
	lsls r2, 1
	adds r0, r2
	ldr r1, _08039620
	b _08039692
	.align 2, 0
_08039620: .4byte gUnknown_80E7824
_08039624:
	movs r0, 0
	movs r1, 0x18
	bl sub_8001658
	cmp r0, 0x7
	beq _08039658
	cmp r0, 0xB
	beq _08039658
	bl sub_8098FB4
	adds r2, r0, 0
	add r0, sp, 0x4
	adds r1, r6, 0
	bl sub_800D158
	ldr r0, [r5]
	movs r3, 0xF6
	lsls r3, 1
	adds r1, r0, r3
	adds r3, 0x24
	adds r2, r0, r3
	add r0, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	b _08039696
_08039658:
	ldr r0, _08039664
	ldr r0, [r0]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	b _08039690
	.align 2, 0
_08039664: .4byte gUnknown_203B374
_08039668:
	ldr r0, _08039684
	cmp r8, r0
	bne _08039688
	ldr r4, [r5]
	movs r2, 0xF6
	lsls r2, 1
	adds r4, r2
_08039676:
	bl sub_809769C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8090228
	b _08039696
	.align 2, 0
_08039684: .4byte 0x000f1207
_08039688:
	ldr r0, [r5]
	movs r3, 0xF6
	lsls r3, 1
	adds r0, r3
_08039690:
	ldr r1, _0803974C
_08039692:
	bl sub_800D158
_08039696:
	ldr r7, _08039750
	ldr r2, [r7]
	movs r0, 0xF6
	lsls r0, 1
	adds r2, r0
	movs r6, 0
	str r6, [sp]
	movs r0, 0x40
	movs r1, 0x18
	movs r3, 0
	bl xxx_call_draw_string
	ldr r0, _08039754
	ldr r0, [r0]
	add r1, sp, 0x144
	add r2, sp, 0x148
	add r3, sp, 0x14C
	bl DeconstructPlayTime
	ldr r0, [r7]
	movs r5, 0x84
	lsls r5, 2
	adds r0, r5
	ldr r1, _08039758
	add r2, sp, 0x144
	ldr r2, [r2]
	add r3, sp, 0x148
	ldr r3, [r3]
	add r4, sp, 0x14C
	ldr r4, [r4]
	str r4, [sp]
	bl sub_800D158
	ldr r2, [r7]
	adds r2, r5
	str r6, [sp]
	movs r0, 0x40
	movs r1, 0x24
	movs r3, 0
	bl xxx_call_draw_string
	bl sub_8097778
	adds r2, r0, 0
	ldr r0, [r7]
	movs r4, 0x8D
	lsls r4, 2
	adds r0, r4
	ldr r1, _0803975C
	bl sub_800D158
	ldr r2, [r7]
	adds r2, r4
	str r6, [sp]
	movs r0, 0x40
	movs r1, 0x30
	movs r3, 0
	bl xxx_call_draw_string
	ldr r0, _08039760
	cmp r8, r0
	bne _0803976C
	ldr r0, _08039764
	ldr r6, [r0]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0803976C
	add r5, sp, 0x130
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_808D930
	add r4, sp, 0xE0
	adds r1, r6, 0
	adds r1, 0x50
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	ldr r0, [r7]
	movs r3, 0x96
	lsls r3, 2
	adds r0, r3
	ldr r1, _08039768
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_800D158
	b _0803977C
	.align 2, 0
_0803974C: .4byte gUnknown_80E780C
_08039750: .4byte gUnknown_203B374
_08039754: .4byte gUnknown_203B47C
_08039758: .4byte gUnknown_80E7838
_0803975C: .4byte gUnknown_80E7848
_08039760: .4byte 0x000f1207
_08039764: .4byte gUnknown_203B484
_08039768: .4byte gUnknown_80E784C
_0803976C:
	ldr r0, _080397AC
	ldr r0, [r0]
	movs r1, 0x96
	lsls r1, 2
	adds r0, r1
	ldr r1, _080397B0
	bl sub_800D158
_0803977C:
	ldr r0, _080397AC
	ldr r2, [r0]
	movs r3, 0x96
	lsls r3, 2
	adds r2, r3
	movs r0, 0
	str r0, [sp]
	movs r0, 0x40
	movs r1, 0x3C
	movs r3, 0
	bl xxx_call_draw_string
	bl sub_80397B4
	movs r0, 0
	bl sub_80073E0
	add sp, 0x150
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080397AC: .4byte gUnknown_203B374
_080397B0: .4byte gUnknown_80E7854
	thumb_func_end sub_80394A4

	thumb_func_start sub_80397B4
sub_80397B4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	ldr r0, _08039834
	ldr r1, _08039838
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	movs r4, 0
_080397C8:
	adds r0, r4, 0
	adds r0, 0xB0
	ldr r1, [r6, 0x4]
	lsls r2, r4, 2
	ldr r1, [r1, 0x4]
	adds r1, r2
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0x3F
	ble _080397C8
	movs r7, 0x8
	movs r0, 0x49
	mov r8, r0
	movs r4, 0
_080397E6:
	ldr r0, _0803983C
	lsls r5, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0803981C
	movs r0, 0x10
	str r0, [sp]
	ldr r0, [r6, 0x4]
	lsls r1, r4, 7
	ldr r0, [r0]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r0, _08039840
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0
	adds r1, r7, 0
	mov r2, r8
	movs r3, 0x10
	bl sub_8007E20
	adds r7, 0x10
_0803981C:
	adds r4, 0x1
	cmp r4, 0xB
	ble _080397E6
	adds r0, r6, 0
	bl CloseFile
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039834: .4byte gUnknown_80E785C
_08039838: .4byte gTitleMenuFileArchive
_0803983C: .4byte gUnknown_203B3B8
_08039840: .4byte gUnknown_203B388
	thumb_func_end sub_80397B4

	thumb_func_start sub_8039844
sub_8039844:
	push {r4,r5,lr}
	bl sub_8011FA8
	adds r5, r0, 0
	movs r4, 0
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _0803986A
	movs r0, 0x7
	bl sub_8095324
	cmp r0, 0
	bne _0803986A
	bl sub_8011C1C
	cmp r0, 0x2
	bne _08039872
_0803986A:
	ldr r0, _0803987C
	cmp r5, r0
	bne _08039872
	movs r4, 0x1
_08039872:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0803987C: .4byte 0x000f1207
	thumb_func_end sub_8039844

	thumb_func_start sub_8039880
sub_8039880:
	push {r4,lr}
	movs r4, 0
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _080398A0
	movs r0, 0x7
	bl sub_8095324
	cmp r0, 0
	bne _080398A0
	bl sub_8011C1C
	cmp r0, 0x2
	bne _080398A2
_080398A0:
	movs r4, 0x1
_080398A2:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8039880

	thumb_func_start sub_80398AC
sub_80398AC:
	push {r4,r5,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _0803991C
	ldr r4, _08039920
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
	movs r1, 0
	movs r2, 0
	adds r4, r5, 0
_080398D8:
	ldr r0, [r5]
	adds r0, 0x1
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, 0x35
	ble _080398D8
	ldr r1, [r4]
	movs r3, 0x92
	lsls r3, 3
	adds r2, r1, r3
	movs r0, 0x3
	str r0, [r2]
	ldr r0, _08039924
	adds r2, r1, r0
	movs r0, 0x2
	str r0, [r2]
	movs r0, 0x93
	lsls r0, 3
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r3
	movs r1, 0x5
	str r1, [r0]
	movs r0, 0x11
	bl sub_803A1C0
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0803991C: .4byte gUnknown_203B3E8
_08039920: .4byte 0x0000049c
_08039924: .4byte 0x00000494
	thumb_func_end sub_80398AC

	thumb_func_start sub_8039928
sub_8039928:
	push {lr}
	ldr r0, _08039940
	ldr r0, [r0]
	ldrb r0, [r0]
	subs r0, 0x4
	cmp r0, 0xF
	bhi _080399DE
	lsls r0, 2
	ldr r1, _08039944
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039940: .4byte gUnknown_203B3E8
_08039944: .4byte _08039948
	.align 2, 0
_08039948:
	.4byte _08039988
	.4byte _0803998E
	.4byte _0803999E
	.4byte _080399AA
	.4byte _08039992
	.4byte _080399A4
	.4byte _080399C8
	.4byte _080399DE
	.4byte _08039998
	.4byte _080399B0
	.4byte _080399B6
	.4byte _080399BC
	.4byte _080399C2
	.4byte _080399CE
	.4byte _080399D4
	.4byte _080399DA
_08039988:
	bl sub_8039A18
	b _080399DE
_0803998E:
	movs r0, 0x3
	b _080399E0
_08039992:
	bl sub_8039AA8
	b _080399DE
_08039998:
	bl sub_8039B14
	b _080399DE
_0803999E:
	bl sub_8039B20
	b _080399DE
_080399A4:
	bl sub_8039B58
	b _080399DE
_080399AA:
	bl sub_8039D88
	b _080399DE
_080399B0:
	bl sub_8039D28
	b _080399DE
_080399B6:
	bl sub_8039D68
	b _080399DE
_080399BC:
	bl sub_8039DA4
	b _080399DE
_080399C2:
	bl sub_8039DCC
	b _080399DE
_080399C8:
	bl sub_8039B3C
	b _080399DE
_080399CE:
	bl sub_8039D0C
	b _080399DE
_080399D4:
	bl sub_8039C60
	b _080399DE
_080399DA:
	bl sub_8039DE8
_080399DE:
	movs r0, 0
_080399E0:
	pop {r1}
	bx r1
	thumb_func_end sub_8039928

	thumb_func_start sub_80399E4
sub_80399E4:
	push {r4,lr}
	ldr r4, _08039A14
	ldr r0, [r4]
	cmp r0, 0
	beq _08039A0E
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	bl sub_8030DE4
	bl sub_801B450
	bl sub_803084C
	bl sub_801CBB8
	bl sub_80155F0
	bl sub_8031E10
_08039A0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039A14: .4byte gUnknown_203B3E8
	thumb_func_end sub_80399E4

	thumb_func_start sub_8039A18
sub_8039A18:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039AA2
	ldr r0, _08039A48
	ldr r1, [r0]
	movs r2, 0x93
	lsls r2, 2
	adds r1, r2
	movs r2, 0xA
	str r2, [r1]
	ldr r1, [sp]
	adds r2, r0, 0
	cmp r1, 0x8
	bhi _08039AA2
	lsls r0, r1, 2
	ldr r1, _08039A4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039A48: .4byte gUnknown_203B3E8
_08039A4C: .4byte _08039A50
	.align 2, 0
_08039A50:
	.4byte _08039A9C
	.4byte _08039AA2
	.4byte _08039AA2
	.4byte _08039A74
	.4byte _08039A74
	.4byte _08039A88
	.4byte _08039AA2
	.4byte _08039AA2
	.4byte _08039A9C
_08039A74:
	ldr r0, [r2]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	movs r1, 0x3
	str r1, [r0]
	movs r0, 0x8
	bl sub_803A1C0
	b _08039AA2
_08039A88:
	ldr r0, [r2]
	movs r2, 0x92
	lsls r2, 3
	adds r0, r2
	movs r1, 0x5
	str r1, [r0]
	movs r0, 0x11
	bl sub_803A1C0
	b _08039AA2
_08039A9C:
	movs r0, 0x5
	bl sub_803A1C0
_08039AA2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039A18

	thumb_func_start sub_8039AA8
sub_8039AA8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039B0E
	ldr r0, [sp]
	cmp r0, 0
	beq _08039AE8
	cmp r0, 0x6
	bne _08039B0E
	ldr r0, _08039AD8
	ldr r0, [r0]
	ldr r1, _08039ADC
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _08039AE0
	movs r0, 0x2
	bl sub_803A1C0
	b _08039B0E
	.align 2, 0
_08039AD8: .4byte gUnknown_203B3E8
_08039ADC: .4byte 0x00000494
_08039AE0:
	movs r0, 0xC
	bl sub_803A1C0
	b _08039B0E
_08039AE8:
	ldr r0, _08039B00
	ldr r0, [r0]
	ldr r1, _08039B04
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _08039B08
	movs r0, 0x1
	bl sub_803A1C0
	b _08039B0E
	.align 2, 0
_08039B00: .4byte gUnknown_203B3E8
_08039B04: .4byte 0x00000494
_08039B08:
	movs r0, 0x4
	bl sub_803A1C0
_08039B0E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039AA8

	thumb_func_start sub_8039B14
sub_8039B14:
	push {lr}
	movs r0, 0x6
	bl sub_803A1C0
	pop {r0}
	bx r0
	thumb_func_end sub_8039B14

	thumb_func_start sub_8039B20
sub_8039B20:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039B34
	movs r0, 0x9
	bl sub_803A1C0
_08039B34:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039B20

	thumb_func_start sub_8039B3C
sub_8039B3C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039B50
	movs r0, 0x4
	bl sub_803A1C0
_08039B50:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039B3C

	thumb_func_start sub_8039B58
sub_8039B58:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039BA6
	ldr r0, _08039B88
	ldr r1, [r0]
	movs r2, 0x94
	lsls r2, 2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _08039B9C
	subs r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0x9
	beq _08039B8C
	cmp r0, 0xA
	beq _08039B94
	b _08039BA6
	.align 2, 0
_08039B88: .4byte gUnknown_203B3E8
_08039B8C:
	movs r0, 0x7
	bl sub_803A1C0
	b _08039BA6
_08039B94:
	movs r0, 0xD
	bl sub_803A1C0
	b _08039BA6
_08039B9C:
	bl sub_8039BAC
	movs r0, 0xA
	bl sub_803A1C0
_08039BA6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039B58

	thumb_func_start sub_8039BAC
sub_8039BAC:
	push {lr}
	cmp r0, 0xF
	bhi _08039C48
	lsls r0, 2
	ldr r1, _08039BBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039BBC: .4byte _08039BC0
	.align 2, 0
_08039BC0:
	.4byte _08039C54
	.4byte _08039C00
	.4byte _08039C10
	.4byte _08039C08
	.4byte _08039C18
	.4byte _08039C20
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C48
	.4byte _08039C28
	.4byte _08039C30
_08039C00:
	ldr r0, _08039C04
	b _08039C32
	.align 2, 0
_08039C04: .4byte gUnknown_80E7914
_08039C08:
	ldr r0, _08039C0C
	b _08039C32
	.align 2, 0
_08039C0C: .4byte gUnknown_80E7938
_08039C10:
	ldr r0, _08039C14
	b _08039C32
	.align 2, 0
_08039C14: .4byte gUnknown_80E7994
_08039C18:
	ldr r0, _08039C1C
	b _08039C32
	.align 2, 0
_08039C1C: .4byte gUnknown_80E79E4
_08039C20:
	ldr r0, _08039C24
	b _08039C32
	.align 2, 0
_08039C24: .4byte gUnknown_80E7914
_08039C28:
	ldr r0, _08039C2C
	b _08039C32
	.align 2, 0
_08039C2C: .4byte gUnknown_80E7914
_08039C30:
	ldr r0, _08039C40
_08039C32:
	ldr r3, _08039C44
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08039C54
	.align 2, 0
_08039C40: .4byte gUnknown_80E7A48
_08039C44: .4byte 0x00000101
_08039C48:
	ldr r0, _08039C58
	ldr r3, _08039C5C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08039C54:
	pop {r0}
	bx r0
	.align 2, 0
_08039C58: .4byte gUnknown_80E7914
_08039C5C: .4byte 0x00000101
	thumb_func_end sub_8039BAC

	thumb_func_start sub_8039C60
sub_8039C60:
	push {r4,r5,lr}
	bl sub_80154F0
	adds r4, r0, 0
	ldr r5, _08039CBC
	ldr r0, [r5]
	adds r0, 0x38
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x2
	beq _08039CE6
	cmp r4, 0x3
	bne _08039D04
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	adds r0, r1, 0x1
	adds r1, 0x38
	bl sub_803D358
	lsls r0, 24
	cmp r0, 0
	beq _08039CB4
	ldr r0, [r5]
	adds r0, 0x38
	bl sub_80959C0
	lsls r0, 24
	cmp r0, 0
	bne _08039CC0
_08039CB4:
	movs r0, 0x13
	bl sub_803A1C0
	b _08039D04
	.align 2, 0
_08039CBC: .4byte gUnknown_203B3E8
_08039CC0:
	ldr r0, [r5]
	movs r2, 0xF0
	lsls r2, 2
	adds r1, r0, r2
	adds r0, 0x38
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r3,r4}
	stm r1!, {r3,r4}
	ldr r0, [r5]
	movs r1, 0x93
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0xD
	bl sub_803A1C0
	b _08039D04
_08039CE6:
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r2, 0xF6
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x5
	bl sub_803A1C0
_08039D04:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8039C60

	thumb_func_start sub_8039D0C
sub_8039D0C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039D20
	movs r0, 0x12
	bl sub_803A1C0
_08039D20:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039D0C

	thumb_func_start sub_8039D28
sub_8039D28:
	push {r4,r5,lr}
	bl sub_802D0E0
	cmp r0, 0x3
	bne _08039D62
	bl sub_802D178
	ldr r5, _08039D58
	ldr r1, [r5]
	movs r4, 0x93
	lsls r4, 3
	adds r1, r4
	strb r0, [r1]
	bl sub_802D184
	ldr r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08039D5C
	movs r0, 0xE
	bl sub_803A1C0
	b _08039D62
	.align 2, 0
_08039D58: .4byte gUnknown_203B3E8
_08039D5C:
	movs r0, 0x10
	bl sub_803A1C0
_08039D62:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8039D28

	thumb_func_start sub_8039D68
sub_8039D68:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039D82
	movs r0, 0xF
	bl sub_803A1C0
	movs r0, 0
	bl sub_8012574
_08039D82:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039D68

	thumb_func_start sub_8039D88
sub_8039D88:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039D9C
	movs r0, 0x8
	bl sub_803A1C0
_08039D9C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039D88

	thumb_func_start sub_8039DA4
sub_8039DA4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039DC6
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08039DC6
	bl sub_8012750
	movs r0, 0x10
	bl sub_803A1C0
_08039DC6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039DA4

	thumb_func_start sub_8039DCC
sub_8039DCC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039DE0
	movs r0, 0x5
	bl sub_803A1C0
_08039DE0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039DCC

	thumb_func_start sub_8039DE8
sub_8039DE8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08039E0E
	ldr r0, [sp]
	cmp r0, 0
	beq _08039E08
	cmp r0, 0x6
	bne _08039E0E
	movs r0, 0x11
	bl sub_803A1C0
	b _08039E0E
_08039E08:
	movs r0, 0x5
	bl sub_803A1C0
_08039E0E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8039DE8

	thumb_func_start nullsub_54
nullsub_54:
	bx lr
	thumb_func_end nullsub_54

	thumb_func_start sub_8039E18
sub_8039E18:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	ldr r1, _08039E38
	ldr r0, [r1]
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x13
	bls _08039E2E
	b _0803A1AA
_08039E2E:
	lsls r0, 2
	ldr r1, _08039E3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039E38: .4byte gUnknown_203B3E8
_08039E3C: .4byte _08039E40
	.align 2, 0
_08039E40:
	.4byte _08039E90
	.4byte _08039EB8
	.4byte _0803A1AA
	.4byte _08039EC8
	.4byte _08039EDC
	.4byte _0803A1AA
	.4byte _08039FF4
	.4byte _08039FA4
	.4byte _08039FCC
	.4byte _0803A00C
	.4byte _0803A1AA
	.4byte _0803A1AA
	.4byte _0803A1AA
	.4byte _08039F04
	.4byte _08039F68
	.4byte _0803A1AA
	.4byte _08039FAC
	.4byte _0803A152
	.4byte _0803A168
	.4byte _0803A18E
_08039E90:
	ldr r0, _08039EB0
	ldr r3, _08039EB4
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x1
	bl sub_8014248
	b _0803A1AA
	.align 2, 0
_08039EB0: .4byte gUnknown_80E7AC4
_08039EB4: .4byte gUnknown_80E786C
_08039EB8:
	ldr r0, _08039EC0
	ldr r3, _08039EC4
	b _08039EE0
	.align 2, 0
_08039EC0: .4byte gUnknown_80E7AE0
_08039EC4: .4byte gUnknown_80E7894
_08039EC8:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_802EF48
	b _0803A1AA
_08039EDC:
	ldr r0, _08039EFC
	ldr r3, _08039F00
_08039EE0:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0803A1AA
	.align 2, 0
_08039EFC: .4byte gUnknown_80E7B14
_08039F00: .4byte gUnknown_80E78D8
_08039F04:
	ldr r0, [r6]
	ldr r2, _08039F3C
	adds r1, r0, r2
	movs r3, 0xF0
	lsls r3, 2
	adds r0, r3
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r4}
	stm r1!, {r2,r4}
	ldr r2, [r6]
	ldr r3, _08039F40
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08039F44
	movs r4, 0x91
	lsls r4, 3
	adds r1, r2, r4
	subs r3, 0xA2
	adds r0, r2, r3
	str r0, [r1]
	adds r4, 0x4
	adds r1, r2, r4
	adds r3, 0x28
	adds r0, r2, r3
	str r0, [r1]
	b _08039F54
	.align 2, 0
_08039F3C: .4byte 0x00000474
_08039F40: .4byte 0x00000476
_08039F44:
	movs r4, 0x91
	lsls r4, 3
	adds r0, r2, r4
	movs r1, 0
	str r1, [r0]
	ldr r3, _08039F60
	adds r0, r2, r3
	str r1, [r0]
_08039F54:
	ldr r0, [r6]
	ldr r4, _08039F64
	adds r0, r4
	bl sub_802D098
	b _0803A1AA
	.align 2, 0
_08039F60: .4byte 0x0000048c
_08039F64: .4byte 0x00000474
_08039F68:
	ldr r1, [r6]
	movs r2, 0x93
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08039F9C
	movs r3, 0x92
	lsls r3, 3
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08039F84
	b _0803A1AA
_08039F84:
	cmp r0, 0x4
	bgt _08039F8E
	cmp r0, 0x3
	beq _08039F94
	b _0803A1AA
_08039F8E:
	cmp r0, 0x5
	beq _08039F94
	b _0803A1AA
_08039F94:
	ldr r0, _08039F98
	b _0803A154
	.align 2, 0
_08039F98: .4byte gUnknown_80E7B48
_08039F9C:
	ldr r0, _08039FA0
	b _0803A154
	.align 2, 0
_08039FA0: .4byte gUnknown_80E7B48
_08039FA4:
	ldr r0, _08039FA8
	b _0803A154
	.align 2, 0
_08039FA8: .4byte gUnknown_80E7B68
_08039FAC:
	ldr r0, [r6]
	movs r4, 0x93
	lsls r4, 3
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08039FC4
	ldr r0, _08039FC0
	b _0803A154
	.align 2, 0
_08039FC0: .4byte gUnknown_80E7B88
_08039FC4:
	ldr r0, _08039FC8
	b _0803A154
	.align 2, 0
_08039FC8: .4byte gUnknown_80E7BC8
_08039FCC:
	ldr r0, _08039FEC
	ldr r3, _08039FF0
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	b _0803A1AA
	.align 2, 0
_08039FEC: .4byte gUnknown_80E7BEC
_08039FF0: .4byte gUnknown_80E78F8
_08039FF4:
	movs r0, 0
	bl nullsub_23
	ldr r0, _0803A008
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _0803A1AA
	.align 2, 0
_0803A008: .4byte gUnknown_80E7C48
_0803A00C:
	ldr r0, [r6]
	movs r1, 0x94
	lsls r1, 2
	mov r8, r1
	add r0, r8
	movs r1, 0
	str r1, [r0]
	bl sub_8011830
	ldr r0, [r6]
	movs r7, 0x93
	lsls r7, 2
	adds r0, r7
	ldr r0, [r0]
	bl sub_8037B28
	ldr r2, [r6]
	mov r3, r8
	adds r1, r2, r3
	str r0, [r1]
	cmp r0, 0
	beq _0803A03A
	b _0803A14C
_0803A03A:
	adds r4, r7, 0
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, 0x9
	beq _0803A04A
	cmp r0, 0xA
	beq _0803A0AA
	b _0803A0DE
_0803A04A:
	movs r5, 0x95
	lsls r5, 2
	adds r0, r2, r5
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	bl sub_803B344
	adds r4, r0, 0
	ldr r1, [r4, 0x14]
	cmp r1, 0
	beq _0803A08C
	ldr r0, [r6]
	movs r2, 0x9A
	lsls r2, 2
	adds r0, r2
	movs r2, 0x28
	bl MemoryCopy8
	ldr r0, [r6]
	movs r3, 0xA4
	lsls r3, 2
	adds r0, r3
	ldr r1, [r4, 0x18]
	movs r2, 0x78
	bl MemoryCopy8
_0803A08C:
	ldr r1, [r6]
	adds r1, r5
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r4}
	stm r1!, {r2,r4}
	ldr r2, [r6]
	adds r0, r2, r7
	ldr r0, [r0]
	adds r1, r2, r5
	movs r3, 0xC2
	lsls r3, 2
	adds r2, r3
	b _0803A0D4
_0803A0AA:
	movs r4, 0x95
	lsls r4, 2
	adds r0, r2, r4
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0xC2
	lsls r5, 2
	adds r0, r5
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r2, [r6]
	adds r0, r2, r7
	ldr r0, [r0]
	adds r4, r2, r4
	adds r2, r5
	adds r1, r4, 0
_0803A0D4:
	bl sub_8037D64
	ldr r1, [r6]
	add r1, r8
	str r0, [r1]
_0803A0DE:
	ldr r4, _0803A134
	ldr r2, [r4]
	movs r5, 0x94
	lsls r5, 2
	adds r0, r2, r5
	ldr r0, [r0]
	cmp r0, 0
	bne _0803A14C
	movs r1, 0x93
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, 0xA
	bhi _0803A14C
	cmp r0, 0x9
	bcc _0803A14C
	movs r3, 0x95
	lsls r3, 2
	adds r1, r2, r3
	adds r3, 0xB4
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	adds r1, r5
	str r0, [r1]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _0803A138
	ldr r1, [r4]
	movs r4, 0xF0
	lsls r4, 2
	adds r0, r1, r4
	movs r2, 0xC2
	lsls r2, 2
	adds r1, r2
	movs r2, 0xB4
	bl memcpy
	b _0803A14C
	.align 2, 0
_0803A134: .4byte gUnknown_203B3E8
_0803A138:
	ldr r1, [r4]
	movs r3, 0xF0
	lsls r3, 2
	adds r0, r1, r3
	movs r4, 0x95
	lsls r4, 2
	adds r1, r4
	movs r2, 0xB4
	bl memcpy
_0803A14C:
	bl xxx_call_start_bg_music
	b _0803A1AA
_0803A152:
	ldr r0, _0803A160
_0803A154:
	ldr r3, _0803A164
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0803A1AA
	.align 2, 0
_0803A160: .4byte gUnknown_80E7C98
_0803A164: .4byte 0x00000101
_0803A168:
	ldr r0, [r6]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r1, 0x1
	movs r0, 0x5
	bl sub_80151C0
	b _0803A1AA
_0803A18E:
	ldr r0, _0803A1B8
	ldr r3, _0803A1BC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
_0803A1AA:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A1B8: .4byte gUnknown_80E7CC4
_0803A1BC: .4byte gUnknown_80E78F8
	thumb_func_end sub_8039E18

	thumb_func_start sub_803A1C0
sub_803A1C0:
	push {lr}
	ldr r1, _0803A1D4
	ldr r1, [r1]
	strb r0, [r1]
	bl nullsub_54
	bl sub_8039E18
	pop {r0}
	bx r0
	.align 2, 0
_0803A1D4: .4byte gUnknown_203B3E8
	thumb_func_end sub_803A1C0

	thumb_func_start sub_803A1D8
sub_803A1D8:
	movs r0, 0x1
	bx lr
	thumb_func_end sub_803A1D8

	thumb_func_start sub_803A1DC
sub_803A1DC:
	movs r0, 0
	bx lr
	thumb_func_end sub_803A1DC

	thumb_func_start nullsub_55
nullsub_55:
	bx lr
	thumb_func_end nullsub_55

	thumb_func_start sub_803A1E4
sub_803A1E4:
	movs r0, 0x1
	bx lr
	thumb_func_end sub_803A1E4

	thumb_func_start sub_803A1E8
sub_803A1E8:
	movs r0, 0x2
	bx lr
	thumb_func_end sub_803A1E8

	thumb_func_start sub_803A1EC
sub_803A1EC:
	push {lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	thumb_func_end sub_803A1EC

	thumb_func_start CreateDebugMenu
CreateDebugMenu:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, _0803A270
	ldr r0, [r5]
	cmp r0, 0
	bne _0803A224
	movs r4, 0xD2
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_0803A224:
	mov r12, r5
	movs r0, 0xA0
	lsls r0, 1
	mov r8, r0
	ldr r4, _0803A274
	movs r3, 0
	movs r2, 0x3
_0803A232:
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
	bge _0803A232
	bl ResetUnusedInputStruct
	ldr r0, _0803A270
	ldr r0, [r0]
	movs r6, 0xA0
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl SetDebugMenuItems
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A270: .4byte gUnknown_203B3EC
_0803A274: .4byte gUnknown_80E7D40
	thumb_func_end CreateDebugMenu

	thumb_func_start DeleteDebugMenu
DeleteDebugMenu:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0803A2A0
	ldr r0, [r4]
	cmp r0, 0
	beq _0803A298
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803A298:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A2A0: .4byte gUnknown_203B3EC
	thumb_func_end DeleteDebugMenu

	thumb_func_start sub_803A2A4
sub_803A2A4:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r4, _0803A2D4
	movs r0, 0xB
	str r0, [sp]
	ldr r5, _0803A2D8
	ldr r0, [r5]
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0803A2C4
	ldr r0, [r5]
	mov r1, sp
	bl sub_8013114
_0803A2C4:
	ldr r0, [sp]
	cmp r0, 0xB
	bhi _0803A34E
	lsls r0, 2
	ldr r1, _0803A2DC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A2D4: .4byte 0x0000ffdc
_0803A2D8: .4byte gUnknown_203B3EC
_0803A2DC: .4byte _0803A2E0
	.align 2, 0
_0803A2E0:
	.4byte _0803A310
	.4byte _0803A314
	.4byte _0803A318
	.4byte _0803A31C
	.4byte _0803A320
	.4byte _0803A324
	.4byte _0803A328
	.4byte _0803A34E
	.4byte _0803A34E
	.4byte _0803A330
	.4byte _0803A344
	.4byte _0803A34C
_0803A310:
	movs r4, 0x2F
	b _0803A34E
_0803A314:
	movs r4, 0x30
	b _0803A34E
_0803A318:
	movs r4, 0x31
	b _0803A34E
_0803A31C:
	movs r4, 0x32
	b _0803A34E
_0803A320:
	movs r4, 0x33
	b _0803A34E
_0803A324:
	movs r4, 0x34
	b _0803A34E
_0803A328:
	bl sub_803A3BC
	movs r4, 0x1
	b _0803A34E
_0803A330:
	movs r4, 0
_0803A332:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80976F8
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0803A332
	movs r4, 0x1
	b _0803A34E
_0803A344:
	bl sub_803A3A0
	movs r4, 0x1
	b _0803A34E
_0803A34C:
	ldr r4, _0803A358
_0803A34E:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0803A358: .4byte 0x0000ffdc
	thumb_func_end sub_803A2A4

	thumb_func_start SetDebugMenuItems
SetDebugMenuItems:
	push {r4,lr}
	sub sp, 0x10
	ldr r4, _0803A394
	ldr r0, [r4]
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r0, r2
	ldr r3, _0803A398
	ldr r2, _0803A39C
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	movs r2, 0
	str r2, [sp, 0xC]
	bl SetMenuItems
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A394: .4byte gUnknown_203B3EC
_0803A398: .4byte gUnknown_80E7D58
_0803A39C: .4byte gDebugMenuItems
	thumb_func_end SetDebugMenuItems

	thumb_func_start sub_803A3A0
sub_803A3A0:
	push {lr}
	ldr r0, _0803A3B8
	ldr r0, [r0]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	pop {r0}
	bx r0
	.align 2, 0
_0803A3B8: .4byte gUnknown_203B3EC
	thumb_func_end sub_803A3A0

	thumb_func_start sub_803A3BC
sub_803A3BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x84
	movs r5, 0x1
	add r4, sp, 0x60
	add r6, sp, 0x68
	add r0, sp, 0x7C
	mov r8, r0
	add r0, sp, 0x80
	mov r10, r0
_0803A3D6:
	lsls r0, r5, 24
	lsrs r0, 24
	bl UnlockFriendArea
	adds r5, 0x1
	cmp r5, 0x39
	ble _0803A3D6
	movs r5, 0
	adds r7, r4, 0
_0803A3E8:
	movs r0, 0
	mov r9, r0
	ldr r0, _0803A454
	str r0, [sp, 0x7C]
	adds r5, 0x1
	lsls r4, r5, 16
	asrs r4, 16
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r0, 0x27
	strh r0, [r7]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_808D8BC
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_80922F4
	movs r0, 0x40
	strb r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r6, 0
	movs r3, 0x43
	bl sub_808CFD0
	add r0, sp, 0x8
	bl sub_808D1DC
	ldr r0, _0803A458
	cmp r5, r0
	ble _0803A3E8
	mov r0, r9
	str r0, [sp, 0x80]
	mov r0, r10
	movs r1, 0x1
	bl sub_801203C
	add sp, 0x84
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A454: .4byte 0x00001006
_0803A458: .4byte 0x0000012b
	thumb_func_end sub_803A3BC

	thumb_func_start sub_803A45C
sub_803A45C:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0803A488
	movs r0, 0x9C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_803A504
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803A488: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A45C

	thumb_func_start sub_803A48C
sub_803A48C:
	push {lr}
	ldr r0, _0803A4A4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	bhi _0803A4E0
	lsls r0, 2
	ldr r1, _0803A4A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A4A4: .4byte gUnknown_203B3F0
_0803A4A8: .4byte _0803A4AC
	.align 2, 0
_0803A4AC:
	.4byte _0803A4C4
	.4byte _0803A4C4
	.4byte _0803A4CA
	.4byte _0803A4D0
	.4byte _0803A4D6
	.4byte _0803A4DC
_0803A4C4:
	bl sub_803A740
	b _0803A4E0
_0803A4CA:
	bl sub_803A7B0
	b _0803A4E0
_0803A4D0:
	bl sub_803A810
	b _0803A4E0
_0803A4D6:
	bl sub_803A86C
	b _0803A4E0
_0803A4DC:
	movs r0, 0x3
	b _0803A4E2
_0803A4E0:
	movs r0, 0
_0803A4E2:
	pop {r1}
	bx r1
	thumb_func_end sub_803A48C

	thumb_func_start sub_803A4E8
sub_803A4E8:
	push {r4,lr}
	ldr r4, _0803A500
	ldr r0, [r4]
	cmp r0, 0
	beq _0803A4FA
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803A4FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A500: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A4E8

	thumb_func_start sub_803A504
sub_803A504:
	push {lr}
	ldr r1, _0803A518
	ldr r1, [r1]
	str r0, [r1]
	bl sub_803A51C
	bl sub_803A5A0
	pop {r0}
	bx r0
	.align 2, 0
_0803A518: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A504

	thumb_func_start sub_803A51C
sub_803A51C:
	push {r4-r7,lr}
	ldr r4, _0803A53C
	ldr r0, [r4]
	adds r0, 0xD8
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2
	beq _0803A544
	cmp r0, 0x3
	bne _0803A55C
	adds r1, 0xF0
	ldr r0, _0803A540
	b _0803A54C
	.align 2, 0
_0803A53C: .4byte gUnknown_203B3F0
_0803A540: .4byte gUnknown_80E7E64
_0803A544:
	movs r0, 0x84
	lsls r0, 1
	adds r1, r0
	ldr r0, _0803A558
_0803A54C:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0803A57E
	.align 2, 0
_0803A558: .4byte gUnknown_80E7E4C
_0803A55C:
	mov r12, r4
	ldr r4, _0803A598
	movs r3, 0
	movs r2, 0x3
_0803A564:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xD8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0803A564
_0803A57E:
	bl ResetUnusedInputStruct
	ldr r0, _0803A59C
	ldr r0, [r0]
	adds r0, 0xD8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A598: .4byte gUnknown_80E7E34
_0803A59C: .4byte gUnknown_203B3F0
	thumb_func_end sub_803A51C

	thumb_func_start sub_803A5A0
sub_803A5A0:
	push {lr}
	sub sp, 0xC
	ldr r1, _0803A5BC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x5
	bhi _0803A68A
	lsls r0, 2
	ldr r1, _0803A5C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A5BC: .4byte gUnknown_203B3F0
_0803A5C0: .4byte _0803A5C4
	.align 2, 0
_0803A5C4:
	.4byte _0803A5DC
	.4byte _0803A5EA
	.4byte _0803A5F2
	.4byte _0803A61C
	.4byte _0803A678
	.4byte _0803A68A
_0803A5DC:
	movs r0, 0x2
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801C8C4
	b _0803A68A
_0803A5EA:
	movs r0, 0x1
	bl sub_801CB5C
	b _0803A68A
_0803A5F2:
	bl sub_801CCD8
	bl sub_803A6F0
	ldr r0, _0803A618
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r1, r2, 0
	adds r1, 0xC
	ldr r2, [r2, 0x8]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0803A68A
	.align 2, 0
_0803A618: .4byte gUnknown_203B3F0
_0803A61C:
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0xAC
	movs r0, 0x3
	str r0, [r1]
	subs r1, 0x8
	movs r0, 0
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0803A670
	str r0, [r1]
	adds r2, r3, 0
	adds r2, 0xA0
	ldr r0, _0803A674
	ldr r1, [r0]
	ldrb r0, [r3, 0x4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	str r0, [r2]
	adds r1, r3, 0
	adds r1, 0xB0
	movs r0, 0x1
	str r0, [r1]
	adds r1, 0x4
	adds r0, r3, 0
	adds r0, 0xF0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x2C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x9C
	bl sub_8013AA0
	bl sub_803A690
	b _0803A68A
	.align 2, 0
_0803A670: .4byte 0x000003e7
_0803A674: .4byte gUnknown_203B460
_0803A678:
	ldr r0, [r2]
	ldrb r1, [r0, 0x4]
	add r0, sp, 0x8
	movs r2, 0
	bl sub_8090A8C
	add r0, sp, 0x8
	bl sub_801B3C0
_0803A68A:
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_803A5A0

	thumb_func_start sub_803A690
sub_803A690:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _0803A6E8
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0803A6EC
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r4]
	adds r0, 0x9C
	bl sub_8013C68
	ldr r0, [r4]
	adds r0, 0xB0
	ldr r0, [r0]
	bl sub_80073E0
	bl sub_801CCD8
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	bl sub_8012EA4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A6E8: .4byte gUnknown_203B3F0
_0803A6EC: .4byte gUnknown_80E7E7C
	thumb_func_end sub_803A690

	thumb_func_start sub_803A6F0
sub_803A6F0:
	push {r4,lr}
	ldr r4, _0803A734
	ldr r1, [r4]
	ldr r0, _0803A738
	str r0, [r1, 0xC]
	movs r0, 0x2
	str r0, [r1, 0x10]
	str r0, [r1, 0x8]
	ldrb r0, [r1, 0x4]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _0803A718
	ldr r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	movs r1, 0x3
	str r1, [r0, 0x8]
_0803A718:
	ldr r1, [r4]
	movs r2, 0x1
	ldr r0, _0803A73C
	ldr r0, [r0]
	str r0, [r1, 0x14]
	movs r0, 0x3
	str r0, [r1, 0x18]
	movs r0, 0
	str r0, [r1, 0x1C]
	str r2, [r1, 0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A734: .4byte gUnknown_203B3F0
_0803A738: .4byte gUnknown_80E7E7C
_0803A73C: .4byte gUnknown_80D4970
	thumb_func_end sub_803A6F0

	thumb_func_start sub_803A740
sub_803A740:
	push {lr}
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x4
	bhi _0803A7AA
	lsls r0, 2
	ldr r1, _0803A758
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A758: .4byte _0803A75C
	.align 2, 0
_0803A75C:
	.4byte _0803A7AA
	.4byte _0803A7AA
	.4byte _0803A7A0
	.4byte _0803A770
	.4byte _0803A788
_0803A770:
	bl sub_801CB24
	ldr r1, _0803A784
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_803A504
	b _0803A7AA
	.align 2, 0
_0803A784: .4byte gUnknown_203B3F0
_0803A788:
	bl sub_801CB24
	ldr r1, _0803A79C
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x4
	bl sub_803A504
	b _0803A7AA
	.align 2, 0
_0803A79C: .4byte gUnknown_203B3F0
_0803A7A0:
	bl sub_801CBB8
	movs r0, 0x5
	bl sub_803A504
_0803A7AA:
	pop {r0}
	bx r0
	thumb_func_end sub_803A740

	thumb_func_start sub_803A7B0
sub_803A7B0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801CA08
	ldr r4, _0803A7E8
	ldr r0, [r4]
	adds r0, 0x4C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0803A7D6
	ldr r0, [r4]
	adds r0, 0x4C
	mov r1, sp
	bl sub_8013114
_0803A7D6:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803A7F2
	cmp r0, 0x2
	bgt _0803A7EC
	cmp r0, 0x1
	beq _0803A802
	b _0803A808
	.align 2, 0
_0803A7E8: .4byte gUnknown_203B3F0
_0803A7EC:
	cmp r0, 0x3
	beq _0803A7FA
	b _0803A808
_0803A7F2:
	movs r0, 0x3
	bl sub_803A504
	b _0803A808
_0803A7FA:
	movs r0, 0x4
	bl sub_803A504
	b _0803A808
_0803A802:
	movs r0, 0x1
	bl sub_803A504
_0803A808:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803A7B0

	thumb_func_start sub_803A810
sub_803A810:
	push {r4,lr}
	movs r0, 0
	bl sub_801CA08
	ldr r4, _0803A838
	ldr r0, [r4]
	adds r0, 0x4C
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x9C
	bl sub_8013BBC
	cmp r0, 0x2
	beq _0803A854
	cmp r0, 0x2
	bhi _0803A83C
	cmp r0, 0x1
	beq _0803A860
	b _0803A864
	.align 2, 0
_0803A838: .4byte gUnknown_203B3F0
_0803A83C:
	cmp r0, 0x3
	bne _0803A864
	ldr r0, _0803A85C
	ldr r2, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	lsls r0, 1
	adds r2, 0x50
	adds r2, r0
	adds r1, 0x9C
	ldr r0, [r1]
	strh r0, [r2]
_0803A854:
	movs r0, 0x1
	bl sub_803A504
	b _0803A864
	.align 2, 0
_0803A85C: .4byte gUnknown_203B460
_0803A860:
	bl sub_803A690
_0803A864:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803A810

	thumb_func_start sub_803A86C
sub_803A86C:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _0803A884
	cmp r0, 0x3
	bhi _0803A884
	bl sub_801B450
	movs r0, 0x1
	bl sub_803A504
_0803A884:
	pop {r0}
	bx r0
	thumb_func_end sub_803A86C

	thumb_func_start sub_803A888
sub_803A888:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0803A8B4
	movs r0, 0xFC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_803A924
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803A8B4: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A888

	thumb_func_start sub_803A8B8
sub_803A8B8:
	push {lr}
	ldr r0, _0803A8D0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0803A902
	lsls r0, 2
	ldr r1, _0803A8D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A8D0: .4byte gUnknown_203B3F4
_0803A8D4: .4byte _0803A8D8
	.align 2, 0
_0803A8D8:
	.4byte _0803A8EC
	.4byte _0803A8EC
	.4byte _0803A8F2
	.4byte _0803A8F8
	.4byte _0803A8FE
_0803A8EC:
	bl sub_803AAC4
	b _0803A902
_0803A8F2:
	bl sub_803AB34
	b _0803A902
_0803A8F8:
	bl sub_803ABAC
	b _0803A902
_0803A8FE:
	movs r0, 0x3
	b _0803A904
_0803A902:
	movs r0, 0
_0803A904:
	pop {r1}
	bx r1
	thumb_func_end sub_803A8B8

	thumb_func_start sub_803A908
sub_803A908:
	push {r4,lr}
	ldr r4, _0803A920
	ldr r0, [r4]
	cmp r0, 0
	beq _0803A91A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803A91A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A920: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A908

	thumb_func_start sub_803A924
sub_803A924:
	push {lr}
	ldr r1, _0803A938
	ldr r1, [r1]
	str r0, [r1]
	bl sub_803A93C
	bl sub_803A9AC
	pop {r0}
	bx r0
	.align 2, 0
_0803A938: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A924

	thumb_func_start sub_803A93C
sub_803A93C:
	push {r4-r7,lr}
	ldr r4, _0803A960
	ldr r0, [r4]
	adds r0, 0x9C
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2
	bne _0803A968
	adds r1, 0xCC
	ldr r0, _0803A964
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0803A98A
	.align 2, 0
_0803A960: .4byte gUnknown_203B3F4
_0803A964: .4byte gUnknown_80E7EA4
_0803A968:
	mov r12, r4
	ldr r4, _0803A9A4
	movs r3, 0
	movs r2, 0x3
_0803A970:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0x9C
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0803A970
_0803A98A:
	bl ResetUnusedInputStruct
	ldr r0, _0803A9A8
	ldr r0, [r0]
	adds r0, 0x9C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A9A4: .4byte gUnknown_80E7E8C
_0803A9A8: .4byte gUnknown_203B3F4
	thumb_func_end sub_803A93C

	thumb_func_start sub_803A9AC
sub_803A9AC:
	push {lr}
	sub sp, 0x8
	ldr r1, _0803A9C8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _0803AA2C
	lsls r0, 2
	ldr r1, _0803A9CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A9C8: .4byte gUnknown_203B3F4
_0803A9CC: .4byte _0803A9D0
	.align 2, 0
_0803A9D0:
	.4byte _0803A9E4
	.4byte _0803A9EE
	.4byte _0803A9F6
	.4byte _0803AA20
	.4byte _0803AA2C
_0803A9E4:
	movs r0, 0
	movs r1, 0x3
	bl sub_80211AC
	b _0803AA2C
_0803A9EE:
	movs r0, 0x1
	bl sub_8021354
	b _0803AA2C
_0803A9F6:
	bl sub_8021494
	bl sub_803AA34
	ldr r0, _0803AA1C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4C
	adds r1, r2, 0
	adds r1, 0xC
	ldr r2, [r2, 0x8]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0803AA2C
	.align 2, 0
_0803AA1C: .4byte gUnknown_203B3F4
_0803AA20:
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	movs r1, 0x1
	movs r2, 0
	bl sub_8021774
_0803AA2C:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_803A9AC

	thumb_func_start sub_803AA34
sub_803AA34:
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, _0803AA64
	ldr r1, [r0]
	ldr r2, _0803AA68
	ldr r3, [r2]
	ldrb r0, [r3, 0x4]
	adds r1, r0
	ldrb r0, [r1]
	adds r5, r2, 0
	cmp r0, 0
	beq _0803AA7A
	ldr r0, _0803AA6C
	str r0, [r3, 0xC]
	bl sub_803ABC8
	lsls r0, 24
	cmp r0, 0
	beq _0803AA70
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x10]
	b _0803AA82
	.align 2, 0
_0803AA64: .4byte gFriendAreas
_0803AA68: .4byte gUnknown_203B3F4
_0803AA6C: .4byte gUnknown_80E7EBC
_0803AA70:
	ldr r1, [r5]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x10]
	b _0803AA82
_0803AA7A:
	ldr r0, _0803AABC
	str r0, [r3, 0xC]
	movs r0, 0x2
	str r0, [r3, 0x10]
_0803AA82:
	adds r4, 0x1
	ldr r5, [r5]
	mov r12, r5
	lsls r1, r4, 3
	mov r3, r12
	adds r3, 0xC
	adds r2, r3, r1
	ldr r0, _0803AAC0
	ldr r0, [r0]
	str r0, [r2]
	mov r2, r12
	adds r2, 0x10
	adds r1, r2, r1
	movs r0, 0x4
	str r0, [r1]
	adds r4, 0x1
	lsls r1, r4, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r2, r1
	movs r0, 0x1
	str r0, [r2]
	mov r1, r12
	ldr r0, [r1, 0x10]
	str r0, [r1, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803AABC: .4byte gUnknown_80E7EC4
_0803AAC0: .4byte gUnknown_80D4970
	thumb_func_end sub_803AA34

	thumb_func_start sub_803AAC4
sub_803AAC4:
	push {lr}
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x4
	bhi _0803AB2E
	lsls r0, 2
	ldr r1, _0803AADC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803AADC: .4byte _0803AAE0
	.align 2, 0
_0803AAE0:
	.4byte _0803AB2E
	.4byte _0803AB2E
	.4byte _0803AB24
	.4byte _0803AAF4
	.4byte _0803AB0C
_0803AAF4:
	bl sub_802132C
	ldr r1, _0803AB08
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_803A924
	b _0803AB2E
	.align 2, 0
_0803AB08: .4byte gUnknown_203B3F4
_0803AB0C:
	bl sub_802132C
	ldr r1, _0803AB20
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x3
	bl sub_803A924
	b _0803AB2E
	.align 2, 0
_0803AB20: .4byte gUnknown_203B3F4
_0803AB24:
	bl sub_80213A0
	movs r0, 0x4
	bl sub_803A924
_0803AB2E:
	pop {r0}
	bx r0
	thumb_func_end sub_803AAC4

	thumb_func_start sub_803AB34
sub_803AB34:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8021274
	ldr r4, _0803AB6C
	ldr r0, [r4]
	adds r0, 0x4C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0803AB5A
	ldr r0, [r4]
	adds r0, 0x4C
	mov r1, sp
	bl sub_8013114
_0803AB5A:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803AB7A
	cmp r0, 0x2
	bgt _0803AB70
	cmp r0, 0x1
	beq _0803AB9E
	b _0803ABA4
	.align 2, 0
_0803AB6C: .4byte gUnknown_203B3F4
_0803AB70:
	cmp r0, 0x3
	beq _0803AB84
	cmp r0, 0x4
	beq _0803AB96
	b _0803ABA4
_0803AB7A:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl UnlockFriendArea
	b _0803AB8E
_0803AB84:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	movs r1, 0x1
	bl sub_809249C
_0803AB8E:
	movs r0, 0x1
	bl sub_803A924
	b _0803ABA4
_0803AB96:
	movs r0, 0x3
	bl sub_803A924
	b _0803ABA4
_0803AB9E:
	movs r0, 0x1
	bl sub_803A924
_0803ABA4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803AB34

	thumb_func_start sub_803ABAC
sub_803ABAC:
	push {lr}
	bl sub_80217EC
	cmp r0, 0x1
	bls _0803ABC4
	cmp r0, 0x3
	bhi _0803ABC4
	bl sub_8021830
	movs r0, 0x1
	bl sub_803A924
_0803ABC4:
	pop {r0}
	bx r0
	thumb_func_end sub_803ABAC

	thumb_func_start sub_803ABC8
sub_803ABC8:
	push {r4-r6,lr}
	movs r5, 0
	movs r6, 0x1
_0803ABCE:
	ldr r2, _0803AC08
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0803AC10
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _0803AC10
	ldr r0, _0803AC0C
	ldr r4, [r0]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl GetFriendArea
	ldrb r1, [r4, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0803AC10
	movs r0, 0
	b _0803AC1C
	.align 2, 0
_0803AC08: .4byte gUnknown_203B45C
_0803AC0C: .4byte gUnknown_203B3F4
_0803AC10:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0803ABCE
	movs r0, 0x1
_0803AC1C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_803ABC8

	thumb_func_start sub_803AC24
sub_803AC24:
	push {r4,lr}
	ldr r4, _0803AC44
	movs r0, 0xA0
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_803ACD0
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803AC44: .4byte gUnknown_203B3F8
	thumb_func_end sub_803AC24

	thumb_func_start sub_803AC48
sub_803AC48:
	push {lr}
	ldr r0, _0803AC60
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x7
	bhi _0803ACA8
	lsls r0, 2
	ldr r1, _0803AC64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803AC60: .4byte gUnknown_203B3F8
_0803AC64: .4byte _0803AC68
	.align 2, 0
_0803AC68:
	.4byte _0803AC88
	.4byte _0803AC90
	.4byte _0803AC90
	.4byte _0803AC96
	.4byte _0803ACA8
	.4byte _0803AC9C
	.4byte _0803ACA2
	.4byte _0803ACA8
_0803AC88:
	movs r0, 0x1
	bl sub_803ACD0
	b _0803ACAC
_0803AC90:
	bl sub_803AF38
	b _0803ACAC
_0803AC96:
	bl sub_803AF88
	b _0803ACAC
_0803AC9C:
	bl sub_803AFE8
	b _0803ACAC
_0803ACA2:
	bl sub_803B034
	b _0803ACAC
_0803ACA8:
	movs r0, 0x3
	b _0803ACAE
_0803ACAC:
	movs r0, 0
_0803ACAE:
	pop {r1}
	bx r1
	thumb_func_end sub_803AC48

	thumb_func_start sub_803ACB4
sub_803ACB4:
	push {r4,lr}
	ldr r4, _0803ACCC
	ldr r0, [r4]
	cmp r0, 0
	beq _0803ACC6
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803ACC6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803ACCC: .4byte gUnknown_203B3F8
	thumb_func_end sub_803ACB4

	thumb_func_start sub_803ACD0
sub_803ACD0:
	push {lr}
	ldr r1, _0803ACE4
	ldr r1, [r1]
	str r0, [r1]
	bl sub_803ACE8
	bl sub_803AD88
	pop {r0}
	bx r0
	.align 2, 0
_0803ACE4: .4byte gUnknown_203B3F8
	thumb_func_end sub_803ACD0

	thumb_func_start sub_803ACE8
sub_803ACE8:
	push {r4-r7,lr}
	ldr r4, _0803AD08
	ldr r0, [r4]
	adds r0, 0xE0
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _0803AD10
	cmp r0, 0x5
	beq _0803AD38
	movs r2, 0
	ldr r3, _0803AD0C
	b _0803AD50
	.align 2, 0
_0803AD08: .4byte gUnknown_203B3F8
_0803AD0C: .4byte gUnknown_80E7ED4
_0803AD10:
	bl sub_803AEB0
	ldr r2, [r4]
	movs r0, 0x88
	lsls r0, 1
	adds r2, r0
	ldr r1, _0803AD34
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x90
	bl sub_8012CAC
	b _0803AD6C
	.align 2, 0
_0803AD34: .4byte gUnknown_80E7EEC
_0803AD38:
	movs r6, 0x94
	lsls r6, 1
	adds r1, r6
	ldr r0, _0803AD4C
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	b _0803AD6C
	.align 2, 0
_0803AD4C: .4byte gUnknown_80E7F04
_0803AD50:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, 0xE0
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0803AD50
_0803AD6C:
	bl ResetUnusedInputStruct
	ldr r0, _0803AD84
	ldr r0, [r0]
	adds r0, 0xE0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AD84: .4byte gUnknown_203B3F8
	thumb_func_end sub_803ACE8

	thumb_func_start sub_803AD88
sub_803AD88:
	push {lr}
	sub sp, 0x8
	ldr r1, _0803ADA4
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x7
	bhi _0803AE50
	lsls r0, 2
	ldr r1, _0803ADA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803ADA4: .4byte gUnknown_203B3F8
_0803ADA8: .4byte _0803ADAC
	.align 2, 0
_0803ADAC:
	.4byte _0803AE50
	.4byte _0803ADCC
	.4byte _0803ADDA
	.4byte _0803ADE2
	.4byte _0803AE50
	.4byte _0803AE0C
	.4byte _0803AE44
	.4byte _0803AE50
_0803ADCC:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _0803AE50
_0803ADDA:
	movs r0, 0x1
	bl sub_8023B7C
	b _0803AE50
_0803ADE2:
	bl sub_8023DA4
	ldr r0, _0803AE08
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x10
	adds r1, r2, 0
	adds r1, 0x90
	adds r3, r2, 0
	adds r3, 0xD0
	ldr r2, [r2, 0xC]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0803AE50
	.align 2, 0
_0803AE08: .4byte gUnknown_203B3F8
_0803AE0C:
	ldr r2, [r2]
	movs r1, 0x3
	str r1, [r2, 0x70]
	movs r0, 0x1
	str r0, [r2, 0x68]
	movs r0, 0x64
	str r0, [r2, 0x6C]
	ldr r0, [r2, 0x8]
	ldrb r0, [r0, 0x3]
	str r0, [r2, 0x64]
	str r1, [r2, 0x74]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	str r0, [r2, 0x78]
	movs r0, 0x2C
	str r0, [r2, 0x7C]
	adds r1, r2, 0
	adds r1, 0x80
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x60
	bl sub_8013AA0
	bl sub_803AE58
	b _0803AE50
_0803AE44:
	ldr r0, [r2]
	ldr r1, [r0, 0x8]
	adds r1, 0x4C
	movs r0, 0x2
	bl sub_801602C
_0803AE50:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_803AD88

	thumb_func_start sub_803AE58
sub_803AE58:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _0803AEA8
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r2, _0803AEAC
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r4]
	adds r0, 0x60
	bl sub_8013C68
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	bl sub_8023DA4
	ldr r0, [r4]
	adds r0, 0x10
	movs r1, 0
	bl sub_8012EA4
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803AEA8: .4byte gUnknown_203B3F8
_0803AEAC: .4byte gUnknown_80E7F1C
	thumb_func_end sub_803AE58

	thumb_func_start sub_803AEB0
sub_803AEB0:
	push {r4-r6,lr}
	ldr r4, _0803AEFC
	ldr r0, [r4]
	adds r0, 0xD0
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	adds r1, r4, 0
	adds r1, 0x90
	ldr r0, _0803AF00
	str r0, [r1]
	adds r5, r4, 0
	adds r5, 0x94
	movs r0, 0x4
	str r0, [r5]
	movs r2, 0x1
	adds r1, 0x8
	ldr r0, _0803AF04
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	movs r6, 0x2
	adds r0, r4, 0
	adds r0, 0xA0
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	adds r0, 0x2C
	ldrh r0, [r0]
	cmp r0, 0
	bne _0803AF08
	ldr r0, [r5]
	str r0, [r4, 0xC]
	b _0803AF2C
	.align 2, 0
_0803AEFC: .4byte gUnknown_203B3F8
_0803AF00: .4byte gUnknown_80E7F24
_0803AF04: .4byte gUnknown_80E7F2C
_0803AF08:
	adds r3, 0x1
	cmp r3, r6
	bge _0803AF2C
	ldr r0, _0803AF34
	ldr r2, [r0]
	lsls r1, r3, 1
	adds r0, r2, 0
	adds r0, 0xD0
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _0803AF08
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x94
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
_0803AF2C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803AF34: .4byte gUnknown_203B3F8
	thumb_func_end sub_803AEB0

	thumb_func_start sub_803AF38
sub_803AF38:
	push {lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x2
	beq _0803AF78
	cmp r0, 0x2
	bcc _0803AF82
	cmp r0, 0x3
	bne _0803AF82
	bl sub_8023B44
	ldr r1, _0803AF70
	ldr r1, [r1]
	strh r0, [r1, 0x4]
	ldr r3, _0803AF74
	movs r0, 0x4
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x8]
	movs r0, 0x3
	bl sub_803ACD0
	b _0803AF82
	.align 2, 0
_0803AF70: .4byte gUnknown_203B3F8
_0803AF74: .4byte gUnknown_203B45C
_0803AF78:
	bl sub_8023C60
	movs r0, 0x7
	bl sub_803ACD0
_0803AF82:
	pop {r0}
	bx r0
	thumb_func_end sub_803AF38

	thumb_func_start sub_803AF88
sub_803AF88:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _0803AFC0
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0803AFAE
	ldr r0, [r4]
	adds r0, 0x10
	mov r1, sp
	bl sub_8013114
_0803AFAE:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0803AFCA
	cmp r0, 0x4
	bgt _0803AFC4
	cmp r0, 0x1
	beq _0803AFDA
	b _0803AFE0
	.align 2, 0
_0803AFC0: .4byte gUnknown_203B3F8
_0803AFC4:
	cmp r0, 0x5
	beq _0803AFD2
	b _0803AFE0
_0803AFCA:
	movs r0, 0x5
	bl sub_803ACD0
	b _0803AFE0
_0803AFD2:
	movs r0, 0x6
	bl sub_803ACD0
	b _0803AFE0
_0803AFDA:
	movs r0, 0x2
	bl sub_803ACD0
_0803AFE0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803AF88

	thumb_func_start sub_803AFE8
sub_803AFE8:
	push {r4,lr}
	movs r0, 0
	bl sub_8023A94
	ldr r4, _0803B010
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x60
	bl sub_8013BBC
	cmp r0, 0x2
	beq _0803B020
	cmp r0, 0x2
	bhi _0803B014
	cmp r0, 0x1
	beq _0803B028
	b _0803B02C
	.align 2, 0
_0803B010: .4byte gUnknown_203B3F8
_0803B014:
	cmp r0, 0x3
	bne _0803B02C
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	ldr r0, [r0, 0x60]
	strb r0, [r1, 0x3]
_0803B020:
	movs r0, 0x2
	bl sub_803ACD0
	b _0803B02C
_0803B028:
	bl sub_803AE58
_0803B02C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803AFE8

	thumb_func_start sub_803B034
sub_803B034:
	push {lr}
	bl sub_8016080
	cmp r0, 0x3
	bhi _0803B04C
	cmp r0, 0x2
	bcc _0803B04C
	bl sub_80160D8
	movs r0, 0x2
	bl sub_803ACD0
_0803B04C:
	pop {r0}
	bx r0
	thumb_func_end sub_803B034

	thumb_func_start sub_803B050
sub_803B050:
	push {r4-r7,lr}
	ldr r4, _0803B0F4
	movs r0, 0xF4
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x84
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0803B0F8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r2, 0
	movs r3, 0
	movs r7, 0xCB
	lsls r7, 1
	movs r6, 0x80
	lsls r6, 9
	movs r5, 0
_0803B0AE:
	ldr r0, _0803B0FC
	adds r0, r5, r0
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r4, _0803B0F4
	cmp r0, 0xA
	bne _0803B0C8
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r0, 0xA0
	adds r0, r1
	strh r3, [r0]
	adds r2, 0x1
_0803B0C8:
	adds r0, r6, 0
	movs r3, 0x80
	lsls r3, 9
	adds r6, r3
	adds r5, 0xC
	asrs r3, r0, 16
	cmp r3, r7
	ble _0803B0AE
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	adds r1, r2, 0
	movs r2, 0xA
	bl sub_8013818
	bl sub_803B204
	bl sub_803B284
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803B0F4: .4byte gUnknown_203B3FC
_0803B0F8: .4byte gUnknown_80E7F54
_0803B0FC: .4byte gFunctionScriptTable
	thumb_func_end sub_803B050

	thumb_func_start sub_803B100
sub_803B100:
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	ldr r0, _0803B11C
	ldr r0, [r0]
	bl sub_8013878
	bl sub_803B204
	bl sub_803B284
	pop {r0}
	bx r0
	.align 2, 0
_0803B11C: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B100

	thumb_func_start sub_803B120
sub_803B120:
	push {r4,lr}
	ldr r4, _0803B13C
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0803B140
	cmp r0, 0x2
	bne _0803B144
	movs r0, 0x1
	bl sub_80119D4
	movs r0, 0x2
	b _0803B160
	.align 2, 0
_0803B13C: .4byte gUnknown_203B3FC
_0803B140:
	movs r0, 0x3
	b _0803B160
_0803B144:
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0803B156
	movs r0, 0
	b _0803B160
_0803B156:
	bl sub_803B204
	bl sub_803B284
	movs r0, 0x1
_0803B160:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_803B120

	thumb_func_start sub_803B168
sub_803B168:
	ldr r0, _0803B188
	ldr r0, [r0]
	movs r1, 0x1E
	ldrsh r2, [r0, r1]
	movs r3, 0x1C
	ldrsh r1, [r0, r3]
	muls r1, r2
	movs r3, 0x18
	ldrsh r2, [r0, r3]
	adds r1, r2
	lsls r1, 1
	adds r0, 0xA0
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0803B188: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B168

	thumb_func_start sub_803B18C
sub_803B18C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0803B1B8
	ldr r0, [r5]
	movs r1, 0xE5
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_803B204
	bl sub_803B284
	cmp r4, 0
	beq _0803B1B2
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0803B1B2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B1B8: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B18C

	thumb_func_start sub_803B1BC
sub_803B1BC:
	push {r4,r5,lr}
	ldr r4, _0803B1FC
	ldr r2, [r4]
	cmp r2, 0
	beq _0803B1F6
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0803B200
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803B1F6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B1FC: .4byte gUnknown_203B3FC
_0803B200: .4byte gUnknown_80E7F3C
	thumb_func_end sub_803B1BC

	thumb_func_start sub_803B204
sub_803B204:
	push {r4,lr}
	ldr r4, _0803B280
	ldr r0, [r4]
	adds r0, 0x9C
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9D
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B280: .4byte gUnknown_203B3FC
	thumb_func_end sub_803B204

	thumb_func_start sub_803B284
sub_803B284:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _0803B338
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0803B33C
	ldr r0, [r6]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r4, [r0]
	lsls r4, 3
	subs r4, 0x2
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r5, 0
	ldr r0, [r6]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _0803B324
_0803B2DC:
	ldr r0, [r6]
	movs r3, 0x1E
	ldrsh r2, [r0, r3]
	movs r3, 0x1C
	ldrsh r1, [r0, r3]
	muls r2, r1
	adds r2, r5
	lsls r2, 1
	adds r1, r0, 0
	adds r1, 0xA0
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r4, r1, 1
	adds r4, r1
	lsls r4, 2
	ldr r1, _0803B340
	adds r4, r1
	adds r1, r5, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4, 0x4]
	ldr r0, [r6]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	bl xxx_call_draw_string
	adds r5, 0x1
	ldr r0, [r6]
	movs r3, 0x1A
	ldrsh r0, [r0, r3]
	cmp r5, r0
	blt _0803B2DC
_0803B324:
	ldr r0, _0803B338
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B338: .4byte gUnknown_203B3FC
_0803B33C: .4byte gUnknown_80E7F6C
_0803B340: .4byte gFunctionScriptTable
	thumb_func_end sub_803B284

	thumb_func_start sub_803B344
sub_803B344:
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, _0803B358
	adds r0, r1
	bx lr
	.align 2, 0
_0803B358: .4byte gUnknown_80E7F94
	thumb_func_end sub_803B344

	thumb_func_start sub_803B35C
sub_803B35C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, 0x18
	bl sub_803C21C
	ldrb r0, [r5, 0x2]
	subs r0, 0x1
	cmp r0, 0x8
	bls _0803B372
	b _0803B4FA
_0803B372:
	lsls r0, 2
	ldr r1, _0803B37C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B37C: .4byte _0803B380
	.align 2, 0
_0803B380:
	.4byte _0803B3A4
	.4byte _0803B3BE
	.4byte _0803B3D8
	.4byte _0803B3F2
	.4byte _0803B414
	.4byte _0803B442
	.4byte _0803B470
	.4byte _0803B49E
	.4byte _0803B4CC
_0803B3A4:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	subs r1, 0x14
	movs r0, 0x5
	b _0803B576
_0803B3BE:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	subs r1, 0x14
	movs r0, 0x5
	b _0803B576
_0803B3D8:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0x2
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	subs r1, 0x14
	movs r0, 0x5
	b _0803B576
_0803B3F2:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0x3
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x6
	strb r0, [r1]
	bl sub_8096DD8
	str r0, [r4, 0x4C]
	bl sub_8096DE8
	str r0, [r4, 0x50]
	b _0803B578
_0803B414:
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3
	bne _0803B42A
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xB
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x1
	b _0803B438
_0803B42A:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xC
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x2
_0803B438:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x4
	b _0803B576
_0803B442:
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3
	bne _0803B458
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xB
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x1
	b _0803B466
_0803B458:
	adds r0, r4, 0
	adds r0, 0x40
	movs r1, 0xC
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x42
	movs r0, 0x2
_0803B466:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x5
	b _0803B576
_0803B470:
	adds r0, r5, 0
	bl sub_803B600
	str r0, [r4, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803B488
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x9
	b _0803B48E
_0803B488:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x4
_0803B48E:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x6
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x4
	b _0803B576
_0803B49E:
	adds r0, r5, 0
	bl sub_803B628
	str r0, [r4, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803B4B6
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x9
	b _0803B4BC
_0803B4B6:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x5
_0803B4BC:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x7
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x4
	b _0803B576
_0803B4CC:
	adds r0, r5, 0
	bl sub_803B66C
	str r0, [r4, 0x4]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803B4E4
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xA
	b _0803B4EA
_0803B4E4:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x6
_0803B4EA:
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0x41
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x5
	b _0803B576
_0803B4FA:
	ldrb r0, [r5, 0x1]
	cmp r0, 0x2
	beq _0803B528
	cmp r0, 0x2
	bgt _0803B50A
	cmp r0, 0x1
	beq _0803B514
	b _0803B564
_0803B50A:
	cmp r0, 0x3
	beq _0803B53C
	cmp r0, 0x4
	beq _0803B550
	b _0803B564
_0803B514:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x9
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xD
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x4
	b _0803B576
_0803B528:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xA
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xE
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x5
	b _0803B576
_0803B53C:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xB
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xF
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x1
	b _0803B576
_0803B550:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0xC
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x10
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x2
	b _0803B576
_0803B564:
	adds r1, r4, 0
	adds r1, 0x40
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0xC
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x3
_0803B576:
	strb r0, [r1]
_0803B578:
	adds r0, r5, 0x4
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4, 0xC]
	ldrh r0, [r5, 0xC]
	movs r1, 0
	strh r0, [r4, 0x10]
	ldrh r0, [r5, 0xE]
	strh r0, [r4, 0x12]
	ldrb r0, [r5, 0x10]
	strb r0, [r4, 0x14]
	ldrb r0, [r5]
	subs r0, 0x2
	cmp r0, 0x7
	bhi _0803B5EC
	lsls r0, 2
	ldr r1, _0803B5A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B5A0: .4byte _0803B5A4
	.align 2, 0
_0803B5A4:
	.4byte _0803B5C4
	.4byte _0803B5C4
	.4byte _0803B5C4
	.4byte _0803B5C4
	.4byte _0803B5DC
	.4byte _0803B5CC
	.4byte _0803B5DC
	.4byte _0803B5DC
_0803B5C4:
	adds r0, r4, 0
	adds r0, 0x43
	movs r1, 0x1
	b _0803B5F0
_0803B5CC:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x3
	strb r0, [r1]
	b _0803B5F6
_0803B5DC:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x3
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0x2
	strb r0, [r1]
	b _0803B5F6
_0803B5EC:
	adds r0, r4, 0
	adds r0, 0x43
_0803B5F0:
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
_0803B5F6:
	str r5, [r4, 0x54]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_803B35C

	thumb_func_start sub_803B600
sub_803B600:
	push {lr}
	ldr r2, _0803B614
	movs r1, 0
	ldr r3, [r0, 0xC]
_0803B608:
	ldr r0, [r2]
	cmp r0, r3
	bne _0803B618
	adds r0, r1, 0
	b _0803B624
	.align 2, 0
_0803B614: .4byte gUnknown_80E9920
_0803B618:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x14
	ble _0803B608
	movs r0, 0x1
	negs r0, r0
_0803B624:
	pop {r1}
	bx r1
	thumb_func_end sub_803B600

	thumb_func_start sub_803B628
sub_803B628:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, _0803B654
	movs r3, 0
_0803B630:
	ldr r1, [r2]
	ldr r0, [r4, 0xC]
	cmp r1, r0
	beq _0803B650
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B658
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r5, 0xE
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B658
_0803B650:
	adds r0, r3, 0
	b _0803B664
	.align 2, 0
_0803B654: .4byte gUnknown_80E9F8C
_0803B658:
	adds r2, 0xC
	adds r3, 0x1
	cmp r3, 0x2C
	ble _0803B630
	movs r0, 0x1
	negs r0, r0
_0803B664:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803B628

	thumb_func_start sub_803B66C
sub_803B66C:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r2, _0803B698
	movs r3, 0
_0803B674:
	ldr r1, [r2]
	ldr r0, [r4, 0xC]
	cmp r1, r0
	beq _0803B694
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r5, 0xC
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B69C
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r5, 0xE
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bne _0803B69C
_0803B694:
	adds r0, r3, 0
	b _0803B6A8
	.align 2, 0
_0803B698: .4byte gUnknown_80E8168
_0803B69C:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x5
	ble _0803B674
	movs r0, 0x1
	negs r0, r0
_0803B6A8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803B66C

	thumb_func_start sub_803B6B0
sub_803B6B0:
	push {r4,lr}
	sub sp, 0x4
	lsls r2, 24
	ldr r4, _0803B6D0
	lsrs r2, 22
	adds r2, r4
	ldr r2, [r2]
	movs r4, 0
	str r4, [sp]
	bl xxx_call_draw_string
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B6D0: .4byte gUnknown_80E8B94
	thumb_func_end sub_803B6B0

	thumb_func_start sub_803B6D4
sub_803B6D4:
	push {r4-r7,lr}
	sub sp, 0x144
	adds r7, r0, 0
	ldr r1, [r7, 0x48]
	adds r0, 0x43
	ldrb r2, [r0]
	ldr r3, [r7]
	movs r0, 0xA
	bl sub_803B6B0
	adds r0, r7, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0xC
	bls _0803B6F4
	b _0803B86C
_0803B6F4:
	lsls r0, 2
	ldr r1, _0803B700
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B700: .4byte _0803B704
	.align 2, 0
_0803B704:
	.4byte _0803B73E
	.4byte _0803B748
	.4byte _0803B754
	.4byte _0803B738
	.4byte _0803B7A4
	.4byte _0803B7B0
	.4byte _0803B7C8
	.4byte _0803B760
	.4byte _0803B86C
	.4byte _0803B818
	.4byte _0803B7E0
	.4byte _0803B788
	.4byte _0803B76A
_0803B738:
	ldr r1, [r7, 0x48]
	ldr r2, [r7, 0x4C]
	b _0803B7CC
_0803B73E:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B744
	b _0803B7CC
	.align 2, 0
_0803B744: .4byte gMankeyMission
_0803B748:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B750
	b _0803B7CC
	.align 2, 0
_0803B750: .4byte gSmeargleMission
_0803B754:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B75C
	b _0803B7CC
	.align 2, 0
_0803B75C: .4byte gMedichamMission
_0803B760:
	ldr r1, [r7, 0x8]
	add r0, sp, 0x4
	bl sub_8090208
	b _0803B850
_0803B76A:
	ldr r4, _0803B780
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803B784
	add r0, sp, 0x4
	adds r2, r4, 0
	b _0803B84C
	.align 2, 0
_0803B780: .4byte gUnknown_202DE58
_0803B784: .4byte gUnknown_80E8830
_0803B788:
	ldr r4, _0803B79C
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803B7A0
	add r0, sp, 0x4
	adds r2, r4, 0
	b _0803B84C
	.align 2, 0
_0803B79C: .4byte gUnknown_202DE58
_0803B7A0: .4byte gUnknown_80E8848
_0803B7A4:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B7AC
	b _0803B7CC
	.align 2, 0
_0803B7AC: .4byte gUnknown_80E885C
_0803B7B0:
	ldr r1, [r7, 0x48]
	ldr r3, _0803B7C4
	ldr r2, [r7, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, 0x4
	adds r0, r3
	ldr r2, [r0]
	b _0803B7CC
	.align 2, 0
_0803B7C4: .4byte gUnknown_80E9F8C
_0803B7C8:
	ldr r1, [r7, 0x48]
	ldr r2, _0803B7DC
_0803B7CC:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	bl xxx_call_draw_string
	b _0803B8B4
	.align 2, 0
_0803B7DC: .4byte gUnknown_80E886C
_0803B7E0:
	ldr r0, [r7, 0x8]
	ldr r4, [r0, 0x4]
	ldrb r0, [r0]
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r5, _0803B810
	adds r0, r5, 0
	bl strcpy
	ldr r1, _0803B814
	movs r0, 0x3
	ands r4, r0
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	add r0, sp, 0x4
	adds r2, r5, 0
	b _0803B84C
	.align 2, 0
_0803B810: .4byte gUnknown_202DF98
_0803B814: .4byte gUnknown_80EAE5C
_0803B818:
	ldr r0, [r7, 0x8]
	ldr r4, [r0, 0x4]
	ldrb r0, [r0]
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r6, _0803B864
	adds r0, r6, 0
	bl strcpy
	ldr r5, _0803B868
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r5
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r6, 0
_0803B84C:
	bl sub_800D158
_0803B850:
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803B8B4
	.align 2, 0
_0803B864: .4byte gUnknown_202DF98
_0803B868: .4byte gUnknown_80E910C
_0803B86C:
	ldr r0, [r7, 0x8]
	ldr r4, [r0, 0x4]
	ldrb r0, [r0]
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r6, _0803B8E8
	adds r0, r6, 0
	bl strcpy
	ldr r5, _0803B8EC
	adds r0, r4, 0
	movs r1, 0xF
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r5
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r6, 0
	bl sub_800D158
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	add r2, sp, 0x4
	bl xxx_call_draw_string
_0803B8B4:
	adds r0, r7, 0
	adds r0, 0x40
	ldrb r1, [r0]
	adds r6, r0, 0
	cmp r1, 0x7
	bne _0803B916
	ldr r5, [r7, 0xC]
	cmp r5, 0
	bne _0803B8F0
	bl sub_8016028
	movs r4, 0xB2
	subs r4, r0
	movs r1, 0x10
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r2, r0, 0
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	str r5, [sp]
	adds r0, r4, 0
	bl xxx_call_draw_string
	b _0803B956
	.align 2, 0
_0803B8E8: .4byte gUnknown_202DF98
_0803B8EC: .4byte gUnknown_80E8C98
_0803B8F0:
	add r4, sp, 0xCC
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xA
	bl sub_80922B4
	bl sub_8016028
	adds r1, r0, 0
	movs r0, 0xB2
	subs r0, r1
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r2, 0
	str r2, [sp]
	adds r2, r4, 0
	bl xxx_call_draw_string
	b _0803B956
_0803B916:
	adds r0, r7, 0
	adds r0, 0x42
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0803B93C
	add r4, sp, 0xE0
	ldr r1, [r7, 0x8]
	adds r0, r4, 0
	bl sub_8090228
	ldr r1, _0803B938
	add r0, sp, 0x4
	adds r2, r4, 0
	bl sub_800D158
	b _0803B944
	.align 2, 0
_0803B938: .4byte gUnknown_80E8884
_0803B93C:
	ldr r1, [r7, 0x8]
	add r0, sp, 0x4
	bl sub_8090228
_0803B944:
	ldr r1, [r7, 0x48]
	adds r1, 0xC
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1D
	add r2, sp, 0x4
	bl xxx_call_draw_string
_0803B956:
	ldrb r0, [r6]
	cmp r0, 0x7
	bne _0803B962
	ldr r0, [r7, 0x8]
	movs r1, 0
	b _0803B968
_0803B962:
	ldr r0, [r7, 0x8]
	ldr r1, [r7, 0x54]
	ldrb r1, [r1, 0x1]
_0803B968:
	bl sub_803C1D0
	lsls r0, 24
	lsrs r0, 24
	bl sub_803C1F0
	adds r2, r0, 0
	ldr r1, [r7, 0x48]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xB4
	bl xxx_call_draw_string
	add sp, 0x144
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_803B6D4

	thumb_func_start sub_803B98C
sub_803B98C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1FC
	adds r7, r0, 0
	movs r0, 0
	mov r9, r0
	ldr r2, _0803B9E0
	ldr r3, [r7]
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, _0803B9E4
	adds r0, r7, 0
	adds r0, 0x44
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r7]
	mov r1, r9
	str r1, [sp]
	movs r0, 0x6C
	movs r1, 0
	bl xxx_call_draw_string
	movs r0, 0x10
	mov r9, r0
	adds r0, r7, 0
	adds r0, 0x41
	ldrb r0, [r0]
	cmp r0, 0x10
	bls _0803B9D6
	b _0803BCC0
_0803B9D6:
	lsls r0, 2
	ldr r1, _0803B9E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B9E0: .4byte gUnknown_80E888C
_0803B9E4: .4byte gUnknown_80E8BCC
_0803B9E8: .4byte _0803B9EC
	.align 2, 0
_0803B9EC:
	.4byte _0803BA34
	.4byte _0803BA3C
	.4byte _0803BA44
	.4byte _0803BA30
	.4byte _0803BA4C
	.4byte _0803BA6C
	.4byte _0803BA8C
	.4byte _0803BAA0
	.4byte _0803BBF0
	.4byte _0803BAE8
	.4byte _0803BAF0
	.4byte _0803BAF8
	.4byte _0803BCC0
	.4byte _0803BC58
	.4byte _0803BB74
	.4byte _0803BB10
	.4byte _0803BB10
_0803BA30:
	ldr r2, [r7, 0x50]
	b _0803BAFA
_0803BA34:
	ldr r2, _0803BA38
	b _0803BAFA
	.align 2, 0
_0803BA38: .4byte gUnknown_80E88A0
_0803BA3C:
	ldr r2, _0803BA40
	b _0803BAFA
	.align 2, 0
_0803BA40: .4byte gUnknown_80E88C8
_0803BA44:
	ldr r2, _0803BA48
	b _0803BAFA
	.align 2, 0
_0803BA48: .4byte gUnknown_80E8920
_0803BA4C:
	ldr r4, _0803BA64
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BA68
	add r0, sp, 0x4
	adds r2, r4, 0
	bl sub_800D158
	b _0803BACC
	.align 2, 0
_0803BA64: .4byte gUnknown_202DE58
_0803BA68: .4byte gUnknown_80E8968
_0803BA6C:
	ldr r4, _0803BA84
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BA88
	add r0, sp, 0x4
	adds r2, r4, 0
	bl sub_800D158
	b _0803BACC
	.align 2, 0
_0803BA84: .4byte gUnknown_202DE58
_0803BA88: .4byte gUnknown_80E89B0
_0803BA8C:
	ldr r1, _0803BA9C
	ldr r0, [r7, 0x4]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r2, [r0]
	b _0803BAFA
	.align 2, 0
_0803BA9C: .4byte gUnknown_80E9920
_0803BAA0:
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r4, _0803BAE0
	adds r0, r4, 0
	bl strcpy
	ldr r2, _0803BAE4
	ldr r1, [r7, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r4, 0
	adds r3, r4, 0
	bl sub_800D158
_0803BACC:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803BD42
	.align 2, 0
_0803BAE0: .4byte gUnknown_202DF98
_0803BAE4: .4byte gUnknown_80E9F8C
_0803BAE8:
	ldr r2, _0803BAEC
	b _0803BAFA
	.align 2, 0
_0803BAEC: .4byte gUnknown_80E89FC
_0803BAF0:
	ldr r2, _0803BAF4
	b _0803BAFA
	.align 2, 0
_0803BAF4: .4byte gUnknown_80E8A40
_0803BAF8:
	ldr r2, _0803BB0C
_0803BAFA:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	b _0803BD42
	.align 2, 0
_0803BB0C: .4byte gUnknown_80E8A7C
_0803BB10:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, _0803BB68
	mov r8, r0
	ldrb r1, [r7, 0x14]
	movs r2, 0
	bl sub_8090DC4
	ldr r6, _0803BB6C
	adds r0, r4, 0
	movs r1, 0x16
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl sub_800D158
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BB70
	adds r0, r5, 0
	movs r1, 0x16
	b _0803BD1A
	.align 2, 0
_0803BB68: .4byte gUnknown_202DE58
_0803BB6C: .4byte gUnknown_80EB3F8
_0803BB70: .4byte gUnknown_80EB72C
_0803BB74:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r0, _0803BBE4
	mov r8, r0
	bl strcpy
	ldr r6, _0803BBE8
	adds r0, r4, 0
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl sub_800D158
	ldr r3, [r7]
	movs r4, 0
	str r4, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r1, _0803BBEC
	movs r0, 0x3
	ands r5, r0
	lsls r5, 2
	adds r5, r1
	ldr r1, [r5]
	add r0, sp, 0x4
	mov r2, r8
	bl sub_800D158
	ldr r3, [r7]
	str r4, [sp]
	b _0803BD32
	.align 2, 0
_0803BBE4: .4byte gUnknown_202DF98
_0803BBE8: .4byte gUnknown_80EAEB8
_0803BBEC: .4byte gUnknown_80EB198
_0803BBF0:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r0, _0803BC4C
	mov r8, r0
	bl strcpy
	ldr r6, _0803BC50
	adds r0, r4, 0
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl sub_800D158
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BC54
	adds r0, r5, 0
	movs r1, 0x6
	b _0803BD1A
	.align 2, 0
_0803BC4C: .4byte gUnknown_202DF98
_0803BC50: .4byte gUnknown_80EB220
_0803BC54: .4byte gUnknown_80EB2F0
_0803BC58:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r0, _0803BCB4
	mov r8, r0
	bl strcpy
	ldr r6, _0803BCB8
	adds r0, r4, 0
	movs r1, 0x2D
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl sub_800D158
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BCBC
	adds r0, r5, 0
	movs r1, 0xA
	b _0803BD1A
	.align 2, 0
_0803BCB4: .4byte gUnknown_202DF98
_0803BCB8: .4byte gUnknown_80E91D4
_0803BCBC: .4byte gUnknown_80E9820
_0803BCC0:
	ldr r0, [r7, 0x8]
	ldr r5, [r0, 0x4]
	ldrb r4, [r0]
	adds r4, r5, r4
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r0, 0x1]
	adds r5, r0
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x10
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r0, _0803BD78
	mov r8, r0
	bl strcpy
	ldr r6, _0803BD7C
	adds r0, r4, 0
	movs r1, 0xD
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r6
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl sub_800D158
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r1, 0xC
	add r9, r1
	ldr r4, _0803BD80
	adds r0, r5, 0
	movs r1, 0xD
_0803BD1A:
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	ldr r1, [r0]
	add r0, sp, 0x4
	mov r2, r8
	bl sub_800D158
	ldr r3, [r7]
	str r6, [sp]
_0803BD32:
	movs r0, 0xA
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	movs r0, 0xC
	negs r0, r0
	add r9, r0
_0803BD42:
	movs r1, 0x1C
	add r9, r1
	ldr r2, _0803BD84
	ldr r3, [r7]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	ldr r1, [r7, 0xC]
	cmp r1, 0
	bne _0803BD88
	movs r1, 0x10
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r2, r0, 0
	ldr r3, [r7]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	b _0803BDBC
	.align 2, 0
_0803BD78: .4byte gUnknown_202DF98
_0803BD7C: .4byte gUnknown_80E8DE4
_0803BD80: .4byte gUnknown_80E8FB0
_0803BD84: .4byte gUnknown_80E8AC8
_0803BD88:
	add r6, sp, 0x158
	adds r0, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	add r4, sp, 0x16C
	movs r0, 0x10
	ldrsh r1, [r7, r0]
	adds r0, r4, 0
	bl sub_808D930
	add r5, sp, 0x130
	ldr r1, _0803BDE8
	adds r0, r5, 0
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_800D158
	ldr r3, [r7]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x44
	mov r1, r9
	adds r2, r5, 0
	bl xxx_call_draw_string
_0803BDBC:
	movs r0, 0xC
	add r9, r0
	ldr r2, _0803BDEC
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	adds r0, r7, 0
	adds r0, 0x42
	ldrb r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x6
	bhi _0803BEB8
	lsls r0, r1, 2
	ldr r1, _0803BDF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BDE8: .4byte gUnknown_80E8AD0
_0803BDEC: .4byte gUnknown_80E8AE0
_0803BDF0: .4byte _0803BDF4
	.align 2, 0
_0803BDF4:
	.4byte _0803BE10
	.4byte _0803BE30
	.4byte _0803BE18
	.4byte _0803BE48
	.4byte _0803BE80
	.4byte _0803BE60
	.4byte _0803BEB8
_0803BE10:
	ldr r2, _0803BE14
	b _0803BE4A
	.align 2, 0
_0803BE14: .4byte gUnknown_80E8AEC
_0803BE18:
	ldr r4, _0803BE28
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BE2C
	b _0803BE94
	.align 2, 0
_0803BE28: .4byte gUnknown_202DE58
_0803BE2C: .4byte gUnknown_80E8AFC
_0803BE30:
	ldr r4, _0803BE40
	ldrb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803BE44
	b _0803BE94
	.align 2, 0
_0803BE40: .4byte gUnknown_202DE58
_0803BE44: .4byte gUnknown_80E8B10
_0803BE48:
	ldr r2, _0803BE5C
_0803BE4A:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	b _0803BEC8
	.align 2, 0
_0803BE5C: .4byte gUnknown_80E8B20
_0803BE60:
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r4, _0803BE78
	adds r0, r4, 0
	bl strcpy
	ldr r1, _0803BE7C
	b _0803BE94
	.align 2, 0
_0803BE78: .4byte gUnknown_202DF98
_0803BE7C: .4byte gUnknown_80E8B2C
_0803BE80:
	movs r1, 0x12
	ldrsh r0, [r7, r1]
	bl sub_808D994
	adds r1, r0, 0
	ldr r4, _0803BEB0
	adds r0, r4, 0
	bl strcpy
	ldr r1, _0803BEB4
_0803BE94:
	add r0, sp, 0x4
	adds r2, r4, 0
	bl sub_800D158
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803BEC8
	.align 2, 0
_0803BEB0: .4byte gUnknown_202DF98
_0803BEB4: .4byte gUnknown_80E8B40
_0803BEB8:
	ldr r2, _0803BEF8
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
_0803BEC8:
	movs r0, 0xC
	add r9, r0
	ldr r2, _0803BEFC
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	ldrb r0, [r5]
	cmp r0, 0x1
	bne _0803BF04
	add r4, sp, 0x180
	ldr r1, [r7, 0x8]
	adds r0, r4, 0
	bl sub_8090228
	ldr r1, _0803BF00
	add r0, sp, 0x4
	adds r2, r4, 0
	bl sub_800D158
	b _0803BF0C
	.align 2, 0
_0803BEF8: .4byte gSpecialMissionText
_0803BEFC: .4byte gPlaceText
_0803BF00: .4byte gUnknown_80E8884
_0803BF04:
	ldr r1, [r7, 0x8]
	add r0, sp, 0x4
	bl sub_8090228
_0803BF0C:
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldrb r0, [r5]
	cmp r0, 0
	bne _0803BF28
	ldr r0, [r7, 0x8]
	movs r1, 0
	b _0803BF2E
_0803BF28:
	ldr r0, [r7, 0x8]
	ldr r1, [r7, 0x54]
	ldrb r1, [r1, 0x1]
_0803BF2E:
	bl sub_803C1D0
	lsls r0, 24
	lsrs r4, r0, 24
	movs r1, 0xC
	add r9, r1
	ldr r2, _0803BF88
	ldr r3, [r7]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	adds r0, r4, 0
	bl sub_803C1F0
	adds r2, r0, 0
	ldr r3, [r7]
	str r6, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	movs r0, 0xC
	add r9, r0
	ldr r2, _0803BF8C
	ldr r3, [r7]
	str r6, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	adds r0, r7, 0
	adds r0, 0x2E
	ldrb r2, [r0]
	adds r5, r0, 0
	cmp r2, 0x4
	bhi _0803C02C
	lsls r0, r2, 2
	ldr r1, _0803BF90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BF88: .4byte gDifficultyText
_0803BF8C: .4byte gRewardText
_0803BF90: .4byte _0803BF94
	.align 2, 0
_0803BF94:
	.4byte _0803BFA8
	.4byte _0803BFBC
	.4byte _0803BFD0
	.4byte _0803BFD0
	.4byte _0803C00C
_0803BFA8:
	ldr r1, _0803BFB8
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r2, [r7, 0x30]
	add r0, sp, 0x4
	b _0803BFEE
	.align 2, 0
_0803BFB8: .4byte gUnknown_80E8C48
_0803BFBC:
	ldr r1, _0803BFCC
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r2, [r7, 0x30]
	add r0, sp, 0x4
	b _0803BFEE
	.align 2, 0
_0803BFCC: .4byte gUnknown_80E8C48
_0803BFD0:
	ldr r4, _0803C004
	adds r0, r7, 0
	adds r0, 0x34
	ldrb r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r1, _0803C008
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	add r0, sp, 0x4
	adds r2, r4, 0
_0803BFEE:
	bl sub_800D158
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0803C040
	.align 2, 0
_0803C004: .4byte gUnknown_202DE58
_0803C008: .4byte gUnknown_80E8C48
_0803C00C:
	ldr r1, _0803C028
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
	b _0803C040
	.align 2, 0
_0803C028: .4byte gUnknown_80E8C48
_0803C02C:
	ldr r1, _0803C0D4
	lsls r0, r2, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r7]
	str r6, [sp]
	movs r0, 0x44
	mov r1, r9
	bl xxx_call_draw_string
_0803C040:
	movs r1, 0xC
	add r9, r1
	adds r0, r7, 0
	adds r0, 0x41
	ldrb r1, [r0]
	adds r0, r1, 0
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _0803C0C6
	cmp r1, 0x3
	beq _0803C0C6
	ldr r0, [r7, 0x54]
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0803C0C6
	ldr r2, _0803C0D8
	ldr r3, [r7]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	mov r1, r9
	bl xxx_call_draw_string
	add r0, sp, 0x1E4
	ldr r1, [r7, 0x54]
	bl sub_803D414
	movs r4, 0
_0803C07C:
	cmp r4, 0xC
	bne _0803C084
	movs r0, 0xC
	add r9, r0
_0803C084:
	movs r5, 0x7
	cmp r4, 0x3
	ble _0803C09C
	movs r5, 0x6
	cmp r4, 0x7
	ble _0803C09C
	movs r5, 0x7
	cmp r4, 0xF
	ble _0803C09C
	cmp r4, 0x13
	bgt _0803C09C
	movs r5, 0x6
_0803C09C:
	adds r0, r4, 0
	movs r1, 0xC
	bl __modsi3
	adds r1, r0, 0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, 0x54
	add r1, sp, 0x1E4
	adds r1, r4
	ldrb r2, [r1]
	ldr r1, [r7]
	str r1, [sp]
	mov r1, r9
	adds r3, r5, 0
	bl sub_8012C60
	adds r4, 0x1
	cmp r4, 0x17
	ble _0803C07C
_0803C0C6:
	add sp, 0x1FC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C0D4: .4byte gUnknown_80E8C48
_0803C0D8: .4byte gUnknown_80E8B7C
	thumb_func_end sub_803B98C

	thumb_func_start sub_803C0DC
sub_803C0DC:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E770
	lsls r0, 16
	asrs r2, r0, 16
	ldr r1, _0803C0F0
	b _0803C102
	.align 2, 0
_0803C0F0: .4byte gUnknown_80E80E0
_0803C0F4:
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	bne _0803C100
	movs r0, 0
	b _0803C10C
_0803C100:
	adds r1, 0x2
_0803C102:
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0803C0F4
	movs r0, 0x1
_0803C10C:
	pop {r1}
	bx r1
	thumb_func_end sub_803C0DC

	thumb_func_start sub_803C110
sub_803C110:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _0803C180
	adds r0, r4, 0
	bl sub_808E770
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	bne _0803C180
	adds r0, r4, 0
	bl sub_803C0DC
	lsls r0, 24
	cmp r0, 0
	beq _0803C180
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0803C188
	ldr r1, _0803C184
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0803C168
	adds r2, r1, 0
_0803C154:
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, r4
	beq _0803C180
	adds r1, 0x2
	adds r2, 0x2
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bne _0803C154
_0803C168:
	bl sub_808D33C
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r0, r4
	beq _0803C180
	bl sub_808D378
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	cmp r0, r4
	bne _0803C188
_0803C180:
	movs r0, 0
	b _0803C18A
	.align 2, 0
_0803C184: .4byte gUnknown_80E8126
_0803C188:
	movs r0, 0x1
_0803C18A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_803C110

        .align 2,0
