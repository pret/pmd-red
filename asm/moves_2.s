	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8093C54
sub_8093C54:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093C86:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093C86
_08093CA6:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093CB0:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CC2
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093CC2:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093CB0
	cmp r4, 0x7
	bgt _08093CDE
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093CD4:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093CD4
_08093CDE:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093CE4:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093CE4
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093C54

	thumb_func_start sub_8093CF8
sub_8093CF8:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093D2A:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093D2A
_08093D4A:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093D54:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D66
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093D66:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093D54
	cmp r4, 0x7
	bgt _08093D82
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093D78:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093D78
_08093D82:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093D88:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093D88
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093CF8

	thumb_func_start sub_8093D9C
sub_8093D9C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl InitPokemonMove
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D9C

	thumb_func_start sub_8093DC4
sub_8093DC4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	mov r0, sp
	bl sub_8093F10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093DC4

	thumb_func_start sub_8093DE8
sub_8093DE8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08093E80
	add sp, r4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	adds r0, r5, 0
	bl sub_80073B8
	ldr r0, _08093E84
	adds r1, r6, 0
	movs r2, 0
	bl sub_80928C0
	lsls r4, 3
	adds r4, 0x10
	ldr r2, _08093E88
	movs r7, 0
	str r7, [sp]
	adds r0, r4, 0
	movs r1, 0
	adds r3, r5, 0
	bl xxx_format_and_draw
	movs r3, 0x13
	ldrh r1, [r6, 0x2]
	ldr r4, _08093E8C
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0, 0x1C]
	ldrb r0, [r2]
	cmp r0, 0x2A
	bne _08093E3A
	movs r3, 0x10
	adds r2, 0x1
_08093E3A:
	str r7, [sp]
	movs r0, 0x4
	adds r1, r3, 0
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8093E90
	adds r0, r5, 0
	bl sub_80073E0
	ldrh r1, [r6, 0x2]
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0, 0x1C]
	add r0, sp, 0x4
	bl strcpy
	add r0, sp, 0x4
	mov r1, r8
	bl sub_8097DF0
	movs r3, 0xC9
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08093E80: .4byte 0xfffffcdc
_08093E84: .4byte gAvailablePokemonNames
_08093E88: .4byte gUnknown_8109930
_08093E8C: .4byte gMovesData
	thumb_func_end sub_8093DE8

	thumb_func_start sub_8093E90
sub_8093E90:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0x7
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0x4
	movs r2, 0x48
	movs r3, 0xC8
	bl sub_80078A4
	ldr r0, _08093F00
	adds r1, r6, 0
	bl sub_8092D54
	ldr r0, _08093F04
	ldr r2, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x4A
	adds r3, r5, 0
	bl xxx_format_and_draw
	ldr r0, _08093F08
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x56
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl GetMoveType
	lsls r0, 24
	lsrs r0, 24
	bl GetUnformattedTypeString 
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x40
	movs r1, 0x56
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl GetMovePower
	ldr r1, _08093F0C
	str r0, [r1]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093F00: .4byte gAvailablePokemonNames
_08093F04: .4byte gUnknown_810CF00
_08093F08: .4byte gPtrTypeText
_08093F0C: .4byte gUnknown_202DE30
	thumb_func_end sub_8093E90

	thumb_func_start sub_8093F10
sub_8093F10:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F48
	movs r0, 0
	strb r1, [r3]
	strb r0, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F44
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F4A
	.align 2, 0
_08093F44: .4byte gMovesData
_08093F48:
	strb r0, [r3]
_08093F4A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F10

	thumb_func_start sub_8093F50
sub_8093F50:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r7, 0
	adds r3, r6, 0
	adds r4, r1, 0
	movs r5, 0x3
_08093F5C:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F8C
	strb r1, [r3]
	strb r7, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F88
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F8E
	.align 2, 0
_08093F88: .4byte gMovesData
_08093F8C:
	strb r0, [r3]
_08093F8E:
	adds r3, 0x8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08093F5C
	adds r1, r6, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F50

	thumb_func_start sub_8093FA8
sub_8093FA8:
	push {lr}
	adds r2, r0, 0
	movs r3, 0x3
_08093FAE:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x2]
	ldrb r0, [r1, 0x5]
	strb r0, [r2, 0x4]
	adds r2, 0x8
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093FAE
	pop {r0}
	bx r0
	thumb_func_end sub_8093FA8

	thumb_func_start sub_8093FC8
sub_8093FC8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r2, r1, 0
	movs r3, 0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094002
	movs r7, 0xFB
	movs r6, 0x1
	adds r4, r2, 0
	adds r2, r5, 0
_08093FE2:
	ldm r4!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2, 0x1]
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2, 0x1]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08094002
	ldrb r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08093FE2
_08094002:
	cmp r3, 0x7
	bgt _08094016
	movs r1, 0
	lsls r0, r3, 3
	adds r0, r5
_0809400C:
	strb r1, [r0]
	adds r0, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _0809400C
_08094016:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093FC8

	thumb_func_start sub_809401C
sub_809401C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	movs r2, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094046
	movs r6, 0x1
	adds r4, r5, 0
_08094032:
	ldm r3!, {r0,r1}
	stm r4!, {r0,r1}
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08094046
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08094032
_08094046:
	cmp r2, 0x7
	bgt _0809405A
	movs r1, 0
	lsls r0, r2, 3
	adds r0, r5
_08094050:
	strb r1, [r0]
	adds r0, 0x8
	adds r2, 0x1
	cmp r2, 0x7
	ble _08094050
_0809405A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809401C

	thumb_func_start sub_8094060
sub_8094060:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	movs r4, 0
	movs r5, 0
	adds r3, r6, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
_08094076:
	lsls r2, r4, 3
	adds r2, r7, r2
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r4, 0x1
_08094084:
	adds r5, 0x1
	cmp r5, 0x7
	bgt _0809409C
	lsls r0, r5, 3
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
	cmp r4, 0x3
	ble _08094076
_0809409C:
	cmp r4, 0x3
	bgt _080940B0
	movs r1, 0
	lsls r0, r4, 3
	adds r0, r7
_080940A6:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _080940A6
_080940B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8094060

        .align 2,0
