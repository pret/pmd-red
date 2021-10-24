	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80951BC
sub_80951BC:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8095190
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080951F4
	ldr r0, _080951F0
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r1, r0
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	b _080951F6
	.align 2, 0
_080951F0: .4byte gUnknown_203B480
_080951F4:
	movs r0, 0
_080951F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80951BC

	thumb_func_start sub_80951FC
sub_80951FC:
	push {r4,r5,lr}
	ldr r1, _08095224
	ldr r1, [r1]
	adds r1, 0x30
	ldrb r2, [r1]
	negs r3, r2
	orrs r3, r2
	lsrs r3, 31
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08095224: .4byte gUnknown_203B480
	thumb_func_end sub_80951FC

	thumb_func_start sub_8095228
sub_8095228:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _0809523C
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_0809523C: .4byte gUnknown_203B480
	thumb_func_end sub_8095228

	thumb_func_start sub_8095240
sub_8095240:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, _08095270
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 4
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x22
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08095270: .4byte gUnknown_203B480
	thumb_func_end sub_8095240

	thumb_func_start sub_8095274
sub_8095274:
	push {lr}
	ldr r1, _08095294
	ldr r3, [r1]
	adds r2, r3, 0
	ldm r2!, {r1}
	lsls r1, 2
	adds r2, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0
	cmp r0, 0x1E
	bgt _0809528E
	adds r1, r0, 0x1
_0809528E:
	str r1, [r3]
	pop {r0}
	bx r0
	.align 2, 0
_08095294: .4byte gUnknown_203B48C
	thumb_func_end sub_8095274

	thumb_func_start sub_8095298
sub_8095298:
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, _080952B0
	ldr r0, [r0]
	adds r1, r0, 0x4
_080952A4:
	ldr r0, [r1]
	cmp r0, r3
	bne _080952B4
	movs r0, 0x1
	b _080952BE
	.align 2, 0
_080952B0: .4byte gUnknown_203B48C
_080952B4:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, 0x1F
	ble _080952A4
	movs r0, 0
_080952BE:
	pop {r1}
	bx r1
	thumb_func_end sub_8095298

	thumb_func_start sub_80952C4
sub_80952C4:
	push {r4,lr}
	ldr r2, _080952EC
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1]
	movs r3, 0
	adds r4, r2, 0
	movs r2, 0x1
	negs r2, r2
_080952D6:
	ldr r0, [r4]
	lsls r1, r3, 2
	adds r0, 0x4
	adds r0, r1
	str r2, [r0]
	adds r3, 0x1
	cmp r3, 0x1F
	ble _080952D6
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080952EC: .4byte gUnknown_203B48C
	thumb_func_end sub_80952C4

	thumb_func_start sub_80952F0
sub_80952F0:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	movs r3, 0
	ldr r0, _08095310
	ldr r2, [r0]
_080952FE:
	ldrb r0, [r2]
	cmp r0, r1
	bne _08095314
	ldr r0, [r2, 0x10]
	cmp r0, r4
	bne _08095314
	movs r0, 0x1
	b _0809531E
	.align 2, 0
_08095310: .4byte gUnknown_203B480
_08095314:
	adds r2, 0x30
	adds r3, 0x1
	cmp r3, 0x1F
	ble _080952FE
	movs r0, 0
_0809531E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80952F0

	thumb_func_start sub_8095324
sub_8095324:
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, _0809534C
	ldr r1, [r0]
	movs r2, 0x1F
_08095332:
	ldrb r0, [r1]
	cmp r0, r4
	bne _0809533A
	adds r3, 0x1
_0809533A:
	adds r1, 0x30
	subs r2, 0x1
	cmp r2, 0
	bge _08095332
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809534C: .4byte gUnknown_203B480
	thumb_func_end sub_8095324

	thumb_func_start sub_8095350
sub_8095350:
	push {lr}
	movs r3, 0
	ldr r0, _08095370
	ldr r1, [r0]
	movs r2, 0x1F
_0809535A:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08095362
	adds r3, 0x1
_08095362:
	adds r1, 0x30
	subs r2, 0x1
	cmp r2, 0
	bge _0809535A
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_08095370: .4byte gUnknown_203B480
	thumb_func_end sub_8095350

	thumb_func_start sub_8095374
sub_8095374:
	push {lr}
	movs r3, 0x1
	negs r3, r3
	movs r2, 0
	ldr r0, _08095398
	ldr r1, [r0]
_08095380:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08095388
	adds r3, r2, 0
_08095388:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _08095380
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_08095398: .4byte gUnknown_203B480
	thumb_func_end sub_8095374

	thumb_func_start sub_809539C
sub_809539C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	movs r3, 0
	ldr r0, _080953BC
	ldr r2, [r0]
_080953AA:
	ldrb r0, [r2]
	cmp r0, r1
	bne _080953C0
	ldr r0, [r2, 0x10]
	cmp r0, r4
	bne _080953C0
	adds r0, r3, 0
	b _080953CC
	.align 2, 0
_080953BC: .4byte gUnknown_203B480
_080953C0:
	adds r2, 0x30
	adds r3, 0x1
	cmp r3, 0x1F
	ble _080953AA
	movs r0, 0x1
	negs r0, r0
_080953CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809539C

	thumb_func_start sub_80953D4
sub_80953D4:
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, _080953EC
	ldr r1, [r0]
_080953E0:
	ldrb r0, [r1]
	cmp r0, r3
	bne _080953F0
	adds r0, r2, 0
	b _080953FC
	.align 2, 0
_080953EC: .4byte gUnknown_203B480
_080953F0:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _080953E0
	movs r0, 0x1
	negs r0, r0
_080953FC:
	pop {r1}
	bx r1
	thumb_func_end sub_80953D4

	thumb_func_start sub_8095400
sub_8095400:
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, _08095418
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x10
_0809540E:
	ldr r0, [r1]
	cmp r0, r3
	bne _0809541C
	adds r0, r2, 0
	b _08095428
	.align 2, 0
_08095418: .4byte gUnknown_203B480
_0809541C:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _0809540E
	movs r0, 0x1
	negs r0, r0
_08095428:
	pop {r1}
	bx r1
	thumb_func_end sub_8095400

	thumb_func_start sub_809542C
sub_809542C:
	push {r4,lr}
	sub sp, 0x14
	ldr r4, _08095490
	ldr r2, [r4]
	movs r1, 0x1
	strb r1, [r2]
	ldr r2, [r4]
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2, 0x4]
	str r1, [r2, 0x8]
	bl Random
	bl sub_8094D28
	bl sub_8094E4C
	ldr r1, [r4]
	str r0, [r1, 0x10]
	bl sub_808D33C
	ldr r1, [r4]
	ldrh r0, [r0, 0x8]
	strh r0, [r1, 0xC]
	bl sub_808D33C
	adds r1, r0, 0
	mov r0, sp
	bl sub_808DA34
	ldr r0, [r4]
	adds r0, 0x14
	mov r1, sp
	bl CopyStringtoBuffer
	bl sub_8011C34
	ldr r1, [r4]
	str r0, [r1, 0x24]
	ldrb r0, [r1, 0x4]
	bl GetUnk3
	ldr r1, [r4]
	adds r1, 0x2C
	strb r0, [r1]
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095490: .4byte gUnknown_203B480
	thumb_func_end sub_809542C

	thumb_func_start sub_8095494
sub_8095494:
	lsls r1, 24
	lsrs r1, 24
	ldr r2, _080954B0
	ldr r3, [r2]
	lsls r2, r1, 1
	adds r2, r1
	lsls r2, 4
	adds r3, r2
	ldr r1, [r3, 0x4]
	ldr r2, [r3, 0x8]
	str r1, [r0]
	str r2, [r0, 0x4]
	bx lr
	.align 2, 0
_080954B0: .4byte gUnknown_203B480
	thumb_func_end sub_8095494

	thumb_func_start sub_80954B4
sub_80954B4:
	push {lr}
	movs r0, 0x3
	bl sub_8095324
	cmp r0, 0
	bne _080954C4
	movs r0, 0
	b _080954C6
_080954C4:
	movs r0, 0x1
_080954C6:
	pop {r1}
	bx r1
	thumb_func_end sub_80954B4

	thumb_func_start sub_80954CC
sub_80954CC:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl xxx_init_struct_8094924_restore_809485C
	ldr r6, _08095618
	movs r5, 0
	movs r4, 0x1F
_080954E2:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8095774
	adds r5, 0x30
	subs r4, 0x1
	cmp r4, 0
	bge _080954E2
	ldr r4, _0809561C
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl RestoreIntegerBits
	ldr r5, [r4]
	adds r4, r5, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x58
	bl memset
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl RestoreIntegerBits
	adds r1, r5, 0x6
	mov r0, sp
	movs r2, 0x1
	bl RestoreIntegerBits
	adds r1, r5, 0x7
	mov r0, sp
	movs r2, 0x7
	bl RestoreIntegerBits
	adds r4, 0x4
	mov r0, sp
	adds r1, r4, 0
	bl xxx_restore_poke_sub_4_8090314
	adds r1, r5, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x9
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x10
	mov r0, sp
	bl xxx_restore_poke_sub_c_808F410
	adds r1, r5, 0
	adds r1, 0x14
	mov r0, sp
	bl xxx_restore_poke_sub_c_808F410
	adds r1, r5, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0xA
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x1A
	mov r0, sp
	movs r2, 0xA
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x1C
	mov r0, sp
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x1D
	mov r0, sp
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x1E
	mov r0, sp
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x1F
	mov r0, sp
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x20
	mov r0, sp
	movs r2, 0x18
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x24
	mov r0, sp
	movs r2, 0x18
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x28
	mov r0, sp
	movs r2, 0x4
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x2C
	mov r0, sp
	bl RestoreHeldItem
	adds r1, r5, 0
	adds r1, 0x30
	mov r0, sp
	bl RestorePokemonMoves
	adds r1, r5, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x50
	bl RestoreIntegerBits
	ldr r4, _08095620
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl RestoreIntegerBits
	adds r6, r4, 0
	movs r5, 0x4
	movs r4, 0x1F
_080955F4:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0x20
	bl RestoreIntegerBits
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _080955F4
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095618: .4byte gUnknown_203B480
_0809561C: .4byte gUnknown_203B484
_08095620: .4byte gUnknown_203B48C
	thumb_func_end sub_80954CC

	thumb_func_start sub_8095624
sub_8095624:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl xxx_init_struct_8094924_save_809486C
	ldr r6, _08095768
	movs r5, 0
	movs r4, 0x1F
_0809563A:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8095824
	adds r5, 0x30
	subs r4, 0x1
	cmp r4, 0
	bge _0809563A
	ldr r4, _0809576C
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl SaveIntegerBits
	ldr r5, [r4]
	adds r4, r5, 0x4
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl SaveIntegerBits
	adds r1, r5, 0x6
	mov r0, sp
	movs r2, 0x1
	bl SaveIntegerBits
	adds r1, r5, 0x7
	mov r0, sp
	movs r2, 0x7
	bl SaveIntegerBits
	adds r4, 0x4
	mov r0, sp
	adds r1, r4, 0
	bl xxx_save_poke_sub_4_80902F4
	adds r1, r5, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x9
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x10
	mov r0, sp
	bl xxx_save_poke_sub_c_808F41C
	adds r1, r5, 0
	adds r1, 0x14
	mov r0, sp
	bl xxx_save_poke_sub_c_808F41C
	adds r1, r5, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0xA
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x1A
	mov r0, sp
	movs r2, 0xA
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x1C
	mov r0, sp
	movs r2, 0x8
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x1D
	mov r0, sp
	movs r2, 0x8
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x1E
	mov r0, sp
	movs r2, 0x8
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x1F
	mov r0, sp
	movs r2, 0x8
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x20
	mov r0, sp
	movs r2, 0x18
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x24
	mov r0, sp
	movs r2, 0x18
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x28
	mov r0, sp
	movs r2, 0x4
	bl SaveIntegerBits
	adds r1, r5, 0
	adds r1, 0x2C
	mov r0, sp
	bl SaveHeldItem
	adds r1, r5, 0
	adds r1, 0x30
	mov r0, sp
	bl SavePokemonMoves
	adds r1, r5, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x50
	bl SaveIntegerBits
	ldr r4, _08095770
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl SaveIntegerBits
	adds r6, r4, 0
	movs r5, 0x4
	movs r4, 0x1F
_08095742:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0x20
	bl SaveIntegerBits
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08095742
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095768: .4byte gUnknown_203B480
_0809576C: .4byte gUnknown_203B484
_08095770: .4byte gUnknown_203B48C
	thumb_func_end sub_8095624

	thumb_func_start sub_8095774
sub_8095774:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl RestoreIntegerBits
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl xxx_restore_poke_sub_4_8090314
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x18
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x9
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	movs r2, 0x20
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x14
	adds r0, r4, 0
	movs r2, 0x50
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x20
	adds r0, r4, 0
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x21
	adds r0, r4, 0
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x22
	adds r0, r4, 0
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x24
	adds r0, r4, 0
	movs r2, 0x20
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x28
	adds r0, r4, 0
	movs r2, 0x20
	bl RestoreIntegerBits
	adds r1, r5, 0
	adds r1, 0x2C
	adds r0, r4, 0
	movs r2, 0x8
	bl RestoreIntegerBits
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl RestoreIntegerBits
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x2D
	strb r0, [r1]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8095774

	thumb_func_start sub_8095824
sub_8095824:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0xFF
	mov r0, sp
	strb r1, [r0]
	mov r6, sp
	adds r6, 0x1
	movs r0, 0
	strb r0, [r6]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x4
	bl SaveIntegerBits
	adds r1, r4, 0x4
	adds r0, r5, 0
	bl xxx_save_poke_sub_4_80902F4
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x18
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x9
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x10
	adds r0, r5, 0
	movs r2, 0x20
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0x50
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r5, 0
	movs r2, 0x8
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x21
	adds r0, r5, 0
	movs r2, 0x8
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x22
	adds r0, r5, 0
	movs r2, 0x8
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x24
	adds r0, r5, 0
	movs r2, 0x20
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x28
	adds r0, r5, 0
	movs r2, 0x20
	bl SaveIntegerBits
	adds r1, r4, 0
	adds r1, 0x2C
	adds r0, r5, 0
	movs r2, 0x8
	bl SaveIntegerBits
	adds r0, r4, 0
	adds r0, 0x2D
	ldrb r0, [r0]
	mov r1, sp
	cmp r0, 0
	bne _080958D2
	adds r1, r6, 0
_080958D2:
	adds r0, r5, 0
	movs r2, 0x1
	bl SaveIntegerBits
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8095824

	thumb_func_start sub_80958E4
sub_80958E4:
	str r1, [r0]
	bx lr
	thumb_func_end sub_80958E4


        .align 2,0
