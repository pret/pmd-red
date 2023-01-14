	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8070BC0
sub_8070BC0:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, [r4, 0x70]
	movs r1, 0
	bl IsCharging
	lsls r0, 24
	cmp r0, 0
	bne _08070C56
	adds r6, r5, 0
	adds r6, 0xA8
	ldrb r0, [r6]
	cmp r0, 0x4
	beq _08070C56
	cmp r0, 0x3
	beq _08070C56
	adds r0, r4, 0
	bl ShouldMonsterRunAway
	lsls r0, 24
	cmp r0, 0
	bne _08070C56
	adds r0, r5, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070C56
	adds r0, r5, 0
	adds r0, 0xB0
	ldrb r1, [r0]
	cmp r1, 0x6
	beq _08070C56
	cmp r1, 0x1
	beq _08070C56
	adds r0, r5, 0
	adds r0, 0xBC
	ldrb r3, [r0]
	adds r4, r0, 0
	cmp r3, 0x2
	beq _08070C56
	ldrb r2, [r6]
	cmp r2, 0x1
	beq _08070C56
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08070C56
	cmp r2, 0x5
	beq _08070C56
	cmp r3, 0x1
	beq _08070C56
	cmp r1, 0x3
	beq _08070C56
	cmp r1, 0x4
	beq _08070C56
	adds r0, r5, 0
	adds r0, 0xE8
	ldrb r1, [r0]
	cmp r1, 0x2
	beq _08070C56
	adds r0, r5, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08070C56
	cmp r1, 0x1
	beq _08070C56
	ldrb r0, [r4]
	cmp r0, 0x7
	beq _08070C56
	cmp r0, 0x3
	beq _08070C56
	movs r0, 0x1
	b _08070C58
_08070C56:
	movs r0, 0
_08070C58:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8070BC0

	.align 2, 0