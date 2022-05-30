        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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

        .align 2,0
