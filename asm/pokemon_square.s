	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_8019E40
sub_8019E40:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_8091814
	cmp r0, 0
	beq _08019ED4
	ldr r5, _08019EC8
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x34]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _08019ECC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	bl sub_8091814
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, [r5]
	ldr r1, _08019ED0
	ldrh r1, [r1]
	strh r1, [r0, 0x18]
	bl sub_8013984
	bl sub_801A064
	bl sub_801A0D8
	movs r0, 0x1
	b _08019ED6
	.align 2, 0
_08019EC8: .4byte gUnknown_203B214
_08019ECC: .4byte gUnknown_80DB8CC
_08019ED0: .4byte gUnknown_203B218
_08019ED4:
	movs r0, 0
_08019ED6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8019E40

	thumb_func_start sub_8019EDC
sub_8019EDC:
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	bne _08019EF8
	ldr r0, _08019EF4
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _08019FAA
	.align 2, 0
_08019EF4: .4byte gUnknown_203B214
_08019EF8:
	ldr r0, _08019F10
	ldr r0, [r0]
	bl GetKeyPress
	cmp r0, 0x2
	beq _08019F1A
	cmp r0, 0x2
	bgt _08019F14
	cmp r0, 0x1
	beq _08019F24
	b _08019F88
	.align 2, 0
_08019F10: .4byte gUnknown_203B214
_08019F14:
	cmp r0, 0x4
	beq _08019F7E
	b _08019F88
_08019F1A:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08019FAA
_08019F24:
	bl sub_8019FB0
	lsls r0, 24
	lsrs r0, 24
	bl sub_809185C
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _08019F68
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	ldrb r0, [r0, 0x1]
	lsls r0, 8
	ldr r2, _08019F6C
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl sub_8090C7C
	ldr r1, _08019F70
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _08019F74
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _08019F7A
	.align 2, 0
_08019F68: .4byte 0xff00ffff
_08019F6C: .4byte 0xffff00ff
_08019F70: .4byte gUnknown_203B460
_08019F74:
	movs r0, 0
	bl PlayMenuSoundEffect
_08019F7A:
	movs r0, 0x3
	b _08019FAA
_08019F7E:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _08019FAA
_08019F88:
	ldr r0, _08019F9C
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08019FA0
	movs r0, 0
	b _08019FAA
	.align 2, 0
_08019F9C: .4byte gUnknown_203B214
_08019FA0:
	bl sub_801A064
	bl sub_801A0D8
	movs r0, 0x1
_08019FAA:
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8019EDC

	thumb_func_start sub_8019FB0
sub_8019FB0:
	ldr r0, _08019FC8
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	ldrb r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_08019FC8: .4byte gUnknown_203B214
	thumb_func_end sub_8019FB0

	thumb_func_start sub_8019FCC
sub_8019FCC:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801A00C
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8091814
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_801A064
	bl sub_801A0D8
	cmp r4, 0
	beq _0801A006
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801A006:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A00C: .4byte gUnknown_203B214
	thumb_func_end sub_8019FCC

	thumb_func_start sub_801A010
sub_801A010:
	push {r4,r5,lr}
	ldr r4, _0801A058
	ldr r2, [r4]
	cmp r2, 0
	beq _0801A050
	ldr r1, _0801A05C
	ldrh r0, [r2, 0x18]
	strh r0, [r1]
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801A060
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
_0801A050:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A058: .4byte gUnknown_203B214
_0801A05C: .4byte gUnknown_203B218
_0801A060: .4byte gUnknown_80DB8B4
	thumb_func_end sub_801A010

	thumb_func_start sub_801A064
sub_801A064:
	push {r4,lr}
	ldr r4, _0801A0D4
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xA
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
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
_0801A0D4: .4byte gUnknown_203B214
	thumb_func_end sub_801A064

	thumb_func_start sub_801A0D8
sub_801A0D8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xB4
	ldr r4, _0801A1A4
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r1, [r4]
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r0, 0xA
	ldr r2, _0801A1A8
	ldr r3, [r1, 0x34]
	movs r1, 0
	str r1, [sp]
	bl xxx_call_draw_string
	movs r6, 0
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0801A1EC
	adds r7, r4, 0
	add r4, sp, 0xB0
	mov r9, r6
	add r5, sp, 0x54
	add r2, sp, 0x60
	mov r8, r2
_0801A122:
	ldr r0, [r7]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl sub_809185C
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _0801A1AC
	ldr r1, [r4]
	ands r1, r3
	orrs r1, r2
	str r1, [r4]
	ldrb r2, [r0, 0x1]
	lsls r2, 8
	ldr r0, _0801A1B0
	ands r1, r0
	orrs r1, r2
	ldr r0, _0801A1B4
	ands r1, r0
	movs r0, 0x3
	orrs r1, r0
	str r1, [r4]
	movs r1, 0x1
	str r1, [sp, 0x54]
	mov r0, r9
	strb r0, [r5, 0x4]
	movs r0, 0x58
	strh r0, [r5, 0x6]
	strb r1, [r5, 0x8]
	add r0, sp, 0x4
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8090E14
	adds r0, r4, 0
	bl sub_8090C7C
	ldr r1, _0801A1B8
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bgt _0801A1BC
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r9
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0801A1E0
	.align 2, 0
_0801A1A4: .4byte gUnknown_203B214
_0801A1A8: .4byte gUnknown_80DB8E4
_0801A1AC: .4byte 0xff00ffff
_0801A1B0: .4byte 0xffff00ff
_0801A1B4: .4byte 0xffffff00
_0801A1B8: .4byte gUnknown_203B460
_0801A1BC:
	mov r0, r8
	ldr r1, _0801A204
	add r2, sp, 0x4
	bl sub_800D158
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r2, r9
	str r2, [sp]
	movs r0, 0x8
	mov r2, r8
	bl xxx_call_draw_string
_0801A1E0:
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0801A122
_0801A1EC:
	ldr r0, _0801A208
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0xB4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A204: .4byte gUnknown_80DB8EC
_0801A208: .4byte gUnknown_203B214
	thumb_func_end sub_801A0D8

	thumb_func_start sub_801A20C
sub_801A20C:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_8091A48
	cmp r0, 0
	beq _0801A2A0
	ldr r5, _0801A294
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x34]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801A298
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	bl sub_8091A48
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, [r5]
	ldr r1, _0801A29C
	ldrh r1, [r1]
	strh r1, [r0, 0x18]
	bl sub_8013984
	bl sub_801A430
	bl sub_801A4A4
	movs r0, 0x1
	b _0801A2A2
	.align 2, 0
_0801A294: .4byte gUnknown_203B21C
_0801A298: .4byte gUnknown_80DB914
_0801A29C: .4byte gUnknown_203B220
_0801A2A0:
	movs r0, 0
_0801A2A2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801A20C

	thumb_func_start sub_801A2A8
sub_801A2A8:
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	bne _0801A2C4
	ldr r0, _0801A2C0
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0801A376
	.align 2, 0
_0801A2C0: .4byte gUnknown_203B21C
_0801A2C4:
	ldr r0, _0801A2DC
	ldr r0, [r0]
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801A2E6
	cmp r0, 0x2
	bgt _0801A2E0
	cmp r0, 0x1
	beq _0801A2F0
	b _0801A354
	.align 2, 0
_0801A2DC: .4byte gUnknown_203B21C
_0801A2E0:
	cmp r0, 0x4
	beq _0801A34A
	b _0801A354
_0801A2E6:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801A376
_0801A2F0:
	bl sub_801A37C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091A90
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _0801A334
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	ldrb r0, [r0, 0x1]
	lsls r0, 8
	ldr r2, _0801A338
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	bl sub_8090C7C
	ldr r1, _0801A33C
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _0801A340
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801A346
	.align 2, 0
_0801A334: .4byte 0xff00ffff
_0801A338: .4byte 0xffff00ff
_0801A33C: .4byte gUnknown_203B460
_0801A340:
	movs r0, 0
	bl PlayMenuSoundEffect
_0801A346:
	movs r0, 0x3
	b _0801A376
_0801A34A:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801A376
_0801A354:
	ldr r0, _0801A368
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801A36C
	movs r0, 0
	b _0801A376
	.align 2, 0
_0801A368: .4byte gUnknown_203B21C
_0801A36C:
	bl sub_801A430
	bl sub_801A4A4
	movs r0, 0x1
_0801A376:
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_801A2A8

	thumb_func_start sub_801A37C
sub_801A37C:
	ldr r0, _0801A394
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	ldrb r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_0801A394: .4byte gUnknown_203B21C
	thumb_func_end sub_801A37C

	thumb_func_start sub_801A398
sub_801A398:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801A3D8
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8091A48
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_801A430
	bl sub_801A4A4
	cmp r4, 0
	beq _0801A3D2
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801A3D2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A3D8: .4byte gUnknown_203B21C
	thumb_func_end sub_801A398

	thumb_func_start sub_801A3DC
sub_801A3DC:
	push {r4,r5,lr}
	ldr r4, _0801A424
	ldr r2, [r4]
	cmp r2, 0
	beq _0801A41C
	ldr r1, _0801A428
	ldrh r0, [r2, 0x18]
	strh r0, [r1]
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801A42C
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
_0801A41C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A424: .4byte gUnknown_203B21C
_0801A428: .4byte gUnknown_203B220
_0801A42C: .4byte gUnknown_80DB8FC
	thumb_func_end sub_801A3DC

	thumb_func_start sub_801A430
sub_801A430:
	push {r4,lr}
	ldr r4, _0801A4A0
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xA
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
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
_0801A4A0: .4byte gUnknown_203B21C
	thumb_func_end sub_801A430

	thumb_func_start sub_801A4A4
sub_801A4A4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xB4
	ldr r4, _0801A570
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r1, [r4]
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r0, 0xA
	ldr r2, _0801A574
	ldr r3, [r1, 0x34]
	movs r1, 0
	str r1, [sp]
	bl xxx_call_draw_string
	movs r6, 0
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0801A5B8
	adds r7, r4, 0
	add r4, sp, 0xB0
	mov r9, r6
	add r5, sp, 0x54
	add r2, sp, 0x60
	mov r8, r2
_0801A4EE:
	ldr r0, [r7]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r6
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091A90
	ldrb r2, [r0]
	lsls r2, 16
	ldr r3, _0801A578
	ldr r1, [r4]
	ands r1, r3
	orrs r1, r2
	str r1, [r4]
	ldrb r2, [r0, 0x1]
	lsls r2, 8
	ldr r0, _0801A57C
	ands r1, r0
	orrs r1, r2
	ldr r0, _0801A580
	ands r1, r0
	movs r0, 0x3
	orrs r1, r0
	str r1, [r4]
	movs r1, 0x1
	str r1, [sp, 0x54]
	mov r0, r9
	strb r0, [r5, 0x4]
	movs r0, 0x58
	strh r0, [r5, 0x6]
	strb r1, [r5, 0x8]
	add r0, sp, 0x4
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8090E14
	adds r0, r4, 0
	bl sub_8090C7C
	ldr r1, _0801A584
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bgt _0801A588
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r9
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0801A5AC
	.align 2, 0
_0801A570: .4byte gUnknown_203B21C
_0801A574: .4byte gUnknown_80DB92C
_0801A578: .4byte 0xff00ffff
_0801A57C: .4byte 0xffff00ff
_0801A580: .4byte 0xffffff00
_0801A584: .4byte gUnknown_203B460
_0801A588:
	mov r0, r8
	ldr r1, _0801A5D0
	add r2, sp, 0x4
	bl sub_800D158
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r2, r9
	str r2, [sp]
	movs r0, 0x8
	mov r2, r8
	bl xxx_call_draw_string
_0801A5AC:
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0801A4EE
_0801A5B8:
	ldr r0, _0801A5D4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0xB4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A5D0: .4byte gUnknown_80DB934
_0801A5D4: .4byte gUnknown_203B21C
	thumb_func_end sub_801A4A4

	thumb_func_start sub_801A5D8
sub_801A5D8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	mov r8, r3
	bl sub_8090A34
	cmp r0, 0
	bne _0801A5F2
	movs r0, 0
	b _0801A6CC
_0801A5F2:
	ldr r5, _0801A6D8
	ldr r0, [r5]
	cmp r0, 0
	bne _0801A604
	movs r0, 0xF4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0801A604:
	ldr r0, [r5]
	str r4, [r0]
	bl sub_80910B4
	bl sub_801AE84
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x88
	str r6, [r1]
	adds r2, r0, 0
	adds r2, 0x8C
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x90
	adds r1, r0, r1
	str r1, [r2]
	adds r0, 0x90
	bl sub_8006518
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x90
	ldr r0, _0801A6DC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x8C
	ldr r1, [r0]
	adds r0, 0x64
	str r0, [r1, 0x14]
	cmp r7, 0
	beq _0801A66E
	subs r0, 0x68
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x98
	adds r1, r0
	ldr r0, [r7]
	str r0, [r1]
_0801A66E:
	ldr r0, [r5]
	adds r0, 0x8C
	ldr r0, [r0]
	mov r1, r8
	bl sub_8012D08
	movs r0, 0x1
	bl sub_8099690
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x90
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x54
	bl sub_8090A34
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013818
	ldr r2, [r5]
	ldr r0, _0801A6E0
	ldrh r1, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	strh r1, [r0]
	ldr r0, _0801A6E4
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x72
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x54
	bl sub_8013984
	bl sub_801A998
	bl sub_801A9E0
	movs r0, 0x1
_0801A6CC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801A6D8: .4byte gUnknown_203B224
_0801A6DC: .4byte gUnknown_80DB95C
_0801A6E0: .4byte gUnknown_203B228
_0801A6E4: .4byte gUnknown_203B22A
	thumb_func_end sub_801A5D8

	thumb_func_start sub_801A6E8
sub_801A6E8:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	cmp r0, 0
	bne _0801A704
	ldr r0, _0801A700
	ldr r0, [r0]
	adds r0, 0x54
	bl sub_8013660
	movs r0, 0
	b _0801A8A2
	.align 2, 0
_0801A700: .4byte gUnknown_203B224
_0801A704:
	ldr r0, _0801A720
	ldr r0, [r0]
	adds r0, 0x54
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0x5
	bls _0801A716
	b _0801A87C
_0801A716:
	lsls r0, 2
	ldr r1, _0801A724
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A720: .4byte gUnknown_203B224
_0801A724: .4byte _0801A728
	.align 2, 0
_0801A728:
	.4byte _0801A74A
	.4byte _0801A740
	.4byte _0801A864
	.4byte _0801A806
	.4byte _0801A810
	.4byte _0801A810
_0801A740:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801A8A2
_0801A74A:
	ldr r1, _0801A760
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x5
	bhi _0801A802
	lsls r0, 2
	ldr r1, _0801A764
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A760: .4byte gUnknown_203B224
_0801A764: .4byte _0801A768
	.align 2, 0
_0801A768:
	.4byte _0801A780
	.4byte _0801A780
	.4byte _0801A780
	.4byte _0801A794
	.4byte _0801A7AC
	.4byte _0801A7FC
_0801A780:
	ldr r4, [r4]
	bl sub_801A8AC
	lsls r0, 2
	adds r4, 0x4
	adds r4, r0
	ldr r0, [r4]
	cmp r0, 0
	bne _0801A7F4
	b _0801A7E2
_0801A794:
	bl sub_801AEA8
	cmp r0, 0
	bne _0801A7E2
	bl sub_801A8AC
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801A7E2
	b _0801A7F4
_0801A7AC:
	ldr r5, _0801A7EC
	ldr r4, [r5]
	bl sub_801A8AC
	lsls r0, 2
	adds r4, r0
	ldr r0, [r4]
	str r0, [sp]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	beq _0801A7F4
	mov r0, sp
	bl sub_8090CCC
	ldr r1, [r5]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	adds r0, r1
	ldr r1, _0801A7F0
	cmp r0, r1
	bgt _0801A7F4
_0801A7E2:
	movs r0, 0
	bl PlayMenuSoundEffect
	b _0801A802
	.align 2, 0
_0801A7EC: .4byte gUnknown_203B460
_0801A7F0: .4byte 0x0001869f
_0801A7F4:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801A802
_0801A7FC:
	movs r0, 0
	bl PlayMenuSoundEffect
_0801A802:
	movs r0, 0x3
	b _0801A8A2
_0801A806:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801A8A2
_0801A810:
	ldr r4, _0801A858
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0801A87C
	bl sub_801A8AC
	adds r1, r0, 0
	ldr r0, [r4]
	lsls r5, r1, 2
	adds r0, 0x4
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0
	bne _0801A83A
	adds r0, r1, 0
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	beq _0801A85C
_0801A83A:
	movs r0, 0x6
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	adds r2, r0, 0x4
	adds r2, r5
	ldr r1, [r2]
	movs r3, 0x1
	eors r1, r3
	str r1, [r2]
	adds r0, 0x54
	movs r1, 0
	bl sub_80138B8
	b _0801A89C
	.align 2, 0
_0801A858: .4byte gUnknown_203B224
_0801A85C:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801A87C
_0801A864:
	ldr r0, _0801A894
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0801A87C
	movs r0, 0x5
	bl PlayMenuSoundEffect
	bl sub_801AEF8
	bl sub_801A9E0
_0801A87C:
	ldr r0, _0801A894
	ldr r0, [r0]
	adds r0, 0x54
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801A898
	movs r0, 0
	b _0801A8A2
	.align 2, 0
_0801A894: .4byte gUnknown_203B224
_0801A898:
	bl sub_801A998
_0801A89C:
	bl sub_801A9E0
	movs r0, 0x1
_0801A8A2:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801A6E8

	thumb_func_start sub_801A8AC
sub_801A8AC:
	ldr r0, _0801A8CC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x72
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x6C
	movs r2, 0
	ldrsh r1, [r1, r2]
	adds r0, r1
	bx lr
	.align 2, 0
_0801A8CC: .4byte gUnknown_203B224
	thumb_func_end sub_801A8AC

	thumb_func_start sub_801A8D0
sub_801A8D0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl sub_8099690
	bl ResetUnusedInputStruct
	ldr r5, _0801A924
	ldr r0, [r5]
	adds r0, 0x90
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_80910B4
	bl sub_8090A34
	adds r1, r0, 0
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x76
	strh r1, [r2]
	adds r0, 0x54
	bl sub_8013984
	bl sub_801A998
	bl sub_801A9E0
	cmp r4, 0
	beq _0801A91C
	ldr r0, [r5]
	adds r0, 0x54
	bl AddMenuCursorSprite
_0801A91C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A924: .4byte gUnknown_203B224
	thumb_func_end sub_801A8D0

	thumb_func_start sub_801A928
sub_801A928:
	push {r4,r5,lr}
	ldr r4, _0801A988
	ldr r2, [r4]
	cmp r2, 0
	beq _0801A980
	ldr r1, _0801A98C
	adds r0, r2, 0
	adds r0, 0x6C
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0801A990
	adds r0, r2, 0
	adds r0, 0x72
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x88
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x90
	ldr r0, _0801A994
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r0, 0
	bl sub_8099690
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x90
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801A980:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A988: .4byte gUnknown_203B224
_0801A98C: .4byte gUnknown_203B228
_0801A990: .4byte gUnknown_203B22A
_0801A994: .4byte gUnknown_80DB944
	thumb_func_end sub_801A928

	thumb_func_start sub_801A998
sub_801A998:
	push {r4,lr}
	ldr r4, _0801A9DC
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x74
	ldrh r1, [r1]
	adds r0, 0xF0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x72
	ldrh r1, [r1]
	adds r0, 0xF1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xF2
	movs r1, 0xB
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xF3
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x90
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801A9DC: .4byte gUnknown_203B224
	thumb_func_end sub_801A998

	thumb_func_start sub_801A9E0
sub_801A9E0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xCC
	ldr r4, _0801AA2C
	ldr r0, [r4]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_80073B8
	ldr r4, [r4]
	adds r1, r4, 0
	adds r1, 0x72
	movs r2, 0
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r5, r0, 0
	adds r5, 0xA
	movs r3, 0
	ldrsh r1, [r1, r3]
	cmp r1, 0
	bne _0801AA34
	ldr r2, _0801AA30
	adds r0, r4, 0
	adds r0, 0x88
	ldr r3, [r0]
	str r1, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	b _0801AA48
	.align 2, 0
_0801AA2C: .4byte gUnknown_203B224
_0801AA30: .4byte gTeamToolboxA
_0801AA34:
	ldr r2, _0801AA58
	adds r0, r4, 0
	adds r0, 0x88
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
_0801AA48:
	movs r7, 0
	ldr r1, _0801AA5C
	ldr r0, [r1]
	adds r0, 0x6E
	movs r4, 0
	ldrsh r0, [r0, r4]
	b _0801AD0A
	.align 2, 0
_0801AA58: .4byte gTeamToolboxB
_0801AA5C: .4byte gUnknown_203B224
_0801AA60:
	ldr r2, [r1]
	adds r0, r2, 0
	adds r0, 0x72
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r4, 0
	ldrsh r0, [r0, r4]
	muls r0, r1
	adds r0, r7
	mov r8, r0
	ldr r0, _0801AA9C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, 2
	adds r0, r1
	ldr r0, [r0]
	add r1, sp, 0xC8
	str r0, [r1]
	ldr r0, [r2]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _0801AA90
	b _0801ACC4
_0801AA90:
	lsls r0, 2
	ldr r1, _0801AAA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801AA9C: .4byte gUnknown_203B460
_0801AAA0: .4byte _0801AAA4
	.align 2, 0
_0801AAA4:
	.4byte _0801AABC
	.4byte _0801AAE4
	.4byte _0801AAE4
	.4byte _0801AB18
	.4byte _0801AB90
	.4byte _0801AC50
_0801AABC:
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	ldr r4, _0801AAE0
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	b _0801AC8C
	.align 2, 0
_0801AAE0: .4byte gUnknown_203B224
_0801AAE4:
	add r2, sp, 0x54
	movs r5, 0
	str r5, [sp, 0x54]
	strb r5, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r1, sp, 0xC8
	add r0, sp, 0x4
	bl sub_8090E14
	ldr r4, _0801AB14
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
	b _0801AC8C
	.align 2, 0
_0801AB14: .4byte gUnknown_203B224
_0801AB18:
	add r2, sp, 0x60
	movs r6, 0
	str r6, [sp, 0x60]
	strb r6, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r1, sp, 0xC8
	add r0, sp, 0x4
	bl sub_8090E14
	ldr r5, _0801AB60
	ldr r0, [r5]
	mov r4, r8
	lsls r1, r4, 2
	adds r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0801AB4E
	mov r0, r8
	bl sub_801ADA0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0801AB64
_0801AB4E:
	ldr r0, [r5]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r5]
	b _0801AC86
	.align 2, 0
_0801AB60: .4byte gUnknown_203B224
_0801AB64:
	ldr r0, _0801AB88
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r0, [r5]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AB8C
	ldr r0, [r5]
	adds r0, 0x88
	ldr r3, [r0]
	str r4, [sp]
	b _0801AC3C
	.align 2, 0
_0801AB88: .4byte gUnknown_202DE58
_0801AB8C: .4byte gUnknown_80DB994
_0801AB90:
	ldrb r0, [r4, 0x2]
	bl sub_80914E4
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0801AC10
	add r2, sp, 0x6C
	movs r1, 0x3
	str r1, [sp, 0x6C]
	movs r6, 0
	strb r6, [r2, 0x4]
	movs r0, 0x58
	strh r0, [r2, 0x6]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r1, [r4]
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_8090E14
	adds r0, r4, 0
	bl sub_8090CCC
	ldr r1, _0801AC00
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	adds r0, r1
	ldr r1, _0801AC04
	cmp r0, r1
	ble _0801AC76
	add r5, sp, 0x78
	ldr r1, _0801AC08
	adds r0, r5, 0
	add r2, sp, 0x4
	bl sub_800D158
	ldr r4, _0801AC0C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r6, [sp]
	movs r0, 0x8
	adds r2, r5, 0
	bl xxx_call_draw_string
	b _0801ACC4
	.align 2, 0
_0801AC00: .4byte gUnknown_203B460
_0801AC04: .4byte 0x0001869f
_0801AC08: .4byte gUnknown_80DB9A0
_0801AC0C: .4byte gUnknown_203B224
_0801AC10:
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	ldr r0, _0801AC44
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r4, _0801AC48
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AC4C
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
_0801AC3C:
	movs r0, 0x8
	bl sub_8014FF0
	b _0801ACC4
	.align 2, 0
_0801AC44: .4byte gUnknown_202DE58
_0801AC48: .4byte gUnknown_203B224
_0801AC4C: .4byte gUnknown_80DB994
_0801AC50:
	add r2, sp, 0x78
	movs r6, 0
	str r6, [sp, 0x78]
	strb r6, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0x8]
	strb r0, [r4]
	add r4, sp, 0xC8
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_8090E14
	ldrb r0, [r4, 0x2]
	bl sub_8091764
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0801AC9C
_0801AC76:
	ldr r4, _0801AC98
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r4]
_0801AC86:
	adds r0, 0x88
	ldr r3, [r0]
	str r6, [sp]
_0801AC8C:
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _0801ACC4
	.align 2, 0
_0801AC98: .4byte gUnknown_203B224
_0801AC9C:
	ldr r0, _0801AD28
	add r1, sp, 0x4
	movs r2, 0x50
	bl strncpy
	ldr r4, _0801AD2C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, _0801AD30
	ldr r0, [r4]
	adds r0, 0x88
	ldr r3, [r0]
	str r5, [sp]
	movs r0, 0x8
	bl sub_8014FF0
_0801ACC4:
	mov r0, r8
	bl sub_801AED0
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801ACFE
	ldr r4, _0801AD2C
	ldr r0, [r4]
	adds r0, 0x54
	adds r1, r7, 0
	bl sub_8013800
	adds r2, r0, 0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r0, [r0]
	adds r1, 0x8C
	ldr r1, [r1]
	movs r4, 0xC
	ldrsh r3, [r1, r4]
	subs r3, 0x2
	lsls r3, 3
	movs r1, 0xA
	str r1, [sp]
	movs r1, 0x8
	bl sub_8007B7C
_0801ACFE:
	adds r7, 0x1
	ldr r1, _0801AD2C
	ldr r0, [r1]
	adds r0, 0x6E
	movs r2, 0
	ldrsh r0, [r0, r2]
_0801AD0A:
	adds r2, r1, 0
	cmp r7, r0
	bge _0801AD12
	b _0801AA60
_0801AD12:
	ldr r0, [r2]
	adds r0, 0x88
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0xCC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD28: .4byte gUnknown_202DE58
_0801AD2C: .4byte gUnknown_203B224
_0801AD30: .4byte gUnknown_80DB994
	thumb_func_end sub_801A9E0

	thumb_func_start sub_801AD34
sub_801AD34:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	bl sub_8008C54
	adds r0, r4, 0
	bl sub_80073B8
	ldr r2, _0801AD98
	movs r6, 0
	str r6, [sp]
	movs r0, 0x6
	movs r1, 0
	adds r3, r4, 0
	bl xxx_call_draw_string
	bl sub_8090A34
	adds r2, r0, 0
	movs r5, 0x7
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x12
	movs r1, 0xD
	movs r3, 0x2
	bl sub_8012BC4
	ldr r2, _0801AD9C
	str r6, [sp]
	movs r0, 0x16
	movs r1, 0xD
	adds r3, r4, 0
	bl xxx_call_draw_string
	str r5, [sp]
	str r4, [sp, 0x4]
	movs r0, 0x2B
	movs r1, 0xD
	movs r2, 0x14
	movs r3, 0x2
	bl sub_8012BC4
	adds r0, r4, 0
	bl sub_80073E0
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD98: .4byte gUnknown_80DB9A8
_0801AD9C: .4byte gUnknown_80DB9B0
	thumb_func_end sub_801AD34

	thumb_func_start sub_801ADA0
sub_801ADA0:
	push {r4-r6,lr}
	ldr r5, _0801ADEC
	ldr r1, [r5]
	lsls r0, 2
	adds r1, r0
	ldr r6, [r1]
	lsls r4, r6, 8
	lsrs r0, r4, 24
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801AE12
	lsrs r0, r4, 24
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0801ADF4
	lsrs r0, r4, 24
	bl sub_801AE24
	ldr r2, [r5]
	lsrs r1, r4, 24
	lsls r1, 1
	adds r2, 0x50
	adds r2, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r2, [r2]
	adds r0, r2
	lsrs r1, r6, 8
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1
	ldr r1, _0801ADF0
	b _0801AE0E
	.align 2, 0
_0801ADEC: .4byte gUnknown_203B460
_0801ADF0: .4byte 0x000003e7
_0801ADF4:
	lsrs r0, r4, 24
	bl sub_801AE24
	ldr r2, [r5]
	lsrs r1, r4, 24
	lsls r1, 1
	adds r2, 0x50
	adds r2, r1
	lsls r0, 16
	lsrs r0, 16
	ldrh r2, [r2]
	adds r0, r2
	ldr r1, _0801AE18
_0801AE0E:
	cmp r0, r1
	ble _0801AE1C
_0801AE12:
	movs r0, 0
	b _0801AE1E
	.align 2, 0
_0801AE18: .4byte 0x000003e6
_0801AE1C:
	movs r0, 0x1
_0801AE1E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801ADA0

	thumb_func_start sub_801AE24
sub_801AE24:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	movs r6, 0
	b _0801AE74
_0801AE2E:
	ldr r0, _0801AE64
	ldr r0, [r0]
	lsls r1, r6, 2
	adds r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0801AE72
	ldr r0, _0801AE68
	ldr r0, [r0]
	adds r0, r1
	ldr r4, [r0]
	lsls r1, r4, 8
	lsrs r0, r1, 24
	cmp r0, r7
	bne _0801AE72
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0801AE6C
	lsrs r0, r4, 8
	lsls r0, 24
	lsrs r0, 24
	adds r0, r5, r0
	b _0801AE6E
	.align 2, 0
_0801AE64: .4byte gUnknown_203B224
_0801AE68: .4byte gUnknown_203B460
_0801AE6C:
	adds r0, r5, 0x1
_0801AE6E:
	lsls r0, 16
	lsrs r5, r0, 16
_0801AE72:
	adds r6, 0x1
_0801AE74:
	bl sub_8090A34
	cmp r6, r0
	blt _0801AE2E
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801AE24

	thumb_func_start sub_801AE84
sub_801AE84:
	push {r4,lr}
	movs r2, 0
	ldr r4, _0801AEA4
	movs r3, 0
_0801AE8C:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x4
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0x13
	ble _0801AE8C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801AEA4: .4byte gUnknown_203B224
	thumb_func_end sub_801AE84

	thumb_func_start sub_801AEA8
sub_801AEA8:
	push {lr}
	movs r3, 0
	ldr r0, _0801AECC
	ldr r0, [r0]
	adds r1, r0, 0x4
	movs r2, 0x13
_0801AEB4:
	ldr r0, [r1]
	cmp r0, 0
	beq _0801AEBC
	adds r3, 0x1
_0801AEBC:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0801AEB4
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0801AECC: .4byte gUnknown_203B224
	thumb_func_end sub_801AEA8

	thumb_func_start sub_801AED0
sub_801AED0:
	ldr r1, _0801AEE0
	ldr r1, [r1]
	lsls r0, 2
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0801AEE0: .4byte gUnknown_203B224
	thumb_func_end sub_801AED0

	thumb_func_start sub_801AEE4
sub_801AEE4:
	ldr r2, _0801AEF4
	ldr r2, [r2]
	lsls r0, 2
	adds r2, 0x4
	adds r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_0801AEF4: .4byte gUnknown_203B224
	thumb_func_end sub_801AEE4

	thumb_func_start sub_801AEF8
sub_801AEF8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	mov r9, r0
	b _0801AF78
_0801AF08:
	movs r1, 0x1
	add r1, r9
	mov r8, r1
	mov r7, r8
	b _0801AF6E
_0801AF12:
	ldr r2, _0801AF90
	ldr r0, [r2]
	mov r1, r9
	lsls r6, r1, 2
	adds r0, r6
	ldrb r0, [r0, 0x2]
	str r2, [sp]
	bl sub_8090D44
	adds r4, r0, 0
	ldr r2, [sp]
	ldr r0, [r2]
	lsls r5, r7, 2
	adds r0, r5
	ldrb r0, [r0, 0x2]
	bl sub_8090D44
	ldr r2, [sp]
	cmp r4, r0
	bgt _0801AF4C
	cmp r4, r0
	bne _0801AF6C
	ldr r0, [r2]
	adds r1, r0, r6
	adds r0, r5
	ldrb r1, [r1, 0x1]
	ldrb r0, [r0, 0x1]
	cmp r1, r0
	bcs _0801AF6C
_0801AF4C:
	ldr r0, [r2]
	adds r2, r0, r6
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
	ldr r0, _0801AF94
	ldr r0, [r0]
	adds r0, 0x4
	adds r2, r0, r6
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
_0801AF6C:
	adds r7, 0x1
_0801AF6E:
	bl sub_8090A34
	cmp r7, r0
	blt _0801AF12
	mov r9, r8
_0801AF78:
	bl sub_8090A34
	subs r0, 0x1
	cmp r9, r0
	blt _0801AF08
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AF90: .4byte gUnknown_203B460
_0801AF94: .4byte gUnknown_203B224
	thumb_func_end sub_801AEF8

	thumb_func_start sub_801AF98
sub_801AF98:
	ldr r0, _0801AFA0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0801AFA0: .4byte gUnknown_203B224
	thumb_func_end sub_801AF98

	thumb_func_start sub_801AFA4
sub_801AFA4:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _0801AFEC
	movs r0, 0xA4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r4, [r0, 0x4]
	ldr r1, _0801AFF0
	ldr r1, [r1]
	lsls r4, 2
	adds r1, r4
	ldrb r1, [r1, 0x2]
	strb r1, [r0, 0x8]
	ldr r0, [r5]
	ldrb r0, [r0, 0x8]
	bl sub_80913CC
	ldr r1, [r5]
	strh r0, [r1, 0xA]
	ldr r0, _0801AFF4
	ldrh r1, [r1, 0xA]
	bl sub_8092C84
	movs r0, 0
	bl sub_8099690
	bl sub_801B2F4
	cmp r0, 0
	bne _0801AFF8
	movs r0, 0x3
	bl sub_801B064
	b _0801B004
	.align 2, 0
_0801AFEC: .4byte gUnknown_203B22C
_0801AFF0: .4byte gUnknown_203B460
_0801AFF4: .4byte gUnknown_202E1C8
_0801AFF8:
	ldr r1, [r5]
	movs r0, 0x4
	str r0, [r1, 0x60]
	movs r0, 0
	bl sub_801B064
_0801B004:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801AFA4

	thumb_func_start sub_801B00C
sub_801B00C:
	push {lr}
	ldr r0, _0801B024
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801B036
	cmp r0, 0x1
	bgt _0801B028
	cmp r0, 0
	beq _0801B030
	b _0801B03C
	.align 2, 0
_0801B024: .4byte gUnknown_203B22C
_0801B028:
	cmp r0, 0x4
	bne _0801B03C
	movs r0, 0x3
	b _0801B042
_0801B030:
	bl sub_801B200
	b _0801B040
_0801B036:
	bl sub_801B2AC
	b _0801B040
_0801B03C:
	bl sub_801B2D8
_0801B040:
	movs r0, 0
_0801B042:
	pop {r1}
	bx r1
	thumb_func_end sub_801B00C

	thumb_func_start sub_801B048
sub_801B048:
	push {r4,lr}
	ldr r4, _0801B060
	ldr r0, [r4]
	cmp r0, 0
	beq _0801B05A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801B05A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B060: .4byte gUnknown_203B22C
	thumb_func_end sub_801B048

	thumb_func_start sub_801B064
sub_801B064:
	push {lr}
	ldr r1, _0801B078
	ldr r1, [r1]
	str r0, [r1]
	bl nullsub_37
	bl sub_801B080
	pop {r0}
	bx r0
	.align 2, 0
_0801B078: .4byte gUnknown_203B22C
	thumb_func_end sub_801B064

	thumb_func_start nullsub_37
nullsub_37:
	bx lr
	thumb_func_end nullsub_37

	thumb_func_start sub_801B080
sub_801B080:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _0801B09C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _0801B168
	lsls r0, 2
	ldr r1, _0801B0A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B09C: .4byte gUnknown_203B22C
_0801B0A0: .4byte _0801B0A4
	.align 2, 0
_0801B0A4:
	.4byte _0801B0B8
	.4byte _0801B0E8
	.4byte _0801B0FC
	.4byte _0801B15C
	.4byte _0801B168
_0801B0B8:
	bl sub_801B178
	ldr r0, _0801B0E0
	ldr r1, _0801B0E4
	ldr r3, [r1]
	ldr r2, [r3, 0x60]
	adds r3, 0x64
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _0801B168
	.align 2, 0
_0801B0E0: .4byte gUnknown_80DB9BC
_0801B0E4: .4byte gUnknown_203B22C
_0801B0E8:
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x58
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r2, 0xC
	movs r0, 0x2
	bl DisplayGulpinDialogueSprite
	b _0801B168
_0801B0FC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldr r1, [r1, 0x5C]
	adds r1, 0x2C
	bl sub_8094060
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_80915A0
	lsls r0, 24
	cmp r0, 0
	bne _0801B138
	ldr r3, _0801B150
	ldr r1, [r3]
	ldr r2, [r4]
	ldr r0, [r2, 0x4]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r2, 0x8]
	subs r0, 0x7D
	strb r0, [r1, 0x1]
	ldr r1, [r3]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	lsls r0, 2
	adds r1, r0
	movs r0, 0x7C
	strb r0, [r1, 0x2]
_0801B138:
	movs r0, 0x9C
	lsls r0, 1
	bl PlaySound
	ldr r0, _0801B154
	ldr r3, _0801B158
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0801B168
	.align 2, 0
_0801B150: .4byte gUnknown_203B460
_0801B154: .4byte gUnknown_80DB9E4
_0801B158: .4byte 0x00000121
_0801B15C:
	ldr r0, _0801B170
	ldr r3, _0801B174
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0801B168:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B170: .4byte gUnknown_80DBA0C
_0801B174: .4byte 0x00000121
	thumb_func_end sub_801B080

	thumb_func_start sub_801B178
sub_801B178:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	ldr r1, _0801B1F4
	ldr r0, [r1]
	ldr r0, [r0, 0x4C]
	cmp r5, r0
	bge _0801B1D2
	ldr r0, _0801B1F8
	mov r8, r0
	adds r7, r1, 0
	movs r6, 0
_0801B192:
	ldr r4, _0801B1FC
	adds r4, r6, r4
	ldr r0, [r7]
	lsls r1, r5, 1
	adds r0, 0x50
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	adds r0, r4, 0
	bl sub_808DA34
	ldr r2, [r7]
	lsls r1, r5, 3
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r1
	str r4, [r0]
	adds r0, r2, 0
	adds r0, 0x68
	adds r0, r1
	adds r1, r5, 0x4
	str r1, [r0]
	adds r6, 0x50
	adds r5, 0x1
	ldr r0, [r2, 0x4C]
	cmp r5, r0
	blt _0801B192
_0801B1D2:
	ldr r0, _0801B1F4
	ldr r2, [r0]
	lsls r3, r5, 3
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r3
	movs r1, 0
	str r1, [r0]
	adds r2, 0x68
	adds r2, r3
	movs r0, 0x1
	str r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B1F4: .4byte gUnknown_203B22C
_0801B1F8: .4byte gRecruitedPokemonRef
_0801B1FC: .4byte gAvailablePokemonNames
	thumb_func_end sub_801B178

	thumb_func_start sub_801B200
sub_801B200:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801B2A4
	ldr r5, _0801B228
	ldr r3, [r5]
	ldr r0, [sp]
	str r0, [r3, 0x60]
	ldr r1, [sp]
	cmp r1, 0
	beq _0801B2A4
	cmp r1, 0x1
	bne _0801B22C
	movs r0, 0x4
	bl sub_801B064
	b _0801B2A4
	.align 2, 0
_0801B228: .4byte gUnknown_203B22C
_0801B22C:
	subs r1, 0x4
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	adds r1, r3, 0
	adds r1, 0x58
	strh r0, [r1]
	ldr r2, _0801B26C
	movs r0, 0
	ldrsh r1, [r1, r0]
	movs r0, 0x58
	muls r0, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r3, 0x5C]
	ldr r0, _0801B270
	bl sub_808DA34
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xC
	ldr r1, [r1, 0x5C]
	adds r1, 0x2C
	bl sub_809401C
	movs r4, 0
	adds r6, r5, 0
	movs r5, 0xC
	b _0801B278
	.align 2, 0
_0801B26C: .4byte gRecruitedPokemonRef
_0801B270: .4byte gUnknown_202E218
_0801B274:
	adds r5, 0x8
	adds r4, 0x1
_0801B278:
	cmp r4, 0x7
	bgt _0801B292
	ldr r3, [r6]
	adds r2, r3, r5
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801B274
	ldrh r1, [r3, 0xA]
	adds r0, r2, 0
	bl sub_8092AD4
_0801B292:
	cmp r4, 0x3
	ble _0801B29E
	movs r0, 0x1
	bl sub_801B064
	b _0801B2A4
_0801B29E:
	movs r0, 0x2
	bl sub_801B064
_0801B2A4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801B200

	thumb_func_start sub_801B2AC
sub_801B2AC:
	push {lr}
	bl sub_801E8C0
	cmp r0, 0x2
	beq _0801B2CA
	cmp r0, 0x2
	bcc _0801B2D4
	cmp r0, 0x3
	bne _0801B2D4
	bl sub_801E93C
	movs r0, 0x2
	bl sub_801B064
	b _0801B2D4
_0801B2CA:
	bl sub_801E93C
	movs r0, 0
	bl sub_801B064
_0801B2D4:
	pop {r0}
	bx r0
	thumb_func_end sub_801B2AC

	thumb_func_start sub_801B2D8
sub_801B2D8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801B2EC
	movs r0, 0x4
	bl sub_801B064
_0801B2EC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801B2D8

	thumb_func_start sub_801B2F4
sub_801B2F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r0, sp
	bl sub_808D580
	adds r6, r0, 0
	ldr r2, _0801B36C
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x4C]
	movs r5, 0
	cmp r5, r6
	bge _0801B35A
	ldr r0, _0801B370
	mov r8, r0
	adds r7, r2, 0
	mov r4, sp
_0801B31A:
	ldr r1, [r4]
	movs r0, 0x58
	muls r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	ldr r0, [r7]
	ldrh r0, [r0, 0xA]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	bl sub_808E190
	lsls r0, 24
	cmp r0, 0
	beq _0801B352
	ldr r2, [r7]
	ldr r0, [r2, 0x4C]
	lsls r0, 1
	adds r1, r2, 0
	adds r1, 0x50
	adds r1, r0
	ldr r0, [r4]
	strh r0, [r1]
	ldr r0, [r2, 0x4C]
	cmp r0, 0x3
	bgt _0801B35A
	adds r0, 0x1
	str r0, [r2, 0x4C]
_0801B352:
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r6
	blt _0801B31A
_0801B35A:
	ldr r0, _0801B36C
	ldr r0, [r0]
	ldr r0, [r0, 0x4C]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B36C: .4byte gUnknown_203B22C
_0801B370: .4byte gRecruitedPokemonRef
	thumb_func_end sub_801B2F4

	thumb_func_start sub_801B374
sub_801B374:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0801B3A8
	ldr r4, [r1]
	bl sub_80913CC
	lsls r0, 16
	lsrs r6, r0, 16
	movs r5, 0
_0801B388:
	ldrh r0, [r4]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801B3AC
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	adds r0, r6, 0
	bl sub_808E190
	lsls r0, 24
	cmp r0, 0
	beq _0801B3AC
	movs r0, 0
	b _0801B3BA
	.align 2, 0
_0801B3A8: .4byte gRecruitedPokemonRef
_0801B3AC:
	adds r5, 0x1
	adds r4, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0801B388
	movs r0, 0x1
_0801B3BA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801B374

	thumb_func_start sub_801B3C0
sub_801B3C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x1
	bl ResetSprites
	ldr r4, _0801B40C
	movs r0, 0x94
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	ldr r1, [r5]
	str r1, [r0, 0x4]
	adds r0, 0x88
	bl sub_801317C
	ldr r0, [r4]
	movs r1, 0
	str r1, [r0, 0x24]
	adds r0, 0x28
	bl sub_80140B4
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x28
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_801B46C
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801B40C: .4byte gUnknown_203B230
	thumb_func_end sub_801B3C0

	thumb_func_start sub_801B410
sub_801B410:
	push {lr}
	ldr r0, _0801B428
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801B43C
	cmp r0, 0x1
	bgt _0801B42C
	cmp r0, 0
	beq _0801B436
	b _0801B446
	.align 2, 0
_0801B428: .4byte gUnknown_203B230
_0801B42C:
	cmp r0, 0x2
	beq _0801B446
	cmp r0, 0x3
	beq _0801B442
	b _0801B446
_0801B436:
	bl sub_801B51C
	b _0801B44A
_0801B43C:
	bl sub_801B590
	b _0801B44A
_0801B442:
	movs r0, 0x3
	b _0801B44C
_0801B446:
	movs r0, 0x2
	b _0801B44C
_0801B44A:
	movs r0, 0
_0801B44C:
	pop {r1}
	bx r1
	thumb_func_end sub_801B410

	thumb_func_start sub_801B450
sub_801B450:
	push {r4,lr}
	ldr r4, _0801B468
	ldr r0, [r4]
	cmp r0, 0
	beq _0801B462
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801B462:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B468: .4byte gUnknown_203B230
	thumb_func_end sub_801B450

	thumb_func_start sub_801B46C
sub_801B46C:
	push {lr}
	ldr r1, _0801B47C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801B480
	pop {r0}
	bx r0
	.align 2, 0
_0801B47C: .4byte gUnknown_203B230
	thumb_func_end sub_801B46C

	thumb_func_start sub_801B480
sub_801B480:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0801B4B0
	ldr r0, [r5]
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0801B4B4
	cmp r4, 0x1
	bgt _0801B50C
	cmp r4, 0
	bne _0801B50C
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r2, [r5]
	adds r0, r2, 0x4
	ldr r1, [r2, 0x24]
	adds r2, 0x10
	bl sub_80913E0
	ldr r1, [r5]
	str r0, [r1, 0xC]
	str r4, [r1, 0x20]
	b _0801B50C
	.align 2, 0
_0801B4B0: .4byte gUnknown_203B230
_0801B4B4:
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073B8
	ldr r0, [r5]
	ldr r1, [r0, 0x8]
	lsls r1, 2
	adds r0, 0x10
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _0801B514
	ldr r1, [r1]
	bl strcpy
	ldr r2, _0801B518
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl sub_8014FF0
	ldr r3, [r5]
	ldr r1, [r3, 0x8]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x10
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	ldr r3, [r3, 0x24]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	bl sub_8014FF0
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073E0
_0801B50C:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801B514: .4byte gAvailablePokemonNames
_0801B518: .4byte gUnknown_80DBA4C
	thumb_func_end sub_801B480

	thumb_func_start sub_801B51C
sub_801B51C:
	push {r4,lr}
	ldr r0, _0801B558
	ldr r2, [r0]
	ldr r1, [r2, 0xC]
	adds r4, r0, 0
	cmp r1, 0
	beq _0801B540
	ldr r0, [r2, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801B538
	bl sub_8013F84
_0801B538:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801B540:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801B55C
	cmp r0, 0x2
	beq _0801B57E
	b _0801B58A
	.align 2, 0
_0801B558: .4byte gUnknown_203B230
_0801B55C:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _0801B576
	movs r0, 0
	str r0, [r1, 0x8]
	movs r0, 0x1
	bl sub_801B46C
	b _0801B58A
_0801B576:
	movs r0, 0x3
	bl sub_801B46C
	b _0801B58A
_0801B57E:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	bl sub_801B46C
_0801B58A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801B51C

	thumb_func_start sub_801B590
sub_801B590:
	push {r4,lr}
	ldr r0, _0801B5D0
	ldr r3, [r0]
	ldr r1, [r3, 0xC]
	subs r1, 0x1
	ldr r2, [r3, 0x8]
	adds r4, r0, 0
	cmp r2, r1
	bge _0801B5B8
	ldr r0, [r3, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801B5B0
	bl sub_8013F84
_0801B5B0:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801B5B8:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801B5D4
	cmp r0, 0x2
	beq _0801B5F8
	b _0801B604
	.align 2, 0
_0801B5D0: .4byte gUnknown_203B230
_0801B5D4:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldr r0, [r0, 0xC]
	cmp r1, r0
	bge _0801B5F0
	movs r0, 0x1
	bl sub_801B46C
	b _0801B604
_0801B5F0:
	movs r0, 0
	bl sub_801B46C
	b _0801B604
_0801B5F8:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	bl sub_801B46C
_0801B604:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801B590

	thumb_func_start sub_801B60C
sub_801B60C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r6, _0801B650
	movs r0, 0xAA
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	adds r2, r0, 0
	adds r2, 0xC8
	movs r1, 0
	str r1, [r2]
	str r5, [r0]
	strb r4, [r0, 0x12]
	ldr r0, [r6]
	ldrb r0, [r0, 0x12]
	bl sub_8090A60
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0801B654
	ldr r0, [r6]
	strb r7, [r0, 0x11]
	ldr r0, [r6]
	strb r7, [r0, 0xC]
	b _0801B65E
	.align 2, 0
_0801B650: .4byte gUnknown_203B234
_0801B654:
	ldr r0, [r6]
	strb r1, [r0, 0x11]
	ldr r1, [r6]
	movs r0, 0x1
	strb r0, [r1, 0xC]
_0801B65E:
	ldr r5, _0801B6A0
	ldr r0, [r5]
	movs r1, 0
	movs r2, 0x1
	strb r2, [r0, 0x10]
	ldr r0, [r5]
	str r1, [r0, 0x14]
	strb r1, [r0, 0x18]
	ldr r0, [r5]
	strb r2, [r0, 0x1C]
	ldr r4, _0801B6A4
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r0, _0801B6A8
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0x10
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0
	bl sub_801B748
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B6A0: .4byte gUnknown_203B234
_0801B6A4: .4byte gAvailablePokemonNames
_0801B6A8: .4byte gUnknown_202DE58
	thumb_func_end sub_801B60C

	thumb_func_start sub_801B6AC
sub_801B6AC:
	push {lr}
	ldr r0, _0801B6C4
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	subs r0, 0x6
	cmp r0, 0xA
	bhi _0801B720
	lsls r0, 2
	ldr r1, _0801B6C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B6C4: .4byte gUnknown_203B234
_0801B6C8: .4byte _0801B6CC
	.align 2, 0
_0801B6CC:
	.4byte _0801B6FC
	.4byte _0801B702
	.4byte _0801B708
	.4byte _0801B708
	.4byte _0801B70E
	.4byte _0801B714
	.4byte _0801B71A
	.4byte _0801B720
	.4byte _0801B720
	.4byte _0801B720
	.4byte _0801B6F8
_0801B6F8:
	movs r0, 0x3
	b _0801B726
_0801B6FC:
	bl sub_801BC64
	b _0801B724
_0801B702:
	bl sub_801BC94
	b _0801B724
_0801B708:
	bl sub_801BCCC
	b _0801B724
_0801B70E:
	bl sub_801BD80
	b _0801B724
_0801B714:
	bl sub_801BEAC
	b _0801B724
_0801B71A:
	bl sub_801BE30
	b _0801B724
_0801B720:
	bl sub_801BEC8
_0801B724:
	movs r0, 0
_0801B726:
	pop {r1}
	bx r1
	thumb_func_end sub_801B6AC

	thumb_func_start sub_801B72C
sub_801B72C:
	push {r4,lr}
	ldr r4, _0801B744
	ldr r0, [r4]
	cmp r0, 0
	beq _0801B73E
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801B73E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B744: .4byte gUnknown_203B234
	thumb_func_end sub_801B72C

	thumb_func_start sub_801B748
sub_801B748:
	push {lr}
	ldr r1, _0801B75C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801B760
	bl sub_801B874
	pop {r0}
	bx r0
	.align 2, 0
_0801B75C: .4byte gUnknown_203B234
	thumb_func_end sub_801B748

	thumb_func_start sub_801B760
sub_801B760:
	push {r4-r7,lr}
	ldr r0, _0801B77C
	ldr r1, [r0]
	ldr r1, [r1, 0x4]
	subs r1, 0x1
	adds r4, r0, 0
	cmp r1, 0xE
	bls _0801B772
	b _0801B86A
_0801B772:
	lsls r0, r1, 2
	ldr r1, _0801B780
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B77C: .4byte gUnknown_203B234
_0801B780: .4byte _0801B784
	.align 2, 0
_0801B784:
	.4byte _0801B7C0
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B800
	.4byte _0801B7C0
	.4byte _0801B840
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
_0801B7C0:
	ldr r4, _0801B7F8
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	mov r12, r4
	ldr r4, _0801B7FC
	movs r3, 0
	movs r2, 0x3
_0801B7D2:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xF4
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801B7D2
	bl ResetUnusedInputStruct
	ldr r0, _0801B7F8
	ldr r0, [r0]
	b _0801B82E
	.align 2, 0
_0801B7F8: .4byte gUnknown_203B234
_0801B7FC: .4byte gUnknown_80DBA58
_0801B800:
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	bl sub_801BB5C
	ldr r2, [r4]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801B83C
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xCC
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
_0801B82E:
	adds r0, 0xF4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801B86A
	.align 2, 0
_0801B83C: .4byte gUnknown_80DBA70
_0801B840:
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	ldr r1, [r4]
	movs r6, 0x86
	lsls r6, 1
	adds r1, r6
	ldr r0, _0801B870
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801B86A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B870: .4byte gUnknown_80DBA88
	thumb_func_end sub_801B760

	thumb_func_start sub_801B874
sub_801B874:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _0801B890
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x10
	bls _0801B886
	b _0801BB0E
_0801B886:
	lsls r0, 2
	ldr r1, _0801B894
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B890: .4byte gUnknown_203B234
_0801B894: .4byte _0801B898
	.align 2, 0
_0801B898:
	.4byte _0801B8DC
	.4byte _0801B9BC
	.4byte _0801B9D8
	.4byte _0801B9E0
	.4byte _0801B9F0
	.4byte _0801B9F8
	.4byte _0801BA08
	.4byte _0801BA34
	.4byte _0801BA60
	.4byte _0801BA6E
	.4byte _0801BA76
	.4byte _0801BA94
	.4byte _0801BA9E
	.4byte _0801BAD0
	.4byte _0801BAE0
	.4byte _0801BAFC
	.4byte _0801BB0E
_0801B8DC:
	ldr r1, [r4]
	ldrb r0, [r1, 0x12]
	cmp r0, 0xEA
	bne _0801B8FE
	movs r0, 0x10
	str r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x47
	movs r2, 0x1
	bl sub_8001784
	cmp r0, 0
	bne _0801B914
	movs r0, 0
	movs r1, 0x47
	movs r2, 0x1
	b _0801B92A
_0801B8FE:
	cmp r0, 0xEB
	bne _0801B938
	movs r0, 0x10
	str r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x47
	movs r2, 0
	bl sub_8001784
	cmp r0, 0
	beq _0801B924
_0801B914:
	movs r0, 0xFA
	lsls r0, 2
	bl sub_80913A0
	movs r0, 0x4
	bl sub_801B748
	b _0801BB0E
_0801B924:
	movs r0, 0
	movs r1, 0x47
	movs r2, 0
_0801B92A:
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0x3
	bl sub_801B748
	b _0801BB0E
_0801B938:
	bl sub_8090A34
	cmp r0, 0x13
	ble _0801B986
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801B968
	ldr r0, _0801B970
	ldr r1, [r0]
	ldr r2, [r4]
	ldrb r0, [r2, 0x12]
	lsls r0, 1
	adds r1, 0x50
	adds r3, r1, r0
	ldrh r1, [r3]
	ldrb r0, [r2, 0xC]
	adds r1, r0
	ldr r0, _0801B974
	cmp r1, r0
	ble _0801B978
_0801B968:
	ldr r1, [r4]
	movs r0, 0x6
	b _0801B99C
	.align 2, 0
_0801B970: .4byte gUnknown_203B460
_0801B974: .4byte 0x000003e7
_0801B978:
	strh r1, [r3]
	movs r0, 0xCB
	bl PlaySound
	ldr r1, [r4]
	movs r0, 0x5
	b _0801B99C
_0801B986:
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8091290
	bl sub_80910B4
	movs r0, 0xCB
	bl PlaySound
	ldr r1, [r4]
	movs r0, 0x10
_0801B99C:
	str r0, [r1, 0x8]
	ldr r0, _0801B9B0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0801B9B4
	movs r0, 0x2
	bl sub_801B748
	b _0801BB0E
	.align 2, 0
_0801B9B0: .4byte gUnknown_203B234
_0801B9B4:
	movs r0, 0x1
	bl sub_801B748
	b _0801BB0E
_0801B9BC:
	movs r0, 0
	bl sub_808D544
	cmp r0, 0x1
	bgt _0801B9D0
	ldr r0, _0801B9CC
	b _0801BAE8
	.align 2, 0
_0801B9CC: .4byte gUnknown_80DBAA0
_0801B9D0:
	ldr r0, _0801B9D4
	b _0801BAE8
	.align 2, 0
_0801B9D4: .4byte gUnknown_80DBAD0
_0801B9D8:
	ldr r0, _0801B9DC
	b _0801BAE8
	.align 2, 0
_0801B9DC: .4byte gUnknown_80DBB08
_0801B9E0:
	movs r0, 0xD4
	bl PlaySound
	ldr r0, _0801B9EC
	b _0801BAE8
	.align 2, 0
_0801B9EC: .4byte gUnknown_80DBB38
_0801B9F0:
	ldr r0, _0801B9F4
	b _0801BAE8
	.align 2, 0
_0801B9F4: .4byte gUnknown_80DBB9C
_0801B9F8:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BA04
	b _0801BAE8
	.align 2, 0
_0801BA04: .4byte gUnknown_80DBC28
_0801BA08:
	bl sub_801BB20
	ldr r0, _0801BA2C
	ldr r1, _0801BA30
	ldr r3, [r1]
	adds r3, 0xCC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	str r2, [sp, 0x10]
	movs r1, 0
	movs r2, 0x4
	bl sub_8014248
	b _0801BB0E
	.align 2, 0
_0801BA2C: .4byte gUnknown_80DBC60
_0801BA30: .4byte gUnknown_203B234
_0801BA34:
	bl sub_801BC24
	ldr r0, _0801BA58
	ldr r1, _0801BA5C
	ldr r3, [r1]
	adds r3, 0xCC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	str r2, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0801BB0E
	.align 2, 0
_0801BA58: .4byte gUnknown_80DBC98
_0801BA5C: .4byte gUnknown_203B234
_0801BA60:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _0801BB0E
_0801BA6E:
	movs r0, 0x1
	bl sub_801A8D0
	b _0801BB0E
_0801BA76:
	bl sub_801A9E0
	ldr r0, _0801BA90
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x28
	adds r1, r2, 0
	adds r1, 0xCC
	adds r2, 0xC8
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x2
	b _0801BAC0
	.align 2, 0
_0801BA90: .4byte gUnknown_203B234
_0801BA94:
	ldr r0, [r4]
	adds r0, 0x20
	bl sub_801B3C0
	b _0801BB0E
_0801BA9E:
	bl sub_801A9E0
	ldr r4, _0801BACC
	ldr r0, [r4]
	adds r0, 0x28
	movs r1, 0
	bl sub_8012EA4
	bl sub_801BC24
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x78
	adds r1, 0xCC
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
_0801BAC0:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0801BB0E
	.align 2, 0
_0801BACC: .4byte gUnknown_203B234
_0801BAD0:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BADC
	b _0801BAE8
	.align 2, 0
_0801BADC: .4byte gUnknown_80DBCC4
_0801BAE0:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BAF4
_0801BAE8:
	ldr r3, _0801BAF8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0801BB0E
	.align 2, 0
_0801BAF4: .4byte gUnknown_80DBCE8
_0801BAF8: .4byte 0x00000101
_0801BAFC:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BB18
	ldr r3, _0801BB1C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0801BB0E:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801BB18: .4byte gUnknown_80DBD24
_0801BB1C: .4byte 0x00000101
	thumb_func_end sub_801B874

	thumb_func_start sub_801BB20
sub_801BB20:
	ldr r0, _0801BB50
	ldr r3, [r0]
	movs r2, 0
	adds r1, r3, 0
	adds r1, 0xCC
	ldr r0, _0801BB54
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0801BB58
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xDC
	str r2, [r0]
	adds r1, 0x8
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801BB50: .4byte gUnknown_203B234
_0801BB54: .4byte gKangaskhanTrashToolboxItem
_0801BB58: .4byte gKangaskhanTrashReceivedItem
	thumb_func_end sub_801BB20

	thumb_func_start sub_801BB5C
sub_801BB5C:
	push {r4-r7,lr}
	ldr r4, _0801BBEC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xCC
	ldr r0, _0801BBF0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x6
	str r0, [r1]
	ldr r0, [r2, 0x24]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801BB86
	ldr r0, [r4]
	adds r0, 0xD0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0801BB86:
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0x1
	movs r2, 0x8
	mov r1, r12
	adds r1, 0xD4
	ldr r0, _0801BBF4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0801BBF8
	ldr r0, [r0]
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE0
	str r2, [r0]
	movs r5, 0x3
	adds r1, 0x8
	movs r0, 0
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE8
	str r3, [r0]
	movs r3, 0
	adds r6, r4, 0
	movs r7, 0x1
	negs r7, r7
	mov r4, r12
	adds r4, 0xC8
	subs r1, 0x14
_0801BBC6:
	ldr r2, [r1]
	cmp r2, r7
	beq _0801BBD2
	ldr r0, [r4]
	cmp r2, r0
	beq _0801BC1C
_0801BBD2:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0801BBC6
	movs r3, 0
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xD0
	ldr r1, [r0]
	b _0801BC0E
	.align 2, 0
_0801BBEC: .4byte gUnknown_203B234
_0801BBF0: .4byte gKangaskhanStorage
_0801BBF4: .4byte gKangaskhanTrash
_0801BBF8: .4byte gUnknown_80D4970
_0801BBFC:
	adds r3, 0x1
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xD0
	adds r1, r0
	ldr r1, [r1]
_0801BC0E:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801BBFC
	adds r0, r2, 0
	adds r0, 0xC8
	str r1, [r0]
_0801BC1C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801BB5C

	thumb_func_start sub_801BC24
sub_801BC24:
	ldr r0, _0801BC58
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	mov r1, r12
	adds r1, 0xCC
	ldr r0, _0801BC5C
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _0801BC60
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x3
	str r0, [r1]
	mov r0, r12
	adds r0, 0xDC
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	bx lr
	.align 2, 0
_0801BC58: .4byte gUnknown_203B234
_0801BC5C: .4byte gUnknown_80D4920
_0801BC60: .4byte gUnknown_80D4928
	thumb_func_end sub_801BC24

	thumb_func_start sub_801BC64
sub_801BC64:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BC8C
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801BC7E
	cmp r0, 0x5
	beq _0801BC86
	b _0801BC8C
_0801BC7E:
	movs r0, 0x8
	bl sub_801B748
	b _0801BC8C
_0801BC86:
	movs r0, 0x7
	bl sub_801B748
_0801BC8C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801BC64

	thumb_func_start sub_801BC94
sub_801BC94:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BCC6
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801BCB8
	cmp r0, 0x2
	bgt _0801BCB2
	cmp r0, 0x1
	beq _0801BCC0
	b _0801BCC6
_0801BCB2:
	cmp r0, 0x3
	beq _0801BCC0
	b _0801BCC6
_0801BCB8:
	movs r0, 0xD
	bl sub_801B748
	b _0801BCC6
_0801BCC0:
	movs r0, 0x6
	bl sub_801B748
_0801BCC6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801BC94

	thumb_func_start sub_801BCCC
sub_801BCCC:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _0801BD7A
	lsls r0, 2
	ldr r1, _0801BCE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801BCE4: .4byte _0801BCE8
	.align 2, 0
_0801BCE8:
	.4byte _0801BD7A
	.4byte _0801BD7A
	.4byte _0801BD70
	.4byte _0801BCFC
	.4byte _0801BD34
_0801BCFC:
	bl sub_801A8AC
	ldr r1, _0801BD28
	ldr r2, [r1]
	str r0, [r2, 0x24]
	ldr r1, _0801BD2C
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
	ldr r0, _0801BD30
	adds r1, r2, 0
	adds r1, 0x20
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0xA
	bl sub_801B748
	b _0801BD7A
	.align 2, 0
_0801BD28: .4byte gUnknown_203B234
_0801BD2C: .4byte gUnknown_203B460
_0801BD30: .4byte gUnknown_202DEA8
_0801BD34:
	bl sub_801A8AC
	ldr r1, _0801BD64
	ldr r2, [r1]
	str r0, [r2, 0x24]
	ldr r1, _0801BD68
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
	ldr r0, _0801BD6C
	adds r1, r2, 0
	adds r1, 0x20
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0
	bl sub_8099690
	movs r0, 0xB
	bl sub_801B748
	b _0801BD7A
	.align 2, 0
_0801BD64: .4byte gUnknown_203B234
_0801BD68: .4byte gUnknown_203B460
_0801BD6C: .4byte gUnknown_202DEA8
_0801BD70:
	bl sub_801A928
	movs r0, 0x6
	bl sub_801B748
_0801BD7A:
	pop {r0}
	bx r0
	thumb_func_end sub_801BCCC

	thumb_func_start sub_801BD80
sub_801BD80:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0801BDC4
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801BDB2
	ldr r0, [r4]
	adds r0, 0x28
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801BDB2
	ldr r0, [r4]
	adds r0, 0xC8
	str r1, [r0]
_0801BDB2:
	ldr r0, [sp]
	cmp r0, 0x6
	beq _0801BDD2
	cmp r0, 0x6
	bgt _0801BDC8
	cmp r0, 0x1
	beq _0801BE22
	b _0801BE28
	.align 2, 0
_0801BDC4: .4byte gUnknown_203B234
_0801BDC8:
	cmp r0, 0x7
	beq _0801BE0C
	cmp r0, 0x8
	beq _0801BE14
	b _0801BE28
_0801BDD2:
	ldr r4, _0801BE08
	ldr r0, [r4]
	adds r0, 0x20
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8091290
	bl sub_80910B4
	movs r0, 0xCB
	bl PlaySound
	movs r0, 0
	bl sub_8099690
	bl sub_801A928
	movs r0, 0xE
	bl sub_801B748
	b _0801BE28
	.align 2, 0
_0801BE08: .4byte gUnknown_203B234
_0801BE0C:
	movs r0, 0xC
	bl sub_801B748
	b _0801BE28
_0801BE14:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xB
	bl sub_801B748
	b _0801BE28
_0801BE22:
	movs r0, 0x9
	bl sub_801B748
_0801BE28:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BD80

	thumb_func_start sub_801BE30
sub_801BE30:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0801BE70
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801BE5E
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
_0801BE5E:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801BE80
	cmp r0, 0x2
	bgt _0801BE74
	cmp r0, 0x1
	beq _0801BE78
	b _0801BEA4
	.align 2, 0
_0801BE70: .4byte gUnknown_203B234
_0801BE74:
	cmp r0, 0x3
	bne _0801BEA4
_0801BE78:
	movs r0, 0x9
	bl sub_801B748
	b _0801BEA4
_0801BE80:
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	ldr r0, [r4]
	adds r0, 0x10
	bl sub_8091290
	bl sub_80910B4
	movs r0, 0xCB
	bl PlaySound
	bl sub_801A928
	movs r0, 0xF
	bl sub_801B748
_0801BEA4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BE30

	thumb_func_start sub_801BEAC
sub_801BEAC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _0801BEC4
	cmp r0, 0x3
	bhi _0801BEC4
	bl sub_801B450
	movs r0, 0x9
	bl sub_801B748
_0801BEC4:
	pop {r0}
	bx r0
	thumb_func_end sub_801BEAC

	thumb_func_start sub_801BEC8
sub_801BEC8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BEE0
	ldr r0, _0801BEE8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801B748
_0801BEE0:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0801BEE8: .4byte gUnknown_203B234
	thumb_func_end sub_801BEC8

	thumb_func_start sub_801BEEC
sub_801BEEC:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	adds r0, r5, 0
	bl sub_801C5F0
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0801BF40
	ldr r4, _0801BF38
	movs r0, 0x92
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r6, [r0, 0x30]
	strh r5, [r0, 0x4]
	ldr r3, _0801BF3C
	movs r1, 0x58
	adds r2, r5, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0, 0x8]
	adds r0, 0xC
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	ldr r1, [r4]
	str r0, [r1, 0x2C]
	movs r0, 0
	bl sub_801BFB4
	movs r0, 0x1
	b _0801BF42
	.align 2, 0
_0801BF38: .4byte gUnknown_203B238
_0801BF3C: .4byte gRecruitedPokemonRef
_0801BF40:
	movs r0, 0
_0801BF42:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801BEEC

	thumb_func_start sub_801BF48
sub_801BF48:
	push {lr}
	ldr r0, _0801BF60
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0801BF90
	lsls r0, 2
	ldr r1, _0801BF64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801BF60: .4byte gUnknown_203B238
_0801BF64: .4byte _0801BF68
	.align 2, 0
_0801BF68:
	.4byte _0801BF80
	.4byte _0801BF80
	.4byte _0801BF86
	.4byte _0801BF8C
	.4byte _0801BF7C
_0801BF7C:
	movs r0, 0x3
	b _0801BF92
_0801BF80:
	bl sub_801C118
	b _0801BF90
_0801BF86:
	bl sub_801C1A0
	b _0801BF90
_0801BF8C:
	bl sub_801C228
_0801BF90:
	movs r0, 0
_0801BF92:
	pop {r1}
	bx r1
	thumb_func_end sub_801BF48

	thumb_func_start sub_801BF98
sub_801BF98:
	push {r4,lr}
	ldr r4, _0801BFB0
	ldr r0, [r4]
	cmp r0, 0
	beq _0801BFAA
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801BFAA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801BFB0: .4byte gUnknown_203B238
	thumb_func_end sub_801BF98

	thumb_func_start sub_801BFB4
sub_801BFB4:
	push {lr}
	ldr r1, _0801BFC8
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801BFCC
	bl sub_801C03C
	pop {r0}
	bx r0
	.align 2, 0
_0801BFC8: .4byte gUnknown_203B238
	thumb_func_end sub_801BFB4

	thumb_func_start sub_801BFCC
sub_801BFCC:
	push {r4-r7,lr}
	ldr r4, _0801BFF0
	ldr r0, [r4]
	adds r0, 0xC4
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2
	bne _0801BFF8
	adds r1, 0xF4
	ldr r0, _0801BFF4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0801C01A
	.align 2, 0
_0801BFF0: .4byte gUnknown_203B238
_0801BFF4: .4byte gUnknown_80DBDB0
_0801BFF8:
	mov r12, r4
	ldr r4, _0801C034
	movs r3, 0
	movs r2, 0x3
_0801C000:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xC4
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801C000
_0801C01A:
	bl ResetUnusedInputStruct
	ldr r0, _0801C038
	ldr r0, [r0]
	adds r0, 0xC4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C034: .4byte gUnknown_80DBD98
_0801C038: .4byte gUnknown_203B238
	thumb_func_end sub_801BFCC

	thumb_func_start sub_801C03C
sub_801C03C:
	push {lr}
	sub sp, 0x8
	ldr r1, _0801C058
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _0801C0C2
	lsls r0, 2
	ldr r1, _0801C05C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C058: .4byte gUnknown_203B238
_0801C05C: .4byte _0801C060
	.align 2, 0
_0801C060:
	.4byte _0801C074
	.4byte _0801C084
	.4byte _0801C08C
	.4byte _0801C0B8
	.4byte _0801C0C2
_0801C074:
	ldr r0, [r2]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0
	movs r2, 0x8
	bl sub_801C244
	b _0801C0C2
_0801C084:
	movs r0, 0x1
	bl sub_801C3B0
	b _0801C0C2
_0801C08C:
	bl sub_801C4C8
	bl sub_801C0C8
	ldr r0, _0801C0B4
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x74
	adds r1, r2, 0
	adds r1, 0x34
	ldr r2, [r2, 0x30]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0801C0C2
	.align 2, 0
_0801C0B4: .4byte gUnknown_203B238
_0801C0B8:
	ldr r0, [r2]
	adds r0, 0x28
	ldrb r0, [r0]
	bl sub_801C620
_0801C0C2:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_801C03C

	thumb_func_start sub_801C0C8
sub_801C0C8:
	push {r4,r5,lr}
	ldr r3, _0801C10C
	ldr r1, [r3]
	movs r4, 0
	ldr r0, _0801C110
	str r0, [r1, 0x34]
	movs r0, 0x2
	str r0, [r1, 0x38]
	movs r2, 0x1
	ldr r0, _0801C114
	ldr r0, [r0]
	str r0, [r1, 0x3C]
	movs r0, 0x3
	str r0, [r1, 0x40]
	movs r5, 0x2
	str r4, [r1, 0x44]
	str r2, [r1, 0x48]
	movs r2, 0
	ldr r4, [r1, 0x30]
	adds r1, 0x38
_0801C0F0:
	ldr r0, [r1]
	cmp r0, r4
	beq _0801C104
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r5
	blt _0801C0F0
	ldr r1, [r3]
	movs r0, 0x2
	str r0, [r1, 0x30]
_0801C104:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C10C: .4byte gUnknown_203B238
_0801C110: .4byte gUnknown_80DBDC8
_0801C114: .4byte gUnknown_80D4970
	thumb_func_end sub_801C0C8

	thumb_func_start sub_801C118
sub_801C118:
	push {lr}
	movs r0, 0x1
	bl sub_801C308
	cmp r0, 0x4
	bhi _0801C19A
	lsls r0, 2
	ldr r1, _0801C130
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C130: .4byte _0801C134
	.align 2, 0
_0801C134:
	.4byte _0801C19A
	.4byte _0801C19A
	.4byte _0801C190
	.4byte _0801C148
	.4byte _0801C16C
_0801C148:
	bl sub_801C390
	ldr r1, _0801C168
	ldr r2, [r1]
	str r0, [r2, 0x24]
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r0
	ldrb r0, [r1]
	adds r2, 0x28
	strb r0, [r2]
	movs r0, 0x2
	bl sub_801BFB4
	b _0801C19A
	.align 2, 0
_0801C168: .4byte gUnknown_203B238
_0801C16C:
	bl sub_801C390
	ldr r1, _0801C18C
	ldr r2, [r1]
	str r0, [r2, 0x24]
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r0
	ldrb r0, [r1]
	adds r2, 0x28
	strb r0, [r2]
	movs r0, 0x3
	bl sub_801BFB4
	b _0801C19A
	.align 2, 0
_0801C18C: .4byte gUnknown_203B238
_0801C190:
	bl sub_801C3F8
	movs r0, 0x4
	bl sub_801BFB4
_0801C19A:
	pop {r0}
	bx r0
	thumb_func_end sub_801C118

	thumb_func_start sub_801C1A0
sub_801C1A0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801C308
	ldr r4, _0801C1E0
	ldr r0, [r4]
	adds r0, 0x74
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801C1D0
	ldr r0, [r4]
	adds r0, 0x74
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801C1D0
	ldr r0, [r4]
	str r1, [r0, 0x30]
_0801C1D0:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801C1EA
	cmp r0, 0x2
	bgt _0801C1E4
	cmp r0, 0x1
	beq _0801C218
	b _0801C21E
	.align 2, 0
_0801C1E0: .4byte gUnknown_203B238
_0801C1E4:
	cmp r0, 0x3
	beq _0801C210
	b _0801C21E
_0801C1EA:
	ldr r0, _0801C208
	bl PlaySound
	ldr r0, _0801C20C
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	adds r0, 0x20
	adds r1, 0x28
	ldrb r1, [r1]
	bl sub_808EBF4
	movs r0, 0x1
	bl sub_801BFB4
	b _0801C21E
	.align 2, 0
_0801C208: .4byte 0x00000133
_0801C20C: .4byte gUnknown_203B238
_0801C210:
	movs r0, 0x3
	bl sub_801BFB4
	b _0801C21E
_0801C218:
	movs r0, 0x1
	bl sub_801BFB4
_0801C21E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801C1A0

	thumb_func_start sub_801C228
sub_801C228:
	push {lr}
	bl sub_801C674
	cmp r0, 0x1
	bls _0801C240
	cmp r0, 0x3
	bhi _0801C240
	bl sub_801C6B4
	movs r0, 0x1
	bl sub_801BFB4
_0801C240:
	pop {r0}
	bx r0
	thumb_func_end sub_801C228

	thumb_func_start sub_801C244
sub_801C244:
	push {r4-r7,lr}
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r0, 16
	asrs r0, 16
	adds r4, r0, 0
	bl sub_801C5F0
	lsls r0, 24
	cmp r0, 0
	beq _0801C25E
	movs r0, 0
	b _0801C2F6
_0801C25E:
	ldr r5, _0801C2FC
	ldr r0, [r5]
	cmp r0, 0
	bne _0801C270
	movs r0, 0xC4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0801C270:
	ldr r0, [r5]
	strh r4, [r0]
	ldr r3, _0801C300
	movs r1, 0x58
	adds r2, r4, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0, 0x4]
	adds r0, 0x8
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	adds r1, r0, 0
	ldr r0, [r5]
	str r1, [r0, 0x20]
	str r6, [r0, 0x58]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x60
	adds r1, r0, r1
	str r1, [r0, 0x5C]
	adds r0, 0x60
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x58]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x60
	ldr r0, _0801C304
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r1, [r5]
	ldr r0, [r1, 0x5C]
	adds r1, 0xC0
	str r1, [r0, 0x14]
	adds r1, r7, 0
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x20]
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_8013818
	bl sub_801C440
	bl sub_801C4C8
	movs r0, 0x1
_0801C2F6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C2FC: .4byte gUnknown_203B23C
_0801C300: .4byte gRecruitedPokemonRef
_0801C304: .4byte gUnknown_80DBDF0
	thumb_func_end sub_801C244

	thumb_func_start sub_801C308
sub_801C308:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801C324
	ldr r0, _0801C320
	ldr r0, [r0]
	adds r0, 0x24
	bl sub_8013660
	movs r0, 0
	b _0801C38A
	.align 2, 0
_0801C320: .4byte gUnknown_203B23C
_0801C324:
	ldr r0, _0801C33C
	ldr r0, [r0]
	adds r0, 0x24
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801C346
	cmp r0, 0x2
	bgt _0801C340
	cmp r0, 0x1
	beq _0801C350
	b _0801C364
	.align 2, 0
_0801C33C: .4byte gUnknown_203B23C
_0801C340:
	cmp r0, 0x4
	beq _0801C35A
	b _0801C364
_0801C346:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801C38A
_0801C350:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801C38A
_0801C35A:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801C38A
_0801C364:
	ldr r0, _0801C37C
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801C380
	movs r0, 0
	b _0801C38A
	.align 2, 0
_0801C37C: .4byte gUnknown_203B23C
_0801C380:
	bl sub_801C440
	bl sub_801C4C8
	movs r0, 0x1
_0801C38A:
	pop {r1}
	bx r1
	thumb_func_end sub_801C308

	thumb_func_start sub_801C390
sub_801C390:
	ldr r0, _0801C3AC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	movs r3, 0x3C
	ldrsh r1, [r2, r3]
	adds r0, r1
	bx lr
	.align 2, 0
_0801C3AC: .4byte gUnknown_203B23C
	thumb_func_end sub_801C390

	thumb_func_start sub_801C3B0
sub_801C3B0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801C3F4
	ldr r0, [r5]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	ldr r1, [r0, 0x20]
	adds r2, r0, 0
	adds r2, 0x46
	strh r1, [r2]
	adds r0, 0x24
	bl sub_8013984
	bl sub_801C440
	bl sub_801C4C8
	cmp r4, 0
	beq _0801C3EE
	ldr r0, [r5]
	adds r0, 0x24
	bl AddMenuCursorSprite
_0801C3EE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C3F4: .4byte gUnknown_203B23C
	thumb_func_end sub_801C3B0

	thumb_func_start sub_801C3F8
sub_801C3F8:
	push {r4,r5,lr}
	ldr r4, _0801C438
	ldr r2, [r4]
	cmp r2, 0
	beq _0801C432
	ldr r0, [r2, 0x58]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x60
	ldr r0, _0801C43C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801C432:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C438: .4byte gUnknown_203B23C
_0801C43C: .4byte gUnknown_80DBDD8
	thumb_func_end sub_801C3F8

	thumb_func_start sub_801C440
sub_801C440:
	push {r4,lr}
	ldr r4, _0801C4C4
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x44
	ldrh r1, [r1]
	adds r0, 0xC0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x42
	ldrh r1, [r1]
	adds r0, 0xC1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC2
	movs r1, 0xA
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC3
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r2, [r4]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6E
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r2, r1
	adds r2, 0x70
	strh r0, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C4C4: .4byte gUnknown_203B23C
	thumb_func_end sub_801C440

	thumb_func_start sub_801C4C8
sub_801C4C8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r6, _0801C594
	ldr r0, [r6]
	ldr r0, [r0, 0x58]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x58]
	bl sub_80073B8
	ldr r0, [r6]
	adds r1, r0, 0
	adds r1, 0x42
	movs r2, 0
	ldrsh r4, [r1, r2]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0801C598
	ldr r3, [r0, 0x58]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	adds r0, r1, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r2, [r0, r3]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x58]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r5, 0
	ldr r0, [r6]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _0801C5CC
	ldr r2, _0801C59C
	mov r8, r2
_0801C53C:
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r1, r0
	adds r1, r5
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1
	ldrb r4, [r0]
	adds r0, r2, 0
	adds r0, 0x24
	adds r1, r5, 0
	bl sub_8013800
	adds r7, r0, 0
	adds r0, r4, 0
	bl sub_808EAB0
	adds r1, r0, 0
	mov r0, r8
	movs r2, 0x50
	bl strncpy
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, 0x20
	movs r1, 0x1
	lsls r1, r4
	bl sub_808ECD0
	lsls r0, 24
	cmp r0, 0
	beq _0801C5A4
	mov r0, r8
	subs r0, 0x50
	ldr r1, _0801C5A0
	bl strcpy
	b _0801C5AE
	.align 2, 0
_0801C594: .4byte gUnknown_203B23C
_0801C598: .4byte gUnknown_80DBE08
_0801C59C: .4byte gUnknown_202DEA8
_0801C5A0: .4byte gUnknown_80DBE14
_0801C5A4:
	mov r0, r8
	subs r0, 0x50
	ldr r1, _0801C5E4
	bl strcpy
_0801C5AE:
	ldr r0, [r6]
	ldr r3, [r0, 0x58]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	adds r1, r7, 0
	ldr r2, _0801C5E8
	bl sub_8014FF0
	adds r5, 0x1
	ldr r0, [r6]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0801C53C
_0801C5CC:
	ldr r0, _0801C5EC
	ldr r0, [r0]
	ldr r0, [r0, 0x58]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C5E4: .4byte gUnknown_80DBE18
_0801C5E8: .4byte gUnknown_80DBE1C
_0801C5EC: .4byte gUnknown_203B23C
	thumb_func_end sub_801C4C8

	thumb_func_start sub_801C5F0
sub_801C5F0:
	push {lr}
	sub sp, 0x18
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0801C614
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x14
	ldrsh r1, [r0, r2]
	mov r0, sp
	bl sub_808EBA8
	cmp r0, 0
	beq _0801C618
	movs r0, 0
	b _0801C61A
	.align 2, 0
_0801C614: .4byte gRecruitedPokemonRef
_0801C618:
	movs r0, 0x1
_0801C61A:
	add sp, 0x18
	pop {r1}
	bx r1
	thumb_func_end sub_801C5F0

	thumb_func_start sub_801C620
sub_801C620:
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	bl ResetSprites
	ldr r5, _0801C670
	movs r0, 0x94
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	adds r0, 0x88
	bl sub_801317C
	ldr r0, [r5]
	str r6, [r0, 0x24]
	adds r0, 0x28
	bl sub_80140B4
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x28
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl sub_801C6D0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C670: .4byte gUnknown_203B240
	thumb_func_end sub_801C620

	thumb_func_start sub_801C674
sub_801C674:
	push {lr}
	ldr r0, _0801C68C
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801C6A0
	cmp r0, 0x1
	bgt _0801C690
	cmp r0, 0
	beq _0801C69A
	b _0801C6AA
	.align 2, 0
_0801C68C: .4byte gUnknown_203B240
_0801C690:
	cmp r0, 0x2
	beq _0801C6AA
	cmp r0, 0x3
	beq _0801C6A6
	b _0801C6AA
_0801C69A:
	bl sub_801C7D4
	b _0801C6AE
_0801C6A0:
	bl sub_801C848
	b _0801C6AE
_0801C6A6:
	movs r0, 0x3
	b _0801C6B0
_0801C6AA:
	movs r0, 0x2
	b _0801C6B0
_0801C6AE:
	movs r0, 0
_0801C6B0:
	pop {r1}
	bx r1
	thumb_func_end sub_801C674

	thumb_func_start sub_801C6B4
sub_801C6B4:
	push {r4,lr}
	ldr r4, _0801C6CC
	ldr r0, [r4]
	cmp r0, 0
	beq _0801C6C6
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801C6C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C6CC: .4byte gUnknown_203B240
	thumb_func_end sub_801C6B4

	thumb_func_start sub_801C6D0
sub_801C6D0:
	push {lr}
	ldr r1, _0801C6E0
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801C6E4
	pop {r0}
	bx r0
	.align 2, 0
_0801C6E0: .4byte gUnknown_203B240
	thumb_func_end sub_801C6D0

	thumb_func_start sub_801C6E4
sub_801C6E4:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0801C760
	ldr r0, [r5]
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0801C76C
	cmp r4, 0x1
	bgt _0801C7C4
	cmp r4, 0
	bne _0801C7C4
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073B8
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	bl sub_808EAB0
	adds r1, r0, 0
	ldr r0, _0801C764
	bl strcpy
	ldr r2, _0801C768
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl sub_8014FF0
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	bl sub_808EADC
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x10
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073E0
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	bl sub_808EADC
	ldr r1, [r5]
	adds r1, 0x10
	bl sub_8097DF0
	ldr r1, [r5]
	str r0, [r1, 0xC]
	str r4, [r1, 0x20]
	b _0801C7C4
	.align 2, 0
_0801C760: .4byte gUnknown_203B240
_0801C764: .4byte gUnknown_202DE58
_0801C768: .4byte gUnknown_80DBE2C
_0801C76C:
	ldr r0, [r0, 0x24]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073B8
	ldr r0, [r5]
	ldr r1, [r0, 0x8]
	lsls r1, 2
	adds r0, 0x10
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _0801C7CC
	ldr r1, [r1]
	bl strcpy
	ldr r2, _0801C7D0
	ldr r0, [r5]
	ldr r3, [r0, 0x24]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl sub_8014FF0
	ldr r3, [r5]
	ldr r1, [r3, 0x8]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x10
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	ldr r3, [r3, 0x24]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	bl sub_8014FF0
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	bl sub_80073E0
_0801C7C4:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C7CC: .4byte gAvailablePokemonNames
_0801C7D0: .4byte gUnknown_80DBE30
	thumb_func_end sub_801C6E4

	thumb_func_start sub_801C7D4
sub_801C7D4:
	push {r4,lr}
	ldr r0, _0801C810
	ldr r2, [r0]
	ldr r1, [r2, 0xC]
	adds r4, r0, 0
	cmp r1, 0
	beq _0801C7F8
	ldr r0, [r2, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801C7F0
	bl sub_8013F84
_0801C7F0:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801C7F8:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801C814
	cmp r0, 0x2
	beq _0801C836
	b _0801C842
	.align 2, 0
_0801C810: .4byte gUnknown_203B240
_0801C814:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r1, [r4]
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _0801C82E
	movs r0, 0
	str r0, [r1, 0x8]
	movs r0, 0x1
	bl sub_801C6D0
	b _0801C842
_0801C82E:
	movs r0, 0x3
	bl sub_801C6D0
	b _0801C842
_0801C836:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	bl sub_801C6D0
_0801C842:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801C7D4

	thumb_func_start sub_801C848
sub_801C848:
	push {r4,lr}
	ldr r0, _0801C888
	ldr r3, [r0]
	ldr r1, [r3, 0xC]
	subs r1, 0x1
	ldr r2, [r3, 0x8]
	adds r4, r0, 0
	cmp r2, r1
	bge _0801C870
	ldr r0, [r3, 0x20]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801C868
	bl sub_8013F84
_0801C868:
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	adds r0, 0x1
	str r0, [r1, 0x20]
_0801C870:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x88
	ldr r1, [r1, 0x24]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801C88C
	cmp r0, 0x2
	beq _0801C8B0
	b _0801C8BC
	.align 2, 0
_0801C888: .4byte gUnknown_203B240
_0801C88C:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x1
	str r1, [r0, 0x8]
	ldr r0, [r0, 0xC]
	cmp r1, r0
	bge _0801C8A8
	movs r0, 0x1
	bl sub_801C6D0
	b _0801C8BC
_0801C8A8:
	movs r0, 0
	bl sub_801C6D0
	b _0801C8BC
_0801C8B0:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	bl sub_801C6D0
_0801C8BC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801C848

	thumb_func_start sub_801C8C4
sub_801C8C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	adds r6, r1, 0
	mov r9, r2
	mov r10, r3
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _0801C8E4
	movs r0, 0
	b _0801C9D0
_0801C8E4:
	ldr r5, _0801C9E0
	ldr r0, [r5]
	cmp r0, 0
	bne _0801C8F6
	ldr r0, _0801C9E4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0801C8F6:
	ldr r0, [r5]
	str r4, [r0]
	bl sub_801CF94
	ldr r0, [r5]
	movs r4, 0x9D
	lsls r4, 3
	adds r1, r0, r4
	str r6, [r1]
	ldr r1, _0801C9E8
	mov r8, r1
	adds r2, r0, r1
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	movs r7, 0x9E
	lsls r7, 3
	adds r1, r7
	adds r1, r0, r1
	str r1, [r2]
	adds r0, r7
	bl sub_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r7
	ldr r0, _0801C9EC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r5]
	mov r1, r8
	adds r0, r2, r1
	ldr r1, [r0]
	movs r3, 0xAA
	lsls r3, 3
	adds r0, r2, r3
	str r0, [r1, 0x14]
	mov r4, r9
	cmp r4, 0
	beq _0801C96C
	movs r1, 0x9D
	lsls r1, 3
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	subs r3, 0x58
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0801C96C:
	ldr r0, [r5]
	add r0, r8
	ldr r0, [r0]
	mov r1, r10
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	ldr r0, _0801C9F0
	adds r4, r0
	bl sub_801CE58
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r10
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, _0801C9F4
	ldr r4, [r5]
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	bne _0801C9C6
	ldr r0, _0801C9F8
	ldrh r1, [r0]
	ldr r2, _0801C9FC
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0801CA00
	ldrh r1, [r0]
	ldr r3, _0801CA04
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _0801C9F0
	adds r0, r4, r1
	bl sub_8013984
_0801C9C6:
	bl sub_801CC38
	bl sub_801CCD8
	movs r0, 0x1
_0801C9D0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C9E0: .4byte gUnknown_203B244
_0801C9E4: .4byte 0x00000554
_0801C9E8: .4byte 0x000004ec
_0801C9EC: .4byte gUnknown_80DBE54
_0801C9F0: .4byte 0x000004b4
_0801C9F4: .4byte gUnknown_203B248
_0801C9F8: .4byte gUnknown_203B24C
_0801C9FC: .4byte 0x000004cc
_0801CA00: .4byte gUnknown_203B24E
_0801CA04: .4byte 0x000004d2
	thumb_func_end sub_801C8C4

	thumb_func_start sub_801CA08
sub_801CA08:
	push {r4-r6,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801CA28
	ldr r0, _0801CA20
	ldr r0, [r0]
	ldr r1, _0801CA24
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _0801CB1E
	.align 2, 0
_0801CA20: .4byte gUnknown_203B244
_0801CA24: .4byte 0x000004b4
_0801CA28:
	ldr r0, _0801CA44
	ldr r0, [r0]
	ldr r1, _0801CA48
	adds r0, r1
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0x5
	bhi _0801CAF2
	lsls r0, 2
	ldr r1, _0801CA4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801CA44: .4byte gUnknown_203B244
_0801CA48: .4byte 0x000004b4
_0801CA4C: .4byte _0801CA50
	.align 2, 0
_0801CA50:
	.4byte _0801CA72
	.4byte _0801CA68
	.4byte _0801CAF2
	.4byte _0801CAE8
	.4byte _0801CA7C
	.4byte _0801CA7C
_0801CA68:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801CB1E
_0801CA72:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801CB1E
_0801CA7C:
	ldr r0, _0801CAD8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0801CAF2
	bl sub_801CB24
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_801CFE0
	movs r6, 0
	cmp r0, 0
	bne _0801CAB0
	bl sub_8090A34
	adds r4, r0, 0
	bl sub_801CFB8
	adds r4, r0
	cmp r4, 0x13
	bgt _0801CAAC
	movs r6, 0x1
_0801CAAC:
	cmp r6, 0
	beq _0801CAE0
_0801CAB0:
	movs r0, 0x6
	bl PlayMenuSoundEffect
	ldr r0, _0801CAD8
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r2, r0, 0
	adds r2, 0xF4
	adds r2, r1
	ldr r1, [r2]
	movs r3, 0x1
	eors r1, r3
	str r1, [r2]
	ldr r1, _0801CADC
	adds r0, r1
	movs r1, 0
	bl sub_80138B8
	b _0801CB18
	.align 2, 0
_0801CAD8: .4byte gUnknown_203B244
_0801CADC: .4byte 0x000004b4
_0801CAE0:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801CAF2
_0801CAE8:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801CB1E
_0801CAF2:
	ldr r0, _0801CB0C
	ldr r0, [r0]
	ldr r1, _0801CB10
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801CB14
	movs r0, 0
	b _0801CB1E
	.align 2, 0
_0801CB0C: .4byte gUnknown_203B244
_0801CB10: .4byte 0x000004b4
_0801CB14:
	bl sub_801CC38
_0801CB18:
	bl sub_801CCD8
	movs r0, 0x1
_0801CB1E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801CA08

	thumb_func_start sub_801CB24
sub_801CB24:
	ldr r0, _0801CB50
	ldr r0, [r0]
	ldr r2, _0801CB54
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0x9A
	lsls r3, 3
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r2, r1
	ldr r3, _0801CB58
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r2, r1
	adds r0, 0x4
	adds r0, r2
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0801CB50: .4byte gUnknown_203B244
_0801CB54: .4byte 0x000004d2
_0801CB58: .4byte 0x000004cc
	thumb_func_end sub_801CB24

	thumb_func_start sub_801CB5C
sub_801CB5C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801CBAC
	ldr r0, [r5]
	movs r1, 0x9E
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_801CE58
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, _0801CBB0
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _0801CBB4
	adds r0, r1
	bl sub_8013984
	bl sub_801CC38
	bl sub_801CCD8
	cmp r4, 0
	beq _0801CBA6
	ldr r0, [r5]
	ldr r3, _0801CBB4
	adds r0, r3
	bl AddMenuCursorSprite
_0801CBA6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CBAC: .4byte gUnknown_203B244
_0801CBB0: .4byte 0x000004d6
_0801CBB4: .4byte 0x000004b4
	thumb_func_end sub_801CB5C

	thumb_func_start sub_801CBB8
sub_801CBB8:
	push {r4-r6,lr}
	ldr r5, _0801CC1C
	ldr r2, [r5]
	cmp r2, 0
	beq _0801CC16
	ldr r1, _0801CC20
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _0801CC24
	ldr r3, _0801CC28
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0801CC2C
	ldr r6, _0801CC30
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0x9D
	lsls r1, 3
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0x9E
	lsls r4, 3
	adds r1, r4
	ldr r0, _0801CC34
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_0801CC16:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801CC1C: .4byte gUnknown_203B244
_0801CC20: .4byte gUnknown_203B248
_0801CC24: .4byte gUnknown_203B24C
_0801CC28: .4byte 0x000004cc
_0801CC2C: .4byte gUnknown_203B24E
_0801CC30: .4byte 0x000004d2
_0801CC34: .4byte gUnknown_80DBE3C
	thumb_func_end sub_801CBB8

	thumb_func_start sub_801CC38
sub_801CC38:
	push {r4,r5,lr}
	ldr r4, _0801CCC4
	ldr r0, [r4]
	movs r1, 0xAA
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0801CCC8
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, 0x1
	adds r0, r1
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0801CCCC
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _0801CCD0
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r4]
	movs r2, 0x9D
	lsls r2, 3
	adds r5, r3, r2
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _0801CCD4
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0xA0
	lsls r0, 3
	adds r3, r0
	strh r2, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	movs r1, 0x9E
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CCC4: .4byte gUnknown_203B244
_0801CCC8: .4byte 0x00000551
_0801CCCC: .4byte 0x00000553
_0801CCD0: .4byte 0x000004ce
_0801CCD4: .4byte 0x000004fe
	thumb_func_end sub_801CC38

	thumb_func_start sub_801CCD8
sub_801CCD8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r4, _0801CE38
	ldr r0, [r4]
	movs r5, 0x9D
	lsls r5, 3
	adds r0, r5
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, r5
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _0801CE3C
	ldr r0, [r4]
	adds r0, r5
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	ldr r1, _0801CE40
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	ldr r2, _0801CE44
	adds r1, r3, r2
	movs r6, 0
	ldrsh r2, [r1, r6]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r3, r5
	ldr r1, [r3]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r7, 0
	ldr r0, [r4]
	ldr r1, _0801CE48
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _0801CE1A
	adds r6, r4, 0
	ldr r3, _0801CE4C
	mov r9, r3
	mov r8, r5
_0801CD50:
	ldr r1, [r6]
	ldr r4, _0801CE44
	adds r0, r1, r4
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r4, 0x2
	adds r0, r1, r4
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r7
	adds r1, 0x4
	adds r1, r0
	ldrb r5, [r1]
	add r0, sp, 0x8
	adds r1, r5, 0
	movs r2, 0
	bl sub_8090DC4
	ldr r0, [r6]
	add r0, r9
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r6]
	add r0, r8
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	ldr r0, [r6]
	add r0, r9
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r4, [r6]
	ldr r2, _0801CE50
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, 0xC
	ldrsh r0, [r0, r3]
	lsls r0, 3
	subs r0, 0x2
	ldr r2, _0801CE54
	ldr r2, [r2]
	lsls r3, r5, 1
	adds r2, 0x50
	adds r2, r3
	ldrh r2, [r2]
	movs r3, 0x5
	str r3, [sp]
	add r4, r8
	ldr r3, [r4]
	str r3, [sp, 0x4]
	movs r3, 0x3
	bl sub_8012BC4
	adds r0, r5, 0
	bl sub_801CFE0
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0801CE0A
	ldr r0, [r6]
	ldr r4, _0801CE4C
	adds r0, r4
	adds r1, r7, 0
	bl sub_8013800
	adds r2, r0, 0
	ldr r1, [r6]
	movs r3, 0x9D
	lsls r3, 3
	adds r0, r1, r3
	ldr r0, [r0]
	adds r4, 0x38
	adds r1, r4
	ldr r1, [r1]
	movs r4, 0xC
	ldrsh r3, [r1, r4]
	subs r3, 0x1
	lsls r3, 3
	movs r1, 0xA
	str r1, [sp]
	movs r1, 0x8
	bl sub_8007B7C
_0801CE0A:
	adds r7, 0x1
	ldr r0, [r6]
	ldr r1, _0801CE48
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	blt _0801CD50
_0801CE1A:
	ldr r0, _0801CE38
	ldr r0, [r0]
	movs r3, 0x9D
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801CE38: .4byte gUnknown_203B244
_0801CE3C: .4byte gUnknown_80DBE6C
_0801CE40: .4byte 0x00000552
_0801CE44: .4byte 0x000004d2
_0801CE48: .4byte 0x000004ce
_0801CE4C: .4byte 0x000004b4
_0801CE50: .4byte 0x000004ec
_0801CE54: .4byte gUnknown_203B460
	thumb_func_end sub_801CCD8

	thumb_func_start sub_801CE58
sub_801CE58:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r3, 0
	movs r6, 0x1
	ldr r4, _0801CF0C
_0801CE68:
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0801CE92
	ldr r0, _0801CF10
	ldr r0, [r0]
	lsls r1, r6, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CE9C
	lsls r0, r6, 24
	lsrs r0, 24
	str r3, [sp]
	bl sub_8091524
	lsls r0, 24
	ldr r3, [sp]
	cmp r0, 0
	beq _0801CE9C
_0801CE92:
	ldr r0, [r4]
	adds r0, 0x4
	adds r0, r3
	strb r6, [r0]
	adds r3, 0x1
_0801CE9C:
	adds r6, 0x1
	cmp r6, 0xEF
	ble _0801CE68
	movs r6, 0
	subs r0, r3, 0x1
	mov r9, r0
	cmp r6, r9
	bge _0801CEFC
_0801CEAC:
	adds r0, r6, 0x1
	mov r8, r0
	mov r5, r8
	cmp r8, r3
	bge _0801CEF6
	ldr r7, _0801CF0C
_0801CEB8:
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r6
	ldrb r0, [r0]
	str r3, [sp]
	bl sub_8090D44
	adds r4, r0, 0
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8090D44
	ldr r3, [sp]
	cmp r4, r0
	ble _0801CEF0
	ldr r0, [r7]
	adds r0, 0x4
	adds r1, r0, r6
	ldrb r2, [r1]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x4
	adds r0, r5
	strb r2, [r0]
_0801CEF0:
	adds r5, 0x1
	cmp r5, r3
	blt _0801CEB8
_0801CEF6:
	mov r6, r8
	cmp r6, r9
	blt _0801CEAC
_0801CEFC:
	adds r0, r3, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF0C: .4byte gUnknown_203B244
_0801CF10: .4byte gUnknown_203B460
	thumb_func_end sub_801CE58

	thumb_func_start sub_801CF14
sub_801CF14:
	push {r4,lr}
	cmp r0, 0x2
	bne _0801CF1E
_0801CF1A:
	movs r0, 0
	b _0801CF46
_0801CF1E:
	movs r4, 0x1
_0801CF20:
	ldr r0, _0801CF4C
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801CF3E
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _0801CF1A
_0801CF3E:
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801CF20
	movs r0, 0x1
_0801CF46:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF4C: .4byte gUnknown_203B460
	thumb_func_end sub_801CF14

	thumb_func_start sub_801CF50
sub_801CF50:
	push {r4,r5,lr}
	cmp r0, 0x2
	bne _0801CF5A
_0801CF56:
	movs r0, 0
	b _0801CF84
_0801CF5A:
	movs r4, 0x1
	ldr r5, _0801CF8C
_0801CF5E:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801CF7C
	ldr r0, _0801CF90
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	bls _0801CF56
_0801CF7C:
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801CF5E
	movs r0, 0x1
_0801CF84:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801CF8C: .4byte 0x000003e6
_0801CF90: .4byte gUnknown_203B460
	thumb_func_end sub_801CF50

	thumb_func_start sub_801CF94
sub_801CF94:
	push {r4,lr}
	movs r2, 0
	ldr r4, _0801CFB4
	movs r3, 0
_0801CF9C:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0xF4
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0xEF
	ble _0801CF9C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801CFB4: .4byte gUnknown_203B244
	thumb_func_end sub_801CF94

	thumb_func_start sub_801CFB8
sub_801CFB8:
	push {lr}
	movs r3, 0
	ldr r0, _0801CFDC
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF4
	movs r2, 0xEF
_0801CFC6:
	ldr r0, [r1]
	cmp r0, 0
	beq _0801CFCE
	adds r3, 0x1
_0801CFCE:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0801CFC6
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0801CFDC: .4byte gUnknown_203B244
	thumb_func_end sub_801CFB8

	thumb_func_start sub_801CFE0
sub_801CFE0:
	lsls r0, 24
	ldr r1, _0801CFF0
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0xF4
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_0801CFF0: .4byte gUnknown_203B244
	thumb_func_end sub_801CFE0

	thumb_func_start sub_801CFF4
sub_801CFF4:
	lsls r0, 24
	ldr r2, _0801D004
	ldr r2, [r2]
	lsrs r0, 22
	adds r2, 0xF4
	adds r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_0801D004: .4byte gUnknown_203B244
	thumb_func_end sub_801CFF4

	thumb_func_start sub_801D008
sub_801D008:
	ldr r0, _0801D010
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0801D010: .4byte gUnknown_203B244
	thumb_func_end sub_801D008

	thumb_func_start sub_801D014
sub_801D014:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0801D054
	movs r0, 0x8C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r4]
	ldr r0, _0801D058
	ldr r0, [r0]
	str r0, [r2, 0x14]
	str r5, [r2]
	cmp r5, 0
	beq _0801D088
	movs r3, 0
	ldr r0, _0801D05C
	ldr r1, [r0]
	adds r4, r0, 0
	cmp r5, r1
	bne _0801D060
	strh r3, [r2, 0x4]
	b _0801D08C
	.align 2, 0
_0801D054: .4byte gUnknown_203B250
_0801D058: .4byte gUnknown_203B254
_0801D05C: .4byte gRecruitedPokemonRef
_0801D060:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	bgt _0801D08C
	ldr r0, _0801D084
	ldr r2, [r0]
	lsls r0, r3, 16
	asrs r0, 16
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r4]
	adds r0, r1
	ldr r1, [r2]
	cmp r1, r0
	bne _0801D060
	strh r3, [r2, 0x4]
	b _0801D08C
	.align 2, 0
_0801D084: .4byte gUnknown_203B250
_0801D088:
	ldr r0, _0801D0C4
	strh r0, [r2, 0x4]
_0801D08C:
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r4, _0801D0C8
	ldr r1, [r4]
	movs r5, 0
	strb r0, [r1, 0x6]
	ldr r0, [r4]
	strb r5, [r0, 0x8]
	ldr r0, [r4]
	strb r5, [r0, 0x9]
	bl sub_808D33C
	ldr r1, [r4]
	str r0, [r1, 0xC]
	strb r5, [r1, 0x7]
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D0CC
	movs r0, 0x5
	bl sub_801D208
	b _0801D0D2
	.align 2, 0
_0801D0C4: .4byte 0x0000019d
_0801D0C8: .4byte gUnknown_203B250
_0801D0CC:
	movs r0, 0
	bl sub_801D208
_0801D0D2:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_801D014

	thumb_func_start sub_801D0DC
sub_801D0DC:
	push {lr}
	ldr r0, _0801D0F4
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	cmp r0, 0xC
	bhi _0801D16C
	lsls r0, 2
	ldr r1, _0801D0F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D0F4: .4byte gUnknown_203B250
_0801D0F8: .4byte _0801D0FC
	.align 2, 0
_0801D0FC:
	.4byte _0801D130
	.4byte _0801D130
	.4byte _0801D16C
	.4byte _0801D136
	.4byte _0801D13C
	.4byte _0801D142
	.4byte _0801D148
	.4byte _0801D148
	.4byte _0801D14E
	.4byte _0801D154
	.4byte _0801D15A
	.4byte _0801D160
	.4byte _0801D166
_0801D130:
	bl sub_801D680
	b _0801D170
_0801D136:
	bl sub_801D760
	b _0801D170
_0801D13C:
	bl sub_801D77C
	b _0801D170
_0801D142:
	bl sub_801D798
	b _0801D170
_0801D148:
	bl sub_801D7CC
	b _0801D170
_0801D14E:
	bl sub_801D808
	b _0801D170
_0801D154:
	bl sub_801D824
	b _0801D170
_0801D15A:
	bl sub_801D840
	b _0801D170
_0801D160:
	bl sub_801D85C
	b _0801D170
_0801D166:
	bl sub_801D878
	b _0801D170
_0801D16C:
	movs r0, 0x3
	b _0801D172
_0801D170:
	movs r0, 0
_0801D172:
	pop {r1}
	bx r1
	thumb_func_end sub_801D0DC

	thumb_func_start sub_801D178
sub_801D178:
	push {r4,lr}
	ldr r0, _0801D188
	ldr r4, [r0]
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0801D18C
	movs r0, 0x2
	b _0801D1CC
	.align 2, 0
_0801D188: .4byte gUnknown_203B250
_0801D18C:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _0801D196
	movs r0, 0x3
	b _0801D1CC
_0801D196:
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0801D1A0
	movs r0, 0x1
	b _0801D1CC
_0801D1A0:
	bl sub_808D33C
	ldr r1, [r4, 0xC]
	cmp r1, r0
	bne _0801D1C6
	movs r0, 0x7
	bl sub_80A7AE8
	lsls r0, 16
	cmp r0, 0
	blt _0801D1CA
	bl sub_808D3F8
	ldrh r0, [r0]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0801D1CA
_0801D1C6:
	movs r0, 0x4
	b _0801D1CC
_0801D1CA:
	movs r0, 0
_0801D1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801D178

	thumb_func_start sub_801D1D4
sub_801D1D4:
	ldr r0, _0801D1DC
	ldr r0, [r0]
	ldrb r0, [r0, 0x7]
	bx lr
	.align 2, 0
_0801D1DC: .4byte gUnknown_203B250
	thumb_func_end sub_801D1D4

	thumb_func_start sub_801D1E0
sub_801D1E0:
	push {r4,lr}
	ldr r4, _0801D200
	ldr r2, [r4]
	cmp r2, 0
	beq _0801D1FA
	ldr r0, _0801D204
	ldr r1, [r2, 0x14]
	str r1, [r0]
	adds r0, r2, 0
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801D1FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D200: .4byte gUnknown_203B250
_0801D204: .4byte gUnknown_203B254
	thumb_func_end sub_801D1E0

	thumb_func_start sub_801D208
sub_801D208:
	push {lr}
	ldr r1, _0801D21C
	ldr r1, [r1]
	str r0, [r1, 0x10]
	bl sub_801D220
	bl sub_801D3A8
	pop {r0}
	bx r0
	.align 2, 0
_0801D21C: .4byte gUnknown_203B250
	thumb_func_end sub_801D208

	thumb_func_start sub_801D220
sub_801D220:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _0801D248
	ldr r0, [r4]
	adds r0, 0xB8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _0801D250
	cmp r0, 0x1
	beq _0801D2C0
	movs r2, 0
	adds r7, r4, 0
	ldr r3, _0801D24C
	b _0801D368
	.align 2, 0
_0801D248: .4byte gUnknown_203B250
_0801D24C: .4byte gUnknown_80DBE7C
_0801D250:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D290
	adds r7, r4, 0
	ldr r0, _0801D288
	mov r9, r0
	mov r12, r7
	ldr r2, _0801D28C
	mov r8, r2
	movs r3, 0
	movs r2, 0x3
_0801D26C:
	mov r4, r12
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r8
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D26C
	b _0801D2F6
	.align 2, 0
_0801D288: .4byte gUnknown_80DBE98
_0801D28C: .4byte gUnknown_80DBE7C
_0801D290:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D2BC
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D29C:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D29C
	b _0801D34E
	.align 2, 0
_0801D2BC: .4byte gUnknown_80DBEB0
_0801D2C0:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D324
	adds r7, r4, 0
	ldr r2, _0801D31C
	mov r9, r2
	mov r8, r7
	ldr r3, _0801D320
	mov r12, r3
	movs r3, 0
	movs r2, 0x3
_0801D2DC:
	mov r4, r8
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r12
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D2DC
_0801D2F6:
	ldr r1, [r7]
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x9
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D31C: .4byte gUnknown_80DBE98
_0801D320: .4byte gUnknown_80DBE7C
_0801D324:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D364
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D330:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D330
_0801D34E:
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x8
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D364: .4byte gUnknown_80DBEB0
_0801D368:
	ldr r0, [r7]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, 0xB8
	adds r1, r3, 0
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0801D368
_0801D384:
	bl ResetUnusedInputStruct
	ldr r0, _0801D3A4
	ldr r0, [r0]
	adds r0, 0xB8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D3A4: .4byte gUnknown_203B250
	thumb_func_end sub_801D220

	thumb_func_start sub_801D3A8
sub_801D3A8:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r1, _0801D3C4
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	adds r6, r1, 0
	cmp r0, 0xC
	bls _0801D3BA
	b _0801D4B6
_0801D3BA:
	lsls r0, 2
	ldr r1, _0801D3C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D3C4: .4byte gUnknown_203B250
_0801D3C8: .4byte _0801D3CC
	.align 2, 0
_0801D3CC:
	.4byte _0801D400
	.4byte _0801D400
	.4byte _0801D4B6
	.4byte _0801D458
	.4byte _0801D462
	.4byte _0801D468
	.4byte _0801D472
	.4byte _0801D47A
	.4byte _0801D482
	.4byte _0801D490
	.4byte _0801D49C
	.4byte _0801D4AA
	.4byte _0801D4B2
_0801D400:
	ldr r0, [r6]
	ldr r5, [r0]
	cmp r5, 0
	beq _0801D438
	ldr r4, _0801D434
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl sub_808D9AC
	ldr r2, [r6]
	str r4, [r2, 0x18]
	adds r0, r2, 0
	adds r0, 0x18
	adds r1, r2, 0
	adds r1, 0x68
	adds r3, r2, 0
	adds r3, 0xA8
	ldr r2, [r2, 0x14]
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	bl sub_8012D60
	b _0801D4B6
	.align 2, 0
_0801D434: .4byte gAvailablePokemonNames
_0801D438:
	bl sub_801D894
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x18
	adds r1, r2, 0
	adds r1, 0x68
	adds r3, r2, 0
	adds r3, 0xA8
	ldr r2, [r2, 0x14]
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0801D4B6
_0801D458:
	ldr r0, [r6]
	ldr r0, [r0]
	bl sub_80227B8
	b _0801D4B6
_0801D462:
	bl sub_8027074
	b _0801D4B6
_0801D468:
	ldr r0, [r6]
	ldr r0, [r0]
	bl sub_8025EF4
	b _0801D4B6
_0801D472:
	movs r0, 0
	bl sub_80252F0
	b _0801D4B6
_0801D47A:
	movs r0, 0x1
	bl sub_80252F0
	b _0801D4B6
_0801D482:
	ldr r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _0801D4B6
_0801D490:
	ldr r0, [r6]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl sub_801BEEC
	b _0801D4B6
_0801D49C:
	ldr r0, [r6]
	ldrb r0, [r0, 0x6]
	movs r1, 0x1
	movs r2, 0x2
	bl sub_8021774
	b _0801D4B6
_0801D4AA:
	movs r0, 0
	bl sub_802C860
	b _0801D4B6
_0801D4B2:
	bl sub_801DCC4
_0801D4B6:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_801D3A8

	thumb_func_start sub_801D4C0
sub_801D4C0:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _0801D554
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0801D568
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _0801D534
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x6C]
	ldr r0, _0801D558
	str r0, [r1, 0x68]
	bl sub_8090A34
	cmp r0, 0
	bne _0801D4FE
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x1
	strh r1, [r0]
_0801D4FE:
	ldr r1, [r4]
	ldr r0, _0801D55C
	str r0, [r1, 0x70]
	movs r0, 0x4
	str r0, [r1, 0x74]
	movs r6, 0x2
	movs r0, 0x2
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0801D534
	ldr r1, [r4]
	ldr r0, _0801D560
	str r0, [r1, 0x78]
	movs r0, 0x9
	str r0, [r1, 0x7C]
	bl sub_802C83C
	lsls r0, 24
	cmp r0, 0
	beq _0801D532
	ldr r0, [r4]
	adds r0, 0xAC
	movs r1, 0x1
	strh r1, [r0]
_0801D532:
	movs r6, 0x3
_0801D534:
	ldr r4, _0801D554
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0x68
	adds r0, r3
	ldr r1, _0801D564
	str r1, [r0]
	adds r2, 0x6C
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	adds r6, 0x1
	adds r7, r4, 0
	b _0801D5E6
	.align 2, 0
_0801D554: .4byte gUnknown_203B250
_0801D558: .4byte gMenuItems
_0801D55C: .4byte gMenuTeam
_0801D560: .4byte gMenuJobList
_0801D564: .4byte gMenuOthers
_0801D568:
	ldr r0, _0801D63C
	ldr r1, _0801D640
	bl strcpy
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _0801D5B6
	ldr r1, [r4]
	ldr r0, _0801D644
	ldr r0, [r0]
	str r0, [r1, 0x68]
	movs r0, 0x5
	str r0, [r1, 0x6C]
	movs r0, 0x4
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _0801D59A
	ldr r0, [r4]
	adds r0, 0xA8
	movs r1, 0x1
	strh r1, [r0]
_0801D59A:
	movs r6, 0x1
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x74]
	ldr r0, _0801D648
	str r0, [r1, 0x70]
	bl sub_8090A34
	cmp r0, 0
	bne _0801D5B4
	ldr r0, [r4]
	adds r0, 0xAA
	strh r6, [r0]
_0801D5B4:
	movs r6, 0x2
_0801D5B6:
	ldr r5, _0801D64C
	ldr r1, [r5]
	lsls r2, r6, 3
	adds r3, r1, 0
	adds r3, 0x68
	adds r4, r3, r2
	ldr r0, _0801D650
	ldr r0, [r0]
	str r0, [r4]
	adds r1, 0x6C
	adds r2, r1, r2
	movs r0, 0x8
	str r0, [r2]
	adds r6, 0x1
	lsls r2, r6, 3
	adds r3, r2
	ldr r0, _0801D654
	ldr r0, [r0]
	str r0, [r3]
	adds r1, r2
	movs r0, 0xA
	str r0, [r1]
	adds r6, 0x1
	adds r7, r5, 0
_0801D5E6:
	ldr r4, [r7]
	lsls r2, r6, 3
	adds r0, r4, 0
	adds r0, 0x68
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	adds r1, r4, 0
	adds r1, 0x6C
	adds r2, r1, r2
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r6
	bge _0801D622
	adds r5, r4, 0
	adds r4, 0xA8
	adds r2, r1, 0
_0801D60A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0801D618
	ldr r1, [r2]
	ldr r0, [r5, 0x14]
	cmp r1, r0
	beq _0801D67A
_0801D618:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0801D60A
_0801D622:
	movs r3, 0
	cmp r3, r6
	bge _0801D67A
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xA8
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801D658
	ldr r0, [r1, 0x6C]
	str r0, [r1, 0x14]
	b _0801D67A
	.align 2, 0
_0801D63C: .4byte gAvailablePokemonNames
_0801D640: .4byte gUnknown_80DBF34
_0801D644: .4byte gUnknown_80D49A8
_0801D648: .4byte gMenuItems
_0801D64C: .4byte gUnknown_203B250
_0801D650: .4byte gUnknown_80D4970
_0801D654: .4byte gUnknown_80D49B4
_0801D658:
	adds r3, 0x1
	cmp r3, r6
	bge _0801D67A
	ldr r2, [r7]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xA8
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801D658
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x6C
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_0801D67A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801D4C0

        .align 2,0
