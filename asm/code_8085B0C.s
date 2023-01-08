	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8085B4C
sub_8085B4C:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, _08085B7C
	str r3, [r0]
	cmp r3, 0
	ble _08085B76
	movs r6, 0x1
	adds r4, r1, 0
	adds r1, r5, 0
_08085B5E:
	strb r6, [r1]
	ldm r2!, {r0}
	str r0, [r1, 0x4]
	ldm r4!, {r0}
	str r0, [r1, 0xC]
	movs r5, 0x4
	ldrsh r0, [r0, r5]
	str r0, [r1, 0x8]
	adds r1, 0x10
	subs r3, 0x1
	cmp r3, 0
	bne _08085B5E
_08085B76:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085B7C: .4byte gUnknown_202F3D8
	thumb_func_end sub_8085B4C

	thumb_func_start sub_8085B80
sub_8085B80:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r1, r0, 0
	movs r0, 0
	mov r8, r0
	movs r7, 0
	ldr r0, _08085BE4
	ldr r0, [r0]
	cmp r8, r0
	bge _08085C3E
	adds r5, r1, 0
_08085B98:
	ldr r6, [r5, 0x4]
	ldr r2, [r6, 0x70]
	adds r3, r2, 0
	ldr r4, [r5, 0xC]
	ldrb r0, [r5]
	cmp r0, 0
	beq _08085C32
	movs r1, 0x1
	mov r8, r1
	ldr r0, [r5, 0x8]
	cmp r0, 0
	bne _08085C08
	adds r4, 0x8
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08085BE8
	strb r0, [r5]
	ldrb r1, [r4]
	movs r0, 0x7
	ands r0, r1
	adds r1, r2, 0
	adds r1, 0x46
	strb r0, [r1]
	movs r3, 0
	ldrsh r2, [r4, r3]
	adds r0, r6, 0
	movs r1, 0x7
	bl sub_806CDD4
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r3, 0xC
	ldrsh r2, [r4, r3]
	adds r0, r6, 0
	bl sub_80856C8
	b _08085C32
	.align 2, 0
_08085BE4: .4byte gUnknown_202F3D8
_08085BE8:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	str r0, [r5, 0x8]
	str r4, [r5, 0xC]
	ldrb r1, [r4]
	movs r0, 0x7
	ands r0, r1
	adds r1, r3, 0
	adds r1, 0x46
	strb r0, [r1]
	movs r3, 0
	ldrsh r2, [r4, r3]
	adds r0, r6, 0
	movs r1, 0
	bl sub_806CDD4
_08085C08:
	ldr r0, [r5, 0x8]
	subs r0, 0x1
	str r0, [r5, 0x8]
	ldr r1, _08085C4C
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	muls r1, r2
	lsls r1, 8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	muls r2, r0
	lsls r2, 8
	adds r0, r6, 0
	bl sub_804539C
_08085C32:
	adds r5, 0x10
	adds r7, 0x1
	ldr r0, _08085C50
	ldr r0, [r0]
	cmp r7, r0
	blt _08085B98
_08085C3E:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08085C4C: .4byte gAdjacentTileOffsets
_08085C50: .4byte gUnknown_202F3D8
	thumb_func_end sub_8085B80

	thumb_func_start SetDungeonBGColorRGB
SetDungeonBGColorRGB:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	str r0, [sp, 0x14]
	mov r10, r1
	mov r9, r2
	ldr r4, [sp, 0x48]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	bl sub_8085E98
	movs r0, 0
	mov r8, r0
	ldr r0, _08085E70
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	cmp r4, 0
	beq _08085CAE
	ldr r1, [sp, 0x14]
	cmp r1, 0
	blt _08085C92
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	str r0, [sp, 0x14]
_08085C92:
	mov r2, r10
	cmp r2, 0
	blt _08085CA0
	lsrs r0, r2, 31
	add r0, r10
	asrs r0, 1
	mov r10, r0
_08085CA0:
	mov r3, r9
	cmp r3, 0
	blt _08085CAE
	lsrs r0, r3, 31
	add r0, r9
	asrs r0, 1
	mov r9, r0
_08085CAE:
	ldr r1, _08085E74
	ldr r0, [sp, 0x8]
	ands r0, r1
	ldr r1, _08085E78
	ands r0, r1
	ldr r1, _08085E7C
	ands r0, r1
	str r0, [sp, 0x8]
	ldr r0, _08085E80
	ldr r2, [r0]
	ldr r0, _08085E84
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	mov r0, r8
	add r1, sp, 0x8
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
	ldr r2, [sp, 0x14]
	lsls r2, 16
	str r2, [sp, 0x1C]
	mov r3, r10
	lsls r3, 16
	str r3, [sp, 0x20]
	mov r0, r9
	lsls r0, 16
	str r0, [sp, 0x24]
	add r7, sp, 0xC
	movs r1, 0xA0
	cmp r1, 0x1
	ble _08085D56
	add r6, sp, 0x8
	movs r4, 0xA0
	subs r4, 0x1
_08085CFA:
	ldrb r0, [r5]
	ldr r3, [sp, 0x14]
	adds r2, r0, r3
	ldrb r0, [r5, 0x1]
	mov r3, r10
	adds r1, r0, r3
	ldrb r0, [r5, 0x2]
	add r0, r9
	cmp r2, 0xFF
	ble _08085D10
	movs r2, 0xFF
_08085D10:
	cmp r1, 0xFF
	ble _08085D16
	movs r1, 0xFF
_08085D16:
	cmp r0, 0xFF
	ble _08085D1C
	movs r0, 0xFF
_08085D1C:
	cmp r2, 0
	bge _08085D22
	movs r2, 0
_08085D22:
	cmp r1, 0
	bge _08085D28
	movs r1, 0
_08085D28:
	cmp r0, 0
	bge _08085D2E
	movs r0, 0
_08085D2E:
	strb r2, [r6]
	strb r1, [r6, 0x1]
	strb r0, [r6, 0x2]
	ldr r0, _08085E80
	ldr r2, [r0]
	ldr r0, _08085E84
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	mov r0, r8
	add r1, sp, 0x8
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
	subs r4, 0x1
	cmp r4, 0
	bne _08085CFA
_08085D56:
	ldr r2, _08085E88
	ldr r3, [sp, 0x1C]
	lsrs r0, r3, 16
	ldr r1, [sp, 0x20]
	orrs r0, r1
	str r0, [sp, 0xC]
	ldr r3, [sp, 0x24]
	lsrs r1, r3, 16
	ldr r0, [r7, 0x4]
	ands r0, r2
	orrs r0, r1
	str r0, [r7, 0x4]
	ldr r0, _08085E8C
	ldr r1, _08085E80
	ldr r3, [r1]
	ldr r1, _08085E84
	ldr r1, [r1]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	str r1, [sp]
	str r7, [sp, 0x4]
	movs r1, 0xA0
	movs r2, 0x20
	bl sub_8004C00
	movs r3, 0x20
	add r8, r3
	ldr r5, _08085E90
	add r6, sp, 0x8
	movs r4, 0x20
_08085D94:
	ldrb r0, [r5]
	ldr r1, [sp, 0x14]
	adds r2, r0, r1
	ldrb r0, [r5, 0x1]
	mov r3, r10
	adds r1, r0, r3
	ldrb r0, [r5, 0x2]
	add r0, r9
	cmp r2, 0xFF
	ble _08085DAA
	movs r2, 0xFF
_08085DAA:
	cmp r1, 0xFF
	ble _08085DB0
	movs r1, 0xFF
_08085DB0:
	cmp r0, 0xFF
	ble _08085DB6
	movs r0, 0xFF
_08085DB6:
	cmp r2, 0
	bge _08085DBC
	movs r2, 0
_08085DBC:
	cmp r1, 0
	bge _08085DC2
	movs r1, 0
_08085DC2:
	cmp r0, 0
	bge _08085DC8
	movs r0, 0
_08085DC8:
	strb r2, [r6]
	strb r1, [r6, 0x1]
	strb r0, [r6, 0x2]
	ldr r0, _08085E80
	ldr r2, [r0]
	ldr r7, _08085E84
	ldr r3, [r7]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	mov r0, r8
	add r1, sp, 0x8
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
	subs r4, 0x1
	cmp r4, 0
	bne _08085D94
	ldr r2, [sp, 0x18]
	cmp r2, 0
	beq _08085E5E
	ldr r0, [r7]
	ldr r3, _08085E94
	adds r0, r3
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r0, 0x80
	lsls r0, 1
	mov r8, r0
	add r6, sp, 0x8
	movs r4, 0xD0
_08085E0A:
	ldrb r0, [r5]
	ldr r1, [sp, 0x14]
	adds r2, r0, r1
	ldrb r0, [r5, 0x1]
	mov r3, r10
	adds r1, r0, r3
	ldrb r0, [r5, 0x2]
	add r0, r9
	cmp r2, 0xFF
	ble _08085E20
	movs r2, 0xFF
_08085E20:
	cmp r1, 0xFF
	ble _08085E26
	movs r1, 0xFF
_08085E26:
	cmp r0, 0xFF
	ble _08085E2C
	movs r0, 0xFF
_08085E2C:
	cmp r2, 0
	bge _08085E32
	movs r2, 0
_08085E32:
	cmp r1, 0
	bge _08085E38
	movs r1, 0
_08085E38:
	cmp r0, 0
	bge _08085E3E
	movs r0, 0
_08085E3E:
	strb r2, [r6]
	strb r1, [r6, 0x1]
	strb r0, [r6, 0x2]
	ldr r0, _08085E80
	ldr r2, [r0]
	mov r0, r8
	add r1, sp, 0x8
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r0, 0x1
	add r8, r0
	subs r4, 0x1
	cmp r4, 0
	bne _08085E0A
_08085E5E:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085E70: .4byte gDungeonPaletteFile
_08085E74: .4byte 0xffffff00
_08085E78: .4byte 0xffff00ff
_08085E7C: .4byte 0xff00ffff
_08085E80: .4byte gUnknown_202EDC8
_08085E84: .4byte gDungeon
_08085E88: .4byte 0xffff0000
_08085E8C: .4byte gUnknown_202EE8C
_08085E90: .4byte gUnknown_202ECA4
_08085E94: .4byte 0x000181e4
	thumb_func_end SetDungeonBGColorRGB

	thumb_func_start sub_8085E98
sub_8085E98:
	ldr r0, _08085EA8
	ldr r0, [r0]
	ldr r1, _08085EAC
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bx lr
	.align 2, 0
_08085EA8: .4byte gDungeon
_08085EAC: .4byte 0x00018215
	thumb_func_end sub_8085E98

	thumb_func_start sub_8085EB0
sub_8085EB0:
	ldr r0, _08085EC0
	ldr r0, [r0]
	ldr r1, _08085EC4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08085EC0: .4byte gDungeon
_08085EC4: .4byte 0x00018215
	thumb_func_end sub_8085EB0

	thumb_func_start sub_8085EC8
sub_8085EC8:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x28
	adds r4, r0, 0
	mov r8, r1
	mov r9, r2
	adds r6, r3, 0
	ldr r5, [sp, 0x40]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	bl sub_800EE5C
	bl sub_800EF64
	movs r0, 0x46
	bl sub_803E46C
	str r4, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	mov r1, sp
	ldrh r0, [r6]
	movs r2, 0
	strh r0, [r1, 0xC]
	ldrh r0, [r6, 0x2]
	strh r0, [r1, 0xE]
	mov r0, sp
	strh r2, [r0, 0x10]
	strh r2, [r0, 0x12]
	ldr r0, _08085F3C
	str r0, [sp, 0x18]
	add r1, sp, 0x1C
	ldr r0, _08085F40
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	mov r0, sp
	bl sub_800E890
	cmp r5, 0
	beq _08085F2E
	bl sub_8085F44
	movs r0, 0x1
	negs r0, r0
_08085F2E:
	add sp, 0x28
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08085F3C: .4byte 0x0000ffff
_08085F40: .4byte gUnknown_8107374
	thumb_func_end sub_8085EC8

	thumb_func_start sub_8085F44
sub_8085F44:
	push {r4,lr}
	adds r4, r0, 0
	b _08085F5C
_08085F4A:
	ldr r0, _08085F70
	ldr r0, [r0]
	ldr r1, _08085F74
	adds r0, r1
	bl sub_800E90C
	movs r0, 0x46
	bl sub_803E46C
_08085F5C:
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08085F4A
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085F70: .4byte gDungeon
_08085F74: .4byte 0x000181f0
	thumb_func_end sub_8085F44

	thumb_func_start sub_8085F78
sub_8085F78:
	push {lr}
	ldr r0, _08085F94
	ldr r0, [r0]
	ldr r1, _08085F98
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3C
	bls _08085F8A
	b _080860A4
_08085F8A:
	lsls r0, 2
	ldr r1, _08085F9C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08085F94: .4byte gDungeon
_08085F98: .4byte 0x00003a0d
_08085F9C: .4byte _08085FA0
	.align 2, 0
_08085FA0:
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _08086094
	.4byte _08086094
	.4byte _08086094
	.4byte _0808609A
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A0
	.4byte _080860A0
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
_08086094:
	bl sub_8088848
	b _080860A4
_0808609A:
	bl sub_8088EE8
	b _080860A4
_080860A0:
	bl sub_808A718
_080860A4:
	pop {r0}
	bx r0
	thumb_func_end sub_8085F78

	thumb_func_start sub_80860A8
sub_80860A8:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r0, _08086108
	ldr r2, [r0]
	movs r3, 0x1
_080860B6:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080860C6
	ldrb r0, [r2, 0x2]
	cmp r0, r6
	beq _08086104
_080860C6:
	adds r2, 0x4
	adds r5, 0x1
	cmp r5, 0x13
	ble _080860B6
	movs r5, 0
_080860D0:
	ldr r0, _0808610C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08086110
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08086114
	ldr r2, [r4, 0x70]
	adds r0, r2, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08086114
	adds r0, r2, 0
	adds r0, 0x62
	ldrb r0, [r0]
	cmp r0, r6
	bne _08086114
_08086104:
	movs r0, 0x1
	b _0808611C
	.align 2, 0
_08086108: .4byte gTeamInventory_203B460
_0808610C: .4byte gDungeon
_08086110: .4byte 0x0001357c
_08086114:
	adds r5, 0x1
	cmp r5, 0x3
	ble _080860D0
	movs r0, 0
_0808611C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80860A8

	thumb_func_start sub_8086124
sub_8086124:
	ldr r0, [r0, 0x70]
	movs r2, 0xB0
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_8086124

	thumb_func_start sub_8086130
sub_8086130:
	push {lr}
	movs r0, 0x3C
	bl DungeonFadeOutBGM
	movs r0, 0x3C
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _08086194
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _08086198
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808619C
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _080861A0
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _080861A4
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	pop {r0}
	bx r0
	.align 2, 0
_08086194: .4byte gUnknown_810665C
_08086198: .4byte gUnknown_810668C
_0808619C: .4byte gUnknown_81066D4
_080861A0: .4byte gUnknown_81066F0
_080861A4: .4byte gUnknown_810671C
	thumb_func_end sub_8086130

	thumb_func_start sub_80861A8
sub_80861A8:
	push {lr}
	movs r1, 0
	movs r2, 0x8
	bl sub_806CDD4
	pop {r0}
	bx r0
	thumb_func_end sub_80861A8

	thumb_func_start sub_80861B8
sub_80861B8:
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, [r0, 0x70]
	adds r1, r4, 0
	bl sub_806CDD4
	adds r5, 0xFE
	strb r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80861B8

	thumb_func_start sub_80861D4
sub_80861D4:
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	bl sub_806CDD4
	adds r0, r4, 0
	bl sub_80861EC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80861D4

	thumb_func_start sub_80861EC
sub_80861EC:
	ldr r0, [r0, 0x70]
	adds r0, 0xFE
	movs r1, 0x63
	strb r1, [r0]
	bx lr
	thumb_func_end sub_80861EC

	thumb_func_start sub_80861F8
sub_80861F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	adds r6, r1, 0
	lsls r0, 16
	asrs r0, 16
	adds r5, r0, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	bl sub_800EE5C
	bl sub_800EF64
	movs r0, 0x46
	bl sub_803E46C
	ldr r0, [r6, 0x70]
	mov r8, r0
	movs r1, 0
	mov r9, r1
	str r1, [sp, 0x28]
	adds r0, r5, 0
	bl sub_800E700
	adds r7, r0, 0
	add r4, sp, 0x28
	movs r2, 0x1
	negs r2, r2
	cmp r7, r2
	beq _0808624A
	adds r1, r6, 0
	adds r1, 0x28
	lsls r2, r7, 24
	lsrs r2, 24
	adds r0, r4, 0
	bl sub_800569C
_0808624A:
	str r5, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	mov r0, r8
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	mov r1, sp
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08086262
	adds r0, 0xFF
_08086262:
	asrs r0, 8
	strh r0, [r1, 0xC]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _08086270
	adds r0, 0xFF
_08086270:
	asrs r0, 8
	strh r0, [r1, 0xE]
	mov r1, sp
	ldrh r0, [r4]
	strh r0, [r1, 0x10]
	add r0, sp, 0x28
	ldrh r0, [r0, 0x2]
	strh r0, [r1, 0x12]
	str r7, [sp, 0x14]
	ldr r0, _080862B4
	str r0, [sp, 0x18]
	add r1, sp, 0x1C
	ldr r0, _080862B8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	mov r0, sp
	bl sub_800E890
	mov r4, r10
	cmp r4, 0
	beq _080862A2
	bl sub_8085F44
	movs r0, 0x1
	negs r0, r0
_080862A2:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080862B4: .4byte 0x0000ffff
_080862B8: .4byte gUnknown_8107380
	thumb_func_end sub_80861F8

        .align 2,0
