	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start GroundMap_GetStationScript
GroundMap_GetStationScript:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	lsls r4, 16
	asrs r4, 16
	lsls r6, 16
	asrs r6, 16
	lsls r5, 24
	asrs r5, 24
	adds r0, r4, 0
	bl sub_80A77A0
	ldr r1, _080A4BE0
	adds r0, r4, 0
	bl sub_80A77D0
	mov r9, r0
	ldr r1, _080A4BE4
	str r5, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl Log
	lsls r1, r6, 3
	mov r2, r9
	ldr r0, [r2, 0x4]
	adds r0, r1
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r0, [r0, 0x24]
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	mov r1, r8
	str r0, [r1]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	strh r6, [r1, 0x6]
	strb r5, [r1, 0x8]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4BE0: .4byte gUnknown_8117560
_080A4BE4: .4byte gUnknown_811756C
	thumb_func_end GroundMap_GetStationScript

	thumb_func_start sub_80A4BE8
sub_80A4BE8:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	movs r2, 0
	movs r3, 0
	bl GroundMap_GetStationScript
	pop {r0}
	bx r0
	thumb_func_end sub_80A4BE8

	thumb_func_start GroundMap_ExecuteEvent
GroundMap_ExecuteEvent:
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	ldr r1, _080A4C44
	movs r0, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl Log
	movs r0, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_809D710
	cmp r5, 0
	beq _080A4C2C
	mov r1, sp
	movs r0, 0x5
	strh r0, [r1, 0x4]
_080A4C2C:
	ldr r0, _080A4C48
	ldr r0, [r0]
	ldr r3, _080A4C4C
	movs r1, 0
	mov r2, sp
	bl GroundScript_ExecutePP
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4C44: .4byte gUnknown_8117594
_080A4C48: .4byte gUnknown_3001B6C
_080A4C4C: .4byte gUnknown_81175E0
	thumb_func_end GroundMap_ExecuteEvent

	thumb_func_start GroundMap_ExecuteStation
GroundMap_ExecuteStation:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	mov r8, r3
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	lsls r6, 24
	asrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, _080A4CB8
	str r6, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl Log
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl GroundMap_GetStationScript
	mov r0, r8
	cmp r0, 0
	beq _080A4C9C
	add r1, sp, 0x8
	movs r0, 0x5
	strh r0, [r1, 0x4]
_080A4C9C:
	ldr r0, _080A4CBC
	ldr r0, [r0]
	ldr r3, _080A4CC0
	movs r1, 0
	add r2, sp, 0x8
	bl GroundScript_ExecutePP
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4CB8: .4byte gUnknown_81175EC
_080A4CBC: .4byte gUnknown_3001B6C
_080A4CC0: .4byte gUnknown_8117644
	thumb_func_end GroundMap_ExecuteStation

	thumb_func_start GroundMap_ExecuteEnter
GroundMap_ExecuteEnter:
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	ldr r1, _080A4D08
	movs r0, 0
	adds r2, r4, 0
	bl Log
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A4BE8
	mov r1, sp
	movs r3, 0
	movs r2, 0
	movs r0, 0x2
	strh r0, [r1, 0x4]
	mov r0, sp
	strh r2, [r0, 0x6]
	strb r3, [r0, 0x8]
	ldr r0, _080A4D0C
	ldr r0, [r0]
	ldr r3, _080A4D10
	movs r1, 0
	mov r2, sp
	bl GroundScript_ExecutePP
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4D08: .4byte gUnknown_8117650
_080A4D0C: .4byte gUnknown_3001B6C
_080A4D10: .4byte gUnknown_8117698
	thumb_func_end GroundMap_ExecuteEnter

	thumb_func_start sub_80A4D14
sub_80A4D14:
	push {lr}
	ldr r0, _080A4D28
	ldr r0, [r0]
	bl sub_809D678
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_080A4D28: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4D14

	thumb_func_start sub_80A4D2C
sub_80A4D2C:
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	ldr r0, _080A4D44
	ldr r0, [r0]
	bl sub_809D968
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_080A4D44: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4D2C

	thumb_func_start sub_80A4D48
sub_80A4D48:
	push {lr}
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080A4D74
	ldr r1, _080A4D70
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x5
	beq _080A4D6C
	cmp r0, 0x8
	bne _080A4D74
_080A4D6C:
	movs r0, 0
	b _080A4D76
	.align 2, 0
_080A4D70: .4byte gUnknown_811BAF4
_080A4D74:
	movs r0, 0x1
_080A4D76:
	pop {r1}
	bx r1
	thumb_func_end sub_80A4D48

	thumb_func_start sub_80A4D7C
sub_80A4D7C:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0x9
	beq _080A4D94
	cmp r5, 0x9
	bgt _080A4D90
	cmp r5, 0x2
	beq _080A4DB6
	b _080A4DC4
_080A4D90:
	cmp r5, 0xC
	bne _080A4DC4
_080A4D94:
	movs r0, 0
	movs r1, 0x27
	bl sub_8001658
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 1
	adds r1, r0
	adds r1, r5, r1
	lsls r1, 16
	asrs r5, r1, 16
	b _080A4DC4
_080A4DB6:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A4DC4
	movs r5, 0x3
_080A4DC4:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A4D7C

	thumb_func_start GroundMap_Select
GroundMap_Select:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	ldr r1, _080A4E38
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	movs r0, 0
	bl sub_80A5EDC
	ldr r4, _080A4E3C
	ldr r0, [r4]
	cmp r0, 0
	beq _080A4E08
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A4E08:
	ldr r0, _080A4E40
	movs r1, 0x6
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r4]
	ldr r0, _080A4E44
	ldr r0, [r0]
	adds r0, 0xE4
	strh r5, [r0]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _080A4E4C
	ldr r1, _080A4E48
	adds r0, r2, 0
	bl sub_80A2B40
	ldr r0, [r4]
	adds r1, r5, 0
	bl sub_80A2FBC
	b _080A50BA
	.align 2, 0
_080A4E38: .4byte gUnknown_81176A4
_080A4E3C: .4byte gUnknown_3001B70
_080A4E40: .4byte 0x0000055c
_080A4E44: .4byte gUnknown_3001B6C
_080A4E48: .4byte gUnknown_8117324
_080A4E4C:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	ldr r1, _080A4E6C
	adds r6, r0, r1
	ldrh r0, [r6]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _080A4F20
	lsls r0, 2
	ldr r1, _080A4E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A4E6C: .4byte gUnknown_811BAF4
_080A4E70: .4byte _080A4E74
	.align 2, 0
_080A4E74:
	.4byte _080A4F08
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4ECC
	.4byte _080A4ECC
_080A4EA8:
	ldr r0, _080A4EC0
	ldr r0, [r0]
	ldr r1, _080A4EC4
	bl sub_80A2B40
	ldr r1, _080A4EC8
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	b _080A4F30
	.align 2, 0
_080A4EC0: .4byte gUnknown_3001B70
_080A4EC4: .4byte gUnknown_811733C
_080A4EC8: .4byte gUnknown_2026E4E
_080A4ECC:
	ldr r4, _080A4EDC
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	negs r1, r1
	ldr r6, _080A4EE0
	b _080A4EEA
	.align 2, 0
_080A4EDC: .4byte gUnknown_81173C0
_080A4EE0: .4byte gUnknown_3001B70
_080A4EE4:
	adds r4, 0xC
	movs r2, 0
	ldrsh r0, [r4, r2]
_080A4EEA:
	cmp r0, r1
	beq _080A4EF2
	cmp r0, r5
	bne _080A4EE4
_080A4EF2:
	ldr r0, [r6]
	bl MemoryFree
	movs r0, 0
	str r0, [r6]
	adds r1, r4, 0x4
	ldr r2, [r4, 0x8]
	adds r0, r5, 0
	bl GroundMap_SelectDungeon
	b _080A50BA
_080A4F08:
	ldr r0, _080A4F18
	ldr r1, _080A4F1C
	movs r2, 0
	ldrsh r3, [r6, r2]
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A4F18: .4byte gUnknown_81176D0
_080A4F1C: .4byte gUnknown_81176DC
_080A4F20:
	ldr r0, _080A4FA0
	ldr r0, [r0]
	ldr r1, _080A4FA4
	bl sub_80A2B40
	movs r0, 0x1
	bl sub_80A5EDC
_080A4F30:
	ldr r5, _080A4FA0
	ldr r0, [r5]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	bl sub_80A2FBC
	ldr r0, _080A4FA8
	ldr r0, [r0]
	mov r12, r0
	adds r0, 0xE8
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	movs r4, 0x80
	lsls r4, 1
	add r4, r12
	movs r3, 0x82
	lsls r3, 1
	add r3, r12
	movs r2, 0x84
	lsls r2, 1
	add r2, r12
	movs r0, 0x86
	lsls r0, 1
	add r0, r12
	str r1, [r0]
	str r1, [r2]
	str r1, [r3]
	str r1, [r4]
	mov r0, r12
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0xAD
	beq _080A5034
	cmp r0, 0xAD
	bgt _080A4FC0
	cmp r0, 0xA3
	bgt _080A4FAC
	cmp r0, 0xA2
	bge _080A4FEE
	cmp r0, 0x4
	beq _080A5084
	cmp r0, 0xA1
	beq _080A5084
	b _080A50A2
	.align 2, 0
_080A4FA0: .4byte gUnknown_3001B70
_080A4FA4: .4byte gUnknown_8117324
_080A4FA8: .4byte gUnknown_3001B6C
_080A4FAC:
	cmp r0, 0xAA
	beq _080A500C
	cmp r0, 0xAA
	bgt _080A4FBA
	cmp r0, 0xA8
	beq _080A500C
	b _080A50A2
_080A4FBA:
	cmp r0, 0xAB
	beq _080A5018
	b _080A50A2
_080A4FC0:
	cmp r0, 0xBA
	beq _080A506A
	cmp r0, 0xBA
	bgt _080A4FD6
	cmp r0, 0xAF
	beq _080A5072
	cmp r0, 0xAF
	blt _080A5044
	cmp r0, 0xB0
	beq _080A5060
	b _080A50A2
_080A4FD6:
	cmp r0, 0xDF
	beq _080A4FEE
	cmp r0, 0xDF
	bgt _080A4FE4
	cmp r0, 0xC0
	beq _080A5020
	b _080A50A2
_080A4FE4:
	cmp r0, 0xE0
	beq _080A508E
	cmp r0, 0xE1
	beq _080A5096
	b _080A50A2
_080A4FEE:
	ldr r0, _080A5000
	ldr r0, [r0]
	movs r1, 0x4
	bl sub_80A3BB0
	ldr r1, _080A5004
	ldr r2, _080A5008
	b _080A5050
	.align 2, 0
_080A5000: .4byte gUnknown_3001B70
_080A5004: .4byte gUnknown_2026E4E
_080A5008: .4byte 0x00000808
_080A500C:
	ldr r0, _080A5014
	ldr r0, [r0]
	b _080A5062
	.align 2, 0
_080A5014: .4byte gUnknown_3001B70
_080A5018:
	ldr r0, [r5]
	movs r1, 0x1
	bl sub_80A3BB0
_080A5020:
	ldr r0, _080A5030
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80A3B80
	b _080A50A2
	.align 2, 0
_080A5030: .4byte gUnknown_3001B70
_080A5034:
	ldr r1, _080A503C
	ldr r2, _080A5040
	b _080A5050
	.align 2, 0
_080A503C: .4byte gUnknown_2026E4E
_080A5040: .4byte 0x00001010
_080A5044:
	ldr r0, [r5]
	movs r1, 0x4
	bl sub_80A3BB0
	ldr r1, _080A5058
	ldr r2, _080A505C
_080A5050:
	adds r0, r2, 0
	strh r0, [r1]
	b _080A50A2
	.align 2, 0
_080A5058: .4byte gUnknown_2026E4E
_080A505C: .4byte 0x0000080c
_080A5060:
	ldr r0, [r5]
_080A5062:
	movs r1, 0x1
	bl sub_80A3BB0
	b _080A50A2
_080A506A:
	ldr r0, _080A507C
	ldr r2, _080A5080
	adds r1, r2, 0
	strh r1, [r0]
_080A5072:
	ldr r0, [r5]
	movs r1, 0x4
	bl sub_80A3BB0
	b _080A50A2
	.align 2, 0
_080A507C: .4byte gUnknown_2026E4E
_080A5080: .4byte 0x00001010
_080A5084:
	ldr r0, [r5]
	movs r1, 0x3
	bl sub_80A3BB0
	b _080A50A2
_080A508E:
	ldr r0, [r5]
	movs r1, 0x3
	bl sub_80A3BB0
_080A5096:
	ldr r0, _080A50C0
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80A3B80
_080A50A2:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A50B4
	adds r0, r1, 0
	bl GroundWeather_Select
_080A50B4:
	ldr r0, _080A50C4
	bl sub_80A56D8
_080A50BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A50C0: .4byte gUnknown_3001B70
_080A50C4: .4byte gUnknown_81176F8
	thumb_func_end GroundMap_Select

	thumb_func_start GroundMap_SelectDungeon
GroundMap_SelectDungeon:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r1
	mov r10, r2
	lsls r0, 16
	asrs r5, r0, 16
	ldr r1, _080A514C
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	movs r0, 0
	bl sub_80A5EDC
	ldr r7, _080A5150
	ldr r0, [r7]
	cmp r0, 0
	beq _080A5110
	bl sub_80A2D00
	ldr r0, [r7]
	bl MemoryFree
	movs r0, 0
	str r0, [r7]
_080A5110:
	ldr r0, _080A5154
	movs r1, 0x6
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r7]
	ldr r0, _080A5158
	mov r9, r0
	ldr r0, [r0]
	adds r0, 0xE4
	movs r4, 0
	strh r5, [r0]
	movs r6, 0x1
	negs r6, r6
	cmp r5, r6
	beq _080A5138
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x63
	bne _080A5160
_080A5138:
	ldr r1, _080A515C
	adds r0, r2, 0
	bl sub_80A2B40
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_80A2FBC
	b _080A51EC
	.align 2, 0
_080A514C: .4byte gUnknown_8117700
_080A5150: .4byte gUnknown_3001B70
_080A5154: .4byte 0x0000055c
_080A5158: .4byte gUnknown_3001B6C
_080A515C: .4byte gUnknown_8117324
_080A5160:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	ldr r1, _080A5180
	adds r6, r0, r1
	ldrh r0, [r6]
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080A518C
	ldr r0, _080A5184
	ldr r1, _080A5188
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A5180: .4byte gUnknown_811BAF4
_080A5184: .4byte gUnknown_8117734
_080A5188: .4byte gUnknown_8117740
_080A518C:
	ldr r1, _080A51FC
	adds r0, r2, 0
	bl sub_80A2B40
	movs r0, 0x1
	bl sub_80A5EDC
	ldr r0, [r7]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	mov r2, r8
	mov r3, r10
	bl sub_80A3440
	mov r0, r9
	ldr r0, [r0]
	mov r12, r0
	adds r0, 0xE8
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	movs r3, 0x80
	lsls r3, 1
	add r3, r12
	movs r2, 0x82
	lsls r2, 1
	add r2, r12
	movs r1, 0x84
	lsls r1, 1
	add r1, r12
	movs r0, 0x86
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	str r4, [r1]
	str r4, [r2]
	str r4, [r3]
	ldr r0, _080A5200
	bl sub_80A56D8
_080A51EC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A51FC: .4byte gUnknown_8117354
_080A5200: .4byte gUnknown_8117754
	thumb_func_end GroundMap_SelectDungeon

	thumb_func_start sub_80A5204
sub_80A5204:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	mov r8, r1
	str r2, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bgt _080A5222
	b _080A53EA
_080A5222:
	mov r5, r8
	ldr r2, [sp]
	mov r12, r2
	movs r0, 0
	ldr r3, [sp, 0x4]
	ldrb r3, [r3, 0x1]
	str r3, [sp, 0x10]
	ldr r1, [sp, 0x4]
	ldrh r2, [r1, 0xA]
	mov r1, sp
	strh r2, [r1, 0xC]
	movs r1, 0xFF
_080A523A:
	adds r0, 0x1
	mov r10, r0
	movs r3, 0xFF
	mov r9, r3
_080A5242:
	mov r0, r12
	strb r1, [r0]
	movs r2, 0x1
	add r12, r2
	movs r3, 0x1
	negs r3, r3
	add r9, r3
	mov r0, r9
	cmp r0, 0
	bge _080A5242
	mov r0, r10
	cmp r0, 0x3
	ble _080A523A
	movs r1, 0
	ldr r2, [sp, 0x10]
	cmp r1, r2
	blt _080A5266
	b _080A53BA
_080A5266:
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
_080A526A:
	adds r0, 0x1
	mov r10, r0
	adds r0, r1, 0x1
	str r0, [sp, 0x14]
	movs r0, 0xFF
	movs r2, 0x4
	mov r9, r2
_080A5278:
	mov r3, r12
	strb r0, [r3]
	movs r2, 0x1
	add r12, r2
	movs r3, 0x1
	negs r3, r3
	add r9, r3
	mov r2, r9
	cmp r2, 0
	bge _080A5278
	movs r3, 0x5
	mov r9, r3
	movs r0, 0
	cmp r1, 0
	bne _080A5308
	cmp r1, r7
	bge _080A5394
_080A529A:
	ldrb r1, [r5]
	adds r5, 0x1
	cmp r1, 0xBF
	ble _080A52C2
	adds r6, r0, 0
	subs r6, 0xBF
	cmp r1, 0xBF
	ble _080A5300
	adds r2, r1, 0
	subs r2, 0xBF
_080A52AE:
	ldrb r0, [r5]
	mov r3, r12
	strb r0, [r3]
	adds r5, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A52AE
	b _080A5300
_080A52C2:
	cmp r1, 0x7F
	ble _080A52E6
	ldrb r4, [r5]
	adds r5, 0x1
	adds r6, r0, 0
	subs r6, 0x7F
	cmp r1, 0x7F
	ble _080A5300
	adds r2, r1, 0
	subs r2, 0x7F
_080A52D6:
	mov r3, r12
	strb r4, [r3]
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A52D6
	b _080A5300
_080A52E6:
	movs r2, 0
	adds r6, r0, 0x1
	cmp r2, r1
	bgt _080A5300
	movs r0, 0
	adds r2, r1, 0x1
_080A52F2:
	mov r3, r12
	strb r0, [r3]
	movs r3, 0x1
	add r12, r3
	subs r2, 0x1
	cmp r2, 0
	bne _080A52F2
_080A5300:
	adds r0, r6, r1
	cmp r0, r7
	blt _080A529A
	b _080A5394
_080A5308:
	ldr r4, _080A5340
	add r4, r12
	cmp r0, r7
	bge _080A5394
_080A5310:
	ldrb r3, [r5]
	adds r5, 0x1
	cmp r3, 0xBF
	ble _080A5344
	adds r6, r0, 0
	subs r6, 0xBF
	cmp r3, 0xBF
	ble _080A538E
	adds r2, r3, 0
	subs r2, 0xBF
_080A5324:
	ldrb r1, [r5]
	ldrb r0, [r4]
	eors r1, r0
	mov r0, r12
	strb r1, [r0]
	adds r4, 0x1
	adds r5, 0x1
	movs r1, 0x1
	add r12, r1
	subs r2, 0x1
	cmp r2, 0
	bne _080A5324
	b _080A538E
	.align 2, 0
_080A5340: .4byte 0xffffff00
_080A5344:
	cmp r3, 0x7F
	ble _080A5372
	ldrb r2, [r5]
	mov r8, r2
	adds r5, 0x1
	adds r6, r0, 0
	subs r6, 0x7F
	cmp r3, 0x7F
	ble _080A538E
	adds r2, r3, 0
	subs r2, 0x7F
_080A535A:
	ldrb r1, [r4]
	mov r0, r8
	eors r0, r1
	mov r1, r12
	strb r0, [r1]
	adds r4, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A535A
	b _080A538E
_080A5372:
	movs r2, 0
	adds r6, r0, 0x1
	cmp r2, r3
	bgt _080A538E
	adds r2, r3, 0x1
_080A537C:
	ldrb r0, [r4]
	mov r1, r12
	strb r0, [r1]
	adds r4, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A537C
_080A538E:
	adds r0, r6, r3
	cmp r0, r7
	blt _080A5310
_080A5394:
	add r9, r7
	mov r1, r9
	cmp r1, 0xFF
	bgt _080A53AE
	movs r0, 0xFF
_080A539E:
	mov r2, r12
	strb r0, [r2]
	movs r3, 0x1
	add r12, r3
	add r9, r3
	mov r1, r9
	cmp r1, 0xFF
	ble _080A539E
_080A53AE:
	ldr r1, [sp, 0x14]
	mov r0, r10
	ldr r2, [sp, 0x10]
	cmp r1, r2
	bge _080A53BA
	b _080A526A
_080A53BA:
	ldr r3, [sp, 0x8]
	cmp r0, r3
	bge _080A53E6
	movs r1, 0xFF
_080A53C2:
	adds r0, 0x1
	mov r10, r0
	movs r0, 0xFF
	mov r9, r0
_080A53CA:
	mov r2, r12
	strb r1, [r2]
	movs r3, 0x1
	add r12, r3
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r2, r9
	cmp r2, 0
	bge _080A53CA
	mov r0, r10
	ldr r3, [sp, 0x8]
	cmp r0, r3
	blt _080A53C2
_080A53E6:
	mov r8, r5
	b _080A547E
_080A53EA:
	ldr r1, [sp]
	movs r0, 0
	ldr r2, [sp, 0x4]
	ldrb r2, [r2, 0x1]
	str r2, [sp, 0x10]
	ldr r3, [sp, 0x4]
	ldrh r2, [r3, 0xA]
	mov r3, sp
	strh r2, [r3, 0xC]
	movs r6, 0xFF
_080A53FE:
	adds r5, r0, 0x1
	movs r4, 0xFF
_080A5402:
	strb r6, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A5402
	adds r0, r5, 0
	cmp r0, 0x3
	ble _080A53FE
	movs r4, 0
	ldr r3, [sp, 0x10]
	cmp r4, r3
	bge _080A5460
	ldr r2, [sp, 0x4]
	ldrb r7, [r2]
	movs r3, 0xFF
_080A5420:
	adds r5, r0, 0x1
	adds r2, r4, 0x1
	movs r4, 0x4
_080A5426:
	strb r3, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A5426
	movs r4, 0x5
	cmp r7, 0
	beq _080A5444
	movs r6, 0
	adds r0, r7, 0
_080A543A:
	strb r6, [r1]
	adds r1, 0x1
	subs r0, 0x1
	cmp r0, 0
	bne _080A543A
_080A5444:
	adds r4, r7
	cmp r4, 0xFF
	bgt _080A5456
	movs r0, 0xFF
_080A544C:
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0xFF
	ble _080A544C
_080A5456:
	adds r4, r2, 0
	adds r0, r5, 0
	ldr r2, [sp, 0x10]
	cmp r4, r2
	blt _080A5420
_080A5460:
	ldr r3, [sp, 0x8]
	cmp r0, r3
	bge _080A547E
	movs r6, 0xFF
_080A5468:
	adds r5, r0, 0x1
	movs r4, 0xFF
_080A546C:
	strb r6, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A546C
	adds r0, r5, 0
	ldr r2, [sp, 0x8]
	cmp r0, r2
	blt _080A5468
_080A547E:
	mov r3, sp
	ldrh r3, [r3, 0xC]
	lsls r0, r3, 16
	cmp r0, 0
	bgt _080A548A
	b _080A5590
_080A548A:
	mov r6, r8
	ldr r0, [sp]
	movs r1, 0x80
	lsls r1, 3
	adds r2, r0, r1
	movs r0, 0
	ldr r3, [sp, 0x10]
	cmp r0, r3
	bge _080A5586
	movs r1, 0xFB
	mov r10, r1
_080A54A0:
	adds r2, 0x5
	movs r4, 0
	cmp r0, 0
	bne _080A54EC
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	movs r1, 0x1
	mov r9, r1
	cmp r0, r7
	bge _080A5574
_080A54B4:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0x7F
	ble _080A54DE
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A54D6
	movs r5, 0x80
	adds r3, r1, 0
	subs r3, 0x7F
_080A54C8:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A54C8
_080A54D6:
	adds r4, r1
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	b _080A54E6
_080A54DE:
	adds r0, r1, 0x1
	adds r2, r0
	adds r0, r4, 0x1
	adds r4, r0, r1
_080A54E6:
	cmp r4, r7
	blt _080A54B4
	b _080A5574
_080A54EC:
	ldr r1, _080A5538
	adds r1, r2
	mov r12, r1
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	adds r0, 0x1
	mov r9, r0
	cmp r4, r7
	bge _080A5574
_080A54FE:
	ldrb r5, [r6]
	adds r6, 0x1
	cmp r5, 0x7F
	ble _080A553C
	subs r4, 0x7F
	cmp r5, 0x7F
	ble _080A556A
	movs r7, 0x80
	movs r0, 0x80
	mov r8, r0
	adds r3, r5, 0
	subs r3, 0x7F
_080A5516:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	bne _080A552C
	ldrb r0, [r2]
	orrs r0, r7
	strb r0, [r2]
_080A552C:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A5516
	b _080A556A
	.align 2, 0
_080A5538: .4byte 0xffffff00
_080A553C:
	movs r3, 0
	adds r4, 0x1
	cmp r3, r5
	bgt _080A556A
	movs r7, 0x80
	movs r3, 0x80
	mov r8, r3
	adds r3, r5, 0x1
_080A554C:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	beq _080A5562
	ldrb r0, [r2]
	orrs r0, r7
	strb r0, [r2]
_080A5562:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A554C
_080A556A:
	adds r4, r5
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	cmp r4, r7
	blt _080A54FE
_080A5574:
	mov r1, r10
	subs r0, r1, r7
	adds r2, r0
	mov r0, r9
	ldr r3, [sp, 0x4]
	ldrb r3, [r3, 0x1]
	str r3, [sp, 0x10]
	cmp r0, r3
	blt _080A54A0
_080A5586:
	mov r8, r6
	ldr r0, [sp, 0x4]
	ldrh r1, [r0, 0xA]
	mov r0, sp
	strh r1, [r0, 0xC]
_080A5590:
	mov r2, sp
	ldrh r2, [r2, 0xC]
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _080A568C
	mov r6, r8
	ldr r3, [sp]
	movs r0, 0x80
	lsls r0, 3
	adds r2, r3, r0
	movs r0, 0
	b _080A5684
_080A55AA:
	adds r2, 0x5
	movs r4, 0
	cmp r0, 0
	bne _080A55F2
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	movs r1, 0x1
	mov r10, r1
	cmp r0, r7
	bge _080A567C
_080A55BE:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0x7F
	ble _080A55E4
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A55E0
	movs r5, 0x40
	adds r3, r1, 0
	subs r3, 0x7F
_080A55D2:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A55D2
_080A55E0:
	adds r4, r1
	b _080A55EC
_080A55E4:
	adds r0, r1, 0x1
	adds r2, r0
	adds r0, r4, 0x1
	adds r4, r0, r1
_080A55EC:
	cmp r4, r7
	blt _080A55BE
	b _080A567C
_080A55F2:
	ldr r3, _080A5640
	adds r3, r2
	mov r12, r3
	ldr r1, [sp, 0x4]
	ldrb r7, [r1]
	adds r0, 0x1
	mov r10, r0
	cmp r4, r7
	bge _080A567C
_080A5604:
	ldrb r5, [r6]
	adds r6, 0x1
	cmp r5, 0x7F
	ble _080A5644
	subs r4, 0x7F
	cmp r5, 0x7F
	ble _080A5676
	movs r3, 0x40
	mov r8, r3
	movs r0, 0x40
	mov r9, r0
	adds r3, r5, 0
	subs r3, 0x7F
_080A561E:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r9
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	bne _080A5636
	ldrb r0, [r2]
	mov r1, r8
	orrs r0, r1
	strb r0, [r2]
_080A5636:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A561E
	b _080A5676
	.align 2, 0
_080A5640: .4byte 0xffffff00
_080A5644:
	movs r3, 0
	adds r4, 0x1
	cmp r3, r5
	bgt _080A5676
	movs r3, 0x40
	mov r8, r3
	movs r0, 0x40
	mov r9, r0
	adds r3, r5, 0x1
_080A5656:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r9
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	beq _080A566E
	ldrb r0, [r2]
	mov r1, r8
	orrs r0, r1
	strb r0, [r2]
_080A566E:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A5656
_080A5676:
	adds r4, r5
	cmp r4, r7
	blt _080A5604
_080A567C:
	movs r3, 0xFB
	subs r0, r3, r7
	adds r2, r0
	mov r0, r10
_080A5684:
	ldr r1, [sp, 0x10]
	cmp r0, r1
	blt _080A55AA
	mov r8, r6
_080A568C:
	mov r0, r8
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A5204

	thumb_func_start sub_80A56A0
sub_80A56A0:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, _080A56BC
	ldr r0, [r0]
	adds r1, r3, 0
	bl sub_80A3B80
	pop {r0}
	bx r0
	.align 2, 0
_080A56BC: .4byte gUnknown_3001B70
	thumb_func_end sub_80A56A0

	thumb_func_start sub_80A56C0
sub_80A56C0:
	push {lr}
	adds r2, r0, 0
	ldr r0, _080A56D4
	ldr r0, [r0]
	movs r1, 0
	bl sub_80A4558
	pop {r0}
	bx r0
	.align 2, 0
_080A56D4: .4byte gUnknown_3001B70
	thumb_func_end sub_80A56C0

	thumb_func_start sub_80A56D8
sub_80A56D8:
	push {lr}
	adds r2, r0, 0
	ldr r0, _080A56EC
	ldr r0, [r0]
	movs r1, 0
	bl sub_80A456C
	pop {r0}
	bx r0
	.align 2, 0
_080A56EC: .4byte gUnknown_3001B70
	thumb_func_end sub_80A56D8

	thumb_func_start sub_80A56F0
sub_80A56F0:
	ldr r1, _080A5700
	ldr r2, [r1]
	adds r2, 0xE8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.align 2, 0
_080A5700: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A56F0

	thumb_func_start sub_80A5704
sub_80A5704:
	ldr r1, _080A5724
	ldr r3, [r1]
	adds r2, r3, 0
	adds r2, 0xF8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r3, 0
	adds r0, 0xF0
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	bx lr
	.align 2, 0
_080A5724: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A5704

	thumb_func_start sub_80A5728
sub_80A5728:
	ldr r0, _080A5734
	ldr r0, [r0]
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A5734: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A5728

	thumb_func_start sub_80A5738
sub_80A5738:
	ldr r0, _080A5750
	ldr r0, [r0]
	adds r0, 0xE4
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, _080A5754
	adds r0, r1
	bx lr
	.align 2, 0
_080A5750: .4byte gUnknown_3001B6C
_080A5754: .4byte gUnknown_811BAF4
	thumb_func_end sub_80A5738

	thumb_func_start sub_80A5758
sub_80A5758:
	push {lr}
	adds r1, r0, 0
	ldr r0, _080A5768
	ldr r0, [r0]
	cmp r0, 0
	bne _080A576C
	movs r0, 0
	b _080A5772
	.align 2, 0
_080A5768: .4byte gUnknown_3001B70
_080A576C:
	bl sub_80A4608
	movs r0, 0x1
_080A5772:
	pop {r1}
	bx r1
	thumb_func_end sub_80A5758

	thumb_func_start sub_80A5778
sub_80A5778:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080A578C
	ldr r0, [r0]
	cmp r0, 0
	bne _080A5790
	movs r0, 0
	b _080A5798
	.align 2, 0
_080A578C: .4byte gUnknown_3001B70
_080A5790:
	adds r1, r3, 0
	bl sub_80A463C
	movs r0, 0x1
_080A5798:
	pop {r1}
	bx r1
	thumb_func_end sub_80A5778

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
	bl sub_80A463C
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
_080A5838: .4byte gUnknown_3001B70
_080A583C: .4byte gUnknown_3001B6C
_080A5840: .4byte gUnknown_811BAF4
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

	thumb_func_start sub_80A585C
sub_80A585C:
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
_080A5884: .4byte gUnknown_3001B70
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
	thumb_func_end sub_80A585C

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
_080A58F0: .4byte gUnknown_3001B70
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

	thumb_func_start sub_80A5934
sub_80A5934:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A5958
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A4660
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A5958: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5934

	thumb_func_start sub_80A595C
sub_80A595C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A5980
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A46C0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A5980: .4byte gUnknown_3001B70
	thumb_func_end sub_80A595C

	thumb_func_start sub_80A5984
sub_80A5984:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080A599C
	ldr r0, [r0]
	adds r1, r3, 0
	bl sub_80A4720
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.align 2, 0
_080A599C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5984

	thumb_func_start sub_80A59A0
sub_80A59A0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r3, r2, 16
	lsrs r3, 16
	ldr r0, _080A59BC
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A4740
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A59BC: .4byte gUnknown_3001B70
	thumb_func_end sub_80A59A0

	thumb_func_start GroundMap_Action
GroundMap_Action:
	push {lr}
	bl nullsub_123
	ldr r0, _080A59D4
	ldr r0, [r0]
	ldr r1, _080A59D8
	bl HandleAction
	pop {r0}
	bx r0
	.align 2, 0
_080A59D4: .4byte gUnknown_3001B6C
_080A59D8: .4byte gUnknown_8117770
	thumb_func_end GroundMap_Action

	thumb_func_start sub_80A59DC
sub_80A59DC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r7, _080A5A34
	ldr r0, [r7]
	cmp r0, 0
	bne _080A59F0
	b _080A5E5A
_080A59F0:
	mov r9, sp
	mov r0, sp
	bl sub_809D248
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A5A04
	str r0, [sp]
	str r0, [sp, 0x4]
_080A5A04:
	ldr r0, _080A5A38
	mov r8, r0
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r6, r8
	cmp r0, 0xAB
	bne _080A5A1A
	b _080A5BBE
_080A5A1A:
	cmp r0, 0xAB
	bgt _080A5A46
	cmp r0, 0xA3
	bgt _080A5A3C
	cmp r0, 0xA2
	bge _080A5A76
	cmp r0, 0x4
	bne _080A5A2C
	b _080A5D76
_080A5A2C:
	cmp r0, 0xA1
	bne _080A5A32
	b _080A5E28
_080A5A32:
	b _080A5E46
	.align 2, 0
_080A5A34: .4byte gUnknown_3001B70
_080A5A38: .4byte gUnknown_3001B6C
_080A5A3C:
	cmp r0, 0xA8
	beq _080A5AF4
	cmp r0, 0xAA
	beq _080A5AF4
	b _080A5E46
_080A5A46:
	cmp r0, 0xB0
	bne _080A5A4C
	b _080A5C76
_080A5A4C:
	cmp r0, 0xB0
	bgt _080A5A5E
	cmp r0, 0xAE
	bne _080A5A56
	b _080A5B58
_080A5A56:
	cmp r0, 0xAF
	bne _080A5A5C
	b _080A5BD8
_080A5A5C:
	b _080A5E46
_080A5A5E:
	cmp r0, 0xDF
	beq _080A5A76
	cmp r0, 0xDF
	bgt _080A5A6E
	cmp r0, 0xBA
	bne _080A5A6C
	b _080A5D18
_080A5A6C:
	b _080A5E46
_080A5A6E:
	cmp r0, 0xE0
	bne _080A5A74
	b _080A5DDA
_080A5A74:
	b _080A5E46
_080A5A76:
	ldr r3, [r6]
	adds r2, r3, 0
	adds r2, 0xF4
	ldr r1, [r2]
	adds r0, r1, 0x2
	str r0, [r2]
	adds r4, r3, 0
	adds r4, 0xFC
	cmp r0, 0
	bge _080A5A8C
	adds r0, r1, 0x5
_080A5A8C:
	asrs r1, r0, 2
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	ldr r0, [r2]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2]
	ldr r5, _080A5AF0
	ldr r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	movs r1, 0
	bl sub_80A4580
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	adds r1, r0
	add r4, sp, 0x8
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	subs r1, r0
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A5DD0
	.align 2, 0
_080A5AF0: .4byte gUnknown_3001B70
_080A5AF4:
	ldr r2, [r6]
	adds r3, r2, 0
	adds r3, 0xF0
	adds r0, r2, 0
	adds r0, 0xE8
	ldr r1, [r3]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r3]
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B0E
	adds r1, 0x7
_080A5B0E:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r3]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B20
	adds r0, r1, 0x7
_080A5B20:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r3]
	ldr r5, _080A5B54
	ldr r0, [r5]
	movs r1, 0
	bl sub_80A4580
	ldr r0, [r6]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x10]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x10
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	b _080A5DD2
	.align 2, 0
_080A5B54: .4byte gUnknown_3001B70
_080A5B58:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r0, r3, 0
	adds r0, 0xE8
	ldr r1, [r4]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r4]
	adds r2, r3, 0
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B72
	adds r1, 0x7
_080A5B72:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B84
	adds r0, r1, 0x7
_080A5B84:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x18]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x18
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5DCE
_080A5BBE:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, [r7]
	add r4, sp, 0x20
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5BD8:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r3, [r0]
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5C12
	adds r1, 0x7
_080A5C12:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	adds r3, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5C24
	adds r1, 0x7
_080A5C24:
	asrs r1, 3
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C36
	adds r0, r1, 0x7
_080A5C36:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C48
	adds r0, r1, 0x7
_080A5C48:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r2, [r1]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x28]
	adds r2, 0xFC
	mov r1, r9
	ldr r0, [r1, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x28
	b _080A5DC2
_080A5C76:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r6, r3, 0
	adds r6, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5CA2
	adds r1, 0x7
_080A5CA2:
	asrs r1, 3
	ldr r0, [r6]
	adds r0, r1
	str r0, [r6]
	adds r2, r3, 0
	adds r2, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5CB6
	adds r1, 0x7
_080A5CB6:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CC8
	adds r0, r1, 0x7
_080A5CC8:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CDA
	adds r0, r1, 0x7
_080A5CDA:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r6, 0
	bl sub_80A4580
	mov r0, r8
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x30]
	adds r2, 0xFC
	ldr r0, [sp, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x30
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D18:
	ldr r0, [r7]
	movs r1, 0x1
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D3A
	adds r0, r4, 0x4
_080A5D3A:
	asrs r1, r0, 2
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x3
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x38]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x38
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D76:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D98
	adds r0, 0x7
_080A5D98:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x40]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x40
_080A5DC2:
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
_080A5DCE:
	ldr r0, [r7]
_080A5DD0:
	movs r1, 0x1
_080A5DD2:
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5E52
_080A5DDA:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5DFC
	adds r0, 0x7
_080A5DFC:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r0, [r0]
	str r0, [sp, 0x48]
	ldr r0, [sp, 0x4]
	add r2, sp, 0x48
	str r0, [r2, 0x4]
	ldr r0, [r7]
	b _080A5E3E
_080A5E28:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	ldr r0, [r7]
	add r2, sp, 0x50
_080A5E3E:
	movs r1, 0x1
	bl sub_80A456C
	b _080A5E52
_080A5E46:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
_080A5E52:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	bl sub_80A4764
_080A5E5A:
	bl sub_80A60D8
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5E6C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A59DC

	thumb_func_start sub_80A5E70
sub_80A5E70:
	push {lr}
	ldr r0, _080A5E88
	ldr r0, [r0]
	cmp r0, 0
	beq _080A5E7E
	bl sub_80A49E8
_080A5E7E:
	bl sub_80A62D0
	pop {r0}
	bx r0
	.align 2, 0
_080A5E88: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5E70

	thumb_func_start sub_80A5E8C
sub_80A5E8C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _080A5EB4
	movs r0, 0x24
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r5]
	ldr r1, _080A5EB8
	strh r1, [r0]
	movs r1, 0
	strb r1, [r0, 0x2]
	adds r0, r4, 0
	bl sub_80A5EDC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5EB4: .4byte gUnknown_3001B74
_080A5EB8: .4byte 0x0000ffff
	thumb_func_end sub_80A5E8C

	thumb_func_start sub_80A5EBC
sub_80A5EBC:
	push {r4,lr}
	movs r0, 0
	bl sub_80A5EDC
	ldr r4, _080A5ED8
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5ED8: .4byte gUnknown_3001B74
	thumb_func_end sub_80A5EBC

	thumb_func_start sub_80A5EDC
sub_80A5EDC:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	movs r6, 0x1
	negs r6, r6
	movs r0, 0
	movs r1, 0x1B
	adds r2, r6, 0
	bl sub_80018D8
	ldr r0, _080A5F34
	ldr r1, [r0]
	ldr r0, _080A5F38
	strh r0, [r1]
	strb r5, [r1, 0x2]
	ldr r4, _080A5F3C
	ldr r0, [r4]
	cmp r0, 0
	beq _080A5F12
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A5F12:
	cmp r5, 0
	beq _080A5F2E
	ldr r0, _080A5F40
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r1, _080A5F44
	bl sub_80A2B40
	ldr r0, [r4]
	adds r1, r6, 0
	bl sub_80A2FBC
_080A5F2E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A5F34: .4byte gUnknown_3001B74
_080A5F38: .4byte 0x0000ffff
_080A5F3C: .4byte gUnknown_3001B78
_080A5F40: .4byte 0x0000055c
_080A5F44: .4byte gUnknown_8117784
	thumb_func_end sub_80A5EDC

	thumb_func_start nullsub_121
nullsub_121:
	bx lr
	thumb_func_end nullsub_121

	thumb_func_start nullsub_122
nullsub_122:
	bx lr
	thumb_func_end nullsub_122

	thumb_func_start GroundWeather_Select
GroundWeather_Select:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r5, r0, 16
	adds r7, r5, 0
	ldr r1, _080A5F94
	ldr r6, _080A5F98
	ldr r0, [r6]
	ldrb r3, [r0, 0x2]
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x1B
	adds r2, r5, 0
	bl sub_80018D8
	ldr r0, [r6]
	movs r4, 0
	strh r5, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	bne _080A5F80
	b _080A60B4
_080A5F80:
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _080A5FA0
	ldr r0, _080A5F9C
	ldr r0, [r0]
	adds r1, r5, 0
	bl sub_80A2FBC
	b _080A60B4
	.align 2, 0
_080A5F94: .4byte gUnknown_811779C
_080A5F98: .4byte gUnknown_3001B74
_080A5F9C: .4byte gUnknown_3001B78
_080A5FA0:
	lsls r1, r7, 2
	ldr r0, _080A5FD8
	adds r5, r1, r0
	ldr r0, _080A5FDC
	ldr r0, [r0]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl sub_80A2FBC
	ldr r0, [r6]
	str r4, [r0, 0x4]
	str r4, [r0, 0x8]
	str r4, [r0, 0xC]
	str r4, [r0, 0x10]
	str r4, [r0, 0x20]
	str r4, [r0, 0x1C]
	str r4, [r0, 0x18]
	str r4, [r0, 0x14]
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0xF
	bhi _080A6098
	lsls r0, 2
	ldr r1, _080A5FE0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A5FD8: .4byte gUnknown_811E5F4
_080A5FDC: .4byte gUnknown_3001B78
_080A5FE0: .4byte _080A5FE4
	.align 2, 0
_080A5FE4:
	.4byte _080A6088
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6088
	.4byte _080A6088
	.4byte _080A6088
	.4byte _080A6098
	.4byte _080A6040
	.4byte _080A6088
	.4byte _080A6024
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6050
	.4byte _080A606C
_080A6024:
	ldr r0, _080A6034
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6038
	ldr r2, _080A603C
	b _080A60B0
	.align 2, 0
_080A6034: .4byte gUnknown_3001B78
_080A6038: .4byte gUnknown_2026E4E
_080A603C: .4byte 0x0000040c
_080A6040:
	ldr r1, _080A6048
	ldr r2, _080A604C
	b _080A60B0
	.align 2, 0
_080A6048: .4byte gUnknown_2026E4E
_080A604C: .4byte 0x00000808
_080A6050:
	ldr r0, _080A6060
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6064
	ldr r2, _080A6068
	b _080A60B0
	.align 2, 0
_080A6060: .4byte gUnknown_3001B78
_080A6064: .4byte gUnknown_2026E4E
_080A6068: .4byte 0x00001010
_080A606C:
	ldr r0, _080A607C
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6080
	ldr r2, _080A6084
	b _080A60B0
	.align 2, 0
_080A607C: .4byte gUnknown_3001B78
_080A6080: .4byte gUnknown_2026E4E
_080A6084: .4byte 0x0000040c
_080A6088:
	ldr r1, _080A6090
	ldr r2, _080A6094
	b _080A60B0
	.align 2, 0
_080A6090: .4byte gUnknown_2026E4E
_080A6094: .4byte 0x00001010
_080A6098:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _080A60AA
	ldr r0, _080A60BC
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
_080A60AA:
	ldr r1, _080A60C0
	movs r2, 0x80
	lsls r2, 5
_080A60B0:
	adds r0, r2, 0
	strh r0, [r1]
_080A60B4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A60BC: .4byte gUnknown_3001B78
_080A60C0: .4byte gUnknown_2026E4E
	thumb_func_end GroundWeather_Select

	thumb_func_start sub_80A60C4
sub_80A60C4:
	ldr r0, _080A60D0
	ldr r0, [r0]
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A60D0: .4byte gUnknown_3001B74
	thumb_func_end sub_80A60C4

	thumb_func_start nullsub_123
nullsub_123:
	bx lr
	thumb_func_end nullsub_123

	thumb_func_start sub_80A60D8
sub_80A60D8:
	push {r4-r6,lr}
	sub sp, 0x28
	ldr r0, _080A6104
	ldr r3, [r0]
	ldrb r1, [r3, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	bne _080A60EA
	b _080A62C0
_080A60EA:
	ldrh r0, [r3]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bls _080A60F8
	b _080A6278
_080A60F8:
	lsls r0, 2
	ldr r1, _080A6108
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A6104: .4byte gUnknown_3001B74
_080A6108: .4byte _080A610C
	.align 2, 0
_080A610C:
	.4byte _080A62AC
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6150
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61D0
	.4byte _080A6224
_080A6150:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x2
	str r0, [r2, 0x4]
	ldr r4, [r2, 0x8]
	adds r3, r4, 0x1
	str r3, [r2, 0x8]
	cmp r0, 0
	bge _080A6164
	adds r0, r1, 0x5
_080A6164:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	adds r1, r3, 0
	cmp r1, 0
	bge _080A6174
	adds r1, r4, 0x4
_080A6174:
	asrs r1, 2
	ldr r0, [r2, 0x10]
	adds r0, r1
	str r0, [r2, 0x10]
	ldr r4, _080A61C8
	ldr r0, [r4]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r1, [r6]
	ldr r0, [r1, 0x4]
	movs r2, 0x3
	ands r0, r2
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x8]
	ands r0, r2
	str r0, [r1, 0x8]
	mov r0, sp
	bl sub_80A56C0
	ldr r2, [r6]
	ldr r0, [sp]
	ldr r1, [r2, 0xC]
	subs r0, r1
	str r0, [sp]
	ldr r0, [sp, 0x4]
	ldr r1, [r2, 0x10]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4]
	movs r1, 0
	mov r2, sp
	bl sub_80A4580
	ldr r0, [r4]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	b _080A62B8
	.align 2, 0
_080A61C8: .4byte gUnknown_3001B78
_080A61CC:
	add r4, sp, 0x8
	b _080A628E
_080A61D0:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0
	bge _080A61DE
	adds r0, r1, 0x4
_080A61DE:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	ldr r5, _080A6220
	ldr r0, [r5]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2, 0x4]
	add r4, sp, 0x10
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r1, [r6]
	ldr r0, [sp, 0x10]
	ldr r1, [r1, 0xC]
	subs r0, r1
	str r0, [sp, 0x10]
	movs r0, 0
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A6298
	.align 2, 0
_080A6220: .4byte gUnknown_3001B78
_080A6224:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x2
	str r0, [r2, 0x4]
	cmp r0, 0
	bge _080A6232
	adds r0, r1, 0x5
_080A6232:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	ldr r5, _080A6274
	ldr r0, [r5]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2, 0x4]
	add r4, sp, 0x18
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r1, [r6]
	ldr r0, [sp, 0x18]
	ldr r1, [r1, 0xC]
	subs r0, r1
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A6298
	.align 2, 0
_080A6274: .4byte gUnknown_3001B78
_080A6278:
	ldr r0, [r6]
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 2
	ldr r1, _080A62A4
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _080A62AC
	add r4, sp, 0x20
_080A628E:
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r0, _080A62A8
	ldr r0, [r0]
_080A6298:
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	b _080A62B8
	.align 2, 0
_080A62A4: .4byte gUnknown_811E5F4
_080A62A8: .4byte gUnknown_3001B78
_080A62AC:
	ldr r0, _080A62C8
	ldr r0, [r0]
	ldr r2, _080A62CC
	movs r1, 0
	bl sub_80A456C
_080A62B8:
	ldr r0, _080A62C8
	ldr r0, [r0]
	bl sub_80A4764
_080A62C0:
	add sp, 0x28
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A62C8: .4byte gUnknown_3001B78
_080A62CC: .4byte gUnknown_81177BC
	thumb_func_end sub_80A60D8

	thumb_func_start sub_80A62D0
sub_80A62D0:
	push {lr}
	ldr r0, _080A62E8
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _080A62E4
	ldr r0, _080A62EC
	ldr r0, [r0]
	bl sub_80A49E8
_080A62E4:
	pop {r0}
	bx r0
	.align 2, 0
_080A62E8: .4byte gUnknown_3001B74
_080A62EC: .4byte gUnknown_3001B78
	thumb_func_end sub_80A62D0

        .align 2,0
