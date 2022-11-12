	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start xxx_dungeon_80442D0
xxx_dungeon_80442D0:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	bl GetLeaderEntity
	adds r5, r0, 0
	cmp r5, 0
	beq _0804431A
	bl TriggerWeatherAbilities
	adds r0, r5, 0
	bl GetMovementSpeed
	ldr r3, _08044320
	ldr r1, _08044324
	ldr r1, [r1]
	movs r2, 0xCC
	lsls r2, 3
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 1
	movs r2, 0x32
	muls r0, r2
	adds r1, r0
	adds r1, r3
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0804431A
	ldr r0, [r5, 0x70]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08044328
_0804431A:
	movs r0, 0
	b _0804444E
	.align 2, 0
_08044320: .4byte gSpeedTurns
_08044324: .4byte gDungeonGlobalData
_08044328:
	bl GetLeaderEntity
	adds r5, r0, 0
	cmp r5, 0
	beq _0804431A
	movs r0, 0
	bl UseAttack
	lsls r0, 24
	cmp r0, 0
	bne _0804435C
	ldr r0, _08044388
	ldr r1, [r0]
	ldr r2, _0804438C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08044356
	ldr r3, _08044390
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804435C
_08044356:
	movs r0, 0xC
	bl sub_803E46C
_0804435C:
	ldr r0, [r5, 0x70]
	adds r0, 0xF8
	movs r1, 0
	strb r1, [r0]
	bl sub_8044B28
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0804431A
	ldr r0, _08044388
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xB8
	str r5, [r0]
	adds r1, 0xBC
	str r2, [r1]
	cmp r7, 0
	beq _08044394
	movs r7, 0
	b _0804439A
	.align 2, 0
_08044388: .4byte gDungeonGlobalData
_0804438C: .4byte 0x0000066c
_08044390: .4byte 0x00000673
_08044394:
	adds r0, r5, 0
	bl TickStatusHeal
_0804439A:
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0804431A
	adds r0, r5, 0
	bl sub_8071DA4
	ldr r6, _08044434
	ldr r1, [r6]
	movs r0, 0x1
	strb r0, [r1, 0xF]
	bl sub_805D8C8
	ldr r0, [r6]
	strb r4, [r0, 0xF]
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804444C
	adds r0, r5, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804444C
	ldr r2, [r5, 0x70]
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08044400
	subs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	movs r3, 0x80
	lsls r3, 7
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
_08044400:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804444C
	bl sub_8044454
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0804444C
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xBC
	ldr r1, [r0]
	cmp r1, 0
	beq _08044438
	bl sub_805F02C
	ldr r0, [r6]
	adds r0, 0xBC
	str r4, [r0]
	movs r7, 0x1
	b _08044328
	.align 2, 0
_08044434: .4byte gDungeonGlobalData
_08044438:
	ldr r0, [r5, 0x70]
	adds r0, 0xF8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804444C
	movs r3, 0xCC
	lsls r3, 3
	adds r0, r2, r3
	strh r1, [r0]
	b _08044328
_0804444C:
	movs r0, 0x1
_0804444E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_dungeon_80442D0

	thumb_func_start sub_8044454
sub_8044454:
	push {r4-r6,lr}
	ldr r0, _080444E8
	ldr r1, [r0]
	ldrb r0, [r1, 0xE]
	cmp r0, 0
	beq _080444E2
	movs r0, 0
	strb r0, [r1, 0xE]
	movs r6, 0
_08044466:
	ldr r0, _080444E8
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _080444EC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080444DC
	ldr r5, [r4, 0x70]
	ldrh r0, [r5]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080444DC
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080444E2
	adds r0, r4, 0
	bl TickStatusHeal
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080444DC
	adds r0, r4, 0
	bl sub_8071DA4
	adds r0, r4, 0
	movs r1, 0
	bl DecideAction
	adds r0, r4, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	ldrh r0, [r5]
	ldr r2, _080444F0
	adds r1, r2, 0
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r5]
_080444DC:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08044466
_080444E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080444E8: .4byte gDungeonGlobalData
_080444EC: .4byte 0x000135cc
_080444F0: .4byte 0x00007fff
	thumb_func_end sub_8044454

	thumb_func_start sub_80444F4
sub_80444F4:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl GetLeaderEntity
	cmp r6, r0
	bne _08044566
	ldr r0, _0804456C
	ldr r1, [r0]
	ldrb r0, [r1, 0xE]
	cmp r0, 0
	beq _08044566
	movs r0, 0
	strb r0, [r1, 0xE]
	movs r5, 0
_08044510:
	ldr r0, _0804456C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08044570
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08044560
	cmp r6, r4
	beq _08044560
	ldr r0, [r4, 0x70]
	ldrh r0, [r0]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08044560
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044566
	adds r0, r4, 0
	movs r1, 0
	bl DecideAction
	adds r0, r4, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
_08044560:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08044510
_08044566:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804456C: .4byte gDungeonGlobalData
_08044570: .4byte 0x000135cc
	thumb_func_end sub_80444F4

	thumb_func_start sub_8044574
sub_8044574:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	bl GetLeaderEntity
	mov r10, r0
	movs r7, 0
	mov r0, sp
	adds r0, 0x4
	str r0, [sp, 0x40]
	ldr r1, _08044634
	mov r9, r1
_08044592:
	mov r2, r9
	ldr r0, [r2]
	lsls r1, r7, 2
	ldr r3, _08044638
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080446A4
	ldr r6, [r5, 0x70]
	mov r8, r6
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _080446A4
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080446AC
	mov r1, r9
	ldr r0, [r1]
	adds r0, 0xB8
	str r5, [r0]
	bl TriggerWeatherAbilities
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	strb r4, [r0]
	adds r0, r5, 0
	bl GetMovementSpeed
	mov r3, r9
	ldr r1, [r3]
	movs r2, 0xCC
	lsls r2, 3
	adds r1, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	lsls r1, 1
	movs r2, 0x32
	muls r0, r2
	adds r1, r0
	ldr r0, _0804463C
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080446A4
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080446A4
	ldrh r1, [r6]
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _080446A4
	movs r3, 0x80
	lsls r3, 7
	adds r0, r3, 0
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08044644
	ldr r2, _08044640
	adds r0, r2, 0
	ands r0, r1
	strh r0, [r6]
	b _080446A4
	.align 2, 0
_08044634: .4byte gDungeonGlobalData
_08044638: .4byte 0x0001357c
_0804463C: .4byte gSpeedTurns
_08044640: .4byte 0x0000bfff
_08044644:
	ldr r1, _08044668
	add r1, r8
	strb r0, [r1]
	adds r0, r5, 0
	bl TickStatusHeal
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080446A4
	adds r0, r5, 0
	bl sub_8071DA4
	movs r4, 0
	b _0804466E
	.align 2, 0
_08044668: .4byte 0x00000145
_0804466C:
	adds r4, 0x1
_0804466E:
	cmp r4, 0x2
	bgt _080446A4
	adds r0, r5, 0
	movs r1, 0
	bl DecideAction
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080446A4
	adds r0, r5, 0
	bl sub_8072CF4
	lsls r0, 24
	cmp r0, 0
	beq _080446A4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0804466C
_080446A4:
	adds r7, 0x1
	cmp r7, 0x3
	bgt _080446AC
	b _08044592
_080446AC:
	movs r0, 0
	mov r8, r0
_080446B0:
	adds r0, 0x1
	mov r9, r0
	add r2, sp, 0x8
	ldr r1, [sp, 0x40]
	mov r0, sp
	movs r7, 0x2
_080446BC:
	mov r3, r8
	str r3, [r0]
	str r2, [r1]
	adds r2, 0x8
	adds r1, 0x8
	adds r0, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _080446BC
	str r3, [sp, 0x18]
	str r3, [sp, 0x1C]
	movs r7, 0
_080446D4:
	ldr r0, _08044710
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08044714
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08044760
	ldr r1, [r4, 0x70]
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r1, r3
	ldrb r0, [r2]
	cmp r0, 0
	beq _08044760
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08044718
	adds r3, 0x1
	adds r0, r1, r3
	mov r1, r8
	strb r1, [r0]
	strb r1, [r2]
	b _08044760
	.align 2, 0
_08044710: .4byte gDungeonGlobalData
_08044714: .4byte 0x0001357c
_08044718:
	mov r2, r10
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	subs r2, r1, r0
	cmp r2, 0
	bge _0804472A
	negs r2, r2
_0804472A:
	mov r3, r10
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	subs r1, r0
	cmp r1, 0
	bge _0804473C
	negs r1, r1
_0804473C:
	cmp r1, r2
	bge _08044742
	adds r1, r2, 0
_08044742:
	cmp r1, 0x2
	ble _08044748
	movs r1, 0x2
_08044748:
	add r3, sp, 0x20
	lsls r0, r7, 3
	adds r3, r0
	str r4, [r3]
	add r2, sp, 0x24
	adds r2, r0
	lsls r1, 3
	ldr r0, [sp, 0x40]
	adds r1, r0, r1
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
_08044760:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080446D4
	mov r5, sp
	movs r6, 0
_0804476A:
	ldr r4, [r5]
	cmp r4, 0
	beq _080447A0
	ldr r1, [r4, 0x70]
	ldr r3, _08044814
	adds r2, r1, r3
	movs r0, 0x1
	strb r0, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	strb r6, [r0]
	adds r0, r4, 0
	movs r1, 0x1
	bl DecideAction
	adds r0, r4, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	adds r0, r4, 0
	bl EntityExists
_080447A0:
	ldr r5, [r5, 0x4]
	cmp r5, 0
	bne _0804476A
	mov r0, r9
	cmp r0, 0x2
	ble _080446B0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044802
	movs r7, 0
_080447B8:
	ldr r0, _08044818
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r3, _0804481C
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080447FC
	ldr r0, [r4, 0x70]
	movs r1, 0xA2
	lsls r1, 1
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0
	beq _080447FC
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080447FC
	adds r0, r4, 0
	bl sub_8071DA4
	movs r0, 0
	strb r0, [r5]
_080447FC:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080447B8
_08044802:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044814: .4byte 0x00000145
_08044818: .4byte gDungeonGlobalData
_0804481C: .4byte 0x0001357c
	thumb_func_end sub_8044574

	thumb_func_start sub_8044820
sub_8044820:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	ldr r0, _08044830
	mov r8, r0
	b _080448FC
	.align 2, 0
_08044830: .4byte gSpeedTurns
_08044834:
	ldr r4, [r5, 0x70]
	ldr r0, [r6]
	adds r0, 0xB8
	str r5, [r0]
	bl TriggerWeatherAbilities
	ldrh r2, [r4]
	movs r1, 0x80
	lsls r1, 8
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	bne _080448FA
	movs r1, 0x80
	lsls r1, 7
	adds r0, r1, 0
	ands r0, r2
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0804486C
	ldr r1, _08044868
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r4]
	b _080448FA
	.align 2, 0
_08044868: .4byte 0x0000bfff
_0804486C:
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r5, 0
	bl GetMovementSpeed
	ldr r1, [r6]
	movs r2, 0xCC
	lsls r2, 3
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	lsls r1, 1
	movs r2, 0x32
	muls r0, r2
	adds r1, r0
	add r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080448FA
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080448FA
	ldrh r1, [r4]
	ldr r2, _08044984
	adds r0, r2, 0
	ands r1, r0
	movs r0, 0
	strh r1, [r4]
	ldr r2, _08044988
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl TickStatusHeal
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080448FA
	adds r0, r5, 0
	bl sub_8071DA4
	adds r0, r5, 0
	movs r1, 0
	bl DecideAction
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044924
	adds r0, r5, 0
	bl sub_8072CF4
	bl sub_8086AC0
	movs r0, 0
	bl sub_8043ED0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08044924
_080448FA:
	adds r7, 0x1
_080448FC:
	cmp r7, 0xF
	bgt _08044924
	ldr r6, _0804498C
	ldr r0, [r6]
	lsls r1, r7, 2
	ldr r2, _08044990
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080448FA
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08044834
_08044924:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0804497A
	movs r7, 0
_08044930:
	ldr r0, _0804498C
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08044990
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08044974
	ldr r0, [r4, 0x70]
	movs r1, 0xA2
	lsls r1, 1
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0
	beq _08044974
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08044974
	adds r0, r4, 0
	bl sub_8071DA4
	movs r0, 0
	strb r0, [r5]
_08044974:
	adds r7, 0x1
	cmp r7, 0xF
	ble _08044930
_0804497A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044984: .4byte 0x00003fff
_08044988: .4byte 0x00000145
_0804498C: .4byte gDungeonGlobalData
_08044990: .4byte 0x0001358c
	thumb_func_end sub_8044820

	.align 2, 0
