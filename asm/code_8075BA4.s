	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8075CFC
sub_8075CFC:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	lsls r3, 24
	lsrs r5, r3, 24
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08075DAA
	ldr r0, _08075D4C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r7, 0
	beq _08075D34
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _08075DAA
_08075D34:
	adds r0, r4, 0
	movs r1, 0x11
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08075D54
	cmp r5, 0
	beq _08075DAA
	ldr r0, _08075D50
	b _08075DA0
	.align 2, 0
_08075D4C: .4byte gAvailablePokemonNames
_08075D50: .4byte gUnknown_80FCD54
_08075D54:
	adds r0, r4, 0
	movs r1, 0x36
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08075D70
	cmp r5, 0
	beq _08075DAA
	ldr r0, _08075D6C
	b _08075DA0
	.align 2, 0
_08075D6C: .4byte gUnknown_80FCD58
_08075D70:
	adds r0, r4, 0
	movs r1, 0x49
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08075D8C
	cmp r5, 0
	beq _08075DAA
	ldr r0, _08075D88
	b _08075DA0
	.align 2, 0
_08075D88: .4byte gUnknown_80FCD88
_08075D8C:
	adds r0, r4, 0
	movs r1, 0x15
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08075DB4
	cmp r5, 0
	beq _08075DAA
	ldr r0, _08075DB0
_08075DA0:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08075DAA:
	movs r0, 0x1
	b _08075DB6
	.align 2, 0
_08075DB0: .4byte gUnknown_80FD548
_08075DB4:
	movs r0, 0
_08075DB6:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8075CFC

	thumb_func_start sub_8075DBC
sub_8075DBC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r5, r1, 0
	mov r8, r2
	movs r0, 0
	mov r9, r0
	adds r0, r7, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8075CFC
	lsls r0, 24
	cmp r0, 0
	bne _08075E62
	ldr r6, [r5, 0x70]
	adds r4, r6, 0
	adds r4, 0xA8
	ldrb r0, [r4]
	cmp r0, 0x2
	beq _08075E50
	adds r0, r5, 0
	bl sub_8041EC8
	ldrb r0, [r4]
	cmp r0, 0x3
	beq _08075E1A
	adds r4, 0x1
	mov r0, r8
	strb r0, [r4]
	adds r0, r5, 0
	movs r1, 0x2F
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08075E1E
	ldrb r0, [r4]
	lsrs r0, 1
	strb r0, [r4]
	cmp r0, 0
	bne _08075E1E
	movs r0, 0x1
	strb r0, [r4]
	b _08075E1E
_08075E1A:
	movs r0, 0x1
	mov r9, r0
_08075E1E:
	adds r1, r6, 0
	adds r1, 0xA8
	movs r0, 0x3
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE68
	mov r0, r9
	cmp r0, 0
	beq _08075E3C
	ldr r0, _08075E38
	b _08075E3E
	.align 2, 0
_08075E38: .4byte gUnknown_80FB3CC
_08075E3C:
	ldr r0, _08075E4C
_08075E3E:
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _08075E5C
	.align 2, 0
_08075E4C: .4byte gUnknown_80FB3A4
_08075E50:
	ldr r0, _08075E70
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_08075E5C:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08075E62:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075E70: .4byte gUnknown_80FB3D0
	thumb_func_end sub_8075DBC

	thumb_func_start sub_8075E74
sub_8075E74:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r5, r1, 0
	mov r8, r2
	movs r0, 0
	mov r9, r0
	adds r0, r7, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8075CFC
	lsls r0, 24
	cmp r0, 0
	bne _08075F22
	ldr r6, [r5, 0x70]
	adds r4, r6, 0
	adds r4, 0xA8
	ldrb r0, [r4]
	cmp r0, 0x2
	beq _08075F10
	adds r0, r5, 0
	bl sub_8041ED8
	ldrb r0, [r4]
	cmp r0, 0
	beq _08075EB2
	cmp r0, 0x4
	bne _08075ED8
_08075EB2:
	adds r4, r6, 0
	adds r4, 0xA9
	mov r0, r8
	strb r0, [r4]
	adds r0, r5, 0
	movs r1, 0x2F
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08075EDC
	ldrb r0, [r4]
	lsrs r0, 1
	strb r0, [r4]
	cmp r0, 0
	bne _08075EDC
	movs r0, 0x1
	strb r0, [r4]
	b _08075EDC
_08075ED8:
	movs r0, 0x1
	mov r9, r0
_08075EDC:
	adds r1, r6, 0
	adds r1, 0xA8
	movs r0, 0x5
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE68
	mov r0, r9
	cmp r0, 0
	beq _08075EFC
	ldr r0, _08075EF8
	b _08075EFE
	.align 2, 0
_08075EF8: .4byte gUnknown_80FB360
_08075EFC:
	ldr r0, _08075F0C
_08075EFE:
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _08075F1C
	.align 2, 0
_08075F0C: .4byte gUnknown_80FB31C
_08075F10:
	ldr r0, _08075F30
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_08075F1C:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08075F22:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075F30: .4byte gUnknown_80FB388
	thumb_func_end sub_8075E74

	thumb_func_start sub_8075F34
sub_8075F34:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8075CFC
	lsls r0, 24
	cmp r0, 0
	bne _08075FC2
	ldr r2, [r4, 0x70]
	adds r1, r2, 0
	adds r1, 0xA8
	ldrb r0, [r1]
	cmp r0, 0
	bne _08075F78
	movs r0, 0x4
	strb r0, [r1]
	adds r0, r2, 0
	adds r0, 0xA9
	strb r6, [r0]
	adds r0, r4, 0
	bl nullsub_91
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_806CE68
	ldr r0, _08075F74
	b _08075F9E
	.align 2, 0
_08075F74: .4byte gUnknown_80FB3E0
_08075F78:
	cmp r0, 0x1
	beq _08075F84
	cmp r0, 0x3
	beq _08075F84
	cmp r0, 0x5
	bne _08075F8C
_08075F84:
	ldr r0, _08075F88
	b _08075F9E
	.align 2, 0
_08075F88: .4byte gUnknown_80FB418
_08075F8C:
	cmp r0, 0x2
	bne _08075F98
	ldr r0, _08075F94
	b _08075F9E
	.align 2, 0
_08075F94: .4byte gUnknown_80FB3F8
_08075F98:
	cmp r0, 0x4
	bne _08075FB0
	ldr r0, _08075FAC
_08075F9E:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08075FBC
	.align 2, 0
_08075FAC: .4byte gUnknown_80FB414
_08075FB0:
	ldr r0, _08075FC8
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08075FBC:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08075FC2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08075FC8: .4byte gUnknown_80FB3E0
	thumb_func_end sub_8075F34

	thumb_func_start sub_8075FCC
sub_8075FCC:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	movs r7, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076086
	ldr r5, [r4, 0x70]
	adds r0, r5, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08075FF4
	cmp r0, 0x5
	beq _08075FF4
	cmp r0, 0x3
	bne _08075FF6
_08075FF4:
	movs r7, 0x1
_08075FF6:
	ldr r0, _08076060
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xA8
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08076074
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, _08076064
	adds r0, r4, 0
	movs r2, 0
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xA9
	strb r0, [r1]
	ldr r0, _08076068
	adds r1, r5, r0
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, 0x65
	adds r1, r5, r0
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041EE8
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_806CE68
	cmp r7, 0
	beq _08076050
	ldr r0, _0807606C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076050:
	ldr r0, _08076070
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08076080
	.align 2, 0
_08076060: .4byte gAvailablePokemonNames
_08076064: .4byte gUnknown_80F4E7C
_08076068: .4byte 0x00000165
_0807606C: .4byte gUnknown_80FB41C
_08076070: .4byte gUnknown_80FB458
_08076074:
	ldr r0, _0807608C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076080:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08076086:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807608C: .4byte gUnknown_80FB43C
	thumb_func_end sub_8075FCC

	thumb_func_start sub_8076090
sub_8076090:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x1C]
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807613A
	ldr r5, [r4, 0x70]
	mov r0, r8
	cmp r0, 0
	beq _080760D0
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, r9
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _0807613A
_080760D0:
	ldr r0, _08076100
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	adds r1, r5, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08076110
	movs r0, 0x3
	strb r0, [r1]
	adds r1, r7, 0x1
	adds r0, r5, 0
	adds r0, 0xBD
	strb r1, [r0]
	adds r0, r4, 0
	bl nullsub_72
	cmp r7, 0x1
	bne _08076108
	ldr r0, _08076104
	b _08076116
	.align 2, 0
_08076100: .4byte gAvailablePokemonNames
_08076104: .4byte gUnknown_80FB480
_08076108:
	ldr r0, _0807610C
	b _08076116
	.align 2, 0
_0807610C: .4byte gUnknown_80FB4D4
_08076110:
	cmp r7, 0x1
	bne _08076128
	ldr r0, _08076124
_08076116:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08076134
	.align 2, 0
_08076124: .4byte gUnknown_80FB4B0
_08076128:
	ldr r0, _08076148
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076134:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807613A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076148: .4byte gUnknown_80FB4F0
	thumb_func_end sub_8076090

	thumb_func_start sub_807614C
sub_807614C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076206
	ldr r5, [r4, 0x70]
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _08076206
	adds r0, r4, 0
	movs r1, 0x29
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080761A8
	ldr r0, _080761A0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r7, 0
	beq _08076206
	ldr r0, _080761A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08076206
	.align 2, 0
_080761A0: .4byte gAvailablePokemonNames
_080761A4: .4byte gUnknown_80FCC4C
_080761A8:
	ldr r0, _080761E8
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	adds r1, r5, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x7
	beq _080761F4
	movs r0, 0x7
	strb r0, [r1]
	ldr r1, _080761EC
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xBD
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041EF8
	ldr r0, _080761F0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08076200
	.align 2, 0
_080761E8: .4byte gAvailablePokemonNames
_080761EC: .4byte gUnknown_80F4F00
_080761F0: .4byte gUnknown_80FB50C
_080761F4:
	ldr r0, _0807620C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076200:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08076206:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807620C: .4byte gUnknown_80FB52C
	thumb_func_end sub_807614C

	thumb_func_start sub_8076210
sub_8076210:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08076238
	b _080763DA
_08076238:
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r10
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	beq _0807624A
	b _080763DA
_0807624A:
	ldr r0, [r5, 0x70]
	mov r8, r0
	ldr r0, _08076274
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	adds r0, r5, 0
	movs r1, 0x42
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807627C
	mov r1, r10
	cmp r1, 0
	bne _0807626E
	b _080763DA
_0807626E:
	ldr r0, _08076278
	b _080762CC
	.align 2, 0
_08076274: .4byte gAvailablePokemonNames
_08076278: .4byte gUnknown_80FCE5C
_0807627C:
	adds r0, r5, 0
	movs r1, 0x2
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _0807629C
	mov r2, r10
	cmp r2, 0
	bne _08076292
	b _080763DA
_08076292:
	ldr r0, _08076298
	b _080762CC
	.align 2, 0
_08076298: .4byte gUnknown_80FCE84
_0807629C:
	adds r0, r5, 0
	bl GetMapTileForDungeonEntity_2
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _080762E8
	ldr r1, _080762D8
	ldr r0, _080762DC
	ldr r0, [r0]
	ldr r3, _080762E0
	adds r0, r3
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080762E8
	mov r3, r10
	cmp r3, 0
	bne _080762CA
	b _080763DA
_080762CA:
	ldr r0, _080762E4
_080762CC:
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080763DA
	.align 2, 0
_080762D8: .4byte gDungeonWaterType
_080762DC: .4byte gDungeonGlobalData
_080762E0: .4byte 0x00003a0e
_080762E4: .4byte gUnknown_80FEBBC
_080762E8:
	movs r6, 0x1
	mov r1, r8
	adds r1, 0xAC
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08076338
	movs r4, 0
	strb r6, [r1]
	ldr r1, _08076330
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	mov r1, r8
	adds r1, 0xAD
	strb r0, [r1]
	mov r0, r8
	adds r0, 0xAE
	strb r4, [r0]
	adds r0, 0x1
	strb r4, [r0]
	movs r6, 0
	mov r0, r9
	cmp r0, 0
	beq _08076322
	adds r0, r5, 0
	bl sub_8041C34
_08076322:
	ldr r0, _08076334
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _08076344
	.align 2, 0
_08076330: .4byte gUnknown_80F4E30
_08076334: .4byte gUnknown_80FB548
_08076338:
	ldr r0, _080763E8
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_08076344:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	adds r0, r5, 0
	movs r1, 0x19
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080763DA
	cmp r6, 0
	bne _080763DA
	movs r1, 0
	mov r9, r1
	movs r6, 0
_08076362:
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldr r1, _080763EC
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTile_1
	ldr r4, [r0, 0x10]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080763D4
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080763D4
	mov r0, r9
	cmp r0, 0
	bne _080763B8
	movs r1, 0x1
	mov r9, r1
	ldr r0, _080763F0
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _080763F4
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_080763B8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807167C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080763D4
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x1
	mov r3, r10
	bl sub_8076210
_080763D4:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08076362
_080763DA:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080763E8: .4byte gUnknown_80FB564
_080763EC: .4byte gAdjacentTileOffsets
_080763F0: .4byte gAvailablePokemonNames
_080763F4: .4byte gUnknown_80FF01C
	thumb_func_end sub_8076210

	thumb_func_start sub_80763F8
sub_80763F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807641A
	b _080765C0
_0807641A:
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r10
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	beq _0807642C
	b _080765C0
_0807642C:
	ldr r0, [r5, 0x70]
	mov r8, r0
	ldr r0, _08076454
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	adds r0, r5, 0
	movs r1, 0x14
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0807645C
	mov r1, r10
	cmp r1, 0
	bne _08076450
	b _080765C0
_08076450:
	ldr r0, _08076458
	b _080764A4
	.align 2, 0
_08076454: .4byte gAvailablePokemonNames
_08076458: .4byte gUnknown_80FD524
_0807645C:
	adds r0, r5, 0
	movs r1, 0x45
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807647C
	mov r3, r10
	cmp r3, 0
	bne _08076472
	b _080765C0
_08076472:
	ldr r0, _08076478
	b _080764A4
	.align 2, 0
_08076478: .4byte gUnknown_80FCEB0
_0807647C:
	adds r0, r5, 0
	movs r1, 0x8
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _0807649A
	adds r0, r5, 0
	movs r1, 0x11
	bl HasType
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080764B4
_0807649A:
	mov r0, r10
	cmp r0, 0
	bne _080764A2
	b _080765C0
_080764A2:
	ldr r0, _080764B0
_080764A4:
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080765C0
	.align 2, 0
_080764B0: .4byte gUnknown_80FCEDC
_080764B4:
	movs r6, 0x1
	mov r1, r8
	adds r1, 0xAC
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08076520
	cmp r0, 0x2
	beq _0807650C
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, _08076504
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	mov r1, r8
	adds r1, 0xAD
	strb r0, [r1]
	mov r0, r8
	adds r0, 0xAE
	strb r4, [r0]
	adds r0, 0x1
	strb r4, [r0]
	movs r6, 0
	adds r0, r5, 0
	bl sub_8041C6C
	ldr r0, _08076508
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE94
	b _0807652C
	.align 2, 0
_08076504: .4byte gUnknown_80F4E34
_08076508: .4byte gUnknown_80FB598
_0807650C:
	ldr r0, _0807651C
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _0807652C
	.align 2, 0
_0807651C: .4byte gUnknown_80FB5D4
_08076520:
	ldr r0, _080765D0
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807652C:
	adds r0, r5, 0
	movs r1, 0x19
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080765BA
	cmp r6, 0
	bne _080765BA
	movs r1, 0
	mov r9, r1
	movs r6, 0
_08076544:
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	ldr r1, _080765D4
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTile_1
	ldr r4, [r0, 0x10]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080765B4
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080765B4
	mov r0, r9
	cmp r0, 0
	bne _0807659A
	movs r1, 0x1
	mov r9, r1
	ldr r0, _080765D8
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _080765DC
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807659A:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807167C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080765B4
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, r10
	bl sub_80763F8
_080765B4:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08076544
_080765BA:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080765C0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080765D0: .4byte gUnknown_80FB5F8
_080765D4: .4byte gAdjacentTileOffsets
_080765D8: .4byte gAvailablePokemonNames
_080765DC: .4byte gUnknown_80FF01C
	thumb_func_end sub_80763F8

	thumb_func_start sub_80765E0
sub_80765E0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08076602
	b _08076790
_08076602:
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r10
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	beq _08076614
	b _08076790
_08076614:
	ldr r0, [r5, 0x70]
	mov r8, r0
	ldr r0, _0807663C
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	adds r0, r5, 0
	movs r1, 0x14
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08076644
	mov r1, r10
	cmp r1, 0
	bne _08076638
	b _08076790
_08076638:
	ldr r0, _08076640
	b _0807668C
	.align 2, 0
_0807663C: .4byte gAvailablePokemonNames
_08076640: .4byte gUnknown_80FD524
_08076644:
	adds r0, r5, 0
	movs r1, 0x45
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08076664
	mov r3, r10
	cmp r3, 0
	bne _0807665A
	b _08076790
_0807665A:
	ldr r0, _08076660
	b _0807668C
	.align 2, 0
_08076660: .4byte gUnknown_80FCEB0
_08076664:
	adds r0, r5, 0
	movs r1, 0x8
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _08076682
	adds r0, r5, 0
	movs r1, 0x11
	bl HasType
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0807669C
_08076682:
	mov r0, r10
	cmp r0, 0
	bne _0807668A
	b _08076790
_0807668A:
	ldr r0, _08076698
_0807668C:
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _08076790
	.align 2, 0
_08076698: .4byte gUnknown_80FCEDC
_0807669C:
	movs r6, 0x1
	mov r1, r8
	adds r1, 0xAC
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _080766F0
	movs r0, 0x3
	strb r0, [r1]
	ldr r1, _080766E8
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	mov r1, r8
	adds r1, 0xAD
	strb r0, [r1]
	mov r0, r8
	adds r0, 0xAE
	strb r4, [r0]
	adds r0, 0x1
	strb r4, [r0]
	movs r6, 0
	adds r0, r5, 0
	bl sub_8041C7C
	ldr r0, _080766EC
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE94
	b _080766FC
	.align 2, 0
_080766E8: .4byte gUnknown_80F4E38
_080766EC: .4byte gUnknown_80FB5B4
_080766F0:
	ldr r0, _080767A0
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_080766FC:
	adds r0, r5, 0
	movs r1, 0x19
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807678A
	cmp r6, 0
	bne _0807678A
	movs r1, 0
	mov r9, r1
	movs r6, 0
_08076714:
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	ldr r1, _080767A4
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r5, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl GetMapTile_1
	ldr r4, [r0, 0x10]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076784
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _08076784
	mov r0, r9
	cmp r0, 0
	bne _0807676A
	movs r1, 0x1
	mov r9, r1
	ldr r0, _080767A8
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _080767AC
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807676A:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807167C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08076784
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, r10
	bl sub_80765E0
_08076784:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08076714
_0807678A:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08076790:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080767A0: .4byte gUnknown_80FB5F8
_080767A4: .4byte gAdjacentTileOffsets
_080767A8: .4byte gAvailablePokemonNames
_080767AC: .4byte gUnknown_80FF01C
	thumb_func_end sub_80765E0

	thumb_func_start sub_80767B0
sub_80767B0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	adds r6, r4, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080767CE
	b _080768C8
_080767CE:
	ldr r0, _0807680C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r7, [r5, 0x70]
	adds r0, r7, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080768C8
	mov r0, r8
	adds r1, r5, 0
	adds r2, r4, 0
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _080768C8
	adds r0, r5, 0
	movs r1, 0x41
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08076814
	cmp r4, 0
	beq _080768C8
	ldr r0, _08076810
	b _0807685C
	.align 2, 0
_0807680C: .4byte gAvailablePokemonNames
_08076810: .4byte gUnknown_80FCDE0
_08076814:
	adds r0, r5, 0
	movs r1, 0x6
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _08076830
	cmp r4, 0
	beq _080768C8
	ldr r0, _0807682C
	b _0807685C
	.align 2, 0
_0807682C: .4byte gUnknown_80FCE00
_08076830:
	adds r0, r5, 0
	bl GetMapTileForDungeonEntity_2
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _08076878
	ldr r1, _08076868
	ldr r0, _0807686C
	ldr r0, [r0]
	ldr r2, _08076870
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08076878
	cmp r6, 0
	beq _080768C8
	ldr r0, _08076874
_0807685C:
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	b _080768C8
	.align 2, 0
_08076868: .4byte gDungeonWaterType
_0807686C: .4byte gDungeonGlobalData
_08076870: .4byte 0x00003a0e
_08076874: .4byte gUnknown_80FCE34
_08076878:
	adds r6, r7, 0
	adds r6, 0xB0
	ldrb r0, [r6]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08076892
	adds r0, r7, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_08076892:
	adds r0, r5, 0
	bl sub_8041F08
	movs r4, 0
	movs r0, 0x1
	strb r0, [r6]
	ldr r1, _080768D4
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xB8
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0xB9
	strb r4, [r0]
	ldr r0, _080768D8
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080768C8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080768D4: .4byte gUnknown_80F4E2C
_080768D8: .4byte gUnknown_80FB610
	thumb_func_end sub_80767B0

	thumb_func_start sub_80768DC
sub_80768DC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r5, r1, 0
	lsls r2, 16
	asrs r2, 16
	mov r8, r2
	lsls r3, 24
	lsrs r4, r3, 24
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080769BE
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _080769BE
	ldr r6, [r5, 0x70]
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r1, [r0]
	subs r0, r1, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0807692A
	adds r0, r6, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
	b _08076948
_0807692A:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08076948
	ldr r0, _0807699C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080769A0
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_08076948:
	ldr r0, _0807699C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xB0
	ldrb r0, [r1]
	cmp r0, 0x7
	beq _080769AC
	movs r4, 0
	movs r0, 0x7
	strb r0, [r1]
	ldr r1, _080769A4
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xB8
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0xB9
	strb r4, [r0]
	subs r0, 0x5
	mov r1, r8
	str r1, [r0]
	adds r0, r5, 0
	bl nullsub_71
	ldr r0, _080769A8
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE94
	b _080769B8
	.align 2, 0
_0807699C: .4byte gAvailablePokemonNames
_080769A0: .4byte gUnknown_80FA844
_080769A4: .4byte gUnknown_80F4E58
_080769A8: .4byte gUnknown_80FB628
_080769AC:
	ldr r0, _080769C8
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_080769B8:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080769BE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080769C8: .4byte gUnknown_80FB64C
	thumb_func_end sub_80768DC

	thumb_func_start sub_80769CC
sub_80769CC:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076A9A
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _08076A9A
	ldr r6, [r5, 0x70]
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r1, [r0]
	subs r0, r1, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08076A0C
	adds r0, r6, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
	b _08076A2A
_08076A0C:
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08076A2A
	ldr r0, _08076A78
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076A7C
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_08076A2A:
	ldr r0, _08076A78
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xB0
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08076A88
	movs r4, 0
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, _08076A80
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xB8
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0xB9
	strb r4, [r0]
	adds r0, r5, 0
	bl nullsub_70
	ldr r0, _08076A84
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE94
	b _08076A94
	.align 2, 0
_08076A78: .4byte gAvailablePokemonNames
_08076A7C: .4byte gUnknown_80FA844
_08076A80: .4byte gUnknown_80F4E54
_08076A84: .4byte gUnknown_80FB668
_08076A88:
	ldr r0, _08076AA0
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_08076A94:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08076A9A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076AA0: .4byte gUnknown_80FB688
	thumb_func_end sub_80769CC

	thumb_func_start sub_8076AA4
sub_8076AA4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076B3A
	ldr r1, [r5, 0x70]
	adds r7, r1, 0
	adds r6, r1, 0
	adds r6, 0xB0
	ldrb r0, [r6]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08076AD8
	adds r0, r1, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_08076AD8:
	ldr r0, _08076B1C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r6]
	cmp r0, 0x5
	beq _08076B28
	movs r4, 0
	movs r0, 0x5
	strb r0, [r6]
	ldr r1, _08076B20
	adds r0, r5, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xB8
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0xB9
	strb r4, [r0]
	adds r0, r5, 0
	bl nullsub_90
	ldr r0, _08076B24
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	b _08076B34
	.align 2, 0
_08076B1C: .4byte gAvailablePokemonNames
_08076B20: .4byte gUnknown_80F4E60
_08076B24: .4byte gUnknown_80FB6A4
_08076B28:
	ldr r0, _08076B44
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
_08076B34:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08076B3A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076B44: .4byte gUnknown_80FB6C0
	thumb_func_end sub_8076AA4

	thumb_func_start sub_8076B48
sub_8076B48:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08076B60
	b _08076C9E
_08076B60:
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	beq _08076B74
	b _08076C9E
_08076B74:
	ldr r5, [r6, 0x70]
	ldr r0, [r4, 0x70]
	mov r8, r0
	adds r1, r5, 0
	adds r1, 0xB0
	ldrb r0, [r1]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08076C20
	mov r2, r8
	adds r2, 0xB0
	ldrb r0, [r2]
	cmp r0, 0x3
	beq _08076C20
	cmp r0, 0x4
	beq _08076C20
	movs r0, 0x3
	strb r0, [r1]
	adds r1, 0x8
	movs r0, 0x7F
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0xB9
	strb r7, [r0]
	movs r0, 0x4
	strb r0, [r2]
	ldr r1, _08076C0C
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	mov r1, r8
	adds r1, 0xB8
	strb r0, [r1]
	mov r0, r8
	adds r0, 0xB9
	strb r7, [r0]
	adds r2, r5, 0
	adds r2, 0x9C
	ldr r0, _08076C10
	ldr r1, [r0]
	ldr r0, _08076C14
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	mov r2, r8
	adds r2, 0x9C
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	adds r0, r6, 0
	adds r1, r4, 0
	bl nullsub_69
	ldr r0, _08076C18
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076C1C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_806CE94
	b _08076C98
	.align 2, 0
_08076C0C: .4byte gUnknown_80F4E5C
_08076C10: .4byte gDungeonGlobalData
_08076C14: .4byte 0x000037f4
_08076C18: .4byte gAvailablePokemonNames
_08076C1C: .4byte gUnknown_80FB6D8
_08076C20:
	adds r7, r5, 0
	adds r7, 0xB0
	ldrb r0, [r7]
	cmp r0, 0x3
	bne _08076C40
	ldr r0, _08076CA8
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076CAC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076C40:
	mov r5, r8
	adds r5, 0xB0
	ldrb r0, [r5]
	cmp r0, 0x3
	bne _08076C60
	ldr r0, _08076CA8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076CAC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076C60:
	ldrb r0, [r7]
	cmp r0, 0x4
	bne _08076C7C
	ldr r0, _08076CA8
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076CB0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076C7C:
	ldrb r0, [r5]
	cmp r0, 0x4
	bne _08076C98
	ldr r0, _08076CA8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076CB0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076C98:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08076C9E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076CA8: .4byte gAvailablePokemonNames
_08076CAC: .4byte gUnknown_80FB6FC
_08076CB0: .4byte gUnknown_80FB718
	thumb_func_end sub_8076B48

	thumb_func_start sub_8076CB4
sub_8076CB4:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r5, 0
	movs r6, 0
_08076CBC:
	ldr r0, _08076D08
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08076D0C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076CFA
	ldr r1, [r4, 0x70]
	adds r2, r1, 0
	adds r2, 0x9C
	ldr r0, [r2]
	cmp r0, r7
	bne _08076CF4
	adds r1, 0xB0
	ldrb r0, [r1]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08076CF2
	strb r6, [r1]
_08076CF2:
	str r6, [r2]
_08076CF4:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08076CFA:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08076CBC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076D08: .4byte gDungeonGlobalData
_08076D0C: .4byte 0x000135cc
	thumb_func_end sub_8076CB4

	thumb_func_start sub_8076D10
sub_8076D10:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076E0E
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _08076E0E
	adds r0, r6, 0
	bl sub_8041C08
	ldr r4, [r6, 0x70]
	adds r5, r4, 0
	adds r5, 0xB0
	ldrb r0, [r5]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08076D54
	adds r0, r4, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_08076D54:
	ldr r0, _08076D74
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r5]
	cmp r0, 0x6
	beq _08076DAC
	movs r0, 0x6
	strb r0, [r5]
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _08076D7C
	ldr r1, _08076D78
	b _08076D7E
	.align 2, 0
_08076D74: .4byte gAvailablePokemonNames
_08076D78: .4byte gUnknown_80F4EBC
_08076D7C:
	ldr r1, _08076DA4
_08076D7E:
	adds r0, r6, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r0, 0x1
	adds r1, r4, 0
	adds r1, 0xB8
	strb r0, [r1]
	adds r1, r4, 0
	adds r1, 0xB9
	movs r0, 0
	strb r0, [r1]
	ldr r0, _08076DA8
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80522F4
	b _08076DB8
	.align 2, 0
_08076DA4: .4byte gUnknown_80F4EC0
_08076DA8: .4byte gUnknown_80FB7BC
_08076DAC:
	ldr r0, _08076E14
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80522F4
_08076DB8:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	beq _08076E08
	movs r5, 0
	movs r7, 0
_08076DC2:
	ldr r0, _08076E18
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08076E1C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076E02
	ldr r1, [r4, 0x70]
	adds r3, r1, 0
	adds r3, 0x78
	ldrb r0, [r3]
	cmp r0, 0x1
	bne _08076E02
	adds r2, r1, 0
	adds r2, 0x80
	ldr r0, [r2]
	cmp r0, r6
	bne _08076E02
	movs r0, 0x6
	strb r0, [r3]
	str r7, [r2]
	adds r0, r1, 0
	adds r0, 0x7C
	strh r7, [r0]
	subs r0, 0x2
	strb r7, [r0]
_08076E02:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08076DC2
_08076E08:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_08076E0E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076E14: .4byte gUnknown_80FB7DC
_08076E18: .4byte gDungeonGlobalData
_08076E1C: .4byte 0x0001357c
	thumb_func_end sub_8076D10

	thumb_func_start sub_8076E20
sub_8076E20:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	mov r9, r3
	ldr r0, [sp, 0x1C]
	ldr r1, [sp, 0x20]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08076E4C
	b _08076F6E
_08076E4C:
	cmp r5, 0
	beq _08076E64
	ldr r0, _08076E5C
	ldr r1, _08076E60
	ldr r1, [r1]
	bl strcpy
	b _08076E6E
	.align 2, 0
_08076E5C: .4byte gUnknown_202DE58
_08076E60: .4byte gUnknown_80FC0C8
_08076E64:
	ldr r0, _08076EA0
	ldr r1, _08076EA4
	ldr r1, [r1]
	bl strcpy
_08076E6E:
	cmp r7, 0
	beq _08076EE4
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, r8
	bl sub_8071728
	lsls r0, 24
	cmp r0, 0
	bne _08076F6E
	adds r0, r4, 0
	movs r1, 0xB
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08076EB0
	ldr r0, _08076EA8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076EAC
	b _08076ECE
	.align 2, 0
_08076EA0: .4byte gUnknown_202DE58
_08076EA4: .4byte gUnknown_80FC0B8
_08076EA8: .4byte gAvailablePokemonNames
_08076EAC: .4byte gUnknown_80FD550
_08076EB0:
	adds r0, r4, 0
	movs r1, 0x9
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08076EE4
	cmp r5, 0
	bne _08076EE4
	ldr r0, _08076EDC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08076EE0
_08076ECE:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08076F6E
	.align 2, 0
_08076EDC: .4byte gAvailablePokemonNames
_08076EE0: .4byte gUnknown_80FCA60
_08076EE4:
	ldr r7, [r4, 0x70]
	ldr r0, _08076F0C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8041F28
	mov r0, r9
	cmp r0, 0x1
	bne _08076F18
	ldr r0, _08076F10
	ldr r1, _08076F14
	ldr r1, [r1]
	bl strcpy
	b _08076F22
	.align 2, 0
_08076F0C: .4byte gAvailablePokemonNames
_08076F10: .4byte gUnknown_202DEA8
_08076F14: .4byte gUnknown_80FC0E4
_08076F18:
	ldr r0, _08076F50
	ldr r1, _08076F54
	ldr r1, [r1]
	bl strcpy
_08076F22:
	lsls r1, r5, 1
	adds r0, r7, 0
	adds r0, 0x1C
	adds r1, r0, r1
	movs r2, 0
	ldrsh r3, [r1, r2]
	mov r0, r9
	subs r3, r0
	cmp r3, 0
	bge _08076F38
	movs r3, 0
_08076F38:
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r3
	beq _08076F5C
	strh r3, [r1]
	ldr r0, _08076F58
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08076F68
	.align 2, 0
_08076F50: .4byte gUnknown_202DEA8
_08076F54: .4byte gUnknown_80FC0D4
_08076F58: .4byte gUnknown_80FC15C
_08076F5C:
	ldr r0, _08076F7C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08076F68:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08076F6E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076F7C: .4byte gUnknown_80FC274
	thumb_func_end sub_8076E20

	thumb_func_start sub_8076F80
sub_8076F80:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	mov r9, r3
	ldr r0, [sp, 0x1C]
	ldr r1, [sp, 0x20]
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077072
	cmp r5, 0
	beq _08076FC4
	ldr r0, _08076FBC
	ldr r1, _08076FC0
	ldr r1, [r1]
	bl strcpy
	b _08076FCE
	.align 2, 0
_08076FBC: .4byte gUnknown_202DE58
_08076FC0: .4byte gUnknown_80FC0AC
_08076FC4:
	ldr r0, _08077008
	ldr r1, _0807700C
	ldr r1, [r1]
	bl strcpy
_08076FCE:
	cmp r7, 0
	beq _08076FE2
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, r8
	bl sub_8071728
	lsls r0, 24
	cmp r0, 0
	bne _08077072
_08076FE2:
	ldr r7, [r4, 0x70]
	ldr r0, _08077010
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8041F4C
	mov r0, r9
	cmp r0, 0x1
	bne _0807701C
	ldr r0, _08077014
	ldr r1, _08077018
	ldr r1, [r1]
	bl strcpy
	b _08077026
	.align 2, 0
_08077008: .4byte gUnknown_202DE58
_0807700C: .4byte gUnknown_80FC09C
_08077010: .4byte gAvailablePokemonNames
_08077014: .4byte gUnknown_202DEA8
_08077018: .4byte gUnknown_80FC0E4
_0807701C:
	ldr r0, _08077054
	ldr r1, _08077058
	ldr r1, [r1]
	bl strcpy
_08077026:
	lsls r1, r5, 1
	adds r0, r7, 0
	adds r0, 0x20
	adds r1, r0, r1
	movs r2, 0
	ldrsh r3, [r1, r2]
	mov r0, r9
	subs r3, r0
	cmp r3, 0
	bge _0807703C
	movs r3, 0
_0807703C:
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r3
	beq _08077060
	strh r3, [r1]
	ldr r0, _0807705C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0807706C
	.align 2, 0
_08077054: .4byte gUnknown_202DEA8
_08077058: .4byte gUnknown_80FC0D4
_0807705C: .4byte gUnknown_80FC158
_08077060:
	ldr r0, _08077080
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807706C:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077072:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077080: .4byte gUnknown_80FC248
	thumb_func_end sub_8076F80

	thumb_func_start sub_8077084
sub_8077084:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077152
	ldr r7, [r4, 0x70]
	ldr r0, _080770C4
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8041F70
	cmp r5, 0
	beq _080770D0
	ldr r0, _080770C8
	ldr r1, _080770CC
	ldr r1, [r1]
	bl strcpy
	b _080770DA
	.align 2, 0
_080770C4: .4byte gAvailablePokemonNames
_080770C8: .4byte gUnknown_202DE58
_080770CC: .4byte gUnknown_80FC0C8
_080770D0:
	ldr r0, _080770EC
	ldr r1, _080770F0
	ldr r1, [r1]
	bl strcpy
_080770DA:
	cmp r6, 0x1
	bne _080770FC
	ldr r0, _080770F4
	ldr r1, _080770F8
	ldr r1, [r1]
	bl strcpy
	b _08077106
	.align 2, 0
_080770EC: .4byte gUnknown_202DE58
_080770F0: .4byte gUnknown_80FC0B8
_080770F4: .4byte gUnknown_202DEA8
_080770F8: .4byte gUnknown_80FC0E4
_080770FC:
	ldr r0, _08077134
	ldr r1, _08077138
	ldr r1, [r1]
	bl strcpy
_08077106:
	lsls r1, r5, 1
	adds r0, r7, 0
	adds r0, 0x1C
	adds r1, r0, r1
	movs r0, 0
	ldrsh r3, [r1, r0]
	adds r3, r6
	cmp r3, 0x13
	ble _0807711A
	movs r3, 0x14
_0807711A:
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r3
	beq _08077140
	strh r3, [r1]
	ldr r0, _0807713C
	ldr r2, [r0]
	mov r0, r8
	adds r1, r4, 0
	bl sub_80522F4
	b _0807714C
	.align 2, 0
_08077134: .4byte gUnknown_202DEA8
_08077138: .4byte gUnknown_80FC0D4
_0807713C: .4byte gUnknown_80FC13C
_08077140:
	ldr r0, _0807715C
	ldr r2, [r0]
	mov r0, r8
	adds r1, r4, 0
	bl sub_80522F4
_0807714C:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077152:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807715C: .4byte gUnknown_80FC270
	thumb_func_end sub_8077084

	thumb_func_start sub_8077160
sub_8077160:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807722E
	ldr r7, [r4, 0x70]
	ldr r0, _080771A0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8041F94
	cmp r5, 0
	beq _080771AC
	ldr r0, _080771A4
	ldr r1, _080771A8
	ldr r1, [r1]
	bl strcpy
	b _080771B6
	.align 2, 0
_080771A0: .4byte gAvailablePokemonNames
_080771A4: .4byte gUnknown_202DE58
_080771A8: .4byte gUnknown_80FC0AC
_080771AC:
	ldr r0, _080771C8
	ldr r1, _080771CC
	ldr r1, [r1]
	bl strcpy
_080771B6:
	cmp r6, 0x1
	bne _080771D8
	ldr r0, _080771D0
	ldr r1, _080771D4
	ldr r1, [r1]
	bl strcpy
	b _080771E2
	.align 2, 0
_080771C8: .4byte gUnknown_202DE58
_080771CC: .4byte gUnknown_80FC09C
_080771D0: .4byte gUnknown_202DEA8
_080771D4: .4byte gUnknown_80FC0E4
_080771D8:
	ldr r0, _08077210
	ldr r1, _08077214
	ldr r1, [r1]
	bl strcpy
_080771E2:
	lsls r1, r5, 1
	adds r0, r7, 0
	adds r0, 0x20
	adds r1, r0, r1
	movs r0, 0
	ldrsh r3, [r1, r0]
	adds r3, r6
	cmp r3, 0x13
	ble _080771F6
	movs r3, 0x14
_080771F6:
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r3
	beq _0807721C
	strh r3, [r1]
	ldr r0, _08077218
	ldr r2, [r0]
	mov r0, r8
	adds r1, r4, 0
	bl sub_80522F4
	b _08077228
	.align 2, 0
_08077210: .4byte gUnknown_202DEA8
_08077214: .4byte gUnknown_80FC0D4
_08077218: .4byte gUnknown_80FC138
_0807721C:
	ldr r0, _08077238
	ldr r2, [r0]
	mov r0, r8
	adds r1, r4, 0
	bl sub_80522F4
_08077228:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807722E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077238: .4byte gUnknown_80FC21C
	thumb_func_end sub_8077160

	.align 2, 0
