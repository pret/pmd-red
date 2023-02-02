	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8092D80
sub_8092D80:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092D8A:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x4
	beq _08092DB0
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092DB0
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092DAA
	adds r0, r3, 0
	b _08092DB2
_08092DAA:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08092D8A
_08092DB0:
	movs r0, 0
_08092DB2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092D80

	thumb_func_start sub_8092DB8
sub_8092DB8:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r6, 0x1
_08092DC0:
	subs r1, 0x1
	cmp r1, 0
	bge _08092DF0
	movs r2, 0x3
	ldrb r1, [r4, 0x18]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08092DD6
	movs r1, 0x3
	b _08092DEC
_08092DD6:
	subs r2, 0x1
	cmp r2, 0
	blt _08092E12
	lsls r0, r2, 3
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08092DD6
	adds r1, r2, 0
_08092DEC:
	cmp r2, 0
	blt _08092E12
_08092DF0:
	lsls r0, r1, 3
	adds r0, r4
	ldrb r2, [r0]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E12
	lsrs r0, r2, 1
	ands r0, r3
	cmp r0, 0
	bne _08092E0C
	adds r0, r1, 0
	b _08092E14
_08092E0C:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08092DC0
_08092E12:
	movs r0, 0
_08092E14:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092DB8

	thumb_func_start sub_8092E1C
sub_8092E1C:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092E26:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	beq _08092E4C
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E4C
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092E46
	adds r0, r3, 0
	b _08092E4E
_08092E46:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E26
_08092E4C:
	movs r0, 0
_08092E4E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E1C

	thumb_func_start sub_8092E54
sub_8092E54:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092E5E:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	beq _08092E84
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E84
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092E7E
	adds r0, r3, 0
	b _08092E86
_08092E7E:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E5E
_08092E84:
	movs r0, 0
_08092E86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E54

        .align 2,0
