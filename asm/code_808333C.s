	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8083568
sub_8083568:
	push {r4,r5,lr}
	lsls r2, 24
	lsrs r5, r2, 24
	ldr r2, _080835E0
	ldr r2, [r2]
	ldr r4, _080835E4
	adds r3, r2, r4
	movs r4, 0
	ldrsh r3, [r3, r4]
	subs r3, r0, r3
	ldr r0, _080835E8
	adds r2, r0
	movs r4, 0
	ldrsh r0, [r2, r4]
	subs r4, r1, r0
	movs r0, 0x10
	negs r0, r0
	cmp r3, r0
	blt _080835F8
	cmp r4, r0
	blt _080835F8
	cmp r3, 0xFF
	bgt _080835F8
	cmp r4, 0xAF
	bgt _080835F8
	ldr r1, _080835EC
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	movs r1, 0x8
	ldrsh r2, [r0, r1]
	adds r2, r3, r2
	ldr r1, _080835F0
	ands r2, r1
	ldrh r3, [r0, 0x2]
	movs r1, 0xFE
	lsls r1, 8
	ands r1, r3
	orrs r1, r2
	strh r1, [r0, 0x2]
	movs r1, 0xA
	ldrsh r2, [r0, r1]
	adds r2, r4, r2
	ldr r1, _080835F4
	ands r2, r1
	lsls r2, 4
	ldrh r3, [r0, 0x6]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r2
	strh r1, [r0, 0x6]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
	movs r0, 0x1
	b _080835FA
	.align 2, 0
_080835E0: .4byte gDungeonGlobalData
_080835E4: .4byte 0x000181f0
_080835E8: .4byte 0x000181f2
_080835EC: .4byte gUnknown_202ED28
_080835F0: .4byte 0x000001ff
_080835F4: .4byte 0x00000fff
_080835F8:
	movs r0, 0
_080835FA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8083568

	.align 2, 0
