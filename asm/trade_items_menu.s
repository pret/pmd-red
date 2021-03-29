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
	bl PrintTradeItemsLinkError
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

        .align 2,0
