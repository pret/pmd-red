	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start ResetSprites
ResetSprites:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, _08004E68
	movs r0, 0
	str r0, [r1]
	ldr r1, _08004E6C
	ldr r0, _08004E70
	str r0, [r1]
	ldr r1, _08004E74
	ldr r0, _08004E78
	str r0, [r1]
	ldr r0, _08004E7C
	adds r1, r0, 0
	adds r1, 0x8
	adds r5, r0, 0
	movs r2, 0
	movs r3, 0xF0
_08004DB0:
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	subs r3, 0x10
	cmp r3, 0
	bge _08004DB0
	cmp r4, 0
	beq _08004E50
	movs r2, 0
	ldr r1, _08004E80
	ldr r0, _08004E84
	movs r3, 0x7F
_08004E42:
	str r2, [r0]
	str r1, [r0, 0x4]
	adds r1, 0x8
	adds r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08004E42
_08004E50:
	movs r1, 0x80
	lsls r1, 4
	adds r0, r5, r1
	movs r1, 0
	str r1, [r0]
	ldr r2, _08004E88
	adds r0, r5, r2
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004E68: .4byte gSpriteCount
_08004E6C: .4byte gCharMemCursor
_08004E70: .4byte 0x06010000
_08004E74: .4byte gUnknown_203B074
_08004E78: .4byte gUnknown_20266B0
_08004E7C: .4byte gUnknown_20256A0
_08004E80: .4byte gUnknown_20262A8
_08004E84: .4byte gUnknown_2025EA8
_08004E88: .4byte 0x00000804
	thumb_func_end ResetSprites

	thumb_func_start sub_8004E8C
sub_8004E8C:
	ldr r1, _08004EA4
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	movs r1, 0
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	bx lr
	.align 2, 0
_08004EA4: .4byte 0x0000ffff
	thumb_func_end sub_8004E8C

	thumb_func_start sub_8004EA8
sub_8004EA8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	adds r5, r0, 0
	mov r8, r1
	adds r0, r2, 0
	adds r6, r3, 0
	cmp r0, 0
	beq _08004EC2
	bl sub_80052BC
_08004EC2:
	ldr r0, _08004F40
	ldr r7, [r0]
	mov r12, r0
	cmp r7, 0x7F
	ble _08004ECE
	b _08005082
_08004ECE:
	mov r2, sp
	ldrh r0, [r5]
	strh r0, [r2]
	ldrh r0, [r5, 0x2]
	strh r0, [r2, 0x2]
	ldrh r4, [r5, 0x4]
	ldr r0, _08004F44
	ands r0, r4
	strh r0, [r2, 0x4]
	ldrh r3, [r5, 0x6]
	ldr r0, _08004F48
	ands r0, r3
	strh r0, [r2, 0x6]
	ldrh r0, [r5, 0x8]
	strh r0, [r2, 0x8]
	movs r1, 0xE0
	lsls r1, 4
	ands r1, r3
	lsrs r1, 9
	ldr r0, _08004F4C
	ands r0, r4
	lsls r0, 4
	orrs r1, r0
	strh r1, [r2, 0xA]
	lsls r1, r7, 3
	ldr r0, _08004F50
	adds r3, r1, r0
	mov r0, r8
	movs r2, 0x16
	ldrsh r1, [r0, r2]
	mov r0, sp
	ldrb r0, [r0, 0x3]
	lsls r0, 24
	asrs r0, 24
	adds r7, r1, r0
	cmp r7, 0
	bge _08004F1A
	movs r7, 0
_08004F1A:
	cmp r7, 0xFF
	ble _08004F20
	movs r7, 0xFF
_08004F20:
	cmp r6, 0
	bne _08004F54
	add r2, sp, 0x4
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	ldrh r0, [r2]
	strh r0, [r3, 0x2]
	adds r2, 0x2
	adds r1, r3, 0x4
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	ldrh r0, [r2]
	strh r0, [r1, 0x2]
	b _08004F86
	.align 2, 0
_08004F40: .4byte gSpriteCount
_08004F44: .4byte 0x0000fcff
_08004F48: .4byte 0x0000f1ff
_08004F4C: .4byte 0x000003ff
_08004F50: .4byte gUnknown_20262A8
_08004F54:
	add r4, sp, 0x4
	ldrh r1, [r4]
	ldrh r0, [r6]
	ands r0, r1
	ldrh r1, [r6, 0x6]
	orrs r0, r1
	strh r0, [r3]
	adds r4, 0x2
	ldrh r1, [r4]
	ldrh r0, [r6, 0x2]
	ands r0, r1
	ldrh r1, [r6, 0x8]
	orrs r0, r1
	strh r0, [r3, 0x2]
	adds r4, 0x2
	adds r2, r3, 0x4
	ldrh r1, [r4]
	ldrh r0, [r6, 0x4]
	ands r0, r1
	ldrh r1, [r6, 0xA]
	orrs r0, r1
	strh r0, [r2]
	adds r4, 0x2
	ldrh r0, [r4]
	strh r0, [r2, 0x2]
_08004F86:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _08004FB0
	ldr r1, _08004FA8
	mov r0, sp
	ldrb r0, [r0, 0x2]
	lsls r0, 1
	adds r1, r0, r1
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08004FB0
	adds r1, r0, 0
	ldr r0, _08004FAC
	ands r1, r0
	b _08004FC0
	.align 2, 0
_08004FA8: .4byte gUnknown_2025672
_08004FAC: .4byte 0x000003ff
_08004FB0:
	ldrh r1, [r3, 0x4]
	ldr r2, _08005090
	ands r1, r2
	mov r6, r8
	movs r4, 0x14
	ldrsh r0, [r6, r4]
	adds r1, r0
	ands r1, r2
_08004FC0:
	ldrh r2, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r4, [r3, 0x2]
	ldr r5, _08005094
	adds r2, r5, 0
	ands r2, r4
	ldr r6, _08005098
	adds r1, r2, r6
	mov r2, r8
	movs r6, 0
	ldrsh r0, [r2, r6]
	adds r2, r1, r0
	movs r0, 0x40
	negs r0, r0
	mov r9, r0
	cmp r2, r9
	blt _08005082
	cmp r2, 0xEF
	bgt _08005082
	ands r2, r5
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r4
	orrs r0, r2
	strh r0, [r3, 0x2]
	ldrh r0, [r3, 0x6]
	lsls r4, r0, 16
	ldr r1, _0800509C
	adds r5, r1, 0
	lsrs r2, r4, 20
	ldr r6, _080050A0
	adds r1, r2, r6
	mov r2, r8
	movs r6, 0x2
	ldrsh r0, [r2, r6]
	adds r2, r1, r0
	cmp r2, r9
	blt _08005082
	cmp r2, 0x9F
	bgt _08005082
	movs r0, 0xFF
	ands r2, r0
	ldrh r1, [r3]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	lsrs r0, r4, 17
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08005044
	mov r0, r8
	ldrb r1, [r0, 0x1E]
	movs r0, 0xF
	ands r1, r0
	lsls r1, 12
	ldrh r0, [r3, 0x4]
	ands r0, r5
	orrs r0, r1
	strh r0, [r3, 0x4]
_08005044:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _08005068
	ldr r1, _080050A4
	mov r0, sp
	ldrb r0, [r0, 0x2]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0xF
	ands r1, r0
	lsls r1, 12
	ldrh r0, [r3, 0x4]
	ands r0, r5
	orrs r0, r1
	strh r0, [r3, 0x4]
_08005068:
	ldr r0, _080050A8
	mov r4, r12
	ldr r3, [r4]
	lsls r2, r3, 3
	adds r2, r0
	ldr r1, _080050AC
	lsls r0, r7, 3
	adds r0, r1
	ldr r1, [r0]
	str r1, [r2]
	str r2, [r0]
	adds r3, 0x1
	str r3, [r4]
_08005082:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005090: .4byte 0x000003ff
_08005094: .4byte 0x000001ff
_08005098: .4byte 0xffffff00
_0800509C: .4byte 0x00000fff
_080050A0: .4byte 0xfffffe00
_080050A4: .4byte gUnknown_2025682
_080050A8: .4byte gUnknown_2025EA8
_080050AC: .4byte gUnknown_20256A0
	thumb_func_end sub_8004EA8

	thumb_func_start AddSprite
AddSprite:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r0, _080050F4
	ldr r0, [r0]
	cmp r0, 0x7F
	bgt _08005168
	lsls r1, r0, 3
	ldr r0, _080050F8
	adds r5, r1, r0
	cmp r7, 0
	bge _080050D2
	movs r7, 0
_080050D2:
	cmp r7, 0xFF
	ble _080050D8
	movs r7, 0xFF
_080050D8:
	cmp r4, 0
	bne _080050FC
	ldrh r0, [r6]
	strh r0, [r5]
	ldrh r0, [r6, 0x2]
	strh r0, [r5, 0x2]
	adds r1, r6, 0x4
	adds r2, r5, 0x4
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x2]
	b _08005128
	.align 2, 0
_080050F4: .4byte gSpriteCount
_080050F8: .4byte gUnknown_20262A8
_080050FC:
	ldrh r1, [r6]
	ldrh r0, [r4]
	ands r0, r1
	ldrh r1, [r4, 0x6]
	orrs r0, r1
	strh r0, [r5]
	ldrh r1, [r6, 0x2]
	ldrh r0, [r4, 0x2]
	ands r0, r1
	ldrh r1, [r4, 0x8]
	orrs r0, r1
	strh r0, [r5, 0x2]
	adds r2, r6, 0x4
	adds r3, r5, 0x4
	ldrh r1, [r2]
	ldrh r0, [r4, 0x4]
	ands r0, r1
	ldrh r1, [r4, 0xA]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2, 0x2]
	strh r0, [r3, 0x2]
_08005128:
	ldrh r4, [r5, 0x6]
	lsrs r4, 4
	adds r0, r4, 0
	movs r1, 0
	bl nullsub_3
	movs r0, 0xFF
	ands r4, r0
	ldrh r1, [r5]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	orrs r0, r4
	strh r0, [r5]
	mov r0, r8
	cmp r0, 0
	beq _0800514E
	bl sub_80052BC
_0800514E:
	ldr r0, _08005174
	ldr r4, _08005178
	ldr r3, [r4]
	lsls r2, r3, 3
	adds r2, r0
	ldr r1, _0800517C
	lsls r0, r7, 3
	adds r0, r1
	ldr r1, [r0]
	str r1, [r2]
	str r2, [r0]
	adds r3, 0x1
	str r3, [r4]
_08005168:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005174: .4byte gUnknown_2025EA8
_08005178: .4byte gSpriteCount
_0800517C: .4byte gUnknown_20256A0
	thumb_func_end AddSprite

	thumb_func_start sub_8005180
sub_8005180:
	push {lr}
	ldr r2, _080051A8
	adds r1, r2, 0
	cmp r2, 0
	beq _0800519E
_0800518A:
	ldr r0, [r1, 0x4]
	cmp r0, 0
	beq _08005198
	cmp r2, 0
	beq _08005196
	str r1, [r2]
_08005196:
	adds r2, r1, 0
_08005198:
	ldr r1, [r1]
	cmp r1, 0
	bne _0800518A
_0800519E:
	movs r0, 0
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080051A8: .4byte gUnknown_20256A0
	thumb_func_end sub_8005180

	thumb_func_start CopySpritesToOam
CopySpritesToOam:
	push {r4-r6,lr}
	ldr r3, _08005204
	ldr r2, _08005208
	movs r4, 0
	ldr r6, _0800520C
	cmp r3, 0
	beq _080051E0
	ldr r5, _08005210
_080051BC:
	ldr r1, [r3, 0x4]
	cmp r1, 0
	beq _080051D6
	subs r2, 0x4
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x2
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	subs r2, 0x2
	ldrh r0, [r1]
	strh r0, [r2]
	adds r4, 0x1
_080051D6:
	ldr r3, [r3]
	cmp r3, 0
	beq _080051E0
	cmp r2, r5
	bhi _080051BC
_080051E0:
	ldr r1, _08005210
	cmp r2, r1
	bls _080051FA
	movs r0, 0
	movs r3, 0xA0
_080051EA:
	subs r2, 0x4
	strh r0, [r2]
	subs r2, 0x2
	strh r0, [r2]
	subs r2, 0x2
	strh r3, [r2]
	cmp r2, r1
	bhi _080051EA
_080051FA:
	strh r4, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08005204: .4byte gUnknown_20256A0
_08005208: .4byte 0x07000400
_0800520C: .4byte gUnknown_2025670
_08005210: .4byte 0x07000008
	thumb_func_end CopySpritesToOam

	thumb_func_start SetSavingIconCoords
SetSavingIconCoords:
	push {lr}
	adds r3, r0, 0
	cmp r3, 0
	bne _0800522C
	ldr r1, _08005228
	strh r3, [r1]
	movs r0, 0xA0
	strh r0, [r1, 0x2]
	b _0800523C
	.align 2, 0
_08005228: .4byte gUnknown_2025694
_0800522C:
	ldr r1, _08005240
	ldrh r0, [r3]
	movs r2, 0
	strh r0, [r1]
	ldrh r0, [r3, 0x2]
	strh r0, [r1, 0x2]
	ldr r0, _08005244
	str r2, [r0]
_0800523C:
	pop {r0}
	bx r0
	.align 2, 0
_08005240: .4byte gUnknown_2025694
_08005244: .4byte gUnknown_2025698
	thumb_func_end SetSavingIconCoords

	thumb_func_start BlinkSavingIcon
BlinkSavingIcon:
	push {r4,lr}
	movs r2, 0xE0
	lsls r2, 19
	ldr r0, _08005280
	ldr r1, [r0]
	adds r3, r1, 0
	adds r1, 0x1
	str r1, [r0]
	movs r0, 0x10
	ands r3, r0
	cmp r3, 0
	beq _08005288
	movs r0, 0xA0
	strh r0, [r2]
	adds r2, 0x2
	movs r1, 0x80
	lsls r1, 7
	adds r0, r1, 0
	strh r0, [r2]
	adds r2, 0x2
	ldr r4, _08005284
	adds r0, r4, 0
	strh r0, [r2]
	adds r2, 0x2
	movs r0, 0
	strh r0, [r2]
	b _080052A8
	.align 2, 0
_08005280: .4byte gUnknown_2025698
_08005284: .4byte 0x0000f3fc
_08005288:
	ldr r1, _080052B0
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	ldr r2, _080052B4
	movs r4, 0x80
	lsls r4, 7
	adds r0, r4, 0
	ldrh r1, [r1]
	adds r0, r1
	strh r0, [r2]
	adds r2, 0x2
	ldr r1, _080052B8
	adds r0, r1, 0
	strh r0, [r2]
	adds r2, 0x2
	strh r3, [r2]
_080052A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080052B0: .4byte gUnknown_2025694
_080052B4: .4byte 0x07000002
_080052B8: .4byte 0x0000f3fc
	thumb_func_end BlinkSavingIcon

	thumb_func_start sub_80052BC
sub_80052BC:
	push {r4-r6,lr}
	adds r3, r0, 0
	ldr r0, [r3, 0x4]
	cmp r0, 0
	beq _080052F2
	ldr r5, _080052F8
	ldr r6, _080052FC
	ldr r4, _08005300
_080052CC:
	ldr r2, [r5]
	cmp r2, r6
	bcs _080052F2
	ldr r0, [r3, 0x4]
	str r0, [r2]
	ldr r0, [r3]
	str r0, [r2, 0x4]
	ldr r1, [r4]
	str r1, [r2, 0x8]
	ldr r0, [r3, 0x4]
	adds r1, r0
	str r1, [r4]
	adds r0, r2, 0
	adds r0, 0xC
	str r0, [r5]
	adds r3, 0x8
	ldr r0, [r3, 0x4]
	cmp r0, 0
	bne _080052CC
_080052F2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080052F8: .4byte gUnknown_203B074
_080052FC: .4byte gCharMemCursor
_08005300: .4byte gCharMemCursor
	thumb_func_end sub_80052BC

	thumb_func_start sub_8005304
sub_8005304:
	push {r4,lr}
	ldr r4, _0800530C
	b _0800532A
	.align 2, 0
_0800530C: .4byte gUnknown_20266B0
_08005310:
	ldr r1, [r4, 0x4]
	cmp r1, 0
	beq _08005320
	ldr r0, [r4, 0x8]
	ldr r2, [r4]
	bl CpuCopy
	b _08005328
_08005320:
	ldr r0, [r4, 0x8]
	ldr r1, [r4]
	bl CpuClear
_08005328:
	adds r4, 0xC
_0800532A:
	ldr r0, _08005338
	ldr r0, [r0]
	cmp r4, r0
	bcc _08005310
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08005338: .4byte gUnknown_203B074
	thumb_func_end sub_8005304

	thumb_func_start sub_800533C
sub_800533C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, 0
	adds r7, r3, 0
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r6, r1, 24
	movs r2, 0x18
	ldrsh r1, [r5, r2]
	lsls r1, 2
	adds r1, r0
	ldr r4, [r1]
	ldr r1, _08005368
	movs r2, 0x14
	ldrsh r0, [r5, r2]
	lsls r0, 5
	ldr r2, _0800536C
	adds r0, r2
	str r0, [r1]
	b _0800538E
	.align 2, 0
_08005368: .4byte gCharMemCursor
_0800536C: .4byte 0x06010000
_08005370:
	cmp r6, 0
	beq _08005382
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08005382
	lsls r0, 2
	add r0, r8
	ldr r2, [r0]
_08005382:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8004EA8
	adds r4, 0xA
_0800538E:
	movs r2, 0
	ldrh r1, [r4]
	ldr r0, _080053A8
	cmp r1, r0
	bne _08005370
	ldrh r0, [r4, 0x2]
	cmp r0, r1
	bne _08005370
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080053A8: .4byte 0x0000ffff
	thumb_func_end sub_800533C

	thumb_func_start sub_80053AC
sub_80053AC:
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r5, [sp, 0x1C]
	ldr r6, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [r1, 0x4]
	str r5, [sp]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	bl sub_80053D0
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80053AC

	thumb_func_start sub_80053D0
sub_80053D0:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x1C]
	lsls r0, 24
	movs r2, 0
	movs r3, 0x80
	lsls r3, 8
	strh r3, [r4]
	cmp r0, 0
	beq _080053F6
	movs r0, 0x80
	lsls r0, 5
	adds r1, r0, 0
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r4]
_080053F6:
	strh r2, [r4, 0x2]
	ldr r0, [sp, 0x18]
	strh r0, [r4, 0x4]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	ldr r0, [sp, 0x14]
	strh r0, [r4, 0x1C]
	ldr r0, _08005438
	strh r0, [r4, 0x20]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x22]
	str r2, [r4, 0x14]
	str r2, [r4, 0x18]
	strh r2, [r4, 0x6]
	ldr r1, [r5, 0x4]
	lsls r0, r6, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	ldr r0, [r5]
	str r0, [r4, 0x34]
	ldr r0, [r5, 0xC]
	str r0, [r4, 0x38]
	ldr r0, [r5, 0x10]
	str r0, [r4, 0x30]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005438: .4byte 0x0000ffff
	thumb_func_end sub_80053D0

	thumb_func_start sub_800543C
sub_800543C:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, [sp, 0x14]
	ldr r4, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [r1, 0x4]
	str r5, [sp]
	str r4, [sp, 0x4]
	bl sub_800545C
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800543C

	thumb_func_start sub_800545C
sub_800545C:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	ldr r0, [sp, 0x18]
	lsls r0, 24
	movs r2, 0
	movs r3, 0x80
	lsls r3, 8
	strh r3, [r4]
	cmp r0, 0
	beq _08005482
	movs r0, 0x80
	lsls r0, 5
	adds r1, r0, 0
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r4]
_08005482:
	strh r2, [r4, 0x2]
	ldr r0, [sp, 0x14]
	strh r0, [r4, 0x4]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	strh r5, [r4, 0x1C]
	ldr r0, _080054B8
	strh r0, [r4, 0x20]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x22]
	str r2, [r4, 0x14]
	str r2, [r4, 0x18]
	strh r2, [r4, 0x6]
	ldr r1, [r6, 0x4]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	ldr r0, [r6]
	str r0, [r4, 0x34]
	str r2, [r4, 0x30]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080054B8: .4byte 0x0000ffff
	thumb_func_end sub_800545C

	thumb_func_start sub_80054BC
sub_80054BC:
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _080054D0
	movs r0, 0
	b _080054D2
_080054D0:
	lsrs r0, r1, 15
_080054D2:
	cmp r0, 0
	beq _08005586
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	ldrh r3, [r4]
	cmp r0, 0
	blt _08005524
	movs r0, 0x80
	lsls r0, 7
	ands r0, r3
	cmp r0, 0
	bne _08005586
	ldrh r2, [r4, 0x6]
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	ldr r0, _0800550C
	cmp r1, r0
	bgt _080054FA
	adds r0, r2, 0x1
	strh r0, [r4, 0x6]
_080054FA:
	ldrh r1, [r4, 0x4]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08005510
	subs r0, r1, 0x1
	strh r0, [r4, 0x4]
	b _08005586
	.align 2, 0
_0800550C: .4byte 0x0000752f
_08005510:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08005524
	subs r0, r1, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _08005586
_08005524:
	ldr r0, [r4, 0x2C]
	ldrb r0, [r0]
	cmp r0, 0
	bne _08005550
	movs r0, 0x80
	lsls r0, 5
	ands r0, r3
	cmp r0, 0
	bne _08005542
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	orrs r0, r3
	strh r0, [r4]
	b _08005586
_08005542:
	ldr r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	bl Random
	movs r1, 0x1
	ands r0, r1
	strh r0, [r4, 0x4]
_08005550:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, [r4, 0x2C]
	ldrb r0, [r1]
	strh r0, [r4, 0x2]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0xE]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x10]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x12]
	ldrb r0, [r1, 0x1]
	str r0, [r4, 0x14]
	ldrb r2, [r1, 0x1]
	ldr r0, [r4, 0x18]
	orrs r0, r2
	str r0, [r4, 0x18]
	adds r1, 0xC
	str r1, [r4, 0x2C]
_08005586:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80054BC

	.align 2, 0 @ Don't pad with nop.
