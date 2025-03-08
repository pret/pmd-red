	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



	thumb_func_start sub_804151C
sub_804151C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r4, r2, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_800DC9C
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8041550
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_804151C

	thumb_func_start sub_8041550
sub_8041550:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r7, r0, 0
	mov r10, r1
	ldr r0, [sp, 0x54]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x2C]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r7, 0
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	ldr r0, [r7, 0x70]
	mov r8, r0
	adds r0, r7, 0
	bl sub_8042768
	lsls r0, 24
	cmp r0, 0
	beq _0804159C
	cmp r6, 0
	bne _080415A2
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080415A2
_0804159C:
	movs r0, 0x1
	negs r0, r0
	b _08041692
_080415A2:
	ldr r1, [sp, 0x50]
	cmp r1, 0
	beq _080415B4
	movs r0, 0
	cmp r1, 0x2
	bne _080415B0
	movs r0, 0x1
_080415B0:
	bl sub_804178C
_080415B4:
	add r6, sp, 0x28
	adds r1, r7, 0
	adds r1, 0x28
	adds r0, r6, 0
	mov r2, r9
	bl sub_800569C
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0x63
	beq _080415F2
	ldrh r0, [r6, 0x2]
	cmp r0, 0x63
	beq _080415F2
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsls r0, 8
	ldr r1, [r7, 0xC]
	adds r4, r1, r0
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	lsls r0, 8
	ldr r2, [r7, 0x10]
	adds r0, r2, r0
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	ldr r1, [r1]
	subs r5, r0, r1
	adds r1, r2, 0
	b _08041600
_080415F2:
	ldr r4, [r7, 0xC]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r8
	ldr r1, [r7, 0x10]
	ldr r0, [r0]
	subs r5, r1, r0
_08041600:
	cmp r1, 0
	bge _08041606
	adds r1, 0xFF
_08041606:
	asrs r1, 8
	ldr r0, _0804166C
	ldr r0, [r0]
	ldr r2, _08041670
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r1, r0
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r1, r0, 1
	adds r1, 0x1
	mov r0, r10
	str r0, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r6, 0x1
	negs r6, r6
	str r6, [sp, 0x8]
	mov r2, sp
	adds r0, r4, 0
	cmp r4, 0
	bge _08041636
	adds r0, 0xFF
_08041636:
	asrs r0, 8
	strh r0, [r2, 0xC]
	mov r2, sp
	adds r0, r5, 0
	cmp r0, 0
	bge _08041644
	adds r0, 0xFF
_08041644:
	asrs r0, 8
	strh r0, [r2, 0xE]
	str r6, [sp, 0x14]
	mov r0, sp
	strh r3, [r0, 0x10]
	strh r3, [r0, 0x12]
	str r1, [sp, 0x18]
	add r0, sp, 0x1C
	bl sub_8004E8C
	mov r0, sp
	movs r1, 0
	bl sub_8041764
	adds r4, r0, 0
	ldr r1, [sp, 0x2C]
	cmp r1, 0
	beq _08041690
	movs r5, 0
	b _0804167C
	.align 2, 0
_0804166C: .4byte gDungeon
_08041670: .4byte 0x000181f2
_08041674:
	movs r0, 0x42
	bl sub_803E46C
	adds r5, 0x1
_0804167C:
	cmp r5, 0x63
	bgt _0804168C
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08041674
_0804168C:
	movs r4, 0x1
	negs r4, r4
_08041690:
	adds r0, r4, 0
_08041692:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8041550

        .align 2,0
