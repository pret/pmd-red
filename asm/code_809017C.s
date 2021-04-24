	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_809017C
sub_809017C:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r1, r0, 0
	mov r0, sp
	bl sub_80901D8
	movs r5, 0
	ldr r2, _080901AC
	ldrb r0, [r2]
	cmp r0, 0x3F
	beq _080901C6
	mov r3, sp
	ldrb r6, [r3]
	movs r4, 0
	adds r1, r2, 0
_0809019A:
	ldrb r0, [r1]
	cmp r6, r0
	bne _080901B0
	ldrb r0, [r3, 0x1]
	ldrb r2, [r1, 0x1]
	cmp r0, r2
	bne _080901B0
	movs r0, 0x1
	b _080901C8
	.align 2, 0
_080901AC: .4byte gUnknown_8107828
_080901B0:
	adds r4, 0x4
	adds r1, 0x4
	adds r5, 0x1
	ldr r0, _080901D0
	cmp r5, r0
	bgt _080901C6
	ldr r2, _080901D4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0x3F
	bne _0809019A
_080901C6:
	movs r0, 0
_080901C8:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080901D0: .4byte 0x000003e6
_080901D4: .4byte gUnknown_8107828
	thumb_func_end sub_809017C

	thumb_func_start sub_80901D8
sub_80901D8:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldrb r0, [r2]
	subs r0, 0x4B
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x16
	bhi _080901FE
	movs r0, 0x34
	strb r0, [r3]
	ldrb r1, [r2]
	subs r1, 0x4B
	lsls r0, r1, 1
	adds r0, r1
	ldrb r2, [r2, 0x1]
	adds r0, r2
	strb r0, [r3, 0x1]
	b _08090202
_080901FE:
	ldr r0, [r2]
	str r0, [r3]
_08090202:
	pop {r0}
	bx r0
	thumb_func_end sub_80901D8

	thumb_func_start sub_8090208
sub_8090208:
	push {lr}
	ldr r3, _08090220
	ldr r2, _08090224
	ldrb r1, [r1]
	lsls r1, 3
	adds r1, r2
	ldr r2, [r1]
	adds r1, r3, 0
	bl sub_800D158
	pop {r0}
	bx r0
	.align 2, 0
_08090220: .4byte gUnknown_8108F10
_08090224: .4byte gDungeonNames
	thumb_func_end sub_8090208

	thumb_func_start sub_8090228
sub_8090228:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r0, _08090250
	ldrb r3, [r4]
	lsls r1, r3, 4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0809025C
	ldr r1, _08090254
	ldr r2, _08090258
	lsls r0, r3, 3
	adds r0, r2
	ldr r2, [r0]
	ldrb r3, [r4, 0x1]
	adds r0, r5, 0
	bl sub_800D158
	b _0809026E
	.align 2, 0
_08090250: .4byte gDungeons
_08090254: .4byte gUnknown_8108F18
_08090258: .4byte gDungeonNames
_0809025C:
	ldr r1, _08090274
	ldr r2, _08090278
	lsls r0, r3, 3
	adds r0, r2
	ldr r2, [r0]
	ldrb r3, [r4, 0x1]
	adds r0, r5, 0
	bl sub_800D158
_0809026E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08090274: .4byte gUnknown_8108F2C
_08090278: .4byte gDungeonNames
	thumb_func_end sub_8090228

	thumb_func_start sub_809027C
sub_809027C:
	push {lr}
	ldr r2, _08090294
	ldrb r1, [r1]
	lsls r1, 3
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0x50
	bl strncpy
	pop {r0}
	bx r0
	.align 2, 0
_08090294: .4byte gDungeonNames
	thumb_func_end sub_809027C

	thumb_func_start sub_8090298
sub_8090298:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r0, 0x4B
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x16
	bhi _080902AE
	movs r0, 0x4
	b _080902C2
_080902AE:
	cmp r1, 0x3E
	bhi _080902C0
	ldr r0, _080902BC
	adds r0, r1, r0
	ldrb r0, [r0]
	b _080902C2
	.align 2, 0
_080902BC: .4byte gUnknown_81077A8
_080902C0:
	movs r0, 0x1
_080902C2:
	pop {r1}
	bx r1
	thumb_func_end sub_8090298

	thumb_func_start sub_80902C8
sub_80902C8:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	subs r0, 0x4B
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x16
	bls _080902EC
	cmp r1, 0x3E
	bhi _080902EC
	ldr r0, _080902E8
	adds r0, r1, r0
	ldrb r0, [r0]
	b _080902EE
	.align 2, 0
_080902E8: .4byte gUnknown_81077E8
_080902EC:
	movs r0, 0
_080902EE:
	pop {r1}
	bx r1
	thumb_func_end sub_80902C8

	thumb_func_start sub_80902F4
sub_80902F4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x7
	bl sub_809488C
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80902F4

	thumb_func_start sub_8090314
sub_8090314:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strb r0, [r4]
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	movs r2, 0x7
	bl sub_8094924
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8090314

	thumb_func_start sub_809033C
sub_809033C:
	lsls r0, 24
	ldr r1, _08090348
	lsrs r0, 20
	adds r0, r1
	ldrb r0, [r0, 0x1]
	bx lr
	.align 2, 0
_08090348: .4byte gDungeons
	thumb_func_end sub_809033C

	thumb_func_start sub_809034C
sub_809034C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xF8
	adds r7, r2, 0
	ldr r2, [sp, 0x118]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 16
	asrs r1, 16
	str r1, [sp, 0xE0]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0xE4]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0xE8]
	bl sub_8090A34
	str r0, [sp, 0xEC]
	movs r5, 0
	movs r0, 0
	str r0, [sp, 0xF4]
	mov r8, r0
	add r4, sp, 0xC8
	movs r0, 0xA
	strb r0, [r4]
	add r1, sp, 0xF4
	ldrb r1, [r1]
	strb r1, [r4, 0x1]
	ldr r1, _0809040C
	adds r0, r7, 0
	bl strcpy
	movs r2, 0
	str r2, [sp, 0xF0]
	movs r3, 0
	ldr r0, _08090410
	ldr r6, [r0]
	movs r4, 0x1
_080903A2:
	movs r0, 0x58
	muls r0, r3
	adds r2, r6, r0
	ldrh r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _080903D0
	lsrs r0, r1, 1
	ands r0, r4
	cmp r0, 0
	beq _080903D0
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	beq _080903CA
	ldr r0, [sp, 0xF0]
	adds r0, 0x1
	str r0, [sp, 0xF0]
_080903CA:
	adds r5, 0x1
	cmp r5, 0x4
	beq _080903DA
_080903D0:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _080903A2
_080903DA:
	ldr r0, _08090414
	mov r2, r9
	lsls r1, r2, 4
	adds r0, r1, r0
	ldrb r0, [r0, 0x5]
	mov r9, r1
	ldr r1, [sp, 0xE4]
	cmp r1, 0
	bne _080903F2
	cmp r0, 0x3
	ble _080903F2
	movs r0, 0x3
_080903F2:
	cmp r5, r0
	ble _0809043C
	cmp r0, 0x1
	bne _0809041C
	ldr r0, _08090418
	ldr r0, [r0]
	mov r1, sp
	add r2, sp, 0xC8
	movs r3, 0
	bl xxx_format_string
	b _08090430
	.align 2, 0
_0809040C: .4byte gUnknown_8108F40
_08090410: .4byte gUnknown_203B45C
_08090414: .4byte gDungeons
_08090418: .4byte gUnknown_8115A2C
_0809041C:
	ldr r1, _08090464
	subs r0, r5, r0
	str r0, [r1]
	ldr r0, _08090468
	ldr r0, [r0]
	mov r1, sp
	add r2, sp, 0xC8
	movs r3, 0
	bl xxx_format_string
_08090430:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8090888
	movs r2, 0x1
	mov r8, r2
_0809043C:
	ldr r0, _0809046C
	mov r2, r9
	adds r1, r2, r0
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0809048E
	ldr r1, [sp, 0xEC]
	cmp r0, r1
	bge _0809048E
	ldr r1, _08090464
	str r0, [r1]
	ldr r2, [sp, 0xEC]
	subs r0, r2, r0
	str r0, [r1, 0x4]
	mov r0, r8
	cmp r0, 0
	bne _08090474
	ldr r0, _08090470
	b _08090476
	.align 2, 0
_08090464: .4byte gUnknown_202DE30
_08090468: .4byte gUnknown_81159DC
_0809046C: .4byte gDungeons
_08090470: .4byte gUnknown_8115A80
_08090474:
	ldr r0, _080904AC
_08090476:
	ldr r0, [r0]
	mov r1, sp
	add r2, sp, 0xC8
	movs r3, 0
	bl xxx_format_string
	adds r0, r7, 0
	mov r1, sp
	bl sub_8090888
	movs r1, 0x1
	mov r8, r1
_0809048E:
	ldr r2, [sp, 0xE0]
	cmp r2, 0
	beq _0809054E
	ldr r0, _080904B0
	adds r1, r2, 0
	bl CopyCyanSpeciesNametoBuffer
	cmp r5, 0x3
	ble _080904D2
	mov r0, r8
	cmp r0, 0
	bne _080904B8
	ldr r0, _080904B4
	b _080904BA
	.align 2, 0
_080904AC: .4byte gUnknown_8115ADC
_080904B0: .4byte gAvailablePokemonNames
_080904B4: .4byte gUnknown_8115B3C
_080904B8:
	ldr r0, _08090528
_080904BA:
	ldr r0, [r0]
	mov r1, sp
	add r2, sp, 0xC8
	movs r3, 0
	bl xxx_format_string
	adds r0, r7, 0
	mov r1, sp
	bl sub_8090888
	movs r1, 0x1
	mov r8, r1
_080904D2:
	ldr r0, [sp, 0xE0]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r2, _0809052C
	mov r10, r2
	movs r6, 0x1
_080904E4:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	mov r2, r10
	ldr r0, [r2]
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08090510
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _08090510
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0
_08090510:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _080904E4
	cmp r5, 0x6
	ble _0809054E
	mov r2, r8
	cmp r2, 0
	bne _08090534
	ldr r0, _08090530
	b _08090536
	.align 2, 0
_08090528: .4byte gUnknown_8115BA4
_0809052C: .4byte gUnknown_203B45C
_08090530: .4byte gUnknown_8115BF4
_08090534:
	ldr r0, _080905D0
_08090536:
	ldr r0, [r0]
	mov r1, sp
	add r2, sp, 0xC8
	movs r3, 0
	bl xxx_format_string
	adds r0, r7, 0
	mov r1, sp
	bl sub_8090888
	movs r0, 0x1
	mov r8, r0
_0809054E:
	ldr r1, [sp, 0xE4]
	cmp r1, 0
	beq _08090602
	add r5, sp, 0xCC
	ldr r1, _080905D4
	adds r0, r5, 0
	movs r2, 0x8
	bl memcpy
	add r4, sp, 0xD4
	ldr r1, _080905D8
	adds r0, r4, 0
	movs r2, 0x4
	bl memcpy
	movs r6, 0
	mov r10, r4
	ldr r0, _080905DC
	add r0, r9
	ldrb r5, [r0, 0xB]
	add r4, sp, 0xCC
_08090578:
	adds r0, r5, 0
	asrs r0, r6
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809059E
	ldrh r0, [r4]
	bl sub_8090820
	lsls r0, 24
	cmp r0, 0
	bne _0809059E
	mov r2, r10
	adds r0, r2, r6
	ldrb r0, [r0]
	bl sub_80911A4
	cmp r0, 0
	beq _080905A6
_0809059E:
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08090578
_080905A6:
	cmp r6, 0x3
	bgt _08090602
	add r4, sp, 0xD8
	lsls r0, r6, 1
	add r0, sp
	adds r0, 0xCC
	ldrh r1, [r0]
	adds r0, r4, 0
	bl sub_8092A88
	ldr r0, _080905E0
	adds r1, r4, 0
	movs r2, 0
	bl sub_80928C0
	mov r0, r8
	cmp r0, 0
	bne _080905E8
	ldr r0, _080905E4
	b _080905EA
	.align 2, 0
_080905D0: .4byte gUnknown_8115C4C
_080905D4: .4byte gUnknown_8108F42
_080905D8: .4byte gUnknown_8108F4A
_080905DC: .4byte gDungeons
_080905E0: .4byte gUnknown_202DE58
_080905E4: .4byte gUnknown_8115CB8
_080905E8:
	ldr r0, _080906A0
_080905EA:
	ldr r0, [r0]
	mov r1, sp
	add r2, sp, 0xC8
	movs r3, 0
	bl xxx_format_string
	adds r0, r7, 0
	mov r1, sp
	bl sub_8090888
	movs r1, 0x1
	mov r8, r1
_08090602:
	ldr r0, _080906A4
	add r0, r9
	ldrb r1, [r0, 0xB]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080906CE
	ldr r5, _080906A8
	ldr r2, [sp, 0xE0]
	cmp r2, 0
	beq _0809063A
	adds r0, r2, 0
	movs r1, 0
	bl GetPokemonType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08090638
	ldr r0, [sp, 0xE0]
	movs r1, 0x1
	bl GetPokemonType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0809063A
_08090638:
	movs r5, 0
_0809063A:
	ldr r0, _080906A8
	cmp r5, r0
	bne _080906CE
	movs r5, 0
	movs r6, 0x1
_08090644:
	ldr r2, _080906AC
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08090686
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _08090686
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	movs r1, 0
	bl GetPokemonType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08090690
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	movs r1, 0x1
	bl GetPokemonType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08090690
_08090686:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _08090644
_08090690:
	ldr r0, _080906A8
	cmp r5, r0
	bne _080906CE
	mov r0, r8
	cmp r0, 0
	bne _080906B4
	ldr r0, _080906B0
	b _080906B6
	.align 2, 0
_080906A0: .4byte gUnknown_8115D14
_080906A4: .4byte gDungeons
_080906A8: .4byte 0x0000019d
_080906AC: .4byte gUnknown_203B45C
_080906B0: .4byte gUnknown_8115D5C
_080906B4:
	ldr r0, _080906D8
_080906B6:
	ldr r0, [r0]
	mov r1, sp
	add r2, sp, 0xC8
	movs r3, 0
	bl xxx_format_string
	adds r0, r7, 0
	mov r1, sp
	bl sub_8090888
	movs r1, 0x1
	mov r8, r1
_080906CE:
	mov r2, r8
	cmp r2, 0
	beq _080906DC
	movs r0, 0x1
	b _0809080E
	.align 2, 0
_080906D8: .4byte gUnknown_8115D94
_080906DC:
	ldr r0, _080907EC
	add r0, r9
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _080906EC
	ldr r0, [sp, 0xE8]
	cmp r0, 0
	beq _0809071A
_080906EC:
	ldr r1, [sp, 0xF4]
	cmp r1, 0
	bne _08090708
	ldr r0, _080907F0
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcpy
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
	movs r2, 0x1
	str r2, [sp, 0xF4]
_08090708:
	ldr r0, _080907F4
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcat
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
_0809071A:
	ldr r0, _080907EC
	add r0, r9
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _08090752
	ldr r0, [sp, 0xF4]
	cmp r0, 0
	bne _08090740
	ldr r0, _080907F0
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcpy
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
	movs r1, 0x1
	str r1, [sp, 0xF4]
_08090740:
	ldr r0, _080907F8
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcat
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
_08090752:
	ldr r0, _080907EC
	add r0, r9
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08090792
	ldr r2, [sp, 0xEC]
	ldr r0, [sp, 0xF0]
	cmn r2, r0
	beq _08090792
	ldr r1, [sp, 0xF4]
	cmp r1, 0
	bne _08090780
	ldr r0, _080907F0
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcpy
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
	movs r2, 0x1
	str r2, [sp, 0xF4]
_08090780:
	ldr r0, _080907FC
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcat
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
_08090792:
	ldr r0, _080907EC
	add r0, r9
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _080907DA
	ldr r0, _08090800
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _080907DA
	ldr r2, [sp, 0xF4]
	cmp r2, 0
	bne _080907C8
	ldr r0, _080907F0
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcpy
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
	movs r0, 0x1
	str r0, [sp, 0xF4]
_080907C8:
	ldr r0, _08090804
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcat
	adds r0, r7, 0
	add r1, sp, 0xC8
	bl strcat
_080907DA:
	ldr r1, [sp, 0xF4]
	cmp r1, 0
	bne _0809080C
	ldr r1, _08090808
	adds r0, r7, 0
	bl sub_800D158
	movs r0, 0
	b _0809080E
	.align 2, 0
_080907EC: .4byte gDungeons
_080907F0: .4byte gUnknown_8115DD4
_080907F4: .4byte gUnknown_8115E00
_080907F8: .4byte gUnknown_8115E28
_080907FC: .4byte gUnknown_8115E54
_08090800: .4byte gUnknown_203B460
_08090804: .4byte gUnknown_8115E80
_08090808: .4byte gUnknown_8108F50
_0809080C:
	movs r0, 0x2
_0809080E:
	add sp, 0xF8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809034C

	thumb_func_start sub_8090820
sub_8090820:
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r4, 0
	ldr r0, _08090868
	ldr r0, [r0]
	mov r12, r0
	movs r7, 0x1
_08090830:
	movs r0, 0x58
	muls r0, r4
	mov r2, r12
	adds r1, r2, r0
	ldrh r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	beq _08090874
	lsrs r0, r2, 1
	ands r0, r7
	cmp r0, 0
	beq _08090874
	movs r3, 0
	movs r5, 0x1
	adds r2, r1, 0
	adds r2, 0x2C
_08090852:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809086C
	ldrh r0, [r2, 0x2]
	cmp r0, r6
	bne _0809086C
	movs r0, 0x1
	b _08090880
	.align 2, 0
_08090868: .4byte gUnknown_203B45C
_0809086C:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08090852
_08090874:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08090830
	movs r0, 0
_08090880:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8090820

	thumb_func_start sub_8090888
sub_8090888:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r6, 0
	b _0809089C
_08090892:
	ldrb r0, [r4]
	cmp r0, 0xA
	bne _0809089A
	adds r6, 0x1
_0809089A:
	adds r4, 0x1
_0809089C:
	ldrb r0, [r4]
	cmp r0, 0
	bne _08090892
	ldrb r7, [r5]
	b _080908AE
_080908A6:
	movs r0, 0xA
	strb r0, [r4]
	adds r4, 0x1
	adds r6, 0x1
_080908AE:
	adds r0, r6, 0
	movs r1, 0x3
	bl __modsi3
	cmp r0, 0
	bne _080908A6
	adds r1, r7, 0
	lsls r0, r1, 24
	cmp r0, 0
	beq _080908CE
_080908C2:
	strb r1, [r4]
	adds r4, 0x1
	adds r5, 0x1
	ldrb r1, [r5]
	cmp r1, 0
	bne _080908C2
_080908CE:
	movs r0, 0
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8090888

	thumb_func_start sub_80908D8
sub_80908D8:
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0x3E
	bhi _08090908
	ldr r0, _08090900
	ldrb r3, [r2]
	adds r0, r3, r0
	ldrb r1, [r2, 0x1]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _08090908
	ldr r1, _08090904
	lsls r0, r3, 2
	adds r0, r1
	ldrb r1, [r2, 0x1]
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	b _0809090A
	.align 2, 0
_08090900: .4byte gUnknown_81077A8
_08090904: .4byte gUnknown_8108084
_08090908:
	movs r0, 0x1
_0809090A:
	pop {r1}
	bx r1
	thumb_func_end sub_80908D8

	thumb_func_start sub_8090910
sub_8090910:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	ldr r4, _0809094C
	adds r0, r4, 0
	bl RandomCapped
	adds r6, r0, 0
	adds r0, r4, 0
	bl RandomCapped
	adds r2, r0, 0
	ldrb r0, [r5]
	cmp r0, 0x3E
	bhi _08090954
	ldr r0, _08090950
	ldrb r1, [r5]
	adds r1, r0
	ldrb r0, [r5, 0x1]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08090954
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_8091E94
	lsls r0, 24
	lsrs r0, 24
	b _08090956
	.align 2, 0
_0809094C: .4byte 0x0000270f
_08090950: .4byte gUnknown_81077A8
_08090954:
	movs r0, 0x46
_08090956:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8090910

	thumb_func_start sub_809095C
sub_809095C:
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x3E
	bls _0809096A
_08090966:
	movs r0, 0x1
	b _0809098C
_0809096A:
	movs r2, 0
	ldr r0, _08090994
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0x3F
	beq _0809098A
	adds r1, r4, 0
_08090978:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, r3
	beq _08090966
	adds r2, 0x1
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, 0x3F
	bne _08090978
_0809098A:
	movs r0, 0
_0809098C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08090994: .4byte gUnknown_810A350
	thumb_func_end sub_809095C

	thumb_func_start LoadItemParameters
LoadItemParameters:
	push {lr}
	ldr r1, _080909B8
	ldr r0, _080909BC
	str r0, [r1]
	ldr r0, _080909C0
	ldr r1, _080909C4
	bl OpenFileAndGetFileDataPtr
	ldr r1, _080909C8
	str r0, [r1]
	ldr r1, _080909CC
	ldr r0, [r0, 0x4]
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080909B8: .4byte gUnknown_203B460
_080909BC: .4byte gUnknown_20389A8
_080909C0: .4byte gUnknown_8109764
_080909C4: .4byte gSystemFileArchive
_080909C8: .4byte gItemParametersFile
_080909CC: .4byte gItemParametersFile + 4
	thumb_func_end LoadItemParameters

	thumb_func_start sub_80909D0
sub_80909D0:
	ldr r0, _080909D4
	bx lr
	.align 2, 0
_080909D4: .4byte gUnknown_20389A8
	thumb_func_end sub_80909D0

	thumb_func_start sub_80909D8
sub_80909D8:
	push {r4,lr}
	movs r4, 0
	ldr r3, _08090A30
	movs r2, 0
_080909E0:
	ldr r0, [r3]
	lsls r1, r4, 2
	adds r0, r1
	strb r2, [r0]
	adds r4, 0x1
	cmp r4, 0x13
	ble _080909E0
	movs r4, 0
	ldr r3, _08090A30
	movs r2, 0
_080909F4:
	ldr r0, [r3]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r0, r1
	strh r2, [r0]
	adds r4, 0x1
	cmp r4, 0xEF
	ble _080909F4
	movs r4, 0
_08090A06:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091840
	adds r4, 0x1
	cmp r4, 0x7
	ble _08090A06
	ldr r0, _08090A30
	ldr r2, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r2, r1
	movs r1, 0
	str r1, [r0]
	movs r3, 0x99
	lsls r3, 2
	adds r0, r2, r3
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090A30: .4byte gUnknown_203B460
	thumb_func_end sub_80909D8

	thumb_func_start sub_8090A34
sub_8090A34:
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, _08090A5C
	movs r5, 0x1
	ldr r2, [r0]
	movs r3, 0x13
_08090A40:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08090A4C
	adds r4, 0x1
_08090A4C:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _08090A40
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08090A5C: .4byte gUnknown_203B460
	thumb_func_end sub_8090A34

	thumb_func_start sub_8090A60
sub_8090A60:
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8090BD0
	lsls r0, 24
	cmp r0, 0
	beq _08090A84
	adds r0, r4, 0
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08090A84
	movs r0, 0
	b _08090A86
_08090A84:
	movs r0, 0x1
_08090A86:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8090A60

	thumb_func_start sub_8090A8C
sub_8090A8C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	cmp r5, 0
	beq _08090AF8
	movs r7, 0x1
	strb r7, [r6]
	strb r5, [r6, 0x2]
	adds r0, r5, 0
	bl sub_8090A60
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08090AD4
	adds r0, r5, 0
	movs r1, 0
	bl sub_8090D80
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8090D80
	adds r1, r0, 0
	adds r0, r4, 0
	bl RandomRange
	strb r0, [r6, 0x1]
	b _08090AE8
_08090AD4:
	adds r0, r5, 0
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08090AE6
	strb r7, [r6, 0x1]
	b _08090AE8
_08090AE6:
	strb r4, [r6, 0x1]
_08090AE8:
	mov r0, r8
	cmp r0, 0
	beq _08090AFE
	ldrb r1, [r6]
	movs r0, 0x8
	orrs r0, r1
	strb r0, [r6]
	b _08090AFE
_08090AF8:
	strb r5, [r6]
	strb r5, [r6, 0x2]
	strb r5, [r6, 0x1]
_08090AFE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8090A8C

	thumb_func_start sub_8090B08
sub_8090B08:
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r5, 0
	beq _08090B5A
	strb r5, [r6]
	adds r0, r5, 0
	bl sub_8090A60
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08090B42
	adds r0, r5, 0
	movs r1, 0
	bl sub_8090D80
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8090D80
	adds r1, r0, 0
	adds r0, r4, 0
	bl RandomRange
	strb r0, [r6, 0x1]
	b _08090B5E
_08090B42:
	adds r0, r5, 0
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08090B56
	movs r0, 0x1
	strb r0, [r6, 0x1]
	b _08090B5E
_08090B56:
	strb r4, [r6, 0x1]
	b _08090B5E
_08090B5A:
	strb r5, [r6]
	strb r5, [r6, 0x1]
_08090B5E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8090B08

	thumb_func_start sub_8090B64
sub_8090B64:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r1, [r5]
	adds r0, r1, 0
	cmp r0, 0
	beq _08090BA4
	movs r0, 0x1
	strb r0, [r4]
	strb r1, [r4, 0x2]
	ldrb r0, [r4, 0x2]
	bl sub_8090A60
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08090B9A
	ldrb r0, [r4, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _08090B9A
	ldrb r0, [r4, 0x2]
	cmp r0, 0x7C
	bne _08090BA0
_08090B9A:
	ldrb r0, [r5, 0x1]
	strb r0, [r4, 0x1]
	b _08090BAA
_08090BA0:
	strb r6, [r4, 0x1]
	b _08090BAA
_08090BA4:
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x1]
	strb r0, [r4]
_08090BAA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8090B64

	thumb_func_start sub_8090BB0
sub_8090BB0:
	push {lr}
	adds r3, r0, 0
	ldrb r0, [r1]
	movs r2, 0x1
	ands r2, r0
	cmp r2, 0
	beq _08090BC8
	ldrb r0, [r1, 0x2]
	strb r0, [r3]
	ldrb r0, [r1, 0x1]
	strb r0, [r3, 0x1]
	b _08090BCA
_08090BC8:
	strb r2, [r3]
_08090BCA:
	pop {r0}
	bx r0
	thumb_func_end sub_8090BB0

	thumb_func_start sub_8090BD0
sub_8090BD0:
	lsls r0, 24
	ldr r1, _08090BE0
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldrb r0, [r0, 0xC]
	bx lr
	.align 2, 0
_08090BE0: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090BD0

	thumb_func_start sub_8090BE4
sub_8090BE4:
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _08090BF6
	adds r0, r4, 0
	bl sub_80915D4
	b _08090C24
_08090BF6:
	ldrb r0, [r4, 0x2]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08090C14
	ldrb r0, [r4, 0x2]
	ldr r1, _08090C10
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldr r0, [r0, 0x4]
	b _08090C24
	.align 2, 0
_08090C10: .4byte gItemParametersFile + 4
_08090C14:
	ldrb r0, [r4, 0x2]
	ldr r1, _08090C2C
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldrb r1, [r4, 0x1]
	ldr r0, [r0, 0x4]
	muls r0, r1
_08090C24:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08090C2C: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090BE4

	thumb_func_start sub_8090C30
sub_8090C30:
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _08090C42
	adds r0, r4, 0
	bl sub_80915D4
	b _08090C70
_08090C42:
	ldrb r0, [r4, 0x2]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08090C60
	ldrb r0, [r4, 0x2]
	ldr r1, _08090C5C
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldr r0, [r0, 0x8]
	b _08090C70
	.align 2, 0
_08090C5C: .4byte gItemParametersFile + 4
_08090C60:
	ldrb r0, [r4, 0x2]
	ldr r1, _08090C78
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldrb r1, [r4, 0x1]
	ldr r0, [r0, 0x8]
	muls r0, r1
_08090C70:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08090C78: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090C30

	thumb_func_start sub_8090C7C
sub_8090C7C:
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	bne _08090C90
	movs r0, 0
	b _08090CC0
_08090C90:
	ldrb r0, [r4, 0x2]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08090CB0
	ldrb r0, [r4, 0x2]
	ldr r1, _08090CAC
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldr r0, [r0, 0x4]
	b _08090CC0
	.align 2, 0
_08090CAC: .4byte gItemParametersFile + 4
_08090CB0:
	ldrb r0, [r4, 0x2]
	ldr r1, _08090CC8
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldrb r1, [r4, 0x1]
	ldr r0, [r0, 0x4]
	muls r0, r1
_08090CC0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08090CC8: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090C7C

	thumb_func_start sub_8090CCC
sub_8090CCC:
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	bl sub_80914E4
	lsls r0, 24
	cmp r0, 0
	bne _08090CE0
	movs r0, 0
	b _08090D10
_08090CE0:
	ldrb r0, [r4, 0x2]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08090D00
	ldrb r0, [r4, 0x2]
	ldr r1, _08090CFC
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldr r0, [r0, 0x8]
	b _08090D10
	.align 2, 0
_08090CFC: .4byte gItemParametersFile + 4
_08090D00:
	ldrb r0, [r4, 0x2]
	ldr r1, _08090D18
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldrb r1, [r4, 0x1]
	ldr r0, [r0, 0x8]
	muls r0, r1
_08090D10:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08090D18: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090CCC

	thumb_func_start sub_8090D1C
sub_8090D1C:
	lsls r0, 24
	ldr r1, _08090D2C
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldr r0, [r0, 0x4]
	bx lr
	.align 2, 0
_08090D2C: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090D1C

	thumb_func_start sub_8090D30
sub_8090D30:
	lsls r0, 24
	ldr r1, _08090D40
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldr r0, [r0, 0x8]
	bx lr
	.align 2, 0
_08090D40: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090D30

	thumb_func_start sub_8090D44
sub_8090D44:
	lsls r0, 24
	ldr r1, _08090D54
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldrb r0, [r0, 0x1A]
	bx lr
	.align 2, 0
_08090D54: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090D44

	thumb_func_start sub_8090D58
sub_8090D58:
	lsls r0, 24
	ldr r1, _08090D68
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldrb r0, [r0, 0x1D]
	bx lr
	.align 2, 0
_08090D68: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090D58

	thumb_func_start sub_8090D6C
sub_8090D6C:
	lsls r0, 24
	ldr r1, _08090D7C
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldrb r0, [r0, 0x1E]
	bx lr
	.align 2, 0
_08090D7C: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090D6C

	thumb_func_start sub_8090D80
sub_8090D80:
	lsls r0, 24
	ldr r2, _08090D94
	ldr r2, [r2]
	lsrs r0, 19
	adds r0, r2
	adds r0, 0x1B
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08090D94: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090D80

	thumb_func_start sub_8090D98
sub_8090D98:
	lsls r0, 24
	ldr r1, _08090DA8
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldr r0, [r0, 0x10]
	bx lr
	.align 2, 0
_08090DA8: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090D98

	thumb_func_start sub_8090DAC
sub_8090DAC:
	lsls r0, 24
	ldr r2, _08090DC0
	ldr r2, [r2]
	lsrs r0, 19
	adds r0, r2
	adds r0, 0x14
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08090DC0: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090DAC

	thumb_func_start sub_8090DC4
sub_8090DC4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x54
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _08090E10
	ldr r1, [r0]
	lsls r0, r4, 5
	adds r0, r1
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x50
	bl strncpy
	add r5, sp, 0x50
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090A8C
	movs r0, 0x1
	strb r0, [r5, 0x1]
	adds r0, r6, 0
	mov r1, sp
	adds r2, r5, 0
	mov r3, r8
	bl sub_8090F58
	add sp, 0x54
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090E10: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090DC4

	thumb_func_start sub_8090E14
sub_8090E14:
	push {r4-r7,lr}
	sub sp, 0x50
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	movs r4, 0
	cmp r7, 0
	beq _08090E2C
	ldrb r1, [r7, 0x8]
	negs r0, r1
	orrs r0, r1
	lsrs r4, r0, 31
_08090E2C:
	ldrb r0, [r5, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	cmp r0, 0
	bne _08090E3E
	cmp r4, 0
	bne _08090E50
	b _08090E70
_08090E3E:
	ldrb r0, [r5, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08090E90
	cmp r4, 0
	beq _08090E70
_08090E50:
	ldr r1, _08090E68
	ldrb r0, [r5, 0x2]
	ldr r2, _08090E6C
	ldr r2, [r2]
	lsls r0, 5
	adds r0, r2
	ldr r2, [r0]
	ldrb r3, [r5, 0x1]
	mov r0, sp
	bl sub_800D158
	b _08090EC4
	.align 2, 0
_08090E68: .4byte gUnknown_8109770
_08090E6C: .4byte gItemParametersFile + 4
_08090E70:
	ldr r1, _08090E88
	ldrb r0, [r5, 0x2]
	ldr r2, _08090E8C
	ldr r2, [r2]
	lsls r0, 5
	adds r0, r2
	ldr r2, [r0]
	mov r0, sp
	bl sub_800D158
	b _08090EC4
	.align 2, 0
_08090E88: .4byte gUnknown_8109778
_08090E8C: .4byte gItemParametersFile + 4
_08090E90:
	ldrb r0, [r5, 0x2]
	cmp r0, 0x69
	bne _08090EB0
	ldr r4, _08090EAC
	adds r0, r5, 0
	bl sub_80915D4
	adds r2, r0, 0
	mov r0, sp
	adds r1, r4, 0
	bl sub_800D158
	b _08090EC4
	.align 2, 0
_08090EAC: .4byte gUnknown_810977C
_08090EB0:
	ldrb r0, [r5, 0x2]
	ldr r1, _08090F2C
	ldr r1, [r1]
	lsls r0, 5
	adds r0, r1
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x50
	bl strncpy
_08090EC4:
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08090EE2
	ldr r1, _08090F30
	adds r0, r6, 0
	mov r2, sp
	bl sub_800D158
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0x50
	bl strncpy
_08090EE2:
	cmp r7, 0
	beq _08090F38
	ldrb r0, [r7, 0x4]
	cmp r0, 0
	beq _08090F0A
	ldrb r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08090F0A
	ldr r1, _08090F34
	adds r0, r6, 0
	mov r2, sp
	bl sub_800D158
	mov r0, sp
	adds r1, r6, 0
	movs r2, 0x50
	bl strncpy
_08090F0A:
	ldr r0, [r7]
	cmp r0, 0x1
	beq _08090F14
	cmp r0, 0x3
	bne _08090F44
_08090F14:
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08090F38
	adds r0, r6, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8090F58
	b _08090F50
	.align 2, 0
_08090F2C: .4byte gItemParametersFile + 4
_08090F30: .4byte gUnknown_8109784
_08090F34: .4byte gUnknown_810978C
_08090F38:
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x50
	bl strncpy
	b _08090F50
_08090F44:
	adds r0, r6, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8090F58
_08090F50:
	add sp, 0x50
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8090E14

	thumb_func_start sub_8090F58
sub_8090F58:
	push {r4-r6,lr}
	sub sp, 0x2C
	adds r5, r0, 0
	adds r6, r1, 0
	adds r0, r2, 0
	adds r4, r3, 0
	cmp r4, 0
	bne _08090F6C
	adds r0, r5, 0
	b _08090F94
_08090F6C:
	ldr r1, [r4]
	cmp r1, 0x1
	bcc _08090F8A
	cmp r1, 0x2
	bhi _08090F7E
	bl sub_8090BE4
	adds r1, r0, 0
	b _08090F8C
_08090F7E:
	cmp r1, 0x4
	bhi _08090F8A
	bl sub_8090C30
	adds r1, r0, 0
	b _08090F8C
_08090F8A:
	movs r1, 0
_08090F8C:
	cmp r1, 0
	bne _08090F9C
	adds r0, r5, 0
	adds r1, r6, 0
_08090F94:
	movs r2, 0x50
	bl strncpy
	b _08090FDE
_08090F9C:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08090FC8
	adds r0, r1, 0
	add r1, sp, 0x4
	movs r2, 0x1
	bl sub_8090FEC
	ldr r1, _08090FC4
	movs r0, 0x6
	ldrsh r3, [r4, r0]
	add r2, sp, 0x4
	str r2, [sp]
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_800D158
	b _08090FDE
	.align 2, 0
_08090FC4: .4byte gUnknown_8109794
_08090FC8:
	adds r0, r1, 0
	add r1, sp, 0x4
	movs r2, 0
	bl sub_8090FEC
	ldr r1, _08090FE8
	adds r0, r5, 0
	adds r2, r6, 0
	add r3, sp, 0x4
	bl sub_800D158
_08090FDE:
	add sp, 0x2C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090FE8: .4byte gUnknown_81097A4
	thumb_func_end sub_8090F58

	thumb_func_start sub_8090FEC
sub_8090FEC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	movs r0, 0
	mov r8, r0
	movs r6, 0
	movs r2, 0
	ldr r1, _08091050
	mov r9, r1
	mov r12, r9
_0809100E:
	movs r1, 0
	lsls r3, r2, 2
	ldr r7, _08091054
	adds r0, r3, r7
	ldr r0, [r0]
	adds r7, r2, 0x1
	cmp r5, r0
	blt _0809102C
	ldr r2, _08091054
_08091020:
	adds r0, r3, r2
	ldr r0, [r0]
	subs r5, r0
	adds r1, 0x1
	cmp r5, r0
	bge _08091020
_0809102C:
	cmp r1, 0x9
	ble _08091032
	movs r1, 0x9
_08091032:
	cmp r1, 0
	beq _0809105C
	movs r0, 0x1
	mov r8, r0
	lsls r1, 1
	mov r2, r12
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	ldr r0, _08091058
	adds r1, r0
	ldrb r0, [r1]
	b _0809106C
	.align 2, 0
_08091050: .4byte gUnknown_81097C4
_08091054: .4byte gUnknown_81097B0
_08091058: .4byte gUnknown_81097C5
_0809105C:
	mov r1, r8
	cmp r1, 0
	beq _08091074
	mov r2, r12
	ldrb r0, [r2]
	strb r0, [r4]
	adds r4, 0x1
	ldrb r0, [r2, 0x1]
_0809106C:
	strb r0, [r4]
	adds r4, 0x1
	adds r6, 0x1
	b _08091080
_08091074:
	mov r0, r10
	cmp r0, 0
	beq _08091080
	movs r0, 0x60
	strb r0, [r4]
	adds r4, 0x1
_08091080:
	adds r2, r7, 0
	cmp r2, 0x4
	ble _0809100E
	lsls r1, r5, 1
	mov r2, r9
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, 0x1
	mov r0, r9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r4]
	adds r6, 0x1
	movs r0, 0
	strb r0, [r4, 0x1]
	adds r0, r6, 0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8090FEC

	thumb_func_start sub_80910B4
sub_80910B4:
	push {r4-r7,lr}
	movs r2, 0
	movs r4, 0
	ldr r7, _080910C0
	movs r3, 0
	b _080910DA
	.align 2, 0
_080910C0: .4byte gUnknown_203B460
_080910C4:
	cmp r2, r4
	ble _080910D4
	ldr r0, [r7]
	lsls r1, r4, 2
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_080910D4:
	adds r3, 0x4
	adds r2, 0x1
	adds r4, 0x1
_080910DA:
	cmp r2, 0x13
	bgt _08091106
	ldr r0, [r7]
	adds r0, r3, r0
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08091106
	ldr r5, _0809112C
	movs r6, 0x1
_080910F0:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x13
	bgt _08091106
	ldr r0, [r5]
	adds r0, r3, r0
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080910F0
_08091106:
	cmp r2, 0x14
	bne _080910C4
	cmp r4, 0x13
	bgt _08091124
	ldr r3, _0809112C
	movs r2, 0
_08091112:
	lsls r1, r4, 2
	ldr r0, [r3]
	adds r1, r0
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x1]
	strb r2, [r1]
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091112
_08091124:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809112C: .4byte gUnknown_203B460
	thumb_func_end sub_80910B4

	thumb_func_start sub_8091130
sub_8091130:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, _08091154
	ldr r2, [r0]
	movs r5, 0x1
_0809113E:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08091158
	ldrb r0, [r2, 0x2]
	cmp r0, r4
	bne _08091158
	adds r0, r3, 0
	b _08091164
	.align 2, 0
_08091154: .4byte gUnknown_203B460
_08091158:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _0809113E
	movs r0, 0x1
	negs r0, r0
_08091164:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8091130

	thumb_func_start sub_809116C
sub_809116C:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, _080911A0
	ldr r2, [r0]
	movs r6, 0x1
	movs r3, 0x13
_0809117C:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809118E
	ldrb r0, [r2, 0x2]
	cmp r0, r5
	bne _0809118E
	adds r4, 0x1
_0809118E:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0809117C
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080911A0: .4byte gUnknown_203B460
	thumb_func_end sub_809116C

	thumb_func_start sub_80911A4
sub_80911A4:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_809116C
	adds r4, r0, 0
	movs r3, 0
	ldr r0, _080911F4
	ldr r7, [r0]
	movs r6, 0x1
_080911BA:
	movs r0, 0x58
	muls r0, r3
	adds r2, r7, r0
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080911E2
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _080911E2
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	beq _080911E2
	cmp r0, r5
	bne _080911E2
	adds r4, 0x1
_080911E2:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _080911BA
	adds r0, r4, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080911F4: .4byte gUnknown_203B45C
	thumb_func_end sub_80911A4

	thumb_func_start sub_80911F8
sub_80911F8:
	push {r4,r5,lr}
	adds r2, r0, 0
	ldr r4, _08091230
	cmp r2, 0x12
	bgt _0809121C
	adds r5, r4, 0
	lsls r0, r2, 2
	adds r3, r0, 0x4
_08091208:
	ldr r0, [r5]
	lsls r1, r2, 2
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x12
	ble _08091208
_0809121C:
	ldr r0, [r4]
	adds r0, 0x4E
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x4C
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091230: .4byte gUnknown_203B460
	thumb_func_end sub_80911F8

	thumb_func_start sub_8091234
sub_8091234:
	ldr r3, _08091248
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	movs r2, 0
	strb r2, [r1, 0x2]
	ldr r1, [r3]
	adds r1, r0
	strb r2, [r1]
	bx lr
	.align 2, 0
_08091248: .4byte gUnknown_203B460
	thumb_func_end sub_8091234

	thumb_func_start sub_809124C
sub_809124C:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	mov r0, sp
	adds r1, r3, 0
	bl sub_8090A8C
	mov r0, sp
	bl sub_8091290
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_809124C

	thumb_func_start sub_8091274
sub_8091274:
	push {lr}
	sub sp, 0x4
	adds r1, r0, 0
	mov r0, sp
	bl sub_8090B64
	mov r0, sp
	bl sub_8091290
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8091274

	thumb_func_start sub_8091290
sub_8091290:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _080912B4
	movs r6, 0x1
_0809129A:
	lsls r1, r3, 2
	ldr r0, [r5]
	adds r2, r1, r0
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _080912B8
	ldr r0, [r4]
	str r0, [r2]
	movs r0, 0
	b _080912C0
	.align 2, 0
_080912B4: .4byte gUnknown_203B460
_080912B8:
	adds r3, 0x1
	cmp r3, 0x13
	ble _0809129A
	movs r0, 0x1
_080912C0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8091290

	thumb_func_start sub_80912C8
sub_80912C8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r5, 0
	movs r6, 0
_080912D6:
	ldr r0, _0809139C
	lsls r1, r5, 2
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080912FE
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _080912FE
	adds r0, r4, 0
	bl sub_80915D4
	bl sub_80913A0
	strb r6, [r4, 0x2]
	strb r6, [r4, 0x1]
	strb r6, [r4]
_080912FE:
	adds r5, 0x1
	cmp r5, 0x13
	ble _080912D6
	bl sub_80910B4
	movs r5, 0
_0809130A:
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	lsls r2, r5, 2
	ldr r1, _0809139C
	mov r8, r1
	ldr r0, [r1]
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	mov r10, r2
	adds r7, r5, 0x1
	cmp r0, 0
	beq _08091382
	ldrb r0, [r3, 0x2]
	bl sub_8090D44
	adds r6, r0, 0
	adds r4, r7, 0
	cmp r7, 0x13
	bgt _08091368
_08091336:
	lsls r5, r4, 2
	mov r1, r8
	ldr r0, [r1]
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08091362
	ldrb r0, [r2, 0x2]
	bl sub_8090D44
	cmp r6, r0
	ble _08091362
	mov r9, r4
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5
	ldrb r0, [r0, 0x2]
	bl sub_8090D44
	adds r6, r0, 0
_08091362:
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091336
_08091368:
	mov r4, r9
	cmp r4, 0
	blt _08091382
	ldr r0, _0809139C
	ldr r1, [r0]
	mov r0, r10
	adds r2, r1, r0
	ldr r3, [r2]
	lsls r0, r4, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
_08091382:
	adds r5, r7, 0
	cmp r5, 0x13
	ble _0809130A
	bl sub_80910B4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809139C: .4byte gUnknown_203B460
	thumb_func_end sub_80912C8

	thumb_func_start sub_80913A0
sub_80913A0:
	push {lr}
	ldr r1, _080913C4
	ldr r1, [r1]
	movs r3, 0x98
	lsls r3, 2
	adds r2, r1, r3
	ldr r1, [r2]
	adds r1, r0
	str r1, [r2]
	ldr r0, _080913C8
	cmp r1, r0
	bgt _080913BE
	cmp r1, 0
	bge _080913C0
	movs r0, 0
_080913BE:
	str r0, [r2]
_080913C0:
	pop {r0}
	bx r0
	.align 2, 0
_080913C4: .4byte gUnknown_203B460
_080913C8: .4byte 0x0001869f
	thumb_func_end sub_80913A0

	thumb_func_start sub_80913CC
sub_80913CC:
	lsls r0, 24
	ldr r1, _080913DC
	ldr r1, [r1]
	lsrs r0, 19
	adds r0, r1
	ldrh r0, [r0, 0x18]
	bx lr
	.align 2, 0
_080913DC: .4byte gItemParametersFile + 4
	thumb_func_end sub_80913CC

	thumb_func_start sub_80913E0
sub_80913E0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x5C
	adds r6, r0, 0
	adds r5, r1, 0
	mov r8, r2
	ldrb r0, [r6, 0x2]
	bl sub_8090D98
	ldrb r1, [r6, 0x2]
	add r0, sp, 0x4
	movs r2, 0
	bl sub_8090DC4
	ldrb r0, [r6, 0x2]
	cmp r0, 0x7C
	bne _08091414
	ldr r0, _080914D4
	ldrb r1, [r6, 0x1]
	adds r1, 0x7D
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	bl sub_8090DC4
_08091414:
	adds r0, r5, 0
	bl sub_80073B8
	movs r7, 0
	str r7, [sp]
	movs r0, 0x10
	movs r1, 0
	add r2, sp, 0x4
	adds r3, r5, 0
	bl sub_8014FF0
	ldrb r0, [r6, 0x2]
	bl sub_8090D98
	adds r2, r0, 0
	str r7, [sp]
	movs r0, 0x8
	movs r1, 0x18
	adds r3, r5, 0
	bl sub_8014FF0
	ldrb r0, [r6, 0x2]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _080914B6
	add r4, sp, 0x54
	ldrb r0, [r6, 0x2]
	bl sub_80913CC
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_8092A88
	movs r0, 0x7
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0x4
	movs r2, 0x52
	movs r3, 0xC8
	bl sub_80078A4
	ldr r0, _080914D8
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x4
	movs r1, 0x54
	adds r3, r5, 0
	bl sub_8014FF0
	adds r0, r4, 0
	bl sub_8092B00
	lsls r0, 24
	lsrs r0, 24
	bl GetUnformattedTypeString
	adds r2, r0, 0
	str r7, [sp]
	movs r0, 0x40
	movs r1, 0x54
	adds r3, r5, 0
	bl sub_8014FF0
	adds r0, r4, 0
	bl sub_8092BF4
	ldr r1, _080914DC
	str r0, [r1]
	ldr r0, _080914E0
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x80
	movs r1, 0x54
	adds r3, r5, 0
	bl sub_8014FF0
_080914B6:
	adds r0, r5, 0
	bl sub_80073E0
	ldrb r0, [r6, 0x2]
	bl sub_8090D98
	mov r1, r8
	bl sub_8097DF0
	add sp, 0x5C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080914D4: .4byte gUnknown_202DE58
_080914D8: .4byte gUnknown_810CF0C
_080914DC: .4byte gUnknown_202DE30
_080914E0: .4byte gUnknown_8115970
	thumb_func_end sub_80913E0

	thumb_func_start sub_80914E4
sub_80914E4:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r0, 0
	beq _0809151A
	cmp r0, 0x69
	beq _0809151A
	cmp r0, 0x79
	beq _0809151A
	cmp r0, 0x77
	beq _0809151A
	cmp r0, 0x78
	beq _0809151A
	cmp r0, 0x7A
	beq _0809151A
	bl sub_8090D30
	cmp r0, 0
	beq _0809151A
	adds r0, r4, 0
	bl sub_8090D1C
	cmp r0, 0
	beq _0809151A
	movs r0, 0x1
	b _0809151C
_0809151A:
	movs r0, 0
_0809151C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80914E4

	thumb_func_start sub_8091524
sub_8091524:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0
	beq _0809153C
	cmp r0, 0x69
	beq _0809153C
	cmp r1, 0x7C
	beq _0809153C
	movs r0, 0x1
	b _0809153E
_0809153C:
	movs r0, 0
_0809153E:
	pop {r1}
	bx r1
	thumb_func_end sub_8091524

	thumb_func_start sub_8091544
sub_8091544:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0
	beq _08091568
	cmp r0, 0x69
	beq _08091568
	cmp r0, 0x79
	beq _08091568
	cmp r0, 0x77
	beq _08091568
	cmp r0, 0x78
	beq _08091568
	cmp r1, 0x7A
	beq _08091568
	movs r0, 0x1
	b _0809156A
_08091568:
	movs r0, 0
_0809156A:
	pop {r1}
	bx r1
	thumb_func_end sub_8091544

	thumb_func_start sub_8091570
sub_8091570:
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _08091596
	adds r0, r4, 0
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08091596
	movs r0, 0
	b _08091598
_08091596:
	movs r0, 0x1
_08091598:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8091570

	thumb_func_start sub_80915A0
sub_80915A0:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0xE0
	beq _080915CC
	cmp r0, 0xE1
	beq _080915CC
	cmp r0, 0xE2
	beq _080915CC
	cmp r0, 0xE3
	beq _080915CC
	cmp r0, 0xE4
	beq _080915CC
	cmp r0, 0xE5
	beq _080915CC
	cmp r0, 0xE6
	beq _080915CC
	cmp r1, 0xE7
	beq _080915CC
	movs r0, 0
	b _080915CE
_080915CC:
	movs r0, 0x1
_080915CE:
	pop {r1}
	bx r1
	thumb_func_end sub_80915A0

	thumb_func_start sub_80915D4
sub_80915D4:
	ldr r1, _080915E0
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080915E0: .4byte gUnknown_810A3F0
	thumb_func_end sub_80915D4

	thumb_func_start sub_80915E4
sub_80915E4:
	ldr r1, _080915F0
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080915F0: .4byte gUnknown_810A3F0
	thumb_func_end sub_80915E4

	thumb_func_start sub_80915F4
sub_80915F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r3, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r0, _080916B8
	strh r0, [r7]
	movs r0, 0
	strh r0, [r7, 0x2]
	adds r0, r5, 0
	bl sub_8091764
	lsls r0, 24
	cmp r0, 0
	bne _0809161E
	b _08091756
_0809161E:
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	movs r1, 0
	bl GetPokemonType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r2, 0x8
	ldrsh r0, [r6, r2]
	movs r1, 0x1
	bl GetPokemonType
	lsls r0, 24
	lsrs r0, 24
	adds r2, r5, 0
	subs r2, 0x55
	ldr r5, _080916BC
	lsls r2, 1
	lsls r1, r4, 3
	adds r1, r4
	lsls r1, 2
	adds r1, r2, r1
	adds r1, r5
	movs r4, 0
	ldrsh r3, [r1, r4]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	adds r2, r5
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r2, 0x14
	ldrsh r1, [r6, r2]
	adds r3, r0
	ldrh r4, [r6, 0x14]
	adds r3, r4
	strh r3, [r6, 0x14]
	movs r2, 0x14
	ldrsh r0, [r6, r2]
	subs r1, r0, r1
	lsls r3, 16
	cmp r3, 0
	bgt _0809167C
	movs r0, 0x1
	strh r0, [r6, 0x14]
_0809167C:
	movs r4, 0x14
	ldrsh r0, [r6, r4]
	ldr r2, _080916C0
	cmp r0, r2
	ble _08091688
	strh r2, [r6, 0x14]
_08091688:
	movs r0, 0
	cmp r1, 0x8
	bgt _0809169C
	movs r0, 0x1
	cmp r1, 0x4
	bgt _0809169C
	movs r0, 0x3
	cmp r1, 0x2
	ble _0809169C
	movs r0, 0x2
_0809169C:
	strh r0, [r7]
	mov r1, r8
	cmp r1, 0
	bne _08091756
	cmp r0, 0
	bne _080916C4
	movs r0, 0x10
	bl RandomCapped
	cmp r0, 0xA
	bne _080916C4
	movs r0, 0xF
	b _080916D2
	.align 2, 0
_080916B8: .4byte 0x0000ffff
_080916BC: .4byte gUnknown_810A580
_080916C0: .4byte 0x000003e7
_080916C4:
	movs r0, 0x4
	bl RandomCapped
	ldr r1, _080916EC
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
_080916D2:
	strh r0, [r7, 0x2]
	ldrh r1, [r7, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080916F6
	ldrb r0, [r6, 0x18]
	cmp r0, 0xFE
	bhi _080916F0
	adds r0, 0x1
	strb r0, [r6, 0x18]
	b _080916F6
	.align 2, 0
_080916EC: .4byte gUnknown_81097E0
_080916F0:
	ldr r0, _0809170C
	ands r0, r1
	strh r0, [r7, 0x2]
_080916F6:
	ldrh r1, [r7, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08091716
	ldrb r0, [r6, 0x19]
	cmp r0, 0xFE
	bhi _08091710
	adds r0, 0x1
	strb r0, [r6, 0x19]
	b _08091716
	.align 2, 0
_0809170C: .4byte 0x0000fffe
_08091710:
	ldr r0, _0809172C
	ands r0, r1
	strh r0, [r7, 0x2]
_08091716:
	ldrh r1, [r7, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08091736
	ldrb r0, [r6, 0x1A]
	cmp r0, 0xFE
	bhi _08091730
	adds r0, 0x1
	strb r0, [r6, 0x1A]
	b _08091736
	.align 2, 0
_0809172C: .4byte 0x0000fffd
_08091730:
	ldr r0, _0809174C
	ands r0, r1
	strh r0, [r7, 0x2]
_08091736:
	ldrh r1, [r7, 0x2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08091756
	ldrb r0, [r6, 0x1B]
	cmp r0, 0xFE
	bhi _08091750
	adds r0, 0x1
	strb r0, [r6, 0x1B]
	b _08091756
	.align 2, 0
_0809174C: .4byte 0x0000fffb
_08091750:
	ldr r0, _08091760
	ands r0, r1
	strh r0, [r7, 0x2]
_08091756:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091760: .4byte 0x0000fff7
	thumb_func_end sub_80915F4

	thumb_func_start sub_8091764
sub_8091764:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x55
	bls _08091776
	cmp r0, 0x66
	bhi _08091776
	movs r0, 0x1
	b _08091778
_08091776:
	movs r0, 0
_08091778:
	pop {r1}
	bx r1
	thumb_func_end sub_8091764

	thumb_func_start sub_809177C
sub_809177C:
	push {r4,lr}
	movs r4, 0
_08091780:
	lsls r1, r4, 2
	ldr r0, _080917A4
	ldr r0, [r0]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080917A8
	ldrb r0, [r2, 0x2]
	bl sub_8091764
	lsls r0, 24
	cmp r0, 0
	beq _080917A8
	movs r0, 0x1
	b _080917B0
	.align 2, 0
_080917A4: .4byte gUnknown_203B460
_080917A8:
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091780
	movs r0, 0
_080917B0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809177C

	thumb_func_start sub_80917B8
sub_80917B8:
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _080917E0
	ldr r2, _080917DC
	ldr r1, [r2]
	ldrb r0, [r4, 0x2]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	ldrb r3, [r4, 0x1]
	adds r0, r3
	b _080917F0
	.align 2, 0
_080917DC: .4byte gUnknown_203B460
_080917E0:
	ldr r2, _0809180C
	ldr r1, [r2]
	ldrb r0, [r4, 0x2]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
_080917F0:
	strh r0, [r1]
	ldr r0, [r2]
	ldrb r1, [r4, 0x2]
	lsls r1, 1
	adds r0, 0x50
	adds r2, r0, r1
	ldrh r0, [r2]
	ldr r1, _08091810
	cmp r0, r1
	bls _08091806
	strh r1, [r2]
_08091806:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809180C: .4byte gUnknown_203B460
_08091810: .4byte 0x000003e7
	thumb_func_end sub_80917B8

	thumb_func_start sub_8091814
sub_8091814:
	push {lr}
	movs r3, 0
	ldr r0, _0809183C
	ldr r0, [r0]
	movs r2, 0x8C
	lsls r2, 2
	adds r1, r0, r2
	movs r2, 0x7
_08091824:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0809182C
	adds r3, 0x1
_0809182C:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _08091824
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809183C: .4byte gUnknown_203B460
	thumb_func_end sub_8091814

	thumb_func_start sub_8091840
sub_8091840:
	lsls r0, 24
	ldr r1, _08091858
	lsrs r0, 22
	movs r2, 0x8C
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	bx lr
	.align 2, 0
_08091858: .4byte gUnknown_203B460
	thumb_func_end sub_8091840

	thumb_func_start sub_809185C
sub_809185C:
	lsls r0, 24
	ldr r1, _08091870
	lsrs r0, 22
	movs r2, 0x8C
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_08091870: .4byte gUnknown_203B460
	thumb_func_end sub_809185C

	thumb_func_start sub_8091874
sub_8091874:
	push {r4-r7,lr}
	movs r2, 0
	movs r4, 0
	ldr r7, _08091884
	movs r6, 0x8C
	lsls r6, 2
	movs r3, 0
	b _080918A0
	.align 2, 0
_08091884: .4byte gUnknown_203B460
_08091888:
	cmp r2, r4
	ble _0809189A
	ldr r0, [r7]
	lsls r1, r4, 2
	adds r0, r6
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809189A:
	adds r3, 0x4
	adds r2, 0x1
	adds r4, 0x1
_080918A0:
	cmp r2, 0x7
	bgt _080918CA
	ldr r0, [r7]
	adds r0, r3
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _080918CA
	ldr r5, _080918E8
	movs r1, 0x8C
	lsls r1, 2
_080918B6:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x7
	bgt _080918CA
	ldr r0, [r5]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080918B6
_080918CA:
	cmp r2, 0x8
	bne _08091888
	cmp r4, 0x7
	bgt _080918E0
_080918D2:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091840
	adds r4, 0x1
	cmp r4, 0x7
	ble _080918D2
_080918E0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080918E8: .4byte gUnknown_203B460
	thumb_func_end sub_8091874

	thumb_func_start sub_80918EC
sub_80918EC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
_080918F8:
	adds r1, r0, 0x1
	mov r8, r1
	mov r6, r8
	cmp r1, 0x7
	bgt _08091964
	ldr r1, _08091978
	mov r9, r1
	lsls r7, r0, 2
	movs r0, 0x8C
	lsls r0, 2
	mov r10, r0
_0809190E:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r7
	add r0, r10
	ldrb r0, [r0]
	bl sub_8090D44
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	lsls r5, r6, 2
	adds r0, r5
	add r0, r10
	ldrb r0, [r0]
	bl sub_8090D44
	cmp r4, r0
	bgt _0809194C
	cmp r4, r0
	bne _0809195E
	mov r1, r9
	ldr r0, [r1]
	adds r2, r0, r7
	ldr r1, _0809197C
	adds r2, r1
	adds r0, r5
	adds r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _0809195E
_0809194C:
	mov r1, r9
	ldr r0, [r1]
	add r0, r10
	adds r2, r0, r7
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
_0809195E:
	adds r6, 0x1
	cmp r6, 0x7
	ble _0809190E
_08091964:
	mov r0, r8
	cmp r0, 0x6
	ble _080918F8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091978: .4byte gUnknown_203B460
_0809197C: .4byte 0x00000231
	thumb_func_end sub_80918EC

	thumb_func_start sub_8091980
sub_8091980:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r1, sp
	ldr r0, _080919F4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	movs r5, 0
_0809199C:
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_8091840
	adds r5, 0x1
	cmp r5, 0x7
	ble _0809199C
	mov r0, r8
	lsls r7, r0, 2
	ldr r6, _080919F8
	movs r5, 0x7
_080919B2:
	adds r0, r6, 0
	bl RandomCapped
	adds r4, r0, 0
	adds r0, r6, 0
	bl RandomCapped
	adds r2, r0, 0
	mov r1, sp
	adds r0, r1, r7
	ldr r0, [r0]
	adds r1, r4, 0
	bl sub_8091E94
	lsls r0, 24
	lsrs r0, 24
	bl sub_80919FC
	subs r5, 0x1
	cmp r5, 0
	bge _080919B2
	bl sub_80918EC
	mov r0, r8
	bl sub_8091BB4
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080919F4: .4byte gUnknown_81097E8
_080919F8: .4byte 0x0000270f
	thumb_func_end sub_8091980

	thumb_func_start sub_80919FC
sub_80919FC:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	bl sub_8090B08
	movs r3, 0
	ldr r5, _08091A34
	movs r4, 0x8C
	lsls r4, 2
_08091A14:
	ldr r1, [r5]
	lsls r2, r3, 2
	adds r0, r1, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08091A38
	movs r3, 0x8C
	lsls r3, 2
	adds r0, r1, r3
	adds r0, r2
	ldr r1, [sp]
	str r1, [r0]
	movs r0, 0
	b _08091A40
	.align 2, 0
_08091A34: .4byte gUnknown_203B460
_08091A38:
	adds r3, 0x1
	cmp r3, 0x7
	ble _08091A14
	movs r0, 0x1
_08091A40:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80919FC

	thumb_func_start sub_8091A48
sub_8091A48:
	push {lr}
	movs r3, 0
	ldr r0, _08091A70
	ldr r0, [r0]
	movs r2, 0x94
	lsls r2, 2
	adds r1, r0, r2
	movs r2, 0x3
_08091A58:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08091A60
	adds r3, 0x1
_08091A60:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bge _08091A58
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_08091A70: .4byte gUnknown_203B460
	thumb_func_end sub_8091A48

	thumb_func_start sub_8091A74
sub_8091A74:
	lsls r0, 24
	ldr r1, _08091A8C
	lsrs r0, 22
	movs r2, 0x94
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	bx lr
	.align 2, 0
_08091A8C: .4byte gUnknown_203B460
	thumb_func_end sub_8091A74

	thumb_func_start sub_8091A90
sub_8091A90:
	lsls r0, 24
	ldr r1, _08091AA4
	lsrs r0, 22
	movs r2, 0x94
	lsls r2, 2
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_08091AA4: .4byte gUnknown_203B460
	thumb_func_end sub_8091A90

	thumb_func_start sub_8091AA8
sub_8091AA8:
	push {r4-r7,lr}
	movs r2, 0
	movs r4, 0
	ldr r7, _08091AB8
	movs r6, 0x94
	lsls r6, 2
	movs r3, 0
	b _08091AD4
	.align 2, 0
_08091AB8: .4byte gUnknown_203B460
_08091ABC:
	cmp r2, r4
	ble _08091ACE
	ldr r0, [r7]
	lsls r1, r4, 2
	adds r0, r6
	adds r1, r0, r1
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_08091ACE:
	adds r3, 0x4
	adds r2, 0x1
	adds r4, 0x1
_08091AD4:
	cmp r2, 0x3
	bgt _08091AFE
	ldr r0, [r7]
	adds r0, r3
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _08091AFE
	ldr r5, _08091B1C
	movs r1, 0x94
	lsls r1, 2
_08091AEA:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08091AFE
	ldr r0, [r5]
	adds r0, r3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08091AEA
_08091AFE:
	cmp r2, 0x4
	bne _08091ABC
	cmp r4, 0x3
	bgt _08091B14
_08091B06:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8091A74
	adds r4, 0x1
	cmp r4, 0x3
	ble _08091B06
_08091B14:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091B1C: .4byte gUnknown_203B460
	thumb_func_end sub_8091AA8

	thumb_func_start sub_8091B20
sub_8091B20:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
_08091B2C:
	adds r1, r0, 0x1
	mov r8, r1
	mov r6, r8
	cmp r1, 0x3
	bgt _08091B98
	ldr r1, _08091BAC
	mov r9, r1
	lsls r7, r0, 2
	movs r0, 0x94
	lsls r0, 2
	mov r10, r0
_08091B42:
	mov r1, r9
	ldr r0, [r1]
	adds r0, r7
	add r0, r10
	ldrb r0, [r0]
	bl sub_8090D44
	adds r4, r0, 0
	mov r1, r9
	ldr r0, [r1]
	lsls r5, r6, 2
	adds r0, r5
	add r0, r10
	ldrb r0, [r0]
	bl sub_8090D44
	cmp r4, r0
	bgt _08091B80
	cmp r4, r0
	bne _08091B92
	mov r1, r9
	ldr r0, [r1]
	adds r2, r0, r7
	ldr r1, _08091BB0
	adds r2, r1
	adds r0, r5
	adds r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _08091B92
_08091B80:
	mov r1, r9
	ldr r0, [r1]
	add r0, r10
	adds r2, r0, r7
	ldr r3, [r2]
	adds r0, r5
	ldr r1, [r0]
	str r1, [r2]
	str r3, [r0]
_08091B92:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08091B42
_08091B98:
	mov r0, r8
	cmp r0, 0x2
	ble _08091B2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091BAC: .4byte gUnknown_203B460
_08091BB0: .4byte 0x00000251
	thumb_func_end sub_8091B20

	thumb_func_start sub_8091BB4
sub_8091BB4:
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	mov r1, sp
	ldr r0, _08091C14
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r5, 0
_08091BCA:
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_8091A74
	adds r5, 0x1
	cmp r5, 0x3
	ble _08091BCA
	lsls r7, r4, 2
	ldr r6, _08091C18
	movs r5, 0x3
_08091BDE:
	adds r0, r6, 0
	bl RandomCapped
	adds r4, r0, 0
	adds r0, r6, 0
	bl RandomCapped
	adds r2, r0, 0
	mov r1, sp
	adds r0, r1, r7
	ldr r0, [r0]
	adds r1, r4, 0
	bl sub_8091E94
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091C1C
	subs r5, 0x1
	cmp r5, 0
	bge _08091BDE
	bl sub_8091B20
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091C14: .4byte gUnknown_81097F8
_08091C18: .4byte 0x0000270f
	thumb_func_end sub_8091BB4

	thumb_func_start sub_8091C1C
sub_8091C1C:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	bl sub_8090B08
	movs r3, 0
	ldr r5, _08091C54
	movs r4, 0x94
	lsls r4, 2
_08091C34:
	ldr r1, [r5]
	lsls r2, r3, 2
	adds r0, r1, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08091C58
	movs r3, 0x94
	lsls r3, 2
	adds r0, r1, r3
	adds r0, r2
	ldr r1, [sp]
	str r1, [r0]
	movs r0, 0
	b _08091C60
	.align 2, 0
_08091C54: .4byte gUnknown_203B460
_08091C58:
	adds r3, 0x1
	cmp r3, 0x3
	ble _08091C34
	movs r0, 0x1
_08091C60:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8091C1C

	thumb_func_start sub_8091C68
sub_8091C68:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	movs r4, 0
	ldr r5, _08091D10
_08091C7C:
	lsls r0, r4, 2
	ldr r1, [r5]
	adds r1, r0
	mov r0, sp
	bl sub_8091E28
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091C7C
	ldr r6, _08091D10
	movs r5, 0x50
	movs r4, 0xEF
_08091C94:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r5, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _08091C94
	ldr r6, _08091D10
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0x7
_08091CB0:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DE0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091CB0
	ldr r6, _08091D10
	movs r5, 0x94
	lsls r5, 2
	movs r4, 0x3
_08091CCA:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DE0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091CCA
	ldr r4, _08091D10
	ldr r1, [r4]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	ldr r1, [r4]
	movs r0, 0x99
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08091D10: .4byte gUnknown_203B460
	thumb_func_end sub_8091C68

	thumb_func_start sub_8091D14
sub_8091D14:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	movs r4, 0
	ldr r5, _08091DBC
_08091D28:
	lsls r0, r4, 2
	ldr r1, [r5]
	adds r1, r0
	mov r0, sp
	bl sub_8091E00
	adds r4, 0x1
	cmp r4, 0x13
	ble _08091D28
	ldr r6, _08091DBC
	movs r5, 0x50
	movs r4, 0xEF
_08091D40:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r5, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _08091D40
	ldr r6, _08091DBC
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0x7
_08091D5C:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DC0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091D5C
	ldr r6, _08091DBC
	movs r5, 0x94
	lsls r5, 2
	movs r4, 0x3
_08091D76:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8091DC0
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08091D76
	ldr r4, _08091DBC
	ldr r1, [r4]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	ldr r1, [r4]
	movs r0, 0x99
	lsls r0, 2
	adds r1, r0
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08091DBC: .4byte gUnknown_203B460
	thumb_func_end sub_8091D14

	thumb_func_start sub_8091DC0
sub_8091DC0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x8
	bl sub_8094924
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091DC0

	thumb_func_start sub_8091DE0
sub_8091DE0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x8
	bl sub_809488C
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091DE0

	thumb_func_start sub_8091E00
sub_8091E00:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_8094924
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x8
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091E00

	thumb_func_start sub_8091E28
sub_8091E28:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_809488C
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x8
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8091E28

	thumb_func_start sub_8091E50
sub_8091E50:
	lsls r0, 24
	ldr r1, _08091E5C
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08091E5C: .4byte gUnknown_810AF50
	thumb_func_end sub_8091E50

	thumb_func_start sub_8091E60
sub_8091E60:
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r0, r1, 24
	lsrs r4, r0, 24
	cmp r3, 0x3E
	bhi _08091E8C
	ldr r2, _08091E88
	lsrs r0, 27
	lsls r1, r3, 5
	adds r0, r1
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0x7
	ands r1, r4
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	b _08091E8E
	.align 2, 0
_08091E88: .4byte gUnknown_8108F64
_08091E8C:
	movs r0, 0
_08091E8E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8091E60

	thumb_func_start sub_8091E94
sub_8091E94:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08091EE4
	add sp, r4
	mov r8, r1
	mov r10, r2
	ldr r1, _08091EE8
	subs r0, 0x1
	lsls r0, 2
	adds r0, r1
	movs r3, 0
	add r1, sp, 0x18
	mov r9, r1
	ldr r2, _08091EEC
	mov r12, r2
	add r6, sp, 0x1F8
	ldr r2, [r0]
	adds r7, r6, 0
	movs r4, 0
_08091EC0:
	ldrh r1, [r2]
	cmp r1, r12
	bls _08091EF4
	ldrh r0, [r2]
	ldr r1, _08091EF0
	adds r0, r1
	cmp r0, 0
	beq _08091EFC
	movs r5, 0
	adds r1, r7, r4
_08091ED4:
	strh r5, [r1]
	adds r1, 0x2
	adds r4, 0x2
	adds r3, 0x1
	subs r0, 0x1
	cmp r0, 0
	bne _08091ED4
	b _08091EFC
	.align 2, 0
_08091EE4: .4byte 0xfffffc10
_08091EE8: .4byte gUnknown_8108E58
_08091EEC: .4byte 0x0000752f
_08091EF0: .4byte 0xffff8ad0
_08091EF4:
	adds r0, r6, r4
	strh r1, [r0]
	adds r4, 0x2
	adds r3, 0x1
_08091EFC:
	adds r2, 0x2
	cmp r3, 0xFB
	ble _08091EC0
	movs r3, 0xB
	add r2, sp, 0x1F8
	mov r1, sp
_08091F08:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08091F08
	mov r2, r9
	add r1, sp, 0x210
	movs r3, 0xEF
_08091F1C:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, 0x2
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08091F1C
	movs r7, 0xC
	movs r6, 0
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _08091F4A
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, r8
	blt _08091F4A
	movs r7, 0
	b _08091F66
_08091F46:
	mov r8, r5
	b _08091F9C
_08091F4A:
	adds r6, 0x1
	cmp r6, 0xB
	bgt _08091F66
	lsls r0, r6, 1
	mov r2, sp
	adds r1, r2, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08091F4A
	cmp r0, r8
	blt _08091F4A
	lsls r0, r6, 24
	lsrs r7, r0, 24
_08091F66:
	movs r0, 0x46
	mov r8, r0
	cmp r7, 0xC
	beq _08091F9C
	movs r6, 0
	mov r4, r9
_08091F72:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _08091F94
	lsls r0, r6, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r7
	bne _08091F94
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, r10
	bge _08091F46
_08091F94:
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0xEF
	ble _08091F72
_08091F9C:
	mov r0, r8
	movs r3, 0xFC
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8091E94

	thumb_func_start sub_8091FB4
sub_8091FB4:
	push {r4-r6,lr}
	movs r6, 0
_08091FB8:
	ldr r0, _08092038
	lsls r1, r6, 2
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08091FE8
	movs r0, 0xF7
	ands r0, r1
	movs r5, 0
	strb r0, [r4]
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _08091FE8
	adds r0, r4, 0
	bl sub_80915D4
	bl sub_80913A0
	strb r5, [r4, 0x2]
	strb r5, [r4, 0x1]
	strb r5, [r4]
_08091FE8:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08091FB8
	bl sub_80910B4
	movs r6, 0
_08091FF4:
	movs r0, 0x58
	adds r1, r6, 0
	muls r1, r0
	ldr r0, _0809203C
	ldr r0, [r0]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092026
	adds r4, r2, 0
	adds r4, 0x28
	ldrb r0, [r4]
	cmp r0, 0
	beq _08092026
	cmp r0, 0x69
	bne _08092026
	adds r0, r4, 0
	bl sub_80915E4
	bl sub_80913A0
	movs r0, 0
	strb r0, [r4]
_08092026:
	adds r6, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r6, r0
	ble _08091FF4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092038: .4byte gUnknown_203B460
_0809203C: .4byte gUnknown_203B45C
	thumb_func_end sub_8091FB4

	.align 2, 0 @ Don't pad with nop.
