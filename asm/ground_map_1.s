	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80A579C
sub_80A579C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r0, _080A5838
	ldr r3, [r0]
	cmp r3, 0
	beq _080A5854
	ldr r0, _080A583C
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xE4
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A5854
	adds r0, r1, 0
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	ldr r0, _080A5840
	adds r4, r0
	adds r0, r3, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GetDungeonBounds
	ldr r2, [r6]
	mov r12, r2
	movs r0, 0xF0
	lsls r0, 7
	add r0, r12
	str r0, [r6]
	ldr r3, [r6, 0x4]
	movs r7, 0xA0
	lsls r7, 7
	adds r0, r3, r7
	str r0, [r6, 0x4]
	ldr r2, [r5]
	ldr r1, _080A5844
	adds r0, r2, r1
	str r0, [r5]
	ldr r1, [r5, 0x4]
	ldr r7, _080A5848
	adds r0, r1, r7
	str r0, [r5, 0x4]
	movs r7, 0
	ldrsh r0, [r4, r7]
	cmp r0, 0xA
	bne _080A581E
	movs r0, 0x90
	lsls r0, 8
	add r0, r12
	str r0, [r6]
	movs r4, 0xD0
	lsls r4, 7
	adds r0, r3, r4
	str r0, [r6, 0x4]
	ldr r7, _080A584C
	adds r0, r2, r7
	str r0, [r5]
	ldr r2, _080A5850
	adds r0, r1, r2
	str r0, [r5, 0x4]
_080A581E:
	ldr r1, [r6]
	ldr r0, [r5]
	cmp r1, r0
	ble _080A5828
	str r1, [r5]
_080A5828:
	ldr r1, [r6, 0x4]
	ldr r0, [r5, 0x4]
	cmp r1, r0
	ble _080A5832
	str r1, [r5, 0x4]
_080A5832:
	movs r0, 0x1
	b _080A5856
	.align 2, 0
_080A5838: .4byte gGroundMapDungeon_3001B70
_080A583C: .4byte gGroundMapAction
_080A5840: .4byte gGroundMapConversionTable
_080A5844: .4byte 0xffff8800
_080A5848: .4byte 0xffffb000
_080A584C: .4byte 0xffff7000
_080A5850: .4byte 0xffff9800
_080A5854:
	movs r0, 0
_080A5856:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A579C

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
