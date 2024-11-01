	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_803E250
sub_803E250:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r1, _0803E3FC
	ldr r0, _0803E400
	str r0, [r1]
	ldr r0, _0803E404
	movs r1, 0
	str r1, [r0]
	ldr r0, _0803E408
	strb r1, [r0]
	ldr r0, _0803E40C
	strh r1, [r0]
	ldr r5, _0803E410
	ldrh r0, [r5, 0x6]
	movs r3, 0xF
	adds r2, r3, 0
	ands r2, r0
	ldrh r4, [r5]
	ldr r1, _0803E414
	adds r0, r1, 0
	ands r0, r4
	ldr r4, _0803E418
	ands r0, r4
	ldr r6, _0803E41C
	ands r0, r6
	ldr r7, _0803E420
	ands r0, r7
	ldr r4, _0803E424
	mov r12, r4
	ands r0, r4
	ldr r4, _0803E428
	ands r0, r4
	strh r0, [r5]
	movs r0, 0x80
	lsls r0, 7
	strh r0, [r5, 0x2]
	movs r0, 0
	strh r0, [r5, 0x4]
	ldr r0, _0803E42C
	mov r10, r0
	ands r2, r0
	subs r0, 0x1
	mov r9, r0
	ands r2, r0
	subs r0, 0x2
	mov r8, r0
	ands r2, r0
	strh r2, [r5, 0x6]
	ldr r2, _0803E430
	ldrh r0, [r2, 0x6]
	ands r3, r0
	ldrh r0, [r2]
	ands r1, r0
	ldr r0, _0803E418
	ands r1, r0
	ands r1, r6
	ands r1, r7
	mov r7, r12
	ands r1, r7
	ands r1, r4
	strh r1, [r2]
	movs r0, 0
	strh r0, [r2, 0x2]
	movs r0, 0xB8
	lsls r0, 7
	strh r0, [r2, 0x4]
	mov r0, r10
	ands r3, r0
	mov r1, r9
	ands r3, r1
	mov r7, r8
	ands r3, r7
	strh r3, [r2, 0x6]
	movs r0, 0
	mov r8, r0
_0803E2EE:
	movs r1, 0
	mov r9, r1
	mov r2, r8
	lsls r0, r2, 3
	lsls r2, 1
	mov r12, r2
	mov r3, r8
	adds r3, 0x1
	str r3, [sp]
	mov r10, r1
	add r0, r8
	lsls r5, r0, 3
	ldr r4, _0803E434
	adds r4, r5, r4
	str r4, [sp, 0x4]
	ldr r7, _0803E438
	adds r6, r5, r7
	ldr r0, _0803E43C
	adds r3, r5, r0
	ldr r1, _0803E440
	adds r4, r5, r1
_0803E318:
	mov r7, r10
	adds r2, r5, r7
	ldrh r1, [r3]
	ldr r0, _0803E414
	ands r0, r1
	ldr r1, _0803E418
	ands r0, r1
	ldr r1, _0803E41C
	ands r0, r1
	ldr r1, _0803E420
	ands r0, r1
	ldr r1, _0803E424
	ands r0, r1
	strh r0, [r3]
	ldr r1, [r4]
	movs r7, 0x3
	ands r1, r7
	lsls r1, 14
	ldr r7, _0803E428
	ands r0, r7
	orrs r0, r1
	strh r0, [r3]
	ldrh r1, [r3, 0x2]
	ldr r0, _0803E444
	ands r0, r1
	strh r0, [r3, 0x2]
	ldr r1, _0803E440
	adds r1, 0x4
	adds r2, r1
	ldr r1, [r2]
	movs r2, 0x3
	ands r1, r2
	lsls r1, 14
	ands r0, r7
	orrs r0, r1
	strh r0, [r3, 0x2]
	ldr r1, [r6]
	ldr r0, _0803E448
	ands r1, r0
	ldrh r2, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	ldr r7, _0803E41C
	ands r0, r7
	movs r1, 0xC0
	lsls r1, 4
	orrs r0, r1
	movs r2, 0
	orrs r0, r2
	ldr r1, _0803E44C
	ands r0, r1
	strh r0, [r3, 0x4]
	ldrh r1, [r3, 0x6]
	ldr r0, _0803E42C
	ands r0, r1
	ldr r1, _0803E450
	ands r0, r1
	strh r0, [r3, 0x6]
	mov r7, r9
	lsls r1, r7, 2
	mov r0, r12
	add r0, r8
	lsls r0, 3
	adds r1, r0
	ldr r0, _0803E454
	adds r1, r0, r1
	ldr r0, [r1]
	ldr r1, [sp, 0x4]
	str r0, [r1]
	adds r1, 0xC
	str r1, [sp, 0x4]
	adds r6, 0xC
	adds r3, 0xC
	adds r4, 0xC
	movs r2, 0xC
	add r10, r2
	movs r7, 0x1
	add r9, r7
	mov r0, r9
	cmp r0, 0x5
	ble _0803E318
	ldr r1, [sp]
	mov r8, r1
	cmp r1, 0x1
	ble _0803E2EE
	movs r2, 0
	ldr r3, _0803E458
	ldr r0, [r3]
	ldr r4, _0803E45C
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r3]
	ldr r7, _0803E460
	adds r0, r7
	strb r1, [r0]
	ldr r0, _0803E464
	str r2, [r0]
	movs r0, 0xF8
	ldr r1, _0803E468
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E3FC: .4byte gUnknown_202EDD0
_0803E400: .4byte 0x000003e7
_0803E404: .4byte gUnknown_202EDD4
_0803E408: .4byte gUnknown_203B40D
_0803E40C: .4byte gUnknown_202EDE8
_0803E410: .4byte gUnknown_202EDC0
_0803E414: .4byte 0x0000feff
_0803E418: .4byte 0x0000fdff
_0803E41C: .4byte 0x0000f3ff
_0803E420: .4byte 0x0000efff
_0803E424: .4byte 0x0000dfff
_0803E428: .4byte 0x00003fff
_0803E42C: .4byte 0x0000fffe
_0803E430: .4byte gUnknown_202EDB8
_0803E434: .4byte gUnknown_202ED30
_0803E438: .4byte gUnknown_80F6224
_0803E43C: .4byte gUnknown_202ED28
_0803E440: .4byte gUnknown_80F621C
_0803E444: .4byte 0x0000c1ff
_0803E448: .4byte 0x000003ff
_0803E44C: .4byte 0x00000fff
_0803E450: .4byte 0x0000fffd
_0803E454: .4byte gUnknown_80F61EC
_0803E458: .4byte gDungeon
_0803E45C: .4byte 0x00018217
_0803E460: .4byte 0x00018218
_0803E464: .4byte gDungeonBrightness
_0803E468: .4byte gUnknown_202D058
	thumb_func_end sub_803E250
