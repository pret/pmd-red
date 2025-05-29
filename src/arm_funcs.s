	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"
    
	.syntax unified

	.text	

    arm_func_start sub_80001E8
sub_80001E8:
	stmdb sp!, {r4-r11}
	mov r12, 0x4000000 @ REG_BASE
	ldr r11, _08000224
	add r10, r11, 0x40
	mov r9, 0x1
	mov r8, 0
	strb r8, [r12, 0x208] @ REG_IME
	ldmia r10, {r0-r7}
	stmia r10!, {r4-r7}
	stmia r10!, {r0-r3}
	ldr r0, [r11, 0x4]
	str r8, [r11, 0x4]
	strb r9, [r12, 0x208] @ REG_IME
	ldmia sp!, {r4-r11}
	bx lr
	.align 2, 0
_08000224: .4byte gUnknown_202DCF8
	arm_func_end sub_80001E8

	arm_func_start sub_8000228
sub_8000228:
	mov r12, 0x4000000
	add r12, r12, 0x120 @ REG_SIODATA32
	ldmia r12, {r0,r1}
	stmdb sp!, {r7-r11}
	ldr r11, _08000340
	mov r9, 0xFE
	add r9, r9, 0xFE00
	ldrh r3, [r12, 0x8]
	and r3, r3, 0x40
	strb r3, [r11, 0x9]
	ldr r10, [r11, 0x14]
	adds r3, r10, 0x1
	blt _08000284
	bne _08000278
	strh r9, [r12, 0xA]
	add r8, r11, 0x28
	ldmia r8, {r2,r3}
	mov r7, r2
	stmia r8, {r3,r7}
	b _08000284
_08000278:
	ldr r3, [r11, 0x2C]
	ldr r2, [r3, r10, lsl 1]
	strh r2, [r12, 0xA]
_08000284:
	cmp r10, 0xB
	addlt r10, r10, 0x1
	strlt r10, [r11, 0x14]
	stmdb sp!, {r0,r1,r5,r6}
	mov r6, 0x3
_08000298:
	add r8, r11, 0x18
	add r8, r8, r6, lsl 2
	ldr r10, [r8]
	mov r3, r6, lsl 1
	ldrh r5, [sp, r3]
	cmp r5, r9
	bne _080002C8
	cmp r10, 0x9
	ble _080002C8
	mov r0, 0x1
	sub r10, r0, 0x2
	b _080002F4
_080002C8:
	ldr r0, [r8, 0x18]
	mov r3, r10, lsl 1
	strh r5, [r0, r3]
	cmp r10, 0x9
	bne _080002F4
	ldr r1, [r8, 0x28]
	str r0, [r8, 0x28]
	str r1, [r8, 0x18]
	add r3, r11, 0x4
	mov r0, 0x1
	strb r0, [r3, r6]
_080002F4:
	cmp r10, 0xB
	addlt r10, r10, 0x1
	str r10, [r8]
	subs r6, r6, 0x1
	bge _08000298
	ldrb r0, [r11]
	cmp r0, 0
	beq _08000334
	ldr r7, _08000344 @ REG_TM3CNT_H
	mov r0, 0
	strh r0, [r7]
	ldrh r0, [r12, 0x8]
	orr r0, r0, 0x80
	strh r0, [r12, 0x8]
	mov r0, 0xC0
	strh r0, [r7]
_08000334:
	add sp, sp, 0x8
	ldmia sp!, {r5-r11}
	bx lr
	.align 2, 0
_08000340: .4byte gUnknown_202DCF8
_08000344: .4byte 0x0400010e
	arm_func_end sub_8000228

        .align 2,0
