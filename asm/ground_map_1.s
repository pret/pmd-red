	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80A5204
sub_80A5204:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	mov r8, r1
	str r2, [sp, 0x4]
	str r3, [sp, 0x8]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bgt _080A5222
	b _080A53EA
_080A5222:
	mov r5, r8
	ldr r2, [sp]
	mov r12, r2
	movs r0, 0
	ldr r3, [sp, 0x4]
	ldrb r3, [r3, 0x1]
	str r3, [sp, 0x10]
	ldr r1, [sp, 0x4]
	ldrh r2, [r1, 0xA]
	mov r1, sp
	strh r2, [r1, 0xC]
	movs r1, 0xFF
_080A523A:
	adds r0, 0x1
	mov r10, r0
	movs r3, 0xFF
	mov r9, r3
_080A5242:
	mov r0, r12
	strb r1, [r0]
	movs r2, 0x1
	add r12, r2
	movs r3, 0x1
	negs r3, r3
	add r9, r3
	mov r0, r9
	cmp r0, 0
	bge _080A5242
	mov r0, r10
	cmp r0, 0x3
	ble _080A523A
	movs r1, 0
	ldr r2, [sp, 0x10]
	cmp r1, r2
	blt _080A5266
	b _080A53BA
_080A5266:
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
_080A526A:
	adds r0, 0x1
	mov r10, r0
	adds r0, r1, 0x1
	str r0, [sp, 0x14]
	movs r0, 0xFF
	movs r2, 0x4
	mov r9, r2
_080A5278:
	mov r3, r12
	strb r0, [r3]
	movs r2, 0x1
	add r12, r2
	movs r3, 0x1
	negs r3, r3
	add r9, r3
	mov r2, r9
	cmp r2, 0
	bge _080A5278
	movs r3, 0x5
	mov r9, r3
	movs r0, 0
	cmp r1, 0
	bne _080A5308
	cmp r1, r7
	bge _080A5394
_080A529A:
	ldrb r1, [r5]
	adds r5, 0x1
	cmp r1, 0xBF
	ble _080A52C2
	adds r6, r0, 0
	subs r6, 0xBF
	cmp r1, 0xBF
	ble _080A5300
	adds r2, r1, 0
	subs r2, 0xBF
_080A52AE:
	ldrb r0, [r5]
	mov r3, r12
	strb r0, [r3]
	adds r5, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A52AE
	b _080A5300
_080A52C2:
	cmp r1, 0x7F
	ble _080A52E6
	ldrb r4, [r5]
	adds r5, 0x1
	adds r6, r0, 0
	subs r6, 0x7F
	cmp r1, 0x7F
	ble _080A5300
	adds r2, r1, 0
	subs r2, 0x7F
_080A52D6:
	mov r3, r12
	strb r4, [r3]
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A52D6
	b _080A5300
_080A52E6:
	movs r2, 0
	adds r6, r0, 0x1
	cmp r2, r1
	bgt _080A5300
	movs r0, 0
	adds r2, r1, 0x1
_080A52F2:
	mov r3, r12
	strb r0, [r3]
	movs r3, 0x1
	add r12, r3
	subs r2, 0x1
	cmp r2, 0
	bne _080A52F2
_080A5300:
	adds r0, r6, r1
	cmp r0, r7
	blt _080A529A
	b _080A5394
_080A5308:
	ldr r4, _080A5340
	add r4, r12
	cmp r0, r7
	bge _080A5394
_080A5310:
	ldrb r3, [r5]
	adds r5, 0x1
	cmp r3, 0xBF
	ble _080A5344
	adds r6, r0, 0
	subs r6, 0xBF
	cmp r3, 0xBF
	ble _080A538E
	adds r2, r3, 0
	subs r2, 0xBF
_080A5324:
	ldrb r1, [r5]
	ldrb r0, [r4]
	eors r1, r0
	mov r0, r12
	strb r1, [r0]
	adds r4, 0x1
	adds r5, 0x1
	movs r1, 0x1
	add r12, r1
	subs r2, 0x1
	cmp r2, 0
	bne _080A5324
	b _080A538E
	.align 2, 0
_080A5340: .4byte 0xffffff00
_080A5344:
	cmp r3, 0x7F
	ble _080A5372
	ldrb r2, [r5]
	mov r8, r2
	adds r5, 0x1
	adds r6, r0, 0
	subs r6, 0x7F
	cmp r3, 0x7F
	ble _080A538E
	adds r2, r3, 0
	subs r2, 0x7F
_080A535A:
	ldrb r1, [r4]
	mov r0, r8
	eors r0, r1
	mov r1, r12
	strb r0, [r1]
	adds r4, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A535A
	b _080A538E
_080A5372:
	movs r2, 0
	adds r6, r0, 0x1
	cmp r2, r3
	bgt _080A538E
	adds r2, r3, 0x1
_080A537C:
	ldrb r0, [r4]
	mov r1, r12
	strb r0, [r1]
	adds r4, 0x1
	movs r0, 0x1
	add r12, r0
	subs r2, 0x1
	cmp r2, 0
	bne _080A537C
_080A538E:
	adds r0, r6, r3
	cmp r0, r7
	blt _080A5310
_080A5394:
	add r9, r7
	mov r1, r9
	cmp r1, 0xFF
	bgt _080A53AE
	movs r0, 0xFF
_080A539E:
	mov r2, r12
	strb r0, [r2]
	movs r3, 0x1
	add r12, r3
	add r9, r3
	mov r1, r9
	cmp r1, 0xFF
	ble _080A539E
_080A53AE:
	ldr r1, [sp, 0x14]
	mov r0, r10
	ldr r2, [sp, 0x10]
	cmp r1, r2
	bge _080A53BA
	b _080A526A
_080A53BA:
	ldr r3, [sp, 0x8]
	cmp r0, r3
	bge _080A53E6
	movs r1, 0xFF
_080A53C2:
	adds r0, 0x1
	mov r10, r0
	movs r0, 0xFF
	mov r9, r0
_080A53CA:
	mov r2, r12
	strb r1, [r2]
	movs r3, 0x1
	add r12, r3
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r2, r9
	cmp r2, 0
	bge _080A53CA
	mov r0, r10
	ldr r3, [sp, 0x8]
	cmp r0, r3
	blt _080A53C2
_080A53E6:
	mov r8, r5
	b _080A547E
_080A53EA:
	ldr r1, [sp]
	movs r0, 0
	ldr r2, [sp, 0x4]
	ldrb r2, [r2, 0x1]
	str r2, [sp, 0x10]
	ldr r3, [sp, 0x4]
	ldrh r2, [r3, 0xA]
	mov r3, sp
	strh r2, [r3, 0xC]
	movs r6, 0xFF
_080A53FE:
	adds r5, r0, 0x1
	movs r4, 0xFF
_080A5402:
	strb r6, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A5402
	adds r0, r5, 0
	cmp r0, 0x3
	ble _080A53FE
	movs r4, 0
	ldr r3, [sp, 0x10]
	cmp r4, r3
	bge _080A5460
	ldr r2, [sp, 0x4]
	ldrb r7, [r2]
	movs r3, 0xFF
_080A5420:
	adds r5, r0, 0x1
	adds r2, r4, 0x1
	movs r4, 0x4
_080A5426:
	strb r3, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A5426
	movs r4, 0x5
	cmp r7, 0
	beq _080A5444
	movs r6, 0
	adds r0, r7, 0
_080A543A:
	strb r6, [r1]
	adds r1, 0x1
	subs r0, 0x1
	cmp r0, 0
	bne _080A543A
_080A5444:
	adds r4, r7
	cmp r4, 0xFF
	bgt _080A5456
	movs r0, 0xFF
_080A544C:
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0xFF
	ble _080A544C
_080A5456:
	adds r4, r2, 0
	adds r0, r5, 0
	ldr r2, [sp, 0x10]
	cmp r4, r2
	blt _080A5420
_080A5460:
	ldr r3, [sp, 0x8]
	cmp r0, r3
	bge _080A547E
	movs r6, 0xFF
_080A5468:
	adds r5, r0, 0x1
	movs r4, 0xFF
_080A546C:
	strb r6, [r1]
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _080A546C
	adds r0, r5, 0
	ldr r2, [sp, 0x8]
	cmp r0, r2
	blt _080A5468
_080A547E:
	mov r3, sp
	ldrh r3, [r3, 0xC]
	lsls r0, r3, 16
	cmp r0, 0
	bgt _080A548A
	b _080A5590
_080A548A:
	mov r6, r8
	ldr r0, [sp]
	movs r1, 0x80
	lsls r1, 3
	adds r2, r0, r1
	movs r0, 0
	ldr r3, [sp, 0x10]
	cmp r0, r3
	bge _080A5586
	movs r1, 0xFB
	mov r10, r1
_080A54A0:
	adds r2, 0x5
	movs r4, 0
	cmp r0, 0
	bne _080A54EC
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	movs r1, 0x1
	mov r9, r1
	cmp r0, r7
	bge _080A5574
_080A54B4:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0x7F
	ble _080A54DE
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A54D6
	movs r5, 0x80
	adds r3, r1, 0
	subs r3, 0x7F
_080A54C8:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A54C8
_080A54D6:
	adds r4, r1
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	b _080A54E6
_080A54DE:
	adds r0, r1, 0x1
	adds r2, r0
	adds r0, r4, 0x1
	adds r4, r0, r1
_080A54E6:
	cmp r4, r7
	blt _080A54B4
	b _080A5574
_080A54EC:
	ldr r1, _080A5538
	adds r1, r2
	mov r12, r1
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	adds r0, 0x1
	mov r9, r0
	cmp r4, r7
	bge _080A5574
_080A54FE:
	ldrb r5, [r6]
	adds r6, 0x1
	cmp r5, 0x7F
	ble _080A553C
	subs r4, 0x7F
	cmp r5, 0x7F
	ble _080A556A
	movs r7, 0x80
	movs r0, 0x80
	mov r8, r0
	adds r3, r5, 0
	subs r3, 0x7F
_080A5516:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	bne _080A552C
	ldrb r0, [r2]
	orrs r0, r7
	strb r0, [r2]
_080A552C:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A5516
	b _080A556A
	.align 2, 0
_080A5538: .4byte 0xffffff00
_080A553C:
	movs r3, 0
	adds r4, 0x1
	cmp r3, r5
	bgt _080A556A
	movs r7, 0x80
	movs r3, 0x80
	mov r8, r3
	adds r3, r5, 0x1
_080A554C:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	beq _080A5562
	ldrb r0, [r2]
	orrs r0, r7
	strb r0, [r2]
_080A5562:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A554C
_080A556A:
	adds r4, r5
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	cmp r4, r7
	blt _080A54FE
_080A5574:
	mov r1, r10
	subs r0, r1, r7
	adds r2, r0
	mov r0, r9
	ldr r3, [sp, 0x4]
	ldrb r3, [r3, 0x1]
	str r3, [sp, 0x10]
	cmp r0, r3
	blt _080A54A0
_080A5586:
	mov r8, r6
	ldr r0, [sp, 0x4]
	ldrh r1, [r0, 0xA]
	mov r0, sp
	strh r1, [r0, 0xC]
_080A5590:
	mov r2, sp
	ldrh r2, [r2, 0xC]
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _080A568C
	mov r6, r8
	ldr r3, [sp]
	movs r0, 0x80
	lsls r0, 3
	adds r2, r3, r0
	movs r0, 0
	b _080A5684
_080A55AA:
	adds r2, 0x5
	movs r4, 0
	cmp r0, 0
	bne _080A55F2
	ldr r3, [sp, 0x4]
	ldrb r7, [r3]
	movs r1, 0x1
	mov r10, r1
	cmp r0, r7
	bge _080A567C
_080A55BE:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0x7F
	ble _080A55E4
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A55E0
	movs r5, 0x40
	adds r3, r1, 0
	subs r3, 0x7F
_080A55D2:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A55D2
_080A55E0:
	adds r4, r1
	b _080A55EC
_080A55E4:
	adds r0, r1, 0x1
	adds r2, r0
	adds r0, r4, 0x1
	adds r4, r0, r1
_080A55EC:
	cmp r4, r7
	blt _080A55BE
	b _080A567C
_080A55F2:
	ldr r3, _080A5640
	adds r3, r2
	mov r12, r3
	ldr r1, [sp, 0x4]
	ldrb r7, [r1]
	adds r0, 0x1
	mov r10, r0
	cmp r4, r7
	bge _080A567C
_080A5604:
	ldrb r5, [r6]
	adds r6, 0x1
	cmp r5, 0x7F
	ble _080A5644
	subs r4, 0x7F
	cmp r5, 0x7F
	ble _080A5676
	movs r3, 0x40
	mov r8, r3
	movs r0, 0x40
	mov r9, r0
	adds r3, r5, 0
	subs r3, 0x7F
_080A561E:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r9
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	bne _080A5636
	ldrb r0, [r2]
	mov r1, r8
	orrs r0, r1
	strb r0, [r2]
_080A5636:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A561E
	b _080A5676
	.align 2, 0
_080A5640: .4byte 0xffffff00
_080A5644:
	movs r3, 0
	adds r4, 0x1
	cmp r3, r5
	bgt _080A5676
	movs r3, 0x40
	mov r8, r3
	movs r0, 0x40
	mov r9, r0
	adds r3, r5, 0x1
_080A5656:
	mov r0, r12
	ldrb r1, [r0]
	mov r0, r9
	ands r0, r1
	movs r1, 0x1
	add r12, r1
	cmp r0, 0
	beq _080A566E
	ldrb r0, [r2]
	mov r1, r8
	orrs r0, r1
	strb r0, [r2]
_080A566E:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _080A5656
_080A5676:
	adds r4, r5
	cmp r4, r7
	blt _080A5604
_080A567C:
	movs r3, 0xFB
	subs r0, r3, r7
	adds r2, r0
	mov r0, r10
_080A5684:
	ldr r1, [sp, 0x10]
	cmp r0, r1
	blt _080A55AA
	mov r8, r6
_080A568C:
	mov r0, r8
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A5204

	thumb_func_start sub_80A56A0
sub_80A56A0:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, _080A56BC
	ldr r0, [r0]
	adds r1, r3, 0
	bl sub_80A3B80
	pop {r0}
	bx r0
	.align 2, 0
_080A56BC: .4byte gGroundMapDungeon_3001B70
	thumb_func_end sub_80A56A0

	thumb_func_start sub_80A56C0
sub_80A56C0:
	push {lr}
	adds r2, r0, 0
	ldr r0, _080A56D4
	ldr r0, [r0]
	movs r1, 0
	bl sub_80A4558
	pop {r0}
	bx r0
	.align 2, 0
_080A56D4: .4byte gGroundMapDungeon_3001B70
	thumb_func_end sub_80A56C0

	thumb_func_start sub_80A56D8
sub_80A56D8:
	push {lr}
	adds r2, r0, 0
	ldr r0, _080A56EC
	ldr r0, [r0]
	movs r1, 0
	bl sub_80A456C
	pop {r0}
	bx r0
	.align 2, 0
_080A56EC: .4byte gGroundMapDungeon_3001B70
	thumb_func_end sub_80A56D8

	thumb_func_start sub_80A56F0
sub_80A56F0:
	ldr r1, _080A5700
	ldr r2, [r1]
	adds r2, 0xE8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.align 2, 0
_080A5700: .4byte gGroundMapAction
	thumb_func_end sub_80A56F0

	thumb_func_start sub_80A5704
sub_80A5704:
	ldr r1, _080A5724
	ldr r3, [r1]
	adds r2, r3, 0
	adds r2, 0xF8
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r3, 0
	adds r0, 0xF0
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	bx lr
	.align 2, 0
_080A5724: .4byte gGroundMapAction
	thumb_func_end sub_80A5704

	thumb_func_start sub_80A5728
sub_80A5728:
	ldr r0, _080A5734
	ldr r0, [r0]
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A5734: .4byte gGroundMapAction
	thumb_func_end sub_80A5728

	thumb_func_start sub_80A5738
sub_80A5738:
	ldr r0, _080A5750
	ldr r0, [r0]
	adds r0, 0xE4
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, _080A5754
	adds r0, r1
	bx lr
	.align 2, 0
_080A5750: .4byte gGroundMapAction
_080A5754: .4byte gGroundMapConversionTable
	thumb_func_end sub_80A5738

	thumb_func_start sub_80A5758
sub_80A5758:
	push {lr}
	adds r1, r0, 0
	ldr r0, _080A5768
	ldr r0, [r0]
	cmp r0, 0
	bne _080A576C
	movs r0, 0
	b _080A5772
	.align 2, 0
_080A5768: .4byte gGroundMapDungeon_3001B70
_080A576C:
	bl sub_80A4608
	movs r0, 0x1
_080A5772:
	pop {r1}
	bx r1
	thumb_func_end sub_80A5758

	thumb_func_start GetCurrentDungeonBounds
GetCurrentDungeonBounds:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080A578C
	ldr r0, [r0]
	cmp r0, 0
	bne _080A5790
	movs r0, 0
	b _080A5798
	.align 2, 0
_080A578C: .4byte gGroundMapDungeon_3001B70
_080A5790:
	adds r1, r3, 0
	bl GetDungeonBounds
	movs r0, 0x1
_080A5798:
	pop {r1}
	bx r1
	thumb_func_end GetCurrentDungeonBounds

	thumb_func_start sub_80A579C
sub_80A579C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r0, _080A5838
	ldr r3, [r0]
	cmp r3, 0
	beq _080A5854
	ldr r0, _080A583C
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xE4
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A5854
	adds r0, r1, 0
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	ldr r0, _080A5840
	adds r4, r0
	adds r0, r3, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GetDungeonBounds
	ldr r2, [r6]
	mov r12, r2
	movs r0, 0xF0
	lsls r0, 7
	add r0, r12
	str r0, [r6]
	ldr r3, [r6, 0x4]
	movs r7, 0xA0
	lsls r7, 7
	adds r0, r3, r7
	str r0, [r6, 0x4]
	ldr r2, [r5]
	ldr r1, _080A5844
	adds r0, r2, r1
	str r0, [r5]
	ldr r1, [r5, 0x4]
	ldr r7, _080A5848
	adds r0, r1, r7
	str r0, [r5, 0x4]
	movs r7, 0
	ldrsh r0, [r4, r7]
	cmp r0, 0xA
	bne _080A581E
	movs r0, 0x90
	lsls r0, 8
	add r0, r12
	str r0, [r6]
	movs r4, 0xD0
	lsls r4, 7
	adds r0, r3, r4
	str r0, [r6, 0x4]
	ldr r7, _080A584C
	adds r0, r2, r7
	str r0, [r5]
	ldr r2, _080A5850
	adds r0, r1, r2
	str r0, [r5, 0x4]
_080A581E:
	ldr r1, [r6]
	ldr r0, [r5]
	cmp r1, r0
	ble _080A5828
	str r1, [r5]
_080A5828:
	ldr r1, [r6, 0x4]
	ldr r0, [r5, 0x4]
	cmp r1, r0
	ble _080A5832
	str r1, [r5, 0x4]
_080A5832:
	movs r0, 0x1
	b _080A5856
	.align 2, 0
_080A5838: .4byte gGroundMapDungeon_3001B70
_080A583C: .4byte gGroundMapAction
_080A5840: .4byte gGroundMapConversionTable
_080A5844: .4byte 0xffff8800
_080A5848: .4byte 0xffffb000
_080A584C: .4byte 0xffff7000
_080A5850: .4byte 0xffff9800
_080A5854:
	movs r0, 0
_080A5856:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A579C

	thumb_func_start CheckMapCollision_80A585C
CheckMapCollision_80A585C:
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r1, _080A5884
	ldr r2, [r1]
	ldr r1, _080A5888
	adds r2, r1
	ldr r1, [r0, 0x4]
	lsls r1, 8
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _080A588C
	adds r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r4, [r7, 0x4]
	cmp r0, 0
	bne _080A5890
_080A587E:
	movs r0, 0x1
	b _080A58C0
	.align 2, 0
_080A5884: .4byte gGroundMapDungeon_3001B70
_080A5888: .4byte 0x00000544
_080A588C: .4byte 0x00000405
_080A5890:
	cmp r4, 0
	ble _080A58BE
	movs r1, 0x80
	lsls r1, 1
	mov r12, r1
_080A589A:
	ldr r2, [r7]
	adds r3, r5, 0
	cmp r2, 0
	ble _080A58B6
	movs r6, 0x80
_080A58A4:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	adds r3, 0x1
	cmp r0, 0
	bne _080A587E
	subs r2, 0x1
	cmp r2, 0
	bgt _080A58A4
_080A58B6:
	add r5, r12
	subs r4, 0x1
	cmp r4, 0
	bgt _080A589A
_080A58BE:
	movs r0, 0
_080A58C0:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckMapCollision_80A585C

	thumb_func_start sub_80A58C8
sub_80A58C8:
	push {r4-r7,lr}
	adds r7, r1, 0
	ldr r1, _080A58F0
	ldr r2, [r1]
	ldr r1, _080A58F4
	adds r2, r1
	ldr r1, [r0, 0x4]
	lsls r1, 8
	ldr r0, [r0]
	adds r1, r0
	ldr r0, _080A58F8
	adds r1, r0
	ldr r0, [r2]
	adds r5, r0, r1
	ldr r4, [r7, 0x4]
	cmp r0, 0
	bne _080A58FC
_080A58EA:
	movs r0, 0x1
	b _080A592C
	.align 2, 0
_080A58F0: .4byte gGroundMapDungeon_3001B70
_080A58F4: .4byte 0x00000544
_080A58F8: .4byte 0x00000405
_080A58FC:
	cmp r4, 0
	ble _080A592A
	movs r1, 0x80
	lsls r1, 1
	mov r12, r1
_080A5906:
	ldr r2, [r7]
	adds r3, r5, 0
	cmp r2, 0
	ble _080A5922
	movs r6, 0x40
_080A5910:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	adds r3, 0x1
	cmp r0, 0
	bne _080A58EA
	subs r2, 0x1
	cmp r2, 0
	bgt _080A5910
_080A5922:
	add r5, r12
	subs r4, 0x1
	cmp r4, 0
	bgt _080A5906
_080A592A:
	movs r0, 0
_080A592C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A58C8

        .align 2,0
