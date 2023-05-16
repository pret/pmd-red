        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

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
	bl CountMailType
	cmp r0, 0
	bne _08032A9C
	movs r0, 0x5
	bl CountMailType
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
	bl CountMailType
	cmp r0, 0
	bne _08032B24
	movs r0, 0x5
	bl CountMailType
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
	bl CountMailType
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
	bl CountMailType
	adds r4, r0, 0
	cmp r4, 0
	bne _08032C0C
	movs r0, 0x5
	bl CountMailType
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
	bl CountMailType
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
	bl GetMailatIndex
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
	bl GetMailatIndex
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
	bl GetMailatIndex
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
	bl GetMailIndex
	lsls r0, 24
	lsrs r0, 24
	bl GetMailatIndex
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
	bl GetDungeonTeamRankPts
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
	bl GetPlayerPokemonStruct
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
	bl sprintfStatic
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

        .align 2,0
