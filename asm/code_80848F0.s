	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_808529C
sub_808529C:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	movs r3, 0x40
	movs r0, 0x86
	lsls r0, 1
	cmp r1, r0
	beq _08085348
	cmp r1, r0
	bgt _080852E0
	cmp r1, 0x90
	beq _08085334
	cmp r1, 0x90
	bgt _080852CE
	cmp r1, 0x38
	beq _08085354
	cmp r1, 0x38
	bgt _080852C8
	cmp r1, 0x17
	beq _08085328
	b _0808535A
_080852C8:
	cmp r1, 0x5E
	beq _08085328
	b _0808535A
_080852CE:
	cmp r1, 0x92
	beq _08085330
	cmp r1, 0x92
	blt _0808532C
	cmp r1, 0x96
	beq _08085340
	cmp r1, 0xFC
	beq _08085324
	b _0808535A
_080852E0:
	ldr r0, _08085304
	cmp r1, r0
	beq _08085358
	cmp r1, r0
	bgt _08085308
	subs r0, 0x87
	cmp r1, r0
	beq _0808534C
	cmp r1, r0
	blt _08085344
	adds r0, 0x5
	cmp r1, r0
	beq _08085350
	adds r0, 0x3A
	cmp r1, r0
	beq _08085328
	b _0808535A
	.align 2, 0
_08085304: .4byte 0x00000195
_08085308:
	ldr r0, _08085320
	cmp r2, r0
	beq _08085358
	cmp r2, r0
	blt _08085358
	adds r0, 0x4
	cmp r2, r0
	beq _08085338
	adds r0, 0x1
	cmp r2, r0
	beq _0808533C
	b _0808535A
	.align 2, 0
_08085320: .4byte 0x00000197
_08085324:
	movs r3, 0x1
	b _0808535A
_08085328:
	movs r3, 0x3
	b _0808535A
_0808532C:
	movs r3, 0x5
	b _0808535A
_08085330:
	movs r3, 0x7
	b _0808535A
_08085334:
	movs r3, 0x9
	b _0808535A
_08085338:
	movs r3, 0xC
	b _0808535A
_0808533C:
	movs r3, 0xF
	b _0808535A
_08085340:
	movs r3, 0x13
	b _0808535A
_08085344:
	movs r3, 0x15
	b _0808535A
_08085348:
	movs r3, 0x17
	b _0808535A
_0808534C:
	movs r3, 0x19
	b _0808535A
_08085350:
	movs r3, 0x1A
	b _0808535A
_08085354:
	movs r3, 0x11
	b _0808535A
_08085358:
	movs r3, 0x1D
_0808535A:
	cmp r3, 0x40
	beq _0808536E
	adds r0, r3, 0
	bl sub_8098100
	lsls r0, 24
	cmp r0, 0
	bne _0808536E
	movs r0, 0
	b _08085370
_0808536E:
	movs r0, 0x1
_08085370:
	pop {r1}
	bx r1
	thumb_func_end sub_808529C

	thumb_func_start sub_8085374
sub_8085374:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	movs r7, 0
	movs r6, 0
	bl sub_808D3F8
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	mov r8, r1
	movs r5, 0
_0808538E:
	ldr r0, _08085444
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08085448
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080853BE
	ldr r1, [r4, 0x70]
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _080853B2
	adds r7, r4, 0
_080853B2:
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	bne _080853BE
	adds r6, r4, 0
_080853BE:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0808538E
	cmp r7, 0
	beq _0808546E
	cmp r6, 0
	bne _0808546E
	ldr r0, _08085444
	ldr r0, [r0]
	ldr r1, _0808544C
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0808546E
	movs r6, 0
	ldr r0, _08085450
	ldr r4, [r0]
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x63
	beq _0808546E
	mov r5, sp
	movs r0, 0
	mov r9, r0
_080853EE:
	ldrh r0, [r7, 0x4]
	adds r0, r4
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08085454
	ands r4, r1
	orrs r4, r0
	asrs r1, r4, 16
	ldrh r2, [r7, 0x6]
	adds r1, r2
	lsls r1, 16
	ldr r0, _08085458
	ands r4, r0
	orrs r4, r1
	lsls r0, r4, 16
	asrs r0, 16
	asrs r1, r4, 16
	bl GetMapTileAtPosition
	adds r1, r0, 0
	mov r0, r8
	bl sub_807034C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0808545C
	mov r0, r8
	strh r0, [r5]
	movs r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x2
	strb r0, [r5, 0x2]
	str r4, [sp, 0xC]
	str r1, [sp, 0x4]
	mov r1, r9
	strb r1, [r5, 0x10]
	mov r0, sp
	movs r1, 0x1
	bl sub_806B7F8
	b _0808546E
	.align 2, 0
_08085444: .4byte gDungeonGlobalData
_08085448: .4byte 0x0001357c
_0808544C: .4byte 0x0000065c
_08085450: .4byte gUnknown_80F4598
_08085454: .4byte 0xffff0000
_08085458: .4byte 0x0000ffff
_0808545C:
	adds r6, 0x1
	ldr r0, _0808547C
	lsls r1, r6, 2
	adds r1, r0
	ldr r4, [r1]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x63
	bne _080853EE
_0808546E:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808547C: .4byte gUnknown_80F4598
	thumb_func_end sub_8085374

	thumb_func_start xxx_call_GetLeaderEntity
xxx_call_GetLeaderEntity:
	push {lr}
	bl GetLeaderEntity
	pop {r1}
	bx r1
	thumb_func_end xxx_call_GetLeaderEntity

	thumb_func_start GetPartnerEntity
GetPartnerEntity:
	push {r4,r5,lr}
	movs r5, 0
_08085490:
	ldr r0, _080854B8
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080854BC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080854C0
	ldr r0, [r4, 0x70]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	bne _080854C0
	adds r0, r4, 0
	b _080854CC
	.align 2, 0
_080854B8: .4byte gDungeonGlobalData
_080854BC: .4byte 0x0001357c
_080854C0:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08085490
	movs r0, 0x2
	bl sub_8085680
_080854CC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetPartnerEntity

	thumb_func_start sub_80854D4
sub_80854D4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	movs r6, 0
	movs r5, 0
	add r0, sp, 0x10
	mov r8, r0
	mov r7, sp
_080854E6:
	ldr r0, _080855D8
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080855DC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08085504
	stm r7!, {r4}
	adds r6, 0x1
_08085504:
	adds r5, 0x1
	cmp r5, 0x3
	ble _080854E6
	cmp r6, 0x3
	bgt _0808551C
	movs r1, 0
	lsls r0, r6, 2
	add r0, sp
_08085514:
	stm r0!, {r1}
	adds r6, 0x1
	cmp r6, 0x3
	ble _08085514
_0808551C:
	movs r6, 0
	movs r4, 0
	mov r2, sp
	mov r3, r8
	movs r5, 0x3
_08085526:
	ldr r1, [r2]
	cmp r1, 0
	beq _0808553A
	ldr r0, [r1, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0808553A
	str r4, [r2]
	stm r3!, {r1}
	adds r6, 0x1
_0808553A:
	adds r2, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08085526
	movs r4, 0
	mov r2, sp
	lsls r0, r6, 2
	mov r1, r8
	adds r3, r0, r1
	movs r5, 0x3
_0808554E:
	ldr r1, [r2]
	cmp r1, 0
	beq _08085564
	ldr r0, [r1, 0x70]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	bne _08085564
	str r4, [r2]
	stm r3!, {r1}
	adds r6, 0x1
_08085564:
	adds r2, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _0808554E
	movs r3, 0
	mov r2, sp
	lsls r0, r6, 2
	add r0, r8
	movs r5, 0x3
_08085576:
	ldr r1, [r2]
	cmp r1, 0
	beq _08085582
	str r3, [r2]
	stm r0!, {r1}
	adds r6, 0x1
_08085582:
	adds r2, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08085576
	cmp r6, 0x3
	bgt _0808559C
	movs r1, 0
	lsls r0, r6, 2
	add r0, r8
_08085594:
	stm r0!, {r1}
	adds r6, 0x1
	cmp r6, 0x3
	ble _08085594
_0808559C:
	movs r5, 0
	mov r4, r8
_080855A0:
	lsls r1, r5, 2
	ldr r3, [r4]
	cmp r3, 0
	beq _080855C4
	ldr r0, _080855D8
	ldr r0, [r0]
	adds r0, r1
	ldr r2, _080855E0
	adds r1, r0, r2
	movs r6, 0
	ldrsh r1, [r1, r6]
	adds r2, 0x2
	adds r0, r2
	movs r6, 0
	ldrsh r2, [r0, r6]
	adds r0, r3, 0
	bl sub_80856C8
_080855C4:
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0x3
	ble _080855A0
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080855D8: .4byte gDungeonGlobalData
_080855DC: .4byte 0x0001357c
_080855E0: .4byte 0x0000e220
	thumb_func_end sub_80854D4

	thumb_func_start sub_80855E4
sub_80855E4:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r7, 0
	movs r5, 0
_080855EC:
	ldr r0, _08085634
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08085638
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08085618
	ldr r0, [r4, 0x70]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	bne _08085612
	movs r7, 0x1
_08085612:
	adds r0, r4, 0
	bl _call_via_r6
_08085618:
	adds r5, 0x1
	cmp r5, 0x3
	ble _080855EC
	cmp r7, 0
	bne _0808562E
	bl GetPartnerEntity
	cmp r0, 0
	beq _0808562E
	bl _call_via_r6
_0808562E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085634: .4byte gDungeonGlobalData
_08085638: .4byte 0x0001357c
	thumb_func_end sub_80855E4

	thumb_func_start sub_808563C
sub_808563C:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
_08085642:
	ldr r0, _08085678
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0808567C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0808566C
	ldr r0, [r4, 0x70]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	beq _0808566C
	adds r0, r4, 0
	bl _call_via_r6
_0808566C:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08085642
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085678: .4byte gDungeonGlobalData
_0808567C: .4byte 0x0001358c
	thumb_func_end sub_808563C

	thumb_func_start sub_8085680
sub_8085680:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
_08085688:
	ldr r0, _080856B0
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080856B4
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080856B8
	ldr r0, [r4, 0x70]
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, r6
	bne _080856B8
	adds r0, r4, 0
	b _080856C0
	.align 2, 0
_080856B0: .4byte gDungeonGlobalData
_080856B4: .4byte 0x000135cc
_080856B8:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08085688
	movs r0, 0
_080856C0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8085680

	thumb_func_start sub_80856C8
sub_80856C8:
	push {r4,lr}
	adds r4, r0, 0
	movs r3, 0x1
	bl sub_80694C0
	adds r0, r4, 0
	movs r1, 0
	bl sub_804535C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80856C8

	thumb_func_start sub_80856E0
sub_80856E0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r1, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	adds r0, r6, 0
	movs r1, 0x6
	adds r2, r7, 0
	bl sub_80861D4
	movs r5, 0xBA
	lsls r5, 1
	add r5, r8
	movs r4, 0x4
_08085700:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1
	str r0, [r5]
	movs r0, 0x46
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08085700
	movs r1, 0x7
	adds r0, r7, 0
	ands r0, r1
	mov r1, r8
	adds r1, 0x46
	strb r0, [r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_806CE68
	movs r5, 0xBA
	lsls r5, 1
	add r5, r8
	movs r4, 0x4
_08085732:
	ldr r0, [r5]
	ldr r1, _08085760
	adds r0, r1
	str r0, [r5]
	movs r0, 0x46
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08085732
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	movs r0, 0
	str r0, [r1]
	movs r0, 0x46
	bl sub_803E46C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085760: .4byte 0xfffffe00
	thumb_func_end sub_80856E0

	thumb_func_start sub_8085764
sub_8085764:
	push {r4,r5,lr}
	sub sp, 0x74
	mov r0, sp
	bl sub_80457DC
	movs r5, 0
_08085770:
	ldr r0, _080857AC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080857B0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0808579E
	ldr r0, [r4, 0x70]
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0808579E
	adds r0, r4, 0
	ldr r1, _080857B4
	mov r2, sp
	bl sub_8068FE0
_0808579E:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08085770
	add sp, 0x74
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080857AC: .4byte gDungeonGlobalData
_080857B0: .4byte 0x0001358c
_080857B4: .4byte 0x00000207
	thumb_func_end sub_8085764

	thumb_func_start sub_80857B8
sub_80857B8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	ldr r0, _08085854
	mov r9, r0
	ldr r1, _08085858
	mov r8, r1
_080857CA:
	mov r2, r9
	ldr r0, [r2]
	lsls r1, r7, 2
	ldr r3, _0808585C
	adds r0, r3
	adds r0, r1
	ldr r6, [r0]
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08085840
	ldr r5, [r6, 0x70]
	mov r0, r9
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08085840
	ldrb r4, [r1, 0x2]
	cmp r4, 0
	bne _08085840
	adds r0, r6, 0
	movs r1, 0
	bl sub_804535C
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, r5, 0
	adds r1, 0xFE
	movs r0, 0x63
	strb r0, [r1]
	adds r2, r5, 0
	adds r2, 0x46
	ldrb r0, [r2]
	lsls r0, 2
	add r0, r8
	ldrh r1, [r6, 0x4]
	ldrh r0, [r0]
	adds r1, r0
	movs r3, 0xB6
	lsls r3, 1
	adds r0, r5, r3
	strh r1, [r0]
	ldrb r0, [r2]
	lsls r0, 2
	add r0, r8
	ldrh r1, [r6, 0x6]
	ldrh r0, [r0, 0x2]
	adds r1, r0
	adds r3, 0x2
	adds r0, r5, r3
	strh r1, [r0]
	ldrb r1, [r2]
	adds r0, r6, 0
	bl sub_806CE68
_08085840:
	adds r7, 0x1
	cmp r7, 0x13
	ble _080857CA
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085854: .4byte gDungeonGlobalData
_08085858: .4byte gAdjacentTileOffsets
_0808585C: .4byte 0x000135cc
	thumb_func_end sub_80857B8

	thumb_func_start sub_8085860
sub_8085860:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	bl sub_803F4A0
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 11
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2
	bl sub_803F878
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8085860

	thumb_func_start sub_8085890
sub_8085890:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	bl sub_803F4A0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_803F878
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8085890

	thumb_func_start sub_80858AC
sub_80858AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r4, r1, 0
	bl sub_803F994
	adds r6, r0, 0
	bl sub_803F9B0
	adds r5, r0, 0
	ldr r0, [r7]
	subs r0, r6
	adds r1, r4, 0
	bl __divsi3
	mov r9, r0
	ldr r0, [r7, 0x4]
	subs r0, r5
	adds r1, r4, 0
	bl __divsi3
	mov r8, r0
	movs r0, 0
	bl sub_803F4A0
	cmp r4, 0
	ble _080858FE
_080858E6:
	add r6, r9
	add r5, r8
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_803F878
	movs r0, 0x46
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bne _080858E6
_080858FE:
	ldr r0, [r7]
	ldr r1, [r7, 0x4]
	bl sub_803F878
	movs r0, 0x46
	bl sub_803E46C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80858AC

	thumb_func_start SetFacingDirection
SetFacingDirection:
	push {r4,lr}
	ldr r3, [r0, 0x70]
	movs r4, 0x7
	adds r2, r1, 0
	ands r2, r4
	adds r3, 0x46
	strb r2, [r3]
	bl sub_806CE68
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SetFacingDirection

	thumb_func_start sub_8085930
sub_8085930:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r5, 0
	movs r0, 0x7
	adds r7, r6, 0
	ands r7, r0
_0808593C:
	ldr r0, _0808596C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08085970
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08085982
	cmp r6, 0x7
	ble _08085974
	movs r0, 0x8
	bl RandomCapped
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_806CE68
	b _08085982
	.align 2, 0
_0808596C: .4byte gDungeonGlobalData
_08085970: .4byte 0x0001357c
_08085974:
	ldr r0, [r4, 0x70]
	adds r0, 0x46
	strb r7, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_806CE68
_08085982:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0808593C
	movs r5, 0
	movs r0, 0x7
	adds r7, r6, 0
	ands r7, r0
_08085990:
	ldr r0, _080859CC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080859D0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080859E2
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080859E2
	cmp r6, 0x7
	ble _080859D4
	movs r0, 0x8
	bl RandomCapped
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_806CE68
	b _080859E2
	.align 2, 0
_080859CC: .4byte gDungeonGlobalData
_080859D0: .4byte 0x0001358c
_080859D4:
	adds r0, r1, 0
	adds r0, 0x46
	strb r7, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_806CE68
_080859E2:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08085990
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8085930

	thumb_func_start sub_80859F0
sub_80859F0:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r5, 0
	movs r0, 0x7
	adds r7, r6, 0
	ands r7, r0
_080859FC:
	ldr r0, _08085A2C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08085A30
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08085A42
	cmp r6, 0x7
	ble _08085A34
	movs r0, 0x8
	bl RandomCapped
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_806CE68
	b _08085A42
	.align 2, 0
_08085A2C: .4byte gDungeonGlobalData
_08085A30: .4byte 0x0001358c
_08085A34:
	ldr r0, [r4, 0x70]
	adds r0, 0x46
	strb r7, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_806CE68
_08085A42:
	adds r5, 0x1
	cmp r5, 0xF
	ble _080859FC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80859F0

	.align 2, 0
