        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802CAA4
sub_802CAA4:
	push {r4-r7,lr}
	movs r7, 0
	ldr r5, _0802CAC8
	ldr r0, [r5]
	ldrb r0, [r0, 0xC]
	bl GetJobSlotInfo
	adds r4, r0, 0
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _0802CB26
	ldrb r0, [r4]
	cmp r0, 0x5
	beq _0802CACC
	cmp r0, 0x6
	beq _0802CB10
	b _0802CB26
	.align 2, 0
_0802CAC8: .4byte gUnknown_203B2F0
_0802CACC:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CAFC
	str r0, [r1]
	adds r0, r4, 0
	bl sub_809693C
	lsls r0, 24
	cmp r0, 0
	bne _0802CAEE
	ldrb r0, [r4, 0x4]
	bl sub_80A2824
	lsls r0, 24
	cmp r0, 0
	bne _0802CB00
_0802CAEE:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	b _0802CB0A
	.align 2, 0
_0802CAFC: .4byte gUnknown_80DFD70
_0802CB00:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x2
_0802CB0A:
	str r1, [r0]
	adds r7, 0x1
	b _0802CB26
_0802CB10:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CB9C
	str r0, [r1]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x3
	str r0, [r1]
	movs r7, 0x1
_0802CB26:
	ldr r4, _0802CBA0
	ldr r6, [r4]
	lsls r1, r7, 3
	movs r0, 0x86
	lsls r0, 1
	adds r3, r6, r0
	adds r2, r3, r1
	ldr r0, _0802CBA4
	ldr r0, [r0]
	str r0, [r2]
	movs r0, 0x88
	lsls r0, 1
	adds r5, r6, r0
	adds r1, r5, r1
	movs r0, 0x4
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802CBA8
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r5, r1
	movs r0, 0x7
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r5, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r7
	bge _0802CB8C
	adds r4, r6, 0
	adds r1, r5, 0
	movs r5, 0x1
	negs r5, r5
_0802CB78:
	ldr r2, [r1]
	cmp r2, r5
	beq _0802CB84
	ldr r0, [r4, 0x68]
	cmp r2, r0
	beq _0802CB94
_0802CB84:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _0802CB78
_0802CB8C:
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x7
	str r0, [r1, 0x68]
_0802CB94:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CB9C: .4byte gUnknown_80DFD7C
_0802CBA0: .4byte gUnknown_203B2F0
_0802CBA4: .4byte gUnknown_80D494C
_0802CBA8: .4byte gUnknown_80D4970
	thumb_func_end sub_802CAA4

    .align 2,0
