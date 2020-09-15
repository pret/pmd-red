	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80035F8
sub_80035F8:
	push {lr}
	pop {r0}
	bx r0
	thumb_func_end sub_80035F8

	thumb_func_start sub_8003600
sub_8003600:
	push {r4-r6,lr}
	ldr r1, _08003650
	ldr r6, _08003654
	movs r2, 0
	ldr r0, _08003658
	movs r3, 0x80
	lsls r3, 2
_0800360E:
	strb r2, [r0]
	strb r2, [r0, 0x1]
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x3]
	adds r0, 0x4
	subs r3, 0x1
	cmp r3, 0
	bne _0800360E
	movs r0, 0
	movs r5, 0x80
	lsls r5, 1
	ldr r4, _0800365C
	movs r3, 0x20
	ldr r2, _08003660
_0800362A:
	strb r0, [r1]
	strh r5, [r1, 0x2]
	strb r0, [r1, 0x4]
	strb r0, [r1, 0x5]
	strb r0, [r1, 0x6]
	strb r0, [r1, 0x7]
	str r0, [r1, 0x8]
	str r4, [r1, 0xC]
	str r2, [r1, 0x10]
	subs r3, 0x1
	adds r1, 0x14
	cmp r3, 0
	bge _0800362A
	movs r0, 0x1
	strb r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003650: .4byte gUnknown_3000C00
_08003654: .4byte gUnknown_3001B58
_08003658: .4byte gUnknown_3000400
_0800365C: .4byte sub_8003A34
_08003660: .4byte sub_8003A74
	thumb_func_end sub_8003600

	thumb_func_start sub_8003664
sub_8003664:
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _0800369C
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	movs r0, 0
	strh r1, [r2, 0x2]
	strb r0, [r2, 0x4]
	strb r0, [r2, 0x5]
	strb r0, [r2, 0x6]
	strb r0, [r2, 0x7]
	str r3, [r2, 0x8]
	ldr r0, _080036A0
	str r0, [r2, 0xC]
	ldr r0, _080036A4
	str r0, [r2, 0x10]
	ldr r0, _080036A8
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800369C: .4byte gUnknown_3000C00
_080036A0: .4byte sub_8003AC0
_080036A4: .4byte sub_8003B50
_080036A8: .4byte gUnknown_3001B58
	thumb_func_end sub_8003664

	thumb_func_start sub_80036AC
sub_80036AC:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _080036E4
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _080036E8
	str r0, [r2, 0xC]
	ldr r0, _080036EC
	str r0, [r2, 0x10]
	ldr r0, _080036F0
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080036E4: .4byte gUnknown_3000C00
_080036E8: .4byte sub_8003C18
_080036EC: .4byte sub_8003D00
_080036F0: .4byte gUnknown_3001B58
	thumb_func_end sub_80036AC

	thumb_func_start sub_80036F4
sub_80036F4:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _0800372C
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _08003730
	str r0, [r2, 0xC]
	ldr r0, _08003734
	str r0, [r2, 0x10]
	ldr r0, _08003738
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800372C: .4byte gUnknown_3000C00
_08003730: .4byte sub_8003E2C
_08003734: .4byte sub_8003EC0
_08003738: .4byte gUnknown_3001B58
	thumb_func_end sub_80036F4

	thumb_func_start sub_800373C
sub_800373C:
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 2
	ldr r0, _08003770
	adds r3, r0
	movs r4, 0x1
	strb r4, [r3]
	movs r0, 0
	strh r1, [r3, 0x2]
	strb r0, [r3, 0x4]
	strb r0, [r3, 0x5]
	strb r0, [r3, 0x6]
	strb r0, [r3, 0x7]
	str r2, [r3, 0x8]
	ldr r0, _08003774
	str r0, [r3, 0xC]
	ldr r0, _08003778
	str r0, [r3, 0x10]
	ldr r0, _0800377C
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003770: .4byte gUnknown_3000C00
_08003774: .4byte sub_8003F60
_08003778: .4byte sub_8004034
_0800377C: .4byte gUnknown_3001B58
	thumb_func_end sub_800373C

	thumb_func_start sub_8003780
sub_8003780:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _080037B8
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _080037BC
	str r0, [r2, 0xC]
	ldr r0, _080037C0
	str r0, [r2, 0x10]
	ldr r0, _080037C4
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080037B8: .4byte gUnknown_3000C00
_080037BC: .4byte sub_8004170
_080037C0: .4byte sub_8004264
_080037C4: .4byte gUnknown_3001B58
	thumb_func_end sub_8003780

	thumb_func_start sub_80037C8
sub_80037C8:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _08003800
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _08003804
	str r0, [r2, 0xC]
	ldr r0, _08003808
	str r0, [r2, 0x10]
	ldr r0, _0800380C
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003800: .4byte gUnknown_3000C00
_08003804: .4byte sub_8004388
_08003808: .4byte sub_8004434
_0800380C: .4byte gUnknown_3001B58
	thumb_func_end sub_80037C8

	thumb_func_start sub_8003810
sub_8003810:
	sub sp, 0x4
	str r1, [sp]
	lsls r0, 16
	lsrs r2, r0, 20
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	ldr r2, _08003838
	adds r1, r2
	movs r2, 0x1
	strb r2, [r1]
	ldr r1, _0800383C
	lsrs r0, 14
	adds r0, r1
	ldr r1, [sp]
	str r1, [r0]
	ldr r0, _08003840
	strb r2, [r0]
	add sp, 0x4
	bx lr
	.align 2, 0
_08003838: .4byte gUnknown_3000C00
_0800383C: .4byte gUnknown_3000400
_08003840: .4byte gUnknown_3001B58
	thumb_func_end sub_8003810

	thumb_func_start sub_8003844
sub_8003844:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	lsrs r1, 16
	lsrs r0, 20
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _08003880
	adds r2, r0
	movs r5, 0x1
	strb r5, [r2]
	adds r0, r1, 0
	bl sub_80027A0
	str r0, [sp]
	ldr r0, _08003884
	lsls r4, 2
	adds r4, r0
	ldr r0, [sp]
	str r0, [r4]
	ldr r0, _08003888
	strb r5, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003880: .4byte gUnknown_3000C00
_08003884: .4byte gUnknown_3000400
_08003888: .4byte gUnknown_3001B58
	thumb_func_end sub_8003844

	thumb_func_start sub_800388C
sub_800388C:
	push {r4-r7,lr}
	adds r6, r1, 0
	lsls r0, 16
	lsrs r1, r0, 16
	lsrs r4, r0, 20
	adds r3, r1, r2
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080038A0
	adds r0, 0xF
_080038A0:
	lsls r0, 12
	lsrs r3, r0, 16
	lsls r1, 2
	ldr r0, _080038E4
	adds r1, r0
	lsls r5, r4, 2
	ldr r7, _080038E8
	ldr r0, _080038EC
	mov r12, r0
	cmp r2, 0
	ble _080038C0
_080038B6:
	ldm r6!, {r0}
	stm r1!, {r0}
	subs r2, 0x1
	cmp r2, 0
	bne _080038B6
_080038C0:
	adds r0, r5, r4
	lsls r0, 2
	adds r0, r7
	adds r2, r4, 0
	cmp r2, r3
	bgt _080038D8
	movs r1, 0x1
_080038CE:
	strb r1, [r0]
	adds r2, 0x1
	adds r0, 0x14
	cmp r2, r3
	ble _080038CE
_080038D8:
	movs r0, 0x1
	mov r1, r12
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080038E4: .4byte gUnknown_3000400
_080038E8: .4byte gUnknown_3000C00
_080038EC: .4byte gUnknown_3001B58
	thumb_func_end sub_800388C

	thumb_func_start sub_80038F0
sub_80038F0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r5, r1, 0
	lsls r0, 16
	lsrs r1, r0, 16
	lsrs r6, r0, 20
	adds r3, r1, r2
	subs r0, r3, 0x1
	cmp r0, 0
	bge _0800390C
	adds r0, 0xF
_0800390C:
	lsls r0, 12
	lsrs r7, r0, 16
	lsls r1, 2
	ldr r0, _0800396C
	adds r1, r0
	mov r8, r1
	lsls r0, r6, 2
	mov r9, r0
	cmp r2, 0
	ble _0800393C
	adds r4, r2, 0
_08003922:
	ldrh r0, [r5]
	adds r5, 0x2
	bl sub_80027A0
	str r0, [sp]
	mov r1, r8
	adds r1, 0x4
	mov r8, r1
	subs r1, 0x4
	stm r1!, {r0}
	subs r4, 0x1
	cmp r4, 0
	bne _08003922
_0800393C:
	mov r1, r9
	adds r0, r1, r6
	lsls r0, 2
	ldr r1, _08003970
	adds r0, r1
	adds r4, r6, 0
	ldr r2, _08003974
	cmp r4, r7
	bgt _0800395A
	movs r1, 0x1
_08003950:
	strb r1, [r0]
	adds r4, 0x1
	adds r0, 0x14
	cmp r4, r7
	ble _08003950
_0800395A:
	movs r0, 0x1
	strb r0, [r2]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800396C: .4byte gUnknown_3000400
_08003970: .4byte gUnknown_3000C00
_08003974: .4byte gUnknown_3001B58
	thumb_func_end sub_80038F0

	thumb_func_start sub_8003978
sub_8003978:
	lsls r0, 16
	ldr r1, _08003984
	lsrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08003984: .4byte gUnknown_3000400
	thumb_func_end sub_8003978

	thumb_func_start sub_8003988
sub_8003988:
	push {lr}
	lsls r0, 16
	ldr r1, _080039A0
	lsrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	bl sub_8002774
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.align 2, 0
_080039A0: .4byte gUnknown_3000400
	thumb_func_end sub_8003988

	thumb_func_start sub_80039A4
sub_80039A4:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _080039B4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_080039B4: .4byte gUnknown_3001B5A
	thumb_func_end sub_80039A4

	thumb_func_start sub_80039B8
sub_80039B8:
	push {r4,r5,lr}
	ldr r0, _08003A28
	ldrb r0, [r0]
	cmp r0, 0
	beq _08003A20
	ldr r4, _08003A2C
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080039DA
	movs r0, 0xA0
	lsls r0, 2
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080039DA:
	movs r5, 0
_080039DC:
	ldrb r0, [r4]
	cmp r0, 0
	beq _080039F0
	lsls r0, r5, 16
	lsrs r0, 16
	ldr r1, [r4, 0x10]
	bl _call_via_r1
	movs r0, 0
	strb r0, [r4]
_080039F0:
	adds r5, 0x1
	adds r4, 0x14
	cmp r5, 0x1F
	ble _080039DC
	ldr r0, _08003A2C
	movs r1, 0xA0
	lsls r1, 2
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0
	beq _08003A14
	ldr r2, [r4, 0xC]
	movs r0, 0x20
	movs r1, 0xF0
	bl _call_via_r2
	movs r0, 0
	strb r0, [r5]
_08003A14:
	ldr r1, _08003A30
	movs r0, 0x3
	strh r0, [r1]
	ldr r1, _08003A28
	movs r0, 0
	strb r0, [r1]
_08003A20:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003A28: .4byte gUnknown_3001B58
_08003A2C: .4byte gUnknown_3000C00
_08003A30: .4byte gUnknown_3001B5A
	thumb_func_end sub_80039B8

	thumb_func_start sub_8003A34
sub_8003A34:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, r1, 16
	lsrs r0, 16
	lsls r5, r0, 2
	ldr r1, _08003A70
	adds r5, r1
	ldrb r1, [r5, 0x2]
	movs r2, 0xF8
	adds r3, r2, 0
	ands r3, r1
	lsls r3, 7
	ldrb r4, [r5, 0x1]
	adds r1, r2, 0
	ands r1, r4
	lsls r1, 2
	orrs r3, r1
	ldrb r1, [r5]
	ands r2, r1
	lsrs r2, 3
	orrs r2, r3
	mov r1, sp
	strh r2, [r1]
	bl SetBGPaletteBufferColor
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003A70: .4byte gUnknown_3000400
	thumb_func_end sub_8003A34

	thumb_func_start sub_8003A74
sub_8003A74:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 20
	lsrs r6, r0, 16
	lsls r1, r6, 2
	ldr r0, _08003ABC
	adds r4, r1, r0
	movs r5, 0
	movs r7, 0xF8
_08003A86:
	ldrb r0, [r4, 0x2]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r7, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r7, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r6, r5
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003A86
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08003ABC: .4byte gUnknown_3000400
	thumb_func_end sub_8003A74

	thumb_func_start sub_8003AC0
sub_8003AC0:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003B04
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r6, r2, 0
	lsls r1, r7, 2
	ldr r0, _08003B08
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _08003B0C
	ldrb r0, [r4, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r4, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r4]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003B3A
	.align 2, 0
_08003B04: .4byte gUnknown_3000C00
_08003B08: .4byte gUnknown_3000400
_08003B0C:
	cmp r2, 0
	bne _08003B16
	mov r0, sp
	strh r2, [r0]
	b _08003B3E
_08003B16:
	ldrb r0, [r4, 0x2]
	muls r0, r2
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r5, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r2
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r5
	ldrb r0, [r4]
	muls r0, r6
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003B3A:
	mov r0, sp
	strh r1, [r0]
_08003B3E:
	adds r0, r7, 0
	mov r1, sp
	bl SetBGPaletteBufferColor
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003AC0

	thumb_func_start sub_8003B50
sub_8003B50:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _08003BAC
	adds r1, r2
	ldrh r6, [r1, 0x2]
	lsls r0, 20
	lsrs r7, r0, 16
	lsls r1, r7, 2
	ldr r0, _08003BB0
	adds r4, r1, r0
	cmp r6, 0xFF
	bls _08003BB4
	movs r5, 0
	movs r6, 0xF8
_08003B7A:
	ldrb r0, [r4, 0x2]
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r6, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r7, r5
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003B7A
	b _08003C0A
	.align 2, 0
_08003BAC: .4byte gUnknown_3000C00
_08003BB0: .4byte gUnknown_3000400
_08003BB4:
	cmp r6, 0
	bne _08003BCE
	mov r0, sp
	strh r6, [r0]
	movs r5, 0
_08003BBE:
	adds r0, r7, r5
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003BBE
	b _08003C0A
_08003BCE:
	movs r5, 0
	mov r8, sp
_08003BD2:
	ldrb r0, [r4, 0x2]
	muls r0, r6
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r2, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r6
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r2
	ldrb r0, [r4]
	muls r0, r6
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
	mov r0, r8
	strh r1, [r0]
	adds r0, r7, r5
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003BD2
_08003C0A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003B50

	thumb_func_start sub_8003C18
sub_8003C18:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003C68
	adds r1, r0
	ldrh r2, [r1, 0x2]
	mov r12, r2
	ldr r0, [r1, 0x4]
	str r0, [sp]
	mov r0, r8
	lsls r1, r0, 2
	ldr r0, _08003C6C
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _08003C70
	ldrb r0, [r4, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r4, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r4]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003CE8
	.align 2, 0
_08003C68: .4byte gUnknown_3000C00
_08003C6C: .4byte gUnknown_3000400
_08003C70:
	cmp r2, 0
	bne _08003C98
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003CE8
_08003C98:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	subs r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	ldrb r1, [r1]
	adds r7, r1, 0
	muls r7, r0
	mov r1, sp
	ldrb r1, [r1, 0x1]
	adds r6, r1, 0
	muls r6, r0
	mov r1, sp
	ldrb r1, [r1, 0x2]
	muls r1, r0
	ldrb r0, [r4, 0x2]
	muls r0, r2
	adds r0, r1
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r5, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r2
	adds r0, r6
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r5
	ldrb r0, [r4]
	mov r2, r12
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003CE8:
	add r0, sp, 0x4
	strh r1, [r0]
	adds r1, r0, 0
	mov r0, r8
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003C18

	thumb_func_start sub_8003D00
sub_8003D00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _08003D68
	adds r1, r2
	ldrh r6, [r1, 0x2]
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r0, 16
	mov r8, r0
	lsls r1, r0, 2
	ldr r0, _08003D6C
	adds r4, r1, r0
	cmp r6, 0xFF
	bls _08003D70
	movs r5, 0
	movs r7, 0xF8
	add r6, sp, 0x4
_08003D36:
	ldrb r0, [r4, 0x2]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r7, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r7, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r6]
	mov r1, r8
	adds r0, r1, r5
	adds r1, r6, 0
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003D36
	b _08003E1C
	.align 2, 0
_08003D68: .4byte gUnknown_3000C00
_08003D6C: .4byte gUnknown_3000400
_08003D70:
	cmp r6, 0
	bne _08003DAE
	add r4, sp, 0x4
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	strh r1, [r4]
	movs r5, 0
_08003D9C:
	mov r2, r8
	adds r0, r2, r5
	adds r1, r4, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003D9C
	b _08003E1C
_08003DAE:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	subs r0, r6
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	ldrb r1, [r1]
	adds r2, r1, 0
	muls r2, r0
	str r2, [sp, 0x8]
	mov r1, sp
	ldrb r1, [r1, 0x1]
	adds r2, r1, 0
	muls r2, r0
	mov r10, r2
	mov r1, sp
	ldrb r1, [r1, 0x2]
	adds r2, r1, 0
	muls r2, r0
	mov r9, r2
	movs r5, 0
	add r7, sp, 0x4
_08003DDC:
	ldrb r0, [r4, 0x2]
	muls r0, r6
	add r0, r9
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r2, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r6
	add r0, r10
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r2
	ldrb r0, [r4]
	muls r0, r6
	ldr r2, [sp, 0x8]
	adds r0, r2
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
	strh r1, [r7]
	mov r1, r8
	adds r0, r1, r5
	adds r1, r7, 0
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003DDC
_08003E1C:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003D00

	thumb_func_start sub_8003E2C
sub_8003E2C:
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003E74
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r5, r2, 0
	ldr r0, [r1, 0x4]
	str r0, [sp]
	cmp r2, 0xFF
	bls _08003E78
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003EAC
	.align 2, 0
_08003E74: .4byte gUnknown_3000C00
_08003E78:
	cmp r2, 0
	bne _08003E82
	add r0, sp, 0x4
	strh r2, [r0]
	b _08003EB0
_08003E82:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r4, r0, 7
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r4
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r5
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003EAC:
	add r0, sp, 0x4
	strh r1, [r0]
_08003EB0:
	adds r1, r0, 0
	adds r0, r6, 0
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8003E2C

	thumb_func_start sub_8003EC0
sub_8003EC0:
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _08003F08
	adds r1, r2
	ldrh r2, [r1, 0x2]
	adds r5, r2, 0
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r6, r0, 16
	cmp r2, 0xFF
	bls _08003F0C
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003F40
	.align 2, 0
_08003F08: .4byte gUnknown_3000C00
_08003F0C:
	cmp r2, 0
	bne _08003F16
	add r0, sp, 0x4
	strh r2, [r0]
	b _08003F44
_08003F16:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r4, r0, 7
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r4
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r5
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003F40:
	add r0, sp, 0x4
	strh r1, [r0]
_08003F44:
	adds r5, r0, 0
	movs r4, 0
_08003F48:
	adds r0, r6, r4
	adds r1, r5, 0
	bl SetBGPaletteBufferColor
	adds r4, 0x1
	cmp r4, 0xF
	ble _08003F48
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8003EC0

	thumb_func_start sub_8003F60
sub_8003F60:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003FA8
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r3, r2, 0
	movs r0, 0xF
	ands r0, r7
	lsls r0, 2
	ldr r1, [r1, 0x8]
	adds r5, r1, r0
	lsls r1, r7, 2
	ldr r0, _08003FAC
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _08003FB0
	ldrb r0, [r4, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r4, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r4]
	b _08003FCA
	.align 2, 0
_08003FA8: .4byte gUnknown_3000C00
_08003FAC: .4byte gUnknown_3000400
_08003FB0:
	cmp r2, 0
	bne _08003FD6
	ldrb r0, [r5, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r5, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r5]
_08003FCA:
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	mov r0, sp
	strh r1, [r0]
	b _08004024
_08003FD6:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	subs r0, r3
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r5]
	adds r2, r1, 0
	muls r2, r0
	ldrb r1, [r4]
	muls r1, r3
	adds r6, r2, r1
	ldrb r1, [r5, 0x1]
	adds r2, r1, 0
	muls r2, r0
	ldrb r1, [r4, 0x1]
	muls r1, r3
	adds r2, r1
	ldrb r1, [r5, 0x2]
	muls r1, r0
	ldrb r0, [r4, 0x2]
	muls r0, r3
	adds r0, r1, r0
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r1, r0, 7
	adds r0, r2, 0
	asrs r0, 8
	ands r0, r3
	lsls r2, r0, 2
	orrs r2, r1
	adds r0, r6, 0
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r2, r0
	mov r0, sp
	strh r2, [r0]
_08004024:
	adds r0, r7, 0
	mov r1, sp
	bl SetBGPaletteBufferColor
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003F60

	thumb_func_start sub_8004034
sub_8004034:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _0800409C
	adds r1, r2
	ldrh r2, [r1, 0x2]
	mov r8, r2
	ldr r5, [r1, 0x8]
	lsls r0, 20
	lsrs r0, 16
	mov r10, r0
	lsls r1, r0, 2
	ldr r0, _080040A0
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _080040A4
	movs r7, 0
	movs r5, 0xF8
_08004068:
	ldrb r0, [r4, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r5, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r5, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r1, r10
	adds r0, r1, r7
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r7, 0x1
	cmp r7, 0xF
	ble _08004068
	b _0800415E
	.align 2, 0
_0800409C: .4byte gUnknown_3000C00
_080040A0: .4byte gUnknown_3000400
_080040A4:
	mov r2, r8
	cmp r2, 0
	bne _080040E2
	movs r7, 0
	mov r6, sp
	movs r4, 0xF8
_080040B0:
	ldrb r0, [r5, 0x2]
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r5, 0x1]
	adds r0, r4, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r5]
	adds r0, r4, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r6]
	mov r1, r10
	adds r0, r1, r7
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r7, 0x1
	cmp r7, 0xF
	ble _080040B0
	b _0800415E
_080040E2:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	mov r1, r8
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r7, 0
	mov r2, sp
	str r2, [sp, 0x4]
_080040F8:
	ldrb r0, [r5]
	mov r1, r9
	muls r1, r0
	ldrb r0, [r4]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r1, r0
	mov r12, r1
	ldrb r0, [r5, 0x1]
	mov r1, r9
	muls r1, r0
	ldrb r0, [r4, 0x1]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r6, r1, r0
	ldrb r0, [r5, 0x2]
	mov r1, r9
	muls r1, r0
	ldrb r0, [r4, 0x2]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r1, r0
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r2, r0, 7
	adds r0, r6, 0
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r2
	mov r0, r12
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
	ldr r0, [sp, 0x4]
	strh r1, [r0]
	mov r1, r10
	adds r0, r1, r7
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x4
	adds r7, 0x1
	cmp r7, 0xF
	ble _080040F8
_0800415E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8004034

	thumb_func_start sub_8004170
sub_8004170:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _080041C4
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r4, r2, 0
	ldr r0, [r1, 0x4]
	str r0, [sp]
	mov r0, r9
	lsls r1, r0, 2
	ldr r0, _080041C8
	adds r6, r1, r0
	cmp r2, 0xFF
	bls _080041CC
	ldrb r0, [r6, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r6, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r6]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	add r0, sp, 0x4
	strh r1, [r0]
	b _0800424C
	.align 2, 0
_080041C4: .4byte gUnknown_3000C00
_080041C8: .4byte gUnknown_3000400
_080041CC:
	mov r0, sp
	ldrb r1, [r0]
	movs r3, 0xFF
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080041DC
	adds r0, 0xFF
_080041DC:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	mov r0, sp
	ldrb r1, [r0, 0x1]
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080041F4
	adds r0, 0xFF
_080041F4:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r7, r0, 16
	mov r0, sp
	ldrb r1, [r0, 0x2]
	subs r0, r3, r1
	muls r0, r4
	cmp r0, 0
	bge _0800420A
	adds r0, 0xFF
_0800420A:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r6, 0x2]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	movs r5, 0xF8
	ands r4, r5
	lsls r4, 7
	ldrb r0, [r6, 0x1]
	muls r0, r7
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r6]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsrs r0, 3
	orrs r4, r0
	add r0, sp, 0x4
	strh r4, [r0]
_0800424C:
	adds r1, r0, 0
	mov r0, r9
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8004170

	thumb_func_start sub_8004264
sub_8004264:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _080042CC
	adds r1, r2
	ldrh r2, [r1, 0x2]
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r0, 16
	mov r9, r0
	lsls r1, r0, 2
	ldr r0, _080042D0
	adds r5, r1, r0
	cmp r2, 0xFF
	bls _080042D4
	movs r6, 0
	movs r7, 0xF8
	add r4, sp, 0x4
_0800429A:
	ldrb r0, [r5, 0x2]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r5, 0x1]
	adds r0, r7, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r5]
	adds r0, r7, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r4]
	mov r1, r9
	adds r0, r1, r6
	adds r1, r4, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0xF
	ble _0800429A
	b _08004378
	.align 2, 0
_080042CC: .4byte gUnknown_3000C00
_080042D0: .4byte gUnknown_3000400
_080042D4:
	mov r0, sp
	ldrb r1, [r0]
	movs r3, 0xFF
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080042E4
	adds r0, 0xFF
_080042E4:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	mov r0, sp
	ldrb r1, [r0, 0x1]
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080042FC
	adds r0, 0xFF
_080042FC:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r0, sp
	ldrb r1, [r0, 0x2]
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _08004314
	adds r0, 0xFF
_08004314:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	movs r6, 0
	add r7, sp, 0x4
	movs r0, 0xF8
	mov r8, r0
_08004326:
	ldrb r0, [r5, 0x2]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	mov r0, r8
	ands r4, r0
	lsls r4, 7
	ldrb r0, [r5, 0x1]
	ldr r1, [sp, 0xC]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r5]
	ldr r1, [sp, 0x8]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsrs r0, 3
	orrs r4, r0
	strh r4, [r7]
	mov r1, r9
	adds r0, r1, r6
	adds r1, r7, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0xF
	ble _08004326
_08004378:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8004264

	thumb_func_start sub_8004388
sub_8004388:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _0800442C
	adds r1, r0
	ldrh r2, [r1, 0x2]
	ldr r0, [r1, 0x4]
	str r0, [sp]
	mov r0, r9
	lsls r1, r0, 2
	ldr r0, _08004430
	adds r6, r1, r0
	cmp r2, 0xFF
	bls _080043BC
	movs r2, 0x80
	lsls r2, 1
_080043BC:
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	mov r8, r0
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	lsls r0, 8
	lsrs r7, r0, 16
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	ldrb r1, [r6, 0x2]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	movs r5, 0xF8
	ands r4, r5
	lsls r4, 7
	ldrb r0, [r6, 0x1]
	muls r0, r7
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r6]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsrs r0, 3
	orrs r4, r0
	add r1, sp, 0x4
	strh r4, [r1]
	mov r0, r9
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800442C: .4byte gUnknown_3000C00
_08004430: .4byte gUnknown_3000400
	thumb_func_end sub_8004388

	thumb_func_start sub_8004434
sub_8004434:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _080044F8
	adds r1, r2
	ldrh r2, [r1, 0x2]
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r0, 16
	mov r9, r0
	lsls r1, r0, 2
	ldr r0, _080044FC
	adds r5, r1, r0
	cmp r2, 0xFF
	bls _08004468
	movs r2, 0x80
	lsls r2, 1
_08004468:
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	str r0, [sp, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	mov r10, r0
	movs r6, 0
	movs r0, 0xF8
	mov r8, r0
	add r7, sp, 0x4
_08004494:
	ldrb r0, [r5, 0x2]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	mov r0, r8
	ands r4, r0
	lsls r4, 7
	ldrb r0, [r5, 0x1]
	ldr r1, [sp, 0xC]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r5]
	ldr r1, [sp, 0x8]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsrs r0, 3
	orrs r4, r0
	strh r4, [r7]
	mov r1, r9
	adds r0, r1, r6
	adds r1, r7, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0xF
	ble _08004494
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080044F8: .4byte gUnknown_3000C00
_080044FC: .4byte gUnknown_3000400
	thumb_func_end sub_8004434

	.align 2, 0 @ Don't pad with nop.
