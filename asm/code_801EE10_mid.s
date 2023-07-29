    #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801FC40
sub_801FC40:
	push {lr}
	ldr r1, _0801FC5C
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0x22
	bls _0801FC50
	b _0801FD70
_0801FC50:
	lsls r0, 2
	ldr r1, _0801FC60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FC5C: .4byte gUnknown_203B27C
_0801FC60: .4byte _0801FC64
	.align 2, 0
_0801FC64:
	.4byte _0801FCF0
	.4byte _0801FCF0
	.4byte _0801FCF6
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FCFC
	.4byte _0801FD02
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD50
	.4byte _0801FD70
	.4byte _0801FD08
	.4byte _0801FD08
	.4byte _0801FD0E
	.4byte _0801FD14
	.4byte _0801FD1A
	.4byte _0801FD70
	.4byte _0801FD20
	.4byte _0801FD20
	.4byte _0801FD26
	.4byte _0801FD2C
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD32
	.4byte _0801FD38
	.4byte _0801FD38
	.4byte _0801FD3E
	.4byte _0801FD44
	.4byte _0801FD4A
_0801FCF0:
	bl sub_8021154
	b _0801FD74
_0801FCF6:
	bl sub_80209AC
	b _0801FD74
_0801FCFC:
	bl sub_80209FC
	b _0801FD74
_0801FD02:
	bl sub_8020A34
	b _0801FD74
_0801FD08:
	bl sub_8020A80
	b _0801FD74
_0801FD0E:
	bl sub_8020B38
	b _0801FD74
_0801FD14:
	bl sub_8020C2C
	b _0801FD74
_0801FD1A:
	bl sub_8020C48
	b _0801FD74
_0801FD20:
	bl sub_8020C64
	b _0801FD74
_0801FD26:
	bl sub_8020CC0
	b _0801FD74
_0801FD2C:
	bl sub_8020D74
	b _0801FD74
_0801FD32:
	bl sub_8020D90
	b _0801FD74
_0801FD38:
	bl sub_8020DCC
	b _0801FD74
_0801FD3E:
	bl sub_8020EB4
	b _0801FD74
_0801FD44:
	bl sub_80210C8
	b _0801FD74
_0801FD4A:
	bl sub_80210E4
	b _0801FD74
_0801FD50:
	ldr r0, [r2]
	ldrb r0, [r0, 0x15]
	cmp r0, 0x1
	bne _0801FD68
	ldr r0, _0801FD6C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x96
	str r0, [r1]
_0801FD68:
	movs r0, 0x3
	b _0801FD76
	.align 2, 0
_0801FD6C: .4byte gTeamInventory_203B460
_0801FD70:
	bl sub_8021130
_0801FD74:
	movs r0, 0
_0801FD76:
	pop {r1}
	bx r1
	thumb_func_end sub_801FC40

	thumb_func_start sub_801FD7C
sub_801FD7C:
	push {r4,lr}
	ldr r4, _0801FDA4
	ldr r0, [r4]
	cmp r0, 0
	beq _0801FD9C
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801FD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FDA4: .4byte gUnknown_203B27C
	thumb_func_end sub_801FD7C

	thumb_func_start sub_801FDA8
sub_801FDA8:
	push {lr}
	ldr r1, _0801FDBC
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801FDC0
	bl sub_801FF28
	pop {r0}
	bx r0
	.align 2, 0
_0801FDBC: .4byte gUnknown_203B27C
	thumb_func_end sub_801FDA8

	thumb_func_start sub_801FDC0
sub_801FDC0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0801FDE8
	ldr r0, [r4]
	movs r5, 0xC0
	lsls r5, 1
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	cmp r1, 0x11
	beq _0801FE38
	cmp r1, 0x11
	bgt _0801FDEC
	cmp r1, 0x2
	beq _0801FDF6
	b _0801FED4
	.align 2, 0
_0801FDE8: .4byte gUnknown_203B27C
_0801FDEC:
	cmp r1, 0x17
	beq _0801FE6C
	cmp r1, 0x20
	beq _0801FE88
	b _0801FED4
_0801FDF6:
	adds r0, r5
	movs r1, 0x80
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, 0xCC
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	movs r3, 0xD8
	lsls r3, 1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r4]
	movs r6, 0xE4
	lsls r6, 1
	adds r1, r6
	ldr r0, _0801FE34
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FE34: .4byte gUnknown_80DC37C
_0801FE38:
	bl sub_80205D0
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE68
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	movs r6, 0xC0
	lsls r6, 1
	adds r0, r6
	b _0801FEC2
	.align 2, 0
_0801FE68: .4byte gUnknown_80DC334
_0801FE6C:
	bl sub_802069C
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE84
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	b _0801FEB0
	.align 2, 0
_0801FE84: .4byte gUnknown_80DC334
_0801FE88:
	bl CreateGulpinLinkMenu
	ldr r1, [r4]
	movs r7, 0xCC
	lsls r7, 1
	adds r1, r7
	ldr r0, _0801FECC
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FED0
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
_0801FEB0:
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, r5
_0801FEC2:
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FECC: .4byte gUnknown_80DC31C
_0801FED0: .4byte gUnknown_80DC34C
_0801FED4:
	ldr r5, _0801FF20
	mov r12, r5
	movs r6, 0xC0
	lsls r6, 1
	mov r8, r6
	ldr r4, _0801FF24
	movs r3, 0
	movs r2, 0x3
_0801FEE4:
	mov r7, r12
	ldr r1, [r7]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801FEE4
	bl ResetUnusedInputStruct
	ldr r0, _0801FF20
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801FF14:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FF20: .4byte gUnknown_203B27C
_0801FF24: .4byte gUnknown_80DC31C
	thumb_func_end sub_801FDC0

	thumb_func_start sub_801FF28
sub_801FF28:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801FF44
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r5, r1, 0
	cmp r0, 0x23
	bls _0801FF3A
	b _08020562
_0801FF3A:
	lsls r0, 2
	ldr r1, _0801FF48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FF44: .4byte gUnknown_203B27C
_0801FF48: .4byte _0801FF4C
	.align 2, 0
_0801FF4C:
	.4byte _0801FFDC
	.4byte _08020018
	.4byte _08020064
	.4byte _0802006C
	.4byte _08020090
	.4byte _080200B4
	.4byte _080200D8
	.4byte _080200FC
	.4byte _08020144
	.4byte _0802018C
	.4byte _080201B0
	.4byte _080201D4
	.4byte _080201F8
	.4byte _08020562
	.4byte _0802021C
	.4byte _08020240
	.4byte _0802024E
	.4byte _08020256
	.4byte _08020274
	.4byte _08020282
	.4byte _0802028E
	.4byte _080202B0
	.4byte _080202BE
	.4byte _080202C6
	.4byte _080202E4
	.4byte _08020304
	.4byte _08020344
	.4byte _080203B0
	.4byte _080203D4
	.4byte _0802038C
	.4byte _080203F8
	.4byte _08020428
	.4byte _08020434
	.4byte _08020460
	.4byte _08020478
	.4byte _08020500
_0801FFDC:
	ldr r0, [r5]
	movs r4, 0x2
	str r4, [r0, 0x6C]
	bl CreateGulpinShopMenu
	ldr r5, [r5]
	str r4, [r5, 0x8]
	ldr r2, _08020014
	ldr r1, [r5]
	movs r0, 0x64
	muls r0, r1
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r5, 0x6C]
	adds r3, r5, 0
	adds r3, 0x7C
	adds r1, r5, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r5, r4
	b _0802004C
	.align 2, 0
_08020014: .4byte gGulpinDialogue
_08020018:
	bl CreateGulpinShopMenu
	ldr r0, _0802005C
	ldr r4, [r0]
	movs r0, 0x2
	str r0, [r4, 0x8]
	ldr r1, _08020060
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r4, 0x6C]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_0802004C:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802005C: .4byte gUnknown_203B27C
_08020060: .4byte gGulpinDialogue
_08020064:
	movs r0, 0x3
	bl DrawTeamMoneyBox
	b _08020562
_0802006C:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _0802008C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802008C: .4byte gGulpinDialogue
_08020090:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200B0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0xC
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200B0: .4byte gGulpinDialogue
_080200B4:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200D4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x10
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200D4: .4byte gGulpinDialogue
_080200D8:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200F8
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x14
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200F8: .4byte gGulpinDialogue
_080200FC:
	bl sub_8020900
	ldr r1, _0802013C
	ldr r0, _08020140
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x18
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x10
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802013C: .4byte gGulpinDialogue
_08020140: .4byte gUnknown_203B27C
_08020144:
	bl sub_8020950
	ldr r1, _08020184
	ldr r0, _08020188
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x54
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xD
	bl sub_8014248
	b _08020562
	.align 2, 0
_08020184: .4byte gGulpinDialogue
_08020188: .4byte gUnknown_203B27C
_0802018C:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x58
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201AC: .4byte gGulpinDialogue
_080201B0:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x5C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201D0: .4byte gGulpinDialogue
_080201D4:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x60
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201F4: .4byte gGulpinDialogue
_080201F8:
	ldr r2, [r5]
	movs r0, 0xD
	str r0, [r2, 0x8]
	ldr r1, _08020218
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_08020218: .4byte gGulpinDialogue
_0802021C:
	ldr r2, [r5]
	movs r0, 0xF
	str r0, [r2, 0x8]
	ldr r1, _0802023C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x20
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802023C: .4byte gGulpinDialogue
_08020240:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _08020562
_0802024E:
	movs r0, 0x1
	bl sub_8023B7C
	b _08020562
_08020256:
	bl sub_8023DA4
	ldr r0, _08020270
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x70]
	b _0802044C
	.align 2, 0
_08020270: .4byte gUnknown_203B27C
_08020274:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0x2
	bl sub_8024458
	b _08020562
_08020282:
	ldr r0, [r5]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl sub_801BEEC
	b _08020562
_0802028E:
	ldr r2, [r5]
	movs r0, 0x15
	str r0, [r2, 0x8]
	ldr r1, _080202AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x24
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080202AC: .4byte gGulpinDialogue
_080202B0:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0
	bl sub_801F428
	b _08020562
_080202BE:
	movs r0, 0x1
	bl sub_801F5F0
	b _08020562
_080202C6:
	bl sub_801F700
	ldr r0, _080202E0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x74]
	b _0802044C
	.align 2, 0
_080202E0: .4byte gUnknown_203B27C
_080202E4:
	ldr r0, [r5]
	ldrh r1, [r0, 0x1C]
	adds r0, 0x64
	strh r1, [r0]
	movs r2, 0x1
	adds r4, r5, 0
	movs r3, 0
_080202F2:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r0, 0x64
	adds r0, r1
	strh r3, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080202F2
	b _0802046E
_08020304:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r1, [r5]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0802033C
	ldrh r1, [r1, 0x1E]
	bl sub_8092C84
	ldr r1, _08020340
	ldr r2, [r5]
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x28
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802033C: .4byte gAvailablePokemonNames
_08020340: .4byte gGulpinDialogue
_08020344:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r3, [r5]
	movs r0, 0x10
	str r0, [r3, 0x8]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020370
	ldr r1, _0802036C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x38
	b _08020520
	.align 2, 0
_0802036C: .4byte gGulpinDialogue
_08020370:
	ldr r1, _08020388
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x34
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	b _0802052A
	.align 2, 0
_08020388: .4byte gGulpinDialogue
_0802038C:
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _080203A2
	movs r5, 0xC
	ldrsh r1, [r2, r5]
	adds r2, 0x24
	movs r0, 0
	bl CreateGulpinShop
	b _08020562
_080203A2:
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	adds r2, 0x24
	movs r0, 0x1
	bl CreateGulpinShop
	b _08020562
_080203B0:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x3C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203D0: .4byte gGulpinDialogue
_080203D4:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x40
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203F4: .4byte gGulpinDialogue
_080203F8:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl unk_CopyMoves4To8
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r1, [r0, r5]
	adds r2, r0, 0
	adds r2, 0x24
	ldrb r3, [r0, 0x15]
	ldr r0, _08020424
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x1
	bl sub_801EE10
	b _08020562
	.align 2, 0
_08020424: .4byte gUnknown_80DC394
_08020428:
	ldr r0, [r5]
	ldrb r1, [r0, 0x15]
	movs r0, 0x1
	bl sub_801F1B0
	b _08020562
_08020434:
	movs r0, 0
	bl sub_801F280
	ldr r0, _0802045C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x78]
_0802044C:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08020562
	.align 2, 0
_0802045C: .4byte gUnknown_203B27C
_08020460:
	ldr r2, [r5]
	ldr r0, [r2, 0x18]
	adds r1, r2, 0
	adds r1, 0x24
	adds r2, 0x64
	bl GetLinkedSequence
_0802046E:
	ldr r0, [r5]
	adds r0, 0x64
	bl sub_801F808
	b _08020562
_08020478:
	bl sub_80208B0
	ldr r0, _080204B8
	ldr r4, _080204BC
	ldr r1, [r4]
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r4, [r4]
	ldrb r5, [r4, 0x14]
	cmp r5, 0
	beq _080204C4
	ldr r1, _080204C0
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	b _080204E8
	.align 2, 0
_080204B8: .4byte gUnknown_202DFE8
_080204BC: .4byte gUnknown_203B27C
_080204C0: .4byte gGulpinDialogue
_080204C4:
	ldr r1, _080204FC
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x44
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_080204E8:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x11
	bl sub_8014248
	b _08020562
	.align 2, 0
_080204FC: .4byte gGulpinDialogue
_08020500:
	ldr r1, [r5]
	movs r0, 0x1F
	str r0, [r1, 0x8]
	ldr r0, _08020538
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r3, [r5]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020544
	ldr r1, _0802053C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x50
_08020520:
	adds r0, r1
	ldr r0, [r0]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r3, r2
_0802052A:
	ldr r2, [r1]
_0802052C:
	ldr r3, _08020540
	movs r1, 0
	bl sub_80141B4
	b _08020562
	.align 2, 0
_08020538: .4byte gUnknown_202DFE8
_0802053C: .4byte gGulpinDialogue
_08020540: .4byte 0x0000010d
_08020544:
	ldr r1, _0802056C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	ldr r2, [r1]
	ldr r3, _08020570
	movs r1, 0
	bl sub_80141B4
_08020562:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802056C: .4byte gGulpinDialogue
_08020570: .4byte 0x0000010d
	thumb_func_end sub_801FF28

	thumb_func_start CreateGulpinShopMenu
CreateGulpinShopMenu:
	push {r4,lr}
	ldr r4, _080205C0
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080205C4
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080205C8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080205CC
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x90
	str r2, [r0]
	adds r0, 0x4
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080205C0: .4byte gUnknown_203B27C
_080205C4: .4byte gGulpinProceed
_080205C8: .4byte gGulpinInfo
_080205CC: .4byte gUnknown_80D4934
	thumb_func_end CreateGulpinShopMenu

	thumb_func_start sub_80205D0
sub_80205D0:
	push {r4-r7,lr}
	ldr r4, _08020660
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _08020664
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r2, r12
	adds r2, 0x80
	movs r0, 0x4
	str r0, [r2]
	movs r3, 0x1
	adds r1, 0x84
	ldr r0, _08020668
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802066C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xC
	str r0, [r1]
	movs r6, 0x3
	adds r1, 0x4
	ldr r0, _08020670
	str r0, [r1]
	mov r0, r12
	adds r0, 0x98
	str r6, [r0]
	movs r6, 0x4
	adds r0, 0x4
	str r5, [r0]
	adds r0, 0x4
	str r3, [r0]
	mov r3, r12
	adds r3, 0xBC
_0802062A:
	ldrh r0, [r3]
	cmp r0, 0
	bne _0802063A
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x70]
	cmp r1, r0
	beq _08020696
_0802063A:
	adds r2, 0x8
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0802062A
	movs r5, 0
	cmp r5, r6
	bge _08020696
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020674
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08020696
	.align 2, 0
_08020660: .4byte gUnknown_203B27C
_08020664: .4byte gUnknown_80DC3D8
_08020668: .4byte gUnknown_80DC3E0
_0802066C: .4byte gUnknown_80DC3E8
_08020670: .4byte gUnknown_80DC3F4
_08020674:
	adds r5, 0x1
	cmp r5, r6
	bge _08020696
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020674
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08020696:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80205D0

	thumb_func_start sub_802069C
sub_802069C:
	push {r4-r7,lr}
	ldr r4, _08020718
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _0802071C
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r3, r12
	adds r3, 0x80
	movs r0, 0x3
	str r0, [r3]
	movs r2, 0x1
	adds r1, 0x84
	ldr r0, _08020720
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	movs r6, 0x2
	mov r0, r12
	adds r0, 0x8C
	str r5, [r0]
	adds r0, 0x4
	str r2, [r0]
	mov r2, r12
	adds r2, 0xBC
_080206E0:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080206F0
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _08020746
_080206F0:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080206E0
	movs r5, 0
	cmp r5, r6
	bge _08020746
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020724
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _08020746
	.align 2, 0
_08020718: .4byte gUnknown_203B27C
_0802071C: .4byte gUnknown_80DC3F4
_08020720: .4byte gUnknown_80D4970
_08020724:
	adds r5, 0x1
	cmp r5, r6
	bge _08020746
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020724
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_08020746:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802069C

	thumb_func_start CreateGulpinLinkMenu
CreateGulpinLinkMenu:
	push {r4-r7,lr}
	movs r7, 0
	ldr r4, _08020780
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldrb r0, [r1, 0x16]
	cmp r0, 0
	beq _0802079C
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl IsMoveSet
	lsls r0, 24
	cmp r0, 0
	beq _08020788
	ldr r0, [r4]
	ldr r1, _08020784
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x6
	b _08020792
	.align 2, 0
_08020780: .4byte gUnknown_203B27C
_08020784: .4byte gGulpinDeselect
_08020788:
	ldr r0, [r4]
	ldr r1, _08020798
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x5
_08020792:
	str r1, [r0]
	mov r12, r4
	b _080207CA
	.align 2, 0
_08020798: .4byte gGulpinSet
_0802079C:
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl IsMoveEnabled
	lsls r0, 24
	cmp r0, 0
	beq _080207B4
	ldr r1, [r4]
	ldr r0, _080207B0
	b _080207B8
	.align 2, 0
_080207B0: .4byte gGulpinDeselect
_080207B4:
	ldr r1, [r4]
	ldr r0, _0802086C
_080207B8:
	str r0, [r1, 0x7C]
	ldr r2, _08020870
	ldr r0, [r2]
	lsls r1, r7, 3
	adds r0, 0x80
	adds r0, r1
	movs r1, 0x7
	str r1, [r0]
	mov r12, r2
_080207CA:
	adds r7, 0x1
	mov r0, r12
	ldr r4, [r0]
	lsls r1, r7, 3
	adds r3, r4, 0
	adds r3, 0x7C
	adds r2, r3, r1
	ldr r0, _08020874
	str r0, [r2]
	adds r6, r4, 0
	adds r6, 0x80
	adds r1, r6, r1
	movs r0, 0x8
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020878
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0x9
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802087C
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xA
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020880
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xB
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r6, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	cmp r3, r7
	bge _0802084C
	adds r5, r4, 0
	adds r4, 0xBC
	adds r2, r6, 0
_08020834:
	ldrh r0, [r4]
	cmp r0, 0
	bne _08020842
	ldr r1, [r2]
	ldr r0, [r5, 0x78]
	cmp r1, r0
	beq _080208A8
_08020842:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _08020834
_0802084C:
	movs r3, 0
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020884
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x78]
	b _080208A8
	.align 2, 0
_0802086C: .4byte gGulpinSet
_08020870: .4byte gUnknown_203B27C
_08020874: .4byte gGulpinLink
_08020878: .4byte gGulpinDelink
_0802087C: .4byte gGulpinForget
_08020880: .4byte gUnknown_80D4970
_08020884:
	adds r3, 0x1
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020884
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x78]
_080208A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateGulpinLinkMenu

	thumb_func_start sub_80208B0
sub_80208B0:
	push {r4,lr}
	ldr r4, _080208F4
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080208F8
	ldr r0, [r0]
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080208FC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x8C
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080208F4: .4byte gUnknown_203B27C
_080208F8: .4byte gUnknown_80D4920
_080208FC: .4byte gUnknown_80D4928
	thumb_func_end sub_80208B0

	thumb_func_start sub_8020900
sub_8020900:
	push {r4,lr}
	ldr r4, _08020944
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08020948
	ldr r0, [r0]
	str r0, [r3, 0x7C]
	adds r1, r3, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802094C
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x8C
	str r2, [r0]
	adds r1, 0x8
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020944: .4byte gUnknown_203B27C
_08020948: .4byte gUnknown_80D4920
_0802094C: .4byte gUnknown_80D4928
	thumb_func_end sub_8020900

	thumb_func_start sub_8020950
sub_8020950:
	push {r4,lr}
	ldr r4, _0802099C
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080209A0
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0xD
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080209A4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xE
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080209A8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xF
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x94
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802099C: .4byte gUnknown_203B27C
_080209A0: .4byte gUnknown_80DC428
_080209A4: .4byte gUnknown_80DC438
_080209A8: .4byte gUnknown_80DC448
	thumb_func_end sub_8020950

	thumb_func_start sub_80209AC
sub_80209AC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080209F4
	ldr r0, _080209D4
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x6C]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080209DE
	cmp r0, 0x2
	bgt _080209D8
	cmp r0, 0x1
	beq _080209EE
	b _080209F4
	.align 2, 0
_080209D4: .4byte gUnknown_203B27C
_080209D8:
	cmp r0, 0xB
	beq _080209E6
	b _080209F4
_080209DE:
	movs r0, 0xE
	bl sub_801FDA8
	b _080209F4
_080209E6:
	movs r0, 0x8
	bl sub_801FDA8
	b _080209F4
_080209EE:
	movs r0, 0xC
	bl sub_801FDA8
_080209F4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209AC

	thumb_func_start sub_80209FC
sub_80209FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A2E
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08020A20
	cmp r0, 0x10
	bgt _08020A1A
	cmp r0, 0x1
	beq _08020A28
	b _08020A2E
_08020A1A:
	cmp r0, 0x11
	beq _08020A28
	b _08020A2E
_08020A20:
	movs r0, 0xE
	bl sub_801FDA8
	b _08020A2E
_08020A28:
	movs r0, 0xC
	bl sub_801FDA8
_08020A2E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209FC

	thumb_func_start sub_8020A34
sub_8020A34:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A7A
	ldr r0, [sp]
	cmp r0, 0xD
	beq _08020A5C
	cmp r0, 0xD
	bgt _08020A52
	cmp r0, 0x1
	beq _08020A74
	b _08020A7A
_08020A52:
	cmp r0, 0xE
	beq _08020A64
	cmp r0, 0xF
	beq _08020A6C
	b _08020A7A
_08020A5C:
	movs r0, 0x9
	bl sub_801FDA8
	b _08020A7A
_08020A64:
	movs r0, 0xA
	bl sub_801FDA8
	b _08020A7A
_08020A6C:
	movs r0, 0xB
	bl sub_801FDA8
	b _08020A7A
_08020A74:
	movs r0, 0x1
	bl sub_801FDA8
_08020A7A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8020A34

	thumb_func_start sub_8020A80
sub_8020A80:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x4
	bhi _08020B32
	lsls r0, 2
	ldr r1, _08020A98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020A98: .4byte _08020A9C
	.align 2, 0
_08020A9C:
	.4byte _08020B32
	.4byte _08020B32
	.4byte _08020B28
	.4byte _08020AB0
	.4byte _08020AEC
_08020AB0:
	bl sub_8023B44
	ldr r4, _08020AE0
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020AE4
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020AE8
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl PrintPokeNameToBuffer
	movs r0, 0x11
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020AE0: .4byte gUnknown_203B27C
_08020AE4: .4byte gRecruitedPokemonRef
_08020AE8: .4byte gUnknown_202E128
_08020AEC:
	bl sub_8023B44
	ldr r4, _08020B1C
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020B20
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020B24
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl PrintPokeNameToBuffer
	movs r0, 0x12
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020B1C: .4byte gUnknown_203B27C
_08020B20: .4byte gRecruitedPokemonRef
_08020B24: .4byte gUnknown_202E128
_08020B28:
	bl sub_8023C60
	movs r0, 0x7
	bl sub_801FDA8
_08020B32:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020A80

	thumb_func_start sub_8020B38
sub_8020B38:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _08020B7C
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020B68
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020B68
	ldr r0, [r4]
	str r1, [r0, 0x70]
_08020B68:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bhi _08020C24
	lsls r0, 2
	ldr r1, _08020B80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020B7C: .4byte gUnknown_203B27C
_08020B80: .4byte _08020B84
	.align 2, 0
_08020B84:
	.4byte _08020BC8
	.4byte _08020C24
	.4byte _08020BD0
	.4byte _08020C0E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C16
	.4byte _08020C1E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020BC8
_08020BC8:
	movs r0, 0x10
	bl sub_801FDA8
	b _08020C24
_08020BD0:
	ldr r0, _08020BF0
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetBaseSpeciesNoUnown
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	bne _08020BF4
	movs r0, 0x1C
	bl sub_801FDA8
	b _08020C24
	.align 2, 0
_08020BF0: .4byte gUnknown_203B27C
_08020BF4:
	bl sub_8021178
	lsls r0, 24
	cmp r0, 0
	beq _08020C06
	movs r0, 0x1B
	bl sub_801FDA8
	b _08020C24
_08020C06:
	movs r0, 0x14
	bl sub_801FDA8
	b _08020C24
_08020C0E:
	movs r0, 0x1E
	bl sub_801FDA8
	b _08020C24
_08020C16:
	movs r0, 0x12
	bl sub_801FDA8
	b _08020C24
_08020C1E:
	movs r0, 0x13
	bl sub_801FDA8
_08020C24:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020B38

	thumb_func_start sub_8020C2C
sub_8020C2C:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08020C44
	cmp r0, 0x3
	bhi _08020C44
	bl sub_802453C
	movs r0, 0x10
	bl sub_801FDA8
_08020C44:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C2C

	thumb_func_start sub_8020C48
sub_8020C48:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08020C60
	cmp r0, 0x3
	bhi _08020C60
	bl sub_801BF98
	movs r0, 0x10
	bl sub_801FDA8
_08020C60:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C48

	thumb_func_start sub_8020C64
sub_8020C64:
	push {lr}
	movs r0, 0x1
	bl sub_801F520
	cmp r0, 0x3
	beq _08020C80
	cmp r0, 0x3
	bhi _08020C7A
	cmp r0, 0x2
	beq _08020CB0
	b _08020CBA
_08020C7A:
	cmp r0, 0x4
	beq _08020C98
	b _08020CBA
_08020C80:
	bl sub_801F5B4
	ldr r1, _08020C94
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x17
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020C94: .4byte gUnknown_203B27C
_08020C98:
	bl sub_801F5B4
	ldr r1, _08020CAC
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x18
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020CAC: .4byte gUnknown_203B27C
_08020CB0:
	bl sub_801F63C
	movs r0, 0x10
	bl sub_801FDA8
_08020CBA:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C64

	thumb_func_start sub_8020CC0
sub_8020CC0:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801F520
	ldr r4, _08020D00
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020CF0
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020CF0
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08020CF0:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08020D14
	cmp r0, 0x3
	bgt _08020D04
	cmp r0, 0x1
	beq _08020D0C
	b _08020D6C
	.align 2, 0
_08020D00: .4byte gUnknown_203B27C
_08020D04:
	cmp r0, 0xB
	beq _08020D66
	cmp r0, 0x11
	bne _08020D6C
_08020D0C:
	movs r0, 0x16
	bl sub_801FDA8
	b _08020D6C
_08020D14:
	bl sub_801F63C
	ldr r4, _08020D30
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl unk_CopyMoves4To8
	movs r5, 0
	adds r6, r4, 0
	movs r4, 0x24
	b _08020D38
	.align 2, 0
_08020D30: .4byte gUnknown_203B27C
_08020D34:
	adds r4, 0x8
	adds r5, 0x1
_08020D38:
	cmp r5, 0x7
	bgt _08020D52
	ldr r3, [r6]
	adds r2, r3, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08020D34
	ldrh r1, [r3, 0x1E]
	adds r0, r2, 0
	bl InitZeroedPPPokemonMove
_08020D52:
	cmp r5, 0x3
	ble _08020D5E
	movs r0, 0x1D
	bl sub_801FDA8
	b _08020D6C
_08020D5E:
	movs r0, 0x19
	bl sub_801FDA8
	b _08020D6C
_08020D66:
	movs r0, 0x18
	bl sub_801FDA8
_08020D6C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8020CC0

	thumb_func_start sub_8020D74
sub_8020D74:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08020D8C
	cmp r0, 0x3
	bhi _08020D8C
	bl sub_801F8D0
	movs r0, 0x16
	bl sub_801FDA8
_08020D8C:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D74

	thumb_func_start sub_8020D90
sub_8020D90:
	push {lr}
	bl sub_801E8C0
	cmp r0, 0x2
	beq _08020DBC
	cmp r0, 0x2
	bcc _08020DC6
	cmp r0, 0x3
	bne _08020DC6
	bl GulpinIsNextMoveLinked
	ldr r1, _08020DB8
	ldr r1, [r1]
	strb r0, [r1, 0x14]
	bl DestroyGulpinShop
	movs r0, 0x1A
	bl sub_801FDA8
	b _08020DC6
	.align 2, 0
_08020DB8: .4byte gUnknown_203B27C
_08020DBC:
	bl DestroyGulpinShop
	movs r0, 0x10
	bl sub_801FDA8
_08020DC6:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D90

	thumb_func_start sub_8020DCC
sub_8020DCC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08020EAA
	lsls r0, 2
	ldr r1, _08020DE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020DE4: .4byte _08020DE8
	.align 2, 0
_08020DE8:
	.4byte _08020EAA
	.4byte _08020E98
	.4byte _08020E64
	.4byte _08020DFC
	.4byte _08020E30
_08020DFC:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E0E
	ldr r0, _08020E2C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E0E:
	bl sub_801F194
	ldr r1, _08020E2C
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x20
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E2C: .4byte gUnknown_203B27C
_08020E30:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E42
	ldr r0, _08020E60
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E42:
	bl sub_801F194
	ldr r1, _08020E60
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x21
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E60: .4byte gUnknown_203B27C
_08020E64:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E76
	ldr r0, _08020E94
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E76:
	bl sub_801F214
	ldr r0, _08020E94
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	movs r0, 0x10
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E94: .4byte gUnknown_203B27C
_08020E98:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020EAA
	ldr r0, _08020EB0
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020EAA:
	pop {r0}
	bx r0
	.align 2, 0
_08020EB0: .4byte gUnknown_203B27C
	thumb_func_end sub_8020DCC

	thumb_func_start sub_8020EB4
sub_8020EB4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801EF38
	ldr r4, _08020EF8
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020EE4
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020EE4
	ldr r0, [r4]
	str r1, [r0, 0x78]
_08020EE4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bls _08020EEE
	b _080210BE
_08020EEE:
	lsls r0, 2
	ldr r1, _08020EFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020EF8: .4byte gUnknown_203B27C
_08020EFC: .4byte _08020F00
	.align 2, 0
_08020F00:
	.4byte _08021068
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08020F44
	.4byte _08020F70
	.4byte _08020F8C
	.4byte _08020FB8
	.4byte _08021034
	.4byte _08021074
	.4byte _080210B8
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08021068
_08020F44:
	ldr r0, _08020F60
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl ToggleSetMove
	lsls r0, 24
	cmp r0, 0
	beq _08020F68
	ldr r0, _08020F64
	bl PlaySound
	b _08021068
	.align 2, 0
_08020F60: .4byte gUnknown_203B27C
_08020F64: .4byte 0x00000133
_08020F68:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _08021068
_08020F70:
	ldr r0, _08020F84
	bl PlaySound
	ldr r0, _08020F88
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl UnSetMove
	b _08021068
	.align 2, 0
_08020F84: .4byte 0x00000133
_08020F88: .4byte gUnknown_203B27C
_08020F8C:
	ldr r0, _08020FA8
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl ToggleMoveEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08020FB0
	ldr r0, _08020FAC
	bl PlaySound
	b _08021068
	.align 2, 0
_08020FA8: .4byte gUnknown_203B27C
_08020FAC: .4byte 0x00000133
_08020FB0:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _08021068
_08020FB8:
	ldr r0, _08020FD8
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x95
	bgt _08020FDC
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x3
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FD8: .4byte gTeamInventory_203B460
_08020FDC:
	ldr r4, _08020FFC
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093318
	lsls r0, 24
	cmp r0, 0
	bne _08021000
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x4
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FFC: .4byte gUnknown_203B27C
_08021000:
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	cmp r0, 0
	bne _08021016
	movs r0, 0x1
	strb r0, [r1, 0x15]
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySound
	b _0802101C
_08021016:
	ldr r0, _0802102C
	bl PlaySound
_0802101C:
	ldr r0, _08021030
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl TryLinkMovesAfter
	b _08021068
	.align 2, 0
_0802102C: .4byte 0x00000133
_08021030: .4byte gUnknown_203B27C
_08021034:
	ldr r4, _08021054
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_809333C
	lsls r0, 24
	cmp r0, 0
	bne _08021058
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x5
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021054: .4byte gUnknown_203B27C
_08021058:
	ldr r0, _08021070
	bl PlaySound
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl UnlinkMovesAfter
_08021068:
	movs r0, 0x1F
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021070: .4byte 0x00000133
_08021074:
	ldr r4, _08021094
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl IsAnyMoveLinked
	lsls r0, 24
	cmp r0, 0
	bne _08021098
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x6
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021094: .4byte gUnknown_203B27C
_08021098:
	ldr r0, _080210B4
	bl PlaySound
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl IsNextMoveLinked
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	movs r0, 0x22
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_080210B4: .4byte 0x00000133
_080210B8:
	movs r0, 0x21
	bl sub_801FDA8
_080210BE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020EB4

	thumb_func_start sub_80210C8
sub_80210C8:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _080210E0
	cmp r0, 0x3
	bhi _080210E0
	bl sub_801F8D0
	movs r0, 0x1F
	bl sub_801FDA8
_080210E0:
	pop {r0}
	bx r0
	thumb_func_end sub_80210C8

	thumb_func_start sub_80210E4
sub_80210E4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802112A
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08021108
	cmp r0, 0x10
	bgt _08021102
	cmp r0, 0x1
	beq _08021124
	b _0802112A
_08021102:
	cmp r0, 0x11
	beq _08021124
	b _0802112A
_08021108:
	ldr r0, _08021120
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x18]
	bl RemoveLinkSequenceFromMoves8
	movs r0, 0x23
	bl sub_801FDA8
	b _0802112A
	.align 2, 0
_08021120: .4byte gUnknown_203B27C
_08021124:
	movs r0, 0x1F
	bl sub_801FDA8
_0802112A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80210E4

	thumb_func_start sub_8021130
sub_8021130:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08021148
	ldr r0, _08021150
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_08021148:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021150: .4byte gUnknown_203B27C
	thumb_func_end sub_8021130

	thumb_func_start sub_8021154
sub_8021154:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0x4
	bne _0802116C
	ldr r0, _08021174
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_0802116C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021174: .4byte gUnknown_203B27C
	thumb_func_end sub_8021154

	thumb_func_start sub_8021178
sub_8021178:
	push {lr}
	mov r12, r4
	ldr r4, _08021198
	add sp, r4
	mov r4, r12
	ldr r0, _0802119C
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	mov r0, sp
	bl sub_808E218
	cmp r0, 0
	beq _080211A0
	movs r0, 0
	b _080211A2
	.align 2, 0
_08021198: .4byte 0xfffffcc0
_0802119C: .4byte gUnknown_203B27C
_080211A0:
	movs r0, 0x1
_080211A2:
	movs r3, 0xD0
	lsls r3, 2
	add sp, r3
	pop {r1}
	bx r1
	thumb_func_end sub_8021178

	thumb_func_start sub_80211AC
sub_80211AC:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _080211C0
	movs r0, 0
	b _08021258
_080211C0:
	ldr r5, _08021260
	movs r0, 0xE0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r4, [r0, 0x3C]
	str r6, [r0, 0x74]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x7C
	adds r1, r0, r1
	str r1, [r0, 0x78]
	adds r0, 0x7C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x74]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x7C
	ldr r0, _08021264
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x78]
	adds r0, 0xDC
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x40
	bl sub_8021664
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, _08021268
	ldr r2, [r5]
	ldr r1, [r0]
	ldr r0, [r2, 0x3C]
	cmp r1, r0
	bne _0802124E
	ldr r0, _0802126C
	ldrh r1, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	strh r1, [r0]
	ldr r0, _08021270
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x5E
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x40
	bl sub_8013984
_0802124E:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021258:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08021260: .4byte gUnknown_203B280
_08021264: .4byte gUnknown_80DC47C
_08021268: .4byte gUnknown_203B284
_0802126C: .4byte gUnknown_203B288
_08021270: .4byte gUnknown_203B28A
	thumb_func_end sub_80211AC

	thumb_func_start sub_8021274
sub_8021274:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08021290
	ldr r0, _0802128C
	ldr r0, [r0]
	adds r0, 0x40
	bl sub_8013660
	movs r0, 0
	b _08021326
	.align 2, 0
_0802128C: .4byte gUnknown_203B280
_08021290:
	ldr r4, _080212A8
	ldr r0, [r4]
	adds r0, 0x40
	bl GetKeyPress
	cmp r0, 0x2
	beq _080212B2
	cmp r0, 0x2
	bgt _080212AC
	cmp r0, 0x1
	beq _080212BC
	b _08021300
	.align 2, 0
_080212A8: .4byte gUnknown_203B280
_080212AC:
	cmp r0, 0x4
	beq _080212F6
	b _08021300
_080212B2:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08021326
_080212BC:
	ldr r0, [r4]
	ldr r0, [r0, 0x3C]
	cmp r0, 0x2
	bne _080212EC
	bl sub_802132C
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaPrice
	ldr r1, _080212E8
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _080212EC
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _080212F2
	.align 2, 0
_080212E8: .4byte gTeamInventory_203B460
_080212EC:
	movs r0, 0
	bl PlayMenuSoundEffect
_080212F2:
	movs r0, 0x3
	b _08021326
_080212F6:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _08021326
_08021300:
	ldr r0, _08021318
	ldr r0, [r0]
	adds r0, 0x40
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802131C
	movs r0, 0
	b _08021326
	.align 2, 0
_08021318: .4byte gUnknown_203B280
_0802131C:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021326:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8021274

	thumb_func_start sub_802132C
sub_802132C:
	ldr r0, _08021350
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	adds r0, r2, r0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08021350: .4byte gUnknown_203B280
	thumb_func_end sub_802132C

	thumb_func_start sub_8021354
sub_8021354:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802139C
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8021664
	adds r1, r0, 0
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x62
	strh r1, [r2]
	adds r0, 0x40
	bl sub_8013984
	bl sub_8021410
	bl sub_8021494
	cmp r4, 0
	beq _08021396
	ldr r0, [r5]
	adds r0, 0x40
	bl AddMenuCursorSprite
_08021396:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802139C: .4byte gUnknown_203B280
	thumb_func_end sub_8021354

	thumb_func_start sub_80213A0
sub_80213A0:
	push {r4,r5,lr}
	ldr r4, _080213FC
	ldr r2, [r4]
	cmp r2, 0
	beq _080213F4
	ldr r1, _08021400
	ldr r0, [r2, 0x3C]
	str r0, [r1]
	ldr r1, _08021404
	adds r0, r2, 0
	adds r0, 0x58
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08021408
	adds r0, r2, 0
	adds r0, 0x5E
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r2, 0x74]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7C
	ldr r0, _0802140C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080213F4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080213FC: .4byte gUnknown_203B280
_08021400: .4byte gUnknown_203B284
_08021404: .4byte gUnknown_203B288
_08021408: .4byte gUnknown_203B28A
_0802140C: .4byte gUnknown_80DC464
	thumb_func_end sub_80213A0

	thumb_func_start sub_8021410
sub_8021410:
	push {r4,lr}
	ldr r4, _08021490
	ldr r0, [r4]
	adds r0, 0xDC
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDD
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xDE
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDF
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x74]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x8A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x74]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x8C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021490: .4byte gUnknown_203B280
	thumb_func_end sub_8021410

	thumb_func_start sub_8021494
sub_8021494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA8
	ldr r4, _08021568
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r2, _0802156C
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0xDE
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0x5E
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	ldr r1, [r3, 0x74]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r0, 0
	mov r9, r0
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	blt _080214FC
	b _08021646
_080214FC:
	mov r8, r4
	add r2, sp, 0x58
	mov r10, r2
_08021502:
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r5, 0
	ldrsh r1, [r0, r5]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	add r0, r9
	adds r0, r2, r0
	ldrb r5, [r0]
	adds r7, r5, 0
	ldr r6, [r2, 0x3C]
	cmp r6, 0x2
	bne _0802159C
	add r0, sp, 0x8
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8092578
	adds r0, r5, 0
	bl GetFriendAreaPrice
	ldr r1, _08021570
	ldr r1, [r1]
	movs r5, 0x98
	lsls r5, 2
	adds r1, r5
	ldr r1, [r1]
	cmp r0, r1
	bgt _08021574
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r2, r8
	ldr r0, [r2]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021568: .4byte gUnknown_203B280
_0802156C: .4byte gUnknown_80DC494
_08021570: .4byte gTeamInventory_203B460
_08021574:
	mov r0, r10
	ldr r1, _08021598
	add r2, sp, 0x8
	bl sprintfStatic
	mov r3, r8
	ldr r0, [r3]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	b _080215FE
	.align 2, 0
_08021598: .4byte gUnknown_80DC4A4
_0802159C:
	cmp r6, 0
	bne _0802160C
	ldr r0, _080215D4
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080215D8
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x74]
	str r6, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_080215D4: .4byte gFriendAreas
_080215D8:
	adds r0, r5, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r0, r10
	ldr r1, _08021608
	bl sprintfStatic
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [r0, 0x74]
	str r6, [sp]
_080215FE:
	movs r0, 0x8
	mov r2, r10
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021608: .4byte gUnknown_80DC4AC
_0802160C:
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r7, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
_08021632:
	movs r0, 0x1
	add r9, r0
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x5A
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r9, r0
	bge _08021646
	b _08021502
_08021646:
	ldr r0, _08021660
	ldr r0, [r0]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	add sp, 0xA8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021660: .4byte gUnknown_203B280
	thumb_func_end sub_8021494

    .align  2,0
