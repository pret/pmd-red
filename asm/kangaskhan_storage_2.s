	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80182E4
sub_80182E4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	ldr r4, _080183DC
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _080183E0
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x2
	str r0, [r1, 0x24]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	beq _0801831C
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	beq _08018324
_0801831C:
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_08018324:
	movs r1, 0x1
	add r8, r1
	ldr r4, _080183DC
	ldr r2, [r4]
	mov r0, r8
	lsls r3, r0, 3
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r3
	ldr r1, _080183E4
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0x24
	adds r2, r3
	movs r0, 0x3
	str r0, [r2]
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	bne _08018358
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	ble _08018366
_08018358:
	ldr r0, [r4]
	mov r2, r8
	lsls r1, r2, 1
	adds r0, 0x60
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08018366:
	movs r0, 0x1
	add r8, r0
	ldr r4, _080183DC
	ldr r7, [r4]
	mov r2, r8
	lsls r1, r2, 3
	adds r2, r7, 0
	adds r2, 0x20
	adds r3, r2, r1
	ldr r0, _080183E8
	ldr r0, [r0]
	str r0, [r3]
	adds r6, r7, 0
	adds r6, 0x24
	adds r1, r6, r1
	movs r3, 0x1
	str r3, [r1]
	add r8, r3
	mov r1, r8
	lsls r0, r1, 3
	adds r2, r0
	movs r1, 0
	str r1, [r2]
	adds r0, r6, r0
	str r3, [r0]
	movs r5, 0
	mov r12, r4
	cmp r5, r8
	bge _080183C0
	adds r4, r7, 0
	adds r2, r4, 0
	adds r2, 0x60
	adds r3, r6, 0
_080183A8:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080183B6
	ldr r1, [r3]
	ldr r0, [r4, 0x14]
	cmp r1, r0
	beq _08018410
_080183B6:
	adds r2, 0x2
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, r8
	blt _080183A8
_080183C0:
	movs r5, 0
	cmp r5, r8
	bge _08018410
	mov r2, r12
	ldr r1, [r2]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _080183EC
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x14]
	b _08018410
	.align 2, 0
_080183DC: .4byte gUnknown_203B20C
_080183E0: .4byte gUnknown_80D4958
_080183E4: .4byte gUnknown_80D4964
_080183E8: .4byte gUnknown_80D4934
_080183EC:
	adds r5, 0x1
	cmp r5, r8
	bge _08018410
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080183EC
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_08018410:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80182E4

	thumb_func_start sub_801841C
sub_801841C:
	push {r4-r7,lr}
	ldr r4, _080184A0
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _080184A4
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x2
	str r0, [r1, 0x24]
	ldr r0, [r1, 0xC]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801844C
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_0801844C:
	ldr r2, [r4]
	movs r1, 0x1
	ldr r0, _080184A8
	ldr r0, [r0]
	str r0, [r2, 0x28]
	movs r0, 0x4
	str r0, [r2, 0x2C]
	movs r5, 0x2
	movs r0, 0
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0x60
	adds r2, 0x24
_0801846E:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0801847E
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _080184CE
_0801847E:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0801846E
	movs r3, 0
	cmp r3, r5
	bge _080184CE
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _080184AC
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x18]
	b _080184CE
	.align 2, 0
_080184A0: .4byte gUnknown_203B20C
_080184A4: .4byte gUnknown_80D4958
_080184A8: .4byte gUnknown_80D4970
_080184AC:
	adds r3, 0x1
	cmp r3, r5
	bge _080184CE
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080184AC
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_080184CE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801841C

	thumb_func_start sub_80184D4
sub_80184D4:
	push {r4-r7,lr}
	ldr r4, _08018554
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _08018558
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x3
	str r0, [r1, 0x24]
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0x13
	ble _08018500
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	strh r1, [r0]
_08018500:
	ldr r2, [r4]
	movs r1, 0x1
	ldr r0, _0801855C
	ldr r0, [r0]
	str r0, [r2, 0x28]
	movs r0, 0x4
	str r0, [r2, 0x2C]
	movs r5, 0x2
	movs r0, 0
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	movs r3, 0
	adds r6, r4, 0
	mov r12, r2
	mov r4, r12
	adds r4, 0x60
	adds r2, 0x24
_08018522:
	ldrh r0, [r4]
	cmp r0, 0
	bne _08018532
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x1C]
	cmp r1, r0
	beq _08018582
_08018532:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _08018522
	movs r3, 0
	cmp r3, r5
	bge _08018582
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x60
	ldrh r0, [r0]
	cmp r0, 0
	bne _08018560
	ldr r0, [r1, 0x24]
	str r0, [r1, 0x1C]
	b _08018582
	.align 2, 0
_08018554: .4byte gUnknown_203B20C
_08018558: .4byte gUnknown_80D4964
_0801855C: .4byte gUnknown_80D4970
_08018560:
	adds r3, 0x1
	cmp r3, r5
	bge _08018582
	ldr r2, [r6]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x60
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08018560
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x24
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
_08018582:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80184D4

        .align 2,0
