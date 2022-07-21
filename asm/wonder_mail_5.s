        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8030E48
sub_8030E48:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x15C
	ldr r3, _08030EA8
	ldr r4, _08030EAC
	ldr r2, [r4]
	ldrb r1, [r2, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r0, [r2, 0x10]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [sp, 0x4]
	add r1, sp, 0x44
	movs r2, 0
	movs r0, 0x7
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x46
	strb r2, [r0]
	add r0, sp, 0x48
	strb r2, [r0]
	adds r0, r5, 0x4
	str r0, [sp, 0xC]
	adds r0, 0x10
	str r0, [sp, 0x10]
	add r1, sp, 0x4
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x10]
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x12]
	adds r0, r1, 0
	strb r2, [r0, 0x14]
	adds r2, r5, 0
	adds r2, 0x22
	ldrb r0, [r2]
	cmp r0, 0
	bne _08030EB0
	adds r1, 0x2E
	movs r0, 0x5
	strb r0, [r1]
	b _08030EBE
	.align 2, 0
_08030EA8: .4byte gUnknown_203B480
_08030EAC: .4byte gUnknown_203B324
_08030EB0:
	mov r1, sp
	adds r1, 0x32
	movs r0, 0x2
	strb r0, [r1]
	ldrb r1, [r2]
	add r0, sp, 0x38
	strb r1, [r0]
_08030EBE:
	ldrb r0, [r5]
	cmp r0, 0x2
	beq _08030ED2
	cmp r0, 0x2
	ble _08030EE2
	cmp r0, 0x4
	beq _08030ED2
	cmp r0, 0x5
	beq _08030EDA
	b _08030EE2
_08030ED2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xA
	b _08030EE8
_08030EDA:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xB
	b _08030EE8
_08030EE2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0x9
_08030EE8:
	strb r0, [r1]
	add r0, sp, 0x4
	bl CreateRescueDescription
	ldrh r0, [r5, 0x10]
	ldr r1, _08030F48
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r2, _08030F4C
	ldr r5, _08030F50
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0x68
	bl xxx_call_draw_string
	add r6, sp, 0x5C
	ldr r1, _08030F54
	adds r0, r6, 0
	adds r2, r4, 0
	bl sprintf_2
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x44
	movs r1, 0x68
	adds r2, r6, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0x15C
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030F48: .4byte 0x00002710
_08030F4C: .4byte gUnknown_80E0934
_08030F50: .4byte gUnknown_203B324
_08030F54: .4byte gUnknown_80E0938
	thumb_func_end sub_8030E48

        .align 2,0
