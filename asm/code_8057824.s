	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start SketchMoveAction
SketchMoveAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	movs r0, 0
	mov r10, r0
	ldr r1, [r6, 0x70]
	str r1, [sp]
	ldr r0, [r7, 0x70]
	movs r2, 0
	mov r12, r2
	movs r4, 0
	movs r1, 0x8C
	lsls r1, 1
	adds r3, r0, r1
	adds r1, r0, 0
	movs r2, 0x1
	mov r9, r2
	movs r0, 0x10
	mov r8, r0
_08059372:
	ldrb r2, [r3]
	mov r0, r9
	ands r0, r2
	cmp r0, 0
	beq _08059384
	mov r0, r8
	ands r0, r2
	cmp r0, 0
	bne _080593A8
_08059384:
	adds r3, 0x8
	adds r1, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08059372
	movs r0, 0
	cmp r0, 0
	bne _080593B2
	ldr r0, _080593A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	movs r0, 0
	b _0805940A
	.align 2, 0
_080593A4: .4byte gUnknown_80FE3BC
_080593A8:
	movs r2, 0x8D
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	mov r12, r0
_080593B2:
	mov r0, r12
	cmp r0, 0
	bne _080593CC
	ldr r0, _080593C8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _08059408
	.align 2, 0
_080593C8: .4byte gUnknown_80FE3BC
_080593CC:
	adds r0, r5, 0
	mov r1, r12
	bl InitPokemonMove
	ldr r0, _0805941C
	adds r1, r5, 0
	movs r2, 0
	bl sub_80928C0
	ldrb r1, [r5, 0x1]
	movs r0, 0x4
	orrs r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r5, 0x1]
	ldr r0, _08059420
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	ldr r1, [sp]
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _08059404
	movs r0, 0x1
	strb r0, [r1]
_08059404:
	movs r1, 0x1
	mov r10, r1
_08059408:
	mov r0, r10
_0805940A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805941C: .4byte gUnknown_202DE58
_08059420: .4byte gUnknown_80FE38C
	thumb_func_end SketchMoveAction

	thumb_func_start sub_8059424
sub_8059424:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805945E
	movs r7, 0x1
	ldr r0, _08059468
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805945E
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl CringeStatusTarget
_0805945E:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059468: .4byte gUnknown_80F4DF0
	thumb_func_end sub_8059424

	thumb_func_start sub_805946C
sub_805946C:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	movs r6, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080594D2
	movs r6, 0x1
	adds r0, r5, 0
	movs r1, 0x7
	bl HasAbility
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080594D2
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _080594D2
	ldr r0, [r5, 0x70]
	movs r1, 0x10
	ldrsh r2, [r0, r1]
	cmp r2, 0
	bge _080594B0
	adds r2, 0x7
_080594B0:
	asrs r2, 3
	cmp r2, 0
	bne _080594B8
	movs r2, 0x1
_080594B8:
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r0, _080594DC
	str r0, [sp, 0x8]
	movs r0, 0x14
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	str r4, [sp, 0x14]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r3, 0
	bl sub_806F370
_080594D2:
	adds r0, r6, 0
	add sp, 0x18
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080594DC: .4byte 0x000001fd
	thumb_func_end sub_805946C

	thumb_func_start sub_80594E0
sub_80594E0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _08059518
	ldr r0, [r0]
	ldr r1, _0805951C
	ldrh r1, [r1]
	ldr r2, _08059520
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x1
	movs r1, 0
	bl sub_807EAA0
	lsls r0, 24
	cmp r0, 0
	bne _0805950E
	ldr r0, _08059524
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_0805950E:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08059518: .4byte gDungeon
_0805951C: .4byte gUnknown_80F4F42
_08059520: .4byte 0x0000e269
_08059524: .4byte gUnknown_80FCF78
	thumb_func_end sub_80594E0

	thumb_func_start sub_8059528
sub_8059528:
	push {lr}
	ldr r2, _0805953C
	ldr r2, [r2]
	movs r3, 0x1
	bl LowerAccuracyStageTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805953C: .4byte gUnknown_8106A4C
	thumb_func_end sub_8059528

	thumb_func_start sub_8059540
sub_8059540:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805957A
	movs r7, 0x1
	ldr r0, _08059584
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805957A
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl PoisonedStatusTarget
_0805957A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059584: .4byte gUnknown_80F4DC4
	thumb_func_end sub_8059540

	thumb_func_start sub_8059588
sub_8059588:
	push {lr}
	ldr r2, _0805959C
	ldr r2, [r2]
	movs r3, 0x1
	bl RaiseAttackStageTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805959C: .4byte gUnknown_8106A50
	thumb_func_end sub_8059588

	thumb_func_start sub_80595A0
sub_80595A0:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080595DC
	movs r7, 0x1
	ldr r0, _080595E8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080595DC
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl BurnedStatusTarget
_080595DC:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080595E8: .4byte gUnknown_80F4DE0
	thumb_func_end sub_80595A0

	thumb_func_start sub_80595EC
sub_80595EC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	mov r9, r0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	movs r7, 0
	add r0, sp, 0x18
	strb r7, [r0]
	adds r0, r5, 0
	bl GetMoveType
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_806F4A4
	lsls r0, 24
	cmp r0, 0
	bne _08059630
	ldr r0, _0805962C
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _08059678
	.align 2, 0
_0805962C: .4byte gUnknown_80FEB8C
_08059630:
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r2, _08059688
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r7, [sp, 0x14]
	mov r0, r9
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059672
	movs r2, 0x1
_08059672:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
_08059678:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059688: .4byte 0x0000270f
	thumb_func_end sub_80595EC

	thumb_func_start sub_805968C
sub_805968C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	mov r8, r1
	adds r6, r2, 0
	adds r7, r3, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	beq _080596B6
	adds r0, r5, 0
	adds r1, r6, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _080596EC
_080596B6:
	ldr r0, _080596E8
	ldr r3, [r0]
	cmp r4, 0x2
	beq _080596C6
	cmp r4, 0x4
	beq _080596C6
	cmp r4, 0x5
	bne _080596CC
_080596C6:
	lsrs r0, r3, 31
	adds r0, r3, r0
	asrs r3, r0, 1
_080596CC:
	str r7, [sp]
	adds r0, r5, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r5, 0
	bl sub_8079764
	b _08059700
	.align 2, 0
_080596E8: .4byte gUnknown_80F4F48
_080596EC:
	ldr r0, _08059710
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x2
	adds r3, r6, 0
	bl sub_8079618
	movs r4, 0x1
_08059700:
	adds r0, r4, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059710: .4byte gUnknown_80FACE4
	thumb_func_end sub_805968C

	thumb_func_start sub_8059714
sub_8059714:
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x1C
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0805978C
	movs r3, 0
	ldrsh r2, [r1, r3]
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r5, [sp, 0x14]
	mov r0, r9
	mov r1, r10
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059774
	movs r2, 0x1
_08059774:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805978C: .4byte gUnknown_80F4F7C
	thumb_func_end sub_8059714

	thumb_func_start sub_8059790
sub_8059790:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	adds r1, r4, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _080597CC
	ldr r0, _080597C8
	ldr r3, [r0]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r5, 0
	bl sub_8079764
	b _080597E0
	.align 2, 0
_080597C8: .4byte gUnknown_80F4F5C
_080597CC:
	ldr r0, _080597EC
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x7
	adds r3, r4, 0
	bl sub_8079618
	movs r4, 0x1
_080597E0:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080597EC: .4byte gUnknown_80FACFC
	thumb_func_end sub_8059790

	thumb_func_start sub_80597F0
sub_80597F0:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	mov r9, r0
	mov r8, r1
	adds r5, r2, 0
	adds r6, r3, 0
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	mov r2, r8
	adds r2, 0x4
	str r4, [sp]
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r3, 0x2
	bl sub_807DF38
	movs r0, 0x1
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80597F0

	thumb_func_start DiveMoveAction
DiveMoveAction:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	mov r8, r3
	movs r6, 0
	bl GetTileAtEntitySafe
	bl IsTileGround
	lsls r0, 24
	cmp r0, 0
	beq _08059870
	ldr r0, _0805986C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _080598B8
	.align 2, 0
_0805986C: .4byte gUnknown_80FD128
_08059870:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _080598A4
	ldr r0, _080598A0
	ldr r3, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r6, r1, 31
	adds r0, r4, 0
	bl sub_8079764
	b _080598B8
	.align 2, 0
_080598A0: .4byte gUnknown_80F4F64
_080598A4:
	ldr r0, _080598C8
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x9
	adds r3, r5, 0
	bl sub_8079618
	movs r6, 0x1
_080598B8:
	adds r0, r6, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080598C8: .4byte gUnknown_80FAD2C
	thumb_func_end DiveMoveAction

	thumb_func_start sub_80598CC
sub_80598CC:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805990A
	movs r7, 0x1
	ldr r0, _08059914
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805990A
	ldr r0, _08059918
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl LowerAccuracyStageTarget
_0805990A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059914: .4byte gUnknown_80F4E00
_08059918: .4byte gUnknown_8106A4C
	thumb_func_end sub_80598CC

	thumb_func_start StockpileMoveAction
StockpileMoveAction:
	push {lr}
	bl HandleStockpile
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end StockpileMoveAction

	thumb_func_start sub_8059928
sub_8059928:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, r3, 0
	movs r3, 0x1
	movs r6, 0
	ldr r0, [r4, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	subs r0, 0x7
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08059948
	movs r3, 0x2
_08059948:
	lsls r3, 8
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059978
	movs r6, 0x1
	ldr r0, _08059984
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059978
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl CringeStatusTarget
_08059978:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08059984: .4byte gUnknown_80F4DEC
	thumb_func_end sub_8059928

	thumb_func_start sub_8059988
sub_8059988:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080599A8
	movs r7, 0x1
	ldr r0, _080599E0
	strb r7, [r0]
_080599A8:
	ldr r0, _080599E0
	ldrb r0, [r0]
	cmp r0, 0
	beq _080599D6
	ldr r0, _080599E4
	ldr r0, [r0]
	cmp r0, 0x2
	bne _080599D6
	ldr r0, _080599E8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080599D6
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl PoisonedStatusTarget
_080599D6:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080599E0: .4byte gUnknown_202F218
_080599E4: .4byte gUnknown_202F214
_080599E8: .4byte gUnknown_80F4DC8
	thumb_func_end sub_8059988

	thumb_func_start sub_80599EC
sub_80599EC:
	push {r4,lr}
	sub sp, 0x4
	adds r3, r0, 0
	ldr r0, [r1, 0x70]
	movs r4, 0x10
	ldrsh r2, [r0, r4]
	cmp r2, 0
	bge _080599FE
	adds r2, 0x3
_080599FE:
	asrs r2, 2
	movs r0, 0x1
	str r0, [sp]
	adds r0, r3, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80599EC

	thumb_func_start sub_8059A18
sub_8059A18:
	push {lr}
	ldr r2, _08059A28
	ldr r2, [r2]
	bl RaiseAccuracyStageTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08059A28: .4byte gUnknown_8106A50
	thumb_func_end sub_8059A18

	thumb_func_start sub_8059A2C
sub_8059A2C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r9, r0
	adds r7, r1, 0
	adds r6, r2, 0
	mov r8, r3
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	mov r1, r9
	ldr r0, [r1, 0x70]
	ldrb r0, [r0, 0x9]
	mov r10, r0
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r5, [sp, 0x14]
	mov r0, r9
	adds r1, r7, 0
	mov r2, r10
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059A90
	movs r2, 0x1
_08059A90:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8059A2C

	thumb_func_start sub_8059AA8
sub_8059AA8:
	push {lr}
	movs r2, 0x1
	bl ConfuseStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059AA8

	thumb_func_start sub_8059AB8
sub_8059AB8:
	push {lr}
	bl TauntStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059AB8

	thumb_func_start sub_8059AC4
sub_8059AC4:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, _08059AF4
	bl GetApparentWeather
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
_08059AF4: .4byte gUnknown_80F501A
	thumb_func_end sub_8059AC4

	thumb_func_start sub_8059AF8
sub_8059AF8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	mov r9, r0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	movs r7, 0
	add r0, sp, 0x18
	strb r7, [r0]
	adds r0, r5, 0
	bl GetMoveType
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_806F4A4
	lsls r0, 24
	cmp r0, 0
	bne _08059B3C
	ldr r0, _08059B38
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _08059B82
	.align 2, 0
_08059B38: .4byte gUnknown_80FEB90
_08059B3C:
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r2, _08059B90
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	str r7, [sp, 0x10]
	str r7, [sp, 0x14]
	mov r0, r9
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059B7C
	movs r2, 0x1
_08059B7C:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
_08059B82:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059B90: .4byte 0x0000270f
	thumb_func_end sub_8059AF8

	thumb_func_start sub_8059B94
sub_8059B94:
	push {lr}
	ldr r2, _08059BA8
	ldr r2, [r2]
	movs r3, 0x2
	bl RaiseAttackStageTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08059BA8: .4byte gUnknown_8106A4C
	thumb_func_end sub_8059B94

	thumb_func_start sub_8059BAC
sub_8059BAC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r10, r0
	adds r5, r1, 0
	movs r0, 0
	mov r8, r0
	ldr r7, [r5, 0x70]
	adds r0, r5, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08059BD8
	ldr r0, _08059BD4
	b _08059C5E
	.align 2, 0
_08059BD4: .4byte gPtrForecastPreventsTypeSwitchMessage
_08059BD8:
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r7, r1
	mov r9, sp
	movs r6, 0x3
_08059BE2:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08059C08
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMoveTypeForMonster
	lsls r0, 24
	cmp r0, 0
	beq _08059C08
	mov r0, r9
	adds r0, 0x4
	mov r9, r0
	subs r0, 0x4
	stm r0!, {r4}
	movs r1, 0x1
	add r8, r1
_08059C08:
	adds r4, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _08059BE2
	mov r0, r8
	cmp r0, 0
	beq _08059C5C
	bl DungeonRandInt
	lsls r0, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r1, [r4]
	adds r0, r5, 0
	bl GetMoveTypeForMonster
	adds r1, r7, 0
	adds r1, 0x5C
	movs r2, 0
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x5D
	strb r2, [r0]
	adds r1, 0x9A
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _08059C54
	ldr r1, [r4]
	bl sub_80928C0
	ldr r0, _08059C58
	ldr r2, [r0]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0x1
	b _08059C6A
	.align 2, 0
_08059C54: .4byte gUnknown_202DE58
_08059C58: .4byte gUnknown_80FE330
_08059C5C:
	ldr r0, _08059C7C
_08059C5E:
	ldr r2, [r0]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0
_08059C6A:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059C7C: .4byte gUnknown_80FE36C
	thumb_func_end sub_8059BAC

	thumb_func_start sub_8059C80
sub_8059C80:
	push {lr}
	bl Conversion2StatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059C80

	thumb_func_start HelpingHandMoveAction
HelpingHandMoveAction:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r6, 0
	cmp r5, r4
	bne _08059CA8
	ldr r0, _08059CA4
	ldr r2, [r0]
	adds r0, r4, 0
	bl sub_80522F4
	b _08059CC6
	.align 2, 0
_08059CA4: .4byte gUnknown_80FEB60
_08059CA8:
	ldr r0, _08059CD0
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl RaiseAttackStageTarget
	ldr r0, _08059CD4
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl RaiseAttackStageTarget
	movs r6, 0x1
_08059CC6:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08059CD0: .4byte gUnknown_8106A4C
_08059CD4: .4byte gUnknown_8106A50
	thumb_func_end HelpingHandMoveAction

	thumb_func_start sub_8059CD8
sub_8059CD8:
	push {lr}
	ldr r2, _08059CEC
	ldr r2, [r2]
	movs r3, 0x2
	bl RaiseDefenseStageTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08059CEC: .4byte gUnknown_8106A4C
	thumb_func_end sub_8059CD8

	thumb_func_start sub_8059CF0
sub_8059CF0:
	push {lr}
	movs r2, 0
	movs r3, 0
	bl sub_807D148
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059CF0

	thumb_func_start sub_8059D00
sub_8059D00:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059D3A
	movs r7, 0x1
	ldr r0, _08059D44
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059D3A
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ParalyzeStatusTarget
_08059D3A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059D44: .4byte gUnknown_80F4DE2
	thumb_func_end sub_8059D00

	thumb_func_start sub_8059D48
sub_8059D48:
	push {lr}
	movs r2, 0x1
	bl ParalyzeStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059D48

	thumb_func_start sub_8059D58
sub_8059D58:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059D8E
	movs r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059D8E
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ParalyzeStatusTarget
_08059D8E:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8059D58

	thumb_func_start sub_8059D98
sub_8059D98:
	push {lr}
	bl ImmobilizedStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059D98

	thumb_func_start sub_8059DA4
sub_8059DA4:
	push {lr}
	movs r2, 0x1
	bl PoisonedStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059DA4

	thumb_func_start sub_8059DB4
sub_8059DB4:
	push {lr}
	movs r2, 0x1
	bl BadlyPoisonedStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059DB4

	thumb_func_start sub_8059DC4
sub_8059DC4:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059DFE
	movs r7, 0x1
	ldr r0, _08059E08
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059DFE
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl BadlyPoisonedStatusTarget
_08059DFE:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059E08: .4byte gUnknown_80F4DCA
	thumb_func_end sub_8059DC4

	thumb_func_start sub_8059E0C
sub_8059E0C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059E46
	movs r7, 0x1
	ldr r0, _08059E50
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059E46
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl PoisonedStatusTarget
_08059E46:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059E50: .4byte gUnknown_80F4DBE
	thumb_func_end sub_8059E0C

	thumb_func_start sub_8059E54
sub_8059E54:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x2C
	adds r6, r0, 0
	mov r8, r1
	adds r7, r2, 0
	adds r1, r3, 0
	ldr r0, [sp, 0x48]
	lsls r0, 24
	movs r2, 0
	mov r9, r2
	cmp r0, 0
	bne _08059E8A
	movs r3, 0x80
	lsls r3, 1
	str r1, [sp]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	mov r9, r1
_08059E8A:
	mov r0, r9
	cmp r0, 0
	bne _08059F1A
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMoveTypeForMonster
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMovePower
	adds r5, r0, 0
	adds r0, r7, 0
	bl GetMoveCritChance
	str r0, [sp]
	add r2, sp, 0x18
	str r2, [sp, 0x4]
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp, 0x8]
	ldrh r0, [r7, 0x2]
	str r0, [sp, 0xC]
	mov r0, r9
	str r0, [sp, 0x10]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_806EAF4
	ldr r0, _08059F2C
	ldr r1, [r6, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _08059F30
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r8
	bl sub_80522F4
	ldr r0, [sp, 0x18]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp, 0x18]
	cmp r0, 0
	bne _08059EF6
	movs r0, 0x1
	str r0, [sp, 0x18]
_08059EF6:
	ldr r2, [sp, 0x18]
	add r0, sp, 0x28
	str r0, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	ldr r0, _08059F34
	str r0, [sp, 0x8]
	movs r0, 0x13
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	mov r0, r9
	str r0, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_806F370
_08059F1A:
	mov r0, r9
	add sp, 0x2C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059F2C: .4byte gAvailablePokemonNames
_08059F30: .4byte gUnknown_80FC7C8
_08059F34: .4byte 0x000001f7
	thumb_func_end sub_8059E54

	thumb_func_start sub_8059F38
sub_8059F38:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _08059FA0
	ldr r0, _08059F98
	ldr r3, [r0]
	str r7, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059F90
	movs r1, 0x1
	mov r8, r1
	ldr r0, _08059F9C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059F90
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl ParalyzeStatusTarget
_08059F90:
	adds r0, r4, 0
	bl sub_8079764
	b _08059FB6
	.align 2, 0
_08059F98: .4byte gUnknown_80F4F60
_08059F9C: .4byte gUnknown_80F4DCC
_08059FA0:
	ldr r0, _08059FC4
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x8
	adds r3, r5, 0
	bl sub_8079618
	movs r0, 0x1
	mov r8, r0
_08059FB6:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059FC4: .4byte gUnknown_80FAD10
	thumb_func_end sub_8059F38

	thumb_func_start sub_8059FC8
sub_8059FC8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x2C
	adds r6, r0, 0
	mov r8, r1
	adds r7, r2, 0
	adds r1, r3, 0
	ldr r0, [sp, 0x48]
	lsls r0, 24
	movs r2, 0
	mov r9, r2
	cmp r0, 0
	bne _08059FFE
	movs r3, 0x80
	lsls r3, 2
	str r1, [sp]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	mov r9, r1
_08059FFE:
	mov r0, r9
	cmp r0, 0
	bne _0805A090
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMoveTypeForMonster
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMovePower
	adds r5, r0, 0
	adds r0, r7, 0
	bl GetMoveCritChance
	str r0, [sp]
	add r2, sp, 0x18
	str r2, [sp, 0x4]
	movs r0, 0x80
	lsls r0, 2
	str r0, [sp, 0x8]
	ldrh r0, [r7, 0x2]
	str r0, [sp, 0xC]
	mov r0, r9
	str r0, [sp, 0x10]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_806EAF4
	ldr r0, _0805A0A0
	ldr r1, [r6, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _0805A0A4
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r8
	bl sub_80522F4
	ldr r0, [sp, 0x18]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp, 0x18]
	cmp r0, 0
	bne _0805A06A
	movs r0, 0x1
	str r0, [sp, 0x18]
_0805A06A:
	ldr r2, [sp, 0x18]
	add r0, sp, 0x28
	str r0, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	movs r0, 0xFC
	lsls r0, 1
	str r0, [sp, 0x8]
	movs r0, 0x13
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	mov r0, r9
	str r0, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_806F370
_0805A090:
	mov r0, r9
	add sp, 0x2C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A0A0: .4byte gAvailablePokemonNames
_0805A0A4: .4byte gUnknown_80FC7C8
	thumb_func_end sub_8059FC8

	thumb_func_start sub_805A0A8
sub_805A0A8:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A114
	movs r7, 0x1
	ldr r0, _0805A0F8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A114
	movs r0, 0x3
	bl DungeonRandInt
	cmp r0, 0x1
	beq _0805A0FC
	cmp r0, 0x1
	ble _0805A0EA
	cmp r0, 0x2
	beq _0805A10A
_0805A0EA:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ParalyzeStatusTarget
	b _0805A114
	.align 2, 0
_0805A0F8: .4byte gUnknown_80F4DFC
_0805A0FC:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl BurnedStatusTarget
	b _0805A114
_0805A10A:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl FrozenStatusTarget
_0805A114:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805A0A8

	thumb_func_start sub_805A120
sub_805A120:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0
	mov r10, r0
	ldr r1, [r6, 0x70]
	mov r9, r1
	mov r7, r9
	ldr r2, [r5, 0x70]
	mov r8, r2
	mov r0, r8
	str r0, [sp]
	ldr r4, _0805A16C
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	movs r1, 0x2C
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805A174
	ldr r0, _0805A170
	b _0805A1B8
	.align 2, 0
_0805A16C: .4byte gAvailablePokemonNames
_0805A170: .4byte gUnknown_80FCCE4
_0805A174:
	adds r0, r5, 0
	movs r1, 0x24
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0805A18C
	ldr r0, _0805A188
	b _0805A1B8
	.align 2, 0
_0805A188: .4byte gUnknown_80FD578
_0805A18C:
	mov r0, r9
	adds r0, 0x60
	mov r2, r8
	adds r2, 0x60
	ldrb r1, [r0]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _0805A1A2
	mov r10, r4
_0805A1A2:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _0805A1B0
	movs r1, 0x1
	mov r10, r1
_0805A1B0:
	mov r2, r10
	cmp r2, 0
	beq _0805A1CC
	ldr r0, _0805A1C8
_0805A1B8:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0
	b _0805A1FC
	.align 2, 0
_0805A1C8: .4byte gUnknown_80FC7AC
_0805A1CC:
	ldr r0, [r7, 0x60]
	ldr r2, [sp]
	ldr r1, [r2, 0x60]
	str r1, [r7, 0x60]
	str r0, [r2, 0x60]
	adds r0, r6, 0
	bl sub_806A6E8
	adds r0, r5, 0
	bl sub_806A6E8
	adds r1, r7, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805A1EE
	strb r4, [r1]
_0805A1EE:
	ldr r0, _0805A20C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0x1
_0805A1FC:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A20C: .4byte gUnknown_80FC790
	thumb_func_end sub_805A120

	thumb_func_start sub_805A210
sub_805A210:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r3, 0
	ldr r4, _0805A238
	ldr r3, [r4]
	adds r3, 0x1
	str r3, [r4]
	lsls r3, 8
	str r5, [sp]
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A238: .4byte gUnknown_202F210
	thumb_func_end sub_805A210

	thumb_func_start sub_805A23C
sub_805A23C:
	push {lr}
	ldrh r0, [r2, 0x2]
	cmp r0, 0xD4
	bne _0805A24C
	movs r0, 0
	bl sub_807EA30
	b _0805A252
_0805A24C:
	movs r0, 0x1
	bl sub_807EA30
_0805A252:
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A23C

	thumb_func_start sub_805A258
sub_805A258:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A292
	movs r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A292
	ldr r0, _0805A29C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl LowerAccuracyStageTarget
_0805A292:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A29C: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A258

	thumb_func_start sub_805A2A0
sub_805A2A0:
	push {lr}
	bl sub_805BA50
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_805A2A0

	thumb_func_start sub_805A2B0
sub_805A2B0:
	push {lr}
	ldr r2, _0805A2C4
	ldr r2, [r2]
	movs r3, 0x2
	bl RaiseDefenseStageTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805A2C4: .4byte gUnknown_8106A50
	thumb_func_end sub_805A2B0

	thumb_func_start sub_805A2C8
sub_805A2C8:
	push {lr}
	sub sp, 0x8
	ldr r2, _0805A2E4
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	bl LowerAttackStageTarget
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0805A2E4: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A2C8

	thumb_func_start sub_805A2E8
sub_805A2E8:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
	ldr r0, [r1, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	movs r4, 0x80
	lsls r4, 1
	cmp r0, 0x9
	bne _0805A302
	movs r4, 0x80
	lsls r4, 2
_0805A302:
	str r3, [sp]
	adds r0, r5, 0
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A312
	movs r6, 0x1
_0805A312:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805A2E8

	thumb_func_start sub_805A31C
sub_805A31C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, [r5, 0x70]
	ldr r7, [r6, 0x70]
	adds r0, r6, 0
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805A348
	ldr r0, _0805A344
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _0805A386
	.align 2, 0
_0805A344: .4byte gUnknown_80FC854
_0805A348:
	adds r0, r7, 0
	adds r0, 0x5E
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x5E
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x5F
	ldrb r0, [r0]
	adds r1, 0x1
	strb r0, [r1]
	ldr r0, _0805A38C
	ldr r0, [r0]
	movs r2, 0x1
	strb r2, [r0, 0xC]
	adds r1, 0x9C
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805A370
	strb r2, [r1]
_0805A370:
	ldr r0, _0805A390
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_806ABAC
	movs r0, 0x1
_0805A386:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A38C: .4byte gDungeon
_0805A390: .4byte gUnknown_80FC81C
	thumb_func_end sub_805A31C

	thumb_func_start sub_805A394
sub_805A394:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _0805A3CC
	ldr r0, [r0]
	ldr r1, _0805A3D0
	ldrh r1, [r1]
	ldr r2, _0805A3D4
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x1
	movs r1, 0
	bl sub_807EAA0
	lsls r0, 24
	cmp r0, 0
	bne _0805A3C2
	ldr r0, _0805A3D8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_0805A3C2:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A3CC: .4byte gDungeon
_0805A3D0: .4byte gUnknown_80F4F42
_0805A3D4: .4byte 0x0000e268
_0805A3D8: .4byte gUnknown_80FCF7C
	thumb_func_end sub_805A394

	thumb_func_start sub_805A3DC
sub_805A3DC:
	push {lr}
	sub sp, 0x8
	ldr r2, _0805A3F8
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	bl LowerDefenseStageTarget
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0805A3F8: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A3DC

	thumb_func_start sub_805A3FC
sub_805A3FC:
	push {lr}
	bl WishStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A3FC

	thumb_func_start sub_805A408
sub_805A408:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A442
	movs r7, 0x1
	ldr r0, _0805A44C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A442
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl CringeStatusTarget
_0805A442:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A44C: .4byte gUnknown_80F4DF2
	thumb_func_end sub_805A408

	thumb_func_start sub_805A450
sub_805A450:
	push {lr}
	ldr r2, _0805A460
	ldr r2, [r2]
	bl sub_80522F4
	movs r0, 0
	pop {r1}
	bx r1
	.align 2, 0
_0805A460: .4byte gUnknown_80FC730
	thumb_func_end sub_805A450

	thumb_func_start sub_805A464
sub_805A464:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A4B4
	movs r7, 0x1
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _0805A4B4
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805A4B4
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	movs r1, 0x69
	movs r2, 0x2
	bl sub_8045C28
	add r3, sp, 0x8
	adds r0, r5, 0
	adds r1, r6, 0
	add r2, sp, 0x4
	bl sub_805A7D4
_0805A4B4:
	adds r0, r7, 0
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805A464

	thumb_func_start sub_805A4C0
sub_805A4C0:
	push {lr}
	ldr r2, _0805A4D0
	ldr r2, [r2]
	bl sub_80522F4
	movs r0, 0
	pop {r1}
	bx r1
	.align 2, 0
_0805A4D0: .4byte gUnknown_80FC74C
	thumb_func_end sub_805A4C0

	thumb_func_start sub_805A4D4
sub_805A4D4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _0805A4F8
	adds r0, r4, 0
	movs r2, 0
	bl CalculateStatusTurns
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl NappingStatusTarget
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A4F8: .4byte gUnknown_80F4E94
	thumb_func_end sub_805A4D4

	thumb_func_start sub_805A4FC
sub_805A4FC:
	push {lr}
	bl IngrainedStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A4FC

	thumb_func_start sub_805A508
sub_805A508:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r3, r1, 0
	ldr r0, [r3, 0x70]
	movs r1, 0x89
	lsls r1, 1
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _0805A540
	ldr r1, _0805A53C
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r3, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0
	strb r0, [r4]
	b _0805A54C
	.align 2, 0
_0805A53C: .4byte gUnknown_80F51D4
_0805A540:
	ldr r0, _0805A558
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r3, 0
	bl sub_80522F4
_0805A54C:
	movs r0, 0x1
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A558: .4byte gUnknown_80FC770
	thumb_func_end sub_805A508

	thumb_func_start sub_805A55C
sub_805A55C:
	push {lr}
	bl CurseStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A55C

	thumb_func_start sub_805A568
sub_805A568:
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_805A568

	thumb_func_start sub_805A588
sub_805A588:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A5D8
	movs r7, 0x1
	adds r0, r6, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A5D8
	ldr r0, _0805A5E4
	ldr r5, [r0]
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl LowerAttackStageTarget
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl LowerDefenseStageTarget
_0805A5D8:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A5E4: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A588

	thumb_func_start sub_805A5E8
sub_805A5E8:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x18]
	movs r6, 0
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	adds r0, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A632
	movs r6, 0x1
	ldr r0, _0805A63C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A632
	ldr r4, [r5, 0x70]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r7, 0
	movs r3, 0x1
	bl RaiseDefenseStageTarget
	adds r4, 0xFB
	ldrb r0, [r4]
	cmp r0, 0
	bne _0805A632
	strb r6, [r4]
_0805A632:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A63C: .4byte gUnknown_80F4DD2
	thumb_func_end sub_805A5E8

	thumb_func_start SpitUpMoveAction
SpitUpMoveAction:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r1, r3, 0
	ldr r0, [r5, 0x70]
	movs r3, 0x89
	lsls r3, 1
	adds r4, r0, r3
	ldrb r0, [r4]
	cmp r0, 0
	beq _0805A66C
	adds r3, r0, 0
	lsls r3, 8
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8055640
	movs r0, 0
	strb r0, [r4]
	b _0805A678
_0805A66C:
	ldr r0, _0805A684
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
_0805A678:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805A684: .4byte gUnknown_80FCA3C
	thumb_func_end SpitUpMoveAction

	thumb_func_start sub_805A688
sub_805A688:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A6BE
	movs r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A6BE
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ConfuseStatusTarget
_0805A6BE:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805A688

	thumb_func_start sub_805A6C8
sub_805A6C8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r0, [r6, 0x70]
	mov r9, r0
	ldr r7, [r5, 0x70]
	mov r8, r7
	ldr r4, _0805A708
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	movs r1, 0x2C
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805A710
	ldr r0, _0805A70C
	b _0805A73A
	.align 2, 0
_0805A708: .4byte gAvailablePokemonNames
_0805A70C: .4byte gUnknown_80FCCE8
_0805A710:
	adds r0, r5, 0
	movs r1, 0x24
	bl HasHeldItem
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _0805A728
	ldr r0, _0805A724
	b _0805A73A
	.align 2, 0
_0805A724: .4byte gUnknown_80FD57C
_0805A728:
	ldr r0, [r7, 0x60]
	str r0, [sp]
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805A74C
	ldr r0, _0805A748
_0805A73A:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0
	b _0805A7B4
	.align 2, 0
_0805A748: .4byte gUnknown_80FD18C
_0805A74C:
	mov r0, r8
	adds r0, 0x60
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x1]
	strb r2, [r0]
	ldr r0, _0805A7C4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	ldr r4, _0805A7C8
	mov r3, r9
	adds r3, 0x46
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r2, [r0]
	ldr r0, _0805A7CC
	ldr r1, [sp, 0x4]
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0x4]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	ldr r2, _0805A7D0
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x4]
	add r3, sp, 0x4
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_805A7D4
	adds r1, r5, 0x4
	adds r0, r5, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _0805A7B2
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_0805A7B2:
	movs r0, 0x1
_0805A7B4:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A7C4: .4byte gUnknown_80FD170
_0805A7C8: .4byte gAdjacentTileOffsets
_0805A7CC: .4byte 0xffff0000
_0805A7D0: .4byte 0x0000ffff
	thumb_func_end sub_805A6C8

	thumb_func_start sub_805A7D4
sub_805A7D4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x78
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	movs r0, 0x3
	str r0, [sp, 0x4]
	add r0, sp, 0x28
	movs r5, 0
	strb r5, [r0]
	add r1, sp, 0x24
	movs r0, 0x1
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x26
	strb r5, [r0]
	str r6, [sp, 0x74]
	add r1, sp, 0x4
	ldrh r0, [r3]
	ldrh r2, [r4, 0x4]
	adds r0, r2
	strh r0, [r1, 0x4]
	ldrh r0, [r3, 0x2]
	ldrh r2, [r4, 0x6]
	adds r0, r2
	strh r0, [r1, 0x6]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	add r0, sp, 0x4
	bl sub_8045394
	add r0, sp, 0x4
	strh r5, [r0, 0x26]
	ldr r0, _0805A858
	add r1, sp, 0x4
	movs r2, 0
	bl SetMessageArgument
	str r5, [sp]
	mov r0, r8
	add r1, sp, 0x4
	adds r2, r6, 0
	movs r3, 0x1
	bl sub_804652C
	add sp, 0x78
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805A858: .4byte gUnknown_202DE58
	thumb_func_end sub_805A7D4

	thumb_func_start sub_805A85C
sub_805A85C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	mov r8, r0
	adds r6, r1, 0
	mov r10, r2
	str r3, [sp, 0x24]
	ldr r0, [r6, 0x4]
	str r0, [sp, 0x18]
	adds r0, r6, 0
	movs r1, 0xA
	movs r2, 0x8
	bl sub_806CDD4
	movs r5, 0
_0805A880:
	movs r0, 0x3
	bl DungeonRandInt
	adds r4, r0, 0
	movs r0, 0x3
	bl DungeonRandInt
	adds r2, r0, 0
	subs r4, 0x1
	subs r2, 0x1
	cmp r4, 0
	bne _0805A89C
	cmp r2, 0
	beq _0805A8BC
_0805A89C:
	ldrh r0, [r6, 0x4]
	adds r0, r4
	lsls r0, 16
	ldrh r1, [r6, 0x6]
	adds r1, r2
	lsls r1, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x18]
	adds r0, r6, 0
	add r1, sp, 0x18
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	beq _0805A8C2
_0805A8BC:
	adds r5, 0x1
	cmp r5, 0x27
	ble _0805A880
_0805A8C2:
	cmp r5, 0x28
	bne _0805A8DC
	ldr r0, _0805A8D8
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _0805AAB8
	.align 2, 0
_0805A8D8: .4byte gUnknown_80FEBDC
_0805A8DC:
	add r0, sp, 0x18
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r3, 0xC0
	lsls r3, 4
	adds r0, r3
	ldr r1, [r6, 0xC]
	subs r0, r1
	movs r1, 0xC
	bl __divsi3
	str r0, [sp, 0x28]
	add r0, sp, 0x18
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r3, 0x80
	lsls r3, 5
	adds r0, r3
	ldr r1, [r6, 0x10]
	subs r0, r1
	movs r1, 0xC
	bl __divsi3
	str r0, [sp, 0x2C]
	adds r4, r6, 0x4
	adds r0, r4, 0
	bl sub_803F428
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0805A934
	add r0, sp, 0x18
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0805A94C
_0805A934:
	movs r5, 0xB
_0805A936:
	adds r0, r6, 0
	ldr r1, [sp, 0x28]
	ldr r2, [sp, 0x2C]
	bl sub_804539C
	movs r0, 0x2C
	bl sub_803E46C
	subs r5, 0x1
	cmp r5, 0
	bge _0805A936
_0805A94C:
	add r0, sp, 0x18
	movs r1, 0
	ldrsh r0, [r0, r1]
	add r4, sp, 0x18
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetTileSafe
	ldr r5, [r0, 0x10]
	cmp r5, 0
	beq _0805AA4C
	adds r0, r5, 0
	bl GetEntityType
	adds r7, r0, 0
	cmp r7, 0x1
	bne _0805A9FE
	add r4, sp, 0x1C
	ldr r1, _0805AA44
	adds r0, r4, 0
	bl InitPokemonMove
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805A9B0
	mov r0, r10
	ldr r1, [sp, 0x24]
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0805AA48
	movs r3, 0
	ldrsh r2, [r1, r3]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	str r7, [sp, 0x10]
	str r4, [sp, 0x14]
	mov r0, r8
	adds r1, r5, 0
	movs r3, 0
	bl sub_806F370
_0805A9B0:
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805AAB6
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
	ldr r0, _0805AA48
	movs r1, 0
	ldrsh r2, [r0, r1]
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0xFF
	lsls r0, 1
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	str r4, [sp, 0x14]
	mov r0, r8
	mov r1, r8
	movs r3, 0
	bl sub_806F370
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0805AAB6
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
_0805A9FE:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
	mov r0, r9
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	bne _0805AA22
	add r0, sp, 0x18
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0805AA5E
_0805AA22:
	ldr r2, [sp, 0x28]
	negs r7, r2
	ldr r3, [sp, 0x2C]
	negs r4, r3
	movs r5, 0xB
_0805AA2C:
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_804539C
	movs r0, 0x2C
	bl sub_803E46C
	subs r5, 0x1
	cmp r5, 0
	bge _0805AA2C
	b _0805AA5E
	.align 2, 0
_0805AA44: .4byte 0x00000163
_0805AA48: .4byte gUnknown_80F4F82
_0805AA4C:
	add r0, sp, 0x18
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	adds r0, r6, 0
	movs r3, 0
	bl sub_80694C0
_0805AA5E:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
	adds r0, r6, 0
	movs r1, 0
	bl sub_804535C
	mov r1, r9
	adds r0, r6, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _0805AA8C
	mov r0, r8
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_0805AA8C:
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0805AAA0
	mov r0, r9
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0805AAA0:
	adds r0, r6, 0
	bl sub_806A5B8
	ldr r0, _0805AAC8
	ldr r0, [r0]
	ldr r1, _0805AACC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8075900
_0805AAB6:
	movs r0, 0x1
_0805AAB8:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AAC8: .4byte gDungeon
_0805AACC: .4byte 0x00003a08
	thumb_func_end sub_805A85C

	thumb_func_start sub_805AAD0
sub_805AAD0:
	push {lr}
	adds r1, r0, 0
	bl FixedDamageStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805AAD0

	thumb_func_start sub_805AAE0
sub_805AAE0:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [r4, 0x70]
	movs r7, 0
	movs r1, 0x9E
	lsls r1, 1
	adds r5, r0, r1
	ldr r0, [r5]
	bl RoundUpFixedPoint
	cmp r0, 0x1
	ble _0805AB20
	ldr r0, _0805AB1C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	movs r3, 0x63
	bl RaiseAttackStageTarget
	mov r0, sp
	movs r1, 0x1
	bl sub_80943A0
	ldr r0, [sp]
	str r0, [r5]
	movs r7, 0x1
	b _0805AB36
	.align 2, 0
_0805AB1C: .4byte gUnknown_8106A4C
_0805AB20:
	ldr r0, _0805AB40
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0805AB44
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80522F4
_0805AB36:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AB40: .4byte gAvailablePokemonNames
_0805AB44: .4byte gUnknown_80FC5CC
	thumb_func_end sub_805AAE0

	thumb_func_start sub_805AB48
sub_805AB48:
	push {lr}
	bl LightScreenStatusTarget
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805AB48

	thumb_func_start sub_805AB54
sub_805AB54:
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
	bne _0805AB70
	b _0805AC86
_0805AB70:
	movs r7, 0x1
	ldr r0, _0805ABA8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	bne _0805AB88
	b _0805AC86
_0805AB88:
	ldr r1, _0805ABAC
	ldr r0, _0805ABB0
	ldr r0, [r0]
	ldr r2, _0805ABB4
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _0805AC7C
	lsls r0, 2
	ldr r1, _0805ABB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805ABA8: .4byte gUnknown_80F4E06
_0805ABAC: .4byte gUnknown_80F5978
_0805ABB0: .4byte gDungeon
_0805ABB4: .4byte 0x00003a0e
_0805ABB8: .4byte _0805ABBC
	.align 2, 0
_0805ABBC:
	.4byte _0805ABE0
	.4byte _0805ABEC
	.4byte _0805AC08
	.4byte _0805AC16
	.4byte _0805AC34
	.4byte _0805AC50
	.4byte _0805AC64
	.4byte _0805AC70
	.4byte _0805AC7C
_0805ABE0:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl PoisonedStatusTarget
	b _0805AC86
_0805ABEC:
	ldr r1, _0805AC04
	adds r0, r6, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_8075C58
	b _0805AC86
	.align 2, 0
_0805AC04: .4byte gUnknown_80F4E74
_0805AC08:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl LowerMovementSpeedTarget
	b _0805AC86
_0805AC16:
	ldr r0, _0805AC30
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl LowerAttackStageTarget
	b _0805AC86
	.align 2, 0
_0805AC30: .4byte gUnknown_8106A4C
_0805AC34:
	ldr r0, _0805AC4C
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl LowerDefenseStageTarget
	b _0805AC86
	.align 2, 0
_0805AC4C: .4byte gUnknown_8106A4C
_0805AC50:
	ldr r0, _0805AC60
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl LowerAccuracyStageTarget
	b _0805AC86
	.align 2, 0
_0805AC60: .4byte gUnknown_8106A4C
_0805AC64:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ConfuseStatusTarget
	b _0805AC86
_0805AC70:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl CringeStatusTarget
	b _0805AC86
_0805AC7C:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ParalyzeStatusTarget
_0805AC86:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805AB54

	thumb_func_start sub_805AC90
sub_805AC90:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805ACCA
	movs r7, 0x1
	ldr r0, _0805ACD4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805ACCA
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl ConfuseStatusTarget
_0805ACCA:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805ACD4: .4byte gUnknown_80F4DFA
	thumb_func_end sub_805AC90

	thumb_func_start sub_805ACD8
sub_805ACD8:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, _0805AD00
	ldr r4, [r0]
	adds r0, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl RaiseAttackStageTarget
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl RaiseDefenseStageTarget
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805AD00: .4byte gUnknown_8106A4C
	thumb_func_end sub_805ACD8

	thumb_func_start sub_805AD04
sub_805AD04:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _0805AD30
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r3, r0, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl PausedStatusTarget
	movs r0, 0x1
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805AD30: .4byte gUnknown_80F4EE0
	thumb_func_end sub_805AD04

	thumb_func_start sub_805AD34
sub_805AD34:
	push {lr}
	sub sp, 0x8
	ldr r2, _0805AD50
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl LowerAttackStageTarget
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0805AD50: .4byte gUnknown_8106A4C
	thumb_func_end sub_805AD34

	thumb_func_start sub_805AD54
sub_805AD54:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	mov r9, r1
	movs r0, 0
	mov r10, r0
	ldr r1, [r5, 0x70]
	mov r8, r1
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0805AD88
	ldr r0, _0805AD80
	ldr r0, [r0]
	ldr r1, _0805AD84
	adds r7, r0, r1
	movs r0, 0x10
	b _0805AD92
	.align 2, 0
_0805AD80: .4byte gDungeon
_0805AD84: .4byte 0x0001358c
_0805AD88:
	ldr r0, _0805AD98
	ldr r0, [r0]
	ldr r1, _0805AD9C
	adds r7, r0, r1
	movs r0, 0x4
_0805AD92:
	str r0, [sp]
	movs r6, 0
	b _0805AE0E
	.align 2, 0
_0805AD98: .4byte gDungeon
_0805AD9C: .4byte 0x0001357c
_0805ADA0:
	lsls r0, r6, 2
	adds r0, r7
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AE0C
	cmp r5, r4
	beq _0805AE0C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl CanTarget
	lsls r0, 24
	cmp r0, 0
	bne _0805AE0C
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0805AE0C
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0805ADE2
	cmp r0, 0x47
	bne _0805ADE6
_0805ADE2:
	movs r0, 0x1
	b _0805ADE8
_0805ADE6:
	movs r0, 0
_0805ADE8:
	cmp r0, 0
	bne _0805AE0C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x2
	mov r3, r9
	adds r3, 0x4
	bl sub_807D148
	movs r0, 0x1
	mov r10, r0
	mov r1, r8
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805AE0C
	mov r0, r10
	strb r0, [r1]
_0805AE0C:
	adds r6, 0x1
_0805AE0E:
	ldr r1, [sp]
	cmp r6, r1
	blt _0805ADA0
	mov r0, r10
	cmp r0, 0
	bne _0805AE26
	ldr r0, _0805AE38
	ldr r2, [r0]
	adds r0, r5, 0
	mov r1, r9
	bl sub_80522F4
_0805AE26:
	mov r0, r10
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AE38: .4byte gUnknown_81004EC
	thumb_func_end sub_805AD54

	thumb_func_start sub_805AE3C
sub_805AE3C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	bl SendThawedMessage
	movs r3, 0x80
	lsls r3, 2
	str r4, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	mov r2, r8
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805AE3C

	thumb_func_start sub_805AE74
sub_805AE74:
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
	beq _0805AEB8
	movs r7, 0x1
	ldr r0, _0805AEC4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805AEB8
	ldr r0, _0805AEC8
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl LowerDefenseStageTarget
_0805AEB8:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AEC4: .4byte gUnknown_80F4DDA
_0805AEC8: .4byte gUnknown_8106A4C
	thumb_func_end sub_805AE74

	thumb_func_start sub_805AECC
sub_805AECC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r6, 0
	bl SendThawedMessage
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805AF1E
	movs r1, 0x1
	mov r8, r1
	ldr r0, _0805AF2C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805AF1E
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0
	bl BurnedStatusTarget
_0805AF1E:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AF2C: .4byte gUnknown_80F4DFE
	thumb_func_end sub_805AECC

	thumb_func_start sub_805AF30
sub_805AF30:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r4, r3, 0
	movs r0, 0x64
	bl DungeonRandInt
	adds r1, r0, 0
	cmp r0, 0x9
	bgt _0805AF54
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x78
	b _0805AF92
_0805AF54:
	cmp r0, 0x1D
	bgt _0805AF78
	ldr r0, [r5, 0x70]
	movs r1, 0x10
	ldrsh r2, [r0, r1]
	cmp r2, 0
	bge _0805AF64
	adds r2, 0x3
_0805AF64:
	asrs r2, 2
	movs r0, 0x1
	str r0, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	b _0805AF9C
_0805AF78:
	cmp r1, 0x3B
	bgt _0805AF88
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x50
	b _0805AF92
_0805AF88:
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x28
_0805AF92:
	bl sub_8055864
	negs r1, r0
	orrs r1, r0
	lsrs r0, r1, 31
_0805AF9C:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805AF30

	.align 2, 0
