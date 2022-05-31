	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
_080ADA8C: .4byte gGroundEventSelectText
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
_080ADAF8: .4byte gGroundEventCancelText
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
_080ADBA4: .4byte gGroundEventAddText
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
_080ADC5C: .4byte gGroundEventDeleteText
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
	bl GetDungeonFloorCount
	cmp r4, r0
	blt _080ADDFA
	adds r0, r5, 0
	bl GetDungeonFloorCount
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
	bl DecompressATGlobalFile
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
	bl DecompressATFile
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
	bl DecompressATFile
	adds r0, r4, 0
	bl CloseFile
	b _080ADEFC
	.align 2, 0
_080ADEB4: .4byte gMapparamText
_080ADEB8: .4byte gDungeonFileArchive
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
	bl DecompressATFile
	adds r0, r4, 0
	bl CloseFile
_080ADEFC:
	movs r5, 0
	ldr r3, [sp, 0x60]
	cmp r5, r3
	bge _080ADF52
_080ADF04:
	mov r0, r8
	bl IsWaterDungeon
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
_080ADF88: .4byte gDungeonFileArchive
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
