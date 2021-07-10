	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8016FF8
sub_8016FF8:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _08017014
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x1D
	bls _0801700A
	b _08017584
_0801700A:
	lsls r0, 2
	ldr r1, _08017018
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017014: .4byte gUnknown_203B208
_08017018: .4byte _0801701C
	.align 2, 0
_0801701C:
	.4byte _08017094
	.4byte _080170BC
	.4byte _0801710C
	.4byte _0801713C
	.4byte _08017584
	.4byte _0801715C
	.4byte _0801718C
	.4byte _080171BC
	.4byte _080171EC
	.4byte _0801721C
	.4byte _0801724C
	.4byte _0801726C
	.4byte _0801728C
	.4byte _080172AC
	.4byte _080172BA
	.4byte _080172C2
	.4byte _080174A8
	.4byte _080172E4
	.4byte _0801731C
	.4byte _08017344
	.4byte _08017394
	.4byte _080173B4
	.4byte _080173E8
	.4byte _080173F6
	.4byte _08017404
	.4byte _08017474
	.4byte _080174A8
	.4byte _080174B2
	.4byte _080174E8
	.4byte _08017530
_08017094:
	bl sub_80175FC
	ldr r2, _080170B4
	ldr r0, [r2]
	adds r0, 0xE4
	movs r4, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r3, _080170B8
	ldr r5, [r2]
	ldr r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r0, r3
	b _080170DA
	.align 2, 0
_080170B4: .4byte gUnknown_203B208
_080170B8: .4byte gUnknown_80D5404
_080170BC:
	bl sub_80175FC
	ldr r1, _08017104
	ldr r0, [r1]
	adds r0, 0xE4
	movs r4, 0
	strb r4, [r0]
	ldr r2, _08017108
	ldr r5, [r1]
	ldr r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4
	adds r0, r2
_080170DA:
	ldr r0, [r0]
	ldr r2, [r5, 0x18]
	adds r3, r5, 0
	adds r3, 0x24
	adds r1, r5, 0
	adds r1, 0x4C
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r1, r5, 0
	adds r1, 0xE8
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08017584
	.align 2, 0
_08017104: .4byte gUnknown_203B208
_08017108: .4byte gUnknown_80D5404
_0801710C:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017134
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4C
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017138
	b _080173D8
	.align 2, 0
_08017134: .4byte gUnknown_80D5404
_08017138: .4byte 0x0000010d
_0801713C:
	ldr r0, [r4]
	movs r1, 0x4
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _08017158
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x8
	b _080173CE
	.align 2, 0
_08017158: .4byte gUnknown_80D5404
_0801715C:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017184
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x34
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017188
	b _080173D8
	.align 2, 0
_08017184: .4byte gUnknown_80D5404
_08017188: .4byte 0x0000010d
_0801718C:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080171B4
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x38
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _080171B8
	b _080173D8
	.align 2, 0
_080171B4: .4byte gUnknown_80D5404
_080171B8: .4byte 0x0000010d
_080171BC:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080171E4
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x3C
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _080171E8
	b _080173D8
	.align 2, 0
_080171E4: .4byte gUnknown_80D5404
_080171E8: .4byte 0x0000010d
_080171EC:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017214
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x48
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017218
	b _080173D8
	.align 2, 0
_08017214: .4byte gUnknown_80D5404
_08017218: .4byte 0x0000010d
_0801721C:
	ldr r0, _08017244
	ldr r1, [r4]
	adds r1, 0xC
	movs r2, 0
	bl sub_8090E14
	ldr r0, [r4]
	movs r1, 0xE
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017248
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x40
	b _080173CE
	.align 2, 0
_08017244: .4byte gUnknown_202DE58
_08017248: .4byte gUnknown_80D5404
_0801724C:
	ldr r0, [r4]
	movs r1, 0xE
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017268
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x44
	b _080173CE
	.align 2, 0
_08017268: .4byte gUnknown_80D5404
_0801726C:
	ldr r0, [r4]
	movs r1, 0xD
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08017288
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0xC
	b _080173CE
	.align 2, 0
_08017288: .4byte gUnknown_80D5404
_0801728C:
	ldr r0, [r4]
	movs r1, 0xE
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080172A8
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x10
	b _080173CE
	.align 2, 0
_080172A8: .4byte gUnknown_80D5404
_080172AC:
	movs r0, 0x3
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08017584
_080172BA:
	movs r0, 0x1
	bl sub_801A8D0
	b _08017584
_080172C2:
	bl sub_801A9E0
	bl sub_80176B8
	ldr r0, _080172E0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	adds r1, r2, 0
	adds r1, 0x24
	adds r3, r2, 0
	adds r3, 0x4C
	ldr r2, [r2, 0x1C]
	b _08017494
	.align 2, 0
_080172E0: .4byte gUnknown_203B208
_080172E4:
	bl sub_80177F8
	ldr r0, _08017310
	ldr r4, _08017314
	ldr r1, [r4]
	adds r1, 0xC
	movs r2, 0
	bl sub_8090E14
	ldr r0, [r4]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _08017318
	ldr r4, [r4]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x14
	b _08017504
	.align 2, 0
_08017310: .4byte gUnknown_202DE58
_08017314: .4byte gUnknown_203B208
_08017318: .4byte gUnknown_80D5404
_0801731C:
	bl sub_80177F8
	ldr r1, _0801733C
	ldr r0, [r1]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _08017340
	ldr r4, [r1]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x18
	b _08017504
	.align 2, 0
_0801733C: .4byte gUnknown_203B208
_08017340: .4byte gUnknown_80D5404
_08017344:
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _0801735C
	bl sub_801A928
	ldr r0, _08017358
	ldr r1, [r0]
	movs r0, 0x1
	b _08017362
	.align 2, 0
_08017358: .4byte gUnknown_203B208
_0801735C:
	ldr r0, _08017388
	ldr r1, [r0]
	movs r0, 0xC
_08017362:
	str r0, [r1, 0x8]
	ldr r3, _08017388
	ldr r0, [r3]
	adds r0, 0xE4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0801738C
	ldr r3, [r3]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x1C
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017390
	b _080173D8
	.align 2, 0
_08017388: .4byte gUnknown_203B208
_0801738C: .4byte gUnknown_80D5404
_08017390: .4byte 0x0000010d
_08017394:
	ldr r0, [r4]
	movs r1, 0x16
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080173B0
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x20
	b _080173CE
	.align 2, 0
_080173B0: .4byte gUnknown_80D5404
_080173B4:
	ldr r0, [r4]
	movs r1, 0x17
	str r1, [r0, 0x8]
	adds r0, 0xE4
	movs r1, 0
	strb r1, [r0]
	ldr r2, _080173E0
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x24
_080173CE:
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _080173E4
_080173D8:
	movs r1, 0
	bl sub_80141B4
	b _08017584
	.align 2, 0
_080173E0: .4byte gUnknown_80D5404
_080173E4: .4byte 0x0000030d
_080173E8:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801C8C4
	b _080173FC
_080173F6:
	movs r0, 0x1
	bl sub_801CB5C
_080173FC:
	movs r0, 0
	bl sub_801AD34
	b _08017584
_08017404:
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xB8
	movs r0, 0x2
	str r0, [r1]
	subs r1, 0x8
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08017430
	ldr r1, [r0]
	ldrb r0, [r2, 0xE]
	lsls r0, 1
	adds r1, 0x50
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, 0x63
	bls _08017434
	adds r1, r2, 0
	adds r1, 0xB4
	movs r0, 0x63
	b _0801743A
	.align 2, 0
_08017430: .4byte gTeamInventory_203B460
_08017434:
	adds r1, r2, 0
	adds r1, 0xB4
	ldrh r0, [r3]
_0801743A:
	str r0, [r1]
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xAC
	adds r0, r2, 0
	adds r0, 0xB4
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x10
	movs r0, 0x1
	str r0, [r1]
	adds r1, 0x4
	movs r3, 0x82
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x28
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x12
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0xA8
	bl sub_8013AA0
	bl sub_8017598
	b _08017584
_08017474:
	bl sub_801CCD8
	movs r0, 0
	bl sub_801AD34
	bl sub_8017758
	ldr r0, _080174A4
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	adds r1, r2, 0
	adds r1, 0x24
	adds r3, r2, 0
	adds r3, 0x4C
	ldr r2, [r2, 0x20]
_08017494:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08017584
	.align 2, 0
_080174A4: .4byte gUnknown_203B208
_080174A8:
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_801B3C0
	b _08017584
_080174B2:
	bl sub_80177F8
	ldr r0, _080174DC
	ldr r4, _080174E0
	ldr r1, [r4]
	adds r1, 0xC
	movs r2, 0
	bl sub_8090E14
	ldr r0, [r4]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _080174E4
	ldr r4, [r4]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x28
	b _08017504
	.align 2, 0
_080174DC: .4byte gUnknown_202DE58
_080174E0: .4byte gUnknown_203B208
_080174E4: .4byte gUnknown_80D5404
_080174E8:
	bl sub_80177F8
	ldr r1, _08017528
	ldr r0, [r1]
	adds r0, 0xE4
	movs r5, 0
	strb r5, [r0]
	ldr r2, _0801752C
	ldr r4, [r1]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x2C
_08017504:
	adds r0, r2
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x24
	str r5, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	adds r4, 0xE8
	ldr r1, [r4]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x4
	bl sub_8014248
	b _08017584
	.align 2, 0
_08017528: .4byte gUnknown_203B208
_0801752C: .4byte gUnknown_80D5404
_08017530:
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08017544
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	ble _08017554
_08017544:
	bl sub_801CBB8
	ldr r0, _08017550
	ldr r1, [r0]
	movs r0, 0x1
	b _0801755A
	.align 2, 0
_08017550: .4byte gUnknown_203B208
_08017554:
	ldr r0, _0801758C
	ldr r1, [r0]
	movs r0, 0x15
_0801755A:
	str r0, [r1, 0x8]
	ldr r3, _0801758C
	ldr r0, [r3]
	adds r0, 0xE4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _08017590
	ldr r3, [r3]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x30
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xE8
	ldr r2, [r3]
	ldr r3, _08017594
	movs r1, 0
	bl sub_80141B4
_08017584:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801758C: .4byte gUnknown_203B208
_08017590: .4byte gUnknown_80D5404
_08017594: .4byte 0x0000010d
	thumb_func_end sub_8016FF8


        .align 2,0
