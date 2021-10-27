	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8075BA4
sub_8075BA4:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 24
	ldr r4, [r5, 0x70]
	cmp r1, 0
	beq _08075BD0
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08075BD0
	adds r0, r4, 0
	adds r0, 0x46
	ldrb r1, [r0]
	adds r1, 0x4
	movs r2, 0x7
	ands r1, r2
	strb r1, [r0]
	adds r0, r5, 0
	bl sub_8069DCC
	b _08075BEC
_08075BD0:
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08075BEC
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r1, r4, 0
	adds r1, 0x46
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8069DCC
_08075BEC:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8075BA4

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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_8071824
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
	bl sub_8071824
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
	bl sub_8046CB0
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80708B4
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
	bl sub_80418D4
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
	bl sub_8071824
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
	bl sub_80708B4
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
	bl sub_80418D4
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
	bl sub_80708B4
	adds r0, r5, 0
	movs r1, 0x42
	bl sub_8071824
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
	bl sub_8071858
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
	bl sub_8045128
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
_080762D8: .4byte gUnknown_810ACC0
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
	bl sub_80418D4
	adds r0, r5, 0
	movs r1, 0x19
	bl sub_8071824
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
	bl sub_804954C
	ldr r4, [r0, 0x10]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080763D4
	adds r0, r4, 0
	bl sub_80450F8
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
	bl sub_80708B4
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
_080763EC: .4byte gUnknown_80F4448
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
	bl sub_80708B4
	adds r0, r5, 0
	movs r1, 0x14
	bl sub_8046CB0
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
	bl sub_8071824
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
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _0807649A
	adds r0, r5, 0
	movs r1, 0x11
	bl sub_8071858
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
	bl sub_8071824
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
	bl sub_804954C
	ldr r4, [r0, 0x10]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080765B4
	adds r0, r4, 0
	bl sub_80450F8
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
	bl sub_80708B4
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
	bl sub_80418D4
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
_080765D4: .4byte gUnknown_80F4448
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
	bl sub_80708B4
	adds r0, r5, 0
	movs r1, 0x14
	bl sub_8046CB0
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
	bl sub_8071824
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
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _08076682
	adds r0, r5, 0
	movs r1, 0x11
	bl sub_8071858
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
	bl sub_8071824
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
	bl sub_804954C
	ldr r4, [r0, 0x10]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08076784
	adds r0, r4, 0
	bl sub_80450F8
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
	bl sub_80708B4
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
	bl sub_80418D4
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
_080767A4: .4byte gUnknown_80F4448
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
	bl sub_8071824
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
	bl sub_8071858
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
	bl sub_8045128
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
_08076868: .4byte gUnknown_810ACC0
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8046CB0
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
_0807722E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077238: .4byte gUnknown_80FC21C
	thumb_func_end sub_8077160

	thumb_func_start sub_807723C
sub_807723C:
	push {r4,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08077258
	adds r0, r4, 0
	movs r1, 0x48
	bl sub_8071824
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
	thumb_func_end sub_807723C

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
	bl sub_80418D4
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
	bl sub_8046CB0
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_8071824
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
	bl sub_8070774
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
	bl sub_8071824
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
	bl sub_804954C
	ldr r4, [r0, 0x10]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080778E4
	adds r0, r4, 0
	bl sub_80450F8
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
	bl sub_80708B4
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
	bl sub_80418D4
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
_08077904: .4byte gUnknown_80F4448
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
	bl sub_8070774
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
	bl sub_8070774
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
	bl sub_80418D4
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
	bl sub_8070774
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
	bl sub_8070774
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
	bl sub_80418D4
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
	bl sub_8046CB0
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80450F8
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
	bl sub_8071858
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80450F8
	cmp r0, 0x1
	bne _080781C4
	adds r0, r5, 0
	bl sub_80450F8
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8071858
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8094450
	adds r4, r0, 0
	ldr r0, [r5]
	bl sub_8094450
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
	bl sub_8094450
	adds r5, r0, 0
	ldr r0, [r4]
	bl sub_8094450
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
	bl sub_80418D4
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
	bl sub_8046CB0
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
	bl sub_8094450
	adds r4, r0, 0
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl sub_8094450
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
	bl sub_8094450
	adds r4, r0, 0
	ldr r0, [r5]
	bl sub_8094450
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
	bl sub_8094450
	adds r4, r0, 0
	movs r1, 0xA0
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl sub_8094450
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
	bl sub_8094450
	adds r4, r0, 0
	ldr r0, [r5]
	bl sub_8094450
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
	bl sub_8094450
	adds r4, r0, 0
	ldr r0, [r7]
	bl sub_8094450
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_808E9B8
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8071858
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8092BF4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8071824
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_8070A58
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
	bl sub_8070774
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
	bl sub_8070774
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
	adds r0, r5, 0
	bl sub_8070774
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80418D4
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
	bl sub_80450FC
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
	bl sub_8046CB0
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
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0807AB00
	adds r0, r4, 0
	bl sub_80450FC
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
	bl sub_8045128
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
	bl sub_8049590
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
	bl sub_8049590
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
	bl sub_80718AC
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
	bl sub_80718AC
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
	bl sub_8094450
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
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	beq _0807AE80
	adds r0, r5, 0
	bl sub_807B5E0
	b _0807AE9C
_0807AE80:
	adds r0, r5, 0
	bl sub_807AEBC
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
	bl sub_807AF58
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
	bl sub_807B2D8
_0807AEB4:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end MoveIfPossible

	thumb_func_start sub_807AEBC
sub_807AEBC:
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
	bl sub_8045128
	adds r6, r0, 0
	ldr r4, [r6, 0x14]
	cmp r4, 0
	beq _0807AF50
	adds r0, r4, 0
	bl sub_80450F8
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
	bl sub_8045108
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
	thumb_func_end sub_807AEBC

	thumb_func_start sub_807AF58
sub_807AF58:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r8, r0
	ldr r7, [r0, 0x70]
	bl sub_8072C88
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
	bl sub_8070460
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
	bl sub_8071598
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
	bl sub_8045A00
	lsls r0, 24
	cmp r0, 0
	beq _0807B098
_0807B082:
	adds r1, r4, 0x4
	mov r0, r8
	adds r0, 0x4
	bl sub_8098434
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
	bl sub_80718AC
	lsls r0, 24
	cmp r0, 0
	bne _0807B0E4
	b _0807B2C6
_0807B0E4:
	mov r0, r8
	bl sub_80719C4
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
	bl sub_80718AC
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
	bl sub_8072CA8
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
	bl sub_804954C
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
	bl sub_8049590
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _0807B216
	bl sub_80450F8
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
	bl sub_8045ABC
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
	bl sub_807B920
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
	thumb_func_end sub_807AF58

	thumb_func_start sub_807B2D8
sub_807B2D8:
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
	bl sub_80983D8
	mov r8, r0
	adds r0, r5, 0
	adds r0, 0x7A
	ldrb r1, [r0]
	mov r0, r9
	bl sub_8071470
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
	bl sub_8083478
	lsls r0, 24
	cmp r0, 0
	beq _0807B37C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8098434
	cmp r0, 0x2
	bne _0807B354
_0807B348:
	adds r0, r5, 0
	adds r0, 0x44
	movs r1, 0x1
	bl sub_8044C94
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
	bl sub_8071214
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
	bl sub_8044C94
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
	bl sub_8044C94
	ldr r3, _0807B438
	adds r1, r5, r3
	movs r0, 0x1
	strb r0, [r1]
	b _0807B5CE
	.align 2, 0
_0807B434: .4byte gUnknown_80F4448
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
	bl sub_8071518
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
	bl sub_8071214
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
	bl sub_8044C94
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
_0807B598: .4byte gUnknown_80F4D04
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
	thumb_func_end sub_807B2D8

	thumb_func_start sub_807B5E0
sub_807B5E0:
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
	bl sub_80450FC
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
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807B6CE
_0807B69A:
	adds r1, r4, 0x4
	adds r0, r7, 0x4
	bl sub_8098434
	ldr r3, [sp, 0x8]
	cmp r3, r0
	ble _0807B6CE
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r4, 0
	bl sub_80450FC
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
	bl sub_804954C
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
	bl sub_804954C
	ldrb r0, [r0, 0x9]
	cmp r0, r10
	beq _0807B758
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, sp
	bl sub_8071214
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
_0807B7A0: .4byte gUnknown_80F4448
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
	bl sub_807B920
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
	thumb_func_end sub_807B5E0

	thumb_func_start sub_807B920
sub_807B920:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r7, [r6, 0x70]
	bl sub_80450FC
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
	bl sub_807138C
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
	bl sub_8071214
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
_0807B9D4: .4byte gUnknown_80F4D04
_0807B9D8: .4byte gUnknown_80F4448
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
_0807BA3C: .4byte gUnknown_80F4448
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
_0807BA80: .4byte gUnknown_80F4448
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
	bl sub_804954C
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
	bl sub_804954C
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0807BB04
	adds r0, r6, 0
	adds r1, r4, 0
	mov r2, sp
	adds r2, 0x1
	bl sub_8071214
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
_0807BB14: .4byte gUnknown_80F4448
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
_0807BB74: .4byte gUnknown_80F4448
	thumb_func_end sub_807B920

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

	thumb_func_start DecideAttack
DecideAttack:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x5C
	mov r10, r0
	ldr r0, [r0, 0x70]
	mov r8, r0
	mov r0, r10
	movs r1, 0
	bl sub_8070D04
	lsls r0, 24
	cmp r0, 0
	beq _0807BBB6
	b _0807C03A
_0807BBB6:
	mov r0, r10
	movs r1, 0x1
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	beq _0807BBC6
	b _0807C03A
_0807BBC6:
	mov r0, r10
	movs r1, 0x8
	bl sub_80718AC
	lsls r0, 24
	cmp r0, 0
	beq _0807BBD6
	b _0807C03A
_0807BBD6:
	mov r0, r8
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0807BBF2
	ldr r0, _0807BC70
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_8084144
	lsls r0, 24
	cmp r0, 0
	beq _0807BBF2
	b _0807C03A
_0807BBF2:
	mov r0, r8
	adds r0, 0xC0
	ldrb r1, [r0]
	str r0, [sp, 0x50]
	cmp r1, 0
	beq _0807BC7C
	movs r5, 0
	movs r4, 0x8C
	lsls r4, 1
	add r4, r8
_0807BC06:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807BC74
	mov r0, r10
	adds r1, r4, 0
	bl sub_80570AC
	lsls r0, 24
	cmp r0, 0
	beq _0807BC74
	mov r0, r8
	adds r0, 0xC2
	ldrb r0, [r0]
	cmp r0, r5
	bne _0807BC74
	mov r0, r8
	adds r0, 0x44
	movs r1, 0x15
	bl sub_8044C94
	adds r3, r5, 0
	mov r6, r8
	adds r6, 0x48
	cmp r5, 0
	bgt _0807BC3E
	b _0807C006
_0807BC3E:
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0807BC4A
	b _0807C006
_0807BC4A:
	movs r4, 0x2
	lsls r0, r5, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	mov r7, r8
	adds r2, r0, r7
_0807BC58:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bgt _0807BC62
	b _0807C006
_0807BC62:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _0807BC58
	b _0807C006
	.align 2, 0
_0807BC70: .4byte gUnknown_80F4DB2
_0807BC74:
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	ble _0807BC06
_0807BC7C:
	movs r0, 0
	str r0, [sp, 0x44]
	movs r1, 0
	str r1, [sp, 0x40]
	movs r2, 0x8C
	lsls r2, 1
	add r2, r8
	movs r4, 0x1
	movs r3, 0x4
	movs r5, 0x3
_0807BC90:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0807BCB0
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0807BCA8
	ldr r7, [sp, 0x40]
	adds r7, 0x1
	str r7, [sp, 0x40]
_0807BCA8:
	ldrb r0, [r2, 0x4]
	ldr r1, [sp, 0x44]
	adds r1, r0
	str r1, [sp, 0x44]
_0807BCB0:
	adds r2, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _0807BC90
	ldr r2, [sp, 0x44]
	cmp r2, 0
	bne _0807BCF8
	add r4, sp, 0x2C
	movs r1, 0xB0
	lsls r1, 1
	adds r0, r4, 0
	bl sub_8092A88
	mov r0, sp
	mov r1, r10
	adds r2, r4, 0
	bl sub_807C04C
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807BCDE
	b _0807C03A
_0807BCDE:
	mov r0, r8
	adds r0, 0x44
	movs r1, 0x17
	bl sub_8044C94
	mov r0, sp
	ldrb r1, [r0, 0x1]
	movs r0, 0x7
	ands r0, r1
	mov r1, r8
	adds r1, 0x46
	strb r0, [r1]
	b _0807C008
_0807BCF8:
	mov r0, r10
	movs r1, 0xB
	bl HasIQSkill
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x48]
	mov r0, r10
	movs r1, 0x6
	bl HasIQSkill
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x3C]
	movs r7, 0
	str r7, [sp, 0x44]
	mov r0, sp
	adds r0, 0x28
	str r0, [sp, 0x4C]
	adds r2, r0, 0
	movs r1, 0x1
	adds r0, 0x3
_0807BD2A:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r2
	bge _0807BD2A
	ldr r1, [sp, 0x3C]
	cmp r1, 0
	beq _0807BDC0
	movs r2, 0x63
	movs r4, 0
	movs r5, 0
	movs r3, 0x8C
	lsls r3, 1
	add r3, r8
	b _0807BD98
_0807BD46:
	cmp r5, 0
	beq _0807BD7A
	ldrb r1, [r3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0807BD7A
	adds r0, r4, 0x1
	adds r6, r5, 0x1
	cmp r0, r5
	bge _0807BD74
	cmp r2, 0x1
	bgt _0807BD74
	adds r1, r4, 0
	cmp r1, r5
	bge _0807BD74
	ldr r2, [sp, 0x4C]
	movs r4, 0
_0807BD6A:
	adds r0, r2, r1
	strb r4, [r0]
	adds r1, 0x1
	cmp r1, r5
	blt _0807BD6A
_0807BD74:
	ldrb r2, [r3, 0x4]
	adds r4, r5, 0
	b _0807BD86
_0807BD7A:
	ldrb r1, [r3, 0x4]
	cmp r1, r2
	ble _0807BD82
	adds r1, r2, 0
_0807BD82:
	adds r2, r1, 0
	adds r6, r5, 0x1
_0807BD86:
	adds r5, r6, 0
	cmp r5, 0x3
	bgt _0807BDA2
	lsls r0, r5, 3
	movs r7, 0x8C
	lsls r7, 1
	adds r0, r7
	mov r1, r8
	adds r3, r1, r0
_0807BD98:
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0807BD46
_0807BDA2:
	adds r0, r4, 0x1
	cmp r0, r5
	bge _0807BDC0
	cmp r2, 0x1
	bgt _0807BDC0
	adds r1, r4, 0
	cmp r1, r5
	bge _0807BDC0
	ldr r2, [sp, 0x4C]
	movs r3, 0
_0807BDB6:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, 0x1
	cmp r1, r5
	blt _0807BDB6
_0807BDC0:
	movs r5, 0
	movs r2, 0
	str r2, [sp, 0x54]
	add r4, sp, 0x4
	movs r7, 0x8C
	lsls r7, 1
	add r7, r8
	adds r6, r7, 0
	mov r9, sp
	mov r0, sp
	str r0, [sp, 0x58]
_0807BDD6:
	movs r2, 0
	mov r1, r9
	strb r2, [r1]
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807BE64
	ldr r1, [sp, 0x4C]
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807BE64
	mov r0, r10
	adds r1, r5, 0
	ldr r2, [sp, 0x3C]
	bl sub_8057348
	lsls r0, 24
	cmp r0, 0
	beq _0807BE64
	ldrb r1, [r7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0807BE64
	movs r0, 0x1
	mov r2, r9
	strb r0, [r2]
	ldr r1, [sp, 0x50]
	ldrb r0, [r1]
	cmp r0, 0xB
	bne _0807BE38
	ldrh r0, [r7, 0x2]
	cmp r0, 0x80
	bne _0807BE24
	movs r2, 0
	str r2, [r4]
	b _0807BE64
_0807BE24:
	mov r0, r10
	adds r1, r6, 0
	bl sub_8071A1C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	beq _0807BE4A
	movs r0, 0x1
	b _0807BE54
_0807BE38:
	ldr r1, [sp, 0x48]
	cmp r1, 0
	beq _0807BE4A
	ldr r0, [sp, 0x58]
	mov r1, r10
	adds r2, r6, 0
	bl sub_807C04C
	b _0807BE54
_0807BE4A:
	adds r0, r6, 0
	bl sub_8092B90
	lsls r0, 24
	lsrs r0, 24
_0807BE54:
	str r0, [r4]
	add r0, sp, 0x4
	ldr r2, [sp, 0x54]
	adds r0, r2
	ldr r0, [r0]
	ldr r1, [sp, 0x44]
	adds r1, r0
	str r1, [sp, 0x44]
_0807BE64:
	ldr r2, [sp, 0x54]
	adds r2, 0x8
	str r2, [sp, 0x54]
	adds r4, 0x8
	adds r7, 0x8
	adds r6, 0x8
	movs r0, 0x8
	add r9, r0
	ldr r1, [sp, 0x58]
	adds r1, 0x8
	str r1, [sp, 0x58]
	adds r5, 0x1
	cmp r5, 0x3
	ble _0807BDD6
	movs r0, 0
	str r0, [sp, 0x24]
	mov r0, r10
	movs r1, 0x17
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807BECA
	ldr r2, [sp, 0x50]
	ldrb r0, [r2]
	cmp r0, 0xB
	beq _0807BECA
	add r0, sp, 0x20
	movs r1, 0x1
	strb r1, [r0]
	ldrb r0, [r2]
	cmp r0, 0xB
	bne _0807BEAA
	str r1, [sp, 0x24]
	b _0807BEC2
_0807BEAA:
	ldr r7, [sp, 0x48]
	cmp r7, 0
	beq _0807BEB4
	movs r0, 0x2
	b _0807BEC0
_0807BEB4:
	ldr r0, _0807BEE8
	ldr r2, [sp, 0x40]
	lsls r1, r2, 1
	adds r1, r0
	movs r7, 0
	ldrsh r0, [r1, r7]
_0807BEC0:
	str r0, [sp, 0x24]
_0807BEC2:
	ldr r0, [sp, 0x24]
	ldr r1, [sp, 0x44]
	adds r1, r0
	str r1, [sp, 0x44]
_0807BECA:
	ldr r2, [sp, 0x48]
	cmp r2, 0
	beq _0807BF2A
	movs r5, 0
	movs r7, 0
	str r7, [sp, 0x44]
	add r0, sp, 0x4
	adds r3, r0, 0
	mov r2, sp
	movs r4, 0x4
_0807BEDE:
	ldrb r1, [r2]
	cmp r1, 0
	bne _0807BEEC
	str r1, [r3]
	b _0807BEF4
	.align 2, 0
_0807BEE8: .4byte gUnknown_80F4E22
_0807BEEC:
	ldr r1, [r3]
	cmp r5, r1
	bge _0807BEF4
	adds r5, r1, 0
_0807BEF4:
	adds r3, 0x8
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _0807BEDE
	movs r4, 0
	movs r6, 0
	adds r1, r0, 0
	adds r3, r1, 0
	mov r2, sp
_0807BF08:
	ldrb r0, [r2]
	cmp r0, 0
	beq _0807BF1E
	ldr r0, [r1]
	cmp r5, r0
	beq _0807BF16
	str r6, [r1]
_0807BF16:
	ldr r0, [r3]
	ldr r7, [sp, 0x44]
	adds r7, r0
	str r7, [sp, 0x44]
_0807BF1E:
	adds r1, 0x8
	adds r3, 0x8
	adds r2, 0x8
	adds r4, 0x1
	cmp r4, 0x4
	ble _0807BF08
_0807BF2A:
	ldr r0, [sp, 0x44]
	cmp r0, 0
	bne _0807BF32
	b _0807C03A
_0807BF32:
	bl DungeonRandomCapped
	str r0, [sp, 0x38]
	movs r1, 0
	mov r9, r1
	mov r0, r10
	movs r1, 0x17
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807BF5A
	add r1, sp, 0x34
	mov r0, r10
	movs r2, 0x1
	bl sub_807C854
	lsls r0, 24
	lsrs r6, r0, 24
	b _0807BF5E
_0807BF5A:
	movs r6, 0
	str r6, [sp, 0x34]
_0807BF5E:
	movs r5, 0
	mov r4, sp
	movs r7, 0
_0807BF64:
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807C010
	add r0, sp, 0x4
	adds r0, r7
	ldr r0, [r0]
	cmp r0, 0
	beq _0807C010
	add r9, r0
	ldr r2, [sp, 0x38]
	cmp r9, r2
	blt _0807C010
	cmp r5, 0x4
	bne _0807BF9C
	cmp r6, 0
	beq _0807C03A
	mov r0, r8
	adds r0, 0x44
	movs r1, 0x32
	bl sub_8044C94
	ldr r0, [sp, 0x34]
	movs r1, 0x7
	ands r0, r1
	mov r1, r8
	adds r1, 0x46
	strb r0, [r1]
	b _0807C008
_0807BF9C:
	movs r0, 0x8C
	lsls r0, 1
	mov r9, r0
	adds r2, r7, r0
	add r2, r8
	adds r0, r4, 0
	mov r1, r10
	bl sub_807C04C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807C01A
	mov r0, r8
	adds r0, 0x44
	movs r1, 0x15
	bl sub_8044C94
	adds r3, r5, 0
	mov r6, r8
	adds r6, 0x48
	movs r1, 0x46
	add r1, r8
	mov r12, r1
	cmp r5, 0
	ble _0807BFFC
	mov r2, r8
	adds r0, r2, r7
	add r0, r9
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0807BFFC
	movs r7, 0x2
	lsls r0, r5, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r2, r0, r2
_0807BFEA:
	subs r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	ble _0807BFFC
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _0807BFEA
_0807BFFC:
	ldrb r1, [r4, 0x1]
	movs r0, 0x7
	ands r0, r1
	mov r2, r12
	strb r0, [r2]
_0807C006:
	strb r3, [r6]
_0807C008:
	mov r0, r10
	bl sub_8069DCC
	b _0807C03A
_0807C010:
	adds r4, 0x8
	adds r7, 0x8
	adds r5, 0x1
	cmp r5, 0x4
	ble _0807BF64
_0807C01A:
	cmp r6, 0
	beq _0807C03A
	mov r0, r8
	adds r0, 0x44
	movs r1, 0x32
	bl sub_8044C94
	ldr r0, [sp, 0x34]
	movs r1, 0x7
	ands r0, r1
	mov r1, r8
	adds r1, 0x46
	strb r0, [r1]
	mov r0, r10
	bl sub_8069DCC
_0807C03A:
	add sp, 0x5C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DecideAttack

	thumb_func_start sub_807C04C
sub_807C04C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	str r0, [sp, 0x8]
	adds r6, r1, 0
	mov r10, r2
	movs r0, 0x1
	str r0, [sp, 0x10]
	ldr r4, [r6, 0x70]
	movs r1, 0
	mov r8, r1
	ldr r1, _0807C0C8
	movs r2, 0
	adds r0, r1, 0x7
_0807C06E:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _0807C06E
	adds r0, r6, 0
	mov r1, r10
	movs r2, 0x1
	bl sub_807CD64
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0xC]
	adds r0, r6, 0
	movs r1, 0x8
	bl HasIQSkill
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	movs r0, 0
	ldr r2, [sp, 0x8]
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0807C0B0
	mov r0, r10
	bl sub_8092C54
	lsls r0, 24
	cmp r0, 0
	beq _0807C0C4
_0807C0B0:
	ldr r3, [sp, 0x14]
	cmp r3, 0
	beq _0807C0CC
	adds r0, r6, 0
	mov r1, r10
	bl sub_805C498
	lsls r0, 24
	cmp r0, 0
	bne _0807C0CC
_0807C0C4:
	movs r0, 0x1
	b _0807C48C
	.align 2, 0
_0807C0C8: .4byte gUnknown_202F380
_0807C0CC:
	movs r0, 0xF0
	ldr r1, [sp, 0xC]
	ands r0, r1
	cmp r0, 0
	beq _0807C0DE
	cmp r0, 0x10
	beq _0807C0DE
	cmp r0, 0x20
	bne _0807C19C
_0807C0DE:
	adds r0, r4, 0
	adds r0, 0xE8
	ldrb r1, [r0]
	cmp r1, 0x1
	bne _0807C128
	subs r0, 0xA2
	ldrb r7, [r0]
	ldr r0, _0807C118
	adds r0, r7, r0
	ldrb r3, [r0]
	cmp r3, 0
	beq _0807C0F8
	b _0807C3F6
_0807C0F8:
	strb r1, [r0]
	ldr r0, _0807C11C
	add r0, r8
	strb r7, [r0]
	ldr r0, _0807C120
	mov r4, r8
	lsls r2, r4, 2
	adds r0, r2, r0
	movs r1, 0x63
	str r1, [r0]
	ldr r0, _0807C124
	adds r2, r0
	str r3, [r2]
	movs r0, 0x1
	add r8, r0
	b _0807C3F6
	.align 2, 0
_0807C118: .4byte gUnknown_202F380
_0807C11C: .4byte gUnknown_202F388
_0807C120: .4byte gUnknown_202F390
_0807C124: .4byte gUnknown_202F3B0
_0807C128:
	movs r7, 0
	movs r0, 0xF0
	ldr r1, [sp, 0xC]
	ands r0, r1
	lsls r5, r0, 16
_0807C132:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	ldr r1, _0807C198
	lsls r2, r7, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r4, 0x6
	ldrsh r1, [r6, r4]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl sub_804954C
	ldr r4, [r0, 0x10]
	cmp r4, 0
	beq _0807C18E
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0807C18E
	asrs r0, r5, 16
	cmp r0, 0x10
	beq _0807C178
	cmp r0, 0x20
	beq _0807C178
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_8071138
	lsls r0, 24
	cmp r0, 0
	beq _0807C18E
_0807C178:
	mov r0, r10
	str r0, [sp]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_807C580
	mov r8, r0
_0807C18E:
	adds r7, 0x1
	cmp r7, 0x7
	ble _0807C132
	b _0807C3F6
	.align 2, 0
_0807C198: .4byte gUnknown_80F4448
_0807C19C:
	cmp r0, 0x30
	bne _0807C1F0
	movs r5, 0
_0807C1A2:
	ldr r0, _0807C1E8
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807C1EC
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807C1E0
	adds r0, r6, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0807C1E0
	mov r3, r10
	str r3, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_807C580
	mov r8, r0
_0807C1E0:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807C1A2
	b _0807C3F6
	.align 2, 0
_0807C1E8: .4byte gDungeonGlobalData
_0807C1EC: .4byte 0x000135cc
_0807C1F0:
	cmp r0, 0x40
	bne _0807C2A8
	movs r7, 0
	ldr r1, _0807C2A4
	mov r9, r1
_0807C1FA:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	mov r3, r9
	movs r4, 0
	ldrsh r1, [r3, r4]
	adds r0, r1
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	movs r4, 0x2
	ldrsh r2, [r3, r4]
	adds r1, r2
	bl sub_804954C
	adds r4, r0, 0
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_8071138
	lsls r0, 24
	cmp r0, 0
	beq _0807C296
	ldr r5, [r4, 0x10]
	cmp r5, 0
	beq _0807C250
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0807C250
	mov r4, r8
	mov r0, r10
	str r0, [sp]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_807C580
	mov r8, r0
	cmp r4, r8
	bne _0807C296
_0807C250:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	mov r3, r9
	movs r4, 0
	ldrsh r1, [r3, r4]
	lsls r1, 1
	adds r0, r1
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	movs r4, 0x2
	ldrsh r2, [r3, r4]
	lsls r2, 1
	adds r1, r2
	bl sub_804954C
	adds r4, r0, 0
	ldr r5, [r4, 0x10]
	cmp r5, 0
	beq _0807C296
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0807C296
	mov r0, r10
	str r0, [sp]
	ldr r1, [sp, 0x14]
	str r1, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_807C580
	mov r8, r0
_0807C296:
	movs r2, 0x4
	add r9, r2
	adds r7, 0x1
	cmp r7, 0x7
	ble _0807C1FA
	b _0807C3F6
	.align 2, 0
_0807C2A4: .4byte gUnknown_80F4448
_0807C2A8:
	cmp r0, 0x50
	beq _0807C2B0
	cmp r0, 0x80
	bne _0807C394
_0807C2B0:
	movs r3, 0x1
	str r3, [sp, 0x18]
	cmp r0, 0x50
	bne _0807C2BC
	movs r4, 0xA
	str r4, [sp, 0x18]
_0807C2BC:
	movs r0, 0
	mov r9, r0
_0807C2C0:
	ldr r0, _0807C37C
	ldr r0, [r0]
	mov r2, r9
	lsls r1, r2, 2
	ldr r3, _0807C380
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	cmp r6, r4
	beq _0807C370
	adds r1, r4, 0x4
	adds r0, r6, 0x4
	bl sub_80983D8
	adds r5, r0, 0
	ldr r0, _0807C384
	adds r7, r5, r0
	ldrb r0, [r7]
	cmp r0, 0
	bne _0807C370
	adds r0, r6, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	adds r0, r6, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x18]
	bl sub_807C4A0
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	ldr r0, [sp, 0x14]
	str r0, [sp]
	ldr r0, [sp, 0xC]
	adds r1, r6, 0
	adds r2, r4, 0
	mov r3, r10
	bl sub_807C648
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	ldr r3, [sp, 0x18]
	bl sub_807C9F8
	lsls r0, 24
	cmp r0, 0
	beq _0807C370
	movs r0, 0x1
	strb r0, [r7]
	ldr r0, _0807C388
	add r0, r8
	strb r5, [r0]
	adds r0, r6, 0
	mov r1, r10
	bl sub_8071A1C
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	ldr r1, [sp, 0xC]
	adds r2, r4, 0
	bl sub_807C7AC
	ldr r1, _0807C38C
	mov r3, r8
	lsls r2, r3, 2
	adds r1, r2, r1
	str r0, [r1]
	ldr r0, _0807C390
	adds r2, r0
	str r4, [r2]
	movs r4, 0x1
	add r8, r4
_0807C370:
	movs r0, 0x1
	add r9, r0
	mov r1, r9
	cmp r1, 0x13
	ble _0807C2C0
	b _0807C3F6
	.align 2, 0
_0807C37C: .4byte gDungeonGlobalData
_0807C380: .4byte 0x000135cc
_0807C384: .4byte gUnknown_202F380
_0807C388: .4byte gUnknown_202F388
_0807C38C: .4byte gUnknown_202F390
_0807C390: .4byte gUnknown_202F3B0
_0807C394:
	cmp r0, 0x60
	bne _0807C3DC
	movs r5, 0
_0807C39A:
	ldr r0, _0807C3D4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807C3D8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807C3CA
	mov r3, r10
	str r3, [sp]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_807C580
	mov r8, r0
_0807C3CA:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0807C39A
	b _0807C3F6
	.align 2, 0
_0807C3D4: .4byte gDungeonGlobalData
_0807C3D8: .4byte 0x000135cc
_0807C3DC:
	cmp r0, 0x70
	bne _0807C3F6
	mov r1, r10
	str r1, [sp]
	ldr r2, [sp, 0x14]
	str r2, [sp, 0x4]
	mov r0, r8
	ldr r1, [sp, 0xC]
	adds r2, r6, 0
	adds r3, r6, 0
	bl sub_807C580
	mov r8, r0
_0807C3F6:
	mov r3, r8
	cmp r3, 0
	bne _0807C402
	ldr r4, [sp, 0x8]
	strb r3, [r4]
	b _0807C48A
_0807C402:
	movs r4, 0
	movs r3, 0
	mov r0, r8
	cmp r0, 0
	ble _0807C420
	ldr r2, _0807C464
	mov r1, r8
_0807C410:
	ldr r0, [r2]
	cmp r3, r0
	bge _0807C418
	adds r3, r0, 0
_0807C418:
	adds r2, 0x4
	subs r1, 0x1
	cmp r1, 0
	bne _0807C410
_0807C420:
	mov r1, r8
	cmp r1, 0
	ble _0807C43A
	movs r5, 0
	ldr r2, _0807C464
_0807C42A:
	ldr r0, [r2]
	cmp r3, r0
	beq _0807C432
	str r5, [r2]
_0807C432:
	adds r2, 0x4
	subs r1, 0x1
	cmp r1, 0
	bne _0807C42A
_0807C43A:
	str r3, [sp, 0x10]
	mov r2, r8
	cmp r2, 0
	ble _0807C450
	ldr r2, _0807C464
	mov r1, r8
_0807C446:
	ldm r2!, {r0}
	adds r4, r0
	subs r1, 0x1
	cmp r1, 0
	bne _0807C446
_0807C450:
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r2, r0, 0
	movs r1, 0
	cmp r1, r8
	bge _0807C478
	ldr r3, _0807C464
	b _0807C470
	.align 2, 0
_0807C464: .4byte gUnknown_202F390
_0807C468:
	adds r3, 0x4
	adds r1, 0x1
	cmp r1, r8
	bge _0807C478
_0807C470:
	ldr r0, [r3]
	subs r2, r0
	cmp r2, 0
	bge _0807C468
_0807C478:
	movs r0, 0x1
	ldr r3, [sp, 0x8]
	strb r0, [r3]
	ldr r0, _0807C49C
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r3, 0x1]
	movs r0, 0x8
	str r0, [r3, 0x4]
_0807C48A:
	ldr r0, [sp, 0x10]
_0807C48C:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807C49C: .4byte gUnknown_202F388
	thumb_func_end sub_807C04C

	thumb_func_start sub_807C4A0
sub_807C4A0:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	cmp r3, 0
	bge _0807C4B6
	negs r3, r3
_0807C4B6:
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	subs r1, r0
	cmp r1, 0
	bge _0807C4C6
	negs r1, r1
_0807C4C6:
	adds r0, r1, 0
	cmp r1, r3
	bge _0807C4CE
	adds r0, r3, 0
_0807C4CE:
	cmp r0, 0xA
	bgt _0807C578
	cmp r0, r2
	bgt _0807C578
	movs r6, 0x1
	negs r6, r6
	cmp r3, r1
	bne _0807C516
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bge _0807C4FE
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0807C574
	cmp r1, r0
	bgt _0807C574
_0807C4FE:
	lsls r1, r2, 16
	lsls r0, r3, 16
	movs r6, 0x7
	cmp r1, r0
	ble _0807C570
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble _0807C570
	b _0807C574
_0807C516:
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bne _0807C532
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0807C574
_0807C532:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bge _0807C546
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	beq _0807C574
_0807C546:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bne _0807C55A
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bgt _0807C574
_0807C55A:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	ble _0807C570
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _0807C570
	movs r6, 0x6
_0807C570:
	cmp r6, 0
	blt _0807C578
_0807C574:
	movs r0, 0x1
	b _0807C57A
_0807C578:
	movs r0, 0
_0807C57A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807C4A0

	thumb_func_start sub_807C580
sub_807C580:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x28]
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r2, [r5, 0x70]
	ldr r1, [r5, 0x4]
	ldr r0, [r7, 0x4]
	cmp r1, r0
	beq _0807C5BC
	movs r0, 0xF0
	mov r1, r9
	ands r0, r1
	cmp r0, 0x30
	beq _0807C5BC
	cmp r0, 0x60
	beq _0807C5BC
	cmp r0, 0x70
	bne _0807C5C4
_0807C5BC:
	adds r0, r2, 0
	adds r0, 0x46
	ldrb r4, [r0]
	b _0807C5CE
_0807C5C4:
	adds r0, r5, 0x4
	adds r1, r7, 0x4
	bl sub_80983D8
	adds r4, r0, 0
_0807C5CE:
	ldr r0, _0807C638
	adds r0, r4
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807C624
	mov r0, r10
	str r0, [sp]
	mov r0, r9
	adds r1, r5, 0
	adds r2, r7, 0
	ldr r3, [sp, 0x24]
	bl sub_807C648
	lsls r0, 24
	cmp r0, 0
	beq _0807C624
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	ldr r0, _0807C63C
	adds r0, r6, r0
	strb r4, [r0]
	adds r0, r5, 0
	ldr r1, [sp, 0x24]
	bl sub_8071A1C
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r5, 0
	mov r1, r9
	adds r2, r7, 0
	bl sub_807C7AC
	ldr r1, _0807C640
	lsls r2, r6, 2
	adds r1, r2, r1
	str r0, [r1]
	ldr r0, _0807C644
	adds r2, r0
	str r7, [r2]
	adds r6, 0x1
_0807C624:
	adds r0, r6, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807C638: .4byte gUnknown_202F380
_0807C63C: .4byte gUnknown_202F388
_0807C640: .4byte gUnknown_202F390
_0807C644: .4byte gUnknown_202F3B0
	thumb_func_end sub_807C580

	thumb_func_start sub_807C648
sub_807C648:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r1, [sp, 0x1C]
	lsls r0, 16
	asrs r6, r0, 16
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r7, 0
	movs r0, 0xF
	ands r0, r6
	adds r1, r0, 0
	cmp r1, 0
	bne _0807C686
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807C6E0
	movs r7, 0x1
	b _0807C6E4
_0807C686:
	cmp r1, 0x1
	beq _0807C6BE
	cmp r1, 0x2
	bne _0807C692
	ldr r1, [r4, 0x70]
	b _0807C69C
_0807C692:
	cmp r1, 0x5
	bne _0807C6B6
	ldr r1, [r4, 0x70]
	cmp r5, r4
	beq _0807C6B2
_0807C69C:
	movs r7, 0x1
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	beq _0807C6B2
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0807C6B2
	cmp r0, 0x1
	bne _0807C6E0
_0807C6B2:
	movs r0, 0
	b _0807C7A0
_0807C6B6:
	cmp r1, 0x6
	bne _0807C6D4
	cmp r5, r4
	beq _0807C6B2
_0807C6BE:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8071598
	lsls r0, 24
	cmp r0, 0
	bne _0807C6E0
	movs r7, 0x1
	b _0807C6E4
_0807C6D4:
	subs r0, 0x3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0807C6E0
	movs r7, 0x1
_0807C6E0:
	cmp r7, 0
	beq _0807C79E
_0807C6E4:
	mov r0, r9
	cmp r0, 0
	beq _0807C77C
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl sub_805CEB8
	lsls r0, 24
	cmp r0, 0
	beq _0807C6B2
	movs r1, 0xF0
	lsls r1, 4
	ands r1, r6
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _0807C78A
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	beq _0807C76E
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	bne _0807C720
	adds r0, r4, 0
	bl sub_8070A58
	b _0807C774
_0807C720:
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	bne _0807C730
	adds r0, r4, 0
	bl sub_8070B28
	b _0807C774
_0807C730:
	movs r0, 0xC0
	lsls r0, 3
	cmp r1, r0
	bne _0807C75A
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _0807C74E
	adds r0, r1, 0
	adds r0, 0x5D
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _0807C6B2
_0807C74E:
	adds r0, r1, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807C79E
	b _0807C6B2
_0807C75A:
	movs r0, 0xA0
	lsls r0, 3
	cmp r1, r0
	bne _0807C79E
	adds r0, r4, 0
	bl sub_8070A58
	lsls r0, 24
	cmp r0, 0
	bne _0807C79E
_0807C76E:
	adds r0, r4, 0
	bl sub_8070B48
_0807C774:
	lsls r0, 24
	cmp r0, 0
	bne _0807C79E
	b _0807C6B2
_0807C77C:
	movs r0, 0xF0
	lsls r0, 4
	ands r0, r6
	movs r1, 0x80
	lsls r1, 1
	cmp r0, r1
	bne _0807C79E
_0807C78A:
	mov r0, r8
	movs r1, 0x2
	bl sub_8092BD8
	adds r4, r0, 0
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, r4
	bge _0807C6B2
_0807C79E:
	adds r0, r7, 0
_0807C7A0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807C648

	thumb_func_start sub_807C7AC
sub_807C7AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	mov r8, r2
	lsls r1, 16
	asrs r1, 16
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r6, 0x1
	ldr r4, [r2, 0x70]
	adds r7, r4, 0
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	beq _0807C7D6
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _0807C7DA
_0807C7D6:
	movs r0, 0x1
	b _0807C848
_0807C7DA:
	adds r0, r5, 0
	movs r1, 0x9
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C804
	ldr r0, _0807C7FC
	ldr r0, [r0]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r2, _0807C800
	adds r0, r2
	adds r0, r1
	ldrb r6, [r0]
	b _0807C846
	.align 2, 0
_0807C7FC: .4byte gDungeonGlobalData
_0807C800: .4byte 0x0000363c
_0807C804:
	adds r0, r5, 0
	movs r1, 0xA
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C828
	ldrb r1, [r7, 0xE]
	movs r2, 0xC
	negs r2, r2
	adds r0, r2, 0
	subs r0, r1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0807C846
	movs r6, 0x1
	b _0807C846
_0807C828:
	adds r0, r5, 0
	movs r1, 0xB
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C846
	adds r0, r5, 0
	mov r1, r8
	mov r2, r9
	bl sub_806E654
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0807C846:
	adds r0, r6, 0
_0807C848:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807C7AC

	thumb_func_start sub_807C854
sub_807C854:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	adds r7, r0, 0
	str r1, [sp, 0x40]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x44]
	ldr r0, [r7, 0x70]
	movs r1, 0
	mov r8, r1
	adds r1, r0, 0
	adds r1, 0x46
	ldrb r6, [r1]
	adds r0, 0xE8
	ldrb r0, [r0]
	movs r3, 0x8
	mov r10, r3
	cmp r0, 0x1
	bne _0807C886
	movs r0, 0x1
	mov r10, r0
_0807C886:
	movs r4, 0
	adds r0, r7, 0
	movs r1, 0x9
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807C8A4
	adds r0, r7, 0
	movs r1, 0xA
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0807C8A6
_0807C8A4:
	movs r4, 0x1
_0807C8A6:
	str r4, [sp, 0x48]
	adds r0, r7, 0
	movs r1, 0x8
	bl HasIQSkill
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4C]
	movs r1, 0
	mov r9, r1
	cmp r9, r10
	bge _0807C952
_0807C8BE:
	movs r0, 0x7
	ands r6, r0
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	ldr r1, _0807C95C
	lsls r2, r6, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r7, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl sub_804954C
	ldr r5, [r0, 0x10]
	cmp r5, 0
	beq _0807C948
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0807C948
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_8071138
	lsls r0, 24
	cmp r0, 0
	beq _0807C948
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0
	ldr r3, [sp, 0x44]
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0807C948
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0807C922
	ldr r0, [r5, 0x70]
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0807C948
_0807C922:
	mov r1, r8
	lsls r4, r1, 2
	mov r3, sp
	adds r0, r3, r4
	str r6, [r0]
	adds r0, r7, 0
	movs r1, 0
	adds r2, r5, 0
	movs r3, 0
	bl sub_807C7AC
	add r1, sp, 0x20
	adds r1, r4
	str r0, [r1]
	ldr r0, [sp, 0x48]
	cmp r0, 0
	beq _0807C960
	movs r1, 0x1
	add r8, r1
_0807C948:
	movs r3, 0x1
	add r9, r3
	adds r6, 0x1
	cmp r9, r10
	blt _0807C8BE
_0807C952:
	mov r0, r8
	cmp r0, 0
	bne _0807C966
	movs r0, 0
	b _0807C9E8
	.align 2, 0
_0807C95C: .4byte gUnknown_80F4448
_0807C960:
	ldr r1, [sp, 0x40]
	str r6, [r1]
	b _0807C9E6
_0807C966:
	movs r4, 0
	movs r3, 0
	mov r0, r8
	cmp r0, 0
	ble _0807C984
	add r1, sp, 0x20
	mov r2, r8
_0807C974:
	ldr r0, [r1]
	cmp r3, r0
	bge _0807C97C
	adds r3, r0, 0
_0807C97C:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _0807C974
_0807C984:
	mov r1, r8
	cmp r1, 0
	ble _0807C9A0
	movs r5, 0
	add r1, sp, 0x20
	mov r2, r8
_0807C990:
	ldr r0, [r1]
	cmp r3, r0
	beq _0807C998
	str r5, [r1]
_0807C998:
	adds r1, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _0807C990
_0807C9A0:
	mov r3, r8
	cmp r3, 0
	ble _0807C9B4
	add r1, sp, 0x20
	mov r2, r8
_0807C9AA:
	ldm r1!, {r0}
	adds r4, r0
	subs r2, 0x1
	cmp r2, 0
	bne _0807C9AA
_0807C9B4:
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r1, r0, 0
	movs r2, 0
	cmp r2, r8
	bge _0807C9DC
	ldr r0, [sp, 0x20]
	subs r1, r0
	cmp r1, 0
	blt _0807C9DC
	add r3, sp, 0x20
_0807C9CC:
	adds r3, 0x4
	adds r2, 0x1
	cmp r2, r8
	bge _0807C9DC
	ldr r0, [r3]
	subs r1, r0
	cmp r1, 0
	bge _0807C9CC
_0807C9DC:
	lsls r0, r2, 2
	add r0, sp
	ldr r0, [r0]
	ldr r1, [sp, 0x40]
	str r0, [r1]
_0807C9E6:
	movs r0, 0x1
_0807C9E8:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807C854

	thumb_func_start sub_807C9F8
sub_807C9F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	mov r10, r1
	adds r7, r2, 0
	adds r5, r3, 0
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	mov r2, r10
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	subs r2, r1, r0
	cmp r2, 0
	bge _0807CA1C
	negs r2, r2
_0807CA1C:
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	mov r3, r10
	movs r6, 0x6
	ldrsh r0, [r3, r6]
	subs r6, r1, r0
	cmp r6, 0
	bge _0807CA2E
	negs r6, r6
_0807CA2E:
	cmp r6, r2
	bge _0807CA34
	adds r6, r2, 0
_0807CA34:
	cmp r6, r5
	ble _0807CA3A
	adds r6, r5, 0
_0807CA3A:
	adds r0, r4, 0
	movs r1, 0x3
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0807CA50
	cmp r6, r5
	bgt _0807CAAC
_0807CA4C:
	movs r0, 0x1
	b _0807CAAE
_0807CA50:
	movs r0, 0x4
	ldrsh r5, [r4, r0]
	movs r1, 0x6
	ldrsh r4, [r4, r1]
	ldr r1, _0807CA70
	lsls r0, r7, 2
	adds r0, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	mov r9, r2
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	mov r8, r1
	movs r7, 0
	b _0807CA94
	.align 2, 0
_0807CA70: .4byte gUnknown_80F4448
_0807CA74:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_804954C
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0807CAAC
	ldr r0, [r2, 0x10]
	cmp r0, r10
	beq _0807CA4C
	cmp r0, 0
	bne _0807CAAC
	adds r7, 0x1
_0807CA94:
	cmp r7, r6
	bgt _0807CAAC
	add r5, r9
	add r4, r8
	cmp r5, 0
	ble _0807CAAC
	cmp r4, 0
	ble _0807CAAC
	cmp r5, 0x36
	bgt _0807CAAC
	cmp r4, 0x1E
	ble _0807CA74
_0807CAAC:
	movs r0, 0
_0807CAAE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807C9F8

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
	bl sub_80441BC
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
	bl sub_8092A88
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
	bl sub_807C04C
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
	bl sub_8069DCC
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

	thumb_func_start sub_807CD64
sub_807CD64:
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
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _0807CD88
	movs r0, 0x73
	b _0807CD94
_0807CD88:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8092AE0
	lsls r0, 16
	asrs r0, 16
_0807CD94:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_807CD64

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
	bl sub_80441E8
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
	bl sub_8071824
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
	bl sub_804954C
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
	bl sub_8092A88
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
_0807D044: .4byte gUnknown_80F4448
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
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0807D188
	ldr r0, _0807D184
	b _0807D194
	.align 2, 0
_0807D180: .4byte gAvailablePokemonNames
_0807D184: .4byte gUnknown_80FCAE8
_0807D188:
	bl sub_80441E8
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
	bl sub_80450FC
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
	bl sub_804954C
	ldr r4, [r0, 0x14]
	cmp r4, 0
	beq _0807D506
	adds r0, r4, 0
	bl sub_80450F8
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
	bl sub_804954C
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
	bl sub_804954C
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
	bl sub_8045108
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
	bl sub_8071824
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
	bl sub_80441E8
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
	bl sub_804954C
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
_0807DAFC: .4byte gUnknown_80F4448
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
	bl sub_80441E8
	lsls r0, 24
	cmp r0, 0
	beq _0807DB94
	ldr r0, _0807DB90
	b _0807DBA0
	.align 2, 0
_0807DB90: .4byte gUnknown_80FD060
_0807DB94:
	bl sub_804AF74
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
	bl sub_8049590
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
	bl sub_80441BC
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
	bl sub_8049590
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
	bl sub_8049590
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
	bl sub_8049590
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
	bl sub_804954C
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
	bl sub_8071824
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
	bl sub_807E580
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
	bl sub_8049590
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
	bl sub_80450F8
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
	bl sub_80450F8
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
	bl sub_80450F8
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
	bl sub_8092A88
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
	bl sub_8071858
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
	bl sub_8071858
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
	bl sub_8071824
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
	bl sub_8071824
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
	bl sub_8083600
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
	bl sub_807520C
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
	bl sub_807520C
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
	bl sub_807520C
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
	bl sub_807520C
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

	thumb_func_start sub_807E580
sub_807E580:
	push {lr}
	cmp r0, 0
	beq _0807E596
	movs r1, 0x2D
	bl sub_8046CB0
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
	thumb_func_end sub_807E580

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
	bl sub_8069E8C
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
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 16
	str r0, [sp, 0x4]
	ldr r0, _0807E724
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	mov r10, r0
	movs r0, 0
	bl sub_807E580
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
	bl sub_8083600
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
	bl sub_807E580
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
	bl sub_807E580
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
	bl sub_8070774
	adds r0, r5, 0
	movs r1, 0x25
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0807E958
	adds r0, r5, 0
	bl sub_807E580
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
	bl sub_8071824
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
	bl sub_8083600
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
	bl sub_8083600
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
	bl sub_807E580
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
	bl sub_807E580
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
	bl sub_8083600
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
	bl sub_8083600
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
	bl sub_8083600
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
	bl sub_8045128
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
	bl sub_80450FC
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_80450FC
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
	bl sub_80450FC
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_80450FC
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
	bl sub_804954C
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
	bl sub_80983D8
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
	bl sub_80983D8
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
	bl sub_8083600
	bl sub_8045128
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
	bl sub_804954C
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0807F114
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F114
	bl sub_80450F8
	cmp r0, 0x3
	bne _0807F114
	ldr r0, [r4, 0x14]
	bl sub_8045108
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
	bl sub_804954C
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0807F27E
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F27E
	bl sub_80450F8
	cmp r0, 0x3
	bne _0807F27E
	ldr r0, [r4, 0x14]
	bl sub_8045108
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
	bl sub_8083600
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
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807F38A
	bl sub_80450F8
	cmp r0, 0x3
	bne _0807F38A
	ldr r0, [r4, 0x14]
	bl sub_8045108
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
	bl sub_8070774
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
	bl sub_8071824
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
	bl sub_8071598
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
	bl sub_8071598
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
_0807F58C: .4byte gUnknown_80F4448
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
_0807F630: .4byte gUnknown_80F4448
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
	bl sub_80983D8
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
	bl sub_804954C
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
_0807F86C: .4byte gUnknown_80F4448
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
_0807F8D0: .4byte gUnknown_80F4448
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
	bl sub_80450F8
	cmp r0, 0x1
	bne _0807F954
	add r4, sp, 0xE4
	ldr r1, _0807F9AC
	adds r0, r4, 0
	bl sub_8092A88
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
	bl sub_8049590
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
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FB24
	bl sub_80450F8
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

	thumb_func_start sub_807FC80
sub_807FC80:
	push {lr}
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	adds r0, r2, 0
	bl sub_8049590
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
	bl sub_80450F8
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
	thumb_func_end sub_807FC80

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
	bl sub_8049590
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
	bl sub_80450F8
	cmp r0, 0x2
	bne _0807FD6E
	ldr r0, [r6, 0x14]
	bl sub_8045104
	strb r5, [r0]
	ldr r0, [r6, 0x14]
	bl sub_8045104
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
	bl sub_8049590
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FE3C
	bl sub_80450F8
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
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FE7C
	bl sub_80450F8
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
	bl sub_8049590
	str r0, [sp, 0x4]
	ldr r0, [r0, 0x14]
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x8]
	cmp r0, 0
	bne _0807FECE
	b _080801B4
_0807FECE:
	bl sub_80450F8
	cmp r0, 0x2
	beq _0807FED8
	b _080801B4
_0807FED8:
	mov r0, r10
	bl sub_8045104
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
	bl sub_80450F8
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
	bl sub_8046CB0
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
	bl sub_8046CB0
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
	bl sub_80441BC
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
	bl sub_80441BC
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
_080806D8: .4byte gUnknown_80F4448
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
	bl sub_80441BC
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
	bl sub_804954C
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
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	adds r2, r6, 0x1
	mov r9, r2
	cmp r0, 0
	beq _08080A18
	bl sub_80450F8
	cmp r0, 0x3
	bne _08080A18
	ldr r0, [r4, 0x14]
	bl sub_8045108
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
_08080AF4: .4byte gUnknown_80F4448
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
	bl sub_80450F8
	cmp r0, 0x2
	bne _08080B26
	adds r0, r4, 0
	bl sub_8045104
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
	bl sub_80450F8
	cmp r0, 0x3
	bne _08080C1A
	adds r0, r4, 0
	bl sub_8045108
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
	bl sub_80450F8
	cmp r0, 0x2
	bne _08080CC8
	adds r0, r5, 0
	bl sub_8045104
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
	bl sub_8049590
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
_08082670: .4byte gUnknown_203B450
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
_08082840: .4byte gUnknown_203B450
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
	bl sub_8049590
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
	bl sub_807191C
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
_080828D8: .4byte gUnknown_203B450
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
	bl sub_800F8D0
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl sub_8049590
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

	thumb_func_start sub_8083294
sub_8083294:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r7, _080832E8
	ldr r0, [r7]
	ldr r1, _080832EC
	adds r0, r1
	ldrb r5, [r0]
	cmp r5, 0
	bne _080832AA
	movs r5, 0x2
_080832AA:
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	bl sub_804954C
	ldrb r1, [r0, 0x9]
	cmp r1, 0xFF
	bne _080832F0
	movs r0, 0
	ldrsh r1, [r4, r0]
	movs r2, 0
	ldrsh r0, [r6, r2]
	subs r1, r0
	cmp r1, 0
	bge _080832CC
	negs r1, r1
_080832CC:
	cmp r1, r5
	bgt _0808332E
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	movs r4, 0x2
	ldrsh r0, [r6, r4]
	subs r0, r1, r0
	cmp r0, 0
	bge _080832E0
	negs r0, r0
_080832E0:
	cmp r0, r5
	bgt _0808332E
_080832E4:
	movs r0, 0x1
	b _08083330
	.align 2, 0
_080832E8: .4byte gDungeonGlobalData
_080832EC: .4byte 0x00018209
_080832F0:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, _08083338
	adds r0, r1
	ldr r1, [r7]
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	movs r4, 0
	ldrsh r3, [r6, r4]
	cmp r0, r3
	bgt _0808332E
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	movs r4, 0x2
	ldrsh r2, [r6, r4]
	cmp r0, r2
	bgt _0808332E
	movs r4, 0x6
	ldrsh r0, [r1, r4]
	adds r0, 0x1
	cmp r0, r3
	ble _0808332E
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	cmp r0, r2
	bgt _080832E4
_0808332E:
	movs r0, 0
_08083330:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08083338: .4byte 0x000104c4
	thumb_func_end sub_8083294

	thumb_func_start sub_808333C
sub_808333C:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_804954C
	ldrb r2, [r0, 0x9]
	cmp r2, 0xFF
	beq _08083394
	ldr r1, _080833C4
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	ldr r3, _080833C8
	adds r0, r3
	ldr r1, [r1]
	adds r1, r0
	movs r6, 0x2
	ldrsh r0, [r1, r6]
	subs r0, 0x1
	movs r2, 0
	ldrsh r3, [r5, r2]
	cmp r0, r3
	bgt _08083394
	movs r6, 0x4
	ldrsh r0, [r1, r6]
	subs r0, 0x1
	movs r6, 0x2
	ldrsh r2, [r5, r6]
	cmp r0, r2
	bgt _08083394
	movs r6, 0x6
	ldrsh r0, [r1, r6]
	adds r0, 0x1
	cmp r0, r3
	ble _08083394
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	cmp r0, r2
	bgt _080833DE
_08083394:
	movs r6, 0
	ldrsh r3, [r4, r6]
	movs r0, 0
	ldrsh r2, [r5, r0]
	movs r6, 0x2
	ldrsh r1, [r4, r6]
	movs r6, 0x2
	ldrsh r0, [r5, r6]
	subs r1, r0
	subs r3, r2
	cmp r3, 0
	bge _080833AE
	negs r3, r3
_080833AE:
	cmp r1, 0
	bge _080833B4
	negs r1, r1
_080833B4:
	cmp r1, r3
	bge _080833BA
	adds r1, r3, 0
_080833BA:
	cmp r1, 0x2
	ble _080833CC
_080833BE:
	movs r0, 0
	b _080833E0
	.align 2, 0
_080833C4: .4byte gDungeonGlobalData
_080833C8: .4byte 0x000104c4
_080833CC:
	cmp r1, 0x2
	bne _080833DE
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8083478
	lsls r0, 24
	cmp r0, 0
	beq _080833BE
_080833DE:
	movs r0, 0x1
_080833E0:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808333C

	thumb_func_start sub_80833E8
sub_80833E8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	bl sub_804954C
	adds r1, r0, 0
	ldr r0, _08083438
	ldr r3, [r0]
	ldr r2, _0808343C
	adds r0, r3, r2
	ldrb r2, [r0]
	cmp r2, 0
	bne _0808340C
	movs r2, 0x2
_0808340C:
	ldrb r0, [r1, 0x9]
	cmp r0, 0xFF
	bne _08083440
	movs r1, 0
	ldrsh r0, [r5, r1]
	subs r0, r2
	str r0, [r4]
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r0, r2
	adds r0, 0x1
	str r0, [r4, 0x8]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	subs r0, r2
	str r0, [r4, 0x4]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	adds r0, r2
	adds r0, 0x1
	b _0808346A
	.align 2, 0
_08083438: .4byte gDungeonGlobalData
_0808343C: .4byte 0x00018209
_08083440:
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r2, _08083474
	adds r1, r2
	adds r1, r3, r1
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	str r0, [r4]
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	adds r0, 0x2
	str r0, [r4, 0x8]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	str r0, [r4, 0x4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r0, 0x2
_0808346A:
	str r0, [r4, 0xC]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083474: .4byte 0x000104c4
	thumb_func_end sub_80833E8

	thumb_func_start sub_8083478
sub_8083478:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r3, r0, 0
	adds r6, r1, 0
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r2, 0
	ldrsh r0, [r6, r2]
	subs r1, r0
	cmp r1, 0
	bge _08083490
	negs r1, r1
_08083490:
	cmp r1, 0x1
	bgt _080834A8
	movs r5, 0x2
	ldrsh r1, [r3, r5]
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	subs r1, r0
	cmp r1, 0
	bge _080834A4
	negs r1, r1
_080834A4:
	cmp r1, 0x1
	ble _0808355A
_080834A8:
	movs r5, 0
	ldrsh r4, [r3, r5]
	movs r1, 0
	ldrsh r0, [r6, r1]
	subs r2, r4, r0
	cmp r2, 0
	bge _080834B8
	negs r2, r2
_080834B8:
	movs r5, 0x2
	ldrsh r1, [r3, r5]
	movs r5, 0x2
	ldrsh r0, [r6, r5]
	subs r0, r1, r0
	cmp r0, 0
	bge _080834C8
	negs r0, r0
_080834C8:
	cmp r0, r2
	bge _080834CE
	adds r0, r2, 0
_080834CE:
	cmp r0, 0x2
	bne _0808355E
	adds r5, r4, 0
	adds r4, r1, 0
	movs r7, 0
_080834D8:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r5, r0
	bge _080834E2
	adds r5, 0x1
_080834E2:
	cmp r5, r0
	ble _080834E8
	subs r5, 0x1
_080834E8:
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	cmp r4, r0
	bge _080834F2
	adds r4, 0x1
_080834F2:
	cmp r4, r0
	ble _080834F8
	subs r4, 0x1
_080834F8:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp]
	bl sub_804954C
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r3, [sp]
	cmp r0, 0
	beq _0808355E
	adds r7, 0x1
	cmp r7, 0x1
	ble _080834D8
	movs r0, 0
	ldrsh r5, [r6, r0]
	movs r1, 0x2
	ldrsh r4, [r6, r1]
	movs r7, 0
_0808351E:
	movs r2, 0
	ldrsh r0, [r3, r2]
	cmp r5, r0
	bge _08083528
	adds r5, 0x1
_08083528:
	cmp r5, r0
	ble _0808352E
	subs r5, 0x1
_0808352E:
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r4, r0
	bge _08083538
	adds r4, 0x1
_08083538:
	cmp r4, r0
	ble _0808353E
	subs r4, 0x1
_0808353E:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp]
	bl sub_804954C
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r3, [sp]
	cmp r0, 0
	beq _0808355E
	adds r7, 0x1
	cmp r7, 0x1
	ble _0808351E
_0808355A:
	movs r0, 0x1
	b _08083560
_0808355E:
	movs r0, 0
_08083560:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8083478

	thumb_func_start sub_8083568
sub_8083568:
	push {r4,r5,lr}
	lsls r2, 24
	lsrs r5, r2, 24
	ldr r2, _080835E0
	ldr r2, [r2]
	ldr r4, _080835E4
	adds r3, r2, r4
	movs r4, 0
	ldrsh r3, [r3, r4]
	subs r3, r0, r3
	ldr r0, _080835E8
	adds r2, r0
	movs r4, 0
	ldrsh r0, [r2, r4]
	subs r4, r1, r0
	movs r0, 0x10
	negs r0, r0
	cmp r3, r0
	blt _080835F8
	cmp r4, r0
	blt _080835F8
	cmp r3, 0xFF
	bgt _080835F8
	cmp r4, 0xAF
	bgt _080835F8
	ldr r1, _080835EC
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	movs r1, 0x8
	ldrsh r2, [r0, r1]
	adds r2, r3, r2
	ldr r1, _080835F0
	ands r2, r1
	ldrh r3, [r0, 0x2]
	movs r1, 0xFE
	lsls r1, 8
	ands r1, r3
	orrs r1, r2
	strh r1, [r0, 0x2]
	movs r1, 0xA
	ldrsh r2, [r0, r1]
	adds r2, r4, r2
	ldr r1, _080835F4
	ands r2, r1
	lsls r2, 4
	ldrh r3, [r0, 0x6]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r2
	strh r1, [r0, 0x6]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
	movs r0, 0x1
	b _080835FA
	.align 2, 0
_080835E0: .4byte gDungeonGlobalData
_080835E4: .4byte 0x000181f0
_080835E8: .4byte 0x000181f2
_080835EC: .4byte gUnknown_202ED28
_080835F0: .4byte 0x000001ff
_080835F4: .4byte 0x00000fff
_080835F8:
	movs r0, 0
_080835FA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8083568

	thumb_func_start sub_8083600
sub_8083600:
	push {r4,r5,lr}
	ldr r0, _08083638
	ldr r0, [r0]
	cmp r0, 0
	bne _0808364A
	movs r5, 0
_0808360C:
	ldr r0, _0808363C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08083640
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0808362E
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _08083644
_0808362E:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0808360C
	movs r0, 0
	b _0808364A
	.align 2, 0
_08083638: .4byte gUnknown_203B450
_0808363C: .4byte gDungeonGlobalData
_08083640: .4byte 0x0001357c
_08083644:
	ldr r0, _08083650
	str r4, [r0]
	adds r0, r4, 0
_0808364A:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08083650: .4byte gUnknown_203B450
	thumb_func_end sub_8083600

	thumb_func_start sub_8083654
sub_8083654:
	push {lr}
	bl sub_8083600
	ldr r0, [r0, 0x70]
	pop {r1}
	bx r1
	thumb_func_end sub_8083654

	thumb_func_start sub_8083660
sub_8083660:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080836D4
	add sp, r4
	movs r1, 0xE0
	lsls r1, 5
	add r1, sp
	str r0, [r1]
	bl sub_8083600
	ldr r2, _080836D8
	add r2, sp
	str r0, [r2]
	movs r7, 0
	movs r0, 0
	ldr r1, _080836DC
	add r1, sp
	str r0, [r1]
_0808368A:
	movs r0, 0x38
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x20
	bl DungeonRandomCapped
	ldr r2, _080836E0
	add r2, sp
	str r0, [r2]
	ldr r0, _080836D8
	add r0, sp
	ldr r0, [r0]
	ldr r3, [r0, 0x4]
	adds r5, r4, 0
	movs r1, 0
	ldr r4, [r2]
	ldr r0, _080836E4
	cmp r7, r0
	ble _080836B4
	b _080837E6
_080836B4:
	movs r2, 0x3
	mov r10, r2
	lsls r0, r7, 2
	mov r2, sp
	adds r6, r0, r2
_080836BE:
	movs r0, 0
	mov r8, r0
	adds r2, r5, 0x1
	ldr r0, _080836E8
	add r0, sp
	str r2, [r0]
	adds r1, 0x1
	ldr r2, _080836EC
	add r2, sp
	str r1, [r2]
	b _0808379C
	.align 2, 0
_080836D4: .4byte 0xffffe3e4
_080836D8: .4byte 0x00001c04
_080836DC: .4byte 0x00001c0c
_080836E0: .4byte 0x00001c08
_080836E4: .4byte 0x000006ff
_080836E8: .4byte 0x00001c14
_080836EC: .4byte 0x00001c10
_080836F0:
	ldr r0, _08083738
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _0808373C
	ldrh r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	bne _08083782
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _08083782
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _08083782
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08083782
	lsls r0, r3, 16
	asrs r0, 16
	subs r0, r5
	cmp r0, 0
	bge _08083722
	negs r0, r0
_08083722:
	cmp r0, 0x5
	bgt _08083788
	asrs r0, r3, 16
	subs r0, r4
	cmp r0, 0
	bge _08083730
	negs r0, r0
_08083730:
	cmp r0, 0x5
	ble _08083782
	b _08083788
	.align 2, 0
_08083738: .4byte 0x00001c0c
_0808373C:
	ldr r1, _08083764
	add r1, sp
	ldr r1, [r1]
	cmp r1, 0x1
	bne _08083768
	ldrh r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	bne _08083782
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _08083782
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _08083782
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08083782
	b _08083788
	.align 2, 0
_08083764: .4byte 0x00001c0c
_08083768:
	ldrh r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	bne _08083782
	ldr r0, [r2, 0x14]
	cmp r0, 0
	bne _08083782
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _08083782
	movs r2, 0x1
	mov r9, r2
_08083782:
	mov r0, r9
	cmp r0, 0
	beq _08083790
_08083788:
	strb r5, [r6]
	strb r4, [r6, 0x1]
	adds r6, 0x4
	adds r7, 0x1
_08083790:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08083798
	movs r4, 0
_08083798:
	movs r1, 0x1
	add r8, r1
_0808379C:
	mov r2, r8
	cmp r2, 0x1F
	bgt _080837C2
	movs r0, 0
	mov r9, r0
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, _0808380C
	add r2, sp
	str r3, [r2]
	bl sub_804954C
	adds r2, r0, 0
	ldr r0, _08083810
	ldr r1, _0808380C
	add r1, sp
	ldr r3, [r1]
	cmp r7, r0
	ble _080836F0
_080837C2:
	ldr r2, _08083814
	add r2, sp
	ldr r5, [r2]
	cmp r5, 0x37
	ble _080837CE
	movs r5, 0
_080837CE:
	ldr r0, _08083818
	add r0, sp
	ldr r1, [r0]
	cmp r1, 0x37
	bgt _080837E6
	ldr r2, _0808381C
	add r2, sp
	ldr r4, [r2]
	ldr r0, _08083810
	cmp r7, r0
	bgt _080837E6
	b _080836BE
_080837E6:
	cmp r7, 0
	beq _08083820
	adds r0, r7, 0
	bl DungeonRandomCapped
	lsls r0, 2
	mov r2, sp
	adds r1, r2, r0
	ldrb r0, [r1]
	movs r2, 0xE0
	lsls r2, 5
	add r2, sp
	ldr r2, [r2]
	strh r0, [r2]
	ldrb r0, [r1, 0x1]
	strh r0, [r2, 0x2]
	movs r0, 0x1
	b _08083832
	.align 2, 0
_0808380C: .4byte 0x00001c18
_08083810: .4byte 0x000006ff
_08083814: .4byte 0x00001c14
_08083818: .4byte 0x00001c10
_0808381C: .4byte 0x00001c08
_08083820:
	ldr r0, _08083844
	add r0, sp
	ldr r2, [r0]
	adds r2, 0x1
	str r2, [r0]
	cmp r2, 0x2
	bgt _08083830
	b _0808368A
_08083830:
	movs r0, 0
_08083832:
	ldr r3, _08083848
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08083844: .4byte 0x00001c0c
_08083848: .4byte 0x00001c1c
	thumb_func_end sub_8083660

	thumb_func_start sub_808384C
sub_808384C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r3, r0, 0
	mov r9, r1
	movs r0, 0
	mov r8, r0
	ldr r0, _080838BC
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x63
	beq _080838D8
	movs r6, 0
_0808386A:
	adds r2, r6, r0
	movs r4, 0
	ldrsh r1, [r2, r4]
	mov r5, r9
	movs r7, 0
	ldrsh r0, [r5, r7]
	adds r5, r1, r0
	movs r0, 0x2
	ldrsh r1, [r2, r0]
	mov r2, r9
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp]
	bl sub_804954C
	adds r1, r0, 0
	ldrh r2, [r1]
	movs r7, 0x80
	lsls r7, 4
	adds r0, r7, 0
	ands r0, r2
	ldr r3, [sp]
	cmp r0, 0
	bne _080838C0
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0x1
	bne _080838C0
	ldr r0, [r1, 0x14]
	cmp r0, 0
	bne _080838C0
	ldr r0, [r1, 0x10]
	cmp r0, 0
	bne _080838C0
	strh r5, [r3]
	strh r4, [r3, 0x2]
	movs r0, 0x1
	b _080838DA
	.align 2, 0
_080838BC: .4byte gUnknown_80F4468
_080838C0:
	adds r6, 0x4
	movs r0, 0x1
	add r8, r0
	mov r2, r8
	cmp r2, 0x18
	bgt _080838D8
	ldr r0, _080838E8
	adds r1, r6, r0
	movs r4, 0
	ldrsh r1, [r1, r4]
	cmp r1, 0x63
	bne _0808386A
_080838D8:
	movs r0, 0
_080838DA:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080838E8: .4byte gUnknown_80F4468
	thumb_func_end sub_808384C

	thumb_func_start sub_80838EC
sub_80838EC:
	push {lr}
	adds r2, r0, 0
	ldrb r0, [r2]
	adds r1, r0, 0
	cmp r1, 0x7F
	beq _08083900
	cmp r1, 0
	beq _08083900
	subs r0, 0x1
	strb r0, [r2]
_08083900:
	pop {r0}
	bx r0
	thumb_func_end sub_80838EC

	thumb_func_start sub_8083904
sub_8083904:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp]
	mov r10, r1
	ldr r4, [r1, 0x70]
	str r4, [sp, 0x4]
	adds r5, r4, 0
	adds r5, 0x46
	ldrb r6, [r5]
	mov r0, r10
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08083954
	ldr r0, _08083950
	lsls r2, r6, 2
	adds r2, r0
	movs r0, 0
	ldrsh r1, [r2, r0]
	lsls r0, r1, 1
	adds r0, r1
	mov r1, r10
	ldrh r1, [r1, 0x4]
	adds r0, r1
	ldr r3, [sp]
	strh r0, [r3]
	movs r4, 0x2
	ldrsh r1, [r2, r4]
	lsls r0, r1, 1
	adds r0, r1
	b _08083A6E
	.align 2, 0
_08083950: .4byte gUnknown_80F4448
_08083954:
	ldr r1, [r4, 0x58]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08083960
	b _08083A8C
_08083960:
	ldrb r0, [r5]
	ldr r1, _080839A0
	lsls r0, 3
	adds r0, r1
	ldr r7, [r0]
	movs r3, 0x4
	ldrsh r2, [r0, r3]
	str r2, [sp, 0x8]
	movs r2, 0x6
	ldrsh r1, [r0, r2]
	str r1, [sp, 0xC]
	mov r3, r10
	movs r0, 0x4
	ldrsh r3, [r3, r0]
	str r3, [sp, 0x10]
	mov r1, r10
	movs r2, 0x6
	ldrsh r1, [r1, r2]
	str r1, [sp, 0x14]
	ldr r0, _080839A4
	ldr r1, [r0]
	ldr r3, _080839A8
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080839B0
	ldr r4, _080839AC
	adds r4, r1, r4
	str r4, [sp, 0x18]
	movs r0, 0x14
	b _080839D0
	.align 2, 0
_080839A0: .4byte gUnknown_80F4CC4
_080839A4: .4byte gDungeonGlobalData
_080839A8: .4byte 0x000037fc
_080839AC: .4byte 0x000135cc
_080839B0:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _080839C8
	ldr r2, _080839C4
	adds r2, r1, r2
	str r2, [sp, 0x18]
	movs r3, 0x10
	str r3, [sp, 0x1C]
	b _080839D2
	.align 2, 0
_080839C4: .4byte 0x0001358c
_080839C8:
	ldr r4, _08083A78
	adds r4, r1, r4
	str r4, [sp, 0x18]
	movs r0, 0x4
_080839D0:
	str r0, [sp, 0x1C]
_080839D2:
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, 0x63
	beq _08083A46
_080839DA:
	movs r2, 0
	ldrsh r0, [r7, r2]
	ldr r3, [sp, 0x8]
	muls r0, r3
	ldr r4, [sp, 0x10]
	adds r4, r0
	mov r9, r4
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	ldr r2, [sp, 0xC]
	muls r0, r2
	ldr r3, [sp, 0x14]
	adds r3, r0
	mov r8, r3
	movs r6, 0
	ldr r4, [sp, 0x1C]
	cmp r6, r4
	bge _08083A3C
	ldr r5, [sp, 0x18]
_08083A00:
	ldr r4, [r5]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08083A32
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, r9
	bne _08083A32
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r0, r8
	bne _08083A32
	mov r0, r10
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08083A80
_08083A32:
	adds r5, 0x4
	adds r6, 0x1
	ldr r3, [sp, 0x1C]
	cmp r6, r3
	blt _08083A00
_08083A3C:
	adds r7, 0x4
	movs r4, 0
	ldrsh r0, [r7, r4]
	cmp r0, 0x63
	bne _080839DA
_08083A46:
	ldr r2, _08083A7C
	ldr r1, [sp, 0x4]
	adds r1, 0x46
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 1
	mov r4, r10
	ldrh r4, [r4, 0x4]
	adds r0, r4
	ldr r3, [sp]
	strh r0, [r3]
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	lsls r0, 1
_08083A6E:
	mov r1, r10
	ldrh r1, [r1, 0x6]
	adds r0, r1
	strh r0, [r3, 0x2]
	b _08083A9E
	.align 2, 0
_08083A78: .4byte 0x0001357c
_08083A7C: .4byte gUnknown_80F4448
_08083A80:
	mov r3, r9
	ldr r2, [sp]
	strh r3, [r2]
	mov r4, r8
	strh r4, [r2, 0x2]
	b _08083A9E
_08083A8C:
	ldr r0, [sp, 0x4]
	adds r0, 0x58
	ldrh r0, [r0]
	ldr r1, [sp]
	strh r0, [r1]
	ldr r0, [sp, 0x4]
	adds r0, 0x5A
	ldrh r0, [r0]
	strh r0, [r1, 0x2]
_08083A9E:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8083904

	thumb_func_start sub_8083AB0
sub_8083AB0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r5, r1, 0
	adds r7, r2, 0
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	ldr r0, _08083AFC
	ldr r0, [r0]
	ldr r1, _08083B00
	adds r4, r0, r1
	movs r6, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08083AE4
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _08083AE4
	ldr r6, [r5, 0x70]
_08083AE4:
	ldr r5, [r7, 0x70]
	cmp r6, 0
	beq _08083B04
	mov r0, sp
	adds r1, r6, 0
	bl sub_80709C8
	adds r0, r4, 0
	mov r1, sp
	bl CopyStringtoBuffer
	b _08083B0E
	.align 2, 0
_08083AFC: .4byte gDungeonGlobalData
_08083B00: .4byte 0x0001ce98
_08083B04:
	ldr r0, _08083C04
	ldr r1, [r0]
	adds r0, r4, 0
	bl CopyStringtoBuffer
_08083B0E:
	mov r0, sp
	adds r1, r5, 0
	bl sub_80709C8
	adds r0, r4, 0
	adds r0, 0xA
	mov r1, sp
	bl CopyStringtoBuffer
	movs r2, 0
	mov r3, r8
	strh r3, [r4, 0x14]
	ldr r0, [r5, 0x60]
	str r0, [r4, 0x1C]
	ldr r0, [r5, 0x18]
	str r0, [r4, 0x20]
	ldrb r0, [r5, 0x9]
	adds r1, r4, 0
	adds r1, 0x2A
	strb r0, [r1]
	ldrh r0, [r5, 0x10]
	strh r0, [r4, 0x24]
	ldrb r0, [r5, 0x14]
	subs r1, 0x4
	strb r0, [r1]
	ldrb r0, [r5, 0x15]
	adds r1, 0x1
	strb r0, [r1]
	ldrb r1, [r5, 0x16]
	adds r0, r4, 0
	adds r0, 0x28
	strb r1, [r0]
	ldrb r0, [r5, 0x17]
	adds r1, r4, 0
	adds r1, 0x29
	strb r0, [r1]
	ldr r0, _08083C08
	ldr r0, [r0]
	ldr r1, _08083C0C
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x18]
	adds r3, r4, 0
	adds r3, 0x2B
	strb r2, [r3]
	adds r6, r4, 0
	adds r6, 0x2C
	strb r2, [r6]
	movs r0, 0x2D
	adds r0, r4
	mov r12, r0
	strb r2, [r0]
	adds r4, 0x2E
	strb r2, [r4]
	adds r0, r5, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08083BF8
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08083BF8
	adds r1, r5, 0
	adds r1, 0x62
	ldrb r0, [r1]
	cmp r0, 0x13
	bne _08083BA4
	ldr r0, _08083C10
	ldrb r0, [r0]
	ldrb r2, [r3]
	adds r0, r2
	strb r0, [r3]
_08083BA4:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08083BB4
	ldr r0, _08083C14
	ldrb r0, [r0]
	ldrb r2, [r3]
	adds r0, r2
	strb r0, [r3]
_08083BB4:
	ldrb r0, [r1]
	cmp r0, 0x21
	bne _08083BC4
	ldr r0, _08083C18
	ldrb r0, [r0]
	ldrb r3, [r6]
	adds r0, r3
	strb r0, [r6]
_08083BC4:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08083BD4
	ldr r0, _08083C14
	ldrb r0, [r0]
	ldrb r2, [r6]
	adds r0, r2
	strb r0, [r6]
_08083BD4:
	ldrb r0, [r1]
	cmp r0, 0x1E
	bne _08083BE8
	ldr r0, _08083C1C
	ldrb r0, [r0]
	mov r3, r12
	ldrb r3, [r3]
	adds r0, r3
	mov r2, r12
	strb r0, [r2]
_08083BE8:
	ldrb r0, [r1]
	cmp r0, 0x22
	bne _08083BF8
	ldr r0, _08083C20
	ldrb r0, [r0]
	ldrb r3, [r4]
	adds r0, r3
	strb r0, [r4]
_08083BF8:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08083C04: .4byte gUnknown_80FE6F4
_08083C08: .4byte gDungeonGlobalData
_08083C0C: .4byte 0x00000644
_08083C10: .4byte gUnknown_810AC60
_08083C14: .4byte gUnknown_810AC68
_08083C18: .4byte gUnknown_810AC62
_08083C1C: .4byte gUnknown_810AC64
_08083C20: .4byte gUnknown_810AC66
	thumb_func_end sub_8083AB0

	thumb_func_start sub_8083C24
sub_8083C24:
	push {lr}
	ldr r0, _08083C3C
	ldr r0, [r0]
	ldr r1, _08083C40
	adds r0, r1
	movs r2, 0x14
	ldrsh r1, [r0, r2]
	ldr r0, _08083C44
	cmp r1, r0
	ble _08083C48
	movs r0, 0
	b _08083C4A
	.align 2, 0
_08083C3C: .4byte gDungeonGlobalData
_08083C40: .4byte 0x0001ce98
_08083C44: .4byte 0x00000225
_08083C48:
	movs r0, 0x1
_08083C4A:
	pop {r1}
	bx r1
	thumb_func_end sub_8083C24

	thumb_func_start sub_8083C50
sub_8083C50:
	push {lr}
	ldr r0, _08083C74
	ldr r0, [r0]
	ldr r1, _08083C78
	adds r0, r1
	movs r2, 0x14
	ldrsh r1, [r0, r2]
	ldr r0, _08083C7C
	cmp r1, r0
	beq _08083C70
	adds r0, 0x3
	cmp r1, r0
	beq _08083C70
	subs r0, 0x2
	cmp r1, r0
	bne _08083C80
_08083C70:
	movs r0, 0x1
	b _08083C82
	.align 2, 0
_08083C74: .4byte gDungeonGlobalData
_08083C78: .4byte 0x0001ce98
_08083C7C: .4byte 0x00000227
_08083C80:
	movs r0, 0
_08083C82:
	pop {r1}
	bx r1
	thumb_func_end sub_8083C50

	thumb_func_start sub_8083C88
sub_8083C88:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, _08083CC4
	ldr r0, [r4]
	ldr r1, _08083CC8
	adds r5, r0, r1
	ldr r1, _08083CCC
	adds r0, r1
	ldrb r0, [r0]
	bl GetUnk9
	lsls r0, 24
	cmp r0, 0
	bne _08083CB6
	ldr r0, [r4]
	ldr r1, _08083CD0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08083CC0
	cmp r6, 0
	bne _08083CC0
_08083CB6:
	movs r0, 0x14
	ldrsh r1, [r5, r0]
	ldr r0, _08083CD4
	cmp r1, r0
	beq _08083CD8
_08083CC0:
	movs r0, 0x1
	b _08083CDA
	.align 2, 0
_08083CC4: .4byte gDungeonGlobalData
_08083CC8: .4byte 0x0001ce98
_08083CCC: .4byte 0x00000644
_08083CD0: .4byte 0x0000065c
_08083CD4: .4byte 0x00000227
_08083CD8:
	movs r0, 0
_08083CDA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8083C88

	thumb_func_start sub_8083CE0
sub_8083CE0:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _08083CF2
	ldr r0, _08083D00
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	ble _08083CFC
_08083CF2:
	ldr r0, _08083D04
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
_08083CFC:
	pop {r0}
	bx r0
	.align 2, 0
_08083D00: .4byte gUnknown_202EE10
_08083D04: .4byte 0x0000012d
	thumb_func_end sub_8083CE0

	thumb_func_start sub_8083D08
sub_8083D08:
	push {lr}
	movs r0, 0x97
	lsls r0, 1
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D08

	thumb_func_start sub_8083D1C
sub_8083D1C:
	push {lr}
	ldr r0, _08083D2C
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	.align 2, 0
_08083D2C: .4byte 0x00000133
	thumb_func_end sub_8083D1C

	thumb_func_start sub_8083D30
sub_8083D30:
	push {lr}
	ldr r0, _08083D40
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	.align 2, 0
_08083D40: .4byte 0x0000012f
	thumb_func_end sub_8083D30

	thumb_func_start sub_8083D44
sub_8083D44:
	push {lr}
	movs r0, 0x98
	lsls r0, 1
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D44

	thumb_func_start sub_8083D58
sub_8083D58:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xC8
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D58

	thumb_func_start sub_8083D68
sub_8083D68:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCF
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D68

	thumb_func_start sub_8083D78
sub_8083D78:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xD3
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D78

	thumb_func_start sub_8083D88
sub_8083D88:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCC
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083D88

	thumb_func_start sub_8083D98
sub_8083D98:
	push {lr}
	movs r0, 0x33
	bl sub_8083E88
	ldr r2, _08083DCC
	ldr r0, [r2]
	ldr r1, _08083DD0
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _08083DD4
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x27
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08083DD8
	adds r0, r1
	ldr r1, _08083DDC
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08083DCC: .4byte gDungeonGlobalData
_08083DD0: .4byte 0x0000066f
_08083DD4: .4byte 0x00000672
_08083DD8: .4byte 0x0000066a
_08083DDC: .4byte 0x000003e7
	thumb_func_end sub_8083D98

	thumb_func_start sub_8083DE0
sub_8083DE0:
	push {lr}
	movs r0, 0x34
	bl sub_8083E88
	ldr r2, _08083E14
	ldr r0, [r2]
	ldr r1, _08083E18
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _08083E1C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, 0x27
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08083E20
	adds r0, r1
	ldr r1, _08083E24
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08083E14: .4byte gDungeonGlobalData
_08083E18: .4byte 0x0000066f
_08083E1C: .4byte 0x00000672
_08083E20: .4byte 0x0000066a
_08083E24: .4byte 0x000003e7
	thumb_func_end sub_8083DE0

	thumb_func_start sub_8083E28
sub_8083E28:
	push {lr}
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCF
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8083E28

	thumb_func_start PlaySoundEffect
PlaySoundEffect:
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, _08083E54
	cmp r2, r0
	beq _08083E4E
	movs r1, 0x80
	lsls r1, 1
	adds r0, r2, 0
	bl sub_800C074
_08083E4E:
	pop {r0}
	bx r0
	.align 2, 0
_08083E54: .4byte 0x000003e5
	thumb_func_end PlaySoundEffect

	thumb_func_start sub_8083E58
sub_8083E58:
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _08083E70
	cmp r1, r0
	beq _08083E6A
	adds r0, r1, 0
	bl sub_800C298
_08083E6A:
	pop {r0}
	bx r0
	.align 2, 0
_08083E70: .4byte 0x000003e5
	thumb_func_end sub_8083E58

	thumb_func_start sub_8083E74
sub_8083E74:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C5D0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_8083E74

	thumb_func_start sub_8083E88
sub_8083E88:
	ldr r1, _08083E9C
	ldr r1, [r1]
	ldr r3, _08083EA0
	adds r2, r1, r3
	movs r3, 0
	strh r0, [r2]
	ldr r0, _08083EA4
	adds r1, r0
	strh r3, [r1]
	bx lr
	.align 2, 0
_08083E9C: .4byte gDungeonGlobalData
_08083EA0: .4byte 0x0001ceda
_08083EA4: .4byte 0x0001ced4
	thumb_func_end sub_8083E88

	thumb_func_start sub_8083EA8
sub_8083EA8:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _08083ECC
	ldr r2, [r2]
	movs r4, 0x80
	lsls r4, 8
	adds r3, r4, 0
	ldr r5, _08083ED0
	adds r4, r2, r5
	orrs r0, r3
	strh r0, [r4]
	ldr r0, _08083ED4
	adds r2, r0
	strh r1, [r2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083ECC: .4byte gDungeonGlobalData
_08083ED0: .4byte 0x0001ceda
_08083ED4: .4byte 0x0001ced4
	thumb_func_end sub_8083EA8

	thumb_func_start sub_8083ED8
sub_8083ED8:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_80118C4
	ldr r0, _08083F00
	ldr r1, [r0]
	ldr r2, _08083F04
	adds r0, r1, r2
	ldr r2, _08083F08
	strh r2, [r0]
	ldr r3, _08083F0C
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _08083F10
	adds r1, r0
	strh r2, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08083F00: .4byte gDungeonGlobalData
_08083F04: .4byte 0x0001ced6
_08083F08: .4byte 0x000003e7
_08083F0C: .4byte 0x0001ced8
_08083F10: .4byte 0x0001ceda
	thumb_func_end sub_8083ED8

	thumb_func_start sub_8083F14
sub_8083F14:
	push {lr}
	bl sub_8083F34
	bl sub_8011924
	pop {r0}
	bx r0
	thumb_func_end sub_8083F14

	thumb_func_start xxx_call_GetCurrentBGSong
xxx_call_GetCurrentBGSong:
	push {lr}
	bl GetCurrentBGSong
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end xxx_call_GetCurrentBGSong

	thumb_func_start sub_8083F34
sub_8083F34:
	ldr r0, _08083F4C
	ldr r0, [r0]
	ldr r1, _08083F50
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	str r1, [r0, 0x4]
	ldr r1, _08083F54
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	bx lr
	.align 2, 0
_08083F4C: .4byte gDungeonGlobalData
_08083F50: .4byte 0x0001cecc
_08083F54: .4byte 0x000003e7
	thumb_func_end sub_8083F34

	thumb_func_start sub_8083F58
sub_8083F58:
	push {r4,lr}
	ldr r0, _08083F7C
	ldr r2, [r0]
	ldr r0, _08083F80
	adds r4, r2, r0
	ldr r1, _08083F84
	adds r3, r2, r1
	ldrh r1, [r3]
	ldr r0, _08083F88
	cmp r1, r0
	bne _08083FB2
	ldr r1, _08083F8C
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08083F90
	movs r1, 0x12
	b _08083FB2
	.align 2, 0
_08083F7C: .4byte gDungeonGlobalData
_08083F80: .4byte 0x0001cecc
_08083F84: .4byte 0x0000066a
_08083F88: .4byte 0x000003e7
_08083F8C: .4byte 0x0000066f
_08083F90:
	ldr r1, _08083FA0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08083FA4
	movs r1, 0x80
	b _08083FB2
	.align 2, 0
_08083FA0: .4byte 0x00000672
_08083FA4:
	ldr r1, _08083FC4
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r1, 0x11
	cmp r0, 0
	bne _08083FB2
	ldrh r1, [r4, 0xE]
_08083FB2:
	ldr r0, [r4]
	cmp r0, 0x4
	bne _08083FC8
	ldrh r0, [r4, 0xC]
	cmp r1, r0
	beq _08083FDA
	movs r0, 0x2
	b _08083FD6
	.align 2, 0
_08083FC4: .4byte 0x00000699
_08083FC8:
	ldr r2, _08083FEC
	cmp r1, r2
	beq _08083FDA
	ldrh r0, [r4, 0xA]
	cmp r0, r2
	bne _08083FDA
	movs r0, 0x1
_08083FD6:
	str r0, [r4]
	strh r1, [r4, 0xA]
_08083FDA:
	ldr r0, [r4]
	cmp r0, 0x4
	bhi _08084084
	lsls r0, 2
	ldr r1, _08083FF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083FEC: .4byte 0x000003e7
_08083FF0: .4byte _08083FF4
	.align 2, 0
_08083FF4:
	.4byte _08084084
	.4byte _08084008
	.4byte _08084050
	.4byte _0808405E
	.4byte _08084084
_08084008:
	ldrh r1, [r4, 0xA]
	ldr r0, _08084014
	cmp r1, r0
	bne _08084018
	movs r0, 0
	b _08084040
	.align 2, 0
_08084014: .4byte 0x000003e7
_08084018:
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08084030
	ldr r0, _0808402C
	ands r0, r1
	bl StartNewBGM
	b _0808403A
	.align 2, 0
_0808402C: .4byte 0x00007fff
_08084030:
	ldr r0, _08084048
	ands r0, r1
	ldrh r1, [r4, 0x8]
	bl FadeInNewBGM
_0808403A:
	ldrh r0, [r4, 0xA]
	strh r0, [r4, 0xC]
	movs r0, 0x4
_08084040:
	str r0, [r4]
	ldr r0, _0808404C
	strh r0, [r4, 0xA]
	b _08084084
	.align 2, 0
_08084048: .4byte 0x00007fff
_0808404C: .4byte 0x000003e7
_08084050:
	movs r0, 0x1E
	bl FadeOutBGM
	movs r0, 0x1E
	str r0, [r4, 0x4]
	movs r0, 0x3
	b _08084082
_0808405E:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0808406C
	subs r0, 0x1
	str r0, [r4, 0x4]
	cmp r0, 0
	bne _08084084
_0808406C:
	ldrh r1, [r4, 0xA]
	ldr r0, _0808407C
	cmp r1, r0
	bne _08084080
	bl sub_800BF80
	movs r0, 0
	b _08084082
	.align 2, 0
_0808407C: .4byte 0x000003e7
_08084080:
	movs r0, 0x1
_08084082:
	str r0, [r4]
_08084084:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8083F58

	thumb_func_start sub_808408C
sub_808408C:
	ldr r2, _0808409C
	movs r1, 0x1
	orrs r1, r0
	ldr r0, _080840A0
	ands r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0808409C: .4byte gUnknown_203B458
_080840A0: .4byte 0x00ffffff
	thumb_func_end sub_808408C

	thumb_func_start sub_80840A4
sub_80840A4:
	ldr r3, _080840C8
	ldr r0, [r3]
	ldr r2, _080840CC
	adds r1, r0, 0
	muls r1, r2
	adds r1, 0x1
	lsrs r0, r1, 16
	muls r1, r2
	adds r1, 0x1
	str r1, [r3]
	ldr r2, _080840D0
	ands r1, r2
	orrs r0, r1
	ldr r1, _080840D4
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	bx lr
	.align 2, 0
_080840C8: .4byte gUnknown_203B458
_080840CC: .4byte 0x5d588b65
_080840D0: .4byte 0xffff0000
_080840D4: .4byte 0x00ffffff
	thumb_func_end sub_80840A4

	thumb_func_start sub_80840D8
sub_80840D8:
	ldr r2, _080840E4
	movs r1, 0x1
	orrs r1, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_080840E4: .4byte gUnknown_203B454
	thumb_func_end sub_80840D8

	thumb_func_start sub_80840E8
sub_80840E8:
	ldr r2, _080840F8
	ldr r1, [r2]
	ldr r0, _080840FC
	muls r0, r1
	adds r0, 0x1
	str r0, [r2]
	lsrs r0, 16
	bx lr
	.align 2, 0
_080840F8: .4byte gUnknown_203B454
_080840FC: .4byte 0x5d588b65
	thumb_func_end sub_80840E8

	thumb_func_start DungeonRandomCapped
DungeonRandomCapped:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80840E8
	ldr r1, _08084118
	ands r0, r1
	muls r0, r4
	asrs r0, 16
	ands r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08084118: .4byte 0x0000ffff
	thumb_func_end DungeonRandomCapped

	thumb_func_start sub_808411C
sub_808411C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r5, r4
	beq _0808413C
	cmp r5, r4
	blt _08084134
	subs r0, r5, r4
	bl DungeonRandomCapped
	adds r0, r4
	b _0808413C
_08084134:
	subs r0, r4, r5
	bl DungeonRandomCapped
	adds r0, r5
_0808413C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_808411C

	thumb_func_start sub_8084144
sub_8084144:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, r4
	blt _08084156
	movs r0, 0
	b _08084158
_08084156:
	movs r0, 0x1
_08084158:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8084144

	thumb_func_start sub_8084160
sub_8084160:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, r4
	blt _08084172
	movs r0, 0
	b _08084174
_08084172:
	movs r0, 0x1
_08084174:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8084160

	thumb_func_start sub_808417C
sub_808417C:
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r2, 24
	lsrs r6, r2, 24
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_808411C
	adds r4, r0, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080841DC
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _080841DC
	cmp r6, 0
	beq _080841DC
	adds r0, r5, 0
	movs r1, 0x12
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080841C4
	cmp r4, 0x7F
	beq _080841C4
	lsrs r0, r4, 31
	adds r0, r4, r0
	asrs r4, r0, 1
_080841C4:
	adds r0, r5, 0
	movs r1, 0x14
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _080841DC
	cmp r4, 0x7F
	beq _080841DC
	cmp r4, 0x4
	ble _080841DC
	movs r4, 0x5
_080841DC:
	cmp r4, 0
	bgt _080841E2
	movs r4, 0x1
_080841E2:
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808417C

	thumb_func_start sub_80841EC
sub_80841EC:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC4
	add r0, sp, 0x60
	mov r8, r0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x64]
	add r1, sp, 0x68
	movs r6, 0
	movs r0, 0x4
	strh r0, [r1]
	movs r2, 0x3
	strh r2, [r1, 0x2]
	add r1, sp, 0x6C
	movs r0, 0x16
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6E
	movs r5, 0xE
	movs r1, 0xE
	strh r1, [r0]
	add r0, sp, 0x70
	strh r1, [r0]
	add r4, sp, 0xC0
	str r4, [sp, 0x74]
	str r2, [sp, 0x7C]
	add r0, sp, 0x90
	str r2, [r0, 0x4]
	add r0, sp, 0xA8
	str r2, [r0, 0x4]
	mov r0, sp
	mov r1, r8
	movs r2, 0x60
	bl memcpy
	movs r0, 0x1
	strb r0, [r4]
	strb r6, [r4, 0x1]
	strb r5, [r4, 0x2]
	strb r6, [r4, 0x3]
	mov r1, sp
	movs r0, 0x14
	strh r0, [r1, 0xA]
	mov r0, sp
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, _0808426C
	ldr r0, [r0]
	ldr r1, _08084270
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r0, _08084274
	cmp r1, r0
	ble _08084278
	bl sub_8083DE0
	b _0808427C
	.align 2, 0
_0808426C: .4byte gDungeonGlobalData
_08084270: .4byte 0x0001ceac
_08084274: .4byte 0x00000225
_08084278:
	bl sub_8083D98
_0808427C:
	ldr r0, _080842B8
	ldr r1, [r0]
	ldr r0, _080842BC
	ldr r2, [r0]
	ldr r0, _080842C0
	adds r2, r0
	movs r0, 0
	bl sub_8094558
	mov r4, sp
_08084290:
	movs r0, 0x36
	bl sub_803E668
	bl sub_8083F58
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0x3
	ble _080842C4
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0xA0
	strb r0, [r4]
	mov r0, sp
	movs r1, 0x1
	bl sub_803ECB4
	b _08084290
	.align 2, 0
_080842B8: .4byte gUnknown_80FE6E8
_080842BC: .4byte gDungeonGlobalData
_080842C0: .4byte 0x0001ce98
_080842C4:
	bl sub_8094D14
	lsls r0, 24
	cmp r0, 0
	bne _080842DA
	ldr r0, _080842EC
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08084290
_080842DA:
	bl sub_8083D08
	add sp, 0xC4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080842EC: .4byte gRealInputs
	thumb_func_end sub_80841EC

	thumb_func_start sub_80842F0
sub_80842F0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, _0808436C
	ldr r0, [r1]
	ldr r2, _08084370
	adds r0, r2
	movs r2, 0
	strb r2, [r0]
	ldr r0, [r1]
	ldr r3, _08084374
	adds r0, r3
	strb r2, [r0]
	ldr r0, [r1]
	movs r5, 0xCF
	lsls r5, 3
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080843AE
	movs r6, 0
	ldr r0, _08084378
	mov r8, r0
	movs r7, 0x1
_08084320:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x6
	bne _080843A8
	ldr r3, _0808436C
	ldr r5, [r3]
	ldr r1, _0808437C
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r4, 0x4]
	mov r1, r8
	ands r1, r0
	mov r0, r8
	ands r0, r2
	cmp r1, r0
	bne _080843A8
	ldrb r0, [r4, 0x1]
	cmp r0, 0x3
	beq _080843A8
	cmp r0, 0x4
	bne _08084380
	ldrb r1, [r4, 0x10]
	ldr r2, _08084374
	adds r0, r5, r2
	strb r1, [r0]
	ldr r2, [r3]
	ldrh r1, [r4, 0xE]
	movs r3, 0xD1
	lsls r3, 3
	adds r0, r2, r3
	strh r1, [r0]
	strb r7, [r2, 0x9]
	b _080843A8
	.align 2, 0
_0808436C: .4byte gDungeonGlobalData
_08084370: .4byte 0x00000677
_08084374: .4byte 0x0000068a
_08084378: .4byte 0x0000ffff
_0808437C: .4byte 0x00000644
_08084380:
	cmp r0, 0
	beq _0808438C
	cmp r0, 0x2
	beq _0808438C
	cmp r0, 0x1
	bne _080843A8
_0808438C:
	ldr r2, [r3]
	ldrh r0, [r4, 0xE]
	movs r5, 0xD1
	lsls r5, 3
	adds r1, r2, r5
	strh r0, [r1]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _080843A4
	ldr r1, _080843B8
	adds r0, r2, r1
	strb r7, [r0]
_080843A4:
	ldr r0, [r3]
	strb r7, [r0, 0x9]
_080843A8:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08084320
_080843AE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080843B8: .4byte 0x00000677
	thumb_func_end sub_80842F0

	thumb_func_start sub_80843BC
sub_80843BC:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r6, r0, 16
	movs r4, 0
	ldr r5, _08084418
_080843C6:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r3, r0, 0
	ldrb r0, [r3]
	cmp r0, 0x6
	bne _0808440C
	ldr r0, _0808441C
	ldr r0, [r0]
	ldr r1, _08084420
	adds r0, r1
	ldrh r0, [r0]
	ldrh r2, [r3, 0x4]
	adds r1, r5, 0
	ands r1, r0
	adds r0, r5, 0
	ands r0, r2
	cmp r1, r0
	bne _0808440C
	ldrb r0, [r3, 0x1]
	cmp r0, 0
	beq _08084400
	cmp r0, 0x4
	beq _08084400
	cmp r0, 0x2
	beq _08084400
	cmp r0, 0x1
	bne _0808440C
_08084400:
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	cmp r6, r0
	bne _0808440C
	movs r0, 0x8
	strb r0, [r3]
_0808440C:
	adds r4, 0x1
	cmp r4, 0x7
	ble _080843C6
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08084418: .4byte 0x0000ffff
_0808441C: .4byte gDungeonGlobalData
_08084420: .4byte 0x00000644
	thumb_func_end sub_80843BC

	thumb_func_start sub_8084424
sub_8084424:
	push {r4,lr}
	movs r4, 0
_08084428:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x8
	bne _0808443C
	movs r0, 0x9
	strb r0, [r1]
_0808443C:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08084428
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8084424

	thumb_func_start sub_8084448
sub_8084448:
	push {r4-r7,lr}
	adds r5, r0, 0
	ldr r7, [r5, 0x70]
	ldr r4, _0808447C
	bl sub_8083600
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _08084484
	ldr r0, _08084480
	b _080844F0
	.align 2, 0
_0808447C: .4byte gAvailablePokemonNames
_08084480: .4byte gUnknown_80FA464
_08084484:
	ldr r4, _080844FC
	ldr r0, [r4]
	ldr r6, _08084500
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08084540
	ldr r0, _08084504
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	beq _080844A4
	b _080845D4
_080844A4:
	ldr r0, _08084508
	ldr r1, [r4]
	adds r1, r6
	ldrb r1, [r1]
	movs r2, 0
	bl sub_8090DC4
	movs r3, 0
	ldr r0, _0808450C
	adds r6, r0, 0
	ldr r2, [r6]
_080844BA:
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080844E2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080844E2
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0x18
	beq _080844E2
	ldr r0, [r4]
	ldr r1, _08084500
	adds r0, r1
	ldrb r1, [r2, 0x2]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080844EA
_080844E2:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _080844BA
_080844EA:
	cmp r3, 0x14
	bne _08084514
	ldr r0, _08084510
_080844F0:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _080845D4
	.align 2, 0
_080844FC: .4byte gDungeonGlobalData
_08084500: .4byte 0x0000068a
_08084504: .4byte gUnknown_80FA32C
_08084508: .4byte gUnknown_202DE58
_0808450C: .4byte gTeamInventory_203B460
_08084510: .4byte gUnknown_80FA448
_08084514:
	lsls r1, r3, 2
	ldr r0, [r6]
	adds r1, r0
	movs r0, 0
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x1]
	strb r0, [r1]
	bl FillInventoryGaps
	ldr r0, _08084538
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	ldr r0, _0808453C
	b _0808455E
	.align 2, 0
_08084538: .4byte gUnknown_80FA2B0
_0808453C: .4byte gUnknown_80FA370
_08084540:
	ldr r0, _080845B0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _080845D4
	ldr r0, _080845B4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	ldr r0, _080845B8
_0808455E:
	ldr r4, [r0]
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl sub_80843BC
	adds r0, r5, 0x4
	bl sub_8042A34
	movs r1, 0x87
	lsls r1, 2
	adds r0, r5, 0
	movs r2, 0
	bl sub_8068FE0
	movs r0, 0x1
	bl sub_804178C
	ldr r5, _080845BC
_08084582:
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _080845C4
	ldr r0, _080845C0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	adds r1, r0, 0
	cmp r1, 0x1
	bne _08084582
	ldr r0, [r5]
	strb r1, [r0, 0x4]
	ldr r1, [r5]
	movs r0, 0x2
	strb r0, [r1, 0x11]
	b _080845D4
	.align 2, 0
_080845B0: .4byte gUnknown_80FA2F0
_080845B4: .4byte gUnknown_80FA260
_080845B8: .4byte gUnknown_80FA36C
_080845BC: .4byte gDungeonGlobalData
_080845C0: .4byte gUnknown_80FA394
_080845C4:
	ldr r0, _080845DC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08084582
_080845D4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080845DC: .4byte gUnknown_80FA3B8
	thumb_func_end sub_8084448

	thumb_func_start sub_80845E0
sub_80845E0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	movs r7, 0
	movs r1, 0
	mov r9, r1
	ldr r4, _08084620
	bl sub_8083600
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _08084630
	ldr r0, _08084624
	b _080846B4
	.align 2, 0
_08084620: .4byte gAvailablePokemonNames
_08084624: .4byte gUnknown_80FA530
_08084628:
	adds r7, r4, 0
	ldr r2, [r7, 0x70]
	mov r9, r2
	b _08084674
_08084630:
	movs r5, 0
_08084632:
	ldr r0, _08084660
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08084664
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0808466E
	ldr r0, [r4, 0x70]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0808465A
	cmp r0, 0x47
	bne _08084668
_0808465A:
	movs r0, 0x1
	b _0808466A
	.align 2, 0
_08084660: .4byte gDungeonGlobalData
_08084664: .4byte 0x0001357c
_08084668:
	movs r0, 0
_0808466A:
	cmp r0, 0
	bne _08084628
_0808466E:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08084632
_08084674:
	cmp r7, 0
	bne _08084680
	ldr r0, _0808467C
	b _080846B4
	.align 2, 0
_0808467C: .4byte gUnknown_80FA52C
_08084680:
	ldr r0, _0808469C
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r7, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _080846A4
	ldr r0, _080846A0
	b _080846B4
	.align 2, 0
_0808469C: .4byte gUnknown_202E038
_080846A0: .4byte gUnknown_80FA54C
_080846A4:
	adds r0, r6, 0
	adds r1, r7, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	bne _080846C4
	ldr r0, _080846C0
_080846B4:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08084768
	.align 2, 0
_080846C0: .4byte gUnknown_80FA500
_080846C4:
	ldr r0, _08084744
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	mov r1, r8
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80843BC
	ldr r5, _08084748
	ldr r0, [r5]
	ldr r1, _0808474C
	adds r0, r1
	ldrb r1, [r0]
	mov r0, r9
	adds r0, 0x40
	strb r1, [r0]
	adds r0, r6, 0x4
	bl sub_8042A34
	adds r0, r7, 0x4
	bl sub_8042A34
	movs r4, 0x87
	lsls r4, 2
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8068FE0
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8068FE0
	movs r0, 0x1
	bl sub_804178C
	ldr r4, _08084750
_08084716:
	movs r0, 0
	ldr r1, [r4]
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08084758
	ldr r0, _08084754
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	adds r1, r0, 0
	cmp r1, 0x1
	bne _08084716
	ldr r0, [r5]
	strb r1, [r0, 0x4]
	ldr r1, [r5]
	movs r0, 0x2
	strb r0, [r1, 0x11]
	b _08084768
	.align 2, 0
_08084744: .4byte gUnknown_80FA4D4
_08084748: .4byte gDungeonGlobalData
_0808474C: .4byte 0x00000644
_08084750: .4byte gUnknown_80FA4D8
_08084754: .4byte gUnknown_80FA394
_08084758:
	ldr r0, _08084774
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08084716
_08084768:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084774: .4byte gUnknown_80FA3B8
	thumb_func_end sub_80845E0

	thumb_func_start sub_8084778
sub_8084778:
	push {r4,lr}
	ldr r0, _080847B8
	ldr r1, _080847BC
	bl strcpy
	movs r4, 0
_08084784:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8096AB4
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _080847C8
	ldr r0, _080847C0
	ldr r0, [r0]
	ldr r2, _080847C4
	adds r0, r2
	ldrb r0, [r0]
	ldrb r2, [r1, 0x4]
	cmp r0, r2
	bne _080847C8
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	bne _080847C8
	movs r0, 0xE
	ldrsh r1, [r1, r0]
	ldr r0, _080847B8
	bl CopyCyanSpeciesNametoBuffer
	b _080847CE
	.align 2, 0
_080847B8: .4byte gUnknown_202E088
_080847BC: .4byte gUnknown_8107224
_080847C0: .4byte gDungeonGlobalData
_080847C4: .4byte 0x00000644
_080847C8:
	adds r4, 0x1
	cmp r4, 0x7
	ble _08084784
_080847CE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8084778

	thumb_func_start sub_80847D4
sub_80847D4:
	push {r4,r5,lr}
	ldr r2, _08084820
	ldr r0, [r2]
	ldr r1, _08084824
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _08084828
	adds r0, r2
	strb r1, [r0]
	bl sub_8040A84
	movs r4, 0
	ldr r0, _0808482C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08084846
	movs r3, 0
_080847FA:
	ldr r0, _08084820
	ldr r0, [r0]
	ldr r5, _08084830
	adds r0, r5
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r1, 0
	subs r0, 0x1C
	cmp r0, 0x15
	bhi _08084810
	movs r1, 0x1B
_08084810:
	ldr r2, _0808482C
	adds r0, r3, r2
	ldrb r5, [r0]
	cmp r1, r5
	bne _08084834
	bl sub_8084854
	b _08084846
	.align 2, 0
_08084820: .4byte gDungeonGlobalData
_08084824: .4byte 0x00003a0d
_08084828: .4byte 0x0001356c
_0808482C: .4byte gUnknown_8107234
_08084830: .4byte 0x00003a14
_08084834:
	adds r3, 0x8
	adds r4, 0x1
	ldr r0, _08084850
	cmp r4, r0
	bgt _08084846
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080847FA
_08084846:
	bl sub_8097FF8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084850: .4byte 0x000003e6
	thumb_func_end sub_80847D4

	thumb_func_start sub_8084854
sub_8084854:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08084874
	ldr r2, [r5]
	movs r1, 0xCF
	lsls r1, 3
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0808487C
	ldrb r1, [r4, 0x5]
	ldr r3, _08084878
	adds r0, r2, r3
	strb r1, [r0]
	b _080848C8
	.align 2, 0
_08084874: .4byte gDungeonGlobalData
_08084878: .4byte 0x00003a0d
_0808487C:
	ldrb r0, [r4, 0x4]
	bl sub_8098100
	lsls r0, 24
	cmp r0, 0
	beq _08084898
	ldr r0, [r5]
	ldrb r1, [r4, 0x5]
	ldr r2, _08084894
	adds r0, r2
	strb r1, [r0]
	b _080848C8
	.align 2, 0
_08084894: .4byte 0x00003a0d
_08084898:
	ldrb r0, [r4, 0x2]
	bl sub_8098100
	lsls r0, 24
	cmp r0, 0
	beq _080848B4
	ldr r0, [r5]
	ldrb r1, [r4, 0x3]
	ldr r3, _080848B0
	adds r0, r3
	strb r1, [r0]
	b _080848C8
	.align 2, 0
_080848B0: .4byte 0x00003a0d
_080848B4:
	ldr r0, [r5]
	ldrb r1, [r4, 0x1]
	ldr r2, _080848E0
	adds r0, r2
	strb r1, [r0]
	ldrb r0, [r4, 0x2]
	cmp r0, 0x40
	beq _080848C8
	bl sub_8097FA8
_080848C8:
	ldr r0, _080848E4
	ldr r0, [r0]
	ldr r3, _080848E8
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0
	bl sub_807E5E4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080848E0: .4byte 0x00003a0d
_080848E4: .4byte gDungeonGlobalData
_080848E8: .4byte 0x00000675
	thumb_func_end sub_8084854

	thumb_func_start sub_80848EC
sub_80848EC:
	movs r0, 0x1
	bx lr
	thumb_func_end sub_80848EC

	thumb_func_start sub_80848F0
sub_80848F0:
	push {lr}
	ldr r2, _08084918
	ldr r0, [r2]
	ldr r1, _0808491C
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08084920
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3C
	bls _0808490C
	b _08084B5C
_0808490C:
	lsls r0, 2
	ldr r1, _08084924
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08084918: .4byte gDungeonGlobalData
_0808491C: .4byte 0x0001356c
_08084920: .4byte 0x00003a0d
_08084924: .4byte _08084928
	.align 2, 0
_08084928:
	.4byte _08084A1C
	.4byte _08084A2C
	.4byte _08084A2C
	.4byte _08084A32
	.4byte _08084A38
	.4byte _08084A38
	.4byte _08084A3E
	.4byte _08084A44
	.4byte _08084A44
	.4byte _08084A4A
	.4byte _08084A50
	.4byte _08084A50
	.4byte _08084A56
	.4byte _08084A5C
	.4byte _08084A62
	.4byte _08084A68
	.4byte _08084A6E
	.4byte _08084A74
	.4byte _08084A7A
	.4byte _08084A80
	.4byte _08084A86
	.4byte _08084A8C
	.4byte _08084A92
	.4byte _08084A98
	.4byte _08084A98
	.4byte _08084A9E
	.4byte _08084AA4
	.4byte _08084AA4
	.4byte _08084AAA
	.4byte _08084AB0
	.4byte _08084AB0
	.4byte _08084AB6
	.4byte _08084ABC
	.4byte _08084ABC
	.4byte _08084AC2
	.4byte _08084AC8
	.4byte _08084ACE
	.4byte _08084AD4
	.4byte _08084ADA
	.4byte _08084AE0
	.4byte _08084AE6
	.4byte _08084AEC
	.4byte _08084AF2
	.4byte _08084AF8
	.4byte _08084AFE
	.4byte _08084B04
	.4byte _08084B0A
	.4byte _08084B10
	.4byte _08084B16
	.4byte _08084B1C
	.4byte _08084B22
	.4byte _08084B28
	.4byte _08084B2E
	.4byte _08084B34
	.4byte _08084B3A
	.4byte _08084B40
	.4byte _08084B46
	.4byte _08084B4C
	.4byte _08084B52
	.4byte _08084B58
	.4byte _08084A1C
_08084A1C:
	ldr r0, [r2]
	ldr r1, _08084A28
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	b _08084B5C
	.align 2, 0
_08084A28: .4byte 0x0001356c
_08084A2C:
	bl sub_8086B14
	b _08084B5C
_08084A32:
	bl sub_8086B94
	b _08084B5C
_08084A38:
	bl sub_8086E9C
	b _08084B5C
_08084A3E:
	bl sub_8086F00
	b _08084B5C
_08084A44:
	bl sub_8087230
	b _08084B5C
_08084A4A:
	bl sub_808729C
	b _08084B5C
_08084A50:
	bl sub_80877E8
	b _08084B5C
_08084A56:
	bl sub_8087848
	b _08084B5C
_08084A5C:
	bl sub_8087F54
	b _08084B5C
_08084A62:
	bl sub_8087FB4
	b _08084B5C
_08084A68:
	bl sub_8087FF8
	b _08084B5C
_08084A6E:
	bl sub_80885A0
	b _08084B5C
_08084A74:
	bl sub_80885C4
	b _08084B5C
_08084A7A:
	bl sub_808862C
	b _08084B5C
_08084A80:
	bl sub_80886C4
	b _08084B5C
_08084A86:
	bl sub_808875C
	b _08084B5C
_08084A8C:
	bl sub_8088DC0
	b _08084B5C
_08084A92:
	bl sub_8088E5C
	b _08084B5C
_08084A98:
	bl sub_80892C8
	b _08084B5C
_08084A9E:
	bl sub_8089328
	b _08084B5C
_08084AA4:
	bl sub_808970C
	b _08084B5C
_08084AAA:
	bl sub_808974C
	b _08084B5C
_08084AB0:
	bl sub_8089914
	b _08084B5C
_08084AB6:
	bl sub_8089978
	b _08084B5C
_08084ABC:
	bl sub_8089C44
	b _08084B5C
_08084AC2:
	bl sub_8089C90
	b _08084B5C
_08084AC8:
	bl sub_8089EFC
	b _08084B5C
_08084ACE:
	bl sub_8089F44
	b _08084B5C
_08084AD4:
	bl sub_8089F8C
	b _08084B5C
_08084ADA:
	bl sub_808A264
	b _08084B5C
_08084AE0:
	bl sub_808A2C0
	b _08084B5C
_08084AE6:
	bl sub_808A308
	b _08084B5C
_08084AEC:
	bl sub_808A608
	b _08084B5C
_08084AF2:
	bl sub_808A668
	b _08084B5C
_08084AF8:
	bl sub_808A9E4
	b _08084B5C
_08084AFE:
	bl sub_808AA3C
	b _08084B5C
_08084B04:
	bl sub_808AA94
	b _08084B5C
_08084B0A:
	bl sub_808ACC0
	b _08084B5C
_08084B10:
	bl sub_808AD48
	b _08084B5C
_08084B16:
	bl sub_808ADCC
	b _08084B5C
_08084B1C:
	bl sub_808B2F4
	b _08084B5C
_08084B22:
	bl sub_808B35C
	b _08084B5C
_08084B28:
	bl sub_808BDEC
	b _08084B5C
_08084B2E:
	bl sub_808C10C
	b _08084B5C
_08084B34:
	bl sub_808C3A0
	b _08084B5C
_08084B3A:
	bl sub_808C5C0
	b _08084B5C
_08084B40:
	bl sub_808C938
	b _08084B5C
_08084B46:
	bl sub_808C9C4
	b _08084B5C
_08084B4C:
	bl sub_808CB5C
	b _08084B5C
_08084B52:
	bl sub_808CBB0
	b _08084B5C
_08084B58:
	bl sub_808CD44
_08084B5C:
	bl sub_8097FF8
	pop {r0}
	bx r0
	thumb_func_end sub_80848F0

	.align 2,0
