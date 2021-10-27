	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start HasIQSkill
HasIQSkill:
	push {lr}
	lsls r2, r1, 24
	lsrs r2, 24
	ldr r0, [r0, 0x70]
	adds r0, 0x90
	movs r1, 0x1
	lsls r1, r2
	bl sub_808ECD0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end HasIQSkill

	thumb_func_start sub_80718F4
sub_80718F4:
	push {r4,lr}
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, [r0, 0x70]
	adds r0, 0x90
	movs r3, 0x1
	adds r1, r3, 0
	lsls r1, r4
	lsls r3, r2
	orrs r1, r3
	bl sub_808ECD0
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80718F4

	thumb_func_start sub_807191C
sub_807191C:
	push {r4-r6,lr}
	ldr r5, [r0, 0x70]
	ldrb r1, [r5, 0x6]
	cmp r1, 0
	beq _08071978
	adds r4, r5, 0
	adds r4, 0x90
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_808EC30
	adds r0, r4, 0
	movs r1, 0x6
	bl sub_808EC30
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_808EC30
	adds r0, r5, 0
	adds r0, 0xF7
	ldrb r0, [r0]
	cmp r0, 0
	beq _08071954
	adds r0, r4, 0
	movs r1, 0x12
	bl sub_808EC30
_08071954:
	ldrb r0, [r5, 0x9]
	ldr r1, _08071974
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	blt _08071968
	adds r0, r4, 0
	movs r1, 0x16
	bl sub_808EC30
_08071968:
	adds r1, r5, 0
	adds r1, 0x94
	movs r0, 0x2
	strb r0, [r1]
	b _080719BE
	.align 2, 0
_08071974: .4byte gUnknown_80F59C4
_08071978:
	adds r0, r5, 0
	adds r0, 0x90
	strb r1, [r0]
	adds r2, r5, 0
	adds r2, 0x91
	strb r1, [r2]
	adds r2, 0x1
	strb r1, [r2]
	movs r4, 0x1
	adds r6, r0, 0
_0807198C:
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	lsls r1, r4, 24
	lsrs r1, 24
	bl sub_808EB7C
	lsls r0, 24
	cmp r0, 0
	beq _080719B8
	movs r1, 0x1
	lsls r1, r4
	adds r0, r5, 0
	adds r0, 0x8C
	bl sub_808ECD0
	lsls r0, 24
	cmp r0, 0
	beq _080719B8
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_808EC30
_080719B8:
	adds r4, 0x1
	cmp r4, 0x17
	ble _0807198C
_080719BE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_807191C

	thumb_func_start sub_80719C4
sub_80719C4:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _080719D6
	b _08071A0A
_080719D2:
	movs r0, 0x1
	b _08071A0C
_080719D6:
	movs r6, 0
_080719D8:
	ldr r0, _08071A14
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08071A18
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08071A04
	cmp r5, r4
	beq _08071A04
	adds r0, r5, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	bne _080719D2
_08071A04:
	adds r6, 0x1
	cmp r6, 0x3
	ble _080719D8
_08071A0A:
	movs r0, 0
_08071A0C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08071A14: .4byte gDungeonGlobalData
_08071A18: .4byte 0x0001357c
	thumb_func_end sub_80719C4

	thumb_func_start sub_8071A1C
sub_8071A1C:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldrh r1, [r2, 0x2]
	movs r0, 0xA2
	lsls r0, 1
	cmp r1, r0
	beq _08071A38
	adds r0, r2, 0
	bl sub_8092B00
	lsls r0, 24
	lsrs r0, 24
	b _08071A3E
_08071A38:
	ldr r0, [r3, 0x70]
	adds r0, 0x3E
	ldrb r0, [r0]
_08071A3E:
	pop {r1}
	bx r1
	thumb_func_end sub_8071A1C

	thumb_func_start sub_8071A44
sub_8071A44:
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	ldrh r1, [r4, 0x2]
	movs r0, 0xA2
	lsls r0, 1
	cmp r1, r0
	beq _08071A60
	adds r0, r4, 0
	bl sub_8092BC0
	ldrb r1, [r4, 0x5]
	adds r0, r1
	b _08071A6A
_08071A60:
	ldr r0, [r2, 0x70]
	movs r1, 0x3C
	ldrsh r0, [r0, r1]
	ldrb r4, [r4, 0x5]
	adds r0, r4
_08071A6A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8071A44

	thumb_func_start sub_8071A70
sub_8071A70:
	push {lr}
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl IsToolboxEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08071A84
	movs r0, 0x1
	b _08071A86
_08071A84:
	movs r0, 0
_08071A86:
	pop {r1}
	bx r1
	thumb_func_end sub_8071A70

	thumb_func_start sub_8071A8C
sub_8071A8C:
	push {r4,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08071AC2
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08071AC2
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08071AB4
	cmp r0, 0x47
	bne _08071AB8
_08071AB4:
	movs r0, 0x1
	b _08071ABA
_08071AB8:
	movs r0, 0
_08071ABA:
	cmp r0, 0
	bne _08071AC2
	movs r0, 0x1
	b _08071AC4
_08071AC2:
	movs r0, 0
_08071AC4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8071A8C

	thumb_func_start sub_8071ACC
sub_8071ACC:
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
	thumb_func_end sub_8071ACC

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
	bl sub_804954C
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
	bl sub_808EB48
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
	bl sub_80708B4
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
	bl sub_808EB48
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
	bl sub_808EB48
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
	bl sub_808EB48
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
	bl sub_80708B4
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
	bl sub_8083600
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
	bl sub_80708B4
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
	bl sub_80708B4
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
	bl sub_807191C
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
	bl sub_807191C
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
	bl sub_80708B4
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
	bl sub_8092A88
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
	bl sub_80708B4
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
	bl sub_8092A88
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
	bl sub_80708B4
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
_08072C04: .4byte gUnknown_80F4448
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
	bl sub_804954C
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
_08072C84: .4byte gUnknown_80F4448
	thumb_func_end sub_8072B78

	thumb_func_start sub_8072C88
sub_8072C88:
	push {lr}
	ldr r1, [r0, 0x70]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08072CA2
	adds r0, r1, 0
	adds r0, 0x94
	ldrb r0, [r0]
	bl sub_808EAFC
	lsls r0, 24
	lsrs r0, 24
	b _08072CA4
_08072CA2:
	movs r0, 0
_08072CA4:
	pop {r1}
	bx r1
	thumb_func_end sub_8072C88

	thumb_func_start sub_8072CA8
sub_8072CA8:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _08072CEC
	bl sub_8083600
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
	bl sub_8071598
	lsls r0, 24
	cmp r0, 0
	bne _08072CEC
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8045A00
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
	thumb_func_end sub_8072CA8

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
	bl sub_8070D04
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
	bl sub_8045028
	lsls r0, 24
	cmp r0, 0
	bne _08072E08
	adds r0, r4, 0
	bl sub_807520C
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
	bl sub_8070D6C
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
_08072FE0: .4byte gUnknown_80F4448
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
	bl sub_8046CB0
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
	bl sub_8071A70
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
	bl sub_8070D04
	lsls r0, 24
	cmp r0, 0
	bne _0807336E
	mov r0, r8
	bl sub_8070B28
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
	bl sub_80573CC
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
	bl sub_8070D04
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
	bl sub_8070B28
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
	bl sub_80573CC
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

	thumb_func_start sub_807360C
sub_807360C:
	push {r4,r5,lr}
	movs r5, 0
_08073610:
	ldr r0, _08073650
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08073654
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08073644
	ldr r0, [r4, 0x70]
	movs r2, 0xA9
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _08073644
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	adds r1, r4, 0
	bl sub_8077274
_08073644:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08073610
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073650: .4byte gDungeonGlobalData
_08073654: .4byte 0x000135cc
	thumb_func_end sub_807360C

	thumb_func_start DecideUseItem
DecideUseItem:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	mov r8, r0
	ldr r6, [r0, 0x70]
	bl CannotUseItems
	lsls r0, 24
	cmp r0, 0
	beq _080736B8
	adds r1, r6, 0
	adds r1, 0xFC
	movs r0, 0
	strb r0, [r1]
	b _080739C4
_0807367C:
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x24
	bl sub_8044C94
	adds r0, r6, 0
	adds r0, 0x48
	add r1, sp, 0x54
	ldrb r1, [r1]
	strb r1, [r0]
	mov r2, r8
	ldrh r1, [r2, 0x4]
	adds r0, 0x4
	strh r1, [r0]
	ldrh r0, [r2, 0x6]
	adds r1, r6, 0
	adds r1, 0x4E
	strh r0, [r1]
	ldr r0, _080736B4
	adds r0, r7, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	adds r1, r6, 0
	adds r1, 0x46
	strb r0, [r1]
	b _08073718
	.align 2, 0
_080736B4: .4byte gUnknown_202F330
_080736B8:
	adds r0, r6, 0
	adds r0, 0xFC
	ldrb r0, [r0]
	cmp r0, 0
	bne _080736C4
	b _080737DC
_080736C4:
	adds r7, r6, 0
	adds r7, 0x60
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080736D4
	b _080739C4
_080736D4:
	movs r3, 0x81
	str r3, [sp, 0x54]
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0807372C
	mov r0, r8
	movs r1, 0x2
	adds r2, r7, 0
	movs r3, 0x1
	bl sub_80739DC
	movs r5, 0
	ldr r0, _08073724
	ldr r0, [r0]
	cmp r5, r0
	bge _08073718
	ldr r4, _08073728
_080736FE:
	lsls r7, r5, 2
	ldr r0, [r4]
	bl sub_8084144
	lsls r0, 24
	cmp r0, 0
	bne _0807367C
	adds r4, 0x4
	adds r5, 0x1
	ldr r0, _08073724
	ldr r0, [r0]
	cmp r5, r0
	blt _080736FE
_08073718:
	ldr r0, _08073724
	ldr r0, [r0]
	cmp r5, r0
	beq _08073722
	b _080739C4
_08073722:
	b _08073792
	.align 2, 0
_08073724: .4byte gUnknown_203B440
_08073728: .4byte gUnknown_202F358
_0807372C:
	cmp r0, 0x1
	bne _0807377C
	mov r0, r8
	adds r1, r7, 0
	mov r2, sp
	movs r3, 0x1
	bl sub_8073AA0
	ldr r0, _08073778
	ldr r0, [r0]
	cmp r0, 0
	beq _08073792
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x24
	bl sub_8044C94
	adds r0, r6, 0
	adds r0, 0x48
	add r1, sp, 0x54
	ldrb r1, [r1]
	strb r1, [r0]
	mov r2, r8
	ldrh r1, [r2, 0x4]
	adds r0, 0x4
	strh r1, [r0]
	ldrh r0, [r2, 0x6]
	adds r1, r6, 0
	adds r1, 0x4E
	strh r0, [r1]
	mov r0, r8
	adds r0, 0x4
	lsls r4, 2
	add r4, sp
	b _0807395E
	.align 2, 0
_08073778: .4byte gUnknown_203B440
_0807377C:
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08073792
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x23
	bl sub_8044C94
	b _080738CE
_08073792:
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x39
	bl sub_8044C94
	b _080739C4
_0807379E:
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x24
	bl sub_8044C94
	adds r0, r6, 0
	adds r0, 0x48
	add r3, sp, 0x54
	ldrb r3, [r3]
	strb r3, [r0]
	mov r0, r8
	ldrh r1, [r0, 0x4]
	adds r0, r6, 0
	adds r0, 0x4C
	strh r1, [r0]
	mov r1, r8
	ldrh r0, [r1, 0x6]
	adds r1, r6, 0
	adds r1, 0x4E
	strh r0, [r1]
	ldr r0, _080737D8
	add r0, r10
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	adds r1, r6, 0
	adds r1, 0x46
	strb r0, [r1]
	b _080739C4
	.align 2, 0
_080737D8: .4byte gUnknown_202F330
_080737DC:
	mov r0, r8
	movs r1, 0x16
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _080737EC
	b _080739C4
_080737EC:
	movs r2, 0x1
	str r2, [sp, 0x50]
_080737F0:
	ldr r3, [sp, 0x50]
	cmp r3, 0x1
	bne _080737FE
	adds r7, r6, 0
	adds r7, 0x60
	movs r0, 0x81
	b _0807384E
_080737FE:
	ldr r1, [sp, 0x50]
	cmp r1, 0
	bne _08073832
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	bne _0807381C
	b _080739B8
_0807381C:
	bl sub_80450F8
	cmp r0, 0x3
	beq _08073826
	b _080739B8
_08073826:
	ldr r0, [r4, 0x14]
	bl sub_8045108
	adds r7, r0, 0
	movs r0, 0x80
	b _0807384E
_08073832:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0807383A
	b _080739C4
_0807383A:
	ldr r1, _080738C0
	ldr r2, [sp, 0x50]
	lsls r0, r2, 2
	subs r0, 0x8
	ldr r1, [r1]
	adds r7, r1, r0
	adds r0, r2, 0
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
_0807384E:
	str r0, [sp, 0x54]
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0807385C
	b _080739B8
_0807385C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08073866
	b _080739B8
_08073866:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08073870
	b _080739B8
_08073870:
	ldrb r0, [r7, 0x2]
	movs r1, 0
	bl GetItemAIFlags
	lsls r0, 24
	cmp r0, 0
	beq _080738EC
	mov r0, r8
	adds r1, r7, 0
	movs r2, 0x2
	bl sub_8048F28
	adds r5, r0, 0
	cmp r5, 0
	beq _080738EC
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r4, 0x9
	bne _080738A4
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _080738EC
_080738A4:
	adds r0, r5, 0
	bl sub_8084144
	lsls r0, 24
	cmp r0, 0
	beq _080738EC
	cmp r4, 0x9
	bne _080738C4
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x31
	bl sub_8044C94
	b _080738CE
	.align 2, 0
_080738C0: .4byte gTeamInventory_203B460
_080738C4:
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x23
	bl sub_8044C94
_080738CE:
	adds r0, r6, 0
	adds r0, 0x48
	add r3, sp, 0x54
	ldrb r3, [r3]
	strb r3, [r0]
	mov r0, r8
	ldrh r1, [r0, 0x4]
	adds r0, r6, 0
	adds r0, 0x4C
	strh r1, [r0]
	mov r2, r8
	ldrh r1, [r2, 0x6]
	adds r0, 0x2
	strh r1, [r0]
	b _080739C4
_080738EC:
	adds r0, r6, 0
	bl sub_8071A70
	lsls r0, 24
	cmp r0, 0
	beq _080739B8
	movs r3, 0x1
	mov r9, r3
_080738FC:
	ldrb r0, [r7, 0x2]
	mov r1, r9
	bl GetItemAIFlags
	lsls r0, 24
	cmp r0, 0
	beq _080739AE
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08073978
	mov r0, r8
	adds r1, r7, 0
	mov r2, sp
	movs r3, 0
	bl sub_8073AA0
	ldr r1, _08073974
	ldr r0, [r1]
	cmp r0, 0
	beq _080739AE
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x24
	bl sub_8044C94
	adds r0, r6, 0
	adds r0, 0x48
	add r2, sp, 0x54
	ldrb r2, [r2]
	strb r2, [r0]
	mov r3, r8
	ldrh r1, [r3, 0x4]
	adds r0, 0x4
	strh r1, [r0]
	ldrh r0, [r3, 0x6]
	adds r1, r6, 0
	adds r1, 0x4E
	strh r0, [r1]
	lsls r4, 2
	add r4, sp
	mov r0, r8
	adds r0, 0x4
_0807395E:
	adds r1, r4, 0
	bl sub_80983D8
	movs r1, 0x7
	ands r0, r1
	adds r1, r6, 0
	adds r1, 0x46
	strb r0, [r1]
	ldr r0, [r4]
	str r0, [r6, 0x58]
	b _080739C4
	.align 2, 0
_08073974: .4byte gUnknown_203B440
_08073978:
	mov r0, r8
	mov r1, r9
	adds r2, r7, 0
	movs r3, 0
	bl sub_80739DC
	movs r5, 0
	ldr r1, _080739D4
	ldr r0, [r1]
	cmp r5, r0
	bge _080739AE
	ldr r4, _080739D8
_08073990:
	lsls r2, r5, 2
	mov r10, r2
	ldr r0, [r4]
	bl sub_8084144
	lsls r0, 24
	cmp r0, 0
	beq _080739A2
	b _0807379E
_080739A2:
	adds r4, 0x4
	adds r5, 0x1
	ldr r3, _080739D4
	ldr r0, [r3]
	cmp r5, r0
	blt _08073990
_080739AE:
	movs r0, 0x1
	add r9, r0
	mov r1, r9
	cmp r1, 0x2
	ble _080738FC
_080739B8:
	ldr r2, [sp, 0x50]
	adds r2, 0x1
	str r2, [sp, 0x50]
	cmp r2, 0x15
	bgt _080739C4
	b _080737F0
_080739C4:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080739D4: .4byte gUnknown_203B440
_080739D8: .4byte gUnknown_202F358
	thumb_func_end DecideUseItem

	thumb_func_start sub_80739DC
sub_80739DC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	mov r10, r1
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	ldr r1, _08073A44
	movs r0, 0
	str r0, [r1]
	ldr r1, _08073A48
	movs r2, 0
	adds r0, r1, 0x7
_08073A00:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08073A00
	movs r7, 0
_08073A0A:
	ldr r0, _08073A4C
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08073A50
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08073A88
	cmp r5, r4
	beq _08073A88
	mov r0, r10
	cmp r0, 0x1
	bne _08073A54
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_8071598
	lsls r0, 24
	cmp r0, 0
	bne _08073A88
	movs r6, 0x3
	b _08073A6A
	.align 2, 0
_08073A44: .4byte gUnknown_203B440
_08073A48: .4byte gUnknown_202F350
_08073A4C: .4byte gDungeonGlobalData
_08073A50: .4byte 0x000135cc
_08073A54:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08073A88
	movs r6, 0x1
_08073A6A:
	adds r0, r5, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _08073A88
	mov r2, r8
	str r2, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r9
	adds r3, r6, 0
	bl sub_8073B78
_08073A88:
	adds r7, 0x1
	cmp r7, 0x13
	ble _08073A0A
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80739DC

	thumb_func_start sub_8073AA0
sub_8073AA0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	mov r10, r1
	mov r9, r2
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	ldr r1, _08073B6C
	movs r0, 0
	str r0, [r1]
	movs r6, 0
	adds r7, r1, 0
_08073AC0:
	ldr r0, _08073B70
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08073B74
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08073B56
	cmp r5, r4
	beq _08073B56
	adds r0, r5, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _08073B56
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08073B56
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	cmp r2, 0
	bge _08073B10
	negs r2, r2
_08073B10:
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x6
	ldrsh r0, [r5, r3]
	subs r1, r0
	cmp r1, 0
	bge _08073B20
	negs r1, r1
_08073B20:
	cmp r1, r2
	bge _08073B26
	adds r1, r2, 0
_08073B26:
	cmp r1, 0xA
	bgt _08073B56
	mov r0, r8
	cmp r0, 0
	bne _08073B44
	adds r0, r4, 0
	mov r1, r10
	movs r2, 0x1
	bl sub_8048F28
	bl sub_8084144
	lsls r0, 24
	cmp r0, 0
	beq _08073B56
_08073B44:
	ldr r2, [r7]
	lsls r1, r2, 2
	add r1, r9
	ldrh r0, [r4, 0x4]
	strh r0, [r1]
	ldrh r0, [r4, 0x6]
	strh r0, [r1, 0x2]
	adds r2, 0x1
	str r2, [r7]
_08073B56:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08073AC0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073B6C: .4byte gUnknown_203B440
_08073B70: .4byte gDungeonGlobalData
_08073B74: .4byte 0x000135cc
	thumb_func_end sub_8073AA0

	thumb_func_start sub_8073B78
sub_8073B78:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r9, r2
	mov r10, r3
	ldr r0, [sp, 0x20]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	cmp r2, 0
	bge _08073BA2
	negs r2, r2
_08073BA2:
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r6, 0x6
	ldrsh r0, [r5, r6]
	subs r1, r0
	cmp r1, 0
	bge _08073BB2
	negs r1, r1
_08073BB2:
	ldr r0, [r4, 0x70]
	adds r0, 0xE0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08073BCA
	adds r0, r1, 0
	cmp r1, r2
	bge _08073BC4
	adds r0, r2, 0
_08073BC4:
	cmp r0, 0xA
	ble _08073BCA
	b _08073CDC
_08073BCA:
	movs r6, 0x1
	negs r6, r6
	cmp r2, r1
	bne _08073C14
	movs r7, 0x4
	ldrsh r1, [r4, r7]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bge _08073BFA
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bge _08073BF2
	movs r6, 0x1
	b _08073C7E
_08073BF2:
	cmp r1, r0
	ble _08073BFA
	movs r6, 0x3
	b _08073C7E
_08073BFA:
	lsls r1, r2, 16
	lsls r0, r3, 16
	movs r6, 0x7
	cmp r1, r0
	ble _08073C7A
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble _08073C7A
	movs r6, 0x5
	b _08073C7E
_08073C14:
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	ldrh r2, [r4, 0x4]
	ldrh r3, [r5, 0x4]
	cmp r1, r0
	bne _08073C34
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bge _08073C34
	movs r6, 0
	b _08073C7E
_08073C34:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bge _08073C4C
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bne _08073C4C
	movs r6, 0x2
	b _08073C7E
_08073C4C:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	bne _08073C64
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r7, 0x6
	ldrsh r0, [r5, r7]
	cmp r1, r0
	ble _08073C64
	movs r6, 0x4
	b _08073C7E
_08073C64:
	lsls r1, r2, 16
	lsls r0, r3, 16
	cmp r1, r0
	ble _08073C7A
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _08073C7A
	movs r6, 0x6
_08073C7A:
	cmp r6, 0
	blt _08073CDC
_08073C7E:
	ldr r0, _08073CC0
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, 0
	bne _08073CDC
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0xA
	bl sub_807C9F8
	lsls r0, 24
	cmp r0, 0
	beq _08073CDC
	movs r0, 0x1
	strb r0, [r7]
	ldr r1, _08073CC4
	ldr r0, _08073CC8
	ldr r0, [r0]
	lsls r0, 2
	adds r1, r0, r1
	str r6, [r1]
	ldr r1, _08073CCC
	adds r4, r0, r1
	mov r3, r8
	cmp r3, 0
	bne _08073CD0
	adds r0, r5, 0
	mov r1, r9
	mov r2, r10
	bl sub_8048F28
	b _08073CD2
	.align 2, 0
_08073CC0: .4byte gUnknown_202F350
_08073CC4: .4byte gUnknown_202F330
_08073CC8: .4byte gUnknown_203B440
_08073CCC: .4byte gUnknown_202F358
_08073CD0:
	movs r0, 0x64
_08073CD2:
	str r0, [r4]
	ldr r1, _08073CEC
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08073CDC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073CEC: .4byte gUnknown_203B440
	thumb_func_end sub_8073B78

	thumb_func_start sub_8073CF0
sub_8073CF0:
	push {lr}
	bl sub_8067110
	pop {r0}
	bx r0
	thumb_func_end sub_8073CF0

	thumb_func_start sub_8073CFC
sub_8073CFC:
	push {lr}
	bl sub_80671A0
	pop {r0}
	bx r0
	thumb_func_end sub_8073CFC

	thumb_func_start sub_8073D08
sub_8073D08:
	push {lr}
	bl sub_8073D14
	pop {r0}
	bx r0
	thumb_func_end sub_8073D08

	thumb_func_start sub_8073D14
sub_8073D14:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xB0
	adds r6, r0, 0
	ldr r4, [r6, 0x70]
	bl sub_8045128
	ldr r5, [r0, 0x14]
	cmp r5, 0
	bne _08073D30
	b _0807407A
_08073D30:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08073D3C
	b _0807407A
_08073D3C:
	ldr r0, _08073D68
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _08073D4E
	b _0807407A
_08073D4E:
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1
	bne _08073D56
	b _0807407A
_08073D56:
	adds r0, r4, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08073D64
	cmp r0, 0x47
	bne _08073D6C
_08073D64:
	movs r0, 0x1
	b _08073D6E
	.align 2, 0
_08073D68: .4byte gAvailablePokemonNames
_08073D6C:
	movs r0, 0
_08073D6E:
	cmp r0, 0
	beq _08073D74
	b _0807407A
_08073D74:
	adds r0, r4, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08073D80
	b _0807407A
_08073D80:
	ldr r0, [r6, 0x70]
	mov r10, r0
	adds r0, r5, 0
	bl sub_8045108
	adds r5, r0, 0
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08073D98
	b _0807407A
_08073D98:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	beq _08073DC8
	ldr r0, _08073DBC
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08073DC0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08073DC4
	b _0807404C
	.align 2, 0
_08073DBC: .4byte gUnknown_202DE58
_08073DC0: .4byte gAvailablePokemonNames
_08073DC4: .4byte gUnknown_80F8F88
_08073DC8:
	mov r1, r10
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	bne _08073E24
	ldrb r0, [r5, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08073E24
	mov r7, r10
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _08073DF4
	ldr r0, _08073DF0
	bl PlaySoundEffect
	b _08073DFC
	.align 2, 0
_08073DF0: .4byte 0x0000014b
_08073DF4:
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySoundEffect
_08073DFC:
	adds r0, r5, 0
	bl GetMoneyValue
	bl AddToTeamMoney
	ldr r0, _08073E1C
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08073E20
	b _0807404C
	.align 2, 0
_08073E1C: .4byte gUnknown_202DE58
_08073E20: .4byte gUnknown_80F9054
_08073E24:
	ldr r0, _08073E64
	ldr r0, [r0]
	ldr r1, _08073E68
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08073E70
	mov r7, r10
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	bne _08073E70
	movs r4, 0
	add r2, sp, 0x54
	adds r7, 0x60
	ldr r0, _08073E6C
	mov r1, sp
	ldr r0, [r0]
	adds r3, r2, 0
_08073E48:
	stm r3!, {r0}
	stm r1!, {r4}
	adds r0, 0x4
	adds r4, 0x1
	cmp r4, 0x13
	ble _08073E48
	str r7, [r2, 0x50]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x50]
	movs r0, 0x15
	mov r8, r0
	b _08073E80
	.align 2, 0
_08073E64: .4byte gDungeonGlobalData
_08073E68: .4byte 0x0000065b
_08073E6C: .4byte gTeamInventory_203B460
_08073E70:
	mov r0, r10
	adds r0, 0x60
	str r0, [sp, 0x54]
	movs r0, 0x1
	negs r0, r0
	str r0, [sp]
	movs r1, 0x1
	mov r8, r1
_08073E80:
	ldrb r0, [r5, 0x2]
	add r7, sp, 0xA8
	strb r0, [r7]
	adds r0, r7, 0
	ldrb r0, [r0]
	cmp r0, 0x8
	bls _08073E90
	b _08073FA8
_08073E90:
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08073E9C
	b _08073FA8
_08073E9C:
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	mov r7, r12
	str r7, [sp, 0xAC]
	movs r4, 0
	cmp r4, r8
	bge _08073EEC
	ldr r0, _08073F94
	mov r9, r0
	add r3, sp, 0x54
_08073EB2:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073EE4
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08073EE4
	ldr r1, [r5]
	mov r7, r9
	ands r1, r7
	ldr r0, [r2]
	ands r0, r7
	cmp r1, r0
	bne _08073EE4
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08073EE4
	ldr r1, [sp, 0xAC]
	cmp r1, r0
	bge _08073EE4
	str r0, [sp, 0xAC]
	mov r12, r4
_08073EE4:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08073EB2
_08073EEC:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	bne _08073F40
	mov r7, r12
	str r7, [sp, 0xAC]
	movs r4, 0
	cmp r4, r8
	bge _08073F38
	add r0, sp, 0xA8
	ldrb r0, [r0]
	mov r9, r0
	add r3, sp, 0x54
_08073F06:
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073F30
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08073F30
	ldrb r1, [r2, 0x2]
	cmp r9, r1
	bne _08073F30
	ldrb r0, [r2, 0x1]
	cmp r0, 0x63
	beq _08073F30
	ldr r7, [sp, 0xAC]
	cmp r7, r0
	bge _08073F30
	str r0, [sp, 0xAC]
	mov r12, r4
_08073F30:
	adds r3, 0x4
	adds r4, 0x1
	cmp r4, r8
	blt _08073F06
_08073F38:
	movs r0, 0x1
	negs r0, r0
	cmp r12, r0
	beq _08073FA8
_08073F40:
	add r0, sp, 0x54
	mov r1, r12
	lsls r4, r1, 2
	adds r3, r0, r4
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r5, 0x1]
	adds r1, r0
	cmp r1, 0x62
	ble _08073F56
	movs r1, 0x63
_08073F56:
	strb r1, [r2, 0x1]
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08073F6C
	ldr r0, [r3]
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_08073F6C:
	ldr r0, _08073F98
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	movs r0, 0xA5
	lsls r0, 1
	bl PlaySoundEffect
	mov r7, sp
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, 0
	bge _08073FA0
	ldr r0, _08073F9C
	b _0807404C
	.align 2, 0
_08073F94: .4byte 0x00ff0008
_08073F98: .4byte gUnknown_202DE58
_08073F9C: .4byte gUnknown_80F9018
_08073FA0:
	ldr r0, _08073FA4
	b _0807404C
	.align 2, 0
_08073FA4: .4byte gUnknown_80F9050
_08073FA8:
	movs r4, 0
	cmp r4, r8
	bge _08073FD2
	ldr r0, [sp, 0x54]
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073FD2
	movs r3, 0x1
	add r2, sp, 0x54
_08073FBE:
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, r8
	bge _08073FD2
	ldr r0, [r2]
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08073FBE
_08073FD2:
	cmp r4, r8
	bne _08073FEC
	ldr r0, _08073FE4
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08073FE8
	b _0807404C
	.align 2, 0
_08073FE4: .4byte gUnknown_202DE58
_08073FE8: .4byte gUnknown_80F8F54
_08073FEC:
	mov r1, r10
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _08074000
	ldr r0, _08073FFC
	bl PlaySoundEffect
	b _08074008
	.align 2, 0
_08073FFC: .4byte 0x0000014b
_08074000:
	movs r0, 0xA5
	lsls r0, 1
	bl PlaySoundEffect
_08074008:
	lsls r0, r4, 2
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bge _08074034
	ldr r0, [r5]
	mov r7, r10
	str r0, [r7, 0x60]
	ldr r0, _0807402C
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08074030
	b _0807404C
	.align 2, 0
_0807402C: .4byte gUnknown_202DE58
_08074030: .4byte gUnknown_80F9018
_08074034:
	adds r0, r5, 0
	bl AddItemToInventory
	lsls r0, 24
	cmp r0, 0
	beq _08074060
	ldr r0, _08074058
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807405C
_0807404C:
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_805239C
	b _0807407A
	.align 2, 0
_08074058: .4byte gAvailablePokemonNames
_0807405C: .4byte gUnknown_80F8FAC
_08074060:
	ldr r0, _0807408C
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0x4
	movs r1, 0x1
	bl sub_80461C8
	ldr r0, _08074090
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_805239C
_0807407A:
	add sp, 0xB0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807408C: .4byte gUnknown_202DE58
_08074090: .4byte gUnknown_80F9050
	thumb_func_end sub_8073D14

	thumb_func_start sub_8074094
sub_8074094:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r5, r0, 0
	cmp r5, 0
	bne _080740AA
	bl _08074B2E
_080740AA:
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080740B8
	bl _08074B2E
_080740B8:
	bl sub_8044B28
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _080740C8
	bl _08074B2E
_080740C8:
	ldr r0, [r5, 0x70]
	mov r8, r0
	movs r0, 0xA3
	lsls r0, 1
	add r0, r8
	strb r6, [r0]
	bl sub_805229C
	adds r0, r5, 0
	bl sub_807E8F0
	adds r0, r5, 0
	movs r1, 0x16
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08074170
	ldr r4, _0807434C
	add r4, r8
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bls _08074102
	movs r0, 0x13
	strb r0, [r4]
_08074102:
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r2, _08074350
	ldrb r1, [r4]
	lsls r1, 1
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _08074170
	strb r6, [r4]
	adds r0, r5, 0
	bl sub_80444F4
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074136
	bl _08074B2E
_08074136:
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08074146
	bl _08074B2E
_08074146:
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
	mov r3, r8
	ldrb r0, [r3, 0x7]
	cmp r0, 0
	bne _0807415C
	b _080743B0
_0807415C:
	ldr r1, _08074354
	ldr r0, [r1]
	strb r4, [r0, 0x1]
	ldr r0, [r1]
	movs r4, 0xB8
	lsls r4, 3
	adds r0, r4
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_08074170:
	mov r1, r8
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _0807417A
	b _080743B0
_0807417A:
	movs r2, 0
	mov r9, r2
	movs r4, 0xA
	adds r0, r5, 0
	movs r1, 0x17
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08074190
	movs r4, 0
_08074190:
	adds r0, r5, 0
	movs r1, 0x1F
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _080741A0
	subs r4, 0x1
_080741A0:
	adds r0, r5, 0
	movs r1, 0x10
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080741B0
	subs r4, 0x1
_080741B0:
	adds r0, r5, 0
	movs r1, 0x1B
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _080741C0
	adds r4, 0x1
_080741C0:
	adds r0, r5, 0
	movs r1, 0xA
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _080741D0
	adds r4, 0x1
_080741D0:
	adds r0, r5, 0
	movs r1, 0x2B
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _080741E0
	adds r4, 0x1
_080741E0:
	cmp r4, 0
	bge _080741E6
	movs r4, 0
_080741E6:
	cmp r4, 0x13
	ble _080741EC
	movs r4, 0x13
_080741EC:
	mov r3, r9
	str r3, [sp, 0x8]
	ldr r0, _08074358
	str r0, [sp, 0xC]
	add r6, sp, 0x10
	lsls r2, r4, 3
	ldr r0, _0807435C
	adds r2, r0
	adds r0, r6, 0
	add r1, sp, 0x8
	bl sub_800A34C
	ldr r2, _08074360
	add r2, r8
	ldrb r0, [r2]
	cmp r0, 0x1
	bls _0807421E
	ldr r1, _08074364
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 16
	ldr r0, [r6, 0x4]
	adds r0, r1
	str r0, [r6, 0x4]
_0807421E:
	mov r4, r9
	strb r4, [r2]
	movs r4, 0x9E
	lsls r4, 1
	add r4, r8
	ldr r7, [r4]
	add r0, sp, 0x18
	adds r1, r6, 0
	bl sub_80943A8
	ldr r2, [sp, 0x18]
	add r0, sp, 0x1C
	adds r1, r7, 0
	bl sub_80942C0
	ldr r0, [sp, 0x1C]
	str r0, [r4]
	movs r6, 0x1
	adds r0, r7, 0
	bl sub_8094450
	cmp r0, 0x13
	ble _0807425C
	ldr r0, [r4]
	bl sub_8094450
	cmp r0, 0x13
	bgt _0807425C
	ldr r0, _08074368
	ldr r0, [r0]
	mov r9, r0
_0807425C:
	adds r0, r7, 0
	bl sub_8094450
	cmp r0, 0x9
	ble _0807427C
	movs r0, 0x9E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0x9
	bgt _0807427C
	ldr r0, _0807436C
	ldr r0, [r0]
	mov r9, r0
_0807427C:
	movs r4, 0x9E
	lsls r4, 1
	add r4, r8
	ldr r0, [r4]
	bl sub_8094450
	cmp r0, 0
	bne _08074298
	add r0, sp, 0x20
	movs r1, 0
	bl sub_80943A0
	ldr r0, [sp, 0x20]
	str r0, [r4]
_08074298:
	ldr r0, [r4]
	bl sub_8094450
	cmp r0, 0
	bge _080742AE
	add r0, sp, 0x24
	movs r1, 0
	bl sub_80943A0
	ldr r0, [sp, 0x24]
	str r0, [r4]
_080742AE:
	ldr r0, [r4]
	bl sub_8094450
	cmp r0, 0
	bne _08074384
	bl sub_805E804
	adds r0, r5, 0
	bl sub_80444F4
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080742D8
	bl _08074B2E
_080742D8:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080742E6
	bl _08074B2E
_080742E6:
	ldr r3, _08074354
	ldr r0, [r3]
	ldr r2, _08074370
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x9
	bhi _080742F8
	adds r0, 0x1
	strb r0, [r1]
_080742F8:
	ldr r0, [r3]
	adds r0, r2
	ldrb r2, [r0]
	cmp r2, 0x1
	bne _08074308
	ldr r0, _08074374
	ldr r0, [r0]
	mov r9, r0
_08074308:
	cmp r2, 0x2
	bne _08074314
	ldr r0, _08074378
	ldr r0, [r0]
	mov r9, r0
	movs r6, 0
_08074314:
	cmp r2, 0x3
	bne _08074320
	ldr r0, _0807437C
	ldr r0, [r0]
	mov r9, r0
	movs r6, 0
_08074320:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r3, _08074380
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0xE
	bl sub_806F324
	movs r1, 0xA3
	lsls r1, 1
	add r1, r8
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4]
	bl sub_8094450
	cmp r0, 0
	beq _08074390
	b _080743B0
	.align 2, 0
_0807434C: .4byte 0x00000169
_08074350: .4byte gUnknown_80F5594
_08074354: .4byte gDungeonGlobalData
_08074358: .4byte 0x0000199a
_0807435C: .4byte gUnknown_80F54F4
_08074360: .4byte 0x00000153
_08074364: .4byte gUnknown_80F60DC
_08074368: .4byte gUnknown_80FD594
_0807436C: .4byte gUnknown_80FD5B8
_08074370: .4byte 0x00000679
_08074374: .4byte gUnknown_80FD5DC
_08074378: .4byte gUnknown_80FD608
_0807437C: .4byte gUnknown_80FD628
_08074380: .4byte 0x00000211
_08074384:
	ldr r0, _08074408
	ldr r0, [r0]
	ldr r1, _0807440C
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
_08074390:
	mov r2, r9
	cmp r2, 0
	beq _080743B0
	cmp r6, 0
	beq _080743A0
	ldr r0, _08074410
	bl PlaySoundEffect
_080743A0:
	adds r0, r5, 0
	mov r1, r9
	bl SendMessage
	movs r0, 0x1E
	movs r1, 0x32
	bl sub_803E708
_080743B0:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080743BE
	b _08074B2E
_080743BE:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080743CA
	b _08074B2E
_080743CA:
	ldr r0, _08074408
	ldr r0, [r0]
	ldr r3, _08074414
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08074480
	adds r0, r5, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _0807441C
	adds r0, r5, 0
	movs r1, 0x6
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	ldr r0, _08074418
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r3, 0x88
	lsls r3, 2
	adds r0, r5, 0
	movs r2, 0x12
	bl sub_806F324
	b _08074466
	.align 2, 0
_08074408: .4byte gDungeonGlobalData
_0807440C: .4byte 0x00000679
_08074410: .4byte 0x00000153
_08074414: .4byte 0x0000e266
_08074418: .4byte gUnknown_80F4F8E
_0807441C:
	adds r0, r5, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08074466
	adds r0, r5, 0
	movs r1, 0x9
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	adds r0, r5, 0
	movs r1, 0xD
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	adds r0, r5, 0
	movs r1, 0x11
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _08074466
	ldr r0, _08074608
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0x88
	lsls r3, 2
	adds r0, r5, 0
	movs r2, 0x12
	bl sub_806F324
_08074466:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074474
	b _08074B2E
_08074474:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074480
	b _08074B2E
_08074480:
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0x21
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080744D8
	ldr r0, _0807460C
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r4, r0
	bge _080744D8
	adds r0, r5, 0
	bl sub_8070A58
	lsls r0, 24
	cmp r0, 0
	beq _080744D8
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080744C0
	b _08074B2E
_080744C0:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080744CC
	b _08074B2E
_080744CC:
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8079F20
_080744D8:
	adds r0, r5, 0
	movs r1, 0xB
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807450C
	ldr r2, _08074610
	add r2, r8
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	ldrb r1, [r2]
	ldr r0, _08074614
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	blt _0807450C
	movs r0, 0
	strb r0, [r2]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x7F
	movs r3, 0
	bl sub_8077910
_0807450C:
	mov r0, r8
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0807453C
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807452A
	b _08074B2E
_0807452A:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074536
	b _08074B2E
_08074536:
	adds r0, r5, 0
	bl sub_80420B8
_0807453C:
	mov r0, r8
	adds r0, 0xAC
	ldrb r1, [r0]
	adds r6, r0, 0
	cmp r1, 0x1
	bne _080745B6
	mov r4, r8
	adds r4, 0xAE
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807455C
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _0807459C
_0807455C:
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074570
	b _08074B2E
_08074570:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807457C
	b _08074B2E
_0807457C:
	ldr r0, _08074618
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r0, _0807461C
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0x82
	lsls r3, 2
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_806F324
_0807459C:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080745AA
	b _08074B2E
_080745AA:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080745B6
	b _08074B2E
_080745B6:
	ldrb r0, [r6]
	cmp r0, 0x2
	bne _08074628
	mov r4, r8
	adds r4, 0xAE
	ldrb r0, [r4]
	cmp r0, 0
	beq _080745D0
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074696
_080745D0:
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080745E4
	b _08074B2E
_080745E4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080745F0
	b _08074B2E
_080745F0:
	ldr r0, _08074620
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r0, _08074624
	movs r3, 0
	ldrsh r1, [r0, r3]
	b _0807468C
	.align 2, 0
_08074608: .4byte gUnknown_80F4F8E
_0807460C: .4byte gUnknown_80F4E0C
_08074610: .4byte 0x00000113
_08074614: .4byte gUnknown_80F4F30
_08074618: .4byte gUnknown_80F4F32
_0807461C: .4byte gUnknown_80F4F70
_08074620: .4byte gUnknown_80F4F34
_08074624: .4byte gUnknown_80F4F72
_08074628:
	cmp r0, 0x3
	bne _080746B0
	mov r2, r8
	adds r2, 0xAE
	ldrb r0, [r2]
	cmp r0, 0
	beq _08074640
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	cmp r0, 0
	bne _08074696
_08074640:
	mov r1, r8
	adds r1, 0xAF
	ldrb r4, [r1]
	cmp r4, 0x1C
	bhi _0807464E
	adds r0, r4, 0x1
	strb r0, [r1]
_0807464E:
	ldr r0, _08074718
	ldrh r0, [r0]
	strb r0, [r2]
	cmp r4, 0x1C
	ble _0807465A
	movs r4, 0x1D
_0807465A:
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807466E
	b _08074B2E
_0807466E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807467A
	b _08074B2E
_0807467A:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r1, _0807471C
	lsls r0, r4, 1
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
_0807468C:
	ldr r3, _08074720
	adds r0, r5, 0
	movs r2, 0x3
	bl sub_806F324
_08074696:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080746A4
	b _08074B2E
_080746A4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080746B0
	b _08074B2E
_080746B0:
	mov r0, r8
	adds r0, 0xB0
	ldrb r1, [r0]
	mov r10, r0
	cmp r1, 0x7
	bne _08074730
	mov r4, r8
	adds r4, 0xB9
	ldrb r0, [r4]
	cmp r0, 0
	beq _080746D0
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074786
_080746D0:
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080746E4
	b _08074B2E
_080746E4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080746F0
	b _08074B2E
_080746F0:
	ldr r0, _08074724
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	mov r0, r8
	adds r0, 0xB4
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8041C4C
	ldr r0, _08074728
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _0807472C
	adds r0, r5, 0
	movs r2, 0x2
	b _08074782
	.align 2, 0
_08074718: .4byte gUnknown_80F4F36
_0807471C: .4byte gUnknown_80F4FC8
_08074720: .4byte 0x0000020a
_08074724: .4byte gUnknown_80F4F38
_08074728: .4byte gUnknown_80F4F74
_0807472C: .4byte 0x00000209
_08074730:
	cmp r1, 0x4
	bne _080747B0
	mov r4, r8
	adds r4, 0xB9
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074748
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074786
_08074748:
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807475C
	b _08074B2E
_0807475C:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074768
	b _08074B2E
_08074768:
	ldr r0, _080747A4
	ldrh r0, [r0]
	strb r0, [r4]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r0, _080747A8
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r3, _080747AC
	adds r0, r5, 0
	movs r2, 0x5
_08074782:
	bl sub_806F324
_08074786:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074794
	b _08074B2E
_08074794:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080747A0
	b _08074B2E
_080747A0:
	b _08074802
	.align 2, 0
_080747A4: .4byte gUnknown_80F4F3A
_080747A8: .4byte gUnknown_80F4F76
_080747AC: .4byte 0x0000020b
_080747B0:
	cmp r1, 0x5
	bne _08074802
	mov r4, r8
	adds r4, 0xB9
	ldrb r0, [r4]
	cmp r0, 0
	beq _080747C8
	subs r0, 0x1
	strb r0, [r4]
	lsls r0, 24
	cmp r0, 0
	bne _08074802
_080747C8:
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080747DC
	b _08074B2E
_080747DC:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080747E8
	b _08074B2E
_080747E8:
	ldr r0, _080748D4
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r0, _080748D8
	movs r4, 0
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r3, 0
	bl HealTargetHP
_08074802:
	mov r0, r8
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807488A
	mov r2, r8
	adds r2, 0xCC
	ldrb r0, [r2]
	cmp r0, 0
	beq _08074820
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	cmp r0, 0
	bne _08074870
_08074820:
	mov r0, r8
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	cmp r1, 0
	bge _0807482C
	adds r1, 0x3
_0807482C:
	asrs r4, r1, 2
	cmp r4, 0
	bne _08074834
	movs r4, 0x1
_08074834:
	ldr r0, _080748DC
	ldrh r0, [r0]
	strb r0, [r2]
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807484E
	b _08074B2E
_0807484E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807485A
	b _08074B2E
_0807485A:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	movs r3, 0x83
	lsls r3, 2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x7
	bl sub_806F324
_08074870:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807487E
	b _08074B2E
_0807487E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0807488A
	b _08074B2E
_0807488A:
	mov r3, r8
	adds r3, 0xD0
	ldrb r4, [r3]
	mov r9, r4
	cmp r4, 0x1
	beq _08074898
	b _080749AE
_08074898:
	mov r2, r8
	adds r2, 0xDA
	ldrb r0, [r2]
	cmp r0, 0
	beq _080748AC
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	cmp r0, 0
	bne _08074994
_080748AC:
	ldr r0, _080748E0
	movs r1, 0
	ldrsh r6, [r0, r1]
	ldr r0, _080748E4
	ldr r1, [r0]
	mov r0, r8
	adds r0, 0xD8
	ldrb r0, [r0]
	lsls r0, 2
	ldr r4, _080748E8
	adds r1, r4
	adds r1, r0
	ldr r4, [r1]
	ldr r0, _080748EC
	ldrh r0, [r0]
	strb r0, [r2]
	cmp r4, 0
	bne _080748F0
	strb r4, [r3]
	b _08074994
	.align 2, 0
_080748D4: .4byte gUnknown_80F4F3C
_080748D8: .4byte gUnknown_80F4FB2
_080748DC: .4byte gUnknown_80F4F3E
_080748E0: .4byte gUnknown_80F4FB4
_080748E4: .4byte gDungeonGlobalData
_080748E8: .4byte 0x000135cc
_080748EC: .4byte gUnknown_80F4F40
_080748F0:
	ldr r0, [r4, 0x70]
	adds r0, 0x98
	mov r1, r8
	adds r1, 0xD4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _08074906
	movs r0, 0
	strb r0, [r3]
	b _08074994
_08074906:
	adds r0, r5, 0
	movs r1, 0x3A
	bl HasAbility
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0
	bl sub_80444F4
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807492C
	b _08074B2E
_0807492C:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807493A
	b _08074B2E
_0807493A:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074946
	b _08074B2E
_08074946:
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08074994
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	ldr r3, _08074980
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x9
	bl sub_806F324
	cmp r7, 0
	beq _08074984
	adds r0, r4, 0
	adds r1, r4, 0
	bl sub_807A96C
	movs r3, 0xFD
	lsls r3, 1
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0xD
	bl sub_806F324
	b _08074994
	.align 2, 0
_08074980: .4byte 0x0000020d
_08074984:
	mov r2, r9
	str r2, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	movs r3, 0
	bl HealTargetHP
_08074994:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080749A2
	b _08074B2E
_080749A2:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080749AE
	b _08074B2E
_080749AE:
	mov r4, r8
	adds r4, 0xFD
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074A46
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074A46
	movs r0, 0
	bl sub_807520C
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080749D8
	b _08074B2E
_080749D8:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _080749E4
	b _08074B2E
_080749E4:
	ldr r0, _08074A18
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08074A1C
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_807A96C
	mov r0, r8
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08074A24
	ldr r0, _08074A20
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _08074A30
	.align 2, 0
_08074A18: .4byte gUnknown_202DFE8
_08074A1C: .4byte gUnknown_80FEB30
_08074A20: .4byte gPtrProtectSavedItMessage
_08074A24:
	ldr r1, _08074B40
	ldr r3, _08074B44
	adds r0, r5, 0
	movs r2, 0xB
	bl sub_806F324
_08074A30:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074B2E
_08074A46:
	mov r0, r8
	adds r0, 0xC0
	ldrb r1, [r0]
	adds r7, r0, 0
	cmp r1, 0x1
	bne _08074AD4
	mov r4, r8
	adds r4, 0xC1
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074AD4
	strb r0, [r7]
	adds r0, r5, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	bne _08074AD4
	adds r0, r5, 0
	movs r1, 0
	bl sub_8070D04
	lsls r0, 24
	cmp r0, 0
	bne _08074AD4
	adds r0, r5, 0
	bl CannotAct
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _08074AD4
	movs r0, 0
	bl sub_807520C
	add r4, sp, 0x28
	ldr r1, _08074B48
	adds r0, r4, 0
	bl sub_8092A88
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4]
	str r6, [sp]
	str r4, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_8055FA0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _08074B2E
	mov r0, r8
	adds r0, 0xA0
	str r1, [r0]
_08074AD4:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074B2E
	ldrb r0, [r7]
	cmp r0, 0xC
	bne _08074B1E
	mov r4, r8
	adds r4, 0xC1
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074B1E
	strb r0, [r7]
	movs r1, 0xA5
	lsls r1, 1
	add r1, r8
	strb r0, [r1]
	ldr r0, _08074B4C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08074B50
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_08074B1E:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074B2E
	bl sub_8044B28
_08074B2E:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074B40: .4byte 0x0000270f
_08074B44: .4byte 0x0000020e
_08074B48: .4byte 0x00000165
_08074B4C: .4byte gAvailablePokemonNames
_08074B50: .4byte gUnknown_80FABD8
	thumb_func_end sub_8074094

	thumb_func_start sub_8074B54
sub_8074B54:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	cmp r7, 0
	bne _08074B62
	b _08074F96
_08074B62:
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074B6E
	b _08074F96
_08074B6E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074B7A
	b _08074F96
_08074B7A:
	bl sub_805229C
	ldr r6, [r7, 0x70]
	movs r1, 0xA3
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08074C48
	adds r0, r6, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08074C48
	cmp r0, 0x3
	beq _08074C48
	movs r4, 0
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _08074BAE
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	bl GetUnk1B
	lsls r0, 24
	lsrs r4, r0, 24
_08074BAE:
	cmp r4, 0
	beq _08074C48
	adds r0, r7, 0
	movs r1, 0xA
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08074BC8
	ldr r0, _08074EF8
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r4, r0
_08074BC8:
	adds r0, r6, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _08074BDA
	ldr r0, _08074EFC
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r4, r0
_08074BDA:
	adds r0, r7, 0
	movs r1, 0x3
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08074BFE
	adds r0, r7, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _08074BFE
	ldr r0, _08074F00
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r4, r0
_08074BFE:
	movs r0, 0xFA
	lsls r0, 1
	cmp r4, r0
	ble _08074C08
	adds r4, r0, 0
_08074C08:
	cmp r4, 0x1D
	bgt _08074C0E
	movs r4, 0x1E
_08074C0E:
	movs r3, 0xFC
	lsls r3, 1
	adds r1, r6, r3
	ldrh r0, [r6, 0x10]
	ldrh r2, [r1]
	adds r0, r2
	strh r0, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	blt _08074C38
_08074C24:
	ldrh r0, [r6, 0xE]
	adds r0, 0x1
	strh r0, [r6, 0xE]
	ldrh r0, [r1]
	subs r0, r4
	strh r0, [r1]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r4
	bge _08074C24
_08074C38:
	movs r3, 0xE
	ldrsh r1, [r6, r3]
	ldrh r2, [r6, 0x10]
	movs r3, 0x10
	ldrsh r0, [r6, r3]
	cmp r1, r0
	blt _08074C48
	strh r2, [r6, 0xE]
_08074C48:
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074C6E
	adds r4, r6, 0
	adds r4, 0xA9
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074C6E
	adds r0, r7, 0
	adds r1, r7, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_807A124
_08074C6E:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074C7C
	b _08074F96
_08074C7C:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074C88
	b _08074F96
_08074C88:
	adds r0, r6, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074CAA
	adds r4, r6, 0
	adds r4, 0xAD
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074CAA
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A290
_08074CAA:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074CB8
	b _08074F96
_08074CB8:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074CC4
	b _08074F96
_08074CC4:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074CE6
	adds r4, r6, 0
	adds r4, 0xB8
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074CE6
	adds r0, r7, 0
	adds r1, r7, 0
	bl SendImmobilizeEndMessage
_08074CE6:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074CF4
	b _08074F96
_08074CF4:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074D00
	b _08074F96
_08074D00:
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074D22
	adds r4, r6, 0
	adds r4, 0xBD
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074D22
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A400
_08074D22:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074D30
	b _08074F96
_08074D30:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074D3C
	b _08074F96
_08074D3C:
	adds r0, r6, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074D5E
	adds r4, r6, 0
	adds r4, 0xC5
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074D5E
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A4C8
_08074D5E:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074D6C
	b _08074F96
_08074D6C:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074D78
	b _08074F96
_08074D78:
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074D9C
	adds r4, r6, 0
	adds r4, 0xCB
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074D9C
	adds r0, r7, 0
	adds r1, r7, 0
	movs r2, 0
	bl sub_807A5D0
_08074D9C:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074DAA
	b _08074F96
_08074DAA:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074DB6
	b _08074F96
_08074DB6:
	adds r0, r6, 0
	adds r0, 0xD0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074DD8
	adds r4, r6, 0
	adds r4, 0xD9
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074DD8
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A6C8
_08074DD8:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074DE6
	b _08074F96
_08074DE6:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074DF2
	b _08074F96
_08074DF2:
	adds r0, r6, 0
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074E14
	adds r4, r6, 0
	adds r4, 0xDD
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074E14
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A734
_08074E14:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074E22
	b _08074F96
_08074E22:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074E2E
	b _08074F96
_08074E2E:
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074E50
	adds r4, r6, 0
	adds r4, 0xE5
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074E50
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A7C8
_08074E50:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074E5E
	b _08074F96
_08074E5E:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08074E6A
	b _08074F96
_08074E6A:
	adds r0, r6, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074E8C
	adds r4, r6, 0
	adds r4, 0xE9
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074E8C
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A888
_08074E8C:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08074E9A
	b _08074F96
_08074E9A:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074F96
	adds r0, r6, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074EC6
	adds r4, r6, 0
	adds r4, 0xED
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074EC6
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_807A924
_08074EC6:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08074F96
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08074F96
	adds r4, r6, 0
	adds r4, 0xFA
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074F18
	adds r0, r4, 0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074F18
	ldr r0, _08074F04
	adds r1, r7, 0
	b _08074F08
	.align 2, 0
_08074EF8: .4byte gUnknown_80F4FC4
_08074EFC: .4byte gUnknown_80F4FC0
_08074F00: .4byte gUnknown_80F4FC2
_08074F04: .4byte gAvailablePokemonNames
_08074F08:
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08074FA0
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_08074F18:
	movs r0, 0
	mov r8, r0
	movs r5, 0
_08074F1E:
	ldr r1, _08074FA4
	adds r0, r6, r1
	adds r4, r0, r5
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074F3C
	adds r0, r5, r1
	adds r0, r6, r0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074F3C
	movs r2, 0x1
	mov r8, r2
_08074F3C:
	movs r3, 0x84
	lsls r3, 1
	adds r0, r6, r3
	adds r4, r0, r5
	ldrb r0, [r4]
	cmp r0, 0
	beq _08074F5C
	adds r0, r5, r3
	adds r0, r6, r0
	bl sub_80838EC
	ldrb r0, [r4]
	cmp r0, 0
	bne _08074F5C
	movs r0, 0x1
	mov r8, r0
_08074F5C:
	adds r5, 0x1
	cmp r5, 0x4
	ble _08074F1E
	mov r1, r8
	cmp r1, 0
	beq _08074F96
	ldr r0, [r7, 0x70]
	movs r2, 0x82
	lsls r2, 1
	adds r0, r2
	ldr r4, [r0]
	adds r0, r7, 0
	bl sub_8070774
	adds r5, r0, 0
	cmp r4, r5
	beq _08074F96
	ldr r0, _08074FA8
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r1, _08074FAC
	lsls r0, r5, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
_08074F96:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074FA0: .4byte gPtrStenchWavedOffMessage
_08074FA4: .4byte 0x0000010d
_08074FA8: .4byte gAvailablePokemonNames
_08074FAC: .4byte gUnknown_80FA124
	thumb_func_end sub_8074B54

	thumb_func_start sub_8074FB0
sub_8074FB0:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r5, r1, 0
	ldr r4, [r3, 0x70]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x3
	ble _08074FD0
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0
	strh r0, [r1]
	b _08075040
_08074FD0:
	ldr r0, _08074FE0
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08074FE8
	ldr r1, _08074FE4
	movs r0, 0x2
	b _08074FEC
	.align 2, 0
_08074FE0: .4byte gUnknown_203B46C
_08074FE4: .4byte gUnknown_202F378
_08074FE8:
	ldr r1, _08075048
	movs r0, 0x1
_08074FEC:
	str r0, [r1]
	adds r6, r1, 0
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	movs r0, 0xC2
	lsls r0, 1
	adds r1, r0
	adds r1, r4, r1
	movs r0, 0
	strb r0, [r1, 0x1A]
	str r5, [r1, 0xC]
	ldrh r0, [r3, 0x4]
	strh r0, [r1]
	ldrh r0, [r3, 0x6]
	strh r0, [r1, 0x2]
	movs r3, 0
	ldrsh r0, [r2, r3]
	str r0, [r1, 0x4]
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	str r0, [r1, 0x8]
	ldr r0, _0807504C
	lsls r2, r5, 2
	adds r2, r0
	movs r5, 0
	ldrsh r0, [r2, r5]
	ldr r3, [r6]
	muls r0, r3
	str r0, [r1, 0x10]
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	muls r0, r3
	str r0, [r1, 0x14]
	adds r0, r4, 0
	bl sub_8075050
_08075040:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08075048: .4byte gUnknown_202F378
_0807504C: .4byte gUnknown_80F4D44
	thumb_func_end sub_8074FB0

	thumb_func_start sub_8075050
sub_8075050:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	adds r6, r1, 0
	ldr r0, _08075070
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08075078
	ldr r1, _08075074
	movs r0, 0x2
	b _0807507C
	.align 2, 0
_08075070: .4byte gUnknown_203B46C
_08075074: .4byte gUnknown_202F378
_08075078:
	ldr r1, _080750D0
	movs r0, 0x1
_0807507C:
	str r0, [r1]
	movs r1, 0xFA
	lsls r1, 1
	add r1, r9
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	bne _080750D4
	ldr r0, _080750D0
	ldr r1, [r0]
	lsls r1, 1
	movs r0, 0x18
	bl __divsi3
	movs r1, 0xCE
	lsls r1, 1
	add r1, r9
	strh r0, [r1]
	movs r2, 0xCA
	lsls r2, 1
	add r2, r9
	ldr r1, [r2]
	lsls r1, 1
	str r1, [r2]
	movs r2, 0xCC
	lsls r2, 1
	add r2, r9
	ldr r1, [r2]
	lsls r1, 1
	str r1, [r2]
	strh r0, [r6, 0x18]
	ldr r0, [r6, 0x10]
	lsls r0, 1
	str r0, [r6, 0x10]
	ldr r0, [r6, 0x14]
	lsls r0, 1
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_080750D0: .4byte gUnknown_202F378
_080750D4:
	cmp r0, 0x3
	bne _08075160
	ldr r1, [r6, 0x10]
	str r1, [sp]
	ldr r0, [r6, 0x14]
	str r0, [sp, 0x4]
	movs r4, 0xCE
	lsls r4, 1
	add r4, r9
	movs r5, 0
	movs r7, 0x1
_080750EA:
	ldr r1, _0807515C
	ldr r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	movs r0, 0x18
	bl __divsi3
	strh r0, [r4]
	movs r3, 0xCA
	lsls r3, 1
	add r3, r9
	adds r3, r5
	ldr r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r3]
	movs r2, 0xCC
	lsls r2, 1
	add r2, r9
	adds r2, r5
	ldr r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r2]
	ldr r0, [r3]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r3]
	ldr r0, [r2]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r2]
	adds r4, 0x1C
	adds r5, 0x1C
	subs r7, 0x1
	cmp r7, 0
	bge _080750EA
	ldr r1, _0807515C
	ldr r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
	ldr r1, [sp]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r6, 0x10]
	ldr r1, [sp, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_0807515C: .4byte gUnknown_202F378
_08075160:
	cmp r0, 0x4
	bne _080751EC
	ldr r0, [r6, 0x10]
	str r0, [sp]
	ldr r1, [r6, 0x14]
	str r1, [sp, 0x4]
	movs r7, 0xCE
	lsls r7, 1
	add r7, r9
	movs r0, 0
	mov r8, r0
	movs r1, 0x2
	mov r10, r1
_0807517A:
	ldr r0, _080751E8
	ldr r1, [r0]
	lsls r1, 2
	movs r0, 0x18
	bl __divsi3
	strh r0, [r7]
	movs r4, 0xCA
	lsls r4, 1
	add r4, r9
	add r4, r8
	ldr r0, [r4]
	lsls r0, 2
	str r0, [r4]
	movs r5, 0xCC
	lsls r5, 1
	add r5, r9
	add r5, r8
	ldr r0, [r5]
	lsls r0, 2
	str r0, [r5]
	ldr r0, [r4]
	movs r1, 0x3
	bl __divsi3
	str r0, [r4]
	ldr r0, [r5]
	movs r1, 0x3
	bl __divsi3
	str r0, [r5]
	adds r7, 0x1C
	movs r1, 0x1C
	add r8, r1
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r1, r10
	cmp r1, 0
	bge _0807517A
	ldr r0, _080751E8
	ldr r1, [r0]
	lsls r1, 2
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
	ldr r1, [sp]
	lsls r0, r1, 2
	str r0, [r6, 0x10]
	ldr r1, [sp, 0x4]
	lsls r0, r1, 2
	str r0, [r6, 0x14]
	b _080751F8
	.align 2, 0
_080751E8: .4byte gUnknown_202F378
_080751EC:
	ldr r0, _08075208
	ldr r1, [r0]
	movs r0, 0x18
	bl __divsi3
	strh r0, [r6, 0x18]
_080751F8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075208: .4byte gUnknown_202F378
	thumb_func_end sub_8075050

	thumb_func_start sub_807520C
sub_807520C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	movs r7, 0
	movs r0, 0
	mov r9, r0
	ldr r0, _08075238
	mov r1, r9
	strb r1, [r0]
	ldr r0, _0807523C
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08075244
	ldr r1, _08075240
	movs r0, 0x2
	b _08075248
	.align 2, 0
_08075238: .4byte gUnknown_202F32D
_0807523C: .4byte gUnknown_203B46C
_08075240: .4byte gUnknown_202F378
_08075244:
	ldr r1, _080752D0
	movs r0, 0x1
_08075248:
	str r0, [r1]
	movs r2, 0
	mov r8, r2
_0807524E:
	ldr r0, _080752D4
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, 2
	ldr r4, _080752D8
	adds r0, r4
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807534C
	ldr r4, [r5, 0x70]
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r4, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	cmp r2, 0
	bne _080752E0
	ldr r0, _080752DC
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0807534C
	strb r2, [r1]
	movs r1, 0xB6
	lsls r1, 1
	adds r6, r4, r1
	ldr r1, [r6]
	cmp r1, 0
	beq _0807534C
	ldr r0, [r5, 0x4]
	cmp r1, r0
	beq _0807534C
	adds r0, r5, 0
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _080752B2
	adds r0, r5, 0
	bl CannotAct
	lsls r0, 24
	cmp r0, 0
	bne _0807534C
_080752B2:
	adds r0, r5, 0x4
	adds r1, r6, 0
	bl sub_80983D8
	adds r1, r0, 0
	adds r0, r4, 0
	adds r0, 0x46
	ldrb r0, [r0]
	cmp r1, r0
	beq _0807534C
	adds r0, r5, 0
	bl sub_806CE68
	b _0807534C
	.align 2, 0
_080752D0: .4byte gUnknown_202F378
_080752D4: .4byte gDungeonGlobalData
_080752D8: .4byte 0x000135cc
_080752DC: .4byte 0x00000147
_080752E0:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 6
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r4]
	movs r3, 0xC4
	lsls r3, 1
	adds r0, r4, r3
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [sp]
	movs r2, 0xC6
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r3, 0x80
	lsls r3, 5
	adds r0, r3
	str r0, [sp, 0x4]
	adds r0, r5, 0
	mov r1, sp
	bl sub_804535C
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r0, r5, 0
	movs r1, 0
	bl sub_806CDFC
	movs r2, 0xFB
	lsls r2, 1
	adds r0, r4, r2
	movs r3, 0
	strh r3, [r0]
	movs r7, 0x1
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0807534C
	movs r4, 0x1
	mov r9, r4
_0807534C:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x13
	bgt _08075358
	b _0807524E
_08075358:
	cmp r7, 0
	bne _08075360
	movs r0, 0
	b _0807566C
_08075360:
	ldr r0, _08075390
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xB8
	ldr r2, [r1]
	str r2, [sp, 0x10]
	mov r3, r10
	str r3, [r1]
	ldr r4, _08075394
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807537C
	b _080754AE
_0807537C:
	mov r0, r9
	cmp r0, 0
	bne _08075384
	b _080754AE
_08075384:
	movs r0, 0x35
	bl sub_80526D0
	movs r5, 0
	b _0807549E
	.align 2, 0
_08075390: .4byte gDungeonGlobalData
_08075394: .4byte 0x0000066c
_08075398:
	movs r0, 0x7
	bl sub_803E46C
	movs r1, 0
	mov r8, r1
	adds r5, 0x1
	mov r9, r5
_080753A6:
	ldr r0, _08075420
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, _08075424
	adds r0, r3
	adds r0, r1
	ldr r3, [r0]
	adds r0, r3, 0
	str r3, [sp, 0x14]
	bl EntityExists
	lsls r0, 24
	ldr r3, [sp, 0x14]
	cmp r0, 0
	beq _08075492
	ldr r0, [r3, 0x70]
	adds r7, r0, 0
	movs r4, 0xFB
	lsls r4, 1
	adds r5, r7, r4
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	movs r2, 0xC2
	lsls r2, 1
	adds r1, r2
	adds r4, r7, r1
	movs r0, 0xFA
	lsls r0, 1
	adds r6, r7, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _08075492
	ldr r1, [r4, 0x10]
	ldr r2, [r4, 0x14]
	adds r0, r3, 0
	bl sub_804539C
	ldrh r0, [r4, 0x18]
	subs r0, 0x1
	strh r0, [r4, 0x18]
	lsls r0, 16
	asrs r2, r0, 16
	ldr r3, [sp, 0x14]
	cmp r2, 0
	bne _08075492
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	movs r4, 0
	ldrsh r1, [r6, r4]
	cmp r0, r1
	bne _08075428
	strh r2, [r6]
	b _08075492
	.align 2, 0
_08075420: .4byte gDungeonGlobalData
_08075424: .4byte 0x000135cc
_08075428:
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	movs r2, 0xC4
	lsls r2, 1
	adds r1, r7, r2
	adds r1, r0
	ldr r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r4, 0xC0
	lsls r4, 4
	adds r0, r4
	str r0, [sp, 0x8]
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r1, r7, r2
	adds r1, r0
	ldr r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r4, 0x80
	lsls r4, 5
	adds r0, r4
	add r1, sp, 0x8
	str r0, [r1, 0x4]
	adds r0, r3, 0
	str r3, [sp, 0x14]
	bl sub_804535C
	movs r0, 0
	ldrsh r1, [r5, r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	movs r2, 0xC8
	lsls r2, 1
	adds r1, r7, r2
	adds r1, r0
	ldr r2, [r1]
	ldr r3, [sp, 0x14]
	adds r0, r3, 0
	movs r1, 0
	bl sub_806CDFC
_08075492:
	movs r3, 0x1
	add r8, r3
	mov r4, r8
	cmp r4, 0x13
	ble _080753A6
	mov r5, r9
_0807549E:
	ldr r0, _08075510
	ldr r1, [r0]
	movs r0, 0x18
	bl __divsi3
	cmp r5, r0
	bge _080754AE
	b _08075398
_080754AE:
	movs r0, 0
	mov r8, r0
_080754B2:
	ldr r0, _08075514
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	ldr r3, _08075518
	adds r0, r3
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080754F6
	ldr r4, [r5, 0x70]
	movs r0, 0xFA
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	strh r0, [r1]
	adds r0, r5, 0
	bl nullsub_97
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 6
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080754F6
	adds r0, r5, 0
	movs r1, 0
	bl sub_804535C
_080754F6:
	movs r3, 0x1
	add r8, r3
	mov r4, r8
	cmp r4, 0x13
	ble _080754B2
	bl sub_807AA30
	movs r7, 0
_08075506:
	movs r5, 0
	adds r0, r7, 0x1
	mov r8, r0
	b _08075600
	.align 2, 0
_08075510: .4byte gUnknown_202F378
_08075514: .4byte gDungeonGlobalData
_08075518: .4byte 0x000135cc
_0807551C:
	ldr r2, [r4, 0x70]
	cmp r7, 0
	bne _0807552A
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _080755FE
	b _08075530
_0807552A:
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	bne _080755FE
_08075530:
	ldr r6, [r4, 0x4]
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 6
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080755BC
	ldr r3, _08075560
	adds r0, r3, 0
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _08075564
	adds r0, r4, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
	bl sub_805EE30
	b _0807556A
	.align 2, 0
_08075560: .4byte 0x0000dfff
_08075564:
	adds r0, r4, 0
	bl sub_8075708
_0807556A:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	movs r0, 0
	bl sub_8043ED0
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	adds r0, r4, 0
	bl sub_8071DA4
	bl sub_8046D20
	ldr r0, _08075650
	ldr r0, [r0]
	ldr r1, _08075654
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8075900
_080755BC:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	ldr r0, [r4, 0x4]
	cmp r6, r0
	beq _080755DE
	ldr r1, _08075658
	movs r0, 0x1
	strb r0, [r1]
_080755DE:
	adds r0, r4, 0
	bl sub_806A5B8
	adds r1, r4, 0x4
	adds r0, r4, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_080755FE:
	adds r5, 0x1
_08075600:
	cmp r5, 0x13
	bgt _0807562A
	ldr r0, _08075650
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0807565C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080755FE
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807562A
	b _0807551C
_0807562A:
	mov r7, r8
	cmp r7, 0x1
	bgt _08075632
	b _08075506
_08075632:
	bl sub_8086AC0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _08075660
	bl sub_8085140
	ldr r0, _08075650
	ldr r0, [r0]
	adds r0, 0xB8
	ldr r3, [sp, 0x10]
	str r3, [r0]
	b _0807566A
	.align 2, 0
_08075650: .4byte gDungeonGlobalData
_08075654: .4byte 0x00003a08
_08075658: .4byte gUnknown_202F32D
_0807565C: .4byte 0x000135cc
_08075660:
	ldr r0, _0807567C
	ldr r0, [r0]
	adds r0, 0xB8
	ldr r4, [sp, 0x10]
	str r4, [r0]
_0807566A:
	movs r0, 0x1
_0807566C:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807567C: .4byte gDungeonGlobalData
	thumb_func_end sub_807520C

	thumb_func_start sub_8075680
sub_8075680:
	push {r4-r7,lr}
	movs r7, 0
_08075684:
	ldr r0, _080756FC
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08075700
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080756EE
	ldr r6, [r5, 0x70]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _080756EE
	movs r0, 0xB6
	lsls r0, 1
	adds r4, r6, r0
	ldr r1, [r4]
	cmp r1, 0
	beq _080756EE
	ldr r0, [r5, 0x4]
	cmp r1, r0
	beq _080756EE
	adds r0, r5, 0
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	bne _080756EE
	adds r0, r5, 0x4
	adds r1, r4, 0
	bl sub_80983D8
	adds r4, r0, 0
	movs r1, 0x7
	ands r0, r1
	adds r1, r6, 0
	adds r1, 0x46
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	adds r2, r4, 0
	bl sub_806CDD4
_080756EE:
	adds r7, 0x1
	cmp r7, 0x13
	ble _08075684
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080756FC: .4byte gDungeonGlobalData
_08075700: .4byte 0x000135cc
	thumb_func_end sub_8075680

	thumb_func_start nullsub_97
nullsub_97:
	bx lr
	thumb_func_end nullsub_97

	thumb_func_start sub_8075708
sub_8075708:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	ldr r6, [r4, 0x70]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807580C
	adds r0, r4, 0
	bl sub_8045128
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08075752
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08075752
	adds r0, r4, 0
	movs r1, 0x9
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _08075752
	adds r0, r4, 0x4
	bl sub_804AE84
_08075752:
	ldr r5, [r5, 0x14]
	cmp r5, 0
	beq _0807580C
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x5
	bhi _0807580C
	lsls r0, 2
	ldr r1, _0807576C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807576C: .4byte _08075770
	.align 2, 0
_08075770:
	.4byte _0807580C
	.4byte _0807580C
	.4byte _08075788
	.4byte _08075806
	.4byte _0807580C
	.4byte _0807580C
_08075788:
	adds r0, r5, 0
	bl sub_8045104
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	mov r9, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _080757BA
	adds r1, r5, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _080757BA
	movs r0, 0x1
	strb r0, [r1]
	bl sub_8049ED4
	movs r0, 0x1
	mov r9, r0
_080757BA:
	ldrb r0, [r7, 0x1]
	cmp r0, 0
	bne _080757D2
	adds r0, r5, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080757EC
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _080757EC
	b _080757F2
_080757D2:
	cmp r0, 0x1
	bne _080757DE
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _080757EC
	b _080757F2
_080757DE:
	cmp r0, 0x2
	bne _080757EC
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _080757EC
	movs r0, 0x1
	mov r8, r0
_080757EC:
	mov r0, r8
	cmp r0, 0
	beq _0807580C
_080757F2:
	mov r0, r9
	cmp r0, 0
	bne _0807580C
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_807FE9C
	b _0807580C
_08075806:
	adds r0, r4, 0
	bl sub_8073D14
_0807580C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8075708

	thumb_func_start sub_8075818
sub_8075818:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, [r4, 0x70]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080758F6
	adds r0, r4, 0
	bl sub_8045128
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08075848
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080758F2
_08075848:
	ldr r4, [r5, 0x14]
	cmp r4, 0
	beq _080758F6
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x5
	bhi _080758F6
	lsls r0, 2
	ldr r1, _08075864
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08075864: .4byte _08075868
	.align 2, 0
_08075868:
	.4byte _080758F6
	.4byte _080758F6
	.4byte _08075880
	.4byte _080758BE
	.4byte _080758F6
	.4byte _080758F6
_08075880:
	adds r0, r4, 0
	bl sub_8045104
	movs r1, 0
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _080758A0
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080758B8
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _080758B8
	b _080758F2
_080758A0:
	cmp r0, 0x1
	bne _080758AC
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _080758B8
	b _080758F2
_080758AC:
	cmp r0, 0x2
	bne _080758B8
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _080758B8
	movs r1, 0x1
_080758B8:
	cmp r1, 0
	beq _080758F6
	b _080758F2
_080758BE:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _080758F6
	adds r0, r6, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080758F6
	ldrh r1, [r5]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080758E2
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _080758F6
_080758E2:
	adds r0, r4, 0
	bl sub_8045108
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080758F6
_080758F2:
	movs r0, 0x1
	b _080758F8
_080758F6:
	movs r0, 0
_080758F8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8075818

	thumb_func_start sub_8075900
sub_8075900:
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807597A
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0807597A
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807597A
	ldr r5, _08075980
	ldr r0, [r5]
	ldr r1, _08075984
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807597A
	adds r0, r4, 0
	bl sub_8045128
	ldrh r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0807597A
	bl sub_8083600
	ldr r1, _08075988
	ldr r1, [r1]
	bl SendMessage
	ldr r0, [r5]
	ldr r1, _0807598C
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_807AB38
	movs r0, 0
	bl sub_8041888
	adds r0, r4, 0x4
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0807597A
	movs r0, 0x78
	movs r1, 0x39
	bl sub_803E708
_0807597A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08075980: .4byte gDungeonGlobalData
_08075984: .4byte 0x00000671
_08075988: .4byte gUnknown_80FE308
_0807598C: .4byte 0x00000672
	thumb_func_end sub_8075900
