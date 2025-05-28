	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_8099E58
sub_8099E58:
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0xF
	adds r1, r4, 0
	bl sub_8003664
	movs r0, 0xE
	adds r1, r4, 0
	bl sub_8003664
	movs r0, 0x1F
	adds r1, r4, 0
	bl sub_8003664
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8099E58

	thumb_func_start sub_8099E80
sub_8099E80:
	push {r4-r7,lr}
	sub sp, 0x4
	str r1, [sp]
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, _08099EA0
	ldr r1, [r0]
	adds r2, r0, 0
	cmp r1, 0xE
	bls _08099E96
	b _0809A558
_08099E96:
	lsls r0, r1, 2
	ldr r1, _08099EA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099EA0: .4byte gUnknown_2039978
_08099EA4: .4byte _08099EA8
	.align 2, 0
_08099EA8:
	.4byte _0809A558
	.4byte _08099EE4
	.4byte _0809A05A
	.4byte _0809A1D2
	.4byte _0809A34A
	.4byte _08099FDE
	.4byte _0809A156
	.4byte _0809A2CE
	.4byte _0809A4BC
	.4byte _08099F5E
	.4byte _0809A0D6
	.4byte _0809A24E
	.4byte _0809A3EA
	.4byte _0809A48A
	.4byte _0809A48A
_08099EE4:
	movs r4, 0
	movs r5, 0
	ldr r7, _08099F00
_08099EEA:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F04
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F0E
	.align 2, 0
_08099F00: .4byte gUnknown_2039998
_08099F04:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F0E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _08099EEA
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _08099F40
	adds r7, r0, 0
	adds r7, 0x20
_08099F28:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F44
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F4E
	.align 2, 0
_08099F40: .4byte gUnknown_2039998
_08099F44:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F4E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08099F28
	b _0809A558
_08099F5E:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _08099F80
	adds r7, r0, 0
	adds r7, 0x1C
_08099F6A:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F84
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F8E
	.align 2, 0
_08099F80: .4byte gUnknown_2039998
_08099F84:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F8E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _08099F6A
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _08099FC0
	adds r7, r0, 0
	adds r7, 0x3E
_08099FA8:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099FC4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099FCE
	.align 2, 0
_08099FC0: .4byte gUnknown_2039998
_08099FC4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099FCE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08099FA8
	b _0809A558
_08099FDE:
	movs r4, 0
	movs r5, 0
	ldr r7, _08099FFC
_08099FE4:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A000
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A00A
	.align 2, 0
_08099FFC: .4byte gUnknown_2039998
_0809A000:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_0809A00A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _08099FE4
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A03C
	adds r7, r0, 0
	adds r7, 0x20
_0809A024:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A040
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A04A
	.align 2, 0
_0809A03C: .4byte gUnknown_2039998
_0809A040:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_0809A04A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A024
	b _0809A558
_0809A05A:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A078
_0809A060:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A07C
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A086
	.align 2, 0
_0809A078: .4byte gUnknown_2039998
_0809A07C:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A086:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A060
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A0B8
	adds r7, r0, 0
	adds r7, 0x20
_0809A0A0:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A0BC
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A0C6
	.align 2, 0
_0809A0B8: .4byte gUnknown_2039998
_0809A0BC:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A0C6:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A0A0
	b _0809A558
_0809A0D6:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _0809A0F8
	adds r7, r0, 0
	adds r7, 0x1C
_0809A0E2:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A0FC
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A106
	.align 2, 0
_0809A0F8: .4byte gUnknown_2039998
_0809A0FC:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A106:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A0E2
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _0809A138
	adds r7, r0, 0
	adds r7, 0x3E
_0809A120:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A13C
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A146
	.align 2, 0
_0809A138: .4byte gUnknown_2039998
_0809A13C:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A146:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A120
	b _0809A558
_0809A156:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A174
_0809A15C:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A178
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A182
	.align 2, 0
_0809A174: .4byte gUnknown_2039998
_0809A178:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A182:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A15C
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A1B4
	adds r7, r0, 0
	adds r7, 0x20
_0809A19C:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A1B8
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A1C2
	.align 2, 0
_0809A1B4: .4byte gUnknown_2039998
_0809A1B8:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A1C2:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A19C
	b _0809A558
_0809A1D2:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A1F0
_0809A1D8:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A1F4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A1FE
	.align 2, 0
_0809A1F0: .4byte gUnknown_2039998
_0809A1F4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A1FE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A1D8
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A230
	adds r7, r0, 0
	adds r7, 0x20
_0809A218:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A234
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A23E
	.align 2, 0
_0809A230: .4byte gUnknown_2039998
_0809A234:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A23E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A218
	b _0809A558
_0809A24E:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _0809A270
	adds r7, r0, 0
	adds r7, 0x1C
_0809A25A:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A274
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A27E
	.align 2, 0
_0809A270: .4byte gUnknown_2039998
_0809A274:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A27E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A25A
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _0809A2B0
	adds r7, r0, 0
	adds r7, 0x3E
_0809A298:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A2B4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A2BE
	.align 2, 0
_0809A2B0: .4byte gUnknown_2039998
_0809A2B4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A2BE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A298
	b _0809A558
_0809A2CE:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A2EC
_0809A2D4:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A2F0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A2FA
	.align 2, 0
_0809A2EC: .4byte gUnknown_2039998
_0809A2F0:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A2FA:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A2D4
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A32C
	adds r7, r0, 0
	adds r7, 0x20
_0809A314:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A330
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A33A
	.align 2, 0
_0809A32C: .4byte gUnknown_2039998
_0809A330:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A33A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A314
	b _0809A558
_0809A34A:
	movs r4, 0
	movs r5, 0
_0809A34E:
	ldr r0, _0809A36C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A370
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A38C
	.align 2, 0
_0809A36C: .4byte gUnknown_2039998
_0809A370:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A382
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A38C
_0809A382:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A38C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A34E
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
_0809A39E:
	ldr r0, _0809A3BC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A3C0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A3DC
	.align 2, 0
_0809A3BC: .4byte gUnknown_2039998
_0809A3C0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A3D2
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A3DC
_0809A3D2:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A3DC:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A39E
	b _0809A558
_0809A3EA:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
_0809A3F0:
	ldr r0, _0809A40C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A410
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A42C
	.align 2, 0
_0809A40C: .4byte gUnknown_2039998
_0809A410:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A422
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A42C
_0809A422:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A42C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A3F0
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
_0809A43E:
	ldr r0, _0809A45C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A460
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A47C
	.align 2, 0
_0809A45C: .4byte gUnknown_2039998
_0809A460:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A472
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A47C
_0809A472:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A47C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A43E
	b _0809A558
_0809A48A:
	ldr r0, [r2]
	cmp r0, 0xD
	beq _0809A496
	cmp r0, 0xE
	beq _0809A4AA
	b _0809A4BC
_0809A496:
	mov r0, sp
	movs r1, 0x90
	strb r1, [r0]
	strb r1, [r0, 0x1]
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0x2]
	movs r0, 0x1
	negs r0, r0
	b _0809A4BA
_0809A4AA:
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0xC0
	strb r0, [r1, 0x1]
	movs r0, 0x80
	strb r0, [r1, 0x2]
	subs r0, 0x81
_0809A4BA:
	strb r0, [r1, 0x3]
_0809A4BC:
	movs r4, 0
	movs r5, 0
_0809A4C0:
	ldr r0, _0809A4DC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A4E0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A4FC
	.align 2, 0
_0809A4DC: .4byte gUnknown_2039998
_0809A4E0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A4F2
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A4FC
_0809A4F2:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A4FC:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A4C0
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
_0809A50E:
	ldr r0, _0809A52C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A530
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A54C
	.align 2, 0
_0809A52C: .4byte gUnknown_2039998
_0809A530:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A542
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A54C
_0809A542:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A54C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A50E
_0809A558:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8099E80

        .align 2,0
