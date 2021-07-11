	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80917B8
sub_80917B8:
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	bl IsThrowableItem
	lsls r0, 24
	cmp r0, 0
	beq _080917E0
	ldr r2, _080917DC
	ldr r1, [r2]
	ldrb r0, [r4, 0x2]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	ldrb r3, [r4, 0x1]
	adds r0, r3
	b _080917F0
	.align 2, 0
_080917DC: .4byte gTeamInventory_203B460
_080917E0:
	ldr r2, _0809180C
	ldr r1, [r2]
	ldrb r0, [r4, 0x2]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
_080917F0:
	strh r0, [r1]
	ldr r0, [r2]
	ldrb r1, [r4, 0x2]
	lsls r1, 1
	adds r0, 0x50
	adds r2, r0, r1
	ldrh r0, [r2]
	ldr r1, _08091810
	cmp r0, r1
	bls _08091806
	strh r1, [r2]
_08091806:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809180C: .4byte gTeamInventory_203B460
_08091810: .4byte 0x000003e7
	thumb_func_end sub_80917B8

	thumb_func_start sub_8091814
sub_8091814:
	push {lr}
	movs r3, 0
	ldr r0, _0809183C
	ldr r0, [r0]
	movs r2, 0x8C
	lsls r2, 2
	adds r1, r0, r2
	movs r2, 0x7
_08091824:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0809182C
	adds r3, 0x1
_0809182C:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _08091824
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809183C: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091814

	thumb_func_start sub_8091840
sub_8091840:
	lsls r0, 24
	ldr r1, _08091858
	lsrs r0, 22
	movs r2, 0x8C
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	bx lr
	.align 2, 0
_08091858: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091840

	thumb_func_start sub_809185C
sub_809185C:
	lsls r0, 24
	ldr r1, _08091870
	lsrs r0, 22
	movs r2, 0x8C
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_08091870: .4byte gTeamInventory_203B460
	thumb_func_end sub_809185C

	thumb_func_start sub_8091874
sub_8091874:
	push {r4-r7,lr}
	movs r2, 0
	movs r4, 0
	ldr r7, _08091884
	movs r6, 0x8C
	lsls r6, 2
	movs r3, 0
	b _080918A0
	.align 2, 0
_08091884: .4byte gTeamInventory_203B460
_08091888:
	cmp r2, r4
	ble _0809189A
	ldr r0, [r7]
	lsls r1, r4, 2
	adds r0, r6
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809189A:
	adds r3, 0x4
	adds r2, 0x1
	adds r4, 0x1
_080918A0:
	cmp r2, 0x7
	bgt _080918CA
	ldr r0, [r7]
	adds r0, r3
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _080918CA
	ldr r5, _080918E8
	movs r1, 0x8C
	lsls r1, 2
_080918B6:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x7
	bgt _080918CA
	ldr r0, [r5]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080918B6
_080918CA:
	cmp r2, 0x8
	bne _08091888
	cmp r4, 0x7
	bgt _080918E0
_080918D2:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091840
	adds r4, 0x1
	cmp r4, 0x7
	ble _080918D2
_080918E0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080918E8: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091874

	thumb_func_start sub_80918EC
sub_80918EC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
_080918F8:
	adds r1, r0, 0x1
	mov r8, r1
	mov r6, r8
	cmp r1, 0x7
	bgt _08091964
	ldr r1, _08091978
	mov r9, r1
	lsls r7, r0, 2
	movs r0, 0x8C
	lsls r0, 2
	mov r10, r0
_0809190E:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r7
	add r0, r10
	ldrb r0, [r0]
	bl GetItemOrder
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	lsls r5, r6, 2
	adds r0, r5
	add r0, r10
	ldrb r0, [r0]
	bl GetItemOrder
	cmp r4, r0
	bgt _0809194C
	cmp r4, r0
	bne _0809195E
	mov r1, r9
	ldr r0, [r1]
	adds r2, r0, r7
	ldr r1, _0809197C
	adds r2, r1
	adds r0, r5
	adds r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0809195E
_0809194C:
	mov r1, r9
	ldr r0, [r1]
	add r0, r10
	adds r2, r0, r7
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
_0809195E:
	adds r6, 0x1
	cmp r6, 0x7
	ble _0809190E
_08091964:
	mov r0, r8
	cmp r0, 0x6
	ble _080918F8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091978: .4byte gTeamInventory_203B460
_0809197C: .4byte 0x00000231
	thumb_func_end sub_80918EC

	thumb_func_start sub_8091980
sub_8091980:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r1, sp
	ldr r0, _080919F4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	movs r5, 0
_0809199C:
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_8091840
	adds r5, 0x1
	cmp r5, 0x7
	ble _0809199C
	mov r0, r8
	lsls r7, r0, 2
	ldr r6, _080919F8
	movs r5, 0x7
_080919B2:
	adds r0, r6, 0
	bl RandomCapped
	adds r4, r0, 0
	adds r0, r6, 0
	bl RandomCapped
	adds r2, r0, 0
	mov r1, sp
	adds r0, r1, r7
	ldr r0, [r0]
	adds r1, r4, 0
	bl sub_8091E94
	lsls r0, 24
	lsrs r0, 24
	bl sub_80919FC
	subs r5, 0x1
	cmp r5, 0
	bge _080919B2
	bl sub_80918EC
	mov r0, r8
	bl sub_8091BB4
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080919F4: .4byte gUnknown_81097E8
_080919F8: .4byte 0x0000270f
	thumb_func_end sub_8091980

	thumb_func_start sub_80919FC
sub_80919FC:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	bl sub_8090B08
	movs r3, 0
	ldr r5, _08091A34
	movs r4, 0x8C
	lsls r4, 2
_08091A14:
	ldr r1, [r5]
	lsls r2, r3, 2
	adds r0, r1, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08091A38
	movs r3, 0x8C
	lsls r3, 2
	adds r0, r1, r3
	adds r0, r2
	ldr r1, [sp]
	str r1, [r0]
	movs r0, 0
	b _08091A40
	.align 2, 0
_08091A34: .4byte gTeamInventory_203B460
_08091A38:
	adds r3, 0x1
	cmp r3, 0x7
	ble _08091A14
	movs r0, 0x1
_08091A40:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80919FC

	thumb_func_start sub_8091A48
sub_8091A48:
	push {lr}
	movs r3, 0
	ldr r0, _08091A70
	ldr r0, [r0]
	movs r2, 0x94
	lsls r2, 2
	adds r1, r0, r2
	movs r2, 0x3
_08091A58:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08091A60
	adds r3, 0x1
_08091A60:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _08091A58
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_08091A70: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091A48

	thumb_func_start sub_8091A74
sub_8091A74:
	lsls r0, 24
	ldr r1, _08091A8C
	lsrs r0, 22
	movs r2, 0x94
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	bx lr
	.align 2, 0
_08091A8C: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091A74

	thumb_func_start sub_8091A90
sub_8091A90:
	lsls r0, 24
	ldr r1, _08091AA4
	lsrs r0, 22
	movs r2, 0x94
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_08091AA4: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091A90

	thumb_func_start sub_8091AA8
sub_8091AA8:
	push {r4-r7,lr}
	movs r2, 0
	movs r4, 0
	ldr r7, _08091AB8
	movs r6, 0x94
	lsls r6, 2
	movs r3, 0
	b _08091AD4
	.align 2, 0
_08091AB8: .4byte gTeamInventory_203B460
_08091ABC:
	cmp r2, r4
	ble _08091ACE
	ldr r0, [r7]
	lsls r1, r4, 2
	adds r0, r6
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_08091ACE:
	adds r3, 0x4
	adds r2, 0x1
	adds r4, 0x1
_08091AD4:
	cmp r2, 0x3
	bgt _08091AFE
	ldr r0, [r7]
	adds r0, r3
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _08091AFE
	ldr r5, _08091B1C
	movs r1, 0x94
	lsls r1, 2
_08091AEA:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08091AFE
	ldr r0, [r5]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08091AEA
_08091AFE:
	cmp r2, 0x4
	bne _08091ABC
	cmp r4, 0x3
	bgt _08091B14
_08091B06:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091A74
	adds r4, 0x1
	cmp r4, 0x3
	ble _08091B06
_08091B14:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091B1C: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091AA8

	thumb_func_start sub_8091B20
sub_8091B20:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
_08091B2C:
	adds r1, r0, 0x1
	mov r8, r1
	mov r6, r8
	cmp r1, 0x3
	bgt _08091B98
	ldr r1, _08091BAC
	mov r9, r1
	lsls r7, r0, 2
	movs r0, 0x94
	lsls r0, 2
	mov r10, r0
_08091B42:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r7
	add r0, r10
	ldrb r0, [r0]
	bl GetItemOrder
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	lsls r5, r6, 2
	adds r0, r5
	add r0, r10
	ldrb r0, [r0]
	bl GetItemOrder
	cmp r4, r0
	bgt _08091B80
	cmp r4, r0
	bne _08091B92
	mov r1, r9
	ldr r0, [r1]
	adds r2, r0, r7
	ldr r1, _08091BB0
	adds r2, r1
	adds r0, r5
	adds r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _08091B92
_08091B80:
	mov r1, r9
	ldr r0, [r1]
	add r0, r10
	adds r2, r0, r7
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
_08091B92:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08091B42
_08091B98:
	mov r0, r8
	cmp r0, 0x2
	ble _08091B2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091BAC: .4byte gTeamInventory_203B460
_08091BB0: .4byte 0x00000251
	thumb_func_end sub_8091B20

	thumb_func_start sub_8091BB4
sub_8091BB4:
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	mov r1, sp
	ldr r0, _08091C14
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r5, 0
_08091BCA:
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_8091A74
	adds r5, 0x1
	cmp r5, 0x3
	ble _08091BCA
	lsls r7, r4, 2
	ldr r6, _08091C18
	movs r5, 0x3
_08091BDE:
	adds r0, r6, 0
	bl RandomCapped
	adds r4, r0, 0
	adds r0, r6, 0
	bl RandomCapped
	adds r2, r0, 0
	mov r1, sp
	adds r0, r1, r7
	ldr r0, [r0]
	adds r1, r4, 0
	bl sub_8091E94
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091C1C
	subs r5, 0x1
	cmp r5, 0
	bge _08091BDE
	bl sub_8091B20
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091C14: .4byte gUnknown_81097F8
_08091C18: .4byte 0x0000270f
	thumb_func_end sub_8091BB4

	thumb_func_start sub_8091C1C
sub_8091C1C:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	bl sub_8090B08
	movs r3, 0
	ldr r5, _08091C54
	movs r4, 0x94
	lsls r4, 2
_08091C34:
	ldr r1, [r5]
	lsls r2, r3, 2
	adds r0, r1, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08091C58
	movs r3, 0x94
	lsls r3, 2
	adds r0, r1, r3
	adds r0, r2
	ldr r1, [sp]
	str r1, [r0]
	movs r0, 0
	b _08091C60
	.align 2, 0
_08091C54: .4byte gTeamInventory_203B460
_08091C58:
	adds r3, 0x1
	cmp r3, 0x3
	ble _08091C34
	movs r0, 0x1
_08091C60:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8091C1C

	thumb_func_start sub_8091C68
sub_8091C68:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	movs r4, 0
	ldr r5, _08091D10
_08091C7C:
	lsls r0, r4, 2
	ldr r1, [r5]
	adds r1, r0
	mov r0, sp
	bl sub_8091E28
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091C7C
	ldr r6, _08091D10
	movs r5, 0x50
	movs r4, 0xEF
_08091C94:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r5, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _08091C94
	ldr r6, _08091D10
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0x7
_08091CB0:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DE0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091CB0
	ldr r6, _08091D10
	movs r5, 0x94
	lsls r5, 2
	movs r4, 0x3
_08091CCA:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DE0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091CCA
	ldr r4, _08091D10
	ldr r1, [r4]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	ldr r1, [r4]
	movs r0, 0x99
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08091D10: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091C68

	thumb_func_start sub_8091D14
sub_8091D14:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	movs r4, 0
	ldr r5, _08091DBC
_08091D28:
	lsls r0, r4, 2
	ldr r1, [r5]
	adds r1, r0
	mov r0, sp
	bl sub_8091E00
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091D28
	ldr r6, _08091DBC
	movs r5, 0x50
	movs r4, 0xEF
_08091D40:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r5, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _08091D40
	ldr r6, _08091DBC
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0x7
_08091D5C:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DC0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091D5C
	ldr r6, _08091DBC
	movs r5, 0x94
	lsls r5, 2
	movs r4, 0x3
_08091D76:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DC0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091D76
	ldr r4, _08091DBC
	ldr r1, [r4]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	ldr r1, [r4]
	movs r0, 0x99
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08091DBC: .4byte gTeamInventory_203B460
	thumb_func_end sub_8091D14

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
