        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801F280
sub_801F280:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, _0801F30C
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl CallPrepareTextbox_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x4C
	add r0, sp, 0x4
	movs r2, 0xA
	bl sub_80922B4
	ldr r0, _0801F310
	add r1, sp, 0x4
	bl strcpy
	ldr r2, _0801F314
	ldr r0, [r4]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	bl PrintFormatStringOnWindow
	movs r7, 0
	ldr r0, [r4]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _0801F394
	add r5, sp, 0x18
	mov r8, r4
	movs r0, 0x1
	mov r9, r0
_0801F2E0:
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xC
	bl memset
	movs r0, 0x6A
	str r0, [r5, 0x4]
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r7, 3
	ldr r0, [r2, 0x10]
	adds r4, r0, r1
	ldrb r1, [r4]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _0801F386
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	beq _0801F318
	movs r0, 0x2
	b _0801F31A
	.align 2, 0
_0801F30C: .4byte gUnknown_203B270
_0801F310: .4byte gFormatBuffer_Monsters
_0801F314: .4byte gUnknown_80DC28C
_0801F318:
	movs r0, 0x4
_0801F31A:
	str r0, [sp, 0x18]
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0801F328
	mov r0, r9
_0801F328:
	strb r0, [r5, 0x9]
	cmp r7, 0x3
	ble _0801F332
	mov r1, r9
	strb r1, [r5, 0x8]
_0801F332:
	ldr r0, _0801F3EC
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80928A0
	ldr r2, _0801F3F0
	ldr r0, [r2]
	adds r0, 0x1C
	adds r1, r7, 0
	str r2, [sp, 0x24]
	bl sub_8013800
	adds r6, r0, 0
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	movs r4, 0xD
	ldr r2, [sp, 0x24]
	cmp r0, 0
	bne _0801F372
	movs r4, 0x8
	cmp r7, 0
	beq _0801F372
	ldr r0, [r2]
	ldr r0, [r0, 0x50]
	subs r2, r6, 0x2
	movs r1, 0x7
	str r1, [sp]
	movs r1, 0xC
	movs r3, 0x78
	bl sub_800792C
_0801F372:
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	ldr r2, _0801F3F4
	bl PrintFormatStringOnWindow
_0801F386:
	adds r7, 0x1
	mov r1, r8
	ldr r0, [r1]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _0801F2E0
_0801F394:
	ldr r4, _0801F3F0
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073E0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801F3DC
	mov r0, r10
	cmp r0, 0
	beq _0801F3DC
	ldr r0, [r1, 0x54]
	bl CallPrepareTextbox_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073B8
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r2, [r0]
	ldr r3, [r1, 0x54]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0
	bl PrintFormatStringOnWindow
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073E0
_0801F3DC:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F3EC: .4byte gFormatBuffer_Items
_0801F3F0: .4byte gUnknown_203B270
_0801F3F4: .4byte gUnknown_80DC2A0
	thumb_func_end sub_801F280

        .align 2,0
