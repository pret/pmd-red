	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



	thumb_func_start sub_8041168
sub_8041168:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r8, r0
	adds r6, r1, 0
	adds r7, r2, 0
	mov r9, r3
	adds r1, r7, 0
	bl sub_804143C
	adds r5, r0, 0
	cmp r5, 0
	beq _0804118A
	movs r5, 0x1
_0804118A:
	ldrh r4, [r7, 0x2]
	mov r0, r8
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	bl sub_800ECB8
	movs r1, 0x4
	ldrsh r5, [r0, r1]
	movs r2, 0
	str r2, [sp, 0x14]
	adds r0, r6, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _080411CA
	ldr r0, [r6, 0x70]
	str r0, [sp, 0x14]
	adds r0, r6, 0
	bl sub_8042768
	b _080411D0
_080411CA:
	mov r0, r9
	bl sub_803F428
_080411D0:
	lsls r0, 24
	cmp r0, 0
	beq _080412CE
	mov r0, r8
	adds r1, r7, 0
	bl sub_80414C0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080412CE
	cmp r5, 0
	beq _080412CE
	adds r0, r5, 0
	bl sub_800ECA4
	ldr r5, [r0, 0x1C]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _08041216
	adds r0, r6, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _08041216
	add r0, sp, 0x8
	adds r1, r6, 0
	adds r1, 0x28
	lsls r2, r5, 24
	lsrs r2, 24
	bl sub_800569C
	b _08041218
_08041216:
	str r4, [sp, 0x8]
_08041218:
	mov r0, sp
	mov r1, r10
	strh r1, [r0]
	ldr r2, [sp, 0x14]
	cmp r2, 0
	beq _08041248
	mov r1, sp
	ldrh r0, [r2, 0x4]
	strh r0, [r1, 0x2]
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08041232
	adds r0, 0xFF
_08041232:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _08041240
	adds r0, 0xFF
_08041240:
	asrs r0, 8
	strh r0, [r1, 0x6]
	movs r0, 0
	b _0804128C
_08041248:
	mov r1, sp
	movs r0, 0x1
	strh r0, [r1, 0x2]
	mov r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r1, sp
	movs r2, 0xC0
	lsls r2, 4
	adds r0, r2
	cmp r0, 0
	bge _08041268
	adds r0, 0xFF
_08041268:
	asrs r0, 8
	strh r0, [r1, 0x4]
	mov r0, r9
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	mov r1, sp
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2
	cmp r0, 0
	bge _08041286
	adds r0, 0xFF
_08041286:
	asrs r0, 8
	strh r0, [r1, 0x6]
	ldr r0, [sp, 0x14]
_0804128C:
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	mov r0, sp
	bl sub_8041500
	mov r0, r10
	bl sub_800EEE0
	bl sub_800EF64
	mov r0, sp
	bl sub_800EBC8
	adds r4, r0, 0
	movs r0, 0x5B
	bl sub_803E46C
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x6
	bl sub_8042DD4
	b _080412C2
_080412BC:
	movs r0, 0x28
	bl sub_803E46C
_080412C2:
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _080412BC
_080412CE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8041168

	thumb_func_start sub_80412E0
sub_80412E0:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r0, r1, 24
	adds r3, r4, 0
	cmp r3, 0x1F
	bne _08041344
	cmp r0, 0x7
	bls _080412F6
	b _080413F6
_080412F6:
	lsls r0, 2
	ldr r1, _08041300
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08041300: .4byte _08041304
	.align 2, 0
_08041304:
	.4byte _080413F4
	.4byte _08041324
	.4byte _0804132A
	.4byte _080413F4
	.4byte _08041334
	.4byte _0804133A
	.4byte _080413F4
	.4byte _0804133A
_08041324:
	movs r3, 0xCF
	lsls r3, 1
	b _080413F6
_0804132A:
	ldr r3, _08041330
	b _080413F6
	.align 2, 0
_08041330: .4byte 0x000001a1
_08041334:
	movs r3, 0xD0
	lsls r3, 1
	b _080413F6
_0804133A:
	ldr r3, _08041340
	b _080413F6
	.align 2, 0
_08041340: .4byte 0x0000019f
_08041344:
	cmp r2, 0
	beq _080413F6
	cmp r3, 0x97
	beq _080413B4
	cmp r3, 0x97
	bgt _0804136C
	cmp r3, 0x3C
	beq _0804139C
	cmp r3, 0x3C
	bgt _08041362
	cmp r3, 0x8
	beq _08041396
	cmp r3, 0x19
	beq _080413E4
	b _080413F4
_08041362:
	cmp r3, 0x4B
	beq _080413A4
	cmp r3, 0x64
	beq _080413AA
	b _080413F4
_0804136C:
	cmp r3, 0xCD
	beq _080413CA
	cmp r3, 0xCD
	bgt _0804137E
	cmp r3, 0x99
	beq _080413BA
	cmp r3, 0x9C
	beq _080413C4
	b _080413F4
_0804137E:
	cmp r3, 0xED
	beq _080413DA
	cmp r3, 0xED
	bgt _0804138C
	cmp r3, 0xE3
	beq _080413EA
	b _080413F4
_0804138C:
	movs r0, 0xAE
	lsls r0, 1
	cmp r3, r0
	beq _080413D4
	b _080413F4
_08041396:
	movs r3, 0xD1
	lsls r3, 1
	b _080413F6
_0804139C:
	ldr r3, _080413A0
	b _080413F6
	.align 2, 0
_080413A0: .4byte 0x000001a3
_080413A4:
	movs r3, 0xD2
	lsls r3, 1
	b _080413F6
_080413AA:
	ldr r3, _080413B0
	b _080413F6
	.align 2, 0
_080413B0: .4byte 0x000001a5
_080413B4:
	movs r3, 0xD3
	lsls r3, 1
	b _080413F6
_080413BA:
	ldr r3, _080413C0
	b _080413F6
	.align 2, 0
_080413C0: .4byte 0x000001a7
_080413C4:
	movs r3, 0xD4
	lsls r3, 1
	b _080413F6
_080413CA:
	ldr r3, _080413D0
	b _080413F6
	.align 2, 0
_080413D0: .4byte 0x000001a9
_080413D4:
	movs r3, 0xD5
	lsls r3, 1
	b _080413F6
_080413DA:
	ldr r3, _080413E0
	b _080413F6
	.align 2, 0
_080413E0: .4byte 0x000001ab
_080413E4:
	movs r3, 0xD6
	lsls r3, 1
	b _080413F6
_080413EA:
	ldr r3, _080413F0
	b _080413F6
	.align 2, 0
_080413F0: .4byte 0x000001ad
_080413F4:
	adds r3, r4, 0
_080413F6:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80412E0

	thumb_func_start sub_8041400
sub_8041400:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800ED20
	pop {r1}
	bx r1
	thumb_func_end sub_8041400

	thumb_func_start sub_804141C
sub_804141C:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 24
	lsrs r1, 24
	bl sub_80412E0
	lsls r0, 16
	lsrs r0, 16
	bl sub_800EC84
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_804141C

	thumb_func_start sub_804143C
sub_804143C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrh r0, [r5, 0x2]
	cmp r0, 0xED
	bne _08041476
	adds r0, r4, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _080414A4
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080414A4
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _080414A0
	adds r0, r1, 0
	adds r0, 0x5D
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _080414A0
	b _0804148A
_08041476:
	cmp r0, 0x19
	beq _0804147E
	cmp r0, 0xE3
	bne _0804148E
_0804147E:
	adds r0, r4, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	beq _080414A0
_0804148A:
	movs r0, 0
	b _080414B8
_0804148E:
	cmp r0, 0x97
	bne _080414A4
	adds r0, r4, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080414A4
_080414A0:
	movs r0, 0x1
	b _080414B8
_080414A4:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MoveMatchesBideClassStatus
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_080414B8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_804143C

	thumb_func_start sub_80414C0
sub_80414C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrh r0, [r4, 0x2]
	cmp r0, 0x9C
	bne _080414DC
	adds r0, r5, 0
	bl GetTileAtEntitySafe
	bl IsTileGround
	lsls r0, 24
	cmp r0, 0
	bne _080414F2
_080414DC:
	ldrh r0, [r4, 0x2]
	cmp r0, 0x8
	bne _080414F6
	adds r0, r5, 0
	bl GetTileAtEntitySafe
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _080414F6
_080414F2:
	movs r0, 0x1
	b _080414F8
_080414F6:
	movs r0, 0
_080414F8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80414C0

	thumb_func_start sub_8041500
sub_8041500:
	push {lr}
	bl sub_800E7D0
	lsls r0, 24
	cmp r0, 0
	beq _08041518
	movs r0, 0x5C
	bl sub_803E46C
	movs r0, 0x5D
	bl sub_8052740
_08041518:
	pop {r0}
	bx r0
	thumb_func_end sub_8041500

	thumb_func_start sub_804151C
sub_804151C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_800DC9C
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8041550
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_804151C

	thumb_func_start sub_8041550
sub_8041550:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r7, r0, 0
	mov r10, r1
	ldr r0, [sp, 0x54]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x2C]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	ldr r0, [r7, 0x70]
	mov r8, r0
	adds r0, r7, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	cmp r6, 0
	bne _080415A2
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080415A2
_0804159C:
	movs r0, 0x1
	negs r0, r0
	b _08041692
_080415A2:
	ldr r1, [sp, 0x50]
	cmp r1, 0
	beq _080415B4
	movs r0, 0
	cmp r1, 0x2
	bne _080415B0
	movs r0, 0x1
_080415B0:
	bl sub_804178C
_080415B4:
	add r6, sp, 0x28
	adds r1, r7, 0
	adds r1, 0x28
	adds r0, r6, 0
	mov r2, r9
	bl sub_800569C
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0x63
	beq _080415F2
	ldrh r0, [r6, 0x2]
	cmp r0, 0x63
	beq _080415F2
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsls r0, 8
	ldr r1, [r7, 0xC]
	adds r4, r1, r0
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	lsls r0, 8
	ldr r2, [r7, 0x10]
	adds r0, r2, r0
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	ldr r1, [r1]
	subs r5, r0, r1
	adds r1, r2, 0
	b _08041600
_080415F2:
	ldr r4, [r7, 0xC]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r8
	ldr r1, [r7, 0x10]
	ldr r0, [r0]
	subs r5, r1, r0
_08041600:
	cmp r1, 0
	bge _08041606
	adds r1, 0xFF
_08041606:
	asrs r1, 8
	ldr r0, _0804166C
	ldr r0, [r0]
	ldr r2, _08041670
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r1, r0, 1
	adds r1, 0x1
	mov r0, r10
	str r0, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r6, 0x1
	negs r6, r6
	str r6, [sp, 0x8]
	mov r2, sp
	adds r0, r4, 0
	cmp r4, 0
	bge _08041636
	adds r0, 0xFF
_08041636:
	asrs r0, 8
	strh r0, [r2, 0xC]
	mov r2, sp
	adds r0, r5, 0
	cmp r0, 0
	bge _08041644
	adds r0, 0xFF
_08041644:
	asrs r0, 8
	strh r0, [r2, 0xE]
	str r6, [sp, 0x14]
	mov r0, sp
	strh r3, [r0, 0x10]
	strh r3, [r0, 0x12]
	str r1, [sp, 0x18]
	add r0, sp, 0x1C
	bl sub_8004E8C
	mov r0, sp
	movs r1, 0
	bl sub_8041764
	adds r4, r0, 0
	ldr r1, [sp, 0x2C]
	cmp r1, 0
	beq _08041690
	movs r5, 0
	b _0804167C
	.align 2, 0
_0804166C: .4byte gDungeon
_08041670: .4byte 0x000181f2
_08041674:
	movs r0, 0x42
	bl sub_803E46C
	adds r5, 0x1
_0804167C:
	cmp r5, 0x63
	bgt _0804168C
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08041674
_0804168C:
	movs r4, 0x1
	negs r4, r4
_08041690:
	adds r0, r4, 0
_08041692:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8041550

        .align 2,0
