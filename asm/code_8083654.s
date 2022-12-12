	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
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

	.align 2, 0
