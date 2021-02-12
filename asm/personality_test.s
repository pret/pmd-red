        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start UpdateNatureTotals
UpdateNatureTotals:
	push {r4-r6,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0803C97C
	ldr r3, [sp]
	cmp r3, 0x63
	bne _0803C944
	ldr r0, _0803C940
	ldr r1, [r0]
	movs r0, 0x37
	str r0, [r1, 0x3C]
	movs r0, 0x1
	b _0803C97A
	.align 2, 0
_0803C940: .4byte gUnknown_203B400
_0803C944:
	ldr r1, _0803C984
	ldr r2, _0803C988
	ldr r0, [r2]
	ldr r0, [r0, 0x3C]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r4, [r0, 0x8]
	lsls r0, r3, 4
	adds r4, r0
	movs r3, 0
	adds r6, r2, 0
	adds r5, r6, 0
_0803C95E:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, 0x44
	adds r1, r0
	adds r0, r4, r3
	ldrb r2, [r0]
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
	adds r3, 0x1
	cmp r3, 0xC
	ble _0803C95E
	ldr r1, [r6]
	movs r0, 0
_0803C97A:
	str r0, [r1, 0x34]
_0803C97C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C984: .4byte gPersonalityQuestionPointerTable
_0803C988: .4byte gUnknown_203B400
	thumb_func_end UpdateNatureTotals

        .align 2,0
