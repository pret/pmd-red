	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8075BF4
sub_8075BF4:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08075C0A
	movs r0, 0
	b _08075C52
_08075C0A:
	ldr r6, [r5, 0x70]
	adds r1, r6, 0
	adds r1, 0xA8
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08075C48
	cmp r0, 0x1
	beq _08075C44
	movs r0, 0x1
	strb r0, [r1]
	cmp r4, 0x7F
	beq _08075C3C
	adds r0, r5, 0
	movs r1, 0x2F
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08075C3C
	lsrs r0, r4, 31
	adds r0, r4, r0
	asrs r4, r0, 1
	cmp r4, 0
	bgt _08075C3C
	movs r4, 0x1
_08075C3C:
	adds r0, r6, 0
	adds r0, 0xA9
	strb r4, [r0]
	b _08075C4A
_08075C44:
	movs r7, 0x1
	b _08075C4A
_08075C48:
	movs r7, 0x2
_08075C4A:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	adds r0, r7, 0
_08075C52:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8075BF4

	thumb_func_start sub_8075C58
sub_8075C58:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	lsls r3, 24
	lsrs r5, r3, 24
	adds r7, r5, 0
	movs r2, 0x1
	adds r3, r5, 0
	bl sub_8075CFC
	lsls r0, 24
	cmp r0, 0
	bne _08075CEC
	ldr r0, [r4, 0x70]
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08075C90
	cmp r5, 0
	beq _08075CEC
	ldr r0, _08075C8C
	b _08075CCE
	.align 2, 0
_08075C8C: .4byte gUnknown_80FB380
_08075C90:
	cmp r0, 0x5
	bne _08075CA0
	cmp r7, 0
	beq _08075CEC
	ldr r0, _08075C9C
	b _08075CCE
	.align 2, 0
_08075C9C: .4byte gUnknown_80FB384
_08075CA0:
	adds r0, r4, 0
	bl sub_8041AF4
	adds r0, r4, 0
	mov r1, r8
	bl sub_8075BF4
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_806CE68
	cmp r5, 0x1
	bne _08075CC8
	ldr r0, _08075CC4
	b _08075CCE
	.align 2, 0
_08075CC4: .4byte gUnknown_80FB338
_08075CC8:
	cmp r5, 0x2
	bne _08075CE0
	ldr r0, _08075CDC
_08075CCE:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08075CEC
	.align 2, 0
_08075CDC: .4byte gUnknown_80FB35C
_08075CE0:
	ldr r0, _08075CF8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08075CEC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075CF8: .4byte gUnknown_80FB318
	thumb_func_end sub_8075C58

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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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
	bl sub_80716E8
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
	bl sub_808417C
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

	thumb_func_start GetFlashFireStatus
GetFlashFireStatus:
	push {r4,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077258
	adds r0, r4, 0
	movs r1, 0x48
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0807725C
_08077258:
	movs r0, 0
	b _0807726C
_0807725C:
	ldr r0, [r4, 0x70]
	movs r1, 0x28
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bgt _0807726A
	movs r0, 0x2
	b _0807726C
_0807726A:
	movs r0, 0x1
_0807726C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetFlashFireStatus

	thumb_func_start sub_8077274
sub_8077274:
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080772B4
	ldr r0, [r5, 0x70]
	adds r4, r0, 0
	ldr r0, _080772BC
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	movs r0, 0x28
	ldrsh r1, [r4, r0]
	adds r1, 0x1
	cmp r1, 0x1
	ble _0807729E
	movs r1, 0x2
_0807729E:
	movs r2, 0x28
	ldrsh r0, [r4, r2]
	cmp r0, r1
	beq _080772AE
	strh r1, [r4, 0x28]
	adds r0, r5, 0
	bl sub_8041C58
_080772AE:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080772B4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080772BC: .4byte gAvailablePokemonNames
	thumb_func_end sub_8077274

	thumb_func_start sub_80772C0
sub_80772C0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	adds r5, r1, 0
	adds r4, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x20]
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080772E6
	b _08077422
_080772E6:
	cmp r4, 0
	beq _08077300
	ldr r0, _080772F8
	ldr r1, _080772FC
	ldr r1, [r1]
	bl strcpy
	b _0807730A
	.align 2, 0
_080772F8: .4byte gUnknown_202DE58
_080772FC: .4byte gUnknown_80FC0C8
_08077300:
	ldr r0, _08077340
	ldr r1, _08077344
	ldr r1, [r1]
	bl strcpy
_0807730A:
	cmp r7, 0xFF
	bgt _08077320
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8071728
	lsls r0, 24
	cmp r0, 0
	beq _08077320
	b _08077422
_08077320:
	adds r0, r5, 0
	movs r1, 0xB
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08077350
	cmp r7, 0xFF
	bgt _08077350
	ldr r0, _08077348
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807734C
	b _08077376
	.align 2, 0
_08077340: .4byte gUnknown_202DE58
_08077344: .4byte gUnknown_80FC0B8
_08077348: .4byte gAvailablePokemonNames
_0807734C: .4byte gUnknown_80FD550
_08077350:
	adds r0, r5, 0
	movs r1, 0x9
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807738C
	cmp r4, 0
	bne _0807738C
	cmp r7, 0xFF
	bgt _0807738C
	cmp r6, 0
	beq _08077422
	ldr r0, _08077384
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077388
_08077376:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
	b _08077422
	.align 2, 0
_08077384: .4byte gAvailablePokemonNames
_08077388: .4byte gUnknown_80FCA60
_0807738C:
	ldr r0, [r5, 0x70]
	mov r8, r0
	ldr r0, _080773B8
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	lsls r1, r4, 2
	mov r0, r8
	adds r0, 0x2C
	adds r0, r1
	ldr r0, [r0]
	mov r10, r0
	adds r6, r1, 0
	cmp r7, 0xFF
	bgt _080773BC
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8041FD8
	b _080773C4
	.align 2, 0
_080773B8: .4byte gAvailablePokemonNames
_080773BC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8041FB4
_080773C4:
	mov r0, r8
	adds r0, 0x2C
	adds r4, r0, r6
	ldr r0, [r4]
	adds r1, r7, 0
	bl sub_8009DA4
	str r0, [r4]
	cmp r0, 0x1
	bgt _080773DC
	movs r0, 0x2
	str r0, [r4]
_080773DC:
	ldr r0, [r4]
	ldr r1, _080773F0
	cmp r0, r1
	ble _080773E6
	str r1, [r4]
_080773E6:
	ldr r0, [r4]
	cmp r10, r0
	ble _080773F8
	ldr r0, _080773F4
	b _080773FE
	.align 2, 0
_080773F0: .4byte 0x000063fd
_080773F4: .4byte gUnknown_80FC11C
_080773F8:
	cmp r10, r0
	bge _08077410
	ldr r0, _0807740C
_080773FE:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
	b _0807741C
	.align 2, 0
_0807740C: .4byte gUnknown_80FC118
_08077410:
	ldr r0, _08077430
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
_0807741C:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08077422:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077430: .4byte gUnknown_80FC184
	thumb_func_end sub_80772C0

	thumb_func_start sub_8077434
sub_8077434:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	adds r5, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x20]
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807752E
	cmp r4, 0
	beq _08077470
	ldr r0, _08077468
	ldr r1, _0807746C
	ldr r1, [r1]
	bl strcpy
	b _0807747A
	.align 2, 0
_08077468: .4byte gUnknown_202DE58
_0807746C: .4byte gUnknown_80FC0AC
_08077470:
	ldr r0, _080774BC
	ldr r1, _080774C0
	ldr r1, [r1]
	bl strcpy
_0807747A:
	mov r0, r8
	cmp r0, 0xFF
	bgt _08077490
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8071728
	lsls r0, 24
	cmp r0, 0
	bne _0807752E
_08077490:
	ldr r7, [r5, 0x70]
	ldr r0, _080774C4
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	lsls r1, r4, 2
	adds r0, r7, 0
	adds r0, 0x34
	adds r0, r1
	ldr r0, [r0]
	mov r10, r0
	adds r6, r1, 0
	mov r0, r8
	cmp r0, 0xFF
	bgt _080774C8
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_804201C
	b _080774D0
	.align 2, 0
_080774BC: .4byte gUnknown_202DE58
_080774C0: .4byte gUnknown_80FC09C
_080774C4: .4byte gAvailablePokemonNames
_080774C8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8041FFC
_080774D0:
	adds r0, r7, 0
	adds r0, 0x34
	adds r4, r0, r6
	ldr r0, [r4]
	mov r1, r8
	bl sub_8009DA4
	str r0, [r4]
	cmp r0, 0x1
	bgt _080774E8
	movs r0, 0x2
	str r0, [r4]
_080774E8:
	ldr r0, [r4]
	ldr r1, _080774FC
	cmp r0, r1
	ble _080774F2
	str r1, [r4]
_080774F2:
	ldr r0, [r4]
	cmp r10, r0
	ble _08077504
	ldr r0, _08077500
	b _0807750A
	.align 2, 0
_080774FC: .4byte 0x000063fd
_08077500: .4byte gUnknown_80FC114
_08077504:
	cmp r10, r0
	bge _0807751C
	ldr r0, _08077518
_0807750A:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
	b _08077528
	.align 2, 0
_08077518: .4byte gUnknown_80FC0FC
_0807751C:
	ldr r0, _0807753C
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
_08077528:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_0807752E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807753C: .4byte gUnknown_80FC180
	thumb_func_end sub_8077434

	thumb_func_start sub_8077540
sub_8077540:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080775D2
	ldr r6, [r4, 0x70]
	ldr r0, _08077578
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8042040
	cmp r5, 0
	beq _08077584
	ldr r0, _0807757C
	ldr r1, _08077580
	ldr r1, [r1]
	bl strcpy
	b _0807758E
	.align 2, 0
_08077578: .4byte gAvailablePokemonNames
_0807757C: .4byte gUnknown_202DE58
_08077580: .4byte gUnknown_80FC090
_08077584:
	ldr r0, _080775B4
	ldr r1, _080775B8
	ldr r1, [r1]
	bl strcpy
_0807758E:
	lsls r0, r5, 1
	adds r1, r6, 0
	adds r1, 0x24
	adds r1, r0
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0x13
	bgt _080775C0
	adds r0, r2, 0x1
	strh r0, [r1]
	ldr r0, _080775BC
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080775CC
	.align 2, 0
_080775B4: .4byte gUnknown_202DE58
_080775B8: .4byte gUnknown_80FC084
_080775BC: .4byte gUnknown_80FC1C4
_080775C0:
	ldr r0, _080775D8
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80522F4
_080775CC:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080775D2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080775D8: .4byte gUnknown_80FC218
	thumb_func_end sub_8077540

	thumb_func_start sub_80775DC
sub_80775DC:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 24
	lsrs r4, r3, 24
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080776B6
	cmp r6, 0
	beq _0807760C
	ldr r0, _08077604
	ldr r1, _08077608
	ldr r1, [r1]
	bl strcpy
	b _08077616
	.align 2, 0
_08077604: .4byte gUnknown_202DE58
_08077608: .4byte gUnknown_80FC090
_0807760C:
	ldr r0, _08077654
	ldr r1, _08077658
	ldr r1, [r1]
	bl strcpy
_08077616:
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_8071728
	lsls r0, 24
	cmp r0, 0
	bne _080776B6
	adds r0, r5, 0
	movs r1, 0x1E
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08077664
	cmp r6, 0
	bne _08077664
	cmp r4, 0
	beq _080776B6
	ldr r0, _0807765C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077660
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080776B6
	.align 2, 0
_08077654: .4byte gUnknown_202DE58
_08077658: .4byte gUnknown_80FC084
_0807765C: .4byte gAvailablePokemonNames
_08077660: .4byte gUnknown_80FCA64
_08077664:
	ldr r4, [r5, 0x70]
	ldr r0, _0807769C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8042060
	lsls r0, r6, 1
	adds r4, 0x24
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _080776A4
	subs r0, r2, 0x1
	strh r0, [r1]
	ldr r0, _080776A0
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080776B0
	.align 2, 0
_0807769C: .4byte gAvailablePokemonNames
_080776A0: .4byte gUnknown_80FC1A4
_080776A4:
	ldr r0, _080776BC
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_080776B0:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080776B6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080776BC: .4byte gUnknown_80FC1F0
	thumb_func_end sub_80775DC

	thumb_func_start sub_80776C0
sub_80776C0:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077776
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08077776
	adds r0, r4, 0
	movs r1, 0x1F
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08077718
	ldr r0, _08077710
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r6, 0
	beq _08077776
	ldr r0, _08077714
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077776
	.align 2, 0
_08077710: .4byte gAvailablePokemonNames
_08077714: .4byte gUnknown_80FCC18
_08077718:
	ldr r6, [r4, 0x70]
	ldr r0, _08077758
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08077764
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0807775C
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xBD
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_80420A0
	ldr r0, _08077760
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077770
	.align 2, 0
_08077758: .4byte gAvailablePokemonNames
_0807775C: .4byte gUnknown_80F4E3C
_08077760: .4byte gUnknown_80FB2E0
_08077764:
	ldr r0, _0807777C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08077770:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077776:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807777C: .4byte gUnknown_80FB300
	thumb_func_end sub_80776C0

	thumb_func_start sub_8077780
sub_8077780:
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
	bne _080777A2
	b _080778F0
_080777A2:
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r10
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	beq _080777B4
	b _080778F0
_080777B4:
	adds r0, r5, 0
	movs r1, 0x16
	bl HasAbility
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _080777EC
	ldr r0, _080777E4
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	mov r0, r10
	cmp r0, 0
	bne _080777D6
	b _080778F0
_080777D6:
	ldr r0, _080777E8
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080778F0
	.align 2, 0
_080777E4: .4byte gAvailablePokemonNames
_080777E8: .4byte gUnknown_80FCBF8
_080777EC:
	movs r6, 0x1
	ldr r1, [r5, 0x70]
	mov r8, r1
	ldr r0, _08077844
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	mov r1, r8
	adds r1, 0xAC
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _08077850
	movs r0, 0x4
	strb r0, [r1]
	ldr r1, _08077848
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_808417C
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
	ldr r0, _0807784C
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	bl sub_8041C1C
	adds r0, r5, 0
	bl GetMovementSpeed
	b _0807785C
	.align 2, 0
_08077844: .4byte gAvailablePokemonNames
_08077848: .4byte gUnknown_80F4E50
_0807784C: .4byte gUnknown_80FB2AC
_08077850:
	ldr r0, _08077900
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807785C:
	adds r0, r5, 0
	movs r1, 0x19
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080778EA
	cmp r6, 0
	bne _080778EA
	movs r3, 0
	mov r9, r3
	movs r6, 0
_08077874:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	ldr r1, _08077904
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
	beq _080778E4
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080778E4
	mov r0, r9
	cmp r0, 0
	bne _080778CA
	movs r1, 0x1
	mov r9, r1
	ldr r0, _08077908
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _0807790C
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
_080778CA:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807167C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080778E4
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, r10
	bl sub_8077780
_080778E4:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08077874
_080778EA:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080778F0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077900: .4byte gUnknown_80FB2CC
_08077904: .4byte gAdjacentTileOffsets
_08077908: .4byte gAvailablePokemonNames
_0807790C: .4byte gUnknown_80FF01C
	thumb_func_end sub_8077780

	thumb_func_start sub_8077910
sub_8077910:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080779DE
	cmp r4, 0
	bne _08077940
	ldr r1, _08077964
	adds r0, r5, 0
	movs r2, 0
	bl sub_808417C
	adds r4, r0, 0x1
_08077940:
	ldr r6, [r5, 0x70]
	ldr r0, _08077968
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	bl GetMovementSpeed
	adds r7, r0, 0
	cmp r7, 0x4
	bne _08077970
	mov r0, r9
	cmp r0, 0
	beq _080779D8
	ldr r0, _0807796C
	b _0807799E
	.align 2, 0
_08077964: .4byte gUnknown_80F4E40
_08077968: .4byte gAvailablePokemonNames
_0807796C: .4byte gUnknown_80FC2B8
_08077970:
	movs r2, 0
	movs r0, 0x84
	lsls r0, 1
	adds r1, r6, r0
	b _08077988
_0807797A:
	adds r2, 0x1
	cmp r2, 0x4
	bgt _08077990
	movs r1, 0x84
	lsls r1, 1
	adds r0, r6, r1
	adds r1, r0, r2
_08077988:
	ldrb r0, [r1]
	cmp r0, 0
	bne _0807797A
	strb r4, [r1]
_08077990:
	adds r0, r5, 0
	bl GetMovementSpeed
	adds r4, r0, 0
	cmp r7, r4
	bne _080779B0
	ldr r0, _080779AC
_0807799E:
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	b _080779D8
	.align 2, 0
_080779AC: .4byte gUnknown_80FC298
_080779B0:
	adds r0, r5, 0
	bl sub_8041CB8
	ldr r1, _080779EC
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	adds r1, r6, 0
	adds r1, 0xF8
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r6, r1
	strb r2, [r0]
_080779D8:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080779DE:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080779EC: .4byte gUnknown_80FA124
	thumb_func_end sub_8077910

	thumb_func_start sub_80779F0
sub_80779F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r10, r0
	adds r5, r1, 0
	mov r8, r2
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077AD0
	mov r0, r10
	adds r1, r5, 0
	mov r2, r9
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08077AD0
	ldr r7, [r5, 0x70]
	ldr r0, _08077A48
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	bl GetMovementSpeed
	str r0, [sp]
	cmp r0, 0
	bne _08077A50
	mov r0, r9
	cmp r0, 0
	beq _08077ACA
	ldr r0, _08077A4C
	b _08077AA2
	.align 2, 0
_08077A48: .4byte gAvailablePokemonNames
_08077A4C: .4byte gUnknown_80FC2D8
_08077A50:
	movs r0, 0
	cmp r0, r8
	bge _08077A8C
_08077A56:
	movs r1, 0
	adds r6, r0, 0x1
_08077A5A:
	ldr r2, _08077A78
	adds r0, r7, r2
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	bne _08077A80
	adds r0, r5, 0
	ldr r1, _08077A7C
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	strb r0, [r4]
	b _08077A86
	.align 2, 0
_08077A78: .4byte 0x0000010d
_08077A7C: .4byte gUnknown_80F4E48
_08077A80:
	adds r1, 0x1
	cmp r1, 0x4
	ble _08077A5A
_08077A86:
	adds r0, r6, 0
	cmp r0, r8
	blt _08077A56
_08077A8C:
	adds r0, r5, 0
	bl GetMovementSpeed
	adds r4, r0, 0
	ldr r0, [sp]
	cmp r0, r4
	bne _08077AB4
	mov r2, r9
	cmp r2, 0
	beq _08077ACA
	ldr r0, _08077AB0
_08077AA2:
	ldr r2, [r0]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
	b _08077ACA
	.align 2, 0
_08077AB0: .4byte gUnknown_80FC298
_08077AB4:
	adds r0, r5, 0
	bl sub_8041CCC
	ldr r0, _08077AE0
	lsls r1, r4, 2
	adds r1, r0
	ldr r2, [r1]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
_08077ACA:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08077AD0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077AE0: .4byte gUnknown_80FA124
	thumb_func_end sub_80779F0

	thumb_func_start sub_8077AE4
sub_8077AE4:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r7, r5, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077BAA
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08077BAA
	ldr r0, _08077B2C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	movs r1, 0x12
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08077B34
	cmp r5, 0
	beq _08077BAA
	ldr r0, _08077B30
	b _08077B48
	.align 2, 0
_08077B2C: .4byte gAvailablePokemonNames
_08077B30: .4byte gUnknown_80FD500
_08077B34:
	adds r0, r4, 0
	movs r1, 0x40
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08077B58
	cmp r7, 0
	beq _08077BAA
	ldr r0, _08077B54
_08077B48:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077BAA
	.align 2, 0
_08077B54: .4byte gUnknown_80FCDB4
_08077B58:
	adds r0, r4, 0
	bl sub_8041BE8
	ldr r5, [r4, 0x70]
	adds r1, r5, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08077B98
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, _08077B90
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xBD
	strb r0, [r1]
	ldr r0, _08077B94
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077BA4
	.align 2, 0
_08077B90: .4byte gUnknown_80F4E4C
_08077B94: .4byte gUnknown_80FB25C
_08077B98:
	ldr r0, _08077BB0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08077BA4:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077BAA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077BB0: .4byte gUnknown_80FB27C
	thumb_func_end sub_8077AE4

	thumb_func_start sub_8077BB4
sub_8077BB4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077C3A
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08077C3A
	ldr r5, [r4, 0x70]
	ldr r0, _08077C1C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _08077C28
	movs r0, 0x4
	strb r0, [r1]
	ldr r1, _08077C20
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xBD
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041BF8
	ldr r0, _08077C24
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077C34
	.align 2, 0
_08077C1C: .4byte gAvailablePokemonNames
_08077C20: .4byte gUnknown_80F4ECC
_08077C24: .4byte gUnknown_80FB940
_08077C28:
	ldr r0, _08077C40
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08077C34:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077C3A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08077C40: .4byte gUnknown_80FB960
	thumb_func_end sub_8077BB4

	thumb_func_start HealTargetHP
HealTargetHP:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	adds r5, r1, 0
	mov r10, r2
	mov r8, r3
	ldr r0, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08077C6E
	b _08077DC8
_08077C6E:
	ldr r4, [r5, 0x70]
	movs r0, 0x10
	ldrsh r7, [r4, r0]
	movs r1, 0xE
	ldrsh r6, [r4, r1]
	ldrh r2, [r4, 0xE]
	adds r0, r6, 0
	ldrh r1, [r4, 0x10]
	mov r12, r1
	adds r1, r7, 0
	cmp r0, r1
	bne _08077C8C
	mov r0, r8
	cmp r0, 0
	bgt _08077C92
_08077C8C:
	mov r3, r10
	cmp r3, 0
	bne _08077CD0
_08077C92:
	ldrh r1, [r4, 0x10]
	add r1, r8
	strh r1, [r4, 0x10]
	ldrh r0, [r4, 0xE]
	add r0, r8
	strh r0, [r4, 0xE]
	lsls r1, 16
	asrs r1, 16
	ldr r0, _08077CCC
	cmp r1, r0
	ble _08077CAA
	strh r0, [r4, 0x10]
_08077CAA:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	movs r3, 0x10
	ldrsh r2, [r4, r3]
	ldrh r1, [r4, 0x10]
	cmp r0, r2
	ble _08077CBA
	strh r1, [r4, 0xE]
_08077CBA:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bne _08077CC4
	adds r6, r0, 0
_08077CC4:
	adds r0, r5, 0
	bl sub_8041C94
	b _08077CE8
	.align 2, 0
_08077CCC: .4byte 0x000003e7
_08077CD0:
	mov r3, r10
	adds r0, r2, r3
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, r1
	ble _08077CE2
	mov r0, r12
	strh r0, [r4, 0xE]
_08077CE2:
	adds r0, r5, 0
	bl sub_8041CA8
_08077CE8:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	subs r7, r0, r7
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	subs r6, r0, r6
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	ldr r0, _08077D1C
	str r6, [r0]
	str r7, [r0, 0x4]
	ldr r0, _08077D20
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r6, 0
	bne _08077D28
	cmp r7, 0
	bne _08077D28
	ldr r3, [sp]
	cmp r3, 0
	beq _08077DC8
	ldr r0, _08077D24
	b _08077D3A
	.align 2, 0
_08077D1C: .4byte gUnknown_202DE30
_08077D20: .4byte gAvailablePokemonNames
_08077D24: .4byte gUnknown_80FB204
_08077D28:
	mov r0, r8
	cmp r0, 0
	bne _08077D4C
	cmp r6, 0
	bne _08077D4C
	ldr r1, [sp]
	cmp r1, 0
	beq _08077DC8
	ldr r0, _08077D48
_08077D3A:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
	b _08077DC8
	.align 2, 0
_08077D48: .4byte gUnknown_80FB21C
_08077D4C:
	movs r2, 0
	mov r8, r2
	cmp r7, 0
	beq _08077D6E
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _08077D62
	mov r8, r7
_08077D62:
	ldr r0, _08077DA0
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
_08077D6E:
	cmp r6, 0
	beq _08077DB4
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _08077D80
	mov r8, r6
_08077D80:
	mov r3, r10
	cmp r3, 0
	beq _08077DB4
	movs r0, 0x10
	ldrsh r1, [r4, r0]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08077DA8
	ldr r0, _08077DA4
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
	b _08077DB4
	.align 2, 0
_08077DA0: .4byte gUnknown_80FB240
_08077DA4: .4byte gUnknown_80FB1E0
_08077DA8:
	ldr r0, _08077DD8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r5, 0
	bl sub_80522F4
_08077DB4:
	mov r3, r8
	cmp r3, 0
	beq _08077DC8
	movs r3, 0x1
	negs r3, r3
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_803ED30
_08077DC8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077DD8: .4byte gUnknown_80FB1C4
	thumb_func_end HealTargetHP

	thumb_func_start sub_8077DDC
sub_8077DDC:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077E3C
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xF1
	ldrb r0, [r1]
	cmp r0, 0
	beq _08077E0C
	ldr r0, _08077E08
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077E3C
	.align 2, 0
_08077E08: .4byte gUnknown_80FAEF0
_08077E0C:
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_75
	ldr r0, _08077E44
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077E48
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0
	bl sub_803F580
	bl sub_8040A84
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077E3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077E44: .4byte gAvailablePokemonNames
_08077E48: .4byte gUnknown_80FAEA0
	thumb_func_end sub_8077DDC

	thumb_func_start sub_8077E4C
sub_8077E4C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077EC0
	bl sub_8043D10
	lsls r0, 24
	cmp r0, 0
	beq _08077E70
	ldr r0, _08077E6C
	b _08077E7E
	.align 2, 0
_08077E6C: .4byte gUnknown_80FAF3C
_08077E70:
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xF2
	ldrb r0, [r1]
	cmp r0, 0
	beq _08077E90
	ldr r0, _08077E8C
_08077E7E:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077EC0
	.align 2, 0
_08077E8C: .4byte gUnknown_80FAF1C
_08077E90:
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_76
	ldr r0, _08077EC8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077ECC
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0
	bl sub_803F580
	bl sub_8040A84
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077EC0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077EC8: .4byte gAvailablePokemonNames
_08077ECC: .4byte gUnknown_80FAEC8
	thumb_func_end sub_8077E4C

	thumb_func_start sub_8077ED0
sub_8077ED0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077F30
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xF0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08077F00
	ldr r0, _08077EFC
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08077F30
	.align 2, 0
_08077EFC: .4byte gUnknown_80FAFD0
_08077F00:
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_77
	ldr r0, _08077F38
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08077F3C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0
	bl sub_803F580
	bl sub_8040A84
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08077F30:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08077F38: .4byte gAvailablePokemonNames
_08077F3C: .4byte gUnknown_80FAFAC
	thumb_func_end sub_8077ED0

	thumb_func_start sub_8077F40
sub_8077F40:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	mov r9, r6
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08077F62
	b _08078068
_08077F62:
	adds r0, r5, 0
	bl GetEntityType
	mov r10, r0
	cmp r0, 0x1
	beq _08077F70
	b _08078068
_08077F70:
	ldr r7, [r4, 0x70]
	cmp r5, r4
	bne _08077F88
	cmp r6, 0
	beq _08078068
	ldr r0, _08077F84
	ldr r2, [r0]
	adds r0, r4, 0
	b _08078022
	.align 2, 0
_08077F84: .4byte gPtrCantLeechSeedSelfMessage
_08077F88:
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r9
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08078068
	ldr r0, _08077FC0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	movs r1, 0x4
	bl HasType
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0
	beq _08077FC8
	mov r0, r9
	cmp r0, 0
	beq _08078068
	ldr r0, _08077FC4
	b _0807801E
	.align 2, 0
_08077FC0: .4byte gAvailablePokemonNames
_08077FC4: .4byte gPtrCantLeechSeedMonMessage
_08077FC8:
	adds r6, r7, 0
	adds r6, 0xD0
	ldrb r0, [r6]
	cmp r0, 0x1
	beq _0807801C
	cmp r0, 0x2
	bne _08077FE2
	ldr r0, _08078014
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08077FE2:
	mov r1, r10
	strb r1, [r6]
	ldr r1, _08078018
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xD9
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0xDA
	mov r6, r8
	strb r6, [r0]
	adds r0, r4, 0
	bl nullsub_78
	adds r1, r7, 0
	adds r1, 0xD8
	movs r0, 0xFF
	strb r0, [r1]
	movs r2, 0
	adds r3, r1, 0
	b _08078030
	.align 2, 0
_08078014: .4byte gUnknown_80FAA8C
_08078018: .4byte gUnknown_80F4EB0
_0807801C:
	ldr r0, _0807802C
_0807801E:
	ldr r2, [r0]
	adds r0, r5, 0
_08078022:
	adds r1, r4, 0
	bl sub_80522F4
	b _08078068
	.align 2, 0
_0807802C: .4byte gUnknown_80FAE7C
_08078030:
	ldr r0, _08078078
	ldr r0, [r0]
	lsls r1, r2, 2
	ldr r6, _0807807C
	adds r0, r6
	adds r0, r1
	ldr r0, [r0]
	cmp r5, r0
	bne _08078050
	strb r2, [r3]
	ldr r0, [r5, 0x70]
	adds r1, r7, 0
	adds r1, 0xD4
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
_08078050:
	adds r2, 0x1
	cmp r2, 0x13
	ble _08078030
	ldr r0, _08078080
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078068:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078078: .4byte gDungeonGlobalData
_0807807C: .4byte 0x000135cc
_08078080: .4byte gUnknown_80FAE58
	thumb_func_end sub_8077F40

	thumb_func_start sub_8078084
sub_8078084:
	push {r4-r6,lr}
	ldr r6, [r0, 0x70]
	movs r5, 0
_0807808A:
	ldr r0, _080780DC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080780E0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080780D0
	ldr r1, [r4, 0x70]
	adds r3, r1, 0
	adds r3, 0xD0
	ldrb r0, [r3]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080780D0
	adds r0, r1, 0
	adds r0, 0xD4
	adds r1, r6, 0
	adds r1, 0x98
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne _080780D0
	movs r0, 0
	strb r0, [r3]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080780D0:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807808A
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080780DC: .4byte gDungeonGlobalData
_080780E0: .4byte 0x000135cc
	thumb_func_end sub_8078084

	thumb_func_start sub_80780E4
sub_80780E4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080781C4
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080781C4
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _080781C4
	ldr r6, [r4, 0x70]
	ldr r0, _0807816C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r7, r6, 0
	adds r7, 0xD0
	ldrb r0, [r7]
	cmp r0, 0x2
	beq _08078178
	cmp r0, 0x1
	bne _08078134
	ldr r0, _08078170
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_08078134:
	movs r0, 0
	mov r8, r0
	movs r0, 0x2
	strb r0, [r7]
	ldr r1, _08078174
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xD9
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0xDA
	mov r1, r8
	strb r1, [r0]
	adds r0, r5, 0
	bl nullsub_74
	adds r1, r6, 0
	adds r1, 0xD8
	movs r0, 0xFF
	strb r0, [r1]
	movs r2, 0
	adds r3, r1, 0
	b _0807818C
	.align 2, 0
_0807816C: .4byte gAvailablePokemonNames
_08078170: .4byte gUnknown_80FA79C
_08078174: .4byte gUnknown_80F4EF0
_08078178:
	ldr r0, _08078188
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080781C4
	.align 2, 0
_08078188: .4byte gUnknown_80FBB78
_0807818C:
	ldr r0, _080781D0
	ldr r0, [r0]
	lsls r1, r2, 2
	ldr r7, _080781D4
	adds r0, r7
	adds r0, r1
	ldr r0, [r0]
	cmp r5, r0
	bne _080781AC
	strb r2, [r3]
	ldr r0, [r5, 0x70]
	adds r1, r6, 0
	adds r1, 0xD4
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
_080781AC:
	adds r2, 0x1
	cmp r2, 0x13
	ble _0807818C
	ldr r0, _080781D8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_080781C4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080781D0: .4byte gDungeonGlobalData
_080781D4: .4byte 0x000135cc
_080781D8: .4byte gUnknown_80FBB4C
	thumb_func_end sub_80780E4

	thumb_func_start sub_80781DC
sub_80781DC:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078242
	ldr r5, [r4, 0x70]
	ldr r0, _08078228
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08078230
	movs r0, 0x1
	strb r0, [r1]
	adds r1, r6, 0x1
	adds r0, r5, 0
	adds r0, 0xDD
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_8041CDC
	ldr r0, _0807822C
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0807823C
	.align 2, 0
_08078228: .4byte gAvailablePokemonNames
_0807822C: .4byte gUnknown_80FB73C
_08078230:
	ldr r0, _08078248
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807823C:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078242:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078248: .4byte gUnknown_80FB764
	thumb_func_end sub_80781DC

	thumb_func_start sub_807824C
sub_807824C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r7, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080782C2
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _080782C2
	ldr r5, [r4, 0x70]
	ldr r0, _080782A8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _080782B0
	movs r0, 0x2
	strb r0, [r1]
	adds r1, r7, 0x1
	adds r0, r5, 0
	adds r0, 0xDD
	strb r1, [r0]
	adds r0, r4, 0
	bl sub_8041CEC
	ldr r0, _080782AC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080782BC
	.align 2, 0
_080782A8: .4byte gAvailablePokemonNames
_080782AC: .4byte gUnknown_80FB780
_080782B0:
	ldr r0, _080782C8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080782BC:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080782C2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080782C8: .4byte gUnknown_80FB7A0
	thumb_func_end sub_807824C

	thumb_func_start sub_80782CC
sub_80782CC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807833E
	ldr r5, [r4, 0x70]
	ldr r0, _08078320
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _0807832C
	movs r0, 0x3
	strb r0, [r1]
	ldr r1, _08078324
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xDD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_79
	ldr r0, _08078328
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078338
	.align 2, 0
_08078320: .4byte gAvailablePokemonNames
_08078324: .4byte gUnknown_80F4EC4
_08078328: .4byte gUnknown_80FB8BC
_0807832C:
	ldr r0, _08078344
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08078338:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807833E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078344: .4byte gUnknown_80FB8E4
	thumb_func_end sub_80782CC

	thumb_func_start sub_8078348
sub_8078348:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080783BA
	ldr r5, [r4, 0x70]
	ldr r0, _0807839C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xDC
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _080783A8
	movs r0, 0x4
	strb r0, [r1]
	ldr r1, _080783A0
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xDD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_80
	ldr r0, _080783A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080783B4
	.align 2, 0
_0807839C: .4byte gAvailablePokemonNames
_080783A0: .4byte gUnknown_80F4EC8
_080783A4: .4byte gUnknown_80FB900
_080783A8:
	ldr r0, _080783C0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080783B4:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080783BA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080783C0: .4byte gUnknown_80FB924
	thumb_func_end sub_8078348

	thumb_func_start sub_80783C4
sub_80783C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	adds r5, r0, 0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080783E8
	b _0807856A
_080783E8:
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	beq _080783FA
	b _0807856A
_080783FA:
	ldr r4, [r7, 0x70]
	ldr r0, _08078420
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r4, 0
	adds r1, 0xC8
	ldrb r0, [r1]
	cmp r0, 0x2
	bne _08078428
	ldr r0, _08078424
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _0807856A
	.align 2, 0
_08078420: .4byte gAvailablePokemonNames
_08078424: .4byte gUnknown_80FB994
_08078428:
	movs r6, 0
	mov r8, r1
	movs r0, 0xC9
	adds r0, r4
	mov r9, r0
	movs r1, 0xCA
	adds r1, r4
	mov r10, r1
	adds r2, r4, 0
	adds r2, 0xCB
	str r2, [sp, 0x1C]
	adds r4, 0xCC
	str r4, [sp, 0x20]
_08078442:
	ldr r0, _0807857C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r3, _08078580
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078480
	cmp r7, r4
	beq _08078480
	ldr r0, [r4, 0x70]
	adds r0, 0xC8
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08078480
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807A5D0
	movs r0, 0x2A
	bl sub_803E46C
_08078480:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08078442
	adds r0, r7, 0
	bl sub_8041D38
	ldr r0, _08078584
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	mov r4, r8
	ldrb r0, [r4]
	cmp r0, 0
	beq _080784A8
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x2
	bl sub_807A5D0
_080784A8:
	movs r4, 0
	movs r0, 0x2
	mov r1, r8
	strb r0, [r1]
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	mov r2, r9
	strb r0, [r2]
	mov r3, sp
	ldrb r0, [r3, 0x18]
	mov r3, r10
	strb r0, [r3]
	ldr r1, _08078588
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldr r2, [sp, 0x20]
	strb r4, [r2]
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	ldr r0, _0807857C
	ldr r0, [r0]
	ldr r3, _0807858C
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08078590
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_80522F4
	movs r6, 0
	mov r8, r6
_08078502:
	ldr r0, _0807857C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r4, _08078580
	adds r0, r4
	adds r0, r1
	ldr r0, [r0]
	mov r9, r0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807855E
	mov r5, r9
	ldr r4, [r5, 0x70]
	adds r1, r4, 0
	adds r1, 0x78
	movs r0, 0x6
	strb r0, [r1]
	adds r0, r4, 0
	adds r0, 0x80
	mov r1, r8
	str r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _0807855E
	mov r1, sp
	adds r0, r4, 0
	adds r0, 0x44
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	mov r0, r9
	movs r1, 0x1
	bl MoveIfPossible
	adds r1, r4, 0
	adds r1, 0x44
	mov r0, sp
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_0807855E:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08078502
	adds r0, r7, 0
	bl DungeonEntityUpdateStatusSprites
_0807856A:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807857C: .4byte gDungeonGlobalData
_08078580: .4byte 0x000135cc
_08078584: .4byte gAvailablePokemonNames
_08078588: .4byte gUnknown_80F4ED0
_0807858C: .4byte 0x000037fc
_08078590: .4byte gUnknown_80FB978
	thumb_func_end sub_80783C4

	thumb_func_start sub_8078594
sub_8078594:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807866E
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807866E
	ldr r4, [r5, 0x70]
	ldr r7, [r6, 0x70]
	adds r0, r5, 0
	movs r1, 0xE
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _08078640
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _0807866E
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl sub_807A5D0
	adds r0, r6, 0
	bl sub_8041D48
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r4, 0xE]
	cmp r0, 0
	bne _080785F6
	movs r0, 0x1
	strh r0, [r4, 0xE]
_080785F6:
	adds r1, r7, 0
	adds r1, 0xC8
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _0807861C
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _08078634
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xCB
	strb r0, [r1]
	adds r1, 0x1
	movs r0, 0
	strb r0, [r1]
_0807861C:
	ldr r0, _08078638
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807863C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	b _08078668
	.align 2, 0
_08078634: .4byte gUnknown_80F4EA4
_08078638: .4byte gAvailablePokemonNames
_0807863C: .4byte gUnknown_80FB004
_08078640:
	ldr r0, _08078674
	ldr r4, [r0]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077084
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077160
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80779F0
_08078668:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_0807866E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078674: .4byte gUnknown_8106A4C
	thumb_func_end sub_8078594

	thumb_func_start sub_8078678
sub_8078678:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r6, r1, 0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078732
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x3
	bl sub_807A5D0
	movs r5, 0
_0807869A:
	ldr r0, _0807873C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08078740
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080786C8
	ldr r0, [r4, 0x70]
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _080786C8
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807A5D0
_080786C8:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807869A
	adds r0, r6, 0
	bl nullsub_81
	ldr r5, [r6, 0x70]
	mov r8, r5
	adds r1, r5, 0
	adds r1, 0xC8
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08078700
	movs r4, 0
	movs r0, 0x3
	strb r0, [r1]
	ldr r1, _08078744
	adds r0, r6, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xCB
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0xCC
	strb r4, [r0]
_08078700:
	ldr r0, _0807873C
	ldr r1, [r0]
	ldr r2, _08078748
	adds r0, r1, r2
	str r6, [r0]
	ldr r0, _0807874C
	adds r1, r0
	mov r0, r8
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08078750
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08078754
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80522F4
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_08078732:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807873C: .4byte gDungeonGlobalData
_08078740: .4byte 0x000135cc
_08078744: .4byte gUnknown_80F4EA8
_08078748: .4byte 0x00017b30
_0807874C: .4byte 0x00017b3c
_08078750: .4byte gAvailablePokemonNames
_08078754: .4byte gUnknown_80FB01C
	thumb_func_end sub_8078678

	thumb_func_start sub_8078758
sub_8078758:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080787DA
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _080787DA
	ldr r6, [r4, 0x70]
	ldr r0, _080787BC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x5
	beq _080787C8
	movs r0, 0x5
	strb r0, [r1]
	ldr r1, _080787C0
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xBD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_73
	ldr r0, _080787C4
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080787D4
	.align 2, 0
_080787BC: .4byte gAvailablePokemonNames
_080787C0: .4byte gUnknown_80F4ED8
_080787C4: .4byte gUnknown_80FB9F0
_080787C8:
	ldr r0, _080787E0
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_080787D4:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080787DA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080787E0: .4byte gUnknown_80FBA14
	thumb_func_end sub_8078758

	thumb_func_start sub_80787E4
sub_80787E4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078852
	ldr r4, [r5, 0x70]
	ldr r0, _08078834
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	movs r0, 0x89
	lsls r0, 1
	adds r4, r0
	ldrb r0, [r4]
	cmp r0, 0x2
	bhi _08078840
	adds r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	bl sub_804178C
	adds r0, r5, 0
	bl sub_8041D5C
	ldr r1, _08078838
	ldrb r0, [r4]
	str r0, [r1]
	ldr r0, _0807883C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _0807884C
	.align 2, 0
_08078834: .4byte gAvailablePokemonNames
_08078838: .4byte gUnknown_202DE30
_0807883C: .4byte gUnknown_80FBA38
_08078840:
	ldr r0, _08078858
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807884C:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08078852:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078858: .4byte gUnknown_80FBA60
	thumb_func_end sub_80787E4

	thumb_func_start sub_807885C
sub_807885C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080788DE
	ldr r0, [r4, 0x70]
	adds r7, r0, 0
	adds r5, r7, 0
	adds r5, 0xE4
	ldrb r0, [r5]
	cmp r0, 0x2
	bne _08078884
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A7C8
_08078884:
	ldr r0, _080788C0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _080788CC
	movs r0, 0x1
	strb r0, [r5]
	ldr r1, _080788C4
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xE5
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041D84
	ldr r0, _080788C8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080788D8
	.align 2, 0
_080788C0: .4byte gAvailablePokemonNames
_080788C4: .4byte gUnknown_80F4EE4
_080788C8: .4byte gUnknown_80FBA80
_080788CC:
	ldr r0, _080788E4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080788D8:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080788DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080788E4: .4byte gUnknown_80FBAA0
	thumb_func_end sub_807885C

	thumb_func_start sub_80788E8
sub_80788E8:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807895E
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _0807895E
	adds r0, r5, 0
	bl nullsub_82
	ldr r4, [r5, 0x70]
	ldr r0, _08078940
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0xFD
	ldrb r0, [r4]
	cmp r0, 0
	bne _0807894C
	ldr r1, _08078944
	adds r0, r5, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	strb r0, [r4]
	ldr r0, _08078948
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _08078958
	.align 2, 0
_08078940: .4byte gAvailablePokemonNames
_08078944: .4byte gUnknown_80F4EEC
_08078948: .4byte gUnknown_80FBB04
_0807894C:
	ldr r0, _08078964
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_08078958:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_0807895E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078964: .4byte gUnknown_80FBB28
	thumb_func_end sub_80788E8

	thumb_func_start sub_8078968
sub_8078968:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, [r4, 0x70]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078A4A
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08078A4A
	movs r3, 0
	ldr r0, _080789E8
	mov r8, r0
	movs r1, 0x1
	mov r12, r1
	movs r0, 0x8C
	lsls r0, 1
	adds r2, r5, r0
	movs r7, 0x10
_080789A2:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _080789B4
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080789BC
_080789B4:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _080789A2
_080789BC:
	cmp r3, 0x4
	bne _080789F0
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080789F0
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080789EC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078A4A
	.align 2, 0
_080789E8: .4byte gAvailablePokemonNames
_080789EC: .4byte gUnknown_80FBBD4
_080789F0:
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xBC
	ldrb r0, [r1]
	cmp r0, 0x6
	beq _08078A38
	movs r0, 0x6
	strb r0, [r1]
	ldr r1, _08078A30
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xBD
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_83
	ldr r0, _08078A34
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078A44
	.align 2, 0
_08078A30: .4byte gUnknown_80F4EF4
_08078A34: .4byte gUnknown_80FBB94
_08078A38:
	ldr r0, _08078A54
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08078A44:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078A4A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078A54: .4byte gUnknown_80FBBB8
	thumb_func_end sub_8078968

	thumb_func_start sub_8078A58
sub_8078A58:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	mov r8, r0
	adds r6, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078B4A
	ldr r4, [r6, 0x70]
	cmp r5, 0
	beq _08078AE0
	mov r0, sp
	adds r1, r5, 0
	bl sub_80943A0
	ldr r2, [sp]
	movs r0, 0xA0
	lsls r0, 1
	adds r5, r4, r0
	ldr r7, [r5]
	add r0, sp, 0x4
	adds r1, r7, 0
	bl sub_80942C0
	ldr r2, [sp, 0x4]
	str r2, [r5]
	movs r0, 0x9E
	lsls r0, 1
	adds r4, r0
	ldr r1, [r4]
	add r0, sp, 0x8
	bl sub_8094318
	ldr r0, [sp, 0x8]
	str r0, [r4]
	ldr r0, _08078AD0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r5]
	bl RoundUpFixedPoint
	cmp r4, r0
	beq _08078AD8
	adds r0, r6, 0
	bl sub_8041D9C
	ldr r0, _08078AD4
	b _08078B22
	.align 2, 0
_08078AD0: .4byte gAvailablePokemonNames
_08078AD4: .4byte gUnknown_80FBD9C
_08078AD8:
	ldr r0, _08078ADC
	b _08078B22
	.align 2, 0
_08078ADC: .4byte gUnknown_80FBE3C
_08078AE0:
	add r0, sp, 0xC
	adds r1, r7, 0
	bl sub_80943A0
	ldr r2, [sp, 0xC]
	movs r0, 0x9E
	lsls r0, 1
	adds r4, r0
	ldr r7, [r4]
	add r0, sp, 0x10
	adds r1, r7, 0
	bl sub_80942C0
	ldr r0, [sp, 0x10]
	str r0, [r4]
	ldr r0, _08078B30
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	bl RoundUpFixedPoint
	adds r5, r0, 0
	ldr r0, [r4]
	bl RoundUpFixedPoint
	cmp r5, r0
	beq _08078B38
	adds r0, r6, 0
	bl nullsub_84
	ldr r0, _08078B34
_08078B22:
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	b _08078B44
	.align 2, 0
_08078B30: .4byte gAvailablePokemonNames
_08078B34: .4byte gUnknown_80FBD78
_08078B38:
	ldr r0, _08078B58
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
_08078B44:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_08078B4A:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078B58: .4byte gUnknown_80FBE40
	thumb_func_end sub_8078A58

	thumb_func_start sub_8078B5C
sub_8078B5C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	mov r9, r0
	adds r6, r1, 0
	mov r10, r2
	str r3, [sp, 0x1C]
	ldr r0, [sp, 0x48]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08078B86
	b _08078D78
_08078B86:
	ldr r7, [r6, 0x70]
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _08078BB8
	adds r0, r6, 0
	movs r1, 0x1B
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08078BB8
	mov r0, r8
	cmp r0, 0
	bne _08078BA4
	b _08078D78
_08078BA4:
	ldr r0, _08078BB4
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	b _08078D78
	.align 2, 0
_08078BB4: .4byte gUnknown_80FBEA0
_08078BB8:
	movs r5, 0
	ldr r1, [sp, 0x1C]
	cmp r1, 0
	beq _08078BE8
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl RoundUpFixedPoint
	cmp r4, r0
	blt _08078BE0
	movs r5, 0x1
_08078BE0:
	ldr r0, _08078C8C
	cmp r10, r0
	bne _08078BE8
	movs r5, 0x1
_08078BE8:
	cmp r5, 0
	beq _08078CC0
	movs r0, 0xA0
	lsls r0, 1
	adds r5, r7, r0
	ldr r1, [r5]
	str r1, [sp, 0x20]
	subs r0, 0x4
	adds r0, r7
	mov r10, r0
	ldr r0, [r0]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r5]
	bl RoundUpFixedPoint
	movs r1, 0
	str r1, [sp, 0x24]
	cmp r4, r0
	bne _08078C16
	movs r0, 0x1
	str r0, [sp, 0x24]
_08078C16:
	mov r0, sp
	ldr r1, [sp, 0x1C]
	bl sub_80943A0
	ldr r2, [sp]
	ldr r1, [r5]
	add r0, sp, 0x4
	bl sub_8094268
	ldr r4, [sp, 0x4]
	str r4, [r5]
	add r0, sp, 0x8
	movs r1, 0xC8
	bl sub_80943A0
	ldr r2, [sp, 0x8]
	add r0, sp, 0xC
	adds r1, r4, 0
	bl sub_8094318
	ldr r0, [sp, 0xC]
	str r0, [r5]
	mov r1, r10
	str r0, [r1]
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _08078C5E
	mov r1, r8
	cmp r1, 0
	beq _08078C5E
	ldr r0, _08078C90
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
_08078C5E:
	ldr r0, [sp, 0x20]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl RoundUpFixedPoint
	cmp r4, r0
	bne _08078C9C
	ldr r0, _08078C94
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	mov r0, r8
	cmp r0, 0
	beq _08078D72
	ldr r0, _08078C98
	b _08078D4E
	.align 2, 0
_08078C8C: .4byte 0x000003e7
_08078C90: .4byte gUnknown_80FBE64
_08078C94: .4byte gAvailablePokemonNames
_08078C98: .4byte gUnknown_80FBDF0
_08078C9C:
	adds r0, r6, 0
	bl sub_8041DB0
	ldr r0, _08078CB8
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	mov r1, r8
	cmp r1, 0
	beq _08078D72
	ldr r0, _08078CBC
	b _08078D4E
	.align 2, 0
_08078CB8: .4byte gAvailablePokemonNames
_08078CBC: .4byte gUnknown_80FBDC4
_08078CC0:
	movs r0, 0x9E
	lsls r0, 1
	adds r5, r7, r0
	ldr r4, [r5]
	add r0, sp, 0x10
	mov r1, r10
	bl sub_80943A0
	ldr r2, [sp, 0x10]
	ldr r1, [r5]
	add r0, sp, 0x14
	bl sub_8094268
	ldr r1, [sp, 0x14]
	str r1, [r5]
	movs r0, 0xA0
	lsls r0, 1
	adds r7, r0
	ldr r2, [r7]
	add r0, sp, 0x18
	bl sub_8094318
	ldr r0, [sp, 0x18]
	str r0, [r5]
	ldr r0, _08078D28
	cmp r10, r0
	bne _08078CFA
	ldr r0, [r7]
	str r0, [r5]
_08078CFA:
	adds r0, r6, 0
	bl nullsub_85
	ldr r0, _08078D2C
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r5]
	bl RoundUpFixedPoint
	cmp r4, r0
	bne _08078D34
	mov r1, r8
	cmp r1, 0
	beq _08078D72
	ldr r0, _08078D30
	b _08078D4E
	.align 2, 0
_08078D28: .4byte 0x000003e7
_08078D2C: .4byte gAvailablePokemonNames
_08078D30: .4byte gUnknown_80FBE14
_08078D34:
	ldr r0, [r5]
	bl RoundUpFixedPoint
	adds r4, r0, 0
	ldr r0, [r7]
	bl RoundUpFixedPoint
	cmp r4, r0
	blt _08078D60
	mov r0, r8
	cmp r0, 0
	beq _08078D72
	ldr r0, _08078D5C
_08078D4E:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	b _08078D72
	.align 2, 0
_08078D5C: .4byte gUnknown_80FBE64
_08078D60:
	mov r1, r8
	cmp r1, 0
	beq _08078D72
	ldr r0, _08078D88
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
_08078D72:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_08078D78:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078D88: .4byte gUnknown_80FBE84
	thumb_func_end sub_8078B5C

	thumb_func_start sub_8078D8C
sub_8078D8C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078E0E
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08078E0E
	ldr r6, [r4, 0x70]
	ldr r0, _08078DF0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xEC
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08078DFC
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _08078DF4
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xED
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_86
	ldr r0, _08078DF8
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078E08
	.align 2, 0
_08078DF0: .4byte gAvailablePokemonNames
_08078DF4: .4byte gUnknown_80F4F1C
_08078DF8: .4byte gUnknown_80FBF68
_08078DFC:
	ldr r0, _08078E14
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08078E08:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078E0E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078E14: .4byte gUnknown_80FBF84
	thumb_func_end sub_8078D8C

	thumb_func_start sub_8078E18
sub_8078E18:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08078E48
	add sp, r4
	mov r10, r0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078F2E
	ldr r7, [r5, 0x70]
	adds r0, r7, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08078E50
	ldr r0, _08078E4C
	b _08078EC0
	.align 2, 0
_08078E48: .4byte 0xfffffe00
_08078E4C: .4byte gUnknown_80FBF04
_08078E50:
	ldr r0, _08078ECC
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	mov r0, sp
	movs r1, 0
	bl sub_803D870
	mov r8, r0
	cmp r0, 0
	beq _08078EBE
	movs r0, 0
	mov r9, r0
	movs r6, 0
_08078E6E:
	mov r0, r8
	bl DungeonRandomCapped
	lsls r0, 3
	add r0, sp
	bl ExtractSpeciesIndex
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r5, 0
	bl sub_8069F54
	lsls r0, 16
	asrs r4, r0, 16
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	cmp r4, r0
	beq _08078EAE
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806AA0C
	lsls r0, 24
	cmp r0, 0
	beq _08078EAE
	adds r0, r4, 0
	bl sub_80687D0
	mov r9, r0
	cmp r0, 0
	bne _08078EB4
_08078EAE:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08078E6E
_08078EB4:
	cmp r6, 0x14
	beq _08078EBE
	mov r2, r9
	cmp r2, 0
	bne _08078ED4
_08078EBE:
	ldr r0, _08078ED0
_08078EC0:
	ldr r2, [r0]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
	b _08078F2E
	.align 2, 0
_08078ECC: .4byte gAvailablePokemonNames
_08078ED0: .4byte gUnknown_80FBEE4
_08078ED4:
	strh r4, [r7, 0x4]
	mov r0, r9
	str r0, [r5, 0x64]
	adds r1, r7, 0
	adds r1, 0xE4
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, _08078F44
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xE5
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_806CF98
	adds r0, r5, 0
	bl nullsub_87
	adds r0, r5, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_806CCB4
	ldr r0, _08078F48
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	bl CopyCyanSpeciesNametoBuffer
	ldr r0, _08078F4C
	ldr r2, [r0]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08078F2E:
	movs r3, 0x80
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
_08078F44: .4byte gUnknown_80F4EFC
_08078F48: .4byte gUnknown_202DFE8
_08078F4C: .4byte gUnknown_80FBEC0
	thumb_func_end sub_8078E18

	thumb_func_start sub_8078F50
sub_8078F50:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08078FD2
	ldr r0, [r4, 0x70]
	adds r7, r0, 0
	adds r5, r7, 0
	adds r5, 0xE4
	ldrb r0, [r5]
	cmp r0, 0x2
	bne _08078F78
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A7C8
_08078F78:
	ldr r0, _08078FB4
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r5]
	cmp r0, 0x3
	beq _08078FC0
	movs r0, 0x3
	strb r0, [r5]
	ldr r1, _08078FB8
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xE5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_88
	ldr r0, _08078FBC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08078FCC
	.align 2, 0
_08078FB4: .4byte gAvailablePokemonNames
_08078FB8: .4byte gUnknown_80F4F04
_08078FBC: .4byte gUnknown_80FBF28
_08078FC0:
	ldr r0, _08078FD8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08078FCC:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08078FD2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078FD8: .4byte gUnknown_80FBF50
	thumb_func_end sub_8078F50

	thumb_func_start sub_8078FDC
sub_8078FDC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r2, 16
	asrs r7, r2, 16
	mov r10, r7
	movs r0, 0
	mov r8, r0
	mov r9, r0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080790B6
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _080790B6
	ldr r5, [r4, 0x70]
	ldr r0, _08079064
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r0, 0xA
	ble _0807902E
	movs r0, 0xA
	strh r0, [r5, 0x26]
	movs r0, 0x1
	mov r8, r0
_0807902E:
	mov r1, r8
	cmp r1, 0
	beq _0807904C
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_8041DD8
	ldr r0, _08079068
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0x1
	mov r9, r0
_0807904C:
	adds r5, 0xF5
	ldrb r0, [r5]
	cmp r0, 0
	beq _08079070
	ldr r0, _0807906C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080790B6
	.align 2, 0
_08079064: .4byte gAvailablePokemonNames
_08079068: .4byte gUnknown_80FC000
_0807906C: .4byte gUnknown_80FBFB8
_08079070:
	mov r1, r9
	cmp r1, 0
	bne _0807907E
	adds r0, r4, 0
	mov r1, r10
	bl sub_8041DD8
_0807907E:
	adds r0, r4, 0
	movs r1, 0xE
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _080790A0
	ldr r0, _0807909C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080790B0
	.align 2, 0
_0807909C: .4byte gUnknown_80FBFD8
_080790A0:
	movs r0, 0x1
	strb r0, [r5]
	ldr r0, _080790C4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080790B0:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080790B6:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080790C4: .4byte gUnknown_80FBF9C
	thumb_func_end sub_8078FDC

	thumb_func_start sub_80790C8
sub_80790C8:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079134
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08079134
	ldr r6, _0807911C
	ldr r0, [r6]
	ldr r1, _08079120
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08079128
	adds r0, r4, 0
	bl nullsub_89
	ldr r0, [r6]
	ldr r1, _08079120
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
	ldr r0, _08079124
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079134
	.align 2, 0
_0807911C: .4byte gDungeonGlobalData
_08079120: .4byte 0x00000676
_08079124: .4byte gUnknown_80FC028
_08079128:
	ldr r0, _0807913C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079134:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807913C: .4byte gUnknown_80FC054
	thumb_func_end sub_80790C8

	thumb_func_start BlindTarget
BlindTarget:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080791CE
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _080791CE
	ldr r6, [r4, 0x70]
	ldr r0, _080791B0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xE8
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _080791BC
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _080791B4
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xE9
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041E0C
	ldr r0, _080791B8
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0x31
	bl sub_803E46C
	bl sub_8049ED4
	bl sub_8040A84
	b _080791C8
	.align 2, 0
_080791B0: .4byte gAvailablePokemonNames
_080791B4: .4byte gUnknown_80F4F08
_080791B8: .4byte gUnknown_80FB7F4
_080791BC:
	ldr r0, _080791D4
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_080791C8:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080791CE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080791D4: .4byte gUnknown_80FB810
	thumb_func_end BlindTarget

	thumb_func_start sub_80791D8
sub_80791D8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079266
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_80716E8
	lsls r0, 24
	cmp r0, 0
	bne _08079266
	ldr r7, [r4, 0x70]
	ldr r0, _08079248
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r6, r7, 0
	adds r6, 0xE8
	ldrb r0, [r6]
	cmp r0, 0x2
	beq _08079254
	adds r0, r4, 0
	bl sub_8041E1C
	ldr r0, _0807924C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0x2
	strb r0, [r6]
	ldr r1, _08079250
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r0, 0x1
	adds r1, r7, 0
	adds r1, 0xE9
	strb r0, [r1]
	movs r0, 0x1
	bl sub_803F580
	bl sub_8049ED4
	bl sub_8040A84
	b _08079260
	.align 2, 0
_08079248: .4byte gAvailablePokemonNames
_0807924C: .4byte gUnknown_80FB834
_08079250: .4byte gUnknown_80F4F0C
_08079254:
	ldr r0, _0807926C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079260:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079266:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807926C: .4byte gUnknown_80FB85C
	thumb_func_end sub_80791D8

	thumb_func_start RestoreVisionTarget
RestoreVisionTarget:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080792EE
	ldr r5, [r4, 0x70]
	ldr r0, _080792D0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xE8
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _080792DC
	movs r0, 0x3
	strb r0, [r1]
	ldr r1, _080792D4
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xE9
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041E3C
	ldr r0, _080792D8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0x31
	bl sub_803E46C
	bl sub_8049ED4
	bl sub_8040A84
	b _080792E8
	.align 2, 0
_080792D0: .4byte gAvailablePokemonNames
_080792D4: .4byte gUnknown_80F4F10
_080792D8: .4byte gUnknown_80FB880
_080792DC:
	ldr r0, _080792F4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080792E8:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080792EE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080792F4: .4byte gUnknown_80FB89C
	thumb_func_end RestoreVisionTarget

	thumb_func_start sub_80792F8
sub_80792F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r10, r0
	adds r6, r1, 0
	mov r9, r2
	movs r0, 0
	mov r8, r0
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807939A
	ldr r0, [r6, 0x70]
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r0, r1
	adds r5, r4, 0
	movs r7, 0x3
_08079326:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807935E
	ldrb r0, [r4, 0x4]
	str r0, [sp]
	adds r0, r5, 0
	bl GetMoveMaxPP
	str r0, [sp, 0x4]
	ldr r1, [sp]
	ldr r0, [sp, 0x4]
	cmp r1, r0
	bge _0807935E
	ldr r0, [sp]
	add r0, r9
	str r0, [sp]
	ldr r1, [sp]
	ldr r0, [sp, 0x4]
	cmp r1, r0
	ble _08079356
	ldr r0, [sp, 0x4]
	str r0, [sp]
_08079356:
	ldr r0, [sp]
	strb r0, [r4, 0x4]
	movs r0, 0x1
	mov r8, r0
_0807935E:
	adds r4, 0x8
	adds r5, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _08079326
	mov r1, r8
	cmp r1, 0
	beq _08079388
	adds r0, r6, 0
	bl sub_8041E4C
	ldr r0, _08079384
	ldr r2, [r0]
	mov r0, r10
	adds r1, r6, 0
	bl sub_80522F4
	b _08079394
	.align 2, 0
_08079384: .4byte gUnknown_80FDBD0
_08079388:
	ldr r0, _080793AC
	ldr r2, [r0]
	mov r0, r10
	adds r1, r6, 0
	bl sub_80522F4
_08079394:
	adds r0, r6, 0
	bl DungeonEntityUpdateStatusSprites
_0807939A:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080793AC: .4byte gUnknown_80FDBF0
	thumb_func_end sub_80792F8

	thumb_func_start sub_80793B0
sub_80793B0:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079416
	ldr r0, _080793FC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	ldrb r0, [r1, 0x14]
	adds r2, r0, 0
	adds r0, r2, r5
	cmp r0, 0xFE
	ble _080793DE
	movs r0, 0xFF
_080793DE:
	strb r0, [r1, 0x14]
	lsls r0, 24
	lsrs r0, 24
	cmp r2, r0
	bcs _08079404
	adds r0, r4, 0
	bl sub_8041E60
	ldr r0, _08079400
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079410
	.align 2, 0
_080793FC: .4byte gAvailablePokemonNames
_08079400: .4byte gUnknown_80FC33C
_08079404:
	ldr r0, _0807941C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079410:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079416:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807941C: .4byte gUnknown_80FC360
	thumb_func_end sub_80793B0

	thumb_func_start sub_8079420
sub_8079420:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079486
	ldr r0, _0807946C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	ldrb r0, [r1, 0x15]
	adds r2, r0, 0
	adds r0, r2, r5
	cmp r0, 0xFE
	ble _0807944E
	movs r0, 0xFF
_0807944E:
	strb r0, [r1, 0x15]
	lsls r0, 24
	lsrs r0, 24
	cmp r2, r0
	bcs _08079474
	adds r0, r4, 0
	bl sub_8041E74
	ldr r0, _08079470
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079480
	.align 2, 0
_0807946C: .4byte gAvailablePokemonNames
_08079470: .4byte gUnknown_80FC388
_08079474:
	ldr r0, _0807948C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079480:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079486:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807948C: .4byte gUnknown_80FC3B4
	thumb_func_end sub_8079420

	thumb_func_start sub_8079490
sub_8079490:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080794F6
	ldr r0, _080794DC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	ldrb r0, [r1, 0x16]
	adds r2, r0, 0
	adds r0, r2, r5
	cmp r0, 0xFE
	ble _080794BE
	movs r0, 0xFF
_080794BE:
	strb r0, [r1, 0x16]
	lsls r0, 24
	lsrs r0, 24
	cmp r2, r0
	bcs _080794E4
	adds r0, r4, 0
	bl sub_8041E84
	ldr r0, _080794E0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080794F0
	.align 2, 0
_080794DC: .4byte gAvailablePokemonNames
_080794E0: .4byte gUnknown_80FC3D8
_080794E4:
	ldr r0, _080794FC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080794F0:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080794F6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080794FC: .4byte gUnknown_80FC3FC
	thumb_func_end sub_8079490

	thumb_func_start sub_8079500
sub_8079500:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079566
	ldr r0, _0807954C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	ldrb r0, [r1, 0x17]
	adds r2, r0, 0
	adds r0, r2, r5
	cmp r0, 0xFE
	ble _0807952E
	movs r0, 0xFF
_0807952E:
	strb r0, [r1, 0x17]
	lsls r0, 24
	lsrs r0, 24
	cmp r2, r0
	bcs _08079554
	adds r0, r4, 0
	bl sub_8041E94
	ldr r0, _08079550
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079560
	.align 2, 0
_0807954C: .4byte gAvailablePokemonNames
_08079550: .4byte gUnknown_80FC428
_08079554:
	ldr r0, _0807956C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079560:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079566:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807956C: .4byte gUnknown_80FC454
	thumb_func_end sub_8079500

	thumb_func_start sub_8079570
sub_8079570:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r4, [r5, 0x70]
	ldr r0, _080795A0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0xE0
	ldrb r0, [r4]
	cmp r0, 0x1
	beq _080795A8
	movs r0, 0x1
	strb r0, [r4]
	adds r0, r5, 0
	bl sub_8041EA4
	ldr r0, _080795A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _080795B4
	.align 2, 0
_080795A0: .4byte gUnknown_202DFE8
_080795A4: .4byte gUnknown_80FD20C
_080795A8:
	ldr r0, _080795C0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_080795B4:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080795C0: .4byte gUnknown_80FD22C
	thumb_func_end sub_8079570

	thumb_func_start sub_80795C4
sub_80795C4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r4, [r5, 0x70]
	ldr r0, _080795F4
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0xE0
	ldrb r0, [r4]
	cmp r0, 0x2
	beq _080795FC
	movs r0, 0x2
	strb r0, [r4]
	adds r0, r5, 0
	bl sub_8041EB4
	ldr r0, _080795F8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _08079608
	.align 2, 0
_080795F4: .4byte gUnknown_202DFE8
_080795F8: .4byte gUnknown_80FD254
_080795FC:
	ldr r0, _08079614
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_08079608:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079614: .4byte gUnknown_80FD27C
	thumb_func_end sub_80795C4

	thumb_func_start sub_8079618
sub_8079618:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	adds r7, r1, 0
	mov r8, r3
	lsls r2, 24
	lsrs r6, r2, 24
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08079638
	b _08079752
_08079638:
	ldr r5, [r7, 0x70]
	ldr r0, _08079660
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, r6
	bne _08079668
	cmp r6, 0xC
	bne _08079668
	ldr r0, _08079664
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _08079752
	.align 2, 0
_08079660: .4byte gAvailablePokemonNames
_08079664: .4byte gUnknown_80FC074
_08079668:
	adds r0, r5, 0
	adds r0, 0xC0
	strb r6, [r0]
	movs r4, 0
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r5, r1
	subs r2, r6, 0x7
	b _0807968A
_0807967A:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08079694
	lsls r0, r4, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r0, r5, r0
_0807968A:
	cmp r0, r8
	bne _0807967A
	adds r0, r5, 0
	adds r0, 0xC2
	strb r4, [r0]
_08079694:
	movs r1, 0xA5
	lsls r1, 1
	adds r0, r5, r1
	movs r1, 0x1
	strb r1, [r0]
	movs r4, 0
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080796B2
	adds r0, r5, 0
	adds r0, 0xFF
	strb r1, [r0]
	movs r4, 0x1
	b _080796C6
_080796B2:
	adds r0, r6, 0
	subs r0, 0x9
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080796C6
	adds r1, r5, 0
	adds r1, 0xFF
	movs r0, 0x2
	strb r0, [r1]
_080796C6:
	cmp r6, 0x1
	bne _080796E4
	ldr r1, _08079718
	adds r0, r7, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r2, r5, 0
	adds r2, 0xC1
	movs r1, 0
	strb r0, [r2]
	adds r0, r5, 0
	adds r0, 0xA0
	str r1, [r0]
_080796E4:
	cmp r6, 0xC
	bne _080796FA
	ldr r1, _0807971C
	adds r0, r7, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC1
	strb r0, [r1]
_080796FA:
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_8041BD0
	mov r0, r9
	adds r1, r7, 0
	ldr r2, [sp, 0x1C]
	bl sub_80522F4
	adds r0, r7, 0
	bl DungeonEntityUpdateStatusSprites
	movs r4, 0
	ldr r6, _08079720
	b _0807972C
	.align 2, 0
_08079718: .4byte gUnknown_80F4E9C
_0807971C: .4byte gUnknown_80F4EA0
_08079720: .4byte 0x0000c7ff
_08079724:
	movs r0, 0x53
	bl sub_803E46C
	adds r4, 0x1
_0807972C:
	ldr r0, _08079760
	cmp r4, r0
	bgt _08079752
	movs r1, 0x1
	adds r0, r5, 0
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807974E
	movs r1, 0xBA
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, 0
	cmp r0, r6
	ble _0807974E
	movs r1, 0x1
_0807974E:
	cmp r1, 0
	beq _08079724
_08079752:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08079760: .4byte 0x0000018f
	thumb_func_end sub_8079618

	thumb_func_start sub_8079764
sub_8079764:
	push {r4,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807979A
	ldr r2, [r4, 0x70]
	adds r3, r2, 0
	adds r3, 0xC0
	ldrb r0, [r3]
	cmp r0, 0x1
	beq _08079794
	cmp r0, 0xC
	beq _08079794
	movs r1, 0
	strb r1, [r3]
	movs r3, 0xA5
	lsls r3, 1
	adds r0, r2, r3
	strb r1, [r0]
	adds r0, r2, 0
	adds r0, 0xFF
	strb r1, [r0]
_08079794:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807979A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8079764

	thumb_func_start sub_80797A0
sub_80797A0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r7, r2, 24
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079822
	ldr r6, [r4, 0x70]
	ldr r0, _080797E0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r5, r6, 0
	adds r5, 0xC4
	ldrb r0, [r5]
	cmp r0, r7
	bne _080797E8
	ldr r0, _080797E4
	ldr r2, [r0]
	mov r0, r8
	adds r1, r4, 0
	bl sub_80522F4
	b _08079822
	.align 2, 0
_080797E0: .4byte gAvailablePokemonNames
_080797E4: .4byte gUnknown_80FB10C
_080797E8:
	adds r0, r4, 0
	bl nullsub_57
	ldrb r0, [r5]
	cmp r0, 0x4
	beq _0807980A
	cmp r0, 0xA
	beq _0807980A
	ldr r1, _0807982C
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xC5
	strb r0, [r1]
_0807980A:
	adds r0, r6, 0
	adds r0, 0xC4
	strb r7, [r0]
	ldr r0, _08079830
	ldr r2, [r0]
	mov r0, r8
	adds r1, r4, 0
	bl sub_80522F4
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079822:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807982C: .4byte gUnknown_80F4E98
_08079830: .4byte gUnknown_80FB0E0
	thumb_func_end sub_80797A0

	thumb_func_start sub_8079834
sub_8079834:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080798A6
	ldr r5, [r4, 0x70]
	ldr r0, _08079888
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x2
	beq _08079894
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, _0807988C
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_58
	ldr r0, _08079890
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080798A0
	.align 2, 0
_08079888: .4byte gAvailablePokemonNames
_0807988C: .4byte gUnknown_80F4E88
_08079890: .4byte gUnknown_80FB048
_08079894:
	ldr r0, _080798AC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_080798A0:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_080798A6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080798AC: .4byte gUnknown_80FB074
	thumb_func_end sub_8079834

	thumb_func_start sub_80798B0
sub_80798B0:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079922
	ldr r5, [r4, 0x70]
	ldr r0, _08079904
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0xE
	beq _08079910
	movs r0, 0xE
	strb r0, [r1]
	ldr r1, _08079908
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_59
	ldr r0, _0807990C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0807991C
	.align 2, 0
_08079904: .4byte gAvailablePokemonNames
_08079908: .4byte gUnknown_80F4E8C
_0807990C: .4byte gUnknown_80FB09C
_08079910:
	ldr r0, _08079928
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807991C:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079922:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079928: .4byte gUnknown_80FB0C4
	thumb_func_end sub_80798B0

	thumb_func_start sub_807992C
sub_807992C:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807999E
	ldr r5, [r4, 0x70]
	ldr r0, _08079980
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x6
	beq _0807998C
	movs r0, 0x6
	strb r0, [r1]
	ldr r1, _08079984
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8041B34
	ldr r0, _08079988
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079998
	.align 2, 0
_08079980: .4byte gAvailablePokemonNames
_08079984: .4byte gUnknown_80F4EB4
_08079988: .4byte gUnknown_80FAE1C
_0807998C:
	ldr r0, _080799A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079998:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807999E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080799A4: .4byte gUnknown_80FAE3C
	thumb_func_end sub_807992C

	thumb_func_start sub_80799A8
sub_80799A8:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079A1A
	ldr r5, [r4, 0x70]
	ldr r0, _080799FC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x5
	beq _08079A08
	movs r0, 0x5
	strb r0, [r1]
	ldr r1, _08079A00
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_60
	ldr r0, _08079A04
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079A14
	.align 2, 0
_080799FC: .4byte gAvailablePokemonNames
_08079A00: .4byte gUnknown_80F4E90
_08079A04: .4byte gUnknown_80FAF5C
_08079A08:
	ldr r0, _08079A20
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079A14:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079A1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079A20: .4byte gUnknown_80FAF8C
	thumb_func_end sub_80799A8

	thumb_func_start sub_8079A24
sub_8079A24:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079A96
	ldr r5, [r4, 0x70]
	ldr r0, _08079A78
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x3
	beq _08079A84
	movs r0, 0x3
	strb r0, [r1]
	ldr r1, _08079A7C
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_61
	ldr r0, _08079A80
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079A90
	.align 2, 0
_08079A78: .4byte gAvailablePokemonNames
_08079A7C: .4byte gUnknown_80F4E84
_08079A80: .4byte gUnknown_80FB130
_08079A84:
	ldr r0, _08079A9C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079A90:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079A96:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079A9C: .4byte gUnknown_80FB160
	thumb_func_end sub_8079A24

	thumb_func_start sub_8079AA0
sub_8079AA0:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079B12
	ldr r5, [r4, 0x70]
	ldr r0, _08079AF4
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08079B00
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _08079AF8
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_62
	ldr r0, _08079AFC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079B0C
	.align 2, 0
_08079AF4: .4byte gAvailablePokemonNames
_08079AF8: .4byte gUnknown_80F4E80
_08079AFC: .4byte gUnknown_80FB17C
_08079B00:
	ldr r0, _08079B18
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079B0C:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079B12:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079B18: .4byte gUnknown_80FB1A8
	thumb_func_end sub_8079AA0

	thumb_func_start sub_8079B1C
sub_8079B1C:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079B98
	adds r0, r4, 0
	bl nullsub_63
	ldr r5, [r4, 0x70]
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x7
	beq _08079B7C
	movs r0, 0x7
	strb r0, [r1]
	ldr r1, _08079B70
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	ldr r0, _08079B74
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08079B78
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079B92
	.align 2, 0
_08079B70: .4byte gUnknown_80F4ED4
_08079B74: .4byte gAvailablePokemonNames
_08079B78: .4byte gUnknown_80FB9B0
_08079B7C:
	ldr r0, _08079BA0
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08079BA4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079B92:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079B98:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079BA0: .4byte gAvailablePokemonNames
_08079BA4: .4byte gUnknown_80FB9D8
	thumb_func_end sub_8079B1C

	thumb_func_start sub_8079BA8
sub_8079BA8:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079C1A
	ldr r5, [r4, 0x70]
	ldr r0, _08079BFC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x8
	beq _08079C08
	movs r0, 0x8
	strb r0, [r1]
	ldr r1, _08079C00
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_64
	ldr r0, _08079C04
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079C14
	.align 2, 0
_08079BFC: .4byte gAvailablePokemonNames
_08079C00: .4byte gUnknown_80F4EE8
_08079C04: .4byte gUnknown_80FBAC0
_08079C08:
	ldr r0, _08079C20
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079C14:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079C1A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079C20: .4byte gUnknown_80FBAE4
	thumb_func_end sub_8079BA8

	thumb_func_start sub_8079C24
sub_8079C24:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079C96
	ldr r5, [r4, 0x70]
	ldr r0, _08079C78
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0x9
	beq _08079C84
	movs r0, 0x9
	strb r0, [r1]
	ldr r1, _08079C7C
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_65
	ldr r0, _08079C80
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079C90
	.align 2, 0
_08079C78: .4byte gAvailablePokemonNames
_08079C7C: .4byte gUnknown_80F4EF8
_08079C80: .4byte gUnknown_80FBBF0
_08079C84:
	ldr r0, _08079C9C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079C90:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079C96:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079C9C: .4byte gUnknown_80FBC14
	thumb_func_end sub_8079C24

	thumb_func_start sub_8079CA0
sub_8079CA0:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079D12
	ldr r5, [r4, 0x70]
	ldr r0, _08079CF4
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0xB
	beq _08079D00
	movs r0, 0xB
	strb r0, [r1]
	ldr r1, _08079CF8
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_66
	ldr r0, _08079CFC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079D0C
	.align 2, 0
_08079CF4: .4byte gAvailablePokemonNames
_08079CF8: .4byte gUnknown_80F4F18
_08079CFC: .4byte gUnknown_80FBC38
_08079D00:
	ldr r0, _08079D18
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079D0C:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079D12:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079D18: .4byte gUnknown_80FBC5C
	thumb_func_end sub_8079CA0

	thumb_func_start sub_8079D1C
sub_8079D1C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079DAE
	ldr r6, [r4, 0x70]
	adds r0, r4, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08079D50
	ldr r0, _08079D4C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079DAE
	.align 2, 0
_08079D4C: .4byte gPtrForecastPreventsConversion2Message
_08079D50:
	ldr r0, _08079D90
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r6, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0xC
	beq _08079D9C
	movs r0, 0xC
	strb r0, [r1]
	ldr r1, _08079D94
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r6, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_67
	ldr r0, _08079D98
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079DA8
	.align 2, 0
_08079D90: .4byte gAvailablePokemonNames
_08079D94: .4byte gUnknown_80F4F20
_08079D98: .4byte gUnknown_80FBC7C
_08079D9C:
	ldr r0, _08079DB4
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079DA8:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079DAE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079DB4: .4byte gUnknown_80FBCA4
	thumb_func_end sub_8079D1C

	thumb_func_start sub_8079DB8
sub_8079DB8:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079E2A
	ldr r5, [r4, 0x70]
	ldr r0, _08079E0C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r1, r5, 0
	adds r1, 0xC4
	ldrb r0, [r1]
	cmp r0, 0xD
	beq _08079E18
	movs r0, 0xD
	strb r0, [r1]
	ldr r1, _08079E10
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r0, 0x1
	adds r1, r5, 0
	adds r1, 0xC5
	strb r0, [r1]
	adds r0, r4, 0
	bl nullsub_68
	ldr r0, _08079E14
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08079E24
	.align 2, 0
_08079E0C: .4byte gAvailablePokemonNames
_08079E10: .4byte gUnknown_80F4F24
_08079E14: .4byte gUnknown_80FBCC8
_08079E18:
	ldr r0, _08079E30
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079E24:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_08079E2A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08079E30: .4byte gUnknown_80FBCF0
	thumb_func_end sub_8079DB8

	thumb_func_start sub_8079E34
sub_8079E34:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	movs r6, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08079F0E
	ldr r0, [r5, 0x70]
	mov r12, r0
	movs r4, 0
	movs r7, 0xA
_08079E5C:
	lsls r2, r4, 1
	mov r0, r12
	adds r0, 0x1C
	adds r1, r0, r2
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0xA
	beq _08079E70
	strh r7, [r1]
	movs r6, 0x1
_08079E70:
	mov r0, r12
	adds r0, 0x20
	adds r1, r0, r2
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0xA
	beq _08079E82
	strh r7, [r1]
	movs r6, 0x1
_08079E82:
	mov r0, r12
	adds r0, 0x24
	adds r1, r0, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0xA
	beq _08079E94
	strh r7, [r1]
	movs r6, 0x1
_08079E94:
	lsls r3, r4, 2
	mov r0, r12
	adds r0, 0x2C
	adds r1, r0, r3
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 1
	cmp r0, r2
	beq _08079EAA
	str r2, [r1]
	movs r6, 0x1
_08079EAA:
	mov r0, r12
	adds r0, 0x34
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, r2
	beq _08079EBA
	str r2, [r1]
	movs r6, 0x1
_08079EBA:
	adds r4, 0x1
	cmp r4, 0x1
	ble _08079E5C
	cmp r6, 0
	beq _08079ECC
	adds r0, r5, 0
	bl sub_80420C8
	b _08079ED8
_08079ECC:
	mov r3, r9
	cmp r3, 0
	beq _08079ED8
	adds r0, r5, 0
	bl sub_80420C8
_08079ED8:
	ldr r0, _08079EF4
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r6, 0
	beq _08079EFC
	ldr r0, _08079EF8
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	b _08079F08
	.align 2, 0
_08079EF4: .4byte gAvailablePokemonNames
_08079EF8: .4byte gUnknown_80FBD18
_08079EFC:
	ldr r0, _08079F1C
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
_08079F08:
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_08079F0E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08079F1C: .4byte gUnknown_80FBD3C
	thumb_func_end sub_8079E34

	thumb_func_start sub_8079F20
sub_8079F20:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	movs r0, 0
	mov r8, r0
	mov r9, r0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08079F50
	b _0807A0B8
_08079F50:
	ldr r7, [r4, 0x70]
	adds r0, r4, 0
	bl HasNegativeStatus
	lsls r0, 24
	cmp r0, 0
	beq _08079FF2
	movs r2, 0x1
	mov r8, r2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807A124
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08079F7C
	b _0807A0B8
_08079F7C:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807A290
	adds r0, r5, 0
	adds r1, r4, 0
	bl SendImmobilizeEndMessage
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807A400
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_807A5D0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807A6C8
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807A734
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807A888
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807A924
	adds r1, r7, 0
	adds r1, 0xFD
	ldrb r0, [r1]
	cmp r0, 0
	beq _08079FD8
	mov r0, r9
	strb r0, [r1]
	ldr r0, _0807A08C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079FD8:
	adds r1, r7, 0
	adds r1, 0xF5
	ldrb r0, [r1]
	cmp r0, 0
	beq _08079FF2
	mov r2, r9
	strb r2, [r1]
	ldr r0, _0807A090
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08079FF2:
	adds r0, r4, 0
	bl GetMovementSpeed
	adds r6, r0, 0
	movs r1, 0
	movs r3, 0x4
	ldr r2, _0807A094
	adds r0, r7, r2
_0807A002:
	strb r1, [r0]
	subs r0, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _0807A002
	adds r0, r4, 0
	bl GetMovementSpeed
	cmp r6, r0
	beq _0807A032
	movs r0, 0x1
	mov r8, r0
	ldr r1, _0807A098
	movs r2, 0x82
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807A032:
	movs r6, 0x1
	movs r0, 0x8C
	lsls r0, 1
	adds r2, r7, r0
	movs r7, 0xFE
	movs r3, 0x3
_0807A03E:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0807A05E
	ldrb r1, [r2, 0x1]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0807A05E
	movs r0, 0x1
	mov r8, r0
	mov r9, r0
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2, 0x1]
_0807A05E:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0807A03E
	mov r2, r8
	cmp r2, 0
	beq _0807A0A0
	ldr r0, [sp]
	cmp r0, 0
	beq _0807A078
	adds r0, r4, 0
	bl sub_80420C8
_0807A078:
	mov r2, r9
	cmp r2, 0
	beq _0807A0B2
	ldr r0, _0807A09C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0807A0B2
	.align 2, 0
_0807A08C: .4byte gUnknown_8100594
_0807A090: .4byte gPtrExposedWoreOffMessage
_0807A094: .4byte 0x00000111
_0807A098: .4byte gUnknown_80FA124
_0807A09C: .4byte gPtrSealedMoveReleasedMessage
_0807A0A0:
	mov r0, r10
	cmp r0, 0
	bne _0807A0B2
	ldr r0, _0807A0C8
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807A0B2:
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807A0B8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A0C8: .4byte gUnknown_81004E8
	thumb_func_end sub_8079F20

	thumb_func_start sub_807A0CC
sub_807A0CC:
	push {r4-r7,lr}
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A11E
	ldr r4, [r5, 0x70]
	adds r0, r4, 0
	movs r1, 0
	bl sub_806BFC0
	adds r1, r4, 0
	adds r1, 0xFD
	movs r0, 0
	strb r0, [r1]
	subs r1, 0x8
	strb r0, [r1]
	movs r7, 0x1
	movs r6, 0xFE
	movs r0, 0x8C
	lsls r0, 1
	adds r2, r4, r0
	movs r3, 0x3
_0807A0FE:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0807A110
	ldrb r1, [r2, 0x1]
	adds r0, r6, 0
	ands r0, r1
	strb r0, [r2, 0x1]
_0807A110:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0807A0FE
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_0807A11E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807A0CC

	thumb_func_start sub_807A124
sub_807A124:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	movs r0, 0
	mov r9, r0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807A14E
	b _0807A27C
_0807A14E:
	ldr r7, [r5, 0x70]
	ldr r0, _0807A170
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x6
	bls _0807A166
	b _0807A260
_0807A166:
	lsls r0, 2
	ldr r1, _0807A174
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A170: .4byte gAvailablePokemonNames
_0807A174: .4byte _0807A178
	.align 2, 0
_0807A178:
	.4byte _0807A260
	.4byte _0807A194
	.4byte _0807A1A0
	.4byte _0807A1B4
	.4byte _0807A228
	.4byte _0807A1E8
	.4byte _0807A260
_0807A194:
	movs r1, 0x1
	mov r9, r1
	ldr r0, _0807A19C
	b _0807A1A2
	.align 2, 0
_0807A19C: .4byte gUnknown_80FA6E8
_0807A1A0:
	ldr r0, _0807A1B0
_0807A1A2:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _0807A260
	.align 2, 0
_0807A1B0: .4byte gUnknown_80FA708
_0807A1B4:
	movs r2, 0x1
	mov r9, r2
	ldr r0, _0807A1DC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	mov r0, r8
	cmp r0, 0
	beq _0807A260
	ldr r0, _0807A1E0
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _0807A1E4
	adds r0, r5, 0
	movs r2, 0x8
	bl sub_806F324
	b _0807A260
	.align 2, 0
_0807A1DC: .4byte gUnknown_80FA70C
_0807A1E0: .4byte gUnknown_80F4F78
_0807A1E4: .4byte 0x0000020f
_0807A1E8:
	movs r0, 0x1
	mov r9, r0
	ldr r0, _0807A220
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	ldr r0, _0807A224
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r4, 0
	str r4, [sp]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r3, 0
	bl HealTargetHP
	adds r0, r7, 0
	adds r0, 0xA8
	strb r4, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8079F20
	b _0807A260
	.align 2, 0
_0807A220: .4byte gUnknown_80FA710
_0807A224: .4byte gUnknown_80F4F7A
_0807A228:
	cmp r4, 0
	beq _0807A254
	adds r1, r7, 0
	adds r1, 0xA8
	movs r0, 0
	strb r0, [r1]
	ldr r1, _0807A250
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r2, 0x1
	adds r0, r6, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_8075C58
	b _0807A27C
	.align 2, 0
_0807A250: .4byte gUnknown_80F4F2C
_0807A254:
	ldr r0, _0807A28C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807A260:
	adds r1, r7, 0
	adds r1, 0xA8
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	mov r2, r9
	cmp r2, 0
	beq _0807A27C
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_806CE68
_0807A27C:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A28C: .4byte gUnknown_80FA734
	thumb_func_end sub_807A124

	thumb_func_start sub_807A290
sub_807A290:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A31A
	ldr r6, [r4, 0x70]
	ldr r0, _0807A2C4
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _0807A30C
	lsls r0, 2
	ldr r1, _0807A2C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A2C4: .4byte gAvailablePokemonNames
_0807A2C8: .4byte _0807A2CC
	.align 2, 0
_0807A2CC:
	.4byte _0807A30C
	.4byte _0807A300
	.4byte _0807A2E4
	.4byte _0807A2E4
	.4byte _0807A2EC
	.4byte _0807A30C
_0807A2E4:
	ldr r0, _0807A2E8
	b _0807A2EE
	.align 2, 0
_0807A2E8: .4byte gUnknown_80FA8A8
_0807A2EC:
	ldr r0, _0807A2FC
_0807A2EE:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0807A30C
	.align 2, 0
_0807A2FC: .4byte gUnknown_80FA868
_0807A300:
	ldr r0, _0807A320
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807A30C:
	adds r1, r6, 0
	adds r1, 0xAC
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807A31A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A320: .4byte gUnknown_80FA888
	thumb_func_end sub_807A290

	thumb_func_start SendImmobilizeEndMessage
SendImmobilizeEndMessage:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r7, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A3F4
	ldr r6, [r4, 0x70]
	ldr r0, _0807A358
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _0807A3DC
	lsls r0, 2
	ldr r1, _0807A35C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A358: .4byte gAvailablePokemonNames
_0807A35C: .4byte _0807A360
	.align 2, 0
_0807A360:
	.4byte _0807A3DC
	.4byte _0807A384
	.4byte _0807A3A0
	.4byte _0807A3B4
	.4byte _0807A3B4
	.4byte _0807A3A0
	.4byte _0807A3D0
	.4byte _0807A398
	.4byte _0807A3DC
_0807A384:
	ldr r0, _0807A394
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r7, 0x1
	b _0807A3DC
	.align 2, 0
_0807A394: .4byte gUnknown_80FA8BC
_0807A398:
	ldr r0, _0807A39C
	b _0807A3A2
	.align 2, 0
_0807A39C: .4byte gUnknown_80FA820
_0807A3A0:
	ldr r0, _0807A3B0
_0807A3A2:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0807A3DC
	.align 2, 0
_0807A3B0: .4byte gUnknown_80FA824
_0807A3B4:
	ldr r0, _0807A3CC
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	adds r0, r6, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
	b _0807A3DC
	.align 2, 0
_0807A3CC: .4byte gUnknown_80FA81C
_0807A3D0:
	ldr r0, _0807A3FC
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807A3DC:
	adds r1, r6, 0
	adds r1, 0xB0
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
	cmp r7, 0
	beq _0807A3F4
	adds r0, r4, 0
	bl sub_8042A74
_0807A3F4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A3FC: .4byte gUnknown_80FABF8
	thumb_func_end SendImmobilizeEndMessage

	thumb_func_start sub_807A400
sub_807A400:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A4BC
	ldr r6, [r5, 0x70]
	ldr r0, _0807A434
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _0807A4A8
	lsls r0, 2
	ldr r1, _0807A438
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A434: .4byte gAvailablePokemonNames
_0807A438: .4byte _0807A43C
	.align 2, 0
_0807A43C:
	.4byte _0807A4A8
	.4byte _0807A49C
	.4byte _0807A460
	.4byte _0807A478
	.4byte _0807A468
	.4byte _0807A470
	.4byte _0807A488
	.4byte _0807A480
	.4byte _0807A4A8
_0807A460:
	ldr r0, _0807A464
	b _0807A48A
	.align 2, 0
_0807A464: .4byte gUnknown_80FA800
_0807A468:
	ldr r0, _0807A46C
	b _0807A48A
	.align 2, 0
_0807A46C: .4byte gUnknown_80FA97C
_0807A470:
	ldr r0, _0807A474
	b _0807A48A
	.align 2, 0
_0807A474: .4byte gUnknown_80FA9DC
_0807A478:
	ldr r0, _0807A47C
	b _0807A48A
	.align 2, 0
_0807A47C: .4byte gUnknown_80FAC38
_0807A480:
	ldr r0, _0807A484
	b _0807A48A
	.align 2, 0
_0807A484: .4byte gUnknown_80FAB90
_0807A488:
	ldr r0, _0807A498
_0807A48A:
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _0807A4A8
	.align 2, 0
_0807A498: .4byte gUnknown_80FAAAC
_0807A49C:
	ldr r0, _0807A4C4
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_0807A4A8:
	adds r1, r6, 0
	adds r1, 0xBC
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
	adds r0, r5, 0
	bl GetMovementSpeed
_0807A4BC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A4C4: .4byte gUnknown_80FAC18
	thumb_func_end sub_807A400

	thumb_func_start sub_807A4C8
sub_807A4C8:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807A4DA
	b _0807A5C4
_0807A4DA:
	ldr r5, [r4, 0x70]
	ldr r0, _0807A4FC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xF
	bhi _0807A5B6
	lsls r0, 2
	ldr r1, _0807A500
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A4FC: .4byte gAvailablePokemonNames
_0807A500: .4byte _0807A504
	.align 2, 0
_0807A504:
	.4byte _0807A5B6
	.4byte _0807A544
	.4byte _0807A54C
	.4byte _0807A554
	.4byte _0807A55C
	.4byte _0807A564
	.4byte _0807A56C
	.4byte _0807A574
	.4byte _0807A57C
	.4byte _0807A584
	.4byte _0807A55C
	.4byte _0807A58C
	.4byte _0807A594
	.4byte _0807A59C
	.4byte _0807A5AC
	.4byte _0807A5B6
_0807A544:
	ldr r0, _0807A548
	b _0807A59E
	.align 2, 0
_0807A548: .4byte gUnknown_80FA638
_0807A54C:
	ldr r0, _0807A550
	b _0807A59E
	.align 2, 0
_0807A550: .4byte gUnknown_80FA69C
_0807A554:
	ldr r0, _0807A558
	b _0807A59E
	.align 2, 0
_0807A558: .4byte gUnknown_80FA658
_0807A55C:
	ldr r0, _0807A560
	b _0807A59E
	.align 2, 0
_0807A560: .4byte gUnknown_80FA67C
_0807A564:
	ldr r0, _0807A568
	b _0807A59E
	.align 2, 0
_0807A568: .4byte gUnknown_80FA6BC
_0807A56C:
	ldr r0, _0807A570
	b _0807A59E
	.align 2, 0
_0807A570: .4byte gUnknown_80FA6D4
_0807A574:
	ldr r0, _0807A578
	b _0807A59E
	.align 2, 0
_0807A578: .4byte gUnknown_80FA9C0
_0807A57C:
	ldr r0, _0807A580
	b _0807A59E
	.align 2, 0
_0807A580: .4byte gUnknown_80FAA68
_0807A584:
	ldr r0, _0807A588
	b _0807A59E
	.align 2, 0
_0807A588: .4byte gUnknown_80FAAC8
_0807A58C:
	ldr r0, _0807A590
	b _0807A59E
	.align 2, 0
_0807A590: .4byte gUnknown_80FAAE8
_0807A594:
	ldr r0, _0807A598
	b _0807A59E
	.align 2, 0
_0807A598: .4byte gUnknown_80FAB08
_0807A59C:
	ldr r0, _0807A5A8
_0807A59E:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _0807A5B6
	.align 2, 0
_0807A5A8: .4byte gUnknown_80FAB28
_0807A5AC:
	ldr r0, _0807A5CC
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_0807A5B6:
	adds r1, r5, 0
	adds r1, 0xC4
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807A5C4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A5CC: .4byte gUnknown_80FAB40
	thumb_func_end sub_807A4C8

	thumb_func_start sub_807A5D0
sub_807A5D0:
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r2, 24
	lsrs r6, r2, 24
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A6B2
	ldr r7, [r5, 0x70]
	ldr r0, _0807A604
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x4
	bhi _0807A6A4
	lsls r0, 2
	ldr r1, _0807A608
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A604: .4byte gAvailablePokemonNames
_0807A608: .4byte _0807A60C
	.align 2, 0
_0807A60C:
	.4byte _0807A6A4
	.4byte _0807A620
	.4byte _0807A668
	.4byte _0807A634
	.4byte _0807A6A4
_0807A620:
	cmp r6, 0x1
	beq _0807A6A4
	ldr r0, _0807A630
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807A6A4
	.align 2, 0
_0807A630: .4byte gUnknown_80FA7BC
_0807A634:
	cmp r6, 0x3
	beq _0807A642
	ldr r0, _0807A658
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_0807A642:
	ldr r0, _0807A65C
	ldr r0, [r0]
	ldr r2, _0807A660
	adds r1, r0, r2
	movs r2, 0
	str r2, [r1]
	ldr r1, _0807A664
	adds r0, r1
	str r2, [r0]
	b _0807A6A4
	.align 2, 0
_0807A658: .4byte gUnknown_80FA7DC
_0807A65C: .4byte gDungeonGlobalData
_0807A660: .4byte 0x00017b30
_0807A664: .4byte 0x00017b3c
_0807A668:
	adds r0, r7, 0
	adds r0, 0xC8
	movs r4, 0
	strb r4, [r0]
	adds r0, r5, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_806CCB4
	ldr r0, _0807A6B8
	ldr r0, [r0]
	ldr r2, _0807A6BC
	adds r0, r2
	strb r4, [r0]
	cmp r6, 0x2
	beq _0807A6A4
	ldr r0, _0807A6C0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807A6C4
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_0807A6A4:
	adds r1, r7, 0
	adds r1, 0xC8
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_0807A6B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A6B8: .4byte gDungeonGlobalData
_0807A6BC: .4byte 0x000037fc
_0807A6C0: .4byte gAvailablePokemonNames
_0807A6C4: .4byte gUnknown_80FA9A0
	thumb_func_end sub_807A5D0

	thumb_func_start sub_807A6C8
sub_807A6C8:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A72A
	ldr r5, [r4, 0x70]
	ldr r0, _0807A6F8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	adds r0, 0xD0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0807A6FC
	cmp r0, 0x1
	ble _0807A716
	cmp r0, 0x2
	beq _0807A70C
	b _0807A716
	.align 2, 0
_0807A6F8: .4byte gAvailablePokemonNames
_0807A6FC:
	ldr r0, _0807A708
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _0807A716
	.align 2, 0
_0807A708: .4byte gUnknown_80FA79C
_0807A70C:
	ldr r0, _0807A730
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_0807A716:
	adds r1, r5, 0
	adds r1, 0xD0
	movs r0, 0
	strb r0, [r1]
	adds r1, 0x8
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807A72A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A730: .4byte gUnknown_80FAA8C
	thumb_func_end sub_807A6C8

	thumb_func_start sub_807A734
sub_807A734:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A7BC
	ldr r5, [r4, 0x70]
	ldr r0, _0807A764
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _0807A7AE
	lsls r0, 2
	ldr r1, _0807A768
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A764: .4byte gAvailablePokemonNames
_0807A768: .4byte _0807A76C
	.align 2, 0
_0807A76C:
	.4byte _0807A7AE
	.4byte _0807A784
	.4byte _0807A78C
	.4byte _0807A794
	.4byte _0807A7A4
	.4byte _0807A7AE
_0807A784:
	ldr r0, _0807A788
	b _0807A796
	.align 2, 0
_0807A788: .4byte gUnknown_80FA8E0
_0807A78C:
	ldr r0, _0807A790
	b _0807A796
	.align 2, 0
_0807A790: .4byte gUnknown_80FA90C
_0807A794:
	ldr r0, _0807A7A0
_0807A796:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _0807A7AE
	.align 2, 0
_0807A7A0: .4byte gUnknown_80FA934
_0807A7A4:
	ldr r0, _0807A7C4
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_0807A7AE:
	adds r1, r5, 0
	adds r1, 0xDC
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807A7BC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A7C4: .4byte gUnknown_80FA95C
	thumb_func_end sub_807A734

	thumb_func_start sub_807A7C8
sub_807A7C8:
	push {r4-r6,lr}
	adds r4, r1, 0
	movs r6, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A87E
	ldr r5, [r4, 0x70]
	ldr r0, _0807A7FC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x4
	bhi _0807A866
	lsls r0, 2
	ldr r1, _0807A800
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A7FC: .4byte gAvailablePokemonNames
_0807A800: .4byte _0807A804
	.align 2, 0
_0807A804:
	.4byte _0807A866
	.4byte _0807A818
	.4byte _0807A834
	.4byte _0807A824
	.4byte _0807A866
_0807A818:
	movs r6, 0x1
	ldr r0, _0807A820
	b _0807A826
	.align 2, 0
_0807A820: .4byte gUnknown_80FA9F4
_0807A824:
	ldr r0, _0807A830
_0807A826:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _0807A866
	.align 2, 0
_0807A830: .4byte gUnknown_80FABBC
_0807A834:
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_8069F54
	strh r0, [r5, 0x4]
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	bl sub_80687D0
	str r0, [r4, 0x64]
	adds r0, r4, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806CCB4
	ldr r0, _0807A884
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_0807A866:
	adds r1, r5, 0
	adds r1, 0xE4
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
	cmp r6, 0
	beq _0807A87E
	movs r0, 0x1
	bl sub_807EC28
_0807A87E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A884: .4byte gUnknown_80FAB6C
	thumb_func_end sub_807A7C8

	thumb_func_start sub_807A888
sub_807A888:
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A918
	ldr r5, [r4, 0x70]
	ldr r0, _0807A8B8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0x4
	bhi _0807A8F6
	lsls r0, 2
	ldr r1, _0807A8BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A8B8: .4byte gAvailablePokemonNames
_0807A8BC: .4byte _0807A8C0
	.align 2, 0
_0807A8C0:
	.4byte _0807A8F6
	.4byte _0807A8D4
	.4byte _0807A8DC
	.4byte _0807A8EC
	.4byte _0807A8F6
_0807A8D4:
	ldr r0, _0807A8D8
	b _0807A8DE
	.align 2, 0
_0807A8D8: .4byte gUnknown_80FAA0C
_0807A8DC:
	ldr r0, _0807A8E8
_0807A8DE:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _0807A8F6
	.align 2, 0
_0807A8E8: .4byte gUnknown_80FAA2C
_0807A8EC:
	ldr r0, _0807A920
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_0807A8F6:
	adds r0, r5, 0
	adds r0, 0xE8
	movs r1, 0
	strb r1, [r0]
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0807A918
	movs r0, 0x31
	bl sub_803E46C
	bl sub_8049ED4
	bl sub_8040A84
_0807A918:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A920: .4byte gUnknown_80FAA48
	thumb_func_end sub_807A888

	thumb_func_start sub_807A924
sub_807A924:
	push {r4,r5,lr}
	adds r5, r1, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807A95C
	ldr r4, [r5, 0x70]
	ldr r0, _0807A964
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0xEC
	ldrb r0, [r4]
	cmp r0, 0x1
	bne _0807A952
	ldr r0, _0807A968
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_0807A952:
	movs r0, 0
	strb r0, [r4]
	adds r0, r5, 0
	bl DungeonEntityUpdateStatusSprites
_0807A95C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A964: .4byte gAvailablePokemonNames
_0807A968: .4byte gUnknown_80FABC0
	thumb_func_end sub_807A924

	thumb_func_start sub_807A96C
sub_807A96C:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r0, [r4, 0x70]
	adds r5, r0, 0
	movs r2, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _0807A988
	adds r0, r6, 0
	bl SendImmobilizeEndMessage
	movs r2, 0x1
_0807A988:
	adds r0, r5, 0
	adds r0, 0xA8
	ldrh r1, [r0]
	ldr r0, _0807A9AC
	cmp r1, r0
	bne _0807A9A2
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_807A124
	movs r2, 0x1
_0807A9A2:
	adds r0, r2, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807A9AC: .4byte 0x00007f01
	thumb_func_end sub_807A96C

	thumb_func_start sub_807A9B0
sub_807A9B0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xA8
	movs r2, 0
	strb r2, [r1]
	adds r0, 0xA9
	strb r2, [r0]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_806A898
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_807A9B0

	thumb_func_start sub_807A9D8
sub_807A9D8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807AA20
	ldr r2, [r4, 0x70]
	adds r3, r2, 0
	adds r3, 0xB0
	ldrb r0, [r3]
	cmp r0, 0x1
	bne _0807AA20
	movs r1, 0
	strb r1, [r3]
	adds r0, r2, 0
	adds r0, 0xB8
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	ldr r0, _0807AA28
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807AA2C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	adds r0, r4, 0
	bl DungeonEntityUpdateStatusSprites
_0807AA20:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807AA28: .4byte gAvailablePokemonNames
_0807AA2C: .4byte gUnknown_80FA8BC
	thumb_func_end sub_807A9D8

	thumb_func_start sub_807AA30
sub_807AA30:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r4, 0
_0807AA3C:
	ldr r0, _0807AAD8
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _0807AADC
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	adds r4, 0x1
	mov r10, r4
	cmp r0, 0
	beq _0807AB22
	ldr r1, [r5, 0x70]
	adds r0, r1, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807AB22
	adds r0, r1, 0
	adds r0, 0xA9
	ldrb r0, [r0]
	cmp r0, 0x7F
	bne _0807AB22
	movs r0, 0
	mov r9, r0
	mov r8, r0
	adds r0, r5, 0
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r7, r0, 24
	movs r6, 0
_0807AA82:
	ldr r0, _0807AAD8
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0807AAE0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807AB00
	adds r0, r4, 0
	movs r1, 0x18
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _0807AB00
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807AABA
	negs r1, r1
_0807AABA:
	cmp r1, 0x1
	bgt _0807AAE4
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807AACE
	negs r1, r1
_0807AACE:
	cmp r1, 0x1
	bgt _0807AAE4
	movs r0, 0x1
	mov r9, r0
	b _0807AB06
	.align 2, 0
_0807AAD8: .4byte gDungeonGlobalData
_0807AADC: .4byte 0x0001358c
_0807AAE0: .4byte 0x0001357c
_0807AAE4:
	adds r0, r4, 0
	movs r1, 0x1D
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0807AB00
	adds r0, r4, 0
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r0, 24
	cmp r7, r0
	beq _0807AB1C
_0807AB00:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0807AA82
_0807AB06:
	mov r2, r8
	cmp r2, 0
	bne _0807AB1C
	mov r0, r9
	cmp r0, 0
	beq _0807AB16
	movs r2, 0x1
	mov r8, r2
_0807AB16:
	mov r0, r8
	cmp r0, 0
	beq _0807AB22
_0807AB1C:
	adds r0, r5, 0
	bl sub_807A9B0
_0807AB22:
	mov r4, r10
	cmp r4, 0xF
	ble _0807AA3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807AA30

	thumb_func_start sub_807AB38
sub_807AB38:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1A8
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, [r2, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0807AB54
	b _0807ADA6
_0807AB54:
	adds r0, r2, 0
	str r2, [sp, 0x1A4]
	bl GetMapTileForDungeonEntity_2
	ldrh r1, [r0]
	movs r0, 0x40
	ands r0, r1
	ldr r2, [sp, 0x1A4]
	cmp r0, 0
	bne _0807AB6A
	b _0807ADA6
_0807AB6A:
	ldr r3, _0807AC10
	ldr r0, [r3]
	ldr r5, _0807AC14
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807AB7A
	b _0807ADA6
_0807AB7A:
	movs r0, 0x1
	strb r0, [r1]
	ldr r3, [r3]
	ldr r1, _0807AC18
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	bne _0807AB8C
	b _0807ADA6
_0807AB8C:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r5, _0807AC1C
	adds r0, r5
	adds r3, r0
	movs r0, 0
	mov r8, r0
	cmp r4, 0
	beq _0807AC20
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	subs r6, r0, 0x4
	adds r0, 0x4
	cmp r6, r0
	ble _0807ABAE
	b _0807ACB4
_0807ABAE:
	movs r4, 0x4
	ldrsh r0, [r2, r4]
	subs r4, r0, 0x4
	adds r0, 0x4
	adds r5, r6, 0x1
	mov r9, r5
	cmp r4, r0
	bgt _0807AC00
	mov r1, r8
	lsls r0, r1, 2
	mov r1, sp
	adds r5, r0, r1
_0807ABC6:
	adds r0, r4, 0
	adds r1, r6, 0
	str r2, [sp, 0x1A4]
	bl GetMapTile_2
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	ldr r2, [sp, 0x1A4]
	cmp r0, 0
	bne _0807ABF4
	ldrh r1, [r1]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0807ABF4
	mov r0, r8
	cmp r0, 0x63
	bgt _0807ABF4
	strh r4, [r5]
	strh r6, [r5, 0x2]
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
_0807ABF4:
	adds r4, 0x1
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	adds r0, 0x4
	cmp r4, r0
	ble _0807ABC6
_0807AC00:
	mov r6, r9
	movs r4, 0x6
	ldrsh r0, [r2, r4]
	adds r0, 0x4
	cmp r6, r0
	ble _0807ABAE
	b _0807ACB4
	.align 2, 0
_0807AC10: .4byte gDungeonGlobalData
_0807AC14: .4byte 0x00000671
_0807AC18: .4byte 0x00003a0c
_0807AC1C: .4byte 0x000104c4
_0807AC20:
	movs r5, 0x4
	ldrsh r0, [r2, r5]
	subs r1, r0, 0x4
	movs r5, 0x2
	ldrsh r4, [r3, r5]
	mov r10, r4
	cmp r10, r1
	bge _0807AC32
	mov r10, r1
_0807AC32:
	adds r1, r0, 0x5
	movs r0, 0x6
	ldrsh r7, [r3, r0]
	cmp r7, r1
	ble _0807AC3E
	adds r7, r1, 0
_0807AC3E:
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	subs r2, r0, 0x4
	movs r4, 0x4
	ldrsh r1, [r3, r4]
	cmp r1, r2
	bge _0807AC4E
	adds r1, r2, 0
_0807AC4E:
	adds r0, 0x5
	movs r5, 0x8
	ldrsh r2, [r3, r5]
	cmp r2, r0
	ble _0807AC5A
	adds r2, r0, 0
_0807AC5A:
	adds r6, r1, 0
	cmp r6, r2
	bge _0807ACB4
_0807AC60:
	mov r4, r10
	adds r0, r6, 0x1
	mov r9, r0
	cmp r4, r7
	bge _0807ACAE
	mov r1, r8
	lsls r0, r1, 2
	mov r1, sp
	adds r5, r0, r1
_0807AC72:
	adds r0, r4, 0
	adds r1, r6, 0
	str r2, [sp, 0x1A4]
	bl GetMapTile_2
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	ldr r2, [sp, 0x1A4]
	cmp r0, 0
	bne _0807ACA8
	ldrh r1, [r1]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0807ACA8
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0807ACA8
	mov r0, r8
	cmp r0, 0x63
	bgt _0807ACA8
	strh r4, [r5]
	strh r6, [r5, 0x2]
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
_0807ACA8:
	adds r4, 0x1
	cmp r4, r7
	blt _0807AC72
_0807ACAE:
	mov r6, r9
	cmp r6, r2
	blt _0807AC60
_0807ACB4:
	ldr r0, _0807AD74
	movs r2, 0
	ldrsh r0, [r0, r2]
	ldr r1, _0807AD78
	movs r4, 0
	ldrsh r1, [r1, r4]
	bl sub_808411C
	adds r7, r0, 0
	cmp r7, r8
	blt _0807ACCC
	mov r7, r8
_0807ACCC:
	movs r6, 0
	cmp r6, r7
	bge _0807ADA0
	mov r10, r6
_0807ACD4:
	mov r0, r8
	bl DungeonRandomCapped
	adds r2, r0, 0
	movs r3, 0
	cmp r3, r8
	bge _0807AD0C
	lsls r0, r2, 2
	mov r5, sp
	adds r1, r5, r0
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r5, r0, 0
	cmp r1, 0
	bne _0807AD1C
_0807ACF2:
	adds r2, 0x1
	cmp r2, r8
	blt _0807ACFA
	movs r2, 0
_0807ACFA:
	adds r3, 0x1
	cmp r3, r8
	bge _0807AD0C
	lsls r0, r2, 2
	add r0, sp
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, 0
	beq _0807ACF2
_0807AD0C:
	lsls r0, r2, 2
	mov r2, sp
	adds r1, r2, r0
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r5, r0, 0
	cmp r1, 0
	beq _0807ADA0
_0807AD1C:
	movs r0, 0x1
	bl sub_803D970
	add r4, sp, 0x190
	movs r1, 0
	strh r0, [r4]
	mov r0, r10
	strh r0, [r4, 0x8]
	strb r1, [r4, 0x2]
	mov r1, r10
	str r1, [r4, 0x4]
	movs r0, 0x1
	strb r0, [r4, 0x10]
	mov r2, sp
	adds r1, r2, r5
	ldrh r0, [r1]
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0xE]
	movs r5, 0
	ldrsh r0, [r4, r5]
	movs r1, 0x1
	bl sub_806AA0C
	lsls r0, 24
	adds r6, 0x1
	mov r9, r6
	cmp r0, 0
	beq _0807AD9A
	adds r0, r4, 0
	movs r1, 0
	bl sub_806B7F8
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807AD9A
	movs r0, 0xC8
	lsls r0, 8
	str r0, [r4, 0x1C]
	movs r5, 0
	b _0807AD84
	.align 2, 0
_0807AD74: .4byte gUnknown_80F4DA2
_0807AD78: .4byte gUnknown_80F4DA4
_0807AD7C:
	movs r0, 0x57
	bl sub_803E46C
	adds r5, 0x1
_0807AD84:
	cmp r5, 0x63
	bgt _0807AD96
	ldr r0, [r4, 0x1C]
	movs r1, 0xAA
	bl sub_8009DA4
	str r0, [r4, 0x1C]
	cmp r0, 0xFF
	bgt _0807AD7C
_0807AD96:
	mov r0, r10
	str r0, [r4, 0x1C]
_0807AD9A:
	mov r6, r9
	cmp r6, r7
	blt _0807ACD4
_0807ADA0:
	movs r0, 0x1
	bl sub_804178C
_0807ADA6:
	add sp, 0x1A8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807AB38

	thumb_func_start MoveIfPossible
MoveIfPossible:
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r4, [r5, 0x70]
	adds r0, r4, 0
	adds r0, 0x79
	movs r6, 0
	strb r6, [r0]
	adds r0, 0x1
	strb r6, [r0]
	adds r0, 0x1
	strb r6, [r0]
	adds r0, r5, 0
	movs r1, 0x7
	bl HasTactic
	lsls r0, 24
	cmp r0, 0
	beq _0807ADFA
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	asrs r0, 1
	cmp r1, r0
	bgt _0807ADFA
	adds r0, r4, 0
	adds r0, 0x44
	strh r6, [r0]
	b _0807AEB4
_0807ADFA:
	adds r0, r5, 0
	movs r1, 0x9
	bl HasTactic
	lsls r0, 24
	cmp r0, 0
	beq _0807AE12
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0
	strh r0, [r1]
	b _0807AEB4
_0807AE12:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _0807AE32
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	bl RoundUpFixedPoint
	adds r1, r0, 0
	cmp r1, 0
	bne _0807AE32
	adds r0, r4, 0
	adds r0, 0x44
	strh r1, [r0]
	b _0807AEB4
_0807AE32:
	adds r0, r4, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807AE6A
	adds r0, r4, 0
	adds r0, 0x44
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl SetWalkAction
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r1, r4, 0
	adds r1, 0x46
	strb r0, [r1]
	ldrh r1, [r5, 0x4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r0, [r5, 0x6]
	subs r0, 0x1
	adds r2, 0x2
	adds r1, r4, r2
	strh r0, [r1]
	b _0807AEB4
_0807AE6A:
	adds r0, r5, 0
	adds r1, r7, 0
	bl ShouldAvoidEnemiesAndShowEffect
	lsls r0, 24
	cmp r0, 0
	beq _0807AE80
	adds r0, r5, 0
	bl AvoidEnemies
	b _0807AE9C
_0807AE80:
	adds r0, r5, 0
	bl CanTakeItem
	lsls r0, 24
	cmp r0, 0
	beq _0807AE96
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x3F
	strh r0, [r1]
	b _0807AEB4
_0807AE96:
	adds r0, r5, 0
	bl ChooseTargetPosition
_0807AE9C:
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0807AEAC
	adds r0, r4, 0
	adds r0, 0x44
	strh r2, [r0]
	b _0807AEB4
_0807AEAC:
	adds r0, r5, 0
	adds r1, r7, 0
	bl DecideMovement
_0807AEB4:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end MoveIfPossible

	thumb_func_start CanTakeItem
CanTakeItem:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r5, [r4, 0x70]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807AF50
	adds r0, r4, 0
	bl CannotUseItems
	lsls r0, 24
	cmp r0, 0
	bne _0807AF50
	adds r0, r4, 0
	bl GetMapTileForDungeonEntity_2
	adds r6, r0, 0
	ldr r4, [r6, 0x14]
	cmp r4, 0
	beq _0807AF50
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x5
	bhi _0807AF50
	lsls r0, 2
	ldr r1, _0807AEFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807AEFC: .4byte _0807AF00
	.align 2, 0
_0807AF00:
	.4byte _0807AF50
	.4byte _0807AF50
	.4byte _0807AF50
	.4byte _0807AF18
	.4byte _0807AF50
	.4byte _0807AF50
_0807AF18:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	bne _0807AF50
	adds r0, r5, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0807AF50
	ldrh r1, [r6]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0807AF3C
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _0807AF50
_0807AF3C:
	adds r0, r4, 0
	bl GetItemData
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0807AF50
	movs r0, 0x1
	b _0807AF52
_0807AF50:
	movs r0, 0
_0807AF52:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CanTakeItem

	thumb_func_start ChooseTargetPosition
ChooseTargetPosition:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	ldr r7, [r0, 0x70]
	bl TargetLeader
	lsls r0, 24
	cmp r0, 0
	beq _0807AF74
	b _0807B12C
_0807AF74:
	ldr r0, _0807AF8C
	ldr r1, [r0]
	ldr r2, _0807AF90
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807AF98
	ldr r3, _0807AF94
	adds r6, r1, r3
	movs r4, 0x14
	mov r10, r4
	b _0807AFB4
	.align 2, 0
_0807AF8C: .4byte gDungeonGlobalData
_0807AF90: .4byte 0x000037fc
_0807AF94: .4byte 0x000135cc
_0807AF98:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _0807AFAC
	ldr r0, _0807AFA8
	adds r6, r1, r0
	movs r1, 0x4
	mov r10, r1
	b _0807AFB4
	.align 2, 0
_0807AFA8: .4byte 0x0001357c
_0807AFAC:
	ldr r2, _0807B01C
	adds r6, r1, r2
	movs r3, 0x10
	mov r10, r3
_0807AFB4:
	mov r0, r8
	bl CanCrossWalls
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	movs r4, 0x1
	negs r4, r4
	str r4, [sp]
	ldr r0, _0807B020
	mov r9, r0
	movs r5, 0
	adds r1, r7, 0
	adds r1, 0x78
	str r1, [sp, 0x8]
	cmp r5, r10
	bge _0807B09E
_0807AFD6:
	lsls r0, r5, 2
	adds r0, r6
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807B098
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xA4
	ldrb r1, [r1]
	adds r2, r0, 0
	cmp r1, 0
	bne _0807B098
	ldr r0, _0807B024
	ldr r0, [r0]
	ldr r3, _0807B028
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B02C
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807B098
	ldr r2, [r4, 0x70]
	b _0807B03C
	.align 2, 0
_0807B01C: .4byte 0x0001358c
_0807B020: .4byte 0x000003e7
_0807B024: .4byte gDungeonGlobalData
_0807B028: .4byte 0x000037fc
_0807B02C:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	bne _0807B03C
	adds r0, r2, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _0807B098
_0807B03C:
	ldrb r0, [r2, 0x8]
	cmp r0, 0x1
	beq _0807B098
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _0807B074
	mov r2, r8
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807B05A
	negs r1, r1
_0807B05A:
	cmp r1, 0x5
	bgt _0807B074
	mov r3, r8
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	subs r1, r0
	cmp r1, 0
	bge _0807B070
	negs r1, r1
_0807B070:
	cmp r1, 0x5
	ble _0807B082
_0807B074:
	mov r0, r8
	adds r1, r4, 0
	bl CanSee_2
	lsls r0, 24
	cmp r0, 0
	beq _0807B098
_0807B082:
	adds r1, r4, 0x4
	mov r0, r8
	adds r0, 0x4
	bl GetMaxPositionDifference
	cmp r9, r0
	ble _0807B098
	mov r9, r0
	str r5, [sp]
	cmp r0, 0x1
	ble _0807B09E
_0807B098:
	adds r5, 0x1
	cmp r5, r10
	blt _0807AFD6
_0807B09E:
	ldr r3, [sp]
	cmp r3, 0
	blt _0807B12C
	movs r2, 0
	movs r5, 0x1
	ldr r4, [sp, 0x8]
	strb r5, [r4]
	adds r1, r7, 0
	adds r1, 0x88
	lsls r0, r3, 2
	adds r4, r0, r6
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	str r0, [r1]
	subs r1, 0x8
	ldr r0, [r4]
	str r0, [r1]
	ldrh r1, [r0, 0x26]
	adds r0, r7, 0
	adds r0, 0x7C
	strh r1, [r0]
	subs r0, 0x2
	strb r5, [r0]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r7, r1
	str r2, [r0]
	mov r0, r8
	movs r1, 0x8
	bl HasTactic
	lsls r0, 24
	cmp r0, 0
	bne _0807B0E4
	b _0807B2C6
_0807B0E4:
	mov r0, r8
	bl CanSeeTeammate
	lsls r0, 24
	cmp r0, 0
	beq _0807B0F2
	b _0807B2C6
_0807B0F2:
	mov r2, r8
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	ldr r2, [r4]
	movs r4, 0x4
	ldrsh r0, [r2, r4]
	subs r1, r0
	cmp r1, 0
	bge _0807B106
	negs r1, r1
_0807B106:
	cmp r1, 0x1
	ble _0807B10C
	b _0807B2C6
_0807B10C:
	mov r0, r8
	movs r3, 0x6
	ldrsh r1, [r0, r3]
	movs r4, 0x6
	ldrsh r0, [r2, r4]
	subs r0, r1, r0
	cmp r0, 0
	bge _0807B11E
	negs r0, r0
_0807B11E:
	cmp r0, 0x1
	ble _0807B124
	b _0807B2C6
_0807B124:
	adds r0, r7, 0
	adds r0, 0x7B
	strb r5, [r0]
	b _0807B2C6
_0807B12C:
	mov r0, r8
	movs r1, 0x1
	bl HasTactic
	lsls r0, 24
	cmp r0, 0
	bne _0807B17C
	ldrb r5, [r7, 0x6]
	adds r0, r7, 0
	adds r0, 0x78
	str r0, [sp, 0x8]
	cmp r5, 0
	bne _0807B222
	mov r0, r8
	bl GetLeaderEntityIfVisible
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807B222
	movs r0, 0x1
	ldr r1, [sp, 0x8]
	strb r0, [r1]
	adds r1, r7, 0
	adds r1, 0x88
	ldr r0, [r4, 0x4]
	str r0, [r1]
	adds r0, r7, 0
	adds r0, 0x80
	str r4, [r0]
	ldrh r1, [r4, 0x26]
	subs r0, 0x4
	strh r1, [r0]
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r7, r2
	str r5, [r0]
	b _0807B2C6
_0807B17C:
	ldrb r0, [r7, 0x7]
	adds r3, r7, 0
	adds r3, 0x78
	str r3, [sp, 0x8]
	cmp r0, 0
	beq _0807B222
	ldr r4, _0807B1BC
	ldr r0, [r4]
	ldr r1, _0807B1C0
	adds r0, r1
	ldrb r0, [r0]
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl GetMapTile_1
	ldrb r1, [r0, 0x9]
	cmp r1, 0xFF
	bne _0807B1C4
	mov r4, r8
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	subs r2, r1, 0x2
	mov r10, r2
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	subs r2, r0, 0x2
	adds r6, r1, 0x2
	adds r0, 0x2
	b _0807B1EC
	.align 2, 0
_0807B1BC: .4byte gDungeonGlobalData
_0807B1C0: .4byte 0x00018209
_0807B1C4:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, _0807B26C
	adds r0, r1
	ldr r1, [r4]
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	mov r10, r0
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	subs r2, r0, 0x1
	movs r4, 0x6
	ldrsh r0, [r1, r4]
	adds r6, r0, 0x1
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	adds r0, 0x1
_0807B1EC:
	mov r9, r0
	adds r5, r2, 0
	adds r4, r7, 0
	adds r4, 0x78
	str r4, [sp, 0x8]
	cmp r5, r9
	bgt _0807B222
_0807B1FA:
	mov r4, r10
	cmp r4, r6
	bgt _0807B21C
_0807B200:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _0807B216
	bl GetEntityType
	cmp r0, 0x3
	beq _0807B270
_0807B216:
	adds r4, 0x1
	cmp r4, r6
	ble _0807B200
_0807B21C:
	adds r5, 0x1
	cmp r5, r9
	ble _0807B1FA
_0807B222:
	ldr r1, [sp, 0x8]
	ldrb r0, [r1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0807B2C0
	adds r3, r7, 0
	adds r3, 0x80
	ldr r1, [r3]
	cmp r1, 0
	beq _0807B2C0
	adds r2, r7, 0
	adds r2, 0x7C
	ldrh r0, [r1, 0x26]
	ldrh r4, [r2]
	cmp r0, r4
	bne _0807B2B4
	ldr r1, [r1, 0x70]
	mov r9, r1
	movs r5, 0
	mov r4, r9
	adds r4, 0x68
_0807B250:
	lsls r6, r5, 2
	mov r0, r8
	adds r1, r4, 0
	bl InSameRoom
	lsls r0, 24
	cmp r0, 0
	bne _0807B294
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0x3
	ble _0807B250
	b _0807B2C0
	.align 2, 0
_0807B26C: .4byte 0x000104c4
_0807B270:
	movs r1, 0
	movs r0, 0x7
	ldr r2, [sp, 0x8]
	strb r0, [r2]
	adds r0, r7, 0
	adds r0, 0x88
	strh r4, [r0]
	adds r0, 0x2
	strh r5, [r0]
	subs r0, 0xA
	str r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	movs r3, 0x8A
	lsls r3, 1
	adds r0, r7, r3
	str r1, [r0]
	b _0807B2C6
_0807B294:
	movs r2, 0
	movs r0, 0x2
	ldr r4, [sp, 0x8]
	strb r0, [r4]
	adds r1, r7, 0
	adds r1, 0x88
	mov r0, r9
	adds r0, 0x68
	adds r0, r6
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r7, r1
	str r2, [r0]
	b _0807B2C6
_0807B2B4:
	movs r1, 0
	movs r0, 0x6
	ldr r4, [sp, 0x8]
	strb r0, [r4]
	str r1, [r3]
	strh r1, [r2]
_0807B2C0:
	mov r0, r8
	bl Explore
_0807B2C6:
	movs r0, 0x1
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ChooseTargetPosition

	thumb_func_start DecideMovement
DecideMovement:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	mov r9, r0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r5, [r0, 0x70]
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r5, r0
	adds r4, r5, 0
	adds r4, 0x88
	ldr r0, [r4]
	str r0, [r1]
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r4]
	cmp r1, r0
	beq _0807B348
	mov r6, r9
	adds r6, 0x4
	adds r0, r6, 0
	adds r1, r4, 0
	bl CalculateFacingDir
	mov r8, r0
	adds r0, r5, 0
	adds r0, 0x7A
	ldrb r1, [r0]
	mov r0, r9
	bl ShouldAvoidFirstHit
	lsls r0, 24
	cmp r0, 0
	beq _0807B366
	adds r0, r5, 0
	adds r0, 0x78
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807B37C
	adds r0, r6, 0
	adds r1, r4, 0
	bl IsTargetTwoTilesAway
	lsls r0, 24
	cmp r0, 0
	beq _0807B37C
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetMaxPositionDifference
	cmp r0, 0x2
	bne _0807B354
_0807B348:
	adds r0, r5, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	b _0807B5CE
_0807B354:
	cmp r0, 0x1
	bgt _0807B37C
	movs r3, 0x4
	add r8, r3
	movs r0, 0x7
	mov r1, r8
	ands r1, r0
	mov r8, r1
	b _0807B37C
_0807B366:
	adds r0, r5, 0
	adds r0, 0x7B
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B37C
	movs r2, 0x4
	add r8, r2
	movs r0, 0x7
	mov r3, r8
	ands r3, r0
	mov r8, r3
_0807B37C:
	add r4, sp, 0x30
	mov r0, r9
	mov r1, r8
	adds r2, r4, 0
	bl CanMoveForward
	lsls r0, 24
	cmp r0, 0
	beq _0807B3A8
	adds r0, r5, 0
	adds r0, 0x44
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl SetWalkAction
	movs r0, 0x7
	mov r3, r8
	ands r3, r0
	adds r0, r5, 0
	adds r0, 0x46
	strb r3, [r0]
	b _0807B5CE
_0807B3A8:
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807B444
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _0807B3E8
	ldr r1, _0807B3E0
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807B3E8
	adds r0, r5, 0
	adds r0, 0x79
	movs r4, 0x1
	strb r4, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	strb r4, [r0]
	adds r0, r5, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	ldr r3, _0807B3E4
	adds r0, r5, r3
	strb r4, [r0]
	b _0807B5CE
	.align 2, 0
_0807B3E0: .4byte 0x00000145
_0807B3E4: .4byte 0x00000147
_0807B3E8:
	mov r0, r9
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r2, _0807B434
	mov r3, r8
	lsls r0, r3, 2
	adds r2, r0, r2
	movs r3, 0
	ldrsh r0, [r2, r3]
	adds r1, r0
	adds r0, r5, 0
	adds r0, 0x88
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _0807B43C
	mov r1, r9
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	adds r0, r1
	adds r1, r5, 0
	adds r1, 0x8A
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bne _0807B43C
	adds r0, r5, 0
	adds r0, 0x44
	movs r1, 0x1
	bl SetAction
	ldr r3, _0807B438
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	b _0807B5CE
	.align 2, 0
_0807B434: .4byte gAdjacentTileOffsets
_0807B438: .4byte 0x00000147
_0807B43C:
	adds r1, r5, 0
	adds r1, 0x79
	movs r0, 0x1
	strb r0, [r1]
_0807B444:
	mov r3, sp
	mov r2, sp
	mov r1, sp
	add r0, sp, 0x28
	movs r4, 0x1
	strb r4, [r0]
	add r0, sp, 0x20
	strb r4, [r0]
	strb r4, [r1, 0x18]
	strb r4, [r2, 0x10]
	strb r4, [r3, 0x8]
	ldrb r6, [r5, 0x6]
	cmp r6, 0
	bne _0807B4C8
	mov r0, r8
	ands r0, r4
	cmp r0, 0
	beq _0807B4C8
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	adds r1, r5, 0
	adds r1, 0x88
	movs r3, 0
	ldrsh r1, [r1, r3]
	subs r2, r0, r1
	cmp r2, 0
	bge _0807B47E
	negs r2, r2
_0807B47E:
	mov r0, r9
	movs r3, 0x6
	ldrsh r1, [r0, r3]
	adds r0, r5, 0
	adds r0, 0x8A
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0
	cmp r1, 0
	bge _0807B494
	negs r1, r1
_0807B494:
	cmp r2, 0x2
	bgt _0807B4C8
	cmp r1, 0x2
	bgt _0807B4C8
	cmp r2, r1
	beq _0807B4C8
	movs r3, 0x2
	mov r0, r8
	ands r3, r0
	cmp r3, 0
	beq _0807B4BA
	cmp r2, r1
	bge _0807B4B4
	mov r0, sp
	strb r6, [r0, 0x10]
	b _0807B4C8
_0807B4B4:
	mov r0, sp
	strb r6, [r0, 0x8]
	b _0807B4C8
_0807B4BA:
	cmp r2, r1
	bge _0807B4C4
	mov r0, sp
	strb r3, [r0, 0x8]
	b _0807B4C8
_0807B4C4:
	mov r0, sp
	strb r3, [r0, 0x10]
_0807B4C8:
	movs r1, 0x3
	mov r10, r1
	mov r0, r9
	adds r1, r7, 0
	bl ShouldAvoidEnemiesAndShowEffect
	lsls r0, 24
	cmp r0, 0
	bne _0807B4E4
	adds r0, r5, 0
	adds r0, 0x7B
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B4E8
_0807B4E4:
	movs r2, 0x5
	mov r10, r2
_0807B4E8:
	movs r6, 0x1
	adds r3, r5, 0
	adds r3, 0x44
	str r3, [sp, 0x34]
	cmp r6, r10
	bge _0807B53C
	mov r3, sp
	mov r4, sp
	adds r4, 0xA
	add r7, sp, 0x8
_0807B4FC:
	lsls r0, r6, 3
	add r2, sp, 0x4
	adds r2, r0
	ldr r1, _0807B598
	lsls r0, r6, 2
	adds r0, r1
	ldr r1, [r0]
	add r1, r8
	movs r0, 0x7
	ands r1, r0
	str r1, [r2]
	mov r0, r9
	adds r2, r4, 0
	str r3, [sp, 0x38]
	bl CanMoveForward
	strb r0, [r7, 0x1]
	lsls r0, 24
	ldr r3, [sp, 0x38]
	cmp r0, 0
	bne _0807B532
	ldrb r0, [r4]
	cmp r0, 0
	bne _0807B532
	movs r0, 0x1
	strb r0, [r3, 0x10]
	strb r0, [r3, 0x8]
_0807B532:
	adds r4, 0x8
	adds r7, 0x8
	adds r6, 0x1
	cmp r6, r10
	blt _0807B4FC
_0807B53C:
	movs r6, 0x1
	cmp r6, r10
	bge _0807B56E
	adds r3, r5, 0
	adds r3, 0x79
	add r1, sp, 0x8
	movs r4, 0x8
	movs r7, 0x1
_0807B54C:
	adds r2, r4, 0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _0807B55A
	ldrb r0, [r1]
	cmp r0, 0
	bne _0807B5A0
_0807B55A:
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0807B562
	strb r7, [r3]
_0807B562:
	adds r1, 0x8
	adds r4, r2, 0
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, r10
	blt _0807B54C
_0807B56E:
	ldr r0, [sp, 0x34]
	movs r1, 0x1
	bl SetAction
	ldr r1, _0807B59C
	adds r0, r5, r1
	movs r1, 0
	movs r2, 0x1
	strb r2, [r0]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0807B5BC
	adds r0, r5, 0
	adds r0, 0x79
	strb r1, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r5, r2
	strb r1, [r0]
	b _0807B5CE
	.align 2, 0
_0807B598: .4byte gFaceDirectionIncrements
_0807B59C: .4byte 0x00000147
_0807B5A0:
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	ldr r0, [sp, 0x34]
	bl SetWalkAction
	add r0, sp, 0x4
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x46
	strb r0, [r1]
	b _0807B5CE
_0807B5BC:
	adds r0, r5, 0
	adds r0, 0x79
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B5CE
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r5, r1
	strb r2, [r0]
_0807B5CE:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DecideMovement

	thumb_func_start AvoidEnemies
AvoidEnemies:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r7, r0, 0
	ldr r0, _0807B61C
	str r0, [sp, 0x8]
	ldr r1, [r7, 0x70]
	str r1, [sp, 0x10]
	adds r0, r7, 0
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, _0807B620
	ldr r1, [r0]
	ldr r2, _0807B624
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B62C
	ldr r3, _0807B628
	adds r0, r1, r3
	movs r4, 0x14
	mov r9, r4
	b _0807B64C
	.align 2, 0
_0807B61C: .4byte 0x000f423f
_0807B620: .4byte gDungeonGlobalData
_0807B624: .4byte 0x000037fc
_0807B628: .4byte 0x000135cc
_0807B62C:
	ldr r2, [sp, 0x10]
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _0807B644
	ldr r3, _0807B640
	adds r0, r1, r3
	movs r4, 0x4
	mov r9, r4
	b _0807B64C
	.align 2, 0
_0807B640: .4byte 0x0001357c
_0807B644:
	ldr r2, _0807B790
	adds r0, r1, r2
	movs r3, 0x10
	mov r9, r3
_0807B64C:
	movs r4, 0
	str r4, [sp, 0xC]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	mov r8, r4
	cmp r4, r9
	bge _0807B6D8
	adds r6, r0, 0
_0807B65C:
	ldr r4, [r6]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807B6CE
	adds r0, r7, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0807B6CE
	ldr r0, _0807B794
	ldr r0, [r0]
	ldr r2, _0807B798
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807B69A
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl CanTarget
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807B6CE
_0807B69A:
	adds r1, r4, 0x4
	adds r0, r7, 0x4
	bl GetMaxPositionDifference
	ldr r3, [sp, 0x8]
	cmp r3, r0
	ble _0807B6CE
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r4, 0
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x10]
	adds r1, 0x88
	ldr r4, [sp, 0xC]
	ldr r0, [r4, 0x4]
	str r0, [r1]
	ldr r0, [sp, 0x10]
	movs r2, 0xB6
	lsls r2, 1
	adds r1, r0, r2
	ldr r0, [r4, 0x4]
	str r0, [r1]
_0807B6CE:
	adds r6, 0x4
	movs r3, 0x1
	add r8, r3
	cmp r8, r9
	blt _0807B65C
_0807B6D8:
	ldr r0, _0807B79C
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bne _0807B6E2
	b _0807B906
_0807B6E2:
	ldr r0, [sp, 0x10]
	adds r0, 0x88
	str r0, [sp, 0x28]
	ldr r1, [sp, 0x10]
	adds r1, 0x78
	str r1, [sp, 0x24]
	ldr r2, [sp, 0x4]
	cmp r10, r2
	beq _0807B6F6
	b _0807B8E0
_0807B6F6:
	mov r3, r10
	cmp r3, 0xFF
	bne _0807B6FE
	b _0807B8E0
_0807B6FE:
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0807B7B2
	ldrh r0, [r7, 0x6]
	lsls r0, 16
	ldrh r5, [r7, 0x4]
	orrs r5, r0
	movs r4, 0
_0807B71E:
	ldr r1, _0807B7A0
	lsls r0, r4, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r3, [r7, 0x4]
	adds r1, r3
	lsls r1, 16
	ldrh r0, [r0, 0x2]
	ldrh r2, [r7, 0x6]
	adds r0, r2
	lsls r0, 16
	lsrs r5, r1, 16
	orrs r5, r0
	lsls r0, r5, 16
	asrs r0, 16
	asrs r1, r5, 16
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, r10
	beq _0807B758
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, sp
	bl CanMoveForward
	lsls r0, 24
	cmp r0, 0
	bne _0807B75E
_0807B758:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0807B71E
_0807B75E:
	cmp r4, 0x8
	bne _0807B7A4
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x6
	ldr r3, [sp, 0x24]
	strb r0, [r3]
	ldr r0, _0807B7A0
	lsls r1, r4, 2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r4, [r7, 0x4]
	adds r0, r4
	ldr r2, [sp, 0x28]
	strh r0, [r2]
	ldrh r0, [r1, 0x2]
	ldrh r7, [r7, 0x6]
	adds r0, r7
	ldr r1, [sp, 0x10]
	adds r1, 0x8A
	strh r0, [r1]
	movs r0, 0x1
	b _0807B910
	.align 2, 0
_0807B790: .4byte 0x0001358c
_0807B794: .4byte gDungeonGlobalData
_0807B798: .4byte 0x000037fc
_0807B79C: .4byte 0x000f423f
_0807B7A0: .4byte gAdjacentTileOffsets
_0807B7A4:
	movs r0, 0x5
	ldr r3, [sp, 0x24]
	strb r0, [r3]
	ldr r4, [sp, 0x28]
	str r5, [r4]
	movs r0, 0x1
	b _0807B910
_0807B7B2:
	ldr r0, _0807B8D0
	mov r2, r10
	lsls r1, r2, 7
	ldr r3, _0807B8D4
	adds r1, r3
	ldr r0, [r0]
	adds r1, r0, r1
	str r1, [sp, 0x18]
	lsls r1, r2, 1
	ldr r4, _0807B8D8
	adds r0, r4
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	str r1, [sp, 0x14]
	ldr r3, _0807B8DC
	str r3, [sp, 0x20]
	movs r4, 0
	str r4, [sp, 0x1C]
	ldr r0, [sp, 0xC]
	movs r1, 0x4
	ldrsh r3, [r0, r1]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	subs r2, r3, r0
	cmp r2, 0
	bge _0807B7EA
	negs r2, r2
_0807B7EA:
	ldr r4, [sp, 0xC]
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r4, 0x6
	ldrsh r0, [r7, r4]
	subs r1, r0
	mov r8, r1
	cmp r1, 0
	bge _0807B802
	mov r0, r8
	negs r0, r0
	mov r8, r0
_0807B802:
	cmp r8, r2
	bge _0807B808
	mov r8, r2
_0807B808:
	movs r1, 0
	mov r9, r1
	ldr r2, [sp, 0x10]
	adds r2, 0x8A
	str r2, [sp, 0x2C]
	ldr r4, [sp, 0x1C]
	ldr r0, [sp, 0x14]
	cmp r4, r0
	bge _0807B8AA
	mov r10, r3
	ldr r6, [sp, 0x18]
_0807B81E:
	movs r1, 0
	ldrsh r3, [r6, r1]
	mov r2, r10
	subs r0, r2, r3
	cmp r0, 0
	bge _0807B82C
	negs r0, r0
_0807B82C:
	ldr r4, [sp, 0xC]
	movs r1, 0x6
	ldrsh r4, [r4, r1]
	mov r12, r4
	movs r4, 0x2
	ldrsh r2, [r6, r4]
	mov r4, r12
	subs r1, r4, r2
	cmp r1, 0
	bge _0807B842
	negs r1, r1
_0807B842:
	cmp r1, r0
	bge _0807B848
	adds r1, r0, 0
_0807B848:
	movs r0, 0x4
	ldrsh r4, [r7, r0]
	subs r0, r3, r4
	movs r3, 0x6
	ldrsh r5, [r7, r3]
	subs r3, r2, r5
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bge _0807B85E
	adds r0, r2, 0
_0807B85E:
	cmp r3, r2
	bge _0807B864
	adds r3, r2, 0
_0807B864:
	cmp r0, 0x1
	ble _0807B86A
	movs r0, 0x1
_0807B86A:
	cmp r3, 0x1
	ble _0807B870
	movs r3, 0x1
_0807B870:
	adds r0, r4, r0
	mov r4, r10
	subs r2, r4, r0
	cmp r2, 0
	bge _0807B87C
	negs r2, r2
_0807B87C:
	adds r0, r5, r3
	mov r3, r12
	subs r0, r3, r0
	cmp r0, 0
	bge _0807B888
	negs r0, r0
_0807B888:
	cmp r0, r2
	bge _0807B88E
	adds r0, r2, 0
_0807B88E:
	cmp r0, r8
	blt _0807B89E
	ldr r4, [sp, 0x20]
	cmp r4, r1
	bge _0807B89E
	mov r0, r9
	str r0, [sp, 0x1C]
	str r1, [sp, 0x20]
_0807B89E:
	adds r6, 0x4
	movs r1, 0x1
	add r9, r1
	ldr r2, [sp, 0x14]
	cmp r9, r2
	blt _0807B81E
_0807B8AA:
	ldr r3, [sp, 0x20]
	cmp r3, 0
	blt _0807B8E0
	movs r0, 0x5
	ldr r4, [sp, 0x24]
	strb r0, [r4]
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 2
	ldr r2, [sp, 0x18]
	adds r0, r2
	ldrh r1, [r0]
	ldr r3, [sp, 0x28]
	strh r1, [r3]
	ldrh r0, [r0, 0x2]
	ldr r4, [sp, 0x2C]
	strh r0, [r4]
	movs r0, 0x1
	b _0807B910
	.align 2, 0
_0807B8D0: .4byte gDungeonGlobalData
_0807B8D4: .4byte 0x00010884
_0807B8D8: .4byte 0x00010844
_0807B8DC: .4byte 0xfff0bdc1
_0807B8E0:
	movs r0, 0x5
	ldr r1, [sp, 0x24]
	strb r0, [r1]
	ldr r2, [sp, 0xC]
	ldrh r1, [r2, 0x4]
	ldrh r0, [r7, 0x4]
	subs r1, r0
	subs r0, r1
	ldr r3, [sp, 0x28]
	strh r0, [r3]
	ldrh r0, [r2, 0x6]
	ldrh r1, [r7, 0x6]
	subs r0, r1
	subs r1, r0
	ldr r0, [sp, 0x10]
	adds r0, 0x8A
	strh r1, [r0]
	movs r0, 0x1
	b _0807B910
_0807B906:
	adds r0, r7, 0
	bl Explore
	lsls r0, 24
	lsrs r0, 24
_0807B910:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end AvoidEnemies

	thumb_func_start Explore
Explore:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r7, [r6, 0x70]
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xFF
	bne _0807B9DC
	movs r0, 0
	str r0, [sp, 0x4]
	adds r4, r7, 0
	adds r4, 0x46
	ldrb r0, [r4]
	adds r0, 0x4
	mov r8, r0
	movs r0, 0x7
	mov r1, r8
	ands r1, r0
	mov r8, r1
	adds r0, r6, 0
	bl IsAtJunction
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	beq _0807B96C
	movs r0, 0x8
	bl DungeonRandomCapped
	strb r0, [r4]
	movs r2, 0x1
	str r2, [sp, 0x4]
_0807B96C:
	movs r3, 0
	movs r4, 0x78
	adds r4, r7
	mov r10, r4
	adds r0, r7, 0
	adds r0, 0x88
	str r0, [sp, 0x8]
	adds r7, 0x8A
	ldr r5, _0807B9D4
_0807B97E:
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, [r5]
	adds r4, r0, r1
	movs r0, 0x7
	ands r4, r0
	ldr r2, [sp, 0x4]
	cmp r2, 0
	beq _0807B994
	cmp r4, r8
	beq _0807B9AA
_0807B994:
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	str r3, [sp, 0xC]
	bl CanMoveForward
	lsls r0, 24
	ldr r3, [sp, 0xC]
	cmp r0, 0
	beq _0807B9AA
	b _0807BB42
_0807B9AA:
	adds r5, 0x4
	adds r3, 0x1
	cmp r3, 0x7
	ble _0807B97E
	movs r0, 0x8
	bl DungeonRandomCapped
	movs r1, 0x6
	mov r3, r10
	strb r1, [r3]
	ldr r1, _0807B9D8
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r4, [r6, 0x4]
	adds r1, r4
	ldr r2, [sp, 0x8]
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	b _0807BB5A
	.align 2, 0
_0807B9D4: .4byte gFaceDirectionIncrements
_0807B9D8: .4byte gAdjacentTileOffsets
_0807B9DC:
	ldr r0, _0807BA30
	ldr r2, [r0]
	lsls r1, r3, 1
	ldr r4, _0807BA34
	adds r0, r2, r4
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
	mov r8, r1
	lsls r0, r3, 7
	ldr r1, _0807BA38
	adds r0, r1
	adds r2, r0
	mov r9, r2
	movs r2, 0x8A
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0807BA40
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r2, r7, 0
	adds r2, 0x78
	movs r1, 0x6
	strb r1, [r2]
	ldr r1, _0807BA3C
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r3, [r6, 0x4]
	adds r1, r3
	adds r2, 0x10
	strh r1, [r2]
	ldrh r0, [r0, 0x2]
	ldrh r6, [r6, 0x6]
	adds r0, r6
	adds r1, r7, 0
	adds r1, 0x8A
	strh r0, [r1]
	b _0807BB60
	.align 2, 0
_0807BA30: .4byte gDungeonGlobalData
_0807BA34: .4byte 0x00010844
_0807BA38: .4byte 0x00010884
_0807BA3C: .4byte gAdjacentTileOffsets
_0807BA40:
	adds r0, r7, 0
	adds r0, 0x78
	ldrb r1, [r0]
	mov r10, r0
	cmp r1, 0x4
	beq _0807BAA2
	mov r4, r8
	cmp r4, 0
	bne _0807BA84
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x6
	mov r1, r10
	strb r0, [r1]
	ldr r0, _0807BA80
	lsls r2, r4, 2
	adds r2, r0
	ldrh r0, [r2]
	ldrh r3, [r6, 0x4]
	adds r0, r3
	adds r1, r7, 0
	adds r1, 0x88
	strh r0, [r1]
	ldrh r0, [r2, 0x2]
	ldrh r6, [r6, 0x6]
	adds r0, r6
	adds r1, 0x2
	strh r0, [r1]
	b _0807BB60
	.align 2, 0
_0807BA80: .4byte gAdjacentTileOffsets
_0807BA84:
	movs r5, 0
_0807BA86:
	mov r0, r8
	bl DungeonRandomCapped
	adds r4, r0, 0
	ldr r0, [r6, 0x4]
	lsls r1, r4, 2
	mov r4, r9
	adds r2, r1, r4
	ldr r1, [r2]
	cmp r0, r1
	bne _0807BB18
	adds r5, 0x1
	cmp r5, 0x9
	ble _0807BA86
_0807BAA2:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0807BB60
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r3, 0
	mov r9, r3
_0807BAC4:
	movs r0, 0x7
	ands r4, r0
	movs r0, 0x4
	ldrsh r2, [r6, r0]
	ldr r0, _0807BB14
	lsls r1, r4, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	adds r2, r0
	mov r8, r2
	movs r0, 0x6
	ldrsh r2, [r6, r0]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r5, r2, r0
	mov r0, r8
	adds r1, r5, 0
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0807BB04
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	adds r2, 0x1
	bl CanMoveForward
	lsls r0, 24
	cmp r0, 0
	bne _0807BB2E
_0807BB04:
	movs r0, 0x1
	add r9, r0
	adds r4, 0x1
	mov r1, r9
	cmp r1, 0x7
	ble _0807BAC4
	b _0807BB60
	.align 2, 0
_0807BB14: .4byte gAdjacentTileOffsets
_0807BB18:
	movs r0, 0x4
	mov r3, r10
	strb r0, [r3]
	ldrh r1, [r2]
	adds r0, r7, 0
	adds r0, 0x88
	strh r1, [r0]
	ldrh r1, [r2, 0x2]
	adds r0, 0x2
	strh r1, [r0]
	b _0807BB60
_0807BB2E:
	movs r0, 0x3
	mov r4, r10
	strb r0, [r4]
	adds r0, r7, 0
	adds r0, 0x88
	mov r1, r8
	strh r1, [r0]
	adds r0, 0x2
	strh r5, [r0]
	b _0807BB60
_0807BB42:
	movs r0, 0x3
	mov r2, r10
	strb r0, [r2]
	ldr r0, _0807BB74
	lsls r1, r4, 2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r3, [r6, 0x4]
	adds r0, r3
	ldr r4, [sp, 0x8]
	strh r0, [r4]
	ldrh r0, [r1, 0x2]
_0807BB5A:
	ldrh r6, [r6, 0x6]
	adds r0, r6
	strh r0, [r7]
_0807BB60:
	movs r0, 0x1
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807BB74: .4byte gAdjacentTileOffsets
	thumb_func_end Explore

	thumb_func_start sub_807BB78
sub_807BB78:
	ldr r3, [r0, 0x70]
	adds r1, r3, 0
	adds r1, 0x78
	movs r2, 0
	strb r2, [r1]
	adds r1, 0x10
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x80
	str r2, [r0]
	subs r0, 0x4
	strh r2, [r0]
	bx lr
	thumb_func_end sub_807BB78

	.align 2, 0