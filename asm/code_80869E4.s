	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_80869E4
sub_80869E4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	asrs r6, r3, 24
	ldr r0, [r7, 0x70]
	adds r0, 0x46
	movs r4, 0
	ldrsb r4, [r0, r4]
	cmp r4, r6
	beq _08086A30
	adds r5, r0, 0
_08086A08:
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, r8
	bl sub_8002A70
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x7
	ands r0, r4
	strb r0, [r5]
	ldrb r1, [r5]
	adds r0, r7, 0
	bl sub_806CE68
	mov r0, r9
	movs r1, 0x46
	bl sub_803E708
	cmp r4, r6
	bne _08086A08
_08086A30:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80869E4

        .align 2,0
