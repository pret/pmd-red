	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_806BFC0
sub_806BFC0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	adds r1, r4, 0
	adds r1, 0xA8
	movs r0, 0
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x8
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r2, r4, 0
	adds r2, 0xB4
	movs r1, 0x22
	str r1, [r2]
	adds r1, r4, 0
	adds r1, 0xBC
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x9
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x2
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0xFF
	strb r0, [r1]
	ldr r2, _0806C168
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	movs r1, 0
	movs r7, 0x84
	lsls r7, 1
	adds r0, r4, r7
	movs r5, 0x4
_0806C080:
	strb r1, [r0]
	strb r1, [r0, 0x5]
	adds r0, 0x1
	subs r5, 0x1
	cmp r5, 0
	bge _0806C080
	movs r0, 0
	str r0, [sp, 0x4]
	movs r5, 0
	adds r1, r4, 0
	adds r1, 0x5E
	str r1, [sp, 0x8]
	movs r2, 0x5C
	adds r2, r4
	mov r10, r2
	adds r7, r4, 0
	adds r7, 0xFD
	str r7, [sp, 0x20]
	adds r0, r4, 0
	adds r0, 0xF4
	str r0, [sp, 0xC]
	adds r1, 0x9D
	str r1, [sp, 0x1C]
	adds r2, r4, 0
	adds r2, 0xF5
	str r2, [sp, 0x10]
	subs r7, 0x7
	str r7, [sp, 0x14]
	adds r0, 0x3
	str r0, [sp, 0x18]
	adds r1, 0x4
	str r1, [sp, 0x24]
	movs r2, 0x1
	mov r9, r2
	movs r3, 0xA
	subs r7, 0xC2
	str r7, [sp, 0x28]
	subs r0, 0xCB
	str r0, [sp, 0x2C]
	adds r2, r4, 0
	adds r2, 0x24
	subs r1, 0xDF
	str r1, [sp, 0x38]
	adds r6, r4, 0
	adds r6, 0x1C
	movs r7, 0x80
	lsls r7, 1
	mov r8, r7
_0806C0E0:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	bl GetPokemonAbility
	ldr r7, [sp, 0x8]
	adds r1, r7, r5
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x30]
	ldr r3, [sp, 0x34]
	cmp r0, 0x25
	bne _0806C104
	movs r0, 0x1
	str r0, [sp, 0x4]
_0806C104:
	ldr r1, [sp]
	cmp r1, 0
	beq _0806C11E
	adds r0, r4, 0
	adds r0, 0x14
	adds r0, r5
	mov r7, r9
	strb r7, [r0]
	adds r0, r4, 0
	adds r0, 0x16
	adds r0, r5
	mov r1, r9
	strb r1, [r0]
_0806C11E:
	strh r3, [r6]
	ldr r7, [sp, 0x38]
	strh r3, [r7]
	strh r3, [r2]
	ldr r1, [sp, 0x2C]
	mov r0, r8
	stm r1!, {r0}
	str r1, [sp, 0x2C]
	ldr r7, [sp, 0x28]
	stm r7!, {r0}
	str r7, [sp, 0x28]
	adds r2, 0x2
	ldr r0, [sp, 0x38]
	adds r0, 0x2
	str r0, [sp, 0x38]
	adds r6, 0x2
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806C0E0
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _0806C170
	movs r0, 0
	bl GetApparentWeather
	ldr r1, _0806C16C
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	mov r2, r10
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x5D
	strb r1, [r0]
	b _0806C188
	.align 2, 0
_0806C168: .4byte 0x00000165
_0806C16C: .4byte gUnknown_80F520C
_0806C170:
	movs r5, 0
_0806C172:
	movs r7, 0x2
	ldrsh r0, [r4, r7]
	adds r1, r5, 0
	bl GetPokemonType
	mov r2, r10
	adds r1, r2, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806C172
_0806C188:
	ldr r0, _0806C1D0
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0xC]
	movs r0, 0
	strh r2, [r4, 0x28]
	movs r7, 0x89
	lsls r7, 1
	adds r1, r4, r7
	strb r0, [r1]
	ldr r1, [sp, 0x20]
	strb r0, [r1]
	ldr r2, _0806C1D4
	adds r1, r4, r2
	strb r0, [r1]
	ldr r7, [sp, 0xC]
	strb r0, [r7]
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldr r2, [sp, 0x10]
	strb r0, [r2]
	ldr r7, [sp, 0x14]
	strb r0, [r7]
	ldr r1, [sp, 0x18]
	strb r0, [r1]
	ldr r2, [sp, 0x24]
	strb r0, [r2]
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C1D0: .4byte gDungeon
_0806C1D4: .4byte 0x00000113
	thumb_func_end sub_806BFC0

	thumb_func_start sub_806C1D8
sub_806C1D8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
_0806C1E2:
	ldr r0, _0806C258
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806C25C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r5, 0x1
	mov r9, r5
	cmp r0, 0
	beq _0806C244
	ldr r4, [r4, 0x70]
	ldrb r6, [r4, 0xA]
	cmp r6, 0
	blt _0806C244
	movs r5, 0
	movs r0, 0x8C
	lsls r0, 1
	mov r12, r0
	movs r2, 0x1
	mov r8, r2
	adds r3, r4, 0
	movs r7, 0xFE
_0806C218:
	lsls r0, r5, 3
	adds r0, r4
	add r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0806C234
	ldr r0, _0806C260
	adds r2, r3, r0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2]
_0806C234:
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806C218
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_806C264
_0806C244:
	mov r5, r9
	cmp r5, 0x3
	ble _0806C1E2
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C258: .4byte gDungeon
_0806C25C: .4byte 0x0001357c
_0806C260: .4byte 0x00000119
	thumb_func_end sub_806C1D8

	thumb_func_start sub_806C264
sub_806C264:
	push {r4,r5,lr}
	mov r12, r1
	ldr r2, _0806C31C
	movs r1, 0x64
	muls r0, r1
	ldr r1, _0806C320
	adds r0, r1
	ldr r1, [r2]
	adds r3, r1, r0
	mov r2, r12
	ldrh r0, [r2, 0xE]
	strh r0, [r3, 0x10]
	ldrh r0, [r2, 0x10]
	strh r0, [r3, 0x12]
	ldr r0, [r2, 0x18]
	str r0, [r3, 0x18]
	adds r2, 0x14
	adds r1, r3, 0
	adds r1, 0x14
	movs r4, 0x1
_0806C28C:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, 0x2]
	strb r0, [r1, 0x2]
	adds r2, 0x1
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _0806C28C
	ldr r4, _0806C324
	adds r0, r4, 0
	mov r5, r12
	ldrh r5, [r5, 0x4]
	adds r0, r5
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0806C2B6
	movs r0, 0xBC
	lsls r0, 1
	strh r0, [r3, 0xE]
_0806C2B6:
	adds r1, r3, 0
	adds r1, 0x1C
	movs r0, 0x8C
	lsls r0, 1
	add r0, r12
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	mov r1, r12
	ldrb r0, [r1, 0x9]
	strb r0, [r3, 0x3]
	ldrh r0, [r1, 0xC]
	strh r0, [r3, 0x8]
	mov r0, r12
	adds r0, 0x8C
	ldr r0, [r0]
	str r0, [r3, 0x4C]
	mov r0, r12
	adds r0, 0x94
	ldrb r1, [r0]
	adds r0, r3, 0
	adds r0, 0x50
	strb r1, [r0]
	mov r2, r12
	ldr r0, [r2, 0x3C]
	str r0, [r3, 0x54]
	movs r0, 0x9E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	str r0, [r3, 0x44]
	movs r0, 0xA0
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	str r0, [r3, 0x48]
	ldr r0, [r2, 0x60]
	str r0, [r3, 0x40]
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	ldr r0, _0806C328
	cmp r1, r0
	bne _0806C316
	ldr r0, _0806C32C
	strh r0, [r3, 0xA]
_0806C316:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806C31C: .4byte gRecruitedPokemonRef
_0806C320: .4byte 0x00008df8
_0806C324: .4byte 0xfffffe87
_0806C328: .4byte 0x000055aa
_0806C32C: .4byte 0x00005aa5
	thumb_func_end sub_806C264

	thumb_func_start sub_806C330
sub_806C330:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 16
	asrs r2, 16
	mov r12, r2
	lsls r3, 24
	lsrs r7, r3, 24
	ldr r0, _0806C370
	ldr r0, [r0]
	ldr r1, _0806C374
	adds r2, r0, r1
	movs r3, 0
	ldr r0, [r2, 0x40]
	cmp r3, r0
	bge _0806C382
	mov r1, r12
	lsls r0, r1, 16
	lsrs r6, r0, 16
	adds r1, r2, 0
_0806C358:
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0806C378
	ldrb r0, [r1, 0x4]
	cmp r0, r4
	bne _0806C378
	ldrb r0, [r1, 0x5]
	cmp r0, r5
	bne _0806C378
	strh r6, [r1]
	strb r7, [r1, 0x2]
	b _0806C3B8
	.align 2, 0
_0806C370: .4byte gDungeon
_0806C374: .4byte 0x0000057c
_0806C378:
	adds r1, 0x8
	adds r3, 0x1
	ldr r0, [r2, 0x40]
	cmp r3, r0
	blt _0806C358
_0806C382:
	ldr r0, [r2, 0x40]
	cmp r0, 0x7
	bgt _0806C3B8
	lsls r0, 3
	adds r0, r2, r0
	movs r1, 0x1
	strb r1, [r0, 0x3]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r4, [r0, 0x4]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r5, [r0, 0x5]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	mov r1, r12
	strh r1, [r0]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r7, [r0, 0x2]
	ldr r0, [r2, 0x40]
	adds r0, 0x1
	str r0, [r2, 0x40]
_0806C3B8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806C330

	thumb_func_start sub_806C3C0
sub_806C3C0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	ldr r0, _0806C424
	ldr r0, [r0]
	ldr r1, _0806C428
	adds r7, r0, r1
	movs r6, 0
	ldr r0, [r7, 0x40]
	cmp r6, r0
	bge _0806C416
	mov r5, sp
	movs r0, 0
	mov r8, r0
	movs r2, 0
	adds r4, r7, 0
_0806C3E2:
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _0806C40C
	ldrh r0, [r4]
	strh r0, [r5]
	strh r2, [r5, 0x8]
	ldrb r0, [r4, 0x4]
	strh r0, [r5, 0xC]
	ldrb r0, [r4, 0x5]
	strh r0, [r5, 0xE]
	ldrb r0, [r4, 0x2]
	strb r0, [r5, 0x2]
	str r2, [sp, 0x4]
	mov r1, r8
	strb r1, [r5, 0x10]
	mov r0, sp
	movs r1, 0x1
	str r2, [sp, 0x14]
	bl sub_806B7F8
	ldr r2, [sp, 0x14]
_0806C40C:
	adds r4, 0x8
	adds r6, 0x1
	ldr r0, [r7, 0x40]
	cmp r6, r0
	blt _0806C3E2
_0806C416:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C424: .4byte gDungeon
_0806C428: .4byte 0x0000057c
	thumb_func_end sub_806C3C0

	thumb_func_start sub_806C42C
sub_806C42C:
	ldr r0, _0806C43C
	ldr r0, [r0]
	ldr r1, _0806C440
	adds r0, r1
	movs r1, 0
	str r1, [r0, 0x40]
	bx lr
	.align 2, 0
_0806C43C: .4byte gDungeon
_0806C440: .4byte 0x0000057c
	thumb_func_end sub_806C42C

	thumb_func_start sub_806C444
sub_806C444:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	bl GetBaseHP
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C478
	mov r8, sp
_0806C462:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrh r0, [r1, 0x4]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C462
_0806C478:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C444

	thumb_func_start sub_806C488
sub_806C488:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	mov r1, r8
	bl GetBaseOffensiveStat
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C4C4
	mov r0, sp
	adds r0, 0x6
	add r8, r0
_0806C4AE:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrb r0, [r1]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C4AE
_0806C4C4:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C488

	thumb_func_start sub_806C4D4
sub_806C4D4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	mov r1, r8
	bl GetBaseDefensiveStat
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C50E
	add r0, sp, 0x8
	add r8, r0
_0806C4F8:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrb r0, [r1]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C4F8
_0806C50E:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C4D4

	thumb_func_start sub_806C51C
sub_806C51C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	adds r6, r0, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	ldr r0, _0806C544
	ldr r1, [r0]
	ldr r2, _0806C548
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r6
	bne _0806C54C
	movs r3, 0
	str r3, [sp, 0x38]
	b _0806C554
	.align 2, 0
_0806C544: .4byte gDungeon
_0806C548: .4byte 0x000181f8
_0806C54C:
	ldr r4, _0806C5AC
	adds r0, r1, r4
	ldrb r0, [r0]
	str r0, [sp, 0x38]
_0806C554:
	mov r0, r8
	adds r0, 0xC8
	ldrb r1, [r0]
	str r0, [sp, 0x40]
	cmp r1, 0x2
	bne _0806C564
	movs r7, 0x1
	str r7, [sp, 0x38]
_0806C564:
	adds r0, r6, 0
	adds r0, 0x6B
	adds r1, r6, 0
	adds r1, 0x6A
	ldrb r2, [r0]
	str r0, [sp, 0x48]
	mov r9, r1
	adds r5, r6, 0
	adds r5, 0x6D
	adds r0, 0x1
	str r0, [sp, 0x4C]
	adds r4, r6, 0
	adds r4, 0x6F
	subs r1, 0x47
	str r1, [sp, 0x44]
	mov r3, r9
	ldrb r3, [r3]
	cmp r2, r3
	bne _0806C676
	ldrb r0, [r5]
	ldr r7, [sp, 0x4C]
	ldrb r7, [r7]
	cmp r0, r7
	bne _0806C654
	ldrb r0, [r4]
	cmp r0, 0
	bne _0806C654
	movs r2, 0
	ldrh r1, [r6, 0x28]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _0806C5B0
	movs r0, 0
	b _0806C5B2
	.align 2, 0
_0806C5AC: .4byte 0x00018210
_0806C5B0:
	lsrs r0, r1, 15
_0806C5B2:
	cmp r0, 0
	bne _0806C5B8
	movs r2, 0x1
_0806C5B8:
	adds r0, r6, 0
	adds r0, 0x23
	str r0, [sp, 0x44]
	cmp r2, 0
	beq _0806C654
	adds r0, r6, 0
	bl sub_806CEBC
	lsls r0, 24
	lsrs r3, r0, 24
	adds r1, r6, 0
	adds r1, 0x21
	movs r0, 0x1
	strb r0, [r1]
	mov r1, r8
	adds r1, 0xFE
	ldrb r0, [r1]
	cmp r0, 0x63
	bne _0806C620
	ldr r1, [sp, 0x48]
	ldrb r0, [r1]
	cmp r0, 0xC
	bhi _0806C61C
	mov r0, r8
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806C5F4
	movs r2, 0x2
	b _0806C600
_0806C5F4:
	ldr r2, [sp, 0x44]
	ldrb r0, [r2]
	movs r2, 0x1
	cmp r0, 0x2
	bhi _0806C600
	movs r2, 0
_0806C600:
	ldr r1, _0806C618
	movs r0, 0xD
	muls r0, r2
	ldr r7, [sp, 0x48]
	ldrb r7, [r7]
	adds r0, r7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _0806C622
	adds r0, r3, 0
	b _0806C622
	.align 2, 0
_0806C618: .4byte gUnknown_8106EC8
_0806C61C:
	movs r0, 0x63
	b _0806C622
_0806C620:
	ldrb r0, [r1]
_0806C622:
	cmp r0, 0x63
	beq _0806C654
	mov r1, r9
	strb r0, [r1]
	ldrb r1, [r5]
	movs r0, 0x7
	ands r0, r1
	ldr r2, [sp, 0x4C]
	strb r0, [r2]
	movs r0, 0x1
	strb r0, [r4]
	mov r7, r9
	ldrb r0, [r7]
	cmp r0, 0x6
	bne _0806C654
	adds r1, r6, 0
	adds r1, 0x6E
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	bne _0806C654
	strb r3, [r7]
_0806C654:
	ldr r1, [sp, 0x48]
	ldrb r0, [r1]
	mov r2, r9
	ldrb r2, [r2]
	cmp r0, r2
	bne _0806C676
	ldrb r0, [r5]
	ldr r3, [sp, 0x4C]
	ldrb r3, [r3]
	cmp r0, r3
	bne _0806C676
	ldrb r0, [r4]
	movs r7, 0x28
	adds r7, r6
	mov r10, r7
	cmp r0, 0
	beq _0806C714
_0806C676:
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, [sp, 0x48]
	strb r0, [r2]
	ldr r3, [sp, 0x4C]
	mov r10, r3
	ldrb r0, [r3]
	strb r0, [r5]
	movs r7, 0
	strb r7, [r4]
	adds r0, r6, 0
	adds r0, 0x68
	movs r1, 0
	ldrsh r7, [r0, r1]
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	mov r4, r9
	ldrb r1, [r4]
	bl sub_808DA44
	lsls r0, 24
	cmp r0, 0
	beq _0806C6A8
	movs r7, 0
_0806C6A8:
	ldr r0, [sp, 0x38]
	cmp r0, 0
	bne _0806C6D6
	bl Rand32Bit
	movs r4, 0x3
	ands r4, r0
	adds r5, r6, 0
	adds r5, 0x28
	ldr r1, [r6, 0x64]
	mov r3, r9
	ldrb r2, [r3]
	mov r0, r10
	ldrb r3, [r0]
	str r7, [sp]
	str r4, [sp, 0x4]
	ldr r4, [sp, 0x38]
	str r4, [sp, 0x8]
	adds r0, r5, 0
	bl AxResInitFile
	mov r10, r5
	b _0806C704
_0806C6D6:
	ldr r0, _0806C774
	bl GetSpriteData
	adds r5, r0, 0
	bl Rand32Bit
	movs r1, 0x3
	ands r1, r0
	adds r4, r6, 0
	adds r4, 0x28
	mov r0, r9
	ldrb r2, [r0]
	ldr r0, [sp, 0x4C]
	ldrb r3, [r0]
	str r7, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r0, r4, 0
	adds r1, r5, 0
	bl AxResInitFile
	mov r10, r4
_0806C704:
	mov r2, r9
	ldrb r0, [r2]
	cmp r0, 0x6
	beq _0806C714
	adds r1, r6, 0
	adds r1, 0x6E
	movs r0, 0
	strb r0, [r1]
_0806C714:
	ldr r0, _0806C778
	ldr r1, [r0]
	ldr r3, _0806C77C
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C784
	ldr r4, [sp, 0x48]
	ldrb r0, [r4]
	cmp r0, 0x7
	bne _0806C73C
	mov r7, r8
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl GetMovementType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0806C7E2
_0806C73C:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C76A
	movs r0, 0xB0
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C7E2
	ldr r0, _0806C780
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C76A
	mov r0, r10
	bl RunAxAnimationFrame
	mov r0, r10
	bl RunAxAnimationFrame
_0806C76A:
	mov r0, r10
	bl RunAxAnimationFrame
	b _0806C7E2
	.align 2, 0
_0806C774: .4byte 0x000001a5
_0806C778: .4byte gDungeon
_0806C77C: .4byte 0x0001356c
_0806C780: .4byte 0x0000015f
_0806C784:
	mov r0, r8
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806C7E2
	cmp r0, 0x6
	beq _0806C7E2
	ldr r2, _0806C7B4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C7BC
	ldr r3, _0806C7B8
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C7BC
	mov r0, r10
	bl RunAxAnimationFrame
	mov r0, r10
	bl RunAxAnimationFrame
	b _0806C7DC
	.align 2, 0
_0806C7B4: .4byte 0x0000066c
_0806C7B8: .4byte 0x0001c05f
_0806C7BC:
	ldr r4, [sp, 0x48]
	ldrb r0, [r4]
	cmp r0, 0
	beq _0806C7C8
	cmp r0, 0x7
	bne _0806C7DC
_0806C7C8:
	ldr r0, [r6, 0x70]
	movs r7, 0x82
	lsls r7, 1
	adds r0, r7
	ldr r0, [r0]
	cmp r0, 0x1
	ble _0806C7DC
	mov r0, r10
	bl RunAxAnimationFrame
_0806C7DC:
	mov r0, r10
	bl RunAxAnimationFrame
_0806C7E2:
	ldr r1, [r6, 0xC]
	ldr r0, [r6, 0x14]
	cmp r1, r0
	bne _0806C800
	ldr r1, [r6, 0x10]
	ldr r0, [r6, 0x18]
	cmp r1, r0
	bne _0806C800
	ldr r1, [sp, 0x44]
	ldrb r0, [r1]
	cmp r0, 0x9
	bhi _0806C806
	adds r0, 0x1
	strb r0, [r1]
	b _0806C806
_0806C800:
	movs r0, 0
	ldr r2, [sp, 0x44]
	strb r0, [r2]
_0806C806:
	ldr r0, [r6, 0xC]
	str r0, [r6, 0x14]
	ldr r2, [r6, 0x10]
	str r2, [r6, 0x18]
	cmp r0, 0
	bge _0806C814
	adds r0, 0xFF
_0806C814:
	asrs r1, r0, 8
	ldr r0, _0806C88C
	ldr r3, [r0]
	ldr r4, _0806C890
	adds r0, r3, r4
	movs r7, 0
	ldrsh r0, [r0, r7]
	subs r1, r0
	str r1, [sp, 0x2C]
	ldr r0, [r6, 0x1C]
	subs r0, r2, r0
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	ldr r1, [r1]
	subs r0, r1
	cmp r0, 0
	bge _0806C83A
	adds r0, 0xFF
_0806C83A:
	asrs r1, r0, 8
	ldr r4, _0806C894
	adds r0, r3, r4
	movs r7, 0
	ldrsh r3, [r0, r7]
	subs r1, r3
	str r1, [sp, 0x30]
	adds r0, r2, 0
	cmp r0, 0
	bge _0806C850
	adds r0, 0xFF
_0806C850:
	asrs r0, 8
	subs r0, r3
	mov r9, r0
	lsrs r0, 31
	add r0, r9
	asrs r0, 1
	mov r9, r0
	movs r0, 0xAB
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C870
	movs r0, 0x1
	negs r0, r0
	add r9, r0
_0806C870:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C898
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x34]
	b _0806C8D8
	.align 2, 0
_0806C88C: .4byte gDungeon
_0806C890: .4byte 0x000181f0
_0806C894: .4byte 0x000181f2
_0806C898:
	ldr r0, _0806C8B8
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C8C6
	ldr r0, _0806C8BC
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0806C8C0
	ldr r1, [sp, 0x2C]
	adds r1, 0x1
	str r1, [sp, 0x2C]
	b _0806C8C6
	.align 2, 0
_0806C8B8: .4byte 0x0000015d
_0806C8BC: .4byte gUnknown_202EDCC
_0806C8C0:
	ldr r2, [sp, 0x2C]
	subs r2, 0x1
	str r2, [sp, 0x2C]
_0806C8C6:
	movs r1, 0
	movs r0, 0xAF
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C8D6
	movs r1, 0x1
_0806C8D6:
	str r1, [sp, 0x34]
_0806C8D8:
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0806C8E0
	adds r0, 0xFF
_0806C8E0:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _0806C998
	ldr r2, [sp, 0x28]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x28]
	ldr r1, [r6, 0x10]
	ldr r0, [r6, 0x1C]
	subs r1, r0
	movs r5, 0xBA
	lsls r5, 1
	add r5, r8
	ldr r0, [r5]
	subs r0, r1, r0
	cmp r0, 0
	bge _0806C904
	adds r0, 0xFF
_0806C904:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _0806C99C
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x28]
	add r0, sp, 0xC
	mov r1, r10
	bl sub_8005700
	mov r4, r8
	adds r4, 0x98
	ldr r0, [r4]
	add r1, sp, 0x28
	ldr r2, _0806C9A0
	ldr r2, [r2]
	ldr r3, _0806C9A4
	adds r2, r3
	ldrb r3, [r2]
	add r2, sp, 0xC
	bl sub_800F958
	adds r0, r6, 0
	bl EntityGetStatusSprites
	adds r2, r0, 0
	ldr r4, [r4]
	mov r0, r8
	movs r1, 0x4
	ldrsh r7, [r0, r1]
	movs r3, 0
	ldr r0, [sp, 0x34]
	cmp r0, 0
	beq _0806C958
	movs r0, 0xA6
	lsls r0, 1
	add r0, r8
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r3, r0, 31
_0806C958:
	adds r0, r4, 0
	adds r1, r7, 0
	bl UpdateDungeonPokemonSprite
	adds r0, r6, 0
	mov r1, r9
	bl sub_8042EC8
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r1, [r0]
	cmp r1, 0
	bne _0806C9BA
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806C9AC
	ldr r1, [r5]
	ldr r0, _0806C9A8
	cmp r1, r0
	bgt _0806C9BA
	movs r2, 0x80
	lsls r2, 4
	adds r0, r1, r2
	str r0, [r5]
	movs r1, 0xC8
	lsls r1, 8
	cmp r0, r1
	ble _0806C9BA
	b _0806C9B8
	.align 2, 0
_0806C998: .4byte 0xffff0000
_0806C99C: .4byte 0x0000ffff
_0806C9A0: .4byte gDungeon
_0806C9A4: .4byte 0x00018208
_0806C9A8: .4byte 0x0000c7ff
_0806C9AC:
	ldr r0, [r5]
	ldr r3, _0806CA5C
	adds r0, r3
	str r0, [r5]
	cmp r0, 0
	bge _0806C9BA
_0806C9B8:
	str r1, [r5]
_0806C9BA:
	ldr r4, [sp, 0x34]
	cmp r4, 0
	bne _0806C9C2
	b _0806CBDE
_0806C9C2:
	movs r4, 0
	adds r0, r6, 0
	bl sub_806CF54
	lsls r0, 24
	lsrs r7, r0, 24
	add r1, sp, 0x1C
	ldr r2, _0806CA60
	strh r2, [r1]
	ldr r0, _0806CA64
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	strh r4, [r1, 0x6]
	strh r4, [r1, 0x8]
	ldr r0, _0806CA68
	ldr r0, [r0]
	ldr r2, _0806CA6C
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 10
	strh r0, [r1, 0xA]
	mov r3, r8
	ldrb r0, [r3, 0x6]
	adds r5, r1, 0
	cmp r0, 0
	beq _0806CA08
	ldr r1, _0806CA70
	adds r0, r1, 0
	ldrh r2, [r3, 0x4]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0806CA08
	movs r4, 0x1
_0806CA08:
	mov r0, r8
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806CA22
	ldr r0, _0806CA68
	ldr r0, [r0]
	ldr r3, _0806CA74
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806CA22
	movs r4, 0x1
_0806CA22:
	cmp r4, 0
	beq _0806CA32
	ldrh r1, [r5, 0x6]
	movs r4, 0x80
	lsls r4, 3
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r5, 0x6]
_0806CA32:
	movs r0, 0
	str r0, [sp, 0x3C]
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0806CA46
	ldr r2, [sp, 0x40]
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _0806CA4A
_0806CA46:
	movs r3, 0x1
	str r3, [sp, 0x3C]
_0806CA4A:
	mov r0, r8
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0806CA58
	cmp r0, 0x47
	bne _0806CA78
_0806CA58:
	movs r0, 0x1
	b _0806CA7A
	.align 2, 0
_0806CA5C: .4byte 0xfffff400
_0806CA60: .4byte 0x0000f3ff
_0806CA64: .4byte 0x0000ffff
_0806CA68: .4byte gDungeon
_0806CA6C: .4byte 0x00018208
_0806CA70: .4byte 0xfffffe5f
_0806CA74: .4byte 0x0001820f
_0806CA78:
	movs r0, 0
_0806CA7A:
	cmp r0, 0
	bne _0806CA88
	mov r0, r8
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806CA8C
_0806CA88:
	movs r4, 0x1
	str r4, [sp, 0x3C]
_0806CA8C:
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0806CB16
	mov r0, r8
	adds r0, 0xB0
	ldrb r1, [r0]
	cmp r1, 0x6
	beq _0806CAAC
	subs r0, 0x4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0806CAAC
	cmp r1, 0x2
	bne _0806CABA
_0806CAAC:
	ldr r0, _0806CAC4
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	ldr r1, [sp, 0x2C]
	adds r1, r0
	str r1, [sp, 0x2C]
_0806CABA:
	ldr r2, [sp, 0x38]
	cmp r2, 0
	beq _0806CACC
	ldr r0, _0806CAC8
	b _0806CAD2
	.align 2, 0
_0806CAC4: .4byte gUnknown_202EDCC
_0806CAC8: .4byte 0x000001a5
_0806CACC:
	mov r3, r8
	movs r4, 0x4
	ldrsh r0, [r3, r4]
_0806CAD2:
	movs r1, 0
	bl GetPokemonOverworldPalette
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r6, 0
	adds r0, 0x22
	ldrb r1, [r0]
	cmp r1, 0
	bne _0806CAF8
	str r2, [sp]
	str r5, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	mov r3, r9
	bl DoAxFrame_800558C
	b _0806CB16
_0806CAF8:
	cmp r1, 0x1
	bne _0806CB16
	ldr r0, _0806CBF0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _0806CB16
	str r2, [sp]
	str r5, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	mov r3, r9
	bl DoAxFrame_800558C
_0806CB16:
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0806CB1E
	adds r0, 0xFF
_0806CB1E:
	asrs r0, 8
	ldrh r1, [r6, 0x38]
	adds r0, r1
	movs r1, 0xB8
	lsls r1, 1
	add r1, r8
	strh r0, [r1]
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _0806CB34
	adds r0, 0xFF
_0806CB34:
	asrs r0, 8
	ldrh r2, [r6, 0x3A]
	adds r0, r2
	movs r3, 0xB9
	lsls r3, 1
	add r3, r8
	strh r0, [r3]
	movs r4, 0
	ldrsh r2, [r1, r4]
	ldr r0, _0806CBF4
	ldr r1, [r0]
	ldr r4, _0806CBF8
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	subs r4, r2, r0
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r3, _0806CBFC
	adds r1, r3
	movs r3, 0
	ldrsh r0, [r1, r3]
	subs r5, r2, r0
	movs r0, 0x20
	negs r0, r0
	cmp r4, r0
	blt _0806CBDE
	cmp r5, r0
	blt _0806CBDE
	ldr r0, _0806CC00
	cmp r4, r0
	bgt _0806CBDE
	cmp r5, 0xBF
	bgt _0806CBDE
	cmp r7, 0x6
	beq _0806CBDE
	adds r0, r6, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806CBDE
	ldr r0, [sp, 0x3C]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	ldr r1, _0806CC04
	adds r0, r1
	adds r3, r2, r0
	movs r0, 0xAB
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806CBDE
	movs r2, 0x8
	ldrsh r1, [r3, r2]
	adds r1, r4, r1
	ldr r0, _0806CC08
	ands r1, r0
	ldrh r2, [r3, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x2]
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	adds r1, r5, r1
	ldr r0, _0806CC0C
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r3, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x6]
	adds r0, r3, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0806CBDE:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806CBF0: .4byte gUnknown_202EDCC
_0806CBF4: .4byte gDungeon
_0806CBF8: .4byte 0x000181f0
_0806CBFC: .4byte 0x000181f2
_0806CC00: .4byte 0x0000010f
_0806CC04: .4byte gUnknown_202ED28
_0806CC08: .4byte 0x000001ff
_0806CC0C: .4byte 0x00000fff
	thumb_func_end sub_806C51C

        .align 2,0
