	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801BB5C
sub_801BB5C:
	push {r4-r7,lr}
	ldr r4, _0801BBEC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xCC
	ldr r0, _0801BBF0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x6
	str r0, [r1]
	ldr r0, [r2, 0x24]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801BB86
	ldr r0, [r4]
	adds r0, 0xD0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0801BB86:
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0x1
	movs r2, 0x8
	mov r1, r12
	adds r1, 0xD4
	ldr r0, _0801BBF4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0801BBF8
	ldr r0, [r0]
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE0
	str r2, [r0]
	movs r5, 0x3
	adds r1, 0x8
	movs r0, 0
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE8
	str r3, [r0]
	movs r3, 0
	adds r6, r4, 0
	movs r7, 0x1
	negs r7, r7
	mov r4, r12
	adds r4, 0xC8
	subs r1, 0x14
_0801BBC6:
	ldr r2, [r1]
	cmp r2, r7
	beq _0801BBD2
	ldr r0, [r4]
	cmp r2, r0
	beq _0801BC1C
_0801BBD2:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0801BBC6
	movs r3, 0
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xD0
	ldr r1, [r0]
	b _0801BC0E
	.align 2, 0
_0801BBEC: .4byte gUnknown_203B234
_0801BBF0: .4byte gKangaskhanStorage
_0801BBF4: .4byte gKangaskhanTrash
_0801BBF8: .4byte gUnknown_80D4970
_0801BBFC:
	adds r3, 0x1
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xD0
	adds r1, r0
	ldr r1, [r1]
_0801BC0E:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801BBFC
	adds r0, r2, 0
	adds r0, 0xC8
	str r1, [r0]
_0801BC1C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801BB5C

        .align 2,0
