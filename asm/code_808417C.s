	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80841EC
sub_80841EC:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC4
	add r0, sp, 0x60
	mov r8, r0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x64]
	add r1, sp, 0x68
	movs r6, 0
	movs r0, 0x4
	strh r0, [r1]
	movs r2, 0x3
	strh r2, [r1, 0x2]
	add r1, sp, 0x6C
	movs r0, 0x16
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6E
	movs r5, 0xE
	movs r1, 0xE
	strh r1, [r0]
	add r0, sp, 0x70
	strh r1, [r0]
	add r4, sp, 0xC0
	str r4, [sp, 0x74]
	str r2, [sp, 0x7C]
	add r0, sp, 0x90
	str r2, [r0, 0x4]
	add r0, sp, 0xA8
	str r2, [r0, 0x4]
	mov r0, sp
	mov r1, r8
	movs r2, 0x60
	bl memcpy
	movs r0, 0x1
	strb r0, [r4]
	strb r6, [r4, 0x1]
	strb r5, [r4, 0x2]
	strb r6, [r4, 0x3]
	mov r1, sp
	movs r0, 0x14
	strh r0, [r1, 0xA]
	mov r0, sp
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, _0808426C
	ldr r0, [r0]
	ldr r1, _08084270
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r0, _08084274
	cmp r1, r0
	ble _08084278
	bl PlayDungeonCompleteBGM
	b _0808427C
	.align 2, 0
_0808426C: .4byte gDungeon
_08084270: .4byte 0x0001ceac
_08084274: .4byte 0x00000225
_08084278:
	bl PlayDungeonFailBGM
_0808427C:
	ldr r0, _080842B8
	ldr r1, [r0]
	ldr r0, _080842BC
	ldr r2, [r0]
	ldr r0, _080842C0
	adds r2, r0
	movs r0, 0
	bl sub_8094558
	mov r4, sp
_08084290:
	movs r0, 0x36
	bl sub_803E668
	bl UpdateDungeonMusic
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	ble _080842C4
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0xA0
	strb r0, [r4]
	mov r0, sp
	movs r1, 0x1
	bl sub_803ECB4
	b _08084290
	.align 2, 0
_080842B8: .4byte gUnknown_80FE6E8
_080842BC: .4byte gDungeon
_080842C0: .4byte 0x0001ce98
_080842C4:
	bl sub_8094D14
	lsls r0, 24
	cmp r0, 0
	bne _080842DA
	ldr r0, _080842EC
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08084290
_080842DA:
	bl sub_8083D08
	add sp, 0xC4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080842EC: .4byte gRealInputs
	thumb_func_end sub_80841EC

	thumb_func_start sub_80842F0
sub_80842F0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, _0808436C
	ldr r0, [r1]
	ldr r2, _08084370
	adds r0, r2
	movs r2, 0
	strb r2, [r0]
	ldr r0, [r1]
	ldr r3, _08084374
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r1]
	movs r5, 0xCF
	lsls r5, 3
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080843AE
	movs r6, 0
	ldr r0, _08084378
	mov r8, r0
	movs r7, 0x1
_08084320:
	lsls r0, r6, 24
	lsrs r0, 24
	bl GetJobSlotInfo
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x6
	bne _080843A8
	ldr r3, _0808436C
	ldr r5, [r3]
	ldr r1, _0808437C
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r4, 0x4]
	mov r1, r8
	ands r1, r0
	mov r0, r8
	ands r0, r2
	cmp r1, r0
	bne _080843A8
	ldrb r0, [r4, 0x1]
	cmp r0, 0x3
	beq _080843A8
	cmp r0, 0x4
	bne _08084380
	ldrb r1, [r4, 0x10]
	ldr r2, _08084374
	adds r0, r5, r2
	strb r1, [r0]
	ldr r2, [r3]
	ldrh r1, [r4, 0xE]
	movs r3, 0xD1
	lsls r3, 3
	adds r0, r2, r3
	strh r1, [r0]
	strb r7, [r2, 0x9]
	b _080843A8
	.align 2, 0
_0808436C: .4byte gDungeon
_08084370: .4byte 0x00000677
_08084374: .4byte 0x0000068a
_08084378: .4byte 0x0000ffff
_0808437C: .4byte 0x00000644
_08084380:
	cmp r0, 0
	beq _0808438C
	cmp r0, 0x2
	beq _0808438C
	cmp r0, 0x1
	bne _080843A8
_0808438C:
	ldr r2, [r3]
	ldrh r0, [r4, 0xE]
	movs r5, 0xD1
	lsls r5, 3
	adds r1, r2, r5
	strh r0, [r1]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _080843A4
	ldr r1, _080843B8
	adds r0, r2, r1
	strb r7, [r0]
_080843A4:
	ldr r0, [r3]
	strb r7, [r0, 0x9]
_080843A8:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08084320
_080843AE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080843B8: .4byte 0x00000677
	thumb_func_end sub_80842F0

	thumb_func_start sub_80843BC
sub_80843BC:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r6, r0, 16
	movs r4, 0
	ldr r5, _08084418
_080843C6:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetJobSlotInfo
	adds r3, r0, 0
	ldrb r0, [r3]
	cmp r0, 0x6
	bne _0808440C
	ldr r0, _0808441C
	ldr r0, [r0]
	ldr r1, _08084420
	adds r0, r1
	ldrh r0, [r0]
	ldrh r2, [r3, 0x4]
	adds r1, r5, 0
	ands r1, r0
	adds r0, r5, 0
	ands r0, r2
	cmp r1, r0
	bne _0808440C
	ldrb r0, [r3, 0x1]
	cmp r0, 0
	beq _08084400
	cmp r0, 0x4
	beq _08084400
	cmp r0, 0x2
	beq _08084400
	cmp r0, 0x1
	bne _0808440C
_08084400:
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	cmp r6, r0
	bne _0808440C
	movs r0, 0x8
	strb r0, [r3]
_0808440C:
	adds r4, 0x1
	cmp r4, 0x7
	ble _080843C6
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08084418: .4byte 0x0000ffff
_0808441C: .4byte gDungeon
_08084420: .4byte 0x00000644
	thumb_func_end sub_80843BC

	thumb_func_start sub_8084424
sub_8084424:
	push {r4,lr}
	movs r4, 0
_08084428:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetJobSlotInfo
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x8
	bne _0808443C
	movs r0, 0x9
	strb r0, [r1]
_0808443C:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08084428
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8084424

	thumb_func_start sub_8084448
sub_8084448:
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r7, [r5, 0x70]
	ldr r4, _0808447C
	bl GetLeader
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _08084484
	ldr r0, _08084480
	b _080844F0
	.align 2, 0
_0808447C: .4byte gAvailablePokemonNames
_08084480: .4byte gUnknown_80FA464
_08084484:
	ldr r4, _080844FC
	ldr r0, [r4]
	ldr r6, _08084500
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08084540
	ldr r0, _08084504
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	beq _080844A4
	b _080845D4
_080844A4:
	ldr r0, _08084508
	ldr r1, [r4]
	adds r1, r6
	ldrb r1, [r1]
	movs r2, 0
	bl BufferItemName
	movs r3, 0
	ldr r0, _0808450C
	adds r6, r0, 0
	ldr r2, [r6]
_080844BA:
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080844E2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080844E2
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0x18
	beq _080844E2
	ldr r0, [r4]
	ldr r1, _08084500
	adds r0, r1
	ldrb r1, [r2, 0x2]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080844EA
_080844E2:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _080844BA
_080844EA:
	cmp r3, 0x14
	bne _08084514
	ldr r0, _08084510
_080844F0:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _080845D4
	.align 2, 0
_080844FC: .4byte gDungeon
_08084500: .4byte 0x0000068a
_08084504: .4byte gUnknown_80FA32C
_08084508: .4byte gUnknown_202DE58
_0808450C: .4byte gTeamInventoryRef
_08084510: .4byte gUnknown_80FA448
_08084514:
	lsls r1, r3, 2
	ldr r0, [r6]
	adds r1, r0
	movs r0, 0
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	strb r0, [r1]
	bl FillInventoryGaps
	ldr r0, _08084538
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	ldr r0, _0808453C
	b _0808455E
	.align 2, 0
_08084538: .4byte gUnknown_80FA2B0
_0808453C: .4byte gUnknown_80FA370
_08084540:
	ldr r0, _080845B0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _080845D4
	ldr r0, _080845B4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	ldr r0, _080845B8
_0808455E:
	ldr r4, [r0]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl sub_80843BC
	adds r0, r5, 0x4
	bl sub_8042A34
	movs r1, 0x87
	lsls r1, 2
	adds r0, r5, 0
	movs r2, 0
	bl sub_8068FE0
	movs r0, 0x1
	bl sub_804178C
	ldr r5, _080845BC
_08084582:
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _080845C4
	ldr r0, _080845C0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	adds r1, r0, 0
	cmp r1, 0x1
	bne _08084582
	ldr r0, [r5]
	strb r1, [r0, 0x4]
	ldr r1, [r5]
	movs r0, 0x2
	strb r0, [r1, 0x11]
	b _080845D4
	.align 2, 0
_080845B0: .4byte gUnknown_80FA2F0
_080845B4: .4byte gUnknown_80FA260
_080845B8: .4byte gUnknown_80FA36C
_080845BC: .4byte gDungeon
_080845C0: .4byte gUnknown_80FA394
_080845C4:
	ldr r0, _080845DC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08084582
_080845D4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080845DC: .4byte gUnknown_80FA3B8
	thumb_func_end sub_8084448

	thumb_func_start sub_80845E0
sub_80845E0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	movs r7, 0
	movs r1, 0
	mov r9, r1
	ldr r4, _08084620
	bl GetLeader
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _08084630
	ldr r0, _08084624
	b _080846B4
	.align 2, 0
_08084620: .4byte gAvailablePokemonNames
_08084624: .4byte gUnknown_80FA530
_08084628:
	adds r7, r4, 0
	ldr r2, [r7, 0x70]
	mov r9, r2
	b _08084674
_08084630:
	movs r5, 0
_08084632:
	ldr r0, _08084660
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08084664
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0808466E
	ldr r0, [r4, 0x70]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0808465A
	cmp r0, 0x47
	bne _08084668
_0808465A:
	movs r0, 0x1
	b _0808466A
	.align 2, 0
_08084660: .4byte gDungeon
_08084664: .4byte 0x0001357c
_08084668:
	movs r0, 0
_0808466A:
	cmp r0, 0
	bne _08084628
_0808466E:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08084632
_08084674:
	cmp r7, 0
	bne _08084680
	ldr r0, _0808467C
	b _080846B4
	.align 2, 0
_0808467C: .4byte gUnknown_80FA52C
_08084680:
	ldr r0, _0808469C
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _080846A4
	ldr r0, _080846A0
	b _080846B4
	.align 2, 0
_0808469C: .4byte gUnknown_202E038
_080846A0: .4byte gUnknown_80FA54C
_080846A4:
	adds r0, r6, 0
	adds r1, r7, 0
	bl CanSeeTarget
	lsls r0, 24
	cmp r0, 0
	bne _080846C4
	ldr r0, _080846C0
_080846B4:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08084768
	.align 2, 0
_080846C0: .4byte gUnknown_80FA500
_080846C4:
	ldr r0, _08084744
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	mov r1, r8
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80843BC
	ldr r5, _08084748
	ldr r0, [r5]
	ldr r1, _0808474C
	adds r0, r1
	ldrb r1, [r0]
	mov r0, r9
	adds r0, 0x40
	strb r1, [r0]
	adds r0, r6, 0x4
	bl sub_8042A34
	adds r0, r7, 0x4
	bl sub_8042A34
	movs r4, 0x87
	lsls r4, 2
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8068FE0
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8068FE0
	movs r0, 0x1
	bl sub_804178C
	ldr r4, _08084750
_08084716:
	movs r0, 0
	ldr r1, [r4]
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08084758
	ldr r0, _08084754
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	adds r1, r0, 0
	cmp r1, 0x1
	bne _08084716
	ldr r0, [r5]
	strb r1, [r0, 0x4]
	ldr r1, [r5]
	movs r0, 0x2
	strb r0, [r1, 0x11]
	b _08084768
	.align 2, 0
_08084744: .4byte gUnknown_80FA4D4
_08084748: .4byte gDungeon
_0808474C: .4byte 0x00000644
_08084750: .4byte gUnknown_80FA4D8
_08084754: .4byte gUnknown_80FA394
_08084758:
	ldr r0, _08084774
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08084716
_08084768:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084774: .4byte gUnknown_80FA3B8
	thumb_func_end sub_80845E0

	thumb_func_start sub_8084778
sub_8084778:
	push {r4,lr}
	ldr r0, _080847B8
	ldr r1, _080847BC
	bl strcpy
	movs r4, 0
_08084784:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetJobSlotInfo
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _080847C8
	ldr r0, _080847C0
	ldr r0, [r0]
	ldr r2, _080847C4
	adds r0, r2
	ldrb r0, [r0]
	ldrb r2, [r1, 0x4]
	cmp r0, r2
	bne _080847C8
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	bne _080847C8
	movs r0, 0xE
	ldrsh r1, [r1, r0]
	ldr r0, _080847B8
	bl CopyCyanMonsterNametoBuffer
	b _080847CE
	.align 2, 0
_080847B8: .4byte gUnknown_202E088
_080847BC: .4byte gUnknown_8107224
_080847C0: .4byte gDungeon
_080847C4: .4byte 0x00000644
_080847C8:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08084784
_080847CE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8084778

	thumb_func_start sub_80847D4
sub_80847D4:
	push {r4,r5,lr}
	ldr r2, _08084820
	ldr r0, [r2]
	ldr r1, _08084824
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _08084828
	adds r0, r2
	strb r1, [r0]
	bl sub_8040A84
	movs r4, 0
	ldr r0, _0808482C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08084846
	movs r3, 0
_080847FA:
	ldr r0, _08084820
	ldr r0, [r0]
	ldr r5, _08084830
	adds r0, r5
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r1, 0
	subs r0, 0x1C
	cmp r0, 0x15
	bhi _08084810
	movs r1, 0x1B
_08084810:
	ldr r2, _0808482C
	adds r0, r3, r2
	ldrb r5, [r0]
	cmp r1, r5
	bne _08084834
	bl sub_8084854
	b _08084846
	.align 2, 0
_08084820: .4byte gDungeon
_08084824: .4byte 0x00003a0d
_08084828: .4byte 0x0001356c
_0808482C: .4byte gUnknown_8107234
_08084830: .4byte 0x00003a14
_08084834:
	adds r3, 0x8
	adds r4, 0x1
	ldr r0, _08084850
	cmp r4, r0
	bgt _08084846
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080847FA
_08084846:
	bl sub_8097FF8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084850: .4byte 0x000003e6
	thumb_func_end sub_80847D4

	.align 2,0
