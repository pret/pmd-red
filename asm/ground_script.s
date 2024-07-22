	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start ExecuteScriptCommand
ExecuteScriptCommand:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1BC
	mov r9, r0
	movs r0, 0x24
	add r0, r9
	mov r10, r0
_0809EAE0:
	mov r1, r10
	ldr r2, [r1, 0x4]
	str r2, [r1, 0x1C]
	add r1, sp, 0x8
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, 0x10
	mov r0, r10
	str r2, [r0, 0x4]
	add r0, sp, 0x8
	ldrb r0, [r0]
	mov r1, r10
	adds r1, 0x20
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	adds r2, r1, 0
	cmp r0, 0xF5
	bhi _0809EAE0
	lsls r0, 2
	ldr r1, _0809EB18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809EB18: .4byte _0809EB1C
	.align 2, 0
_0809EB1C:
	.4byte _0809EEF4
	.4byte _0809EF40
	.4byte _0809EFA2
	.4byte _0809EFD6
	.4byte _0809F064
	.4byte _0809F02A
	.4byte _0809F06C
	.4byte _0809F0D0
	.4byte _0809F0D0
	.4byte _0809F1FC
	.4byte _0809F2C8
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F42A
	.4byte _0809F432
	.4byte _0809F43A
	.4byte _0809F442
	.4byte _0809F4FE
	.4byte _0809F5BE
	.4byte _0809F5AE
	.4byte _0809F5C6
	.4byte _0809F5C6
	.4byte _0809F660
	.4byte _0809F6EA
	.4byte _0809F786
	.4byte _0809F830
	.4byte _0809F842
	.4byte _0809F854
	.4byte _0809F872
	.4byte _0809F884
	.4byte _0809F896
	.4byte _0809F896
	.4byte _0809F8E8
	.4byte _0809F8F4
	.4byte _0809F900
	.4byte _0809F90C
	.4byte _0809F93E
	.4byte _0809FAF8
	.4byte _0809FB10
	.4byte _0809F92E
	.4byte _0809F936
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FBDA
	.4byte _0809FC12
	.4byte _0809FC40
	.4byte _0809FC2E
	.4byte _0809FC46
	.4byte _0809FCA4
	.4byte _0809FCC4
	.4byte _0809EAE0
	.4byte _080A0E3A
	.4byte _0809FCE8
	.4byte _0809FCF0
	.4byte _0809FD0A
	.4byte _0809FD38
	.4byte _0809FD6C
	.4byte _0809FDA0
	.4byte _0809FDA8
	.4byte _0809FDC2
	.4byte _0809FDD4
	.4byte _0809FDE2
	.4byte _0809FDC2
	.4byte _0809FDD4
	.4byte _0809FDE2
	.4byte _0809FE04
	.4byte _0809FE28
	.4byte _0809FE86
	.4byte _0809FEBE
	.4byte _0809FED0
	.4byte _0809FF00
	.4byte _0809FF32
	.4byte _0809FF46
	.4byte _0809FF62
	.4byte _0809FF78
	.4byte _0809FF9A
	.4byte _0809FFBA
	.4byte _0809FFE4
	.4byte _080A0010
	.4byte _080A0064
	.4byte _080A0096
	.4byte _080A010E
	.4byte _080A0186
	.4byte _080A0198
	.4byte _080A01B8
	.4byte _080A01F0
	.4byte _080A0220
	.4byte _080A0250
	.4byte _080A0282
	.4byte _080A0282
	.4byte _080A0560
	.4byte _080A0198
	.4byte _080A01B8
	.4byte _080A01F0
	.4byte _080A0220
	.4byte _080A0250
	.4byte _080A0282
	.4byte _080A0282
	.4byte _080A0560
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A057C
	.4byte _080A05A4
	.4byte _080A05F0
	.4byte _080A060E
	.4byte _080A065C
	.4byte _080A068A
	.4byte _080A068A
	.4byte _080A068A
	.4byte _080A07CA
	.4byte _080A07DC
	.4byte _080A07C4
	.4byte _080A07C4
	.4byte _080A07C4
	.4byte _0809EAE0
	.4byte _080A080C
	.4byte _080A081E
	.4byte _080A086A
	.4byte _080A08BE
	.4byte _080A08CA
	.4byte _080A091E
	.4byte _080A0986
	.4byte _080A0998
	.4byte _080A09EA
	.4byte _080A0A52
	.4byte _080A0A64
	.4byte _080A0AB6
	.4byte _080A0B1E
	.4byte _080A0B30
	.4byte _080A0B42
	.4byte _080A0B54
	.4byte _080A0B6C
	.4byte _080A0B88
	.4byte _080A0BA2
	.4byte _080A0BB4
	.4byte _080A0BDA
	.4byte _080A0BF6
	.4byte _080A0C08
	.4byte _080A0C20
	.4byte _080A0C38
	.4byte _080A0C50
	.4byte _080A0C68
	.4byte _080A0C80
	.4byte _080A0C90
	.4byte _080A0CA2
	.4byte _080A0CC8
	.4byte _080A0CF2
	.4byte _080A0D16
	.4byte _080A0D40
	.4byte _080A0D6A
	.4byte _080A0D7A
	.4byte _080A0D94
	.4byte _080A0DAE
	.4byte _080A0DD6
	.4byte _080A0E08
	.4byte _080A0DE2
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _080A10A0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _0809EAE0
	.4byte _080A129E
	.4byte _080A12A8
	.4byte _080A12B4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _080A12D0
	.4byte _080A12E6
	.4byte _080A12F4
	.4byte _080A1318
	.4byte _080A1324
	.4byte _080A1338
	.4byte _080A1344
	.4byte _080A1368
	.4byte _080A1374
	.4byte _080A13CA
	.4byte _080A13F8
	.4byte _080A1404
	.4byte _080A140C
	.4byte _080A1428
	.4byte _080A142C
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
_0809EEF4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	adds r6, r4, 0
	add r0, sp, 0x8
	ldrb r5, [r0, 0x1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809EF26
	ldr r1, _0809EF38
	ldr r2, _0809EF3C
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r3, [r0]
	str r5, [sp]
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809EF26:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundMainGroundRequest
	b _0809EAE0
	.align 2, 0
_0809EF38: .4byte gUnknown_81165D4
_0809EF3C: .4byte gUnknown_811BAF4
_0809EF40:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	movs r5, 0x1
	negs r5, r5
	cmp r4, r5
	bne _0809EF5A
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
_0809EF5A:
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809EF70
	ldr r1, _0809EF90
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809EF70:
	cmp r4, r5
	beq _0809EF94
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl GroundMainRescueRequest
	mov r0, r9
	movs r1, 0x1
	bl sub_80A2460
	mov r3, r9
	str r0, [r3, 0x28]
	b _0809EAE0
	.align 2, 0
_0809EF90: .4byte gUnknown_81165F4
_0809EF94:
	mov r0, r9
	movs r1, 0
	bl sub_80A2460
	mov r4, r9
	str r0, [r4, 0x28]
	b _0809EAE0
_0809EFA2:
	ldr r0, [sp, 0xC]
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _0809EFBE
	movs r1, 0x1
	negs r1, r1
	mov r0, r9
	bl sub_80A2460
	mov r5, r9
	str r0, [r5, 0x28]
	b _0809EAE0
_0809EFBE:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_8098D80
	mov r0, r9
	movs r1, 0
	bl sub_80A2460
	mov r2, r9
	str r0, [r2, 0x28]
	b _0809EAE0
_0809EFD6:
	ldr r1, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809F00C
	bl sub_802FCF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0809F0BC
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _0809F0BC
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	mov r0, r9
	adds r0, 0x4C
	strh r4, [r0]
	b _0809F0C4
_0809F00C:
	lsls r0, r1, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F02A:
	ldr r2, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bne _0809F054
	movs r0, 0x24
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _0809F0BC
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0
	b _0809F0C2
_0809F054:
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F064:
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F06C:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0809F088
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	b _0809F092
_0809F088:
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
_0809F092:
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F0A8
	ldr r1, _0809F0B8
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809F0A8:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809F0BC
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
	.align 2, 0
_0809F0B8: .4byte gUnknown_811660C
_0809F0BC:
	mov r1, r9
	adds r1, 0x4C
	ldr r0, _0809F0CC
_0809F0C2:
	strh r0, [r1]
_0809F0C4:
	movs r0, 0x2
	bl _080A142E
	.align 2, 0
_0809F0CC: .4byte 0x0000ffff
_0809F0D0:
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0809F130
	ldr r5, _0809F11C
	ldr r0, [sp, 0xC]
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A4D7C
	ldr r4, _0809F120
	strh r0, [r4]
	ldr r1, _0809F124
	strh r0, [r1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F16A
	ldr r1, _0809F128
	movs r3, 0
	ldrsh r2, [r5, r3]
	movs r5, 0
	ldrsh r3, [r4, r5]
	ldr r4, _0809F12C
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
	b _0809F16A
	.align 2, 0
_0809F11C: .4byte gUnknown_2039A30
_0809F120: .4byte gUnknown_2039A32
_0809F124: .4byte gUnknown_2039A34
_0809F128: .4byte gUnknown_8116628
_0809F12C: .4byte gUnknown_811BAF4
_0809F130:
	ldr r5, _0809F1E8
	ldr r4, _0809F1EC
	ldr r1, [sp, 0xC]
	strh r1, [r4]
	strh r1, [r5]
	ldr r0, _0809F1F0
	strh r1, [r0]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F16A
	ldr r1, _0809F1F4
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r4, 0
	ldrsh r3, [r5, r4]
	ldr r4, _0809F1F8
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
_0809F16A:
	ldr r5, _0809F1EC
	movs r0, 0
	ldrsh r2, [r5, r0]
	movs r0, 0
	movs r1, 0x10
	bl sub_80018D8
	ldr r6, _0809F1F8
	movs r2, 0
	ldrsh r1, [r5, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0
	movs r1, 0x11
	bl sub_80018D8
	ldr r4, _0809F1E8
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl GroundSprite_Reset
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl sub_809C770
	movs r5, 0
	ldrsh r0, [r4, r5]
	bl GroundMap_Select
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl GroundLink_Select
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r1, 0
	movs r2, 0
	bl GroundLives_Select
	movs r3, 0
	ldrsh r0, [r4, r3]
	b _0809F2A0
	.align 2, 0
_0809F1E8: .4byte gUnknown_2039A32
_0809F1EC: .4byte gUnknown_2039A30
_0809F1F0: .4byte gUnknown_2039A34
_0809F1F4: .4byte gUnknown_8116644
_0809F1F8: .4byte gUnknown_811BAF4
_0809F1FC:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	adds r6, r0, 0
	ldr r1, _0809F2AC
	ldr r5, _0809F2B0
	ldr r4, _0809F2B4
	ldr r0, [sp, 0x10]
	strh r0, [r4]
	strh r0, [r5]
	strh r0, [r1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F242
	ldr r1, _0809F2B8
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r4, 0
	ldrsh r3, [r5, r4]
	ldr r4, _0809F2BC
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
_0809F242:
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl GroundSprite_Reset
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
	ldrb r2, [r6, 0xC]
	ldr r1, _0809F2C0
	ldr r0, [sp, 0x58]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x58]
	add r1, sp, 0x8
	ldrh r2, [r1, 0x2]
	lsls r2, 24
	lsrs r2, 16
	ldr r1, _0809F2C4
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x58]
	movs r2, 0
	ldrsh r0, [r5, r2]
	add r1, sp, 0x58
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl GroundMap_SelectDungeon
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl GroundLink_Select
	movs r4, 0
	ldrsh r0, [r5, r4]
	movs r1, 0
	movs r2, 0
	bl GroundLives_Select
	movs r1, 0
	ldrsh r0, [r5, r1]
_0809F2A0:
	movs r1, 0
	movs r2, 0
	bl GroundObject_Select
	b _0809EAE0
	.align 2, 0
_0809F2AC: .4byte gUnknown_2039A34
_0809F2B0: .4byte gUnknown_2039A32
_0809F2B4: .4byte gUnknown_2039A30
_0809F2B8: .4byte gUnknown_8116664
_0809F2BC: .4byte gUnknown_811BAF4
_0809F2C0: .4byte 0xffffff00
_0809F2C4: .4byte 0xffff00ff
_0809F2C8:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl GroundWeather_Select
	bl _0809EAE0
_0809F2D6:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809F2E8
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	b _0809F2EE
_0809F2E8:
	mov r3, r10
	movs r4, 0xC
	ldrsh r0, [r3, r4]
_0809F2EE:
	adds r6, r0, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F302
	add r0, sp, 0x8
	movs r1, 0x1
	ldrsb r1, [r0, r1]
	b _0809F308
_0809F302:
	mov r5, r10
	movs r1, 0xE
	ldrsb r1, [r5, r1]
_0809F308:
	adds r5, r1, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	subs r0, 0xC
	cmp r0, 0x9
	bls _0809F318
	bl _0809EAE0
_0809F318:
	lsls r0, 2
	ldr r1, _0809F324
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809F324: .4byte _0809F328
	.align 2, 0
_0809F328:
	.4byte _0809F350
	.4byte _0809F380
	.4byte _0809F398
	.4byte _0809F3B0
	.4byte _0809F3C8
	.4byte _0809F3E0
	.4byte _0809F3FA
	.4byte _0809F406
	.4byte _0809F412
	.4byte _0809F41E
_0809F350:
	ldr r4, _0809F37C
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundLives_Select
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundObject_Select
	movs r3, 0
	ldrsh r0, [r4, r3]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEffect_Select
	movs r1, 0
	ldrsh r0, [r4, r1]
	b _0809F3CE
	.align 2, 0
_0809F37C: .4byte gUnknown_2039A32
_0809F380:
	ldr r0, _0809F394
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundLives_Select
	bl _0809EAE0
	.align 2, 0
_0809F394: .4byte gUnknown_2039A32
_0809F398:
	ldr r0, _0809F3AC
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundObject_Select
	bl _0809EAE0
	.align 2, 0
_0809F3AC: .4byte gUnknown_2039A32
_0809F3B0:
	ldr r0, _0809F3C4
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEffect_Select
	bl _0809EAE0
	.align 2, 0
_0809F3C4: .4byte gUnknown_2039A32
_0809F3C8:
	ldr r0, _0809F3DC
	movs r1, 0
	ldrsh r0, [r0, r1]
_0809F3CE:
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEvent_Select
	bl _0809EAE0
	.align 2, 0
_0809F3DC: .4byte gUnknown_2039A32
_0809F3E0:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundLives_Cancel
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundObject_Cancel
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEffect_Cancel
	b _0809F41E
_0809F3FA:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundLives_Cancel
	bl _0809EAE0
_0809F406:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundObject_Cancel
	bl _0809EAE0
_0809F412:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEffect_Cancel
	bl _0809EAE0
_0809F41E:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEvent_Cancel
	bl _0809EAE0
_0809F42A:
	bl sub_80A79FC
	bl _0809EAE0
_0809F432:
	bl GroundObject_CancelBlank
	bl _0809EAE0
_0809F43A:
	bl GroundEffect_CancelBlank
	bl _0809EAE0
_0809F442:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x18
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r6, sp, 0x1C
	ldr r0, [sp, 0x10]
	add r5, sp, 0x34
	movs r2, 0
	strb r0, [r5]
	ldrb r1, [r4]
	mov r0, sp
	adds r0, 0x35
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	str r2, [sp, 0x38]
	add r4, sp, 0x3C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	bl memset
	ldr r2, _0809F4AC
	ldr r1, [sp, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	str r0, [r4, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x18
	bl memcpy
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	adds r1, r6, 0
	cmp r0, 0
	blt _0809F4B0
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	b _0809F4B6
	.align 2, 0
_0809F4AC: .4byte gFunctionScriptTable
_0809F4B0:
	mov r4, r10
	movs r5, 0xC
	ldrsh r2, [r4, r5]
_0809F4B6:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F4C8
	add r0, sp, 0x8
	movs r3, 0x1
	ldrsb r3, [r0, r3]
	b _0809F4CE
_0809F4C8:
	mov r0, r10
	movs r3, 0xE
	ldrsb r3, [r0, r3]
_0809F4CE:
	movs r0, 0x1
	negs r0, r0
	bl GroundObject_Add
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _0809F4E2
	bl _0809EAE0
_0809F4E2:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x5C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AC49C
	bl _0809EAE0
_0809F4FE:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r4, sp, 0x4C
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0x1C
	ldr r0, [sp, 0x10]
	add r1, sp, 0x28
	movs r3, 0
	strb r0, [r1]
	ldrb r2, [r4]
	mov r0, sp
	adds r0, 0x29
	strb r2, [r0]
	adds r0, 0x1
	movs r2, 0x1
	strb r2, [r0]
	adds r0, 0x1
	strb r2, [r0]
	str r3, [sp, 0x2C]
	ldr r3, _0809F55C
	ldr r2, [sp, 0xC]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, 0x8
	adds r0, r3
	ldr r0, [r0]
	str r0, [sp, 0x30]
	adds r0, r5, 0
	movs r2, 0xC
	bl memcpy
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	adds r1, r5, 0
	cmp r0, 0
	blt _0809F560
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	b _0809F566
	.align 2, 0
_0809F55C: .4byte gFunctionScriptTable
_0809F560:
	mov r5, r10
	movs r0, 0xC
	ldrsh r2, [r5, r0]
_0809F566:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F578
	add r0, sp, 0x8
	movs r3, 0x1
	ldrsb r3, [r0, r3]
	b _0809F57E
_0809F578:
	mov r4, r10
	movs r3, 0xE
	ldrsb r3, [r4, r3]
_0809F57E:
	movs r0, 0x1
	negs r0, r0
	bl GroundEffect_Add
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _0809F592
	bl _0809EAE0
_0809F592:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	add r4, sp, 0x64
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AD3B4
	bl _0809EAE0
_0809F5AE:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	movs r1, 0x1
	bl GroundMap_ExecuteEvent
	bl _0809EAE0
_0809F5BE:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	b _0809F712
_0809F5C6:
	ldr r1, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809F5D6
	lsls r0, r1, 16
	asrs r0, 16
	b _0809F5DC
_0809F5D6:
	ldr r0, _0809F5F0
	movs r3, 0
	ldrsh r0, [r0, r3]
_0809F5DC:
	adds r4, r0, 0
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809F5F4
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	b _0809F5FA
	.align 2, 0
_0809F5F0: .4byte gUnknown_2039A30
_0809F5F4:
	mov r0, r10
	movs r2, 0xC
	ldrsh r1, [r0, r2]
_0809F5FA:
	adds r6, r1, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F60E
	add r0, sp, 0x8
	movs r5, 0x1
	ldrsb r5, [r0, r5]
	b _0809F614
_0809F60E:
	mov r3, r10
	movs r5, 0xE
	ldrsb r5, [r3, r5]
_0809F614:
	adds r0, r4, 0
	bl sub_80A4D7C
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x1E
	bne _0809F62A
	movs r3, 0x1
_0809F62A:
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundMap_ExecuteStation
	ldr r1, _0809F65C
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r4
	bne _0809F642
	bl _0809EAE0
_0809F642:
	strh r4, [r1]
	bl sub_809D940
	mov r1, r9
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809F656
	bl _0809EAE0
_0809F656:
	bl _080A142C
	.align 2, 0
_0809F65C: .4byte gUnknown_2039A34
_0809F660:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2608
	adds r5, r0, 0
	lsls r2, r4, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x30
	bl sub_8001784
	cmp r0, 0
	bne _0809F68A
	movs r3, 0x6
	ldrsh r5, [r5, r3]
	b _0809F68E
_0809F68A:
	movs r0, 0x8
	ldrsh r5, [r5, r0]
_0809F68E:
	adds r0, r4, 0
	subs r0, 0x37
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x10
	bls _0809F6DC
	adds r0, r4, 0
	bl sub_80A2750
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0809F6DC
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0809F6D8
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F6C6
	ldr r1, _0809F6D4
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809F6C6:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GroundMainRescueRequest
	bl _0809EAE0
	.align 2, 0
_0809F6D4: .4byte gUnknown_8116684
_0809F6D8:
	adds r0, r5, 0
	b _0809F712
_0809F6DC:
	movs r1, 0x1
	negs r1, r1
	adds r0, r4, 0
	bl GroundMainRescueRequest
	bl _0809EAE0
_0809F6EA:
	mov r1, r9
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0809F71C
	cmp r0, 0x1
	bgt _0809F700
	cmp r0, 0
	beq _0809F70C
	bl _0809EAE0
_0809F700:
	cmp r0, 0x2
	beq _0809F73E
	cmp r0, 0x3
	beq _0809F762
	bl _0809EAE0
_0809F70C:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
_0809F712:
	movs r1, 0
	bl GroundMap_ExecuteEvent
	bl _0809EAE0
_0809F71C:
	add r4, sp, 0x1C
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r1, r9
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundLives_ExecuteScript
	bl _0809EAE0
_0809F73E:
	add r4, sp, 0x28
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r5, r9
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	mov r1, r9
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundObject_ExecuteScript
	bl _0809EAE0
_0809F762:
	add r4, sp, 0x34
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r5, r9
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	mov r1, r9
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundEffect_ExecuteScript
	bl _0809EAE0
_0809F786:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	cmp r0, 0
	bge _0809F79E
	bl _0809EAE0
_0809F79E:
	add r1, sp, 0x6C
	bl sub_80A8BD8
	ldr r0, [sp, 0x6C]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _0809F818
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r7, sp, 0x70
	ldr r2, [r1, 0xC]
	adds r1, r7, 0
	bl _call_via_r2
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r5, sp, 0x78
	ldr r2, [r1, 0x8]
	adds r1, r5, 0
	bl _call_via_r2
	add r6, sp, 0x80
	mov r0, r8
	adds r1, r6, 0
	bl sub_80A8FD8
	add r4, sp, 0x88
	mov r0, r8
	adds r1, r4, 0
	bl sub_80A8F9C
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	adds r4, r1, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809F812
	ldr r3, _0809F82C
	adds r0, r7, 0
	adds r1, r3, 0
	adds r2, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, r4
	beq _0809F818
_0809F812:
	mov r0, r8
	bl sub_80A9090
_0809F818:
	mov r4, r9
	movs r5, 0xA
	ldrsh r0, [r4, r5]
	mov r1, r8
	bl GroundLives_ExecutePlayerScriptActionLives
	movs r0, 0x3
	bl _080A142E
	.align 2, 0
_0809F82C: .4byte gUnknown_81164DC
_0809F830:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80999E8
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F842:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80999FC
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F854:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	lsrs r2, 16
	bl sub_8099A10
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F872:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_8099A34
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F884:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_8099A48
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F896:
	ldr r0, [sp, 0x10]
	asrs r0, 16
	add r1, sp, 0x20
	movs r2, 0
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	asrs r0, 8
	adds r1, 0x1
	strb r0, [r1]
	ldr r1, [sp, 0x10]
	mov r0, sp
	adds r0, 0x22
	strb r1, [r0]
	adds r0, 0x1
	strb r2, [r0]
	ldr r2, [sp, 0x20]
	str r2, [sp, 0x1C]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x27
	beq _0809F8C6
	cmp r0, 0x28
	beq _0809F8D4
	b _0809F8E0
_0809F8C6:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	bl sub_8099A5C
	b _0809F8E0
_0809F8D4:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	bl sub_8099AFC
_0809F8E0:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F8E8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	bl sub_809A6E4
	bl _0809EAE0
_0809F8F4:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	bl sub_809A6F8
	bl _0809EAE0
_0809F900:
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	bl sub_809A738
	bl _0809EAE0
_0809F90C:
	bl sub_809A768
	lsls r0, 24
	cmp r0, 0
	bne _0809F91A
	bl _0809EAE0
_0809F91A:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809F92E:
	bl sub_809A76C
	bl _0809EAE0
_0809F936:
	bl sub_809A7B4
	bl _0809EAE0
_0809F93E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0xA
	bls _0809F94A
	bl _0809EAE0
_0809F94A:
	lsls r0, 2
	ldr r1, _0809F954
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809F954: .4byte _0809F958
	.align 2, 0
_0809F958:
	.4byte _0809F984
	.4byte _0809F992
	.4byte _0809F9A4
	.4byte _0809F9B6
	.4byte _0809F9D8
	.4byte _0809F9EA
	.4byte _0809F9FC
	.4byte _0809FA44
	.4byte _0809FA56
	.4byte _0809FA68
	.4byte _0809FAB0
_0809F984:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_809A83C
	bl _0809EAE0
_0809F992:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A2500
	bl _0809EAE0
_0809F9A4:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A2500
	bl _0809EAE0
_0809F9B6:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	add r1, sp, 0x90
	lsls r0, 16
	movs r2, 0x1
	orrs r0, r2
	str r0, [r1]
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80A2500
	bl _0809EAE0
_0809F9D8:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A252C
	bl _0809EAE0
_0809F9EA:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A252C
	bl _0809EAE0
_0809F9FC:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	add r1, sp, 0x94
	ldrh r2, [r1]
	orrs r2, r0
	str r2, [r1]
	cmp r2, 0
	blt _0809FA30
	ldr r0, _0809FA2C
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	str r2, [r1]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_80A252C
	bl _0809EAE0
	.align 2, 0
_0809FA2C: .4byte 0xffff0000
_0809FA30:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_80A2584
	bl _0809EAE0
_0809FA44:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A2558
	bl _0809EAE0
_0809FA56:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A2558
	bl _0809EAE0
_0809FA68:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	add r1, sp, 0x98
	ldrh r2, [r1]
	orrs r2, r0
	str r2, [r1]
	cmp r2, 0
	blt _0809FA9C
	ldr r0, _0809FA98
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	str r2, [r1]
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_80A2558
	bl _0809EAE0
	.align 2, 0
_0809FA98: .4byte 0xffff0000
_0809FA9C:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_80A2598
	bl _0809EAE0
_0809FAB0:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2740
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _0809FAD0
	cmp r0, 0x2
	beq _0809FAD4
	b _0809FAD8
_0809FAD0:
	movs r4, 0x1
	b _0809FAD8
_0809FAD4:
	movs r4, 0x1
	negs r4, r4
_0809FAD8:
	adds r0, r1, 0
	bl GetDungeonFloorCount
	ldr r2, _0809FAF4
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	lsls r1, 2
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	bl _0809EAE0
	.align 2, 0
_0809FAF4: .4byte gUnknown_202DE30
_0809FAF8:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	asrs r1, 24
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl sub_809AC7C
	bl _0809EAE0
_0809FB10:
	ldr r0, [sp, 0xC]
	add r1, sp, 0x9C
	str r0, [r1]
	ldr r0, [sp, 0x10]
	str r0, [r1, 0x4]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_809ADD8
	bl _0809EAE0
_0809FB28:
	movs r1, 0
	ldrb r0, [r2]
	subs r0, 0x32
	cmp r0, 0x6
	bhi _0809FBBE
	lsls r0, 2
	ldr r1, _0809FB3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809FB3C: .4byte _0809FB40
	.align 2, 0
_0809FB40:
	.4byte _0809FB5C
	.4byte _0809FB6C
	.4byte _0809FB7C
	.4byte _0809FB8C
	.4byte _0809FB9C
	.4byte _0809FBAC
	.4byte _0809FBB4
_0809FB5C:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0x14]
	movs r0, 0
	bl sub_809AE90
	b _0809FBBA
_0809FB6C:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	ldr r2, [sp, 0x14]
	movs r0, 0x1
	bl sub_809AE90
	b _0809FBBA
_0809FB7C:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	ldr r2, [sp, 0x14]
	movs r0, 0x2
	bl sub_809AE90
	b _0809FBBA
_0809FB8C:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	ldr r2, [sp, 0x14]
	movs r0, 0x3
	bl sub_809AE90
	b _0809FBBA
_0809FB9C:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0x14]
	movs r0, 0x4
	bl sub_809AE90
	b _0809FBBA
_0809FBAC:
	ldr r0, [sp, 0x14]
	bl sub_809AEEC
	b _0809FBBA
_0809FBB4:
	ldr r0, [sp, 0x14]
	bl sub_809AF2C
_0809FBBA:
	lsls r0, 24
	lsrs r1, r0, 24
_0809FBBE:
	cmp r1, 0
	bne _0809FBC6
	bl _0809EAE0
_0809FBC6:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809FBDA:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0x14]
	bl sub_809AF6C
	lsls r0, 24
	cmp r0, 0
	bne _0809FBF0
	bl _0809EAE0
_0809FBF0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _0809FBFE
	bl _0809EAE0
_0809FBFE:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809FC12:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	lsls r2, 16
	asrs r2, 16
	ldr r3, [sp, 0x14]
	bl sub_809AFC8
	bl _080A1280
_0809FC2E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	bl sub_809B1D4
	bl _080A1292
_0809FC40:
	movs r0, 0
	bl _080A0654
_0809FC46:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809FC90
	adds r0, r1, 0
	bl sub_80A8D54
	cmp r0, 0
	bne _0809FC62
	bl _0809EAE0
_0809FC62:
	movs r3, 0
	ldr r2, _0809FC8C
	adds r5, r2, 0
	adds r4, r0, 0
	adds r4, 0x4C
_0809FC6C:
	adds r0, r3, r5
	adds r1, r4, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _0809FC6C
	movs r0, 0
	strb r0, [r2, 0xA]
	movs r0, 0x4
	movs r1, 0
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FC8C: .4byte gUnknown_2039D98
_0809FC90:
	ldr r2, _0809FCA0
	movs r0, 0x4
	movs r1, 0x1
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCA0: .4byte gUnknown_2039D98
_0809FCA4:
	ldr r4, _0809FCC0
	adds r0, r4, 0
	bl sub_80920B8
	movs r0, 0
	strb r0, [r4, 0xA]
	movs r0, 0x5
	movs r1, 0
	adds r2, r4, 0
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCC0: .4byte gUnknown_2039D98
_0809FCC4:
	ldr r2, _0809FCE4
	adds r3, r2, 0
	movs r1, 0
	adds r0, r2, 0
	adds r0, 0xB
_0809FCCE:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r3
	bge _0809FCCE
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	movs r0, 0x6
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCE4: .4byte gUnknown_2039D98
_0809FCE8:
	bl StopAllMusic_1
	bl _0809EAE0
_0809FCF0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FD00
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _0809FD02
_0809FD00:
	movs r0, 0x1E
_0809FD02:
	bl FadeOutAllMusic
	bl _0809EAE0
_0809FD0A:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD1E
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD20
_0809FD1E:
	ldr r0, [sp, 0xC]
_0809FD20:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _0809FD34
	cmp r1, r0
	beq _0809FDA0
	adds r0, r1, 0
	bl xxx_call_start_new_bgm
	bl _0809EAE0
	.align 2, 0
_0809FD34: .4byte 0x000003e7
_0809FD38:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD4C
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD4E
_0809FD4C:
	ldr r0, [sp, 0xC]
_0809FD4E:
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, _0809FD68
	cmp r2, r0
	beq _0809FDA0
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	adds r0, r2, 0
	bl xxx_call_fade_in_new_bgm
	bl _0809EAE0
	.align 2, 0
_0809FD68: .4byte 0x000003e7
_0809FD6C:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD80
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD82
_0809FD80:
	ldr r0, [sp, 0xC]
_0809FD82:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _0809FD9C
	cmp r1, r0
	bne _0809FD90
	bl _0809EAE0
_0809FD90:
	adds r0, r1, 0
	bl xxx_call_queue_bgm
	bl _0809EAE0
	.align 2, 0
_0809FD9C: .4byte 0x000003e7
_0809FDA0:
	bl xxx_call_stop_bgm
	bl _0809EAE0
_0809FDA8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FDB8
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _0809FDBA
_0809FDB8:
	movs r0, 0x1E
_0809FDBA:
	bl xxx_call_fade_out_bgm
	bl _0809EAE0
_0809FDC2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 1
	bl xxx_call_play_fanfare_se
	bl _0809EAE0
_0809FDD4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl xxx_call_stop_fanfare_se
	bl _0809EAE0
_0809FDE2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r2, r0, 16
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FDF8
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	b _0809FDFA
_0809FDF8:
	movs r1, 0x1E
_0809FDFA:
	adds r0, r2, 0
	bl xxx_call_fade_out_fanfare_se
	bl _0809EAE0
_0809FE04:
	mov r1, r9
	adds r1, 0x84
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, 0x1
	bne _0809FE16
	adds r0, r1, 0
	bl InitScriptData
_0809FE16:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x1C]
	movs r1, 0
	bl _call_via_r2
	bl _0809EAE0
_0809FE28:
	mov r0, r9
	adds r0, 0xC
	bl sub_809D52C
	adds r4, r0, 0
	cmp r4, 0
	bne _0809FE3A
	bl _0809EAE0
_0809FE3A:
	ldr r1, [r4]
	mov r2, r9
	ldr r0, [r2, 0x4]
	add r5, sp, 0xA4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r4]
	mov r3, r9
	ldr r0, [r3, 0x4]
	mov r4, sp
	adds r4, 0x4D
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldrb r0, [r4]
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r1, r9
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	movs r1, 0
	ldrsb r1, [r4, r1]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	bl _0809EAE0
_0809FE86:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r6, sp, 0xAC
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r4, sp, 0xB4
	add r5, sp, 0xBC
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80AD914
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r3, [r1, 0x20]
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	bl _0809EAE0
_0809FEBE:
	mov r1, r9
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	ldr r1, [sp, 0xC]
	ldr r2, [r2, 0x3C]
	bl _call_via_r2
	bl _0809EAE0
_0809FED0:
	ldr r0, [sp, 0xC]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0809FEEE
	mov r1, r9
	adds r1, 0x84
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _0809FEEE
	adds r0, r1, 0
	bl InitScriptData
_0809FEEE:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldr r1, [sp, 0xC]
	ldr r2, [r2, 0x40]
	bl _call_via_r2
	bl _0809EAE0
_0809FF00:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r9
	adds r1, 0x4A
	ldr r2, [r2, 0x14]
	bl _call_via_r2
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	cmp r1, 0
	beq _0809FF1E
	mov r0, r9
	adds r0, 0x48
	strh r1, [r0]
_0809FF1E:
	mov r5, r9
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	bl _0809EAE0
_0809FF32:
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	ldr r2, [r2, 0x34]
	bl _call_via_r2
	bl _0809EAE0
_0809FF46:
	mov r1, r9
	ldr r3, [r1]
	ldr r0, [r1, 0x4]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	add r2, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r2, r4]
	ldr r3, [r3, 0x38]
	bl _call_via_r3
	bl _0809EAE0
_0809FF62:
	mov r5, r9
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	ldr r2, [r2, 0x44]
	bl _call_via_r2
	bl _0809EAE0
_0809FF78:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	add r1, sp, 0xC4
	str r0, [r1]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	str r0, [r1, 0x4]
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	ldr r2, [r2, 0x24]
	bl _call_via_r2
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	mov r5, r10
	b _080A05EA
_0809FF9A:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	lsls r0, 8
	add r1, sp, 0xCC
	str r0, [r1]
	ldr r0, [sp, 0xC]
	lsls r0, 8
	str r0, [r1, 0x4]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	b _080A0650
_0809FFBA:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl OtherRandInt
	lsls r0, 8
	add r4, sp, 0xD4
	str r0, [r4]
	ldr r0, [sp, 0xC]
	bl OtherRandInt
	lsls r0, 8
	str r0, [r4, 0x4]
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A07B4
_0809FFE4:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0xDC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A0650
_080A0010:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r6, sp, 0xE4
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	add r4, sp, 0xEC
	add r5, sp, 0xF4
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80AD914
	ldr r0, [r5]
	ldr r1, [r4]
	subs r0, r1
	bl OtherRandInt
	ldr r1, [r4]
	adds r1, r0
	str r1, [r6]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x4]
	subs r0, r1
	bl OtherRandInt
	ldr r1, [r4, 0x4]
	adds r1, r0
	str r1, [r6, 0x4]
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r6, 0
	bl _call_via_r2
	b _080A07B4
_080A0064:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A007A
	bl _0809EAE0
_080A007A:
	add r4, sp, 0xFC
	adds r1, r4, 0
	bl sub_80A8FD8
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r4, 0
	bl _call_via_r2
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	b _080A03F0
_080A0096:
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x32
	bl sub_8001784
	add r5, sp, 0x104
	str r0, [r5]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x33
	bl sub_8001784
	str r0, [r5, 0x4]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x34
	bl sub_8001784
	adds r6, r0, 0
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x35
	bl sub_8001784
	adds r4, r0, 0
	lsls r4, 24
	asrs r4, 24
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r2, [r1, 0x28]
	adds r1, r6, 0
	bl _call_via_r2
	mov r0, r9
	adds r0, 0x4A
	strb r4, [r0]
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r1, 0x2C]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A0650
_080A010E:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r4, sp, 0x10C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r3, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x114
	add r2, sp, 0x118
	ldr r3, [r3, 0x10]
	bl _call_via_r3
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r5, sp
	adds r5, 0x4E
	ldr r2, [r1, 0x14]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	add r0, sp, 0x10C
	ldr r3, [r0]
	movs r0, 0
	movs r1, 0x32
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	ldr r3, [r4, 0x4]
	movs r0, 0
	movs r1, 0x33
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	add r0, sp, 0x114
	ldr r3, [r0]
	movs r0, 0
	movs r1, 0x34
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r3, 0
	ldrsb r3, [r5, r3]
	movs r0, 0
	movs r1, 0x35
	bl sub_800199C
	bl _0809EAE0
_080A0186:
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [sp, 0xC]
	lsls r1, 8
	ldr r2, [r2, 0x28]
	bl _call_via_r2
	b _080A07B4
_080A0198:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r2, r10
	str r0, [r2, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	str r0, [r2, 0x40]
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	str r0, [r2, 0x30]
	ldr r0, _080A01B4
	bl _080A12AE
	.align 2, 0
_080A01B4: .4byte 0x0000ffff
_080A01B8:
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x11C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r1, [sp, 0xC]
	lsls r1, 8
	add r0, sp, 0x11C
	ldr r0, [r0]
	adds r0, r1
	mov r5, r10
	str r0, [r5, 0x3C]
	ldr r1, [sp, 0x10]
	lsls r1, 8
	ldr r0, [r4, 0x4]
	adds r0, r1
	str r0, [r5, 0x40]
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r5, 0x30]
	ldr r0, _080A01EC
	b _080A05EA
	.align 2, 0
_080A01EC: .4byte 0x0000ffff
_080A01F0:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r4, r10
	str r0, [r4, 0x30]
	ldr r0, _080A021C
	b _080A0656
	.align 2, 0
_080A021C: .4byte 0x0000ffff
_080A0220:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r2, r10
	str r0, [r2, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A12AE
_080A0250:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r5, r10
	str r0, [r5, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl OtherRandInt
	b _080A05EA
_080A0282:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A0298
	bl _0809EAE0
_080A0298:
	mov r1, r10
	adds r1, 0x3C
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r2, r10
	str r0, [r2, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A12AE
_080A02B2:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r1, r0, 8
	mov r4, r10
	str r1, [r4, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r2, r0, 8
	str r2, [r4, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7D
	beq _080A02DC
	cmp r0, 0x83
	bne _080A0304
_080A02DC:
	mov r5, r10
	ldr r0, [r5, 0x34]
	subs r0, r1, r0
	ldr r1, [r5, 0x38]
	subs r1, r2, r1
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0300
	bl _0809F0C4
_080A0300:
	movs r0, 0x1
	b _080A05EA
_080A0304:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r3, r10
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A0310:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r5, r10
	ldr r4, [r5, 0x34]
	adds r3, r4, r0
	str r3, [r5, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	ldr r2, [r5, 0x38]
	adds r1, r2, r0
	str r1, [r5, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7E
	beq _080A0342
	cmp r0, 0x84
	bne _080A036A
_080A0342:
	subs r0, r3, r4
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	mov r3, r10
	strh r0, [r3, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0362
	bl _0809F0C4
_080A0362:
	movs r0, 0x1
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A036A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A0654
_080A0370:
	ldr r4, [sp, 0xC]
	lsls r4, 1
	subs r4, 0x1
	ldr r5, [sp, 0x10]
	lsls r5, 1
	subs r5, 0x1
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	adds r0, r4, 0
	bl OtherRandInt
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	subs r0, r1
	lsls r0, 8
	mov r3, r10
	ldr r1, [r3, 0x34]
	adds r1, r0
	str r1, [r3, 0x3C]
	adds r0, r5, 0
	bl OtherRandInt
	ldr r1, [sp, 0xC]
	subs r0, r1
	lsls r0, 8
	mov r4, r10
	ldr r3, [r4, 0x38]
	adds r2, r3, r0
	str r2, [r4, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7F
	beq _080A03C4
	cmp r0, 0x85
	bne _080A03EC
_080A03C4:
	mov r5, r10
	ldr r0, [r5, 0x3C]
	ldr r1, [r5, 0x34]
	subs r0, r1
	subs r1, r2, r3
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A03E8
	bl _0809F0C4
_080A03E8:
	movs r0, 0x1
	b _080A05EA
_080A03EC:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
_080A03F0:
	mov r3, r10
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A03F8:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	mov r5, r10
	ldr r0, [r5, 0x34]
	ldr r1, [r5, 0x38]
	mov r2, r10
	str r0, [r2, 0x3C]
	str r1, [r2, 0x40]
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	mov r1, r10
	adds r1, 0x3C
	bl sub_80AD8B4
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x80
	beq _080A042E
	cmp r0, 0x86
	bne _080A045C
_080A042E:
	mov r3, r10
	ldr r0, [r3, 0x3C]
	ldr r1, [r3, 0x34]
	subs r0, r1
	ldr r1, [r3, 0x40]
	ldr r2, [r3, 0x38]
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl __divsi3
	mov r5, r10
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0458
	bl _0809F0C4
_080A0458:
	movs r0, 0x1
	b _080A05EA
_080A045C:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A0462:
	ldr r4, [sp, 0xC]
	lsls r4, 1
	subs r4, 0x1
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r5, r10
	adds r5, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r0, [sp, 0x10]
	lsls r0, 16
	asrs r0, 16
	adds r1, r5, 0
	bl sub_80AD8B4
	adds r0, r4, 0
	bl OtherRandInt
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	subs r0, r1
	lsls r0, 8
	mov r5, r10
	ldr r1, [r5, 0x3C]
	adds r1, r0
	str r1, [r5, 0x3C]
	adds r0, r4, 0
	bl OtherRandInt
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	subs r0, r1
	lsls r0, 8
	ldr r1, [r5, 0x40]
	adds r2, r1, r0
	str r2, [r5, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x81
	beq _080A04C0
	cmp r0, 0x87
	bne _080A04EC
_080A04C0:
	mov r3, r10
	ldr r0, [r3, 0x3C]
	ldr r1, [r3, 0x34]
	subs r0, r1
	ldr r1, [r3, 0x38]
	subs r1, r2, r1
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl __divsi3
	mov r5, r10
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A04E8
	bl _0809F0C4
_080A04E8:
	movs r0, 0x1
	b _080A05EA
_080A04EC:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A04F2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	bge _080A0508
	bl _0809EAE0
_080A0508:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	mov r1, r10
	adds r1, 0x3C
	adds r0, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x82
	beq _080A052E
	cmp r0, 0x88
	bne _080A055A
_080A052E:
	mov r4, r10
	ldr r0, [r4, 0x3C]
	ldr r1, [r4, 0x34]
	subs r0, r1
	ldr r1, [r4, 0x40]
	ldr r2, [r4, 0x38]
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl __divsi3
	strh r0, [r4, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0556
	bl _0809F0C4
_080A0556:
	movs r0, 0x1
	b _080A0656
_080A055A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A0560:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r2, r10
	str r0, [r2, 0x48]
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	str r0, [r2, 0x30]
	ldr r0, _080A0578
	bl _080A12AE
	.align 2, 0
_080A0578: .4byte 0x0000ffff
_080A057C:
	ldr r1, [sp, 0xC]
	mov r0, r9
	adds r0, 0x4A
	strb r1, [r0]
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	mov r1, r10
	str r0, [r1, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	b _080A07BA
_080A05A4:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r4, sp
	adds r4, 0x4F
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r5, r10
	str r0, [r5, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A05EA:
	strh r0, [r5, 0x2A]
	bl _0809F0C4
_080A05F0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
_080A0600:
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	b _080A07B4
_080A060E:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080A0650
	add r4, sp, 0x50
	adds r1, r4, 0
	bl sub_80A9050
	movs r0, 0
	ldrsb r0, [r4, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_080A0650:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A0654:
	mov r4, r10
_080A0656:
	strh r0, [r4, 0x2A]
	bl _0809F0C4
_080A065C:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r4, sp
	adds r4, 0x51
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	b _080A0600
_080A068A:
	movs r5, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x8F
	beq _080A06CA
	cmp r0, 0x8F
	bgt _080A069E
	cmp r0, 0x8E
	beq _080A06A4
	b _080A0724
_080A069E:
	cmp r0, 0x90
	beq _080A06F8
	b _080A0724
_080A06A4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080A0724
	movs r5, 0x1
	add r1, sp, 0x124
	adds r0, r4, 0
	bl sub_80A8FD8
	add r1, sp, 0x12C
	adds r0, r4, 0
	bl sub_80A8F9C
	b _080A0724
_080A06CA:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080A0724
	movs r5, 0x1
	add r1, sp, 0x124
	bl sub_80A8FD8
	ldr r0, _080A06F4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x12C
	str r0, [r2]
	str r1, [r2, 0x4]
	b _080A0724
	.align 2, 0
_080A06F4: .4byte gUnknown_81164DC
_080A06F8:
	movs r5, 0x1
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x124
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	add r1, sp, 0x12C
	ldr r2, [r2, 0x8]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
_080A0724:
	cmp r5, 0
	beq _080A07B4
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r5, sp, 0x134
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x13C
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r7, sp, 0x124
	add r3, sp, 0x12C
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_8002DF0
	mov r1, sp
	adds r1, 0x52
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	movs r4, 0
	ldrsb r4, [r1, r4]
	adds r6, r1, 0
	cmp r4, r0
	bne _080A078C
	ldr r3, _080A07C0
	adds r0, r5, 0
	adds r1, r3, 0
	adds r2, r7, 0
	bl sub_8002D54
	strb r0, [r6]
	movs r0, 0
	ldrsb r0, [r6, r0]
	cmp r0, r4
	bne _080A078C
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r2, [r1, 0x14]
	adds r1, r6, 0
	bl _call_via_r2
_080A078C:
	movs r0, 0
	ldrsb r0, [r6, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_080A07B4:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A07B8:
	mov r1, r10
_080A07BA:
	strh r0, [r1, 0x2A]
	bl _0809F0C4
	.align 2, 0
_080A07C0: .4byte gUnknown_81164DC
_080A07C4:
	movs r0, 0
	bl _080A12AC
_080A07CA:
	ldr r0, [sp, 0xC]
	mov r1, r9
	adds r1, 0x71
	movs r2, 0
	strb r0, [r1]
	mov r3, r10
	strh r2, [r3, 0x2A]
	bl _0809F0C4
_080A07DC:
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	mov r4, sp
	adds r4, 0x53
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x71
	movs r2, 0
	strb r0, [r1]
	mov r5, r10
	strh r2, [r5, 0x2A]
	bl _0809F0C4
_080A080C:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_809D124
	bl _0809EAE0
_080A081E:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	mov r3, r9
	movs r4, 0x8
	ldrsh r0, [r3, r4]
	cmp r0, 0x2
	beq _080A0856
	cmp r0, 0x2
	bgt _080A0844
	cmp r0, 0x1
	beq _080A084C
	bl _0809EAE0
_080A0844:
	cmp r0, 0x3
	beq _080A0860
	bl _0809EAE0
_080A084C:
	movs r0, 0x1
	bl sub_809D170
	bl _0809EAE0
_080A0856:
	movs r0, 0x2
	bl sub_809D170
	bl _0809EAE0
_080A0860:
	movs r0, 0x3
	bl sub_809D170
	bl _0809EAE0
_080A086A:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x8
	ldrsh r1, [r5, r2]
	cmp r1, 0x2
	beq _080A08A0
	cmp r1, 0x2
	bgt _080A088E
	cmp r1, 0x1
	beq _080A0896
	bl _0809EAE0
_080A088E:
	cmp r1, 0x3
	beq _080A08AA
	bl _0809EAE0
_080A0896:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80A8FD8
	b _080A08B2
_080A08A0:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80AC448
	b _080A08B2
_080A08AA:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80AD360
_080A08B2:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D158
	bl _0809EAE0
_080A08BE:
	movs r0, 0x1
	movs r1, 0
	bl sub_809D170
	bl _0809EAE0
_080A08CA:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A08E2
	bl _0809EAE0
_080A08E2:
	mov r4, r9
	movs r5, 0x8
	ldrsh r0, [r4, r5]
	cmp r0, 0x2
	beq _080A090A
	cmp r0, 0x2
	bgt _080A08F8
	cmp r0, 0x1
	beq _080A0900
	bl _0809EAE0
_080A08F8:
	cmp r0, 0x3
	beq _080A0914
	bl _0809EAE0
_080A0900:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0990
_080A090A:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0990
_080A0914:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0990
_080A091E:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A095C
	cmp r1, 0x2
	bgt _080A0944
	cmp r1, 0x1
	beq _080A094C
	bl _0809EAE0
_080A0944:
	cmp r1, 0x3
	beq _080A096C
	bl _0809EAE0
_080A094C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A097A
_080A095C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A097A
_080A096C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A097A:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D190
	bl _0809F0C4
_080A0986:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0990:
	bl sub_809D1A8
	bl _0809F0C4
_080A0998:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A09B0
	bl _0809EAE0
_080A09B0:
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r0, 0x2
	beq _080A09D6
	cmp r0, 0x2
	bgt _080A09C4
	cmp r0, 0x1
	beq _080A09CC
	bl _0809EAE0
_080A09C4:
	cmp r0, 0x3
	beq _080A09E0
	bl _0809EAE0
_080A09CC:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0A5C
_080A09D6:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0A5C
_080A09E0:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0A5C
_080A09EA:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A0A28
	cmp r1, 0x2
	bgt _080A0A10
	cmp r1, 0x1
	beq _080A0A18
	bl _0809EAE0
_080A0A10:
	cmp r1, 0x3
	beq _080A0A38
	bl _0809EAE0
_080A0A18:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A0A46
_080A0A28:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A0A46
_080A0A38:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A0A46:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D1CC
	bl _0809F0C4
_080A0A52:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0A5C:
	bl sub_809D1E4
	bl _0809F0C4
_080A0A64:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A0A7C
	bl _0809EAE0
_080A0A7C:
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r0, 0x2
	beq _080A0AA2
	cmp r0, 0x2
	bgt _080A0A90
	cmp r0, 0x1
	beq _080A0A98
	bl _0809EAE0
_080A0A90:
	cmp r0, 0x3
	beq _080A0AAC
	bl _0809EAE0
_080A0A98:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0B28
_080A0AA2:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0B28
_080A0AAC:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0B28
_080A0AB6:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A0AF4
	cmp r1, 0x2
	bgt _080A0ADC
	cmp r1, 0x1
	beq _080A0AE4
	bl _0809EAE0
_080A0ADC:
	cmp r1, 0x3
	beq _080A0B04
	bl _0809EAE0
_080A0AE4:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A0B12
_080A0AF4:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A0B12
_080A0B04:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A0B12:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D208
	bl _0809F0C4
_080A0B1E:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0B28:
	bl sub_809D220
	bl _0809F0C4
_080A0B30:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl sub_8001570
	bl _0809EAE0
_080A0B42:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_80015C0
	bl _0809EAE0
_080A0B54:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	ldr r2, [sp, 0xC]
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_800226C
	bl _0809EAE0
_080A0B6C:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	asrs r2, 16
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_80022A0
	bl _0809EAE0
_080A0B88:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	ldr r3, [sp, 0x10]
	bl sub_800199C
	bl _0809EAE0
_080A0BA2:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl ScenarioCalc
	bl _0809EAE0
_080A0BB4:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	add r1, sp, 0x164
	add r2, sp, 0x168
	bl sub_8001B88
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r1, sp, 0x164
	ldr r1, [r1]
	add r2, sp, 0x168
	ldr r2, [r2]
	adds r2, 0x1
	bl ScenarioCalc
	bl _0809EAE0
_080A0BDA:
	ldr r2, [sp, 0xC]
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0
	movs r1, 0x16
	bl sub_80018D8
	bl _0809EAE0
_080A0BF6:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0
	movs r1, 0x1C
	bl sub_80018D8
	bl _0809EAE0
_080A0C08:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80026E8
	bl _0809EAE0
_080A0C20:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_809733C
	bl _0809EAE0
_080A0C38:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80973A8
	bl _0809EAE0
_080A0C50:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_8097418
	bl _0809EAE0
_080A0C68:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80975A8
	bl _0809EAE0
_080A0C80:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80976F8
	bl _0809EAE0
_080A0C90:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0xC]
	movs r0, 0
	movs r3, 0x2
	bl sub_80022F8
	b _080A0E1E
_080A0CA2:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_80022F8
	lsls r0, 24
	cmp r0, 0
	bne _080A0CC0
	bl _0809EAE0
_080A0CC0:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _080A0D5C
_080A0CC8:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	asrs r2, 16
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_8002318
	lsls r0, 24
	cmp r0, 0
	bne _080A0CEA
	bl _0809EAE0
_080A0CEA:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	b _080A0E2C
_080A0CF2:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	lsrs r2, 16
	bl sub_8001784
	cmp r0, 0
	bne _080A0D0E
	bl _0809EAE0
_080A0D0E:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _080A0D5C
_080A0D16:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_8001AB0
	ldr r1, [sp, 0x10]
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	bne _080A0D38
	bl _0809EAE0
_080A0D38:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	b _080A0E2C
_080A0D40:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _080A0D58
	bl _0809EAE0
_080A0D58:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
_080A0D5C:
	mov r0, r9
	bl sub_80A242C
	mov r5, r10
	str r0, [r5, 0x4]
	bl _0809EAE0
_080A0D6A:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001D08
	b _080A0DBA
_080A0D7A:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	bne _080A0D92
	bl _0809EAE0
_080A0D92:
	b _080A0DF6
_080A0D94:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A0DA8
	bl _0809EAE0
_080A0DA8:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	b _080A132A
_080A0DAE:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8098100
_080A0DBA:
	lsls r0, 24
	cmp r0, 0
	bne _080A0DC4
	bl _0809EAE0
_080A0DC4:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	mov r0, r9
	bl sub_80A242C
	mov r2, r10
	str r0, [r2, 0x4]
	bl _0809EAE0
_080A0DD6:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80026CC
	b _080A0E1E
_080A0DE2:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_809CBA4
	cmp r0, 0
	bgt _080A0DF6
	bl _0809EAE0
_080A0DF6:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	mov r0, r9
	bl sub_80A242C
	mov r4, r10
	str r0, [r4, 0x4]
	bl _0809EAE0
_080A0E08:
	mov r5, r9
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080A0E16
	bl _0809EAE0
_080A0E16:
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	bl sub_80A8C98
_080A0E1E:
	lsls r0, 24
	cmp r0, 0
	bne _080A0E28
	bl _0809EAE0
_080A0E28:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
_080A0E2C:
	mov r0, r9
	bl sub_80A242C
	mov r3, r10
	str r0, [r3, 0x4]
	bl _0809EAE0
_080A0E3A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl FindItemInInventory
	cmp r0, 0
	bge _080A0E4E
	bl _0809EAE0
_080A0E4E:
	bl ShiftItemsDownFrom
	bl _0809EAE0
_080A0E56:
	add r0, sp, 0x8
	ldrb r2, [r0]
	adds r0, r2, 0
	subs r0, 0xC0
	cmp r0, 0xB
	bls _080A0E64
	b _080A1088
_080A0E64:
	lsls r0, 2
	ldr r1, _080A0E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0E70: .4byte _080A0E74
	.align 2, 0
_080A0E74:
	.4byte _080A0EA4
	.4byte _080A0EB6
	.4byte _080A0ECC
	.4byte _080A0EFA
	.4byte _080A0F08
	.4byte _080A0F14
	.4byte _080A0F26
	.4byte _080A0F36
	.4byte _080A0F98
	.4byte _080A1008
	.4byte _080A0F4C
	.4byte _080A107A
_080A0EA4:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl sub_8001658
	adds r1, r0, 0
	b _080A1098
_080A0EB6:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl sub_8001658
	ldr r1, [sp, 0xC]
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	b _080A0EF2
_080A0ECC:
	mov r4, r10
	adds r4, 0x50
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_8001658
	adds r5, r0, 0
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8001658
	adds r1, r0, 0
	add r0, sp, 0x8
	ldrb r2, [r0, 0x1]
	adds r0, r5, 0
_080A0EF2:
	bl FlagCalc
	adds r1, r0, 0
	b _080A1098
_080A0EFA:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	bl OtherRandInt
	adds r1, r0, 0
	b _080A1098
_080A0F08:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	movs r0, 0
	movs r2, 0
	b _080A0F1E
_080A0F14:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	movs r0, 0
	movs r2, 0x1
_080A0F1E:
	bl sub_8001784
	adds r1, r0, 0
	b _080A1098
_080A0F26:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A8C2C
	lsls r0, 16
	asrs r1, r0, 16
	b _080A1098
_080A0F36:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	add r4, sp, 0x54
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0
	ldrsb r1, [r4, r1]
	b _080A1098
_080A0F4C:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	movs r3, 0xB6
	lsls r3, 1
	add r3, sp
	mov r8, r3
	ldr r2, [r1, 0xC]
	mov r1, r8
	bl _call_via_r2
	add r6, sp, 0x16C
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	add r4, sp, 0x174
	str r0, [r4]
	str r1, [r4, 0x4]
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r5, r4, 0
	adds r1, r5, 0
	bl sub_80AD8B4
	ldr r1, [r4]
	ldr r0, [r6]
	subs r1, r0
	add r0, sp, 0x17C
	str r1, [r0]
	ldr r1, [r5, 0x4]
	mov r4, r8
	ldr r0, [r4, 0x4]
	subs r1, r0
	add r0, sp, 0x17C
	str r1, [r0, 0x4]
	bl sub_8002C60
	b _080A106A
_080A0F98:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r6, r0, 16
	cmp r6, 0
	blt _080A1074
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	movs r2, 0xC2
	lsls r2, 1
	add r2, sp
	mov r8, r2
	ldr r2, [r1, 0xC]
	mov r1, r8
	bl _call_via_r2
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r5, sp, 0x18C
	ldr r2, [r1, 0x8]
	adds r1, r5, 0
	bl _call_via_r2
	add r7, sp, 0x194
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80A8FD8
	add r4, sp, 0x19C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80A8F9C
	mov r0, r8
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A1098
	ldr r3, _080A1004
	mov r0, r8
	adds r1, r3, 0
	adds r2, r7, 0
	b _080A1066
	.align 2, 0
_080A1004: .4byte gUnknown_81164DC
_080A1008:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r7, r0, 16
	cmp r7, 0
	blt _080A1074
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r6, sp, 0x1A4
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x1AC
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0x1B4
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80A8FD8
	ldr r7, _080A1070
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A1098
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	adds r3, r7, 0
_080A1066:
	bl sub_8002D54
_080A106A:
	lsls r0, 24
	asrs r1, r0, 24
	b _080A1098
	.align 2, 0
_080A1070: .4byte gUnknown_81164DC
_080A1074:
	movs r1, 0x1
	negs r1, r1
	b _080A1098
_080A107A:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_809CC90
	adds r1, r0, 0
	b _080A1098
_080A1088:
	ldr r0, _080A1090
	ldr r1, _080A1094
	bl FatalError
	.align 2, 0
_080A1090: .4byte gUnknown_81166B4
_080A1094: .4byte gUnknown_81166C0
_080A1098:
	mov r0, r9
	bl sub_80A2460
	b _080A1330
_080A10A0:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_8001658
	adds r2, r0, 0
	mov r3, r10
	strh r2, [r3, 0x28]
	ldr r1, [r3, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _080A10DE
	lsls r0, r2, 16
	asrs r3, r0, 16
_080A10C0:
	adds r2, r1, 0
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080A10CE
	bl _0809F0C4
_080A10CE:
	adds r0, r1, 0
	adds r0, 0x10
	mov r5, r10
	str r0, [r5, 0x4]
	adds r1, r0, 0
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD0
	beq _080A10C0
_080A10DE:
	mov r1, r10
	ldr r0, [r1, 0x4]
	ldrb r0, [r0]
	cmp r0, 0xD1
	beq _080A10EC
	bl _0809EAE0
_080A10EC:
	ldr r0, _080A10F4
	strh r0, [r1, 0x28]
	bl _0809F0C4
	.align 2, 0
_080A10F4: .4byte 0x0000ffff
_080A10F8:
	ldr r7, [sp, 0x14]
	ldr r1, _080A11F0
	movs r0, 0
	str r0, [r1]
	mov r2, r10
	strh r0, [r2, 0x28]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0xD8
	bgt _080A1176
	cmp r0, 0xD6
	blt _080A1176
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0x10]
	lsls r1, 16
	asrs r1, 16
	bl sub_8001658
	adds r3, r0, 0
	mov r4, r10
	ldr r1, [r4, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _080A114E
_080A112A:
	adds r2, r1, 0
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	cmp r0, r3
	bne _080A1136
	ldr r7, [r2, 0xC]
_080A1136:
	adds r0, r1, 0
	adds r0, 0x10
	mov r1, r10
	str r0, [r1, 0x4]
	ldrh r1, [r1, 0x28]
	adds r1, 0x1
	mov r4, r10
	strh r1, [r4, 0x28]
	adds r1, r0, 0
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD0
	beq _080A112A
_080A114E:
	mov r5, r10
	ldr r1, [r5, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD1
	bne _080A1176
_080A1158:
	cmp r7, 0
	bne _080A115E
	ldr r7, [r1, 0xC]
_080A115E:
	mov r0, r10
	ldr r2, [r0, 0x4]
	adds r1, r2, 0
	adds r1, 0x10
	str r1, [r0, 0x4]
	ldrh r0, [r0, 0x28]
	adds r0, 0x1
	mov r3, r10
	strh r0, [r3, 0x28]
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD1
	beq _080A1158
_080A1176:
	cmp r7, 0
	bne _080A117C
	ldr r7, _080A11F4
_080A117C:
	mov r4, r10
	ldr r5, [r4, 0x4]
	ldrb r0, [r5]
	cmp r0, 0xD9
	bne _080A11B8
	ldr r0, _080A11F8
	mov r8, r0
	ldr r6, _080A11F0
	movs r1, 0x4
	add r1, r8
	mov r12, r1
_080A1192:
	ldr r1, [r6]
	lsls r2, r1, 3
	mov r4, r8
	adds r3, r2, r4
	adds r4, r5, 0
	ldr r0, [r4, 0xC]
	str r0, [r3]
	add r2, r12
	adds r1, 0x1
	str r1, [r2]
	str r1, [r6]
	adds r0, r4, 0
	adds r0, 0x10
	mov r5, r10
	str r0, [r5, 0x4]
	adds r5, r0, 0
	ldrb r0, [r4, 0x10]
	cmp r0, 0xD9
	beq _080A1192
_080A11B8:
	ldr r0, _080A11F0
	ldr r1, [r0]
	cmp r1, 0
	bgt _080A11C4
	bl _0809EAE0
_080A11C4:
	ldr r3, _080A11F8
	lsls r2, r1, 3
	adds r1, r2, r3
	movs r0, 0
	str r0, [r1]
	adds r0, r3, 0x4
	adds r2, r0
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r2]
	add r0, sp, 0x8
	ldrb r0, [r0]
	subs r0, 0xD2
	cmp r0, 0x6
	bhi _080A1280
	lsls r0, 2
	ldr r1, _080A11FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A11F0: .4byte gUnknown_203B4AC
_080A11F4: .4byte gUnknown_81166D8
_080A11F8: .4byte gUnknown_2039D50
_080A11FC: .4byte _080A1200
	.align 2, 0
_080A1200:
	.4byte _080A121C
	.4byte _080A121C
	.4byte _080A123E
	.4byte _080A1260
	.4byte _080A121C
	.4byte _080A123E
	.4byte _080A1260
_080A121C:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0
	bl sub_809B028
	b _080A1280
_080A123E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0x1
	bl sub_809B028
	b _080A1280
_080A1260:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0x2
	bl sub_809B028
_080A1280:
	mov r0, r9
	movs r1, 0x1
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	bne _080A1292
	bl _0809EAE0
_080A1292:
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	bl _0809F0C4
_080A129E:
	mov r0, r9
	movs r1, 0x1
	bl sub_809D8EC
	b _080A130A
_080A12A8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
_080A12AC:
	mov r2, r10
_080A12AE:
	strh r0, [r2, 0x2A]
	bl _0809F0C4
_080A12B4:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	ldr r0, [sp, 0xC]
	subs r0, r1
	bl OtherRandInt
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	adds r1, r0
	mov r4, r10
	strh r1, [r4, 0x2A]
	bl _0809F0C4
_080A12D0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r5, r10
	strh r0, [r5, 0x28]
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	mov r0, r9
	bl sub_809D8EC
	b _080A130A
_080A12E6:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	bl sub_809D9B8
	bl _0809EAE0
_080A12F4:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r4, r10
	strh r0, [r4, 0x28]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	ldrb r2, [r0, 0x1]
	mov r0, r9
	bl sub_809DA08
_080A130A:
	lsls r0, 24
_080A130C:
	cmp r0, 0
	bne _080A1314
	bl _0809EAE0
_080A1314:
	bl _0809F0C4
_080A1318:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1324:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
_080A132A:
	mov r0, r9
	bl sub_80A242C
_080A1330:
	mov r1, r10
	str r0, [r1, 0x4]
	bl _0809EAE0
_080A1338:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1344:
	ldr r2, _080A1364
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	mov r1, r10
	str r0, [r1, 0x4]
	str r0, [r1, 0x8]
	bl _0809EAE0
	.align 2, 0
_080A1364: .4byte gFunctionScriptTable
_080A1368:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1374:
	ldr r0, _080A138C
	movs r5, 0
	ldrsh r1, [r0, r5]
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _080A1390
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	b _080A1396
	.align 2, 0
_080A138C: .4byte gUnknown_2039A34
_080A1390:
	mov r4, r10
	movs r5, 0xC
	ldrsh r2, [r4, r5]
_080A1396:
	adds r5, r2, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _080A13AA
	add r0, sp, 0x8
	movs r4, 0x1
	ldrsb r4, [r0, r4]
	b _080A13B0
_080A13AA:
	mov r0, r10
	movs r4, 0xE
	ldrsb r4, [r0, r4]
_080A13B0:
	add r0, sp, 0x1C
	adds r2, r5, 0
	adds r3, r4, 0
	bl GroundMap_GetStationScript
	ldr r0, [sp, 0x1C]
	mov r1, r10
	str r0, [r1, 0x4]
	str r0, [r1, 0x8]
	strh r5, [r1, 0xC]
	strb r4, [r1, 0xE]
	bl _0809EAE0
_080A13CA:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A4D7C
	ldr r4, _080A13F4
	strh r0, [r4]
	bl sub_809D940
	movs r3, 0
	ldrsh r0, [r4, r3]
	bl GroundMap_ExecuteEnter
	bl _0809EAE0
	.align 2, 0
_080A13F4: .4byte gUnknown_2039A34
_080A13F8:
	movs r0, 0
	mov r4, r10
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	bl _0809EAE0
_080A1404:
	mov r5, r10
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _080A1410
_080A140C:
	movs r0, 0
	b _080A142E
_080A1410:
	mov r0, r10
	adds r0, 0x4
	mov r1, r10
	adds r1, 0x10
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	movs r0, 0
	mov r5, r10
	str r0, [r5, 0x10]
	str r0, [r5, 0x14]
	bl _0809EAE0
_080A1428:
	movs r0, 0x1
	b _080A142E
_080A142C:
	movs r0, 0x4
_080A142E:
	add sp, 0x1BC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ExecuteScriptCommand

	thumb_func_start sub_80A1440
sub_80A1440:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A14E8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A1440

	thumb_func_start GroundScript_ExecuteTrigger
GroundScript_ExecuteTrigger:
	push {r4,r5,lr}
	sub sp, 0xF4
	lsls r0, 16
	asrs r4, r0, 16
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	ldr r1, _080A14C8
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0xB
	bne _080A14C4
	add r5, sp, 0x10
	ldr r1, _080A14CC
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl InitActionWithParams
	movs r0, 0
	add r1, sp, 0x4
	adds r2, r4, 0
	bl sub_809D710
	ldr r3, _080A14D0
	adds r0, r5, 0
	movs r1, 0
	add r2, sp, 0x4
	bl GroundScript_ExecutePP
	add r1, sp, 0x44
	add r0, sp, 0x38
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, _080A14D4
	str r0, [r5, 0x34]
	str r0, [r5, 0x38]
	ldr r1, _080A14D8
	adds r0, r5, 0
	bl HandleAction
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r5, 0
	bl sub_809D648
	cmp r4, 0
	beq _080A14DC
_080A14C4:
	movs r0, 0
	b _080A14DE
	.align 2, 0
_080A14C8: .4byte gFunctionScriptTable
_080A14CC: .4byte gUnknown_8116488
_080A14D0: .4byte gUnknown_81166F8
_080A14D4: .4byte gUnknown_81164E4
_080A14D8: .4byte gUnknown_8116704
_080A14DC:
	movs r0, 0x1
_080A14DE:
	add sp, 0xF4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GroundScript_ExecuteTrigger

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
	bl sub_809AE90
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
	bl sub_809AE90
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

	thumb_func_start sub_80A242C
sub_80A242C:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r1, 0
	ldr r0, [r0, 0x2C]
	adds r2, r0, 0
	adds r2, 0x10
	mov r3, sp
_080A243A:
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, 0x10
	ldrb r0, [r3]
	cmp r0, 0xF4
	bne _080A243A
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r4, r0
	bne _080A243A
	adds r0, r2, 0
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A242C

	thumb_func_start sub_80A2460
sub_80A2460:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r5, r0, 0
	mov r8, r1
	ldr r6, [r5, 0x28]
	mov r4, sp
_080A2470:
	mov r0, sp
	adds r1, r6, 0
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldr r1, [r1]
	str r1, [r0]
	ldrb r0, [r4]
	cmp r0, 0xCC
	bne _080A249E
	ldr r1, [sp, 0x4]
	mov r0, r8
	movs r2, 0x2
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A249E:
	cmp r0, 0xCD
	bne _080A24BE
	ldr r1, [sp, 0x4]
	ldrb r2, [r4, 0x1]
	mov r0, r8
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A24BE:
	cmp r0, 0xCE
	bne _080A24EC
	ldr r1, [sp, 0x4]
	lsls r1, 16
	asrs r1, 16
	adds r0, r5, 0
	adds r0, 0x74
	bl sub_8001658
	adds r1, r0, 0
	ldrb r2, [r4, 0x1]
	mov r0, r8
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A24EC:
	adds r0, r6, 0
	b _080A24F4
_080A24F0:
	adds r6, 0x10
	b _080A2470
_080A24F4:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2460

    .align 2,0
