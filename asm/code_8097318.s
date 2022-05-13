	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_809733C
sub_809733C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r4, 0xD
	beq _0809737C
	lsls r0, r4, 16
	lsrs r5, r0, 16
	movs r0, 0
	movs r1, 0x2C
	adds r2, r5, 0
	bl sub_8001784
	cmp r0, 0
	bne _0809737C
	movs r0, 0
	movs r1, 0x2B
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_800199C
	cmp r6, 0
	beq _0809737C
	cmp r4, 0xE
	blt _0809737C
	cmp r4, 0xF
	ble _08097378
	cmp r4, 0x1C
	bne _0809737C
_08097378:
	bl sub_809674C
_0809737C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809733C

	thumb_func_start sub_8097384
sub_8097384:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097392
	movs r0, 0
	b _080973A4
_08097392:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2C
	bl sub_8001784
	cmp r0, 0
	beq _080973A4
	movs r0, 0x1
_080973A4:
	pop {r1}
	bx r1
	thumb_func_end sub_8097384

	thumb_func_start sub_80973A8
sub_80973A8:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r0, 0xD
	beq _080973EE
	lsls r5, r0, 16
	cmp r6, 0
	beq _080973E2
	bl sub_80A26B8
	lsls r0, 16
	asrs r4, r0, 16
	lsrs r2, r5, 16
	movs r0, 0
	movs r1, 0x2B
	movs r3, 0
	bl sub_800199C
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080973E2
	movs r0, 0
	movs r1, 0x12
	adds r2, r4, 0
	bl sub_80018D8
_080973E2:
	lsrs r2, r5, 16
	movs r0, 0
	movs r1, 0x2C
	adds r3, r6, 0
	bl sub_800199C
_080973EE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80973A8

	thumb_func_start sub_80973F4
sub_80973F4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097402
	movs r0, 0
	b _08097414
_08097402:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2D
	bl sub_8001784
	cmp r0, 0
	beq _08097414
	movs r0, 0x1
_08097414:
	pop {r1}
	bx r1
	thumb_func_end sub_80973F4

	thumb_func_start sub_8097418
sub_8097418:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r5, 0xD
	beq _08097470
	lsls r6, r5, 16
	cmp r7, 0
	beq _08097464
	lsrs r2, r6, 16
	movs r0, 0
	movs r1, 0x2C
	movs r3, 0
	bl sub_800199C
	cmp r5, 0x1E
	bgt _08097464
	lsls r0, r5, 3
	ldr r1, _08097478
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0xFF
	beq _0809744C
	bl sub_8097FA8
_0809744C:
	ldrb r0, [r4, 0x5]
	cmp r0, 0xFF
	beq _08097456
	bl sub_8097FA8
_08097456:
	cmp r5, 0x9
	bne _08097460
	movs r0, 0x1F
	bl sub_8097FA8
_08097460:
	bl sub_8097FF8
_08097464:
	lsrs r2, r6, 16
	movs r0, 0
	movs r1, 0x2D
	adds r3, r7, 0
	bl sub_800199C
_08097470:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097478: .4byte gStoryMissionText
	thumb_func_end sub_8097418

        .align 2,0
