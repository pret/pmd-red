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

	.align 2, 0
