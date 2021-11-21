        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CreateMailboxMenu
CreateMailboxMenu:
	push {r4-r7,lr}
	ldr r4, _0802E380
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802E384
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x2
	str r0, [r1]
	bl HasNoMailinMailbox
	lsls r0, 24
	cmp r0, 0
	beq _0802E2E6
	ldr r0, [r4]
	adds r0, 0xFC
	movs r1, 0x1
	strh r1, [r0]
_0802E2E6:
	movs r5, 0x1
	ldr r1, [r4]
	movs r6, 0x1
	adds r2, r1, 0
	adds r2, 0xC4
	ldr r0, _0802E388
	str r0, [r2]
	adds r1, 0xC8
	movs r0, 0x3
	str r0, [r1]
	bl HasNoAcceptedJobs
	lsls r0, 24
	cmp r0, 0
	beq _0802E30A
	ldr r0, [r4]
	adds r0, 0xFE
	strh r5, [r0]
_0802E30A:
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xCC
	ldr r0, _0802E38C
	str r0, [r2]
	adds r1, 0xD0
	movs r0, 0x4
	str r0, [r1]
	bl HasNoPKMNNews
	lsls r0, 24
	cmp r0, 0
	beq _0802E32E
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_0802E32E:
	movs r5, 0x3
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xD4
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r6, [r0]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0xFC
	adds r2, 0xC0
_0802E34A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802E35A
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x64]
	cmp r1, r0
	beq _0802E3B2
_0802E35A:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802E34A
	movs r3, 0
	cmp r3, r5
	bge _0802E3B2
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xFC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802E390
	adds r0, r1, 0
	adds r0, 0xC0
	ldr r0, [r0]
	str r0, [r1, 0x64]
	b _0802E3B2
	.align 2, 0
_0802E380: .4byte gUnknown_203B304
_0802E384: .4byte gMailboxCheckMail
_0802E388: .4byte gMailboxJobList
_0802E38C: .4byte gMailboxPKMNNews
_0802E390:
	adds r3, 0x1
	cmp r3, r5
	bge _0802E3B2
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xFC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802E390
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xC0
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x64]
_0802E3B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateMailboxMenu

	thumb_func_start CreateMailActionMenu
CreateMailActionMenu:
	push {r4-r7,lr}
	movs r5, 0
	ldr r4, _0802E3F0
	ldr r0, [r4]
	ldrb r0, [r0, 0x8]
	bl sub_8095FE8
	adds r7, r0, 0
	ldrb r0, [r7]
	cmp r0, 0x1
	bne _0802E3FC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xBC
	ldr r0, _0802E3F4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x6
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802E3F8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	movs r5, 0x2
	b _0802E44A
	.align 2, 0
_0802E3F0: .4byte gUnknown_203B304
_0802E3F4: .4byte gMailActionStore
_0802E3F8: .4byte gMailActionRead
_0802E3FC:
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xBC
	ldr r0, _0802E494
	ldr r0, [r0]
	str r0, [r2]
	adds r1, 0xC0
	movs r0, 0x5
	str r0, [r1]
	adds r0, r7, 0
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	bne _0802E422
	bl GetNumAcceptedJobs
	cmp r0, 0x7
	ble _0802E42C
_0802E422:
	ldr r0, [r4]
	adds r0, 0xC0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0802E42C:
	adds r5, 0x1
	ldr r4, _0802E498
	ldr r2, [r4]
	lsls r3, r5, 3
	adds r0, r2, 0
	adds r0, 0xBC
	adds r0, r3
	ldr r1, _0802E49C
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0xC0
	adds r2, r3
	movs r0, 0x8
	str r0, [r2]
	adds r5, 0x1
_0802E44A:
	mov r12, r4
	mov r0, r12
	ldr r4, [r0]
	lsls r2, r5, 3
	adds r0, r4, 0
	adds r0, 0xBC
	adds r0, r2
	movs r1, 0
	str r1, [r0]
	adds r1, r4, 0
	adds r1, 0xC0
	adds r2, r1, r2
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r5
	bge _0802E486
	movs r6, 0x1
	negs r6, r6
	adds r2, r1, 0
_0802E472:
	ldr r1, [r2]
	cmp r1, r6
	beq _0802E47E
	ldr r0, [r4, 0x68]
	cmp r1, r0
	beq _0802E4A8
_0802E47E:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802E472
_0802E486:
	ldrb r0, [r7]
	cmp r0, 0x1
	bne _0802E4A0
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x7
	b _0802E4A6
	.align 2, 0
_0802E494: .4byte gUnknown_80D4990
_0802E498: .4byte gUnknown_203B304
_0802E49C: .4byte gUnknown_80D4970
_0802E4A0:
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x8
_0802E4A6:
	str r0, [r1, 0x68]
_0802E4A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateMailActionMenu

        .align 2,0
