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
	bl SetChargeStatusTarget
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
	bl SetChargeStatusTarget
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
	bl SetChargeStatusTarget
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

	.align 2, 0
