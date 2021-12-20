        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_803AEB0
sub_803AEB0:
	push {r4-r6,lr}
	ldr r4, _0803AEFC
	ldr r0, [r4]
	adds r0, 0xD0
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	adds r1, r4, 0
	adds r1, 0x90
	ldr r0, _0803AF00
	str r0, [r1]
	adds r5, r4, 0
	adds r5, 0x94
	movs r0, 0x4
	str r0, [r5]
	movs r2, 0x1
	adds r1, 0x8
	ldr r0, _0803AF04
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	movs r6, 0x2
	adds r0, r4, 0
	adds r0, 0xA0
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	adds r0, 0x2C
	ldrh r0, [r0]
	cmp r0, 0
	bne _0803AF08
	ldr r0, [r5]
	str r0, [r4, 0xC]
	b _0803AF2C
	.align 2, 0
_0803AEFC: .4byte gUnknown_203B3F8
_0803AF00: .4byte gDebug_LevelText
_0803AF04: .4byte gUnknown_80E7F2C
_0803AF08:
	adds r3, 0x1
	cmp r3, r6
	bge _0803AF2C
	ldr r0, _0803AF34
	ldr r2, [r0]
	lsls r1, r3, 1
	adds r0, r2, 0
	adds r0, 0xD0
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _0803AF08
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x94
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
_0803AF2C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803AF34: .4byte gUnknown_203B3F8
	thumb_func_end sub_803AEB0

        .align 2,0
