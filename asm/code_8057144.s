	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8057144
sub_8057144:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x144
	mov r9, r0
	movs r7, 0
	movs r5, 0
_08057154:
	ldr r0, _080571D4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080571D8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r5, 0x1
	mov r8, r5
	cmp r0, 0
	beq _080571B8
	ldr r0, [r4, 0x70]
	movs r1, 0x8C
	lsls r1, 1
	adds r5, r0, r1
	adds r4, r5, 0
	lsls r0, r7, 2
	mov r1, sp
	adds r2, r0, r1
	movs r6, 0x3
_08057184:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080571AE
	ldrh r1, [r4, 0x2]
	mov r0, r9
	str r2, [sp, 0x140]
	bl sub_805755C
	lsls r0, 24
	ldr r2, [sp, 0x140]
	cmp r0, 0
	bne _080571AE
	ldrh r0, [r4, 0x2]
	cmp r0, 0x8A
	beq _080571AE
	cmp r7, 0x4F
	bgt _080571AE
	stm r2!, {r5}
	adds r7, 0x1
_080571AE:
	adds r4, 0x8
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _08057184
_080571B8:
	mov r5, r8
	cmp r5, 0x13
	ble _08057154
	cmp r7, 0
	beq _080571DC
	adds r0, r7, 0
	bl DungeonRandomCapped
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	ldrh r0, [r0, 0x2]
	b _080571DE
	.align 2, 0
_080571D4: .4byte gDungeonGlobalData
_080571D8: .4byte 0x000135cc
_080571DC:
	ldr r0, _080571EC
_080571DE:
	add sp, 0x144
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080571EC: .4byte 0x00000163
	thumb_func_end sub_8057144

	thumb_func_start sub_80571F0
sub_80571F0:
	push {lr}
	ldr r0, [r0, 0x70]
	adds r2, r0, 0
	adds r2, 0xFF
	ldrb r2, [r2]
	cmp r2, 0x1
	bne _08057212
	ldrh r1, [r1, 0x2]
	cmp r1, 0x88
	beq _08057274
	cmp r1, 0xA2
	beq _08057274
	cmp r1, 0x39
	beq _08057274
	cmp r1, 0x40
	beq _08057274
	b _08057264
_08057212:
	cmp r2, 0x2
	bne _08057274
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x9
	bne _0805722A
	ldrh r1, [r1, 0x2]
	cmp r1, 0x20
	beq _08057274
	cmp r1, 0xDB
	bne _08057264
	b _08057274
_0805722A:
	cmp r0, 0xA
	bne _08057264
	ldrh r1, [r1, 0x2]
	cmp r1, 0x76
	beq _08057274
	movs r0, 0x94
	lsls r0, 1
	cmp r1, r0
	beq _08057274
	cmp r1, 0x77
	bne _08057264
	ldr r0, _08057268
	ldr r0, [r0]
	ldr r1, _0805726C
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _08057252
	movs r1, 0
_08057252:
	cmp r1, 0x4A
	ble _08057258
	movs r1, 0x4A
_08057258:
	ldr r0, _08057270
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0x76
	beq _08057274
_08057264:
	movs r0, 0x1
	b _08057276
	.align 2, 0
_08057268: .4byte gDungeonGlobalData
_0805726C: .4byte 0x00003a0e
_08057270: .4byte gUnknown_80F5D10
_08057274:
	movs r0, 0
_08057276:
	pop {r1}
	bx r1
	thumb_func_end sub_80571F0

	thumb_func_start sub_805727C
sub_805727C:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080572FC
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080572FC
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080572FC
	ldr r1, [r5, 0x70]
	movs r2, 0xAC
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080572FC
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080572FC
	cmp r4, 0
	beq _080572DE
	adds r0, r6, 0
	movs r1, 0x26
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080572D2
	lsls r0, r4, 1
	b _080572D4
_080572D2:
	adds r0, r4, 0
_080572D4:
	bl sub_8084160
	lsls r0, 24
	lsrs r4, r0, 24
	b _080572E0
_080572DE:
	movs r4, 0x1
_080572E0:
	cmp r4, 0
	beq _08057300
	cmp r6, r5
	beq _08057300
	adds r0, r5, 0
	movs r1, 0x4C
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08057300
	adds r0, r5, 0
	bl sub_80429C8
_080572FC:
	movs r0, 0
	b _08057302
_08057300:
	adds r0, r4, 0
_08057302:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805727C

	thumb_func_start sub_8057308
sub_8057308:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0805731C
	movs r0, 0
	b _08057340
_0805731C:
	cmp r4, 0
	bne _08057324
	movs r0, 0x1
	b _08057340
_08057324:
	adds r0, r5, 0
	movs r1, 0x26
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _08057336
	adds r0, r4, 0
	b _08057338
_08057336:
	lsls r0, r4, 1
_08057338:
	bl sub_8084160
	lsls r0, 24
	lsrs r0, 24
_08057340:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8057308

	thumb_func_start sub_8057348
sub_8057348:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r6, [r7, 0x70]
	lsls r1, 3
	movs r0, 0x8C
	lsls r0, 1
	adds r1, r0
	adds r4, r6, r1
	ldrb r1, [r4]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080573BE
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080573BE
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080573BE
	ldrb r1, [r4, 0x1]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0805738E
	b _080573BE
_0805738A:
	movs r0, 0x1
	b _080573C0
_0805738E:
	movs r5, 0
	b _08057394
_08057392:
	adds r5, 0x1
_08057394:
	cmp r5, 0x3
	bgt _080573BE
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, r8
	bl sub_80573CC
	lsls r0, 24
	cmp r0, 0
	bne _0805738A
	adds r4, 0x8
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r6, r1
	cmp r4, r0
	bcs _080573BE
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08057392
_080573BE:
	movs r0, 0
_080573C0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8057348

	thumb_func_start sub_80573CC
sub_80573CC:
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r6, [r0, 0x70]
	ldrh r1, [r4, 0x2]
	ldr r0, _08057430
	cmp r1, r0
	beq _08057442
	ldrb r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0805743E
	ldrb r1, [r4, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805743E
	cmp r2, 0
	beq _08057442
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _0805743E
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x5
	bne _08057414
	adds r0, r4, 0
	bl sub_8092C54
	lsls r0, 24
	cmp r0, 0
	beq _0805743E
_08057414:
	ldrb r0, [r5]
	cmp r0, 0x6
	bne _08057442
	ldrh r1, [r4, 0x2]
	movs r0, 0xB0
	lsls r0, 1
	cmp r1, r0
	bne _08057434
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	b _08057436
	.align 2, 0
_08057430: .4byte 0x00000163
_08057434:
	ldrb r1, [r4]
_08057436:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08057442
_0805743E:
	movs r0, 0
	b _08057444
_08057442:
	movs r0, 0x1
_08057444:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80573CC

	thumb_func_start sub_805744C
sub_805744C:
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r6, [r0, 0x70]
	ldrh r1, [r4, 0x2]
	ldr r0, _080574A8
	cmp r1, r0
	beq _080574BA
	ldrb r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080574B6
	ldrb r1, [r4, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080574B6
	cmp r2, 0
	beq _080574BA
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x5
	bne _0805748E
	adds r0, r4, 0
	bl sub_8092C54
	lsls r0, 24
	cmp r0, 0
	beq _080574B6
_0805748E:
	ldrb r0, [r5]
	cmp r0, 0x6
	bne _080574BA
	ldrh r1, [r4, 0x2]
	movs r0, 0xB0
	lsls r0, 1
	cmp r1, r0
	bne _080574AC
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	b _080574AE
	.align 2, 0
_080574A8: .4byte 0x00000163
_080574AC:
	ldrb r1, [r4]
_080574AE:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080574BA
_080574B6:
	movs r0, 0
	b _080574BC
_080574BA:
	movs r0, 0x1
_080574BC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805744C

	thumb_func_start sub_80574C4
sub_80574C4:
	push {r4-r6,lr}
	sub sp, 0x104
	adds r4, r0, 0
	adds r5, r1, 0
	movs r3, 0
	movs r2, 0
	ldr r0, [r4]
	cmp r0, 0
	beq _08057502
	cmp r0, r5
	beq _080574EA
_080574DA:
	lsls r0, r3, 2
	mov r6, sp
	adds r1, r6, r0
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r3, 0x1
_080574EA:
	adds r2, 0x1
	cmp r2, 0x40
	bgt _08057502
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _08057502
	cmp r0, r5
	beq _080574EA
	cmp r3, 0x3F
	ble _080574DA
_08057502:
	movs r2, 0
	ldr r0, [r4]
	b _08057524
_08057508:
	lsls r0, r3, 2
	mov r6, sp
	adds r1, r6, r0
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r3, 0x1
_08057518:
	adds r2, 0x1
	cmp r2, 0x40
	bgt _08057530
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
_08057524:
	cmp r0, 0
	beq _08057530
	cmp r0, r5
	bne _08057518
	cmp r3, 0x3F
	ble _08057508
_08057530:
	cmp r3, 0x40
	bgt _08057542
	movs r1, 0
	lsls r0, r3, 2
	add r0, sp
_0805753A:
	stm r0!, {r1}
	adds r3, 0x1
	cmp r3, 0x40
	ble _0805753A
_08057542:
	mov r3, sp
	adds r1, r4, 0
	movs r2, 0x40
_08057548:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x1
	cmp r2, 0
	bge _08057548
	add sp, 0x104
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80574C4

	thumb_func_start sub_805755C
sub_805755C:
	push {r4,lr}
	lsls r1, 16
	lsrs r4, r1, 16
	cmp r4, 0x97
	bne _08057576
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08057576
	movs r0, 0
	b _08057580
_08057576:
	adds r0, r4, 0
	bl sub_809422C
	lsls r0, 24
	lsrs r0, 24
_08057580:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_805755C

	thumb_func_start sub_8057588
sub_8057588:
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080575F8
	ldr r5, [r4, 0x70]
	movs r3, 0
_0805759E:
	lsls r0, r3, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	adds r4, r3, 0x1
	cmp r0, 0
	beq _080575F2
	movs r3, 0x1
	ldrb r1, [r2, 0x1]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080575C8
	movs r0, 0xEF
	ands r0, r1
	strb r0, [r2, 0x1]
	movs r3, 0x2
_080575C8:
	ldrb r1, [r2, 0x1]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080575F2
	movs r0, 0xF7
	ands r0, r1
	strb r0, [r2, 0x1]
	cmp r6, 0
	beq _080575F2
	cmp r3, 0
	beq _080575F2
	adds r1, r3, 0
_080575E2:
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	beq _080575EC
	subs r0, 0x1
	strb r0, [r2, 0x4]
_080575EC:
	subs r1, 0x1
	cmp r1, 0
	bne _080575E2
_080575F2:
	adds r3, r4, 0
	cmp r3, 0x3
	ble _0805759E
_080575F8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8057588

	thumb_func_start sub_8057600
sub_8057600:
	push {r4,lr}
	ldrh r4, [r0, 0x2]
	adds r0, r1, 0
	bl sub_8057620
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_8094828
	lsls r0, 16
	asrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8057600

	thumb_func_start sub_8057620
sub_8057620:
	push {lr}
	cmp r0, 0
	beq _0805762C
	lsls r0, 24
	lsrs r0, 24
	b _0805762E
_0805762C:
	movs r0, 0
_0805762E:
	pop {r1}
	bx r1
	thumb_func_end sub_8057620

	thumb_func_start sub_8057634
sub_8057634:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08057678
	movs r7, 0x1
	ldr r0, _08057684
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08057678
	ldr r0, _08057688
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_8076F80
_08057678:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057684: .4byte gUnknown_80F4DB4
_08057688: .4byte gUnknown_8106A4C
	thumb_func_end sub_8057634

	thumb_func_start sub_805768C
sub_805768C:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r3, 0
	movs r6, 0
	ldr r4, _080576B8
	ldr r3, [r4]
	adds r3, 0x1
	str r3, [r4]
	ldr r4, _080576BC
	lsls r3, 2
	adds r3, r4
	ldr r3, [r3]
	str r5, [sp]
	bl sub_8055640
	cmp r0, 0
	bne _080576C4
	ldr r1, _080576C0
	movs r0, 0x1
	strb r0, [r1]
	b _080576C6
	.align 2, 0
_080576B8: .4byte gUnknown_202F21C
_080576BC: .4byte gUnknown_8106A54
_080576C0: .4byte gUnknown_202F220
_080576C4:
	movs r6, 0x1
_080576C6:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805768C

	thumb_func_start sub_80576D0
sub_80576D0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _080576F4
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r2, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8075F34
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080576F4: .4byte gUnknown_80F4F28
	thumb_func_end sub_80576D0

	thumb_func_start sub_80576F8
sub_80576F8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _0805771C
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8075C58
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805771C: .4byte gUnknown_80F4E74
	thumb_func_end sub_80576F8

	thumb_func_start sub_8057720
sub_8057720:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _08057744
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8075DBC
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08057744: .4byte gUnknown_80F4E78
	thumb_func_end sub_8057720

	thumb_func_start sub_8057748
sub_8057748:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, _08057778
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08057778: .4byte gUnknown_80F502A
	thumb_func_end sub_8057748

	thumb_func_start sub_805777C
sub_805777C:
	push {lr}
	bl sub_8079DB8
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805777C

	thumb_func_start sub_8057788
sub_8057788:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	mov r8, r3
	movs r0, 0
	mov r9, r0
	adds r0, r4, 0
	bl sub_8045128
	adds r5, r0, 0
	bl sub_804AF20
	lsls r0, 24
	cmp r0, 0
	beq _080577BA
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _080577CC
_080577BA:
	ldr r0, _080577C8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _0805780E
	.align 2, 0
_080577C8: .4byte gUnknown_80FD14C
_080577CC:
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80570AC
	lsls r0, 24
	cmp r0, 0
	beq _080577F8
	ldr r0, _080577F4
	ldr r3, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_8055640
	adds r0, r4, 0
	bl sub_8079764
	b _0805780A
	.align 2, 0
_080577F4: .4byte gUnknown_80F4F68
_080577F8:
	ldr r0, _08057820
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8079618
_0805780A:
	movs r0, 0x1
	mov r9, r0
_0805780E:
	mov r0, r9
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057820: .4byte gUnknown_80FAD4C
	thumb_func_end sub_8057788

        .align 2,0 @ Don't pad with nop
