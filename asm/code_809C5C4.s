	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_809C770
sub_809C770:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r4, _0809C790
	ldr r1, [r4]
	ldrb r0, [r1, 0xE]
	cmp r0, 0
	beq _0809C794
	movs r0, 0
	strb r0, [r1, 0xE]
	b _0809CA10
	.align 2, 0
_0809C790: .4byte gUnknown_3001B68
_0809C794:
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	bne _0809C79E
	bl sub_809C6EC
_0809C79E:
	ldr r0, [r4]
	ldrb r5, [r0, 0x18]
	ldrb r7, [r0, 0x19]
	cmp r6, 0x26
	bls _0809C7AA
	b _0809C8C8
_0809C7AA:
	lsls r0, r6, 2
	ldr r1, _0809C7B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C7B4: .4byte _0809C7B8
	.align 2, 0
_0809C7B8:
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C854
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C86E
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
_0809C854:
	mov r0, r8
	bl sub_8002658
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0809C864
	b _0809CA10
_0809C864:
	movs r4, 0x1
	b _0809C988
_0809C868:
	movs r4, 0x1
	movs r5, 0
	b _0809C988
_0809C86E:
	mov r0, r8
	subs r0, 0xA4
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bls _0809C87C
	b _0809CA10
_0809C87C:
	lsls r0, 2
	ldr r1, _0809C888
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C888: .4byte _0809C88C
	.align 2, 0
_0809C88C:
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
_0809C8C4:
	movs r4, 0
	b _0809C988
_0809C8C8:
	adds r0, r6, 0
	subs r0, 0xC
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x16
	bhi _0809C968
	lsls r0, 2
	ldr r1, _0809C8E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C8E0: .4byte _0809C8E4
	.align 2, 0
_0809C8E4:
	.4byte _0809C968
	.4byte _0809C940
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C944
	.4byte _0809C944
	.4byte _0809C948
	.4byte _0809C948
	.4byte _0809C94C
	.4byte _0809C968
	.4byte _0809C950
	.4byte _0809C950
	.4byte _0809C954
	.4byte _0809C954
	.4byte _0809C958
	.4byte _0809C958
	.4byte _0809C95C
	.4byte _0809C95C
	.4byte _0809C960
	.4byte _0809C960
	.4byte _0809C964
_0809C940:
	movs r1, 0
	b _0809C974
_0809C944:
	movs r1, 0x7
	b _0809C974
_0809C948:
	movs r1, 0x9
	b _0809C974
_0809C94C:
	movs r1, 0xA
	b _0809C974
_0809C950:
	movs r1, 0xB
	b _0809C974
_0809C954:
	movs r1, 0xD
	b _0809C974
_0809C958:
	movs r1, 0xF
	b _0809C974
_0809C95C:
	movs r1, 0x11
	b _0809C974
_0809C960:
	movs r1, 0x13
	b _0809C974
_0809C964:
	movs r1, 0x20
	b _0809C974
_0809C968:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r1, r0, 16
_0809C974:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809CA10
	adds r0, r1, 0
	bl sub_80A2740
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0x2
_0809C988:
	ldr r0, _0809C99C
	ldr r2, [r0]
	ldr r1, [r2, 0x10]
	adds r3, r0, 0
	cmp r1, r4
	beq _0809C9A0
	movs r0, 0x2
	str r0, [r2]
	b _0809C9DE
	.align 2, 0
_0809C99C: .4byte gUnknown_3001B68
_0809C9A0:
	cmp r4, 0x1
	bne _0809C9CC
	ldrb r0, [r2, 0x18]
	cmp r5, r0
	bne _0809C9B2
	movs r1, 0x14
	ldrsh r0, [r2, r1]
	cmp r0, r8
	beq _0809C9BC
_0809C9B2:
	strb r4, [r2, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r4, [r0]
	b _0809C9E8
_0809C9BC:
	cmp r5, 0
	bne _0809C9E8
	movs r1, 0x16
	ldrsh r0, [r2, r1]
	cmp r0, r6
	beq _0809C9E8
	strb r4, [r2, 0xC]
	b _0809C9E8
_0809C9CC:
	cmp r4, 0x2
	bne _0809C9E8
	ldrb r0, [r2, 0x19]
	cmp r7, r0
	bne _0809C9DE
	movs r1, 0x16
	ldrsh r0, [r2, r1]
	cmp r0, r6
	beq _0809C9E8
_0809C9DE:
	movs r1, 0x1
	strb r1, [r2, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r1, [r0]
_0809C9E8:
	ldr r1, [r3]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0809CA10
	str r4, [r1, 0x10]
	movs r2, 0
	mov r0, r8
	strh r0, [r1, 0x14]
	strh r6, [r1, 0x16]
	strb r5, [r1, 0x18]
	ldr r0, [r3]
	strb r7, [r0, 0x19]
	ldr r1, [r3]
	ldrh r0, [r1, 0x8]
	cmp r0, 0x4
	beq _0809CA10
	strb r2, [r1, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r2, [r0]
_0809CA10:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809C770

	thumb_func_start nullsub_105
nullsub_105:
	bx lr
	thumb_func_end nullsub_105

	thumb_func_start sub_809CA20
sub_809CA20:
	push {lr}
	ldr r1, _0809CA74
	ldr r2, [r1]
	ldr r0, [r2]
	cmp r0, 0
	beq _0809CA38
	movs r0, 0
	str r0, [r2]
	movs r0, 0x1F
	str r0, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0xC]
_0809CA38:
	ldr r1, [r1]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0809CAE8
	ldrh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bne _0809CA5E
	ldr r2, [r1, 0x10]
	cmp r2, 0
	bne _0809CA5E
	movs r0, 0x2
	strh r0, [r1, 0xA]
	str r2, [r1, 0x1C]
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
_0809CA5E:
	ldr r0, _0809CA74
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r0, 0x5
	bhi _0809CADA
	lsls r0, 2
	ldr r1, _0809CA78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CA74: .4byte gUnknown_3001B68
_0809CA78: .4byte _0809CA7C
	.align 2, 0
_0809CA7C:
	.4byte _0809CAD2
	.4byte _0809CAD2
	.4byte _0809CABE
	.4byte _0809CA94
	.4byte _0809CAB0
	.4byte _0809CAC8
_0809CA94:
	bl nullsub_111
	bl nullsub_113
	bl nullsub_112
	ldr r0, _0809CAAC
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	b _0809CADA
	.align 2, 0
_0809CAAC: .4byte gUnknown_3001B68
_0809CAB0:
	bl nullsub_114
	bl nullsub_115
	bl nullsub_116
	b _0809CADA
_0809CABE:
	bl nullsub_109
	bl nullsub_110
	b _0809CADA
_0809CAC8:
	bl nullsub_107
	bl nullsub_108
	b _0809CADA
_0809CAD2:
	bl nullsub_107
	bl nullsub_108
_0809CADA:
	ldr r0, _0809CAE4
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0xC]
	b _0809CB1E
	.align 2, 0
_0809CAE4: .4byte gUnknown_3001B68
_0809CAE8:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x5
	bhi _0809CB1E
	lsls r0, 2
	ldr r1, _0809CAF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CAF8: .4byte _0809CAFC
	.align 2, 0
_0809CAFC:
	.4byte _0809CB1E
	.4byte _0809CB1E
	.4byte _0809CB1E
	.4byte _0809CB14
	.4byte _0809CB1A
	.4byte _0809CB1E
_0809CB14:
	bl nullsub_113
	b _0809CB1E
_0809CB1A:
	bl nullsub_116
_0809CB1E:
	pop {r0}
	bx r0
	thumb_func_end sub_809CA20

	thumb_func_start nullsub_106
nullsub_106:
	bx lr
	thumb_func_end nullsub_106

	thumb_func_start nullsub_107
nullsub_107:
	bx lr
	thumb_func_end nullsub_107

	thumb_func_start nullsub_108
nullsub_108:
	bx lr
	thumb_func_end nullsub_108

	thumb_func_start nullsub_109
nullsub_109:
	bx lr
	thumb_func_end nullsub_109

	thumb_func_start nullsub_110
nullsub_110:
	bx lr
	thumb_func_end nullsub_110

	thumb_func_start nullsub_111
nullsub_111:
	bx lr
	thumb_func_end nullsub_111

	thumb_func_start nullsub_112
nullsub_112:
	bx lr
	thumb_func_end nullsub_112

	thumb_func_start nullsub_113
nullsub_113:
	bx lr
	thumb_func_end nullsub_113

	thumb_func_start nullsub_114
nullsub_114:
	bx lr
	thumb_func_end nullsub_114

	thumb_func_start nullsub_115
nullsub_115:
	bx lr
	thumb_func_end nullsub_115

	thumb_func_start nullsub_116
nullsub_116:
	bx lr
	thumb_func_end nullsub_116

	thumb_func_start sub_809CB50
sub_809CB50:
	push {r4,lr}
	ldr r4, _0809CB70
	movs r0, 0xC
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x4]
	movs r1, 0
	str r1, [r0, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809CB70: .4byte gUnknown_20399E0
	thumb_func_end sub_809CB50

	thumb_func_start sub_809CB74
sub_809CB74:
	push {r4,lr}
	ldr r4, _0809CB88
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809CB88: .4byte gUnknown_20399E0
	thumb_func_end sub_809CB74

	thumb_func_start sub_809CB8C
sub_809CB8C:
	push {lr}
	movs r0, 0
	movs r1, 0x3B
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x3D
	bl sub_80015C0
	pop {r0}
	bx r0
	thumb_func_end sub_809CB8C

	thumb_func_start sub_809CBA4
sub_809CBA4:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl FindItemInInventory
	cmp r0, 0
	bge _0809CBB6
	movs r0, 0
	b _0809CBB8
_0809CBB6:
	movs r0, 0x1
_0809CBB8:
	pop {r1}
	bx r1
	thumb_func_end sub_809CBA4

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
