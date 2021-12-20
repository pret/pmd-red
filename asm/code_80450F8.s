	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_804513C
sub_804513C:
	push {r4-r7,lr}
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _08045200
	ldr r4, _08045204
	movs r5, 0
_08045148:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0x3
	ble _08045148
	ldr r1, _08045208
	movs r2, 0
	adds r0, r1, 0x5
_08045164:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08045164
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _0804520C
	ldr r4, _08045210
	movs r5, 0
_08045176:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0xF
	ble _08045176
	ldr r1, _08045214
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0xF
_08045194:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08045194
	movs r3, 0
	ldr r5, _080451FC
	ldr r4, _08045218
	movs r2, 0
_080451A4:
	ldr r0, [r5]
	lsls r1, r3, 2
	adds r0, r4
	adds r0, r1
	str r2, [r0]
	adds r3, 0x1
	cmp r3, 0x13
	ble _080451A4
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _0804521C
	ldr r4, _08045220
	movs r5, 0
_080451BE:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0x3F
	ble _080451BE
	movs r3, 0
	ldr r7, _080451FC
	ldr r6, _08045224
	ldr r4, _08045228
	movs r5, 0
_080451DE:
	ldr r0, [r7]
	lsls r2, r3, 2
	adds r1, r0, r6
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	str r5, [r0]
	adds r4, 0x74
	adds r3, 0x1
	cmp r3, 0x3F
	ble _080451DE
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080451FC: .4byte gDungeonGlobalData
_08045200: .4byte 0x0001357c
_08045204: .4byte 0x0001381c
_08045208: .4byte gUnknown_202EE70
_0804520C: .4byte 0x0001358c
_08045210: .4byte 0x000139ec
_08045214: .4byte gUnknown_202EE76
_08045218: .4byte 0x000135cc
_0804521C: .4byte 0x0001361c
_08045220: .4byte 0x0001412c
_08045224: .4byte 0x0001371c
_08045228: .4byte 0x00015e2c
	thumb_func_end sub_804513C

	thumb_func_start sub_804522C
sub_804522C:
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r2, _08045274
	ldr r0, [r2]
	ldr r3, _08045278
	adds r1, r0, r3
	ldrb r7, [r1]
	ldr r1, _0804527C
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080452AA
	movs r6, 0
	adds r7, r2, 0
_08045248:
	ldr r0, [r7]
	lsls r1, r6, 2
	ldr r2, _08045280
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080452A2
	ldr r0, [r7]
	ldr r3, _08045284
	adds r0, r3
	ldr r0, [r0]
	cmp r5, r0
	bne _08045288
	adds r0, r5, 0
	bl sub_806C51C
	b _080452A2
	.align 2, 0
_08045274: .4byte gDungeonGlobalData
_08045278: .4byte 0x00018210
_0804527C: .4byte 0x0001820a
_08045280: .4byte 0x000135cc
_08045284: .4byte 0x000181f8
_08045288:
	ldr r4, [r5, 0x70]
	adds r0, r5, 0
	bl EntityGetStatusSprites
	adds r2, r0, 0
	adds r0, r4, 0
	adds r0, 0x98
	ldr r0, [r0]
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	movs r3, 0
	bl UpdateDungeonPokemonSprite
_080452A2:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08045248
	b _0804533E
_080452AA:
	movs r6, 0
_080452AC:
	ldr r0, _08045348
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0804534C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080452CC
	adds r0, r4, 0
	bl sub_806C51C
_080452CC:
	adds r6, 0x1
	cmp r6, 0x3
	ble _080452AC
	movs r6, 0
_080452D4:
	ldr r5, _08045348
	ldr r0, [r5]
	lsls r1, r6, 2
	ldr r3, _08045350
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080452F4
	adds r0, r4, 0
	bl sub_806C51C
_080452F4:
	adds r6, 0x1
	cmp r6, 0xF
	ble _080452D4
	movs r6, 0
	ldr r0, [r5]
	ldr r1, _08045354
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _08045336
	adds r4, r5, 0
_0804530C:
	ldr r0, [r4]
	lsls r1, r6, 2
	ldr r3, _08045358
	adds r0, r3
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	str r1, [sp]
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0xFF
	bl sub_80462AC
	adds r6, 0x1
	ldr r0, [r4]
	ldr r1, _08045354
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _0804530C
_08045336:
	cmp r7, 0
	beq _0804533E
	bl sub_807FA9C
_0804533E:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045348: .4byte gDungeonGlobalData
_0804534C: .4byte 0x0001357c
_08045350: .4byte 0x0001358c
_08045354: .4byte 0x00003904
_08045358: .4byte 0x0001361c
	thumb_func_end sub_804522C

	thumb_func_start sub_804535C
sub_804535C:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	beq _0804536C
	ldr r0, [r1]
	str r0, [r2, 0xC]
	ldr r0, [r1, 0x4]
	b _0804538E
_0804536C:
	movs r0, 0x4
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [r2, 0xC]
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1
_0804538E:
	str r0, [r2, 0x10]
	pop {r0}
	bx r0
	thumb_func_end sub_804535C

	thumb_func_start sub_8045394
sub_8045394:
	str r1, [r0, 0xC]
	str r2, [r0, 0x10]
	bx lr
	thumb_func_end sub_8045394

	thumb_func_start sub_804539C
sub_804539C:
	ldr r3, [r0, 0xC]
	adds r3, r1
	str r3, [r0, 0xC]
	ldr r1, [r0, 0x10]
	adds r1, r2
	str r1, [r0, 0x10]
	bx lr
	thumb_func_end sub_804539C

	thumb_func_start sub_80453AC
sub_80453AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	mov r0, r8
	bl GetPokemonSize
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r0, 0x6
	subs r3, r0, r6
	ldr r4, _080453D8
	b _080453DE
	.align 2, 0
_080453D8: .4byte gUnknown_202EE70
_080453DC:
	adds r5, 0x1
_080453DE:
	cmp r5, r3
	bgt _08045400
	movs r2, 0
	cmp r2, r6
	bge _080453FA
	adds r1, r5, r4
	b _080453F4
_080453EC:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r6
	bge _080453FA
_080453F4:
	ldrb r0, [r1]
	cmp r0, 0
	beq _080453EC
_080453FA:
	cmp r2, r6
	bne _080453DC
	mov r9, r5
_08045400:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _080454FC
	movs r5, 0
	ldr r7, _080454DC
_0804540C:
	ldr r1, _080454E0
	ldr r0, [r1]
	lsls r1, r5, 2
	ldr r2, _080454E4
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	cmp r0, 0
	bne _080454F0
	movs r0, 0x1
	str r0, [r4]
	adds r0, r4, 0
	adds r0, 0x24
	strb r5, [r0]
	ldr r1, _080454E0
	ldr r0, [r1]
	adds r0, r7
	str r0, [r4, 0x70]
	mov r2, r8
	strh r2, [r0, 0x2]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	ldr r1, [r4, 0x70]
	strh r0, [r1, 0x4]
	ldr r0, [r4, 0x70]
	movs r5, 0
	strb r5, [r0, 0x6]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	lsls r0, 16
	asrs r0, 16
	bl sub_80687D0
	str r0, [r4, 0x64]
	mov r1, r9
	lsls r0, r1, 4
	adds r0, 0x40
	adds r1, r4, 0
	adds r1, 0x68
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6C
	movs r2, 0
	strb r2, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6D
	movs r5, 0x1
	strb r5, [r0]
	adds r0, 0x2
	strb r5, [r0]
	mov r0, r10
	str r0, [r4, 0x1C]
	bl sub_8045ACC
	ldr r0, [r4, 0x70]
	ldr r1, _080454E8
	adds r0, r1
	mov r2, r9
	strb r2, [r0]
	ldr r0, [r4, 0x70]
	movs r5, 0xB4
	lsls r5, 1
	adds r0, r5
	strb r6, [r0]
	cmp r6, 0
	beq _080454C6
	ldr r3, _080454EC
	movs r2, 0x1
	adds r1, r6, 0
_080454B6:
	mov r5, r9
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, 0x1
	add r9, r0
	subs r1, 0x1
	cmp r1, 0
	bne _080454B6
_080454C6:
	ldr r1, _080454E0
	ldr r0, [r1]
	movs r2, 0xCD
	lsls r2, 3
	adds r0, r2
	ldrh r2, [r0]
	adds r1, r2, 0x1
	strh r1, [r0]
	strh r2, [r4, 0x26]
	adds r0, r4, 0
	b _080454FE
	.align 2, 0
_080454DC: .4byte 0x0000069c
_080454E0: .4byte gDungeonGlobalData
_080454E4: .4byte 0x0001357c
_080454E8: .4byte 0x00000167
_080454EC: .4byte gUnknown_202EE70
_080454F0:
	movs r0, 0x82
	lsls r0, 2
	adds r7, r0
	adds r5, 0x1
	cmp r5, 0x3
	ble _0804540C
_080454FC:
	movs r0, 0
_080454FE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80453AC

	thumb_func_start sub_804550C
sub_804550C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	mov r0, r8
	bl GetPokemonSize
	lsls r0, 24
	lsrs r7, r0, 24
	movs r5, 0
	movs r0, 0x10
	subs r3, r0, r7
	ldr r4, _08045538
	b _0804553E
	.align 2, 0
_08045538: .4byte gUnknown_202EE76
_0804553C:
	adds r5, 0x1
_0804553E:
	cmp r5, r3
	bgt _08045560
	movs r2, 0
	cmp r2, r7
	bge _0804555A
	adds r1, r5, r4
	b _08045554
_0804554C:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r7
	bge _0804555A
_08045554:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0804554C
_0804555A:
	cmp r2, r7
	bne _0804553C
	mov r9, r5
_08045560:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	bne _0804556A
	b _08045670
_0804556A:
	movs r5, 0
	movs r1, 0x1
	mov r10, r1
	ldr r2, _08045650
	mov r3, r9
	lsls r0, r3, 4
	adds r0, 0xA0
	str r0, [sp]
_0804557A:
	ldr r1, _08045654
	ldr r0, [r1]
	lsls r1, r5, 2
	ldr r3, _08045658
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	str r2, [sp, 0x4]
	bl EntityExists
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, [sp, 0x4]
	cmp r6, 0
	bne _08045664
	mov r0, r10
	str r0, [r4]
	adds r0, r4, 0
	adds r0, 0x24
	strb r5, [r0]
	subs r0, 0x2
	strb r6, [r0]
	ldr r1, _08045654
	ldr r0, [r1]
	adds r0, r2
	str r0, [r4, 0x70]
	mov r2, r8
	strh r2, [r0, 0x2]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	ldr r1, [r4, 0x70]
	strh r0, [r1, 0x4]
	ldr r0, [r4, 0x70]
	mov r3, r10
	strb r3, [r0, 0x6]
	movs r0, 0
	mov r1, r8
	bl sub_8069F54
	lsls r0, 16
	asrs r0, 16
	bl sub_80687D0
	str r0, [r4, 0x64]
	adds r0, r4, 0
	adds r0, 0x68
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r0]
	adds r1, r4, 0
	adds r1, 0x6A
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6C
	movs r1, 0
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x6B
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x6D
	mov r2, r10
	strb r2, [r0]
	adds r0, 0x2
	strb r2, [r0]
	str r6, [r4, 0x1C]
	ldr r0, [r4, 0x70]
	ldr r3, _0804565C
	adds r0, r3
	mov r5, r9
	strb r5, [r0]
	ldr r0, [r4, 0x70]
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r1
	strb r7, [r0]
	cmp r7, 0
	beq _08045636
	ldr r3, _08045660
	movs r2, 0x1
	adds r1, r7, 0
_08045626:
	mov r5, r9
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, 0x1
	add r9, r0
	subs r1, 0x1
	cmp r1, 0
	bne _08045626
_08045636:
	bl sub_8045ACC
	ldr r1, _08045654
	ldr r0, [r1]
	movs r2, 0xCD
	lsls r2, 3
	adds r0, r2
	ldrh r2, [r0]
	adds r1, r2, 0x1
	strh r1, [r0]
	strh r2, [r4, 0x26]
	adds r0, r4, 0
	b _08045672
	.align 2, 0
_08045650: .4byte 0x00000ebc
_08045654: .4byte gDungeonGlobalData
_08045658: .4byte 0x0001358c
_0804565C: .4byte 0x00000167
_08045660: .4byte gUnknown_202EE76
_08045664:
	movs r3, 0x82
	lsls r3, 2
	adds r2, r3
	adds r5, 0x1
	cmp r5, 0xF
	ble _0804557A
_08045670:
	movs r0, 0
_08045672:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_804550C

	thumb_func_start sub_8045684
sub_8045684:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	movs r5, 0
	ldr r7, _080456E4
	ldr r6, _080456E8
_080456A2:
	ldr r0, [r7]
	lsls r1, r5, 2
	ldr r2, _080456EC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080456F0
	movs r0, 0x2
	str r0, [r4]
	ldr r0, [r7]
	adds r0, r6
	str r0, [r4, 0x70]
	mov r2, r8
	strb r2, [r0]
	ldr r0, [r4, 0x70]
	mov r2, r9
	strb r2, [r0, 0x1]
	str r1, [r4, 0x1C]
	adds r0, r4, 0
	adds r0, 0x22
	strb r1, [r0]
	mov r2, r10
	ldr r0, [r2]
	str r0, [r4, 0x4]
	strh r1, [r4, 0x26]
	adds r0, r4, 0
	b _080456FA
	.align 2, 0
_080456E4: .4byte gDungeonGlobalData
_080456E8: .4byte 0x00003908
_080456EC: .4byte 0x0001371c
_080456F0:
	adds r6, 0x4
	adds r5, 0x1
	cmp r5, 0x3F
	ble _080456A2
	movs r0, 0
_080456FA:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8045684

	thumb_func_start sub_8045708
sub_8045708:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	ldr r1, _08045744
	ldr r0, _08045748
	ldr r0, [r0]
	ldr r2, _0804574C
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0804579C
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl GetMapEntity
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0804579C
	b _080457C4
	.align 2, 0
_08045744: .4byte gDungeonWaterType
_08045748: .4byte gDungeonGlobalData
_0804574C: .4byte 0x00003a0e
_08045750:
	movs r0, 0x3
	str r0, [r4]
	ldr r0, _08045798
	adds r1, r6, r0
	mov r2, r9
	ldr r0, [r2]
	adds r0, r1
	str r0, [r4, 0x70]
	mov r3, r8
	ldr r0, [r3]
	str r0, [r4, 0x4]
	movs r1, 0
	ldrsh r0, [r3, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	adds r0, r4, 0
	bl sub_8045394
	movs r0, 0
	strh r7, [r4, 0x26]
	adds r1, r4, 0
	adds r1, 0x22
	strb r0, [r1]
	str r7, [r4, 0x1C]
	adds r0, r4, 0
	b _080457C6
	.align 2, 0
_08045798: .4byte 0x00003804
_0804579C:
	movs r5, 0
	ldr r3, _080457D4
	mov r9, r3
_080457A2:
	mov r1, r9
	ldr r0, [r1]
	lsls r6, r5, 2
	ldr r2, _080457D8
	adds r0, r2
	adds r0, r6
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _08045750
	adds r5, 0x1
	cmp r5, 0x3F
	ble _080457A2
_080457C4:
	movs r0, 0
_080457C6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080457D4: .4byte gDungeonGlobalData
_080457D8: .4byte 0x0001361c
	thumb_func_end sub_8045708

	thumb_func_start sub_80457DC
sub_80457DC:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r0, 0x5
	str r0, [r4]
	movs r6, 0
	movs r5, 0
	strh r5, [r4, 0x4]
	strh r5, [r4, 0x6]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_8045394
	strh r5, [r4, 0x26]
	adds r4, 0x22
	strb r6, [r4]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80457DC

	thumb_func_start sub_8045804
sub_8045804:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl GetEntityType
	cmp r0, 0x1
	beq _0804581C
	cmp r0, 0x1
	bcc _08045880
	cmp r0, 0x5
	beq _08045880
_08045818:
	movs r0, 0x1
	b _08045882
_0804581C:
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045880
	ldr r0, _08045874
	ldr r1, [r0]
	ldr r0, _08045878
	adds r2, r1, r0
	ldr r5, [r2, 0x10]
	ldr r3, [r4, 0x70]
	ldrb r0, [r3, 0x6]
	cmp r0, 0
	beq _08045818
	ldr r6, _0804587C
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0804584C
	adds r0, r3, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08045880
_0804584C:
	adds r0, r2, 0
	adds r0, 0x23
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045818
	adds r0, r2, 0
	adds r0, 0x25
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045818
	cmp r5, 0
	beq _08045880
	adds r1, r4, 0x4
	adds r0, r2, 0
	bl InSameRoom_2
	lsls r0, 24
	lsrs r0, 24
	b _08045882
	.align 2, 0
_08045874: .4byte gDungeonGlobalData
_08045878: .4byte 0x000181e8
_0804587C: .4byte 0x0001820f
_08045880:
	movs r0, 0
_08045882:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8045804

	thumb_func_start sub_8045888
sub_8045888:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08045988
	ldr r1, [r4, 0xC]
	cmp r1, 0
	bge _0804589C
	adds r1, 0xFF
_0804589C:
	asrs r1, 8
	ldr r0, _080458F0
	ldr r2, [r0]
	ldr r3, _080458F4
	adds r0, r2, r3
	movs r5, 0
	ldrsh r0, [r0, r5]
	subs r3, r1, r0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bge _080458B4
	adds r0, 0xFF
_080458B4:
	asrs r0, 8
	ldr r5, _080458F8
	adds r1, r2, r5
	movs r5, 0
	ldrsh r1, [r1, r5]
	subs r1, r0, r1
	movs r0, 0x20
	negs r0, r0
	cmp r3, r0
	blt _08045988
	cmp r1, r0
	blt _08045988
	movs r0, 0x88
	lsls r0, 1
	cmp r3, r0
	bgt _08045988
	cmp r1, 0xC0
	bgt _08045988
	ldr r0, _080458FC
	adds r5, r2, r0
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x5
	bhi _08045984
	lsls r0, 2
	ldr r1, _08045900
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080458F0: .4byte gDungeonGlobalData
_080458F4: .4byte 0x000181f0
_080458F8: .4byte 0x000181f2
_080458FC: .4byte 0x000181e8
_08045900: .4byte _08045904
	.align 2, 0
_08045904:
	.4byte _08045988
	.4byte _08045934
	.4byte _08045964
	.4byte _0804591C
	.4byte _08045984
	.4byte _08045988
_0804591C:
	adds r0, r5, 0
	adds r0, 0x26
_08045920:
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045984
	adds r0, r4, 0x4
	bl sub_803F428
	lsls r0, 24
_0804592E:
	cmp r0, 0
	bne _08045984
	b _08045988
_08045934:
	ldr r1, [r4, 0x70]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08045984
	ldr r0, _0804595C
	ldr r0, [r0]
	ldr r2, _08045960
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045954
	adds r0, r1, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08045988
_08045954:
	adds r0, r5, 0
	adds r0, 0x25
	b _08045920
	.align 2, 0
_0804595C: .4byte gDungeonGlobalData
_08045960: .4byte 0x0001820f
_08045964:
	ldr r0, _0804597C
	ldr r0, [r0]
	ldr r3, _08045980
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08045984
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	b _0804592E
	.align 2, 0
_0804597C: .4byte gDungeonGlobalData
_08045980: .4byte 0x0001820f
_08045984:
	movs r0, 0x1
	b _0804598A
_08045988:
	movs r0, 0
_0804598A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8045888

	.align 2, 0