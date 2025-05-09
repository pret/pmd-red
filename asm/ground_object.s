	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
	bl GetScriptVarValue
	cmp r0, 0x1
	bgt _080ABDBC
	movs r4, 0x1B
	b _080ABDDA
_080ABDBC:
	movs r0, 0
	movs r1, 0x29
	bl GetScriptVarValue
	cmp r0, 0
	bne _080ABDD4
	movs r0, 0
	movs r1, 0x27
	bl GetScriptVarValue
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
_080ABE10: .4byte gGroundObjectTypes
_080ABE14: .4byte gGroundObjects
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
_080ABEA8: .4byte gGroundObjects
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
	bl GetCurrentDungeonBounds
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
	bl InitActionWithParams
	adds r6, r4, 0
	mov r1, r8
	ldr r2, [r1, 0xC]
	cmp r2, 0
	bne _080AC0F2
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	bl SpriteHasPokemonSize_80A66A4
	lsls r0, 24
	ldr r2, _080AC158
	cmp r0, 0
	beq _080AC0F2
	ldr r2, _080AC15C
_080AC0F2:
	adds r0, r6, 0
	movs r1, 0x1
	bl SetPredefinedScript
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
	bl SetPredefinedScript
	mov r0, r8
	ldr r2, [r0, 0x14]
	cmp r2, 0
	bne _080AC11C
	ldr r0, _080AC160
	ldr r2, [r0, 0x68]
_080AC11C:
	adds r0, r4, 0
	movs r1, 0x3
	bl SetPredefinedScript
	mov r1, r8
	ldr r2, [r1, 0x8]
	cmp r2, 0
	beq _080AC140
	adds r0, r4, 0
	movs r1, 0
	bl SetPredefinedScript
	ldr r3, _080AC164
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl ExecutePredefinedScript
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
_080AC154: .4byte gGroundObjectCallbacks
_080AC158: .4byte gUnknown_81182F4
_080AC15C: .4byte gUnknown_8118350
_080AC160: .4byte gFunctionScriptTable
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
	bl InitAction2
	ldr r0, _080AC1AC
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC1A4: .4byte gGroundObjects
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
_080AC1F0: .4byte gGroundObjects
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
_080AC238: .4byte gGroundObjects
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
_080AC268: .4byte gGroundObjects
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
_080AC2A0: .4byte gGroundObjects
_080AC2A4:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl GetPredefinedScript
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
_080AC2F4: .4byte gGroundObjects
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

	thumb_func_start GroundObjectsNotifyAll
GroundObjectsNotifyAll:
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
	bl GroundScriptNotify
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
_080AC374: .4byte gGroundObjects
	thumb_func_end GroundObjectsNotifyAll

	thumb_func_start GroundObjectsCancellAll
GroundObjectsCancellAll:
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
	bl GroundScript_Cancel
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
_080AC3BC: .4byte gGroundObjects
	thumb_func_end GroundObjectsCancellAll

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
_080AC3DC: .4byte gGroundObjects
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
_080AC404: .4byte gGroundObjects
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
_080AC434: .4byte gGroundObjects
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
_080AC474: .4byte gGroundObjects
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
	bl TryMoveObjectRelative_80AC6AC
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AC4C4: .4byte gGroundObjects
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
_080AC530: .4byte gGroundObjects
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
_080AC5C8: .4byte gGroundObjects
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

	thumb_func_start GetObjectCollision_80AC5F4
GetObjectCollision_80AC5F4:
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
	bl CheckMapCollision_80A585C
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
	bl GetLivesCollision_80A92A0
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
	thumb_func_end GetObjectCollision_80AC5F4

	thumb_func_start TryMoveObjectRelative_80AC6AC
TryMoveObjectRelative_80AC6AC:
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
	bl GetObjectCollision_80AC5F4
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
	thumb_func_end TryMoveObjectRelative_80AC6AC

	thumb_func_start TryMoveRelative_80AC720
TryMoveRelative_80AC720:
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
	bl GetObjectCollision_80AC5F4
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
	thumb_func_end TryMoveRelative_80AC720

	thumb_func_start CallbackObjectGetIndex
CallbackObjectGetIndex:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end CallbackObjectGetIndex

	thumb_func_start CallbackObjectGetSize
CallbackObjectGetSize:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end CallbackObjectGetSize

	thumb_func_start CallbackObjectSetHitboxPos
CallbackObjectSetHitboxPos:
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
	thumb_func_end CallbackObjectSetHitboxPos

	thumb_func_start CallbackObjectSetPositionBounds
CallbackObjectSetPositionBounds:
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
	thumb_func_end CallbackObjectSetPositionBounds

	thumb_func_start CallbackObjectGetHitboxCenter
CallbackObjectGetHitboxCenter:
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
	thumb_func_end CallbackObjectGetHitboxCenter

	thumb_func_start CallbackObjectMoveReal
CallbackObjectMoveReal:
	push {lr}
	bl TryMoveObjectRelative_80AC6AC
	pop {r1}
	bx r1
	thumb_func_end CallbackObjectMoveReal

	thumb_func_start CallbackObjectGetPosHeightAndUnk
CallbackObjectGetPosHeightAndUnk:
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
	thumb_func_end CallbackObjectGetPosHeightAndUnk

	thumb_func_start CallbackObjectSetPosHeight
CallbackObjectSetPosHeight:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end CallbackObjectSetPosHeight

	thumb_func_start CallbackObjectGetDirection
CallbackObjectGetDirection:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end CallbackObjectGetDirection

	thumb_func_start CallbackObjectSetDirection
CallbackObjectSetDirection:
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
	thumb_func_end CallbackObjectSetDirection

	thumb_func_start CallbackObjectSetEventIndex
CallbackObjectSetEventIndex:
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
	thumb_func_end CallbackObjectSetEventIndex

	thumb_func_start CallbackObjectSetUnk_80AC998
CallbackObjectSetUnk_80AC998:
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
	thumb_func_end CallbackObjectSetUnk_80AC998

	thumb_func_start CallbackObjectSpriteRelatedCheck_80AC9B8
CallbackObjectSpriteRelatedCheck_80AC9B8:
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
	thumb_func_end CallbackObjectSpriteRelatedCheck_80AC9B8

	thumb_func_start CallbackObjectSpriteRelated_80AC9DC
CallbackObjectSpriteRelated_80AC9DC:
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
	thumb_func_end CallbackObjectSpriteRelated_80AC9DC

	thumb_func_start CallbackObjectGetFlags
CallbackObjectGetFlags:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end CallbackObjectGetFlags

	thumb_func_start CallbackObjectSetFlags
CallbackObjectSetFlags:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1B0
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectSetFlags

	thumb_func_start CallbackObjectClearFlags
CallbackObjectClearFlags:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1F4
	pop {r0}
	bx r0
	thumb_func_end CallbackObjectClearFlags

	thumb_func_start CallbackObjectMoveRelative
CallbackObjectMoveRelative:
	push {lr}
	bl TryMoveRelative_80AC720
	pop {r1}
	bx r1
	thumb_func_end CallbackObjectMoveRelative

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
_080ACA7C: .4byte gGroundObjects
_080ACA80: .4byte gUnknown_8118524
_080ACA84:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080ACAD0
	bl ExecutePredefinedScript
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
_080ACB8C: .4byte gGroundObjects
	thumb_func_end sub_80ACAD4

        .align 2,0
