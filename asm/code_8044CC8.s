	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8045064
sub_8045064:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r1, 0
	ldr r0, _080450D4
	mov r8, r0
	ldr r0, [r0]
	cmp r1, r0
	bge _080450C8
	mov r7, r8
	ldr r2, _080450D8
	mov r9, r2
	ldr r0, _080450DC
	mov r12, r0
_08045082:
	adds r4, r1, 0x1
	ldr r0, [r7]
	adds r5, r4, 0
	cmp r5, r0
	bge _080450BE
	lsls r0, r1, 2
	mov r1, r12
	adds r3, r0, r1
	mov r6, r9
	lsls r0, r5, 2
	adds r2, r0, r1
_08045098:
	ldrh r1, [r3]
	lsls r1, 3
	adds r1, r6
	ldrh r0, [r2]
	lsls r0, 3
	adds r0, r6
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	ble _080450B4
	ldr r1, [r3]
	ldr r0, [r2]
	str r0, [r3]
	str r1, [r2]
_080450B4:
	adds r2, 0x4
	adds r4, 0x1
	ldr r0, [r7]
	cmp r4, r0
	blt _08045098
_080450BE:
	adds r1, r5, 0
	mov r2, r8
	ldr r0, [r2]
	cmp r1, r0
	blt _08045082
_080450C8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080450D4: .4byte gUnknown_202EE6C
_080450D8: .4byte gUnknown_80F7C54
_080450DC: .4byte gUnknown_202EE44
	thumb_func_end sub_8045064
