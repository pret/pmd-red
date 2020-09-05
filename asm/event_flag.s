	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800135C
sub_800135C:
	push {r4-r7,lr}
	movs r1, 0
	ldr r4, _0800138C
	ldr r3, _08001390
	movs r2, 0
_08001366:
	adds r0, r1, r3
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, r4
	ble _08001366
	movs r6, 0
_08001372:
	lsls r1, r6, 4
	ldr r0, _08001394
	adds r5, r1, r0
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r7, r6, 0x1
	cmp r0, 0
	beq _080013B4
	cmp r0, 0x8
	beq _080013B4
	movs r4, 0
	b _080013AC
	.align 2, 0
_0800138C: .4byte 0x000003ff
_08001390: .4byte gUnknown_2000A88
_08001394: .4byte gUnknown_80B7394
_08001398:
	movs r0, 0xA
	ldrsh r3, [r5, r0]
	movs r0, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_800199C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080013AC:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _08001398
_080013B4:
	lsls r0, r7, 16
	asrs r6, r0, 16
	cmp r6, 0x50
	ble _08001372
	movs r0, 0
	movs r1, 0x1
	bl sub_80015C0
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x4
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x5
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x6
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x8
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x9
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xA
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xB
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0
	movs r1, 0xD
	movs r2, 0xA2
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xE
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xF
	movs r2, 0xA2
	bl sub_80018D8
	movs r4, 0x1
	negs r4, r4
	movs r0, 0
	movs r1, 0x10
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x11
	movs r2, 0x24
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x12
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x13
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x14
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x19
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1B
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1C
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1D
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1E
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1F
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x24
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x25
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x26
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x27
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x29
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x2A
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x2B
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2C
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2D
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2E
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2F
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x30
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x31
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x41
	bl sub_80015C0
	bl sub_80972F4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800135C

	thumb_func_start sub_8001564
sub_8001564:
	push {lr}
	bl nullsub_128
	pop {r0}
	bx r0
	thumb_func_end sub_8001564

	thumb_func_start sub_8001570
sub_8001570:
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _08001584
	cmp r6, r0
	bgt _0800158C
	lsls r1, r6, 4
	ldr r0, _08001588
	b _08001590
	.align 2, 0
_08001584: .4byte 0x000003ff
_08001588: .4byte gUnknown_80B7394
_0800158C:
	lsls r1, r6, 4
	ldr r0, _08001598
_08001590:
	adds r5, r1, r0
	movs r4, 0
	b _080015B0
	.align 2, 0
_08001598: .4byte 0x080b2d30
_0800159C:
	movs r0, 0xA
	ldrsh r3, [r5, r0]
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_800199C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080015B0:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _0800159C
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8001570

	thumb_func_start sub_80015C0
sub_80015C0:
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _080015D4
	cmp r6, r0
	bgt _080015DC
	lsls r1, r6, 4
	ldr r0, _080015D8
	b _080015E0
	.align 2, 0
_080015D4: .4byte 0x000003ff
_080015D8: .4byte gUnknown_80B7394
_080015DC:
	lsls r1, r6, 4
	ldr r0, _080015E8
_080015E0:
	adds r5, r1, r0
	movs r4, 0
	b _080015FE
	.align 2, 0
_080015E8: .4byte 0x080b2d30
_080015EC:
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_800199C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080015FE:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _080015EC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80015C0

	thumb_func_start sub_800160C
sub_800160C:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 16
	asrs r1, r2, 16
	ldr r0, _08001630
	cmp r1, r0
	bgt _0800163C
	lsls r1, 4
	ldr r0, _08001634
	adds r1, r0
	str r1, [r3]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	ldr r1, _08001638
	adds r0, r1
	b _0800164C
	.align 2, 0
_08001630: .4byte 0x000003ff
_08001634: .4byte gUnknown_80B7394
_08001638: .4byte gUnknown_2000A88
_0800163C:
	lsls r1, 4
	ldr r0, _08001654
	adds r1, r0
	str r1, [r3]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	lsls r0, 2
	adds r0, r4, r0
_0800164C:
	str r0, [r3, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001654: .4byte 0x080b2d30
	thumb_func_end sub_800160C

	thumb_func_start sub_8001658
sub_8001658:
	push {r4,lr}
	sub sp, 0x8
	adds r2, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	mov r0, sp
	adds r1, r2, 0
	adds r2, r4, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _0800167C
	b _08001778
_0800167C:
	lsls r0, 2
	ldr r1, _08001688
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001688: .4byte _0800168C
	.align 2, 0
_0800168C:
	.4byte _080016AC
	.4byte _080016C2
	.4byte _080016C8
	.4byte _080016D2
	.4byte _080016D8
	.4byte _080016E0
	.4byte _080016C2
	.4byte _080016E6
_080016AC:
	ldr r0, [sp]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	ands r1, r0
	b _0800173E
_080016C2:
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	b _0800177A
_080016C8:
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	b _0800177A
_080016D2:
	ldr r0, [sp, 0x4]
	ldrh r0, [r0]
	b _0800177A
_080016D8:
	ldr r0, [sp, 0x4]
	movs r1, 0
	ldrsh r0, [r0, r1]
	b _0800177A
_080016E0:
	ldr r0, [sp, 0x4]
	ldr r0, [r0]
	b _0800177A
_080016E6:
	adds r0, r4, 0
	subs r0, 0x17
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _08001778
	lsls r0, 2
	ldr r1, _080016FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080016FC: .4byte _08001700
	.align 2, 0
_08001700:
	.4byte _08001734
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001746
	.4byte _0800174C
	.4byte _08001754
	.4byte _08001764
_08001734:
	bl sub_8098F94
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
_0800173E:
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _0800177A
_08001746:
	bl sub_808D480
	b _0800177A
_0800174C:
	movs r0, 0
	bl sub_808D544
	b _0800177A
_08001754:
	ldr r0, _08001760
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	b _0800176C
	.align 2, 0
_08001760: .4byte gUnknown_203B460
_08001764:
	ldr r0, _08001774
	ldr r0, [r0]
	movs r1, 0x99
	lsls r1, 2
_0800176C:
	adds r0, r1
	ldr r0, [r0]
	b _0800177A
	.align 2, 0
_08001774: .4byte gUnknown_203B460
_08001778:
	movs r0, 0
_0800177A:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8001658

	thumb_func_start sub_8001784
sub_8001784:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	mov r0, sp
	adds r1, r3, 0
	adds r2, r5, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _080017AC
	b _080018CC
_080017AC:
	lsls r0, 2
	ldr r1, _080017B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080017B8: .4byte _080017BC
	.align 2, 0
_080017BC:
	.4byte _080017DC
	.4byte _08001800
	.4byte _08001808
	.4byte _08001814
	.4byte _0800181E
	.4byte _0800182A
	.4byte _08001800
	.4byte _08001834
_080017DC:
	ldr r0, [sp]
	ldrh r1, [r0, 0x6]
	adds r1, r4, r1
	lsls r1, 16
	lsrs r0, r1, 19
	ldr r2, [sp, 0x4]
	adds r2, r0
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldrb r0, [r2]
	ands r1, r0
	b _0800188E
_08001800:
	ldr r0, [sp, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	b _080018CE
_08001808:
	ldr r0, [sp, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	b _080018CE
_08001814:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	b _080018CE
_0800181E:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	b _080018CE
_0800182A:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 2
	adds r1, r0
	ldr r0, [r1]
	b _080018CE
_08001834:
	adds r0, r5, 0
	subs r0, 0x17
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _080018CC
	lsls r0, 2
	ldr r1, _0800184C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800184C: .4byte _08001850
	.align 2, 0
_08001850:
	.4byte _08001884
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _08001896
	.4byte _0800189C
	.4byte _080018A4
	.4byte _080018B8
_08001884:
	bl sub_8098F94
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
_0800188E:
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _080018CE
_08001896:
	bl sub_808D480
	b _080018CE
_0800189C:
	movs r0, 0
	bl sub_808D544
	b _080018CE
_080018A4:
	ldr r0, _080018B4
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	b _080018CE
	.align 2, 0
_080018B4: .4byte gUnknown_203B460
_080018B8:
	ldr r0, _080018C8
	ldr r0, [r0]
	movs r2, 0x99
	lsls r2, 2
	adds r0, r2
	ldr r0, [r0]
	b _080018CE
	.align 2, 0
_080018C8: .4byte gUnknown_203B460
_080018CC:
	movs r0, 0
_080018CE:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8001784

	thumb_func_start sub_80018D8
sub_80018D8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r2, 0
	lsls r1, 16
	asrs r5, r1, 16
	mov r0, sp
	adds r1, r3, 0
	adds r2, r5, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _08001990
	lsls r0, 2
	ldr r1, _08001908
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001908: .4byte _0800190C
	.align 2, 0
_0800190C:
	.4byte _0800192C
	.4byte _08001958
	.4byte _08001958
	.4byte _0800195E
	.4byte _0800195E
	.4byte _08001964
	.4byte _08001958
	.4byte _08001968
_0800192C:
	ldr r0, [sp]
	movs r2, 0x6
	ldrsh r1, [r0, r2]
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r3, r0, 24
	cmp r4, 0
	beq _0800194A
	ldr r2, [sp, 0x4]
	ldrb r1, [r2]
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
	b _08001990
_0800194A:
	ldr r2, [sp, 0x4]
	ldrb r1, [r2]
	adds r0, r3, 0
	orrs r0, r1
	eors r0, r3
	strb r0, [r2]
	b _08001990
_08001958:
	ldr r0, [sp, 0x4]
	strb r4, [r0]
	b _08001990
_0800195E:
	ldr r0, [sp, 0x4]
	strh r4, [r0]
	b _08001990
_08001964:
	ldr r0, [sp, 0x4]
	b _0800198E
_08001968:
	cmp r5, 0x22
	beq _08001972
	cmp r5, 0x23
	beq _08001984
	b _08001990
_08001972:
	ldr r0, _08001980
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	b _0800198E
	.align 2, 0
_08001980: .4byte gUnknown_203B460
_08001984:
	ldr r0, _08001998
	ldr r0, [r0]
	movs r2, 0x99
	lsls r2, 2
	adds r0, r2
_0800198E:
	str r4, [r0]
_08001990:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001998: .4byte gUnknown_203B460
	thumb_func_end sub_80018D8

	thumb_func_start sub_800199C
sub_800199C:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	mov r0, sp
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _08001A68
	lsls r0, 2
	ldr r1, _080019D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080019D0: .4byte _080019D4
	.align 2, 0
_080019D4:
	.4byte _080019F4
	.4byte _08001A2C
	.4byte _08001A2C
	.4byte _08001A34
	.4byte _08001A34
	.4byte _08001A3E
	.4byte _08001A2C
	.4byte _08001A44
_080019F4:
	ldr r0, [sp]
	ldrh r0, [r0, 0x6]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r2, r0, 19
	ldr r1, [sp, 0x4]
	adds r3, r1, r2
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	lsrs r1, 16
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r2, r0, 24
	cmp r6, 0
	beq _08001A20
	ldrb r1, [r3]
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3]
	b _08001A68
_08001A20:
	ldrb r1, [r3]
	adds r0, r2, 0
	orrs r0, r1
	eors r0, r2
	strb r0, [r3]
	b _08001A68
_08001A2C:
	ldr r0, [sp, 0x4]
	adds r0, r5
	strb r6, [r0]
	b _08001A68
_08001A34:
	ldr r1, [sp, 0x4]
	lsls r0, r5, 1
	adds r0, r1
	strh r6, [r0]
	b _08001A68
_08001A3E:
	ldr r1, [sp, 0x4]
	lsls r0, r5, 2
	b _08001A64
_08001A44:
	cmp r7, 0x22
	beq _08001A4E
	cmp r7, 0x23
	beq _08001A5C
	b _08001A68
_08001A4E:
	ldr r0, _08001A58
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	b _08001A64
	.align 2, 0
_08001A58: .4byte gUnknown_203B460
_08001A5C:
	ldr r0, _08001A70
	ldr r0, [r0]
	movs r1, 0x99
	lsls r1, 2
_08001A64:
	adds r0, r1
	str r6, [r0]
_08001A68:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001A70: .4byte gUnknown_203B460
	thumb_func_end sub_800199C

	thumb_func_start sub_8001A74
sub_8001A74:
	push {lr}
	sub sp, 0x8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r1, 0
	bl sub_800160C
	ldr r0, [sp, 0x4]
	add sp, 0x8
	pop {r1}
	bx r1
	thumb_func_end sub_8001A74

	thumb_func_start sub_8001A90
sub_8001A90:
	push {lr}
	sub sp, 0x8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r1, 0
	bl sub_800160C
	ldr r0, [sp]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	add sp, 0x8
	pop {r1}
	bx r1
	thumb_func_end sub_8001A90

	thumb_func_start sub_8001AB0
sub_8001AB0:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r7, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	movs r6, 0
	mov r0, sp
	movs r1, 0
	adds r2, r5, 0
	bl sub_800160C
	movs r4, 0
	ldr r0, [sp]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _08001AEC
_08001AD2:
	lsls r2, r4, 16
	lsrs r2, 16
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_8001784
	adds r6, r0
	adds r4, 0x1
	ldr r0, [sp]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _08001AD2
_08001AEC:
	adds r0, r6, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001AB0

	thumb_func_start sub_8001AF8
sub_8001AF8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r3, 16
	asrs r3, 16
	mov r0, sp
	movs r1, 0
	adds r2, r3, 0
	bl sub_800160C
	ldr r1, [sp, 0x4]
	movs r2, 0
	b _08001B1C
_08001B16:
	strb r0, [r4]
	adds r4, 0x1
	adds r2, 0x1
_08001B1C:
	cmp r2, r5
	bge _08001B28
	ldrb r0, [r1]
	adds r1, 0x1
	cmp r0, 0
	bne _08001B16
_08001B28:
	movs r0, 0
	strb r0, [r4]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8001AF8

	thumb_func_start sub_8001B34
sub_8001B34:
	push {r4,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r2, 0
	lsls r3, 16
	asrs r3, 16
	mov r0, sp
	movs r1, 0
	adds r2, r3, 0
	bl sub_800160C
	ldr r1, [sp, 0x4]
	movs r2, 0
	b _08001B56
_08001B50:
	strb r0, [r1]
	adds r1, 0x1
	adds r2, 0x1
_08001B56:
	cmp r2, r4
	bge _08001B62
	ldrb r0, [r1]
	adds r1, 0x1
	cmp r0, 0
	bne _08001B50
_08001B62:
	ldr r0, [sp]
	movs r3, 0x8
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bge _08001B7E
	movs r3, 0
_08001B6E:
	strb r3, [r1]
	adds r1, 0x1
	adds r2, 0x1
	ldr r0, [sp]
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	cmp r2, r0
	blt _08001B6E
_08001B7E:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8001B34

	thumb_func_start sub_8001B88
sub_8001B88:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	str r0, [r5]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	str r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8001B88

	thumb_func_start sub_8001BB4
sub_8001BB4:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r0, 16
	asrs r4, r0, 16
	add r2, sp, 0x10
	adds r0, r4, 0
	add r1, sp, 0xC
	bl sub_8001B88
	ldr r1, _08001C20
	ldr r3, [sp, 0xC]
	ldr r0, [sp, 0x10]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x6
	adds r2, r4, 0
	bl Log
	cmp r4, 0x3
	bne _08001BF8
	ldr r0, [sp, 0xC]
	cmp r5, r0
	bne _08001BEE
	ldr r0, [sp, 0x10]
	cmp r6, r0
	beq _08001BF8
_08001BEE:
	movs r0, 0
	movs r1, 0x19
	movs r2, 0
	bl sub_80018D8
_08001BF8:
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_800199C
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	adds r3, r6, 0
	bl sub_800199C
	cmp r4, 0x4
	beq _08001C76
	cmp r4, 0x4
	bgt _08001C24
	cmp r4, 0x3
	beq _08001C2A
	b _08001CBA
	.align 2, 0
_08001C20: .4byte gUnknown_80B72CC
_08001C24:
	cmp r4, 0xC
	beq _08001CA4
	b _08001CBA
_08001C2A:
	subs r0, r5, 0x1
	cmp r0, 0x1A
	bhi _08001CBA
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x8
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001C48
	movs r0, 0
	bl sub_80976F8
_08001C48:
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001C5E
	movs r0, 0x1
	bl sub_80976F8
_08001C5E:
	movs r0, 0x3
	movs r1, 0x11
	movs r2, 0
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001CBA
	movs r0, 0x2
	bl sub_80976F8
	b _08001CBA
_08001C76:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08001C8C
	movs r0, 0x4
	bl sub_80976F8
_08001C8C:
	movs r0, 0x4
	movs r1, 0x20
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08001CBA
	movs r0, 0x5
	bl sub_80976F8
	b _08001CBA
_08001CA4:
	movs r0, 0xC
	movs r1, 0x37
	movs r2, 0x2
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08001CBA
	movs r0, 0x3
	bl sub_80976F8
_08001CBA:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8001BB4

	thumb_func_start sub_8001CC4
sub_8001CC4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	adds r5, r0, 0
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	cmp r5, 0x3A
	beq _08001CFE
	cmp r5, r6
	bcc _08001CFA
	cmp r7, 0
	blt _08001CFE
	cmp r5, r6
	bne _08001CFE
	cmp r0, r7
	bge _08001CFE
_08001CFA:
	movs r0, 0x1
	b _08001D00
_08001CFE:
	movs r0, 0
_08001D00:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001CC4

	thumb_func_start sub_8001D08
sub_8001D08:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	adds r5, r0, 0
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	cmp r5, r6
	bne _08001D3A
	cmp r7, 0
	blt _08001D36
	cmp r0, r7
	bne _08001D3A
_08001D36:
	movs r0, 0x1
	b _08001D3C
_08001D3A:
	movs r0, 0
_08001D3C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001D08

	thumb_func_start sub_8001D44
sub_8001D44:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	adds r5, r0, 0
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	cmp r5, 0x3A
	beq _08001D7E
	cmp r5, r6
	bhi _08001D7A
	cmp r7, 0
	blt _08001D7E
	cmp r5, r6
	bne _08001D7E
	cmp r0, r7
	ble _08001D7E
_08001D7A:
	movs r0, 0x1
	b _08001D80
_08001D7E:
	movs r0, 0
_08001D80:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001D44

	thumb_func_start sub_8001D88
sub_8001D88:
	push {lr}
	sub sp, 0x8
	add r2, sp, 0x4
	movs r0, 0x3
	mov r1, sp
	bl sub_8001B88
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x1A
	bls _08001DA0
	b _080020D4
_08001DA0:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _08001E08
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0x7
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001DDE
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xE
	movs r1, 0x1
	bl sub_8097418
	movs r0, 0
	movs r1, 0x28
	movs r2, 0x2
	bl sub_80018D8
	b _08001E08
_08001DDE:
	movs r0, 0x4
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001E08
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001E08
	movs r0, 0x4
	movs r1, 0x1D
	movs r2, 0x1
	bl sub_8001BB4
_08001E08:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001E36
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001E36
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0x1
	bl sub_8001BB4
	movs r0, 0xF
	movs r1, 0x1
	bl sub_809733C
_08001E36:
	ldr r0, [sp]
	cmp r0, 0x11
	bhi _08001E3E
	b _080020D4
_08001E3E:
	movs r0, 0x25
	movs r1, 0x1
	bl sub_80973A8
	movs r0, 0xE7
	bl sub_8091130
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08001E72
	ldr r0, _080020DC
	ldr r0, [r0]
	ldr r1, _080020E0
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _08001E72
	movs r0, 0x5
	movs r1, 0x21
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001E7A
_08001E72:
	movs r0, 0x22
	movs r1, 0x1
	bl sub_80973A8
_08001E7A:
	movs r0, 0x2B
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001E8E
	movs r0, 0x1F
	movs r1, 0x1
	bl sub_80973A8
_08001E8E:
	movs r0, 0x24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001EA2
	movs r0, 0x20
	movs r1, 0x1
	bl sub_80973A8
_08001EA2:
	movs r0, 0x23
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001EB6
	movs r0, 0x21
	movs r1, 0x1
	bl sub_80973A8
_08001EB6:
	movs r0, 0x19
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001ECA
	movs r0, 0x23
	movs r1, 0x1
	bl sub_80973A8
_08001ECA:
	movs r0, 0x3
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001EE6
	movs r0, 0x24
	movs r1, 0x1
	bl sub_80973A8
	movs r0, 0x28
	movs r1, 0x1
	bl sub_80973A8
_08001EE6:
	movs r0, 0x2C
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001F06
	movs r0, 0x2D
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001F06
	movs r0, 0x26
	movs r1, 0x1
	bl sub_80973A8
_08001F06:
	movs r0, 0x5
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001F20
	movs r0, 0x5
	movs r1, 0x21
	movs r2, 0x1
	bl sub_8001BB4
_08001F20:
	movs r0, 0xE2
	bl sub_8091130
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08001F3E
	ldr r0, _080020DC
	ldr r0, [r0]
	movs r1, 0x85
	lsls r1, 2
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _08001F7E
_08001F3E:
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001F58
	movs r0, 0x7
	movs r1, 0x26
	movs r2, 0x1
	bl sub_8001BB4
_08001F58:
	movs r0, 0x9
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001F7E
	movs r0, 0x37
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001F7E
	movs r0, 0x9
	movs r1, 0x2E
	movs r2, 0x1
	bl sub_8001BB4
_08001F7E:
	movs r0, 0x9
	movs r1, 0x30
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _0800202A
	movs r0, 0x5
	movs r1, 0x22
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x90
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x91
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x92
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x5
	movs r1, 0x22
	movs r2, 0x1
	bl sub_8001BB4
_08001FCC:
	movs r0, 0xB
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08002002
	movs r0, 0x5
	movs r1, 0x21
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08002002
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08002002
	movs r0, 0xB
	movs r1, 0x33
	movs r2, 0x1
	bl sub_8001BB4
_08002002:
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08002016
	movs r0, 0x27
	movs r1, 0x1
	bl sub_80973A8
_08002016:
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _0800202A
	movs r0, 0x29
	movs r1, 0x1
	bl sub_80973A8
_0800202A:
	movs r0, 0x5
	movs r1, 0x22
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08002086
	movs r0, 0xA
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _0800205C
	movs r0, 0xA
	movs r1, 0x31
	movs r2, 0x1
	bl sub_8001BB4
	movs r0, 0x1B
	movs r1, 0x1
	bl sub_809733C
_0800205C:
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08002086
	movs r0, 0xB
	movs r1, 0x34
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08002086
	movs r0, 0xC
	movs r1, 0x35
	movs r2, 0x1
	bl sub_8001BB4
_08002086:
	movs r0, 0x6
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _080020AE
	movs r0, 0x89
	lsls r0, 1
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _080020AE
	movs r0, 0x6
	movs r1, 0x24
	movs r2, 0x1
	bl sub_8001BB4
_080020AE:
	movs r0, 0x8
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _080020D4
	ldr r0, _080020E4
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _080020D4
	movs r0, 0x8
	movs r1, 0x2C
	movs r2, 0x1
	bl sub_8001BB4
_080020D4:
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_080020DC: .4byte gUnknown_203B460
_080020E0: .4byte 0x0000021e
_080020E4: .4byte 0x00000113
	thumb_func_end sub_8001D88

	thumb_func_start _FlagCalc
_FlagCalc:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0xB
	bhi _08002182
	lsls r0, r2, 2
	ldr r1, _080020FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080020FC: .4byte _08002100
	.align 2, 0
_08002100:
	.4byte _08002130
	.4byte _08002134
	.4byte _08002138
	.4byte _0800213C
	.4byte _08002142
	.4byte _0800214C
	.4byte _08002156
	.4byte _0800215C
	.4byte _08002162
	.4byte _08002168
	.4byte _08002170
	.4byte _0800217A
_08002130:
	adds r0, r4, 0
	b _08002194
_08002134:
	subs r0, r3, r4
	b _08002194
_08002138:
	adds r0, r3, r4
	b _08002194
_0800213C:
	adds r0, r3, 0
	muls r0, r4
	b _08002194
_08002142:
	adds r0, r3, 0
	adds r1, r4, 0
	bl __divsi3
	b _08002194
_0800214C:
	adds r0, r3, 0
	adds r1, r4, 0
	bl __modsi3
	b _08002194
_08002156:
	ands r3, r4
	adds r0, r3, 0
	b _08002194
_0800215C:
	orrs r3, r4
	adds r0, r3, 0
	b _08002194
_08002162:
	eors r3, r4
	adds r0, r3, 0
	b _08002194
_08002168:
	movs r0, 0x1
	lsls r0, r4
	orrs r0, r3
	b _08002194
_08002170:
	movs r0, 0x1
	lsls r0, r4
	bics r3, r0
	adds r0, r3, 0
	b _08002194
_0800217A:
	adds r0, r4, 0
	bl OtherRandomCapped
	b _08002194
_08002182:
	ldr r0, _0800218C
	ldr r1, _08002190
	bl FatalError
	.align 2, 0
_0800218C: .4byte gUnknown_80B7318
_08002190: .4byte gUnknown_80B7324
_08002194:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end _FlagCalc

	thumb_func_start _FlagJudge
_FlagJudge:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0xA
	bhi _08002248
	lsls r0, r2, 2
	ldr r1, _080021B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080021B0: .4byte _080021B4
	.align 2, 0
_080021B4:
	.4byte _080021E0
	.4byte _080021E4
	.4byte _080021E8
	.4byte _080021FE
	.4byte _08002212
	.4byte _08002208
	.4byte _0800221C
	.4byte _080021F2
	.4byte _08002226
	.4byte _08002232
	.4byte _0800223E
_080021E0:
	movs r0, 0x1
	b _08002258
_080021E4:
	movs r0, 0
	b _08002258
_080021E8:
	movs r0, 0
	cmp r3, r4
	bne _08002258
	movs r0, 0x1
	b _08002258
_080021F2:
	adds r1, r3, 0
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _08002258
_080021FE:
	movs r0, 0
	cmp r3, r4
	ble _08002258
	movs r0, 0x1
	b _08002258
_08002208:
	movs r0, 0
	cmp r3, r4
	blt _08002258
	movs r0, 0x1
	b _08002258
_08002212:
	movs r0, 0
	cmp r3, r4
	bge _08002258
	movs r0, 0x1
	b _08002258
_0800221C:
	movs r0, 0
	cmp r3, r4
	bgt _08002258
	movs r0, 0x1
	b _08002258
_08002226:
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _08002258
	movs r0, 0x1
	b _08002258
_08002232:
	adds r0, r3, 0
	eors r0, r4
	cmp r0, 0
	beq _08002258
	movs r0, 0x1
	b _08002258
_0800223E:
	asrs r3, r4
	movs r0, 0x1
	ands r3, r0
	adds r0, r3, 0
	b _08002258
_08002248:
	ldr r0, _08002250
	ldr r1, _08002254
	bl FatalError
	.align 2, 0
_08002250: .4byte gUnknown_80B7350
_08002254: .4byte gUnknown_80B735C
_08002258:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end _FlagJudge

	thumb_func_start FlagCalc
FlagCalc:
	push {lr}
	bl _FlagCalc
	pop {r1}
	bx r1
	thumb_func_end FlagCalc

	thumb_func_start sub_800226C
sub_800226C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r4, 16
	asrs r4, 16
	adds r1, r4, 0
	bl sub_8001658
	adds r1, r5, 0
	adds r2, r6, 0
	bl _FlagCalc
	adds r2, r0, 0
	mov r0, r8
	adds r1, r4, 0
	bl sub_80018D8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800226C

	thumb_func_start sub_80022A0
sub_80022A0:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	mov r9, r3
	lsls r5, 16
	asrs r5, 16
	lsls r4, 16
	asrs r4, 16
	adds r1, r5, 0
	bl sub_8001658
	adds r6, r0, 0
	mov r0, r8
	adds r1, r4, 0
	bl sub_8001658
	adds r1, r0, 0
	adds r0, r6, 0
	mov r2, r9
	bl _FlagCalc
	adds r2, r0, 0
	mov r0, r8
	adds r1, r5, 0
	bl sub_80018D8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80022A0

	thumb_func_start FlagJudge
FlagJudge:
	push {lr}
	bl _FlagJudge
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end FlagJudge

	thumb_func_start sub_80022F8
sub_80022F8:
	push {r4,r5,lr}
	adds r4, r2, 0
	adds r5, r3, 0
	lsls r1, 16
	asrs r1, 16
	bl sub_8001658
	adds r1, r4, 0
	adds r2, r5, 0
	bl _FlagJudge
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80022F8

	thumb_func_start sub_8002318
sub_8002318:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	adds r4, r2, 0
	mov r8, r3
	lsls r1, 16
	asrs r1, 16
	lsls r4, 16
	asrs r4, 16
	bl sub_8001658
	adds r5, r0, 0
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8001658
	adds r1, r0, 0
	adds r0, r5, 0
	mov r2, r8
	bl _FlagJudge
	lsls r0, 24
	lsrs r0, 24
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8002318

	thumb_func_start sub_8002354
sub_8002354:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x3A
	bls _08002362
	movs r0, 0x1
	negs r0, r0
	b _0800236C
_08002362:
	ldr r0, _08002370
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
_0800236C:
	pop {r1}
	bx r1
	.align 2, 0
_08002370: .4byte gUnknown_80B6D90
	thumb_func_end sub_8002354

	thumb_func_start sub_8002374
sub_8002374:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x3A
	bls _08002384
	ldr r0, _08002380
	b _0800238C
	.align 2, 0
_08002380: .4byte gUnknown_80B7378
_08002384:
	ldr r0, _08002390
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
_0800238C:
	pop {r1}
	bx r1
	.align 2, 0
_08002390: .4byte gUnknown_80B6D90
	thumb_func_end sub_8002374

	thumb_func_start sub_8002394
sub_8002394:
	push {lr}
	adds r1, r0, 0
	subs r1, 0x12
	cmp r1, 0x8
	bhi _080023AC
	ldr r0, _080023A8
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	b _080023BA
	.align 2, 0
_080023A8: .4byte gUnknown_80B714C
_080023AC:
	cmp r0, 0xF
	beq _080023B8
	ldr r0, _080023B4
	b _080023BA
	.align 2, 0
_080023B4: .4byte gUnknown_80B7144
_080023B8:
	ldr r0, _080023C0
_080023BA:
	pop {r1}
	bx r1
	.align 2, 0
_080023C0: .4byte gUnknown_80B7388
	thumb_func_end sub_8002394

	thumb_func_start sub_80023C4
sub_80023C4:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x3
	bls _080023D4
	ldr r0, _080023D0
	b _080023DC
	.align 2, 0
_080023D0: .4byte gUnknown_80B7144
_080023D4:
	ldr r0, _080023E0
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
_080023DC:
	pop {r1}
	bx r1
	.align 2, 0
_080023E0: .4byte gUnknown_80B71A0
	thumb_func_end sub_80023C4

	thumb_func_start sub_80023E4
sub_80023E4:
	push {r4,lr}
	cmp r0, 0x1D
	bls _080023EC
	b _0800264E
_080023EC:
	lsls r0, 2
	ldr r1, _080023F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080023F8: .4byte _080023FC
	.align 2, 0
_080023FC:
	.4byte _08002474
	.4byte _08002482
	.4byte _0800248E
	.4byte _0800249A
	.4byte _080024A6
	.4byte _080024BE
	.4byte _080024E6
	.4byte _080024F4
	.4byte _08002500
	.4byte _0800250C
	.4byte _0800251A
	.4byte _08002526
	.4byte _08002532
	.4byte _0800255A
	.4byte _08002566
	.4byte _0800257A
	.4byte _0800258E
	.4byte _0800259C
	.4byte _080025AA
	.4byte _080025B8
	.4byte _080025C6
	.4byte _080025D4
	.4byte _080025E2
	.4byte _080025F0
	.4byte _080025FE
	.4byte _0800260C
	.4byte _0800261A
	.4byte _08002628
	.4byte _08002630
	.4byte _08002644
_08002474:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x2
	bl sub_8001D44
	b _08002648
_08002482:
	movs r0, 0x3
	movs r1, 0x3
	movs r2, 0x3
	bl sub_8001D44
	b _08002648
_0800248E:
	movs r0, 0x3
	movs r1, 0x4
	movs r2, 0x3
	bl sub_8001D44
	b _08002648
_0800249A:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0
	bl sub_8001D44
	b _08002648
_080024A6:
	movs r4, 0
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08002556
	movs r0, 0x3
	movs r1, 0xD
	b _080024D4
_080024BE:
	movs r4, 0
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08002556
	movs r0, 0x3
	movs r1, 0xF
_080024D4:
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	b _08002556
_080024E6:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x11
	bl sub_8001D44
	b _08002648
_080024F4:
	movs r0, 0x3
	movs r1, 0x12
	movs r2, 0x2
	bl sub_8001D44
	b _08002648
_08002500:
	movs r0, 0x3
	movs r1, 0x12
	movs r2, 0x3
	bl sub_8001D44
	b _08002648
_0800250C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x12
	bl sub_8001D44
	b _08002648
_0800251A:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0x4
	bl sub_8001D44
	b _08002648
_08002526:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0x4
	bl sub_8001D44
	b _08002648
_08002532:
	movs r4, 0
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x2
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	bne _08002556
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x3
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	bne _08002556
	movs r4, 0x1
_08002556:
	adds r0, r4, 0
	b _08002650
_0800255A:
	movs r0, 0x3
	movs r1, 0x10
	movs r2, 0x2
	bl sub_8001D08
	b _08002648
_08002566:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0x7
	bl sub_8001CC4
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08002640
	b _0800263E
_0800257A:
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0
	bl sub_8001CC4
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08002640
	b _0800263E
_0800258E:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x7
	bl sub_8001D44
	b _08002648
_0800259C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xC
	bl sub_8001D44
	b _08002648
_080025AA:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xD
	bl sub_8001D44
	b _08002648
_080025B8:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xF
	bl sub_8001D44
	b _08002648
_080025C6:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x10
	bl sub_8001D44
	b _08002648
_080025D4:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x5
	movs r1, 0x21
	bl sub_8001D44
	b _08002648
_080025E2:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x5
	movs r1, 0x22
	bl sub_8001D44
	b _08002648
_080025F0:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x6
	movs r1, 0x24
	bl sub_8001D44
	b _08002648
_080025FE:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x7
	movs r1, 0x2A
	bl sub_8001D44
	b _08002648
_0800260C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x8
	movs r1, 0x2C
	bl sub_8001D44
	b _08002648
_0800261A:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0xA
	movs r1, 0x31
	bl sub_8001D44
	b _08002648
_08002628:
	movs r0, 0x29
	bl sub_80973F4
	b _08002648
_08002630:
	bl sub_8092178
	movs r1, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08002640
_0800263E:
	movs r1, 0x1
_08002640:
	adds r0, r1, 0
	b _08002650
_08002644:
	bl sub_809761C
_08002648:
	lsls r0, 24
	lsrs r0, 24
	b _08002650
_0800264E:
	movs r0, 0
_08002650:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80023E4

	thumb_func_start sub_8002658
sub_8002658:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0800267C
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	movs r3, 0x1
	negs r3, r3
	cmp r0, r3
	beq _0800268C
_0800266E:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r4
	bne _08002680
	ldrb r0, [r1, 0x2]
	b _0800268E
	.align 2, 0
_0800267C: .4byte gUnknown_80B71E4
_08002680:
	adds r1, 0x4
	ldrh r2, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r3
	bne _0800266E
_0800268C:
	movs r0, 0
_0800268E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002658

	thumb_func_start sub_8002694
sub_8002694:
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, _080026B4
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	beq _080026C2
_080026A8:
	ldrb r0, [r1, 0x2]
	cmp r0, r3
	bne _080026B8
	movs r4, 0
	ldrsh r0, [r1, r4]
	b _080026C6
	.align 2, 0
_080026B4: .4byte gUnknown_80B71E4
_080026B8:
	adds r1, 0x4
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	bne _080026A8
_080026C2:
	movs r0, 0x1
	negs r0, r0
_080026C6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002694

	thumb_func_start sub_80026CC
sub_80026CC:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80026CC

	thumb_func_start sub_80026E8
sub_80026E8:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
	pop {r0}
	bx r0
	thumb_func_end sub_80026E8

	thumb_func_start sub_8002700
sub_8002700:
	push {lr}
	ldr r1, _08002714
	movs r2, 0x80
	lsls r2, 3
	bl MemoryCopy8
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08002714: .4byte gUnknown_2000A88
	thumb_func_end sub_8002700

	thumb_func_start sub_8002718
sub_8002718:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl sub_800160C
	ldr r0, _08002748
	movs r2, 0x80
	lsls r2, 3
	adds r1, r4, 0
	bl MemoryCopy8
	ldr r0, [sp]
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	ldr r0, [sp, 0x4]
	ldr r0, [r0]
	cmp r1, r0
	bne _0800274C
	movs r0, 0x1
	b _0800274E
	.align 2, 0
_08002748: .4byte gUnknown_2000A88
_0800274C:
	movs r0, 0
_0800274E:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002718

	thumb_func_start sub_8002758
sub_8002758:
	push {lr}
	adds r2, r0, 0
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x9
	bl sub_800226C
	pop {r0}
	bx r0
	thumb_func_end sub_8002758

	thumb_func_start sub_800276C
sub_800276C:
	movs r0, 0
	bx lr
	thumb_func_end sub_800276C

	.align 2, 0 @ Don't pad with nop.
