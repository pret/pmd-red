	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

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
	bl RollPercentChance_2
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
	bl RollPercentChance_2
	lsls r0, 24
	lsrs r0, 24
_08057340:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8057308

	.align 2, 0