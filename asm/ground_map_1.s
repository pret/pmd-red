	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CheckMapCollision_80A585C
CheckMapCollision_80A585C:
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r1, _080A5884
	ldr r2, [r1]
	ldr r1, _080A5888
	adds r2, r1
	ldr r1, [r0, 0x4]
	lsls r1, 8
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _080A588C
	adds r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r4, [r7, 0x4]
	cmp r0, 0
	bne _080A5890
_080A587E:
	movs r0, 0x1
	b _080A58C0
	.align 2, 0
_080A5884: .4byte gGroundMapDungeon_3001B70
_080A5888: .4byte 0x00000544
_080A588C: .4byte 0x00000405
_080A5890:
	cmp r4, 0
	ble _080A58BE
	movs r1, 0x80
	lsls r1, 1
	mov r12, r1
_080A589A:
	ldr r2, [r7]
	adds r3, r5, 0
	cmp r2, 0
	ble _080A58B6
	movs r6, 0x80
_080A58A4:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	adds r3, 0x1
	cmp r0, 0
	bne _080A587E
	subs r2, 0x1
	cmp r2, 0
	bgt _080A58A4
_080A58B6:
	add r5, r12
	subs r4, 0x1
	cmp r4, 0
	bgt _080A589A
_080A58BE:
	movs r0, 0
_080A58C0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckMapCollision_80A585C

	thumb_func_start sub_80A58C8
sub_80A58C8:
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r1, _080A58F0
	ldr r2, [r1]
	ldr r1, _080A58F4
	adds r2, r1
	ldr r1, [r0, 0x4]
	lsls r1, 8
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _080A58F8
	adds r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r4, [r7, 0x4]
	cmp r0, 0
	bne _080A58FC
_080A58EA:
	movs r0, 0x1
	b _080A592C
	.align 2, 0
_080A58F0: .4byte gGroundMapDungeon_3001B70
_080A58F4: .4byte 0x00000544
_080A58F8: .4byte 0x00000405
_080A58FC:
	cmp r4, 0
	ble _080A592A
	movs r1, 0x80
	lsls r1, 1
	mov r12, r1
_080A5906:
	ldr r2, [r7]
	adds r3, r5, 0
	cmp r2, 0
	ble _080A5922
	movs r6, 0x40
_080A5910:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	adds r3, 0x1
	cmp r0, 0
	bne _080A58EA
	subs r2, 0x1
	cmp r2, 0
	bgt _080A5910
_080A5922:
	add r5, r12
	subs r4, 0x1
	cmp r4, 0
	bgt _080A5906
_080A592A:
	movs r0, 0
_080A592C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A58C8

        .align 2,0
