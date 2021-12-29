	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_807CABC
sub_807CABC:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r6, 0
	b _0807CADC
_0807CAC6:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807CB0A
	ldr r1, _0807CB38
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807CB0A
	adds r6, 0x1
_0807CADC:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8070828
	cmp r6, r0
	bge _0807CB0A
	ldr r5, [r4, 0x70]
	adds r0, r5, 0
	adds r0, 0x48
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8055A00
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807CAC6
_0807CB0A:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8057588
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807CB2A
	ldr r0, [r4, 0x70]
	adds r0, 0x48
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_806A9B4
_0807CB2A:
	adds r0, r4, 0
	bl sub_806A1B0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807CB38: .4byte 0x00000159
	thumb_func_end sub_807CABC

	thumb_func_start sub_807CB3C
sub_807CB3C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r6, r0, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	movs r2, 0x15
	bl sub_8044D90
	adds r2, r0, 0
	ldr r5, [r2]
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0807CB80
	ldr r0, _0807CB78
	adds r1, r2, 0
	bl sub_8045BF8
	ldr r0, _0807CB7C
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _0807CD54
	.align 2, 0
_0807CB78: .4byte gUnknown_202DE58
_0807CB7C: .4byte gUnknown_80FE3E8
_0807CB80:
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r1, 0x44
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _0807CBAC
	ldr r0, _0807CBA8
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	movs r4, 0x1
	b _0807CCDE
	.align 2, 0
_0807CBA8: .4byte gPtrMysteriousPowerPreventedUseMessage
_0807CBAC:
	movs r0, 0x1
	mov r8, r0
	add r4, sp, 0x20
	lsls r5, 8
	lsrs r0, r5, 24
	bl GetItemMove
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl InitPokemonMove
	ldrb r0, [r7, 0x7]
	mov r10, r4
	mov r9, r5
	cmp r0, 0
	bne _0807CC08
	ldr r1, _0807CC20
	ldr r0, [sp, 0x28]
	ands r0, r1
	mov r1, r8
	orrs r0, r1
	str r0, [sp, 0x28]
	movs r0, 0xA
	add r4, sp, 0x28
	str r0, [r4, 0x4]
	movs r3, 0x8C
	lsls r3, 1
	adds r2, r7, r3
	adds r0, r4, 0
	adds r1, r6, 0
	bl FindMoveTarget
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807CC08
	ldrb r1, [r4, 0x1]
	movs r0, 0x7
	ands r0, r1
	adds r1, r7, 0
	adds r1, 0x46
	strb r0, [r1]
	adds r0, r6, 0
	bl TargetTileInFront
_0807CC08:
	adds r0, r7, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807CC2C
	ldr r0, _0807CC24
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807CC28
	b _0807CC3C
	.align 2, 0
_0807CC20: .4byte 0xffffff00
_0807CC24: .4byte gAvailablePokemonNames
_0807CC28: .4byte gUnknown_80FC714
_0807CC2C:
	cmp r0, 0x7
	bne _0807CC50
	ldr r0, _0807CC48
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807CC4C
_0807CC3C:
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _0807CCDC
	.align 2, 0
_0807CC48: .4byte gAvailablePokemonNames
_0807CC4C: .4byte gUnknown_80FC718
_0807CC50:
	adds r0, r7, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0807CC72
	ldr r0, _0807CCB8
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807CCBC
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	movs r4, 0
	mov r8, r4
_0807CC72:
	mov r0, r8
	cmp r0, 0
	beq _0807CCDC
	mov r5, r9
	lsrs r0, r5, 24
	cmp r0, 0xB6
	beq _0807CC84
	cmp r0, 0xBF
	bne _0807CCC0
_0807CC84:
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x7A
	bl sub_8044DF0
	mov r2, r10
	ldrb r1, [r2]
	movs r0, 0x8
	movs r4, 0
	orrs r0, r1
	add r3, sp, 0x20
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0xA
	strb r0, [r3, 0x4]
	lsrs r2, r5, 24
	str r4, [sp]
	str r3, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl sub_8055FA0
	b _0807CCDE
	.align 2, 0
_0807CCB8: .4byte gAvailablePokemonNames
_0807CCBC: .4byte gUnknown_80FC6A8
_0807CCC0:
	mov r3, r9
	lsrs r2, r3, 24
	movs r0, 0
	str r0, [sp]
	mov r4, r10
	str r4, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl sub_8055FA0
	lsls r0, 24
	lsrs r4, r0, 24
	b _0807CCDE
_0807CCDC:
	movs r4, 0
_0807CCDE:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807CD38
	cmp r4, 0
	beq _0807CCF8
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x7A
	bl sub_8044DF0
_0807CCF8:
	adds r0, r6, 0
	bl sub_8071DA4
	adds r0, r6, 0
	movs r1, 0x8
	bl sub_806CE68
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0807CD18
	adds r0, r6, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807CD18:
	adds r0, r6, 0
	bl sub_806A5B8
	ldr r0, _0807CD30
	ldr r0, [r0]
	ldr r1, _0807CD34
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8075900
	b _0807CD44
	.align 2, 0
_0807CD30: .4byte gDungeonGlobalData
_0807CD34: .4byte 0x00003a08
_0807CD38:
	cmp r4, 0
	beq _0807CD44
	add r0, sp, 0x8
	movs r1, 0
	bl sub_8044D40
_0807CD44:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807CD54
	adds r0, r6, 0
	bl sub_806A1B0
_0807CD54:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807CB3C

	thumb_func_start GetTargetingFlags
GetTargetingFlags:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	ldrh r0, [r4, 0x2]
	cmp r0, 0xED
	bne _0807CD88
	cmp r5, 0
	bne _0807CD88
	adds r0, r3, 0
	movs r1, 0xE
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _0807CD88
	movs r0, 0x73
	b _0807CD94
_0807CD88:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMoveTargetingFlags
	lsls r0, 16
	asrs r0, 16
_0807CD94:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetTargetingFlags

	thumb_func_start sub_807CD9C
sub_807CD9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	mov r9, r0
	adds r6, r1, 0
	adds r4, r2, 0
	movs r0, 0xA
	str r0, [sp, 0x24]
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	beq _0807CDC4
	ldr r0, _0807CDC0
	b _0807CDFE
	.align 2, 0
_0807CDC0: .4byte gUnknown_80FC9E8
_0807CDC4:
	cmp r9, r6
	bne _0807CDE4
	ldr r0, _0807CDDC
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807CDE0
	ldr r2, [r0]
	adds r0, r6, 0
	b _0807CE02
	.align 2, 0
_0807CDDC: .4byte gAvailablePokemonNames
_0807CDE0: .4byte gUnknown_80FCA10
_0807CDE4:
	ldr r0, _0807CE0C
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	movs r1, 0xE
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807CE28
	ldr r0, _0807CE10
_0807CDFE:
	ldr r2, [r0]
	mov r0, r9
_0807CE02:
	adds r1, r6, 0
	bl sub_80522F4
	b _0807D02A
	.align 2, 0
_0807CE0C: .4byte gAvailablePokemonNames
_0807CE10: .4byte gUnknown_80FCBCC
_0807CE14:
	str r0, [sp, 0x28]
	b _0807CF26
_0807CE18:
	ldrh r0, [r5]
	movs r1, 0x3
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r10, r0
	b _0807CF20
_0807CE28:
	ldr r1, [r6, 0x70]
	adds r2, r4, 0x4
	movs r3, 0x7
	adds r0, r2, 0
	ands r0, r3
	adds r1, 0x46
	strb r0, [r1]
	movs r0, 0x7
	ands r2, r0
	adds r0, r6, 0
	movs r1, 0x6
	bl sub_806CDD4
	ldr r1, _0807D03C
	adds r0, r6, 0
	bl sub_80421C0
	ldr r0, _0807D040
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	movs r1, 0x1
	mov r10, r1
	movs r2, 0
	str r2, [sp, 0x28]
	lsls r1, r4, 2
	ldr r0, _0807D044
	adds r1, r0
	mov r8, r1
	add r7, sp, 0x18
_0807CE68:
	ldr r2, [r6, 0x4]
	str r2, [sp, 0x18]
	ldrh r0, [r7]
	mov r3, r8
	ldrh r3, [r3]
	adds r0, r3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _0807D048
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x18]
	asrs r0, r1, 16
	mov r2, r8
	ldrh r2, [r2, 0x2]
	adds r0, r2
	lsls r0, 16
	ldr r2, _0807D04C
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x18]
	movs r3, 0
	ldrsh r0, [r7, r3]
	cmp r0, 0
	blt _0807CF20
	asrs r1, r2, 16
	cmp r1, 0
	blt _0807CF20
	cmp r0, 0x37
	bgt _0807CF20
	cmp r1, 0x1F
	bgt _0807CF20
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	lsls r0, 10
	str r0, [sp, 0x2C]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	lsls r0, 10
	str r0, [sp, 0x30]
	movs r4, 0x5
_0807CEBC:
	adds r0, r6, 0
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	bl sub_804539C
	adds r0, r6, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807CED8
	movs r0, 0x19
	bl sub_803E46C
_0807CED8:
	subs r4, 0x1
	cmp r4, 0
	bge _0807CEBC
	movs r1, 0
	ldrsh r0, [r7, r1]
	ldr r1, [sp, 0x18]
	asrs r1, 16
	bl GetMapTileAtPosition
	adds r5, r0, 0
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _0807CE14
	add r4, sp, 0x18
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	bne _0807CE18
	movs r2, 0
	ldrsh r1, [r7, r2]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	adds r0, r6, 0
	movs r3, 0x1
	bl sub_80694C0
	ldr r0, [sp, 0x24]
	subs r0, 0x1
	str r0, [sp, 0x24]
	cmp r0, 0
	bgt _0807CE68
	movs r1, 0x1
	mov r10, r1
_0807CF20:
	mov r2, r10
	cmp r2, 0
	bne _0807CF4E
_0807CF26:
	adds r1, r6, 0x4
	adds r0, r6, 0
	bl sub_807D068
	ldr r0, _0807D050
	movs r3, 0
	ldrsh r2, [r0, r3]
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	ldr r0, _0807D054
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	mov r0, r9
	adds r1, r6, 0
	movs r3, 0
	bl sub_806F370
_0807CF4E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807D02A
	ldr r0, [sp, 0x28]
	cmp r0, 0
	beq _0807CF9E
	add r4, sp, 0x1C
	ldr r1, _0807D058
	adds r0, r4, 0
	bl InitPokemonMove
	ldr r0, [sp, 0x28]
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0807CF9E
	mov r0, r9
	ldr r1, [sp, 0x28]
	bl sub_807A96C
	ldr r0, _0807D050
	movs r1, 0
	ldrsh r2, [r0, r1]
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r0, _0807D05C
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	str r4, [sp, 0x14]
	mov r0, r9
	ldr r1, [sp, 0x28]
	movs r3, 0
	bl sub_806F370
_0807CF9E:
	bl sub_8044B28
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0807D02A
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807D02A
	adds r0, r6, 0
	bl sub_806A5B8
	adds r4, r6, 0x4
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _0807CFD8
	adds r0, r6, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_0807CFD8:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807D02A
	adds r0, r6, 0
	movs r1, 0x8
	bl sub_806CE68
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0807D014
	ldr r1, _0807D060
	ldr r0, [r1]
	strb r5, [r0, 0x1]
	ldr r0, [r1]
	movs r2, 0xB8
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	adds r0, r4, 0
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807D014:
	adds r0, r6, 0
	bl sub_806A5B8
	ldr r0, _0807D060
	ldr r0, [r0]
	ldr r3, _0807D064
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8075900
_0807D02A:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807D03C: .4byte 0x000001a3
_0807D040: .4byte gUnknown_80F8A0C
_0807D044: .4byte gAdjacentTileOffsets
_0807D048: .4byte 0xffff0000
_0807D04C: .4byte 0x0000ffff
_0807D050: .4byte gUnknown_80F4F90
_0807D054: .4byte 0x00000219
_0807D058: .4byte 0x00000163
_0807D05C: .4byte 0x0000021a
_0807D060: .4byte gDungeonGlobalData
_0807D064: .4byte 0x00003a08
	thumb_func_end sub_807CD9C

	thumb_func_start sub_807D068
sub_807D068:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r6, r0, 0
	movs r0, 0
	ldrsh r2, [r1, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 11
	movs r2, 0xC0
	lsls r2, 4
	adds r2, r0
	mov r10, r2
	movs r0, 0x2
	ldrsh r1, [r1, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0x80
	lsls r1, 5
	adds r1, r0
	mov r9, r1
	ldr r0, [r6, 0xC]
	subs r0, r2
	cmp r0, 0
	bge _0807D0A4
	negs r0, r0
_0807D0A4:
	ldr r1, [r6, 0x10]
	cmp r0, 0xB
	bgt _0807D0B8
	mov r2, r9
	subs r0, r1, r2
	cmp r0, 0
	bge _0807D0B4
	negs r0, r0
_0807D0B4:
	cmp r0, 0xB
	ble _0807D11E
_0807D0B8:
	movs r0, 0
	mov r8, r0
	ldr r5, [r6, 0xC]
	adds r4, r1, 0
	mov r1, r10
	subs r0, r1, r5
	movs r1, 0xC
	bl __divsi3
	str r0, [sp, 0x8]
	mov r2, r9
	subs r0, r2, r4
	movs r1, 0xC
	bl __divsi3
	str r0, [sp, 0xC]
	mov r0, sp
	str r0, [sp, 0x10]
	movs r7, 0xB
_0807D0DE:
	ldr r1, [sp, 0x8]
	adds r5, r1
	ldr r2, [sp, 0xC]
	adds r4, r2
	str r5, [sp]
	ldr r0, [sp, 0x10]
	str r4, [r0, 0x4]
	mov r0, r8
	bl sub_8009C7C
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	str r1, [r6, 0x1C]
	adds r0, r6, 0
	mov r1, sp
	bl sub_804535C
	adds r0, r6, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807D114
	movs r0, 0x1A
	bl sub_803E46C
_0807D114:
	movs r1, 0xAA
	add r8, r1
	subs r7, 0x1
	cmp r7, 0
	bge _0807D0DE
_0807D11E:
	mov r2, r10
	str r2, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [r6, 0x1C]
	adds r0, r6, 0
	mov r1, sp
	bl sub_804535C
	movs r0, 0x1A
	bl sub_803E46C
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807D068

	thumb_func_start sub_807D148
sub_807D148:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	adds r5, r1, 0
	mov r9, r2
	str r3, [sp, 0x4]
	ldr r0, [r5, 0x70]
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x8]
	ldr r0, _0807D180
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	movs r1, 0xE
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807D188
	ldr r0, _0807D184
	b _0807D194
	.align 2, 0
_0807D180: .4byte gAvailablePokemonNames
_0807D184: .4byte gUnknown_80FCAE8
_0807D188:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	beq _0807D1A4
	ldr r0, _0807D1A0
_0807D194:
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	b _0807D3A8
	.align 2, 0
_0807D1A0: .4byte gUnknown_80FC97C
_0807D1A4:
	mov r2, r9
	cmp r2, 0x1
	bne _0807D1DC
	ldr r0, _0807D1D0
	ldr r0, [r0]
	ldr r3, _0807D1D4
	adds r0, r3
	ldr r1, [r0]
	ldr r0, [r5, 0x4]
	cmp r1, r0
	bne _0807D1DC
	ldr r0, _0807D1D8
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	mov r0, r8
	adds r1, r5, 0
	bl sub_8076D10
	b _0807D3A8
	.align 2, 0
_0807D1D0: .4byte gDungeonGlobalData
_0807D1D4: .4byte 0x0000e21c
_0807D1D8: .4byte gUnknown_80FC9A0
_0807D1DC:
	ldr r0, _0807D27C
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	mov r0, r8
	adds r1, r5, 0
	bl sub_80421AC
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807D252
	mov r0, r10
	adds r0, 0x46
	ldrb r4, [r0]
	ldr r1, [r5, 0x1C]
	movs r2, 0x80
	lsls r2, 4
	adds r1, r2
	str r1, [r5, 0x1C]
	ldr r2, _0807D280
	adds r6, r0, 0
	cmp r1, r2
	bgt _0807D252
	movs r7, 0x7
_0807D21E:
	ldr r0, _0807D284
	ldr r0, [r0]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0807D23C
	adds r4, 0x1
	ands r4, r7
	adds r0, r4, 0
	ands r0, r7
	strb r0, [r6]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806CE68
_0807D23C:
	movs r0, 0x22
	bl sub_803E46C
	ldr r1, [r5, 0x1C]
	movs r3, 0x80
	lsls r3, 4
	adds r1, r3
	str r1, [r5, 0x1C]
	ldr r0, _0807D280
	cmp r1, r0
	ble _0807D21E
_0807D252:
	mov r0, r9
	cmp r0, 0x1
	beq _0807D288
	cmp r0, 0x1
	bcc _0807D264
	cmp r0, 0x2
	beq _0807D2B0
	cmp r0, 0x3
	beq _0807D2C8
_0807D264:
	mov r0, sp
	bl sub_8083660
	lsls r0, 24
	cmp r0, 0
	bne _0807D2CE
	ldr r0, [r5, 0x4]
	str r0, [sp]
	movs r1, 0x1
	str r1, [sp, 0x8]
	b _0807D2CE
	.align 2, 0
_0807D27C: .4byte gUnknown_80FC584
_0807D280: .4byte 0x00009fff
_0807D284: .4byte gUnknown_202EDCC
_0807D288:
	ldr r0, _0807D2A8
	ldr r1, [r0]
	ldr r2, _0807D2AC
	adds r1, r2
	mov r0, sp
	bl sub_808384C
	lsls r0, 24
	cmp r0, 0
	bne _0807D2CE
	ldr r0, [r5, 0x4]
	str r0, [sp]
	movs r3, 0x1
	str r3, [sp, 0x8]
	b _0807D2CE
	.align 2, 0
_0807D2A8: .4byte gDungeonGlobalData
_0807D2AC: .4byte 0x0000e21c
_0807D2B0:
	mov r0, sp
	ldr r1, [sp, 0x4]
	bl sub_808384C
	lsls r0, 24
	cmp r0, 0
	bne _0807D2CE
	ldr r0, [r5, 0x4]
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x8]
	b _0807D2CE
_0807D2C8:
	ldr r1, [sp, 0x4]
	ldr r0, [r1]
	str r0, [sp]
_0807D2CE:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	adds r0, r5, 0
	movs r3, 0x1
	bl sub_80694C0
	adds r0, r5, 0
	movs r1, 0
	bl sub_804535C
	adds r0, r5, 0
	bl sub_807BB78
	movs r0, 0x1
	bl sub_803F580
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807D340
	mov r1, r10
	adds r1, 0x46
	ldrb r4, [r1]
	movs r0, 0x9C
	lsls r0, 8
	str r0, [r5, 0x1C]
	adds r6, r1, 0
	movs r7, 0x7
_0807D310:
	ldr r0, _0807D3B8
	ldr r0, [r0]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0807D32E
	adds r4, 0x1
	ands r4, r7
	adds r0, r4, 0
	ands r0, r7
	strb r0, [r6]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806CE68
_0807D32E:
	movs r0, 0x22
	bl sub_803E46C
	ldr r0, [r5, 0x1C]
	ldr r1, _0807D3BC
	adds r0, r1
	str r0, [r5, 0x1C]
	cmp r0, 0
	bgt _0807D310
_0807D340:
	movs r4, 0
	str r4, [r5, 0x1C]
	movs r0, 0x22
	bl sub_803E46C
	ldr r2, [sp, 0x8]
	cmp r2, 0
	beq _0807D35C
	ldr r0, _0807D3C0
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
_0807D35C:
	mov r3, r9
	cmp r3, 0x1
	bne _0807D36A
	mov r0, r8
	adds r1, r5, 0
	bl sub_8076D10
_0807D36A:
	mov r1, r10
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _0807D392
	adds r0, r5, 0x4
	bl sub_804AC20
	ldr r1, _0807D3C4
	ldr r0, [r1]
	strb r4, [r0, 0x1]
	ldr r0, [r1]
	movs r2, 0xB8
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	movs r0, 0
	bl sub_807EC28
_0807D392:
	adds r0, r5, 0
	bl sub_806A5B8
	ldr r0, _0807D3C4
	ldr r0, [r0]
	ldr r3, _0807D3C8
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8075900
_0807D3A8:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807D3B8: .4byte gUnknown_202EDCC
_0807D3BC: .4byte 0xfffffc00
_0807D3C0: .4byte gUnknown_80FCB14
_0807D3C4: .4byte gDungeonGlobalData
_0807D3C8: .4byte 0x00003a08
	thumb_func_end sub_807D148

	thumb_func_start sub_807D3CC
sub_807D3CC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	movs r2, 0
	ldr r4, _0807D448
	ldr r0, [r4]
	ldr r1, _0807D44C
	adds r0, r1
	ldrb r6, [r0]
	cmp r6, 0
	bne _0807D3E8
	movs r6, 0x2
_0807D3E8:
	mov r0, r8
	str r2, [sp]
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r2, [sp]
	cmp r1, 0xFF
	bne _0807D450
	mov r3, r8
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	subs r5, r0, r6
	adds r0, r6
	cmp r5, r0
	bgt _0807D4A8
_0807D408:
	mov r3, r8
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	subs r4, r0, r6
	adds r0, r6
	adds r7, r5, 0x1
	cmp r4, r0
	bgt _0807D438
_0807D418:
	adds r0, r4, 0
	adds r1, r5, 0
	str r2, [sp]
	bl sub_807D4E0
	ldr r2, [sp]
	orrs r2, r0
	lsls r0, r2, 24
	lsrs r2, r0, 24
	adds r4, 0x1
	mov r3, r8
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	adds r0, r6
	cmp r4, r0
	ble _0807D418
_0807D438:
	adds r5, r7, 0
	mov r3, r8
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	adds r0, r6
	cmp r5, r0
	ble _0807D408
	b _0807D4A8
	.align 2, 0
_0807D448: .4byte gDungeonGlobalData
_0807D44C: .4byte 0x00018209
_0807D450:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r3, _0807D468
	adds r0, r3
	ldr r1, [r4]
	adds r6, r1, r0
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	subs r5, r0, 0x1
	b _0807D49E
	.align 2, 0
_0807D468: .4byte 0x000104c4
_0807D46C:
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	subs r4, r0, 0x1
	movs r3, 0x6
	ldrsh r0, [r6, r3]
	adds r0, 0x1
	adds r7, r5, 0x1
	cmp r4, r0
	bgt _0807D49C
_0807D47E:
	adds r0, r4, 0
	adds r1, r5, 0
	str r2, [sp]
	bl sub_807D4E0
	ldr r2, [sp]
	orrs r2, r0
	lsls r0, r2, 24
	lsrs r2, r0, 24
	adds r4, 0x1
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	adds r0, 0x1
	cmp r4, r0
	ble _0807D47E
_0807D49C:
	adds r5, r7, 0
_0807D49E:
	movs r3, 0x8
	ldrsh r0, [r6, r3]
	adds r0, 0x1
	cmp r5, r0
	ble _0807D46C
_0807D4A8:
	cmp r2, 0
	beq _0807D4C4
	ldr r0, _0807D4C0
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	bl sub_8040A84
	bl sub_8049ED4
	b _0807D4CE
	.align 2, 0
_0807D4C0: .4byte gUnknown_80FD2F8
_0807D4C4:
	ldr r0, _0807D4DC
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
_0807D4CE:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807D4DC: .4byte gUnknown_80FD320
	thumb_func_end sub_807D3CC

	thumb_func_start sub_807D4E0
sub_807D4E0:
	push {r4,lr}
	bl GetMapTileAtPosition
	ldr r4, [r0, 0x14]
	cmp r4, 0
	beq _0807D506
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _0807D506
	adds r1, r4, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _0807D506
	movs r0, 0x1
	strb r0, [r1]
	b _0807D508
_0807D506:
	movs r0, 0
_0807D508:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_807D4E0

	thumb_func_start sub_807D510
sub_807D510:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0807D540
	add sp, r4
	ldr r1, _0807D544
	add r1, sp
	str r0, [r1]
	movs r2, 0
	movs r3, 0xD1
	lsls r3, 4
	add r3, sp
	str r2, [r3]
	ldr r4, _0807D548
	add r4, sp
	str r2, [r4]
	add r5, sp, 0x4
	mov r8, r5
	mov r10, r2
	mov r9, r2
	add r7, sp, 0x8
	b _0807D606
	.align 2, 0
_0807D540: .4byte 0xfffff2d4
_0807D544: .4byte 0x00000d08
_0807D548: .4byte 0x00000d0c
_0807D54C:
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	ldr r2, _0807D650
	add r2, sp
	ldr r2, [r2]
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	subs r1, r0
	cmp r1, 0
	bge _0807D562
	negs r1, r1
_0807D562:
	cmp r1, 0x2
	bgt _0807D580
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	ldr r4, _0807D650
	add r4, sp
	ldr r4, [r4]
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807D57C
	negs r1, r1
_0807D57C:
	cmp r1, 0x2
	ble _0807D5FE
_0807D580:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl GetMapTileAtPosition
	ldrh r1, [r0]
	movs r2, 0x3
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0807D5FE
	mov r3, r8
	str r2, [r3]
	ldr r4, _0807D654
	add r4, sp
	ldr r1, _0807D658
	add r1, sp
	ldr r1, [r1]
	lsls r0, r1, 2
	adds r4, r0
	str r4, [r7, 0x6C]
	ldr r0, [r5, 0x4]
	str r0, [r7]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	mov r0, r8
	bl sub_8045394
	movs r2, 0
	movs r1, 0
	strh r1, [r7, 0x22]
	movs r0, 0x1
	strb r0, [r7, 0x1C]
	strb r2, [r7, 0x1E]
	str r1, [r7, 0x18]
	ldr r0, _0807D65C
	ldr r0, [r0]
	ldr r5, _0807D660
	adds r0, r5
	add r0, r9
	ldr r0, [r0]
	str r0, [r4]
	adds r7, 0x74
	movs r0, 0x74
	add r8, r0
	ldr r2, _0807D658
	add r2, sp
	ldr r1, [r2]
	adds r1, 0x1
	str r1, [r2]
_0807D5FE:
	movs r3, 0x4
	add r9, r3
	movs r4, 0x1
	add r10, r4
_0807D606:
	ldr r0, _0807D65C
	ldr r1, [r0]
	ldr r5, _0807D664
	adds r0, r1, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r10, r0
	bge _0807D634
	ldr r3, _0807D668
	adds r0, r1, r3
	add r0, r9
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807D5FE
	ldr r4, _0807D658
	add r4, sp
	ldr r4, [r4]
	cmp r4, 0x18
	ble _0807D54C
_0807D634:
	ldr r5, _0807D658
	add r5, sp
	ldr r5, [r5]
	cmp r5, 0
	bne _0807D670
	ldr r0, _0807D66C
	ldr r1, [r0]
	ldr r2, _0807D650
	add r2, sp
	ldr r0, [r2]
	bl SendMessage
	b _0807D9F4
	.align 2, 0
_0807D650: .4byte 0x00000d08
_0807D654: .4byte 0x00000b58
_0807D658: .4byte 0x00000d0c
_0807D65C: .4byte gDungeonGlobalData
_0807D660: .4byte 0x00003804
_0807D664: .4byte 0x00003904
_0807D668: .4byte 0x0001361c
_0807D66C: .4byte gUnknown_80FE034
_0807D670:
	movs r1, 0
	movs r7, 0x1D
	ldr r0, _0807D754
	add r0, sp
_0807D678:
	strb r1, [r0]
	subs r0, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _0807D678
	movs r7, 0
	ldr r3, _0807D758
	add r3, sp
	ldr r3, [r3]
	cmp r7, r3
	blt _0807D690
	b _0807D7CC
_0807D690:
	ldr r4, _0807D75C
	mov r10, r4
	ldr r5, _0807D760
	movs r0, 0
	ldrsh r5, [r5, r0]
	ldr r0, _0807D764
	add r0, sp
	str r5, [r0]
_0807D6A0:
	movs r1, 0
	mov r9, r1
	ldr r2, _0807D768
	add r2, sp
	ldr r2, [r2]
	ldrh r0, [r2, 0x4]
	ldr r1, _0807D76C
	ands r6, r1
	orrs r6, r0
	ldrh r0, [r2, 0x6]
	lsls r0, 16
	mov r4, r10
	ands r6, r4
	orrs r6, r0
	mov r4, r9
	adds r5, r7, 0x1
	movs r0, 0xD2
	lsls r0, 4
	add r0, sp
	str r5, [r0]
	ldr r1, _0807D760
	ldr r2, _0807D764
	add r2, sp
	ldr r2, [r2]
	cmp r2, 0x63
	beq _0807D790
	ldr r3, _0807D770
	add r3, sp
	mov r8, r3
_0807D6DA:
	ldr r0, _0807D774
	add r0, sp
	adds r0, r4
	ldr r5, _0807D778
	add r5, sp
	str r0, [r5]
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807D77C
	lsls r2, r4, 2
	adds r2, r1
	ldrh r0, [r2]
	ldr r1, _0807D768
	add r1, sp
	ldr r1, [r1]
	ldrh r1, [r1, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _0807D76C
	ands r6, r1
	orrs r6, r0
	ldrh r0, [r2, 0x2]
	ldr r2, _0807D768
	add r2, sp
	ldr r2, [r2]
	ldrh r2, [r2, 0x6]
	adds r0, r2
	lsls r0, 16
	mov r3, r10
	ands r6, r3
	orrs r6, r0
	lsls r0, r6, 16
	asrs r0, 16
	asrs r1, r6, 16
	bl GetMapTileAtPosition
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r3, 0x3
	ands r3, r1
	cmp r3, 0x1
	bne _0807D77C
	movs r5, 0x80
	lsls r5, 2
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0807D77C
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _0807D77C
	lsls r0, r7, 2
	add r0, r8
	str r6, [r0]
	ldr r0, _0807D778
	add r0, sp
	ldr r0, [r0]
	strb r3, [r0]
	b _0807D7B8
	.align 2, 0
_0807D754: .4byte 0x00000d05
_0807D758: .4byte 0x00000d0c
_0807D75C: .4byte 0x0000ffff
_0807D760: .4byte gUnknown_80F4468
_0807D764: .4byte 0x00000d18
_0807D768: .4byte 0x00000d08
_0807D76C: .4byte 0xffff0000
_0807D770: .4byte 0x00000bbc
_0807D774: .4byte 0x00000ce8
_0807D778: .4byte 0x00000d28
_0807D77C:
	adds r4, 0x1
	cmp r4, 0x1D
	bgt _0807D790
	lsls r0, r4, 2
	ldr r1, _0807D9B4
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x63
	bne _0807D6DA
_0807D790:
	mov r3, r9
	cmp r3, 0
	bne _0807D7B8
	movs r0, 0x74
	muls r0, r7
	add r0, sp
	adds r0, 0x4
	str r3, [r0]
	ldr r1, _0807D9B8
	add r1, sp
	lsls r0, r7, 2
	adds r1, r0
	ldrh r2, [r1]
	mov r0, r10
	orrs r0, r2
	strh r0, [r1]
	ldrh r2, [r1, 0x2]
	mov r0, r10
	orrs r0, r2
	strh r0, [r1, 0x2]
_0807D7B8:
	movs r4, 0xD2
	lsls r4, 4
	add r4, sp
	ldr r7, [r4]
	ldr r5, _0807D9BC
	add r5, sp
	ldr r5, [r5]
	cmp r7, r5
	bge _0807D7CC
	b _0807D6A0
_0807D7CC:
	movs r7, 0
	ldr r0, _0807D9BC
	add r0, sp
	ldr r0, [r0]
	cmp r7, r0
	bge _0807D866
_0807D7D8:
	movs r0, 0x74
	adds r1, r7, 0
	muls r1, r0
	mov r8, r1
	mov r4, sp
	add r4, r8
	adds r4, 0x4
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807D85A
	adds r0, r4, 0x4
	movs r1, 0x1
	bl sub_80461C8
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	bl sub_80402AC
	movs r5, 0xC2
	lsls r5, 4
	add r5, sp
	lsls r6, r7, 3
	adds r5, r6
	ldr r4, _0807D9B8
	add r4, sp
	lsls r0, r7, 2
	adds r4, r0
	movs r0, 0
	ldrsh r1, [r4, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r0, 8
	add r1, sp, 0x10
	add r1, r8
	ldr r1, [r1]
	subs r0, r1
	movs r1, 0x3C
	bl __divsi3
	str r0, [r5]
	ldr r5, _0807D9C0
	add r5, sp
	adds r5, r6
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, 0x4
	lsls r0, 8
	add r1, sp, 0x14
	add r1, r8
	ldr r1, [r1]
	subs r0, r1
	movs r1, 0x3C
	bl __divsi3
	str r0, [r5]
_0807D85A:
	adds r7, 0x1
	ldr r3, _0807D9BC
	add r3, sp
	ldr r3, [r3]
	cmp r7, r3
	blt _0807D7D8
_0807D866:
	movs r1, 0xD1
	lsls r1, 1
	ldr r4, _0807D9C4
	add r4, sp
	ldr r0, [r4]
	bl sub_80421C0
	movs r5, 0
	mov r9, r5
	ldr r0, _0807D9C8
	ldr r0, [r0]
	ldr r1, _0807D9CC
	adds r0, r1
	ldrb r0, [r0]
	ldr r2, _0807D9D0
	add r2, sp
	str r0, [r2]
	mov r10, r5
	movs r6, 0
_0807D88C:
	movs r7, 0
	mov r3, r10
	adds r3, 0x22
	ldr r4, _0807D9D4
	add r4, sp
	str r3, [r4]
	adds r5, r6, 0x1
	ldr r0, _0807D9D8
	add r0, sp
	str r5, [r0]
	ldr r1, _0807D9BC
	add r1, sp
	ldr r1, [r1]
	cmp r7, r1
	bge _0807D916
	mov r2, r9
	lsls r2, 24
	mov r8, r2
_0807D8B0:
	movs r0, 0x74
	adds r5, r7, 0
	muls r5, r0
	mov r4, sp
	adds r4, r5
	adds r4, 0x4
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807D90A
	movs r0, 0xC2
	lsls r0, 4
	add r0, sp
	lsls r2, r7, 3
	adds r0, r2
	ldr r1, [r0]
	ldr r0, _0807D9C0
	add r0, sp
	adds r0, r2
	ldr r2, [r0]
	adds r0, r4, 0
	bl sub_804539C
	mov r0, r10
	bl sub_8009C7C
	add r2, sp, 0x20
	adds r2, r5
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	str r1, [r2]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	ldr r3, _0807D9D0
	add r3, sp
	ldr r1, [r3]
	movs r2, 0
	mov r4, r8
	lsrs r3, r4, 24
	bl sub_80462AC
_0807D90A:
	adds r7, 0x1
	ldr r5, _0807D9BC
	add r5, sp
	ldr r5, [r5]
	cmp r7, r5
	blt _0807D8B0
_0807D916:
	movs r0, 0x13
	bl sub_803E46C
	ldr r0, _0807D9D4
	add r0, sp
	ldr r0, [r0]
	mov r10, r0
	movs r0, 0x3
	ands r0, r6
	cmp r0, 0
	bne _0807D930
	movs r1, 0x1
	add r9, r1
_0807D930:
	movs r0, 0x7
	mov r2, r9
	ands r2, r0
	mov r9, r2
	ldr r3, _0807D9D8
	add r3, sp
	ldr r6, [r3]
	cmp r6, 0x3B
	ble _0807D88C
	movs r7, 0
	ldr r4, _0807D9BC
	add r4, sp
	ldr r4, [r4]
	cmp r7, r4
	bge _0807D996
_0807D94E:
	ldr r0, _0807D9B8
	add r0, sp
	lsls r1, r7, 2
	adds r4, r0, r1
	movs r5, 0
	ldrsh r0, [r4, r5]
	cmp r0, 0
	blt _0807D98A
	movs r0, 0x74
	muls r0, r7
	add r0, sp
	adds r0, 0x4
	bl GetItemData
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80460F8
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_80402AC
	movs r3, 0x1
	movs r4, 0xD1
	lsls r4, 4
	add r4, sp
	str r3, [r4]
_0807D98A:
	adds r7, 0x1
	ldr r5, _0807D9BC
	add r5, sp
	ldr r5, [r5]
	cmp r7, r5
	blt _0807D94E
_0807D996:
	movs r0, 0xD1
	lsls r0, 4
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	beq _0807D9E0
	ldr r0, _0807D9DC
	ldr r1, [r0]
	ldr r2, _0807D9C4
	add r2, sp
	ldr r0, [r2]
	bl SendMessage
	b _0807D9EE
	.align 2, 0
_0807D9B4: .4byte gUnknown_80F4468
_0807D9B8: .4byte 0x00000bbc
_0807D9BC: .4byte 0x00000d0c
_0807D9C0: .4byte 0x00000c24
_0807D9C4: .4byte 0x00000d08
_0807D9C8: .4byte gDungeonGlobalData
_0807D9CC: .4byte 0x00018210
_0807D9D0: .4byte 0x00000d14
_0807D9D4: .4byte 0x00000d1c
_0807D9D8: .4byte 0x00000d24
_0807D9DC: .4byte gUnknown_80FE060
_0807D9E0:
	ldr r0, _0807DA08
	ldr r1, [r0]
	ldr r3, _0807DA0C
	add r3, sp
	ldr r0, [r3]
	bl SendMessage
_0807D9EE:
	movs r0, 0x1
	bl sub_807EC28
_0807D9F4:
	ldr r3, _0807DA10
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807DA08: .4byte gUnknown_80FE034
_0807DA0C: .4byte 0x00000d08
_0807DA10: .4byte 0x00000d2c
	thumb_func_end sub_807D510

	thumb_func_start sub_807DA14
sub_807DA14:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	ldr r0, [r6, 0x70]
	mov r10, r0
	adds r0, r6, 0
	movs r1, 0xE
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807DA50
	ldr r0, _0807DA48
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807DA4C
	b _0807DA5C
	.align 2, 0
_0807DA48: .4byte gAvailablePokemonNames
_0807DA4C: .4byte gUnknown_80FCB98
_0807DA50:
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	beq _0807DA6C
	ldr r0, _0807DA68
_0807DA5C:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	b _0807DB5E
	.align 2, 0
_0807DA68: .4byte gUnknown_80FC9C0
_0807DA6C:
	cmp r4, 0x8
	bne _0807DA76
	mov r0, r10
	adds r0, 0x46
	ldrb r4, [r0]
_0807DA76:
	adds r0, r6, 0
	movs r1, 0x6
	adds r2, r4, 0
	bl sub_806CDD4
	lsls r1, r4, 2
	adds r2, r6, 0x4
	mov r9, r2
	ldr r0, _0807DAFC
	adds r1, r0
	mov r8, r1
_0807DA8C:
	ldrh r0, [r6, 0x4]
	mov r3, r8
	ldrh r3, [r3]
	adds r0, r3
	lsls r0, 16
	ldrh r1, [r6, 0x6]
	mov r2, r8
	ldrh r2, [r2, 0x2]
	adds r1, r2
	lsls r1, 16
	lsrs r7, r0, 16
	orrs r7, r1
	lsls r0, r7, 16
	asrs r5, r0, 16
	cmp r5, 0
	ble _0807DB00
	asrs r4, r7, 16
	cmp r4, 0
	ble _0807DB00
	cmp r5, 0x36
	bgt _0807DB00
	cmp r4, 0x1E
	bgt _0807DB00
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTileAtPosition
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	cmp r0, 0
	bne _0807DB00
	ldrh r1, [r1]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0807DB00
	adds r0, r6, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_80694C0
	adds r0, r6, 0
	movs r1, 0
	bl sub_804535C
	adds r0, r6, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807DA8C
	movs r0, 0x3A
	bl sub_803E46C
	b _0807DA8C
	.align 2, 0
_0807DAFC: .4byte gAdjacentTileOffsets
_0807DB00:
	adds r0, r6, 0
	bl sub_806A5B8
	mov r1, r9
	adds r0, r6, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _0807DB20
	adds r0, r6, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_0807DB20:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807DB5E
	adds r0, r6, 0
	movs r1, 0x8
	bl sub_806CE68
	mov r3, r10
	ldrb r0, [r3, 0x7]
	cmp r0, 0
	beq _0807DB48
	mov r0, r9
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807DB48:
	adds r0, r6, 0
	bl sub_806A5B8
	ldr r0, _0807DB6C
	ldr r0, [r0]
	ldr r1, _0807DB70
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8075900
_0807DB5E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807DB6C: .4byte gDungeonGlobalData
_0807DB70: .4byte 0x00003a08
	thumb_func_end sub_807DA14

	thumb_func_start sub_807DB74
sub_807DB74:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	beq _0807DB94
	ldr r0, _0807DB90
	b _0807DBA0
	.align 2, 0
_0807DB90: .4byte gUnknown_80FD060
_0807DB94:
	bl IsWaterTileset
	lsls r0, 24
	cmp r0, 0
	beq _0807DBB0
	ldr r0, _0807DBAC
_0807DBA0:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _0807DC54
	.align 2, 0
_0807DBAC: .4byte gUnknown_80FD08C
_0807DBB0:
	movs r5, 0
	ldr r0, _0807DC24
	adds r6, r0, 0
_0807DBB6:
	movs r4, 0
_0807DBB8:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapEntity
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0807DBE2
	adds r0, r1, 0
	ands r0, r6
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80498A8
	movs r1, 0x1
	mov r8, r1
_0807DBE2:
	adds r4, 0x1
	cmp r4, 0x37
	ble _0807DBB8
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0807DBB6
	movs r5, 0
_0807DBF0:
	movs r4, 0
	adds r6, r5, 0x1
_0807DBF4:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8049BB0
	adds r4, 0x1
	cmp r4, 0x37
	ble _0807DBF4
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _0807DBF0
	mov r0, r8
	cmp r0, 0
	beq _0807DC30
	ldr r1, _0807DC28
	adds r0, r7, 0
	bl sub_80421C0
	ldr r0, _0807DC2C
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _0807DC3A
	.align 2, 0
_0807DC24: .4byte 0x0000fffc
_0807DC28: .4byte 0x000001a1
_0807DC2C: .4byte gUnknown_80FD05C
_0807DC30:
	ldr r0, _0807DC60
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_0807DC3A:
	ldr r0, _0807DC64
	ldr r0, [r0]
	movs r1, 0xCE
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bl sub_806CF60
	bl sub_8040A84
	bl sub_8049ED4
_0807DC54:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807DC60: .4byte gUnknown_80FD060
_0807DC64: .4byte gDungeonGlobalData
	thumb_func_end sub_807DB74

	thumb_func_start sub_807DC68
sub_807DC68:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	ldr r0, _0807DC88
	ldr r1, [r0]
	ldr r2, _0807DC8C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807DC94
	ldr r0, _0807DC90
	b _0807DCB8
	.align 2, 0
_0807DC88: .4byte gDungeonGlobalData
_0807DC8C: .4byte 0x00003a08
_0807DC90: .4byte gUnknown_80FD3C8
_0807DC94:
	ldr r3, _0807DCA4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807DCAC
	ldr r0, _0807DCA8
	b _0807DCB8
	.align 2, 0
_0807DCA4: .4byte 0x00003a0b
_0807DCA8: .4byte gUnknown_80FD3CC
_0807DCAC:
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _0807DCC8
	ldr r0, _0807DCC4
_0807DCB8:
	ldr r1, [r0]
	mov r0, r9
	bl SendMessage
	b _0807DF0E
	.align 2, 0
_0807DCC4: .4byte gUnknown_80FD3D0
_0807DCC8:
	movs r0, 0
	mov r8, r0
	movs r5, 0x1
	movs r1, 0
	mov r10, r1
	ldr r2, _0807DD68
	adds r7, r2, 0
_0807DCD6:
	movs r4, 0x1
_0807DCD8:
	movs r6, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapEntity
	adds r2, r0, 0
	ldrh r1, [r2]
	ldr r3, _0807DD6C
	adds r0, r3, 0
	adds r3, r1, 0
	ands r3, r0
	strh r3, [r2]
	mov r0, r10
	strb r0, [r2, 0x9]
	movs r0, 0x10
	ands r0, r3
	cmp r0, 0
	bne _0807DD94
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0, 0
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0807DD94
	ldrh r0, [r2, 0x4]
	movs r1, 0x3
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldr r1, _0807DD70
	adds r0, r1, 0
	adds r1, r3, 0
	ands r1, r0
	strh r1, [r2]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0807DD28
	movs r3, 0x1
	mov r8, r3
_0807DD28:
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _0807DD94
	cmp r0, 0x3
	beq _0807DD94
	cmp r5, 0x1
	beq _0807DD44
	cmp r4, 0x1
	beq _0807DD44
	cmp r5, 0x36
	beq _0807DD44
	cmp r4, 0x1E
	bne _0807DD5C
_0807DD44:
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _0807DD5C
	ldr r0, _0807DD74
	ldr r0, [r0]
	movs r1, 0xCE
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807DD5C
	movs r6, 0x1
_0807DD5C:
	cmp r6, 0
	beq _0807DD78
	ldrh r0, [r2]
	ands r0, r7
	movs r1, 0x2
	b _0807DD90
	.align 2, 0
_0807DD68: .4byte 0x0000fffc
_0807DD6C: .4byte 0x0000fbff
_0807DD70: .4byte 0x0000fff7
_0807DD74: .4byte gDungeonGlobalData
_0807DD78:
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0807DD94
	adds r0, r1, 0
	ands r0, r7
	movs r1, 0x1
	orrs r0, r1
	movs r3, 0x80
	lsls r3, 3
	adds r1, r3, 0
_0807DD90:
	orrs r0, r1
	strh r0, [r2]
_0807DD94:
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0807DCD8
	adds r5, 0x1
	cmp r5, 0x36
	ble _0807DCD6
	ldr r0, _0807DF1C
	ldr r1, [r0]
	ldr r2, _0807DF20
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r2, 0x2
	adds r1, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	movs r2, 0x1
	bl sub_8050C30
	lsls r0, 24
	cmp r0, 0
	beq _0807DE02
	movs r5, 0
	movs r6, 0x84
	lsls r6, 8
	movs r7, 0
_0807DDC8:
	movs r4, 0
_0807DDCA:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapEntity
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0807DDF6
	adds r0, r6, 0
	ands r0, r1
	cmp r0, r6
	bne _0807DDF6
	ldr r3, _0807DF24
	adds r0, r3, 0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r2]
_0807DDF6:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0807DDCA
	adds r5, 0x1
	cmp r5, 0x37
	ble _0807DDC8
_0807DE02:
	mov r0, r8
	cmp r0, 0
	beq _0807DE14
	ldr r0, _0807DF1C
	ldr r0, [r0]
	ldr r1, _0807DF28
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_0807DE14:
	movs r5, 0
_0807DE16:
	movs r4, 0
	adds r6, r5, 0x1
_0807DE1A:
	mov r2, r8
	cmp r2, 0
	beq _0807DE30
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapEntity
	ldrh r2, [r0]
	movs r1, 0x40
	orrs r1, r2
	strh r1, [r0]
_0807DE30:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8049BB0
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0807DE1A
	adds r5, r6, 0
	cmp r5, 0x37
	ble _0807DE16
	movs r5, 0
_0807DE46:
	ldr r0, _0807DF1C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r3, _0807DF2C
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807DE74
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	ldrb r1, [r0, 0x9]
	adds r0, r4, 0
	adds r0, 0x25
	strb r1, [r0]
_0807DE74:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807DE46
	bl sub_804EB30
	bl sub_804AAD4
	bl sub_8049884
	bl sub_806CF60
	bl sub_8040A84
	bl sub_8049ED4
	ldr r0, _0807DF30
	ldr r1, [r0]
	mov r0, r9
	bl SendMessage
	movs r0, 0x28
	movs r1, 0x2B
	bl sub_803E708
	mov r0, r9
	movs r1, 0x1
	bl sub_8075900
	movs r5, 0
_0807DEAE:
	ldr r0, _0807DF1C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r3, _0807DF2C
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807DEF4
	adds r0, r4, 0
	bl sub_806A5B8
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807DEF4
	adds r1, r4, 0x4
	adds r0, r4, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _0807DEF4
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_0807DEF4:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807DEAE
	ldr r0, _0807DF1C
	ldr r0, [r0]
	ldr r1, _0807DF34
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x14
	movs r1, 0x2B
	bl sub_803E708
_0807DF0E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807DF1C: .4byte gDungeonGlobalData
_0807DF20: .4byte 0x0000e21c
_0807DF24: .4byte 0x0000fffc
_0807DF28: .4byte 0x00003a0c
_0807DF2C: .4byte 0x000135cc
_0807DF30: .4byte gUnknown_80FD3A0
_0807DF34: .4byte 0x00003a08
	thumb_func_end sub_807DC68

	thumb_func_start sub_807DF38
sub_807DF38:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp, 0x8]
	mov r10, r1
	str r2, [sp, 0xC]
	adds r6, r3, 0
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	lsls r1, 16
	asrs r1, 16
	str r1, [sp, 0x14]
	movs r5, 0
	b _0807DF62
_0807DF60:
	adds r5, 0x1
_0807DF62:
	cmp r5, 0x13
	bgt _0807DF8E
	ldr r0, _0807DFA8
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807DFAC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807DF60
	adds r0, r4, 0
	movs r1, 0x15
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807DF60
_0807DF8E:
	cmp r5, 0x14
	beq _0807DFB4
	ldr r0, [sp, 0x8]
	mov r1, r10
	bl sub_804218C
	ldr r0, _0807DFB0
	mov r1, r10
	movs r2, 0
	bl SetMessageArgument
	b _0807DFC2
	.align 2, 0
_0807DFA8: .4byte gDungeonGlobalData
_0807DFAC: .4byte 0x000135cc
_0807DFB0: .4byte gAvailablePokemonNames
_0807DFB4:
	mov r0, r10
	bl GetWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _0807DFD4
_0807DFC2:
	ldr r0, _0807DFD0
	ldr r2, [r0]
	ldr r0, [sp, 0x8]
	mov r1, r10
	bl sub_80522F4
	b _0807E174
	.align 2, 0
_0807DFD0: .4byte gUnknown_80F96EC
_0807DFD4:
	ldr r0, [sp, 0x8]
	mov r1, r10
	adds r2, r6, 0
	bl sub_804216C
	ldr r0, _0807E184
	mov r1, r10
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807E188
	ldr r2, [r0]
	ldr r0, [sp, 0x8]
	mov r1, r10
	bl sub_80522F4
	movs r5, 0
	ldr r0, _0807E18C
	lsls r1, r6, 2
	adds r0, r1, r0
	ldr r0, [r0]
	mov r9, r0
	ldrh r4, [r0]
	movs r3, 0
	ldrsh r0, [r0, r3]
	str r1, [sp, 0x1C]
	cmp r0, 0x63
	bne _0807E00E
	b _0807E124
_0807E00E:
	mov r0, sp
	adds r0, 0x4
	str r0, [sp, 0x18]
_0807E014:
	ldr r1, [sp, 0xC]
	ldrh r0, [r1]
	adds r0, r4, r0
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807E190
	ldr r1, [sp, 0x4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x4]
	ldr r2, [sp, 0xC]
	ldrh r0, [r2, 0x2]
	mov r3, r9
	ldrh r3, [r3, 0x2]
	adds r0, r3
	lsls r0, 16
	ldr r2, _0807E194
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	ldr r1, [sp, 0x18]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	blt _0807E112
	asrs r1, r2, 16
	cmp r1, 0
	blt _0807E112
	cmp r0, 0x37
	bgt _0807E112
	cmp r1, 0x1F
	bgt _0807E112
	bl GetMapEntity
	mov r8, r0
	ldr r0, [sp, 0x18]
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	ble _0807E0BE
	ldr r0, [sp, 0x4]
	asrs r0, 16
	cmp r0, 0
	ble _0807E0BE
	cmp r1, 0x36
	bgt _0807E0BE
	cmp r0, 0x1E
	bgt _0807E0BE
	mov r3, r8
	ldrh r1, [r3]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0807E0BE
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0807E0BE
	ldr r2, _0807E198
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r3]
	movs r5, 0x1
	negs r5, r5
	add r7, sp, 0x4
_0807E09A:
	movs r4, 0x1
	negs r4, r4
	adds r6, r5, 0x1
_0807E0A0:
	movs r3, 0
	ldrsh r0, [r7, r3]
	adds r0, r4
	ldr r1, [sp, 0x4]
	asrs r1, 16
	adds r1, r5
	bl sub_80498A8
	adds r4, 0x1
	cmp r4, 0x1
	ble _0807E0A0
	adds r5, r6, 0
	cmp r5, 0x1
	ble _0807E09A
	movs r5, 0x1
_0807E0BE:
	mov r0, r8
	ldr r4, [r0, 0x14]
	cmp r4, 0
	beq _0807E0DC
	cmp r4, r10
	beq _0807E0DC
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x3
	bne _0807E0DC
	add r0, sp, 0x4
	movs r1, 0
	bl sub_80461C8
_0807E0DC:
	mov r1, r8
	ldr r4, [r1, 0x10]
	cmp r4, 0
	beq _0807E112
	cmp r4, r10
	beq _0807E112
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0807E112
	ldr r0, _0807E19C
	ldr r2, [sp, 0x1C]
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, [sp, 0x8]
	adds r1, r4, 0
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	bl sub_807E1A0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807E124
_0807E112:
	movs r3, 0x4
	add r9, r3
	mov r0, r9
	ldrh r4, [r0]
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x63
	beq _0807E124
	b _0807E014
_0807E124:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807E174
	mov r0, r10
	bl GetEntityType
	cmp r0, 0x1
	bne _0807E14E
	ldr r0, _0807E19C
	ldr r2, [sp, 0x1C]
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, [sp, 0x8]
	mov r1, r10
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	bl sub_807E1A0
_0807E14E:
	cmp r5, 0
	beq _0807E174
	movs r5, 0
_0807E154:
	movs r4, 0
	adds r6, r5, 0x1
_0807E158:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8049BB0
	adds r4, 0x1
	cmp r4, 0x37
	ble _0807E158
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _0807E154
	bl sub_8040A84
	bl sub_8049ED4
_0807E174:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E184: .4byte gAvailablePokemonNames
_0807E188: .4byte gUnknown_80F96BC
_0807E18C: .4byte gUnknown_8107178
_0807E190: .4byte 0xffff0000
_0807E194: .4byte 0x0000ffff
_0807E198: .4byte 0x0000fffc
_0807E19C: .4byte gUnknown_203B444
	thumb_func_end sub_807DF38

	thumb_func_start sub_807E1A0
sub_807E1A0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x24
	mov r9, r0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 16
	asrs r7, r3, 16
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807E244
	ldr r5, [r6, 0x70]
	add r4, sp, 0x1C
	ldr r1, _0807E20C
	adds r0, r4, 0
	bl InitPokemonMove
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	cmp r0, 0
	bne _0807E244
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _0807E210
	movs r0, 0xE
	ldrsh r4, [r5, r0]
	lsrs r0, r4, 31
	adds r5, r4, r0
	asrs r4, r5, 1
	adds r0, r6, 0
	movs r1, 0x2
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _0807E202
	lsrs r0, r5, 31
	adds r0, r4, r0
	asrs r4, r0, 1
_0807E202:
	cmp r4, 0
	bgt _0807E226
	movs r4, 0x1
	b _0807E226
	.align 2, 0
_0807E20C: .4byte 0x00000163
_0807E210:
	ldr r4, [sp, 0x40]
	adds r0, r6, 0
	movs r1, 0x2
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _0807E226
	lsrs r0, r4, 31
	adds r0, r4, r0
	asrs r4, r0, 1
_0807E226:
	add r0, sp, 0x18
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	mov r0, r9
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_806F370
_0807E244:
	add sp, 0x24
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807E1A0

	thumb_func_start sub_807E254
sub_807E254:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	adds r7, r1, 0
	movs r1, 0xE
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807E274
	ldr r0, _0807E270
	adds r1, r6, 0
	b _0807E286
	.align 2, 0
_0807E270: .4byte gAvailablePokemonNames
_0807E274:
	adds r0, r7, 0
	movs r1, 0xE
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807E2A4
	ldr r0, _0807E29C
	adds r1, r7, 0
_0807E286:
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807E2A0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _0807E366
	.align 2, 0
_0807E29C: .4byte gAvailablePokemonNames
_0807E2A0: .4byte gUnknown_80FCAC0
_0807E2A4:
	ldrh r1, [r6, 0x6]
	lsls r1, 16
	ldrh r0, [r6, 0x4]
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r7, 0x6]
	lsls r1, 16
	ldrh r0, [r7, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r5, sp
	mov r0, sp
	bl nullsub_93
	add r4, sp, 0x4
	adds r0, r4, 0
	bl nullsub_93
	movs r0, 0
	ldrsh r1, [r4, r0]
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	adds r0, r6, 0
	movs r3, 0x1
	bl sub_80694C0
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	adds r0, r7, 0
	movs r3, 0x1
	bl sub_80694C0
	adds r0, r6, 0
	movs r1, 0
	bl sub_804535C
	adds r0, r7, 0
	movs r1, 0
	bl sub_804535C
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807E330
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0807E31A
	adds r0, r6, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807E31A:
	adds r0, r6, 0
	bl sub_806A5B8
	ldr r0, _0807E370
	ldr r0, [r0]
	ldr r1, _0807E374
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8075900
_0807E330:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807E366
	ldr r0, [r7, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0807E350
	adds r0, r7, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807E350:
	adds r0, r7, 0
	bl sub_806A5B8
	ldr r0, _0807E370
	ldr r0, [r0]
	ldr r2, _0807E374
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8075900
_0807E366:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E370: .4byte gDungeonGlobalData
_0807E374: .4byte 0x00003a08
	thumb_func_end sub_807E254

	thumb_func_start sub_807E378
sub_807E378:
	push {r4-r7,lr}
	bl GetLeaderEntity
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807E38C
	b _0807E564
_0807E38C:
	ldr r0, _0807E41C
	ldr r1, [r0]
	ldr r3, _0807E420
	adds r2, r1, r3
	ldrh r3, [r2]
	movs r5, 0
	ldrsh r1, [r2, r5]
	adds r6, r0, 0
	cmp r1, 0
	ble _0807E3AA
	subs r0, r3, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	bgt _0807E3B4
_0807E3AA:
	ldr r0, [r6]
	ldr r1, _0807E424
	adds r0, r1
	movs r1, 0x3
	strb r1, [r0]
_0807E3B4:
	adds r5, r6, 0
	ldr r1, [r5]
	ldr r7, _0807E424
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807E434
	ldr r2, _0807E420
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0xF9
	ble _0807E3D0
	b _0807E564
_0807E3D0:
	bl sub_805E804
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806A2BC
	adds r0, r4, 0
	bl UseAttack
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807E3EE
	b _0807E564
_0807E3EE:
	ldr r0, _0807E428
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	ldr r1, _0807E42C
	ldr r0, [r5]
	ldr r2, _0807E430
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl sub_80426C8
	ldr r0, [r5]
	adds r0, r7
	movs r1, 0x1
	strb r1, [r0]
	b _0807E564
	.align 2, 0
_0807E41C: .4byte gDungeonGlobalData
_0807E420: .4byte 0x00000666
_0807E424: .4byte 0x0000067a
_0807E428: .4byte gUnknown_80F9C4C
_0807E42C: .4byte gUnknown_80F5FAC
_0807E430: .4byte 0x00003a0e
_0807E434:
	cmp r0, 0x1
	bne _0807E4A0
	ldr r2, _0807E490
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0x95
	ble _0807E446
	b _0807E564
_0807E446:
	bl sub_805E804
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806A2BC
	adds r0, r4, 0
	bl UseAttack
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807E464
	b _0807E564
_0807E464:
	ldr r0, _0807E494
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	ldr r1, _0807E498
	ldr r0, [r5]
	ldr r2, _0807E49C
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80426C8
	ldr r0, [r5]
	adds r0, r7
	movs r1, 0x2
	strb r1, [r0]
	b _0807E564
	.align 2, 0
_0807E490: .4byte 0x00000666
_0807E494: .4byte gUnknown_80F9C70
_0807E498: .4byte gUnknown_80F5FAC
_0807E49C: .4byte 0x00003a0e
_0807E4A0:
	cmp r0, 0x2
	bne _0807E508
	ldr r2, _0807E4F8
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0x31
	bgt _0807E564
	bl sub_805E804
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806A2BC
	adds r0, r4, 0
	bl UseAttack
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807E564
	ldr r0, _0807E4FC
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	ldr r1, _0807E500
	ldr r0, [r5]
	ldr r2, _0807E504
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	bl sub_80426C8
	ldr r0, [r5]
	adds r0, r7
	movs r1, 0x3
	strb r1, [r0]
	b _0807E564
	.align 2, 0
_0807E4F8: .4byte 0x00000666
_0807E4FC: .4byte gUnknown_80F9C8C
_0807E500: .4byte gUnknown_80F5FAC
_0807E504: .4byte 0x00003a0e
_0807E508:
	ldr r5, _0807E56C
	adds r0, r1, r5
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bgt _0807E564
	bl sub_805E804
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806A2BC
	adds r0, r4, 0
	bl UseAttack
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807E564
	ldr r0, _0807E570
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	ldr r1, _0807E574
	ldr r0, [r6]
	ldr r2, _0807E578
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x3
	bl sub_80426C8
	ldr r0, [r6]
	adds r0, r7
	movs r1, 0x4
	strb r1, [r0]
	ldr r1, _0807E57C
	adds r0, r4, 0
	adds r2, r4, 0
	bl sub_8068FE0
_0807E564:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E56C: .4byte 0x00000666
_0807E570: .4byte gUnknown_80F9CBC
_0807E574: .4byte gUnknown_80F5FAC
_0807E578: .4byte 0x00003a0e
_0807E57C: .4byte 0x0000021e
	thumb_func_end sub_807E378

	thumb_func_start GetWeather
GetWeather:
	push {lr}
	cmp r0, 0
	beq _0807E596
	movs r1, 0x2D
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0807E596
	movs r0, 0
	b _0807E5A0
_0807E596:
	ldr r0, _0807E5A4
	ldr r0, [r0]
	ldr r1, _0807E5A8
	adds r0, r1
	ldrb r0, [r0]
_0807E5A0:
	pop {r1}
	bx r1
	.align 2, 0
_0807E5A4: .4byte gDungeonGlobalData
_0807E5A8: .4byte 0x0000e264
	thumb_func_end GetWeather

	thumb_func_start sub_807E5AC
sub_807E5AC:
	push {lr}
	ldr r0, _0807E5DC
	ldr r0, [r0]
	ldr r1, _0807E5E0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0807E5C6
	movs r0, 0x8
	bl DungeonRandomCapped
	lsls r0, 24
	lsrs r0, 24
_0807E5C6:
	bl sub_807E5E4
	bl TriggerWeatherAbilities
	movs r0, 0
	movs r1, 0x1
	bl sub_807EAA0
	pop {r0}
	bx r0
	.align 2, 0
_0807E5DC: .4byte gDungeonGlobalData
_0807E5E0: .4byte 0x0001c578
	thumb_func_end sub_807E5AC

	thumb_func_start sub_807E5E4
sub_807E5E4:
	push {r4-r6,lr}
	ldr r3, _0807E674
	ldr r1, [r3]
	ldr r2, _0807E678
	adds r1, r2
	movs r4, 0
	strb r0, [r1]
	ldr r0, [r3]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _0807E67C
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r3]
	ldr r1, _0807E680
	adds r0, r1
	strb r4, [r0]
	movs r2, 0
	adds r4, r3, 0
	ldr r6, _0807E684
	movs r1, 0
	ldr r5, _0807E688
_0807E610:
	ldr r0, [r4]
	adds r0, r6
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r5
	adds r0, r2
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _0807E610
	ldr r0, [r3]
	ldr r2, _0807E68C
	adds r0, r2
	movs r2, 0
	movs r1, 0x9
	strb r1, [r0]
	ldr r0, [r3]
	ldr r1, _0807E690
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, 0x1
	adds r0, r1
	strb r2, [r0]
	movs r6, 0xBE
	lsls r6, 1
	ldr r5, _0807E694
	movs r4, 0xBF
	lsls r4, 1
_0807E64C:
	ldr r0, [r3]
	lsls r1, r2, 2
	adds r0, r1
	adds r0, r6
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, r1
	adds r0, r5
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, r1
	adds r0, r4
	strb r2, [r0]
	adds r2, 0x1
	cmp r2, 0xFF
	ble _0807E64C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807E674: .4byte gDungeonGlobalData
_0807E678: .4byte 0x0000e265
_0807E67C: .4byte 0x0000e264
_0807E680: .4byte 0x0000e279
_0807E684: .4byte 0x0000e267
_0807E688: .4byte 0x0000e26f
_0807E68C: .4byte 0x0000e266
_0807E690: .4byte 0x0000e277
_0807E694: .4byte 0x0000017d
	thumb_func_end sub_807E5E4

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
	bl GetWeather
	lsls r0, 24
	lsrs r0, 16
	str r0, [sp, 0x4]
	ldr r0, _0807E724
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r10, r0
	movs r0, 0
	bl GetWeather
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
_0807E72C: .4byte gDungeonGlobalData
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
	bl GetLeaderEntity
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
	bl GetWeather
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
_0807E874: .4byte gDungeonGlobalData
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
	bl GetWeather
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
_0807E8E8: .4byte gDungeonGlobalData
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
	bl GetMovementSpeed
	adds r0, r5, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807E958
	adds r0, r5, 0
	bl GetWeather
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

	thumb_func_start sub_807EA30
sub_807EA30:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0807EA6C
	ldr r1, _0807EA5C
	movs r0, 0
	movs r2, 0
	bl sub_808417C
	ldr r1, _0807EA60
	ldr r1, [r1]
	ldr r2, _0807EA64
	adds r1, r2
	strb r0, [r1]
	bl GetLeaderEntity
	ldr r1, _0807EA68
	ldr r1, [r1]
	bl SendMessage
	b _0807EA8C
	.align 2, 0
_0807EA5C: .4byte gUnknown_80F4EAC
_0807EA60: .4byte gDungeonGlobalData
_0807EA64: .4byte 0x0000e277
_0807EA68: .4byte gUnknown_80FAD8C
_0807EA6C:
	ldr r1, _0807EA90
	movs r0, 0
	movs r2, 0
	bl sub_808417C
	ldr r1, _0807EA94
	ldr r1, [r1]
	ldr r2, _0807EA98
	adds r1, r2
	strb r0, [r1]
	bl GetLeaderEntity
	ldr r1, _0807EA9C
	ldr r1, [r1]
	bl SendMessage
_0807EA8C:
	pop {r0}
	bx r0
	.align 2, 0
_0807EA90: .4byte gUnknown_80F4EAC
_0807EA94: .4byte gDungeonGlobalData
_0807EA98: .4byte 0x0000e278
_0807EA9C: .4byte gUnknown_80FADB0
	thumb_func_end sub_807EA30

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
	bl GetWeather
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
_0807EAF0: .4byte gDungeonGlobalData
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
_0807EB3C: .4byte gDungeonGlobalData
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
	bl GetWeather
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
_0807EB98: .4byte gDungeonGlobalData
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
	bl GetLeaderEntity
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
	bl GetLeaderEntity
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
_0807EC14: .4byte gDungeonGlobalData
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
	bl GetLeaderEntity
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
	bl GetMapEntityForDungeonEntity
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
_0807ECB4: .4byte gDungeonGlobalData
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
	bl GetEntityRoomIndex
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetEntityRoomIndex
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
_0807ED48: .4byte gDungeonGlobalData
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
	bl GetEntityRoomIndex
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetEntityRoomIndex
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
	bl GetMapTileAtPosition
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
	bl CalculateFacingDir
	adds r1, r0, 0
	adds r0, r7, 0
	bl sub_806CE34
	b _0807EEB2
	.align 2, 0
_0807EE90: .4byte gDungeonGlobalData
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
	bl CalculateFacingDir
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
_0807EEF8: .4byte gDungeonGlobalData
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
_0807EF70: .4byte gDungeonGlobalData
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
	bl GetLeaderEntity
	bl GetMapEntityForDungeonEntity
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
	bl GetMapTileAtPosition
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
_0807F168: .4byte gDungeonGlobalData
_0807F16C: .4byte 0xffff0000
_0807F170: .4byte 0xff00ffff
_0807F174: .4byte gUnknown_202DE30
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
_0807F1F4: .4byte gDungeonGlobalData
_0807F1F8: .4byte 0x00000694
_0807F1FC: .4byte gUnknown_202DE30
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
_0807F224: .4byte gTeamInventory_203B460
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
	bl GetMapTileAtPosition
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
_0807F324: .4byte gTeamInventory_203B460
_0807F328: .4byte gDungeonGlobalData
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
	bl GetLeaderEntity
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
	bl GetMapTileAtPosition
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
	bl GetMovementSpeed
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
_0807F41C: .4byte gDungeonGlobalData
_0807F420: .4byte 0x0000066e
_0807F424: .4byte 0x0000066f
_0807F428: .4byte gUnknown_80FE4B8
_0807F42C: .4byte gTeamInventory_203B460
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
	bl CanSee
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
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0807F500
	b _0807F602
_0807F500:
	b _0807F51E
	.align 2, 0
_0807F504: .4byte gDungeonGlobalData
_0807F508: .4byte 0x000135cc
_0807F50C:
	ldr r0, [sp, 0xEC]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
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
	bl DungeonRandomCapped
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
	bl sub_808411C
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0807F6A0
	ldr r1, [r5]
	ands r1, r2
	orrs r1, r0
	str r1, [r6]
	ldr r0, [r4, 0x4]
	ldr r1, [r4, 0xC]
	bl sub_808411C
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
	bl CalculateFacingDir
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
	bl sub_8009C7C
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
	bl GetMapTileAtPosition
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
_0807FA10: .4byte gDungeonGlobalData
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
	bl GetMapEntity
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
_0807FAC4: .4byte gDungeonGlobalData
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
	bl GetMapTileAtPosition
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
_0807FC24: .4byte gDungeonGlobalData
_0807FC28: .4byte 0x000181f0
_0807FC2C: .4byte 0x000181f2
_0807FC30: .4byte 0x00000fff
_0807FC34: .4byte 0x000001ff
_0807FC38: .4byte 0x000181ea
	thumb_func_end sub_807FA9C

	thumb_func_start sub_807FC3C
sub_807FC3C:
	push {r4-r7,lr}
	ldr r6, _0807FC70
	ldr r4, [r6]
	ldrh r5, [r0]
	ldr r7, _0807FC74
	adds r3, r4, r7
	strh r5, [r3]
	ldrh r3, [r0, 0x2]
	ldr r5, _0807FC78
	adds r0, r4, r5
	strh r3, [r0]
	adds r7, 0x4
	adds r4, r7
	strb r1, [r4]
	ldr r0, [r6]
	ldr r1, _0807FC7C
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	subs r5, 0x6
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FC70: .4byte gDungeonGlobalData
_0807FC74: .4byte 0x00013574
_0807FC78: .4byte 0x00013576
_0807FC7C: .4byte 0x00013579
	thumb_func_end sub_807FC3C

	thumb_func_start CanLayTrap
CanLayTrap:
	push {lr}
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	adds r0, r2, 0
	bl GetMapEntity
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _0807FCCA
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0807FCCA
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0807FCCA
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0807FCCA
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0807FCCA
	ldr r0, [r2, 0x14]
	cmp r0, 0
	beq _0807FCCE
	bl GetEntityType
	cmp r0, 0x2
	beq _0807FCCE
_0807FCCA:
	movs r0, 0
	b _0807FCD0
_0807FCCE:
	movs r0, 0x1
_0807FCD0:
	pop {r1}
	bx r1
	thumb_func_end CanLayTrap

	thumb_func_start sub_807FCD4
sub_807FCD4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r2, 0x2
	ldrsh r1, [r7, r2]
	bl GetMapEntity
	adds r6, r0, 0
	cmp r5, 0x13
	bls _0807FD12
	movs r4, 0
	b _0807FCFE
_0807FCFC:
	adds r4, 0x1
_0807FCFE:
	cmp r4, 0x1D
	bgt _0807FD0C
	bl sub_803D6FC
	adds r5, r0, 0
	cmp r5, 0x11
	beq _0807FCFC
_0807FD0C:
	cmp r4, 0x1E
	bne _0807FD12
	movs r5, 0x10
_0807FD12:
	ldrh r1, [r6]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _0807FD6E
	ldrb r0, [r6, 0x9]
	cmp r0, 0xFF
	beq _0807FD6E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0807FD6E
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0807FD6E
	movs r4, 0x3
	ands r4, r1
	cmp r4, 0x1
	bne _0807FD6E
	ldr r0, [r6, 0x14]
	cmp r0, 0
	beq _0807FD60
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FD6E
	ldr r0, [r6, 0x14]
	bl GetTrapData
	strb r5, [r0]
	ldr r0, [r6, 0x14]
	bl GetTrapData
	mov r1, r8
	strb r1, [r0, 0x1]
	ldr r0, [r6, 0x14]
	b _0807FD74
_0807FD60:
	adds r0, r5, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8045684
	cmp r0, 0
	bne _0807FD72
_0807FD6E:
	movs r0, 0
	b _0807FD7A
_0807FD72:
	str r0, [r6, 0x14]
_0807FD74:
	adds r0, 0x20
	strb r4, [r0]
	movs r0, 0x1
_0807FD7A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807FCD4

	thumb_func_start sub_807FD84
sub_807FD84:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, _0807FD9C
	ldr r0, [r4]
	ldr r2, _0807FDA0
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _0807FDA4
	movs r0, 0
	b _0807FDF6
	.align 2, 0
_0807FD9C: .4byte gDungeonGlobalData
_0807FDA0: .4byte 0x00013570
_0807FDA4:
	strb r5, [r1]
	ldr r2, [r4]
	ldr r3, _0807FDD8
	adds r0, r2, r3
	adds r3, 0x4
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r3, 0x1
	adds r2, r3
	ldrb r2, [r2]
	bl sub_807FCD4
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0807FDE0
	ldr r1, [r4]
	ldr r0, _0807FDD8
	adds r1, r0
	ldr r0, _0807FDDC
	ldr r2, [r0]
	adds r0, r6, 0
	bl sub_8052364
	b _0807FDF0
	.align 2, 0
_0807FDD8: .4byte 0x00013574
_0807FDDC: .4byte gUnknown_80FC5F8
_0807FDE0:
	ldr r1, [r4]
	ldr r2, _0807FDFC
	adds r1, r2
	ldr r0, _0807FE00
	ldr r2, [r0]
	adds r0, r6, 0
	bl sub_8052364
_0807FDF0:
	bl sub_8049ED4
	adds r0, r5, 0
_0807FDF6:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807FDFC: .4byte 0x00013574
_0807FE00: .4byte gUnknown_80FC5FC
	thumb_func_end sub_807FD84

	thumb_func_start sub_807FE04
sub_807FE04:
	push {r4,r5,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl GetMapEntity
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FE3C
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FE3C
	ldr r1, [r4, 0x14]
	movs r0, 0
	str r0, [r1]
	str r0, [r4, 0x14]
	cmp r5, 0
	beq _0807FE38
	bl sub_8049ED4
_0807FE38:
	movs r0, 0x1
	b _0807FE3E
_0807FE3C:
	movs r0, 0
_0807FE3E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_807FE04

	thumb_func_start sub_807FE44
sub_807FE44:
	push {r4,r5,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl GetMapTileAtPosition
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FE7C
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FE7C
	ldr r0, [r4, 0x14]
	adds r0, 0x20
	movs r1, 0x1
	strb r1, [r0]
	cmp r5, 0
	beq _0807FE78
	bl sub_8049ED4
_0807FE78:
	movs r0, 0x1
	b _0807FE7E
_0807FE7C:
	movs r0, 0
_0807FE7E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_807FE44

	thumb_func_start GetTrapName
GetTrapName:
	push {lr}
	lsls r1, 24
	ldr r2, _0807FE98
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	bl strcpy
	pop {r0}
	bx r0
	.align 2, 0
_0807FE98: .4byte gTrapNames
	thumb_func_end GetTrapName

	thumb_func_start sub_807FE9C
sub_807FE9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r5, r0, 0
	mov r9, r1
	str r2, [sp]
	lsls r3, 24
	lsrs r6, r3, 24
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl GetMapEntity
	str r0, [sp, 0x4]
	ldr r0, [r0, 0x14]
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x8]
	cmp r0, 0
	bne _0807FECE
	b _080801B4
_0807FECE:
	bl GetEntityType
	cmp r0, 0x2
	beq _0807FED8
	b _080801B4
_0807FED8:
	mov r0, r10
	bl GetTrapData
	mov r8, r0
	ldr r0, _0807FF58
	mov r2, r8
	ldrb r1, [r2]
	bl GetTrapName
	ldr r3, [sp, 0x4]
	ldr r4, [r3, 0x10]
	cmp r4, 0
	beq _0807FEFE
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	beq _0807FEFE
	movs r4, 0
_0807FEFE:
	mov r1, r10
	adds r1, 0x20
	ldrb r0, [r1]
	str r0, [sp, 0xC]
	movs r0, 0x1
	strb r0, [r1]
	cmp r4, 0
	beq _0807FF96
	adds r0, r4, 0
	bl sub_806A1E8
	cmp r6, 0
	beq _0807FF96
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x11
	beq _0807FF96
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r7, r0, 0
	movs r6, 0
	adds r0, r4, 0
	movs r1, 0x1C
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0807FF3C
	ldr r0, _0807FF5C
	ldr r6, [r0]
_0807FF3C:
	ldr r2, [sp, 0xC]
	cmp r2, 0x1
	beq _0807FF50
	ldr r0, _0807FF60
	ldr r0, [r0]
	ldr r3, _0807FF64
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807FF68
_0807FF50:
	cmp r7, 0
	bge _0807FF70
	b _0807FF6C
	.align 2, 0
_0807FF58: .4byte gAvailablePokemonNames
_0807FF5C: .4byte gUnknown_80FDB5C
_0807FF60: .4byte gDungeonGlobalData
_0807FF64: .4byte 0x0001820f
_0807FF68:
	cmp r7, 0xE
	bgt _0807FF70
_0807FF6C:
	ldr r0, _0807FFD8
	ldr r6, [r0]
_0807FF70:
	cmp r6, 0
	beq _0807FF96
	mov r0, r9
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0807FF84
	bl sub_8049ED4
_0807FF84:
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_80522F4
	ldr r0, [sp]
	cmp r0, 0
	bne _0807FF96
	b _080801B4
_0807FF96:
	mov r0, r9
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0807FFFA
	movs r1, 0xAE
	lsls r1, 1
	movs r0, 0
	bl sub_80421C0
	bl sub_8049ED4
	mov r1, r8
	ldrb r2, [r1]
	adds r0, r5, 0
	mov r1, r9
	bl sub_804225C
	ldr r0, _0807FFDC
	ldr r0, [r0]
	ldr r2, _0807FFE0
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807FFE8
	ldr r0, _0807FFE4
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807FFFA
	.align 2, 0
_0807FFD8: .4byte gUnknown_80FDB7C
_0807FFDC: .4byte gDungeonGlobalData
_0807FFE0: .4byte 0x0001820a
_0807FFE4: .4byte gUnknown_80FD7F4
_0807FFE8:
	ldr r0, _08080010
	mov r3, r8
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl SendMessage
_0807FFFA:
	cmp r4, 0
	beq _08080020
	mov r1, r8
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	bne _08080014
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806F480
	b _08080020
	.align 2, 0
_08080010: .4byte gUnknown_80FD7F8
_08080014:
	cmp r0, 0x1
	bne _08080020
	adds r0, r4, 0
	movs r1, 0
	bl sub_806F480
_08080020:
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0x1B
	bls _0808002A
	b _08080194
_0808002A:
	lsls r0, 2
	ldr r1, _08080034
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08080034: .4byte _08080038
	.align 2, 0
_08080038:
	.4byte _080800A8
	.4byte _080800B2
	.4byte _080800BC
	.4byte _080800C6
	.4byte _080800D0
	.4byte _080800DA
	.4byte _080800E6
	.4byte _080800F0
	.4byte _080800FA
	.4byte _08080104
	.4byte _0808010E
	.4byte _08080118
	.4byte _08080122
	.4byte _0808012C
	.4byte _08080136
	.4byte _08080140
	.4byte _0808014A
	.4byte _08080168
	.4byte _08080172
	.4byte _08080180
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _080800DA
_080800A8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080A5C
	b _08080194
_080800B2:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80801CC
	b _08080194
_080800BC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808024C
	b _08080194
_080800C6:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080418
	b _08080194
_080800D0:
	adds r0, r5, 0
	mov r1, r9
	bl sub_8080620
	b _0808017A
_080800DA:
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x4]
	bl sub_8080504
	b _08080194
_080800E6:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080374
	b _08080194
_080800F0:
	mov r0, r10
	adds r1, r4, 0
	bl sub_8080884
	b _08080194
_080800FA:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080364
	b _08080194
_08080104:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080388
	b _08080194
_0808010E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803B4
	b _08080194
_08080118:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80807C0
	b _08080194
_08080122:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803C8
	b _08080194
_0808012C:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803D8
	b _08080194
_08080136:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803F8
	b _08080194
_08080140:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080700
	b _08080194
_0808014A:
	cmp r4, 0
	beq _08080194
	ldr r0, _08080160
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _08080164
	adds r0, r4, 0
	movs r2, 0xF
	bl sub_806F324
	b _08080194
	.align 2, 0
_08080160: .4byte gUnknown_80F4F86
_08080164: .4byte 0x00000213
_08080168:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80807B4
	b _08080194
_08080172:
	adds r0, r5, 0
	mov r1, r9
	bl sub_80808A4
_0808017A:
	movs r3, 0x1
	str r3, [sp, 0x8]
	b _08080194
_08080180:
	cmp r4, 0
	beq _08080194
	ldr r0, _080801C4
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _080801C8
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_806F324
_08080194:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080801A6
	adds r0, r4, 0
	bl sub_8071DA4
_080801A6:
	ldr r3, [sp, 0x8]
	cmp r3, 0
	beq _080801B4
	mov r0, r9
	movs r1, 0x1
	bl sub_807FE04
_080801B4:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080801C4: .4byte gUnknown_80F4F84
_080801C8: .4byte 0x00000206
	thumb_func_end sub_807FE9C

	thumb_func_start sub_80801CC
sub_80801CC:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _08080240
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r1, r0, 0
	cmp r0, 0x18
	bgt _080801EC
	ldr r0, _080801E8
	b _080801F2
	.align 2, 0
_080801E8: .4byte gUnknown_8106A4C
_080801EC:
	cmp r0, 0x31
	bgt _0808020C
	ldr r0, _08080208
_080801F2:
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8076E20
	b _08080240
	.align 2, 0
_08080208: .4byte gUnknown_8106A50
_0808020C:
	cmp r1, 0x4A
	bgt _0808022C
	ldr r0, _08080228
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8076F80
	b _08080240
	.align 2, 0
_08080228: .4byte gUnknown_8106A4C
_0808022C:
	ldr r0, _08080248
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8076F80
_08080240:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08080248: .4byte gUnknown_8106A50
	thumb_func_end sub_80801CC

	thumb_func_start sub_808024C
sub_808024C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x5C
	str r0, [sp, 0x54]
	mov r10, r1
	ldr r0, [r1, 0x70]
	mov r8, r0
	mov r0, r10
	movs r1, 0xE
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08080278
	ldr r0, _08080274
	b _08080300
	.align 2, 0
_08080274: .4byte gUnknown_80FDC7C
_08080278:
	movs r6, 0
	mov r1, r8
	ldrb r0, [r1, 0x7]
	movs r1, 0x60
	add r1, r8
	mov r9, r1
	cmp r0, 0
	beq _080802C8
	movs r5, 0
	ldr r7, _0808030C
	mov r0, sp
	str r0, [sp, 0x58]
_08080290:
	lsls r4, r5, 2
	ldr r0, [r7]
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080802C2
	ldrb r0, [r2, 0x2]
	bl IsNotSpecialItem
	lsls r0, 24
	cmp r0, 0
	beq _080802C2
	ldr r0, [r7]
	adds r2, r0, r4
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080802C2
	ldr r1, [sp, 0x58]
	stm r1!, {r2}
	str r1, [sp, 0x58]
	adds r6, 0x1
_080802C2:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08080290
_080802C8:
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080802FA
	mov r0, r8
	adds r0, 0x62
	ldrb r0, [r0]
	bl IsNotSpecialItem
	lsls r0, 24
	cmp r0, 0
	beq _080802FA
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080802FA
	lsls r0, r6, 2
	add r0, sp
	mov r1, r9
	str r1, [r0]
	adds r6, 0x1
_080802FA:
	cmp r6, 0
	bne _08080314
	ldr r0, _08080310
_08080300:
	ldr r2, [r0]
	ldr r0, [sp, 0x54]
	mov r1, r10
	bl sub_80522F4
	b _0808034A
	.align 2, 0
_0808030C: .4byte gTeamInventory_203B460
_08080310: .4byte gUnknown_80FDC40
_08080314:
	adds r0, r6, 0
	bl DungeonRandomCapped
	ldr r2, _0808035C
	lsls r0, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r1, [r4]
	adds r0, r2, 0
	bl sub_8045BF8
	ldr r2, [r4]
	ldrb r1, [r2]
	movs r0, 0x8
	orrs r0, r1
	strb r0, [r2]
	movs r1, 0xC9
	lsls r1, 1
	mov r0, r10
	bl sub_80421C0
	ldr r0, _08080360
	ldr r2, [r0]
	ldr r0, [sp, 0x54]
	mov r1, r10
	bl sub_80522F4
_0808034A:
	add sp, 0x5C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808035C: .4byte gUnknown_202DE58
_08080360: .4byte gUnknown_80FDC18
	thumb_func_end sub_808024C

	thumb_func_start sub_8080364
sub_8080364:
	push {lr}
	cmp r1, 0
	beq _08080370
	movs r2, 0x1
	bl sub_8077AE4
_08080370:
	pop {r0}
	bx r0
	thumb_func_end sub_8080364

	thumb_func_start sub_8080374
sub_8080374:
	push {lr}
	cmp r1, 0
	beq _08080382
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_08080382:
	pop {r0}
	bx r0
	thumb_func_end sub_8080374

	thumb_func_start sub_8080388
sub_8080388:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080803A8
	ldr r1, _080803B0
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8075C58
_080803A8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080803B0: .4byte gUnknown_80F4E74
	thumb_func_end sub_8080388

	thumb_func_start sub_80803B4
sub_80803B4:
	push {lr}
	cmp r1, 0
	beq _080803C2
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80779F0
_080803C2:
	pop {r0}
	bx r0
	thumb_func_end sub_80803B4

	thumb_func_start sub_80803C8
sub_80803C8:
	push {lr}
	cmp r1, 0
	beq _080803D4
	movs r2, 0x1
	bl sub_80763F8
_080803D4:
	pop {r0}
	bx r0
	thumb_func_end sub_80803C8

	thumb_func_start sub_80803D8
sub_80803D8:
	push {lr}
	sub sp, 0x8
	adds r2, r1, 0x4
	movs r3, 0
	str r3, [sp]
	ldr r3, _080803F4
	str r3, [sp, 0x4]
	movs r3, 0x1
	bl sub_807DF38
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_080803F4: .4byte 0x00000212
	thumb_func_end sub_80803D8

	thumb_func_start sub_80803F8
sub_80803F8:
	push {lr}
	sub sp, 0x8
	adds r2, r1, 0x4
	movs r3, 0
	str r3, [sp]
	ldr r3, _08080414
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl sub_807DF38
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_08080414: .4byte 0x00000212
	thumb_func_end sub_80803F8

	thumb_func_start sub_8080418
sub_8080418:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	mov r8, r0
	adds r6, r1, 0
	movs r0, 0
	mov r9, r0
	cmp r6, 0
	beq _080804F0
	ldr r7, [r6, 0x70]
	movs r3, 0
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0808045A
	ldr r0, _080804C0
	movs r1, 0x1
	mov r12, r1
	ldr r2, [r0]
	mov r4, sp
	movs r5, 0x13
_08080444:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _08080452
	stm r4!, {r2}
	adds r3, 0x1
_08080452:
	adds r2, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08080444
_0808045A:
	adds r2, r7, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08080470
	lsls r0, r3, 2
	add r0, sp
	str r2, [r0]
	adds r3, 0x1
_08080470:
	cmp r3, 0
	ble _080804B6
	mov r4, sp
	adds r5, r3, 0
_08080478:
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _080804AE
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x54
	beq _080804AE
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _080804C4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _080804AE
	movs r0, 0x1
	add r9, r0
	ldr r0, [r4]
	movs r1, 0x54
	movs r2, 0x2
	bl sub_8045C28
_080804AE:
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bne _08080478
_080804B6:
	mov r1, r9
	cmp r1, 0x1
	bne _080804CC
	ldr r0, _080804C8
	b _080804D4
	.align 2, 0
_080804C0: .4byte gTeamInventory_203B460
_080804C4: .4byte gUnknown_80F4E0E
_080804C8: .4byte gUnknown_80FD788
_080804CC:
	mov r2, r9
	cmp r2, 0
	bne _080804E4
	ldr r0, _080804E0
_080804D4:
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	b _080804F0
	.align 2, 0
_080804E0: .4byte gUnknown_80FD7D4
_080804E4:
	ldr r0, _08080500
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
_080804F0:
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080500: .4byte gUnknown_80FD7AC
	thumb_func_end sub_8080418

	thumb_func_start sub_8080504
sub_8080504:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r7, r2, 0
	movs r0, 0
	mov r8, r0
	cmp r4, 0
	bne _0808051A
	b _0808060E
_0808051A:
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _08080534
	ldr r0, _08080530
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _0808060E
	.align 2, 0
_08080530: .4byte gUnknown_80FED0C
_08080534:
	ldr r5, [r4, 0x70]
	adds r0, r4, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0808055E
	adds r0, r7, 0
	movs r1, 0x1B
	bl sub_8080B00
	movs r1, 0x1
	mov r8, r1
	ldr r1, _080805A4
	adds r0, r4, 0
	bl sub_80421C0
	movs r0, 0x1E
	movs r1, 0x48
	bl sub_803E708
_0808055E:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _080805C4
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080805B4
	movs r2, 0xAE
	lsls r2, 1
	adds r0, r5, r2
	movs r1, 0x1
	strb r1, [r0]
	adds r2, 0x2
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, 0x28
	movs r1, 0x4B
	bl sub_803E708
	ldr r0, _080805A8
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _080805AC
	adds r0, r4, 0
	movs r2, 0x11
	bl sub_806F324
	ldr r0, _080805B0
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	b _0808060E
	.align 2, 0
_080805A4: .4byte 0x00000193
_080805A8: .4byte gUnknown_80F4F8A
_080805AC: .4byte 0x00000215
_080805B0: .4byte gDungeonGlobalData
_080805B4:
	ldr r0, _080805C0
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _08080600
	.align 2, 0
_080805C0: .4byte gUnknown_80F9728
_080805C4:
	ldr r0, _080805E4
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _080805EC
	ldr r0, _080805E8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080805F6
	.align 2, 0
_080805E4: .4byte gAvailablePokemonNames
_080805E8: .4byte gUnknown_80F970C
_080805EC:
	ldr r0, _08080618
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_805239C
_080805F6:
	ldr r1, _0808061C
	adds r0, r4, 0
	adds r2, r6, 0
	bl sub_8068FE0
_08080600:
	mov r0, r8
	cmp r0, 0
	beq _0808060E
	adds r0, r7, 0
	movs r1, 0x5
	bl sub_8080B00
_0808060E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080618: .4byte gUnknown_80F970C
_0808061C: .4byte 0x00000215
	thumb_func_end sub_8080504

	thumb_func_start sub_8080620
sub_8080620:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x14]
	adds r7, r1, 0
	movs r0, 0x3
	bl DungeonRandomCapped
	adds r6, r0, 0
	adds r4, r6, 0x2
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r5, r0, 0
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	bne _080806CA
	movs r0, 0
	mov r8, r0
	cmp r8, r4
	bge _080806BA
	mov r4, sp
	movs r1, 0
	mov r10, r1
	movs r2, 0
	mov r9, r2
	adds r6, 0x2
_08080660:
	movs r0, 0
	bl sub_803D970
	movs r1, 0x7
	ands r5, r1
	strh r0, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0
	bl sub_806AA0C
	lsls r0, 24
	cmp r0, 0
	beq _080806B2
	mov r2, r9
	strh r2, [r4, 0x8]
	mov r0, r10
	strb r0, [r4, 0x2]
	ldr r0, _080806D8
	lsls r1, r5, 2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r2, [r7]
	adds r0, r2
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x2]
	ldrh r1, [r7, 0x2]
	adds r0, r1
	strh r0, [r4, 0xE]
	mov r2, r9
	str r2, [sp, 0x4]
	mov r0, r10
	strb r0, [r4, 0x10]
	mov r0, sp
	movs r1, 0x1
	bl sub_806B7F8
	cmp r0, 0
	beq _080806B2
	movs r1, 0x1
	add r8, r1
_080806B2:
	adds r5, 0x1
	subs r6, 0x1
	cmp r6, 0
	bne _08080660
_080806BA:
	movs r1, 0xCA
	lsls r1, 1
	adds r0, r7, 0
	bl sub_80421EC
	mov r2, r8
	cmp r2, 0
	bne _080806E0
_080806CA:
	ldr r0, _080806DC
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
	b _080806EA
	.align 2, 0
_080806D8: .4byte gAdjacentTileOffsets
_080806DC: .4byte gUnknown_80FED04
_080806E0:
	ldr r0, _080806FC
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
_080806EA:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080806FC: .4byte gUnknown_80FED00
	thumb_func_end sub_8080620

	thumb_func_start sub_8080700
sub_8080700:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	mov r8, r0
	adds r5, r1, 0
	movs r0, 0
	mov r12, r0
	cmp r5, 0
	beq _080807A4
	ldr r7, [r5, 0x70]
	movs r4, 0
	movs r3, 0
	mov r6, sp
_0808071C:
	lsls r0, r3, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r2, r7, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08080742
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	beq _08080742
	lsls r1, r4, 2
	stm r6!, {r2}
	add r0, sp, 0x10
	adds r0, r1
	str r3, [r0]
	adds r4, 0x1
_08080742:
	adds r3, 0x1
	cmp r3, 0x3
	ble _0808071C
	cmp r4, 0
	beq _0808077A
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	lsls r4, 2
	mov r0, sp
	adds r2, r0, r4
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x4]
	ldr r0, _08080790
	ldr r1, [r2]
	movs r2, 0
	bl sub_80928C0
	add r0, sp, 0x10
	adds r0, r4
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_806A9B4
	movs r1, 0x1
	mov r12, r1
_0808077A:
	mov r0, r12
	cmp r0, 0
	beq _08080798
	ldr r0, _08080794
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	b _080807A4
	.align 2, 0
_08080790: .4byte gUnknown_202DE58
_08080794: .4byte gUnknown_80FDA80
_08080798:
	ldr r0, _080807B0
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
_080807A4:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080807B0: .4byte gUnknown_80FDAA0
	thumb_func_end sub_8080700

	thumb_func_start sub_80807B4
sub_80807B4:
	push {lr}
	movs r2, 0
	bl sub_8079E34
	pop {r0}
	bx r0
	thumb_func_end sub_80807B4

	thumb_func_start sub_80807C0
sub_80807C0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	adds r7, r1, 0
	movs r0, 0
	mov r9, r0
	cmp r7, 0
	beq _08080870
	mov r0, r8
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08080870
	ldr r0, [r7, 0x70]
	movs r5, 0
	movs r6, 0x1
	movs r1, 0x8C
	lsls r1, 1
	adds r2, r0, r1
	adds r3, r2, 0
	mov r12, sp
	movs r4, 0x3
_080807F6:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08080816
	ldrb r1, [r2, 0x1]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08080816
	mov r0, r12
	adds r0, 0x4
	mov r12, r0
	subs r0, 0x4
	stm r0!, {r3}
	adds r5, 0x1
_08080816:
	adds r2, 0x8
	adds r3, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _080807F6
	cmp r5, 0
	beq _08080848
	adds r0, r5, 0
	bl DungeonRandomCapped
	lsls r0, 2
	mov r1, sp
	adds r3, r1, r0
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r0, _0808085C
	ldr r1, [r3]
	movs r2, 0
	bl sub_80928C0
	movs r0, 0x1
	mov r9, r0
_08080848:
	mov r1, r9
	cmp r1, 0
	beq _08080864
	ldr r0, _08080860
	ldr r2, [r0]
	mov r0, r8
	adds r1, r7, 0
	bl sub_80522F4
	b _08080870
	.align 2, 0
_0808085C: .4byte gUnknown_202DE58
_08080860: .4byte gUnknown_80FDB04
_08080864:
	ldr r0, _08080880
	ldr r2, [r0]
	mov r0, r8
	adds r1, r7, 0
	bl sub_80522F4
_08080870:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080880: .4byte gUnknown_80FDB2C
	thumb_func_end sub_80807C0

	thumb_func_start sub_8080884
sub_8080884:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _0808089E
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807CD9C
_0808089E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8080884

	thumb_func_start sub_80808A4
sub_80808A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp, 0x14]
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp, 0x20]
	ldr r6, _080808D0
	ldr r0, [r6]
	ldr r1, _080808D4
	adds r0, r1
	ldrb r4, [r0]
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _080808DC
	ldr r0, _080808D8
	b _08080A2E
	.align 2, 0
_080808D0: .4byte gDungeonGlobalData
_080808D4: .4byte 0x00018209
_080808D8: .4byte gUnknown_80FED08
_080808DC:
	cmp r4, 0
	bne _080808E2
	movs r4, 0x2
_080808E2:
	movs r2, 0
	ldrsh r0, [r5, r2]
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	bl GetMapTileAtPosition
	ldrb r1, [r0, 0x9]
	cmp r1, 0xFF
	bne _0808090A
	movs r0, 0
	ldrsh r1, [r5, r0]
	subs r2, r1, r4
	str r2, [sp, 0x18]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	subs r2, r0, r4
	adds r1, r4
	mov r10, r1
	adds r0, r4
	b _08080934
_0808090A:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, _08080994
	adds r0, r1
	ldr r1, [r6]
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	str r0, [sp, 0x18]
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	subs r2, r0, 0x1
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	mov r10, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	adds r0, 0x1
_08080934:
	str r0, [sp, 0x1C]
	adds r7, r2, 0
	ldr r0, [sp, 0x1C]
	cmp r7, r0
	bgt _08080A26
_0808093E:
	ldr r6, [sp, 0x18]
	adds r1, r7, 0x1
	str r1, [sp, 0x24]
	cmp r6, r10
	bgt _08080A1E
	mov r5, sp
_0808094A:
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMapTileAtPosition
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	adds r2, r6, 0x1
	mov r9, r2
	cmp r0, 0
	beq _08080A18
	bl GetEntityType
	cmp r0, 0x3
	bne _08080A18
	ldr r0, [r4, 0x14]
	bl GetItemData
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08080A18
	movs r0, 0xBE
	lsls r0, 1
	strh r0, [r5]
	movs r2, 0
	mov r4, sp
_08080980:
	ldr r0, _08080998
	ldr r0, [r0]
	ldr r3, _0808099C
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080809A0
	movs r0, 0xBE
	lsls r0, 1
	b _080809AE
	.align 2, 0
_08080994: .4byte 0x000104c4
_08080998: .4byte gDungeonGlobalData
_0808099C: .4byte 0x0000066e
_080809A0:
	movs r0, 0
	str r2, [sp, 0x28]
	bl sub_803D970
	lsls r0, 16
	asrs r0, 16
	ldr r2, [sp, 0x28]
_080809AE:
	movs r1, 0
	mov r8, r1
	movs r3, 0
	strh r0, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0
	str r2, [sp, 0x28]
	str r3, [sp, 0x2C]
	bl sub_806AA0C
	lsls r0, 24
	ldr r2, [sp, 0x28]
	ldr r3, [sp, 0x2C]
	cmp r0, 0
	bne _080809D4
	adds r2, 0x1
	cmp r2, 0x63
	ble _08080980
_080809D4:
	movs r2, 0
	ldrsh r0, [r5, r2]
	movs r1, 0
	str r3, [sp, 0x2C]
	bl sub_806AA0C
	lsls r0, 24
	ldr r3, [sp, 0x2C]
	cmp r0, 0
	beq _08080A10
	strh r3, [r5, 0x8]
	mov r0, r8
	strb r0, [r5, 0x2]
	strh r6, [r5, 0xC]
	strh r7, [r5, 0xE]
	str r3, [sp, 0x4]
	strb r0, [r5, 0x10]
	mov r0, sp
	movs r1, 0x1
	bl sub_806B7F8
	cmp r0, 0
	beq _08080A10
	add r0, sp, 0xC
	movs r1, 0
	bl sub_80461C8
	ldr r1, [sp, 0x20]
	adds r1, 0x1
	str r1, [sp, 0x20]
_08080A10:
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80402AC
_08080A18:
	mov r6, r9
	cmp r6, r10
	ble _0808094A
_08080A1E:
	ldr r7, [sp, 0x24]
	ldr r2, [sp, 0x1C]
	cmp r7, r2
	ble _0808093E
_08080A26:
	ldr r3, [sp, 0x20]
	cmp r3, 0
	beq _08080A3C
	ldr r0, _08080A38
_08080A2E:
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
	b _08080A46
	.align 2, 0
_08080A38: .4byte gUnknown_80FDACC
_08080A3C:
	ldr r0, _08080A58
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
_08080A46:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080A58: .4byte gUnknown_80FDAE4
	thumb_func_end sub_80808A4

	thumb_func_start sub_8080A5C
sub_8080A5C:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _08080AEC
	adds r0, r4, 0
	movs r1, 0x6
	movs r2, 0x8
	bl sub_806CDD4
	movs r0, 0x10
	movs r1, 0x55
	bl sub_803E708
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_806CE68
	ldr r5, [r4, 0x70]
	adds r2, r5, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08080AEC
	ldr r0, [r5, 0x60]
	str r0, [sp, 0x8]
	movs r0, 0
	strb r0, [r2]
	bl FillInventoryGaps
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, 0
	bl sub_80421C0
	adds r0, r5, 0
	adds r0, 0x46
	ldrb r0, [r0]
	movs r2, 0x7
	ands r2, r0
	ldr r0, _08080AF4
	lsls r2, 2
	adds r2, r0
	ldrh r0, [r2]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _08080AF8
	ldr r1, [sp, 0x4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, 0x4]
	ldrh r0, [r2, 0x2]
	ldrh r2, [r4, 0x6]
	adds r0, r2
	lsls r0, 16
	ldr r2, _08080AFC
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x4]
	adds r1, r4, 0x4
	add r3, sp, 0x8
	str r6, [sp]
	adds r0, r7, 0
	add r2, sp, 0x4
	bl sub_804687C
_08080AEC:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080AF4: .4byte gAdjacentTileOffsets
_08080AF8: .4byte 0xffff0000
_08080AFC: .4byte 0x0000ffff
	thumb_func_end sub_8080A5C

	thumb_func_start sub_8080B00
sub_8080B00:
	push {r4,r5,lr}
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r4, [r0, 0x14]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08080B2A
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _08080B26
	adds r0, r4, 0
	bl GetTrapData
	strb r5, [r0]
_08080B26:
	bl sub_8049ED4
_08080B2A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8080B00

	thumb_func_start sub_8080B30
sub_8080B30:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_8082F9C
	movs r0, 0
	str r0, [sp, 0xC]
	add r1, sp, 0xC
	mov r0, sp
	movs r2, 0x4
	bl sub_8082FA8
	mov r0, sp
	bl sub_8080B90
	mov r0, sp
	bl sub_8081454
	mov r0, sp
	bl sub_808165C
	mov r0, sp
	bl sub_808173C
	mov r0, sp
	bl sub_8080BBC
	mov r0, sp
	bl sub_8080C44
	mov r0, sp
	bl sub_8080CF0
	ldr r1, _08080B8C
	mov r0, sp
	bl sub_808300C
	mov r0, sp
	bl nullsub_98
	add sp, 0x10
	pop {r0}
	bx r0
	.align 2, 0
_08080B8C: .4byte gUnknown_81071D4
	thumb_func_end sub_8080B30

	thumb_func_start sub_8080B90
sub_8080B90:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08080BB0
	bl sub_808300C
	ldr r0, _08080BB4
	ldr r1, [r0]
	ldr r0, _08080BB8
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0x58
	bl sub_8082FA8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080BB0: .4byte gUnknown_81071E0
_08080BB4: .4byte gDungeonGlobalData
_08080BB8: .4byte 0x00000644
	thumb_func_end sub_8080B90

	thumb_func_start sub_8080BBC
sub_8080BBC:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	ldr r1, _08080C38
	movs r2, 0
	add r0, sp, 0x4
_08080BC8:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _08080BC8
	adds r0, r6, 0
	bl sub_808300C
	movs r7, 0
_08080BD8:
	ldr r0, _08080C3C
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08080C40
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	movs r5, 0
	cmp r4, 0
	beq _08080C1A
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x3
	bne _08080C1A
	adds r0, r4, 0
	bl GetItemData
	adds r1, r0, 0
	adds r0, r6, 0
	bl sub_8081788
	adds r1, r4, 0x4
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x6
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	movs r5, 0x1
_08080C1A:
	cmp r5, 0
	bne _08080C28
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x5
	bl sub_8082FA8
_08080C28:
	adds r7, 0x1
	cmp r7, 0x3F
	ble _08080BD8
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080C38: .4byte gUnknown_81071E0
_08080C3C: .4byte gDungeonGlobalData
_08080C40: .4byte 0x0001361c
	thumb_func_end sub_8080BBC

	thumb_func_start sub_8080C44
sub_8080C44:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r7, 0
	ldr r3, _08080CE4
	movs r2, 0xFF
_08080C50:
	mov r0, sp
	adds r1, r0, r7
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r7, 0x1
	cmp r7, 0x4
	ble _08080C50
	adds r0, r6, 0
	adds r1, r3, 0
	bl sub_808300C
	movs r7, 0
_08080C6A:
	ldr r0, _08080CE8
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08080CEC
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	movs r4, 0
	cmp r5, 0
	beq _08080CC8
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _08080CC8
	adds r0, r5, 0
	bl GetTrapData
	adds r4, r0, 0
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x1
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0
	adds r1, 0x20
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x4
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x6
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	movs r4, 0x1
_08080CC8:
	cmp r4, 0
	bne _08080CD6
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x5
	bl sub_8082FA8
_08080CD6:
	adds r7, 0x1
	cmp r7, 0x3F
	ble _08080C6A
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080CE4: .4byte gUnknown_81071E0
_08080CE8: .4byte gDungeonGlobalData
_08080CEC: .4byte 0x0001371c
	thumb_func_end sub_8080C44

	thumb_func_start sub_8080CF0
sub_8080CF0:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r1, _08080DD4
	bl sub_808300C
	ldr r4, _08080DD8
	ldr r0, [r4]
	ldr r1, _08080DDC
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8083078
	ldr r0, [r4]
	ldr r2, _08080DE0
	adds r0, r2
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8083078
	ldr r0, [r4]
	ldr r1, _08080DE4
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080DE8
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08080DEC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080DF0
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08080DF4
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080DF8
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08080DFC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080E00
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	movs r1, 0xE0
	lsls r1, 6
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r6, 0
	bl sub_8083030
	movs r5, 0
_08080D9A:
	ldr r0, [r4]
	lsls r1, r5, 2
	ldr r2, _08080E04
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8080E0C
	adds r5, 0x1
	cmp r5, 0x3
	ble _08080D9A
	movs r5, 0
	ldr r4, _08080DD8
_08080DB6:
	ldr r0, [r4]
	lsls r1, r5, 2
	ldr r2, _08080E08
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8080E0C
	adds r5, 0x1
	cmp r5, 0xF
	ble _08080DB6
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08080DD4: .4byte gUnknown_81071E0
_08080DD8: .4byte gDungeonGlobalData
_08080DDC: .4byte 0x000037f0
_08080DE0: .4byte 0x000037f4
_08080DE4: .4byte 0x000037f8
_08080DE8: .4byte 0x000037f9
_08080DEC: .4byte 0x000037fa
_08080DF0: .4byte 0x000037fb
_08080DF4: .4byte 0x000037fc
_08080DF8: .4byte 0x000037fd
_08080DFC: .4byte 0x000037fe
_08080E00: .4byte 0x000037ff
_08080E04: .4byte 0x0001357c
_08080E08: .4byte 0x0001358c
	thumb_func_end sub_8080CF0

	thumb_func_start sub_8080E0C
sub_8080E0C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08080E88
	add sp, r4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	add r0, sp, 0x20C
	str r1, [r0]
	movs r1, 0x1
	movs r6, 0x82
	lsls r6, 2
	mov r2, sp
	adds r0, r2, r6
	str r1, [r0]
	adds r0, r5, 0
	movs r1, 0xAA
	bl sub_8083060
	adds r0, r5, 0
	movs r1, 0x55
	bl sub_8083060
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08080E8C
	ldr r6, [r4, 0x70]
	add r1, sp, 0x208
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x6
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x26
	adds r0, r5, 0
	movs r2, 0x2
	bl sub_8082FA8
	b _08080ECC
	.align 2, 0
_08080E88: .4byte 0xfffffd6c
_08080E8C:
	mov r0, sp
	movs r1, 0
	adds r2, r6, 0
	bl memset
	mov r6, sp
	add r4, sp, 0x20C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_8082FA8
_08080ECC:
	ldrh r1, [r6]
	adds r0, r5, 0
	bl sub_8083030
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_80817F4
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_80817F4
	ldrb r1, [r6, 0x6]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r6, 0x7]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r6, 0x8]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x9]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0xA]
	adds r0, r5, 0
	bl sub_8083060
	adds r1, r6, 0
	adds r1, 0x40
	adds r0, r5, 0
	bl sub_80818C8
	movs r0, 0xC
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0xE
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x10
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x12
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	ldrb r1, [r6, 0x14]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x15]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x16]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x17]
	adds r0, r5, 0
	bl sub_8083060
	ldr r1, [r6, 0x18]
	adds r0, r5, 0
	bl sub_8083078
	movs r0, 0x1C
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x1E
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x20
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x22
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x24
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x26
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x28
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	ldr r1, [r6, 0x2C]
	adds r0, r5, 0
	bl sub_80830A0
	ldr r1, [r6, 0x30]
	adds r0, r5, 0
	bl sub_80830A0
	ldr r1, [r6, 0x34]
	adds r0, r5, 0
	bl sub_80830A0
	ldr r1, [r6, 0x38]
	adds r0, r5, 0
	bl sub_80830A0
	adds r1, r6, 0
	adds r1, 0x44
	adds r0, r5, 0
	bl sub_80817C8
	adds r0, r6, 0
	adds r0, 0x5C
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_808180C
	adds r0, r6, 0
	adds r0, 0x5D
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_808180C
	adds r0, r6, 0
	adds r0, 0x5E
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8081824
	adds r0, r6, 0
	adds r0, 0x5F
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8081824
	adds r1, r6, 0
	adds r1, 0x60
	adds r0, r5, 0
	bl sub_8081788
	adds r0, r6, 0
	adds r0, 0x64
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80817B0
	movs r1, 0x78
	adds r1, r6
	mov r8, r1
	movs r2, 0x8C
	adds r2, r6
	mov r9, r2
	movs r0, 0x90
	adds r0, r6
	mov r10, r0
	adds r1, r6, 0
	adds r1, 0x94
	str r1, [sp, 0x214]
	adds r2, r6, 0
	adds r2, 0x3C
	str r2, [sp, 0x210]
	adds r0, r6, 0
	adds r0, 0x98
	str r0, [sp, 0x218]
	adds r1, 0x8
	str r1, [sp, 0x21C]
	adds r2, 0x64
	str r2, [sp, 0x220]
	adds r0, 0x10
	str r0, [sp, 0x228]
	adds r1, 0x10
	str r1, [sp, 0x22C]
	adds r2, 0x10
	str r2, [sp, 0x230]
	adds r0, 0x14
	str r0, [sp, 0x234]
	adds r1, 0x14
	str r1, [sp, 0x238]
	adds r2, 0x14
	str r2, [sp, 0x23C]
	adds r0, 0xC
	str r0, [sp, 0x240]
	adds r1, 0x10
	str r1, [sp, 0x244]
	adds r2, 0x18
	str r2, [sp, 0x248]
	adds r0, 0x18
	str r0, [sp, 0x24C]
	adds r1, 0x14
	str r1, [sp, 0x250]
	adds r2, 0xC
	str r2, [sp, 0x254]
	adds r0, 0xC
	str r0, [sp, 0x258]
	adds r1, 0xC
	str r1, [sp, 0x25C]
	adds r2, 0x9
	str r2, [sp, 0x260]
	adds r0, 0x6
	str r0, [sp, 0x264]
	adds r1, 0x3
	str r1, [sp, 0x268]
	adds r2, 0x3
	str r2, [sp, 0x26C]
	adds r0, 0x9
	str r0, [sp, 0x280]
	adds r1, 0x2
	str r1, [sp, 0x270]
	adds r2, 0x2
	str r2, [sp, 0x274]
	subs r0, 0x4
	str r0, [sp, 0x278]
	adds r1, 0x5
	str r1, [sp, 0x27C]
	adds r2, 0x6
	str r2, [sp, 0x284]
	adds r0, 0x6
	str r0, [sp, 0x288]
	adds r1, 0x4
	str r1, [sp, 0x28C]
	adds r2, 0x3
	str r2, [sp, 0x290]
	subs r0, 0x59
	str r0, [sp, 0x224]
	adds r4, r6, 0
	adds r4, 0x68
	movs r7, 0x3
_080810C2:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80830D8
	adds r4, 0x4
	subs r7, 0x1
	cmp r7, 0
	bge _080810C2
	adds r0, r5, 0
	mov r1, r8
	bl sub_80818E4
	adds r0, r5, 0
	mov r1, r9
	bl sub_8081B54
	adds r0, r5, 0
	mov r1, r10
	bl sub_8081B54
	ldr r2, [sp, 0x214]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_8081880
	adds r0, r5, 0
	ldr r1, [sp, 0x210]
	bl sub_8081898
	ldr r0, [sp, 0x218]
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8083078
	ldr r2, [sp, 0x21C]
	ldr r1, [r2]
	adds r0, r5, 0
	bl sub_8083078
	ldr r0, [sp, 0x220]
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8083078
	adds r0, r5, 0
	ldr r1, [sp, 0x228]
	bl sub_8081920
	adds r0, r5, 0
	ldr r1, [sp, 0x22C]
	bl sub_808193C
	adds r0, r5, 0
	ldr r1, [sp, 0x230]
	bl sub_8081968
	adds r0, r5, 0
	ldr r1, [sp, 0x234]
	bl sub_8081994
	adds r0, r5, 0
	ldr r1, [sp, 0x238]
	bl sub_80819B0
	adds r0, r5, 0
	ldr r1, [sp, 0x23C]
	bl sub_80819D4
	adds r0, r5, 0
	ldr r1, [sp, 0x240]
	bl sub_80819F0
	adds r0, r5, 0
	ldr r1, [sp, 0x244]
	bl sub_8081A24
	adds r0, r5, 0
	ldr r1, [sp, 0x248]
	bl sub_8081A58
	adds r0, r5, 0
	ldr r1, [sp, 0x24C]
	bl sub_8081A74
	adds r0, r5, 0
	ldr r1, [sp, 0x250]
	bl sub_8081A80
	adds r0, r5, 0
	ldr r1, [sp, 0x254]
	bl sub_8081A9C
	adds r0, r5, 0
	ldr r1, [sp, 0x258]
	bl sub_8081AB8
	ldr r2, [sp, 0x25C]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x260]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, [sp, 0x264]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x268]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, [sp, 0x26C]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x280]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, [sp, 0x270]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x274]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, [sp, 0x278]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x27C]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, [sp, 0x284]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x288]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, [sp, 0x28C]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_8083060
	ldr r0, [sp, 0x290]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_808183C
	movs r1, 0x80
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8081854
	movs r2, 0x82
	lsls r2, 1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_808186C
	movs r0, 0x84
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_808314C
	ldr r2, _08081428
	adds r1, r6, r2
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_808314C
	movs r1, 0x89
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _0808142C
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r2, 0x8C
	lsls r2, 1
	adds r1, r6, r2
	adds r0, r5, 0
	bl sub_8081B08
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r5, 0
	bl sub_8081B34
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r6, r2
	adds r0, r5, 0
	bl sub_8081B34
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, _08081430
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r1, _08081434
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r2, 0xA3
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, _08081438
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xA5
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, _0808143C
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r2, 0xA7
	lsls r2, 1
	adds r0, r6, r2
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_8083030
	movs r1, 0xA8
	lsls r1, 1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_8083030
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r1, _08081440
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r1, _08081444
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r2, 0xAB
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _08081448
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r1, 0xB3
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _0808144C
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _08081450
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r5, 0
	bl sub_80830D8
	movs r1, 0xBA
	lsls r1, 1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_80830A0
	movs r2, 0xBC
	lsls r2, 1
	adds r0, r6, r2
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_8083030
	movs r1, 0xFC
	lsls r1, 1
	adds r0, r6, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r1, 0xFD
	lsls r1, 1
	adds r0, r6, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8083078
	ldr r2, [sp, 0x224]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80818B8
	movs r3, 0xA5
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081428: .4byte 0x0000010d
_0808142C: .4byte 0x00000113
_08081430: .4byte 0x00000145
_08081434: .4byte 0x00000147
_08081438: .4byte 0x00000149
_0808143C: .4byte 0x0000014b
_08081440: .4byte 0x00000153
_08081444: .4byte 0x00000155
_08081448: .4byte 0x00000165
_0808144C: .4byte 0x00000167
_08081450: .4byte 0x00000169
	thumb_func_end sub_8080E0C

	thumb_func_start sub_8081454
sub_8081454:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	ldr r1, _08081600
	bl sub_808300C
	ldr r4, _08081604
	ldr r0, [r4]
	ldr r1, _08081608
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _0808160C
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081610
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08081614
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081618
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r2, _0808161C
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r1, _08081620
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081624
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081628
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _0808162C
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081630
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	movs r1, 0
	mov r9, r4
_08081510:
	lsls r0, r1, 2
	adds r2, r1, 0x1
	mov r8, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081634
	adds r6, r0, r1
	movs r5, 0
	movs r4, 0x37
_08081526:
	mov r2, r9
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081B60
	adds r5, 0x18
	subs r4, 0x1
	cmp r4, 0
	bge _08081526
	mov r1, r8
	cmp r1, 0x1F
	ble _08081510
	ldr r4, _08081604
	ldr r1, [r4]
	ldr r0, _08081638
	adds r1, r0
	adds r0, r7, 0
	bl sub_80830D8
	ldr r1, [r4]
	ldr r2, _0808163C
	adds r1, r2
	adds r0, r7, 0
	bl sub_80830D8
	ldr r6, _08081640
	movs r5, 0x7
_08081560:
	ldr r1, [r4]
	adds r1, r6
	adds r0, r7, 0
	bl sub_80830D8
	adds r6, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08081560
	ldr r4, _08081604
	ldr r1, [r4]
	ldr r0, _08081644
	adds r1, r0
	adds r0, r7, 0
	bl sub_80830F8
	ldr r1, [r4]
	ldr r2, _08081648
	adds r1, r2
	adds r0, r7, 0
	bl sub_80830F8
	ldr r1, [r4]
	ldr r0, _0808164C
	adds r1, r0
	adds r0, r7, 0
	bl sub_808312C
	movs r1, 0
	mov r10, r4
_0808159C:
	movs r4, 0
	adds r2, r1, 0x1
	mov r8, r2
	lsls r0, r1, 1
	lsls r2, r1, 3
	mov r9, r2
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081650
	adds r6, r0, r1
	movs r5, 0
_080815B2:
	mov r2, r10
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081B60
	mov r1, r10
	ldr r0, [r1]
	mov r2, r9
	adds r1, r4, r2
	ldr r2, _08081654
	adds r0, r2
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8083060
	adds r5, 0x18
	adds r4, 0x1
	cmp r4, 0x7
	ble _080815B2
	mov r1, r8
	cmp r1, 0x7
	ble _0808159C
	ldr r0, _08081604
	ldr r1, [r0]
	ldr r0, _08081658
	adds r1, r0
	adds r0, r7, 0
	bl sub_8081B94
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081600: .4byte gUnknown_81071E0
_08081604: .4byte gDungeonGlobalData
_08081608: .4byte 0x00003a08
_0808160C: .4byte 0x00003a09
_08081610: .4byte 0x00003a0a
_08081614: .4byte 0x00003a0b
_08081618: .4byte 0x00003a0c
_0808161C: .4byte 0x00003a0d
_08081620: .4byte 0x00003a0e
_08081624: .4byte 0x00003a10
_08081628: .4byte 0x00003a12
_0808162C: .4byte 0x00003a14
_08081630: .4byte 0x00003a16
_08081634: .4byte 0x00003a18
_08081638: .4byte 0x0000e218
_0808163C: .4byte 0x0000e21c
_08081640: .4byte 0x0000e220
_08081644: .4byte 0x0000e240
_08081648: .4byte 0x0000e250
_0808164C: .4byte 0x0000e260
_08081650: .4byte 0x0000e27c
_08081654: .4byte 0x0000e87c
_08081658: .4byte 0x0000e264
	thumb_func_end sub_8081454

	thumb_func_start sub_808165C
sub_808165C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08081708
	bl sub_808300C
	ldr r4, _0808170C
	ldr r0, [r4]
	ldr r1, _08081710
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r1, _08081714
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r1, _08081718
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _0808171C
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081720
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081724
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081728
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _0808172C
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081730
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081734
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081738
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081708: .4byte gUnknown_81071E0
_0808170C: .4byte gDungeonGlobalData
_08081710: .4byte 0x00018208
_08081714: .4byte 0x00018209
_08081718: .4byte 0x0001820a
_0808171C: .4byte 0x0001820b
_08081720: .4byte 0x0001820c
_08081724: .4byte 0x0001820d
_08081728: .4byte 0x0001820e
_0808172C: .4byte 0x0001820f
_08081730: .4byte 0x00018210
_08081734: .4byte 0x00018211
_08081738: .4byte 0x00018213
	thumb_func_end sub_808165C

	thumb_func_start sub_808173C
sub_808173C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _08081778
	ldr r0, [r4]
	ldr r1, _0808177C
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081780
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081784
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081778: .4byte gDungeonGlobalData
_0808177C: .4byte 0x0001ced6
_08081780: .4byte 0x0001ced8
_08081784: .4byte 0x0001ceda
	thumb_func_end sub_808173C

	thumb_func_start sub_8081788
sub_8081788:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081788

	thumb_func_start sub_80817B0
sub_80817B0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80817B0

	thumb_func_start sub_80817C8
sub_80817C8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, r4, 0x2
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x16
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80817C8

	thumb_func_start sub_80817F4
sub_80817F4:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80817F4

	thumb_func_start sub_808180C
sub_808180C:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808180C

	thumb_func_start sub_8081824
sub_8081824:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8081824

	thumb_func_start sub_808183C
sub_808183C:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808183C

	thumb_func_start sub_8081854
sub_8081854:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8081854

	thumb_func_start sub_808186C
sub_808186C:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808186C

	thumb_func_start sub_8081880
sub_8081880:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8081880

	thumb_func_start sub_8081898
sub_8081898:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_8083048
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_808180C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081898

	thumb_func_start sub_80818B8
sub_80818B8:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	bl sub_8083060
	pop {r0}
	bx r0
	thumb_func_end sub_80818B8

	thumb_func_start sub_80818C8
sub_80818C8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	bl sub_8083060
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80818C8

	thumb_func_start sub_80818E4
sub_80818E4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r4, 0x3]
	adds r0, r5, 0
	bl sub_80830B4
	ldrh r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083030
	adds r4, 0x10
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80830D8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80818E4

	thumb_func_start sub_8081920
sub_8081920:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081920

	thumb_func_start sub_808193C
sub_808193C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x3]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808193C

	thumb_func_start sub_8081968
sub_8081968:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x8]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x9]
	adds r0, r5, 0
	bl sub_8083060
	ldr r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083078
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081968

	thumb_func_start sub_8081994
sub_8081994:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081994

	thumb_func_start sub_80819B0
sub_80819B0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80819B0

	thumb_func_start sub_80819D4
sub_80819D4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80819D4

	thumb_func_start sub_80819F0
sub_80819F0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r4, 0x3]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80819F0

	thumb_func_start sub_8081A24
sub_8081A24:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldr r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083078
	ldrb r1, [r4, 0x8]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x9]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0xA]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A24

	thumb_func_start sub_8081A58
sub_8081A58:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A58

	thumb_func_start sub_8081A74
sub_8081A74:
	push {lr}
	movs r2, 0x1
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_8081A74

	thumb_func_start sub_8081A80
sub_8081A80:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A80

	thumb_func_start sub_8081A9C
sub_8081A9C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A9C

	thumb_func_start sub_8081AB8
sub_8081AB8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081AB8

	thumb_func_start sub_8081AD4
sub_8081AD4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	bl sub_8083060
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x2
	bl sub_8082FA8
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x5]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081AD4

	thumb_func_start sub_8081B08
sub_8081B08:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_08081B12:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8081AD4
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08081B12
	adds r0, r7, 0
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8083060
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B08

	thumb_func_start sub_8081B34
sub_8081B34:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_8083048
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B34

	thumb_func_start sub_8081B54
sub_8081B54:
	push {lr}
	movs r2, 0x3
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_8081B54

	thumb_func_start sub_8081B60
sub_8081B60:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrh r1, [r4]
	bl sub_8083030
	ldrh r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083030
	adds r1, r4, 0
	adds r1, 0x9
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0xE
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B60

	thumb_func_start sub_8081B94
sub_8081B94:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x1
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	movs r4, 0
_08081BAC:
	adds r0, r5, 0x3
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8083060
	adds r0, r5, 0
	adds r0, 0xB
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8083060
	adds r4, 0x1
	cmp r4, 0x7
	ble _08081BAC
	ldrb r1, [r5, 0x2]
	adds r0, r6, 0
	bl sub_8083060
	ldrb r1, [r5, 0x13]
	adds r0, r6, 0
	bl sub_8083060
	ldrb r1, [r5, 0x14]
	adds r0, r6, 0
	bl sub_8083060
	ldrb r1, [r5, 0x15]
	adds r0, r6, 0
	bl sub_80830B4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B94

	thumb_func_start sub_8081BF4
sub_8081BF4:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_8082FD4
	add r1, sp, 0xC
	mov r0, sp
	movs r2, 0x4
	bl sub_8082FE0
	mov r0, sp
	bl sub_8081C50
	mov r0, sp
	bl sub_8081C7C
	mov r0, sp
	bl sub_8081F2C
	mov r0, sp
	bl sub_808201C
	mov r0, sp
	bl sub_8082060
	mov r0, sp
	bl sub_80820D8
	mov r0, sp
	bl sub_808217C
	ldr r1, _08081C4C
	mov r0, sp
	bl sub_8083018
	mov r0, sp
	bl nullsub_98
	add sp, 0x10
	pop {r0}
	bx r0
	.align 2, 0
_08081C4C: .4byte gUnknown_81071D4
	thumb_func_end sub_8081BF4

	thumb_func_start sub_8081C50
sub_8081C50:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08081C70
	bl sub_8083018
	ldr r0, _08081C74
	ldr r1, [r0]
	ldr r0, _08081C78
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0x58
	bl sub_8082FE0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08081C70: .4byte gUnknown_81071E0
_08081C74: .4byte gDungeonGlobalData
_08081C78: .4byte 0x00000644
	thumb_func_end sub_8081C50

	thumb_func_start sub_8081C7C
sub_8081C7C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	ldr r1, _08081E20
	bl sub_8083018
	adds r0, r7, 0
	bl sub_80831DC
	ldr r4, _08081E24
	ldr r1, [r4]
	ldr r2, _08081E28
	adds r1, r2
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r3, _08081E2C
	adds r1, r3
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08081E30
	adds r1, r2
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r3, _08081E34
	adds r1, r3
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r2, _08081E38
	adds r1, r2
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r3, _08081E3C
	adds r1, r3
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08081E40
	adds r1, r2
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r3, _08081E44
	adds r1, r3
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08081E48
	adds r1, r2
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r3, _08081E4C
	adds r1, r3
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08081E50
	adds r1, r2
	strh r0, [r1]
	movs r1, 0
	mov r9, r4
_08081D2E:
	lsls r0, r1, 2
	adds r3, r1, 0x1
	mov r8, r3
	adds r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081E54
	adds r6, r0, r1
	movs r5, 0
	movs r4, 0x37
_08081D44:
	mov r2, r9
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081E7C
	adds r5, 0x18
	subs r4, 0x1
	cmp r4, 0
	bge _08081D44
	mov r1, r8
	cmp r1, 0x1F
	ble _08081D2E
	ldr r4, _08081E24
	ldr r1, [r4]
	ldr r3, _08081E58
	adds r1, r3
	adds r0, r7, 0
	bl sub_80831F8
	ldr r1, [r4]
	ldr r0, _08081E5C
	adds r1, r0
	adds r0, r7, 0
	bl sub_80831F8
	ldr r6, _08081E60
	movs r5, 0x7
_08081D7E:
	ldr r1, [r4]
	adds r1, r6
	adds r0, r7, 0
	bl sub_80831F8
	adds r6, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08081D7E
	ldr r4, _08081E24
	ldr r1, [r4]
	ldr r2, _08081E64
	adds r1, r2
	adds r0, r7, 0
	bl sub_8083220
	ldr r1, [r4]
	ldr r3, _08081E68
	adds r1, r3
	adds r0, r7, 0
	bl sub_8083220
	ldr r1, [r4]
	ldr r0, _08081E6C
	adds r1, r0
	adds r0, r7, 0
	bl sub_8083260
	movs r1, 0
	mov r10, r4
_08081DBA:
	movs r4, 0
	adds r2, r1, 0x1
	mov r8, r2
	lsls r0, r1, 1
	lsls r3, r1, 3
	mov r9, r3
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081E70
	adds r6, r0, r1
	movs r5, 0
_08081DD0:
	mov r2, r10
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081E7C
	adds r0, r7, 0
	bl sub_8083188
	mov r3, r10
	ldr r1, [r3]
	mov r3, r9
	adds r2, r4, r3
	ldr r3, _08081E74
	adds r1, r3
	adds r1, r2
	strb r0, [r1]
	adds r5, 0x18
	adds r4, 0x1
	cmp r4, 0x7
	ble _08081DD0
	mov r1, r8
	cmp r1, 0x7
	ble _08081DBA
	ldr r0, _08081E24
	ldr r1, [r0]
	ldr r0, _08081E78
	adds r1, r0
	adds r0, r7, 0
	bl sub_8081EC0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081E20: .4byte gUnknown_81071E0
_08081E24: .4byte gDungeonGlobalData
_08081E28: .4byte 0x00003a08
_08081E2C: .4byte 0x00003a09
_08081E30: .4byte 0x00003a0a
_08081E34: .4byte 0x00003a0b
_08081E38: .4byte 0x00003a0c
_08081E3C: .4byte 0x00003a0d
_08081E40: .4byte 0x00003a0e
_08081E44: .4byte 0x00003a10
_08081E48: .4byte 0x00003a12
_08081E4C: .4byte 0x00003a14
_08081E50: .4byte 0x00003a16
_08081E54: .4byte 0x00003a18
_08081E58: .4byte 0x0000e218
_08081E5C: .4byte 0x0000e21c
_08081E60: .4byte 0x0000e220
_08081E64: .4byte 0x0000e240
_08081E68: .4byte 0x0000e250
_08081E6C: .4byte 0x0000e260
_08081E70: .4byte 0x0000e27c
_08081E74: .4byte 0x0000e87c
_08081E78: .4byte 0x0000e264
	thumb_func_end sub_8081C7C

	thumb_func_start sub_8081E7C
sub_8081E7C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x18
	bl memset
	adds r0, r5, 0
	bl sub_8083158
	movs r6, 0
	strh r0, [r4]
	adds r0, r5, 0
	bl sub_8083158
	strh r0, [r4, 0x4]
	adds r1, r4, 0
	adds r1, 0x9
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0
	adds r1, 0xE
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	str r6, [r4, 0x10]
	str r6, [r4, 0x14]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8081E7C

	thumb_func_start sub_8081EC0
sub_8081EC0:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x18
	bl memset
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r5, 0x1
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FE0
	movs r4, 0
_08081EE6:
	adds r0, r6, 0
	bl sub_8083188
	adds r1, r5, 0x3
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	bl sub_8083188
	adds r1, r5, 0
	adds r1, 0xB
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x7
	ble _08081EE6
	adds r0, r6, 0
	bl sub_8083188
	strb r0, [r5, 0x2]
	adds r0, r6, 0
	bl sub_8083188
	strb r0, [r5, 0x13]
	adds r0, r6, 0
	bl sub_8083188
	strb r0, [r5, 0x14]
	adds r0, r6, 0
	bl sub_80831DC
	strb r0, [r5, 0x15]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8081EC0

	thumb_func_start sub_8081F2C
sub_8081F2C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08081FE4
	bl sub_8083018
	ldr r4, _08081FE8
	ldr r0, [r4]
	ldr r1, _08081FEC
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r2, _08081FF0
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r2, _08081FF4
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08081FF8
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08081FFC
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082000
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082004
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082008
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _0808200C
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082010
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082014
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082018
	adds r1, r2
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081FE4: .4byte gUnknown_81071E0
_08081FE8: .4byte gDungeonGlobalData
_08081FEC: .4byte 0x000181f8
_08081FF0: .4byte 0x00018208
_08081FF4: .4byte 0x00018209
_08081FF8: .4byte 0x0001820a
_08081FFC: .4byte 0x0001820b
_08082000: .4byte 0x0001820c
_08082004: .4byte 0x0001820d
_08082008: .4byte 0x0001820e
_0808200C: .4byte 0x0001820f
_08082010: .4byte 0x00018210
_08082014: .4byte 0x00018211
_08082018: .4byte 0x00018213
	thumb_func_end sub_8081F2C

	thumb_func_start sub_808201C
sub_808201C:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8083170
	ldr r4, _08082050
	ldr r1, [r4]
	ldr r2, _08082054
	adds r1, r2
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08082058
	adds r1, r2
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _0808205C
	adds r1, r2
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082050: .4byte gDungeonGlobalData
_08082054: .4byte 0x0001ced6
_08082058: .4byte 0x0001ced8
_0808205C: .4byte 0x0001ceda
	thumb_func_end sub_808201C

	thumb_func_start sub_8082060
sub_8082060:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r1, _080820A4
	bl sub_8083018
	add r4, sp, 0x4
	mov r7, sp
	movs r6, 0x3F
_08082072:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80820A8
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08082096
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0
	bl sub_80460F8
_08082096:
	subs r6, 0x1
	cmp r6, 0
	bge _08082072
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080820A4: .4byte gUnknown_81071E0
	thumb_func_end sub_8082060

	thumb_func_start sub_80820A8
sub_80820A8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0x1
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80820A8

	thumb_func_start sub_80820D8
sub_80820D8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r1, _08082178
	bl sub_8083018
	movs r0, 0x1
	add r0, sp
	mov r9, r0
	add r1, sp, 0x4
	mov r8, r1
	mov r7, sp
	movs r2, 0x3F
	mov r10, r2
_080820FC:
	movs r0, 0x6
	strb r0, [r7]
	movs r0, 0
	mov r3, sp
	strb r0, [r3, 0x1]
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r5, 0
	mov r1, sp
	adds r1, 0x1
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r5, 0
	bl sub_80831DC
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0
	add r1, sp, 0x4
	bl sub_80831F8
	ldrb r0, [r7]
	cmp r0, 0xFF
	beq _0808215C
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	mov r3, sp
	movs r2, 0x6
	ldrsh r1, [r3, r2]
	bl GetMapEntity
	adds r4, r0, 0
	ldrb r0, [r7]
	mov r3, r9
	ldrb r2, [r3]
	mov r1, r8
	bl sub_8045684
	cmp r0, 0
	beq _0808215C
	str r0, [r4, 0x14]
	adds r0, 0x20
	strb r6, [r0]
_0808215C:
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r1, r10
	cmp r1, 0
	bge _080820FC
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082178: .4byte gUnknown_81071E0
	thumb_func_end sub_80820D8

	thumb_func_start sub_808217C
sub_808217C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08082250
	bl sub_8083018
	adds r0, r5, 0
	bl sub_80831A0
	ldr r4, _08082254
	ldr r1, [r4]
	ldr r2, _08082258
	adds r1, r2
	str r0, [r1]
	adds r0, r5, 0
	bl sub_80831A0
	ldr r1, [r4]
	ldr r2, _0808225C
	adds r1, r2
	str r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082260
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082264
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082268
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _0808226C
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082270
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082274
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082278
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _0808227C
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	ldr r1, [r4]
	movs r2, 0xE0
	lsls r2, 6
	adds r1, r2
	strh r0, [r1]
	movs r4, 0
_08082226:
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_8082280
	adds r4, 0x1
	cmp r4, 0x3
	ble _08082226
	movs r4, 0
_08082238:
	adds r0, r5, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_8082280
	adds r4, 0x1
	cmp r4, 0xF
	ble _08082238
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082250: .4byte gUnknown_81071E0
_08082254: .4byte gDungeonGlobalData
_08082258: .4byte 0x000037f0
_0808225C: .4byte 0x000037f4
_08082260: .4byte 0x000037f8
_08082264: .4byte 0x000037f9
_08082268: .4byte 0x000037fa
_0808226C: .4byte 0x000037fb
_08082270: .4byte 0x000037fc
_08082274: .4byte 0x000037fd
_08082278: .4byte 0x000037fe
_0808227C: .4byte 0x000037ff
	thumb_func_end sub_808217C

	thumb_func_start sub_8082280
sub_8082280:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0808266C
	add sp, r4
	adds r5, r0, 0
	str r2, [sp, 0x210]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x20C]
	movs r2, 0x82
	lsls r2, 2
	mov r0, sp
	movs r1, 0
	bl memset
	adds r0, r5, 0
	bl sub_8083188
	adds r0, r5, 0
	bl sub_8083188
	adds r0, r5, 0
	bl sub_8083188
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x214]
	add r4, sp, 0x208
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	adds r0, r5, 0
	bl sub_80831DC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x218]
	adds r0, r5, 0
	bl sub_8083158
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x21C]
	ldr r1, _08082670
	movs r0, 0
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8082BC0
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r5, 0
	bl sub_8082BC0
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r5, 0
	bl sub_80831DC
	mov r1, sp
	strb r0, [r1, 0x6]
	adds r0, r5, 0
	bl sub_80831DC
	mov r1, sp
	strb r0, [r1, 0x7]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x8]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x9]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0xA]
	add r1, sp, 0x40
	adds r0, r5, 0
	bl sub_8082F64
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0xC]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0xE]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x10]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x12]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x14]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x15]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x16]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x17]
	adds r0, r5, 0
	bl sub_80831A0
	str r0, [sp, 0x18]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x1C]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x1E]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x20]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x22]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x24]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x26]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x2C]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x30]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x34]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x38]
	add r1, sp, 0x44
	adds r0, r5, 0
	bl sub_8082CBC
	adds r0, r5, 0
	bl sub_8082BFC
	add r1, sp, 0x5C
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082BFC
	mov r1, sp
	adds r1, 0x5D
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C18
	mov r1, sp
	adds r1, 0x5E
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C18
	mov r1, sp
	adds r1, 0x5F
	strb r0, [r1]
	add r1, sp, 0x60
	adds r0, r5, 0
	bl sub_80820A8
	adds r0, r5, 0
	bl sub_8082BE0
	add r1, sp, 0x64
	strb r0, [r1]
	add r7, sp, 0x78
	add r0, sp, 0x8C
	mov r8, r0
	add r1, sp, 0x90
	mov r9, r1
	add r2, sp, 0x94
	mov r10, r2
	mov r3, sp
	adds r3, 0x3C
	str r3, [sp, 0x270]
	mov r0, sp
	adds r0, 0x98
	str r0, [sp, 0x274]
	mov r1, sp
	adds r1, 0x9C
	str r1, [sp, 0x278]
	mov r2, sp
	adds r2, 0xA0
	str r2, [sp, 0x27C]
	adds r3, 0x6C
	str r3, [sp, 0x284]
	adds r0, 0x14
	str r0, [sp, 0x288]
	adds r1, 0x14
	str r1, [sp, 0x28C]
	adds r2, 0x1C
	str r2, [sp, 0x290]
	adds r3, 0x18
	str r3, [sp, 0x294]
	adds r0, 0x18
	str r0, [sp, 0x298]
	adds r1, 0x18
	str r1, [sp, 0x29C]
	adds r2, 0x14
	str r2, [sp, 0x220]
	adds r3, 0x1C
	str r3, [sp, 0x224]
	adds r0, 0x1C
	str r0, [sp, 0x228]
	adds r1, 0x1C
	str r1, [sp, 0x22C]
	adds r2, 0x18
	str r2, [sp, 0x230]
	adds r3, 0x10
	str r3, [sp, 0x234]
	adds r0, 0x10
	str r0, [sp, 0x238]
	adds r1, 0xD
	str r1, [sp, 0x23C]
	adds r2, 0xA
	str r2, [sp, 0x240]
	adds r3, 0x7
	str r3, [sp, 0x244]
	adds r0, 0x4
	str r0, [sp, 0x248]
	adds r1, 0xA
	str r1, [sp, 0x25C]
	adds r2, 0x3
	str r2, [sp, 0x24C]
	adds r3, 0x3
	str r3, [sp, 0x250]
	adds r0, 0x3
	str r0, [sp, 0x254]
	subs r1, 0x1
	str r1, [sp, 0x258]
	adds r2, 0x7
	str r2, [sp, 0x260]
	adds r3, 0x7
	str r3, [sp, 0x264]
	adds r0, 0x7
	str r0, [sp, 0x268]
	adds r1, 0x5
	str r1, [sp, 0x26C]
	subs r2, 0x58
	str r2, [sp, 0x280]
	add r4, sp, 0x68
	movs r6, 0x3
_080824DC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	adds r4, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _080824DC
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_8082CE4
	adds r0, r5, 0
	mov r1, r8
	bl sub_8082D28
	adds r0, r5, 0
	mov r1, r9
	bl sub_8082D28
	adds r0, r5, 0
	bl sub_8082C84
	movs r4, 0
	mov r3, r10
	strb r0, [r3]
	adds r0, r5, 0
	ldr r1, [sp, 0x270]
	bl sub_8082F80
	adds r0, r5, 0
	bl sub_80831A0
	ldr r1, [sp, 0x274]
	str r0, [r1]
	adds r0, r5, 0
	bl sub_80831A0
	ldr r2, [sp, 0x278]
	str r0, [r2]
	adds r0, r5, 0
	bl sub_80831A0
	ldr r3, [sp, 0x27C]
	str r0, [r3]
	adds r0, r5, 0
	ldr r1, [sp, 0x284]
	bl sub_8082D34
	adds r0, r5, 0
	ldr r1, [sp, 0x288]
	bl sub_8082D50
	adds r0, r5, 0
	ldr r1, [sp, 0x28C]
	bl sub_8082D7C
	adds r0, r5, 0
	ldr r1, [sp, 0x290]
	bl sub_8082DA8
	adds r0, r5, 0
	ldr r1, [sp, 0x294]
	bl sub_8082DC4
	adds r0, r5, 0
	ldr r1, [sp, 0x298]
	bl sub_8082DE8
	adds r0, r5, 0
	ldr r1, [sp, 0x29C]
	bl sub_8082E04
	adds r0, r5, 0
	ldr r1, [sp, 0x220]
	bl sub_8082E38
	adds r0, r5, 0
	ldr r1, [sp, 0x224]
	bl sub_8082E6C
	adds r0, r5, 0
	ldr r1, [sp, 0x228]
	bl sub_8082E88
	adds r0, r5, 0
	ldr r1, [sp, 0x22C]
	bl sub_8082E94
	adds r0, r5, 0
	ldr r1, [sp, 0x230]
	bl sub_8082EB0
	adds r0, r5, 0
	ldr r1, [sp, 0x234]
	bl sub_8082ECC
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [sp, 0x238]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x23C]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r3, [sp, 0x240]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [sp, 0x244]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x248]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_8083188
	ldr r3, [sp, 0x25C]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [sp, 0x24C]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x250]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r3, [sp, 0x254]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [sp, 0x258]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x260]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_8083188
	ldr r3, [sp, 0x264]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [sp, 0x268]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C34
	ldr r2, [sp, 0x26C]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_8082C50
	add r1, sp, 0x100
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C6C
	add r1, sp, 0x104
	str r0, [r1]
	add r1, sp, 0x108
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_8083288
	ldr r1, _08082674
	add r1, sp
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_8083288
	adds r0, r5, 0
	bl sub_8083188
	movs r1, 0x89
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	b _08082678
	.align 2, 0
_0808266C: .4byte 0xfffffd60
_08082670: .4byte gLeaderPokemon
_08082674: .4byte 0x0000010d
_08082678:
	ldr r1, _08082818
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	add r1, sp, 0x114
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	add r1, sp, 0x118
	adds r0, r5, 0
	bl sub_8082F1C
	add r1, sp, 0x13C
	adds r0, r5, 0
	bl sub_8082F48
	add r1, sp, 0x140
	adds r0, r5, 0
	bl sub_8082F48
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x144
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _0808281C
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082820
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xA3
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x148
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082824
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xA5
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082828
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x14C
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	movs r1, 0xA7
	lsls r1, 1
	add r1, sp
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	add r1, sp, 0x150
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xA9
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _0808282C
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x154
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082830
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xAB
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	add r1, sp, 0x164
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _08082834
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	movs r1, 0xB3
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _08082838
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	add r1, sp, 0x168
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _0808283C
	add r1, sp
	strb r0, [r1]
	add r1, sp, 0x16C
	adds r0, r5, 0
	bl sub_80831F8
	adds r0, r5, 0
	bl sub_80831C8
	add r1, sp, 0x174
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	add r1, sp, 0x178
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	add r1, sp, 0x1F8
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	movs r1, 0xFD
	lsls r1, 1
	add r1, sp
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_80831A0
	add r1, sp, 0x1FC
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8082CA0
	ldr r3, [sp, 0x280]
	strb r0, [r3]
	ldr r0, _08082840
	str r4, [r0]
	ldr r0, [sp, 0x214]
	cmp r0, 0
	beq _080828BE
	ldr r1, [sp, 0x20C]
	cmp r1, 0
	beq _08082844
	mov r0, sp
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	mov r1, sp
	movs r3, 0x4
	ldrsh r1, [r1, r3]
	ldr r2, [sp, 0x210]
	bl sub_80828E0
	b _08082856
	.align 2, 0
_08082818: .4byte 0x00000113
_0808281C: .4byte 0x00000145
_08082820: .4byte 0x00000147
_08082824: .4byte 0x00000149
_08082828: .4byte 0x0000014b
_0808282C: .4byte 0x00000153
_08082830: .4byte 0x00000155
_08082834: .4byte 0x00000165
_08082838: .4byte 0x00000167
_0808283C: .4byte 0x00000169
_08082840: .4byte gLeaderPokemon
_08082844:
	mov r0, sp
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, 0x4
	ldrsh r1, [r1, r2]
	ldr r2, [sp, 0x210]
	bl sub_8082A08
_08082856:
	adds r7, r0, 0
	cmp r7, 0
	beq _080828BE
	ldr r6, [r7, 0x70]
	movs r5, 0x82
	lsls r5, 2
	mov r3, sp
	adds r4, r3, r5
	movs r1, 0
	ldrsh r0, [r4, r1]
	ldr r3, _080828D4
	add r3, sp
	movs r2, 0
	ldrsh r1, [r3, r2]
	bl GetMapEntity
	ldr r1, [r4]
	str r1, [r7, 0x8]
	ldr r1, [r4]
	str r1, [r7, 0x4]
	str r7, [r0, 0x10]
	adds r0, r7, 0
	adds r0, 0x20
	movs r4, 0
	add r1, sp, 0x218
	ldrb r1, [r1]
	strb r1, [r0]
	add r2, sp, 0x21C
	ldrh r2, [r2]
	strh r2, [r7, 0x26]
	adds r0, r6, 0
	mov r1, sp
	adds r2, r5, 0
	bl memcpy
	ldr r0, _080828D8
	str r4, [r0]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _080828B0
	ldr r0, _080828DC
	ldrh r1, [r7, 0x4]
	strh r1, [r0]
	ldrh r1, [r7, 0x6]
	strh r1, [r0, 0x2]
_080828B0:
	adds r0, r7, 0
	bl LoadIQSkills
	adds r0, r7, 0
	movs r1, 0
	bl sub_804535C
_080828BE:
	movs r3, 0xA8
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080828D4: .4byte 0x0000020a
_080828D8: .4byte gLeaderPokemon
_080828DC: .4byte gUnknown_203B410
	thumb_func_end sub_8082280

	thumb_func_start sub_80828E0
sub_80828E0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r2, 0
	lsls r0, 16
	asrs r0, 16
	mov r10, r0
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	movs r4, 0x1
	negs r4, r4
	mov r0, r8
	bl GetPokemonSize
	lsls r0, 24
	lsrs r6, r0, 24
	movs r3, 0
	movs r0, 0x6
	subs r7, r0, r6
	ldr r0, _08082914
	mov r9, r0
	b _0808291A
	.align 2, 0
_08082914: .4byte gUnknown_202EE70
_08082918:
	adds r3, 0x1
_0808291A:
	cmp r3, r7
	bgt _0808293E
	movs r2, 0
	cmp r2, r6
	bge _08082938
	mov r0, r9
	adds r1, r3, r0
	b _08082932
_0808292A:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r6
	bge _08082938
_08082932:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808292A
_08082938:
	cmp r2, r6
	bne _08082918
	adds r4, r3, 0
_0808293E:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0808294A
	movs r0, 0
	b _080829E6
_0808294A:
	ldr r2, _080829F4
	ldr r0, [r2]
	lsls r1, r5, 2
	ldr r3, _080829F8
	adds r0, r3
	adds r0, r1
	ldr r7, [r0]
	movs r0, 0x1
	mov r9, r0
	str r0, [r7]
	adds r0, r7, 0
	adds r0, 0x24
	strb r5, [r0]
	lsls r0, r5, 6
	adds r0, r5
	lsls r0, 3
	ldr r1, _080829FC
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r7, 0x70]
	movs r5, 0
	mov r3, r10
	strh r3, [r1, 0x2]
	ldr r0, [r7, 0x70]
	mov r1, r8
	strh r1, [r0, 0x4]
	ldr r0, [r7, 0x70]
	strb r5, [r0, 0x6]
	mov r0, r8
	bl sub_80687D0
	str r0, [r7, 0x64]
	lsls r0, r4, 4
	adds r0, 0x40
	adds r1, r7, 0
	adds r1, 0x68
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6C
	strb r5, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6D
	mov r3, r9
	strb r3, [r0]
	adds r0, 0x2
	strb r3, [r0]
	movs r0, 0
	str r0, [r7, 0x1C]
	bl sub_8045ACC
	ldr r0, [r7, 0x70]
	ldr r1, _08082A00
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r7, 0x70]
	movs r3, 0xB4
	lsls r3, 1
	adds r0, r3
	strb r6, [r0]
	cmp r6, 0
	beq _080829E4
	ldr r3, _08082A04
	movs r2, 0x1
	adds r1, r6, 0
_080829D8:
	adds r0, r4, r3
	strb r2, [r0]
	adds r4, 0x1
	subs r1, 0x1
	cmp r1, 0
	bne _080829D8
_080829E4:
	adds r0, r7, 0
_080829E6:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080829F4: .4byte gDungeonGlobalData
_080829F8: .4byte 0x0001357c
_080829FC: .4byte 0x0000069c
_08082A00: .4byte 0x00000167
_08082A04: .4byte gUnknown_202EE70
	thumb_func_end sub_80828E0

	thumb_func_start sub_8082A08
sub_8082A08:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r2, 0
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	mov r0, r9
	bl GetPokemonSize
	lsls r0, 24
	lsrs r6, r0, 24
	movs r3, 0
	movs r0, 0x10
	subs r4, r0, r6
	ldr r7, _08082A3C
	b _08082A42
	.align 2, 0
_08082A3C: .4byte gUnknown_202EE76
_08082A40:
	adds r3, 0x1
_08082A42:
	cmp r3, r4
	bgt _08082A64
	movs r2, 0
	cmp r2, r6
	bge _08082A5E
	adds r1, r3, r7
	b _08082A58
_08082A50:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r6
	bge _08082A5E
_08082A58:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08082A50
_08082A5E:
	cmp r2, r6
	bne _08082A40
	mov r8, r3
_08082A64:
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _08082A70
	movs r0, 0
	b _08082B1C
_08082A70:
	ldr r2, _08082B2C
	ldr r0, [r2]
	lsls r1, r5, 2
	ldr r3, _08082B30
	adds r0, r3
	adds r0, r1
	ldr r7, [r0]
	movs r4, 0x1
	str r4, [r7]
	adds r0, r7, 0
	adds r0, 0x24
	movs r1, 0
	mov r10, r1
	strb r5, [r0]
	subs r0, 0x2
	mov r3, r10
	strb r3, [r0]
	lsls r0, r5, 6
	adds r0, r5
	lsls r0, 3
	ldr r1, _08082B34
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r7, 0x70]
	movs r5, 0
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r1, 0x2]
	ldr r0, [r7, 0x70]
	mov r3, r9
	strh r3, [r0, 0x4]
	ldr r0, [r7, 0x70]
	strb r4, [r0, 0x6]
	mov r0, r9
	bl sub_80687D0
	str r0, [r7, 0x64]
	mov r1, r8
	lsls r0, r1, 4
	adds r0, 0xA0
	adds r1, r7, 0
	adds r1, 0x68
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6C
	strb r5, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6D
	strb r4, [r0]
	adds r0, 0x2
	strb r4, [r0]
	mov r2, r10
	str r2, [r7, 0x1C]
	ldr r0, [r7, 0x70]
	ldr r3, _08082B38
	adds r0, r3
	mov r4, r8
	strb r4, [r0]
	ldr r0, [r7, 0x70]
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r1
	strb r6, [r0]
	cmp r6, 0
	beq _08082B16
	ldr r3, _08082B3C
	movs r2, 0x1
	adds r1, r6, 0
_08082B06:
	mov r4, r8
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, 0x1
	add r8, r0
	subs r1, 0x1
	cmp r1, 0
	bne _08082B06
_08082B16:
	bl sub_8045ACC
	adds r0, r7, 0
_08082B1C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08082B2C: .4byte gDungeonGlobalData
_08082B30: .4byte 0x0001358c
_08082B34: .4byte 0x00000ebc
_08082B38: .4byte 0x00000167
_08082B3C: .4byte gUnknown_202EE76
	thumb_func_end sub_8082A08

	thumb_func_start sub_8082B40
sub_8082B40:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r6, 0
_08082B46:
	ldr r0, _08082BB8
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08082BBC
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08082BA8
	ldr r4, [r5, 0x70]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl sub_80687D0
	str r0, [r5, 0x64]
	adds r0, r5, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_806CCB4
	ldr r0, [r5, 0x4]
	str r0, [sp]
	adds r0, r4, 0
	adds r0, 0x98
	ldr r0, [r0]
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	mov r2, sp
	movs r3, 0x3
	bl AddPokemonDungeonSprite
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl GetMapEntity
	ldrb r1, [r0, 0x9]
	adds r0, r5, 0
	adds r0, 0x25
	strb r1, [r0]
_08082BA8:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08082B46
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082BB8: .4byte gDungeonGlobalData
_08082BBC: .4byte 0x000135cc
	thumb_func_end sub_8082B40

	thumb_func_start sub_8082BC0
sub_8082BC0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FE0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082BC0

	thumb_func_start sub_8082BE0
sub_8082BE0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082BE0

	thumb_func_start sub_8082BFC
sub_8082BFC:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082BFC

	thumb_func_start sub_8082C18
sub_8082C18:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C18

	thumb_func_start sub_8082C34
sub_8082C34:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C34

	thumb_func_start sub_8082C50
sub_8082C50:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C50

	thumb_func_start sub_8082C6C
sub_8082C6C:
	push {lr}
	sub sp, 0x4
	movs r1, 0
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C6C

	thumb_func_start sub_8082C84
sub_8082C84:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C84

	thumb_func_start sub_8082CA0
sub_8082CA0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082CA0

	thumb_func_start sub_8082CBC
sub_8082CBC:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strh r0, [r4]
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	movs r0, 0x7
	strb r0, [r4, 0x3]
	adds r4, 0x14
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082CBC

	thumb_func_start sub_8082CE4
sub_8082CE4:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r5, 0
	bl sub_80831DC
	movs r6, 0
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	bl sub_80831DC
	strb r0, [r4, 0x2]
	adds r0, r5, 0
	bl sub_80831DC
	strb r0, [r4, 0x3]
	adds r0, r5, 0
	bl sub_8083158
	strh r0, [r4, 0x4]
	str r6, [r4, 0x8]
	str r6, [r4, 0xC]
	adds r4, 0x10
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8082CE4

	thumb_func_start sub_8082D28
sub_8082D28:
	push {lr}
	movs r2, 0x3
	bl sub_8082FE0
	pop {r0}
	bx r0
	thumb_func_end sub_8082D28

	thumb_func_start sub_8082D34
sub_8082D34:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082D34

	thumb_func_start sub_8082D50
sub_8082D50:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x2]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x3]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082D50

	thumb_func_start sub_8082D7C
sub_8082D7C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x8]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x9]
	adds r0, r4, 0
	bl sub_80831A0
	str r0, [r5, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082D7C

	thumb_func_start sub_8082DA8
sub_8082DA8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082DA8

	thumb_func_start sub_8082DC4
sub_8082DC4:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082DC4

	thumb_func_start sub_8082DE8
sub_8082DE8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082DE8

	thumb_func_start sub_8082E04
sub_8082E04:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_80831DC
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	bl sub_80831DC
	strb r0, [r5, 0x2]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x3]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E04

	thumb_func_start sub_8082E38
sub_8082E38:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_80831A0
	str r0, [r5, 0x4]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x8]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x9]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E38

	thumb_func_start sub_8082E6C
sub_8082E6C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E6C

	thumb_func_start sub_8082E88
sub_8082E88:
	push {lr}
	movs r2, 0x1
	bl sub_8082FE0
	pop {r0}
	bx r0
	thumb_func_end sub_8082E88

	thumb_func_start sub_8082E94
sub_8082E94:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E94

	thumb_func_start sub_8082EB0
sub_8082EB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082EB0

	thumb_func_start sub_8082ECC
sub_8082ECC:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082ECC

	thumb_func_start sub_8082EE8
sub_8082EE8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083188
	strb r0, [r5]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x2
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x4]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082EE8

	thumb_func_start sub_8082F1C
sub_8082F1C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_08082F26:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8082EE8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08082F26
	adds r0, r6, 0
	bl sub_8083188
	adds r1, r7, 0
	adds r1, 0x20
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F1C

	thumb_func_start sub_8082F48
sub_8082F48:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083170
	strh r0, [r5]
	adds r0, r4, 0
	bl sub_8083170
	strh r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F48

	thumb_func_start sub_8082F64
sub_8082F64:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083188
	strb r0, [r5]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F64

	thumb_func_start sub_8082F80
sub_8082F80:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083170
	strh r0, [r5]
	adds r0, r4, 0
	bl sub_8082BFC
	strb r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F80

	thumb_func_start sub_8082F9C
sub_8082F9C:
	str r1, [r0]
	movs r3, 0
	str r3, [r0, 0x8]
	adds r1, r2
	str r1, [r0, 0x4]
	bx lr
	thumb_func_end sub_8082F9C

	thumb_func_start sub_8082FA8
sub_8082FA8:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0
	beq _08082FCC
_08082FB2:
	ldr r1, [r3]
	ldrb r0, [r4]
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x1
	str r0, [r3]
	adds r4, 0x1
	subs r2, 0x1
	ldr r0, [r3, 0x8]
	adds r0, 0x1
	str r0, [r3, 0x8]
	cmp r2, 0
	bne _08082FB2
_08082FCC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8082FA8

	thumb_func_start sub_8082FD4
sub_8082FD4:
	str r1, [r0]
	movs r3, 0
	str r3, [r0, 0x8]
	adds r1, r2
	str r1, [r0, 0x4]
	bx lr
	thumb_func_end sub_8082FD4

	thumb_func_start sub_8082FE0
sub_8082FE0:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0
	beq _08083002
_08082FEA:
	ldr r1, [r3]
	ldrb r0, [r1]
	strb r0, [r4]
	adds r1, 0x1
	str r1, [r3]
	adds r4, 0x1
	subs r2, 0x1
	ldr r0, [r3, 0x8]
	adds r0, 0x1
	str r0, [r3, 0x8]
	cmp r2, 0
	bne _08082FEA
_08083002:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8082FE0

	thumb_func_start nullsub_98
nullsub_98:
	bx lr
	thumb_func_end nullsub_98

	thumb_func_start sub_808300C
sub_808300C:
	push {lr}
	movs r2, 0x8
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_808300C

	thumb_func_start sub_8083018
sub_8083018:
	push {lr}
	sub sp, 0xC
	mov r1, sp
	movs r2, 0x8
	bl sub_8082FE0
	mov r1, sp
	movs r0, 0
	strb r0, [r1, 0x8]
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_8083018

	thumb_func_start sub_8083030
sub_8083030:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083030

	thumb_func_start sub_8083048
sub_8083048:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083048

	thumb_func_start sub_8083060
sub_8083060:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083060

	thumb_func_start sub_8083078
sub_8083078:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083078

	thumb_func_start sub_808308C
sub_808308C:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808308C

	thumb_func_start sub_80830A0
sub_80830A0:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80830A0

	thumb_func_start sub_80830B4
sub_80830B4:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	lsls r1, 24
	movs r2, 0
	cmp r1, 0
	beq _080830C4
	movs r2, 0xFF
_080830C4:
	mov r0, sp
	strb r2, [r0]
	adds r0, r3, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80830B4

	thumb_func_start sub_80830D8
sub_80830D8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80830D8

	thumb_func_start sub_80830F8
sub_80830F8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0xC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80830F8

	thumb_func_start sub_808312C
sub_808312C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808312C

	thumb_func_start sub_808314C
sub_808314C:
	push {lr}
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_808314C

	thumb_func_start sub_8083158
sub_8083158:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FE0
	mov r0, sp
	ldrh r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8083158

	thumb_func_start sub_8083170
sub_8083170:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FE0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8083170

	thumb_func_start sub_8083188
sub_8083188:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8083188

	thumb_func_start sub_80831A0
sub_80831A0:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831A0

	thumb_func_start sub_80831B4
sub_80831B4:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831B4

	thumb_func_start sub_80831C8
sub_80831C8:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831C8

	thumb_func_start sub_80831DC
sub_80831DC:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831DC

	thumb_func_start sub_80831F8
sub_80831F8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80831F8

	thumb_func_start sub_8083220
sub_8083220:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r4, 0xC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8083220

	thumb_func_start sub_8083260
sub_8083260:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8083260

	thumb_func_start sub_8083288
sub_8083288:
	push {lr}
	bl sub_8082FE0
	pop {r0}
	bx r0
	thumb_func_end sub_8083288

	.align 2, 0