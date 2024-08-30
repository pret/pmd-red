	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_807E698
sub_807E698:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 16
	str r0, [sp, 0x4]
	ldr r0, _0807E724
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r10, r0
	movs r0, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp]
	bl sub_8042818
	movs r0, 0x25
	bl sub_803E46C
	movs r0, 0x1
	bl sub_804178C
	ldr r1, _0807E728
	ldrb r0, [r1]
	str r0, [sp, 0x8]
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0
	mov r9, r1
	ldr r2, _0807E72C
	mov r8, r2
_0807E6EC:
	movs r7, 0
	movs r0, 0x25
	bl sub_803E46C
	movs r6, 0
	ldr r1, [sp, 0x4]
	lsls r0, r1, 2
	mov r2, r10
	adds r5, r0, r2
	movs r0, 0xFF
	mov r12, r0
_0807E702:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	movs r2, 0xBE
	lsls r2, 1
	adds r4, r0, r2
	ldrb r0, [r4]
	ldrb r3, [r5]
	subs r1, r0, r3
	cmp r1, 0
	bge _0807E71A
	negs r1, r1
_0807E71A:
	cmp r1, 0x9
	bgt _0807E730
	strb r3, [r4]
	b _0807E746
	.align 2, 0
_0807E724: .4byte gUnknown_202ECA0
_0807E728: .4byte gUnknown_203B40D
_0807E72C: .4byte gDungeon
_0807E730:
	movs r7, 0x1
	adds r2, r0, 0
	adds r1, r3, 0
	cmp r2, r1
	bcs _0807E73E
	adds r0, 0xA
	b _0807E744
_0807E73E:
	cmp r2, r1
	bls _0807E746
	subs r0, 0xA
_0807E744:
	strb r0, [r4]
_0807E746:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	ldr r2, _0807E764
	adds r4, r0, r2
	ldrb r0, [r4]
	ldrb r3, [r5, 0x1]
	subs r1, r0, r3
	cmp r1, 0
	bge _0807E75C
	negs r1, r1
_0807E75C:
	cmp r1, 0x9
	bgt _0807E768
	strb r3, [r4]
	b _0807E77E
	.align 2, 0
_0807E764: .4byte 0x0000017d
_0807E768:
	movs r7, 0x1
	adds r2, r0, 0
	adds r1, r3, 0
	cmp r2, r1
	bcs _0807E776
	adds r0, 0xA
	b _0807E77C
_0807E776:
	cmp r2, r1
	bls _0807E77E
	subs r0, 0xA
_0807E77C:
	strb r0, [r4]
_0807E77E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	movs r2, 0xBF
	lsls r2, 1
	adds r4, r0, r2
	ldrb r0, [r4]
	ldrb r3, [r5, 0x2]
	subs r1, r0, r3
	cmp r1, 0
	bge _0807E796
	negs r1, r1
_0807E796:
	cmp r1, 0x9
	bgt _0807E79E
	strb r3, [r4]
	b _0807E7B4
_0807E79E:
	movs r7, 0x1
	adds r2, r0, 0
	adds r1, r3, 0
	cmp r2, r1
	bcs _0807E7AC
	adds r0, 0xA
	b _0807E7B2
_0807E7AC:
	cmp r2, r1
	bls _0807E7B4
	subs r0, 0xA
_0807E7B2:
	strb r0, [r4]
_0807E7B4:
	adds r6, 0x4
	adds r5, 0x4
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	mov r1, r12
	cmp r1, 0
	bge _0807E702
	movs r0, 0
	movs r1, 0
	bl sub_803E874
	cmp r7, 0
	beq _0807E7DA
	movs r2, 0x1
	add r9, r2
	mov r0, r9
	cmp r0, 0x3F
	ble _0807E6EC
_0807E7DA:
	ldr r0, _0807E7F8
	mov r1, sp
	ldrb r1, [r1, 0x8]
	strb r1, [r0]
	ldr r0, [sp]
	bl sub_807E7FC
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E7F8: .4byte gUnknown_203B40D
	thumb_func_end sub_807E698

	thumb_func_start sub_807E7FC
sub_807E7FC:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, _0807E874
	ldr r0, [r6]
	ldr r1, _0807E878
	adds r0, r1
	ldr r5, [r0]
	cmp r5, 0
	bne _0807E816
	bl GetLeader
	adds r5, r0, 0
_0807E816:
	cmp r4, 0
	beq _0807E844
	ldr r0, [r6]
	ldr r2, _0807E87C
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807E844
	ldr r4, _0807E880
	movs r0, 0
	bl GetApparentWeather
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl GetWeatherName
	ldr r0, _0807E884
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_0807E844:
	movs r5, 0
_0807E846:
	ldr r0, _0807E874
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807E888
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807E866
	adds r0, r4, 0
	bl sub_807E8F0
_0807E866:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807E846
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807E874: .4byte gDungeon
_0807E878: .4byte 0x000181f8
_0807E87C: .4byte 0x0001356c
_0807E880: .4byte gAvailablePokemonNames
_0807E884: .4byte gUnknown_80FC5E0
_0807E888: .4byte 0x000135cc
	thumb_func_end sub_807E7FC

	thumb_func_start sub_807E88C
sub_807E88C:
	push {r4-r7,lr}
	movs r0, 0
	bl GetApparentWeather
	lsls r0, 24
	ldr r1, _0807E8E4
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	movs r4, 0
	ldr r5, _0807E8E8
	lsrs r0, 14
	adds r3, r0, r1
	movs r6, 0xBE
	lsls r6, 1
_0807E8A8:
	ldr r0, [r5]
	lsls r2, r4, 2
	adds r0, r2
	ldrb r1, [r3]
	adds r0, r6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2
	ldrb r1, [r3, 0x1]
	ldr r7, _0807E8EC
	adds r0, r7
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2
	ldrb r1, [r3, 0x2]
	movs r2, 0xBF
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, 0xFF
	ble _0807E8A8
	movs r0, 0
	movs r1, 0
	bl sub_803E874
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E8E4: .4byte gUnknown_202ECA0
_0807E8E8: .4byte gDungeon
_0807E8EC: .4byte 0x0000017d
	thumb_func_end sub_807E88C

	thumb_func_start sub_807E8F0
sub_807E8F0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r5, r0, 0
	movs r0, 0
	mov r8, r0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807E90E
	b _0807EA0A
_0807E90E:
	ldr r4, [r5, 0x70]
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	mov r9, r1
	mov r1, sp
	adds r6, r4, 0
	adds r6, 0x5C
	ldrb r0, [r6]
	strb r0, [r1]
	adds r7, r4, 0
	adds r7, 0x5D
	ldrb r0, [r7]
	strb r0, [r1, 0x1]
	adds r0, r5, 0
	bl CalcSpeedStage
	adds r0, r5, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807E958
	adds r0, r5, 0
	bl GetApparentWeather
	ldr r1, _0807E954
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	mov r1, r8
	strb r1, [r7]
	b _0807E984
	.align 2, 0
_0807E954: .4byte gUnknown_80F520C
_0807E958:
	adds r0, r4, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xC
	beq _0807E984
	adds r0, r4, 0
	adds r0, 0xF6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807E984
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r1, 0
	bl GetPokemonType
	strb r0, [r6]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	bl GetPokemonType
	strb r0, [r7]
_0807E984:
	mov r0, sp
	adds r1, r4, 0
	adds r1, 0x5C
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0807E9A0
	mov r0, sp
	adds r1, r4, 0
	adds r1, 0x5D
	ldrb r0, [r0, 0x1]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0807E9A4
_0807E9A0:
	movs r0, 0x1
	mov r8, r0
_0807E9A4:
	ldr r1, _0807E9D0
	adds r0, r1, 0
	ldrh r1, [r4, 0x2]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _0807E9FE
	adds r0, r5, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807E9D4
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_8069F54
	b _0807E9D8
	.align 2, 0
_0807E9D0: .4byte 0xfffffe88
_0807E9D4:
	movs r0, 0xBC
	lsls r0, 1
_0807E9D8:
	strh r0, [r4, 0x4]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, r9
	beq _0807E9FE
	bl sub_80687D0
	str r0, [r5, 0x64]
	adds r0, r5, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_806CCB4
	movs r0, 0x1
	mov r8, r0
_0807E9FE:
	mov r1, r8
	cmp r1, 0
	beq _0807EA0A
	adds r0, r5, 0
	bl sub_80429D8
_0807EA0A:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807E8F0

	thumb_func_start GetWeatherName
GetWeatherName:
	push {lr}
	lsls r1, 24
	ldr r2, _0807EA2C
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	bl strcpy
	pop {r0}
	bx r0
	.align 2, 0
_0807EA2C: .4byte gWeatherNames
	thumb_func_end GetWeatherName

	thumb_func_start MudWaterSportEffect
MudWaterSportEffect:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0807EA6C
	ldr r1, _0807EA5C
	movs r0, 0
	movs r2, 0
	bl CalculateStatusTurns
	ldr r1, _0807EA60
	ldr r1, [r1]
	ldr r2, _0807EA64
	adds r1, r2
	strb r0, [r1]
	bl GetLeader
	ldr r1, _0807EA68
	ldr r1, [r1]
	bl SendMessage
	b _0807EA8C
	.align 2, 0
_0807EA5C: .4byte gUnknown_80F4EAC
_0807EA60: .4byte gDungeon
_0807EA64: .4byte 0x0000e277
_0807EA68: .4byte gUnknown_80FAD8C
_0807EA6C:
	ldr r1, _0807EA90
	movs r0, 0
	movs r2, 0
	bl CalculateStatusTurns
	ldr r1, _0807EA94
	ldr r1, [r1]
	ldr r2, _0807EA98
	adds r1, r2
	strb r0, [r1]
	bl GetLeader
	ldr r1, _0807EA9C
	ldr r1, [r1]
	bl SendMessage
_0807EA8C:
	pop {r0}
	bx r0
	.align 2, 0
_0807EA90: .4byte gUnknown_80F4EAC
_0807EA94: .4byte gDungeon
_0807EA98: .4byte 0x0000e278
_0807EA9C: .4byte gUnknown_80FADB0
	thumb_func_end MudWaterSportEffect

	thumb_func_start sub_807EAA0
sub_807EAA0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x4]
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0
	str r2, [sp, 0x8]
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r5, 0
	ldr r7, _0807EAF0
	ldr r6, _0807EAF4
_0807EAD6:
	ldr r3, [r7]
	adds r0, r3, r6
	adds r4, r0, r5
	ldr r1, _0807EAF8
	adds r0, r3, r1
	adds r0, r5
	ldrb r0, [r0]
	ldrb r2, [r4]
	adds r1, r0, 0
	cmp r2, r1
	bcs _0807EAFC
	strb r0, [r4]
	b _0807EB08
	.align 2, 0
_0807EAF0: .4byte gDungeon
_0807EAF4: .4byte 0x0000e267
_0807EAF8: .4byte 0x0000e26f
_0807EAFC:
	cmp r2, r1
	bls _0807EB08
	adds r0, r5, r6
	adds r0, r3, r0
	bl sub_80838EC
_0807EB08:
	ldr r0, [r7]
	ldr r2, _0807EB38
	adds r0, r2
	adds r0, r5
	ldrb r1, [r0]
	ldr r0, _0807EB3C
	cmp r8, r1
	bge _0807EB1C
	mov r8, r1
	mov r9, r5
_0807EB1C:
	adds r5, 0x1
	cmp r5, 0x7
	ble _0807EAD6
	mov r1, r9
	cmp r1, 0
	bge _0807EB44
	ldr r0, [r0]
	ldr r2, _0807EB40
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, 0x1
	adds r0, r2
	strb r1, [r0]
	b _0807EB4E
	.align 2, 0
_0807EB38: .4byte 0x0000e267
_0807EB3C: .4byte gDungeon
_0807EB40: .4byte 0x0000e265
_0807EB44:
	ldr r0, [r0]
	ldr r1, _0807EB94
	adds r0, r1
	mov r2, r9
	strb r2, [r0]
_0807EB4E:
	ldr r0, _0807EB98
	ldr r1, [r0]
	ldr r2, _0807EB9C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807EB64
	ldr r0, _0807EB94
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
_0807EB64:
	movs r0, 0
	bl GetApparentWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r10, r0
	bne _0807EB78
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _0807EB82
_0807EB78:
	movs r2, 0x1
	str r2, [sp, 0x8]
	ldr r0, [sp]
	bl sub_807E698
_0807EB82:
	ldr r0, _0807EB98
	ldr r0, [r0]
	ldr r2, _0807EBA0
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807EBA4
	subs r0, 0x1
	b _0807EBA6
	.align 2, 0
_0807EB94: .4byte 0x0000e264
_0807EB98: .4byte gDungeon
_0807EB9C: .4byte 0x0000e279
_0807EBA0: .4byte 0x0000e266
_0807EBA4:
	movs r0, 0x9
_0807EBA6:
	strb r0, [r1]
	ldr r4, _0807EC14
	ldr r0, [r4]
	ldr r2, _0807EC18
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807EBD4
	adds r0, r1, 0
	bl sub_80838EC
	ldr r0, [r4]
	ldr r1, _0807EC18
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807EBD4
	bl GetLeader
	ldr r1, _0807EC1C
	ldr r1, [r1]
	bl SendMessage
_0807EBD4:
	ldr r4, _0807EC14
	ldr r0, [r4]
	ldr r2, _0807EC20
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807EC00
	adds r0, r1, 0
	bl sub_80838EC
	ldr r0, [r4]
	ldr r1, _0807EC20
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807EC00
	bl GetLeader
	ldr r1, _0807EC24
	ldr r1, [r1]
	bl SendMessage
_0807EC00:
	ldr r0, [sp, 0x8]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807EC14: .4byte gDungeon
_0807EC18: .4byte 0x0000e277
_0807EC1C: .4byte gUnknown_80FA778
_0807EC20: .4byte 0x0000e278
_0807EC24: .4byte gUnknown_80FA758
	thumb_func_end sub_807EAA0

	thumb_func_start sub_807EC28
sub_807EC28:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807EC46
	b _0807EF32
_0807EC46:
	bl GetLeader
	adds r7, r0, 0
	ldr r0, [r7, 0x70]
	mov r9, r0
	ldr r4, _0807ECB4
	ldr r0, [r4]
	movs r5, 0xD3
	lsls r5, 3
	adds r0, r5
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	adds r0, r7, 0
	bl GetTileAtEntitySafe
	ldrh r0, [r0]
	lsrs r0, 5
	mov r10, r0
	movs r0, 0x1
	mov r1, r10
	ands r1, r0
	mov r10, r1
	ldr r0, [r4]
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0807ECB8
	adds r0, r3
	mov r2, r10
	strb r2, [r0]
	ldr r2, [r4]
	ldr r6, _0807ECBC
	adds r0, r2, r6
	ldrb r1, [r0]
	cmp r1, 0
	beq _0807EC90
	b _0807EF32
_0807EC90:
	adds r6, 0x26
	adds r0, r2, r6
	ldr r0, [r0]
	cmp r0, 0
	bne _0807EC9C
	b _0807EF32
_0807EC9C:
	mov r0, r9
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807ECC0
	adds r0, r2, r5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r3
	strb r1, [r0]
	b _0807EF32
	.align 2, 0
_0807ECB4: .4byte gDungeon
_0807ECB8: .4byte 0x00000699
_0807ECBC: .4byte 0x0000066e
_0807ECC0:
	movs r0, 0
	str r0, [sp, 0xC]
	movs r6, 0
_0807ECC6:
	ldr r0, _0807ED48
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0807ED4C
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807ED0E
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1
	bne _0807ED0E
	adds r0, r5, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	beq _0807ED0E
	adds r0, r7, 0
	bl GetEntityRoom
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetEntityRoom
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _0807ED0E
	movs r0, 0x1
	str r0, [sp, 0xC]
_0807ED0E:
	adds r6, 0x1
	cmp r6, 0xF
	ble _0807ECC6
	ldr r1, _0807ED50
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xBE
	lsls r1, 1
	orrs r0, r1
	ldr r1, _0807ED54
	ands r0, r1
	str r0, [sp]
	ldr r1, [sp, 0x8]
	cmp r1, 0
	bne _0807ED5C
	mov r2, r10
	cmp r2, 0x1
	bne _0807ED64
	ldr r6, [sp, 0xC]
	cmp r6, 0
	bne _0807ED3A
	b _0807EF32
_0807ED3A:
	ldr r0, _0807ED58
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl PrintFieldMessage
	b _0807EF32
	.align 2, 0
_0807ED48: .4byte gDungeon
_0807ED4C: .4byte 0x0001358c
_0807ED50: .4byte 0xffff0000
_0807ED54: .4byte 0xff00ffff
_0807ED58: .4byte gUnknown_80FE674
_0807ED5C:
	mov r0, r10
	cmp r0, 0x1
	bne _0807ED64
	b _0807EF32
_0807ED64:
	ldr r1, [sp, 0x8]
	cmp r1, 0x1
	bne _0807ED70
	mov r2, r10
	cmp r2, 0
	beq _0807ED78
_0807ED70:
	mov r6, r8
	cmp r6, 0
	bne _0807ED78
	b _0807EF32
_0807ED78:
	movs r0, 0
	str r0, [sp, 0x10]
	movs r1, 0
	str r1, [sp, 0x14]
	bl sub_807EF48
	lsls r0, 24
	cmp r0, 0
	bne _0807ED8C
	b _0807EECC
_0807ED8C:
	movs r2, 0x1
	str r2, [sp, 0x14]
	movs r6, 0
_0807ED92:
	ldr r0, _0807EE90
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0807EE94
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807EDAE
	b _0807EEC4
_0807EDAE:
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1
	beq _0807EDB8
	b _0807EEC4
_0807EDB8:
	adds r0, r5, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _0807EDC6
	b _0807EEC4
_0807EDC6:
	adds r0, r7, 0
	bl GetEntityRoom
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetEntityRoom
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _0807EEC4
	movs r6, 0x1
	str r6, [sp, 0x10]
	movs r0, 0x4
	ldrsh r1, [r7, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807EDF0
	negs r1, r1
_0807EDF0:
	cmp r1, 0x1
	bgt _0807EE10
	movs r6, 0x6
	ldrsh r1, [r7, r6]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807EE04
	negs r1, r1
_0807EE04:
	adds r6, r7, 0x4
	mov r9, r6
	adds r0, r5, 0x4
	mov r8, r0
	cmp r1, 0x1
	ble _0807EE72
_0807EE10:
	movs r3, 0x1
	negs r3, r3
	add r6, sp, 0x4
	adds r1, r7, 0x4
	mov r9, r1
	adds r2, r5, 0x4
	mov r8, r2
_0807EE1E:
	movs r4, 0x1
	negs r4, r4
_0807EE22:
	ldrh r0, [r7, 0x4]
	adds r0, r3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _0807EE98
	ldr r2, [sp, 0x4]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	ldrh r0, [r7, 0x6]
	adds r0, r4
	lsls r0, 16
	ldr r1, _0807EE9C
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x4]
	movs r2, 0
	ldrsh r0, [r6, r2]
	asrs r1, 16
	str r3, [sp, 0x18]
	bl GetTile
	ldrb r0, [r0, 0x9]
	ldr r3, [sp, 0x18]
	cmp r0, 0xFF
	beq _0807EE66
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80703A0
	lsls r0, 24
	ldr r3, [sp, 0x18]
	cmp r0, 0
	beq _0807EEA0
_0807EE66:
	adds r4, 0x1
	cmp r4, 0x1
	ble _0807EE22
	adds r3, 0x1
	cmp r3, 0x1
	ble _0807EE1E
_0807EE72:
	adds r0, r7, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	beq _0807EEAE
	mov r0, r9
	mov r1, r8
	bl GetDirectionTowardsPosition
	adds r1, r0, 0
	adds r0, r7, 0
	bl sub_806CE34
	b _0807EEB2
	.align 2, 0
_0807EE90: .4byte gDungeon
_0807EE94: .4byte 0x0001358c
_0807EE98: .4byte 0xffff0000
_0807EE9C: .4byte 0x0000ffff
_0807EEA0:
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x3
	adds r3, r6, 0
	bl sub_807D148
	b _0807EE72
_0807EEAE:
	movs r6, 0
	str r6, [sp, 0x10]
_0807EEB2:
	mov r0, r8
	mov r1, r9
	bl GetDirectionTowardsPosition
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_806CE68
	b _0807EECC
_0807EEC4:
	adds r6, 0x1
	cmp r6, 0xF
	bgt _0807EECC
	b _0807ED92
_0807EECC:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	beq _0807EF04
	ldr r1, [sp, 0x10]
	cmp r1, 0
	beq _0807EEDE
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _0807EF04
_0807EEDE:
	ldr r0, _0807EEF8
	ldr r0, [r0]
	ldr r2, _0807EEFC
	adds r1, r0, r2
	ldr r6, _0807EF00
	adds r0, r6
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	ble _0807EF32
_0807EEF2:
	bl sub_807F33C
	b _0807EF32
	.align 2, 0
_0807EEF8: .4byte gDungeon
_0807EEFC: .4byte 0x00000694
_0807EF00: .4byte 0x0000068c
_0807EF04:
	ldr r0, [sp, 0x10]
	bl sub_807EFFC
	ldr r0, [sp, 0x10]
	bl sub_807F19C
	cmp r0, 0
	bne _0807EEF2
	ldr r0, [sp, 0x8]
	cmp r0, 0x1
	bne _0807EF32
	mov r1, r10
	cmp r1, 0
	bne _0807EF32
	ldr r2, [sp, 0xC]
	cmp r2, 0
	beq _0807EF32
	ldr r0, _0807EF44
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl PrintFieldMessage
_0807EF32:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807EF44: .4byte gUnknown_80FE65C
	thumb_func_end sub_807EC28

	thumb_func_start sub_807EF48
sub_807EF48:
	push {lr}
	ldr r0, _0807EF70
	ldr r2, [r0]
	ldr r1, _0807EF74
	adds r0, r2, r1
	ldr r3, _0807EF78
	adds r1, r2, r3
	ldr r0, [r0]
	ldr r1, [r1]
	subs r0, r1
	cmp r0, 0
	bgt _0807EF7C
	movs r1, 0xD2
	lsls r1, 3
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0807EF7C
	movs r0, 0
	b _0807EF7E
	.align 2, 0
_0807EF70: .4byte gDungeon
_0807EF74: .4byte 0x00000694
_0807EF78: .4byte 0x0000068c
_0807EF7C:
	movs r0, 0x1
_0807EF7E:
	pop {r1}
	bx r1
	thumb_func_end sub_807EF48

	thumb_func_start sub_807EF84
sub_807EF84:
	push {r4,lr}
	sub sp, 0x4
	ldr r1, _0807EFD0
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xBE
	lsls r1, 1
	orrs r0, r1
	ldr r1, _0807EFD4
	ands r0, r1
	str r0, [sp]
	movs r0, 0x1
	bl sub_807EFFC
	movs r0, 0x1
	bl sub_807F19C
	adds r4, r0, 0
	cmp r4, 0
	beq _0807EFE2
	bl GetLeader
	bl GetTileAtEntitySafe
	ldrh r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0807EFDC
	cmp r4, 0x2
	beq _0807EFEE
	ldr r0, _0807EFD8
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl PrintFieldMessage
	b _0807EFEE
	.align 2, 0
_0807EFD0: .4byte 0xffff0000
_0807EFD4: .4byte 0xff00ffff
_0807EFD8: .4byte gUnknown_80FE63C
_0807EFDC:
	bl sub_807F33C
	b _0807EFEE
_0807EFE2:
	ldr r0, _0807EFF8
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl PrintFieldMessage
_0807EFEE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807EFF8: .4byte gUnknown_80FE5F0
	thumb_func_end sub_807EF84

	thumb_func_start sub_807EFFC
sub_807EFFC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r4, _0807F168
	ldr r0, [r4]
	movs r5, 0xD2
	lsls r5, 3
	adds r2, r0, r5
	ldr r0, [r2]
	cmp r0, 0
	bne _0807F01E
	b _0807F158
_0807F01E:
	ldr r1, _0807F16C
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xBE
	lsls r1, 1
	orrs r0, r1
	ldr r1, _0807F170
	ands r0, r1
	str r0, [sp]
	cmp r3, 0
	bne _0807F036
	b _0807F158
_0807F036:
	ldr r1, _0807F174
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, _0807F178
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	beq _0807F04E
	b _0807F158
_0807F04E:
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySoundEffect
	ldr r0, [r4]
	adds r0, r5
	ldr r0, [r0]
	bl AddToTeamMoney
	ldr r0, [r4]
	ldr r2, _0807F17C
	adds r1, r0, r2
	ldr r1, [r1]
	str r1, [sp, 0xC]
	ldr r2, _0807F180
	adds r1, r0, r2
	ldr r6, [r1]
	ldr r1, _0807F184
	adds r0, r1
	ldr r0, [r0]
	cmp r6, r0
	bgt _0807F134
	mov r8, r4
_0807F07C:
	mov r2, r8
	ldr r0, [r2]
	ldr r2, _0807F188
	adds r1, r0, r2
	ldr r5, [r1]
	ldr r1, _0807F18C
	adds r0, r1
	ldr r0, [r0]
	adds r2, r6, 0x1
	mov r10, r2
	cmp r5, r0
	bgt _0807F124
	lsls r0, r6, 16
	lsrs r0, 16
	mov r9, r0
_0807F09A:
	lsls r0, r5, 16
	mov r1, r9
	orrs r0, r1
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetTile
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0807F114
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F114
	bl GetEntityType
	cmp r0, 0x3
	bne _0807F114
	ldr r0, [r4, 0x14]
	bl GetItemData
	adds r2, r0, 0
	ldrb r1, [r2]
	movs r7, 0x2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0807F114
	ldr r0, [r2]
	str r0, [sp, 0x8]
	add r4, sp, 0x4
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, [sp, 0x8]
	lsrs r0, 16
	lsls r0, 24
	lsrs r0, 24
	bl CanSellItem
	lsls r0, 24
	add r3, sp, 0x8
	cmp r0, 0
	beq _0807F10A
	ldrb r0, [r3]
	adds r2, r7, 0
	orrs r2, r0
	ldr r1, _0807F190
	ldr r0, [sp, 0x8]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x8]
_0807F10A:
	adds r0, r4, 0
	adds r1, r3, 0
	movs r2, 0x1
	bl sub_80460F8
_0807F114:
	adds r5, 0x1
	mov r2, r8
	ldr r0, [r2]
	ldr r1, _0807F18C
	adds r0, r1
	ldr r0, [r0]
	cmp r5, r0
	ble _0807F09A
_0807F124:
	mov r6, r10
	mov r2, r8
	ldr r0, [r2]
	ldr r1, _0807F184
	adds r0, r1
	ldr r0, [r0]
	cmp r6, r0
	ble _0807F07C
_0807F134:
	ldr r0, _0807F168
	ldr r0, [r0]
	ldr r1, _0807F194
	adds r2, r0, r1
	subs r1, 0x8
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [sp, 0xC]
	subs r1, r0
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
	ldr r0, _0807F198
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl PrintFieldMessage
_0807F158:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F168: .4byte gDungeon
_0807F16C: .4byte 0xffff0000
_0807F170: .4byte 0xff00ffff
_0807F174: .4byte gFormatData_202DE30
_0807F178: .4byte gUnknown_80FE5C0
_0807F17C: .4byte 0x0000068c
_0807F180: .4byte 0x0000e240
_0807F184: .4byte 0x0000e248
_0807F188: .4byte 0x0000e244
_0807F18C: .4byte 0x0000e24c
_0807F190: .4byte 0xffffff00
_0807F194: .4byte 0x00000694
_0807F198: .4byte gUnknown_80FE4F4
	thumb_func_end sub_807EFFC

	thumb_func_start sub_807F19C
sub_807F19C:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, _0807F1EC
	ldr r0, [sp]
	ands r0, r1
	movs r1, 0xBE
	lsls r1, 1
	orrs r0, r1
	ldr r1, _0807F1F0
	ands r0, r1
	str r0, [sp]
	ldr r0, _0807F1F4
	ldr r0, [r0]
	ldr r3, _0807F1F8
	adds r1, r0, r3
	subs r3, 0x8
	adds r0, r3
	ldr r1, [r1]
	ldr r0, [r0]
	subs r4, r1, r0
	cmp r4, 0
	bgt _0807F1CE
	b _0807F31A
_0807F1CE:
	cmp r2, 0
	beq _0807F1E6
	ldr r0, _0807F1FC
	str r4, [r0]
	ldr r0, _0807F200
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	beq _0807F204
_0807F1E6:
	movs r0, 0x1
	b _0807F31C
	.align 2, 0
_0807F1EC: .4byte 0xffff0000
_0807F1F0: .4byte 0xff00ffff
_0807F1F4: .4byte gDungeon
_0807F1F8: .4byte 0x00000694
_0807F1FC: .4byte gFormatData_202DE30
_0807F200: .4byte gUnknown_80FE568
_0807F204:
	ldr r0, _0807F224
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r4
	bge _0807F22C
	ldr r0, _0807F228
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl PrintFieldMessage
	movs r0, 0x2
	b _0807F31C
	.align 2, 0
_0807F224: .4byte gTeamInventoryRef
_0807F228: .4byte gUnknown_80FE520
_0807F22C:
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySoundEffect
	negs r0, r4
	bl AddToTeamMoney
	movs r6, 0
_0807F23C:
	movs r5, 0
	adds r7, r6, 0x1
_0807F240:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetTile
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0807F27E
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F27E
	bl GetEntityType
	cmp r0, 0x3
	bne _0807F27E
	ldr r0, [r4, 0x14]
	bl GetItemData
	adds r4, r0, 0
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _0807F27E
	ldrb r1, [r4]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F27E:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0807F240
	adds r6, r7, 0
	cmp r6, 0x37
	ble _0807F23C
	movs r5, 0
_0807F28C:
	ldr r0, _0807F324
	lsls r1, r5, 2
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807F2B2
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _0807F2B2
	ldrb r1, [r4]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F2B2:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807F28C
	movs r5, 0
_0807F2BA:
	ldr r0, _0807F328
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807F32C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F2F8
	ldr r0, [r4, 0x70]
	adds r4, r0, 0
	adds r4, 0x60
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807F2F8
	ldrb r0, [r4, 0x2]
	bl CanSellItem
	lsls r0, 24
	cmp r0, 0
	beq _0807F2F8
	ldrb r1, [r4]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F2F8:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807F2BA
	ldr r0, _0807F328
	ldr r0, [r0]
	ldr r3, _0807F330
	adds r1, r0, r3
	ldr r2, _0807F334
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0807F338
	ldr r1, [r0]
	mov r0, sp
	movs r2, 0x1
	bl PrintFieldMessage
_0807F31A:
	movs r0, 0
_0807F31C:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807F324: .4byte gTeamInventoryRef
_0807F328: .4byte gDungeon
_0807F32C: .4byte 0x000135cc
_0807F330: .4byte 0x00000694
_0807F334: .4byte 0x0000068c
_0807F338: .4byte gUnknown_80FE4D4
	thumb_func_end sub_807F19C

	thumb_func_start sub_807F33C
sub_807F33C:
	push {r4-r7,lr}
	ldr r2, _0807F41C
	ldr r0, [r2]
	ldr r1, _0807F420
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _0807F424
	adds r0, r2
	strb r1, [r0]
	bl GetLeader
	ldr r1, _0807F428
	ldr r1, [r1]
	bl SendMessage
	movs r6, 0
_0807F360:
	movs r5, 0
	adds r7, r6, 0x1
_0807F364:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetTile
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F38A
	bl GetEntityType
	cmp r0, 0x3
	bne _0807F38A
	ldr r0, [r4, 0x14]
	bl GetItemData
	ldrb r2, [r0]
	movs r1, 0xFD
	ands r1, r2
	strb r1, [r0]
_0807F38A:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0807F364
	adds r6, r7, 0
	cmp r6, 0x37
	ble _0807F360
	movs r6, 0
	ldr r4, _0807F42C
	movs r5, 0x1
	movs r3, 0xFD
_0807F39E:
	lsls r1, r6, 2
	ldr r0, [r4]
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0807F3B4
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r2]
_0807F3B4:
	adds r6, 0x1
	cmp r6, 0x13
	ble _0807F39E
	movs r6, 0
_0807F3BC:
	ldr r0, _0807F41C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r3, _0807F430
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F3F4
	ldr r4, [r5, 0x70]
	movs r0, 0
	strb r0, [r4, 0x8]
	adds r0, r5, 0
	bl CalcSpeedStage
	adds r4, 0x60
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807F3F4
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r4]
_0807F3F4:
	adds r6, 0x1
	cmp r6, 0x13
	ble _0807F3BC
	ldr r0, _0807F41C
	ldr r1, [r0]
	ldr r2, _0807F434
	adds r0, r1, r2
	movs r2, 0
	str r2, [r0]
	ldr r3, _0807F438
	adds r0, r1, r3
	str r2, [r0]
	movs r0, 0xD2
	lsls r0, 3
	adds r1, r0
	str r2, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F41C: .4byte gDungeon
_0807F420: .4byte 0x0000066e
_0807F424: .4byte 0x0000066f
_0807F428: .4byte gUnknown_80FE4B8
_0807F42C: .4byte gTeamInventoryRef
_0807F430: .4byte 0x000135cc
_0807F434: .4byte 0x00000694
_0807F438: .4byte 0x0000068c
	thumb_func_end sub_807F33C

	thumb_func_start sub_807F43C
sub_807F43C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10C
	str r0, [sp, 0xEC]
	mov r8, r1
	mov r0, r8
	movs r1, 0xE
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807F470
	ldr r0, _0807F468
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807F46C
	b _0807F694
	.align 2, 0
_0807F468: .4byte gAvailablePokemonNames
_0807F46C: .4byte gUnknown_80FCB40
_0807F470:
	ldr r0, [sp, 0xEC]
	cmp r0, r8
	bne _0807F490
	ldr r0, _0807F488
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807F48C
	ldr r2, [r0]
	mov r0, r8
	b _0807F698
	.align 2, 0
_0807F488: .4byte gAvailablePokemonNames
_0807F48C: .4byte gUnknown_80FCB70
_0807F490:
	mov r1, r8
	ldr r0, [r1, 0x4]
	add r1, sp, 0xD4
	str r0, [r1]
	movs r2, 0
	str r2, [sp, 0xF0]
_0807F49C:
	movs r3, 0
	mov r9, r3
	movs r7, 0
	mov r4, sp
	adds r4, 0x18
	str r4, [sp, 0x108]
_0807F4A8:
	ldr r0, _0807F504
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _0807F508
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r3, r7, 0x1
	str r3, [sp, 0x104]
	cmp r0, 0
	bne _0807F4C8
	b _0807F602
_0807F4C8:
	ldr r0, [sp, 0xEC]
	cmp r0, r4
	bne _0807F4D0
	b _0807F602
_0807F4D0:
	cmp r8, r4
	bne _0807F4D6
	b _0807F602
_0807F4D6:
	adds r1, r4, 0
	bl CanSeeTarget
	lsls r0, 24
	cmp r0, 0
	bne _0807F4E4
	b _0807F602
_0807F4E4:
	ldr r1, [sp, 0xF0]
	cmp r1, 0
	bne _0807F50C
	ldr r0, [sp, 0xEC]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0807F500
	b _0807F602
_0807F500:
	b _0807F51E
	.align 2, 0
_0807F504: .4byte gDungeon
_0807F508: .4byte 0x000135cc
_0807F50C:
	ldr r0, [sp, 0xEC]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl GetTreatmentBetweenMonsters
	lsls r0, 24
	cmp r0, 0
	bne _0807F602
_0807F51E:
	ldr r2, [sp, 0xF0]
	cmp r2, 0
	bne _0807F594
	movs r5, 0
	add r6, sp, 0xC8
	adds r3, r7, 0x1
	str r3, [sp, 0x104]
	adds r7, r6, 0
	ldr r0, _0807F588
	mov r10, r0
_0807F532:
	ldr r0, _0807F58C
	lsls r3, r5, 2
	adds r3, r0
	ldrh r0, [r4, 0x4]
	ldrh r1, [r3]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [r6]
	mov r2, r10
	ands r1, r2
	orrs r1, r0
	str r1, [r7]
	ldrh r2, [r4, 0x6]
	ldrh r3, [r3, 0x2]
	adds r2, r3
	lsls r2, 16
	ldr r0, _0807F590
	ands r1, r0
	orrs r1, r2
	str r1, [r7]
	mov r0, r8
	add r1, sp, 0xC8
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	beq _0807F570
	adds r5, 0x1
	cmp r5, 0x7
	ble _0807F532
_0807F570:
	cmp r5, 0x8
	beq _0807F602
	mov r3, r9
	cmp r3, 0x27
	bgt _0807F602
	ldr r0, [r4, 0x4]
	ldr r4, [sp, 0x108]
	stm r4!, {r0}
	str r4, [sp, 0x108]
	movs r0, 0x1
	add r9, r0
	b _0807F602
	.align 2, 0
_0807F588: .4byte 0xffff0000
_0807F58C: .4byte gAdjacentTileOffsets
_0807F590: .4byte 0x0000ffff
_0807F594:
	movs r5, 0
	add r6, sp, 0xCC
	adds r1, r7, 0x1
	str r1, [sp, 0x104]
	adds r7, r6, 0
	mov r2, r9
	lsls r0, r2, 2
	add r0, sp
	adds r0, 0x18
	mov r10, r0
_0807F5A8:
	ldr r0, _0807F630
	lsls r3, r5, 2
	adds r3, r0
	ldrh r0, [r4, 0x4]
	ldrh r1, [r3]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807F634
	ldr r1, [r6]
	ands r1, r2
	orrs r1, r0
	str r1, [r7]
	ldrh r2, [r4, 0x6]
	ldrh r3, [r3, 0x2]
	adds r2, r3
	lsls r2, 16
	ldr r0, _0807F638
	ands r1, r0
	orrs r1, r2
	str r1, [r7]
	mov r0, r8
	add r1, sp, 0xCC
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	bne _0807F5FC
	mov r2, r9
	cmp r2, 0x27
	bgt _0807F5FC
	ldr r0, [r6]
	mov r3, r10
	adds r3, 0x4
	mov r10, r3
	subs r3, 0x4
	stm r3!, {r0}
	ldr r0, [sp, 0x108]
	adds r0, 0x4
	str r0, [sp, 0x108]
	movs r1, 0x1
	add r9, r1
_0807F5FC:
	adds r5, 0x1
	cmp r5, 0x7
	ble _0807F5A8
_0807F602:
	ldr r7, [sp, 0x104]
	cmp r7, 0x13
	bgt _0807F60A
	b _0807F4A8
_0807F60A:
	mov r2, r9
	cmp r2, 0
	bne _0807F63C
	ldr r3, [sp, 0xF0]
	adds r3, 0x1
	str r3, [sp, 0xF0]
	cmp r3, 0x1
	bgt _0807F61C
	b _0807F49C
_0807F61C:
	ldr r0, [sp, 0xEC]
	adds r0, 0x4
	add r4, sp, 0xB8
	adds r1, r4, 0
	bl sub_80833E8
	movs r7, 0
	add r5, sp, 0xD0
	adds r6, r5, 0
	b _0807F654
	.align 2, 0
_0807F630: .4byte gAdjacentTileOffsets
_0807F634: .4byte 0xffff0000
_0807F638: .4byte 0x0000ffff
_0807F63C:
	mov r0, r9
	bl DungeonRandInt
	lsls r0, 2
	add r0, sp
	adds r0, 0x18
	ldr r0, [r0]
	str r0, [sp, 0xD4]
	b _0807F6A8
_0807F64E:
	ldr r0, [r5]
	str r0, [sp, 0xD4]
	b _0807F68E
_0807F654:
	ldr r0, [r4]
	ldr r1, [r4, 0x8]
	bl DungeonRandRange
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807F6A0
	ldr r1, [r5]
	ands r1, r2
	orrs r1, r0
	str r1, [r6]
	ldr r0, [r4, 0x4]
	ldr r1, [r4, 0xC]
	bl DungeonRandRange
	lsls r0, 16
	ldrh r1, [r6]
	orrs r1, r0
	str r1, [r6]
	mov r0, r8
	add r1, sp, 0xD0
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	beq _0807F64E
	adds r7, 0x1
	cmp r7, 0x63
	ble _0807F654
_0807F68E:
	cmp r7, 0x64
	bne _0807F6A8
	ldr r0, _0807F6A4
_0807F694:
	ldr r2, [r0]
	ldr r0, [sp, 0xEC]
_0807F698:
	mov r1, r8
	bl sub_80522F4
	b _0807F99C
	.align 2, 0
_0807F6A0: .4byte 0xffff0000
_0807F6A4: .4byte gUnknown_80FE6B4
_0807F6A8:
	ldr r0, _0807F860
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807F864
	ldr r2, [r0]
	ldr r0, [sp, 0xEC]
	mov r1, r8
	bl sub_80522F4
	mov r0, r8
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807F6D0
	ldr r0, _0807F868
	bl PlaySoundEffect
_0807F6D0:
	movs r4, 0
	str r4, [sp, 0x100]
	mov r1, r8
	ldr r0, [r1, 0x70]
	adds r0, 0x46
	ldrb r0, [r0]
	mov r9, r0
	add r2, sp, 0xD4
	movs r3, 0
	ldrsh r1, [r2, r3]
	mov r4, r8
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r4, 0x2
	ldrsh r1, [r2, r4]
	mov r2, r8
	movs r4, 0x6
	ldrsh r0, [r2, r4]
	subs r1, r0
	cmp r1, r3
	bge _0807F6FE
	adds r1, r3, 0
_0807F6FE:
	lsls r6, r1, 4
	cmp r6, 0x50
	ble _0807F706
	movs r6, 0x50
_0807F706:
	cmp r6, 0x9
	bgt _0807F70C
	movs r6, 0xA
_0807F70C:
	mov r1, r8
	adds r1, 0x4
	add r0, sp, 0xD4
	bl GetDirectionTowardsPosition
	adds r5, r0, 0
	add r2, sp, 0xD4
	movs r1, 0
	ldrsh r0, [r2, r1]
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 11
	movs r3, 0xC0
	lsls r3, 4
	adds r4, r3
	ldr r0, _0807F86C
	lsls r5, 2
	adds r5, r0
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r0, 8
	movs r1, 0x3
	bl __divsi3
	adds r4, r0
	str r4, [sp, 0xF4]
	movs r3, 0xD6
	add r3, sp
	movs r2, 0
	ldrsh r0, [r3, r2]
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 11
	movs r0, 0x80
	lsls r0, 5
	adds r4, r0
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	lsls r0, 8
	movs r1, 0x3
	bl __divsi3
	adds r4, r0
	str r4, [sp, 0xF8]
	mov r2, r8
	ldr r5, [r2, 0xC]
	ldr r3, [sp, 0xF4]
	subs r0, r3, r5
	adds r1, r6, 0
	bl __divsi3
	str r0, [sp, 0xFC]
	mov r0, r8
	ldr r4, [r0, 0x10]
	ldr r1, [sp, 0xF8]
	subs r0, r1, r4
	adds r1, r6, 0
	bl __divsi3
	mov r10, r0
	add r0, sp, 0xD8
	str r5, [r0]
	str r4, [r0, 0x4]
	movs r7, 0
	adds r5, r0, 0
	cmp r7, r6
	bge _0807F7FC
	adds r4, r5, 0
_0807F794:
	ldr r0, [r5]
	ldr r2, [sp, 0xFC]
	adds r0, r2, r0
	str r0, [r4]
	ldr r0, [r4, 0x4]
	add r0, r10
	str r0, [r4, 0x4]
	mov r0, r8
	adds r1, r4, 0
	bl sub_804535C
	mov r0, r8
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807F7E6
	ldr r0, [sp, 0x100]
	bl sin_abs_4096
	lsls r0, 5
	mov r3, r8
	str r0, [r3, 0x1C]
	movs r0, 0x3B
	bl sub_803E46C
	movs r0, 0x3
	ands r0, r7
	cmp r0, 0
	bne _0807F7E6
	movs r0, 0x7
	mov r1, r9
	ands r1, r0
	mov r9, r1
	mov r0, r8
	movs r1, 0x6
	mov r2, r9
	bl sub_806CDD4
	movs r2, 0x1
	add r9, r2
_0807F7E6:
	movs r0, 0x80
	lsls r0, 4
	adds r1, r6, 0
	bl __divsi3
	ldr r3, [sp, 0x100]
	adds r3, r0
	str r3, [sp, 0x100]
	adds r7, 0x1
	cmp r7, r6
	blt _0807F794
_0807F7FC:
	ldr r4, [sp, 0xF4]
	str r4, [r5]
	add r1, sp, 0xD8
	ldr r0, [sp, 0xF8]
	str r0, [r1, 0x4]
	movs r0, 0
	mov r2, r8
	str r0, [r2, 0x1C]
	mov r0, r8
	bl sub_804535C
	movs r0, 0x3B
	bl sub_803E46C
	mov r3, r8
	ldr r0, [r3, 0x70]
	movs r1, 0x7
	mov r4, r9
	ands r4, r1
	adds r0, 0x46
	strb r4, [r0]
	add r2, sp, 0xD4
	movs r1, 0
	ldrsh r0, [r2, r1]
	adds r4, r2, 0
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	bl GetTile
	ldr r6, [r0, 0x10]
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807F876
	add r2, sp, 0xD4
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	mov r0, r8
	movs r3, 0x1
	bl sub_80694C0
	mov r0, r8
	bl sub_807F9BC
	b _0807F99C
	.align 2, 0
_0807F860: .4byte gAvailablePokemonNames
_0807F864: .4byte gUnknown_80FE690
_0807F868: .4byte 0x000001a3
_0807F86C: .4byte gAdjacentTileOffsets
_0807F870:
	ldr r0, [r7]
	str r0, [sp, 0xD4]
	b _0807F8BE
_0807F876:
	movs r5, 0
	add r4, sp, 0xE0
	adds r7, r4, 0
_0807F87C:
	ldr r0, _0807F8D0
	lsls r3, r5, 2
	adds r3, r0
	add r1, sp, 0xD4
	ldrh r0, [r1]
	ldrh r2, [r3]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807F8D4
	ldr r1, [r7]
	ands r1, r2
	orrs r1, r0
	str r1, [r4]
	add r0, sp, 0xD4
	ldrh r2, [r0, 0x2]
	ldrh r3, [r3, 0x2]
	adds r2, r3
	lsls r2, 16
	ldr r0, _0807F8D8
	ands r1, r0
	orrs r1, r2
	str r1, [r4]
	mov r0, r8
	add r1, sp, 0xE0
	bl sub_80703A0
	lsls r0, 24
	cmp r0, 0
	beq _0807F870
	adds r5, 0x1
	cmp r5, 0x7
	ble _0807F87C
_0807F8BE:
	cmp r5, 0x8
	bne _0807F8DC
	ldr r0, [sp, 0xEC]
	mov r1, r8
	movs r2, 0
	movs r3, 0
	bl sub_807D148
	b _0807F8FA
	.align 2, 0
_0807F8D0: .4byte gAdjacentTileOffsets
_0807F8D4: .4byte 0xffff0000
_0807F8D8: .4byte 0x0000ffff
_0807F8DC:
	mov r0, r8
	add r1, sp, 0xD4
	bl sub_807D068
	add r0, sp, 0xD4
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0xD6
	add r0, sp
	movs r4, 0
	ldrsh r2, [r0, r4]
	mov r0, r8
	movs r3, 0x1
	bl sub_80694C0
_0807F8FA:
	adds r0, r6, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807F954
	add r4, sp, 0xE4
	ldr r1, _0807F9AC
	adds r0, r4, 0
	bl InitPokemonMove
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0807F93C
	ldr r0, _0807F9B0
	movs r3, 0
	ldrsh r2, [r0, r3]
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0807F9B4
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp, 0xEC]
	adds r1, r6, 0
	movs r3, 0
	bl sub_806F370
_0807F93C:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F954
	ldr r0, [r6, 0x70]
	adds r0, 0x46
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_806CE68
_0807F954:
	ldr r0, _0807F9B0
	movs r4, 0
	ldrsh r2, [r0, r4]
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0807F9B8
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	ldr r0, [sp, 0xEC]
	mov r1, r8
	movs r3, 0
	bl sub_806F370
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807F98E
	mov r1, r8
	ldr r0, [r1, 0x70]
	adds r0, 0x46
	ldrb r1, [r0]
	mov r0, r8
	bl sub_806CE68
_0807F98E:
	movs r0, 0x1E
	movs r1, 0x3B
	bl sub_803E708
	mov r0, r8
	bl sub_807F9BC
_0807F99C:
	add sp, 0x10C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F9AC: .4byte 0x00000163
_0807F9B0: .4byte gUnknown_80F4F92
_0807F9B4: .4byte 0x0000021a
_0807F9B8: .4byte 0x00000219
	thumb_func_end sub_807F43C

	thumb_func_start sub_807F9BC
sub_807F9BC:
	push {r4,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807FA0A
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0807F9F4
	ldr r2, _0807FA10
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x1]
	ldr r0, [r2]
	movs r1, 0xB8
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	adds r0, r4, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807F9F4:
	adds r0, r4, 0
	bl sub_806A5B8
	ldr r0, _0807FA10
	ldr r0, [r0]
	ldr r1, _0807FA14
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8075900
_0807FA0A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807FA10: .4byte gDungeon
_0807FA14: .4byte 0x00003a08
	thumb_func_end sub_807F9BC

	thumb_func_start sub_807FA18
sub_807FA18:
	push {r4-r7,lr}
	sub sp, 0x4
	movs r6, 0
_0807FA1E:
	movs r5, 0
	adds r7, r6, 0x1
_0807FA22:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetTileSafe
	adds r4, r0, 0
	ldrh r1, [r4, 0x4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0807FA88
	lsls r0, r5, 16
	lsls r1, r6, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0807FA4E
	movs r0, 0x6
	b _0807FA56
_0807FA4E:
	bl sub_803D6FC
	lsls r0, 24
	lsrs r0, 24
_0807FA56:
	cmp r0, 0x11
	bne _0807FA72
	movs r0, 0x11
	mov r1, sp
	movs r2, 0x2
	bl sub_8045684
	cmp r0, 0
	beq _0807FA88
	str r0, [r4, 0x14]
	adds r1, r0, 0
	adds r1, 0x20
	movs r0, 0x1
	b _0807FA86
_0807FA72:
	mov r1, sp
	movs r2, 0
	bl sub_8045684
	cmp r0, 0
	beq _0807FA88
	str r0, [r4, 0x14]
	adds r1, r0, 0
	adds r1, 0x20
	movs r0, 0
_0807FA86:
	strb r0, [r1]
_0807FA88:
	adds r5, 0x1
	cmp r5, 0x37
	ble _0807FA22
	adds r6, r7, 0
	cmp r6, 0x1F
	ble _0807FA1E
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807FA18

	thumb_func_start sub_807FA9C
sub_807FA9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r2, _0807FAC4
	ldr r0, [r2]
	ldr r3, _0807FAC8
	adds r1, r0, r3
	ldrb r1, [r1]
	str r1, [sp]
	ldr r1, _0807FACC
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0, 0x5
	mov r8, r1
	b _0807FBFE
	.align 2, 0
_0807FAC4: .4byte gDungeon
_0807FAC8: .4byte 0x0001820f
_0807FACC: .4byte 0x000181ea
_0807FAD0:
	ldr r0, [r2]
	ldr r2, _0807FC18
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r5, r0, 0x6
	adds r0, 0x6
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x4]
	cmp r5, r0
	blt _0807FAEA
	b _0807FBEE
_0807FAEA:
	ldr r7, _0807FC1C
	ldr r2, _0807FC20
	mov r10, r2
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 3
	mov r9, r0
_0807FAF8:
	movs r6, 0
	adds r0, r5, 0
	mov r1, r8
	bl GetTile
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FB24
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FB24
	ldr r0, [r4, 0x14]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807FB22
	ldr r3, [sp]
	cmp r3, 0
	beq _0807FB24
_0807FB22:
	movs r6, 0x1
_0807FB24:
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0807FB34
	movs r6, 0x1
_0807FB34:
	cmp r6, 0
	beq _0807FBD6
	ldr r0, _0807FC24
	ldr r1, [r0]
	ldr r3, _0807FC28
	adds r0, r1, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	mov r2, r9
	subs r3, r2, r0
	mov r2, r8
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 3
	ldr r2, _0807FC2C
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	movs r0, 0x20
	negs r0, r0
	cmp r3, r0
	blt _0807FBD6
	cmp r2, r0
	blt _0807FBD6
	movs r0, 0x88
	lsls r0, 1
	cmp r3, r0
	bgt _0807FBD6
	cmp r2, 0xC0
	bgt _0807FBD6
	ldrh r1, [r7]
	mov r0, r10
	ands r0, r1
	strh r0, [r7]
	ldr r1, _0807FC30
	ands r1, r2
	lsls r1, 4
	ldrh r2, [r7, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, 0x6]
	ldr r0, _0807FC34
	ands r3, r0
	ldrh r0, [r7, 0x2]
	movs r2, 0xFE
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	orrs r0, r3
	strh r0, [r7, 0x2]
	ldrh r1, [r7, 0x4]
	mov r0, r10
	ands r0, r1
	movs r3, 0xC0
	lsls r3, 4
	orrs r0, r3
	movs r1, 0
	orrs r0, r1
	movs r1, 0xA0
	lsls r1, 8
	ldr r2, _0807FC30
	ands r0, r2
	orrs r0, r1
	movs r3, 0
	orrs r0, r3
	movs r2, 0xFE
	lsls r2, 1
	movs r3, 0xFC
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r7, 0x4]
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0807FBD6:
	movs r0, 0x18
	add r9, r0
	adds r5, 0x1
	ldr r0, _0807FC24
	ldr r0, [r0]
	ldr r1, _0807FC18
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, 0x6
	cmp r5, r0
	blt _0807FAF8
_0807FBEE:
	ldr r3, [sp, 0x4]
	mov r8, r3
	ldr r2, _0807FC24
	ldr r0, [r2]
	ldr r1, _0807FC38
	adds r0, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
_0807FBFE:
	adds r0, 0x5
	cmp r8, r0
	bge _0807FC06
	b _0807FAD0
_0807FC06:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FC18: .4byte 0x000181e8
_0807FC1C: .4byte gUnknown_202EDC0
_0807FC20: .4byte 0x0000f3ff
_0807FC24: .4byte gDungeon
_0807FC28: .4byte 0x000181f0
_0807FC2C: .4byte 0x000181f2
_0807FC30: .4byte 0x00000fff
_0807FC34: .4byte 0x000001ff
_0807FC38: .4byte 0x000181ea
	thumb_func_end sub_807FA9C

	.align 2, 0
