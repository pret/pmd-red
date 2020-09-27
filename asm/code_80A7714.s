	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80A7764
sub_80A7764:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	bl sub_80A7784
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080A777A
	ldr r0, _080A7780
	strh r4, [r0]
_080A777A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7780: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7764

	thumb_func_start sub_80A7784
sub_80A7784:
	push {lr}
	ldr r2, _080A779C
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080A7796
	strh r1, [r2]
_080A7796:
	pop {r0}
	bx r0
	.align 2, 0
_080A779C: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7784

	thumb_func_start sub_80A77A0
sub_80A77A0:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _080A77BC
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, r1
	beq _080A77CA
	cmp r1, 0
	bge _080A77C0
	bl sub_80A7784
	b _080A77C6
	.align 2, 0
_080A77BC: .4byte gUnknown_2039DE0
_080A77C0:
	adds r0, r2, 0
	bl sub_80A7764
_080A77C6:
	movs r0, 0x1
	b _080A77CC
_080A77CA:
	movs r0, 0
_080A77CC:
	pop {r1}
	bx r1
	thumb_func_end sub_80A77A0

	thumb_func_start sub_80A77D0
sub_80A77D0:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A77E8
	ldr r0, _080A77E4
	b _080A77F0
	.align 2, 0
_080A77E4: .4byte gUnknown_8117EFC
_080A77E8:
	ldr r0, _080A77F4
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
_080A77F0:
	pop {r1}
	bx r1
	.align 2, 0
_080A77F4: .4byte gUnknown_811E258
	thumb_func_end sub_80A77D0

	thumb_func_start sub_80A77F8
sub_80A77F8:
	push {r4,r5,lr}
	ldr r4, _080A7860
	movs r0, 0xCE
	lsls r0, 2
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r4, _080A7864
	movs r0, 0xBA
	lsls r0, 6
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080A7868
	adds r5, r0, 0
	movs r4, 0xF8
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080A7826:
	ldrh r0, [r1, 0x2]
	orrs r0, r5
	strh r0, [r1, 0x2]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0x17
	ble _080A7826
	ldr r4, _080A7860
	ldr r1, [r4]
	movs r0, 0xCB
	lsls r0, 2
	adds r1, r0
	movs r0, 0
	movs r2, 0x19
	bl sub_809D710
	ldr r0, [r4]
	movs r1, 0xCC
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
	bl sub_80A786C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A7860: .4byte gUnknown_3001B80
_080A7864: .4byte gUnknown_3001B84
_080A7868: .4byte 0x0000ffff
	thumb_func_end sub_80A77F8

	thumb_func_start sub_80A786C
sub_80A786C:
	push {r4-r6,lr}
	ldr r0, _080A78E8
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080A787C:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080A788A
	adds r0, r1, 0
	bl GroundLives_Delete
_080A788A:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xF8
	lsls r2, 1
	adds r4, r2
	cmp r1, 0x17
	ble _080A787C
	ldr r3, _080A78EC
	ldr r0, [r3]
	movs r2, 0x1
	negs r2, r2
	str r2, [r0, 0x24]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
	movs r5, 0
	movs r4, 0
	movs r1, 0x2
_080A78B4:
	ldr r0, [r3]
	adds r0, r4
	str r2, [r0, 0x8]
	str r5, [r0]
	str r5, [r0, 0x4]
	adds r4, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _080A78B4
	ldr r4, _080A78EC
	movs r2, 0
	movs r3, 0x2C
	movs r1, 0x3F
_080A78CE:
	ldr r0, [r4]
	adds r0, r3
	str r2, [r0]
	str r2, [r0, 0x4]
	str r2, [r0, 0x8]
	adds r3, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _080A78CE
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A78E8: .4byte gUnknown_3001B84
_080A78EC: .4byte gUnknown_3001B80
	thumb_func_end sub_80A786C

	thumb_func_start sub_80A78F0
sub_80A78F0:
	push {r4,r5,lr}
	bl sub_80A786C
	ldr r4, _080A7914
	ldr r0, [r4]
	bl MemoryFree
	movs r5, 0
	str r5, [r4]
	ldr r4, _080A7918
	ldr r0, [r4]
	bl MemoryFree
	str r5, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A7914: .4byte gUnknown_3001B84
_080A7918: .4byte gUnknown_3001B80
	thumb_func_end sub_80A78F0

	thumb_func_start GroundLives_Select
GroundLives_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080A7980
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080A7984
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x4]
	ldr r0, [r0]
	cmp r0, 0
	ble _080A7976
	adds r4, r0, 0
_080A7960:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundLives_Add
	subs r4, 0x1
	adds r5, 0x18
	cmp r4, 0
	bne _080A7960
_080A7976:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7980: .4byte gUnknown_811808C
_080A7984: .4byte gUnknown_8118098
	thumb_func_end GroundLives_Select

	thumb_func_start GroundLives_Cancel
GroundLives_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080A79F4
	movs r0, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl Log
	movs r1, 0
	ldr r0, _080A79F8
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080A79B2:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080A79D4
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080A79D4
	cmp r5, 0
	blt _080A79CE
	movs r0, 0x6
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080A79D4
_080A79CE:
	adds r0, r1, 0
	bl GroundLives_Delete
_080A79D4:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xF8
	lsls r2, 1
	adds r4, r2
	cmp r1, 0x17
	ble _080A79B2
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A79F4: .4byte gUnknown_81180BC
_080A79F8: .4byte gUnknown_3001B84
	thumb_func_end GroundLives_Cancel

	thumb_func_start sub_80A79FC
sub_80A79FC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080A7A70
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080A7A74
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080A7A20:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080A7A50
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080A7A50
	adds r0, r6, 0
	bl GroundLives_Delete
_080A7A50:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0x17
	ble _080A7A20
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7A70: .4byte gUnknown_81180D8
_080A7A74: .4byte gUnknown_3001B84
	thumb_func_end sub_80A79FC

	thumb_func_start sub_80A7A78
sub_80A7A78:
	push {r4-r7,lr}
	ldr r1, _080A7AC0
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080A7AC4
	ldr r4, [r0]
	movs r7, 0x1
	negs r7, r7
	movs r0, 0x9F
	lsls r0, 1
	adds r5, r4, r0
_080A7A92:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080A7ACC
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 4
	ands r0, r1
	cmp r0, 0
	beq _080A7AC8
	movs r0, 0xA2
	lsls r0, 1
	adds r1, r4, r0
	adds r0, 0x8
	adds r2, r4, r0
	movs r0, 0x20
	bl sub_80ADCA0
	b _080A7ACA
	.align 2, 0
_080A7AC0: .4byte gUnknown_81180D8
_080A7AC4: .4byte gUnknown_3001B84
_080A7AC8:
	ldr r0, _080A7AE4
_080A7ACA:
	strh r0, [r5]
_080A7ACC:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r5, r1
	adds r4, r1
	cmp r6, 0x17
	ble _080A7A92
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7AE4: .4byte 0x0000ffff
	thumb_func_end sub_80A7A78

	thumb_func_start sub_80A7AE8
sub_80A7AE8:
	push {r4-r7,lr}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl sub_80A7B94
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080A7B34
	movs r3, 0
	ldr r0, _080A7B24
	ldr r1, [r0]
	adds r4, r2, 0
	movs r2, 0x80
	lsls r2, 9
	adds r6, r2, 0
	movs r5, 0xF8
	lsls r5, 1
_080A7B16:
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080A7B28
	adds r0, r3, 0
	b _080A7B38
	.align 2, 0
_080A7B24: .4byte gUnknown_3001B84
_080A7B28:
	adds r0, r2, 0
	adds r2, r6
	asrs r3, r0, 16
	adds r1, r5
	cmp r3, 0x17
	ble _080A7B16
_080A7B34:
	movs r0, 0x1
	negs r0, r0
_080A7B38:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7AE8

	thumb_func_start sub_80A7B40
sub_80A7B40:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080A7B70
	ldr r1, [r0]
	movs r6, 0x1
	negs r6, r6
	movs r2, 0x80
	lsls r2, 9
	movs r5, 0x9E
	lsls r5, 1
_080A7B58:
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _080A7B74
	adds r0, r1, r5
	movs r7, 0
	ldrsh r0, [r0, r7]
	cmp r0, r4
	bne _080A7B74
	adds r0, r3, 0
	b _080A7B8C
	.align 2, 0
_080A7B70: .4byte gUnknown_3001B84
_080A7B74:
	adds r0, r2, 0
	movs r3, 0x80
	lsls r3, 9
	adds r2, r3
	asrs r3, r0, 16
	movs r7, 0xF8
	lsls r7, 1
	adds r1, r7
	cmp r3, 0x17
	ble _080A7B58
	movs r0, 0x1
	negs r0, r0
_080A7B8C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7B40

	thumb_func_start sub_80A7B94
sub_80A7B94:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r7, r0, 0
	movs r0, 0
	ldrsh r2, [r7, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A7BD4
	adds r0, r1
	movs r6, 0x1
	negs r6, r6
	movs r1, 0
	ldrsh r5, [r0, r1]
	cmp r5, 0x1
	bne _080A7C14
	adds r0, r2, 0
	cmp r0, 0
	bne _080A7C10
	movs r0, 0
	movs r1, 0x1C
	bl sub_8001658
	adds r4, r0, 0
	cmp r4, 0x1
	beq _080A7BDE
	cmp r4, 0x1
	bgt _080A7BD8
	cmp r4, 0
	beq _080A7BF2
	b _080A7C08
	.align 2, 0
_080A7BD4: .4byte gUnknown_811E63C
_080A7BD8:
	cmp r4, 0x2
	beq _080A7BE4
	b _080A7C08
_080A7BDE:
	movs r0, 0x2
	strh r0, [r7]
	b _080A7C10
_080A7BE4:
	bl sub_808D33C
	adds r6, r0, 0
	bl sub_808D3BC
	cmp r0, r6
	bne _080A7BF6
_080A7BF2:
	strh r5, [r7]
	b _080A7C10
_080A7BF6:
	bl sub_808D3F8
	cmp r0, r6
	bne _080A7C02
	strh r4, [r7]
	b _080A7C10
_080A7C02:
	movs r0, 0x3
	strh r0, [r7]
	b _080A7C10
_080A7C08:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _080A7DAC
_080A7C10:
	movs r6, 0
	b _080A7DD2
_080A7C14:
	cmp r5, 0x2
	bne _080A7CD2
	movs r0, 0
	movs r1, 0x1D
	bl sub_8001658
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x1E
	bl sub_8001658
	adds r2, r0, 0
	ldrh r1, [r7]
	subs r0, r1, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080A7C82
	cmp r1, 0x4
	bne _080A7C44
	adds r0, r4, 0
	cmp r0, 0
	bne _080A7C4C
	b _080A7C4A
_080A7C44:
	movs r0, 0
	cmp r4, 0
	beq _080A7C4C
_080A7C4A:
	adds r0, r2, 0
_080A7C4C:
	cmp r0, 0x2
	beq _080A7C7A
	cmp r0, 0x2
	bhi _080A7C5A
	cmp r0, 0x1
	beq _080A7C6E
	b _080A7DA6
_080A7C5A:
	cmp r0, 0x3
	beq _080A7C60
	b _080A7DA6
_080A7C60:
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	bne _080A7C72
_080A7C6E:
	movs r0, 0x6
	b _080A7C80
_080A7C72:
	bl sub_808D3F8
	cmp r0, r4
	bne _080A7C7E
_080A7C7A:
	movs r0, 0x7
	b _080A7C80
_080A7C7E:
	movs r0, 0x8
_080A7C80:
	strh r0, [r7]
_080A7C82:
	movs r0, 0
	ldrsh r5, [r7, r0]
	cmp r5, 0x7
	beq _080A7CB0
	cmp r5, 0x7
	bgt _080A7C94
	cmp r5, 0x6
	beq _080A7C9A
	b _080A7CCA
_080A7C94:
	cmp r5, 0x8
	beq _080A7CC6
	b _080A7CCA
_080A7C9A:
	movs r6, 0x2
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r4, r0
	beq _080A7CAC
	b _080A7DD2
_080A7CAC:
	strh r5, [r7]
	b _080A7DD2
_080A7CB0:
	movs r6, 0x1
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3F8
	cmp r4, r0
	beq _080A7CC2
	b _080A7DD2
_080A7CC2:
	movs r0, 0x6
	b _080A7DD0
_080A7CC6:
	movs r6, 0x2
	b _080A7DD2
_080A7CCA:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _080A7DAC
_080A7CD2:
	cmp r5, 0x3
	bne _080A7DB0
	ldrh r1, [r7]
	adds r0, r1, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A7D12
	adds r4, r2, 0
	subs r4, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _080A7DD2
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7D06
	mov r0, sp
	bl sub_808D6A4
	b _080A7D0C
_080A7D06:
	mov r0, sp
	bl sub_808D654
_080A7D0C:
	cmp r4, r0
	bge _080A7DA6
	b _080A7D7E
_080A7D12:
	adds r0, r1, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A7DA6
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A7DA6
	movs r2, 0
	ldrsh r0, [r7, r2]
	adds r4, r0, 0
	subs r4, 0xE
	adds r0, r1, 0
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bge _080A7DA6
	ldr r2, _080A7D84
	ldr r0, [sp, 0x8]
	adds r0, r4
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7D88
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7DA6
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A7DA6
_080A7D7E:
	movs r0, 0x1
	negs r0, r0
	b _080A7DD4
	.align 2, 0
_080A7D84: .4byte gUnknown_203B45C
_080A7D88:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7DA6
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A7DA6
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A7DA2
	movs r1, 0x1
_080A7DA2:
	cmp r1, 0
	beq _080A7D7E
_080A7DA6:
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
_080A7DAC:
	strh r0, [r7]
	b _080A7D7E
_080A7DB0:
	cmp r2, 0x23
	bne _080A7DD2
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	bne _080A7DC6
	movs r0, 0x21
	b _080A7DD0
_080A7DC6:
	bl sub_808D3F8
	cmp r0, r4
	bne _080A7DD2
	movs r0, 0x22
_080A7DD0:
	strh r0, [r7]
_080A7DD2:
	adds r0, r6, 0
_080A7DD4:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7B94

	thumb_func_start sub_80A7DDC
sub_80A7DDC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x24
	adds r7, r0, 0
	adds r5, r1, 0
	bl sub_80A7B94
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0
	strh r0, [r5]
	ldrh r3, [r7]
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r6, 0x1
	negs r6, r6
	cmp r0, r6
	bne _080A7E0A
_080A7E04:
	movs r0, 0x1
	negs r0, r0
	b _080A8098
_080A7E0A:
	movs r0, 0
	ldrsh r2, [r7, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A7E50
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	beq _080A7E22
	b _080A7F38
_080A7E22:
	adds r0, r3, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A7E90
	adds r4, r2, 0
	subs r4, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	beq _080A7E58
	ldr r0, _080A7E54
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
	cmp r0, 0
	bne _080A7E04
	strh r6, [r7]
	b _080A7E04
	.align 2, 0
_080A7E50: .4byte gUnknown_811E63C
_080A7E54: .4byte gUnknown_81180F0
_080A7E58:
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7E6C
	mov r0, sp
	bl sub_808D6A4
	b _080A7E72
_080A7E6C:
	mov r0, sp
	bl sub_808D654
_080A7E72:
	cmp r4, r0
	blt _080A7E78
	b _080A8080
_080A7E78:
	ldr r2, _080A7E8C
	lsls r0, r4, 2
	add r0, sp
	ldr r1, [r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldrh r0, [r0, 0x8]
	b _080A800A
	.align 2, 0
_080A7E8C: .4byte gUnknown_203B45C
_080A7E90:
	adds r0, r3, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bls _080A7E9E
	b _080A8080
_080A7E9E:
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080A7EB8
	b _080A8080
_080A7EB8:
	movs r2, 0
	ldrsh r0, [r7, r2]
	adds r4, r0, 0
	subs r4, 0xE
	adds r0, r1, 0
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _080A7ED8
	b _080A8080
_080A7ED8:
	ldr r2, _080A7F0C
	ldr r0, [sp, 0x8]
	adds r0, r4
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7F10
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A7EFE
	b _080A8080
_080A7EFE:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _080A7F06
	b _080A8080
_080A7F06:
	ldrh r0, [r4, 0x8]
	b _080A800A
	.align 2, 0
_080A7F0C: .4byte gUnknown_203B45C
_080A7F10:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A7F1C
	b _080A8080
_080A7F1C:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _080A7F24
	b _080A8080
_080A7F24:
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A7F2E
	movs r1, 0x1
_080A7F2E:
	cmp r1, 0
	beq _080A7F34
	b _080A8080
_080A7F34:
	ldrh r0, [r4, 0x8]
	b _080A800A
_080A7F38:
	subs r0, r3, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x23
	bls _080A7F44
	b _080A808A
_080A7F44:
	lsls r0, 2
	ldr r1, _080A7F50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A7F50: .4byte _080A7F54
	.align 2, 0
_080A7F54:
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A8032
	.4byte _080A8032
	.4byte _080A8014
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A7FFC
_080A7FE4:
	bl sub_808D3BC
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FEC:
	bl sub_808D3F8
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FF4:
	bl sub_808D33C
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FFC:
	movs r0, 0xF
	bl RandomCapped
	ldr r1, _080A8010
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
_080A800A:
	strh r0, [r5]
	b _080A7E04
	.align 2, 0
_080A8010: .4byte gUnknown_81180FC
_080A8014:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080A8028
	strh r0, [r5]
	b _080A7E04
_080A8028:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r7]
	b _080A7E04
_080A8032:
	movs r0, 0x89
	strh r0, [r5]
	add r6, sp, 0x10
	adds r0, r6, 0
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	bne _080A8046
	b _080A7E04
_080A8046:
	add r1, sp, 0x14
	add r2, sp, 0x18
	movs r0, 0x2
	bl sub_8001B88
	add r4, sp, 0x1C
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r6]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	beq _080A8076
	movs r2, 0
	ldrsh r0, [r7, r2]
	cmp r0, 0x1E
	bne _080A8072
	ldrh r0, [r4, 0x2]
	b _080A8074
_080A8072:
	ldrh r0, [r4, 0x4]
_080A8074:
	strh r0, [r5]
_080A8076:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080A8080
	b _080A7E04
_080A8080:
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r7]
	b _080A7E04
_080A808A:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080A8096
	ldrh r0, [r4, 0x2]
_080A8094:
	strh r0, [r5]
_080A8096:
	mov r0, r8
_080A8098:
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7DDC

	thumb_func_start GroundLives_Add
GroundLives_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0x10]
	lsls r0, 16
	asrs r6, r0, 16
	lsls r2, 16
	asrs r2, 16
	str r2, [sp, 0x14]
	lsls r3, 24
	asrs r3, 24
	str r3, [sp, 0x18]
	ldrb r1, [r1]
	add r0, sp, 0xC
	strh r1, [r0]
	movs r0, 0
	mov r8, r0
	mov r4, sp
	adds r4, 0xE
	add r0, sp, 0xC
	adds r1, r4, 0
	bl sub_80A7DDC
	lsls r0, 16
	asrs r7, r0, 16
	add r0, sp, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	mov r9, r4
	cmp r1, r0
	beq _080A81AE
	cmp r7, 0x1
	beq _080A8104
	cmp r7, 0x1
	bgt _080A80FA
	cmp r7, 0
	beq _080A8100
	b _080A8118
_080A80FA:
	cmp r7, 0x2
	beq _080A8108
	b _080A8118
_080A8100:
	movs r6, 0
	b _080A8118
_080A8104:
	movs r6, 0x1
	b _080A8118
_080A8108:
	movs r0, 0
	movs r1, 0x1D
	bl sub_8001658
	cmp r0, 0
	bne _080A8116
	movs r7, 0x1
_080A8116:
	movs r6, 0x2
_080A8118:
	add r0, sp, 0xC
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A813C
	adds r0, r1
	str r0, [sp, 0x1C]
	cmp r6, 0
	bge _080A81B4
	cmp r2, 0x21
	beq _080A8140
	cmp r2, 0x23
	beq _080A8154
	adds r0, r2, 0
	b _080A8162
	.align 2, 0
_080A813C: .4byte gUnknown_811E63C
_080A8140:
	ldr r0, _080A8150
	ldr r0, [r0]
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	cmp r0, 0x1
	beq _080A81AE
	movs r0, 0x21
	b _080A8162
	.align 2, 0
_080A8150: .4byte gUnknown_3001B84
_080A8154:
	ldr r0, _080A8188
	ldr r0, [r0]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0x3
	beq _080A81AE
	movs r0, 0x23
_080A8162:
	bl sub_80A7AE8
	adds r6, r0, 0
	cmp r6, 0
	bge _080A81B4
	movs r2, 0x3
	ldr r0, _080A8188
	ldr r0, [r0]
	movs r3, 0xBA
	lsls r3, 3
	adds r5, r0, r3
	movs r4, 0x2
	ldrsh r1, [r5, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A818C
	movs r6, 0x3
	b _080A81B4
	.align 2, 0
_080A8188: .4byte gUnknown_3001B84
_080A818C:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	cmp r2, 0x17
	bgt _080A81AA
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A818C
	adds r6, r2, 0
_080A81AA:
	cmp r6, 0
	bge _080A81B4
_080A81AE:
	movs r0, 0x1
	negs r0, r0
	b _080A8674
_080A81B4:
	ldr r1, _080A8234
	lsls r0, r6, 5
	subs r0, r6
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080A8238
	add r0, sp, 0xC
	movs r4, 0
	ldrsh r3, [r0, r4]
	ldr r2, [sp, 0x1C]
	movs r4, 0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x18]
	str r2, [sp, 0x8]
	movs r0, 0
	adds r2, r6, 0
	bl Log
	movs r2, 0
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A81F0
	movs r2, 0x1
_080A81F0:
	str r2, [sp, 0x20]
	strh r6, [r5]
	add r0, sp, 0xC
	ldrh r0, [r0]
	strh r0, [r5, 0x2]
	mov r4, sp
	ldrh r4, [r4, 0x14]
	strh r4, [r5, 0x4]
	mov r0, sp
	ldrb r0, [r0, 0x18]
	strb r0, [r5, 0x6]
	mov r1, r9
	ldrh r0, [r1]
	strh r0, [r5, 0x8]
	movs r2, 0x90
	lsls r2, 1
	adds r4, r5, r2
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x9
	str r0, [r4]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bhi _080A82D8
	lsls r0, 2
	ldr r1, _080A823C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A8234: .4byte gUnknown_3001B84
_080A8238: .4byte gUnknown_811811C
_080A823C: .4byte _080A8240
	.align 2, 0
_080A8240:
	.4byte _080A8268
	.4byte _080A8280
	.4byte _080A8290
	.4byte _080A82D8
	.4byte _080A82D8
	.4byte _080A8298
	.4byte _080A82A8
	.4byte _080A82B4
	.4byte _080A82BE
	.4byte _080A82CA
_080A8268:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A827C
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	b _080A82E0
	.align 2, 0
_080A827C: .4byte 0x2300181d
_080A8280:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080A828C
	b _080A82E0
	.align 2, 0
_080A828C: .4byte 0x23001000
_080A8290:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	b _080A82DE
_080A8298:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A82A4
	b _080A82E0
	.align 2, 0
_080A82A4: .4byte 0x2000000d
_080A82A8:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x80
	lsls r0, 10
	b _080A82E0
_080A82B4:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	b _080A82E0
_080A82BE:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0xC0
	lsls r0, 12
	b _080A82E0
_080A82CA:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A82D4
	b _080A82E0
	.align 2, 0
_080A82D4: .4byte 0x20010000
_080A82D8:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
_080A82DE:
	ldr r0, _080A83DC
_080A82E0:
	str r0, [r1]
	ldr r2, [sp, 0x1C]
	ldrb r1, [r2, 0x8]
	lsls r1, 11
	str r1, [r5, 0xC]
	ldrb r0, [r2, 0x9]
	lsls r0, 11
	str r0, [r5, 0x10]
	lsrs r1, 1
	str r1, [r5, 0x14]
	lsrs r0, 1
	str r0, [r5, 0x18]
	ldr r3, [sp, 0x10]
	ldrb r0, [r3, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, r3, 0
	adds r2, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A8328
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A8328
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080A8328:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A834A
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A834A
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080A834A:
	ldr r3, [sp, 0x20]
	cmp r3, 0
	beq _080A83EC
	ldrb r0, [r5, 0x1C]
	movs r4, 0xA1
	lsls r4, 1
	adds r1, r5, r4
	movs r3, 0
	strb r0, [r1]
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0xA6
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	adds r4, 0x6
	adds r2, r5, r4
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r5, r2
	adds r4, 0x10
	adds r0, r5, r4
	str r3, [r0]
	str r3, [r1]
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r5, r1
	strh r7, [r0]
	ldr r1, _080A83E0
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x8]
	str r3, [r1]
	str r3, [r1, 0x4]
	ldrh r0, [r5, 0x2]
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A83E4
	movs r0, 0x12
	bl OtherRandomCapped
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r5, r2
	strh r0, [r1]
	b _080A83EC
	.align 2, 0
_080A83DC: .4byte 0x2300068d
_080A83E0: .4byte gUnknown_3001B80
_080A83E4:
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r5, r4
	strh r3, [r0]
_080A83EC:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 4
	ands r0, r1
	cmp r0, 0
	beq _080A8418
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r5, r2
	movs r3, 0xA6
	lsls r3, 1
	adds r2, r5, r3
	movs r0, 0x20
	bl sub_80ADCA0
	movs r4, 0x9F
	lsls r4, 1
	adds r1, r5, r4
	b _080A8420
_080A8418:
	movs r0, 0x9F
	lsls r0, 1
	adds r1, r5, r0
	ldr r0, _080A849C
_080A8420:
	strh r0, [r1]
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r1, [sp, 0x20]
	cmp r1, 0
	beq _080A84AC
	ldr r2, _080A84A0
	adds r1, r5, r2
	movs r0, 0xFF
	strb r0, [r1]
	movs r3, 0xAF
	lsls r3, 1
	adds r1, r5, r3
	movs r3, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r4, 0xB0
	lsls r4, 1
	adds r1, r5, r4
	movs r2, 0x1
	movs r0, 0x1
	strh r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r5, r1
	str r3, [r0]
	adds r4, 0x8
	adds r1, r5, r4
	ldr r0, _080A84A4
	strh r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, 0xB5
	lsls r2, 1
	adds r0, r5, r2
	strh r3, [r0]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r5, r3
	movs r4, 0x2
	ldrsh r1, [r5, r4]
	movs r3, 0x8
	ldrsh r2, [r5, r3]
	movs r4, 0x8E
	lsls r4, 1
	adds r3, r5, r4
	ldr r3, [r3]
	bl sub_80A7428
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080A84A8
	ldr r0, [sp, 0x18]
	str r0, [sp]
	b _080A855C
	.align 2, 0
_080A849C: .4byte 0x0000ffff
_080A84A0: .4byte 0x0000015d
_080A84A4: .4byte 0x00000807
_080A84A8: .4byte gUnknown_8117F10
_080A84AC:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r0, _080A84F0
	ldr r1, [r0]
	movs r2, 0xCB
	lsls r2, 2
	adds r1, r2
	adds r0, r4, 0
	bl sub_809D684
	lsls r0, 24
	cmp r0, 0
	beq _080A8550
	adds r0, r5, 0
	adds r0, 0xBE
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	beq _080A84F4
	adds r0, r5, 0
	adds r0, 0xE0
	ldrh r0, [r0]
	mov r10, r0
	adds r0, r5, 0
	adds r0, 0xE2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r9, r0
	adds r7, r5, 0
	adds r7, 0x80
	movs r0, 0x82
	adds r0, r5
	b _080A8508
	.align 2, 0
_080A84F0: .4byte gUnknown_3001B80
_080A84F4:
	adds r1, r5, 0
	adds r1, 0x80
	ldrh r2, [r1]
	mov r10, r2
	adds r0, r5, 0
	adds r0, 0x82
	movs r3, 0
	ldrsb r3, [r0, r3]
	mov r9, r3
	adds r7, r1, 0
_080A8508:
	mov r8, r0
	adds r0, r4, 0
	bl sub_809D648
	ldr r1, _080A8544
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x14]
	bl sub_809D600
	ldr r0, _080A8548
	ldr r2, [r0]
	movs r1, 0xCB
	lsls r1, 2
	adds r2, r1
	ldr r3, _080A854C
	adds r0, r4, 0
	movs r1, 0
	bl GroundScript_ExecutePP
	mov r2, r10
	strh r2, [r7]
	mov r0, r9
	mov r3, r8
	strb r0, [r3]
	movs r1, 0x1
	mov r8, r1
	b _080A8566
	.align 2, 0
_080A8544: .4byte gUnknown_8117F10
_080A8548: .4byte gUnknown_3001B80
_080A854C: .4byte gUnknown_8118170
_080A8550:
	adds r0, r4, 0
	bl sub_809D648
	ldr r1, _080A861C
	ldr r2, [sp, 0x18]
	str r2, [sp]
_080A855C:
	adds r0, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x14]
	bl sub_809D600
_080A8566:
	ldr r3, [sp, 0x10]
	ldr r2, [r3, 0xC]
	cmp r2, 0
	bne _080A8574
	ldr r0, _080A8620
	adds r0, 0xEC
	ldr r2, [r0]
_080A8574:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_809D6D8
	ldr r0, [sp, 0x10]
	ldr r2, [r0, 0x10]
	cmp r2, 0
	bne _080A8588
	ldr r0, _080A8620
	ldr r2, [r0, 0x38]
_080A8588:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_809D6D8
	ldr r1, [sp, 0x10]
	ldr r2, [r1, 0x14]
	cmp r2, 0
	bne _080A859C
	ldr r0, _080A8620
	ldr r2, [r0, 0x50]
_080A859C:
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_809D6D8
	ldr r3, [sp, 0x10]
	ldr r2, [r3, 0x8]
	cmp r2, 0
	beq _080A8630
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080A860C
	mov r1, r8
	cmp r1, 0
	bne _080A860C
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	bne _080A860C
	ldr r0, _080A8624
	ldr r2, [r0]
	movs r3, 0xCB
	lsls r3, 2
	adds r2, r3
	ldr r3, _080A8628
	adds r0, r4, 0
	movs r1, 0
	bl GroundScript_ExecutePP
	movs r1, 0xB0
	lsls r1, 1
	adds r0, r5, r1
	movs r2, 0xAF
	lsls r2, 1
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	orrs r0, r1
	adds r1, r5, 0
	adds r1, 0x80
	strh r0, [r1]
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x82
	strb r1, [r0]
_080A860C:
	ldr r3, _080A862C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
	b _080A865A
	.align 2, 0
_080A861C: .4byte gUnknown_8117F10
_080A8620: .4byte gUnknown_812F1F8
_080A8624: .4byte gUnknown_3001B80
_080A8628: .4byte gUnknown_811817C
_080A862C: .4byte gUnknown_8118188
_080A8630:
	mov r4, r8
	cmp r4, 0
	beq _080A865A
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x82
	ldrb r0, [r0]
	movs r2, 0xA1
	lsls r2, 1
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x80
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_80A9750
_080A865A:
	ldr r3, [sp, 0x1C]
	movs r4, 0
	ldrsh r0, [r3, r4]
	cmp r0, 0x1
	bne _080A8672
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _080A8672
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_809D170
_080A8672:
	adds r0, r6, 0
_080A8674:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundLives_Add

	thumb_func_start GroundLives_Delete
GroundLives_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080A86BC
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080A86C0
	movs r0, 0
	bl Log
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A74E4
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080A86C4
	strh r0, [r4, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A86BC: .4byte gUnknown_3001B84
_080A86C0: .4byte gUnknown_8118194
_080A86C4: .4byte 0x0000ffff
	thumb_func_end GroundLives_Delete

	thumb_func_start sub_80A86C8
sub_80A86C8:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8708
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r3, 0x1
	negs r3, r3
	cmp r0, r3
	beq _080A8744
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _080A870C
	movs r0, 0xC0
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A872E
	bl sub_80AB5A4
	b _080A872E
	.align 2, 0
_080A8708: .4byte gUnknown_3001B84
_080A870C:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r5
	cmp r0, 0
	beq _080A872E
	ldr r2, _080A874C
	movs r0, 0
	ldrsh r1, [r1, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	str r3, [r1, 0x8]
	movs r0, 0
	str r0, [r1]
	str r0, [r1, 0x4]
_080A872E:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r5
	str r1, [r0]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r4, r2
	bl sub_80A6688
_080A8744:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A874C: .4byte gUnknown_3001B80
	thumb_func_end sub_80A86C8

	thumb_func_start sub_80A8750
sub_80A8750:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A87A8
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A87A2
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r4, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080A878C
	movs r0, 0xC0
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A878C
	bl sub_80AB5A4
_080A878C:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	bics r1, r5
	str r1, [r0]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r4, r2
	bl sub_80A6688
_080A87A2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A87A8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8750

	thumb_func_start sub_80A87AC
sub_80A87AC:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A87DC
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
	beq _080A87D8
	movs r1, 0x90
	lsls r1, 1
	adds r0, r2, r1
	adds r1, r3, 0
	bl sub_809CD8C
_080A87D8:
	pop {r0}
	bx r0
	.align 2, 0
_080A87DC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A87AC

	thumb_func_start sub_80A87E0
sub_80A87E0:
	push {r4,lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8820
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8824
	movs r0, 0x7
	movs r1, 0
	adds r2, r3, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _080A8824
	movs r1, 0x90
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0x5
	bl sub_809CD8C
	movs r0, 0x1
	b _080A8826
	.align 2, 0
_080A8820: .4byte gUnknown_3001B84
_080A8824:
	movs r0, 0
_080A8826:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A87E0

	thumb_func_start sub_80A882C
sub_80A882C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8850
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
	bne _080A8854
	movs r0, 0
	b _080A8858
	.align 2, 0
_080A8850: .4byte gUnknown_3001B84
_080A8854:
	adds r0, r2, 0
	adds r0, 0x38
_080A8858:
	pop {r1}
	bx r1
	thumb_func_end sub_80A882C

	thumb_func_start sub_80A885C
sub_80A885C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080A8884
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
	bne _080A8888
	movs r0, 0
	b _080A8898
	.align 2, 0
_080A8884: .4byte gUnknown_3001B84
_080A8888:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080A8898:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A885C

	thumb_func_start sub_80A88A0
sub_80A88A0:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A88C4
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
	bne _080A88C8
	movs r0, 0
	b _080A88D4
	.align 2, 0
_080A88C4: .4byte gUnknown_3001B84
_080A88C8:
	adds r0, r2, 0
	adds r0, 0x38
	bl sub_809D678
	lsls r0, 24
	lsrs r0, 24
_080A88D4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A88A0

	thumb_func_start GroundLives_ExecuteScript
GroundLives_ExecuteScript:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	asrs r4, 16
	ldr r1, _080A8914
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080A8918
	movs r0, 0x2
	ldrsh r3, [r5, r0]
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A891C
	movs r0, 0
	b _080A8934
	.align 2, 0
_080A8914: .4byte gUnknown_3001B84
_080A8918: .4byte gUnknown_81181B0
_080A891C:
	adds r0, r5, 0
	adds r0, 0x38
	ldr r3, _080A893C
	adds r1, r7, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080A8934:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A893C: .4byte gUnknown_81181F4
	thumb_func_end GroundLives_ExecuteScript

	thumb_func_start _ExecutePlayerScript
_ExecutePlayerScript:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r0, 0xAF
	lsls r0, 1
	adds r1, r3, r0
	movs r2, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r0, 0xB0
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strh r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	movs r0, 0xB4
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldr r1, _080A898C
	cmp r0, r1
	beq _080A8984
	strh r1, [r2]
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080A8984:
	cmp r4, 0
	bne _080A8990
	movs r0, 0
	b _080A89A2
	.align 2, 0
_080A898C: .4byte 0x00000807
_080A8990:
	adds r0, r3, 0
	adds r0, 0x38
	ldr r3, _080A89A8
	adds r1, r5, 0
	adds r2, r4, 0
	bl GroundScript_ExecutePP
	lsls r0, 24
	lsrs r0, 24
_080A89A2:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A89A8: .4byte gUnknown_8118218
	thumb_func_end _ExecutePlayerScript

	thumb_func_start sub_80A89AC
sub_80A89AC:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r4, _080A89CC
	lsls r3, r0, 5
	subs r3, r0
	lsls r3, 4
	ldr r0, [r4]
	adds r0, r3
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A89CC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A89AC

	thumb_func_start GroundLives_ExecutePlayerScriptActionLives
GroundLives_ExecutePlayerScriptActionLives:
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	cmp r2, 0
	blt _080A8A50
	cmp r4, 0
	blt _080A8A50
	ldr r1, _080A8A48
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	beq _080A8A50
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	cmp r0, r2
	beq _080A8A50
	adds r6, r1, 0
	adds r6, 0x38
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_809D6E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8A50
	movs r1, 0x1
	lsls r0, r4, 16
	orrs r0, r1
	str r0, [sp, 0xC]
	adds r1, r5, 0
	adds r1, 0x40
	ldr r3, _080A8A4C
	adds r0, r6, 0
	movs r2, 0x3
	bl sub_809D8C0
	add r1, sp, 0xC
	adds r0, r5, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8A52
	.align 2, 0
_080A8A48: .4byte gUnknown_3001B84
_080A8A4C: .4byte gUnknown_8118250
_080A8A50:
	movs r0, 0
_080A8A52:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GroundLives_ExecutePlayerScriptActionLives

	thumb_func_start sub_80A8A5C
sub_80A8A5C:
	push {r4-r6,lr}
	sub sp, 0x1C
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r5, r1, 16
	cmp r2, 0
	blt _080A8AC0
	cmp r5, 0
	blt _080A8AC0
	ldr r1, _080A8ABC
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_80AC274
	lsls r0, 24
	cmp r0, 0
	beq _080A8AC0
	movs r1, 0x2
	lsls r0, r5, 16
	orrs r0, r1
	str r0, [sp, 0x18]
	add r4, sp, 0xC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x3
	bl sub_80AC274
	adds r1, r6, 0
	adds r1, 0x40
	adds r0, r5, 0
	adds r2, r4, 0
	bl GroundObject_ExecuteScript
	add r1, sp, 0x18
	adds r0, r6, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8AC2
	.align 2, 0
_080A8ABC: .4byte gUnknown_3001B84
_080A8AC0:
	movs r0, 0
_080A8AC2:
	add sp, 0x1C
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8A5C

	thumb_func_start sub_80A8ACC
sub_80A8ACC:
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, 0
	blt _080A8B10
	cmp r3, 0
	blt _080A8B10
	ldr r1, _080A8B0C
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r4, r1, r0
	adds r0, r3, 0
	mov r1, sp
	bl sub_80ADC64
	lsls r0, 24
	cmp r0, 0
	beq _080A8B10
	adds r0, r4, 0
	movs r1, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8B12
	.align 2, 0
_080A8B0C: .4byte gUnknown_3001B84
_080A8B10:
	movs r0, 0
_080A8B12:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8ACC

	thumb_func_start sub_80A8B1C
sub_80A8B1C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080A8B70
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080A8B36:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080A8B4E
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080A8B4E:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	cmp r0, 0x17
	ble _080A8B36
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A8B70: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8B1C

	thumb_func_start sub_80A8B74
sub_80A8B74:
	push {r4-r7,lr}
	ldr r0, _080A8BB8
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080A8B84:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080A8B9A
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080A8B9A:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	cmp r0, 0x17
	ble _080A8B84
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A8BB8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8B74

	thumb_func_start sub_80A8BBC
sub_80A8BBC:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8BD4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A8BD4: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8BBC

	thumb_func_start sub_80A8BD8
sub_80A8BD8:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080A8BF8
	lsls r2, r0, 5
	subs r2, r0
	lsls r2, 4
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A8BF8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8BD8

	thumb_func_start sub_80A8BFC
sub_80A8BFC:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8C20
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
	bne _080A8C24
	movs r0, 0
	b _080A8C28
	.align 2, 0
_080A8C20: .4byte gUnknown_3001B84
_080A8C24:
	movs r1, 0x8
	ldrsh r0, [r2, r1]
_080A8C28:
	pop {r1}
	bx r1
	thumb_func_end sub_80A8BFC

	thumb_func_start sub_80A8C2C
sub_80A8C2C:
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A7DDC
	movs r1, 0
	ldrsh r0, [r4, r1]
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C2C

	thumb_func_start sub_80A8C4C
sub_80A8C4C:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8C80
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8C90
	adds r0, r1, 0
	bl sub_80A8D54
	adds r1, r0, 0
	cmp r1, 0
	beq _080A8C84
	ldr r0, [r1, 0x4]
	str r0, [r5]
	b _080A8C8A
	.align 2, 0
_080A8C80: .4byte gUnknown_3001B84
_080A8C84:
	movs r0, 0x63
	strb r0, [r5]
	strb r1, [r5, 0x1]
_080A8C8A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	b _080A8C92
_080A8C90:
	movs r0, 0
_080A8C92:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C4C

	thumb_func_start sub_80A8C98
sub_80A8C98:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8CD4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8CE8
	ldr r1, _080A8CD8
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _080A8CE8
	movs r0, 0x8
	ldrsh r3, [r3, r0]
_080A8CC6:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r3
	bne _080A8CDC
	movs r0, 0x1
	b _080A8CEA
	.align 2, 0
_080A8CD4: .4byte gUnknown_3001B84
_080A8CD8: .4byte gUnknown_8117FCE
_080A8CDC:
	adds r1, 0x2
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080A8CC6
_080A8CE8:
	movs r0, 0
_080A8CEA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C98

	thumb_func_start sub_80A8CF0
sub_80A8CF0:
	push {r4,lr}
	lsls r0, 16
	asrs r3, r0, 16
	ldr r1, _080A8CFC
	b _080A8D0E
	.align 2, 0
_080A8CFC: .4byte gUnknown_8117FCE
_080A8D00:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r3
	bne _080A8D0C
	movs r0, 0x1
	b _080A8D1A
_080A8D0C:
	adds r1, 0x2
_080A8D0E:
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080A8D00
	movs r0, 0
_080A8D1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8CF0

	thumb_func_start sub_80A8D20
sub_80A8D20:
	push {lr}
	movs r0, 0
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8D50
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x90
	lsls r1, 1
	adds r0, r1
	bl sub_809CDB8
	movs r1, 0
	cmp r0, 0x1
	bne _080A8D4A
	movs r1, 0x1
_080A8D4A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_080A8D50: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8D20

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
	bl sub_808D33C
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
_080A8DF4: .4byte gUnknown_203B45C
_080A8DF8:
	adds r0, r1, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A8E92
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
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
	bl sub_8092638
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
_080A8E6C: .4byte gUnknown_203B45C
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
_080A8EBC: .4byte gUnknown_3001B84
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
_080A8F2C: .4byte gUnknown_811E63C
_080A8F30:
	movs r2, 0x2
	ldrsh r1, [r0, r2]
_080A8F34:
	adds r0, r4, 0
	bl sub_808D8BC
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
_080A8F4C: .4byte gUnknown_811825C
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
	bl sub_8092310
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
_080A8F98: .4byte gUnknown_3001B84
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
_080A8FC4: .4byte gUnknown_3001B84
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
_080A9000: .4byte gUnknown_3001B84
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
_080A904C: .4byte gUnknown_3001B84
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
_080A9078: .4byte gUnknown_3001B84
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
_080A90C4: .4byte gUnknown_3001B84
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
_080A90E4: .4byte gUnknown_3001B84
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
	bl sub_8002DF0
	b _080A917E
	.align 2, 0
_080A916C: .4byte gUnknown_3001B84
_080A9170:
	adds r1, r5, 0
	adds r1, 0xC
	adds r3, r4, 0
	adds r3, 0xC
	mov r0, sp
	bl sub_8002D54
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
	bl sub_8002DF0
	lsls r0, 24
	asrs r0, 24
	mov r9, r0
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_8002D54
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
_080A9260: .4byte gUnknown_3001B84
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

	thumb_func_start sub_80A92A0
sub_80A92A0:
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
_080A931C: .4byte gUnknown_3001B84
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
	thumb_func_end sub_80A92A0

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
_080A93C4: .4byte gUnknown_3001B84
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
_080A947C: .4byte gUnknown_3001B84
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
	bl sub_80A585C
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
	bl sub_80A92A0
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
	bl sub_80ADCA0
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
	bl sub_80A585C
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
	bl sub_80A92A0
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
_080A96C4: .4byte gUnknown_3001B84
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
	bl sub_80ADCA0
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
	bl sub_80ADCA0
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
	bl sub_8002C60
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
	bl sub_8002C60
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
	bl sub_80A92A0
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
_080AA3CC: .4byte gUnknown_3001B84
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
	bl sub_8002BB8
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
	bl sub_8002BB8
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
	bl sub_80A92A0
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
	bl sub_8002BB8
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
	bl sub_8002BB8
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
	bl sub_8002BB8
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
_080AAD98: .4byte gUnknown_3001B80
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
	bl sub_8002BB8
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
_080AADF0: .4byte gUnknown_3001B80
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
	bl sub_809D710
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
	bl sub_809D710
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
	bl sub_809D710
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

	thumb_func_start sub_80AB008
sub_80AB008:
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AB008

	thumb_func_start sub_80AB010
sub_80AB010:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AB010

	thumb_func_start sub_80AB01C
sub_80AB01C:
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
	thumb_func_end sub_80AB01C

	thumb_func_start sub_80AB0C8
sub_80AB0C8:
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
	thumb_func_end sub_80AB0C8

	thumb_func_start sub_80AB0E0
sub_80AB0E0:
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
	thumb_func_end sub_80AB0E0

	thumb_func_start sub_80AB100
sub_80AB100:
	push {lr}
	bl sub_80A9F20
	pop {r1}
	bx r1
	thumb_func_end sub_80AB100

	thumb_func_start sub_80AB10C
sub_80AB10C:
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
	thumb_func_end sub_80AB10C

	thumb_func_start sub_80AB12C
sub_80AB12C:
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AB12C

	thumb_func_start sub_80AB138
sub_80AB138:
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AB138

	thumb_func_start sub_80AB144
sub_80AB144:
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
	thumb_func_end sub_80AB144

	thumb_func_start sub_80AB184
sub_80AB184:
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80A9750
	pop {r0}
	bx r0
	thumb_func_end sub_80AB184

	thumb_func_start sub_80AB194
sub_80AB194:
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
	thumb_func_end sub_80AB194

	thumb_func_start nullsub_211
nullsub_211:
	bx lr
	thumb_func_end nullsub_211

	thumb_func_start sub_80AB1C0
sub_80AB1C0:
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
	thumb_func_end sub_80AB1C0

	thumb_func_start sub_80AB1E4
sub_80AB1E4:
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
	thumb_func_end sub_80AB1E4

	thumb_func_start sub_80AB20C
sub_80AB20C:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80AB20C

	thumb_func_start sub_80AB218
sub_80AB218:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A86C8
	pop {r0}
	bx r0
	thumb_func_end sub_80AB218

	thumb_func_start sub_80AB228
sub_80AB228:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A8750
	pop {r0}
	bx r0
	thumb_func_end sub_80AB228

	thumb_func_start sub_80AB238
sub_80AB238:
	push {lr}
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r2
	bl sub_80A6EC8
	pop {r0}
	bx r0
	thumb_func_end sub_80AB238

	thumb_func_start sub_80AB248
sub_80AB248:
	push {lr}
	bl sub_80A9F94
	pop {r1}
	bx r1
	thumb_func_end sub_80AB248

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
_080AB29C: .4byte gUnknown_3001B84
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
	bl sub_8002C60
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
	bl sub_809D8C0
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
_080AB4CC: .4byte gUnknown_3001B80
_080AB4D0: .4byte gUnknown_3001B84
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
_080AB5D0: .4byte gUnknown_3001B80
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
	bl sub_8002BB8
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
_080AB6BC: .4byte gUnknown_3001B80
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
_080AB754: .4byte gUnknown_3001B80
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
_080AB7D4: .4byte gUnknown_3001B80
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
_080AB860: .4byte gUnknown_3001B80
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
	bl sub_8002C60
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
_080AB96C: .4byte gUnknown_3001B80
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
_080ABA34: .4byte gUnknown_3001B80
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
_080ABB50: .4byte gUnknown_3001B84
	thumb_func_end sub_80ABA7C

	thumb_func_start sub_80ABB54
sub_80ABB54:
	push {r4,r5,lr}
	ldr r4, _080ABB90
	movs r0, 0xE2
	lsls r0, 5
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080ABB94
	adds r5, r0, 0
	movs r4, 0xE2
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080ABB74:
	ldrh r0, [r1, 0x6]
	orrs r0, r5
	strh r0, [r1, 0x6]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0xF
	ble _080ABB74
	bl sub_80ABB98
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB90: .4byte gUnknown_3001B88
_080ABB94: .4byte 0x0000ffff
	thumb_func_end sub_80ABB54

	thumb_func_start sub_80ABB98
sub_80ABB98:
	push {r4-r6,lr}
	ldr r0, _080ABBD0
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080ABBA8:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080ABBB6
	adds r0, r1, 0
	bl GroundObject_Delete
_080ABBB6:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ABBA8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBD0: .4byte gUnknown_3001B88
	thumb_func_end sub_80ABB98

	thumb_func_start sub_80ABBD4
sub_80ABBD4:
	push {r4,lr}
	bl sub_80ABB98
	ldr r4, _080ABBEC
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBEC: .4byte gUnknown_3001B88
	thumb_func_end sub_80ABBD4

	thumb_func_start GroundObject_Select
GroundObject_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ABC54
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ABC58
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0xC]
	ldr r0, [r0, 0x8]
	cmp r0, 0
	ble _080ABC4A
	adds r4, r0, 0
_080ABC34:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundObject_Add
	subs r4, 0x1
	adds r5, 0x18
	cmp r4, 0
	bne _080ABC34
_080ABC4A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABC54: .4byte gUnknown_81183E4
_080ABC58: .4byte gUnknown_81183F0
	thumb_func_end GroundObject_Select

	thumb_func_start GroundObject_Cancel
GroundObject_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ABCC4
	movs r0, 0
	adds r2, r7, 0
	bl Log
	movs r1, 0
	ldr r0, _080ABCC8
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ABC84:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ABCA6
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ABCA6
	cmp r5, 0
	blt _080ABCA0
	movs r0, 0xA
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ABCA6
_080ABCA0:
	adds r0, r1, 0
	bl GroundObject_Delete
_080ABCA6:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ABC84
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABCC4: .4byte gUnknown_8118414
_080ABCC8: .4byte gUnknown_3001B88
	thumb_func_end GroundObject_Cancel

	thumb_func_start GroundObject_CancelBlank
GroundObject_CancelBlank:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080ABD40
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080ABD44
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x92
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080ABCF0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080ABD20
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080ABD20
	adds r0, r6, 0
	bl GroundObject_Delete
_080ABD20:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0xF
	ble _080ABCF0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABD40: .4byte gUnknown_811842C
_080ABD44: .4byte gUnknown_3001B88
	thumb_func_end GroundObject_CancelBlank

	thumb_func_start sub_80ABD48
sub_80ABD48:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080ABD6C
	ldr r1, [r0]
	movs r6, 0xE2
	lsls r6, 1
	movs r2, 0x80
	lsls r2, 9
	adds r5, r2, 0
_080ABD5E:
	movs r7, 0x6
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080ABD70
	adds r0, r3, 0
	b _080ABD80
	.align 2, 0
_080ABD6C: .4byte gUnknown_3001B88
_080ABD70:
	adds r0, r2, 0
	adds r2, r5
	asrs r3, r0, 16
	adds r1, r6
	cmp r3, 0xF
	ble _080ABD5E
	movs r0, 0x1
	negs r0, r0
_080ABD80:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABD48

	thumb_func_start GroundObject_Add
GroundObject_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldrb r4, [r1]
	cmp r4, 0x1A
	bne _080ABDDA
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	cmp r0, 0x1
	bgt _080ABDBC
	movs r4, 0x1B
	b _080ABDDA
_080ABDBC:
	movs r0, 0
	movs r1, 0x29
	bl sub_8001658
	cmp r0, 0
	bne _080ABDD4
	movs r0, 0
	movs r1, 0x27
	bl sub_8001658
	adds r0, 0x1C
	b _080ABDD6
_080ABDD4:
	adds r0, 0x2B
_080ABDD6:
	lsls r0, 16
	asrs r4, r0, 16
_080ABDDA:
	lsls r1, r4, 2
	ldr r0, _080ABE10
	adds r6, r1, r0
	cmp r7, 0
	bge _080ABE40
	cmp r4, 0xE
	bgt _080ABDF4
	cmp r4, 0xD
	blt _080ABDF4
	adds r0, r4, 0
	bl sub_80ABD48
	adds r7, r0, 0
_080ABDF4:
	cmp r7, 0
	bge _080ABE40
	movs r3, 0
	ldr r0, _080ABE14
	ldr r5, [r0]
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE18
	movs r7, 0
	b _080ABE40
	.align 2, 0
_080ABE10: .4byte gUnknown_811ED20
_080ABE14: .4byte gUnknown_3001B88
_080ABE18:
	adds r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r5, r1
	cmp r3, 0xF
	bgt _080ABE36
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE18
	adds r7, r3, 0
_080ABE36:
	cmp r7, 0
	bge _080ABE40
	movs r0, 0x1
	negs r0, r0
	b _080AC142
_080ABE40:
	ldr r1, _080ABEA8
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080ABEAC
	mov r3, r8
	ldrb r0, [r3]
	str r0, [sp]
	movs r2, 0
	ldrsh r0, [r6, r2]
	str r0, [sp, 0x4]
	mov r3, r10
	str r3, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	movs r0, 0
	adds r2, r7, 0
	adds r3, r4, 0
	bl Log
	movs r2, 0
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE80
	movs r2, 0x1
_080ABE80:
	str r2, [sp, 0x10]
	strh r7, [r5, 0x4]
	strh r4, [r5, 0x6]
	mov r0, r10
	strh r0, [r5, 0x8]
	mov r1, r9
	strb r1, [r5, 0xA]
	ldrh r0, [r6]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bls _080ABE9C
	b _080ABF8C
_080ABE9C:
	lsls r0, 2
	ldr r1, _080ABEB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ABEA8: .4byte gUnknown_3001B88
_080ABEAC: .4byte gUnknown_8118448
_080ABEB0: .4byte _080ABEB4
	.align 2, 0
_080ABEB4:
	.4byte _080ABEF0
	.4byte _080ABF7C
	.4byte _080ABF46
	.4byte _080ABF54
	.4byte _080ABF54
	.4byte _080ABF5E
	.4byte _080ABF68
	.4byte _080ABF72
	.4byte _080ABF3C
	.4byte _080ABEFA
	.4byte _080ABEF0
	.4byte _080ABF06
	.4byte _080ABF2C
	.4byte _080ABF1E
	.4byte _080ABF12
_080ABEF0:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	b _080ABF94
_080ABEFA:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x80
	lsls r0, 10
	b _080ABF94
_080ABF06:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x80
	lsls r0, 11
	b _080ABF94
_080ABF12:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x83
	lsls r0, 18
	b _080ABF94
_080ABF1E:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABF28
	b _080ABF94
	.align 2, 0
_080ABF28: .4byte 0x220c0000
_080ABF2C:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	ldr r0, _080ABF38
	b _080ABF94
	.align 2, 0
_080ABF38: .4byte 0x20010000
_080ABF3C:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x5
	b _080ABF94
_080ABF46:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABF50
	b _080ABF94
	.align 2, 0
_080ABF50: .4byte 0x22000184
_080ABF54:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	adds r0, 0x68
	b _080ABF94
_080ABF5E:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x44
	b _080ABF94
_080ABF68:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x84
	b _080ABF94
_080ABF72:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	adds r0, 0x64
	b _080ABF94
_080ABF7C:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080ABF88
	b _080ABF94
	.align 2, 0
_080ABF88: .4byte 0x020000c4
_080ABF8C:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABFA8
_080ABF94:
	str r0, [r1]
	ldrb r0, [r6, 0x2]
	cmp r0, 0
	bne _080ABFAC
	mov r1, r8
	ldrb r0, [r1, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r1, 0x3]
	b _080ABFB4
	.align 2, 0
_080ABFA8: .4byte 0x02000185
_080ABFAC:
	ldrb r0, [r6, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r6, 0x3]
_080ABFB4:
	lsls r0, 11
	str r0, [r5, 0x10]
	ldr r0, [r5, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x14]
	ldr r0, [r5, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x18]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ABFFC
	mov r3, r8
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ABFFC
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080ABFFC:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AC01E
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AC01E
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080AC01E:
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _080AC076
	ldrb r1, [r5, 0x1C]
	movs r2, 0x90
	lsls r2, 1
	adds r0, r5, r2
	movs r3, 0
	strb r1, [r0]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x96
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x98
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r5, r2
	adds r2, 0x4
	adds r0, r5, r2
	str r3, [r0]
	str r3, [r1]
_080AC076:
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _080AC0C0
	movs r0, 0x9F
	lsls r0, 1
	adds r1, r5, r0
	movs r2, 0
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	movs r3, 0x6
	ldrsh r2, [r5, r3]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r3, [r1]
	adds r1, r7, 0
	bl sub_80A75CC
_080AC0C0:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AC154
	mov r0, r9
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl sub_809D600
	adds r6, r4, 0
	mov r1, r8
	ldr r2, [r1, 0xC]
	cmp r2, 0
	bne _080AC0F2
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	bl sub_80A66A4
	lsls r0, 24
	ldr r2, _080AC158
	cmp r0, 0
	beq _080AC0F2
	ldr r2, _080AC15C
_080AC0F2:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_809D6D8
	adds r1, r4, 0
	mov r3, r8
	ldr r2, [r3, 0x10]
	cmp r2, 0
	bne _080AC108
	ldr r0, _080AC160
	ldr r2, [r0, 0x38]
_080AC108:
	adds r0, r1, 0
	movs r1, 0x2
	bl sub_809D6D8
	mov r0, r8
	ldr r2, [r0, 0x14]
	cmp r2, 0
	bne _080AC11C
	ldr r0, _080AC160
	ldr r2, [r0, 0x68]
_080AC11C:
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_809D6D8
	mov r1, r8
	ldr r2, [r1, 0x8]
	cmp r2, 0
	beq _080AC140
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r3, _080AC164
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
_080AC140:
	adds r0, r7, 0
_080AC142:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC154: .4byte gUnknown_81182A0
_080AC158: .4byte gUnknown_81182F4
_080AC15C: .4byte gUnknown_8118350
_080AC160: .4byte gUnknown_812F1F8
_080AC164: .4byte gUnknown_81184A4
	thumb_func_end GroundObject_Add

	thumb_func_start GroundObject_Delete
GroundObject_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080AC1A4
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AC1A8
	movs r0, 0
	bl Log
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A7658
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080AC1AC
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC1A4: .4byte gUnknown_3001B88
_080AC1A8: .4byte gUnknown_81184B0
_080AC1AC: .4byte 0x0000ffff
	thumb_func_end GroundObject_Delete

	thumb_func_start sub_80AC1B0
sub_80AC1B0:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC1F0
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC1EA
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r2, r3
	bl sub_80A6688
_080AC1EA:
	pop {r0}
	bx r0
	.align 2, 0
_080AC1F0: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC1B0

	thumb_func_start sub_80AC1F4
sub_80AC1F4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC238
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC232
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, _080AC23C
	eors r0, r4
	ldr r1, [r2]
	ands r1, r0
	str r1, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	bl sub_80A6688
_080AC232:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC238: .4byte gUnknown_3001B88
_080AC23C: .4byte 0x337fffff
	thumb_func_end sub_80AC1F4

	thumb_func_start sub_80AC240
sub_80AC240:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC268
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC26C
	movs r0, 0
	b _080AC270
	.align 2, 0
_080AC268: .4byte gUnknown_3001B88
_080AC26C:
	adds r0, r2, 0
	adds r0, 0x38
_080AC270:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC240

	thumb_func_start sub_80AC274
sub_80AC274:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080AC2A0
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC2A4
	movs r0, 0
	b _080AC2B4
	.align 2, 0
_080AC2A0: .4byte gUnknown_3001B88
_080AC2A4:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080AC2B4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC274

	thumb_func_start GroundObject_ExecuteScript
GroundObject_ExecuteScript:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	asrs r3, 16
	ldr r1, _080AC2F4
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AC2F8
	movs r0, 0
	adds r2, r3, 0
	bl Log
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC2FC
	movs r0, 0
	b _080AC314
	.align 2, 0
_080AC2F4: .4byte gUnknown_3001B88
_080AC2F8: .4byte gUnknown_81184CC
_080AC2FC:
	adds r0, r4, 0
	adds r0, 0x38
	ldr r3, _080AC31C
	adds r1, r5, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AC314:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AC31C: .4byte gUnknown_8118504
	thumb_func_end GroundObject_ExecuteScript

	thumb_func_start sub_80AC320
sub_80AC320:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080AC374
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080AC33A:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080AC352
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AC352:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AC33A
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC374: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC320

	thumb_func_start sub_80AC378
sub_80AC378:
	push {r4-r7,lr}
	ldr r0, _080AC3BC
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080AC388:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080AC39E
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AC39E:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AC388
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC3BC: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC378

	thumb_func_start sub_80AC3C0
sub_80AC3C0:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC3DC
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AC3DC: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC3C0

	thumb_func_start sub_80AC3E0
sub_80AC3E0:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AC404
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AC404: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC3E0

	thumb_func_start sub_80AC408
sub_80AC408:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC434
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC438
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080AC440
	.align 2, 0
_080AC434: .4byte gUnknown_3001B88
_080AC438:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080AC440:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AC408

	thumb_func_start sub_80AC448
sub_80AC448:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC474
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC478
	movs r0, 0
	str r0, [r3]
	b _080AC492
	.align 2, 0
_080AC474: .4byte gUnknown_3001B88
_080AC478:
	movs r1, 0x92
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080AC492:
	str r0, [r3, 0x4]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AC448

	thumb_func_start sub_80AC49C
sub_80AC49C:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AC4C4
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80AC6AC
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AC4C4: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC49C

	thumb_func_start sub_80AC4C8
sub_80AC4C8:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _080AC530
	ldr r3, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r6, 0x80
	lsls r6, 9
_080AC4DE:
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r0, r12
	beq _080AC534
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	ands r0, r7
	cmp r0, 0
	beq _080AC534
	adds r1, 0x8
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r1, r0
	bge _080AC534
	movs r1, 0x96
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	ble _080AC534
	movs r1, 0x94
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _080AC534
	movs r1, 0x98
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080AC534
	adds r0, r5, 0
	b _080AC54C
	.align 2, 0
_080AC530: .4byte gUnknown_3001B88
_080AC534:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r5, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r3, r0
	cmp r5, 0xF
	ble _080AC4DE
	movs r0, 0x1
	negs r0, r0
_080AC54C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC4C8

	thumb_func_start sub_80AC554
sub_80AC554:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	mov r10, r1
	adds r4, r2, 0
	ldr r0, _080AC5C8
	ldr r0, [r0]
	mov r12, r0
	movs r6, 0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	movs r7, 0x80
	lsls r7, 9
_080AC576:
	mov r1, r12
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r0, r9
	beq _080AC5CC
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r5, r8
	ands r0, r5
	cmp r0, 0
	beq _080AC5CC
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	mov r5, r12
	ldr r0, [r5, 0x14]
	adds r2, r1, r0
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r3, r1, r0
	ldr r0, [r4]
	cmp r2, r0
	bge _080AC5CC
	mov r1, r10
	ldr r0, [r1]
	cmp r2, r0
	ble _080AC5CC
	ldr r0, [r4, 0x4]
	cmp r3, r0
	bge _080AC5CC
	ldr r0, [r1, 0x4]
	cmp r3, r0
	ble _080AC5CC
	adds r0, r6, 0
	b _080AC5E4
	.align 2, 0
_080AC5C8: .4byte gUnknown_3001B88
_080AC5CC:
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 9
	adds r7, r2
	asrs r6, r0, 16
	movs r5, 0xE2
	lsls r5, 1
	add r12, r5
	cmp r6, 0xF
	ble _080AC576
	movs r0, 0x1
	negs r0, r0
_080AC5E4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC554

	thumb_func_start sub_80AC5F4
sub_80AC5F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, [r5]
	cmp r0, 0
	bge _080AC60C
	ldr r1, _080AC670
	adds r0, r1
_080AC60C:
	asrs r0, 11
	mov r12, r0
	str r0, [sp]
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _080AC61C
	ldr r3, _080AC670
	adds r0, r3
_080AC61C:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080AC62C
	ldr r7, _080AC674
	adds r0, r3, r7
_080AC62C:
	asrs r1, r0, 11
	ldr r3, [r6, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080AC63A
	ldr r7, _080AC674
	adds r0, r3, r7
_080AC63A:
	asrs r2, r0, 11
	mov r3, r12
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r0, 0x8E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080AC678
	mov r0, sp
	adds r1, r2, 0
	bl sub_80A585C
	lsls r0, 24
	cmp r0, 0
	beq _080AC678
	movs r0, 0x1
	b _080AC6A0
	.align 2, 0
_080AC670: .4byte 0x000007ff
_080AC674: .4byte 0x000007fe
_080AC678:
	movs r0, 0x8E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080AC69E
	movs r0, 0x1
	negs r0, r0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80A92A0
	lsls r0, 16
	cmp r0, 0
	blt _080AC69E
	movs r0, 0x4
	b _080AC6A0
_080AC69E:
	movs r0, 0
_080AC6A0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC5F4

	thumb_func_start sub_80AC6AC
sub_80AC6AC:
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
	blt _080AC6EA
	ldr r1, [r5, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	bge _080AC6EA
	ldr r1, [r5, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	blt _080AC6EA
	ldr r0, [r5, 0x34]
	cmp r3, r0
	blt _080AC6EE
_080AC6EA:
	movs r0, 0x1
	b _080AC718
_080AC6EE:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80AC5F4
	cmp r0, 0
	bne _080AC718
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
_080AC718:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC6AC

	thumb_func_start sub_80AC720
sub_80AC720:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0x94
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
	movs r2, 0x98
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	movs r5, 0
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r2, r1, 0
	cmp r0, r3
	bge _080AC770
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080AC780
_080AC770:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AC782
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080AC780:
	movs r5, 0x1
_080AC782:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AC794
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r2, 0x4]
	b _080AC7A4
_080AC794:
	ldr r1, [r4, 0x34]
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AC7A6
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r2, 0x4]
_080AC7A4:
	movs r5, 0x1
_080AC7A6:
	adds r0, r4, 0
	mov r1, sp
	bl sub_80AC5F4
	cmp r0, 0
	bne _080AC7D8
	movs r3, 0x92
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r5, 0
	bne _080AC7D6
	movs r0, 0
	b _080AC7D8
_080AC7D6:
	movs r0, 0x1
_080AC7D8:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC720

	thumb_func_start sub_80AC7E0
sub_80AC7E0:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AC7E0

	thumb_func_start sub_80AC7E8
sub_80AC7E8:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AC7E8

	thumb_func_start sub_80AC7F4
sub_80AC7F4:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AC834
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AC89A
_080AC834:
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AC896
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AC896:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AC89A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC7F4

	thumb_func_start sub_80AC8A0
sub_80AC8A0:
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
	thumb_func_end sub_80AC8A0

	thumb_func_start sub_80AC8B8
sub_80AC8B8:
	adds r3, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AC8B8

	thumb_func_start sub_80AC8D8
sub_80AC8D8:
	push {lr}
	bl sub_80AC6AC
	pop {r1}
	bx r1
	thumb_func_end sub_80AC8D8

	thumb_func_start sub_80AC8E4
sub_80AC8E4:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC8E4

	thumb_func_start sub_80AC904
sub_80AC904:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AC904

	thumb_func_start sub_80AC910
sub_80AC910:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AC910

	thumb_func_start sub_80AC91C
sub_80AC91C:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC934
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AC934:
	pop {r0}
	bx r0
	thumb_func_end sub_80AC91C

	thumb_func_start sub_80AC938
sub_80AC938:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AC958
	ldr r1, _080AC954
	lsls r0, 1
	adds r0, r1
	b _080AC95E
	.align 2, 0
_080AC954: .4byte gUnknown_81183A0
_080AC958:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AC95E:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AC97C
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AC98C
_080AC97C:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AC990
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AC98C:
	movs r0, 0x1
	strb r0, [r1]
_080AC990:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC938

	thumb_func_start sub_80AC998
sub_80AC998:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AC9AA
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AC9AA:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AC998

	thumb_func_start sub_80AC9B8
sub_80AC9B8:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC9D6
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AC9D8
_080AC9D6:
	movs r0, 0x1
_080AC9D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC9B8

	thumb_func_start sub_80AC9DC
sub_80AC9DC:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AC9FE
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080ACA00
_080AC9FE:
	movs r0, 0x1
_080ACA00:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC9DC

	thumb_func_start sub_80ACA04
sub_80ACA04:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80ACA04

	thumb_func_start sub_80ACA10
sub_80ACA10:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1B0
	pop {r0}
	bx r0
	thumb_func_end sub_80ACA10

	thumb_func_start sub_80ACA20
sub_80ACA20:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1F4
	pop {r0}
	bx r0
	thumb_func_end sub_80ACA20

	thumb_func_start sub_80ACA30
sub_80ACA30:
	push {lr}
	bl sub_80AC720
	pop {r1}
	bx r1
	thumb_func_end sub_80ACA30

	thumb_func_start GroundObject_Action
GroundObject_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080ACA7C
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080ACA54:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080ACAB2
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080ACA80
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080ACA84
	cmp r0, 0x4
	bne _080ACA90
	adds r0, r7, 0
	bl GroundObject_Delete
	b _080ACAB2
	.align 2, 0
_080ACA7C: .4byte gUnknown_3001B88
_080ACA80: .4byte gUnknown_8118524
_080ACA84:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080ACAD0
	bl sub_809D8C0
_080ACA90:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080ACAB2
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080ACAB2:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080ACA54
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAD0: .4byte gUnknown_8118530
	thumb_func_end GroundObject_Action

	thumb_func_start sub_80ACAD4
sub_80ACAD4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080ACB8C
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080ACAF2:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080ACB64
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080ACB40
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080ACB40:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080ACB5A
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080ACB5A:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7664
_080ACB64:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080ACAF2
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACB8C: .4byte gUnknown_3001B88
	thumb_func_end sub_80ACAD4

	thumb_func_start sub_80ACB90
sub_80ACB90:
	push {r4,r5,lr}
	ldr r4, _080ACBCC
	movs r0, 0xE2
	lsls r0, 5
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080ACBD0
	adds r5, r0, 0
	movs r4, 0xE2
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080ACBB0:
	ldrh r0, [r1, 0x6]
	orrs r0, r5
	strh r0, [r1, 0x6]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0xF
	ble _080ACBB0
	bl sub_80ACBD4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACBCC: .4byte gUnknown_3001B8C
_080ACBD0: .4byte 0x0000ffff
	thumb_func_end sub_80ACB90

	thumb_func_start sub_80ACBD4
sub_80ACBD4:
	push {r4-r6,lr}
	ldr r0, _080ACC0C
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080ACBE4:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080ACBF2
	adds r0, r1, 0
	bl GroundEffect_Delete
_080ACBF2:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ACBE4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC0C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80ACBD4

	thumb_func_start sub_80ACC10
sub_80ACC10:
	push {r4,lr}
	bl sub_80ACBD4
	ldr r4, _080ACC28
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC28: .4byte gUnknown_3001B8C
	thumb_func_end sub_80ACC10

	thumb_func_start GroundEffect_Select
GroundEffect_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ACC90
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ACC94
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x14]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	ble _080ACC86
	adds r4, r0, 0
_080ACC70:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundEffect_Add
	subs r4, 0x1
	adds r5, 0xC
	cmp r4, 0
	bne _080ACC70
_080ACC86:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC90: .4byte gUnknown_8118610
_080ACC94: .4byte gUnknown_811861C
	thumb_func_end GroundEffect_Select

	thumb_func_start GroundEffect_Cancel
GroundEffect_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ACD00
	movs r0, 0
	adds r2, r7, 0
	bl Log
	movs r1, 0
	ldr r0, _080ACD04
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ACCC0:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ACCE2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ACCE2
	cmp r5, 0
	blt _080ACCDC
	movs r0, 0xA
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ACCE2
_080ACCDC:
	adds r0, r1, 0
	bl GroundEffect_Delete
_080ACCE2:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ACCC0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD00: .4byte gUnknown_8118640
_080ACD04: .4byte gUnknown_3001B8C
	thumb_func_end GroundEffect_Cancel

	thumb_func_start GroundEffect_CancelBlank
GroundEffect_CancelBlank:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080ACD7C
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080ACD80
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x92
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080ACD2C:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080ACD5C
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080ACD5C
	adds r0, r6, 0
	bl GroundEffect_Delete
_080ACD5C:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0xF
	ble _080ACD2C
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD7C: .4byte gUnknown_8118658
_080ACD80: .4byte gUnknown_3001B8C
	thumb_func_end GroundEffect_CancelBlank

	thumb_func_start sub_80ACD84
sub_80ACD84:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080ACDA8
	ldr r1, [r0]
	movs r6, 0xE2
	lsls r6, 1
	movs r2, 0x80
	lsls r2, 9
	adds r5, r2, 0
_080ACD9A:
	movs r7, 0x6
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080ACDAC
	adds r0, r3, 0
	b _080ACDBC
	.align 2, 0
_080ACDA8: .4byte gUnknown_3001B8C
_080ACDAC:
	adds r0, r2, 0
	adds r2, r5
	asrs r3, r0, 16
	adds r1, r6
	cmp r3, 0xF
	ble _080ACD9A
	movs r0, 0x1
	negs r0, r0
_080ACDBC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ACD84

	thumb_func_start GroundEffect_Add
GroundEffect_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r1, 0
	lsls r0, 16
	asrs r6, r0, 16
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldrb r0, [r7]
	lsls r0, 2
	ldr r1, _080ACE08
	adds r0, r1
	mov r8, r0
	ldr r3, _080ACE0C
	cmp r6, 0
	bge _080ACE38
	movs r2, 0
	ldr r5, [r3]
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	movs r6, 0
	b _080ACE38
	.align 2, 0
_080ACE08: .4byte gUnknown_811EE38
_080ACE0C: .4byte gUnknown_3001B8C
_080ACE10:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r5, r1
	cmp r2, 0xF
	bgt _080ACE2E
	movs r4, 0x6
	ldrsh r1, [r5, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	adds r6, r2, 0
_080ACE2E:
	cmp r6, 0
	bge _080ACE38
	movs r0, 0x1
	negs r0, r0
	b _080AD062
_080ACE38:
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r1, _080ACE9C
	ldrb r3, [r7]
	mov r2, r8
	movs r4, 0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	movs r0, 0
	adds r2, r6, 0
	bl Log
	movs r2, 0
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE72
	movs r2, 0x1
_080ACE72:
	str r2, [sp, 0xC]
	strh r6, [r5, 0x4]
	ldrb r0, [r7]
	strh r0, [r5, 0x6]
	mov r4, r10
	strh r4, [r5, 0x8]
	mov r0, r9
	strb r0, [r5, 0xA]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _080ACEEC
	lsls r0, 2
	ldr r1, _080ACEA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ACE9C: .4byte gUnknown_8118674
_080ACEA0: .4byte _080ACEA4
	.align 2, 0
_080ACEA4:
	.4byte _080ACEB8
	.4byte _080ACEEC
	.4byte _080ACEC4
	.4byte _080ACED0
	.4byte _080ACEDC
_080ACEB8:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x81
	lsls r0, 22
	b _080ACEF4
_080ACEC4:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0x83
	lsls r0, 18
	b _080ACEF4
_080ACED0:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x88
	lsls r0, 22
	b _080ACEF4
_080ACEDC:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080ACEE8
	b _080ACEF4
	.align 2, 0
_080ACEE8: .4byte 0x22020000
_080ACEEC:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ACF08
_080ACEF4:
	str r0, [r1]
	mov r4, r8
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080ACF0C
	ldrb r0, [r7, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r7, 0x3]
	b _080ACF16
	.align 2, 0
_080ACF08: .4byte 0x220c0000
_080ACF0C:
	mov r1, r8
	ldrb r0, [r1, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r1, 0x3]
_080ACF16:
	lsls r0, 11
	str r0, [r5, 0x10]
	ldr r0, [r5, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x14]
	ldr r0, [r5, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x18]
	ldrb r0, [r7, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, r7, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF5A
	ldrb r0, [r7, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF5A
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080ACF5A:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF7C
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF7C
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080ACF7C:
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _080ACFD2
	ldrb r1, [r5, 0x1C]
	movs r4, 0x90
	lsls r4, 1
	adds r0, r5, r4
	movs r3, 0
	strb r1, [r0]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x96
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	adds r4, 0x8
	adds r2, r5, r4
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r5, r2
	adds r4, 0x10
	adds r0, r5, r4
	str r3, [r0]
	str r3, [r1]
_080ACFD2:
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080AD01A
	movs r2, 0x9F
	lsls r2, 1
	adds r1, r5, r2
	movs r2, 0
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	movs r3, 0x6
	ldrsh r2, [r5, r3]
	subs r4, 0x24
	adds r1, r5, r4
	ldr r3, [r1]
	adds r1, r6, 0
	bl sub_80A7688
_080AD01A:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AD074
	mov r0, r9
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl sub_809D600
	ldr r2, [r7, 0x8]
	cmp r2, 0
	bne _080AD04C
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bne _080AD048
	ldr r0, _080AD078
	movs r1, 0xB0
	lsls r1, 2
	adds r0, r1
	ldr r2, [r0]
_080AD048:
	cmp r2, 0
	beq _080AD060
_080AD04C:
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r3, _080AD07C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
_080AD060:
	adds r0, r6, 0
_080AD062:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD074: .4byte gUnknown_8118544
_080AD078: .4byte gUnknown_812F1F8
_080AD07C: .4byte gUnknown_81186CC
	thumb_func_end GroundEffect_Add

	thumb_func_start GroundEffect_Delete
GroundEffect_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080AD0BC
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD0C0
	movs r0, 0
	bl Log
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A7714
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080AD0C4
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD0BC: .4byte gUnknown_3001B8C
_080AD0C0: .4byte gUnknown_81186D8
_080AD0C4: .4byte 0x0000ffff
	thumb_func_end GroundEffect_Delete

	thumb_func_start sub_80AD0C8
sub_80AD0C8:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD108
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD102
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r2, r3
	bl sub_80A6688
_080AD102:
	pop {r0}
	bx r0
	.align 2, 0
_080AD108: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD0C8

	thumb_func_start sub_80AD10C
sub_80AD10C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD150
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD14A
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, _080AD154
	eors r0, r4
	ldr r1, [r2]
	ands r1, r0
	str r1, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	bl sub_80A6688
_080AD14A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD150: .4byte gUnknown_3001B8C
_080AD154: .4byte 0x337fffff
	thumb_func_end sub_80AD10C

	thumb_func_start sub_80AD158
sub_80AD158:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD180
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD184
	movs r0, 0
	b _080AD188
	.align 2, 0
_080AD180: .4byte gUnknown_3001B8C
_080AD184:
	adds r0, r2, 0
	adds r0, 0x38
_080AD188:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD158

	thumb_func_start sub_80AD18C
sub_80AD18C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080AD1B8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD1BC
	movs r0, 0
	b _080AD1CC
	.align 2, 0
_080AD1B8: .4byte gUnknown_3001B8C
_080AD1BC:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080AD1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD18C

	thumb_func_start GroundEffect_ExecuteScript
GroundEffect_ExecuteScript:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	asrs r3, 16
	ldr r1, _080AD20C
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD210
	movs r0, 0
	adds r2, r3, 0
	bl Log
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD214
	movs r0, 0
	b _080AD22C
	.align 2, 0
_080AD20C: .4byte gUnknown_3001B8C
_080AD210: .4byte gUnknown_81186F4
_080AD214:
	adds r0, r4, 0
	adds r0, 0x38
	ldr r3, _080AD234
	adds r1, r5, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD22C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AD234: .4byte gUnknown_811872C
	thumb_func_end GroundEffect_ExecuteScript

	thumb_func_start sub_80AD238
sub_80AD238:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080AD28C
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080AD252:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080AD26A
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD26A:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD252
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD28C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD238

	thumb_func_start sub_80AD290
sub_80AD290:
	push {r4-r7,lr}
	ldr r0, _080AD2D4
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080AD2A0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080AD2B6
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD2B6:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD2A0
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD2D4: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD290

	thumb_func_start sub_80AD2D8
sub_80AD2D8:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD2F4
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD2F4: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD2D8

	thumb_func_start sub_80AD2F8
sub_80AD2F8:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD31C
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD31C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD2F8

	thumb_func_start sub_80AD320
sub_80AD320:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD34C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD350
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080AD358
	.align 2, 0
_080AD34C: .4byte gUnknown_3001B8C
_080AD350:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080AD358:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD320

	thumb_func_start sub_80AD360
sub_80AD360:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD38C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD390
	movs r0, 0
	str r0, [r3]
	b _080AD3AA
	.align 2, 0
_080AD38C: .4byte gUnknown_3001B8C
_080AD390:
	movs r1, 0x92
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080AD3AA:
	str r0, [r3, 0x4]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD360

	thumb_func_start sub_80AD3B4
sub_80AD3B4:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD3DC
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80AD3E0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD3DC: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD3B4

	thumb_func_start sub_80AD3E0
sub_80AD3E0:
	push {r4-r7,lr}
	mov r12, r0
	ldr r3, [r1]
	ldr r2, [r0, 0x14]
	subs r6, r3, r2
	ldr r1, [r1, 0x4]
	ldr r0, [r0, 0x18]
	subs r7, r1, r0
	adds r4, r3, r2
	adds r5, r1, r0
	mov r1, r12
	ldr r0, [r1, 0x28]
	cmp r6, r0
	blt _080AD40E
	ldr r0, [r1, 0x30]
	cmp r4, r0
	bge _080AD40E
	ldr r0, [r1, 0x2C]
	cmp r7, r0
	blt _080AD40E
	ldr r0, [r1, 0x34]
	cmp r5, r0
	blt _080AD412
_080AD40E:
	movs r0, 0x1
	b _080AD428
_080AD412:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r6, [r0]
	str r7, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	str r5, [r0, 0x4]
	movs r0, 0
_080AD428:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD3E0

	thumb_func_start sub_80AD430
sub_80AD430:
	push {r4-r6,lr}
	mov r12, r0
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r2, [r1]
	adds r5, r0, r2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r6, r0, r1
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, 0x98
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r4, r0, r1
	mov r0, r12
	ldr r1, [r0, 0x28]
	cmp r5, r1
	bge _080AD470
	adds r5, r1, 0
	ldr r0, [r0, 0xC]
	adds r3, r1, r0
	b _080AD47E
_080AD470:
	mov r2, r12
	ldr r1, [r2, 0x30]
	cmp r3, r1
	blt _080AD47E
	ldr r0, [r2, 0xC]
	subs r5, r1, r0
	adds r3, r1, 0
_080AD47E:
	mov r0, r12
	ldr r1, [r0, 0x2C]
	cmp r6, r1
	bge _080AD48E
	adds r6, r1, 0
	ldr r0, [r0, 0x10]
	adds r4, r1, r0
	b _080AD49C
_080AD48E:
	mov r2, r12
	ldr r1, [r2, 0x34]
	cmp r4, r1
	blt _080AD49C
	ldr r0, [r2, 0x10]
	subs r6, r1, r0
	adds r4, r1, 0
_080AD49C:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	str r6, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	str r4, [r0, 0x4]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD430

	thumb_func_start sub_80AD4B8
sub_80AD4B8:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AD4B8

	thumb_func_start sub_80AD4C0
sub_80AD4C0:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AD4C0

	thumb_func_start sub_80AD4CC
sub_80AD4CC:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AD50C
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AD572
_080AD50C:
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AD56E
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD56E:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AD572:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD4CC

	thumb_func_start sub_80AD578
sub_80AD578:
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
	thumb_func_end sub_80AD578

	thumb_func_start sub_80AD590
sub_80AD590:
	adds r3, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AD590

	thumb_func_start sub_80AD5B0
sub_80AD5B0:
	push {lr}
	bl sub_80AD3E0
	pop {r1}
	bx r1
	thumb_func_end sub_80AD5B0

	thumb_func_start sub_80AD5BC
sub_80AD5BC:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD5BC

	thumb_func_start sub_80AD5DC
sub_80AD5DC:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AD5DC

	thumb_func_start sub_80AD5E8
sub_80AD5E8:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AD5E8

	thumb_func_start sub_80AD5F4
sub_80AD5F4:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD60C
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AD60C:
	pop {r0}
	bx r0
	thumb_func_end sub_80AD5F4

	thumb_func_start sub_80AD610
sub_80AD610:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AD630
	ldr r1, _080AD62C
	lsls r0, 1
	adds r0, r1
	b _080AD636
	.align 2, 0
_080AD62C: .4byte gUnknown_81185F2
_080AD630:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AD636:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AD654
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AD664
_080AD654:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AD668
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AD664:
	movs r0, 0x1
	strb r0, [r1]
_080AD668:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD610

	thumb_func_start sub_80AD670
sub_80AD670:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AD682
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AD682:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AD670

	thumb_func_start sub_80AD690
sub_80AD690:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD6AE
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AD6B0
_080AD6AE:
	movs r0, 0x1
_080AD6B0:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD690

	thumb_func_start sub_80AD6B4
sub_80AD6B4:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AD6D6
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080AD6D8
_080AD6D6:
	movs r0, 0x1
_080AD6D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD6B4

	thumb_func_start sub_80AD6DC
sub_80AD6DC:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80AD6DC

	thumb_func_start sub_80AD6E8
sub_80AD6E8:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD0C8
	pop {r0}
	bx r0
	thumb_func_end sub_80AD6E8

	thumb_func_start sub_80AD6F8
sub_80AD6F8:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD10C
	pop {r0}
	bx r0
	thumb_func_end sub_80AD6F8

	thumb_func_start sub_80AD708
sub_80AD708:
	push {lr}
	bl sub_80AD430
	pop {r1}
	bx r1
	thumb_func_end sub_80AD708

	thumb_func_start GroundEffect_Action
GroundEffect_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080AD754
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080AD72C:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080AD78A
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080AD758
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080AD75C
	cmp r0, 0x4
	bne _080AD768
	adds r0, r7, 0
	bl GroundEffect_Delete
	b _080AD78A
	.align 2, 0
_080AD754: .4byte gUnknown_3001B8C
_080AD758: .4byte gUnknown_811874C
_080AD75C:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080AD7A8
	bl sub_809D8C0
_080AD768:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080AD78A
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080AD78A:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080AD72C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD7A8: .4byte gUnknown_8118758
	thumb_func_end GroundEffect_Action

	thumb_func_start sub_80AD7AC
sub_80AD7AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080AD864
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080AD7CA:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080AD83C
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080AD818
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080AD818:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080AD832
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080AD832:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7720
_080AD83C:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080AD7CA
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD864: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD7AC

	thumb_func_start sub_80AD868
sub_80AD868:
	ldr r1, _080AD870
	movs r0, 0
	str r0, [r1]
	bx lr
	.align 2, 0
_080AD870: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD868

	thumb_func_start sub_80AD874
sub_80AD874:
	ldr r1, _080AD87C
	movs r0, 0
	str r0, [r1]
	bx lr
	.align 2, 0
_080AD87C: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD874

	thumb_func_start GroundLink_Select
GroundLink_Select:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r1, _080AD898
	bl sub_80A77D0
	ldr r1, _080AD89C
	ldr r0, [r0, 0x8]
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080AD898: .4byte gUnknown_8118798
_080AD89C: .4byte gUnknown_203B4B8
	thumb_func_end GroundLink_Select

	thumb_func_start sub_80AD8A0
sub_80AD8A0:
	lsls r0, 16
	ldr r1, _080AD8B0
	asrs r0, 13
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_080AD8B0: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD8A0

	thumb_func_start sub_80AD8B4
sub_80AD8B4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	ldr r1, _080AD910
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD8E4
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD8E4
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD8E4:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD906
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD906
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD906:
	ldrb r0, [r2, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD910: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD8B4

	thumb_func_start sub_80AD914
sub_80AD914:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 16
	ldr r1, _080AD98C
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r4]
	str r1, [r4, 0x4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD94E
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD94E
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD94E:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD970
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD970
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD970:
	ldrb r1, [r2, 0x4]
	lsls r1, 11
	ldr r0, [r4]
	adds r0, r1
	str r0, [r5]
	ldrb r1, [r2, 0x5]
	lsls r1, 11
	ldr r0, [r4, 0x4]
	adds r0, r1
	str r0, [r5, 0x4]
	ldrb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AD98C: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD914

	thumb_func_start sub_80AD990
sub_80AD990:
	push {r4,lr}
	ldr r4, _080AD9C8
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080AD9CC
	adds r4, r0, 0
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080AD9AC:
	ldrh r0, [r1, 0x2]
	orrs r0, r4
	strh r0, [r1, 0x2]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, 0x20
	cmp r0, 0x1F
	ble _080AD9AC
	bl sub_80AD9D0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9C8: .4byte gUnknown_3001B90
_080AD9CC: .4byte 0x0000ffff
	thumb_func_end sub_80AD990

	thumb_func_start sub_80AD9D0
sub_80AD9D0:
	push {r4-r6,lr}
	ldr r0, _080ADA04
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080AD9E0:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080AD9EE
	adds r0, r1, 0
	bl GroundEvent_Delete
_080AD9EE:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	adds r4, 0x20
	cmp r1, 0x1F
	ble _080AD9E0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA04: .4byte gUnknown_3001B90
	thumb_func_end sub_80AD9D0

	thumb_func_start sub_80ADA08
sub_80ADA08:
	push {r4,lr}
	bl sub_80AD9D0
	ldr r4, _080ADA20
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA20: .4byte gUnknown_3001B90
	thumb_func_end sub_80ADA08

	thumb_func_start GroundEvent_Select
GroundEvent_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ADA88
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ADA8C
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x1C]
	ldr r0, [r0, 0x18]
	cmp r0, 0
	ble _080ADA7E
	adds r4, r0, 0
_080ADA68:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundEvent_Add
	subs r4, 0x1
	adds r5, 0xC
	cmp r4, 0
	bne _080ADA68
_080ADA7E:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA88: .4byte gUnknown_81187DC
_080ADA8C: .4byte gUnknown_81187E8
	thumb_func_end GroundEvent_Select

	thumb_func_start GroundEvent_Cancel
GroundEvent_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ADAF8
	movs r0, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl Log
	movs r1, 0
	ldr r0, _080ADAFC
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ADABA:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ADADC
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ADADC
	cmp r5, 0
	blt _080ADAD6
	movs r0, 0x6
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ADADC
_080ADAD6:
	adds r0, r1, 0
	bl GroundEvent_Delete
_080ADADC:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	adds r4, 0x20
	cmp r1, 0x1F
	ble _080ADABA
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADAF8: .4byte gUnknown_811880C
_080ADAFC: .4byte gUnknown_3001B90
	thumb_func_end GroundEvent_Cancel

	thumb_func_start GroundEvent_Add
GroundEvent_Add:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	lsls r2, 16
	asrs r6, r2, 16
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldr r5, [r1, 0x8]
	cmp r7, 0
	bge _080ADB60
	ldr r0, _080ADB38
	ldr r4, [r0]
	movs r2, 0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADB3C
	movs r7, 0
	b _080ADB68
	.align 2, 0
_080ADB38: .4byte gUnknown_3001B90
_080ADB3C:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	adds r4, 0x20
	cmp r2, 0x1F
	bgt _080ADB56
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADB3C
	adds r7, r2, 0
_080ADB56:
	cmp r7, 0
	bge _080ADB68
	movs r0, 0x1
	negs r0, r0
	b _080ADC24
_080ADB60:
	ldr r0, _080ADBA0
	lsls r1, r7, 5
	ldr r0, [r0]
	adds r4, r0, r1
_080ADB68:
	ldr r1, _080ADBA4
	movs r0, 0
	ldrsh r3, [r5, r0]
	str r6, [sp]
	mov r2, r9
	str r2, [sp, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x8]
	movs r0, 0
	adds r2, r7, 0
	bl Log
	strh r7, [r4]
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
	strh r6, [r4, 0x4]
	mov r3, r9
	strb r3, [r4, 0x6]
	movs r6, 0x2
	ldrsh r0, [r5, r6]
	cmp r0, 0x1
	blt _080ADBA8
	cmp r0, 0x2
	bgt _080ADBA8
	movs r0, 0x60
	b _080ADBAA
	.align 2, 0
_080ADBA0: .4byte gUnknown_3001B90
_080ADBA4: .4byte gUnknown_8118828
_080ADBA8:
	movs r0, 0x20
_080ADBAA:
	str r0, [r4, 0x8]
	mov r3, r8
	ldrb r0, [r3]
	lsls r1, r0, 11
	ldrb r0, [r3, 0x1]
	lsls r2, r0, 11
	mov r5, r8
	adds r5, 0x4
	add r6, sp, 0xC
	mov r12, r6
	ldrb r6, [r5, 0x2]
	movs r0, 0x4
	ands r0, r6
	cmp r0, 0
	bne _080ADBDE
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [sp, 0xC]
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _080ADBDE
	movs r6, 0x80
	lsls r6, 3
	adds r0, r3, r6
	str r0, [sp, 0xC]
_080ADBDE:
	ldrb r6, [r5, 0x3]
	movs r0, 0x4
	ands r0, r6
	cmp r0, 0
	bne _080ADC02
	ldrb r0, [r5, 0x1]
	lsls r3, r0, 11
	mov r0, r12
	str r3, [r0, 0x4]
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _080ADC02
	movs r5, 0x80
	lsls r5, 3
	adds r0, r3, r5
	mov r6, r12
	str r0, [r6, 0x4]
_080ADC02:
	ldr r0, [sp, 0xC]
	str r0, [r4, 0xC]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [r4, 0x14]
	ldr r0, [sp, 0x10]
	str r0, [r4, 0x10]
	ldr r0, [sp, 0x10]
	adds r0, r2
	str r0, [r4, 0x18]
	mov r1, r8
	ldr r0, [r1, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [r4, 0x1C]
	bl sub_80A7A78
	adds r0, r7, 0
_080ADC24:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundEvent_Add

	thumb_func_start GroundEvent_Delete
GroundEvent_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r0, _080ADC58
	lsls r1, r2, 5
	ldr r4, [r0]
	adds r4, r1
	ldr r1, _080ADC5C
	movs r0, 0
	bl Log
	ldr r0, _080ADC60
	strh r0, [r4, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADC58: .4byte gUnknown_3001B90
_080ADC5C: .4byte gUnknown_811886C
_080ADC60: .4byte 0x0000ffff
	thumb_func_end GroundEvent_Delete

	thumb_func_start sub_80ADC64
sub_80ADC64:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	ldr r1, _080ADC84
	asrs r0, 11
	ldr r1, [r1]
	adds r2, r1, r0
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADC88
	movs r0, 0
	b _080ADC9A
	.align 2, 0
_080ADC84: .4byte gUnknown_3001B90
_080ADC88:
	ldr r0, [r2, 0x1C]
	str r0, [r3]
	movs r0, 0x2
	strh r0, [r3, 0x4]
	ldrh r0, [r2, 0x4]
	strh r0, [r3, 0x6]
	ldrb r0, [r2, 0x6]
	strb r0, [r3, 0x8]
	movs r0, 0x1
_080ADC9A:
	pop {r1}
	bx r1
	thumb_func_end sub_80ADC64

	thumb_func_start sub_80ADCA0
sub_80ADCA0:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _080ADCEC
	ldr r3, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r6, 0x80
	lsls r6, 9
_080ADCB6:
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r12
	beq _080ADCF0
	ldr r0, [r3, 0x8]
	ands r0, r7
	cmp r0, 0
	beq _080ADCF0
	ldr r1, [r3, 0xC]
	ldr r0, [r2]
	cmp r1, r0
	bge _080ADCF0
	ldr r1, [r3, 0x14]
	ldr r0, [r4]
	cmp r1, r0
	ble _080ADCF0
	ldr r1, [r3, 0x10]
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _080ADCF0
	ldr r1, [r3, 0x18]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080ADCF0
	adds r0, r5, 0
	b _080ADD04
	.align 2, 0
_080ADCEC: .4byte gUnknown_3001B90
_080ADCF0:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r5, r0, 16
	adds r3, 0x20
	cmp r5, 0x1F
	ble _080ADCB6
	movs r0, 0x1
	negs r0, r0
_080ADD04:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADCA0

	thumb_func_start sub_80ADD0C
sub_80ADD0C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	ldr r0, _080ADD74
	ldr r4, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	movs r1, 0x80
	lsls r1, 9
	mov r12, r1
_080ADD2C:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r9
	beq _080ADD78
	ldr r0, [r4, 0x8]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _080ADD78
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x14]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r2, r0, 1
	ldr r0, [r4, 0x10]
	ldr r1, [r4, 0x18]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r3, r0, 1
	ldr r0, [r5]
	cmp r2, r0
	bge _080ADD78
	ldr r0, [r6]
	cmp r2, r0
	ble _080ADD78
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _080ADD78
	ldr r0, [r6, 0x4]
	cmp r3, r0
	ble _080ADD78
	adds r0, r7, 0
	b _080ADD8C
	.align 2, 0
_080ADD74: .4byte gUnknown_3001B90
_080ADD78:
	mov r0, r12
	movs r1, 0x80
	lsls r1, 9
	add r12, r1
	asrs r7, r0, 16
	adds r4, 0x20
	cmp r7, 0x1F
	ble _080ADD2C
	movs r0, 0x1
	negs r0, r0
_080ADD8C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADD0C

	thumb_func_start nullsub_124
nullsub_124:
	bx lr
	thumb_func_end nullsub_124

	thumb_func_start sub_80ADD9C
sub_80ADD9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	str r2, [sp, 0x28]
	str r3, [sp, 0x2C]
	ldr r5, [sp, 0x54]
	ldr r0, [sp, 0x5C]
	mov r9, r0
	movs r0, 0x93
	lsls r0, 4
	movs r1, 0x7
	bl MemoryAlloc
	mov r10, r0
	ldr r0, _080ADEB4
	ldr r7, _080ADEB8
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	add r4, sp, 0x1C
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80901D8
	ldrb r5, [r4]
	ldrb r4, [r4, 0x1]
	cmp r5, 0x3E
	bls _080ADDE2
	movs r5, 0x3E
_080ADDE2:
	cmp r4, 0
	bgt _080ADDE8
	movs r4, 0x1
_080ADDE8:
	adds r0, r5, 0
	bl sub_8090298
	cmp r4, r0
	blt _080ADDFA
	adds r0, r5, 0
	bl sub_8090298
	subs r4, r0, 0x1
_080ADDFA:
	ldr r2, [r6, 0x4]
	ldr r1, [r2]
	lsls r0, r5, 2
	adds r0, r1
	lsls r1, r4, 4
	ldr r0, [r0]
	adds r0, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	mov r8, r0
	adds r0, r6, 0
	bl CloseFile
	ldr r1, _080ADEBC
	ldr r0, _080ADEC0
	add r0, r8
	ldrb r5, [r0]
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	ldr r0, [sp, 0x28]
	movs r1, 0
	adds r2, r4, 0
	bl sub_800AE28
	adds r0, r4, 0
	bl CloseFile
	ldr r1, _080ADEC4
	add r0, sp, 0x10
	mov r2, r8
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFile
	ldr r1, [sp, 0x20]
	str r0, [r1]
	ldr r1, _080ADEC8
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	ldr r1, _080ADECC
	ldr r0, [sp, 0x2C]
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
	mov r2, r8
	cmp r2, 0x3F
	bgt _080ADED4
	ldr r1, _080ADED0
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	mov r0, r10
	movs r1, 0x93
	lsls r1, 4
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
	b _080ADEFC
	.align 2, 0
_080ADEB4: .4byte gUnknown_8118890
_080ADEB8: .4byte gUnknown_83B0000
_080ADEBC: .4byte gUnknown_811889C
_080ADEC0: .4byte gUnknown_8108EC0
_080ADEC4: .4byte gUnknown_81188A8
_080ADEC8: .4byte gUnknown_81188B4
_080ADECC: .4byte 0x00001194
_080ADED0: .4byte gUnknown_81188C0
_080ADED4:
	ldr r1, _080ADF80
	add r0, sp, 0x10
	mov r2, r8
	ldr r3, [sp, 0x58]
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	movs r1, 0x90
	lsls r1, 2
	mov r0, r10
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
_080ADEFC:
	movs r5, 0
	ldr r3, [sp, 0x60]
	cmp r5, r3
	bge _080ADF52
_080ADF04:
	mov r0, r8
	bl sub_8097F40
	lsls r0, 24
	movs r7, 0
	cmp r0, 0
	beq _080ADF14
	movs r7, 0x3
_080ADF14:
	movs r4, 0
	adds r6, r5, 0x1
	cmp r4, r9
	bge _080ADF4A
_080ADF1C:
	ldr r0, [sp, 0x64]
	str r0, [sp]
	str r7, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	mov r2, r8
	str r2, [sp, 0xC]
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, r9
	ldr r3, [sp, 0x60]
	bl sub_80ADFB8
	mov r1, r9
	muls r1, r5
	adds r1, r4
	lsls r1, 1
	ldr r3, [sp, 0x50]
	adds r1, r3
	strh r0, [r1]
	adds r4, 0x1
	cmp r4, r9
	blt _080ADF1C
_080ADF4A:
	adds r5, r6, 0
	ldr r0, [sp, 0x60]
	cmp r5, r0
	blt _080ADF04
_080ADF52:
	ldr r1, _080ADF84
	add r0, sp, 0x10
	mov r2, r8
	bl sprintf
	ldr r1, _080ADF88
	add r0, sp, 0x10
	bl OpenFile
	ldr r1, [sp, 0x24]
	str r0, [r1]
	mov r0, r10
	bl MemoryFree
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADF80: .4byte gUnknown_81188CC
_080ADF84: .4byte gUnknown_81188DC
_080ADF88: .4byte gUnknown_83B0000
	thumb_func_end sub_80ADD9C

	thumb_func_start sub_80ADF8C
sub_80ADF8C:
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [sp, 0xC]
	cmp r4, 0
	blt _080ADFB0
	cmp r1, 0
	blt _080ADFB0
	cmp r4, r2
	bge _080ADFB0
	cmp r1, r3
	bge _080ADFB0
	adds r0, r1, 0
	muls r0, r2
	adds r0, r4, r0
	lsls r0, 1
	ldr r1, [sp, 0x8]
	adds r0, r1
	ldrh r0, [r0]
_080ADFB0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADF8C

	thumb_func_start sub_80ADFB8
sub_80ADFB8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r4, [sp, 0x5C]
	movs r7, 0
	ldr r0, [sp, 0x50]
	str r0, [sp]
	ldr r1, [sp, 0x54]
	str r1, [sp, 0x4]
	mov r0, r9
	mov r1, r10
	bl sub_80ADF8C
	str r0, [sp, 0x28]
	cmp r4, 0x3F
	ble _080AE000
	mov r0, r9
	cmp r0, 0x17
	bgt _080ADFFC
	mov r1, r10
	cmp r1, 0x17
	bgt _080ADFFC
	lsls r0, r1, 1
	add r0, r10
	lsls r0, 3
	add r0, r9
	b _080AE24E
_080ADFFC:
	ldr r0, [sp, 0x54]
	b _080AE254
_080AE000:
	mov r0, r10
	adds r0, 0x1
	str r0, [sp, 0x2C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x8]
	mov r4, r9
	adds r4, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0xC]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x10]
	mov r5, r10
	subs r5, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x14]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x18]
	subs r4, 0x2
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x1C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	adds r1, r0, 0
	str r1, [sp, 0x24]
	ldr r0, [sp, 0x28]
	cmp r0, 0x1
	bne _080AE12A
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE0D2
	movs r7, 0xFE
_080AE0D2:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE0DE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE0DE:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE0EA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE0EA:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE0F6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE0F6:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE102
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE102:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE10E
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE10E:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE11A
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE11A:
	cmp r1, 0
	bne _080AE124
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE124:
	movs r0, 0x80
	lsls r0, 2
	b _080AE248
_080AE12A:
	ldr r0, [sp, 0x28]
	cmp r0, 0x2
	bne _080AE192
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x2
	beq _080AE13A
	movs r7, 0xFE
_080AE13A:
	ldr r0, [sp, 0xC]
	cmp r0, 0x2
	beq _080AE146
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE146:
	ldr r0, [sp, 0x10]
	cmp r0, 0x2
	beq _080AE152
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE152:
	ldr r0, [sp, 0x14]
	cmp r0, 0x2
	beq _080AE15E
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE15E:
	ldr r0, [sp, 0x18]
	cmp r0, 0x2
	beq _080AE16A
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE16A:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x2
	beq _080AE176
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE176:
	ldr r0, [sp, 0x20]
	cmp r0, 0x2
	beq _080AE182
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE182:
	cmp r1, 0x2
	beq _080AE18C
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE18C:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE192:
	ldr r1, [sp, 0x28]
	cmp r1, 0x3
	bne _080AE1FC
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x3
	beq _080AE1A2
	movs r7, 0xFE
_080AE1A2:
	ldr r0, [sp, 0xC]
	cmp r0, 0x3
	beq _080AE1AE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE1AE:
	ldr r0, [sp, 0x10]
	cmp r0, 0x3
	beq _080AE1BA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE1BA:
	ldr r0, [sp, 0x14]
	cmp r0, 0x3
	beq _080AE1C6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE1C6:
	ldr r0, [sp, 0x18]
	cmp r0, 0x3
	beq _080AE1D2
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE1D2:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x3
	beq _080AE1DE
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE1DE:
	ldr r0, [sp, 0x20]
	cmp r0, 0x3
	beq _080AE1EA
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE1EA:
	ldr r0, [sp, 0x24]
	cmp r0, 0x3
	beq _080AE1F6
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE1F6:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE1FC:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE204
	movs r7, 0x1
_080AE204:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE20E
	movs r0, 0x2
	orrs r7, r0
_080AE20E:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE218
	movs r0, 0x4
	orrs r7, r0
_080AE218:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE222
	movs r0, 0x8
	orrs r7, r0
_080AE222:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE22C
	movs r0, 0x10
	orrs r7, r0
_080AE22C:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE236
	movs r0, 0x20
	orrs r7, r0
_080AE236:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE240
	movs r0, 0x40
	orrs r7, r0
_080AE240:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _080AE24A
	movs r0, 0x80
_080AE248:
	orrs r7, r0
_080AE24A:
	lsls r0, r7, 1
	adds r0, r7
_080AE24E:
	ldr r1, [sp, 0x58]
	adds r0, r1, r0
	ldrb r0, [r0]
_080AE254:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADFB8

        .align 2,0
