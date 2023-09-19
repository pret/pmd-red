        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8023758
sub_8023758:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _080237DC
	ldr r2, [r3]
	ldr r1, [r2, 0x8]
	lsls r0, r1, 1
	adds r0, 0xA
	adds r2, r0
	mov r9, r2
	movs r2, 0
	subs r1, 0x1
	cmp r2, r1
	bge _080237CC
_08023778:
	mov r5, r9
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r7, r0, 0x1
	adds r0, r2, 0x1
	mov r8, r0
	cmp r7, r2
	ble _080237BE
_08023788:
	subs r6, r5, 0x2
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0x1
	str r2, [sp]
	bl GetAlphabetParentNo
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0x1
	bl GetAlphabetParentNo
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp]
	cmp r4, r0
	ble _080237B6
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_080237B6:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08023788
_080237BE:
	mov r2, r8
	ldr r3, _080237DC
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r0, 0x1
	cmp r2, r0
	blt _08023778
_080237CC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080237DC: .4byte gUnknown_3001B5C
	thumb_func_end sub_8023758

	thumb_func_start sub_80237E0
sub_80237E0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _08023864
	ldr r2, [r3]
	ldr r1, [r2, 0x8]
	lsls r0, r1, 1
	adds r0, 0xA
	adds r2, r0
	mov r9, r2
	movs r2, 0
	subs r1, 0x1
	cmp r2, r1
	bge _08023854
_08023800:
	mov r5, r9
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r7, r0, 0x1
	adds r0, r2, 0x1
	mov r8, r0
	cmp r7, r2
	ble _08023846
_08023810:
	subs r6, r5, 0x2
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0
	str r2, [sp]
	bl GetAlphabetParentNo
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0
	bl GetAlphabetParentNo
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp]
	cmp r4, r0
	ble _0802383E
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_0802383E:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08023810
_08023846:
	mov r2, r8
	ldr r3, _08023864
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r0, 0x1
	cmp r2, r0
	blt _08023800
_08023854:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023864: .4byte gUnknown_3001B5C
	thumb_func_end sub_80237E0