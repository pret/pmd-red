	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8002658
sub_8002658:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0800267C
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	movs r3, 0x1
	negs r3, r3
	cmp r0, r3
	beq _0800268C
_0800266E:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r4
	bne _08002680
	ldrb r0, [r1, 0x2]
	b _0800268E
	.align 2, 0
_0800267C: .4byte gUnknown_80B71E4
_08002680:
	adds r1, 0x4
	ldrh r2, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r3
	bne _0800266E
_0800268C:
	movs r0, 0
_0800268E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002658

        .align 2,0
