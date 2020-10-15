	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_8094FB4
sub_8094FB4:
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2, 0x4]
	adds r0, 0x1
	movs r1, 0
	strb r0, [r2, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _0809500A
	strb r1, [r2, 0x4]
	ldrb r0, [r2, 0x3]
	adds r0, 0x1
	strb r0, [r2, 0x3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _0809500A
	strb r1, [r2, 0x3]
	ldrb r0, [r2, 0x2]
	adds r0, 0x1
	strb r0, [r2, 0x2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _0809500A
	strb r1, [r2, 0x2]
	ldrh r3, [r2]
	movs r0, 0
	ldrsh r1, [r2, r0]
	ldr r0, _08094FFC
	cmp r1, r0
	bgt _08095000
	adds r0, r3, 0x1
	b _08095008
	.align 2, 0
_08094FFC: .4byte 0x0000270e
_08095000:
	movs r0, 0x3B
	strb r0, [r2, 0x3]
	strb r0, [r2, 0x2]
	ldr r0, _08095010
_08095008:
	strh r0, [r2]
_0809500A:
	pop {r0}
	bx r0
	.align 2, 0
_08095010: .4byte 0x0000270f
	thumb_func_end sub_8094FB4

        .align 2,0
