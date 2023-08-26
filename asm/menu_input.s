	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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

    .align 2,0
