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
_08019F70: .4byte gTeamInventory_203B460
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
_0801A1B8: .4byte gTeamInventory_203B460
_0801A1BC:
	mov r0, r8
	ldr r1, _0801A204
	add r2, sp, 0x4
	bl ExpandPlaceholdersBuffer
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
_0801A33C: .4byte gTeamInventory_203B460
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
_0801A584: .4byte gTeamInventory_203B460
_0801A588:
	mov r0, r8
	ldr r1, _0801A5D0
	add r2, sp, 0x4
	bl ExpandPlaceholdersBuffer
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
	bl CanSellItem
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
_0801A7EC: .4byte gTeamInventory_203B460
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
_0801AA9C: .4byte gTeamInventory_203B460
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
	bl CanSellItem
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
	bl ExpandPlaceholdersBuffer
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
_0801AC00: .4byte gTeamInventory_203B460
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
	bl xxx_format_and_draw
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
	bl xxx_format_and_draw
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
	bl IsNotMoneyOrUsedTMItem
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
_0801ADEC: .4byte gTeamInventory_203B460
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
_0801AE68: .4byte gTeamInventory_203B460
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
	bl GetItemOrder
	adds r4, r0, 0
	ldr r2, [sp]
	ldr r0, [r2]
	lsls r5, r7, 2
	adds r0, r5
	ldrb r0, [r0, 0x2]
	bl GetItemOrder
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
_0801AF90: .4byte gTeamInventory_203B460
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


        .align 2,0
