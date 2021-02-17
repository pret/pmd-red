        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start DisplayStarterSprite
DisplayStarterSprite:
	push {r4-r7,lr}
	sub sp, 0x60
	ldr r0, _0803CD00
	ldr r0, [r0]
	movs r1, 0x8
	ldrsh r4, [r0, r1]
	mov r0, sp
	bl sub_8006518
	add r1, sp, 0x18
	ldr r0, _0803CD04
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	mov r0, sp
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	movs r0, 0x1
	bl sub_8008C54
	movs r0, 0x1
	bl sub_80073B8
	adds r0, r4, 0
	bl GetDialogueSpriteDataPtr
	adds r5, r0, 0
	ldr r0, [r5, 0x4]
	ldr r6, [r0, 0xC]
	movs r4, 0
	movs r7, 0x8
_0803CCC8:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r1, [r5, 0x4]
	adds r1, r7
	lsls r2, r4, 2
	ldr r1, [r1]
	adds r1, r2
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0xF
	ble _0803CCC8
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0xE
	bl sub_800836C
	adds r0, r5, 0
	bl CloseFile
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CD00: .4byte gUnknown_203B400
_0803CD04: .4byte gUnknown_80F4244
	thumb_func_end DisplayStarterSprite

	thumb_func_start sub_803CD08
sub_803CD08:
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	bl sub_803CEAC
	ldr r5, _0803CDB0
	ldr r0, [r5]
	movs r3, 0
	movs r1, 0
	strh r4, [r0]
	str r1, [r0, 0x4C]
	adds r1, r0, 0
	adds r1, 0x54
	str r1, [r0, 0x50]
	ldr r0, _0803CDB4
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldr r1, [r5]
	adds r1, 0x6C
	ldr r0, _0803CDB8
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r5]
	ldr r2, _0803CDBC
	adds r1, 0x84
	adds r0, r2, 0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r0, [r5]
	adds r0, 0x9C
	ldm r2!, {r1,r4,r6}
	stm r0!, {r1,r4,r6}
	ldm r2!, {r1,r4,r7}
	stm r0!, {r1,r4,r7}
	ldr r0, [r5]
	ldr r1, [r0, 0x50]
	adds r0, 0xB4
	str r0, [r1, 0x14]
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0xB5
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, 0xB6
	movs r1, 0x6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0xB7
	strb r3, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x18
	bl GetValidPartners
	adds r1, r0, 0
	ldr r0, [r5]
	ldr r3, [r0, 0x4C]
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_8013818
	bl sub_803CEF0
	bl sub_803CFC0
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CDB0: .4byte gUnknown_203B404
_0803CDB4: .4byte gUnknown_80F4290
_0803CDB8: .4byte gUnknown_80F42A8
_0803CDBC: .4byte gUnknown_80F4278
	thumb_func_end sub_803CD08

	thumb_func_start sub_803CDC0
sub_803CDC0:
	push {r4,r5,lr}
	ldr r4, _0803CDF0
	ldr r1, [r4]
	movs r0, 0x30
	ldrsh r5, [r1, r0]
	movs r0, 0
	strb r0, [r1, 0x16]
	ldr r0, [r4]
	adds r0, 0x18
	bl GetKeyPress
	cmp r0, 0x1
	bne _0803CDF4
	movs r0, 0
	bl sub_80119D4
	ldr r0, [r4]
	movs r2, 0x30
	ldrsh r1, [r0, r2]
	lsls r1, 1
	adds r0, 0x2
	adds r0, r1
	ldrh r0, [r0]
	b _0803CE2A
	.align 2, 0
_0803CDF0: .4byte gUnknown_203B404
_0803CDF4:
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	beq _0803CE08
	bl sub_803CEF0
_0803CE08:
	ldr r0, [r4]
	movs r1, 0x30
	ldrsh r0, [r0, r1]
	cmp r5, r0
	beq _0803CE16
	bl sub_803CFC0
_0803CE16:
	ldr r0, [r4]
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	bne _0803CE28
	ldr r0, _0803CE24
	b _0803CE2A
	.align 2, 0
_0803CE24: .4byte 0x0000ffff
_0803CE28:
	ldr r0, _0803CE30
_0803CE2A:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0803CE30: .4byte 0x0000fffe
	thumb_func_end sub_803CDC0

	thumb_func_start sub_803CE34
sub_803CE34:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl GetValidPartners
	adds r1, r0, 0
	ldr r5, _0803CE68
	ldr r0, [r5]
	strh r1, [r0, 0x3A]
	adds r0, 0x18
	bl sub_8013984
	bl sub_803CEF0
	bl sub_803CFC0
	cmp r4, 0
	beq _0803CE62
	ldr r0, [r5]
	adds r0, 0x18
	bl AddMenuCursorSprite
_0803CE62:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CE68: .4byte gUnknown_203B404
	thumb_func_end sub_803CE34

	thumb_func_start sub_803CE6C
sub_803CE6C:
	push {r4,r5,lr}
	ldr r4, _0803CEA4
	ldr r1, [r4]
	ldr r2, [r1, 0x4C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x54
	ldr r0, _0803CEA8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803CECC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CEA4: .4byte gUnknown_203B404
_0803CEA8: .4byte gUnknown_80F4278
	thumb_func_end sub_803CE6C

	thumb_func_start sub_803CEAC
sub_803CEAC:
	push {r4,lr}
	ldr r4, _0803CEC4
	movs r0, 0xB8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	bl nullsub_135
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CEC4: .4byte gUnknown_203B404
	thumb_func_end sub_803CEAC

	thumb_func_start nullsub_135
nullsub_135:
	bx lr
	thumb_func_end nullsub_135

	thumb_func_start sub_803CECC
sub_803CECC:
	push {r4,lr}
	ldr r4, _0803CEEC
	ldr r0, [r4]
	cmp r0, 0
	beq _0803CEE4
	bl nullsub_135
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0803CEE4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CEEC: .4byte gUnknown_203B404
	thumb_func_end sub_803CECC

	thumb_func_start sub_803CEF0
sub_803CEF0:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, _0803CF60
	ldr r0, [r6]
	movs r1, 0x32
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r6]
	ldr r3, [r2, 0x4C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x62
	movs r4, 0
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x4C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x64
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	ldr r0, [r0, 0x4C]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x4C]
	bl sub_80073B8
	ldr r2, _0803CF64
	ldr r0, [r6]
	ldr r3, [r0, 0x4C]
	str r4, [sp]
	movs r0, 0xC
	movs r1, 0
	bl xxx_call_draw_string
	movs r5, 0
	b _0803CF98
	.align 2, 0
_0803CF60: .4byte gUnknown_203B404
_0803CF64: .4byte gUnknown_80F42C0
_0803CF68:
	ldr r0, [r6]
	adds r0, 0x18
	adds r1, r5, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r0, [r6]
	lsls r1, r5, 1
	adds r0, 0x2
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_808D994
	adds r2, r0, 0
	ldr r0, [r6]
	ldr r3, [r0, 0x4C]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	adds r5, 0x1
_0803CF98:
	ldr r0, [r6]
	movs r1, 0x32
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0803CF68
	ldr r4, _0803CFBC
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_80073E0
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x16]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803CFBC: .4byte gUnknown_203B404
	thumb_func_end sub_803CEF0

	thumb_func_start sub_803CFC0
sub_803CFC0:
	push {r4-r7,lr}
	ldr r0, _0803D02C
	ldr r0, [r0]
	movs r2, 0x30
	ldrsh r1, [r0, r2]
	lsls r1, 1
	adds r0, 0x2
	adds r0, r1
	movs r1, 0
	ldrsh r4, [r0, r1]
	movs r0, 0x1
	bl sub_8008C54
	movs r0, 0x1
	bl sub_80073B8
	adds r0, r4, 0
	bl GetDialogueSpriteDataPtr
	adds r5, r0, 0
	ldr r0, [r5, 0x4]
	ldr r6, [r0, 0x4]
	movs r4, 0
	movs r7, 0
_0803CFF0:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r1, [r5, 0x4]
	adds r1, r7
	lsls r2, r4, 2
	ldr r1, [r1]
	adds r1, r2
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0xF
	ble _0803CFF0
	movs r0, 0x1
	adds r1, r6, 0
	movs r2, 0xE
	bl sub_800836C
	adds r0, r5, 0
	bl CloseFile
	movs r0, 0x1
	bl sub_80073E0
	ldr r0, _0803D02C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x16]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D02C: .4byte gUnknown_203B404
	thumb_func_end sub_803CFC0

        .align 2,0
