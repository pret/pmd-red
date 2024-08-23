	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80A14E8
sub_80A14E8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _080A1514
	add sp, r4
	adds r6, r0, 0
	adds r5, r2, 0
	adds r7, r3, 0
	lsls r1, 24
	lsrs r1, 24
	subs r0, r1, 0x1
	cmp r0, 0x49
	bls _080A1508
	bl _080A236A
_080A1508:
	lsls r0, 2
	ldr r1, _080A1518
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A1514: .4byte 0xfffffc80
_080A1518: .4byte _080A151C
	.align 2, 0
_080A151C:
	.4byte _080A1644
	.4byte _080A164C
	.4byte _080A1672
	.4byte _080A167A
	.4byte _080A1680
	.4byte _080A1688
	.4byte _080A1690
	.4byte _080A1698
	.4byte _080A169E
	.4byte _080A16C6
	.4byte _080A1730
	.4byte _080A1756
	.4byte _080A178C
	.4byte _080A1792
	.4byte _080A17C0
	.4byte _080A17C6
	.4byte _080A1800
	.4byte _080A1814
	.4byte _080A1824
	.4byte _080A1840
	.4byte _080A185E
	.4byte _080A18C2
	.4byte _080A18E2  @ Wigglytuff Club Opening
	.4byte _080A18F2
	.4byte _080A1904
	.4byte _080A197C
	.4byte _080A1988
	.4byte _080A19DC
	.4byte _080A19FC
	.4byte _080A1A0E
	.4byte _080A1A18
	.4byte _080A1A70
	.4byte _080A1AF8
	.4byte _080A1B20
	.4byte _080A1B36
	.4byte _080A1B58
	.4byte _080A1B64
	.4byte _080A1BD8
	.4byte _080A1BE4
	.4byte _080A1C30
	.4byte _080A1C84
	.4byte _080A1DEC
	.4byte _080A1E30
	.4byte _080A1E3C
	.4byte _080A1ED0
	.4byte _080A1ED6
	.4byte _080A1F28
	.4byte _080A1F3C
	.4byte _080A1F44
	.4byte _080A1F50
	.4byte _080A1F80
	.4byte _080A1FDA
	.4byte _080A202C
	.4byte _080A2054
	.4byte _080A2060
	.4byte _080A204A
	.4byte _080A206C
	.4byte _080A2076
	.4byte _080A207C
	.4byte _080A2082
	.4byte _080A20D4
	.4byte _080A20F4
	.4byte _080A21E4
	.4byte _080A228C
	.4byte _080A229E
	.4byte _080A2298
	.4byte _080A22AE
	.4byte _080A22CC
	.4byte _080A22E4
	.4byte _080A2304
	.4byte _080A2320
	.4byte _080A232E
	.4byte _080A233A
	.4byte _080A2346
_080A1644:
	bl sub_8098C58
	bl _080A236A
_080A164C:
	bl sub_8011C34
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080A1660
	bl Rand32Bit
	bl sub_8011C40
_080A1660:
	movs r0, 0x1
	bl sub_8011C28
	bl sub_8001064
	bl sub_809965C
	bl _080A236A
_080A1672:
	bl sub_8098CC8
	bl _080A236A
_080A167A:
	bl sub_80961D8
	b _080A1804
_080A1680:
	bl ResetMailbox
	bl _080A236A
_080A1688:
	bl sub_80963FC
	bl _080A236A
_080A1690:
	bl sub_8096488
	bl _080A236A
_080A1698:
	bl sub_80964B4
	b _080A1804
_080A169E:
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A16B0
	bl sub_808D4B0
	b _080A16B4
_080A16B0:
	bl sub_808D500
_080A16B4:
	lsls r0, 24
	lsrs r4, r0, 24
	bl nullsub_104
	negs r0, r4
	orrs r0, r4
	lsrs r0, 31
	bl _080A236C
_080A16C6:
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080A16D2
	bl _080A236A
_080A16D2:
	movs r2, 0xE
	ldrsh r0, [r6, r2]
	add r1, sp, 0x314
	bl sub_80A8C4C
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _080A16E8
	bl _080A236A
_080A16E8:
	add r0, sp, 0x314
	ldrb r0, [r0]
	cmp r0, 0x44
	bne _080A16FC
	movs r0, 0x82
	lsls r0, 1
	cmp r1, r0
	bne _080A16FC
	bl _080A203C
_080A16FC:
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_80A90C8
	lsls r0, 16
	ldr r1, _080A172C
	asrs r0, 14
	adds r0, r1
	ldr r1, [r0]
	add r0, sp, 0x4
	bl strcpy
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0x4
	bl ScriptPrintText
_080A171E:
	lsls r0, 24
_080A1720:
	cmp r0, 0
	beq _080A1726
	b _080A1EBE
_080A1726:
	bl _080A236A
	.align 2, 0
_080A172C: .4byte gFriendAreaDialogue
_080A1730:
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2740
	lsls r0, 24
	lsrs r0, 24
	bl CountJobsinDungeon
	movs r1, 0
	cmp r0, 0
	ble _080A1750
	movs r1, 0x1
_080A1750:
	adds r0, r1, 0
	bl _080A236C
_080A1756:
	add r4, sp, 0x104
	adds r0, r4, 0
	bl sub_8099394
	lsls r0, 24
	cmp r0, 0
	bne _080A1768
	bl _080A236A
_080A1768:
	ldr r0, _080A1788
	ldr r1, [r0]
	ldrb r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r1, r0
	adds r1, 0x2C
	movs r0, 0
	ldrsb r0, [r1, r0]
_080A177C:
	cmp r0, 0
	ble _080A1782
	b _080A1EBE
_080A1782:
	bl _080A236A
	.align 2, 0
_080A1788: .4byte gUnknown_203B480
_080A178C:
	bl sub_8097640
	b _080A1804
_080A1792:
	movs r5, 0x11
_080A1794:
	lsls r4, r5, 16
	asrs r0, r4, 16
	bl IsMazeCompleted
	lsls r0, 24
	cmp r0, 0
	beq _080A17B6
	lsrs r4, 16
	movs r0, 0
	movs r1, 0x2F
	adds r2, r4, 0
	bl sub_8001784
	cmp r0, 0
	bne _080A17B6
	bl _080A234E
_080A17B6:
	adds r5, 0x1
	cmp r5, 0x16
	ble _080A1794
	bl _080A236A
_080A17C0:
	bl sub_80964E4
	b _080A1804
_080A17C6:
	movs r4, 0x8
	ldrsh r0, [r6, r4]
	cmp r0, 0x1
	beq _080A17D2
	bl _080A236A
_080A17D2:
	movs r5, 0xA
	ldrsh r0, [r6, r5]
	cmp r0, 0
	beq _080A17DE
	bl _080A236A
_080A17DE:
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080A17EA
	bl _080A236A
_080A17EA:
	movs r2, 0xA
	ldrsh r4, [r6, r2]
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_80A8E9C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_80A87E0
	b _080A171E
_080A1800:
	bl sub_80A8D20
_080A1804:
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bl _080A236C
_080A1814:
	ldr r0, _080A1820
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 2
	ands r0, r1
	b _080A1720
	.align 2, 0
_080A1820: .4byte gRealInputs
_080A1824:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_80A8D54
	cmp r0, 0
	bne _080A1834
	bl _080A236A
_080A1834:
	ldrh r0, [r0]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	bl _080A236C
_080A1840:
	movs r4, 0x8
	ldrsh r0, [r6, r4]
	cmp r0, 0x1
	beq _080A184C
	bl _080A236A
_080A184C:
	movs r5, 0xA
	ldrsh r0, [r6, r5]
	bl sub_80A8BFC
	lsls r0, 16
	asrs r0, 16
	bl CanMove
	b _080A171E
_080A185E:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _080A1872
	bl _080A236A
_080A1872:
	lsls r4, r7, 8
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	add r7, sp, 0x318
	ldr r2, [r1, 0xC]
	adds r1, r7, 0
	bl _call_via_r2
	add r6, sp, 0x320
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80A8FD8
	add r0, sp, 0x318
	ldr r3, [r0]
	subs r1, r3, r4
	add r0, sp, 0x320
	ldr r2, [r0]
	cmp r1, r2
	ble _080A189E
	bl _080A236A
_080A189E:
	adds r0, r3, r4
	cmp r0, r2
	bge _080A18A8
	bl _080A236A
_080A18A8:
	ldr r2, [r7, 0x4]
	subs r0, r2, r4
	ldr r1, [r6, 0x4]
	cmp r0, r1
	ble _080A18B6
	bl _080A236A
_080A18B6:
	adds r0, r2, r4
	cmp r0, r1
	blt _080A18BE
	b _080A1EBE
_080A18BE:
	bl _080A236A
_080A18C2:
	movs r0, 0x1
	bl sub_80A8D54
	cmp r0, 0
	bne _080A18D0
	bl _080A236A
_080A18D0:
	adds r1, r0, 0
	adds r1, 0x4C
	movs r2, 0
	adds r0, 0x55
_080A18D8:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _080A18D8
	b _080A1EBE
_080A18E2: @ Wigglytuff Guild Opening
	movs r0, 0xC @ Wild Plains
	bl UnlockFriendArea
	movs r0, 0x12 @ Mist-Rise Forest
	bl UnlockFriendArea
	bl _080A236A
_080A18F2:
	ldr r0, _080A1900
	movs r1, 0x3C
_080A18F6:
	movs r2, 0xA
	bl sub_80A8F50
	bl _080A236A
	.align 2, 0
_080A1900: .4byte gUnknown_2039D98
_080A1904:
	movs r0, 0x51
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl UnlockFriendArea
	add r1, sp, 0x4
	ldr r0, _080A1970
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r4, sp, 0x2C
	adds r0, r4, 0
	add r1, sp, 0x4
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A193C
	b _080A1EBE
_080A193C:
	movs r3, 0
	ldr r1, _080A1974
	mov r8, r1
	lsls r6, r5, 2
	ldr r2, _080A1978
	adds r4, r0, 0
	adds r4, 0x4C
	mov r7, r8
_080A194C:
	adds r0, r4, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _080A194C
_080A195A:
	adds r0, r6, r5
	lsls r0, 4
	adds r0, r2
	mov r1, r8
	movs r2, 0xA
	bl sub_80922B4
_080A1968:
	bl sub_8097848
	bl _080A236A
	.align 2, 0
_080A1970: .4byte gUnknown_8116710
_080A1974: .4byte gUnknown_2039D98
_080A1978: .4byte gPlayerName
_080A197C:
	ldr r0, _080A1984
	movs r1, 0x53
	b _080A18F6
	.align 2, 0
_080A1984: .4byte gUnknown_2039D98
_080A1988:
	ldr r0, _080A19D4
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl UnlockFriendArea
	add r1, sp, 0x84
	adds r2, r1, 0
	ldr r0, _080A19D8
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0xAC
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	adds r4, r0, 0
	cmp r4, 0
	bne _080A19C2
	b _080A1EBE
_080A19C2:
	bl sub_8097848
	ldrh r1, [r4]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r4]
	bl _080A236A
	.align 2, 0
_080A19D4: .4byte 0x00000183
_080A19D8: .4byte gUnknown_8116738
_080A19DC:
	ldr r0, _080A19F8
	movs r1, 0
	bl sub_808D434
	adds r2, r0, 0
	cmp r2, 0
	bne _080A19EC
	b _080A1EBE
_080A19EC:
	ldrh r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r2]
	bl _080A236A
	.align 2, 0
_080A19F8: .4byte 0x00000183
_080A19FC:
	movs r0, 0x82
	lsls r0, 1
_080A1A00:
	bl sub_808D278
	cmp r0, 0
	bne _080A1A0A
	b _080A1EBE
_080A1A0A:
	bl _080A236A
_080A1A0E:
	ldr r0, _080A1A14
	movs r1, 0x7C
	b _080A18F6
	.align 2, 0
_080A1A14: .4byte gUnknown_2039D98
_080A1A18:
	add r1, sp, 0x108
	adds r2, r1, 0
	ldr r0, _080A1A64
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x130
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1A42
	b _080A1EBE
_080A1A42:
	movs r3, 0
	ldr r4, _080A1A68
	mov r8, r4
	lsls r6, r5, 2
	ldr r2, _080A1A6C
	adds r4, r0, 0
	adds r4, 0x4C
	mov r7, r8
_080A1A52:
	adds r0, r4, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _080A1A52
	b _080A195A
	.align 2, 0
_080A1A64: .4byte gUnknown_8116760
_080A1A68: .4byte gUnknown_2039D98
_080A1A6C: .4byte gPlayerName
_080A1A70:
	movs r0, 0x9E
	movs r1, 0x1
	bl sub_80026E8
	movs r0, 0x91
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	bne _080A1A9A
	ldr r3, _080A1AEC
	str r0, [sp]
	movs r0, 0x91
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	beq _080A1A9A
	bl sub_8097848
_080A1A9A:
	movs r0, 0x92
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	bne _080A1ABC
	ldr r3, _080A1AF0
	str r0, [sp]
	movs r0, 0x92
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	beq _080A1ABC
	bl sub_8097848
_080A1ABC:
	movs r0, 0x90
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	beq _080A1ACC
	bl _080A236A
_080A1ACC:
	ldr r3, _080A1AF4
	str r0, [sp]
	movs r0, 0x90
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	bne _080A1AE2
	bl _080A236A
_080A1AE2:
	bl sub_8097848
	bl _080A236A
	.align 2, 0
_080A1AEC: .4byte gUnknown_8116788
_080A1AF0: .4byte gUnknown_811678C
_080A1AF4: .4byte gUnknown_8116790
_080A1AF8:
	movs r0, 0x90
	bl HasRecruitedMon
	lsls r0, 24
	cmp r0, 0
	bne _080A1B08
	bl _080A236A
_080A1B08:
	movs r0, 0x91
	bl HasRecruitedMon
	lsls r0, 24
	cmp r0, 0
	bne _080A1B18
	bl _080A236A
_080A1B18:
	movs r0, 0x92
	bl HasRecruitedMon
	b _080A171E
_080A1B20:
	bl GetPlayerPokemonStruct
	ldrh r0, [r0, 0x8]
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080A1B32
	b _080A1EBE
_080A1B32:
	bl _080A236A
_080A1B36:
	bl GetPlayerPokemonStruct
	cmp r0, 0
	beq _080A1B4A
	movs r5, 0x8
	ldrsh r1, [r0, r5]
	ldr r0, _080A1B54
	cmp r1, r0
	bne _080A1B4A
	b _080A203C
_080A1B4A:
	ldr r0, _080A1B54
	bl sub_8098134
	b _080A171E
	.align 2, 0
_080A1B54: .4byte 0x00000113
_080A1B58:
	ldr r0, _080A1B60
	movs r1, 0x79
	b _080A18F6
	.align 2, 0
_080A1B60: .4byte gUnknown_2039D98
_080A1B64:
	ldr r4, _080A1BCC
	adds r0, r4, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _080A1B88
	adds r0, r4, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl UnlockFriendArea
_080A1B88:
	add r1, sp, 0x188
	adds r2, r1, 0
	ldr r0, _080A1BD0
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r0!, {r4-r6}
	stm r2!, {r4-r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x1B0
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1BB2
	b _080A1EBE
_080A1BB2:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1BD4
_080A1BBA:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1BBA
	b _080A1968
	.align 2, 0
_080A1BCC: .4byte 0x00000199
_080A1BD0: .4byte gUnknown_8116794
_080A1BD4: .4byte gUnknown_2039D98
_080A1BD8:
	ldr r0, _080A1BE0
	movs r1, 0x7A
	b _080A18F6
	.align 2, 0
_080A1BE0: .4byte gUnknown_2039D98
_080A1BE4:
	add r1, sp, 0x208
	adds r2, r1, 0
	ldr r0, _080A1C28
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x230
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1C0E
	b _080A1EBE
_080A1C0E:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1C2C
_080A1C16:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1C16
	b _080A1968
	.align 2, 0
_080A1C28: .4byte gUnknown_81167BC
_080A1C2C: .4byte gUnknown_2039D98
_080A1C30:
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	ble _080A1C70
	ldr r0, _080A1C64
	ldrb r4, [r0, 0x2]
	adds r0, r4, 0
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	cmp r0, 0
	bne _080A1C4A
	b _080A236A
_080A1C4A:
	ldr r0, _080A1C68
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r1, r0, r1
	ldrh r2, [r1]
	ldr r0, _080A1C6C
	cmp r2, r0
	bls _080A1C5E
	b _080A236A
_080A1C5E:
	adds r0, r2, 0x1
	strh r0, [r1]
	b _080A236A
	.align 2, 0
_080A1C64: .4byte gUnknown_81167E4
_080A1C68: .4byte gTeamInventoryRef
_080A1C6C: .4byte 0x000003e6
_080A1C70:
	ldr r0, _080A1C80
	ldrb r0, [r0, 0x2]
	movs r1, 0
	bl sub_809124C
	bl FillInventoryGaps
	b _080A236A
	.align 2, 0
_080A1C80: .4byte gUnknown_81167E4
_080A1C84:
	movs r0, 0xD1
	lsls r0, 1
	bl RandInt
	adds r0, 0x1
	lsls r0, 16
	asrs r5, r0, 16
	movs r0, 0x20
	bl RandInt
	adds r4, r0, 0
	movs r7, 0xD2
	lsls r7, 1
	movs r6, 0
	ldr r0, _080A1DE0
	mov r8, r0
_080A1CA4:
	adds r0, r5, 0x1
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, r8
	ble _080A1CB0
	movs r5, 0x1
_080A1CB0:
	subs r7, 0x1
	cmp r7, 0
	bge _080A1CCC
	cmp r6, 0
	bne _080A1CBC
	b _080A2360
_080A1CBC:
	cmp r4, r6
	blt _080A1CCC
	adds r0, r6, 0
	bl RandInt
	adds r4, r0, 0
	movs r7, 0xD2
	lsls r7, 1
_080A1CCC:
	adds r0, r5, 0
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080A1CA4
	ldr r0, _080A1DE4
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0xB
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0xD
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x88
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x67
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x23
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x3
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	cmp r5, r8
	beq _080A1CA4
	cmp r5, 0x96
	beq _080A1CA4
	subs r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	cmp r5, 0x97
	beq _080A1CA4
	subs r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x8C
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x2
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x82
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x83
	cmp r5, r0
	beq _080A1CA4
	adds r0, r5, 0
	bl IsExclusivePokemonUnlocked
	lsls r0, 24
	cmp r0, 0
	beq _080A1CA4
	adds r0, r5, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	beq _080A1D9E
	adds r0, r5, 0
	bl HasRecruitedMon
	lsls r0, 24
	cmp r0, 0
	bne _080A1CA4
	adds r0, r5, 0
	bl sub_808D278
	cmp r0, 0
	beq _080A1CA4
_080A1D9E:
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	blt _080A1DA8
	b _080A1CA4
_080A1DA8:
	movs r0, 0
	movs r1, 0x1F
	adds r2, r5, 0
	bl sub_80018D8
	ldr r4, _080A1DE8
	adds r0, r5, 0
	bl GetFriendArea
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	adds r0, r5, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
	b _080A203C
	.align 2, 0
_080A1DE0: .4byte 0x000001a3
_080A1DE4: .4byte 0x0000019b
_080A1DE8: .4byte gUnknown_202E628
_080A1DEC:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r5, r0, 16
	ldr r4, _080A1E2C
	adds r0, r5, 0
	bl GetFriendArea
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	cmp r5, 0
	bne _080A1E14
	b _080A236A
_080A1E14:
	adds r0, r5, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
	b _080A203C
	.align 2, 0
_080A1E2C: .4byte gUnknown_202E628
_080A1E30:
	ldr r0, _080A1E38
	movs r1, 0x20
	b _080A18F6
	.align 2, 0
_080A1E38: .4byte gUnknown_2039D98
_080A1E3C:
	cmp r5, 0
	bne _080A1E42
	b _080A2360
_080A1E42:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r5, r0, 16
	adds r6, r5, 0
	ldr r4, _080A1EC4
	adds r0, r5, 0
	bl GetFriendArea
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	cmp r5, 0
	bne _080A1E6C
	b _080A236A
_080A1E6C:
	adds r0, r5, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _080A1E8E
	adds r0, r5, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl UnlockFriendArea
_080A1E8E:
	ldr r3, _080A1EC8
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	bne _080A1EA4
	b _080A236A
_080A1EA4:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1ECC
_080A1EAC:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1EAC
	bl sub_8097848
_080A1EBE:
	movs r0, 0x1
	b _080A236C
	.align 2, 0
_080A1EC4: .4byte gUnknown_202E628
_080A1EC8: .4byte gUnknown_81167E8
_080A1ECC: .4byte gUnknown_2039D98
_080A1ED0:
	bl GetPtsToNextRank
	b _080A177C
_080A1ED6:
	bl GetRescueTeamRank
	lsls r0, 24
	lsrs r4, r0, 24
	bl GetPtsToNextRank
	cmp r0, 0
	bgt _080A1EE8
	b _080A236A
_080A1EE8:
	bl AddToTeamRankPts
	bl GetRescueTeamRank
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	bl GetTeamRankString
	adds r1, r0, 0
	ldr r4, _080A1F30
	adds r0, r4, 0
	bl strcpy
	adds r0, r5, 0
	bl GetTeamRankString
	adds r1, r0, 0
	adds r4, 0x50
	adds r0, r4, 0
	bl strcpy
	movs r1, 0x1
	negs r1, r1
	ldr r2, _080A1F34
	movs r0, 0
	bl ScriptPrintText
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
_080A1F28:
	ldr r0, _080A1F38
	bl AddToTeamMoney
	b _080A236A
	.align 2, 0
_080A1F30: .4byte gUnknown_202DE58
_080A1F34: .4byte gUnknown_81167EC
_080A1F38: .4byte 0x00002710
_080A1F3C:
	ldr r0, _080A1F40
	b _080A1A00
	.align 2, 0
_080A1F40: .4byte 0x00000133
_080A1F44:
	ldr r0, _080A1F4C
	movs r1, 0x52
	b _080A18F6
	.align 2, 0
_080A1F4C: .4byte gUnknown_2039D98
_080A1F50:
	add r1, sp, 0x288
	adds r2, r1, 0
	ldr r0, _080A1F7C
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x2B0
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	beq _080A1EBE
	b _080A1968
	.align 2, 0
_080A1F7C: .4byte gUnknown_811681C
_080A1F80:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x12
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	bne _080A1F94
	b _080A236A
_080A1F94:
	movs r0, 0
	movs r1, 0xF
	bl sub_8001658
	cmp r0, 0x4
	bne _080A1FA2
	b _080A236A
_080A1FA2:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	bl sub_8001784
	cmp r0, 0
	ble _080A1FB2
	b _080A236A
_080A1FB2:
	movs r0, 0x80
	lsls r0, 1
	bl OtherRandInt
	cmp r0, 0
	bne _080A1FCC
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	movs r3, 0x4
	bl sub_800199C
	b _080A1EBE
_080A1FCC:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	movs r3, 0x1
	bl sub_800199C
	b _080A236A
_080A1FDA:
	ldr r6, _080A200C
	ldr r7, _080A2010
	movs r5, 0x2
_080A1FE0:
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	ble _080A2018
	ldrb r4, [r6, 0x2]
	adds r0, r4, 0
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	cmp r0, 0
	beq _080A2024
	ldr r0, _080A2014
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r7
	bhi _080A2024
	adds r0, 0x1
	strh r0, [r1]
	b _080A2024
	.align 2, 0
_080A200C: .4byte gUnknown_8116844
_080A2010: .4byte 0x000003e6
_080A2014: .4byte gTeamInventoryRef
_080A2018:
	ldrb r0, [r6, 0x2]
	movs r1, 0
	bl sub_809124C
	bl FillInventoryGaps
_080A2024:
	subs r5, 0x1
	cmp r5, 0
	bge _080A1FE0
	b _080A236A
_080A202C:
	bl GetPlayerPokemonStruct
	cmp r0, 0
	beq _080A2040
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	cmp r0, 0x71
	bne _080A2040
_080A203C:
	movs r0, 0x2
	b _080A236C
_080A2040:
	movs r0, 0x71
	bl sub_8098134
	bl _080A171E
_080A204A:
	movs r0, 0
	movs r1, 0x1
	bl sub_80A56A0
	b _080A236A
_080A2054:
	add r0, sp, 0x328
	str r5, [r0]
	str r7, [r0, 0x4]
	bl sub_80A56F0
	b _080A236A
_080A2060:
	add r0, sp, 0x330
	str r5, [r0]
	str r7, [r0, 0x4]
	bl sub_80A5704
	b _080A236A
_080A206C:
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_809C6CC
	b _080A236A
_080A2076:
	bl sub_809C6EC
	b _080A236A
_080A207C:
	bl sub_809C760
	b _080A236A
_080A2082:
	movs r0, 0
	movs r4, 0x80
	lsls r4, 9
_080A2088:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80A86C8
	adds r0, r4, 0
	movs r5, 0x80
	lsls r5, 9
	adds r4, r5
	asrs r0, 16
	cmp r0, 0x17
	ble _080A2088
	movs r0, 0
	adds r4, r5, 0
_080A20A2:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80AC1B0
	adds r0, r4, 0
	movs r6, 0x80
	lsls r6, 9
	adds r4, r6
	asrs r0, 16
	cmp r0, 0xF
	ble _080A20A2
	movs r0, 0
	adds r4, r6, 0
_080A20BC:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80AD0C8
	adds r0, r4, 0
	movs r1, 0x80
	lsls r1, 9
	adds r4, r1
	asrs r0, 16
	cmp r0, 0xF
	ble _080A20BC
	b _080A236A
_080A20D4:
	add r0, sp, 0x338
	str r5, [r0]
	adds r4, r0, 0
	str r7, [r4, 0x4]
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_80A5984
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	adds r1, r4, 0
	bl sub_80A59A0
	b _080A236A
_080A20F4:
	add r1, sp, 0x308
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	strb r2, [r1, 0x1]
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x3]
	str r2, [r1, 0x4]
	ldr r0, _080A21D8
	ldr r2, _080A21DC
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1, 0x8]
	movs r0, 0x1
	negs r0, r0
	lsls r2, r5, 16
	asrs r2, 16
	lsls r3, r7, 24
	asrs r3, 24
	bl GroundEffect_Add
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A2128
	b _080A236A
_080A2128:
	bl sub_80AD158
	adds r7, r0, 0
	add r4, sp, 0x340
	add r5, sp, 0x348
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80A579C
	ldr r0, [r4, 0x4]
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [r4, 0x4]
	ldr r0, [r5, 0x4]
	adds r0, r1
	str r0, [r5, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	add r6, sp, 0x350
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	add r1, sp, 0x350
	ldr r2, [r1]
	add r0, sp, 0x340
	ldr r0, [r0]
	cmp r2, r0
	blt _080A216E
	add r0, sp, 0x348
	ldr r0, [r0]
	cmp r2, r0
	blt _080A2170
	subs r0, 0x1
_080A216E:
	str r0, [r1]
_080A2170:
	ldr r1, [r6, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	blt _080A2180
	ldr r0, [r5, 0x4]
	cmp r1, r0
	blt _080A2182
	subs r0, 0x1
_080A2180:
	str r0, [r6, 0x4]
_080A2182:
	add r1, sp, 0x340
	ldr r0, [r1]
	ldr r2, _080A21E0
	adds r0, r2
	str r0, [r1]
	ldr r0, [r4, 0x4]
	adds r0, r2
	str r0, [r4, 0x4]
	add r1, sp, 0x348
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2
	str r0, [r1]
	ldr r0, [r5, 0x4]
	adds r0, r2
	str r0, [r5, 0x4]
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r3, [r1, 0x20]
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r6, 0
	bl _call_via_r2
	movs r0, 0
	movs r1, 0
	add r2, sp, 0x358
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0x358
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	b _080A1EBE
	.align 2, 0
_080A21D8: .4byte gFunctionScriptTable
_080A21DC: .4byte 0x00001310
_080A21E0: .4byte 0xfffffc00
_080A21E4:
	ldr r0, _080A2288
	ldrh r4, [r0]
	ldrh r0, [r0, 0x2]
	movs r1, 0xC
	ands r0, r1
	cmp r0, 0
	beq _080A21F4
	b _080A236A
_080A21F4:
	adds r0, r4, 0
	bl sub_809CFE8
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A2282
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x360
	bl sub_8002BB8
	add r0, sp, 0x360
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x368
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x2
	ands r4, r0
	cmp r4, 0
	beq _080A2226
	movs r0, 0x4
_080A2226:
	cmp r0, 0
	beq _080A2282
	movs r3, 0xDA
	lsls r3, 2
	add r3, sp
	mov r9, r3
	add r7, sp, 0x370
	add r4, sp, 0x378
	mov r8, r0
_080A2238:
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	mov r1, r9
	bl _call_via_r2
	cmp r0, 0
	beq _080A2276
	movs r5, 0
	str r5, [r7]
	mov r1, r9
	ldr r0, [r1, 0x4]
	str r0, [r7, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r7, 0
	bl _call_via_r2
	cmp r0, 0
	beq _080A2276
	mov r2, r9
	ldr r0, [r2]
	str r0, [r4]
	str r5, [r4, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
_080A2276:
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r5, r8
	cmp r5, 0
	bne _080A2238
_080A2282:
	movs r0, 0x1
	negs r0, r0
	b _080A236C
	.align 2, 0
_080A2288: .4byte gRealInputs
_080A228C:
	negs r0, r5
	orrs r0, r5
	lsrs r0, 31
	bl sub_80993C0
	b _080A236A
_080A2298:
	movs r0, 0x1
	bl sub_8011C28
_080A229E:
	adds r0, r5, 0
	bl GroundMainGameEndRequest
	lsls r0, r5, 16
	lsrs r0, 16
	bl FadeOutAllMusic
	b _080A236A
_080A22AE:
	bl GetCurrentBGSong
	ldr r1, _080A22C4
	strh r0, [r1]
	lsls r0, 16
	ldr r1, _080A22C8
	cmp r0, r1
	beq _080A22C0
	b _080A1EBE
_080A22C0:
	b _080A236A
	.align 2, 0
_080A22C4: .4byte gUnknown_2039DA8
_080A22C8: .4byte 0x03e70000
_080A22CC:
	ldr r4, _080A22DC
	ldrh r0, [r4]
	ldr r5, _080A22E0
	cmp r0, r5
	beq _080A236A
	bl xxx_call_start_new_bgm
	b _080A2312
	.align 2, 0
_080A22DC: .4byte gUnknown_2039DA8
_080A22E0: .4byte 0x000003e7
_080A22E4:
	ldr r4, _080A22FC
	ldrh r0, [r4]
	ldr r6, _080A2300
	cmp r0, r6
	beq _080A236A
	lsls r1, r5, 16
	lsrs r1, 16
	bl xxx_call_fade_in_new_bgm
	strh r6, [r4]
	b _080A1EBE
	.align 2, 0
_080A22FC: .4byte gUnknown_2039DA8
_080A2300: .4byte 0x000003e7
_080A2304:
	ldr r4, _080A2318
	ldrh r0, [r4]
	ldr r5, _080A231C
	cmp r0, r5
	beq _080A236A
	bl xxx_call_queue_bgm
_080A2312:
	strh r5, [r4]
	b _080A1EBE
	.align 2, 0
_080A2318: .4byte gUnknown_2039DA8
_080A231C: .4byte 0x000003e7
_080A2320:
	lsls r0, r5, 16
	lsrs r0, 16
	lsls r1, r7, 16
	lsrs r1, 16
	bl sub_80997F4
	b _080A236A
_080A232E:
	lsls r1, r5, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl sub_80997F4
	b _080A236A
_080A233A:
	lsls r1, r5, 16
	lsrs r1, 16
	movs r0, 0
	bl GroundSprite_ExtendPaletteAdd
	b _080A236A
_080A2346:
	movs r0, 0
	bl GroundSprite_ExtendPaletteDelete
	b _080A236A
_080A234E:
	movs r0, 0
	movs r1, 0x2F
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_800199C
	adds r0, r5, 0
	subs r0, 0x10
	b _080A236C
_080A2360:
	movs r0, 0
	movs r1, 0x1F
	movs r2, 0
	bl sub_80018D8
_080A236A:
	movs r0, 0
_080A236C:
	movs r3, 0xE0
	lsls r3, 2
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A14E8

	thumb_func_start GroundScript_Unlock
GroundScript_Unlock:
	push {r4-r7,lr}
	ldr r1, _080A241C
	ldrb r0, [r1]
	cmp r0, 0
	beq _080A2414
	movs r0, 0
	strb r0, [r1]
	movs r6, 0
_080A2390:
	ldr r0, _080A2420
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, 0
	beq _080A240E
	movs r0, 0x1
	ldr r1, _080A2424
	adds r2, r6, 0
	bl Log
	lsls r5, r6, 16
	asrs r5, 16
	adds r0, r5, 0
	bl sub_80A4D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80A8B1C
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80AC320
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80AD238
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A2428
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, 0
	beq _080A240C
	cmp r4, 0
	beq _080A240E
	movs r0, 0x80
	adds r4, r6, 0
	orrs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_80A4D2C
	adds r0, r4, 0
	bl sub_80A8B1C
	adds r0, r4, 0
	bl sub_80AC320
	adds r0, r4, 0
	bl sub_80AD238
	movs r0, 0
	strb r0, [r5]
_080A240C:
	strb r0, [r7]
_080A240E:
	adds r6, 0x1
	cmp r6, 0x80
	ble _080A2390
_080A2414:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A241C: .4byte gUnknown_2039A36
_080A2420: .4byte gUnknown_2039A38
_080A2424: .4byte gUnknown_8116848
_080A2428: .4byte gUnknown_2039AC0
	thumb_func_end GroundScript_Unlock

    .align 2,0
