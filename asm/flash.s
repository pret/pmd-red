	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800CF0C
sub_800CF0C:
	push {lr}
	bl IdentifyFlash
	lsls r0, 16
	cmp r0, 0
	bne _0800CF32
	movs r0, 0x3
	bl sub_800B6E8
	adds r1, r0, 0
	movs r0, 0x2
	bl SetFlashTimerIntr
	lsls r0, 16
	cmp r0, 0
	bne _0800CF32
	ldr r1, _0800CF38
	movs r0, 0x1
	strb r0, [r1]
_0800CF32:
	pop {r0}
	bx r0
	.align 2, 0
_0800CF38: .4byte gUnknown_203B0B4
	thumb_func_end sub_800CF0C

	thumb_func_start sub_800CF3C
sub_800CF3C:
	push {lr}
	ldr r0, _0800CF54
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800CF4E
	ldr r0, _0800CF58
	ldr r0, [r0]
	bl _call_via_r0
_0800CF4E:
	pop {r0}
	bx r0
	.align 2, 0
_0800CF54: .4byte gUnknown_203B0B4
_0800CF58: .4byte EraseFlashChip
	thumb_func_end sub_800CF3C

	thumb_func_start sub_800CF5C
sub_800CF5C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r5, r2, 0
	ldr r0, _0800CFAC
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800CFB4
	adds r4, r1, 0
	ldr r0, _0800CFB0
	cmp r5, r0
	ble _0800CF94
	movs r7, 0x80
	lsls r7, 5
	mov r8, r0
_0800CF7C:
	lsls r0, r6, 16
	lsrs r0, 16
	movs r1, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl ReadFlash
	adds r6, 0x1
	adds r4, r7
	subs r5, r7
	cmp r5, r8
	bgt _0800CF7C
_0800CF94:
	cmp r5, 0
	ble _0800CFA6
	lsls r0, r6, 16
	lsrs r0, 16
	movs r1, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl ReadFlash
_0800CFA6:
	movs r0, 0
	b _0800CFB6
	.align 2, 0
_0800CFAC: .4byte gUnknown_203B0B4
_0800CFB0: .4byte 0x00000fff
_0800CFB4:
	movs r0, 0x3
_0800CFB6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800CF5C

	thumb_func_start sub_800CFC0
sub_800CFC0:
	push {r4-r6,lr}
	ldr r4, _0800CFD8
	add sp, r4
	adds r6, r0, 0
	adds r5, r2, 0
	ldr r0, _0800CFDC
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800D03C
	movs r2, 0x1
	adds r4, r1, 0
	b _0800CFEC
	.align 2, 0
_0800CFD8: .4byte 0xfffff000
_0800CFDC: .4byte gUnknown_203B0B4
_0800CFE0:
	adds r6, 0x1
	movs r0, 0x80
	lsls r0, 5
	adds r4, r0
	ldr r0, _0800D034
	adds r5, r0
_0800CFEC:
	ldr r0, _0800D038
	cmp r5, r0
	ble _0800D002
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_800D04C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0800CFE0
_0800D002:
	cmp r2, 0
	beq _0800D03C
	cmp r5, 0
	ble _0800D02C
	movs r2, 0x80
	lsls r2, 5
	mov r0, sp
	movs r1, 0xFF
	bl MemoryFill8
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	bl MemoryCopy8
	adds r0, r6, 0
	mov r1, sp
	bl sub_800D04C
	lsls r0, 24
	lsrs r2, r0, 24
_0800D02C:
	cmp r2, 0
	beq _0800D03C
	movs r0, 0
	b _0800D03E
	.align 2, 0
_0800D034: .4byte 0xfffff000
_0800D038: .4byte 0x00000fff
_0800D03C:
	movs r0, 0x3
_0800D03E:
	movs r3, 0x80
	lsls r3, 5
	add sp, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800CFC0

	thumb_func_start sub_800D04C
sub_800D04C:
	push {r4-r7,lr}
	adds r5, r1, 0
	movs r6, 0x3
	ldr r7, _0800D07C
	lsls r0, 16
	lsrs r4, r0, 16
_0800D058:
	ldr r2, [r7]
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r2
	lsls r0, 16
	cmp r0, 0
	bne _0800D080
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x80
	lsls r2, 5
	bl VerifyFlashSectorNBytes
	cmp r0, 0
	bne _0800D080
	movs r0, 0x1
	b _0800D08A
	.align 2, 0
_0800D07C: .4byte ProgramFlashSector
_0800D080:
	adds r0, r6, 0
	subs r6, 0x1
	cmp r0, 0
	bgt _0800D058
	movs r0, 0
_0800D08A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800D04C

	.align 2, 0 @ Don't pad with nop.
