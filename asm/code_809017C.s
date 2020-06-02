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
	bl sub_808D908
	cmp r5, 0x3
	ble _080904D2
	mov r0, r8
	cmp r0, 0
	bne _080904B8
	ldr r0, _080904B4
	b _080904BA
	.align 2, 0
_080904AC: .4byte gUnknown_8115ADC
_080904B0: .4byte gUnknown_202DF98
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
	bl sub_808DACC
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
	bl sub_808DACC
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
	bl sub_808DC68
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08090638
	ldr r0, [sp, 0xE0]
	movs r1, 0x1
	bl sub_808DC68
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
	bl sub_808DC68
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	beq _08090690
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	movs r1, 0x1
	bl sub_808DC68
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

	thumb_func_start sub_8090998
sub_8090998:
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
_080909C4: .4byte gUnknown_8300500
_080909C8: .4byte gItemParametersFile
_080909CC: .4byte gItemParametersFile + 4
	thumb_func_end sub_8090998

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
	bl sub_8092334
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
	bl sub_808DC68
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r2, 0x8
	ldrsh r0, [r6, r2]
	movs r1, 0x1
	bl sub_808DC68
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

	thumb_func_start sub_8092040
sub_8092040:
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xEF
	bls _0809204E
_0809204A:
	movs r0, 0x1
	b _08092070
_0809204E:
	movs r2, 0
	ldr r0, _08092078
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0xF0
	beq _0809206E
	adds r1, r4, 0
_0809205C:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, r3
	beq _0809204A
	adds r2, 0x1
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, 0xF0
	bne _0809205C
_0809206E:
	movs r0, 0
_08092070:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08092078: .4byte gUnknown_810A35B
	thumb_func_end sub_8092040

	thumb_func_start sub_809207C
sub_809207C:
	ldr r1, _08092084
	ldr r0, _08092088
	str r0, [r1]
	bx lr
	.align 2, 0
_08092084: .4byte gUnknown_203B464
_08092088: .4byte gUnknown_2038C10
	thumb_func_end sub_809207C

	thumb_func_start sub_809208C
sub_809208C:
	ldr r0, _08092090
	bx lr
	.align 2, 0
_08092090: .4byte gUnknown_2038C10
	thumb_func_end sub_809208C

	thumb_func_start sub_8092094
sub_8092094:
	push {r4,lr}
	ldr r4, _080920B0
	ldr r0, [r4]
	ldr r1, _080920B4
	movs r2, 0xA
	bl sub_8092310
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0xC]
	strb r0, [r1, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080920B0: .4byte gUnknown_203B464
_080920B4: .4byte gUnknown_810982C
	thumb_func_end sub_8092094

	thumb_func_start sub_80920B8
sub_80920B8:
	push {lr}
	adds r2, r0, 0
	movs r1, 0
	ldr r0, _080920D4
	ldr r3, [r0]
_080920C2:
	adds r0, r3, r1
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, 0x1
	adds r1, 0x1
	cmp r1, 0x9
	ble _080920C2
	pop {r0}
	bx r0
	.align 2, 0
_080920D4: .4byte gUnknown_203B464
	thumb_func_end sub_80920B8

	thumb_func_start sub_80920D8
sub_80920D8:
	push {lr}
	ldr r1, _080920E8
	ldr r1, [r1]
	movs r2, 0xA
	bl sub_80922B4
	pop {r0}
	bx r0
	.align 2, 0
_080920E8: .4byte gUnknown_203B464
	thumb_func_end sub_80920D8

	thumb_func_start sub_80920EC
sub_80920EC:
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r4, _0809210C
_080920F4:
	ldr r0, [r4]
	adds r0, r2
	ldrb r1, [r3]
	strb r1, [r0]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x9
	ble _080920F4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809210C: .4byte gUnknown_203B464
	thumb_func_end sub_80920EC

	thumb_func_start sub_8092110
sub_8092110:
	ldr r0, _08092118
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bx lr
	.align 2, 0
_08092118: .4byte gUnknown_203B464
	thumb_func_end sub_8092110

	thumb_func_start sub_809211C
sub_809211C:
	push {lr}
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _08092144
	ldr r1, _0809213C
	lsls r0, 2
	adds r0, r1
	ldr r1, _08092140
	ldr r1, [r1]
	ldr r0, [r0]
	ldr r1, [r1, 0xC]
	subs r0, r1
	b _08092146
	.align 2, 0
_0809213C: .4byte gUnknown_8109810
_08092140: .4byte gUnknown_203B464
_08092144:
	movs r0, 0
_08092146:
	pop {r1}
	bx r1
	thumb_func_end sub_809211C

	thumb_func_start sub_809214C
sub_809214C:
	ldr r1, _08092154
	ldr r1, [r1]
	str r0, [r1, 0xC]
	bx lr
	.align 2, 0
_08092154: .4byte gUnknown_203B464
	thumb_func_end sub_809214C

	thumb_func_start sub_8092158
sub_8092158:
	push {lr}
	ldr r1, _08092170
	ldr r2, [r1]
	ldr r1, [r2, 0xC]
	adds r1, r0
	str r1, [r2, 0xC]
	ldr r0, _08092174
	cmp r1, r0
	ble _0809216C
	str r0, [r2, 0xC]
_0809216C:
	pop {r0}
	bx r0
	.align 2, 0
_08092170: .4byte gUnknown_203B464
_08092174: .4byte 0x05f5e0ff
	thumb_func_end sub_8092158

	thumb_func_start sub_8092178
sub_8092178:
	push {lr}
	movs r1, 0
	ldr r0, _08092190
	ldr r0, [r0]
	ldr r3, [r0, 0xC]
	ldr r2, _08092194
_08092184:
	ldr r0, [r2]
	cmp r3, r0
	bge _08092198
	lsls r0, r1, 24
	lsrs r0, 24
	b _080921A2
	.align 2, 0
_08092190: .4byte gUnknown_203B464
_08092194: .4byte gUnknown_8109810
_08092198:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0x6
	ble _08092184
	movs r0, 0x6
_080921A2:
	pop {r1}
	bx r1
	thumb_func_end sub_8092178

	thumb_func_start sub_80921A8
sub_80921A8:
	lsls r0, 24
	ldr r1, _080921B4
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080921B4: .4byte gUnknown_810B44C
	thumb_func_end sub_80921A8

	thumb_func_start sub_80921B8
sub_80921B8:
	ldr r0, _080921C0
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	bx lr
	.align 2, 0
_080921C0: .4byte gUnknown_203B464
	thumb_func_end sub_80921B8

	thumb_func_start sub_80921C4
sub_80921C4:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	add r6, sp, 0x10
	movs r0, 0xFF
	strb r0, [r6]
	mov r5, sp
	adds r5, 0x11
	movs r0, 0
	strb r0, [r5]
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	ldr r4, _08092228
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x58
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
	movs r0, 0
	bl sub_80023E4
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	adds r1, r5, 0
	cmp r0, 0
	beq _08092210
	adds r1, r6, 0
_08092210:
	mov r0, sp
	movs r2, 0x1
	bl sub_809488C
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08092228: .4byte gUnknown_203B464
	thumb_func_end sub_80921C4

	thumb_func_start sub_809222C
sub_809222C:
	push {r4,r5,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	ldr r5, _0809227C
	ldr r1, [r5]
	mov r0, sp
	movs r2, 0x58
	bl sub_8094924
	ldr r1, [r5]
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
	add r4, sp, 0x10
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8094924
	ldr r2, [r5]
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	strb r0, [r2, 0x10]
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809227C: .4byte gUnknown_203B464
	thumb_func_end sub_809222C

	thumb_func_start sub_8092280
sub_8092280:
	lsls r0, 24
	lsrs r0, 24
	bx lr
	thumb_func_end sub_8092280

	thumb_func_start sub_8092288
sub_8092288:
	lsls r0, 24
	lsrs r0, 24
	bx lr
	thumb_func_end sub_8092288

	thumb_func_start sub_8092290
sub_8092290:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	b _080922A4
_08092298:
	ldrb r0, [r4]
	adds r4, 0x1
	bl sub_8092288
	strb r0, [r5]
	adds r5, 0x1
_080922A4:
	ldrb r0, [r4]
	cmp r0, 0
	bne _08092298
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8092290

	thumb_func_start sub_80922B4
sub_80922B4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	b _080922CA
_080922BE:
	ldrb r0, [r4]
	adds r4, 0x1
	bl sub_8092288
	strb r0, [r6]
	adds r6, 0x1
_080922CA:
	adds r0, r5, 0
	subs r5, 0x1
	cmp r0, 0
	ble _080922D8
	ldrb r0, [r4]
	cmp r0, 0
	bne _080922BE
_080922D8:
	movs r0, 0
	strb r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80922B4

	thumb_func_start sub_80922E4
sub_80922E4:
	ldr r1, _080922F0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080922F0: .4byte gUnknown_810983C
	thumb_func_end sub_80922E4

	thumb_func_start sub_80922F4
sub_80922F4:
	push {lr}
	adds r2, r0, 0
	b _08092300
_080922FA:
	strb r0, [r2]
	adds r1, 0x1
	adds r2, 0x1
_08092300:
	ldrb r0, [r1]
	cmp r0, 0
	bne _080922FA
	movs r0, 0
	strb r0, [r2]
	pop {r0}
	bx r0
	thumb_func_end sub_80922F4

	thumb_func_start sub_8092310
sub_8092310:
	push {r4,lr}
	adds r4, r0, 0
	b _0809231C
_08092316:
	strb r0, [r4]
	adds r4, 0x1
	adds r1, 0x1
_0809231C:
	adds r0, r2, 0
	subs r2, 0x1
	cmp r0, 0
	ble _0809232E
	ldrb r0, [r1]
	adds r3, r0, 0
	cmp r3, 0
	bne _08092316
	strb r3, [r4]
_0809232E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8092310

	thumb_func_start sub_8092334
sub_8092334:
	lsls r0, 24
	ldr r1, _08092340
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08092340: .4byte gUnknown_810AD4C
	thumb_func_end sub_8092334

	thumb_func_start sub_8092344
sub_8092344:
	lsls r0, 24
	ldr r1, _08092350
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08092350: .4byte gUnknown_810AE24
	thumb_func_end sub_8092344

	thumb_func_start sub_8092354
sub_8092354:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08092360
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08092360: .4byte gUnknown_810AC7C
	thumb_func_end sub_8092354

	thumb_func_start sub_8092364
sub_8092364:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08092370
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08092370: .4byte gUnknown_810AC6A
	thumb_func_end sub_8092364

	thumb_func_start sub_8092374
sub_8092374:
	push {lr}
	lsls r1, 24
	ldr r2, _0809238C
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0x50
	bl strncpy
	pop {r0}
	bx r0
	.align 2, 0
_0809238C: .4byte gUnknown_810B4C8
	thumb_func_end sub_8092374

	thumb_func_start sub_8092390
sub_8092390:
	lsls r0, 24
	ldr r1, _0809239C
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0809239C: .4byte gUnknown_810B988
	thumb_func_end sub_8092390

	thumb_func_start sub_80923A0
sub_80923A0:
	ldr r1, _080923A8
	ldr r0, _080923AC
	str r0, [r1]
	bx lr
	.align 2, 0
_080923A8: .4byte gUnknown_203B468
_080923AC: .4byte gUnknown_2038C28
	thumb_func_end sub_80923A0

	thumb_func_start sub_80923B0
sub_80923B0:
	ldr r0, _080923B4
	bx lr
	.align 2, 0
_080923B4: .4byte gUnknown_2038C28
	thumb_func_end sub_80923B0

	thumb_func_start sub_80923B8
sub_80923B8:
	push {lr}
	movs r1, 0
	ldr r3, _080923D0
	movs r2, 0
_080923C0:
	ldr r0, [r3]
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, 0x39
	ble _080923C0
	pop {r0}
	bx r0
	.align 2, 0
_080923D0: .4byte gUnknown_203B468
	thumb_func_end sub_80923B8

	thumb_func_start sub_80923D4
sub_80923D4:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	movs r1, 0
	ldr r2, _080923F0
_080923DE:
	movs r5, 0
	ldrsh r0, [r2, r5]
	adds r3, r0
	cmp r3, r4
	ble _080923F4
	lsls r0, r1, 24
	lsrs r0, 24
	b _080923FE
	.align 2, 0
_080923F0: .4byte gUnknown_810AA90
_080923F4:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x39
	ble _080923DE
	movs r0, 0
_080923FE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80923D4

	thumb_func_start sub_8092404
sub_8092404:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 24
	lsrs r7, r3, 24
	movs r6, 0
	movs r4, 0
	mov r5, r10
_08092426:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, _08092494
	ldr r0, [r0]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092472
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	beq _08092448
	mov r0, r8
	cmp r0, 0
	beq _08092472
_08092448:
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _08092452
	movs r1, 0x1
_08092452:
	cmp r1, 0
	beq _0809245A
	cmp r7, 0
	beq _08092472
_0809245A:
	adds r0, r4, 0
	bl sub_80923D4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r9
	bne _08092472
	cmp r6, 0xF
	bgt _08092472
	strh r4, [r5]
	adds r5, 0x2
	adds r6, 0x1
_08092472:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08092426
	lsls r0, r6, 1
	add r0, r10
	ldr r2, _08092498
	adds r1, r2, 0
	strh r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092494: .4byte gUnknown_203B45C
_08092498: .4byte 0x0000ffff
	thumb_func_end sub_8092404

	thumb_func_start sub_809249C
sub_809249C:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r0, _080924F8
	ldr r0, [r0]
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809251A
	movs r5, 0
_080924B4:
	ldr r2, _080924FC
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092502
	adds r0, r5, 0
	bl sub_80923D4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r6
	bne _08092502
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080924E2
	movs r1, 0x1
_080924E2:
	cmp r1, 0
	bne _080924F2
	ldrb r1, [r4, 0x2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	cmp r0, 0
	beq _08092500
_080924F2:
	movs r7, 0
	b _08092502
	.align 2, 0
_080924F8: .4byte gUnknown_203B468
_080924FC: .4byte gUnknown_203B45C
_08092500:
	strh r0, [r4]
_08092502:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _080924B4
	cmp r7, 0
	beq _0809251A
	ldr r0, _08092520
	ldr r0, [r0]
	adds r0, r6
	movs r1, 0
	strb r1, [r0]
_0809251A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092520: .4byte gUnknown_203B468
	thumb_func_end sub_809249C

	thumb_func_start sub_8092524
sub_8092524:
	lsls r0, 24
	ldr r1, _08092530
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08092530: .4byte gUnknown_81139D0
	thumb_func_end sub_8092524

	thumb_func_start sub_8092534
sub_8092534:
	lsls r0, 24
	ldr r1, _08092540
	lsrs r0, 21
	adds r0, r1
	ldrb r0, [r0, 0x2]
	bx lr
	.align 2, 0
_08092540: .4byte gUnknown_810AA90
	thumb_func_end sub_8092534

	thumb_func_start sub_8092544
sub_8092544:
	lsls r0, 24
	ldr r1, _08092554
	lsrs r0, 21
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08092554: .4byte gUnknown_810AA90
	thumb_func_end sub_8092544

	thumb_func_start sub_8092558
sub_8092558:
	push {lr}
	lsls r2, r1, 24
	ldr r1, _08092570
	ldr r3, _08092574
	lsrs r2, 22
	adds r2, r3
	ldr r2, [r2]
	bl sub_800D158
	pop {r0}
	bx r0
	.align 2, 0
_08092570: .4byte gUnknown_81098A4
_08092574: .4byte gUnknown_81139D0
	thumb_func_end sub_8092558

	thumb_func_start sub_8092578
sub_8092578:
	push {r4,r5,lr}
	sub sp, 0x18
	adds r5, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	cmp r2, 0
	beq _080925C0
	ldr r0, _080925B4
	lsls r1, r4, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	add r1, sp, 0x4
	movs r2, 0x1
	bl sub_8090FEC
	ldr r1, _080925B8
	ldr r2, _080925BC
	lsls r0, r4, 2
	adds r0, r2
	ldr r2, [r0]
	add r0, sp, 0x4
	str r0, [sp]
	adds r0, r5, 0
	movs r3, 0x60
	bl sub_800D158
	b _080925CE
	.align 2, 0
_080925B4: .4byte gUnknown_810AA90
_080925B8: .4byte gUnknown_81098AC
_080925BC: .4byte gUnknown_81139D0
_080925C0:
	ldr r0, _080925D8
	lsls r1, r4, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl strcpy
_080925CE:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080925D8: .4byte gUnknown_81139D0
	thumb_func_end sub_8092578

	thumb_func_start sub_80925DC
sub_80925DC:
	lsls r0, 24
	ldr r1, _080925E8
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080925E8: .4byte gUnknown_8113E30
	thumb_func_end sub_80925DC

	thumb_func_start sub_80925EC
sub_80925EC:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080925FC
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_080925FC: .4byte gUnknown_203B468
	thumb_func_end sub_80925EC

	thumb_func_start sub_8092600
sub_8092600:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08092610
	ldr r1, [r1]
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_08092610: .4byte gUnknown_203B468
	thumb_func_end sub_8092600

	thumb_func_start sub_8092614
sub_8092614:
	push {lr}
	movs r1, 0x1
	ldr r0, _08092628
	ldr r2, [r0]
_0809261C:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809262C
	movs r0, 0
	b _08092634
	.align 2, 0
_08092628: .4byte gUnknown_203B468
_0809262C:
	adds r1, 0x1
	cmp r1, 0x39
	ble _0809261C
	movs r0, 0x1
_08092634:
	pop {r1}
	bx r1
	thumb_func_end sub_8092614

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
_080926DC: .4byte gUnknown_203B468
_080926E0: .4byte gUnknown_810AA90
_080926E4: .4byte gUnknown_203B45C
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
_08092780: .4byte gUnknown_203B468
_08092784: .4byte gUnknown_810AA90
_08092788: .4byte gUnknown_203B45C
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

	thumb_func_start sub_80927A8
sub_80927A8:
	push {r4,r5,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	movs r4, 0
	add r5, sp, 0x10
_080927BC:
	ldr r0, _080927F0
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080927CC
	movs r0, 0x1
	negs r0, r0
_080927CC:
	str r0, [sp, 0x10]
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_809488C
	adds r4, 0x1
	cmp r4, 0x39
	ble _080927BC
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080927F0: .4byte gUnknown_203B468
	thumb_func_end sub_80927A8

	thumb_func_start sub_80927F4
sub_80927F4:
	push {r4-r7,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	movs r4, 0
	add r7, sp, 0x10
	movs r6, 0x1
	ldr r5, _08092828
_0809280C:
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_8094924
	ldr r1, [sp, 0x10]
	ands r1, r6
	cmp r1, 0
	beq _0809282C
	ldr r0, [r5]
	adds r0, r4
	strb r6, [r0]
	b _08092832
	.align 2, 0
_08092828: .4byte gUnknown_203B468
_0809282C:
	ldr r0, [r5]
	adds r0, r4
	strb r1, [r0]
_08092832:
	adds r4, 0x1
	cmp r4, 0x39
	ble _0809280C
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80927F4

	thumb_func_start LoadWazaParameters
LoadWazaParameters:
	push {lr}
	ldr r0, _08092868
	ldr r1, _0809286C
	bl OpenFileAndGetFileDataPtr
	ldr r1, _08092870
	str r0, [r1]
	ldr r1, _08092874
	ldr r2, [r0, 0x4]
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _08092878
	ldr r0, [r2, 0x4]
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08092868: .4byte gUnknown_81098D0
_0809286C: .4byte gUnknown_8300500
_08092870: .4byte gWazaParametersFile
_08092874: .4byte gUnknown_2038C68
_08092878: .4byte gUnknown_2038C6C
	thumb_func_end LoadWazaParameters

	thumb_func_start sub_809287C
sub_809287C:
	push {lr}
	adds r2, r0, 0
	ldrb r1, [r2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08092894
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08092898
_08092894:
	movs r0, 0x32
	b _0809289A
_08092898:
	movs r0, 0x34
_0809289A:
	pop {r1}
	bx r1
	thumb_func_end sub_809287C

	thumb_func_start sub_80928A0
sub_80928A0:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	mov r0, sp
	bl sub_8093F10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_80928C0
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80928A0

	thumb_func_start sub_80928C0
sub_80928C0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r7, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl sub_809287C
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r5, 0
	bne _080928DE
	ldr r5, _080928F0
_080928DE:
	ldrb r1, [r4, 0x5]
	cmp r1, 0
	beq _080928F8
	ldr r1, _080928F4
	ldrb r2, [r4, 0x5]
	add r0, sp, 0x14
	bl sub_800D158
	b _080928FC
	.align 2, 0
_080928F0: .4byte gUnknown_81098C4
_080928F4: .4byte gUnknown_81098DC
_080928F8:
	add r0, sp, 0x14
	strb r1, [r0]
_080928FC:
	ldrb r0, [r5, 0x8]
	cmp r0, 0
	beq _08092904
	movs r6, 0x2
_08092904:
	ldrb r0, [r5, 0x9]
	cmp r0, 0
	beq _08092918
	ldrh r0, [r4, 0x2]
	bl sub_809422C
	lsls r0, 24
	cmp r0, 0
	beq _08092918
	movs r6, 0x2
_08092918:
	ldr r0, [r5]
	cmp r0, 0x4
	bls _08092920
	b _08092A6A
_08092920:
	lsls r0, 2
	ldr r1, _0809292C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809292C: .4byte _08092930
	.align 2, 0
_08092930:
	.4byte _08092944
	.4byte _0809296C
	.4byte _08092998
	.4byte _080929C4
	.4byte _08092A20
_08092944:
	ldr r1, _08092964
	ldrh r2, [r4, 0x2]
	ldr r0, _08092968
	ldr r3, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldr r3, [r0]
	add r0, sp, 0x14
	str r0, [sp]
	adds r0, r7, 0
	adds r2, r6, 0
	bl sub_800D158
	b _08092A6A
	.align 2, 0
_08092964: .4byte gUnknown_81098E0
_08092968: .4byte gUnknown_2038C68
_0809296C:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r1, _0809298C
	mov r8, r1
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	ldr r1, _08092990
	mov r12, r1
	cmp r0, 0
	beq _080929E2
	ldr r0, _08092994
	b _080929E0
	.align 2, 0
_0809298C: .4byte gUnknown_81098EC
_08092990: .4byte gUnknown_810990C
_08092994: .4byte gUnknown_8109908
_08092998:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r0, _080929B8
	mov r8, r0
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	ldr r1, _080929BC
	mov r12, r1
	cmp r0, 0
	beq _080929E2
	ldr r0, _080929C0
	b _080929E0
	.align 2, 0
_080929B8: .4byte gUnknown_8109910
_080929BC: .4byte gUnknown_810990C
_080929C0: .4byte gUnknown_8109908
_080929C4:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r0, _08092A10
	mov r8, r0
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	ldr r1, _08092A14
	mov r12, r1
	cmp r0, 0
	beq _080929E2
	ldr r0, _08092A18
_080929E0:
	mov r12, r0
_080929E2:
	ldrh r1, [r4, 0x2]
	ldr r0, _08092A1C
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [sp]
	add r1, sp, 0x14
	str r1, [sp, 0x4]
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0xC]
	str r3, [sp, 0x10]
	adds r0, r7, 0
	mov r1, r8
	adds r2, r6, 0
	mov r3, r12
	bl sub_800D158
	b _08092A6A
	.align 2, 0
_08092A10: .4byte gUnknown_81098EC
_08092A14: .4byte gUnknown_810990C
_08092A18: .4byte gUnknown_8109928
_08092A1C: .4byte gUnknown_2038C68
_08092A20:
	adds r0, r4, 0
	bl sub_8092BF4
	adds r3, r0, 0
	ldr r0, _08092A78
	mov r8, r0
	ldrb r1, [r4]
	movs r0, 0x4
	ands r0, r1
	ldr r1, _08092A7C
	mov r12, r1
	cmp r0, 0
	beq _08092A3E
	ldr r0, _08092A80
	mov r12, r0
_08092A3E:
	ldrh r1, [r4, 0x2]
	ldr r0, _08092A84
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [sp]
	add r1, sp, 0x14
	str r1, [sp, 0x4]
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x4]
	str r0, [sp, 0xC]
	str r3, [sp, 0x10]
	adds r0, r7, 0
	mov r1, r8
	adds r2, r6, 0
	mov r3, r12
	bl sub_800D158
_08092A6A:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092A78: .4byte gUnknown_8109910
_08092A7C: .4byte gUnknown_810990C
_08092A80: .4byte gUnknown_8109928
_08092A84: .4byte gUnknown_2038C68
	thumb_func_end sub_80928C0

	thumb_func_start sub_8092A88
sub_8092A88:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r2, 0
	movs r0, 0x5
	strb r0, [r4]
	strb r2, [r4, 0x1]
	movs r5, 0
	strh r1, [r4, 0x2]
	adds r0, r4, 0
	bl sub_8092BF4
	strb r0, [r4, 0x4]
	strb r5, [r4, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8092A88

	thumb_func_start sub_8092AA8
sub_8092AA8:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r2, r1, 16
	cmp r2, 0
	bne _08092AB8
	strb r2, [r5]
	b _08092ACE
_08092AB8:
	movs r1, 0
	movs r0, 0x5
	strb r0, [r5]
	strb r1, [r5, 0x1]
	movs r4, 0
	strh r2, [r5, 0x2]
	adds r0, r5, 0
	bl sub_8092BF4
	strb r0, [r5, 0x4]
	strb r4, [r5, 0x5]
_08092ACE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8092AA8

	thumb_func_start sub_8092AD4
sub_8092AD4:
	movs r2, 0x5
	strb r2, [r0]
	movs r2, 0
	strh r1, [r0, 0x2]
	strb r2, [r0, 0x4]
	bx lr
	thumb_func_end sub_8092AD4

	thumb_func_start sub_8092AE0
sub_8092AE0:
	ldrh r2, [r0, 0x2]
	ldr r0, _08092AFC
	ldr r3, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	lsls r1, 1
	adds r0, 0x8
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08092AFC: .4byte gUnknown_2038C68
	thumb_func_end sub_8092AE0

	thumb_func_start sub_8092B00
sub_8092B00:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092B14
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x6]
	bx lr
	.align 2, 0
_08092B14: .4byte gUnknown_2038C68
	thumb_func_end sub_8092B00

	thumb_func_start sub_8092B18
sub_8092B18:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _08092B40
	cmp r1, r0
	beq _08092B48
	cmp r1, 0
	beq _08092B48
	movs r0, 0xD2
	lsls r0, 1
	cmp r2, r0
	beq _08092B48
	ldr r0, _08092B44
	ldr r1, [r0]
	lsls r0, r2, 3
	adds r0, r1
	ldr r0, [r0]
	b _08092B4A
	.align 2, 0
_08092B40: .4byte 0x000001a5
_08092B44: .4byte gUnknown_2038C6C
_08092B48:
	ldr r0, _08092B50
_08092B4A:
	pop {r1}
	bx r1
	.align 2, 0
_08092B50: .4byte gUnknown_810992B
	thumb_func_end sub_8092B18

	thumb_func_start sub_8092B54
sub_8092B54:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _08092B7C
	cmp r1, r0
	beq _08092B84
	cmp r1, 0
	beq _08092B84
	movs r0, 0xD2
	lsls r0, 1
	cmp r2, r0
	beq _08092B84
	ldr r0, _08092B80
	ldr r1, [r0]
	lsls r0, r2, 3
	adds r0, r1
	ldr r0, [r0, 0x4]
	b _08092B86
	.align 2, 0
_08092B7C: .4byte 0x000001a5
_08092B80: .4byte gUnknown_2038C6C
_08092B84:
	ldr r0, _08092B8C
_08092B86:
	pop {r1}
	bx r1
	.align 2, 0
_08092B8C: .4byte gUnknown_810992B
	thumb_func_end sub_8092B54

	thumb_func_start sub_8092B90
sub_8092B90:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092BA4
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xD]
	bx lr
	.align 2, 0
_08092BA4: .4byte gUnknown_2038C68
	thumb_func_end sub_8092B90

	thumb_func_start sub_8092BA8
sub_8092BA8:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092BBC
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x11]
	bx lr
	.align 2, 0
_08092BBC: .4byte gUnknown_2038C68
	thumb_func_end sub_8092BA8

	thumb_func_start sub_8092BC0
sub_8092BC0:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092BD4
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08092BD4: .4byte gUnknown_2038C68
	thumb_func_end sub_8092BC0

	thumb_func_start sub_8092BD8
sub_8092BD8:
	ldrh r2, [r0, 0x2]
	ldr r0, _08092BF0
	ldr r3, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	adds r0, 0xE
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08092BF0: .4byte gUnknown_2038C68
	thumb_func_end sub_8092BD8

	thumb_func_start sub_8092BF4
sub_8092BF4:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C08
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	bx lr
	.align 2, 0
_08092C08: .4byte gUnknown_2038C68
	thumb_func_end sub_8092BF4

	thumb_func_start sub_8092C0C
sub_8092C0C:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C20
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x12]
	bx lr
	.align 2, 0
_08092C20: .4byte gUnknown_2038C68
	thumb_func_end sub_8092C0C

	thumb_func_start sub_8092C24
sub_8092C24:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C38
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x13]
	bx lr
	.align 2, 0
_08092C38: .4byte gUnknown_2038C68
	thumb_func_end sub_8092C24

	thumb_func_start sub_8092C3C
sub_8092C3C:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C50
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x17]
	bx lr
	.align 2, 0
_08092C50: .4byte gUnknown_2038C68
	thumb_func_end sub_8092C3C

	thumb_func_start sub_8092C54
sub_8092C54:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C68
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x18]
	bx lr
	.align 2, 0
_08092C68: .4byte gUnknown_2038C68
	thumb_func_end sub_8092C54

	thumb_func_start sub_8092C6C
sub_8092C6C:
	ldrh r1, [r0, 0x2]
	ldr r0, _08092C80
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x19]
	bx lr
	.align 2, 0
_08092C80: .4byte gUnknown_2038C68
	thumb_func_end sub_8092C6C

	thumb_func_start sub_8092C84
sub_8092C84:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl sub_8092A88
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0
	bl sub_80928C0
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8092C84

	thumb_func_start sub_8092CA8
sub_8092CA8:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092CBC
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1, 0x20]
	bx lr
	.align 2, 0
_08092CBC: .4byte gUnknown_2038C68
	thumb_func_end sub_8092CA8

	thumb_func_start sub_8092CC0
sub_8092CC0:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092CD4
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x14]
	bx lr
	.align 2, 0
_08092CD4: .4byte gUnknown_2038C68
	thumb_func_end sub_8092CC0

	thumb_func_start sub_8092CD8
sub_8092CD8:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092CEC
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x15]
	bx lr
	.align 2, 0
_08092CEC: .4byte gUnknown_2038C68
	thumb_func_end sub_8092CD8

	thumb_func_start sub_8092CF0
sub_8092CF0:
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08092D04
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x16]
	bx lr
	.align 2, 0
_08092D04: .4byte gUnknown_2038C68
	thumb_func_end sub_8092CF0

	thumb_func_start sub_8092D08
sub_8092D08:
	push {lr}
	adds r2, r0, 0
	ldrh r1, [r2, 0x2]
	cmp r1, 0xD9
	beq _08092D4C
	movs r0, 0x8E
	lsls r0, 1
	cmp r1, r0
	beq _08092D4C
	cmp r1, 0x53
	beq _08092D4C
	cmp r1, 0x22
	beq _08092D4C
	cmp r1, 0x54
	beq _08092D4C
	cmp r1, 0xAB
	beq _08092D4C
	ldr r0, _08092D48
	cmp r1, r0
	beq _08092D4C
	cmp r1, 0x1B
	beq _08092D4C
	cmp r1, 0xF1
	beq _08092D4C
	cmp r1, 0x19
	beq _08092D4C
	ldrh r0, [r2, 0x2]
	cmp r0, 0x1A
	beq _08092D4C
	movs r0, 0
	b _08092D4E
	.align 2, 0
_08092D48: .4byte 0x00000125
_08092D4C:
	movs r0, 0x1
_08092D4E:
	pop {r1}
	bx r1
	thumb_func_end sub_8092D08

	thumb_func_start sub_8092D54
sub_8092D54:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r0, r1, 0
	ldr r5, _08092D78
	ldr r4, _08092D7C
	bl sub_8092C6C
	lsls r0, 2
	adds r0, r4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_800D158
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092D78: .4byte gUnknown_810992C
_08092D7C: .4byte gUnknown_810CC0C
	thumb_func_end sub_8092D54

	thumb_func_start sub_8092D80
sub_8092D80:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092D8A:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x4
	beq _08092DB0
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092DB0
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092DAA
	adds r0, r3, 0
	b _08092DB2
_08092DAA:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08092D8A
_08092DB0:
	movs r0, 0
_08092DB2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092D80

	thumb_func_start sub_8092DB8
sub_8092DB8:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r6, 0x1
_08092DC0:
	subs r1, 0x1
	cmp r1, 0
	bge _08092DF0
	movs r2, 0x3
	ldrb r1, [r4, 0x18]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08092DD6
	movs r1, 0x3
	b _08092DEC
_08092DD6:
	subs r2, 0x1
	cmp r2, 0
	blt _08092E12
	lsls r0, r2, 3
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08092DD6
	adds r1, r2, 0
_08092DEC:
	cmp r2, 0
	blt _08092E12
_08092DF0:
	lsls r0, r1, 3
	adds r0, r4
	ldrb r2, [r0]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E12
	lsrs r0, r2, 1
	ands r0, r3
	cmp r0, 0
	bne _08092E0C
	adds r0, r1, 0
	b _08092E14
_08092E0C:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08092DC0
_08092E12:
	movs r0, 0
_08092E14:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092DB8

	thumb_func_start sub_8092E1C
sub_8092E1C:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092E26:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	beq _08092E4C
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E4C
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092E46
	adds r0, r3, 0
	b _08092E4E
_08092E46:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E26
_08092E4C:
	movs r0, 0
_08092E4E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E1C

	thumb_func_start sub_8092E54
sub_8092E54:
	push {r4,r5,lr}
	adds r3, r1, 0
	movs r5, 0
	lsls r1, r3, 3
	adds r1, r0
_08092E5E:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	beq _08092E84
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092E84
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092E7E
	adds r0, r3, 0
	b _08092E86
_08092E7E:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E5E
_08092E84:
	movs r0, 0
_08092E86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E54

	thumb_func_start sub_8092E8C
sub_8092E8C:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	lsls r0, r1, 3
	adds r3, r0, r6
_08092E96:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _08092EC6
	movs r3, 0x7
	movs r4, 0x1
	adds r2, r6, 0
	adds r2, 0x38
_08092EA6:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08092EBC
	lsrs r0, r1, 1
	ands r0, r4
	cmp r0, 0
	bne _08092EBC
	adds r0, r3, 0
	b _08092EE6
_08092EBC:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bgt _08092EA6
	b _08092EE4
_08092EC6:
	ldrb r2, [r3]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092EE4
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092EDE
	adds r0, r1, 0
	b _08092EE6
_08092EDE:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092E96
_08092EE4:
	movs r0, 0
_08092EE6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092E8C

	thumb_func_start sub_8092EEC
sub_8092EEC:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	lsls r0, r1, 3
	adds r3, r0, r6
_08092EF6:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _08092F26
	movs r3, 0x7
	movs r4, 0x1
	adds r2, r6, 0
	adds r2, 0x38
_08092F06:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08092F1C
	lsrs r0, r1, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F1C
	adds r0, r3, 0
	b _08092F46
_08092F1C:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bgt _08092F06
	b _08092F44
_08092F26:
	ldrb r2, [r3]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092F44
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F3E
	adds r0, r1, 0
	b _08092F46
_08092F3E:
	adds r5, 0x1
	cmp r5, 0x7
	ble _08092EF6
_08092F44:
	movs r0, 0
_08092F46:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8092EEC

	thumb_func_start sub_8092F4C
sub_8092F4C:
	push {r4,lr}
	adds r2, r0, 0
	cmp r1, 0
	ble _08092F78
	movs r4, 0x1
	lsls r0, r1, 3
	adds r3, r0, r2
_08092F5A:
	ldrb r2, [r3]
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08092F78
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	bne _08092F70
	adds r0, r1, 0
	b _08092F7A
_08092F70:
	subs r3, 0x8
	subs r1, 0x1
	cmp r1, 0
	bgt _08092F5A
_08092F78:
	movs r0, 0
_08092F7A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8092F4C

	thumb_func_start sub_8092F80
sub_8092F80:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093784
	mov r0, sp
	bl sub_8093744
	adds r3, r0, 0
	cmp r3, 0x2
	bhi _08092FCC
	lsls r1, r3, 5
	adds r0, r3, 0x1
	lsls r0, 5
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x3
_08092FBA:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _08092FBA
_08092FCC:
	adds r0, r7, 0
	mov r1, sp
	bl sub_80937E0
	movs r3, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r1, r7, 0
_08092FDC:
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08092FF0
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1]
	mov r8, r3
	b _08092FF8
_08092FF0:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08092FDC
_08092FF8:
	mov r0, r8
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8092F80

	thumb_func_start sub_8093008
sub_8093008:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0809307C
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093974
	mov r0, sp
	bl sub_80938F4
	adds r3, r0, 0
	cmp r3, 0x6
	bhi _08093056
	lsls r1, r3, 6
	adds r0, r3, 0x1
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_08093044:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _08093044
_08093056:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093A2C
	movs r3, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r1, r7, 0
_08093066:
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08093080
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1]
	mov r8, r3
	b _08093088
	.align 2, 0
_0809307C: .4byte 0xfffffe00
_08093080:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093066
_08093088:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093008

	thumb_func_start sub_809309C
sub_809309C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08093110
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_80939D0
	mov r0, sp
	bl sub_8093934
	adds r3, r0, 0
	cmp r3, 0x6
	bhi _080930EA
	lsls r1, r3, 6
	adds r0, r3, 0x1
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_080930D8:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _080930D8
_080930EA:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093B40
	movs r3, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r1, r7, 0
_080930FA:
	ldrb r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08093114
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1]
	mov r8, r3
	b _0809311C
	.align 2, 0
_08093110: .4byte 0xfffffe00
_08093114:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _080930FA
_0809311C:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809309C

	thumb_func_start sub_8093130
sub_8093130:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093784
	mov r0, sp
	bl sub_8093744
	adds r1, r0, 0
	subs r0, r1, 0x1
	cmp r0, 0x2
	bhi _0809317C
	lsls r1, 5
	lsls r0, 5
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x3
_0809316A:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _0809316A
_0809317C:
	adds r0, r7, 0
	mov r1, sp
	bl sub_80937E0
	movs r1, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r2, r7, 0
_0809318C:
	ldrb r3, [r2]
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _080931A0
	adds r0, r4, 0
	ands r0, r3
	strb r0, [r2]
	mov r8, r1
	b _080931A8
_080931A0:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x3
	ble _0809318C
_080931A8:
	mov r0, r8
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093130

	thumb_func_start sub_80931B8
sub_80931B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0809322C
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093974
	mov r0, sp
	bl sub_80938F4
	adds r1, r0, 0
	subs r0, r1, 0x1
	cmp r0, 0x6
	bhi _08093206
	lsls r1, 6
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_080931F4:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _080931F4
_08093206:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093A2C
	movs r1, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r2, r7, 0
_08093216:
	ldrb r3, [r2]
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _08093230
	adds r0, r4, 0
	ands r0, r3
	strb r0, [r2]
	mov r8, r1
	b _08093238
	.align 2, 0
_0809322C: .4byte 0xfffffe00
_08093230:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x7
	ble _08093216
_08093238:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80931B8

	thumb_func_start sub_809324C
sub_809324C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _080932C0
	add sp, r4
	adds r7, r0, 0
	mov r8, r1
	lsls r0, r1, 3
	adds r0, r7, r0
	ldrb r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strb r1, [r0]
	adds r0, r7, 0
	mov r1, sp
	bl sub_80939D0
	mov r0, sp
	bl sub_8093934
	adds r1, r0, 0
	subs r0, r1, 0x1
	cmp r0, 0x6
	bhi _0809329A
	lsls r1, 6
	lsls r0, 6
	mov r2, sp
	adds r5, r0, r2
	adds r4, r1, r2
	movs r6, 0x7
_08093288:
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	stm r4!, {r0,r1}
	stm r5!, {r2,r3}
	subs r6, 0x1
	cmp r6, 0
	bge _08093288
_0809329A:
	adds r0, r7, 0
	mov r1, sp
	bl sub_8093B40
	movs r1, 0
	movs r5, 0x80
	movs r4, 0x7F
	adds r2, r7, 0
_080932AA:
	ldrb r3, [r2]
	adds r0, r5, 0
	ands r0, r3
	cmp r0, 0
	beq _080932C4
	adds r0, r4, 0
	ands r0, r3
	strb r0, [r2]
	mov r8, r1
	b _080932CC
	.align 2, 0
_080932C0: .4byte 0xfffffe00
_080932C4:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x7
	ble _080932AA
_080932CC:
	mov r0, r8
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809324C

	thumb_func_start sub_80932E0
sub_80932E0:
	push {lr}
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080932F4
	movs r0, 0
	b _080932F6
_080932F4:
	movs r0, 0x1
_080932F6:
	pop {r1}
	bx r1
	thumb_func_end sub_80932E0

	thumb_func_start sub_80932FC
sub_80932FC:
	push {lr}
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08093310
	movs r0, 0
	b _08093312
_08093310:
	movs r0, 0x1
_08093312:
	pop {r1}
	bx r1
	thumb_func_end sub_80932FC

	thumb_func_start sub_8093318
sub_8093318:
	push {r4,lr}
	sub sp, 0x40
	adds r4, r0, 0
	mov r0, sp
	movs r2, 0x40
	bl MemoryCopy8
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093400
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x40
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093318

	thumb_func_start sub_809333C
sub_809333C:
	push {r4,lr}
	sub sp, 0x40
	adds r4, r0, 0
	mov r0, sp
	movs r2, 0x40
	bl MemoryCopy8
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093468
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x40
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809333C

	thumb_func_start sub_8093360
sub_8093360:
	push {r4,lr}
	sub sp, 0x40
	adds r4, r0, 0
	mov r0, sp
	movs r2, 0x40
	bl MemoryCopy8
	adds r0, r4, 0
	mov r1, sp
	bl sub_80933D8
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x40
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8093360

	thumb_func_start sub_8093384
sub_8093384:
	push {lr}
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08093398
	movs r0, 0x1
	b _0809339A
_08093398:
	movs r0, 0
_0809339A:
	pop {r1}
	bx r1
	thumb_func_end sub_8093384

	thumb_func_start sub_80933A0
sub_80933A0:
	push {r4-r6,lr}
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x2
	movs r3, 0x7
_080933AA:
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	beq _080933BE
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	bne _080933BE
	adds r4, 0x1
_080933BE:
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _080933AA
	cmp r4, 0x1
	bgt _080933CE
	movs r0, 0
	b _080933D0
_080933CE:
	movs r0, 0x1
_080933D0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80933A0

	thumb_func_start sub_80933D8
sub_80933D8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8093400
	lsls r0, 24
	cmp r0, 0
	bne _080933F6
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8093468
	lsls r0, 24
	lsrs r0, 24
	b _080933F8
_080933F6:
	movs r0, 0x1
_080933F8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80933D8

	thumb_func_start sub_8093400
sub_8093400:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r7, r1, 0
	lsls r0, r4, 3
	adds r0, r7, r0
	ldrh r0, [r0, 0x2]
	bl sub_809422C
	lsls r0, 24
	cmp r0, 0
	beq _08093428
	b _08093460
_08093418:
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r6]
	adds r0, r7, 0
	bl sub_809371C
	movs r0, 0x1
	b _08093462
_08093428:
	adds r5, r4, 0x1
	cmp r5, 0x7
	bgt _08093460
	lsls r0, r5, 3
	adds r4, r0, r7
	adds r6, r4, 0
_08093434:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093460
	ldrh r0, [r4, 0x2]
	bl sub_809422C
	lsls r0, 24
	cmp r0, 0
	bne _08093460
	ldrb r1, [r4]
	movs r2, 0x2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093418
	adds r4, 0x8
	adds r6, 0x8
	adds r5, 0x1
	cmp r5, 0x7
	ble _08093434
_08093460:
	movs r0, 0
_08093462:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093400

	thumb_func_start sub_8093468
sub_8093468:
	push {r4-r7,lr}
	adds r6, r1, 0
	movs r5, 0
	adds r1, r0, 0x1
	movs r4, 0
	cmp r1, 0x7
	bgt _080934A0
	movs r0, 0x2
	mov r12, r0
	movs r7, 0xFD
	lsls r0, r1, 3
	adds r3, r0, r6
_08093480:
	ldrb r2, [r3]
	mov r0, r12
	ands r0, r2
	cmp r0, 0
	beq _080934A0
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r3]
	movs r5, 0x1
	adds r3, 0x8
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x7
	bgt _080934A0
	cmp r1, 0x7
	ble _08093480
_080934A0:
	adds r0, r6, 0
	bl sub_809371C
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093468

	thumb_func_start sub_80934B0
sub_80934B0:
	push {lr}
	adds r2, r0, 0
	adds r0, r2, 0x1
	cmp r0, 0x7
	bgt _080934D2
	lsls r0, r2, 3
	adds r0, 0x8
	adds r0, r1, r0
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080934D2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080934D6
_080934D2:
	movs r0, 0
	b _080934D8
_080934D6:
	movs r0, 0x1
_080934D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80934B0

	thumb_func_start sub_80934DC
sub_80934DC:
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r0, 3
	adds r4, r5, r0
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080934F4
	movs r0, 0xF7
	ands r0, r1
	b _0809351A
_080934F4:
	movs r7, 0x1
	movs r6, 0xF7
	adds r1, r5, 0
	movs r3, 0x3
_080934FC:
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	beq _0809350C
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
_0809350C:
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _080934FC
	ldrb r1, [r4]
	movs r0, 0x8
	orrs r0, r1
_0809351A:
	strb r0, [r4]
	adds r0, r5, 0
	bl sub_809371C
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80934DC

	thumb_func_start sub_809352C
sub_809352C:
	push {lr}
	lsls r0, 3
	adds r0, r1, r0
	ldrb r3, [r0]
	movs r2, 0xF7
	ands r2, r3
	strb r2, [r0]
	adds r0, r1, 0
	bl sub_809371C
	pop {r0}
	bx r0
	thumb_func_end sub_809352C

	thumb_func_start sub_8093544
sub_8093544:
	push {lr}
	lsls r0, 3
	adds r0, r1, r0
	ldrb r2, [r0]
	movs r3, 0x4
	eors r2, r3
	strb r2, [r0]
	adds r0, r1, 0
	bl sub_809371C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8093544

	thumb_func_start sub_8093560
sub_8093560:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	movs r5, 0x1
	lsls r0, r4, 3
	adds r0, r6, r0
	ldrh r0, [r0, 0x2]
	strh r0, [r2]
	movs r1, 0
	adds r0, r2, 0x2
	movs r3, 0x2
_08093576:
	strh r1, [r0]
	adds r0, 0x2
	subs r3, 0x1
	cmp r3, 0
	bge _08093576
	adds r4, 0x1
	adds r2, 0x2
	cmp r4, 0x7
	bgt _080935B0
	cmp r5, 0x3
	bgt _080935B0
	movs r7, 0x2
	lsls r0, r4, 3
	adds r3, r0, r6
_08093592:
	ldrb r1, [r3]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080935B0
	ldrh r0, [r3, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	adds r5, 0x1
	adds r3, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	bgt _080935B0
	cmp r5, 0x3
	ble _08093592
_080935B0:
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093560

	thumb_func_start sub_80935B8
sub_80935B8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r0, 0x63
	mov r12, r0
	movs r0, 0
	mov r8, r0
	movs r6, 0
	adds r4, r1, 0
	cmp r4, 0
	blt _08093606
	lsls r0, r4, 3
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093606
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093606
	movs r7, 0x1
	movs r3, 0x2
_080935EC:
	subs r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	blt _08093606
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093606
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080935EC
_08093606:
	adds r2, r4, 0x1
	mov r9, r2
	cmp r2, 0x3
	bgt _08093642
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093642
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093642
	movs r6, 0x1
	movs r7, 0x2
_08093628:
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08093642
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08093642
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _08093628
_08093642:
	cmp r6, 0
	bne _0809364A
	movs r0, 0x63
	b _080936CC
_0809364A:
	movs r6, 0
	b _08093668
_0809364E:
	ldrb r0, [r3, 0x4]
	cmp r12, r0
	ble _08093656
	mov r12, r0
_08093656:
	cmp r0, 0
	bne _0809365C
	movs r6, 0x1
_0809365C:
	ldrb r1, [r3, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08093668
	movs r6, 0x1
_08093668:
	subs r2, 0x1
	cmp r2, r4
	blt _0809367C
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0809364E
_0809367C:
	cmp r6, 0
	beq _080936C6
	mov r2, r9
	cmp r2, 0x3
	bgt _080936C0
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080936C0
	movs r6, 0x2
	movs r4, 0xFD
_08093698:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080936C0
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r3]
	movs r0, 0x1
	mov r8, r0
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080936C0
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	bne _08093698
_080936C0:
	mov r0, r8
	cmp r0, 0
	bne _080936CA
_080936C6:
	mov r0, r12
	b _080936CC
_080936CA:
	movs r0, 0
_080936CC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80935B8

	thumb_func_start sub_80936D8
sub_80936D8:
	push {r4,lr}
	sub sp, 0x80
	adds r4, r0, 0
	mov r1, sp
	bl sub_8093784
	adds r0, r4, 0
	mov r1, sp
	bl sub_80937E0
	add sp, 0x80
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80936D8

	thumb_func_start sub_80936F4
sub_80936F4:
	push {r4,lr}
	ldr r4, _08093718
	add sp, r4
	adds r4, r0, 0
	mov r1, sp
	bl sub_8093974
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093A2C
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093718: .4byte 0xfffffe00
	thumb_func_end sub_80936F4

	thumb_func_start sub_809371C
sub_809371C:
	push {r4,lr}
	ldr r4, _08093740
	add sp, r4
	adds r4, r0, 0
	mov r1, sp
	bl sub_80939D0
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093B40
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093740: .4byte 0xfffffe00
	thumb_func_end sub_809371C

	thumb_func_start sub_8093744
sub_8093744:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_0809374E:
	movs r3, 0
	lsls r0, r4, 5
	adds r2, r0, r7
_08093754:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809376A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809376A
	adds r0, r4, 0
	b _0809377C
_0809376A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08093754
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809374E
	movs r0, 0x1
	negs r0, r0
_0809377C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093744

	thumb_func_start sub_8093784
sub_8093784:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_0809378C:
	lsls r0, r2, 5
	adds r2, 0x1
	movs r3, 0x3
	adds r0, r1
	adds r0, 0x18
_08093796:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093796
	cmp r2, 0x3
	ble _0809378C
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x20
	movs r7, 0x2
_080937AE:
	cmp r5, 0
	beq _080937BC
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080937C0
_080937BC:
	adds r4, 0x20
	movs r3, 0
_080937C0:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x3
	ble _080937AE
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093784

	thumb_func_start sub_80937E0
sub_80937E0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp, 0x8]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x4
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_080937FE:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x4
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 5
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x3
_0809381E:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0809383E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093832
	strb r3, [r7]
_08093832:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0809383E
	strb r3, [r5]
_0809383E:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _0809381E
	cmp r6, 0x3
	ble _080937FE
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0xC]
_08093852:
	movs r4, 0
	lsls r0, r6, 5
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x8]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093866:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080938D6
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093884
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _0809388A
_08093884:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_0809388A:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080938B0
	cmp r4, 0
	bne _080938B0
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_080938B0:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _080938C4
	cmp r4, 0
	bne _080938C4
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080938C4:
	adds r2, 0x8
	ldr r7, [sp, 0xC]
	adds r7, 0x8
	str r7, [sp, 0xC]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x4
	beq _080938E4
_080938D6:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08093866
	adds r6, 0x1
	cmp r6, 0x3
	ble _08093852
_080938E4:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80937E0

	thumb_func_start sub_80938F4
sub_80938F4:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_080938FE:
	movs r3, 0
	lsls r0, r4, 6
	adds r2, r0, r7
_08093904:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809391A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809391A
	adds r0, r4, 0
	b _0809392C
_0809391A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093904
	adds r4, 0x1
	cmp r4, 0x7
	ble _080938FE
	movs r0, 0x1
	negs r0, r0
_0809392C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80938F4

	thumb_func_start sub_8093934
sub_8093934:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_0809393E:
	movs r3, 0
	lsls r0, r4, 6
	adds r2, r0, r7
_08093944:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809395A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809395A
	adds r0, r4, 0
	b _0809396C
_0809395A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093944
	adds r4, 0x1
	cmp r4, 0x7
	ble _0809393E
	movs r0, 0x1
	negs r0, r0
_0809396C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093934

	thumb_func_start sub_8093974
sub_8093974:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_0809397C:
	lsls r0, r2, 6
	adds r2, 0x1
	movs r3, 0x7
	adds r0, r1
	adds r0, 0x38
_08093986:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093986
	cmp r2, 0x7
	ble _0809397C
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x40
	movs r7, 0x2
_0809399E:
	cmp r5, 0
	beq _080939AC
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080939B0
_080939AC:
	adds r4, 0x40
	movs r3, 0
_080939B0:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x7
	ble _0809399E
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093974

	thumb_func_start sub_80939D0
sub_80939D0:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_080939D8:
	lsls r0, r2, 6
	adds r2, 0x1
	movs r3, 0x7
	adds r0, r1
	adds r0, 0x38
_080939E2:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _080939E2
	cmp r2, 0x7
	ble _080939D8
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x40
	movs r7, 0x2
_080939FA:
	cmp r5, 0
	beq _08093A08
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _08093A0C
_08093A08:
	adds r4, 0x40
	movs r3, 0
_08093A0C:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x7
	ble _080939FA
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80939D0

	thumb_func_start sub_8093A2C
sub_8093A2C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x8
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_08093A4A:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x8
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 6
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x7
_08093A6A:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08093A8A
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093A7E
	strb r3, [r7]
_08093A7E:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08093A8A
	strb r3, [r5]
_08093A8A:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _08093A6A
	cmp r6, 0x7
	ble _08093A4A
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0x14]
_08093A9E:
	movs r4, 0
	lsls r0, r6, 6
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x10]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093AB2:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093B22
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093AD0
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _08093AD6
_08093AD0:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_08093AD6:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08093AFC
	cmp r4, 0
	bne _08093AFC
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_08093AFC:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _08093B10
	cmp r4, 0
	bne _08093B10
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08093B10:
	adds r2, 0x8
	ldr r7, [sp, 0x14]
	adds r7, 0x8
	str r7, [sp, 0x14]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x8
	beq _08093B30
_08093B22:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093AB2
	adds r6, 0x1
	cmp r6, 0x7
	ble _08093A9E
_08093B30:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093A2C

	thumb_func_start sub_8093B40
sub_8093B40:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x8
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_08093B5E:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x8
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 6
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x7
_08093B7E:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08093B9E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093B92
	strb r3, [r7]
_08093B92:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08093B9E
	strb r3, [r5]
_08093B9E:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _08093B7E
	cmp r6, 0x7
	ble _08093B5E
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0x14]
_08093BB2:
	movs r4, 0
	lsls r0, r6, 6
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x10]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093BC6:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093C36
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093BE4
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _08093BEA
_08093BE4:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_08093BEA:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08093C10
	cmp r4, 0
	bne _08093C10
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_08093C10:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _08093C24
	cmp r4, 0
	bne _08093C24
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08093C24:
	adds r2, 0x8
	ldr r7, [sp, 0x14]
	adds r7, 0x8
	str r7, [sp, 0x14]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x8
	beq _08093C44
_08093C36:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093BC6
	adds r6, 0x1
	cmp r6, 0x7
	ble _08093BB2
_08093C44:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093B40

	thumb_func_start sub_8093C54
sub_8093C54:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093C86:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093C86
_08093CA6:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093CB0:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CC2
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093CC2:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093CB0
	cmp r4, 0x7
	bgt _08093CDE
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093CD4:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093CD4
_08093CDE:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093CE4:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093CE4
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093C54

	thumb_func_start sub_8093CF8
sub_8093CF8:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093D2A:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093D2A
_08093D4A:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093D54:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D66
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093D66:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093D54
	cmp r4, 0x7
	bgt _08093D82
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093D78:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093D78
_08093D82:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093D88:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093D88
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093CF8

	thumb_func_start sub_8093D9C
sub_8093D9C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl sub_8092A88
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D9C

	thumb_func_start sub_8093DC4
sub_8093DC4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	mov r0, sp
	bl sub_8093F10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093DC4

	thumb_func_start sub_8093DE8
sub_8093DE8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08093E80
	add sp, r4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	adds r0, r5, 0
	bl sub_80073B8
	ldr r0, _08093E84
	adds r1, r6, 0
	movs r2, 0
	bl sub_80928C0
	lsls r4, 3
	adds r4, 0x10
	ldr r2, _08093E88
	movs r7, 0
	str r7, [sp]
	adds r0, r4, 0
	movs r1, 0
	adds r3, r5, 0
	bl sub_8014FF0
	movs r3, 0x13
	ldrh r1, [r6, 0x2]
	ldr r4, _08093E8C
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0, 0x1C]
	ldrb r0, [r2]
	cmp r0, 0x2A
	bne _08093E3A
	movs r3, 0x10
	adds r2, 0x1
_08093E3A:
	str r7, [sp]
	movs r0, 0x4
	adds r1, r3, 0
	adds r3, r5, 0
	bl sub_8014FF0
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8093E90
	adds r0, r5, 0
	bl sub_80073E0
	ldrh r1, [r6, 0x2]
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0, 0x1C]
	add r0, sp, 0x4
	bl strcpy
	add r0, sp, 0x4
	mov r1, r8
	bl sub_8097DF0
	movs r3, 0xC9
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08093E80: .4byte 0xfffffcdc
_08093E84: .4byte gUnknown_202DF98
_08093E88: .4byte gUnknown_8109930
_08093E8C: .4byte gUnknown_2038C68
	thumb_func_end sub_8093DE8

	thumb_func_start sub_8093E90
sub_8093E90:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0x7
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0x4
	movs r2, 0x48
	movs r3, 0xC8
	bl sub_80078A4
	ldr r0, _08093F00
	adds r1, r6, 0
	bl sub_8092D54
	ldr r0, _08093F04
	ldr r2, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x4A
	adds r3, r5, 0
	bl sub_8014FF0
	ldr r0, _08093F08
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x56
	adds r3, r5, 0
	bl sub_8014FF0
	adds r0, r6, 0
	bl sub_8092B00
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092334
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x40
	movs r1, 0x56
	adds r3, r5, 0
	bl sub_8014FF0
	adds r0, r6, 0
	bl sub_8092BC0
	ldr r1, _08093F0C
	str r0, [r1]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093F00: .4byte gUnknown_202DF98
_08093F04: .4byte gUnknown_810CF00
_08093F08: .4byte gUnknown_810CF0C
_08093F0C: .4byte gUnknown_202DE30
	thumb_func_end sub_8093E90

	thumb_func_start sub_8093F10
sub_8093F10:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F48
	movs r0, 0
	strb r1, [r3]
	strb r0, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F44
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F4A
	.align 2, 0
_08093F44: .4byte gUnknown_2038C68
_08093F48:
	strb r0, [r3]
_08093F4A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F10

	thumb_func_start sub_8093F50
sub_8093F50:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r7, 0
	adds r3, r6, 0
	adds r4, r1, 0
	movs r5, 0x3
_08093F5C:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F8C
	strb r1, [r3]
	strb r7, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F88
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F8E
	.align 2, 0
_08093F88: .4byte gUnknown_2038C68
_08093F8C:
	strb r0, [r3]
_08093F8E:
	adds r3, 0x8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08093F5C
	adds r1, r6, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F50

	thumb_func_start sub_8093FA8
sub_8093FA8:
	push {lr}
	adds r2, r0, 0
	movs r3, 0x3
_08093FAE:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x2]
	ldrb r0, [r1, 0x5]
	strb r0, [r2, 0x4]
	adds r2, 0x8
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093FAE
	pop {r0}
	bx r0
	thumb_func_end sub_8093FA8

	thumb_func_start sub_8093FC8
sub_8093FC8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r2, r1, 0
	movs r3, 0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094002
	movs r7, 0xFB
	movs r6, 0x1
	adds r4, r2, 0
	adds r2, r5, 0
_08093FE2:
	ldm r4!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2, 0x1]
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2, 0x1]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08094002
	ldrb r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08093FE2
_08094002:
	cmp r3, 0x7
	bgt _08094016
	movs r1, 0
	lsls r0, r3, 3
	adds r0, r5
_0809400C:
	strb r1, [r0]
	adds r0, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _0809400C
_08094016:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093FC8

	thumb_func_start sub_809401C
sub_809401C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	movs r2, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094046
	movs r6, 0x1
	adds r4, r5, 0
_08094032:
	ldm r3!, {r0,r1}
	stm r4!, {r0,r1}
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08094046
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08094032
_08094046:
	cmp r2, 0x7
	bgt _0809405A
	movs r1, 0
	lsls r0, r2, 3
	adds r0, r5
_08094050:
	strb r1, [r0]
	adds r0, 0x8
	adds r2, 0x1
	cmp r2, 0x7
	ble _08094050
_0809405A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809401C

	thumb_func_start sub_8094060
sub_8094060:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	movs r4, 0
	movs r5, 0
	adds r3, r6, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
_08094076:
	lsls r2, r4, 3
	adds r2, r7, r2
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r4, 0x1
_08094084:
	adds r5, 0x1
	cmp r5, 0x7
	bgt _0809409C
	lsls r0, r5, 3
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
	cmp r4, 0x3
	ble _08094076
_0809409C:
	cmp r4, 0x3
	bgt _080940B0
	movs r1, 0
	lsls r0, r4, 3
	adds r0, r7
_080940A6:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _080940A6
_080940B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8094060

	thumb_func_start sub_80940B8
sub_80940B8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_809488C
	adds r5, 0x4
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80940B8

	thumb_func_start sub_80940E0
sub_80940E0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_8094924
	adds r5, 0x4
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80940E0

	thumb_func_start sub_8094108
sub_8094108:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	movs r5, 0x3
_08094110:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80940B8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08094110
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8094108

	thumb_func_start sub_8094128
sub_8094128:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	movs r5, 0x3
_08094130:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80940E0
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08094130
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8094128

	thumb_func_start sub_8094148
sub_8094148:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r4, 0x1
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_809488C
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x7
	bl sub_809488C
	adds r4, 0x5
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8094148

	thumb_func_start sub_8094184
sub_8094184:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_0809418E:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8094148
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _0809418E
	adds r1, r7, 0
	adds r1, 0x20
	adds r0, r6, 0
	movs r2, 0x8
	bl sub_809488C
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8094184

	thumb_func_start sub_80941B0
sub_80941B0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r4, 0x1
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8094924
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x7
	bl sub_8094924
	adds r4, 0x5
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80941B0

	thumb_func_start sub_80941FC
sub_80941FC:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_08094206:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80941B0
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08094206
	adds r1, r7, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	movs r2, 0x8
	bl sub_8094924
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80941FC

	thumb_func_start sub_809422C
sub_809422C:
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	cmp r1, 0x97
	beq _08094260
	cmp r1, 0x64
	beq _08094260
	cmp r1, 0x3C
	beq _08094260
	cmp r1, 0x4B
	beq _08094260
	movs r0, 0xAE
	lsls r0, 1
	cmp r1, r0
	beq _08094260
	cmp r1, 0x99
	beq _08094260
	cmp r1, 0xCD
	beq _08094260
	cmp r1, 0x9C
	beq _08094260
	cmp r2, 0x8
	beq _08094260
	movs r0, 0
	b _08094262
_08094260:
	movs r0, 0x1
_08094262:
	pop {r1}
	bx r1
	thumb_func_end sub_809422C

	thumb_func_start sub_8094268
sub_8094268:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	adds r0, r1
	lsls r0, 16
	ldr r6, _080942B0
	ands r3, r6
	orrs r3, r0
	adds r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r4, _080942B4
	ands r3, r4
	orrs r3, r2
	asrs r1, r3, 16
	ldr r0, _080942B8
	cmp r1, r0
	ble _080942A6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r4
	orrs r3, r0
	asrs r0, r3, 16
	ldr r1, _080942BC
	adds r0, r1
	lsls r0, 16
	ands r3, r6
	orrs r3, r0
_080942A6:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080942B0: .4byte 0x0000ffff
_080942B4: .4byte 0xffff0000
_080942B8: .4byte 0x000003e7
_080942BC: .4byte 0xfffffc18
	thumb_func_end sub_8094268

	thumb_func_start sub_80942C0
sub_80942C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	subs r0, r1
	lsls r0, 16
	ldr r4, _08094310
	ands r3, r4
	orrs r3, r0
	subs r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r1, _08094314
	ands r3, r1
	orrs r3, r2
	cmp r3, 0
	bge _080942FC
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r1
	orrs r3, r0
	asrs r0, r3, 16
	movs r2, 0xFA
	lsls r2, 2
	adds r0, r2
	lsls r0, 16
	ands r3, r4
	orrs r3, r0
_080942FC:
	lsls r0, r3, 16
	cmp r0, 0
	bge _08094304
	movs r3, 0
_08094304:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094310: .4byte 0x0000ffff
_08094314: .4byte 0xffff0000
	thumb_func_end sub_80942C0

	thumb_func_start sub_8094318
sub_8094318:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094336
	cmp r1, r0
	blt _0809433A
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _0809433A
_08094336:
	str r2, [r4]
	b _0809433C
_0809433A:
	str r3, [r4]
_0809433C:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094318

	thumb_func_start sub_8094344
sub_8094344:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094362
	cmp r1, r0
	blt _08094366
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _08094366
_08094362:
	str r3, [r4]
	b _08094368
_08094366:
	str r2, [r4]
_08094368:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094344

	thumb_func_start sub_8094370
sub_8094370:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsls r2, 16
	ldr r4, _08094398
	lsrs r3, r1, 16
	orrs r3, r2
	asrs r2, 16
	ldr r1, _0809439C
	asrs r0, r1, 16
	cmp r2, r0
	ble _0809438C
	ands r3, r4
	orrs r3, r1
_0809438C:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094398: .4byte 0x0000ffff
_0809439C: .4byte 0x03e70000
	thumb_func_end sub_8094370

	thumb_func_start sub_80943A0
sub_80943A0:
	lsls r1, 16
	lsrs r2, r1, 16
	str r2, [r0]
	bx lr
	thumb_func_end sub_80943A0

	thumb_func_start sub_80943A8
sub_80943A8:
	push {r4,r5,lr}
	ldr r3, [r1, 0x4]
	lsrs r2, r3, 16
	ldr r1, _080943D4
	ands r5, r1
	orrs r5, r2
	ldr r4, _080943D8
	adds r2, r4, 0
	ands r2, r3
	lsls r1, r2, 5
	subs r1, r2
	lsls r1, 2
	adds r1, r2
	lsls r1, 3
	lsrs r1, 16
	lsls r1, 16
	ands r5, r4
	orrs r5, r1
	str r5, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080943D4: .4byte 0xffff0000
_080943D8: .4byte 0x0000ffff
	thumb_func_end sub_80943A8

	thumb_func_start sub_80943DC
sub_80943DC:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	lsls r1, r4, 16
	asrs r1, 16
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	asrs r1, r4, 16
	adds r0, r1
	lsls r3, r2, 16
	asrs r3, 16
	lsls r1, r3, 5
	subs r1, r3
	lsls r1, 2
	adds r1, r3
	lsls r1, 3
	asrs r2, 16
	adds r1, r2
	muls r0, r1
	movs r5, 0xFA
	lsls r5, 2
	adds r1, r5, 0
	bl __divsi3
	adds r6, r0, 0
	adds r1, r5, 0
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08094448
	ands r4, r1
	orrs r4, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl __modsi3
	lsls r0, 16
	ldr r1, _0809444C
	ands r1, r4
	orrs r0, r1
	mov r1, r8
	str r0, [r1]
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094448: .4byte 0xffff0000
_0809444C: .4byte 0x0000ffff
	thumb_func_end sub_80943DC

	thumb_func_start sub_8094450
sub_8094450:
	push {lr}
	adds r1, r0, 0
	lsls r0, r1, 16
	asrs r2, r0, 16
	cmp r2, 0
	bne _0809446A
	asrs r0, r1, 16
	cmp r0, 0
	bne _08094466
	movs r0, 0
	b _08094476
_08094466:
	movs r0, 0x1
	b _08094476
_0809446A:
	asrs r0, r1, 16
	cmp r0, 0
	bne _08094474
	adds r0, r2, 0
	b _08094476
_08094474:
	adds r0, r2, 0x1
_08094476:
	pop {r1}
	bx r1
	thumb_func_end sub_8094450

	thumb_func_start sub_809447C
sub_809447C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x10
	bl sub_8094924
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809447C

	thumb_func_start sub_809449C
sub_809449C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x10
	bl sub_809488C
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809449C

	thumb_func_start sub_80944BC
sub_80944BC:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r1, 0
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _080944F4
	cmp r1, r0
	bgt _08094500
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl sub_8092AA8
	ldr r0, _080944F8
	mov r1, sp
	movs r2, 0
	bl sub_80928C0
	ldr r0, _080944FC
	ldr r0, [r0]
	adds r2, r4, 0
	adds r2, 0xC8
	adds r1, r4, 0
	movs r3, 0
	bl xxx_format_string
	b _08094516
	.align 2, 0
_080944F4: .4byte 0x000001f3
_080944F8: .4byte gUnknown_202DE58
_080944FC: .4byte gUnknown_811383C
_08094500:
	ldr r0, _08094520
	ldr r2, _08094524
	adds r1, r2
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r4, 0
	movs r2, 0xC8
	bl strncpy
_08094516:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094520: .4byte gUnknown_8113080
_08094524: .4byte 0xfffffe0c
	thumb_func_end sub_80944BC

	thumb_func_start sub_8094528
sub_8094528:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _08094544
	cmp r1, r0
	ble _08094550
	ldr r0, _08094548
	ldr r2, _0809454C
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1]
	b _08094552
	.align 2, 0
_08094544: .4byte 0x000001f3
_08094548: .4byte gUnknown_8113080
_0809454C: .4byte 0xfffffe0c
_08094550:
	movs r0, 0x1
_08094552:
	pop {r1}
	bx r1
	thumb_func_end sub_8094528

	thumb_func_start sub_8094558
sub_8094558:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xCC
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	bl sub_80073B8
	movs r5, 0
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl sub_8014FF0
	ldr r4, _080945D0
	adds r1, r6, 0
	adds r1, 0x18
	adds r0, r4, 0
	bl sub_8090208
	ldr r0, _080945D4
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x10
	adds r3, r7, 0
	bl sub_8014FF0
	movs r5, 0x1A
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	adds r4, 0x50
	adds r1, r6, 0
	adds r1, 0xA
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	bl sub_8094528
	lsls r0, 24
	cmp r0, 0
	beq _080945DC
	ldr r0, _080945D8
	ldr r0, [r0]
	add r2, sp, 0xCC
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	b _080945EA
	.align 2, 0
_080945D0: .4byte gUnknown_202DF98
_080945D4: .4byte gUnknown_8113850
_080945D8: .4byte gUnknown_8113868
_080945DC:
	ldr r0, _0809465C
	ldr r0, [r0]
	add r2, sp, 0xCC
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
_080945EA:
	add r0, sp, 0x4
	bl sub_8008ED0
	movs r4, 0xB0
	subs r0, r4, r0
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0
	mov r8, r1
	str r1, [sp]
	adds r1, r5, 0
	add r2, sp, 0x4
	adds r3, r7, 0
	bl sub_8014FF0
	adds r5, 0xA
	movs r1, 0x14
	ldrsh r0, [r6, r1]
	add r1, sp, 0x4
	bl sub_80944BC
	add r0, sp, 0x4
	bl sub_8008ED0
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r0, r4, 1
	mov r1, r8
	str r1, [sp]
	adds r1, r5, 0
	add r2, sp, 0x4
	adds r3, r7, 0
	bl sub_8014FF0
	adds r5, 0x10
	ldr r1, _08094660
	ldr r0, [r6, 0x20]
	str r0, [r1]
	adds r0, r6, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	str r0, [r1, 0x4]
	cmp r0, 0x63
	ble _08094668
	ldr r0, _08094664
	ldr r2, [r0]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
	b _0809467A
	.align 2, 0
_0809465C: .4byte gUnknown_8113870
_08094660: .4byte gUnknown_202DE30
_08094664: .4byte gUnknown_81138C0
_08094668:
	ldr r0, _080946CC
	ldr r2, [r0]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
_0809467A:
	adds r5, 0xA
	ldr r4, _080946D0
	movs r1, 0x24
	ldrsh r0, [r6, r1]
	str r0, [r4]
	ldr r0, _080946D4
	ldr r2, [r0]
	movs r0, 0
	mov r8, r0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
	adds r5, 0xA
	adds r0, r6, 0
	adds r0, 0x26
	ldrb r2, [r0]
	str r2, [r4]
	adds r0, 0x2
	ldrb r0, [r0]
	str r0, [r4, 0x4]
	adds r0, r6, 0
	adds r0, 0x2B
	ldrb r1, [r0]
	cmp r1, 0
	beq _080946DC
	adds r0, r1, 0
	adds r0, r2, r0
	str r0, [r4]
	ldr r0, _080946D8
	ldr r2, [r0]
	mov r1, r8
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
	b _080946EC
	.align 2, 0
_080946CC: .4byte gUnknown_8113898
_080946D0: .4byte gUnknown_202DE30
_080946D4: .4byte gUnknown_81138D0
_080946D8: .4byte gUnknown_8113950
_080946DC:
	ldr r0, _08094714
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
_080946EC:
	adds r0, r6, 0
	adds r0, 0x2D
	ldrb r1, [r0]
	cmp r1, 0
	beq _08094720
	ldr r2, _08094718
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, _0809471C
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
	b _08094730
	.align 2, 0
_08094714: .4byte gUnknown_81138E4
_08094718: .4byte gUnknown_202DE30
_0809471C: .4byte gUnknown_8113974
_08094720:
	ldr r0, _08094768
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
_08094730:
	adds r5, 0xA
	ldr r2, _0809476C
	adds r0, r6, 0
	adds r0, 0x27
	ldrb r3, [r0]
	str r3, [r2]
	adds r0, 0x2
	ldrb r0, [r0]
	str r0, [r2, 0x4]
	adds r0, r6, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	cmp r1, 0
	beq _08094774
	adds r0, r1, 0
	adds r0, r3, r0
	str r0, [r2]
	ldr r0, _08094770
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
	b _08094784
	.align 2, 0
_08094768: .4byte gUnknown_8113900
_0809476C: .4byte gUnknown_202DE30
_08094770: .4byte gUnknown_8113990
_08094774:
	ldr r0, _080947AC
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
_08094784:
	adds r0, r6, 0
	adds r0, 0x2E
	ldrb r1, [r0]
	cmp r1, 0
	beq _080947B8
	ldr r2, _080947B0
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, _080947B4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
	b _080947C8
	.align 2, 0
_080947AC: .4byte gUnknown_8113918
_080947B0: .4byte gUnknown_202DE30
_080947B4: .4byte gUnknown_81139B4
_080947B8:
	ldr r0, _080947E4
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
_080947C8:
	adds r5, 0x10
	adds r2, r6, 0
	adds r2, 0x1C
	ldrb r1, [r6, 0x1C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080947EC
	ldr r0, _080947E8
	adds r1, r2, 0
	movs r2, 0
	bl sub_8090E14
	b _080947F6
	.align 2, 0
_080947E4: .4byte gUnknown_8113934
_080947E8: .4byte gUnknown_202DE58
_080947EC:
	ldr r0, _0809481C
	ldr r1, _08094820
	ldr r1, [r1]
	bl strcpy
_080947F6:
	ldr r0, _08094824
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8014FF0
	adds r0, r7, 0
	bl sub_80073E0
	add sp, 0xCC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809481C: .4byte gUnknown_202DE58
_08094820: .4byte gUnknown_81139B8
_08094824: .4byte gUnknown_81139CC
	thumb_func_end sub_8094558

	thumb_func_start sub_8094828
sub_8094828:
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, 0
	beq _08094852
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bne _0809484C
	ldr r0, _08094848
	b _08094856
	.align 2, 0
_08094848: .4byte 0x00000223
_0809484C:
	movs r0, 0x89
	lsls r0, 2
	b _08094856
_08094852:
	lsls r0, r2, 16
	asrs r0, 16
_08094856:
	pop {r1}
	bx r1
	thumb_func_end sub_8094828

	thumb_func_start sub_809485C
sub_809485C:
	str r1, [r0]
	movs r3, 0
	str r3, [r0, 0x8]
	str r3, [r0, 0xC]
	adds r1, r2
	str r1, [r0, 0x4]
	bx lr
	thumb_func_end sub_809485C

	thumb_func_start sub_809486C
sub_809486C:
	push {lr}
	str r1, [r0]
	movs r3, 0
	str r3, [r0, 0x8]
	str r3, [r0, 0xC]
	adds r3, r1, r2
	str r3, [r0, 0x4]
	adds r0, r1, 0
	adds r1, r2, 0
	bl MemoryClear8
	pop {r0}
	bx r0
	thumb_func_end sub_809486C

	thumb_func_start nullsub_102
nullsub_102:
	bx lr
	thumb_func_end nullsub_102

	thumb_func_start sub_809488C
sub_809488C:
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r4, r2, 0
	movs r5, 0
	adds r6, r1, 0
	cmp r4, 0
	beq _080948DE
	movs r7, 0x1
_0809489C:
	ldrb r0, [r6]
	asrs r0, r5
	ands r0, r7
	cmp r0, 0
	beq _080948B4
	ldr r2, [r3]
	ldr r1, [r3, 0x8]
	adds r0, r7, 0
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_080948B4:
	adds r5, 0x1
	cmp r5, 0x8
	bne _080948BE
	adds r6, 0x1
	movs r5, 0
_080948BE:
	ldr r0, [r3, 0x8]
	adds r0, 0x1
	str r0, [r3, 0x8]
	cmp r0, 0x8
	bne _080948D2
	ldr r0, [r3]
	adds r0, 0x1
	str r0, [r3]
	movs r0, 0
	str r0, [r3, 0x8]
_080948D2:
	ldr r0, [r3, 0xC]
	adds r0, 0x1
	str r0, [r3, 0xC]
	subs r4, 0x1
	cmp r4, 0
	bne _0809489C
_080948DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809488C

	thumb_func_start sub_80948E4
sub_80948E4:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r1, 0
	cmp r5, 0
	beq _0809491C
_080948F0:
	ldrb r1, [r6]
	ldr r0, [r4, 0x8]
	lsls r1, r0
	ldr r3, [r4]
	ldrb r2, [r3]
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r3]
	ldr r2, [r4]
	adds r0, r2, 0x1
	str r0, [r4]
	asrs r1, 8
	ldrb r0, [r2, 0x1]
	orrs r1, r0
	strb r1, [r2, 0x1]
	adds r6, 0x1
	ldr r0, [r4, 0xC]
	adds r0, 0x8
	str r0, [r4, 0xC]
	subs r5, 0x1
	cmp r5, 0
	bne _080948F0
_0809491C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80948E4

	thumb_func_start sub_8094924
sub_8094924:
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r5, r2, 0
	movs r6, 0
	adds r2, r1, 0
	cmp r5, 0
	beq _08094978
_08094932:
	cmp r6, 0
	bne _08094938
	strb r6, [r2]
_08094938:
	ldr r7, [r3]
	ldrb r0, [r7]
	ldr r4, [r3, 0x8]
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094952
	adds r0, r1, 0
	lsls r0, r6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08094952:
	adds r6, 0x1
	cmp r6, 0x8
	bne _0809495C
	adds r2, 0x1
	movs r6, 0
_0809495C:
	adds r0, r4, 0x1
	str r0, [r3, 0x8]
	cmp r0, 0x8
	bne _0809496C
	adds r0, r7, 0x1
	str r0, [r3]
	movs r0, 0
	str r0, [r3, 0x8]
_0809496C:
	ldr r0, [r3, 0xC]
	adds r0, 0x1
	str r0, [r3, 0xC]
	subs r5, 0x1
	cmp r5, 0
	bne _08094932
_08094978:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8094924

	thumb_func_start sub_8094980
sub_8094980:
	ldr r1, _08094988
	ldr r0, _0809498C
	str r0, [r1]
	bx lr
	.align 2, 0
_08094988: .4byte gUnknown_203B46C
_0809498C: .4byte gUnknown_2038C70
	thumb_func_end sub_8094980

	thumb_func_start sub_8094990
sub_8094990:
	ldr r0, _08094994
	bx lr
	.align 2, 0
_08094994: .4byte gUnknown_2038C70
	thumb_func_end sub_8094990

	thumb_func_start sub_8094998
sub_8094998:
	push {lr}
	lsls r0, 24
	ldr r2, _080949D8
	ldr r1, [r2]
	movs r3, 0
	strb r3, [r1, 0x8]
	cmp r0, 0
	beq _080949AC
	ldr r0, [r2]
	strb r3, [r0, 0xB]
_080949AC:
	ldr r0, [r2]
	strb r3, [r0, 0x9]
	ldr r0, [r2]
	strb r3, [r0, 0xA]
	ldr r0, [r2]
	strb r3, [r0]
	ldr r0, [r2]
	movs r1, 0x1
	strb r1, [r0, 0x1]
	ldr r0, [r2]
	strb r1, [r0, 0x2]
	ldr r0, [r2]
	strb r1, [r0, 0x3]
	ldr r0, [r2]
	strb r1, [r0, 0x4]
	ldr r0, [r2]
	strb r3, [r0, 0xC]
	bl sub_8094C14
	pop {r0}
	bx r0
	.align 2, 0
_080949D8: .4byte gUnknown_203B46C
	thumb_func_end sub_8094998

	thumb_func_start sub_80949DC
sub_80949DC:
	push {lr}
	adds r2, r0, 0
	ldr r0, _08094A38
	ldr r1, [r0]
	ldrb r0, [r1, 0x8]
	ldrb r3, [r2, 0x8]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0x9]
	ldrb r3, [r2, 0x9]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0xA]
	ldrb r3, [r2, 0xA]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0xB]
	ldrb r3, [r2, 0xB]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1]
	ldrb r3, [r2]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0x1]
	ldrb r3, [r2, 0x1]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0x2]
	ldrb r3, [r2, 0x2]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0x3]
	ldrb r3, [r2, 0x3]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0x4]
	ldrb r3, [r2, 0x4]
	cmp r0, r3
	bne _08094A3C
	ldrb r0, [r1, 0xC]
	ldrb r2, [r2, 0xC]
	cmp r0, r2
	bne _08094A3C
	movs r0, 0x1
	b _08094A3E
	.align 2, 0
_08094A38: .4byte gUnknown_203B46C
_08094A3C:
	movs r0, 0
_08094A3E:
	pop {r1}
	bx r1
	thumb_func_end sub_80949DC

	thumb_func_start sub_8094A44
sub_8094A44:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0xFF
	mov r0, sp
	strb r1, [r0]
	mov r7, sp
	adds r7, 0x1
	movs r0, 0
	strb r0, [r7]
	ldr r5, _08094B14
	ldr r1, [r5]
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x2
	bl sub_809488C
	ldr r0, [r5]
	ldrb r0, [r0, 0x9]
	mov r1, sp
	adds r6, r7, 0
	cmp r0, 0
	bne _08094A74
	adds r1, r6, 0
_08094A74:
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r0, [r5]
	ldrb r0, [r0, 0xA]
	adds r1, r6, 0
	cmp r0, 0
	beq _08094A88
	mov r1, sp
_08094A88:
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r0, [r5]
	ldrb r0, [r0, 0xB]
	adds r1, r6, 0
	cmp r0, 0
	beq _08094A9C
	mov r1, sp
_08094A9C:
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r0, [r5]
	ldrb r0, [r0]
	adds r1, r6, 0
	cmp r0, 0
	beq _08094AB0
	mov r1, sp
_08094AB0:
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	adds r1, r6, 0
	cmp r0, 0
	beq _08094AC4
	mov r1, sp
_08094AC4:
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r0, [r5]
	ldrb r0, [r0, 0x2]
	adds r1, r6, 0
	cmp r0, 0
	beq _08094AD8
	mov r1, sp
_08094AD8:
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r0, [r5]
	ldrb r0, [r0, 0x3]
	adds r1, r7, 0
	cmp r0, 0
	beq _08094AEC
	mov r1, sp
_08094AEC:
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r1, [r5]
	adds r1, 0x4
	adds r0, r4, 0
	movs r2, 0x3
	bl sub_809488C
	ldr r1, [r5]
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x2
	bl sub_809488C
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094B14: .4byte gUnknown_203B46C
	thumb_func_end sub_8094A44

	thumb_func_start sub_8094B18
sub_8094B18:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r6, r0, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_8094924
	ldr r5, _08094C10
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x3
	mov r8, r0
	ands r0, r1
	strb r0, [r2, 0x8]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2, 0x9]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2, 0xA]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2, 0xB]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2, 0x1]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2, 0x2]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	ldr r1, [r5]
	mov r0, sp
	ldrb r0, [r0]
	ands r4, r0
	strb r4, [r1, 0x3]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x3
	bl sub_8094924
	ldr r2, [r5]
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x7
	ands r0, r1
	strb r0, [r2, 0x4]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_8094924
	ldr r1, [r5]
	mov r0, sp
	ldrb r0, [r0]
	mov r2, r8
	ands r2, r0
	strb r2, [r1, 0xC]
	bl sub_8094C14
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08094C10: .4byte gUnknown_203B46C
	thumb_func_end sub_8094B18

	thumb_func_start sub_8094C14
sub_8094C14:
	push {r4,lr}
	sub sp, 0x10
	mov r1, sp
	ldr r0, _08094C40
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08094C44
	ldr r0, [r0]
	ldrb r1, [r0, 0x8]
	movs r0, 0x3
	ands r0, r1
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	bl sub_80099F0
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094C40: .4byte gUnknown_8109954
_08094C44: .4byte gUnknown_203B46C
	thumb_func_end sub_8094C14

	thumb_func_start sub_8094C48
sub_8094C48:
	push {lr}
	ldr r0, _08094C5C
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08094C60
	cmp r0, 0x3
	beq _08094C60
	movs r0, 0x1
	b _08094C62
	.align 2, 0
_08094C5C: .4byte gUnknown_203B46C
_08094C60:
	movs r0, 0
_08094C62:
	pop {r1}
	bx r1
	thumb_func_end sub_8094C48

	thumb_func_start sub_8094C68
sub_8094C68:
	push {lr}
	ldr r0, _08094C7C
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2
	beq _08094C80
	cmp r0, 0x5
	beq _08094C80
	movs r0, 0x1
	b _08094C82
	.align 2, 0
_08094C7C: .4byte gUnknown_203B46C
_08094C80:
	movs r0, 0
_08094C82:
	pop {r1}
	bx r1
	thumb_func_end sub_8094C68

	thumb_func_start sub_8094C88
sub_8094C88:
	push {lr}
	ldr r0, _08094C98
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	cmp r0, 0x2
	bhi _08094C9C
	movs r0, 0x1
	b _08094CA8
	.align 2, 0
_08094C98: .4byte gUnknown_203B46C
_08094C9C:
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _08094CAA
	movs r0, 0x4
_08094CA8:
	strb r0, [r1, 0x4]
_08094CAA:
	pop {r0}
	bx r0
	thumb_func_end sub_8094C88

	thumb_func_start sub_8094CB0
sub_8094CB0:
	ldr r1, _08094CBC
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08094CBC: .4byte 0x0000ffff
	thumb_func_end sub_8094CB0

	thumb_func_start sub_8094CC0
sub_8094CC0:
	ldr r1, _08094CCC
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08094CCC: .4byte 0x0000ffff
	thumb_func_end sub_8094CC0

	thumb_func_start sub_8094CD0
sub_8094CD0:
	ldr r1, _08094CDC
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08094CDC: .4byte 0x0000ffff
	thumb_func_end sub_8094CD0

	thumb_func_start sub_8094CE0
sub_8094CE0:
	ldr r1, _08094CEC
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08094CEC: .4byte 0x0000ffff
	thumb_func_end sub_8094CE0

	thumb_func_start sub_8094CF0
sub_8094CF0:
	ldr r1, _08094CFC
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08094CFC: .4byte 0x0000ffff
	thumb_func_end sub_8094CF0

	thumb_func_start sub_8094D00
sub_8094D00:
	ldr r1, _08094D0C
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08094D0C: .4byte 0x0000ffff
	thumb_func_end sub_8094D00

	thumb_func_start sub_8094D10
sub_8094D10:
	movs r0, 0
	bx lr
	thumb_func_end sub_8094D10

	thumb_func_start sub_8094D14
sub_8094D14:
	movs r0, 0
	bx lr
	thumb_func_end sub_8094D14

	thumb_func_start sub_8094D18
sub_8094D18:
	movs r0, 0
	bx lr
	thumb_func_end sub_8094D18

	thumb_func_start sub_8094D1C
sub_8094D1C:
	movs r0, 0
	bx lr
	thumb_func_end sub_8094D1C

	thumb_func_start sub_8094D20
sub_8094D20:
	movs r0, 0
	bx lr
	thumb_func_end sub_8094D20

	thumb_func_start sub_8094D24
sub_8094D24:
	movs r0, 0
	bx lr
	thumb_func_end sub_8094D24

	thumb_func_start sub_8094D28
sub_8094D28:
	push {r4-r7,lr}
	ldr r2, _08094D64
	str r0, [r2]
	ldr r1, _08094D68
	movs r0, 0x1
	str r0, [r1]
	ldr r7, _08094D6C
	adds r5, r2, 0
	adds r4, r1, 0
	ldr r6, _08094D70
_08094D3C:
	ldr r2, [r4]
	lsls r3, r2, 2
	adds r3, r5
	subs r0, r2, 0x1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	lsrs r1, r0, 30
	eors r0, r1
	muls r0, r6
	adds r0, r2
	str r0, [r3]
	adds r2, 0x1
	str r2, [r4]
	cmp r2, r7
	ble _08094D3C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094D64: .4byte gUnknown_3001198
_08094D68: .4byte gUnknown_203B470
_08094D6C: .4byte 0x0000026f
_08094D70: .4byte 0x6c078965
	thumb_func_end sub_8094D28

	thumb_func_start sub_8094D74
sub_8094D74:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r7, r1, 0
	ldr r0, _08094E34
	bl sub_8094D28
	movs r4, 0x1
	movs r5, 0
	adds r3, r7, 0
	movs r0, 0x9C
	lsls r0, 2
	cmp r3, r0
	bge _08094D96
	adds r3, r0, 0
_08094D96:
	ldr r6, _08094E38
	cmp r3, 0
	beq _08094DE2
	mov r9, r6
	ldr r0, _08094E3C
	adds r0, r6
	mov r12, r0
	adds r2, r6, 0
_08094DA6:
	ldr r1, [r2]
	lsrs r0, r1, 30
	eors r1, r0
	ldr r0, _08094E40
	muls r0, r1
	ldr r1, [r2, 0x4]
	eors r1, r0
	lsls r0, r5, 2
	add r0, r8
	ldr r0, [r0]
	adds r1, r0
	adds r1, r5
	str r1, [r2, 0x4]
	adds r2, 0x4
	adds r4, 0x1
	adds r5, 0x1
	ldr r0, _08094E44
	cmp r4, r0
	ble _08094DD6
	mov r1, r12
	ldr r0, [r1]
	str r0, [r6]
	mov r2, r9
	movs r4, 0x1
_08094DD6:
	cmp r5, r7
	blt _08094DDC
	movs r5, 0
_08094DDC:
	subs r3, 0x1
	cmp r3, 0
	bne _08094DA6
_08094DE2:
	ldr r3, _08094E44
	ldr r5, _08094E38
	ldr r0, _08094E3C
	adds r0, r5
	mov r8, r0
	lsls r0, r4, 2
	subs r0, 0x4
	adds r2, r0, r5
	ldr r1, _08094E48
	mov r12, r1
	adds r7, r3, 0
_08094DF8:
	ldr r0, [r2]
	lsrs r1, r0, 30
	eors r0, r1
	mov r1, r12
	muls r1, r0
	ldr r0, [r2, 0x4]
	eors r0, r1
	subs r0, r4
	str r0, [r2, 0x4]
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, r7
	ble _08094E1C
	mov r1, r8
	ldr r0, [r1]
	str r0, [r6]
	adds r2, r5, 0
	movs r4, 0x1
_08094E1C:
	subs r3, 0x1
	cmp r3, 0
	bne _08094DF8
	movs r0, 0x80
	lsls r0, 24
	str r0, [r6]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094E34: .4byte 0x012bd6aa
_08094E38: .4byte gUnknown_3001198
_08094E3C: .4byte 0x000009bc
_08094E40: .4byte 0x0019660d
_08094E44: .4byte 0x0000026f
_08094E48: .4byte 0x5d588b65
	thumb_func_end sub_8094D74

	thumb_func_start sub_8094E4C
sub_8094E4C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, _08094F54
	ldr r2, [r0]
	ldr r1, _08094F58
	mov r8, r0
	cmp r2, r1
	ble _08094F1C
	ldr r0, _08094F5C
	cmp r2, r0
	bne _08094E6C
	ldr r0, _08094F60
	bl sub_8094D28
_08094E6C:
	movs r3, 0
	ldr r0, _08094F64
	mov r9, r0
	ldr r7, _08094F68
	mov r12, r9
	adds r5, r7, 0
_08094E78:
	ldr r4, [r5]
	movs r6, 0x80
	lsls r6, 24
	ands r4, r6
	ldr r0, [r5, 0x4]
	ldr r1, _08094F6C
	ands r0, r1
	orrs r4, r0
	ldr r1, _08094F70
	adds r0, r3, r1
	lsls r0, 2
	adds r0, r7
	lsrs r2, r4, 1
	ldr r1, [r0]
	eors r1, r2
	movs r0, 0x1
	ands r4, r0
	lsls r0, r4, 2
	add r0, r12
	ldr r0, [r0]
	eors r1, r0
	stm r5!, {r1}
	adds r3, 0x1
	cmp r3, 0xE2
	ble _08094E78
	ldr r5, _08094F74
	cmp r3, r5
	bgt _08094EE6
	ldr r1, _08094F68
	ldr r4, _08094F64
	mov r12, r4
	lsls r0, r3, 2
	adds r2, r0, r1
	ldr r4, _08094F78
	adds r0, r4
	adds r7, r0, r1
_08094EC0:
	ldr r4, [r2]
	ands r4, r6
	ldr r0, [r2, 0x4]
	ldr r1, _08094F6C
	ands r0, r1
	orrs r4, r0
	lsrs r0, r4, 1
	ldm r7!, {r1}
	eors r1, r0
	movs r0, 0x1
	ands r4, r0
	lsls r0, r4, 2
	add r0, r12
	ldr r0, [r0]
	eors r1, r0
	stm r2!, {r1}
	adds r3, 0x1
	cmp r3, r5
	ble _08094EC0
_08094EE6:
	ldr r2, _08094F68
	ldr r0, _08094F7C
	adds r3, r2, r0
	ldr r4, [r3]
	movs r0, 0x80
	lsls r0, 24
	ands r4, r0
	ldr r0, [r2]
	ldr r1, _08094F6C
	ands r0, r1
	orrs r4, r0
	movs r1, 0xC6
	lsls r1, 3
	adds r2, r1
	lsrs r0, r4, 1
	ldr r1, [r2]
	eors r1, r0
	movs r0, 0x1
	ands r4, r0
	lsls r0, r4, 2
	add r0, r9
	ldr r0, [r0]
	eors r1, r0
	str r1, [r3]
	movs r0, 0
	mov r4, r8
	str r0, [r4]
_08094F1C:
	ldr r2, _08094F68
	mov r0, r8
	ldr r1, [r0]
	lsls r0, r1, 2
	adds r0, r2
	ldr r4, [r0]
	adds r1, 0x1
	mov r0, r8
	str r1, [r0]
	lsrs r0, r4, 11
	eors r4, r0
	lsls r0, r4, 7
	ldr r1, _08094F80
	ands r0, r1
	eors r4, r0
	lsls r0, r4, 15
	ldr r1, _08094F84
	ands r0, r1
	eors r4, r0
	lsrs r0, r4, 18
	eors r4, r0
	adds r0, r4, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08094F54: .4byte gUnknown_203B470
_08094F58: .4byte 0x0000026f
_08094F5C: .4byte 0x00000271
_08094F60: .4byte 0x00001571
_08094F64: .4byte gUnknown_203B474
_08094F68: .4byte gUnknown_3001198
_08094F6C: .4byte 0x7fffffff
_08094F70: .4byte 0x0000018d
_08094F74: .4byte 0x0000026e
_08094F78: .4byte 0xfffffc74
_08094F7C: .4byte 0x000009bc
_08094F80: .4byte 0x9d2c5680
_08094F84: .4byte 0xefc60000
	thumb_func_end sub_8094E4C

	thumb_func_start sub_8094F88
sub_8094F88:
	push {lr}
	ldr r1, _08094F98
	ldr r0, _08094F9C
	str r0, [r1]
	bl sub_8094FA8
	pop {r0}
	bx r0
	.align 2, 0
_08094F98: .4byte gUnknown_203B47C
_08094F9C: .4byte gUnknown_2038C80
	thumb_func_end sub_8094F88

	thumb_func_start sub_8094FA0
sub_8094FA0:
	ldr r0, _08094FA4
	bx lr
	.align 2, 0
_08094FA4: .4byte gUnknown_2038C80
	thumb_func_end sub_8094FA0

	thumb_func_start sub_8094FA8
sub_8094FA8:
	movs r1, 0
	strb r1, [r0, 0x4]
	strb r1, [r0, 0x3]
	strb r1, [r0, 0x2]
	strh r1, [r0]
	bx lr
	thumb_func_end sub_8094FA8

	thumb_func_start sub_8094FB4
sub_8094FB4:
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2, 0x4]
	adds r0, 0x1
	movs r1, 0
	strb r0, [r2, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _0809500A
	strb r1, [r2, 0x4]
	ldrb r0, [r2, 0x3]
	adds r0, 0x1
	strb r0, [r2, 0x3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _0809500A
	strb r1, [r2, 0x3]
	ldrb r0, [r2, 0x2]
	adds r0, 0x1
	strb r0, [r2, 0x2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bls _0809500A
	strb r1, [r2, 0x2]
	ldrh r3, [r2]
	movs r0, 0
	ldrsh r1, [r2, r0]
	ldr r0, _08094FFC
	cmp r1, r0
	bgt _08095000
	adds r0, r3, 0x1
	b _08095008
	.align 2, 0
_08094FFC: .4byte 0x0000270e
_08095000:
	movs r0, 0x3B
	strb r0, [r2, 0x3]
	strb r0, [r2, 0x2]
	ldr r0, _08095010
_08095008:
	strh r0, [r2]
_0809500A:
	pop {r0}
	bx r0
	.align 2, 0
_08095010: .4byte 0x0000270f
	thumb_func_end sub_8094FB4

	thumb_func_start sub_8095014
sub_8095014:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	ldr r1, _08095030
	cmp r0, r1
	bgt _08095034
	str r0, [r5]
	ldrb r0, [r4, 0x2]
	str r0, [r2]
	ldrb r0, [r4, 0x3]
	b _0809503A
	.align 2, 0
_08095030: .4byte 0x0000270f
_08095034:
	str r1, [r5]
	movs r0, 0x3B
	str r0, [r2]
_0809503A:
	str r0, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8095014

	thumb_func_start sub_8095044
sub_8095044:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0809507C
	ldr r1, [r4]
	adds r1, 0x4
	movs r2, 0x6
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x3
	adds r0, r5, 0
	movs r2, 0x6
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x2
	adds r0, r5, 0
	movs r2, 0x6
	bl sub_809488C
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_809488C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809507C: .4byte gUnknown_203B47C
	thumb_func_end sub_8095044

	thumb_func_start sub_8095080
sub_8095080:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _080950B8
	ldr r1, [r4]
	adds r1, 0x4
	movs r2, 0x6
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x3
	adds r0, r5, 0
	movs r2, 0x6
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x2
	adds r0, r5, 0
	movs r2, 0x6
	bl sub_8094924
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_8094924
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080950B8: .4byte gUnknown_203B47C
	thumb_func_end sub_8095080

	thumb_func_start sub_80950BC
sub_80950BC:
	ldr r1, _080950D8
	ldr r0, _080950DC
	str r0, [r1]
	ldr r1, _080950E0
	ldr r0, _080950E4
	str r0, [r1]
	ldr r1, _080950E8
	ldr r0, _080950EC
	str r0, [r1]
	ldr r1, _080950F0
	ldr r0, _080950F4
	str r0, [r1]
	bx lr
	.align 2, 0
_080950D8: .4byte gUnknown_203B480
_080950DC: .4byte gUnknown_2038C88
_080950E0: .4byte gUnknown_203B484
_080950E4: .4byte gUnknown_2039288
_080950E8: .4byte gUnknown_203B488
_080950EC: .4byte gUnknown_20392E8
_080950F0: .4byte gUnknown_203B48C
_080950F4: .4byte gUnknown_20393C0
	thumb_func_end sub_80950BC

	thumb_func_start sub_80950F8
sub_80950F8:
	ldr r0, _080950FC
	bx lr
	.align 2, 0
_080950FC: .4byte gUnknown_2038C88
	thumb_func_end sub_80950F8

	thumb_func_start sub_8095100
sub_8095100:
	ldr r0, _08095104
	bx lr
	.align 2, 0
_08095104: .4byte gUnknown_2039288
	thumb_func_end sub_8095100

	thumb_func_start sub_8095108
sub_8095108:
	ldr r0, _0809510C
	bx lr
	.align 2, 0
_0809510C: .4byte gUnknown_20392E8
	thumb_func_end sub_8095108

	thumb_func_start sub_8095110
sub_8095110:
	ldr r0, _08095114
	bx lr
	.align 2, 0
_08095114: .4byte gUnknown_20393C0
	thumb_func_end sub_8095110

	thumb_func_start sub_8095118
sub_8095118:
	push {r4,lr}
	ldr r4, _0809517C
	ldr r0, [r4]
	movs r2, 0xC0
	lsls r2, 3
	movs r1, 0
	bl MemoryFill8
	ldr r0, _08095180
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	movs r2, 0
	movs r1, 0
	movs r3, 0x1F
_0809513A:
	ldr r0, [r4]
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x22
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x2D
	strb r2, [r0]
	adds r1, 0x30
	subs r3, 0x1
	cmp r3, 0
	bge _0809513A
	ldr r2, _08095184
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1]
	movs r3, 0
	movs r4, 0x1
	negs r4, r4
_08095166:
	ldr r0, [r2]
	lsls r1, r3, 2
	adds r0, 0x4
	adds r0, r1
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1F
	ble _08095166
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809517C: .4byte gUnknown_203B480
_08095180: .4byte gUnknown_203B484
_08095184: .4byte gUnknown_203B48C
	thumb_func_end sub_8095118

	thumb_func_start nullsub_206
nullsub_206:
	bx lr
	thumb_func_end nullsub_206

	thumb_func_start nullsub_207
nullsub_207:
	bx lr
	thumb_func_end nullsub_207

	thumb_func_start sub_8095190
sub_8095190:
	push {lr}
	movs r2, 0x2
	ldr r0, _080951A8
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x60
_0809519C:
	ldrb r0, [r1]
	cmp r0, 0
	bne _080951AC
	adds r0, r2, 0
	b _080951B8
	.align 2, 0
_080951A8: .4byte gUnknown_203B480
_080951AC:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _0809519C
	movs r0, 0x1
	negs r0, r0
_080951B8:
	pop {r1}
	bx r1
	thumb_func_end sub_8095190

	thumb_func_start sub_80951BC
sub_80951BC:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8095190
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080951F4
	ldr r0, _080951F0
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r1, r0
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	b _080951F6
	.align 2, 0
_080951F0: .4byte gUnknown_203B480
_080951F4:
	movs r0, 0
_080951F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80951BC

	thumb_func_start sub_80951FC
sub_80951FC:
	push {r4,r5,lr}
	ldr r1, _08095224
	ldr r1, [r1]
	adds r1, 0x30
	ldrb r2, [r1]
	negs r3, r2
	orrs r3, r2
	lsrs r3, 31
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	adds r0, r3, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08095224: .4byte gUnknown_203B480
	thumb_func_end sub_80951FC

	thumb_func_start sub_8095228
sub_8095228:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _0809523C
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_0809523C: .4byte gUnknown_203B480
	thumb_func_end sub_8095228

	thumb_func_start sub_8095240
sub_8095240:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, _08095270
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 4
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	adds r0, 0x22
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08095270: .4byte gUnknown_203B480
	thumb_func_end sub_8095240

	thumb_func_start sub_8095274
sub_8095274:
	push {lr}
	ldr r1, _08095294
	ldr r3, [r1]
	adds r2, r3, 0
	ldm r2!, {r1}
	lsls r1, 2
	adds r2, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0
	cmp r0, 0x1E
	bgt _0809528E
	adds r1, r0, 0x1
_0809528E:
	str r1, [r3]
	pop {r0}
	bx r0
	.align 2, 0
_08095294: .4byte gUnknown_203B48C
	thumb_func_end sub_8095274

	thumb_func_start sub_8095298
sub_8095298:
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, _080952B0
	ldr r0, [r0]
	adds r1, r0, 0x4
_080952A4:
	ldr r0, [r1]
	cmp r0, r3
	bne _080952B4
	movs r0, 0x1
	b _080952BE
	.align 2, 0
_080952B0: .4byte gUnknown_203B48C
_080952B4:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, 0x1F
	ble _080952A4
	movs r0, 0
_080952BE:
	pop {r1}
	bx r1
	thumb_func_end sub_8095298

	thumb_func_start sub_80952C4
sub_80952C4:
	push {r4,lr}
	ldr r2, _080952EC
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1]
	movs r3, 0
	adds r4, r2, 0
	movs r2, 0x1
	negs r2, r2
_080952D6:
	ldr r0, [r4]
	lsls r1, r3, 2
	adds r0, 0x4
	adds r0, r1
	str r2, [r0]
	adds r3, 0x1
	cmp r3, 0x1F
	ble _080952D6
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080952EC: .4byte gUnknown_203B48C
	thumb_func_end sub_80952C4

	thumb_func_start sub_80952F0
sub_80952F0:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	movs r3, 0
	ldr r0, _08095310
	ldr r2, [r0]
_080952FE:
	ldrb r0, [r2]
	cmp r0, r1
	bne _08095314
	ldr r0, [r2, 0x10]
	cmp r0, r4
	bne _08095314
	movs r0, 0x1
	b _0809531E
	.align 2, 0
_08095310: .4byte gUnknown_203B480
_08095314:
	adds r2, 0x30
	adds r3, 0x1
	cmp r3, 0x1F
	ble _080952FE
	movs r0, 0
_0809531E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80952F0

	thumb_func_start sub_8095324
sub_8095324:
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, _0809534C
	ldr r1, [r0]
	movs r2, 0x1F
_08095332:
	ldrb r0, [r1]
	cmp r0, r4
	bne _0809533A
	adds r3, 0x1
_0809533A:
	adds r1, 0x30
	subs r2, 0x1
	cmp r2, 0
	bge _08095332
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809534C: .4byte gUnknown_203B480
	thumb_func_end sub_8095324

	thumb_func_start sub_8095350
sub_8095350:
	push {lr}
	movs r3, 0
	ldr r0, _08095370
	ldr r1, [r0]
	movs r2, 0x1F
_0809535A:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08095362
	adds r3, 0x1
_08095362:
	adds r1, 0x30
	subs r2, 0x1
	cmp r2, 0
	bge _0809535A
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_08095370: .4byte gUnknown_203B480
	thumb_func_end sub_8095350

	thumb_func_start sub_8095374
sub_8095374:
	push {lr}
	movs r3, 0x1
	negs r3, r3
	movs r2, 0
	ldr r0, _08095398
	ldr r1, [r0]
_08095380:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08095388
	adds r3, r2, 0
_08095388:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _08095380
	adds r0, r3, 0
	pop {r1}
	bx r1
	.align 2, 0
_08095398: .4byte gUnknown_203B480
	thumb_func_end sub_8095374

	thumb_func_start sub_809539C
sub_809539C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r1, r0, 24
	movs r3, 0
	ldr r0, _080953BC
	ldr r2, [r0]
_080953AA:
	ldrb r0, [r2]
	cmp r0, r1
	bne _080953C0
	ldr r0, [r2, 0x10]
	cmp r0, r4
	bne _080953C0
	adds r0, r3, 0
	b _080953CC
	.align 2, 0
_080953BC: .4byte gUnknown_203B480
_080953C0:
	adds r2, 0x30
	adds r3, 0x1
	cmp r3, 0x1F
	ble _080953AA
	movs r0, 0x1
	negs r0, r0
_080953CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809539C

	thumb_func_start sub_80953D4
sub_80953D4:
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, _080953EC
	ldr r1, [r0]
_080953E0:
	ldrb r0, [r1]
	cmp r0, r3
	bne _080953F0
	adds r0, r2, 0
	b _080953FC
	.align 2, 0
_080953EC: .4byte gUnknown_203B480
_080953F0:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _080953E0
	movs r0, 0x1
	negs r0, r0
_080953FC:
	pop {r1}
	bx r1
	thumb_func_end sub_80953D4

	thumb_func_start sub_8095400
sub_8095400:
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r0, _08095418
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x10
_0809540E:
	ldr r0, [r1]
	cmp r0, r3
	bne _0809541C
	adds r0, r2, 0
	b _08095428
	.align 2, 0
_08095418: .4byte gUnknown_203B480
_0809541C:
	adds r1, 0x30
	adds r2, 0x1
	cmp r2, 0x1F
	ble _0809540E
	movs r0, 0x1
	negs r0, r0
_08095428:
	pop {r1}
	bx r1
	thumb_func_end sub_8095400

	thumb_func_start sub_809542C
sub_809542C:
	push {r4,lr}
	sub sp, 0x14
	ldr r4, _08095490
	ldr r2, [r4]
	movs r1, 0x1
	strb r1, [r2]
	ldr r2, [r4]
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2, 0x4]
	str r1, [r2, 0x8]
	bl Random
	bl sub_8094D28
	bl sub_8094E4C
	ldr r1, [r4]
	str r0, [r1, 0x10]
	bl sub_808D33C
	ldr r1, [r4]
	ldrh r0, [r0, 0x8]
	strh r0, [r1, 0xC]
	bl sub_808D33C
	adds r1, r0, 0
	mov r0, sp
	bl sub_808DA34
	ldr r0, [r4]
	adds r0, 0x14
	mov r1, sp
	bl sub_80922F4
	bl sub_8011C34
	ldr r1, [r4]
	str r0, [r1, 0x24]
	ldrb r0, [r1, 0x4]
	bl GetUnk3
	ldr r1, [r4]
	adds r1, 0x2C
	strb r0, [r1]
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095490: .4byte gUnknown_203B480
	thumb_func_end sub_809542C

	thumb_func_start sub_8095494
sub_8095494:
	lsls r1, 24
	lsrs r1, 24
	ldr r2, _080954B0
	ldr r3, [r2]
	lsls r2, r1, 1
	adds r2, r1
	lsls r2, 4
	adds r3, r2
	ldr r1, [r3, 0x4]
	ldr r2, [r3, 0x8]
	str r1, [r0]
	str r2, [r0, 0x4]
	bx lr
	.align 2, 0
_080954B0: .4byte gUnknown_203B480
	thumb_func_end sub_8095494

	thumb_func_start sub_80954B4
sub_80954B4:
	push {lr}
	movs r0, 0x3
	bl sub_8095324
	cmp r0, 0
	bne _080954C4
	movs r0, 0
	b _080954C6
_080954C4:
	movs r0, 0x1
_080954C6:
	pop {r1}
	bx r1
	thumb_func_end sub_80954B4

	thumb_func_start sub_80954CC
sub_80954CC:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	ldr r6, _08095618
	movs r5, 0
	movs r4, 0x1F
_080954E2:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8095774
	adds r5, 0x30
	subs r4, 0x1
	cmp r4, 0
	bge _080954E2
	ldr r4, _0809561C
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
	ldr r5, [r4]
	adds r4, r5, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x58
	bl memset
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_8094924
	adds r1, r5, 0x6
	mov r0, sp
	movs r2, 0x1
	bl sub_8094924
	adds r1, r5, 0x7
	mov r0, sp
	movs r2, 0x7
	bl sub_8094924
	adds r4, 0x4
	mov r0, sp
	adds r1, r4, 0
	bl sub_8090314
	adds r1, r5, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x10
	mov r0, sp
	bl sub_808F410
	adds r1, r5, 0
	adds r1, 0x14
	mov r0, sp
	bl sub_808F410
	adds r1, r5, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1A
	mov r0, sp
	movs r2, 0xA
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1C
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1D
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1E
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x1F
	mov r0, sp
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x20
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x24
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x28
	mov r0, sp
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x2C
	mov r0, sp
	bl sub_8091DC0
	adds r1, r5, 0
	adds r1, 0x30
	mov r0, sp
	bl sub_8094128
	adds r1, r5, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x50
	bl sub_8094924
	ldr r4, _08095620
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
	adds r6, r4, 0
	movs r5, 0x4
	movs r4, 0x1F
_080955F4:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _080955F4
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095618: .4byte gUnknown_203B480
_0809561C: .4byte gUnknown_203B484
_08095620: .4byte gUnknown_203B48C
	thumb_func_end sub_80954CC

	thumb_func_start sub_8095624
sub_8095624:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	ldr r6, _08095768
	movs r5, 0
	movs r4, 0x1F
_0809563A:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8095824
	adds r5, 0x30
	subs r4, 0x1
	cmp r4, 0
	bge _0809563A
	ldr r4, _0809576C
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
	ldr r5, [r4]
	adds r4, r5, 0x4
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_809488C
	adds r1, r5, 0x6
	mov r0, sp
	movs r2, 0x1
	bl sub_809488C
	adds r1, r5, 0x7
	mov r0, sp
	movs r2, 0x7
	bl sub_809488C
	adds r4, 0x4
	mov r0, sp
	adds r1, r4, 0
	bl sub_80902F4
	adds r1, r5, 0
	adds r1, 0xC
	mov r0, sp
	movs r2, 0x9
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x10
	mov r0, sp
	bl sub_808F41C
	adds r1, r5, 0
	adds r1, 0x14
	mov r0, sp
	bl sub_808F41C
	adds r1, r5, 0
	adds r1, 0x18
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1A
	mov r0, sp
	movs r2, 0xA
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1C
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1D
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1E
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x1F
	mov r0, sp
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x20
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x24
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x28
	mov r0, sp
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x2C
	mov r0, sp
	bl sub_8091DE0
	adds r1, r5, 0
	adds r1, 0x30
	mov r0, sp
	bl sub_8094108
	adds r1, r5, 0
	adds r1, 0x50
	mov r0, sp
	movs r2, 0x50
	bl sub_809488C
	ldr r4, _08095770
	ldr r1, [r4]
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
	adds r6, r4, 0
	movs r5, 0x4
	movs r4, 0x1F
_08095742:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08095742
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095768: .4byte gUnknown_203B480
_0809576C: .4byte gUnknown_203B484
_08095770: .4byte gUnknown_203B48C
	thumb_func_end sub_8095624

	thumb_func_start sub_8095774
sub_8095774:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl sub_8090314
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	movs r2, 0x20
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x14
	adds r0, r4, 0
	movs r2, 0x50
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x20
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x21
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x22
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x24
	adds r0, r4, 0
	movs r2, 0x20
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x28
	adds r0, r4, 0
	movs r2, 0x20
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x2C
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x2D
	strb r0, [r1]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8095774

	thumb_func_start sub_8095824
sub_8095824:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0xFF
	mov r0, sp
	strb r1, [r0]
	mov r6, sp
	adds r6, 0x1
	movs r0, 0
	strb r0, [r6]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r4, 0x4
	adds r0, r5, 0
	bl sub_80902F4
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x18
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x10
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0x50
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x21
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x22
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x24
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x28
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	adds r1, r4, 0
	adds r1, 0x2C
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_809488C
	adds r0, r4, 0
	adds r0, 0x2D
	ldrb r0, [r0]
	mov r1, sp
	cmp r0, 0
	bne _080958D2
	adds r1, r6, 0
_080958D2:
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_809488C
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8095824

	thumb_func_start sub_80958E4
sub_80958E4:
	str r1, [r0]
	bx lr
	thumb_func_end sub_80958E4

	thumb_func_start sub_80958E8
sub_80958E8:
	ldr r1, _080958F0
	ldr r0, _080958F4
	str r0, [r1]
	bx lr
	.align 2, 0
_080958F0: .4byte gUnknown_203B490
_080958F4: .4byte gUnknown_2039448
	thumb_func_end sub_80958E8

	thumb_func_start sub_80958F8
sub_80958F8:
	ldr r0, _080958FC
	bx lr
	.align 2, 0
_080958FC: .4byte gUnknown_2039448
	thumb_func_end sub_80958F8

	thumb_func_start sub_8095900
sub_8095900:
	push {r4-r7,lr}
	movs r4, 0
_08095904:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096040
	adds r4, 0x1
	cmp r4, 0x3
	ble _08095904
	movs r4, 0
_08095914:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80965B8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08095914
	movs r4, 0
_08095924:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096C3C
	adds r4, 0x1
	cmp r4, 0x7
	ble _08095924
	movs r4, 0
	ldr r3, _080959B8
	movs r2, 0xBC
	lsls r2, 2
	movs r1, 0
_0809593C:
	ldr r0, [r3]
	adds r0, r2
	adds r0, r4
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x37
	ble _0809593C
	ldr r4, _080959B8
	ldr r0, [r4]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r4]
	movs r7, 0xC8
	lsls r7, 1
	adds r0, r7
	movs r1, 0x28
	bl MemoryClear8
	ldr r0, [r4]
	movs r1, 0xDC
	lsls r1, 1
	adds r0, r1
	movs r1, 0x78
	bl MemoryClear8
	adds r3, r4, 0
	movs r5, 0
	movs r2, 0
	movs r6, 0x8C
	lsls r6, 2
	movs r4, 0xF
_08095980:
	ldr r0, [r3]
	adds r0, r2
	adds r0, r6
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, r2
	ldr r7, _080959BC
	adds r0, r7
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, [r3]
	adds r7, 0x3
	adds r0, r1, r7
	adds r0, r2
	str r5, [r0]
	adds r7, 0x4
	adds r0, r1, r7
	adds r0, r2
	str r5, [r0]
	adds r2, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _08095980
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080959B8: .4byte gUnknown_203B490
_080959BC: .4byte 0x00000231
	thumb_func_end sub_8095900

	thumb_func_start sub_80959C0
sub_80959C0:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x5
	bne _080959D6
	adds r0, r1, 0
	bl sub_80959DC
	lsls r0, 24
	lsrs r0, 24
	b _080959D8
_080959D6:
	movs r0, 0
_080959D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80959C0

	thumb_func_start sub_80959DC
sub_80959DC:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrb r0, [r5, 0x1]
	cmp r0, 0x4
	bls _080959E8
	b _08095B16
_080959E8:
	cmp r0, 0x4
	bne _080959F8
	ldrb r0, [r5, 0x4]
	bl GetMaxItemCount
	cmp r0, 0
	bne _080959F8
	b _08095B16
_080959F8:
	ldrb r0, [r5, 0x2]
	cmp r0, 0x9
	bls _08095A00
	b _08095B16
_08095A00:
	ldrb r0, [r5, 0x4]
	bl sub_809095C
	lsls r0, 24
	cmp r0, 0
	beq _08095A0E
	b _08095B16
_08095A0E:
	ldrb r4, [r5, 0x5]
	ldrb r0, [r5, 0x4]
	bl sub_8090298
	cmp r4, r0
	bge _08095B16
	adds r4, r5, 0x4
	adds r0, r4, 0
	bl sub_809017C
	lsls r0, 24
	adds r6, r4, 0
	cmp r0, 0
	bne _08095B16
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08095B16
	ldr r4, _08095B1C
	cmp r0, r4
	bgt _08095B16
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	bl sub_808E770
	movs r2, 0xC
	ldrsh r1, [r5, r2]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _08095B16
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	bl sub_803C0DC
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	cmp r0, r4
	bgt _08095B16
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	bl sub_808E770
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	lsls r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _08095B16
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	bl sub_803C0DC
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
	ldrb r0, [r5, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08095A9C
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _08095B16
_08095A9C:
	ldrb r0, [r5, 0x10]
	bl sub_8092040
	lsls r0, 24
	cmp r0, 0
	bne _08095B16
	ldrb r0, [r5, 0x10]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08095B16
	ldrb r0, [r5, 0x10]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
	ldrb r0, [r5, 0x1]
	cmp r0, 0x3
	bne _08095AD4
	ldrb r0, [r5, 0x4]
	ldrb r1, [r5, 0x10]
	bl sub_8091E60
	lsls r0, 24
	cmp r0, 0
	beq _08095B16
_08095AD4:
	ldrb r0, [r5, 0x11]
	cmp r0, 0x4
	beq _08095B16
	cmp r0, 0xA
	beq _08095B16
	cmp r0, 0xA
	bhi _08095B16
	ldrb r0, [r5, 0x12]
	bl sub_8092040
	lsls r0, 24
	cmp r0, 0
	bne _08095B16
	ldrb r0, [r5, 0x13]
	cmp r0, 0x39
	bhi _08095B16
	ldrb r0, [r5, 0x11]
	cmp r0, 0x9
	bne _08095B20
	ldrb r0, [r5, 0x13]
	bl sub_8092534
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08095B16
	ldrb r1, [r5, 0x1]
	adds r0, r6, 0
	bl sub_803C1D0
	lsls r0, 24
	cmp r0, 0
	bne _08095B20
_08095B16:
	movs r0, 0
	b _08095B22
	.align 2, 0
_08095B1C: .4byte 0x000001a7
_08095B20:
	movs r0, 0x1
_08095B22:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80959DC

	thumb_func_start sub_8095B28
sub_8095B28:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _08095B44
	add sp, r4
	adds r4, r0, 0
	bl sub_8095CE0
	lsls r0, 24
	cmp r0, 0
	bne _08095B48
	movs r0, 0
	b _08095CCC
	.align 2, 0
_08095B44: .4byte 0xfffffcb0
_08095B48:
	movs r0, 0x5
	strb r0, [r4]
	movs r0, 0x8
	bl RandomCapped
	ldr r1, _08095BC8
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _08095B6C
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095B6C
	strb r0, [r4, 0x1]
_08095B6C:
	movs r0, 0
	strb r0, [r4, 0x2]
	bl Random
	ldr r1, _08095BCC
	ands r1, r0
	str r1, [r4, 0x8]
	movs r7, 0
	movs r5, 0x1
	adds r0, r4, 0x4
	mov r8, r0
	movs r1, 0x12
	adds r1, r4
	mov r9, r1
	mov r6, sp
_08095B8A:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _08095B9E
	strh r5, [r6]
	adds r6, 0x2
	adds r7, 0x1
_08095B9E:
	adds r5, 0x1
	ldr r0, _08095BD0
	cmp r5, r0
	ble _08095B8A
	cmp r7, 0
	beq _08095BD4
	adds r0, r7, 0
	bl RandomCapped
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0xC]
	adds r0, r7, 0
	bl RandomCapped
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	b _08095BDC
	.align 2, 0
_08095BC8: .4byte gUnknown_8109984
_08095BCC: .4byte 0x00ffffff
_08095BD0: .4byte 0x000001a7
_08095BD4:
	movs r0, 0x10
	strh r0, [r4, 0xC]
	movs r0, 0x91
	lsls r0, 1
_08095BDC:
	strh r0, [r4, 0xE]
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08095BEE
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095BEE:
	ldrb r0, [r4, 0x4]
	bl sub_8095F28
	strb r0, [r4, 0x10]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095C10
	strb r0, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x10
	mov r0, r8
	movs r1, 0
	bl sub_803C37C
_08095C10:
	ldrb r0, [r4, 0x4]
	bl GetMaxItemCount
	adds r1, r0, 0
	cmp r1, 0
	bne _08095C28
	ldrb r0, [r4, 0x1]
	cmp r0, 0x4
	bne _08095C28
	strb r1, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095C28:
	ldrb r1, [r4, 0x1]
	mov r0, r8
	mov r2, r9
	bl sub_803C37C
	ldrb r0, [r4, 0x10]
	ldrb r1, [r4, 0x12]
	cmp r0, r1
	beq _08095C28
	movs r0, 0
	strb r0, [r4, 0x13]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	beq _08095C90
	cmp r0, 0x2
	bgt _08095C4E
	cmp r0, 0x1
	beq _08095C6C
	b _08095CCA
_08095C4E:
	cmp r0, 0x4
	bgt _08095CCA
	bl Random
	adds r1, r0, 0
	movs r0, 0xE0
	lsls r0, 3
	ands r1, r0
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _08095CC4
	cmp r1, r0
	bgt _08095CB4
	b _08095CAA
_08095C6C:
	bl Random
	adds r1, r0, 0
	movs r0, 0x70
	ands r1, r0
	cmp r1, 0x10
	beq _08095C80
	cmp r1, 0x30
	beq _08095C88
	b _08095CCA
_08095C80:
	adds r0, r4, 0
	bl sub_803C3E0
	b _08095CCA
_08095C88:
	adds r0, r4, 0
	bl sub_803C45C
	b _08095CCA
_08095C90:
	bl Random
	movs r1, 0xC0
	lsls r1, 6
	ands r1, r0
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _08095CCA
	adds r0, r4, 0
	bl sub_803C4F0
	b _08095CCA
_08095CAA:
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _08095CBC
	b _08095CCA
_08095CB4:
	movs r0, 0xC0
	lsls r0, 3
	cmp r1, r0
	bne _08095CCA
_08095CBC:
	adds r0, r4, 0
	bl sub_803C580
	b _08095CCA
_08095CC4:
	adds r0, r4, 0
	bl sub_803C610
_08095CCA:
	movs r0, 0x1
_08095CCC:
	movs r3, 0xD4
	lsls r3, 2
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095B28

	thumb_func_start sub_8095CE0
sub_8095CE0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x60
	str r0, [sp, 0x44]
	mov r0, sp
	bl sub_80A29B0
	str r0, [sp, 0x4C]
	cmp r0, 0
	bne _08095D0C
	mov r0, sp
	add r1, sp, 0x4C
	ldrb r1, [r1]
	strb r1, [r0]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r2, 0x2
	str r2, [sp, 0x4C]
_08095D0C:
	ldr r0, [sp, 0x4C]
	bl RandomCapped
	mov r9, r0
	str r0, [sp, 0x48]
	mov r1, sp
	adds r1, 0x40
	str r1, [sp, 0x5C]
_08095D1C:
	mov r0, sp
	add r0, r9
	ldrb r7, [r0]
	adds r0, r7, 0
	bl sub_8090298
	str r0, [sp, 0x58]
	lsrs r0, 31
	ldr r2, [sp, 0x58]
	adds r0, r2, r0
	asrs r0, 1
	str r0, [sp, 0x54]
	adds r1, r2, 0
	bl RandomRange
	adds r4, r0, 0
	str r4, [sp, 0x50]
_08095D3E:
	movs r0, 0x1
	mov r8, r0
	ldr r1, _08095DF4
	ldr r0, [sp, 0x40]
	ands r0, r1
	orrs r0, r7
	lsls r2, r4, 24
	lsrs r2, 16
	ldr r1, _08095DF8
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x40]
	ldr r0, [sp, 0x5C]
	bl sub_809017C
	lsls r0, 24
	cmp r0, 0
	beq _08095D66
	movs r1, 0
	mov r8, r1
_08095D66:
	ldr r2, _08095DFC
	mov r10, r2
	movs r6, 0
	movs r5, 0x3
_08095D6E:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095D88
	movs r2, 0
	mov r8, r2
_08095D88:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095D6E
	ldr r0, _08095DFC
	mov r10, r0
	movs r6, 0x50
	movs r5, 0x7
_08095D98:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095DB2
	movs r2, 0
	mov r8, r2
_08095DB2:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095D98
	ldr r0, _08095DFC
	mov r10, r0
	movs r6, 0xF0
	movs r5, 0x7
_08095DC2:
	mov r1, r10
	ldr r0, [r1]
	adds r0, r6
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	beq _08095DDC
	movs r2, 0
	mov r8, r2
_08095DDC:
	adds r6, 0x14
	subs r5, 0x1
	cmp r5, 0
	bge _08095DC2
	mov r0, r8
	cmp r0, 0
	beq _08095E00
	ldr r1, [sp, 0x44]
	strb r7, [r1, 0x4]
	strb r4, [r1, 0x5]
	movs r0, 0x1
	b _08095E28
	.align 2, 0
_08095DF4: .4byte 0xffffff00
_08095DF8: .4byte 0xffff00ff
_08095DFC: .4byte gUnknown_203B490
_08095E00:
	adds r4, 0x1
	ldr r2, [sp, 0x58]
	cmp r4, r2
	blt _08095E0A
	ldr r4, [sp, 0x54]
_08095E0A:
	ldr r0, [sp, 0x50]
	cmp r4, r0
	bne _08095D3E
	movs r1, 0x1
	add r9, r1
	ldr r2, [sp, 0x4C]
	cmp r9, r2
	bne _08095E1E
	movs r0, 0
	mov r9, r0
_08095E1E:
	ldr r1, [sp, 0x48]
	cmp r9, r1
	beq _08095E26
	b _08095D1C
_08095E26:
	movs r0, 0
_08095E28:
	add sp, 0x60
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095CE0

	thumb_func_start sub_8095E38
sub_8095E38:
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4]
	cmp r0, 0
	beq _08095E6E
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _08095E5E
	cmp r3, 0x1
	bne _08095E5E
	ldrb r0, [r4, 0x4]
	cmp r0, r1
	bne _08095E6E
	movs r0, 0x1
	b _08095E70
_08095E5E:
	ldrb r0, [r4, 0x4]
	cmp r0, r1
	bne _08095E6E
	ldrb r0, [r4, 0x5]
	cmp r0, r2
	bne _08095E6E
	movs r0, 0x1
	b _08095E70
_08095E6E:
	movs r0, 0
_08095E70:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E38

	thumb_func_start sub_8095E78
sub_8095E78:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x3C
	movs r6, 0
	movs r5, 0x1
_08095E84:
	ldr r0, _08095F04
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	adds r1, r5, 0x1
	mov r8, r1
	cmp r0, 0
	bne _08095EF6
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_8092534
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08095EF6
	movs r4, 0
	ldr r0, _08095F08
	ldr r1, [r0]
	movs r3, 0x3
_08095EAC:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08095EBA
	ldrb r0, [r1, 0x11]
	cmp r0, 0x9
	bne _08095EBA
	movs r4, 0x1
_08095EBA:
	adds r1, 0x14
	subs r3, 0x1
	cmp r3, 0
	bge _08095EAC
	ldr r0, _08095F08
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xF0
	adds r1, r0, 0
	movs r3, 0x7
_08095ECE:
	ldrb r0, [r2]
	cmp r0, 0
	beq _08095EE0
	ldr r7, _08095F0C
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, 0x9
	bne _08095EE0
	movs r4, 0x1
_08095EE0:
	adds r2, 0x14
	adds r1, 0x14
	subs r3, 0x1
	cmp r3, 0
	bge _08095ECE
	cmp r4, 0
	bne _08095EF6
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	adds r6, 0x1
_08095EF6:
	mov r5, r8
	cmp r5, 0x39
	ble _08095E84
	cmp r6, 0
	bne _08095F10
	movs r0, 0
	b _08095F1A
	.align 2, 0
_08095F04: .4byte gUnknown_203B468
_08095F08: .4byte gUnknown_203B490
_08095F0C: .4byte 0x00000101
_08095F10:
	adds r0, r6, 0
	bl RandomCapped
	add r0, sp
	ldrb r0, [r0]
_08095F1A:
	add sp, 0x3C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095E78

	thumb_func_start sub_8095F28
sub_8095F28:
	push {r4-r7,lr}
	sub sp, 0xF0
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
	movs r5, 0x1
_08095F34:
	lsls r4, r5, 24
	cmp r7, 0x63
	beq _08095F48
	lsrs r1, r4, 24
	adds r0, r7, 0
	bl sub_8091E60
	lsls r0, 24
	cmp r0, 0
	beq _08095F6A
_08095F48:
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	bne _08095F6A
	adds r0, r4, 0
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _08095F6A
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	adds r6, 0x1
_08095F6A:
	adds r5, 0x1
	cmp r5, 0xEF
	ble _08095F34
	cmp r6, 0
	beq _08095F80
	adds r0, r6, 0
	bl RandomCapped
	add r0, sp
	ldrb r0, [r0]
	b _08095F82
_08095F80:
	movs r0, 0
_08095F82:
	add sp, 0xF0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F28

	thumb_func_start sub_8095F8C
sub_8095F8C:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_08095F92:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096000
	lsls r0, 24
	cmp r0, 0
	bne _08095FA2
	adds r5, 0x1
_08095FA2:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08095F92
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095F8C

	thumb_func_start sub_8095FB0
sub_8095FB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _08095FD4
	movs r2, 0
_08095FBA:
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _08095FD8
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	b _08095FE2
	.align 2, 0
_08095FD4: .4byte gUnknown_203B490
_08095FD8:
	adds r2, 0x14
	adds r3, 0x1
	cmp r3, 0x3
	ble _08095FBA
	movs r0, 0x1
_08095FE2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8095FB0

	thumb_func_start sub_8095FE8
sub_8095FE8:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _08095FFC
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_08095FFC: .4byte gUnknown_203B490
	thumb_func_end sub_8095FE8

	thumb_func_start sub_8096000
sub_8096000:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0809601C
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	ldrb r0, [r2]
	cmp r0, 0
	beq _08096020
	movs r0, 0
	b _08096022
	.align 2, 0
_0809601C: .4byte gUnknown_203B490
_08096020:
	movs r0, 0x1
_08096022:
	pop {r1}
	bx r1
	thumb_func_end sub_8096000

	thumb_func_start sub_8096028
sub_8096028:
	push {r4,lr}
	movs r4, 0
_0809602C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096040
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809602C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8096028

	thumb_func_start sub_8096040
sub_8096040:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, _08096074
	ldr r1, [r3]
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	movs r4, 0
	strb r4, [r1]
	ldr r0, [r3]
	adds r0, r2
	movs r1, 0x63
	strb r1, [r0, 0x4]
	ldr r0, [r3]
	adds r0, r2
	strb r4, [r0, 0x5]
	ldr r0, [r3]
	adds r0, r2
	movs r1, 0x5
	strb r1, [r0, 0x11]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096074: .4byte gUnknown_203B490
	thumb_func_end sub_8096040

	thumb_func_start sub_8096078
sub_8096078:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _08096090
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _080960B6
	.align 2, 0
_08096090: .4byte gUnknown_203B490
_08096094:
	cmp r2, r3
	ble _080960AA
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_080960AA:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_080960B6:
	cmp r2, 0x3
	bgt _080960E2
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080960E2
	ldr r6, _08096110
	mov r1, r9
_080960CA:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080960E2
	ldr r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080960CA
_080960E2:
	cmp r2, 0x4
	bne _08096094
	cmp r3, 0x3
	bgt _08096102
	ldr r4, _08096110
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_080960F4:
	ldr r0, [r4]
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x3
	ble _080960F4
_08096102:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096110: .4byte gUnknown_203B490
	thumb_func_end sub_8096078

	thumb_func_start sub_8096114
sub_8096114:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r1, 0
_08096122:
	adds r0, r1, 0x1
	mov r10, r0
	mov r8, r10
	cmp r0, 0x3
	bgt _08096198
	ldr r2, _080961B0
	mov r9, r2
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r12, r0
	mov r3, r10
	lsls r0, r3, 2
	add r0, r10
	lsls r4, r0, 2
_08096140:
	mov r5, r9
	ldr r1, [r5]
	adds r3, r1, r4
	ldrb r0, [r3]
	cmp r0, 0
	beq _0809618C
	mov r6, r12
	adds r2, r1, r6
	ldrb r1, [r2, 0x4]
	ldrb r0, [r3, 0x4]
	cmp r1, r0
	bhi _08096164
	cmp r1, r0
	bne _0809618C
	ldrb r0, [r2, 0x5]
	ldrb r7, [r3, 0x5]
	cmp r0, r7
	bls _0809618C
_08096164:
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5,r6}
	stm r1!, {r5,r6}
	adds r1, r2, 0
	adds r0, r3, 0
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5,r6}
	stm r1!, {r5,r6}
	mov r7, r9
	ldr r1, [r7]
	adds r1, r4
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_0809618C:
	adds r4, 0x14
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x3
	ble _08096140
_08096198:
	mov r1, r10
	cmp r1, 0x2
	ble _08096122
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080961B0: .4byte gUnknown_203B490
	thumb_func_end sub_8096114

	thumb_func_start sub_80961B4
sub_80961B4:
	push {lr}
	bl sub_8096E2C
	lsls r0, 24
	cmp r0, 0
	beq _080961CE
	ldr r0, _080961D4
	ldr r0, [r0]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_080961CE:
	pop {r0}
	bx r0
	.align 2, 0
_080961D4: .4byte gUnknown_203B490
	thumb_func_end sub_80961B4

	thumb_func_start sub_80961D8
sub_80961D8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	bl sub_8095F8C
	adds r6, r0, 0
	movs r1, 0x4
	bl RandomRange
	mov r8, r0
	cmp r6, 0x3
	bgt _08096202
	ldr r4, _08096208
	ldr r0, [r4]
	movs r2, 0xCA
	lsls r2, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _0809620C
_08096202:
	movs r0, 0
	b _080963A8
	.align 2, 0
_08096208: .4byte gUnknown_203B490
_0809620C:
	strb r7, [r1]
	movs r5, 0x38
	movs r0, 0xA
	movs r1, 0x31
	movs r2, 0x1
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _0809623A
	ldr r0, [r4]
	ldr r1, _08096328
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809623A
	movs r0, 0x35
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809623A
	movs r5, 0x35
_0809623A:
	movs r0, 0xF
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809629C
	ldr r0, _0809632C
	ldr r0, [r0]
	movs r2, 0xC9
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096264
	movs r0, 0x34
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _08096264
	movs r5, 0x34
_08096264:
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r1, _08096330
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096280
	movs r0, 0x33
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _08096280
	movs r5, 0x33
_08096280:
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r2, _08096334
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809629C
	movs r0, 0x32
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809629C
	movs r5, 0x32
_0809629C:
	bl sub_8092178
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _080962C4
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r1, _08096338
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080962C4
	movs r0, 0x36
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080962C4
	movs r5, 0x36
_080962C4:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080962EC
	ldr r0, _0809632C
	ldr r0, [r0]
	ldr r2, _0809633C
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080962EC
	movs r0, 0x37
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080962EC
	movs r5, 0x37
_080962EC:
	cmp r5, 0x38
	bne _08096310
	cmp r6, r8
	bgt _08096392
	bl sub_8096E2C
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0xE
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0809630C
	cmp r5, 0x2
	bhi _0809638E
_0809630C:
	cmp r5, 0x31
	bhi _0809638E
_08096310:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8095FE8
	adds r4, r0, 0
	movs r0, 0x1
	strb r0, [r4]
	movs r0, 0x62
	strb r0, [r4, 0x4]
	strb r5, [r4, 0x5]
	b _0809638A
	.align 2, 0
_08096328: .4byte 0x00000325
_0809632C: .4byte gUnknown_203B490
_08096330: .4byte 0x00000323
_08096334: .4byte 0x00000322
_08096338: .4byte 0x00000326
_0809633C: .4byte 0x00000327
_08096340:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8095FE8
	adds r4, r0, 0
	bl sub_8095B28
	lsls r0, 24
	cmp r0, 0
	beq _08096392
	bl sub_8095E78
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0x4
	ldrb r1, [r4, 0x1]
	bl sub_803C1D0
	lsls r0, 24
	cmp r0, 0
	bne _0809636C
	movs r5, 0
_0809636C:
	movs r0, 0x5
	movs r1, 0xA
	bl RandomRange
	strb r0, [r4, 0x11]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bne _0809638A
	cmp r5, 0
	bne _08096388
	movs r0, 0x5
	strb r0, [r4, 0x11]
	b _0809638A
_08096388:
	strb r5, [r4, 0x13]
_0809638A:
	movs r7, 0x1
	adds r6, 0x1
_0809638E:
	cmp r6, r8
	ble _08096340
_08096392:
	bl sub_80963B4
	lsls r0, 24
	cmp r0, 0
	beq _0809639E
	movs r7, 0x1
_0809639E:
	bl sub_8096078
	bl sub_8096114
	adds r0, r7, 0
_080963A8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80961D8

	thumb_func_start sub_80963B4
sub_80963B4:
	push {r4-r6,lr}
	movs r6, 0
	bl sub_8096E2C
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8095F8C
	adds r4, r0, 0
	cmp r4, 0x3
	ble _080963CE
	movs r0, 0
	b _080963F4
_080963CE:
	movs r0, 0xE
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080963F2
	cmp r5, 0x31
	bhi _080963F2
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8095FE8
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x62
	strb r1, [r0, 0x4]
	strb r5, [r0, 0x5]
	movs r6, 0x1
_080963F2:
	adds r0, r6, 0
_080963F4:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80963B4

	thumb_func_start sub_80963FC
sub_80963FC:
	push {r4-r6,lr}
	movs r6, 0
_08096400:
	lsls r0, r6, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_8095FE8
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _08096418
	adds r0, r4, 0
	bl sub_8096040
_08096418:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08096400
	bl sub_8096078
	bl sub_8095F8C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095FE8
	adds r5, r0, 0
	movs r0, 0
	movs r4, 0x5
	strb r4, [r5]
	strb r0, [r5, 0x1]
	strb r0, [r5, 0x2]
	movs r0, 0x2
	strb r0, [r5, 0x4]
	movs r0, 0x3
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096484
	ands r1, r0
	str r1, [r5, 0x8]
	movs r0, 0x10
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	ldrb r0, [r5, 0x4]
	bl sub_8095F28
	strb r0, [r5, 0x10]
	strb r4, [r5, 0x11]
_0809645C:
	ldrb r1, [r5, 0x1]
	adds r0, r5, 0x4
	adds r2, r5, 0
	adds r2, 0x12
	bl sub_803C37C
	ldrb r0, [r5, 0x10]
	ldrb r1, [r5, 0x12]
	cmp r0, r1
	beq _0809645C
	movs r0, 0
	strb r0, [r5, 0x13]
	bl sub_8096078
	bl sub_8096114
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096484: .4byte 0x00ffffff
	thumb_func_end sub_80963FC

	thumb_func_start sub_8096488
sub_8096488:
	push {r4,lr}
	movs r4, 0
_0809648C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096040
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809648C
	movs r0, 0
	bl sub_8095FE8
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	movs r1, 0x62
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8096488

	thumb_func_start sub_80964B4
sub_80964B4:
	push {lr}
	ldr r0, _080964D4
	ldr r0, [r0]
	ldr r1, _080964D8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080964DC
	movs r0, 0x35
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _080964DC
	movs r0, 0
	b _080964DE
	.align 2, 0
_080964D4: .4byte gUnknown_203B490
_080964D8: .4byte 0x00000325
_080964DC:
	movs r0, 0x1
_080964DE:
	pop {r1}
	bx r1
	thumb_func_end sub_80964B4

	thumb_func_start sub_80964E4
sub_80964E4:
	push {lr}
	ldr r0, _08096504
	ldr r0, [r0]
	ldr r1, _08096508
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809650C
	movs r0, 0x36
	bl sub_8096E80
	lsls r0, 24
	cmp r0, 0
	bne _0809650C
	movs r0, 0
	b _0809650E
	.align 2, 0
_08096504: .4byte gUnknown_203B490
_08096508: .4byte 0x00000326
_0809650C:
	movs r0, 0x1
_0809650E:
	pop {r1}
	bx r1
	thumb_func_end sub_80964E4

	thumb_func_start sub_8096514
sub_8096514:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0809651A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_809658C
	lsls r0, 24
	cmp r0, 0
	bne _0809652A
	adds r5, 0x1
_0809652A:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0809651A
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096514

	thumb_func_start sub_8096538
sub_8096538:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _08096560
	movs r2, 0
_08096542:
	ldr r0, [r5]
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0x50
	ldrb r0, [r1]
	cmp r0, 0
	bne _08096564
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	b _0809656E
	.align 2, 0
_08096560: .4byte gUnknown_203B490
_08096564:
	adds r2, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096542
	movs r0, 0x1
_0809656E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096538

	thumb_func_start sub_8096574
sub_8096574:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _08096588
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0x50
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_08096588: .4byte gUnknown_203B490
	thumb_func_end sub_8096574

	thumb_func_start sub_809658C
sub_809658C:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080965AC
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	adds r2, 0x50
	ldrb r0, [r2]
	cmp r0, 0
	beq _080965B0
	movs r0, 0
	b _080965B2
	.align 2, 0
_080965AC: .4byte gUnknown_203B490
_080965B0:
	movs r0, 0x1
_080965B2:
	pop {r1}
	bx r1
	thumb_func_end sub_809658C

	thumb_func_start sub_80965B8
sub_80965B8:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, _080965F0
	ldr r1, [r4]
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r1, 0x50
	movs r3, 0
	strb r3, [r1]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x54
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x55
	strb r3, [r0]
	ldr r0, [r4]
	adds r0, r2
	adds r0, 0x61
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080965F0: .4byte gUnknown_203B490
	thumb_func_end sub_80965B8

	thumb_func_start sub_80965F4
sub_80965F4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _0809660C
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _08096636
	.align 2, 0
_0809660C: .4byte gUnknown_203B490
_08096610:
	cmp r2, r3
	ble _0809662A
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	adds r1, 0x50
	adds r0, 0x50
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_0809662A:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_08096636:
	cmp r2, 0x7
	bgt _08096666
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096666
	ldr r6, _08096694
	mov r1, r9
_0809664C:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08096666
	ldr r0, [r6]
	adds r0, r1
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809664C
_08096666:
	cmp r2, 0x8
	bne _08096610
	cmp r3, 0x7
	bgt _08096688
	ldr r4, _08096694
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_08096678:
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x50
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096678
_08096688:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096694: .4byte gUnknown_203B490
	thumb_func_end sub_80965F4

	thumb_func_start sub_8096698
sub_8096698:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r1, 0
_080966A6:
	adds r6, r1, 0x1
	mov r10, r6
	cmp r6, 0x7
	bgt _08096730
	ldr r0, _08096748
	mov r8, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r9, r0
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 2
_080966C0:
	mov r2, r8
	ldr r1, [r2]
	adds r3, r1, r4
	adds r5, r3, 0
	adds r5, 0x50
	ldrb r0, [r5]
	cmp r0, 0
	beq _08096724
	add r1, r9
	mov r12, r1
	mov r0, r12
	adds r0, 0x54
	adds r1, r3, 0
	adds r1, 0x54
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	bhi _080966F6
	cmp r2, r0
	bne _08096724
	mov r0, r12
	adds r0, 0x55
	adds r1, 0x1
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _08096724
_080966F6:
	mov r1, sp
	mov r0, r12
	adds r0, 0x50
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r3,r7}
	stm r1!, {r3,r7}
	mov r1, r12
	adds r1, 0x50
	adds r0, r5, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r7}
	stm r1!, {r2,r7}
	mov r3, r8
	ldr r1, [r3]
	adds r1, r4
	adds r1, 0x50
	mov r0, sp
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
	ldm r0!, {r3,r5}
	stm r1!, {r3,r5}
_08096724:
	adds r4, 0x14
	movs r7, 0x1
	add r10, r7
	mov r0, r10
	cmp r0, 0x7
	ble _080966C0
_08096730:
	adds r1, r6, 0
	cmp r1, 0x6
	ble _080966A6
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096748: .4byte gUnknown_203B490
	thumb_func_end sub_8096698

	thumb_func_start sub_809674C
sub_809674C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0x4
	movs r1, 0x8
	bl RandomRange
	mov r8, r0
	ldr r3, _08096864
	movs r2, 0
	movs r1, 0
	movs r7, 0x7
_08096764:
	ldr r0, [r3]
	adds r0, r1
	adds r0, 0x50
	strb r2, [r0]
	adds r1, 0x14
	subs r7, 0x1
	cmp r7, 0
	bge _08096764
	movs r7, 0
	movs r0, 0xE
	bl sub_8097318
	lsls r0, 24
	cmp r0, 0
	beq _080967C0
	movs r0, 0
	bl sub_8096574
	adds r5, r0, 0
	movs r4, 0x2
	strb r4, [r5]
	movs r0, 0x6
	strb r0, [r5, 0x1]
	movs r0, 0x1
	strb r0, [r5, 0x2]
	movs r0, 0x2A
	strb r0, [r5, 0x4]
	movs r0, 0xA
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096868
	ands r1, r0
	str r1, [r5, 0x8]
	movs r1, 0
	movs r0, 0xC2
	lsls r0, 1
	strh r0, [r5, 0xC]
	movs r0, 0x38
	strh r0, [r5, 0xE]
	strb r1, [r5, 0x10]
	strb r4, [r5, 0x11]
	movs r0, 0x3A
	strb r0, [r5, 0x12]
	strb r1, [r5, 0x13]
	movs r7, 0x1
_080967C0:
	movs r0, 0xF
	bl sub_8097318
	lsls r0, 24
	cmp r0, 0
	beq _0809680A
	lsls r0, r7, 24
	lsrs r0, 24
	bl sub_8096574
	adds r5, r0, 0
	movs r0, 0x3
	strb r0, [r5]
	movs r0, 0x6
	strb r0, [r5, 0x1]
	movs r4, 0x2
	strb r4, [r5, 0x2]
	movs r0, 0x35
	strb r0, [r5, 0x4]
	movs r0, 0xF
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096868
	ands r1, r0
	str r1, [r5, 0x8]
	movs r1, 0
	movs r0, 0x82
	lsls r0, 1
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	strb r1, [r5, 0x10]
	strb r4, [r5, 0x11]
	movs r0, 0x3A
	strb r0, [r5, 0x12]
	strb r1, [r5, 0x13]
	adds r7, 0x1
_0809680A:
	movs r0, 0x1C
	bl sub_8097318
	lsls r0, 24
	cmp r0, 0
	beq _08096854
	lsls r0, r7, 24
	lsrs r0, 24
	bl sub_8096574
	adds r5, r0, 0
	movs r0, 0x4
	strb r0, [r5]
	movs r0, 0x6
	strb r0, [r5, 0x1]
	movs r0, 0x3
	strb r0, [r5, 0x2]
	movs r0, 0x1A
	strb r0, [r5, 0x4]
	movs r0, 0x14
	strb r0, [r5, 0x5]
	bl Random
	ldr r1, _08096868
	ands r1, r0
	str r1, [r5, 0x8]
	movs r1, 0
	ldr r0, _0809686C
	strh r0, [r5, 0xC]
	strh r0, [r5, 0xE]
	strb r1, [r5, 0x10]
	movs r0, 0x2
	strb r0, [r5, 0x11]
	movs r0, 0x3A
	strb r0, [r5, 0x12]
	strb r1, [r5, 0x13]
	adds r7, 0x1
_08096854:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 2
	adds r5, r0, 0
	adds r5, 0x50
	adds r4, r0, 0
	b _08096886
	.align 2, 0
_08096864: .4byte gUnknown_203B490
_08096868: .4byte 0x00ffffff
_0809686C: .4byte 0x0000014d
_08096870:
	movs r0, 0
	movs r1, 0x4
	bl RandomRange
	ldr r1, [r6]
	adds r1, r4
	adds r1, 0x61
	strb r0, [r1]
	adds r5, 0x14
	adds r4, 0x14
	adds r7, 0x1
_08096886:
	cmp r7, r8
	bgt _0809689A
	ldr r6, _080968AC
	ldr r0, [r6]
	adds r0, r5
	bl sub_8095B28
	lsls r0, 24
	cmp r0, 0
	bne _08096870
_0809689A:
	bl sub_80965F4
	bl sub_8096698
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080968AC: .4byte gUnknown_203B490
	thumb_func_end sub_809674C

	thumb_func_start sub_80968B0
sub_80968B0:
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r4, 0
	ldr r0, _08096928
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xF0
_080968BE:
	ldrb r0, [r2]
	cmp r0, 0
	beq _0809692C
	ldrb r0, [r3, 0x1]
	ldrb r1, [r2, 0x1]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x2]
	ldrb r5, [r2, 0x2]
	cmp r0, r5
	bne _0809692C
	ldrb r0, [r3, 0x4]
	ldrb r1, [r2, 0x4]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x5]
	ldrb r5, [r2, 0x5]
	cmp r0, r5
	bne _0809692C
	ldr r1, [r3, 0x8]
	ldr r0, [r2, 0x8]
	cmp r1, r0
	bne _0809692C
	movs r0, 0xC
	ldrsh r1, [r3, r0]
	movs r5, 0xC
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _0809692C
	movs r0, 0xE
	ldrsh r1, [r3, r0]
	movs r5, 0xE
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bne _0809692C
	ldrb r0, [r3, 0x10]
	ldrb r1, [r2, 0x10]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x11]
	ldrb r5, [r2, 0x11]
	cmp r0, r5
	bne _0809692C
	ldrb r0, [r3, 0x12]
	ldrb r1, [r2, 0x12]
	cmp r0, r1
	bne _0809692C
	ldrb r0, [r3, 0x13]
	ldrb r5, [r2, 0x13]
	cmp r0, r5
	bne _0809692C
	movs r0, 0x1
	b _08096936
	.align 2, 0
_08096928: .4byte gUnknown_203B490
_0809692C:
	adds r2, 0x14
	adds r4, 0x1
	cmp r4, 0x7
	ble _080968BE
	movs r0, 0
_08096936:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80968B0

	thumb_func_start sub_809693C
sub_809693C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	ldrb r0, [r4, 0x4]
	mov r9, r0
	ldrb r0, [r4, 0x5]
	mov r8, r0
	movs r7, 0
	adds r0, r4, 0
	bl sub_80959C0
	lsls r0, 24
	cmp r0, 0
	bne _08096962
	b _0809699A
_0809695E:
	movs r0, 0x1
	b _0809699C
_08096962:
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _0809696A
	movs r7, 0x1
_0809696A:
	movs r6, 0
	movs r5, 0xF0
	movs r4, 0
_08096970:
	ldr r0, _080969A8
	ldr r1, [r0]
	adds r0, r1, r4
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08096990
	adds r0, r1, r5
	mov r1, r9
	mov r2, r8
	adds r3, r7, 0
	bl sub_8095E38
	lsls r0, 24
	cmp r0, 0
	bne _0809695E
_08096990:
	adds r5, 0x14
	adds r4, 0x14
	adds r6, 0x1
	cmp r6, 0x7
	ble _08096970
_0809699A:
	movs r0, 0
_0809699C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080969A8: .4byte gUnknown_203B490
	thumb_func_end sub_809693C

	thumb_func_start sub_80969AC
sub_80969AC:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_080969B2:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096ACC
	lsls r0, 24
	cmp r0, 0
	bne _080969C2
	adds r5, 0x1
_080969C2:
	adds r4, 0x1
	cmp r4, 0x7
	ble _080969B2
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80969AC

	thumb_func_start sub_80969D0
sub_80969D0:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r4, 0
_080969DA:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r1, r0, 0
	ldrb r0, [r1, 0x4]
	cmp r0, r6
	bne _080969FA
	ldrb r0, [r1]
	cmp r0, 0x6
	beq _080969F8
	cmp r0, 0x8
	beq _080969F8
	cmp r0, 0x9
	bne _080969FA
_080969F8:
	adds r5, 0x1
_080969FA:
	adds r4, 0x1
	cmp r4, 0x7
	ble _080969DA
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80969D0

	thumb_func_start sub_8096A08
sub_8096A08:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r6, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_08096A14:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r2, r0, 0
	ldrb r0, [r2, 0x4]
	cmp r0, r5
	bne _08096A68
	ldrb r0, [r2]
	cmp r0, 0x6
	bne _08096A68
	ldrb r0, [r2, 0x1]
	cmp r0, 0x2
	bne _08096A68
	ldr r1, _08096A60
	ldr r0, [sp, 0x8]
	ands r0, r1
	movs r1, 0x4A
	orrs r0, r1
	ldr r1, _08096A64
	ands r0, r1
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp, 0x8]
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	add r0, sp, 0x8
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_808CFD0
	movs r0, 0x1
	b _08096A70
	.align 2, 0
_08096A60: .4byte 0xffffff00
_08096A64: .4byte 0xffff00ff
_08096A68:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08096A14
	movs r0, 0
_08096A70:
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8096A08

	thumb_func_start sub_8096A78
sub_8096A78:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _08096AA0
	movs r2, 0
_08096A82:
	ldr r0, [r5]
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08096AA4
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	movs r0, 0
	b _08096AAE
	.align 2, 0
_08096AA0: .4byte gUnknown_203B490
_08096AA4:
	adds r2, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096A82
	movs r0, 0x1
_08096AAE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096A78

	thumb_func_start sub_8096AB4
sub_8096AB4:
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _08096AC8
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, 0xF0
	ldr r0, [r2]
	adds r0, r1
	bx lr
	.align 2, 0
_08096AC8: .4byte gUnknown_203B490
	thumb_func_end sub_8096AB4

	thumb_func_start sub_8096ACC
sub_8096ACC:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096AEC
	ldr r2, [r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r2, r1
	adds r2, 0xF0
	ldrb r0, [r2]
	cmp r0, 0
	beq _08096AF0
	movs r0, 0
	b _08096AF2
	.align 2, 0
_08096AEC: .4byte gUnknown_203B490
_08096AF0:
	movs r0, 0x1
_08096AF2:
	pop {r1}
	bx r1
	thumb_func_end sub_8096ACC

	thumb_func_start sub_8096AF8
sub_8096AF8:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r4, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	bl sub_8096AB4
	adds r3, r0, 0
	movs r1, 0
	strb r1, [r5]
	ldrh r0, [r3, 0xC]
	strh r0, [r5, 0x2]
	strh r1, [r5, 0x4]
	ldrb r0, [r3, 0x4]
	cmp r0, r4
	bne _08096B92
	ldrb r0, [r3, 0x1]
	cmp r0, 0x4
	bhi _08096B92
	lsls r0, 2
	ldr r1, _08096B30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08096B30: .4byte _08096B34
	.align 2, 0
_08096B34:
	.4byte _08096B78
	.4byte _08096B84
	.4byte _08096B84
	.4byte _08096B48
	.4byte _08096B78
_08096B48:
	ldrb r0, [r3]
	cmp r0, 0x6
	bne _08096B92
	ldr r0, _08096B74
	movs r6, 0x1
	ldr r2, [r0]
	movs r4, 0x13
_08096B56:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08096B6A
	ldrb r0, [r2, 0x2]
	ldrb r1, [r3, 0x10]
	cmp r0, r1
	bne _08096B6A
	strb r6, [r5]
_08096B6A:
	adds r2, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08096B56
	b _08096B92
	.align 2, 0
_08096B74: .4byte gUnknown_203B460
_08096B78:
	ldrb r0, [r3]
	cmp r0, 0x9
	bne _08096B92
	movs r0, 0x1
	strb r0, [r5]
	b _08096B92
_08096B84:
	ldrb r0, [r3]
	cmp r0, 0x9
	bne _08096B92
	movs r0, 0x1
	strb r0, [r5]
	ldrh r0, [r3, 0xE]
	strh r0, [r5, 0x4]
_08096B92:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8096AF8

	thumb_func_start sub_8096B98
sub_8096B98:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_08096BA0:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _08096BC2
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	bne _08096BC2
	ldrb r0, [r1, 0x4]
	cmp r0, r5
	bne _08096BC2
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	b _08096BCA
_08096BC2:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08096BA0
	movs r0, 0
_08096BCA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8096B98

	thumb_func_start sub_8096BD0
sub_8096BD0:
	push {r4,r5,lr}
	ldr r0, _08096C04
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0xF0
	movs r4, 0
_08096BDC:
	ldrb r0, [r5]
	cmp r0, 0x9
	bgt _08096BEE
	cmp r0, 0x7
	blt _08096BEE
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096C3C
_08096BEE:
	adds r5, 0x14
	adds r4, 0x1
	cmp r4, 0x7
	ble _08096BDC
	bl sub_8096C80
	bl sub_8096D24
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096C04: .4byte gUnknown_203B490
	thumb_func_end sub_8096BD0

	thumb_func_start sub_8096C08
sub_8096C08:
	push {lr}
	adds r3, r0, 0
	ldr r0, _08096C28
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	movs r2, 0
_08096C16:
	ldrb r0, [r1]
	cmp r0, 0x4
	bls _08096C2C
	ldrb r0, [r1, 0x2]
	cmp r0, 0x4
	bne _08096C2C
	strb r2, [r3]
	movs r0, 0x1
	b _08096C36
	.align 2, 0
_08096C28: .4byte gUnknown_203B490
_08096C2C:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x7
	ble _08096C16
	movs r0, 0
_08096C36:
	pop {r1}
	bx r1
	thumb_func_end sub_8096C08

	thumb_func_start sub_8096C3C
sub_8096C3C:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, _08096C78
	ldr r1, [r3]
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	adds r1, r2
	adds r1, 0xF0
	movs r4, 0
	strb r4, [r1]
	ldr r0, [r3]
	adds r0, r2
	adds r0, 0xF4
	movs r1, 0x63
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, r2
	adds r0, 0xF5
	strb r4, [r0]
	ldr r0, [r3]
	adds r0, r2
	ldr r2, _08096C7C
	adds r1, r0, r2
	movs r0, 0x5
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096C78: .4byte gUnknown_203B490
_08096C7C: .4byte 0x00000101
	thumb_func_end sub_8096C3C

	thumb_func_start sub_8096C80
sub_8096C80:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _08096C98
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _08096CC2
	.align 2, 0
_08096C98: .4byte gUnknown_203B490
_08096C9C:
	cmp r2, r3
	ble _08096CB6
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	adds r1, 0xF0
	adds r0, 0xF0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_08096CB6:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_08096CC2:
	cmp r2, 0x7
	bgt _08096CF2
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096CF2
	ldr r6, _08096D20
	mov r1, r9
_08096CD8:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08096CF2
	ldr r0, [r6]
	adds r0, r1
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08096CD8
_08096CF2:
	cmp r2, 0x8
	bne _08096C9C
	cmp r3, 0x7
	bgt _08096D14
	ldr r4, _08096D20
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_08096D04:
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0xF0
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096D04
_08096D14:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096D20: .4byte gUnknown_203B490
	thumb_func_end sub_8096C80

	thumb_func_start sub_8096D24
sub_8096D24:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	movs r1, 0
_08096D32:
	adds r6, r1, 0x1
	mov r10, r6
	cmp r6, 0x7
	bgt _08096DBC
	ldr r0, _08096DD4
	mov r8, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	mov r9, r0
	lsls r0, r6, 2
	adds r0, r6
	lsls r4, r0, 2
_08096D4C:
	mov r1, r8
	ldr r2, [r1]
	adds r3, r2, r4
	adds r5, r3, 0
	adds r5, 0xF0
	str r5, [sp, 0x14]
	ldrb r0, [r5]
	cmp r0, 0
	beq _08096DB0
	add r2, r9
	mov r12, r2
	mov r0, r12
	adds r0, 0xF4
	adds r1, r3, 0
	adds r1, 0xF4
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	bhi _08096D84
	cmp r2, r0
	bne _08096DB0
	mov r0, r12
	adds r0, 0xF5
	adds r1, 0x1
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _08096DB0
_08096D84:
	mov r2, r12
	adds r2, 0xF0
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldm r0!, {r3,r7}
	stm r1!, {r3,r7}
	ldr r0, [sp, 0x14]
	ldm r0!, {r1,r5,r7}
	stm r2!, {r1,r5,r7}
	ldm r0!, {r3,r5}
	stm r2!, {r3,r5}
	mov r7, r8
	ldr r1, [r7]
	adds r1, r4
	adds r1, 0xF0
	mov r0, sp
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r7}
	stm r1!, {r2,r7}
_08096DB0:
	adds r4, 0x14
	movs r3, 0x1
	add r10, r3
	mov r5, r10
	cmp r5, 0x7
	ble _08096D4C
_08096DBC:
	adds r1, r6, 0
	cmp r1, 0x6
	ble _08096D32
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096DD4: .4byte gUnknown_203B490
	thumb_func_end sub_8096D24

	thumb_func_start sub_8096DD8
sub_8096DD8:
	ldr r0, _08096DE4
	ldr r0, [r0]
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r1
	bx lr
	.align 2, 0
_08096DE4: .4byte gUnknown_203B490
	thumb_func_end sub_8096DD8

	thumb_func_start sub_8096DE8
sub_8096DE8:
	ldr r0, _08096DF4
	ldr r0, [r0]
	movs r1, 0xDC
	lsls r1, 1
	adds r0, r1
	bx lr
	.align 2, 0
_08096DF4: .4byte gUnknown_203B490
	thumb_func_end sub_8096DE8

	thumb_func_start sub_8096DF8
sub_8096DF8:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096E10
	ldr r1, [r1]
	movs r2, 0xBC
	lsls r2, 2
	adds r1, r2
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08096E10: .4byte gUnknown_203B490
	thumb_func_end sub_8096DF8

	thumb_func_start sub_8096E14
sub_8096E14:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08096E28
	ldr r1, [r1]
	movs r2, 0xBC
	lsls r2, 2
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_08096E28: .4byte gUnknown_203B490
	thumb_func_end sub_8096E14

	thumb_func_start sub_8096E2C
sub_8096E2C:
	push {lr}
	movs r3, 0
	ldr r0, _08096E70
	ldr r1, [r0]
	movs r2, 0x3
_08096E36:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08096E48
	ldrb r0, [r1, 0x5]
	cmp r3, r0
	bgt _08096E48
	cmp r0, 0x31
	bhi _08096E48
	adds r3, r0, 0x1
_08096E48:
	adds r1, 0x14
	subs r2, 0x1
	cmp r2, 0
	bge _08096E36
	adds r2, r3, 0
	cmp r2, 0x31
	bgt _08096E7A
	ldr r0, _08096E70
	ldr r0, [r0]
	movs r3, 0xBC
	lsls r3, 2
	adds r1, r0, r3
_08096E60:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096E74
	lsls r0, r2, 24
	lsrs r0, 24
	b _08096E7C
	.align 2, 0
_08096E70: .4byte gUnknown_203B490
_08096E74:
	adds r2, 0x1
	cmp r2, 0x31
	ble _08096E60
_08096E7A:
	movs r0, 0x38
_08096E7C:
	pop {r1}
	bx r1
	thumb_func_end sub_8096E2C

	thumb_func_start sub_8096E80
sub_8096E80:
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, _08096E9C
	ldr r1, [r0]
_08096E8C:
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08096EA0
	ldrb r0, [r1, 0x5]
	cmp r3, r0
	bne _08096EA0
	movs r0, 0x1
	b _08096EAA
	.align 2, 0
_08096E9C: .4byte gUnknown_203B490
_08096EA0:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x3
	ble _08096E8C
	movs r0, 0
_08096EAA:
	pop {r1}
	bx r1
	thumb_func_end sub_8096E80

	thumb_func_start sub_8096EB0
sub_8096EB0:
	ldrb r1, [r0, 0x2]
	ldrb r2, [r0, 0x1]
	adds r1, r2
	ldrb r3, [r0, 0x4]
	adds r2, r1, r3
	ldrb r1, [r0, 0x5]
	adds r2, r1
	ldr r1, [r0, 0x8]
	lsls r1, 8
	adds r2, r1
	movs r3, 0xC
	ldrsh r1, [r0, r3]
	lsls r1, 12
	adds r2, r1
	movs r3, 0xE
	ldrsh r1, [r0, r3]
	lsls r1, 16
	adds r2, r1
	ldrb r1, [r0, 0x10]
	lsls r1, 24
	adds r1, r2, r1
	ldrb r3, [r0, 0x11]
	adds r2, r1, r3
	ldrb r1, [r0, 0x12]
	adds r1, r2, r1
	ldrb r0, [r0, 0x13]
	adds r2, r1, r0
	adds r0, r2, 0
	bx lr
	thumb_func_end sub_8096EB0

	thumb_func_start sub_8096EEC
sub_8096EEC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r12, r0
	movs r3, 0xF
	ldr r5, _08096F4C
	mov r8, r5
	movs r4, 0x8C
	lsls r4, 2
_08096EFE:
	mov r0, r8
	ldr r2, [r0]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2, r1
	subs r3, 0x1
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r2, r0
	adds r1, r4
	adds r2, r4
	ldm r2!, {r0,r6,r7}
	stm r1!, {r0,r6,r7}
	cmp r3, 0
	bgt _08096EFE
	ldr r2, [r5]
	movs r3, 0x8C
	lsls r3, 2
	adds r2, r3
	mov r6, r12
	ldr r0, [r6, 0x4]
	ldr r1, [r6, 0x8]
	str r0, [r2]
	str r1, [r2, 0x4]
	mov r0, r12
	bl sub_8096EB0
	ldr r1, [r5]
	movs r7, 0x8E
	lsls r7, 2
	adds r1, r7
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096F4C: .4byte gUnknown_203B490
	thumb_func_end sub_8096EEC

	thumb_func_start sub_8096F50
sub_8096F50:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_8096EB0
	mov r12, r0
	movs r5, 0
	ldr r0, _08096F8C
	ldr r7, [r0]
	ldrb r6, [r4, 0x4]
	movs r3, 0
_08096F64:
	movs r1, 0x8C
	lsls r1, 2
	adds r0, r3, r1
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, r6
	bne _08096F90
	ldrb r0, [r2, 0x1]
	ldrb r1, [r4, 0x5]
	cmp r0, r1
	bne _08096F90
	ldr r1, [r2, 0x4]
	ldr r0, [r4, 0x8]
	cmp r1, r0
	bne _08096F90
	ldr r0, [r2, 0x8]
	cmp r0, r12
	bne _08096F90
	movs r0, 0x1
	b _08096F9A
	.align 2, 0
_08096F8C: .4byte gUnknown_203B490
_08096F90:
	adds r3, 0xC
	adds r5, 0x1
	cmp r5, 0xF
	ble _08096F64
	movs r0, 0
_08096F9A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8096F50

	thumb_func_start sub_8096FA0
sub_8096FA0:
	push {r4-r7,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	add r7, sp, 0x10
	ldr r6, _08097020
	movs r5, 0
	movs r4, 0x3
_08096FB8:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80971EC
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08096FB8
	ldr r6, _08097020
	movs r5, 0x50
	movs r4, 0x7
_08096FD0:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80971EC
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08096FD0
	ldr r6, _08097020
	movs r5, 0xF0
	movs r4, 0x7
_08096FE8:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80971EC
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08096FE8
	movs r4, 0
	movs r6, 0x1
	ldr r5, _08097020
_08097000:
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_8094924
	ldr r1, [sp, 0x10]
	ands r1, r6
	cmp r1, 0
	beq _08097024
	ldr r0, [r5]
	movs r1, 0xBC
	lsls r1, 2
	adds r0, r1
	adds r0, r4
	strb r6, [r0]
	b _08097030
	.align 2, 0
_08097020: .4byte gUnknown_203B490
_08097024:
	ldr r0, [r5]
	movs r2, 0xBC
	lsls r2, 2
	adds r0, r2
	adds r0, r4
	strb r1, [r0]
_08097030:
	adds r4, 0x1
	cmp r4, 0x37
	ble _08097000
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_8094924
	ldr r1, [sp, 0x10]
	movs r2, 0x1
	ands r1, r2
	cmp r1, 0
	beq _0809705C
	ldr r0, _08097058
	ldr r0, [r0]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	strb r2, [r0]
	b _08097068
	.align 2, 0
_08097058: .4byte gUnknown_203B490
_0809705C:
	ldr r0, _080970D4
	ldr r0, [r0]
	movs r2, 0xCA
	lsls r2, 2
	adds r0, r2
	strb r1, [r0]
_08097068:
	ldr r4, _080970D4
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r2, 0xA0
	lsls r2, 1
	mov r0, sp
	bl sub_8094924
	ldr r1, [r4]
	movs r2, 0xDC
	lsls r2, 1
	adds r1, r2
	movs r2, 0xF0
	lsls r2, 2
	mov r0, sp
	bl sub_8094924
	adds r6, r4, 0
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0xF
_08097096:
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x8
	mov r0, sp
	movs r2, 0x20
	bl sub_8094924
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x4
	mov r0, sp
	movs r2, 0x18
	bl sub_8094924
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8090314
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _08097096
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080970D4: .4byte gUnknown_203B490
	thumb_func_end sub_8096FA0

	thumb_func_start sub_80970D8
sub_80970D8:
	push {r4-r7,lr}
	sub sp, 0x14
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	add r7, sp, 0x10
	ldr r6, _080971E8
	movs r5, 0
	movs r4, 0x3
_080970F0:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8097270
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _080970F0
	ldr r6, _080971E8
	movs r5, 0x50
	movs r4, 0x7
_08097108:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8097270
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08097108
	ldr r6, _080971E8
	movs r5, 0xF0
	movs r4, 0x7
_08097120:
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_8097270
	adds r5, 0x14
	subs r4, 0x1
	cmp r4, 0
	bge _08097120
	movs r4, 0
_08097134:
	ldr r0, _080971E8
	ldr r0, [r0]
	movs r1, 0xBC
	lsls r1, 2
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809714A
	movs r0, 0x1
	negs r0, r0
_0809714A:
	str r0, [sp, 0x10]
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_809488C
	adds r4, 0x1
	cmp r4, 0x37
	ble _08097134
	ldr r0, _080971E8
	ldr r0, [r0]
	movs r1, 0xCA
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08097170
	movs r0, 0x1
	negs r0, r0
_08097170:
	str r0, [sp, 0x10]
	mov r0, sp
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_809488C
	ldr r4, _080971E8
	ldr r1, [r4]
	movs r0, 0xC8
	lsls r0, 1
	adds r1, r0
	movs r2, 0xA0
	lsls r2, 1
	mov r0, sp
	bl sub_809488C
	ldr r1, [r4]
	movs r0, 0xDC
	lsls r0, 1
	adds r1, r0
	movs r2, 0xF0
	lsls r2, 2
	mov r0, sp
	bl sub_809488C
	adds r6, r4, 0
	movs r5, 0x8C
	lsls r5, 2
	movs r4, 0xF
_080971AA:
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x8
	mov r0, sp
	movs r2, 0x20
	bl sub_809488C
	ldr r1, [r6]
	adds r1, r5
	adds r1, 0x4
	mov r0, sp
	movs r2, 0x18
	bl sub_809488C
	ldr r1, [r6]
	adds r1, r5
	mov r0, sp
	bl sub_80902F4
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bge _080971AA
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080971E8: .4byte gUnknown_203B490
	thumb_func_end sub_80970D8

	thumb_func_start sub_80971EC
sub_80971EC:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x3
	bl sub_8094924
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0xE
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x11
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x12
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x13
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_8094924
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_8094924
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl sub_8090314
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80971EC

	thumb_func_start sub_8097270
sub_8097270:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x3
	bl sub_809488C
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0xC
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0xE
	adds r0, r4, 0
	movs r2, 0x9
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x10
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x11
	adds r0, r4, 0
	movs r2, 0x4
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x12
	adds r0, r4, 0
	movs r2, 0x8
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x13
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_809488C
	adds r1, r5, 0
	adds r1, 0x8
	adds r0, r4, 0
	movs r2, 0x18
	bl sub_809488C
	adds r1, r5, 0x4
	adds r0, r4, 0
	bl sub_80902F4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8097270

	thumb_func_start sub_80972F4
sub_80972F4:
	push {lr}
	movs r0, 0
	movs r1, 0x2B
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2C
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2D
	bl sub_80015C0
	pop {r0}
	bx r0
	thumb_func_end sub_80972F4

	thumb_func_start nullsub_128
nullsub_128:
	bx lr
	thumb_func_end nullsub_128

	thumb_func_start sub_8097318
sub_8097318:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097326
	movs r0, 0
	b _08097338
_08097326:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2B
	bl sub_8001784
	cmp r0, 0
	beq _08097338
	movs r0, 0x1
_08097338:
	pop {r1}
	bx r1
	thumb_func_end sub_8097318

	thumb_func_start sub_809733C
sub_809733C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r4, 0xD
	beq _0809737C
	lsls r0, r4, 16
	lsrs r5, r0, 16
	movs r0, 0
	movs r1, 0x2C
	adds r2, r5, 0
	bl sub_8001784
	cmp r0, 0
	bne _0809737C
	movs r0, 0
	movs r1, 0x2B
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_800199C
	cmp r6, 0
	beq _0809737C
	cmp r4, 0xE
	blt _0809737C
	cmp r4, 0xF
	ble _08097378
	cmp r4, 0x1C
	bne _0809737C
_08097378:
	bl sub_809674C
_0809737C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809733C

	thumb_func_start sub_8097384
sub_8097384:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097392
	movs r0, 0
	b _080973A4
_08097392:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2C
	bl sub_8001784
	cmp r0, 0
	beq _080973A4
	movs r0, 0x1
_080973A4:
	pop {r1}
	bx r1
	thumb_func_end sub_8097384

	thumb_func_start sub_80973A8
sub_80973A8:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	cmp r0, 0xD
	beq _080973EE
	lsls r5, r0, 16
	cmp r6, 0
	beq _080973E2
	bl sub_80A26B8
	lsls r0, 16
	asrs r4, r0, 16
	lsrs r2, r5, 16
	movs r0, 0
	movs r1, 0x2B
	movs r3, 0
	bl sub_800199C
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080973E2
	movs r0, 0
	movs r1, 0x12
	adds r2, r4, 0
	bl sub_80018D8
_080973E2:
	lsrs r2, r5, 16
	movs r0, 0
	movs r1, 0x2C
	adds r3, r6, 0
	bl sub_800199C
_080973EE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80973A8

	thumb_func_start sub_80973F4
sub_80973F4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bne _08097402
	movs r0, 0
	b _08097414
_08097402:
	lsls r2, r0, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2D
	bl sub_8001784
	cmp r0, 0
	beq _08097414
	movs r0, 0x1
_08097414:
	pop {r1}
	bx r1
	thumb_func_end sub_80973F4

	thumb_func_start sub_8097418
sub_8097418:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 24
	lsrs r7, r1, 24
	cmp r5, 0xD
	beq _08097470
	lsls r6, r5, 16
	cmp r7, 0
	beq _08097464
	lsrs r2, r6, 16
	movs r0, 0
	movs r1, 0x2C
	movs r3, 0
	bl sub_800199C
	cmp r5, 0x1E
	bgt _08097464
	lsls r0, r5, 3
	ldr r1, _08097478
	adds r4, r0, r1
	ldrb r0, [r4, 0x4]
	cmp r0, 0xFF
	beq _0809744C
	bl sub_8097FA8
_0809744C:
	ldrb r0, [r4, 0x5]
	cmp r0, 0xFF
	beq _08097456
	bl sub_8097FA8
_08097456:
	cmp r5, 0x9
	bne _08097460
	movs r0, 0x1F
	bl sub_8097FA8
_08097460:
	bl sub_8097FF8
_08097464:
	lsrs r2, r6, 16
	movs r0, 0
	movs r1, 0x2D
	adds r3, r7, 0
	bl sub_800199C
_08097470:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097478: .4byte gUnknown_8109994
	thumb_func_end sub_8097418

	thumb_func_start sub_809747C
sub_809747C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	beq _08097494
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	bl GetDungeonName1
	b _08097496
_08097494:
	ldr r0, _0809749C
_08097496:
	pop {r1}
	bx r1
	.align 2, 0
_0809749C: .4byte gUnknown_8109CA8
	thumb_func_end sub_809747C

	thumb_func_start sub_80974A0
sub_80974A0:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	beq _080974B8
	bl sub_80A270C
	lsls r0, 24
	lsrs r0, 24
	bl GetDungeonName1
	b _080974BA
_080974B8:
	ldr r0, _080974C0
_080974BA:
	pop {r1}
	bx r1
	.align 2, 0
_080974C0: .4byte gUnknown_8109CA8
	thumb_func_end sub_80974A0

	thumb_func_start sub_80974C4
sub_80974C4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1E
	ble _080974D8
	ldr r0, _080974D4
	b _080974E0
	.align 2, 0
_080974D4: .4byte gUnknown_8109CC0
_080974D8:
	lsls r0, 3
	ldr r1, _080974E4
	adds r0, r1
	ldr r0, [r0]
_080974E0:
	pop {r1}
	bx r1
	.align 2, 0
_080974E4: .4byte gUnknown_8109994
	thumb_func_end sub_80974C4

	thumb_func_start sub_80974E8
sub_80974E8:
	push {lr}
	movs r0, 0
	movs r1, 0x2E
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2F
	bl sub_80015C0
	pop {r0}
	bx r0
	thumb_func_end sub_80974E8

	thumb_func_start nullsub_208
nullsub_208:
	bx lr
	thumb_func_end nullsub_208

	thumb_func_start sub_8097504
sub_8097504:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	adds r1, r0, 0
	cmp r0, 0x10
	bgt _08097568
	cmp r0, 0xE
	bhi _08097580
	lsls r0, 2
	ldr r1, _08097520
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08097520: .4byte _08097524
	.align 2, 0
_08097524:
	.4byte _08097564
	.4byte _08097564
	.4byte _08097560
	.4byte _08097580
	.4byte _08097580
	.4byte _08097564
	.4byte _08097580
	.4byte _08097564
	.4byte _08097580
	.4byte _08097564
	.4byte _08097560
	.4byte _08097560
	.4byte _08097560
	.4byte _08097574
	.4byte _08097564
_08097560:
	movs r0, 0xE
	b _08097576
_08097564:
	movs r0, 0xF
	b _08097576
_08097568:
	cmp r1, 0x16
	bgt _08097584
	cmp r1, 0x16
	beq _08097584
	cmp r1, 0x15
	beq _08097584
_08097574:
	movs r0, 0x6
_08097576:
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08097584
_08097580:
	movs r0, 0x1
	b _08097586
_08097584:
	movs r0, 0
_08097586:
	pop {r1}
	bx r1
	thumb_func_end sub_8097504

	thumb_func_start sub_809758C
sub_809758C:
	push {lr}
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2E
	bl sub_8001784
	cmp r0, 0
	beq _080975A2
	movs r0, 0x1
_080975A2:
	pop {r1}
	bx r1
	thumb_func_end sub_809758C

	thumb_func_start sub_80975A8
sub_80975A8:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x2E
	bl sub_800199C
	pop {r0}
	bx r0
	thumb_func_end sub_80975A8

	thumb_func_start sub_80975C4
sub_80975C4:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2728
	lsls r0, 24
	lsrs r0, 24
	bl GetDungeonName1
	pop {r1}
	bx r1
	thumb_func_end sub_80975C4

	thumb_func_start sub_80975DC
sub_80975DC:
	push {lr}
	lsls r0, 16
	ldr r1, _08097600
	adds r0, r1
	lsrs r0, 16
	cmp r0, 0x1
	bhi _08097610
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xE
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08097608
	ldr r0, _08097604
	b _08097612
	.align 2, 0
_08097600: .4byte 0xffe90000
_08097604: .4byte gUnknown_8109CD4
_08097608:
	ldr r0, _0809760C
	b _08097612
	.align 2, 0
_0809760C: .4byte gUnknown_8109CE4
_08097610:
	ldr r0, _08097618
_08097612:
	pop {r1}
	bx r1
	.align 2, 0
_08097618: .4byte gUnknown_8109CF4
	thumb_func_end sub_80975DC

	thumb_func_start sub_809761C
sub_809761C:
	push {r4,lr}
	movs r4, 0
_08097620:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_809758C
	lsls r0, 24
	cmp r0, 0
	bne _08097632
	movs r0, 0
	b _0809763A
_08097632:
	adds r4, 0x1
	cmp r4, 0x10
	ble _08097620
	movs r0, 0x1
_0809763A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809761C

	thumb_func_start sub_8097640
sub_8097640:
	push {lr}
	movs r0, 0
	movs r1, 0x2E
	movs r2, 0x1F
	bl sub_8001784
	cmp r0, 0
	bne _0809766A
	bl sub_809761C
	lsls r0, 24
	cmp r0, 0
	beq _0809766A
	movs r0, 0
	movs r1, 0x2E
	movs r2, 0x1F
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0x1
	b _0809766C
_0809766A:
	movs r0, 0
_0809766C:
	pop {r1}
	bx r1
	thumb_func_end sub_8097640

	thumb_func_start sub_8097670
sub_8097670:
	ldr r1, _08097678
	ldr r0, _0809767C
	str r0, [r1]
	bx lr
	.align 2, 0
_08097678: .4byte gUnknown_203B494
_0809767C: .4byte gUnknown_2039778
	thumb_func_end sub_8097670

	thumb_func_start sub_8097680
sub_8097680:
	ldr r0, _08097684
	bx lr
	.align 2, 0
_08097684: .4byte gUnknown_2039778
	thumb_func_end sub_8097680

	thumb_func_start sub_8097688
sub_8097688:
	ldr r3, _08097698
	ldr r2, [r3]
	ldrb r1, [r0]
	strb r1, [r2, 0x10]
	ldr r1, [r3]
	ldrb r0, [r0, 0x1]
	strb r0, [r1, 0x11]
	bx lr
	.align 2, 0
_08097698: .4byte gUnknown_203B494
	thumb_func_end sub_8097688

	thumb_func_start sub_809769C
sub_809769C:
	ldr r0, _080976A4
	ldr r0, [r0]
	adds r0, 0x10
	bx lr
	.align 2, 0
_080976A4: .4byte gUnknown_203B494
	thumb_func_end sub_809769C

	thumb_func_start sub_80976A8
sub_80976A8:
	push {r4,lr}
	ldr r3, _080976F4
	ldr r1, [r3]
	movs r0, 0
	str r0, [r1]
	strh r0, [r1, 0x14]
	strh r0, [r1, 0x16]
	strh r0, [r1, 0x18]
	adds r2, r1, 0
	adds r2, 0xC0
	str r0, [r2]
	str r0, [r1, 0x8]
	str r0, [r1, 0xC]
	movs r2, 0
	adds r4, r3, 0
	movs r3, 0
_080976C8:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x1C
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0xD
	ble _080976C8
	movs r2, 0
	ldr r4, _080976F4
	movs r3, 0
_080976DE:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x8C
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0xC
	ble _080976DE
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080976F4: .4byte gUnknown_203B494
	thumb_func_end sub_80976A8

	thumb_func_start sub_80976F8
sub_80976F8:
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0809770C
	ldr r2, [r1]
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0809770C: .4byte gUnknown_203B494
	thumb_func_end sub_80976F8

	thumb_func_start sub_8097710
sub_8097710:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0809772C
	ldr r2, [r1]
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _08097730
	movs r0, 0
	b _08097732
	.align 2, 0
_0809772C: .4byte gUnknown_203B494
_08097730:
	movs r0, 0x1
_08097732:
	pop {r1}
	bx r1
	thumb_func_end sub_8097710

	thumb_func_start sub_8097738
sub_8097738:
	lsls r0, 24
	ldr r1, _08097744
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08097744: .4byte gUnknown_810B04C
	thumb_func_end sub_8097738

	thumb_func_start sub_8097748
sub_8097748:
	ldr r0, _08097754
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_08097754: .4byte gUnknown_203B494
	thumb_func_end sub_8097748

	thumb_func_start sub_8097758
sub_8097758:
	push {lr}
	ldr r0, _08097770
	ldr r1, [r0]
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	ldr r2, _08097774
	cmp r0, r2
	ble _0809776C
	str r2, [r1, 0x4]
_0809776C:
	pop {r0}
	bx r0
	.align 2, 0
_08097770: .4byte gUnknown_203B494
_08097774: .4byte 0x0001869f
	thumb_func_end sub_8097758

	thumb_func_start sub_8097778
sub_8097778:
	ldr r0, _08097780
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bx lr
	.align 2, 0
_08097780: .4byte gUnknown_203B494
	thumb_func_end sub_8097778

	thumb_func_start sub_8097784
sub_8097784:
	ldr r1, _0809778C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_0809778C: .4byte gUnknown_203B494
	thumb_func_end sub_8097784

	thumb_func_start sub_8097790
sub_8097790:
	push {lr}
	ldr r0, _080977B0
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	adds r0, 0x1
	str r0, [r1, 0x8]
	ldr r2, _080977B4
	cmp r0, r2
	ble _080977A4
	str r2, [r1, 0x8]
_080977A4:
	movs r0, 0x8
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_080977B0: .4byte gUnknown_203B494
_080977B4: .4byte 0x0001869f
	thumb_func_end sub_8097790

	thumb_func_start sub_80977B8
sub_80977B8:
	ldr r0, _080977C0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bx lr
	.align 2, 0
_080977C0: .4byte gUnknown_203B494
	thumb_func_end sub_80977B8

	thumb_func_start sub_80977C4
sub_80977C4:
	ldr r1, _080977CC
	ldr r1, [r1]
	str r0, [r1, 0x8]
	bx lr
	.align 2, 0
_080977CC: .4byte gUnknown_203B494
	thumb_func_end sub_80977C4

	thumb_func_start sub_80977D0
sub_80977D0:
	push {lr}
	ldr r0, _080977F0
	ldr r1, [r0]
	ldr r0, [r1, 0xC]
	adds r0, 0x1
	str r0, [r1, 0xC]
	ldr r2, _080977F4
	cmp r0, r2
	ble _080977E4
	str r2, [r1, 0xC]
_080977E4:
	movs r0, 0x9
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_080977F0: .4byte gUnknown_203B494
_080977F4: .4byte 0x0001869f
	thumb_func_end sub_80977D0

	thumb_func_start sub_80977F8
sub_80977F8:
	ldr r0, _08097800
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bx lr
	.align 2, 0
_08097800: .4byte gUnknown_203B494
	thumb_func_end sub_80977F8

	thumb_func_start sub_8097804
sub_8097804:
	ldr r1, _0809780C
	ldr r1, [r1]
	str r0, [r1, 0xC]
	bx lr
	.align 2, 0
_0809780C: .4byte gUnknown_203B494
	thumb_func_end sub_8097804

	thumb_func_start sub_8097810
sub_8097810:
	push {lr}
	ldr r0, _08097830
	ldr r2, [r0]
	ldrh r3, [r2, 0x14]
	movs r0, 0x14
	ldrsh r1, [r2, r0]
	ldr r0, _08097834
	cmp r1, r0
	bgt _08097826
	adds r0, r3, 0x1
	strh r0, [r2, 0x14]
_08097826:
	movs r0, 0xB
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_08097830: .4byte gUnknown_203B494
_08097834: .4byte 0x0000270e
	thumb_func_end sub_8097810

	thumb_func_start sub_8097838
sub_8097838:
	ldr r0, _08097844
	ldr r0, [r0]
	movs r1, 0x14
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08097844: .4byte gUnknown_203B494
	thumb_func_end sub_8097838

	thumb_func_start sub_8097848
sub_8097848:
	push {lr}
	ldr r0, _08097868
	ldr r2, [r0]
	ldrh r3, [r2, 0x16]
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	ldr r0, _0809786C
	cmp r1, r0
	bgt _0809785E
	adds r0, r3, 0x1
	strh r0, [r2, 0x16]
_0809785E:
	movs r0, 0xA
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_08097868: .4byte gUnknown_203B494
_0809786C: .4byte 0x0000270e
	thumb_func_end sub_8097848

	thumb_func_start sub_8097870
sub_8097870:
	ldr r0, _0809787C
	ldr r0, [r0]
	movs r1, 0x16
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0809787C: .4byte gUnknown_203B494
	thumb_func_end sub_8097870

	thumb_func_start sub_8097880
sub_8097880:
	ldr r0, _0809788C
	ldr r0, [r0]
	movs r1, 0x18
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0809788C: .4byte gUnknown_203B494
	thumb_func_end sub_8097880

	thumb_func_start sub_8097890
sub_8097890:
	push {lr}
	ldr r0, _080978B0
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0xC0
	ldr r1, [r2]
	ldr r0, _080978B4
	cmp r1, r0
	bgt _080978A6
	adds r0, r1, 0x1
	str r0, [r2]
_080978A6:
	movs r0, 0xC
	bl sub_80976F8
	pop {r0}
	bx r0
	.align 2, 0
_080978B0: .4byte gUnknown_203B494
_080978B4: .4byte 0x0001869e
	thumb_func_end sub_8097890

	thumb_func_start sub_80978B8
sub_80978B8:
	ldr r0, _080978C4
	ldr r0, [r0]
	adds r0, 0xC0
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080978C4: .4byte gUnknown_203B494
	thumb_func_end sub_80978B8

	thumb_func_start sub_80978C8
sub_80978C8:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E858
	lsls r0, 16
	asrs r3, r0, 16
	ldr r0, _080978FC
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _080978E2
	adds r0, 0x1F
_080978E2:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x54
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080978FC: .4byte gUnknown_203B494
	thumb_func_end sub_80978C8

	thumb_func_start sub_8097900
sub_8097900:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E858
	lsls r0, 16
	asrs r3, r0, 16
	ldr r0, _08097938
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _0809791A
	adds r0, 0x1F
_0809791A:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x1C
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _0809793C
	movs r0, 0
	b _0809793E
	.align 2, 0
_08097938: .4byte gUnknown_203B494
_0809793C:
	movs r0, 0x1
_0809793E:
	pop {r1}
	bx r1
	thumb_func_end sub_8097900

	thumb_func_start sub_8097944
sub_8097944:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0x1
	str r0, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	movs r0, 0xD
	bl sub_8097710
	lsls r0, 24
	cmp r0, 0
	bne _08097974
	bl sub_8092614
	lsls r0, 24
	cmp r0, 0
	beq _08097974
	movs r0, 0xD
	bl sub_80976F8
_08097974:
	movs r4, 0
	ldr r0, _08097B5C
	mov r10, r0
	mov r8, r4
_0809797C:
	ldr r1, _08097B60
	ldr r0, [r1]
	mov r1, r8
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080979F6
	movs r0, 0x8
	ldrsh r3, [r2, r0]
	mov r1, r10
	ldr r2, [r1]
	adds r0, r3, 0
	cmp r3, 0
	bge _0809799E
	adds r0, 0x1F
_0809799E:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x1C
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08097B60
	mov r9, r0
	mov r12, r8
	movs r7, 0x1
	movs r6, 0x2C
	movs r5, 0x3
_080979C0:
	mov r1, r9
	ldr r0, [r1]
	add r0, r12
	adds r3, r0, r6
	ldrb r1, [r3]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080979EE
	mov r0, r10
	ldr r2, [r0]
	ldrh r3, [r3, 0x2]
	lsrs r0, r3, 5
	lsls r0, 2
	adds r2, 0x8C
	adds r2, r0
	movs r0, 0x1F
	ands r3, r0
	adds r1, r7, 0
	lsls r1, r3
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080979EE:
	adds r6, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _080979C0
_080979F6:
	movs r1, 0x58
	add r8, r1
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0809797C
	movs r4, 0
	ldr r1, _08097B64
_08097A08:
	cmp r4, 0
	bne _08097A0E
	b _08097B80
_08097A0E:
	ldr r0, _08097B68
	cmp r4, r0
	bne _08097A16
	b _08097B80
_08097A16:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A1E
	b _08097B80
_08097A1E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A26
	b _08097B80
_08097A26:
	adds r0, 0x26
	cmp r4, r0
	bne _08097A2E
	b _08097B80
_08097A2E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A36
	b _08097B80
_08097A36:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A3E
	b _08097B80
_08097A3E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A46
	b _08097B80
_08097A46:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A4E
	b _08097B80
_08097A4E:
	adds r0, 0x1
	cmp r4, r0
	bne _08097A56
	b _08097B80
_08097A56:
	cmp r4, r1
	bne _08097A5C
	b _08097B80
_08097A5C:
	ldr r0, _08097B5C
	ldr r5, [r0]
	adds r0, r4, 0
	cmp r4, 0
	bge _08097A68
	adds r0, 0x1F
_08097A68:
	asrs r0, 5
	lsls r3, r0, 2
	adds r1, r5, 0
	adds r1, 0x54
	adds r1, r3
	lsls r0, 5
	subs r0, r4, r0
	movs r2, 0x1
	lsls r2, r0
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	bne _08097A86
	movs r0, 0
	str r0, [sp, 0x4]
_08097A86:
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r3
	ldr r0, [r0]
	ands r0, r2
	cmp r0, 0
	beq _08097B7C
	cmp r4, 0x92
	bne _08097A9E
	movs r0, 0x10
	bl sub_80976F8
_08097A9E:
	cmp r4, 0x91
	bne _08097AA8
	movs r0, 0x11
	bl sub_80976F8
_08097AA8:
	cmp r4, 0x90
	bne _08097AB2
	movs r0, 0x12
	bl sub_80976F8
_08097AB2:
	movs r0, 0xCF
	lsls r0, 1
	cmp r4, r0
	bne _08097AC0
	movs r0, 0x13
	bl sub_80976F8
_08097AC0:
	ldr r0, _08097B6C
	cmp r4, r0
	bne _08097ACC
	movs r0, 0x14
	bl sub_80976F8
_08097ACC:
	movs r0, 0x86
	lsls r0, 1
	cmp r4, r0
	bne _08097ADA
	movs r0, 0x15
	bl sub_80976F8
_08097ADA:
	movs r0, 0x87
	lsls r0, 1
	cmp r4, r0
	bne _08097AE8
	movs r0, 0x16
	bl sub_80976F8
_08097AE8:
	ldr r0, _08097B70
	cmp r4, r0
	bne _08097AF4
	movs r0, 0x17
	bl sub_80976F8
_08097AF4:
	movs r0, 0xCD
	lsls r0, 1
	cmp r4, r0
	bne _08097B02
	movs r0, 0x18
	bl sub_80976F8
_08097B02:
	ldr r0, _08097B74
	cmp r4, r0
	bne _08097B0E
	movs r0, 0x19
	bl sub_80976F8
_08097B0E:
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bne _08097B1C
	movs r0, 0x1A
	bl sub_80976F8
_08097B1C:
	movs r0, 0x89
	lsls r0, 1
	cmp r4, r0
	bne _08097B2A
	movs r0, 0x1B
	bl sub_80976F8
_08097B2A:
	movs r0, 0x8A
	lsls r0, 1
	cmp r4, r0
	bne _08097B38
	movs r0, 0x1C
	bl sub_80976F8
_08097B38:
	cmp r4, 0x97
	bne _08097B42
	movs r0, 0x1D
	bl sub_80976F8
_08097B42:
	cmp r4, 0x96
	bne _08097B4C
	movs r0, 0x1E
	bl sub_80976F8
_08097B4C:
	ldr r0, _08097B78
	cmp r4, r0
	bne _08097B80
	movs r0, 0x1F
	bl sub_80976F8
	b _08097B80
	.align 2, 0
_08097B5C: .4byte gUnknown_203B494
_08097B60: .4byte gUnknown_203B45C
_08097B64: .4byte 0x000001a7
_08097B68: .4byte 0x00000179
_08097B6C: .4byte 0x0000010d
_08097B70: .4byte 0x00000113
_08097B74: .4byte 0x0000019b
_08097B78: .4byte 0x0000019d
_08097B7C:
	movs r1, 0
	str r1, [sp]
_08097B80:
	adds r4, 0x1
	ldr r1, _08097C0C
	cmp r4, r1
	bgt _08097B8A
	b _08097A08
_08097B8A:
	ldr r0, [sp]
	cmp r0, 0
	beq _08097B96
	movs r0, 0xF
	bl sub_80976F8
_08097B96:
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _08097BA2
	movs r0, 0xE
	bl sub_80976F8
_08097BA2:
	movs r3, 0
	movs r4, 0
_08097BA6:
	cmp r4, 0
	beq _08097BE2
	ldr r0, _08097C10
	cmp r4, r0
	beq _08097BE2
	adds r0, 0x1
	cmp r4, r0
	beq _08097BE2
	adds r0, 0x1
	cmp r4, r0
	beq _08097BE2
	ldr r0, _08097C14
	ldr r2, [r0]
	adds r0, r4, 0
	cmp r4, 0
	bge _08097BC8
	adds r0, 0x1F
_08097BC8:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x8C
	adds r2, r1
	lsls r0, 5
	subs r0, r4, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _08097BE2
	adds r3, 0x1
_08097BE2:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08097BA6
	cmp r3, 0
	beq _08097BFC
	ldr r0, _08097C14
	ldr r0, [r0]
	strh r3, [r0, 0x18]
	movs r0, 0x7
	bl sub_80976F8
_08097BFC:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097C0C: .4byte 0x000001a7
_08097C10: .4byte 0x00000163
_08097C14: .4byte gUnknown_203B494
	thumb_func_end sub_8097944

	thumb_func_start sub_8097C18
sub_8097C18:
	push {r4-r6,lr}
	adds r5, r0, 0
	bl sub_8097944
	ldr r4, _08097CBC
	ldr r1, [r4]
	adds r1, 0x4
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x16
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x18
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0xC0
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x1C
	movs r6, 0xE0
	lsls r6, 1
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x54
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x8C
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r5, 0
	bl sub_809488C
	ldr r1, [r4]
	adds r1, 0x10
	adds r0, r5, 0
	bl sub_80902F4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097CBC: .4byte gUnknown_203B494
	thumb_func_end sub_8097C18

	thumb_func_start sub_8097CC0
sub_8097CC0:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _08097D5C
	ldr r1, [r4]
	adds r1, 0x4
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0xC
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r0, r5, 0
	movs r2, 0x20
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x16
	adds r0, r5, 0
	movs r2, 0xE
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x18
	adds r0, r5, 0
	movs r2, 0x9
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0xC0
	adds r0, r5, 0
	movs r2, 0x11
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x1C
	movs r6, 0xE0
	lsls r6, 1
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x54
	adds r0, r5, 0
	adds r2, r6, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x8C
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r5, 0
	bl sub_8094924
	ldr r1, [r4]
	adds r1, 0x10
	adds r0, r5, 0
	bl sub_8090314
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097D5C: .4byte gUnknown_203B494
	thumb_func_end sub_8097CC0

	thumb_func_start sub_8097D60
sub_8097D60:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809486C
	mov r0, sp
	bl sub_8094A44
	mov r0, sp
	bl sub_8095044
	mov r0, sp
	bl sub_8097C18
	mov r0, sp
	bl sub_8098248
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r1}
	bx r1
	thumb_func_end sub_8097D60

	thumb_func_start sub_8097D98
sub_8097D98:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_809485C
	mov r0, sp
	bl sub_8094B18
	mov r0, sp
	bl sub_8095080
	mov r0, sp
	bl sub_8097CC0
	mov r0, sp
	bl sub_8098308
	mov r0, sp
	bl nullsub_102
	ldr r0, [sp, 0x8]
	add sp, 0x10
	pop {r1}
	bx r1
	thumb_func_end sub_8097D98

	thumb_func_start sub_8097DD0
sub_8097DD0:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _08097DEA
	ldr r1, [r2, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bne _08097DEA
	movs r0, 0x1
	b _08097DEC
_08097DEA:
	movs r0, 0
_08097DEC:
	pop {r1}
	bx r1
	thumb_func_end sub_8097DD0

	thumb_func_start sub_8097DF0
sub_8097DF0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1F8
	mov r8, r0
	str r1, [sp, 0x1F0]
	movs r0, 0
	mov r9, r0
	movs r7, 0
	ldr r1, _08097E3C
	ldr r0, [r1]
	cmp r0, 0
	beq _08097E6E
_08097E0E:
	movs r4, 0
	lsls r5, r7, 3
	lsls r1, r7, 2
	mov r10, r1
	adds r6, r7, 0x1
	ldr r2, _08097E3C
	adds r3, r5, r2
	add r1, sp, 0x18C
_08097E1E:
	ldr r0, [r3]
	adds r0, r4
	ldrb r2, [r0]
	cmp r2, 0x23
	bne _08097E40
	ldrb r0, [r0, 0x1]
	cmp r0, 0x72
	bne _08097E40
	strb r2, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0
	strb r0, [r1]
	b _08097E50
	.align 2, 0
_08097E3C: .4byte gUnknown_810E074
_08097E40:
	ldr r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x63
	ble _08097E1E
_08097E50:
	add r0, sp, 0x18C
	bl strlen
	mov r1, sp
	add r1, r10
	str r0, [r1]
	adds r7, r6, 0
	cmp r6, 0x62
	bgt _08097E6E
	lsls r0, r6, 3
	ldr r1, _08097EB4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _08097E0E
_08097E6E:
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0
	beq _08097F2C
	ldr r3, _08097EB4
_08097E78:
	cmp r0, 0x23
	bne _08097F08
	movs r7, 0
	adds r1, r3, 0
	ldr r0, [r1]
	cmp r0, 0
	beq _08097F20
	mov r2, r9
	lsls r0, r2, 2
	ldr r2, [sp, 0x1F0]
	adds r0, r2
	mov r10, r0
_08097E90:
	lsls r4, r7, 3
	adds r0, r4, r1
	ldr r0, [r0]
	lsls r1, r7, 2
	add r1, sp
	ldr r2, [r1]
	mov r1, r8
	str r3, [sp, 0x1F4]
	bl sub_800B2D4
	lsls r0, 24
	adds r5, r4, 0
	adds r6, r7, 0x1
	ldr r3, [sp, 0x1F4]
	cmp r0, 0
	bne _08097EF0
	movs r4, 0
	b _08097EBA
	.align 2, 0
_08097EB4: .4byte gUnknown_810E074
_08097EB8:
	adds r4, 0x1
_08097EBA:
	cmp r4, r9
	bge _08097ED6
	adds r0, r5, r3
	lsls r1, r4, 2
	ldr r2, [sp, 0x1F0]
	adds r1, r2
	ldr r1, [r1]
	str r3, [sp, 0x1F4]
	bl sub_8097DD0
	lsls r0, 24
	ldr r3, [sp, 0x1F4]
	cmp r0, 0
	beq _08097EB8
_08097ED6:
	cmp r4, r9
	bne _08097EF0
	mov r0, r9
	cmp r0, 0x3
	bgt _08097EF0
	adds r0, r5, r3
	mov r1, r10
	adds r1, 0x4
	mov r10, r1
	subs r1, 0x4
	stm r1!, {r0}
	movs r2, 0x1
	add r9, r2
_08097EF0:
	adds r7, r6, 0
	cmp r6, 0x62
	bgt _08097F20
	ldr r1, _08097F04
	lsls r0, r6, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _08097E90
	b _08097F20
	.align 2, 0
_08097F04: .4byte gUnknown_810E074
_08097F08:
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r1, 0
	adds r0, 0x7F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08097F1C
	cmp r1, 0x87
	bne _08097F20
_08097F1C:
	movs r1, 0x1
	add r8, r1
_08097F20:
	movs r2, 0x1
	add r8, r2
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	bne _08097E78
_08097F2C:
	mov r0, r9
	add sp, 0x1F8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8097DF0

	thumb_func_start sub_8097F40
sub_8097F40:
	push {lr}
	movs r2, 0
	ldr r1, _08097F58
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08097F50
	movs r2, 0x1
_08097F50:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.align 2, 0
_08097F58: .4byte gUnknown_810ACC0
	thumb_func_end sub_8097F40

	thumb_func_start sub_8097F5C
sub_8097F5C:
	ldr r1, _08097F64
	ldr r0, _08097F68
	str r0, [r1]
	bx lr
	.align 2, 0
_08097F64: .4byte gUnknown_203B498
_08097F68: .4byte gUnknown_2039840
	thumb_func_end sub_8097F5C

	thumb_func_start sub_8097F6C
sub_8097F6C:
	ldr r0, _08097F70
	bx lr
	.align 2, 0
_08097F70: .4byte gUnknown_2039840
	thumb_func_end sub_8097F6C

	thumb_func_start sub_8097F74
sub_8097F74:
	push {r4,lr}
	ldr r4, _08097FA0
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x64
	bl memset
	movs r2, 0
	ldr r3, _08097FA4
_08097F86:
	ldr r0, [r4]
	adds r0, 0x58
	adds r0, r2
	ldrb r1, [r3, 0x2]
	strb r1, [r0]
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, 0xB
	ble _08097F86
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097FA0: .4byte gUnknown_203B498
_08097FA4: .4byte gUnknown_810AD0C
	thumb_func_end sub_8097F74

	thumb_func_start sub_8097FA8
sub_8097FA8:
	lsls r0, 24
	ldr r1, _08097FCC
	ldr r3, [r1]
	lsrs r1, r0, 29
	lsls r1, 2
	adds r3, 0x48
	adds r3, r1
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	bx lr
	.align 2, 0
_08097FCC: .4byte gUnknown_203B498
	thumb_func_end sub_8097FA8

	thumb_func_start sub_8097FD0
sub_8097FD0:
	lsls r0, 24
	ldr r1, _08097FF4
	ldr r3, [r1]
	lsrs r1, r0, 29
	lsls r1, 2
	adds r3, 0x3C
	adds r3, r1
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	bx lr
	.align 2, 0
_08097FF4: .4byte gUnknown_203B498
	thumb_func_end sub_8097FD0

	thumb_func_start sub_8097FF8
sub_8097FF8:
	push {r4-r7,lr}
	movs r4, 0
	ldr r6, _08098040
	movs r7, 0x1
_08098000:
	ldr r5, [r6]
	adds r0, r4, 0
	cmp r4, 0
	bge _0809800A
	adds r0, 0x1F
_0809800A:
	asrs r0, 5
	lsls r3, r0, 2
	adds r1, r5, 0
	adds r1, 0x48
	adds r1, r3
	lsls r0, 5
	subs r0, r4, r0
	adds r2, r7, 0
	lsls r2, r0
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	beq _08098030
	adds r1, r5, 0
	adds r1, 0x3C
	adds r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08098030:
	adds r4, 0x1
	cmp r4, 0x3F
	ble _08098000
	bl sub_8098080
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098040: .4byte gUnknown_203B498
	thumb_func_end sub_8097FF8

	thumb_func_start sub_8098044
sub_8098044:
	push {r4,r5,lr}
	lsls r0, 24
	ldr r1, _0809807C
	ldr r3, [r1]
	lsrs r5, r0, 29
	lsls r5, 2
	adds r4, r3, 0
	adds r4, 0x3C
	adds r4, r5
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	mvns r2, r2
	ldr r0, [r4]
	ands r0, r2
	str r0, [r4]
	adds r3, 0x48
	adds r3, r5
	ldr r0, [r3]
	ands r0, r2
	str r0, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809807C: .4byte gUnknown_203B498
	thumb_func_end sub_8098044

	thumb_func_start sub_8098080
sub_8098080:
	push {r4,lr}
	movs r2, 0
	ldr r4, _080980A0
	movs r3, 0
_08098088:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x48
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0x2
	ble _08098088
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080980A0: .4byte gUnknown_203B498
	thumb_func_end sub_8098080

	thumb_func_start sub_80980A4
sub_80980A4:
	ldr r0, _080980B0
	ldr r2, [r0]
	ldrb r0, [r2]
	movs r1, 0x1
	strb r1, [r2]
	bx lr
	.align 2, 0
_080980B0: .4byte gUnknown_203B498
	thumb_func_end sub_80980A4

	thumb_func_start sub_80980B4
sub_80980B4:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r3, r1, 0
	ldr r0, _080980F8
	cmp r1, r0
	beq _080980F4
	adds r0, 0x1
	cmp r1, r0
	beq _080980F4
	adds r0, 0x1
	cmp r1, r0
	beq _080980F4
	ldr r0, _080980FC
	ldr r2, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _080980DA
	adds r0, 0x1F
_080980DA:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x4
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080980F4:
	pop {r0}
	bx r0
	.align 2, 0
_080980F8: .4byte 0x000001a5
_080980FC: .4byte gUnknown_203B498
	thumb_func_end sub_80980B4

	thumb_func_start sub_8098100
sub_8098100:
	push {lr}
	lsls r1, r0, 24
	lsrs r3, r1, 24
	cmp r3, 0x3F
	bls _0809810E
	movs r0, 0
	b _0809812C
_0809810E:
	ldr r0, _08098130
	ldr r2, [r0]
	lsrs r0, r1, 29
	lsls r0, 2
	adds r2, 0x3C
	adds r2, r0
	movs r0, 0x1F
	ands r0, r3
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _0809812C
	movs r0, 0x1
_0809812C:
	pop {r1}
	bx r1
	.align 2, 0
_08098130: .4byte gUnknown_203B498
	thumb_func_end sub_8098100

	thumb_func_start sub_8098134
sub_8098134:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r3, r1, 0
	ldr r0, _0809816C
	ldr r2, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08098148
	adds r0, 0x1F
_08098148:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x4
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _08098166
	movs r0, 0x1
_08098166:
	pop {r1}
	bx r1
	.align 2, 0
_0809816C: .4byte gUnknown_203B498
	thumb_func_end sub_8098134

	thumb_func_start sub_8098170
sub_8098170:
	push {lr}
	adds r3, r0, 0
	ldr r0, _0809819C
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _08098180
	adds r0, 0x1F
_08098180:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x54
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0809819C: .4byte gUnknown_203B498
	thumb_func_end sub_8098170

	thumb_func_start sub_80981A0
sub_80981A0:
	push {lr}
	adds r3, r0, 0
	cmp r3, 0x1E
	ble _080981AC
	movs r0, 0
	b _080981D4
_080981AC:
	ldr r0, _080981D8
	ldr r2, [r0]
	adds r1, r3, 0
	cmp r3, 0
	bge _080981B8
	adds r1, 0x1F
_080981B8:
	asrs r1, 5
	lsls r0, r1, 2
	adds r2, 0x54
	adds r2, r0
	lsls r1, 5
	subs r1, r3, r1
	movs r0, 0x1
	lsls r0, r1
	ldr r2, [r2]
	ands r2, r0
	cmp r2, 0
	beq _080981D2
	movs r2, 0x1
_080981D2:
	adds r0, r2, 0
_080981D4:
	pop {r1}
	bx r1
	.align 2, 0
_080981D8: .4byte gUnknown_203B498
	thumb_func_end sub_80981A0

	thumb_func_start sub_80981DC
sub_80981DC:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r3, r0, 16
	movs r1, 0
	ldr r4, _080981FC
	ldr r2, _08098200
_080981E8:
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, r3
	bne _08098204
	ldr r0, [r4]
	adds r0, 0x58
	adds r0, r1
	ldrb r0, [r0]
	b _0809820E
	.align 2, 0
_080981FC: .4byte gUnknown_203B498
_08098200: .4byte gUnknown_810AD0C
_08098204:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0xB
	ble _080981E8
	movs r0, 0x1
_0809820E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80981DC

	thumb_func_start sub_8098214
sub_8098214:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r3, r0, 16
	movs r1, 0
	ldr r5, _08098240
	movs r4, 0x1
	ldr r2, _08098244
_08098222:
	movs r6, 0
	ldrsh r0, [r2, r6]
	cmp r0, r3
	bne _08098232
	ldr r0, [r5]
	adds r0, 0x58
	adds r0, r1
	strb r4, [r0]
_08098232:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0xB
	ble _08098222
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098240: .4byte gUnknown_203B498
_08098244: .4byte gUnknown_810AD0C
	thumb_func_end sub_8098214

	thumb_func_start sub_8098248
sub_8098248:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r7, r0, 0
	mov r5, sp
	adds r5, 0x3
	movs r0, 0xFF
	strb r0, [r5]
	add r4, sp, 0x4
	movs r0, 0
	strb r0, [r4]
	ldr r0, _08098300
	ldr r1, [r0]
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_809488C
	movs r6, 0
	mov r9, r5
	mov r8, r4
	mov r4, sp
	adds r4, 0x1
	mov r5, sp
	adds r5, 0x2
_0809827C:
	lsls r0, r6, 16
	asrs r0, 16
	bl sub_8098134
	mov r1, sp
	strb r0, [r1]
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	ldr r0, _08098304
	cmp r6, r0
	ble _0809827C
	movs r6, 0
_0809829A:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8098100
	strb r0, [r4]
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	cmp r6, 0x3F
	ble _0809829A
	movs r6, 0
	adds r4, r5, 0
_080982B8:
	adds r0, r6, 0
	bl sub_80981A0
	strb r0, [r4]
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	cmp r6, 0x1E
	ble _080982B8
	movs r6, 0
_080982D2:
	ldr r0, _08098300
	ldr r0, [r0]
	adds r0, 0x58
	adds r0, r6
	ldrb r0, [r0]
	mov r1, r8
	cmp r0, 0
	beq _080982E4
	mov r1, r9
_080982E4:
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_809488C
	adds r6, 0x1
	cmp r6, 0xB
	ble _080982D2
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098300: .4byte gUnknown_203B498
_08098304: .4byte 0x000001a7
	thumb_func_end sub_8098248

	thumb_func_start sub_8098308
sub_8098308:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r4, _080983D0
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x64
	bl memset
	ldr r1, [r4]
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8094924
	movs r4, 0
	mov r5, sp
	adds r5, 0x1
	mov r7, sp
	adds r7, 0x2
	movs r0, 0x3
	add r0, sp
	mov r8, r0
_08098338:
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8094924
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098352
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_80980B4
_08098352:
	adds r4, 0x1
	ldr r0, _080983D4
	cmp r4, r0
	ble _08098338
	movs r4, 0
_0809835C:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094924
	ldrb r0, [r5]
	cmp r0, 0
	beq _08098374
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8097FA8
_08098374:
	adds r4, 0x1
	cmp r4, 0x3F
	ble _0809835C
	movs r4, 0
	adds r5, r7, 0
_0809837E:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8094924
	ldrb r0, [r5]
	cmp r0, 0
	beq _08098394
	adds r0, r4, 0
	bl sub_8098170
_08098394:
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809837E
	movs r4, 0
_0809839C:
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0x1
	bl sub_8094924
	ldr r0, _080983D0
	ldr r1, [r0]
	adds r1, 0x58
	adds r1, r4
	mov r0, sp
	adds r0, 0x3
	ldrb r2, [r0]
	movs r0, 0x1
	ands r0, r2
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0xB
	ble _0809839C
	bl sub_8097FF8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080983D0: .4byte gUnknown_203B498
_080983D4: .4byte 0x000001a7
	thumb_func_end sub_8098308

	thumb_func_start sub_80983D8
sub_80983D8:
	push {r4,lr}
	movs r2, 0
	ldrsh r3, [r1, r2]
	movs r4, 0
	ldrsh r2, [r0, r4]
	subs r2, r3, r2
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	subs r1, r0
	cmp r2, 0
	bne _080983FA
	cmp r1, 0
	bne _080983FA
	movs r0, 0
	b _08098428
_080983FA:
	cmp r2, 0
	ble _08098400
	movs r2, 0x1
_08098400:
	cmp r1, 0
	ble _08098406
	movs r1, 0x1
_08098406:
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bgt _08098410
	adds r2, r0, 0
_08098410:
	cmp r1, r0
	bgt _08098416
	adds r1, r0, 0
_08098416:
	ldr r3, _08098430
	adds r2, 0x1
	adds r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
_08098428:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08098430: .4byte gUnknown_8115E94
	thumb_func_end sub_80983D8

	thumb_func_start sub_8098434
sub_8098434:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r2, 0
	ldrsh r0, [r4, r2]
	subs r2, r1, r0
	cmp r2, 0
	bge _0809844A
	negs r2, r2
_0809844A:
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, 0
	bge _0809845A
	negs r0, r0
_0809845A:
	cmp r0, r2
	bge _08098460
	adds r0, r2, 0
_08098460:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098434

	thumb_func_start xxx_script_related_8098468
xxx_script_related_8098468:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, _08098494
	str r0, [r1]
	ldr r4, _08098498
	movs r2, 0
	strb r2, [r4]
	ldr r3, _0809849C
	movs r1, 0x1
	strb r1, [r3]
	ldr r1, _080984A0
	strb r2, [r1]
	subs r0, 0xD
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _08098504
	lsls r0, 2
	ldr r1, _080984A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098494: .4byte gUnknown_20398B4
_08098498: .4byte gUnknown_20398B9
_0809849C: .4byte gUnknown_20398B8
_080984A0: .4byte gUnknown_20398BA
_080984A4: .4byte _080984A8
	.align 2, 0
_080984A8:
	.4byte _080984BC
	.4byte _080984C8
	.4byte _080984CE
	.4byte _080984D4
	.4byte _080984FC
_080984BC:
	movs r1, 0x1
	strb r1, [r2]
	movs r0, 0
	strb r0, [r3]
	strb r1, [r4]
	b _08098504
_080984C8:
	movs r0, 0x1
	strb r0, [r3]
	b _08098502
_080984CE:
	movs r0, 0x1
	strb r0, [r3]
	b _08098502
_080984D4:
	add r2, sp, 0x4
	movs r0, 0x3
	mov r1, sp
	bl sub_8001B88
	ldr r2, _080984F4
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0
	bne _080984EA
	movs r1, 0x1
_080984EA:
	strb r1, [r2]
	ldr r1, _080984F8
	movs r0, 0x1
	strb r0, [r1]
	b _08098504
	.align 2, 0
_080984F4: .4byte gUnknown_20398B8
_080984F8: .4byte gUnknown_20398B9
_080984FC:
	movs r0, 0
	strb r0, [r3]
	movs r0, 0x1
_08098502:
	strb r0, [r4]
_08098504:
	bl sub_801180C
	ldr r0, _080985B0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08098522
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08098522
	movs r0, 0x10
	bl sub_80118C4
_08098522:
	ldr r1, _080985B4
	ldr r2, _080985B8
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	bl xxx_update_some_bg_tiles
	bl sub_8099648
	bl sub_809975C
	bl sub_809D0AC
	bl sub_80A7744
	bl sub_809D490
	bl sub_80A62F0
	bl sub_809C5C4
	bl sub_809A560
	bl sub_809CB50
	bl sub_80A4A7C
	bl nullsub_117
	bl sub_80AD990
	bl sub_80A77F8
	bl sub_80ABB54
	bl sub_80ACB90
	bl sub_809A62C
	ldr r0, _080985BC
	movs r1, 0
	strb r1, [r0]
	ldr r0, _080985C0
	strb r1, [r0]
	ldr r6, _080985C4
	movs r0, 0x1
	str r0, [r6]
	ldr r1, _080985C8
	movs r0, 0
	str r0, [r1]
	ldr r0, _080985CC
	movs r4, 0x1
	negs r4, r4
	str r4, [r0]
	ldr r5, _080985D0
	movs r0, 0
	movs r1, 0xD
	bl sub_8001658
	strh r0, [r5]
	movs r0, 0
	movs r1, 0xE
	bl sub_8001658
	ldr r1, _080985D4
	str r0, [r1]
	ldr r0, _080985D8
	strh r4, [r0]
	adds r7, r4, 0
	ldr r0, [r6]
	b _08098988
	.align 2, 0
_080985B0: .4byte gUnknown_20398B9
_080985B4: .4byte gUnknown_2026E4E
_080985B8: .4byte 0x00000808
_080985BC: .4byte gUnknown_203B49C
_080985C0: .4byte gUnknown_203B49D
_080985C4: .4byte gUnknown_20398A8
_080985C8: .4byte gUnknown_20398AC
_080985CC: .4byte gUnknown_20398B0
_080985D0: .4byte gUnknown_20398BE
_080985D4: .4byte gUnknown_20398C0
_080985D8: .4byte gUnknown_20398C4
_080985DC:
	movs r0, 0x1
	negs r0, r0
	bl sub_809A71C
	bl sub_809A76C
	bl sub_809977C
	ldr r0, _08098600
	ldr r0, [r0]
	cmp r0, 0x11
	bls _080985F6
	b _08098756
_080985F6:
	lsls r0, 2
	ldr r1, _08098604
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098600: .4byte gUnknown_20398B4
_08098604: .4byte _08098608
	.align 2, 0
_08098608:
	.4byte _08098650
	.4byte _08098756
	.4byte _08098660
	.4byte _08098660
	.4byte _08098756
	.4byte _08098666
	.4byte _08098756
	.4byte _08098756
	.4byte _08098756
	.4byte _0809866A
	.4byte _0809866A
	.4byte _0809866A
	.4byte _0809866A
	.4byte _0809870C
	.4byte _08098748
	.4byte _0809874C
	.4byte _08098750
	.4byte _08098754
_08098650:
	bl sub_8098C58
	ldr r1, _0809865C
	movs r0, 0x1
	str r0, [r1]
	b _08098756
	.align 2, 0
_0809865C: .4byte gUnknown_20398B4
_08098660:
	bl sub_8001D88
	b _08098756
_08098666:
	movs r7, 0x70
	b _08098756
_0809866A:
	ldr r0, _080986BC
	ldr r2, [r0]
	movs r0, 0
	movs r1, 0x16
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x25
	movs r2, 0
	bl sub_80018D8
	bl sub_8098C58
	movs r0, 0
	movs r1, 0x15
	movs r2, 0x1
	movs r3, 0x2
	bl sub_800226C
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _08098756
	cmp r4, 0x51
	bne _080986C0
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	b _080986C6
	.align 2, 0
_080986BC: .4byte gUnknown_20398B4
_080986C0:
	adds r0, r4, 0
	bl sub_80A2608
_080986C6:
	movs r1, 0xA
	ldrsh r7, [r0, r1]
	ldr r5, _08098700
	ldr r0, [r5]
	cmp r0, 0x9
	bne _080986E0
	lsls r2, r4, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x31
	movs r3, 0x1
	bl sub_800199C
_080986E0:
	ldr r0, [r5]
	bl sub_8098FCC
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08098756
	ldr r0, _08098704
	strh r1, [r0]
	ldr r1, _08098708
	movs r0, 0
	str r0, [r1]
	b _08098756
	.align 2, 0
_08098700: .4byte gUnknown_20398B4
_08098704: .4byte gUnknown_20398BE
_08098708: .4byte gUnknown_20398C0
_0809870C:
	bl sub_8098C58
	ldr r1, _08098744
	movs r0, 0x1
	str r0, [r1]
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x1
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xF
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xD
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xE
	movs r2, 0
	bl sub_80018D8
	movs r7, 0x71
	b _08098756
	.align 2, 0
_08098744: .4byte gUnknown_20398B4
_08098748:
	movs r7, 0x73
	b _08098756
_0809874C:
	movs r7, 0x74
	b _08098756
_08098750:
	movs r7, 0x75
	b _08098756
_08098754:
	movs r7, 0x76
_08098756:
	ldr r0, _08098790
	ldrb r0, [r0]
	cmp r0, 0
	bne _080987C0
	movs r0, 0
	movs r1, 0xD
	bl sub_8001658
	adds r5, r0, 0
	ldr r4, _08098794
	ldr r2, [r4]
	movs r0, 0
	movs r1, 0x18
	bl sub_80018D8
	ldr r4, [r4]
	cmp r4, 0x1
	beq _080987A6
	cmp r4, 0x3
	bne _0809879C
	ldr r0, _08098798
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0xF
	bl sub_80018D8
	b _080987A6
	.align 2, 0
_08098790: .4byte gUnknown_20398B9
_08098794: .4byte gUnknown_20398B4
_08098798: .4byte gUnknown_20398BE
_0809879C:
	movs r0, 0
	movs r1, 0xF
	adds r2, r5, 0
	bl sub_80018D8
_080987A6:
	ldr r0, _0809882C
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0xD
	bl sub_80018D8
	ldr r0, _08098830
	ldr r2, [r0]
	movs r0, 0
	movs r1, 0xE
	bl sub_80018D8
_080987C0:
	ldr r1, _08098834
	movs r0, 0x2
	str r0, [r1]
	ldr r0, _08098838
	movs r1, 0
	str r1, [r0]
	ldr r0, _0809883C
	str r1, [r0]
	ldr r0, _08098840
	movs r4, 0x1
	negs r4, r4
	str r4, [r0]
	ldr r2, _08098844
	ldr r1, _0809882C
	ldrh r0, [r1]
	strh r0, [r2]
	strh r4, [r1]
	bl sub_809977C
	bl sub_809D4B0
	adds r0, r4, 0
	bl GroundSprite_Reset
	bl sub_809C63C
	bl sub_809A62C
	bl sub_80A4AEC
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
	bl sub_809C658
	bl nullsub_16
	bl sub_8097944
	cmp r7, r4
	beq _08098848
	adds r0, r7, 0
	movs r1, 0
	bl GroundMap_ExecuteEvent
	b _08098850
	.align 2, 0
_0809882C: .4byte gUnknown_20398BE
_08098830: .4byte gUnknown_20398C0
_08098834: .4byte gUnknown_20398B4
_08098838: .4byte gUnknown_20398A8
_0809883C: .4byte gUnknown_20398AC
_08098840: .4byte gUnknown_20398B0
_08098844: .4byte gUnknown_20398BC
_08098848:
	movs r0, 0x66
	movs r1, 0
	bl GroundMap_ExecuteEvent
_08098850:
	bl GroundMap_Action
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	bl xxx_call_update_bg_sound_input
_08098864:
	bl xxx_call_update_bg_sound_input
	bl sub_80A6E68
	ldr r0, _08098890
	ldr r0, [r0]
	cmp r0, 0
	beq _080988B2
	ldr r1, _08098894
	ldr r0, [r1]
	cmp r0, 0
	ble _0809889C
	subs r0, 0x1
	str r0, [r1]
	cmp r0, 0
	bgt _080988F8
	ldr r0, _08098898
	ldr r0, [r0]
	bl sub_80999D4
	b _080988F8
	.align 2, 0
_08098890: .4byte gUnknown_20398A8
_08098894: .4byte gUnknown_20398AC
_08098898: .4byte gUnknown_20398B0
_0809889C:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _080988F8
	bl sub_809C740
	lsls r0, 24
	cmp r0, 0
	bne _0809897C
	b _080988F8
_080988B2:
	ldr r0, _08098968
	ldrb r0, [r0]
	cmp r0, 0
	beq _080988F8
	ldr r0, _0809896C
	ldrb r0, [r0]
	cmp r0, 0
	bne _080988F8
	bl sub_809AFAC
	lsls r0, 24
	cmp r0, 0
	bne _080988F8
	ldr r0, _08098970
	ldrh r0, [r0, 0x2]
	ldr r2, _08098974
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _080988E4
	bl sub_80048BC
	lsls r0, 24
	cmp r0, 0
	beq _080988F8
_080988E4:
	movs r0, 0x72
	movs r1, 0
	bl GroundMap_ExecuteEvent
	movs r0, 0x1E
	bl sub_8098F44
	movs r0, 0x1E
	bl sub_80118C4
_080988F8:
	bl GroundMap_Action
	bl nullsub_124
	bl GroundLives_Action
	bl GroundObject_Action
	bl GroundEffect_Action
	bl nullsub_105
	bl sub_809B474
	bl GroundScript_Unlock
	bl sub_809D25C
	bl sub_80A59DC
	bl sub_809B614
	bl sub_809CA20
	bl sub_80A6E80
	bl sub_8099BE4
	bl sub_8099744
	bl sub_8011860
	ldr r0, _08098978
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl nullsub_120
	bl sub_80A5E70
	bl sub_809B638
	bl nullsub_106
	bl sub_80A73EC
	bl sub_8099750
	bl sub_8009908
	b _08098864
	.align 2, 0
_08098968: .4byte gUnknown_20398B9
_0809896C: .4byte gUnknown_20398B8
_08098970: .4byte gUnknown_20255F0
_08098974: .4byte 0x0000030f
_08098978: .4byte gUnknown_203B47C
_0809897C:
	bl sub_80A4AEC
	movs r7, 0x1
	negs r7, r7
	ldr r0, _080989E8
	ldr r0, [r0]
_08098988:
	subs r0, 0x1
	cmp r0, 0x1
	bhi _08098990
	b _080985DC
_08098990:
	bl sub_80A4AC4
	bl nullsub_118
	bl sub_80A78F0
	bl sub_80ABBD4
	bl sub_80ACC10
	bl sub_80ADA08
	bl sub_809CB74
	bl sub_809A610
	bl sub_809C618
	bl sub_80A658C
	bl sub_809D508
	bl sub_80A7754
	bl nullsub_119
	bl sub_8099768
	bl nullsub_103
	bl nullsub_16
	ldr r0, _080989EC
	ldrb r0, [r0]
	cmp r0, 0
	beq _080989FA
	ldr r0, _080989E8
	ldr r0, [r0]
	cmp r0, 0x9
	beq _080989F0
	cmp r0, 0xA
	bne _080989F0
	movs r0, 0x10
	b _08098BD2
	.align 2, 0
_080989E8: .4byte gUnknown_20398A8
_080989EC: .4byte gUnknown_20398B9
_080989F0:
	movs r0, 0x1E
	bl sub_80118C4
	movs r0, 0xF
	b _08098BD2
_080989FA:
	ldr r0, _08098A10
	ldr r0, [r0]
	subs r0, 0x3
	cmp r0, 0x5
	bls _08098A06
	b _08098BC0
_08098A06:
	lsls r0, 2
	ldr r1, _08098A14
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098A10: .4byte gUnknown_20398A8
_08098A14: .4byte _08098A18
	.align 2, 0
_08098A18:
	.4byte _08098A30
	.4byte _08098A72
	.4byte _08098AA0
	.4byte _08098B08
	.4byte _08098B58
	.4byte _08098B8C
_08098A30:
	movs r4, 0x1
	negs r4, r4
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x14
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x4
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x4
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xD
	bl sub_8001658
	adds r2, r0, 0
	movs r0, 0
	movs r1, 0xF
	bl sub_80018D8
	movs r0, 0x5
	b _08098BD2
_08098A72:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x5
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x5
	bl sub_80018D8
	movs r2, 0x1
	negs r2, r2
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	movs r0, 0x6
	b _08098BD2
_08098AA0:
	ldr r5, _08098B04
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl sub_80A2654
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	ldrsh r2, [r5, r0]
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x14
	adds r2, r4, 0
	bl sub_80018D8
	ldrh r2, [r5]
	movs r0, 0
	movs r1, 0x30
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08098B00
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	bl sub_80018D8
_08098B00:
	movs r0, 0x7
	b _08098BD2
	.align 2, 0
_08098B04: .4byte gUnknown_20398C4
_08098B08:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x51
	bl sub_80018D8
	ldr r0, _08098B54
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08098B4E
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	bl sub_80018D8
_08098B4E:
	movs r0, 0x8
	b _08098BD2
	.align 2, 0
_08098B54: .4byte gUnknown_20398C4
_08098B58:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x50
	bl sub_80018D8
	ldr r0, _08098B88
	ldrb r2, [r0]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0x9
	b _08098BD2
	.align 2, 0
_08098B88: .4byte gUnknown_2039950
_08098B8C:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x52
	bl sub_80018D8
	ldr r0, _08098BBC
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0xA
	b _08098BD2
	.align 2, 0
_08098BBC: .4byte gUnknown_20398C4
_08098BC0:
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x1
	bl sub_80018D8
	movs r0, 0x10
	bl sub_80118C4
	movs r0, 0xE
_08098BD2:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_script_related_8098468

	thumb_func_start sub_8098BDC
sub_8098BDC:
	push {lr}
	bl sub_809B57C
	bl GroundScript_Unlock
	bl sub_809D25C
	bl sub_80A59DC
	bl sub_809B614
	bl sub_809CA20
	bl sub_80A6E80
	bl sub_8099BE4
	bl sub_8099744
	bl sub_8011860
	ldr r0, _08098C54
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl nullsub_120
	bl sub_80A5E70
	bl sub_809B638
	bl nullsub_106
	bl sub_80A73EC
	bl sub_8099750
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	bl sub_80A6E68
	bl GroundMap_Action
	bl nullsub_124
	bl GroundLives_Action
	bl GroundObject_Action
	bl GroundEffect_Action
	pop {r0}
	bx r0
	.align 2, 0
_08098C54: .4byte gUnknown_203B47C
	thumb_func_end sub_8098BDC

	thumb_func_start sub_8098C58
sub_8098C58:
	push {lr}
	movs r0, 0
	movs r1, 0x36
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x39
	bl sub_80015C0
	bl sub_809CB8C
	bl sub_8001D88
	movs r0, 0
	movs r1, 0x2A
	bl sub_8001658
	cmp r0, 0
	beq _08098CA2
	movs r0, 0
	movs r1, 0x29
	bl sub_8001658
	adds r2, r0, 0
	adds r2, 0x1
	cmp r2, 0xF
	ble _08098C90
	movs r2, 0
_08098C90:
	movs r0, 0
	movs r1, 0x29
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x2A
	movs r2, 0
	bl sub_80018D8
_08098CA2:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	bl sub_8001784
	adds r3, r0, 0
	cmp r3, 0
	bgt _08098CB4
	movs r3, 0x1
_08098CB4:
	subs r3, 0x1
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	bl sub_800199C
	bl sub_8098CC8
	pop {r0}
	bx r0
	thumb_func_end sub_8098C58

	thumb_func_start sub_8098CC8
sub_8098CC8:
	push {lr}
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _08098CDE
	movs r1, 0
	b _08098D06
_08098CDE:
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _08098CF2
	movs r1, 0x1
	b _08098D06
_08098CF2:
	movs r0, 0x3
	movs r1, 0x12
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	movs r1, 0x3
	cmp r0, 0
	beq _08098D06
	movs r1, 0x2
_08098D06:
	adds r0, r1, 0
	bl sub_8091980
	bl sub_809674C
	bl sub_80961B4
	bl sub_8091FB4
	pop {r0}
	bx r0
	thumb_func_end sub_8098CC8

	thumb_func_start sub_8098D1C
sub_8098D1C:
	push {r4-r7,lr}
	adds r7, r1, 0
	adds r4, r2, 0
	lsls r0, 16
	asrs r5, r0, 16
	ldr r6, _08098D34
	ldr r0, [r6]
	cmp r0, 0
	beq _08098D38
	movs r0, 0
	b _08098D60
	.align 2, 0
_08098D34: .4byte gUnknown_20398A8
_08098D38:
	ldr r1, _08098D68
	movs r0, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl Log
	movs r1, 0x1
	str r1, [r6]
	ldr r0, _08098D6C
	str r1, [r0]
	ldr r0, _08098D70
	str r4, [r0]
	ldr r1, _08098D74
	movs r0, 0x2
	str r0, [r1]
	ldr r0, _08098D78
	strh r5, [r0]
	ldr r0, _08098D7C
	str r7, [r0]
	movs r0, 0x1
_08098D60:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08098D68: .4byte gUnknown_8115F5C
_08098D6C: .4byte gUnknown_20398AC
_08098D70: .4byte gUnknown_20398B0
_08098D74: .4byte gUnknown_20398B4
_08098D78: .4byte gUnknown_20398BE
_08098D7C: .4byte gUnknown_20398C0
	thumb_func_end sub_8098D1C

	thumb_func_start sub_8098D80
sub_8098D80:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08098DB8
	ldr r0, [r1]
	cmp r0, 0
	bne _08098DC4
	movs r0, 0x3
	str r0, [r1]
	ldr r1, _08098DBC
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098DC0
	str r4, [r0]
	bl sub_809C730
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08098DB2
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_80118C4
_08098DB2:
	movs r0, 0x1
	b _08098DC6
	.align 2, 0
_08098DB8: .4byte gUnknown_20398A8
_08098DBC: .4byte gUnknown_20398AC
_08098DC0: .4byte gUnknown_20398B0
_08098DC4:
	movs r0, 0
_08098DC6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098D80

	thumb_func_start sub_8098DCC
sub_8098DCC:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08098E04
	ldr r0, [r1]
	cmp r0, 0
	bne _08098E10
	movs r0, 0x4
	str r0, [r1]
	ldr r1, _08098E08
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098E0C
	str r4, [r0]
	bl sub_809C730
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08098DFE
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_80118C4
_08098DFE:
	movs r0, 0x1
	b _08098E12
	.align 2, 0
_08098E04: .4byte gUnknown_20398A8
_08098E08: .4byte gUnknown_20398AC
_08098E0C: .4byte gUnknown_20398B0
_08098E10:
	movs r0, 0
_08098E12:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098DCC

	thumb_func_start sub_8098E18
sub_8098E18:
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 16
	asrs r2, r0, 16
	adds r5, r2, 0
	ldr r4, _08098E40
	ldr r0, [r4]
	cmp r0, 0
	bne _08098EA8
	ldr r1, _08098E44
	movs r0, 0
	adds r3, r6, 0
	bl Log
	ldr r0, _08098E48
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098E4C
	movs r0, 0x7
	b _08098E8A
	.align 2, 0
_08098E40: .4byte gUnknown_20398A8
_08098E44: .4byte gUnknown_8115F80
_08098E48: .4byte gUnknown_203B49D
_08098E4C:
	ldr r0, _08098E74
	ldrb r0, [r0]
	ldr r1, _08098E78
	cmp r0, 0
	bne _08098E58
	strh r5, [r1]
_08098E58:
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_80A2750
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	beq _08098E88
	cmp r0, 0x2
	bgt _08098E7C
	cmp r0, 0x1
	beq _08098E84
	b _08098E8C
	.align 2, 0
_08098E74: .4byte gUnknown_203B49C
_08098E78: .4byte gUnknown_20398C4
_08098E7C:
	cmp r0, 0x4
	bne _08098E8C
	movs r0, 0x8
	b _08098E8A
_08098E84:
	movs r0, 0x5
	b _08098E8A
_08098E88:
	movs r0, 0x6
_08098E8A:
	str r0, [r4]
_08098E8C:
	ldr r0, _08098EA0
	movs r1, 0x1
	str r1, [r0]
	ldr r0, _08098EA4
	str r6, [r0]
	bl sub_809C730
	movs r0, 0x1
	b _08098EAA
	.align 2, 0
_08098EA0: .4byte gUnknown_20398AC
_08098EA4: .4byte gUnknown_20398B0
_08098EA8:
	movs r0, 0
_08098EAA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8098E18

	thumb_func_start sub_8098EB0
sub_8098EB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08098EE4
	ldr r0, [r5]
	cmp r0, 0
	bne _08098EF8
	ldr r0, _08098EE8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098EF8
	ldr r1, _08098EEC
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0x7
	str r0, [r5]
	ldr r1, _08098EF0
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098EF4
	str r4, [r0]
	bl sub_809C730
	movs r0, 0x1
	b _08098EFA
	.align 2, 0
_08098EE4: .4byte gUnknown_20398A8
_08098EE8: .4byte gUnknown_203B49D
_08098EEC: .4byte gUnknown_8115FA4
_08098EF0: .4byte gUnknown_20398AC
_08098EF4: .4byte gUnknown_20398B0
_08098EF8:
	movs r0, 0
_08098EFA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8098EB0

	thumb_func_start sub_8098F00
sub_8098F00:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08098F10
	ldr r0, [r5]
	cmp r0, 0
	beq _08098F14
	movs r0, 0
	b _08098F32
	.align 2, 0
_08098F10: .4byte gUnknown_20398A8
_08098F14:
	ldr r1, _08098F38
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0x9
	str r0, [r5]
	ldr r1, _08098F3C
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098F40
	str r4, [r0]
	bl sub_809C730
	movs r0, 0x1
_08098F32:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08098F38: .4byte gUnknown_8115FC8
_08098F3C: .4byte gUnknown_20398AC
_08098F40: .4byte gUnknown_20398B0
	thumb_func_end sub_8098F00

	thumb_func_start sub_8098F44
sub_8098F44:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08098F54
	ldr r0, [r5]
	cmp r0, 0
	beq _08098F58
	movs r0, 0
	b _08098F76
	.align 2, 0
_08098F54: .4byte gUnknown_20398A8
_08098F58:
	ldr r1, _08098F7C
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0xA
	str r0, [r5]
	ldr r1, _08098F80
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098F84
	str r4, [r0]
	bl sub_809C730
	movs r0, 0x1
_08098F76:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08098F7C: .4byte gUnknown_8115FE8
_08098F80: .4byte gUnknown_20398AC
_08098F84: .4byte gUnknown_20398B0
	thumb_func_end sub_8098F44

	thumb_func_start sub_8098F88
sub_8098F88:
	ldr r0, _08098F90
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08098F90: .4byte gUnknown_20398B9
	thumb_func_end sub_8098F88

	thumb_func_start sub_8098F94
sub_8098F94:
	ldr r0, _08098F9C
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08098F9C: .4byte gUnknown_20398BA
	thumb_func_end sub_8098F94

	thumb_func_start sub_8098FA0
sub_8098FA0:
	push {lr}
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8098FA0

	thumb_func_start sub_8098FB4
sub_8098FB4:
	push {lr}
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2B18
	pop {r1}
	bx r1
	thumb_func_end sub_8098FB4

	thumb_func_start sub_8098FCC
sub_8098FCC:
	push {r4,lr}
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809909E
	cmp r1, 0x51
	bne _08098FF6
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	b _08098FF8
_08098FF6:
	adds r0, r2, 0
_08098FF8:
	bl sub_80A2608
	adds r4, r0, 0
	ldr r0, _0809900C
	ldr r0, [r0]
	cmp r0, 0x9
	bne _08099010
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	b _080990B2
	.align 2, 0
_0809900C: .4byte gUnknown_20398B4
_08099010:
	ldrh r0, [r4, 0x4]
	subs r0, 0xB2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	bhi _080990AE
	lsls r0, 2
	ldr r1, _08099028
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099028: .4byte _0809902C
	.align 2, 0
_0809902C:
	.4byte _0809908C
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990A2
	.4byte _080990AE
	.4byte _080990A2
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990A2
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990A2
_0809908C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x2
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _080990AE
_0809909E:
	movs r0, 0xC
	b _080990B2
_080990A2:
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809909E
_080990AE:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
_080990B2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098FCC

	thumb_func_start sub_80990B8
sub_80990B8:
	push {lr}
	movs r0, 0xB
	bl sub_8098FCC
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bne _080990D2
	bl sub_8098FB4
	b _080990E4
_080990D2:
	ldr r1, _080990E8
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A2B18
_080990E4:
	pop {r1}
	bx r1
	.align 2, 0
_080990E8: .4byte gUnknown_811BAF4
	thumb_func_end sub_80990B8

	thumb_func_start sub_80990EC
sub_80990EC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	adds r7, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	adds r0, r4, 0
	bl sub_80A2608
	mov r8, r0
	ldrb r0, [r0, 0xC]
	movs r5, 0
	strb r0, [r7]
	movs r0, 0x1
	strb r0, [r7, 0x1]
	strb r5, [r7, 0xC]
	adds r0, r4, 0
	bl sub_80A2750
	lsls r0, 16
	asrs r6, r0, 16
	cmp r6, 0x2
	beq _080991C8
	cmp r6, 0x2
	bgt _08099126
	cmp r6, 0x1
	beq _0809912C
	b _080991CA
_08099126:
	cmp r6, 0x4
	beq _080991C4
	b _080991CA
_0809912C:
	movs r1, 0
	strb r5, [r7, 0xB]
	adds r0, r4, 0
	subs r0, 0x25
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0809913E
	movs r1, 0x1
_0809913E:
	cmp r1, 0
	beq _080991CA
	strb r6, [r7, 0xC]
	mov r0, sp
	movs r1, 0x5B
	bl sub_80A8EC0
	add r4, sp, 0x18
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0xA
	bl sub_8092310
	add r5, sp, 0x30
	str r4, [sp, 0x58]
	add r1, sp, 0x5C
	movs r2, 0
	movs r0, 0x5E
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x5E
	strb r2, [r0]
	add r0, sp, 0x60
	movs r1, 0x47
	strb r1, [r0]
	strb r2, [r0, 0x1]
	add r1, sp, 0x64
	movs r0, 0x82
	lsls r0, 1
	strh r0, [r1]
	movs r0, 0xE0
	strh r0, [r1, 0x2]
	movs r0, 0xAC
	strh r0, [r1, 0x4]
	movs r0, 0xBE
	strh r0, [r1, 0x6]
	add r1, sp, 0x6C
	movs r0, 0x50
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6E
	movs r2, 0xF
	strh r2, [r0]
	add r0, sp, 0x70
	strh r6, [r0]
	adds r0, 0x2
	movs r1, 0x19
	strh r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	strh r2, [r0]
	strh r2, [r0, 0x2]
	ldr r0, _080991C0
	str r0, [sp, 0x7C]
	add r1, sp, 0x58
	adds r0, r5, 0
	movs r2, 0x28
	bl memcpy
	adds r0, r7, 0
	adds r0, 0x18
	adds r1, r5, 0
	bl sub_808D144
	b _080991CA
	.align 2, 0
_080991C0: .4byte 0x000061a8
_080991C4:
	strb r5, [r7, 0xB]
	b _080991CA
_080991C8:
	strb r6, [r7, 0xB]
_080991CA:
	movs r0, 0
	strb r0, [r7, 0x4]
	strb r0, [r7, 0xD]
	mov r1, r8
	ldrb r0, [r1, 0x11]
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80990EC

	thumb_func_start sub_80991E0
sub_80991E0:
	push {lr}
	adds r2, r0, 0
	ldr r3, _08099204
	ldrh r0, [r3]
	strh r0, [r1]
	ldr r0, _08099208
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809920C
	movs r0, 0
	ldrsh r1, [r3, r0]
	adds r0, r2, 0
	bl sub_80990EC
	lsls r0, 24
	lsrs r0, 24
	b _08099218
	.align 2, 0
_08099204: .4byte gUnknown_20398C4
_08099208: .4byte gUnknown_203B49C
_0809920C:
	ldr r1, _0809921C
	adds r0, r2, 0
	movs r2, 0x88
	bl memcpy
	movs r0, 0x1
_08099218:
	pop {r1}
	bx r1
	.align 2, 0
_0809921C: .4byte gUnknown_20398C8
	thumb_func_end sub_80991E0

	thumb_func_start sub_8099220
sub_8099220:
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, 0
	beq _08099258
	ldr r1, _08099248
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0809924C
	movs r0, 0
	strb r0, [r1]
	ldr r0, _08099250
	strh r3, [r0]
	ldr r0, _08099254
	adds r1, r2, 0
	movs r2, 0x88
	bl memcpy
	b _0809926A
	.align 2, 0
_08099248: .4byte gUnknown_203B49C
_0809924C: .4byte gUnknown_203B49D
_08099250: .4byte gUnknown_20398C4
_08099254: .4byte gUnknown_20398C8
_08099258:
	ldr r0, _08099270
	strb r2, [r0]
	ldr r0, _08099274
	strb r2, [r0]
	ldr r1, _08099278
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
_0809926A:
	pop {r0}
	bx r0
	.align 2, 0
_08099270: .4byte gUnknown_203B49C
_08099274: .4byte gUnknown_203B49D
_08099278: .4byte gUnknown_20398C4
	thumb_func_end sub_8099220

	thumb_func_start sub_809927C
sub_809927C:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, _080992CC
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _080992D0
	strb r1, [r0]
	ldr r1, _080992D4
	movs r0, 0x50
	strh r0, [r1]
	ldr r4, _080992D8
	strb r5, [r4]
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x50
	bl sub_80018D8
	ldrb r2, [r4]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	ldr r4, _080992DC
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095494
	subs r4, 0x10
	movs r1, 0
	movs r0, 0x1
	strb r0, [r4, 0xB]
	strb r1, [r4, 0xC]
	strb r1, [r4, 0x4]
	strb r1, [r4, 0xD]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080992CC: .4byte gUnknown_203B49C
_080992D0: .4byte gUnknown_203B49D
_080992D4: .4byte gUnknown_20398C4
_080992D8: .4byte gUnknown_2039950
_080992DC: .4byte gUnknown_20398D8
	thumb_func_end sub_809927C

	thumb_func_start sub_80992E0
sub_80992E0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08099316
	cmp r1, 0x50
	beq _08099316
	cmp r1, 0x51
	beq _08099316
	cmp r1, 0x52
	beq _08099316
	strh r1, [r4]
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	strh r0, [r5]
	movs r0, 0x1
	b _08099322
_08099316:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r4]
	strh r0, [r5]
	movs r0, 0
_08099322:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80992E0

	thumb_func_start sub_8099328
sub_8099328:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bne _08099358
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	cmp r0, 0x3E
	bhi _08099358
	strb r0, [r4]
	movs r0, 0x1
	b _0809935A
_08099358:
	movs r0, 0
_0809935A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8099328

	thumb_func_start sub_8099360
sub_8099360:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x52
	beq _08099378
	movs r0, 0
	b _0809938E
_08099378:
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	strb r0, [r4]
	movs r0, 0x1
_0809938E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8099360

	thumb_func_start sub_8099394
sub_8099394:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x50
	beq _080993AC
	movs r0, 0
	b _080993B8
_080993AC:
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	strb r0, [r4]
	movs r0, 0x1
_080993B8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8099394

	thumb_func_start sub_80993C0
sub_80993C0:
	push {lr}
	lsls r0, 24
	ldr r2, _080993D4
	movs r1, 0
	cmp r0, 0
	bne _080993CE
	movs r1, 0x1
_080993CE:
	strb r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080993D4: .4byte gUnknown_20398B8
	thumb_func_end sub_80993C0

	thumb_func_start sub_80993D8
sub_80993D8:
	push {lr}
	bl sub_80A4B38
	pop {r0}
	bx r0
	thumb_func_end sub_80993D8

	thumb_func_start sub_80993E4
sub_80993E4:
	push {lr}
	bl sub_80A4B54
	pop {r0}
	bx r0
	thumb_func_end sub_80993E4

	thumb_func_start sub_80993F0
sub_80993F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	movs r0, 0
	mov r10, r0
	bl sub_801180C
	movs r0, 0x10
	bl sub_80118C4
	ldr r1, _0809948C
	ldr r2, _08099490
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	bl xxx_update_some_bg_tiles
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	movs r1, 0x14
	bl sub_8009408
	bl sub_8099648
	bl sub_809975C
	bl sub_809D0AC
	bl sub_8014144
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80A4A7C
	mov r7, sp
	add r0, sp, 0x8
	mov r8, r0
_08099454:
	bl sub_801D9E4
	lsls r0, 24
	cmp r0, 0
	beq _0809949C
	mov r0, r10
	bl sub_801DA58
_08099464:
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	movs r0, 0
	bl sub_8012A18
	bl sub_801DA78
	cmp r0, 0x2
	beq _08099494
	cmp r0, 0x3
	bne _08099464
	bl sub_801DAC0
	lsls r0, 16
	asrs r0, 16
	mov r10, r0
	b _080994A2
	.align 2, 0
_0809948C: .4byte gUnknown_2026E4E
_08099490: .4byte 0x00000808
_08099494:
	movs r1, 0x1
	negs r1, r1
	mov r10, r1
	b _080994A2
_0809949C:
	movs r2, 0x1
	negs r2, r2
	mov r10, r2
_080994A2:
	bl sub_801DB0C
	movs r0, 0x1
	negs r0, r0
	cmp r10, r0
	bne _080994B0
	b _08099624
_080994B0:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_80A4AEC
	bl sub_809D0BC
	mov r0, r10
	bl GroundMap_Select
	mov r0, sp
	mov r1, r8
	bl sub_80A579C
	ldr r0, [r7, 0x4]
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [r7, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, [sp]
	ldr r1, _08099520
	adds r0, r1
	str r0, [sp]
	ldr r0, [r7, 0x4]
	adds r0, r1
	str r0, [r7, 0x4]
	ldr r0, [sp, 0x8]
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r1, [r0, 0x4]
	adds r1, r2
	str r1, [r0, 0x4]
	ldr r2, [sp, 0x8]
	ldr r0, [sp]
	subs r0, r2, r0
	str r0, [sp, 0x20]
	ldr r0, [r7, 0x4]
	subs r0, r1, r0
	str r0, [sp, 0x24]
	movs r4, 0
	movs r5, 0
	movs r0, 0x4
	bl sub_80999E8
	mov r9, r5
	b _08099604
	.align 2, 0
_08099520: .4byte 0xfffffc00
_08099524:
	ldr r0, _0809953C
	ldrh r1, [r0, 0x2]
	ldrh r6, [r0]
	movs r0, 0x4
	ands r1, r0
	cmp r1, 0
	beq _08099540
	bl sub_80999FC
	movs r1, 0x1
	mov r9, r1
	b _080995AE
	.align 2, 0
_0809953C: .4byte gUnknown_20255F0
_08099540:
	adds r0, r6, 0
	bl sub_809CFE8
	lsls r0, 24
	asrs r1, r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r1, r2
	beq _0809959A
	add r0, sp, 0x10
	movs r2, 0x80
	lsls r2, 1
	bl sub_8002BB8
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	movs r0, 0x2
	ands r6, r0
	cmp r6, 0
	beq _0809956A
	movs r0, 0x4
_0809956A:
	adds r1, r0, 0
	muls r1, r2
	adds r1, r4
	adds r4, r1, 0
	muls r0, r3
	adds r5, r0
	cmp r1, 0
	bge _0809957E
	movs r4, 0
	b _08099588
_0809957E:
	ldr r0, [sp, 0x20]
	cmp r4, r0
	blt _08099588
	adds r4, r0, 0
	subs r4, 0x1
_08099588:
	cmp r5, 0
	bge _08099590
	movs r5, 0
	b _0809959A
_08099590:
	ldr r1, [sp, 0x24]
	cmp r5, r1
	blt _0809959A
	adds r5, r1, 0
	subs r5, 0x1
_0809959A:
	ldr r0, [sp]
	adds r0, r4
	str r0, [sp, 0x18]
	ldr r0, [r7, 0x4]
	adds r0, r5
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0
	bl sub_809D158
_080995AE:
	bl sub_809D25C
	bl sub_80A59DC
	bl xxx_draw_string_80144C4
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	ldr r0, _08099620
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl sub_8099BE4
	bl sub_8099744
	bl sub_8011860
	bl sub_800CB20
	bl sub_800485C
	bl nullsub_120
	bl sub_80A5E70
	bl xxx_call_update_bg_vram
	bl CopySpritesToOam
	bl sub_8005304
	bl sub_8099750
	bl sub_8009908
_08099604:
	bl xxx_call_update_bg_sound_input
	movs r0, 0
	bl ResetSprites
	mov r2, r9
	cmp r2, 0
	beq _08099524
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _080995AE
	b _08099454
	.align 2, 0
_08099620: .4byte gUnknown_203B46C
_08099624:
	movs r0, 0x10
	bl sub_80118C4
	bl sub_80A4AC4
	bl sub_8099768
	bl nullsub_103
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80993F0

	thumb_func_start sub_8099648
sub_8099648:
	push {lr}
	bl sub_8003600
	bl sub_809965C
	pop {r0}
	bx r0
	thumb_func_end sub_8099648

	thumb_func_start nullsub_103
nullsub_103:
	bx lr
	thumb_func_end nullsub_103

	thumb_func_start sub_809965C
sub_809965C:
	push {r4,lr}
	movs r0, 0
	bl sub_8099690
	ldr r0, _08099688
	ldr r1, _0809968C
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	movs r0, 0xF8
	lsls r0, 1
	ldr r1, [r4, 0x4]
	movs r2, 0x10
	bl sub_800388C
	adds r0, r4, 0
	bl CloseFile
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099688: .4byte gUnknown_811601C
_0809968C: .4byte gUnknown_8300500
	thumb_func_end sub_809965C

	thumb_func_start sub_8099690
sub_8099690:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, _080996BC
	ldr r1, _080996C0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	cmp r4, 0x1
	beq _080996CC
	cmp r4, 0x2
	beq _080996D4
	ldr r0, _080996C4
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	ldr r4, _080996C8
	cmp r0, 0
	beq _080996D6
	movs r0, 0x80
	lsls r0, 1
	adds r4, r0
	b _080996D6
	.align 2, 0
_080996BC: .4byte gUnknown_8116028
_080996C0: .4byte gUnknown_8300500
_080996C4: .4byte gUnknown_203B46C
_080996C8: .4byte gUnknown_202D078
_080996CC:
	ldr r4, _080996D0
	b _080996D6
	.align 2, 0
_080996D0: .4byte gUnknown_202D1B8
_080996D4:
	ldr r4, _08099704
_080996D6:
	movs r0, 0xF0
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_800388C
	adds r5, r4, 0
	movs r4, 0
_080996E4:
	adds r0, r4, 0
	adds r0, 0xF0
	adds r1, r5, 0
	adds r5, 0x4
	bl nullsub_5
	adds r4, 0x1
	cmp r4, 0xF
	ble _080996E4
	adds r0, r6, 0
	bl CloseFile
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08099704: .4byte gUnknown_202D1F8
	thumb_func_end sub_8099690

	thumb_func_start sub_8099708
sub_8099708:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	lsls r0, 16
	lsrs r0, 16
	bl sub_8003810
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8099708

	thumb_func_start sub_809971C
sub_809971C:
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r2, 0
	ble _0809973E
	adds r4, r2, 0
_0809972A:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldm r6!, {r1}
	bl sub_8003810
	subs r4, 0x1
	cmp r4, 0
	bne _0809972A
_0809973E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809971C

	thumb_func_start sub_8099744
sub_8099744:
	push {lr}
	bl sub_80039B8
	pop {r0}
	bx r0
	thumb_func_end sub_8099744

	thumb_func_start sub_8099750
sub_8099750:
	push {lr}
	bl TransferBGPaletteBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8099750

	thumb_func_start sub_809975C
sub_809975C:
	push {lr}
	bl sub_809977C
	pop {r0}
	bx r0
	thumb_func_end sub_809975C

	thumb_func_start sub_8099768
sub_8099768:
	push {lr}
	bl sub_809977C
	bl sub_8099744
	bl sub_8099750
	pop {r0}
	bx r0
	thumb_func_end sub_8099768

	thumb_func_start sub_809977C
sub_809977C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r1, _080997DC
	movs r0, 0
	strb r0, [r1]
	ldr r1, _080997E0
	movs r0, 0
	strh r0, [r1]
	ldr r6, _080997E4
	adds r0, r6, 0
	bl sub_8099838
	ldr r0, _080997E8
	mov r8, r0
	bl sub_8099838
	ldr r4, _080997EC
	adds r0, r4, 0
	bl sub_8099838
	subs r4, 0x8
	movs r0, 0
	str r0, [r4]
	movs r5, 0x80
	lsls r5, 1
	strh r5, [r4, 0x14]
	strh r0, [r6, 0xC]
	bl sub_8099DD0
	mov r0, r8
	strh r5, [r0, 0xC]
	adds r0, r5, 0
	bl sub_8099E58
	ldr r1, _080997F0
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x40
_080997CA:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080997CA
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080997DC: .4byte gUnknown_2039990
_080997E0: .4byte gUnknown_2039992
_080997E4: .4byte gUnknown_2039958
_080997E8: .4byte gUnknown_2039968
_080997EC: .4byte gUnknown_2039980
_080997F0: .4byte gUnknown_2039998
	thumb_func_end sub_809977C

	thumb_func_start sub_80997F4
sub_80997F4:
	push {lr}
	lsls r0, 16
	ldr r2, _08099818
	lsrs r0, 15
	adds r0, r2
	strh r1, [r0]
	ldr r0, _0809981C
	bl sub_8099848
	ldr r0, _08099820
	bl sub_8099848
	ldr r0, _08099824
	bl sub_8099848
	pop {r0}
	bx r0
	.align 2, 0
_08099818: .4byte gUnknown_2039998
_0809981C: .4byte gUnknown_2039958
_08099820: .4byte gUnknown_2039968
_08099824: .4byte gUnknown_2039980
	thumb_func_end sub_80997F4

	thumb_func_start sub_8099828
sub_8099828:
	lsls r0, 16
	ldr r1, _08099834
	lsrs r0, 15
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_08099834: .4byte gUnknown_2039998
	thumb_func_end sub_8099828

	thumb_func_start sub_8099838
sub_8099838:
	movs r1, 0x1
	str r1, [r0]
	movs r1, 0
	strh r1, [r0, 0xC]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	bx lr
	thumb_func_end sub_8099838

	thumb_func_start sub_8099848
sub_8099848:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bne _08099856
	movs r0, 0x1
	str r0, [r1]
_08099856:
	pop {r0}
	bx r0
	thumb_func_end sub_8099848

	thumb_func_start sub_809985C
sub_809985C:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	blt _08099872
	cmp r1, 0
	bne _08099874
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r2, 0xC]
	movs r0, 0x1
	b _08099876
_08099872:
	movs r1, 0x1E
_08099874:
	movs r0, 0x2
_08099876:
	str r0, [r2]
	strh r1, [r2, 0x4]
	strh r1, [r2, 0x6]
	pop {r0}
	bx r0
	thumb_func_end sub_809985C

	thumb_func_start sub_8099880
sub_8099880:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	blt _08099892
	cmp r1, 0
	bne _08099894
	strh r1, [r2, 0xC]
	movs r0, 0x1
	b _08099896
_08099892:
	movs r1, 0x1E
_08099894:
	movs r0, 0x3
_08099896:
	str r0, [r2]
	strh r1, [r2, 0x4]
	strh r1, [r2, 0x6]
	pop {r0}
	bx r0
	thumb_func_end sub_8099880

	thumb_func_start sub_80998A0
sub_80998A0:
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	cmp r1, 0
	bge _080998B2
	movs r1, 0x1E
_080998B2:
	cmp r2, r3
	bls _080998BE
	movs r0, 0x5
	str r0, [r4]
	subs r0, r2, r3
	b _080998D0
_080998BE:
	cmp r2, r3
	bcs _080998CA
	movs r0, 0x4
	str r0, [r4]
	subs r0, r3, r2
	b _080998D0
_080998CA:
	movs r0, 0x1
	str r0, [r4]
	movs r0, 0
_080998D0:
	strh r0, [r4, 0xA]
	strh r1, [r4, 0x4]
	strh r1, [r4, 0x6]
	strh r2, [r4, 0xC]
	strh r3, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80998A0

	thumb_func_start sub_80998E0
sub_80998E0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	cmp r0, 0x5
	bhi _080999CA
	lsls r0, 2
	ldr r1, _080998F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080998F4: .4byte _080998F8
	.align 2, 0
_080998F8:
	.4byte _080999CA
	.4byte _080999C2
	.4byte _08099910
	.4byte _08099946
	.4byte _08099976
	.4byte _0809999A
_08099910:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _08099940
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	lsls r0, 8
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	ldrh r0, [r4, 0xC]
	cmp r0, r1
	bcs _080999C6
	strh r1, [r4, 0xC]
	b _080999C6
_08099940:
	movs r0, 0x80
	lsls r0, 1
	b _080999C0
_08099946:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _08099970
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	lsls r0, 8
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	ldrh r0, [r4, 0xC]
	cmp r0, r1
	bls _080999C6
	strh r1, [r4, 0xC]
	b _080999C6
_08099970:
	strh r1, [r4, 0xC]
	str r1, [r4]
	b _080999C6
_08099976:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _080999BE
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	ldrh r0, [r4, 0xA]
	muls r0, r1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	ldrh r1, [r4, 0x8]
	subs r1, r0
	strh r1, [r4, 0xC]
	b _080999C6
_0809999A:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _080999BE
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	ldrh r0, [r4, 0xA]
	muls r0, r1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	ldrh r1, [r4, 0x8]
	adds r1, r0
	strh r1, [r4, 0xC]
	b _080999C6
_080999BE:
	ldrh r0, [r4, 0x8]
_080999C0:
	strh r0, [r4, 0xC]
_080999C2:
	movs r0, 0
	str r0, [r4]
_080999C6:
	movs r0, 0x1
	b _080999CC
_080999CA:
	movs r0, 0
_080999CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80998E0

	thumb_func_start sub_80999D4
sub_80999D4:
	ldr r2, _080999E0
	movs r1, 0x1
	strb r1, [r2]
	ldr r1, _080999E4
	strh r0, [r1]
	bx lr
	.align 2, 0
_080999E0: .4byte gUnknown_2039990
_080999E4: .4byte gUnknown_2039992
	thumb_func_end sub_80999D4

	thumb_func_start sub_80999E8
sub_80999E8:
	push {lr}
	adds r1, r0, 0
	ldr r0, _080999F8
	bl sub_809985C
	pop {r0}
	bx r0
	.align 2, 0
_080999F8: .4byte gUnknown_2039958
	thumb_func_end sub_80999E8

	thumb_func_start sub_80999FC
sub_80999FC:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08099A0C
	bl sub_8099880
	pop {r0}
	bx r0
	.align 2, 0
_08099A0C: .4byte gUnknown_2039958
	thumb_func_end sub_80999FC

	thumb_func_start sub_8099A10
sub_8099A10:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r0, _08099A30
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80998A0
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099A30: .4byte gUnknown_2039958
	thumb_func_end sub_8099A10

	thumb_func_start sub_8099A34
sub_8099A34:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08099A44
	bl sub_809985C
	pop {r0}
	bx r0
	.align 2, 0
_08099A44: .4byte gUnknown_2039968
	thumb_func_end sub_8099A34

	thumb_func_start sub_8099A48
sub_8099A48:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08099A58
	bl sub_8099880
	pop {r0}
	bx r0
	.align 2, 0
_08099A58: .4byte gUnknown_2039968
	thumb_func_end sub_8099A48

	thumb_func_start sub_8099A5C
sub_8099A5C:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	str r2, [sp]
	ldr r0, _08099A88
	str r4, [r0]
	ldr r2, [sp]
	str r2, [r0, 0x4]
	movs r2, 0
	strh r2, [r0, 0x14]
	adds r0, 0x8
	bl sub_809985C
	subs r0, r4, 0x1
	cmp r0, 0xD
	bhi _08099AF0
	lsls r0, 2
	ldr r1, _08099A8C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099A88: .4byte gUnknown_2039978
_08099A8C: .4byte _08099A90
	.align 2, 0
_08099A90:
	.4byte _08099AC8
	.4byte _08099AF0
	.4byte _08099AC8
	.4byte _08099AF0
	.4byte _08099AE8
	.4byte _08099AF0
	.4byte _08099AE8
	.4byte _08099AF0
	.4byte _08099AE0
	.4byte _08099AF0
	.4byte _08099AE0
	.4byte _08099AF0
	.4byte _08099AE8
	.4byte _08099AE8
_08099AC8:
	ldr r0, _08099AD8
	movs r1, 0x80
	lsls r1, 1
	strh r1, [r0, 0xC]
	ldr r0, _08099ADC
	strh r1, [r0, 0xC]
	b _08099AF0
	.align 2, 0
_08099AD8: .4byte gUnknown_2039968
_08099ADC: .4byte gUnknown_2039958
_08099AE0:
	ldr r1, _08099AE4
	b _08099AEA
	.align 2, 0
_08099AE4: .4byte gUnknown_2039968
_08099AE8:
	ldr r1, _08099AF8
_08099AEA:
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r1, 0xC]
_08099AF0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099AF8: .4byte gUnknown_2039958
	thumb_func_end sub_8099A5C

	thumb_func_start sub_8099AFC
sub_8099AFC:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	str r2, [sp]
	ldr r0, _08099B28
	str r4, [r0]
	ldr r2, [sp]
	str r2, [r0, 0x4]
	movs r2, 0x80
	lsls r2, 1
	strh r2, [r0, 0x14]
	adds r0, 0x8
	bl sub_8099880
	subs r0, r4, 0x2
	cmp r0, 0xC
	bhi _08099B86
	lsls r0, 2
	ldr r1, _08099B2C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099B28: .4byte gUnknown_2039978
_08099B2C: .4byte _08099B30
	.align 2, 0
_08099B30:
	.4byte _08099B64
	.4byte _08099B86
	.4byte _08099B64
	.4byte _08099B86
	.4byte _08099B80
	.4byte _08099B86
	.4byte _08099B80
	.4byte _08099B86
	.4byte _08099B78
	.4byte _08099B86
	.4byte _08099B78
	.4byte _08099B80
	.4byte _08099B80
_08099B64:
	ldr r0, _08099B70
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r0, _08099B74
	strh r1, [r0, 0xC]
	b _08099B86
	.align 2, 0
_08099B70: .4byte gUnknown_2039968
_08099B74: .4byte gUnknown_2039958
_08099B78:
	ldr r1, _08099B7C
	b _08099B82
	.align 2, 0
_08099B7C: .4byte gUnknown_2039968
_08099B80:
	ldr r1, _08099B90
_08099B82:
	movs r0, 0
	strh r0, [r1, 0xC]
_08099B86:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099B90: .4byte gUnknown_2039958
	thumb_func_end sub_8099AFC

	thumb_func_start sub_8099B94
sub_8099B94:
	push {lr}
	ldr r0, _08099BA4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08099BA8
	movs r0, 0x1
	b _08099BD6
	.align 2, 0
_08099BA4: .4byte gUnknown_2039990
_08099BA8:
	ldr r1, _08099BBC
	ldr r0, [r1]
	cmp r0, 0
	beq _08099BC0
	ldr r0, [r1, 0x8]
	cmp r0, 0
	beq _08099BD6
	movs r0, 0x1
	b _08099BD6
	.align 2, 0
_08099BBC: .4byte gUnknown_2039978
_08099BC0:
	movs r1, 0
	ldr r0, _08099BDC
	ldr r0, [r0]
	cmp r0, 0
	bne _08099BD2
	ldr r0, _08099BE0
	ldr r0, [r0]
	cmp r0, 0
	beq _08099BD4
_08099BD2:
	movs r1, 0x1
_08099BD4:
	adds r0, r1, 0
_08099BD6:
	pop {r1}
	bx r1
	.align 2, 0
_08099BDC: .4byte gUnknown_2039958
_08099BE0: .4byte gUnknown_2039968
	thumb_func_end sub_8099B94

	thumb_func_start sub_8099BE4
sub_8099BE4:
	push {r4,r5,lr}
	ldr r4, _08099C10
	ldr r0, [r4]
	cmp r0, 0
	bne _08099BF6
	ldr r0, [r4, 0x8]
	cmp r0, 0
	bne _08099BF6
	b _08099D08
_08099BF6:
	adds r0, r4, 0
	adds r0, 0x8
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099C14
	ldrh r0, [r4, 0x14]
	ldr r1, [r4, 0x4]
	bl sub_8099E80
	b _08099DC0
	.align 2, 0
_08099C10: .4byte gUnknown_2039978
_08099C14:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _08099C1C
	b _08099DC0
_08099C1C:
	ldr r0, [r4]
	cmp r0, 0xE
	bls _08099C24
	b _08099DC0
_08099C24:
	lsls r0, 2
	ldr r1, _08099C30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099C30: .4byte _08099C34
	.align 2, 0
_08099C34:
	.4byte _08099DC0
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099CD8
	.4byte _08099CD8
_08099C70:
	ldr r0, _08099C80
	ldrh r1, [r0, 0x14]
	adds r3, r0, 0
	cmp r1, 0xFF
	bls _08099C84
	movs r0, 0
	str r0, [r3]
	b _08099DC0
	.align 2, 0
_08099C80: .4byte gUnknown_2039978
_08099C84:
	ldr r0, _08099CA0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08099C8E
	b _08099DC0
_08099C8E:
	movs r2, 0
	ldr r0, [r3]
	cmp r0, 0x3
	beq _08099CB2
	cmp r0, 0x3
	bhi _08099CA4
	cmp r0, 0x1
	beq _08099CAE
	b _08099CBC
	.align 2, 0
_08099CA0: .4byte gUnknown_2039990
_08099CA4:
	cmp r0, 0x5
	beq _08099CB6
	cmp r0, 0x7
	beq _08099CBA
	b _08099CBC
_08099CAE:
	movs r2, 0x2
	b _08099CC0
_08099CB2:
	movs r2, 0x4
	b _08099CC0
_08099CB6:
	movs r2, 0x6
	b _08099CC0
_08099CBA:
	movs r2, 0x8
_08099CBC:
	cmp r2, 0
	beq _08099CD4
_08099CC0:
	ldr r0, _08099CD0
	movs r4, 0
	ldrsh r1, [r0, r4]
	adds r0, r2, 0
	ldr r2, [r3, 0x4]
	bl sub_8099AFC
	b _08099DC0
	.align 2, 0
_08099CD0: .4byte gUnknown_2039992
_08099CD4:
	str r2, [r3]
	b _08099DC0
_08099CD8:
	ldr r2, _08099CE4
	ldrh r0, [r2, 0x14]
	cmp r0, 0
	bne _08099CE8
	str r0, [r2]
	b _08099DC0
	.align 2, 0
_08099CE4: .4byte gUnknown_2039978
_08099CE8:
	ldr r0, _08099D00
	ldrb r0, [r0]
	cmp r0, 0
	beq _08099DC0
	ldr r0, [r2]
	ldr r1, _08099D04
	movs r3, 0
	ldrsh r1, [r1, r3]
	ldr r2, [r2, 0x4]
	bl sub_8099AFC
	b _08099DC0
	.align 2, 0
_08099D00: .4byte gUnknown_2039990
_08099D04: .4byte gUnknown_2039992
_08099D08:
	ldr r0, _08099D88
	ldrb r0, [r0]
	cmp r0, 0
	beq _08099D98
	movs r5, 0x1
	ldr r4, _08099D8C
	ldrh r0, [r4, 0xC]
	cmp r0, 0
	bne _08099D20
	ldr r0, [r4]
	cmp r0, 0
	beq _08099D46
_08099D20:
	movs r5, 0
	ldr r0, [r4]
	cmp r0, 0x3
	beq _08099D34
	ldr r0, _08099D90
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_8099880
_08099D34:
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099D46
	ldrh r0, [r4, 0xC]
	bl sub_8099DD0
_08099D46:
	ldr r4, _08099D94
	ldrh r0, [r4, 0xC]
	cmp r0, 0
	bne _08099D54
	ldr r0, [r4]
	cmp r0, 0
	beq _08099D7A
_08099D54:
	movs r5, 0
	ldr r0, [r4]
	cmp r0, 0x3
	beq _08099D68
	ldr r0, _08099D90
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r0, r4, 0
	bl sub_8099880
_08099D68:
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099D7A
	ldrh r0, [r4, 0xC]
	bl sub_8099E58
_08099D7A:
	cmp r5, 0
	beq _08099DC0
	ldr r1, _08099D88
	movs r0, 0
	strb r0, [r1]
	b _08099DC0
	.align 2, 0
_08099D88: .4byte gUnknown_2039990
_08099D8C: .4byte gUnknown_2039958
_08099D90: .4byte gUnknown_2039992
_08099D94: .4byte gUnknown_2039968
_08099D98:
	ldr r4, _08099DC8
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099DAC
	ldrh r0, [r4, 0xC]
	bl sub_8099DD0
_08099DAC:
	ldr r4, _08099DCC
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099DC0
	ldrh r0, [r4, 0xC]
	bl sub_8099E58
_08099DC0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099DC8: .4byte gUnknown_2039958
_08099DCC: .4byte gUnknown_2039968
	thumb_func_end sub_8099BE4

	thumb_func_start sub_8099DD0
sub_8099DD0:
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r7, r0, 16
	movs r4, 0
	ldr r6, _08099DF4
	movs r5, 0xD
_08099DDC:
	ldrh r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08099DF8
	lsrs r0, r4, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099E00
	.align 2, 0
_08099DF4: .4byte gUnknown_2039998
_08099DF8:
	lsrs r0, r4, 16
	adds r1, r7, 0
	bl sub_8003664
_08099E00:
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r6, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _08099DDC
	ldr r0, _08099E30
	movs r4, 0x80
	lsls r4, 13
	adds r6, r0, 0
	adds r6, 0x20
	movs r5, 0xE
_08099E1A:
	ldrh r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08099E34
	lsrs r0, r4, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099E3C
	.align 2, 0
_08099E30: .4byte gUnknown_2039998
_08099E34:
	lsrs r0, r4, 16
	adds r1, r7, 0
	bl sub_8003664
_08099E3C:
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r6, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _08099E1A
	movs r0, 0x20
	adds r1, r7, 0
	bl sub_8003664
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8099DD0

	thumb_func_start sub_8099E58
sub_8099E58:
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0xF
	adds r1, r4, 0
	bl sub_8003664
	movs r0, 0xE
	adds r1, r4, 0
	bl sub_8003664
	movs r0, 0x1F
	adds r1, r4, 0
	bl sub_8003664
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8099E58

	thumb_func_start sub_8099E80
sub_8099E80:
	push {r4-r7,lr}
	sub sp, 0x4
	str r1, [sp]
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, _08099EA0
	ldr r1, [r0]
	adds r2, r0, 0
	cmp r1, 0xE
	bls _08099E96
	b _0809A558
_08099E96:
	lsls r0, r1, 2
	ldr r1, _08099EA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099EA0: .4byte gUnknown_2039978
_08099EA4: .4byte _08099EA8
	.align 2, 0
_08099EA8:
	.4byte _0809A558
	.4byte _08099EE4
	.4byte _0809A05A
	.4byte _0809A1D2
	.4byte _0809A34A
	.4byte _08099FDE
	.4byte _0809A156
	.4byte _0809A2CE
	.4byte _0809A4BC
	.4byte _08099F5E
	.4byte _0809A0D6
	.4byte _0809A24E
	.4byte _0809A3EA
	.4byte _0809A48A
	.4byte _0809A48A
_08099EE4:
	movs r4, 0
	movs r5, 0
	ldr r7, _08099F00
_08099EEA:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F04
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F0E
	.align 2, 0
_08099F00: .4byte gUnknown_2039998
_08099F04:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F0E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _08099EEA
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _08099F40
	adds r7, r0, 0
	adds r7, 0x20
_08099F28:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F44
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F4E
	.align 2, 0
_08099F40: .4byte gUnknown_2039998
_08099F44:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F4E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08099F28
	b _0809A558
_08099F5E:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _08099F80
	adds r7, r0, 0
	adds r7, 0x1C
_08099F6A:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F84
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F8E
	.align 2, 0
_08099F80: .4byte gUnknown_2039998
_08099F84:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F8E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _08099F6A
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _08099FC0
	adds r7, r0, 0
	adds r7, 0x3E
_08099FA8:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099FC4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099FCE
	.align 2, 0
_08099FC0: .4byte gUnknown_2039998
_08099FC4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099FCE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08099FA8
	b _0809A558
_08099FDE:
	movs r4, 0
	movs r5, 0
	ldr r7, _08099FFC
_08099FE4:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A000
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A00A
	.align 2, 0
_08099FFC: .4byte gUnknown_2039998
_0809A000:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_0809A00A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _08099FE4
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A03C
	adds r7, r0, 0
	adds r7, 0x20
_0809A024:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A040
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A04A
	.align 2, 0
_0809A03C: .4byte gUnknown_2039998
_0809A040:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_0809A04A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A024
	b _0809A558
_0809A05A:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A078
_0809A060:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A07C
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A086
	.align 2, 0
_0809A078: .4byte gUnknown_2039998
_0809A07C:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A086:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A060
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A0B8
	adds r7, r0, 0
	adds r7, 0x20
_0809A0A0:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A0BC
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A0C6
	.align 2, 0
_0809A0B8: .4byte gUnknown_2039998
_0809A0BC:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A0C6:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A0A0
	b _0809A558
_0809A0D6:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _0809A0F8
	adds r7, r0, 0
	adds r7, 0x1C
_0809A0E2:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A0FC
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A106
	.align 2, 0
_0809A0F8: .4byte gUnknown_2039998
_0809A0FC:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A106:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A0E2
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _0809A138
	adds r7, r0, 0
	adds r7, 0x3E
_0809A120:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A13C
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A146
	.align 2, 0
_0809A138: .4byte gUnknown_2039998
_0809A13C:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A146:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A120
	b _0809A558
_0809A156:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A174
_0809A15C:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A178
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A182
	.align 2, 0
_0809A174: .4byte gUnknown_2039998
_0809A178:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A182:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A15C
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A1B4
	adds r7, r0, 0
	adds r7, 0x20
_0809A19C:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A1B8
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A1C2
	.align 2, 0
_0809A1B4: .4byte gUnknown_2039998
_0809A1B8:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A1C2:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A19C
	b _0809A558
_0809A1D2:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A1F0
_0809A1D8:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A1F4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A1FE
	.align 2, 0
_0809A1F0: .4byte gUnknown_2039998
_0809A1F4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A1FE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A1D8
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A230
	adds r7, r0, 0
	adds r7, 0x20
_0809A218:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A234
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A23E
	.align 2, 0
_0809A230: .4byte gUnknown_2039998
_0809A234:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A23E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A218
	b _0809A558
_0809A24E:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _0809A270
	adds r7, r0, 0
	adds r7, 0x1C
_0809A25A:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A274
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A27E
	.align 2, 0
_0809A270: .4byte gUnknown_2039998
_0809A274:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A27E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A25A
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _0809A2B0
	adds r7, r0, 0
	adds r7, 0x3E
_0809A298:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A2B4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A2BE
	.align 2, 0
_0809A2B0: .4byte gUnknown_2039998
_0809A2B4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A2BE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A298
	b _0809A558
_0809A2CE:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A2EC
_0809A2D4:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A2F0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A2FA
	.align 2, 0
_0809A2EC: .4byte gUnknown_2039998
_0809A2F0:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A2FA:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A2D4
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A32C
	adds r7, r0, 0
	adds r7, 0x20
_0809A314:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A330
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A33A
	.align 2, 0
_0809A32C: .4byte gUnknown_2039998
_0809A330:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A33A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A314
	b _0809A558
_0809A34A:
	movs r4, 0
	movs r5, 0
_0809A34E:
	ldr r0, _0809A36C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A370
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A38C
	.align 2, 0
_0809A36C: .4byte gUnknown_2039998
_0809A370:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A382
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A38C
_0809A382:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A38C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A34E
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
_0809A39E:
	ldr r0, _0809A3BC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A3C0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A3DC
	.align 2, 0
_0809A3BC: .4byte gUnknown_2039998
_0809A3C0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A3D2
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A3DC
_0809A3D2:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A3DC:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A39E
	b _0809A558
_0809A3EA:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
_0809A3F0:
	ldr r0, _0809A40C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A410
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A42C
	.align 2, 0
_0809A40C: .4byte gUnknown_2039998
_0809A410:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A422
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A42C
_0809A422:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A42C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A3F0
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
_0809A43E:
	ldr r0, _0809A45C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A460
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A47C
	.align 2, 0
_0809A45C: .4byte gUnknown_2039998
_0809A460:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A472
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A47C
_0809A472:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A47C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A43E
	b _0809A558
_0809A48A:
	ldr r0, [r2]
	cmp r0, 0xD
	beq _0809A496
	cmp r0, 0xE
	beq _0809A4AA
	b _0809A4BC
_0809A496:
	mov r0, sp
	movs r1, 0x90
	strb r1, [r0]
	strb r1, [r0, 0x1]
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0x2]
	movs r0, 0x1
	negs r0, r0
	b _0809A4BA
_0809A4AA:
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0xC0
	strb r0, [r1, 0x1]
	movs r0, 0x80
	strb r0, [r1, 0x2]
	subs r0, 0x81
_0809A4BA:
	strb r0, [r1, 0x3]
_0809A4BC:
	movs r4, 0
	movs r5, 0
_0809A4C0:
	ldr r0, _0809A4DC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A4E0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A4FC
	.align 2, 0
_0809A4DC: .4byte gUnknown_2039998
_0809A4E0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A4F2
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A4FC
_0809A4F2:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A4FC:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A4C0
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
_0809A50E:
	ldr r0, _0809A52C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A530
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A54C
	.align 2, 0
_0809A52C: .4byte gUnknown_2039998
_0809A530:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A542
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A54C
_0809A542:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A54C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A50E
_0809A558:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8099E80

	thumb_func_start sub_809A560
sub_809A560:
	push {r4-r6,lr}
	bl sub_8014144
	ldr r6, _0809A5F4
	movs r0, 0xB5
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r6]
	movs r4, 0
	str r4, [r0]
	movs r5, 0x1
	negs r5, r5
	str r5, [r0, 0x4]
	str r5, [r0, 0x8]
	ldr r0, _0809A5F8
	strh r4, [r0]
	ldr r0, _0809A5FC
	strh r4, [r0]
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	movs r1, 0x14
	bl sub_8009408
	bl sub_809B294
	ldr r0, [r6]
	ldr r2, _0809A600
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r5, [r1]
	ldr r1, _0809A604
	adds r0, r1
	str r5, [r0]
	bl sub_809A7EC
	ldr r0, [r6]
	ldr r2, _0809A608
	adds r0, r2
	ldr r1, _0809A60C
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A5F4: .4byte gUnknown_3001B64
_0809A5F8: .4byte gUnknown_20399DC
_0809A5FC: .4byte gUnknown_20399DE
_0809A600: .4byte 0x00000414
_0809A604: .4byte 0x00000434
_0809A608: .4byte 0x000005a4
_0809A60C: .4byte 0x0000ffff
	thumb_func_end sub_809A560

	thumb_func_start sub_809A610
sub_809A610:
	push {r4,lr}
	bl sub_809A62C
	ldr r4, _0809A628
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A628: .4byte gUnknown_3001B64
	thumb_func_end sub_809A610

	thumb_func_start sub_809A62C
sub_809A62C:
	push {r4,lr}
	ldr r0, _0809A670
	ldr r0, [r0]
	movs r2, 0
	str r2, [r0]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	ldr r0, _0809A674
	strh r2, [r0]
	ldr r0, _0809A678
	strh r2, [r0]
	movs r4, 0
_0809A648:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_809A83C
	adds r4, 0x1
	cmp r4, 0x9
	ble _0809A648
	ldr r0, _0809A670
	ldr r0, [r0]
	ldr r1, _0809A67C
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A670: .4byte gUnknown_3001B64
_0809A674: .4byte gUnknown_20399DC
_0809A678: .4byte gUnknown_20399DE
_0809A67C: .4byte 0x00000414
	thumb_func_end sub_809A62C

	thumb_func_start sub_809A680
sub_809A680:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0x4
	bhi _0809A6C2
	lsls r0, r4, 2
	ldr r1, _0809A694
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809A694: .4byte _0809A698
	.align 2, 0
_0809A698:
	.4byte _0809A6AC
	.4byte _0809A6BC
	.4byte _0809A6BC
	.4byte _0809A6BC
	.4byte _0809A6BC
_0809A6AC:
	bl sub_809B294
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0809A6D0
_0809A6BC:
	bl sub_809B294
	b _0809A6D0
_0809A6C2:
	bl sub_809B294
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0809A6D0:
	ldr r0, _0809A6E0
	ldr r0, [r0]
	str r4, [r0]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809A6E0: .4byte gUnknown_3001B64
	thumb_func_end sub_809A680

	thumb_func_start sub_809A6E4
sub_809A6E4:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0809A6F4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_0809A6F4: .4byte gUnknown_20399DC
	thumb_func_end sub_809A6E4

	thumb_func_start sub_809A6F8
sub_809A6F8:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0809A708
	ldrh r1, [r2]
	bics r1, r0
	strh r1, [r2]
	bx lr
	.align 2, 0
_0809A708: .4byte gUnknown_20399DC
	thumb_func_end sub_809A6F8

	thumb_func_start sub_809A70C
sub_809A70C:
	ldr r0, _0809A714
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_0809A714: .4byte gUnknown_20399DC
	thumb_func_end sub_809A70C

	thumb_func_start nullsub_209
nullsub_209:
	bx lr
	thumb_func_end nullsub_209

	thumb_func_start sub_809A71C
sub_809A71C:
	push {lr}
	adds r1, r0, 0
	ldr r0, _0809A734
	ldr r0, [r0]
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	adds r0, r1, 0
	bl sub_801416C
	pop {r0}
	bx r0
	.align 2, 0
_0809A734: .4byte gUnknown_3001B64
	thumb_func_end sub_809A71C

	thumb_func_start sub_809A738
sub_809A738:
	push {lr}
	ldr r2, _0809A74C
	ldr r2, [r2]
	str r0, [r2, 0x4]
	str r1, [r2, 0x8]
	bl sub_801416C
	pop {r0}
	bx r0
	.align 2, 0
_0809A74C: .4byte gUnknown_3001B64
	thumb_func_end sub_809A738

	thumb_func_start sub_809A750
sub_809A750:
	push {lr}
	ldr r0, _0809A764
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_809B40C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_0809A764: .4byte gUnknown_3001B64
	thumb_func_end sub_809A750

	thumb_func_start sub_809A768
sub_809A768:
	movs r0, 0
	bx lr
	thumb_func_end sub_809A768

	thumb_func_start sub_809A76C
sub_809A76C:
	push {lr}
	ldr r0, _0809A78C
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0x1
	bcc _0809A7A4
	cmp r1, 0x2
	bls _0809A790
	cmp r1, 0x3
	bne _0809A7A4
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x4
	b _0809A798
	.align 2, 0
_0809A78C: .4byte gUnknown_3001B64
_0809A790:
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x84
_0809A798:
	movs r3, 0
	bl sub_809B2B8
	lsls r0, 24
	lsrs r0, 24
	b _0809A7AE
_0809A7A4:
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	movs r0, 0
_0809A7AE:
	pop {r1}
	bx r1
	thumb_func_end sub_809A76C

	thumb_func_start sub_809A7B4
sub_809A7B4:
	push {lr}
	ldr r0, _0809A7D8
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0x3
	bhi _0809A7DC
	cmp r1, 0x1
	bcc _0809A7DC
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x4
	movs r3, 0
	bl sub_809B2B8
	lsls r0, 24
	lsrs r0, 24
	b _0809A7E6
	.align 2, 0
_0809A7D8: .4byte gUnknown_3001B64
_0809A7DC:
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	movs r0, 0
_0809A7E6:
	pop {r1}
	bx r1
	thumb_func_end sub_809A7B4

	thumb_func_start sub_809A7EC
sub_809A7EC:
	push {r4-r6,lr}
	ldr r0, _0809A830
	ldr r0, [r0]
	ldr r2, _0809A834
	adds r1, r0, r2
	ldr r0, _0809A838
	adds r6, r0, 0
	movs r3, 0
	movs r2, 0
	movs r4, 0x9
	movs r5, 0xFF
_0809A802:
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
	strh r2, [r1, 0x2]
	strb r3, [r1, 0x4]
	strb r3, [r1, 0x5]
	ldrb r0, [r1, 0x6]
	orrs r0, r5
	strb r0, [r1, 0x6]
	strb r3, [r1, 0x7]
	str r2, [r1, 0x8]
	str r2, [r1, 0xC]
	str r2, [r1, 0x10]
	str r2, [r1, 0x14]
	strb r3, [r1, 0x1C]
	str r2, [r1, 0x20]
	subs r4, 0x1
	adds r1, 0x24
	cmp r4, 0
	bge _0809A802
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A830: .4byte gUnknown_3001B64
_0809A834: .4byte 0x0000043c
_0809A838: .4byte 0x0000ffff
	thumb_func_end sub_809A7EC

	thumb_func_start sub_809A83C
sub_809A83C:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0809A8A0
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r3, _0809A8A4
	adds r1, r3
	ldr r2, [r2]
	adds r6, r2, r1
	ldr r1, _0809A8A8
	strh r1, [r6]
	movs r2, 0
	movs r7, 0
	strh r7, [r6, 0x2]
	strb r2, [r6, 0x4]
	strb r2, [r6, 0x5]
	movs r1, 0xFF
	strb r1, [r6, 0x6]
	strb r2, [r6, 0x7]
	str r7, [r6, 0x8]
	str r7, [r6, 0xC]
	str r7, [r6, 0x10]
	str r7, [r6, 0x14]
	strb r2, [r6, 0x1C]
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 4
	ldr r0, _0809A8AC
	adds r0, r4, r0
	ldr r5, _0809A8B0
	adds r1, r5, 0
	bl strcpy
	ldr r0, _0809A8B4
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	ldr r0, [r6, 0x20]
	cmp r0, 0
	beq _0809A89A
	bl CloseFile
	str r7, [r6, 0x20]
_0809A89A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A8A0: .4byte gUnknown_3001B64
_0809A8A4: .4byte 0x0000043c
_0809A8A8: .4byte 0x0000ffff
_0809A8AC: .4byte gUnknown_202DF98
_0809A8B0: .4byte gUnknown_811615C
_0809A8B4: .4byte gUnknown_202E2B8
	thumb_func_end sub_809A83C

	thumb_func_start sub_809A8B8
sub_809A8B8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	mov r0, sp
	strh r1, [r0]
	ldr r1, _0809A928
	mov r2, r9
	lsls r0, r2, 3
	add r0, r9
	lsls r0, 2
	ldr r2, _0809A92C
	adds r0, r2
	ldr r1, [r1]
	adds r7, r1, r0
	movs r0, 0x1
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, [r7, 0x20]
	cmp r0, 0
	beq _0809A8F6
	bl CloseFile
	ldr r2, [sp, 0x4]
	str r2, [r7, 0x20]
_0809A8F6:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A7DDC
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x13
	bhi _0809A9D6
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	adds r5, r0, 0
	cmp r5, 0
	bne _0809A930
	movs r2, 0
	mov r10, r2
	b _0809A9D6
	.align 2, 0
_0809A928: .4byte gUnknown_3001B64
_0809A92C: .4byte 0x0000043c
_0809A930:
	bl sub_808D3BC
	cmp r5, r0
	bne _0809A940
	mov r1, sp
	movs r0, 0x21
	strh r0, [r1]
	b _0809A9D6
_0809A940:
	bl sub_808D3F8
	cmp r5, r0
	bne _0809A950
	mov r1, sp
	movs r0, 0x22
	strh r0, [r1]
	b _0809A9D6
_0809A950:
	ldrb r0, [r5, 0x4]
	subs r0, 0x43
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _0809A990
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldr r0, _0809A978
	cmp r1, r0
	beq _0809A9D6
	cmp r1, r0
	ble _0809A97C
	adds r0, 0x16
	cmp r1, r0
	bgt _0809A98A
	subs r0, 0x1
	cmp r1, r0
	blt _0809A98A
	b _0809A9D6
	.align 2, 0
_0809A978: .4byte 0x00000183
_0809A97C:
	movs r0, 0x82
	lsls r0, 1
	cmp r1, r0
	beq _0809A9D6
	adds r0, 0x2F
	cmp r1, r0
	beq _0809A9D6
_0809A98A:
	movs r1, 0
	mov r10, r1
	b _0809A9D6
_0809A990:
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r0, 0x87
	lsls r0, 1
	cmp r1, r0
	bgt _0809A9B0
	subs r0, 0x2
	cmp r1, r0
	bge _0809A9D6
	cmp r1, 0x90
	blt _0809A9D2
	cmp r1, 0x92
	ble _0809A9D6
	cmp r1, 0x96
	beq _0809A9D6
	b _0809A9D2
_0809A9B0:
	movs r0, 0xCF
	lsls r0, 1
	cmp r1, r0
	bgt _0809A9CC
	subs r0, 0x4
	cmp r1, r0
	bge _0809A9D6
	subs r0, 0x87
	cmp r1, r0
	bgt _0809A9D2
	subs r0, 0x1
	cmp r1, r0
	blt _0809A9D2
	b _0809A9D6
_0809A9CC:
	ldr r0, _0809A9F0
	cmp r1, r0
	beq _0809A9D6
_0809A9D2:
	movs r0, 0
	mov r10, r0
_0809A9D6:
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x21
	bhi _0809AA98
	lsls r0, 2
	ldr r1, _0809A9F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809A9F0: .4byte 0x000001a7
_0809A9F4: .4byte _0809A9F8
	.align 2, 0
_0809A9F8:
	.4byte _0809AA80
	.4byte _0809AA80
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA80
	.4byte _0809AA80
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA80
	.4byte _0809AA80
_0809AA80:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_80A8CF0
	lsls r0, 24
	cmp r0, 0
	beq _0809AA94
	movs r2, 0x1
	str r2, [sp, 0x4]
	b _0809AA98
_0809AA94:
	movs r0, 0
	mov r10, r0
_0809AA98:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809AB34
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A7AE8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _0809AACE
	mov r0, sp
	ldrh r0, [r0]
	movs r2, 0
	mov r8, r2
	movs r6, 0
	strh r0, [r7]
	adds r0, r1, 0
	bl sub_80A8BFC
	strh r0, [r7, 0x2]
	b _0809AAE6
_0809AACE:
	ldrh r1, [r4]
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0809AB34
	mov r0, sp
	ldrh r0, [r0]
	movs r2, 0
	mov r8, r2
	movs r6, 0
	strh r0, [r7]
	strh r1, [r7, 0x2]
_0809AAE6:
	mov r0, r9
	lsls r4, r0, 2
	add r4, r9
	lsls r4, 4
	ldr r0, _0809AB28
	adds r0, r4, r0
	ldr r5, _0809AB2C
	adds r1, r5, 0
	bl strcpy
	ldr r0, _0809AB30
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	mov r1, r10
	strb r1, [r7, 0x4]
	mov r2, sp
	ldrb r2, [r2, 0x4]
	strb r2, [r7, 0x5]
	movs r0, 0xFF
	strb r0, [r7, 0x6]
	mov r0, r8
	strb r0, [r7, 0x7]
	str r6, [r7, 0x8]
	str r6, [r7, 0xC]
	str r6, [r7, 0x10]
	str r6, [r7, 0x14]
	strb r0, [r7, 0x1C]
	movs r0, 0x1
	b _0809AB3C
	.align 2, 0
_0809AB28: .4byte gUnknown_202DF98
_0809AB2C: .4byte gUnknown_811616C
_0809AB30: .4byte gUnknown_202E2B8
_0809AB34:
	mov r0, r9
	bl sub_809A83C
	movs r0, 0
_0809AB3C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809A8B8

	thumb_func_start sub_809AB4C
sub_809AB4C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809AB78
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809AB7C
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809AB80
	movs r0, 0
	b _0809ABA0
	.align 2, 0
_0809AB78: .4byte gUnknown_3001B64
_0809AB7C: .4byte 0x0000043c
_0809AB80:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r0, _0809ABA8
	adds r0, r4, r0
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl sub_808D908
	ldr r0, _0809ABAC
	adds r4, r0
	ldr r1, _0809ABB0
	adds r0, r4, 0
	bl strcpy
	movs r0, 0x1
_0809ABA0:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809ABA8: .4byte gUnknown_202DF98
_0809ABAC: .4byte gUnknown_202E2B8
_0809ABB0: .4byte gUnknown_811617C
	thumb_func_end sub_809AB4C

	thumb_func_start sub_809ABB4
sub_809ABB4:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809ABE0
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809ABE4
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809ABE8
	movs r0, 0
	b _0809AC0A
	.align 2, 0
_0809ABE0: .4byte gUnknown_3001B64
_0809ABE4: .4byte 0x0000043c
_0809ABE8:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r5, _0809AC10
	adds r5, r4, r5
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_808D908
	ldr r0, _0809AC14
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	movs r0, 0x1
_0809AC0A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AC10: .4byte gUnknown_202DF98
_0809AC14: .4byte gUnknown_202E2B8
	thumb_func_end sub_809ABB4

	thumb_func_start sub_809AC18
sub_809AC18:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809AC44
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809AC48
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809AC4C
	movs r0, 0
	b _0809AC6E
	.align 2, 0
_0809AC44: .4byte gUnknown_3001B64
_0809AC48: .4byte 0x0000043c
_0809AC4C:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r0, _0809AC74
	adds r0, r4, r0
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl sub_808D908
	ldr r0, _0809AC78
	adds r4, r0
	movs r3, 0
	ldrsh r1, [r6, r3]
	adds r0, r4, 0
	bl sub_80A8EC0
	movs r0, 0x1
_0809AC6E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AC74: .4byte gUnknown_202DF98
_0809AC78: .4byte gUnknown_202E2B8
	thumb_func_end sub_809AC18

	thumb_func_start sub_809AC7C
sub_809AC7C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r2, _0809AD10
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, _0809AD14
	adds r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldr r0, [r4, 0x20]
	cmp r0, 0
	beq _0809ACA8
	bl CloseFile
	movs r0, 0
	str r0, [r4, 0x20]
_0809ACA8:
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bge _0809ACB2
	b _0809ADC0
_0809ACB2:
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0809ACBC
	b _0809ADC0
_0809ACBC:
	cmp r1, 0
	bne _0809ACC2
	b _0809ADC0
_0809ACC2:
	cmp r6, 0x15
	beq _0809ACCE
	movs r0, 0
	strb r6, [r4, 0x7]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
_0809ACCE:
	ldr r2, _0809AD18
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r4, 0x8]
	ldrh r0, [r0]
	adds r0, r1
	movs r6, 0
	movs r3, 0
	strh r0, [r4, 0x18]
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r4, 0xC]
	ldrh r0, [r0, 0x2]
	adds r0, r1
	strh r0, [r4, 0x1A]
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	strb r0, [r4, 0x1D]
	strb r6, [r4, 0x1E]
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	bne _0809AD1C
	strb r5, [r4, 0x6]
	str r3, [r4, 0x10]
	str r3, [r4, 0x14]
	strb r6, [r4, 0x1C]
	movs r0, 0
	b _0809ADD2
	.align 2, 0
_0809AD10: .4byte gUnknown_3001B64
_0809AD14: .4byte 0x0000043c
_0809AD18: .4byte gUnknown_8116040
_0809AD1C:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _0809ADC0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_808DD90
	str r0, [r4, 0x20]
	cmp r0, 0
	beq _0809ADB6
	strb r5, [r4, 0x6]
	str r0, [r4, 0x10]
	movs r1, 0
	bl GetFileDataPtr
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x4D
	beq _0809AD62
	cmp r0, 0x4D
	bgt _0809AD4C
	cmp r0, 0x47
	beq _0809AD56
	b _0809ADA8
_0809AD4C:
	cmp r0, 0x53
	beq _0809AD76
	cmp r0, 0x73
	beq _0809AD8A
	b _0809ADA8
_0809AD56:
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x5
	bgt _0809ADA8
	adds r0, r5, 0x6
	b _0809AD9C
_0809AD62:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x3
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x4
	b _0809AD9C
_0809AD76:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x1
	b _0809AD9C
_0809AD8A:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x1
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x2
_0809AD9C:
	lsls r0, 24
	asrs r5, r0, 24
	movs r0, 0x40
	orrs r5, r0
	lsls r0, r5, 24
	asrs r5, r0, 24
_0809ADA8:
	ldr r0, [r4, 0x20]
	ldr r0, [r0, 0x4]
	str r0, [r4, 0x14]
	movs r0, 0xF
	ands r5, r0
	strb r5, [r4, 0x1C]
	b _0809ADBC
_0809ADB6:
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	strb r6, [r4, 0x1C]
_0809ADBC:
	movs r0, 0x1
	b _0809ADD2
_0809ADC0:
	movs r0, 0xFF
	strb r0, [r4, 0x6]
	movs r0, 0
	strb r0, [r4, 0x7]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	strb r0, [r4, 0x1C]
_0809ADD2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809AC7C

	thumb_func_start sub_809ADD8
sub_809ADD8:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0809AE28
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, _0809AE2C
	adds r1, r0
	ldr r0, [r2]
	adds r3, r0, r1
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, 0
	blt _0809AE34
	cmp r0, 0
	beq _0809AE34
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r3, 0x8]
	str r1, [r3, 0xC]
	ldr r2, _0809AE30
	ldrb r0, [r3, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r3, 0x8]
	ldrh r0, [r0]
	adds r0, r1
	strh r0, [r3, 0x18]
	ldrb r0, [r3, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r3, 0xC]
	ldrh r0, [r0, 0x2]
	adds r0, r1
	strh r0, [r3, 0x1A]
	movs r0, 0x1
	b _0809AE36
	.align 2, 0
_0809AE28: .4byte gUnknown_3001B64
_0809AE2C: .4byte 0x0000043c
_0809AE30: .4byte gUnknown_8116040
_0809AE34:
	movs r0, 0
_0809AE36:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809ADD8

	thumb_func_start sub_809AE3C
sub_809AE3C:
	push {r4,lr}
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _0809AE88
	ldr r1, _0809AE80
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r3, _0809AE84
	adds r0, r3
	ldr r1, [r1]
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0809AE74
	movs r1, 0x6
	ldrsb r1, [r4, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809AE74
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0
	bl sub_809AC7C
_0809AE74:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0809AE88
	adds r0, r4, 0
	adds r0, 0x10
	b _0809AE8A
	.align 2, 0
_0809AE80: .4byte gUnknown_3001B64
_0809AE84: .4byte 0x0000043c
_0809AE88:
	movs r0, 0
_0809AE8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AE3C

	thumb_func_start sub_809AE90
sub_809AE90:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	lsls r1, 16
	asrs r6, r1, 16
	cmp r4, 0
	bne _0809AEA4
	bl sub_809A76C
	b _0809AEE0
_0809AEA4:
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AEDC
	ldr r1, _0809AED0
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl sub_809A680
	ldr r0, _0809AED4
	ldr r0, [r0]
	adds r0, 0xC
	ldr r2, _0809AED8
	lsls r1, r5, 1
	adds r1, r2
	ldrh r1, [r1]
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AEE0
	.align 2, 0
_0809AED0: .4byte gUnknown_8116134
_0809AED4: .4byte gUnknown_3001B64
_0809AED8: .4byte gUnknown_8116148
_0809AEDC:
	bl sub_809A7B4
_0809AEE0:
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809AE90

	thumb_func_start sub_809AEEC
sub_809AEEC:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0809AF1C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF1C
	movs r0, 0x2
	movs r1, 0x1
	bl sub_809A680
	ldr r0, _0809AF18
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0xC2
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AF20
	.align 2, 0
_0809AF18: .4byte gUnknown_3001B64
_0809AF1C:
	bl sub_809A76C
_0809AF20:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AEEC

	thumb_func_start sub_809AF2C
sub_809AF2C:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0809AF5C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF5C
	movs r0, 0x2
	movs r1, 0x1
	bl sub_809A680
	ldr r0, _0809AF58
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0xC2
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AF60
	.align 2, 0
_0809AF58: .4byte gUnknown_3001B64
_0809AF5C:
	bl sub_809A76C
_0809AF60:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AF2C

	thumb_func_start sub_809AF6C
sub_809AF6C:
	push {r4,lr}
	adds r4, r1, 0
	cmp r4, 0
	beq _0809AF9C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF9C
	movs r0, 0x3
	movs r1, 0x1
	bl sub_809A680
	ldr r0, _0809AF98
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x65
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AFA0
	.align 2, 0
_0809AF98: .4byte gUnknown_3001B64
_0809AF9C:
	bl sub_809A76C
_0809AFA0:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AF6C

	thumb_func_start sub_809AFAC
sub_809AFAC:
	push {lr}
	movs r1, 0
	ldr r0, _0809AFC4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0809AFBC
	movs r1, 0x1
_0809AFBC:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809AFC4: .4byte gUnknown_3001B64
	thumb_func_end sub_809AFAC

	thumb_func_start sub_809AFC8
sub_809AFC8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r1, 0
	adds r1, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	asrs r1, 16
	ldr r4, _0809AFF8
	negs r2, r0
	orrs r2, r0
	lsrs r2, 31
	str r1, [sp]
	str r3, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	adds r3, r5, 0
	bl sub_809B028
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AFF8: .4byte gUnknown_81160E8
	thumb_func_end sub_809AFC8

	thumb_func_start sub_809AFFC
sub_809AFFC:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	mov r0, sp
	bl sub_809B18C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r4, 0
	beq _0809B01C
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bne _0809B01A
	movs r1, 0x1
_0809B01A:
	strb r1, [r4]
_0809B01C:
	adds r0, r2, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AFFC

	thumb_func_start sub_809B028
sub_809B028:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	mov r8, r0
	adds r7, r2, 0
	adds r6, r3, 0
	ldr r0, [sp, 0x2C]
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0809B084
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl sub_809A680
	ldr r0, _0809B088
	ldr r1, [r0]
	ldr r0, _0809B08C
	adds r2, r1, r0
	movs r0, 0x1
	str r0, [r2]
	movs r0, 0x83
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0
	str r0, [r2]
	ldr r2, _0809B090
	adds r0, r1, r2
	mov r2, r8
	str r2, [r0]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r1, r2
	movs r2, 0x2
	str r2, [r0]
	ldr r0, _0809B094
	adds r1, r0
	cmp r5, 0
	beq _0809B098
	str r2, [r1]
	b _0809B09A
	.align 2, 0
_0809B084: .4byte gUnknown_8116134
_0809B088: .4byte gUnknown_3001B64
_0809B08C: .4byte 0x00000414
_0809B090: .4byte 0x0000041c
_0809B094: .4byte 0x00000424
_0809B098:
	str r5, [r1]
_0809B09A:
	ldr r0, _0809B0D4
	ldr r0, [r0]
	movs r1, 0x85
	lsls r1, 3
	adds r2, r0, r1
	movs r1, 0
	str r1, [r2]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	str r7, [r0]
	ldr r0, _0809B0D8
	lsls r2, r6, 1
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	adds r5, r2, 0
	cmp r0, 0
	beq _0809B0F6
	cmp r4, 0
	bge _0809B0E4
	ldr r0, _0809B0DC
	ldr r1, _0809B0E0
	bl strcpy
	b _0809B0F6
	.align 2, 0
_0809B0D4: .4byte gUnknown_3001B64
_0809B0D8: .4byte gUnknown_8116148
_0809B0DC: .4byte gUnknown_202E5D8
_0809B0E0: .4byte gUnknown_8116180
_0809B0E4:
	ldr r0, _0809B134
	ldr r1, _0809B138
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 4
	ldr r3, _0809B13C
	adds r2, r3
	bl sub_800D158
_0809B0F6:
	adds r0, r4, 0
	bl sub_809AE3C
	ldr r4, _0809B140
	movs r1, 0
	str r1, [sp]
	movs r3, 0x4
	str r3, [sp, 0x4]
	str r1, [sp, 0x8]
	str r0, [sp, 0xC]
	ldr r0, _0809B144
	adds r0, r5, r0
	ldrh r2, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _0809B11C
	movs r1, 0xC
_0809B11C:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	beq _0809B128
	orrs r1, r3
_0809B128:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _0809B148
	movs r0, 0x21
	b _0809B14A
	.align 2, 0
_0809B134: .4byte gUnknown_202E5D8
_0809B138: .4byte gUnknown_8116188
_0809B13C: .4byte gUnknown_202E2B8
_0809B140: .4byte sub_809B428
_0809B144: .4byte gUnknown_8116148
_0809B148:
	movs r0, 0x1
_0809B14A:
	orrs r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	ldr r0, [sp, 0x30]
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8014248
	ldr r0, _0809B184
	ldr r0, [r0]
	ldr r1, _0809B188
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809B176
	movs r0, 0x1
	bl sub_809A6E4
_0809B176:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B184: .4byte gUnknown_3001B64
_0809B188: .4byte 0x00000424
	thumb_func_end sub_809B028

	thumb_func_start sub_809B18C
sub_809B18C:
	push {lr}
	adds r1, r0, 0
	ldr r2, _0809B1BC
	cmp r1, 0
	beq _0809B1A2
	ldr r0, [r2]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809B1A2:
	movs r1, 0
	ldr r0, [r2]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B1B4
	movs r1, 0x1
_0809B1B4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809B1BC: .4byte gUnknown_3001B64
	thumb_func_end sub_809B18C

	thumb_func_start sub_809B1C0
sub_809B1C0:
	push {lr}
	adds r3, r2, 0
	movs r2, 0
	bl sub_809B1D4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_809B1C0

	thumb_func_start sub_809B1D4
sub_809B1D4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	cmp r4, 0xB
	beq _0809B1E8
	cmp r4, 0xC
	beq _0809B1F0
	b _0809B202
_0809B1E8:
	adds r0, r5, 0
	bl sub_8021700
	b _0809B1F8
_0809B1F0:
	bl sub_8001D88
	bl sub_802FCF0
_0809B1F8:
	lsls r0, 24
	cmp r0, 0
	beq _0809B202
	movs r0, 0
	b _0809B24C
_0809B202:
	movs r0, 0x4
	movs r1, 0
	bl sub_809A680
	ldr r0, _0809B254
	ldr r1, [r0]
	ldr r2, _0809B258
	adds r0, r1, r2
	str r4, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r1, r3
	movs r2, 0
	str r2, [r0]
	adds r3, 0x4
	adds r0, r1, r3
	str r2, [r0]
	movs r0, 0x84
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0x1
	str r0, [r2]
	ldr r2, _0809B25C
	adds r0, r1, r2
	str r5, [r0]
	adds r3, 0xC
	adds r0, r1, r3
	str r6, [r0]
	adds r2, 0x8
	adds r0, r1, r2
	str r7, [r0]
	adds r3, 0x8
	adds r1, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	movs r0, 0x1
_0809B24C:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B254: .4byte gUnknown_3001B64
_0809B258: .4byte 0x00000414
_0809B25C: .4byte 0x00000424
	thumb_func_end sub_809B1D4

	thumb_func_start sub_809B260
sub_809B260:
	push {lr}
	adds r1, r0, 0
	ldr r2, _0809B290
	cmp r1, 0
	beq _0809B276
	ldr r0, [r2]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809B276:
	movs r1, 0
	ldr r0, [r2]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B288
	movs r1, 0x1
_0809B288:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809B290: .4byte gUnknown_3001B64
	thumb_func_end sub_809B260

	thumb_func_start sub_809B294
sub_809B294:
	push {lr}
	movs r0, 0x3
	bl sub_80063D8
	ldr r0, _0809B2B4
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	movs r3, 0
	bl sub_809B2B8
	pop {r0}
	bx r0
	.align 2, 0
_0809B2B4: .4byte gUnknown_3001B64
	thumb_func_end sub_809B294

	thumb_func_start sub_809B2B8
sub_809B2B8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r4, r0, 0
	adds r7, r3, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	asrs r6, r2, 16
	strh r5, [r4]
	cmp r7, 0
	bne _0809B2F6
	cmp r5, 0
	bne _0809B2DE
	str r7, [r4, 0x4]
	movs r0, 0
	b _0809B3FC
_0809B2DE:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	bne _0809B2E8
	b _0809B3FA
_0809B2E8:
	bl sub_8014490
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	b _0809B3FA
_0809B2F6:
	movs r0, 0x1
	str r0, [r4, 0x4]
	adds r0, 0xFF
	ands r0, r5
	cmp r0, 0
	beq _0809B32A
	cmp r6, 0
	bge _0809B318
	ldr r0, _0809B310
	ldr r1, _0809B314
	bl strcpy
	b _0809B32A
	.align 2, 0
_0809B310: .4byte gUnknown_202E5D8
_0809B314: .4byte gUnknown_8116180
_0809B318:
	ldr r0, _0809B3D0
	ldr r1, _0809B3D4
	lsls r2, r6, 2
	adds r2, r6
	lsls r2, 4
	ldr r3, _0809B3D8
	adds r2, r3
	bl sub_800D158
_0809B32A:
	ldr r0, _0809B3DC
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B344
	adds r4, 0x8
	ldr r1, _0809B3E0
	adds r0, r4, 0
	adds r2, r7, 0
	bl sub_800D158
	adds r7, r4, 0
_0809B344:
	adds r0, r6, 0
	bl sub_809AE3C
	ldr r1, _0809B3E4
	mov r9, r1
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	movs r2, 0
	str r2, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r0, [sp, 0xC]
	movs r6, 0x80
	lsls r6, 1
	adds r0, r5, 0
	ands r0, r6
	movs r1, 0
	cmp r0, 0
	beq _0809B370
	movs r1, 0xC
_0809B370:
	movs r4, 0x80
	lsls r4, 2
	adds r0, r5, 0
	ands r0, r4
	cmp r0, 0
	beq _0809B380
	movs r0, 0x4
	orrs r1, r0
_0809B380:
	mov r0, r8
	ldr r3, [r0]
	ldr r2, [r3]
	cmp r2, 0x3
	bne _0809B38E
	movs r0, 0x10
	orrs r1, r0
_0809B38E:
	cmp r2, 0x2
	bne _0809B396
	movs r0, 0x10
	orrs r1, r0
_0809B396:
	adds r2, r1, 0
	movs r1, 0x20
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809B3A4
	orrs r2, r1
_0809B3A4:
	lsrs r1, r5, 6
	movs r0, 0x1
	ands r1, r0
	orrs r1, r2
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	beq _0809B3B6
	orrs r1, r6
_0809B3B6:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _0809B3C0
	orrs r1, r4
_0809B3C0:
	ldr r0, [r3, 0x4]
	cmp r0, r12
	beq _0809B3E8
	movs r0, 0x2
	orrs r0, r1
	lsls r0, 16
	b _0809B3EA
	.align 2, 0
_0809B3D0: .4byte gUnknown_202E5D8
_0809B3D4: .4byte gUnknown_8116188
_0809B3D8: .4byte gUnknown_202E2B8
_0809B3DC: .4byte gUnknown_3001B64
_0809B3E0: .4byte gUnknown_8116190
_0809B3E4: .4byte sub_809B428
_0809B3E8:
	lsls r0, r1, 16
_0809B3EA:
	lsrs r0, 16
	str r0, [sp, 0x10]
	adds r0, r7, 0
	mov r1, r9
	mov r2, r12
	movs r3, 0
	bl sub_8014248
_0809B3FA:
	movs r0, 0x1
_0809B3FC:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809B2B8

	thumb_func_start sub_809B40C
sub_809B40C:
	push {lr}
	ldr r0, [r0, 0x4]
	cmp r0, 0
	beq _0809B41C
	cmp r0, 0x3
	bhi _0809B420
	cmp r0, 0x2
	bcc _0809B420
_0809B41C:
	movs r0, 0
	b _0809B422
_0809B420:
	movs r0, 0x1
_0809B422:
	pop {r1}
	bx r1
	thumb_func_end sub_809B40C

	thumb_func_start sub_809B428
sub_809B428:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0x4F
	beq _0809B44C
	cmp r0, 0x4F
	bgt _0809B43E
	cmp r0, 0x49
	beq _0809B444
	b _0809B46A
_0809B43E:
	cmp r0, 0x57
	beq _0809B454
	b _0809B46A
_0809B444:
	movs r0, 0x1E
	bl sub_8099A34
	b _0809B462
_0809B44C:
	movs r0, 0x1E
	bl sub_8099A48
	b _0809B462
_0809B454:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809B462
	adds r0, r5, 0
	b _0809B46C
_0809B462:
	adds r1, r4, 0
	adds r1, 0x21
	movs r0, 0x1
	strb r0, [r1]
_0809B46A:
	movs r0, 0
_0809B46C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809B428

	thumb_func_start sub_809B474
sub_809B474:
	push {r4-r6,lr}
	ldr r0, _0809B498
	ldr r1, [r0]
	ldr r2, [r1]
	adds r6, r0, 0
	cmp r2, 0x3
	bls _0809B56E
	cmp r2, 0x4
	bne _0809B56E
	movs r5, 0x84
	lsls r5, 3
	adds r0, r1, r5
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0809B49C
	cmp r0, 0x2
	beq _0809B508
	b _0809B56E
	.align 2, 0
_0809B498: .4byte gUnknown_3001B64
_0809B49C:
	bl sub_809B648
	lsls r0, 24
	cmp r0, 0
	bne _0809B4B0
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x3
	str r1, [r0]
	b _0809B4E8
_0809B4B0:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _0809B4F8
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0809B4F2
	bl sub_809B294
	ldr r0, [r4, 0x4]
	bl _call_via_r0
	lsls r0, 24
	cmp r0, 0
	bne _0809B4F2
	ldr r1, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r2, r1, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r2]
	adds r1, r5
	movs r0, 0x3
	str r0, [r1]
_0809B4E8:
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	b _0809B56E
_0809B4F2:
	ldrh r0, [r4]
	bl sub_809A6E4
_0809B4F8:
	ldr r0, _0809B534
	ldr r1, [r0]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	movs r2, 0x2
	str r2, [r1]
	adds r6, r0, 0
_0809B508:
	ldr r0, [r6]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r4, [r0]
	cmp r4, 0
	beq _0809B54E
	ldr r0, [r4, 0xC]
	bl _call_via_r0
	adds r2, r0, 0
	cmp r2, 0x1
	bls _0809B56E
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r1, r0, r3
	cmp r2, 0x2
	bne _0809B538
	movs r0, 0x1
	negs r0, r0
	b _0809B53A
	.align 2, 0
_0809B534: .4byte gUnknown_3001B64
_0809B538:
	movs r0, 0
_0809B53A:
	str r0, [r1]
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0809B546
	bl _call_via_r0
_0809B546:
	ldrh r0, [r4]
	bl sub_809A6F8
	b _0809B558
_0809B54E:
	bl sub_809B648
	lsls r0, 24
	cmp r0, 0
	bne _0809B56E
_0809B558:
	ldr r0, _0809B578
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	movs r1, 0x3
	str r1, [r0]
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
_0809B56E:
	bl sub_809B57C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B578: .4byte gUnknown_3001B64
	thumb_func_end sub_809B474

	thumb_func_start sub_809B57C
sub_809B57C:
	push {r4,r5,lr}
	sub sp, 0x8
	bl xxx_draw_string_80144C4
	ldr r5, _0809B5C8
	ldr r0, [r5]
	ldr r1, [r0]
	cmp r1, 0x3
	bhi _0809B5E4
	cmp r1, 0x1
	bcc _0809B5E4
	movs r4, 0x84
	lsls r4, 3
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _0809B5CC
	cmp r0, 0x3
	beq _0809B5CC
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0809B5E4
	ldr r1, [sp]
	movs r0, 0x1
	bl sub_809D9E0
	ldr r1, [r5]
	adds r2, r1, r4
	movs r0, 0x3
	str r0, [r2]
	movs r0, 0x86
	lsls r0, 3
	adds r1, r0
	ldr r0, [sp]
	str r0, [r1]
	b _0809B5E4
	.align 2, 0
_0809B5C8: .4byte gUnknown_3001B64
_0809B5CC:
	add r0, sp, 0x4
	bl sub_80144A4
	adds r4, r0, 0
	cmp r4, 0
	bne _0809B5E4
	movs r0, 0
	bl sub_809D9B8
	ldr r0, _0809B5FC
	ldr r0, [r0]
	str r4, [r0]
_0809B5E4:
	ldr r0, _0809B5FC
	ldr r0, [r0]
	ldr r1, _0809B600
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bge _0809B604
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	b _0809B60C
	.align 2, 0
_0809B5FC: .4byte gUnknown_3001B64
_0809B600: .4byte 0x00000434
_0809B604:
	movs r0, 0
	movs r1, 0x5
	bl sub_8005838
_0809B60C:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809B57C

	thumb_func_start sub_809B614
sub_809B614:
	push {lr}
	bl sub_80060EC
	ldr r0, _0809B62C
	ldr r2, _0809B630
	ldrh r1, [r2]
	strh r1, [r0]
	ldr r0, _0809B634
	ands r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0809B62C: .4byte gUnknown_20399DE
_0809B630: .4byte gUnknown_20399DC
_0809B634: .4byte 0x0000fffd
	thumb_func_end sub_809B614

	thumb_func_start sub_809B638
sub_809B638:
	push {lr}
	bl xxx_call_update_bg_vram
	pop {r0}
	bx r0
	thumb_func_end sub_809B638

	thumb_func_start nullsub_210
nullsub_210:
	bx lr
	thumb_func_end nullsub_210

	thumb_func_start sub_809B648
sub_809B648:
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r0, _0809B66C
	ldr r1, [r0]
	ldr r2, _0809B670
	adds r1, r2
	ldr r1, [r1]
	subs r1, 0x2
	adds r6, r0, 0
	cmp r1, 0x2C
	bls _0809B662
	bl _0809C392
_0809B662:
	lsls r0, r1, 2
	ldr r1, _0809B674
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B66C: .4byte gUnknown_3001B64
_0809B670: .4byte 0x00000414
_0809B674: .4byte _0809B678
	.align 2, 0
_0809B678:
	.4byte _0809B72C
	.4byte _0809B772
	.4byte _0809B7AC
	.4byte _0809B834
	.4byte _0809B89C
	.4byte _0809B8FC
	.4byte _0809B91C
	.4byte _0809B944
	.4byte _0809B9D2
	.4byte _0809BA2A
	.4byte _0809BAA8
	.4byte _0809BB66
	.4byte _0809BBDA
	.4byte _0809BBDA
	.4byte _0809BC26
	.4byte _0809BC68
	.4byte _0809C1B4
	.4byte _0809BC78
	.4byte _0809C1C2
	.4byte _0809C1C2
	.4byte _0809C1C8
	.4byte _0809BCBC
	.4byte _0809BCBC
	.4byte _0809BD1C
	.4byte _0809BD64
	.4byte _0809BDE8
	.4byte _0809BE30
	.4byte _0809BE40
	.4byte _0809BE50
	.4byte _0809BE60
	.4byte _0809BE9C
	.4byte _0809BEB8
	.4byte _0809BED4
	.4byte _0809BF70
	.4byte _0809BFFC
	.4byte _0809C072
	.4byte _0809C0B8
	.4byte _0809C0FC
	.4byte _0809C148
	.4byte _0809C158
	.4byte _0809C168
	.4byte _0809C204
	.4byte _0809C238
	.4byte _0809C280
	.4byte _0809C32A
_0809B72C:
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0809B780
	ldr r0, _0809B754
	ldrh r0, [r0, 0x2]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0809B758
	movs r0, 0x86
	lsls r0, 3
	adds r1, r2, r0
	movs r0, 0x1
	str r0, [r1]
	bl _0809C392
	.align 2, 0
_0809B754: .4byte gUnknown_20255F0
_0809B758:
	bl sub_8094D14
	lsls r0, 24
	cmp r0, 0
	beq _0809B784
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x2
	str r1, [r0]
	bl _0809C392
_0809B772:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B78A
_0809B780:
	bl sub_809B294
_0809B784:
	movs r0, 0x1
	bl _0809C394
_0809B78A:
	ldr r0, _0809B7A8
	ldrh r1, [r0]
	ldrh r0, [r0, 0x2]
	movs r2, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0809B79C
	bl _0809C392
_0809B79C:
	ands r1, r2
	cmp r1, 0
	bne _0809B784
	bl _0809C392
	.align 2, 0
_0809B7A8: .4byte gUnknown_20255F0
_0809B7AC:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B7F4
	bl sub_809B294
	ldr r1, [r6]
	ldr r2, _0809B7D8
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B7E0
	ldr r3, _0809B7DC
	adds r0, r1, r3
	ldr r1, [r0]
	movs r0, 0
	bl sub_801602C
	b _0809B784
	.align 2, 0
_0809B7D8: .4byte 0x00000424
_0809B7DC: .4byte 0x0000042c
_0809B7E0:
	ldr r2, _0809B7F0
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, 0x2
	bl sub_801602C
	b _0809B784
	.align 2, 0
_0809B7F0: .4byte 0x0000042c
_0809B7F4:
	bl sub_8016080
	cmp r0, 0x3
	bne _0809B80C
	bl sub_80160D8
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809C1BC
_0809B80C:
	cmp r0, 0x2
	bne _0809B784
	ldr r0, [r6]
	ldr r1, _0809B830
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0809B784
	bl sub_80160D8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
_0809B828:
	movs r1, 0
	str r1, [r0]
	bl _0809C392
	.align 2, 0
_0809B830: .4byte 0x00000424
_0809B834:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B85C
	bl sub_809B294
	ldr r0, [r6]
	ldr r1, _0809B858
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x1
	bl sub_801602C
	b _0809B784
	.align 2, 0
_0809B858: .4byte 0x0000042c
_0809B85C:
	bl sub_8016080
	cmp r0, 0x3
	bne _0809B874
	bl sub_80160D8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	bl _0809C1BC
_0809B874:
	cmp r0, 0x2
	beq _0809B87A
	b _0809B784
_0809B87A:
	ldr r0, [r6]
	ldr r3, _0809B898
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B888
	b _0809B784
_0809B888:
	bl sub_80160D8
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	b _0809B828
	.align 2, 0
_0809B898: .4byte 0x00000424
_0809B89C:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B8C4
	bl sub_809B294
	ldr r0, [r6]
	ldr r3, _0809B8C0
	adds r0, r3
	ldr r1, [r0]
	movs r0, 0x4
	bl sub_80151C0
	b _0809B784
	.align 2, 0
_0809B8C0: .4byte 0x0000042c
_0809B8C4:
	bl sub_80154F0
	cmp r0, 0x3
	bne _0809B8D4
	bl sub_80155F0
	bl _0809C1B4
_0809B8D4:
	cmp r0, 0x2
	beq _0809B8DA
	b _0809B784
_0809B8DA:
	ldr r0, [r6]
	ldr r2, _0809B8F8
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B8E8
	b _0809B784
_0809B8E8:
	bl sub_80155F0
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B828
	.align 2, 0
_0809B8F8: .4byte 0x00000424
_0809B8FC:
	ldr r0, [r6]
	ldr r1, _0809B914
	adds r0, r1
	ldr r0, [r0]
	bl sub_801D014
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809B918
	b _0809B932
	.align 2, 0
_0809B914: .4byte 0x0000042c
_0809B918: .4byte gUnknown_81161A8
_0809B91C:
	ldr r0, [r6]
	ldr r3, _0809B93C
	adds r0, r3
	ldr r0, [r0]
	bl sub_801D014
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809B940
_0809B932:
	str r1, [r0]
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
	.align 2, 0
_0809B93C: .4byte 0x0000042c
_0809B940: .4byte gUnknown_81161B8
_0809B944:
	bl sub_809B294
	ldr r4, _0809B984
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B998
	bl sub_809B294
	ldr r0, [r4]
	ldr r3, _0809B988
	adds r0, r3
	ldr r0, [r0]
	ldr r1, _0809B98C
	bl sub_8015080
	lsls r0, 24
	cmp r0, 0
	bne _0809B990
	ldr r0, [r4]
_0809B972:
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
_0809B978:
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl _0809C392
	.align 2, 0
_0809B984: .4byte gUnknown_3001B64
_0809B988: .4byte 0x0000042c
_0809B98C: .4byte gUnknown_811610C
_0809B990:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809B998:
	bl sub_801516C
	cmp r0, 0x2
	beq _0809B9BC
	cmp r0, 0x3
	beq _0809B9A6
	b _0809B784
_0809B9A6:
	bl sub_8015198
	ldr r1, [r4]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	str r0, [r1]
	bl sub_80151A4
	bl _0809C392
_0809B9BC:
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_80151A4
	bl _0809C392
_0809B9D2:
	bl sub_809B294
	ldr r4, _0809BA08
	ldr r0, [r4]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BA1C
	bl sub_809B294
	ldr r0, [r4]
	ldr r2, _0809BA0C
	adds r0, r2
	ldr r0, [r0]
	ldr r1, _0809BA10
	bl sub_8015080
	lsls r0, 24
	cmp r0, 0
	bne _0809BA14
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BA08: .4byte gUnknown_3001B64
_0809BA0C: .4byte 0x0000042c
_0809BA10: .4byte gUnknown_811612C
_0809BA14:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BA1C:
	bl sub_801516C
	cmp r0, 0x2
	beq _0809B9BC
	cmp r0, 0x3
	beq _0809B9A6
	b _0809B784
_0809BA2A:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BA68
	bl sub_809B294
	ldr r0, [r6]
	ldr r2, _0809BA5C
	adds r0, r2
	ldr r0, [r0]
	movs r1, 0x3
	bl sub_80211AC
	lsls r0, 24
	cmp r0, 0
	bne _0809BA60
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BA5C: .4byte 0x00000424
_0809BA60:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BA68:
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x2
	beq _0809BA92
	cmp r0, 0x3
	beq _0809BA78
	b _0809B784
_0809BA78:
	bl sub_802132C
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	bl sub_80213A0
	bl _0809C392
_0809BA92:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_80213A0
	bl _0809C392
_0809BAA8:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BB10
	movs r0, 0
	movs r1, 0x12
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2654
	lsls r0, 16
	asrs r4, r0, 16
	bl sub_809B294
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	movs r3, 0x1
	bl sub_802F73C
	lsls r0, 24
	cmp r0, 0
	bne _0809BAEA
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
_0809BAEA:
	movs r5, 0x1
	negs r5, r5
	cmp r4, r5
	beq _0809BB08
	adds r0, r4, 0
	bl sub_802F848
	lsls r0, 24
	cmp r0, 0
	bne _0809BB08
	movs r0, 0
	movs r1, 0x12
	adds r2, r5, 0
	bl sub_80018D8
_0809BB08:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BB10:
	movs r0, 0x1
	bl sub_802F8A0
	cmp r0, 0x2
	beq _0809BB50
	cmp r0, 0x3
	beq _0809BB20
	b _0809B784
_0809BB20:
	bl sub_802F90C
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	str r4, [r0]
	bl sub_802F974
	bl _0809C392
_0809BB50:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_802F974
	bl _0809C392
_0809BB66:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BB9A
	bl sub_809B294
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	bl sub_80302E8
	lsls r0, 24
	cmp r0, 0
	bne _0809BB92
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
_0809BB92:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BB9A:
	movs r0, 0x1
	bl sub_80303AC
	cmp r0, 0x2
	beq _0809BBC4
	cmp r0, 0x3
	beq _0809BBAA
	b _0809B784
_0809BBAA:
	bl sub_8030418
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	str r0, [r1]
	bl sub_8030480
	bl _0809C392
_0809BBC4:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_8030480
	bl _0809C392
_0809BBDA:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BC14
	bl sub_809B294
	ldr r0, [r6]
	ldr r2, _0809BC10
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xE
	bne _0809BC02
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x1
	bl sub_80018D8
_0809BC02:
	movs r0, 0x1
	bl sub_8011C28
	movs r0, 0
	bl sub_8012574
	b _0809B784
	.align 2, 0
_0809BC10: .4byte 0x00000414
_0809BC14:
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	beq _0809BC20
	b _0809B784
_0809BC20:
	bl sub_8012750
	b _0809C392
_0809BC26:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_8016C94
	lsls r0, 24
	cmp r0, 0
	beq _0809BC5C
	ldr r0, _0809BC54
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BC58
	b _0809C266
	.align 2, 0
_0809BC54: .4byte gUnknown_3001B64
_0809BC58: .4byte gUnknown_81161C8
_0809BC5C:
	ldr r0, _0809BC64
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BC64: .4byte gUnknown_3001B64
_0809BC68:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BC74
	b _0809C266
	.align 2, 0
_0809BC74: .4byte gUnknown_81161D8
_0809BC78:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_80162E4
	lsls r0, 24
	cmp r0, 0
	beq _0809BCB0
	ldr r0, _0809BCA8
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BCAC
	b _0809C266
	.align 2, 0
_0809BCA8: .4byte gUnknown_3001B64
_0809BCAC: .4byte gUnknown_81161E8
_0809BCB0:
	ldr r0, _0809BCB8
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BCB8: .4byte gUnknown_3001B64
_0809BCBC:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_809B294
	ldr r0, _0809BCE0
	ldr r0, [r0]
	ldr r2, _0809BCE4
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x17
	bne _0809BCE8
	negs r0, r4
	orrs r0, r4
	lsrs r0, 31
	b _0809BCF0
	.align 2, 0
_0809BCE0: .4byte gUnknown_3001B64
_0809BCE4: .4byte 0x00000414
_0809BCE8:
	movs r0, 0x2
	cmp r4, 0
	beq _0809BCF0
	movs r0, 0x3
_0809BCF0:
	bl sub_8018B00
	lsls r0, 24
	cmp r0, 0
	beq _0809BD10
	ldr r0, _0809BD08
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BD0C
	b _0809C266
	.align 2, 0
_0809BD08: .4byte gUnknown_3001B64
_0809BD0C: .4byte gUnknown_81161F8
_0809BD10:
	ldr r0, _0809BD18
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BD18: .4byte gUnknown_3001B64
_0809BD1C:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_801FB50
	lsls r0, 24
	cmp r0, 0
	beq _0809BD54
	ldr r0, _0809BD4C
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BD50
	b _0809C266
	.align 2, 0
_0809BD4C: .4byte gUnknown_3001B64
_0809BD50: .4byte gUnknown_8116208
_0809BD54:
	ldr r0, _0809BD60
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BD60: .4byte gUnknown_3001B64
_0809BD64:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BD84
	bl sub_809B294
	movs r0, 0
	movs r1, 0x39
	bl sub_80015C0
	bl sub_802465C
	b _0809B784
_0809BD84:
	bl sub_80246F0
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x39
	bl sub_8001658
	cmp r0, 0
	bne _0809BDB2
	bl sub_80247B4
	lsls r0, 24
	cmp r0, 0
	beq _0809BDB2
	movs r0, 0
	movs r1, 0x39
	movs r2, 0x1
	bl sub_80018D8
	movs r0, 0x46
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809BDB2:
	cmp r4, 0x3
	bne _0809BDCC
	bl sub_80247C0
	ldr r0, _0809BDC8
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809C1BC
	.align 2, 0
_0809BDC8: .4byte gUnknown_3001B64
_0809BDCC:
	cmp r4, 0x2
	beq _0809BDD2
	b _0809B784
_0809BDD2:
	bl sub_80247C0
	ldr r0, _0809BDE4
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B828
	.align 2, 0
_0809BDE4: .4byte gUnknown_3001B64
_0809BDE8:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_8021B9C
	lsls r0, 24
	cmp r0, 0
	beq _0809BE20
	ldr r0, _0809BE18
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE1C
	b _0809C266
	.align 2, 0
_0809BE18: .4byte gUnknown_3001B64
_0809BE1C: .4byte gUnknown_8116218
_0809BE20:
	ldr r0, _0809BE2C
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
	.align 2, 0
_0809BE2C: .4byte gUnknown_3001B64
_0809BE30:
	ldr r0, [r6]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BE3C
	b _0809C266
	.align 2, 0
_0809BE3C: .4byte gUnknown_8116228
_0809BE40:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE4C
	b _0809C266
	.align 2, 0
_0809BE4C: .4byte gUnknown_8116238
_0809BE50:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BE5C
	b _0809C266
	.align 2, 0
_0809BE5C: .4byte gUnknown_8116248
_0809BE60:
	bl sub_809B294
	movs r0, 0x98
	lsls r0, 1
	bl sub_80314B4
	lsls r0, 24
	cmp r0, 0
	bne _0809BE84
	ldr r0, _0809BE80
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BE80: .4byte gUnknown_3001B64
_0809BE84:
	ldr r0, _0809BE94
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE98
	b _0809C266
	.align 2, 0
_0809BE94: .4byte gUnknown_3001B64
_0809BE98: .4byte gUnknown_8116258
_0809BE9C:
	movs r0, 0x4
	bl sub_80119D4
	ldr r0, _0809BEB0
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BEB4
	b _0809C266
	.align 2, 0
_0809BEB0: .4byte gUnknown_3001B64
_0809BEB4: .4byte gUnknown_8116268
_0809BEB8:
	movs r0, 0x4
	bl sub_80119D4
	ldr r0, _0809BECC
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BED0
	b _0809C266
	.align 2, 0
_0809BECC: .4byte gUnknown_3001B64
_0809BED0: .4byte gUnknown_8116278
_0809BED4:
	mov r0, sp
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	beq _0809BF4E
	add r1, sp, 0x4
	add r2, sp, 0x8
	movs r0, 0x2
	bl sub_8001B88
	ldr r0, [sp, 0x8]
	cmp r0, 0x7
	bgt _0809BF4E
	add r4, sp, 0xC
_0809BEF2:
	lsls r1, r0, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r2, [r0]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809BF44
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	movs r0, 0x2
	bl sub_8001BB4
	ldr r0, _0809BF40
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r2, r0, r1
	ldrh r1, [r4, 0x2]
	lsls r1, 16
	asrs r1, 16
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0809BF30
	adds r1, 0x2
_0809BF30:
	str r1, [r2]
	cmp r1, 0
	beq _0809BF38
	b _0809C392
_0809BF38:
	movs r0, 0x3
	str r0, [r2]
	b _0809C392
	.align 2, 0
_0809BF40: .4byte gUnknown_3001B64
_0809BF44:
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
	cmp r0, 0x7
	ble _0809BEF2
_0809BF4E:
	ldr r0, _0809BF6C
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	bl sub_8096BD0
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	b _0809C392
	.align 2, 0
_0809BF6C: .4byte gUnknown_3001B64
_0809BF70:
	mov r5, sp
	adds r5, 0x1
	adds r0, r5, 0
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	bne _0809BF82
	b _0809C392
_0809BF82:
	add r1, sp, 0x14
	add r2, sp, 0x18
	movs r0, 0x2
	bl sub_8001B88
	add r4, sp, 0x1C
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r5]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	bne _0809BFA4
	b _0809C392
_0809BFA4:
	ldr r0, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r5]
	bl sub_802DB28
	lsls r0, 24
	cmp r0, 0
	bne _0809BFB8
	b _0809C392
_0809BFB8:
	movs r0, 0
	movs r1, 0x19
	bl sub_8001658
	cmp r0, 0x63
	bgt _0809BFCE
	adds r2, r0, 0x1
	movs r0, 0
	movs r1, 0x19
	bl sub_80018D8
_0809BFCE:
	movs r0, 0
	movs r1, 0x39
	movs r2, 0x1
	bl sub_80018D8
	ldr r1, [sp, 0x14]
	ldr r2, [sp, 0x18]
	adds r2, 0x1
	movs r0, 0x2
	bl sub_8001BB4
	ldr r0, _0809BFF4
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BFF8
	b _0809C266
	.align 2, 0
_0809BFF4: .4byte gUnknown_3001B64
_0809BFF8: .4byte gUnknown_8116288
_0809BFFC:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C036
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	asrs r4, 31
	movs r0, 0x4
	ands r4, r0
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C032
	bl _0809B784
_0809C032:
	ldr r0, [r6]
	b _0809B972
_0809C036:
	bl sub_802FE58
	cmp r0, 0x2
	beq _0809C05E
	cmp r0, 0x3
	beq _0809C046
	bl _0809B784
_0809C046:
	bl sub_802FED0
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	str r0, [r1]
	bl sub_802FEE0
	b _0809C392
_0809C05E:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_802FEE0
	b _0809C392
_0809C072:
	movs r4, 0x1
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C082
	movs r4, 0x5
_0809C082:
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C0A8
	ldr r0, _0809C0A0
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C0A4
	b _0809C266
	.align 2, 0
_0809C0A0: .4byte gUnknown_3001B64
_0809C0A4: .4byte gUnknown_8116298
_0809C0A8:
	ldr r0, _0809C0B4
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
	.align 2, 0
_0809C0B4: .4byte gUnknown_3001B64
_0809C0B8:
	movs r4, 0x2
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C0C8
	movs r4, 0x6
_0809C0C8:
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C0F0
	ldr r0, _0809C0E8
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809C0EC
	b _0809C266
	.align 2, 0
_0809C0E8: .4byte gUnknown_3001B64
_0809C0EC: .4byte gUnknown_81162A8
_0809C0F0:
	ldr r0, _0809C0F8
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809C0F8: .4byte gUnknown_3001B64
_0809C0FC:
	movs r4, 0x3
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C10C
	movs r4, 0x7
_0809C10C:
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C134
	ldr r0, _0809C12C
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C130
	b _0809C266
	.align 2, 0
_0809C12C: .4byte gUnknown_3001B64
_0809C130: .4byte gUnknown_81162B8
_0809C134:
	ldr r0, _0809C144
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C144: .4byte gUnknown_3001B64
_0809C148:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C154
	b _0809C266
	.align 2, 0
_0809C154: .4byte gUnknown_81162C8
_0809C158:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C164
	b _0809C266
	.align 2, 0
_0809C164: .4byte gUnknown_81162D8
_0809C168:
	bl sub_809B294
	bl sub_803B050
	lsls r0, 24
	cmp r0, 0
	beq _0809C1A0
	ldr r4, _0809C194
	ldr r0, [r4]
	ldr r3, _0809C198
	adds r0, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_803B100
	ldr r0, [r4]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C19C
	b _0809C266
	.align 2, 0
_0809C194: .4byte gUnknown_3001B64
_0809C198: .4byte 0x000005a4
_0809C19C: .4byte gUnknown_81162E8
_0809C1A0:
	ldr r0, _0809C1B0
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C1B0: .4byte gUnknown_3001B64
_0809C1B4:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
_0809C1BC:
	movs r1, 0x1
	str r1, [r0]
	b _0809C392
_0809C1C2:
	bl sub_809B294
	b _0809C392
_0809C1C8:
	movs r0, 0x2
	bl sub_80252F0
	lsls r0, 24
	cmp r0, 0
	beq _0809C1EC
	ldr r0, _0809C1E4
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C1E8
	b _0809C266
	.align 2, 0
_0809C1E4: .4byte gUnknown_3001B64
_0809C1E8: .4byte gUnknown_81162F8
_0809C1EC:
	ldr r0, _0809C200
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x2
	negs r1, r1
	str r1, [r0]
	b _0809C392
	.align 2, 0
_0809C200: .4byte gUnknown_3001B64
_0809C204:
	ldr r1, [r6]
	ldr r2, _0809C230
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, 0x85
	lsls r3, 3
	adds r1, r3
	ldr r1, [r1]
	bl sub_809CCDC
	ldr r1, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	movs r0, 0x83
	lsls r0, 3
	adds r1, r0
	ldr r0, _0809C234
	str r0, [r1]
	bl _0809B784
	.align 2, 0
_0809C230: .4byte 0x00000424
_0809C234: .4byte gUnknown_8116308
_0809C238:
	ldr r0, [r6]
	movs r2, 0x85
	lsls r2, 3
	adds r1, r0, r2
	ldr r5, [r1]
	ldr r3, _0809C26C
	adds r0, r3
	ldrb r4, [r0]
	bl sub_809B294
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_801B60C
	lsls r0, 24
	cmp r0, 0
	beq _0809C274
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C270
_0809C266:
	str r1, [r0]
	bl _0809B784
	.align 2, 0
_0809C26C: .4byte 0x00000424
_0809C270: .4byte gUnknown_8116318
_0809C274:
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	bl _0809B978
_0809C280:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C2B8
	bl sub_809B294
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	lsls r0, 24
	cmp r0, 0
	beq _0809C2B2
	bl _0809B784
_0809C2B2:
	ldr r0, [r6]
	bl _0809B972
_0809C2B8:
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x2
	beq _0809C320
	cmp r0, 0x3
	beq _0809C2CA
	bl _0809B784
_0809C2CA:
	bl sub_801A8AC
	adds r5, r0, 0
	ldr r0, _0809C304
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, r1
	ldrb r4, [r0, 0x2]
	adds r0, r4, 0
	bl sub_8091570
	lsls r0, 24
	cmp r0, 0
	beq _0809C30C
	ldr r0, _0809C308
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	bl sub_80911F8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	b _0809C318
	.align 2, 0
_0809C304: .4byte gUnknown_203B460
_0809C308: .4byte gUnknown_202DE58
_0809C30C:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
_0809C314:
	movs r1, 0x1
	negs r1, r1
_0809C318:
	str r1, [r0]
	bl sub_801A928
	b _0809C392
_0809C320:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	b _0809C314
_0809C32A:
	adds r4, r6, 0
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C36C
	bl sub_809B294
	ldr r1, [r4]
	ldr r3, _0809C368
	adds r0, r1, r3
	ldr r0, [r0]
	movs r2, 0x85
	lsls r2, 3
	adds r1, r2
	ldr r1, [r1]
	bl sub_8035444
	lsls r0, 24
	cmp r0, 0
	beq _0809C35C
	bl _0809B784
_0809C35C:
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C368: .4byte 0x00000424
_0809C36C:
	bl sub_8035574
	cmp r0, 0x3
	bls _0809C378
	bl _0809B784
_0809C378:
	cmp r0, 0x2
	bcs _0809C380
	bl _0809B784
_0809C380:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_803565C
_0809C392:
	movs r0, 0
_0809C394:
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809B648

	thumb_func_start sub_809C39C
sub_809C39C:
	push {lr}
	bl sub_801D178
	ldr r1, _0809C3D4
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	str r0, [r1]
	cmp r0, 0x3
	bne _0809C3CC
	bl sub_801D1D4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	bl sub_8098D1C
_0809C3CC:
	bl sub_801D1E0
	pop {r0}
	bx r0
	.align 2, 0
_0809C3D4: .4byte gUnknown_3001B64
	thumb_func_end sub_809C39C

	thumb_func_start sub_809C3D8
sub_809C3D8:
	push {lr}
	bl sub_801D178
	ldr r1, _0809C410
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	str r0, [r1]
	cmp r0, 0x3
	bne _0809C408
	bl sub_801D1D4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	bl sub_8098D1C
_0809C408:
	bl sub_801D1E0
	pop {r0}
	bx r0
	.align 2, 0
_0809C410: .4byte gUnknown_3001B64
	thumb_func_end sub_809C3D8

	thumb_func_start sub_809C414
sub_809C414:
	push {lr}
	bl sub_802540C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0809C448
	ldr r0, _0809C444
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	str r1, [r0]
	adds r0, r1, 0
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	bl sub_8098D1C
	b _0809C458
	.align 2, 0
_0809C444: .4byte gUnknown_3001B64
_0809C448:
	ldr r0, _0809C460
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0809C458:
	bl sub_8025418
	pop {r0}
	bx r0
	.align 2, 0
_0809C460: .4byte gUnknown_3001B64
	thumb_func_end sub_809C414

	thumb_func_start sub_809C464
sub_809C464:
	push {lr}
	bl sub_803C850
	bl sub_8001064
	bl sub_809965C
	pop {r0}
	bx r0
	thumb_func_end sub_809C464

	thumb_func_start sub_809C478
sub_809C478:
	push {lr}
	sub sp, 0x8
	bl sub_80356A0
	cmp r0, 0x3
	bne _0809C492
	ldr r0, _0809C4AC
	bl sub_8011988
	bl InitFlash
	bl ClearFlashData
_0809C492:
	bl sub_8035758
	add r2, sp, 0x4
	movs r0, 0x3
	mov r1, sp
	bl sub_8001B88
	movs r0, 0
	bl sub_80993C0
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_0809C4AC: .4byte 0x00000313
	thumb_func_end sub_809C478

	thumb_func_start sub_809C4B0
sub_809C4B0:
	push {r4,r5,lr}
	movs r4, 0x1
	negs r4, r4
	ldr r5, _0809C4FC
	ldr r0, [r5]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, 0
	bne _0809C4DE
	bl sub_803B168
	lsls r0, 16
	ldr r1, [r5]
	ldr r3, _0809C500
	adds r2, r1, r3
	asrs r4, r0, 16
	lsrs r0, 16
	strh r0, [r2]
	movs r0, 0x86
	lsls r0, 3
	adds r1, r0
_0809C4DE:
	str r4, [r1]
	bl sub_803B1BC
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809C4F4
	adds r0, r4, 0
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809C4F4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C4FC: .4byte gUnknown_3001B64
_0809C500: .4byte 0x000005a4
	thumb_func_end sub_809C4B0

	thumb_func_start sub_809C504
sub_809C504:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80282DC
	adds r4, r0, 0
	cmp r4, 0x1
	bne _0809C530
	mov r0, sp
	ldrb r0, [r0]
	bl sub_809927C
	ldr r0, _0809C52C
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	str r4, [r0]
	b _0809C540
	.align 2, 0
_0809C52C: .4byte gUnknown_3001B64
_0809C530:
	ldr r0, _0809C54C
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0809C540:
	bl sub_80282FC
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C54C: .4byte gUnknown_3001B64
	thumb_func_end sub_809C504

	thumb_func_start sub_809C550
sub_809C550:
	push {r4,r5,lr}
	bl sub_802E90C
	adds r4, r0, 0
	movs r5, 0
	bl sub_802E918
	cmp r4, 0x2
	beq _0809C586
	cmp r4, 0x2
	bhi _0809C56C
	cmp r4, 0x1
	beq _0809C572
	b _0809C5AC
_0809C56C:
	cmp r4, 0x3
	beq _0809C59A
	b _0809C5AC
_0809C572:
	movs r0, 0x4
	movs r1, 0x1D
	movs r2, 0x3
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _0809C5AC
	movs r5, 0x1
	b _0809C5AC
_0809C586:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0x2
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _0809C5AC
	movs r5, 0x2
	b _0809C5AC
_0809C59A:
	movs r0, 0xB
	movs r1, 0x33
	movs r2, 0x8
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _0809C5AC
	movs r5, 0x3
_0809C5AC:
	ldr r0, _0809C5C0
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C5C0: .4byte gUnknown_3001B64
	thumb_func_end sub_809C550

	thumb_func_start sub_809C5C4
sub_809C5C4:
	push {r4,lr}
	ldr r4, _0809C610
	movs r0, 0x24
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	movs r2, 0
	str r2, [r0]
	str r2, [r0, 0x4]
	movs r3, 0
	strh r2, [r0, 0x8]
	strh r2, [r0, 0xA]
	strb r3, [r0, 0xD]
	ldr r0, [r4]
	strb r3, [r0, 0xE]
	ldr r1, [r4]
	str r2, [r1, 0x10]
	ldr r0, _0809C614
	strh r0, [r1, 0x14]
	movs r0, 0x23
	strh r0, [r1, 0x16]
	strb r3, [r1, 0x18]
	ldr r1, [r4]
	movs r0, 0x3F
	strb r0, [r1, 0x19]
	ldr r0, [r4]
	str r2, [r0, 0x1C]
	adds r0, 0x20
	strb r3, [r0]
	bl nullsub_107
	bl sub_809C63C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C610: .4byte gUnknown_3001B68
_0809C614: .4byte 0x0000ffff
	thumb_func_end sub_809C5C4

	thumb_func_start sub_809C618
sub_809C618:
	push {r4,lr}
	bl sub_809C63C
	bl nullsub_107
	bl nullsub_108
	ldr r4, _0809C638
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C638: .4byte gUnknown_3001B68
	thumb_func_end sub_809C618

	thumb_func_start sub_809C63C
sub_809C63C:
	push {lr}
	bl nullsub_108
	ldr r0, _0809C654
	ldr r0, [r0]
	movs r1, 0
	str r1, [r0, 0x1C]
	adds r0, 0x20
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0809C654: .4byte gUnknown_3001B68
	thumb_func_end sub_809C63C

	thumb_func_start sub_809C658
sub_809C658:
	push {lr}
	ldr r0, _0809C670
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r0, 0x5
	bhi _0809C6C8
	lsls r0, 2
	ldr r1, _0809C674
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C670: .4byte gUnknown_3001B68
_0809C674: .4byte _0809C678
	.align 2, 0
_0809C678:
	.4byte _0809C6C0
	.4byte _0809C6C0
	.4byte _0809C6AC
	.4byte _0809C690
	.4byte _0809C69E
	.4byte _0809C6B6
_0809C690:
	bl nullsub_111
	bl nullsub_112
	bl nullsub_113
	b _0809C6C8
_0809C69E:
	bl nullsub_114
	bl nullsub_115
	bl nullsub_116
	b _0809C6C8
_0809C6AC:
	bl nullsub_109
	bl nullsub_110
	b _0809C6C8
_0809C6B6:
	bl nullsub_107
	bl nullsub_108
	b _0809C6C8
_0809C6C0:
	bl nullsub_107
	bl nullsub_108
_0809C6C8:
	pop {r0}
	bx r0
	thumb_func_end sub_809C658

	thumb_func_start sub_809C6CC
sub_809C6CC:
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, _0809C6E8
	ldr r1, [r0]
	ldrh r0, [r1, 0x8]
	cmp r0, r2
	beq _0809C6E2
	movs r0, 0
	strh r2, [r1, 0x8]
	strb r0, [r1, 0xE]
_0809C6E2:
	pop {r0}
	bx r0
	.align 2, 0
_0809C6E8: .4byte gUnknown_3001B68
	thumb_func_end sub_809C6CC

	thumb_func_start sub_809C6EC
sub_809C6EC:
	push {lr}
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _0809C718
	ldr r0, _0809C70C
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	bne _0809C710
	movs r0, 0x4
	bl sub_809C6CC
	b _0809C71E
	.align 2, 0
_0809C70C: .4byte gUnknown_203B46C
_0809C710:
	movs r0, 0x3
	bl sub_809C6CC
	b _0809C71E
_0809C718:
	movs r0, 0x5
	bl sub_809C6CC
_0809C71E:
	pop {r0}
	bx r0
	thumb_func_end sub_809C6EC

	thumb_func_start sub_809C724
sub_809C724:
	ldr r0, _0809C72C
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	bx lr
	.align 2, 0
_0809C72C: .4byte gUnknown_3001B68
	thumb_func_end sub_809C724

	thumb_func_start sub_809C730
sub_809C730:
	push {lr}
	bl sub_809C740
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_809C730

	thumb_func_start sub_809C740
sub_809C740:
	push {lr}
	ldr r0, _0809C750
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _0809C754
	movs r0, 0
	b _0809C756
	.align 2, 0
_0809C750: .4byte gUnknown_3001B68
_0809C754:
	movs r0, 0x1
_0809C756:
	pop {r1}
	bx r1
	thumb_func_end sub_809C740

	thumb_func_start nullsub_104
nullsub_104:
	bx lr
	thumb_func_end nullsub_104

	thumb_func_start sub_809C760
sub_809C760:
	ldr r0, _0809C76C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xE]
	bx lr
	.align 2, 0
_0809C76C: .4byte gUnknown_3001B68
	thumb_func_end sub_809C760

	thumb_func_start sub_809C770
sub_809C770:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r4, _0809C790
	ldr r1, [r4]
	ldrb r0, [r1, 0xE]
	cmp r0, 0
	beq _0809C794
	movs r0, 0
	strb r0, [r1, 0xE]
	b _0809CA10
	.align 2, 0
_0809C790: .4byte gUnknown_3001B68
_0809C794:
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	bne _0809C79E
	bl sub_809C6EC
_0809C79E:
	ldr r0, [r4]
	ldrb r5, [r0, 0x18]
	ldrb r7, [r0, 0x19]
	cmp r6, 0x26
	bls _0809C7AA
	b _0809C8C8
_0809C7AA:
	lsls r0, r6, 2
	ldr r1, _0809C7B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C7B4: .4byte _0809C7B8
	.align 2, 0
_0809C7B8:
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C854
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C86E
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
_0809C854:
	mov r0, r8
	bl sub_8002658
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0809C864
	b _0809CA10
_0809C864:
	movs r4, 0x1
	b _0809C988
_0809C868:
	movs r4, 0x1
	movs r5, 0
	b _0809C988
_0809C86E:
	mov r0, r8
	subs r0, 0xA4
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bls _0809C87C
	b _0809CA10
_0809C87C:
	lsls r0, 2
	ldr r1, _0809C888
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C888: .4byte _0809C88C
	.align 2, 0
_0809C88C:
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
_0809C8C4:
	movs r4, 0
	b _0809C988
_0809C8C8:
	adds r0, r6, 0
	subs r0, 0xC
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x16
	bhi _0809C968
	lsls r0, 2
	ldr r1, _0809C8E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C8E0: .4byte _0809C8E4
	.align 2, 0
_0809C8E4:
	.4byte _0809C968
	.4byte _0809C940
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C944
	.4byte _0809C944
	.4byte _0809C948
	.4byte _0809C948
	.4byte _0809C94C
	.4byte _0809C968
	.4byte _0809C950
	.4byte _0809C950
	.4byte _0809C954
	.4byte _0809C954
	.4byte _0809C958
	.4byte _0809C958
	.4byte _0809C95C
	.4byte _0809C95C
	.4byte _0809C960
	.4byte _0809C960
	.4byte _0809C964
_0809C940:
	movs r1, 0
	b _0809C974
_0809C944:
	movs r1, 0x7
	b _0809C974
_0809C948:
	movs r1, 0x9
	b _0809C974
_0809C94C:
	movs r1, 0xA
	b _0809C974
_0809C950:
	movs r1, 0xB
	b _0809C974
_0809C954:
	movs r1, 0xD
	b _0809C974
_0809C958:
	movs r1, 0xF
	b _0809C974
_0809C95C:
	movs r1, 0x11
	b _0809C974
_0809C960:
	movs r1, 0x13
	b _0809C974
_0809C964:
	movs r1, 0x20
	b _0809C974
_0809C968:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r1, r0, 16
_0809C974:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809CA10
	adds r0, r1, 0
	bl sub_80A2740
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0x2
_0809C988:
	ldr r0, _0809C99C
	ldr r2, [r0]
	ldr r1, [r2, 0x10]
	adds r3, r0, 0
	cmp r1, r4
	beq _0809C9A0
	movs r0, 0x2
	str r0, [r2]
	b _0809C9DE
	.align 2, 0
_0809C99C: .4byte gUnknown_3001B68
_0809C9A0:
	cmp r4, 0x1
	bne _0809C9CC
	ldrb r0, [r2, 0x18]
	cmp r5, r0
	bne _0809C9B2
	movs r1, 0x14
	ldrsh r0, [r2, r1]
	cmp r0, r8
	beq _0809C9BC
_0809C9B2:
	strb r4, [r2, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r4, [r0]
	b _0809C9E8
_0809C9BC:
	cmp r5, 0
	bne _0809C9E8
	movs r1, 0x16
	ldrsh r0, [r2, r1]
	cmp r0, r6
	beq _0809C9E8
	strb r4, [r2, 0xC]
	b _0809C9E8
_0809C9CC:
	cmp r4, 0x2
	bne _0809C9E8
	ldrb r0, [r2, 0x19]
	cmp r7, r0
	bne _0809C9DE
	movs r1, 0x16
	ldrsh r0, [r2, r1]
	cmp r0, r6
	beq _0809C9E8
_0809C9DE:
	movs r1, 0x1
	strb r1, [r2, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r1, [r0]
_0809C9E8:
	ldr r1, [r3]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0809CA10
	str r4, [r1, 0x10]
	movs r2, 0
	mov r0, r8
	strh r0, [r1, 0x14]
	strh r6, [r1, 0x16]
	strb r5, [r1, 0x18]
	ldr r0, [r3]
	strb r7, [r0, 0x19]
	ldr r1, [r3]
	ldrh r0, [r1, 0x8]
	cmp r0, 0x4
	beq _0809CA10
	strb r2, [r1, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r2, [r0]
_0809CA10:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809C770

	thumb_func_start nullsub_105
nullsub_105:
	bx lr
	thumb_func_end nullsub_105

	thumb_func_start sub_809CA20
sub_809CA20:
	push {lr}
	ldr r1, _0809CA74
	ldr r2, [r1]
	ldr r0, [r2]
	cmp r0, 0
	beq _0809CA38
	movs r0, 0
	str r0, [r2]
	movs r0, 0x1F
	str r0, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0xC]
_0809CA38:
	ldr r1, [r1]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0809CAE8
	ldrh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bne _0809CA5E
	ldr r2, [r1, 0x10]
	cmp r2, 0
	bne _0809CA5E
	movs r0, 0x2
	strh r0, [r1, 0xA]
	str r2, [r1, 0x1C]
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
_0809CA5E:
	ldr r0, _0809CA74
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r0, 0x5
	bhi _0809CADA
	lsls r0, 2
	ldr r1, _0809CA78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CA74: .4byte gUnknown_3001B68
_0809CA78: .4byte _0809CA7C
	.align 2, 0
_0809CA7C:
	.4byte _0809CAD2
	.4byte _0809CAD2
	.4byte _0809CABE
	.4byte _0809CA94
	.4byte _0809CAB0
	.4byte _0809CAC8
_0809CA94:
	bl nullsub_111
	bl nullsub_113
	bl nullsub_112
	ldr r0, _0809CAAC
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	b _0809CADA
	.align 2, 0
_0809CAAC: .4byte gUnknown_3001B68
_0809CAB0:
	bl nullsub_114
	bl nullsub_115
	bl nullsub_116
	b _0809CADA
_0809CABE:
	bl nullsub_109
	bl nullsub_110
	b _0809CADA
_0809CAC8:
	bl nullsub_107
	bl nullsub_108
	b _0809CADA
_0809CAD2:
	bl nullsub_107
	bl nullsub_108
_0809CADA:
	ldr r0, _0809CAE4
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0xC]
	b _0809CB1E
	.align 2, 0
_0809CAE4: .4byte gUnknown_3001B68
_0809CAE8:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x5
	bhi _0809CB1E
	lsls r0, 2
	ldr r1, _0809CAF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CAF8: .4byte _0809CAFC
	.align 2, 0
_0809CAFC:
	.4byte _0809CB1E
	.4byte _0809CB1E
	.4byte _0809CB1E
	.4byte _0809CB14
	.4byte _0809CB1A
	.4byte _0809CB1E
_0809CB14:
	bl nullsub_113
	b _0809CB1E
_0809CB1A:
	bl nullsub_116
_0809CB1E:
	pop {r0}
	bx r0
	thumb_func_end sub_809CA20

	thumb_func_start nullsub_106
nullsub_106:
	bx lr
	thumb_func_end nullsub_106

	thumb_func_start nullsub_107
nullsub_107:
	bx lr
	thumb_func_end nullsub_107

	thumb_func_start nullsub_108
nullsub_108:
	bx lr
	thumb_func_end nullsub_108

	thumb_func_start nullsub_109
nullsub_109:
	bx lr
	thumb_func_end nullsub_109

	thumb_func_start nullsub_110
nullsub_110:
	bx lr
	thumb_func_end nullsub_110

	thumb_func_start nullsub_111
nullsub_111:
	bx lr
	thumb_func_end nullsub_111

	thumb_func_start nullsub_112
nullsub_112:
	bx lr
	thumb_func_end nullsub_112

	thumb_func_start nullsub_113
nullsub_113:
	bx lr
	thumb_func_end nullsub_113

	thumb_func_start nullsub_114
nullsub_114:
	bx lr
	thumb_func_end nullsub_114

	thumb_func_start nullsub_115
nullsub_115:
	bx lr
	thumb_func_end nullsub_115

	thumb_func_start nullsub_116
nullsub_116:
	bx lr
	thumb_func_end nullsub_116

	thumb_func_start sub_809CB50
sub_809CB50:
	push {r4,lr}
	ldr r4, _0809CB70
	movs r0, 0xC
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x4]
	movs r1, 0
	str r1, [r0, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809CB70: .4byte gUnknown_20399E0
	thumb_func_end sub_809CB50

	thumb_func_start sub_809CB74
sub_809CB74:
	push {r4,lr}
	ldr r4, _0809CB88
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809CB88: .4byte gUnknown_20399E0
	thumb_func_end sub_809CB74

	thumb_func_start sub_809CB8C
sub_809CB8C:
	push {lr}
	movs r0, 0
	movs r1, 0x3B
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x3D
	bl sub_80015C0
	pop {r0}
	bx r0
	thumb_func_end sub_809CB8C

	thumb_func_start sub_809CBA4
sub_809CBA4:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091130
	cmp r0, 0
	bge _0809CBB6
	movs r0, 0
	b _0809CBB8
_0809CBB6:
	movs r0, 0x1
_0809CBB8:
	pop {r1}
	bx r1
	thumb_func_end sub_809CBA4

	thumb_func_start sub_809CBBC
sub_809CBBC:
	push {r4-r7,lr}
	sub sp, 0x54
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	ldrb r1, [r4]
	cmp r1, 0x69
	bne _0809CC20
	ldr r1, _0809CC0C
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r0, _0809CC10
	ldr r0, [r0]
	movs r3, 0xD2
	lsls r3, 4
	adds r0, r3
	ldr r3, [r0]
	mov r0, sp
	bl sub_800D158
	ldr r0, _0809CC14
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r2, r0, r1
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, _0809CC18
	cmp r1, r0
	ble _0809CC1C
	cmp r6, 0
	beq _0809CC4E
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r6, 0
	b _0809CC4A
	.align 2, 0
_0809CC0C: .4byte gUnknown_81163E4
_0809CC10: .4byte gItemParametersFile + 4
_0809CC14: .4byte gUnknown_203B460
_0809CC18: .4byte 0x0001869f
_0809CC1C:
	str r1, [r2]
	b _0809CC5E
_0809CC20:
	ldrb r0, [r4, 0x2]
	lsls r1, 16
	lsls r0, 8
	orrs r0, r1
	str r0, [sp, 0x50]
	add r4, sp, 0x50
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	bl sub_8090A34
	cmp r0, 0x13
	ble _0809CC52
	cmp r5, 0
	beq _0809CC4E
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r5, 0
_0809CC4A:
	bl sub_809AE90
_0809CC4E:
	movs r0, 0
	b _0809CC82
_0809CC52:
	ldrb r0, [r4, 0x2]
	movs r1, 0
	bl sub_809124C
	bl sub_80910B4
_0809CC5E:
	cmp r7, 0
	beq _0809CC80
	ldr r0, _0809CC8C
	mov r1, sp
	bl strcpy
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r7, 0
	bl sub_809AE90
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCB
	bl sub_8011974
_0809CC80:
	movs r0, 0x1
_0809CC82:
	add sp, 0x54
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809CC8C: .4byte gUnknown_202DE58
	thumb_func_end sub_809CBBC

	thumb_func_start sub_809CC90
sub_809CC90:
	push {lr}
	lsls r0, 2
	ldr r1, _0809CCBC
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x69
	bne _0809CCC8
	ldr r0, _0809CCC0
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	ldr r0, [r0]
	adds r0, r1
	ldr r1, _0809CCC4
	cmp r0, r1
	ble _0809CCD4
	movs r0, 0x2
	b _0809CCD6
	.align 2, 0
_0809CCBC: .4byte gUnknown_81163BC
_0809CCC0: .4byte gUnknown_203B460
_0809CCC4: .4byte 0x0001869f
_0809CCC8:
	bl sub_8090A34
	cmp r0, 0x13
	ble _0809CCD4
	movs r0, 0x2
	b _0809CCD6
_0809CCD4:
	movs r0, 0x1
_0809CCD6:
	pop {r1}
	bx r1
	thumb_func_end sub_809CC90

	thumb_func_start sub_809CCDC
sub_809CCDC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r1, r6, 2
	ldr r0, _0809CD20
	adds r5, r1, r0
	ldr r0, _0809CD24
	ldr r1, [r0]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x4]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r0, 0x2
	cmp r4, 0x63
	bgt _0809CD04
	movs r0, 0
	cmp r4, 0x1
	ble _0809CD04
	movs r0, 0x1
_0809CD04:
	ldr r1, _0809CD28
	ldr r2, _0809CD2C
	ldr r3, _0809CD30
	lsls r0, 2
	adds r0, r3
	ldr r3, [r0]
	adds r0, r5, 0
	bl sub_809CBBC
	lsls r0, 24
	cmp r0, 0
	bne _0809CD34
	movs r0, 0x2
	b _0809CD3E
	.align 2, 0
_0809CD20: .4byte gUnknown_81163BC
_0809CD24: .4byte gUnknown_20399E0
_0809CD28: .4byte gUnknown_81163F0
_0809CD2C: .4byte gUnknown_811642C
_0809CD30: .4byte gUnknown_203B4A0
_0809CD34:
	ldr r0, _0809CD44
	ldr r0, [r0]
	str r6, [r0, 0x4]
	str r4, [r0, 0x8]
	movs r0, 0x1
_0809CD3E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809CD44: .4byte gUnknown_20399E0
	thumb_func_end sub_809CCDC

	thumb_func_start sub_809CD48
sub_809CD48:
	push {lr}
	bl sub_809A750
	lsls r0, 24
	cmp r0, 0
	bne _0809CD58
	movs r0, 0x3
	b _0809CD5A
_0809CD58:
	movs r0, 0
_0809CD5A:
	pop {r1}
	bx r1
	thumb_func_end sub_809CD48

	thumb_func_start nullsub_117
nullsub_117:
	bx lr
	thumb_func_end nullsub_117

	thumb_func_start nullsub_118
nullsub_118:
	bx lr
	thumb_func_end nullsub_118

	thumb_func_start sub_809CD68
sub_809CD68:
	movs r2, 0
	str r2, [r0]
	str r2, [r0, 0x4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	str r2, [r0, 0x14]
	str r2, [r0, 0x8]
	strb r2, [r0, 0x18]
	bx lr
	thumb_func_end sub_809CD68

	thumb_func_start sub_809CD7C
sub_809CD7C:
	movs r2, 0
	str r2, [r0]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	str r2, [r0, 0x14]
	str r2, [r0, 0x8]
	bx lr
	thumb_func_end sub_809CD7C

	thumb_func_start sub_809CD8C
sub_809CD8C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0x5
	bne _0809CD9E
	bl sub_809CD68
	str r4, [r5]
	b _0809CDB0
_0809CD9E:
	ldr r0, [r5, 0x4]
	cmp r0, r4
	beq _0809CDB0
	str r4, [r5, 0x4]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x10]
	movs r0, 0
	str r0, [r5, 0x14]
_0809CDB0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809CD8C

	thumb_func_start sub_809CDB8
sub_809CDB8:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _0809CDC4
	ldr r0, [r1]
_0809CDC4:
	pop {r1}
	bx r1
	thumb_func_end sub_809CDB8

	thumb_func_start sub_809CDC8
sub_809CDC8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r1, [sp, 0x24]
	movs r0, 0x1
	negs r0, r0
	str r0, [r3]
	ldr r0, [r4]
	cmp r0, 0x1
	beq _0809CDEA
	cmp r0, 0x2
	beq _0809CDFE
	b _0809CE12
_0809CDEA:
	movs r0, 0x80
	lsls r0, 6
	ands r1, r0
	cmp r1, 0
	beq _0809CE12
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x2
	b _0809CE10
_0809CDFE:
	movs r0, 0x80
	lsls r0, 6
	ands r1, r0
	cmp r1, 0
	bne _0809CE12
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x1
_0809CE10:
	str r0, [r4]
_0809CE12:
	ldr r0, [r4, 0x4]
	mov r8, r0
	cmp r0, 0
	bne _0809CE1E
	ldr r1, [r4]
	mov r8, r1
_0809CE1E:
	mov r0, r8
	subs r0, 0x1
	cmp r0, 0x6
	bls _0809CE28
	b _0809CFCC
_0809CE28:
	lsls r0, 2
	ldr r1, _0809CE34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CE34: .4byte _0809CE38
	.align 2, 0
_0809CE38:
	.4byte _0809CE54
	.4byte _0809CF74
	.4byte _0809CFCC
	.4byte _0809CFCC
	.4byte _0809CECC
	.4byte _0809CF5C
	.4byte _0809CF5C
_0809CE54:
	ldr r0, _0809CE70
	ldrh r2, [r0]
	ldrh r1, [r0, 0x2]
	movs r0, 0xF0
	ands r0, r2
	cmp r0, 0
	beq _0809CE74
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0809CEA4
	movs r0, 0
	b _0809CEA8
	.align 2, 0
_0809CE70: .4byte gUnknown_20255F0
_0809CE74:
	movs r3, 0x2
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _0809CE82
	movs r0, 0x14
	b _0809CEA8
_0809CE82:
	ldr r0, [r4, 0x10]
	cmp r0, 0x1
	ble _0809CEA4
	subs r0, 0x1
	str r0, [r4, 0x10]
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	bne _0809CEAA
	movs r0, 0x13
	str r0, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strb r0, [r7]
	movs r0, 0x5
	b _0809CFDA
_0809CEA4:
	movs r0, 0x1
	negs r0, r0
_0809CEA8:
	str r0, [r4, 0x10]
_0809CEAA:
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0809CEB6
	movs r0, 0xA
	b _0809CEC2
_0809CEB6:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _0809CEC0
	movs r0, 0x8
	b _0809CEC2
_0809CEC0:
	movs r0, 0x7
_0809CEC2:
	str r0, [r6]
	adds r0, r2, 0
	bl sub_809CFE8
	b _0809CF4E
_0809CECC:
	mov r0, sp
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	beq _0809CFCC
	ldr r0, _0809CEEC
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	bne _0809CEF0
	movs r0, 0x4
	bl sub_809C6CC
	b _0809CEF6
	.align 2, 0
_0809CEEC: .4byte gUnknown_203B46C
_0809CEF0:
	movs r0, 0x3
	bl sub_809C6CC
_0809CEF6:
	bl nullsub_104
	adds r0, r4, 0
	bl sub_809CD7C
	movs r5, 0x1
	str r5, [r4]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0809CF1E
	cmp r0, 0x2
	bgt _0809CF14
	cmp r0, 0x1
	beq _0809CF2A
	b _0809CF54
_0809CF14:
	cmp r0, 0x3
	beq _0809CF2A
	cmp r0, 0x4
	beq _0809CF3C
	b _0809CF54
_0809CF1E:
	movs r0, 0x4
	str r0, [r4]
	movs r0, 0x1E
	bl sub_8098D80
	b _0809CF46
_0809CF2A:
	movs r0, 0x4
	str r0, [r4]
	str r5, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strb r0, [r7]
	movs r0, 0x4
	b _0809CFDA
_0809CF3C:
	str r0, [r4]
	movs r0, 0x45
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809CF46:
	str r5, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CF4E:
	strb r0, [r7]
	ldr r0, [r4]
	b _0809CFDA
_0809CF54:
	movs r0, 0x2
	bl sub_809D9B8
	b _0809CFCC
_0809CF5C:
	add r0, sp, 0x4
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	beq _0809CFCC
	adds r0, r4, 0
	bl sub_809CD7C
	movs r0, 0x1
	str r0, [r4]
	b _0809CFDA
_0809CF74:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	ble _0809CF86
	subs r0, 0x1
	str r0, [r4, 0x8]
	movs r0, 0x9
	str r0, [r6]
	ldrb r0, [r4, 0xC]
	b _0809CFD6
_0809CF86:
	ldr r0, _0809CFA0
	ldrh r1, [r0]
	movs r0, 0x9
	str r0, [r6]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _0809CFA4
	movs r0, 0x4
	b _0809CFB6
	.align 2, 0
_0809CFA0: .4byte gUnknown_20255F0
_0809CFA4:
	movs r0, 0x80
	ands r1, r0
	cmp r1, 0
	beq _0809CFB0
	strb r2, [r7]
	b _0809CFB8
_0809CFB0:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CFB6:
	strb r0, [r7]
_0809CFB8:
	ldrb r0, [r7]
	strb r0, [r4, 0xC]
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	cmp r0, r1
	beq _0809CFD8
	movs r0, 0x20
	str r0, [r4, 0x8]
	b _0809CFD8
_0809CFCC:
	movs r0, 0
	str r0, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CFD6:
	strb r0, [r7]
_0809CFD8:
	mov r0, r8
_0809CFDA:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809CDC8

	thumb_func_start sub_809CFE8
sub_809CFE8:
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0809D014
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0809D004
	movs r0, 0x3
	b _0809D052
_0809D004:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0809D010
	movs r0, 0x5
	b _0809D052
_0809D010:
	movs r0, 0x4
	b _0809D052
_0809D014:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809D038
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0809D028
	movs r0, 0x1
	b _0809D052
_0809D028:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0809D034
	movs r0, 0x7
	b _0809D052
_0809D034:
	movs r0, 0
	b _0809D052
_0809D038:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0809D044
	movs r0, 0x2
	b _0809D052
_0809D044:
	movs r0, 0x20
	ands r2, r0
	cmp r2, 0
	bne _0809D050
	subs r0, 0x21
	b _0809D052
_0809D050:
	movs r0, 0x6
_0809D052:
	pop {r1}
	bx r1
	thumb_func_end sub_809CFE8

	thumb_func_start sub_809D058
sub_809D058:
	push {lr}
	ldr r1, [r0, 0x4]
	cmp r1, 0x3F
	bgt _0809D076
	ldr r0, [r0]
	cmp r0, 0x67
	bgt _0809D06A
	movs r0, 0x5
	b _0809D0A6
_0809D06A:
	cmp r0, 0x88
	ble _0809D072
	movs r0, 0x3
	b _0809D0A6
_0809D072:
	movs r0, 0x4
	b _0809D0A6
_0809D076:
	cmp r1, 0x60
	ble _0809D090
	ldr r0, [r0]
	cmp r0, 0x67
	bgt _0809D084
	movs r0, 0x7
	b _0809D0A6
_0809D084:
	cmp r0, 0x88
	ble _0809D08C
	movs r0, 0x1
	b _0809D0A6
_0809D08C:
	movs r0, 0
	b _0809D0A6
_0809D090:
	ldr r0, [r0]
	cmp r0, 0x67
	bgt _0809D09A
	movs r0, 0x6
	b _0809D0A6
_0809D09A:
	cmp r0, 0x88
	bgt _0809D0A4
	movs r0, 0x1
	negs r0, r0
	b _0809D0A6
_0809D0A4:
	movs r0, 0x2
_0809D0A6:
	pop {r1}
	bx r1
	thumb_func_end sub_809D058

	thumb_func_start sub_809D0AC
sub_809D0AC:
	push {lr}
	bl sub_809D0BC
	pop {r0}
	bx r0
	thumb_func_end sub_809D0AC

	thumb_func_start nullsub_119
nullsub_119:
	bx lr
	thumb_func_end nullsub_119

	thumb_func_start sub_809D0BC
sub_809D0BC:
	push {r4,r5,lr}
	ldr r5, _0809D0F8
	ldr r1, _0809D0FC
	ldr r2, [r1]
	ldr r3, [r1, 0x4]
	str r2, [r5, 0x3C]
	str r3, [r5, 0x40]
	adds r0, r5, 0
	adds r0, 0x44
	movs r4, 0
	strb r4, [r0]
	movs r0, 0
	bl sub_809D158
	str r4, [r5, 0x8]
	str r4, [r5, 0xC]
	str r4, [r5, 0x10]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x4]
	str r4, [r5, 0x24]
	str r4, [r5, 0x28]
	str r4, [r5, 0x2C]
	str r4, [r5, 0x30]
	str r4, [r5, 0x34]
	str r4, [r5, 0x38]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809D0F8: .4byte gUnknown_20399E8
_0809D0FC: .4byte gUnknown_8116478
	thumb_func_end sub_809D0BC

	thumb_func_start sub_809D100
sub_809D100:
	push {lr}
	adds r2, r0, 0
	ldr r1, _0809D120
	ldr r0, [r1, 0x24]
	cmp r0, r2
	beq _0809D11A
	str r2, [r1, 0x24]
	movs r0, 0
	str r0, [r1, 0x28]
	str r0, [r1, 0x2C]
	str r0, [r1, 0x30]
	str r0, [r1, 0x34]
	str r0, [r1, 0x38]
_0809D11A:
	pop {r0}
	bx r0
	.align 2, 0
_0809D120: .4byte gUnknown_20399E8
	thumb_func_end sub_809D100

	thumb_func_start sub_809D124
sub_809D124:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, _0809D144
	ldr r0, [r3, 0x24]
	cmp r0, r4
	beq _0809D13A
	str r4, [r3, 0x24]
	movs r0, 0
	str r0, [r3, 0x30]
	str r0, [r3, 0x34]
	str r0, [r3, 0x38]
_0809D13A:
	str r1, [r3, 0x28]
	str r2, [r3, 0x2C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D144: .4byte gUnknown_20399E8
	thumb_func_end sub_809D124

	thumb_func_start sub_809D148
sub_809D148:
	ldr r1, _0809D154
	str r0, [r1]
	movs r0, 0
	str r0, [r1, 0x8]
	bx lr
	.align 2, 0
_0809D154: .4byte gUnknown_20399E8
	thumb_func_end sub_809D148

	thumb_func_start sub_809D158
sub_809D158:
	ldr r2, _0809D16C
	str r0, [r2]
	movs r0, 0
	str r0, [r2, 0x8]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r2, 0x1C]
	str r1, [r2, 0x20]
	bx lr
	.align 2, 0
_0809D16C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D158

	thumb_func_start sub_809D170
sub_809D170:
	ldr r2, _0809D17C
	str r0, [r2]
	movs r0, 0
	str r0, [r2, 0x8]
	str r1, [r2, 0x4]
	bx lr
	.align 2, 0
_0809D17C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D170

	thumb_func_start sub_809D180
sub_809D180:
	ldr r2, _0809D18C
	str r0, [r2]
	movs r0, 0x1
	str r0, [r2, 0x8]
	str r1, [r2, 0xC]
	bx lr
	.align 2, 0
_0809D18C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D180

	thumb_func_start sub_809D190
sub_809D190:
	ldr r3, _0809D1A4
	str r0, [r3]
	movs r0, 0x1
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r3, 0x14]
	str r1, [r3, 0x18]
	bx lr
	.align 2, 0
_0809D1A4: .4byte gUnknown_20399E8
	thumb_func_end sub_809D190

	thumb_func_start sub_809D1A8
sub_809D1A8:
	ldr r3, _0809D1B8
	str r0, [r3]
	movs r0, 0x1
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	str r1, [r3, 0x4]
	bx lr
	.align 2, 0
_0809D1B8: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1A8

	thumb_func_start sub_809D1BC
sub_809D1BC:
	ldr r2, _0809D1C8
	str r0, [r2]
	movs r0, 0x2
	str r0, [r2, 0x8]
	str r1, [r2, 0x10]
	bx lr
	.align 2, 0
_0809D1C8: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1BC

	thumb_func_start sub_809D1CC
sub_809D1CC:
	ldr r3, _0809D1E0
	str r0, [r3]
	movs r0, 0x2
	str r0, [r3, 0x8]
	str r2, [r3, 0x10]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r3, 0x14]
	str r1, [r3, 0x18]
	bx lr
	.align 2, 0
_0809D1E0: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1CC

	thumb_func_start sub_809D1E4
sub_809D1E4:
	ldr r3, _0809D1F4
	str r0, [r3]
	movs r0, 0x2
	str r0, [r3, 0x8]
	str r2, [r3, 0x10]
	str r1, [r3, 0x4]
	bx lr
	.align 2, 0
_0809D1F4: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1E4

	thumb_func_start sub_809D1F8
sub_809D1F8:
	ldr r2, _0809D204
	str r0, [r2]
	movs r0, 0x3
	str r0, [r2, 0x8]
	str r1, [r2, 0xC]
	bx lr
	.align 2, 0
_0809D204: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1F8

	thumb_func_start sub_809D208
sub_809D208:
	ldr r3, _0809D21C
	str r0, [r3]
	movs r0, 0x3
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r3, 0x14]
	str r1, [r3, 0x18]
	bx lr
	.align 2, 0
_0809D21C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D208

	thumb_func_start sub_809D220
sub_809D220:
	ldr r3, _0809D230
	str r0, [r3]
	movs r0, 0x3
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	str r1, [r3, 0x4]
	bx lr
	.align 2, 0
_0809D230: .4byte gUnknown_20399E8
	thumb_func_end sub_809D220

	thumb_func_start sub_809D234
sub_809D234:
	push {lr}
	ldr r0, _0809D244
	ldr r0, [r0, 0x8]
	cmp r0, 0
	beq _0809D240
	movs r0, 0x1
_0809D240:
	pop {r1}
	bx r1
	.align 2, 0
_0809D244: .4byte gUnknown_20399E8
	thumb_func_end sub_809D234

	thumb_func_start sub_809D248
sub_809D248:
	ldr r3, _0809D258
	ldr r1, [r3, 0x3C]
	ldr r2, [r3, 0x40]
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r3, 0x44
	ldrb r0, [r3]
	bx lr
	.align 2, 0
_0809D258: .4byte gUnknown_20399E8
	thumb_func_end sub_809D248

	thumb_func_start sub_809D25C
sub_809D25C:
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r4, _0809D274
	ldr r0, [r4]
	cmp r0, 0x2
	beq _0809D28C
	cmp r0, 0x2
	bhi _0809D278
	cmp r0, 0x1
	beq _0809D27E
	b _0809D2B2
	.align 2, 0
_0809D274: .4byte gUnknown_20399E8
_0809D278:
	cmp r0, 0x3
	beq _0809D29A
	b _0809D2B2
_0809D27E:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80A8FD8
	b _0809D2A6
_0809D28C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80AC448
	b _0809D2A6
_0809D29A:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80AD360
_0809D2A6:
	lsls r0, 16
	ldr r1, _0809D2C4
	cmp r0, r1
	bne _0809D2B2
	movs r0, 0
	str r0, [r4]
_0809D2B2:
	ldr r4, _0809D2C8
	ldr r0, [r4, 0x8]
	cmp r0, 0x2
	beq _0809D356
	cmp r0, 0x2
	bhi _0809D2CC
	cmp r0, 0x1
	beq _0809D2D2
	b _0809D388
	.align 2, 0
_0809D2C4: .4byte 0xffff0000
_0809D2C8: .4byte gUnknown_20399E8
_0809D2CC:
	cmp r0, 0x3
	beq _0809D314
	b _0809D388
_0809D2D2:
	ldr r0, [r4, 0x1C]
	ldr r1, [r4, 0x14]
	subs r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	subs r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r4, 0xC]
	add r0, sp, 0x4
	bl sub_800290C
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _0809D2FA
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _0809D2FA
	str r0, [r4, 0x8]
	b _0809D392
_0809D2FA:
	ldr r2, _0809D310
	ldr r0, [r2, 0x14]
	ldr r1, [sp, 0x4]
	adds r0, r1
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x18]
	ldr r1, [sp, 0x8]
	adds r0, r1
	str r0, [r2, 0x18]
	b _0809D392
	.align 2, 0
_0809D310: .4byte gUnknown_20399E8
_0809D314:
	ldr r1, [r4, 0x1C]
	ldr r0, [r4, 0x14]
	subs r0, r1, r0
	cmp r0, 0
	bge _0809D320
	adds r0, 0xFF
_0809D320:
	asrs r2, r0, 8
	ldr r1, [r4, 0x20]
	ldr r0, [r4, 0x18]
	subs r1, r0
	cmp r1, 0
	bge _0809D32E
	adds r1, 0xFF
_0809D32E:
	asrs r1, 8
	lsls r0, r2, 8
	lsls r1, 8
	bl sub_8009FB8
	cmp r0, 0
	bge _0809D33E
	adds r0, 0xFF
_0809D33E:
	asrs r0, 8
	lsls r0, 8
	ldr r1, [r4, 0xC]
	bl __divsi3
	str r0, [r4, 0x10]
	cmp r0, 0
	bgt _0809D352
	movs r0, 0x1
	str r0, [r4, 0x10]
_0809D352:
	movs r0, 0x2
	str r0, [r4, 0x8]
_0809D356:
	add r0, sp, 0xC
	ldr r1, _0809D384
	adds r2, r1, 0
	adds r2, 0x8
	adds r5, r1, 0
	subs r5, 0x14
	ldr r3, [r5, 0x10]
	movs r4, 0x1
	str r4, [sp]
	bl sub_8002934
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	str r0, [r5, 0x14]
	str r1, [r5, 0x18]
	ldr r0, [r5, 0x10]
	subs r0, 0x1
	str r0, [r5, 0x10]
	cmp r0, 0
	bgt _0809D392
	movs r0, 0
	str r0, [r5, 0x8]
	b _0809D392
	.align 2, 0
_0809D384: .4byte gUnknown_20399FC
_0809D388:
	ldr r2, _0809D3A4
	ldr r0, [r2, 0x1C]
	ldr r1, [r2, 0x20]
	str r0, [r2, 0x14]
	str r1, [r2, 0x18]
_0809D392:
	ldr r5, _0809D3A4
	ldr r0, [r5, 0x24]
	cmp r0, 0x1
	beq _0809D3A8
	cmp r0, 0x2
	beq _0809D3D2
	movs r0, 0
	str r0, [r5, 0x34]
	b _0809D402
	.align 2, 0
_0809D3A4: .4byte gUnknown_20399E8
_0809D3A8:
	ldr r0, [r5, 0x30]
	subs r0, 0x1
	str r0, [r5, 0x30]
	cmp r0, 0
	bgt _0809D404
	movs r0, 0x4
	str r0, [r5, 0x30]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	lsls r0, 10
	str r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	lsls r0, 10
	b _0809D402
_0809D3D2:
	ldr r0, [r5, 0x30]
	subs r0, 0x1
	str r0, [r5, 0x30]
	cmp r0, 0
	bgt _0809D404
	ldr r0, [r5, 0x2C]
	str r0, [r5, 0x30]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	ldr r1, [r5, 0x28]
	muls r0, r1
	lsls r0, 8
	str r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	ldr r1, [r5, 0x28]
	muls r0, r1
	lsls r0, 8
_0809D402:
	str r0, [r5, 0x38]
_0809D404:
	add r5, sp, 0x14
	add r6, sp, 0x1C
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80A579C
	lsls r0, 24
	cmp r0, 0
	beq _0809D474
	ldr r4, _0809D47C
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x34]
	adds r0, r1
	adds r2, r0, 0
	subs r2, 0x80
	ldr r0, [r4, 0x18]
	ldr r1, [r4, 0x38]
	adds r0, r1
	ldr r1, _0809D480
	adds r3, r0, r1
	ldr r0, [sp, 0x14]
	cmp r2, r0
	bge _0809D434
	adds r2, r0, 0
_0809D434:
	ldr r0, [sp, 0x1C]
	cmp r2, r0
	blt _0809D43C
	subs r2, r0, 0x1
_0809D43C:
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _0809D444
	adds r3, r0, 0
_0809D444:
	ldr r1, [r6, 0x4]
	cmp r3, r1
	blt _0809D44C
	subs r3, r1, 0x1
_0809D44C:
	ldr r1, _0809D484
	adds r0, r2, r1
	cmp r0, 0
	bge _0809D458
	adds r1, 0xFF
	adds r0, r2, r1
_0809D458:
	asrs r0, 8
	str r0, [r4, 0x3C]
	ldr r1, _0809D488
	adds r0, r3, r1
	cmp r0, 0
	bge _0809D468
	adds r1, 0xFF
	adds r0, r3, r1
_0809D468:
	asrs r0, 8
	str r0, [r4, 0x40]
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x1
	strb r0, [r1]
_0809D474:
	add sp, 0x24
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D47C: .4byte gUnknown_20399E8
_0809D480: .4byte 0xfffff480
_0809D484: .4byte 0xffff8700
_0809D488: .4byte 0xffffb000
	thumb_func_end sub_809D25C

	thumb_func_start nullsub_120
nullsub_120:
	bx lr
	thumb_func_end nullsub_120

	thumb_func_start sub_809D490
sub_809D490:
	push {r4,lr}
	ldr r4, _0809D4AC
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	bl sub_809D4B0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D4AC: .4byte gUnknown_203B4B0
	thumb_func_end sub_809D490

	thumb_func_start sub_809D4B0
sub_809D4B0:
	push {r4,r5,lr}
	ldr r0, _0809D4EC
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, _0809D4F0
	strh r1, [r0]
	ldr r0, _0809D4F4
	strh r1, [r0]
	ldr r1, _0809D4F8
	movs r0, 0
	strb r0, [r1]
	movs r1, 0
	ldr r5, _0809D4FC
	movs r2, 0
	ldr r3, _0809D500
	ldr r4, _0809D504
_0809D4D4:
	adds r0, r1, r5
	strb r2, [r0]
	adds r0, r1, r3
	strb r2, [r0]
	stm r4!, {r2}
	adds r1, 0x1
	cmp r1, 0x80
	ble _0809D4D4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809D4EC: .4byte gUnknown_2039A30
_0809D4F0: .4byte gUnknown_2039A32
_0809D4F4: .4byte gUnknown_2039A34
_0809D4F8: .4byte gUnknown_2039A36
_0809D4FC: .4byte gUnknown_2039A38
_0809D500: .4byte gUnknown_2039AC0
_0809D504: .4byte gUnknown_2039B48
	thumb_func_end sub_809D4B0

	thumb_func_start sub_809D508
sub_809D508:
	push {r4,lr}
	ldr r4, _0809D51C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D51C: .4byte gUnknown_203B4B0
	thumb_func_end sub_809D508

	thumb_func_start sub_809D520
sub_809D520:
	ldr r1, _0809D528
	strh r1, [r0]
	bx lr
	.align 2, 0
_0809D528: .4byte 0x0000ffff
	thumb_func_end sub_809D520

	thumb_func_start sub_809D52C
sub_809D52C:
	push {lr}
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x1
	beq _0809D544
	cmp r1, 0x1
	ble _0809D562
	cmp r1, 0x2
	beq _0809D54E
	cmp r1, 0x3
	beq _0809D558
	b _0809D562
_0809D544:
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A882C
	b _0809D564
_0809D54E:
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80AC240
	b _0809D564
_0809D558:
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80AD158
	b _0809D564
_0809D562:
	movs r0, 0
_0809D564:
	pop {r1}
	bx r1
	thumb_func_end sub_809D52C

	thumb_func_start sub_809D568
sub_809D568:
	push {lr}
	adds r3, r0, 0
	ldr r0, _0809D5B4
	strh r0, [r3]
	movs r2, 0
	movs r0, 0
	strh r0, [r3, 0x2]
	str r0, [r3, 0x8]
	str r0, [r3, 0x4]
	str r0, [r3, 0x14]
	str r0, [r3, 0x10]
	adds r1, r3, 0
	adds r1, 0x20
	strb r2, [r1]
	str r0, [r3, 0x1C]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r3, 0x22]
	strh r0, [r3, 0x24]
	adds r2, r3, 0
	adds r2, 0x26
	movs r1, 0xFF
	strb r1, [r2]
	strh r0, [r3, 0x28]
	strh r0, [r3, 0x2A]
	strh r0, [r3, 0x2C]
	str r0, [r3, 0x30]
	movs r2, 0
	movs r1, 0x3
	adds r0, r3, 0
	adds r0, 0x5C
_0809D5A6:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _0809D5A6
	pop {r0}
	bx r0
	.align 2, 0
_0809D5B4: .4byte 0x0000ffff
	thumb_func_end sub_809D568

	thumb_func_start sub_809D5B8
sub_809D5B8:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	ldr r0, _0809D5FC
	strh r0, [r4, 0x10]
	movs r0, 0xFF
	strb r0, [r4, 0x12]
	adds r0, r4, 0
	adds r0, 0xC
	bl sub_809D520
	movs r2, 0
	movs r1, 0x3
	adds r0, r4, 0
	adds r0, 0x20
_0809D5DA:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _0809D5DA
	adds r0, r4, 0
	adds r0, 0x24
	bl sub_809D568
	adds r0, r4, 0
	adds r0, 0x84
	bl sub_809D568
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D5FC: .4byte 0x0000ffff
	thumb_func_end sub_809D5B8

	thumb_func_start sub_809D600
sub_809D600:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x18]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	asrs r5, 24
	bl sub_809D5B8
	str r6, [r7]
	mov r0, r8
	str r0, [r7, 0x4]
	strh r4, [r7, 0x10]
	strb r5, [r7, 0x12]
	ldrh r0, [r6]
	strh r0, [r7, 0x8]
	ldr r1, [r6, 0x4]
	cmp r1, 0
	beq _0809D63A
	mov r0, r8
	bl _call_via_r1
	strh r0, [r7, 0xA]
	b _0809D63C
_0809D63A:
	strh r1, [r7, 0xA]
_0809D63C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809D600

	thumb_func_start sub_809D648
sub_809D648:
	push {lr}
	bl sub_809D5B8
	pop {r0}
	bx r0
	thumb_func_end sub_809D648

	thumb_func_start sub_809D654
sub_809D654:
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_809D654

	thumb_func_start sub_809D65C
sub_809D65C:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x26
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809D66E
	movs r0, 0x1
	negs r0, r0
	b _0809D672
_0809D66E:
	movs r2, 0x24
	ldrsh r0, [r1, r2]
_0809D672:
	pop {r1}
	bx r1
	thumb_func_end sub_809D65C

	thumb_func_start sub_809D678
sub_809D678:
	movs r2, 0x26
	ldrsh r1, [r0, r2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	thumb_func_end sub_809D678

	thumb_func_start sub_809D684
sub_809D684:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0809D6A4
	ldr r0, [r2, 0x34]
	cmp r0, 0
	beq _0809D69C
	ldr r1, [r2, 0x38]
	b _0809D69E
_0809D69C:
	ldr r1, [r2, 0x2C]
_0809D69E:
	ldr r0, [r3]
	cmp r1, r0
	beq _0809D6CC
_0809D6A4:
	adds r0, r2, 0
	adds r0, 0x86
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0809D6D0
	adds r0, r2, 0
	adds r0, 0x94
	ldr r0, [r0]
	cmp r0, 0
	beq _0809D6C0
	adds r0, r2, 0
	adds r0, 0x98
	b _0809D6C4
_0809D6C0:
	adds r0, r2, 0
	adds r0, 0x8C
_0809D6C4:
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bne _0809D6D0
_0809D6CC:
	movs r0, 0x1
	b _0809D6D2
_0809D6D0:
	movs r0, 0
_0809D6D2:
	pop {r1}
	bx r1
	thumb_func_end sub_809D684

	thumb_func_start sub_809D6D8
sub_809D6D8:
	lsls r1, 16
	asrs r1, 14
	adds r0, 0x14
	adds r0, r1
	str r2, [r0]
	bx lr
	thumb_func_end sub_809D6D8

	thumb_func_start sub_809D6E4
sub_809D6E4:
	push {r4,lr}
	lsls r2, 16
	asrs r2, 16
	lsls r4, r2, 2
	adds r3, r0, 0
	adds r3, 0x14
	adds r3, r4
	ldr r3, [r3]
	str r3, [r1]
	strh r2, [r1, 0x4]
	ldrh r2, [r0, 0x10]
	strh r2, [r1, 0x6]
	ldrb r0, [r0, 0x12]
	strb r0, [r1, 0x8]
	adds r0, r3, 0
	cmp r0, 0
	beq _0809D708
	movs r0, 0x1
_0809D708:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D6E4

	thumb_func_start sub_809D710
sub_809D710:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _0809D73C
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	str r0, [r3]
	movs r0, 0x2
	strh r0, [r3, 0x4]
	cmp r4, 0
	beq _0809D740
	ldrh r0, [r4, 0x10]
	strh r0, [r3, 0x6]
	ldrb r0, [r4, 0x12]
	b _0809D746
	.align 2, 0
_0809D73C: .4byte gUnknown_812F1F8
_0809D740:
	ldr r0, _0809D750
	strh r0, [r3, 0x6]
	movs r0, 0xFF
_0809D746:
	strb r0, [r3, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D750: .4byte 0x0000ffff
	thumb_func_end sub_809D710

	thumb_func_start sub_809D754
sub_809D754:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_809D568
	adds r4, 0x84
	adds r0, r4, 0
	bl sub_809D568
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D754

	thumb_func_start sub_809D770
sub_809D770:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_809D568
	adds r0, r4, 0
	adds r0, 0x84
	bl sub_809D568
	movs r0, 0x4
	strh r0, [r4, 0x26]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D770

	thumb_func_start GroundScript_ExecutePP
GroundScript_ExecutePP:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	cmp r6, 0
	beq _0809D7A2
	ldr r0, [r6]
	cmp r0, 0
	bne _0809D7A6
_0809D7A2:
	movs r0, 0
	b _0809D8B8
_0809D7A6:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0x5
	bhi _0809D858
	lsls r0, 2
	ldr r1, _0809D7B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809D7B8: .4byte _0809D7BC
	.align 2, 0
_0809D7BC:
	.4byte _0809D830
	.4byte _0809D84A
	.4byte _0809D7D4
	.4byte _0809D7D4
	.4byte _0809D858
	.4byte _0809D7EE
_0809D7D4:
	movs r3, 0x24
	ldrsh r0, [r5, r3]
	cmp r0, 0x1
	beq _0809D838
	adds r4, r5, 0
	adds r4, 0x24
	cmp r0, 0x5
	bne _0809D86C
	adds r0, r5, 0
	adds r0, 0x84
	bl sub_809D568
	b _0809D86C
_0809D7EE:
	movs r1, 0x24
	ldrsh r0, [r5, r1]
	cmp r0, 0x2
	beq _0809D808
	ldr r0, _0809D800
	ldr r1, _0809D804
	bl FatalError
	.align 2, 0
_0809D800: .4byte gUnknown_8116538
_0809D804: .4byte gUnknown_8116544
_0809D808:
	adds r2, r5, 0
	adds r2, 0x84
	movs r3, 0
	ldrsh r1, [r2, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809D828
	ldr r0, _0809D820
	ldr r1, _0809D824
	bl FatalError
	.align 2, 0
_0809D820: .4byte gUnknown_8116560
_0809D824: .4byte gUnknown_811656C
_0809D828:
	adds r4, r5, 0
	adds r4, 0x24
	adds r0, r2, 0
	b _0809D840
_0809D830:
	movs r1, 0x24
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _0809D84A
_0809D838:
	adds r0, r5, 0
	adds r0, 0x84
	adds r4, r5, 0
	adds r4, 0x24
_0809D840:
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	b _0809D86C
_0809D84A:
	adds r0, r5, 0
	adds r0, 0x84
	bl sub_809D568
	adds r4, r5, 0
	adds r4, 0x24
	b _0809D86C
_0809D858:
	ldr r0, _0809D864
	ldr r1, _0809D868
	movs r3, 0x4
	ldrsh r2, [r6, r3]
	bl FatalError
	.align 2, 0
_0809D864: .4byte gUnknown_8116588
_0809D868: .4byte gUnknown_8116594
_0809D86C:
	adds r0, r4, 0
	bl sub_809D568
	cmp r7, 0
	beq _0809D87C
	ldr r0, [r7]
	str r0, [r5, 0xC]
	b _0809D884
_0809D87C:
	adds r0, r5, 0
	adds r0, 0xC
	bl sub_809D520
_0809D884:
	ldrh r0, [r6, 0x4]
	movs r1, 0
	strh r0, [r5, 0x24]
	movs r0, 0x3
	strh r0, [r5, 0x26]
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x30]
	ldrb r0, [r6, 0x8]
	adds r2, r5, 0
	adds r2, 0x32
	strb r0, [r2]
	ldr r0, [r6]
	str r0, [r5, 0x28]
	str r0, [r5, 0x2C]
	str r1, [r5, 0x34]
	str r1, [r5, 0x38]
	ldr r0, [r5]
	ldr r2, [r0, 0x14]
	cmp r2, 0
	beq _0809D8B6
	ldr r0, [r5, 0x4]
	adds r1, r5, 0
	adds r1, 0x4A
	bl _call_via_r2
_0809D8B6:
	movs r0, 0x1
_0809D8B8:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundScript_ExecutePP

	thumb_func_start sub_809D8C0
sub_809D8C0:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 16
	mov r1, sp
	bl sub_809D6E4
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	adds r3, r6, 0
	bl GroundScript_ExecutePP
	lsls r0, 24
	lsrs r0, 24
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809D8C0

	thumb_func_start sub_809D8EC
sub_809D8EC:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	cmp r5, 0
	bne _0809D910
	bl sub_809A750
	lsls r0, 24
	cmp r0, 0
	bne _0809D910
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A2460
	str r0, [r4, 0x28]
	movs r0, 0
	b _0809D922
_0809D910:
	adds r0, r4, 0
	adds r0, 0x46
	strh r5, [r0]
	movs r0, 0x2
	strh r0, [r4, 0x26]
	ldr r1, _0809D928
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
_0809D922:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809D928: .4byte gUnknown_2039A36
	thumb_func_end sub_809D8EC

	thumb_func_start sub_809D92C
sub_809D92C:
	push {lr}
	ldr r1, _0809D93C
	bl sub_809D770
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_0809D93C: .4byte gUnknown_81165C8
	thumb_func_end sub_809D92C

	thumb_func_start sub_809D940
sub_809D940:
	push {r4,lr}
	bl sub_80A8B74
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80AC378
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80AD290
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D940

	thumb_func_start sub_809D968
sub_809D968:
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	movs r4, 0
	adds r2, r5, 0
	adds r2, 0x46
	ldrh r1, [r2]
	movs r0, 0
	ldrsh r3, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	beq _0809D98E
	cmp r3, r6
	bne _0809D98E
	ldr r0, _0809D9B4
	strh r0, [r2]
	movs r4, 0x1
_0809D98E:
	adds r2, r5, 0
	adds r2, 0xA6
	ldrh r1, [r2]
	movs r0, 0
	ldrsh r3, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	beq _0809D9AA
	cmp r3, r6
	bne _0809D9AA
	ldr r0, _0809D9B4
	strh r0, [r2]
	movs r4, 0x1
_0809D9AA:
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809D9B4: .4byte 0x0000ffff
	thumb_func_end sub_809D968

	thumb_func_start sub_809D9B8
sub_809D9B8:
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0809D9D4
	adds r1, r0, r1
	movs r3, 0
	movs r2, 0x1
	strb r2, [r1]
	ldr r1, _0809D9D8
	lsls r0, 2
	adds r0, r1
	str r3, [r0]
	ldr r0, _0809D9DC
	strb r2, [r0]
	bx lr
	.align 2, 0
_0809D9D4: .4byte gUnknown_2039A38
_0809D9D8: .4byte gUnknown_2039B48
_0809D9DC: .4byte gUnknown_2039A36
	thumb_func_end sub_809D9B8

	thumb_func_start sub_809D9E0
sub_809D9E0:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0809D9FC
	adds r2, r0, r2
	movs r3, 0x1
	strb r3, [r2]
	ldr r2, _0809DA00
	lsls r0, 2
	adds r0, r2
	str r1, [r0]
	ldr r0, _0809DA04
	strb r3, [r0]
	bx lr
	.align 2, 0
_0809D9FC: .4byte gUnknown_2039A38
_0809DA00: .4byte gUnknown_2039B48
_0809DA04: .4byte gUnknown_2039A36
	thumb_func_end sub_809D9E0

	thumb_func_start sub_809DA08
sub_809DA08:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	ldr r1, _0809DA2C
	lsls r0, r4, 2
	adds r0, r1
	str r2, [r0]
	cmp r4, 0
	bne _0809DA38
	bl sub_809A750
	lsls r0, 24
	cmp r0, 0
	bne _0809DA30
	movs r0, 0
	b _0809DA5E
	.align 2, 0
_0809DA2C: .4byte gUnknown_2039B48
_0809DA30:
	adds r0, r5, 0
	adds r0, 0x46
	strh r4, [r0]
	b _0809DA52
_0809DA38:
	movs r1, 0x80
	adds r2, r5, 0
	adds r2, 0x46
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0809DA64
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _0809DA68
	adds r0, r4, r0
	strb r1, [r0]
_0809DA52:
	movs r0, 0x2
	strh r0, [r5, 0x26]
	ldr r1, _0809DA6C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
_0809DA5E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809DA64: .4byte gUnknown_2039A38
_0809DA68: .4byte gUnknown_2039AC0
_0809DA6C: .4byte gUnknown_2039A36
	thumb_func_end sub_809DA08

	thumb_func_start HandleAction
HandleAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x148
	adds r7, r0, 0
	movs r1, 0x26
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _0809DA8A
	bl _0809EAB8
_0809DA8A:
	movs r2, 0x26
	ldrsh r0, [r7, r2]
	cmp r0, 0x4
	bls _0809DA96
	bl _0809E9CC
_0809DA96:
	lsls r0, 2
	ldr r1, _0809DAA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809DAA0: .4byte _0809DAA4
	.align 2, 0
_0809DAA4:
	.4byte _0809E9C6
	.4byte _0809E9C6
	.4byte _0809DAB8
	.4byte _0809E900
	.4byte _0809E9C6
_0809DAB8:
	adds r1, r7, 0
	adds r1, 0x44
	ldrb r0, [r1]
	subs r0, 0x3
	adds r6, r1, 0
	cmp r0, 0xED
	bls _0809DACA
	bl _0809E9D6
_0809DACA:
	lsls r0, 2
	ldr r1, _0809DAD4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809DAD4: .4byte _0809DAD8
	.align 2, 0
_0809DAD8:
	.4byte _0809E382
	.4byte _0809E3C4
	.4byte _0809E524
	.4byte _0809E464
	.4byte _0809E4B4
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E308
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E31C
	.4byte _0809E75C
	.4byte _0809E33C
	.4byte _0809E368
	.4byte _0809E658
	.4byte _0809E6B4
	.4byte _0809E6E8
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809E0A2
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809E0A2
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E0E8
	.4byte _0809E0E8
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E798
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E9D6
	.4byte _0809E8D8
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DEA6
	.4byte _0809DEBE
	.4byte _0809DED6
	.4byte _0809DEE8
	.4byte _0809DF24
	.4byte _0809DF24
	.4byte _0809E2DE
	.4byte _0809E9D6
	.4byte _0809E2DE
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
_0809DE90:
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	ble _0809DEA2
	bl _0809EAB2
_0809DEA2:
	bl _0809E8F4
_0809DEA6:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r1, [r1, 0x4C]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0809DEBA
	bl _0809E9D6
_0809DEBA:
	bl _0809E8F4
_0809DEBE:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r1, [r1, 0x50]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0809DED2
	bl _0809E9D6
_0809DED2:
	bl _0809E8F4
_0809DED6:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809DEE4
	bl _0809E9D6
_0809DEE4:
	bl _0809E8F4
_0809DEE8:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrh r0, [r0, 0x2]
	bl sub_8011940
	lsls r0, 24
	cmp r0, 0
	bne _0809DF06
	bl _0809E8F4
_0809DF06:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r1, [r2]
	adds r0, r1, 0x1
	strh r0, [r2]
	lsls r1, 16
	ldr r0, _0809DF20
	cmp r1, r0
	bgt _0809DF1C
	bl _0809E9D6
_0809DF1C:
	bl _0809E8F4
	.align 2, 0
_0809DF20: .4byte 0x2a2f0000
_0809DF24:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrh r0, [r0, 0x2]
	bl sub_80119C0
	lsls r0, 24
	cmp r0, 0
	bne _0809DF42
	bl _0809E8F4
_0809DF42:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r1, [r2]
	adds r0, r1, 0x1
	strh r0, [r2]
	lsls r1, 16
	ldr r0, _0809DF5C
	cmp r1, r0
	bgt _0809DF58
	bl _0809E9D6
_0809DF58:
	bl _0809E8F4
	.align 2, 0
_0809DF5C: .4byte 0x0e0f0000
_0809DF60:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0xA4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7, 0x60]
	ldr r0, [r5]
	subs r1, r0
	add r4, sp, 0xAC
	str r1, [r4]
	ldr r0, [r7, 0x64]
	ldr r1, [r5, 0x4]
	subs r0, r1
	str r0, [r4, 0x4]
	ldr r1, [r7, 0x54]
	adds r0, r4, 0
	bl sub_800290C
	ldr r0, [r4]
	cmp r0, 0
	bne _0809DF98
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bne _0809DF98
	bl _0809E8F4
_0809DF98:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0x9
	ands r1, r0
	cmp r1, 0
	beq _0809DFB0
	bl _0809E8F4
_0809DFB0:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r2, r7, 0
	adds r2, 0x4E
	ldrh r0, [r2]
	movs r5, 0
	ldrsh r1, [r2, r5]
	cmp r1, 0
	bge _0809DFD0
	bl _0809E9D6
_0809DFD0:
	cmp r1, 0
	ble _0809DFD8
	bl _0809EAAC
_0809DFD8:
	bl _0809E8F4
_0809DFDC:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0xB4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7, 0x60]
	ldr r0, [r5]
	subs r1, r0
	add r4, sp, 0xBC
	str r1, [r4]
	ldr r0, [r7, 0x64]
	ldr r1, [r5, 0x4]
	subs r0, r1
	str r0, [r4, 0x4]
	ldr r1, [r7, 0x54]
	adds r0, r4, 0
	bl sub_800290C
	ldr r0, [r4]
	adds r5, r4, 0
	cmp r0, 0
	bne _0809E016
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bne _0809E016
	bl _0809E8F4
_0809E016:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r5, 0
	bl _call_via_r2
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_8002C60
	lsls r0, 24
	adds r2, r7, 0
	adds r2, 0x4A
	asrs r1, r0, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	movs r0, 0x9
	ands r0, r4
	cmp r0, 0
	beq _0809E04C
	bl _0809E8F4
_0809E04C:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r2, r7, 0
	adds r2, 0x4E
	ldrh r0, [r2]
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0
	bge _0809E06C
	bl _0809E9D6
_0809E06C:
	cmp r1, 0
	ble _0809E074
	bl _0809EAAC
_0809E074:
	bl _0809E8F4
_0809E078:
	adds r6, r7, 0
	adds r6, 0x4E
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	ble _0809E088
	bl _0809EA62
_0809E088:
	bl _0809E8F4
_0809E08C:
	movs r2, 0x4E
	adds r2, r7
	mov r8, r2
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _0809E09E
	bl _0809E9DA
_0809E09E:
	bl _0809E8F4
_0809E0A2:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xE4
	add r2, sp, 0xE8
	ldr r3, [r1, 0x10]
	adds r1, r4, 0
	bl _call_via_r3
	ldr r0, [r7, 0x6C]
	ldr r1, [r4]
	subs r0, r1
	adds r2, r4, 0
	cmp r0, 0
	bne _0809E0C2
	bl _0809E8F4
_0809E0C2:
	ldr r4, [r7, 0x54]
	cmn r0, r4
	bge _0809E0CC
	subs r0, r1, r4
	b _0809E0D4
_0809E0CC:
	cmp r0, r4
	ble _0809E0D2
	adds r0, r4, 0
_0809E0D2:
	adds r0, r1, r0
_0809E0D4:
	str r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0xE4
	ldr r1, [r1]
	ldr r2, [r2, 0x28]
	bl _call_via_r2
	bl _0809E9D6
_0809E0E8:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0x14
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0
	ldrsb r1, [r4, r1]
	ldr r2, [r7, 0x54]
	add r4, sp, 0xEC
	adds r0, r4, 0
	bl sub_8002BB8
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	add r1, sp, 0xF4
	str r2, [r1]
	str r3, [r1, 0x4]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	movs r1, 0x9
	ands r1, r0
	cmp r1, 0
	beq _0809E124
	bl _0809E8F4
_0809E124:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	ble _0809E144
	bl _0809EAB2
_0809E144:
	b _0809E8F4
_0809E146:
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	mov r10, r1
	cmp r0, 0
	ble _0809E15A
	bl _0809EAB2
_0809E15A:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	movs r4, 0x1
	negs r4, r4
	mov r8, r4
	movs r5, 0
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	mov r4, sp
	adds r4, 0x15
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r0, sp, 0x4
	ldrb r0, [r0]
	subs r0, 0x91
	mov r9, r4
	cmp r0, 0x4
	bhi _0809E234
	lsls r0, 2
	ldr r1, _0809E194
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809E194: .4byte _0809E198
	.align 2, 0
_0809E198:
	.4byte _0809E1AC
	.4byte _0809E1AC
	.4byte _0809E1BA
	.4byte _0809E1E0
	.4byte _0809E20C
_0809E1AC:
	adds r0, r7, 0
	adds r0, 0x71
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	b _0809E234
_0809E1BA:
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _0809E234
	movs r5, 0x1
	add r1, sp, 0xFC
	adds r0, r4, 0
	bl sub_80A8FD8
	add r1, sp, 0x104
	adds r0, r4, 0
	bl sub_80A8F9C
	b _0809E234
_0809E1E0:
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _0809E234
	movs r5, 0x1
	add r1, sp, 0xFC
	bl sub_80A8FD8
	ldr r0, _0809E208
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x104
	str r0, [r2]
	str r1, [r2, 0x4]
	b _0809E234
	.align 2, 0
_0809E208: .4byte gUnknown_81164DC
_0809E20C:
	movs r5, 0x1
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xFC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0x104
	ldr r2, [r2, 0x8]
	bl _call_via_r2
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
_0809E234:
	cmp r5, 0
	beq _0809E282
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0x10C
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0x114
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r6, sp, 0xFC
	add r3, sp, 0x104
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _0809E28C
	ldr r3, _0809E2CC
	adds r0, r5, 0
	adds r1, r3, 0
	adds r2, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
_0809E282:
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _0809E28C
	b _0809E8F4
_0809E28C:
	mov r5, r9
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r8, r0
	bne _0809E298
	b _0809E8F4
_0809E298:
	mov r6, r9
	movs r0, 0
	ldrsb r0, [r6, r0]
	add r1, sp, 0x4
	ldrh r2, [r1, 0x2]
	lsls r2, 24
	lsrs r2, 24
	mov r1, r8
	bl sub_8002A70
	adds r1, r7, 0
	adds r1, 0x4A
	strb r0, [r1]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x4
	ldrb r0, [r0, 0x1]
	mov r1, r10
	strh r0, [r1]
	b _0809E9CC
	.align 2, 0
_0809E2CC: .4byte gUnknown_81164DC
_0809E2D0:
	bl sub_809D234
	lsls r0, 24
	cmp r0, 0
	beq _0809E2DC
	b _0809E9D6
_0809E2DC:
	b _0809E8F4
_0809E2DE:
	adds r0, r7, 0
	adds r0, 0x46
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E2F0
	b _0809E9D6
_0809E2F0:
	ldr r1, _0809E304
	adds r0, r7, 0
	adds r0, 0x4C
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _0809E8EC
	.align 2, 0
_0809E304: .4byte gUnknown_2039B48
_0809E308:
	adds r0, r7, 0
	adds r0, 0x46
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E31A
	b _0809E9D6
_0809E31A:
	b _0809E8CA
_0809E31C:
	adds r0, r7, 0
	adds r0, 0x46
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E32E
	b _0809E9D6
_0809E32E:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809E33A
	b _0809E9D6
_0809E33A:
	b _0809E8CA
_0809E33C:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrb r1, [r0, 0x1]
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	ldr r3, [sp, 0x8]
	adds r0, r7, 0
	bl sub_80A14E8
	adds r1, r0, 0
	cmp r1, 0
	bge _0809E360
	b _0809E9D6
_0809E360:
	movs r0, 0x3
	strh r0, [r7, 0x26]
	adds r0, r7, 0
	b _0809E60C
_0809E368:
	add r0, sp, 0x11C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E376
	b _0809E9D6
_0809E376:
	add r0, sp, 0x11C
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
_0809E382:
	add r0, sp, 0x120
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E390
	b _0809E9D6
_0809E390:
	add r4, sp, 0x120
	ldr r0, [r4]
	cmp r0, 0
	blt _0809E3BA
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r4]
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x4
	movs r3, 0x2
	ldrsh r2, [r1, r3]
	movs r1, 0
	bl sub_8098D1C
_0809E3BA:
	ldr r1, [r4]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
_0809E3C4:
	adds r4, r7, 0
	adds r4, 0x4C
	movs r5, 0
	ldrsh r0, [r4, r5]
	cmp r0, 0
	bne _0809E40C
	add r0, sp, 0x124
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E3DE
	b _0809E9D6
_0809E3DE:
	add r0, sp, 0x124
	ldr r0, [r0]
	cmp r0, 0
	blt _0809E400
	lsls r0, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	movs r0, 0x1
	b _0809E402
_0809E400:
	ldr r0, _0809E408
_0809E402:
	strh r0, [r4]
	b _0809E8CE
	.align 2, 0
_0809E408: .4byte 0x0000ffff
_0809E40C:
	cmp r0, 0x1
	bne _0809E464
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0
	movs r1, 0x12
	bl sub_8001658
	adds r2, r0, 0
	lsls r2, 16
	asrs r4, r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x30
	bl sub_8001784
	cmp r4, 0x13
	bne _0809E43C
	cmp r0, 0
	beq _0809E45A
_0809E43C:
	add r0, sp, 0x4
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_8098DCC
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A2460
	str r0, [r7, 0x28]
	movs r0, 0
	movs r1, 0
	bl sub_80A87AC
	b _0809E8F4
_0809E45A:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x13
	bl sub_80018D8
_0809E464:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r5, r0, 0
	cmp r1, 0
	bne _0809E4B4
	add r0, sp, 0x128
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E480
	b _0809E9D6
_0809E480:
	add r0, sp, 0x128
	ldr r1, [r0]
	cmp r1, 0
	blt _0809E4AA
	ldrb r0, [r6]
	cmp r0, 0x4
	bne _0809E49A
	lsls r0, r1, 16
	asrs r0, 16
	bl sub_80A26B8
	lsls r0, 16
	b _0809E49C
_0809E49A:
	lsls r0, r1, 16
_0809E49C:
	asrs r2, r0, 16
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	movs r0, 0x1
	b _0809E4AC
_0809E4AA:
	ldr r0, _0809E4B0
_0809E4AC:
	strh r0, [r5]
	b _0809E8CE
	.align 2, 0
_0809E4B0: .4byte 0x0000ffff
_0809E4B4:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r5, r0, 0
	cmp r1, 0x1
	beq _0809E4C4
	b _0809E5B8
_0809E4C4:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r6, r0, 16
	add r4, sp, 0x18
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80990EC
	lsls r0, 24
	cmp r0, 0
	beq _0809E580
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8099220
	movs r0, 0x6
	bl sub_80023E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4]
	ldr r4, _0809E51C
	ldr r2, [r4]
	movs r1, 0
	str r1, [sp]
	bl sub_809034C
	adds r1, r0, 0
	ldr r0, _0809E520
	str r1, [r0]
	cmp r1, 0x1
	beq _0809E586
	cmp r1, 0x1
	bcc _0809E580
	cmp r1, 0x2
	bne _0809E5AE
	strh r1, [r5]
	ldr r2, [r4]
	movs r0, 0x9
	b _0809E58E
	.align 2, 0
_0809E51C: .4byte gUnknown_203B4B0
_0809E520: .4byte gUnknown_2039DA4
_0809E524:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r4, 0
	ldrsh r6, [r0, r4]
	adds r5, r0, 0
	cmp r6, 0x1
	bne _0809E5B8
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_80023E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x4]
	ldr r4, _0809E578
	ldr r2, [r4]
	str r6, [sp]
	movs r1, 0
	bl sub_809034C
	adds r1, r0, 0
	ldr r0, _0809E57C
	str r1, [r0]
	cmp r1, 0x1
	beq _0809E586
	cmp r1, 0x1
	bcc _0809E580
	cmp r1, 0x2
	bne _0809E5AE
	strh r1, [r5]
	ldr r2, [r4]
	movs r0, 0x9
	b _0809E58E
	.align 2, 0
_0809E578: .4byte gUnknown_203B4B0
_0809E57C: .4byte gUnknown_2039DA4
_0809E580:
	movs r0, 0x3
	strh r0, [r5]
	b _0809E9CC
_0809E586:
	movs r0, 0x4
	strh r0, [r5]
	ldr r2, [r4]
	movs r0, 0xA
_0809E58E:
	movs r1, 0x1
	bl sub_809B1C0
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	bne _0809E5A4
	b _0809E9CC
_0809E5A4:
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	b _0809E9CC
_0809E5AE:
	ldr r0, _0809E5B4
	strh r0, [r5]
	b _0809E9CC
	.align 2, 0
_0809E5B4: .4byte 0x0000ffff
_0809E5B8:
	movs r6, 0
	ldrsh r2, [r5, r6]
	cmp r2, 0x2
	bne _0809E5DA
	add r0, sp, 0x12C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E5CE
	b _0809E9D6
_0809E5CE:
	add r0, sp, 0x12C
	ldr r0, [r0]
	cmp r0, 0
	beq _0809E626
	movs r0, 0x3
	b _0809E628
_0809E5DA:
	cmp r2, 0x3
	bne _0809E614
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	strh r2, [r7, 0x26]
	add r0, sp, 0x4
	movs r6, 0x2
	ldrsh r0, [r0, r6]
	bl sub_80999FC
	movs r0, 0x70
	movs r1, 0
	bl GroundMap_ExecuteEvent
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _0809E608
	b _0809E9CC
_0809E608:
	adds r0, r7, 0
	movs r1, 0x1
_0809E60C:
	bl sub_80A2460
	str r0, [r7, 0x28]
	b _0809E9CC
_0809E614:
	cmp r2, 0x4
	bne _0809E63C
	add r0, sp, 0x130
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E626
	b _0809E9D6
_0809E626:
	ldr r0, _0809E638
_0809E628:
	strh r0, [r5]
	movs r0, 0
	movs r1, 0
	bl sub_80A87AC
	bl sub_809A76C
	b _0809E9CC
	.align 2, 0
_0809E638: .4byte 0x0000ffff
_0809E63C:
	movs r0, 0
	movs r1, 0
	bl sub_8099220
	movs r4, 0x1
	negs r4, r4
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
	adds r0, r7, 0
	adds r1, r4, 0
	b _0809E8EE
_0809E658:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x134
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E672
	b _0809E9D6
_0809E672:
	add r0, sp, 0x134
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809E6A4
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E6A4
	adds r0, r1, 0
	bl sub_80A8D54
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _0809E6B0
_0809E696:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _0809E696
_0809E6A4:
	add r0, sp, 0x134
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E6B0: .4byte gUnknown_2039D98
_0809E6B4:
	add r0, sp, 0x138
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E6C2
	b _0809E9D6
_0809E6C2:
	add r4, sp, 0x138
	ldr r0, [r4]
	cmp r0, 0x1
	bne _0809E6D0
	ldr r0, _0809E6DC
	bl sub_80920EC
_0809E6D0:
	ldr r1, [r4]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E6DC: .4byte gUnknown_2039D98
_0809E6E0:
	movs r1, 0x2
	add r0, sp, 0x13C
	str r1, [r0]
	b _0809E74A
_0809E6E8:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	ldr r5, [sp, 0x10]
	add r0, sp, 0x13C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E704
	b _0809E9D6
_0809E704:
	add r0, sp, 0x13C
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809E74A
	add r4, sp, 0x18
	ldr r0, _0809E758
	adds r3, r4, 0
	movs r2, 0
	mov r1, sp
	adds r1, 0x27
_0809E718:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, r3
	bge _0809E718
	adds r1, r4, 0
	bl sub_80922F4
	movs r2, 0
	ldrb r0, [r4]
	ldrb r3, [r5]
	cmp r0, r3
	bne _0809E6E0
	cmp r0, 0
	beq _0809E74A
_0809E734:
	adds r2, 0x1
	cmp r2, 0xF
	bgt _0809E74A
	adds r0, r4, r2
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0809E6E0
	cmp r0, 0
	bne _0809E734
_0809E74A:
	add r0, sp, 0x13C
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E758: .4byte gUnknown_2039D98
_0809E75C:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r3, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	bne _0809E76C
	b _0809E872
_0809E76C:
	add r4, sp, 0xA0
	adds r0, r4, 0
	bl sub_809AFFC
	lsls r0, 24
	cmp r0, 0
	bne _0809E77C
	b _0809E9D6
_0809E77C:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0809E784
	b _0809E8CA
_0809E784:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _0809E8C2
_0809E798:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, r7, 0
	adds r2, 0x50
	movs r3, 0
	ldrsh r0, [r2, r3]
	adds r4, r2, 0
	cmp r0, 0
	bne _0809E84C
	movs r3, 0
	adds r0, r7, 0
	adds r0, 0x4C
	movs r5, 0
	ldrsh r2, [r0, r5]
	adds r5, r0, 0
	cmp r2, 0
	bge _0809E7CC
	ldr r0, [r7, 0x28]
	ldrb r0, [r0]
	cmp r0, 0xD1
	beq _0809E812
	b _0809E8F4
_0809E7CC:
	ldr r1, [r7, 0x28]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _0809E7F8
	movs r6, 0x2
	ldrsh r0, [r1, r6]
	cmp r0, r2
	beq _0809E812
_0809E7DC:
	ldr r0, [r7, 0x28]
	adds r1, r0, 0
	adds r1, 0x10
	str r1, [r7, 0x28]
	ldrb r0, [r0, 0x10]
	cmp r0, 0xD0
	bne _0809E7F8
	movs r0, 0x2
	ldrsh r1, [r1, r0]
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _0809E7DC
	movs r3, 0x1
_0809E7F8:
	cmp r3, 0
	bne _0809E812
	ldr r1, [r7, 0x28]
	ldrb r0, [r1]
	cmp r0, 0xD1
	bne _0809E8F4
_0809E804:
	adds r0, r1, 0
	adds r1, 0x10
	str r1, [r7, 0x28]
	ldrb r0, [r0, 0x10]
	cmp r0, 0xD1
	beq _0809E804
	b _0809E8F4
_0809E812:
	add r0, sp, 0x4
	ldrb r0, [r0, 0x1]
	ldr r1, [sp, 0x8]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [r7, 0x28]
	ldr r2, [r2, 0xC]
	bl sub_809AE90
	lsls r0, 24
	cmp r0, 0
	beq _0809E844
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	adds r0, r7, 0
	movs r1, 0
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	beq _0809E844
	movs r0, 0x1
	strh r0, [r4]
_0809E844:
	ldr r0, [r7, 0x28]
	adds r0, 0x10
	str r0, [r7, 0x28]
	b _0809E9CC
_0809E84C:
	adds r0, r7, 0
	adds r0, 0x46
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E85E
	b _0809E9D6
_0809E85E:
	movs r0, 0
	strh r0, [r2]
	b _0809E8D0
_0809E864:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r3, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	bne _0809E88A
_0809E872:
	adds r0, r7, 0
	adds r0, 0x46
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E884
	b _0809E9D6
_0809E884:
	adds r0, r3, 0x1
	strh r0, [r2]
	b _0809E9CC
_0809E88A:
	add r0, sp, 0x140
	bl sub_809B18C
	lsls r0, 24
	cmp r0, 0
	bne _0809E898
	b _0809E9D6
_0809E898:
	add r0, sp, 0x140
	ldr r3, [r0]
	cmp r3, 0
	ble _0809E8CA
	adds r0, r7, 0
	adds r0, 0x4C
	movs r6, 0
	ldrsh r2, [r0, r6]
	ldr r1, [r7, 0x40]
	lsls r0, r3, 4
	lsls r2, 4
	adds r2, r1
	add r1, sp, 0x4
	adds r0, r2
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	movs r5, 0x2
	ldrsh r1, [r0, r5]
_0809E8C2:
	adds r0, r7, 0
	bl sub_80A242C
_0809E8C8:
	str r0, [r7, 0x28]
_0809E8CA:
	movs r0, 0x3
	strh r0, [r7, 0x26]
_0809E8CE:
	movs r0, 0
_0809E8D0:
	movs r1, 0
	bl sub_80A87AC
	b _0809E9CC
_0809E8D8:
	adds r0, r7, 0
	adds r0, 0x46
	movs r6, 0
	ldrsh r1, [r0, r6]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809E9D6
	ldr r0, _0809E8FC
	ldr r1, [r0, 0x4]
_0809E8EC:
	adds r0, r7, 0
_0809E8EE:
	bl sub_80A2460
	str r0, [r7, 0x28]
_0809E8F4:
	movs r0, 0x3
	strh r0, [r7, 0x26]
	b _0809E9CC
	.align 2, 0
_0809E8FC: .4byte gUnknown_2039B48
_0809E900:
	adds r0, r7, 0
	bl ExecuteScriptCommand
	strh r0, [r7, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _0809E9BC
	lsls r0, 2
	ldr r1, _0809E91C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809E91C: .4byte _0809E920
	.align 2, 0
_0809E920:
	.4byte _0809E934
	.4byte _0809E9B8
	.4byte _0809E9BC
	.4byte _0809E9D6
	.4byte _0809E9B4
_0809E934:
	adds r0, r7, 0
	adds r0, 0x86
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0809E9AA
	adds r4, r7, 0
	adds r4, 0x84
	adds r0, r7, 0
	adds r0, 0x24
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	ldr r2, [r7]
	ldr r0, [r2, 0x2C]
	cmp r0, 0
	beq _0809E98E
	adds r5, r7, 0
	adds r5, 0x4A
	movs r1, 0
	ldrsb r1, [r5, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E98E
	ldr r0, [r7, 0x4]
	add r1, sp, 0x144
	ldr r2, [r2, 0x18]
	bl _call_via_r2
	add r0, sp, 0x144
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0809E98E
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0
	ldrsb r1, [r5, r1]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_0809E98E:
	ldr r0, [r7]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq _0809E9A2
	ldr r0, [r7, 0x4]
	adds r1, r7, 0
	adds r1, 0x48
	ldrh r1, [r1]
	bl _call_via_r2
_0809E9A2:
	adds r0, r4, 0
	bl sub_809D568
	b _0809E9D6
_0809E9AA:
	adds r0, r7, 0
	adds r0, 0x24
	bl sub_809D568
	b _0809E9D6
_0809E9B4:
	movs r0, 0x4
	b _0809EABA
_0809E9B8:
	movs r0, 0x1
	b _0809EABA
_0809E9BC:
	adds r1, r7, 0
	adds r1, 0x50
	movs r0, 0
	strh r0, [r1]
	b _0809E9CC
_0809E9C6:
	movs r2, 0x26
	ldrsh r0, [r7, r2]
	b _0809EABA
_0809E9CC:
	movs r3, 0x1
	cmp r3, 0
	beq _0809E9D6
	bl _0809DA8A
_0809E9D6:
	movs r0, 0x3
	b _0809EABA
_0809E9DA:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xCC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0xD4
	adds r1, r7, 0
	adds r1, 0x58
	adds r2, r7, 0
	adds r2, 0x60
	mov r6, r8
	movs r0, 0
	ldrsh r6, [r6, r0]
	mov r9, r6
	adds r6, r7, 0
	adds r6, 0x50
	movs r3, 0
	ldrsh r0, [r6, r3]
	str r0, [sp]
	adds r0, r5, 0
	mov r3, r9
	bl sub_8002934
	ldr r1, [r5]
	ldr r0, [r4]
	subs r1, r0
	add r0, sp, 0xDC
	str r1, [r0]
	ldr r1, [r5, 0x4]
	ldr r2, [r4, 0x4]
	subs r1, r2
	str r1, [r0, 0x4]
	bl sub_8002C60
	lsls r0, 24
	adds r2, r7, 0
	adds r2, 0x4A
	asrs r1, r0, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	mov r4, r8
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	b _0809E9D6
_0809EA62:
	add r5, sp, 0xC4
	adds r1, r7, 0
	adds r1, 0x58
	adds r2, r7, 0
	adds r2, 0x60
	movs r3, 0
	ldrsh r0, [r6, r3]
	mov r8, r0
	adds r4, r7, 0
	adds r4, 0x50
	movs r3, 0
	ldrsh r0, [r4, r3]
	str r0, [sp]
	adds r0, r5, 0
	mov r3, r8
	bl sub_8002934
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	ldrh r0, [r6]
	subs r0, 0x1
	strh r0, [r6]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0809E9D6
_0809EAAC:
	subs r0, 0x1
	strh r0, [r2]
	b _0809E9D6
_0809EAB2:
	subs r0, r2, 0x1
	strh r0, [r1]
	b _0809E9D6
_0809EAB8:
	movs r0, 0
_0809EABA:
	add sp, 0x148
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end HandleAction

	thumb_func_start ExecuteScriptCommand
ExecuteScriptCommand:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1BC
	mov r9, r0
	movs r0, 0x24
	add r0, r9
	mov r10, r0
_0809EAE0:
	mov r1, r10
	ldr r2, [r1, 0x4]
	str r2, [r1, 0x1C]
	add r1, sp, 0x8
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, 0x10
	mov r0, r10
	str r2, [r0, 0x4]
	add r0, sp, 0x8
	ldrb r0, [r0]
	mov r1, r10
	adds r1, 0x20
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	adds r2, r1, 0
	cmp r0, 0xF5
	bhi _0809EAE0
	lsls r0, 2
	ldr r1, _0809EB18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809EB18: .4byte _0809EB1C
	.align 2, 0
_0809EB1C:
	.4byte _0809EEF4
	.4byte _0809EF40
	.4byte _0809EFA2
	.4byte _0809EFD6
	.4byte _0809F064
	.4byte _0809F02A
	.4byte _0809F06C
	.4byte _0809F0D0
	.4byte _0809F0D0
	.4byte _0809F1FC
	.4byte _0809F2C8
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F42A
	.4byte _0809F432
	.4byte _0809F43A
	.4byte _0809F442
	.4byte _0809F4FE
	.4byte _0809F5BE
	.4byte _0809F5AE
	.4byte _0809F5C6
	.4byte _0809F5C6
	.4byte _0809F660
	.4byte _0809F6EA
	.4byte _0809F786
	.4byte _0809F830
	.4byte _0809F842
	.4byte _0809F854
	.4byte _0809F872
	.4byte _0809F884
	.4byte _0809F896
	.4byte _0809F896
	.4byte _0809F8E8
	.4byte _0809F8F4
	.4byte _0809F900
	.4byte _0809F90C
	.4byte _0809F93E
	.4byte _0809FAF8
	.4byte _0809FB10
	.4byte _0809F92E
	.4byte _0809F936
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FBDA
	.4byte _0809FC12
	.4byte _0809FC40
	.4byte _0809FC2E
	.4byte _0809FC46
	.4byte _0809FCA4
	.4byte _0809FCC4
	.4byte _0809EAE0
	.4byte _080A0E3A
	.4byte _0809FCE8
	.4byte _0809FCF0
	.4byte _0809FD0A
	.4byte _0809FD38
	.4byte _0809FD6C
	.4byte _0809FDA0
	.4byte _0809FDA8
	.4byte _0809FDC2
	.4byte _0809FDD4
	.4byte _0809FDE2
	.4byte _0809FDC2
	.4byte _0809FDD4
	.4byte _0809FDE2
	.4byte _0809FE04
	.4byte _0809FE28
	.4byte _0809FE86
	.4byte _0809FEBE
	.4byte _0809FED0
	.4byte _0809FF00
	.4byte _0809FF32
	.4byte _0809FF46
	.4byte _0809FF62
	.4byte _0809FF78
	.4byte _0809FF9A
	.4byte _0809FFBA
	.4byte _0809FFE4
	.4byte _080A0010
	.4byte _080A0064
	.4byte _080A0096
	.4byte _080A010E
	.4byte _080A0186
	.4byte _080A0198
	.4byte _080A01B8
	.4byte _080A01F0
	.4byte _080A0220
	.4byte _080A0250
	.4byte _080A0282
	.4byte _080A0282
	.4byte _080A0560
	.4byte _080A0198
	.4byte _080A01B8
	.4byte _080A01F0
	.4byte _080A0220
	.4byte _080A0250
	.4byte _080A0282
	.4byte _080A0282
	.4byte _080A0560
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A057C
	.4byte _080A05A4
	.4byte _080A05F0
	.4byte _080A060E
	.4byte _080A065C
	.4byte _080A068A
	.4byte _080A068A
	.4byte _080A068A
	.4byte _080A07CA
	.4byte _080A07DC
	.4byte _080A07C4
	.4byte _080A07C4
	.4byte _080A07C4
	.4byte _0809EAE0
	.4byte _080A080C
	.4byte _080A081E
	.4byte _080A086A
	.4byte _080A08BE
	.4byte _080A08CA
	.4byte _080A091E
	.4byte _080A0986
	.4byte _080A0998
	.4byte _080A09EA
	.4byte _080A0A52
	.4byte _080A0A64
	.4byte _080A0AB6
	.4byte _080A0B1E
	.4byte _080A0B30
	.4byte _080A0B42
	.4byte _080A0B54
	.4byte _080A0B6C
	.4byte _080A0B88
	.4byte _080A0BA2
	.4byte _080A0BB4
	.4byte _080A0BDA
	.4byte _080A0BF6
	.4byte _080A0C08
	.4byte _080A0C20
	.4byte _080A0C38
	.4byte _080A0C50
	.4byte _080A0C68
	.4byte _080A0C80
	.4byte _080A0C90
	.4byte _080A0CA2
	.4byte _080A0CC8
	.4byte _080A0CF2
	.4byte _080A0D16
	.4byte _080A0D40
	.4byte _080A0D6A
	.4byte _080A0D7A
	.4byte _080A0D94
	.4byte _080A0DAE
	.4byte _080A0DD6
	.4byte _080A0E08
	.4byte _080A0DE2
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _080A10A0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _0809EAE0
	.4byte _080A129E
	.4byte _080A12A8
	.4byte _080A12B4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _080A12D0
	.4byte _080A12E6
	.4byte _080A12F4
	.4byte _080A1318
	.4byte _080A1324
	.4byte _080A1338
	.4byte _080A1344
	.4byte _080A1368
	.4byte _080A1374
	.4byte _080A13CA
	.4byte _080A13F8
	.4byte _080A1404
	.4byte _080A140C
	.4byte _080A1428
	.4byte _080A142C
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
_0809EEF4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	adds r6, r4, 0
	add r0, sp, 0x8
	ldrb r5, [r0, 0x1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809EF26
	ldr r1, _0809EF38
	ldr r2, _0809EF3C
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r3, [r0]
	str r5, [sp]
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809EF26:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8098D1C
	b _0809EAE0
	.align 2, 0
_0809EF38: .4byte gUnknown_81165D4
_0809EF3C: .4byte gUnknown_811BAF4
_0809EF40:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	movs r5, 0x1
	negs r5, r5
	cmp r4, r5
	bne _0809EF5A
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
_0809EF5A:
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809EF70
	ldr r1, _0809EF90
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809EF70:
	cmp r4, r5
	beq _0809EF94
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_8098E18
	mov r0, r9
	movs r1, 0x1
	bl sub_80A2460
	mov r3, r9
	str r0, [r3, 0x28]
	b _0809EAE0
	.align 2, 0
_0809EF90: .4byte gUnknown_81165F4
_0809EF94:
	mov r0, r9
	movs r1, 0
	bl sub_80A2460
	mov r4, r9
	str r0, [r4, 0x28]
	b _0809EAE0
_0809EFA2:
	ldr r0, [sp, 0xC]
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _0809EFBE
	movs r1, 0x1
	negs r1, r1
	mov r0, r9
	bl sub_80A2460
	mov r5, r9
	str r0, [r5, 0x28]
	b _0809EAE0
_0809EFBE:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_8098D80
	mov r0, r9
	movs r1, 0
	bl sub_80A2460
	mov r2, r9
	str r0, [r2, 0x28]
	b _0809EAE0
_0809EFD6:
	ldr r1, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809F00C
	bl sub_802FCF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0809F0BC
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _0809F0BC
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	mov r0, r9
	adds r0, 0x4C
	strh r4, [r0]
	b _0809F0C4
_0809F00C:
	lsls r0, r1, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F02A:
	ldr r2, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bne _0809F054
	movs r0, 0x24
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _0809F0BC
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0
	b _0809F0C2
_0809F054:
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F064:
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F06C:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0809F088
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	b _0809F092
_0809F088:
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
_0809F092:
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F0A8
	ldr r1, _0809F0B8
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809F0A8:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809F0BC
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
	.align 2, 0
_0809F0B8: .4byte gUnknown_811660C
_0809F0BC:
	mov r1, r9
	adds r1, 0x4C
	ldr r0, _0809F0CC
_0809F0C2:
	strh r0, [r1]
_0809F0C4:
	movs r0, 0x2
	bl _080A142E
	.align 2, 0
_0809F0CC: .4byte 0x0000ffff
_0809F0D0:
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0809F130
	ldr r5, _0809F11C
	ldr r0, [sp, 0xC]
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A4D7C
	ldr r4, _0809F120
	strh r0, [r4]
	ldr r1, _0809F124
	strh r0, [r1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F16A
	ldr r1, _0809F128
	movs r3, 0
	ldrsh r2, [r5, r3]
	movs r5, 0
	ldrsh r3, [r4, r5]
	ldr r4, _0809F12C
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
	b _0809F16A
	.align 2, 0
_0809F11C: .4byte gUnknown_2039A30
_0809F120: .4byte gUnknown_2039A32
_0809F124: .4byte gUnknown_2039A34
_0809F128: .4byte gUnknown_8116628
_0809F12C: .4byte gUnknown_811BAF4
_0809F130:
	ldr r5, _0809F1E8
	ldr r4, _0809F1EC
	ldr r1, [sp, 0xC]
	strh r1, [r4]
	strh r1, [r5]
	ldr r0, _0809F1F0
	strh r1, [r0]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F16A
	ldr r1, _0809F1F4
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r4, 0
	ldrsh r3, [r5, r4]
	ldr r4, _0809F1F8
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
_0809F16A:
	ldr r5, _0809F1EC
	movs r0, 0
	ldrsh r2, [r5, r0]
	movs r0, 0
	movs r1, 0x10
	bl sub_80018D8
	ldr r6, _0809F1F8
	movs r2, 0
	ldrsh r1, [r5, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0
	movs r1, 0x11
	bl sub_80018D8
	ldr r4, _0809F1E8
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl GroundSprite_Reset
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl sub_809C770
	movs r5, 0
	ldrsh r0, [r4, r5]
	bl GroundMap_Select
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl GroundLink_Select
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r1, 0
	movs r2, 0
	bl GroundLives_Select
	movs r3, 0
	ldrsh r0, [r4, r3]
	b _0809F2A0
	.align 2, 0
_0809F1E8: .4byte gUnknown_2039A32
_0809F1EC: .4byte gUnknown_2039A30
_0809F1F0: .4byte gUnknown_2039A34
_0809F1F4: .4byte gUnknown_8116644
_0809F1F8: .4byte gUnknown_811BAF4
_0809F1FC:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	adds r6, r0, 0
	ldr r1, _0809F2AC
	ldr r5, _0809F2B0
	ldr r4, _0809F2B4
	ldr r0, [sp, 0x10]
	strh r0, [r4]
	strh r0, [r5]
	strh r0, [r1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F242
	ldr r1, _0809F2B8
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r4, 0
	ldrsh r3, [r5, r4]
	ldr r4, _0809F2BC
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
_0809F242:
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl GroundSprite_Reset
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
	ldrb r2, [r6, 0xC]
	ldr r1, _0809F2C0
	ldr r0, [sp, 0x58]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x58]
	add r1, sp, 0x8
	ldrh r2, [r1, 0x2]
	lsls r2, 24
	lsrs r2, 16
	ldr r1, _0809F2C4
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x58]
	movs r2, 0
	ldrsh r0, [r5, r2]
	add r1, sp, 0x58
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl GroundMap_SelectDungeon
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl GroundLink_Select
	movs r4, 0
	ldrsh r0, [r5, r4]
	movs r1, 0
	movs r2, 0
	bl GroundLives_Select
	movs r1, 0
	ldrsh r0, [r5, r1]
_0809F2A0:
	movs r1, 0
	movs r2, 0
	bl GroundObject_Select
	b _0809EAE0
	.align 2, 0
_0809F2AC: .4byte gUnknown_2039A34
_0809F2B0: .4byte gUnknown_2039A32
_0809F2B4: .4byte gUnknown_2039A30
_0809F2B8: .4byte gUnknown_8116664
_0809F2BC: .4byte gUnknown_811BAF4
_0809F2C0: .4byte 0xffffff00
_0809F2C4: .4byte 0xffff00ff
_0809F2C8:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl GroundWeather_Select
	bl _0809EAE0
_0809F2D6:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809F2E8
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	b _0809F2EE
_0809F2E8:
	mov r3, r10
	movs r4, 0xC
	ldrsh r0, [r3, r4]
_0809F2EE:
	adds r6, r0, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F302
	add r0, sp, 0x8
	movs r1, 0x1
	ldrsb r1, [r0, r1]
	b _0809F308
_0809F302:
	mov r5, r10
	movs r1, 0xE
	ldrsb r1, [r5, r1]
_0809F308:
	adds r5, r1, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	subs r0, 0xC
	cmp r0, 0x9
	bls _0809F318
	bl _0809EAE0
_0809F318:
	lsls r0, 2
	ldr r1, _0809F324
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809F324: .4byte _0809F328
	.align 2, 0
_0809F328:
	.4byte _0809F350
	.4byte _0809F380
	.4byte _0809F398
	.4byte _0809F3B0
	.4byte _0809F3C8
	.4byte _0809F3E0
	.4byte _0809F3FA
	.4byte _0809F406
	.4byte _0809F412
	.4byte _0809F41E
_0809F350:
	ldr r4, _0809F37C
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundLives_Select
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundObject_Select
	movs r3, 0
	ldrsh r0, [r4, r3]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEffect_Select
	movs r1, 0
	ldrsh r0, [r4, r1]
	b _0809F3CE
	.align 2, 0
_0809F37C: .4byte gUnknown_2039A32
_0809F380:
	ldr r0, _0809F394
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundLives_Select
	bl _0809EAE0
	.align 2, 0
_0809F394: .4byte gUnknown_2039A32
_0809F398:
	ldr r0, _0809F3AC
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundObject_Select
	bl _0809EAE0
	.align 2, 0
_0809F3AC: .4byte gUnknown_2039A32
_0809F3B0:
	ldr r0, _0809F3C4
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEffect_Select
	bl _0809EAE0
	.align 2, 0
_0809F3C4: .4byte gUnknown_2039A32
_0809F3C8:
	ldr r0, _0809F3DC
	movs r1, 0
	ldrsh r0, [r0, r1]
_0809F3CE:
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEvent_Select
	bl _0809EAE0
	.align 2, 0
_0809F3DC: .4byte gUnknown_2039A32
_0809F3E0:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundLives_Cancel
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundObject_Cancel
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEffect_Cancel
	b _0809F41E
_0809F3FA:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundLives_Cancel
	bl _0809EAE0
_0809F406:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundObject_Cancel
	bl _0809EAE0
_0809F412:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEffect_Cancel
	bl _0809EAE0
_0809F41E:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEvent_Cancel
	bl _0809EAE0
_0809F42A:
	bl sub_80A79FC
	bl _0809EAE0
_0809F432:
	bl GroundObject_CancelBlank
	bl _0809EAE0
_0809F43A:
	bl GroundEffect_CancelBlank
	bl _0809EAE0
_0809F442:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x18
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r6, sp, 0x1C
	ldr r0, [sp, 0x10]
	add r5, sp, 0x34
	movs r2, 0
	strb r0, [r5]
	ldrb r1, [r4]
	mov r0, sp
	adds r0, 0x35
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	str r2, [sp, 0x38]
	add r4, sp, 0x3C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	bl memset
	ldr r2, _0809F4AC
	ldr r1, [sp, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	str r0, [r4, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x18
	bl memcpy
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	adds r1, r6, 0
	cmp r0, 0
	blt _0809F4B0
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	b _0809F4B6
	.align 2, 0
_0809F4AC: .4byte gUnknown_812F1F8
_0809F4B0:
	mov r4, r10
	movs r5, 0xC
	ldrsh r2, [r4, r5]
_0809F4B6:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F4C8
	add r0, sp, 0x8
	movs r3, 0x1
	ldrsb r3, [r0, r3]
	b _0809F4CE
_0809F4C8:
	mov r0, r10
	movs r3, 0xE
	ldrsb r3, [r0, r3]
_0809F4CE:
	movs r0, 0x1
	negs r0, r0
	bl GroundObject_Add
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _0809F4E2
	bl _0809EAE0
_0809F4E2:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x5C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AC49C
	bl _0809EAE0
_0809F4FE:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r4, sp, 0x4C
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0x1C
	ldr r0, [sp, 0x10]
	add r1, sp, 0x28
	movs r3, 0
	strb r0, [r1]
	ldrb r2, [r4]
	mov r0, sp
	adds r0, 0x29
	strb r2, [r0]
	adds r0, 0x1
	movs r2, 0x1
	strb r2, [r0]
	adds r0, 0x1
	strb r2, [r0]
	str r3, [sp, 0x2C]
	ldr r3, _0809F55C
	ldr r2, [sp, 0xC]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, 0x8
	adds r0, r3
	ldr r0, [r0]
	str r0, [sp, 0x30]
	adds r0, r5, 0
	movs r2, 0xC
	bl memcpy
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	adds r1, r5, 0
	cmp r0, 0
	blt _0809F560
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	b _0809F566
	.align 2, 0
_0809F55C: .4byte gUnknown_812F1F8
_0809F560:
	mov r5, r10
	movs r0, 0xC
	ldrsh r2, [r5, r0]
_0809F566:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F578
	add r0, sp, 0x8
	movs r3, 0x1
	ldrsb r3, [r0, r3]
	b _0809F57E
_0809F578:
	mov r4, r10
	movs r3, 0xE
	ldrsb r3, [r4, r3]
_0809F57E:
	movs r0, 0x1
	negs r0, r0
	bl GroundEffect_Add
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _0809F592
	bl _0809EAE0
_0809F592:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	add r4, sp, 0x64
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AD3B4
	bl _0809EAE0
_0809F5AE:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	movs r1, 0x1
	bl GroundMap_ExecuteEvent
	bl _0809EAE0
_0809F5BE:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	b _0809F712
_0809F5C6:
	ldr r1, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809F5D6
	lsls r0, r1, 16
	asrs r0, 16
	b _0809F5DC
_0809F5D6:
	ldr r0, _0809F5F0
	movs r3, 0
	ldrsh r0, [r0, r3]
_0809F5DC:
	adds r4, r0, 0
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809F5F4
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	b _0809F5FA
	.align 2, 0
_0809F5F0: .4byte gUnknown_2039A30
_0809F5F4:
	mov r0, r10
	movs r2, 0xC
	ldrsh r1, [r0, r2]
_0809F5FA:
	adds r6, r1, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F60E
	add r0, sp, 0x8
	movs r5, 0x1
	ldrsb r5, [r0, r5]
	b _0809F614
_0809F60E:
	mov r3, r10
	movs r5, 0xE
	ldrsb r5, [r3, r5]
_0809F614:
	adds r0, r4, 0
	bl sub_80A4D7C
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x1E
	bne _0809F62A
	movs r3, 0x1
_0809F62A:
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundMap_ExecuteStation
	ldr r1, _0809F65C
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r4
	bne _0809F642
	bl _0809EAE0
_0809F642:
	strh r4, [r1]
	bl sub_809D940
	mov r1, r9
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809F656
	bl _0809EAE0
_0809F656:
	bl _080A142C
	.align 2, 0
_0809F65C: .4byte gUnknown_2039A34
_0809F660:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2608
	adds r5, r0, 0
	lsls r2, r4, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x30
	bl sub_8001784
	cmp r0, 0
	bne _0809F68A
	movs r3, 0x6
	ldrsh r5, [r5, r3]
	b _0809F68E
_0809F68A:
	movs r0, 0x8
	ldrsh r5, [r5, r0]
_0809F68E:
	adds r0, r4, 0
	subs r0, 0x37
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x10
	bls _0809F6DC
	adds r0, r4, 0
	bl sub_80A2750
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0809F6DC
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0809F6D8
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F6C6
	ldr r1, _0809F6D4
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809F6C6:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8098E18
	bl _0809EAE0
	.align 2, 0
_0809F6D4: .4byte gUnknown_8116684
_0809F6D8:
	adds r0, r5, 0
	b _0809F712
_0809F6DC:
	movs r1, 0x1
	negs r1, r1
	adds r0, r4, 0
	bl sub_8098E18
	bl _0809EAE0
_0809F6EA:
	mov r1, r9
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0809F71C
	cmp r0, 0x1
	bgt _0809F700
	cmp r0, 0
	beq _0809F70C
	bl _0809EAE0
_0809F700:
	cmp r0, 0x2
	beq _0809F73E
	cmp r0, 0x3
	beq _0809F762
	bl _0809EAE0
_0809F70C:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
_0809F712:
	movs r1, 0
	bl GroundMap_ExecuteEvent
	bl _0809EAE0
_0809F71C:
	add r4, sp, 0x1C
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r1, r9
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundLives_ExecuteScript
	bl _0809EAE0
_0809F73E:
	add r4, sp, 0x28
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r5, r9
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	mov r1, r9
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundObject_ExecuteScript
	bl _0809EAE0
_0809F762:
	add r4, sp, 0x34
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r5, r9
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	mov r1, r9
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundEffect_ExecuteScript
	bl _0809EAE0
_0809F786:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	cmp r0, 0
	bge _0809F79E
	bl _0809EAE0
_0809F79E:
	add r1, sp, 0x6C
	bl sub_80A8BD8
	ldr r0, [sp, 0x6C]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _0809F818
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r7, sp, 0x70
	ldr r2, [r1, 0xC]
	adds r1, r7, 0
	bl _call_via_r2
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r5, sp, 0x78
	ldr r2, [r1, 0x8]
	adds r1, r5, 0
	bl _call_via_r2
	add r6, sp, 0x80
	mov r0, r8
	adds r1, r6, 0
	bl sub_80A8FD8
	add r4, sp, 0x88
	mov r0, r8
	adds r1, r4, 0
	bl sub_80A8F9C
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	adds r4, r1, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809F812
	ldr r3, _0809F82C
	adds r0, r7, 0
	adds r1, r3, 0
	adds r2, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, r4
	beq _0809F818
_0809F812:
	mov r0, r8
	bl sub_80A9090
_0809F818:
	mov r4, r9
	movs r5, 0xA
	ldrsh r0, [r4, r5]
	mov r1, r8
	bl GroundLives_ExecutePlayerScriptActionLives
	movs r0, 0x3
	bl _080A142E
	.align 2, 0
_0809F82C: .4byte gUnknown_81164DC
_0809F830:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80999E8
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F842:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80999FC
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F854:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	lsrs r2, 16
	bl sub_8099A10
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F872:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_8099A34
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F884:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_8099A48
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F896:
	ldr r0, [sp, 0x10]
	asrs r0, 16
	add r1, sp, 0x20
	movs r2, 0
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	asrs r0, 8
	adds r1, 0x1
	strb r0, [r1]
	ldr r1, [sp, 0x10]
	mov r0, sp
	adds r0, 0x22
	strb r1, [r0]
	adds r0, 0x1
	strb r2, [r0]
	ldr r2, [sp, 0x20]
	str r2, [sp, 0x1C]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x27
	beq _0809F8C6
	cmp r0, 0x28
	beq _0809F8D4
	b _0809F8E0
_0809F8C6:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	bl sub_8099A5C
	b _0809F8E0
_0809F8D4:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	bl sub_8099AFC
_0809F8E0:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F8E8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	bl sub_809A6E4
	bl _0809EAE0
_0809F8F4:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	bl sub_809A6F8
	bl _0809EAE0
_0809F900:
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	bl sub_809A738
	bl _0809EAE0
_0809F90C:
	bl sub_809A768
	lsls r0, 24
	cmp r0, 0
	bne _0809F91A
	bl _0809EAE0
_0809F91A:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809F92E:
	bl sub_809A76C
	bl _0809EAE0
_0809F936:
	bl sub_809A7B4
	bl _0809EAE0
_0809F93E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0xA
	bls _0809F94A
	bl _0809EAE0
_0809F94A:
	lsls r0, 2
	ldr r1, _0809F954
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809F954: .4byte _0809F958
	.align 2, 0
_0809F958:
	.4byte _0809F984
	.4byte _0809F992
	.4byte _0809F9A4
	.4byte _0809F9B6
	.4byte _0809F9D8
	.4byte _0809F9EA
	.4byte _0809F9FC
	.4byte _0809FA44
	.4byte _0809FA56
	.4byte _0809FA68
	.4byte _0809FAB0
_0809F984:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_809A83C
	bl _0809EAE0
_0809F992:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A2500
	bl _0809EAE0
_0809F9A4:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A2500
	bl _0809EAE0
_0809F9B6:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	add r1, sp, 0x90
	lsls r0, 16
	movs r2, 0x1
	orrs r0, r2
	str r0, [r1]
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80A2500
	bl _0809EAE0
_0809F9D8:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A252C
	bl _0809EAE0
_0809F9EA:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A252C
	bl _0809EAE0
_0809F9FC:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	add r1, sp, 0x94
	ldrh r2, [r1]
	orrs r2, r0
	str r2, [r1]
	cmp r2, 0
	blt _0809FA30
	ldr r0, _0809FA2C
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	str r2, [r1]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_80A252C
	bl _0809EAE0
	.align 2, 0
_0809FA2C: .4byte 0xffff0000
_0809FA30:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_80A2584
	bl _0809EAE0
_0809FA44:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A2558
	bl _0809EAE0
_0809FA56:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A2558
	bl _0809EAE0
_0809FA68:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	add r1, sp, 0x98
	ldrh r2, [r1]
	orrs r2, r0
	str r2, [r1]
	cmp r2, 0
	blt _0809FA9C
	ldr r0, _0809FA98
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	str r2, [r1]
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_80A2558
	bl _0809EAE0
	.align 2, 0
_0809FA98: .4byte 0xffff0000
_0809FA9C:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_80A2598
	bl _0809EAE0
_0809FAB0:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2740
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _0809FAD0
	cmp r0, 0x2
	beq _0809FAD4
	b _0809FAD8
_0809FAD0:
	movs r4, 0x1
	b _0809FAD8
_0809FAD4:
	movs r4, 0x1
	negs r4, r4
_0809FAD8:
	adds r0, r1, 0
	bl sub_8090298
	ldr r2, _0809FAF4
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	lsls r1, 2
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	bl _0809EAE0
	.align 2, 0
_0809FAF4: .4byte gUnknown_202DE30
_0809FAF8:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	asrs r1, 24
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl sub_809AC7C
	bl _0809EAE0
_0809FB10:
	ldr r0, [sp, 0xC]
	add r1, sp, 0x9C
	str r0, [r1]
	ldr r0, [sp, 0x10]
	str r0, [r1, 0x4]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_809ADD8
	bl _0809EAE0
_0809FB28:
	movs r1, 0
	ldrb r0, [r2]
	subs r0, 0x32
	cmp r0, 0x6
	bhi _0809FBBE
	lsls r0, 2
	ldr r1, _0809FB3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809FB3C: .4byte _0809FB40
	.align 2, 0
_0809FB40:
	.4byte _0809FB5C
	.4byte _0809FB6C
	.4byte _0809FB7C
	.4byte _0809FB8C
	.4byte _0809FB9C
	.4byte _0809FBAC
	.4byte _0809FBB4
_0809FB5C:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0x14]
	movs r0, 0
	bl sub_809AE90
	b _0809FBBA
_0809FB6C:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	ldr r2, [sp, 0x14]
	movs r0, 0x1
	bl sub_809AE90
	b _0809FBBA
_0809FB7C:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	ldr r2, [sp, 0x14]
	movs r0, 0x2
	bl sub_809AE90
	b _0809FBBA
_0809FB8C:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	ldr r2, [sp, 0x14]
	movs r0, 0x3
	bl sub_809AE90
	b _0809FBBA
_0809FB9C:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0x14]
	movs r0, 0x4
	bl sub_809AE90
	b _0809FBBA
_0809FBAC:
	ldr r0, [sp, 0x14]
	bl sub_809AEEC
	b _0809FBBA
_0809FBB4:
	ldr r0, [sp, 0x14]
	bl sub_809AF2C
_0809FBBA:
	lsls r0, 24
	lsrs r1, r0, 24
_0809FBBE:
	cmp r1, 0
	bne _0809FBC6
	bl _0809EAE0
_0809FBC6:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809FBDA:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0x14]
	bl sub_809AF6C
	lsls r0, 24
	cmp r0, 0
	bne _0809FBF0
	bl _0809EAE0
_0809FBF0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _0809FBFE
	bl _0809EAE0
_0809FBFE:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809FC12:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	lsls r2, 16
	asrs r2, 16
	ldr r3, [sp, 0x14]
	bl sub_809AFC8
	bl _080A1280
_0809FC2E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	bl sub_809B1D4
	bl _080A1292
_0809FC40:
	movs r0, 0
	bl _080A0654
_0809FC46:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809FC90
	adds r0, r1, 0
	bl sub_80A8D54
	cmp r0, 0
	bne _0809FC62
	bl _0809EAE0
_0809FC62:
	movs r3, 0
	ldr r2, _0809FC8C
	adds r5, r2, 0
	adds r4, r0, 0
	adds r4, 0x4C
_0809FC6C:
	adds r0, r3, r5
	adds r1, r4, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _0809FC6C
	movs r0, 0
	strb r0, [r2, 0xA]
	movs r0, 0x4
	movs r1, 0
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FC8C: .4byte gUnknown_2039D98
_0809FC90:
	ldr r2, _0809FCA0
	movs r0, 0x4
	movs r1, 0x1
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCA0: .4byte gUnknown_2039D98
_0809FCA4:
	ldr r4, _0809FCC0
	adds r0, r4, 0
	bl sub_80920B8
	movs r0, 0
	strb r0, [r4, 0xA]
	movs r0, 0x5
	movs r1, 0
	adds r2, r4, 0
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCC0: .4byte gUnknown_2039D98
_0809FCC4:
	ldr r2, _0809FCE4
	adds r3, r2, 0
	movs r1, 0
	adds r0, r2, 0
	adds r0, 0xB
_0809FCCE:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r3
	bge _0809FCCE
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	movs r0, 0x6
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCE4: .4byte gUnknown_2039D98
_0809FCE8:
	bl sub_80118A4
	bl _0809EAE0
_0809FCF0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FD00
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _0809FD02
_0809FD00:
	movs r0, 0x1E
_0809FD02:
	bl sub_80118C4
	bl _0809EAE0
_0809FD0A:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD1E
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD20
_0809FD1E:
	ldr r0, [sp, 0xC]
_0809FD20:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _0809FD34
	cmp r1, r0
	beq _0809FDA0
	adds r0, r1, 0
	bl sub_80118F0
	bl _0809EAE0
	.align 2, 0
_0809FD34: .4byte 0x000003e7
_0809FD38:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD4C
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD4E
_0809FD4C:
	ldr r0, [sp, 0xC]
_0809FD4E:
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, _0809FD68
	cmp r2, r0
	beq _0809FDA0
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	adds r0, r2, 0
	bl sub_8011900
	bl _0809EAE0
	.align 2, 0
_0809FD68: .4byte 0x000003e7
_0809FD6C:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD80
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD82
_0809FD80:
	ldr r0, [sp, 0xC]
_0809FD82:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _0809FD9C
	cmp r1, r0
	bne _0809FD90
	bl _0809EAE0
_0809FD90:
	adds r0, r1, 0
	bl sub_8011914
	bl _0809EAE0
	.align 2, 0
_0809FD9C: .4byte 0x000003e7
_0809FDA0:
	bl sub_8011924
	bl _0809EAE0
_0809FDA8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FDB8
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _0809FDBA
_0809FDB8:
	movs r0, 0x1E
_0809FDBA:
	bl sub_8011930
	bl _0809EAE0
_0809FDC2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8011974
	bl _0809EAE0
_0809FDD4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_801199C
	bl _0809EAE0
_0809FDE2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r2, r0, 16
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FDF8
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	b _0809FDFA
_0809FDF8:
	movs r1, 0x1E
_0809FDFA:
	adds r0, r2, 0
	bl sub_80119AC
	bl _0809EAE0
_0809FE04:
	mov r1, r9
	adds r1, 0x84
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, 0x1
	bne _0809FE16
	adds r0, r1, 0
	bl sub_809D568
_0809FE16:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x1C]
	movs r1, 0
	bl _call_via_r2
	bl _0809EAE0
_0809FE28:
	mov r0, r9
	adds r0, 0xC
	bl sub_809D52C
	adds r4, r0, 0
	cmp r4, 0
	bne _0809FE3A
	bl _0809EAE0
_0809FE3A:
	ldr r1, [r4]
	mov r2, r9
	ldr r0, [r2, 0x4]
	add r5, sp, 0xA4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r4]
	mov r3, r9
	ldr r0, [r3, 0x4]
	mov r4, sp
	adds r4, 0x4D
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldrb r0, [r4]
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r1, r9
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	movs r1, 0
	ldrsb r1, [r4, r1]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	bl _0809EAE0
_0809FE86:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r6, sp, 0xAC
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r4, sp, 0xB4
	add r5, sp, 0xBC
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80AD914
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r3, [r1, 0x20]
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	bl _0809EAE0
_0809FEBE:
	mov r1, r9
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	ldr r1, [sp, 0xC]
	ldr r2, [r2, 0x3C]
	bl _call_via_r2
	bl _0809EAE0
_0809FED0:
	ldr r0, [sp, 0xC]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0809FEEE
	mov r1, r9
	adds r1, 0x84
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _0809FEEE
	adds r0, r1, 0
	bl sub_809D568
_0809FEEE:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldr r1, [sp, 0xC]
	ldr r2, [r2, 0x40]
	bl _call_via_r2
	bl _0809EAE0
_0809FF00:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r9
	adds r1, 0x4A
	ldr r2, [r2, 0x14]
	bl _call_via_r2
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	cmp r1, 0
	beq _0809FF1E
	mov r0, r9
	adds r0, 0x48
	strh r1, [r0]
_0809FF1E:
	mov r5, r9
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	bl _0809EAE0
_0809FF32:
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	ldr r2, [r2, 0x34]
	bl _call_via_r2
	bl _0809EAE0
_0809FF46:
	mov r1, r9
	ldr r3, [r1]
	ldr r0, [r1, 0x4]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	add r2, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r2, r4]
	ldr r3, [r3, 0x38]
	bl _call_via_r3
	bl _0809EAE0
_0809FF62:
	mov r5, r9
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	ldr r2, [r2, 0x44]
	bl _call_via_r2
	bl _0809EAE0
_0809FF78:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	add r1, sp, 0xC4
	str r0, [r1]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	str r0, [r1, 0x4]
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	ldr r2, [r2, 0x24]
	bl _call_via_r2
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	mov r5, r10
	b _080A05EA
_0809FF9A:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	lsls r0, 8
	add r1, sp, 0xCC
	str r0, [r1]
	ldr r0, [sp, 0xC]
	lsls r0, 8
	str r0, [r1, 0x4]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	b _080A0650
_0809FFBA:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl OtherRandomCapped
	lsls r0, 8
	add r4, sp, 0xD4
	str r0, [r4]
	ldr r0, [sp, 0xC]
	bl OtherRandomCapped
	lsls r0, 8
	str r0, [r4, 0x4]
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A07B4
_0809FFE4:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0xDC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A0650
_080A0010:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r6, sp, 0xE4
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	add r4, sp, 0xEC
	add r5, sp, 0xF4
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80AD914
	ldr r0, [r5]
	ldr r1, [r4]
	subs r0, r1
	bl OtherRandomCapped
	ldr r1, [r4]
	adds r1, r0
	str r1, [r6]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x4]
	subs r0, r1
	bl OtherRandomCapped
	ldr r1, [r4, 0x4]
	adds r1, r0
	str r1, [r6, 0x4]
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r6, 0
	bl _call_via_r2
	b _080A07B4
_080A0064:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A007A
	bl _0809EAE0
_080A007A:
	add r4, sp, 0xFC
	adds r1, r4, 0
	bl sub_80A8FD8
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r4, 0
	bl _call_via_r2
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	b _080A03F0
_080A0096:
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x32
	bl sub_8001784
	add r5, sp, 0x104
	str r0, [r5]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x33
	bl sub_8001784
	str r0, [r5, 0x4]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x34
	bl sub_8001784
	adds r6, r0, 0
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x35
	bl sub_8001784
	adds r4, r0, 0
	lsls r4, 24
	asrs r4, 24
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r2, [r1, 0x28]
	adds r1, r6, 0
	bl _call_via_r2
	mov r0, r9
	adds r0, 0x4A
	strb r4, [r0]
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r1, 0x2C]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A0650
_080A010E:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r4, sp, 0x10C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r3, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x114
	add r2, sp, 0x118
	ldr r3, [r3, 0x10]
	bl _call_via_r3
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r5, sp
	adds r5, 0x4E
	ldr r2, [r1, 0x14]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	add r0, sp, 0x10C
	ldr r3, [r0]
	movs r0, 0
	movs r1, 0x32
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	ldr r3, [r4, 0x4]
	movs r0, 0
	movs r1, 0x33
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	add r0, sp, 0x114
	ldr r3, [r0]
	movs r0, 0
	movs r1, 0x34
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r3, 0
	ldrsb r3, [r5, r3]
	movs r0, 0
	movs r1, 0x35
	bl sub_800199C
	bl _0809EAE0
_080A0186:
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [sp, 0xC]
	lsls r1, 8
	ldr r2, [r2, 0x28]
	bl _call_via_r2
	b _080A07B4
_080A0198:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r2, r10
	str r0, [r2, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	str r0, [r2, 0x40]
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	str r0, [r2, 0x30]
	ldr r0, _080A01B4
	bl _080A12AE
	.align 2, 0
_080A01B4: .4byte 0x0000ffff
_080A01B8:
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x11C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r1, [sp, 0xC]
	lsls r1, 8
	add r0, sp, 0x11C
	ldr r0, [r0]
	adds r0, r1
	mov r5, r10
	str r0, [r5, 0x3C]
	ldr r1, [sp, 0x10]
	lsls r1, 8
	ldr r0, [r4, 0x4]
	adds r0, r1
	str r0, [r5, 0x40]
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r5, 0x30]
	ldr r0, _080A01EC
	b _080A05EA
	.align 2, 0
_080A01EC: .4byte 0x0000ffff
_080A01F0:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r4, r10
	str r0, [r4, 0x30]
	ldr r0, _080A021C
	b _080A0656
	.align 2, 0
_080A021C: .4byte 0x0000ffff
_080A0220:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r2, r10
	str r0, [r2, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A12AE
_080A0250:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r5, r10
	str r0, [r5, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl OtherRandomCapped
	b _080A05EA
_080A0282:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A0298
	bl _0809EAE0
_080A0298:
	mov r1, r10
	adds r1, 0x3C
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r2, r10
	str r0, [r2, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A12AE
_080A02B2:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r1, r0, 8
	mov r4, r10
	str r1, [r4, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r2, r0, 8
	str r2, [r4, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7D
	beq _080A02DC
	cmp r0, 0x83
	bne _080A0304
_080A02DC:
	mov r5, r10
	ldr r0, [r5, 0x34]
	subs r0, r1, r0
	ldr r1, [r5, 0x38]
	subs r1, r2, r1
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0300
	bl _0809F0C4
_080A0300:
	movs r0, 0x1
	b _080A05EA
_080A0304:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r3, r10
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A0310:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r5, r10
	ldr r4, [r5, 0x34]
	adds r3, r4, r0
	str r3, [r5, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	ldr r2, [r5, 0x38]
	adds r1, r2, r0
	str r1, [r5, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7E
	beq _080A0342
	cmp r0, 0x84
	bne _080A036A
_080A0342:
	subs r0, r3, r4
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	mov r3, r10
	strh r0, [r3, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0362
	bl _0809F0C4
_080A0362:
	movs r0, 0x1
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A036A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A0654
_080A0370:
	ldr r4, [sp, 0xC]
	lsls r4, 1
	subs r4, 0x1
	ldr r5, [sp, 0x10]
	lsls r5, 1
	subs r5, 0x1
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	adds r0, r4, 0
	bl OtherRandomCapped
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	subs r0, r1
	lsls r0, 8
	mov r3, r10
	ldr r1, [r3, 0x34]
	adds r1, r0
	str r1, [r3, 0x3C]
	adds r0, r5, 0
	bl OtherRandomCapped
	ldr r1, [sp, 0xC]
	subs r0, r1
	lsls r0, 8
	mov r4, r10
	ldr r3, [r4, 0x38]
	adds r2, r3, r0
	str r2, [r4, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7F
	beq _080A03C4
	cmp r0, 0x85
	bne _080A03EC
_080A03C4:
	mov r5, r10
	ldr r0, [r5, 0x3C]
	ldr r1, [r5, 0x34]
	subs r0, r1
	subs r1, r2, r3
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A03E8
	bl _0809F0C4
_080A03E8:
	movs r0, 0x1
	b _080A05EA
_080A03EC:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
_080A03F0:
	mov r3, r10
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A03F8:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	mov r5, r10
	ldr r0, [r5, 0x34]
	ldr r1, [r5, 0x38]
	mov r2, r10
	str r0, [r2, 0x3C]
	str r1, [r2, 0x40]
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	mov r1, r10
	adds r1, 0x3C
	bl sub_80AD8B4
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x80
	beq _080A042E
	cmp r0, 0x86
	bne _080A045C
_080A042E:
	mov r3, r10
	ldr r0, [r3, 0x3C]
	ldr r1, [r3, 0x34]
	subs r0, r1
	ldr r1, [r3, 0x40]
	ldr r2, [r3, 0x38]
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl __divsi3
	mov r5, r10
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0458
	bl _0809F0C4
_080A0458:
	movs r0, 0x1
	b _080A05EA
_080A045C:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A0462:
	ldr r4, [sp, 0xC]
	lsls r4, 1
	subs r4, 0x1
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r5, r10
	adds r5, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r0, [sp, 0x10]
	lsls r0, 16
	asrs r0, 16
	adds r1, r5, 0
	bl sub_80AD8B4
	adds r0, r4, 0
	bl OtherRandomCapped
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	subs r0, r1
	lsls r0, 8
	mov r5, r10
	ldr r1, [r5, 0x3C]
	adds r1, r0
	str r1, [r5, 0x3C]
	adds r0, r4, 0
	bl OtherRandomCapped
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	subs r0, r1
	lsls r0, 8
	ldr r1, [r5, 0x40]
	adds r2, r1, r0
	str r2, [r5, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x81
	beq _080A04C0
	cmp r0, 0x87
	bne _080A04EC
_080A04C0:
	mov r3, r10
	ldr r0, [r3, 0x3C]
	ldr r1, [r3, 0x34]
	subs r0, r1
	ldr r1, [r3, 0x38]
	subs r1, r2, r1
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl __divsi3
	mov r5, r10
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A04E8
	bl _0809F0C4
_080A04E8:
	movs r0, 0x1
	b _080A05EA
_080A04EC:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A04F2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	bge _080A0508
	bl _0809EAE0
_080A0508:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	mov r1, r10
	adds r1, 0x3C
	adds r0, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x82
	beq _080A052E
	cmp r0, 0x88
	bne _080A055A
_080A052E:
	mov r4, r10
	ldr r0, [r4, 0x3C]
	ldr r1, [r4, 0x34]
	subs r0, r1
	ldr r1, [r4, 0x40]
	ldr r2, [r4, 0x38]
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl __divsi3
	strh r0, [r4, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0556
	bl _0809F0C4
_080A0556:
	movs r0, 0x1
	b _080A0656
_080A055A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A0560:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r2, r10
	str r0, [r2, 0x48]
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	str r0, [r2, 0x30]
	ldr r0, _080A0578
	bl _080A12AE
	.align 2, 0
_080A0578: .4byte 0x0000ffff
_080A057C:
	ldr r1, [sp, 0xC]
	mov r0, r9
	adds r0, 0x4A
	strb r1, [r0]
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	mov r1, r10
	str r0, [r1, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	b _080A07BA
_080A05A4:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r4, sp
	adds r4, 0x4F
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r5, r10
	str r0, [r5, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A05EA:
	strh r0, [r5, 0x2A]
	bl _0809F0C4
_080A05F0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
_080A0600:
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	b _080A07B4
_080A060E:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080A0650
	add r4, sp, 0x50
	adds r1, r4, 0
	bl sub_80A9050
	movs r0, 0
	ldrsb r0, [r4, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_080A0650:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A0654:
	mov r4, r10
_080A0656:
	strh r0, [r4, 0x2A]
	bl _0809F0C4
_080A065C:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r4, sp
	adds r4, 0x51
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	b _080A0600
_080A068A:
	movs r5, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x8F
	beq _080A06CA
	cmp r0, 0x8F
	bgt _080A069E
	cmp r0, 0x8E
	beq _080A06A4
	b _080A0724
_080A069E:
	cmp r0, 0x90
	beq _080A06F8
	b _080A0724
_080A06A4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080A0724
	movs r5, 0x1
	add r1, sp, 0x124
	adds r0, r4, 0
	bl sub_80A8FD8
	add r1, sp, 0x12C
	adds r0, r4, 0
	bl sub_80A8F9C
	b _080A0724
_080A06CA:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080A0724
	movs r5, 0x1
	add r1, sp, 0x124
	bl sub_80A8FD8
	ldr r0, _080A06F4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x12C
	str r0, [r2]
	str r1, [r2, 0x4]
	b _080A0724
	.align 2, 0
_080A06F4: .4byte gUnknown_81164DC
_080A06F8:
	movs r5, 0x1
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x124
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	add r1, sp, 0x12C
	ldr r2, [r2, 0x8]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
_080A0724:
	cmp r5, 0
	beq _080A07B4
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r5, sp, 0x134
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x13C
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r7, sp, 0x124
	add r3, sp, 0x12C
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_8002DF0
	mov r1, sp
	adds r1, 0x52
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	movs r4, 0
	ldrsb r4, [r1, r4]
	adds r6, r1, 0
	cmp r4, r0
	bne _080A078C
	ldr r3, _080A07C0
	adds r0, r5, 0
	adds r1, r3, 0
	adds r2, r7, 0
	bl sub_8002D54
	strb r0, [r6]
	movs r0, 0
	ldrsb r0, [r6, r0]
	cmp r0, r4
	bne _080A078C
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r2, [r1, 0x14]
	adds r1, r6, 0
	bl _call_via_r2
_080A078C:
	movs r0, 0
	ldrsb r0, [r6, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_080A07B4:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A07B8:
	mov r1, r10
_080A07BA:
	strh r0, [r1, 0x2A]
	bl _0809F0C4
	.align 2, 0
_080A07C0: .4byte gUnknown_81164DC
_080A07C4:
	movs r0, 0
	bl _080A12AC
_080A07CA:
	ldr r0, [sp, 0xC]
	mov r1, r9
	adds r1, 0x71
	movs r2, 0
	strb r0, [r1]
	mov r3, r10
	strh r2, [r3, 0x2A]
	bl _0809F0C4
_080A07DC:
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	mov r4, sp
	adds r4, 0x53
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x71
	movs r2, 0
	strb r0, [r1]
	mov r5, r10
	strh r2, [r5, 0x2A]
	bl _0809F0C4
_080A080C:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_809D124
	bl _0809EAE0
_080A081E:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	mov r3, r9
	movs r4, 0x8
	ldrsh r0, [r3, r4]
	cmp r0, 0x2
	beq _080A0856
	cmp r0, 0x2
	bgt _080A0844
	cmp r0, 0x1
	beq _080A084C
	bl _0809EAE0
_080A0844:
	cmp r0, 0x3
	beq _080A0860
	bl _0809EAE0
_080A084C:
	movs r0, 0x1
	bl sub_809D170
	bl _0809EAE0
_080A0856:
	movs r0, 0x2
	bl sub_809D170
	bl _0809EAE0
_080A0860:
	movs r0, 0x3
	bl sub_809D170
	bl _0809EAE0
_080A086A:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x8
	ldrsh r1, [r5, r2]
	cmp r1, 0x2
	beq _080A08A0
	cmp r1, 0x2
	bgt _080A088E
	cmp r1, 0x1
	beq _080A0896
	bl _0809EAE0
_080A088E:
	cmp r1, 0x3
	beq _080A08AA
	bl _0809EAE0
_080A0896:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80A8FD8
	b _080A08B2
_080A08A0:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80AC448
	b _080A08B2
_080A08AA:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80AD360
_080A08B2:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D158
	bl _0809EAE0
_080A08BE:
	movs r0, 0x1
	movs r1, 0
	bl sub_809D170
	bl _0809EAE0
_080A08CA:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A08E2
	bl _0809EAE0
_080A08E2:
	mov r4, r9
	movs r5, 0x8
	ldrsh r0, [r4, r5]
	cmp r0, 0x2
	beq _080A090A
	cmp r0, 0x2
	bgt _080A08F8
	cmp r0, 0x1
	beq _080A0900
	bl _0809EAE0
_080A08F8:
	cmp r0, 0x3
	beq _080A0914
	bl _0809EAE0
_080A0900:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0990
_080A090A:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0990
_080A0914:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0990
_080A091E:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A095C
	cmp r1, 0x2
	bgt _080A0944
	cmp r1, 0x1
	beq _080A094C
	bl _0809EAE0
_080A0944:
	cmp r1, 0x3
	beq _080A096C
	bl _0809EAE0
_080A094C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A097A
_080A095C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A097A
_080A096C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A097A:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D190
	bl _0809F0C4
_080A0986:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0990:
	bl sub_809D1A8
	bl _0809F0C4
_080A0998:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A09B0
	bl _0809EAE0
_080A09B0:
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r0, 0x2
	beq _080A09D6
	cmp r0, 0x2
	bgt _080A09C4
	cmp r0, 0x1
	beq _080A09CC
	bl _0809EAE0
_080A09C4:
	cmp r0, 0x3
	beq _080A09E0
	bl _0809EAE0
_080A09CC:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0A5C
_080A09D6:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0A5C
_080A09E0:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0A5C
_080A09EA:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A0A28
	cmp r1, 0x2
	bgt _080A0A10
	cmp r1, 0x1
	beq _080A0A18
	bl _0809EAE0
_080A0A10:
	cmp r1, 0x3
	beq _080A0A38
	bl _0809EAE0
_080A0A18:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A0A46
_080A0A28:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A0A46
_080A0A38:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A0A46:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D1CC
	bl _0809F0C4
_080A0A52:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0A5C:
	bl sub_809D1E4
	bl _0809F0C4
_080A0A64:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A0A7C
	bl _0809EAE0
_080A0A7C:
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r0, 0x2
	beq _080A0AA2
	cmp r0, 0x2
	bgt _080A0A90
	cmp r0, 0x1
	beq _080A0A98
	bl _0809EAE0
_080A0A90:
	cmp r0, 0x3
	beq _080A0AAC
	bl _0809EAE0
_080A0A98:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0B28
_080A0AA2:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0B28
_080A0AAC:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0B28
_080A0AB6:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A0AF4
	cmp r1, 0x2
	bgt _080A0ADC
	cmp r1, 0x1
	beq _080A0AE4
	bl _0809EAE0
_080A0ADC:
	cmp r1, 0x3
	beq _080A0B04
	bl _0809EAE0
_080A0AE4:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A0B12
_080A0AF4:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A0B12
_080A0B04:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A0B12:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D208
	bl _0809F0C4
_080A0B1E:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0B28:
	bl sub_809D220
	bl _0809F0C4
_080A0B30:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl sub_8001570
	bl _0809EAE0
_080A0B42:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_80015C0
	bl _0809EAE0
_080A0B54:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	ldr r2, [sp, 0xC]
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_800226C
	bl _0809EAE0
_080A0B6C:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	asrs r2, 16
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_80022A0
	bl _0809EAE0
_080A0B88:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	ldr r3, [sp, 0x10]
	bl sub_800199C
	bl _0809EAE0
_080A0BA2:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001BB4
	bl _0809EAE0
_080A0BB4:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	add r1, sp, 0x164
	add r2, sp, 0x168
	bl sub_8001B88
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r1, sp, 0x164
	ldr r1, [r1]
	add r2, sp, 0x168
	ldr r2, [r2]
	adds r2, 0x1
	bl sub_8001BB4
	bl _0809EAE0
_080A0BDA:
	ldr r2, [sp, 0xC]
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0
	movs r1, 0x16
	bl sub_80018D8
	bl _0809EAE0
_080A0BF6:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0
	movs r1, 0x1C
	bl sub_80018D8
	bl _0809EAE0
_080A0C08:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80026E8
	bl _0809EAE0
_080A0C20:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_809733C
	bl _0809EAE0
_080A0C38:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80973A8
	bl _0809EAE0
_080A0C50:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_8097418
	bl _0809EAE0
_080A0C68:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80975A8
	bl _0809EAE0
_080A0C80:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80976F8
	bl _0809EAE0
_080A0C90:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0xC]
	movs r0, 0
	movs r3, 0x2
	bl sub_80022F8
	b _080A0E1E
_080A0CA2:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_80022F8
	lsls r0, 24
	cmp r0, 0
	bne _080A0CC0
	bl _0809EAE0
_080A0CC0:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _080A0D5C
_080A0CC8:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	asrs r2, 16
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_8002318
	lsls r0, 24
	cmp r0, 0
	bne _080A0CEA
	bl _0809EAE0
_080A0CEA:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	b _080A0E2C
_080A0CF2:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	lsrs r2, 16
	bl sub_8001784
	cmp r0, 0
	bne _080A0D0E
	bl _0809EAE0
_080A0D0E:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _080A0D5C
_080A0D16:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_8001AB0
	ldr r1, [sp, 0x10]
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	bne _080A0D38
	bl _0809EAE0
_080A0D38:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	b _080A0E2C
_080A0D40:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _080A0D58
	bl _0809EAE0
_080A0D58:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
_080A0D5C:
	mov r0, r9
	bl sub_80A242C
	mov r5, r10
	str r0, [r5, 0x4]
	bl _0809EAE0
_080A0D6A:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001D08
	b _080A0DBA
_080A0D7A:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	bne _080A0D92
	bl _0809EAE0
_080A0D92:
	b _080A0DF6
_080A0D94:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A0DA8
	bl _0809EAE0
_080A0DA8:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	b _080A132A
_080A0DAE:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8098100
_080A0DBA:
	lsls r0, 24
	cmp r0, 0
	bne _080A0DC4
	bl _0809EAE0
_080A0DC4:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	mov r0, r9
	bl sub_80A242C
	mov r2, r10
	str r0, [r2, 0x4]
	bl _0809EAE0
_080A0DD6:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80026CC
	b _080A0E1E
_080A0DE2:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_809CBA4
	cmp r0, 0
	bgt _080A0DF6
	bl _0809EAE0
_080A0DF6:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	mov r0, r9
	bl sub_80A242C
	mov r4, r10
	str r0, [r4, 0x4]
	bl _0809EAE0
_080A0E08:
	mov r5, r9
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080A0E16
	bl _0809EAE0
_080A0E16:
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	bl sub_80A8C98
_080A0E1E:
	lsls r0, 24
	cmp r0, 0
	bne _080A0E28
	bl _0809EAE0
_080A0E28:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
_080A0E2C:
	mov r0, r9
	bl sub_80A242C
	mov r3, r10
	str r0, [r3, 0x4]
	bl _0809EAE0
_080A0E3A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091130
	cmp r0, 0
	bge _080A0E4E
	bl _0809EAE0
_080A0E4E:
	bl sub_80911F8
	bl _0809EAE0
_080A0E56:
	add r0, sp, 0x8
	ldrb r2, [r0]
	adds r0, r2, 0
	subs r0, 0xC0
	cmp r0, 0xB
	bls _080A0E64
	b _080A1088
_080A0E64:
	lsls r0, 2
	ldr r1, _080A0E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0E70: .4byte _080A0E74
	.align 2, 0
_080A0E74:
	.4byte _080A0EA4
	.4byte _080A0EB6
	.4byte _080A0ECC
	.4byte _080A0EFA
	.4byte _080A0F08
	.4byte _080A0F14
	.4byte _080A0F26
	.4byte _080A0F36
	.4byte _080A0F98
	.4byte _080A1008
	.4byte _080A0F4C
	.4byte _080A107A
_080A0EA4:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl sub_8001658
	adds r1, r0, 0
	b _080A1098
_080A0EB6:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl sub_8001658
	ldr r1, [sp, 0xC]
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	b _080A0EF2
_080A0ECC:
	mov r4, r10
	adds r4, 0x50
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_8001658
	adds r5, r0, 0
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8001658
	adds r1, r0, 0
	add r0, sp, 0x8
	ldrb r2, [r0, 0x1]
	adds r0, r5, 0
_080A0EF2:
	bl FlagCalc
	adds r1, r0, 0
	b _080A1098
_080A0EFA:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	bl OtherRandomCapped
	adds r1, r0, 0
	b _080A1098
_080A0F08:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	movs r0, 0
	movs r2, 0
	b _080A0F1E
_080A0F14:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	movs r0, 0
	movs r2, 0x1
_080A0F1E:
	bl sub_8001784
	adds r1, r0, 0
	b _080A1098
_080A0F26:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A8C2C
	lsls r0, 16
	asrs r1, r0, 16
	b _080A1098
_080A0F36:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	add r4, sp, 0x54
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0
	ldrsb r1, [r4, r1]
	b _080A1098
_080A0F4C:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	movs r3, 0xB6
	lsls r3, 1
	add r3, sp
	mov r8, r3
	ldr r2, [r1, 0xC]
	mov r1, r8
	bl _call_via_r2
	add r6, sp, 0x16C
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	add r4, sp, 0x174
	str r0, [r4]
	str r1, [r4, 0x4]
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r5, r4, 0
	adds r1, r5, 0
	bl sub_80AD8B4
	ldr r1, [r4]
	ldr r0, [r6]
	subs r1, r0
	add r0, sp, 0x17C
	str r1, [r0]
	ldr r1, [r5, 0x4]
	mov r4, r8
	ldr r0, [r4, 0x4]
	subs r1, r0
	add r0, sp, 0x17C
	str r1, [r0, 0x4]
	bl sub_8002C60
	b _080A106A
_080A0F98:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r6, r0, 16
	cmp r6, 0
	blt _080A1074
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	movs r2, 0xC2
	lsls r2, 1
	add r2, sp
	mov r8, r2
	ldr r2, [r1, 0xC]
	mov r1, r8
	bl _call_via_r2
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r5, sp, 0x18C
	ldr r2, [r1, 0x8]
	adds r1, r5, 0
	bl _call_via_r2
	add r7, sp, 0x194
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80A8FD8
	add r4, sp, 0x19C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80A8F9C
	mov r0, r8
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A1098
	ldr r3, _080A1004
	mov r0, r8
	adds r1, r3, 0
	adds r2, r7, 0
	b _080A1066
	.align 2, 0
_080A1004: .4byte gUnknown_81164DC
_080A1008:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r7, r0, 16
	cmp r7, 0
	blt _080A1074
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r6, sp, 0x1A4
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x1AC
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0x1B4
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80A8FD8
	ldr r7, _080A1070
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A1098
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	adds r3, r7, 0
_080A1066:
	bl sub_8002D54
_080A106A:
	lsls r0, 24
	asrs r1, r0, 24
	b _080A1098
	.align 2, 0
_080A1070: .4byte gUnknown_81164DC
_080A1074:
	movs r1, 0x1
	negs r1, r1
	b _080A1098
_080A107A:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_809CC90
	adds r1, r0, 0
	b _080A1098
_080A1088:
	ldr r0, _080A1090
	ldr r1, _080A1094
	bl FatalError
	.align 2, 0
_080A1090: .4byte gUnknown_81166B4
_080A1094: .4byte gUnknown_81166C0
_080A1098:
	mov r0, r9
	bl sub_80A2460
	b _080A1330
_080A10A0:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_8001658
	adds r2, r0, 0
	mov r3, r10
	strh r2, [r3, 0x28]
	ldr r1, [r3, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _080A10DE
	lsls r0, r2, 16
	asrs r3, r0, 16
_080A10C0:
	adds r2, r1, 0
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080A10CE
	bl _0809F0C4
_080A10CE:
	adds r0, r1, 0
	adds r0, 0x10
	mov r5, r10
	str r0, [r5, 0x4]
	adds r1, r0, 0
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD0
	beq _080A10C0
_080A10DE:
	mov r1, r10
	ldr r0, [r1, 0x4]
	ldrb r0, [r0]
	cmp r0, 0xD1
	beq _080A10EC
	bl _0809EAE0
_080A10EC:
	ldr r0, _080A10F4
	strh r0, [r1, 0x28]
	bl _0809F0C4
	.align 2, 0
_080A10F4: .4byte 0x0000ffff
_080A10F8:
	ldr r7, [sp, 0x14]
	ldr r1, _080A11F0
	movs r0, 0
	str r0, [r1]
	mov r2, r10
	strh r0, [r2, 0x28]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0xD8
	bgt _080A1176
	cmp r0, 0xD6
	blt _080A1176
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0x10]
	lsls r1, 16
	asrs r1, 16
	bl sub_8001658
	adds r3, r0, 0
	mov r4, r10
	ldr r1, [r4, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _080A114E
_080A112A:
	adds r2, r1, 0
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	cmp r0, r3
	bne _080A1136
	ldr r7, [r2, 0xC]
_080A1136:
	adds r0, r1, 0
	adds r0, 0x10
	mov r1, r10
	str r0, [r1, 0x4]
	ldrh r1, [r1, 0x28]
	adds r1, 0x1
	mov r4, r10
	strh r1, [r4, 0x28]
	adds r1, r0, 0
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD0
	beq _080A112A
_080A114E:
	mov r5, r10
	ldr r1, [r5, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD1
	bne _080A1176
_080A1158:
	cmp r7, 0
	bne _080A115E
	ldr r7, [r1, 0xC]
_080A115E:
	mov r0, r10
	ldr r2, [r0, 0x4]
	adds r1, r2, 0
	adds r1, 0x10
	str r1, [r0, 0x4]
	ldrh r0, [r0, 0x28]
	adds r0, 0x1
	mov r3, r10
	strh r0, [r3, 0x28]
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD1
	beq _080A1158
_080A1176:
	cmp r7, 0
	bne _080A117C
	ldr r7, _080A11F4
_080A117C:
	mov r4, r10
	ldr r5, [r4, 0x4]
	ldrb r0, [r5]
	cmp r0, 0xD9
	bne _080A11B8
	ldr r0, _080A11F8
	mov r8, r0
	ldr r6, _080A11F0
	movs r1, 0x4
	add r1, r8
	mov r12, r1
_080A1192:
	ldr r1, [r6]
	lsls r2, r1, 3
	mov r4, r8
	adds r3, r2, r4
	adds r4, r5, 0
	ldr r0, [r4, 0xC]
	str r0, [r3]
	add r2, r12
	adds r1, 0x1
	str r1, [r2]
	str r1, [r6]
	adds r0, r4, 0
	adds r0, 0x10
	mov r5, r10
	str r0, [r5, 0x4]
	adds r5, r0, 0
	ldrb r0, [r4, 0x10]
	cmp r0, 0xD9
	beq _080A1192
_080A11B8:
	ldr r0, _080A11F0
	ldr r1, [r0]
	cmp r1, 0
	bgt _080A11C4
	bl _0809EAE0
_080A11C4:
	ldr r3, _080A11F8
	lsls r2, r1, 3
	adds r1, r2, r3
	movs r0, 0
	str r0, [r1]
	adds r0, r3, 0x4
	adds r2, r0
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r2]
	add r0, sp, 0x8
	ldrb r0, [r0]
	subs r0, 0xD2
	cmp r0, 0x6
	bhi _080A1280
	lsls r0, 2
	ldr r1, _080A11FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A11F0: .4byte gUnknown_203B4AC
_080A11F4: .4byte gUnknown_81166D8
_080A11F8: .4byte gUnknown_2039D50
_080A11FC: .4byte _080A1200
	.align 2, 0
_080A1200:
	.4byte _080A121C
	.4byte _080A121C
	.4byte _080A123E
	.4byte _080A1260
	.4byte _080A121C
	.4byte _080A123E
	.4byte _080A1260
_080A121C:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0
	bl sub_809B028
	b _080A1280
_080A123E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0x1
	bl sub_809B028
	b _080A1280
_080A1260:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0x2
	bl sub_809B028
_080A1280:
	mov r0, r9
	movs r1, 0x1
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	bne _080A1292
	bl _0809EAE0
_080A1292:
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	bl _0809F0C4
_080A129E:
	mov r0, r9
	movs r1, 0x1
	bl sub_809D8EC
	b _080A130A
_080A12A8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
_080A12AC:
	mov r2, r10
_080A12AE:
	strh r0, [r2, 0x2A]
	bl _0809F0C4
_080A12B4:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	ldr r0, [sp, 0xC]
	subs r0, r1
	bl OtherRandomCapped
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	adds r1, r0
	mov r4, r10
	strh r1, [r4, 0x2A]
	bl _0809F0C4
_080A12D0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r5, r10
	strh r0, [r5, 0x28]
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	mov r0, r9
	bl sub_809D8EC
	b _080A130A
_080A12E6:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	bl sub_809D9B8
	bl _0809EAE0
_080A12F4:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r4, r10
	strh r0, [r4, 0x28]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	ldrb r2, [r0, 0x1]
	mov r0, r9
	bl sub_809DA08
_080A130A:
	lsls r0, 24
_080A130C:
	cmp r0, 0
	bne _080A1314
	bl _0809EAE0
_080A1314:
	bl _0809F0C4
_080A1318:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1324:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
_080A132A:
	mov r0, r9
	bl sub_80A242C
_080A1330:
	mov r1, r10
	str r0, [r1, 0x4]
	bl _0809EAE0
_080A1338:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1344:
	ldr r2, _080A1364
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	mov r1, r10
	str r0, [r1, 0x4]
	str r0, [r1, 0x8]
	bl _0809EAE0
	.align 2, 0
_080A1364: .4byte gUnknown_812F1F8
_080A1368:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1374:
	ldr r0, _080A138C
	movs r5, 0
	ldrsh r1, [r0, r5]
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _080A1390
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	b _080A1396
	.align 2, 0
_080A138C: .4byte gUnknown_2039A34
_080A1390:
	mov r4, r10
	movs r5, 0xC
	ldrsh r2, [r4, r5]
_080A1396:
	adds r5, r2, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _080A13AA
	add r0, sp, 0x8
	movs r4, 0x1
	ldrsb r4, [r0, r4]
	b _080A13B0
_080A13AA:
	mov r0, r10
	movs r4, 0xE
	ldrsb r4, [r0, r4]
_080A13B0:
	add r0, sp, 0x1C
	adds r2, r5, 0
	adds r3, r4, 0
	bl GroundMap_GetStationScript
	ldr r0, [sp, 0x1C]
	mov r1, r10
	str r0, [r1, 0x4]
	str r0, [r1, 0x8]
	strh r5, [r1, 0xC]
	strb r4, [r1, 0xE]
	bl _0809EAE0
_080A13CA:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A4D7C
	ldr r4, _080A13F4
	strh r0, [r4]
	bl sub_809D940
	movs r3, 0
	ldrsh r0, [r4, r3]
	bl GroundMap_ExecuteEnter
	bl _0809EAE0
	.align 2, 0
_080A13F4: .4byte gUnknown_2039A34
_080A13F8:
	movs r0, 0
	mov r4, r10
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	bl _0809EAE0
_080A1404:
	mov r5, r10
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _080A1410
_080A140C:
	movs r0, 0
	b _080A142E
_080A1410:
	mov r0, r10
	adds r0, 0x4
	mov r1, r10
	adds r1, 0x10
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	movs r0, 0
	mov r5, r10
	str r0, [r5, 0x10]
	str r0, [r5, 0x14]
	bl _0809EAE0
_080A1428:
	movs r0, 0x1
	b _080A142E
_080A142C:
	movs r0, 0x4
_080A142E:
	add sp, 0x1BC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ExecuteScriptCommand

	thumb_func_start sub_80A1440
sub_80A1440:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A14E8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A1440

	thumb_func_start GroundScript_ExecuteTrigger
GroundScript_ExecuteTrigger:
	push {r4,r5,lr}
	sub sp, 0xF4
	lsls r0, 16
	asrs r4, r0, 16
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	ldr r1, _080A14C8
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0xB
	bne _080A14C4
	add r5, sp, 0x10
	ldr r1, _080A14CC
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_809D600
	movs r0, 0
	add r1, sp, 0x4
	adds r2, r4, 0
	bl sub_809D710
	ldr r3, _080A14D0
	adds r0, r5, 0
	movs r1, 0
	add r2, sp, 0x4
	bl GroundScript_ExecutePP
	add r1, sp, 0x44
	add r0, sp, 0x38
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, _080A14D4
	str r0, [r5, 0x34]
	str r0, [r5, 0x38]
	ldr r1, _080A14D8
	adds r0, r5, 0
	bl HandleAction
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r5, 0
	bl sub_809D648
	cmp r4, 0
	beq _080A14DC
_080A14C4:
	movs r0, 0
	b _080A14DE
	.align 2, 0
_080A14C8: .4byte gUnknown_812F1F8
_080A14CC: .4byte gUnknown_8116488
_080A14D0: .4byte gUnknown_81166F8
_080A14D4: .4byte gUnknown_81164E4
_080A14D8: .4byte gUnknown_8116704
_080A14DC:
	movs r0, 0x1
_080A14DE:
	add sp, 0xF4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GroundScript_ExecuteTrigger

	thumb_func_start sub_80A14E8
sub_80A14E8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _080A1514
	add sp, r4
	adds r6, r0, 0
	adds r5, r2, 0
	adds r7, r3, 0
	lsls r1, 24
	lsrs r1, 24
	subs r0, r1, 0x1
	cmp r0, 0x49
	bls _080A1508
	bl _080A236A
_080A1508:
	lsls r0, 2
	ldr r1, _080A1518
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A1514: .4byte 0xfffffc80
_080A1518: .4byte _080A151C
	.align 2, 0
_080A151C:
	.4byte _080A1644
	.4byte _080A164C
	.4byte _080A1672
	.4byte _080A167A
	.4byte _080A1680
	.4byte _080A1688
	.4byte _080A1690
	.4byte _080A1698
	.4byte _080A169E
	.4byte _080A16C6
	.4byte _080A1730
	.4byte _080A1756
	.4byte _080A178C
	.4byte _080A1792
	.4byte _080A17C0
	.4byte _080A17C6
	.4byte _080A1800
	.4byte _080A1814
	.4byte _080A1824
	.4byte _080A1840
	.4byte _080A185E
	.4byte _080A18C2
	.4byte _080A18E2
	.4byte _080A18F2
	.4byte _080A1904
	.4byte _080A197C
	.4byte _080A1988
	.4byte _080A19DC
	.4byte _080A19FC
	.4byte _080A1A0E
	.4byte _080A1A18
	.4byte _080A1A70
	.4byte _080A1AF8
	.4byte _080A1B20
	.4byte _080A1B36
	.4byte _080A1B58
	.4byte _080A1B64
	.4byte _080A1BD8
	.4byte _080A1BE4
	.4byte _080A1C30
	.4byte _080A1C84
	.4byte _080A1DEC
	.4byte _080A1E30
	.4byte _080A1E3C
	.4byte _080A1ED0
	.4byte _080A1ED6
	.4byte _080A1F28
	.4byte _080A1F3C
	.4byte _080A1F44
	.4byte _080A1F50
	.4byte _080A1F80
	.4byte _080A1FDA
	.4byte _080A202C
	.4byte _080A2054
	.4byte _080A2060
	.4byte _080A204A
	.4byte _080A206C
	.4byte _080A2076
	.4byte _080A207C
	.4byte _080A2082
	.4byte _080A20D4
	.4byte _080A20F4
	.4byte _080A21E4
	.4byte _080A228C
	.4byte _080A229E
	.4byte _080A2298
	.4byte _080A22AE
	.4byte _080A22CC
	.4byte _080A22E4
	.4byte _080A2304
	.4byte _080A2320
	.4byte _080A232E
	.4byte _080A233A
	.4byte _080A2346
_080A1644:
	bl sub_8098C58
	bl _080A236A
_080A164C:
	bl sub_8011C34
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080A1660
	bl Random
	bl sub_8011C40
_080A1660:
	movs r0, 0x1
	bl sub_8011C28
	bl sub_8001064
	bl sub_809965C
	bl _080A236A
_080A1672:
	bl sub_8098CC8
	bl _080A236A
_080A167A:
	bl sub_80961D8
	b _080A1804
_080A1680:
	bl sub_8096028
	bl _080A236A
_080A1688:
	bl sub_80963FC
	bl _080A236A
_080A1690:
	bl sub_8096488
	bl _080A236A
_080A1698:
	bl sub_80964B4
	b _080A1804
_080A169E:
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A16B0
	bl sub_808D4B0
	b _080A16B4
_080A16B0:
	bl sub_808D500
_080A16B4:
	lsls r0, 24
	lsrs r4, r0, 24
	bl nullsub_104
	negs r0, r4
	orrs r0, r4
	lsrs r0, 31
	bl _080A236C
_080A16C6:
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080A16D2
	bl _080A236A
_080A16D2:
	movs r2, 0xE
	ldrsh r0, [r6, r2]
	add r1, sp, 0x314
	bl sub_80A8C4C
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _080A16E8
	bl _080A236A
_080A16E8:
	add r0, sp, 0x314
	ldrb r0, [r0]
	cmp r0, 0x44
	bne _080A16FC
	movs r0, 0x82
	lsls r0, 1
	cmp r1, r0
	bne _080A16FC
	bl _080A203C
_080A16FC:
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_80A90C8
	lsls r0, 16
	ldr r1, _080A172C
	asrs r0, 14
	adds r0, r1
	ldr r1, [r0]
	add r0, sp, 0x4
	bl strcpy
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0x4
	bl sub_809AE90
_080A171E:
	lsls r0, 24
_080A1720:
	cmp r0, 0
	beq _080A1726
	b _080A1EBE
_080A1726:
	bl _080A236A
	.align 2, 0
_080A172C: .4byte gUnknown_813237C
_080A1730:
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2740
	lsls r0, 24
	lsrs r0, 24
	bl sub_80969D0
	movs r1, 0
	cmp r0, 0
	ble _080A1750
	movs r1, 0x1
_080A1750:
	adds r0, r1, 0
	bl _080A236C
_080A1756:
	add r4, sp, 0x104
	adds r0, r4, 0
	bl sub_8099394
	lsls r0, 24
	cmp r0, 0
	bne _080A1768
	bl _080A236A
_080A1768:
	ldr r0, _080A1788
	ldr r1, [r0]
	ldrb r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r1, r0
	adds r1, 0x2C
	movs r0, 0
	ldrsb r0, [r1, r0]
_080A177C:
	cmp r0, 0
	ble _080A1782
	b _080A1EBE
_080A1782:
	bl _080A236A
	.align 2, 0
_080A1788: .4byte gUnknown_203B480
_080A178C:
	bl sub_8097640
	b _080A1804
_080A1792:
	movs r5, 0x11
_080A1794:
	lsls r4, r5, 16
	asrs r0, r4, 16
	bl sub_809758C
	lsls r0, 24
	cmp r0, 0
	beq _080A17B6
	lsrs r4, 16
	movs r0, 0
	movs r1, 0x2F
	adds r2, r4, 0
	bl sub_8001784
	cmp r0, 0
	bne _080A17B6
	bl _080A234E
_080A17B6:
	adds r5, 0x1
	cmp r5, 0x16
	ble _080A1794
	bl _080A236A
_080A17C0:
	bl sub_80964E4
	b _080A1804
_080A17C6:
	movs r4, 0x8
	ldrsh r0, [r6, r4]
	cmp r0, 0x1
	beq _080A17D2
	bl _080A236A
_080A17D2:
	movs r5, 0xA
	ldrsh r0, [r6, r5]
	cmp r0, 0
	beq _080A17DE
	bl _080A236A
_080A17DE:
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080A17EA
	bl _080A236A
_080A17EA:
	movs r2, 0xA
	ldrsh r4, [r6, r2]
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_80A8E9C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_80A87E0
	b _080A171E
_080A1800:
	bl sub_80A8D20
_080A1804:
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bl _080A236C
_080A1814:
	ldr r0, _080A1820
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 2
	ands r0, r1
	b _080A1720
	.align 2, 0
_080A1820: .4byte gUnknown_20255F0
_080A1824:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_80A8D54
	cmp r0, 0
	bne _080A1834
	bl _080A236A
_080A1834:
	ldrh r0, [r0]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	bl _080A236C
_080A1840:
	movs r4, 0x8
	ldrsh r0, [r6, r4]
	cmp r0, 0x1
	beq _080A184C
	bl _080A236A
_080A184C:
	movs r5, 0xA
	ldrsh r0, [r6, r5]
	bl sub_80A8BFC
	lsls r0, 16
	asrs r0, 16
	bl sub_808DB48
	b _080A171E
_080A185E:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _080A1872
	bl _080A236A
_080A1872:
	lsls r4, r7, 8
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	add r7, sp, 0x318
	ldr r2, [r1, 0xC]
	adds r1, r7, 0
	bl _call_via_r2
	add r6, sp, 0x320
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80A8FD8
	add r0, sp, 0x318
	ldr r3, [r0]
	subs r1, r3, r4
	add r0, sp, 0x320
	ldr r2, [r0]
	cmp r1, r2
	ble _080A189E
	bl _080A236A
_080A189E:
	adds r0, r3, r4
	cmp r0, r2
	bge _080A18A8
	bl _080A236A
_080A18A8:
	ldr r2, [r7, 0x4]
	subs r0, r2, r4
	ldr r1, [r6, 0x4]
	cmp r0, r1
	ble _080A18B6
	bl _080A236A
_080A18B6:
	adds r0, r2, r4
	cmp r0, r1
	blt _080A18BE
	b _080A1EBE
_080A18BE:
	bl _080A236A
_080A18C2:
	movs r0, 0x1
	bl sub_80A8D54
	cmp r0, 0
	bne _080A18D0
	bl _080A236A
_080A18D0:
	adds r1, r0, 0
	adds r1, 0x4C
	movs r2, 0
	adds r0, 0x55
_080A18D8:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _080A18D8
	b _080A1EBE
_080A18E2:
	movs r0, 0xC
	bl sub_80925EC
	movs r0, 0x12
	bl sub_80925EC
	bl _080A236A
_080A18F2:
	ldr r0, _080A1900
	movs r1, 0x3C
_080A18F6:
	movs r2, 0xA
	bl sub_80A8F50
	bl _080A236A
	.align 2, 0
_080A1900: .4byte gUnknown_2039D98
_080A1904:
	movs r0, 0x51
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
	add r1, sp, 0x4
	ldr r0, _080A1970
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r4, sp, 0x2C
	adds r0, r4, 0
	add r1, sp, 0x4
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A193C
	b _080A1EBE
_080A193C:
	movs r3, 0
	ldr r1, _080A1974
	mov r8, r1
	lsls r6, r5, 2
	ldr r2, _080A1978
	adds r4, r0, 0
	adds r4, 0x4C
	mov r7, r8
_080A194C:
	adds r0, r4, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _080A194C
_080A195A:
	adds r0, r6, r5
	lsls r0, 4
	adds r0, r2
	mov r1, r8
	movs r2, 0xA
	bl sub_80922B4
_080A1968:
	bl sub_8097848
	bl _080A236A
	.align 2, 0
_080A1970: .4byte gUnknown_8116710
_080A1974: .4byte gUnknown_2039D98
_080A1978: .4byte gUnknown_202E2B8
_080A197C:
	ldr r0, _080A1984
	movs r1, 0x53
	b _080A18F6
	.align 2, 0
_080A1984: .4byte gUnknown_2039D98
_080A1988:
	ldr r0, _080A19D4
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
	add r1, sp, 0x84
	adds r2, r1, 0
	ldr r0, _080A19D8
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0xAC
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	adds r4, r0, 0
	cmp r4, 0
	bne _080A19C2
	b _080A1EBE
_080A19C2:
	bl sub_8097848
	ldrh r1, [r4]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r4]
	bl _080A236A
	.align 2, 0
_080A19D4: .4byte 0x00000183
_080A19D8: .4byte gUnknown_8116738
_080A19DC:
	ldr r0, _080A19F8
	movs r1, 0
	bl sub_808D434
	adds r2, r0, 0
	cmp r2, 0
	bne _080A19EC
	b _080A1EBE
_080A19EC:
	ldrh r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r2]
	bl _080A236A
	.align 2, 0
_080A19F8: .4byte 0x00000183
_080A19FC:
	movs r0, 0x82
	lsls r0, 1
_080A1A00:
	bl sub_808D278
	cmp r0, 0
	bne _080A1A0A
	b _080A1EBE
_080A1A0A:
	bl _080A236A
_080A1A0E:
	ldr r0, _080A1A14
	movs r1, 0x7C
	b _080A18F6
	.align 2, 0
_080A1A14: .4byte gUnknown_2039D98
_080A1A18:
	add r1, sp, 0x108
	adds r2, r1, 0
	ldr r0, _080A1A64
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x130
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1A42
	b _080A1EBE
_080A1A42:
	movs r3, 0
	ldr r4, _080A1A68
	mov r8, r4
	lsls r6, r5, 2
	ldr r2, _080A1A6C
	adds r4, r0, 0
	adds r4, 0x4C
	mov r7, r8
_080A1A52:
	adds r0, r4, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _080A1A52
	b _080A195A
	.align 2, 0
_080A1A64: .4byte gUnknown_8116760
_080A1A68: .4byte gUnknown_2039D98
_080A1A6C: .4byte gUnknown_202E2B8
_080A1A70:
	movs r0, 0x9E
	movs r1, 0x1
	bl sub_80026E8
	movs r0, 0x91
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	bne _080A1A9A
	ldr r3, _080A1AEC
	str r0, [sp]
	movs r0, 0x91
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	beq _080A1A9A
	bl sub_8097848
_080A1A9A:
	movs r0, 0x92
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	bne _080A1ABC
	ldr r3, _080A1AF0
	str r0, [sp]
	movs r0, 0x92
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	beq _080A1ABC
	bl sub_8097848
_080A1ABC:
	movs r0, 0x90
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	beq _080A1ACC
	bl _080A236A
_080A1ACC:
	ldr r3, _080A1AF4
	str r0, [sp]
	movs r0, 0x90
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	bne _080A1AE2
	bl _080A236A
_080A1AE2:
	bl sub_8097848
	bl _080A236A
	.align 2, 0
_080A1AEC: .4byte gUnknown_8116788
_080A1AF0: .4byte gUnknown_811678C
_080A1AF4: .4byte gUnknown_8116790
_080A1AF8:
	movs r0, 0x90
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	bne _080A1B08
	bl _080A236A
_080A1B08:
	movs r0, 0x91
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	bne _080A1B18
	bl _080A236A
_080A1B18:
	movs r0, 0x92
	bl sub_808E734
	b _080A171E
_080A1B20:
	bl sub_808D33C
	ldrh r0, [r0, 0x8]
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080A1B32
	b _080A1EBE
_080A1B32:
	bl _080A236A
_080A1B36:
	bl sub_808D33C
	cmp r0, 0
	beq _080A1B4A
	movs r5, 0x8
	ldrsh r1, [r0, r5]
	ldr r0, _080A1B54
	cmp r1, r0
	bne _080A1B4A
	b _080A203C
_080A1B4A:
	ldr r0, _080A1B54
	bl sub_8098134
	b _080A171E
	.align 2, 0
_080A1B54: .4byte 0x00000113
_080A1B58:
	ldr r0, _080A1B60
	movs r1, 0x79
	b _080A18F6
	.align 2, 0
_080A1B60: .4byte gUnknown_2039D98
_080A1B64:
	ldr r4, _080A1BCC
	adds r0, r4, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1B88
	adds r0, r4, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
_080A1B88:
	add r1, sp, 0x188
	adds r2, r1, 0
	ldr r0, _080A1BD0
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r0!, {r4-r6}
	stm r2!, {r4-r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x1B0
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1BB2
	b _080A1EBE
_080A1BB2:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1BD4
_080A1BBA:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1BBA
	b _080A1968
	.align 2, 0
_080A1BCC: .4byte 0x00000199
_080A1BD0: .4byte gUnknown_8116794
_080A1BD4: .4byte gUnknown_2039D98
_080A1BD8:
	ldr r0, _080A1BE0
	movs r1, 0x7A
	b _080A18F6
	.align 2, 0
_080A1BE0: .4byte gUnknown_2039D98
_080A1BE4:
	add r1, sp, 0x208
	adds r2, r1, 0
	ldr r0, _080A1C28
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x230
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1C0E
	b _080A1EBE
_080A1C0E:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1C2C
_080A1C16:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1C16
	b _080A1968
	.align 2, 0
_080A1C28: .4byte gUnknown_81167BC
_080A1C2C: .4byte gUnknown_2039D98
_080A1C30:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080A1C70
	ldr r0, _080A1C64
	ldrb r4, [r0, 0x2]
	adds r0, r4, 0
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _080A1C4A
	b _080A236A
_080A1C4A:
	ldr r0, _080A1C68
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r1, r0, r1
	ldrh r2, [r1]
	ldr r0, _080A1C6C
	cmp r2, r0
	bls _080A1C5E
	b _080A236A
_080A1C5E:
	adds r0, r2, 0x1
	strh r0, [r1]
	b _080A236A
	.align 2, 0
_080A1C64: .4byte gUnknown_81167E4
_080A1C68: .4byte gUnknown_203B460
_080A1C6C: .4byte 0x000003e6
_080A1C70:
	ldr r0, _080A1C80
	ldrb r0, [r0, 0x2]
	movs r1, 0
	bl sub_809124C
	bl sub_80910B4
	b _080A236A
	.align 2, 0
_080A1C80: .4byte gUnknown_81167E4
_080A1C84:
	movs r0, 0xD1
	lsls r0, 1
	bl RandomCapped
	adds r0, 0x1
	lsls r0, 16
	asrs r5, r0, 16
	movs r0, 0x20
	bl RandomCapped
	adds r4, r0, 0
	movs r7, 0xD2
	lsls r7, 1
	movs r6, 0
	ldr r0, _080A1DE0
	mov r8, r0
_080A1CA4:
	adds r0, r5, 0x1
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, r8
	ble _080A1CB0
	movs r5, 0x1
_080A1CB0:
	subs r7, 0x1
	cmp r7, 0
	bge _080A1CCC
	cmp r6, 0
	bne _080A1CBC
	b _080A2360
_080A1CBC:
	cmp r4, r6
	blt _080A1CCC
	adds r0, r6, 0
	bl RandomCapped
	adds r4, r0, 0
	movs r7, 0xD2
	lsls r7, 1
_080A1CCC:
	adds r0, r5, 0
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080A1CA4
	ldr r0, _080A1DE4
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0xB
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0xD
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x88
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x67
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x23
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x3
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	cmp r5, r8
	beq _080A1CA4
	cmp r5, 0x96
	beq _080A1CA4
	subs r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	cmp r5, 0x97
	beq _080A1CA4
	subs r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x8C
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x2
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x82
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x83
	cmp r5, r0
	beq _080A1CA4
	adds r0, r5, 0
	bl sub_80981DC
	lsls r0, 24
	cmp r0, 0
	beq _080A1CA4
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _080A1D9E
	adds r0, r5, 0
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	bne _080A1CA4
	adds r0, r5, 0
	bl sub_808D278
	cmp r0, 0
	beq _080A1CA4
_080A1D9E:
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	blt _080A1DA8
	b _080A1CA4
_080A1DA8:
	movs r0, 0
	movs r1, 0x1F
	adds r2, r5, 0
	bl sub_80018D8
	ldr r4, _080A1DE8
	adds r0, r5, 0
	bl sub_808DBA8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
	b _080A203C
	.align 2, 0
_080A1DE0: .4byte 0x000001a3
_080A1DE4: .4byte 0x0000019b
_080A1DE8: .4byte gUnknown_202E628
_080A1DEC:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r5, r0, 16
	ldr r4, _080A1E2C
	adds r0, r5, 0
	bl sub_808DBA8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	cmp r5, 0
	bne _080A1E14
	b _080A236A
_080A1E14:
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
	b _080A203C
	.align 2, 0
_080A1E2C: .4byte gUnknown_202E628
_080A1E30:
	ldr r0, _080A1E38
	movs r1, 0x20
	b _080A18F6
	.align 2, 0
_080A1E38: .4byte gUnknown_2039D98
_080A1E3C:
	cmp r5, 0
	bne _080A1E42
	b _080A2360
_080A1E42:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r5, r0, 16
	adds r6, r5, 0
	ldr r4, _080A1EC4
	adds r0, r5, 0
	bl sub_808DBA8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	cmp r5, 0
	bne _080A1E6C
	b _080A236A
_080A1E6C:
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1E8E
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
_080A1E8E:
	ldr r3, _080A1EC8
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	bne _080A1EA4
	b _080A236A
_080A1EA4:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1ECC
_080A1EAC:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1EAC
	bl sub_8097848
_080A1EBE:
	movs r0, 0x1
	b _080A236C
	.align 2, 0
_080A1EC4: .4byte gUnknown_202E628
_080A1EC8: .4byte gUnknown_81167E8
_080A1ECC: .4byte gUnknown_2039D98
_080A1ED0:
	bl sub_809211C
	b _080A177C
_080A1ED6:
	bl sub_8092178
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_809211C
	cmp r0, 0
	bgt _080A1EE8
	b _080A236A
_080A1EE8:
	bl sub_8092158
	bl sub_8092178
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	bl sub_80921A8
	adds r1, r0, 0
	ldr r4, _080A1F30
	adds r0, r4, 0
	bl strcpy
	adds r0, r5, 0
	bl sub_80921A8
	adds r1, r0, 0
	adds r4, 0x50
	adds r0, r4, 0
	bl strcpy
	movs r1, 0x1
	negs r1, r1
	ldr r2, _080A1F34
	movs r0, 0
	bl sub_809AE90
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
_080A1F28:
	ldr r0, _080A1F38
	bl sub_80913A0
	b _080A236A
	.align 2, 0
_080A1F30: .4byte gUnknown_202DE58
_080A1F34: .4byte gUnknown_81167EC
_080A1F38: .4byte 0x00002710
_080A1F3C:
	ldr r0, _080A1F40
	b _080A1A00
	.align 2, 0
_080A1F40: .4byte 0x00000133
_080A1F44:
	ldr r0, _080A1F4C
	movs r1, 0x52
	b _080A18F6
	.align 2, 0
_080A1F4C: .4byte gUnknown_2039D98
_080A1F50:
	add r1, sp, 0x288
	adds r2, r1, 0
	ldr r0, _080A1F7C
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x2B0
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	beq _080A1EBE
	b _080A1968
	.align 2, 0
_080A1F7C: .4byte gUnknown_811681C
_080A1F80:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x12
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	bne _080A1F94
	b _080A236A
_080A1F94:
	movs r0, 0
	movs r1, 0xF
	bl sub_8001658
	cmp r0, 0x4
	bne _080A1FA2
	b _080A236A
_080A1FA2:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	bl sub_8001784
	cmp r0, 0
	ble _080A1FB2
	b _080A236A
_080A1FB2:
	movs r0, 0x80
	lsls r0, 1
	bl OtherRandomCapped
	cmp r0, 0
	bne _080A1FCC
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	movs r3, 0x4
	bl sub_800199C
	b _080A1EBE
_080A1FCC:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	movs r3, 0x1
	bl sub_800199C
	b _080A236A
_080A1FDA:
	ldr r6, _080A200C
	ldr r7, _080A2010
	movs r5, 0x2
_080A1FE0:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080A2018
	ldrb r4, [r6, 0x2]
	adds r0, r4, 0
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _080A2024
	ldr r0, _080A2014
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r7
	bhi _080A2024
	adds r0, 0x1
	strh r0, [r1]
	b _080A2024
	.align 2, 0
_080A200C: .4byte gUnknown_8116844
_080A2010: .4byte 0x000003e6
_080A2014: .4byte gUnknown_203B460
_080A2018:
	ldrb r0, [r6, 0x2]
	movs r1, 0
	bl sub_809124C
	bl sub_80910B4
_080A2024:
	subs r5, 0x1
	cmp r5, 0
	bge _080A1FE0
	b _080A236A
_080A202C:
	bl sub_808D33C
	cmp r0, 0
	beq _080A2040
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	cmp r0, 0x71
	bne _080A2040
_080A203C:
	movs r0, 0x2
	b _080A236C
_080A2040:
	movs r0, 0x71
	bl sub_8098134
	bl _080A171E
_080A204A:
	movs r0, 0
	movs r1, 0x1
	bl sub_80A56A0
	b _080A236A
_080A2054:
	add r0, sp, 0x328
	str r5, [r0]
	str r7, [r0, 0x4]
	bl sub_80A56F0
	b _080A236A
_080A2060:
	add r0, sp, 0x330
	str r5, [r0]
	str r7, [r0, 0x4]
	bl sub_80A5704
	b _080A236A
_080A206C:
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_809C6CC
	b _080A236A
_080A2076:
	bl sub_809C6EC
	b _080A236A
_080A207C:
	bl sub_809C760
	b _080A236A
_080A2082:
	movs r0, 0
	movs r4, 0x80
	lsls r4, 9
_080A2088:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80A86C8
	adds r0, r4, 0
	movs r5, 0x80
	lsls r5, 9
	adds r4, r5
	asrs r0, 16
	cmp r0, 0x17
	ble _080A2088
	movs r0, 0
	adds r4, r5, 0
_080A20A2:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80AC1B0
	adds r0, r4, 0
	movs r6, 0x80
	lsls r6, 9
	adds r4, r6
	asrs r0, 16
	cmp r0, 0xF
	ble _080A20A2
	movs r0, 0
	adds r4, r6, 0
_080A20BC:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80AD0C8
	adds r0, r4, 0
	movs r1, 0x80
	lsls r1, 9
	adds r4, r1
	asrs r0, 16
	cmp r0, 0xF
	ble _080A20BC
	b _080A236A
_080A20D4:
	add r0, sp, 0x338
	str r5, [r0]
	adds r4, r0, 0
	str r7, [r4, 0x4]
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_80A5984
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	adds r1, r4, 0
	bl sub_80A59A0
	b _080A236A
_080A20F4:
	add r1, sp, 0x308
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	strb r2, [r1, 0x1]
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x3]
	str r2, [r1, 0x4]
	ldr r0, _080A21D8
	ldr r2, _080A21DC
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1, 0x8]
	movs r0, 0x1
	negs r0, r0
	lsls r2, r5, 16
	asrs r2, 16
	lsls r3, r7, 24
	asrs r3, 24
	bl GroundEffect_Add
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A2128
	b _080A236A
_080A2128:
	bl sub_80AD158
	adds r7, r0, 0
	add r4, sp, 0x340
	add r5, sp, 0x348
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80A579C
	ldr r0, [r4, 0x4]
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [r4, 0x4]
	ldr r0, [r5, 0x4]
	adds r0, r1
	str r0, [r5, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	add r6, sp, 0x350
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	add r1, sp, 0x350
	ldr r2, [r1]
	add r0, sp, 0x340
	ldr r0, [r0]
	cmp r2, r0
	blt _080A216E
	add r0, sp, 0x348
	ldr r0, [r0]
	cmp r2, r0
	blt _080A2170
	subs r0, 0x1
_080A216E:
	str r0, [r1]
_080A2170:
	ldr r1, [r6, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	blt _080A2180
	ldr r0, [r5, 0x4]
	cmp r1, r0
	blt _080A2182
	subs r0, 0x1
_080A2180:
	str r0, [r6, 0x4]
_080A2182:
	add r1, sp, 0x340
	ldr r0, [r1]
	ldr r2, _080A21E0
	adds r0, r2
	str r0, [r1]
	ldr r0, [r4, 0x4]
	adds r0, r2
	str r0, [r4, 0x4]
	add r1, sp, 0x348
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2
	str r0, [r1]
	ldr r0, [r5, 0x4]
	adds r0, r2
	str r0, [r5, 0x4]
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r3, [r1, 0x20]
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r6, 0
	bl _call_via_r2
	movs r0, 0
	movs r1, 0
	add r2, sp, 0x358
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0x358
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	b _080A1EBE
	.align 2, 0
_080A21D8: .4byte gUnknown_812F1F8
_080A21DC: .4byte 0x00001310
_080A21E0: .4byte 0xfffffc00
_080A21E4:
	ldr r0, _080A2288
	ldrh r4, [r0]
	ldrh r0, [r0, 0x2]
	movs r1, 0xC
	ands r0, r1
	cmp r0, 0
	beq _080A21F4
	b _080A236A
_080A21F4:
	adds r0, r4, 0
	bl sub_809CFE8
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A2282
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x360
	bl sub_8002BB8
	add r0, sp, 0x360
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x368
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x2
	ands r4, r0
	cmp r4, 0
	beq _080A2226
	movs r0, 0x4
_080A2226:
	cmp r0, 0
	beq _080A2282
	movs r3, 0xDA
	lsls r3, 2
	add r3, sp
	mov r9, r3
	add r7, sp, 0x370
	add r4, sp, 0x378
	mov r8, r0
_080A2238:
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	mov r1, r9
	bl _call_via_r2
	cmp r0, 0
	beq _080A2276
	movs r5, 0
	str r5, [r7]
	mov r1, r9
	ldr r0, [r1, 0x4]
	str r0, [r7, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r7, 0
	bl _call_via_r2
	cmp r0, 0
	beq _080A2276
	mov r2, r9
	ldr r0, [r2]
	str r0, [r4]
	str r5, [r4, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
_080A2276:
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r5, r8
	cmp r5, 0
	bne _080A2238
_080A2282:
	movs r0, 0x1
	negs r0, r0
	b _080A236C
	.align 2, 0
_080A2288: .4byte gUnknown_20255F0
_080A228C:
	negs r0, r5
	orrs r0, r5
	lsrs r0, 31
	bl sub_80993C0
	b _080A236A
_080A2298:
	movs r0, 0x1
	bl sub_8011C28
_080A229E:
	adds r0, r5, 0
	bl sub_8098F00
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_80118C4
	b _080A236A
_080A22AE:
	bl sub_800C068
	ldr r1, _080A22C4
	strh r0, [r1]
	lsls r0, 16
	ldr r1, _080A22C8
	cmp r0, r1
	beq _080A22C0
	b _080A1EBE
_080A22C0:
	b _080A236A
	.align 2, 0
_080A22C4: .4byte gUnknown_2039DA8
_080A22C8: .4byte 0x03e70000
_080A22CC:
	ldr r4, _080A22DC
	ldrh r0, [r4]
	ldr r5, _080A22E0
	cmp r0, r5
	beq _080A236A
	bl sub_80118F0
	b _080A2312
	.align 2, 0
_080A22DC: .4byte gUnknown_2039DA8
_080A22E0: .4byte 0x000003e7
_080A22E4:
	ldr r4, _080A22FC
	ldrh r0, [r4]
	ldr r6, _080A2300
	cmp r0, r6
	beq _080A236A
	lsls r1, r5, 16
	lsrs r1, 16
	bl sub_8011900
	strh r6, [r4]
	b _080A1EBE
	.align 2, 0
_080A22FC: .4byte gUnknown_2039DA8
_080A2300: .4byte 0x000003e7
_080A2304:
	ldr r4, _080A2318
	ldrh r0, [r4]
	ldr r5, _080A231C
	cmp r0, r5
	beq _080A236A
	bl sub_8011914
_080A2312:
	strh r5, [r4]
	b _080A1EBE
	.align 2, 0
_080A2318: .4byte gUnknown_2039DA8
_080A231C: .4byte 0x000003e7
_080A2320:
	lsls r0, r5, 16
	lsrs r0, 16
	lsls r1, r7, 16
	lsrs r1, 16
	bl sub_80997F4
	b _080A236A
_080A232E:
	lsls r1, r5, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl sub_80997F4
	b _080A236A
_080A233A:
	lsls r1, r5, 16
	lsrs r1, 16
	movs r0, 0
	bl GroundSprite_ExtendPaletteAdd
	b _080A236A
_080A2346:
	movs r0, 0
	bl GroundSprite_ExtendPaletteDelete
	b _080A236A
_080A234E:
	movs r0, 0
	movs r1, 0x2F
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_800199C
	adds r0, r5, 0
	subs r0, 0x10
	b _080A236C
_080A2360:
	movs r0, 0
	movs r1, 0x1F
	movs r2, 0
	bl sub_80018D8
_080A236A:
	movs r0, 0
_080A236C:
	movs r3, 0xE0
	lsls r3, 2
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A14E8

	thumb_func_start GroundScript_Unlock
GroundScript_Unlock:
	push {r4-r7,lr}
	ldr r1, _080A241C
	ldrb r0, [r1]
	cmp r0, 0
	beq _080A2414
	movs r0, 0
	strb r0, [r1]
	movs r6, 0
_080A2390:
	ldr r0, _080A2420
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, 0
	beq _080A240E
	movs r0, 0x1
	ldr r1, _080A2424
	adds r2, r6, 0
	bl Log
	lsls r5, r6, 16
	asrs r5, 16
	adds r0, r5, 0
	bl sub_80A4D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80A8B1C
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80AC320
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80AD238
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A2428
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, 0
	beq _080A240C
	cmp r4, 0
	beq _080A240E
	movs r0, 0x80
	adds r4, r6, 0
	orrs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_80A4D2C
	adds r0, r4, 0
	bl sub_80A8B1C
	adds r0, r4, 0
	bl sub_80AC320
	adds r0, r4, 0
	bl sub_80AD238
	movs r0, 0
	strb r0, [r5]
_080A240C:
	strb r0, [r7]
_080A240E:
	adds r6, 0x1
	cmp r6, 0x80
	ble _080A2390
_080A2414:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A241C: .4byte gUnknown_2039A36
_080A2420: .4byte gUnknown_2039A38
_080A2424: .4byte gUnknown_8116848
_080A2428: .4byte gUnknown_2039AC0
	thumb_func_end GroundScript_Unlock

	thumb_func_start sub_80A242C
sub_80A242C:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r1, 0
	ldr r0, [r0, 0x2C]
	adds r2, r0, 0
	adds r2, 0x10
	mov r3, sp
_080A243A:
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, 0x10
	ldrb r0, [r3]
	cmp r0, 0xF4
	bne _080A243A
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r4, r0
	bne _080A243A
	adds r0, r2, 0
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A242C

	thumb_func_start sub_80A2460
sub_80A2460:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r5, r0, 0
	mov r8, r1
	ldr r6, [r5, 0x28]
	mov r4, sp
_080A2470:
	mov r0, sp
	adds r1, r6, 0
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldr r1, [r1]
	str r1, [r0]
	ldrb r0, [r4]
	cmp r0, 0xCC
	bne _080A249E
	ldr r1, [sp, 0x4]
	mov r0, r8
	movs r2, 0x2
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A249E:
	cmp r0, 0xCD
	bne _080A24BE
	ldr r1, [sp, 0x4]
	ldrb r2, [r4, 0x1]
	mov r0, r8
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A24BE:
	cmp r0, 0xCE
	bne _080A24EC
	ldr r1, [sp, 0x4]
	lsls r1, 16
	asrs r1, 16
	adds r0, r5, 0
	adds r0, 0x74
	bl sub_8001658
	adds r1, r0, 0
	ldrb r2, [r4, 0x1]
	mov r0, r8
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A24EC:
	adds r0, r6, 0
	b _080A24F4
_080A24F0:
	adds r6, 0x10
	b _080A2470
_080A24F4:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2460

	thumb_func_start sub_80A2500
sub_80A2500:
	push {r4,lr}
	adds r4, r0, 0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _080A2524
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80A8BBC
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_809AB4C
_080A2524:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A2500

	thumb_func_start sub_80A252C
sub_80A252C:
	push {r4,lr}
	adds r4, r0, 0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _080A2550
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80A8BBC
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_809ABB4
_080A2550:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A252C

	thumb_func_start sub_80A2558
sub_80A2558:
	push {r4,lr}
	adds r4, r0, 0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _080A257C
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80A8BBC
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_809AC18
_080A257C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A2558

	thumb_func_start sub_80A2584
sub_80A2584:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	lsls r0, 16
	asrs r0, 16
	bl sub_809ABB4
	pop {r0}
	bx r0
	thumb_func_end sub_80A2584

	thumb_func_start sub_80A2598
sub_80A2598:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	lsls r0, 16
	asrs r0, 16
	bl sub_809AC18
	pop {r0}
	bx r0
	thumb_func_end sub_80A2598

	thumb_func_start sub_80A25AC
sub_80A25AC:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	beq _080A25C2
	adds r0, r4, 0
	b _080A2602
_080A25C2:
	cmp r4, 0x32
	bne _080A25CA
	movs r0, 0x32
	b _080A2602
_080A25CA:
	movs r0, 0xC
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A25E0
	ldr r0, _080A25DC
	b _080A2602
	.align 2, 0
_080A25DC: .4byte 0x000003e7
_080A25E0:
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A25F0
	movs r0, 0x13
	b _080A2602
_080A25F0:
	cmp r4, 0x1
	bne _080A2600
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	movs r0, 0x1
	b _080A2602
_080A2600:
	adds r0, r5, 0
_080A2602:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A25AC

	thumb_func_start sub_80A2608
sub_80A2608:
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, _080A261C
	adds r0, r1
	bx lr
	.align 2, 0
_080A261C: .4byte gUnknown_81168A8
	thumb_func_end sub_80A2608

	thumb_func_start sub_80A2620
sub_80A2620:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, _080A2640
	adds r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_080A2640: .4byte gUnknown_81168A8
	thumb_func_end sub_80A2620

	thumb_func_start sub_80A2644
sub_80A2644:
	ldr r1, _080A2650
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A2650: .4byte gUnknown_8116F24
	thumb_func_end sub_80A2644

	thumb_func_start sub_80A2654
sub_80A2654:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A2654

	thumb_func_start sub_80A2668
sub_80A2668:
	push {lr}
	lsls r0, 16
	ldr r2, _080A267C
	adds r1, r0, r2
	lsrs r0, r1, 16
	cmp r0, 0x18
	bls _080A2680
	movs r0, 0x1
	negs r0, r0
	b _080A2682
	.align 2, 0
_080A267C: .4byte 0xffc90000
_080A2680:
	asrs r0, r1, 16
_080A2682:
	pop {r1}
	bx r1
	thumb_func_end sub_80A2668

	thumb_func_start sub_80A2688
sub_80A2688:
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	adds r3, r1, 0
	adds r2, r1, 0
	subs r2, 0x4B
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x16
	bhi _080A26A0
	adds r0, r2, 0
	b _080A26B4
_080A26A0:
	cmp r1, 0x2F
	bne _080A26A8
	movs r0, 0x17
	b _080A26B4
_080A26A8:
	cmp r3, 0x30
	beq _080A26B2
	movs r0, 0x1
	negs r0, r0
	b _080A26B4
_080A26B2:
	movs r0, 0x18
_080A26B4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A2688

	thumb_func_start sub_80A26B8
sub_80A26B8:
	lsls r0, 16
	ldr r1, _080A26C8
	asrs r0, 15
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A26C8: .4byte gUnknown_8116F9A
	thumb_func_end sub_80A26B8

	thumb_func_start sub_80A26CC
sub_80A26CC:
	lsls r0, 16
	movs r1, 0xDC
	lsls r1, 14
	adds r0, r1
	asrs r0, 16
	bx lr
	thumb_func_end sub_80A26CC

	thumb_func_start sub_80A26D8
sub_80A26D8:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
_080A26E0:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2608
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A26FC
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A26FC
	adds r0, r4, 0
	b _080A2706
_080A26FC:
	adds r5, 0x1
	cmp r5, 0x52
	ble _080A26E0
	movs r0, 0x1
	negs r0, r0
_080A2706:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A26D8

	thumb_func_start sub_80A270C
sub_80A270C:
	push {lr}
	lsls r0, 16
	ldr r1, _080A2724
	asrs r0, 15
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	pop {r1}
	bx r1
	.align 2, 0
_080A2724: .4byte gUnknown_8116F9A
	thumb_func_end sub_80A270C

	thumb_func_start sub_80A2728
sub_80A2728:
	push {lr}
	lsls r0, 16
	movs r1, 0xDC
	lsls r1, 14
	adds r0, r1
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_80A2728

	thumb_func_start sub_80A2740
sub_80A2740:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_80A2740

	thumb_func_start sub_80A2750
sub_80A2750:
	push {r4,lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	cmp r1, 0x50
	bne _080A2760
	movs r0, 0x3
	b _080A27C4
_080A2760:
	cmp r1, 0x51
	beq _080A27BE
	cmp r1, 0x52
	beq _080A2780
	adds r0, r1, 0
	subs r0, 0x28
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xE
	bls _080A27BE
	adds r0, r1, 0
	subs r0, 0x37
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x18
	bhi _080A2784
_080A2780:
	movs r0, 0x4
	b _080A27C4
_080A2784:
	adds r0, r2, 0
	bl sub_80A2608
	adds r4, r0, 0
	movs r0, 0xE
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A27C2
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A27C2
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A27C2
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A27C2
_080A27BE:
	movs r0, 0x2
	b _080A27C4
_080A27C2:
	movs r0, 0x1
_080A27C4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2750

	thumb_func_start sub_80A27CC
sub_80A27CC:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	adds r5, r4, 0
	adds r0, r4, 0
	bl sub_80A2620
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A281A
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A281A
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A2816
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A281A
	adds r0, r5, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A281A
_080A2816:
	movs r0, 0x1
	b _080A281C
_080A281A:
	movs r0, 0
_080A281C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A27CC

	thumb_func_start sub_80A2824
sub_80A2824:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A28AC
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A2880
	movs r5, 0
_080A2844:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A2874
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A2874
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A287C
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	bne _080A287C
_080A2874:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A2844
	b _080A28AC
_080A287C:
	movs r0, 0x1
	b _080A28AE
_080A2880:
	movs r5, 0
_080A2882:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A28A6
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A28A6
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A287C
_080A28A6:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A2882
_080A28AC:
	movs r0, 0
_080A28AE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2824

	thumb_func_start sub_80A28B4
sub_80A28B4:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A28E8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A28E4
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A28E8
_080A28E4:
	movs r0, 0x1
	b _080A28EA
_080A28E8:
	movs r0, 0
_080A28EA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A28B4

	thumb_func_start sub_80A28F0
sub_80A28F0:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
_080A28F8:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r1, r0, 0
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	beq _080A292C
	ldrb r0, [r1, 0xC]
	cmp r0, r6
	bne _080A292C
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A2928
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A292C
_080A2928:
	movs r0, 0x1
	b _080A2934
_080A292C:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A28F8
	movs r0, 0
_080A2934:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A28F0

	thumb_func_start sub_80A293C
sub_80A293C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x40
	mov r8, r0
	movs r7, 0
	movs r1, 0
	mov r0, sp
	adds r0, 0x3E
_080A294E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _080A294E
	movs r5, 0
_080A2958:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r6, r0, 0
	ldrb r0, [r6, 0x11]
	cmp r0, 0
	beq _080A2980
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _080A2980
	ldrb r0, [r6, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2980:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A2958
	movs r5, 0
_080A2988:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A299A
	mov r2, r8
	adds r0, r2, r7
	strb r5, [r0]
	adds r7, 0x1
_080A299A:
	adds r5, 0x1
	cmp r5, 0x3E
	ble _080A2988
	adds r0, r7, 0
	add sp, 0x40
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A293C

	thumb_func_start sub_80A29B0
sub_80A29B0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x48
	mov r8, r0
	movs r7, 0
	movs r0, 0x2B
	add r0, sp
	mov r9, r0
	add r1, sp, 0x2C
	mov r10, r1
	mov r2, sp
	adds r2, 0x2D
	str r2, [sp, 0x40]
	mov r0, sp
	adds r0, 0x2E
	str r0, [sp, 0x44]
	movs r1, 0
	adds r0, 0x10
_080A29DA:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _080A29DA
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A2A1E
	movs r5, 0
_080A29F0:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r6, r0, 0
	ldrb r0, [r6, 0x11]
	cmp r0, 0
	beq _080A2A18
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A2A18
	ldrb r0, [r6, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2A18:
	adds r5, 0x1
	cmp r5, 0x2D
	ble _080A29F0
_080A2A1E:
	movs r0, 0
	mov r1, r9
	strb r0, [r1]
	mov r2, r10
	strb r0, [r2]
	ldr r1, [sp, 0x40]
	strb r0, [r1]
	ldr r2, [sp, 0x44]
	strb r0, [r2]
	movs r5, 0
_080A2A32:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A2A44
	mov r2, r8
	adds r0, r2, r7
	strb r5, [r0]
	adds r7, 0x1
_080A2A44:
	adds r5, 0x1
	cmp r5, 0x3E
	ble _080A2A32
	adds r0, r7, 0
	add sp, 0x48
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A29B0

	thumb_func_start sub_80A2A5C
sub_80A2A5C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x40
	mov r8, r0
	movs r7, 0
	movs r1, 0
	mov r0, sp
	adds r0, 0x3E
_080A2A6E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _080A2A6E
	movs r0, 0x1
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A2AC0
	movs r6, 0
_080A2A84:
	lsls r0, r6, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r5, r0, 0
	ldrb r0, [r5, 0x11]
	cmp r0, 0
	beq _080A2AB8
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	bne _080A2AAE
	adds r0, r4, 0
	bl sub_80973F4
	lsls r0, 24
	cmp r0, 0
	beq _080A2AB8
_080A2AAE:
	ldrb r0, [r5, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2AB8:
	adds r6, 0x1
	cmp r6, 0x2D
	ble _080A2A84
	b _080A2AF0
_080A2AC0:
	movs r6, 0
_080A2AC2:
	lsls r0, r6, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2620
	adds r5, r0, 0
	ldrb r0, [r5, 0x11]
	cmp r0, 0
	beq _080A2AEA
	adds r0, r4, 0
	bl sub_8097384
	lsls r0, 24
	cmp r0, 0
	beq _080A2AEA
	ldrb r0, [r5, 0xC]
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_080A2AEA:
	adds r6, 0x1
	cmp r6, 0x2D
	ble _080A2AC2
_080A2AF0:
	movs r6, 0
_080A2AF2:
	mov r1, sp
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A2B04
	mov r2, r8
	adds r0, r2, r7
	strb r6, [r0]
	adds r7, 0x1
_080A2B04:
	adds r6, 0x1
	cmp r6, 0x3E
	ble _080A2AF2
	adds r0, r7, 0
	add sp, 0x40
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2A5C

	thumb_func_start sub_80A2B18
sub_80A2B18:
	lsls r0, 16
	ldr r1, _080A2B24
	asrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080A2B24: .4byte gUnknown_8117000
	thumb_func_end sub_80A2B18

	thumb_func_start sub_80A2B28
sub_80A2B28:
	push {lr}
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2B18
	pop {r1}
	bx r1
	thumb_func_end sub_80A2B28

	thumb_func_start sub_80A2B40
sub_80A2B40:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r2, _080A2BFC
	adds r0, r5, r2
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldr r3, _080A2C00
	adds r0, r5, r3
	movs r4, 0
	ldrsh r1, [r0, r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	movs r1, 0x6
	bl MemoryAlloc
	movs r2, 0xA9
	lsls r2, 3
	adds r1, r5, r2
	str r0, [r1]
	movs r6, 0
	movs r3, 0xA7
	lsls r3, 3
	adds r0, r5, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r6, r0
	bge _080A2BC0
_080A2B7C:
	lsls r4, r6, 2
	ldr r0, _080A2C04
	adds r2, r5, r0
	adds r2, r4
	ldr r1, _080A2C08
	adds r0, r5, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r1, r6, 0x2
	adds r0, r1
	lsls r0, 11
	ldr r1, _080A2C0C
	adds r0, r1
	str r0, [r2]
	ldr r1, _080A2C10
	adds r0, r5, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	lsls r0, 7
	movs r1, 0x6
	bl MemoryAlloc
	ldr r3, _080A2C14
	adds r1, r5, r3
	adds r1, r4
	str r0, [r1]
	adds r6, 0x1
	movs r4, 0xA7
	lsls r4, 3
	adds r0, r5, r4
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _080A2B7C
_080A2BC0:
	cmp r6, 0x1
	bgt _080A2BD8
	movs r1, 0
	lsls r0, r6, 2
	ldr r2, _080A2C14
	adds r0, r2
	adds r0, r5
_080A2BCE:
	str r1, [r0, 0x8]
	stm r0!, {r1}
	adds r6, 0x1
	cmp r6, 0x1
	ble _080A2BCE
_080A2BD8:
	movs r3, 0xA8
	lsls r3, 3
	adds r0, r5, r3
	ldr r1, [r0]
	cmp r1, 0
	beq _080A2C20
	ldr r4, _080A2C18
	adds r0, r5, r4
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 8
	movs r1, 0x6
	bl MemoryAlloc
	ldr r2, _080A2C1C
	adds r1, r5, r2
	str r0, [r1]
	b _080A2C26
	.align 2, 0
_080A2BFC: .4byte 0x0000052c
_080A2C00: .4byte 0x00000534
_080A2C04: .4byte 0x00000554
_080A2C08: .4byte 0x00000536
_080A2C0C: .4byte gUnknown_202B038
_080A2C10: .4byte 0x0000053c
_080A2C14: .4byte 0x0000054c
_080A2C18: .4byte 0x0000053a
_080A2C1C: .4byte 0x00000544
_080A2C20:
	ldr r3, _080A2CF0
	adds r0, r5, r3
	str r1, [r0]
_080A2C26:
	movs r4, 0x86
	lsls r4, 3
	adds r0, r5, r4
	movs r1, 0
	str r1, [r0]
	ldr r2, _080A2CF4
	adds r0, r5, r2
	str r1, [r0]
	movs r3, 0x87
	lsls r3, 3
	adds r0, r5, r3
	str r1, [r0]
	adds r4, 0xC
	adds r0, r5, r4
	str r1, [r0]
	adds r2, 0xC
	adds r0, r5, r2
	str r1, [r0]
	adds r3, 0xF2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, 0x8
	adds r2, r5, r4
	ldr r0, _080A2CF8
	strh r0, [r2]
	movs r2, 0x8D
	lsls r2, 3
	adds r0, r5, r2
	str r1, [r0]
	subs r3, 0xE2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, 0x5
	adds r0, r5, r4
	strb r1, [r0]
	subs r2, 0x1E
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, 0x3
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, 0x3
	adds r0, r5, r4
	strb r1, [r0]
	adds r2, 0x3
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, r5, 0
	adds r3, 0x21
	adds r0, r5, r3
	str r1, [r0]
	adds r4, 0x24
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, 0x5
	adds r0, r5, r3
	strb r1, [r0]
	movs r0, 0
	movs r1, 0xD
_080A2C9C:
	strh r0, [r2]
	strh r0, [r2, 0x2]
	str r0, [r2, 0x8]
	str r0, [r2, 0x4]
	subs r1, 0x1
	adds r2, 0x10
	cmp r1, 0
	bge _080A2C9C
	movs r1, 0
	movs r4, 0xF8
	lsls r4, 2
	adds r0, r5, r4
	movs r2, 0x1
_080A2CB6:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	str r1, [r0, 0x14]
	str r1, [r0, 0x10]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x18]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adds r0, 0x28
	subs r2, 0x1
	cmp r2, 0
	bge _080A2CB6
	movs r4, 0
_080A2CD8:
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, _080A2CFC
	bl sub_80A456C
	adds r4, 0x1
	cmp r4, 0x1
	ble _080A2CD8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CF0: .4byte 0x00000544
_080A2CF4: .4byte 0x00000434
_080A2CF8: .4byte 0x0000ffff
_080A2CFC: .4byte gUnknown_81172B8
	thumb_func_end sub_80A2B40

	thumb_func_start sub_80A2D00
sub_80A2D00:
	push {r4-r7,lr}
	adds r6, r0, 0
	bl sub_80A2DD4
	ldr r0, _080A2D5C
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2D1A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A2D1A:
	movs r1, 0xA9
	lsls r1, 3
	adds r4, r6, r1
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	movs r5, 0
	movs r7, 0
_080A2D2E:
	lsls r2, r5, 2
	ldr r1, _080A2D60
	adds r0, r6, r1
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, 0
	beq _080A2D3E
	str r7, [r1]
_080A2D3E:
	ldr r1, _080A2D64
	adds r0, r6, r1
	adds r4, r0, r2
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2D50
	bl MemoryFree
	str r7, [r4]
_080A2D50:
	adds r5, 0x1
	cmp r5, 0x1
	ble _080A2D2E
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D5C: .4byte 0x00000544
_080A2D60: .4byte 0x00000554
_080A2D64: .4byte 0x0000054c
	thumb_func_end sub_80A2D00

	thumb_func_start sub_80A2D68
sub_80A2D68:
	push {r4,lr}
	ldr r1, _080A2D84
	adds r4, r0, r1
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2D7C
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A2D7C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D84: .4byte 0x00000544
	thumb_func_end sub_80A2D68

	thumb_func_start sub_80A2D88
sub_80A2D88:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r0, 0xA8
	lsls r0, 3
	adds r7, r6, r0
	ldr r0, [r7]
	cmp r0, 0
	beq _080A2DC6
	movs r1, 0x89
	lsls r1, 3
	adds r5, r6, r1
	ldr r2, _080A2DCC
	adds r4, r6, r2
	movs r1, 0
	ldrsh r0, [r4, r1]
	lsls r0, 8
	movs r1, 0x6
	bl MemoryAlloc
	ldr r2, _080A2DD0
	adds r1, r6, r2
	str r0, [r1]
	subs r2, 0xDC
	adds r1, r6, r2
	ldr r1, [r1]
	movs r2, 0
	ldrsh r3, [r4, r2]
	ldr r4, [r7]
	adds r2, r5, 0
	bl _call_via_r4
_080A2DC6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2DCC: .4byte 0x0000053a
_080A2DD0: .4byte 0x00000544
	thumb_func_end sub_80A2D88

	thumb_func_start sub_80A2DD4
sub_80A2DD4:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0xFA
	lsls r0, 2
	adds r4, r6, r0
	movs r5, 0x1
_080A2DE0:
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2DEE
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2DEE:
	adds r4, 0x28
	subs r5, 0x1
	cmp r5, 0
	bge _080A2DE0
	ldr r0, _080A2E5C
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E08
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E08:
	movs r0, 0x88
	lsls r0, 3
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E1C
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E1C:
	movs r0, 0x86
	lsls r0, 3
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E30
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E30:
	ldr r0, _080A2E60
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E42
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E42:
	movs r0, 0x87
	lsls r0, 3
	adds r4, r6, r0
	ldr r0, [r4]
	cmp r0, 0
	beq _080A2E56
	bl CloseFile
	movs r0, 0
	str r0, [r4]
_080A2E56:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E5C: .4byte 0x0000043c
_080A2E60: .4byte 0x00000434
	thumb_func_end sub_80A2DD4

	thumb_func_start sub_80A2E64
sub_80A2E64:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r7, r0, 0
	bl sub_80A2DD4
	ldr r0, _080A2FA4
	adds r1, r7, r0
	ldr r0, _080A2FA8
	strh r0, [r1]
	movs r1, 0xA5
	lsls r1, 3
	adds r0, r7, r1
	movs r1, 0
	movs r2, 0
	strh r2, [r0]
	movs r3, 0x89
	lsls r3, 3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _080A2FAC
	adds r0, r7, r4
	strb r1, [r0]
	adds r3, 0x2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, 0x2
	adds r0, r7, r4
	strb r1, [r0]
	adds r3, 0x2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, 0x2
	adds r0, r7, r4
	strb r1, [r0]
	adds r3, r7, 0
	adds r4, 0x1F
	adds r0, r7, r4
	str r2, [r0]
	movs r2, 0x8E
	lsls r2, 3
	adds r0, r7, r2
	strb r1, [r0]
	adds r4, 0x5
	adds r0, r7, r4
	strb r1, [r0]
	movs r0, 0
	movs r1, 0xD
_080A2ECA:
	strh r0, [r3]
	strh r0, [r3, 0x2]
	str r0, [r3, 0x8]
	str r0, [r3, 0x4]
	subs r1, 0x1
	adds r3, 0x10
	cmp r1, 0
	bge _080A2ECA
	movs r1, 0
	movs r2, 0xF8
	lsls r2, 2
	adds r0, r7, r2
	movs r2, 0x1
_080A2EE4:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	str r1, [r0, 0x14]
	str r1, [r0, 0x10]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x18]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adds r0, 0x28
	subs r2, 0x1
	cmp r2, 0
	bge _080A2EE4
	ldr r3, _080A2FB0
	adds r0, r7, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	lsls r0, 20
	lsrs r6, r0, 16
	movs r5, 0
	ldr r1, _080A2FB4
	adds r0, r7, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge _080A2F78
	mov r10, r5
	add r4, sp, 0x4
	movs r3, 0xFF
	mov r9, r3
_080A2F26:
	mov r0, r10
	str r0, [sp]
	ldrb r0, [r4]
	mov r1, r9
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r4, 0x1]
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x2]
	orrs r0, r1
	strb r0, [r4, 0x2]
	mov r2, r10
	strb r2, [r4, 0x3]
	adds r0, r6, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r1, [sp]
	bl sub_8003810
	adds r5, 0x1
	mov r8, r5
	movs r5, 0xE
_080A2F56:
	adds r0, r6, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r1, [sp, 0x4]
	bl sub_8003810
	subs r5, 0x1
	cmp r5, 0
	bge _080A2F56
	mov r5, r8
	ldr r3, _080A2FB4
	adds r0, r7, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _080A2F26
_080A2F78:
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A3BB0
	movs r2, 0x91
	lsls r2, 3
	adds r0, r7, r2
	bl sub_80A3EB0
	ldr r3, _080A2FB8
	adds r1, r7, r3
	movs r0, 0x1
	strb r0, [r1]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2FA4: .4byte 0x00000444
_080A2FA8: .4byte 0x0000ffff
_080A2FAC: .4byte 0x00000449
_080A2FB0: .4byte 0x0000052c
_080A2FB4: .4byte 0x0000052e
_080A2FB8: .4byte 0x0000052a
	thumb_func_end sub_80A2E64

	thumb_func_start sub_80A2FBC
sub_80A2FBC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	lsls r1, 16
	asrs r4, r1, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _080A2FDE
	mov r0, r9
	bl sub_80A2E64
	b _080A3428
_080A2FDE:
	mov r0, r9
	bl sub_80A2DD4
	ldr r0, _080A3284
	add r0, r9
	strh r4, [r0]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r1, _080A3288
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r0]
	ldr r4, _080A328C
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	movs r6, 0x86
	lsls r6, 3
	add r6, r9
	str r0, [r6]
	ldr r1, [sp, 0xC]
	ldr r0, [r1, 0x4]
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	ldr r5, _080A3290
	add r5, r9
	str r0, [r5]
	ldr r2, [sp, 0xC]
	ldr r0, [r2, 0x8]
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x87
	lsls r1, 3
	add r1, r9
	str r0, [r1]
	ldr r1, [r6]
	ldr r1, [r1, 0x4]
	str r1, [sp, 0x18]
	ldr r1, [r5]
	ldr r1, [r1, 0x4]
	mov r8, r1
	ldr r6, [r0, 0x4]
	ldr r3, _080A3294
	add r3, r9
	str r3, [sp, 0x10]
	ldr r4, _080A3298
	add r4, r9
	str r4, [sp, 0x14]
	movs r5, 0x89
	lsls r5, 3
	add r5, r9
	mov r10, r5
	ldr r7, [sp, 0x18]
	ldrb r0, [r7]
	strh r0, [r3]
	adds r0, r7, 0
	adds r0, 0x2
	str r0, [sp, 0x18]
	ldrb r0, [r0]
	strh r0, [r3, 0x2]
	ldr r1, [sp, 0x18]
	adds r1, 0x2
	str r1, [sp, 0x18]
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r4]
	movs r3, 0x2
	add r8, r3
	mov r4, r8
	ldrh r0, [r4]
	ldr r5, [sp, 0x14]
	strh r0, [r5, 0x2]
	add r8, r3
	mov r7, r8
	ldrh r0, [r7]
	strh r0, [r5, 0x4]
	add r8, r3
	add r3, sp, 0x8
	ldr r0, _080A329C
	add r0, r9
	str r0, [sp, 0x1C]
	adds r1, r0, 0
	movs r2, 0x3
_080A308A:
	mov r4, r8
	ldrh r0, [r4]
	strh r0, [r1]
	movs r5, 0x2
	add r8, r5
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080A308A
	mov r7, r8
	ldrh r0, [r7]
	movs r2, 0
	movs r1, 0
	ldr r4, [sp, 0x14]
	strh r0, [r4, 0xE]
	add r8, r5
	ldrb r0, [r6]
	mov r5, r10
	strb r0, [r5]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x1]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x2]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x3]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x4]
	adds r6, 0x1
	ldrb r0, [r6]
	strb r0, [r5, 0x5]
	adds r6, 0x1
	ldrb r0, [r6]
	strh r0, [r5, 0x6]
	adds r6, 0x2
	ldrb r0, [r6]
	strh r0, [r5, 0x8]
	adds r6, 0x2
	ldrb r0, [r6]
	strh r0, [r5, 0xA]
	adds r6, 0x2
	ldr r7, [sp, 0x18]
	ldr r0, _080A32A0
	add r0, r9
	movs r4, 0
	ldrsh r0, [r0, r4]
	lsls r0, 20
	lsrs r5, r0, 16
	str r1, [sp, 0x4]
	movs r0, 0xFF
	strb r0, [r3]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r3, 0x1]
	strb r0, [r3, 0x2]
	strb r2, [r3, 0x3]
	movs r4, 0
	ldr r1, [sp, 0x10]
	movs r2, 0
	ldrsh r0, [r1, r2]
	ldr r3, [sp, 0xC]
	adds r3, 0xC
	str r3, [sp, 0x20]
	cmp r4, r0
	bge _080A3158
	ldr r0, _080A32A4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bge _080A3198
_080A311E:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r1, [sp, 0x4]
	bl sub_8003810
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0xF
	bl sub_809971C
	adds r0, r5, 0
	adds r0, 0xF
	lsls r0, 16
	lsrs r5, r0, 16
	adds r7, 0x3C
	adds r4, 0x1
	ldr r2, [sp, 0x10]
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r4, r0
	bge _080A3158
	ldr r0, _080A32A4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _080A311E
_080A3158:
	ldr r0, _080A32A4
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r4, r0
	bge _080A3198
_080A3164:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r1, [sp, 0x4]
	bl sub_8003810
	adds r7, r4, 0x1
	movs r4, 0xE
_080A3176:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r1, [sp, 0x8]
	bl sub_8003810
	subs r4, 0x1
	cmp r4, 0
	bge _080A3176
	adds r4, r7, 0
	ldr r0, _080A32A4
	add r0, r9
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r4, r0
	blt _080A3164
_080A3198:
	movs r0, 0xA6
	lsls r0, 3
	add r0, r9
	movs r4, 0
	ldrsh r0, [r0, r4]
	lsls r0, 5
	ldr r5, _080A32A8
	adds r0, r5
	ldr r4, _080A32A0
	add r4, r9
	ldr r5, _080A3298
	add r5, r9
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_80A37C4
	movs r0, 0xA9
	lsls r0, 3
	add r0, r9
	ldr r0, [r0]
	movs r1, 0xA5
	lsls r1, 3
	add r1, r9
	ldr r7, [sp, 0x14]
	movs r3, 0x4
	ldrsh r2, [r7, r3]
	subs r2, 0x1
	lsls r2, 5
	add r2, r8
	str r5, [sp]
	adds r3, r4, 0
	bl _UncompressCell
	ldr r0, _080A32AC
	add r0, r9
	movs r3, 0x89
	lsls r3, 3
	add r3, r9
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_80A3908
	adds r6, r0, 0
	movs r0, 0x8D
	lsls r0, 3
	add r0, r9
	str r6, [r0]
	ldr r0, _080A32B0
	add r0, r9
	ldr r2, [r0]
	cmp r2, 0
	beq _080A321C
	movs r1, 0xA8
	lsls r1, 3
	add r1, r9
	ldr r0, _080A32B4
	add r0, r9
	movs r4, 0
	ldrsh r3, [r0, r4]
	ldr r4, [r1]
	adds r0, r2, 0
	adds r1, r6, 0
	mov r2, r10
	bl _call_via_r4
_080A321C:
	mov r2, r9
	movs r4, 0
	ldr r5, [sp, 0x10]
	movs r6, 0x2
	ldrsh r0, [r5, r6]
	cmp r0, 0
	beq _080A32E4
	movs r7, 0
	ldrsh r1, [r5, r7]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	ldr r5, [sp, 0x18]
	adds r3, r5, r0
	lsls r1, 2
	adds r6, r3, r1
	ldr r0, _080A32B8
	add r0, r9
	str r3, [r0]
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _080A32BC
	add r0, r9
	strb r1, [r0]
	ldr r7, [sp, 0x10]
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r4, r0
	bge _080A32F8
	ldr r1, _080A32A4
	add r1, r9
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r4, r0
	bge _080A32F8
	movs r5, 0
	mov r8, r1
_080A326C:
	movs r7, 0x2
	ldrsh r0, [r3, r7]
	cmp r0, 0
	ble _080A32C0
	str r6, [r2, 0x4]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 2
	adds r6, r0
	b _080A32C2
	.align 2, 0
_080A3284: .4byte 0x00000444
_080A3288: .4byte gUnknown_81188F0
_080A328C: .4byte gUnknown_9890000
_080A3290: .4byte 0x00000434
_080A3294: .4byte 0x00000464
_080A3298: .4byte 0x00000454
_080A329C: .4byte 0x0000045a
_080A32A0: .4byte 0x0000052c
_080A32A4: .4byte 0x0000052e
_080A32A8: .4byte 0x06008000
_080A32AC: .4byte 0x0000054c
_080A32B0: .4byte 0x00000544
_080A32B4: .4byte 0x0000053a
_080A32B8: .4byte 0x0000046c
_080A32BC: .4byte 0x00000471
_080A32C0:
	str r5, [r2, 0x4]
_080A32C2:
	strh r5, [r2]
	strh r5, [r2, 0x2]
	str r5, [r2, 0x8]
	adds r4, 0x1
	adds r2, 0x10
	adds r3, 0x4
	ldr r1, [sp, 0x10]
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r4, r0
	bge _080A32F8
	mov r1, r8
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r4, r0
	blt _080A326C
	b _080A32F8
_080A32E4:
	ldr r0, _080A3384
	add r0, r9
	str r4, [r0]
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	strb r4, [r0]
	ldr r0, _080A3388
	add r0, r9
	strb r4, [r0]
_080A32F8:
	cmp r4, 0xD
	bgt _080A330E
	movs r0, 0
_080A32FE:
	strh r0, [r2]
	strh r0, [r2, 0x2]
	str r0, [r2, 0x8]
	str r0, [r2, 0x4]
	adds r4, 0x1
	adds r2, 0x10
	cmp r4, 0xD
	ble _080A32FE
_080A330E:
	movs r0, 0xA6
	lsls r0, 3
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, 0x14]
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	adds r0, r1
	lsls r0, 5
	ldr r4, _080A338C
	adds r5, r0, r4
	movs r7, 0
	movs r6, 0
	mov r8, r6
	movs r4, 0xF8
	lsls r4, 2
	add r4, r9
	ldr r0, [sp, 0x1C]
	str r0, [sp, 0x28]
	ldr r3, [sp, 0x20]
_080A3338:
	ldr r0, [r3]
	cmp r0, 0
	beq _080A3394
	ldr r1, _080A3390
	str r3, [sp, 0x24]
	bl OpenFileAndGetFileDataPtr
	str r0, [r4, 0x8]
	movs r1, 0x1
	strb r1, [r4]
	strb r1, [r4, 0x1]
	ldr r2, [r0, 0x4]
	str r2, [r4, 0xC]
	adds r1, r2, 0x4
	movs r0, 0x2
	ldrsh r6, [r2, r0]
	lsls r6, 2
	adds r0, r1, r6
	str r1, [r4, 0x14]
	str r1, [r4, 0x10]
	str r0, [r4, 0x1C]
	str r0, [r4, 0x18]
	mov r1, r8
	strh r1, [r4, 0x2]
	ldr r0, [r2, 0x4]
	strh r0, [r4, 0x4]
	str r5, [r4, 0x20]
	ldr r2, [sp, 0x28]
	movs r6, 0
	ldrsh r0, [r2, r6]
	lsls r0, 5
	str r0, [r4, 0x24]
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r0, 5
	adds r5, r0
	ldr r3, [sp, 0x24]
	b _080A33AC
	.align 2, 0
_080A3384: .4byte 0x0000046c
_080A3388: .4byte 0x00000471
_080A338C: .4byte 0x06008000
_080A3390: .4byte gUnknown_9890000
_080A3394:
	strb r0, [r4]
	strb r0, [r4, 0x1]
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	str r0, [r4, 0x14]
	str r0, [r4, 0x10]
	str r0, [r4, 0x1C]
	str r0, [r4, 0x18]
	str r0, [r4, 0x20]
	str r0, [r4, 0x24]
_080A33AC:
	adds r4, 0x28
	ldr r2, [sp, 0x28]
	adds r2, 0x2
	str r2, [sp, 0x28]
	adds r3, 0x4
	adds r7, 0x1
	cmp r7, 0x1
	ble _080A3338
	cmp r7, 0x3
	bgt _080A340E
_080A33C0:
	lsls r0, r7, 2
	ldr r3, [sp, 0x20]
	adds r0, r3, r0
	ldr r0, [r0]
	adds r4, r7, 0x1
	cmp r0, 0
	beq _080A3408
	ldr r1, _080A3438
	bl OpenFileAndGetFileDataPtr
	adds r3, r0, 0
	ldr r0, [r3, 0x4]
	adds r1, r0, 0x4
	movs r6, 0x2
	ldrsh r0, [r0, r6]
	lsls r0, 2
	adds r1, r0
	lsls r0, r7, 1
	ldr r7, [sp, 0x1C]
	adds r0, r7, r0
	movs r2, 0
	ldrsh r0, [r0, r2]
	lsls r0, 4
	cmp r0, 0
	ble _080A3402
	adds r2, r0, 0
_080A33F4:
	ldrh r0, [r1]
	strh r0, [r5]
	adds r1, 0x2
	adds r5, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _080A33F4
_080A3402:
	adds r0, r3, 0
	bl CloseFile
_080A3408:
	adds r7, r4, 0
	cmp r7, 0x3
	ble _080A33C0
_080A340E:
	mov r0, r9
	movs r1, 0
	bl sub_80A3BB0
	movs r0, 0x91
	lsls r0, 3
	add r0, r9
	bl sub_80A3EB0
	ldr r1, _080A343C
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A3428:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3438: .4byte gUnknown_9890000
_080A343C: .4byte 0x0000052a
	thumb_func_end sub_80A2FBC

	thumb_func_start sub_80A3440
sub_80A3440:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4C
	mov r9, r0
	str r2, [sp, 0x34]
	str r3, [sp, 0x38]
	lsls r1, 16
	asrs r5, r1, 16
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _080A3464
	ldrb r0, [r2]
	cmp r0, 0x63
	bne _080A346C
_080A3464:
	mov r0, r9
	bl sub_80A2E64
	b _080A376C
_080A346C:
	mov r0, r9
	adds r1, r5, 0
	bl sub_80A2FBC
	mov r0, r9
	bl sub_80A2DD4
	ldr r0, _080A377C
	add r0, r9
	strh r5, [r0]
	lsls r4, r5, 3
	subs r4, r5
	lsls r4, 2
	ldr r0, _080A3780
	adds r4, r0
	ldr r0, [r4]
	ldr r5, _080A3784
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x86
	lsls r1, 3
	add r1, r9
	mov r8, r1
	str r0, [r1]
	ldr r0, [r4, 0x4]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r6, _080A3788
	add r6, r9
	str r0, [r6]
	ldr r0, [r4, 0x8]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	movs r1, 0x87
	lsls r1, 3
	add r1, r9
	str r0, [r1]
	mov r2, r8
	ldr r1, [r2]
	ldr r2, [r1, 0x4]
	ldr r1, [r6]
	ldr r3, [r1, 0x4]
	ldr r7, [r0, 0x4]
	ldr r1, _080A378C
	add r1, r9
	ldr r4, _080A3790
	add r4, r9
	str r4, [sp, 0x3C]
	movs r0, 0x89
	lsls r0, 3
	add r0, r9
	mov r10, r0
	ldrb r0, [r2]
	strh r0, [r1]
	ldrb r0, [r2, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r3]
	strh r0, [r4]
	adds r3, 0x2
	ldrh r0, [r3]
	strh r0, [r4, 0x2]
	adds r3, 0x2
	ldrh r0, [r3]
	strh r0, [r4, 0x4]
	adds r3, 0x2
	add r5, sp, 0x2C
	ldr r1, _080A3794
	add r1, r9
	str r1, [sp, 0x48]
	movs r2, 0x3
_080A34FE:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080A34FE
	ldrh r0, [r3]
	movs r2, 0
	mov r8, r2
	ldr r4, [sp, 0x3C]
	strh r0, [r4, 0xE]
	ldrb r0, [r7]
	mov r1, r10
	strb r0, [r1]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x1]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x2]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x3]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x4]
	adds r7, 0x1
	ldrb r0, [r7]
	strb r0, [r1, 0x5]
	adds r7, 0x1
	ldrb r0, [r7]
	strh r0, [r1, 0x6]
	adds r7, 0x2
	ldrb r0, [r7]
	strh r0, [r1, 0x8]
	adds r7, 0x2
	ldrb r0, [r7]
	strh r0, [r1, 0xA]
	adds r7, 0x2
	ldr r4, _080A3798
	add r4, r9
	ldr r0, [r4]
	str r0, [sp, 0x2C]
	str r2, [r5, 0x4]
	ldr r2, _080A379C
	add r2, r9
	movs r3, 0x89
	lsls r3, 3
	add r3, r9
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80A3908
	adds r7, r0, 0
	movs r0, 0x8D
	lsls r0, 3
	add r0, r9
	str r7, [r0]
	ldr r5, _080A37A0
	add r5, r9
	movs r6, 0x88
	lsls r6, 3
	add r6, r9
	ldr r2, _080A37A4
	movs r0, 0xA9
	lsls r0, 3
	add r0, r9
	ldr r3, [r0]
	ldr r0, _080A37A8
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, [sp, 0x34]
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x38]
	str r1, [sp, 0x8]
	movs r0, 0x40
	str r0, [sp, 0xC]
	mov r1, r10
	ldrb r0, [r1, 0x5]
	str r0, [sp, 0x10]
	ldr r0, [r4]
	str r0, [sp, 0x14]
	mov r0, r8
	str r0, [sp, 0x18]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80ADD9C
	ldr r0, [r5]
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r6]
	movs r1, 0
	bl GetFileDataPtr
	movs r2, 0xA8
	lsls r2, 3
	add r2, r9
	ldr r0, [r4]
	ldr r1, _080A37AC
	add r1, r9
	movs r4, 0
	ldrsh r3, [r1, r4]
	ldr r4, [r2]
	adds r1, r7, 0
	mov r2, r10
	bl _call_via_r4
	movs r0, 0x80
	lsls r0, 2
	ldr r1, [sp, 0x3C]
	strh r0, [r1, 0x4]
	ldr r1, [sp, 0x48]
	movs r2, 0
	adds r0, r1, 0x6
_080A35EA:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080A35EA
	movs r2, 0
	movs r0, 0xFA
	ldr r4, [sp, 0x3C]
	strh r0, [r4, 0xE]
	ldr r1, _080A378C
	add r1, r9
	movs r0, 0xC
	strh r0, [r1]
	ldr r0, _080A37B0
	add r0, r9
	strh r2, [r0]
	ldr r0, _080A37A0
	add r0, r9
	ldr r0, [r0]
	cmp r0, 0
	beq _080A36E6
	ldr r4, [r0, 0x4]
	movs r7, 0
	str r7, [sp, 0x1C]
	add r1, sp, 0x20
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	movs r0, 0
	strb r0, [r1, 0x3]
	movs r5, 0
	ldr r0, _080A37B4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _080A36E6
	mov r2, sp
	adds r2, 0x28
	str r2, [sp, 0x40]
	mov r0, sp
	adds r0, 0x29
	str r0, [sp, 0x44]
	movs r1, 0x2A
	add r1, sp
	mov r10, r1
	movs r2, 0x2B
	add r2, sp
	mov r8, r2
_080A3650:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x1C]
	bl sub_8003810
	adds r4, 0x4
	adds r6, r5, 0x1
	movs r5, 0xE
_080A3664:
	ldrb r0, [r4]
	ldr r1, [sp, 0x40]
	strb r0, [r1]
	ldrb r0, [r4, 0x1]
	ldr r2, [sp, 0x44]
	strb r0, [r2]
	ldrb r0, [r4, 0x2]
	mov r1, r10
	strb r0, [r1]
	ldrb r0, [r4, 0x3]
	mov r2, r8
	strb r0, [r2]
	ldr r1, [sp, 0x28]
	str r1, [sp, 0x24]
	adds r0, r7, 0
	adds r2, r0, 0x1
	lsls r2, 16
	lsrs r7, r2, 16
	bl sub_8003810
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _080A3664
	adds r5, r6, 0
	cmp r5, 0xB
	bgt _080A36A6
	ldr r0, _080A37B4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _080A3650
_080A36A6:
	ldr r0, _080A37B4
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge _080A36E6
_080A36B2:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x1C]
	bl sub_8003810
	adds r6, r5, 0x1
	movs r5, 0xE
_080A36C4:
	adds r0, r7, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r7, r1, 16
	ldr r1, [sp, 0x20]
	bl sub_8003810
	subs r5, 0x1
	cmp r5, 0
	bge _080A36C4
	adds r5, r6, 0
	ldr r0, _080A37B4
	add r0, r9
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r5, r0
	blt _080A36B2
_080A36E6:
	mov r4, r9
	movs r0, 0x88
	lsls r0, 3
	add r0, r9
	ldr r1, [r0]
	cmp r1, 0
	beq _080A36FE
	mov r0, r9
	adds r0, 0xE0
	movs r2, 0x20
	bl sub_8004AA4
_080A36FE:
	ldr r0, _080A37B8
	add r0, r9
	movs r1, 0
	str r1, [r0]
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	strb r1, [r0]
	ldr r0, _080A37BC
	add r0, r9
	strb r1, [r0]
	movs r0, 0
	movs r1, 0xD
_080A3718:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	str r0, [r4, 0x4]
	subs r1, 0x1
	adds r4, 0x10
	cmp r1, 0
	bge _080A3718
	movs r1, 0
	movs r0, 0xF8
	lsls r0, 2
	add r0, r9
	movs r2, 0x1
_080A3732:
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x2]
	str r1, [r0, 0x8]
	str r1, [r0, 0xC]
	str r1, [r0, 0x14]
	str r1, [r0, 0x10]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x18]
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adds r0, 0x28
	subs r2, 0x1
	cmp r2, 0
	bge _080A3732
	mov r0, r9
	movs r1, 0
	bl sub_80A3BB0
	movs r0, 0x91
	lsls r0, 3
	add r0, r9
	bl sub_80A3EB0
	ldr r1, _080A37C0
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A376C:
	add sp, 0x4C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A377C: .4byte 0x00000444
_080A3780: .4byte gUnknown_81188F0
_080A3784: .4byte gUnknown_9890000
_080A3788: .4byte 0x00000434
_080A378C: .4byte 0x00000464
_080A3790: .4byte 0x00000454
_080A3794: .4byte 0x0000045a
_080A3798: .4byte 0x00000544
_080A379C: .4byte 0x0000052c
_080A37A0: .4byte 0x0000043c
_080A37A4: .4byte 0x06008000
_080A37A8: .4byte 0x0000054c
_080A37AC: .4byte 0x0000053a
_080A37B0: .4byte 0x00000466
_080A37B4: .4byte 0x0000052e
_080A37B8: .4byte 0x0000046c
_080A37BC: .4byte 0x00000471
_080A37C0: .4byte 0x0000052a
	thumb_func_end sub_80A3440

	thumb_func_start sub_80A37C4
sub_80A37C4:
	push {r4-r6,lr}
	adds r6, r2, 0
	adds r4, r1, 0
	adds r2, r0, 0
	movs r0, 0
	movs r1, 0xF
_080A37D0:
	strh r0, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A37D0
	movs r0, 0x1
	movs r1, 0x4
	ldrsh r3, [r3, r1]
	cmp r0, r3
	bge _080A37FE
	adds r5, r3, 0
_080A37E6:
	adds r3, r0, 0x1
	movs r1, 0xF
_080A37EA:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A37EA
	adds r0, r3, 0
	cmp r0, r5
	blt _080A37E6
_080A37FE:
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	cmp r0, r1
	bge _080A3820
	ldr r3, _080A3828
	adds r4, r3, 0
	adds r5, r1, 0
_080A380C:
	adds r3, r0, 0x1
	movs r1, 0xF
_080A3810:
	strh r4, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A3810
	adds r0, r3, 0
	cmp r0, r5
	blt _080A380C
_080A3820:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3828: .4byte 0x0000ffff
	thumb_func_end sub_80A37C4

	thumb_func_start _UncompressCell
_UncompressCell:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r1, 0
	mov r8, r3
	ldr r3, [sp, 0x18]
	adds r4, r2, 0
	adds r2, r0, 0
	mov r1, r8
	ldrh r0, [r1]
	lsls r0, 12
	ldrh r1, [r1, 0x4]
	orrs r0, r1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r1, [r3]
	ldr r0, _080A385C
	cmp r1, r0
	bne _080A3860
	movs r0, 0x1
	strh r0, [r5]
	movs r5, 0x4
	b _080A3890
	.align 2, 0
_080A385C: .4byte 0x00020002
_080A3860:
	ldr r0, _080A3870
	cmp r1, r0
	bne _080A3874
	movs r0, 0x2
	strh r0, [r5]
	movs r5, 0x9
	b _080A3890
	.align 2, 0
_080A3870: .4byte 0x00030003
_080A3874:
	movs r0, 0
	strh r0, [r5]
	ldr r0, _080A3888
	ldr r1, _080A388C
	movs r4, 0
	ldrsh r2, [r3, r4]
	movs r6, 0x2
	ldrsh r3, [r3, r6]
	bl FatalError
	.align 2, 0
_080A3888: .4byte gUnknown_81172E8
_080A388C: .4byte gUnknown_81172F4
_080A3890:
	movs r0, 0
	movs r1, 0x8
_080A3894:
	strh r0, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A3894
	movs r0, 0x1
	movs r7, 0xE
	ldrsh r1, [r3, r7]
	cmp r0, r1
	bge _080A38DC
	mov r12, r1
_080A38AA:
	movs r1, 0
	adds r3, r0, 0x1
	cmp r1, r5
	bge _080A38C6
	adds r1, r5, 0
_080A38B4:
	ldrh r0, [r4]
	adds r0, r6, r0
	strh r0, [r2]
	adds r4, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _080A38B4
	adds r1, r5, 0
_080A38C6:
	cmp r1, 0x8
	bgt _080A38D6
	movs r0, 0
_080A38CC:
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x1
	cmp r1, 0x8
	ble _080A38CC
_080A38D6:
	adds r0, r3, 0
	cmp r0, r12
	blt _080A38AA
_080A38DC:
	mov r1, r8
	movs r4, 0x8
	ldrsh r3, [r1, r4]
	cmp r0, r3
	bge _080A38FE
	movs r4, 0
	adds r5, r3, 0
_080A38EA:
	adds r3, r0, 0x1
	movs r1, 0x8
_080A38EE:
	strh r4, [r2]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080A38EE
	adds r0, r3, 0
	cmp r0, r5
	blt _080A38EA
_080A38FE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end _UncompressCell

	thumb_func_start sub_80A3908
sub_80A3908:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp]
	str r2, [sp, 0x4]
	mov r9, r3
	adds r6, r1, 0
	movs r2, 0
	ldr r1, [sp, 0x4]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r2, r0
	blt _080A392A
	b _080A3B6C
_080A392A:
	lsls r0, r2, 2
	ldr r4, [sp]
	adds r0, r4
	ldr r0, [r0]
	mov r12, r0
	movs r1, 0
	adds r2, 0x1
	str r2, [sp, 0x8]
	mov r5, r9
	ldrb r5, [r5, 0x5]
	cmp r1, r5
	blt _080A3944
	b _080A3B2A
_080A3944:
	ldr r0, _080A39A4
	mov r10, r0
_080A3948:
	movs r2, 0
	mov r8, r2
	cmp r1, 0
	bne _080A3A18
	movs r3, 0x1
	str r3, [sp, 0xC]
	mov r4, r9
	ldrb r4, [r4, 0x4]
	cmp r1, r4
	blt _080A395E
	b _080A3B04
_080A395E:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0xBF
	ble _080A39A8
	adds r2, r1, 0
	subs r2, 0xBF
	cmp r1, 0xBF
	ble _080A39A0
	ldr r5, _080A39A4
	adds r4, r5, 0
	adds r3, r2, 0
_080A3974:
	ldrb r1, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r1, r0
	adds r6, 0x3
	adds r0, r1, 0
	ands r0, r4
	mov r5, r12
	strh r0, [r5]
	movs r0, 0x2
	add r12, r0
	asrs r1, 12
	ands r1, r4
	mov r5, r12
	strh r1, [r5]
	add r12, r0
	subs r3, 0x1
	cmp r3, 0
	bne _080A3974
_080A39A0:
	lsls r0, r2, 1
	b _080A3A0C
	.align 2, 0
_080A39A4: .4byte 0x00000fff
_080A39A8:
	cmp r1, 0x7F
	ble _080A39EA
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r4, r1, 0
	subs r4, 0x7F
	cmp r1, 0x7F
	ble _080A39E6
	adds r0, r2, 0
	mov r1, r10
	ands r0, r1
	asrs r1, r2, 12
	mov r2, r10
	ands r1, r2
	adds r3, r4, 0
_080A39D2:
	mov r5, r12
	strh r0, [r5]
	movs r2, 0x2
	add r12, r2
	mov r5, r12
	strh r1, [r5]
	add r12, r2
	subs r3, 0x1
	cmp r3, 0
	bne _080A39D2
_080A39E6:
	lsls r0, r4, 1
	b _080A3A0C
_080A39EA:
	movs r3, 0
	adds r0, r1, 0x1
	cmp r3, r1
	bgt _080A3A0A
	movs r1, 0
	adds r3, r0, 0
_080A39F6:
	mov r2, r12
	strh r1, [r2]
	movs r4, 0x2
	add r12, r4
	mov r5, r12
	strh r1, [r5]
	add r12, r4
	subs r3, 0x1
	cmp r3, 0
	bne _080A39F6
_080A3A0A:
	lsls r0, 1
_080A3A0C:
	add r8, r0
	mov r0, r9
	ldrb r0, [r0, 0x4]
	cmp r8, r0
	blt _080A395E
	b _080A3B04
_080A3A18:
	mov r4, r12
	subs r4, 0x80
	adds r1, 0x1
	str r1, [sp, 0xC]
	mov r1, r9
	ldrb r1, [r1, 0x4]
	cmp r8, r1
	bge _080A3B04
_080A3A28:
	ldrb r1, [r6]
	adds r6, 0x1
	cmp r1, 0xBF
	ble _080A3A80
	adds r5, r1, 0
	subs r5, 0xBF
	cmp r1, 0xBF
	ble _080A3A78
	ldr r2, _080A3A7C
	adds r7, r2, 0
	adds r3, r5, 0
_080A3A3E:
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r0, r2, 0
	ands r0, r7
	ldrh r1, [r4]
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	asrs r2, 12
	ands r2, r7
	ldrh r0, [r4]
	eors r2, r0
	mov r1, r12
	strh r2, [r1]
	adds r4, 0x2
	movs r2, 0x2
	add r12, r2
	subs r3, 0x1
	cmp r3, 0
	bne _080A3A3E
_080A3A78:
	lsls r0, r5, 1
	b _080A3AFA
	.align 2, 0
_080A3A7C: .4byte 0x00000fff
_080A3A80:
	cmp r1, 0x7F
	ble _080A3AD2
	ldrb r2, [r6]
	ldrb r0, [r6, 0x1]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r6, 0x2]
	lsls r0, 16
	orrs r2, r0
	adds r6, 0x3
	adds r7, r1, 0
	subs r7, 0x7F
	cmp r1, 0x7F
	ble _080A3ACE
	adds r5, r2, 0
	mov r3, r10
	ands r5, r3
	asrs r2, 12
	ands r2, r3
	adds r3, r7, 0
_080A3AA8:
	ldrh r1, [r4]
	adds r0, r5, 0
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	ldrh r1, [r4]
	adds r0, r2, 0
	eors r0, r1
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r0, 0x2
	add r12, r0
	subs r3, 0x1
	cmp r3, 0
	bne _080A3AA8
_080A3ACE:
	lsls r0, r7, 1
	b _080A3AFA
_080A3AD2:
	movs r3, 0
	adds r2, r1, 0x1
	cmp r3, r1
	bgt _080A3AF8
	adds r3, r2, 0
_080A3ADC:
	ldrh r0, [r4]
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	movs r5, 0x2
	add r12, r5
	ldrh r0, [r4]
	mov r1, r12
	strh r0, [r1]
	adds r4, 0x2
	add r12, r5
	subs r3, 0x1
	cmp r3, 0
	bne _080A3ADC
_080A3AF8:
	lsls r0, r2, 1
_080A3AFA:
	add r8, r0
	mov r2, r9
	ldrb r2, [r2, 0x4]
	cmp r8, r2
	blt _080A3A28
_080A3B04:
	mov r3, r8
	cmp r3, 0x3F
	bgt _080A3B1E
	movs r0, 0
_080A3B0C:
	mov r4, r12
	strh r0, [r4]
	movs r5, 0x2
	add r12, r5
	movs r1, 0x1
	add r8, r1
	mov r2, r8
	cmp r2, 0x3F
	ble _080A3B0C
_080A3B1E:
	ldr r1, [sp, 0xC]
	mov r3, r9
	ldrb r3, [r3, 0x5]
	cmp r1, r3
	bge _080A3B2A
	b _080A3948
_080A3B2A:
	ldr r4, [sp, 0x4]
	movs r5, 0x10
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge _080A3B5E
	movs r2, 0
_080A3B36:
	adds r1, 0x1
	str r1, [sp, 0xC]
	movs r0, 0x3F
	mov r8, r0
_080A3B3E:
	mov r1, r12
	strh r2, [r1]
	movs r3, 0x2
	add r12, r3
	movs r4, 0x1
	negs r4, r4
	add r8, r4
	mov r5, r8
	cmp r5, 0
	bge _080A3B3E
	ldr r1, [sp, 0xC]
	ldr r3, [sp, 0x4]
	movs r4, 0x10
	ldrsh r0, [r3, r4]
	cmp r1, r0
	blt _080A3B36
_080A3B5E:
	ldr r2, [sp, 0x8]
	ldr r5, [sp, 0x4]
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r2, r0
	bge _080A3B6C
	b _080A392A
_080A3B6C:
	adds r0, r6, 0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A3908

	thumb_func_start sub_80A3B80
sub_80A3B80:
	push {r4,lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r4, _080A3BA8
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080A3BA2
	adds r4, 0x4
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _080A3BAC
	adds r0, r3, r1
	strb r2, [r0]
_080A3BA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3BA8: .4byte 0x0000046c
_080A3BAC: .4byte 0x00000471
	thumb_func_end sub_80A3B80

	thumb_func_start sub_80A3BB0
sub_80A3BB0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r6, r1, 0
	movs r0, 0x91
	lsls r0, 3
	adds r0, r5
	mov r8, r0
	cmp r1, 0
	blt _080A3BD4
	cmp r1, 0x1
	ble _080A3BD4
	cmp r1, 0x4
	ble _080A3C00
_080A3BD4:
	ldr r1, _080A3BFC
	adds r0, r5, r1
	movs r1, 0x1
	str r1, [r0]
	movs r2, 0xA7
	lsls r2, 3
	adds r0, r5, r2
	movs r1, 0
	ldrsh r3, [r0, r1]
	movs r0, 0
	cmp r6, 0x1
	bne _080A3BEE
	movs r0, 0x1
_080A3BEE:
	str r0, [sp]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A3D40
	b _080A3C48
	.align 2, 0
_080A3BFC: .4byte 0x00000474
_080A3C00:
	ldr r2, _080A3C88
	adds r0, r5, r2
	movs r7, 0x2
	str r7, [r0]
	movs r0, 0xA7
	lsls r0, 3
	adds r4, r5, r0
	movs r2, 0
	ldrsh r0, [r4, r2]
	subs r3, r0, 0x1
	movs r0, 0
	cmp r1, 0x4
	bne _080A3C1C
	movs r0, 0x1
_080A3C1C:
	str r0, [sp]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl sub_80A3D40
	movs r1, 0x9B
	lsls r1, 3
	adds r0, r5, r1
	movs r1, 0
	ldrsh r2, [r4, r1]
	subs r2, 0x1
	adds r3, r7, 0
	eors r3, r6
	negs r1, r3
	orrs r1, r3
	lsrs r1, 31
	str r1, [sp]
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_80A3D40
_080A3C48:
	movs r6, 0
	ldr r2, _080A3C88
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r6, r0
	bge _080A3CF0
	movs r0, 0x8F
	lsls r0, 3
	adds r7, r5, r0
	mov r4, r8
_080A3C5C:
	adds r0, r5, 0
	adds r1, r6, 0
	ldr r2, _080A3C8C
	bl sub_80A456C
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080A3C72
	cmp r0, 0x2
	beq _080A3CB4
_080A3C72:
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0x1
	beq _080A3C94
	cmp r0, 0x1
	ble _080A3C82
	cmp r0, 0x2
	beq _080A3C9C
_080A3C82:
	ldr r0, _080A3C90
	b _080A3CD6
	.align 2, 0
_080A3C88: .4byte 0x00000474
_080A3C8C: .4byte gUnknown_8117314
_080A3C90: .4byte sub_80A3EBC
_080A3C94:
	ldr r0, _080A3C98
	b _080A3CD6
	.align 2, 0
_080A3C98: .4byte sub_80A3EF4
_080A3C9C:
	ldrb r0, [r4, 0x6]
	ldr r1, _080A3CAC
	cmp r0, 0
	beq _080A3CA6
	ldr r1, _080A3CB0
_080A3CA6:
	str r1, [r4, 0x18]
	b _080A3CD8
	.align 2, 0
_080A3CAC: .4byte sub_80A4088
_080A3CB0: .4byte sub_80A41C4
_080A3CB4:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080A3CCC
	cmp r0, 0x1
	ble _080A3CC4
	cmp r0, 0x2
	beq _080A3CD4
_080A3CC4:
	ldr r0, _080A3CC8
	b _080A3CD6
	.align 2, 0
_080A3CC8: .4byte sub_80A3ED4
_080A3CCC:
	ldr r0, _080A3CD0
	b _080A3CD6
	.align 2, 0
_080A3CD0: .4byte sub_80A3F94
_080A3CD4:
	ldr r0, _080A3D34
_080A3CD6:
	str r0, [r4, 0x18]
_080A3CD8:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80A3E14
	adds r7, 0x8
	adds r4, 0x50
	adds r6, 0x1
	ldr r2, _080A3D38
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r6, r0
	blt _080A3C5C
_080A3CF0:
	ldr r1, _080A3D38
	adds r0, r5, r1
	ldr r6, [r0]
	cmp r6, 0x1
	bgt _080A3D26
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 4
	mov r2, r8
	adds r4, r0, r2
_080A3D04:
	adds r0, r5, 0
	adds r1, r6, 0
	ldr r2, _080A3D3C
	bl sub_80A456C
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_80A3D40
	adds r4, 0x50
	adds r6, 0x1
	cmp r6, 0x1
	ble _080A3D04
_080A3D26:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D34: .4byte sub_80A4358
_080A3D38: .4byte 0x00000474
_080A3D3C: .4byte gUnknown_8117314
	thumb_func_end sub_80A3BB0

	thumb_func_start sub_80A3D40
sub_80A3D40:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r3
	ldr r1, [sp, 0x1C]
	movs r3, 0xA5
	lsls r3, 3
	adds r0, r5, r3
	ldrh r0, [r0]
	strh r0, [r4]
	strh r2, [r4, 0x2]
	mov r7, r8
	strh r7, [r4, 0x4]
	strb r1, [r4, 0x6]
	ldr r1, _080A3E10
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [r4, 0x8]
	subs r3, 0xDB
	adds r0, r5, r3
	ldrb r0, [r0]
	str r0, [r4, 0xC]
	movs r7, 0x89
	lsls r7, 3
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r4, 0x10]
	subs r1, 0x3
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r4, 0x14]
	adds r3, 0xFB
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [r4, 0x1C]
	movs r3, 0
	cmp r3, r8
	bge _080A3DE0
	adds r7, 0xF0
	adds r6, r5, r7
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r2, r0
	bge _080A3DE0
	lsls r0, r2, 2
	adds r7, 0x14
	adds r0, r7
	adds r1, r0, r5
	movs r0, 0x20
	adds r0, r4
	mov r12, r0
	movs r7, 0x28
	adds r7, r4
	mov r9, r7
_080A3DB6:
	ldr r0, [r1]
	mov r7, r12
	adds r7, 0x4
	mov r12, r7
	subs r7, 0x4
	stm r7!, {r0}
	ldr r0, [r1, 0x8]
	mov r7, r9
	adds r7, 0x4
	mov r9, r7
	subs r7, 0x4
	stm r7!, {r0}
	adds r3, 0x1
	adds r1, 0x4
	adds r2, 0x1
	cmp r3, r8
	bge _080A3DE0
	movs r7, 0
	ldrsh r0, [r6, r7]
	cmp r2, r0
	blt _080A3DB6
_080A3DE0:
	cmp r3, 0x1
	bgt _080A3DF8
	movs r1, 0
	lsls r0, r3, 2
	adds r0, 0x20
	adds r0, r4
_080A3DEC:
	str r1, [r0]
	str r1, [r0, 0x8]
	adds r0, 0x4
	adds r3, 0x1
	cmp r3, 0x1
	ble _080A3DEC
_080A3DF8:
	movs r0, 0x8F
	lsls r0, 3
	adds r1, r5, r0
	adds r0, r4, 0
	bl sub_80A3E14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A3E10: .4byte 0x0000044c
	thumb_func_end sub_80A3D40

	thumb_func_start sub_80A3E14
sub_80A3E14:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r0, r1, 0
	ldr r1, [r0]
	mov r8, r1
	str r1, [r4, 0x30]
	cmp r1, 0
	bge _080A3E2A
	adds r1, 0x7
_080A3E2A:
	asrs r6, r1, 3
	str r6, [r4, 0x38]
	ldr r7, [r0, 0x4]
	str r7, [r4, 0x34]
	adds r0, r7, 0
	cmp r7, 0
	bge _080A3E3A
	adds r0, r7, 0x7
_080A3E3A:
	asrs r5, r0, 3
	str r5, [r4, 0x3C]
	movs r3, 0
	ldrsh r2, [r4, r3]
	cmp r2, 0x1
	beq _080A3E60
	cmp r2, 0x1
	bgt _080A3E50
	cmp r2, 0
	beq _080A3E56
	b _080A3EA4
_080A3E50:
	cmp r2, 0x2
	beq _080A3E7E
	b _080A3EA4
_080A3E56:
	str r2, [r4, 0x40]
	str r2, [r4, 0x44]
	str r2, [r4, 0x48]
	str r2, [r4, 0x4C]
	b _080A3EA4
_080A3E60:
	lsrs r1, 31
	adds r1, r6, r1
	asrs r1, 1
	str r1, [r4, 0x40]
	lsrs r0, 31
	adds r0, r5, r0
	asrs r0, 1
	str r0, [r4, 0x44]
	lsls r1, 4
	mov r2, r8
	subs r1, r2, r1
	str r1, [r4, 0x48]
	lsls r0, 4
	subs r0, r7, r0
	b _080A3EA2
_080A3E7E:
	adds r0, r6, 0
	movs r1, 0x3
	bl __divsi3
	str r0, [r4, 0x40]
	adds r0, r5, 0
	movs r1, 0x3
	bl __divsi3
	str r0, [r4, 0x44]
	lsls r0, r6, 3
	mov r3, r8
	subs r0, r3, r0
	str r0, [r4, 0x48]
	adds r0, r7, 0
	movs r1, 0x18
	bl __modsi3
_080A3EA2:
	str r0, [r4, 0x4C]
_080A3EA4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3E14

	thumb_func_start sub_80A3EB0
sub_80A3EB0:
	push {lr}
	ldr r1, [r0, 0x18]
	bl _call_via_r1
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EB0

	thumb_func_start sub_80A3EBC
sub_80A3EBC:
	push {lr}
	ldr r0, [r0, 0x28]
	movs r2, 0
	movs r1, 0x80
	lsls r1, 3
_080A3EC6:
	strh r2, [r0]
	adds r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _080A3EC6
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EBC

	thumb_func_start sub_80A3ED4
sub_80A3ED4:
	push {lr}
	ldr r1, [r0, 0x28]
	ldr r0, [r0, 0x2C]
	movs r3, 0
	movs r2, 0x80
	lsls r2, 3
_080A3EE0:
	strh r3, [r1]
	adds r1, 0x2
	strh r3, [r0]
	adds r0, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _080A3EE0
	pop {r0}
	bx r0
	thumb_func_end sub_80A3ED4

	thumb_func_start sub_80A3EF4
sub_80A3EF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r1, [r0, 0x44]
	lsls r1, 6
	ldr r2, [r0, 0x40]
	adds r1, r2
	lsls r1, 1
	ldr r2, [r0, 0x20]
	adds r2, r1
	movs r1, 0
	mov r12, r1
	ldr r3, [r0, 0x28]
	str r3, [sp, 0xC]
	ldr r0, [r0, 0x1C]
	mov r10, r0
	mov r0, sp
	str r0, [sp, 0x8]
_080A3F1E:
	adds r5, r2, 0
	movs r2, 0x80
	adds r2, r5
	mov r9, r2
	adds r1, 0x1
	mov r8, r1
	ldr r1, [sp, 0x8]
	mov r3, r12
	lsls r0, r3, 1
	ldr r2, [sp, 0xC]
	adds r0, r2
	movs r2, 0x1
_080A3F36:
	stm r1!, {r0}
	adds r0, 0x40
	movs r3, 0x20
	add r12, r3
	subs r2, 0x1
	cmp r2, 0
	bge _080A3F36
	movs r4, 0
	mov r7, sp
_080A3F48:
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r10
	adds r3, r1, r0
	adds r5, 0x2
	adds r6, r4, 0x1
	adds r4, r7, 0
	movs r2, 0x1
_080A3F5C:
	ldr r0, [r4]
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, 0x2
	adds r0, 0x2
	ldrh r1, [r3]
	strh r1, [r0]
	adds r3, 0x2
	adds r0, 0x2
	stm r4!, {r0}
	subs r2, 0x1
	cmp r2, 0
	bge _080A3F5C
	adds r4, r6, 0
	cmp r4, 0xF
	ble _080A3F48
	mov r2, r9
	mov r1, r8
	cmp r1, 0xA
	ble _080A3F1E
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3EF4

	thumb_func_start sub_80A3F94
sub_80A3F94:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	ldr r1, [r0, 0x44]
	lsls r1, 6
	ldr r2, [r0, 0x40]
	adds r1, r2
	lsls r1, 1
	ldr r2, [r0, 0x20]
	adds r3, r2, r1
	ldr r2, [r0, 0x24]
	adds r2, r1
	movs r1, 0
	ldr r4, [r0, 0x28]
	str r4, [sp, 0x2C]
	ldr r5, [r0, 0x2C]
	str r5, [sp, 0x18]
	ldr r0, [r0, 0x1C]
	str r0, [sp, 0x1C]
	mov r0, sp
	str r0, [sp, 0x10]
	mov r4, sp
	adds r4, 0x8
	str r4, [sp, 0x14]
	movs r5, 0
	str r5, [sp, 0x30]
_080A3FCE:
	mov r8, r3
	mov r12, r2
	mov r0, r8
	adds r0, 0x80
	str r0, [sp, 0x20]
	mov r4, r12
	adds r4, 0x80
	str r4, [sp, 0x24]
	adds r1, 0x1
	str r1, [sp, 0x28]
	ldr r3, [sp, 0x14]
	ldr r2, [sp, 0x10]
	ldr r5, [sp, 0x30]
	ldr r0, [sp, 0x18]
	adds r1, r5, r0
	ldr r4, [sp, 0x2C]
	adds r0, r5, r4
	movs r5, 0x1
_080A3FF2:
	stm r2!, {r0}
	stm r3!, {r1}
	adds r1, 0x40
	adds r0, 0x40
	ldr r4, [sp, 0x30]
	adds r4, 0x40
	str r4, [sp, 0x30]
	subs r5, 0x1
	cmp r5, 0
	bge _080A3FF2
	movs r2, 0
	ldr r5, [sp, 0x1C]
	mov r9, r5
_080A400C:
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r4, r1, r0
	movs r5, 0x2
	add r8, r5
	mov r0, r12
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r3, r1, r0
	add r12, r5
	movs r5, 0
	adds r2, 0x1
	mov r10, r2
	ldr r7, [sp, 0x14]
	ldr r6, [sp, 0x10]
_080A4038:
	ldr r1, [r6]
	ldr r2, [r7]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	stm r6!, {r1}
	stm r7!, {r2}
	adds r5, 0x1
	cmp r5, 0x1
	ble _080A4038
	mov r2, r10
	cmp r2, 0xF
	ble _080A400C
	ldr r3, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r1, [sp, 0x28]
	cmp r1, 0xA
	ble _080A3FCE
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A3F94

	thumb_func_start sub_80A4088
sub_80A4088:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r0, [r4, 0x38]
	movs r1, 0x3
	bl __modsi3
	adds r7, r0, 0
	ldr r0, [r4, 0x44]
	lsls r0, 6
	ldr r1, [r4, 0x40]
	adds r0, r1
	lsls r0, 1
	ldr r1, [r4, 0x20]
	adds r1, r0
	movs r0, 0
	mov r8, r0
	ldr r2, [r4, 0x28]
	str r2, [sp, 0xC]
	ldr r4, [r4, 0x1C]
	mov r12, r4
_080A40BA:
	adds r5, r1, 0
	movs r1, 0x80
	adds r1, r5
	mov r9, r1
	adds r0, 0x1
	mov r10, r0
	mov r1, sp
	mov r2, r8
	lsls r0, r2, 1
	ldr r2, [sp, 0xC]
	adds r0, r2
	movs r3, 0x2
_080A40D2:
	stm r1!, {r0}
	adds r0, 0x40
	movs r2, 0x20
	add r8, r2
	subs r3, 0x1
	cmp r3, 0
	bge _080A40D2
	cmp r7, 0
	beq _080A412E
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	adds r5, 0x2
	cmp r7, 0x1
	bne _080A4116
	adds r2, 0x2
	mov r4, sp
	movs r3, 0x2
_080A40FC:
	ldr r0, [r4]
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, 0x2
	ldrh r1, [r2, 0x2]
	strh r1, [r0]
	adds r0, 0x2
	stm r4!, {r0}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A40FC
	b _080A412E
_080A4116:
	adds r2, 0x4
	mov r4, sp
	movs r3, 0x2
_080A411C:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, 0x2
	stm r4!, {r1}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A411C
_080A412E:
	movs r3, 0
_080A4130:
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	adds r5, 0x2
	adds r6, r3, 0x1
	mov r4, sp
	movs r3, 0x2
_080A4144:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	stm r4!, {r1}
	subs r3, 0x1
	cmp r3, 0
	bge _080A4144
	adds r3, r6, 0
	cmp r3, 0x9
	ble _080A4130
	cmp r7, 0x1
	beq _080A41AA
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r12
	adds r2, r1, r0
	cmp r7, 0
	bne _080A4198
	mov r4, sp
	movs r3, 0x2
_080A4184:
	ldm r4!, {r0}
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x2]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4184
	b _080A41AA
_080A4198:
	mov r4, sp
	movs r3, 0x2
_080A419C:
	ldm r4!, {r1}
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A419C
_080A41AA:
	mov r1, r9
	mov r0, r10
	cmp r0, 0x7
	ble _080A40BA
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4088

	thumb_func_start sub_80A41C4
sub_80A41C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	ldr r0, [r0, 0x38]
	movs r1, 0x3
	bl __modsi3
	str r0, [sp, 0xC]
	mov r0, r8
	ldr r2, [r0, 0x44]
	lsls r0, r2, 6
	mov r1, r8
	ldr r3, [r1, 0x40]
	adds r0, r3
	lsls r0, 1
	ldr r1, [r1, 0x20]
	adds r4, r1, r0
	movs r0, 0
	str r0, [sp, 0x10]
	mov r1, r8
	ldr r0, [r1, 0xC]
	subs r0, r2
	mov r10, r0
	ldr r0, [r1, 0x8]
	subs r0, r3
	str r0, [sp, 0x14]
	movs r2, 0
_080A4202:
	ldr r5, [sp, 0x14]
	mov r3, r10
	cmp r3, 0
	ble _080A4212
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	b _080A4222
_080A4212:
	mov r1, r8
	ldr r1, [r1, 0xC]
	mov r10, r1
	mov r3, r8
	ldr r0, [r3, 0x40]
	lsls r0, 1
	ldr r1, [r3, 0x20]
	adds r4, r1, r0
_080A4222:
	adds r6, r4, 0
	mov r0, r8
	ldr r1, [r0, 0x28]
	ldrh r7, [r4]
	ldr r3, [r0, 0x1C]
	mov r9, r3
	adds r0, r4, 0x2
	mov r12, r0
	adds r4, 0x80
	str r4, [sp, 0x18]
	adds r2, 0x1
	str r2, [sp, 0x1C]
	mov r2, sp
	ldr r3, [sp, 0x10]
	lsls r0, r3, 1
	adds r0, r1
	movs r3, 0x2
_080A4244:
	stm r2!, {r0}
	adds r0, 0x40
	ldr r4, [sp, 0x10]
	adds r4, 0x20
	str r4, [sp, 0x10]
	subs r3, 0x1
	cmp r3, 0
	bge _080A4244
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080A42B2
	lsls r0, r7, 3
	adds r0, r7
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	mov r6, r12
	ldr r3, [sp, 0xC]
	cmp r3, 0x1
	bne _080A428C
	adds r2, 0x2
	mov r4, sp
	movs r3, 0x2
_080A4272:
	ldr r0, [r4]
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, 0x2
	ldrh r1, [r2, 0x2]
	strh r1, [r0]
	adds r0, 0x2
	stm r4!, {r0}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4272
	b _080A42A4
_080A428C:
	adds r2, 0x4
	mov r4, sp
	movs r3, 0x2
_080A4292:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, 0x2
	stm r4!, {r1}
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4292
_080A42A4:
	subs r5, 0x1
	cmp r5, 0
	bgt _080A42B2
	mov r4, r8
	ldr r5, [r4, 0x8]
	lsls r0, r5, 1
	subs r6, r0
_080A42B2:
	movs r3, 0
_080A42B4:
	ldrh r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	adds r6, 0x2
	subs r5, 0x1
	adds r7, r3, 0x1
	mov r4, sp
	movs r3, 0x2
_080A42CA:
	ldr r1, [r4]
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	adds r1, 0x2
	stm r4!, {r1}
	subs r3, 0x1
	cmp r3, 0
	bge _080A42CA
	cmp r5, 0
	bgt _080A42F8
	mov r3, r8
	ldr r5, [r3, 0x8]
	lsls r0, r5, 1
	subs r6, r0
_080A42F8:
	adds r3, r7, 0
	cmp r3, 0x9
	ble _080A42B4
	ldr r4, [sp, 0xC]
	cmp r4, 0x1
	beq _080A433E
	ldrh r1, [r6]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r1, r9
	adds r2, r1, r0
	cmp r4, 0
	bne _080A432C
	mov r4, sp
	movs r3, 0x2
_080A4318:
	ldm r4!, {r0}
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	strh r1, [r0, 0x2]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4318
	b _080A433E
_080A432C:
	mov r4, sp
	movs r3, 0x2
_080A4330:
	ldm r4!, {r1}
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x6
	subs r3, 0x1
	cmp r3, 0
	bge _080A4330
_080A433E:
	ldr r4, [sp, 0x18]
	ldr r2, [sp, 0x1C]
	cmp r2, 0x7
	bgt _080A4348
	b _080A4202
_080A4348:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A41C4

	thumb_func_start sub_80A4358
sub_80A4358:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	ldr r0, [r4, 0x38]
	movs r1, 0x3
	bl __modsi3
	str r0, [sp, 0x18]
	ldr r0, [r4, 0x44]
	lsls r0, 6
	ldr r1, [r4, 0x40]
	adds r0, r1
	lsls r0, 1
	ldr r1, [r4, 0x20]
	adds r2, r1, r0
	ldr r1, [r4, 0x24]
	adds r1, r0
	movs r0, 0
	ldr r3, [r4, 0x28]
	str r3, [sp, 0x24]
	ldr r5, [r4, 0x2C]
	str r5, [sp, 0x28]
	ldr r4, [r4, 0x1C]
	str r4, [sp, 0x20]
	mov r3, sp
	adds r3, 0xC
	str r3, [sp, 0x1C]
	movs r4, 0
	str r4, [sp, 0x38]
_080A439A:
	mov r12, r2
	mov r8, r1
	mov r5, r12
	adds r5, 0x80
	str r5, [sp, 0x30]
	adds r1, 0x80
	str r1, [sp, 0x34]
	adds r0, 0x1
	str r0, [sp, 0x2C]
	add r3, sp, 0xC
	mov r2, sp
	ldr r4, [sp, 0x38]
	ldr r5, [sp, 0x28]
	adds r1, r4, r5
	ldr r5, [sp, 0x24]
	adds r0, r4, r5
	movs r5, 0x2
_080A43BC:
	stm r2!, {r0}
	stm r3!, {r1}
	adds r1, 0x40
	adds r0, 0x40
	ldr r4, [sp, 0x38]
	adds r4, 0x40
	str r4, [sp, 0x38]
	subs r5, 0x1
	cmp r5, 0
	bge _080A43BC
	ldr r5, [sp, 0x18]
	cmp r5, 0
	beq _080A445C
	mov r0, r12
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r4, r1, r0
	movs r3, 0x2
	add r12, r3
	mov r5, r8
	ldrh r1, [r5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r3, r1, r0
	movs r5, 0x2
	add r8, r5
	ldr r0, [sp, 0x18]
	cmp r0, 0x1
	bne _080A4434
	adds r4, 0x2
	adds r3, 0x2
	ldr r7, [sp, 0x1C]
	mov r6, sp
_080A4408:
	ldr r1, [r6]
	ldr r2, [r7]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r4, 0x2]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r3, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	stm r6!, {r1}
	stm r7!, {r2}
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A4408
	b _080A445C
_080A4434:
	adds r4, 0x4
	adds r3, 0x4
	ldr r6, [sp, 0x1C]
	mov r2, sp
	movs r5, 0x2
_080A443E:
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, 0x2
	stm r2!, {r1}
	ldr r1, [r6]
	ldrh r0, [r3]
	strh r0, [r1]
	adds r1, 0x2
	stm r6!, {r1}
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A443E
_080A445C:
	movs r2, 0
	ldr r1, [sp, 0x20]
	mov r9, r1
_080A4462:
	mov r3, r12
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	mov r5, r9
	adds r4, r5, r0
	movs r0, 0x2
	add r12, r0
	mov r3, r8
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r3, r5, r0
	movs r5, 0x2
	add r8, r5
	movs r5, 0
	adds r2, 0x1
	mov r10, r2
	mov r7, sp
	add r6, sp, 0xC
_080A448E:
	ldr r1, [r7]
	ldr r2, [r6]
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r4]
	strh r0, [r1]
	adds r4, 0x2
	adds r1, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, 0x2
	adds r2, 0x2
	stm r7!, {r1}
	stm r6!, {r2}
	adds r5, 0x1
	cmp r5, 0x2
	ble _080A448E
	mov r2, r10
	cmp r2, 0x9
	ble _080A4462
	ldr r0, [sp, 0x18]
	cmp r0, 0x1
	beq _080A453A
	mov r3, r12
	ldrh r1, [r3]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	ldr r5, [sp, 0x20]
	adds r4, r5, r0
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r3, r5, r0
	ldr r1, [sp, 0x18]
	cmp r1, 0
	bne _080A451E
	ldr r7, [sp, 0x1C]
	mov r6, sp
	movs r5, 0x2
_080A44FE:
	ldm r6!, {r1}
	ldm r7!, {r2}
	ldrh r0, [r4]
	strh r0, [r1]
	ldrh r0, [r4, 0x2]
	strh r0, [r1, 0x2]
	ldrh r0, [r3]
	strh r0, [r2]
	ldrh r0, [r3, 0x2]
	strh r0, [r2, 0x2]
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A44FE
	b _080A453A
_080A451E:
	ldr r6, [sp, 0x1C]
	mov r2, sp
	movs r5, 0x2
_080A4524:
	ldm r2!, {r1}
	ldrh r0, [r4]
	strh r0, [r1]
	ldm r6!, {r1}
	ldrh r0, [r3]
	strh r0, [r1]
	adds r4, 0x6
	adds r3, 0x6
	subs r5, 0x1
	cmp r5, 0
	bge _080A4524
_080A453A:
	ldr r2, [sp, 0x30]
	ldr r1, [sp, 0x34]
	ldr r0, [sp, 0x2C]
	cmp r0, 0x7
	bgt _080A4546
	b _080A439A
_080A4546:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4358

	thumb_func_start sub_80A4558
sub_80A4558:
	lsls r1, 3
	movs r3, 0x8F
	lsls r3, 3
	adds r0, r3
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	thumb_func_end sub_80A4558

	thumb_func_start sub_80A456C
sub_80A456C:
	lsls r1, 3
	movs r3, 0x8F
	lsls r3, 3
	adds r0, r3
	adds r0, r1
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0]
	str r2, [r0, 0x4]
	bx lr
	thumb_func_end sub_80A456C

	thumb_func_start sub_80A4580
sub_80A4580:
	push {r4,lr}
	adds r3, r2, 0
	lsls r2, r1, 2
	adds r2, r1
	lsls r2, 4
	movs r1, 0x91
	lsls r1, 3
	adds r2, r1
	adds r2, r0, r2
	ldr r0, [r3]
	cmp r0, 0
	bge _080A45AE
	ldrb r0, [r2, 0x6]
	ldr r4, [r3, 0x4]
	cmp r0, 0
	beq _080A45CA
	ldr r1, [r2, 0x10]
_080A45A2:
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	cmp r0, 0
	blt _080A45A2
	b _080A45CC
_080A45AE:
	ldr r1, [r2, 0x10]
	ldr r4, [r3, 0x4]
	cmp r0, r1
	blt _080A45CC
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45C8
_080A45BC:
	ldr r0, [r3]
	subs r0, r1
	str r0, [r3]
	cmp r0, r1
	bge _080A45BC
	b _080A45CC
_080A45C8:
	subs r0, r1, 0x1
_080A45CA:
	str r0, [r3]
_080A45CC:
	cmp r4, 0
	bge _080A45E4
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45FE
	ldr r1, [r2, 0x14]
_080A45D8:
	ldr r0, [r3, 0x4]
	adds r0, r1
	str r0, [r3, 0x4]
	cmp r0, 0
	blt _080A45D8
	b _080A4600
_080A45E4:
	ldr r1, [r2, 0x14]
	cmp r4, r1
	blt _080A4600
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _080A45FC
_080A45F0:
	ldr r0, [r3, 0x4]
	subs r0, r1
	str r0, [r3, 0x4]
	cmp r0, r1
	bge _080A45F0
	b _080A4600
_080A45FC:
	subs r0, r1, 0x1
_080A45FE:
	str r0, [r3, 0x4]
_080A4600:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A4580

	thumb_func_start sub_80A4608
sub_80A4608:
	movs r3, 0x89
	lsls r3, 3
	adds r2, r0, r3
	ldrb r2, [r2]
	str r2, [r1]
	ldr r2, _080A461C
	adds r0, r2
	ldrb r0, [r0]
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_080A461C: .4byte 0x00000449
	thumb_func_end sub_80A4608

	thumb_func_start sub_80A4620
sub_80A4620:
	movs r3, 0x89
	lsls r3, 3
	adds r2, r0, r3
	ldrb r2, [r2]
	lsls r2, 3
	str r2, [r1]
	ldr r2, _080A4638
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 3
	str r0, [r1, 0x4]
	bx lr
	.align 2, 0
_080A4638: .4byte 0x00000449
	thumb_func_end sub_80A4620

	thumb_func_start sub_80A463C
sub_80A463C:
	movs r3, 0
	str r3, [r1]
	str r3, [r1, 0x4]
	movs r3, 0x89
	lsls r3, 3
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, 11
	str r1, [r2]
	ldr r1, _080A465C
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 11
	str r0, [r2, 0x4]
	bx lr
	.align 2, 0
_080A465C: .4byte 0x00000449
	thumb_func_end sub_80A463C

	thumb_func_start sub_80A4660
sub_80A4660:
	push {r4-r7,lr}
	adds r6, r3, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r1, _080A4678
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _080A467C
	movs r0, 0
	b _080A46B6
	.align 2, 0
_080A4678: .4byte 0x00000544
_080A467C:
	ldr r0, [r2, 0x4]
	lsls r0, 8
	ldr r1, [r2]
	adds r0, r1
	ldr r1, _080A46BC
	adds r0, r1
	adds r4, r0
	ldr r3, [r6, 0x4]
	cmp r3, 0
	ble _080A46B4
	movs r7, 0x80
	lsls r7, 1
_080A4694:
	ldr r1, [r6]
	adds r2, r4, 0
	cmp r1, 0
	ble _080A46AC
_080A469C:
	ldrb r0, [r2]
	ands r0, r5
	adds r2, 0x1
	cmp r0, 0
	bne _080A46B6
	subs r1, 0x1
	cmp r1, 0
	bgt _080A469C
_080A46AC:
	adds r4, r7
	subs r3, 0x1
	cmp r3, 0
	bgt _080A4694
_080A46B4:
	movs r0, 0
_080A46B6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A46BC: .4byte 0x00000405
	thumb_func_end sub_80A4660

	thumb_func_start sub_80A46C0
sub_80A46C0:
	push {r4-r7,lr}
	adds r6, r3, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r1, _080A46D8
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	bne _080A46DC
_080A46D2:
	movs r0, 0
	b _080A4716
	.align 2, 0
_080A46D8: .4byte 0x00000544
_080A46DC:
	ldr r0, [r2, 0x4]
	lsls r0, 8
	ldr r1, [r2]
	adds r0, r1
	ldr r1, _080A471C
	adds r0, r1
	adds r4, r0
	ldr r3, [r6, 0x4]
	cmp r3, 0
	ble _080A4714
	movs r7, 0x80
	lsls r7, 1
_080A46F4:
	ldr r1, [r6]
	adds r2, r4, 0
	cmp r1, 0
	ble _080A470C
_080A46FC:
	ldrb r0, [r2]
	ands r0, r5
	adds r2, 0x1
	cmp r0, r5
	bne _080A46D2
	subs r1, 0x1
	cmp r1, 0
	bgt _080A46FC
_080A470C:
	adds r4, r7
	subs r3, 0x1
	cmp r3, 0
	bgt _080A46F4
_080A4714:
	movs r0, 0x1
_080A4716:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A471C: .4byte 0x00000405
	thumb_func_end sub_80A46C0

	thumb_func_start sub_80A4720
sub_80A4720:
	lsls r1, 2
	ldr r3, _080A473C
	adds r0, r3
	adds r0, r1
	ldr r1, [r2, 0x4]
	lsls r1, 7
	ldr r3, [r0]
	adds r3, r1
	ldr r0, [r2]
	lsls r0, 1
	adds r3, r0
	ldrh r0, [r3]
	bx lr
	.align 2, 0
_080A473C: .4byte 0x0000054c
	thumb_func_end sub_80A4720

	thumb_func_start sub_80A4740
sub_80A4740:
	push {r4,lr}
	lsls r1, 2
	ldr r4, _080A4760
	adds r0, r4
	adds r0, r1
	ldr r1, [r2, 0x4]
	lsls r1, 7
	ldr r4, [r0]
	adds r4, r1
	ldr r0, [r2]
	lsls r0, 1
	adds r4, r0
	strh r3, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4760: .4byte 0x0000054c
	thumb_func_end sub_80A4740

	thumb_func_start sub_80A4764
sub_80A4764:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	ldr r0, _080A47E8
	add r0, r9
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A4784
	b _080A49CE
_080A4784:
	ldr r0, _080A47EC
	add r0, r9
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, 0
	beq _080A4864
	mov r4, r9
	ldr r0, _080A47F0
	add r0, r9
	ldr r5, [r0]
	ldr r0, _080A47F4
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 20
	lsrs r6, r0, 16
	movs r7, 0
	ldr r0, _080A47F8
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _080A484C
_080A47B2:
	ldr r1, [r4, 0x4]
	cmp r1, 0
	beq _080A4832
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _080A4832
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	cmp r0, 0
	bgt _080A4808
	ldr r0, _080A47FC
	add r0, r9
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A4800
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
	ldrh r0, [r5, 0x2]
	strh r0, [r4]
	str r1, [r4, 0x8]
	b _080A480C
	.align 2, 0
_080A47E8: .4byte 0x00000444
_080A47EC: .4byte 0x00000466
_080A47F0: .4byte 0x0000046c
_080A47F4: .4byte 0x0000052c
_080A47F8: .4byte 0x00000464
_080A47FC: .4byte 0x00000471
_080A4800:
	strh r0, [r4]
	strh r0, [r4, 0x2]
	str r0, [r4, 0x8]
	b _080A480C
_080A4808:
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
_080A480C:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _080A4832
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	bl sub_8003810
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r4, 0x8]
	movs r2, 0xF
	bl sub_809971C
	ldr r0, [r4, 0x8]
	adds r0, 0x3C
	str r0, [r4, 0x8]
_080A4832:
	adds r7, 0x1
	adds r4, 0x10
	adds r5, 0x4
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, _080A485C
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _080A47B2
_080A484C:
	movs r0, 0x8E
	lsls r0, 3
	add r0, r9
	ldrb r1, [r0]
	ldr r0, _080A4860
	add r0, r9
	strb r1, [r0]
	b _080A48E6
	.align 2, 0
_080A485C: .4byte 0x00000464
_080A4860: .4byte 0x00000471
_080A4864:
	movs r0, 0x88
	lsls r0, 3
	add r0, r9
	ldr r0, [r0]
	cmp r0, 0
	beq _080A48E6
	mov r4, r9
	adds r4, 0xE0
	movs r6, 0xA0
	movs r5, 0x1F
_080A4878:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _080A48DC
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _080A48DC
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _080A48DC
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _080A48B0
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_080A48B0:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	ldrb r1, [r4, 0x14]
	add r0, sp, 0x4
	strb r1, [r0]
	ldrb r1, [r4, 0x15]
	adds r0, 0x1
	strb r1, [r0]
	ldrb r1, [r4, 0x16]
	adds r0, 0x1
	strb r1, [r0]
	ldrb r1, [r4, 0x17]
	adds r0, 0x1
	strb r1, [r0]
	ldr r1, [sp, 0x4]
	str r1, [sp]
	lsls r0, r6, 16
	lsrs r0, 16
	bl sub_8003810
_080A48DC:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bge _080A4878
_080A48E6:
	movs r5, 0
	movs r4, 0x1
_080A48EA:
	movs r2, 0xF8
	lsls r2, 2
	adds r0, r5, r2
	mov r6, r9
	adds r2, r6, r0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080A4942
	ldrh r1, [r2, 0x4]
	subs r0, r1, 0x1
	strh r0, [r2, 0x4]
	lsls r1, 16
	cmp r1, 0
	bgt _080A4942
	ldr r0, [r2, 0x14]
	adds r0, 0x4
	str r0, [r2, 0x14]
	ldr r1, [r2, 0x24]
	lsrs r1, 1
	lsls r1, 1
	ldr r0, [r2, 0x1C]
	adds r0, r1
	str r0, [r2, 0x1C]
	ldrh r0, [r2, 0x2]
	adds r0, 0x1
	movs r3, 0
	strh r0, [r2, 0x2]
	ldr r1, [r2, 0xC]
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x2
	ldrsh r1, [r1, r6]
	cmp r0, r1
	blt _080A4938
	ldr r0, [r2, 0x10]
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x18]
	str r0, [r2, 0x1C]
	strh r3, [r2, 0x2]
_080A4938:
	movs r0, 0x1
	strb r0, [r2, 0x1]
	ldr r0, [r2, 0x14]
	ldr r0, [r0]
	strh r0, [r2, 0x4]
_080A4942:
	adds r5, 0x28
	subs r4, 0x1
	cmp r4, 0
	bge _080A48EA
	movs r4, 0x91
	lsls r4, 3
	add r4, r9
	movs r7, 0x8F
	lsls r7, 3
	add r7, r9
	movs r0, 0
	mov r8, r0
	b _080A49BC
_080A495C:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80A3E14
	adds r0, r4, 0
	bl sub_80A3EB0
	movs r6, 0
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r0, _080A4998
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r5, r1, r0
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x1
	add r8, r2
	movs r1, 0x50
	adds r1, r4
	mov r10, r1
	adds r7, 0x8
	cmp r6, r0
	bge _080A49BA
_080A498E:
	cmp r5, 0
	beq _080A499C
	cmp r5, 0x1
	beq _080A49A6
	b _080A49AE
	.align 2, 0
_080A4998: .4byte 0x00000536
_080A499C:
	ldr r0, [r4, 0x48]
	ldr r1, [r4, 0x4C]
	bl sub_800CCA0
	b _080A49AE
_080A49A6:
	ldr r0, [r4, 0x48]
	ldr r1, [r4, 0x4C]
	bl sub_800CCAC
_080A49AE:
	adds r6, 0x1
	adds r5, 0x1
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r6, r0
	blt _080A498E
_080A49BA:
	mov r4, r10
_080A49BC:
	ldr r0, _080A49E0
	add r0, r9
	ldr r0, [r0]
	cmp r8, r0
	blt _080A495C
	ldr r1, _080A49E4
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080A49CE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49E0: .4byte 0x00000474
_080A49E4: .4byte 0x0000052a
	thumb_func_end sub_80A4764

	thumb_func_start sub_80A49E8
sub_80A49E8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldr r0, _080A4A74
	adds r5, r6, r0
	movs r1, 0xFF
	lsls r1, 2
	adds r4, r6, r1
	ldr r0, _080A4A78
	adds r0, r6
	mov r8, r0
	movs r7, 0x1
_080A4A02:
	ldrb r0, [r5]
	cmp r0, 0
	beq _080A4A1C
	ldr r0, [r4, 0x4]
	ldr r1, [r4]
	ldr r2, [r4, 0x8]
	bl MemoryCopy32
	movs r0, 0
	strb r0, [r5]
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
_080A4A1C:
	adds r5, 0x28
	adds r4, 0x28
	subs r7, 0x1
	cmp r7, 0
	bge _080A4A02
	ldr r1, _080A4A78
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080A4A68
	movs r5, 0
	adds r1, 0xC
	adds r0, r6, r1
	movs r1, 0
	ldrsh r4, [r0, r1]
	movs r1, 0xA7
	lsls r1, 3
	adds r0, r6, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _080A4A60
	movs r0, 0xA7
	lsls r0, 3
	adds r7, r6, r0
_080A4A4E:
	adds r0, r4, 0x2
	bl sub_80098F8
	adds r5, 0x1
	adds r4, 0x1
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r5, r0
	blt _080A4A4E
_080A4A60:
	ldr r0, _080A4A78
	adds r1, r6, r0
	movs r0, 0
	strb r0, [r1]
_080A4A68:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4A74: .4byte 0x000003e1
_080A4A78: .4byte 0x0000052a
	thumb_func_end sub_80A49E8

	thumb_func_start sub_80A4A7C
sub_80A4A7C:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080A4AB8
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r2, r0, 0
	adds r2, 0xE4
	ldr r1, _080A4ABC
	strh r1, [r2]
	ldr r1, _080A4AC0
	movs r3, 0x1
	negs r3, r3
	str r3, [sp]
	movs r2, 0
	bl sub_809D600
	movs r0, 0
	bl sub_80A5E8C
	bl sub_80A4AEC
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4AB8: .4byte gUnknown_3001B6C
_080A4ABC: .4byte 0x0000ffff
_080A4AC0: .4byte gUnknown_811736C
	thumb_func_end sub_80A4A7C

	thumb_func_start sub_80A4AC4
sub_80A4AC4:
	push {r4,lr}
	bl sub_80A4AEC
	bl sub_80A5EBC
	ldr r4, _080A4AE8
	ldr r0, [r4]
	bl sub_809D648
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4AE8: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4AC4

	thumb_func_start sub_80A4AEC
sub_80A4AEC:
	push {r4,lr}
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	ldr r0, _080A4B2C
	ldr r0, [r0]
	ldr r1, _080A4B30
	bl sub_809D754
	ldr r4, _080A4B34
	ldr r0, [r4]
	cmp r0, 0
	beq _080A4B1E
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A4B1E:
	movs r0, 0
	bl sub_80A5EDC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4B2C: .4byte gUnknown_3001B6C
_080A4B30: .4byte gUnknown_8117538
_080A4B34: .4byte gUnknown_3001B70
	thumb_func_end sub_80A4AEC

	thumb_func_start sub_80A4B38
sub_80A4B38:
	push {lr}
	bl nullsub_121
	ldr r0, _080A4B50
	ldr r0, [r0]
	cmp r0, 0
	beq _080A4B4A
	bl sub_80A2D68
_080A4B4A:
	pop {r0}
	bx r0
	.align 2, 0
_080A4B50: .4byte gUnknown_3001B70
	thumb_func_end sub_80A4B38

	thumb_func_start sub_80A4B54
sub_80A4B54:
	push {lr}
	ldr r0, _080A4B6C
	ldr r0, [r0]
	cmp r0, 0
	beq _080A4B62
	bl sub_80A2D88
_080A4B62:
	bl nullsub_122
	pop {r0}
	bx r0
	.align 2, 0
_080A4B6C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A4B54

	thumb_func_start GroundMap_GetStationScript
GroundMap_GetStationScript:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	lsls r4, 16
	asrs r4, 16
	lsls r6, 16
	asrs r6, 16
	lsls r5, 24
	asrs r5, 24
	adds r0, r4, 0
	bl sub_80A77A0
	ldr r1, _080A4BE0
	adds r0, r4, 0
	bl sub_80A77D0
	mov r9, r0
	ldr r1, _080A4BE4
	str r5, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl Log
	lsls r1, r6, 3
	mov r2, r9
	ldr r0, [r2, 0x4]
	adds r0, r1
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r0, [r0, 0x24]
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	mov r1, r8
	str r0, [r1]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	strh r6, [r1, 0x6]
	strb r5, [r1, 0x8]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4BE0: .4byte gUnknown_8117560
_080A4BE4: .4byte gUnknown_811756C
	thumb_func_end GroundMap_GetStationScript

	thumb_func_start sub_80A4BE8
sub_80A4BE8:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	movs r2, 0
	movs r3, 0
	bl GroundMap_GetStationScript
	pop {r0}
	bx r0
	thumb_func_end sub_80A4BE8

	thumb_func_start GroundMap_ExecuteEvent
GroundMap_ExecuteEvent:
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	ldr r1, _080A4C44
	movs r0, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl Log
	movs r0, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_809D710
	cmp r5, 0
	beq _080A4C2C
	mov r1, sp
	movs r0, 0x5
	strh r0, [r1, 0x4]
_080A4C2C:
	ldr r0, _080A4C48
	ldr r0, [r0]
	ldr r3, _080A4C4C
	movs r1, 0
	mov r2, sp
	bl GroundScript_ExecutePP
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4C44: .4byte gUnknown_8117594
_080A4C48: .4byte gUnknown_3001B6C
_080A4C4C: .4byte gUnknown_81175E0
	thumb_func_end GroundMap_ExecuteEvent

	thumb_func_start GroundMap_ExecuteStation
GroundMap_ExecuteStation:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	mov r8, r3
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	lsls r6, 24
	asrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, _080A4CB8
	str r6, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl Log
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl GroundMap_GetStationScript
	mov r0, r8
	cmp r0, 0
	beq _080A4C9C
	add r1, sp, 0x8
	movs r0, 0x5
	strh r0, [r1, 0x4]
_080A4C9C:
	ldr r0, _080A4CBC
	ldr r0, [r0]
	ldr r3, _080A4CC0
	movs r1, 0
	add r2, sp, 0x8
	bl GroundScript_ExecutePP
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4CB8: .4byte gUnknown_81175EC
_080A4CBC: .4byte gUnknown_3001B6C
_080A4CC0: .4byte gUnknown_8117644
	thumb_func_end GroundMap_ExecuteStation

	thumb_func_start GroundMap_ExecuteEnter
GroundMap_ExecuteEnter:
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	ldr r1, _080A4D08
	movs r0, 0
	adds r2, r4, 0
	bl Log
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A4BE8
	mov r1, sp
	movs r3, 0
	movs r2, 0
	movs r0, 0x2
	strh r0, [r1, 0x4]
	mov r0, sp
	strh r2, [r0, 0x6]
	strb r3, [r0, 0x8]
	ldr r0, _080A4D0C
	ldr r0, [r0]
	ldr r3, _080A4D10
	movs r1, 0
	mov r2, sp
	bl GroundScript_ExecutePP
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4D08: .4byte gUnknown_8117650
_080A4D0C: .4byte gUnknown_3001B6C
_080A4D10: .4byte gUnknown_8117698
	thumb_func_end GroundMap_ExecuteEnter

	thumb_func_start sub_80A4D14
sub_80A4D14:
	push {lr}
	ldr r0, _080A4D28
	ldr r0, [r0]
	bl sub_809D678
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_080A4D28: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4D14

	thumb_func_start sub_80A4D2C
sub_80A4D2C:
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	ldr r0, _080A4D44
	ldr r0, [r0]
	bl sub_809D968
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_080A4D44: .4byte gUnknown_3001B6C
	thumb_func_end sub_80A4D2C

	thumb_func_start sub_80A4D48
sub_80A4D48:
	push {lr}
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080A4D74
	ldr r1, _080A4D70
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x5
	beq _080A4D6C
	cmp r0, 0x8
	bne _080A4D74
_080A4D6C:
	movs r0, 0
	b _080A4D76
	.align 2, 0
_080A4D70: .4byte gUnknown_811BAF4
_080A4D74:
	movs r0, 0x1
_080A4D76:
	pop {r1}
	bx r1
	thumb_func_end sub_80A4D48

	thumb_func_start sub_80A4D7C
sub_80A4D7C:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0x9
	beq _080A4D94
	cmp r5, 0x9
	bgt _080A4D90
	cmp r5, 0x2
	beq _080A4DB6
	b _080A4DC4
_080A4D90:
	cmp r5, 0xC
	bne _080A4DC4
_080A4D94:
	movs r0, 0
	movs r1, 0x27
	bl sub_8001658
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 1
	adds r1, r0
	adds r1, r5, r1
	lsls r1, 16
	asrs r5, r1, 16
	b _080A4DC4
_080A4DB6:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A4DC4
	movs r5, 0x3
_080A4DC4:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A4D7C

	thumb_func_start GroundMap_Select
GroundMap_Select:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	ldr r1, _080A4E38
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	movs r0, 0
	bl sub_80A5EDC
	ldr r4, _080A4E3C
	ldr r0, [r4]
	cmp r0, 0
	beq _080A4E08
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A4E08:
	ldr r0, _080A4E40
	movs r1, 0x6
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r4]
	ldr r0, _080A4E44
	ldr r0, [r0]
	adds r0, 0xE4
	strh r5, [r0]
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _080A4E4C
	ldr r1, _080A4E48
	adds r0, r2, 0
	bl sub_80A2B40
	ldr r0, [r4]
	adds r1, r5, 0
	bl sub_80A2FBC
	b _080A50BA
	.align 2, 0
_080A4E38: .4byte gUnknown_81176A4
_080A4E3C: .4byte gUnknown_3001B70
_080A4E40: .4byte 0x0000055c
_080A4E44: .4byte gUnknown_3001B6C
_080A4E48: .4byte gUnknown_8117324
_080A4E4C:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	ldr r1, _080A4E6C
	adds r6, r0, r1
	ldrh r0, [r6]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _080A4F20
	lsls r0, 2
	ldr r1, _080A4E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A4E6C: .4byte gUnknown_811BAF4
_080A4E70: .4byte _080A4E74
	.align 2, 0
_080A4E74:
	.4byte _080A4F08
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4F20
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4EA8
	.4byte _080A4ECC
	.4byte _080A4ECC
_080A4EA8:
	ldr r0, _080A4EC0
	ldr r0, [r0]
	ldr r1, _080A4EC4
	bl sub_80A2B40
	ldr r1, _080A4EC8
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	b _080A4F30
	.align 2, 0
_080A4EC0: .4byte gUnknown_3001B70
_080A4EC4: .4byte gUnknown_811733C
_080A4EC8: .4byte gUnknown_2026E4E
_080A4ECC:
	ldr r4, _080A4EDC
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	negs r1, r1
	ldr r6, _080A4EE0
	b _080A4EEA
	.align 2, 0
_080A4EDC: .4byte gUnknown_81173C0
_080A4EE0: .4byte gUnknown_3001B70
_080A4EE4:
	adds r4, 0xC
	movs r2, 0
	ldrsh r0, [r4, r2]
_080A4EEA:
	cmp r0, r1
	beq _080A4EF2
	cmp r0, r5
	bne _080A4EE4
_080A4EF2:
	ldr r0, [r6]
	bl MemoryFree
	movs r0, 0
	str r0, [r6]
	adds r1, r4, 0x4
	ldr r2, [r4, 0x8]
	adds r0, r5, 0
	bl GroundMap_SelectDungeon
	b _080A50BA
_080A4F08:
	ldr r0, _080A4F18
	ldr r1, _080A4F1C
	movs r2, 0
	ldrsh r3, [r6, r2]
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A4F18: .4byte gUnknown_81176D0
_080A4F1C: .4byte gUnknown_81176DC
_080A4F20:
	ldr r0, _080A4FA0
	ldr r0, [r0]
	ldr r1, _080A4FA4
	bl sub_80A2B40
	movs r0, 0x1
	bl sub_80A5EDC
_080A4F30:
	ldr r5, _080A4FA0
	ldr r0, [r5]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	bl sub_80A2FBC
	ldr r0, _080A4FA8
	ldr r0, [r0]
	mov r12, r0
	adds r0, 0xE8
	movs r1, 0
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	adds r0, 0x4
	str r1, [r0]
	movs r4, 0x80
	lsls r4, 1
	add r4, r12
	movs r3, 0x82
	lsls r3, 1
	add r3, r12
	movs r2, 0x84
	lsls r2, 1
	add r2, r12
	movs r0, 0x86
	lsls r0, 1
	add r0, r12
	str r1, [r0]
	str r1, [r2]
	str r1, [r3]
	str r1, [r4]
	mov r0, r12
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0xAD
	beq _080A5034
	cmp r0, 0xAD
	bgt _080A4FC0
	cmp r0, 0xA3
	bgt _080A4FAC
	cmp r0, 0xA2
	bge _080A4FEE
	cmp r0, 0x4
	beq _080A5084
	cmp r0, 0xA1
	beq _080A5084
	b _080A50A2
	.align 2, 0
_080A4FA0: .4byte gUnknown_3001B70
_080A4FA4: .4byte gUnknown_8117324
_080A4FA8: .4byte gUnknown_3001B6C
_080A4FAC:
	cmp r0, 0xAA
	beq _080A500C
	cmp r0, 0xAA
	bgt _080A4FBA
	cmp r0, 0xA8
	beq _080A500C
	b _080A50A2
_080A4FBA:
	cmp r0, 0xAB
	beq _080A5018
	b _080A50A2
_080A4FC0:
	cmp r0, 0xBA
	beq _080A506A
	cmp r0, 0xBA
	bgt _080A4FD6
	cmp r0, 0xAF
	beq _080A5072
	cmp r0, 0xAF
	blt _080A5044
	cmp r0, 0xB0
	beq _080A5060
	b _080A50A2
_080A4FD6:
	cmp r0, 0xDF
	beq _080A4FEE
	cmp r0, 0xDF
	bgt _080A4FE4
	cmp r0, 0xC0
	beq _080A5020
	b _080A50A2
_080A4FE4:
	cmp r0, 0xE0
	beq _080A508E
	cmp r0, 0xE1
	beq _080A5096
	b _080A50A2
_080A4FEE:
	ldr r0, _080A5000
	ldr r0, [r0]
	movs r1, 0x4
	bl sub_80A3BB0
	ldr r1, _080A5004
	ldr r2, _080A5008
	b _080A5050
	.align 2, 0
_080A5000: .4byte gUnknown_3001B70
_080A5004: .4byte gUnknown_2026E4E
_080A5008: .4byte 0x00000808
_080A500C:
	ldr r0, _080A5014
	ldr r0, [r0]
	b _080A5062
	.align 2, 0
_080A5014: .4byte gUnknown_3001B70
_080A5018:
	ldr r0, [r5]
	movs r1, 0x1
	bl sub_80A3BB0
_080A5020:
	ldr r0, _080A5030
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80A3B80
	b _080A50A2
	.align 2, 0
_080A5030: .4byte gUnknown_3001B70
_080A5034:
	ldr r1, _080A503C
	ldr r2, _080A5040
	b _080A5050
	.align 2, 0
_080A503C: .4byte gUnknown_2026E4E
_080A5040: .4byte 0x00001010
_080A5044:
	ldr r0, [r5]
	movs r1, 0x4
	bl sub_80A3BB0
	ldr r1, _080A5058
	ldr r2, _080A505C
_080A5050:
	adds r0, r2, 0
	strh r0, [r1]
	b _080A50A2
	.align 2, 0
_080A5058: .4byte gUnknown_2026E4E
_080A505C: .4byte 0x0000080c
_080A5060:
	ldr r0, [r5]
_080A5062:
	movs r1, 0x1
	bl sub_80A3BB0
	b _080A50A2
_080A506A:
	ldr r0, _080A507C
	ldr r2, _080A5080
	adds r1, r2, 0
	strh r1, [r0]
_080A5072:
	ldr r0, [r5]
	movs r1, 0x4
	bl sub_80A3BB0
	b _080A50A2
	.align 2, 0
_080A507C: .4byte gUnknown_2026E4E
_080A5080: .4byte 0x00001010
_080A5084:
	ldr r0, [r5]
	movs r1, 0x3
	bl sub_80A3BB0
	b _080A50A2
_080A508E:
	ldr r0, [r5]
	movs r1, 0x3
	bl sub_80A3BB0
_080A5096:
	ldr r0, _080A50C0
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0
	bl sub_80A3B80
_080A50A2:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A50B4
	adds r0, r1, 0
	bl GroundWeather_Select
_080A50B4:
	ldr r0, _080A50C4
	bl sub_80A56D8
_080A50BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A50C0: .4byte gUnknown_3001B70
_080A50C4: .4byte gUnknown_81176F8
	thumb_func_end GroundMap_Select

	thumb_func_start GroundMap_SelectDungeon
GroundMap_SelectDungeon:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r1
	mov r10, r2
	lsls r0, 16
	asrs r5, r0, 16
	ldr r1, _080A514C
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x37
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x38
	bl sub_80015C0
	movs r0, 0
	bl sub_80A5EDC
	ldr r7, _080A5150
	ldr r0, [r7]
	cmp r0, 0
	beq _080A5110
	bl sub_80A2D00
	ldr r0, [r7]
	bl MemoryFree
	movs r0, 0
	str r0, [r7]
_080A5110:
	ldr r0, _080A5154
	movs r1, 0x6
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r7]
	ldr r0, _080A5158
	mov r9, r0
	ldr r0, [r0]
	adds r0, 0xE4
	movs r4, 0
	strh r5, [r0]
	movs r6, 0x1
	negs r6, r6
	cmp r5, r6
	beq _080A5138
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x63
	bne _080A5160
_080A5138:
	ldr r1, _080A515C
	adds r0, r2, 0
	bl sub_80A2B40
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_80A2FBC
	b _080A51EC
	.align 2, 0
_080A514C: .4byte gUnknown_8117700
_080A5150: .4byte gUnknown_3001B70
_080A5154: .4byte 0x0000055c
_080A5158: .4byte gUnknown_3001B6C
_080A515C: .4byte gUnknown_8117324
_080A5160:
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	ldr r1, _080A5180
	adds r6, r0, r1
	ldrh r0, [r6]
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _080A518C
	ldr r0, _080A5184
	ldr r1, _080A5188
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A5180: .4byte gUnknown_811BAF4
_080A5184: .4byte gUnknown_8117734
_080A5188: .4byte gUnknown_8117740
_080A518C:
	ldr r1, _080A51FC
	adds r0, r2, 0
	bl sub_80A2B40
	movs r0, 0x1
	bl sub_80A5EDC
	ldr r0, [r7]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	mov r2, r8
	mov r3, r10
	bl sub_80A3440
	mov r0, r9
	ldr r0, [r0]
	mov r12, r0
	adds r0, 0xE8
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	movs r3, 0x80
	lsls r3, 1
	add r3, r12
	movs r2, 0x82
	lsls r2, 1
	add r2, r12
	movs r1, 0x84
	lsls r1, 1
	add r1, r12
	movs r0, 0x86
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	str r4, [r1]
	str r4, [r2]
	str r4, [r3]
	ldr r0, _080A5200
	bl sub_80A56D8
_080A51EC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A51FC: .4byte gUnknown_8117354
_080A5200: .4byte gUnknown_8117754
	thumb_func_end GroundMap_SelectDungeon

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
_080A56BC: .4byte gUnknown_3001B70
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
_080A56D4: .4byte gUnknown_3001B70
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
_080A56EC: .4byte gUnknown_3001B70
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
_080A5700: .4byte gUnknown_3001B6C
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
_080A5724: .4byte gUnknown_3001B6C
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
_080A5734: .4byte gUnknown_3001B6C
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
_080A5750: .4byte gUnknown_3001B6C
_080A5754: .4byte gUnknown_811BAF4
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
_080A5768: .4byte gUnknown_3001B70
_080A576C:
	bl sub_80A4608
	movs r0, 0x1
_080A5772:
	pop {r1}
	bx r1
	thumb_func_end sub_80A5758

	thumb_func_start sub_80A5778
sub_80A5778:
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
_080A578C: .4byte gUnknown_3001B70
_080A5790:
	adds r1, r3, 0
	bl sub_80A463C
	movs r0, 0x1
_080A5798:
	pop {r1}
	bx r1
	thumb_func_end sub_80A5778

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
	bl sub_80A463C
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
_080A5838: .4byte gUnknown_3001B70
_080A583C: .4byte gUnknown_3001B6C
_080A5840: .4byte gUnknown_811BAF4
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

	thumb_func_start sub_80A585C
sub_80A585C:
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
_080A5884: .4byte gUnknown_3001B70
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
	thumb_func_end sub_80A585C

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
_080A58F0: .4byte gUnknown_3001B70
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

	thumb_func_start sub_80A5934
sub_80A5934:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A5958
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A4660
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A5958: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5934

	thumb_func_start sub_80A595C
sub_80A595C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A5980
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A46C0
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A5980: .4byte gUnknown_3001B70
	thumb_func_end sub_80A595C

	thumb_func_start sub_80A5984
sub_80A5984:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080A599C
	ldr r0, [r0]
	adds r1, r3, 0
	bl sub_80A4720
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.align 2, 0
_080A599C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5984

	thumb_func_start sub_80A59A0
sub_80A59A0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r3, r2, 16
	lsrs r3, 16
	ldr r0, _080A59BC
	ldr r0, [r0]
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A4740
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A59BC: .4byte gUnknown_3001B70
	thumb_func_end sub_80A59A0

	thumb_func_start GroundMap_Action
GroundMap_Action:
	push {lr}
	bl nullsub_123
	ldr r0, _080A59D4
	ldr r0, [r0]
	ldr r1, _080A59D8
	bl HandleAction
	pop {r0}
	bx r0
	.align 2, 0
_080A59D4: .4byte gUnknown_3001B6C
_080A59D8: .4byte gUnknown_8117770
	thumb_func_end GroundMap_Action

	thumb_func_start sub_80A59DC
sub_80A59DC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r7, _080A5A34
	ldr r0, [r7]
	cmp r0, 0
	bne _080A59F0
	b _080A5E5A
_080A59F0:
	mov r9, sp
	mov r0, sp
	bl sub_809D248
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A5A04
	str r0, [sp]
	str r0, [sp, 0x4]
_080A5A04:
	ldr r0, _080A5A38
	mov r8, r0
	ldr r3, [r0]
	adds r0, r3, 0
	adds r0, 0xE4
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r6, r8
	cmp r0, 0xAB
	bne _080A5A1A
	b _080A5BBE
_080A5A1A:
	cmp r0, 0xAB
	bgt _080A5A46
	cmp r0, 0xA3
	bgt _080A5A3C
	cmp r0, 0xA2
	bge _080A5A76
	cmp r0, 0x4
	bne _080A5A2C
	b _080A5D76
_080A5A2C:
	cmp r0, 0xA1
	bne _080A5A32
	b _080A5E28
_080A5A32:
	b _080A5E46
	.align 2, 0
_080A5A34: .4byte gUnknown_3001B70
_080A5A38: .4byte gUnknown_3001B6C
_080A5A3C:
	cmp r0, 0xA8
	beq _080A5AF4
	cmp r0, 0xAA
	beq _080A5AF4
	b _080A5E46
_080A5A46:
	cmp r0, 0xB0
	bne _080A5A4C
	b _080A5C76
_080A5A4C:
	cmp r0, 0xB0
	bgt _080A5A5E
	cmp r0, 0xAE
	bne _080A5A56
	b _080A5B58
_080A5A56:
	cmp r0, 0xAF
	bne _080A5A5C
	b _080A5BD8
_080A5A5C:
	b _080A5E46
_080A5A5E:
	cmp r0, 0xDF
	beq _080A5A76
	cmp r0, 0xDF
	bgt _080A5A6E
	cmp r0, 0xBA
	bne _080A5A6C
	b _080A5D18
_080A5A6C:
	b _080A5E46
_080A5A6E:
	cmp r0, 0xE0
	bne _080A5A74
	b _080A5DDA
_080A5A74:
	b _080A5E46
_080A5A76:
	ldr r3, [r6]
	adds r2, r3, 0
	adds r2, 0xF4
	ldr r1, [r2]
	adds r0, r1, 0x2
	str r0, [r2]
	adds r4, r3, 0
	adds r4, 0xFC
	cmp r0, 0
	bge _080A5A8C
	adds r0, r1, 0x5
_080A5A8C:
	asrs r1, r0, 2
	ldr r0, [r4]
	adds r0, r1
	str r0, [r4]
	ldr r0, [r2]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2]
	ldr r5, _080A5AF0
	ldr r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	movs r1, 0
	bl sub_80A4580
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	adds r1, r0
	add r4, sp, 0x8
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	ldr r0, [sp]
	str r0, [sp, 0x8]
	ldr r0, [r6]
	adds r0, 0xFC
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	subs r1, r0
	str r1, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A5DD0
	.align 2, 0
_080A5AF0: .4byte gUnknown_3001B70
_080A5AF4:
	ldr r2, [r6]
	adds r3, r2, 0
	adds r3, 0xF0
	adds r0, r2, 0
	adds r0, 0xE8
	ldr r1, [r3]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r3]
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B0E
	adds r1, 0x7
_080A5B0E:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r3]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B20
	adds r0, r1, 0x7
_080A5B20:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r3]
	ldr r5, _080A5B54
	ldr r0, [r5]
	movs r1, 0
	bl sub_80A4580
	ldr r0, [r6]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x10]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x10
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	movs r1, 0
	b _080A5DD2
	.align 2, 0
_080A5B54: .4byte gUnknown_3001B70
_080A5B58:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r0, r3, 0
	adds r0, 0xE8
	ldr r1, [r4]
	ldr r0, [r0]
	adds r1, r0
	str r1, [r4]
	adds r2, r3, 0
	adds r2, 0xF8
	cmp r1, 0
	bge _080A5B72
	adds r1, 0x7
_080A5B72:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5B84
	adds r0, r1, 0x7
_080A5B84:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x18]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x18
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5DCE
_080A5BBE:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	ldr r0, [r7]
	add r4, sp, 0x20
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5BD8:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r3, [r0]
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r2, r3, 0
	adds r2, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5C12
	adds r1, 0x7
_080A5C12:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	adds r3, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5C24
	adds r1, 0x7
_080A5C24:
	asrs r1, 3
	ldr r0, [r3]
	adds r0, r1
	str r0, [r3]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C36
	adds r0, r1, 0x7
_080A5C36:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5C48
	adds r0, r1, 0x7
_080A5C48:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	bl sub_80A4580
	mov r1, r8
	ldr r2, [r1]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x28]
	adds r2, 0xFC
	mov r1, r9
	ldr r0, [r1, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x28
	b _080A5DC2
_080A5C76:
	adds r4, r3, 0
	adds r4, 0xF0
	adds r1, r3, 0
	adds r1, 0xE8
	ldr r0, [r4]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r4]
	adds r5, r3, 0
	adds r5, 0xF4
	adds r1, r3, 0
	adds r1, 0xEC
	ldr r0, [r5]
	ldr r1, [r1]
	adds r0, r1
	str r0, [r5]
	adds r6, r3, 0
	adds r6, 0xF8
	ldr r1, [r4]
	cmp r1, 0
	bge _080A5CA2
	adds r1, 0x7
_080A5CA2:
	asrs r1, 3
	ldr r0, [r6]
	adds r0, r1
	str r0, [r6]
	adds r2, r3, 0
	adds r2, 0xFC
	ldr r1, [r5]
	cmp r1, 0
	bge _080A5CB6
	adds r1, 0x7
_080A5CB6:
	asrs r1, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r1, [r4]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CC8
	adds r0, r1, 0x7
_080A5CC8:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r4]
	ldr r1, [r5]
	adds r0, r1, 0
	cmp r1, 0
	bge _080A5CDA
	adds r0, r1, 0x7
_080A5CDA:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	str r0, [r5]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r6, 0
	bl sub_80A4580
	mov r0, r8
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, [sp]
	ldr r1, [r1]
	adds r0, r1
	str r0, [sp, 0x30]
	adds r2, 0xFC
	ldr r0, [sp, 0x4]
	ldr r1, [r2]
	adds r0, r1
	add r4, sp, 0x30
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D18:
	ldr r0, [r7]
	movs r1, 0x1
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D3A
	adds r0, r4, 0x4
_080A5D3A:
	asrs r1, r0, 2
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x3
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x38]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x38
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r7]
	movs r1, 0
	b _080A5DD2
_080A5D76:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5D98
	adds r0, 0x7
_080A5D98:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r1, [sp]
	ldr r0, [r0]
	adds r1, r0
	str r1, [sp, 0x40]
	ldr r0, [sp, 0x4]
	add r4, sp, 0x40
_080A5DC2:
	str r0, [r4, 0x4]
	ldr r0, [r7]
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_80A4580
_080A5DCE:
	ldr r0, [r7]
_080A5DD0:
	movs r1, 0x1
_080A5DD2:
	adds r2, r4, 0
	bl sub_80A456C
	b _080A5E52
_080A5DDA:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	mov r0, r8
	ldr r1, [r0]
	adds r3, r1, 0
	adds r3, 0xF0
	ldr r4, [r3]
	adds r0, r4, 0x1
	str r0, [r3]
	adds r2, r1, 0
	adds r2, 0xF8
	cmp r0, 0
	bge _080A5DFC
	adds r0, 0x7
_080A5DFC:
	asrs r1, r0, 3
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	movs r1, 0x7
	ands r0, r1
	str r0, [r3]
	ldr r0, [r7]
	movs r1, 0x1
	bl sub_80A4580
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0xF8
	ldr r0, [r0]
	str r0, [sp, 0x48]
	ldr r0, [sp, 0x4]
	add r2, sp, 0x48
	str r0, [r2, 0x4]
	ldr r0, [r7]
	b _080A5E3E
_080A5E28:
	ldr r0, [r7]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	ldr r0, [r7]
	add r2, sp, 0x50
_080A5E3E:
	movs r1, 0x1
	bl sub_80A456C
	b _080A5E52
_080A5E46:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
_080A5E52:
	ldr r0, _080A5E6C
	ldr r0, [r0]
	bl sub_80A4764
_080A5E5A:
	bl sub_80A60D8
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5E6C: .4byte gUnknown_3001B70
	thumb_func_end sub_80A59DC

	thumb_func_start sub_80A5E70
sub_80A5E70:
	push {lr}
	ldr r0, _080A5E88
	ldr r0, [r0]
	cmp r0, 0
	beq _080A5E7E
	bl sub_80A49E8
_080A5E7E:
	bl sub_80A62D0
	pop {r0}
	bx r0
	.align 2, 0
_080A5E88: .4byte gUnknown_3001B70
	thumb_func_end sub_80A5E70

	thumb_func_start sub_80A5E8C
sub_80A5E8C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _080A5EB4
	movs r0, 0x24
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r5]
	ldr r1, _080A5EB8
	strh r1, [r0]
	movs r1, 0
	strb r1, [r0, 0x2]
	adds r0, r4, 0
	bl sub_80A5EDC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A5EB4: .4byte gUnknown_3001B74
_080A5EB8: .4byte 0x0000ffff
	thumb_func_end sub_80A5E8C

	thumb_func_start sub_80A5EBC
sub_80A5EBC:
	push {r4,lr}
	movs r0, 0
	bl sub_80A5EDC
	ldr r4, _080A5ED8
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A5ED8: .4byte gUnknown_3001B74
	thumb_func_end sub_80A5EBC

	thumb_func_start sub_80A5EDC
sub_80A5EDC:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	movs r6, 0x1
	negs r6, r6
	movs r0, 0
	movs r1, 0x1B
	adds r2, r6, 0
	bl sub_80018D8
	ldr r0, _080A5F34
	ldr r1, [r0]
	ldr r0, _080A5F38
	strh r0, [r1]
	strb r5, [r1, 0x2]
	ldr r4, _080A5F3C
	ldr r0, [r4]
	cmp r0, 0
	beq _080A5F12
	bl sub_80A2D00
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080A5F12:
	cmp r5, 0
	beq _080A5F2E
	ldr r0, _080A5F40
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r1, _080A5F44
	bl sub_80A2B40
	ldr r0, [r4]
	adds r1, r6, 0
	bl sub_80A2FBC
_080A5F2E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A5F34: .4byte gUnknown_3001B74
_080A5F38: .4byte 0x0000ffff
_080A5F3C: .4byte gUnknown_3001B78
_080A5F40: .4byte 0x0000055c
_080A5F44: .4byte gUnknown_8117784
	thumb_func_end sub_80A5EDC

	thumb_func_start nullsub_121
nullsub_121:
	bx lr
	thumb_func_end nullsub_121

	thumb_func_start nullsub_122
nullsub_122:
	bx lr
	thumb_func_end nullsub_122

	thumb_func_start GroundWeather_Select
GroundWeather_Select:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r5, r0, 16
	adds r7, r5, 0
	ldr r1, _080A5F94
	ldr r6, _080A5F98
	ldr r0, [r6]
	ldrb r3, [r0, 0x2]
	movs r0, 0
	adds r2, r5, 0
	bl Log
	movs r0, 0
	movs r1, 0x1B
	adds r2, r5, 0
	bl sub_80018D8
	ldr r0, [r6]
	movs r4, 0
	strh r5, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	bne _080A5F80
	b _080A60B4
_080A5F80:
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _080A5FA0
	ldr r0, _080A5F9C
	ldr r0, [r0]
	adds r1, r5, 0
	bl sub_80A2FBC
	b _080A60B4
	.align 2, 0
_080A5F94: .4byte gUnknown_811779C
_080A5F98: .4byte gUnknown_3001B74
_080A5F9C: .4byte gUnknown_3001B78
_080A5FA0:
	lsls r1, r7, 2
	ldr r0, _080A5FD8
	adds r5, r1, r0
	ldr r0, _080A5FDC
	ldr r0, [r0]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl sub_80A2FBC
	ldr r0, [r6]
	str r4, [r0, 0x4]
	str r4, [r0, 0x8]
	str r4, [r0, 0xC]
	str r4, [r0, 0x10]
	str r4, [r0, 0x20]
	str r4, [r0, 0x1C]
	str r4, [r0, 0x18]
	str r4, [r0, 0x14]
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0xF
	bhi _080A6098
	lsls r0, 2
	ldr r1, _080A5FE0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A5FD8: .4byte gUnknown_811E5F4
_080A5FDC: .4byte gUnknown_3001B78
_080A5FE0: .4byte _080A5FE4
	.align 2, 0
_080A5FE4:
	.4byte _080A6088
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6088
	.4byte _080A6088
	.4byte _080A6088
	.4byte _080A6098
	.4byte _080A6040
	.4byte _080A6088
	.4byte _080A6024
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6098
	.4byte _080A6050
	.4byte _080A606C
_080A6024:
	ldr r0, _080A6034
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6038
	ldr r2, _080A603C
	b _080A60B0
	.align 2, 0
_080A6034: .4byte gUnknown_3001B78
_080A6038: .4byte gUnknown_2026E4E
_080A603C: .4byte 0x0000040c
_080A6040:
	ldr r1, _080A6048
	ldr r2, _080A604C
	b _080A60B0
	.align 2, 0
_080A6048: .4byte gUnknown_2026E4E
_080A604C: .4byte 0x00000808
_080A6050:
	ldr r0, _080A6060
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6064
	ldr r2, _080A6068
	b _080A60B0
	.align 2, 0
_080A6060: .4byte gUnknown_3001B78
_080A6064: .4byte gUnknown_2026E4E
_080A6068: .4byte 0x00001010
_080A606C:
	ldr r0, _080A607C
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
	ldr r1, _080A6080
	ldr r2, _080A6084
	b _080A60B0
	.align 2, 0
_080A607C: .4byte gUnknown_3001B78
_080A6080: .4byte gUnknown_2026E4E
_080A6084: .4byte 0x0000040c
_080A6088:
	ldr r1, _080A6090
	ldr r2, _080A6094
	b _080A60B0
	.align 2, 0
_080A6090: .4byte gUnknown_2026E4E
_080A6094: .4byte 0x00001010
_080A6098:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _080A60AA
	ldr r0, _080A60BC
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80A3BB0
_080A60AA:
	ldr r1, _080A60C0
	movs r2, 0x80
	lsls r2, 5
_080A60B0:
	adds r0, r2, 0
	strh r0, [r1]
_080A60B4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A60BC: .4byte gUnknown_3001B78
_080A60C0: .4byte gUnknown_2026E4E
	thumb_func_end GroundWeather_Select

	thumb_func_start sub_80A60C4
sub_80A60C4:
	ldr r0, _080A60D0
	ldr r0, [r0]
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A60D0: .4byte gUnknown_3001B74
	thumb_func_end sub_80A60C4

	thumb_func_start nullsub_123
nullsub_123:
	bx lr
	thumb_func_end nullsub_123

	thumb_func_start sub_80A60D8
sub_80A60D8:
	push {r4-r6,lr}
	sub sp, 0x28
	ldr r0, _080A6104
	ldr r3, [r0]
	ldrb r1, [r3, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	bne _080A60EA
	b _080A62C0
_080A60EA:
	ldrh r0, [r3]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	bls _080A60F8
	b _080A6278
_080A60F8:
	lsls r0, 2
	ldr r1, _080A6108
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A6104: .4byte gUnknown_3001B74
_080A6108: .4byte _080A610C
	.align 2, 0
_080A610C:
	.4byte _080A62AC
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6278
	.4byte _080A6150
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61CC
	.4byte _080A61D0
	.4byte _080A6224
_080A6150:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x2
	str r0, [r2, 0x4]
	ldr r4, [r2, 0x8]
	adds r3, r4, 0x1
	str r3, [r2, 0x8]
	cmp r0, 0
	bge _080A6164
	adds r0, r1, 0x5
_080A6164:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	adds r1, r3, 0
	cmp r1, 0
	bge _080A6174
	adds r1, r4, 0x4
_080A6174:
	asrs r1, 2
	ldr r0, [r2, 0x10]
	adds r0, r1
	str r0, [r2, 0x10]
	ldr r4, _080A61C8
	ldr r0, [r4]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r1, [r6]
	ldr r0, [r1, 0x4]
	movs r2, 0x3
	ands r0, r2
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x8]
	ands r0, r2
	str r0, [r1, 0x8]
	mov r0, sp
	bl sub_80A56C0
	ldr r2, [r6]
	ldr r0, [sp]
	ldr r1, [r2, 0xC]
	subs r0, r1
	str r0, [sp]
	ldr r0, [sp, 0x4]
	ldr r1, [r2, 0x10]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4]
	movs r1, 0
	mov r2, sp
	bl sub_80A4580
	ldr r0, [r4]
	movs r1, 0
	mov r2, sp
	bl sub_80A456C
	b _080A62B8
	.align 2, 0
_080A61C8: .4byte gUnknown_3001B78
_080A61CC:
	add r4, sp, 0x8
	b _080A628E
_080A61D0:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0
	bge _080A61DE
	adds r0, r1, 0x4
_080A61DE:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	ldr r5, _080A6220
	ldr r0, [r5]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2, 0x4]
	add r4, sp, 0x10
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r1, [r6]
	ldr r0, [sp, 0x10]
	ldr r1, [r1, 0xC]
	subs r0, r1
	str r0, [sp, 0x10]
	movs r0, 0
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A6298
	.align 2, 0
_080A6220: .4byte gUnknown_3001B78
_080A6224:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	adds r0, r1, 0x2
	str r0, [r2, 0x4]
	cmp r0, 0
	bge _080A6232
	adds r0, r1, 0x5
_080A6232:
	asrs r1, r0, 2
	ldr r0, [r2, 0xC]
	adds r0, r1
	str r0, [r2, 0xC]
	ldr r5, _080A6274
	ldr r0, [r5]
	adds r2, 0xC
	movs r1, 0
	bl sub_80A4580
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	movs r1, 0x3
	ands r0, r1
	str r0, [r2, 0x4]
	add r4, sp, 0x18
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r1, [r6]
	ldr r0, [sp, 0x18]
	ldr r1, [r1, 0xC]
	subs r0, r1
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [r4, 0x4]
	ldr r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A4580
	ldr r0, [r5]
	b _080A6298
	.align 2, 0
_080A6274: .4byte gUnknown_3001B78
_080A6278:
	ldr r0, [r6]
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 2
	ldr r1, _080A62A4
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _080A62AC
	add r4, sp, 0x20
_080A628E:
	adds r0, r4, 0
	bl sub_80A56C0
	ldr r0, _080A62A8
	ldr r0, [r0]
_080A6298:
	movs r1, 0
	adds r2, r4, 0
	bl sub_80A456C
	b _080A62B8
	.align 2, 0
_080A62A4: .4byte gUnknown_811E5F4
_080A62A8: .4byte gUnknown_3001B78
_080A62AC:
	ldr r0, _080A62C8
	ldr r0, [r0]
	ldr r2, _080A62CC
	movs r1, 0
	bl sub_80A456C
_080A62B8:
	ldr r0, _080A62C8
	ldr r0, [r0]
	bl sub_80A4764
_080A62C0:
	add sp, 0x28
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A62C8: .4byte gUnknown_3001B78
_080A62CC: .4byte gUnknown_81177BC
	thumb_func_end sub_80A60D8

	thumb_func_start sub_80A62D0
sub_80A62D0:
	push {lr}
	ldr r0, _080A62E8
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _080A62E4
	ldr r0, _080A62EC
	ldr r0, [r0]
	bl sub_80A49E8
_080A62E4:
	pop {r0}
	bx r0
	.align 2, 0
_080A62E8: .4byte gUnknown_3001B74
_080A62EC: .4byte gUnknown_3001B78
	thumb_func_end sub_80A62D0

	thumb_func_start sub_80A62F0
sub_80A62F0:
	push {r4-r7,lr}
	ldr r4, _080A6378
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r0, _080A637C
	ldr r1, _080A6380
	bl OpenFileAndGetFileDataPtr
	ldr r1, _080A6384
	str r0, [r1]
	movs r0, 0x1
	bl sub_800DAC0
	ldr r4, [r4]
	ldr r1, _080A6388
	movs r0, 0x16
	str r0, [r1]
	ldr r1, _080A638C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0
	movs r2, 0
	movs r1, 0x80
	lsls r1, 9
	adds r3, r1, 0
_080A632A:
	str r2, [r4]
	lsls r0, 4
	str r0, [r4, 0x4]
	str r2, [r4, 0x8]
	adds r0, r1, 0
	adds r1, r3
	asrs r0, 16
	adds r4, 0xC
	cmp r0, 0x15
	ble _080A632A
	ldr r0, _080A6378
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 1
	adds r4, r0, r1
	movs r6, 0
	movs r7, 0
	movs r5, 0xE8
	lsls r5, 13
_080A6350:
	strh r7, [r4]
	strh r7, [r4, 0x2]
	lsrs r0, r5, 16
	movs r1, 0
	bl sub_80997F4
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r6, 0x1
	adds r4, 0x4
	cmp r6, 0x1
	ble _080A6350
	movs r0, 0x1
	negs r0, r0
	bl GroundSprite_Reset
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6378: .4byte gUnknown_3001B7C
_080A637C: .4byte gUnknown_81177CC
_080A6380: .4byte gUnknown_83B0000
_080A6384: .4byte gUnknown_203B4B4
_080A6388: .4byte gUnknown_2039DD4
_080A638C: .4byte gUnknown_2039DD0
	thumb_func_end sub_80A62F0

	thumb_func_start GroundSprite_Reset
GroundSprite_Reset:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	ldr r1, _080A641C
	movs r0, 0
	bl Log
	ldr r0, _080A6420
	movs r1, 0
	mov r8, r1
	strh r1, [r0]
	ldr r0, _080A6424
	strh r1, [r0]
	bl sub_80A6460
	mov r0, r9
	bl sub_80A4D48
	lsls r0, 24
	movs r1, 0x2
	cmp r0, 0
	beq _080A63C6
	movs r1, 0x3
_080A63C6:
	movs r0, 0xF8
	lsls r0, 1
	bl sub_808E53C
	ldr r5, _080A6428
	adds r0, r5, 0
	bl sub_8004E8C
	ldr r4, _080A642C
	adds r0, r4, 0
	bl sub_8004E8C
	ldrh r1, [r4, 0x4]
	ldr r6, _080A6430
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r4, 0x4]
	ldrh r1, [r4, 0xA]
	adds r0, r6, 0
	ands r0, r1
	movs r2, 0x80
	lsls r2, 4
	adds r7, r2, 0
	orrs r0, r7
	strh r0, [r4, 0xA]
	mov r0, r9
	bl sub_80A4D48
	lsls r0, 24
	cmp r0, 0
	beq _080A6434
	ldrh r1, [r5, 0x4]
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r5, 0x4]
	ldrh r1, [r5, 0xA]
	adds r0, r6, 0
	ands r0, r1
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	orrs r0, r1
	b _080A6444
	.align 2, 0
_080A641C: .4byte gUnknown_81177D8
_080A6420: .4byte gUnknown_2039DCC
_080A6424: .4byte gUnknown_2039DCE
_080A6428: .4byte gUnknown_2039DB0
_080A642C: .4byte gUnknown_2039DC0
_080A6430: .4byte 0x0000f3ff
_080A6434:
	ldrh r1, [r5, 0x4]
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r5, 0x4]
	ldrh r1, [r5, 0xA]
	adds r0, r6, 0
	ands r0, r1
	orrs r0, r7
_080A6444:
	strh r0, [r5, 0xA]
	movs r0, 0x1
	bl ResetSprites
	movs r0, 0x1
	bl nullsub_10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundSprite_Reset

	thumb_func_start sub_80A6460
sub_80A6460:
	push {r4-r7,lr}
	ldr r0, _080A649C
	ldr r1, _080A64A0
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	movs r5, 0x80
	lsls r5, 1
	ldr r4, [r7, 0x4]
	movs r6, 0xC
_080A6474:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_809971C
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x40
	subs r6, 0x1
	cmp r6, 0
	bge _080A6474
	adds r0, r7, 0
	bl CloseFile
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A649C: .4byte gUnknown_81177EC
_080A64A0: .4byte gUnknown_8510000
	thumb_func_end sub_80A6460

	thumb_func_start sub_80A64A4
sub_80A64A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, _080A6508
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 1
	adds r7, r0, r1
	bl sub_80A6460
	movs r0, 0
	mov r8, r0
_080A64C0:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	cmp r0, 0
	ble _080A6568
	ldrh r5, [r7]
	mov r0, r8
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	mov r1, r8
	lsls r0, r1, 20
	movs r1, 0xE8
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	mov r9, r0
	movs r0, 0x80
	lsls r0, 2
	adds r1, r0, 0
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080A6514
	ldr r0, _080A650C
	ldr r1, _080A6510
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 6
	ldr r1, [r6, 0x4]
	adds r2, r1, r0
	b _080A652A
	.align 2, 0
_080A6508: .4byte gUnknown_3001B7C
_080A650C: .4byte gUnknown_81177EC
_080A6510: .4byte gUnknown_8510000
_080A6514:
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 2
	ldr r1, _080A6584
	adds r0, r1
	ldr r0, [r0]
	ldr r1, _080A6588
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r2, [r6, 0x4]
_080A652A:
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1, 0
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 16
	lsrs r1, 16
	negs r1, r1
	lsrs r4, r1, 31
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	ands r5, r0
	cmp r5, 0
	beq _080A654C
	movs r0, 0x2
	orrs r4, r0
_080A654C:
	mov r0, r9
	adds r1, r2, 0
	movs r2, 0x10
	bl sub_809971C
	mov r0, r10
	adds r1, r4, 0
	bl sub_80997F4
	cmp r6, 0
	beq _080A6568
	adds r0, r6, 0
	bl CloseFile
_080A6568:
	movs r0, 0x1
	add r8, r0
	adds r7, 0x4
	mov r1, r8
	cmp r1, 0x1
	ble _080A64C0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6584: .4byte gUnknown_81178F4
_080A6588: .4byte gUnknown_9E60000
	thumb_func_end sub_80A64A4

	thumb_func_start sub_80A658C
sub_80A658C:
	push {r4,lr}
	bl sub_800DB7C
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	bl sub_8005180
	bl nullsub_12
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	ldr r0, _080A65D0
	ldr r0, [r0]
	bl CloseFile
	ldr r4, _080A65D4
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A65D0: .4byte gUnknown_203B4B4
_080A65D4: .4byte gUnknown_3001B7C
	thumb_func_end sub_80A658C

	thumb_func_start sub_80A65D8
sub_80A65D8:
	adds r0, 0x50
	ldrh r0, [r0]
	bx lr
	thumb_func_end sub_80A65D8

	thumb_func_start sub_80A65E0
sub_80A65E0:
	lsrs r0, 16
	ldr r2, _080A65EC
	adds r1, r2, 0
	ands r0, r1
	bx lr
	.align 2, 0
_080A65EC: .4byte 0x0000337f
	thumb_func_end sub_80A65E0

	thumb_func_start sub_80A65F0
sub_80A65F0:
	push {r4-r6,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, 0x50
	strh r1, [r0]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	asrs r2, r0, 31
	movs r0, 0x40
	ands r2, r0
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A6616
	subs r2, 0x40
_080A6616:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A6624
	adds r1, r2, 0
	adds r1, 0x48
	b _080A6628
_080A6624:
	adds r1, r2, 0
	adds r1, 0x40
_080A6628:
	adds r0, r3, 0
	adds r0, 0x6A
	strh r1, [r0]
	adds r2, r3, 0
	adds r2, 0x50
	ldrh r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A6648
	adds r1, r3, 0
	adds r1, 0x3C
	ldr r0, _080A6644
	b _080A664E
	.align 2, 0
_080A6644: .4byte gUnknown_2039DC0
_080A6648:
	adds r1, r3, 0
	adds r1, 0x3C
	ldr r0, _080A6680
_080A664E:
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldrh r1, [r2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080A6678
	ldrh r2, [r3, 0x3C]
	ldr r1, _080A6684
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r3, 0x3C]
	adds r2, r3, 0
	adds r2, 0x42
	ldrh r0, [r2]
	ands r1, r0
	movs r3, 0x80
	lsls r3, 3
	adds r0, r3, 0
	orrs r1, r0
	strh r1, [r2]
_080A6678:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A6680: .4byte gUnknown_2039DB0
_080A6684: .4byte 0x0000f3ff
	thumb_func_end sub_80A65F0

	thumb_func_start sub_80A6688
sub_80A6688:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	bl sub_80A65E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_80A65F0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A6688

	thumb_func_start sub_80A66A4
sub_80A66A4:
	push {lr}
	movs r1, 0
	adds r0, 0x48
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _080A66B4
	movs r1, 0x1
_080A66B4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80A66A4

	thumb_func_start sub_80A66BC
sub_80A66BC:
	push {lr}
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080A66CC
	movs r0, 0
	b _080A66CE
_080A66CC:
	movs r0, 0x1
_080A66CE:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66BC

	thumb_func_start sub_80A66D4
sub_80A66D4:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _080A66F2
	adds r0, r1, 0
	adds r0, 0x48
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _080A66F2
	movs r0, 0x1
	b _080A66F4
_080A66F2:
	movs r0, 0
_080A66F4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66D4

	thumb_func_start sub_80A66F8
sub_80A66F8:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	blt _080A6716
	ldrh r1, [r1]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	bne _080A6716
	lsrs r0, r1, 15
	b _080A6718
_080A6716:
	movs r0, 0
_080A6718:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66F8

	thumb_func_start sub_80A671C
sub_80A671C:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r4, 0
	adds r6, 0x58
	movs r0, 0
	ldrsh r1, [r6, r0]
	cmp r1, 0
	beq _080A6752
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	beq _080A674A
	ldr r0, [r4, 0x5C]
	movs r5, 0x1
	negs r5, r5
	cmp r0, r5
	beq _080A674A
	bl sub_800E9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080A674E
_080A674A:
	movs r0, 0x1
	b _080A6754
_080A674E:
	str r5, [r4, 0x5C]
	strh r0, [r6]
_080A6752:
	movs r0, 0
_080A6754:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A671C

	thumb_func_start sub_80A675C
sub_80A675C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r1, 0
	mov r0, sp
	bl sub_809D248
	lsls r0, 24
	cmp r0, 0
	beq _080A678C
	ldr r1, [r6]
	cmp r1, 0
	bge _080A6776
	adds r1, 0xFF
_080A6776:
	asrs r1, 8
	ldr r0, [sp]
	subs r4, r1, r0
	ldr r1, [r6, 0x4]
	cmp r1, 0
	bge _080A6784
	adds r1, 0xFF
_080A6784:
	asrs r1, 8
	ldr r0, [sp, 0x4]
	subs r5, r1, r0
	b _080A67A0
_080A678C:
	ldr r0, [r6]
	cmp r0, 0
	bge _080A6794
	adds r0, 0xFF
_080A6794:
	asrs r4, r0, 8
	ldr r1, [r6, 0x4]
	cmp r1, 0
	bge _080A679E
	adds r1, 0xFF
_080A679E:
	asrs r5, r1, 8
_080A67A0:
	adds r1, r4, 0
	adds r1, 0x40
	ldr r0, _080A67BC
	cmp r1, r0
	bhi _080A67C0
	movs r0, 0x10
	negs r0, r0
	cmp r5, r0
	blt _080A67C0
	cmp r5, 0xCF
	bgt _080A67C0
	movs r0, 0x1
	b _080A67C2
	.align 2, 0
_080A67BC: .4byte 0x0000016f
_080A67C0:
	movs r0, 0
_080A67C2:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A675C

	thumb_func_start sub_80A67CC
sub_80A67CC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r7, 0
	cmp r5, 0
	beq _080A67E2
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	ble _080A67E2
	movs r7, 0x1
_080A67E2:
	adds r0, r2, 0
	bl sub_80A65E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_80A65F0
	movs r1, 0
	str r1, [r4, 0x74]
	str r1, [r4, 0x78]
	movs r6, 0x1
	negs r6, r6
	str r6, [r4, 0x7C]
	adds r0, r4, 0
	adds r0, 0x70
	strb r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r2, r4, 0
	adds r2, 0x52
	ldr r0, _080A6884
	strh r0, [r2]
	str r1, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x64
	strh r1, [r0]
	adds r2, 0x14
	adds r0, r6, 0
	adds r3, r0, 0
	strh r0, [r2]
	adds r0, r4, 0
	adds r0, 0x68
	strh r1, [r0]
	subs r0, 0x10
	strh r1, [r0]
	adds r1, r4, 0
	adds r1, 0x5A
	movs r0, 0xFF
	strb r0, [r1]
	str r6, [r4, 0x5C]
	str r6, [r4, 0x60]
	cmp r7, 0
	beq _080A6888
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r4, 0x48]
	str r1, [r4, 0x4C]
	adds r5, r4, 0
	adds r5, 0x48
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	bne _080A689A
	adds r0, r4, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _080A689A
	adds r0, r5, 0
	bl sub_80A6CF4
	lsls r0, 24
	cmp r0, 0
	beq _080A689A
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A68F8
	b _080A689A
	.align 2, 0
_080A6884: .4byte 0x0000ffff
_080A6888:
	adds r1, r4, 0
	adds r1, 0x48
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x4A
	strh r7, [r0]
	str r7, [r4, 0x4C]
_080A689A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A67CC

	thumb_func_start sub_80A68A0
sub_80A68A0:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A68CE
	adds r0, r4, 0
	adds r0, 0x58
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080A68CE
	ldr r1, [r4, 0x5C]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A68CE
	adds r0, r1, 0
	bl sub_800DC14
_080A68CE:
	ldr r0, [r4, 0x54]
	cmp r0, 0
	beq _080A68DC
	bl CloseFile
	movs r0, 0
	str r0, [r4, 0x54]
_080A68DC:
	adds r0, r4, 0
	bl sub_80A69FC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A68A0

	thumb_func_start sub_80A68E8
sub_80A68E8:
	push {lr}
	movs r0, 0x15
_080A68EC:
	subs r0, 0x1
	cmp r0, 0
	bge _080A68EC
	pop {r0}
	bx r0
	thumb_func_end sub_80A68E8

	thumb_func_start sub_80A68F8
sub_80A68F8:
	push {r4-r7,lr}
	mov r12, r0
	adds r5, r2, 0
	ldr r0, _080A6924
	ldr r4, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r5
	blt _080A6956
	adds r5, r0, 0
	movs r3, 0
	ldr r0, [r4]
	mov r6, r12
	adds r6, 0x52
	mov r7, r12
	adds r7, 0x64
	cmp r0, 0
	bne _080A6928
	movs r2, 0x1
	cmp r2, r5
	blt _080A692A
	b _080A6986
	.align 2, 0
_080A6924: .4byte gUnknown_3001B7C
_080A6928:
	movs r2, 0
_080A692A:
	adds r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	adds r4, 0xC
	cmp r3, 0x15
	bgt _080A6986
	ldr r0, [r4]
	cmp r0, 0
	bne _080A6928
	adds r2, 0x1
	cmp r2, r5
	blt _080A692A
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	subs r0, 0xC
	subs r4, r0
	adds r0, r3, 0x1
	subs r0, r2
	lsls r0, 16
	asrs r3, r0, 16
	b _080A6986
_080A6956:
	movs r3, 0x15
	adds r4, 0xFC
	ldr r0, [r4]
	mov r6, r12
	adds r6, 0x52
	mov r7, r12
	adds r7, 0x64
	cmp r0, 0
	bne _080A696C
	movs r2, 0x1
	b _080A6982
_080A696C:
	movs r2, 0
_080A696E:
	subs r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	subs r4, 0xC
	cmp r3, 0
	blt _080A6986
	ldr r0, [r4]
	cmp r0, 0
	bne _080A696C
	adds r2, 0x1
_080A6982:
	cmp r2, r5
	blt _080A696E
_080A6986:
	cmp r2, r5
	blt _080A69C4
	strh r3, [r6]
	strh r5, [r7]
	movs r0, 0x1
	str r0, [r4]
	mov r0, r12
	str r0, [r4, 0x8]
	ldrh r1, [r1, 0x2]
	bl GroundSprite_ExtendPaletteAdd
	cmp r5, 0x1
	ble _080A69B2
	movs r2, 0x2
	adds r0, r4, 0
	adds r0, 0xC
	subs r1, r5, 0x1
_080A69A8:
	str r2, [r0]
	adds r0, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080A69A8
_080A69B2:
	ldr r1, _080A69C0
	ldr r0, [r1]
	subs r0, r5
	str r0, [r1]
	movs r0, 0x1
	b _080A69EC
	.align 2, 0
_080A69C0: .4byte gUnknown_2039DD4
_080A69C4:
	ldr r1, _080A69F4
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r0, r12
	adds r0, 0x70
	movs r1, 0
	strb r1, [r0]
	ldr r0, _080A69F8
	strh r0, [r6]
	strh r1, [r7]
	mov r0, r12
	adds r0, 0x6C
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	movs r0, 0
_080A69EC:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A69F4: .4byte gUnknown_2039DD0
_080A69F8: .4byte 0x0000ffff
	thumb_func_end sub_80A68F8

	thumb_func_start sub_80A69FC
sub_80A69FC:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r6, 0
	adds r7, 0x52
	movs r0, 0
	ldrsh r4, [r7, r0]
	ldr r0, _080A6A80
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	ldr r0, [r0]
	adds r5, r0, r1
	cmp r4, 0
	blt _080A6A7A
	adds r0, r6, 0
	bl GroundSprite_ExtendPaletteDelete
	movs r0, 0
	str r0, [r5, 0x8]
	str r0, [r5]
	adds r5, 0xC
	ldr r1, _080A6A84
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	asrs r4, r0, 16
	adds r6, 0x64
	mov r12, r6
	cmp r4, 0x15
	bgt _080A6A6A
	ldr r0, [r5]
	cmp r0, 0x2
	bne _080A6A6A
	movs r6, 0
	adds r2, r1, 0
	lsls r1, r4, 16
	movs r0, 0x80
	lsls r0, 9
	adds r1, r0
	adds r3, r0, 0
_080A6A50:
	str r6, [r5]
	adds r5, 0xC
	ldr r0, [r2]
	adds r0, 0x1
	str r0, [r2]
	adds r0, r1, 0
	adds r1, r3
	asrs r4, r0, 16
	cmp r4, 0x15
	bgt _080A6A6A
	ldr r0, [r5]
	cmp r0, 0x2
	beq _080A6A50
_080A6A6A:
	ldr r0, _080A6A88
	strh r0, [r7]
	movs r0, 0
	mov r1, r12
	strh r0, [r1]
	ldr r1, _080A6A8C
	movs r0, 0x1
	strb r0, [r1]
_080A6A7A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6A80: .4byte gUnknown_3001B7C
_080A6A84: .4byte gUnknown_2039DD4
_080A6A88: .4byte 0x0000ffff
_080A6A8C: .4byte gUnknown_2039DD0
	thumb_func_end sub_80A69FC

	thumb_func_start GroundSprite_ExtendPaletteAdd
GroundSprite_ExtendPaletteAdd:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r10, r0
	lsls r1, 16
	lsrs r2, r1, 16
	adds r5, r2, 0
	movs r0, 0xC0
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	bne _080A6AB0
	b _080A6C6C
_080A6AB0:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r2
	cmp r0, 0
	beq _080A6AD8
	ldr r0, _080A6AD4
	ldr r1, [r0]
	movs r3, 0x86
	lsls r3, 1
	adds r4, r1, r3
	ldrh r1, [r4]
	adds r3, r0, 0
	cmp r1, r2
	bne _080A6B36
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _080A6C78
	.align 2, 0
_080A6AD4: .4byte gUnknown_3001B7C
_080A6AD8:
	movs r0, 0
	mov r8, r0
	ldr r1, _080A6B1C
	ldr r0, [r1]
	movs r2, 0x84
	lsls r2, 1
	adds r4, r0, r2
	adds r3, r1, 0
	movs r1, 0xE8
	lsls r1, 13
_080A6AEC:
	ldrh r0, [r4]
	cmp r0, r5
	bne _080A6B24
	lsrs r1, 16
	adds r3, r1, 0
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	mov r0, r10
	cmp r0, 0
	beq _080A6B08
	subs r1, 0x10
	adds r0, 0x68
	strh r1, [r0]
_080A6B08:
	adds r0, r3, 0
	subs r0, 0x10
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	ldr r1, _080A6B20
	mov r2, r8
	bl Log
	b _080A6C78
	.align 2, 0
_080A6B1C: .4byte gUnknown_3001B7C
_080A6B20: .4byte gUnknown_81177F4
_080A6B24:
	movs r2, 0x80
	lsls r2, 9
	adds r1, r2
	movs r0, 0x1
	add r8, r0
	adds r4, 0x4
	mov r2, r8
	cmp r2, 0x1
	ble _080A6AEC
_080A6B36:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r5
	cmp r0, 0
	beq _080A6B68
	movs r0, 0x1
	mov r8, r0
	ldr r0, [r3]
	movs r1, 0x86
	lsls r1, 1
	adds r4, r0, r1
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080A6BA8
	ldr r0, _080A6B60
	ldr r1, _080A6B64
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A6B60: .4byte gUnknown_8117858
_080A6B64: .4byte gUnknown_8117864
_080A6B68:
	movs r0, 0
	mov r8, r0
	ldr r0, [r3]
	movs r1, 0x84
	lsls r1, 1
	adds r4, r0, r1
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080A6B90
_080A6B7C:
	movs r3, 0x1
	add r8, r3
	adds r4, 0x4
	mov r0, r8
	cmp r0, 0x1
	bgt _080A6B96
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _080A6B7C
_080A6B90:
	mov r2, r8
	cmp r2, 0x1
	ble _080A6BA8
_080A6B96:
	ldr r0, _080A6BA0
	ldr r1, _080A6BA4
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A6BA0: .4byte gUnknown_8117888
_080A6BA4: .4byte gUnknown_8117864
_080A6BA8:
	mov r0, r8
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r3, r8
	lsls r0, r3, 20
	movs r1, 0xE8
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	str r0, [sp, 0x10]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r5
	cmp r0, 0
	beq _080A6BE8
	ldr r0, _080A6BE0
	ldr r1, _080A6BE4
	bl OpenFileAndGetFileDataPtr
	mov r9, r0
	ldr r7, [r0, 0x4]
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 6
	adds r7, r0
	b _080A6BFE
	.align 2, 0
_080A6BE0: .4byte gUnknown_81177EC
_080A6BE4: .4byte gUnknown_8510000
_080A6BE8:
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 2
	ldr r1, _080A6C60
	adds r0, r1
	ldr r0, [r0]
	ldr r1, _080A6C64
	bl OpenFileAndGetFileDataPtr
	mov r9, r0
	ldr r7, [r0, 0x4]
_080A6BFE:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r5
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	lsrs r6, r0, 31
	movs r0, 0x80
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A6C1A
	movs r0, 0x2
	orrs r6, r0
_080A6C1A:
	ldr r0, [sp, 0xC]
	adds r1, r6, 0
	bl sub_80997F4
	ldr r0, [sp, 0x10]
	adds r1, r7, 0
	movs r2, 0x10
	bl sub_809971C
	strh r5, [r4]
	movs r0, 0x1
	strh r0, [r4, 0x2]
	ldr r2, [sp, 0xC]
	subs r2, 0x10
	mov r3, r10
	cmp r3, 0
	beq _080A6C42
	mov r0, r10
	adds r0, 0x68
	strh r2, [r0]
_080A6C42:
	ldr r1, _080A6C68
	str r2, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	mov r2, r8
	ldr r3, [sp, 0xC]
	bl Log
	mov r0, r9
	cmp r0, 0
	beq _080A6C78
	bl CloseFile
	b _080A6C78
	.align 2, 0
_080A6C60: .4byte gUnknown_81178F4
_080A6C64: .4byte gUnknown_9E60000
_080A6C68: .4byte gUnknown_8117894
_080A6C6C:
	mov r1, r10
	cmp r1, 0
	beq _080A6C78
	mov r0, r10
	adds r0, 0x68
	strh r5, [r0]
_080A6C78:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundSprite_ExtendPaletteAdd

	thumb_func_start GroundSprite_ExtendPaletteDelete
GroundSprite_ExtendPaletteDelete:
	push {r4-r6,lr}
	adds r2, r0, 0
	cmp r2, 0
	beq _080A6C9E
	adds r0, 0x68
	ldrh r0, [r0]
	adds r5, r0, 0
	subs r5, 0xD
	cmp r5, 0
	blt _080A6CE6
	b _080A6CA0
_080A6C9E:
	movs r5, 0x1
_080A6CA0:
	ldr r0, _080A6CEC
	lsls r1, r5, 2
	movs r3, 0x84
	lsls r3, 1
	adds r1, r3
	ldr r0, [r0]
	adds r4, r0, r1
	cmp r2, 0
	beq _080A6CBA
	adds r1, r2, 0
	adds r1, 0x68
	movs r0, 0
	strh r0, [r1]
_080A6CBA:
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	movs r6, 0
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _080A6CE6
	ldr r1, _080A6CF0
	ldrh r3, [r4]
	movs r0, 0
	adds r2, r5, 0
	bl Log
	strh r6, [r4]
	strh r6, [r4, 0x2]
	adds r0, r5, 0
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_80997F4
_080A6CE6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A6CEC: .4byte gUnknown_3001B7C
_080A6CF0: .4byte gUnknown_81178C0
	thumb_func_end GroundSprite_ExtendPaletteDelete

	thumb_func_start sub_80A6CF4
sub_80A6CF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x68
	movs r1, 0
	mov r8, r1
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r9, r2
	movs r2, 0
	mov r10, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x60]
	str r0, [sp, 0x64]
	add r4, sp, 0x58
	adds r0, r4, 0
	bl sub_809D248
	movs r7, 0
	ldr r0, _080A6D70
	ldr r3, [r0]
	movs r1, 0x80
	lsls r1, 6
	mov r12, r1
	mov r4, sp
_080A6D2C:
	ldr r0, [r3]
	cmp r0, 0x1
	bne _080A6DB4
	ldr r2, [r3, 0x8]
	adds r0, r2, 0
	adds r0, 0x50
	ldrh r1, [r0]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	bne _080A6DB4
	ldr r0, [r2, 0x7C]
	cmp r0, 0
	blt _080A6DB4
	ldr r1, [r2, 0x74]
	cmp r1, 0
	bge _080A6D50
	adds r1, 0xFF
_080A6D50:
	asrs r1, 8
	ldr r0, [sp, 0x58]
	subs r5, r1, r0
	ldr r1, [r2, 0x78]
	cmp r1, 0
	bge _080A6D5E
	adds r1, 0xFF
_080A6D5E:
	asrs r1, 8
	ldr r0, [sp, 0x5C]
	subs r1, r0
	adds r6, r1, 0
	cmp r1, 0
	ble _080A6D74
	adds r0, r6, 0
	adds r0, 0x28
	b _080A6D78
	.align 2, 0
_080A6D70: .4byte gUnknown_3001B7C
_080A6D74:
	movs r0, 0x28
	subs r0, r6
_080A6D78:
	str r0, [r2, 0x7C]
	cmp r5, 0
	ble _080A6D88
	ldr r0, [r2, 0x7C]
	cmp r5, r0
	ble _080A6D92
	str r5, [r2, 0x7C]
	b _080A6D92
_080A6D88:
	negs r1, r5
	ldr r0, [r2, 0x7C]
	cmp r1, r0
	ble _080A6D92
	str r1, [r2, 0x7C]
_080A6D92:
	adds r0, r2, 0
	adds r0, 0x48
	movs r1, 0
	ldrsh r0, [r0, r1]
	add r10, r0
	cmp r0, r9
	blt _080A6DAE
	ldr r0, [r2, 0x7C]
	ldr r1, [sp, 0x64]
	cmp r1, r0
	bge _080A6DAE
	mov r1, r8
	str r1, [sp, 0x60]
	str r0, [sp, 0x64]
_080A6DAE:
	stm r4!, {r2}
	movs r2, 0x1
	add r8, r2
_080A6DB4:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	adds r3, 0xC
	cmp r7, 0x15
	ble _080A6D2C
	cmp r10, r9
	blt _080A6E54
	ldr r0, [sp, 0x60]
	cmp r0, 0
	blt _080A6DD8
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	bl sub_80A69FC
	movs r0, 0x1
	b _080A6E56
_080A6DD8:
	mov r1, r8
	cmp r1, 0
	ble _080A6E54
_080A6DDE:
	movs r5, 0x1
	negs r5, r5
	adds r3, r5, 0
	movs r6, 0
	mov r7, r8
	subs r7, 0x1
	mov r2, r8
	cmp r2, 0
	ble _080A6E08
	mov r2, sp
	mov r1, r8
_080A6DF4:
	ldr r0, [r2]
	ldr r0, [r0, 0x7C]
	cmp r3, r0
	bge _080A6E00
	mov r5, r8
	adds r3, r0, 0
_080A6E00:
	adds r2, 0x4
	subs r1, 0x1
	cmp r1, 0
	bne _080A6DF4
_080A6E08:
	lsls r0, r5, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r0, [r4]
	bl sub_80A69FC
	mov r8, r7
	adds r1, r5, 0
	cmp r1, r8
	bge _080A6E28
	adds r2, r4, 0
_080A6E1E:
	ldr r0, [r2, 0x4]
	stm r2!, {r0}
	adds r1, 0x1
	cmp r1, r8
	blt _080A6E1E
_080A6E28:
	movs r1, 0
	ldr r0, _080A6E40
	ldr r3, [r0]
_080A6E2E:
	ldr r0, [r3]
	cmp r0, 0
	bne _080A6E44
	adds r6, 0x1
	cmp r6, r9
	blt _080A6E46
	movs r0, 0x1
	b _080A6E56
	.align 2, 0
_080A6E40: .4byte gUnknown_3001B7C
_080A6E44:
	movs r6, 0
_080A6E46:
	adds r1, 0x1
	adds r3, 0xC
	cmp r1, 0x15
	ble _080A6E2E
	mov r2, r8
	cmp r2, 0
	bgt _080A6DDE
_080A6E54:
	movs r0, 0
_080A6E56:
	add sp, 0x68
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A6CF4

	thumb_func_start sub_80A6E68
sub_80A6E68:
	push {lr}
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	bl sub_800E970
	pop {r0}
	bx r0
	thumb_func_end sub_80A6E68

	thumb_func_start sub_80A6E80
sub_80A6E80:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080A6EC4
	adds r0, r4, 0
	bl sub_809D248
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A6E98
	str r0, [r4]
	str r0, [r4, 0x4]
_080A6E98:
	bl sub_80ABA7C
	bl sub_80ACAD4
	bl sub_80AD7AC
	ldrh r1, [r4, 0x4]
	lsls r1, 16
	ldrh r0, [r4]
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	bl sub_800E90C
	bl sub_8005180
	bl nullsub_12
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A6EC4: .4byte gUnknown_2039DD8
	thumb_func_end sub_80A6E80

	thumb_func_start sub_80A6EC8
sub_80A6EC8:
	push {lr}
	adds r2, r0, 0
	adds r0, 0x52
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	ble _080A6EF6
	adds r0, r2, 0
	adds r0, 0x48
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bgt _080A6EE4
	adds r1, r0, 0
_080A6EE4:
	adds r0, r2, 0
	adds r0, 0x64
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, r1
	beq _080A6EF6
	adds r0, r2, 0
	adds r0, 0x66
	strh r1, [r0]
_080A6EF6:
	pop {r0}
	bx r0
	thumb_func_end sub_80A6EC8

	thumb_func_start sub_80A6EFC
sub_80A6EFC:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080A6F48
	adds r5, r4, 0
	adds r5, 0x66
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r0, 0
	blt _080A6F28
	adds r1, r4, 0
	adds r1, 0x48
	adds r2, r0, 0
	b _080A6F62
_080A6F28:
	adds r1, r4, 0
	adds r1, 0x48
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bgt _080A6F36
	b _080A7038
_080A6F36:
	movs r2, 0x1
	negs r2, r2
	adds r0, r4, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	beq _080A7038
	b _080A6F72
_080A6F48:
	adds r5, r4, 0
	adds r5, 0x66
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080A6F72
	adds r0, r4, 0
	bl sub_80A69FC
	adds r1, r4, 0
	adds r1, 0x48
	movs r0, 0
	ldrsh r2, [r5, r0]
_080A6F62:
	adds r0, r4, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	beq _080A7038
	ldr r0, _080A6F8C
	strh r0, [r5]
_080A6F72:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r7
	lsls r0, 16
	asrs r3, r0, 16
	cmp r3, 0
	beq _080A6F94
	ldrh r1, [r4]
	ldr r0, _080A6F90
	ands r0, r1
	strh r0, [r4]
	b _080A7038
	.align 2, 0
_080A6F8C: .4byte 0x0000ffff
_080A6F90: .4byte 0x0000efff
_080A6F94:
	ldr r2, _080A6FE0
	adds r0, r4, 0
	adds r0, 0x52
	movs r5, 0
	ldrsh r1, [r0, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	mov r12, r1
	adds r1, r4, 0
	adds r1, 0x70
	movs r0, 0x1
	strb r0, [r1]
	subs r0, 0x2
	str r0, [r4, 0x7C]
	movs r1, 0xE0
	lsls r1, 3
	ands r1, r7
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _080A6FE4
	cmp r1, r0
	ble _080A6FEE
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	beq _080A6FFA
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	bne _080A6FEE
	adds r0, r4, 0
	adds r0, 0x6C
	strh r3, [r0]
	b _080A7000
	.align 2, 0
_080A6FE0: .4byte gUnknown_3001B7C
_080A6FE4:
	adds r1, r4, 0
	adds r1, 0x6C
	movs r0, 0x80
	strh r0, [r1]
	b _080A7000
_080A6FEE:
	adds r1, r4, 0
	adds r1, 0x6C
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r1]
	b _080A7000
_080A6FFA:
	adds r0, r4, 0
	adds r0, 0x6C
	strh r1, [r0]
_080A7000:
	adds r0, r4, 0
	adds r0, 0x6E
	movs r1, 0
	strh r1, [r0]
	ldr r5, [r4, 0x4C]
	movs r0, 0xFF
	ands r0, r7
	adds r2, r6, 0
	cmp r6, 0
	bge _080A7016
	adds r2, r6, 0x7
_080A7016:
	asrs r2, 3
	adds r2, r0, r2
	movs r3, 0x7
	ands r3, r6
	mov r6, r12
	ldr r0, [r6, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	lsls r0, r7, 16
	lsrs r0, 27
	movs r1, 0x1
	ands r0, r1
	str r0, [sp, 0x8]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80053D0
_080A7038:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A6EFC

	thumb_func_start sub_80A7040
sub_80A7040:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r3, 0
	lsls r1, 16
	asrs r3, r1, 16
	lsls r2, 24
	asrs r2, 24
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A708C
	cmp r3, 0
	beq _080A7068
	movs r0, 0xE0
	lsls r0, 1
	cmp r3, r0
	bne _080A7080
_080A7068:
	adds r0, r4, 0
	bl sub_80A671C
	lsls r0, 24
	cmp r0, 0
	beq _080A708C
	adds r1, r4, 0
	adds r1, 0x58
	movs r0, 0xE0
	lsls r0, 1
	strh r0, [r1]
	b _080A708C
_080A7080:
	adds r0, r4, 0
	adds r0, 0x58
	strh r3, [r0]
	adds r0, 0x2
	strb r2, [r0]
	str r5, [r4, 0x60]
_080A708C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7040

	thumb_func_start sub_80A7094
sub_80A7094:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r7, r0, 0
	mov r10, r1
	mov r8, r2
	str r3, [sp, 0x3C]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [r7, 0x74]
	str r1, [r7, 0x78]
	movs r6, 0
	str r6, [r7, 0x7C]
	adds r0, r7, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A7172
	adds r4, r7, 0
	adds r4, 0x58
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080A7172
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	bne _080A70EC
	ldr r0, [r7, 0x5C]
	movs r5, 0x1
	negs r5, r5
	cmp r0, r5
	beq _080A70E8
	bl sub_800DC14
	str r5, [r7, 0x5C]
_080A70E8:
	strh r6, [r4]
	b _080A7172
_080A70EC:
	ldr r0, [r7, 0x5C]
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	cmp r0, r9
	bne _080A7160
	add r1, sp, 0x8
	ldr r0, _080A715C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_800EE5C
	bl sub_800EF64
	add r2, sp, 0x14
	movs r3, 0
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x14]
	str r6, [r2, 0x4]
	adds r0, r7, 0
	adds r0, 0x5A
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	str r0, [r2, 0x8]
	mov r4, r8
	ldr r0, [r4]
	cmp r0, 0
	bge _080A712C
	adds r0, 0xFF
_080A712C:
	asrs r0, 8
	strh r0, [r2, 0xC]
	mov r5, r8
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _080A713A
	adds r0, 0xFF
_080A713A:
	asrs r0, 8
	strh r0, [r2, 0xE]
	strh r6, [r2, 0x10]
	strh r6, [r2, 0x12]
	mov r0, r9
	str r0, [r2, 0x14]
	str r6, [r2, 0x18]
	add r1, sp, 0x30
	add r0, sp, 0x8
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	adds r0, r2, 0
	bl sub_800E890
	str r0, [r7, 0x5C]
	b _080A7172
	.align 2, 0
_080A715C: .4byte gUnknown_81178E0
_080A7160:
	bl sub_800E9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A7172
	mov r1, r9
	str r1, [r7, 0x5C]
	strh r0, [r4]
_080A7172:
	adds r0, r7, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	blt _080A7222
	adds r0, r7, 0
	adds r0, 0x50
	ldrh r4, [r0]
	movs r0, 0x40
	ands r0, r4
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0
	bne _080A7222
	mov r3, r8
	ldr r1, [r3]
	cmp r1, 0
	bge _080A719C
	adds r1, 0xFF
_080A719C:
	asrs r1, 8
	ldr r2, _080A7228
	ldr r0, [r2]
	subs r5, r1, r0
	mov r1, r8
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bge _080A71AE
	adds r0, 0xFF
_080A71AE:
	asrs r1, r0, 8
	ldr r0, [r2, 0x4]
	subs r6, r1, r0
	ldr r3, [sp, 0x3C]
	cmp r3, 0
	bge _080A71BC
	adds r3, 0xFF
_080A71BC:
	asrs r0, r3, 8
	subs r0, r6, r0
	mov r8, r0
	adds r1, r5, 0
	adds r1, 0x40
	ldr r0, _080A722C
	cmp r1, r0
	bhi _080A7274
	movs r0, 0x10
	negs r0, r0
	cmp r6, r0
	blt _080A7274
	cmp r6, 0xCF
	bgt _080A7274
	cmp r8, r0
	blt _080A7274
	mov r2, r8
	cmp r2, 0xCF
	bgt _080A7274
	movs r0, 0x10
	ands r0, r4
	cmp r0, 0
	beq _080A7234
	ldr r0, _080A7230
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7234
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A72B8
	movs r1, 0x98
	lsls r1, 1
	adds r0, r7, 0
	adds r0, 0x68
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0xD0
	movs r3, 0
	bl sub_800558C
	adds r0, r7, 0
	adds r0, 0x70
	mov r3, r9
	strb r3, [r0]
_080A7222:
	movs r0, 0
	b _080A72A6
	.align 2, 0
_080A7228: .4byte gUnknown_2039DD8
_080A722C: .4byte 0x0000016f
_080A7230: .4byte gUnknown_2039DCC
_080A7234:
	adds r4, r7, 0
	adds r4, 0x70
	ldrb r1, [r4]
	adds r0, r7, 0
	bl sub_80A72B8
	adds r0, r7, 0
	adds r0, 0x6A
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r3, r6
	subs r0, 0x2
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r8
	bl sub_800558C
	movs r0, 0
	strb r0, [r4]
	mov r2, r10
	cmp r2, 0
	beq _080A7270
	mov r3, r10
	str r5, [r3]
	str r6, [r3, 0x4]
_080A7270:
	movs r0, 0x1
	b _080A72A6
_080A7274:
	adds r4, r7, 0
	adds r4, 0x70
	ldrb r0, [r4]
	cmp r0, 0
	beq _080A7222
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_80A72B8
	movs r1, 0x98
	lsls r1, 1
	adds r0, r7, 0
	adds r0, 0x68
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0xD0
	movs r3, 0
	bl sub_800558C
	movs r0, 0
	strb r0, [r4]
_080A72A6:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7094

	thumb_func_start sub_80A72B8
sub_80A72B8:
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	cmp r1, 0
	beq _080A72D2
	adds r1, r6, 0
	adds r1, 0x6E
	movs r0, 0
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_80054BC
	b _080A7304
_080A72D2:
	adds r5, r6, 0
	adds r5, 0x6E
	adds r0, r6, 0
	adds r0, 0x6C
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _080A7304
	ldr r0, _080A730C
	adds r7, r0, 0
_080A72EE:
	adds r4, r5, 0
	ldrh r1, [r5]
	adds r0, r7, r1
	strh r0, [r5]
	adds r0, r6, 0
	bl sub_80054BC
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	bgt _080A72EE
_080A7304:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A730C: .4byte 0xffffff00
	thumb_func_end sub_80A72B8

	thumb_func_start sub_80A7310
sub_80A7310:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	mov r12, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A73DC
	mov r0, r12
	ldr r0, [r0, 0x5C]
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	beq _080A73DC
	ldr r0, [r4]
	cmp r0, 0
	bge _080A7344
	adds r0, 0xFF
_080A7344:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080A73D0
	mov r9, r1
	ldr r2, [sp, 0x4]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bge _080A735C
	adds r0, 0xFF
_080A735C:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r6, _080A73D4
	adds r4, r6, 0
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x4]
	asrs r2, r4, 16
	ldr r0, _080A73D8
	ldr r0, [r0, 0x4]
	subs r0, r2, r0
	mov r1, r12
	adds r1, 0x6A
	movs r7, 0
	ldrsh r1, [r1, r7]
	adds r0, r1
	adds r7, r0, 0x2
	cmp r3, 0
	bge _080A7386
	adds r3, 0xFF
_080A7386:
	asrs r0, r3, 8
	subs r0, r2, r0
	lsls r0, 16
	adds r2, r6, 0
	ands r2, r4
	orrs r2, r0
	str r2, [sp, 0x4]
	cmp r5, 0
	beq _080A73B8
	ldr r1, [r5]
	add r0, sp, 0x4
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	asrs r2, r0, 16
	ldr r1, [r5, 0x4]
	adds r1, r2
	lsls r1, 16
	ands r0, r6
	orrs r0, r1
	str r0, [sp, 0x4]
_080A73B8:
	mov r0, r12
	adds r0, 0x3C
	str r0, [sp]
	mov r0, r8
	add r1, sp, 0x4
	movs r2, 0
	adds r3, r7, 0
	bl sub_800E8AC
	movs r0, 0x1
	b _080A73DE
	.align 2, 0
_080A73D0: .4byte 0xffff0000
_080A73D4: .4byte 0x0000ffff
_080A73D8: .4byte gUnknown_2039DD8
_080A73DC:
	movs r0, 0
_080A73DE:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7310

	thumb_func_start sub_80A73EC
sub_80A73EC:
	push {lr}
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	ldr r1, _080A7420
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r1, _080A7424
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB
	bls _080A741A
	movs r0, 0
	strh r0, [r1]
_080A741A:
	pop {r0}
	bx r0
	.align 2, 0
_080A7420: .4byte gUnknown_2039DCC
_080A7424: .4byte gUnknown_2039DCE
	thumb_func_end sub_80A73EC

	thumb_func_start sub_80A7428
sub_80A7428:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	mov r8, r3
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r4, r2, 0
	ldr r1, _080A7480
	mov r0, sp
	bl sprintf
	ldr r1, _080A7484
	mov r0, sp
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	adds r0, r4, 0
	bl sub_808DACC
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080A7488
	ldr r2, [sp, 0xC]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0xC]
	movs r0, 0xD3
	lsls r0, 1
	cmp r4, r0
	bne _080A7490
	ldr r0, _080A748C
	ands r0, r2
	movs r1, 0x91
	lsls r1, 17
	orrs r0, r1
	str r0, [sp, 0xC]
	b _080A74AC
	.align 2, 0
_080A7480: .4byte gUnknown_8117EDC
_080A7484: .4byte gUnknown_8510000
_080A7488: .4byte 0xffff0000
_080A748C: .4byte 0x0000ffff
_080A7490:
	movs r1, 0
	cmp r7, 0x47
	bne _080A7498
	movs r1, 0x1
_080A7498:
	adds r0, r4, 0
	bl sub_808DD68
	lsls r0, 24
	lsrs r0, 8
	ldr r2, _080A74E0
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
_080A74AC:
	ldr r0, [r5, 0x4]
	add r1, sp, 0xC
	str r0, [r1, 0x4]
	adds r0, r6, 0
	mov r2, r8
	bl sub_80A67CC
	str r5, [r6, 0x54]
	adds r0, r6, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A74D4
	movs r1, 0xC0
	lsls r1, 2
	adds r0, r6, 0
	movs r2, 0
	bl sub_80A6EFC
_080A74D4:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A74E0: .4byte 0x0000ffff
	thumb_func_end sub_80A7428

	thumb_func_start sub_80A74E4
sub_80A74E4:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A74E4

	thumb_func_start sub_80A74F0
sub_80A74F0:
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	lsls r2, 24
	asrs r5, r2, 24
	cmp r3, 0
	bge _080A7514
	movs r0, 0xE0
	lsls r0, 1
	cmp r4, r0
	beq _080A7512
	adds r0, r4, 0
	bl sub_800E700
	adds r3, r0, 0
	b _080A7514
_080A7512:
	movs r3, 0
_080A7514:
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A7040
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A74F0

	thumb_func_start sub_80A7524
sub_80A7524:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	adds r5, r0, 0
	adds r6, r2, 0
	adds r7, r3, 0
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	mov r1, sp
	bl sub_80A7094
	lsls r0, 24
	cmp r0, 0
	beq _080A75C0
	ldr r1, [r5, 0x5C]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A758C
	ldr r2, [r5, 0x60]
	cmp r2, 0x3
	bgt _080A7580
	cmp r2, 0
	blt _080A7580
	add r4, sp, 0x8
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800569C
	movs r1, 0
	ldrsh r0, [r4, r1]
	str r0, [sp, 0xC]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	add r2, sp, 0xC
	str r0, [r2, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	adds r3, r7, 0
	bl sub_80A7310
	b _080A758C
_080A7580:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_80A7310
_080A758C:
	adds r0, r5, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080A75B4
	ldr r0, [sp]
	lsls r0, 16
	ldr r1, [sp, 0x4]
	lsls r1, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x14]
	add r1, sp, 0x14
	mov r0, r8
	adds r2, r5, 0
	bl sub_808E668
_080A75B4:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_80A7310
_080A75C0:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7524

	thumb_func_start sub_80A75CC
sub_80A75CC:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 13
	ldr r0, _080A7618
	adds r2, r0
	movs r5, 0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _080A761C
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r3, [r2, 0x2]
	lsls r3, 16
	ldr r0, _080A7620
	ands r0, r1
	orrs r0, r3
	str r0, [sp]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _080A7628
	ldr r1, _080A7624
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	b _080A762A
	.align 2, 0
_080A7618: .4byte gUnknown_8117AE4
_080A761C: .4byte 0xffff0000
_080A7620: .4byte 0x0000ffff
_080A7624: .4byte gUnknown_9E60000
_080A7628:
	str r5, [sp, 0x4]
_080A762A:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r6, 0
	bl sub_80A67CC
	str r5, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A764E
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A6EFC
_080A764E:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A75CC

	thumb_func_start sub_80A7658
sub_80A7658:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A7658

	thumb_func_start sub_80A7664
sub_80A7664:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	movs r1, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80A7094
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	adds r3, r6, 0
	bl sub_80A7310
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7664

	thumb_func_start sub_80A7688
sub_80A7688:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 13
	ldr r0, _080A76D4
	adds r2, r0
	movs r5, 0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _080A76D8
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r3, [r2, 0x2]
	lsls r3, 16
	ldr r0, _080A76DC
	ands r0, r1
	orrs r0, r3
	str r0, [sp]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _080A76E4
	ldr r1, _080A76E0
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	b _080A76E6
	.align 2, 0
_080A76D4: .4byte gUnknown_8117E8C
_080A76D8: .4byte 0xffff0000
_080A76DC: .4byte 0x0000ffff
_080A76E0: .4byte gUnknown_9E60000
_080A76E4:
	str r5, [sp, 0x4]
_080A76E6:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r6, 0
	bl sub_80A67CC
	str r5, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A770A
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A6EFC
_080A770A:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7688

	thumb_func_start sub_80A7714
sub_80A7714:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A7714

	thumb_func_start sub_80A7720
sub_80A7720:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	movs r1, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80A7094
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	adds r3, r6, 0
	bl sub_80A7310
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7720

	thumb_func_start sub_80A7744
sub_80A7744:
	ldr r1, _080A7750
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.align 2, 0
_080A7750: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7744

	thumb_func_start sub_80A7754
sub_80A7754:
	ldr r1, _080A7760
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
	bx lr
	.align 2, 0
_080A7760: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7754

	thumb_func_start sub_80A7764
sub_80A7764:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	bl sub_80A7784
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080A777A
	ldr r0, _080A7780
	strh r4, [r0]
_080A777A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7780: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7764

	thumb_func_start sub_80A7784
sub_80A7784:
	push {lr}
	ldr r2, _080A779C
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080A7796
	strh r1, [r2]
_080A7796:
	pop {r0}
	bx r0
	.align 2, 0
_080A779C: .4byte gUnknown_2039DE0
	thumb_func_end sub_80A7784

	thumb_func_start sub_80A77A0
sub_80A77A0:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _080A77BC
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, r1
	beq _080A77CA
	cmp r1, 0
	bge _080A77C0
	bl sub_80A7784
	b _080A77C6
	.align 2, 0
_080A77BC: .4byte gUnknown_2039DE0
_080A77C0:
	adds r0, r2, 0
	bl sub_80A7764
_080A77C6:
	movs r0, 0x1
	b _080A77CC
_080A77CA:
	movs r0, 0
_080A77CC:
	pop {r1}
	bx r1
	thumb_func_end sub_80A77A0

	thumb_func_start sub_80A77D0
sub_80A77D0:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A77E8
	ldr r0, _080A77E4
	b _080A77F0
	.align 2, 0
_080A77E4: .4byte gUnknown_8117EFC
_080A77E8:
	ldr r0, _080A77F4
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
_080A77F0:
	pop {r1}
	bx r1
	.align 2, 0
_080A77F4: .4byte gUnknown_811E258
	thumb_func_end sub_80A77D0

	thumb_func_start sub_80A77F8
sub_80A77F8:
	push {r4,r5,lr}
	ldr r4, _080A7860
	movs r0, 0xCE
	lsls r0, 2
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r4, _080A7864
	movs r0, 0xBA
	lsls r0, 6
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080A7868
	adds r5, r0, 0
	movs r4, 0xF8
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080A7826:
	ldrh r0, [r1, 0x2]
	orrs r0, r5
	strh r0, [r1, 0x2]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0x17
	ble _080A7826
	ldr r4, _080A7860
	ldr r1, [r4]
	movs r0, 0xCB
	lsls r0, 2
	adds r1, r0
	movs r0, 0
	movs r2, 0x19
	bl sub_809D710
	ldr r0, [r4]
	movs r1, 0xCC
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
	bl sub_80A786C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A7860: .4byte gUnknown_3001B80
_080A7864: .4byte gUnknown_3001B84
_080A7868: .4byte 0x0000ffff
	thumb_func_end sub_80A77F8

	thumb_func_start sub_80A786C
sub_80A786C:
	push {r4-r6,lr}
	ldr r0, _080A78E8
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080A787C:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080A788A
	adds r0, r1, 0
	bl GroundLives_Delete
_080A788A:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xF8
	lsls r2, 1
	adds r4, r2
	cmp r1, 0x17
	ble _080A787C
	ldr r3, _080A78EC
	ldr r0, [r3]
	movs r2, 0x1
	negs r2, r2
	str r2, [r0, 0x24]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
	movs r5, 0
	movs r4, 0
	movs r1, 0x2
_080A78B4:
	ldr r0, [r3]
	adds r0, r4
	str r2, [r0, 0x8]
	str r5, [r0]
	str r5, [r0, 0x4]
	adds r4, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _080A78B4
	ldr r4, _080A78EC
	movs r2, 0
	movs r3, 0x2C
	movs r1, 0x3F
_080A78CE:
	ldr r0, [r4]
	adds r0, r3
	str r2, [r0]
	str r2, [r0, 0x4]
	str r2, [r0, 0x8]
	adds r3, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _080A78CE
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A78E8: .4byte gUnknown_3001B84
_080A78EC: .4byte gUnknown_3001B80
	thumb_func_end sub_80A786C

	thumb_func_start sub_80A78F0
sub_80A78F0:
	push {r4,r5,lr}
	bl sub_80A786C
	ldr r4, _080A7914
	ldr r0, [r4]
	bl MemoryFree
	movs r5, 0
	str r5, [r4]
	ldr r4, _080A7918
	ldr r0, [r4]
	bl MemoryFree
	str r5, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A7914: .4byte gUnknown_3001B84
_080A7918: .4byte gUnknown_3001B80
	thumb_func_end sub_80A78F0

	thumb_func_start GroundLives_Select
GroundLives_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080A7980
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080A7984
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x4]
	ldr r0, [r0]
	cmp r0, 0
	ble _080A7976
	adds r4, r0, 0
_080A7960:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundLives_Add
	subs r4, 0x1
	adds r5, 0x18
	cmp r4, 0
	bne _080A7960
_080A7976:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7980: .4byte gUnknown_811808C
_080A7984: .4byte gUnknown_8118098
	thumb_func_end GroundLives_Select

	thumb_func_start GroundLives_Cancel
GroundLives_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080A79F4
	movs r0, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl Log
	movs r1, 0
	ldr r0, _080A79F8
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080A79B2:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080A79D4
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080A79D4
	cmp r5, 0
	blt _080A79CE
	movs r0, 0x6
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080A79D4
_080A79CE:
	adds r0, r1, 0
	bl GroundLives_Delete
_080A79D4:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xF8
	lsls r2, 1
	adds r4, r2
	cmp r1, 0x17
	ble _080A79B2
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A79F4: .4byte gUnknown_81180BC
_080A79F8: .4byte gUnknown_3001B84
	thumb_func_end GroundLives_Cancel

	thumb_func_start sub_80A79FC
sub_80A79FC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080A7A70
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080A7A74
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080A7A20:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080A7A50
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080A7A50
	adds r0, r6, 0
	bl GroundLives_Delete
_080A7A50:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0x17
	ble _080A7A20
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7A70: .4byte gUnknown_81180D8
_080A7A74: .4byte gUnknown_3001B84
	thumb_func_end sub_80A79FC

	thumb_func_start sub_80A7A78
sub_80A7A78:
	push {r4-r7,lr}
	ldr r1, _080A7AC0
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080A7AC4
	ldr r4, [r0]
	movs r7, 0x1
	negs r7, r7
	movs r0, 0x9F
	lsls r0, 1
	adds r5, r4, r0
_080A7A92:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080A7ACC
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 4
	ands r0, r1
	cmp r0, 0
	beq _080A7AC8
	movs r0, 0xA2
	lsls r0, 1
	adds r1, r4, r0
	adds r0, 0x8
	adds r2, r4, r0
	movs r0, 0x20
	bl sub_80ADCA0
	b _080A7ACA
	.align 2, 0
_080A7AC0: .4byte gUnknown_81180D8
_080A7AC4: .4byte gUnknown_3001B84
_080A7AC8:
	ldr r0, _080A7AE4
_080A7ACA:
	strh r0, [r5]
_080A7ACC:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r5, r1
	adds r4, r1
	cmp r6, 0x17
	ble _080A7A92
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7AE4: .4byte 0x0000ffff
	thumb_func_end sub_80A7A78

	thumb_func_start sub_80A7AE8
sub_80A7AE8:
	push {r4-r7,lr}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl sub_80A7B94
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080A7B34
	movs r3, 0
	ldr r0, _080A7B24
	ldr r1, [r0]
	adds r4, r2, 0
	movs r2, 0x80
	lsls r2, 9
	adds r6, r2, 0
	movs r5, 0xF8
	lsls r5, 1
_080A7B16:
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080A7B28
	adds r0, r3, 0
	b _080A7B38
	.align 2, 0
_080A7B24: .4byte gUnknown_3001B84
_080A7B28:
	adds r0, r2, 0
	adds r2, r6
	asrs r3, r0, 16
	adds r1, r5
	cmp r3, 0x17
	ble _080A7B16
_080A7B34:
	movs r0, 0x1
	negs r0, r0
_080A7B38:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7AE8

	thumb_func_start sub_80A7B40
sub_80A7B40:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080A7B70
	ldr r1, [r0]
	movs r6, 0x1
	negs r6, r6
	movs r2, 0x80
	lsls r2, 9
	movs r5, 0x9E
	lsls r5, 1
_080A7B58:
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _080A7B74
	adds r0, r1, r5
	movs r7, 0
	ldrsh r0, [r0, r7]
	cmp r0, r4
	bne _080A7B74
	adds r0, r3, 0
	b _080A7B8C
	.align 2, 0
_080A7B70: .4byte gUnknown_3001B84
_080A7B74:
	adds r0, r2, 0
	movs r3, 0x80
	lsls r3, 9
	adds r2, r3
	asrs r3, r0, 16
	movs r7, 0xF8
	lsls r7, 1
	adds r1, r7
	cmp r3, 0x17
	ble _080A7B58
	movs r0, 0x1
	negs r0, r0
_080A7B8C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7B40

	thumb_func_start sub_80A7B94
sub_80A7B94:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r7, r0, 0
	movs r0, 0
	ldrsh r2, [r7, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A7BD4
	adds r0, r1
	movs r6, 0x1
	negs r6, r6
	movs r1, 0
	ldrsh r5, [r0, r1]
	cmp r5, 0x1
	bne _080A7C14
	adds r0, r2, 0
	cmp r0, 0
	bne _080A7C10
	movs r0, 0
	movs r1, 0x1C
	bl sub_8001658
	adds r4, r0, 0
	cmp r4, 0x1
	beq _080A7BDE
	cmp r4, 0x1
	bgt _080A7BD8
	cmp r4, 0
	beq _080A7BF2
	b _080A7C08
	.align 2, 0
_080A7BD4: .4byte gUnknown_811E63C
_080A7BD8:
	cmp r4, 0x2
	beq _080A7BE4
	b _080A7C08
_080A7BDE:
	movs r0, 0x2
	strh r0, [r7]
	b _080A7C10
_080A7BE4:
	bl sub_808D33C
	adds r6, r0, 0
	bl sub_808D3BC
	cmp r0, r6
	bne _080A7BF6
_080A7BF2:
	strh r5, [r7]
	b _080A7C10
_080A7BF6:
	bl sub_808D3F8
	cmp r0, r6
	bne _080A7C02
	strh r4, [r7]
	b _080A7C10
_080A7C02:
	movs r0, 0x3
	strh r0, [r7]
	b _080A7C10
_080A7C08:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _080A7DAC
_080A7C10:
	movs r6, 0
	b _080A7DD2
_080A7C14:
	cmp r5, 0x2
	bne _080A7CD2
	movs r0, 0
	movs r1, 0x1D
	bl sub_8001658
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x1E
	bl sub_8001658
	adds r2, r0, 0
	ldrh r1, [r7]
	subs r0, r1, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080A7C82
	cmp r1, 0x4
	bne _080A7C44
	adds r0, r4, 0
	cmp r0, 0
	bne _080A7C4C
	b _080A7C4A
_080A7C44:
	movs r0, 0
	cmp r4, 0
	beq _080A7C4C
_080A7C4A:
	adds r0, r2, 0
_080A7C4C:
	cmp r0, 0x2
	beq _080A7C7A
	cmp r0, 0x2
	bhi _080A7C5A
	cmp r0, 0x1
	beq _080A7C6E
	b _080A7DA6
_080A7C5A:
	cmp r0, 0x3
	beq _080A7C60
	b _080A7DA6
_080A7C60:
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	bne _080A7C72
_080A7C6E:
	movs r0, 0x6
	b _080A7C80
_080A7C72:
	bl sub_808D3F8
	cmp r0, r4
	bne _080A7C7E
_080A7C7A:
	movs r0, 0x7
	b _080A7C80
_080A7C7E:
	movs r0, 0x8
_080A7C80:
	strh r0, [r7]
_080A7C82:
	movs r0, 0
	ldrsh r5, [r7, r0]
	cmp r5, 0x7
	beq _080A7CB0
	cmp r5, 0x7
	bgt _080A7C94
	cmp r5, 0x6
	beq _080A7C9A
	b _080A7CCA
_080A7C94:
	cmp r5, 0x8
	beq _080A7CC6
	b _080A7CCA
_080A7C9A:
	movs r6, 0x2
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r4, r0
	beq _080A7CAC
	b _080A7DD2
_080A7CAC:
	strh r5, [r7]
	b _080A7DD2
_080A7CB0:
	movs r6, 0x1
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3F8
	cmp r4, r0
	beq _080A7CC2
	b _080A7DD2
_080A7CC2:
	movs r0, 0x6
	b _080A7DD0
_080A7CC6:
	movs r6, 0x2
	b _080A7DD2
_080A7CCA:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	b _080A7DAC
_080A7CD2:
	cmp r5, 0x3
	bne _080A7DB0
	ldrh r1, [r7]
	adds r0, r1, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A7D12
	adds r4, r2, 0
	subs r4, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _080A7DD2
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7D06
	mov r0, sp
	bl sub_808D6A4
	b _080A7D0C
_080A7D06:
	mov r0, sp
	bl sub_808D654
_080A7D0C:
	cmp r4, r0
	bge _080A7DA6
	b _080A7D7E
_080A7D12:
	adds r0, r1, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A7DA6
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A7DA6
	movs r2, 0
	ldrsh r0, [r7, r2]
	adds r4, r0, 0
	subs r4, 0xE
	adds r0, r1, 0
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bge _080A7DA6
	ldr r2, _080A7D84
	ldr r0, [sp, 0x8]
	adds r0, r4
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7D88
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7DA6
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A7DA6
_080A7D7E:
	movs r0, 0x1
	negs r0, r0
	b _080A7DD4
	.align 2, 0
_080A7D84: .4byte gUnknown_203B45C
_080A7D88:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7DA6
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A7DA6
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A7DA2
	movs r1, 0x1
_080A7DA2:
	cmp r1, 0
	beq _080A7D7E
_080A7DA6:
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
_080A7DAC:
	strh r0, [r7]
	b _080A7D7E
_080A7DB0:
	cmp r2, 0x23
	bne _080A7DD2
	bl sub_808D33C
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	bne _080A7DC6
	movs r0, 0x21
	b _080A7DD0
_080A7DC6:
	bl sub_808D3F8
	cmp r0, r4
	bne _080A7DD2
	movs r0, 0x22
_080A7DD0:
	strh r0, [r7]
_080A7DD2:
	adds r0, r6, 0
_080A7DD4:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7B94

	thumb_func_start sub_80A7DDC
sub_80A7DDC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x24
	adds r7, r0, 0
	adds r5, r1, 0
	bl sub_80A7B94
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0
	strh r0, [r5]
	ldrh r3, [r7]
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r6, 0x1
	negs r6, r6
	cmp r0, r6
	bne _080A7E0A
_080A7E04:
	movs r0, 0x1
	negs r0, r0
	b _080A8098
_080A7E0A:
	movs r0, 0
	ldrsh r2, [r7, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A7E50
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	beq _080A7E22
	b _080A7F38
_080A7E22:
	adds r0, r3, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A7E90
	adds r4, r2, 0
	subs r4, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	beq _080A7E58
	ldr r0, _080A7E54
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
	cmp r0, 0
	bne _080A7E04
	strh r6, [r7]
	b _080A7E04
	.align 2, 0
_080A7E50: .4byte gUnknown_811E63C
_080A7E54: .4byte gUnknown_81180F0
_080A7E58:
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7E6C
	mov r0, sp
	bl sub_808D6A4
	b _080A7E72
_080A7E6C:
	mov r0, sp
	bl sub_808D654
_080A7E72:
	cmp r4, r0
	blt _080A7E78
	b _080A8080
_080A7E78:
	ldr r2, _080A7E8C
	lsls r0, r4, 2
	add r0, sp
	ldr r1, [r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldrh r0, [r0, 0x8]
	b _080A800A
	.align 2, 0
_080A7E8C: .4byte gUnknown_203B45C
_080A7E90:
	adds r0, r3, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bls _080A7E9E
	b _080A8080
_080A7E9E:
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _080A7EB8
	b _080A8080
_080A7EB8:
	movs r2, 0
	ldrsh r0, [r7, r2]
	adds r4, r0, 0
	subs r4, 0xE
	adds r0, r1, 0
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _080A7ED8
	b _080A8080
_080A7ED8:
	ldr r2, _080A7F0C
	ldr r0, [sp, 0x8]
	adds r0, r4
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A7F10
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A7EFE
	b _080A8080
_080A7EFE:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _080A7F06
	b _080A8080
_080A7F06:
	ldrh r0, [r4, 0x8]
	b _080A800A
	.align 2, 0
_080A7F0C: .4byte gUnknown_203B45C
_080A7F10:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080A7F1C
	b _080A8080
_080A7F1C:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _080A7F24
	b _080A8080
_080A7F24:
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A7F2E
	movs r1, 0x1
_080A7F2E:
	cmp r1, 0
	beq _080A7F34
	b _080A8080
_080A7F34:
	ldrh r0, [r4, 0x8]
	b _080A800A
_080A7F38:
	subs r0, r3, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x23
	bls _080A7F44
	b _080A808A
_080A7F44:
	lsls r0, 2
	ldr r1, _080A7F50
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A7F50: .4byte _080A7F54
	.align 2, 0
_080A7F54:
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A808A
	.4byte _080A8032
	.4byte _080A8032
	.4byte _080A8014
	.4byte _080A7FE4
	.4byte _080A7FEC
	.4byte _080A7FF4
	.4byte _080A7FFC
_080A7FE4:
	bl sub_808D3BC
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FEC:
	bl sub_808D3F8
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FF4:
	bl sub_808D33C
	ldrh r0, [r0, 0x8]
	b _080A8094
_080A7FFC:
	movs r0, 0xF
	bl RandomCapped
	ldr r1, _080A8010
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
_080A800A:
	strh r0, [r5]
	b _080A7E04
	.align 2, 0
_080A8010: .4byte gUnknown_81180FC
_080A8014:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080A8028
	strh r0, [r5]
	b _080A7E04
_080A8028:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r7]
	b _080A7E04
_080A8032:
	movs r0, 0x89
	strh r0, [r5]
	add r6, sp, 0x10
	adds r0, r6, 0
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	bne _080A8046
	b _080A7E04
_080A8046:
	add r1, sp, 0x14
	add r2, sp, 0x18
	movs r0, 0x2
	bl sub_8001B88
	add r4, sp, 0x1C
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r6]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	beq _080A8076
	movs r2, 0
	ldrsh r0, [r7, r2]
	cmp r0, 0x1E
	bne _080A8072
	ldrh r0, [r4, 0x2]
	b _080A8074
_080A8072:
	ldrh r0, [r4, 0x4]
_080A8074:
	strh r0, [r5]
_080A8076:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080A8080
	b _080A7E04
_080A8080:
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r7]
	b _080A7E04
_080A808A:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bne _080A8096
	ldrh r0, [r4, 0x2]
_080A8094:
	strh r0, [r5]
_080A8096:
	mov r0, r8
_080A8098:
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7DDC

	thumb_func_start GroundLives_Add
GroundLives_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r1, [sp, 0x10]
	lsls r0, 16
	asrs r6, r0, 16
	lsls r2, 16
	asrs r2, 16
	str r2, [sp, 0x14]
	lsls r3, 24
	asrs r3, 24
	str r3, [sp, 0x18]
	ldrb r1, [r1]
	add r0, sp, 0xC
	strh r1, [r0]
	movs r0, 0
	mov r8, r0
	mov r4, sp
	adds r4, 0xE
	add r0, sp, 0xC
	adds r1, r4, 0
	bl sub_80A7DDC
	lsls r0, 16
	asrs r7, r0, 16
	add r0, sp, 0xC
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	mov r9, r4
	cmp r1, r0
	beq _080A81AE
	cmp r7, 0x1
	beq _080A8104
	cmp r7, 0x1
	bgt _080A80FA
	cmp r7, 0
	beq _080A8100
	b _080A8118
_080A80FA:
	cmp r7, 0x2
	beq _080A8108
	b _080A8118
_080A8100:
	movs r6, 0
	b _080A8118
_080A8104:
	movs r6, 0x1
	b _080A8118
_080A8108:
	movs r0, 0
	movs r1, 0x1D
	bl sub_8001658
	cmp r0, 0
	bne _080A8116
	movs r7, 0x1
_080A8116:
	movs r6, 0x2
_080A8118:
	add r0, sp, 0xC
	movs r3, 0
	ldrsh r2, [r0, r3]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A813C
	adds r0, r1
	str r0, [sp, 0x1C]
	cmp r6, 0
	bge _080A81B4
	cmp r2, 0x21
	beq _080A8140
	cmp r2, 0x23
	beq _080A8154
	adds r0, r2, 0
	b _080A8162
	.align 2, 0
_080A813C: .4byte gUnknown_811E63C
_080A8140:
	ldr r0, _080A8150
	ldr r0, [r0]
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	cmp r0, 0x1
	beq _080A81AE
	movs r0, 0x21
	b _080A8162
	.align 2, 0
_080A8150: .4byte gUnknown_3001B84
_080A8154:
	ldr r0, _080A8188
	ldr r0, [r0]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0x3
	beq _080A81AE
	movs r0, 0x23
_080A8162:
	bl sub_80A7AE8
	adds r6, r0, 0
	cmp r6, 0
	bge _080A81B4
	movs r2, 0x3
	ldr r0, _080A8188
	ldr r0, [r0]
	movs r3, 0xBA
	lsls r3, 3
	adds r5, r0, r3
	movs r4, 0x2
	ldrsh r1, [r5, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A818C
	movs r6, 0x3
	b _080A81B4
	.align 2, 0
_080A8188: .4byte gUnknown_3001B84
_080A818C:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	cmp r2, 0x17
	bgt _080A81AA
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A818C
	adds r6, r2, 0
_080A81AA:
	cmp r6, 0
	bge _080A81B4
_080A81AE:
	movs r0, 0x1
	negs r0, r0
	b _080A8674
_080A81B4:
	ldr r1, _080A8234
	lsls r0, r6, 5
	subs r0, r6
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080A8238
	add r0, sp, 0xC
	movs r4, 0
	ldrsh r3, [r0, r4]
	ldr r2, [sp, 0x1C]
	movs r4, 0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x18]
	str r2, [sp, 0x8]
	movs r0, 0
	adds r2, r6, 0
	bl Log
	movs r2, 0
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A81F0
	movs r2, 0x1
_080A81F0:
	str r2, [sp, 0x20]
	strh r6, [r5]
	add r0, sp, 0xC
	ldrh r0, [r0]
	strh r0, [r5, 0x2]
	mov r4, sp
	ldrh r4, [r4, 0x14]
	strh r4, [r5, 0x4]
	mov r0, sp
	ldrb r0, [r0, 0x18]
	strb r0, [r5, 0x6]
	mov r1, r9
	ldrh r0, [r1]
	strh r0, [r5, 0x8]
	movs r2, 0x90
	lsls r2, 1
	adds r4, r5, r2
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x9
	str r0, [r4]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	bhi _080A82D8
	lsls r0, 2
	ldr r1, _080A823C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A8234: .4byte gUnknown_3001B84
_080A8238: .4byte gUnknown_811811C
_080A823C: .4byte _080A8240
	.align 2, 0
_080A8240:
	.4byte _080A8268
	.4byte _080A8280
	.4byte _080A8290
	.4byte _080A82D8
	.4byte _080A82D8
	.4byte _080A8298
	.4byte _080A82A8
	.4byte _080A82B4
	.4byte _080A82BE
	.4byte _080A82CA
_080A8268:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A827C
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	b _080A82E0
	.align 2, 0
_080A827C: .4byte 0x2300181d
_080A8280:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080A828C
	b _080A82E0
	.align 2, 0
_080A828C: .4byte 0x23001000
_080A8290:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	b _080A82DE
_080A8298:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A82A4
	b _080A82E0
	.align 2, 0
_080A82A4: .4byte 0x2000000d
_080A82A8:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x80
	lsls r0, 10
	b _080A82E0
_080A82B4:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	b _080A82E0
_080A82BE:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0xC0
	lsls r0, 12
	b _080A82E0
_080A82CA:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, _080A82D4
	b _080A82E0
	.align 2, 0
_080A82D4: .4byte 0x20010000
_080A82D8:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
_080A82DE:
	ldr r0, _080A83DC
_080A82E0:
	str r0, [r1]
	ldr r2, [sp, 0x1C]
	ldrb r1, [r2, 0x8]
	lsls r1, 11
	str r1, [r5, 0xC]
	ldrb r0, [r2, 0x9]
	lsls r0, 11
	str r0, [r5, 0x10]
	lsrs r1, 1
	str r1, [r5, 0x14]
	lsrs r0, 1
	str r0, [r5, 0x18]
	ldr r3, [sp, 0x10]
	ldrb r0, [r3, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, r3, 0
	adds r2, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A8328
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A8328
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080A8328:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080A834A
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A834A
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080A834A:
	ldr r3, [sp, 0x20]
	cmp r3, 0
	beq _080A83EC
	ldrb r0, [r5, 0x1C]
	movs r4, 0xA1
	lsls r4, 1
	adds r1, r5, r4
	movs r3, 0
	strb r0, [r1]
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0xA6
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	adds r4, 0x6
	adds r2, r5, r4
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r5, r2
	adds r4, 0x10
	adds r0, r5, r4
	str r3, [r0]
	str r3, [r1]
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r5, r1
	strh r7, [r0]
	ldr r1, _080A83E0
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	ldr r1, [r1]
	adds r1, r0
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x8]
	str r3, [r1]
	str r3, [r1, 0x4]
	ldrh r0, [r5, 0x2]
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A83E4
	movs r0, 0x12
	bl OtherRandomCapped
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r5, r2
	strh r0, [r1]
	b _080A83EC
	.align 2, 0
_080A83DC: .4byte 0x2300068d
_080A83E0: .4byte gUnknown_3001B80
_080A83E4:
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r5, r4
	strh r3, [r0]
_080A83EC:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 4
	ands r0, r1
	cmp r0, 0
	beq _080A8418
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r5, r2
	movs r3, 0xA6
	lsls r3, 1
	adds r2, r5, r3
	movs r0, 0x20
	bl sub_80ADCA0
	movs r4, 0x9F
	lsls r4, 1
	adds r1, r5, r4
	b _080A8420
_080A8418:
	movs r0, 0x9F
	lsls r0, 1
	adds r1, r5, r0
	ldr r0, _080A849C
_080A8420:
	strh r0, [r1]
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r1, [sp, 0x20]
	cmp r1, 0
	beq _080A84AC
	ldr r2, _080A84A0
	adds r1, r5, r2
	movs r0, 0xFF
	strb r0, [r1]
	movs r3, 0xAF
	lsls r3, 1
	adds r1, r5, r3
	movs r3, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r4, 0xB0
	lsls r4, 1
	adds r1, r5, r4
	movs r2, 0x1
	movs r0, 0x1
	strh r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r5, r1
	str r3, [r0]
	adds r4, 0x8
	adds r1, r5, r4
	ldr r0, _080A84A4
	strh r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, 0xB5
	lsls r2, 1
	adds r0, r5, r2
	strh r3, [r0]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r5, r3
	movs r4, 0x2
	ldrsh r1, [r5, r4]
	movs r3, 0x8
	ldrsh r2, [r5, r3]
	movs r4, 0x8E
	lsls r4, 1
	adds r3, r5, r4
	ldr r3, [r3]
	bl sub_80A7428
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080A84A8
	ldr r0, [sp, 0x18]
	str r0, [sp]
	b _080A855C
	.align 2, 0
_080A849C: .4byte 0x0000ffff
_080A84A0: .4byte 0x0000015d
_080A84A4: .4byte 0x00000807
_080A84A8: .4byte gUnknown_8117F10
_080A84AC:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r0, _080A84F0
	ldr r1, [r0]
	movs r2, 0xCB
	lsls r2, 2
	adds r1, r2
	adds r0, r4, 0
	bl sub_809D684
	lsls r0, 24
	cmp r0, 0
	beq _080A8550
	adds r0, r5, 0
	adds r0, 0xBE
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	beq _080A84F4
	adds r0, r5, 0
	adds r0, 0xE0
	ldrh r0, [r0]
	mov r10, r0
	adds r0, r5, 0
	adds r0, 0xE2
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r9, r0
	adds r7, r5, 0
	adds r7, 0x80
	movs r0, 0x82
	adds r0, r5
	b _080A8508
	.align 2, 0
_080A84F0: .4byte gUnknown_3001B80
_080A84F4:
	adds r1, r5, 0
	adds r1, 0x80
	ldrh r2, [r1]
	mov r10, r2
	adds r0, r5, 0
	adds r0, 0x82
	movs r3, 0
	ldrsb r3, [r0, r3]
	mov r9, r3
	adds r7, r1, 0
_080A8508:
	mov r8, r0
	adds r0, r4, 0
	bl sub_809D648
	ldr r1, _080A8544
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x14]
	bl sub_809D600
	ldr r0, _080A8548
	ldr r2, [r0]
	movs r1, 0xCB
	lsls r1, 2
	adds r2, r1
	ldr r3, _080A854C
	adds r0, r4, 0
	movs r1, 0
	bl GroundScript_ExecutePP
	mov r2, r10
	strh r2, [r7]
	mov r0, r9
	mov r3, r8
	strb r0, [r3]
	movs r1, 0x1
	mov r8, r1
	b _080A8566
	.align 2, 0
_080A8544: .4byte gUnknown_8117F10
_080A8548: .4byte gUnknown_3001B80
_080A854C: .4byte gUnknown_8118170
_080A8550:
	adds r0, r4, 0
	bl sub_809D648
	ldr r1, _080A861C
	ldr r2, [sp, 0x18]
	str r2, [sp]
_080A855C:
	adds r0, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x14]
	bl sub_809D600
_080A8566:
	ldr r3, [sp, 0x10]
	ldr r2, [r3, 0xC]
	cmp r2, 0
	bne _080A8574
	ldr r0, _080A8620
	adds r0, 0xEC
	ldr r2, [r0]
_080A8574:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_809D6D8
	ldr r0, [sp, 0x10]
	ldr r2, [r0, 0x10]
	cmp r2, 0
	bne _080A8588
	ldr r0, _080A8620
	ldr r2, [r0, 0x38]
_080A8588:
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_809D6D8
	ldr r1, [sp, 0x10]
	ldr r2, [r1, 0x14]
	cmp r2, 0
	bne _080A859C
	ldr r0, _080A8620
	ldr r2, [r0, 0x50]
_080A859C:
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_809D6D8
	ldr r3, [sp, 0x10]
	ldr r2, [r3, 0x8]
	cmp r2, 0
	beq _080A8630
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080A860C
	mov r1, r8
	cmp r1, 0
	bne _080A860C
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	bne _080A860C
	ldr r0, _080A8624
	ldr r2, [r0]
	movs r3, 0xCB
	lsls r3, 2
	adds r2, r3
	ldr r3, _080A8628
	adds r0, r4, 0
	movs r1, 0
	bl GroundScript_ExecutePP
	movs r1, 0xB0
	lsls r1, 1
	adds r0, r5, r1
	movs r2, 0xAF
	lsls r2, 1
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	orrs r0, r1
	adds r1, r5, 0
	adds r1, 0x80
	strh r0, [r1]
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x82
	strb r1, [r0]
_080A860C:
	ldr r3, _080A862C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
	b _080A865A
	.align 2, 0
_080A861C: .4byte gUnknown_8117F10
_080A8620: .4byte gUnknown_812F1F8
_080A8624: .4byte gUnknown_3001B80
_080A8628: .4byte gUnknown_811817C
_080A862C: .4byte gUnknown_8118188
_080A8630:
	mov r4, r8
	cmp r4, 0
	beq _080A865A
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x82
	ldrb r0, [r0]
	movs r2, 0xA1
	lsls r2, 1
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x80
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_80A9750
_080A865A:
	ldr r3, [sp, 0x1C]
	movs r4, 0
	ldrsh r0, [r3, r4]
	cmp r0, 0x1
	bne _080A8672
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _080A8672
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_809D170
_080A8672:
	adds r0, r6, 0
_080A8674:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundLives_Add

	thumb_func_start GroundLives_Delete
GroundLives_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080A86BC
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080A86C0
	movs r0, 0
	bl Log
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A74E4
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080A86C4
	strh r0, [r4, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A86BC: .4byte gUnknown_3001B84
_080A86C0: .4byte gUnknown_8118194
_080A86C4: .4byte 0x0000ffff
	thumb_func_end GroundLives_Delete

	thumb_func_start sub_80A86C8
sub_80A86C8:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8708
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r3, 0x1
	negs r3, r3
	cmp r0, r3
	beq _080A8744
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _080A870C
	movs r0, 0xC0
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A872E
	bl sub_80AB5A4
	b _080A872E
	.align 2, 0
_080A8708: .4byte gUnknown_3001B84
_080A870C:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r5
	cmp r0, 0
	beq _080A872E
	ldr r2, _080A874C
	movs r0, 0
	ldrsh r1, [r1, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	str r3, [r1, 0x8]
	movs r0, 0
	str r0, [r1]
	str r0, [r1, 0x4]
_080A872E:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	orrs r1, r5
	str r1, [r0]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r4, r2
	bl sub_80A6688
_080A8744:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A874C: .4byte gUnknown_3001B80
	thumb_func_end sub_80A86C8

	thumb_func_start sub_80A8750
sub_80A8750:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A87A8
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A87A2
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r4, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080A878C
	movs r0, 0xC0
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A878C
	bl sub_80AB5A4
_080A878C:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	bics r1, r5
	str r1, [r0]
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r4, r2
	bl sub_80A6688
_080A87A2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A87A8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8750

	thumb_func_start sub_80A87AC
sub_80A87AC:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A87DC
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A87D8
	movs r1, 0x90
	lsls r1, 1
	adds r0, r2, r1
	adds r1, r3, 0
	bl sub_809CD8C
_080A87D8:
	pop {r0}
	bx r0
	.align 2, 0
_080A87DC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A87AC

	thumb_func_start sub_80A87E0
sub_80A87E0:
	push {r4,lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8820
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8824
	movs r0, 0x7
	movs r1, 0
	adds r2, r3, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _080A8824
	movs r1, 0x90
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0x5
	bl sub_809CD8C
	movs r0, 0x1
	b _080A8826
	.align 2, 0
_080A8820: .4byte gUnknown_3001B84
_080A8824:
	movs r0, 0
_080A8826:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A87E0

	thumb_func_start sub_80A882C
sub_80A882C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8850
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8854
	movs r0, 0
	b _080A8858
	.align 2, 0
_080A8850: .4byte gUnknown_3001B84
_080A8854:
	adds r0, r2, 0
	adds r0, 0x38
_080A8858:
	pop {r1}
	bx r1
	thumb_func_end sub_80A882C

	thumb_func_start sub_80A885C
sub_80A885C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080A8884
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8888
	movs r0, 0
	b _080A8898
	.align 2, 0
_080A8884: .4byte gUnknown_3001B84
_080A8888:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080A8898:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A885C

	thumb_func_start sub_80A88A0
sub_80A88A0:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A88C4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A88C8
	movs r0, 0
	b _080A88D4
	.align 2, 0
_080A88C4: .4byte gUnknown_3001B84
_080A88C8:
	adds r0, r2, 0
	adds r0, 0x38
	bl sub_809D678
	lsls r0, 24
	lsrs r0, 24
_080A88D4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A88A0

	thumb_func_start GroundLives_ExecuteScript
GroundLives_ExecuteScript:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	asrs r4, 16
	ldr r1, _080A8914
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080A8918
	movs r0, 0x2
	ldrsh r3, [r5, r0]
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A891C
	movs r0, 0
	b _080A8934
	.align 2, 0
_080A8914: .4byte gUnknown_3001B84
_080A8918: .4byte gUnknown_81181B0
_080A891C:
	adds r0, r5, 0
	adds r0, 0x38
	ldr r3, _080A893C
	adds r1, r7, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080A8934:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A893C: .4byte gUnknown_81181F4
	thumb_func_end GroundLives_ExecuteScript

	thumb_func_start _ExecutePlayerScript
_ExecutePlayerScript:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r0, 0xAF
	lsls r0, 1
	adds r1, r3, r0
	movs r2, 0
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r0, 0xB0
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strh r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	movs r0, 0xB4
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldr r1, _080A898C
	cmp r0, r1
	beq _080A8984
	strh r1, [r2]
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080A8984:
	cmp r4, 0
	bne _080A8990
	movs r0, 0
	b _080A89A2
	.align 2, 0
_080A898C: .4byte 0x00000807
_080A8990:
	adds r0, r3, 0
	adds r0, 0x38
	ldr r3, _080A89A8
	adds r1, r5, 0
	adds r2, r4, 0
	bl GroundScript_ExecutePP
	lsls r0, 24
	lsrs r0, 24
_080A89A2:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A89A8: .4byte gUnknown_8118218
	thumb_func_end _ExecutePlayerScript

	thumb_func_start sub_80A89AC
sub_80A89AC:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r4, _080A89CC
	lsls r3, r0, 5
	subs r3, r0
	lsls r3, 4
	ldr r0, [r4]
	adds r0, r3
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A89CC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A89AC

	thumb_func_start GroundLives_ExecutePlayerScriptActionLives
GroundLives_ExecutePlayerScriptActionLives:
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	cmp r2, 0
	blt _080A8A50
	cmp r4, 0
	blt _080A8A50
	ldr r1, _080A8A48
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r5, r2]
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	beq _080A8A50
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	cmp r0, r2
	beq _080A8A50
	adds r6, r1, 0
	adds r6, 0x38
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_809D6E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8A50
	movs r1, 0x1
	lsls r0, r4, 16
	orrs r0, r1
	str r0, [sp, 0xC]
	adds r1, r5, 0
	adds r1, 0x40
	ldr r3, _080A8A4C
	adds r0, r6, 0
	movs r2, 0x3
	bl sub_809D8C0
	add r1, sp, 0xC
	adds r0, r5, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8A52
	.align 2, 0
_080A8A48: .4byte gUnknown_3001B84
_080A8A4C: .4byte gUnknown_8118250
_080A8A50:
	movs r0, 0
_080A8A52:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GroundLives_ExecutePlayerScriptActionLives

	thumb_func_start sub_80A8A5C
sub_80A8A5C:
	push {r4-r6,lr}
	sub sp, 0x1C
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r5, r1, 16
	cmp r2, 0
	blt _080A8AC0
	cmp r5, 0
	blt _080A8AC0
	ldr r1, _080A8ABC
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x2
	bl sub_80AC274
	lsls r0, 24
	cmp r0, 0
	beq _080A8AC0
	movs r1, 0x2
	lsls r0, r5, 16
	orrs r0, r1
	str r0, [sp, 0x18]
	add r4, sp, 0xC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x3
	bl sub_80AC274
	adds r1, r6, 0
	adds r1, 0x40
	adds r0, r5, 0
	adds r2, r4, 0
	bl GroundObject_ExecuteScript
	add r1, sp, 0x18
	adds r0, r6, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8AC2
	.align 2, 0
_080A8ABC: .4byte gUnknown_3001B84
_080A8AC0:
	movs r0, 0
_080A8AC2:
	add sp, 0x1C
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8A5C

	thumb_func_start sub_80A8ACC
sub_80A8ACC:
	push {r4,lr}
	sub sp, 0xC
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, 0
	blt _080A8B10
	cmp r3, 0
	blt _080A8B10
	ldr r1, _080A8B0C
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r4, r1, r0
	adds r0, r3, 0
	mov r1, sp
	bl sub_80ADC64
	lsls r0, 24
	cmp r0, 0
	beq _080A8B10
	adds r0, r4, 0
	movs r1, 0
	mov r2, sp
	bl _ExecutePlayerScript
	lsls r0, 24
	lsrs r0, 24
	b _080A8B12
	.align 2, 0
_080A8B0C: .4byte gUnknown_3001B84
_080A8B10:
	movs r0, 0
_080A8B12:
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8ACC

	thumb_func_start sub_80A8B1C
sub_80A8B1C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080A8B70
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080A8B36:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080A8B4E
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080A8B4E:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	cmp r0, 0x17
	ble _080A8B36
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A8B70: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8B1C

	thumb_func_start sub_80A8B74
sub_80A8B74:
	push {r4-r7,lr}
	ldr r0, _080A8BB8
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080A8B84:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080A8B9A
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080A8B9A:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	cmp r0, 0x17
	ble _080A8B84
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A8BB8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8B74

	thumb_func_start sub_80A8BBC
sub_80A8BBC:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8BD4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A8BD4: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8BBC

	thumb_func_start sub_80A8BD8
sub_80A8BD8:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080A8BF8
	lsls r2, r0, 5
	subs r2, r0
	lsls r2, 4
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A8BF8: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8BD8

	thumb_func_start sub_80A8BFC
sub_80A8BFC:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8C20
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8C24
	movs r0, 0
	b _080A8C28
	.align 2, 0
_080A8C20: .4byte gUnknown_3001B84
_080A8C24:
	movs r1, 0x8
	ldrsh r0, [r2, r1]
_080A8C28:
	pop {r1}
	bx r1
	thumb_func_end sub_80A8BFC

	thumb_func_start sub_80A8C2C
sub_80A8C2C:
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A7DDC
	movs r1, 0
	ldrsh r0, [r4, r1]
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C2C

	thumb_func_start sub_80A8C4C
sub_80A8C4C:
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8C80
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8C90
	adds r0, r1, 0
	bl sub_80A8D54
	adds r1, r0, 0
	cmp r1, 0
	beq _080A8C84
	ldr r0, [r1, 0x4]
	str r0, [r5]
	b _080A8C8A
	.align 2, 0
_080A8C80: .4byte gUnknown_3001B84
_080A8C84:
	movs r0, 0x63
	strb r0, [r5]
	strb r1, [r5, 0x1]
_080A8C8A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	b _080A8C92
_080A8C90:
	movs r0, 0
_080A8C92:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C4C

	thumb_func_start sub_80A8C98
sub_80A8C98:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8CD4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8CE8
	ldr r1, _080A8CD8
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _080A8CE8
	movs r0, 0x8
	ldrsh r3, [r3, r0]
_080A8CC6:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r3
	bne _080A8CDC
	movs r0, 0x1
	b _080A8CEA
	.align 2, 0
_080A8CD4: .4byte gUnknown_3001B84
_080A8CD8: .4byte gUnknown_8117FCE
_080A8CDC:
	adds r1, 0x2
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080A8CC6
_080A8CE8:
	movs r0, 0
_080A8CEA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8C98

	thumb_func_start sub_80A8CF0
sub_80A8CF0:
	push {r4,lr}
	lsls r0, 16
	asrs r3, r0, 16
	ldr r1, _080A8CFC
	b _080A8D0E
	.align 2, 0
_080A8CFC: .4byte gUnknown_8117FCE
_080A8D00:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r3
	bne _080A8D0C
	movs r0, 0x1
	b _080A8D1A
_080A8D0C:
	adds r1, 0x2
_080A8D0E:
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080A8D00
	movs r0, 0
_080A8D1A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8CF0

	thumb_func_start sub_80A8D20
sub_80A8D20:
	push {lr}
	movs r0, 0
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8D50
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x90
	lsls r1, 1
	adds r0, r1
	bl sub_809CDB8
	movs r1, 0
	cmp r0, 0x1
	bne _080A8D4A
	movs r1, 0x1
_080A8D4A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_080A8D50: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8D20

	thumb_func_start sub_80A8D54
sub_80A8D54:
	push {r4,r5,lr}
	sub sp, 0x14
	mov r1, sp
	strh r0, [r1]
	mov r0, sp
	bl sub_80A7B94
	mov r0, sp
	ldrh r1, [r0]
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	beq _080A8D76
	cmp r0, 0x6
	beq _080A8D76
	cmp r0, 0x21
	bne _080A8D7C
_080A8D76:
	bl sub_808D3BC
	b _080A8E94
_080A8D7C:
	cmp r0, 0x2
	beq _080A8D88
	cmp r0, 0x7
	beq _080A8D88
	cmp r0, 0x22
	bne _080A8D8E
_080A8D88:
	bl sub_808D3F8
	b _080A8E94
_080A8D8E:
	cmp r0, 0x3
	beq _080A8D9A
	cmp r0, 0x8
	beq _080A8D9A
	cmp r0, 0x23
	bne _080A8DA0
_080A8D9A:
	bl sub_808D33C
	b _080A8E94
_080A8DA0:
	adds r0, r1, 0
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _080A8DF8
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r5, r0, 0
	subs r5, 0xA
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _080A8E92
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8DD6
	add r4, sp, 0x4
	adds r0, r4, 0
	bl sub_808D6A4
	b _080A8DDE
_080A8DD6:
	add r4, sp, 0x4
	adds r0, r4, 0
	bl sub_808D654
_080A8DDE:
	cmp r5, r0
	bge _080A8E92
	ldr r2, _080A8DF4
	lsls r0, r5, 2
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	b _080A8E94
	.align 2, 0
_080A8DF4: .4byte gUnknown_203B45C
_080A8DF8:
	adds r0, r1, 0
	subs r0, 0xE
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080A8E92
	movs r0, 0
	movs r1, 0x10
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _080A8E92
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r5, r0, 0
	subs r5, 0xE
	add r4, sp, 0x4
	adds r0, r1, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r5, r0
	bge _080A8E92
	ldr r2, _080A8E6C
	ldr r0, [r4, 0x8]
	adds r0, r5
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A8E70
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A8E92
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A8E92
	adds r0, r4, 0
	b _080A8E94
	.align 2, 0
_080A8E6C: .4byte gUnknown_203B45C
_080A8E70:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A8E92
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080A8E92
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _080A8E8A
	movs r1, 0x1
_080A8E8A:
	cmp r1, 0
	bne _080A8E92
	adds r0, r4, 0
	b _080A8E94
_080A8E92:
	movs r0, 0
_080A8E94:
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A8D54

	thumb_func_start sub_80A8E9C
sub_80A8E9C:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8EBC
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	pop {r1}
	bx r1
	.align 2, 0
_080A8EBC: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8E9C

	thumb_func_start sub_80A8EC0
sub_80A8EC0:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	mov r0, sp
	strh r1, [r0]
	mov r5, sp
	adds r5, 0x2
	adds r1, r5, 0
	bl sub_80A7DDC
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	cmp r0, 0
	beq _080A8EF0
	adds r1, r0, 0
	adds r1, 0x4C
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	b _080A8F44
_080A8EF0:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x20
	bne _080A8F00
	movs r0, 0
	ldrsh r1, [r5, r0]
	b _080A8F34
_080A8F00:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A8F3C
	mov r0, sp
	movs r1, 0
	ldrsh r2, [r0, r1]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	ldr r1, _080A8F2C
	adds r0, r1
	cmp r2, 0x34
	beq _080A8F20
	cmp r2, 0x64
	bne _080A8F30
_080A8F20:
	ldr r1, [r0, 0x4]
	adds r0, r4, 0
	bl strcpy
	b _080A8F44
	.align 2, 0
_080A8F2C: .4byte gUnknown_811E63C
_080A8F30:
	movs r2, 0x2
	ldrsh r1, [r0, r2]
_080A8F34:
	adds r0, r4, 0
	bl sub_808D8BC
	b _080A8F44
_080A8F3C:
	ldr r1, _080A8F4C
	adds r0, r4, 0
	bl strcpy
_080A8F44:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8F4C: .4byte gUnknown_811825C
	thumb_func_end sub_80A8EC0

	thumb_func_start sub_80A8F50
sub_80A8F50:
	push {r4,r5,lr}
	sub sp, 0x80
	adds r4, r0, 0
	adds r5, r2, 0
	lsls r1, 16
	asrs r1, 16
	mov r0, sp
	bl sub_80A8EC0
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_8092310
	add sp, 0x80
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A8F50

	thumb_func_start sub_80A8F74
sub_80A8F74:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8F98
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r3, 0
	bl sub_80A8EC0
	pop {r0}
	bx r0
	.align 2, 0
_080A8F98: .4byte gUnknown_3001B84
	thumb_func_end sub_80A8F74

	thumb_func_start sub_80A8F9C
sub_80A8F9C:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A8FC4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A8FC8
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080A8FD0
	.align 2, 0
_080A8FC4: .4byte gUnknown_3001B84
_080A8FC8:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080A8FD0:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A8F9C

	thumb_func_start sub_80A8FD8
sub_80A8FD8:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A9000
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A9004
	movs r0, 0
	str r0, [r3]
	b _080A901E
	.align 2, 0
_080A9000: .4byte gUnknown_3001B84
_080A9004:
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080A901E:
	str r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A8FD8

	thumb_func_start sub_80A9028
sub_80A9028:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080A904C
	lsls r2, r0, 5
	subs r2, r0
	lsls r2, 4
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80A9F20
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A904C: .4byte gUnknown_3001B84
	thumb_func_end sub_80A9028

	thumb_func_start sub_80A9050
sub_80A9050:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A9078
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	adds r3, r0, 0
	cmp r1, r0
	bne _080A907C
	strb r3, [r4]
	b _080A9086
	.align 2, 0
_080A9078: .4byte gUnknown_3001B84
_080A907C:
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	strb r0, [r4]
_080A9086:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9050

	thumb_func_start sub_80A9090
sub_80A9090:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	asrs r3, r1, 24
	ldr r2, _080A90C4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A90BA
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r2, r1
	strb r3, [r0]
_080A90BA:
	movs r1, 0x2
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A90C4: .4byte gUnknown_3001B84
	thumb_func_end sub_80A9090

	thumb_func_start sub_80A90C8
sub_80A90C8:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080A90E4
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A90E4: .4byte gUnknown_3001B84
	thumb_func_end sub_80A90C8

	thumb_func_start sub_80A90E8
sub_80A90E8:
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, r3
	beq _080A9196
	ldr r1, _080A916C
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r5, r1, r0
	lsls r0, r3, 5
	subs r0, r3
	lsls r0, 4
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080A9196
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r1
	beq _080A9196
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [sp]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, r4, r3
	ldr r0, [r3]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp, 0x8]
	adds r2, r4, r2
	ldr r0, [r2]
	ldr r1, [r4, 0x18]
	adds r0, r1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0x24
	bgt _080A9170
	adds r1, r5, 0
	adds r1, 0xC
	adds r3, r4, 0
	adds r3, 0xC
	mov r0, sp
	bl sub_8002DF0
	b _080A917E
	.align 2, 0
_080A916C: .4byte gUnknown_3001B84
_080A9170:
	adds r1, r5, 0
	adds r1, 0xC
	adds r3, r4, 0
	adds r3, 0xC
	mov r0, sp
	bl sub_8002D54
_080A917E:
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A9196
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, 0x1
	b _080A9198
_080A9196:
	movs r0, 0
_080A9198:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A90E8

	thumb_func_start sub_80A91A0
sub_80A91A0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	asrs r2, r0, 16
	lsls r1, 16
	asrs r4, r1, 16
	cmp r2, r4
	beq _080A928E
	ldr r1, _080A9260
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r7, r1, r0
	lsls r0, r4, 5
	subs r0, r4
	lsls r0, 4
	adds r1, r0
	mov r8, r1
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	movs r2, 0x1
	negs r2, r2
	mov r10, r2
	cmp r0, r10
	beq _080A928E
	mov r3, r8
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r10
	beq _080A928E
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r1, [r7, 0x14]
	adds r0, r1
	str r0, [sp]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r7, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	add r3, r8
	ldr r0, [r3]
	mov r3, r8
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [sp, 0x8]
	add r2, r8
	ldr r0, [r2]
	ldr r1, [r3, 0x18]
	adds r0, r1
	add r4, sp, 0x8
	str r0, [r4, 0x4]
	adds r5, r7, 0
	adds r5, 0xC
	mov r6, r8
	adds r6, 0xC
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r0, 24
	mov r9, r0
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r1, r0, 24
	cmp r9, r10
	beq _080A928E
	cmp r1, r10
	beq _080A928E
	movs r2, 0x2
	ldrsh r0, [r7, r2]
	cmp r0, 0x24
	bgt _080A9264
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r7, r3
	mov r2, r9
	strb r2, [r0]
	b _080A926C
	.align 2, 0
_080A9260: .4byte gUnknown_3001B84
_080A9264:
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r7, r3
	strb r1, [r0]
_080A926C:
	mov r2, r8
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0x25
	bgt _080A927A
	mov r0, r9
	b _080A927C
_080A927A:
	adds r0, r1, 0
_080A927C:
	movs r1, 0x5
	bl sub_8002984
	movs r1, 0xA1
	lsls r1, 1
	add r1, r8
	strb r0, [r1]
	movs r0, 0x1
	b _080A9290
_080A928E:
	movs r0, 0
_080A9290:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A91A0

	thumb_func_start sub_80A92A0
sub_80A92A0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r1
	adds r4, r2, 0
	lsls r0, 16
	asrs r6, r0, 16
	ldr r0, _080A931C
	ldr r0, [r0]
	mov r12, r0
	movs r2, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r5, 0x80
	lsls r5, 9
_080A92C2:
	cmp r2, r6
	beq _080A9320
	mov r1, r12
	movs r7, 0x2
	ldrsh r0, [r1, r7]
	cmp r0, r8
	beq _080A9320
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	beq _080A9320
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bge _080A9320
	movs r0, 0xA6
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	ble _080A9320
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bge _080A9320
	movs r0, 0xA8
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080A9320
	adds r0, r2, 0
	b _080A9338
	.align 2, 0
_080A931C: .4byte gUnknown_3001B84
_080A9320:
	adds r0, r5, 0
	movs r7, 0x80
	lsls r7, 9
	adds r5, r7
	asrs r2, r0, 16
	movs r0, 0xF8
	lsls r0, 1
	add r12, r0
	cmp r2, 0x17
	ble _080A92C2
	movs r0, 0x1
	negs r0, r0
_080A9338:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A92A0

	thumb_func_start sub_80A9344
sub_80A9344:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r1
	str r2, [sp]
	adds r5, r3, 0
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	ldr r0, _080A93C4
	ldr r0, [r0]
	mov r12, r0
	movs r4, 0
	movs r0, 0x1
	negs r0, r0
	mov r10, r0
	movs r7, 0x80
	lsls r7, 9
_080A936E:
	cmp r4, r8
	beq _080A93C8
	mov r1, r12
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	cmp r0, r10
	beq _080A93C8
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r6, r9
	ands r0, r6
	cmp r0, 0
	beq _080A93C8
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	mov r6, r12
	ldr r0, [r6, 0x14]
	adds r2, r1, r0
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r6, 0x18]
	adds r3, r1, r0
	ldr r0, [r5]
	cmp r2, r0
	bge _080A93C8
	ldr r1, [sp]
	ldr r0, [r1]
	cmp r2, r0
	ble _080A93C8
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _080A93C8
	ldr r0, [r1, 0x4]
	cmp r3, r0
	ble _080A93C8
	adds r0, r4, 0
	b _080A93E0
	.align 2, 0
_080A93C4: .4byte gUnknown_3001B84
_080A93C8:
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 9
	adds r7, r2
	asrs r4, r0, 16
	movs r6, 0xF8
	lsls r6, 1
	add r12, r6
	cmp r4, 0x17
	ble _080A936E
	movs r0, 0x1
	negs r0, r0
_080A93E0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9344

	thumb_func_start sub_80A93F0
sub_80A93F0:
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r2, _080A947C
	lsls r1, r0, 5
	subs r1, r0
	lsls r1, 4
	ldr r0, [r2]
	adds r0, r1
	mov r12, r0
	movs r0, 0xA2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bge _080A941A
	ldr r1, _080A9480
	adds r0, r1
_080A941A:
	asrs r5, r0, 11
	str r5, [sp]
	movs r0, 0xA4
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bge _080A942E
	ldr r7, _080A9480
	adds r0, r7
_080A942E:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	subs r1, r0, 0x1
	cmp r1, 0
	bge _080A9444
	ldr r7, _080A9484
	adds r1, r0, r7
_080A9444:
	asrs r2, r1, 11
	movs r0, 0xA8
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	subs r1, r0, 0x1
	cmp r1, 0
	bge _080A9458
	ldr r7, _080A9484
	adds r1, r0, r7
_080A9458:
	asrs r3, r1, 11
	subs r0, r2, r5
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r3, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	adds r0, r6, 0
	mov r1, sp
	bl sub_80A5934
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A947C: .4byte gUnknown_3001B84
_080A9480: .4byte 0x000007ff
_080A9484: .4byte 0x000007fe
	thumb_func_end sub_80A93F0

	thumb_func_start sub_80A9488
sub_80A9488:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	ldr r0, [r7]
	cmp r0, 0
	bge _080A94A0
	ldr r1, _080A9528
	adds r0, r1
_080A94A0:
	asrs r0, 11
	mov r12, r0
	str r0, [sp]
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080A94B0
	ldr r3, _080A9528
	adds r0, r3
_080A94B0:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	mov r6, r8
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A94C2
	ldr r6, _080A952C
	adds r0, r3, r6
_080A94C2:
	asrs r1, r0, 11
	mov r0, r8
	ldr r3, [r0, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A94D2
	ldr r6, _080A952C
	adds r0, r3, r6
_080A94D2:
	asrs r2, r0, 11
	mov r3, r12
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _080A9504
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A585C
	lsls r0, 24
	cmp r0, 0
	bne _080A9522
_080A9504:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A9530
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A58C8
	lsls r0, 24
	cmp r0, 0
	beq _080A9530
_080A9522:
	movs r0, 0x1
	b _080A95A0
	.align 2, 0
_080A9528: .4byte 0x000007ff
_080A952C: .4byte 0x000007fe
_080A9530:
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A9556
	movs r6, 0
	ldrsh r0, [r5, r6]
	adds r2, r7, 0
	mov r3, r8
	bl sub_80A92A0
	lsls r0, 16
	cmp r0, 0
	blt _080A9556
	movs r0, 0x4
	b _080A95A0
_080A9556:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A957A
	movs r0, 0x4
	adds r1, r7, 0
	mov r2, r8
	bl sub_80AC4C8
	lsls r0, 16
	cmp r0, 0
	blt _080A957A
	movs r0, 0x8
	b _080A95A0
_080A957A:
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A959E
	movs r0, 0x40
	adds r1, r7, 0
	mov r2, r8
	bl sub_80ADCA0
	lsls r0, 16
	cmp r0, 0
	blt _080A959E
	movs r0, 0x10
	b _080A95A0
_080A959E:
	movs r0, 0
_080A95A0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9488

	thumb_func_start sub_80A95AC
sub_80A95AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r5, r0, 0
	adds r7, r1, 0
	mov r8, r2
	ldr r0, [r7]
	cmp r0, 0
	bge _080A95C6
	ldr r1, _080A96BC
	adds r0, r1
_080A95C6:
	asrs r0, 11
	mov r9, r0
	str r0, [sp]
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080A95D6
	ldr r2, _080A96BC
	adds r0, r2
_080A95D6:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	mov r6, r8
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A95E8
	ldr r6, _080A96C0
	adds r0, r3, r6
_080A95E8:
	asrs r1, r0, 11
	mov r0, r8
	ldr r3, [r0, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080A95F8
	ldr r6, _080A96C0
	adds r0, r3, r6
_080A95F8:
	asrs r2, r0, 11
	mov r3, r9
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _080A962C
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A585C
	lsls r0, 24
	cmp r0, 0
	beq _080A962C
	b _080A973C
_080A962C:
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A964A
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A58C8
	lsls r0, 24
	cmp r0, 0
	bne _080A973C
_080A964A:
	movs r4, 0x8E
	lsls r4, 1
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080A96C8
	movs r2, 0
	ldrsh r0, [r5, r2]
	movs r1, 0x44
	adds r2, r7, 0
	mov r3, r8
	bl sub_80A92A0
	lsls r0, 16
	asrs r2, r0, 16
	mov r9, r2
	cmp r2, 0
	blt _080A96C8
	ldr r1, _080A96C4
	lsls r0, r2, 5
	subs r0, r2
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r6, r4
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080A973C
	movs r0, 0x80
	lsls r0, 2
	ands r1, r0
	cmp r1, 0
	beq _080A96A8
	adds r4, 0x26
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r4, r6, r4
	strb r0, [r4]
_080A96A8:
	movs r3, 0
	ldrsh r0, [r5, r3]
	mov r1, r9
	bl GroundLives_ExecutePlayerScriptActionLives
_080A96B2:
	lsls r0, 24
	cmp r0, 0
	bne _080A9738
	b _080A973C
	.align 2, 0
_080A96BC: .4byte 0x000007ff
_080A96C0: .4byte 0x000007fe
_080A96C4: .4byte gUnknown_3001B84
_080A96C8:
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A9708
	movs r0, 0x44
	adds r1, r7, 0
	mov r2, r8
	bl sub_80AC4C8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080A9708
	add r1, sp, 0x10
	adds r0, r4, 0
	bl sub_80AC3E0
	ldr r0, [sp, 0x10]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080A973C
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	bl sub_80A8A5C
	b _080A96B2
_080A9708:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080A9740
	movs r0, 0x40
	adds r1, r7, 0
	mov r2, r8
	bl sub_80ADCA0
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080A9740
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl sub_80A8ACC
	lsls r0, 24
	cmp r0, 0
	beq _080A973C
_080A9738:
	movs r0, 0x2
	b _080A9742
_080A973C:
	movs r0, 0x1
	b _080A9742
_080A9740:
	movs r0, 0
_080A9742:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A95AC

	thumb_func_start sub_80A9750
sub_80A9750:
	push {r4,lr}
	mov r12, r0
	lsls r1, 16
	lsrs r1, 16
	adds r4, r1, 0
	movs r3, 0xFF
	ands r3, r1
	movs r2, 0xF0
	lsls r2, 4
	ands r2, r1
	cmp r3, 0
	beq _080A9770
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	strh r3, [r0]
_080A9770:
	cmp r2, 0
	beq _080A977C
	movs r0, 0xAF
	lsls r0, 1
	add r0, r12
	strh r2, [r0]
_080A977C:
	movs r2, 0xB0
	lsls r2, 1
	add r2, r12
	ldrh r0, [r2]
	cmp r0, 0x1
	bne _080A97A8
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	beq _080A97B6
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r2, _080A97A4
	cmp r0, 0
	bgt _080A97A0
	b _080A9E98
_080A97A0:
	b _080A97C0
	.align 2, 0
_080A97A4: .4byte 0x00000807
_080A97A8:
	cmp r0, 0x2
	beq _080A97AE
	b _080A9E8C
_080A97AE:
	movs r0, 0x80
	lsls r0, 5
	cmp r4, r0
	bne _080A97C6
_080A97B6:
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
_080A97C0:
	movs r2, 0x80
	lsls r2, 4
	b _080A9E98
_080A97C6:
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	cmp r0, 0
	bgt _080A97C0
	mov r1, r12
	ldrh r0, [r1, 0x8]
	subs r0, 0xC
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _080A97F0
	cmp r1, r0
	bls _080A97E4
	b _080A9E7E
_080A97E4:
	lsls r0, r1, 2
	ldr r1, _080A97F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A97F0: .4byte 0x00000197
_080A97F4: .4byte _080A97F8
	.align 2, 0
_080A97F8:
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E68
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E60
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E60
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E7E
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
	.4byte _080A9E58
_080A9E58:
	ldr r2, _080A9E5C
	b _080A9E98
	.align 2, 0
_080A9E5C: .4byte 0x00000807
_080A9E60:
	ldr r2, _080A9E64
	b _080A9E98
	.align 2, 0
_080A9E64: .4byte 0x00000307
_080A9E68:
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r2, _080A9E84
	cmp r1, r2
	beq _080A9E98
	ldr r0, _080A9E88
	cmp r1, r0
	beq _080A9E98
_080A9E7E:
	movs r2, 0xC0
	lsls r2, 2
	b _080A9E98
	.align 2, 0
_080A9E84: .4byte 0x00000807
_080A9E88: .4byte 0x00000307
_080A9E8C:
	ldr r1, _080A9EC4
	ldrh r0, [r2]
	lsls r0, 1
	adds r0, r1
	movs r4, 0
	ldrsh r2, [r0, r4]
_080A9E98:
	movs r0, 0xE0
	lsls r0, 3
	ands r0, r2
	cmp r0, 0
	bne _080A9EEE
	movs r0, 0xAF
	lsls r0, 1
	add r0, r12
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _080A9EEE
	cmp r1, r0
	bgt _080A9EC8
	movs r3, 0x80
	lsls r3, 1
	cmp r1, r3
	beq _080A9EDA
	movs r0, 0x80
	lsls r0, 2
	b _080A9ED4
	.align 2, 0
_080A9EC4: .4byte gUnknown_8117F64
_080A9EC8:
	movs r3, 0x80
	lsls r3, 3
	cmp r1, r3
	beq _080A9EDE
	movs r0, 0x80
	lsls r0, 4
_080A9ED4:
	cmp r1, r0
	beq _080A9EEC
	b _080A9EEE
_080A9EDA:
	orrs r2, r0
	b _080A9EEE
_080A9EDE:
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1, 0
	orrs r2, r0
	lsls r0, r2, 16
	asrs r2, r0, 16
	b _080A9EEE
_080A9EEC:
	orrs r2, r3
_080A9EEE:
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldrh r3, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	beq _080A9F02
	strh r2, [r1]
	b _080A9F0C
_080A9F02:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r3
	cmp r0, 0
	beq _080A9F16
_080A9F0C:
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x1
	strb r0, [r1]
_080A9F16:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9750

	thumb_func_start sub_80A9F20
sub_80A9F20:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r2, [r1]
	ldr r4, [r5, 0x14]
	subs r0, r2, r4
	str r0, [sp]
	ldr r3, [r1, 0x4]
	ldr r1, [r5, 0x18]
	subs r0, r3, r1
	str r0, [sp, 0x4]
	adds r2, r4
	str r2, [sp, 0x8]
	adds r3, r1
	add r2, sp, 0x8
	str r3, [r2, 0x4]
	ldr r1, [r5, 0x28]
	ldr r0, [sp]
	cmp r0, r1
	blt _080A9F5E
	ldr r1, [r5, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	bge _080A9F5E
	ldr r1, [r5, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	blt _080A9F5E
	ldr r0, [r5, 0x34]
	cmp r3, r0
	blt _080A9F62
_080A9F5E:
	movs r0, 0x1
	b _080A9F8C
_080A9F62:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80A9488
	cmp r0, 0
	bne _080A9F8C
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
_080A9F8C:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9F20

	thumb_func_start sub_80A9F94
sub_80A9F94:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0xA8
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	movs r6, 0
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r2, r1, 0
	cmp r0, r3
	bge _080A9FE4
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080A9FF4
_080A9FE4:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080A9FF6
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080A9FF4:
	movs r6, 0x1
_080A9FF6:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AA008
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r2, 0x4]
	b _080AA018
_080AA008:
	ldr r1, [r4, 0x34]
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA01A
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r2, 0x4]
_080AA018:
	movs r6, 0x1
_080AA01A:
	adds r0, r4, 0
	mov r1, sp
	bl sub_80A9488
	adds r5, r0, 0
	cmp r5, 0
	beq _080AA034
	adds r0, r4, 0
	movs r1, 0
	bl sub_80AAF68
	adds r0, r5, 0
	b _080AA06A
_080AA034:
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r6, 0
	bne _080AA060
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80AAF68
	movs r0, 0
	b _080AA06A
_080AA060:
	adds r0, r4, 0
	movs r1, 0
	bl sub_80AAF68
	movs r0, 0x1
_080AA06A:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A9F94

	thumb_func_start sub_80AA074
sub_80AA074:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0xA8
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r5, r1, 0
	cmp r0, r3
	bge _080AA0C2
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080AA0D2
_080AA0C2:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AA0D2
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080AA0D2:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AA0E4
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r5, 0x4]
	b _080AA0F4
_080AA0E4:
	ldr r1, [r4, 0x34]
	ldr r0, [r5, 0x4]
	cmp r0, r1
	blt _080AA0F4
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r5, 0x4]
_080AA0F4:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_80A95AC
	adds r6, r0, 0
	cmp r6, 0
	bne _080AA170
	movs r3, 0xA2
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080AA170
	movs r0, 0x20
	mov r1, sp
	adds r2, r5, 0
	bl sub_80ADCA0
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	blt _080AA166
	movs r2, 0x9F
	lsls r2, 1
	adds r7, r4, r2
	movs r3, 0
	ldrsh r0, [r7, r3]
	cmp r0, r5
	beq _080AA170
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	bl sub_80A8ACC
	lsls r0, 24
	cmp r0, 0
	beq _080AA170
	strh r5, [r7]
	movs r6, 0x2
	b _080AA170
_080AA166:
	movs r2, 0x9F
	lsls r2, 1
	adds r1, r4, r2
	ldr r0, _080AA17C
	strh r0, [r1]
_080AA170:
	adds r0, r6, 0
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AA17C: .4byte 0x0000ffff
	thumb_func_end sub_80AA074

	thumb_func_start sub_80AA180
sub_80AA180:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _080AA220
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	bl sub_80A9344
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080AA220
	mov r1, sp
	bl sub_80A8FD8
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, [r0]
	ldr r0, [r4, 0x14]
	adds r1, r0
	ldr r0, [sp]
	subs r0, r1
	str r0, [sp, 0x8]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r4, 0x18]
	adds r0, r1
	ldr r1, [sp, 0x4]
	subs r1, r0
	add r0, sp, 0x8
	str r1, [r0, 0x4]
	bl sub_8002C60
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AA2B2
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r4, r0
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r3, _080AA21C
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AA20A
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AA20A:
	movs r1, 0
	ldrsb r1, [r2, r1]
	adds r0, r4, 0
	bl sub_80AA3F8
	lsls r0, 24
	cmp r0, 0
	bne _080AA2AE
	b _080AA2B2
	.align 2, 0
_080AA21C: .4byte 0x0000015d
_080AA220:
	movs r0, 0x8
	ands r0, r5
	cmp r0, 0
	beq _080AA2B2
	movs r0, 0x80
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_80AC554
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080AA2B2
	mov r1, sp
	bl sub_80AC448
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r4, 0x14]
	adds r1, r0
	ldr r0, [sp]
	subs r0, r1
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r4, r2
	ldr r2, [r1]
	ldr r1, [r4, 0x18]
	adds r2, r1
	ldr r1, [sp, 0x4]
	subs r1, r2
	str r1, [r0, 0x4]
	bl sub_8002C60
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AA2B2
	movs r3, 0xA1
	lsls r3, 1
	adds r2, r4, r3
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	adds r3, 0x1B
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AA29E
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AA29E:
	movs r1, 0
	ldrsb r1, [r2, r1]
	adds r0, r4, 0
	bl sub_80AA3F8
	lsls r0, 24
	cmp r0, 0
	beq _080AA2B2
_080AA2AE:
	movs r0, 0x3
	b _080AA2B4
_080AA2B2:
	movs r0, 0
_080AA2B4:
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA180

	thumb_func_start sub_80AA2BC
sub_80AA2BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r7, r0, 0
	mov r8, r1
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp]
	cmp r0, 0
	bge _080AA2E6
	ldr r1, _080AA3C4
	adds r0, r1
_080AA2E6:
	asrs r0, 11
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _080AA2F4
	ldr r2, _080AA3C4
	adds r0, r2
_080AA2F4:
	asrs r0, 11
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r4, [sp, 0x10]
	subs r0, r4, 0x1
	mov r10, r1
	cmp r0, 0
	bge _080AA308
	ldr r1, _080AA3C8
	adds r0, r4, r1
_080AA308:
	asrs r2, r0, 11
	add r0, sp, 0x10
	ldr r4, [r0, 0x4]
	subs r1, r4, 0x1
	mov r9, r0
	cmp r1, 0
	bge _080AA31A
	ldr r0, _080AA3C8
	adds r1, r4, r0
_080AA31A:
	asrs r3, r1, 11
	ldr r0, [sp, 0x8]
	subs r0, r2, r0
	adds r0, 0x1
	str r0, [sp, 0x18]
	mov r1, r10
	ldr r0, [r1, 0x4]
	subs r0, r3, r0
	adds r0, 0x1
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0x4
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	beq _080AA394
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r1, 0x80
	mov r2, sp
	mov r3, r9
	bl sub_80A92A0
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	blt _080AA394
	ldr r1, _080AA3CC
	lsls r0, r5, 5
	subs r0, r5
	lsls r0, 4
	ldr r1, [r1]
	adds r6, r1, r0
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _080AA384
	movs r4, 0xA1
	lsls r4, 1
	adds r0, r7, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r4, r6, r4
	strb r0, [r4]
_080AA384:
	movs r1, 0
	ldrsh r0, [r7, r1]
	adds r1, r5, 0
	bl GroundLives_ExecutePlayerScriptActionLives
	lsls r0, 24
	cmp r0, 0
	bne _080AA3BE
_080AA394:
	movs r0, 0x8
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	beq _080AA3D0
	movs r0, 0x80
	mov r1, sp
	mov r2, r9
	bl sub_80AC4C8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080AA3D0
	movs r2, 0
	ldrsh r0, [r7, r2]
	bl sub_80A8A5C
	lsls r0, 24
	cmp r0, 0
	beq _080AA3D0
_080AA3BE:
	movs r0, 0x3
	b _080AA3E6
	.align 2, 0
_080AA3C4: .4byte 0x000007ff
_080AA3C8: .4byte 0x000007fe
_080AA3CC: .4byte gUnknown_3001B84
_080AA3D0:
	movs r0, 0x10
	mov r1, r10
	add r2, sp, 0x18
	bl sub_80A595C
	lsls r0, 24
	cmp r0, 0
	bne _080AA3E4
	movs r0, 0
	b _080AA3E6
_080AA3E4:
	movs r0, 0x6
_080AA3E6:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA2BC

	thumb_func_start sub_80AA3F8
sub_80AA3F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r1, 24
	asrs r1, 24
	str r1, [sp, 0x28]
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl sub_8002BB8
	ldr r4, [sp]
	ldr r5, [sp, 0x4]
	movs r0, 0xA2
	lsls r0, 1
	adds r0, r6
	mov r9, r0
	ldr r0, [r0]
	adds r0, r4
	str r0, [sp, 0x8]
	movs r1, 0xA4
	lsls r1, 1
	adds r1, r6
	mov r10, r1
	ldr r0, [r1]
	adds r0, r5
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, r4
	str r0, [sp, 0x10]
	adds r1, 0x4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, r5
	add r3, sp, 0x10
	str r0, [r3, 0x4]
	adds r0, r6, 0
	movs r1, 0xC
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA462
_080AA45E:
	movs r0, 0x1
	b _080AA650
_080AA462:
	ldr r0, [r6, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r2, 0x80
	lsls r2, 2
	mov r8, r2
	add r0, r8
	muls r0, r4
	cmp r0, 0
	bge _080AA47A
	adds r0, 0xFF
_080AA47A:
	asrs r0, 8
	str r0, [sp, 0x2C]
	ldr r0, [r6, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r8
	muls r0, r5
	cmp r0, 0
	bge _080AA490
	adds r0, 0xFF
_080AA490:
	asrs r0, 8
	str r0, [sp, 0x30]
	mov r1, r9
	ldr r0, [r1]
	ldr r1, [r6, 0x14]
	adds r0, r1
	ldr r2, [sp, 0x2C]
	adds r0, r2
	ldr r2, _080AA4F4
	adds r0, r2
	str r0, [sp, 0x18]
	mov r1, r10
	ldr r0, [r1]
	ldr r1, [r6, 0x18]
	adds r0, r1
	ldr r1, [sp, 0x30]
	adds r0, r1
	adds r0, r2
	add r2, sp, 0x18
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0x18]
	adds r0, r1
	str r0, [sp, 0x20]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x20
	str r0, [r3, 0x4]
	ldr r0, _080AA4F8
	mov r9, r0
	ldr r0, [sp, 0x28]
	lsls r1, r0, 2
	add r9, r1
	mov r0, r9
	ldr r0, [r0]
	str r0, [sp, 0x34]
	ldr r0, _080AA4FC
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, 0x38]
	ldr r0, _080AA500
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x3C]
	mov r10, r8
	mov r9, r2
	mov r8, r3
	b _080AA568
	.align 2, 0
_080AA4F4: .4byte 0xfffffd00
_080AA4F8: .4byte gUnknown_8117FF0
_080AA4FC: .4byte gUnknown_8118010
_080AA500: .4byte gUnknown_8118030
_080AA504:
	ldr r1, [r6, 0x28]
	ldr r0, [sp, 0x18]
	cmp r0, r1
	bge _080AA50E
	b _080AA64E
_080AA50E:
	ldr r1, [r6, 0x30]
	ldr r0, [sp, 0x20]
	cmp r0, r1
	blt _080AA518
	b _080AA64E
_080AA518:
	ldr r1, [r6, 0x2C]
	mov r2, r9
	ldr r0, [r2, 0x4]
	cmp r0, r1
	bge _080AA524
	b _080AA64E
_080AA524:
	ldr r1, [r6, 0x34]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA530
	b _080AA64E
_080AA530:
	adds r0, r6, 0
	movs r1, 0xC
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	beq _080AA45E
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	cmp r7, 0x6
	beq _080AA572
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
_080AA568:
	ldr r1, [sp, 0x34]
	cmp r10, r1
	blt _080AA504
	cmp r7, 0x6
	bne _080AA64E
_080AA572:
	ldr r2, [sp, 0x38]
	cmp r10, r2
	bge _080AA5DC
_080AA578:
	ldr r1, [sp, 0x18]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AA64E
	ldr r1, [sp, 0x20]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AA64E
	mov r0, r9
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AA64E
	mov r2, r8
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AA64E
	adds r0, r6, 0
	movs r1, 0x4
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA5B0
	b _080AA45E
_080AA5B0:
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	cmp r7, 0x6
	bne _080AA5E0
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
	ldr r1, [sp, 0x38]
	cmp r10, r1
	blt _080AA578
_080AA5DC:
	cmp r7, 0x6
	beq _080AA64E
_080AA5E0:
	movs r2, 0
	mov r10, r2
	ldr r0, [sp, 0x3C]
	cmp r10, r0
	bge _080AA64E
_080AA5EA:
	ldr r1, [sp, 0x18]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AA64E
	ldr r1, [sp, 0x20]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AA64E
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AA64E
	mov r0, r8
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AA64E
	adds r0, r6, 0
	movs r1, 0x4
	mov r2, r9
	mov r3, r8
	bl sub_80AA2BC
	adds r7, r0, 0
	cmp r7, 0x3
	bne _080AA622
	b _080AA45E
_080AA622:
	cmp r7, 0x6
	beq _080AA64E
	ldr r0, [sp, 0x18]
	adds r0, r4
	str r0, [sp, 0x18]
	mov r1, r9
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x20]
	adds r0, r4
	str r0, [sp, 0x20]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	movs r0, 0x80
	lsls r0, 1
	add r10, r0
	ldr r1, [sp, 0x3C]
	cmp r10, r1
	blt _080AA5EA
_080AA64E:
	movs r0, 0
_080AA650:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA3F8

	thumb_func_start sub_80AA660
sub_80AA660:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 1
	bl sub_80AC4C8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _080AA686
	movs r2, 0
	ldrsh r0, [r4, r2]
	bl sub_80A8A5C
	lsls r0, 24
	cmp r0, 0
	beq _080AA686
	movs r0, 0x4
	b _080AA688
_080AA686:
	movs r0, 0
_080AA688:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA660

	thumb_func_start sub_80AA690
sub_80AA690:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r7, r0, 0
	lsls r1, 24
	asrs r1, 24
	mov r9, r1
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl sub_8002BB8
	ldr r5, [sp]
	ldr r6, [sp, 0x4]
	ldr r0, [r7, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x80
	lsls r1, 2
	mov r8, r1
	add r0, r8
	muls r0, r5
	cmp r0, 0
	bge _080AA6CA
	adds r0, 0xFF
_080AA6CA:
	asrs r3, r0, 8
	ldr r0, [r7, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r8
	muls r0, r6
	cmp r0, 0
	bge _080AA6DE
	adds r0, 0xFF
_080AA6DE:
	asrs r4, r0, 8
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r7, 0x14]
	adds r0, r1
	adds r0, r3
	ldr r2, _080AA76C
	adds r0, r2
	str r0, [sp, 0x8]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r7, 0x18]
	adds r0, r1
	adds r0, r4
	adds r0, r2
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x10]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x10
	str r0, [r3, 0x4]
	ldr r1, _080AA770
	mov r4, r9
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	mov r10, r0
	mov r9, r8
	mov r8, r2
	adds r4, r3, 0
	cmp r9, r10
	bge _080AA79C
_080AA730:
	ldr r1, [r7, 0x28]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AA79C
	ldr r1, [r7, 0x30]
	ldr r0, [sp, 0x10]
	cmp r0, r1
	bge _080AA79C
	ldr r1, [r7, 0x2C]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AA79C
	ldr r1, [r7, 0x34]
	ldr r0, [r4, 0x4]
	cmp r0, r1
	bge _080AA79C
	adds r0, r7, 0
	mov r1, r8
	adds r2, r4, 0
	bl sub_80AA660
	cmp r0, 0x4
	beq _080AA774
	cmp r0, 0x4
	bhi _080AA778
	cmp r0, 0
	bne _080AA778
	b _080AA79C
	.align 2, 0
_080AA76C: .4byte 0xfffffd00
_080AA770: .4byte gUnknown_8117FF0
_080AA774:
	movs r0, 0x1
	b _080AA79E
_080AA778:
	ldr r0, [sp, 0x8]
	adds r0, r5
	str r0, [sp, 0x8]
	mov r1, r8
	ldr r0, [r1, 0x4]
	adds r0, r6
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x10]
	adds r0, r5
	str r0, [sp, 0x10]
	ldr r0, [r4, 0x4]
	adds r0, r6
	str r0, [r4, 0x4]
	movs r2, 0x80
	lsls r2, 1
	add r9, r2
	cmp r9, r10
	blt _080AA730
_080AA79C:
	movs r0, 0
_080AA79E:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA690

	thumb_func_start sub_80AA7B0
sub_80AA7B0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	adds r7, r0, 0
	adds r6, r1, 0
	mov r12, r2
	ldr r2, [sp, 0x38]
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp]
	cmp r0, 0
	bge _080AA7DA
	ldr r1, _080AA884
	adds r0, r1
_080AA7DA:
	asrs r0, 11
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _080AA7E8
	ldr r2, _080AA884
	adds r0, r2
_080AA7E8:
	asrs r0, 11
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	ldr r4, [sp, 0x10]
	subs r0, r4, 0x1
	mov r8, r1
	cmp r0, 0
	bge _080AA7FC
	ldr r5, _080AA888
	adds r0, r4, r5
_080AA7FC:
	asrs r2, r0, 11
	add r4, sp, 0x10
	ldr r1, [r4, 0x4]
	subs r0, r1, 0x1
	cmp r0, 0
	bge _080AA80C
	ldr r5, _080AA888
	adds r0, r1, r5
_080AA80C:
	asrs r3, r0, 11
	ldr r0, [sp, 0x8]
	subs r0, r2, r0
	adds r0, 0x1
	str r0, [sp, 0x18]
	mov r1, r8
	ldr r0, [r1, 0x4]
	subs r0, r3, r0
	adds r0, 0x1
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0x4
	mov r2, r12
	ands r0, r2
	adds r5, r1, 0
	cmp r0, 0
	beq _080AA890
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r1, 0x80
	mov r2, sp
	adds r3, r4, 0
	bl sub_80A92A0
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080AA890
	adds r0, r4, 0
	bl sub_80A8BBC
	lsls r0, 16
	ldr r2, _080AA88C
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0xF
	bhi _080AA890
	adds r0, r4, 0
	bl sub_80A8E9C
	cmp r0, 0
	beq _080AA890
	strh r4, [r6]
	movs r5, 0xA1
	lsls r5, 1
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x5
	bl sub_8002984
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl sub_80A9090
	movs r0, 0x5
	b _080AA8AE
	.align 2, 0
_080AA884: .4byte 0x000007ff
_080AA888: .4byte 0x000007fe
_080AA88C: .4byte 0xfff20000
_080AA890:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r6]
	movs r0, 0x10
	mov r1, r8
	adds r2, r5, 0
	bl sub_80A595C
	lsls r0, 24
	cmp r0, 0
	bne _080AA8AC
	movs r0, 0
	b _080AA8AE
_080AA8AC:
	movs r0, 0x6
_080AA8AE:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA7B0

	thumb_func_start sub_80AA8BC
sub_80AA8BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r6, r0, 0
	str r1, [sp, 0x1C]
	lsls r2, 24
	asrs r2, 24
	mov r8, r2
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x4
	mov r1, r8
	bl sub_8002BB8
	ldr r4, [sp, 0x4]
	ldr r5, [sp, 0x8]
	ldr r0, [r6, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0x80
	lsls r1, 2
	mov r9, r1
	add r0, r9
	muls r0, r4
	cmp r0, 0
	bge _080AA8FA
	adds r0, 0xFF
_080AA8FA:
	asrs r0, 8
	str r0, [sp, 0x20]
	ldr r0, [r6, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	add r0, r9
	muls r0, r5
	cmp r0, 0
	bge _080AA910
	adds r0, 0xFF
_080AA910:
	asrs r0, 8
	str r0, [sp, 0x24]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	ldr r0, [r0]
	ldr r1, [r6, 0x14]
	adds r0, r1
	ldr r7, [sp, 0x20]
	adds r0, r7
	ldr r2, _080AA9F0
	adds r0, r2
	str r0, [sp, 0xC]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, [r6, 0x18]
	adds r0, r1
	ldr r7, [sp, 0x24]
	adds r0, r7
	adds r0, r2
	add r2, sp, 0xC
	str r0, [r2, 0x4]
	movs r1, 0xC0
	lsls r1, 3
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0x14]
	ldr r0, [r2, 0x4]
	adds r0, r1
	add r3, sp, 0x14
	str r0, [r3, 0x4]
	ldr r0, _080AA9F4
	mov r7, r8
	lsls r1, r7, 2
	adds r0, r1, r0
	ldr r0, [r0]
	mov r10, r0
	ldr r0, _080AA9F8
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, 0x28]
	ldr r0, _080AA9FC
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x2C]
	movs r1, 0
	movs r7, 0x1
	negs r7, r7
	adds r0, r7, 0
	ldr r7, [sp, 0x1C]
	strh r0, [r7]
	mov r8, r2
	adds r7, r3, 0
	cmp r9, r10
	bge _080AA9E8
_080AA982:
	ldr r1, [r6, 0x28]
	ldr r0, [sp, 0xC]
	cmp r0, r1
	bge _080AA98C
	b _080AAAD4
_080AA98C:
	ldr r1, [r6, 0x30]
	ldr r0, [sp, 0x14]
	cmp r0, r1
	blt _080AA996
	b _080AAAD4
_080AA996:
	ldr r1, [r6, 0x2C]
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, r1
	bge _080AA9A2
	b _080AAAD4
_080AA9A2:
	ldr r1, [r6, 0x34]
	ldr r0, [r7, 0x4]
	cmp r0, r1
	blt _080AA9AC
	b _080AAAD4
_080AA9AC:
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0xC
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	cmp r1, 0x6
	beq _080AAA5A
	movs r0, 0x80
	lsls r0, 1
	add r9, r0
	cmp r9, r10
	blt _080AA982
_080AA9E8:
	cmp r1, 0x6
	bne _080AAAD4
	b _080AAA5A
	.align 2, 0
_080AA9F0: .4byte 0xfffffd00
_080AA9F4: .4byte gUnknown_8117FF0
_080AA9F8: .4byte gUnknown_8118010
_080AA9FC: .4byte gUnknown_8118030
_080AAA00:
	ldr r1, [sp, 0xC]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [sp, 0x14]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AAAD4
	mov r0, r8
	ldr r1, [r0, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [r7, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AAAD4
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0x4
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r5
	str r0, [r2, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	cmp r1, 0x6
	bne _080AAA6A
	movs r0, 0x80
	lsls r0, 1
	add r9, r0
_080AAA5A:
	ldr r2, [sp, 0x28]
	cmp r9, r2
	blt _080AAA00
	cmp r1, 0x6
	bne _080AAA6A
	b _080AAAD4
_080AAA66:
	movs r0, 0x1
	b _080AAAD6
_080AAA6A:
	movs r0, 0
	mov r9, r0
	ldr r1, [sp, 0x2C]
	cmp r9, r1
	bge _080AAAD4
_080AAA74:
	ldr r1, [sp, 0xC]
	ldr r0, [r6, 0x28]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [sp, 0x14]
	ldr r0, [r6, 0x30]
	cmp r1, r0
	bge _080AAAD4
	mov r2, r8
	ldr r1, [r2, 0x4]
	ldr r0, [r6, 0x2C]
	cmp r1, r0
	blt _080AAAD4
	ldr r1, [r7, 0x4]
	ldr r0, [r6, 0x34]
	cmp r1, r0
	bge _080AAAD4
	str r7, [sp]
	adds r0, r6, 0
	ldr r1, [sp, 0x1C]
	movs r2, 0x4
	mov r3, r8
	bl sub_80AA7B0
	adds r1, r0, 0
	cmp r1, 0x5
	beq _080AAA66
	cmp r1, 0x6
	beq _080AAAD4
	ldr r0, [sp, 0xC]
	adds r0, r4
	str r0, [sp, 0xC]
	mov r1, r8
	ldr r0, [r1, 0x4]
	adds r0, r5
	str r0, [r1, 0x4]
	ldr r0, [sp, 0x14]
	adds r0, r4
	str r0, [sp, 0x14]
	ldr r0, [r7, 0x4]
	adds r0, r5
	str r0, [r7, 0x4]
	movs r2, 0x80
	lsls r2, 1
	add r9, r2
	ldr r0, [sp, 0x2C]
	cmp r9, r0
	blt _080AAA74
_080AAAD4:
	movs r0, 0
_080AAAD6:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AA8BC

	thumb_func_start sub_80AAAE8
sub_80AAAE8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x80
	adds r5, r0, 0
	adds r3, r1, 0
	lsls r2, 24
	asrs r4, r2, 24
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x78]
	movs r2, 0xAF
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r5, r6
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, [sp, 0x78]
	cmp r4, r0
	beq _080AAB26
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r5, r1
	strb r4, [r0]
_080AAB26:
	subs r0, r3, 0x1
	cmp r0, 0x13
	bls _080AAB2E
	b _080AAEB8
_080AAB2E:
	lsls r0, 2
	ldr r1, _080AAB38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AAB38: .4byte _080AAB3C
	.align 2, 0
_080AAB3C:
	.4byte _080AAB8C
	.4byte _080AAD60
	.4byte _080AAC9C
	.4byte _080AAC9C
	.4byte _080AAC9C
	.4byte _080AAB9E
	.4byte _080AAB9E
	.4byte _080AAB9E
	.4byte _080AAD7C
	.4byte _080AADF4
	.4byte _080AAE06
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAEB8
	.4byte _080AAE32
	.4byte _080AAE9C
_080AAB8C:
	movs r4, 0xB2
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0
	str r0, [r1]
	movs r6, 0xC0
	lsls r6, 2
	str r6, [sp, 0x78]
	b _080AAD6E
_080AAB9E:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080AAC88
	movs r6, 0
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	str r0, [r1]
	cmp r3, 0x7
	beq _080AABD2
	cmp r3, 0x7
	bhi _080AABC0
	cmp r3, 0x6
	beq _080AABC6
	b _080AABEA
_080AABC0:
	cmp r3, 0x8
	beq _080AABDE
	b _080AABEA
_080AABC6:
	movs r1, 0x90
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x1
	str r2, [sp, 0x7C]
	b _080AABFC
_080AABD2:
	movs r3, 0x80
	lsls r3, 4
	str r3, [sp, 0x78]
	movs r0, 0x2
	str r0, [sp, 0x7C]
	b _080AABFC
_080AABDE:
	movs r1, 0xA0
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x4
	str r2, [sp, 0x7C]
	b _080AABFC
_080AABEA:
	movs r3, 0xB2
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0
	str r0, [r1]
	ldr r0, _080AAC20
	str r0, [sp, 0x78]
	movs r1, 0
	str r1, [sp, 0x7C]
_080AABFC:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x28
	adds r1, r4, 0
	bl sub_8002BB8
	ldr r0, [sp, 0x28]
	ldr r1, [sp, 0x2C]
	str r0, [sp, 0x38]
	str r1, [sp, 0x3C]
	movs r2, 0
	mov r10, r2
	add r3, sp, 0x40
	mov r9, r3
	add r4, sp, 0x30
	mov r8, r4
	b _080AAC42
	.align 2, 0
_080AAC20: .4byte 0x00000807
_080AAC24:
	cmp r6, 0x1
	bne _080AAC3E
	ldr r0, [sp, 0x38]
	str r0, [sp, 0x30]
	mov r6, r8
	str r7, [r6, 0x4]
	adds r0, r5, 0
	mov r1, r8
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	beq _080AAC78
_080AAC3E:
	movs r0, 0x1
	add r10, r0
_080AAC42:
	ldr r1, [sp, 0x7C]
	cmp r10, r1
	bge _080AAC74
	add r4, sp, 0x38
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	beq _080AAC78
	cmp r6, 0x1
	bne _080AAC3E
	movs r7, 0
	str r7, [sp, 0x40]
	ldr r0, [r4, 0x4]
	mov r2, r9
	str r0, [r2, 0x4]
	adds r0, r5, 0
	mov r1, r9
	bl sub_80AA074
	adds r6, r0, 0
	cmp r6, 0x2
	bne _080AAC24
_080AAC74:
	cmp r6, 0x2
	bne _080AAC7E
_080AAC78:
	movs r3, 0x1
	negs r3, r3
	b _080AAD6C
_080AAC7E:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80AAF68
	b _080AAEC0
_080AAC88:
	movs r4, 0xB2
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0
	str r0, [r1]
	ldr r6, _080AAC98
	str r6, [sp, 0x78]
	b _080AAD6E
	.align 2, 0
_080AAC98: .4byte 0x00000807
_080AAC9C:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _080AAD60
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x4
	str r0, [r1]
	cmp r3, 0x4
	beq _080AACCE
	cmp r3, 0x4
	bhi _080AACBC
	cmp r3, 0x3
	beq _080AACC2
	b _080AACE6
_080AACBC:
	cmp r3, 0x5
	beq _080AACDA
	b _080AACE6
_080AACC2:
	movs r1, 0x90
	lsls r1, 4
	str r1, [sp, 0x78]
	movs r2, 0x1
	mov r9, r2
	b _080AACF6
_080AACCE:
	movs r3, 0x80
	lsls r3, 4
	str r3, [sp, 0x78]
	movs r6, 0x2
	mov r9, r6
	b _080AACF6
_080AACDA:
	movs r0, 0xA0
	lsls r0, 4
	str r0, [sp, 0x78]
	movs r1, 0x4
	mov r9, r1
	b _080AACF6
_080AACE6:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	str r0, [r1]
	ldr r3, _080AAD5C
	str r3, [sp, 0x78]
	mov r9, r0
_080AACF6:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x48
	adds r1, r4, 0
	bl sub_8002BB8
	ldr r0, [sp, 0x48]
	ldr r1, [sp, 0x4C]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	movs r6, 0
	cmp r6, r9
	bge _080AAD52
	add r4, sp, 0x50
	mov r8, r4
	add r7, sp, 0x58
_080AAD16:
	adds r0, r5, 0
	mov r1, r8
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	movs r4, 0
	str r4, [sp, 0x58]
	mov r1, r8
	ldr r0, [r1, 0x4]
	str r0, [r7, 0x4]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	ldr r0, [sp, 0x50]
	str r0, [sp, 0x60]
	add r1, sp, 0x60
	str r4, [r1, 0x4]
	adds r0, r5, 0
	bl sub_80A9F94
	cmp r0, 0
	beq _080AAD4C
	mov r9, r4
_080AAD4C:
	adds r6, 0x1
	cmp r6, r9
	blt _080AAD16
_080AAD52:
	adds r0, r5, 0
	mov r1, r9
	bl sub_80AAF68
	b _080AAEC0
	.align 2, 0
_080AAD5C: .4byte 0x00000807
_080AAD60:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	str r0, [r1]
	ldr r3, _080AAD78
_080AAD6C:
	str r3, [sp, 0x78]
_080AAD6E:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80AAF68
	b _080AAEC0
	.align 2, 0
_080AAD78: .4byte 0x00000807
_080AAD7C:
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	beq _080AAD9C
	ldr r0, _080AAD98
	ldr r0, [r0]
	adds r0, 0x28
	strb r4, [r0]
	b _080AADA6
	.align 2, 0
_080AAD98: .4byte gUnknown_3001B80
_080AAD9C:
	ldr r0, _080AADF0
	ldr r0, [r0]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
_080AADA6:
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r5, r1
	movs r1, 0
	str r1, [r0]
	movs r2, 0x80
	lsls r2, 4
	str r2, [sp, 0x78]
	movs r3, 0xA1
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x4
	strb r0, [r1]
	movs r6, 0x1
	negs r6, r6
	cmp r4, r6
	bne _080AADCA
	b _080AAEC0
_080AADCA:
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x68
	adds r1, r4, 0
	bl sub_8002BB8
	ldr r0, [sp, 0x68]
	ldr r1, [sp, 0x6C]
	str r0, [sp, 0x70]
	str r1, [sp, 0x74]
	add r1, sp, 0x70
	adds r0, r5, 0
	bl sub_80AA074
	cmp r0, 0x2
	bne _080AAEC0
	str r6, [sp, 0x78]
	b _080AAEC0
	.align 2, 0
_080AADF0: .4byte gUnknown_3001B80
_080AADF4:
	movs r4, 0xA1
	lsls r4, 1
	adds r0, r5, r4
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r0, r5, 0
	bl sub_80AA3F8
	b _080AAEC0
_080AAE06:
	movs r6, 0xA1
	lsls r6, 1
	adds r0, r5, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	adds r0, r5, 0
	bl sub_80AA690
	lsls r0, 24
	cmp r0, 0
	bne _080AAEC0
	movs r0, 0
	mov r1, sp
	movs r2, 0x9
	bl sub_809D710
	adds r0, r5, 0
	movs r1, 0
	mov r2, sp
	bl _ExecutePlayerScript
	b _080AAEC0
_080AAE32:
	add r6, sp, 0xC
	movs r1, 0xA1
	lsls r1, 1
	adds r0, r5, r1
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80AA8BC
	lsls r0, 24
	cmp r0, 0
	beq _080AAE84
	add r4, sp, 0x10
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x6
	bl sub_809D710
	movs r2, 0
	ldrsh r0, [r6, r2]
	adds r1, r5, 0
	adds r1, 0x40
	adds r2, r4, 0
	bl GroundLives_ExecuteScript
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	bl _ExecutePlayerScript
	movs r3, 0
	ldrsh r0, [r6, r3]
	bl sub_80A8E9C
	adds r2, r0, 0
	movs r0, 0x7
	movs r1, 0
	bl sub_809B1C0
	b _080AAE8E
_080AAE84:
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
_080AAE8E:
	movs r4, 0x90
	lsls r4, 1
	adds r0, r5, r4
	movs r1, 0x5
	bl sub_809CD8C
	b _080AAEC0
_080AAE9C:
	add r4, sp, 0x1C
	ldr r2, _080AAEB4
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D710
	adds r0, r5, 0
	movs r1, 0
	adds r2, r4, 0
	bl _ExecutePlayerScript
	b _080AAEC0
	.align 2, 0
_080AAEB4: .4byte 0x00000195
_080AAEB8:
	adds r0, r5, 0
	movs r1, 0
	bl sub_80AAF68
_080AAEC0:
	movs r0, 0x1
	negs r0, r0
	ldr r6, [sp, 0x78]
	cmp r6, r0
	beq _080AAF04
	movs r0, 0xB4
	lsls r0, 1
	adds r2, r5, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r6, r0
	beq _080AAF04
	movs r3, 0xAE
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0
	strb r0, [r1]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r5, r4
	strh r6, [r2]
	movs r1, 0xA1
	lsls r1, 1
	adds r3, r5, r1
	ldrb r1, [r3]
	subs r4, 0x13
	adds r2, r5, r4
	strb r1, [r2]
	movs r2, 0
	ldrsb r2, [r3, r2]
	ldr r1, [sp, 0x78]
	bl sub_80A6EFC
	b _080AAF54
_080AAF04:
	movs r6, 0xAE
	lsls r6, 1
	adds r2, r5, r6
	ldrb r0, [r2]
	cmp r0, 0
	bne _080AAF2A
	ldr r0, _080AAF64
	adds r1, r5, r0
	movs r3, 0xA1
	lsls r3, 1
	adds r0, r5, r3
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AAF54
_080AAF2A:
	movs r0, 0
	strb r0, [r2]
	movs r4, 0xB8
	lsls r4, 1
	adds r0, r5, r4
	movs r6, 0xB4
	lsls r6, 1
	adds r1, r5, r6
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0xA1
	lsls r3, 1
	adds r4, r5, r3
	ldrb r2, [r4]
	subs r6, 0xB
	adds r3, r5, r6
	strb r2, [r3]
	movs r2, 0
	ldrsb r2, [r4, r2]
	bl sub_80A6EFC
_080AAF54:
	add sp, 0x80
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAF64: .4byte 0x0000015d
	thumb_func_end sub_80AAAE8

	thumb_func_start sub_80AAF68
sub_80AAF68:
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 7
	ands r0, r1
	cmp r0, 0
	beq _080AB002
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r1, 0x1
	bl sub_80A93F0
	lsls r0, 24
	cmp r0, 0
	beq _080AAFD0
	movs r1, 0xE4
	lsls r1, 1
	adds r0, r4, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bne _080AAFA6
	movs r0, 0xB5
	lsls r0, 1
	adds r1, r4, r0
	adds r0, 0x4C
	b _080AAFB4
_080AAFA6:
	movs r0, 0xDB
	lsls r0, 1
	cmp r1, r0
	beq _080AAFC2
	subs r0, 0x4C
	adds r1, r4, r0
	adds r0, 0x56
_080AAFB4:
	strh r0, [r1]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
_080AAFC2:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 17
	bl sub_80A8750
	b _080AB002
_080AAFD0:
	movs r2, 0xE4
	lsls r2, 1
	adds r0, r4, r2
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0xDB
	lsls r0, 1
	cmp r1, r0
	bne _080AAFF6
	subs r0, 0x4C
	adds r1, r4, r0
	adds r0, 0x56
	strh r0, [r1]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
_080AAFF6:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 17
	bl sub_80A86C8
_080AB002:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AAF68

	thumb_func_start sub_80AB008
sub_80AB008:
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AB008

	thumb_func_start sub_80AB010
sub_80AB010:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AB010

	thumb_func_start sub_80AB01C
sub_80AB01C:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AB05C
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AB0C2
_080AB05C:
	movs r0, 0xA2
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA6
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0xAA
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AB0BE
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AB0BE:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AB0C2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB01C

	thumb_func_start sub_80AB0C8
sub_80AB0C8:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB0C8

	thumb_func_start sub_80AB0E0
sub_80AB0E0:
	adds r3, r0, 0
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AB0E0

	thumb_func_start sub_80AB100
sub_80AB100:
	push {lr}
	bl sub_80A9F20
	pop {r1}
	bx r1
	thumb_func_end sub_80AB100

	thumb_func_start sub_80AB10C
sub_80AB10C:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0xAA
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AB10C

	thumb_func_start sub_80AB12C
sub_80AB12C:
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AB12C

	thumb_func_start sub_80AB138
sub_80AB138:
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AB138

	thumb_func_start sub_80AB144
sub_80AB144:
	push {lr}
	adds r3, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AB17C
	movs r0, 0xA1
	lsls r0, 1
	adds r2, r3, r0
	lsls r0, r1, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, _080AB180
	adds r1, r3, r2
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AB17C
	movs r0, 0xAE
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AB17C:
	pop {r0}
	bx r0
	.align 2, 0
_080AB180: .4byte 0x0000015d
	thumb_func_end sub_80AB144

	thumb_func_start sub_80AB184
sub_80AB184:
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80A9750
	pop {r0}
	bx r0
	thumb_func_end sub_80AB184

	thumb_func_start sub_80AB194
sub_80AB194:
	push {lr}
	mov r12, r0
	lsls r1, 16
	asrs r1, 16
	adds r3, r1, 0
	cmp r1, 0
	bne _080AB1A8
	movs r0, 0xE0
	lsls r0, 1
	adds r3, r0, 0
_080AB1A8:
	movs r0, 0xB5
	lsls r0, 1
	add r0, r12
	strh r3, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AB194

	thumb_func_start nullsub_211
nullsub_211:
	bx lr
	thumb_func_end nullsub_211

	thumb_func_start sub_80AB1C0
sub_80AB1C0:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xAE
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB1DE
	adds r2, 0x14
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AB1E0
_080AB1DE:
	movs r0, 0x1
_080AB1E0:
	pop {r1}
	bx r1
	thumb_func_end sub_80AB1C0

	thumb_func_start sub_80AB1E4
sub_80AB1E4:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xB5
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AB206
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080AB208
_080AB206:
	movs r0, 0x1
_080AB208:
	pop {r1}
	bx r1
	thumb_func_end sub_80AB1E4

	thumb_func_start sub_80AB20C
sub_80AB20C:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80AB20C

	thumb_func_start sub_80AB218
sub_80AB218:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A86C8
	pop {r0}
	bx r0
	thumb_func_end sub_80AB218

	thumb_func_start sub_80AB228
sub_80AB228:
	push {lr}
	movs r2, 0
	ldrsh r0, [r0, r2]
	bl sub_80A8750
	pop {r0}
	bx r0
	thumb_func_end sub_80AB228

	thumb_func_start sub_80AB238
sub_80AB238:
	push {lr}
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r2
	bl sub_80A6EC8
	pop {r0}
	bx r0
	thumb_func_end sub_80AB238

	thumb_func_start sub_80AB248
sub_80AB248:
	push {lr}
	bl sub_80A9F94
	pop {r1}
	bx r1
	thumb_func_end sub_80AB248

	thumb_func_start GroundLives_Action
GroundLives_Action:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x3C
	ldr r0, _080AB29C
	ldr r5, [r0]
	movs r0, 0
	mov r9, r0
_080AB266:
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	movs r3, 0x1
	negs r3, r3
	mov r8, r3
	adds r0, r3, 0
	cmp r1, r0
	bne _080AB278
	b _080AB47C
_080AB278:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AB2A0
	adds r0, r4, 0
	bl HandleAction
	lsls r0, 16
	asrs r3, r0, 16
	cmp r3, 0
	beq _080AB2A4
	cmp r3, 0x4
	beq _080AB292
	b _080AB44C
_080AB292:
	mov r0, r9
	bl GroundLives_Delete
	b _080AB47C
	.align 2, 0
_080AB29C: .4byte gUnknown_3001B84
_080AB2A0: .4byte gUnknown_8118280
_080AB2A4:
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	bne _080AB2B8
	b _080AB42E
_080AB2B8:
	str r3, [sp, 0xC]
	add r0, sp, 0x8
	mov r1, r8
	strb r1, [r0]
	str r3, [sp, 0x10]
	movs r3, 0x90
	lsls r3, 1
	adds r0, r5, r3
	add r1, sp, 0xC
	add r3, sp, 0x10
	add r4, sp, 0x14
	str r4, [sp]
	ldr r2, [r2]
	str r2, [sp, 0x4]
	add r2, sp, 0x8
	bl sub_809CDC8
	subs r0, 0x1
	mov r8, r4
	cmp r0, 0x7
	bls _080AB2E4
	b _080AB44C
_080AB2E4:
	lsls r0, 2
	ldr r1, _080AB2F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AB2F0: .4byte _080AB2F4
	.align 2, 0
_080AB2F4:
	.4byte _080AB314
	.4byte _080AB314
	.4byte _080AB326
	.4byte _080AB44C
	.4byte _080AB314
	.4byte _080AB44C
	.4byte _080AB44C
	.4byte _080AB314
_080AB314:
	ldr r1, [sp, 0xC]
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldr r3, [sp, 0x10]
	adds r0, r5, 0
	bl sub_80AAAE8
	b _080AB44C
_080AB326:
	add r4, sp, 0x1C
	adds r0, r4, 0
	bl sub_809D248
	ldr r1, [sp, 0x1C]
	ldr r0, [sp, 0x14]
	adds r6, r1, r0
	ldr r1, [r4, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r7, r1, r0
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r5, r3
	ldr r1, [r0]
	ldr r0, [r5, 0x14]
	adds r0, r1, r0
	cmp r0, 0
	bge _080AB34E
	adds r0, 0xFF
_080AB34E:
	asrs r0, 8
	subs r0, r6, r0
	str r0, [sp, 0x24]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r0, r1, r0
	cmp r0, 0
	bge _080AB366
	adds r0, 0xFF
_080AB366:
	asrs r0, 8
	subs r0, r7, r0
	add r1, sp, 0x24
	str r0, [r1, 0x4]
	adds r0, r6, 0
	subs r0, 0x10
	lsls r0, 8
	str r0, [sp, 0x2C]
	adds r0, r6, 0
	adds r0, 0x10
	lsls r0, 8
	str r0, [sp, 0x34]
	subs r0, r7, 0x4
	lsls r0, 8
	add r2, sp, 0x2C
	str r0, [r2, 0x4]
	adds r0, r7, 0
	adds r0, 0x1C
	lsls r0, 8
	add r3, sp, 0x34
	str r0, [r3, 0x4]
	ldr r0, [sp, 0xC]
	adds r4, r1, 0
	cmp r0, 0xC
	bne _080AB3C4
	adds r0, r5, 0
	movs r1, 0xC
	bl sub_80AA180
	cmp r0, 0
	bne _080AB44C
	ldr r0, [sp, 0x24]
	adds r0, 0x10
	cmp r0, 0x20
	bhi _080AB44C
	movs r0, 0x1C
	negs r0, r0
	ldr r1, [r4, 0x4]
	cmp r1, r0
	blt _080AB44C
	cmp r1, 0x4
	bgt _080AB44C
	movs r2, 0x1
	negs r2, r2
	adds r0, r5, 0
	movs r1, 0x13
	b _080AB426
_080AB3C4:
	ldr r0, [sp, 0x24]
	adds r0, 0x10
	cmp r0, 0x20
	bhi _080AB3DA
	movs r0, 0x1C
	negs r0, r0
	ldr r1, [r4, 0x4]
	cmp r1, r0
	blt _080AB3DA
	cmp r1, 0x4
	ble _080AB44C
_080AB3DA:
	adds r0, r4, 0
	bl sub_8002C60
	add r1, sp, 0x8
	strb r0, [r1]
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	cmp r0, r1
	beq _080AB44C
	ldr r0, [sp, 0xC]
	cmp r0, 0x11
	beq _080AB410
	cmp r0, 0x11
	bhi _080AB3FE
	cmp r0, 0x10
	beq _080AB404
	b _080AB44C
_080AB3FE:
	cmp r0, 0x12
	beq _080AB41C
	b _080AB44C
_080AB404:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x6
	b _080AB426
_080AB410:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x7
	b _080AB426
_080AB41C:
	add r0, sp, 0x8
	movs r2, 0
	ldrsb r2, [r0, r2]
	adds r0, r5, 0
	movs r1, 0x8
_080AB426:
	movs r3, 0
	bl sub_80AAAE8
	b _080AB44C
_080AB42E:
	movs r0, 0x80
	lsls r0, 5
	ands r1, r0
	cmp r1, 0
	beq _080AB440
	adds r0, r5, 0
	bl sub_80AB5D4
	b _080AB44C
_080AB440:
	ldr r3, _080AB4C4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	bl sub_809D8C0
_080AB44C:
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080AB47C
	movs r0, 0
	strb r0, [r1]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r5, r3
	adds r2, 0xC
	adds r1, r5, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	subs r2, 0x26
	adds r4, r5, r2
	ldrb r2, [r4]
	ldr r3, _080AB4C8
	strb r2, [r3, r5]
	movs r2, 0
	ldrsb r2, [r4, r2]
	bl sub_80A6EFC
_080AB47C:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	movs r0, 0xF8
	lsls r0, 1
	adds r5, r0
	mov r1, r9
	cmp r1, 0x17
	bgt _080AB494
	b _080AB266
_080AB494:
	ldr r0, _080AB4CC
	ldr r6, [r0]
	ldr r0, _080AB4D0
	ldr r5, [r0]
	movs r0, 0
	str r0, [r6]
	str r0, [r6, 0x4]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	subs r0, 0x1
	cmp r1, r0
	beq _080AB4BE
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r3, 0x80
	lsls r3, 6
	ands r3, r1
	cmp r3, 0
	beq _080AB4D4
_080AB4BE:
	bl sub_80AB5A4
	b _080AB594
	.align 2, 0
_080AB4C4: .4byte gUnknown_811828C
_080AB4C8: .4byte 0x0000015d
_080AB4CC: .4byte gUnknown_3001B80
_080AB4D0: .4byte gUnknown_3001B84
_080AB4D4:
	movs r0, 0x80
	lsls r0, 5
	ands r1, r0
	cmp r1, 0
	beq _080AB590
	ldr r7, [r6, 0x24]
	cmp r7, 0
	bge _080AB51E
	adds r2, r6, 0
	adds r2, 0x2C
	str r3, [r6, 0x24]
	str r3, [r6, 0x2C]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2, 0x4]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2, 0x8]
	adds r0, r6, 0
	movs r2, 0
	movs r1, 0x2
_080AB50E:
	str r2, [r0, 0x8]
	str r2, [r0]
	str r2, [r0, 0x4]
	subs r1, 0x1
	adds r0, 0xC
	cmp r1, 0
	bge _080AB50E
	b _080AB594
_080AB51E:
	adds r2, r7, 0x1
	adds r0, r2, 0
	cmp r2, 0
	bge _080AB52A
	adds r0, r7, 0
	adds r0, 0x40
_080AB52A:
	asrs r1, r0, 6
	lsls r0, r1, 6
	subs r1, r2, r0
	str r1, [r6, 0x24]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r6
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, [r5, 0x14]
	adds r2, r0
	mov r3, r8
	str r2, [r3, 0x4]
	adds r1, 0x4
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r1, r0
	str r1, [r3, 0x8]
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r6, r0
	ldr r3, [r0, 0x4]
	ldr r0, [r0, 0x8]
	subs r0, r1, r0
	subs r2, r3
	cmp r2, 0
	bge _080AB572
	negs r2, r2
_080AB572:
	adds r4, r2, 0
	cmp r0, 0
	bge _080AB57A
	negs r0, r0
_080AB57A:
	cmp r0, r4
	bge _080AB580
	adds r0, r2, 0
_080AB580:
	mov r2, r8
	str r0, [r2]
	cmp r0, 0
	bgt _080AB58C
	str r7, [r6, 0x24]
	b _080AB594
_080AB58C:
	str r0, [r6]
	b _080AB594
_080AB590:
	bl sub_80AB5A4
_080AB594:
	add sp, 0x3C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundLives_Action

	thumb_func_start sub_80AB5A4
sub_80AB5A4:
	push {lr}
	ldr r3, _080AB5D0
	ldr r0, [r3]
	movs r2, 0x1
	negs r2, r2
	str r2, [r0, 0x24]
	adds r0, 0x28
	movs r1, 0xFF
	strb r1, [r0]
	ldr r3, [r3]
	movs r1, 0
	movs r0, 0x2
_080AB5BC:
	str r2, [r3, 0x8]
	str r1, [r3]
	str r1, [r3, 0x4]
	subs r0, 0x1
	adds r3, 0xC
	cmp r0, 0
	bge _080AB5BC
	pop {r0}
	bx r0
	.align 2, 0
_080AB5D0: .4byte gUnknown_3001B80
	thumb_func_end sub_80AB5A4

	thumb_func_start sub_80AB5D4
sub_80AB5D4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r0
	ldr r4, _080AB6BC
	movs r2, 0x9E
	lsls r2, 1
	add r2, r9
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r3, [r4]
	adds r0, r3
	mov r8, r0
	adds r0, r1, 0
	adds r5, r4, 0
	cmp r0, 0
	bne _080AB604
	b _080AB9E6
_080AB604:
	movs r1, 0xAF
	lsls r1, 1
	add r1, r9
	movs r0, 0xC0
	lsls r0, 2
	strh r0, [r1]
	movs r1, 0xB0
	lsls r1, 1
	add r1, r9
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x8E
	lsls r0, 1
	add r0, r9
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 6
	ands r2, r0
	cmp r2, 0
	beq _080AB6D4
	movs r2, 0xA1
	lsls r2, 1
	add r2, r9
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0x4
	bne _080AB64C
	movs r0, 0xB4
	lsls r0, 1
	add r0, r9
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	beq _080AB670
_080AB64C:
	movs r1, 0xB2
	lsls r1, 1
	add r1, r9
	movs r0, 0
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r9
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r0, 0x4
	strb r0, [r2]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r9
	movs r0, 0x1
	strb r0, [r1]
_080AB670:
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x28
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AB69C
	movs r2, 0x80
	lsls r2, 1
	mov r0, sp
	bl sub_8002BB8
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	add r1, sp, 0x8
	mov r0, r9
	bl sub_80A9F94
_080AB69C:
	mov r4, r8
	ldr r0, [r4, 0x8]
	cmp r0, 0
	blt _080AB6A6
	b _080AB9E6
_080AB6A6:
	ldr r0, [r5]
	ldr r0, [r0, 0x24]
	cmp r0, 0
	bge _080AB6B0
	b _080AB9E6
_080AB6B0:
	str r0, [r4, 0x8]
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	b _080AB9E6
	.align 2, 0
_080AB6BC: .4byte gUnknown_3001B80
_080AB6C0:
	ldr r5, [sp, 0x28]
	ldr r0, [r5, 0x4]
	adds r0, r7, r0
	str r0, [r5, 0x4]
	b _080AB7E2
_080AB6CA:
	ldr r1, [sp, 0x28]
	ldr r0, [r1, 0x4]
	subs r0, r7
	str r0, [r1, 0x4]
	b _080AB7E2
_080AB6D4:
	movs r0, 0xA2
	lsls r0, 1
	add r0, r9
	ldr r1, [r0]
	mov r5, r9
	ldr r0, [r5, 0x14]
	adds r0, r1, r0
	str r0, [sp, 0x20]
	movs r0, 0xA4
	lsls r0, 1
	add r0, r9
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r0, r1, r0
	str r0, [sp, 0x24]
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x24]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	mov r1, r8
	ldr r0, [r1, 0x8]
	cmp r0, 0
	bge _080AB710
	ldr r0, [r3, 0x24]
	cmp r0, 0
	bge _080AB70A
	b _080AB9E6
_080AB70A:
	str r0, [r1, 0x8]
	str r2, [r1]
	str r2, [r1, 0x4]
_080AB710:
	mov r2, r8
	ldr r7, [r2]
	movs r3, 0x1
	mov r10, r3
	mov r5, sp
	adds r5, 0x10
	str r5, [sp, 0x28]
_080AB71E:
	mov r0, r8
	ldr r1, [r0, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	ldr r2, _080AB754
	ldr r1, [r2]
	adds r1, r0
	mov r12, r1
	ldr r6, [r1, 0x4]
	ldr r5, [sp, 0x10]
	subs r4, r6, r5
	adds r2, r4, 0
	ldr r1, [r1, 0x8]
	ldr r0, [sp, 0x14]
	subs r3, r1, r0
	cmp r4, 0
	ble _080AB75E
	cmp r2, r7
	ble _080AB758
	adds r0, r7, r5
	str r0, [sp, 0x10]
	movs r4, 0
	mov r10, r4
	b _080AB75A
	.align 2, 0
_080AB754: .4byte gUnknown_3001B80
_080AB758:
	str r6, [sp, 0x10]
_080AB75A:
	adds r1, r2, 0
	b _080AB778
_080AB75E:
	cmp r4, 0
	bge _080AB776
	cmn r2, r7
	bge _080AB770
	subs r0, r5, r7
	str r0, [sp, 0x10]
	movs r5, 0
	mov r10, r5
	b _080AB772
_080AB770:
	str r6, [sp, 0x10]
_080AB772:
	negs r1, r2
	b _080AB778
_080AB776:
	movs r1, 0
_080AB778:
	cmp r3, 0
	ble _080AB78E
	cmp r3, r7
	bgt _080AB6C0
	mov r4, r12
	ldr r0, [r4, 0x8]
	str r0, [sp, 0x14]
	cmp r3, r1
	ble _080AB7A2
	adds r1, r3, 0
	b _080AB7A2
_080AB78E:
	cmp r3, 0
	bge _080AB7A2
	cmn r3, r7
	blt _080AB6CA
	mov r5, r12
	ldr r0, [r5, 0x8]
	str r0, [sp, 0x14]
	cmn r3, r1
	bge _080AB7A2
	negs r1, r3
_080AB7A2:
	mov r0, r10
	cmp r0, 0
	beq _080AB7E2
	subs r7, r1
	cmp r7, 0
	ble _080AB7E2
	ldr r1, _080AB7D4
	ldr r0, [r1]
	mov r3, r8
	ldr r2, [r3, 0x8]
	ldr r0, [r0, 0x24]
	cmp r2, r0
	beq _080AB7D8
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB7C8
	adds r0, r2, 0
	adds r0, 0x40
_080AB7C8:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	mov r4, r8
	str r0, [r4, 0x8]
	b _080AB7DC
	.align 2, 0
_080AB7D4: .4byte gUnknown_3001B80
_080AB7D8:
	movs r5, 0
	mov r10, r5
_080AB7DC:
	mov r0, r10
	cmp r0, 0
	bne _080AB71E
_080AB7E2:
	mov r1, r8
	ldr r0, [r1, 0x8]
	bl sub_80ABA00
	adds r6, r0, 0
	ldr r0, _080AB860
	ldr r7, [r0]
	movs r2, 0x9E
	lsls r2, 1
	add r2, r9
	mov r10, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	subs r1, r2, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r7, 0x4
	adds r1, r0
	ldr r0, _080AB864
	lsls r2, 2
	adds r2, r0
	ldr r1, [r1]
	ldr r0, [r2]
	adds r1, r0
	mov r12, r1
	mov r4, r8
	ldr r1, [r4, 0x8]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r0, r7, r0
	ldr r3, [r0, 0x4]
	ldr r2, [sp, 0x10]
	ldr r1, [r0, 0x8]
	ldr r5, [sp, 0x28]
	ldr r0, [r5, 0x4]
	subs r1, r0
	subs r3, r2
	cmp r3, 0
	bge _080AB838
	negs r3, r3
_080AB838:
	adds r4, r3, 0
	cmp r1, 0
	bge _080AB840
	negs r1, r1
_080AB840:
	cmp r1, r4
	bge _080AB846
	adds r1, r3, 0
_080AB846:
	adds r6, r1
	mov r0, r8
	str r6, [r0, 0x4]
	cmp r6, r12
	bgt _080AB86C
	ldr r0, [r0]
	cmp r0, 0
	ble _080AB8B2
	ldr r1, _080AB868
	adds r0, r1
	mov r2, r8
	b _080AB8B0
	.align 2, 0
_080AB860: .4byte gUnknown_3001B80
_080AB864: .4byte gUnknown_8118050
_080AB868: .4byte 0xffffff00
_080AB86C:
	mov r3, r10
	movs r4, 0
	ldrsh r1, [r3, r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	cmp r6, r0
	bgt _080AB88E
	mov r5, r8
	ldr r0, [r5]
	cmp r0, 0xFF
	bgt _080AB8B2
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1
	str r0, [r5]
	b _080AB8B2
_080AB88E:
	subs r1, 0x1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r7, r0
	ldr r0, [r0]
	cmp r0, 0xFF
	bgt _080AB8A2
	movs r0, 0x80
	lsls r0, 1
_080AB8A2:
	mov r2, r8
	ldr r1, [r2]
	cmp r1, r0
	bge _080AB8B2
	movs r3, 0x80
	lsls r3, 1
	adds r0, r1, r3
_080AB8B0:
	str r0, [r2]
_080AB8B2:
	ldr r0, _080AB96C
	ldr r3, [r0]
	mov r4, r8
	ldr r0, [r4, 0x8]
	subs r0, 0x40
	ldr r2, [r3, 0x24]
	subs r1, r2, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB8C8
	adds r0, 0x3F
_080AB8C8:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	cmp r0, 0x3B
	ble _080AB8FC
	adds r1, r2, 0x5
	adds r0, r1, 0
	cmp r1, 0
	bge _080AB8DE
	adds r0, r2, 0
	adds r0, 0x44
_080AB8DE:
	asrs r0, 6
	lsls r0, 6
	subs r0, r1, r0
	mov r5, r8
	str r0, [r5, 0x8]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x30
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
_080AB8FC:
	mov r0, r9
	ldr r1, [sp, 0x28]
	bl sub_80A9F20
	adds r6, r0, 0
	cmp r6, 0
	bne _080AB9E6
	ldr r0, [sp, 0x10]
	ldr r1, [sp, 0x20]
	subs r0, r1
	str r0, [sp, 0x18]
	ldr r2, [sp, 0x28]
	ldr r1, [r2, 0x4]
	ldr r3, [sp, 0x24]
	subs r1, r3
	add r0, sp, 0x18
	str r1, [r0, 0x4]
	movs r5, 0xA1
	lsls r5, 1
	add r5, r9
	movs r4, 0
	ldrsb r4, [r5, r4]
	bl sub_8002C60
	adds r1, r0, 0
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl sub_8002B04
	strb r0, [r5]
	mov r4, r8
	ldr r0, [r4]
	cmp r0, 0
	ble _080AB970
	movs r1, 0xB2
	lsls r1, 1
	add r1, r9
	movs r0, 0x4
	str r0, [r1]
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 2
	movs r2, 0x80
	lsls r2, 4
	cmp r1, r0
	ble _080AB95E
	movs r2, 0xA0
	lsls r2, 4
_080AB95E:
	adds r4, r2, 0
	mov r0, r9
	movs r1, 0x1
	bl sub_80AAF68
	b _080AB982
	.align 2, 0
_080AB96C: .4byte gUnknown_3001B80
_080AB970:
	ldr r4, _080AB9F8
	movs r0, 0xB2
	lsls r0, 1
	add r0, r9
	str r6, [r0]
	mov r0, r9
	movs r1, 0
	bl sub_80AAF68
_080AB982:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r9
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AB9B6
	movs r0, 0xB4
	lsls r0, 1
	add r0, r9
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r4, r0
	bne _080AB9B6
	ldr r1, _080AB9FC
	add r1, r9
	movs r0, 0xA1
	lsls r0, 1
	add r0, r9
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r1, r0
	beq _080AB9E6
_080AB9B6:
	movs r1, 0xAE
	lsls r1, 1
	add r1, r9
	movs r0, 0
	strb r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	add r0, r9
	movs r1, 0xB4
	lsls r1, 1
	add r1, r9
	strh r4, [r1]
	movs r3, 0xA1
	lsls r3, 1
	add r3, r9
	ldrb r1, [r3]
	ldr r2, _080AB9FC
	add r2, r9
	strb r1, [r2]
	movs r2, 0
	ldrsb r2, [r3, r2]
	adds r1, r4, 0
	bl sub_80A6EFC
_080AB9E6:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB9F8: .4byte 0x00000807
_080AB9FC: .4byte 0x0000015d
	thumb_func_end sub_80AB5D4

	thumb_func_start sub_80ABA00
sub_80ABA00:
	push {r4,r5,lr}
	adds r1, r0, 0
	movs r4, 0
	ldr r0, _080ABA34
	ldr r2, [r0]
	ldr r3, [r2, 0x24]
	adds r5, r0, 0
	cmp r3, r1
	ble _080ABA38
	adds r1, 0x1
	cmp r1, r3
	bge _080ABA72
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r2, r0, r2
	subs r1, r3, r1
_080ABA24:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080ABA24
	b _080ABA72
	.align 2, 0
_080ABA34: .4byte gUnknown_3001B80
_080ABA38:
	cmp r3, r1
	bge _080ABA72
	adds r1, 0x1
	cmp r1, 0x3F
	bgt _080ABA58
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, 0x2C
	adds r2, r0, r2
_080ABA4C:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	adds r1, 0x1
	cmp r1, 0x3F
	ble _080ABA4C
_080ABA58:
	ldr r1, [r5]
	ldr r0, [r1, 0x24]
	cmp r0, 0
	ble _080ABA72
	adds r2, r1, 0
	adds r2, 0x2C
	adds r1, r0, 0
_080ABA66:
	ldr r0, [r2]
	adds r4, r0
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080ABA66
_080ABA72:
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABA00

	thumb_func_start sub_80ABA7C
sub_80ABA7C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080ABB50
	ldr r5, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0xA2
	lsls r1, 1
	adds r4, r5, r1
	movs r2, 0x1
	negs r2, r2
	mov r9, r2
_080ABA9A:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, r9
	beq _080ABB2C
	ldr r0, [r4]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x10]
	ldr r0, [r4, 0x14]
	adds r7, r1, r0
	ldr r0, [r4, 0x20]
	cmp r0, 0
	ble _080ABADA
	subs r0, 0x1
	str r0, [r4, 0x20]
	cmp r0, 0
	bgt _080ABADA
	ldrh r0, [r4, 0x1C]
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _080ABADA
	ldrh r1, [r4, 0x1C]
	adds r0, r5, 0
	bl sub_80A9750
_080ABADA:
	movs r2, 0xB8
	lsls r2, 1
	adds r6, r5, r2
	adds r0, r6, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080ABAFE
	movs r0, 0
	strb r0, [r4, 0x18]
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	movs r2, 0x19
	ldrsb r2, [r4, r2]
	adds r0, r6, 0
	bl sub_80A6EFC
_080ABAFE:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080ABB1E
	adds r1, r0, 0
	movs r2, 0xA1
	lsls r2, 1
	adds r0, r5, r2
	movs r2, 0
	ldrsb r2, [r0, r2]
	ldr r3, [r4, 0x28]
	adds r0, r6, 0
	bl sub_80A74F0
	movs r0, 0
	strh r0, [r4, 0x26]
_080ABB1E:
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	adds r0, r6, 0
	mov r2, sp
	adds r3, r7, 0
	bl sub_80A7524
_080ABB2C:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r1, 0xF8
	lsls r1, 1
	adds r4, r1
	adds r5, r1
	cmp r0, 0x17
	ble _080ABA9A
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB50: .4byte gUnknown_3001B84
	thumb_func_end sub_80ABA7C

	thumb_func_start sub_80ABB54
sub_80ABB54:
	push {r4,r5,lr}
	ldr r4, _080ABB90
	movs r0, 0xE2
	lsls r0, 5
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080ABB94
	adds r5, r0, 0
	movs r4, 0xE2
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080ABB74:
	ldrh r0, [r1, 0x6]
	orrs r0, r5
	strh r0, [r1, 0x6]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0xF
	ble _080ABB74
	bl sub_80ABB98
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ABB90: .4byte gUnknown_3001B88
_080ABB94: .4byte 0x0000ffff
	thumb_func_end sub_80ABB54

	thumb_func_start sub_80ABB98
sub_80ABB98:
	push {r4-r6,lr}
	ldr r0, _080ABBD0
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080ABBA8:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080ABBB6
	adds r0, r1, 0
	bl GroundObject_Delete
_080ABBB6:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ABBA8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBD0: .4byte gUnknown_3001B88
	thumb_func_end sub_80ABB98

	thumb_func_start sub_80ABBD4
sub_80ABBD4:
	push {r4,lr}
	bl sub_80ABB98
	ldr r4, _080ABBEC
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ABBEC: .4byte gUnknown_3001B88
	thumb_func_end sub_80ABBD4

	thumb_func_start GroundObject_Select
GroundObject_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ABC54
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ABC58
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0xC]
	ldr r0, [r0, 0x8]
	cmp r0, 0
	ble _080ABC4A
	adds r4, r0, 0
_080ABC34:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundObject_Add
	subs r4, 0x1
	adds r5, 0x18
	cmp r4, 0
	bne _080ABC34
_080ABC4A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABC54: .4byte gUnknown_81183E4
_080ABC58: .4byte gUnknown_81183F0
	thumb_func_end GroundObject_Select

	thumb_func_start GroundObject_Cancel
GroundObject_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ABCC4
	movs r0, 0
	adds r2, r7, 0
	bl Log
	movs r1, 0
	ldr r0, _080ABCC8
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ABC84:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ABCA6
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ABCA6
	cmp r5, 0
	blt _080ABCA0
	movs r0, 0xA
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ABCA6
_080ABCA0:
	adds r0, r1, 0
	bl GroundObject_Delete
_080ABCA6:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ABC84
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABCC4: .4byte gUnknown_8118414
_080ABCC8: .4byte gUnknown_3001B88
	thumb_func_end GroundObject_Cancel

	thumb_func_start GroundObject_CancelBlank
GroundObject_CancelBlank:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080ABD40
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080ABD44
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x92
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080ABCF0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080ABD20
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080ABD20
	adds r0, r6, 0
	bl GroundObject_Delete
_080ABD20:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0xF
	ble _080ABCF0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABD40: .4byte gUnknown_811842C
_080ABD44: .4byte gUnknown_3001B88
	thumb_func_end GroundObject_CancelBlank

	thumb_func_start sub_80ABD48
sub_80ABD48:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080ABD6C
	ldr r1, [r0]
	movs r6, 0xE2
	lsls r6, 1
	movs r2, 0x80
	lsls r2, 9
	adds r5, r2, 0
_080ABD5E:
	movs r7, 0x6
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080ABD70
	adds r0, r3, 0
	b _080ABD80
	.align 2, 0
_080ABD6C: .4byte gUnknown_3001B88
_080ABD70:
	adds r0, r2, 0
	adds r2, r5
	asrs r3, r0, 16
	adds r1, r6
	cmp r3, 0xF
	ble _080ABD5E
	movs r0, 0x1
	negs r0, r0
_080ABD80:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ABD48

	thumb_func_start GroundObject_Add
GroundObject_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldrb r4, [r1]
	cmp r4, 0x1A
	bne _080ABDDA
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	cmp r0, 0x1
	bgt _080ABDBC
	movs r4, 0x1B
	b _080ABDDA
_080ABDBC:
	movs r0, 0
	movs r1, 0x29
	bl sub_8001658
	cmp r0, 0
	bne _080ABDD4
	movs r0, 0
	movs r1, 0x27
	bl sub_8001658
	adds r0, 0x1C
	b _080ABDD6
_080ABDD4:
	adds r0, 0x2B
_080ABDD6:
	lsls r0, 16
	asrs r4, r0, 16
_080ABDDA:
	lsls r1, r4, 2
	ldr r0, _080ABE10
	adds r6, r1, r0
	cmp r7, 0
	bge _080ABE40
	cmp r4, 0xE
	bgt _080ABDF4
	cmp r4, 0xD
	blt _080ABDF4
	adds r0, r4, 0
	bl sub_80ABD48
	adds r7, r0, 0
_080ABDF4:
	cmp r7, 0
	bge _080ABE40
	movs r3, 0
	ldr r0, _080ABE14
	ldr r5, [r0]
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE18
	movs r7, 0
	b _080ABE40
	.align 2, 0
_080ABE10: .4byte gUnknown_811ED20
_080ABE14: .4byte gUnknown_3001B88
_080ABE18:
	adds r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r5, r1
	cmp r3, 0xF
	bgt _080ABE36
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE18
	adds r7, r3, 0
_080ABE36:
	cmp r7, 0
	bge _080ABE40
	movs r0, 0x1
	negs r0, r0
	b _080AC142
_080ABE40:
	ldr r1, _080ABEA8
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 4
	adds r0, r7
	lsls r0, 2
	ldr r1, [r1]
	adds r5, r1, r0
	ldr r1, _080ABEAC
	mov r3, r8
	ldrb r0, [r3]
	str r0, [sp]
	movs r2, 0
	ldrsh r0, [r6, r2]
	str r0, [sp, 0x4]
	mov r3, r10
	str r3, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	movs r0, 0
	adds r2, r7, 0
	adds r3, r4, 0
	bl Log
	movs r2, 0
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ABE80
	movs r2, 0x1
_080ABE80:
	str r2, [sp, 0x10]
	strh r7, [r5, 0x4]
	strh r4, [r5, 0x6]
	mov r0, r10
	strh r0, [r5, 0x8]
	mov r1, r9
	strb r1, [r5, 0xA]
	ldrh r0, [r6]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xE
	bls _080ABE9C
	b _080ABF8C
_080ABE9C:
	lsls r0, 2
	ldr r1, _080ABEB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ABEA8: .4byte gUnknown_3001B88
_080ABEAC: .4byte gUnknown_8118448
_080ABEB0: .4byte _080ABEB4
	.align 2, 0
_080ABEB4:
	.4byte _080ABEF0
	.4byte _080ABF7C
	.4byte _080ABF46
	.4byte _080ABF54
	.4byte _080ABF54
	.4byte _080ABF5E
	.4byte _080ABF68
	.4byte _080ABF72
	.4byte _080ABF3C
	.4byte _080ABEFA
	.4byte _080ABEF0
	.4byte _080ABF06
	.4byte _080ABF2C
	.4byte _080ABF1E
	.4byte _080ABF12
_080ABEF0:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0
	b _080ABF94
_080ABEFA:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x80
	lsls r0, 10
	b _080ABF94
_080ABF06:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x80
	lsls r0, 11
	b _080ABF94
_080ABF12:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x83
	lsls r0, 18
	b _080ABF94
_080ABF1E:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABF28
	b _080ABF94
	.align 2, 0
_080ABF28: .4byte 0x220c0000
_080ABF2C:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	ldr r0, _080ABF38
	b _080ABF94
	.align 2, 0
_080ABF38: .4byte 0x20010000
_080ABF3C:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x5
	b _080ABF94
_080ABF46:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABF50
	b _080ABF94
	.align 2, 0
_080ABF50: .4byte 0x22000184
_080ABF54:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	adds r0, 0x68
	b _080ABF94
_080ABF5E:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x44
	b _080ABF94
_080ABF68:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x84
	b _080ABF94
_080ABF72:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	adds r0, 0x64
	b _080ABF94
_080ABF7C:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080ABF88
	b _080ABF94
	.align 2, 0
_080ABF88: .4byte 0x020000c4
_080ABF8C:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ABFA8
_080ABF94:
	str r0, [r1]
	ldrb r0, [r6, 0x2]
	cmp r0, 0
	bne _080ABFAC
	mov r1, r8
	ldrb r0, [r1, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r1, 0x3]
	b _080ABFB4
	.align 2, 0
_080ABFA8: .4byte 0x02000185
_080ABFAC:
	ldrb r0, [r6, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r6, 0x3]
_080ABFB4:
	lsls r0, 11
	str r0, [r5, 0x10]
	ldr r0, [r5, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x14]
	ldr r0, [r5, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x18]
	mov r2, r8
	ldrb r0, [r2, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ABFFC
	mov r3, r8
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ABFFC
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080ABFFC:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AC01E
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AC01E
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080AC01E:
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _080AC076
	ldrb r1, [r5, 0x1C]
	movs r2, 0x90
	lsls r2, 1
	adds r0, r5, r2
	movs r3, 0
	strb r1, [r0]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x96
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x98
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r5, r2
	adds r2, 0x4
	adds r0, r5, r2
	str r3, [r0]
	str r3, [r1]
_080AC076:
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _080AC0C0
	movs r0, 0x9F
	lsls r0, 1
	adds r1, r5, r0
	movs r2, 0
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	movs r3, 0x6
	ldrsh r2, [r5, r3]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r3, [r1]
	adds r1, r7, 0
	bl sub_80A75CC
_080AC0C0:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AC154
	mov r0, r9
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl sub_809D600
	adds r6, r4, 0
	mov r1, r8
	ldr r2, [r1, 0xC]
	cmp r2, 0
	bne _080AC0F2
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	bl sub_80A66A4
	lsls r0, 24
	ldr r2, _080AC158
	cmp r0, 0
	beq _080AC0F2
	ldr r2, _080AC15C
_080AC0F2:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_809D6D8
	adds r1, r4, 0
	mov r3, r8
	ldr r2, [r3, 0x10]
	cmp r2, 0
	bne _080AC108
	ldr r0, _080AC160
	ldr r2, [r0, 0x38]
_080AC108:
	adds r0, r1, 0
	movs r1, 0x2
	bl sub_809D6D8
	mov r0, r8
	ldr r2, [r0, 0x14]
	cmp r2, 0
	bne _080AC11C
	ldr r0, _080AC160
	ldr r2, [r0, 0x68]
_080AC11C:
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_809D6D8
	mov r1, r8
	ldr r2, [r1, 0x8]
	cmp r2, 0
	beq _080AC140
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r3, _080AC164
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
_080AC140:
	adds r0, r7, 0
_080AC142:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC154: .4byte gUnknown_81182A0
_080AC158: .4byte gUnknown_81182F4
_080AC15C: .4byte gUnknown_8118350
_080AC160: .4byte gUnknown_812F1F8
_080AC164: .4byte gUnknown_81184A4
	thumb_func_end GroundObject_Add

	thumb_func_start GroundObject_Delete
GroundObject_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080AC1A4
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AC1A8
	movs r0, 0
	bl Log
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A7658
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080AC1AC
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC1A4: .4byte gUnknown_3001B88
_080AC1A8: .4byte gUnknown_81184B0
_080AC1AC: .4byte 0x0000ffff
	thumb_func_end GroundObject_Delete

	thumb_func_start sub_80AC1B0
sub_80AC1B0:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC1F0
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC1EA
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r2, r3
	bl sub_80A6688
_080AC1EA:
	pop {r0}
	bx r0
	.align 2, 0
_080AC1F0: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC1B0

	thumb_func_start sub_80AC1F4
sub_80AC1F4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC238
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC232
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, _080AC23C
	eors r0, r4
	ldr r1, [r2]
	ands r1, r0
	str r1, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	bl sub_80A6688
_080AC232:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AC238: .4byte gUnknown_3001B88
_080AC23C: .4byte 0x337fffff
	thumb_func_end sub_80AC1F4

	thumb_func_start sub_80AC240
sub_80AC240:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC268
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC26C
	movs r0, 0
	b _080AC270
	.align 2, 0
_080AC268: .4byte gUnknown_3001B88
_080AC26C:
	adds r0, r2, 0
	adds r0, 0x38
_080AC270:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC240

	thumb_func_start sub_80AC274
sub_80AC274:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080AC2A0
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC2A4
	movs r0, 0
	b _080AC2B4
	.align 2, 0
_080AC2A0: .4byte gUnknown_3001B88
_080AC2A4:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080AC2B4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC274

	thumb_func_start GroundObject_ExecuteScript
GroundObject_ExecuteScript:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	asrs r3, 16
	ldr r1, _080AC2F4
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AC2F8
	movs r0, 0
	adds r2, r3, 0
	bl Log
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC2FC
	movs r0, 0
	b _080AC314
	.align 2, 0
_080AC2F4: .4byte gUnknown_3001B88
_080AC2F8: .4byte gUnknown_81184CC
_080AC2FC:
	adds r0, r4, 0
	adds r0, 0x38
	ldr r3, _080AC31C
	adds r1, r5, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AC314:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AC31C: .4byte gUnknown_8118504
	thumb_func_end GroundObject_ExecuteScript

	thumb_func_start sub_80AC320
sub_80AC320:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080AC374
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080AC33A:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080AC352
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AC352:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AC33A
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC374: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC320

	thumb_func_start sub_80AC378
sub_80AC378:
	push {r4-r7,lr}
	ldr r0, _080AC3BC
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080AC388:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080AC39E
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AC39E:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AC388
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AC3BC: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC378

	thumb_func_start sub_80AC3C0
sub_80AC3C0:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC3DC
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AC3DC: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC3C0

	thumb_func_start sub_80AC3E0
sub_80AC3E0:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AC404
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AC404: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC3E0

	thumb_func_start sub_80AC408
sub_80AC408:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC434
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC438
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080AC440
	.align 2, 0
_080AC434: .4byte gUnknown_3001B88
_080AC438:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080AC440:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AC408

	thumb_func_start sub_80AC448
sub_80AC448:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AC474
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AC478
	movs r0, 0
	str r0, [r3]
	b _080AC492
	.align 2, 0
_080AC474: .4byte gUnknown_3001B88
_080AC478:
	movs r1, 0x92
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080AC492:
	str r0, [r3, 0x4]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AC448

	thumb_func_start sub_80AC49C
sub_80AC49C:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AC4C4
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80AC6AC
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AC4C4: .4byte gUnknown_3001B88
	thumb_func_end sub_80AC49C

	thumb_func_start sub_80AC4C8
sub_80AC4C8:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _080AC530
	ldr r3, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r6, 0x80
	lsls r6, 9
_080AC4DE:
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r0, r12
	beq _080AC534
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	ands r0, r7
	cmp r0, 0
	beq _080AC534
	adds r1, 0x8
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r1, r0
	bge _080AC534
	movs r1, 0x96
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	ble _080AC534
	movs r1, 0x94
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _080AC534
	movs r1, 0x98
	lsls r1, 1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080AC534
	adds r0, r5, 0
	b _080AC54C
	.align 2, 0
_080AC530: .4byte gUnknown_3001B88
_080AC534:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r5, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r3, r0
	cmp r5, 0xF
	ble _080AC4DE
	movs r0, 0x1
	negs r0, r0
_080AC54C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC4C8

	thumb_func_start sub_80AC554
sub_80AC554:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	mov r10, r1
	adds r4, r2, 0
	ldr r0, _080AC5C8
	ldr r0, [r0]
	mov r12, r0
	movs r6, 0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	movs r7, 0x80
	lsls r7, 9
_080AC576:
	mov r1, r12
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r0, r9
	beq _080AC5CC
	movs r0, 0x8E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	mov r5, r8
	ands r0, r5
	cmp r0, 0
	beq _080AC5CC
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	mov r5, r12
	ldr r0, [r5, 0x14]
	adds r2, r1, r0
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	ldr r1, [r0]
	ldr r0, [r5, 0x18]
	adds r3, r1, r0
	ldr r0, [r4]
	cmp r2, r0
	bge _080AC5CC
	mov r1, r10
	ldr r0, [r1]
	cmp r2, r0
	ble _080AC5CC
	ldr r0, [r4, 0x4]
	cmp r3, r0
	bge _080AC5CC
	ldr r0, [r1, 0x4]
	cmp r3, r0
	ble _080AC5CC
	adds r0, r6, 0
	b _080AC5E4
	.align 2, 0
_080AC5C8: .4byte gUnknown_3001B88
_080AC5CC:
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 9
	adds r7, r2
	asrs r6, r0, 16
	movs r5, 0xE2
	lsls r5, 1
	add r12, r5
	cmp r6, 0xF
	ble _080AC576
	movs r0, 0x1
	negs r0, r0
_080AC5E4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC554

	thumb_func_start sub_80AC5F4
sub_80AC5F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r0, [r5]
	cmp r0, 0
	bge _080AC60C
	ldr r1, _080AC670
	adds r0, r1
_080AC60C:
	asrs r0, 11
	mov r12, r0
	str r0, [sp]
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _080AC61C
	ldr r3, _080AC670
	adds r0, r3
_080AC61C:
	asrs r4, r0, 11
	str r4, [sp, 0x4]
	ldr r3, [r6]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080AC62C
	ldr r7, _080AC674
	adds r0, r3, r7
_080AC62C:
	asrs r1, r0, 11
	ldr r3, [r6, 0x4]
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080AC63A
	ldr r7, _080AC674
	adds r0, r3, r7
_080AC63A:
	asrs r2, r0, 11
	mov r3, r12
	subs r0, r1, r3
	adds r0, 0x1
	str r0, [sp, 0x8]
	subs r0, r2, r4
	adds r0, 0x1
	add r2, sp, 0x8
	str r0, [r2, 0x4]
	movs r0, 0x8E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080AC678
	mov r0, sp
	adds r1, r2, 0
	bl sub_80A585C
	lsls r0, 24
	cmp r0, 0
	beq _080AC678
	movs r0, 0x1
	b _080AC6A0
	.align 2, 0
_080AC670: .4byte 0x000007ff
_080AC674: .4byte 0x000007fe
_080AC678:
	movs r0, 0x8E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080AC69E
	movs r0, 0x1
	negs r0, r0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80A92A0
	lsls r0, 16
	cmp r0, 0
	blt _080AC69E
	movs r0, 0x4
	b _080AC6A0
_080AC69E:
	movs r0, 0
_080AC6A0:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC5F4

	thumb_func_start sub_80AC6AC
sub_80AC6AC:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r2, [r1]
	ldr r4, [r5, 0x14]
	subs r0, r2, r4
	str r0, [sp]
	ldr r3, [r1, 0x4]
	ldr r1, [r5, 0x18]
	subs r0, r3, r1
	str r0, [sp, 0x4]
	adds r2, r4
	str r2, [sp, 0x8]
	adds r3, r1
	add r2, sp, 0x8
	str r3, [r2, 0x4]
	ldr r1, [r5, 0x28]
	ldr r0, [sp]
	cmp r0, r1
	blt _080AC6EA
	ldr r1, [r5, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	bge _080AC6EA
	ldr r1, [r5, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	blt _080AC6EA
	ldr r0, [r5, 0x34]
	cmp r3, r0
	blt _080AC6EE
_080AC6EA:
	movs r0, 0x1
	b _080AC718
_080AC6EE:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80AC5F4
	cmp r0, 0
	bne _080AC718
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0
_080AC718:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC6AC

	thumb_func_start sub_80AC720
sub_80AC720:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r4, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r2, [r1]
	adds r0, r2
	str r0, [sp]
	movs r3, 0x94
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r0, r1
	str r0, [sp, 0x4]
	adds r3, 0x4
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, r2
	str r0, [sp, 0x8]
	movs r2, 0x98
	lsls r2, 1
	adds r0, r4, r2
	ldr r0, [r0]
	adds r0, r1
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	movs r5, 0
	ldr r3, [r4, 0x28]
	ldr r0, [sp]
	adds r2, r1, 0
	cmp r0, r3
	bge _080AC770
	str r3, [sp]
	ldr r0, [r4, 0xC]
	adds r0, r3, r0
	str r0, [sp, 0x8]
	b _080AC780
_080AC770:
	ldr r1, [r4, 0x30]
	ldr r0, [sp, 0x8]
	cmp r0, r1
	blt _080AC782
	ldr r0, [r4, 0xC]
	subs r0, r1, r0
	str r0, [sp]
	str r1, [sp, 0x8]
_080AC780:
	movs r5, 0x1
_080AC782:
	ldr r1, [r4, 0x2C]
	ldr r0, [sp, 0x4]
	cmp r0, r1
	bge _080AC794
	str r1, [sp, 0x4]
	ldr r0, [r4, 0x10]
	adds r0, r1, r0
	str r0, [r2, 0x4]
	b _080AC7A4
_080AC794:
	ldr r1, [r4, 0x34]
	ldr r0, [r2, 0x4]
	cmp r0, r1
	blt _080AC7A6
	ldr r0, [r4, 0x10]
	subs r0, r1, r0
	str r0, [sp, 0x4]
	str r1, [r2, 0x4]
_080AC7A4:
	movs r5, 0x1
_080AC7A6:
	adds r0, r4, 0
	mov r1, sp
	bl sub_80AC5F4
	cmp r0, 0
	bne _080AC7D8
	movs r3, 0x92
	lsls r3, 1
	adds r2, r4, r3
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r4, r0
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r5, 0
	bne _080AC7D6
	movs r0, 0
	b _080AC7D8
_080AC7D6:
	movs r0, 0x1
_080AC7D8:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80AC720

	thumb_func_start sub_80AC7E0
sub_80AC7E0:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AC7E0

	thumb_func_start sub_80AC7E8
sub_80AC7E8:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AC7E8

	thumb_func_start sub_80AC7F4
sub_80AC7F4:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AC834
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AC89A
_080AC834:
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AC896
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AC896:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AC89A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC7F4

	thumb_func_start sub_80AC8A0
sub_80AC8A0:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC8A0

	thumb_func_start sub_80AC8B8
sub_80AC8B8:
	adds r3, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AC8B8

	thumb_func_start sub_80AC8D8
sub_80AC8D8:
	push {lr}
	bl sub_80AC6AC
	pop {r1}
	bx r1
	thumb_func_end sub_80AC8D8

	thumb_func_start sub_80AC8E4
sub_80AC8E4:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC8E4

	thumb_func_start sub_80AC904
sub_80AC904:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AC904

	thumb_func_start sub_80AC910
sub_80AC910:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AC910

	thumb_func_start sub_80AC91C
sub_80AC91C:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AC934
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AC934:
	pop {r0}
	bx r0
	thumb_func_end sub_80AC91C

	thumb_func_start sub_80AC938
sub_80AC938:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AC958
	ldr r1, _080AC954
	lsls r0, 1
	adds r0, r1
	b _080AC95E
	.align 2, 0
_080AC954: .4byte gUnknown_81183A0
_080AC958:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AC95E:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AC97C
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AC98C
_080AC97C:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AC990
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AC98C:
	movs r0, 0x1
	strb r0, [r1]
_080AC990:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AC938

	thumb_func_start sub_80AC998
sub_80AC998:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AC9AA
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AC9AA:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AC998

	thumb_func_start sub_80AC9B8
sub_80AC9B8:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AC9D6
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AC9D8
_080AC9D6:
	movs r0, 0x1
_080AC9D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC9B8

	thumb_func_start sub_80AC9DC
sub_80AC9DC:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AC9FE
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080ACA00
_080AC9FE:
	movs r0, 0x1
_080ACA00:
	pop {r1}
	bx r1
	thumb_func_end sub_80AC9DC

	thumb_func_start sub_80ACA04
sub_80ACA04:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80ACA04

	thumb_func_start sub_80ACA10
sub_80ACA10:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1B0
	pop {r0}
	bx r0
	thumb_func_end sub_80ACA10

	thumb_func_start sub_80ACA20
sub_80ACA20:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AC1F4
	pop {r0}
	bx r0
	thumb_func_end sub_80ACA20

	thumb_func_start sub_80ACA30
sub_80ACA30:
	push {lr}
	bl sub_80AC720
	pop {r1}
	bx r1
	thumb_func_end sub_80ACA30

	thumb_func_start GroundObject_Action
GroundObject_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080ACA7C
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080ACA54:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080ACAB2
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080ACA80
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080ACA84
	cmp r0, 0x4
	bne _080ACA90
	adds r0, r7, 0
	bl GroundObject_Delete
	b _080ACAB2
	.align 2, 0
_080ACA7C: .4byte gUnknown_3001B88
_080ACA80: .4byte gUnknown_8118524
_080ACA84:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080ACAD0
	bl sub_809D8C0
_080ACA90:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080ACAB2
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080ACAB2:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080ACA54
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAD0: .4byte gUnknown_8118530
	thumb_func_end GroundObject_Action

	thumb_func_start sub_80ACAD4
sub_80ACAD4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080ACB8C
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080ACAF2:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080ACB64
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080ACB40
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080ACB40:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080ACB5A
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080ACB5A:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7664
_080ACB64:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080ACAF2
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACB8C: .4byte gUnknown_3001B88
	thumb_func_end sub_80ACAD4

	thumb_func_start sub_80ACB90
sub_80ACB90:
	push {r4,r5,lr}
	ldr r4, _080ACBCC
	movs r0, 0xE2
	lsls r0, 5
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080ACBD0
	adds r5, r0, 0
	movs r4, 0xE2
	lsls r4, 1
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080ACBB0:
	ldrh r0, [r1, 0x6]
	orrs r0, r5
	strh r0, [r1, 0x6]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, r4
	cmp r0, 0xF
	ble _080ACBB0
	bl sub_80ACBD4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ACBCC: .4byte gUnknown_3001B8C
_080ACBD0: .4byte 0x0000ffff
	thumb_func_end sub_80ACB90

	thumb_func_start sub_80ACBD4
sub_80ACBD4:
	push {r4-r6,lr}
	ldr r0, _080ACC0C
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080ACBE4:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080ACBF2
	adds r0, r1, 0
	bl GroundEffect_Delete
_080ACBF2:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ACBE4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC0C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80ACBD4

	thumb_func_start sub_80ACC10
sub_80ACC10:
	push {r4,lr}
	bl sub_80ACBD4
	ldr r4, _080ACC28
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC28: .4byte gUnknown_3001B8C
	thumb_func_end sub_80ACC10

	thumb_func_start GroundEffect_Select
GroundEffect_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ACC90
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ACC94
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x14]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	ble _080ACC86
	adds r4, r0, 0
_080ACC70:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundEffect_Add
	subs r4, 0x1
	adds r5, 0xC
	cmp r4, 0
	bne _080ACC70
_080ACC86:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACC90: .4byte gUnknown_8118610
_080ACC94: .4byte gUnknown_811861C
	thumb_func_end GroundEffect_Select

	thumb_func_start GroundEffect_Cancel
GroundEffect_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ACD00
	movs r0, 0
	adds r2, r7, 0
	bl Log
	movs r1, 0
	ldr r0, _080ACD04
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ACCC0:
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ACCE2
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ACCE2
	cmp r5, 0
	blt _080ACCDC
	movs r0, 0xA
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ACCE2
_080ACCDC:
	adds r0, r1, 0
	bl GroundEffect_Delete
_080ACCE2:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	movs r2, 0xE2
	lsls r2, 1
	adds r4, r2
	cmp r1, 0xF
	ble _080ACCC0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD00: .4byte gUnknown_8118640
_080ACD04: .4byte gUnknown_3001B8C
	thumb_func_end GroundEffect_Cancel

	thumb_func_start GroundEffect_CancelBlank
GroundEffect_CancelBlank:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r1, _080ACD7C
	movs r0, 0
	bl Log
	movs r6, 0
	ldr r0, _080ACD80
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x92
	lsls r1, 1
	adds r5, r4, r1
	mov r7, sp
_080ACD2C:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080ACD5C
	ldr r0, [r5]
	ldr r1, [r4, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x18]
	adds r0, r1
	str r0, [r7, 0x4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	mov r1, sp
	bl sub_80A675C
	lsls r0, 24
	cmp r0, 0
	bne _080ACD5C
	adds r0, r6, 0
	bl GroundEffect_Delete
_080ACD5C:
	adds r0, r6, 0x1
	lsls r0, 16
	asrs r6, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r0
	adds r4, r0
	cmp r6, 0xF
	ble _080ACD2C
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACD7C: .4byte gUnknown_8118658
_080ACD80: .4byte gUnknown_3001B8C
	thumb_func_end GroundEffect_CancelBlank

	thumb_func_start sub_80ACD84
sub_80ACD84:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	ldr r0, _080ACDA8
	ldr r1, [r0]
	movs r6, 0xE2
	lsls r6, 1
	movs r2, 0x80
	lsls r2, 9
	adds r5, r2, 0
_080ACD9A:
	movs r7, 0x6
	ldrsh r0, [r1, r7]
	cmp r0, r4
	bne _080ACDAC
	adds r0, r3, 0
	b _080ACDBC
	.align 2, 0
_080ACDA8: .4byte gUnknown_3001B8C
_080ACDAC:
	adds r0, r2, 0
	adds r2, r5
	asrs r3, r0, 16
	adds r1, r6
	cmp r3, 0xF
	ble _080ACD9A
	movs r0, 0x1
	negs r0, r0
_080ACDBC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ACD84

	thumb_func_start GroundEffect_Add
GroundEffect_Add:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r7, r1, 0
	lsls r0, 16
	asrs r6, r0, 16
	lsls r2, 16
	asrs r2, 16
	mov r10, r2
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldrb r0, [r7]
	lsls r0, 2
	ldr r1, _080ACE08
	adds r0, r1
	mov r8, r0
	ldr r3, _080ACE0C
	cmp r6, 0
	bge _080ACE38
	movs r2, 0
	ldr r5, [r3]
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	movs r6, 0
	b _080ACE38
	.align 2, 0
_080ACE08: .4byte gUnknown_811EE38
_080ACE0C: .4byte gUnknown_3001B8C
_080ACE10:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r5, r1
	cmp r2, 0xF
	bgt _080ACE2E
	movs r4, 0x6
	ldrsh r1, [r5, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE10
	adds r6, r2, 0
_080ACE2E:
	cmp r6, 0
	bge _080ACE38
	movs r0, 0x1
	negs r0, r0
	b _080AD062
_080ACE38:
	lsls r0, r6, 3
	subs r0, r6
	lsls r0, 4
	adds r0, r6
	lsls r0, 2
	ldr r1, [r3]
	adds r5, r1, r0
	ldr r1, _080ACE9C
	ldrb r3, [r7]
	mov r2, r8
	movs r4, 0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	mov r0, r10
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	movs r0, 0
	adds r2, r6, 0
	bl Log
	movs r2, 0
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ACE72
	movs r2, 0x1
_080ACE72:
	str r2, [sp, 0xC]
	strh r6, [r5, 0x4]
	ldrb r0, [r7]
	strh r0, [r5, 0x6]
	mov r4, r10
	strh r4, [r5, 0x8]
	mov r0, r9
	strb r0, [r5, 0xA]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _080ACEEC
	lsls r0, 2
	ldr r1, _080ACEA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ACE9C: .4byte gUnknown_8118674
_080ACEA0: .4byte _080ACEA4
	.align 2, 0
_080ACEA4:
	.4byte _080ACEB8
	.4byte _080ACEEC
	.4byte _080ACEC4
	.4byte _080ACED0
	.4byte _080ACEDC
_080ACEB8:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	movs r0, 0x81
	lsls r0, 22
	b _080ACEF4
_080ACEC4:
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r5, r4
	movs r0, 0x83
	lsls r0, 18
	b _080ACEF4
_080ACED0:
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x88
	lsls r0, 22
	b _080ACEF4
_080ACEDC:
	movs r2, 0x8E
	lsls r2, 1
	adds r1, r5, r2
	ldr r0, _080ACEE8
	b _080ACEF4
	.align 2, 0
_080ACEE8: .4byte 0x22020000
_080ACEEC:
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r5, r3
	ldr r0, _080ACF08
_080ACEF4:
	str r0, [r1]
	mov r4, r8
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _080ACF0C
	ldrb r0, [r7, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r7, 0x3]
	b _080ACF16
	.align 2, 0
_080ACF08: .4byte 0x220c0000
_080ACF0C:
	mov r1, r8
	ldrb r0, [r1, 0x2]
	lsls r0, 11
	str r0, [r5, 0xC]
	ldrb r0, [r1, 0x3]
_080ACF16:
	lsls r0, 11
	str r0, [r5, 0x10]
	ldr r0, [r5, 0xC]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x14]
	ldr r0, [r5, 0x10]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r5, 0x18]
	ldrb r0, [r7, 0x1]
	strb r0, [r5, 0x1C]
	adds r2, r7, 0x4
	adds r4, r5, 0
	adds r4, 0x20
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF5A
	ldrb r0, [r7, 0x4]
	lsls r3, r0, 11
	str r3, [r5, 0x20]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF5A
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r5, 0x20]
_080ACF5A:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080ACF7C
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080ACF7C
	movs r2, 0x80
	lsls r2, 3
	adds r0, r3, r2
	str r0, [r4, 0x4]
_080ACF7C:
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _080ACFD2
	ldrb r1, [r5, 0x1C]
	movs r4, 0x90
	lsls r4, 1
	adds r0, r5, r4
	movs r3, 0
	strb r1, [r0]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r1, 0x96
	lsls r1, 1
	adds r2, r5, r1
	ldr r0, [r5, 0x20]
	ldr r1, [r5, 0x14]
	adds r0, r1
	str r0, [r2]
	adds r4, 0x8
	adds r2, r5, r4
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r5, r0
	ldr r0, [r5, 0x24]
	ldr r1, [r5, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r5, r2
	adds r4, 0x10
	adds r0, r5, r4
	str r3, [r0]
	str r3, [r1]
_080ACFD2:
	adds r0, r5, 0
	adds r0, 0x28
	adds r1, r5, 0
	adds r1, 0x30
	bl sub_80A5778
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080AD01A
	movs r2, 0x9F
	lsls r2, 1
	adds r1, r5, r2
	movs r2, 0
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r4, 0xA0
	lsls r4, 1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	movs r3, 0x6
	ldrsh r2, [r5, r3]
	subs r4, 0x24
	adds r1, r5, r4
	ldr r3, [r1]
	adds r1, r6, 0
	bl sub_80A7688
_080AD01A:
	adds r4, r5, 0
	adds r4, 0x38
	ldr r1, _080AD074
	mov r0, r9
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	mov r3, r10
	bl sub_809D600
	ldr r2, [r7, 0x8]
	cmp r2, 0
	bne _080AD04C
	mov r1, r8
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x1
	bne _080AD048
	ldr r0, _080AD078
	movs r1, 0xB0
	lsls r1, 2
	adds r0, r1
	ldr r2, [r0]
_080AD048:
	cmp r2, 0
	beq _080AD060
_080AD04C:
	adds r0, r4, 0
	movs r1, 0
	bl sub_809D6D8
	ldr r3, _080AD07C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl sub_809D8C0
_080AD060:
	adds r0, r6, 0
_080AD062:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD074: .4byte gUnknown_8118544
_080AD078: .4byte gUnknown_812F1F8
_080AD07C: .4byte gUnknown_81186CC
	thumb_func_end GroundEffect_Add

	thumb_func_start GroundEffect_Delete
GroundEffect_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _080AD0BC
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 4
	adds r0, r2
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD0C0
	movs r0, 0
	bl Log
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r4, r1
	bl sub_80A7714
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D648
	ldr r0, _080AD0C4
	strh r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD0BC: .4byte gUnknown_3001B8C
_080AD0C0: .4byte gUnknown_81186D8
_080AD0C4: .4byte 0x0000ffff
	thumb_func_end GroundEffect_Delete

	thumb_func_start sub_80AD0C8
sub_80AD0C8:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD108
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD102
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	movs r3, 0xA2
	lsls r3, 1
	adds r0, r2, r3
	bl sub_80A6688
_080AD102:
	pop {r0}
	bx r0
	.align 2, 0
_080AD108: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD0C8

	thumb_func_start sub_80AD10C
sub_80AD10C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD150
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r3, r0, r1
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD14A
	movs r0, 0x8E
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, _080AD154
	eors r0, r4
	ldr r1, [r2]
	ands r1, r0
	str r1, [r2]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r3, r2
	bl sub_80A6688
_080AD14A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD150: .4byte gUnknown_3001B8C
_080AD154: .4byte 0x337fffff
	thumb_func_end sub_80AD10C

	thumb_func_start sub_80AD158
sub_80AD158:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD180
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD184
	movs r0, 0
	b _080AD188
	.align 2, 0
_080AD180: .4byte gUnknown_3001B8C
_080AD184:
	adds r0, r2, 0
	adds r0, 0x38
_080AD188:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD158

	thumb_func_start sub_80AD18C
sub_80AD18C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	lsls r2, 16
	asrs r3, r2, 16
	ldr r2, _080AD1B8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD1BC
	movs r0, 0
	b _080AD1CC
	.align 2, 0
_080AD1B8: .4byte gUnknown_3001B8C
_080AD1BC:
	adds r0, r2, 0
	adds r0, 0x38
	adds r1, r4, 0
	adds r2, r3, 0
	bl sub_809D6E4
	lsls r0, 24
	lsrs r0, 24
_080AD1CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD18C

	thumb_func_start GroundEffect_ExecuteScript
GroundEffect_ExecuteScript:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	asrs r3, 16
	ldr r1, _080AD20C
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 4
	adds r0, r3
	lsls r0, 2
	ldr r1, [r1]
	adds r4, r1, r0
	ldr r1, _080AD210
	movs r0, 0
	adds r2, r3, 0
	bl Log
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD214
	movs r0, 0
	b _080AD22C
	.align 2, 0
_080AD20C: .4byte gUnknown_3001B8C
_080AD210: .4byte gUnknown_81186F4
_080AD214:
	adds r0, r4, 0
	adds r0, 0x38
	ldr r3, _080AD234
	adds r1, r5, 0
	adds r2, r6, 0
	bl GroundScript_ExecutePP
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD22C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AD234: .4byte gUnknown_811872C
	thumb_func_end GroundEffect_ExecuteScript

	thumb_func_start sub_80AD238
sub_80AD238:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, _080AD28C
	ldr r4, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080AD252:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r8
	beq _080AD26A
	adds r0, r4, 0
	adds r0, 0x38
	adds r1, r7, 0
	bl sub_809D968
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD26A:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD252
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD28C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD238

	thumb_func_start sub_80AD290
sub_80AD290:
	push {r4-r7,lr}
	ldr r0, _080AD2D4
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
	movs r6, 0x80
	lsls r6, 9
_080AD2A0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, r7
	beq _080AD2B6
	adds r0, r4, 0
	adds r0, 0x38
	bl sub_809D92C
	orrs r5, r0
	lsls r0, r5, 24
	lsrs r5, r0, 24
_080AD2B6:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r0, 16
	movs r1, 0xE2
	lsls r1, 1
	adds r4, r1
	cmp r0, 0xF
	ble _080AD2A0
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AD2D4: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD290

	thumb_func_start sub_80AD2D8
sub_80AD2D8:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD2F4
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD2F4: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD2D8

	thumb_func_start sub_80AD2F8
sub_80AD2F8:
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD31C
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, [r3]
	adds r0, r2
	movs r3, 0x8E
	lsls r3, 1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [r1]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080AD31C: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD2F8

	thumb_func_start sub_80AD320
sub_80AD320:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD34C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD350
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
	b _080AD358
	.align 2, 0
_080AD34C: .4byte gUnknown_3001B8C
_080AD350:
	ldr r0, [r2, 0xC]
	ldr r1, [r2, 0x10]
	str r0, [r3]
	str r1, [r3, 0x4]
_080AD358:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD320

	thumb_func_start sub_80AD360
sub_80AD360:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _080AD38C
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, [r2]
	adds r2, r0, r1
	movs r0, 0x6
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080AD390
	movs r0, 0
	str r0, [r3]
	b _080AD3AA
	.align 2, 0
_080AD38C: .4byte gUnknown_3001B8C
_080AD390:
	movs r1, 0x92
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x14]
	adds r0, r1
	str r0, [r3]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, [r2, 0x18]
	adds r0, r1
_080AD3AA:
	str r0, [r3, 0x4]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80AD360

	thumb_func_start sub_80AD3B4
sub_80AD3B4:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r3, _080AD3DC
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 4
	adds r2, r0
	lsls r2, 2
	ldr r4, [r3]
	adds r4, r2
	adds r0, r4, 0
	bl sub_80AD3E0
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD3DC: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD3B4

	thumb_func_start sub_80AD3E0
sub_80AD3E0:
	push {r4-r7,lr}
	mov r12, r0
	ldr r3, [r1]
	ldr r2, [r0, 0x14]
	subs r6, r3, r2
	ldr r1, [r1, 0x4]
	ldr r0, [r0, 0x18]
	subs r7, r1, r0
	adds r4, r3, r2
	adds r5, r1, r0
	mov r1, r12
	ldr r0, [r1, 0x28]
	cmp r6, r0
	blt _080AD40E
	ldr r0, [r1, 0x30]
	cmp r4, r0
	bge _080AD40E
	ldr r0, [r1, 0x2C]
	cmp r7, r0
	blt _080AD40E
	ldr r0, [r1, 0x34]
	cmp r5, r0
	blt _080AD412
_080AD40E:
	movs r0, 0x1
	b _080AD428
_080AD412:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r6, [r0]
	str r7, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	str r5, [r0, 0x4]
	movs r0, 0
_080AD428:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD3E0

	thumb_func_start sub_80AD430
sub_80AD430:
	push {r4-r6,lr}
	mov r12, r0
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r2, [r1]
	adds r5, r0, r2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	ldr r1, [r1, 0x4]
	adds r6, r0, r1
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r3, r0, r2
	movs r0, 0x98
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	adds r4, r0, r1
	mov r0, r12
	ldr r1, [r0, 0x28]
	cmp r5, r1
	bge _080AD470
	adds r5, r1, 0
	ldr r0, [r0, 0xC]
	adds r3, r1, r0
	b _080AD47E
_080AD470:
	mov r2, r12
	ldr r1, [r2, 0x30]
	cmp r3, r1
	blt _080AD47E
	ldr r0, [r2, 0xC]
	subs r5, r1, r0
	adds r3, r1, 0
_080AD47E:
	mov r0, r12
	ldr r1, [r0, 0x2C]
	cmp r6, r1
	bge _080AD48E
	adds r6, r1, 0
	ldr r0, [r0, 0x10]
	adds r4, r1, r0
	b _080AD49C
_080AD48E:
	mov r2, r12
	ldr r1, [r2, 0x34]
	cmp r4, r1
	blt _080AD49C
	ldr r0, [r2, 0x10]
	subs r6, r1, r0
	adds r4, r1, 0
_080AD49C:
	movs r0, 0x92
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	str r6, [r0, 0x4]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	str r4, [r0, 0x4]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80AD430

	thumb_func_start sub_80AD4B8
sub_80AD4B8:
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_80AD4B8

	thumb_func_start sub_80AD4C0
sub_80AD4C0:
	ldr r2, [r0, 0xC]
	ldr r3, [r0, 0x10]
	str r2, [r1]
	str r3, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AD4C0

	thumb_func_start sub_80AD4CC
sub_80AD4CC:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080AD50C
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4]
	ldr r0, [r3, 0x14]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x14]
	adds r1, r0
	str r1, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r1, [r4, 0x4]
	ldr r0, [r3, 0x18]
	subs r0, r1, r0
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x18]
	adds r1, r0
	str r1, [r2]
	b _080AD572
_080AD50C:
	movs r0, 0x92
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x96
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x20]
	ldr r1, [r3, 0x14]
	adds r0, r1
	str r0, [r2]
	movs r0, 0x94
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	subs r0, r1
	str r0, [r2]
	movs r0, 0x98
	lsls r0, 1
	adds r2, r3, r0
	ldr r0, [r3, 0x24]
	ldr r1, [r3, 0x18]
	adds r0, r1
	str r0, [r2]
	movs r2, 0x9A
	lsls r2, 1
	adds r1, r3, r2
	adds r2, 0x4
	adds r0, r3, r2
	str r4, [r0]
	str r4, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r2, r3, r0
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r0, 0x1C
	ldrsb r0, [r3, r0]
	cmp r1, r0
	beq _080AD56E
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	movs r0, 0x1
	strb r0, [r1]
_080AD56E:
	ldrb r0, [r3, 0x1C]
	strb r0, [r2]
_080AD572:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD4CC

	thumb_func_start sub_80AD578
sub_80AD578:
	push {r4,lr}
	ldr r3, [r1]
	ldr r4, [r1, 0x4]
	str r3, [r0, 0x28]
	str r4, [r0, 0x2C]
	ldr r1, [r2]
	ldr r2, [r2, 0x4]
	str r1, [r0, 0x30]
	str r2, [r0, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD578

	thumb_func_start sub_80AD590
sub_80AD590:
	adds r3, r0, 0
	movs r2, 0x92
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x14]
	adds r0, r2
	str r0, [r1]
	movs r2, 0x94
	lsls r2, 1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x18]
	adds r0, r2
	str r0, [r1, 0x4]
	bx lr
	thumb_func_end sub_80AD590

	thumb_func_start sub_80AD5B0
sub_80AD5B0:
	push {lr}
	bl sub_80AD3E0
	pop {r1}
	bx r1
	thumb_func_end sub_80AD5B0

	thumb_func_start sub_80AD5BC
sub_80AD5BC:
	push {r4,lr}
	adds r3, r0, 0
	movs r4, 0x9A
	lsls r4, 1
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD5BC

	thumb_func_start sub_80AD5DC
sub_80AD5DC:
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	str r1, [r0]
	bx lr
	thumb_func_end sub_80AD5DC

	thumb_func_start sub_80AD5E8
sub_80AD5E8:
	movs r2, 0x90
	lsls r2, 1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80AD5E8

	thumb_func_start sub_80AD5F4
sub_80AD5F4:
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080AD60C
	movs r3, 0x90
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
_080AD60C:
	pop {r0}
	bx r0
	thumb_func_end sub_80AD5F4

	thumb_func_start sub_80AD610
sub_80AD610:
	push {r4,r5,lr}
	lsls r1, 16
	adds r3, r0, 0
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	cmp r0, 0
	beq _080AD630
	ldr r1, _080AD62C
	lsls r0, 1
	adds r0, r1
	b _080AD636
	.align 2, 0
_080AD62C: .4byte gUnknown_81185F2
_080AD630:
	movs r5, 0x9F
	lsls r5, 1
	adds r0, r3, r5
_080AD636:
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r5, 0x9F
	lsls r5, 1
	adds r1, r3, r5
	ldrh r4, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r2
	beq _080AD654
	strh r2, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r3, r0
	b _080AD664
_080AD654:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r4
	cmp r0, 0
	beq _080AD668
	movs r5, 0x9E
	lsls r5, 1
	adds r1, r3, r5
_080AD664:
	movs r0, 0x1
	strb r0, [r1]
_080AD668:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AD610

	thumb_func_start sub_80AD670
sub_80AD670:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	adds r2, r1, 0
	cmp r1, 0
	bne _080AD682
	movs r1, 0xE0
	lsls r1, 1
	adds r2, r1, 0
_080AD682:
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_80AD670

	thumb_func_start sub_80AD690
sub_80AD690:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080AD6AE
	adds r2, 0x8
	adds r0, r1, r2
	bl sub_80A66F8
	lsls r0, 24
	lsrs r0, 24
	b _080AD6B0
_080AD6AE:
	movs r0, 0x1
_080AD6B0:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD690

	thumb_func_start sub_80AD6B4
sub_80AD6B4:
	push {lr}
	adds r1, r0, 0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r1, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _080AD6D6
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r1, r2
	bl sub_80A671C
	lsls r0, 24
	lsrs r0, 24
	b _080AD6D8
_080AD6D6:
	movs r0, 0x1
_080AD6D8:
	pop {r1}
	bx r1
	thumb_func_end sub_80AD6B4

	thumb_func_start sub_80AD6DC
sub_80AD6DC:
	movs r2, 0x8E
	lsls r2, 1
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	bx lr
	thumb_func_end sub_80AD6DC

	thumb_func_start sub_80AD6E8
sub_80AD6E8:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD0C8
	pop {r0}
	bx r0
	thumb_func_end sub_80AD6E8

	thumb_func_start sub_80AD6F8
sub_80AD6F8:
	push {lr}
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl sub_80AD10C
	pop {r0}
	bx r0
	thumb_func_end sub_80AD6F8

	thumb_func_start sub_80AD708
sub_80AD708:
	push {lr}
	bl sub_80AD430
	pop {r1}
	bx r1
	thumb_func_end sub_80AD708

	thumb_func_start GroundEffect_Action
GroundEffect_Action:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, _080AD754
	ldr r5, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r1, 0x9E
	lsls r1, 1
	adds r6, r5, r1
_080AD72C:
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	cmp r0, r8
	beq _080AD78A
	adds r4, r5, 0
	adds r4, 0x38
	adds r0, r4, 0
	ldr r1, _080AD758
	bl HandleAction
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _080AD75C
	cmp r0, 0x4
	bne _080AD768
	adds r0, r7, 0
	bl GroundEffect_Delete
	b _080AD78A
	.align 2, 0
_080AD754: .4byte gUnknown_3001B8C
_080AD758: .4byte gUnknown_811874C
_080AD75C:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	ldr r3, _080AD7A8
	bl sub_809D8C0
_080AD768:
	ldrb r0, [r6]
	cmp r0, 0
	beq _080AD78A
	movs r0, 0
	strb r0, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	ldrh r2, [r6, 0x2]
	movs r3, 0xF8
	lsls r3, 5
	adds r1, r3, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	bl sub_80A6EFC
_080AD78A:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	movs r0, 0xE2
	lsls r0, 1
	adds r6, r0
	adds r5, r0
	cmp r7, 0xF
	ble _080AD72C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD7A8: .4byte gUnknown_8118758
	thumb_func_end GroundEffect_Action

	thumb_func_start sub_80AD7AC
sub_80AD7AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	ldr r0, _080AD864
	ldr r6, [r0]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x90
	lsls r2, 1
	adds r4, r6, r2
_080AD7CA:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r9
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	beq _080AD83C
	ldr r0, [r4, 0x4]
	ldr r1, [r6, 0x14]
	adds r0, r1
	str r0, [sp]
	ldr r0, [r4, 0x8]
	ldr r1, [r6, 0x18]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r1, [r4, 0x14]
	ldr r0, [r4, 0x18]
	adds r7, r1, r0
	movs r0, 0xA2
	lsls r0, 1
	adds r5, r6, r0
	adds r0, r5, 0
	bl sub_80A66D4
	lsls r0, 24
	cmp r0, 0
	beq _080AD818
	movs r0, 0
	strb r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1E]
	movs r0, 0xF8
	lsls r0, 5
	adds r1, r0, 0
	ands r1, r2
	lsls r2, 24
	asrs r2, 24
	adds r0, r5, 0
	bl sub_80A6EFC
_080AD818:
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080AD832
	adds r1, r0, 0
	movs r2, 0
	ldrsb r2, [r4, r2]
	adds r0, r5, 0
	movs r3, 0
	bl sub_80A7040
	movs r0, 0
	strh r0, [r4, 0x20]
_080AD832:
	adds r0, r5, 0
	mov r1, sp
	adds r2, r7, 0
	bl sub_80A7720
_080AD83C:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0xE2
	lsls r0, 1
	adds r4, r0
	adds r6, r0
	mov r1, r8
	cmp r1, 0xF
	ble _080AD7CA
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD864: .4byte gUnknown_3001B8C
	thumb_func_end sub_80AD7AC

	thumb_func_start sub_80AD868
sub_80AD868:
	ldr r1, _080AD870
	movs r0, 0
	str r0, [r1]
	bx lr
	.align 2, 0
_080AD870: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD868

	thumb_func_start sub_80AD874
sub_80AD874:
	ldr r1, _080AD87C
	movs r0, 0
	str r0, [r1]
	bx lr
	.align 2, 0
_080AD87C: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD874

	thumb_func_start GroundLink_Select
GroundLink_Select:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	ldr r1, _080AD898
	bl sub_80A77D0
	ldr r1, _080AD89C
	ldr r0, [r0, 0x8]
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080AD898: .4byte gUnknown_8118798
_080AD89C: .4byte gUnknown_203B4B8
	thumb_func_end GroundLink_Select

	thumb_func_start sub_80AD8A0
sub_80AD8A0:
	lsls r0, 16
	ldr r1, _080AD8B0
	asrs r0, 13
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_080AD8B0: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD8A0

	thumb_func_start sub_80AD8B4
sub_80AD8B4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	ldr r1, _080AD910
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD8E4
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD8E4
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD8E4:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD906
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD906
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD906:
	ldrb r0, [r2, 0x6]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AD910: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD8B4

	thumb_func_start sub_80AD914
sub_80AD914:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 16
	ldr r1, _080AD98C
	asrs r0, 13
	ldr r1, [r1]
	adds r2, r1, r0
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r4]
	str r1, [r4, 0x4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD94E
	ldrb r0, [r2]
	lsls r3, r0, 11
	str r3, [r4]
	ldrb r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD94E
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4]
_080AD94E:
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080AD970
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 11
	str r3, [r4, 0x4]
	ldrb r1, [r2, 0x3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AD970
	movs r1, 0x80
	lsls r1, 3
	adds r0, r3, r1
	str r0, [r4, 0x4]
_080AD970:
	ldrb r1, [r2, 0x4]
	lsls r1, 11
	ldr r0, [r4]
	adds r0, r1
	str r0, [r5]
	ldrb r1, [r2, 0x5]
	lsls r1, 11
	ldr r0, [r4, 0x4]
	adds r0, r1
	str r0, [r5, 0x4]
	ldrb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AD98C: .4byte gUnknown_203B4B8
	thumb_func_end sub_80AD914

	thumb_func_start sub_80AD990
sub_80AD990:
	push {r4,lr}
	ldr r4, _080AD9C8
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	adds r1, r0, 0
	ldr r0, _080AD9CC
	adds r4, r0, 0
	movs r2, 0x80
	lsls r2, 9
	adds r3, r2, 0
_080AD9AC:
	ldrh r0, [r1, 0x2]
	orrs r0, r4
	strh r0, [r1, 0x2]
	adds r0, r2, 0
	adds r2, r3
	asrs r0, 16
	adds r1, 0x20
	cmp r0, 0x1F
	ble _080AD9AC
	bl sub_80AD9D0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9C8: .4byte gUnknown_3001B90
_080AD9CC: .4byte 0x0000ffff
	thumb_func_end sub_80AD990

	thumb_func_start sub_80AD9D0
sub_80AD9D0:
	push {r4-r6,lr}
	ldr r0, _080ADA04
	ldr r4, [r0]
	movs r1, 0
	movs r6, 0x1
	negs r6, r6
	movs r5, 0x80
	lsls r5, 9
_080AD9E0:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r6
	beq _080AD9EE
	adds r0, r1, 0
	bl GroundEvent_Delete
_080AD9EE:
	adds r0, r5, 0
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	asrs r1, r0, 16
	adds r4, 0x20
	cmp r1, 0x1F
	ble _080AD9E0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA04: .4byte gUnknown_3001B90
	thumb_func_end sub_80AD9D0

	thumb_func_start sub_80ADA08
sub_80ADA08:
	push {r4,lr}
	bl sub_80AD9D0
	ldr r4, _080ADA20
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA20: .4byte gUnknown_3001B90
	thumb_func_end sub_80ADA08

	thumb_func_start GroundEvent_Select
GroundEvent_Select:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	ldr r1, _080ADA88
	adds r0, r4, 0
	bl sub_80A77D0
	adds r5, r0, 0
	ldr r1, _080ADA8C
	str r6, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl Log
	lsls r1, r7, 3
	ldr r0, [r5, 0x4]
	adds r0, r1
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r5, [r0, 0x1C]
	ldr r0, [r0, 0x18]
	cmp r0, 0
	ble _080ADA7E
	adds r4, r0, 0
_080ADA68:
	movs r0, 0x1
	negs r0, r0
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r6, 0
	bl GroundEvent_Add
	subs r4, 0x1
	adds r5, 0xC
	cmp r4, 0
	bne _080ADA68
_080ADA7E:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA88: .4byte gUnknown_81187DC
_080ADA8C: .4byte gUnknown_81187E8
	thumb_func_end GroundEvent_Select

	thumb_func_start GroundEvent_Cancel
GroundEvent_Cancel:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r7, r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	ldr r1, _080ADAF8
	movs r0, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl Log
	movs r1, 0
	ldr r0, _080ADAFC
	ldr r4, [r0]
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	movs r6, 0x80
	lsls r6, 9
_080ADABA:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, r8
	beq _080ADADC
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, r7
	bne _080ADADC
	cmp r5, 0
	blt _080ADAD6
	movs r0, 0x6
	ldrsb r0, [r4, r0]
	cmp r0, r5
	bne _080ADADC
_080ADAD6:
	adds r0, r1, 0
	bl GroundEvent_Delete
_080ADADC:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r1, r0, 16
	adds r4, 0x20
	cmp r1, 0x1F
	ble _080ADABA
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADAF8: .4byte gUnknown_811880C
_080ADAFC: .4byte gUnknown_3001B90
	thumb_func_end GroundEvent_Cancel

	thumb_func_start GroundEvent_Add
GroundEvent_Add:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	lsls r2, 16
	asrs r6, r2, 16
	lsls r3, 24
	asrs r3, 24
	mov r9, r3
	ldr r5, [r1, 0x8]
	cmp r7, 0
	bge _080ADB60
	ldr r0, _080ADB38
	ldr r4, [r0]
	movs r2, 0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADB3C
	movs r7, 0
	b _080ADB68
	.align 2, 0
_080ADB38: .4byte gUnknown_3001B90
_080ADB3C:
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r2, r0, 16
	adds r4, 0x20
	cmp r2, 0x1F
	bgt _080ADB56
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADB3C
	adds r7, r2, 0
_080ADB56:
	cmp r7, 0
	bge _080ADB68
	movs r0, 0x1
	negs r0, r0
	b _080ADC24
_080ADB60:
	ldr r0, _080ADBA0
	lsls r1, r7, 5
	ldr r0, [r0]
	adds r4, r0, r1
_080ADB68:
	ldr r1, _080ADBA4
	movs r0, 0
	ldrsh r3, [r5, r0]
	str r6, [sp]
	mov r2, r9
	str r2, [sp, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x8]
	movs r0, 0
	adds r2, r7, 0
	bl Log
	strh r7, [r4]
	ldrh r0, [r5]
	strh r0, [r4, 0x2]
	strh r6, [r4, 0x4]
	mov r3, r9
	strb r3, [r4, 0x6]
	movs r6, 0x2
	ldrsh r0, [r5, r6]
	cmp r0, 0x1
	blt _080ADBA8
	cmp r0, 0x2
	bgt _080ADBA8
	movs r0, 0x60
	b _080ADBAA
	.align 2, 0
_080ADBA0: .4byte gUnknown_3001B90
_080ADBA4: .4byte gUnknown_8118828
_080ADBA8:
	movs r0, 0x20
_080ADBAA:
	str r0, [r4, 0x8]
	mov r3, r8
	ldrb r0, [r3]
	lsls r1, r0, 11
	ldrb r0, [r3, 0x1]
	lsls r2, r0, 11
	mov r5, r8
	adds r5, 0x4
	add r6, sp, 0xC
	mov r12, r6
	ldrb r6, [r5, 0x2]
	movs r0, 0x4
	ands r0, r6
	cmp r0, 0
	bne _080ADBDE
	ldrb r0, [r3, 0x4]
	lsls r3, r0, 11
	str r3, [sp, 0xC]
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _080ADBDE
	movs r6, 0x80
	lsls r6, 3
	adds r0, r3, r6
	str r0, [sp, 0xC]
_080ADBDE:
	ldrb r6, [r5, 0x3]
	movs r0, 0x4
	ands r0, r6
	cmp r0, 0
	bne _080ADC02
	ldrb r0, [r5, 0x1]
	lsls r3, r0, 11
	mov r0, r12
	str r3, [r0, 0x4]
	movs r0, 0x2
	ands r0, r6
	cmp r0, 0
	beq _080ADC02
	movs r5, 0x80
	lsls r5, 3
	adds r0, r3, r5
	mov r6, r12
	str r0, [r6, 0x4]
_080ADC02:
	ldr r0, [sp, 0xC]
	str r0, [r4, 0xC]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [r4, 0x14]
	ldr r0, [sp, 0x10]
	str r0, [r4, 0x10]
	ldr r0, [sp, 0x10]
	adds r0, r2
	str r0, [r4, 0x18]
	mov r1, r8
	ldr r0, [r1, 0x8]
	ldr r0, [r0, 0x8]
	str r0, [r4, 0x1C]
	bl sub_80A7A78
	adds r0, r7, 0
_080ADC24:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundEvent_Add

	thumb_func_start GroundEvent_Delete
GroundEvent_Delete:
	push {r4,lr}
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	ldr r0, _080ADC58
	lsls r1, r2, 5
	ldr r4, [r0]
	adds r4, r1
	ldr r1, _080ADC5C
	movs r0, 0
	bl Log
	ldr r0, _080ADC60
	strh r0, [r4, 0x2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADC58: .4byte gUnknown_3001B90
_080ADC5C: .4byte gUnknown_811886C
_080ADC60: .4byte 0x0000ffff
	thumb_func_end GroundEvent_Delete

	thumb_func_start sub_80ADC64
sub_80ADC64:
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	ldr r1, _080ADC84
	asrs r0, 11
	ldr r1, [r1]
	adds r2, r1, r0
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080ADC88
	movs r0, 0
	b _080ADC9A
	.align 2, 0
_080ADC84: .4byte gUnknown_3001B90
_080ADC88:
	ldr r0, [r2, 0x1C]
	str r0, [r3]
	movs r0, 0x2
	strh r0, [r3, 0x4]
	ldrh r0, [r2, 0x4]
	strh r0, [r3, 0x6]
	ldrb r0, [r2, 0x6]
	strb r0, [r3, 0x8]
	movs r0, 0x1
_080ADC9A:
	pop {r1}
	bx r1
	thumb_func_end sub_80ADC64

	thumb_func_start sub_80ADCA0
sub_80ADCA0:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _080ADCEC
	ldr r3, [r0]
	movs r5, 0
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r6, 0x80
	lsls r6, 9
_080ADCB6:
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, r12
	beq _080ADCF0
	ldr r0, [r3, 0x8]
	ands r0, r7
	cmp r0, 0
	beq _080ADCF0
	ldr r1, [r3, 0xC]
	ldr r0, [r2]
	cmp r1, r0
	bge _080ADCF0
	ldr r1, [r3, 0x14]
	ldr r0, [r4]
	cmp r1, r0
	ble _080ADCF0
	ldr r1, [r3, 0x10]
	ldr r0, [r2, 0x4]
	cmp r1, r0
	bge _080ADCF0
	ldr r1, [r3, 0x18]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	ble _080ADCF0
	adds r0, r5, 0
	b _080ADD04
	.align 2, 0
_080ADCEC: .4byte gUnknown_3001B90
_080ADCF0:
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 9
	adds r6, r1
	asrs r5, r0, 16
	adds r3, 0x20
	cmp r5, 0x1F
	ble _080ADCB6
	movs r0, 0x1
	negs r0, r0
_080ADD04:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADCA0

	thumb_func_start sub_80ADD0C
sub_80ADD0C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	ldr r0, _080ADD74
	ldr r4, [r0]
	movs r7, 0
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	movs r1, 0x80
	lsls r1, 9
	mov r12, r1
_080ADD2C:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, r9
	beq _080ADD78
	ldr r0, [r4, 0x8]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _080ADD78
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x14]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r2, r0, 1
	ldr r0, [r4, 0x10]
	ldr r1, [r4, 0x18]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r3, r0, 1
	ldr r0, [r5]
	cmp r2, r0
	bge _080ADD78
	ldr r0, [r6]
	cmp r2, r0
	ble _080ADD78
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _080ADD78
	ldr r0, [r6, 0x4]
	cmp r3, r0
	ble _080ADD78
	adds r0, r7, 0
	b _080ADD8C
	.align 2, 0
_080ADD74: .4byte gUnknown_3001B90
_080ADD78:
	mov r0, r12
	movs r1, 0x80
	lsls r1, 9
	add r12, r1
	asrs r7, r0, 16
	adds r4, 0x20
	cmp r7, 0x1F
	ble _080ADD2C
	movs r0, 0x1
	negs r0, r0
_080ADD8C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADD0C

	thumb_func_start nullsub_124
nullsub_124:
	bx lr
	thumb_func_end nullsub_124

	thumb_func_start sub_80ADD9C
sub_80ADD9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp, 0x20]
	str r1, [sp, 0x24]
	str r2, [sp, 0x28]
	str r3, [sp, 0x2C]
	ldr r5, [sp, 0x54]
	ldr r0, [sp, 0x5C]
	mov r9, r0
	movs r0, 0x93
	lsls r0, 4
	movs r1, 0x7
	bl MemoryAlloc
	mov r10, r0
	ldr r0, _080ADEB4
	ldr r7, _080ADEB8
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	add r4, sp, 0x1C
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80901D8
	ldrb r5, [r4]
	ldrb r4, [r4, 0x1]
	cmp r5, 0x3E
	bls _080ADDE2
	movs r5, 0x3E
_080ADDE2:
	cmp r4, 0
	bgt _080ADDE8
	movs r4, 0x1
_080ADDE8:
	adds r0, r5, 0
	bl sub_8090298
	cmp r4, r0
	blt _080ADDFA
	adds r0, r5, 0
	bl sub_8090298
	subs r4, r0, 0x1
_080ADDFA:
	ldr r2, [r6, 0x4]
	ldr r1, [r2]
	lsls r0, r5, 2
	adds r0, r1
	lsls r1, r4, 4
	ldr r0, [r0]
	adds r0, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	mov r8, r0
	adds r0, r6, 0
	bl CloseFile
	ldr r1, _080ADEBC
	ldr r0, _080ADEC0
	add r0, r8
	ldrb r5, [r0]
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	ldr r0, [sp, 0x28]
	movs r1, 0
	adds r2, r4, 0
	bl sub_800AE28
	adds r0, r4, 0
	bl CloseFile
	ldr r1, _080ADEC4
	add r0, sp, 0x10
	mov r2, r8
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFile
	ldr r1, [sp, 0x20]
	str r0, [r1]
	ldr r1, _080ADEC8
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	ldr r1, _080ADECC
	ldr r0, [sp, 0x2C]
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
	mov r2, r8
	cmp r2, 0x3F
	bgt _080ADED4
	ldr r1, _080ADED0
	add r0, sp, 0x10
	adds r2, r5, 0
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	mov r0, r10
	movs r1, 0x93
	lsls r1, 4
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
	b _080ADEFC
	.align 2, 0
_080ADEB4: .4byte gUnknown_8118890
_080ADEB8: .4byte gUnknown_83B0000
_080ADEBC: .4byte gUnknown_811889C
_080ADEC0: .4byte gUnknown_8108EC0
_080ADEC4: .4byte gUnknown_81188A8
_080ADEC8: .4byte gUnknown_81188B4
_080ADECC: .4byte 0x00001194
_080ADED0: .4byte gUnknown_81188C0
_080ADED4:
	ldr r1, _080ADF80
	add r0, sp, 0x10
	mov r2, r8
	ldr r3, [sp, 0x58]
	bl sprintf
	add r0, sp, 0x10
	adds r1, r7, 0
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	movs r1, 0x90
	lsls r1, 2
	mov r0, r10
	adds r2, r4, 0
	bl sub_800AAA8
	adds r0, r4, 0
	bl CloseFile
_080ADEFC:
	movs r5, 0
	ldr r3, [sp, 0x60]
	cmp r5, r3
	bge _080ADF52
_080ADF04:
	mov r0, r8
	bl sub_8097F40
	lsls r0, 24
	movs r7, 0
	cmp r0, 0
	beq _080ADF14
	movs r7, 0x3
_080ADF14:
	movs r4, 0
	adds r6, r5, 0x1
	cmp r4, r9
	bge _080ADF4A
_080ADF1C:
	ldr r0, [sp, 0x64]
	str r0, [sp]
	str r7, [sp, 0x4]
	mov r1, r10
	str r1, [sp, 0x8]
	mov r2, r8
	str r2, [sp, 0xC]
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, r9
	ldr r3, [sp, 0x60]
	bl sub_80ADFB8
	mov r1, r9
	muls r1, r5
	adds r1, r4
	lsls r1, 1
	ldr r3, [sp, 0x50]
	adds r1, r3
	strh r0, [r1]
	adds r4, 0x1
	cmp r4, r9
	blt _080ADF1C
_080ADF4A:
	adds r5, r6, 0
	ldr r0, [sp, 0x60]
	cmp r5, r0
	blt _080ADF04
_080ADF52:
	ldr r1, _080ADF84
	add r0, sp, 0x10
	mov r2, r8
	bl sprintf
	ldr r1, _080ADF88
	add r0, sp, 0x10
	bl OpenFile
	ldr r1, [sp, 0x24]
	str r0, [r1]
	mov r0, r10
	bl MemoryFree
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ADF80: .4byte gUnknown_81188CC
_080ADF84: .4byte gUnknown_81188DC
_080ADF88: .4byte gUnknown_83B0000
	thumb_func_end sub_80ADD9C

	thumb_func_start sub_80ADF8C
sub_80ADF8C:
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [sp, 0xC]
	cmp r4, 0
	blt _080ADFB0
	cmp r1, 0
	blt _080ADFB0
	cmp r4, r2
	bge _080ADFB0
	cmp r1, r3
	bge _080ADFB0
	adds r0, r1, 0
	muls r0, r2
	adds r0, r4, r0
	lsls r0, 1
	ldr r1, [sp, 0x8]
	adds r0, r1
	ldrh r0, [r0]
_080ADFB0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADF8C

	thumb_func_start sub_80ADFB8
sub_80ADFB8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r4, [sp, 0x5C]
	movs r7, 0
	ldr r0, [sp, 0x50]
	str r0, [sp]
	ldr r1, [sp, 0x54]
	str r1, [sp, 0x4]
	mov r0, r9
	mov r1, r10
	bl sub_80ADF8C
	str r0, [sp, 0x28]
	cmp r4, 0x3F
	ble _080AE000
	mov r0, r9
	cmp r0, 0x17
	bgt _080ADFFC
	mov r1, r10
	cmp r1, 0x17
	bgt _080ADFFC
	lsls r0, r1, 1
	add r0, r10
	lsls r0, 3
	add r0, r9
	b _080AE24E
_080ADFFC:
	ldr r0, [sp, 0x54]
	b _080AE254
_080AE000:
	mov r0, r10
	adds r0, 0x1
	str r0, [sp, 0x2C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x8]
	mov r4, r9
	adds r4, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0xC]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x10]
	mov r5, r10
	subs r5, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x14]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x18]
	subs r4, 0x2
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x1C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	adds r1, r0, 0
	str r1, [sp, 0x24]
	ldr r0, [sp, 0x28]
	cmp r0, 0x1
	bne _080AE12A
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE0D2
	movs r7, 0xFE
_080AE0D2:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE0DE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE0DE:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE0EA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE0EA:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE0F6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE0F6:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE102
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE102:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE10E
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE10E:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE11A
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE11A:
	cmp r1, 0
	bne _080AE124
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE124:
	movs r0, 0x80
	lsls r0, 2
	b _080AE248
_080AE12A:
	ldr r0, [sp, 0x28]
	cmp r0, 0x2
	bne _080AE192
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x2
	beq _080AE13A
	movs r7, 0xFE
_080AE13A:
	ldr r0, [sp, 0xC]
	cmp r0, 0x2
	beq _080AE146
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE146:
	ldr r0, [sp, 0x10]
	cmp r0, 0x2
	beq _080AE152
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE152:
	ldr r0, [sp, 0x14]
	cmp r0, 0x2
	beq _080AE15E
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE15E:
	ldr r0, [sp, 0x18]
	cmp r0, 0x2
	beq _080AE16A
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE16A:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x2
	beq _080AE176
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE176:
	ldr r0, [sp, 0x20]
	cmp r0, 0x2
	beq _080AE182
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE182:
	cmp r1, 0x2
	beq _080AE18C
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE18C:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE192:
	ldr r1, [sp, 0x28]
	cmp r1, 0x3
	bne _080AE1FC
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x3
	beq _080AE1A2
	movs r7, 0xFE
_080AE1A2:
	ldr r0, [sp, 0xC]
	cmp r0, 0x3
	beq _080AE1AE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE1AE:
	ldr r0, [sp, 0x10]
	cmp r0, 0x3
	beq _080AE1BA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE1BA:
	ldr r0, [sp, 0x14]
	cmp r0, 0x3
	beq _080AE1C6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE1C6:
	ldr r0, [sp, 0x18]
	cmp r0, 0x3
	beq _080AE1D2
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE1D2:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x3
	beq _080AE1DE
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE1DE:
	ldr r0, [sp, 0x20]
	cmp r0, 0x3
	beq _080AE1EA
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE1EA:
	ldr r0, [sp, 0x24]
	cmp r0, 0x3
	beq _080AE1F6
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE1F6:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE1FC:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE204
	movs r7, 0x1
_080AE204:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE20E
	movs r0, 0x2
	orrs r7, r0
_080AE20E:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE218
	movs r0, 0x4
	orrs r7, r0
_080AE218:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE222
	movs r0, 0x8
	orrs r7, r0
_080AE222:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE22C
	movs r0, 0x10
	orrs r7, r0
_080AE22C:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE236
	movs r0, 0x20
	orrs r7, r0
_080AE236:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE240
	movs r0, 0x40
	orrs r7, r0
_080AE240:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _080AE24A
	movs r0, 0x80
_080AE248:
	orrs r7, r0
_080AE24A:
	lsls r0, r7, 1
	adds r0, r7
_080AE24E:
	ldr r1, [sp, 0x58]
	adds r0, r1, r0
	ldrb r0, [r0]
_080AE254:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADFB8

	.align 2, 0 @ Don't pad with nop.
