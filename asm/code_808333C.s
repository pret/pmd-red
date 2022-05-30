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

	thumb_func_start GetLeaderEntity
GetLeaderEntity:
	push {r4,r5,lr}
	ldr r0, _08083638
	ldr r0, [r0]
	cmp r0, 0
	bne _0808364A
	movs r5, 0
_0808360C:
	ldr r0, _0808363C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08083640
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0808362E
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _08083644
_0808362E:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0808360C
	movs r0, 0
	b _0808364A
	.align 2, 0
_08083638: .4byte gLeaderPokemon
_0808363C: .4byte gDungeonGlobalData
_08083640: .4byte 0x0001357c
_08083644:
	ldr r0, _08083650
	str r4, [r0]
	adds r0, r4, 0
_0808364A:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08083650: .4byte gLeaderPokemon
	thumb_func_end GetLeaderEntity

	thumb_func_start sub_8083654
sub_8083654:
	push {lr}
	bl GetLeaderEntity
	ldr r0, [r0, 0x70]
	pop {r1}
	bx r1
	thumb_func_end sub_8083654

	thumb_func_start sub_8083660
sub_8083660:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080836D4
	add sp, r4
	movs r1, 0xE0
	lsls r1, 5
	add r1, sp
	str r0, [r1]
	bl GetLeaderEntity
	ldr r2, _080836D8
	add r2, sp
	str r0, [r2]
	movs r7, 0
	movs r0, 0
	ldr r1, _080836DC
	add r1, sp
	str r0, [r1]
_0808368A:
	movs r0, 0x38
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x20
	bl DungeonRandomCapped
	ldr r2, _080836E0
	add r2, sp
	str r0, [r2]
	ldr r0, _080836D8
	add r0, sp
	ldr r0, [r0]
	ldr r3, [r0, 0x4]
	adds r5, r4, 0
	movs r1, 0
	ldr r4, [r2]
	ldr r0, _080836E4
	cmp r7, r0
	ble _080836B4
	b _080837E6
_080836B4:
	movs r2, 0x3
	mov r10, r2
	lsls r0, r7, 2
	mov r2, sp
	adds r6, r0, r2
_080836BE:
	movs r0, 0
	mov r8, r0
	adds r2, r5, 0x1
	ldr r0, _080836E8
	add r0, sp
	str r2, [r0]
	adds r1, 0x1
	ldr r2, _080836EC
	add r2, sp
	str r1, [r2]
	b _0808379C
	.align 2, 0
_080836D4: .4byte 0xffffe3e4
_080836D8: .4byte 0x00001c04
_080836DC: .4byte 0x00001c0c
_080836E0: .4byte 0x00001c08
_080836E4: .4byte 0x000006ff
_080836E8: .4byte 0x00001c14
_080836EC: .4byte 0x00001c10
_080836F0:
	ldr r0, _08083738
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _0808373C
	ldrh r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	bne _08083782
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _08083782
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _08083782
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08083782
	lsls r0, r3, 16
	asrs r0, 16
	subs r0, r5
	cmp r0, 0
	bge _08083722
	negs r0, r0
_08083722:
	cmp r0, 0x5
	bgt _08083788
	asrs r0, r3, 16
	subs r0, r4
	cmp r0, 0
	bge _08083730
	negs r0, r0
_08083730:
	cmp r0, 0x5
	ble _08083782
	b _08083788
	.align 2, 0
_08083738: .4byte 0x00001c0c
_0808373C:
	ldr r1, _08083764
	add r1, sp
	ldr r1, [r1]
	cmp r1, 0x1
	bne _08083768
	ldrh r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	bne _08083782
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _08083782
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _08083782
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08083782
	b _08083788
	.align 2, 0
_08083764: .4byte 0x00001c0c
_08083768:
	ldrh r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	bne _08083782
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _08083782
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08083782
	movs r2, 0x1
	mov r9, r2
_08083782:
	mov r0, r9
	cmp r0, 0
	beq _08083790
_08083788:
	strb r5, [r6]
	strb r4, [r6, 0x1]
	adds r6, 0x4
	adds r7, 0x1
_08083790:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08083798
	movs r4, 0
_08083798:
	movs r1, 0x1
	add r8, r1
_0808379C:
	mov r2, r8
	cmp r2, 0x1F
	bgt _080837C2
	movs r0, 0
	mov r9, r0
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, _0808380C
	add r2, sp
	str r3, [r2]
	bl GetMapTile_1
	adds r2, r0, 0
	ldr r0, _08083810
	ldr r1, _0808380C
	add r1, sp
	ldr r3, [r1]
	cmp r7, r0
	ble _080836F0
_080837C2:
	ldr r2, _08083814
	add r2, sp
	ldr r5, [r2]
	cmp r5, 0x37
	ble _080837CE
	movs r5, 0
_080837CE:
	ldr r0, _08083818
	add r0, sp
	ldr r1, [r0]
	cmp r1, 0x37
	bgt _080837E6
	ldr r2, _0808381C
	add r2, sp
	ldr r4, [r2]
	ldr r0, _08083810
	cmp r7, r0
	bgt _080837E6
	b _080836BE
_080837E6:
	cmp r7, 0
	beq _08083820
	adds r0, r7, 0
	bl DungeonRandomCapped
	lsls r0, 2
	mov r2, sp
	adds r1, r2, r0
	ldrb r0, [r1]
	movs r2, 0xE0
	lsls r2, 5
	add r2, sp
	ldr r2, [r2]
	strh r0, [r2]
	ldrb r0, [r1, 0x1]
	strh r0, [r2, 0x2]
	movs r0, 0x1
	b _08083832
	.align 2, 0
_0808380C: .4byte 0x00001c18
_08083810: .4byte 0x000006ff
_08083814: .4byte 0x00001c14
_08083818: .4byte 0x00001c10
_0808381C: .4byte 0x00001c08
_08083820:
	ldr r0, _08083844
	add r0, sp
	ldr r2, [r0]
	adds r2, 0x1
	str r2, [r0]
	cmp r2, 0x2
	bgt _08083830
	b _0808368A
_08083830:
	movs r0, 0
_08083832:
	ldr r3, _08083848
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08083844: .4byte 0x00001c0c
_08083848: .4byte 0x00001c1c
	thumb_func_end sub_8083660

	thumb_func_start sub_808384C
sub_808384C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r3, r0, 0
	mov r9, r1
	movs r0, 0
	mov r8, r0
	ldr r0, _080838BC
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x63
	beq _080838D8
	movs r6, 0
_0808386A:
	adds r2, r6, r0
	movs r4, 0
	ldrsh r1, [r2, r4]
	mov r5, r9
	movs r7, 0
	ldrsh r0, [r5, r7]
	adds r5, r1, r0
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	mov r2, r9
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp]
	bl GetMapTile_1
	adds r1, r0, 0
	ldrh r2, [r1]
	movs r7, 0x80
	lsls r7, 4
	adds r0, r7, 0
	ands r0, r2
	ldr r3, [sp]
	cmp r0, 0
	bne _080838C0
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0x1
	bne _080838C0
	ldr r0, [r1, 0x14]
	cmp r0, 0
	bne _080838C0
	ldr r0, [r1, 0x10]
	cmp r0, 0
	bne _080838C0
	strh r5, [r3]
	strh r4, [r3, 0x2]
	movs r0, 0x1
	b _080838DA
	.align 2, 0
_080838BC: .4byte gUnknown_80F4468
_080838C0:
	adds r6, 0x4
	movs r0, 0x1
	add r8, r0
	mov r2, r8
	cmp r2, 0x18
	bgt _080838D8
	ldr r0, _080838E8
	adds r1, r6, r0
	movs r4, 0
	ldrsh r1, [r1, r4]
	cmp r1, 0x63
	bne _0808386A
_080838D8:
	movs r0, 0
_080838DA:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080838E8: .4byte gUnknown_80F4468
	thumb_func_end sub_808384C

	thumb_func_start sub_80838EC
sub_80838EC:
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2]
	adds r1, r0, 0
	cmp r1, 0x7F
	beq _08083900
	cmp r1, 0
	beq _08083900
	subs r0, 0x1
	strb r0, [r2]
_08083900:
	pop {r0}
	bx r0
	thumb_func_end sub_80838EC

	thumb_func_start sub_8083904
sub_8083904:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp]
	mov r10, r1
	ldr r4, [r1, 0x70]
	str r4, [sp, 0x4]
	adds r5, r4, 0
	adds r5, 0x46
	ldrb r6, [r5]
	mov r0, r10
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08083954
	ldr r0, _08083950
	lsls r2, r6, 2
	adds r2, r0
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	mov r1, r10
	ldrh r1, [r1, 0x4]
	adds r0, r1
	ldr r3, [sp]
	strh r0, [r3]
	movs r4, 0x2
	ldrsh r1, [r2, r4]
	lsls r0, r1, 1
	adds r0, r1
	b _08083A6E
	.align 2, 0
_08083950: .4byte gAdjacentTileOffsets
_08083954:
	ldr r1, [r4, 0x58]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08083960
	b _08083A8C
_08083960:
	ldrb r0, [r5]
	ldr r1, _080839A0
	lsls r0, 3
	adds r0, r1
	ldr r7, [r0]
	movs r3, 0x4
	ldrsh r2, [r0, r3]
	str r2, [sp, 0x8]
	movs r2, 0x6
	ldrsh r1, [r0, r2]
	str r1, [sp, 0xC]
	mov r3, r10
	movs r0, 0x4
	ldrsh r3, [r3, r0]
	str r3, [sp, 0x10]
	mov r1, r10
	movs r2, 0x6
	ldrsh r1, [r1, r2]
	str r1, [sp, 0x14]
	ldr r0, _080839A4
	ldr r1, [r0]
	ldr r3, _080839A8
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080839B0
	ldr r4, _080839AC
	adds r4, r1, r4
	str r4, [sp, 0x18]
	movs r0, 0x14
	b _080839D0
	.align 2, 0
_080839A0: .4byte gUnknown_80F4CC4
_080839A4: .4byte gDungeonGlobalData
_080839A8: .4byte 0x000037fc
_080839AC: .4byte 0x000135cc
_080839B0:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _080839C8
	ldr r2, _080839C4
	adds r2, r1, r2
	str r2, [sp, 0x18]
	movs r3, 0x10
	str r3, [sp, 0x1C]
	b _080839D2
	.align 2, 0
_080839C4: .4byte 0x0001358c
_080839C8:
	ldr r4, _08083A78
	adds r4, r1, r4
	str r4, [sp, 0x18]
	movs r0, 0x4
_080839D0:
	str r0, [sp, 0x1C]
_080839D2:
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x63
	beq _08083A46
_080839DA:
	movs r2, 0
	ldrsh r0, [r7, r2]
	ldr r3, [sp, 0x8]
	muls r0, r3
	ldr r4, [sp, 0x10]
	adds r4, r0
	mov r9, r4
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	ldr r2, [sp, 0xC]
	muls r0, r2
	ldr r3, [sp, 0x14]
	adds r3, r0
	mov r8, r3
	movs r6, 0
	ldr r4, [sp, 0x1C]
	cmp r6, r4
	bge _08083A3C
	ldr r5, [sp, 0x18]
_08083A00:
	ldr r4, [r5]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08083A32
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, r9
	bne _08083A32
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	bne _08083A32
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08083A80
_08083A32:
	adds r5, 0x4
	adds r6, 0x1
	ldr r3, [sp, 0x1C]
	cmp r6, r3
	blt _08083A00
_08083A3C:
	adds r7, 0x4
	movs r4, 0
	ldrsh r0, [r7, r4]
	cmp r0, 0x63
	bne _080839DA
_08083A46:
	ldr r2, _08083A7C
	ldr r1, [sp, 0x4]
	adds r1, 0x46
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 1
	mov r4, r10
	ldrh r4, [r4, 0x4]
	adds r0, r4
	ldr r3, [sp]
	strh r0, [r3]
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	lsls r0, 1
_08083A6E:
	mov r1, r10
	ldrh r1, [r1, 0x6]
	adds r0, r1
	strh r0, [r3, 0x2]
	b _08083A9E
	.align 2, 0
_08083A78: .4byte 0x0001357c
_08083A7C: .4byte gAdjacentTileOffsets
_08083A80:
	mov r3, r9
	ldr r2, [sp]
	strh r3, [r2]
	mov r4, r8
	strh r4, [r2, 0x2]
	b _08083A9E
_08083A8C:
	ldr r0, [sp, 0x4]
	adds r0, 0x58
	ldrh r0, [r0]
	ldr r1, [sp]
	strh r0, [r1]
	ldr r0, [sp, 0x4]
	adds r0, 0x5A
	ldrh r0, [r0]
	strh r0, [r1, 0x2]
_08083A9E:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8083904

	thumb_func_start sub_8083AB0
sub_8083AB0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r5, r1, 0
	adds r7, r2, 0
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	ldr r0, _08083AFC
	ldr r0, [r0]
	ldr r1, _08083B00
	adds r4, r0, r1
	movs r6, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08083AE4
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _08083AE4
	ldr r6, [r5, 0x70]
_08083AE4:
	ldr r5, [r7, 0x70]
	cmp r6, 0
	beq _08083B04
	mov r0, sp
	adds r1, r6, 0
	bl sub_80709C8
	adds r0, r4, 0
	mov r1, sp
	bl CopyStringtoBuffer
	b _08083B0E
	.align 2, 0
_08083AFC: .4byte gDungeonGlobalData
_08083B00: .4byte 0x0001ce98
_08083B04:
	ldr r0, _08083C04
	ldr r1, [r0]
	adds r0, r4, 0
	bl CopyStringtoBuffer
_08083B0E:
	mov r0, sp
	adds r1, r5, 0
	bl sub_80709C8
	adds r0, r4, 0
	adds r0, 0xA
	mov r1, sp
	bl CopyStringtoBuffer
	movs r2, 0
	mov r3, r8
	strh r3, [r4, 0x14]
	ldr r0, [r5, 0x60]
	str r0, [r4, 0x1C]
	ldr r0, [r5, 0x18]
	str r0, [r4, 0x20]
	ldrb r0, [r5, 0x9]
	adds r1, r4, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrh r0, [r5, 0x10]
	strh r0, [r4, 0x24]
	ldrb r0, [r5, 0x14]
	subs r1, 0x4
	strb r0, [r1]
	ldrb r0, [r5, 0x15]
	adds r1, 0x1
	strb r0, [r1]
	ldrb r1, [r5, 0x16]
	adds r0, r4, 0
	adds r0, 0x28
	strb r1, [r0]
	ldrb r0, [r5, 0x17]
	adds r1, r4, 0
	adds r1, 0x29
	strb r0, [r1]
	ldr r0, _08083C08
	ldr r0, [r0]
	ldr r1, _08083C0C
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x18]
	adds r3, r4, 0
	adds r3, 0x2B
	strb r2, [r3]
	adds r6, r4, 0
	adds r6, 0x2C
	strb r2, [r6]
	movs r0, 0x2D
	adds r0, r4
	mov r12, r0
	strb r2, [r0]
	adds r4, 0x2E
	strb r2, [r4]
	adds r0, r5, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08083BF8
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08083BF8
	adds r1, r5, 0
	adds r1, 0x62
	ldrb r0, [r1]
	cmp r0, 0x13
	bne _08083BA4
	ldr r0, _08083C10
	ldrb r0, [r0]
	ldrb r2, [r3]
	adds r0, r2
	strb r0, [r3]
_08083BA4:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08083BB4
	ldr r0, _08083C14
	ldrb r0, [r0]
	ldrb r2, [r3]
	adds r0, r2
	strb r0, [r3]
_08083BB4:
	ldrb r0, [r1]
	cmp r0, 0x21
	bne _08083BC4
	ldr r0, _08083C18
	ldrb r0, [r0]
	ldrb r3, [r6]
	adds r0, r3
	strb r0, [r6]
_08083BC4:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08083BD4
	ldr r0, _08083C14
	ldrb r0, [r0]
	ldrb r2, [r6]
	adds r0, r2
	strb r0, [r6]
_08083BD4:
	ldrb r0, [r1]
	cmp r0, 0x1E
	bne _08083BE8
	ldr r0, _08083C1C
	ldrb r0, [r0]
	mov r3, r12
	ldrb r3, [r3]
	adds r0, r3
	mov r2, r12
	strb r0, [r2]
_08083BE8:
	ldrb r0, [r1]
	cmp r0, 0x22
	bne _08083BF8
	ldr r0, _08083C20
	ldrb r0, [r0]
	ldrb r3, [r4]
	adds r0, r3
	strb r0, [r4]
_08083BF8:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08083C04: .4byte gUnknown_80FE6F4
_08083C08: .4byte gDungeonGlobalData
_08083C0C: .4byte 0x00000644
_08083C10: .4byte gUnknown_810AC60
_08083C14: .4byte gUnknown_810AC68
_08083C18: .4byte gUnknown_810AC62
_08083C1C: .4byte gUnknown_810AC64
_08083C20: .4byte gUnknown_810AC66
	thumb_func_end sub_8083AB0

	thumb_func_start sub_8083C24
sub_8083C24:
	push {lr}
	ldr r0, _08083C3C
	ldr r0, [r0]
	ldr r1, _08083C40
	adds r0, r1
	movs r2, 0x14
	ldrsh r1, [r0, r2]
	ldr r0, _08083C44
	cmp r1, r0
	ble _08083C48
	movs r0, 0
	b _08083C4A
	.align 2, 0
_08083C3C: .4byte gDungeonGlobalData
_08083C40: .4byte 0x0001ce98
_08083C44: .4byte 0x00000225
_08083C48:
	movs r0, 0x1
_08083C4A:
	pop {r1}
	bx r1
	thumb_func_end sub_8083C24

	thumb_func_start sub_8083C50
sub_8083C50:
	push {lr}
	ldr r0, _08083C74
	ldr r0, [r0]
	ldr r1, _08083C78
	adds r0, r1
	movs r2, 0x14
	ldrsh r1, [r0, r2]
	ldr r0, _08083C7C
	cmp r1, r0
	beq _08083C70
	adds r0, 0x3
	cmp r1, r0
	beq _08083C70
	subs r0, 0x2
	cmp r1, r0
	bne _08083C80
_08083C70:
	movs r0, 0x1
	b _08083C82
	.align 2, 0
_08083C74: .4byte gDungeonGlobalData
_08083C78: .4byte 0x0001ce98
_08083C7C: .4byte 0x00000227
_08083C80:
	movs r0, 0
_08083C82:
	pop {r1}
	bx r1
	thumb_func_end sub_8083C50

	thumb_func_start sub_8083C88
sub_8083C88:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, _08083CC4
	ldr r0, [r4]
	ldr r1, _08083CC8
	adds r5, r0, r1
	ldr r1, _08083CCC
	adds r0, r1
	ldrb r0, [r0]
	bl GetUnk9
	lsls r0, 24
	cmp r0, 0
	bne _08083CB6
	ldr r0, [r4]
	ldr r1, _08083CD0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08083CC0
	cmp r6, 0
	bne _08083CC0
_08083CB6:
	movs r0, 0x14
	ldrsh r1, [r5, r0]
	ldr r0, _08083CD4
	cmp r1, r0
	beq _08083CD8
_08083CC0:
	movs r0, 0x1
	b _08083CDA
	.align 2, 0
_08083CC4: .4byte gDungeonGlobalData
_08083CC8: .4byte 0x0001ce98
_08083CCC: .4byte 0x00000644
_08083CD0: .4byte 0x0000065c
_08083CD4: .4byte 0x00000227
_08083CD8:
	movs r0, 0
_08083CDA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8083C88

	thumb_func_start sub_8083CE0
sub_8083CE0:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _08083CF2
	ldr r0, _08083D00
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	ble _08083CFC
_08083CF2:
	ldr r0, _08083D04
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
_08083CFC:
	pop {r0}
	bx r0
	.align 2, 0
_08083D00: .4byte gUnknown_202EE10
_08083D04: .4byte 0x0000012d
	thumb_func_end sub_8083CE0

	thumb_func_start sub_8083D08
sub_8083D08:
	push {lr}
	movs r0, 0x97
	lsls r0, 1
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D08

	thumb_func_start sub_8083D1C
sub_8083D1C:
	push {lr}
	ldr r0, _08083D2C
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	.align 2, 0
_08083D2C: .4byte 0x00000133
	thumb_func_end sub_8083D1C

	thumb_func_start sub_8083D30
sub_8083D30:
	push {lr}
	ldr r0, _08083D40
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	.align 2, 0
_08083D40: .4byte 0x0000012f
	thumb_func_end sub_8083D30

	thumb_func_start sub_8083D44
sub_8083D44:
	push {lr}
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D44

	thumb_func_start sub_8083D58
sub_8083D58:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xC8
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D58

	thumb_func_start sub_8083D68
sub_8083D68:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCF
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D68

	thumb_func_start sub_8083D78
sub_8083D78:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xD3
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D78

	thumb_func_start sub_8083D88
sub_8083D88:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCC
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D88

	thumb_func_start sub_8083D98
sub_8083D98:
	push {lr}
	movs r0, 0x33
	bl sub_8083E88
	ldr r2, _08083DCC
	ldr r0, [r2]
	ldr r1, _08083DD0
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _08083DD4
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x27
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08083DD8
	adds r0, r1
	ldr r1, _08083DDC
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08083DCC: .4byte gDungeonGlobalData
_08083DD0: .4byte 0x0000066f
_08083DD4: .4byte 0x00000672
_08083DD8: .4byte 0x0000066a
_08083DDC: .4byte 0x000003e7
	thumb_func_end sub_8083D98

	thumb_func_start sub_8083DE0
sub_8083DE0:
	push {lr}
	movs r0, 0x34
	bl sub_8083E88
	ldr r2, _08083E14
	ldr r0, [r2]
	ldr r1, _08083E18
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _08083E1C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x27
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08083E20
	adds r0, r1
	ldr r1, _08083E24
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08083E14: .4byte gDungeonGlobalData
_08083E18: .4byte 0x0000066f
_08083E1C: .4byte 0x00000672
_08083E20: .4byte 0x0000066a
_08083E24: .4byte 0x000003e7
	thumb_func_end sub_8083DE0

	thumb_func_start sub_8083E28
sub_8083E28:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCF
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083E28

	thumb_func_start PlaySoundEffect
PlaySoundEffect:
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, _08083E54
	cmp r2, r0
	beq _08083E4E
	movs r1, 0x80
	lsls r1, 1
	adds r0, r2, 0
	bl sub_800C074
_08083E4E:
	pop {r0}
	bx r0
	.align 2, 0
_08083E54: .4byte 0x000003e5
	thumb_func_end PlaySoundEffect

	thumb_func_start sub_8083E58
sub_8083E58:
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _08083E70
	cmp r1, r0
	beq _08083E6A
	adds r0, r1, 0
	bl sub_800C298
_08083E6A:
	pop {r0}
	bx r0
	.align 2, 0
_08083E70: .4byte 0x000003e5
	thumb_func_end sub_8083E58

	thumb_func_start sub_8083E74
sub_8083E74:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C5D0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8083E74

	thumb_func_start sub_8083E88
sub_8083E88:
	ldr r1, _08083E9C
	ldr r1, [r1]
	ldr r3, _08083EA0
	adds r2, r1, r3
	movs r3, 0
	strh r0, [r2]
	ldr r0, _08083EA4
	adds r1, r0
	strh r3, [r1]
	bx lr
	.align 2, 0
_08083E9C: .4byte gDungeonGlobalData
_08083EA0: .4byte 0x0001ceda
_08083EA4: .4byte 0x0001ced4
	thumb_func_end sub_8083E88

	thumb_func_start sub_8083EA8
sub_8083EA8:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _08083ECC
	ldr r2, [r2]
	movs r4, 0x80
	lsls r4, 8
	adds r3, r4, 0
	ldr r5, _08083ED0
	adds r4, r2, r5
	orrs r0, r3
	strh r0, [r4]
	ldr r0, _08083ED4
	adds r2, r0
	strh r1, [r2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083ECC: .4byte gDungeonGlobalData
_08083ED0: .4byte 0x0001ceda
_08083ED4: .4byte 0x0001ced4
	thumb_func_end sub_8083EA8

	thumb_func_start sub_8083ED8
sub_8083ED8:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_80118C4
	ldr r0, _08083F00
	ldr r1, [r0]
	ldr r2, _08083F04
	adds r0, r1, r2
	ldr r2, _08083F08
	strh r2, [r0]
	ldr r3, _08083F0C
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _08083F10
	adds r1, r0
	strh r2, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08083F00: .4byte gDungeonGlobalData
_08083F04: .4byte 0x0001ced6
_08083F08: .4byte 0x000003e7
_08083F0C: .4byte 0x0001ced8
_08083F10: .4byte 0x0001ceda
	thumb_func_end sub_8083ED8

	thumb_func_start sub_8083F14
sub_8083F14:
	push {lr}
	bl sub_8083F34
	bl sub_8011924
	pop {r0}
	bx r0
	thumb_func_end sub_8083F14

	thumb_func_start xxx_call_GetCurrentBGSong
xxx_call_GetCurrentBGSong:
	push {lr}
	bl GetCurrentBGSong
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end xxx_call_GetCurrentBGSong

	thumb_func_start sub_8083F34
sub_8083F34:
	ldr r0, _08083F4C
	ldr r0, [r0]
	ldr r1, _08083F50
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	str r1, [r0, 0x4]
	ldr r1, _08083F54
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	bx lr
	.align 2, 0
_08083F4C: .4byte gDungeonGlobalData
_08083F50: .4byte 0x0001cecc
_08083F54: .4byte 0x000003e7
	thumb_func_end sub_8083F34

	thumb_func_start sub_8083F58
sub_8083F58:
	push {r4,lr}
	ldr r0, _08083F7C
	ldr r2, [r0]
	ldr r0, _08083F80
	adds r4, r2, r0
	ldr r1, _08083F84
	adds r3, r2, r1
	ldrh r1, [r3]
	ldr r0, _08083F88
	cmp r1, r0
	bne _08083FB2
	ldr r1, _08083F8C
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08083F90
	movs r1, 0x12
	b _08083FB2
	.align 2, 0
_08083F7C: .4byte gDungeonGlobalData
_08083F80: .4byte 0x0001cecc
_08083F84: .4byte 0x0000066a
_08083F88: .4byte 0x000003e7
_08083F8C: .4byte 0x0000066f
_08083F90:
	ldr r1, _08083FA0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08083FA4
	movs r1, 0x80
	b _08083FB2
	.align 2, 0
_08083FA0: .4byte 0x00000672
_08083FA4:
	ldr r1, _08083FC4
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r1, 0x11
	cmp r0, 0
	bne _08083FB2
	ldrh r1, [r4, 0xE]
_08083FB2:
	ldr r0, [r4]
	cmp r0, 0x4
	bne _08083FC8
	ldrh r0, [r4, 0xC]
	cmp r1, r0
	beq _08083FDA
	movs r0, 0x2
	b _08083FD6
	.align 2, 0
_08083FC4: .4byte 0x00000699
_08083FC8:
	ldr r2, _08083FEC
	cmp r1, r2
	beq _08083FDA
	ldrh r0, [r4, 0xA]
	cmp r0, r2
	bne _08083FDA
	movs r0, 0x1
_08083FD6:
	str r0, [r4]
	strh r1, [r4, 0xA]
_08083FDA:
	ldr r0, [r4]
	cmp r0, 0x4
	bhi _08084084
	lsls r0, 2
	ldr r1, _08083FF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083FEC: .4byte 0x000003e7
_08083FF0: .4byte _08083FF4
	.align 2, 0
_08083FF4:
	.4byte _08084084
	.4byte _08084008
	.4byte _08084050
	.4byte _0808405E
	.4byte _08084084
_08084008:
	ldrh r1, [r4, 0xA]
	ldr r0, _08084014
	cmp r1, r0
	bne _08084018
	movs r0, 0
	b _08084040
	.align 2, 0
_08084014: .4byte 0x000003e7
_08084018:
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08084030
	ldr r0, _0808402C
	ands r0, r1
	bl StartNewBGM
	b _0808403A
	.align 2, 0
_0808402C: .4byte 0x00007fff
_08084030:
	ldr r0, _08084048
	ands r0, r1
	ldrh r1, [r4, 0x8]
	bl FadeInNewBGM
_0808403A:
	ldrh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	movs r0, 0x4
_08084040:
	str r0, [r4]
	ldr r0, _0808404C
	strh r0, [r4, 0xA]
	b _08084084
	.align 2, 0
_08084048: .4byte 0x00007fff
_0808404C: .4byte 0x000003e7
_08084050:
	movs r0, 0x1E
	bl FadeOutBGM
	movs r0, 0x1E
	str r0, [r4, 0x4]
	movs r0, 0x3
	b _08084082
_0808405E:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0808406C
	subs r0, 0x1
	str r0, [r4, 0x4]
	cmp r0, 0
	bne _08084084
_0808406C:
	ldrh r1, [r4, 0xA]
	ldr r0, _0808407C
	cmp r1, r0
	bne _08084080
	bl sub_800BF80
	movs r0, 0
	b _08084082
	.align 2, 0
_0808407C: .4byte 0x000003e7
_08084080:
	movs r0, 0x1
_08084082:
	str r0, [r4]
_08084084:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8083F58

	thumb_func_start sub_808408C
sub_808408C:
	ldr r2, _0808409C
	movs r1, 0x1
	orrs r1, r0
	ldr r0, _080840A0
	ands r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0808409C: .4byte gUnknown_203B458
_080840A0: .4byte 0x00ffffff
	thumb_func_end sub_808408C

	thumb_func_start sub_80840A4
sub_80840A4:
	ldr r3, _080840C8
	ldr r0, [r3]
	ldr r2, _080840CC
	adds r1, r0, 0
	muls r1, r2
	adds r1, 0x1
	lsrs r0, r1, 16
	muls r1, r2
	adds r1, 0x1
	str r1, [r3]
	ldr r2, _080840D0
	ands r1, r2
	orrs r0, r1
	ldr r1, _080840D4
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	bx lr
	.align 2, 0
_080840C8: .4byte gUnknown_203B458
_080840CC: .4byte 0x5d588b65
_080840D0: .4byte 0xffff0000
_080840D4: .4byte 0x00ffffff
	thumb_func_end sub_80840A4

	.align 2, 0
