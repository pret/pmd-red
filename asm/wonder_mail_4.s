        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start sub_80306A8
sub_80306A8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	mov r8, r3
	bl sub_8030C20
	lsls r0, 24
	cmp r0, 0
	beq _080306C4
	movs r0, 0
	b _08030756
_080306C4:
	ldr r6, _08030760
	movs r0, 0xC4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	str r4, [r0, 0x20]
	str r5, [r0, 0x58]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x60
	adds r1, r0, r1
	str r1, [r0, 0x5C]
	adds r0, 0x60
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x58]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x60
	ldr r0, _08030764
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	ldr r1, [r2, 0x5C]
	adds r0, r2, 0
	adds r0, 0xC0
	str r0, [r1, 0x14]
	cmp r7, 0
	beq _0803071E
	ldr r1, [r2, 0x58]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x68
	adds r1, r0
	ldr r0, [r7]
	str r0, [r1]
_0803071E:
	ldr r0, [r6]
	ldr r0, [r0, 0x5C]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r6]
	adds r4, 0x24
	bl sub_8030A74
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_80308A0
	bl sub_803092C
	movs r0, 0x1
_08030756:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08030760: .4byte gUnknown_203B320
_08030764: .4byte gUnknown_80E0854
	thumb_func_end sub_80306A8

	thumb_func_start sub_8030768
sub_8030768:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _08030784
	ldr r0, _08030780
	ldr r0, [r0]
	adds r0, 0x24
	bl sub_8013660
	movs r0, 0
	b _080307E6
	.align 2, 0
_08030780: .4byte gUnknown_203B320
_08030784:
	ldr r0, _0803079C
	ldr r0, [r0]
	adds r0, 0x24
	bl GetKeyPress
	cmp r0, 0x2
	beq _080307AE
	cmp r0, 0x2
	bgt _080307A0
	cmp r0, 0x1
	beq _080307B8
	b _080307C2
	.align 2, 0
_0803079C: .4byte gUnknown_203B320
_080307A0:
	cmp r0, 0x4
	bne _080307C2
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _080307E6
_080307AE:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _080307E6
_080307B8:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _080307E6
_080307C2:
	ldr r0, _080307D8
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _080307DC
	movs r0, 0
	b _080307E6
	.align 2, 0
_080307D8: .4byte gUnknown_203B320
_080307DC:
	bl sub_80308A0
	bl sub_803092C
	movs r0, 0x1
_080307E6:
	pop {r1}
	bx r1
	thumb_func_end sub_8030768

	thumb_func_start sub_80307EC
sub_80307EC:
	ldr r0, _0803080C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	movs r3, 0x3C
	ldrsh r1, [r2, r3]
	adds r0, r1
	adds r2, r0
	ldrb r0, [r2]
	bx lr
	.align 2, 0
_0803080C: .4byte gUnknown_203B320
	thumb_func_end sub_80307EC

	thumb_func_start sub_8030810
sub_8030810:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8030A74
	adds r1, r0, 0
	ldr r5, _08030848
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x46
	strh r1, [r2]
	adds r0, 0x24
	bl sub_8013984
	bl sub_80308A0
	bl sub_803092C
	cmp r4, 0
	beq _08030842
	ldr r0, [r5]
	adds r0, 0x24
	bl AddMenuCursorSprite
_08030842:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030848: .4byte gUnknown_203B320
	thumb_func_end sub_8030810

	thumb_func_start sub_803084C
sub_803084C:
	push {r4,r5,lr}
	ldr r4, _0803088C
	ldr r2, [r4]
	cmp r2, 0
	beq _08030886
	ldr r0, [r2, 0x58]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x60
	ldr r0, _08030890
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08030886:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803088C: .4byte gUnknown_203B320
_08030890: .4byte gUnknown_80E083C
	thumb_func_end sub_803084C

	thumb_func_start sub_8030894
sub_8030894:
	ldr r0, _0803089C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0803089C: .4byte gUnknown_203B320
	thumb_func_end sub_8030894

	thumb_func_start sub_80308A0
sub_80308A0:
	push {r4,lr}
	ldr r4, _08030928
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x44
	ldrh r1, [r1]
	adds r0, 0xC0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x42
	ldrh r1, [r1]
	adds r0, 0xC1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC2
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC3
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6E
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x58]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x70
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030928: .4byte gUnknown_203B320
	thumb_func_end sub_80308A0

	thumb_func_start sub_803092C
sub_803092C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x60
	ldr r7, _08030A24
	ldr r0, [r7]
	ldr r0, [r0, 0x58]
	bl sub_8008C54
	ldr r0, [r7]
	ldr r0, [r0, 0x58]
	bl sub_80073B8
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x42
	movs r2, 0
	ldrsh r4, [r0, r2]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _08030A28
	ldr r0, [r1, 0x20]
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0]
	ldr r3, [r1, 0x58]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r3, [r7]
	adds r0, r3, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	adds r0, r3, 0
	adds r0, 0x42
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r3, 0x58]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r6, 0
	ldr r0, [r7]
	movs r2, 0x3E
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _08030A56
	mov r9, r7
	mov r8, r6
	add r7, sp, 0x8
	mov r5, sp
	adds r5, 0x4B
_080309B0:
	mov r3, r9
	ldr r1, [r3]
	adds r0, r1, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r2, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	adds r0, r6
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8095228
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r0, 0x58]
	str r1, [sp, 0x8]
	adds r0, 0x24
	adds r1, r6, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	add r1, sp, 0x48
	movs r0, 0x7
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x4A
	mov r2, r8
	strb r2, [r0]
	add r0, sp, 0x4C
	strb r2, [r0]
	adds r0, r4, 0x4
	str r0, [sp, 0x10]
	adds r0, 0x10
	str r0, [sp, 0x14]
	ldrh r0, [r4, 0xC]
	strh r0, [r7, 0x10]
	ldrh r0, [r4, 0xC]
	strh r0, [r7, 0x12]
	strb r2, [r7, 0x14]
	subs r1, 0x12
	movs r0, 0x5
	strb r0, [r1]
	ldrb r0, [r4]
	cmp r0, 0x4
	beq _08030A32
	cmp r0, 0x4
	bgt _08030A2C
	cmp r0, 0x2
	bgt _08030A3E
	cmp r0, 0x1
	blt _08030A3E
	movs r0, 0x1
	strb r0, [r5]
	b _08030A42
	.align 2, 0
_08030A24: .4byte gUnknown_203B320
_08030A28: .4byte gUnknown_80E086C
_08030A2C:
	cmp r0, 0x5
	beq _08030A38
	b _08030A3E
_08030A32:
	movs r0, 0x3
	strb r0, [r5]
	b _08030A42
_08030A38:
	movs r0, 0x4
	strb r0, [r5]
	b _08030A42
_08030A3E:
	mov r3, r8
	strb r3, [r5]
_08030A42:
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r6, 0x1
	mov r1, r9
	ldr r0, [r1]
	movs r2, 0x3E
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _080309B0
_08030A56:
	ldr r0, _08030A70
	ldr r0, [r0]
	ldr r0, [r0, 0x58]
	bl sub_80073E0
	add sp, 0x60
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030A70: .4byte gUnknown_203B320
	thumb_func_end sub_803092C

	thumb_func_start sub_8030A74
sub_8030A74:
	push {r4,r5,lr}
	movs r2, 0
	ldr r0, _08030A90
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	cmp r0, 0x7
	bls _08030A84
	b _08030C0E
_08030A84:
	lsls r0, 2
	ldr r1, _08030A94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030A90: .4byte gUnknown_203B320
_08030A94: .4byte _08030A98
	.align 2, 0
_08030A98:
	.4byte _08030AB8
	.4byte _08030B10
	.4byte _08030B3C
	.4byte _08030B94
	.4byte _08030B68
	.4byte _08030BC0
	.4byte _08030AE4
	.4byte _08030BEC
_08030AB8:
	movs r1, 0
	ldr r5, _08030ADC
	ldr r4, _08030AE0
	movs r3, 0
_08030AC0:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08030AD2
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030AD2:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030AC0
	b _08030C0E
	.align 2, 0
_08030ADC: .4byte gUnknown_203B480
_08030AE0: .4byte gUnknown_203B320
_08030AE4:
	movs r1, 0
	ldr r5, _08030B08
	ldr r4, _08030B0C
	movs r3, 0
_08030AEC:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08030AFE
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030AFE:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030AEC
	b _08030C0E
	.align 2, 0
_08030B08: .4byte gUnknown_203B480
_08030B0C: .4byte gUnknown_203B320
_08030B10:
	movs r1, 0
	ldr r5, _08030B34
	ldr r4, _08030B38
	movs r3, 0
_08030B18:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08030B2A
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B2A:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B18
	b _08030C0E
	.align 2, 0
_08030B34: .4byte gUnknown_203B480
_08030B38: .4byte gUnknown_203B320
_08030B3C:
	movs r1, 0
	ldr r5, _08030B60
	ldr r4, _08030B64
	movs r3, 0
_08030B44:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08030B56
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B56:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B44
	b _08030C0E
	.align 2, 0
_08030B60: .4byte gUnknown_203B480
_08030B64: .4byte gUnknown_203B320
_08030B68:
	movs r1, 0
	ldr r5, _08030B8C
	ldr r4, _08030B90
	movs r3, 0
_08030B70:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08030B82
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030B82:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B70
	b _08030C0E
	.align 2, 0
_08030B8C: .4byte gUnknown_203B480
_08030B90: .4byte gUnknown_203B320
_08030B94:
	movs r1, 0
	ldr r5, _08030BB8
	ldr r4, _08030BBC
	movs r3, 0
_08030B9C:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _08030BAE
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030BAE:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030B9C
	b _08030C0E
	.align 2, 0
_08030BB8: .4byte gUnknown_203B480
_08030BBC: .4byte gUnknown_203B320
_08030BC0:
	movs r1, 0
	ldr r5, _08030BE4
	ldr r4, _08030BE8
	movs r3, 0
_08030BC8:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _08030BDA
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030BDA:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030BC8
	b _08030C0E
	.align 2, 0
_08030BE4: .4byte gUnknown_203B480
_08030BE8: .4byte gUnknown_203B320
_08030BEC:
	movs r1, 0
	ldr r5, _08030C18
	ldr r4, _08030C1C
	movs r3, 0
_08030BF4:
	ldr r0, [r5]
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08030C06
	ldr r0, [r4]
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
_08030C06:
	adds r3, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030BF4
_08030C0E:
	adds r0, r2, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08030C18: .4byte gUnknown_203B480
_08030C1C: .4byte gUnknown_203B320
	thumb_func_end sub_8030A74

	thumb_func_start sub_8030C20
sub_8030C20:
	push {lr}
	cmp r0, 0x7
	bls _08030C28
	b _08030D34
_08030C28:
	lsls r0, 2
	ldr r1, _08030C34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030C34: .4byte _08030C38
	.align 2, 0
_08030C38:
	.4byte _08030C58
	.4byte _08030C90
	.4byte _08030CAC
	.4byte _08030CE4
	.4byte _08030CC8
	.4byte _08030D00
	.4byte _08030C74
	.4byte _08030D20
_08030C58:
	movs r1, 0
	ldr r0, _08030C70
	ldr r2, [r0]
_08030C5E:
	ldrb r0, [r2]
	cmp r0, 0
	bne _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C5E
	b _08030D34
	.align 2, 0
_08030C70: .4byte gUnknown_203B480
_08030C74:
	movs r1, 0
	ldr r0, _08030C8C
	ldr r2, [r0]
_08030C7A:
	ldrb r0, [r2]
	cmp r0, 0x6
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C7A
	b _08030D34
	.align 2, 0
_08030C8C: .4byte gUnknown_203B480
_08030C90:
	movs r1, 0
	ldr r0, _08030CA8
	ldr r2, [r0]
_08030C96:
	ldrb r0, [r2]
	cmp r0, 0x1
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030C96
	b _08030D34
	.align 2, 0
_08030CA8: .4byte gUnknown_203B480
_08030CAC:
	movs r1, 0
	ldr r0, _08030CC4
	ldr r2, [r0]
_08030CB2:
	ldrb r0, [r2]
	cmp r0, 0x2
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CB2
	b _08030D34
	.align 2, 0
_08030CC4: .4byte gUnknown_203B480
_08030CC8:
	movs r1, 0
	ldr r0, _08030CE0
	ldr r2, [r0]
_08030CCE:
	ldrb r0, [r2]
	cmp r0, 0x4
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CCE
	b _08030D34
	.align 2, 0
_08030CE0: .4byte gUnknown_203B480
_08030CE4:
	movs r1, 0
	ldr r0, _08030CFC
	ldr r2, [r0]
_08030CEA:
	ldrb r0, [r2]
	cmp r0, 0x3
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030CEA
	b _08030D34
	.align 2, 0
_08030CFC: .4byte gUnknown_203B480
_08030D00:
	movs r1, 0
	ldr r0, _08030D18
	ldr r2, [r0]
_08030D06:
	ldrb r0, [r2]
	cmp r0, 0x5
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030D06
	b _08030D34
	.align 2, 0
_08030D18: .4byte gUnknown_203B480
_08030D1C:
	movs r0, 0
	b _08030D36
_08030D20:
	movs r1, 0
	ldr r0, _08030D3C
	ldr r2, [r0]
_08030D26:
	ldrb r0, [r2]
	cmp r0, 0x7
	beq _08030D1C
	adds r2, 0x30
	adds r1, 0x1
	cmp r1, 0x1F
	ble _08030D26
_08030D34:
	movs r0, 0x1
_08030D36:
	pop {r1}
	bx r1
	.align 2, 0
_08030D3C: .4byte gUnknown_203B480
	thumb_func_end sub_8030C20

	thumb_func_start sub_8030D40
sub_8030D40:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, _08030D98
	movs r0, 0x78
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	bl sub_801317C
	ldr r0, [r6]
	str r5, [r0, 0x10]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08030D9C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8030DD4
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08030D98: .4byte gUnknown_203B324
_08030D9C: .4byte gUnknown_80E091C
	thumb_func_end sub_8030D40

	thumb_func_start sub_8030DA0
sub_8030DA0:
	push {lr}
	ldr r0, _08030DC0
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08030DC4
	cmp r0, 0x2
	bne _08030DCE
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08030DD0
	.align 2, 0
_08030DC0: .4byte gUnknown_203B324
_08030DC4:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08030DD0
_08030DCE:
	movs r0, 0
_08030DD0:
	pop {r1}
	bx r1
	thumb_func_end sub_8030DA0

	thumb_func_start sub_8030DD4
sub_8030DD4:
	push {lr}
	bl sub_8030E2C
	bl sub_8030E48
	pop {r0}
	bx r0
	thumb_func_end sub_8030DD4

	thumb_func_start sub_8030DE4
sub_8030DE4:
	push {r4,r5,lr}
	ldr r4, _08030E24
	ldr r2, [r4]
	cmp r2, 0
	beq _08030E1E
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08030E28
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08030E1E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030E24: .4byte gUnknown_203B324
_08030E28: .4byte gUnknown_80E0900
	thumb_func_end sub_8030DE4

	thumb_func_start sub_8030E2C
sub_8030E2C:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08030E44
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08030E44: .4byte gUnknown_203B324
	thumb_func_end sub_8030E2C

	thumb_func_start sub_8030E48
sub_8030E48:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x15C
	ldr r3, _08030EA8
	ldr r4, _08030EAC
	ldr r2, [r4]
	ldrb r1, [r2, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r0, [r2, 0x10]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	str r0, [sp, 0x4]
	add r1, sp, 0x44
	movs r2, 0
	movs r0, 0x7
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x46
	strb r2, [r0]
	add r0, sp, 0x48
	strb r2, [r0]
	adds r0, r5, 0x4
	str r0, [sp, 0xC]
	adds r0, 0x10
	str r0, [sp, 0x10]
	add r1, sp, 0x4
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x10]
	ldrh r0, [r5, 0xC]
	strh r0, [r1, 0x12]
	adds r0, r1, 0
	strb r2, [r0, 0x14]
	adds r2, r5, 0
	adds r2, 0x22
	ldrb r0, [r2]
	cmp r0, 0
	bne _08030EB0
	adds r1, 0x2E
	movs r0, 0x5
	strb r0, [r1]
	b _08030EBE
	.align 2, 0
_08030EA8: .4byte gUnknown_203B480
_08030EAC: .4byte gUnknown_203B324
_08030EB0:
	mov r1, sp
	adds r1, 0x32
	movs r0, 0x2
	strb r0, [r1]
	ldrb r1, [r2]
	add r0, sp, 0x38
	strb r1, [r0]
_08030EBE:
	ldrb r0, [r5]
	cmp r0, 0x2
	beq _08030ED2
	cmp r0, 0x2
	ble _08030EE2
	cmp r0, 0x4
	beq _08030ED2
	cmp r0, 0x5
	beq _08030EDA
	b _08030EE2
_08030ED2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xA
	b _08030EE8
_08030EDA:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0xB
	b _08030EE8
_08030EE2:
	mov r1, sp
	adds r1, 0x45
	movs r0, 0x9
_08030EE8:
	strb r0, [r1]
	add r0, sp, 0x4
	bl CreateRescueDescription
	ldrh r0, [r5, 0x10]
	ldr r1, _08030F48
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r2, _08030F4C
	ldr r5, _08030F50
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0x68
	bl xxx_call_draw_string
	add r6, sp, 0x5C
	ldr r1, _08030F54
	adds r0, r6, 0
	adds r2, r4, 0
	bl sub_800D158
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x44
	movs r1, 0x68
	adds r2, r6, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0x15C
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030F48: .4byte 0x00002710
_08030F4C: .4byte gUnknown_80E0934
_08030F50: .4byte gUnknown_203B324
_08030F54: .4byte gUnknown_80E0938
	thumb_func_end sub_8030E48

	thumb_func_start sub_8030F58
sub_8030F58:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08030FF4
	ldr r0, [r5]
	cmp r0, 0
	bne _08030F88
	movs r4, 0x8E
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08030F88:
	ldr r0, [r5]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	str r6, [r0]
	movs r0, 0x98
	lsls r0, 1
	bl GetDialogueSpriteDataPtr
	ldr r2, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	str r0, [r1]
	movs r3, 0x86
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r0, 0x8A
	lsls r0, 1
	adds r2, r0
	movs r1, 0
	strb r1, [r2]
	ldr r0, [r5]
	ldr r2, _08030FF8
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, 0xA
	adds r0, r3
	strb r1, [r0]
	ldr r2, [r5]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x4
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_8030C20
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _08031038
	cmp r6, 0x2
	beq _08030FFC
	cmp r6, 0x4
	beq _08031014
	b _08031022
	.align 2, 0
_08030FF4: .4byte gUnknown_203B328
_08030FF8: .4byte 0x00000115
_08030FFC:
	ldr r0, _0803100C
	ldr r2, [r5]
	adds r2, r4
	ldr r3, _08031010
	movs r1, 0
	bl sub_80141B4
	b _08031022
	.align 2, 0
_0803100C: .4byte gUnknown_80E09D8
_08031010: .4byte 0x00000101
_08031014:
	ldr r0, _0803102C
	ldr r2, [r5]
	adds r2, r4
	ldr r3, _08031030
	movs r1, 0
	bl sub_80141B4
_08031022:
	ldr r0, _08031034
	ldr r1, [r0]
	movs r0, 0x5
	str r0, [r1]
	b _08031048
	.align 2, 0
_0803102C: .4byte gUnknown_80E0A0C
_08031030: .4byte 0x00000101
_08031034: .4byte gUnknown_203B328
_08031038:
	ldr r0, [r5]
	str r1, [r0]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x8
	bl sub_80306A8
_08031048:
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8030F58

	thumb_func_start sub_8031050
sub_8031050:
	push {lr}
	ldr r1, _08031068
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x6
	bhi _080310AC
	lsls r0, 2
	ldr r1, _0803106C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031068: .4byte gUnknown_203B328
_0803106C: .4byte _08031070
	.align 2, 0
_08031070:
	.4byte _0803108C
	.4byte _08031092
	.4byte _08031098
	.4byte _08031098
	.4byte _080310A2
	.4byte _080310A8
	.4byte _080310A8
_0803108C:
	bl sub_8031300
	b _080310AC
_08031092:
	bl sub_803136C
	b _080310AC
_08031098:
	ldr r0, [r2]
	ldr r0, [r0]
	bl sub_80313D8
	b _080310AC
_080310A2:
	bl sub_8031498
	b _080310AC
_080310A8:
	movs r0, 0x3
	b _080310AE
_080310AC:
	movs r0, 0
_080310AE:
	pop {r1}
	bx r1
	thumb_func_end sub_8031050

	thumb_func_start sub_80310B4
sub_80310B4:
	push {r4,lr}
	bl sub_803084C
	ldr r4, _080310E0
	ldr r0, [r4]
	cmp r0, 0
	beq _080310D8
	movs r1, 0x84
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080310D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080310E0: .4byte gUnknown_203B328
	thumb_func_end sub_80310B4

	thumb_func_start sub_80310E4
sub_80310E4:
	push {lr}
	ldr r1, _080310F8
	ldr r1, [r1]
	str r0, [r1]
	bl sub_80310FC
	bl sub_8031258
	pop {r0}
	bx r0
	.align 2, 0
_080310F8: .4byte gUnknown_203B328
	thumb_func_end sub_80310E4

	thumb_func_start sub_80310FC
sub_80310FC:
	push {r4-r6,lr}
	ldr r4, _0803111C
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x6
	bls _08031112
	b _0803122C
_08031112:
	lsls r0, 2
	ldr r1, _08031120
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803111C: .4byte gUnknown_203B328
_08031120: .4byte _08031124
	.align 2, 0
_08031124:
	.4byte _08031140
	.4byte _08031178
	.4byte _080311C0
	.4byte _080311C0
	.4byte _080311E8
	.4byte _0803122C
	.4byte _0803122C
_08031140:
	ldr r3, _08031170
	ldr r1, [r3]
	ldr r2, _08031174
	adds r1, 0xC0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r3,r4}
	stm r0!, {r1,r3,r4}
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	b _0803123A
	.align 2, 0
_08031170: .4byte gUnknown_203B328
_08031174: .4byte gUnknown_80E0990
_08031178:
	ldr r3, _080311B0
	ldr r1, [r3]
	adds r1, 0xC0
	ldr r0, _080311B4
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldr r1, [r3]
	ldr r2, _080311B8
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	ldm r2!, {r4-r6}
	stm r0!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xC0
	ldr r1, _080311BC
	bl sub_8012CAC
	b _0803123A
	.align 2, 0
_080311B0: .4byte gUnknown_203B328
_080311B4: .4byte gUnknown_80E09A8
_080311B8: .4byte gUnknown_80E0990
_080311BC: .4byte gUnknown_80E0968
_080311C0:
	ldr r2, _080311DC
	ldr r1, [r2]
	adds r1, 0xD8
	ldr r0, _080311E0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	ldr r0, [r2]
	adds r0, 0xD8
	ldr r1, _080311E4
	bl sub_8012CAC
	b _0803123A
	.align 2, 0
_080311DC: .4byte gUnknown_203B328
_080311E0: .4byte gUnknown_80E09C0
_080311E4: .4byte gUnknown_80E0948
_080311E8:
	ldr r3, _08031224
	ldr r1, [r3]
	ldr r2, _08031228
	adds r1, 0xA8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xC0
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r1, [r3]
	adds r1, 0xD8
	adds r0, r2, 0
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r0, 0xF0
	ldm r2!, {r1,r5,r6}
	stm r0!, {r1,r5,r6}
	ldm r2!, {r3-r5}
	stm r0!, {r3-r5}
	b _0803123A
	.align 2, 0
_08031224: .4byte gUnknown_203B328
_08031228: .4byte gUnknown_80E0990
_0803122C:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0803123A:
	bl ResetUnusedInputStruct
	ldr r0, _08031254
	ldr r0, [r0]
	adds r0, 0xA8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031254: .4byte gUnknown_203B328
	thumb_func_end sub_80310FC

	thumb_func_start sub_8031258
sub_8031258:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _08031274
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x6
	bhi _080312F6
	lsls r0, 2
	ldr r1, _08031278
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031274: .4byte gUnknown_203B328
_08031278: .4byte _0803127C
	.align 2, 0
_0803127C:
	.4byte _08031298
	.4byte _080312A0
	.4byte _080312BC
	.4byte _080312BC
	.4byte _080312EC
	.4byte _080312F6
	.4byte _080312F6
_08031298:
	movs r0, 0x1
	bl sub_8030810
	b _080312F6
_080312A0:
	bl sub_803092C
	ldr r0, _080312B4
	ldr r0, [r0]
	adds r0, 0x8
	ldr r1, _080312B8
	movs r2, 0x4
	str r2, [sp]
	movs r2, 0x1
	b _080312D8
	.align 2, 0
_080312B4: .4byte gUnknown_203B328
_080312B8: .4byte gUnknown_80E0968
_080312BC:
	bl sub_803092C
	ldr r4, _080312E4
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	bl sub_8012EA4
	ldr r0, [r4]
	adds r0, 0x58
	ldr r1, _080312E8
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x2
_080312D8:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _080312F6
	.align 2, 0
_080312E4: .4byte gUnknown_203B328
_080312E8: .4byte gUnknown_80E0948
_080312EC:
	ldr r0, [r2]
	ldrb r0, [r0, 0x4]
	movs r1, 0x3
	bl sub_8030D40
_080312F6:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8031258

	thumb_func_start sub_8031300
sub_8031300:
	push {lr}
	movs r0, 0x1
	bl sub_8030768
	cmp r0, 0x4
	bhi _08031366
	lsls r0, 2
	ldr r1, _08031318
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031318: .4byte _0803131C
	.align 2, 0
_0803131C:
	.4byte _08031366
	.4byte _08031366
	.4byte _08031360
	.4byte _08031330
	.4byte _08031348
_08031330:
	bl sub_80307EC
	ldr r1, _08031344
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x1
	bl sub_80310E4
	b _08031366
	.align 2, 0
_08031344: .4byte gUnknown_203B328
_08031348:
	bl sub_80307EC
	ldr r1, _0803135C
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x4
	bl sub_80310E4
	b _08031366
	.align 2, 0
_0803135C: .4byte gUnknown_203B328
_08031360:
	movs r0, 0x6
	bl sub_80310E4
_08031366:
	pop {r0}
	bx r0
	thumb_func_end sub_8031300

	thumb_func_start sub_803136C
sub_803136C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8030768
	ldr r4, _080313A4
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08031392
	ldr r0, [r4]
	adds r0, 0x8
	mov r1, sp
	bl sub_8013114
_08031392:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080313C2
	cmp r0, 0x4
	bgt _080313A8
	cmp r0, 0x1
	beq _080313B2
	b _080313D0
	.align 2, 0
_080313A4: .4byte gUnknown_203B328
_080313A8:
	cmp r0, 0x5
	beq _080313CA
	cmp r0, 0x6
	beq _080313BA
	b _080313D0
_080313B2:
	movs r0, 0
	bl sub_80310E4
	b _080313D0
_080313BA:
	movs r0, 0x3
	bl sub_80310E4
	b _080313D0
_080313C2:
	movs r0, 0x2
	bl sub_80310E4
	b _080313D0
_080313CA:
	movs r0, 0x4
	bl sub_80310E4
_080313D0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803136C

	thumb_func_start sub_80313D8
sub_80313D8:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r0, 0
	str r0, [sp]
	bl sub_8030768
	ldr r4, _08031418
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08031408
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
_08031408:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08031428
	cmp r0, 0x2
	bgt _0803141C
	cmp r0, 0x1
	beq _08031420
	b _0803148E
	.align 2, 0
_08031418: .4byte gUnknown_203B328
_0803141C:
	cmp r0, 0x3
	bne _0803148E
_08031420:
	movs r0, 0
	bl sub_80310E4
	b _0803148E
_08031428:
	cmp r5, 0x2
	beq _08031432
	cmp r5, 0x3
	beq _0803143C
	b _0803145A
_08031432:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl sub_8095240
	b _0803145A
_0803143C:
	ldr r4, _08031480
	movs r3, 0
	movs r1, 0
	movs r2, 0x1F
_08031444:
	ldr r0, [r4]
	adds r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x22
	strb r3, [r0]
	adds r1, 0x30
	subs r2, 0x1
	cmp r2, 0
	bge _08031444
_0803145A:
	ldr r0, _08031484
	ldr r0, [r0]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x2
	beq _0803146E
	cmp r0, 0x4
	bne _0803148E
_0803146E:
	bl sub_8030C20
	lsls r0, 24
	cmp r0, 0
	beq _08031488
	movs r0, 0x5
	bl sub_80310E4
	b _0803148E
	.align 2, 0
_08031480: .4byte gUnknown_203B480
_08031484: .4byte gUnknown_203B328
_08031488:
	movs r0, 0
	bl sub_80310E4
_0803148E:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80313D8

	thumb_func_start sub_8031498
sub_8031498:
	push {lr}
	bl sub_8030DA0
	cmp r0, 0x1
	bls _080314B0
	cmp r0, 0x3
	bhi _080314B0
	bl sub_8030DE4
	movs r0, 0
	bl sub_80310E4
_080314B0:
	pop {r0}
	bx r0
	thumb_func_end sub_8031498
