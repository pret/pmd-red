	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_141
nullsub_141:
	bx lr
	thumb_func_end nullsub_141

	thumb_func_start nullsub_142
nullsub_142:
	bx lr
	thumb_func_end nullsub_142

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

	thumb_func_start sub_8004500
sub_8004500:
	ldr r1, _08004514
	ldrh r2, [r1]
	movs r0, 0x6D
	muls r0, r2
	ldr r2, _08004518
	adds r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	bx lr
	.align 2, 0
_08004514: .4byte gUnknown_203B070
_08004518: .4byte 0x000003fd
	thumb_func_end sub_8004500

	thumb_func_start sub_800451C
sub_800451C:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8004500
	muls r0, r4
	asrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800451C

	thumb_func_start sub_8004530
sub_8004530:
	push {r4,lr}
	adds r4, r0, 0
	subs r0, r1, r4
	bl sub_800451C
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8004530

	thumb_func_start sub_8004544
sub_8004544:
	push {r4,r5,lr}
	adds r3, r0, 0
	subs r4, r1, 0x1
	adds r2, r3, r4
	movs r5, 0
	cmp r5, r4
	bge _08004566
_08004552:
	ldrb r1, [r3]
	ldrb r0, [r2]
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r2]
	subs r2, 0x1
	adds r5, 0x1
	subs r4, 0x1
	cmp r5, r4
	blt _08004552
_08004566:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8004544

	thumb_func_start sub_800456C
sub_800456C:
	push {r4-r7,lr}
	adds r4, r1, 0
	cmp r4, 0
	ble _08004578
	movs r7, 0x1
	b _0800457E
_08004578:
	negs r4, r4
	movs r7, 0x1
	negs r7, r7
_0800457E:
	cmp r2, 0
	ble _080045A0
	adds r6, r0, 0
	adds r5, r2, 0
_08004586:
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	stm r6!, {r0}
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	subs r5, 0x1
	cmp r5, 0
	bne _08004586
_080045A0:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800456C

	thumb_func_start sub_80045A8
sub_80045A8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldm r4!, {r1}
	movs r3, 0xA
	cmp r2, 0x1
	ble _080045CA
	subs r2, 0x1
_080045B8:
	ldm r4!, {r0}
	muls r0, r3
	adds r1, r0
	subs r2, 0x1
	lsls r0, r3, 2
	adds r0, r3
	lsls r3, r0, 1
	cmp r2, 0
	bne _080045B8
_080045CA:
	adds r0, r1, 0
	cmp r5, 0
	bge _080045D2
	negs r0, r0
_080045D2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80045A8

	thumb_func_start ConvertFromBCD
ConvertFromBCD:
	push {r4,lr}
	adds r1, r0, 0
	movs r2, 0x1
	movs r3, 0
	cmp r1, 0
	ble _080045FA
	movs r4, 0xF
_080045E6:
	adds r0, r1, 0
	ands r0, r4
	muls r0, r2
	adds r3, r0
	lsls r0, r2, 2
	adds r0, r2
	lsls r2, r0, 1
	asrs r1, 4
	cmp r1, 0
	bgt _080045E6
_080045FA:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ConvertFromBCD

	thumb_func_start ConvertToBCD
ConvertToBCD:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r6, 0
	cmp r4, 0
	ble _0800462C
_08004610:
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	lsls r0, r5
	adds r6, r0
	adds r5, 0x4
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	cmp r4, 0
	bgt _08004610
_0800462C:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end ConvertToBCD

	thumb_func_start InitBGPaletteBuffer
InitBGPaletteBuffer:
	push {lr}
	movs r2, 0
	ldr r1, _0800465C
	movs r0, 0x80
	lsls r0, 2
_0800463E:
	strh r2, [r1]
	adds r1, 0x2
	subs r0, 0x1
	cmp r0, 0
	bne _0800463E
	ldr r1, _08004660
	movs r2, 0x1
	adds r0, r1, 0
	adds r0, 0x1F
_08004650:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08004650
	pop {r0}
	bx r0
	.align 2, 0
_0800465C: .4byte gUnknown_20251F0
_08004660: .4byte gUnknown_20251D0
	thumb_func_end InitBGPaletteBuffer

	thumb_func_start SetBGPaletteBufferColorRGB
SetBGPaletteBufferColorRGB:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	cmp r2, 0
	bge _08004670
	movs r2, 0
_08004670:
	cmp r2, 0x1F
	ble _08004676
	movs r2, 0x1F
_08004676:
	ldr r1, _080046CC
	adds r0, r4, 0
	cmp r4, 0
	bge _08004680
	adds r0, 0xF
_08004680:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	cmp r3, 0
	bne _080046D4
	ldr r0, _080046D0
	lsls r1, r4, 1
	adds r6, r1, r0
	ldrb r0, [r5, 0x2]
	muls r0, r2
	cmp r0, 0
	bge _0800469C
	adds r0, 0xFF
_0800469C:
	asrs r0, 8
	movs r3, 0x1F
	ands r0, r3
	lsls r4, r0, 10
	ldrb r0, [r5, 0x1]
	muls r0, r2
	cmp r0, 0
	bge _080046AE
	adds r0, 0xFF
_080046AE:
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 5
	orrs r1, r4
	ldrb r0, [r5]
	muls r0, r2
	cmp r0, 0
	bge _080046C0
	adds r0, 0xFF
_080046C0:
	asrs r0, 8
	ands r0, r3
	orrs r1, r0
	strh r1, [r6]
	b _08004722
	.align 2, 0
_080046CC: .4byte gUnknown_20251D0
_080046D0: .4byte gUnknown_20251F0
_080046D4:
	ldr r1, _08004728
	lsls r0, r4, 1
	adds r7, r0, r1
	ldrb r0, [r5, 0x2]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	muls r0, r2
	cmp r0, 0
	bge _080046EA
	adds r0, 0xFF
_080046EA:
	asrs r0, 8
	movs r4, 0x1F
	ands r0, r4
	lsls r6, r0, 10
	ldrb r0, [r5, 0x1]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	muls r0, r2
	cmp r0, 0
	bge _08004702
	adds r0, 0xFF
_08004702:
	asrs r0, 8
	ands r0, r4
	lsls r1, r0, 5
	orrs r1, r6
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0]
	muls r0, r2
	cmp r0, 0
	bge _0800471A
	adds r0, 0xFF
_0800471A:
	asrs r0, 8
	ands r0, r4
	orrs r1, r0
	strh r1, [r7]
_08004722:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004728: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColorRGB

	thumb_func_start SetBGPaletteBufferColorArray
SetBGPaletteBufferColorArray:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, _08004764
	cmp r2, 0
	bge _0800473A
	adds r0, 0xF
_0800473A:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08004768
	lsls r2, 1
	adds r2, r0
	ldrb r1, [r3, 0x2]
	lsrs r1, 3
	lsls r1, 10
	ldrb r0, [r3, 0x1]
	lsrs r0, 3
	lsls r0, 5
	orrs r1, r0
	ldrb r0, [r3]
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_08004764: .4byte gUnknown_20251D0
_08004768: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColorArray

	thumb_func_start SetBGPaletteBufferColor
SetBGPaletteBufferColor:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, _08004790
	cmp r2, 0
	bge _0800477A
	adds r0, 0xF
_0800477A:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, _08004794
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r3]
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08004790: .4byte gUnknown_20251D0
_08004794: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColor

	thumb_func_start nullsub_4
nullsub_4:
	bx lr
	thumb_func_end nullsub_4

	thumb_func_start nullsub_5
nullsub_5:
	bx lr
	thumb_func_end nullsub_5

	thumb_func_start nullsub_143
nullsub_143:
	bx lr
	thumb_func_end nullsub_143

	thumb_func_start TransferBGPaletteBuffer
TransferBGPaletteBuffer:
	push {r4-r6,lr}
	movs r6, 0
	movs r4, 0
	movs r5, 0xA0
	lsls r5, 19
_080047AE:
	ldr r0, _080047DC
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080047CA
	movs r0, 0
	strb r0, [r1]
	lsls r1, r4, 1
	ldr r0, _080047E0
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0x20
	bl CpuCopy
_080047CA:
	adds r6, 0x1
	adds r5, 0x20
	adds r4, 0x10
	ldr r0, _080047E4
	cmp r4, r0
	ble _080047AE
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080047DC: .4byte gUnknown_20251D0
_080047E0: .4byte gUnknown_20251F0
_080047E4: .4byte 0x000001ff
	thumb_func_end TransferBGPaletteBuffer

	thumb_func_start sub_80047E8
sub_80047E8:
	ldr r0, _08004840
	movs r3, 0
	movs r2, 0
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r0, _08004844
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r1, _08004848
	ldr r0, _0800484C
	str r0, [r1]
	ldr r0, _08004850
	str r2, [r0, 0x20]
	ldr r1, _08004854
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x1C]
	strh r1, [r0, 0x1E]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r3, [r1]
	adds r0, 0x29
	strb r3, [r0]
	ldr r0, _08004858
	strh r2, [r0]
	strh r2, [r0, 0x2]
	bx lr
	.align 2, 0
_08004840: .4byte gUnknown_20255F0
_08004844: .4byte gUnknown_2025638
_08004848: .4byte gUnknown_202562C
_0800484C: .4byte 0x004a14c1
_08004850: .4byte gUnknown_2025600
_08004854: .4byte 0x0000ffff
_08004858: .4byte gUnknown_2025668
	thumb_func_end sub_80047E8

	thumb_func_start sub_800485C
sub_800485C:
	push {r4,r5,lr}
	ldr r2, _080048A8
	ldr r1, _080048AC
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0
	movs r0, 0
	strh r0, [r2]
	strh r0, [r2, 0x2]
	strh r0, [r2, 0x4]
	strh r0, [r2, 0x6]
	ldr r0, _080048B0
	ldr r1, _080048B4
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r3, [r1]
	adds r0, 0x29
	strb r3, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080048A8: .4byte gUnknown_2025638
_080048AC: .4byte gUnknown_20255F0
_080048B0: .4byte gUnknown_2025600
_080048B4: .4byte 0x0000ffff
	thumb_func_end sub_800485C

	thumb_func_start sub_80048B8
sub_80048B8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048B8

	thumb_func_start sub_80048BC
sub_80048BC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048BC

	thumb_func_start sub_80048C0
sub_80048C0:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C0

	thumb_func_start sub_80048C4
sub_80048C4:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C4

	thumb_func_start sub_80048C8
sub_80048C8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C8

	thumb_func_start sub_80048CC
sub_80048CC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048CC

	thumb_func_start sub_80048D0
sub_80048D0:
	ldr r1, _080048E8
	movs r0, 0
	strh r0, [r1, 0x4]
	ldr r1, _080048EC
	str r0, [r1, 0xC]
	strh r0, [r1, 0x8]
	ldr r1, _080048F0
	ldr r0, _080048F4
	strh r0, [r1]
	strh r0, [r1, 0x2]
	bx lr
	.align 2, 0
_080048E8: .4byte gUnknown_20255F0
_080048EC: .4byte gUnknown_2025648
_080048F0: .4byte gUnknown_2025668
_080048F4: .4byte 0x000003e7
	thumb_func_end sub_80048D0

	thumb_func_start sub_80048F8
sub_80048F8:
	ldr r0, _08004908
	movs r1, 0
	strh r1, [r0, 0x2]
	ldr r0, _0800490C
	strh r1, [r0, 0x2]
	ldr r0, _08004910
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08004908: .4byte gUnknown_20255F0
_0800490C: .4byte gUnknown_2025638
_08004910: .4byte gUnknown_2025648
	thumb_func_end sub_80048F8

	thumb_func_start sub_8004914
sub_8004914:
	ldr r0, _0800494C
	movs r1, 0x5
	str r1, [r0, 0x20]
	movs r2, 0
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r1, _08004950
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r2, [r1]
	adds r0, 0x29
	strb r2, [r0]
	bx lr
	.align 2, 0
_0800494C: .4byte gUnknown_2025600
_08004950: .4byte 0x0000ffff
	thumb_func_end sub_8004914

	thumb_func_start UpdateInput
UpdateInput:
	push {r4-r6,lr}
	ldr r4, _08004998
	ldr r5, _0800499C
	adds r1, r4, 0
	adds r0, r5, 0
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, 0
	bl ReadKeyInput
	ldrh r0, [r4]
	ldrh r3, [r5]
	eors r0, r3
	ands r0, r3
	strh r0, [r5, 0x2]
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080049A8
	ldrh r1, [r5, 0x8]
	movs r0, 0xF0
	adds r2, r0, 0
	ands r2, r3
	ands r0, r1
	cmp r0, r2
	bne _080049A0
	ldr r0, [r5, 0xC]
	cmp r0, 0x31
	bgt _080049AC
	adds r0, 0x1
	str r0, [r5, 0xC]
	b _080049AC
	.align 2, 0
_08004998: .4byte gUnknown_2025658
_0800499C: .4byte gUnknown_2025648
_080049A0:
	strh r2, [r5, 0x8]
	movs r0, 0x1
	str r0, [r5, 0xC]
	b _080049AC
_080049A8:
	str r0, [r5, 0xC]
	strh r0, [r5, 0x8]
_080049AC:
	ldr r0, _080049C4
	ldr r2, [r0, 0xC]
	adds r3, r0, 0
	cmp r2, 0x1
	bne _080049C8
	ldrh r0, [r3, 0x8]
	movs r1, 0xF0
	ands r1, r0
	ldrh r0, [r3, 0x2]
	orrs r1, r0
	strh r1, [r3, 0x4]
	b _080049E0
	.align 2, 0
_080049C4: .4byte gUnknown_2025648
_080049C8:
	cmp r2, 0x30
	bne _080049DC
	movs r0, 0x2B
	str r0, [r3, 0xC]
	ldrh r1, [r3, 0x8]
	movs r0, 0xF0
	ands r0, r1
	ldrh r1, [r3, 0x2]
	orrs r0, r1
	b _080049DE
_080049DC:
	movs r0, 0
_080049DE:
	strh r0, [r3, 0x4]
_080049E0:
	movs r0, 0
	strh r0, [r3, 0x6]
	ldrh r1, [r3]
	movs r5, 0x2
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08004A0C
	ldr r0, _08004A08
	ldrh r2, [r0]
	movs r4, 0
	ldrsh r1, [r0, r4]
	adds r4, r0, 0
	cmp r1, 0x63
	bgt _08004A20
	adds r0, r2, 0x1
	strh r0, [r4]
	b _08004A20
	.align 2, 0
_08004A08: .4byte gUnknown_2025668
_08004A0C:
	ldr r1, _08004A44
	ldrh r0, [r1]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	adds r4, r1, 0
	cmp r0, 0x9
	bhi _08004A1E
	strh r5, [r3, 0x6]
_08004A1E:
	strh r2, [r4]
_08004A20:
	ldrh r1, [r3]
	movs r5, 0x80
	lsls r5, 1
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08004A48
	ldrh r1, [r4, 0x2]
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	cmp r0, 0x63
	bgt _08004A5E
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _08004A5E
	.align 2, 0
_08004A44: .4byte gUnknown_2025668
_08004A48:
	ldrh r0, [r4, 0x2]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x9
	bhi _08004A5C
	ldrh r1, [r3, 0x6]
	adds r0, r5, 0
	orrs r0, r1
	strh r0, [r3, 0x6]
_08004A5C:
	strh r2, [r4, 0x2]
_08004A5E:
	ldr r2, _08004A94
	ldrh r0, [r2]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r3, 0x2]
	orrs r0, r1
	strh r0, [r2, 0x2]
	ldrh r0, [r2, 0x4]
	ldrh r1, [r3, 0x4]
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r2, 0x6]
	ldrh r1, [r3, 0x6]
	orrs r0, r1
	strh r0, [r2, 0x6]
	ldr r2, _08004A98
	ldrh r0, [r3]
	ldr r1, _08004A9C
	orrs r0, r1
	ldr r1, [r2]
	muls r0, r1
	str r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004A94: .4byte gUnknown_2025638
_08004A98: .4byte gUnknown_202562C
_08004A9C: .4byte 0x054a1c41
	thumb_func_end UpdateInput

	thumb_func_start nullsub_6
nullsub_6:
	bx lr
	thumb_func_end nullsub_6

	thumb_func_start sub_8004AA4
sub_8004AA4:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r4, [r1, 0x4]
	cmp r2, 0
	ble _08004AE8
_08004AAE:
	ldm r4!, {r1}
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, 0
	beq _08004ADE
	movs r0, 0x80
	lsls r0, 24
	str r0, [r3]
	ldrh r0, [r1, 0x2]
	strh r0, [r3, 0x6]
	ldrh r0, [r1, 0x2]
	strh r0, [r3, 0x4]
	adds r0, r1, 0x4
	str r0, [r3, 0x8]
	str r0, [r3, 0xC]
	movs r5, 0
	ldrsh r0, [r1, r5]
	lsls r0, 2
	adds r0, 0x4
	adds r0, r1, r0
	str r0, [r3, 0x10]
	ldr r0, [r1, 0x4]
	str r0, [r3, 0x14]
	b _08004AE0
_08004ADE:
	str r0, [r3]
_08004AE0:
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bne _08004AAE
_08004AE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8004AA4

	thumb_func_start sub_8004AF0
sub_8004AF0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	cmp r7, r3
	bge _08004B6A
	adds r5, r3, 0
_08004B08:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004B60
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004B60
	mov r1, r8
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004B4E
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004B42
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004B42:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r1, 0x1
	movs r7, 0x1
_08004B4E:
	cmp r1, 0
	beq _08004B60
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl SetBGPaletteBufferColorRGB
_08004B60:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bne _08004B08
_08004B6A:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8004AF0

	thumb_func_start sub_8004B78
sub_8004B78:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	cmp r7, r3
	bge _08004BF2
	adds r5, r3, 0
_08004B90:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004BE8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004BE8
	mov r1, r8
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004BD6
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004BCA
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004BCA:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r1, 0x1
	movs r7, 0x1
_08004BD6:
	cmp r1, 0
	beq _08004BE8
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl nullsub_4
_08004BE8:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bne _08004B90
_08004BF2:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8004B78

	thumb_func_start sub_8004C00
sub_8004C00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r10, r3
	ldr r0, [sp, 0x28]
	mov r8, r0
	movs r1, 0
	mov r9, r1
	cmp r9, r2
	bge _08004CDC
	adds r6, r2, 0
_08004C20:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004CD2
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004CD2
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004C64
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004C58
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004C58:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r2, 0x1
	mov r9, r2
_08004C64:
	mov r3, r8
	movs r5, 0
	ldrsh r0, [r3, r5]
	ldrb r2, [r4, 0x14]
	adds r1, r0, r2
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	ldrb r2, [r4, 0x15]
	adds r3, r0, r2
	mov r5, r8
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldrb r2, [r4, 0x16]
	adds r5, r0, r2
	cmp r1, 0xFF
	ble _08004C86
	movs r1, 0xFF
_08004C86:
	cmp r3, 0xFF
	ble _08004C8C
	movs r3, 0xFF
_08004C8C:
	cmp r5, 0xFF
	ble _08004C92
	movs r5, 0xFF
_08004C92:
	cmp r1, 0
	bge _08004C98
	movs r1, 0
_08004C98:
	cmp r3, 0
	bge _08004C9E
	movs r3, 0
_08004C9E:
	cmp r5, 0
	bge _08004CA4
	movs r5, 0
_08004CA4:
	lsls r1, 24
	lsrs r1, 24
	ldr r2, _08004CF0
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r3, 24
	lsrs r2, 16
	ldr r1, _08004CF4
	ands r0, r1
	orrs r0, r2
	lsls r2, r5, 24
	lsrs r2, 8
	ldr r1, _08004CF8
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	adds r0, r7, 0
	mov r1, sp
	mov r2, r10
	ldr r3, [sp, 0x24]
	bl SetBGPaletteBufferColorRGB
_08004CD2:
	subs r6, 0x1
	adds r4, 0x18
	adds r7, 0x1
	cmp r6, 0
	bne _08004C20
_08004CDC:
	mov r0, r9
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08004CF0: .4byte 0xffffff00
_08004CF4: .4byte 0xffff00ff
_08004CF8: .4byte 0xff00ffff
	thumb_func_end sub_8004C00

	thumb_func_start sub_8004CFC
sub_8004CFC:
	push {lr}
	cmp r1, 0
	ble _08004D0E
	movs r2, 0
_08004D04:
	str r2, [r0]
	adds r0, 0x18
	subs r1, 0x1
	cmp r1, 0
	bne _08004D04
_08004D0E:
	pop {r0}
	bx r0
	thumb_func_end sub_8004CFC

	thumb_func_start sub_8004D14
sub_8004D14:
	push {r4,lr}
	adds r2, r0, 0
	movs r3, 0
	cmp r3, r1
	bge _08004D36
	movs r4, 0x80
	lsls r4, 24
_08004D22:
	ldr r0, [r2]
	ands r0, r4
	cmp r0, 0
	beq _08004D2E
	movs r0, 0x1
	b _08004D38
_08004D2E:
	adds r2, 0x18
	adds r3, 0x1
	cmp r3, r1
	blt _08004D22
_08004D36:
	movs r0, 0
_08004D38:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8004D14

	thumb_func_start sub_8004D40
sub_8004D40:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	movs r1, 0
	cmp r1, r4
	bge _08004D70
	movs r6, 0x80
	lsls r6, 24
	movs r5, 0x80
	lsls r5, 22
_08004D54:
	ldr r2, [r3]
	adds r0, r2, 0
	ands r0, r6
	cmp r0, 0
	beq _08004D6A
	ands r2, r5
	cmp r2, 0
	bne _08004D68
	movs r0, 0
	b _08004D72
_08004D68:
	adds r3, 0x18
_08004D6A:
	adds r1, 0x1
	cmp r1, r4
	blt _08004D54
_08004D70:
	movs r0, 0x1
_08004D72:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8004D40

	thumb_func_start sub_8004D78
sub_8004D78:
	push {lr}
	movs r0, 0x1
	bl sub_8004D8C
	movs r0, 0
	bl SetSavingIconCoords
	pop {r0}
	bx r0
	thumb_func_end sub_8004D78

	thumb_func_start sub_8004D8C
sub_8004D8C:
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
_08004E68: .4byte gUnknown_20266A8
_08004E6C: .4byte gUnknown_2026E30
_08004E70: .4byte 0x06010000
_08004E74: .4byte gUnknown_203B074
_08004E78: .4byte gUnknown_20266B0
_08004E7C: .4byte gUnknown_20256A0
_08004E80: .4byte gUnknown_20262A8
_08004E84: .4byte gUnknown_2025EA8
_08004E88: .4byte 0x00000804
	thumb_func_end sub_8004D8C

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
_08004F40: .4byte gUnknown_20266A8
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
_080050F4: .4byte gUnknown_20266A8
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
_08005178: .4byte gUnknown_20266A8
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
_080052FC: .4byte gUnknown_2026E30
_08005300: .4byte gUnknown_2026E30
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
_08005368: .4byte gUnknown_2026E30
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

	thumb_func_start sub_800558C
sub_800558C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _080055AE
	adds r0, r5, 0
	bl sub_80054BC
_080055AE:
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	ldrh r0, [r5, 0xC]
	adds r0, r4
	strh r0, [r5, 0x8]
	ldrh r0, [r5, 0xE]
	adds r0, r6
	strh r0, [r5, 0xA]
	adds r1, r5, 0
	adds r1, 0x26
	ldr r0, [sp, 0x18]
	strb r0, [r1]
	strh r7, [r5, 0x1E]
	ldr r0, [r5, 0x34]
	ldr r1, [r5, 0x38]
	adds r2, r5, 0
	adds r2, 0x8
	movs r3, 0x22
	ldrsh r4, [r5, r3]
	movs r6, 0x20
	ldrsh r3, [r5, r6]
	eors r4, r3
	negs r3, r4
	orrs r3, r4
	lsrs r3, 31
	str r3, [sp]
	ldr r3, [sp, 0x1C]
	bl sub_800533C
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x22]
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	beq _08005602
	ldr r0, _0800560C
	ands r0, r1
	strh r0, [r5]
_08005602:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800560C: .4byte 0x0000f7ff
	thumb_func_end sub_800558C

	thumb_func_start sub_8005610
sub_8005610:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_800561C
	pop {r0}
	bx r0
	thumb_func_end sub_8005610

	thumb_func_start sub_800561C
sub_800561C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	ldr r1, [r5, 0x14]
	cmp r1, 0
	beq _0800563A
	lsls r0, 5
	ldr r2, _08005664
	adds r0, r2
	ldr r2, [r5, 0x1C]
	lsls r2, 5
	bl CpuCopy
_0800563A:
	ldr r0, [r5, 0x18]
	cmp r0, 0
	beq _0800565C
	movs r4, 0
_08005642:
	movs r1, 0xF0
	lsls r1, 1
	adds r0, r4, r1
	lsls r2, r4, 2
	ldr r1, [r5, 0x18]
	adds r1, r2
	adds r2, r7, 0
	adds r3, r6, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x1
	cmp r4, 0xF
	ble _08005642
_0800565C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005664: .4byte 0x06010000
	thumb_func_end sub_800561C

	thumb_func_start sub_8005668
sub_8005668:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_8005674
	pop {r1}
	bx r1
	thumb_func_end sub_8005668

	thumb_func_start sub_8005674
sub_8005674:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r4, 0x14]
	cmp r3, 0
	beq _0800568E
	lsls r0, r1, 5
	ldr r1, _08005698
	adds r0, r1
	ldr r2, [r4, 0x1C]
	lsls r2, 5
	adds r1, r3, 0
	bl CpuCopy
_0800568E:
	ldr r0, [r4, 0x18]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005698: .4byte 0x06010000
	thumb_func_end sub_8005674

	thumb_func_start sub_800569C
sub_800569C:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	strh r0, [r3]
	strh r0, [r3, 0x2]
	ldrh r0, [r4]
	lsrs r0, 15
	cmp r0, 0
	beq _080056F8
	cmp r2, 0x3
	bhi _080056F8
	ldr r1, [r4, 0x30]
	cmp r1, 0
	beq _080056F2
	movs r5, 0x20
	ldrsh r0, [r4, r5]
	lsls r0, 4
	adds r5, r1, r0
	lsls r0, r2, 2
	adds r2, r5, r0
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	movs r6, 0x2
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	strh r1, [r3]
	strh r1, [r3, 0x2]
	b _080056F8
_080056E0:
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r4, 0xC]
	adds r1, r2
	strh r1, [r3]
	ldrh r0, [r0, 0x2]
	ldrh r4, [r4, 0xE]
	adds r0, r4
	b _080056F6
_080056F2:
	movs r0, 0x63
	strh r0, [r3]
_080056F6:
	strh r0, [r3, 0x2]
_080056F8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800569C

	thumb_func_start sub_8005700
sub_8005700:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldrh r0, [r1]
	lsrs r0, 15
	cmp r0, 0
	beq _0800575C
	ldr r2, [r1, 0x30]
	cmp r2, 0
	beq _0800574C
	movs r4, 0x20
	ldrsh r0, [r1, r4]
	lsls r0, 4
	adds r2, r0
	adds r4, r2, 0
	adds r4, 0xC
_0800571E:
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	strh r0, [r3]
	b _08005740
_08005732:
	ldrh r0, [r2]
	ldrh r5, [r1, 0xC]
	adds r0, r5
	strh r0, [r3]
	ldrh r0, [r2, 0x2]
	ldrh r5, [r1, 0xE]
	adds r0, r5
_08005740:
	strh r0, [r3, 0x2]
	adds r3, 0x4
	adds r2, 0x4
	cmp r2, r4
	ble _0800571E
	b _0800575C
_0800574C:
	movs r1, 0x63
	movs r0, 0x3
_08005750:
	strh r1, [r3]
	strh r1, [r3, 0x2]
	adds r3, 0x4
	subs r0, 0x1
	cmp r0, 0
	bge _08005750
_0800575C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8005700

	thumb_func_start sub_8005764
sub_8005764:
	push {lr}
	ldr r1, [r1, 0x4]
	bl sub_8005770
	pop {r0}
	bx r0
	thumb_func_end sub_8005764

	thumb_func_start sub_8005770
sub_8005770:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	adds r7, r3, 0
	movs r5, 0
	adds r0, 0x10
	lsls r6, r0, 4
	adds r4, r1, 0
_08005782:
	adds r0, r6, r5
	adds r1, r4, 0
	mov r2, r8
	adds r3, r7, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08005782
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8005770

	thumb_func_start nullsub_7
nullsub_7:
	bx lr
	thumb_func_end nullsub_7

	thumb_func_start nullsub_8
nullsub_8:
	bx lr
	thumb_func_end nullsub_8

	thumb_func_start nullsub_9
nullsub_9:
	bx lr
	thumb_func_end nullsub_9

	thumb_func_start nullsub_10
nullsub_10:
	bx lr
	thumb_func_end nullsub_10

	thumb_func_start nullsub_144
nullsub_144:
	bx lr
	thumb_func_end nullsub_144

	thumb_func_start nullsub_11
nullsub_11:
	bx lr
	thumb_func_end nullsub_11

	thumb_func_start nullsub_12
nullsub_12:
	bx lr
	thumb_func_end nullsub_12

	thumb_func_start nullsub_13
nullsub_13:
	bx lr
	thumb_func_end nullsub_13

	thumb_func_start nullsub_145
nullsub_145:
	bx lr
	thumb_func_end nullsub_145

	thumb_func_start nullsub_14
nullsub_14:
	bx lr
	thumb_func_end nullsub_14

	thumb_func_start nullsub_146
nullsub_146:
	bx lr
	thumb_func_end nullsub_146

	thumb_func_start nullsub_147
nullsub_147:
	bx lr
	thumb_func_end nullsub_147

	thumb_func_start nullsub_148
nullsub_148:
	bx lr
	thumb_func_end nullsub_148

	thumb_func_start nullsub_149
nullsub_149:
	bx lr
	thumb_func_end nullsub_149

	thumb_func_start sub_80057D8
sub_80057D8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80057D8

	thumb_func_start sub_80057DC
sub_80057DC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80057DC

	thumb_func_start nullsub_150
nullsub_150:
	bx lr
	thumb_func_end nullsub_150

	thumb_func_start nullsub_151
nullsub_151:
	bx lr
	thumb_func_end nullsub_151

	thumb_func_start sub_80057E8
sub_80057E8:
	ldr r1, _08005814
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _08005818
	movs r2, 0
	str r2, [r0]
	ldr r1, _0800581C
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08005820
	str r2, [r0]
	ldr r0, _08005824
	str r2, [r0]
	ldr r0, _08005828
	strb r2, [r0]
	ldr r1, _0800582C
	ldr r3, _08005830
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, _08005834
	str r2, [r0]
	bx lr
	.align 2, 0
_08005814: .4byte gUnknown_2026E4C
_08005818: .4byte gUnknown_2026E54
_0800581C: .4byte gUnknown_2026E50
_08005820: .4byte gUnknown_2026E58
_08005824: .4byte gUnknown_2026E3C
_08005828: .4byte gUnknown_2026E38
_0800582C: .4byte gUnknown_2026E4E
_08005830: .4byte 0x0000060c
_08005834: .4byte gUnknown_203B078
	thumb_func_end sub_80057E8

	thumb_func_start sub_8005838
sub_8005838:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, _08005880
	ldrb r0, [r0]
	cmp r0, 0
	bne _08005854
	movs r1, 0
_08005854:
	ldr r0, _08005884
	ldr r0, [r0]
	ldr r3, _08005888
	cmp r0, 0
	bne _08005860
	ldr r3, _0800588C
_08005860:
	ldr r0, _08005890
	ldr r2, [r0]
	cmp r2, 0
	bne _0800586A
	ldr r2, _08005894
_0800586A:
	ldr r0, _08005898
	str r3, [r0]
	cmp r1, 0x5
	bls _08005876
	bl _08006094
_08005876:
	lsls r0, r1, 2
	ldr r1, _0800589C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08005880: .4byte gUnknown_2026E4C
_08005884: .4byte gUnknown_2026E54
_08005888: .4byte gUnknown_20270E8
_0800588C: .4byte gUnknown_2026E60
_08005890: .4byte gUnknown_203B078
_08005894: .4byte gUnknown_80B83EA
_08005898: .4byte gUnknown_2026E58
_0800589C: .4byte _080058A0
	.align 2, 0
_080058A0:
	.4byte _080058B8
	.4byte _08005984
	.4byte _08005A98
	.4byte _08005BAC
	.4byte _08005D46
	.4byte _08005E58
_080058B8:
	movs r1, 0
	movs r7, 0x9
_080058BC:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _080058BC
	b _08006094
_08005984:
	ldr r1, _08005A94
	movs r7, 0x9
_08005988:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005A90
	b _08005988
_08005A90:
	b _08006094
	.align 2, 0
_08005A94: .4byte gUnknown_80B816A
_08005A98:
	ldr r1, _08005BA8
	movs r7, 0x9
_08005A9C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005BA4
	b _08005A9C
_08005BA4:
	b _08006094
	.align 2, 0
_08005BA8: .4byte gUnknown_80B802A
_08005BAC:
	ldr r0, [r5]
	mov r10, r0
	cmp r0, 0
	bge _08005BBA
	ldr r0, [r5, 0x8]
	cmp r0, 0
	blt _08005BDC
_08005BBA:
	ldr r1, [r5, 0x4]
	cmp r1, 0
	bge _08005BC6
	ldr r0, [r5, 0xC]
	cmp r0, 0
	blt _08005BDC
_08005BC6:
	mov r4, r10
	cmp r4, 0xEF
	ble _08005BD2
	ldr r0, [r5, 0x8]
	cmp r0, 0xEF
	bgt _08005BDC
_08005BD2:
	cmp r1, 0x9F
	ble _08005CA8
	ldr r0, [r5, 0xC]
	cmp r0, 0x9F
	ble _08005CA8
_08005BDC:
	movs r1, 0xF0
	movs r7, 0x9
_08005BE0:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005BE0
	b _08006094
_08005CA8:
	movs r7, 0
	mov r8, r1
	movs r6, 0x80
	lsls r6, 1
	mov r12, r6
	lsls r0, r1, 1
	ldr r1, _08005CCC
	subs r6, r1, r0
	mov r9, r10
_08005CBA:
	cmp r8, r7
	ble _08005CD0
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r4, r12
	strh r4, [r3]
	b _08005D3A
	.align 2, 0
_08005CCC: .4byte gUnknown_80B8008
_08005CD0:
	ldr r1, [r5, 0xC]
	cmp r1, r7
	bgt _08005CE2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r0, r12
	b _08005D38
_08005CE2:
	mov r4, r8
	subs r0, r7, r4
	cmp r0, 0xF
	bgt _08005CF0
	movs r0, 0
	ldrsh r1, [r6, r0]
	b _08005D00
_08005CF0:
	subs r0, r1, r7
	cmp r0, 0xF
	bgt _08005D10
	lsls r0, 1
	ldr r1, _08005D0C
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
_08005D00:
	mov r0, r9
	adds r4, r0, r1
	ldr r0, [r5, 0x8]
	subs r1, r0, r1
	b _08005D14
	.align 2, 0
_08005D0C: .4byte gUnknown_80B8008
_08005D10:
	mov r4, r10
	ldr r1, [r5, 0x8]
_08005D14:
	cmp r4, 0
	bge _08005D1A
	movs r4, 0
_08005D1A:
	cmp r4, 0xEF
	ble _08005D20
	movs r4, 0xEF
_08005D20:
	cmp r1, 0
	bgt _08005D26
	movs r1, 0x1
_08005D26:
	cmp r1, 0xF0
	ble _08005D2C
	movs r1, 0xF0
_08005D2C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	lsls r0, r1, 8
	orrs r0, r4
_08005D38:
	strh r0, [r3]
_08005D3A:
	adds r3, 0x2
	adds r6, 0x2
	adds r7, 0x1
	cmp r7, 0x9F
	ble _08005CBA
	b _08006094
_08005D46:
	ldr r1, _08005E54
	movs r7, 0xE
_08005D4A:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005E52
	b _08005D4A
_08005E52:
	b _08006094
	.align 2, 0
_08005E54: .4byte gUnknown_80B82AA
_08005E58:
	ldr r4, _08005FF4
	ldr r5, _08005FF8
	ldr r6, _08005FFC
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0, 0
	movs r7, 0xE
_08005E66:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005E66
	ldr r4, [r4]
	str r4, [sp]
	ldr r5, [r5]
	str r5, [sp, 0x4]
	ldr r6, [r6]
	str r6, [sp, 0x8]
	adds r1, r6, 0
	cmp r6, 0
	bge _08005F40
	adds r1, 0xFF
_08005F40:
	asrs r1, 8
	adds r1, 0x1
	movs r0, 0x80
	lsls r0, 3
	bl __divsi3
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _08005F56
	adds r0, 0xFF
_08005F56:
	asrs r4, r0, 8
	adds r5, r4, 0
	movs r3, 0
	lsls r0, r4, 2
	adds r7, r0, 0x2
	mov r9, r7
_08005F62:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009C7C
	ldr r1, [sp, 0x8]
	muls r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005F76
	adds r0, 0xFF
_08005F76:
	asrs r0, 8
	ldr r2, [sp, 0x4]
	adds r1, r2, r0
	cmp r1, 0
	bge _08005F82
	adds r1, 0xFF
_08005F82:
	asrs r1, 8
	str r1, [sp, 0x14]
	ldr r6, [sp, 0x4]
	subs r0, r6, r0
	cmp r0, 0
	bge _08005F90
	adds r0, 0xFF
_08005F90:
	asrs r0, 8
	mov r8, r0
	ldr r0, [sp, 0x14]
	cmp r5, r0
	blt _08005FA4
	ldr r1, [sp, 0xC]
	adds r1, r3
	mov r10, r1
	cmp r4, r8
	ble _0800608A
_08005FA4:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009D04
	ldr r2, [sp, 0x8]
	muls r0, r2
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005FB8
	adds r0, 0xFF
_08005FB8:
	asrs r0, 8
	ldr r6, [sp]
	subs r1, r6, r0
	cmp r1, 0
	bge _08005FC4
	adds r1, 0xFF
_08005FC4:
	asrs r1, 8
	ldr r2, [sp]
	adds r0, r2, r0
	cmp r0, 0
	bge _08005FD0
	adds r0, 0xFF
_08005FD0:
	asrs r0, 8
	cmp r1, 0
	bge _08005FD8
	movs r1, 0
_08005FD8:
	cmp r0, 0
	bge _08005FDE
	movs r0, 0
_08005FDE:
	cmp r1, 0xEF
	ble _08005FE4
	movs r1, 0x9F
_08005FE4:
	cmp r0, 0xEF
	ble _08005FEA
	movs r0, 0x9F
_08005FEA:
	cmp r1, r0
	ble _08006000
	lsls r2, r1, 8
	orrs r2, r0
	b _08006004
	.align 2, 0
_08005FF4: .4byte gUnknown_2026E40
_08005FF8: .4byte gUnknown_2026E44
_08005FFC: .4byte gUnknown_2026E48
_08006000:
	lsls r2, r0, 8
	orrs r2, r1
_08006004:
	ldr r6, [sp, 0xC]
	adds r3, r6
	mov r10, r3
	ldr r0, [sp, 0x14]
	cmp r5, r0
	bge _0800604E
	ldr r1, _08006030
	mov r12, r1
	ldr r3, _08006034
	add r3, r9
	ldr r1, _08006038
	add r1, r9
_0800601C:
	cmp r5, 0
	blt _0800603E
	cmp r5, 0x9F
	bgt _0800603E
	mov r6, r12
	ldr r0, [r6]
	cmp r0, 0
	bne _0800603C
	strh r2, [r1]
	b _0800603E
	.align 2, 0
_08006030: .4byte gUnknown_2026E54
_08006034: .4byte gUnknown_20270E8
_08006038: .4byte gUnknown_2026E60
_0800603C:
	strh r2, [r3]
_0800603E:
	adds r3, 0x4
	adds r1, 0x4
	movs r0, 0x4
	add r9, r0
	adds r5, 0x1
	ldr r6, [sp, 0x14]
	cmp r5, r6
	blt _0800601C
_0800604E:
	cmp r4, r8
	ble _0800608A
	ldr r6, _08006070
	ldr r0, _08006074
	adds r3, r7, r0
	ldr r0, _08006078
	adds r1, r7, r0
_0800605C:
	cmp r4, 0
	blt _0800607E
	cmp r4, 0x9F
	bgt _0800607E
	ldr r0, [r6]
	cmp r0, 0
	bne _0800607C
	strh r2, [r1]
	b _0800607E
	.align 2, 0
_08006070: .4byte gUnknown_2026E54
_08006074: .4byte gUnknown_20270E8
_08006078: .4byte gUnknown_2026E60
_0800607C:
	strh r2, [r3]
_0800607E:
	subs r3, 0x4
	subs r1, 0x4
	subs r7, 0x4
	subs r4, 0x1
	cmp r4, r8
	bgt _0800605C
_0800608A:
	mov r3, r10
	ldr r0, _080060A4
	cmp r3, r0
	bgt _08006094
	b _08005F62
_08006094:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080060A4: .4byte 0x000003ff
	thumb_func_end sub_8005838

	thumb_func_start sub_80060A8
sub_80060A8:
	push {lr}
	ldr r1, _080060D8
	ldr r0, _080060DC
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, _080060E0
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _080060BE
	movs r1, 0x1
_080060BE:
	str r1, [r2]
	ldr r2, _080060E4
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _080060CC
	movs r1, 0x1
_080060CC:
	str r1, [r2]
	ldr r1, _080060E8
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080060D8: .4byte gUnknown_2026E3C
_080060DC: .4byte gUnknown_2026E58
_080060E0: .4byte gUnknown_2026E54
_080060E4: .4byte gUnknown_2026E50
_080060E8: .4byte gUnknown_2026E38
	thumb_func_end sub_80060A8

	thumb_func_start sub_80060EC
sub_80060EC:
	push {lr}
	ldr r1, _08006130
	ldr r0, _08006134
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, _08006138
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _08006102
	movs r1, 0x1
_08006102:
	str r1, [r2]
	ldr r2, _0800613C
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _08006110
	movs r1, 0x1
_08006110:
	str r1, [r2]
	ldr r0, _08006140
	ldrh r2, [r0]
	movs r0, 0xF8
	lsls r0, 5
	ands r0, r2
	lsrs r0, 8
	movs r1, 0x1F
	ands r1, r2
	bl sub_800CC44
	ldr r1, _08006144
	movs r0, 0x1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08006130: .4byte gUnknown_2026E3C
_08006134: .4byte gUnknown_2026E58
_08006138: .4byte gUnknown_2026E54
_0800613C: .4byte gUnknown_2026E50
_08006140: .4byte gUnknown_2026E4E
_08006144: .4byte gUnknown_2026E38
	thumb_func_end sub_80060EC

	.align 2, 0 @ Don't pad with nop.
