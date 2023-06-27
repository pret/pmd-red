	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

    thumb_func_start AddMenuCursorSprite_
AddMenuCursorSprite_:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r1, 0x1A
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bgt _080131CC
	b _080132D6
_080131CC:
	adds r0, r6, 0
	bl UpdateMenuCursorSpriteCoords
	ldrh r1, [r6, 0x24]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080132D6
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _080132FC
	ands r1, r0
	ldr r3, _08013300
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013304
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r4, _08013308
	adds r0, r4, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0801330C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013310
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013314
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	ands r3, r1
	orrs r3, r0
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFD
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r5, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _08013318
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r1, _0801331C
	ands r1, r0
	ldr r0, _08013320
	ands r1, r0
	movs r2, 0x8
	ldrsh r0, [r6, r2]
	ldr r2, _08013324
	ands r0, r2
	strh r0, [r3, 0x2]
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	ands r0, r4
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080132D6:
	adds r0, r6, 0
	bl sub_8013470
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _080132EC
	adds r0, r6, 0
	adds r0, 0x14
	bl sub_801332C
_080132EC:
	ldrh r0, [r6, 0x24]
	adds r0, 0x1
	strh r0, [r6, 0x24]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080132FC: .4byte 0x0000feff
_08013300: .4byte 0xffff0000
_08013304: .4byte 0x0000fdff
_08013308: .4byte 0x0000f3ff
_0801330C: .4byte 0x0000efff
_08013310: .4byte 0x0000dfff
_08013314: .4byte 0x00003fff
_08013318: .4byte 0x00000fff
_0801331C: .4byte 0x0000fffe
_08013320: .4byte 0x0000fffd
_08013324: .4byte 0x000001ff
	thumb_func_end AddMenuCursorSprite_

	thumb_func_start nullsub_34
nullsub_34:
	bx lr
	thumb_func_end nullsub_34

	thumb_func_start sub_801332C
sub_801332C:
	push {r4-r6,lr}
	sub sp, 0x8
	movs r1, 0
	movs r2, 0
	str r1, [sp]
	str r2, [sp, 0x4]
	mov r1, sp
	ldrh r1, [r1]
	ldr r2, _08013440
	ands r2, r1
	ldr r4, _08013444
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r2
	str r1, [sp]
	mov r2, sp
	ldrh r2, [r2]
	adds r3, r4, 0
	ands r3, r1
	orrs r3, r2
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013448
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r1
	str r3, [sp]
	movs r5, 0x80
	lsls r5, 3
	mov r1, sp
	ldrh r2, [r1]
	ldr r6, _0801344C
	adds r1, r6, 0
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	orrs r5, r1
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r5
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013450
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r1
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013454
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r3, r4, 0
	ands r3, r2
	orrs r3, r1
	str r3, [sp]
	mov r1, sp
	ldrh r2, [r1]
	ldr r1, _08013458
	ands r1, r2
	adds r2, r4, 0
	ands r2, r3
	orrs r2, r1
	str r2, [sp]
	mov r1, sp
	ldrh r1, [r1]
	ands r4, r2
	orrs r4, r1
	str r4, [sp]
	mov r4, sp
	ldr r3, _0801345C
	ldrh r2, [r4, 0x4]
	movs r1, 0xFC
	lsls r1, 8
	ands r1, r2
	orrs r1, r3
	ands r1, r6
	movs r6, 0xF
	movs r2, 0xF0
	lsls r2, 8
	ldr r5, _08013460
	ands r1, r5
	orrs r1, r2
	strh r1, [r4, 0x4]
	ldrh r1, [r4, 0x6]
	ldr r2, _08013464
	ands r2, r1
	ldr r1, _08013468
	ands r2, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, _0801346C
	ands r1, r3
	strh r1, [r4, 0x2]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	adds r0, 0x1
	ands r0, r5
	lsls r0, 4
	ands r2, r6
	orrs r2, r0
	strh r2, [r4, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013440: .4byte 0x0000feff
_08013444: .4byte 0xffff0000
_08013448: .4byte 0x0000fdff
_0801344C: .4byte 0x0000f3ff
_08013450: .4byte 0x0000efff
_08013454: .4byte 0x0000dfff
_08013458: .4byte 0x00003fff
_0801345C: .4byte 0x000003f5
_08013460: .4byte 0x00000fff
_08013464: .4byte 0x0000fffe
_08013468: .4byte 0x0000fffd
_0801346C: .4byte 0x000001ff
	thumb_func_end sub_801332C

	thumb_func_start sub_8013470
sub_8013470:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08013488
	b _08013624
_08013488:
	movs r2, 0x1E
	ldrsh r0, [r6, r2]
	cmp r0, 0
	beq _08013586
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _0801362C
	ands r1, r0
	ldr r3, _08013630
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013634
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r4, _08013638
	adds r0, r4, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0801363C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013640
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013644
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	ands r3, r1
	orrs r3, r0
	str r3, [sp]
	mov r3, sp
	ldr r2, _08013648
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r5, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _0801364C
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r1, _08013650
	ands r1, r0
	ldr r0, _08013654
	ands r1, r0
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	ldr r2, _08013658
	ands r0, r2
	strh r0, [r3, 0x2]
	movs r2, 0xE
	ldrsh r0, [r6, r2]
	ands r0, r4
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08013586:
	movs r1, 0x20
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _08013624
	adds r1, r0, 0
	movs r2, 0x1E
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	cmp r1, r0
	beq _08013624
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _0801362C
	ands r1, r0
	mov r0, sp
	strh r1, [r0]
	strh r1, [r0]
	ldr r0, _08013634
	ands r0, r1
	mov r1, sp
	strh r0, [r1]
	strh r0, [r1]
	ldr r4, _08013638
	ands r0, r4
	strh r0, [r1]
	strh r0, [r1]
	ldr r1, _0801363C
	ands r1, r0
	mov r0, sp
	strh r1, [r0]
	strh r1, [r0]
	ldr r2, _08013640
	ands r2, r1
	strh r2, [r0]
	strh r2, [r0]
	ldr r0, _08013644
	ands r0, r2
	mov r1, sp
	strh r0, [r1]
	strh r0, [r1]
	mov r3, sp
	ldr r2, _0801365C
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r5, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _0801364C
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r3, 0x6]
	ldr r1, _08013650
	ands r1, r0
	ldr r0, _08013654
	ands r1, r0
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	adds r0, 0xA
	ldr r2, _08013658
	ands r0, r2
	strh r0, [r3, 0x2]
	movs r2, 0xE
	ldrsh r0, [r6, r2]
	ands r0, r4
	lsls r0, 4
	ands r1, r5
	orrs r1, r0
	strh r1, [r3, 0x6]
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08013624:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801362C: .4byte 0x0000feff
_08013630: .4byte 0xffff0000
_08013634: .4byte 0x0000fdff
_08013638: .4byte 0x0000f3ff
_0801363C: .4byte 0x0000efff
_08013640: .4byte 0x0000dfff
_08013644: .4byte 0x00003fff
_08013648: .4byte 0x000003f2
_0801364C: .4byte 0x00000fff
_08013650: .4byte 0x0000fffe
_08013654: .4byte 0x0000fffd
_08013658: .4byte 0x000001ff
_0801365C: .4byte 0x000003f3
	thumb_func_end sub_8013470

	thumb_func_start sub_8013660
sub_8013660:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x1A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _0801367A
	adds r0, r4, 0
	bl UpdateMenuCursorSpriteCoords
	adds r0, r4, 0
	adds r0, 0x8
	bl sub_801332C
_0801367A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8013660

	thumb_func_start UpdateMenuCursorSpriteCoords
UpdateMenuCursorSpriteCoords:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 3
	ldr r0, _080136B8
	adds r4, r0
	movs r1, 0
	ldrsh r0, [r4, r1]
	lsls r0, 3
	ldrh r2, [r5, 0x4]
	adds r0, r2
	strh r0, [r5, 0x8]
	movs r0, 0x18
	ldrsh r1, [r5, r0]
	adds r0, r5, 0
	bl sub_8013800
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r1, 3
	adds r1, r0
	strh r1, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080136B8: .4byte gUnknown_2027370
	thumb_func_end UpdateMenuCursorSpriteCoords

	thumb_func_start MoveMenuCursorDown
MoveMenuCursorDown:
	push {lr}
	adds r1, r0, 0
	movs r3, 0
	strh r3, [r1, 0x24]
	movs r0, 0x1A
	ldrsh r2, [r1, r0]
	cmp r2, 0
	ble _080136DA
	ldrh r0, [r1, 0x18]
	adds r0, 0x1
	strh r0, [r1, 0x18]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r2
	blt _080136DC
_080136DA:
	strh r3, [r1, 0x18]
_080136DC:
	pop {r0}
	bx r0
	thumb_func_end MoveMenuCursorDown

	thumb_func_start sub_80136E0
sub_80136E0:
	push {r4,r5,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r1, 0
	strh r1, [r2, 0x24]
	ldrh r4, [r2, 0x1A]
	movs r0, 0x1A
	ldrsh r3, [r2, r0]
	cmp r3, 0
	ble _08013708
	ldrh r0, [r2, 0x18]
	adds r0, 0x1
	strh r0, [r2, 0x18]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r3
	blt _08013710
	cmp r5, 0
	beq _0801370C
_08013708:
	strh r1, [r2, 0x18]
	b _08013710
_0801370C:
	subs r0, r4, 0x1
	strh r0, [r2, 0x18]
_08013710:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80136E0

	thumb_func_start MoveMenuCursorUp
MoveMenuCursorUp:
	push {r4,lr}
	adds r1, r0, 0
	movs r2, 0
	strh r2, [r1, 0x24]
	ldrh r3, [r1, 0x1A]
	movs r4, 0x1A
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bgt _0801372E
	strh r2, [r1, 0x18]
	b _0801373E
_0801372E:
	ldrh r0, [r1, 0x18]
	subs r0, 0x1
	strh r0, [r1, 0x18]
	lsls r0, 16
	cmp r0, 0
	bge _0801373E
	subs r0, r3, 0x1
	strh r0, [r1, 0x18]
_0801373E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end MoveMenuCursorUp

	thumb_func_start sub_8013744
sub_8013744:
	push {r4-r6,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r5, r1, 0
	movs r3, 0
	strh r3, [r2, 0x24]
	ldrh r4, [r2, 0x1A]
	movs r6, 0x1A
	ldrsh r0, [r2, r6]
	cmp r0, 0
	bgt _08013760
	strh r3, [r2, 0x18]
	b _08013778
_08013760:
	ldrh r0, [r2, 0x18]
	subs r0, 0x1
	strh r0, [r2, 0x18]
	lsls r0, 16
	cmp r0, 0
	bge _08013778
	cmp r1, 0
	beq _08013776
	subs r0, r4, 0x1
	strh r0, [r2, 0x18]
	b _08013778
_08013776:
	strh r5, [r2, 0x18]
_08013778:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8013744

	thumb_func_start sub_8013780
sub_8013780:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	bge _0801378E
	movs r0, 0
	strh r0, [r2, 0x18]
	b _080137A0
_0801378E:
	movs r3, 0x1A
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _0801379E
	ldrh r0, [r2, 0x1A]
	subs r0, 0x1
	strh r0, [r2, 0x18]
	b _080137A0
_0801379E:
	strh r1, [r2, 0x18]
_080137A0:
	movs r0, 0
	strh r0, [r2, 0x24]
	pop {r0}
	bx r0
	thumb_func_end sub_8013780

	thumb_func_start sub_80137A8
sub_80137A8:
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80137A8

	thumb_func_start sub_80137B0
sub_80137B0:
	push {r4,lr}
	adds r4, r0, 0
	cmp r1, 0
	ble _080137BC
	lsls r0, r1, 8
	b _080137E2
_080137BC:
	ldr r3, _080137F4
	ldr r1, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r1, r0, 3
	adds r0, r3, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	movs r2, 0
	cmp r0, 0x6
	bne _080137D6
	movs r2, 0x10
_080137D6:
	adds r0, r1, r3
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	lsls r0, 3
	subs r0, r2
	lsls r0, 8
_080137E2:
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __divsi3
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080137F4: .4byte gUnknown_2027370
	thumb_func_end sub_80137B0

	thumb_func_start sub_80137F8
sub_80137F8:
	lsls r1, 8
	str r1, [r0, 0x10]
	bx lr
	thumb_func_end sub_80137F8

	thumb_func_start sub_8013800
sub_8013800:
	push {lr}
	movs r3, 0x6
	ldrsh r2, [r0, r3]
	ldr r0, [r0, 0x10]
	muls r0, r1
	cmp r0, 0
	bge _08013810
	adds r0, 0xFF
_08013810:
	asrs r0, 8
	adds r0, r2, r0
	pop {r1}
	bx r1
	thumb_func_end sub_8013800

	thumb_func_start sub_8013818
sub_8013818:
	push {r4,lr}
	adds r4, r0, 0
	str r3, [r4]
	movs r0, 0
	strh r1, [r4, 0x22]
	strh r2, [r4, 0x1C]
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x18]
	strh r0, [r4, 0x1E]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	bl sub_8013984
	adds r0, r4, 0
	movs r1, 0xC
	bl sub_80137F8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8013818

	thumb_func_start sub_8013848
sub_8013848:
	push {r4,lr}
	adds r4, r0, 0
	str r3, [r4]
	movs r0, 0
	strh r1, [r4, 0x22]
	strh r2, [r4, 0x1C]
	strh r0, [r4, 0x14]
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x18]
	strh r0, [r4, 0x1E]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	bl sub_8013984
	adds r0, r4, 0
	movs r1, 0x18
	bl sub_80137F8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8013848

	thumb_func_start sub_8013878
sub_8013878:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r6, 0
	bge _08013886
	movs r6, 0
	b _08013890
_08013886:
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	cmp r6, r0
	blt _08013890
	subs r6, r0, 0x1
_08013890:
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	adds r0, r6, 0
	bl __divsi3
	movs r4, 0
	strh r0, [r5, 0x1E]
	movs r0, 0x1C
	ldrsh r1, [r5, r0]
	adds r0, r6, 0
	bl __modsi3
	strh r0, [r5, 0x18]
	strh r4, [r5, 0x24]
	adds r0, r5, 0
	bl sub_8013984
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8013878

	thumb_func_start sub_80138B8
sub_80138B8:
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	movs r0, 0x1E
	ldrsh r7, [r5, r0]
	movs r1, 0x18
	ldrsh r6, [r5, r1]
	adds r0, r5, 0
	bl AddMenuCursorSprite
	cmp r4, 0
	beq _0801391C
	adds r0, r5, 0
	bl GetKeyPress
	cmp r0, 0x8
	beq _080138F8
	cmp r0, 0x8
	bgt _080138E6
	cmp r0, 0x7
	beq _080138F0
	b _0801391C
_080138E6:
	cmp r0, 0x9
	beq _0801390E
	cmp r0, 0xA
	beq _08013916
	b _0801391C
_080138F0:
	adds r0, r5, 0
	bl MoveMenuCursorUp
	b _080138FE
_080138F8:
	adds r0, r5, 0
	bl MoveMenuCursorDown
_080138FE:
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	cmp r6, r0
	beq _0801391C
	movs r0, 0x3
	bl PlayMenuSoundEffect
	b _0801391C
_0801390E:
	adds r0, r5, 0
	bl sub_8013A7C
	b _0801391C
_08013916:
	adds r0, r5, 0
	bl sub_8013A54
_0801391C:
	movs r1, 0x1E
	ldrsh r0, [r5, r1]
	cmp r7, r0
	bne _08013928
	movs r0, 0
	b _08013930
_08013928:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x1
_08013930:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80138B8

	thumb_func_start sub_8013938
sub_8013938:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x1E
	ldrsh r5, [r4, r0]
	movs r0, 0
	strh r0, [r4, 0x1A]
	strh r0, [r4, 0x14]
	adds r0, r4, 0
	bl AddMenuCursorSprite
	adds r0, r4, 0
	bl GetKeyPress
	cmp r0, 0x9
	beq _0801395C
	cmp r0, 0xA
	beq _08013964
	b _0801396A
_0801395C:
	adds r0, r4, 0
	bl sub_8013A7C
	b _0801396A
_08013964:
	adds r0, r4, 0
	bl sub_8013A54
_0801396A:
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r5, r0
	bne _08013976
	movs r0, 0
	b _0801397E
_08013976:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x1
_0801397E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8013938

	thumb_func_start sub_8013984
sub_8013984:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r1, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 3
	ldr r1, _08013A20
	adds r6, r0, r1
	ldrh r1, [r4, 0x1C]
	movs r2, 0x1C
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _080139A2
	adds r0, r1, 0x1
	strh r0, [r4, 0x1C]
_080139A2:
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __divsi3
	adds r5, r0, 0
	strh r5, [r4, 0x20]
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	beq _080139C6
	adds r0, r5, 0x1
	strh r0, [r4, 0x20]
_080139C6:
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	subs r0, 0x1
	ldrh r5, [r4, 0x20]
	cmp r1, r0
	ble _080139DA
	subs r0, r5, 0x1
	strh r0, [r4, 0x1E]
_080139DA:
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	subs r0, 0x1
	cmp r1, r0
	bne _080139F8
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	movs r2, 0x1C
	ldrsh r1, [r4, r2]
	bl __modsi3
	cmp r0, 0
	bne _080139FA
_080139F8:
	ldrh r0, [r4, 0x1C]
_080139FA:
	strh r0, [r4, 0x1A]
	movs r0, 0x18
	ldrsh r1, [r4, r0]
	movs r2, 0x1A
	ldrsh r0, [r4, r2]
	subs r0, 0x1
	cmp r1, r0
	ble _08013A10
	ldrh r0, [r4, 0x1A]
	subs r0, 0x1
	strh r0, [r4, 0x18]
_08013A10:
	movs r1, 0
	strh r1, [r4, 0x4]
	ldr r0, [r6, 0xC]
	cmp r0, 0x6
	bne _08013A24
	movs r0, 0x10
	strh r0, [r4, 0x6]
	b _08013A26
	.align 2, 0
_08013A20: .4byte gUnknown_2027370
_08013A24:
	strh r1, [r4, 0x6]
_08013A26:
	lsls r0, r5, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _08013A32
	movs r0, 0
	b _08013A40
_08013A32:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	adds r0, r1
	subs r0, 0x2
	lsls r0, 3
_08013A40:
	strh r0, [r4, 0xC]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r4, 0xE]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8013984

	thumb_func_start sub_8013A54
sub_8013A54:
	push {lr}
	adds r2, r0, 0
	movs r0, 0x1E
	ldrsh r1, [r2, r0]
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	subs r0, 0x1
	cmp r1, r0
	bge _08013A6C
	ldrh r0, [r2, 0x1E]
	adds r0, 0x1
	b _08013A6E
_08013A6C:
	movs r0, 0
_08013A6E:
	strh r0, [r2, 0x1E]
	adds r0, r2, 0
	bl sub_8013984
	pop {r0}
	bx r0
	thumb_func_end sub_8013A54

	thumb_func_start sub_8013A7C
sub_8013A7C:
	push {lr}
	adds r1, r0, 0
	ldrh r2, [r1, 0x1E]
	movs r3, 0x1E
	ldrsh r0, [r1, r3]
	cmp r0, 0
	bgt _08013A90
	ldrh r0, [r1, 0x20]
	subs r0, 0x1
	b _08013A92
_08013A90:
	subs r0, r2, 0x1
_08013A92:
	strh r0, [r1, 0x1E]
	adds r0, r1, 0
	bl sub_8013984
	pop {r0}
	bx r0
	thumb_func_end sub_8013A7C

    .align 2,0
