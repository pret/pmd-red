        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8032828
sub_8032828:
	push {r4-r6,lr}
	sub sp, 0x68
	ldr r1, _08032848
	ldr r0, [r1]
	ldr r0, [r0]
	adds r6, r1, 0
	cmp r0, 0x7D
	bls _0803283C
	bl _080338B4
_0803283C:
	lsls r0, 2
	ldr r1, _0803284C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08032848: .4byte gUnknown_203B33C
_0803284C: .4byte _08032850
	.align 2, 0
_08032850:
	.4byte _08032A48
	.4byte _08032AD0
	.4byte _080338B4
	.4byte _08032B80
	.4byte _08032BC4
	.4byte _08032FD0
	.4byte _080338B4
	.4byte _08032FF0
	.4byte _080338B4
	.4byte _080338B4
	.4byte _08032FD8
	.4byte _08032FE0
	.4byte _08032FE8
	.4byte _0803356C
	.4byte _08032C50
	.4byte _08033200
	.4byte _080331CC
	.4byte _080331D4
	.4byte _080331DC
	.4byte _080336B2
	.4byte _080338B4
	.4byte _080331F8
	.4byte _08033208
	.4byte _080338B4
	.4byte _08033234
	.4byte _0803323C
	.4byte _08033244
	.4byte _080338B4
	.4byte _08032F8C
	.4byte _08032F98
	.4byte _080336B2
	.4byte _080338B4
	.4byte _08032FB6
	.4byte _08032EB8
	.4byte _08032FC4
	.4byte _08032EAC
	.4byte _08032F54
	.4byte _08032EE0
	.4byte _08032EEC
	.4byte _08032F16
	.4byte _080338B4
	.4byte _08032F7C
	.4byte _08032E60
	.4byte _08032E6C
	.4byte _08032EA0
	.4byte _08032E48
	.4byte _0803341C
	.4byte _08032E54
	.4byte _08032D84
	.4byte _08032D90
	.4byte _08032D9C
	.4byte _080336B2
	.4byte _080338B4
	.4byte _08032DBC
	.4byte _080338B4
	.4byte _08032DCC
	.4byte _08032E00
	.4byte _08032E3C
	.4byte _08032E0C
	.4byte _08032E30
	.4byte _08032D04
	.4byte _08032D10
	.4byte _08032D2C
	.4byte _08032D38
	.4byte _08032D44
	.4byte _080338B4
	.4byte _08032D78
	.4byte _08032D20
	.4byte _08033720
	.4byte _08033728
	.4byte _08033684
	.4byte _0803368C
	.4byte _080336B2
	.4byte _080338B4
	.4byte _080336F8
	.4byte _080338B4
	.4byte _08032FD8
	.4byte _08032FE0
	.4byte _08032FE8
	.4byte _080338B4
	.4byte _08033468
	.4byte _08033730
	.4byte _08033738
	.4byte _0803366C
	.4byte _08033674
	.4byte _08033644
	.4byte _0803361C
	.4byte _08033614
	.4byte _080335F4
	.4byte _080335C0
	.4byte _0803324E
	.4byte _0803325C
	.4byte _0803368C
	.4byte _08033264
	.4byte _080338B4
	.4byte _08033288
	.4byte _080332B8
	.4byte _080338B4
	.4byte _0803356C
	.4byte _080335B0
	.4byte _08033584
	.4byte _080338B4
	.4byte _08033412
	.4byte _0803341C
	.4byte _08033448
	.4byte _080335B8
	.4byte _080332F4
	.4byte _080338B4
	.4byte _08033460
	.4byte _08033470
	.4byte _0803349C
	.4byte _08033450
	.4byte _08033458
	.4byte _080338B4
	.4byte _080333E4
	.4byte _080333EC
	.4byte _080338B4
	.4byte _08033604
	.4byte _0803360C
	.4byte _080338B4
	.4byte _0803384C
	.4byte _0803387C
	.4byte _080337D4
	.4byte _080337F0
	.4byte _08033770
	.4byte _0803378C
_08032A48:
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _08032A9C
	movs r0, 0x5
	bl sub_8095324
	adds r4, r0, 0
	cmp r4, 0
	bne _08032A9C
	ldr r0, _08032A7C
	ldr r0, [r0]
	ldr r1, _08032A80
	adds r0, r1
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032A8C
	ldr r0, _08032A84
	ldr r3, _08032A88
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032B66
	.align 2, 0
_08032A7C: .4byte gUnknown_203B33C
_08032A80: .4byte 0x0000052c
_08032A84: .4byte gUnknown_80E25F4
_08032A88: .4byte gUnknown_80E2108
_08032A8C:
	ldr r0, _08032A94
	ldr r3, _08032A98
	b _08032B5C
	.align 2, 0
_08032A94: .4byte gUnknown_80E25F4
_08032A98: .4byte gUnknown_80E20B8
_08032A9C:
	ldr r0, _08032AC0
	ldr r0, [r0]
	ldr r2, _08032AC4
	adds r0, r2
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032B58
	ldr r0, _08032AC8
	ldr r3, _08032ACC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	bl _08033864
	.align 2, 0
_08032AC0: .4byte gUnknown_203B33C
_08032AC4: .4byte 0x0000052c
_08032AC8: .4byte gUnknown_80E25F4
_08032ACC: .4byte gUnknown_80E20E0
_08032AD0:
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _08032B24
	movs r0, 0x5
	bl sub_8095324
	adds r4, r0, 0
	cmp r4, 0
	bne _08032B24
	ldr r0, _08032B04
	ldr r0, [r0]
	ldr r3, _08032B08
	adds r0, r3
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032B14
	ldr r0, _08032B0C
	ldr r3, _08032B10
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032B66
	.align 2, 0
_08032B04: .4byte gUnknown_203B33C
_08032B08: .4byte 0x0000052c
_08032B0C: .4byte gUnknown_80E25F4
_08032B10: .4byte gUnknown_80E2108
_08032B14:
	ldr r0, _08032B1C
	ldr r3, _08032B20
	b _08032B5C
	.align 2, 0
_08032B1C: .4byte gUnknown_80E25F4
_08032B20: .4byte gUnknown_80E20B8
_08032B24:
	ldr r0, _08032B48
	ldr r0, [r0]
	ldr r4, _08032B4C
	adds r0, r4
	ldrb r2, [r0]
	cmp r2, 0
	beq _08032B58
	ldr r0, _08032B50
	ldr r3, _08032B54
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	bl _08033864
	.align 2, 0
_08032B48: .4byte gUnknown_203B33C
_08032B4C: .4byte 0x0000052c
_08032B50: .4byte gUnknown_80E25F4
_08032B54: .4byte gUnknown_80E20E0
_08032B58:
	ldr r0, _08032B78
	ldr r3, _08032B7C
_08032B5C:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
_08032B66:
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032B78: .4byte gUnknown_80E25F4
_08032B7C: .4byte gUnknown_80E2068
_08032B80:
	movs r0, 0x4
	bl sub_8095324
	adds r2, r0, 0
	cmp r2, 0
	beq _08032B9C
	ldr r0, _08032B94
	ldr r3, _08032B98
	movs r2, 0
	b _08032BA0
	.align 2, 0
_08032B94: .4byte gUnknown_80E25F4
_08032B98: .4byte gUnknown_80E2130
_08032B9C:
	ldr r0, _08032BBC
	ldr r3, _08032BC0
_08032BA0:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032BBC: .4byte gUnknown_80E25F4
_08032BC0: .4byte gUnknown_80E2190
_08032BC4:
	movs r0, 0x1
	bl sub_8095324
	adds r4, r0, 0
	cmp r4, 0
	bne _08032C0C
	movs r0, 0x5
	bl sub_8095324
	cmp r0, 0
	bne _08032BF4
	ldr r0, _08032BEC
	ldr r3, _08032BF0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032C38
	.align 2, 0
_08032BEC: .4byte gUnknown_80E25F4
_08032BF0: .4byte gUnknown_80E2268
_08032BF4:
	ldr r0, _08032C04
	ldr r3, _08032C08
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	b _08032C38
	.align 2, 0
_08032C04: .4byte gUnknown_80E25F4
_08032C08: .4byte gUnknown_80E2218
_08032C0C:
	movs r0, 0x5
	bl sub_8095324
	adds r2, r0, 0
	cmp r2, 0
	bne _08032C28
	ldr r0, _08032C20
	ldr r3, _08032C24
	b _08032C2E
	.align 2, 0
_08032C20: .4byte gUnknown_80E25F4
_08032C24: .4byte gUnknown_80E2240
_08032C28:
	ldr r0, _08032C48
	ldr r3, _08032C4C
	movs r2, 0
_08032C2E:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
_08032C38:
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x11
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032C48: .4byte gUnknown_80E25F4
_08032C4C: .4byte gUnknown_80E21B8
_08032C50:
	ldr r0, [r6]
	movs r5, 0xA5
	lsls r5, 3
	adds r0, r5
	ldr r0, [r0]
	subs r0, 0x3
	cmp r0, 0x11
	bls _08032C64
	bl _080338B4
_08032C64:
	lsls r0, 2
	ldr r1, _08032C70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08032C70: .4byte _08032C74
	.align 2, 0
_08032C74:
	.4byte _08032CC8
	.4byte _08032CD4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _080338B4
	.4byte _08032CBC
	.4byte _08032CE0
	.4byte _08032CEC
	.4byte _08032CF8
_08032CBC:
	ldr r0, _08032CC4
	bl _0803374A
	.align 2, 0
_08032CC4: .4byte gUnknown_80E2610
_08032CC8:
	ldr r0, _08032CD0
	bl _0803374A
	.align 2, 0
_08032CD0: .4byte gUnknown_80E2640
_08032CD4:
	ldr r0, _08032CDC
	bl _0803374A
	.align 2, 0
_08032CDC: .4byte gUnknown_80E2680
_08032CE0:
	ldr r0, _08032CE8
	bl _0803374A
	.align 2, 0
_08032CE8: .4byte gUnknown_80E26B0
_08032CEC:
	ldr r0, _08032CF4
	bl _0803374A
	.align 2, 0
_08032CF4: .4byte gUnknown_80E26F0
_08032CF8:
	ldr r0, _08032D00
	bl _0803374A
	.align 2, 0
_08032D00: .4byte gUnknown_80E2728
_08032D04:
	ldr r0, _08032D0C
	bl _0803388E
	.align 2, 0
_08032D0C: .4byte gUnknown_80E276C
_08032D10:
	ldr r0, _08032D18
	ldr r3, _08032D1C
	bl _080336FC
	.align 2, 0
_08032D18: .4byte gUnknown_80E27A4
_08032D1C: .4byte gUnknown_80E2458
_08032D20:
	ldr r0, _08032D28
	bl _0803388E
	.align 2, 0
_08032D28: .4byte gUnknown_80E2814
_08032D2C:
	ldr r0, _08032D34
	bl _0803388E
	.align 2, 0
_08032D34: .4byte gUnknown_80E2840
_08032D38:
	ldr r0, _08032D40
	bl _0803388E
	.align 2, 0
_08032D40: .4byte gUnknown_80E2874
_08032D44:
	ldr r0, [r6]
	ldr r1, _08032D60
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08032D54
	bl _080338B4
_08032D54:
	cmp r0, 0xC
	bhi _08032D64
	cmp r0, 0xB
	beq _08032D6C
	bl _080338B4
	.align 2, 0
_08032D60: .4byte 0x00000524
_08032D64:
	cmp r0, 0xE
	bls _08032D6C
	bl _080338B4
_08032D6C:
	ldr r0, _08032D74
	bl _0803388E
	.align 2, 0
_08032D74: .4byte gUnknown_80E2898
_08032D78:
	ldr r0, _08032D80
	bl _0803388E
	.align 2, 0
_08032D80: .4byte gUnknown_80E28D8
_08032D84:
	ldr r0, _08032D8C
	bl _0803388E
	.align 2, 0
_08032D8C: .4byte gUnknown_80E2904
_08032D90:
	ldr r0, _08032D98
	bl _0803388E
	.align 2, 0
_08032D98: .4byte gUnknown_80E296C
_08032D9C:
	bl sub_8030894
	cmp r0, 0
	beq _08032DA8
	bl _080338B4
_08032DA8:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl _080336A6
_08032DBC:
	ldr r0, _08032DC4
	ldr r3, _08032DC8
	bl _080336FC
	.align 2, 0
_08032DC4: .4byte gUnknown_80E29A0
_08032DC8: .4byte gUnknown_80E22B4
_08032DCC:
	ldr r0, [r6]
	ldr r2, _08032DE8
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08032DDC
	bl _080338B4
_08032DDC:
	cmp r0, 0xC
	bhi _08032DEC
	cmp r0, 0xB
	beq _08032DF4
	bl _080338B4
	.align 2, 0
_08032DE8: .4byte 0x00000524
_08032DEC:
	cmp r0, 0xE
	bls _08032DF4
	bl _080338B4
_08032DF4:
	ldr r0, _08032DFC
	bl _0803388E
	.align 2, 0
_08032DFC: .4byte gUnknown_80E29D0
_08032E00:
	ldr r0, _08032E08
	bl _0803388E
	.align 2, 0
_08032E08: .4byte gUnknown_80E2A0C
_08032E0C:
	ldr r0, [r6]
	movs r3, 0xEF
	lsls r3, 2
	adds r0, r3
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	movs r4, 0x86
	lsls r4, 2
	adds r0, r4
	b _0803343E
_08032E30:
	ldr r0, _08032E38
	bl _0803388E
	.align 2, 0
_08032E38: .4byte gUnknown_80E2A1C
_08032E3C:
	ldr r0, _08032E44
	bl _0803388E
	.align 2, 0
_08032E44: .4byte gUnknown_80E2A5C
_08032E48:
	ldr r0, _08032E50
	bl _0803388E
	.align 2, 0
_08032E50: .4byte gUnknown_80E2A80
_08032E54:
	ldr r0, _08032E5C
	bl _0803388E
	.align 2, 0
_08032E5C: .4byte gUnknown_80E2AA8
_08032E60:
	ldr r0, _08032E68
	bl _0803388E
	.align 2, 0
_08032E68: .4byte gUnknown_80E2AE4
_08032E6C:
	ldr r0, [r6]
	ldr r2, _08032E88
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08032E7C
	bl _080338B4
_08032E7C:
	cmp r0, 0xC
	bhi _08032E8C
	cmp r0, 0xB
	beq _08032E94
	bl _080338B4
	.align 2, 0
_08032E88: .4byte 0x00000524
_08032E8C:
	cmp r0, 0xE
	bls _08032E94
	bl _080338B4
_08032E94:
	ldr r0, _08032E9C
	bl _0803388E
	.align 2, 0
_08032E9C: .4byte gUnknown_80E2B54
_08032EA0:
	ldr r0, _08032EA8
	bl _0803388E
	.align 2, 0
_08032EA8: .4byte gUnknown_80E2A0C
_08032EAC:
	ldr r0, _08032EB4
	bl _0803388E
	.align 2, 0
_08032EB4: .4byte gUnknown_80E2B90
_08032EB8:
	ldr r0, _08032ED8
	ldr r3, _08032EDC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xF
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032ED8: .4byte gUnknown_80E2BE0
_08032EDC: .4byte gUnknown_80E23A8
_08032EE0:
	ldr r0, _08032EE8
	bl _0803388E
	.align 2, 0
_08032EE8: .4byte gUnknown_80E2C48
_08032EEC:
	bl sub_8023CE8
	cmp r0, 0
	beq _08032EF8
	bl sub_8023C60
_08032EF8:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0x9
	bl sub_8023868
	bl _080338B4
_08032F16:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _08032F4C
	ldr r2, _08032F50
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_8023DA4
	bl _080336E2
	.align 2, 0
_08032F4C: .4byte gUnknown_80E2334
_08032F50: .4byte gUnknown_80E234C
_08032F54:
	ldr r0, _08032F74
	ldr r3, _08032F78
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x10
	bl sub_8014248
	bl _080338B4
	.align 2, 0
_08032F74: .4byte gUnknown_80E2C94
_08032F78: .4byte gUnknown_80E22F0
_08032F7C:
	ldr r0, _08032F84
	ldr r3, _08032F88
	bl _080336FC
	.align 2, 0
_08032F84: .4byte gUnknown_80E2CD4
_08032F88: .4byte gUnknown_80E22D0
_08032F8C:
	ldr r0, _08032F94
	bl _0803388E
	.align 2, 0
_08032F94: .4byte gUnknown_80E2CE8
_08032F98:
	bl sub_8030894
	cmp r0, 0
	beq _08032FA4
	bl _080338B4
_08032FA4:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x4
	b _080336A6
_08032FB6:
	ldr r0, _08032FBC
	ldr r3, _08032FC0
	b _080336FC
	.align 2, 0
_08032FBC: .4byte gUnknown_80E2D30
_08032FC0: .4byte gUnknown_80E22B4
_08032FC4:
	ldr r0, _08032FCC
	bl _0803388E
	.align 2, 0
_08032FCC: .4byte gUnknown_80E2D60
_08032FD0:
	ldr r0, _08032FD4
	b _080336FA
	.align 2, 0
_08032FD4: .4byte gUnknown_80E2D7C
_08032FD8:
	ldr r0, _08032FDC
	b _080336FA
	.align 2, 0
_08032FDC: .4byte gUnknown_80E2E20
_08032FE0:
	ldr r0, _08032FE4
	b _08033574
	.align 2, 0
_08032FE4: .4byte gUnknown_80E2E54
_08032FE8:
	ldr r0, _08032FEC
	b _08033574
	.align 2, 0
_08032FEC: .4byte gUnknown_80E2EB4
_08032FF0:
	ldr r1, [r6]
	movs r0, 0
	str r0, [r1, 0x44]
	bl sub_8011830
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	bl sub_8037B28
	adds r4, r0, 0
	ldr r0, [r6]
	str r4, [r0, 0x44]
	cmp r4, 0
	beq _0803300E
	b _080333DE
_0803300E:
	ldr r1, [r0, 0x40]
	cmp r1, 0x3
	beq _08033028
	cmp r1, 0x3
	bhi _0803301E
	cmp r1, 0x2
	beq _0803304A
	b _0803313C
_0803301E:
	cmp r1, 0x4
	beq _080330B4
	cmp r1, 0x5
	beq _0803308E
	b _0803313C
_08033028:
	adds r0, 0x48
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	adds r0, 0x78
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	b _08033134
_0803304A:
	adds r0, 0x48
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	adds r0, 0x78
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 2
	adds r0, r3
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, 0x48
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	b _08033134
_0803308E:
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r0, [r6]
	movs r4, 0x98
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0xA8
	adds r2, r4
	b _08033134
_080330B4:
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0x98
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xE0
	strh r4, [r0]
	movs r2, 0xB4
	lsls r2, 1
	adds r0, r1, r2
	strh r4, [r0]
	movs r3, 0x86
	lsls r3, 2
	adds r0, r1, r3
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, 0xA8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	movs r4, 0xA7
	lsls r4, 3
	adds r3, r2, r4
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0803312A
	adds r0, r2, 0
	adds r0, 0xD8
	ldr r1, _08033188
	ldr r1, [r1]
	movs r2, 0
	ldrsh r3, [r3, r2]
	movs r2, 0x58
	muls r2, r3
	adds r1, r2
	movs r2, 0x58
	bl memcpy
_0803312A:
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0xA8
	adds r2, r5
_08033134:
	bl sub_8037D64
	ldr r1, [r6]
	str r0, [r1, 0x44]
_0803313C:
	ldr r4, _0803318C
	ldr r2, [r4]
	ldr r0, [r2, 0x44]
	cmp r0, 0
	beq _08033148
	b _080333DE
_08033148:
	ldr r0, [r2, 0x40]
	cmp r0, 0x2
	bcs _08033150
	b _080333DE
_08033150:
	cmp r0, 0x3
	bls _08033190
	cmp r0, 0x5
	bls _0803315A
	b _080333DE
_0803315A:
	adds r1, r2, 0
	adds r1, 0xA8
	movs r3, 0x98
	lsls r3, 1
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _080331C0
	ldr r0, [r4]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r0, r4
	movs r5, 0xA0
	lsls r5, 1
	adds r0, r5
	b _080333DA
	.align 2, 0
_08033188: .4byte gRecruitedPokemonRef
_0803318C: .4byte gUnknown_203B33C
_08033190:
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _080331B4
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r0, r2
	adds r0, 0x88
	b _080333DA
_080331B4:
	ldr r0, [r4]
	movs r3, 0x84
	lsls r3, 3
	adds r1, r0, r3
	ldr r0, [r0, 0x58]
	b _080333DC
_080331C0:
	ldr r0, [r4]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r0, r4
	adds r0, 0xB8
	b _080333DA
_080331CC:
	ldr r0, _080331D0
	b _0803388E
	.align 2, 0
_080331D0: .4byte gUnknown_80E2F14
_080331D4:
	ldr r0, _080331D8
	b _0803388E
	.align 2, 0
_080331D8: .4byte gUnknown_80E2F44
_080331DC:
	bl sub_8030894
	cmp r0, 0
	beq _080331E6
	b _080338B4
_080331E6:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	b _080336A6
_080331F8:
	ldr r0, _080331FC
	b _080336FA
	.align 2, 0
_080331FC: .4byte gUnknown_80E2F78
_08033200:
	ldr r0, _08033204
	b _0803388E
	.align 2, 0
_08033204: .4byte gUnknown_80E2FA0
_08033208:
	ldr r0, [r6]
	ldr r5, _08033220
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08033216
	b _080338B4
_08033216:
	cmp r0, 0xC
	bhi _08033224
	cmp r0, 0xB
	beq _0803322A
	b _080338B4
	.align 2, 0
_08033220: .4byte 0x00000524
_08033224:
	cmp r0, 0xE
	bls _0803322A
	b _080338B4
_0803322A:
	ldr r0, _08033230
	b _0803388E
	.align 2, 0
_08033230: .4byte gUnknown_80E2FEC
_08033234:
	ldr r0, _08033238
	b _0803388E
	.align 2, 0
_08033238: .4byte gUnknown_80E3030
_0803323C:
	ldr r0, _08033240
	b _0803388E
	.align 2, 0
_08033240: .4byte gUnknown_80E3078
_08033244:
	ldr r0, [r6]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	b _080333F4
_0803324E:
	ldr r0, _08033254
	ldr r3, _08033258
	b _080336FC
	.align 2, 0
_08033254: .4byte gUnknown_80E30A4
_08033258: .4byte gUnknown_80E2458
_0803325C:
	ldr r0, _08033260
	b _0803388E
	.align 2, 0
_08033260: .4byte gUnknown_80E30D0
_08033264:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _08033280
	ldr r2, _08033284
	b _080336CC
	.align 2, 0
_08033280: .4byte gUnknown_80E231C
_08033284: .4byte gUnknown_80E2408
_08033288:
	bl sub_801D008
	cmp r0, 0
	beq _08033292
	b _080338B4
_08033292:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _080332B4
	str r0, [sp, 0x64]
	add r2, sp, 0x64
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x9
	bl sub_801C8C4
	b _080338B4
	.align 2, 0
_080332B4: .4byte 0x00020003
_080332B8:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _080332EC
	ldr r2, _080332F0
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_801CCD8
	b _080336E2
	.align 2, 0
_080332EC: .4byte gUnknown_80E23F0
_080332F0: .4byte gUnknown_80E2408
_080332F4:
	ldr r1, [r6]
	movs r0, 0
	str r0, [r1, 0x44]
	bl sub_8011830
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	bl sub_8037B28
	ldr r1, [r6]
	str r0, [r1, 0x44]
	cmp r0, 0
	bne _080333DE
	ldr r0, [r1, 0x40]
	cmp r0, 0x6
	beq _0803331A
	cmp r0, 0x7
	beq _08033358
	b _08033388
_0803331A:
	movs r4, 0xDC
	lsls r4, 1
	adds r0, r1, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, r4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r4, r2, r4
	movs r3, 0xF4
	lsls r3, 1
	adds r2, r3
	b _0803337E
_08033358:
	movs r4, 0xDC
	lsls r4, 1
	adds r0, r1, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0xF4
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r4, r2, r4
	adds r2, r5
_0803337E:
	adds r1, r4, 0
	bl sub_8037D64
	ldr r1, [r6]
	str r0, [r1, 0x44]
_08033388:
	ldr r4, _080333C8
	ldr r2, [r4]
	ldr r0, [r2, 0x44]
	cmp r0, 0
	bne _080333DE
	ldr r0, [r2, 0x40]
	cmp r0, 0x7
	bhi _080333DE
	cmp r0, 0x6
	bcc _080333DE
	movs r5, 0xDC
	lsls r5, 1
	adds r1, r2, r5
	movs r3, 0xF4
	lsls r3, 1
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _080333CC
	ldr r0, [r4]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r0, r4
	adds r5, 0x40
	adds r0, r5
	b _080333DA
	.align 2, 0
_080333C8: .4byte gUnknown_203B33C
_080333CC:
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r0, r2
	movs r3, 0xE4
	lsls r3, 1
	adds r0, r3
_080333DA:
	ldr r0, [r0]
_080333DC:
	str r0, [r1]
_080333DE:
	bl xxx_call_start_bg_music
	b _080338B4
_080333E4:
	ldr r0, _080333E8
	b _0803388E
	.align 2, 0
_080333E8: .4byte gUnknown_80E311C
_080333EC:
	ldr r0, [r6]
	movs r4, 0xEF
	lsls r4, 2
	adds r0, r4
_080333F4:
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r1, 0x8
	movs r0, 0x4
	bl sub_80151C0
	b _080338B4
_08033412:
	ldr r0, _08033418
	b _0803388E
	.align 2, 0
_08033418: .4byte gUnknown_80E314C
_0803341C:
	ldr r0, [r6]
	movs r5, 0xEF
	lsls r5, 2
	adds r0, r5
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
_0803343E:
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8031D70
	b _080338B4
_08033448:
	ldr r0, _0803344C
	b _0803388E
	.align 2, 0
_0803344C: .4byte gUnknown_80E317C
_08033450:
	ldr r0, _08033454
	b _0803388E
	.align 2, 0
_08033454: .4byte gUnknown_80E319C
_08033458:
	ldr r0, _0803345C
	b _0803388E
	.align 2, 0
_0803345C: .4byte gUnknown_80E317C
_08033460:
	ldr r0, _08033464
	b _0803388E
	.align 2, 0
_08033464: .4byte gUnknown_80E31D8
_08033468:
	ldr r0, _0803346C
	b _0803388E
	.align 2, 0
_0803346C: .4byte gUnknown_80E31FC
_08033470:
	ldr r0, [r6]
	ldr r2, _08033488
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xC
	bne _0803347E
	b _080338B4
_0803347E:
	cmp r0, 0xC
	bhi _0803348C
	cmp r0, 0xB
	beq _08033492
	b _080338B4
	.align 2, 0
_08033488: .4byte 0x00000524
_0803348C:
	cmp r0, 0xE
	bls _08033492
	b _080338B4
_08033492:
	ldr r0, _08033498
	b _0803388E
	.align 2, 0
_08033498: .4byte gUnknown_80E3220
_0803349C:
	movs r0, 0x98
	lsls r0, 1
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r4, _080334F8
	ldr r0, [r4]
	ldr r3, _080334FC
	adds r0, r3
	bl strcpy
	ldr r1, [r4]
	movs r5, 0xAA
	lsls r5, 3
	adds r0, r1, r5
	movs r2, 0
	strh r2, [r0]
	ldr r0, _08033500
	adds r1, r0
	movs r0, 0x2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _08033504
	adds r1, r0, r3
	str r2, [r1]
	movs r5, 0x84
	lsls r5, 3
	adds r0, r5
	ldr r1, [r0]
	movs r0, 0x6
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	adds r0, 0x22
	ldrb r1, [r0]
	cmp r1, 0
	beq _08033508
	ldr r0, [r4]
	movs r3, 0xAB
	lsls r3, 3
	adds r0, r3
	b _08033512
	.align 2, 0
_080334F8: .4byte gUnknown_203B33C
_080334FC: .4byte 0x0000053c
_08033500: .4byte 0x00000552
_08033504: .4byte 0x00000554
_08033508:
	ldr r0, [r4]
	movs r4, 0xAB
	lsls r4, 3
	adds r0, r4
	movs r1, 0
_08033512:
	strb r1, [r0]
	ldr r4, _08033558
	ldr r0, [r4]
	ldr r5, _0803355C
	adds r0, r5
	movs r5, 0
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r2, 0x4
	movs r1, 0
	bl sub_803C200
	ldr r1, [r4]
	movs r3, 0xAC
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	ldr r0, _08033560
	adds r1, r0
	strb r5, [r1]
	ldr r0, [r4]
	ldr r1, _08033564
	adds r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _08033568
	adds r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	subs r3, 0x24
	adds r0, r3
	movs r1, 0
	bl sub_802F204
	b _080338B4
	.align 2, 0
_08033558: .4byte gUnknown_203B33C
_0803355C: .4byte 0x0000055b
_08033560: .4byte 0x00000559
_08033564: .4byte 0x0000055a
_08033568: .4byte 0x0000055c
_0803356C:
	movs r0, 0
	bl nullsub_23
	ldr r0, _08033580
_08033574:
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _080338B4
	.align 2, 0
_08033580: .4byte gUnknown_80E2DD0
_08033584:
	ldr r0, [r6]
	ldr r4, _0803359C
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0xC
	bne _08033592
	b _080338B4
_08033592:
	cmp r0, 0xC
	bhi _080335A0
	cmp r0, 0xB
	beq _080335A6
	b _080338B4
	.align 2, 0
_0803359C: .4byte 0x00000524
_080335A0:
	cmp r0, 0xE
	bls _080335A6
	b _080338B4
_080335A6:
	ldr r0, _080335AC
	b _0803388E
	.align 2, 0
_080335AC: .4byte gUnknown_80E3248
_080335B0:
	ldr r0, _080335B4
	b _0803388E
	.align 2, 0
_080335B4: .4byte gUnknown_80E3288
_080335B8:
	ldr r0, _080335BC
	b _080336FA
	.align 2, 0
_080335BC: .4byte gUnknown_80E2D7C
_080335C0:
	bl sub_808D33C
	adds r1, r0, 0
	adds r1, 0x4C
	add r0, sp, 0x14
	movs r2, 0xA
	bl sub_80922B4
	ldr r5, _080335E8
	ldr r0, [r5]
	ldr r4, _080335EC
	adds r0, r4
	ldr r1, _080335F0
	add r2, sp, 0x14
	bl ExpandPlaceholdersBuffer
	ldr r0, [r5]
	adds r0, r4
	b _0803388E
	.align 2, 0
_080335E8: .4byte gUnknown_203B33C
_080335EC: .4byte 0x00000424
_080335F0: .4byte gUnknown_80E32C4
_080335F4:
	ldr r0, _080335FC
	ldr r3, _08033600
	b _080336FC
	.align 2, 0
_080335FC: .4byte gUnknown_80E331C
_08033600: .4byte gUnknown_80E24D8
_08033604:
	ldr r0, _08033608
	b _0803388E
	.align 2, 0
_08033608: .4byte gUnknown_80E317C
_0803360C:
	ldr r0, _08033610
	b _0803388E
	.align 2, 0
_08033610: .4byte gUnknown_80E2A0C
_08033614:
	ldr r0, _08033618
	b _0803388E
	.align 2, 0
_08033618: .4byte gUnknown_80E3378
_0803361C:
	ldr r0, _0803363C
	ldr r3, _08033640
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x16
	bl sub_8014248
	b _080338B4
	.align 2, 0
_0803363C: .4byte gUnknown_80E339C
_08033640: .4byte gUnknown_80E24B0
_08033644:
	ldr r0, _08033664
	ldr r3, _08033668
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x15
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033664: .4byte gUnknown_80E33D8
_08033668: .4byte gUnknown_80E2470
_0803366C:
	ldr r0, _08033670
	b _0803388E
	.align 2, 0
_08033670: .4byte gUnknown_80E3430
_08033674:
	ldr r0, _0803367C
	ldr r3, _08033680
	b _080336FC
	.align 2, 0
_0803367C: .4byte gUnknown_80E34B0
_08033680: .4byte gUnknown_80E2440
_08033684:
	ldr r0, _08033688
	b _0803388E
	.align 2, 0
_08033688: .4byte gUnknown_80E34F0
_0803368C:
	bl sub_8030894
	cmp r0, 0
	beq _08033696
	b _080338B4
_08033696:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x5
_080336A6:
	movs r1, 0
	movs r2, 0
	movs r3, 0x6
	bl sub_80306A8
	b _080338B4
_080336B2:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _080336F0
	ldr r2, _080336F4
_080336CC:
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_803092C
_080336E2:
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	b _080338B4
	.align 2, 0
_080336F0: .4byte gUnknown_80E231C
_080336F4: .4byte gUnknown_80E234C
_080336F8:
	ldr r0, _08033718
_080336FA:
	ldr r3, _0803371C
_080336FC:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033718: .4byte gUnknown_80E352C
_0803371C: .4byte gUnknown_80E2290
_08033720:
	ldr r0, _08033724
	b _0803388E
	.align 2, 0
_08033724: .4byte gUnknown_80E355C
_08033728:
	ldr r0, _0803372C
	b _0803388E
	.align 2, 0
_0803372C: .4byte gUnknown_80E35AC
_08033730:
	ldr r0, _08033734
	b _0803388E
	.align 2, 0
_08033734: .4byte gUnknown_80E35E8
_08033738:
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	cmp r0, 0x6
	bne _08033748
	ldr r0, _08033744
	b _0803374A
	.align 2, 0
_08033744: .4byte gUnknown_80E360C
_08033748:
	ldr r0, _08033768
_0803374A:
	ldr r3, _0803376C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xB
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033768: .4byte gUnknown_80E3644
_0803376C: .4byte gUnknown_80E236C
_08033770:
	ldr r0, _08033780
	ldr r1, [r6]
	ldr r5, _08033784
	adds r1, r5
	ldr r2, [r1]
	ldr r3, _08033788
	b _08033858
	.align 2, 0
_08033780: .4byte gUnknown_80E367C
_08033784: .4byte 0x00000564
_08033788: .4byte gUnknown_80E25B4
_0803378C:
	ldr r0, [r6]
	ldr r1, _080337A4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x24
	beq _080337BC
	cmp r0, 0x24
	bgt _080337A8
	cmp r0, 0x23
	beq _080337B2
	b _080338B4
	.align 2, 0
_080337A4: .4byte 0x00000564
_080337A8:
	cmp r0, 0x25
	beq _080337C4
	cmp r0, 0x26
	beq _080337CC
	b _080338B4
_080337B2:
	ldr r0, _080337B8
	b _0803388E
	.align 2, 0
_080337B8: .4byte gUnknown_80E3690
_080337BC:
	ldr r0, _080337C0
	b _0803388E
	.align 2, 0
_080337C0: .4byte gUnknown_80E3818
_080337C4:
	ldr r0, _080337C8
	b _0803388E
	.align 2, 0
_080337C8: .4byte gUnknown_80E3998
_080337CC:
	ldr r0, _080337D0
	b _0803388E
	.align 2, 0
_080337D0: .4byte gUnknown_80E3B1C
_080337D4:
	ldr r0, _080337E4
	ldr r1, [r6]
	ldr r2, _080337E8
	adds r1, r2
	ldr r2, [r1]
	ldr r3, _080337EC
	b _08033858
	.align 2, 0
_080337E4: .4byte gUnknown_80E367C
_080337E8: .4byte 0x00000564
_080337EC: .4byte gUnknown_80E2554
_080337F0:
	ldr r0, [r6]
	ldr r3, _08033808
	adds r0, r3
	ldr r0, [r0]
	subs r0, 0x1E
	cmp r0, 0x4
	bhi _080338B4
	lsls r0, 2
	ldr r1, _0803380C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033808: .4byte 0x00000564
_0803380C: .4byte _08033810
	.align 2, 0
_08033810:
	.4byte _08033824
	.4byte _0803382C
	.4byte _0803383C
	.4byte _08033834
	.4byte _08033844
_08033824:
	ldr r0, _08033828
	b _0803388E
	.align 2, 0
_08033828: .4byte gUnknown_80E3BF8
_0803382C:
	ldr r0, _08033830
	b _0803388E
	.align 2, 0
_08033830: .4byte gUnknown_80E3DE4
_08033834:
	ldr r0, _08033838
	b _0803388E
	.align 2, 0
_08033838: .4byte gUnknown_80E3E98
_0803383C:
	ldr r0, _08033840
	b _0803388E
	.align 2, 0
_08033840: .4byte gUnknown_80E4014
_08033844:
	ldr r0, _08033848
	b _0803388E
	.align 2, 0
_08033848: .4byte gUnknown_80E4130
_0803384C:
	ldr r0, _08033870
	ldr r1, [r6]
	ldr r4, _08033874
	adds r1, r4
	ldr r2, [r1]
	ldr r3, _08033878
_08033858:
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
_08033864:
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080338B4
	.align 2, 0
_08033870: .4byte gUnknown_80E367C
_08033874: .4byte 0x00000564
_08033878: .4byte gUnknown_80E24F8
_0803387C:
	ldr r0, [r6]
	ldr r5, _0803389C
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0x1A
	beq _080338A8
	cmp r0, 0x1D
	bne _080338B4
	ldr r0, _080338A0
_0803388E:
	ldr r3, _080338A4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080338B4
	.align 2, 0
_0803389C: .4byte 0x00000564
_080338A0: .4byte gUnknown_80E41DC
_080338A4: .4byte 0x00000101
_080338A8:
	ldr r0, _080338BC
	ldr r3, _080338C0
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080338B4:
	add sp, 0x68
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080338BC: .4byte gUnknown_80E4314
_080338C0: .4byte 0x00000101
	thumb_func_end sub_8032828

	thumb_func_start sub_80338C4
sub_80338C4:
	push {lr}
	ldr r1, _080338D8
	ldr r1, [r1]
	str r0, [r1]
	bl nullsub_40
	bl sub_8032828
	pop {r0}
	bx r0
	.align 2, 0
_080338D8: .4byte gUnknown_203B33C
	thumb_func_end sub_80338C4

	thumb_func_start sub_80338DC
sub_80338DC:
	push {lr}
	cmp r0, 0x10
	bls _080338E4
	b _080339BC
_080338E4:
	lsls r0, 2
	ldr r1, _080338F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080338F0: .4byte _080338F4
	.align 2, 0
_080338F4:
	.4byte _080339BC
	.4byte _08033998
	.4byte _08033940
	.4byte _08033938
	.4byte _08033948
	.4byte _08033998
	.4byte _08033950
	.4byte _08033958
	.4byte _08033960
	.4byte _08033968
	.4byte _08033970
	.4byte _08033978
	.4byte _08033980
	.4byte _08033990
	.4byte _08033998
	.4byte _080339B0
	.4byte _08033988
_08033938:
	ldr r0, _0803393C
	b _0803399A
	.align 2, 0
_0803393C: .4byte gUnknown_80E44A4
_08033940:
	ldr r0, _08033944
	b _0803399A
	.align 2, 0
_08033944: .4byte gUnknown_80E4500
_08033948:
	ldr r0, _0803394C
	b _0803399A
	.align 2, 0
_0803394C: .4byte gUnknown_80E4550
_08033950:
	ldr r0, _08033954
	b _0803399A
	.align 2, 0
_08033954: .4byte gUnknown_80E45B4
_08033958:
	ldr r0, _0803395C
	b _0803399A
	.align 2, 0
_0803395C: .4byte gUnknown_80E460C
_08033960:
	ldr r0, _08033964
	b _0803399A
	.align 2, 0
_08033964: .4byte gUnknown_80E4650
_08033968:
	ldr r0, _0803396C
	b _0803399A
	.align 2, 0
_0803396C: .4byte gUnknown_80E468C
_08033970:
	ldr r0, _08033974
	b _0803399A
	.align 2, 0
_08033974: .4byte gUnknown_80E46C8
_08033978:
	ldr r0, _0803397C
	b _0803399A
	.align 2, 0
_0803397C: .4byte gUnknown_80E4704
_08033980:
	ldr r0, _08033984
	b _0803399A
	.align 2, 0
_08033984: .4byte gUnknown_80E4744
_08033988:
	ldr r0, _0803398C
	b _0803399A
	.align 2, 0
_0803398C: .4byte gUnknown_80E4788
_08033990:
	ldr r0, _08033994
	b _0803399A
	.align 2, 0
_08033994: .4byte gUnknown_80E47D8
_08033998:
	ldr r0, _080339A8
_0803399A:
	ldr r3, _080339AC
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080339BC
	.align 2, 0
_080339A8: .4byte gUnknown_80E4480
_080339AC: .4byte 0x00000101
_080339B0:
	ldr r0, _080339C0
	ldr r3, _080339C4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080339BC:
	pop {r0}
	bx r0
	.align 2, 0
_080339C0: .4byte gUnknown_80E482C
_080339C4: .4byte 0x00000101
	thumb_func_end sub_80338DC

	thumb_func_start sub_80339C8
sub_80339C8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033A24
	ldr r0, _080339F4
	ldr r0, [r0]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	ldr r1, _080339F8
	strh r1, [r0]
	ldr r0, [sp]
	cmp r0, 0x1
	beq _08033A0E
	cmp r0, 0x1
	bgt _080339FC
	cmp r0, 0
	beq _08033A06
	b _08033A24
	.align 2, 0
_080339F4: .4byte gUnknown_203B33C
_080339F8: .4byte 0x0000ffff
_080339FC:
	cmp r0, 0x8
	beq _08033A1E
	cmp r0, 0x17
	beq _08033A16
	b _08033A24
_08033A06:
	movs r0, 0x3
	bl sub_80338C4
	b _08033A24
_08033A0E:
	movs r0, 0x4
	bl sub_80338C4
	b _08033A24
_08033A16:
	movs r0, 0x78
	bl sub_80338C4
	b _08033A24
_08033A1E:
	movs r0, 0x2
	bl sub_80338C4
_08033A24:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80339C8

	thumb_func_start sub_8033A2C
sub_8033A2C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	beq _08033A3C
	b _08033B86
_08033A3C:
	ldr r2, _08033A58
	ldr r1, [r2]
	movs r0, 0x8
	str r0, [r1, 0x40]
	ldr r0, [sp]
	subs r0, 0x3
	cmp r0, 0x11
	bls _08033A4E
	b _08033B86
_08033A4E:
	lsls r0, 2
	ldr r1, _08033A5C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033A58: .4byte gUnknown_203B33C
_08033A5C: .4byte _08033A60
	.align 2, 0
_08033A60:
	.4byte _08033ACA
	.4byte _08033AEC
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B80
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033B86
	.4byte _08033AA8
	.4byte _08033B14
	.4byte _08033B3E
	.4byte _08033B68
_08033AA8:
	ldr r0, [r2]
	movs r1, 0x2
	str r1, [r0, 0x40]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	movs r1, 0x11
	str r1, [r0]
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	beq _08033B0C
	movs r0, 0x31
	bl sub_80338C4
	b _08033B86
_08033ACA:
	ldr r0, [r2]
	movs r1, 0x3
	str r1, [r0, 0x40]
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r2
	str r1, [r0]
	bl sub_8095190
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08033B36
	movs r0, 0xF
	bl sub_80338C4
	b _08033B86
_08033AEC:
	ldr r0, [r2]
	movs r1, 0x4
	str r1, [r0, 0x40]
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r2
	str r1, [r0]
	movs r0, 0x4
	bl sub_8095324
	cmp r0, 0
	beq _08033B0C
	movs r0, 0x1C
	bl sub_80338C4
	b _08033B86
_08033B0C:
	movs r0, 0x22
	bl sub_80338C4
	b _08033B86
_08033B14:
	ldr r0, [r2]
	movs r1, 0x5
	str r1, [r0, 0x40]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	movs r1, 0x12
	str r1, [r0]
	movs r0, 0x5
	bl sub_8095324
	cmp r0, 0
	beq _08033B36
	movs r0, 0x3D
	bl sub_80338C4
	b _08033B86
_08033B36:
	movs r0, 0xE
	bl sub_80338C4
	b _08033B86
_08033B3E:
	ldr r0, [r2]
	movs r1, 0x6
	str r1, [r0, 0x40]
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r2
	movs r1, 0x13
	str r1, [r0]
	movs r0, 0x5
	bl sub_8095324
	cmp r0, 0
	bne _08033B60
	movs r0, 0x51
	bl sub_80338C4
	b _08033B86
_08033B60:
	movs r0, 0x5B
	bl sub_80338C4
	b _08033B86
_08033B68:
	ldr r0, [r2]
	movs r1, 0x7
	str r1, [r0, 0x40]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	movs r1, 0x14
	str r1, [r0]
	movs r0, 0x52
	bl sub_80338C4
	b _08033B86
_08033B80:
	movs r0, 0x1
	bl sub_80338C4
_08033B86:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033A2C

	thumb_func_start sub_8033B8C
sub_8033B8C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033C4C
	ldr r2, [sp]
	cmp r2, 0xC
	bgt _08033BAA
	cmp r2, 0xB
	bge _08033BB0
	cmp r2, 0x8
	beq _08033C46
	b _08033C4C
_08033BAA:
	cmp r2, 0xD
	beq _08033BF4
	b _08033C4C
_08033BB0:
	ldr r0, _08033BD4
	ldr r0, [r0]
	ldr r1, _08033BD8
	adds r2, r0, r1
	movs r1, 0xB
	str r1, [r2]
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033BEC
	cmp r0, 0x4
	bhi _08033BDC
	cmp r0, 0x3
	beq _08033BE4
	b _08033C4C
	.align 2, 0
_08033BD4: .4byte gUnknown_203B33C
_08033BD8: .4byte 0x00000524
_08033BDC:
	cmp r0, 0x12
	bhi _08033C4C
	cmp r0, 0x11
	bcc _08033C4C
_08033BE4:
	movs r0, 0x5
	bl sub_80338C4
	b _08033C4C
_08033BEC:
	movs r0, 0x23
	bl sub_80338C4
	b _08033C4C
_08033BF4:
	ldr r0, _08033C14
	ldr r0, [r0]
	ldr r3, _08033C18
	adds r1, r0, r3
	str r2, [r1]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033C3E
	cmp r0, 0x4
	bhi _08033C1C
	cmp r0, 0x3
	beq _08033C26
	b _08033C4C
	.align 2, 0
_08033C14: .4byte gUnknown_203B33C
_08033C18: .4byte 0x00000524
_08033C1C:
	cmp r0, 0x11
	beq _08033C2E
	cmp r0, 0x12
	beq _08033C36
	b _08033C4C
_08033C26:
	movs r0, 0x19
	bl sub_80338C4
	b _08033C4C
_08033C2E:
	movs r0, 0x39
	bl sub_80338C4
	b _08033C4C
_08033C36:
	movs r0, 0x43
	bl sub_80338C4
	b _08033C4C
_08033C3E:
	movs r0, 0x2D
	bl sub_80338C4
	b _08033C4C
_08033C46:
	movs r0, 0x1
	bl sub_80338C4
_08033C4C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033B8C

	thumb_func_start sub_8033C54
sub_8033C54:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033CA2
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08033C6E
	cmp r0, 0x8
	beq _08033C9C
	b _08033CA2
_08033C6E:
	ldr r0, _08033C88
	ldr r0, [r0]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033C94
	cmp r0, 0x4
	bhi _08033C8C
	cmp r0, 0x3
	beq _08033C94
	b _08033CA2
	.align 2, 0
_08033C88: .4byte gUnknown_203B33C
_08033C8C:
	cmp r0, 0x11
	beq _08033C94
	cmp r0, 0x12
	bne _08033CA2
_08033C94:
	movs r0, 0xD
	bl sub_80338C4
	b _08033CA2
_08033C9C:
	movs r0, 0x1
	bl sub_80338C4
_08033CA2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033C54

	thumb_func_start nullsub_41
nullsub_41:
	bx lr
	thumb_func_end nullsub_41

	thumb_func_start sub_8033CAC
sub_8033CAC:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033D40
	ldr r4, _08033CDC
	ldr r1, [r4]
	ldr r0, [r1, 0x44]
	cmp r0, 0
	bne _08033D36
	movs r2, 0xA5
	lsls r2, 3
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0x4
	beq _08033D2E
	cmp r0, 0x4
	bhi _08033CE0
	cmp r0, 0x3
	beq _08033CEA
	b _08033D40
	.align 2, 0
_08033CDC: .4byte gUnknown_203B33C
_08033CE0:
	cmp r0, 0x11
	beq _08033CF2
	cmp r0, 0x12
	beq _08033CFA
	b _08033D40
_08033CEA:
	movs r0, 0x16
	bl sub_80338C4
	b _08033D40
_08033CF2:
	movs r0, 0x37
	bl sub_80338C4
	b _08033D40
_08033CFA:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _08033D12
	ldr r0, [r4]
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	b _08033D1A
_08033D12:
	ldr r0, [r4]
	adds r0, 0xE0
	movs r1, 0
	ldrsh r0, [r0, r1]
_08033D1A:
	cmp r0, 0
	beq _08033D26
	movs r0, 0x3F
	bl sub_80338C4
	b _08033D40
_08033D26:
	movs r0, 0x40
	bl sub_80338C4
	b _08033D40
_08033D2E:
	movs r0, 0x2B
	bl sub_80338C4
	b _08033D40
_08033D36:
	bl sub_80338DC
	movs r0, 0x8
	bl sub_80338C4
_08033D40:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8033CAC

	thumb_func_start sub_8033D48
sub_8033D48:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033D5C
	movs r0, 0x1
	bl sub_80338C4
_08033D5C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033D48

	thumb_func_start nullsub_42
nullsub_42:
	bx lr
	thumb_func_end nullsub_42

	thumb_func_start nullsub_43
nullsub_43:
	bx lr
	thumb_func_end nullsub_43

	thumb_func_start nullsub_44
nullsub_44:
	bx lr
	thumb_func_end nullsub_44

	thumb_func_start nullsub_45
nullsub_45:
	bx lr
	thumb_func_end nullsub_45

	thumb_func_start sub_8033D74
sub_8033D74:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033D8E
	movs r0, 0x17
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08033D8E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033D74

	thumb_func_start sub_8033D94
sub_8033D94:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033DB6
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08033DB6
	bl sub_8012750
	movs r0, 0x18
	bl sub_80338C4
_08033DB6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033D94

	thumb_func_start sub_8033DBC
sub_8033DBC:
	push {r4,lr}
	sub sp, 0x44
	bl sub_80154F0
	adds r4, r0, 0
	add r0, sp, 0x14
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x2
	bne _08033DD6
	b _08033F38
_08033DD6:
	cmp r4, 0x3
	beq _08033DDC
	b _08033F58
_08033DDC:
	ldr r2, _08033DF4
	ldr r1, _08033DF8
	ldr r0, [r1]
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x3
	beq _08033DFC
	cmp r0, 0x12
	beq _08033E00
	b _08033E02
	.align 2, 0
_08033DF4: .4byte 0x0000ffdc
_08033DF8: .4byte gUnknown_203B33C
_08033DFC:
	movs r2, 0x1C
	b _08033E02
_08033E00:
	movs r2, 0x1E
_08033E02:
	ldr r1, [r1]
	adds r1, 0x8
	adds r0, r2, 0
	add r2, sp, 0x14
	bl sub_8039068
	subs r0, 0x7
	cmp r0, 0x11
	bls _08033E16
	b _08033F2E
_08033E16:
	lsls r0, 2
	ldr r1, _08033E20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033E20: .4byte _08033E24
	.align 2, 0
_08033E24:
	.4byte _08033EA0
	.4byte _08033F2E
	.4byte _08033EE0
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033E6C
	.4byte _08033E98
	.4byte _08033ED8
	.4byte _08033F2E
	.4byte _08033F2E
	.4byte _08033EA8
	.4byte _08033EFC
	.4byte _08033F2E
_08033E6C:
	ldr r0, _08033E90
	ldr r3, _08033E94
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	movs r0, 0x1B
	bl sub_80338C4
	b _08033F2E
	.align 2, 0
_08033E90: .4byte gUnknown_80E48A8
_08033E94: .4byte gUnknown_80E2290
_08033E98:
	ldr r0, _08033E9C
	b _08033EE2
	.align 2, 0
_08033E9C: .4byte gUnknown_80E48E8
_08033EA0:
	ldr r0, _08033EA4
	b _08033EE2
	.align 2, 0
_08033EA4: .4byte gUnknown_80E460C
_08033EA8:
	ldr r0, [sp, 0x24]
	bl sub_8095274
	add r1, sp, 0x14
	movs r0, 0x2
	strb r0, [r1]
	adds r0, r1, 0
	bl sub_80951BC
	ldr r0, _08033ED0
	ldr r3, _08033ED4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	movs r0, 0x16
	bl sub_80338C4
	b _08033F2E
	.align 2, 0
_08033ED0: .4byte gUnknown_80E4928
_08033ED4: .4byte 0x00000101
_08033ED8:
	ldr r0, _08033EDC
	b _08033EE2
	.align 2, 0
_08033EDC: .4byte gUnknown_80E4964
_08033EE0:
	ldr r0, _08033EF4
_08033EE2:
	ldr r3, _08033EF8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	movs r0, 0x8
	bl sub_80338C4
	b _08033F2E
	.align 2, 0
_08033EF4: .4byte gUnknown_80E499C
_08033EF8: .4byte 0x00000101
_08033EFC:
	add r1, sp, 0x14
	movs r0, 0x5
	strb r0, [r1]
	adds r0, r1, 0
	bl sub_80951FC
	ldr r1, [sp, 0x24]
	movs r0, 0x1
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	movs r1, 0x7
	strb r1, [r0]
	ldr r0, _08033F34
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	movs r0, 0x40
	bl sub_80338C4
_08033F2E:
	bl sub_80155F0
	b _08033F58
	.align 2, 0
_08033F34: .4byte gUnknown_203B484
_08033F38:
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, _08033F60
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_80338C4
_08033F58:
	add sp, 0x44
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033F60: .4byte gUnknown_203B33C
	thumb_func_end sub_8033DBC

	thumb_func_start sub_8033F64
sub_8033F64:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033FAE
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08033F7E
	cmp r0, 0x8
	beq _08033FA8
	b _08033FAE
_08033F7E:
	ldr r0, _08033F94
	ldr r0, [r0]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x3
	beq _08033F98
	cmp r0, 0x12
	beq _08033FA0
	b _08033FAE
	.align 2, 0
_08033F94: .4byte gUnknown_203B33C
_08033F98:
	movs r0, 0x19
	bl sub_80338C4
	b _08033FAE
_08033FA0:
	movs r0, 0x43
	bl sub_80338C4
	b _08033FAE
_08033FA8:
	movs r0, 0x1
	bl sub_80338C4
_08033FAE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033F64

	thumb_func_start sub_8033FB4
sub_8033FB4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08033FDE
	ldr r0, [sp]
	cmp r0, 0x6
	bne _08033FD0
	movs r0, 0xE
	bl sub_80338C4
	b _08033FDE
_08033FD0:
	cmp r0, 0x6
	blt _08033FDE
	cmp r0, 0x8
	bgt _08033FDE
	movs r0, 0x1
	bl sub_80338C4
_08033FDE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8033FB4

	thumb_func_start sub_8033FE4
sub_8033FE4:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x3
	beq _0803400C
	cmp r0, 0x3
	bhi _08033FFA
	cmp r0, 0x2
	beq _08034000
	b _0803406A
_08033FFA:
	cmp r0, 0x4
	beq _08034028
	b _0803406A
_08034000:
	bl sub_803084C
	movs r0, 0x1
	bl sub_80338C4
	b _0803406A
_0803400C:
	bl sub_80307EC
	ldr r1, _08034024
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x1E
	bl sub_80338C4
	b _0803406A
	.align 2, 0
_08034024: .4byte gUnknown_203B33C
_08034028:
	ldr r4, _08034070
	ldr r1, [r4]
	movs r0, 0x1D
	str r0, [r1, 0x4]
	bl sub_80307EC
	ldr r1, [r4]
	movs r5, 0x86
	lsls r5, 2
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x1F
	bl sub_80338C4
_0803406A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034070: .4byte gUnknown_203B33C
	thumb_func_end sub_8033FE4

	thumb_func_start sub_8034074
sub_8034074:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8030768
	ldr r4, _080340B8
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080340A6
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_080340A6:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034108
	cmp r0, 0x8
	bgt _080340BC
	cmp r0, 0x5
	beq _08034108
	b _08034124
	.align 2, 0
_080340B8: .4byte gUnknown_203B33C
_080340BC:
	cmp r0, 0x9
	beq _080340C6
	cmp r0, 0xA
	beq _080340D2
	b _08034124
_080340C6:
	bl sub_803084C
	movs r0, 0x20
	bl sub_80338C4
	b _08034124
_080340D2:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x1F
	bl sub_80338C4
	b _08034124
_08034108:
	ldr r0, _0803412C
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x2
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_8030810
	movs r0, 0x1D
	bl sub_80338C4
_08034124:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803412C: .4byte gUnknown_203B33C
	thumb_func_end sub_8034074

	thumb_func_start sub_8034130
sub_8034130:
	push {r4,lr}
	bl sub_8030DA0
	cmp r0, 0x3
	bhi _08034184
	cmp r0, 0x2
	bcc _08034184
	bl sub_8030DE4
	bl ResetUnusedInputStruct
	ldr r4, _0803417C
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803092C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _08034180
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x1E
	bl sub_80338C4
	b _08034184
	.align 2, 0
_0803417C: .4byte gUnknown_203B33C
_08034180:
	bl sub_80338C4
_08034184:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034130

	thumb_func_start sub_803418C
sub_803418C:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x3
	beq _080341D0
	cmp r0, 0x3
	bhi _080341A2
	cmp r0, 0x2
	beq _080341A8
	b _08034248
_080341A2:
	cmp r0, 0x4
	beq _08034204
	b _08034248
_080341A8:
	bl sub_8023C60
	movs r0, 0x1
	bl sub_80338C4
	bl sub_8035D1C
	ldr r0, _080341C8
	ldr r0, [r0]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	ldr r1, _080341CC
	strh r1, [r0]
	b _08034248
	.align 2, 0
_080341C8: .4byte gUnknown_203B33C
_080341CC: .4byte 0x0000ffff
_080341D0:
	bl sub_8023B44
	ldr r1, _080341F4
	ldr r1, [r1]
	movs r3, 0xA7
	lsls r3, 3
	adds r2, r1, r3
	strh r0, [r2]
	ldr r0, _080341F8
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0xE
	bne _080341FC
	movs r0, 0x9
	bl sub_80338C4
	b _08034248
	.align 2, 0
_080341F4: .4byte gUnknown_203B33C
_080341F8: .4byte 0x00000524
_080341FC:
	movs r0, 0x27
	bl sub_80338C4
	b _08034248
_08034204:
	ldr r4, _08034250
	ldr r1, [r4]
	movs r0, 0x26
	str r0, [r1, 0x4]
	bl sub_8023B44
	adds r2, r0, 0
	ldr r0, [r4]
	movs r5, 0xA7
	lsls r5, 3
	adds r1, r0, r5
	strh r2, [r1]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r1, 0
	bl sub_8024458
	movs r0, 0x28
	bl sub_80338C4
_08034248:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034250: .4byte gUnknown_203B33C
	thumb_func_end sub_803418C

	thumb_func_start sub_8034254
sub_8034254:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8023A94
	ldr r4, _08034298
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08034286
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_08034286:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _080342EA
	cmp r0, 0x8
	bgt _0803429C
	cmp r0, 0x5
	beq _080342EA
	b _08034304
	.align 2, 0
_08034298: .4byte gUnknown_203B33C
_0803429C:
	cmp r0, 0x9
	beq _080342A6
	cmp r0, 0xA
	beq _080342B2
	b _08034304
_080342A6:
	bl sub_8023C60
	movs r0, 0x29
	bl sub_80338C4
	b _08034304
_080342B2:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0
	bl sub_8024458
	movs r0, 0x28
	bl sub_80338C4
	b _08034304
_080342EA:
	ldr r0, _0803430C
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x3
	bl sub_8035CC0
	bl sub_8023DA4
	movs r0, 0x26
	bl sub_80338C4
_08034304:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803430C: .4byte gUnknown_203B33C
	thumb_func_end sub_8034254

	thumb_func_start sub_8034310
sub_8034310:
	push {r4,lr}
	bl sub_80244E4
	cmp r0, 0x1
	bne _08034320
	bl sub_802452C
	b _08034370
_08034320:
	cmp r0, 0x1
	bcc _08034370
	cmp r0, 0x3
	bhi _08034370
	bl sub_802453C
	bl ResetUnusedInputStruct
	ldr r4, _08034368
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_8023B7C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _0803436C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x27
	bl sub_80338C4
	b _08034370
	.align 2, 0
_08034368: .4byte gUnknown_203B33C
_0803436C:
	bl sub_80338C4
_08034370:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034310

	thumb_func_start sub_8034378
sub_8034378:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080343BE
	ldr r0, [sp]
	cmp r0, 0x8
	beq _080343B8
	cmp r0, 0x10
	bne _080343BE
	ldr r0, _080343A8
	ldr r0, [r0]
	ldr r1, _080343AC
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xE
	bne _080343B0
	movs r0, 0x9
	bl sub_80338C4
	b _080343BE
	.align 2, 0
_080343A8: .4byte gUnknown_203B33C
_080343AC: .4byte 0x00000524
_080343B0:
	movs r0, 0x5
	bl sub_80338C4
	b _080343BE
_080343B8:
	movs r0, 0x1
	bl sub_80338C4
_080343BE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034378

	thumb_func_start sub_80343C4
sub_80343C4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080343FE
	ldr r0, [sp]
	cmp r0, 0x7
	beq _080343F0
	cmp r0, 0x7
	bgt _080343E2
	cmp r0, 0x6
	beq _080343E8
	b _080343FE
_080343E2:
	cmp r0, 0x8
	beq _080343F8
	b _080343FE
_080343E8:
	movs r0, 0x5
	bl sub_80338C4
	b _080343FE
_080343F0:
	movs r0, 0x25
	bl sub_80338C4
	b _080343FE
_080343F8:
	movs r0, 0x1
	bl sub_80338C4
_080343FE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80343C4

	thumb_func_start sub_8034404
sub_8034404:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034472
	ldr r0, [sp]
	cmp r0, 0xF
	beq _08034428
	cmp r0, 0xF
	bgt _08034422
	cmp r0, 0x8
	beq _0803446C
	b _08034472
_08034422:
	cmp r0, 0x10
	beq _08034444
	b _08034472
_08034428:
	movs r0, 0x3
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _0803443C
	movs r0, 0x24
	bl sub_80338C4
	b _08034472
_0803443C:
	movs r0, 0x25
	bl sub_80338C4
	b _08034472
_08034444:
	ldr r0, _0803445C
	ldr r0, [r0]
	ldr r1, _08034460
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xE
	bne _08034464
	movs r0, 0x9
	bl sub_80338C4
	b _08034472
	.align 2, 0
_0803445C: .4byte gUnknown_203B33C
_08034460: .4byte 0x00000524
_08034464:
	movs r0, 0x5
	bl sub_80338C4
	b _08034472
_0803446C:
	movs r0, 0x1
	bl sub_80338C4
_08034472:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034404

	thumb_func_start sub_8034478
sub_8034478:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803449A
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0803449A
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_0803449A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034478

	thumb_func_start sub_80344A0
sub_80344A0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080344BA
	movs r0, 0x2C
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_080344BA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80344A0

	thumb_func_start sub_80344C0
sub_80344C0:
	push {lr}
	bl sub_8031DCC
	cmp r0, 0x1
	beq _080344F8
	cmp r0, 0x1
	bcc _080344FC
	cmp r0, 0x3
	bhi _080344FC
	bl sub_8031E10
	bl ResetUnusedInputStruct
	ldr r0, _080344F4
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x2F
	bl sub_80338C4
	b _080344FC
	.align 2, 0
_080344F4: .4byte gUnknown_203B33C
_080344F8:
	bl sub_8031E00
_080344FC:
	pop {r0}
	bx r0
	thumb_func_end sub_80344C0

	thumb_func_start sub_8034500
sub_8034500:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x3
	beq _08034528
	cmp r0, 0x3
	bhi _08034516
	cmp r0, 0x2
	beq _0803451C
	b _08034586
_08034516:
	cmp r0, 0x4
	beq _08034544
	b _08034586
_0803451C:
	bl sub_803084C
	movs r0, 0x1
	bl sub_80338C4
	b _08034586
_08034528:
	bl sub_80307EC
	ldr r1, _08034540
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x33
	bl sub_80338C4
	b _08034586
	.align 2, 0
_08034540: .4byte gUnknown_203B33C
_08034544:
	ldr r4, _0803458C
	ldr r1, [r4]
	movs r0, 0x32
	str r0, [r1, 0x4]
	bl sub_80307EC
	ldr r1, [r4]
	movs r5, 0x86
	lsls r5, 2
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x34
	bl sub_80338C4
_08034586:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803458C: .4byte gUnknown_203B33C
	thumb_func_end sub_8034500

	thumb_func_start sub_8034590
sub_8034590:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8030768
	ldr r4, _080345D4
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080345C2
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_080345C2:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034624
	cmp r0, 0x8
	bgt _080345D8
	cmp r0, 0x5
	beq _08034624
	b _08034640
	.align 2, 0
_080345D4: .4byte gUnknown_203B33C
_080345D8:
	cmp r0, 0x9
	beq _080345E2
	cmp r0, 0xA
	beq _080345EE
	b _08034640
_080345E2:
	bl sub_803084C
	movs r0, 0x35
	bl sub_80338C4
	b _08034640
_080345EE:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x34
	bl sub_80338C4
	b _08034640
_08034624:
	ldr r0, _08034648
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x2
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_8030810
	movs r0, 0x32
	bl sub_80338C4
_08034640:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034648: .4byte gUnknown_203B33C
	thumb_func_end sub_8034590

	thumb_func_start sub_803464C
sub_803464C:
	push {r4,lr}
	bl sub_8030DA0
	cmp r0, 0x3
	bhi _080346A0
	cmp r0, 0x2
	bcc _080346A0
	bl sub_8030DE4
	bl ResetUnusedInputStruct
	ldr r4, _08034698
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803092C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _0803469C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x33
	bl sub_80338C4
	b _080346A0
	.align 2, 0
_08034698: .4byte gUnknown_203B33C
_0803469C:
	bl sub_80338C4
_080346A0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803464C

	thumb_func_start sub_80346A8
sub_80346A8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080346D2
	ldr r0, [sp]
	cmp r0, 0x6
	bne _080346C4
	movs r0, 0xE
	bl sub_80338C4
	b _080346D2
_080346C4:
	cmp r0, 0x6
	blt _080346D2
	cmp r0, 0x8
	bgt _080346D2
	movs r0, 0x1
	bl sub_80338C4
_080346D2:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80346A8

	thumb_func_start sub_80346D8
sub_80346D8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080346FA
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _080346FA
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_080346FA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80346D8

	thumb_func_start sub_8034700
sub_8034700:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803471A
	movs r0, 0x38
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_0803471A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034700

	thumb_func_start sub_8034720
sub_8034720:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034734
	movs r0, 0x3A
	bl sub_80338C4
_08034734:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034720

	thumb_func_start sub_803473C
sub_803473C:
	push {lr}
	bl sub_8031DCC
	cmp r0, 0x1
	beq _08034774
	cmp r0, 0x1
	bcc _08034778
	cmp r0, 0x3
	bhi _08034778
	bl sub_8031E10
	bl ResetUnusedInputStruct
	ldr r0, _08034770
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x3B
	bl sub_80338C4
	b _08034778
	.align 2, 0
_08034770: .4byte gUnknown_203B33C
_08034774:
	bl sub_8031E00
_08034778:
	pop {r0}
	bx r0
	thumb_func_end sub_803473C

	thumb_func_start sub_803477C
sub_803477C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347A6
	ldr r0, [sp]
	cmp r0, 0x6
	bne _08034798
	movs r0, 0xE
	bl sub_80338C4
	b _080347A6
_08034798:
	cmp r0, 0x6
	blt _080347A6
	cmp r0, 0x8
	bgt _080347A6
	movs r0, 0x1
	bl sub_80338C4
_080347A6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803477C

	thumb_func_start sub_80347AC
sub_80347AC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347C0
	movs r0, 0xD
	bl sub_80338C4
_080347C0:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80347AC

	thumb_func_start sub_80347C8
sub_80347C8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347DC
	movs r0, 0x40
	bl sub_80338C4
_080347DC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80347C8

	thumb_func_start sub_80347E4
sub_80347E4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080347FE
	movs r0, 0x41
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_080347FE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80347E4

	thumb_func_start sub_8034804
sub_8034804:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034826
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08034826
	bl sub_8012750
	movs r0, 0x42
	bl sub_80338C4
_08034826:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034804

	thumb_func_start sub_803482C
sub_803482C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034840
	movs r0, 0x1
	bl sub_80338C4
_08034840:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803482C

	thumb_func_start sub_8034848
sub_8034848:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	adds r6, r0, 0
	cmp r6, 0
	bne _080348BA
	ldr r4, _0803489C
	ldr r0, [r4]
	ldr r5, _080348A0
	adds r0, r5
	movs r1, 0
	movs r2, 0x4
	bl MemoryFill8
	ldr r0, [r4]
	ldr r1, _080348A4
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r4]
	subs r1, 0x1
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r5
	strb r6, [r0]
	ldr r4, [r4]
	ldr r0, [r4, 0x44]
	cmp r0, 0
	bne _080348B0
	ldr r4, [r4, 0x40]
	cmp r4, 0x6
	beq _080348A8
	cmp r4, 0x7
	bne _080348BA
	movs r0, 0x6D
	bl sub_80338C4
	b _080348BA
	.align 2, 0
_0803489C: .4byte gUnknown_203B33C
_080348A0: .4byte 0x0000041c
_080348A4: .4byte 0x0000041e
_080348A8:
	movs r0, 0x50
	bl sub_80338C4
	b _080348BA
_080348B0:
	bl sub_80338DC
	movs r0, 0x6B
	bl sub_80338C4
_080348BA:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8034848

	thumb_func_start sub_80348C4
sub_80348C4:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	adds r6, r0, 0
	cmp r6, 0
	bne _08034968
	ldr r4, _08034910
	ldr r0, [r4]
	ldr r5, _08034914
	adds r0, r5
	movs r1, 0
	movs r2, 0x4
	bl MemoryFill8
	ldr r0, [r4]
	ldr r1, _08034918
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r4]
	subs r1, 0x1
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r5
	strb r6, [r0]
	ldr r0, [r4]
	ldr r1, [r0, 0x44]
	cmp r1, 0
	bne _0803495C
	ldr r1, [r0, 0x40]
	cmp r1, 0x6
	beq _0803491C
	cmp r1, 0x7
	beq _08034954
	b _08034968
	.align 2, 0
_08034910: .4byte gUnknown_203B33C
_08034914: .4byte 0x0000041c
_08034918: .4byte 0x0000041e
_0803491C:
	ldr r1, _08034930
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xC
	beq _08034944
	cmp r0, 0xC
	bhi _08034934
	cmp r0, 0xB
	beq _08034938
	b _08034944
	.align 2, 0
_08034930: .4byte 0x00000524
_08034934:
	cmp r0, 0xE
	bhi _08034944
_08034938:
	ldr r0, _0803494C
	ldr r3, _08034950
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08034944:
	movs r0, 0x77
	bl sub_80338C4
	b _08034968
	.align 2, 0
_0803494C: .4byte gUnknown_80E31FC
_08034950: .4byte 0x00000101
_08034954:
	movs r0, 0x6D
	bl sub_80338C4
	b _08034968
_0803495C:
	adds r0, r1, 0
	bl sub_80338DC
	movs r0, 0x6B
	bl sub_80338C4
_08034968:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80348C4

	thumb_func_start sub_8034970
sub_8034970:
	push {lr}
	bl sub_8031DCC
	cmp r0, 0x1
	beq _080349A8
	cmp r0, 0x1
	bcc _080349AC
	cmp r0, 0x3
	bhi _080349AC
	bl sub_8031E10
	bl ResetUnusedInputStruct
	ldr r0, _080349A4
	ldr r0, [r0]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x68
	bl sub_80338C4
	b _080349AC
	.align 2, 0
_080349A4: .4byte gUnknown_203B33C
_080349A8:
	bl sub_8031E00
_080349AC:
	pop {r0}
	bx r0
	thumb_func_end sub_8034970

	thumb_func_start sub_80349B0
sub_80349B0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080349DA
	ldr r0, [sp]
	cmp r0, 0x6
	bne _080349CC
	movs r0, 0x52
	bl sub_80338C4
	b _080349DA
_080349CC:
	cmp r0, 0x6
	blt _080349DA
	cmp r0, 0x8
	bgt _080349DA
	movs r0, 0x1
	bl sub_80338C4
_080349DA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80349B0

	thumb_func_start sub_80349E0
sub_80349E0:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x3
	beq _08034A08
	cmp r0, 0x3
	bhi _080349F6
	cmp r0, 0x2
	beq _080349FC
	b _08034A66
_080349F6:
	cmp r0, 0x4
	beq _08034A24
	b _08034A66
_080349FC:
	bl sub_803084C
	movs r0, 0x1
	bl sub_80338C4
	b _08034A66
_08034A08:
	bl sub_80307EC
	ldr r1, _08034A20
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x5D
	bl sub_80338C4
	b _08034A66
	.align 2, 0
_08034A20: .4byte gUnknown_203B33C
_08034A24:
	ldr r4, _08034A6C
	ldr r1, [r4]
	movs r0, 0x5C
	str r0, [r1, 0x4]
	bl sub_80307EC
	ldr r1, [r4]
	movs r5, 0x86
	lsls r5, 2
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x5E
	bl sub_80338C4
_08034A66:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034A6C: .4byte gUnknown_203B33C
	thumb_func_end sub_80349E0

	thumb_func_start sub_8034A70
sub_8034A70:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_8030768
	ldr r4, _08034AB4
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08034AA2
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_08034AA2:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034B04
	cmp r0, 0x8
	bgt _08034AB8
	cmp r0, 0x5
	beq _08034B04
	b _08034B20
	.align 2, 0
_08034AB4: .4byte gUnknown_203B33C
_08034AB8:
	cmp r0, 0x9
	beq _08034AC2
	cmp r0, 0xA
	beq _08034ACE
	b _08034B20
_08034AC2:
	bl sub_803084C
	movs r0, 0x5A
	bl sub_80338C4
	b _08034B20
_08034ACE:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8030D40
	movs r0, 0x5E
	bl sub_80338C4
	b _08034B20
_08034B04:
	ldr r0, _08034B28
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x2
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_8030810
	movs r0, 0x5C
	bl sub_80338C4
_08034B20:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034B28: .4byte gUnknown_203B33C
	thumb_func_end sub_8034A70

	thumb_func_start sub_8034B2C
sub_8034B2C:
	push {r4,lr}
	bl sub_8030DA0
	cmp r0, 0x3
	bhi _08034B80
	cmp r0, 0x2
	bcc _08034B80
	bl sub_8030DE4
	bl ResetUnusedInputStruct
	ldr r4, _08034B78
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_803092C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _08034B7C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x5D
	bl sub_80338C4
	b _08034B80
	.align 2, 0
_08034B78: .4byte gUnknown_203B33C
_08034B7C:
	bl sub_80338C4
_08034B80:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034B2C

	thumb_func_start sub_8034B88
sub_8034B88:
	push {r4-r6,lr}
	ldr r4, _08034BBC
	ldr r0, [r4]
	ldr r5, _08034BC0
	adds r0, r5
	movs r2, 0
	strb r2, [r0]
	ldr r0, [r4]
	ldr r1, _08034BC4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r6, _08034BC8
	adds r0, r6
	strb r2, [r0]
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x3
	beq _08034BDE
	cmp r0, 0x3
	bhi _08034BCC
	cmp r0, 0x2
	beq _08034BD2
	b _08034C30
	.align 2, 0
_08034BBC: .4byte gUnknown_203B33C
_08034BC0: .4byte 0x0000041e
_08034BC4: .4byte 0x0000041d
_08034BC8: .4byte 0x0000041c
_08034BCC:
	cmp r0, 0x4
	beq _08034BF8
	b _08034C30
_08034BD2:
	bl sub_801CBB8
	movs r0, 0x1
	bl sub_80338C4
	b _08034C30
_08034BDE:
	bl sub_801CB24
	ldr r1, [r4]
	ldr r2, _08034BF4
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x60
	bl sub_80338C4
	b _08034C30
	.align 2, 0
_08034BF4: .4byte 0x0000041e
_08034BF8:
	ldr r1, [r4]
	movs r0, 0x5F
	str r0, [r1, 0x4]
	bl sub_801CB24
	ldr r1, [r4]
	adds r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, r6
	bl sub_801B3C0
	movs r0, 0x61
	bl sub_80338C4
_08034C30:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8034B88

	thumb_func_start sub_8034C38
sub_8034C38:
	push {r4,lr}
	bl sub_801B410
	cmp r0, 0x1
	beq _08034C90
	cmp r0, 0x1
	bcc _08034C90
	cmp r0, 0x3
	bhi _08034C90
	bl sub_801B450
	bl ResetUnusedInputStruct
	ldr r4, _08034C88
	ldr r0, [r4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_801CB5C
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0x7E
	bne _08034C8C
	movs r1, 0x87
	lsls r1, 2
	adds r0, r4, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	movs r0, 0x60
	bl sub_80338C4
	b _08034C90
	.align 2, 0
_08034C88: .4byte gUnknown_203B33C
_08034C8C:
	bl sub_80338C4
_08034C90:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8034C38

	thumb_func_start sub_8034C98
sub_8034C98:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r0, 0
	bl sub_801CA08
	ldr r4, _08034CDC
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08034CCA
	ldr r0, [r4]
	movs r1, 0xC3
	lsls r1, 2
	adds r0, r1
	mov r1, sp
	bl sub_8013114
_08034CCA:
	ldr r0, [sp]
	cmp r0, 0x8
	beq _08034D2C
	cmp r0, 0x8
	bgt _08034CE0
	cmp r0, 0x5
	beq _08034D2C
	b _08034D48
	.align 2, 0
_08034CDC: .4byte gUnknown_203B33C
_08034CE0:
	cmp r0, 0x9
	beq _08034CEA
	cmp r0, 0xA
	beq _08034CF6
	b _08034D48
_08034CEA:
	bl sub_801CBB8
	movs r0, 0x58
	bl sub_80338C4
	b _08034D48
_08034CF6:
	ldr r0, [r4]
	movs r1, 0x7E
	str r1, [r0, 0x4]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	ldr r1, _08034D28
	adds r0, r1
	bl sub_801B3C0
	movs r0, 0x61
	bl sub_80338C4
	b _08034D48
	.align 2, 0
_08034D28: .4byte 0x0000041c
_08034D2C:
	ldr r0, _08034D50
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x3
	bl sub_8035CC0
	movs r0, 0x1
	bl sub_801CB5C
	movs r0, 0x5F
	bl sub_80338C4
_08034D48:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034D50: .4byte gUnknown_203B33C
	thumb_func_end sub_8034C98

	thumb_func_start sub_8034D54
sub_8034D54:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034D6E
	movs r0, 0x65
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08034D6E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034D54

	thumb_func_start sub_8034D74
sub_8034D74:
	push {r4,r5,lr}
	sub sp, 0x44
	bl sub_80154F0
	adds r4, r0, 0
	add r0, sp, 0x14
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x2
	bne _08034D8E
	b _08034E9C
_08034D8E:
	cmp r4, 0x3
	beq _08034D94
	b _08034EBC
_08034D94:
	ldr r0, _08034DB4
	ldr r1, [r0]
	adds r1, 0x8
	movs r0, 0x20
	add r2, sp, 0x14
	bl sub_8039068
	subs r0, 0x7
	cmp r0, 0x11
	bhi _08034E90
	lsls r0, 2
	ldr r1, _08034DB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08034DB4: .4byte gUnknown_203B33C
_08034DB8: .4byte _08034DBC
	.align 2, 0
_08034DBC:
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E38
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E04
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E30
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E90
	.4byte _08034E54
_08034E04:
	ldr r0, _08034E28
	ldr r3, _08034E2C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x6
	bl sub_8014248
	movs r0, 0x74
	bl sub_80338C4
	b _08034E90
	.align 2, 0
_08034E28: .4byte gUnknown_80E48A8
_08034E2C: .4byte gUnknown_80E2440
_08034E30:
	ldr r0, _08034E34
	b _08034E3A
	.align 2, 0
_08034E34: .4byte gUnknown_80E49C4
_08034E38:
	ldr r0, _08034E4C
_08034E3A:
	ldr r3, _08034E50
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	movs r0, 0x6B
	bl sub_80338C4
	b _08034E90
	.align 2, 0
_08034E4C: .4byte gUnknown_80E4704
_08034E50: .4byte 0x00000101
_08034E54:
	ldr r1, [sp, 0x24]
	movs r0, 0x4
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	add r1, sp, 0x14
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	movs r1, 0x6
	strb r1, [r0]
	ldr r0, _08034E98
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r1, [sp, 0x24]
	str r1, [r0]
	movs r0, 0x6D
	bl sub_80338C4
_08034E90:
	bl sub_80155F0
	b _08034EBC
	.align 2, 0
_08034E98: .4byte gUnknown_203B33C
_08034E9C:
	bl sub_80155F0
	bl ResetUnusedInputStruct
	ldr r0, _08034EC4
	ldr r0, [r0]
	movs r3, 0xEF
	lsls r3, 2
	adds r0, r3
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x1
	bl sub_80338C4
_08034EBC:
	add sp, 0x44
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034EC4: .4byte gUnknown_203B33C
	thumb_func_end sub_8034D74

	thumb_func_start sub_8034EC8
sub_8034EC8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034EEA
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08034EEA
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_08034EEA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034EC8

	thumb_func_start sub_8034EF0
sub_8034EF0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F12
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08034F12
	bl sub_8012750
	movs r0, 0x2
	bl sub_80338C4
_08034F12:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034EF0

	thumb_func_start sub_8034F18
sub_8034F18:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F32
	movs r0, 0x65
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08034F32:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034F18

	thumb_func_start sub_8034F38
sub_8034F38:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F52
	movs r0, 0x71
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08034F52:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034F38

	thumb_func_start sub_8034F58
sub_8034F58:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08034F80
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08034F72
	cmp r0, 0x8
	beq _08034F7A
	b _08034F80
_08034F72:
	movs r0, 0x62
	bl sub_80338C4
	b _08034F80
_08034F7A:
	movs r0, 0x1
	bl sub_80338C4
_08034F80:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8034F58

	thumb_func_start sub_8034F88
sub_8034F88:
	push {r4,r5,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803500E
	ldr r0, [sp]
	cmp r0, 0x7
	beq _08035000
	cmp r0, 0x7
	bgt _08034FA6
	cmp r0, 0x6
	beq _08034FAC
	b _0803500E
_08034FA6:
	cmp r0, 0x8
	beq _08035008
	b _0803500E
_08034FAC:
	ldr r4, _08034FF0
	ldr r0, [r4]
	movs r1, 0x86
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8095228
	adds r2, r0, 0
	ldr r1, [r4]
	ldr r3, _08034FF4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08034FD2
	ldr r5, _08034FF8
	adds r0, r1, r5
	ldr r0, [r0]
	str r0, [r2, 0x20]
_08034FD2:
	ldr r0, _08034FFC
	ldr r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
	movs r0, 0x75
	bl sub_80338C4
	b _0803500E
	.align 2, 0
_08034FF0: .4byte gUnknown_203B33C
_08034FF4: .4byte 0x0000041e
_08034FF8: .4byte 0x0000041c
_08034FFC: .4byte gUnknown_203B460
_08035000:
	movs r0, 0x57
	bl sub_80338C4
	b _0803500E
_08035008:
	movs r0, 0x1
	bl sub_80338C4
_0803500E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8034F88

	thumb_func_start sub_8035018
sub_8035018:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08035032
	movs r0, 0x76
	bl sub_80338C4
	movs r0, 0
	bl sub_8012574
_08035032:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035018

	thumb_func_start sub_8035038
sub_8035038:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803508E
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _0803508E
	bl sub_8012750
	ldr r0, _0803506C
	ldr r0, [r0]
	ldr r1, _08035070
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _08035080
	cmp r0, 0xD
	bls _08035074
	cmp r0, 0xE
	beq _08035088
	b _0803508E
	.align 2, 0
_0803506C: .4byte gUnknown_203B33C
_08035070: .4byte 0x00000524
_08035074:
	cmp r0, 0xB
	bcc _0803508E
	movs r0, 0x69
	bl sub_80338C4
	b _0803508E
_08035080:
	movs r0, 0x66
	bl sub_80338C4
	b _0803508E
_08035088:
	movs r0, 0x4B
	bl sub_80338C4
_0803508E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035038

	thumb_func_start sub_8035094
sub_8035094:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080350EE
	ldr r0, [sp]
	cmp r0, 0x8
	beq _080350E8
	cmp r0, 0x16
	bne _080350EE
	ldr r0, _080350C4
	ldr r0, [r0]
	ldr r1, _080350C8
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _080350D8
	cmp r0, 0xD
	bls _080350CC
	cmp r0, 0xE
	beq _080350E0
	b _080350EE
	.align 2, 0
_080350C4: .4byte gUnknown_203B33C
_080350C8: .4byte 0x00000524
_080350CC:
	cmp r0, 0xB
	bcc _080350EE
	movs r0, 0x69
	bl sub_80338C4
	b _080350EE
_080350D8:
	movs r0, 0x66
	bl sub_80338C4
	b _080350EE
_080350E0:
	movs r0, 0x4B
	bl sub_80338C4
	b _080350EE
_080350E8:
	movs r0, 0x1
	bl sub_80338C4
_080350EE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035094

	thumb_func_start sub_80350F4
sub_80350F4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08035176
	ldr r0, [sp]
	cmp r0, 0x15
	beq _08035118
	cmp r0, 0x15
	bgt _08035112
	cmp r0, 0x8
	beq _08035170
	b _08035176
_08035112:
	cmp r0, 0x16
	beq _08035134
	b _08035176
_08035118:
	movs r0, 0
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _0803512C
	movs r0, 0x56
	bl sub_80338C4
	b _08035176
_0803512C:
	movs r0, 0x57
	bl sub_80338C4
	b _08035176
_08035134:
	ldr r0, _0803514C
	ldr r0, [r0]
	ldr r1, _08035150
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _08035160
	cmp r0, 0xD
	bls _08035154
	cmp r0, 0xE
	beq _08035168
	b _08035176
	.align 2, 0
_0803514C: .4byte gUnknown_203B33C
_08035150: .4byte 0x00000524
_08035154:
	cmp r0, 0xB
	bcc _08035176
	movs r0, 0x69
	bl sub_80338C4
	b _08035176
_08035160:
	movs r0, 0x66
	bl sub_80338C4
	b _08035176
_08035168:
	movs r0, 0x4B
	bl sub_80338C4
	b _08035176
_08035170:
	movs r0, 0x1
	bl sub_80338C4
_08035176:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80350F4

	thumb_func_start sub_803517C
sub_803517C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080351DA
	ldr r0, [sp]
	cmp r0, 0x6
	beq _08035196
	cmp r0, 0x8
	beq _080351D4
	b _080351DA
_08035196:
	ldr r0, _080351B0
	ldr r0, [r0]
	ldr r1, _080351B4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xD
	beq _080351C4
	cmp r0, 0xD
	bls _080351B8
	cmp r0, 0xE
	beq _080351CC
	b _080351DA
	.align 2, 0
_080351B0: .4byte gUnknown_203B33C
_080351B4: .4byte 0x00000524
_080351B8:
	cmp r0, 0xB
	bcc _080351DA
	movs r0, 0x69
	bl sub_80338C4
	b _080351DA
_080351C4:
	movs r0, 0x66
	bl sub_80338C4
	b _080351DA
_080351CC:
	movs r0, 0x4B
	bl sub_80338C4
	b _080351DA
_080351D4:
	movs r0, 0x1
	bl sub_80338C4
_080351DA:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_803517C

	thumb_func_start sub_80351E0
sub_80351E0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08035208
	ldr r0, [sp]
	cmp r0, 0x6
	beq _080351FA
	cmp r0, 0x8
	beq _08035202
	b _08035208
_080351FA:
	movs r0, 0x72
	bl sub_80338C4
	b _08035208
_08035202:
	movs r0, 0x1
	bl sub_80338C4
_08035208:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80351E0

	thumb_func_start sub_8035210
sub_8035210:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803528C
	ldr r0, _08035238
	ldr r2, [r0]
	ldr r1, _0803523C
	adds r0, r2, r1
	ldr r1, [sp]
	str r1, [r0]
	cmp r1, 0xD
	bgt _0803528C
	cmp r1, 0xB
	bge _08035240
	cmp r1, 0x8
	beq _08035286
	b _0803528C
	.align 2, 0
_08035238: .4byte gUnknown_203B33C
_0803523C: .4byte 0x00000524
_08035240:
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, 0x13
	bne _08035272
	movs r0, 0x5
	bl sub_80953D4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803526A
	movs r0, 0x53
	bl sub_80338C4
	b _0803528C
_0803526A:
	movs r0, 0x55
	bl sub_80338C4
	b _0803528C
_08035272:
	cmp r1, 0xD
	beq _0803527E
	movs r0, 0x69
	bl sub_80338C4
	b _0803528C
_0803527E:
	movs r0, 0x72
	bl sub_80338C4
	b _0803528C
_08035286:
	movs r0, 0x1
	bl sub_80338C4
_0803528C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8035210

        .align 2,0
