	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
	bl PrintColoredPokeNameToBuffer
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
	bl InitializeJobListMenu
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
	bl GetNumberOfFilledInventorySlots
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
	bl HasNoAcceptedJobs
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
	bl GetNumberOfFilledInventorySlots
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
