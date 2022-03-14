        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start DisplayMissionObjectives
DisplayMissionObjectives:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xDC
	ldr r7, _08031B24
	ldr r0, [r7]
	ldr r0, [r0, 0x10]
	bl sub_80073B8
	ldr r2, _08031B28
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	movs r6, 0
	str r6, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r7]
	ldrb r0, [r1, 0xC]
	cmp r0, 0x1
	beq _08031B2C
	cmp r0, 0x1
	bgt _08031B1E
	b _08031CD4
_08031B1E:
	cmp r0, 0x2
	beq _08031B94
	b _08031CD4
	.align 2, 0
_08031B24: .4byte gUnknown_203B330
_08031B28: .4byte gUnknown_80E1F30
_08031B2C:
	add r4, sp, 0x68
	adds r0, r4, 0
	bl sub_8099394
	ldrb r0, [r4]
	bl sub_8095228
	adds r5, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	movs r0, 0xA
	movs r1, 0x10
	movs r2, 0x3
	bl sub_803B6B0
	ldr r1, _08031B8C
	ldrb r2, [r5, 0x5]
	add r0, sp, 0x4
	bl sprintf_2
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r6, [sp]
	movs r0, 0x15
	movs r1, 0x10
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldr r4, _08031B90
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sprintf_2
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r6, [sp]
	movs r0, 0x28
	movs r1, 0x10
	add r2, sp, 0x4
	bl xxx_call_draw_string
	b _08031D4E
	.align 2, 0
_08031B8C: .4byte gUnknown_80E1F3C
_08031B90: .4byte gUnknown_80E1F40
_08031B94:
	ldrb r0, [r1, 0xD]
	bl sub_80969D0
	adds r1, r0, 0
	cmp r1, 0
	bne _08031BB0
	ldr r2, _08031BAC
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	str r1, [sp]
	b _08031D2C
	.align 2, 0
_08031BAC: .4byte gUnknown_80E1F54
_08031BB0:
	movs r6, 0x10
	movs r2, 0
	mov r10, r2
	mov r8, r2
	ldr r0, _08031C28
	mov r9, r0
	mov r1, sp
	adds r1, 0x6C
	str r1, [sp, 0xD8]
_08031BC2:
	mov r2, r10
	lsls r0, r2, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r4, r0, 0
	ldr r1, [r7]
	ldrb r0, [r4, 0x4]
	ldrb r2, [r1, 0xD]
	cmp r0, r2
	bne _08031CC2
	ldrb r0, [r4]
	cmp r0, 0
	beq _08031CC2
	cmp r0, 0x5
	beq _08031CC2
	cmp r0, 0x7
	beq _08031CC2
	ldr r3, [r1, 0x10]
	movs r0, 0xA
	adds r1, r6, 0
	movs r2, 0x3
	bl sub_803B6B0
	ldrb r0, [r4, 0x1]
	add r5, sp, 0x6C
	cmp r0, 0x3
	beq _08031C16
	ldrb r2, [r4, 0x5]
	ldr r0, [sp, 0xD8]
	ldr r1, _08031C2C
	bl sprintf_2
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x15
	adds r1, r6, 0
	ldr r2, [sp, 0xD8]
	bl xxx_call_draw_string
_08031C16:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x3
	beq _08031C58
	cmp r0, 0x3
	bgt _08031C30
	cmp r0, 0x2
	beq _08031C70
	b _08031C9C
	.align 2, 0
_08031C28: .4byte gUnknown_202DE58
_08031C2C: .4byte gUnknown_80E1F3C
_08031C30:
	cmp r0, 0x4
	bne _08031C9C
	ldrb r1, [r4, 0x10]
	mov r0, r9
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	ldr r1, _08031C54
	mov r2, r9
	bl sprintf_2
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r1, r8
	str r1, [sp]
	b _08031C8A
	.align 2, 0
_08031C54: .4byte gUnknown_80E1F60
_08031C58:
	ldrb r1, [r4, 0x10]
	mov r0, r9
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	ldr r1, _08031C6C
	mov r2, r9
	b _08031C7E
	.align 2, 0
_08031C6C: .4byte gUnknown_80E1F70
_08031C70:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	adds r0, r5, 0
	ldr r1, _08031C98
_08031C7E:
	bl sprintf_2
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r2, r8
	str r2, [sp]
_08031C8A:
	movs r0, 0x28
	adds r1, r6, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
	b _08031CC0
	.align 2, 0
_08031C98: .4byte gUnknown_80E1F80
_08031C9C:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetMonSpecies
	adds r2, r0, 0
	adds r0, r5, 0
	ldr r1, _08031CD0
	bl sprintf_2
	ldr r0, [r7]
	ldr r3, [r0, 0x10]
	mov r2, r8
	str r2, [sp]
	movs r0, 0x28
	adds r1, r6, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
_08031CC0:
	adds r6, 0xC
_08031CC2:
	movs r0, 0x1
	add r10, r0
	mov r1, r10
	cmp r1, 0x7
	bgt _08031CCE
	b _08031BC2
_08031CCE:
	b _08031D4E
	.align 2, 0
_08031CD0: .4byte gUnknown_80E1F40
_08031CD4:
	add r0, sp, 0xD0
	mov r4, sp
	adds r4, 0xD2
	adds r1, r4, 0
	bl sub_80992E0
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _08031D04
	movs r2, 0
	ldrsh r0, [r4, r2]
	bl GetCurrentMissionText
	adds r2, r0, 0
	ldr r0, _08031D00
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	movs r0, 0
	str r0, [sp]
	b _08031D2C
	.align 2, 0
_08031D00: .4byte gUnknown_203B330
_08031D04:
	add r4, sp, 0xD4
	adds r0, r4, 0
	bl sub_8099360
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08031D3C
	ldrb r0, [r4]
	bl sub_80A2688
	lsls r0, 16
	asrs r0, 16
	bl sub_80975DC
	adds r2, r0, 0
	ldr r0, _08031D38
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	str r5, [sp]
_08031D2C:
	movs r0, 0xA
	movs r1, 0x10
	bl xxx_call_draw_string
	b _08031D4E
	.align 2, 0
_08031D38: .4byte gUnknown_203B330
_08031D3C:
	ldr r2, _08031D68
	ldr r0, _08031D6C
	ldr r0, [r0]
	ldr r3, [r0, 0x10]
	str r1, [sp]
	movs r0, 0xA
	movs r1, 0x10
	bl xxx_call_draw_string
_08031D4E:
	ldr r0, _08031D6C
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0xDC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031D68: .4byte gUnknown_80E1F94
_08031D6C: .4byte gUnknown_203B330
	thumb_func_end DisplayMissionObjectives

        .align 2,0
