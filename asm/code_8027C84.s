        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8027CA0
sub_8027CA0:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08027CFA
	lsls r0, 2
	ldr r1, _08027CB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027CB8: .4byte _08027CBC
	.align 2, 0
_08027CBC:
	.4byte _08027CFA
	.4byte _08027CFA
	.4byte _08027CF0
	.4byte _08027CD0
	.4byte _08027CD0
_08027CD0:
	bl sub_801F194
	ldr r1, _08027CEC
	ldr r1, [r1]
	str r0, [r1, 0x20]
	lsls r0, 3
	adds r0, r1, r0
	ldrh r0, [r0, 0x2A]
	strh r0, [r1, 0x24]
	movs r0, 0x10
	bl sub_8027184
	b _08027CFA
	.align 2, 0
_08027CEC: .4byte gUnknown_203B2BC
_08027CF0:
	bl sub_801F214
	movs r0, 0x2
	bl sub_8027184
_08027CFA:
	pop {r0}
	bx r0
	thumb_func_end sub_8027CA0

	thumb_func_start sub_8027D00
sub_8027D00:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08027D18
	cmp r0, 0x3
	bhi _08027D18
	bl sub_801F8D0
	movs r0, 0xF
	bl sub_8027184
_08027D18:
	pop {r0}
	bx r0
	thumb_func_end sub_8027D00

	thumb_func_start sub_8027D1C
sub_8027D1C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08027D34
	ldr r0, _08027D3C
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_8027184
_08027D34:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08027D3C: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027D1C

	thumb_func_start sub_8027D40
sub_8027D40:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8008C54
	adds r0, r6, 0
	bl sub_80073B8
	add r4, sp, 0x10
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8090B64
	movs r5, 0
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	strb r5, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08027D94
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_8090E14
	ldr r2, _08027D98
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x3
	adds r3, r6, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08027D94: .4byte gUnknown_202DE58
_08027D98: .4byte gUnknown_80DD958
	thumb_func_end sub_8027D40

	thumb_func_start sub_8027D9C
sub_8027D9C:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08027DC0
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08027DB0
	movs r2, 0x1
_08027DB0:
	cmp r2, 0
	beq _08027DC4
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08027DC4
_08027DC0:
	movs r0, 0
	b _08027DC6
_08027DC4:
	movs r0, 0x1
_08027DC6:
	pop {r1}
	bx r1
	thumb_func_end sub_8027D9C

	thumb_func_start sub_8027DCC
sub_8027DCC:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	beq _08027E0E
	bl sub_808D3F8
	cmp r0, r4
	beq _08027E0E
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _08027E0E
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _08027DF0
	movs r1, 0x1
_08027DF0:
	cmp r1, 0
	beq _08027E00
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08027E0E
_08027E00:
	adds r0, r4, 0
	bl sub_8027E18
	cmp r0, 0x3
	beq _08027E0E
	movs r0, 0x1
	b _08027E10
_08027E0E:
	movs r0, 0
_08027E10:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8027DCC

	thumb_func_start sub_8027E18
sub_8027E18:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	bne _08027E28
	movs r0, 0
	b _08027E46
_08027E28:
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08027E34
	movs r0, 0x1
	b _08027E46
_08027E34:
	adds r0, r4, 0
	bl sub_8027E4C
	lsls r0, 24
	cmp r0, 0
	bne _08027E44
	movs r0, 0x3
	b _08027E46
_08027E44:
	movs r0, 0x2
_08027E46:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8027E18

	thumb_func_start sub_8027E4C
sub_8027E4C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x28
	ldrb r0, [r4]
	bl IsNotMoneyOrUsedTMItem
	lsls r0, 24
	cmp r0, 0
	beq _08027E88
	ldrb r0, [r4]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08027E94
	ldr r0, _08027E8C
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	adds r1, r0
	ldr r0, _08027E90
	cmp r1, r0
	ble _08027EA8
_08027E88:
	movs r0, 0
	b _08027EAA
	.align 2, 0
_08027E8C: .4byte gTeamInventory_203B460
_08027E90: .4byte 0x000003e7
_08027E94:
	ldr r0, _08027EB0
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	ldr r0, _08027EB4
	cmp r1, r0
	bhi _08027E88
_08027EA8:
	movs r0, 0x1
_08027EAA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08027EB0: .4byte gTeamInventory_203B460
_08027EB4: .4byte 0x000003e6
	thumb_func_end sub_8027E4C

	thumb_func_start sub_8027EB8
sub_8027EB8:
	push {r4,lr}
	ldr r4, _08027ED4
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_8027E18
	cmp r0, 0x1
	beq _08027ED8
	cmp r0, 0x1
	bcc _08027F7C
	cmp r0, 0x2
	beq _08027F0C
	b _08027F7C
	.align 2, 0
_08027ED4: .4byte gUnknown_203B2BC
_08027ED8:
	ldr r0, _08027F08
	bl PlaySound
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_8091274
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0x6
	bl sub_8027184
	b _08027F82
	.align 2, 0
_08027F08: .4byte 0x0000014d
_08027F0C:
	ldr r0, _08027F38
	bl PlaySound
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08027F40
	ldr r0, _08027F3C
	ldr r1, [r0]
	ldr r2, [r4]
	ldrb r0, [r2, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	ldrb r2, [r2, 0x15]
	adds r0, r2
	b _08027F52
	.align 2, 0
_08027F38: .4byte 0x0000014d
_08027F3C: .4byte gTeamInventory_203B460
_08027F40:
	ldr r0, _08027F74
	ldr r1, [r0]
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
_08027F52:
	strh r0, [r1]
	ldr r1, _08027F78
	ldr r0, [r1]
	movs r2, 0
	strb r2, [r0, 0x14]
	ldr r0, [r1]
	strb r2, [r0, 0x15]
	ldr r1, [r1]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0x7
	bl sub_8027184
	b _08027F82
	.align 2, 0
_08027F74: .4byte gTeamInventory_203B460
_08027F78: .4byte gUnknown_203B2BC
_08027F7C:
	movs r0, 0x2
	bl sub_8027184
_08027F82:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027EB8


        .align 2,0
