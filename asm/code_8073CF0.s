	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

  	.syntax unified

  	.text


	thumb_func_start sub_8075050
sub_8075050:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	adds r6, r1, 0
	ldr r0, _08075070
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08075078
	ldr r1, _08075074
	movs r0, 0x2
	b _0807507C
	.align 2, 0
_08075070: .4byte gGameOptionsRef
_08075074: .4byte gUnknown_202F378
_08075078:
	ldr r1, _080750D0
	movs r0, 0x1
_0807507C:
	str r0, [r1]
	movs r1, 0xFA
	lsls r1, 1
	add r1, r9
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080750D4
	ldr r0, _080750D0
	ldr r1, [r0]
	lsls r1, 1
	movs r0, 0x18
	bl __divsi3
	movs r1, 0xCE
	lsls r1, 1
	add r1, r9
	strh r0, [r1]
	movs r2, 0xCA
	lsls r2, 1
	add r2, r9
	ldr r1, [r2]
	lsls r1, 1
	str r1, [r2]
	movs r2, 0xCC
	lsls r2, 1
	add r2, r9
	ldr r1, [r2]
	lsls r1, 1
	str r1, [r2]
	strh r0, [r6, 0x18]
	ldr r0, [r6, 0x10]
	lsls r0, 1
	str r0, [r6, 0x10]
	ldr r0, [r6, 0x14]
	lsls r0, 1
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_080750D0: .4byte gUnknown_202F378
_080750D4:
	cmp r0, 0x3
	bne _08075160
	ldr r1, [r6, 0x10]
	str r1, [sp]
	ldr r0, [r6, 0x14]
	str r0, [sp, 0x4]
	movs r4, 0xCE
	lsls r4, 1
	add r4, r9
	movs r5, 0
	movs r7, 0x1
_080750EA:
	ldr r1, _0807515C
	ldr r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	movs r0, 0x18
	bl __divsi3
	strh r0, [r4]
	movs r3, 0xCA
	lsls r3, 1
	add r3, r9
	adds r3, r5
	ldr r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r3]
	movs r2, 0xCC
	lsls r2, 1
	add r2, r9
	adds r2, r5
	ldr r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r3]
	ldr r0, [r2]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r2]
	adds r4, 0x1C
	adds r5, 0x1C
	subs r7, 0x1
	cmp r7, 0
	bge _080750EA
	ldr r1, _0807515C
	ldr r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
	ldr r1, [sp]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r6, 0x10]
	ldr r1, [sp, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_0807515C: .4byte gUnknown_202F378
_08075160:
	cmp r0, 0x4
	bne _080751EC
	ldr r0, [r6, 0x10]
	str r0, [sp]
	ldr r1, [r6, 0x14]
	str r1, [sp, 0x4]
	movs r7, 0xCE
	lsls r7, 1
	add r7, r9
	movs r0, 0
	mov r8, r0
	movs r1, 0x2
	mov r10, r1
_0807517A:
	ldr r0, _080751E8
	ldr r1, [r0]
	lsls r1, 2
	movs r0, 0x18
	bl __divsi3
	strh r0, [r7]
	movs r4, 0xCA
	lsls r4, 1
	add r4, r9
	add r4, r8
	ldr r0, [r4]
	lsls r0, 2
	str r0, [r4]
	movs r5, 0xCC
	lsls r5, 1
	add r5, r9
	add r5, r8
	ldr r0, [r5]
	lsls r0, 2
	str r0, [r5]
	ldr r0, [r4]
	movs r1, 0x3
	bl __divsi3
	str r0, [r4]
	ldr r0, [r5]
	movs r1, 0x3
	bl __divsi3
	str r0, [r5]
	adds r7, 0x1C
	movs r1, 0x1C
	add r8, r1
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r1, r10
	cmp r1, 0
	bge _0807517A
	ldr r0, _080751E8
	ldr r1, [r0]
	lsls r1, 2
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
	ldr r1, [sp]
	lsls r0, r1, 2
	str r0, [r6, 0x10]
	ldr r1, [sp, 0x4]
	lsls r0, r1, 2
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_080751E8: .4byte gUnknown_202F378
_080751EC:
	ldr r0, _08075208
	ldr r1, [r0]
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
_080751F8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075208: .4byte gUnknown_202F378
	thumb_func_end sub_8075050

	thumb_func_start UseAttack
UseAttack:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	movs r7, 0
	movs r0, 0
	mov r9, r0
	ldr r0, _08075238
	mov r1, r9
	strb r1, [r0]
	ldr r0, _0807523C
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08075244
	ldr r1, _08075240
	movs r0, 0x2
	b _08075248
	.align 2, 0
_08075238: .4byte gUnknown_202F32D
_0807523C: .4byte gGameOptionsRef
_08075240: .4byte gUnknown_202F378
_08075244:
	ldr r1, _080752D0
	movs r0, 0x1
_08075248:
	str r0, [r1]
	movs r2, 0
	mov r8, r2
_0807524E:
	ldr r0, _080752D4
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, 2
	ldr r4, _080752D8
	adds r0, r4
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807534C
	ldr r4, [r5, 0x70]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	cmp r2, 0
	bne _080752E0
	ldr r0, _080752DC
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807534C
	strb r2, [r1]
	movs r1, 0xB6
	lsls r1, 1
	adds r6, r4, r1
	ldr r1, [r6]
	cmp r1, 0
	beq _0807534C
	ldr r0, [r5, 0x4]
	cmp r1, r0
	beq _0807534C
	adds r0, r5, 0
	movs r1, 0x1
	bl CheckVariousStatuses2
	lsls r0, 24
	cmp r0, 0
	beq _080752B2
	adds r0, r5, 0
	bl CheckVariousStatuses
	lsls r0, 24
	cmp r0, 0
	bne _0807534C
_080752B2:
	adds r0, r5, 0x4
	adds r1, r6, 0
	bl GetDirectionTowardsPosition
	adds r1, r0, 0
	adds r0, r4, 0
	adds r0, 0x46
	ldrb r0, [r0]
	cmp r1, r0
	beq _0807534C
	adds r0, r5, 0
	bl sub_806CE68
	b _0807534C
	.align 2, 0
_080752D0: .4byte gUnknown_202F378
_080752D4: .4byte gDungeon
_080752D8: .4byte 0x000135cc
_080752DC: .4byte 0x00000147
_080752E0:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r4]
	movs r3, 0xC4
	lsls r3, 1
	adds r0, r4, r3
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [sp]
	movs r2, 0xC6
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r3, 0x80
	lsls r3, 5
	adds r0, r3
	str r0, [sp, 0x4]
	adds r0, r5, 0
	mov r1, sp
	bl sub_804535C
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_806CDFC
	movs r2, 0xFB
	lsls r2, 1
	adds r0, r4, r2
	movs r3, 0
	strh r3, [r0]
	movs r7, 0x1
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807534C
	movs r4, 0x1
	mov r9, r4
_0807534C:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x13
	bgt _08075358
	b _0807524E
_08075358:
	cmp r7, 0
	bne _08075360
	movs r0, 0
	b _0807566C
_08075360:
	ldr r0, _08075390
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xB8
	ldr r2, [r1]
	str r2, [sp, 0x10]
	mov r3, r10
	str r3, [r1]
	ldr r4, _08075394
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807537C
	b _080754AE
_0807537C:
	mov r0, r9
	cmp r0, 0
	bne _08075384
	b _080754AE
_08075384:
	movs r0, 0x35
	bl sub_80526D0
	movs r5, 0
	b _0807549E
	.align 2, 0
_08075390: .4byte gDungeon
_08075394: .4byte 0x0000066c
_08075398:
	movs r0, 0x7
	bl sub_803E46C
	movs r1, 0
	mov r8, r1
	adds r5, 0x1
	mov r9, r5
_080753A6:
	ldr r0, _08075420
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, _08075424
	adds r0, r3
	adds r0, r1
	ldr r3, [r0]
	adds r0, r3, 0
	str r3, [sp, 0x14]
	bl EntityExists
	lsls r0, 24
	ldr r3, [sp, 0x14]
	cmp r0, 0
	beq _08075492
	ldr r0, [r3, 0x70]
	adds r7, r0, 0
	movs r4, 0xFB
	lsls r4, 1
	adds r5, r7, r4
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	movs r2, 0xC2
	lsls r2, 1
	adds r1, r2
	adds r4, r7, r1
	movs r0, 0xFA
	lsls r0, 1
	adds r6, r7, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _08075492
	ldr r1, [r4, 0x10]
	ldr r2, [r4, 0x14]
	adds r0, r3, 0
	bl IncreaseEntityPixelPos
	ldrh r0, [r4, 0x18]
	subs r0, 0x1
	strh r0, [r4, 0x18]
	lsls r0, 16
	asrs r2, r0, 16
	ldr r3, [sp, 0x14]
	cmp r2, 0
	bne _08075492
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	movs r4, 0
	ldrsh r1, [r6, r4]
	cmp r0, r1
	bne _08075428
	strh r2, [r6]
	b _08075492
	.align 2, 0
_08075420: .4byte gDungeon
_08075424: .4byte 0x000135cc
_08075428:
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	movs r2, 0xC4
	lsls r2, 1
	adds r1, r7, r2
	adds r1, r0
	ldr r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r4, 0xC0
	lsls r4, 4
	adds r0, r4
	str r0, [sp, 0x8]
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r1, r7, r2
	adds r1, r0
	ldr r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r4, 0x80
	lsls r4, 5
	adds r0, r4
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	adds r0, r3, 0
	str r3, [sp, 0x14]
	bl sub_804535C
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	movs r2, 0xC8
	lsls r2, 1
	adds r1, r7, r2
	adds r1, r0
	ldr r2, [r1]
	ldr r3, [sp, 0x14]
	adds r0, r3, 0
	movs r1, 0
	bl sub_806CDFC
_08075492:
	movs r3, 0x1
	add r8, r3
	mov r4, r8
	cmp r4, 0x13
	ble _080753A6
	mov r5, r9
_0807549E:
	ldr r0, _08075510
	ldr r1, [r0]
	movs r0, 0x18
	bl __divsi3
	cmp r5, r0
	bge _080754AE
	b _08075398
_080754AE:
	movs r0, 0
	mov r8, r0
_080754B2:
	ldr r0, _08075514
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, _08075518
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080754F6
	ldr r4, [r5, 0x70]
	movs r0, 0xFA
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	strh r0, [r1]
	adds r0, r5, 0
	bl nullsub_97
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080754F6
	adds r0, r5, 0
	movs r1, 0
	bl sub_804535C
_080754F6:
	movs r3, 0x1
	add r8, r3
	mov r4, r8
	cmp r4, 0x13
	ble _080754B2
	bl sub_807AA30
	movs r7, 0
_08075506:
	movs r5, 0
	adds r0, r7, 0x1
	mov r8, r0
	b _08075600
	.align 2, 0
_08075510: .4byte gUnknown_202F378
_08075514: .4byte gDungeon
_08075518: .4byte 0x000135cc
_0807551C:
	ldr r2, [r4, 0x70]
	cmp r7, 0
	bne _0807552A
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _080755FE
	b _08075530
_0807552A:
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	bne _080755FE
_08075530:
	ldr r6, [r4, 0x4]
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080755BC
	ldr r3, _08075560
	adds r0, r3, 0
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _08075564
	adds r0, r4, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
	bl sub_805EE30
	b _0807556A
	.align 2, 0
_08075560: .4byte 0x0000dfff
_08075564:
	adds r0, r4, 0
	bl sub_8075708
_0807556A:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	movs r0, 0
	bl sub_8043ED0
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	adds r0, r4, 0
	bl sub_8071DA4
	bl sub_8046D20
	ldr r0, _08075650
	ldr r0, [r0]
	ldr r1, _08075654
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8075900
_080755BC:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	ldr r0, [r4, 0x4]
	cmp r6, r0
	beq _080755DE
	ldr r1, _08075658
	movs r0, 0x1
	strb r0, [r1]
_080755DE:
	adds r0, r4, 0
	bl sub_806A5B8
	adds r1, r4, 0x4
	adds r0, r4, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_080755FE:
	adds r5, 0x1
_08075600:
	cmp r5, 0x13
	bgt _0807562A
	ldr r0, _08075650
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807565C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	b _0807551C
_0807562A:
	mov r7, r8
	cmp r7, 0x1
	bgt _08075632
	b _08075506
_08075632:
	bl sub_8086AC0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08075660
	bl sub_8085140
	ldr r0, _08075650
	ldr r0, [r0]
	adds r0, 0xB8
	ldr r3, [sp, 0x10]
	str r3, [r0]
	b _0807566A
	.align 2, 0
_08075650: .4byte gDungeon
_08075654: .4byte 0x00003a08
_08075658: .4byte gUnknown_202F32D
_0807565C: .4byte 0x000135cc
_08075660:
	ldr r0, _0807567C
	ldr r0, [r0]
	adds r0, 0xB8
	ldr r4, [sp, 0x10]
	str r4, [r0]
_0807566A:
	movs r0, 0x1
_0807566C:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807567C: .4byte gDungeon
	thumb_func_end UseAttack

        .align 2,0
