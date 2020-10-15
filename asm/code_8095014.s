	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8095118
sub_8095118:
	push {r4,lr}
	ldr r4, _0809517C
	ldr r0, [r4]
	movs r2, 0xC0
	lsls r2, 3
	movs r1, 0
	bl MemoryFill8
	ldr r0, _08095180
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	movs r2, 0
	movs r1, 0
	movs r3, 0x1F
_0809513A:
	ldr r0, [r4]
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x22
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x2D
	strb r2, [r0]
	adds r1, 0x30
	subs r3, 0x1
	cmp r3, 0
	bge _0809513A
	ldr r2, _08095184
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1]
	movs r3, 0
	movs r4, 0x1
	negs r4, r4
_08095166:
	ldr r0, [r2]
	lsls r1, r3, 2
	adds r0, 0x4
	adds r0, r1
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1F
	ble _08095166
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809517C: .4byte gUnknown_203B480
_08095180: .4byte gUnknown_203B484
_08095184: .4byte gUnknown_203B48C
	thumb_func_end sub_8095118

	thumb_func_start nullsub_206
nullsub_206:
	bx lr
	thumb_func_end nullsub_206

	thumb_func_start nullsub_207
nullsub_207:
	bx lr
	thumb_func_end nullsub_207

	thumb_func_start sub_8095190
sub_8095190:
	push {lr}
	movs r2, 0x2
	ldr r0, _080951A8
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x60
_0809519C:
	ldrb r0, [r1]
	cmp r0, 0
	bne _080951AC
	adds r0, r2, 0
	b _080951B8
	.align 2, 0
_080951A8: .4byte gUnknown_203B480
_080951AC:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _0809519C
	movs r0, 0x1
	negs r0, r0
_080951B8:
	pop {r1}
	bx r1
	thumb_func_end sub_8095190

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
	bl sub_80922F4
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
	bl sub_809485C
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
	bl sub_8094924
	ldr r5, [r4]
	adds r4, r5, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x58
	bl memset
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_8094924
	adds r1, r5, 0x6
	mov r0, sp
	movs r2, 0x1
	bl sub_8094924
	adds r1, r5, 0x7
	mov r0, sp
	movs r2, 0x7
	bl sub_8094924
	adds r4, 0x4
	mov r0, sp
	adds r1, r4, 0
	bl sub_8090314
	adds r1, r5, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x10
	mov r0, sp
	bl sub_808F410
	adds r1, r5, 0
	adds r1, 0x14
	mov r0, sp
	bl sub_808F410
	adds r1, r5, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1A
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1C
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1D
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1E
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1F
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x20
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x24
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x28
	mov r0, sp
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x2C
	mov r0, sp
	bl sub_8091DC0
	adds r1, r5, 0
	adds r1, 0x30
	mov r0, sp
	bl sub_8094128
	adds r1, r5, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x50
	bl sub_8094924
	ldr r4, _08095620
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
	adds r6, r4, 0
	movs r5, 0x4
	movs r4, 0x1F
_080955F4:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
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
	bl sub_809486C
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
	bl sub_809488C
	ldr r5, [r4]
	adds r4, r5, 0x4
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_809488C
	adds r1, r5, 0x6
	mov r0, sp
	movs r2, 0x1
	bl sub_809488C
	adds r1, r5, 0x7
	mov r0, sp
	movs r2, 0x7
	bl sub_809488C
	adds r4, 0x4
	mov r0, sp
	adds r1, r4, 0
	bl sub_80902F4
	adds r1, r5, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x9
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x10
	mov r0, sp
	bl sub_808F41C
	adds r1, r5, 0
	adds r1, 0x14
	mov r0, sp
	bl sub_808F41C
	adds r1, r5, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1A
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1C
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1D
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1E
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1F
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x20
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x24
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x28
	mov r0, sp
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x2C
	mov r0, sp
	bl sub_8091DE0
	adds r1, r5, 0
	adds r1, 0x30
	mov r0, sp
	bl sub_8094108
	adds r1, r5, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x50
	bl sub_809488C
	ldr r4, _08095770
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
	adds r6, r4, 0
	movs r5, 0x4
	movs r4, 0x1F
_08095742:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
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
	bl sub_8094924
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl sub_8090314
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	movs r2, 0x20
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x14
	adds r0, r4, 0
	movs r2, 0x50
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x20
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x21
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x22
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x24
	adds r0, r4, 0
	movs r2, 0x20
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x28
	adds r0, r4, 0
	movs r2, 0x20
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x2C
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
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
	bl sub_809488C
	adds r1, r4, 0x4
	adds r0, r5, 0
	bl sub_80902F4
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x18
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x10
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0x50
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x21
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x22
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x24
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x28
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x2C
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
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
	bl sub_809488C
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

	thumb_func_start sub_80958E8
sub_80958E8:
	ldr r1, _080958F0
	ldr r0, _080958F4
	str r0, [r1]
	bx lr
	.align 2, 0
_080958F0: .4byte gUnknown_203B490
_080958F4: .4byte gUnknown_2039448
	thumb_func_end sub_80958E8

	thumb_func_start sub_80958F8
sub_80958F8:
	ldr r0, _080958FC
	bx lr
	.align 2, 0
_080958FC: .4byte gUnknown_2039448
	thumb_func_end sub_80958F8

	thumb_func_start sub_8095900
sub_8095900:
	push {r4-r7,lr}
	movs r4, 0
_08095904:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096040
	adds r4, 0x1
	cmp r4, 0x3
	ble _08095904
	movs r4, 0
_08095914:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80965B8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08095914
	movs r4, 0
_08095924:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096C3C
	adds r4, 0x1
	cmp r4, 0x7
	ble _08095924
	movs r4, 0
	ldr r3, _080959B8
	movs r2, 0xBC
	lsls r2, 2
	movs r1, 0
_0809593C:
	ldr r0, [r3]
	adds r0, r2
	adds r0, r4
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x37
	ble _0809593C
	ldr r4, _080959B8
	ldr r0, [r4]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	movs r7, 0xC8
	lsls r7, 1
	adds r0, r7
	movs r1, 0x28
	bl MemoryClear8
	ldr r0, [r4]
	movs r1, 0xDC
	lsls r1, 1
	adds r0, r1
	movs r1, 0x78
	bl MemoryClear8
	adds r3, r4, 0
	movs r5, 0
	movs r2, 0
	movs r6, 0x8C
	lsls r6, 2
	movs r4, 0xF
_08095980:
	ldr r0, [r3]
	adds r0, r2
	adds r0, r6
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, r2
	ldr r7, _080959BC
	adds r0, r7
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, [r3]
	adds r7, 0x3
	adds r0, r1, r7
	adds r0, r2
	str r5, [r0]
	adds r7, 0x4
	adds r0, r1, r7
	adds r0, r2
	str r5, [r0]
	adds r2, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _08095980
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080959B8: .4byte gUnknown_203B490
_080959BC: .4byte 0x00000231
	thumb_func_end sub_8095900

	thumb_func_start sub_80959C0
sub_80959C0:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x5
	bne _080959D6
	adds r0, r1, 0
	bl sub_80959DC
	lsls r0, 24
	lsrs r0, 24
	b _080959D8
_080959D6:
	movs r0, 0
_080959D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80959C0

	thumb_func_start sub_80959DC
sub_80959DC:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrb r0, [r5, 0x1]
	cmp r0, 0x4
	bls _080959E8
	b _08095B16
_080959E8:
	cmp r0, 0x4
	bne _080959F8
	ldrb r0, [r5, 0x4]
	bl GetMaxItemCount
	cmp r0, 0
	bne _080959F8
	b _08095B16
_080959F8:
	ldrb r0, [r5, 0x2]
	cmp r0, 0x9
	bls _08095A00
	b _08095B16
_08095A00:
	ldrb r0, [r5, 0x4]
	bl sub_809095C
	lsls r0, 24
	cmp r0, 0
	beq _08095A0E
	b _08095B16
_08095A0E:
	ldrb r4, [r5, 0x5]
	ldrb r0, [r5, 0x4]
	bl sub_8090298
	cmp r4, r0
	bge _08095B16
	adds r4, r5, 0x4
	adds r0, r4, 0
	bl sub_809017C
	lsls r0, 24
	adds r6, r4, 0
	cmp r0, 0
	bne _08095B16
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08095B16
	ldr r4, _08095B1C
	cmp r0, r4
	bgt _08095B16
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	bl sub_808E770
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _08095B16
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	bl sub_803C0DC
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	cmp r0, r4
	bgt _08095B16
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	bl sub_808E770
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _08095B16
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	bl sub_803C0DC
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
	ldrb r0, [r5, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08095A9C
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _08095B16
_08095A9C:
	ldrb r0, [r5, 0x10]
	bl sub_8092040
	lsls r0, 24
	cmp r0, 0
	bne _08095B16
	ldrb r0, [r5, 0x10]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08095B16
	ldrb r0, [r5, 0x10]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3
	bne _08095AD4
	ldrb r0, [r5, 0x4]
	ldrb r1, [r5, 0x10]
	bl sub_8091E60
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
_08095AD4:
	ldrb r0, [r5, 0x11]
	cmp r0, 0x4
	beq _08095B16
	cmp r0, 0xA
	beq _08095B16
	cmp r0, 0xA
	bhi _08095B16
	ldrb r0, [r5, 0x12]
	bl sub_8092040
	lsls r0, 24
	cmp r0, 0
	bne _08095B16
	ldrb r0, [r5, 0x13]
	cmp r0, 0x39
	bhi _08095B16
	ldrb r0, [r5, 0x11]
	cmp r0, 0x9
	bne _08095B20
	ldrb r0, [r5, 0x13]
	bl sub_8092534
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08095B16
	ldrb r1, [r5, 0x1]
	adds r0, r6, 0
	bl sub_803C1D0
	lsls r0, 24
	cmp r0, 0
	bne _08095B20
_08095B16:
	movs r0, 0
	b _08095B22
	.align 2, 0
_08095B1C: .4byte 0x000001a7
_08095B20:
	movs r0, 0x1
_08095B22:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80959DC

	thumb_func_start sub_8095B28
sub_8095B28:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _08095B44
	add sp, r4
	adds r4, r0, 0
	bl sub_8095CE0
	lsls r0, 24
	cmp r0, 0
	bne _08095B48
	movs r0, 0
	b _08095CCC
	.align 2, 0
_08095B44: .4byte 0xfffffcb0
_08095B48:
	movs r0, 0x5
	strb r0, [r4]
	movs r0, 0x8
	bl RandomCapped
	ldr r1, _08095BC8
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _08095B6C
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095B6C
	strb r0, [r4, 0x1]
_08095B6C:
	movs r0, 0
	strb r0, [r4, 0x2]
	bl Random
	ldr r1, _08095BCC
	ands r1, r0
	str r1, [r4, 0x8]
	movs r7, 0
	movs r5, 0x1
	adds r0, r4, 0x4
	mov r8, r0
	movs r1, 0x12
	adds r1, r4
	mov r9, r1
	mov r6, sp
_08095B8A:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _08095B9E
	strh r5, [r6]
	adds r6, 0x2
	adds r7, 0x1
_08095B9E:
	adds r5, 0x1
	ldr r0, _08095BD0
	cmp r5, r0
	ble _08095B8A
	cmp r7, 0
	beq _08095BD4
	adds r0, r7, 0
	bl RandomCapped
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0xC]
	adds r0, r7, 0
	bl RandomCapped
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	b _08095BDC
	.align 2, 0
_08095BC8: .4byte gUnknown_8109984
_08095BCC: .4byte 0x00ffffff
_08095BD0: .4byte 0x000001a7
_08095BD4:
	movs r0, 0x10
	strh r0, [r4, 0xC]
	movs r0, 0x91
	lsls r0, 1
_08095BDC:
	strh r0, [r4, 0xE]
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08095BEE
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095BEE:
	ldrb r0, [r4, 0x4]
	bl sub_8095F28
	strb r0, [r4, 0x10]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095C10
	strb r0, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x10
	mov r0, r8
	movs r1, 0
	bl sub_803C37C
_08095C10:
	ldrb r0, [r4, 0x4]
	bl GetMaxItemCount
	adds r1, r0, 0
	cmp r1, 0
	bne _08095C28
	ldrb r0, [r4, 0x1]
	cmp r0, 0x4
	bne _08095C28
	strb r1, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095C28:
	ldrb r1, [r4, 0x1]
	mov r0, r8
	mov r2, r9
	bl sub_803C37C
	ldrb r0, [r4, 0x10]
	ldrb r1, [r4, 0x12]
	cmp r0, r1
	beq _08095C28
	movs r0, 0
	strb r0, [r4, 0x13]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	beq _08095C90
	cmp r0, 0x2
	bgt _08095C4E
	cmp r0, 0x1
	beq _08095C6C
	b _08095CCA
_08095C4E:
	cmp r0, 0x4
	bgt _08095CCA
	bl Random
	adds r1, r0, 0
	movs r0, 0xE0
	lsls r0, 3
	ands r1, r0
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _08095CC4
	cmp r1, r0
	bgt _08095CB4
	b _08095CAA
_08095C6C:
	bl Random
	adds r1, r0, 0
	movs r0, 0x70
	ands r1, r0
	cmp r1, 0x10
	beq _08095C80
	cmp r1, 0x30
	beq _08095C88
	b _08095CCA
_08095C80:
	adds r0, r4, 0
	bl sub_803C3E0
	b _08095CCA
_08095C88:
	adds r0, r4, 0
	bl sub_803C45C
	b _08095CCA
_08095C90:
	bl Random
	movs r1, 0xC0
	lsls r1, 6
	ands r1, r0
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _08095CCA
	adds r0, r4, 0
	bl sub_803C4F0
	b _08095CCA
_08095CAA:
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _08095CBC
	b _08095CCA
_08095CB4:
	movs r0, 0xC0
	lsls r0, 3
	cmp r1, r0
	bne _08095CCA
_08095CBC:
	adds r0, r4, 0
	bl sub_803C580
	b _08095CCA
_08095CC4:
	adds r0, r4, 0
	bl sub_803C610
_08095CCA:
	movs r0, 0x1
_08095CCC:
	movs r3, 0xD4
	lsls r3, 2
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095B28

	thumb_func_start sub_8095CE0
sub_8095CE0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x60
	str r0, [sp, 0x44]
	mov r0, sp
	bl sub_80A29B0
	str r0, [sp, 0x4C]
	cmp r0, 0
	bne _08095D0C
	mov r0, sp
	add r1, sp, 0x4C
	ldrb r1, [r1]
	strb r1, [r0]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r2, 0x2
	str r2, [sp, 0x4C]
_08095D0C:
	ldr r0, [sp, 0x4C]
	bl RandomCapped
	mov r9, r0
	str r0, [sp, 0x48]
	mov r1, sp
	adds r1, 0x40
	str r1, [sp, 0x5C]
_08095D1C:
	mov r0, sp
	add r0, r9
	ldrb r7, [r0]
	adds r0, r7, 0
	bl sub_8090298
	str r0, [sp, 0x58]
	lsrs r0, 31
	ldr r2, [sp, 0x58]
	adds r0, r2, r0
	asrs r0, 1
	str r0, [sp, 0x54]
	adds r1, r2, 0
	bl RandomRange
	adds r4, r0, 0
	str r4, [sp, 0x50]
_08095D3E:
	movs r0, 0x1
	mov r8, r0
	ldr r1, _08095DF4
	ldr r0, [sp, 0x40]
	ands r0, r1
	orrs r0, r7
	lsls r2, r4, 24
	lsrs r2, 16
	ldr r1, _08095DF8
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x40]
	ldr r0, [sp, 0x5C]
	bl sub_809017C
	lsls r0, 24
	cmp r0, 0
	beq _08095D66
	movs r1, 0
	mov r8, r1
_08095D66:
	ldr r2, _08095DFC
	mov r10, r2
	movs r6, 0
	movs r5, 0x3
_08095D6E:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095D88
	movs r2, 0
	mov r8, r2
_08095D88:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095D6E
	ldr r0, _08095DFC
	mov r10, r0
	movs r6, 0x50
	movs r5, 0x7
_08095D98:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095DB2
	movs r2, 0
	mov r8, r2
_08095DB2:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095D98
	ldr r0, _08095DFC
	mov r10, r0
	movs r6, 0xF0
	movs r5, 0x7
_08095DC2:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095DDC
	movs r2, 0
	mov r8, r2
_08095DDC:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095DC2
	mov r0, r8
	cmp r0, 0
	beq _08095E00
	ldr r1, [sp, 0x44]
	strb r7, [r1, 0x4]
	strb r4, [r1, 0x5]
	movs r0, 0x1
	b _08095E28
	.align 2, 0
_08095DF4: .4byte 0xffffff00
_08095DF8: .4byte 0xffff00ff
_08095DFC: .4byte gUnknown_203B490
_08095E00:
	adds r4, 0x1
	ldr r2, [sp, 0x58]
	cmp r4, r2
	blt _08095E0A
	ldr r4, [sp, 0x54]
_08095E0A:
	ldr r0, [sp, 0x50]
	cmp r4, r0
	bne _08095D3E
	movs r1, 0x1
	add r9, r1
	ldr r2, [sp, 0x4C]
	cmp r9, r2
	bne _08095E1E
	movs r0, 0
	mov r9, r0
_08095E1E:
	ldr r1, [sp, 0x48]
	cmp r9, r1
	beq _08095E26
	b _08095D1C
_08095E26:
	movs r0, 0
_08095E28:
	add sp, 0x60
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095CE0

	thumb_func_start sub_8095E38
sub_8095E38:
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4]
	cmp r0, 0
	beq _08095E6E
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _08095E5E
	cmp r3, 0x1
	bne _08095E5E
	ldrb r0, [r4, 0x4]
	cmp r0, r1
	bne _08095E6E
	movs r0, 0x1
	b _08095E70
_08095E5E:
	ldrb r0, [r4, 0x4]
	cmp r0, r1
	bne _08095E6E
	ldrb r0, [r4, 0x5]
	cmp r0, r2
	bne _08095E6E
	movs r0, 0x1
	b _08095E70
_08095E6E:
	movs r0, 0
_08095E70:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E38

	thumb_func_start sub_8095E78
sub_8095E78:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x3C
	movs r6, 0
	movs r5, 0x1
_08095E84:
	ldr r0, _08095F04
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	adds r1, r5, 0x1
	mov r8, r1
	cmp r0, 0
	bne _08095EF6
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_8092534
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08095EF6
	movs r4, 0
	ldr r0, _08095F08
	ldr r1, [r0]
	movs r3, 0x3
_08095EAC:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08095EBA
	ldrb r0, [r1, 0x11]
	cmp r0, 0x9
	bne _08095EBA
	movs r4, 0x1
_08095EBA:
	adds r1, 0x14
	subs r3, 0x1
	cmp r3, 0
	bge _08095EAC
	ldr r0, _08095F08
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xF0
	adds r1, r0, 0
	movs r3, 0x7
_08095ECE:
	ldrb r0, [r2]
	cmp r0, 0
	beq _08095EE0
	ldr r7, _08095F0C
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, 0x9
	bne _08095EE0
	movs r4, 0x1
_08095EE0:
	adds r2, 0x14
	adds r1, 0x14
	subs r3, 0x1
	cmp r3, 0
	bge _08095ECE
	cmp r4, 0
	bne _08095EF6
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	adds r6, 0x1
_08095EF6:
	mov r5, r8
	cmp r5, 0x39
	ble _08095E84
	cmp r6, 0
	bne _08095F10
	movs r0, 0
	b _08095F1A
	.align 2, 0
_08095F04: .4byte gUnknown_203B468
_08095F08: .4byte gUnknown_203B490
_08095F0C: .4byte 0x00000101
_08095F10:
	adds r0, r6, 0
	bl RandomCapped
	add r0, sp
	ldrb r0, [r0]
_08095F1A:
	add sp, 0x3C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E78

	thumb_func_start sub_8095F28
sub_8095F28:
	push {r4-r7,lr}
	sub sp, 0xF0
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	movs r5, 0x1
_08095F34:
	lsls r4, r5, 24
	cmp r7, 0x63
	beq _08095F48
	lsrs r1, r4, 24
	adds r0, r7, 0
	bl sub_8091E60
	lsls r0, 24
	cmp r0, 0
	beq _08095F6A
_08095F48:
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08095F6A
	adds r0, r4, 0
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _08095F6A
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	adds r6, 0x1
_08095F6A:
	adds r5, 0x1
	cmp r5, 0xEF
	ble _08095F34
	cmp r6, 0
	beq _08095F80
	adds r0, r6, 0
	bl RandomCapped
	add r0, sp
	ldrb r0, [r0]
	b _08095F82
_08095F80:
	movs r0, 0
_08095F82:
	add sp, 0xF0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F28

	thumb_func_start sub_8095F8C
sub_8095F8C:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_08095F92:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096000
	lsls r0, 24
	cmp r0, 0
	bne _08095FA2
	adds r5, 0x1
_08095FA2:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08095F92
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F8C

	thumb_func_start sub_8095FB0
sub_8095FB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _08095FD4
	movs r2, 0
_08095FBA:
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _08095FD8
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	b _08095FE2
	.align 2, 0
_08095FD4: .4byte gUnknown_203B490
_08095FD8:
	adds r2, 0x14
	adds r3, 0x1
	cmp r3, 0x3
	ble _08095FBA
	movs r0, 0x1
_08095FE2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095FB0

	thumb_func_start sub_8095FE8
sub_8095FE8:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _08095FFC
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_08095FFC: .4byte gUnknown_203B490
	thumb_func_end sub_8095FE8

	thumb_func_start sub_8096000
sub_8096000:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0809601C
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	ldrb r0, [r2]
	cmp r0, 0
	beq _08096020
	movs r0, 0
	b _08096022
	.align 2, 0
_0809601C: .4byte gUnknown_203B490
_08096020:
	movs r0, 0x1
_08096022:
	pop {r1}
	bx r1
	thumb_func_end sub_8096000

	thumb_func_start sub_8096028
sub_8096028:
	push {r4,lr}
	movs r4, 0
_0809602C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096040
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809602C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8096028

	thumb_func_start sub_8096040
sub_8096040:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, _08096074
	ldr r1, [r3]
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	movs r4, 0
	strb r4, [r1]
	ldr r0, [r3]
	adds r0, r2
	movs r1, 0x63
	strb r1, [r0, 0x4]
	ldr r0, [r3]
	adds r0, r2
	strb r4, [r0, 0x5]
	ldr r0, [r3]
	adds r0, r2
	movs r1, 0x5
	strb r1, [r0, 0x11]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096074: .4byte gUnknown_203B490
	thumb_func_end sub_8096040

	thumb_func_start sub_8096078
sub_8096078:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _08096090
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _080960B6
	.align 2, 0
_08096090: .4byte gUnknown_203B490
_08096094:
	cmp r2, r3
	ble _080960AA
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_080960AA:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_080960B6:
	cmp r2, 0x3
	bgt _080960E2
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080960E2
	ldr r6, _08096110
	mov r1, r9
_080960CA:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080960E2
	ldr r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080960CA
_080960E2:
	cmp r2, 0x4
	bne _08096094
	cmp r3, 0x3
	bgt _08096102
	ldr r4, _08096110
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_080960F4:
	ldr r0, [r4]
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x3
	ble _080960F4
_08096102:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096110: .4byte gUnknown_203B490
	thumb_func_end sub_8096078

	thumb_func_start sub_8096114
sub_8096114:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r1, 0
_08096122:
	adds r0, r1, 0x1
	mov r10, r0
	mov r8, r10
	cmp r0, 0x3
	bgt _08096198
	ldr r2, _080961B0
	mov r9, r2
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r12, r0
	mov r3, r10
	lsls r0, r3, 2
	add r0, r10
	lsls r4, r0, 2
_08096140:
	mov r5, r9
	ldr r1, [r5]
	adds r3, r1, r4
	ldrb r0, [r3]
	cmp r0, 0
	beq _0809618C
	mov r6, r12
	adds r2, r1, r6
	ldrb r1, [r2, 0x4]
	ldrb r0, [r3, 0x4]
	cmp r1, r0
	bhi _08096164
	cmp r1, r0
	bne _0809618C
	ldrb r0, [r2, 0x5]
	ldrb r7, [r3, 0x5]
	cmp r0, r7
	bls _0809618C
_08096164:
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5,r6}
	stm r1!, {r5,r6}
	adds r1, r2, 0
	adds r0, r3, 0
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5,r6}
	stm r1!, {r5,r6}
	mov r7, r9
	ldr r1, [r7]
	adds r1, r4
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_0809618C:
	adds r4, 0x14
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x3
	ble _08096140
_08096198:
	mov r1, r10
	cmp r1, 0x2
	ble _08096122
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080961B0: .4byte gUnknown_203B490
	thumb_func_end sub_8096114

	thumb_func_start sub_80961B4
sub_80961B4:
	push {lr}
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _080961CE
	ldr r0, _080961D4
	ldr r0, [r0]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080961CE:
	pop {r0}
	bx r0
	.align 2, 0
_080961D4: .4byte gUnknown_203B490
	thumb_func_end sub_80961B4

	thumb_func_start sub_80961D8
sub_80961D8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	bl sub_8095F8C
	adds r6, r0, 0
	movs r1, 0x4
	bl RandomRange
	mov r8, r0
	cmp r6, 0x3
	bgt _08096202
	ldr r4, _08096208
	ldr r0, [r4]
	movs r2, 0xCA
	lsls r2, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _0809620C
_08096202:
	movs r0, 0
	b _080963A8
	.align 2, 0
_08096208: .4byte gUnknown_203B490
_0809620C:
	strb r7, [r1]
	movs r5, 0x38
	movs r0, 0xA
	movs r1, 0x31
	movs r2, 0x1
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _0809623A
	ldr r0, [r4]
	ldr r1, _08096328
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809623A
	movs r0, 0x35
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809623A
	movs r5, 0x35
_0809623A:
	movs r0, 0xF
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809629C
	ldr r0, _0809632C
	ldr r0, [r0]
	movs r2, 0xC9
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096264
	movs r0, 0x34
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _08096264
	movs r5, 0x34
_08096264:
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r1, _08096330
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096280
	movs r0, 0x33
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _08096280
	movs r5, 0x33
_08096280:
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r2, _08096334
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809629C
	movs r0, 0x32
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809629C
	movs r5, 0x32
_0809629C:
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _080962C4
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r1, _08096338
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080962C4
	movs r0, 0x36
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080962C4
	movs r5, 0x36
_080962C4:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080962EC
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r2, _0809633C
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080962EC
	movs r0, 0x37
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080962EC
	movs r5, 0x37
_080962EC:
	cmp r5, 0x38
	bne _08096310
	cmp r6, r8
	bgt _08096392
	bl sub_8096E2C
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0xE
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0809630C
	cmp r5, 0x2
	bhi _0809638E
_0809630C:
	cmp r5, 0x31
	bhi _0809638E
_08096310:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8095FE8
	adds r4, r0, 0
	movs r0, 0x1
	strb r0, [r4]
	movs r0, 0x62
	strb r0, [r4, 0x4]
	strb r5, [r4, 0x5]
	b _0809638A
	.align 2, 0
_08096328: .4byte 0x00000325
_0809632C: .4byte gUnknown_203B490
_08096330: .4byte 0x00000323
_08096334: .4byte 0x00000322
_08096338: .4byte 0x00000326
_0809633C: .4byte 0x00000327
_08096340:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8095FE8
	adds r4, r0, 0
	bl sub_8095B28
	lsls r0, 24
	cmp r0, 0
	beq _08096392
	bl sub_8095E78
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0x4
	ldrb r1, [r4, 0x1]
	bl sub_803C1D0
	lsls r0, 24
	cmp r0, 0
	bne _0809636C
	movs r5, 0
_0809636C:
	movs r0, 0x5
	movs r1, 0xA
	bl RandomRange
	strb r0, [r4, 0x11]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bne _0809638A
	cmp r5, 0
	bne _08096388
	movs r0, 0x5
	strb r0, [r4, 0x11]
	b _0809638A
_08096388:
	strb r5, [r4, 0x13]
_0809638A:
	movs r7, 0x1
	adds r6, 0x1
_0809638E:
	cmp r6, r8
	ble _08096340
_08096392:
	bl sub_80963B4
	lsls r0, 24
	cmp r0, 0
	beq _0809639E
	movs r7, 0x1
_0809639E:
	bl sub_8096078
	bl sub_8096114
	adds r0, r7, 0
_080963A8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80961D8

	thumb_func_start sub_80963B4
sub_80963B4:
	push {r4-r6,lr}
	movs r6, 0
	bl sub_8096E2C
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8095F8C
	adds r4, r0, 0
	cmp r4, 0x3
	ble _080963CE
	movs r0, 0
	b _080963F4
_080963CE:
	movs r0, 0xE
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080963F2
	cmp r5, 0x31
	bhi _080963F2
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8095FE8
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x62
	strb r1, [r0, 0x4]
	strb r5, [r0, 0x5]
	movs r6, 0x1
_080963F2:
	adds r0, r6, 0
_080963F4:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80963B4

	thumb_func_start sub_80963FC
sub_80963FC:
	push {r4-r6,lr}
	movs r6, 0
_08096400:
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8095FE8
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _08096418
	adds r0, r4, 0
	bl sub_8096040
_08096418:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08096400
	bl sub_8096078
	bl sub_8095F8C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095FE8
	adds r5, r0, 0
	movs r0, 0
	movs r4, 0x5
	strb r4, [r5]
	strb r0, [r5, 0x1]
	strb r0, [r5, 0x2]
	movs r0, 0x2
	strb r0, [r5, 0x4]
	movs r0, 0x3
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096484
	ands r1, r0
	str r1, [r5, 0x8]
	movs r0, 0x10
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	ldrb r0, [r5, 0x4]
	bl sub_8095F28
	strb r0, [r5, 0x10]
	strb r4, [r5, 0x11]
_0809645C:
	ldrb r1, [r5, 0x1]
	adds r0, r5, 0x4
	adds r2, r5, 0
	adds r2, 0x12
	bl sub_803C37C
	ldrb r0, [r5, 0x10]
	ldrb r1, [r5, 0x12]
	cmp r0, r1
	beq _0809645C
	movs r0, 0
	strb r0, [r5, 0x13]
	bl sub_8096078
	bl sub_8096114
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096484: .4byte 0x00ffffff
	thumb_func_end sub_80963FC

	thumb_func_start sub_8096488
sub_8096488:
	push {r4,lr}
	movs r4, 0
_0809648C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096040
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809648C
	movs r0, 0
	bl sub_8095FE8
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x62
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8096488

	thumb_func_start sub_80964B4
sub_80964B4:
	push {lr}
	ldr r0, _080964D4
	ldr r0, [r0]
	ldr r1, _080964D8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080964DC
	movs r0, 0x35
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080964DC
	movs r0, 0
	b _080964DE
	.align 2, 0
_080964D4: .4byte gUnknown_203B490
_080964D8: .4byte 0x00000325
_080964DC:
	movs r0, 0x1
_080964DE:
	pop {r1}
	bx r1
	thumb_func_end sub_80964B4

	thumb_func_start sub_80964E4
sub_80964E4:
	push {lr}
	ldr r0, _08096504
	ldr r0, [r0]
	ldr r1, _08096508
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809650C
	movs r0, 0x36
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809650C
	movs r0, 0
	b _0809650E
	.align 2, 0
_08096504: .4byte gUnknown_203B490
_08096508: .4byte 0x00000326
_0809650C:
	movs r0, 0x1
_0809650E:
	pop {r1}
	bx r1
	thumb_func_end sub_80964E4

	thumb_func_start sub_8096514
sub_8096514:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0809651A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_809658C
	lsls r0, 24
	cmp r0, 0
	bne _0809652A
	adds r5, 0x1
_0809652A:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0809651A
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096514

	thumb_func_start sub_8096538
sub_8096538:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _08096560
	movs r2, 0
_08096542:
	ldr r0, [r5]
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0x50
	ldrb r0, [r1]
	cmp r0, 0
	bne _08096564
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	b _0809656E
	.align 2, 0
_08096560: .4byte gUnknown_203B490
_08096564:
	adds r2, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096542
	movs r0, 0x1
_0809656E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096538

	thumb_func_start sub_8096574
sub_8096574:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _08096588
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x50
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_08096588: .4byte gUnknown_203B490
	thumb_func_end sub_8096574

	thumb_func_start sub_809658C
sub_809658C:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080965AC
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	adds r2, 0x50
	ldrb r0, [r2]
	cmp r0, 0
	beq _080965B0
	movs r0, 0
	b _080965B2
	.align 2, 0
_080965AC: .4byte gUnknown_203B490
_080965B0:
	movs r0, 0x1
_080965B2:
	pop {r1}
	bx r1
	thumb_func_end sub_809658C

	thumb_func_start sub_80965B8
sub_80965B8:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, _080965F0
	ldr r1, [r4]
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r1, 0x50
	movs r3, 0
	strb r3, [r1]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x54
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x55
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x61
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080965F0: .4byte gUnknown_203B490
	thumb_func_end sub_80965B8

	thumb_func_start sub_80965F4
sub_80965F4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _0809660C
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _08096636
	.align 2, 0
_0809660C: .4byte gUnknown_203B490
_08096610:
	cmp r2, r3
	ble _0809662A
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	adds r1, 0x50
	adds r0, 0x50
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_0809662A:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_08096636:
	cmp r2, 0x7
	bgt _08096666
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096666
	ldr r6, _08096694
	mov r1, r9
_0809664C:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08096666
	ldr r0, [r6]
	adds r0, r1
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809664C
_08096666:
	cmp r2, 0x8
	bne _08096610
	cmp r3, 0x7
	bgt _08096688
	ldr r4, _08096694
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_08096678:
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x50
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096678
_08096688:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096694: .4byte gUnknown_203B490
	thumb_func_end sub_80965F4

	thumb_func_start sub_8096698
sub_8096698:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r1, 0
_080966A6:
	adds r6, r1, 0x1
	mov r10, r6
	cmp r6, 0x7
	bgt _08096730
	ldr r0, _08096748
	mov r8, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r9, r0
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 2
_080966C0:
	mov r2, r8
	ldr r1, [r2]
	adds r3, r1, r4
	adds r5, r3, 0
	adds r5, 0x50
	ldrb r0, [r5]
	cmp r0, 0
	beq _08096724
	add r1, r9
	mov r12, r1
	mov r0, r12
	adds r0, 0x54
	adds r1, r3, 0
	adds r1, 0x54
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	bhi _080966F6
	cmp r2, r0
	bne _08096724
	mov r0, r12
	adds r0, 0x55
	adds r1, 0x1
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _08096724
_080966F6:
	mov r1, sp
	mov r0, r12
	adds r0, 0x50
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r3,r7}
	stm r1!, {r3,r7}
	mov r1, r12
	adds r1, 0x50
	adds r0, r5, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r7}
	stm r1!, {r2,r7}
	mov r3, r8
	ldr r1, [r3]
	adds r1, r4
	adds r1, 0x50
	mov r0, sp
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
	ldm r0!, {r3,r5}
	stm r1!, {r3,r5}
_08096724:
	adds r4, 0x14
	movs r7, 0x1
	add r10, r7
	mov r0, r10
	cmp r0, 0x7
	ble _080966C0
_08096730:
	adds r1, r6, 0
	cmp r1, 0x6
	ble _080966A6
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096748: .4byte gUnknown_203B490
	thumb_func_end sub_8096698

	thumb_func_start sub_809674C
sub_809674C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x4
	movs r1, 0x8
	bl RandomRange
	mov r8, r0
	ldr r3, _08096864
	movs r2, 0
	movs r1, 0
	movs r7, 0x7
_08096764:
	ldr r0, [r3]
	adds r0, r1
	adds r0, 0x50
	strb r2, [r0]
	adds r1, 0x14
	subs r7, 0x1
	cmp r7, 0
	bge _08096764
	movs r7, 0
	movs r0, 0xE
	bl sub_8097318
	lsls r0, 24
	cmp r0, 0
	beq _080967C0
	movs r0, 0
	bl sub_8096574
	adds r5, r0, 0
	movs r4, 0x2
	strb r4, [r5]
	movs r0, 0x6
	strb r0, [r5, 0x1]
	movs r0, 0x1
	strb r0, [r5, 0x2]
	movs r0, 0x2A
	strb r0, [r5, 0x4]
	movs r0, 0xA
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096868
	ands r1, r0
	str r1, [r5, 0x8]
	movs r1, 0
	movs r0, 0xC2
	lsls r0, 1
	strh r0, [r5, 0xC]
	movs r0, 0x38
	strh r0, [r5, 0xE]
	strb r1, [r5, 0x10]
	strb r4, [r5, 0x11]
	movs r0, 0x3A
	strb r0, [r5, 0x12]
	strb r1, [r5, 0x13]
	movs r7, 0x1
_080967C0:
	movs r0, 0xF
	bl sub_8097318
	lsls r0, 24
	cmp r0, 0
	beq _0809680A
	lsls r0, r7, 24
	lsrs r0, 24
	bl sub_8096574
	adds r5, r0, 0
	movs r0, 0x3
	strb r0, [r5]
	movs r0, 0x6
	strb r0, [r5, 0x1]
	movs r4, 0x2
	strb r4, [r5, 0x2]
	movs r0, 0x35
	strb r0, [r5, 0x4]
	movs r0, 0xF
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096868
	ands r1, r0
	str r1, [r5, 0x8]
	movs r1, 0
	movs r0, 0x82
	lsls r0, 1
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	strb r1, [r5, 0x10]
	strb r4, [r5, 0x11]
	movs r0, 0x3A
	strb r0, [r5, 0x12]
	strb r1, [r5, 0x13]
	adds r7, 0x1
_0809680A:
	movs r0, 0x1C
	bl sub_8097318
	lsls r0, 24
	cmp r0, 0
	beq _08096854
	lsls r0, r7, 24
	lsrs r0, 24
	bl sub_8096574
	adds r5, r0, 0
	movs r0, 0x4
	strb r0, [r5]
	movs r0, 0x6
	strb r0, [r5, 0x1]
	movs r0, 0x3
	strb r0, [r5, 0x2]
	movs r0, 0x1A
	strb r0, [r5, 0x4]
	movs r0, 0x14
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096868
	ands r1, r0
	str r1, [r5, 0x8]
	movs r1, 0
	ldr r0, _0809686C
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	strb r1, [r5, 0x10]
	movs r0, 0x2
	strb r0, [r5, 0x11]
	movs r0, 0x3A
	strb r0, [r5, 0x12]
	strb r1, [r5, 0x13]
	adds r7, 0x1
_08096854:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 2
	adds r5, r0, 0
	adds r5, 0x50
	adds r4, r0, 0
	b _08096886
	.align 2, 0
_08096864: .4byte gUnknown_203B490
_08096868: .4byte 0x00ffffff
_0809686C: .4byte 0x0000014d
_08096870:
	movs r0, 0
	movs r1, 0x4
	bl RandomRange
	ldr r1, [r6]
	adds r1, r4
	adds r1, 0x61
	strb r0, [r1]
	adds r5, 0x14
	adds r4, 0x14
	adds r7, 0x1
_08096886:
	cmp r7, r8
	bgt _0809689A
	ldr r6, _080968AC
	ldr r0, [r6]
	adds r0, r5
	bl sub_8095B28
	lsls r0, 24
	cmp r0, 0
	bne _08096870
_0809689A:
	bl sub_80965F4
	bl sub_8096698
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080968AC: .4byte gUnknown_203B490
	thumb_func_end sub_809674C

	thumb_func_start sub_80968B0
sub_80968B0:
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r4, 0
	ldr r0, _08096928
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xF0
_080968BE:
	ldrb r0, [r2]
	cmp r0, 0
	beq _0809692C
	ldrb r0, [r3, 0x1]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x2]
	ldrb r5, [r2, 0x2]
	cmp r0, r5
	bne _0809692C
	ldrb r0, [r3, 0x4]
	ldrb r1, [r2, 0x4]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x5]
	ldrb r5, [r2, 0x5]
	cmp r0, r5
	bne _0809692C
	ldr r1, [r3, 0x8]
	ldr r0, [r2, 0x8]
	cmp r1, r0
	bne _0809692C
	movs r0, 0xC
	ldrsh r1, [r3, r0]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _0809692C
	movs r0, 0xE
	ldrsh r1, [r3, r0]
	movs r5, 0xE
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _0809692C
	ldrb r0, [r3, 0x10]
	ldrb r1, [r2, 0x10]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x11]
	ldrb r5, [r2, 0x11]
	cmp r0, r5
	bne _0809692C
	ldrb r0, [r3, 0x12]
	ldrb r1, [r2, 0x12]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x13]
	ldrb r5, [r2, 0x13]
	cmp r0, r5
	bne _0809692C
	movs r0, 0x1
	b _08096936
	.align 2, 0
_08096928: .4byte gUnknown_203B490
_0809692C:
	adds r2, 0x14
	adds r4, 0x1
	cmp r4, 0x7
	ble _080968BE
	movs r0, 0
_08096936:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80968B0

	thumb_func_start sub_809693C
sub_809693C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	ldrb r0, [r4, 0x4]
	mov r9, r0
	ldrb r0, [r4, 0x5]
	mov r8, r0
	movs r7, 0
	adds r0, r4, 0
	bl sub_80959C0
	lsls r0, 24
	cmp r0, 0
	bne _08096962
	b _0809699A
_0809695E:
	movs r0, 0x1
	b _0809699C
_08096962:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _0809696A
	movs r7, 0x1
_0809696A:
	movs r6, 0
	movs r5, 0xF0
	movs r4, 0
_08096970:
	ldr r0, _080969A8
	ldr r1, [r0]
	adds r0, r1, r4
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08096990
	adds r0, r1, r5
	mov r1, r9
	mov r2, r8
	adds r3, r7, 0
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	bne _0809695E
_08096990:
	adds r5, 0x14
	adds r4, 0x14
	adds r6, 0x1
	cmp r6, 0x7
	ble _08096970
_0809699A:
	movs r0, 0
_0809699C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080969A8: .4byte gUnknown_203B490
	thumb_func_end sub_809693C

	thumb_func_start sub_80969AC
sub_80969AC:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_080969B2:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096ACC
	lsls r0, 24
	cmp r0, 0
	bne _080969C2
	adds r5, 0x1
_080969C2:
	adds r4, 0x1
	cmp r4, 0x7
	ble _080969B2
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80969AC

	thumb_func_start sub_80969D0
sub_80969D0:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r4, 0
_080969DA:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r1, r0, 0
	ldrb r0, [r1, 0x4]
	cmp r0, r6
	bne _080969FA
	ldrb r0, [r1]
	cmp r0, 0x6
	beq _080969F8
	cmp r0, 0x8
	beq _080969F8
	cmp r0, 0x9
	bne _080969FA
_080969F8:
	adds r5, 0x1
_080969FA:
	adds r4, 0x1
	cmp r4, 0x7
	ble _080969DA
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80969D0

	thumb_func_start sub_8096A08
sub_8096A08:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_08096A14:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r2, r0, 0
	ldrb r0, [r2, 0x4]
	cmp r0, r5
	bne _08096A68
	ldrb r0, [r2]
	cmp r0, 0x6
	bne _08096A68
	ldrb r0, [r2, 0x1]
	cmp r0, 0x2
	bne _08096A68
	ldr r1, _08096A60
	ldr r0, [sp, 0x8]
	ands r0, r1
	movs r1, 0x4A
	orrs r0, r1
	ldr r1, _08096A64
	ands r0, r1
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp, 0x8]
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	add r0, sp, 0x8
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_808CFD0
	movs r0, 0x1
	b _08096A70
	.align 2, 0
_08096A60: .4byte 0xffffff00
_08096A64: .4byte 0xffff00ff
_08096A68:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08096A14
	movs r0, 0
_08096A70:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8096A08

	thumb_func_start sub_8096A78
sub_8096A78:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _08096AA0
	movs r2, 0
_08096A82:
	ldr r0, [r5]
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08096AA4
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	b _08096AAE
	.align 2, 0
_08096AA0: .4byte gUnknown_203B490
_08096AA4:
	adds r2, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096A82
	movs r0, 0x1
_08096AAE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096A78

	thumb_func_start sub_8096AB4
sub_8096AB4:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _08096AC8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0xF0
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_08096AC8: .4byte gUnknown_203B490
	thumb_func_end sub_8096AB4

	thumb_func_start sub_8096ACC
sub_8096ACC:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096AEC
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	adds r2, 0xF0
	ldrb r0, [r2]
	cmp r0, 0
	beq _08096AF0
	movs r0, 0
	b _08096AF2
	.align 2, 0
_08096AEC: .4byte gUnknown_203B490
_08096AF0:
	movs r0, 0x1
_08096AF2:
	pop {r1}
	bx r1
	thumb_func_end sub_8096ACC

	thumb_func_start sub_8096AF8
sub_8096AF8:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	bl sub_8096AB4
	adds r3, r0, 0
	movs r1, 0
	strb r1, [r5]
	ldrh r0, [r3, 0xC]
	strh r0, [r5, 0x2]
	strh r1, [r5, 0x4]
	ldrb r0, [r3, 0x4]
	cmp r0, r4
	bne _08096B92
	ldrb r0, [r3, 0x1]
	cmp r0, 0x4
	bhi _08096B92
	lsls r0, 2
	ldr r1, _08096B30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08096B30: .4byte _08096B34
	.align 2, 0
_08096B34:
	.4byte _08096B78
	.4byte _08096B84
	.4byte _08096B84
	.4byte _08096B48
	.4byte _08096B78
_08096B48:
	ldrb r0, [r3]
	cmp r0, 0x6
	bne _08096B92
	ldr r0, _08096B74
	movs r6, 0x1
	ldr r2, [r0]
	movs r4, 0x13
_08096B56:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08096B6A
	ldrb r0, [r2, 0x2]
	ldrb r1, [r3, 0x10]
	cmp r0, r1
	bne _08096B6A
	strb r6, [r5]
_08096B6A:
	adds r2, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08096B56
	b _08096B92
	.align 2, 0
_08096B74: .4byte gUnknown_203B460
_08096B78:
	ldrb r0, [r3]
	cmp r0, 0x9
	bne _08096B92
	movs r0, 0x1
	strb r0, [r5]
	b _08096B92
_08096B84:
	ldrb r0, [r3]
	cmp r0, 0x9
	bne _08096B92
	movs r0, 0x1
	strb r0, [r5]
	ldrh r0, [r3, 0xE]
	strh r0, [r5, 0x4]
_08096B92:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8096AF8

	thumb_func_start sub_8096B98
sub_8096B98:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_08096BA0:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _08096BC2
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	bne _08096BC2
	ldrb r0, [r1, 0x4]
	cmp r0, r5
	bne _08096BC2
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	b _08096BCA
_08096BC2:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08096BA0
	movs r0, 0
_08096BCA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096B98

	thumb_func_start sub_8096BD0
sub_8096BD0:
	push {r4,r5,lr}
	ldr r0, _08096C04
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0xF0
	movs r4, 0
_08096BDC:
	ldrb r0, [r5]
	cmp r0, 0x9
	bgt _08096BEE
	cmp r0, 0x7
	blt _08096BEE
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096C3C
_08096BEE:
	adds r5, 0x14
	adds r4, 0x1
	cmp r4, 0x7
	ble _08096BDC
	bl sub_8096C80
	bl sub_8096D24
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096C04: .4byte gUnknown_203B490
	thumb_func_end sub_8096BD0

	thumb_func_start sub_8096C08
sub_8096C08:
	push {lr}
	adds r3, r0, 0
	ldr r0, _08096C28
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	movs r2, 0
_08096C16:
	ldrb r0, [r1]
	cmp r0, 0x4
	bls _08096C2C
	ldrb r0, [r1, 0x2]
	cmp r0, 0x4
	bne _08096C2C
	strb r2, [r3]
	movs r0, 0x1
	b _08096C36
	.align 2, 0
_08096C28: .4byte gUnknown_203B490
_08096C2C:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x7
	ble _08096C16
	movs r0, 0
_08096C36:
	pop {r1}
	bx r1
	thumb_func_end sub_8096C08

	thumb_func_start sub_8096C3C
sub_8096C3C:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, _08096C78
	ldr r1, [r3]
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r1, 0xF0
	movs r4, 0
	strb r4, [r1]
	ldr r0, [r3]
	adds r0, r2
	adds r0, 0xF4
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, r2
	adds r0, 0xF5
	strb r4, [r0]
	ldr r0, [r3]
	adds r0, r2
	ldr r2, _08096C7C
	adds r1, r0, r2
	movs r0, 0x5
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096C78: .4byte gUnknown_203B490
_08096C7C: .4byte 0x00000101
	thumb_func_end sub_8096C3C

	thumb_func_start sub_8096C80
sub_8096C80:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _08096C98
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _08096CC2
	.align 2, 0
_08096C98: .4byte gUnknown_203B490
_08096C9C:
	cmp r2, r3
	ble _08096CB6
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	adds r1, 0xF0
	adds r0, 0xF0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_08096CB6:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_08096CC2:
	cmp r2, 0x7
	bgt _08096CF2
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096CF2
	ldr r6, _08096D20
	mov r1, r9
_08096CD8:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08096CF2
	ldr r0, [r6]
	adds r0, r1
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08096CD8
_08096CF2:
	cmp r2, 0x8
	bne _08096C9C
	cmp r3, 0x7
	bgt _08096D14
	ldr r4, _08096D20
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_08096D04:
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0xF0
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096D04
_08096D14:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096D20: .4byte gUnknown_203B490
	thumb_func_end sub_8096C80

	thumb_func_start sub_8096D24
sub_8096D24:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	movs r1, 0
_08096D32:
	adds r6, r1, 0x1
	mov r10, r6
	cmp r6, 0x7
	bgt _08096DBC
	ldr r0, _08096DD4
	mov r8, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r9, r0
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 2
_08096D4C:
	mov r1, r8
	ldr r2, [r1]
	adds r3, r2, r4
	adds r5, r3, 0
	adds r5, 0xF0
	str r5, [sp, 0x14]
	ldrb r0, [r5]
	cmp r0, 0
	beq _08096DB0
	add r2, r9
	mov r12, r2
	mov r0, r12
	adds r0, 0xF4
	adds r1, r3, 0
	adds r1, 0xF4
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	bhi _08096D84
	cmp r2, r0
	bne _08096DB0
	mov r0, r12
	adds r0, 0xF5
	adds r1, 0x1
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _08096DB0
_08096D84:
	mov r2, r12
	adds r2, 0xF0
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldm r0!, {r3,r7}
	stm r1!, {r3,r7}
	ldr r0, [sp, 0x14]
	ldm r0!, {r1,r5,r7}
	stm r2!, {r1,r5,r7}
	ldm r0!, {r3,r5}
	stm r2!, {r3,r5}
	mov r7, r8
	ldr r1, [r7]
	adds r1, r4
	adds r1, 0xF0
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r7}
	stm r1!, {r2,r7}
_08096DB0:
	adds r4, 0x14
	movs r3, 0x1
	add r10, r3
	mov r5, r10
	cmp r5, 0x7
	ble _08096D4C
_08096DBC:
	adds r1, r6, 0
	cmp r1, 0x6
	ble _08096D32
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096DD4: .4byte gUnknown_203B490
	thumb_func_end sub_8096D24

	thumb_func_start sub_8096DD8
sub_8096DD8:
	ldr r0, _08096DE4
	ldr r0, [r0]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bx lr
	.align 2, 0
_08096DE4: .4byte gUnknown_203B490
	thumb_func_end sub_8096DD8

	thumb_func_start sub_8096DE8
sub_8096DE8:
	ldr r0, _08096DF4
	ldr r0, [r0]
	movs r1, 0xDC
	lsls r1, 1
	adds r0, r1
	bx lr
	.align 2, 0
_08096DF4: .4byte gUnknown_203B490
	thumb_func_end sub_8096DE8

	thumb_func_start sub_8096DF8
sub_8096DF8:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096E10
	ldr r1, [r1]
	movs r2, 0xBC
	lsls r2, 2
	adds r1, r2
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08096E10: .4byte gUnknown_203B490
	thumb_func_end sub_8096DF8

	thumb_func_start sub_8096E14
sub_8096E14:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096E28
	ldr r1, [r1]
	movs r2, 0xBC
	lsls r2, 2
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_08096E28: .4byte gUnknown_203B490
	thumb_func_end sub_8096E14

	thumb_func_start sub_8096E2C
sub_8096E2C:
	push {lr}
	movs r3, 0
	ldr r0, _08096E70
	ldr r1, [r0]
	movs r2, 0x3
_08096E36:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08096E48
	ldrb r0, [r1, 0x5]
	cmp r3, r0
	bgt _08096E48
	cmp r0, 0x31
	bhi _08096E48
	adds r3, r0, 0x1
_08096E48:
	adds r1, 0x14
	subs r2, 0x1
	cmp r2, 0
	bge _08096E36
	adds r2, r3, 0
	cmp r2, 0x31
	bgt _08096E7A
	ldr r0, _08096E70
	ldr r0, [r0]
	movs r3, 0xBC
	lsls r3, 2
	adds r1, r0, r3
_08096E60:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096E74
	lsls r0, r2, 24
	lsrs r0, 24
	b _08096E7C
	.align 2, 0
_08096E70: .4byte gUnknown_203B490
_08096E74:
	adds r2, 0x1
	cmp r2, 0x31
	ble _08096E60
_08096E7A:
	movs r0, 0x38
_08096E7C:
	pop {r1}
	bx r1
	thumb_func_end sub_8096E2C

	thumb_func_start sub_8096E80
sub_8096E80:
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, _08096E9C
	ldr r1, [r0]
_08096E8C:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08096EA0
	ldrb r0, [r1, 0x5]
	cmp r3, r0
	bne _08096EA0
	movs r0, 0x1
	b _08096EAA
	.align 2, 0
_08096E9C: .4byte gUnknown_203B490
_08096EA0:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x3
	ble _08096E8C
	movs r0, 0
_08096EAA:
	pop {r1}
	bx r1
	thumb_func_end sub_8096E80

	thumb_func_start sub_8096EB0
sub_8096EB0:
	ldrb r1, [r0, 0x2]
	ldrb r2, [r0, 0x1]
	adds r1, r2
	ldrb r3, [r0, 0x4]
	adds r2, r1, r3
	ldrb r1, [r0, 0x5]
	adds r2, r1
	ldr r1, [r0, 0x8]
	lsls r1, 8
	adds r2, r1
	movs r3, 0xC
	ldrsh r1, [r0, r3]
	lsls r1, 12
	adds r2, r1
	movs r3, 0xE
	ldrsh r1, [r0, r3]
	lsls r1, 16
	adds r2, r1
	ldrb r1, [r0, 0x10]
	lsls r1, 24
	adds r1, r2, r1
	ldrb r3, [r0, 0x11]
	adds r2, r1, r3
	ldrb r1, [r0, 0x12]
	adds r1, r2, r1
	ldrb r0, [r0, 0x13]
	adds r2, r1, r0
	adds r0, r2, 0
	bx lr
	thumb_func_end sub_8096EB0

	thumb_func_start sub_8096EEC
sub_8096EEC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r12, r0
	movs r3, 0xF
	ldr r5, _08096F4C
	mov r8, r5
	movs r4, 0x8C
	lsls r4, 2
_08096EFE:
	mov r0, r8
	ldr r2, [r0]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2, r1
	subs r3, 0x1
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r2, r0
	adds r1, r4
	adds r2, r4
	ldm r2!, {r0,r6,r7}
	stm r1!, {r0,r6,r7}
	cmp r3, 0
	bgt _08096EFE
	ldr r2, [r5]
	movs r3, 0x8C
	lsls r3, 2
	adds r2, r3
	mov r6, r12
	ldr r0, [r6, 0x4]
	ldr r1, [r6, 0x8]
	str r0, [r2]
	str r1, [r2, 0x4]
	mov r0, r12
	bl sub_8096EB0
	ldr r1, [r5]
	movs r7, 0x8E
	lsls r7, 2
	adds r1, r7
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096F4C: .4byte gUnknown_203B490
	thumb_func_end sub_8096EEC

	thumb_func_start sub_8096F50
sub_8096F50:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_8096EB0
	mov r12, r0
	movs r5, 0
	ldr r0, _08096F8C
	ldr r7, [r0]
	ldrb r6, [r4, 0x4]
	movs r3, 0
_08096F64:
	movs r1, 0x8C
	lsls r1, 2
	adds r0, r3, r1
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, r6
	bne _08096F90
	ldrb r0, [r2, 0x1]
	ldrb r1, [r4, 0x5]
	cmp r0, r1
	bne _08096F90
	ldr r1, [r2, 0x4]
	ldr r0, [r4, 0x8]
	cmp r1, r0
	bne _08096F90
	ldr r0, [r2, 0x8]
	cmp r0, r12
	bne _08096F90
	movs r0, 0x1
	b _08096F9A
	.align 2, 0
_08096F8C: .4byte gUnknown_203B490
_08096F90:
	adds r3, 0xC
	adds r5, 0x1
	cmp r5, 0xF
	ble _08096F64
	movs r0, 0
_08096F9A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8096F50

	thumb_func_start sub_8096FA0
sub_8096FA0:
	push {r4-r7,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	add r7, sp, 0x10
	ldr r6, _08097020
	movs r5, 0
	movs r4, 0x3
_08096FB8:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80971EC
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08096FB8
	ldr r6, _08097020
	movs r5, 0x50
	movs r4, 0x7
_08096FD0:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80971EC
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08096FD0
	ldr r6, _08097020
	movs r5, 0xF0
	movs r4, 0x7
_08096FE8:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80971EC
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08096FE8
	movs r4, 0
	movs r6, 0x1
	ldr r5, _08097020
_08097000:
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_8094924
	ldr r1, [sp, 0x10]
	ands r1, r6
	cmp r1, 0
	beq _08097024
	ldr r0, [r5]
	movs r1, 0xBC
	lsls r1, 2
	adds r0, r1
	adds r0, r4
	strb r6, [r0]
	b _08097030
	.align 2, 0
_08097020: .4byte gUnknown_203B490
_08097024:
	ldr r0, [r5]
	movs r2, 0xBC
	lsls r2, 2
	adds r0, r2
	adds r0, r4
	strb r1, [r0]
_08097030:
	adds r4, 0x1
	cmp r4, 0x37
	ble _08097000
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_8094924
	ldr r1, [sp, 0x10]
	movs r2, 0x1
	ands r1, r2
	cmp r1, 0
	beq _0809705C
	ldr r0, _08097058
	ldr r0, [r0]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	strb r2, [r0]
	b _08097068
	.align 2, 0
_08097058: .4byte gUnknown_203B490
_0809705C:
	ldr r0, _080970D4
	ldr r0, [r0]
	movs r2, 0xCA
	lsls r2, 2
	adds r0, r2
	strb r1, [r0]
_08097068:
	ldr r4, _080970D4
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r2, 0xA0
	lsls r2, 1
	mov r0, sp
	bl sub_8094924
	ldr r1, [r4]
	movs r2, 0xDC
	lsls r2, 1
	adds r1, r2
	movs r2, 0xF0
	lsls r2, 2
	mov r0, sp
	bl sub_8094924
	adds r6, r4, 0
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0xF
_08097096:
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x8
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x4
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8090314
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _08097096
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080970D4: .4byte gUnknown_203B490
	thumb_func_end sub_8096FA0

	thumb_func_start sub_80970D8
sub_80970D8:
	push {r4-r7,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	add r7, sp, 0x10
	ldr r6, _080971E8
	movs r5, 0
	movs r4, 0x3
_080970F0:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8097270
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _080970F0
	ldr r6, _080971E8
	movs r5, 0x50
	movs r4, 0x7
_08097108:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8097270
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08097108
	ldr r6, _080971E8
	movs r5, 0xF0
	movs r4, 0x7
_08097120:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8097270
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08097120
	movs r4, 0
_08097134:
	ldr r0, _080971E8
	ldr r0, [r0]
	movs r1, 0xBC
	lsls r1, 2
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809714A
	movs r0, 0x1
	negs r0, r0
_0809714A:
	str r0, [sp, 0x10]
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_809488C
	adds r4, 0x1
	cmp r4, 0x37
	ble _08097134
	ldr r0, _080971E8
	ldr r0, [r0]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08097170
	movs r0, 0x1
	negs r0, r0
_08097170:
	str r0, [sp, 0x10]
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r4, _080971E8
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r2, 0xA0
	lsls r2, 1
	mov r0, sp
	bl sub_809488C
	ldr r1, [r4]
	movs r0, 0xDC
	lsls r0, 1
	adds r1, r0
	movs r2, 0xF0
	lsls r2, 2
	mov r0, sp
	bl sub_809488C
	adds r6, r4, 0
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0xF
_080971AA:
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x8
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x4
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80902F4
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _080971AA
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080971E8: .4byte gUnknown_203B490
	thumb_func_end sub_80970D8

	thumb_func_start sub_80971EC
sub_80971EC:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x3
	bl sub_8094924
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0xE
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x11
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x12
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x13
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl sub_8090314
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80971EC

	thumb_func_start sub_8097270
sub_8097270:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x3
	bl sub_809488C
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0xE
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x11
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x12
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x13
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl sub_80902F4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8097270

	thumb_func_start sub_80972F4
sub_80972F4:
	push {lr}
	movs r0, 0
	movs r1, 0x2B
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2C
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2D
	bl sub_80015C0
	pop {r0}
	bx r0
	thumb_func_end sub_80972F4

	thumb_func_start nullsub_128
nullsub_128:
	bx lr
	thumb_func_end nullsub_128

	thumb_func_start sub_8097318
sub_8097318:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097326
	movs r0, 0
	b _08097338
_08097326:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2B
	bl sub_8001784
	cmp r0, 0
	beq _08097338
	movs r0, 0x1
_08097338:
	pop {r1}
	bx r1
	thumb_func_end sub_8097318

	thumb_func_start sub_809733C
sub_809733C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r4, 0xD
	beq _0809737C
	lsls r0, r4, 16
	lsrs r5, r0, 16
	movs r0, 0
	movs r1, 0x2C
	adds r2, r5, 0
	bl sub_8001784
	cmp r0, 0
	bne _0809737C
	movs r0, 0
	movs r1, 0x2B
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_800199C
	cmp r6, 0
	beq _0809737C
	cmp r4, 0xE
	blt _0809737C
	cmp r4, 0xF
	ble _08097378
	cmp r4, 0x1C
	bne _0809737C
_08097378:
	bl sub_809674C
_0809737C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809733C

	thumb_func_start sub_8097384
sub_8097384:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097392
	movs r0, 0
	b _080973A4
_08097392:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2C
	bl sub_8001784
	cmp r0, 0
	beq _080973A4
	movs r0, 0x1
_080973A4:
	pop {r1}
	bx r1
	thumb_func_end sub_8097384

	thumb_func_start sub_80973A8
sub_80973A8:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r0, 0xD
	beq _080973EE
	lsls r5, r0, 16
	cmp r6, 0
	beq _080973E2
	bl sub_80A26B8
	lsls r0, 16
	asrs r4, r0, 16
	lsrs r2, r5, 16
	movs r0, 0
	movs r1, 0x2B
	movs r3, 0
	bl sub_800199C
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080973E2
	movs r0, 0
	movs r1, 0x12
	adds r2, r4, 0
	bl sub_80018D8
_080973E2:
	lsrs r2, r5, 16
	movs r0, 0
	movs r1, 0x2C
	adds r3, r6, 0
	bl sub_800199C
_080973EE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80973A8

	thumb_func_start sub_80973F4
sub_80973F4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097402
	movs r0, 0
	b _08097414
_08097402:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2D
	bl sub_8001784
	cmp r0, 0
	beq _08097414
	movs r0, 0x1
_08097414:
	pop {r1}
	bx r1
	thumb_func_end sub_80973F4

	thumb_func_start sub_8097418
sub_8097418:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r5, 0xD
	beq _08097470
	lsls r6, r5, 16
	cmp r7, 0
	beq _08097464
	lsrs r2, r6, 16
	movs r0, 0
	movs r1, 0x2C
	movs r3, 0
	bl sub_800199C
	cmp r5, 0x1E
	bgt _08097464
	lsls r0, r5, 3
	ldr r1, _08097478
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0xFF
	beq _0809744C
	bl sub_8097FA8
_0809744C:
	ldrb r0, [r4, 0x5]
	cmp r0, 0xFF
	beq _08097456
	bl sub_8097FA8
_08097456:
	cmp r5, 0x9
	bne _08097460
	movs r0, 0x1F
	bl sub_8097FA8
_08097460:
	bl sub_8097FF8
_08097464:
	lsrs r2, r6, 16
	movs r0, 0
	movs r1, 0x2D
	adds r3, r7, 0
	bl sub_800199C
_08097470:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097478: .4byte gStoryMissionText
	thumb_func_end sub_8097418

	thumb_func_start sub_809747C
sub_809747C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	beq _08097494
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	bl GetDungeonName1
	b _08097496
_08097494:
	ldr r0, _0809749C
_08097496:
	pop {r1}
	bx r1
	.align 2, 0
_0809749C: .4byte gDummyScenarioText
	thumb_func_end sub_809747C

	thumb_func_start sub_80974A0
sub_80974A0:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	beq _080974B8
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	bl GetDungeonName1
	b _080974BA
_080974B8:
	ldr r0, _080974C0
_080974BA:
	pop {r1}
	bx r1
	.align 2, 0
_080974C0: .4byte gDummyScenarioText
	thumb_func_end sub_80974A0

	thumb_func_start sub_80974C4
sub_80974C4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _080974D8
	ldr r0, _080974D4
	b _080974E0
	.align 2, 0
_080974D4: .4byte gUnknown_8109CC0
_080974D8:
	lsls r0, 3
	ldr r1, _080974E4
	adds r0, r1
	ldr r0, [r0]
_080974E0:
	pop {r1}
	bx r1
	.align 2, 0
_080974E4: .4byte gStoryMissionText
	thumb_func_end sub_80974C4

	thumb_func_start sub_80974E8
sub_80974E8:
	push {lr}
	movs r0, 0
	movs r1, 0x2E
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2F
	bl sub_80015C0
	pop {r0}
	bx r0
	thumb_func_end sub_80974E8

	thumb_func_start nullsub_208
nullsub_208:
	bx lr
	thumb_func_end nullsub_208

	thumb_func_start sub_8097504
sub_8097504:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	adds r1, r0, 0
	cmp r0, 0x10
	bgt _08097568
	cmp r0, 0xE
	bhi _08097580
	lsls r0, 2
	ldr r1, _08097520
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08097520: .4byte _08097524
	.align 2, 0
_08097524:
	.4byte _08097564
	.4byte _08097564
	.4byte _08097560
	.4byte _08097580
	.4byte _08097580
	.4byte _08097564
	.4byte _08097580
	.4byte _08097564
	.4byte _08097580
	.4byte _08097564
	.4byte _08097560
	.4byte _08097560
	.4byte _08097560
	.4byte _08097574
	.4byte _08097564
_08097560:
	movs r0, 0xE
	b _08097576
_08097564:
	movs r0, 0xF
	b _08097576
_08097568:
	cmp r1, 0x16
	bgt _08097584
	cmp r1, 0x16
	beq _08097584
	cmp r1, 0x15
	beq _08097584
_08097574:
	movs r0, 0x6
_08097576:
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08097584
_08097580:
	movs r0, 0x1
	b _08097586
_08097584:
	movs r0, 0
_08097586:
	pop {r1}
	bx r1
	thumb_func_end sub_8097504

	thumb_func_start sub_809758C
sub_809758C:
	push {lr}
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2E
	bl sub_8001784
	cmp r0, 0
	beq _080975A2
	movs r0, 0x1
_080975A2:
	pop {r1}
	bx r1
	thumb_func_end sub_809758C

	thumb_func_start sub_80975A8
sub_80975A8:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2E
	bl sub_800199C
	pop {r0}
	bx r0
	thumb_func_end sub_80975A8

	thumb_func_start sub_80975C4
sub_80975C4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2728
	lsls r0, 24
	lsrs r0, 24
	bl GetDungeonName1
	pop {r1}
	bx r1
	thumb_func_end sub_80975C4

	thumb_func_start sub_80975DC
sub_80975DC:
	push {lr}
	lsls r0, 16
	ldr r1, _08097600
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0x1
	bhi _08097610
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xE
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08097608
	ldr r0, _08097604
	b _08097612
	.align 2, 0
_08097600: .4byte 0xffe90000
_08097604: .4byte gMeetNinetalesText
_08097608:
	ldr r0, _0809760C
	b _08097612
	.align 2, 0
_0809760C: .4byte gAvoidCaptureText
_08097610:
	ldr r0, _08097618
_08097612:
	pop {r1}
	bx r1
	.align 2, 0
_08097618: .4byte gFinalScenarioText
	thumb_func_end sub_80975DC

	thumb_func_start sub_809761C
sub_809761C:
	push {r4,lr}
	movs r4, 0
_08097620:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_809758C
	lsls r0, 24
	cmp r0, 0
	bne _08097632
	movs r0, 0
	b _0809763A
_08097632:
	adds r4, 0x1
	cmp r4, 0x10
	ble _08097620
	movs r0, 0x1
_0809763A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809761C

	thumb_func_start sub_8097640
sub_8097640:
	push {lr}
	movs r0, 0
	movs r1, 0x2E
	movs r2, 0x1F
	bl sub_8001784
	cmp r0, 0
	bne _0809766A
	bl sub_809761C
	lsls r0, 24
	cmp r0, 0
	beq _0809766A
	movs r0, 0
	movs r1, 0x2E
	movs r2, 0x1F
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0x1
	b _0809766C
_0809766A:
	movs r0, 0
_0809766C:
	pop {r1}
	bx r1
	thumb_func_end sub_8097640

	thumb_func_start sub_8097670
sub_8097670:
	ldr r1, _08097678
	ldr r0, _0809767C
	str r0, [r1]
	bx lr
	.align 2, 0
_08097678: .4byte gUnknown_203B494
_0809767C: .4byte gUnknown_2039778
	thumb_func_end sub_8097670

	thumb_func_start sub_8097680
sub_8097680:
	ldr r0, _08097684
	bx lr
	.align 2, 0
_08097684: .4byte gUnknown_2039778
	thumb_func_end sub_8097680

	thumb_func_start sub_8097688
sub_8097688:
	ldr r3, _08097698
	ldr r2, [r3]
	ldrb r1, [r0]
	strb r1, [r2, 0x10]
	ldr r1, [r3]
	ldrb r0, [r0, 0x1]
	strb r0, [r1, 0x11]
	bx lr
	.align 2, 0
_08097698: .4byte gUnknown_203B494
	thumb_func_end sub_8097688

	thumb_func_start sub_809769C
sub_809769C:
	ldr r0, _080976A4
	ldr r0, [r0]
	adds r0, 0x10
	bx lr
	.align 2, 0
_080976A4: .4byte gUnknown_203B494
	thumb_func_end sub_809769C

	thumb_func_start sub_80976A8
sub_80976A8:
	push {r4,lr}
	ldr r3, _080976F4
	ldr r1, [r3]
	movs r0, 0
	str r0, [r1]
	strh r0, [r1, 0x14]
	strh r0, [r1, 0x16]
	strh r0, [r1, 0x18]
	adds r2, r1, 0
	adds r2, 0xC0
	str r0, [r2]
	str r0, [r1, 0x8]
	str r0, [r1, 0xC]
	movs r2, 0
	adds r4, r3, 0
	movs r3, 0
_080976C8:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x1C
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0xD
	ble _080976C8
	movs r2, 0
	ldr r4, _080976F4
	movs r3, 0
_080976DE:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x8C
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0xC
	ble _080976DE
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080976F4: .4byte gUnknown_203B494
	thumb_func_end sub_80976A8

	thumb_func_start sub_80976F8
sub_80976F8:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0809770C
	ldr r2, [r1]
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0809770C: .4byte gUnknown_203B494
	thumb_func_end sub_80976F8

	thumb_func_start sub_8097710
sub_8097710:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0809772C
	ldr r2, [r1]
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _08097730
	movs r0, 0
	b _08097732
	.align 2, 0
_0809772C: .4byte gUnknown_203B494
_08097730:
	movs r0, 0x1
_08097732:
	pop {r1}
	bx r1
	thumb_func_end sub_8097710

	thumb_func_start sub_8097738
sub_8097738:
	lsls r0, 24
	ldr r1, _08097744
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08097744: .4byte gTeamRanks
	thumb_func_end sub_8097738

	thumb_func_start sub_8097748
sub_8097748:
	ldr r0, _08097754
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_08097754: .4byte gUnknown_203B494
	thumb_func_end sub_8097748

	thumb_func_start sub_8097758
sub_8097758:
	push {lr}
	ldr r0, _08097770
	ldr r1, [r0]
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	ldr r2, _08097774
	cmp r0, r2
	ble _0809776C
	str r2, [r1, 0x4]
_0809776C:
	pop {r0}
	bx r0
	.align 2, 0
_08097770: .4byte gUnknown_203B494
_08097774: .4byte 0x0001869f
	thumb_func_end sub_8097758

	thumb_func_start sub_8097778
sub_8097778:
	ldr r0, _08097780
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bx lr
	.align 2, 0
_08097780: .4byte gUnknown_203B494
	thumb_func_end sub_8097778

	thumb_func_start sub_8097784
sub_8097784:
	ldr r1, _0809778C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_0809778C: .4byte gUnknown_203B494
	thumb_func_end sub_8097784

	thumb_func_start sub_8097790
sub_8097790:
	push {lr}
	ldr r0, _080977B0
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	adds r0, 0x1
	str r0, [r1, 0x8]
	ldr r2, _080977B4
	cmp r0, r2
	ble _080977A4
	str r2, [r1, 0x8]
_080977A4:
	movs r0, 0x8
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_080977B0: .4byte gUnknown_203B494
_080977B4: .4byte 0x0001869f
	thumb_func_end sub_8097790

	thumb_func_start sub_80977B8
sub_80977B8:
	ldr r0, _080977C0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bx lr
	.align 2, 0
_080977C0: .4byte gUnknown_203B494
	thumb_func_end sub_80977B8

	thumb_func_start sub_80977C4
sub_80977C4:
	ldr r1, _080977CC
	ldr r1, [r1]
	str r0, [r1, 0x8]
	bx lr
	.align 2, 0
_080977CC: .4byte gUnknown_203B494
	thumb_func_end sub_80977C4

	thumb_func_start sub_80977D0
sub_80977D0:
	push {lr}
	ldr r0, _080977F0
	ldr r1, [r0]
	ldr r0, [r1, 0xC]
	adds r0, 0x1
	str r0, [r1, 0xC]
	ldr r2, _080977F4
	cmp r0, r2
	ble _080977E4
	str r2, [r1, 0xC]
_080977E4:
	movs r0, 0x9
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_080977F0: .4byte gUnknown_203B494
_080977F4: .4byte 0x0001869f
	thumb_func_end sub_80977D0

	thumb_func_start sub_80977F8
sub_80977F8:
	ldr r0, _08097800
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bx lr
	.align 2, 0
_08097800: .4byte gUnknown_203B494
	thumb_func_end sub_80977F8

	thumb_func_start sub_8097804
sub_8097804:
	ldr r1, _0809780C
	ldr r1, [r1]
	str r0, [r1, 0xC]
	bx lr
	.align 2, 0
_0809780C: .4byte gUnknown_203B494
	thumb_func_end sub_8097804

	thumb_func_start sub_8097810
sub_8097810:
	push {lr}
	ldr r0, _08097830
	ldr r2, [r0]
	ldrh r3, [r2, 0x14]
	movs r0, 0x14
	ldrsh r1, [r2, r0]
	ldr r0, _08097834
	cmp r1, r0
	bgt _08097826
	adds r0, r3, 0x1
	strh r0, [r2, 0x14]
_08097826:
	movs r0, 0xB
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_08097830: .4byte gUnknown_203B494
_08097834: .4byte 0x0000270e
	thumb_func_end sub_8097810

	thumb_func_start sub_8097838
sub_8097838:
	ldr r0, _08097844
	ldr r0, [r0]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08097844: .4byte gUnknown_203B494
	thumb_func_end sub_8097838

	thumb_func_start sub_8097848
sub_8097848:
	push {lr}
	ldr r0, _08097868
	ldr r2, [r0]
	ldrh r3, [r2, 0x16]
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	ldr r0, _0809786C
	cmp r1, r0
	bgt _0809785E
	adds r0, r3, 0x1
	strh r0, [r2, 0x16]
_0809785E:
	movs r0, 0xA
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_08097868: .4byte gUnknown_203B494
_0809786C: .4byte 0x0000270e
	thumb_func_end sub_8097848

	thumb_func_start sub_8097870
sub_8097870:
	ldr r0, _0809787C
	ldr r0, [r0]
	movs r1, 0x16
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0809787C: .4byte gUnknown_203B494
	thumb_func_end sub_8097870

	thumb_func_start sub_8097880
sub_8097880:
	ldr r0, _0809788C
	ldr r0, [r0]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0809788C: .4byte gUnknown_203B494
	thumb_func_end sub_8097880

	thumb_func_start sub_8097890
sub_8097890:
	push {lr}
	ldr r0, _080978B0
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xC0
	ldr r1, [r2]
	ldr r0, _080978B4
	cmp r1, r0
	bgt _080978A6
	adds r0, r1, 0x1
	str r0, [r2]
_080978A6:
	movs r0, 0xC
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_080978B0: .4byte gUnknown_203B494
_080978B4: .4byte 0x0001869e
	thumb_func_end sub_8097890

	thumb_func_start sub_80978B8
sub_80978B8:
	ldr r0, _080978C4
	ldr r0, [r0]
	adds r0, 0xC0
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080978C4: .4byte gUnknown_203B494
	thumb_func_end sub_80978B8

	thumb_func_start sub_80978C8
sub_80978C8:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E858
	lsls r0, 16
	asrs r3, r0, 16
	ldr r0, _080978FC
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _080978E2
	adds r0, 0x1F
_080978E2:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x54
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080978FC: .4byte gUnknown_203B494
	thumb_func_end sub_80978C8

	thumb_func_start sub_8097900
sub_8097900:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E858
	lsls r0, 16
	asrs r3, r0, 16
	ldr r0, _08097938
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _0809791A
	adds r0, 0x1F
_0809791A:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x1C
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _0809793C
	movs r0, 0
	b _0809793E
	.align 2, 0
_08097938: .4byte gUnknown_203B494
_0809793C:
	movs r0, 0x1
_0809793E:
	pop {r1}
	bx r1
	thumb_func_end sub_8097900

	thumb_func_start sub_8097944
sub_8097944:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0x1
	str r0, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	movs r0, 0xD
	bl sub_8097710
	lsls r0, 24
	cmp r0, 0
	bne _08097974
	bl sub_8092614
	lsls r0, 24
	cmp r0, 0
	beq _08097974
	movs r0, 0xD
	bl sub_80976F8
_08097974:
	movs r4, 0
	ldr r0, _08097B5C
	mov r10, r0
	mov r8, r4
_0809797C:
	ldr r1, _08097B60
	ldr r0, [r1]
	mov r1, r8
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080979F6
	movs r0, 0x8
	ldrsh r3, [r2, r0]
	mov r1, r10
	ldr r2, [r1]
	adds r0, r3, 0
	cmp r3, 0
	bge _0809799E
	adds r0, 0x1F
_0809799E:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x1C
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08097B60
	mov r9, r0
	mov r12, r8
	movs r7, 0x1
	movs r6, 0x2C
	movs r5, 0x3
_080979C0:
	mov r1, r9
	ldr r0, [r1]
	add r0, r12
	adds r3, r0, r6
	ldrb r1, [r3]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080979EE
	mov r0, r10
	ldr r2, [r0]
	ldrh r3, [r3, 0x2]
	lsrs r0, r3, 5
	lsls r0, 2
	adds r2, 0x8C
	adds r2, r0
	movs r0, 0x1F
	ands r3, r0
	adds r1, r7, 0
	lsls r1, r3
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080979EE:
	adds r6, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _080979C0
_080979F6:
	movs r1, 0x58
	add r8, r1
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0809797C
	movs r4, 0
	ldr r1, _08097B64
_08097A08:
	cmp r4, 0
	bne _08097A0E
	b _08097B80
_08097A0E:
	ldr r0, _08097B68
	cmp r4, r0
	bne _08097A16
	b _08097B80
_08097A16:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A1E
	b _08097B80
_08097A1E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A26
	b _08097B80
_08097A26:
	adds r0, 0x26
	cmp r4, r0
	bne _08097A2E
	b _08097B80
_08097A2E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A36
	b _08097B80
_08097A36:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A3E
	b _08097B80
_08097A3E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A46
	b _08097B80
_08097A46:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A4E
	b _08097B80
_08097A4E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A56
	b _08097B80
_08097A56:
	cmp r4, r1
	bne _08097A5C
	b _08097B80
_08097A5C:
	ldr r0, _08097B5C
	ldr r5, [r0]
	adds r0, r4, 0
	cmp r4, 0
	bge _08097A68
	adds r0, 0x1F
_08097A68:
	asrs r0, 5
	lsls r3, r0, 2
	adds r1, r5, 0
	adds r1, 0x54
	adds r1, r3
	lsls r0, 5
	subs r0, r4, r0
	movs r2, 0x1
	lsls r2, r0
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	bne _08097A86
	movs r0, 0
	str r0, [sp, 0x4]
_08097A86:
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r3
	ldr r0, [r0]
	ands r0, r2
	cmp r0, 0
	beq _08097B7C
	cmp r4, 0x92
	bne _08097A9E
	movs r0, 0x10
	bl sub_80976F8
_08097A9E:
	cmp r4, 0x91
	bne _08097AA8
	movs r0, 0x11
	bl sub_80976F8
_08097AA8:
	cmp r4, 0x90
	bne _08097AB2
	movs r0, 0x12
	bl sub_80976F8
_08097AB2:
	movs r0, 0xCF
	lsls r0, 1
	cmp r4, r0
	bne _08097AC0
	movs r0, 0x13
	bl sub_80976F8
_08097AC0:
	ldr r0, _08097B6C
	cmp r4, r0
	bne _08097ACC
	movs r0, 0x14
	bl sub_80976F8
_08097ACC:
	movs r0, 0x86
	lsls r0, 1
	cmp r4, r0
	bne _08097ADA
	movs r0, 0x15
	bl sub_80976F8
_08097ADA:
	movs r0, 0x87
	lsls r0, 1
	cmp r4, r0
	bne _08097AE8
	movs r0, 0x16
	bl sub_80976F8
_08097AE8:
	ldr r0, _08097B70
	cmp r4, r0
	bne _08097AF4
	movs r0, 0x17
	bl sub_80976F8
_08097AF4:
	movs r0, 0xCD
	lsls r0, 1
	cmp r4, r0
	bne _08097B02
	movs r0, 0x18
	bl sub_80976F8
_08097B02:
	ldr r0, _08097B74
	cmp r4, r0
	bne _08097B0E
	movs r0, 0x19
	bl sub_80976F8
_08097B0E:
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bne _08097B1C
	movs r0, 0x1A
	bl sub_80976F8
_08097B1C:
	movs r0, 0x89
	lsls r0, 1
	cmp r4, r0
	bne _08097B2A
	movs r0, 0x1B
	bl sub_80976F8
_08097B2A:
	movs r0, 0x8A
	lsls r0, 1
	cmp r4, r0
	bne _08097B38
	movs r0, 0x1C
	bl sub_80976F8
_08097B38:
	cmp r4, 0x97
	bne _08097B42
	movs r0, 0x1D
	bl sub_80976F8
_08097B42:
	cmp r4, 0x96
	bne _08097B4C
	movs r0, 0x1E
	bl sub_80976F8
_08097B4C:
	ldr r0, _08097B78
	cmp r4, r0
	bne _08097B80
	movs r0, 0x1F
	bl sub_80976F8
	b _08097B80
	.align 2, 0
_08097B5C: .4byte gUnknown_203B494
_08097B60: .4byte gUnknown_203B45C
_08097B64: .4byte 0x000001a7
_08097B68: .4byte 0x00000179
_08097B6C: .4byte 0x0000010d
_08097B70: .4byte 0x00000113
_08097B74: .4byte 0x0000019b
_08097B78: .4byte 0x0000019d
_08097B7C:
	movs r1, 0
	str r1, [sp]
_08097B80:
	adds r4, 0x1
	ldr r1, _08097C0C
	cmp r4, r1
	bgt _08097B8A
	b _08097A08
_08097B8A:
	ldr r0, [sp]
	cmp r0, 0
	beq _08097B96
	movs r0, 0xF
	bl sub_80976F8
_08097B96:
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _08097BA2
	movs r0, 0xE
	bl sub_80976F8
_08097BA2:
	movs r3, 0
	movs r4, 0
_08097BA6:
	cmp r4, 0
	beq _08097BE2
	ldr r0, _08097C10
	cmp r4, r0
	beq _08097BE2
	adds r0, 0x1
	cmp r4, r0
	beq _08097BE2
	adds r0, 0x1
	cmp r4, r0
	beq _08097BE2
	ldr r0, _08097C14
	ldr r2, [r0]
	adds r0, r4, 0
	cmp r4, 0
	bge _08097BC8
	adds r0, 0x1F
_08097BC8:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x8C
	adds r2, r1
	lsls r0, 5
	subs r0, r4, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _08097BE2
	adds r3, 0x1
_08097BE2:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08097BA6
	cmp r3, 0
	beq _08097BFC
	ldr r0, _08097C14
	ldr r0, [r0]
	strh r3, [r0, 0x18]
	movs r0, 0x7
	bl sub_80976F8
_08097BFC:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097C0C: .4byte 0x000001a7
_08097C10: .4byte 0x00000163
_08097C14: .4byte gUnknown_203B494
	thumb_func_end sub_8097944

	thumb_func_start sub_8097C18
sub_8097C18:
	push {r4-r6,lr}
	adds r5, r0, 0
	bl sub_8097944
	ldr r4, _08097CBC
	ldr r1, [r4]
	adds r1, 0x4
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x16
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x18
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0xC0
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x1C
	movs r6, 0xE0
	lsls r6, 1
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x54
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x8C
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r5, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x10
	adds r0, r5, 0
	bl sub_80902F4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097CBC: .4byte gUnknown_203B494
	thumb_func_end sub_8097C18

	thumb_func_start sub_8097CC0
sub_8097CC0:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _08097D5C
	ldr r1, [r4]
	adds r1, 0x4
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x16
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x18
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0xC0
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x1C
	movs r6, 0xE0
	lsls r6, 1
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x54
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x8C
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r5, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x10
	adds r0, r5, 0
	bl sub_8090314
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097D5C: .4byte gUnknown_203B494
	thumb_func_end sub_8097CC0

	thumb_func_start sub_8097D60
sub_8097D60:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	mov r0, sp
	bl sub_8094A44
	mov r0, sp
	bl sub_8095044
	mov r0, sp
	bl sub_8097C18
	mov r0, sp
	bl sub_8098248
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r1}
	bx r1
	thumb_func_end sub_8097D60

	thumb_func_start sub_8097D98
sub_8097D98:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	mov r0, sp
	bl sub_8094B18
	mov r0, sp
	bl sub_8095080
	mov r0, sp
	bl sub_8097CC0
	mov r0, sp
	bl sub_8098308
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r1}
	bx r1
	thumb_func_end sub_8097D98

	thumb_func_start sub_8097DD0
sub_8097DD0:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _08097DEA
	ldr r1, [r2, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bne _08097DEA
	movs r0, 0x1
	b _08097DEC
_08097DEA:
	movs r0, 0
_08097DEC:
	pop {r1}
	bx r1
	thumb_func_end sub_8097DD0

	thumb_func_start sub_8097DF0
sub_8097DF0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1F8
	mov r8, r0
	str r1, [sp, 0x1F0]
	movs r0, 0
	mov r9, r0
	movs r7, 0
	ldr r1, _08097E3C
	ldr r0, [r1]
	cmp r0, 0
	beq _08097E6E
_08097E0E:
	movs r4, 0
	lsls r5, r7, 3
	lsls r1, r7, 2
	mov r10, r1
	adds r6, r7, 0x1
	ldr r2, _08097E3C
	adds r3, r5, r2
	add r1, sp, 0x18C
_08097E1E:
	ldr r0, [r3]
	adds r0, r4
	ldrb r2, [r0]
	cmp r2, 0x23
	bne _08097E40
	ldrb r0, [r0, 0x1]
	cmp r0, 0x72
	bne _08097E40
	strb r2, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0
	strb r0, [r1]
	b _08097E50
	.align 2, 0
_08097E3C: .4byte gStatusDescriptions
_08097E40:
	ldr r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x63
	ble _08097E1E
_08097E50:
	add r0, sp, 0x18C
	bl strlen
	mov r1, sp
	add r1, r10
	str r0, [r1]
	adds r7, r6, 0
	cmp r6, 0x62
	bgt _08097E6E
	lsls r0, r6, 3
	ldr r1, _08097EB4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _08097E0E
_08097E6E:
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0
	beq _08097F2C
	ldr r3, _08097EB4
_08097E78:
	cmp r0, 0x23
	bne _08097F08
	movs r7, 0
	adds r1, r3, 0
	ldr r0, [r1]
	cmp r0, 0
	beq _08097F20
	mov r2, r9
	lsls r0, r2, 2
	ldr r2, [sp, 0x1F0]
	adds r0, r2
	mov r10, r0
_08097E90:
	lsls r4, r7, 3
	adds r0, r4, r1
	ldr r0, [r0]
	lsls r1, r7, 2
	add r1, sp
	ldr r2, [r1]
	mov r1, r8
	str r3, [sp, 0x1F4]
	bl sub_800B2D4
	lsls r0, 24
	adds r5, r4, 0
	adds r6, r7, 0x1
	ldr r3, [sp, 0x1F4]
	cmp r0, 0
	bne _08097EF0
	movs r4, 0
	b _08097EBA
	.align 2, 0
_08097EB4: .4byte gStatusDescriptions
_08097EB8:
	adds r4, 0x1
_08097EBA:
	cmp r4, r9
	bge _08097ED6
	adds r0, r5, r3
	lsls r1, r4, 2
	ldr r2, [sp, 0x1F0]
	adds r1, r2
	ldr r1, [r1]
	str r3, [sp, 0x1F4]
	bl sub_8097DD0
	lsls r0, 24
	ldr r3, [sp, 0x1F4]
	cmp r0, 0
	beq _08097EB8
_08097ED6:
	cmp r4, r9
	bne _08097EF0
	mov r0, r9
	cmp r0, 0x3
	bgt _08097EF0
	adds r0, r5, r3
	mov r1, r10
	adds r1, 0x4
	mov r10, r1
	subs r1, 0x4
	stm r1!, {r0}
	movs r2, 0x1
	add r9, r2
_08097EF0:
	adds r7, r6, 0
	cmp r6, 0x62
	bgt _08097F20
	ldr r1, _08097F04
	lsls r0, r6, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _08097E90
	b _08097F20
	.align 2, 0
_08097F04: .4byte gStatusDescriptions
_08097F08:
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r1, 0
	adds r0, 0x7F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08097F1C
	cmp r1, 0x87
	bne _08097F20
_08097F1C:
	movs r1, 0x1
	add r8, r1
_08097F20:
	movs r2, 0x1
	add r8, r2
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	bne _08097E78
_08097F2C:
	mov r0, r9
	add sp, 0x1F8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8097DF0

	thumb_func_start sub_8097F40
sub_8097F40:
	push {lr}
	movs r2, 0
	ldr r1, _08097F58
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08097F50
	movs r2, 0x1
_08097F50:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.align 2, 0
_08097F58: .4byte gUnknown_810ACC0
	thumb_func_end sub_8097F40

	thumb_func_start sub_8097F5C
sub_8097F5C:
	ldr r1, _08097F64
	ldr r0, _08097F68
	str r0, [r1]
	bx lr
	.align 2, 0
_08097F64: .4byte gUnknown_203B498
_08097F68: .4byte gUnknown_2039840
	thumb_func_end sub_8097F5C

	thumb_func_start sub_8097F6C
sub_8097F6C:
	ldr r0, _08097F70
	bx lr
	.align 2, 0
_08097F70: .4byte gUnknown_2039840
	thumb_func_end sub_8097F6C

	thumb_func_start sub_8097F74
sub_8097F74:
	push {r4,lr}
	ldr r4, _08097FA0
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x64
	bl memset
	movs r2, 0
	ldr r3, _08097FA4
_08097F86:
	ldr r0, [r4]
	adds r0, 0x58
	adds r0, r2
	ldrb r1, [r3, 0x2]
	strb r1, [r0]
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0xB
	ble _08097F86
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097FA0: .4byte gUnknown_203B498
_08097FA4: .4byte gUnknown_810AD0C
	thumb_func_end sub_8097F74

	thumb_func_start sub_8097FA8
sub_8097FA8:
	lsls r0, 24
	ldr r1, _08097FCC
	ldr r3, [r1]
	lsrs r1, r0, 29
	lsls r1, 2
	adds r3, 0x48
	adds r3, r1
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	bx lr
	.align 2, 0
_08097FCC: .4byte gUnknown_203B498
	thumb_func_end sub_8097FA8

	thumb_func_start sub_8097FD0
sub_8097FD0:
	lsls r0, 24
	ldr r1, _08097FF4
	ldr r3, [r1]
	lsrs r1, r0, 29
	lsls r1, 2
	adds r3, 0x3C
	adds r3, r1
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	bx lr
	.align 2, 0
_08097FF4: .4byte gUnknown_203B498
	thumb_func_end sub_8097FD0

	thumb_func_start sub_8097FF8
sub_8097FF8:
	push {r4-r7,lr}
	movs r4, 0
	ldr r6, _08098040
	movs r7, 0x1
_08098000:
	ldr r5, [r6]
	adds r0, r4, 0
	cmp r4, 0
	bge _0809800A
	adds r0, 0x1F
_0809800A:
	asrs r0, 5
	lsls r3, r0, 2
	adds r1, r5, 0
	adds r1, 0x48
	adds r1, r3
	lsls r0, 5
	subs r0, r4, r0
	adds r2, r7, 0
	lsls r2, r0
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	beq _08098030
	adds r1, r5, 0
	adds r1, 0x3C
	adds r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08098030:
	adds r4, 0x1
	cmp r4, 0x3F
	ble _08098000
	bl sub_8098080
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098040: .4byte gUnknown_203B498
	thumb_func_end sub_8097FF8

	thumb_func_start sub_8098044
sub_8098044:
	push {r4,r5,lr}
	lsls r0, 24
	ldr r1, _0809807C
	ldr r3, [r1]
	lsrs r5, r0, 29
	lsls r5, 2
	adds r4, r3, 0
	adds r4, 0x3C
	adds r4, r5
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	mvns r2, r2
	ldr r0, [r4]
	ands r0, r2
	str r0, [r4]
	adds r3, 0x48
	adds r3, r5
	ldr r0, [r3]
	ands r0, r2
	str r0, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809807C: .4byte gUnknown_203B498
	thumb_func_end sub_8098044

	thumb_func_start sub_8098080
sub_8098080:
	push {r4,lr}
	movs r2, 0
	ldr r4, _080980A0
	movs r3, 0
_08098088:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x48
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0x2
	ble _08098088
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080980A0: .4byte gUnknown_203B498
	thumb_func_end sub_8098080

	thumb_func_start sub_80980A4
sub_80980A4:
	ldr r0, _080980B0
	ldr r2, [r0]
	ldrb r0, [r2]
	movs r1, 0x1
	strb r1, [r2]
	bx lr
	.align 2, 0
_080980B0: .4byte gUnknown_203B498
	thumb_func_end sub_80980A4

	thumb_func_start sub_80980B4
sub_80980B4:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r3, r1, 0
	ldr r0, _080980F8
	cmp r1, r0
	beq _080980F4
	adds r0, 0x1
	cmp r1, r0
	beq _080980F4
	adds r0, 0x1
	cmp r1, r0
	beq _080980F4
	ldr r0, _080980FC
	ldr r2, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _080980DA
	adds r0, 0x1F
_080980DA:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x4
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080980F4:
	pop {r0}
	bx r0
	.align 2, 0
_080980F8: .4byte 0x000001a5
_080980FC: .4byte gUnknown_203B498
	thumb_func_end sub_80980B4

	thumb_func_start sub_8098100
sub_8098100:
	push {lr}
	lsls r1, r0, 24
	lsrs r3, r1, 24
	cmp r3, 0x3F
	bls _0809810E
	movs r0, 0
	b _0809812C
_0809810E:
	ldr r0, _08098130
	ldr r2, [r0]
	lsrs r0, r1, 29
	lsls r0, 2
	adds r2, 0x3C
	adds r2, r0
	movs r0, 0x1F
	ands r0, r3
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _0809812C
	movs r0, 0x1
_0809812C:
	pop {r1}
	bx r1
	.align 2, 0
_08098130: .4byte gUnknown_203B498
	thumb_func_end sub_8098100

	thumb_func_start sub_8098134
sub_8098134:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r3, r1, 0
	ldr r0, _0809816C
	ldr r2, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08098148
	adds r0, 0x1F
_08098148:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x4
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _08098166
	movs r0, 0x1
_08098166:
	pop {r1}
	bx r1
	.align 2, 0
_0809816C: .4byte gUnknown_203B498
	thumb_func_end sub_8098134

	thumb_func_start sub_8098170
sub_8098170:
	push {lr}
	adds r3, r0, 0
	ldr r0, _0809819C
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _08098180
	adds r0, 0x1F
_08098180:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x54
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0809819C: .4byte gUnknown_203B498
	thumb_func_end sub_8098170

	thumb_func_start sub_80981A0
sub_80981A0:
	push {lr}
	adds r3, r0, 0
	cmp r3, 0x1E
	ble _080981AC
	movs r0, 0
	b _080981D4
_080981AC:
	ldr r0, _080981D8
	ldr r2, [r0]
	adds r1, r3, 0
	cmp r3, 0
	bge _080981B8
	adds r1, 0x1F
_080981B8:
	asrs r1, 5
	lsls r0, r1, 2
	adds r2, 0x54
	adds r2, r0
	lsls r1, 5
	subs r1, r3, r1
	movs r0, 0x1
	lsls r0, r1
	ldr r2, [r2]
	ands r2, r0
	cmp r2, 0
	beq _080981D2
	movs r2, 0x1
_080981D2:
	adds r0, r2, 0
_080981D4:
	pop {r1}
	bx r1
	.align 2, 0
_080981D8: .4byte gUnknown_203B498
	thumb_func_end sub_80981A0

	thumb_func_start sub_80981DC
sub_80981DC:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r3, r0, 16
	movs r1, 0
	ldr r4, _080981FC
	ldr r2, _08098200
_080981E8:
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, r3
	bne _08098204
	ldr r0, [r4]
	adds r0, 0x58
	adds r0, r1
	ldrb r0, [r0]
	b _0809820E
	.align 2, 0
_080981FC: .4byte gUnknown_203B498
_08098200: .4byte gUnknown_810AD0C
_08098204:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0xB
	ble _080981E8
	movs r0, 0x1
_0809820E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80981DC

	thumb_func_start sub_8098214
sub_8098214:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r3, r0, 16
	movs r1, 0
	ldr r5, _08098240
	movs r4, 0x1
	ldr r2, _08098244
_08098222:
	movs r6, 0
	ldrsh r0, [r2, r6]
	cmp r0, r3
	bne _08098232
	ldr r0, [r5]
	adds r0, 0x58
	adds r0, r1
	strb r4, [r0]
_08098232:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0xB
	ble _08098222
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098240: .4byte gUnknown_203B498
_08098244: .4byte gUnknown_810AD0C
	thumb_func_end sub_8098214

	thumb_func_start sub_8098248
sub_8098248:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r7, r0, 0
	mov r5, sp
	adds r5, 0x3
	movs r0, 0xFF
	strb r0, [r5]
	add r4, sp, 0x4
	movs r0, 0
	strb r0, [r4]
	ldr r0, _08098300
	ldr r1, [r0]
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_809488C
	movs r6, 0
	mov r9, r5
	mov r8, r4
	mov r4, sp
	adds r4, 0x1
	mov r5, sp
	adds r5, 0x2
_0809827C:
	lsls r0, r6, 16
	asrs r0, 16
	bl sub_8098134
	mov r1, sp
	strb r0, [r1]
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	ldr r0, _08098304
	cmp r6, r0
	ble _0809827C
	movs r6, 0
_0809829A:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8098100
	strb r0, [r4]
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	cmp r6, 0x3F
	ble _0809829A
	movs r6, 0
	adds r4, r5, 0
_080982B8:
	adds r0, r6, 0
	bl sub_80981A0
	strb r0, [r4]
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	cmp r6, 0x1E
	ble _080982B8
	movs r6, 0
_080982D2:
	ldr r0, _08098300
	ldr r0, [r0]
	adds r0, 0x58
	adds r0, r6
	ldrb r0, [r0]
	mov r1, r8
	cmp r0, 0
	beq _080982E4
	mov r1, r9
_080982E4:
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	cmp r6, 0xB
	ble _080982D2
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098300: .4byte gUnknown_203B498
_08098304: .4byte 0x000001a7
	thumb_func_end sub_8098248

	thumb_func_start sub_8098308
sub_8098308:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r4, _080983D0
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x64
	bl memset
	ldr r1, [r4]
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8094924
	movs r4, 0
	mov r5, sp
	adds r5, 0x1
	mov r7, sp
	adds r7, 0x2
	movs r0, 0x3
	add r0, sp
	mov r8, r0
_08098338:
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098352
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_80980B4
_08098352:
	adds r4, 0x1
	ldr r0, _080983D4
	cmp r4, r0
	ble _08098338
	movs r4, 0
_0809835C:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094924
	ldrb r0, [r5]
	cmp r0, 0
	beq _08098374
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8097FA8
_08098374:
	adds r4, 0x1
	cmp r4, 0x3F
	ble _0809835C
	movs r4, 0
	adds r5, r7, 0
_0809837E:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094924
	ldrb r0, [r5]
	cmp r0, 0
	beq _08098394
	adds r0, r4, 0
	bl sub_8098170
_08098394:
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809837E
	movs r4, 0
_0809839C:
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0x1
	bl sub_8094924
	ldr r0, _080983D0
	ldr r1, [r0]
	adds r1, 0x58
	adds r1, r4
	mov r0, sp
	adds r0, 0x3
	ldrb r2, [r0]
	movs r0, 0x1
	ands r0, r2
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0xB
	ble _0809839C
	bl sub_8097FF8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080983D0: .4byte gUnknown_203B498
_080983D4: .4byte 0x000001a7
	thumb_func_end sub_8098308

	thumb_func_start sub_80983D8
sub_80983D8:
	push {r4,lr}
	movs r2, 0
	ldrsh r3, [r1, r2]
	movs r4, 0
	ldrsh r2, [r0, r4]
	subs r2, r3, r2
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	subs r1, r0
	cmp r2, 0
	bne _080983FA
	cmp r1, 0
	bne _080983FA
	movs r0, 0
	b _08098428
_080983FA:
	cmp r2, 0
	ble _08098400
	movs r2, 0x1
_08098400:
	cmp r1, 0
	ble _08098406
	movs r1, 0x1
_08098406:
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bgt _08098410
	adds r2, r0, 0
_08098410:
	cmp r1, r0
	bgt _08098416
	adds r1, r0, 0
_08098416:
	ldr r3, _08098430
	adds r2, 0x1
	adds r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
_08098428:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08098430: .4byte gUnknown_8115E94
	thumb_func_end sub_80983D8

	thumb_func_start sub_8098434
sub_8098434:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r2, 0
	ldrsh r0, [r4, r2]
	subs r2, r1, r0
	cmp r2, 0
	bge _0809844A
	negs r2, r2
_0809844A:
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, 0
	bge _0809845A
	negs r0, r0
_0809845A:
	cmp r0, r2
	bge _08098460
	adds r0, r2, 0
_08098460:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098434

        .align 2,0
