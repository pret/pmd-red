        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start RedrawPartnerSelectionMenu
RedrawPartnerSelectionMenu:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, _0803CF60
	ldr r0, [r6]
	movs r1, 0x32
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r6]
	ldr r3, [r2, 0x4C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x62
	movs r4, 0
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x4C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x64
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, 0x54
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	ldr r0, [r0, 0x4C]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x4C]
	bl sub_80073B8
	ldr r2, _0803CF64
	ldr r0, [r6]
	ldr r3, [r0, 0x4C]
	str r4, [sp]
	movs r0, 0xC
	movs r1, 0
	bl xxx_call_draw_string
	movs r5, 0
	b _0803CF98
	.align 2, 0
_0803CF60: .4byte gUnknown_203B404
_0803CF64: .4byte gUnknown_80F42C0
_0803CF68:
	ldr r0, [r6]
	adds r0, 0x18
	adds r1, r5, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r0, [r6]
	lsls r1, r5, 1
	adds r0, 0x2
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_808D994
	adds r2, r0, 0
	ldr r0, [r6]
	ldr r3, [r0, 0x4C]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	adds r5, 0x1
_0803CF98:
	ldr r0, [r6]
	movs r1, 0x32
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0803CF68
	ldr r4, _0803CFBC
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_80073E0
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x16]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803CFBC: .4byte gUnknown_203B404
	thumb_func_end RedrawPartnerSelectionMenu

        .align 2,0
