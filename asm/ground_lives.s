	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text





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
