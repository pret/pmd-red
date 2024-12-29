	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

@ https://decomp.me/scratch/67fVt (kermalis 92.38%)
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

@ https://decomp.me/scratch/verq3 (kermalis 97.1%)
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
	bl EntityIsValid
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
	bl GetTile
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
_08085444: .4byte gDungeon
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

	.align 2, 0
