	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_80701A4
sub_80701A4:
	push {r4-r7,lr}
	adds r7, r0, 0
	ldr r6, [r7, 0x70]
	movs r4, 0
	ldr r0, _080701D4
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _080701DC
	cmp r0, 0x3
	bgt _080701D8
	cmp r0, 0x1
	beq _080701DC
	b _080701E4
	.align 2, 0
_080701D4: .4byte gAvailablePokemonNames
_080701D8:
	cmp r0, 0x5
	bne _080701E4
_080701DC:
	ldr r0, _080701E0
	b _08070278
	.align 2, 0
_080701E0: .4byte gUnknown_80F95EC
_080701E4:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _0807020C
	cmp r0, 0x3
	bgt _080701F8
	cmp r0, 0x1
	beq _08070202
	b _0807021C
_080701F8:
	cmp r0, 0x4
	beq _08070214
	cmp r0, 0x6
	beq _08070280
	b _0807021C
_08070202:
	ldr r0, _08070208
	b _08070278
	.align 2, 0
_08070208: .4byte gPtrFrozenMessage
_0807020C:
	ldr r0, _08070210
	b _08070278
	.align 2, 0
_08070210: .4byte gPtrWrappedAroundMessage
_08070214:
	ldr r0, _08070218
	b _08070278
	.align 2, 0
_08070218: .4byte gPtrWrappedByMessage
_0807021C:
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _0807026C
	lsls r0, 2
	ldr r1, _08070230
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08070230: .4byte _08070234
	.align 2, 0
_08070234:
	.4byte _0807026C
	.4byte _0807026C
	.4byte _08070258
	.4byte _0807025C
	.4byte _0807026C
	.4byte _0807026C
	.4byte _0807026C
	.4byte _08070264
	.4byte _0807026C
_08070258:
	movs r4, 0x1
	b _0807026C
_0807025C:
	ldr r0, _08070260
	b _08070278
	.align 2, 0
_08070260: .4byte gPtrPausedMessage
_08070264:
	ldr r0, _08070268
	b _08070278
	.align 2, 0
_08070268: .4byte gPtrInfatuatedMessage
_0807026C:
	adds r0, r6, 0
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08070288
	ldr r0, _08070284
_08070278:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_08070280:
	movs r0, 0x1
	b _08070322
	.align 2, 0
_08070284: .4byte gPtrBideMessage
_08070288:
	cmp r0, 0
	beq _08070320
	cmp r0, 0xB
	beq _08070320
	cmp r0, 0xC
	beq _08070320
	cmp r4, 0
	beq _080702A8
	ldr r0, _080702A4
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _0807031A
	.align 2, 0
_080702A4: .4byte gPtrMoveInterruptedMessage
_080702A8:
	movs r5, 0
	movs r0, 0x8C
	lsls r0, 1
	adds r4, r6, r0
_080702B0:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08070312
	adds r0, r7, 0
	adds r1, r4, 0
	bl IsChargeMove
	lsls r0, 24
	cmp r0, 0
	beq _08070312
	adds r0, r6, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	cmp r0, r5
	bne _08070312
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x14
	bl SetAction
	adds r3, r5, 0
	adds r7, r6, 0
	adds r7, 0x50
	cmp r5, 0
	ble _0807030E
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0807030E
	movs r4, 0x2
	lsls r0, r5, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r2, r0, r6
_080702FC:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	ble _0807030E
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _080702FC
_0807030E:
	strb r3, [r7]
	b _08070280
_08070312:
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	ble _080702B0
_0807031A:
	adds r0, r7, 0
	bl sub_8079764
_08070320:
	movs r0, 0
_08070322:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80701A4

	.align 2, 0