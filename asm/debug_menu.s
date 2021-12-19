        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_803A3BC
sub_803A3BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x84
	movs r5, 0x1
	add r4, sp, 0x60
	add r6, sp, 0x68
	add r0, sp, 0x7C
	mov r8, r0
	add r0, sp, 0x80
	mov r10, r0
_0803A3D6:
	lsls r0, r5, 24
	lsrs r0, 24
	bl UnlockFriendArea
	adds r5, 0x1
	cmp r5, 0x39
	ble _0803A3D6
	movs r5, 0
	adds r7, r4, 0
_0803A3E8:
	movs r0, 0
	mov r9, r0
	ldr r0, _0803A454
	str r0, [sp, 0x7C]
	adds r5, 0x1
	lsls r4, r5, 16
	asrs r4, 16
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r0, 0x27
	strh r0, [r7]
	adds r0, r6, 0
	adds r1, r4, 0
	bl CopySpeciesNametoBuffer
	adds r0, r6, 0
	adds r1, r6, 0
	bl CopyStringtoBuffer
	movs r0, 0x40
	strb r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r7, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r6, 0
	movs r3, 0x43
	bl sub_808CFD0
	add r0, sp, 0x8
	bl sub_808D1DC
	ldr r0, _0803A458
	cmp r5, r0
	ble _0803A3E8
	mov r0, r9
	str r0, [sp, 0x80]
	mov r0, r10
	movs r1, 0x1
	bl WriteSavetoPak
	add sp, 0x84
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A454: .4byte 0x00001006
_0803A458: .4byte 0x0000012b
	thumb_func_end sub_803A3BC

        .align 2,0
