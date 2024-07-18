	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text




	thumb_func_start sub_809D600
sub_809D600:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x18]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	asrs r5, 24
	bl sub_809D5B8
	str r6, [r7]
	mov r0, r8
	str r0, [r7, 0x4]
	strh r4, [r7, 0x10]
	strb r5, [r7, 0x12]
	ldrh r0, [r6]
	strh r0, [r7, 0x8]
	ldr r1, [r6, 0x4]
	cmp r1, 0
	beq _0809D63A
	mov r0, r8
	bl _call_via_r1
	strh r0, [r7, 0xA]
	b _0809D63C
_0809D63A:
	strh r1, [r7, 0xA]
_0809D63C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809D600

	thumb_func_start sub_809D648
sub_809D648:
	push {lr}
	bl sub_809D5B8
	pop {r0}
	bx r0
	thumb_func_end sub_809D648

	thumb_func_start sub_809D654
sub_809D654:
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_809D654

	thumb_func_start sub_809D65C
sub_809D65C:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x26
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809D66E
	movs r0, 0x1
	negs r0, r0
	b _0809D672
_0809D66E:
	movs r2, 0x24
	ldrsh r0, [r1, r2]
_0809D672:
	pop {r1}
	bx r1
	thumb_func_end sub_809D65C

	thumb_func_start sub_809D678
sub_809D678:
	movs r2, 0x26
	ldrsh r1, [r0, r2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	thumb_func_end sub_809D678

	thumb_func_start sub_809D684
sub_809D684:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0809D6A4
	ldr r0, [r2, 0x34]
	cmp r0, 0
	beq _0809D69C
	ldr r1, [r2, 0x38]
	b _0809D69E
_0809D69C:
	ldr r1, [r2, 0x2C]
_0809D69E:
	ldr r0, [r3]
	cmp r1, r0
	beq _0809D6CC
_0809D6A4:
	adds r0, r2, 0
	adds r0, 0x86
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0809D6D0
	adds r0, r2, 0
	adds r0, 0x94
	ldr r0, [r0]
	cmp r0, 0
	beq _0809D6C0
	adds r0, r2, 0
	adds r0, 0x98
	b _0809D6C4
_0809D6C0:
	adds r0, r2, 0
	adds r0, 0x8C
_0809D6C4:
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bne _0809D6D0
_0809D6CC:
	movs r0, 0x1
	b _0809D6D2
_0809D6D0:
	movs r0, 0
_0809D6D2:
	pop {r1}
	bx r1
	thumb_func_end sub_809D684

        .align 2,0
