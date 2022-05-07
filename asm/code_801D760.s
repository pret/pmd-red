	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_801DB54
sub_801DB54:
	push {r4,lr}
	ldr r4, _0801DBD0
	ldr r0, [r4]
	adds r0, 0x9C
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9D
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DBD0: .4byte gUnknown_203B258
	thumb_func_end sub_801DB54

	thumb_func_start sub_801DBD4
sub_801DBD4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r5, _0801DCB4
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0801DCB8
	ldr r0, [r5]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r4, [r0]
	lsls r4, 3
	subs r4, 0x2
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r6, 0
	ldr r0, [r5]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0801DC9C
	adds r7, r5, 0
	mov r8, r6
_0801DC34:
	ldr r0, [r7]
	ldrh r2, [r0, 0x1E]
	ldrh r1, [r0, 0x1C]
	adds r3, r2, 0
	muls r3, r1
	adds r1, r3, 0
	adds r1, r6
	lsls r1, 16
	asrs r1, 16
	lsls r5, r1, 1
	adds r5, r1
	lsls r5, 2
	ldr r1, _0801DCBC
	adds r5, r1
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	lsls r4, r1, 3
	subs r4, r1
	lsls r4, 2
	ldr r1, _0801DCC0
	adds r4, r1
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4]
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x8
	bl xxx_call_draw_string
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r5, 0x8]
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x3E
	bl xxx_call_draw_string
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0801DC34
_0801DC9C:
	ldr r0, _0801DCB4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DCB4: .4byte gUnknown_203B258
_0801DCB8: .4byte gUnknown_80DBFA0
_0801DCBC: .4byte gUnknown_811BAF4
_0801DCC0: .4byte gUnknown_81188F0
	thumb_func_end sub_801DBD4


        .align 2,0
