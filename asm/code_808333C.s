	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_80833E8
sub_80833E8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl GetMapTile_1
	adds r1, r0, 0
	ldr r0, _08083438
	ldr r3, [r0]
	ldr r2, _0808343C
	adds r0, r3, r2
	ldrb r2, [r0]
	cmp r2, 0
	bne _0808340C
	movs r2, 0x2
_0808340C:
	ldrb r0, [r1, 0x9]
	cmp r0, 0xFF
	bne _08083440
	movs r1, 0
	ldrsh r0, [r5, r1]
	subs r0, r2
	str r0, [r4]
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r0, r2
	adds r0, 0x1
	str r0, [r4, 0x8]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	subs r0, r2
	str r0, [r4, 0x4]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	adds r0, r2
	adds r0, 0x1
	b _0808346A
	.align 2, 0
_08083438: .4byte gDungeonGlobalData
_0808343C: .4byte 0x00018209
_08083440:
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r2, _08083474
	adds r1, r2
	adds r1, r3, r1
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	str r0, [r4]
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	adds r0, 0x2
	str r0, [r4, 0x8]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	str r0, [r4, 0x4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r0, 0x2
_0808346A:
	str r0, [r4, 0xC]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083474: .4byte 0x000104c4
	thumb_func_end sub_80833E8

	thumb_func_start IsTargetTwoTilesAway
IsTargetTwoTilesAway:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r3, r0, 0
	adds r6, r1, 0
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r2, 0
	ldrsh r0, [r6, r2]
	subs r1, r0
	cmp r1, 0
	bge _08083490
	negs r1, r1
_08083490:
	cmp r1, 0x1
	bgt _080834A8
	movs r5, 0x2
	ldrsh r1, [r3, r5]
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	subs r1, r0
	cmp r1, 0
	bge _080834A4
	negs r1, r1
_080834A4:
	cmp r1, 0x1
	ble _0808355A
_080834A8:
	movs r5, 0
	ldrsh r4, [r3, r5]
	movs r1, 0
	ldrsh r0, [r6, r1]
	subs r2, r4, r0
	cmp r2, 0
	bge _080834B8
	negs r2, r2
_080834B8:
	movs r5, 0x2
	ldrsh r1, [r3, r5]
	movs r5, 0x2
	ldrsh r0, [r6, r5]
	subs r0, r1, r0
	cmp r0, 0
	bge _080834C8
	negs r0, r0
_080834C8:
	cmp r0, r2
	bge _080834CE
	adds r0, r2, 0
_080834CE:
	cmp r0, 0x2
	bne _0808355E
	adds r5, r4, 0
	adds r4, r1, 0
	movs r7, 0
_080834D8:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r5, r0
	bge _080834E2
	adds r5, 0x1
_080834E2:
	cmp r5, r0
	ble _080834E8
	subs r5, 0x1
_080834E8:
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	cmp r4, r0
	bge _080834F2
	adds r4, 0x1
_080834F2:
	cmp r4, r0
	ble _080834F8
	subs r4, 0x1
_080834F8:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r3, [sp]
	cmp r0, 0
	beq _0808355E
	adds r7, 0x1
	cmp r7, 0x1
	ble _080834D8
	movs r0, 0
	ldrsh r5, [r6, r0]
	movs r1, 0x2
	ldrsh r4, [r6, r1]
	movs r7, 0
_0808351E:
	movs r2, 0
	ldrsh r0, [r3, r2]
	cmp r5, r0
	bge _08083528
	adds r5, 0x1
_08083528:
	cmp r5, r0
	ble _0808352E
	subs r5, 0x1
_0808352E:
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r4, r0
	bge _08083538
	adds r4, 0x1
_08083538:
	cmp r4, r0
	ble _0808353E
	subs r4, 0x1
_0808353E:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r3, [sp]
	cmp r0, 0
	beq _0808355E
	adds r7, 0x1
	cmp r7, 0x1
	ble _0808351E
_0808355A:
	movs r0, 0x1
	b _08083560
_0808355E:
	movs r0, 0
_08083560:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end IsTargetTwoTilesAway

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