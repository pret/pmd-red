	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CheckRunAwayVisualFlag
CheckRunAwayVisualFlag:
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r4, [r5, 0x70]
	adds r6, r4, 0
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _08071590
	adds r0, r5, 0
	movs r1, 0x2B
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08071590
	movs r2, 0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	movs r3, 0xE
	ldrsh r1, [r4, r3]
	asrs r0, 1
	cmp r1, r0
	bgt _08071576
	movs r2, 0x1
_08071576:
	adds r0, r6, 0
	movs r1, 0x4
	bl SetVisualFlags
	lsls r0, 24
	lsrs r0, 24
	cmp r7, 0
	beq _08071590
	cmp r0, 0
	beq _08071590
	adds r0, r5, 0
	bl ShowVisualFlags
_08071590:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CheckRunAwayVisualFlag

	.align 2, 0