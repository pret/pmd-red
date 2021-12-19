	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified
	
        .text

        thumb_func_start sub_8092638
sub_8092638:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, 24
	lsrs r2, 24
	mov r12, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	movs r6, 0
	movs r3, 0
	ldr r2, _080926DC
	cmp r3, r5
	bge _0809266E
	ldr r1, _080926E0
	adds r3, r5, 0
_0809265E:
	movs r7, 0
	ldrsh r0, [r1, r7]
	adds r6, r0
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bne _0809265E
	adds r3, r5, 0
_0809266E:
	str r6, [r4, 0x8]
	ldr r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	strb r0, [r4, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080926E8
	movs r0, 0
	strh r0, [r4, 0x2]
	ldr r1, _080926E0
	lsls r0, r3, 3
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	movs r3, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r3, r0
	bge _080926EC
	ldr r5, _080926E4
_0809269A:
	movs r0, 0x58
	adds r1, r6, 0
	muls r1, r0
	ldr r0, [r5]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080926CC
	mov r7, r12
	cmp r7, 0
	beq _080926BA
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _080926CC
_080926BA:
	mov r0, r8
	cmp r0, 0
	beq _080926C6
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	beq _080926CC
_080926C6:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
_080926CC:
	adds r3, 0x1
	adds r6, 0x1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r3, r0
	blt _0809269A
	b _080926EC
	.align 2, 0
_080926DC: .4byte gFriendAreas
_080926E0: .4byte gFriendAreaSettings
_080926E4: .4byte gRecruitedPokemonRef
_080926E8:
	strh r0, [r4, 0x2]
	strh r0, [r4]
_080926EC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8092638

	thumb_func_start sub_80926F8
sub_80926F8:
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r2, 24
	lsrs r7, r2, 24
	movs r5, 0
	movs r2, 0
	ldr r0, _08092780
	mov r12, r0
	cmp r2, r3
	bge _08092724
	ldr r1, _08092784
	adds r2, r3, 0
_08092714:
	movs r6, 0
	ldrsh r0, [r1, r6]
	adds r5, r0
	adds r1, 0x8
	subs r2, 0x1
	cmp r2, 0
	bne _08092714
	adds r2, r3, 0
_08092724:
	str r5, [r4, 0x8]
	mov r1, r12
	ldr r0, [r1]
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r4, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0809279C
	movs r0, 0
	strh r0, [r4, 0x2]
	ldr r1, _08092784
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r0, 0
	ble _080927A0
	ldr r6, _08092788
	adds r2, r0, 0
_08092752:
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r6]
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092792
	ldrb r0, [r3, 0x2]
	cmp r0, 0
	bne _08092776
	cmp r7, 0
	bne _0809278C
	ldrb r0, [r3, 0x4]
	cmp r0, 0x41
	bne _0809278C
_08092776:
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	b _08092792
	.align 2, 0
_08092780: .4byte gFriendAreas
_08092784: .4byte gFriendAreaSettings
_08092788: .4byte gRecruitedPokemonRef
_0809278C:
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
_08092792:
	subs r2, 0x1
	adds r5, 0x1
	cmp r2, 0
	bne _08092752
	b _080927A0
_0809279C:
	strh r0, [r4, 0x2]
	strh r0, [r4]
_080927A0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80926F8

        .align 2,0 @ Don't pad with nop

