	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start UpdateKecleonStoreDialogue
UpdateKecleonStoreDialogue:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _08018EA4
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r4, r1, 0
	cmp r0, 0x20
	bls _08018E9A
	b _080194E8
_08018E9A:
	lsls r0, 2
	ldr r1, _08018EA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018EA4: .4byte gUnknown_203B210
_08018EA8: .4byte _08018EAC
	.align 2, 0
_08018EAC:
	.4byte _08018F30
	.4byte _08018F58
	.4byte _08018FA8
	.4byte _08018FD0
	.4byte _080194E8
	.4byte _08018FFC
	.4byte _08019024
	.4byte _0801904C
	.4byte _08019070
	.4byte _08019094
	.4byte _080190B8
	.4byte _080190DC
	.4byte _08019104
	.4byte _0801912C
	.4byte _08019164
	.4byte _0801918C
	.4byte _080191B4
	.4byte _08019294
	.4byte _080191DC
	.4byte _080191FA
	.4byte _08019218
	.4byte _080193F4
	.4byte _08019254
	.4byte _08019314
	.4byte _0801933C
	.4byte _080193FE
	.4byte _08019364
	.4byte _08019372
	.4byte _08019380
	.4byte _080193F4
	.4byte _080193B4
	.4byte _0801946C
	.4byte _080194C0
_08018F30:
	bl sub_8019DAC
	bl sub_80194F8
	movs r0, 0
	bl sub_8019E04
	ldr r2, _08018F50
	ldr r0, _08018F54
	ldr r4, [r0]
	ldr r1, [r4]
	movs r0, 0x5C
	muls r0, r1
	adds r0, r2
	b _08018F76
	.align 2, 0
_08018F50: .4byte gKecleonShopDialogue
_08018F54: .4byte gUnknown_203B210
_08018F58:
	bl sub_8019DAC
	bl sub_80194F8
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08018FA0
	ldr r0, _08018FA4
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x4
	adds r0, r1
_08018F76:
	ldr r0, [r0]
	ldr r2, [r4, 0x28]
	adds r3, r4, 0
	adds r3, 0x34
	adds r1, r4, 0
	adds r1, 0x74
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r1, r4, 0
	adds r1, 0xE4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080194E8
	.align 2, 0
_08018FA0: .4byte gKecleonShopDialogue
_08018FA4: .4byte gUnknown_203B210
_08018FA8:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08018FCC
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x58
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08018FCC: .4byte gKecleonShopDialogue
_08018FD0:
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08018FF4
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	ldr r3, _08018FF8
	b _08019456
	.align 2, 0
_08018FF4: .4byte gKecleonShopDialogue
_08018FF8: .4byte 0x0000030d
_08018FFC:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019020
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x30
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019020: .4byte gKecleonShopDialogue
_08019024:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019048
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x34
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019048: .4byte gKecleonShopDialogue
_0801904C:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _0801906C
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x38
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_0801906C: .4byte gKecleonShopDialogue
_08019070:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _08019090
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x3C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019090: .4byte gKecleonShopDialogue
_08019094:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _080190B4
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x40
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080190B4: .4byte gKecleonShopDialogue
_080190B8:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	bl sub_8019E04
	ldr r1, _080190D8
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x44
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080190D8: .4byte gKecleonShopDialogue
_080190DC:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019100
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019100: .4byte gKecleonShopDialogue
_08019104:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019128
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019128: .4byte gKecleonShopDialogue
_0801912C:
	ldr r0, _0801915C
	ldr r1, [r4]
	adds r1, 0x1C
	movs r2, 0
	bl sub_8090E14
	ldr r1, [r4]
	movs r0, 0x18
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019160
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_0801915C: .4byte gUnknown_202DE58
_08019160: .4byte gKecleonShopDialogue
_08019164:
	ldr r1, [r4]
	movs r0, 0x18
	str r0, [r1, 0xC]
	movs r0, 0x1
	bl sub_8019E04
	ldr r1, _08019188
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x54
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019188: .4byte gKecleonShopDialogue
_0801918C:
	ldr r1, [r4]
	movs r0, 0x12
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080191B0
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0xC
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080191B0: .4byte gKecleonShopDialogue
_080191B4:
	ldr r1, [r4]
	movs r0, 0x13
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080191D8
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x10
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_080191D8: .4byte gKecleonShopDialogue
_080191DC:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080191EC
	movs r0, 0x3
	bl sub_8019E40
	b _080191F2
_080191EC:
	movs r0, 0x3
	bl sub_801A20C
_080191F2:
	movs r0, 0
	bl sub_801AD34
	b _08019378
_080191FA:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0801920A
	movs r0, 0x1
	bl sub_8019FCC
	b _08019210
_0801920A:
	movs r0, 0x1
	bl sub_801A398
_08019210:
	movs r0, 0
	bl sub_801AD34
	b _08019378
_08019218:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019226
	bl sub_801A0D8
	b _0801922A
_08019226:
	bl sub_801A4A4
_0801922A:
	movs r0, 0
	bl sub_801AD34
	movs r0, 0x1
	bl sub_8016C40
	bl sub_80195C0
	ldr r0, _08019250
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x84
	adds r1, r2, 0
	adds r1, 0x34
	adds r3, r2, 0
	adds r3, 0x74
	ldr r2, [r2, 0x30]
	b _080193A0
	.align 2, 0
_08019250: .4byte gUnknown_203B210
_08019254:
	bl sub_8019700
	ldr r0, _08019284
	ldr r4, _08019288
	ldr r1, [r4]
	adds r1, 0x1C
	movs r2, 0
	bl sub_8090E14
	ldr r1, _0801928C
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [r1]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019290
	ldr r4, [r4]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x14
	b _0801948C
	.align 2, 0
_08019284: .4byte gUnknown_202DE58
_08019288: .4byte gUnknown_203B210
_0801928C: .4byte gUnknown_202DE30
_08019290: .4byte gKecleonShopDialogue
_08019294:
	bl sub_8019D8C
	cmp r0, 0
	bne _080192C0
	ldr r0, _080192AC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080192B0
	bl sub_801A010
	b _080192B4
	.align 2, 0
_080192AC: .4byte gUnknown_203B210
_080192B0:
	bl sub_801A3DC
_080192B4:
	ldr r0, _080192BC
	ldr r1, [r0]
	movs r0, 0xB
	b _080192F2
	.align 2, 0
_080192BC: .4byte gUnknown_203B210
_080192C0:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080192EC
	ldr r0, _080192D8
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080192DC
	bl sub_801A010
	b _080192E0
	.align 2, 0
_080192D8: .4byte gUnknown_203B210
_080192DC:
	bl sub_801A3DC
_080192E0:
	ldr r0, _080192E8
	ldr r1, [r0]
	movs r0, 0x1
	b _080192F2
	.align 2, 0
_080192E8: .4byte gUnknown_203B210
_080192EC:
	ldr r0, _0801930C
	ldr r1, [r0]
	movs r0, 0x10
_080192F2:
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r2, _08019310
	ldr r0, _0801930C
	ldr r1, [r0]
	ldr r3, [r1]
	movs r0, 0x5C
	muls r0, r3
	adds r2, 0x18
	b _0801944C
	.align 2, 0
_0801930C: .4byte gUnknown_203B210
_08019310: .4byte gKecleonShopDialogue
_08019314:
	ldr r1, [r4]
	movs r0, 0x1A
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019338
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019338: .4byte gKecleonShopDialogue
_0801933C:
	ldr r1, [r4]
	movs r0, 0x1B
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _08019360
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x20
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	b _08019454
	.align 2, 0
_08019360: .4byte gKecleonShopDialogue
_08019364:
	movs r0, 0x4
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08019378
_08019372:
	movs r0, 0x1
	bl sub_801A8D0
_08019378:
	movs r0, 0x1
	bl sub_8016C40
	b _080194E8
_08019380:
	bl sub_801A9E0
	movs r0, 0x1
	bl sub_8016C40
	bl sub_8019660
	ldr r0, _080193B0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x84
	adds r1, r2, 0
	adds r1, 0x34
	adds r3, r2, 0
	adds r3, 0x74
	ldr r2, [r2, 0x2C]
_080193A0:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080194E8
	.align 2, 0
_080193B0: .4byte gUnknown_203B210
_080193B4:
	bl sub_8019700
	ldr r0, _080193E4
	ldr r4, _080193E8
	ldr r1, [r4]
	adds r1, 0x1C
	movs r2, 0
	bl sub_8090E14
	ldr r1, _080193EC
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [r1]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080193F0
	ldr r4, [r4]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x24
	b _0801948C
	.align 2, 0
_080193E4: .4byte gUnknown_202DE58
_080193E8: .4byte gUnknown_203B210
_080193EC: .4byte gUnknown_202DE30
_080193F0: .4byte gKecleonShopDialogue
_080193F4:
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_801B3C0
	b _080194E8
_080193FE:
	bl sub_8090A34
	cmp r0, 0
	beq _08019418
	ldr r0, _08019424
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _08019428
	cmp r1, r0
	ble _08019430
_08019418:
	bl sub_801A928
	ldr r0, _0801942C
	ldr r1, [r0]
	movs r0, 0x1
	b _08019436
	.align 2, 0
_08019424: .4byte gUnknown_203B460
_08019428: .4byte 0x0001869e
_0801942C: .4byte gUnknown_203B210
_08019430:
	ldr r0, _08019460
	ldr r1, [r0]
	movs r0, 0x18
_08019436:
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r2, _08019464
	ldr r0, _08019460
	ldr r1, [r0]
	ldr r3, [r1]
	movs r0, 0x5C
	muls r0, r3
	adds r2, 0x2C
_0801944C:
	adds r0, r2
	ldr r0, [r0]
	adds r1, 0xE4
	ldr r2, [r1]
_08019454:
	ldr r3, _08019468
_08019456:
	movs r1, 0
	bl sub_80141B4
	b _080194E8
	.align 2, 0
_08019460: .4byte gUnknown_203B210
_08019464: .4byte gKecleonShopDialogue
_08019468: .4byte 0x0000010d
_0801946C:
	bl sub_8019700
	ldr r1, _080194B4
	ldr r4, _080194B8
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	str r0, [r1]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080194BC
	ldr r4, [r4]
	ldr r2, [r4]
	movs r0, 0x5C
	muls r0, r2
	adds r1, 0x28
_0801948C:
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x34
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	adds r4, 0xE4
	ldr r1, [r4]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _080194E8
	.align 2, 0
_080194B4: .4byte gUnknown_202DE30
_080194B8: .4byte gUnknown_203B210
_080194BC: .4byte gKecleonShopDialogue
_080194C0:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0xC]
	movs r0, 0
	bl sub_8019E04
	ldr r1, _080194F0
	ldr r2, [r4]
	ldr r3, [r2]
	movs r0, 0x5C
	muls r0, r3
	adds r1, 0x2C
	adds r0, r1
	ldr r0, [r0]
	adds r2, 0xE4
	ldr r2, [r2]
	ldr r3, _080194F4
	movs r1, 0
	bl sub_80141B4
_080194E8:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080194F0: .4byte gKecleonShopDialogue
_080194F4: .4byte 0x0000010d
	thumb_func_end UpdateKecleonStoreDialogue

	thumb_func_start sub_80194F8
sub_80194F8:
	push {r4-r7,lr}
	ldr r4, _08019580
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08019584
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x2
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08019588
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x3
	str r0, [r3, 0x40]
	ldr r0, _0801958C
	str r0, [r3, 0x44]
	movs r0, 0x4
	str r0, [r3, 0x48]
	ldr r0, _08019590
	ldr r0, [r0]
	str r0, [r3, 0x4C]
	movs r0, 0x7
	str r0, [r3, 0x50]
	ldr r0, _08019594
	ldr r0, [r0]
	str r0, [r3, 0x54]
	str r1, [r3, 0x58]
	movs r6, 0x5
	str r2, [r3, 0x5C]
	str r1, [r3, 0x60]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_0801954C:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0801955C
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x28]
	cmp r1, r0
	beq _080195BA
_0801955C:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0801954C
	movs r5, 0
	cmp r5, r6
	bge _080195BA
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x74
	ldrh r0, [r0]
	cmp r0, 0
	bne _08019598
	ldr r0, [r1, 0x38]
	str r0, [r1, 0x28]
	b _080195BA
	.align 2, 0
_08019580: .4byte gUnknown_203B210
_08019584: .4byte gUnknown_80D4978
_08019588: .4byte gUnknown_80D4984
_0801958C: .4byte gUnknown_80DB8A0
_08019590: .4byte gUnknown_80D4970
_08019594: .4byte gUnknown_80D4934
_08019598:
	adds r5, 0x1
	cmp r5, r6
	bge _080195BA
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08019598
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x38
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x28]
_080195BA:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80194F8

	thumb_func_start sub_80195C0
sub_80195C0:
	push {r4-r7,lr}
	ldr r4, _0801962C
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08019630
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x2
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08019634
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x7
	str r0, [r3, 0x40]
	movs r6, 0x2
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_080195FA:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0801960A
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x30]
	cmp r1, r0
	beq _0801965A
_0801960A:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080195FA
	movs r5, 0
	cmp r5, r6
	bge _0801965A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x74
	ldrh r0, [r0]
	cmp r0, 0
	bne _08019638
	ldr r0, [r1, 0x38]
	str r0, [r1, 0x30]
	b _0801965A
	.align 2, 0
_0801962C: .4byte gUnknown_203B210
_08019630: .4byte gUnknown_80D4978
_08019634: .4byte gUnknown_80D4970
_08019638:
	adds r5, 0x1
	cmp r5, r6
	bge _0801965A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08019638
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x38
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x30]
_0801965A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80195C0

	thumb_func_start sub_8019660
sub_8019660:
	push {r4-r7,lr}
	ldr r4, _080196CC
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080196D0
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x3
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _080196D4
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x7
	str r0, [r3, 0x40]
	movs r6, 0x2
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_0801969A:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080196AA
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x2C]
	cmp r1, r0
	beq _080196FA
_080196AA:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0801969A
	movs r5, 0
	cmp r5, r6
	bge _080196FA
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x74
	ldrh r0, [r0]
	cmp r0, 0
	bne _080196D8
	ldr r0, [r1, 0x38]
	str r0, [r1, 0x2C]
	b _080196FA
	.align 2, 0
_080196CC: .4byte gUnknown_203B210
_080196D0: .4byte gUnknown_80D4984
_080196D4: .4byte gUnknown_80D4970
_080196D8:
	adds r5, 0x1
	cmp r5, r6
	bge _080196FA
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080196D8
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x38
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x2C]
_080196FA:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8019660

	thumb_func_start sub_8019700
sub_8019700:
	ldr r0, _08019724
	ldr r1, [r0]
	movs r3, 0
	ldr r0, _08019728
	ldr r0, [r0]
	str r0, [r1, 0x34]
	movs r0, 0x5
	str r0, [r1, 0x38]
	movs r2, 0x1
	ldr r0, _0801972C
	ldr r0, [r0]
	str r0, [r1, 0x3C]
	movs r0, 0x6
	str r0, [r1, 0x40]
	str r3, [r1, 0x44]
	str r2, [r1, 0x48]
	bx lr
	.align 2, 0
_08019724: .4byte gUnknown_203B210
_08019728: .4byte gUnknown_80D4920
_0801972C: .4byte gUnknown_80D4928
	thumb_func_end sub_8019700

	thumb_func_start sub_8019730
sub_8019730:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	beq _08019740
	b _0801984A
_08019740:
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801974C
	ldr r0, _08019760
	ldr r0, [r0]
	str r1, [r0, 0x28]
_0801974C:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bls _08019756
	b _0801984A
_08019756:
	lsls r0, 2
	ldr r1, _08019764
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08019760: .4byte gUnknown_203B210
_08019764: .4byte _08019768
	.align 2, 0
_08019768:
	.4byte _08019844
	.4byte _08019784
	.4byte _080197AC
	.4byte _080197E4
	.4byte _0801984A
	.4byte _0801984A
	.4byte _0801983C
_08019784:
	bl sub_8019D8C
	cmp r0, 0
	bne _08019794
	movs r0, 0x5
	bl UpdateKecleonStoreState
	b _0801984A
_08019794:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080197A4
	movs r0, 0xA
	bl UpdateKecleonStoreState
	b _0801984A
_080197A4:
	movs r0, 0xF
	bl UpdateKecleonStoreState
	b _0801984A
_080197AC:
	bl sub_8090A34
	cmp r0, 0
	beq _080197EC
	ldr r0, _080197D8
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _080197FE
	ldr r0, _080197DC
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _080197E0
	cmp r1, r0
	bgt _08019822
	movs r0, 0x17
	bl UpdateKecleonStoreState
	b _0801984A
	.align 2, 0
_080197D8: .4byte gUnknown_203B210
_080197DC: .4byte gUnknown_203B460
_080197E0: .4byte 0x0001869e
_080197E4:
	bl sub_8090A34
	cmp r0, 0
	bne _080197F4
_080197EC:
	movs r0, 0x9
	bl UpdateKecleonStoreState
	b _0801984A
_080197F4:
	ldr r0, _08019808
	ldr r1, [r0]
	ldr r0, [r1, 0x14]
	cmp r0, 0
	bne _0801980C
_080197FE:
	movs r0, 0x8
	bl UpdateKecleonStoreState
	b _0801984A
	.align 2, 0
_08019808: .4byte gUnknown_203B210
_0801980C:
	ldr r0, _0801982C
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1, 0x18]
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _08019830
	cmp r1, r0
	ble _08019834
_08019822:
	movs r0, 0x7
	bl UpdateKecleonStoreState
	b _0801984A
	.align 2, 0
_0801982C: .4byte gUnknown_203B460
_08019830: .4byte 0x0001869f
_08019834:
	movs r0, 0x1F
	bl UpdateKecleonStoreState
	b _0801984A
_0801983C:
	movs r0, 0x2
	bl UpdateKecleonStoreState
	b _0801984A
_08019844:
	movs r0, 0x3
	bl UpdateKecleonStoreState
_0801984A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8019730

	thumb_func_start sub_8019850
sub_8019850:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080198DE
	ldr r0, [sp]
	cmp r0, 0x5
	beq _08019874
	cmp r0, 0x5
	bgt _0801986E
	cmp r0, 0x1
	beq _080198D8
	b _080198DE
_0801986E:
	cmp r0, 0x6
	beq _080198D8
	b _080198DE
_08019874:
	ldr r4, _080198A8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	negs r0, r0
	bl AddToTeamMoney
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _080198AC
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_809185C
	bl sub_8091274
	ldr r0, [r4]
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_8091840
	bl sub_8091874
	b _080198C8
	.align 2, 0
_080198A8: .4byte gUnknown_203B210
_080198AC:
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A90
	bl sub_8091274
	ldr r0, [r4]
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A74
	bl sub_8091AA8
_080198C8:
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySound
	movs r0, 0x11
	bl UpdateKecleonStoreState
	b _080198DE
_080198D8:
	movs r0, 0x10
	bl UpdateKecleonStoreState
_080198DE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8019850

	thumb_func_start sub_80198E8
sub_80198E8:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801993A
	ldr r0, [sp]
	cmp r0, 0x5
	beq _0801990C
	cmp r0, 0x5
	bgt _08019906
	cmp r0, 0x1
	beq _08019934
	b _0801993A
_08019906:
	cmp r0, 0x6
	beq _08019934
	b _0801993A
_0801990C:
	ldr r4, _08019930
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl AddToTeamMoney
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySound
	movs r0, 0x19
	bl UpdateKecleonStoreState
	b _0801993A
	.align 2, 0
_08019930: .4byte gUnknown_203B210
_08019934:
	movs r0, 0x18
	bl UpdateKecleonStoreState
_0801993A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80198E8

	thumb_func_start sub_8019944
sub_8019944:
	push {r4,r5,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080199C2
	ldr r0, [sp]
	cmp r0, 0x5
	beq _08019968
	cmp r0, 0x5
	bgt _08019962
	cmp r0, 0x1
	beq _080199BC
	b _080199C2
_08019962:
	cmp r0, 0x6
	beq _080199BC
	b _080199C2
_08019968:
	movs r4, 0
	ldr r5, _080199B4
_0801996C:
	lsls r1, r4, 2
	ldr r0, [r5]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0801998E
	ldrb r0, [r2, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	beq _0801998E
	adds r0, r4, 0
	bl sub_8091234
_0801998E:
	adds r4, 0x1
	cmp r4, 0x13
	ble _0801996C
	bl sub_80910B4
	ldr r0, _080199B8
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl AddToTeamMoney
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySound
	movs r0, 0x20
	bl UpdateKecleonStoreState
	b _080199C2
	.align 2, 0
_080199B4: .4byte gUnknown_203B460
_080199B8: .4byte gUnknown_203B210
_080199BC:
	movs r0, 0x1
	bl UpdateKecleonStoreState
_080199C2:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8019944

	thumb_func_start sub_80199CC
sub_80199CC:
	push {r4,r5,lr}
	ldr r0, _080199E0
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080199E4
	movs r0, 0x1
	bl sub_8019EDC
	b _080199EA
	.align 2, 0
_080199E0: .4byte gUnknown_203B210
_080199E4:
	movs r0, 0x1
	bl sub_801A2A8
_080199EA:
	cmp r0, 0x2
	beq _08019AD4
	cmp r0, 0x2
	bhi _080199FA
	cmp r0, 0x1
	bne _080199F8
	b _08019AF4
_080199F8:
	b _08019B00
_080199FA:
	cmp r0, 0x3
	beq _08019A04
	cmp r0, 0x4
	beq _08019A6C
	b _08019B00
_08019A04:
	ldr r4, _08019A24
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019A28
	bl sub_8019FB0
	ldr r1, [r4]
	adds r1, 0x20
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_809185C
	b _08019A3C
	.align 2, 0
_08019A24: .4byte gUnknown_203B210
_08019A28:
	bl sub_801A37C
	ldr r1, [r4]
	adds r1, 0x21
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A90
_08019A3C:
	adds r5, r0, 0
	ldr r4, _08019A68
	ldr r0, [r4]
	adds r0, 0x1C
	ldrb r1, [r5]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	ldrb r0, [r5, 0x1]
	strb r0, [r1, 0x1D]
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_8090C7C
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x14
	bl UpdateKecleonStoreState
	b _08019B00
	.align 2, 0
_08019A68: .4byte gUnknown_203B210
_08019A6C:
	ldr r4, _08019A8C
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019A90
	bl sub_8019FB0
	ldr r1, [r4]
	adds r1, 0x20
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x20
	ldrb r0, [r0]
	bl sub_809185C
	b _08019AA4
	.align 2, 0
_08019A8C: .4byte gUnknown_203B210
_08019A90:
	bl sub_801A37C
	ldr r1, [r4]
	adds r1, 0x21
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, 0x21
	ldrb r0, [r0]
	bl sub_8091A90
_08019AA4:
	adds r5, r0, 0
	ldr r4, _08019AD0
	ldr r0, [r4]
	adds r0, 0x1C
	ldrb r1, [r5]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	ldrb r0, [r5, 0x1]
	strb r0, [r1, 0x1D]
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_8090C7C
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x15
	bl UpdateKecleonStoreState
	b _08019B00
	.align 2, 0
_08019AD0: .4byte gUnknown_203B210
_08019AD4:
	ldr r0, _08019AE4
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08019AE8
	bl sub_801A010
	b _08019AEC
	.align 2, 0
_08019AE4: .4byte gUnknown_203B210
_08019AE8:
	bl sub_801A3DC
_08019AEC:
	movs r0, 0x1
	bl UpdateKecleonStoreState
	b _08019B00
_08019AF4:
	movs r0, 0
	bl sub_801AD34
	movs r0, 0x1
	bl sub_8016C40
_08019B00:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80199CC

        .align 2,0
