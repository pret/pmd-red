        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80369D0
sub_80369D0:
	ldr r0, _080369F4
	ldr r2, [r0]
	ldr r0, _080369F8
	ldr r1, [r0]
	movs r3, 0x95
	lsls r3, 2
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, 1
	adds r2, 0x50
	adds r2, r0
	ldrh r0, [r2]
	adds r3, 0x4
	adds r1, r3
	ldr r1, [r1]
	adds r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_080369F4: .4byte gUnknown_203B460
_080369F8: .4byte gUnknown_203B358
	thumb_func_end sub_80369D0

	thumb_func_start sub_80369FC
sub_80369FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A10
	movs r0, 0
	bl SetTradeItemMenu
_08036A10:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80369FC

	thumb_func_start sub_8036A18
sub_8036A18:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A2C
	movs r0, 0x12
	bl SetTradeItemMenu
_08036A2C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A18

	thumb_func_start sub_8036A34
sub_8036A34:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A4E
	movs r0, 0x10
	bl SetTradeItemMenu
	movs r0, 0
	bl sub_8012574
_08036A4E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A34

	thumb_func_start sub_8036A54
sub_8036A54:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A76
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036A76
	bl sub_8012750
	movs r0, 0x12
	bl SetTradeItemMenu
_08036A76:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A54

	thumb_func_start sub_8036A7C
sub_8036A7C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036A9E
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036A9E
	bl sub_8012750
	movs r0, 0x8
	bl SetTradeItemMenu
_08036A9E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036A7C

	thumb_func_start sub_8036AA4
sub_8036AA4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036AD0
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036AD0
	bl sub_8012750
	ldr r0, _08036AD8
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bl sub_8036E18
	movs r0, 0xC
	bl SetTradeItemMenu
_08036AD0:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08036AD8: .4byte gUnknown_203B358
	thumb_func_end sub_8036AA4

	thumb_func_start sub_8036ADC
sub_8036ADC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08036AFE
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	bne _08036AFE
	bl sub_8012750
	movs r0, 0x12
	bl SetTradeItemMenu
_08036AFE:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8036ADC

	thumb_func_start CleanTradeItemsMenu
CleanTradeItemsMenu:
	push {r4,lr}
	ldr r4, _08036B20
	ldr r0, [r4]
	cmp r0, 0
	beq _08036B1A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	bl sub_801CBB8
_08036B1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036B20: .4byte gUnknown_203B358
	thumb_func_end CleanTradeItemsMenu

	thumb_func_start nullsub_52
nullsub_52:
	bx lr
	thumb_func_end nullsub_52

	thumb_func_start sub_8036B28
sub_8036B28:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _08036B44
	ldr r0, [r1]
	ldr r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x12
	bls _08036B3A
	b _08036DFA
_08036B3A:
	lsls r0, 2
	ldr r1, _08036B48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036B44: .4byte gUnknown_203B358
_08036B48: .4byte _08036B4C
	.align 2, 0
_08036B4C:
	.4byte _08036B98
	.4byte _08036BDC
	.4byte _08036BE4
	.4byte _08036C14
	.4byte _08036C58
	.4byte _08036DFA
	.4byte _08036C5E
	.4byte _08036C90
	.4byte _08036C98
	.4byte _08036CC0
	.4byte _08036CD8
	.4byte _08036DFA
	.4byte _08036DFA
	.4byte _08036DD8
	.4byte _08036D70
	.4byte _08036DFA
	.4byte _08036DFA
	.4byte _08036DFA
	.4byte _08036DFA
_08036B98:
	movs r0, 0
	bl sub_801CF14
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08036BB8
	ldr r0, _08036BB0
	ldr r3, _08036BB4
	movs r2, 0
	b _08036BBC
	.align 2, 0
_08036BB0: .4byte gUnknown_80E61A4
_08036BB4: .4byte gUnknown_80E60D4
_08036BB8:
	ldr r0, _08036BD4
	ldr r3, _08036BD8
_08036BBC:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x1
	bl sub_8014248
	b _08036DFA
	.align 2, 0
_08036BD4: .4byte gUnknown_80E61A4
_08036BD8: .4byte gUnknown_80E60A0
_08036BDC:
	ldr r0, _08036BE0
	b _08036DBA
	.align 2, 0
_08036BE0: .4byte gUnknown_80E61C0
_08036BE4:
	bl sub_801D008
	cmp r0, 0
	beq _08036BEE
	b _08036DFA
_08036BEE:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, _08036C10
	str r0, [sp, 0x14]
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0x14
	movs r3, 0x9
	bl sub_801C8C4
	b _08036DFA
	.align 2, 0
_08036C10: .4byte 0x00020003
_08036C14:
	ldr r0, [r5]
	movs r4, 0xC2
	lsls r4, 1
	adds r0, r4
	bl sub_8006518
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x44
	adds r1, r4
	ldr r3, _08036C50
	ldr r2, _08036C54
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_801CCD8
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	b _08036DFA
	.align 2, 0
_08036C50: .4byte gUnknown_80E60EC
_08036C54: .4byte gUnknown_80E6104
_08036C58:
	bl sub_8036F74
	b _08036DFA
_08036C5E:
	ldr r2, _08036C7C
	ldr r1, [r5]
	ldr r0, [r1, 0x14]
	str r0, [r2]
	ldr r0, _08036C80
	ldr r2, _08036C84
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
	ldr r0, _08036C88
	ldr r3, _08036C8C
	b _08036C9C
	.align 2, 0
_08036C7C: .4byte gUnknown_202DE30
_08036C80: .4byte gUnknown_202DE58
_08036C84: .4byte 0x0000025e
_08036C88: .4byte gUnknown_80E61E4
_08036C8C: .4byte gUnknown_80E6154
_08036C90:
	ldr r0, _08036C94
	b _08036C9A
	.align 2, 0
_08036C94: .4byte gUnknown_80E6214
_08036C98:
	ldr r0, _08036CB8
_08036C9A:
	ldr r3, _08036CBC
_08036C9C:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _08036DFA
	.align 2, 0
_08036CB8: .4byte gUnknown_80E6268
_08036CBC: .4byte gUnknown_80E618C
_08036CC0:
	movs r0, 0
	bl nullsub_23
	ldr r0, _08036CD4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _08036DFA
	.align 2, 0
_08036CD4: .4byte gUnknown_80E62C4
_08036CD8:
	ldr r4, _08036D18
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0xC]
	movs r2, 0
	movs r3, 0
	movs r5, 0x91
	lsls r5, 2
	adds r0, r1, r5
	str r2, [r0]
	str r3, [r0, 0x4]
	movs r0, 0x93
	lsls r0, 2
	adds r1, r0
	str r2, [r1]
	str r3, [r1, 0x4]
	bl sub_8011830
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	bl sub_8037B28
	ldr r4, [r4]
	str r0, [r4, 0xC]
	cmp r0, 0
	bne _08036D44
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _08036D1C
	cmp r0, 0x1
	beq _08036D2C
	b _08036D44
	.align 2, 0
_08036D18: .4byte gUnknown_203B358
_08036D1C:
	adds r2, r4, r5
	movs r1, 0x95
	lsls r1, 2
	adds r0, r4, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
_08036D2C:
	ldr r4, _08036D6C
	ldr r2, [r4]
	ldr r0, [r2, 0x8]
	movs r3, 0x91
	lsls r3, 2
	adds r1, r2, r3
	adds r3, 0x8
	adds r2, r3
	bl sub_8037D64
	ldr r1, [r4]
	str r0, [r1, 0xC]
_08036D44:
	ldr r4, _08036D6C
	ldr r2, [r4]
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _08036D66
	ldr r0, [r2, 0x8]
	cmp r0, 0x1
	bhi _08036D66
	movs r3, 0x91
	lsls r3, 2
	adds r1, r2, r3
	adds r3, 0x8
	adds r2, r3
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0xC]
_08036D66:
	bl xxx_call_start_bg_music
	b _08036DFA
	.align 2, 0
_08036D6C: .4byte gUnknown_203B358
_08036D70:
	ldr r2, [r5]
	movs r1, 0x94
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08036DA4
	ldr r1, _08036D9C
	movs r3, 0x92
	lsls r3, 2
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08036DA0
	subs r3, 0x4
	adds r1, r2, r3
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
	b _08036DB8
	.align 2, 0
_08036D9C: .4byte gUnknown_202DE30
_08036DA0: .4byte gUnknown_202DE58
_08036DA4:
	ldr r0, _08036DC8
	str r1, [r0]
	ldr r0, _08036DCC
	movs r3, 0x93
	lsls r3, 2
	adds r1, r2, r3
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
_08036DB8:
	ldr r0, _08036DD0
_08036DBA:
	ldr r3, _08036DD4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08036DFA
	.align 2, 0
_08036DC8: .4byte gUnknown_202DE30
_08036DCC: .4byte gUnknown_202DE58
_08036DD0: .4byte gUnknown_80E6314
_08036DD4: .4byte 0x00000101
_08036DD8:
	ldr r2, _08036E04
	ldr r1, [r5]
	ldr r0, [r1, 0x14]
	str r0, [r2]
	ldr r0, _08036E08
	ldr r2, _08036E0C
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
	ldr r0, _08036E10
	ldr r3, _08036E14
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08036DFA:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036E04: .4byte gUnknown_202DE30
_08036E08: .4byte gUnknown_202DE58
_08036E0C: .4byte 0x0000025e
_08036E10: .4byte gUnknown_80E6358
_08036E14: .4byte 0x00000101
	thumb_func_end sub_8036B28

        .align 2,0
