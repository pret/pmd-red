        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start SetMenuItems
SetMenuItems:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r0, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	adds r0, r4
	ldm r3!, {r1,r2,r7}
	stm r0!, {r1,r2,r7}
	ldm r3!, {r1,r2,r7}
	stm r0!, {r1,r2,r7}
	bl ResetUnusedInputStruct
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	mov r0, r8
	cmp r0, 0
	beq _08035C90
	lsls r4, r5, 2
	adds r0, r4, r5
	lsls r0, 4
	adds r0, r6, r0
	ldr r1, [sp, 0x28]
	str r1, [sp]
	str r5, [sp, 0x4]
	ldr r1, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _08035CA8
_08035C90:
	lsls r4, r5, 2
	adds r0, r4, r5
	lsls r0, 4
	adds r0, r6, r0
	mov r1, r8
	str r1, [sp]
	str r5, [sp, 0x4]
	ldr r1, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl sub_8012E04
_08035CA8:
	adds r0, r4, r5
	lsls r0, 4
	adds r0, r6
	adds r0, 0x4C
	movs r1, 0x1
	strb r1, [r0]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end SetMenuItems

        .align 2,0
