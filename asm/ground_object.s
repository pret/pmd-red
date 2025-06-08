	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CallbackObjectGetPosHeightAndUnk
CallbackObjectGetPosHeightAndUnk:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectGetPosHeightAndUnk

	thumb_func_start CallbackObjectSetPosHeight
CallbackObjectSetPosHeight:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end CallbackObjectSetPosHeight

	thumb_func_start CallbackObjectGetDirection
CallbackObjectGetDirection:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end CallbackObjectGetDirection

	thumb_func_start CallbackObjectSetDirection
CallbackObjectSetDirection:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC934
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AC934:
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectSetDirection

	thumb_func_start CallbackObjectSetEventIndex
CallbackObjectSetEventIndex:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AC958
	ldr r1, _080AC954
	lsls r0, 1
	adds r0, r1
	b _080AC95E
	.align 2, 0
_080AC954: .4byte gUnknown_81183A0
_080AC958:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AC95E:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AC97C
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AC98C
_080AC97C:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AC990
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AC98C:
	movs r0, 0x1
	strb r0, [r1]
_080AC990:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectSetEventIndex

	thumb_func_start CallbackObjectSetUnk_80AC998
CallbackObjectSetUnk_80AC998:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AC9AA
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AC9AA:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectSetUnk_80AC998

	thumb_func_start CallbackObjectSpriteRelatedCheck_80AC9B8
CallbackObjectSpriteRelatedCheck_80AC9B8:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC9D6
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AC9D8
_080AC9D6:
	movs r0, 0x1
_080AC9D8:
	pop {r1}
	bx r1
	thumb_func_end CallbackObjectSpriteRelatedCheck_80AC9B8

	thumb_func_start CallbackObjectSpriteRelated_80AC9DC
CallbackObjectSpriteRelated_80AC9DC:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AC9FE
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080ACA00
_080AC9FE:
	movs r0, 0x1
_080ACA00:
	pop {r1}
	bx r1
	thumb_func_end CallbackObjectSpriteRelated_80AC9DC

	thumb_func_start CallbackObjectGetFlags
CallbackObjectGetFlags:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end CallbackObjectGetFlags

	thumb_func_start CallbackObjectSetFlags
CallbackObjectSetFlags:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1B0
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectSetFlags

	thumb_func_start CallbackObjectClearFlags
CallbackObjectClearFlags:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1F4
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectClearFlags

	thumb_func_start CallbackObjectMoveRelative
CallbackObjectMoveRelative:
	push {lr}
	bl TryMoveRelative_80AC720
	pop {r1}
	bx r1
	thumb_func_end CallbackObjectMoveRelative

	thumb_func_start GroundObject_Action
GroundObject_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080ACA7C
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080ACA54:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080ACAB2
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080ACA80
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080ACA84
	cmp r0, 0x4
	bne _080ACA90
	adds r0, r7, 0
	bl GroundObject_Delete
	b _080ACAB2
	.align 2, 0
_080ACA7C: .4byte gGroundObjects
_080ACA80: .4byte gUnknown_8118524
_080ACA84:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080ACAD0
	bl ExecutePredefinedScript
_080ACA90:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080ACAB2
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080ACAB2:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080ACA54
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAD0: .4byte gUnknown_8118530
	thumb_func_end GroundObject_Action

	thumb_func_start sub_80ACAD4
sub_80ACAD4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080ACB8C
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080ACAF2:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080ACB64
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080ACB40
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080ACB40:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080ACB5A
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080ACB5A:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7664
_080ACB64:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080ACAF2
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACB8C: .4byte gGroundObjects
	thumb_func_end sub_80ACAD4

        .align 2,0
