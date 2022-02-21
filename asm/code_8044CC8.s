	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8044CC8
sub_8044CC8:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldrb r1, [r2]
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _08044CEC
	ldr r0, _08044CE8
	ldrb r1, [r2]
	lsls r1, 2
	subs r1, 0x4
	ldr r0, [r0]
	adds r0, r1
	b _08044D34
	.align 2, 0
_08044CE8: .4byte gTeamInventory_203B460
_08044CEC:
	adds r0, r1, 0
	cmp r0, 0x80
	bne _08044D06
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl GetMapTile_1
	ldr r0, [r0, 0x14]
	bl GetItemData
	b _08044D34
_08044D06:
	cmp r0, 0x81
	bne _08044D0E
	ldr r0, [r3, 0x70]
	b _08044D32
_08044D0E:
	adds r0, r1, 0
	adds r0, 0x70
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08044D1E
	movs r0, 0
	b _08044D34
_08044D1E:
	ldr r0, _08044D38
	ldr r1, [r0]
	ldrb r0, [r2]
	subs r0, 0x90
	lsls r0, 2
	ldr r2, _08044D3C
	adds r1, r2
	adds r1, r0
	ldr r0, [r1]
	ldr r0, [r0, 0x70]
_08044D32:
	adds r0, 0x60
_08044D34:
	pop {r1}
	bx r1
	.align 2, 0
_08044D38: .4byte gDungeonGlobalData
_08044D3C: .4byte 0x0001357c
	thumb_func_end sub_8044CC8

	thumb_func_start sub_8044D40
sub_8044D40:
	push {lr}
	lsls r1, 3
	adds r1, 0x4
	adds r2, r0, r1
	ldrb r1, [r2]
	subs r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bhi _08044D74
	ldr r1, _08044D70
	ldrb r0, [r2]
	lsls r0, 2
	subs r0, 0x4
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	strb r0, [r1]
	bl FillInventoryGaps
	b _08044D88
	.align 2, 0
_08044D70: .4byte gTeamInventory_203B460
_08044D74:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x80
	beq _08044D80
	movs r0, 0
	b _08044D8A
_08044D80:
	adds r0, r2, 0x4
	movs r1, 0x1
	bl sub_80461C8
_08044D88:
	movs r0, 0x1
_08044D8A:
	pop {r1}
	bx r1
	thumb_func_end sub_8044D40

	thumb_func_start sub_8044D90
sub_8044D90:
	push {lr}
	ldr r3, [r0, 0x70]
	lsls r1, 3
	adds r1, 0x48
	adds r3, r1
	adds r1, r3, 0
	bl sub_8044CC8
	pop {r1}
	bx r1
	thumb_func_end sub_8044D90

	thumb_func_start sub_8044DA4
sub_8044DA4:
	ldr r0, [r0, 0x70]
	ldr r2, _08044DC0
	ldr r2, [r2]
	lsls r1, 3
	adds r0, r1
	adds r0, 0x48
	ldrb r0, [r0]
	lsls r0, 2
	ldr r1, _08044DC4
	adds r2, r1
	adds r2, r0
	ldr r0, [r2]
	bx lr
	.align 2, 0
_08044DC0: .4byte gDungeonGlobalData
_08044DC4: .4byte 0x0001357c
	thumb_func_end sub_8044DA4

	thumb_func_start sub_8044DC8
sub_8044DC8:
	push {r4,lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0xE9
	beq _08044DE8
	ldr r4, _08044DE4
	bl GetItemType
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r0, [r0]
	b _08044DEA
	.align 2, 0
_08044DE4: .4byte gUnknown_80F6964
_08044DE8:
	movs r0, 0x35
_08044DEA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8044DC8

	thumb_func_start sub_8044DF0
sub_8044DF0:
	push {r4,lr}
	ldr r4, [r0, 0x70]
	bl sub_8044D90
	adds r1, r0, 0
	adds r0, r4, 0
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x80
	bne _08044E10
	adds r0, r4, 0
	adds r0, 0x4C
	movs r1, 0x1
	bl sub_80461C8
	b _08044E1C
_08044E10:
	movs r0, 0
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	strb r0, [r1]
	bl FillInventoryGaps
_08044E1C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8044DF0

	thumb_func_start sub_8044E24
sub_8044E24:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	bl sub_8044D90
	adds r5, r0, 0
	ldr r0, [r4, 0x70]
	mov r8, r0
	ldrb r0, [r5, 0x2]
	bl IsHMItem
	lsls r0, 24
	cmp r0, 0
	bne _08044EBA
	ldrb r0, [r5, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08044EB0
	lsls r1, r6, 3
	mov r2, r8
	adds r0, r2, r1
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x80
	bne _08044EA4
	ldr r0, [r5]
	str r0, [sp]
	adds r4, r1, r2
	adds r4, 0x4C
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80461C8
	ldrb r1, [r5, 0x2]
	subs r1, 0x7D
	lsls r1, 24
	lsrs r1, 16
	ldr r2, _08044E9C
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	ldr r1, _08044EA0
	ands r0, r1
	movs r1, 0xF8
	lsls r1, 15
	orrs r0, r1
	str r0, [sp]
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_80460F8
	b _08044EBA
	.align 2, 0
_08044E9C: .4byte 0xffff00ff
_08044EA0: .4byte 0xff00ffff
_08044EA4:
	ldrb r0, [r5, 0x2]
	subs r0, 0x7D
	strb r0, [r5, 0x1]
	movs r0, 0x7C
	strb r0, [r5, 0x2]
	b _08044EBA
_08044EB0:
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8044DF0
_08044EBA:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8044E24

	thumb_func_start sub_8044EC8
sub_8044EC8:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08044EE8
	lsls r0, r5, 2
	adds r0, r1
	ldrh r4, [r0]
	cmp r4, 0x26
	bne _08044EF0
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08044EF0
	ldr r0, _08044EEC
	b _08044F2C
	.align 2, 0
_08044EE8: .4byte gUnknown_202EE44
_08044EEC: .4byte gUnknown_80F91EC
_08044EF0:
	ldr r1, _08044F10
	lsls r0, r4, 3
	adds r4, r0, r1
	ldr r0, [r4]
	ldr r1, _08044F14
	bl strcmp
	cmp r0, 0
	beq _08044F04
	movs r0, 0x1
_08044F04:
	lsls r0, 24
	cmp r0, 0
	beq _08044F18
	ldr r0, [r4]
	b _08044F2E
	.align 2, 0
_08044F10: .4byte gUnknown_80F7C50
_08044F14: .4byte gUnknown_80F697C
_08044F18:
	ldr r4, _08044F34
	ldr r1, _08044F38
	lsls r0, r5, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	bl GetItemCategory
	lsls r0, 3
	adds r4, 0x4
	adds r0, r4
_08044F2C:
	ldr r0, [r0]
_08044F2E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08044F34: .4byte gActions
_08044F38: .4byte gUnknown_202EE44
	thumb_func_end sub_8044EC8

	thumb_func_start sub_8044F3C
sub_8044F3C:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	blt _08044F54
	ldr r0, _08044F50
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x3]
	b _08044F56
	.align 2, 0
_08044F50: .4byte gUnknown_202EE44
_08044F54:
	movs r0, 0
_08044F56:
	pop {r1}
	bx r1
	thumb_func_end sub_8044F3C

	thumb_func_start sub_8044F5C
sub_8044F5C:
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, _08044FAC
	ldr r2, [r0]
	adds r6, r0, 0
	cmp r2, 0x9
	bgt _08044FA4
	movs r3, 0
	ldr r5, _08044FB0
	cmp r3, r2
	bge _08044F8A
	adds r1, r2, 0
	adds r2, r5, 0
_08044F7C:
	ldrh r0, [r2]
	cmp r0, r4
	beq _08044FA4
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, r1
	blt _08044F7C
_08044F8A:
	ldr r0, [r6]
	lsls r0, 2
	adds r0, r5
	strh r4, [r0]
	strb r7, [r0, 0x2]
	ldr r0, [r6]
	lsls r0, 2
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0, 0x3]
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
_08044FA4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044FAC: .4byte gUnknown_202EE6C
_08044FB0: .4byte gUnknown_202EE44
	thumb_func_end sub_8044F5C

	thumb_func_start sub_8044FB4
sub_8044FB4:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	movs r1, 0
	ldr r0, _08044FD4
	ldr r0, [r0]
	cmp r1, r0
	bge _08044FE4
	adds r3, r0, 0
	ldr r2, _08044FD8
_08044FC8:
	ldrh r0, [r2]
	cmp r0, r4
	bne _08044FDC
	adds r0, r1, 0
	b _08044FE8
	.align 2, 0
_08044FD4: .4byte gUnknown_202EE6C
_08044FD8: .4byte gUnknown_202EE44
_08044FDC:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, r3
	blt _08044FC8
_08044FE4:
	movs r0, 0x1
	negs r0, r0
_08044FE8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8044FB4

	thumb_func_start sub_8044FF0
sub_8044FF0:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r1, _08045010
	ldr r0, [r1]
	cmp r2, r0
	bge _08045022
	movs r5, 0
	adds r4, r1, 0
	ldr r1, _08045014
_08045006:
	ldrh r0, [r1]
	cmp r0, r3
	bne _08045018
	strb r5, [r1, 0x3]
	b _08045022
	.align 2, 0
_08045010: .4byte gUnknown_202EE6C
_08045014: .4byte gUnknown_202EE44
_08045018:
	adds r1, 0x4
	adds r2, 0x1
	ldr r0, [r4]
	cmp r2, r0
	blt _08045006
_08045022:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8044FF0

	thumb_func_start IsNotAttacking
IsNotAttacking:
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	ldr r0, [r2, 0x70]
	adds r4, r0, 0
	adds r4, 0x44
	cmp r1, 0
	beq _08045044
	adds r0, r2, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0804505A
_08045044:
	ldrh r0, [r4]
	cmp r0, 0
	beq _0804505A
	cmp r0, 0x2
	beq _0804505A
	cmp r0, 0x1
	beq _0804505A
	cmp r0, 0x5
	beq _0804505A
	movs r0, 0
	b _0804505C
_0804505A:
	movs r0, 0x1
_0804505C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end IsNotAttacking

	thumb_func_start sub_8045064
sub_8045064:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r1, 0
	ldr r0, _080450D4
	mov r8, r0
	ldr r0, [r0]
	cmp r1, r0
	bge _080450C8
	mov r7, r8
	ldr r2, _080450D8
	mov r9, r2
	ldr r0, _080450DC
	mov r12, r0
_08045082:
	adds r4, r1, 0x1
	ldr r0, [r7]
	adds r5, r4, 0
	cmp r5, r0
	bge _080450BE
	lsls r0, r1, 2
	mov r1, r12
	adds r3, r0, r1
	mov r6, r9
	lsls r0, r5, 2
	adds r2, r0, r1
_08045098:
	ldrh r1, [r3]
	lsls r1, 3
	adds r1, r6
	ldrh r0, [r2]
	lsls r0, 3
	adds r0, r6
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	ble _080450B4
	ldr r1, [r3]
	ldr r0, [r2]
	str r0, [r3]
	str r1, [r2]
_080450B4:
	adds r2, 0x4
	adds r4, 0x1
	ldr r0, [r7]
	cmp r4, r0
	blt _08045098
_080450BE:
	adds r1, r5, 0
	mov r2, r8
	ldr r0, [r2]
	cmp r1, r0
	blt _08045082
_080450C8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080450D4: .4byte gUnknown_202EE6C
_080450D8: .4byte gUnknown_80F7C54
_080450DC: .4byte gUnknown_202EE44
	thumb_func_end sub_8045064
