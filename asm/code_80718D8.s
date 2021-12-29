	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start SetVisualFlags
SetVisualFlags:
	push {r4,r5,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r5, r2, 24
	movs r1, 0xA7
	lsls r1, 1
	adds r0, r3, r1
	ldrh r0, [r0]
	ands r0, r4
	cmp r0, 0
	beq _08071AF6
	movs r0, 0xA8
	lsls r0, 1
	adds r2, r3, r0
	ldrh r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
	b _08071B02
_08071AF6:
	movs r0, 0xA8
	lsls r0, 1
	adds r1, r3, r0
	ldrh r0, [r1]
	bics r0, r4
	strh r0, [r1]
_08071B02:
	cmp r5, 0
	beq _08071B16
	movs r1, 0xA7
	lsls r1, 1
	adds r2, r3, r1
	ldrh r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
	b _08071B22
_08071B16:
	movs r0, 0xA7
	lsls r0, 1
	adds r1, r3, r0
	ldrh r0, [r1]
	bics r0, r4
	strh r0, [r1]
_08071B22:
	movs r1, 0xA8
	lsls r1, 1
	adds r0, r3, r1
	ldrh r0, [r0]
	ands r0, r4
	cmp r0, 0
	bne _08071B40
	subs r1, 0x2
	adds r0, r3, r1
	ldrh r0, [r0]
	ands r0, r4
	cmp r0, 0
	beq _08071B40
	movs r0, 0x1
	b _08071B42
_08071B40:
	movs r0, 0
_08071B42:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end SetVisualFlags

	thumb_func_start sub_8071B48
sub_8071B48:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	movs r0, 0
	mov r8, r0
	ldr r0, _08071B94
	ldr r6, [r0]
	ldr r1, _08071B98
	adds r0, r6, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _08071B66
	b _08071D3E
_08071B66:
	subs r1, 0x20
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0x15
	bne _08071B7C
	ldr r2, _08071B9C
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08071B7C
	b _08071D3E
_08071B7C:
	ldr r0, _08071BA0
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r2, r0, 0x1
	strh r2, [r1]
	ldr r1, _08071BA4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08071BAC
	ldr r0, _08071BA8
	b _08071BAE
	.align 2, 0
_08071B94: .4byte gDungeonGlobalData
_08071B98: .4byte 0x00000664
_08071B9C: .4byte 0x000037fd
_08071BA0: .4byte 0x00000662
_08071BA4: .4byte 0x0000066e
_08071BA8: .4byte gUnknown_80F4DAA
_08071BAC:
	ldr r0, _08071C60
_08071BAE:
	lsls r1, r2, 16
	asrs r1, 16
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08071BBC
	b _08071D3E
_08071BBC:
	ldr r1, _08071C64
	adds r0, r6, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0xE1
	lsls r0, 2
	cmp r1, r0
	ble _08071BF6
	ldr r1, _08071C68
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08071BF6
	ldrh r0, [r4, 0x26]
	ldr r2, _08071C6C
	adds r1, r6, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _08071BF6
	ldr r0, _08071C70
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	mov r8, r4
_08071BF6:
	ldr r1, _08071C64
	adds r0, r6, r1
	movs r1, 0
	strh r1, [r0]
	ldr r2, _08071C68
	adds r0, r6, r2
	str r1, [r0]
	movs r7, 0
	movs r5, 0
_08071C08:
	lsls r0, r5, 2
	ldr r2, _08071C74
	adds r1, r6, r2
	adds r1, r0
	ldr r4, [r1]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08071C3A
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl GetMapTileAtPosition
	ldrh r0, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08071C3A
	adds r7, 0x1
_08071C3A:
	adds r5, 0x1
	cmp r5, 0xF
	ble _08071C08
	ldr r1, _08071C78
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08071C92
	ldr r0, _08071C7C
	ldr r0, [r0]
	ldr r2, _08071C80
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08071C88
	ldr r0, _08071C84
	movs r1, 0
	ldrsh r0, [r0, r1]
	b _08071C8E
	.align 2, 0
_08071C60: .4byte gUnknown_80F4DAC
_08071C64: .4byte 0x00000662
_08071C68: .4byte 0x00017b34
_08071C6C: .4byte 0x00017b40
_08071C70: .4byte gAvailablePokemonNames
_08071C74: .4byte 0x0001358c
_08071C78: .4byte 0x0000066e
_08071C7C: .4byte gDungeonGlobalData
_08071C80: .4byte 0x00003a0c
_08071C84: .4byte gUnknown_80F4DA6
_08071C88:
	ldr r0, _08071CB8
	movs r2, 0
	ldrsh r0, [r0, r2]
_08071C8E:
	cmp r7, r0
	bge _08071D3E
_08071C92:
	mov r0, r8
	cmp r0, 0
	beq _08071CA8
	ldr r0, _08071CBC
	ldr r1, [r0]
	movs r0, 0
	bl sub_805239C
	mov r0, r8
	bl sub_8042920
_08071CA8:
	ldr r1, _08071CC0
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08071CC4
	movs r5, 0xBE
	lsls r5, 1
	b _08071CCE
	.align 2, 0
_08071CB8: .4byte gUnknown_80F4DA8
_08071CBC: .4byte gUnknown_80FED68
_08071CC0: .4byte 0x0000066e
_08071CC4:
	movs r0, 0
	bl sub_803D970
	lsls r0, 16
	asrs r5, r0, 16
_08071CCE:
	adds r0, r5, 0
	bl sub_803DA20
	adds r4, r0, 0
	cmp r4, 0
	bne _08071CDC
	movs r4, 0x1
_08071CDC:
	adds r0, r5, 0
	movs r1, 0
	bl sub_806AA0C
	lsls r0, 24
	cmp r0, 0
	beq _08071D3E
	add r0, sp, 0xC
	bl sub_8083660
	lsls r0, 24
	cmp r0, 0
	beq _08071D3E
	mov r0, sp
	movs r1, 0
	strh r5, [r0]
	strh r4, [r0, 0x8]
	strb r1, [r0, 0x2]
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r4, r0, 0
	ldr r0, _08071D24
	ldr r0, [r0]
	ldr r2, _08071D28
	adds r0, r2
	ldrb r0, [r0]
	bl sub_8090168
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	bge _08071D2C
	movs r0, 0x1
	b _08071D2E
	.align 2, 0
_08071D24: .4byte gDungeonGlobalData
_08071D28: .4byte 0x00000644
_08071D2C:
	movs r0, 0
_08071D2E:
	str r0, [sp, 0x4]
	mov r1, sp
	movs r0, 0
	strb r0, [r1, 0x10]
	mov r0, sp
	movs r1, 0
	bl sub_806B7F8
_08071D3E:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8071B48

	thumb_func_start sub_8071D4C
sub_8071D4C:
	push {lr}
	ldr r3, [r1, 0x70]
	ldrb r0, [r3, 0x9]
	cmp r0, 0x64
	beq _08071D94
	adds r0, r3, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08071D64
	cmp r0, 0x47
	bne _08071D68
_08071D64:
	movs r0, 0x1
	b _08071D6A
_08071D68:
	movs r0, 0
_08071D6A:
	cmp r0, 0
	bne _08071D94
	ldr r1, [r3, 0x18]
	adds r2, r1, r2
	ldr r0, _08071D98
	cmp r2, r0
	ble _08071D7A
	ldr r2, _08071D9C
_08071D7A:
	subs r2, r1
	cmp r2, 0
	beq _08071D94
	movs r0, 0xFE
	lsls r0, 1
	adds r1, r3, r0
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
	ldr r0, _08071DA0
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xD]
_08071D94:
	pop {r0}
	bx r0
	.align 2, 0
_08071D98: .4byte 0x0098967e
_08071D9C: .4byte 0x0098967f
_08071DA0: .4byte gDungeonGlobalData
	thumb_func_end sub_8071D4C

	thumb_func_start sub_8071DA4
sub_8071DA4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xD4
	str r0, [sp, 0xB4]
	ldr r2, _08071E44
	ldr r1, [r2]
	ldrb r0, [r1, 0xD]
	cmp r0, 0
	bne _08071DBE
	b _08071FE2
_08071DBE:
	movs r0, 0
	strb r0, [r1, 0xD]
	ldr r0, [r2]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	beq _08071DCC
	b _08071FE2
_08071DCC:
	ldr r0, [sp, 0xB4]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08071DE2
	mov r0, sp
	bl sub_80457DC
	mov r0, sp
	str r0, [sp, 0xB4]
_08071DE2:
	movs r4, 0
_08071DE4:
	movs r5, 0
	ldr r0, _08071E44
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _08071E48
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r0, 0
	str r0, [sp, 0xB8]
	movs r1, 0
	movs r2, 0
	str r1, [sp, 0xBC]
	str r2, [sp, 0xC0]
	movs r0, 0
	movs r1, 0
	str r0, [sp, 0xC4]
	str r1, [sp, 0xC8]
	adds r1, r4, 0x1
	str r1, [sp, 0xCC]
	mov r2, r8
	cmp r2, 0
	bne _08071E16
	b _08071FDA
_08071E16:
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08071E24
	b _08071FDA
_08071E24:
	mov r0, r8
	ldr r6, [r0, 0x70]
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _08071E32
	b _08071FDA
_08071E32:
	adds r1, r6, 0
	adds r1, 0xF9
	ldrb r0, [r1]
	cmp r0, 0
	beq _08071E4C
	add r2, sp, 0xB8
	ldrb r2, [r2]
	strb r2, [r1]
	b _08071FCA
	.align 2, 0
_08071E44: .4byte gDungeonGlobalData
_08071E48: .4byte 0x000135cc
_08071E4C:
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r10, r0
	cmp r0, 0
	beq _08071EB6
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _08071E68
	ldrb r1, [r6, 0x9]
	add r0, sp, 0x74
	bl GetAvailTacticsforLvl_Bool
_08071E68:
	movs r0, 0x10
	ldrsh r2, [r6, r0]
	str r2, [sp, 0xB8]
	ldrb r1, [r6, 0x14]
	str r1, [sp, 0xBC]
	ldrb r2, [r6, 0x15]
	str r2, [sp, 0xC0]
	ldrb r0, [r6, 0x16]
	str r0, [sp, 0xC4]
	ldrb r1, [r6, 0x17]
	str r1, [sp, 0xC8]
	ldrb r0, [r6, 0x9]
	cmp r0, 0x64
	beq _08071EB6
	ldr r0, [r6, 0x18]
	add r0, r10
	str r0, [r6, 0x18]
	mov r2, r10
	ldr r0, _08071EE8
	str r2, [r0]
	ldr r0, _08071EEC
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _08071EF0
	ldr r2, [r0]
	ldr r0, [sp, 0xB4]
	mov r1, r8
	bl sub_80522F4
	ldr r0, [sp, 0xB4]
	mov r1, r8
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80723D0
	lsls r0, 24
	lsrs r5, r0, 24
_08071EB6:
	ldr r1, _08071EF4
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r4, 0x1
	str r4, [sp, 0xCC]
	cmp r0, 0
	beq _08071F3A
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	add r1, sp, 0x8C
	movs r2, 0
	movs r3, 0
	bl sub_808E400
	adds r7, r0, 0
	add r0, sp, 0x8C
	mov r9, r0
	cmp r7, 0
	beq _08071F38
	adds r0, r7, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r1, 0
	b _08071F02
	.align 2, 0
_08071EE8: .4byte gUnknown_202DE30
_08071EEC: .4byte gAvailablePokemonNames
_08071EF0: .4byte gUnknown_80F9E64
_08071EF4: .4byte 0x00000149
_08071EF8:
	adds r4, 0x1
	cmp r4, r7
	blt _08071F00
	movs r4, 0
_08071F00:
	adds r1, 0x1
_08071F02:
	cmp r1, r7
	bge _08071F38
	lsls r0, r4, 1
	mov r2, r9
	adds r5, r2, r0
	movs r2, 0
	ldrsh r0, [r5, r2]
	str r1, [sp, 0xD0]
	bl sub_803D930
	lsls r0, 24
	ldr r1, [sp, 0xD0]
	cmp r0, 0
	beq _08071EF8
	movs r2, 0
	ldrsh r0, [r5, r2]
	bl sub_80687D0
	ldr r1, [sp, 0xD0]
	cmp r0, 0
	beq _08071EF8
	movs r0, 0
	ldrsh r2, [r5, r0]
	ldr r0, [sp, 0xB4]
	mov r1, r8
	bl sub_8072B78
_08071F38:
	movs r5, 0
_08071F3A:
	cmp r5, 0
	beq _08071F7A
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _08071F7A
	movs r1, 0x10
	ldrsh r0, [r6, r1]
	ldr r2, [sp, 0xB8]
	subs r0, r2
	ldr r1, _08071FF4
	str r0, [r1]
	ldrb r0, [r6, 0x14]
	ldr r2, [sp, 0xBC]
	subs r0, r2
	str r0, [r1, 0x4]
	ldrb r0, [r6, 0x16]
	ldr r1, [sp, 0xC4]
	subs r0, r1
	ldr r2, _08071FF4
	str r0, [r2, 0x8]
	ldrb r0, [r6, 0x15]
	ldr r1, [sp, 0xC0]
	subs r0, r1
	str r0, [r2, 0xC]
	ldrb r0, [r6, 0x17]
	ldr r2, [sp, 0xC8]
	subs r0, r2
	ldr r1, _08071FF4
	str r0, [r1, 0x10]
	mov r0, r8
	bl sub_807218C
_08071F7A:
	mov r2, r10
	cmp r2, 0
	beq _08071FCA
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _08071FCA
	ldrb r1, [r6, 0x9]
	add r0, sp, 0x80
	bl GetAvailTacticsforLvl_Bool
	movs r4, 0
	add r7, sp, 0x74
	add r5, sp, 0x80
_08071F94:
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08071FC4
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08071FC4
	ldr r0, _08071FF8
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	lsls r1, r4, 24
	lsrs r1, 24
	ldr r0, _08071FFC
	bl CopyTacticsNameToBuffer
	ldr r0, _08072000
	ldr r2, [r0]
	ldr r0, [sp, 0xB4]
	mov r1, r8
	bl sub_80522F4
_08071FC4:
	adds r4, 0x1
	cmp r4, 0xB
	ble _08071F94
_08071FCA:
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r6, r1
	movs r1, 0
	str r1, [r0]
	ldr r2, _08072004
	adds r0, r6, r2
	strb r1, [r0]
_08071FDA:
	ldr r4, [sp, 0xCC]
	cmp r4, 0x13
	bgt _08071FE2
	b _08071DE4
_08071FE2:
	add sp, 0xD4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08071FF4: .4byte gUnknown_202DE30
_08071FF8: .4byte gAvailablePokemonNames
_08071FFC: .4byte gUnknown_202DE58
_08072000: .4byte gUnknown_80FF730
_08072004: .4byte 0x00000149
	thumb_func_end sub_8071DA4

	thumb_func_start sub_8072008
sub_8072008:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	mov r9, r0
	mov r8, r1
	adds r4, r2, 0
	ldr r0, [sp, 0x58]
	lsls r3, 24
	lsrs r3, 24
	mov r10, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x24]
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08072036
	b _08072162
_08072036:
	movs r0, 0
	str r0, [sp, 0x28]
	mov r1, r8
	ldr r5, [r1, 0x70]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0807204C
	add r0, sp, 0xC
	ldrb r1, [r5, 0x9]
	bl GetAvailTacticsforLvl_Bool
_0807204C:
	movs r0, 0x10
	ldrsh r2, [r5, r0]
	str r2, [sp, 0x2C]
	ldrb r6, [r5, 0x14]
	ldrb r7, [r5, 0x15]
	ldrb r1, [r5, 0x16]
	str r1, [sp, 0x30]
	ldrb r2, [r5, 0x17]
	str r2, [sp, 0x34]
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0807206C
	cmp r0, 0x47
	bne _08072070
_0807206C:
	movs r0, 0x1
	b _08072072
_08072070:
	movs r0, 0
_08072072:
	cmp r0, 0
	bne _080720E6
	ldrb r0, [r5, 0x9]
	adds r2, r0, r4
	cmp r2, 0x63
	ble _08072080
	movs r2, 0x64
_08072080:
	cmp r2, r0
	beq _080720E6
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	mov r0, sp
	bl GetPokemonLevelData
	ldr r0, [sp]
	str r0, [r5, 0x18]
	mov r0, r9
	mov r1, r8
	mov r2, r10
	ldr r3, [sp, 0x24]
	bl sub_80723D0
	ldr r1, [sp, 0x28]
	orrs r1, r0
	lsls r0, r1, 24
	lsrs r0, 24
	str r0, [sp, 0x28]
	cmp r0, 0
	beq _080720E6
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _080720E6
	ldr r1, _08072174
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	ldr r2, [sp, 0x2C]
	subs r0, r2
	str r0, [r1]
	ldrb r0, [r5, 0x14]
	subs r0, r6
	str r0, [r1, 0x4]
	ldrb r0, [r5, 0x16]
	ldr r2, [sp, 0x30]
	subs r0, r2
	str r0, [r1, 0x8]
	ldrb r0, [r5, 0x15]
	subs r0, r7
	str r0, [r1, 0xC]
	ldrb r0, [r5, 0x17]
	ldr r2, [sp, 0x34]
	subs r0, r2
	str r0, [r1, 0x10]
	mov r0, r10
	cmp r0, 0
	beq _080720E6
	mov r0, r8
	bl sub_807218C
_080720E6:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08072130
	add r4, sp, 0x18
	ldrb r1, [r5, 0x9]
	adds r0, r4, 0
	bl GetAvailTacticsforLvl_Bool
	movs r6, 0
	add r7, sp, 0xC
_080720FA:
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807212A
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807212A
	ldr r0, _08072178
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	lsls r1, r6, 24
	lsrs r1, 24
	ldr r0, _0807217C
	bl CopyTacticsNameToBuffer
	ldr r0, _08072180
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
_0807212A:
	adds r6, 0x1
	cmp r6, 0xB
	ble _080720FA
_08072130:
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r5, r1
	movs r1, 0
	str r1, [r0]
	ldr r2, _08072184
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, [sp, 0x28]
	cmp r0, 0
	bne _08072162
	mov r1, r10
	cmp r1, 0
	beq _08072162
	ldr r0, _08072178
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08072188
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
_08072162:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08072174: .4byte gUnknown_202DE30
_08072178: .4byte gAvailablePokemonNames
_0807217C: .4byte gUnknown_202DE58
_08072180: .4byte gUnknown_80FF730
_08072184: .4byte 0x00000149
_08072188: .4byte gUnknown_80F9B74
	thumb_func_end sub_8072008

	thumb_func_start sub_807218C
sub_807218C:
	push {r4-r6,lr}
	sub sp, 0x190
	adds r4, r0, 0
	movs r6, 0
	ldr r5, [r4, 0x70]
	movs r1, 0
	bl sub_806A2BC
	ldr r0, _080721C8
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	adds r0, r4, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	beq _08072200
	movs r3, 0
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	bne _080721CC
	movs r1, 0xD2
	lsls r1, 1
	b _080721EC
	.align 2, 0
_080721C8: .4byte gAvailablePokemonNames
_080721CC:
	cmp r0, 0x47
	bne _080721D8
	ldr r1, _080721D4
	b _080721EC
	.align 2, 0
_080721D4: .4byte 0x000001a5
_080721D8:
	cmp r0, 0x41
	bne _080721EC
	ldr r0, _080721F8
	ldr r0, [r0]
	ldr r2, _080721FC
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080721EC
	movs r3, 0x1
_080721EC:
	mov r0, sp
	movs r2, 0x3
	bl sub_806A3D4
	b _0807220A
	.align 2, 0
_080721F8: .4byte gDungeonGlobalData
_080721FC: .4byte 0x0000065c
_08072200:
	ldr r0, _08072308
	ldr r1, [r0]
	mov r0, sp
	bl strcpy
_0807220A:
	movs r0, 0
	mov r1, sp
	movs r2, 0x1
	bl PrintFieldMessage
	mov r0, sp
	movs r1, 0
	strb r1, [r0]
	ldr r4, _0807230C
	ldr r0, [r4]
	cmp r0, 0
	ble _0807222E
	ldr r0, _08072310
	ldr r1, [r0]
	mov r0, sp
	bl strcat
	adds r6, 0x1
_0807222E:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	ble _0807225A
	ldr r0, _08072314
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807224E
	ldr r0, _08072318
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	mov r0, sp
	bl strcat
_0807224E:
	ldr r0, _0807231C
	ldr r1, [r0]
	mov r0, sp
	bl strcat
	adds r6, 0x1
_0807225A:
	ldr r0, _0807230C
	ldr r0, [r0, 0x8]
	cmp r0, 0
	ble _08072288
	ldr r0, _08072314
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807227C
	ldr r0, _08072318
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	mov r0, sp
	bl strcat
_0807227C:
	ldr r0, _08072320
	ldr r1, [r0]
	mov r0, sp
	bl strcat
	adds r6, 0x1
_08072288:
	ldr r0, _0807230C
	ldr r0, [r0, 0xC]
	cmp r0, 0
	ble _080722B6
	ldr r0, _08072314
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080722AA
	ldr r0, _08072318
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	mov r0, sp
	bl strcat
_080722AA:
	ldr r0, _08072324
	ldr r1, [r0]
	mov r0, sp
	bl strcat
	adds r6, 0x1
_080722B6:
	ldr r0, _0807230C
	ldr r0, [r0, 0x10]
	cmp r0, 0
	ble _080722E2
	ldr r0, _08072314
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080722D8
	ldr r0, _08072318
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	mov r0, sp
	bl strcat
_080722D8:
	ldr r0, _08072328
	ldr r1, [r0]
	mov r0, sp
	bl strcat
_080722E2:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _080722F4
	movs r0, 0
	mov r1, sp
	movs r2, 0x1
	bl PrintFieldMessage
_080722F4:
	bl GetLeaderEntity
	movs r1, 0
	bl sub_806A2BC
	add sp, 0x190
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08072308: .4byte gUnknown_80FCF18
_0807230C: .4byte gUnknown_202DE30
_08072310: .4byte gUnknown_80F9ACC
_08072314: .4byte gUnknown_8107010
_08072318: .4byte gUnknown_8107018
_0807231C: .4byte gUnknown_80F9AEC
_08072320: .4byte gUnknown_80F9B10
_08072324: .4byte gUnknown_80F9B34
_08072328: .4byte gUnknown_80F9B58
	thumb_func_end sub_807218C

	thumb_func_start LevelDownTarget
LevelDownTarget:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	mov r8, r0
	adds r5, r1, 0
	adds r7, r2, 0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080723B6
	movs r6, 0
	ldr r4, [r5, 0x70]
	adds r0, r4, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08072358
	cmp r0, 0x47
	bne _0807235C
_08072358:
	movs r0, 0x1
	b _0807235E
_0807235C:
	movs r0, 0
_0807235E:
	cmp r0, 0
	bne _0807238C
	ldrb r0, [r4, 0x9]
	subs r2, r0, r7
	cmp r2, 0
	bgt _0807236C
	movs r2, 0x1
_0807236C:
	cmp r2, r0
	beq _0807238C
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	mov r0, sp
	bl GetPokemonLevelData
	ldr r0, [sp]
	str r0, [r4, 0x18]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80725A4
	orrs r6, r0
	lsls r0, r6, 24
	lsrs r6, r0, 24
_0807238C:
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0
	str r1, [r0]
	ldr r2, _080723C4
	adds r0, r4, r2
	strb r1, [r0]
	cmp r6, 0
	bne _080723B6
	ldr r0, _080723C8
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080723CC
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
_080723B6:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080723C4: .4byte 0x00000149
_080723C8: .4byte gAvailablePokemonNames
_080723CC: .4byte gUnknown_80F9B94
	thumb_func_end LevelDownTarget

	thumb_func_start sub_80723D0
sub_80723D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r0, [sp, 0xC]
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x10]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x14]
	movs r0, 0
	str r0, [sp, 0x18]
	mov r0, r10
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08072422
	mov r1, r10
	ldr r5, [r1, 0x70]
	movs r0, 0x2
	ldrsh r3, [r5, r0]
	str r3, [sp, 0x1C]
	ldr r1, [r5, 0x18]
	str r1, [sp, 0x20]
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08072418
	cmp r0, 0x47
	bne _0807241C
_08072418:
	movs r0, 0x1
	b _0807241E
_0807241C:
	movs r0, 0
_0807241E:
	cmp r0, 0
	beq _08072426
_08072422:
	movs r0, 0
	b _08072576
_08072426:
	ldrb r0, [r5, 0x9]
	adds r0, 0x1
	mov r8, r0
	mov r9, sp
	b _0807255A
_08072430:
	mov r3, r8
	strb r3, [r5, 0x9]
	ldr r0, [sp, 0x20]
	str r0, [r5, 0x18]
	ldr r1, [sp, 0x10]
	cmp r1, 0
	beq _080724A4
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _08072480
	mov r0, r10
	movs r1, 0
	bl sub_806A2BC
	ldr r3, [sp, 0x18]
	cmp r3, 0
	bne _08072456
	bl sub_8083D58
_08072456:
	ldr r0, _08072474
	mov r1, r8
	str r1, [r0]
	ldr r0, _08072478
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _0807247C
	ldr r1, [r0]
	mov r0, r10
	bl sub_80528F4
	b _080724A4
	.align 2, 0
_08072474: .4byte gUnknown_202DE30
_08072478: .4byte gAvailablePokemonNames
_0807247C: .4byte gUnknown_80F9E80
_08072480:
	ldr r3, [sp, 0x18]
	cmp r3, 0
	bne _0807248A
	bl sub_8083D58
_0807248A:
	ldr r0, _08072588
	mov r1, r8
	str r1, [r0]
	ldr r0, _0807258C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _08072590
	ldr r1, [r0]
	mov r0, r10
	bl sub_805239C
_080724A4:
	movs r3, 0x1
	str r3, [sp, 0x18]
	mov r1, r9
	ldrh r0, [r1, 0x4]
	ldrh r3, [r5, 0x10]
	adds r0, r3
	movs r2, 0
	strh r0, [r5, 0x10]
	ldrh r1, [r1, 0x4]
	ldrh r3, [r5, 0xE]
	adds r1, r3
	strh r1, [r5, 0xE]
	lsls r0, 16
	ldr r1, _08072594
	cmp r0, r1
	ble _080724C8
	ldr r0, _08072598
	strh r0, [r5, 0x10]
_080724C8:
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	ldrh r2, [r5, 0x10]
	movs r3, 0x10
	ldrsh r0, [r5, r3]
	cmp r1, r0
	blt _080724D8
	strh r2, [r5, 0xE]
_080724D8:
	ldr r7, _0807259C
	ldrb r4, [r5, 0x14]
	str r4, [r7]
	ldrb r1, [r5, 0x15]
	str r1, [r7, 0x4]
	ldr r6, _080725A0
	ldrb r2, [r5, 0x16]
	str r2, [r6]
	ldrb r0, [r5, 0x17]
	mov r12, r0
	mov r3, r9
	ldrb r0, [r3, 0x6]
	adds r4, r0
	str r4, [r7]
	ldrb r0, [r3, 0x7]
	adds r1, r0
	str r1, [r7, 0x4]
	ldrb r0, [r3, 0x8]
	adds r2, r0
	str r2, [r6]
	ldrb r0, [r3, 0x9]
	mov r1, r12
	adds r3, r1, r0
	str r3, [r6, 0x4]
	cmp r4, 0xFE
	ble _08072510
	movs r3, 0xFF
	str r3, [r7]
_08072510:
	ldr r0, [r7, 0x4]
	cmp r0, 0xFE
	ble _0807251A
	movs r0, 0xFF
	str r0, [r7, 0x4]
_0807251A:
	ldr r0, [r6]
	cmp r0, 0xFE
	ble _08072524
	movs r1, 0xFF
	str r1, [r6]
_08072524:
	ldr r0, [r6, 0x4]
	cmp r0, 0xFE
	ble _0807252E
	movs r3, 0xFF
	str r3, [r6, 0x4]
_0807252E:
	mov r0, r10
	bl LoadIQSkills
	mov r0, r10
	bl sub_8079764
	ldr r0, [r7]
	strb r0, [r5, 0x14]
	ldr r0, [r7, 0x4]
	strb r0, [r5, 0x15]
	ldr r0, [r6]
	strb r0, [r5, 0x16]
	ldr r0, [r6, 0x4]
	strb r0, [r5, 0x17]
	ldr r0, [sp, 0xC]
	mov r1, r10
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	bl sub_8072778
	movs r0, 0x1
	add r8, r0
_0807255A:
	mov r1, r8
	cmp r1, 0x64
	bgt _08072574
	mov r0, sp
	ldr r1, [sp, 0x1C]
	mov r2, r8
	bl GetPokemonLevelData
	ldr r0, [sp]
	ldr r3, [sp, 0x20]
	cmp r0, r3
	bgt _08072574
	b _08072430
_08072574:
	ldr r0, [sp, 0x18]
_08072576:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08072588: .4byte gUnknown_202DE30
_0807258C: .4byte gAvailablePokemonNames
_08072590: .4byte gUnknown_80F9E80
_08072594: .4byte 0x03e60000
_08072598: .4byte 0x000003e7
_0807259C: .4byte gUnknown_202F31C
_080725A0: .4byte gUnknown_202F324
	thumb_func_end sub_80723D0

	thumb_func_start sub_80725A4
sub_80725A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	adds r0, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080725C2
	b _0807272E
_080725C2:
	ldr r0, [sp, 0x10]
	ldr r5, [r0, 0x70]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	str r1, [sp, 0x18]
	ldr r3, [r5, 0x18]
	str r3, [sp, 0x1C]
	ldrb r0, [r5, 0x9]
	str r0, [sp, 0x20]
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _080725E2
	cmp r0, 0x47
	bne _080725E6
_080725E2:
	movs r0, 0x1
	b _080725E8
_080725E6:
	movs r0, 0
_080725E8:
	cmp r0, 0
	beq _080725EE
	b _0807272E
_080725EE:
	movs r1, 0x1
	mov r8, r1
	b _080725F8
_080725F4:
	movs r2, 0x1
	add r8, r2
_080725F8:
	ldrb r3, [r5, 0x9]
	cmp r8, r3
	bge _08072610
	mov r0, sp
	ldr r1, [sp, 0x18]
	mov r2, r8
	bl GetPokemonLevelData
	ldr r0, [sp]
	ldr r1, [sp, 0x1C]
	cmp r0, r1
	blt _080725F4
_08072610:
	mov r2, r8
	subs r2, 0x1
	str r2, [sp, 0x14]
	ldrb r3, [r5, 0x9]
	mov r8, r3
	cmp r8, r2
	ble _08072710
	mov r9, sp
	movs r0, 0x1
	mov r10, r0
_08072624:
	mov r4, r8
	adds r4, 0x1
	mov r1, r8
	cmp r1, 0x63
	bgt _08072640
	mov r0, sp
	ldr r1, [sp, 0x18]
	adds r2, r4, 0
	bl GetPokemonLevelData
	ldr r0, [sp]
	subs r0, 0x1
	str r0, [r5, 0x18]
	b _08072644
_08072640:
	ldr r2, [sp, 0x1C]
	str r2, [r5, 0x18]
_08072644:
	ldr r3, [sp, 0x20]
	cmp r3, r8
	ble _08072704
	mov r0, sp
	ldr r1, [sp, 0x18]
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r0, r8
	strb r0, [r5, 0x9]
	ldrh r0, [r5, 0x10]
	mov r2, r9
	ldrh r1, [r2, 0x4]
	subs r0, r1
	strh r0, [r5, 0x10]
	ldrh r0, [r5, 0xE]
	ldrh r1, [r2, 0x4]
	subs r0, r1
	strh r0, [r5, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bgt _08072676
	mov r3, r10
	strh r3, [r5, 0xE]
_08072676:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bgt _08072682
	mov r2, r10
	strh r2, [r5, 0x10]
_08072682:
	movs r3, 0xE
	ldrsh r1, [r5, r3]
	ldrh r2, [r5, 0x10]
	movs r3, 0x10
	ldrsh r0, [r5, r3]
	cmp r1, r0
	blt _08072692
	strh r2, [r5, 0xE]
_08072692:
	ldr r7, _08072734
	ldrb r4, [r5, 0x14]
	str r4, [r7]
	ldrb r1, [r5, 0x15]
	str r1, [r7, 0x4]
	ldr r6, _08072738
	ldrb r2, [r5, 0x16]
	str r2, [r6]
	ldrb r0, [r5, 0x17]
	mov r12, r0
	mov r3, r9
	ldrb r0, [r3, 0x6]
	subs r4, r0
	str r4, [r7]
	ldrb r0, [r3, 0x7]
	subs r1, r0
	str r1, [r7, 0x4]
	ldrb r0, [r3, 0x8]
	subs r2, r0
	str r2, [r6]
	ldrb r0, [r3, 0x9]
	mov r1, r12
	subs r3, r1, r0
	str r3, [r6, 0x4]
	cmp r4, 0x1
	bgt _080726CA
	mov r2, r10
	str r2, [r7]
_080726CA:
	ldr r0, [r7, 0x4]
	cmp r0, 0x1
	bgt _080726D4
	mov r3, r10
	str r3, [r7, 0x4]
_080726D4:
	ldr r0, [r6]
	cmp r0, 0x1
	bgt _080726DE
	mov r0, r10
	str r0, [r6]
_080726DE:
	ldr r0, [r6, 0x4]
	cmp r0, 0x1
	bgt _080726E8
	mov r1, r10
	str r1, [r6, 0x4]
_080726E8:
	ldr r0, [sp, 0x10]
	bl LoadIQSkills
	ldr r0, [sp, 0x10]
	bl sub_8079764
	ldr r0, [r7]
	strb r0, [r5, 0x14]
	ldr r0, [r7, 0x4]
	strb r0, [r5, 0x15]
	ldr r0, [r6]
	strb r0, [r5, 0x16]
	ldr r0, [r6, 0x4]
	strb r0, [r5, 0x17]
_08072704:
	movs r2, 0x1
	negs r2, r2
	add r8, r2
	ldr r3, [sp, 0x14]
	cmp r8, r3
	bgt _08072624
_08072710:
	ldr r0, _0807273C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument_2
	ldrb r1, [r5, 0x9]
	ldr r0, [sp, 0x20]
	cmp r1, r0
	bne _08072744
	ldr r0, _08072740
	ldr r2, [r0]
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	bl sub_80522F4
_0807272E:
	movs r0, 0
	b _08072760
	.align 2, 0
_08072734: .4byte gUnknown_202F31C
_08072738: .4byte gUnknown_202F324
_0807273C: .4byte gAvailablePokemonNames
_08072740: .4byte gUnknown_80F9EEC
_08072744:
	ldr r0, _08072770
	str r1, [r0]
	movs r1, 0xD3
	lsls r1, 1
	ldr r0, [sp, 0x10]
	bl sub_80421C0
	ldr r0, _08072774
	ldr r2, [r0]
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	bl sub_80522F4
	movs r0, 0x1
_08072760:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08072770: .4byte gUnknown_202DE30
_08072774: .4byte gUnknown_80F9EC8
	thumb_func_end sub_80725A4

	thumb_func_start sub_8072778
sub_8072778:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xD0
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0xC4]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0xC8]
	ldr r0, [r1, 0x70]
	mov r8, r0
	movs r1, 0
	str r1, [sp, 0xCC]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _080727A8
	movs r2, 0
	str r2, [sp, 0xC8]
	movs r4, 0
	str r4, [sp, 0xC4]
_080727A8:
	mov r0, r8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldrb r2, [r0, 0x9]
	movs r4, 0xC
	ldrsh r3, [r0, r4]
	mov r0, sp
	bl sub_808E0AC
	adds r7, r0, 0
	add r4, sp, 0x20
	movs r1, 0x8C
	lsls r1, 1
	add r1, r8
	adds r0, r4, 0
	bl sub_8093FC8
	mov r10, r4
	cmp r7, 0
	beq _08072810
	adds r0, r7, 0
	bl DungeonRandomCapped
	movs r2, 0
	lsls r0, 1
	mov r1, sp
	adds r6, r1, r0
	mov r5, sp
	adds r5, 0x21
	mov r3, r10
_080727E4:
	lsls r0, r2, 3
	add r0, sp
	adds r0, 0x20
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08072806
	ldrh r1, [r6]
	adds r0, r3, 0
	bl InitPokemonMove
	ldrb r1, [r5]
	movs r0, 0x4
	orrs r0, r1
	strb r0, [r5]
	b _08072810
_08072806:
	adds r5, 0x8
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x7
	ble _080727E4
_08072810:
	movs r5, 0
	movs r4, 0x1
_08072814:
	movs r7, 0
	movs r2, 0
_08072818:
	lsls r0, r2, 3
	add r0, sp
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0807282A
	adds r7, 0x1
_0807282A:
	adds r2, 0x1
	cmp r2, 0x7
	ble _08072818
	cmp r7, 0x4
	bgt _080728D4
	movs r3, 0
	movs r5, 0
	cmp r3, r7
	bge _0807287C
	movs r4, 0x8C
	lsls r4, 1
	add r4, r8
	mov r6, r10
_08072844:
	lsls r0, r5, 3
	movs r2, 0x8C
	lsls r2, 1
	add r2, r8
	adds r2, r0
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08072872
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r4, 0x1]
	add r0, sp, 0x60
	adds r1, r4, 0
	movs r2, 0
	bl sub_80928C0
	movs r3, 0x1
_08072872:
	adds r4, 0x8
	adds r6, 0x8
	adds r5, 0x1
	cmp r5, r7
	blt _08072844
_0807287C:
	cmp r5, 0x3
	bgt _08072894
	movs r2, 0x8C
	lsls r2, 1
	movs r1, 0
_08072886:
	lsls r0, r5, 3
	add r0, r8
	adds r0, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x3
	ble _08072886
_08072894:
	cmp r3, 0
	beq _08072928
	ldr r2, [sp, 0xC4]
	cmp r2, 0
	beq _08072928
	ldr r0, _080728C8
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _080728CC
	add r1, sp, 0x60
	bl strcpy
	mov r0, r9
	movs r1, 0x9C
	lsls r1, 1
	bl sub_80421C0
	ldr r0, _080728D0
	ldr r1, [r0]
	mov r0, r9
	bl sub_80528F4
	b _08072928
	.align 2, 0
_080728C8: .4byte gAvailablePokemonNames
_080728CC: .4byte gUnknown_202DE58
_080728D0: .4byte gUnknown_80F9F04
_080728D4:
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072918
	ldr r2, [sp, 0xC8]
	cmp r2, 0
	beq _08072918
	ldr r0, [sp, 0xCC]
	cmp r0, 0
	bne _08072902
	ldr r1, [sp, 0xC4]
	cmp r1, 0
	beq _08072902
	movs r0, 0xA
	movs r1, 0x6
	bl sub_803E708
	ldr r0, _08072914
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08072902:
	movs r2, 0x1
	str r2, [sp, 0xCC]
	mov r0, r9
	mov r1, r10
	movs r3, 0
	bl sub_8063E70
	b _08072920
	.align 2, 0
_08072914: .4byte gUnknown_80F9FA4
_08072918:
	mov r0, r9
	mov r1, r10
	bl sub_8072B24
_08072920:
	adds r5, 0x1
	cmp r5, 0x1D
	bgt _08072928
	b _08072814
_08072928:
	add sp, 0xD0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8072778

	thumb_func_start sub_8072938
sub_8072938:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA4
	mov r9, r0
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r0, [r0, 0x70]
	mov r8, r0
	movs r1, 0
	mov r10, r1
	movs r1, 0x8C
	lsls r1, 1
	add r1, r8
	mov r0, sp
	bl sub_8093FC8
	movs r3, 0
	mov r4, sp
	mov r2, sp
_08072964:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08072980
	adds r0, r2, 0
	adds r1, r5, 0
	bl InitPokemonMove
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	orrs r0, r1
	strb r0, [r4, 0x1]
	b _0807298A
_08072980:
	adds r4, 0x8
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08072964
_0807298A:
	movs r4, 0
	movs r5, 0x1
_0807298E:
	movs r7, 0
	mov r2, sp
	movs r3, 0x7
_08072994:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080729A0
	adds r7, 0x1
_080729A0:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08072994
	cmp r7, 0x4
	bgt _08072A50
	movs r5, 0
	cmp r5, r7
	bge _080729F4
	movs r4, 0x8C
	lsls r4, 1
	add r4, r8
	mov r6, sp
_080729BA:
	lsls r0, r5, 3
	movs r2, 0x8C
	lsls r2, 1
	add r2, r8
	adds r2, r0
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080729EA
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r4, 0x1]
	add r0, sp, 0x40
	adds r1, r4, 0
	movs r2, 0
	bl sub_80928C0
	movs r0, 0x1
	mov r10, r0
_080729EA:
	adds r4, 0x8
	adds r6, 0x8
	adds r5, 0x1
	cmp r5, r7
	blt _080729BA
_080729F4:
	cmp r5, 0x3
	bgt _08072A0C
	movs r2, 0x8C
	lsls r2, 1
	movs r1, 0
_080729FE:
	lsls r0, r5, 3
	add r0, r8
	adds r0, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080729FE
_08072A0C:
	mov r1, r10
	cmp r1, 0
	beq _08072A92
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072A8C
	ldr r0, _08072A44
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08072A48
	add r1, sp, 0x40
	bl strcpy
	mov r0, r9
	movs r1, 0x9C
	lsls r1, 1
	bl sub_80421C0
	ldr r0, _08072A4C
	ldr r1, [r0]
	mov r0, r9
	bl sub_80528F4
	b _08072A8C
	.align 2, 0
_08072A44: .4byte gAvailablePokemonNames
_08072A48: .4byte gUnknown_202DE58
_08072A4C: .4byte gUnknown_80F9F04
_08072A50:
	movs r0, 0
	mov r10, r0
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072A84
	ldr r0, _08072A80
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	mov r0, r9
	mov r1, sp
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8063E70
	lsls r0, 24
	cmp r0, 0
	bne _08072A84
	movs r0, 0
	b _08072AB0
	.align 2, 0
_08072A80: .4byte gUnknown_80FDF40
_08072A84:
	adds r4, 0x1
	cmp r4, 0x1D
	bgt _08072A8C
	b _0807298E
_08072A8C:
	mov r0, r10
	cmp r0, 0
	bne _08072AAE
_08072A92:
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072AAE
	ldr r0, _08072AC0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08072AC4
	ldr r1, [r0]
	mov r0, r9
	bl sub_80528F4
_08072AAE:
	movs r0, 0x1
_08072AB0:
	add sp, 0xA4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08072AC0: .4byte gAvailablePokemonNames
_08072AC4: .4byte gUnknown_80F9F2C
	thumb_func_end sub_8072938

	thumb_func_start sub_8072AC8
sub_8072AC8:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r2, 0
	lsls r1, 16
	asrs r0, r1, 16
	movs r3, 0
	adds r2, r6, 0x6
_08072AD8:
	strh r3, [r2]
	subs r2, 0x2
	cmp r2, r6
	bge _08072AD8
	movs r5, 0
	bl sub_8092B18
	adds r4, r0, 0
	b _08072B04
_08072AEA:
	cmp r5, 0x4
	bne _08072AF6
	movs r0, 0x4
	bl DungeonRandomCapped
	b _08072AFA
_08072AF6:
	adds r0, r5, 0
	adds r5, 0x1
_08072AFA:
	lsls r0, 1
	adds r0, r6
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0]
_08072B04:
	ldrb r0, [r4]
	cmp r0, 0
	beq _08072B1C
	adds r0, r4, 0
	mov r1, sp
	bl sub_808E07C
	adds r4, r0, 0
	ldrb r0, [r4]
	adds r4, 0x1
	cmp r0, r7
	ble _08072AEA
_08072B1C:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8072AC8

	thumb_func_start sub_8072B24
sub_8072B24:
	push {r4-r7,lr}
	adds r5, r1, 0
	movs r4, 0
	movs r7, 0x1
	movs r6, 0xFD
	adds r2, r5, 0
	movs r3, 0x7
_08072B32:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08072B44
	adds r0, r6, 0
	ands r0, r1
	strb r0, [r2]
	adds r4, 0x1
_08072B44:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08072B32
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r3, r0, 0
	adds r4, r5, 0
	adds r4, 0x38
	cmp r3, 0x6
	bgt _08072B6C
	lsls r0, r3, 3
	adds r2, r0, r5
_08072B60:
	ldr r0, [r2, 0x8]
	ldr r1, [r2, 0xC]
	stm r2!, {r0,r1}
	adds r3, 0x1
	cmp r3, 0x6
	ble _08072B60
_08072B6C:
	movs r0, 0
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8072B24

	thumb_func_start sub_8072B78
sub_8072B78:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	mov r8, r0
	adds r7, r1, 0
	lsls r5, r2, 16
	asrs r5, 16
	ldr r6, [r7, 0x70]
	ldr r4, _08072BFC
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument_2
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	bl CopyCyanSpeciesNametoBuffer
	adds r0, r5, 0
	bl sub_80687D0
	adds r4, r0, 0
	lsls r0, r5, 16
	lsrs r0, 16
	strh r0, [r6, 0x4]
	strh r0, [r6, 0x2]
	ldrb r2, [r6, 0x9]
	mov r0, sp
	adds r1, r5, 0
	bl GetPokemonLevelData
	ldr r0, [sp]
	str r0, [r6, 0x18]
	str r4, [r7, 0x64]
	adds r0, r6, 0
	movs r1, 0
	bl sub_806BFC0
	adds r0, r7, 0
	bl sub_8069E0C
	adds r0, r7, 0
	movs r1, 0x7
	bl sub_806CCB4
	ldr r0, _08072C00
	ldr r2, [r0]
	mov r0, r8
	adds r1, r7, 0
	bl sub_80522F4
	adds r0, r7, 0
	bl sub_8042A44
	bl sub_8083D78
	movs r0, 0x9E
	lsls r0, 1
	cmp r5, r0
	bne _08072C74
	movs r5, 0
	ldr r4, _08072C04
	b _08072C0C
	.align 2, 0
_08072BFC: .4byte gAvailablePokemonNames
_08072C00: .4byte gUnknown_80FE2EC
_08072C04: .4byte gAdjacentTileOffsets
_08072C08:
	adds r4, 0x4
	adds r5, 0x1
_08072C0C:
	cmp r5, 0x7
	bgt _08072C36
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	adds r0, r1
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	movs r3, 0x6
	ldrsh r2, [r7, r3]
	adds r1, r2
	bl GetMapTileAtPosition
	adds r1, r0, 0
	ldr r0, _08072C80
	bl sub_807034C
	lsls r0, 24
	cmp r0, 0
	bne _08072C08
_08072C36:
	ldr r0, _08072C80
	mov r8, r0
	bl sub_803D930
	lsls r0, 24
	cmp r0, 0
	beq _08072C74
	add r0, sp, 0xC
	movs r3, 0
	movs r4, 0
	mov r1, r8
	strh r1, [r0]
	ldrb r1, [r6, 0x9]
	strh r1, [r0, 0x8]
	strb r3, [r0, 0x2]
	ldr r1, _08072C84
	lsls r2, r5, 2
	adds r2, r1
	ldrh r1, [r7, 0x4]
	ldrh r5, [r2]
	adds r1, r5
	strh r1, [r0, 0xC]
	ldrh r1, [r7, 0x6]
	ldrh r2, [r2, 0x2]
	adds r1, r2
	strh r1, [r0, 0xE]
	str r4, [r0, 0x4]
	strb r3, [r0, 0x10]
	movs r1, 0x1
	bl sub_806B7F8
_08072C74:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08072C80: .4byte 0x0000013d
_08072C84: .4byte gAdjacentTileOffsets
	thumb_func_end sub_8072B78

	thumb_func_start TargetLeader
TargetLeader:
	push {lr}
	ldr r1, [r0, 0x70]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072CA2
	adds r0, r1, 0
	adds r0, 0x94
	ldrb r0, [r0]
	bl TacticsTargetLeader
	lsls r0, 24
	lsrs r0, 24
	b _08072CA4
_08072CA2:
	movs r0, 0
_08072CA4:
	pop {r1}
	bx r1
	thumb_func_end TargetLeader

	thumb_func_start GetLeaderEntityIfVisible
GetLeaderEntityIfVisible:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _08072CEC
	bl GetLeaderEntity
	adds r4, r0, 0
	cmp r4, 0
	beq _08072CEC
	ldr r0, [r4, 0x70]
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08072CEC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl CanTarget
	lsls r0, 24
	cmp r0, 0
	bne _08072CEC
	adds r0, r5, 0
	adds r1, r4, 0
	bl CanSee_2
	lsls r0, 24
	cmp r0, 0
	beq _08072CEC
	adds r0, r4, 0
	b _08072CEE
_08072CEC:
	movs r0, 0
_08072CEE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetLeaderEntityIfVisible

	thumb_func_start sub_8072CF4
sub_8072CF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x1
	bl sub_804178C
	ldr r1, _08072D4C
	movs r0, 0x1
	strb r0, [r1]
	ldr r6, [r4, 0x70]
	adds r0, r6, 0
	adds r0, 0xFC
	movs r1, 0
	strb r1, [r0]
	subs r0, 0x9
	strb r1, [r0]
	ldr r0, _08072D50
	ldr r0, [r0]
	adds r0, 0xB8
	str r4, [r0]
	ldr r2, _08072D54
	adds r0, r6, 0
	adds r0, 0x44
	ldrh r0, [r0]
	lsls r1, r0, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08072D64
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _08072D58
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_805EFB4
	b _08072D64
	.align 2, 0
_08072D4C: .4byte gUnknown_203B434
_08072D50: .4byte gDungeonGlobalData
_08072D54: .4byte gUnknown_80F58F4
_08072D58:
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8075BA4
_08072D64:
	adds r0, r4, 0
	movs r1, 0
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	beq _08072D86
	adds r0, r4, 0
	movs r1, 0x1
	bl IsCharging
	lsls r0, 24
	cmp r0, 0
	beq _08072D86
	adds r0, r4, 0
	bl sub_8079764
_08072D86:
	movs r7, 0x1
	movs r5, 0xFB
	movs r0, 0x8C
	lsls r0, 1
	adds r2, r6, r0
	movs r3, 0x3
_08072D92:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08072DA4
	ldrb r1, [r2, 0x1]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2, 0x1]
_08072DA4:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08072D92
	adds r0, r4, 0
	movs r1, 0
	bl IsNotAttacking
	lsls r0, 24
	cmp r0, 0
	bne _08072E08
	adds r0, r4, 0
	bl UseAttack
	lsls r0, 24
	cmp r0, 0
	beq _08072DF0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08072DD2
	b _080732D4
_08072DD2:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08072DE0
	b _080732D4
_08072DE0:
	ldr r0, _08072DEC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08072DF0
	movs r0, 0x1
	b _080732D6
	.align 2, 0
_08072DEC: .4byte gUnknown_202F32D
_08072DF0:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _08072DFC
	movs r0, 0xA
	bl sub_8052740
_08072DFC:
	adds r0, r4, 0
	bl sub_806A1E8
	movs r0, 0xA
	bl sub_803E46C
_08072E08:
	adds r0, r6, 0
	adds r0, 0x44
	ldrh r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x1
	bls _08072E26
	cmp r1, 0x4
	beq _08072E26
	cmp r1, 0x2
	beq _08072E26
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0x1
	strb r0, [r1]
_08072E26:
	movs r3, 0
	mov r10, r3
	movs r7, 0xA5
	lsls r7, 1
	adds r0, r6, r7
	mov r1, r10
	strb r1, [r0]
	ldr r0, _08072E50
	strb r1, [r0]
	ldr r0, _08072E54
	strb r1, [r0]
	ldrh r0, [r5]
	subs r0, 0x2
	cmp r0, 0x3F
	bls _08072E46
	b _080731B4
_08072E46:
	lsls r0, 2
	ldr r1, _08072E58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072E50: .4byte gUnknown_202F221
_08072E54: .4byte gUnknown_202F222
_08072E58: .4byte _08072E5C
	.align 2, 0
_08072E5C:
	.4byte _08072F5C
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _08073104
	.4byte _080730A4
	.4byte _0807310C
	.4byte _0807311C
	.4byte _080731B4
	.4byte _08073094
	.4byte _08073094
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _08073094
	.4byte _0807314C
	.4byte _08073154
	.4byte _0807303E
	.4byte _080731B4
	.4byte _0807315C
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _08073186
	.4byte _0807318E
	.4byte _08073170
	.4byte _08073046
	.4byte _0807311C
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _0807309C
	.4byte _08073162
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080730AC
	.4byte _080730B4
	.4byte _080730C4
	.4byte _08073196
	.4byte _08073114
	.4byte _080730E0
	.4byte _080730CC
	.4byte _080730D6
	.4byte _080730BC
	.4byte _0807317E
	.4byte _080731B4
	.4byte _0807311C
_08072F5C:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08072F76
	cmp r0, 0x7
	beq _08072F76
	cmp r0, 0x5
	beq _08072F76
	cmp r0, 0x3
	beq _08072F76
	cmp r0, 0x4
	bne _08072F84
_08072F76:
	movs r0, 0
	strh r0, [r5]
	ldr r2, _08072F80
	adds r1, r6, r2
	b _08072FDA
	.align 2, 0
_08072F80: .4byte 0x00000147
_08072F84:
	movs r3, 0
	mov r9, r3
	ldr r1, _08072FE0
	adds r2, r6, 0
	adds r2, 0x46
	ldrb r3, [r2]
	lsls r0, r3, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r7, [r4, 0x4]
	adds r1, r7
	lsls r1, 16
	ldrh r0, [r0, 0x2]
	ldrh r7, [r4, 0x6]
	adds r0, r7
	lsls r0, 16
	lsrs r1, 16
	mov r8, r1
	orrs r1, r0
	mov r8, r1
	ldrh r1, [r6]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	adds r7, r2, 0
	cmp r0, 0
	bne _08072FCC
	adds r0, r4, 0
	adds r1, r3, 0
	bl CannotMoveForward
	lsls r0, 24
	cmp r0, 0
	bne _08072FCC
	movs r2, 0x1
	mov r9, r2
_08072FCC:
	mov r3, r9
	cmp r3, 0
	beq _08072FE8
	movs r0, 0
	strh r0, [r5]
	ldr r7, _08072FE4
	adds r1, r6, r7
_08072FDA:
	movs r0, 0x1
	strb r0, [r1]
	b _080731B8
	.align 2, 0
_08072FE0: .4byte gAdjacentTileOffsets
_08072FE4: .4byte 0x00000147
_08072FE8:
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	ldrh r0, [r4, 0x4]
	orrs r0, r1
	str r0, [sp]
	mov r0, r8
	lsls r1, r0, 16
	asrs r1, 16
	asrs r2, r0, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_80694C0
	ldrb r1, [r7]
	adds r0, r4, 0
	mov r2, sp
	bl sub_8074FB0
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08073038
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08073038
	adds r0, r4, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _08073038
	adds r0, r4, 0x4
	bl sub_804AE08
_08073038:
	movs r1, 0x1
	mov r10, r1
	b _080731B8
_0807303E:
	adds r0, r4, 0
	bl sub_807CABC
	b _080731B8
_08073046:
	ldr r0, _08073064
	ldr r1, [r0]
	ldr r2, _08073068
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x15
	bne _08073074
	ldr r3, _0807306C
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08073074
	ldr r0, _08073070
	b _080731A2
	.align 2, 0
_08073064: .4byte gDungeonGlobalData
_08073068: .4byte 0x00000644
_0807306C: .4byte 0x000037fe
_08073070: .4byte gUnknown_80FA5B4
_08073074:
	bl sub_804267C
	ldr r0, _0807308C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x2]
	ldr r1, _08073090
	adds r0, r6, 0
	adds r0, 0x46
	ldrb r0, [r0]
	strb r0, [r1]
	b _080731B8
	.align 2, 0
_0807308C: .4byte gDungeonGlobalData
_08073090: .4byte gUnknown_202F32C
_08073094:
	adds r0, r4, 0
	bl sub_8067110
	b _080731B8
_0807309C:
	adds r0, r4, 0
	bl sub_807CB3C
	b _080731B8
_080730A4:
	adds r0, r4, 0
	bl sub_8066744
	b _080731B8
_080730AC:
	adds r0, r4, 0
	bl sub_80668D0
	b _080731B8
_080730B4:
	adds r0, r4, 0
	bl sub_8066AC0
	b _080731B8
_080730BC:
	adds r0, r4, 0
	bl sub_8066BD4
	b _080731B8
_080730C4:
	adds r0, r4, 0
	bl sub_8066CF0
	b _080731B8
_080730CC:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806675C
	b _080731B8
_080730D6:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806684C
	b _080731B8
_080730E0:
	ldr r0, _080730FC
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0xBC
	adds r0, r6, 0
	adds r0, 0x48
	ldrb r0, [r0]
	lsls r0, 2
	ldr r7, _08073100
	adds r1, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _080731B8
	.align 2, 0
_080730FC: .4byte gDungeonGlobalData
_08073100: .4byte 0x0001357c
_08073104:
	adds r0, r4, 0
	bl sub_8066D04
	b _080731B8
_0807310C:
	adds r0, r4, 0
	bl sub_8066E14
	b _080731B8
_08073114:
	adds r0, r4, 0
	bl sub_8066FA4
	b _080731B8
_0807311C:
	adds r0, r6, 0
	bl ToolboxEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08073136
	adds r0, r4, 0
	bl nullsub_95
	adds r0, r4, 0
	bl sub_80671A0
	b _080731B8
_08073136:
	ldr r0, _08073144
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08073148
	b _080731A2
	.align 2, 0
_08073144: .4byte gAvailablePokemonNames
_08073148: .4byte gUnknown_80FE6D4
_0807314C:
	adds r0, r4, 0
	bl sub_8067510
	b _080731B8
_08073154:
	adds r0, r4, 0
	bl sub_8067884
	b _080731B8
_0807315C:
	movs r1, 0xB0
	lsls r1, 1
	b _08073164
_08073162:
	ldr r1, _0807316C
_08073164:
	adds r0, r4, 0
	bl sub_8067904
	b _080731B8
	.align 2, 0
_0807316C: .4byte 0x00000163
_08073170:
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807FE9C
	b _080731B8
_0807317E:
	adds r0, r4, 0
	bl sub_8073D08
	b _080731B8
_08073186:
	adds r0, r4, 0
	bl sub_8073CF0
	b _080731B8
_0807318E:
	adds r0, r4, 0
	bl sub_8073CFC
	b _080731B8
_08073196:
	ldr r0, _080731AC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080731B0
_080731A2:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _080731B8
	.align 2, 0
_080731AC: .4byte gAvailablePokemonNames
_080731B0: .4byte gUnknown_80FE478
_080731B4:
	movs r0, 0x1
	strh r0, [r5]
_080731B8:
	adds r0, r4, 0
	bl sub_807FD84
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080731CC
	b _080732D4
_080731CC:
	ldr r0, [r4, 0x70]
	movs r2, 0xA5
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _080731E2
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8079764
_080731E2:
	movs r0, 0
	bl sub_8041888
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
	bl sub_8085140
	ldr r3, _080732E8
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, 0
	beq _08073242
	movs r5, 0
	strb r5, [r1]
	movs r7, 0x8C
	lsls r7, 1
	adds r2, r6, r7
	movs r0, 0x1
	mov r12, r0
	movs r7, 0x10
	movs r3, 0x3
_08073214:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _0807322C
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0807322C
	movs r0, 0
	strb r0, [r2, 0x4]
	movs r5, 0x1
_0807322C:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08073214
	cmp r5, 0
	beq _08073242
	ldr r0, _080732EC
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_08073242:
	bl sub_807360C
	bl sub_8044B84
	lsls r0, 24
	cmp r0, 0
	bne _08073264
	bl sub_807348C
	bl sub_80732F0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
_08073264:
	mov r1, r10
	cmp r1, 0
	beq _08073270
	adds r0, r4, 0
	bl sub_8075818
_08073270:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
	bl sub_8044B84
	lsls r0, 24
	cmp r0, 0
	bne _0807328A
	bl sub_8046D20
_0807328A:
	movs r0, 0
	bl sub_8041888
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080732D4
	mov r3, r10
	cmp r3, 0
	bne _080732D4
	adds r1, r4, 0x4
	adds r0, r4, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _080732C8
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_080732C8:
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl sub_8071DA4
_080732D4:
	movs r0, 0
_080732D6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080732E8: .4byte 0x0000014b
_080732EC: .4byte gUnknown_80FD2CC
	thumb_func_end sub_8072CF4

	thumb_func_start sub_80732F0
sub_80732F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r4, 0
_080732FE:
	movs r5, 0
	ldr r0, _0807335C
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _08073360
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	bl EntityExists
	lsls r0, 24
	adds r4, 0x1
	str r4, [sp, 0x10]
	cmp r0, 0
	bne _08073320
	b _08073472
_08073320:
	mov r0, r8
	ldr r7, [r0, 0x70]
	movs r1, 0xB2
	lsls r1, 1
	adds r4, r7, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _08073332
	b _08073472
_08073332:
	adds r2, r0, 0
	mov r9, r2
	mov r0, r8
	movs r1, 0x1
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	bne _0807336E
	mov r0, r8
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _08073364
	ldrb r0, [r4]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r4]
	b _08073472
	.align 2, 0
_0807335C: .4byte gDungeonGlobalData
_08073360: .4byte 0x000135cc
_08073364:
	adds r0, r7, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08073378
_0807336E:
	ldrb r0, [r4]
	movs r1, 0xFF
	orrs r0, r1
	strb r0, [r4]
	b _08073472
_08073378:
	movs r0, 0x4
	bl DungeonRandomCapped
	adds r3, r0, 0
	movs r4, 0
_08073382:
	lsls r0, r3, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r2, r7, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073448
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r1, [sp, 0x8]
	lsrs r0, r1, 16
	cmp r0, 0x8A
	beq _08073448
	adds r1, r0, 0
	ldr r0, _08073434
	cmp r1, r0
	beq _08073448
	movs r6, 0
	movs r0, 0x46
	adds r0, r7
	mov r10, r0
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r7, r1
_080733BC:
	lsls r0, r6, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r5, r7, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080733F4
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _080733DE
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080733F4
_080733DE:
	ldrh r0, [r4, 0x2]
	cmp r0, 0xE3
	bne _080733F4
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x1
	bl IsMoveUsable_2
	lsls r0, 24
	cmp r0, 0
	bne _08073440
_080733F4:
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0x3
	ble _080733BC
_080733FC:
	ldr r0, _08073438
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807343C
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	movs r0, 0x7
	mov r1, r9
	ands r1, r0
	movs r0, 0
	mov r2, r10
	strb r1, [r2]
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	mov r0, r8
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8055FA0
	movs r5, 0x1
	b _08073456
	.align 2, 0
_08073434: .4byte 0x00000147
_08073438: .4byte gAvailablePokemonNames
_0807343C: .4byte gUnknown_80FCF38
_08073440:
	adds r0, r5, 0x4
	bl sub_80838EC
	b _080733FC
_08073448:
	adds r3, 0x1
	cmp r3, 0x4
	bne _08073450
	movs r3, 0
_08073450:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08073382
_08073456:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r7, r2
	ldrb r0, [r1]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r1]
	cmp r5, 0
	beq _08073472
	mov r0, r8
	movs r1, 0xB8
	lsls r1, 2
	bl sub_80421C0
_08073472:
	ldr r4, [sp, 0x10]
	cmp r4, 0x13
	bgt _0807347A
	b _080732FE
_0807347A:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80732F0

	thumb_func_start sub_807348C
sub_807348C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	movs r4, 0
	movs r0, 0xFF
	mov r9, r0
_0807349E:
	ldr r0, _080734E8
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _080734EC
	adds r0, r2
	adds r0, r1
	ldr r7, [r0]
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	adds r4, 0x1
	str r4, [sp, 0x10]
	cmp r0, 0
	bne _080734BE
	b _080735E6
_080734BE:
	ldr r6, [r7, 0x70]
	ldr r0, _080734F0
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _080734CC
	b _080735E6
_080734CC:
	adds r1, r0, 0
	mov r8, r1
	adds r0, r7, 0
	movs r1, 0x1
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	beq _080734F4
	ldrb r0, [r4]
	mov r2, r9
	orrs r0, r2
	strb r0, [r4]
	b _080735DA
	.align 2, 0
_080734E8: .4byte gDungeonGlobalData
_080734EC: .4byte 0x000135cc
_080734F0: .4byte 0x00000165
_080734F4:
	adds r0, r7, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _08073514
	ldrb r0, [r4]
	mov r1, r9
	orrs r0, r1
	strb r0, [r4]
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r6, r2
	ldrb r0, [r1]
	mov r2, r9
	b _080735E2
_08073514:
	adds r0, r6, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807354A
	ldrb r0, [r4]
	mov r1, r9
	orrs r0, r1
	strb r0, [r4]
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r6, r2
	ldrb r0, [r1]
	mov r2, r9
	b _080735E2
_08073532:
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r0, r5, 0x4
	bl sub_80838EC
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_806ACE8
	b _0807359C
_0807354A:
	movs r3, 0
	movs r0, 0x46
	adds r0, r6
	mov r10, r0
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r6, r1
_08073558:
	lsls r0, r3, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r5, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073594
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0807357A
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08073594
_0807357A:
	ldrh r0, [r4, 0x2]
	cmp r0, 0x19
	bne _08073594
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	str r3, [sp, 0x14]
	bl IsMoveUsable_2
	lsls r0, 24
	ldr r3, [sp, 0x14]
	cmp r0, 0
	bne _08073532
_08073594:
	adds r4, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08073558
_0807359C:
	ldr r0, _08073600
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08073604
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	movs r0, 0x7
	mov r1, r8
	ands r1, r0
	movs r0, 0
	mov r2, r10
	strb r1, [r2]
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8055FA0
	ldr r2, _08073608
	adds r1, r6, r2
	ldrb r0, [r1]
	mov r2, r9
	orrs r0, r2
	strb r0, [r1]
_080735DA:
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r6, r0
	ldrb r0, [r1]
_080735E2:
	orrs r0, r2
	strb r0, [r1]
_080735E6:
	ldr r4, [sp, 0x10]
	cmp r4, 0x13
	bgt _080735EE
	b _0807349E
_080735EE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073600: .4byte gAvailablePokemonNames
_08073604: .4byte gUnknown_80FCF50
_08073608: .4byte 0x00000165
	thumb_func_end sub_807348C

	.align 2, 0
