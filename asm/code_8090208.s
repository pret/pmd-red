	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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

	thumb_func_start xxx_save_poke_sub_4_80902F4
xxx_save_poke_sub_4_80902F4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x7
	bl SaveIntegerBits
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl SaveIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end xxx_save_poke_sub_4_80902F4

	thumb_func_start xxx_restore_poke_sub_4_8090314
xxx_restore_poke_sub_4_8090314:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strb r0, [r4]
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	movs r2, 0x7
	bl RestoreIntegerBits
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl RestoreIntegerBits
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end xxx_restore_poke_sub_4_8090314

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
	bl GetNumberOfFilledInventorySlots
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
_08090410: .4byte gRecruitedPokemonRef
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
_0809052C: .4byte gRecruitedPokemonRef
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
	bl GetItemPossessionCount
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
	bl InitPokemonMove
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
_080906AC: .4byte gRecruitedPokemonRef
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
	bl sprintf_2
	movs r0, 0
	b _0809080E
	.align 2, 0
_080907EC: .4byte gDungeons
_080907F0: .4byte gUnknown_8115DD4
_080907F4: .4byte gUnknown_8115E00
_080907F8: .4byte gUnknown_8115E28
_080907FC: .4byte gUnknown_8115E54
_08090800: .4byte gTeamInventory_203B460
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
_08090868: .4byte gRecruitedPokemonRef
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

        .align 2,0
