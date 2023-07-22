	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start UpdateFelicityBankDialogue
UpdateFelicityBankDialogue:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _08016558
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0xC
	bls _0801654E
	b _080168EC
_0801654E:
	lsls r0, 2
	ldr r1, _0801655C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016558: .4byte gFelicityBankWork
_0801655C: .4byte _08016560
	.align 2, 0
_08016560:
	.4byte _08016594
	.4byte _080165B4
	.4byte _080168B2
	.4byte _08016650
	.4byte _08016668
	.4byte _080166C4
	.4byte _080168EC
	.4byte _080166DC
	.4byte _0801674C
	.4byte _080167A8
	.4byte _080167CC
	.4byte _0801685C
	.4byte _080168C4
_08016594:
	ldr r2, [r2]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r3, _080165B0
	ldr r1, [r2]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	adds r2, 0xA4
	ldr r2, [r2]
	b _08016844
	.align 2, 0
_080165B0: .4byte gFelicityDialogue
_080165B4:
	bl CreateFelicityBankShopMenu
	ldr r0, _080165FC
	ldr r0, [r0]
	mov r12, r0
	movs r0, 0x2
	mov r1, r12
	str r0, [r1, 0x8]
	ldr r0, _08016600
	ldr r0, [r0]
	movs r3, 0x99
	lsls r3, 2
	adds r0, r3
	ldr r4, [r0]
	cmp r4, 0
	bne _08016608
	ldr r2, _08016604
	ldr r1, [r1]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r0, r2
	ldr r0, [r0]
	mov r5, r12
	ldr r2, [r5, 0x10]
	mov r3, r12
	adds r3, 0x14
	mov r1, r12
	adds r1, 0x54
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	b _08016632
	.align 2, 0
_080165FC: .4byte gFelicityBankWork
_08016600: .4byte gTeamInventory_203B460
_08016604: .4byte gFelicityDialogue
_08016608:
	ldr r0, _08016648
	str r4, [r0]
	ldr r2, _0801664C
	mov r0, r12
	ldr r1, [r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	mov r1, r12
	ldr r2, [r1, 0x10]
	mov r3, r12
	adds r3, 0x14
	adds r1, 0x54
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
_08016632:
	mov r1, r12
	adds r1, 0xA4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080168EC
	.align 2, 0
_08016648: .4byte gUnknown_202DE30
_0801664C: .4byte gFelicityDialogue
_08016650:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016664
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x38
	b _0801683C
	.align 2, 0
_08016664: .4byte gFelicityDialogue
_08016668:
	ldr r3, [r2]
	movs r0, 0x6
	str r0, [r3, 0x8]
	ldr r0, _08016698
	ldr r0, [r0]
	movs r5, 0x99
	lsls r5, 2
	adds r0, r5
	ldr r1, [r0]
	cmp r1, 0
	bne _080166A0
	ldr r2, _0801669C
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x10
	adds r0, r2
	ldr r0, [r0]
	adds r1, r3, 0
	adds r1, 0xA4
	ldr r2, [r1]
	b _08016844
	.align 2, 0
_08016698: .4byte gTeamInventory_203B460
_0801669C: .4byte gFelicityDialogue
_080166A0:
	ldr r0, _080166BC
	str r1, [r0]
	ldr r2, _080166C0
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x14
	adds r0, r2
	ldr r0, [r0]
	adds r1, r3, 0
	adds r1, 0xA4
	ldr r2, [r1]
	b _08016844
	.align 2, 0
_080166BC: .4byte gUnknown_202DE30
_080166C0: .4byte gFelicityDialogue
_080166C4:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _080166D8
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0xC
	b _0801683C
	.align 2, 0
_080166D8: .4byte gFelicityDialogue
_080166DC:
	ldr r0, _08016700
	ldr r1, [r0]
	movs r3, 0x98
	lsls r3, 2
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, 0
	bne _08016708
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016704
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x1C
	b _0801683C
	.align 2, 0
_08016700: .4byte gTeamInventory_203B460
_08016704: .4byte gFelicityDialogue
_08016708:
	movs r5, 0x99
	lsls r5, 2
	adds r0, r1, r5
	ldr r1, [r0]
	ldr r0, _0801672C
	cmp r1, r0
	ble _08016734
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016730
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x20
	b _0801683C
	.align 2, 0
_0801672C: .4byte 0x0098967e
_08016730: .4byte gFelicityDialogue
_08016734:
	ldr r3, [r2]
	movs r0, 0x8
	str r0, [r3, 0x8]
	ldr r2, _08016748
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x18
	b _0801683C
	.align 2, 0
_08016748: .4byte gFelicityDialogue
_0801674C:
	ldr r4, [r2]
	ldr r0, _080167A0
	ldr r3, [r0]
	movs r1, 0x99
	lsls r1, 2
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _080167A4
	subs r0, r1
	str r0, [r4, 0x70]
	movs r5, 0x98
	lsls r5, 2
	adds r1, r3, r5
	ldr r1, [r1]
	cmp r0, r1
	ble _0801676E
	str r1, [r4, 0x70]
_0801676E:
	ldr r2, [r2]
	ldr r0, [r2, 0x70]
	str r0, [r2, 0x68]
	movs r0, 0x1
	str r0, [r2, 0x6C]
	movs r0, 0x5
	str r0, [r2, 0x74]
	movs r0, 0x2
	str r0, [r2, 0x78]
	adds r0, r2, 0
	adds r0, 0xD8
	str r0, [r2, 0x7C]
	adds r1, r2, 0
	adds r1, 0x80
	movs r0, 0x50
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x64
	bl sub_8013AA0
	movs r0, 0x1
	b _080168AE
	.align 2, 0
_080167A0: .4byte gTeamInventory_203B460
_080167A4: .4byte 0x0098967f
_080167A8:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r1, _080167C4
	ldr r0, [r3, 0xC]
	str r0, [r1]
	ldr r2, _080167C8
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x24
	b _0801683C
	.align 2, 0
_080167C4: .4byte gUnknown_202DE30
_080167C8: .4byte gFelicityDialogue
_080167CC:
	ldr r0, _080167F4
	ldr r3, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _080167F8
	cmp r1, r0
	ble _08016800
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _080167FC
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x30
	b _0801683C
	.align 2, 0
_080167F4: .4byte gTeamInventory_203B460
_080167F8: .4byte 0x0001869e
_080167FC: .4byte gFelicityDialogue
_08016800:
	movs r5, 0x99
	lsls r5, 2
	adds r4, r3, r5
	ldr r0, [r4]
	cmp r0, 0
	bne _08016824
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08016820
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x2C
	b _0801683C
	.align 2, 0
_08016820: .4byte gFelicityDialogue
_08016824:
	ldr r3, [r2]
	movs r0, 0xB
	str r0, [r3, 0x8]
	ldr r1, _08016850
	ldr r0, [r4]
	str r0, [r1]
	ldr r2, _08016854
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x28
_0801683C:
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xA4
	ldr r2, [r3]
_08016844:
	ldr r3, _08016858
	movs r1, 0
	bl sub_80141B4
	b _080168EC
	.align 2, 0
_08016850: .4byte gUnknown_202DE30
_08016854: .4byte gFelicityDialogue
_08016858: .4byte 0x0000010d
_0801685C:
	ldr r4, [r2]
	ldr r0, _080168BC
	ldr r3, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _080168C0
	subs r0, r1
	str r0, [r4, 0x70]
	movs r5, 0x99
	lsls r5, 2
	adds r1, r3, r5
	ldr r1, [r1]
	cmp r0, r1
	ble _0801687E
	str r1, [r4, 0x70]
_0801687E:
	ldr r2, [r2]
	ldr r0, [r2, 0x70]
	str r0, [r2, 0x68]
	movs r0, 0x1
	str r0, [r2, 0x6C]
	movs r0, 0x5
	str r0, [r2, 0x74]
	movs r0, 0x2
	str r0, [r2, 0x78]
	adds r0, r2, 0
	adds r0, 0xD8
	str r0, [r2, 0x7C]
	adds r1, r2, 0
	adds r1, 0x80
	movs r0, 0x50
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x64
	bl sub_8013AA0
	movs r0, 0
_080168AE:
	bl sub_8016B48
_080168B2:
	movs r0, 0x3
	bl CreateFelicityMoneySavingsHeader
	b _080168EC
	.align 2, 0
_080168BC: .4byte gTeamInventory_203B460
_080168C0: .4byte 0x0001869f
_080168C4:
	ldr r3, [r2]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r1, _080168F4
	ldr r0, [r3, 0xC]
	str r0, [r1]
	ldr r2, _080168F8
	ldr r1, [r3]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r2, 0x34
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xA4
	ldr r2, [r3]
	ldr r3, _080168FC
	movs r1, 0
	bl sub_80141B4
_080168EC:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080168F4: .4byte gUnknown_202DE30
_080168F8: .4byte gFelicityDialogue
_080168FC: .4byte 0x0000010d
	thumb_func_end UpdateFelicityBankDialogue

	thumb_func_start CreateFelicityBankShopMenu
CreateFelicityBankShopMenu:
	push {r4-r7,lr}
	ldr r4, _08016980
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08016984
	ldr r0, [r0]
	str r0, [r3, 0x14]
	movs r0, 0x2
	str r0, [r3, 0x18]
	movs r1, 0x1
	ldr r0, _08016988
	ldr r0, [r0]
	str r0, [r3, 0x1C]
	movs r0, 0x3
	str r0, [r3, 0x20]
	ldr r0, _0801698C
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x4
	str r0, [r3, 0x28]
	ldr r0, _08016990
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	str r1, [r3, 0x30]
	movs r6, 0x4
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x18
	mov r2, r12
	adds r2, 0x54
_0801694C:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0801695C
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x10]
	cmp r1, r0
	beq _080169B6
_0801695C:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0801694C
	movs r5, 0
	cmp r5, r6
	bge _080169B6
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x54
	ldrh r0, [r0]
	cmp r0, 0
	bne _08016994
	ldr r0, [r1, 0x18]
	str r0, [r1, 0x10]
	b _080169B6
	.align 2, 0
_08016980: .4byte gFelicityBankWork
_08016984: .4byte gUnknown_80D4958
_08016988: .4byte gUnknown_80D4964
_0801698C: .4byte gUnknown_80D4970
_08016990: .4byte gUnknown_80D4934
_08016994:
	adds r5, 0x1
	cmp r5, r6
	bge _080169B6
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x54
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08016994
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x18
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x10]
_080169B6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateFelicityBankShopMenu

        .align 2,0
