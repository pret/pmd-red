	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

@ SpriteOAM memes. Same as sub_8013F84 except instead of a 0x60 it's a 0x80
	thumb_func_start sub_8013E54
sub_8013E54:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _08013F60
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _08013F64
	ands r1, r0
	ldr r3, _08013F68
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
	ldr r0, _08013F6C
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
	ldr r5, _08013F70
	adds r0, r5, 0
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
	ldr r0, _08013F74
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
	ldr r0, _08013F78
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
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08013F7C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r2, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _08013F80
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x80
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r3, 0x6]
	ands r2, r1
	orrs r2, r0
	strh r2, [r3, 0x6]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013F60: .4byte gUnknown_2027370
_08013F64: .4byte 0x0000feff
_08013F68: .4byte 0xffff0000
_08013F6C: .4byte 0x0000fdff
_08013F70: .4byte 0x0000f3ff
_08013F74: .4byte 0x0000efff
_08013F78: .4byte 0x0000dfff
_08013F7C: .4byte 0x00003fff
_08013F80: .4byte 0x00000fff
	thumb_func_end sub_8013E54

@ SpriteOAM memes https://decomp.me/scratch/GROyH
	thumb_func_start sub_8013F84
sub_8013F84:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r6, _08014090
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _08014094
	ands r1, r0
	ldr r3, _08014098
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
	ldr r0, _0801409C
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
	ldr r5, _080140A0
	adds r0, r5, 0
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
	ldr r0, _080140A4
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
	ldr r0, _080140A8
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
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080140AC
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r2, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _080140B0
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x60
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r3, 0x6]
	ands r2, r1
	orrs r2, r0
	strh r2, [r3, 0x6]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08014090: .4byte gUnknown_2027370
_08014094: .4byte 0x0000feff
_08014098: .4byte 0xffff0000
_0801409C: .4byte 0x0000fdff
_080140A0: .4byte 0x0000f3ff
_080140A4: .4byte 0x0000efff
_080140A8: .4byte 0x0000dfff
_080140AC: .4byte 0x00003fff
_080140B0: .4byte 0x00000fff
	thumb_func_end sub_8013F84

    .align 2,0
