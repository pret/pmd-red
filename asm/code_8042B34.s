	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8042CC0
sub_8042CC0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r7, 0
	ldr r2, _08042D20
	ldr r1, [r2]
	ldr r0, [r1, 0x4]
	cmp r0, 0
	beq _08042CDC
	movs r7, 0x1
	subs r0, 0x1
	str r0, [r1, 0x4]
_08042CDC:
	movs r5, 0
	ldr r0, [r2]
	ldr r0, [r0, 0x8]
	cmp r5, r0
	bge _08042D56
	adds r6, r2, 0
	movs r0, 0x98
	negs r0, r0
	mov r9, r0
	movs r4, 0
	ldr r1, _08042D24
	mov r8, r1
_08042CF4:
	ldr r3, [r6]
	adds r0, r3, r4
	adds r2, r0, 0
	adds r2, 0x8C
	adds r0, r3, 0
	adds r0, 0x4C
	adds r0, r4
	ldr r1, [r0]
	ldrh r0, [r2]
	subs r0, r1
	strh r0, [r2]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r9
	bgt _08042D2E
	ldr r0, [r3, 0x4]
	cmp r0, 0
	ble _08042D28
	movs r0, 0x98
	strh r0, [r2]
	b _08042D30
	.align 2, 0
_08042D20: .4byte gUnknown_203B414
_08042D24: .4byte 0x0000ff68
_08042D28:
	mov r0, r8
	strh r0, [r2]
	b _08042D30
_08042D2E:
	movs r7, 0x1
_08042D30:
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r4
	ldr r0, [r0]
	adds r1, r4, 0
	adds r1, 0x8C
	adds r2, r1
	movs r1, 0
	str r1, [sp]
	movs r3, 0
	bl sub_800E8AC
	adds r4, 0x4
	adds r5, 0x1
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	cmp r5, r0
	blt _08042CF4
_08042D56:
	ldr r0, _08042D74
	ldr r0, [r0]
	ldr r1, _08042D78
	adds r0, r1
	bl sub_800E90C
	adds r0, r7, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08042D74: .4byte gDungeon
_08042D78: .4byte 0x000181f0
	thumb_func_end sub_8042CC0

	thumb_func_start sub_8042D7C
sub_8042D7C:
	push {r4-r6,lr}
	ldr r1, _08042DD0
	ldr r0, [r1]
	cmp r0, 0
	beq _08042DCA
	movs r5, 0
	ldr r0, [r0, 0x8]
	cmp r5, r0
	bge _08042DBA
	adds r6, r1, 0
_08042D90:
	ldr r0, [r6]
	lsls r4, r5, 2
	adds r0, 0xC
	adds r0, r4
	ldr r0, [r0]
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	beq _08042DB0
	ldr r0, [r6]
	adds r0, 0xC
	adds r0, r4
	ldr r0, [r0]
	bl sub_800DC14
_08042DB0:
	adds r5, 0x1
	ldr r0, [r6]
	ldr r0, [r0, 0x8]
	cmp r5, r0
	blt _08042D90
_08042DBA:
	bl sub_800DBBC
	ldr r4, _08042DD0
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08042DCA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042DD0: .4byte gUnknown_203B414
	thumb_func_end sub_8042D7C

	thumb_func_start sub_8042DD4
sub_8042DD4:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r2, 0
	ldr r0, _08042E04
	mov r12, r0
	ldr r3, _08042E08
_08042DE4:
	mov r1, r12
	ldr r0, [r1]
	adds r4, r0, r3
	ldr r1, [r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _08042E0C
	str r5, [r4]
	str r6, [r4, 0xC]
	str r7, [r4, 0x4]
	adds r0, r5, 0
	bl sub_800E6D8
	str r0, [r4, 0x8]
	b _08042E14
	.align 2, 0
_08042E04: .4byte gDungeon
_08042E08: .4byte 0x000005c4
_08042E0C:
	adds r3, 0x10
	adds r2, 0x1
	cmp r2, 0x2
	ble _08042DE4
_08042E14:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8042DD4

	thumb_func_start sub_8042E1C
sub_8042E1C:
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, _08042E44
	ldr r4, _08042E48
_08042E24:
	ldr r0, [r6]
	adds r0, r4
	ldr r1, [r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08042E4C
	adds r0, r1, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	beq _08042E4C
	movs r0, 0x1
	b _08042E56
	.align 2, 0
_08042E44: .4byte gDungeon
_08042E48: .4byte 0x000005c4
_08042E4C:
	adds r4, 0x10
	adds r5, 0x1
	cmp r5, 0x2
	ble _08042E24
	movs r0, 0
_08042E56:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8042E1C

	thumb_func_start sub_8042E5C
sub_8042E5C:
	push {r4-r7,lr}
	ldr r7, _08042E90
	ldr r6, _08042E94
	movs r5, 0x2
_08042E64:
	ldr r0, [r7]
	adds r4, r0, r6
	ldr r0, [r4]
	cmp r0, 0
	blt _08042E82
	bl sub_800E9A8
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08042E82
	movs r0, 0x1
	negs r0, r0
	str r0, [r4]
	str r1, [r4, 0xC]
_08042E82:
	adds r6, 0x10
	subs r5, 0x1
	cmp r5, 0
	bge _08042E64
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042E90: .4byte gDungeon
_08042E94: .4byte 0x000005c4
	thumb_func_end sub_8042E5C

	thumb_func_start sub_8042E98
sub_8042E98:
	push {r4,r5,lr}
	ldr r5, _08042EC0
	movs r4, 0x1
	negs r4, r4
	movs r3, 0
	ldr r2, _08042EC4
	movs r1, 0x2
_08042EA6:
	ldr r0, [r5]
	adds r0, r2
	str r4, [r0]
	str r3, [r0, 0x4]
	str r3, [r0, 0xC]
	adds r2, 0x10
	subs r1, 0x1
	cmp r1, 0
	bge _08042EA6
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042EC0: .4byte gDungeon
_08042EC4: .4byte 0x000005c4
	thumb_func_end sub_8042E98

	thumb_func_start sub_8042EC8
sub_8042EC8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r6, r0, 0
	mov r8, r1
	movs r7, 0
_08042ED6:
	ldr r1, _08042F5C
	lsls r0, r7, 4
	ldr r2, _08042F60
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r0, [r4]
	cmp r0, 0
	blt _08042F4A
	ldr r0, [r4, 0xC]
	cmp r0, r6
	bne _08042F4A
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08042EF6
	adds r0, 0xFF
_08042EF6:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _08042F64
	ldr r2, [sp, 0x8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x8]
	ldr r1, [r6, 0x10]
	cmp r1, 0
	bge _08042F0C
	adds r1, 0xFF
_08042F0C:
	lsls r1, 8
	lsrs r1, 16
	lsls r1, 16
	ldr r0, _08042F68
	ands r2, r0
	orrs r2, r1
	str r2, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r5, [r6, 0x70]
	ldr r2, [r4, 0x8]
	subs r0, 0x1
	cmp r2, r0
	beq _08042F36
	lsls r2, 24
	lsrs r2, 24
	add r0, sp, 0x4
	adds r1, r6, 0
	adds r1, 0x28
	bl sub_800569C
_08042F36:
	ldr r0, [r4]
	adds r1, r5, 0
	adds r1, 0x46
	ldrb r1, [r1]
	str r1, [sp]
	add r1, sp, 0x8
	add r2, sp, 0x4
	mov r3, r8
	bl sub_800EB24
_08042F4A:
	adds r7, 0x1
	cmp r7, 0x2
	ble _08042ED6
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042F5C: .4byte gDungeon
_08042F60: .4byte 0x000005c4
_08042F64: .4byte 0xffff0000
_08042F68: .4byte 0x0000ffff
	thumb_func_end sub_8042EC8

	thumb_func_start xxx_dungeon_8042F6C
xxx_dungeon_8042F6C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r8, r0
	ldr r1, _0804310C
	movs r0, 0
	strb r0, [r1]
	mov r0, r8
	ldrb r6, [r0, 0x8]
	ldrb r1, [r0, 0x11]
	mov r9, r1
	ldrb r2, [r0, 0x10]
	mov r10, r2
	ldr r0, _08043110
	mov r3, r8
	ldr r1, [r3, 0x74]
	str r1, [r0]
	ldr r2, _08043114
	ldr r0, [r3, 0x78]
	str r0, [r2]
	cmp r6, 0
	bne _08042FA0
	strb r6, [r1]
_08042FA0:
	ldr r2, [r2]
	movs r1, 0
	ldr r4, _08043118
	ldr r5, _0804311C
	mov r0, sp
	adds r0, 0x4
	str r0, [sp, 0x8]
	mov r3, r8
	adds r3, 0x7C
	str r3, [sp, 0xC]
	movs r3, 0
_08042FB6:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, 0x1
	cmp r1, r4
	bls _08042FB6
	movs r7, 0
	movs r0, 0x64
	strh r0, [r5]
	cmp r6, 0
	bne _0804300C
	ldr r4, _08043114
	ldr r0, [r4]
	mov r5, r8
	ldrb r1, [r5, 0xF]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r2
	strb r1, [r0]
	ldr r2, [r4]
	ldr r3, _08043120
	adds r2, r3
	ldr r0, [r5, 0x14]
	ldr r1, [r5, 0x18]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r0, [r5, 0x4]
	bl GetTurnLimit
	ldr r1, [r4]
	ldr r5, _08043124
	adds r2, r1, r5
	strh r0, [r2]
	ldr r0, _08043128
	adds r1, r0
	strb r7, [r1]
	mov r1, r8
	ldrb r0, [r1, 0x4]
	bl GetRescuesAllowed
	ldr r1, [r4]
	ldr r2, _0804312C
	adds r1, r2
	strb r0, [r1]
_0804300C:
	ldr r4, _08043114
	ldr r0, [r4]
	movs r3, 0xD3
	lsls r3, 3
	adds r0, r3
	strb r7, [r0]
	ldr r0, [r4]
	ldr r5, _08043130
	adds r0, r5
	strb r7, [r0]
	ldr r0, [r4]
	mov r2, r8
	ldrb r1, [r2, 0x9]
	subs r3, 0x3C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r2, 0xC]
	subs r5, 0x3F
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r2, 0xA]
	movs r2, 0xCB
	lsls r2, 3
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	mov r3, r8
	ldrb r1, [r3, 0xB]
	subs r5, 0x1
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r3, 0xD]
	adds r2, 0x3
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldrb r1, [r3, 0xE]
	ldr r3, _08043134
	adds r0, r3
	strb r1, [r0]
	bl StopDungeonBGM
	bl sub_803D4AC
	bl sub_804513C
	bl sub_8043CD8
	bl sub_80495E4
	bl sub_803E250
	bl sub_8040130
	bl sub_8040124
	movs r0, 0x1
	bl sub_803F27C
	ldr r1, _08043138
	ldr r5, _0804313C
	adds r0, r5, 0
	strh r0, [r1]
	movs r0, 0x1
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0
	bl sub_800DAC0
	movs r0, 0x1
	bl UpdateFadeInTile
	bl sub_803DF60
	bl sub_803E02C
	bl sub_8042E98
	ldr r0, _08043140
	strb r7, [r0]
	cmp r6, 0
	beq _080430C8
	ldr r0, _08043110
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 7
	bl sub_8081BF4
	bl sub_8049840
_080430C8:
	mov r0, r9
	cmp r0, 0
	beq _080430D2
	bl sub_8043D60
_080430D2:
	cmp r6, 0
	beq _080430D8
	b _080431DC
_080430D8:
	ldr r0, [r4]
	ldr r1, _08043144
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08043148
	adds r0, r2
	strb r1, [r0]
	ldr r2, [r4]
	movs r3, 0xCF
	lsls r3, 3
	adds r0, r2, r3
	ldrb r3, [r0]
	cmp r3, 0x1
	bne _08043154
	mov r5, r8
	ldrb r1, [r5, 0x14]
	ldr r5, _0804314C
	adds r0, r2, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _08043150
	adds r0, r1
	strb r3, [r0]
	b _0804315E
	.align 2, 0
_0804310C: .4byte gUnknown_203B40C
_08043110: .4byte gSerializedData_203B41C
_08043114: .4byte gDungeon
_08043118: .4byte 0x0001cedb
_0804311C: .4byte gUnknown_203B410
_08043120: .4byte 0x0000064c
_08043124: .4byte 0x00000666
_08043128: .4byte 0x0000067a
_0804312C: .4byte 0x0000067b
_08043130: .4byte 0x00000699
_08043134: .4byte 0x0000065d
_08043138: .4byte gUnknown_2026E4E
_0804313C: .4byte 0x00000808
_08043140: .4byte gUnknown_202F32C
_08043144: .4byte 0x0001820b
_08043148: .4byte 0x0001820c
_0804314C: .4byte 0x00000644
_08043150: .4byte 0x00000645
_08043154:
	ldr r3, _0804318C
	adds r1, r2, r3
	mov r5, r8
	ldr r0, [r5, 0x4]
	str r0, [r1]
_0804315E:
	ldr r4, _08043190
	ldr r0, [r4]
	ldr r1, _08043194
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bl sub_8044124
	cmp r6, 0
	bne _080431DC
	ldr r1, [r4]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0804319C
	ldr r3, _08043198
	adds r1, r3
	mov r5, r8
	ldr r0, [r5, 0x18]
	str r0, [r1]
	b _080431AC
	.align 2, 0
_0804318C: .4byte 0x00000644
_08043190: .4byte gDungeon
_08043194: .4byte 0x00000674
_08043198: .4byte 0x0000067c
_0804319C:
	bl Rand32Bit
	ldr r2, [r4]
	ldr r1, _08043208
	adds r2, r1
	ldr r1, _0804320C
	ands r1, r0
	str r1, [r2]
_080431AC:
	ldr r4, _08043210
	ldr r0, [r4]
	ldr r2, _08043208
	adds r0, r2
	ldr r0, [r0]
	bl sub_808408C
	cmp r6, 0
	bne _080431DC
	bl sub_80980A4
	lsls r0, 24
	cmp r0, 0
	bne _080431D8
	ldr r0, [r4]
	ldr r3, _08043214
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080431D8
	bl sub_8043FD0
_080431D8:
	bl sub_806890C
_080431DC:
	mov r5, r9
	cmp r5, 0
	beq _08043230
	ldr r1, _08043218
	ldr r0, _08043210
	ldr r0, [r0]
	ldr r2, _0804321C
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	str r0, [r1]
	cmp r0, 0
	beq _08043224
	ldr r0, _08043220
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08043230
	.align 2, 0
_08043208: .4byte 0x0000067c
_0804320C: .4byte 0x00ffffff
_08043210: .4byte gDungeon
_08043214: .4byte 0x00000644
_08043218: .4byte gFormatData_202DE30
_0804321C: .4byte 0x0000067b
_08043220: .4byte gUnknown_80FEC48
_08043224:
	ldr r0, _080432B4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043230:
	mov r3, r10
	cmp r3, 0
	beq _0804326A
	mov r1, r8
	adds r1, 0x44
	movs r0, 0
	strb r0, [r1]
	ldr r0, _080432B8
	ldr r0, [r0]
	ldr r5, _080432BC
	adds r0, r5
	ldrb r0, [r0]
	bl IsLevelResetTo1
	lsls r0, 24
	mov r4, r8
	adds r4, 0x1C
	cmp r0, 0
	beq _0804325C
	adds r0, r4, 0
	bl sub_808D0D8
_0804325C:
	adds r0, r4, 0
	bl sub_8068A84
	cmp r6, 0
	beq _0804326A
	bl sub_806B404
_0804326A:
	bl sub_8068614
	cmp r6, 0
	bne _080432F4
	ldr r0, _080432B8
	ldr r0, [r0]
	movs r1, 0xCF
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080432F4
	mov r0, sp
	bl sub_8099394
	lsls r0, 24
	cmp r0, 0
	beq _080432F4
	mov r0, sp
	ldrb r0, [r0]
	bl GetMailatIndex
	adds r2, r0, 0
	adds r2, 0x2C
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0
	beq _080432E8
	ldr r1, _080432C0
	str r0, [r1]
	ldr r0, _080432C4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _080432F4
	.align 2, 0
_080432B4: .4byte gUnknown_80FEC7C
_080432B8: .4byte gDungeon
_080432BC: .4byte 0x00000644
_080432C0: .4byte gFormatData_202DE30
_080432C4: .4byte gUnknown_81002B8
_080432C8:
	ldr r4, _080432CC
	b _080432D2
	.align 2, 0
_080432CC: .4byte 0x00000226
_080432D0:
	ldr r4, _080432E4
_080432D2:
	bl GetLeader
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl sub_8083AB0
	bl _08043AF4
	.align 2, 0
_080432E4: .4byte 0x00000227
_080432E8:
	ldr r0, _080434B8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_080432F4:
	movs r2, 0
	mov r10, r2
	movs r3, 0
	mov r9, r3
_080432FC:
	bl sub_8098080
	bl nullsub_16
	bl sub_80521D0
	bl sub_80531A8
	bl InitDungeonPokemonSprites
	cmp r6, 0
	bne _08043318
	bl sub_804513C
_08043318:
	ldr r0, _080434BC
	movs r5, 0
	str r5, [r0]
	ldr r4, _080434C0
	ldr r0, [r4]
	strb r5, [r0]
	cmp r6, 0
	bne _08043346
	bl YetAnotherRandom24
	ldr r1, [r4]
	movs r3, 0xD0
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	movs r0, 0xCD
	lsls r0, 3
	adds r1, r0
	movs r0, 0xA
	strh r0, [r1]
	ldr r0, [r2]
	bl InitDungeonRNG
_08043346:
	ldr r0, [r4]
	ldr r1, _080434C4
	adds r0, r1
	strb r5, [r0]
	cmp r6, 0
	bne _08043390
	ldr r0, [r4]
	ldr r2, _080434C8
	adds r0, r2
	strb r6, [r0]
	movs r0, 0x4
	bl DungeonRandInt
	ldr r1, [r4]
	ldr r3, _080434CC
	adds r1, r3
	strb r6, [r1]
	ldr r1, [r4]
	ldr r2, _080434D0
	adds r1, r2
	strb r6, [r1]
	ldr r2, [r4]
	ldr r1, _080434D4
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	adds r3, 0x3
	adds r0, r2, r3
	strh r1, [r0]
	ldr r0, _080434D8
	adds r2, r0
	mov r1, r10
	strb r1, [r2]
	ldr r0, [r4]
	ldr r2, _080434DC
	adds r0, r2
	strb r1, [r0]
_08043390:
	bl sub_803D4D0
	ldr r0, [r4]
	strb r5, [r0, 0x1]
	ldr r0, [r4]
	strb r5, [r0, 0x10]
	ldr r0, [r4]
	strb r5, [r0, 0x2]
	ldr r0, [r4]
	strb r5, [r0, 0x4]
	ldr r0, [r4]
	strb r5, [r0, 0x11]
	ldr r0, [r4]
	strb r5, [r0, 0x8]
	ldr r0, [r4]
	strb r5, [r0, 0x3]
	ldr r0, [r4]
	strb r5, [r0, 0x6]
	ldr r0, [r4]
	strb r5, [r0, 0xF]
	ldr r2, [r4]
	movs r3, 0xB8
	lsls r3, 3
	adds r1, r2, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	strb r5, [r2, 0x7]
	ldr r0, [r4]
	strb r5, [r0, 0x9]
	ldr r0, [r4]
	strb r5, [r0, 0xA]
	ldr r0, [r4]
	movs r1, 0x1
	strb r1, [r0, 0xB]
	ldr r0, [r4]
	strb r1, [r0, 0xD]
	ldr r0, [r4]
	strb r5, [r0, 0xE]
	ldr r0, [r4]
	ldr r2, _080434E0
	adds r0, r2
	strb r5, [r0]
	cmp r6, 0
	bne _080434A6
	ldr r0, [r4]
	adds r3, 0xB9
	adds r0, r3
	strb r6, [r0]
	ldr r1, [r4]
	ldr r5, _080434E4
	adds r0, r1, r5
	str r6, [r0]
	movs r2, 0xD2
	lsls r2, 3
	adds r0, r1, r2
	str r6, [r0]
	adds r3, 0x1B
	adds r0, r1, r3
	str r6, [r0]
	subs r5, 0x2C
	adds r0, r1, r5
	strh r6, [r0]
	subs r2, 0x2E
	adds r0, r1, r2
	strh r6, [r0]
	subs r3, 0x26
	adds r1, r3
	mov r5, r10
	strb r5, [r1]
	ldr r0, [r4]
	ldr r1, _080434E8
	adds r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	adds r2, 0xE
	adds r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	adds r3, 0x8
	adds r0, r3
	strb r5, [r0]
	ldr r0, [r4]
	ldr r5, _080434EC
	adds r0, r5
	mov r1, r10
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, 0x2
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r4]
	subs r3, 0xC
	adds r2, r1, r3
	ldr r0, _080434F0
	strh r0, [r2]
	adds r5, 0x17
	adds r0, r1, r5
	strh r6, [r0]
	ldr r0, _080434F4
	adds r1, r0
	mov r2, r10
	strb r2, [r1]
	ldr r1, [r4]
	adds r3, 0x1A
	adds r0, r1, r3
	movs r2, 0x63
	strh r2, [r0]
	subs r5, 0x2
	adds r0, r1, r5
	strh r2, [r0]
	ldr r0, _080434F8
	adds r1, r0
	mov r2, r10
	strb r2, [r1]
	ldr r1, [r4]
	ldr r3, _080434FC
	adds r0, r1, r3
	ldrb r2, [r0]
	ldr r5, _08043500
	adds r0, r1, r5
	strh r2, [r0]
	ldr r2, _08043504
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r3, _08043508
	adds r0, r1, r3
	strh r2, [r0]
	ldr r5, _0804350C
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, _08043510
	adds r1, r2
	strh r0, [r1]
	movs r0, 0
	bl sub_807E5E4
	bl sub_80842F0
_080434A6:
	bl sub_803D8F0
	bl LoadDungeonPokemonSprites
	cmp r6, 0
	bne _08043514
	bl sub_80687AC
	b _0804351C
	.align 2, 0
_080434B8: .4byte gPtrFinalChanceMessage
_080434BC: .4byte gLeaderPointer
_080434C0: .4byte gDungeon
_080434C4: .4byte 0x000037ec
_080434C8: .4byte 0x000037fc
_080434CC: .4byte 0x000037fd
_080434D0: .4byte 0x000037fe
_080434D4: .4byte gUnknown_80F6850
_080434D8: .4byte 0x000037ff
_080434DC: .4byte 0x00000675
_080434E0: .4byte 0x0001c05e
_080434E4: .4byte 0x0000068c
_080434E8: .4byte 0x0000066f
_080434EC: .4byte 0x00000671
_080434F0: .4byte 0x000003e7
_080434F4: .4byte 0x0000068a
_080434F8: .4byte 0x0000e264
_080434FC: .4byte 0x0001c576
_08043500: .4byte 0x00003a0e
_08043504: .4byte 0x0001c577
_08043508: .4byte 0x00003a10
_0804350C: .4byte 0x0001c586
_08043510: .4byte 0x00003a14
_08043514:
	bl sub_8068768
	bl sub_8082B40
_0804351C:
	bl sub_806C42C
	bl sub_806AD3C
	cmp r6, 0
	bne _08043544
	ldr r1, _080435B4
	ldr r3, _080435B8
	ldr r0, [r3]
	ldr r5, _080435BC
	adds r0, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	bl DungeonStartNewBGM
	bl sub_80847D4
_08043544:
	bl sub_8049840
	bl sub_803E178
	ldr r0, _080435C0
	mov r3, r9
	str r3, [r0]
	bl sub_8040124
	movs r0, 0x4
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0
	bl sub_8052210
	adds r0, r6, 0
	bl sub_803F27C
	bl ShowDungeonNameBanner
	cmp r6, 0
	bne _08043594
	bl sub_804AFAC
	ldr r5, _080435B8
	ldr r0, [r5]
	ldr r1, _080435C4
	adds r0, r1
	ldrb r0, [r0]
	bl GetTurnLimit
	ldr r2, [r5]
	ldr r3, _080435C8
	adds r1, r2, r3
	strh r0, [r1]
	ldr r5, _080435CC
	adds r2, r5
	mov r0, r10
	strb r0, [r2]
_08043594:
	bl sub_804AAD4
	bl sub_8049B8C
	bl LoadDungeonTilesetAssets
	cmp r6, 0
	bne _080435D0
	bl sub_806B168
	bl sub_806C3C0
	bl sub_806B6C4
	b _080435D4
	.align 2, 0
_080435B4: .4byte gDungeonMusic
_080435B8: .4byte gDungeon
_080435BC: .4byte 0x00003a10
_080435C0: .4byte gUnknown_202EDC8
_080435C4: .4byte 0x00000644
_080435C8: .4byte 0x00000666
_080435CC: .4byte 0x0000067a
_080435D0:
	bl sub_806B678
_080435D4:
	ldr r4, _0804362C
	ldr r1, [r4]
	ldr r2, _08043630
	adds r0, r1, r2
	mov r3, r9
	str r3, [r0]
	ldr r5, _08043634
	adds r0, r1, r5
	str r3, [r0]
	adds r2, 0x4
	adds r0, r1, r2
	str r3, [r0]
	ldr r3, _08043638
	adds r0, r1, r3
	mov r5, r9
	str r5, [r0]
	adds r2, 0x4
	adds r0, r1, r2
	str r5, [r0]
	adds r3, 0x4
	adds r1, r3
	str r5, [r1]
	cmp r6, 0
	bne _08043644
	bl sub_807FA18
	bl sub_8045CB0
	ldr r1, [r4]
	ldr r5, _0804363C
	adds r2, r1, r5
	ldr r3, _08043640
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r2]
	subs r5, 0x4
	adds r1, r5
	str r6, [r1]
	bl sub_8051E3C
	bl sub_804AAAC
	b _08043648
	.align 2, 0
_0804362C: .4byte gDungeon
_08043630: .4byte 0x00017b2c
_08043634: .4byte 0x00017b38
_08043638: .4byte 0x00017b3c
_0804363C: .4byte 0x00000694
_08043640: .4byte 0x0000068c
_08043644:
	bl sub_806A338
_08043648:
	bl sub_8068F80
	bl sub_8049884
	bl sub_8049ED4
	cmp r6, 0
	bne _08043664
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl sub_806A914
	b _0804366C
_08043664:
	bl sub_806CF60
	bl sub_806A974
_0804366C:
	movs r0, 0x1
	bl sub_8041888
	cmp r6, 0
	bne _0804367E
	bl sub_80848F0
	bl sub_8097890
_0804367E:
	ldr r0, _080436A0
	movs r1, 0x1
	strb r1, [r0]
	cmp r6, 0
	beq _08043690
	bl sub_807E88C
	bl sub_806AB2C
_08043690:
	ldr r2, _080436A4
	ldr r0, [r2]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _080436A8
	bl sub_803E748
	b _080436AC
	.align 2, 0
_080436A0: .4byte gUnknown_203B40C
_080436A4: .4byte gDungeon
_080436A8:
	bl sub_803E7C8
_080436AC:
	movs r0, 0
	bl sub_8040094
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	bl sub_8040150
	bl sub_8040A84
	ldr r4, _08043730
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	mov r3, r9
	str r3, [r0]
	ldr r5, _08043734
	adds r1, r5
	strb r3, [r1]
	ldr r0, [r4]
	ldr r1, _08043738
	adds r0, r1
	mov r2, r9
	strb r2, [r0]
	ldr r1, [r4]
	movs r5, 0
	movs r0, 0x63
	strh r0, [r1, 0x12]
	movs r3, 0x1
	strb r3, [r1]
	cmp r6, 0
	bne _08043706
	bl sub_8052DD0
	ldr r1, [r4]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	beq _08043706
	strb r5, [r1, 0x9]
	bl sub_8083D68
	bl sub_8052F80
_08043706:
	ldr r0, _0804373C
	mov r5, r9
	str r5, [r0]
	ldr r4, _08043730
	ldr r0, [r4]
	strb r5, [r0, 0x5]
	cmp r6, 0
	bne _08043778
	bl DisplayPreFightDialogue
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08043728
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08043740
_08043728:
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _0804374C
	.align 2, 0
_08043730: .4byte gDungeon
_08043734: .4byte 0x0000066c
_08043738: .4byte 0x0000066d
_0804373C: .4byte gLeaderPointer
_08043740:
	bl GetLeader
	bl sub_803F4A0
	bl sub_8040A84
_0804374C:
	cmp r6, 0
	bne _08043778
	ldr r1, _08043774
	ldr r0, [r1]
	ldrb r0, [r0, 0x5]
	cmp r0, 0
	bne _0804377C
	bl sub_807E5AC
	movs r0, 0
	bl GetApparentWeather
	lsls r0, 24
	cmp r0, 0
	beq _0804377C
	movs r0, 0x1
	bl sub_807E7FC
	b _0804377C
	.align 2, 0
_08043774: .4byte gDungeon
_08043778:
	bl TriggerWeatherAbilities
_0804377C:
	cmp r6, 0
	beq _08043784
	movs r6, 0
	b _080437A2
_08043784:
	bl sub_80427AC
	bl GetLeader
	ldr r2, _08043960
	ldr r1, [r2]
	ldr r3, _08043964
	adds r1, r3
	ldrb r1, [r1]
	bl sub_8075900
	movs r0, 0x1
	movs r1, 0
	bl sub_807EAA0
_080437A2:
	bl nullsub_16
	ldr r2, _08043960
	ldr r0, [r2]
	ldrb r1, [r0, 0x5]
	cmp r1, 0
	bne _080437DA
	movs r4, 0x1
	ldr r5, _08043968
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _0804396C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r5, _08043970
	adds r0, r5
	strb r4, [r0]
_080437C8:
	adds r0, r4, 0
	bl RunFractionalTurn
	movs r4, 0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080437C8
_080437DA:
	bl GetLeader
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080437F0
	adds r0, r4, 0
	bl sub_8071DA4
_080437F0:
	ldr r5, _08043960
	ldr r0, [r5]
	ldr r4, _08043968
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08043822
	movs r0, 0x1
	bl sub_8043ED0
	lsls r0, 24
	cmp r0, 0
	beq _08043812
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
_08043812:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08043822
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _08043830
_08043822:
	ldr r2, _08043960
	ldr r0, [r2]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _08043830
	bl sub_806AA70
_08043830:
	bl GetLeader
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0804384A
	movs r0, 0x4F
	bl sub_80526D0
	movs r0, 0x4F
	bl sub_8052740
_0804384A:
	bl sub_8040124
	movs r0, 0x1
	movs r1, 0
	bl sub_803EAF0
	ldr r3, _08043960
	ldr r0, [r3]
	ldr r5, _08043970
	adds r0, r5
	mov r1, r9
	strb r1, [r0]
	ldr r0, [r3]
	ldr r2, _0804396C
	adds r0, r2
	movs r3, 0x1
	strb r3, [r0]
	ldr r5, _08043960
	ldr r1, [r5]
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	bne _08043896
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08043896
	ldr r2, _08043974
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0x72
	bne _08043896
	ldr r3, _08043978
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0x1B
	bne _08043896
	movs r0, 0x3C
	bl DungeonFadeOutBGM
_08043896:
	movs r0, 0x4
	movs r1, 0x4F
	bl sub_803E708
	ldr r5, _08043960
	ldr r0, [r5]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _080438AC
	bl sub_803E830
_080438AC:
	movs r0, 0
	bl SetBGOBJEnableFlags
	ldr r1, _0804397C
	ldr r0, [sp, 0x4]
	ands r0, r1
	movs r1, 0x60
	orrs r0, r1
	ldr r1, _08043980
	ands r0, r1
	movs r1, 0x80
	lsls r1, 8
	orrs r0, r1
	ldr r1, _08043984
	ands r0, r1
	movs r1, 0xF8
	lsls r1, 16
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r0, _08043988
	ldr r2, [r0]
	movs r0, 0xFD
	ldr r1, [sp, 0x8]
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	movs r0, 0x1
	bl sub_8040094
	ldr r0, [r5]
	ldr r1, _0804396C
	adds r0, r1
	movs r7, 0
	movs r2, 0x1
	strb r2, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08043926
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08043926
	bl GetLeader
	adds r4, r0, 0
	ldr r0, _0804398C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	ldr r0, [r5]
	strb r7, [r0, 0x6]
	ldr r0, _08043990
	adds r1, r4, 0
	adds r2, r4, 0
	bl sub_8083AB0
_08043926:
	bl CloseAllSpriteFiles
	bl sub_8049820
	ldr r0, _08043994
	ldr r0, [r0]
	bl CloseFile
	bl FreeDungeonPokemonSprites
	ldr r0, _08043998
	mov r3, r10
	strb r3, [r0]
	ldr r4, _08043960
	ldr r1, [r4]
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0804394C
	b _08043BFC
_0804394C:
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _080439A0
	ldr r0, _0804399C
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 7
	bl sub_8080B30
	b _080439A6
	.align 2, 0
_08043960: .4byte gDungeon
_08043964: .4byte 0x00003a08
_08043968: .4byte 0x00000654
_0804396C: .4byte 0x00018218
_08043970: .4byte 0x00018219
_08043974: .4byte 0x0001ceda
_08043978: .4byte 0x00000644
_0804397C: .4byte 0xffffff00
_08043980: .4byte 0xffff00ff
_08043984: .4byte 0xff00ffff
_08043988: .4byte gUnknown_202EDC8
_0804398C: .4byte gPtrClientFaintedMessage
_08043990: .4byte 0x00000222
_08043994: .4byte gDungeonNameBannerPalette
_08043998: .4byte gUnknown_203B40C
_0804399C: .4byte gSerializedData_203B41C
_080439A0:
	movs r0, 0x2
	bl sub_8046F84
_080439A6:
	bl sub_806C1D8
	ldr r4, _080439CC
	ldr r1, [r4]
	ldr r5, _080439D0
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080439D4
	adds r5, 0x1A
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080439C4
	b _08043AF4
_080439C4:
	bl sub_804700C
	b _08043AF4
	.align 2, 0
_080439CC: .4byte gDungeon
_080439D0: .4byte 0x00000654
_080439D4:
	ldrb r0, [r1, 0x11]
	cmp r0, 0x1
	bne _080439DC
	b _080432C8
_080439DC:
	cmp r0, 0x2
	bne _08043A00
	bl GetLeader
	adds r2, r0, 0
	ldr r0, _080439F8
	movs r1, 0
	bl sub_8083AB0
	ldr r0, [r4]
	ldr r1, _080439FC
	adds r0, r1
	b _08043A62
	.align 2, 0
_080439F8: .4byte 0x00000229
_080439FC: .4byte 0x0000066e
_08043A00:
	cmp r0, 0x3
	bne _08043A24
	bl GetLeader
	adds r2, r0, 0
	ldr r0, _08043A1C
	movs r1, 0
	bl sub_8083AB0
	ldr r0, [r4]
	ldr r2, _08043A20
	adds r0, r2
	b _08043A62
	.align 2, 0
_08043A1C: .4byte 0x0000022a
_08043A20: .4byte 0x0000066e
_08043A24:
	cmp r0, 0x4
	bne _08043A2A
	b _080432D0
_08043A2A:
	movs r3, 0xCF
	lsls r3, 3
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043A74
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08043A74
	ldr r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08043A74
	bl GetLeader
	adds r2, r0, 0
	movs r0, 0x8A
	lsls r0, 2
	movs r1, 0
	bl sub_8083AB0
	ldr r0, [r4]
	ldr r5, _08043A70
	adds r0, r5
_08043A62:
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043AF4
	bl sub_8097810
	b _08043AF4
	.align 2, 0
_08043A70: .4byte 0x0000066e
_08043A74:
	ldr r4, _08043ACC
	ldr r0, [r4]
	ldr r1, _08043AD0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043A86
	bl sub_8097810
_08043A86:
	ldr r1, [r4]
	ldr r3, _08043AD4
	adds r2, r1, r3
	ldrb r0, [r2]
	adds r0, 0x1
	ldr r5, _08043AD8
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	bge _08043AE4
	strb r0, [r2]
	ldr r0, [r4]
	ldr r1, _08043ADC
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, _08043AE0
	cmp r1, r0
	beq _08043AAC
	b _080432FC
_08043AAC:
	movs r0, 0x1F
	bl sub_8098100
	lsls r0, 24
	cmp r0, 0
	beq _08043ABA
	b _080432FC
_08043ABA:
	movs r0, 0x1F
	bl sub_8097FA8
	bl sub_8086130
	bl sub_8097FF8
	b _080432FC
	.align 2, 0
_08043ACC: .4byte gDungeon
_08043AD0: .4byte 0x0000066e
_08043AD4: .4byte 0x00000645
_08043AD8: .4byte 0x0001cec8
_08043ADC: .4byte 0x00000644
_08043AE0: .4byte 0x0000060b
_08043AE4:
	ldr r4, _08043B80
	bl GetLeader
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl sub_8083AB0
_08043AF4:
	ldr r1, _08043B84
	movs r0, 0
	strb r0, [r1]
	mov r4, r8
	adds r4, 0x7E
	movs r0, 0
	strb r0, [r4]
	bl sub_8097FF8
	movs r0, 0x1
	movs r1, 0x14
	bl sub_80095CC
	bl sub_803E13C
	movs r0, 0x4
	bl sub_800CDA8
	ldr r0, _08043B88
	ldr r1, [r0]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08043B38
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	bl sub_8083C88
	lsls r0, 24
	cmp r0, 0
	beq _08043B38
	bl sub_80841EC
_08043B38:
	bl sub_8083C24
	lsls r0, 24
	cmp r0, 0
	beq _08043BA4
	ldr r5, _08043B88
	ldr r0, [r5]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _08043B98
	ldr r0, _08043B8C
	ldr r3, [sp, 0xC]
	strh r0, [r3]
	mov r4, r8
	adds r4, 0x84
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	mov r3, r8
	adds r3, 0x80
	ldr r1, [r5]
	ldr r5, _08043B90
	adds r2, r1, r5
	ldr r0, [r2]
	str r0, [r3]
	ldr r0, [r2]
	str r0, [r4]
	mov r2, r8
	adds r2, 0x88
	ldr r0, _08043B94
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _08043C32
	.align 2, 0
_08043B80: .4byte 0x00000227
_08043B84: .4byte gUnknown_203B40C
_08043B88: .4byte gDungeon
_08043B8C: .4byte 0x0000fffe
_08043B90: .4byte 0x00000644
_08043B94: .4byte 0x0000067c
_08043B98:
	ldr r0, _08043BA0
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	b _08043C32
	.align 2, 0
_08043BA0: .4byte 0x0000ffff
_08043BA4:
	bl sub_8083C50
	lsls r0, 24
	cmp r0, 0
	beq _08043C28
	ldr r0, _08043BC8
	ldr r0, [r0]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043BCC
	movs r0, 0x4
	ldr r3, [sp, 0xC]
	strh r0, [r3]
	b _08043BE6
	.align 2, 0
_08043BC8: .4byte gDungeon
_08043BCC:
	cmp r0, 0
	bne _08043BDC
	movs r0, 0x1
	ldr r5, [sp, 0xC]
	strh r0, [r5]
	bl sub_8084424
	b _08043BE6
_08043BDC:
	movs r0, 0x1
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	bl sub_8084424
_08043BE6:
	ldr r0, _08043BF4
	ldr r0, [r0]
	ldr r2, _08043BF8
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r4]
	b _08043C32
	.align 2, 0
_08043BF4: .4byte gDungeon
_08043BF8: .4byte 0x00000674
_08043BFC:
	ldr r0, _08043C20
	ldr r0, [r0]
	movs r1, 0x90
	lsls r1, 7
	bl sub_8080B30
	movs r0, 0x3
	ldr r3, [sp, 0xC]
	strh r0, [r3]
	mov r1, r8
	adds r1, 0x80
	ldr r0, [r4]
	ldr r5, _08043C24
	adds r0, r5
	ldr r0, [r0]
	str r0, [r1]
	b _08043C32
	.align 2, 0
_08043C20: .4byte gSerializedData_203B41C
_08043C24: .4byte 0x00000644
_08043C28:
	movs r0, 0x2
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	bl sub_8084424
_08043C32:
	bl sub_806863C
	bl sub_803E214
	bl nullsub_56
	bl sub_8040218
	ldr r2, [sp, 0xC]
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0x1
	beq _08043C54
	cmp r0, 0x4
	beq _08043C54
	cmp r0, 0x2
	bne _08043C58
_08043C54:
	bl sub_8047104
_08043C58:
	ldr r5, [sp, 0xC]
	movs r0, 0
	ldrsh r1, [r5, r0]
	cmp r1, 0x1
	beq _08043C8A
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _08043C78
	cmp r1, 0x4
	beq _08043C78
	adds r0, 0x1
	cmp r1, r0
	beq _08043C78
	cmp r1, 0x2
	bne _08043CAC
_08043C78:
	ldr r2, [sp, 0xC]
	movs r3, 0
	ldrsh r1, [r2, r3]
	cmp r1, 0x1
	beq _08043C8A
	cmp r1, 0x4
	beq _08043C8A
	cmp r1, 0x2
	bne _08043C92
_08043C8A:
	movs r0, 0x1
	bl sub_8068BDC
	b _08043CAC
_08043C92:
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	bne _08043CA2
	movs r0, 0
	bl sub_8068BDC
	b _08043CAC
_08043CA2:
	bl sub_8068F28
	movs r0, 0
	bl sub_8068BDC
_08043CAC:
	bl sub_800DB7C
	ldr r0, _08043CD0
	movs r1, 0
	str r1, [r0]
	ldr r0, _08043CD4
	str r1, [r0]
	bl nullsub_16
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043CD0: .4byte gDungeon
_08043CD4: .4byte gSerializedData_203B41C
	thumb_func_end xxx_dungeon_8042F6C

	thumb_func_start sub_8043CD8
sub_8043CD8:
	push {lr}
	bl vram_related_8009804
	pop {r0}
	bx r0
	thumb_func_end sub_8043CD8

	thumb_func_start sub_8043CE4
sub_8043CE4:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08043CF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043CF8
	movs r0, 0x1
	b _08043D08
	.align 2, 0
_08043CF4: .4byte gUnknown_202F1A8
_08043CF8:
	movs r2, 0
	ldr r0, _08043D0C
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08043D06
	movs r2, 0x1
_08043D06:
	adds r0, r2, 0
_08043D08:
	pop {r1}
	bx r1
	.align 2, 0
_08043D0C: .4byte gDungeonWaterType
	thumb_func_end sub_8043CE4

	thumb_func_start sub_8043D10
sub_8043D10:
	push {lr}
	ldr r0, _08043D38
	ldr r1, [r0]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043D3C
	subs r2, 0x2B
	adds r0, r1, r2
	subs r2, 0x8
	adds r1, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08043D3C
	movs r0, 0x2
	b _08043D4C
	.align 2, 0
_08043D38: .4byte gDungeon
_08043D3C:
	bl IsBossFight
	lsls r0, 24
	cmp r0, 0
	bne _08043D4A
	movs r0, 0
	b _08043D4C
_08043D4A:
	movs r0, 0x1
_08043D4C:
	pop {r1}
	bx r1
	thumb_func_end sub_8043D10

	thumb_func_start sub_8043D50
sub_8043D50:
	ldr r2, _08043D5C
	str r2, [r1]
	movs r1, 0x90
	lsls r1, 7
	str r1, [r0]
	bx lr
	.align 2, 0
_08043D5C: .4byte 0x0001cedc
	thumb_func_end sub_8043D50

	thumb_func_start sub_8043D60
sub_8043D60:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
_08043D6A:
	ldr r0, _08043DA4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08043DA8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043DCE
	ldr r2, [r4, 0x70]
	movs r1, 0x1
	ldrb r0, [r2, 0x8]
	eors r0, r1
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08043DA0
	cmp r0, 0x47
	bne _08043DAC
_08043DA0:
	movs r0, 0x1
	b _08043DAE
	.align 2, 0
_08043DA4: .4byte gDungeon
_08043DA8: .4byte 0x0001358c
_08043DAC:
	movs r0, 0
_08043DAE:
	cmp r0, 0
	beq _08043DB4
	movs r1, 0
_08043DB4:
	adds r0, r2, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08043DC0
	movs r1, 0
_08043DC0:
	cmp r1, 0
	beq _08043DCE
	adds r0, r4, 0
	ldr r1, _08043EC0
	adds r2, r4, 0
	bl sub_8068FE0
_08043DCE:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08043D6A
	movs r5, 0
	ldr r0, _08043EC4
	mov r9, r0
	mov r8, r5
_08043DDC:
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r5, 2
	ldr r2, _08043EC8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r7, r5, 0x1
	cmp r0, 0
	beq _08043E62
	adds r0, r4, 0
	adds r0, 0x22
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	ldr r4, [r4, 0x70]
	ldrh r0, [r4, 0x10]
	strh r0, [r4, 0xE]
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r4, r2
	adds r2, 0x4
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r9
	ldr r0, [r1]
	ldr r2, _08043ECC
	adds r0, r2
	mov r1, r8
	strb r1, [r0]
	adds r0, r4, 0
	movs r1, 0
	bl sub_806BFC0
	ldrh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r0, r4, 0
	adds r0, 0xFD
	mov r2, r8
	strb r2, [r0]
	movs r0, 0x8C
	lsls r0, 1
	adds r5, r4, r0
	adds r4, r5, 0
	movs r6, 0x3
_08043E46:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08043E58
	adds r0, r5, 0
	bl GetMoveBasePP
	strb r0, [r4, 0x4]
_08043E58:
	adds r4, 0x8
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _08043E46
_08043E62:
	adds r5, r7, 0
	cmp r5, 0x3
	ble _08043DDC
	movs r6, 0
_08043E6A:
	movs r5, 0
	adds r7, r6, 0x1
_08043E6E:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	ldr r4, [r0, 0x14]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043EA0
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _08043EA0
	adds r0, r4, 0
	bl GetTrapData
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x1B
	bne _08043EA0
	movs r0, 0x5
	strb r0, [r1]
_08043EA0:
	adds r5, 0x1
	cmp r5, 0x37
	ble _08043E6E
	adds r6, r7, 0
	cmp r6, 0x1F
	ble _08043E6A
	movs r0, 0x2
	bl sub_8046F84
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043EC0: .4byte 0x00000207
_08043EC4: .4byte gDungeon
_08043EC8: .4byte 0x0001357c
_08043ECC: .4byte 0x00000676
	thumb_func_end sub_8043D60

	thumb_func_start sub_8043ED0
sub_8043ED0:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0
	cmp r5, 0
	bne _08043EEA
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08043EEA
	movs r0, 0
	b _08043FB8
_08043EEA:
	ldr r6, _08043F2C
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x1
	bne _08043F40
	bl GetLeader
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043F20
	ldr r0, _08043F30
	ldr r1, [r6]
	ldr r2, _08043F34
	adds r1, r2
	bl strcpy
	ldr r0, _08043F38
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043F20:
	adds r0, r4, 0
	bl sub_8042B0C
	ldr r1, _08043F3C
	b _08043FAC
	.align 2, 0
_08043F2C: .4byte gDungeon
_08043F30: .4byte gAvailablePokemonNames
_08043F34: .4byte 0x000005f4
_08043F38: .4byte gUnknown_80F89B4
_08043F3C: .4byte 0x0000021f
_08043F40:
	cmp r0, 0x2
	bne _08043F74
	bl GetLeader
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043FA4
	ldr r0, _08043F68
	ldr r1, [r6]
	ldr r2, _08043F6C
	adds r1, r2
	bl strcpy
	ldr r0, _08043F70
	b _08043F9A
	.align 2, 0
_08043F68: .4byte gAvailablePokemonNames
_08043F6C: .4byte 0x000005f4
_08043F70: .4byte gUnknown_80F89D4
_08043F74:
	cmp r0, 0x3
	bne _08043FB6
	bl GetLeader
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08043FB6
	cmp r5, 0
	bne _08043FA4
	ldr r0, _08043FC0
	ldr r1, [r6]
	ldr r2, _08043FC4
	adds r1, r2
	bl strcpy
	ldr r0, _08043FC8
_08043F9A:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08043FA4:
	adds r0, r4, 0
	bl sub_8042B0C
	ldr r1, _08043FCC
_08043FAC:
	adds r0, r4, 0
	adds r2, r4, 0
	bl sub_8068FE0
	movs r7, 0x1
_08043FB6:
	adds r0, r7, 0
_08043FB8:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08043FC0: .4byte gAvailablePokemonNames
_08043FC4: .4byte 0x000005f4
_08043FC8: .4byte gUnknown_80F89D8
_08043FCC: .4byte 0x00000222
	thumb_func_end sub_8043ED0

	thumb_func_start sub_8043FD0
sub_8043FD0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	movs r0, 0x2
	mov r9, r0
	movs r1, 0x1
	mov r10, r1
	movs r0, 0xFF
	mov r8, r0
_08043FE8:
	movs r3, 0
	mov r1, r9
	adds r1, 0x1
	str r1, [sp, 0x3C]
_08043FF0:
	ldr r2, _080440E4
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r10
	ands r0, r1
	adds r3, 0x1
	str r3, [sp, 0x40]
	cmp r0, 0
	beq _080440FE
	lsrs r0, r1, 1
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _080440FE
	add r5, sp, 0x20
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	mov r2, r9
	bl GetPokemonLevelData
	mov r1, r9
	strb r1, [r4, 0x3]
	ldr r0, [sp, 0x20]
	str r0, [r4, 0x1C]
	ldrh r0, [r5, 0x4]
	ldrh r1, [r4, 0x16]
	adds r0, r1
	movs r2, 0
	strh r0, [r4, 0x16]
	lsls r0, 16
	ldr r1, _080440E8
	cmp r0, r1
	ble _08044040
	ldr r0, _080440EC
	strh r0, [r4, 0x16]
_08044040:
	ldrb r0, [r4, 0x18]
	str r0, [sp, 0x2C]
	ldrb r0, [r4, 0x19]
	str r0, [sp, 0x30]
	ldrb r0, [r4, 0x1A]
	str r0, [sp, 0x34]
	ldrb r0, [r4, 0x1B]
	str r0, [sp, 0x38]
	ldrb r1, [r5, 0x6]
	ldr r0, [sp, 0x2C]
	adds r0, r1
	str r0, [sp, 0x2C]
	ldrb r1, [r5, 0x7]
	ldr r0, [sp, 0x30]
	adds r0, r1
	str r0, [sp, 0x30]
	ldrb r1, [r5, 0x8]
	ldr r0, [sp, 0x34]
	adds r0, r1
	str r0, [sp, 0x34]
	ldrb r1, [r5, 0x9]
	ldr r0, [sp, 0x38]
	adds r0, r1
	str r0, [sp, 0x38]
	ldr r0, [sp, 0x2C]
	cmp r0, 0xFE
	ble _0804407A
	mov r0, r8
	str r0, [sp, 0x2C]
_0804407A:
	ldr r0, [sp, 0x30]
	cmp r0, 0xFE
	ble _08044084
	mov r1, r8
	str r1, [sp, 0x30]
_08044084:
	ldr r0, [sp, 0x34]
	cmp r0, 0xFE
	ble _0804408E
	mov r0, r8
	str r0, [sp, 0x34]
_0804408E:
	ldr r0, [sp, 0x38]
	cmp r0, 0xFE
	ble _08044098
	mov r1, r8
	str r1, [sp, 0x38]
_08044098:
	ldr r0, [sp, 0x2C]
	strb r0, [r4, 0x18]
	ldr r0, [sp, 0x30]
	strb r0, [r4, 0x19]
	ldr r0, [sp, 0x34]
	strb r0, [r4, 0x1A]
	ldr r0, [sp, 0x38]
	strb r0, [r4, 0x1B]
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	ldrb r2, [r4, 0x3]
	mov r0, sp
	ldr r3, _080440EC
	bl sub_808E0AC
	adds r6, r0, 0
	cmp r6, 0
	beq _080440FE
	movs r0, 0
	cmp r0, r6
	bge _080440FE
_080440C2:
	movs r3, 0
	adds r7, r0, 0x1
	lsls r0, 1
	mov r1, sp
	adds r5, r1, r0
	adds r2, r4, 0
	adds r2, 0x2C
_080440D0:
	ldrb r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	bne _080440F0
	ldrh r1, [r5]
	adds r0, r2, 0
	bl InitZeroedPPPokemonMove
	b _080440F8
	.align 2, 0
_080440E4: .4byte gRecruitedPokemonRef
_080440E8: .4byte 0x03e60000
_080440EC: .4byte 0x000003e7
_080440F0:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _080440D0
_080440F8:
	adds r0, r7, 0
	cmp r0, r6
	blt _080440C2
_080440FE:
	ldr r3, [sp, 0x40]
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	bgt _0804410A
	b _08043FF0
_0804410A:
	ldr r0, [sp, 0x3C]
	mov r9, r0
	cmp r0, 0x5
	bgt _08044114
	b _08043FE8
_08044114:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8043FD0

	thumb_func_start sub_8044124
sub_8044124:
	push {r4,r5,lr}
	ldr r0, _080441AC
	ldr r0, [r0]
	ldr r1, _080441B0
	adds r0, r1
	ldrb r0, [r0]
	bl GetMaxItemsAllowed
	cmp r0, 0
	bne _08044182
	movs r3, 0
	ldr r4, _080441B4
	movs r2, 0
_0804413E:
	lsls r1, r3, 2
	ldr r0, [r4]
	adds r1, r0
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x1]
	strb r2, [r1]
	adds r3, 0x1
	cmp r3, 0x13
	ble _0804413E
	movs r3, 0
	ldr r5, _080441B8
	movs r4, 0x1
_08044156:
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08044178
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	beq _08044178
	adds r1, 0x28
	movs r0, 0
	strb r0, [r1]
_08044178:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _08044156
_08044182:
	ldr r0, _080441AC
	ldr r0, [r0]
	ldr r2, _080441B0
	adds r0, r2
	ldrb r0, [r0]
	bl IsKeepMoney
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080441A4
	ldr r0, _080441B4
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	str r1, [r0]
_080441A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080441AC: .4byte gDungeon
_080441B0: .4byte 0x00000644
_080441B4: .4byte gTeamInventoryRef
_080441B8: .4byte gRecruitedPokemonRef
	thumb_func_end sub_8044124

	.align 2, 0
