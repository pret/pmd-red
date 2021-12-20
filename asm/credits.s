        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start DrawCredits
DrawCredits:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x84
	mov r8, r0
	adds r5, r1, 0
	ldr r4, _080354C0
	movs r0, 0x6C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x60]
	str r5, [r0, 0x64]
	mov r1, r8
	str r1, [r0, 0x68]
	ldr r2, _080354C4
	mov r12, r2
	mov r9, r4
	movs r3, 0
	movs r2, 0x3
_08035472:
	ldr r1, [r4]
	adds r1, r3
	mov r0, r12
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08035472
	mov r0, r9
	ldr r1, [r0]
	ldr r0, _080354C8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	bl ResetUnusedInputStruct
	mov r1, r9
	ldr r0, [r1]
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x2
	bl sub_8099690
	movs r0, 0
	bl sub_80073B8
	mov r2, r8
	lsls r0, r2, 2
	ldr r1, _080354CC
	adds r0, r1
	ldr r1, [r0]
	movs r5, 0
	b _08035542
	.align 2, 0
_080354C0: .4byte gUnknown_203B340
_080354C4: .4byte gUnknown_80E4A10
_080354C8: .4byte gUnknown_80E4A28
_080354CC: .4byte gCreditsTable
_080354D0:
	ldr r2, [r1, 0x8]
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	cmp r0, 0
	blt _080354DE
	adds r5, r0, 0
	b _080354E4
_080354DE:
	movs r6, 0x4
	ldrsh r0, [r1, r6]
	subs r5, r0
_080354E4:
	movs r7, 0x2
	ldrsh r6, [r1, r7]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	beq _080354FA
	cmp r0, 0x2
	beq _08035514
	adds r4, r1, 0
	adds r4, 0xC
	b _08035532
_080354FA:
	add r3, sp, 0x4
	ldrb r0, [r2]
	adds r4, r1, 0
	adds r4, 0xC
	cmp r0, 0
	beq _0803552C
_08035506:
	strb r0, [r3]
	adds r2, 0x1
	adds r3, 0x1
	ldrb r0, [r2]
	cmp r0, 0
	bne _08035506
	b _0803552C
_08035514:
	add r3, sp, 0x4
	ldrb r0, [r2]
	adds r4, r1, 0
	adds r4, 0xC
	cmp r0, 0
	beq _0803552C
_08035520:
	strb r0, [r3]
	adds r2, 0x1
	adds r3, 0x1
	ldrb r0, [r2]
	cmp r0, 0
	bne _08035520
_0803552C:
	movs r0, 0
	strb r0, [r3]
	add r2, sp, 0x4
_08035532:
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r3, 0
	bl xxx_call_draw_string
	adds r1, r4, 0
_08035542:
	ldr r0, [r1, 0x8]
	cmp r0, 0
	bne _080354D0
	movs r0, 0
	bl sub_80073E0
	movs r0, 0
	bl SelectCharmap
	ldr r2, _08035570
	movs r0, 0x9
	movs r1, 0
	ldr r2, [r2]
	bl sub_8099AFC
	movs r0, 0x1
	add sp, 0x84
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08035570: .4byte gUnknown_80E4A40
	thumb_func_end DrawCredits

	thumb_func_start sub_8035574
sub_8035574:
	push {r4,lr}
	ldr r1, _0803558C
	ldr r0, [r1]
	ldr r0, [r0, 0x60]
	adds r4, r1, 0
	cmp r0, 0x4
	bhi _08035654
	lsls r0, 2
	ldr r1, _08035590
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803558C: .4byte gUnknown_203B340
_08035590: .4byte _08035594
	.align 2, 0
_08035594:
	.4byte _080355A8
	.4byte _080355D0
	.4byte _080355E8
	.4byte _08035610
	.4byte _08035638
_080355A8:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _08035654
	ldr r0, _080355C8
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1, 0x60]
	ldr r2, _080355CC
	movs r0, 0x9
	movs r1, 0x1E
	ldr r2, [r2]
	bl sub_8099A5C
	b _08035654
	.align 2, 0
_080355C8: .4byte gUnknown_203B340
_080355CC: .4byte gUnknown_80E4A40
_080355D0:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _08035654
	ldr r0, _080355E4
	ldr r1, [r0]
	movs r0, 0x2
	str r0, [r1, 0x60]
	b _08035654
	.align 2, 0
_080355E4: .4byte gUnknown_203B340
_080355E8:
	ldr r1, [r4]
	ldr r0, [r1, 0x64]
	cmp r0, 0
	bgt _08035600
	movs r0, 0x3
	str r0, [r1, 0x60]
	ldr r2, _0803560C
	movs r0, 0x9
	movs r1, 0x1E
	ldr r2, [r2]
	bl sub_8099AFC
_08035600:
	ldr r1, [r4]
	ldr r0, [r1, 0x64]
	subs r0, 0x1
	str r0, [r1, 0x64]
	b _08035654
	.align 2, 0
_0803560C: .4byte gUnknown_80E4A40
_08035610:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _08035654
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _08035634
	ldr r1, [r0]
	movs r0, 0x4
	str r0, [r1, 0x60]
	b _08035654
	.align 2, 0
_08035634: .4byte gUnknown_203B340
_08035638:
	movs r0, 0
	bl sub_8099690
	ldr r2, _08035650
	movs r0, 0x1
	movs r1, 0
	ldr r2, [r2]
	bl sub_8099A5C
	movs r0, 0x3
	b _08035656
	.align 2, 0
_08035650: .4byte gUnknown_80E4A40
_08035654:
	movs r0, 0
_08035656:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8035574

        .align 2,0
