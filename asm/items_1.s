	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8091DC0
sub_8091DC0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x8
	bl sub_8094924
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091DC0

	thumb_func_start sub_8091DE0
sub_8091DE0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x8
	bl sub_809488C
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091DE0

	thumb_func_start sub_8091E00
sub_8091E00:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_8094924
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x8
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091E00

	thumb_func_start sub_8091E28
sub_8091E28:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_809488C
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x8
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091E28

	thumb_func_start sub_8091E50
sub_8091E50:
	lsls r0, 24
	ldr r1, _08091E5C
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08091E5C: .4byte gUnknown_810AF50
	thumb_func_end sub_8091E50

	thumb_func_start sub_8091E60
sub_8091E60:
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r1, 24
	lsrs r4, r0, 24
	cmp r3, 0x3E
	bhi _08091E8C
	ldr r2, _08091E88
	lsrs r0, 27
	lsls r1, r3, 5
	adds r0, r1
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x7
	ands r1, r4
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	b _08091E8E
	.align 2, 0
_08091E88: .4byte gUnknown_8108F64
_08091E8C:
	movs r0, 0
_08091E8E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8091E60

	thumb_func_start sub_8091E94
sub_8091E94:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08091EE4
	add sp, r4
	mov r8, r1
	mov r10, r2
	ldr r1, _08091EE8
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	movs r3, 0
	add r1, sp, 0x18
	mov r9, r1
	ldr r2, _08091EEC
	mov r12, r2
	add r6, sp, 0x1F8
	ldr r2, [r0]
	adds r7, r6, 0
	movs r4, 0
_08091EC0:
	ldrh r1, [r2]
	cmp r1, r12
	bls _08091EF4
	ldrh r0, [r2]
	ldr r1, _08091EF0
	adds r0, r1
	cmp r0, 0
	beq _08091EFC
	movs r5, 0
	adds r1, r7, r4
_08091ED4:
	strh r5, [r1]
	adds r1, 0x2
	adds r4, 0x2
	adds r3, 0x1
	subs r0, 0x1
	cmp r0, 0
	bne _08091ED4
	b _08091EFC
	.align 2, 0
_08091EE4: .4byte 0xfffffc10
_08091EE8: .4byte gUnknown_8108E58
_08091EEC: .4byte 0x0000752f
_08091EF0: .4byte 0xffff8ad0
_08091EF4:
	adds r0, r6, r4
	strh r1, [r0]
	adds r4, 0x2
	adds r3, 0x1
_08091EFC:
	adds r2, 0x2
	cmp r3, 0xFB
	ble _08091EC0
	movs r3, 0xB
	add r2, sp, 0x1F8
	mov r1, sp
_08091F08:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08091F08
	mov r2, r9
	add r1, sp, 0x210
	movs r3, 0xEF
_08091F1C:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, 0x2
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08091F1C
	movs r7, 0xC
	movs r6, 0
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _08091F4A
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, r8
	blt _08091F4A
	movs r7, 0
	b _08091F66
_08091F46:
	mov r8, r5
	b _08091F9C
_08091F4A:
	adds r6, 0x1
	cmp r6, 0xB
	bgt _08091F66
	lsls r0, r6, 1
	mov r2, sp
	adds r1, r2, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08091F4A
	cmp r0, r8
	blt _08091F4A
	lsls r0, r6, 24
	lsrs r7, r0, 24
_08091F66:
	movs r0, 0x46
	mov r8, r0
	cmp r7, 0xC
	beq _08091F9C
	movs r6, 0
	mov r4, r9
_08091F72:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08091F94
	lsls r0, r6, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r7
	bne _08091F94
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, r10
	bge _08091F46
_08091F94:
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0xEF
	ble _08091F72
_08091F9C:
	mov r0, r8
	movs r3, 0xFC
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8091E94

	thumb_func_start sub_8091FB4
sub_8091FB4:
	push {r4-r6,lr}
	movs r6, 0
_08091FB8:
	ldr r0, _08092038
	lsls r1, r6, 2
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08091FE8
	movs r0, 0xF7
	ands r0, r1
	movs r5, 0
	strb r0, [r4]
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _08091FE8
	adds r0, r4, 0
	bl GetMoneyValue
	bl AddToTeamMoney
	strb r5, [r4, 0x2]
	strb r5, [r4, 0x1]
	strb r5, [r4]
_08091FE8:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08091FB8
	bl FillInventoryGaps
	movs r6, 0
_08091FF4:
	movs r0, 0x58
	adds r1, r6, 0
	muls r1, r0
	ldr r0, _0809203C
	ldr r0, [r0]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092026
	adds r4, r2, 0
	adds r4, 0x28
	ldrb r0, [r4]
	cmp r0, 0
	beq _08092026
	cmp r0, 0x69
	bne _08092026
	adds r0, r4, 0
	bl GetMoneyValue2
	bl AddToTeamMoney
	movs r0, 0
	strb r0, [r4]
_08092026:
	adds r6, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r6, r0
	ble _08091FF4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092038: .4byte gTeamInventory_203B460
_0809203C: .4byte gRecruitedPokemonRef
	thumb_func_end sub_8091FB4

        .align 2,0