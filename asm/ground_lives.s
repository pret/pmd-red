	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



	thumb_func_start sub_80A8D54
sub_80A8D54:
	push {r4,r5,lr}
	sub sp, 0x14
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl sub_80A7B94
	mov r0, sp
	ldrh r1, [r0]
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	beq _080A8D76
	cmp r0, 0x6
	beq _080A8D76
	cmp r0, 0x21
	bne _080A8D7C
_080A8D76:
	bl sub_808D3BC
	b _080A8E94
_080A8D7C:
	cmp r0, 0x2
	beq _080A8D88
	cmp r0, 0x7
	beq _080A8D88
	cmp r0, 0x22
	bne _080A8D8E
_080A8D88:
	bl sub_808D3F8
	b _080A8E94
_080A8D8E:
	cmp r0, 0x3
	beq _080A8D9A
	cmp r0, 0x8
	beq _080A8D9A
	cmp r0, 0x23
	bne _080A8DA0
_080A8D9A:
	bl GetPlayerPokemonStruct
	b _080A8E94
_080A8DA0:
	adds r0, r1, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A8DF8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r5, r0, 0
	subs r5, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _080A8E92
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8DD6
	add r4, sp, 0x4
	adds r0, r4, 0
	bl sub_808D6A4
	b _080A8DDE
_080A8DD6:
	add r4, sp, 0x4
	adds r0, r4, 0
	bl sub_808D654
_080A8DDE:
	cmp r5, r0
	bge _080A8E92
	ldr r2, _080A8DF4
	lsls r0, r5, 2
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	b _080A8E94
	.align 2, 0
_080A8DF4: .4byte gRecruitedPokemonRef
_080A8DF8:
	adds r0, r1, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A8E92
	movs r0, 0
	movs r1, 0x10
	bl GetScriptVarValue
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A8E92
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r5, r0, 0
	subs r5, 0xE
	add r4, sp, 0x4
	adds r0, r1, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl GetFriendAreaCapacity2
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r5, r0
	bge _080A8E92
	ldr r2, _080A8E6C
	ldr r0, [r4, 0x8]
	adds r0, r5
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8E70
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A8E92
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A8E92
	adds r0, r4, 0
	b _080A8E94
	.align 2, 0
_080A8E6C: .4byte gRecruitedPokemonRef
_080A8E70:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A8E92
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A8E92
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A8E8A
	movs r1, 0x1
_080A8E8A:
	cmp r1, 0
	bne _080A8E92
	adds r0, r4, 0
	b _080A8E94
_080A8E92:
	movs r0, 0
_080A8E94:
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8D54

	thumb_func_start sub_80A8E9C
sub_80A8E9C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8EBC
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	pop {r1}
	bx r1
	.align 2, 0
_080A8EBC: .4byte gGroundLives
	thumb_func_end sub_80A8E9C

	thumb_func_start sub_80A8EC0
sub_80A8EC0:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	mov r0, sp
	strh r1, [r0]
	mov r5, sp
	adds r5, 0x2
	adds r1, r5, 0
	bl sub_80A7DDC
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	cmp r0, 0
	beq _080A8EF0
	adds r1, r0, 0
	adds r1, 0x4C
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	b _080A8F44
_080A8EF0:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x20
	bne _080A8F00
	movs r0, 0
	ldrsh r1, [r5, r0]
	b _080A8F34
_080A8F00:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8F3C
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A8F2C
	adds r0, r1
	cmp r2, 0x34
	beq _080A8F20
	cmp r2, 0x64
	bne _080A8F30
_080A8F20:
	ldr r1, [r0, 0x4]
	adds r0, r4, 0
	bl strcpy
	b _080A8F44
	.align 2, 0
_080A8F2C: .4byte gGroundLivesTypeData_811E63C
_080A8F30:
	movs r2, 0x2
	ldrsh r1, [r0, r2]
_080A8F34:
	adds r0, r4, 0
	bl CopyMonsterNameToBuffer
	b _080A8F44
_080A8F3C:
	ldr r1, _080A8F4C
	adds r0, r4, 0
	bl strcpy
_080A8F44:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8F4C: .4byte gGroundLives_InvalidityText
	thumb_func_end sub_80A8EC0

	thumb_func_start sub_80A8F50
sub_80A8F50:
	push {r4,r5,lr}
	sub sp, 0x80
	adds r4, r0, 0
	adds r5, r2, 0
	lsls r1, 16
	asrs r1, 16
	mov r0, sp
	bl sub_80A8EC0
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl BoundedCopyStringtoBuffer
	add sp, 0x80
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A8F50

	thumb_func_start sub_80A8F74
sub_80A8F74:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8F98
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r3, 0
	bl sub_80A8EC0
	pop {r0}
	bx r0
	.align 2, 0
_080A8F98: .4byte gGroundLives
	thumb_func_end sub_80A8F74

	thumb_func_start sub_80A8F9C
sub_80A8F9C:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8FC4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8FC8
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080A8FD0
	.align 2, 0
_080A8FC4: .4byte gGroundLives
_080A8FC8:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080A8FD0:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A8F9C

	thumb_func_start sub_80A8FD8
sub_80A8FD8:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A9000
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A9004
	movs r0, 0
	str r0, [r3]
	b _080A901E
	.align 2, 0
_080A9000: .4byte gGroundLives
_080A9004:
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080A901E:
	str r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A8FD8

	thumb_func_start sub_80A9028
sub_80A9028:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080A904C
	lsls r2, r0, 5
	subs r2, r0
	lsls r2, 4
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80A9F20
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A904C: .4byte gGroundLives
	thumb_func_end sub_80A9028

	thumb_func_start sub_80A9050
sub_80A9050:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A9078
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	adds r3, r0, 0
	cmp r1, r0
	bne _080A907C
	strb r3, [r4]
	b _080A9086
	.align 2, 0
_080A9078: .4byte gGroundLives
_080A907C:
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	strb r0, [r4]
_080A9086:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9050

	thumb_func_start sub_80A9090
sub_80A9090:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	asrs r3, r1, 24
	ldr r2, _080A90C4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A90BA
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r2, r1
	strb r3, [r0]
_080A90BA:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A90C4: .4byte gGroundLives
	thumb_func_end sub_80A9090

	thumb_func_start sub_80A90C8
sub_80A90C8:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A90E4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A90E4: .4byte gGroundLives
	thumb_func_end sub_80A90C8

	thumb_func_start sub_80A90E8
sub_80A90E8:
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, r3
	beq _080A9196
	ldr r1, _080A916C
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	lsls r0, r3, 5
	subs r0, r3
	lsls r0, 4
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080A9196
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r1
	beq _080A9196
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [sp]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, r4, r3
	ldr r0, [r3]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp, 0x8]
	adds r2, r4, r2
	ldr r0, [r2]
	ldr r1, [r4, 0x18]
	adds r0, r1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0x24
	bgt _080A9170
	adds r1, r5, 0
	adds r1, 0xC
	adds r3, r4, 0
	adds r3, 0xC
	mov r0, sp
	bl SizedDeltaDirection8
	b _080A917E
	.align 2, 0
_080A916C: .4byte gGroundLives
_080A9170:
	adds r1, r5, 0
	adds r1, 0xC
	adds r3, r4, 0
	adds r3, 0xC
	mov r0, sp
	bl SizedDeltaDirection4
_080A917E:
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A9196
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, 0x1
	b _080A9198
_080A9196:
	movs r0, 0
_080A9198:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A90E8

	thumb_func_start sub_80A91A0
sub_80A91A0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	cmp r2, r4
	beq _080A928E
	ldr r1, _080A9260
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r7, r1, r0
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	adds r1, r0
	mov r8, r1
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	movs r2, 0x1
	negs r2, r2
	mov r10, r2
	cmp r0, r10
	beq _080A928E
	mov r3, r8
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r10
	beq _080A928E
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r1, [r7, 0x14]
	adds r0, r1
	str r0, [sp]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r7, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	add r3, r8
	ldr r0, [r3]
	mov r3, r8
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [sp, 0x8]
	add r2, r8
	ldr r0, [r2]
	ldr r1, [r3, 0x18]
	adds r0, r1
	add r4, sp, 0x8
	str r0, [r4, 0x4]
	adds r5, r7, 0
	adds r5, 0xC
	mov r6, r8
	adds r6, 0xC
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl SizedDeltaDirection8
	lsls r0, 24
	asrs r0, 24
	mov r9, r0
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl SizedDeltaDirection4
	lsls r0, 24
	asrs r1, r0, 24
	cmp r9, r10
	beq _080A928E
	cmp r1, r10
	beq _080A928E
	movs r2, 0x2
	ldrsh r0, [r7, r2]
	cmp r0, 0x24
	bgt _080A9264
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r7, r3
	mov r2, r9
	strb r2, [r0]
	b _080A926C
	.align 2, 0
_080A9260: .4byte gGroundLives
_080A9264:
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r7, r3
	strb r1, [r0]
_080A926C:
	mov r2, r8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0x25
	bgt _080A927A
	mov r0, r9
	b _080A927C
_080A927A:
	adds r0, r1, 0
_080A927C:
	movs r1, 0x5
	bl sub_8002984
	movs r1, 0xA1
	lsls r1, 1
	add r1, r8
	strb r0, [r1]
	movs r0, 0x1
	b _080A9290
_080A928E:
	movs r0, 0
_080A9290:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A91A0

	thumb_func_start GetLivesCollision_80A92A0
GetLivesCollision_80A92A0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r1
	adds r4, r2, 0
	lsls r0, 16
	asrs r6, r0, 16
	ldr r0, _080A931C
	ldr r0, [r0]
	mov r12, r0
	movs r2, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r5, 0x80
	lsls r5, 9
_080A92C2:
	cmp r2, r6
	beq _080A9320
	mov r1, r12
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r8
	beq _080A9320
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	beq _080A9320
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bge _080A9320
	movs r0, 0xA6
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	ble _080A9320
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bge _080A9320
	movs r0, 0xA8
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080A9320
	adds r0, r2, 0
	b _080A9338
	.align 2, 0
_080A931C: .4byte gGroundLives
_080A9320:
	adds r0, r5, 0
	movs r7, 0x80
	lsls r7, 9
	adds r5, r7
	asrs r2, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	add r12, r0
	cmp r2, 0x17
	ble _080A92C2
	movs r0, 0x1
	negs r0, r0
_080A9338:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetLivesCollision_80A92A0

	thumb_func_start sub_80A9344
sub_80A9344:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r1
	str r2, [sp]
	adds r5, r3, 0
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	ldr r0, _080A93C4
	ldr r0, [r0]
	mov r12, r0
	movs r4, 0
	movs r0, 0x1
	negs r0, r0
	mov r10, r0
	movs r7, 0x80
	lsls r7, 9
_080A936E:
	cmp r4, r8
	beq _080A93C8
	mov r1, r12
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	cmp r0, r10
	beq _080A93C8
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r6, r9
	ands r0, r6
	cmp r0, 0
	beq _080A93C8
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	mov r6, r12
	ldr r0, [r6, 0x14]
	adds r2, r1, r0
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r6, 0x18]
	adds r3, r1, r0
	ldr r0, [r5]
	cmp r2, r0
	bge _080A93C8
	ldr r1, [sp]
	ldr r0, [r1]
	cmp r2, r0
	ble _080A93C8
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _080A93C8
	ldr r0, [r1, 0x4]
	cmp r3, r0
	ble _080A93C8
	adds r0, r4, 0
	b _080A93E0
	.align 2, 0
_080A93C4: .4byte gGroundLives
_080A93C8:
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 9
	adds r7, r2
	asrs r4, r0, 16
	movs r6, 0xF8
	lsls r6, 1
	add r12, r6
	cmp r4, 0x17
	ble _080A936E
	movs r0, 0x1
	negs r0, r0
_080A93E0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9344

	thumb_func_start sub_80A93F0
sub_80A93F0:
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r2, _080A947C
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	mov r12, r0
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bge _080A941A
	ldr r1, _080A9480
	adds r0, r1
_080A941A:
	asrs r5, r0, 11
	str r5, [sp]
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bge _080A942E
	ldr r7, _080A9480
	adds r0, r7
_080A942E:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	subs r1, r0, 0x1
	cmp r1, 0
	bge _080A9444
	ldr r7, _080A9484
	adds r1, r0, r7
_080A9444:
	asrs r2, r1, 11
	movs r0, 0xA8
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	subs r1, r0, 0x1
	cmp r1, 0
	bge _080A9458
	ldr r7, _080A9484
	adds r1, r0, r7
_080A9458:
	asrs r3, r1, 11
	subs r0, r2, r5
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r3, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	adds r0, r6, 0
	mov r1, sp
	bl sub_80A5934
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A947C: .4byte gGroundLives
_080A9480: .4byte 0x000007ff
_080A9484: .4byte 0x000007fe
	thumb_func_end sub_80A93F0

	thumb_func_start sub_80A9488
sub_80A9488:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	ldr r0, [r7]
	cmp r0, 0
	bge _080A94A0
	ldr r1, _080A9528
	adds r0, r1
_080A94A0:
	asrs r0, 11
	mov r12, r0
	str r0, [sp]
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080A94B0
	ldr r3, _080A9528
	adds r0, r3
_080A94B0:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	mov r6, r8
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A94C2
	ldr r6, _080A952C
	adds r0, r3, r6
_080A94C2:
	asrs r1, r0, 11
	mov r0, r8
	ldr r3, [r0, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A94D2
	ldr r6, _080A952C
	adds r0, r3, r6
_080A94D2:
	asrs r2, r0, 11
	mov r3, r12
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _080A9504
	mov r0, sp
	adds r1, r4, 0
	bl CheckMapCollision_80A585C
	lsls r0, 24
	cmp r0, 0
	bne _080A9522
_080A9504:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A9530
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A58C8
	lsls r0, 24
	cmp r0, 0
	beq _080A9530
_080A9522:
	movs r0, 0x1
	b _080A95A0
	.align 2, 0
_080A9528: .4byte 0x000007ff
_080A952C: .4byte 0x000007fe
_080A9530:
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A9556
	movs r6, 0
	ldrsh r0, [r5, r6]
	adds r2, r7, 0
	mov r3, r8
	bl GetLivesCollision_80A92A0
	lsls r0, 16
	cmp r0, 0
	blt _080A9556
	movs r0, 0x4
	b _080A95A0
_080A9556:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A957A
	movs r0, 0x4
	adds r1, r7, 0
	mov r2, r8
	bl sub_80AC4C8
	lsls r0, 16
	cmp r0, 0
	blt _080A957A
	movs r0, 0x8
	b _080A95A0
_080A957A:
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A959E
	movs r0, 0x40
	adds r1, r7, 0
	mov r2, r8
	bl FindGroundEvent
	lsls r0, 16
	cmp r0, 0
	blt _080A959E
	movs r0, 0x10
	b _080A95A0
_080A959E:
	movs r0, 0
_080A95A0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9488

	thumb_func_start sub_80A95AC
sub_80A95AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	ldr r0, [r7]
	cmp r0, 0
	bge _080A95C6
	ldr r1, _080A96BC
	adds r0, r1
_080A95C6:
	asrs r0, 11
	mov r9, r0
	str r0, [sp]
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080A95D6
	ldr r2, _080A96BC
	adds r0, r2
_080A95D6:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	mov r6, r8
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A95E8
	ldr r6, _080A96C0
	adds r0, r3, r6
_080A95E8:
	asrs r1, r0, 11
	mov r0, r8
	ldr r3, [r0, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A95F8
	ldr r6, _080A96C0
	adds r0, r3, r6
_080A95F8:
	asrs r2, r0, 11
	mov r3, r9
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _080A962C
	mov r0, sp
	adds r1, r4, 0
	bl CheckMapCollision_80A585C
	lsls r0, 24
	cmp r0, 0
	beq _080A962C
	b _080A973C
_080A962C:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A964A
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A58C8
	lsls r0, 24
	cmp r0, 0
	bne _080A973C
_080A964A:
	movs r4, 0x8E
	lsls r4, 1
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A96C8
	movs r2, 0
	ldrsh r0, [r5, r2]
	movs r1, 0x44
	adds r2, r7, 0
	mov r3, r8
	bl GetLivesCollision_80A92A0
	lsls r0, 16
	asrs r2, r0, 16
	mov r9, r2
	cmp r2, 0
	blt _080A96C8
	ldr r1, _080A96C4
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r6, r4
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080A973C
	movs r0, 0x80
	lsls r0, 2
	ands r1, r0
	cmp r1, 0
	beq _080A96A8
	adds r4, 0x26
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r4, r6, r4
	strb r0, [r4]
_080A96A8:
	movs r3, 0
	ldrsh r0, [r5, r3]
	mov r1, r9
	bl GroundLives_ExecutePlayerScriptActionLives
_080A96B2:
	lsls r0, 24
	cmp r0, 0
	bne _080A9738
	b _080A973C
	.align 2, 0
_080A96BC: .4byte 0x000007ff
_080A96C0: .4byte 0x000007fe
_080A96C4: .4byte gGroundLives
_080A96C8:
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A9708
	movs r0, 0x44
	adds r1, r7, 0
	mov r2, r8
	bl sub_80AC4C8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080A9708
	add r1, sp, 0x10
	adds r0, r4, 0
	bl sub_80AC3E0
	ldr r0, [sp, 0x10]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080A973C
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	bl sub_80A8A5C
	b _080A96B2
_080A9708:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A9740
	movs r0, 0x40
	adds r1, r7, 0
	mov r2, r8
	bl FindGroundEvent
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080A9740
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl sub_80A8ACC
	lsls r0, 24
	cmp r0, 0
	beq _080A973C
_080A9738:
	movs r0, 0x2
	b _080A9742
_080A973C:
	movs r0, 0x1
	b _080A9742
_080A9740:
	movs r0, 0
_080A9742:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A95AC

	thumb_func_start sub_80A9750
sub_80A9750:
	push {r4,lr}
	mov r12, r0
	lsls r1, 16
	lsrs r1, 16
	adds r4, r1, 0
	movs r3, 0xFF
	ands r3, r1
	movs r2, 0xF0
	lsls r2, 4
	ands r2, r1
	cmp r3, 0
	beq _080A9770
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	strh r3, [r0]
_080A9770:
	cmp r2, 0
	beq _080A977C
	movs r0, 0xAF
	lsls r0, 1
	add r0, r12
	strh r2, [r0]
_080A977C:
	movs r2, 0xB0
	lsls r2, 1
	add r2, r12
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _080A97A8
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	beq _080A97B6
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r2, _080A97A4
	cmp r0, 0
	bgt _080A97A0
	b _080A9E98
_080A97A0:
	b _080A97C0
	.align 2, 0
_080A97A4: .4byte 0x00000807
_080A97A8:
	cmp r0, 0x2
	beq _080A97AE
	b _080A9E8C
_080A97AE:
	movs r0, 0x80
	lsls r0, 5
	cmp r4, r0
	bne _080A97C6
_080A97B6:
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
_080A97C0:
	movs r2, 0x80
	lsls r2, 4
	b _080A9E98
_080A97C6:
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bgt _080A97C0
	mov r1, r12
	ldrh r0, [r1, 0x8]
	subs r0, 0xC
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _080A97F0
	cmp r1, r0
	bls _080A97E4
	b _080A9E7E
_080A97E4:
	lsls r0, r1, 2
	ldr r1, _080A97F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A97F0: .4byte 0x00000197
_080A97F4: .4byte _080A97F8
	.align 2, 0
_080A97F8:
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E68
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
_080A9E58:
	ldr r2, _080A9E5C
	b _080A9E98
	.align 2, 0
_080A9E5C: .4byte 0x00000807
_080A9E60:
	ldr r2, _080A9E64
	b _080A9E98
	.align 2, 0
_080A9E64: .4byte 0x00000307
_080A9E68:
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r2, _080A9E84
	cmp r1, r2
	beq _080A9E98
	ldr r0, _080A9E88
	cmp r1, r0
	beq _080A9E98
_080A9E7E:
	movs r2, 0xC0
	lsls r2, 2
	b _080A9E98
	.align 2, 0
_080A9E84: .4byte 0x00000807
_080A9E88: .4byte 0x00000307
_080A9E8C:
	ldr r1, _080A9EC4
	ldrh r0, [r2]
	lsls r0, 1
	adds r0, r1
	movs r4, 0
	ldrsh r2, [r0, r4]
_080A9E98:
	movs r0, 0xE0
	lsls r0, 3
	ands r0, r2
	cmp r0, 0
	bne _080A9EEE
	movs r0, 0xAF
	lsls r0, 1
	add r0, r12
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _080A9EEE
	cmp r1, r0
	bgt _080A9EC8
	movs r3, 0x80
	lsls r3, 1
	cmp r1, r3
	beq _080A9EDA
	movs r0, 0x80
	lsls r0, 2
	b _080A9ED4
	.align 2, 0
_080A9EC4: .4byte gUnknown_8117F64
_080A9EC8:
	movs r3, 0x80
	lsls r3, 3
	cmp r1, r3
	beq _080A9EDE
	movs r0, 0x80
	lsls r0, 4
_080A9ED4:
	cmp r1, r0
	beq _080A9EEC
	b _080A9EEE
_080A9EDA:
	orrs r2, r0
	b _080A9EEE
_080A9EDE:
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1, 0
	orrs r2, r0
	lsls r0, r2, 16
	asrs r2, r0, 16
	b _080A9EEE
_080A9EEC:
	orrs r2, r3
_080A9EEE:
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldrh r3, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	beq _080A9F02
	strh r2, [r1]
	b _080A9F0C
_080A9F02:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r3
	cmp r0, 0
	beq _080A9F16
_080A9F0C:
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x1
	strb r0, [r1]
_080A9F16:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9750

	thumb_func_start sub_80A9F20
sub_80A9F20:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r2, [r1]
	ldr r4, [r5, 0x14]
	subs r0, r2, r4
	str r0, [sp]
	ldr r3, [r1, 0x4]
	ldr r1, [r5, 0x18]
	subs r0, r3, r1
	str r0, [sp, 0x4]
	adds r2, r4
	str r2, [sp, 0x8]
	adds r3, r1
	add r2, sp, 0x8
	str r3, [r2, 0x4]
	ldr r1, [r5, 0x28]
	ldr r0, [sp]
	cmp r0, r1
	blt _080A9F5E
	ldr r1, [r5, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	bge _080A9F5E
	ldr r1, [r5, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	blt _080A9F5E
	ldr r0, [r5, 0x34]
	cmp r3, r0
	blt _080A9F62
_080A9F5E:
	movs r0, 0x1
	b _080A9F8C
_080A9F62:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80A9488
	cmp r0, 0
	bne _080A9F8C
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
_080A9F8C:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9F20

	thumb_func_start sub_80A9F94
sub_80A9F94:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0xA8
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	movs r6, 0
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r2, r1, 0
	cmp r0, r3
	bge _080A9FE4
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080A9FF4
_080A9FE4:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080A9FF6
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080A9FF4:
	movs r6, 0x1
_080A9FF6:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AA008
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r2, 0x4]
	b _080AA018
_080AA008:
	ldr r1, [r4, 0x34]
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA01A
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r2, 0x4]
_080AA018:
	movs r6, 0x1
_080AA01A:
	adds r0, r4, 0
	mov r1, sp
	bl sub_80A9488
	adds r5, r0, 0
	cmp r5, 0
	beq _080AA034
	adds r0, r4, 0
	movs r1, 0
	bl sub_80AAF68
	adds r0, r5, 0
	b _080AA06A
_080AA034:
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r6, 0
	bne _080AA060
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80AAF68
	movs r0, 0
	b _080AA06A
_080AA060:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80AAF68
	movs r0, 0x1
_080AA06A:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9F94

	thumb_func_start sub_80AA074
sub_80AA074:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0xA8
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r5, r1, 0
	cmp r0, r3
	bge _080AA0C2
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080AA0D2
_080AA0C2:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AA0D2
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080AA0D2:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AA0E4
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r5, 0x4]
	b _080AA0F4
_080AA0E4:
	ldr r1, [r4, 0x34]
	ldr r0, [r5, 0x4]
	cmp r0, r1
	blt _080AA0F4
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r5, 0x4]
_080AA0F4:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_80A95AC
	adds r6, r0, 0
	cmp r6, 0
	bne _080AA170
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080AA170
	movs r0, 0x20
	mov r1, sp
	adds r2, r5, 0
	bl FindGroundEvent
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	blt _080AA166
	movs r2, 0x9F
	lsls r2, 1
	adds r7, r4, r2
	movs r3, 0
	ldrsh r0, [r7, r3]
	cmp r0, r5
	beq _080AA170
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	bl sub_80A8ACC
	lsls r0, 24
	cmp r0, 0
	beq _080AA170
	strh r5, [r7]
	movs r6, 0x2
	b _080AA170
_080AA166:
	movs r2, 0x9F
	lsls r2, 1
	adds r1, r4, r2
	ldr r0, _080AA17C
	strh r0, [r1]
_080AA170:
	adds r0, r6, 0
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AA17C: .4byte 0x0000ffff
	thumb_func_end sub_80AA074

	thumb_func_start sub_80AA180
sub_80AA180:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _080AA220
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	bl sub_80A9344
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080AA220
	mov r1, sp
	bl sub_80A8FD8
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, [r0]
	ldr r0, [r4, 0x14]
	adds r1, r0
	ldr r0, [sp]
	subs r0, r1
	str r0, [sp, 0x8]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r4, 0x18]
	adds r0, r1
	ldr r1, [sp, 0x4]
	subs r1, r0
	add r0, sp, 0x8
	str r1, [r0, 0x4]
	bl VecDirection8Radial
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AA2B2
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r4, r0
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r3, _080AA21C
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AA20A
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AA20A:
	movs r1, 0
	ldrsb r1, [r2, r1]
	adds r0, r4, 0
	bl sub_80AA3F8
	lsls r0, 24
	cmp r0, 0
	bne _080AA2AE
	b _080AA2B2
	.align 2, 0
_080AA21C: .4byte 0x0000015d
_080AA220:
	movs r0, 0x8
	ands r0, r5
	cmp r0, 0
	beq _080AA2B2
	movs r0, 0x80
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_80AC554
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080AA2B2
	mov r1, sp
	bl sub_80AC448
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r4, 0x14]
	adds r1, r0
	ldr r0, [sp]
	subs r0, r1
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r4, r2
	ldr r2, [r1]
	ldr r1, [r4, 0x18]
	adds r2, r1
	ldr r1, [sp, 0x4]
	subs r1, r2
	str r1, [r0, 0x4]
	bl VecDirection8Radial
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AA2B2
	movs r3, 0xA1
	lsls r3, 1
	adds r2, r4, r3
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	adds r3, 0x1B
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AA29E
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AA29E:
	movs r1, 0
	ldrsb r1, [r2, r1]
	adds r0, r4, 0
	bl sub_80AA3F8
	lsls r0, 24
	cmp r0, 0
	beq _080AA2B2
_080AA2AE:
	movs r0, 0x3
	b _080AA2B4
_080AA2B2:
	movs r0, 0
_080AA2B4:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA180

	thumb_func_start sub_80AA2BC
sub_80AA2BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r7, r0, 0
	mov r8, r1
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp]
	cmp r0, 0
	bge _080AA2E6
	ldr r1, _080AA3C4
	adds r0, r1
_080AA2E6:
	asrs r0, 11
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _080AA2F4
	ldr r2, _080AA3C4
	adds r0, r2
_080AA2F4:
	asrs r0, 11
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r4, [sp, 0x10]
	subs r0, r4, 0x1
	mov r10, r1
	cmp r0, 0
	bge _080AA308
	ldr r1, _080AA3C8
	adds r0, r4, r1
_080AA308:
	asrs r2, r0, 11
	add r0, sp, 0x10
	ldr r4, [r0, 0x4]
	subs r1, r4, 0x1
	mov r9, r0
	cmp r1, 0
	bge _080AA31A
	ldr r0, _080AA3C8
	adds r1, r4, r0
_080AA31A:
	asrs r3, r1, 11
	ldr r0, [sp, 0x8]
	subs r0, r2, r0
	adds r0, 0x1
	str r0, [sp, 0x18]
	mov r1, r10
	ldr r0, [r1, 0x4]
	subs r0, r3, r0
	adds r0, 0x1
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0x4
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	beq _080AA394
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r1, 0x80
	mov r2, sp
	mov r3, r9
	bl GetLivesCollision_80A92A0
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	blt _080AA394
	ldr r1, _080AA3CC
	lsls r0, r5, 5
	subs r0, r5
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080AA384
	movs r4, 0xA1
	lsls r4, 1
	adds r0, r7, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r4, r6, r4
	strb r0, [r4]
_080AA384:
	movs r1, 0
	ldrsh r0, [r7, r1]
	adds r1, r5, 0
	bl GroundLives_ExecutePlayerScriptActionLives
	lsls r0, 24
	cmp r0, 0
	bne _080AA3BE
_080AA394:
	movs r0, 0x8
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	beq _080AA3D0
	movs r0, 0x80
	mov r1, sp
	mov r2, r9
	bl sub_80AC4C8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080AA3D0
	movs r2, 0
	ldrsh r0, [r7, r2]
	bl sub_80A8A5C
	lsls r0, 24
	cmp r0, 0
	beq _080AA3D0
_080AA3BE:
	movs r0, 0x3
	b _080AA3E6
	.align 2, 0
_080AA3C4: .4byte 0x000007ff
_080AA3C8: .4byte 0x000007fe
_080AA3CC: .4byte gGroundLives
_080AA3D0:
	movs r0, 0x10
	mov r1, r10
	add r2, sp, 0x18
	bl sub_80A595C
	lsls r0, 24
	cmp r0, 0
	bne _080AA3E4
	movs r0, 0
	b _080AA3E6
_080AA3E4:
	movs r0, 0x6
_080AA3E6:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA2BC

	thumb_func_start sub_80AA3F8
sub_80AA3F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x28]
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl SetVecFromDirectionSpeed
	ldr r4, [sp]
	ldr r5, [sp, 0x4]
	movs r0, 0xA2
	lsls r0, 1
	adds r0, r6
	mov r9, r0
	ldr r0, [r0]
	adds r0, r4
	str r0, [sp, 0x8]
	movs r1, 0xA4
	lsls r1, 1
	adds r1, r6
	mov r10, r1
	ldr r0, [r1]
	adds r0, r5
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, r4
	str r0, [sp, 0x10]
	adds r1, 0x4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, r5
	add r3, sp, 0x10
	str r0, [r3, 0x4]
	adds r0, r6, 0
	movs r1, 0xC
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA462
_080AA45E:
	movs r0, 0x1
	b _080AA650
_080AA462:
	ldr r0, [r6, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r2, 0x80
	lsls r2, 2
	mov r8, r2
	add r0, r8
	muls r0, r4
	cmp r0, 0
	bge _080AA47A
	adds r0, 0xFF
_080AA47A:
	asrs r0, 8
	str r0, [sp, 0x2C]
	ldr r0, [r6, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r8
	muls r0, r5
	cmp r0, 0
	bge _080AA490
	adds r0, 0xFF
_080AA490:
	asrs r0, 8
	str r0, [sp, 0x30]
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r6, 0x14]
	adds r0, r1
	ldr r2, [sp, 0x2C]
	adds r0, r2
	ldr r2, _080AA4F4
	adds r0, r2
	str r0, [sp, 0x18]
	mov r1, r10
	ldr r0, [r1]
	ldr r1, [r6, 0x18]
	adds r0, r1
	ldr r1, [sp, 0x30]
	adds r0, r1
	adds r0, r2
	add r2, sp, 0x18
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0x18]
	adds r0, r1
	str r0, [sp, 0x20]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x20
	str r0, [r3, 0x4]
	ldr r0, _080AA4F8
	mov r9, r0
	ldr r0, [sp, 0x28]
	lsls r1, r0, 2
	add r9, r1
	mov r0, r9
	ldr r0, [r0]
	str r0, [sp, 0x34]
	ldr r0, _080AA4FC
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, 0x38]
	ldr r0, _080AA500
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x3C]
	mov r10, r8
	mov r9, r2
	mov r8, r3
	b _080AA568
	.align 2, 0
_080AA4F4: .4byte 0xfffffd00
_080AA4F8: .4byte gUnknown_8117FF0
_080AA4FC: .4byte gUnknown_8118010
_080AA500: .4byte gUnknown_8118030
_080AA504:
	ldr r1, [r6, 0x28]
	ldr r0, [sp, 0x18]
	cmp r0, r1
	bge _080AA50E
	b _080AA64E
_080AA50E:
	ldr r1, [r6, 0x30]
	ldr r0, [sp, 0x20]
	cmp r0, r1
	blt _080AA518
	b _080AA64E
_080AA518:
	ldr r1, [r6, 0x2C]
	mov r2, r9
	ldr r0, [r2, 0x4]
	cmp r0, r1
	bge _080AA524
	b _080AA64E
_080AA524:
	ldr r1, [r6, 0x34]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA530
	b _080AA64E
_080AA530:
	adds r0, r6, 0
	movs r1, 0xC
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	beq _080AA45E
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	cmp r7, 0x6
	beq _080AA572
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
_080AA568:
	ldr r1, [sp, 0x34]
	cmp r10, r1
	blt _080AA504
	cmp r7, 0x6
	bne _080AA64E
_080AA572:
	ldr r2, [sp, 0x38]
	cmp r10, r2
	bge _080AA5DC
_080AA578:
	ldr r1, [sp, 0x18]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AA64E
	ldr r1, [sp, 0x20]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AA64E
	mov r0, r9
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AA64E
	mov r2, r8
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AA64E
	adds r0, r6, 0
	movs r1, 0x4
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA5B0
	b _080AA45E
_080AA5B0:
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	cmp r7, 0x6
	bne _080AA5E0
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
	ldr r1, [sp, 0x38]
	cmp r10, r1
	blt _080AA578
_080AA5DC:
	cmp r7, 0x6
	beq _080AA64E
_080AA5E0:
	movs r2, 0
	mov r10, r2
	ldr r0, [sp, 0x3C]
	cmp r10, r0
	bge _080AA64E
_080AA5EA:
	ldr r1, [sp, 0x18]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AA64E
	ldr r1, [sp, 0x20]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AA64E
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AA64E
	mov r0, r8
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AA64E
	adds r0, r6, 0
	movs r1, 0x4
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA622
	b _080AA45E
_080AA622:
	cmp r7, 0x6
	beq _080AA64E
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
	ldr r1, [sp, 0x3C]
	cmp r10, r1
	blt _080AA5EA
_080AA64E:
	movs r0, 0
_080AA650:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA3F8

	thumb_func_start sub_80AA660
sub_80AA660:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 1
	bl sub_80AC4C8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080AA686
	movs r2, 0
	ldrsh r0, [r4, r2]
	bl sub_80A8A5C
	lsls r0, 24
	cmp r0, 0
	beq _080AA686
	movs r0, 0x4
	b _080AA688
_080AA686:
	movs r0, 0
_080AA688:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA660

	thumb_func_start sub_80AA690
sub_80AA690:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r7, r0, 0
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl SetVecFromDirectionSpeed
	ldr r5, [sp]
	ldr r6, [sp, 0x4]
	ldr r0, [r7, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x80
	lsls r1, 2
	mov r8, r1
	add r0, r8
	muls r0, r5
	cmp r0, 0
	bge _080AA6CA
	adds r0, 0xFF
_080AA6CA:
	asrs r3, r0, 8
	ldr r0, [r7, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r8
	muls r0, r6
	cmp r0, 0
	bge _080AA6DE
	adds r0, 0xFF
_080AA6DE:
	asrs r4, r0, 8
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r7, 0x14]
	adds r0, r1
	adds r0, r3
	ldr r2, _080AA76C
	adds r0, r2
	str r0, [sp, 0x8]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r7, 0x18]
	adds r0, r1
	adds r0, r4
	adds r0, r2
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x10]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x10
	str r0, [r3, 0x4]
	ldr r1, _080AA770
	mov r4, r9
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	mov r10, r0
	mov r9, r8
	mov r8, r2
	adds r4, r3, 0
	cmp r9, r10
	bge _080AA79C
_080AA730:
	ldr r1, [r7, 0x28]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AA79C
	ldr r1, [r7, 0x30]
	ldr r0, [sp, 0x10]
	cmp r0, r1
	bge _080AA79C
	ldr r1, [r7, 0x2C]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA79C
	ldr r1, [r7, 0x34]
	ldr r0, [r4, 0x4]
	cmp r0, r1
	bge _080AA79C
	adds r0, r7, 0
	mov r1, r8
	adds r2, r4, 0
	bl sub_80AA660
	cmp r0, 0x4
	beq _080AA774
	cmp r0, 0x4
	bhi _080AA778
	cmp r0, 0
	bne _080AA778
	b _080AA79C
	.align 2, 0
_080AA76C: .4byte 0xfffffd00
_080AA770: .4byte gUnknown_8117FF0
_080AA774:
	movs r0, 0x1
	b _080AA79E
_080AA778:
	ldr r0, [sp, 0x8]
	adds r0, r5
	str r0, [sp, 0x8]
	mov r1, r8
	ldr r0, [r1, 0x4]
	adds r0, r6
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x10]
	adds r0, r5
	str r0, [sp, 0x10]
	ldr r0, [r4, 0x4]
	adds r0, r6
	str r0, [r4, 0x4]
	movs r2, 0x80
	lsls r2, 1
	add r9, r2
	cmp r9, r10
	blt _080AA730
_080AA79C:
	movs r0, 0
_080AA79E:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA690

	thumb_func_start sub_80AA7B0
sub_80AA7B0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r7, r0, 0
	adds r6, r1, 0
	mov r12, r2
	ldr r2, [sp, 0x38]
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp]
	cmp r0, 0
	bge _080AA7DA
	ldr r1, _080AA884
	adds r0, r1
_080AA7DA:
	asrs r0, 11
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _080AA7E8
	ldr r2, _080AA884
	adds r0, r2
_080AA7E8:
	asrs r0, 11
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r4, [sp, 0x10]
	subs r0, r4, 0x1
	mov r8, r1
	cmp r0, 0
	bge _080AA7FC
	ldr r5, _080AA888
	adds r0, r4, r5
_080AA7FC:
	asrs r2, r0, 11
	add r4, sp, 0x10
	ldr r1, [r4, 0x4]
	subs r0, r1, 0x1
	cmp r0, 0
	bge _080AA80C
	ldr r5, _080AA888
	adds r0, r1, r5
_080AA80C:
	asrs r3, r0, 11
	ldr r0, [sp, 0x8]
	subs r0, r2, r0
	adds r0, 0x1
	str r0, [sp, 0x18]
	mov r1, r8
	ldr r0, [r1, 0x4]
	subs r0, r3, r0
	adds r0, 0x1
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0x4
	mov r2, r12
	ands r0, r2
	adds r5, r1, 0
	cmp r0, 0
	beq _080AA890
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r1, 0x80
	mov r2, sp
	adds r3, r4, 0
	bl GetLivesCollision_80A92A0
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080AA890
	adds r0, r4, 0
	bl sub_80A8BBC
	lsls r0, 16
	ldr r2, _080AA88C
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080AA890
	adds r0, r4, 0
	bl sub_80A8E9C
	cmp r0, 0
	beq _080AA890
	strh r4, [r6]
	movs r5, 0xA1
	lsls r5, 1
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl sub_80A9090
	movs r0, 0x5
	b _080AA8AE
	.align 2, 0
_080AA884: .4byte 0x000007ff
_080AA888: .4byte 0x000007fe
_080AA88C: .4byte 0xfff20000
_080AA890:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r6]
	movs r0, 0x10
	mov r1, r8
	adds r2, r5, 0
	bl sub_80A595C
	lsls r0, 24
	cmp r0, 0
	bne _080AA8AC
	movs r0, 0
	b _080AA8AE
_080AA8AC:
	movs r0, 0x6
_080AA8AE:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA7B0

	thumb_func_start sub_80AA8BC
sub_80AA8BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r6, r0, 0
	str r1, [sp, 0x1C]
	lsls r2, 24
	asrs r2, 24
	mov r8, r2
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x4
	mov r1, r8
	bl SetVecFromDirectionSpeed
	ldr r4, [sp, 0x4]
	ldr r5, [sp, 0x8]
	ldr r0, [r6, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x80
	lsls r1, 2
	mov r9, r1
	add r0, r9
	muls r0, r4
	cmp r0, 0
	bge _080AA8FA
	adds r0, 0xFF
_080AA8FA:
	asrs r0, 8
	str r0, [sp, 0x20]
	ldr r0, [r6, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r9
	muls r0, r5
	cmp r0, 0
	bge _080AA910
	adds r0, 0xFF
_080AA910:
	asrs r0, 8
	str r0, [sp, 0x24]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	ldr r0, [r0]
	ldr r1, [r6, 0x14]
	adds r0, r1
	ldr r7, [sp, 0x20]
	adds r0, r7
	ldr r2, _080AA9F0
	adds r0, r2
	str r0, [sp, 0xC]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, [r6, 0x18]
	adds r0, r1
	ldr r7, [sp, 0x24]
	adds r0, r7
	adds r0, r2
	add r2, sp, 0xC
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0x14]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x14
	str r0, [r3, 0x4]
	ldr r0, _080AA9F4
	mov r7, r8
	lsls r1, r7, 2
	adds r0, r1, r0
	ldr r0, [r0]
	mov r10, r0
	ldr r0, _080AA9F8
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, 0x28]
	ldr r0, _080AA9FC
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x2C]
	movs r1, 0
	movs r7, 0x1
	negs r7, r7
	adds r0, r7, 0
	ldr r7, [sp, 0x1C]
	strh r0, [r7]
	mov r8, r2
	adds r7, r3, 0
	cmp r9, r10
	bge _080AA9E8
_080AA982:
	ldr r1, [r6, 0x28]
	ldr r0, [sp, 0xC]
	cmp r0, r1
	bge _080AA98C
	b _080AAAD4
_080AA98C:
	ldr r1, [r6, 0x30]
	ldr r0, [sp, 0x14]
	cmp r0, r1
	blt _080AA996
	b _080AAAD4
_080AA996:
	ldr r1, [r6, 0x2C]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	bge _080AA9A2
	b _080AAAD4
_080AA9A2:
	ldr r1, [r6, 0x34]
	ldr r0, [r7, 0x4]
	cmp r0, r1
	blt _080AA9AC
	b _080AAAD4
_080AA9AC:
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0xC
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	cmp r1, 0x6
	beq _080AAA5A
	movs r0, 0x80
	lsls r0, 1
	add r9, r0
	cmp r9, r10
	blt _080AA982
_080AA9E8:
	cmp r1, 0x6
	bne _080AAAD4
	b _080AAA5A
	.align 2, 0
_080AA9F0: .4byte 0xfffffd00
_080AA9F4: .4byte gUnknown_8117FF0
_080AA9F8: .4byte gUnknown_8118010
_080AA9FC: .4byte gUnknown_8118030
_080AAA00:
	ldr r1, [sp, 0xC]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [sp, 0x14]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AAAD4
	mov r0, r8
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [r7, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AAAD4
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0x4
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	cmp r1, 0x6
	bne _080AAA6A
	movs r0, 0x80
	lsls r0, 1
	add r9, r0
_080AAA5A:
	ldr r2, [sp, 0x28]
	cmp r9, r2
	blt _080AAA00
	cmp r1, 0x6
	bne _080AAA6A
	b _080AAAD4
_080AAA66:
	movs r0, 0x1
	b _080AAAD6
_080AAA6A:
	movs r0, 0
	mov r9, r0
	ldr r1, [sp, 0x2C]
	cmp r9, r1
	bge _080AAAD4
_080AAA74:
	ldr r1, [sp, 0xC]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [sp, 0x14]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AAAD4
	mov r2, r8
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [r7, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AAAD4
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0x4
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	cmp r1, 0x6
	beq _080AAAD4
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r1, r8
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	movs r2, 0x80
	lsls r2, 1
	add r9, r2
	ldr r0, [sp, 0x2C]
	cmp r9, r0
	blt _080AAA74
_080AAAD4:
	movs r0, 0
_080AAAD6:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA8BC

	thumb_func_start sub_80AAAE8
sub_80AAAE8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x80
	adds r5, r0, 0
	adds r3, r1, 0
	lsls r2, 24
	asrs r4, r2, 24
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x78]
	movs r2, 0xAF
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r5, r6
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, [sp, 0x78]
	cmp r4, r0
	beq _080AAB26
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r5, r1
	strb r4, [r0]
_080AAB26:
	subs r0, r3, 0x1
	cmp r0, 0x13
	bls _080AAB2E
	b _080AAEB8
_080AAB2E:
	lsls r0, 2
	ldr r1, _080AAB38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AAB38: .4byte _080AAB3C
	.align 2, 0
_080AAB3C:
	.4byte _080AAB8C
	.4byte _080AAD60
	.4byte _080AAC9C
	.4byte _080AAC9C
	.4byte _080AAC9C
	.4byte _080AAB9E
	.4byte _080AAB9E
	.4byte _080AAB9E
	.4byte _080AAD7C
	.4byte _080AADF4
	.4byte _080AAE06
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAE32
	.4byte _080AAE9C
_080AAB8C:
	movs r4, 0xB2
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0
	str r0, [r1]
	movs r6, 0xC0
	lsls r6, 2
	str r6, [sp, 0x78]
	b _080AAD6E
_080AAB9E:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080AAC88
	movs r6, 0
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	str r0, [r1]
	cmp r3, 0x7
	beq _080AABD2
	cmp r3, 0x7
	bhi _080AABC0
	cmp r3, 0x6
	beq _080AABC6
	b _080AABEA
_080AABC0:
	cmp r3, 0x8
	beq _080AABDE
	b _080AABEA
_080AABC6:
	movs r1, 0x90
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x1
	str r2, [sp, 0x7C]
	b _080AABFC
_080AABD2:
	movs r3, 0x80
	lsls r3, 4
	str r3, [sp, 0x78]
	movs r0, 0x2
	str r0, [sp, 0x7C]
	b _080AABFC
_080AABDE:
	movs r1, 0xA0
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x4
	str r2, [sp, 0x7C]
	b _080AABFC
_080AABEA:
	movs r3, 0xB2
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0
	str r0, [r1]
	ldr r0, _080AAC20
	str r0, [sp, 0x78]
	movs r1, 0
	str r1, [sp, 0x7C]
_080AABFC:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x28
	adds r1, r4, 0
	bl SetVecFromDirectionSpeed
	ldr r0, [sp, 0x28]
	ldr r1, [sp, 0x2C]
	str r0, [sp, 0x38]
	str r1, [sp, 0x3C]
	movs r2, 0
	mov r10, r2
	add r3, sp, 0x40
	mov r9, r3
	add r4, sp, 0x30
	mov r8, r4
	b _080AAC42
	.align 2, 0
_080AAC20: .4byte 0x00000807
_080AAC24:
	cmp r6, 0x1
	bne _080AAC3E
	ldr r0, [sp, 0x38]
	str r0, [sp, 0x30]
	mov r6, r8
	str r7, [r6, 0x4]
	adds r0, r5, 0
	mov r1, r8
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	beq _080AAC78
_080AAC3E:
	movs r0, 0x1
	add r10, r0
_080AAC42:
	ldr r1, [sp, 0x7C]
	cmp r10, r1
	bge _080AAC74
	add r4, sp, 0x38
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	beq _080AAC78
	cmp r6, 0x1
	bne _080AAC3E
	movs r7, 0
	str r7, [sp, 0x40]
	ldr r0, [r4, 0x4]
	mov r2, r9
	str r0, [r2, 0x4]
	adds r0, r5, 0
	mov r1, r9
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	bne _080AAC24
_080AAC74:
	cmp r6, 0x2
	bne _080AAC7E
_080AAC78:
	movs r3, 0x1
	negs r3, r3
	b _080AAD6C
_080AAC7E:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80AAF68
	b _080AAEC0
_080AAC88:
	movs r4, 0xB2
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0
	str r0, [r1]
	ldr r6, _080AAC98
	str r6, [sp, 0x78]
	b _080AAD6E
	.align 2, 0
_080AAC98: .4byte 0x00000807
_080AAC9C:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080AAD60
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	str r0, [r1]
	cmp r3, 0x4
	beq _080AACCE
	cmp r3, 0x4
	bhi _080AACBC
	cmp r3, 0x3
	beq _080AACC2
	b _080AACE6
_080AACBC:
	cmp r3, 0x5
	beq _080AACDA
	b _080AACE6
_080AACC2:
	movs r1, 0x90
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x1
	mov r9, r2
	b _080AACF6
_080AACCE:
	movs r3, 0x80
	lsls r3, 4
	str r3, [sp, 0x78]
	movs r6, 0x2
	mov r9, r6
	b _080AACF6
_080AACDA:
	movs r0, 0xA0
	lsls r0, 4
	str r0, [sp, 0x78]
	movs r1, 0x4
	mov r9, r1
	b _080AACF6
_080AACE6:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	str r0, [r1]
	ldr r3, _080AAD5C
	str r3, [sp, 0x78]
	mov r9, r0
_080AACF6:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x48
	adds r1, r4, 0
	bl SetVecFromDirectionSpeed
	ldr r0, [sp, 0x48]
	ldr r1, [sp, 0x4C]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	movs r6, 0
	cmp r6, r9
	bge _080AAD52
	add r4, sp, 0x50
	mov r8, r4
	add r7, sp, 0x58
_080AAD16:
	adds r0, r5, 0
	mov r1, r8
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	movs r4, 0
	str r4, [sp, 0x58]
	mov r1, r8
	ldr r0, [r1, 0x4]
	str r0, [r7, 0x4]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	ldr r0, [sp, 0x50]
	str r0, [sp, 0x60]
	add r1, sp, 0x60
	str r4, [r1, 0x4]
	adds r0, r5, 0
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	mov r9, r4
_080AAD4C:
	adds r6, 0x1
	cmp r6, r9
	blt _080AAD16
_080AAD52:
	adds r0, r5, 0
	mov r1, r9
	bl sub_80AAF68
	b _080AAEC0
	.align 2, 0
_080AAD5C: .4byte 0x00000807
_080AAD60:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	str r0, [r1]
	ldr r3, _080AAD78
_080AAD6C:
	str r3, [sp, 0x78]
_080AAD6E:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80AAF68
	b _080AAEC0
	.align 2, 0
_080AAD78: .4byte 0x00000807
_080AAD7C:
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	beq _080AAD9C
	ldr r0, _080AAD98
	ldr r0, [r0]
	adds r0, 0x28
	strb r4, [r0]
	b _080AADA6
	.align 2, 0
_080AAD98: .4byte gGroundLivesMeta
_080AAD9C:
	ldr r0, _080AADF0
	ldr r0, [r0]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
_080AADA6:
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r5, r1
	movs r1, 0
	str r1, [r0]
	movs r2, 0x80
	lsls r2, 4
	str r2, [sp, 0x78]
	movs r3, 0xA1
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x4
	strb r0, [r1]
	movs r6, 0x1
	negs r6, r6
	cmp r4, r6
	bne _080AADCA
	b _080AAEC0
_080AADCA:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x68
	adds r1, r4, 0
	bl SetVecFromDirectionSpeed
	ldr r0, [sp, 0x68]
	ldr r1, [sp, 0x6C]
	str r0, [sp, 0x70]
	str r1, [sp, 0x74]
	add r1, sp, 0x70
	adds r0, r5, 0
	bl sub_80AA074
	cmp r0, 0x2
	bne _080AAEC0
	str r6, [sp, 0x78]
	b _080AAEC0
	.align 2, 0
_080AADF0: .4byte gGroundLivesMeta
_080AADF4:
	movs r4, 0xA1
	lsls r4, 1
	adds r0, r5, r4
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r0, r5, 0
	bl sub_80AA3F8
	b _080AAEC0
_080AAE06:
	movs r6, 0xA1
	lsls r6, 1
	adds r0, r5, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r0, r5, 0
	bl sub_80AA690
	lsls r0, 24
	cmp r0, 0
	bne _080AAEC0
	movs r0, 0
	mov r1, sp
	movs r2, 0x9
	bl GetFunctionScript
	adds r0, r5, 0
	movs r1, 0
	mov r2, sp
	bl _ExecutePlayerScript
	b _080AAEC0
_080AAE32:
	add r6, sp, 0xC
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r5, r1
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80AA8BC
	lsls r0, 24
	cmp r0, 0
	beq _080AAE84
	add r4, sp, 0x10
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x6
	bl GetFunctionScript
	movs r2, 0
	ldrsh r0, [r6, r2]
	adds r1, r5, 0
	adds r1, 0x40
	adds r2, r4, 0
	bl GroundLives_ExecuteScript
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	bl _ExecutePlayerScript
	movs r3, 0
	ldrsh r0, [r6, r3]
	bl sub_80A8E9C
	adds r2, r0, 0
	movs r0, 0x7
	movs r1, 0
	bl sub_809B1C0
	b _080AAE8E
_080AAE84:
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
_080AAE8E:
	movs r4, 0x90
	lsls r4, 1
	adds r0, r5, r4
	movs r1, 0x5
	bl sub_809CD8C
	b _080AAEC0
_080AAE9C:
	add r4, sp, 0x1C
	ldr r2, _080AAEB4
	movs r0, 0
	adds r1, r4, 0
	bl GetFunctionScript
	adds r0, r5, 0
	movs r1, 0
	adds r2, r4, 0
	bl _ExecutePlayerScript
	b _080AAEC0
	.align 2, 0
_080AAEB4: .4byte 0x00000195
_080AAEB8:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80AAF68
_080AAEC0:
	movs r0, 0x1
	negs r0, r0
	ldr r6, [sp, 0x78]
	cmp r6, r0
	beq _080AAF04
	movs r0, 0xB4
	lsls r0, 1
	adds r2, r5, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r6, r0
	beq _080AAF04
	movs r3, 0xAE
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0
	strb r0, [r1]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r5, r4
	strh r6, [r2]
	movs r1, 0xA1
	lsls r1, 1
	adds r3, r5, r1
	ldrb r1, [r3]
	subs r4, 0x13
	adds r2, r5, r4
	strb r1, [r2]
	movs r2, 0
	ldrsb r2, [r3, r2]
	ldr r1, [sp, 0x78]
	bl sub_80A6EFC
	b _080AAF54
_080AAF04:
	movs r6, 0xAE
	lsls r6, 1
	adds r2, r5, r6
	ldrb r0, [r2]
	cmp r0, 0
	bne _080AAF2A
	ldr r0, _080AAF64
	adds r1, r5, r0
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r5, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AAF54
_080AAF2A:
	movs r0, 0
	strb r0, [r2]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r5, r4
	movs r6, 0xB4
	lsls r6, 1
	adds r1, r5, r6
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0xA1
	lsls r3, 1
	adds r4, r5, r3
	ldrb r2, [r4]
	subs r6, 0xB
	adds r3, r5, r6
	strb r2, [r3]
	movs r2, 0
	ldrsb r2, [r4, r2]
	bl sub_80A6EFC
_080AAF54:
	add sp, 0x80
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAF64: .4byte 0x0000015d
	thumb_func_end sub_80AAAE8

	thumb_func_start sub_80AAF68
sub_80AAF68:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 7
	ands r0, r1
	cmp r0, 0
	beq _080AB002
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r1, 0x1
	bl sub_80A93F0
	lsls r0, 24
	cmp r0, 0
	beq _080AAFD0
	movs r1, 0xE4
	lsls r1, 1
	adds r0, r4, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bne _080AAFA6
	movs r0, 0xB5
	lsls r0, 1
	adds r1, r4, r0
	adds r0, 0x4C
	b _080AAFB4
_080AAFA6:
	movs r0, 0xDB
	lsls r0, 1
	cmp r1, r0
	beq _080AAFC2
	subs r0, 0x4C
	adds r1, r4, r0
	adds r0, 0x56
_080AAFB4:
	strh r0, [r1]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
_080AAFC2:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 17
	bl sub_80A8750
	b _080AB002
_080AAFD0:
	movs r2, 0xE4
	lsls r2, 1
	adds r0, r4, r2
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0xDB
	lsls r0, 1
	cmp r1, r0
	bne _080AAFF6
	subs r0, 0x4C
	adds r1, r4, r0
	adds r0, 0x56
	strh r0, [r1]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
_080AAFF6:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 17
	bl sub_80A86C8
_080AB002:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AAF68

	thumb_func_start CallbackLivesGetIndex
CallbackLivesGetIndex:
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end CallbackLivesGetIndex

	thumb_func_start CallbackLivesGetSize
CallbackLivesGetSize:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end CallbackLivesGetSize

	thumb_func_start CallbackLivesSetHitboxPos
CallbackLivesSetHitboxPos:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AB05C
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AB0C2
_080AB05C:
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AB0BE
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AB0BE:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AB0C2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesSetHitboxPos

	thumb_func_start CallbackLivesSetPositionBounds
CallbackLivesSetPositionBounds:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesSetPositionBounds

	thumb_func_start CallbackLivesGetHitboxCenter
CallbackLivesGetHitboxCenter:
	adds r3, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end CallbackLivesGetHitboxCenter

	thumb_func_start CallbackLivesMoveReal
CallbackLivesMoveReal:
	push {lr}
	bl sub_80A9F20
	pop {r1}
	bx r1
	thumb_func_end CallbackLivesMoveReal

	thumb_func_start CallbackLivesGetPosHeightAndUnk
CallbackLivesGetPosHeightAndUnk:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0xAA
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesGetPosHeightAndUnk

	thumb_func_start CallbackLivesSetPosHeight
CallbackLivesSetPosHeight:
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end CallbackLivesSetPosHeight

	thumb_func_start CallbackLivesGetDirection
CallbackLivesGetDirection:
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end CallbackLivesGetDirection

	thumb_func_start CallbackLivesSetDirection
CallbackLivesSetDirection:
	push {lr}
	adds r3, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AB17C
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r3, r0
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, _080AB180
	adds r1, r3, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AB17C
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AB17C:
	pop {r0}
	bx r0
	.align 2, 0
_080AB180: .4byte 0x0000015d
	thumb_func_end CallbackLivesSetDirection

	thumb_func_start CallbackLivesSetEventIndex
CallbackLivesSetEventIndex:
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80A9750
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesSetEventIndex

	thumb_func_start CallbackLivesSetUnk_80AB194
CallbackLivesSetUnk_80AB194:
	push {lr}
	mov r12, r0
	lsls r1, 16
	asrs r1, 16
	adds r3, r1, 0
	cmp r1, 0
	bne _080AB1A8
	movs r0, 0xE0
	lsls r0, 1
	adds r3, r0, 0
_080AB1A8:
	movs r0, 0xB5
	lsls r0, 1
	add r0, r12
	strh r3, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesSetUnk_80AB194

	thumb_func_start nullsub_211
nullsub_211:
	bx lr
	thumb_func_end nullsub_211

	thumb_func_start CallbackLivesSpriteRelatedCheck_80AB1C0
CallbackLivesSpriteRelatedCheck_80AB1C0:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xAE
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB1DE
	adds r2, 0x14
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AB1E0
_080AB1DE:
	movs r0, 0x1
_080AB1E0:
	pop {r1}
	bx r1
	thumb_func_end CallbackLivesSpriteRelatedCheck_80AB1C0

	thumb_func_start CallbackLivesSpriteRelated_80AB1E4
CallbackLivesSpriteRelated_80AB1E4:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xB5
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AB206
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080AB208
_080AB206:
	movs r0, 0x1
_080AB208:
	pop {r1}
	bx r1
	thumb_func_end CallbackLivesSpriteRelated_80AB1E4

	thumb_func_start CallbackLivesGetFlags
CallbackLivesGetFlags:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end CallbackLivesGetFlags

	thumb_func_start CallbackLivesSetFlags
CallbackLivesSetFlags:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A86C8
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesSetFlags

	thumb_func_start CallbackLivesClearFlags
CallbackLivesClearFlags:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A8750
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesClearFlags

	thumb_func_start CallbackLivesSpriteRelated_80AB238
CallbackLivesSpriteRelated_80AB238:
	push {lr}
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r2
	bl sub_80A6EC8
	pop {r0}
	bx r0
	thumb_func_end CallbackLivesSpriteRelated_80AB238

	thumb_func_start CallbackLivesMoveRelative
CallbackLivesMoveRelative:
	push {lr}
	bl sub_80A9F94
	pop {r1}
	bx r1
	thumb_func_end CallbackLivesMoveRelative

	thumb_func_start GroundLives_Action
GroundLives_Action:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x3C
	ldr r0, _080AB29C
	ldr r5, [r0]
	movs r0, 0
	mov r9, r0
_080AB266:
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	movs r3, 0x1
	negs r3, r3
	mov r8, r3
	adds r0, r3, 0
	cmp r1, r0
	bne _080AB278
	b _080AB47C
_080AB278:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AB2A0
	adds r0, r4, 0
	bl HandleAction
	lsls r0, 16
	asrs r3, r0, 16
	cmp r3, 0
	beq _080AB2A4
	cmp r3, 0x4
	beq _080AB292
	b _080AB44C
_080AB292:
	mov r0, r9
	bl GroundLives_Delete
	b _080AB47C
	.align 2, 0
_080AB29C: .4byte gGroundLives
_080AB2A0: .4byte gUnknown_8118280
_080AB2A4:
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	bne _080AB2B8
	b _080AB42E
_080AB2B8:
	str r3, [sp, 0xC]
	add r0, sp, 0x8
	mov r1, r8
	strb r1, [r0]
	str r3, [sp, 0x10]
	movs r3, 0x90
	lsls r3, 1
	adds r0, r5, r3
	add r1, sp, 0xC
	add r3, sp, 0x10
	add r4, sp, 0x14
	str r4, [sp]
	ldr r2, [r2]
	str r2, [sp, 0x4]
	add r2, sp, 0x8
	bl sub_809CDC8
	subs r0, 0x1
	mov r8, r4
	cmp r0, 0x7
	bls _080AB2E4
	b _080AB44C
_080AB2E4:
	lsls r0, 2
	ldr r1, _080AB2F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AB2F0: .4byte _080AB2F4
	.align 2, 0
_080AB2F4:
	.4byte _080AB314
	.4byte _080AB314
	.4byte _080AB326
	.4byte _080AB44C
	.4byte _080AB314
	.4byte _080AB44C
	.4byte _080AB44C
	.4byte _080AB314
_080AB314:
	ldr r1, [sp, 0xC]
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldr r3, [sp, 0x10]
	adds r0, r5, 0
	bl sub_80AAAE8
	b _080AB44C
_080AB326:
	add r4, sp, 0x1C
	adds r0, r4, 0
	bl sub_809D248
	ldr r1, [sp, 0x1C]
	ldr r0, [sp, 0x14]
	adds r6, r1, r0
	ldr r1, [r4, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r7, r1, r0
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r5, r3
	ldr r1, [r0]
	ldr r0, [r5, 0x14]
	adds r0, r1, r0
	cmp r0, 0
	bge _080AB34E
	adds r0, 0xFF
_080AB34E:
	asrs r0, 8
	subs r0, r6, r0
	str r0, [sp, 0x24]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r0, r1, r0
	cmp r0, 0
	bge _080AB366
	adds r0, 0xFF
_080AB366:
	asrs r0, 8
	subs r0, r7, r0
	add r1, sp, 0x24
	str r0, [r1, 0x4]
	adds r0, r6, 0
	subs r0, 0x10
	lsls r0, 8
	str r0, [sp, 0x2C]
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 8
	str r0, [sp, 0x34]
	subs r0, r7, 0x4
	lsls r0, 8
	add r2, sp, 0x2C
	str r0, [r2, 0x4]
	adds r0, r7, 0
	adds r0, 0x1C
	lsls r0, 8
	add r3, sp, 0x34
	str r0, [r3, 0x4]
	ldr r0, [sp, 0xC]
	adds r4, r1, 0
	cmp r0, 0xC
	bne _080AB3C4
	adds r0, r5, 0
	movs r1, 0xC
	bl sub_80AA180
	cmp r0, 0
	bne _080AB44C
	ldr r0, [sp, 0x24]
	adds r0, 0x10
	cmp r0, 0x20
	bhi _080AB44C
	movs r0, 0x1C
	negs r0, r0
	ldr r1, [r4, 0x4]
	cmp r1, r0
	blt _080AB44C
	cmp r1, 0x4
	bgt _080AB44C
	movs r2, 0x1
	negs r2, r2
	adds r0, r5, 0
	movs r1, 0x13
	b _080AB426
_080AB3C4:
	ldr r0, [sp, 0x24]
	adds r0, 0x10
	cmp r0, 0x20
	bhi _080AB3DA
	movs r0, 0x1C
	negs r0, r0
	ldr r1, [r4, 0x4]
	cmp r1, r0
	blt _080AB3DA
	cmp r1, 0x4
	ble _080AB44C
_080AB3DA:
	adds r0, r4, 0
	bl VecDirection8Radial
	add r1, sp, 0x8
	strb r0, [r1]
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	cmp r0, r1
	beq _080AB44C
	ldr r0, [sp, 0xC]
	cmp r0, 0x11
	beq _080AB410
	cmp r0, 0x11
	bhi _080AB3FE
	cmp r0, 0x10
	beq _080AB404
	b _080AB44C
_080AB3FE:
	cmp r0, 0x12
	beq _080AB41C
	b _080AB44C
_080AB404:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x6
	b _080AB426
_080AB410:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x7
	b _080AB426
_080AB41C:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x8
_080AB426:
	movs r3, 0
	bl sub_80AAAE8
	b _080AB44C
_080AB42E:
	movs r0, 0x80
	lsls r0, 5
	ands r1, r0
	cmp r1, 0
	beq _080AB440
	adds r0, r5, 0
	bl sub_80AB5D4
	b _080AB44C
_080AB440:
	ldr r3, _080AB4C4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	bl ExecutePredefinedScript
_080AB44C:
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080AB47C
	movs r0, 0
	strb r0, [r1]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r5, r3
	adds r2, 0xC
	adds r1, r5, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	subs r2, 0x26
	adds r4, r5, r2
	ldrb r2, [r4]
	ldr r3, _080AB4C8
	strb r2, [r3, r5]
	movs r2, 0
	ldrsb r2, [r4, r2]
	bl sub_80A6EFC
_080AB47C:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	mov r1, r9
	cmp r1, 0x17
	bgt _080AB494
	b _080AB266
_080AB494:
	ldr r0, _080AB4CC
	ldr r6, [r0]
	ldr r0, _080AB4D0
	ldr r5, [r0]
	movs r0, 0
	str r0, [r6]
	str r0, [r6, 0x4]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	subs r0, 0x1
	cmp r1, r0
	beq _080AB4BE
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r3, 0x80
	lsls r3, 6
	ands r3, r1
	cmp r3, 0
	beq _080AB4D4
_080AB4BE:
	bl sub_80AB5A4
	b _080AB594
	.align 2, 0
_080AB4C4: .4byte gUnknown_811828C
_080AB4C8: .4byte 0x0000015d
_080AB4CC: .4byte gGroundLivesMeta
_080AB4D0: .4byte gGroundLives
_080AB4D4:
	movs r0, 0x80
	lsls r0, 5
	ands r1, r0
	cmp r1, 0
	beq _080AB590
	ldr r7, [r6, 0x24]
	cmp r7, 0
	bge _080AB51E
	adds r2, r6, 0
	adds r2, 0x2C
	str r3, [r6, 0x24]
	str r3, [r6, 0x2C]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2, 0x4]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2, 0x8]
	adds r0, r6, 0
	movs r2, 0
	movs r1, 0x2
_080AB50E:
	str r2, [r0, 0x8]
	str r2, [r0]
	str r2, [r0, 0x4]
	subs r1, 0x1
	adds r0, 0xC
	cmp r1, 0
	bge _080AB50E
	b _080AB594
_080AB51E:
	adds r2, r7, 0x1
	adds r0, r2, 0
	cmp r2, 0
	bge _080AB52A
	adds r0, r7, 0
	adds r0, 0x40
_080AB52A:
	asrs r1, r0, 6
	lsls r0, r1, 6
	subs r1, r2, r0
	str r1, [r6, 0x24]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r6
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, [r5, 0x14]
	adds r2, r0
	mov r3, r8
	str r2, [r3, 0x4]
	adds r1, 0x4
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r1, r0
	str r1, [r3, 0x8]
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r6, r0
	ldr r3, [r0, 0x4]
	ldr r0, [r0, 0x8]
	subs r0, r1, r0
	subs r2, r3
	cmp r2, 0
	bge _080AB572
	negs r2, r2
_080AB572:
	adds r4, r2, 0
	cmp r0, 0
	bge _080AB57A
	negs r0, r0
_080AB57A:
	cmp r0, r4
	bge _080AB580
	adds r0, r2, 0
_080AB580:
	mov r2, r8
	str r0, [r2]
	cmp r0, 0
	bgt _080AB58C
	str r7, [r6, 0x24]
	b _080AB594
_080AB58C:
	str r0, [r6]
	b _080AB594
_080AB590:
	bl sub_80AB5A4
_080AB594:
	add sp, 0x3C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundLives_Action

	thumb_func_start sub_80AB5A4
sub_80AB5A4:
	push {lr}
	ldr r3, _080AB5D0
	ldr r0, [r3]
	movs r2, 0x1
	negs r2, r2
	str r2, [r0, 0x24]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
	ldr r3, [r3]
	movs r1, 0
	movs r0, 0x2
_080AB5BC:
	str r2, [r3, 0x8]
	str r1, [r3]
	str r1, [r3, 0x4]
	subs r0, 0x1
	adds r3, 0xC
	cmp r0, 0
	bge _080AB5BC
	pop {r0}
	bx r0
	.align 2, 0
_080AB5D0: .4byte gGroundLivesMeta
	thumb_func_end sub_80AB5A4

	thumb_func_start sub_80AB5D4
sub_80AB5D4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	ldr r4, _080AB6BC
	movs r2, 0x9E
	lsls r2, 1
	add r2, r9
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r3, [r4]
	adds r0, r3
	mov r8, r0
	adds r0, r1, 0
	adds r5, r4, 0
	cmp r0, 0
	bne _080AB604
	b _080AB9E6
_080AB604:
	movs r1, 0xAF
	lsls r1, 1
	add r1, r9
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r1, 0xB0
	lsls r1, 1
	add r1, r9
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x8E
	lsls r0, 1
	add r0, r9
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 6
	ands r2, r0
	cmp r2, 0
	beq _080AB6D4
	movs r2, 0xA1
	lsls r2, 1
	add r2, r9
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0x4
	bne _080AB64C
	movs r0, 0xB4
	lsls r0, 1
	add r0, r9
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	beq _080AB670
_080AB64C:
	movs r1, 0xB2
	lsls r1, 1
	add r1, r9
	movs r0, 0
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r9
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r0, 0x4
	strb r0, [r2]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080AB670:
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x28
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AB69C
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl SetVecFromDirectionSpeed
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	add r1, sp, 0x8
	mov r0, r9
	bl sub_80A9F94
_080AB69C:
	mov r4, r8
	ldr r0, [r4, 0x8]
	cmp r0, 0
	blt _080AB6A6
	b _080AB9E6
_080AB6A6:
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	bge _080AB6B0
	b _080AB9E6
_080AB6B0:
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	b _080AB9E6
	.align 2, 0
_080AB6BC: .4byte gGroundLivesMeta
_080AB6C0:
	ldr r5, [sp, 0x28]
	ldr r0, [r5, 0x4]
	adds r0, r7, r0
	str r0, [r5, 0x4]
	b _080AB7E2
_080AB6CA:
	ldr r1, [sp, 0x28]
	ldr r0, [r1, 0x4]
	subs r0, r7
	str r0, [r1, 0x4]
	b _080AB7E2
_080AB6D4:
	movs r0, 0xA2
	lsls r0, 1
	add r0, r9
	ldr r1, [r0]
	mov r5, r9
	ldr r0, [r5, 0x14]
	adds r0, r1, r0
	str r0, [sp, 0x20]
	movs r0, 0xA4
	lsls r0, 1
	add r0, r9
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r0, r1, r0
	str r0, [sp, 0x24]
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	mov r1, r8
	ldr r0, [r1, 0x8]
	cmp r0, 0
	bge _080AB710
	ldr r0, [r3, 0x24]
	cmp r0, 0
	bge _080AB70A
	b _080AB9E6
_080AB70A:
	str r0, [r1, 0x8]
	str r2, [r1]
	str r2, [r1, 0x4]
_080AB710:
	mov r2, r8
	ldr r7, [r2]
	movs r3, 0x1
	mov r10, r3
	mov r5, sp
	adds r5, 0x10
	str r5, [sp, 0x28]
_080AB71E:
	mov r0, r8
	ldr r1, [r0, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	ldr r2, _080AB754
	ldr r1, [r2]
	adds r1, r0
	mov r12, r1
	ldr r6, [r1, 0x4]
	ldr r5, [sp, 0x10]
	subs r4, r6, r5
	adds r2, r4, 0
	ldr r1, [r1, 0x8]
	ldr r0, [sp, 0x14]
	subs r3, r1, r0
	cmp r4, 0
	ble _080AB75E
	cmp r2, r7
	ble _080AB758
	adds r0, r7, r5
	str r0, [sp, 0x10]
	movs r4, 0
	mov r10, r4
	b _080AB75A
	.align 2, 0
_080AB754: .4byte gGroundLivesMeta
_080AB758:
	str r6, [sp, 0x10]
_080AB75A:
	adds r1, r2, 0
	b _080AB778
_080AB75E:
	cmp r4, 0
	bge _080AB776
	cmn r2, r7
	bge _080AB770
	subs r0, r5, r7
	str r0, [sp, 0x10]
	movs r5, 0
	mov r10, r5
	b _080AB772
_080AB770:
	str r6, [sp, 0x10]
_080AB772:
	negs r1, r2
	b _080AB778
_080AB776:
	movs r1, 0
_080AB778:
	cmp r3, 0
	ble _080AB78E
	cmp r3, r7
	bgt _080AB6C0
	mov r4, r12
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x14]
	cmp r3, r1
	ble _080AB7A2
	adds r1, r3, 0
	b _080AB7A2
_080AB78E:
	cmp r3, 0
	bge _080AB7A2
	cmn r3, r7
	blt _080AB6CA
	mov r5, r12
	ldr r0, [r5, 0x8]
	str r0, [sp, 0x14]
	cmn r3, r1
	bge _080AB7A2
	negs r1, r3
_080AB7A2:
	mov r0, r10
	cmp r0, 0
	beq _080AB7E2
	subs r7, r1
	cmp r7, 0
	ble _080AB7E2
	ldr r1, _080AB7D4
	ldr r0, [r1]
	mov r3, r8
	ldr r2, [r3, 0x8]
	ldr r0, [r0, 0x24]
	cmp r2, r0
	beq _080AB7D8
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB7C8
	adds r0, r2, 0
	adds r0, 0x40
_080AB7C8:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	mov r4, r8
	str r0, [r4, 0x8]
	b _080AB7DC
	.align 2, 0
_080AB7D4: .4byte gGroundLivesMeta
_080AB7D8:
	movs r5, 0
	mov r10, r5
_080AB7DC:
	mov r0, r10
	cmp r0, 0
	bne _080AB71E
_080AB7E2:
	mov r1, r8
	ldr r0, [r1, 0x8]
	bl sub_80ABA00
	adds r6, r0, 0
	ldr r0, _080AB860
	ldr r7, [r0]
	movs r2, 0x9E
	lsls r2, 1
	add r2, r9
	mov r10, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	subs r1, r2, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r7, 0x4
	adds r1, r0
	ldr r0, _080AB864
	lsls r2, 2
	adds r2, r0
	ldr r1, [r1]
	ldr r0, [r2]
	adds r1, r0
	mov r12, r1
	mov r4, r8
	ldr r1, [r4, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r7, r0
	ldr r3, [r0, 0x4]
	ldr r2, [sp, 0x10]
	ldr r1, [r0, 0x8]
	ldr r5, [sp, 0x28]
	ldr r0, [r5, 0x4]
	subs r1, r0
	subs r3, r2
	cmp r3, 0
	bge _080AB838
	negs r3, r3
_080AB838:
	adds r4, r3, 0
	cmp r1, 0
	bge _080AB840
	negs r1, r1
_080AB840:
	cmp r1, r4
	bge _080AB846
	adds r1, r3, 0
_080AB846:
	adds r6, r1
	mov r0, r8
	str r6, [r0, 0x4]
	cmp r6, r12
	bgt _080AB86C
	ldr r0, [r0]
	cmp r0, 0
	ble _080AB8B2
	ldr r1, _080AB868
	adds r0, r1
	mov r2, r8
	b _080AB8B0
	.align 2, 0
_080AB860: .4byte gGroundLivesMeta
_080AB864: .4byte gUnknown_8118050
_080AB868: .4byte 0xffffff00
_080AB86C:
	mov r3, r10
	movs r4, 0
	ldrsh r1, [r3, r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	cmp r6, r0
	bgt _080AB88E
	mov r5, r8
	ldr r0, [r5]
	cmp r0, 0xFF
	bgt _080AB8B2
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	str r0, [r5]
	b _080AB8B2
_080AB88E:
	subs r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r7, r0
	ldr r0, [r0]
	cmp r0, 0xFF
	bgt _080AB8A2
	movs r0, 0x80
	lsls r0, 1
_080AB8A2:
	mov r2, r8
	ldr r1, [r2]
	cmp r1, r0
	bge _080AB8B2
	movs r3, 0x80
	lsls r3, 1
	adds r0, r1, r3
_080AB8B0:
	str r0, [r2]
_080AB8B2:
	ldr r0, _080AB96C
	ldr r3, [r0]
	mov r4, r8
	ldr r0, [r4, 0x8]
	subs r0, 0x40
	ldr r2, [r3, 0x24]
	subs r1, r2, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB8C8
	adds r0, 0x3F
_080AB8C8:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	cmp r0, 0x3B
	ble _080AB8FC
	adds r1, r2, 0x5
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB8DE
	adds r0, r2, 0
	adds r0, 0x44
_080AB8DE:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	mov r5, r8
	str r0, [r5, 0x8]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x30
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
_080AB8FC:
	mov r0, r9
	ldr r1, [sp, 0x28]
	bl sub_80A9F20
	adds r6, r0, 0
	cmp r6, 0
	bne _080AB9E6
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x20]
	subs r0, r1
	str r0, [sp, 0x18]
	ldr r2, [sp, 0x28]
	ldr r1, [r2, 0x4]
	ldr r3, [sp, 0x24]
	subs r1, r3
	add r0, sp, 0x18
	str r1, [r0, 0x4]
	movs r5, 0xA1
	lsls r5, 1
	add r5, r9
	movs r4, 0
	ldrsb r4, [r5, r4]
	bl VecDirection8Radial
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl sub_8002B04
	strb r0, [r5]
	mov r4, r8
	ldr r0, [r4]
	cmp r0, 0
	ble _080AB970
	movs r1, 0xB2
	lsls r1, 1
	add r1, r9
	movs r0, 0x4
	str r0, [r1]
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 2
	movs r2, 0x80
	lsls r2, 4
	cmp r1, r0
	ble _080AB95E
	movs r2, 0xA0
	lsls r2, 4
_080AB95E:
	adds r4, r2, 0
	mov r0, r9
	movs r1, 0x1
	bl sub_80AAF68
	b _080AB982
	.align 2, 0
_080AB96C: .4byte gGroundLivesMeta
_080AB970:
	ldr r4, _080AB9F8
	movs r0, 0xB2
	lsls r0, 1
	add r0, r9
	str r6, [r0]
	mov r0, r9
	movs r1, 0
	bl sub_80AAF68
_080AB982:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r9
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB9B6
	movs r0, 0xB4
	lsls r0, 1
	add r0, r9
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r4, r0
	bne _080AB9B6
	ldr r1, _080AB9FC
	add r1, r9
	movs r0, 0xA1
	lsls r0, 1
	add r0, r9
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AB9E6
_080AB9B6:
	movs r1, 0xAE
	lsls r1, 1
	add r1, r9
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	add r0, r9
	movs r1, 0xB4
	lsls r1, 1
	add r1, r9
	strh r4, [r1]
	movs r3, 0xA1
	lsls r3, 1
	add r3, r9
	ldrb r1, [r3]
	ldr r2, _080AB9FC
	add r2, r9
	strb r1, [r2]
	movs r2, 0
	ldrsb r2, [r3, r2]
	adds r1, r4, 0
	bl sub_80A6EFC
_080AB9E6:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB9F8: .4byte 0x00000807
_080AB9FC: .4byte 0x0000015d
	thumb_func_end sub_80AB5D4

	thumb_func_start sub_80ABA00
sub_80ABA00:
	push {r4,r5,lr}
	adds r1, r0, 0
	movs r4, 0
	ldr r0, _080ABA34
	ldr r2, [r0]
	ldr r3, [r2, 0x24]
	adds r5, r0, 0
	cmp r3, r1
	ble _080ABA38
	adds r1, 0x1
	cmp r1, r3
	bge _080ABA72
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r2, r0, r2
	subs r1, r3, r1
_080ABA24:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080ABA24
	b _080ABA72
	.align 2, 0
_080ABA34: .4byte gGroundLivesMeta
_080ABA38:
	cmp r3, r1
	bge _080ABA72
	adds r1, 0x1
	cmp r1, 0x3F
	bgt _080ABA58
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r2, r0, r2
_080ABA4C:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	adds r1, 0x1
	cmp r1, 0x3F
	ble _080ABA4C
_080ABA58:
	ldr r1, [r5]
	ldr r0, [r1, 0x24]
	cmp r0, 0
	ble _080ABA72
	adds r2, r1, 0
	adds r2, 0x2C
	adds r1, r0, 0
_080ABA66:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080ABA66
_080ABA72:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABA00

	thumb_func_start sub_80ABA7C
sub_80ABA7C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080ABB50
	ldr r5, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r4, r5, r1
	movs r2, 0x1
	negs r2, r2
	mov r9, r2
_080ABA9A:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, r9
	beq _080ABB2C
	ldr r0, [r4]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x10]
	ldr r0, [r4, 0x14]
	adds r7, r1, r0
	ldr r0, [r4, 0x20]
	cmp r0, 0
	ble _080ABADA
	subs r0, 0x1
	str r0, [r4, 0x20]
	cmp r0, 0
	bgt _080ABADA
	ldrh r0, [r4, 0x1C]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080ABADA
	ldrh r1, [r4, 0x1C]
	adds r0, r5, 0
	bl sub_80A9750
_080ABADA:
	movs r2, 0xB8
	lsls r2, 1
	adds r6, r5, r2
	adds r0, r6, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080ABAFE
	movs r0, 0
	strb r0, [r4, 0x18]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r2, 0x19
	ldrsb r2, [r4, r2]
	adds r0, r6, 0
	bl sub_80A6EFC
_080ABAFE:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080ABB1E
	adds r1, r0, 0
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r5, r2
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldr r3, [r4, 0x28]
	adds r0, r6, 0
	bl sub_80A74F0
	movs r0, 0
	strh r0, [r4, 0x26]
_080ABB1E:
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	adds r0, r6, 0
	mov r2, sp
	adds r3, r7, 0
	bl sub_80A7524
_080ABB2C:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	adds r5, r1
	cmp r0, 0x17
	ble _080ABA9A
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB50: .4byte gGroundLives
	thumb_func_end sub_80ABA7C

        .align 2,0
