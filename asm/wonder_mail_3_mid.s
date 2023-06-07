        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802FBF4
sub_802FBF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r8, r0
	movs r1, 0
	str r1, [sp]
_0802FC08:
	ldr r1, [sp]
	lsls r0, r1, 16
	asrs r4, r0, 16
	mov r10, r4
	adds r0, r4, 0
	bl sub_80A27CC
	lsls r0, 24
	cmp r0, 0
	beq _0802FCCE
	cmp r4, 0x13
	beq _0802FCCE
	cmp r4, 0x1D
	beq _0802FCCE
	ldr r7, _0802FC88
	ldr r1, [r7]
	mov r0, r8
	lsls r6, r0, 1
	adds r0, r1, r6
	strh r4, [r0]
	adds r1, 0x5C
	add r1, r8
	movs r0, 0
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, 0xB8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0802FCCA
	cmp r4, 0xD
	beq _0802FCCA
	adds r0, r4, 0
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r5, 0
	cmp r4, 0x1E
	bgt _0802FCA8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _0802FCA6
	cmp r4, 0x6
	bne _0802FC8C
	movs r0, 0x13
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x13
	b _0802FCA4
	.align 2, 0
_0802FC88: .4byte gUnknown_203B314
_0802FC8C:
	mov r0, r10
	cmp r0, 0xA
	bne _0802FCA8
	movs r0, 0x1D
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _0802FCA8
	ldr r0, [r7]
	adds r0, r6
	movs r1, 0x1D
_0802FCA4:
	strh r1, [r0]
_0802FCA6:
	movs r5, 0x1
_0802FCA8:
	ldr r4, _0802FCEC
	ldr r0, [r4]
	adds r0, 0x5C
	add r0, r8
	strb r5, [r0]
	cmp r5, 0
	bne _0802FCCA
	mov r0, r9
	bl CountJobsinDungeon
	cmp r0, 0
	ble _0802FCCA
	ldr r0, [r4]
	adds r0, 0x8A
	add r0, r8
	movs r1, 0x1
	strb r1, [r0]
_0802FCCA:
	movs r1, 0x1
	add r8, r1
_0802FCCE:
	ldr r0, [sp]
	adds r0, 0x1
	str r0, [sp]
	cmp r0, 0x2D
	ble _0802FC08
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802FCEC: .4byte gUnknown_203B314
	thumb_func_end sub_802FBF4

        .align 2,0
