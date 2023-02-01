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

	thumb_func_start sub_8092E8C
sub_8092E8C:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	lsls r0, r1, 3
	adds r3, r0, r6
_08092E96:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _08092EC6
	movs r3, 0x7
	movs r4, 0x1
	adds r2, r6, 0
	adds r2, 0x38
_08092EA6:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08092EBC
	lsrs r0, r1, 1
	ands r0, r4
	cmp r0, 0
	bne _08092EBC
	adds r0, r3, 0
	b _08092EE6
_08092EBC:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bgt _08092EA6
	b _08092EE4
_08092EC6:
	ldrb r2, [r3]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092EE4
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092EDE
	adds r0, r1, 0
	b _08092EE6
_08092EDE:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E96
_08092EE4:
	movs r0, 0
_08092EE6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E8C

	thumb_func_start sub_8092EEC
sub_8092EEC:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	lsls r0, r1, 3
	adds r3, r0, r6
_08092EF6:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _08092F26
	movs r3, 0x7
	movs r4, 0x1
	adds r2, r6, 0
	adds r2, 0x38
_08092F06:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08092F1C
	lsrs r0, r1, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F1C
	adds r0, r3, 0
	b _08092F46
_08092F1C:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bgt _08092F06
	b _08092F44
_08092F26:
	ldrb r2, [r3]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092F44
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F3E
	adds r0, r1, 0
	b _08092F46
_08092F3E:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092EF6
_08092F44:
	movs r0, 0
_08092F46:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092EEC

	thumb_func_start sub_8092F4C
sub_8092F4C:
	push {r4,lr}
	adds r2, r0, 0
	cmp r1, 0
	ble _08092F78
	movs r4, 0x1
	lsls r0, r1, 3
	adds r3, r0, r2
_08092F5A:
	ldrb r2, [r3]
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092F78
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F70
	adds r0, r1, 0
	b _08092F7A
_08092F70:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bgt _08092F5A
_08092F78:
	movs r0, 0
_08092F7A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8092F4C

        .align 2,0
