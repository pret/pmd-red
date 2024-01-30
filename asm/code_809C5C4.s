	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_809CBBC
sub_809CBBC:
	push {r4-r7,lr}
	sub sp, 0x54
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	ldrb r1, [r4]
	cmp r1, 0x69
	bne _0809CC20
	ldr r1, _0809CC0C
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r0, _0809CC10
	ldr r0, [r0]
	movs r3, 0xD2
	lsls r3, 4
	adds r0, r3
	ldr r3, [r0]
	mov r0, sp
	bl sprintfStatic
	ldr r0, _0809CC14
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r2, r0, r1
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, _0809CC18
	cmp r1, r0
	ble _0809CC1C
	cmp r6, 0
	beq _0809CC4E
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r6, 0
	b _0809CC4A
	.align 2, 0
_0809CC0C: .4byte gUnknown_81163E4
_0809CC10: .4byte gItemParametersData
_0809CC14: .4byte gTeamInventoryRef
_0809CC18: .4byte 0x0001869f
_0809CC1C:
	str r1, [r2]
	b _0809CC5E
_0809CC20:
	ldrb r0, [r4, 0x2]
	lsls r1, 16
	lsls r0, 8
	orrs r0, r1
	str r0, [sp, 0x50]
	add r4, sp, 0x50
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	ble _0809CC52
	cmp r5, 0
	beq _0809CC4E
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r5, 0
_0809CC4A:
	bl sub_809AE90
_0809CC4E:
	movs r0, 0
	b _0809CC82
_0809CC52:
	ldrb r0, [r4, 0x2]
	movs r1, 0
	bl sub_809124C
	bl FillInventoryGaps
_0809CC5E:
	cmp r7, 0
	beq _0809CC80
	ldr r0, _0809CC8C
	mov r1, sp
	bl strcpy
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r7, 0
	bl sub_809AE90
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCB
	bl xxx_call_play_fanfare_se
_0809CC80:
	movs r0, 0x1
_0809CC82:
	add sp, 0x54
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809CC8C: .4byte gUnknown_202DE58
	thumb_func_end sub_809CBBC

	thumb_func_start sub_809CC90
sub_809CC90:
	push {lr}
	lsls r0, 2
	ldr r1, _0809CCBC
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x69
	bne _0809CCC8
	ldr r0, _0809CCC0
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	ldr r0, [r0]
	adds r0, r1
	ldr r1, _0809CCC4
	cmp r0, r1
	ble _0809CCD4
	movs r0, 0x2
	b _0809CCD6
	.align 2, 0
_0809CCBC: .4byte gUnknown_81163BC
_0809CCC0: .4byte gTeamInventoryRef
_0809CCC4: .4byte 0x0001869f
_0809CCC8:
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	ble _0809CCD4
	movs r0, 0x2
	b _0809CCD6
_0809CCD4:
	movs r0, 0x1
_0809CCD6:
	pop {r1}
	bx r1
	thumb_func_end sub_809CC90

	thumb_func_start sub_809CCDC
sub_809CCDC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r1, r6, 2
	ldr r0, _0809CD20
	adds r5, r1, r0
	ldr r0, _0809CD24
	ldr r1, [r0]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x4]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r0, 0x2
	cmp r4, 0x63
	bgt _0809CD04
	movs r0, 0
	cmp r4, 0x1
	ble _0809CD04
	movs r0, 0x1
_0809CD04:
	ldr r1, _0809CD28
	ldr r2, _0809CD2C
	ldr r3, _0809CD30
	lsls r0, 2
	adds r0, r3
	ldr r3, [r0]
	adds r0, r5, 0
	bl sub_809CBBC
	lsls r0, 24
	cmp r0, 0
	bne _0809CD34
	movs r0, 0x2
	b _0809CD3E
	.align 2, 0
_0809CD20: .4byte gUnknown_81163BC
_0809CD24: .4byte gUnknown_20399E0
_0809CD28: .4byte gUnknown_81163F0
_0809CD2C: .4byte gUnknown_811642C
_0809CD30: .4byte gUnknown_203B4A0
_0809CD34:
	ldr r0, _0809CD44
	ldr r0, [r0]
	str r6, [r0, 0x4]
	str r4, [r0, 0x8]
	movs r0, 0x1
_0809CD3E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809CD44: .4byte gUnknown_20399E0
	thumb_func_end sub_809CCDC

	thumb_func_start sub_809CD48
sub_809CD48:
	push {lr}
	bl sub_809A750
	lsls r0, 24
	cmp r0, 0
	bne _0809CD58
	movs r0, 0x3
	b _0809CD5A
_0809CD58:
	movs r0, 0
_0809CD5A:
	pop {r1}
	bx r1
	thumb_func_end sub_809CD48

	thumb_func_start nullsub_117
nullsub_117:
	bx lr
	thumb_func_end nullsub_117

	thumb_func_start nullsub_118
nullsub_118:
	bx lr
	thumb_func_end nullsub_118

	thumb_func_start sub_809CD68
sub_809CD68:
	movs r2, 0
	str r2, [r0]
	str r2, [r0, 0x4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	str r2, [r0, 0x14]
	str r2, [r0, 0x8]
	strb r2, [r0, 0x18]
	bx lr
	thumb_func_end sub_809CD68

	thumb_func_start sub_809CD7C
sub_809CD7C:
	movs r2, 0
	str r2, [r0]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	str r2, [r0, 0x14]
	str r2, [r0, 0x8]
	bx lr
	thumb_func_end sub_809CD7C

	thumb_func_start sub_809CD8C
sub_809CD8C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0x5
	bne _0809CD9E
	bl sub_809CD68
	str r4, [r5]
	b _0809CDB0
_0809CD9E:
	ldr r0, [r5, 0x4]
	cmp r0, r4
	beq _0809CDB0
	str r4, [r5, 0x4]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x10]
	movs r0, 0
	str r0, [r5, 0x14]
_0809CDB0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809CD8C

	thumb_func_start sub_809CDB8
sub_809CDB8:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _0809CDC4
	ldr r0, [r1]
_0809CDC4:
	pop {r1}
	bx r1
	thumb_func_end sub_809CDB8

	thumb_func_start sub_809CDC8
sub_809CDC8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r1, [sp, 0x24]
	movs r0, 0x1
	negs r0, r0
	str r0, [r3]
	ldr r0, [r4]
	cmp r0, 0x1
	beq _0809CDEA
	cmp r0, 0x2
	beq _0809CDFE
	b _0809CE12
_0809CDEA:
	movs r0, 0x80
	lsls r0, 6
	ands r1, r0
	cmp r1, 0
	beq _0809CE12
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x2
	b _0809CE10
_0809CDFE:
	movs r0, 0x80
	lsls r0, 6
	ands r1, r0
	cmp r1, 0
	bne _0809CE12
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x1
_0809CE10:
	str r0, [r4]
_0809CE12:
	ldr r0, [r4, 0x4]
	mov r8, r0
	cmp r0, 0
	bne _0809CE1E
	ldr r1, [r4]
	mov r8, r1
_0809CE1E:
	mov r0, r8
	subs r0, 0x1
	cmp r0, 0x6
	bls _0809CE28
	b _0809CFCC
_0809CE28:
	lsls r0, 2
	ldr r1, _0809CE34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CE34: .4byte _0809CE38
	.align 2, 0
_0809CE38:
	.4byte _0809CE54
	.4byte _0809CF74
	.4byte _0809CFCC
	.4byte _0809CFCC
	.4byte _0809CECC
	.4byte _0809CF5C
	.4byte _0809CF5C
_0809CE54:
	ldr r0, _0809CE70
	ldrh r2, [r0]
	ldrh r1, [r0, 0x2]
	movs r0, 0xF0
	ands r0, r2
	cmp r0, 0
	beq _0809CE74
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0809CEA4
	movs r0, 0
	b _0809CEA8
	.align 2, 0
_0809CE70: .4byte gRealInputs
_0809CE74:
	movs r3, 0x2
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _0809CE82
	movs r0, 0x14
	b _0809CEA8
_0809CE82:
	ldr r0, [r4, 0x10]
	cmp r0, 0x1
	ble _0809CEA4
	subs r0, 0x1
	str r0, [r4, 0x10]
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	bne _0809CEAA
	movs r0, 0x13
	str r0, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strb r0, [r7]
	movs r0, 0x5
	b _0809CFDA
_0809CEA4:
	movs r0, 0x1
	negs r0, r0
_0809CEA8:
	str r0, [r4, 0x10]
_0809CEAA:
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0809CEB6
	movs r0, 0xA
	b _0809CEC2
_0809CEB6:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _0809CEC0
	movs r0, 0x8
	b _0809CEC2
_0809CEC0:
	movs r0, 0x7
_0809CEC2:
	str r0, [r6]
	adds r0, r2, 0
	bl sub_809CFE8
	b _0809CF4E
_0809CECC:
	mov r0, sp
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	beq _0809CFCC
	ldr r0, _0809CEEC
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	bne _0809CEF0
	movs r0, 0x4
	bl sub_809C6CC
	b _0809CEF6
	.align 2, 0
_0809CEEC: .4byte gGameOptionsRef
_0809CEF0:
	movs r0, 0x3
	bl sub_809C6CC
_0809CEF6:
	bl nullsub_104
	adds r0, r4, 0
	bl sub_809CD7C
	movs r5, 0x1
	str r5, [r4]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0809CF1E
	cmp r0, 0x2
	bgt _0809CF14
	cmp r0, 0x1
	beq _0809CF2A
	b _0809CF54
_0809CF14:
	cmp r0, 0x3
	beq _0809CF2A
	cmp r0, 0x4
	beq _0809CF3C
	b _0809CF54
_0809CF1E:
	movs r0, 0x4
	str r0, [r4]
	movs r0, 0x1E
	bl sub_8098D80
	b _0809CF46
_0809CF2A:
	movs r0, 0x4
	str r0, [r4]
	str r5, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strb r0, [r7]
	movs r0, 0x4
	b _0809CFDA
_0809CF3C:
	str r0, [r4]
	movs r0, 0x45
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809CF46:
	str r5, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CF4E:
	strb r0, [r7]
	ldr r0, [r4]
	b _0809CFDA
_0809CF54:
	movs r0, 0x2
	bl sub_809D9B8
	b _0809CFCC
_0809CF5C:
	add r0, sp, 0x4
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	beq _0809CFCC
	adds r0, r4, 0
	bl sub_809CD7C
	movs r0, 0x1
	str r0, [r4]
	b _0809CFDA
_0809CF74:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	ble _0809CF86
	subs r0, 0x1
	str r0, [r4, 0x8]
	movs r0, 0x9
	str r0, [r6]
	ldrb r0, [r4, 0xC]
	b _0809CFD6
_0809CF86:
	ldr r0, _0809CFA0
	ldrh r1, [r0]
	movs r0, 0x9
	str r0, [r6]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _0809CFA4
	movs r0, 0x4
	b _0809CFB6
	.align 2, 0
_0809CFA0: .4byte gRealInputs
_0809CFA4:
	movs r0, 0x80
	ands r1, r0
	cmp r1, 0
	beq _0809CFB0
	strb r2, [r7]
	b _0809CFB8
_0809CFB0:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CFB6:
	strb r0, [r7]
_0809CFB8:
	ldrb r0, [r7]
	strb r0, [r4, 0xC]
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	cmp r0, r1
	beq _0809CFD8
	movs r0, 0x20
	str r0, [r4, 0x8]
	b _0809CFD8
_0809CFCC:
	movs r0, 0
	str r0, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CFD6:
	strb r0, [r7]
_0809CFD8:
	mov r0, r8
_0809CFDA:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809CDC8

    .align 2,0
