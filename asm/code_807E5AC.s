	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text




	thumb_func_start sub_807FA9C
sub_807FA9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r2, _0807FAC4
	ldr r0, [r2]
	ldr r3, _0807FAC8
	adds r1, r0, r3
	ldrb r1, [r1]
	str r1, [sp]
	ldr r1, _0807FACC
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0, 0x5
	mov r8, r1
	b _0807FBFE
	.align 2, 0
_0807FAC4: .4byte gDungeon
_0807FAC8: .4byte 0x0001820f
_0807FACC: .4byte 0x000181ea
_0807FAD0:
	ldr r0, [r2]
	ldr r2, _0807FC18
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r5, r0, 0x6
	adds r0, 0x6
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x4]
	cmp r5, r0
	blt _0807FAEA
	b _0807FBEE
_0807FAEA:
	ldr r7, _0807FC1C
	ldr r2, _0807FC20
	mov r10, r2
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	mov r9, r0
_0807FAF8:
	movs r6, 0
	adds r0, r5, 0
	mov r1, r8
	bl GetTile
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FB24
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FB24
	ldr r0, [r4, 0x14]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807FB22
	ldr r3, [sp]
	cmp r3, 0
	beq _0807FB24
_0807FB22:
	movs r6, 0x1
_0807FB24:
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0807FB34
	movs r6, 0x1
_0807FB34:
	cmp r6, 0
	beq _0807FBD6
	ldr r0, _0807FC24
	ldr r1, [r0]
	ldr r3, _0807FC28
	adds r0, r1, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	mov r2, r9
	subs r3, r2, r0
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 3
	ldr r2, _0807FC2C
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	movs r0, 0x20
	negs r0, r0
	cmp r3, r0
	blt _0807FBD6
	cmp r2, r0
	blt _0807FBD6
	movs r0, 0x88
	lsls r0, 1
	cmp r3, r0
	bgt _0807FBD6
	cmp r2, 0xC0
	bgt _0807FBD6
	ldrh r1, [r7]
	mov r0, r10
	ands r0, r1
	strh r0, [r7]
	ldr r1, _0807FC30
	ands r1, r2
	lsls r1, 4
	ldrh r2, [r7, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, 0x6]
	ldr r0, _0807FC34
	ands r3, r0
	ldrh r0, [r7, 0x2]
	movs r2, 0xFE
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	orrs r0, r3
	strh r0, [r7, 0x2]
	ldrh r1, [r7, 0x4]
	mov r0, r10
	ands r0, r1
	movs r3, 0xC0
	lsls r3, 4
	orrs r0, r3
	movs r1, 0
	orrs r0, r1
	movs r1, 0xA0
	lsls r1, 8
	ldr r2, _0807FC30
	ands r0, r2
	orrs r0, r1
	movs r3, 0
	orrs r0, r3
	movs r2, 0xFE
	lsls r2, 1
	movs r3, 0xFC
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r7, 0x4]
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0807FBD6:
	movs r0, 0x18
	add r9, r0
	adds r5, 0x1
	ldr r0, _0807FC24
	ldr r0, [r0]
	ldr r1, _0807FC18
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, 0x6
	cmp r5, r0
	blt _0807FAF8
_0807FBEE:
	ldr r3, [sp, 0x4]
	mov r8, r3
	ldr r2, _0807FC24
	ldr r0, [r2]
	ldr r1, _0807FC38
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
_0807FBFE:
	adds r0, 0x5
	cmp r8, r0
	bge _0807FC06
	b _0807FAD0
_0807FC06:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FC18: .4byte 0x000181e8
_0807FC1C: .4byte gUnknown_202EDC0
_0807FC20: .4byte 0x0000f3ff
_0807FC24: .4byte gDungeon
_0807FC28: .4byte 0x000181f0
_0807FC2C: .4byte 0x000181f2
_0807FC30: .4byte 0x00000fff
_0807FC34: .4byte 0x000001ff
_0807FC38: .4byte 0x000181ea
	thumb_func_end sub_807FA9C

	.align 2, 0
