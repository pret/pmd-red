	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_804A1F0
sub_804A1F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	ldr r2, _0804A284
	ldr r7, [r2]
	ldr r3, _0804A288
	adds r2, r7, r3
	ldrb r2, [r2]
	str r2, [sp]
	ldr r4, _0804A28C
	adds r2, r7, r4
	ldrb r2, [r2]
	str r2, [sp, 0x4]
	ldr r5, _0804A290
	adds r2, r7, r5
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r2, r0
	subs r4, 0x1D
	adds r0, r7, r4
	movs r5, 0
	ldrsh r0, [r0, r5]
	adds r0, r1
	asrs r0, 3
	asrs r2, 3
	str r2, [sp, 0x14]
	subs r1, r0, 0x1
	mov r9, r1
	ldr r3, _0804A294
	adds r1, r2, 0
	adds r1, 0x1E
	lsls r1, 1
	adds r2, r1, r3
	movs r5, 0
	ldrsh r4, [r2, r5]
	str r4, [sp, 0x10]
	ldr r2, _0804A298
	adds r1, r2
	movs r5, 0
	ldrsh r4, [r1, r5]
	str r4, [sp, 0xC]
	adds r0, 0x1D
	lsls r0, 1
	adds r3, r0, r3
	movs r4, 0
	ldrsh r1, [r3, r4]
	mov r8, r1
	adds r0, r2
	movs r1, 0
	ldrsh r5, [r0, r1]
	mov r10, r5
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	ldr r3, [sp, 0x10]
	adds r6, r3, r0
	ldr r0, [sp, 0xC]
	mov r1, r10
	bl GetTile
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804A2A0
	lsls r0, r6, 1
	ldr r4, _0804A29C
	adds r0, r4
	adds r2, r7, r0
	b _0804A356
	.align 2, 0
_0804A284: .4byte gDungeon
_0804A288: .4byte 0x00018210
_0804A28C: .4byte 0x0001820f
_0804A290: .4byte 0x000181f0
_0804A294: .4byte gUnknown_80F6A4A
_0804A298: .4byte gUnknown_80F6C06
_0804A29C: .4byte 0x00012bda
_0804A2A0:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	beq _0804A2B8
	lsls r0, r6, 1
	ldr r5, _0804A2B4
	adds r0, r5
	adds r2, r7, r0
	b _0804A356
	.align 2, 0
_0804A2B4: .4byte 0x00012bec
_0804A2B8:
	ldr r0, [sp]
	cmp r0, 0
	beq _0804A2D0
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r2, _0804A2CC
	adds r1, r2
	b _0804A350
	.align 2, 0
_0804A2CC: .4byte 0x00011884
_0804A2D0:
	ldr r4, [r5, 0x14]
	cmp r4, 0
	beq _0804A318
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _0804A304
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0804A2F0
	ldr r3, [sp, 0x4]
	cmp r3, 0
	beq _0804A304
_0804A2F0:
	ldr r0, [r4, 0x70]
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r4, _0804A300
	adds r0, r4
	b _0804A334
	.align 2, 0
_0804A300: .4byte 0x00012a18
_0804A304:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r5, _0804A314
	adds r1, r5
	b _0804A350
	.align 2, 0
_0804A314: .4byte 0x00011884
_0804A318:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _0804A344
	ldr r1, _0804A33C
	adds r0, r7, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r3, _0804A340
	adds r0, r3
_0804A334:
	adds r0, r7, r0
	lsls r1, r6, 1
	adds r2, r0, r1
	b _0804A356
	.align 2, 0
_0804A33C: .4byte 0x00003a12
_0804A340: .4byte 0x00012a18
_0804A344:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r4, _0804A3AC
	adds r1, r4
_0804A350:
	adds r1, r7, r1
	lsls r0, r6, 1
	adds r2, r1, r0
_0804A356:
	movs r5, 0x16
	str r5, [sp, 0x8]
_0804A35A:
	movs r0, 0x1F
	ldr r1, [sp, 0x14]
	ands r1, r0
	str r1, [sp, 0x14]
	mov r3, r9
	ands r3, r0
	mov r9, r3
	lsls r1, 1
	lsls r0, r3, 6
	adds r1, r0
	ldr r4, _0804A3B0
	adds r1, r4
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x6
	movs r5, 0x1
	add r9, r5
	add r8, r5
	mov r0, r8
	cmp r0, 0x3
	beq _0804A386
	b _0804A476
_0804A386:
	movs r1, 0
	mov r8, r1
	add r10, r5
	ldr r6, [sp, 0x10]
	ldr r0, [sp, 0xC]
	mov r1, r10
	bl GetTile
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804A3B8
	lsls r0, r6, 1
	ldr r2, _0804A3B4
	adds r0, r2
	adds r2, r7, r0
	b _0804A476
	.align 2, 0
_0804A3AC: .4byte 0x00011884
_0804A3B0: .4byte gUnknown_202C838
_0804A3B4: .4byte 0x00012bda
_0804A3B8:
	movs r3, 0x80
	lsls r3, 5
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0804A3D4
	lsls r0, r6, 1
	ldr r4, _0804A3D0
	adds r0, r4
	adds r2, r7, r0
	b _0804A476
	.align 2, 0
_0804A3D0: .4byte 0x00012bec
_0804A3D4:
	ldr r0, [sp]
	cmp r0, 0
	beq _0804A3EC
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r2, _0804A3E8
	adds r1, r2
	b _0804A470
	.align 2, 0
_0804A3E8: .4byte 0x00011884
_0804A3EC:
	ldr r4, [r5, 0x14]
	cmp r4, 0
	beq _0804A434
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _0804A420
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0804A40C
	ldr r3, [sp, 0x4]
	cmp r3, 0
	beq _0804A420
_0804A40C:
	ldr r0, [r4, 0x70]
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r4, _0804A41C
	adds r0, r4
	b _0804A452
	.align 2, 0
_0804A41C: .4byte 0x00012a18
_0804A420:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r5, _0804A430
	adds r1, r5
	b _0804A470
	.align 2, 0
_0804A430: .4byte 0x00011884
_0804A434:
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0804A464
	ldr r3, _0804A45C
	adds r0, r7, r3
	movs r4, 0
	ldrsh r1, [r0, r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r5, _0804A460
	adds r0, r5
_0804A452:
	adds r0, r7, r0
	lsls r1, r6, 1
	adds r2, r0, r1
	b _0804A476
	.align 2, 0
_0804A45C: .4byte 0x00003a12
_0804A460: .4byte 0x00012a18
_0804A464:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r0, _0804A498
	adds r1, r0
_0804A470:
	adds r1, r7, r1
	lsls r0, r6, 1
	adds r2, r1, r0
_0804A476:
	ldr r1, [sp, 0x8]
	subs r1, 0x1
	str r1, [sp, 0x8]
	cmp r1, 0
	blt _0804A482
	b _0804A35A
_0804A482:
	movs r0, 0x3
	bl sub_80098F8
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804A498: .4byte 0x00011884
	thumb_func_end sub_804A1F0

	thumb_func_start sub_804A49C
sub_804A49C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	ldr r2, _0804A52C
	ldr r7, [r2]
	ldr r3, _0804A530
	adds r2, r7, r3
	ldrb r2, [r2]
	str r2, [sp]
	ldr r4, _0804A534
	adds r2, r7, r4
	ldrb r2, [r2]
	str r2, [sp, 0x4]
	subs r3, 0x20
	adds r2, r7, r3
	movs r4, 0
	ldrsh r2, [r2, r4]
	adds r2, r0
	adds r3, 0x2
	adds r0, r7, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r0, r1
	asrs r2, 3
	mov r8, r2
	asrs r0, 3
	str r0, [sp, 0x14]
	ldr r2, _0804A538
	mov r0, r8
	adds r0, 0x1E
	lsls r0, 1
	adds r1, r0, r2
	movs r4, 0
	ldrsh r3, [r1, r4]
	mov r9, r3
	ldr r1, _0804A53C
	adds r0, r1
	movs r4, 0
	ldrsh r3, [r0, r4]
	mov r10, r3
	ldr r0, [sp, 0x14]
	adds r0, 0x1E
	lsls r0, 1
	adds r2, r0, r2
	movs r4, 0
	ldrsh r3, [r2, r4]
	str r3, [sp, 0x10]
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	str r1, [sp, 0xC]
	lsls r0, r3, 1
	adds r0, r3
	mov r3, r9
	adds r6, r3, r0
	mov r0, r10
	bl GetTile
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804A544
	lsls r0, r6, 1
	ldr r4, _0804A540
	adds r0, r4
	adds r2, r7, r0
	b _0804A5DA
	.align 2, 0
_0804A52C: .4byte gDungeon
_0804A530: .4byte 0x00018210
_0804A534: .4byte 0x0001820f
_0804A538: .4byte gUnknown_80F6A4A
_0804A53C: .4byte gUnknown_80F6C06
_0804A540: .4byte 0x00012bda
_0804A544:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	beq _0804A55C
	lsls r0, r6, 1
	ldr r1, _0804A558
	adds r0, r1
	adds r2, r7, r0
	b _0804A5DA
	.align 2, 0
_0804A558: .4byte 0x00012bec
_0804A55C:
	ldr r2, [sp]
	cmp r2, 0
	beq _0804A574
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r3, _0804A570
	adds r1, r3
	b _0804A5D4
	.align 2, 0
_0804A570: .4byte 0x00011884
_0804A574:
	ldr r4, [r5, 0x14]
	cmp r4, 0
	beq _0804A59A
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _0804A5C8
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0804A594
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _0804A5C8
_0804A594:
	ldr r0, [r4, 0x70]
	ldrb r1, [r0]
	b _0804A5AC
_0804A59A:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _0804A5C8
	ldr r3, _0804A5C0
	adds r0, r7, r3
	movs r4, 0
	ldrsh r1, [r0, r4]
_0804A5AC:
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r1, _0804A5C4
	adds r0, r1
	adds r0, r7, r0
	lsls r1, r6, 1
	adds r2, r0, r1
	b _0804A5DA
	.align 2, 0
_0804A5C0: .4byte 0x00003a12
_0804A5C4: .4byte 0x00012a18
_0804A5C8:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r2, _0804A638
	adds r1, r2
_0804A5D4:
	adds r1, r7, r1
	lsls r0, r6, 1
	adds r2, r1, r0
_0804A5DA:
	movs r3, 0x1E
	str r3, [sp, 0x8]
_0804A5DE:
	movs r0, 0x1F
	mov r4, r8
	ands r4, r0
	mov r8, r4
	ldr r1, [sp, 0x14]
	ands r1, r0
	str r1, [sp, 0x14]
	lsls r1, r4, 1
	ldr r3, [sp, 0x14]
	lsls r0, r3, 6
	adds r1, r0
	ldr r4, _0804A63C
	adds r1, r4
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	movs r0, 0x1
	add r8, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0x3
	beq _0804A60C
	b _0804A702
_0804A60C:
	movs r2, 0
	mov r9, r2
	add r10, r0
	ldr r3, [sp, 0x10]
	lsls r0, r3, 1
	adds r6, r0, r3
	mov r0, r10
	ldr r1, [sp, 0xC]
	bl GetTile
	adds r5, r0, 0
	ldrh r1, [r5]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804A644
	lsls r0, r6, 1
	ldr r4, _0804A640
	adds r0, r4
	adds r2, r7, r0
	b _0804A702
	.align 2, 0
_0804A638: .4byte 0x00011884
_0804A63C: .4byte gUnknown_202C838
_0804A640: .4byte 0x00012bda
_0804A644:
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0804A660
	lsls r0, r6, 1
	ldr r3, _0804A65C
	adds r0, r3
	adds r2, r7, r0
	b _0804A702
	.align 2, 0
_0804A65C: .4byte 0x00012bec
_0804A660:
	ldr r4, [sp]
	cmp r4, 0
	beq _0804A678
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r0, _0804A674
	adds r1, r0
	b _0804A6FC
	.align 2, 0
_0804A674: .4byte 0x00011884
_0804A678:
	ldr r4, [r5, 0x14]
	cmp r4, 0
	beq _0804A6C0
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _0804A6AC
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0804A698
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _0804A6AC
_0804A698:
	ldr r0, [r4, 0x70]
	ldrb r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r2, _0804A6A8
	adds r0, r2
	b _0804A6DE
	.align 2, 0
_0804A6A8: .4byte 0x00012a18
_0804A6AC:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r3, _0804A6BC
	adds r1, r3
	b _0804A6FC
	.align 2, 0
_0804A6BC: .4byte 0x00011884
_0804A6C0:
	movs r4, 0x80
	lsls r4, 2
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0804A6F0
	ldr r1, _0804A6E8
	adds r0, r7, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r3, _0804A6EC
	adds r0, r3
_0804A6DE:
	adds r0, r7, r0
	lsls r1, r6, 1
	adds r2, r0, r1
	b _0804A702
	.align 2, 0
_0804A6E8: .4byte 0x00003a12
_0804A6EC: .4byte 0x00012a18
_0804A6F0:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 1
	ldr r4, _0804A724
	adds r1, r4
_0804A6FC:
	adds r1, r7, r1
	lsls r0, r6, 1
	adds r2, r1, r0
_0804A702:
	ldr r0, [sp, 0x8]
	subs r0, 0x1
	str r0, [sp, 0x8]
	cmp r0, 0
	blt _0804A70E
	b _0804A5DE
_0804A70E:
	movs r0, 0x3
	bl sub_80098F8
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804A724: .4byte 0x00011884
	thumb_func_end sub_804A49C

	thumb_func_start sub_804A728
sub_804A728:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	str r0, [sp, 0x1C]
	adds r5, r1, 0
	adds r4, r3, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x20]
	lsls r4, 24
	lsrs r4, 24
	ldr r6, _0804A814
	ldr r0, [r6]
	mov r8, r0
	bl GetLeader
	str r0, [sp, 0x24]
	ldr r0, _0804A818
	add r0, r8
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	str r0, [sp, 0x30]
	adds r1, r0, 0
	ldr r0, [r6]
	ldr r2, _0804A81C
	adds r0, r2
	strb r4, [r0]
	ldr r3, [sp, 0x1C]
	movs r4, 0
	ldrsh r7, [r3, r4]
	movs r0, 0x2
	ldrsh r6, [r3, r0]
	ldr r0, _0804A820
	lsls r5, 2
	adds r5, r0
	movs r2, 0
	ldrsh r4, [r5, r2]
	movs r0, 0x2
	ldrsh r3, [r5, r0]
	mov r0, sp
	movs r2, 0x5
_0804A782:
	strh r7, [r0]
	strh r6, [r0, 0x2]
	adds r7, r4
	adds r6, r3
	adds r0, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _0804A782
	ldr r0, _0804A824
	adds r1, 0x1E
	lsls r1, 1
	adds r0, r1, r0
	movs r3, 0
	ldrsh r2, [r0, r3]
	str r2, [sp, 0x28]
	ldr r0, _0804A828
	adds r1, r0
	movs r0, 0
	ldrsh r4, [r1, r0]
	mov r10, r4
	movs r7, 0
_0804A7AC:
	ldr r0, _0804A82C
	add r0, r8
	ldrh r0, [r0]
	lsls r0, 16
	asrs r0, 19
	str r0, [sp, 0x34]
	ldr r0, _0804A824
	ldr r1, [sp, 0x34]
	adds r1, 0x1E
	lsls r1, 1
	adds r0, r1, r0
	movs r3, 0
	ldrsh r2, [r0, r3]
	str r2, [sp, 0x2C]
	ldr r0, _0804A828
	adds r1, r0
	movs r0, 0
	ldrsh r4, [r1, r0]
	mov r9, r4
	lsls r0, r2, 1
	adds r0, r2
	ldr r1, [sp, 0x28]
	adds r5, r1, r0
	mov r2, r10
	lsls r0, r2, 16
	lsls r1, r4, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x18]
	ldr r3, [sp, 0x20]
	cmp r3, 0
	beq _0804A850
	ldr r4, [sp, 0x1C]
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r10, r0
	bne _0804A834
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r9, r0
	bne _0804A834
	lsls r0, r5, 1
	ldr r3, _0804A830
	adds r0, r3
	mov r4, r8
	adds r2, r4, r0
	ldr r0, [sp, 0x28]
	adds r0, 0x1
	str r0, [sp, 0x3C]
	adds r1, r7, 0x1
	str r1, [sp, 0x38]
	b _0804A8FC
	.align 2, 0
_0804A814: .4byte gDungeon
_0804A818: .4byte 0x000181f0
_0804A81C: .4byte 0x0001821a
_0804A820: .4byte gAdjacentTileOffsets
_0804A824: .4byte gUnknown_80F6A4A
_0804A828: .4byte gUnknown_80F6C06
_0804A82C: .4byte 0x000181f2
_0804A830: .4byte 0x00012b92
_0804A834:
	lsls r0, r5, 1
	ldr r2, _0804A84C
	adds r0, r2
	mov r3, r8
	adds r2, r3, r0
	ldr r4, [sp, 0x28]
	adds r4, 0x1
	str r4, [sp, 0x3C]
	adds r0, r7, 0x1
	str r0, [sp, 0x38]
	b _0804A8FC
	.align 2, 0
_0804A84C: .4byte 0x00013554
_0804A850:
	add r4, sp, 0x18
	ldr r0, [sp, 0x24]
	adds r1, r4, 0
	bl sub_807049C
	lsls r0, 24
	cmp r0, 0
	bne _0804A8E8
	ldr r0, [sp, 0x24]
	adds r1, r4, 0
	bl sub_8045AAC
	lsls r0, 24
	cmp r0, 0
	beq _0804A8E8
	movs r2, 0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r3, r5, 1
	ldr r4, [sp, 0x28]
	adds r4, 0x1
	str r4, [sp, 0x3C]
	adds r1, r7, 0x1
	str r1, [sp, 0x38]
	cmp r0, r10
	bne _0804A890
	mov r0, sp
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	cmp r0, r9
	beq _0804A8AC
_0804A890:
	adds r2, 0x1
	cmp r2, 0x5
	bgt _0804A8AC
	lsls r0, r2, 2
	mov r4, sp
	adds r1, r4, r0
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r10
	bne _0804A890
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r9
	bne _0804A890
_0804A8AC:
	cmp r2, 0x6
	bne _0804A8D8
	ldr r0, _0804A8C0
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _0804A8C8
	ldr r1, _0804A8C4
	adds r0, r3, r1
	b _0804A8DC
	.align 2, 0
_0804A8C0: .4byte gGameOptionsRef
_0804A8C4: .4byte 0x00012b80
_0804A8C8:
	ldr r4, _0804A8D4
	adds r0, r3, r4
	mov r1, r8
	adds r2, r1, r0
	b _0804A8FC
	.align 2, 0
_0804A8D4: .4byte 0x00013554
_0804A8D8:
	ldr r2, _0804A8E4
	adds r0, r3, r2
_0804A8DC:
	mov r3, r8
	adds r2, r3, r0
	b _0804A8FC
	.align 2, 0
_0804A8E4: .4byte 0x00012b92
_0804A8E8:
	lsls r0, r5, 1
	ldr r4, _0804A968
	adds r0, r4
	mov r1, r8
	adds r2, r1, r0
	ldr r3, [sp, 0x28]
	adds r3, 0x1
	str r3, [sp, 0x3C]
	adds r4, r7, 0x1
	str r4, [sp, 0x38]
_0804A8FC:
	movs r6, 0
_0804A8FE:
	movs r0, 0x1F
	ldr r1, [sp, 0x30]
	ands r1, r0
	str r1, [sp, 0x30]
	ldr r3, [sp, 0x34]
	ands r3, r0
	lsls r0, r1, 1
	lsls r1, r3, 6
	adds r0, r1
	ldr r4, _0804A96C
	adds r0, r4
	ldrh r1, [r2]
	strh r1, [r0]
	adds r2, 0x6
	adds r3, 0x1
	str r3, [sp, 0x34]
	ldr r0, [sp, 0x2C]
	adds r0, 0x1
	str r0, [sp, 0x2C]
	adds r7, r6, 0x1
	cmp r0, 0x3
	beq _0804A92C
	b _0804AA20
_0804A92C:
	movs r1, 0
	str r1, [sp, 0x2C]
	movs r2, 0x1
	add r9, r2
	ldr r5, [sp, 0x28]
	add r4, sp, 0x18
	mov r3, r10
	strh r3, [r4]
	adds r0, r4, 0
	mov r1, r9
	strh r1, [r0, 0x2]
	ldr r2, [sp, 0x20]
	cmp r2, 0
	beq _0804A984
	ldr r3, [sp, 0x1C]
	movs r4, 0
	ldrsh r0, [r3, r4]
	cmp r10, r0
	bne _0804A974
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r9, r0
	bne _0804A974
	ldr r2, [sp, 0x28]
	lsls r0, r2, 1
	ldr r3, _0804A970
	adds r0, r3
	mov r4, r8
	adds r2, r4, r0
	b _0804AA20
	.align 2, 0
_0804A968: .4byte 0x00013554
_0804A96C: .4byte gUnknown_202C038
_0804A970: .4byte 0x00012b92
_0804A974:
	lsls r0, r5, 1
	ldr r1, _0804A980
	adds r0, r1
	mov r3, r8
	adds r2, r3, r0
	b _0804AA1E
	.align 2, 0
_0804A980: .4byte 0x00013554
_0804A984:
	ldr r0, [sp, 0x24]
	adds r1, r4, 0
	bl sub_807049C
	lsls r0, 24
	cmp r0, 0
	bne _0804AA14
	ldr r0, [sp, 0x24]
	adds r1, r4, 0
	bl sub_8045AAC
	lsls r0, 24
	cmp r0, 0
	beq _0804AA14
	movs r2, 0
	mov r0, sp
	movs r4, 0
	ldrsh r0, [r0, r4]
	ldr r1, [sp, 0x28]
	lsls r3, r1, 1
	cmp r0, r10
	bne _0804A9BA
	mov r0, sp
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	cmp r0, r9
	beq _0804A9D6
_0804A9BA:
	adds r2, 0x1
	cmp r2, 0x5
	bgt _0804A9D6
	lsls r0, r2, 2
	mov r4, sp
	adds r1, r4, r0
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r10
	bne _0804A9BA
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r9
	bne _0804A9BA
_0804A9D6:
	cmp r2, 0x6
	bne _0804AA04
	ldr r0, _0804A9EC
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _0804A9F4
	ldr r1, _0804A9F0
	adds r0, r3, r1
	b _0804AA08
	.align 2, 0
_0804A9EC: .4byte gGameOptionsRef
_0804A9F0: .4byte 0x00012b80
_0804A9F4:
	ldr r4, _0804AA00
	adds r0, r3, r4
	mov r1, r8
	adds r2, r1, r0
	b _0804AA20
	.align 2, 0
_0804AA00: .4byte 0x00013554
_0804AA04:
	ldr r2, _0804AA10
	adds r0, r3, r2
_0804AA08:
	mov r3, r8
	adds r2, r3, r0
	b _0804AA20
	.align 2, 0
_0804AA10: .4byte 0x00012b92
_0804AA14:
	lsls r0, r5, 1
	ldr r4, _0804AA5C
	adds r0, r4
	mov r1, r8
	adds r2, r1, r0
_0804AA1E:
	adds r7, r6, 0x1
_0804AA20:
	adds r6, r7, 0
	cmp r6, 0x14
	bgt _0804AA28
	b _0804A8FE
_0804AA28:
	ldr r2, [sp, 0x30]
	adds r2, 0x1
	str r2, [sp, 0x30]
	ldr r3, [sp, 0x3C]
	str r3, [sp, 0x28]
	cmp r3, 0x3
	bne _0804AA3E
	movs r4, 0
	str r4, [sp, 0x28]
	movs r0, 0x1
	add r10, r0
_0804AA3E:
	ldr r7, [sp, 0x38]
	cmp r7, 0x1E
	bgt _0804AA46
	b _0804A7AC
_0804AA46:
	movs r0, 0x2
	bl sub_80098F8
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804AA5C: .4byte 0x00013554
	thumb_func_end sub_804A728

	.align 2, 0
