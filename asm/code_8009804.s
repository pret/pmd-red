	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start vram_related_8009804
vram_related_8009804:
	push {lr}
	movs r1, 0xC0
	lsls r1, 19
	movs r0, 0
	ldr r3, _0800987C
	movs r2, 0
_08009810:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009810
	ldr r1, _08009880
	movs r0, 0
	ldr r3, _08009884
	movs r2, 0
_08009820:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009820
	ldr r1, _08009888
	movs r0, 0
	ldr r3, _0800988C
	movs r2, 0
_08009830:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009830
	ldr r1, _08009890
	movs r0, 0
	ldr r3, _08009894
	movs r2, 0
_08009840:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009840
	movs r1, 0xA0
	lsls r1, 19
	movs r0, 0
	movs r2, 0
_08009850:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, 0x77
	bls _08009850
	ldr r1, _08009898
	movs r0, 0
	movs r2, 0
_0800985E:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, 0x77
	bls _0800985E
	movs r1, 0xE0
	lsls r1, 19
	movs r0, 0
	ldr r2, _0800989C
_0800986E:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, 0xFF
	bls _0800986E
	pop {r0}
	bx r0
	.align 2, 0
_0800987C: .4byte 0x000013bf
_08009880: .4byte 0x06007000
_08009884: .4byte 0x000003ff
_08009888: .4byte 0x06008000
_0800988C: .4byte 0x00001fff
_08009890: .4byte 0x06010000
_08009894: .4byte 0x00001f7f
_08009898: .4byte 0x05000200
_0800989C: .4byte 0x00a000a0
	thumb_func_end vram_related_8009804

	thumb_func_start sub_80098A0
sub_80098A0:
	ldr r0, _080098B4
	movs r1, 0
	str r1, [r0]
	ldr r0, _080098B8
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strb r1, [r0, 0x2]
	strb r1, [r0, 0x3]
	bx lr
	.align 2, 0
_080098B4: .4byte gUnknown_202D23C
_080098B8: .4byte gUnknown_202D238
	thumb_func_end sub_80098A0

	thumb_func_start sub_80098BC
sub_80098BC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r7, _080098F0
	ldr r3, [r7]
	cmp r3, 0x7
	bgt _080098E8
	ldr r2, _080098F4
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r0, r1, r2
	str r4, [r0]
	adds r0, r2, 0x4
	adds r0, r1, r0
	str r5, [r0]
	adds r2, 0x8
	adds r1, r2
	str r6, [r1]
	adds r0, r3, 0x1
	str r0, [r7]
_080098E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080098F0: .4byte gUnknown_202D23C
_080098F4: .4byte gUnknown_202D240
	thumb_func_end sub_80098BC

	thumb_func_start sub_80098F8
sub_80098F8:
	ldr r1, _08009904
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08009904: .4byte gUnknown_202D238
	thumb_func_end sub_80098F8

	thumb_func_start sub_8009908
sub_8009908:
	push {r4-r7,lr}
	movs r5, 0
	ldr r0, _08009994
	ldr r0, [r0]
	cmp r5, r0
	bge _08009936
	ldr r4, _08009998
	adds r7, r4, 0
	movs r6, 0
_0800991A:
	ldr r0, [r4]
	adds r1, r7, 0x4
	adds r1, r6, r1
	ldr r1, [r1]
	ldr r2, [r4, 0x8]
	bl CpuCopy
	adds r4, 0xC
	adds r6, 0xC
	adds r5, 0x1
	ldr r0, _08009994
	ldr r0, [r0]
	cmp r5, r0
	blt _0800991A
_08009936:
	ldr r0, _08009994
	movs r5, 0
	str r5, [r0]
	ldr r4, _0800999C
	ldrb r0, [r4]
	cmp r0, 0
	beq _08009952
	strb r5, [r4]
	ldr r0, _080099A0
	ldr r1, _080099A4
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_08009952:
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08009966
	strb r5, [r4, 0x1]
	ldr r0, _080099A8
	ldr r1, _080099AC
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_08009966:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _0800997A
	strb r5, [r4, 0x2]
	ldr r0, _080099B0
	ldr r1, _080099B4
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_0800997A:
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _0800998E
	strb r5, [r4, 0x3]
	ldr r0, _080099B8
	ldr r1, _080099BC
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_0800998E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009994: .4byte gUnknown_202D23C
_08009998: .4byte gUnknown_202D240
_0800999C: .4byte gUnknown_202D238
_080099A0: .4byte 0x06006000
_080099A4: .4byte gUnknown_202B038
_080099A8: .4byte 0x06006800
_080099AC: .4byte gUnknown_202B838
_080099B0: .4byte 0x06007000
_080099B4: .4byte gUnknown_202C038
_080099B8: .4byte 0x06007800
_080099BC: .4byte gUnknown_202C838
	thumb_func_end sub_8009908

	thumb_func_start sub_80099C0
sub_80099C0:
	push {r4,r5,lr}
	ldr r0, _080099E4
	ldr r4, _080099E8
	movs r5, 0x80
	lsls r5, 4
	adds r1, r4, 0
	adds r2, r5, 0
	bl CpuCopy
	ldr r0, _080099EC
	adds r4, r5
	adds r1, r4, 0
	adds r2, r5, 0
	bl CpuCopy
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080099E4: .4byte 0x06006000
_080099E8: .4byte gUnknown_202B038
_080099EC: .4byte 0x06006800
	thumb_func_end sub_80099C0

	thumb_func_start sub_80099F0
sub_80099F0:
	push {lr}
	adds r2, r0, 0
	ldr r0, _08009A0C
	movs r1, 0x7
	movs r3, 0xE2
	lsls r3, 1
	adds r0, r3
_080099FE:
	str r2, [r0]
	subs r0, 0x40
	subs r1, 0x1
	cmp r1, 0
	bge _080099FE
	pop {r0}
	bx r0
	.align 2, 0
_08009A0C: .4byte gUnknown_202D038
	thumb_func_end sub_80099F0

	thumb_func_start sub_8009A10
sub_8009A10:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_8009A1C
	pop {r0}
	bx r0
	thumb_func_end sub_8009A10

	thumb_func_start sub_8009A1C
sub_8009A1C:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, _08009A30
	str r3, [r0]
	ldr r3, [r6, 0xC]
	movs r0, 0xC0
	lsls r0, 19
	adds r2, r0
	movs r5, 0
	b _08009A56
	.align 2, 0
_08009A30: .4byte gUnknown_202D2A0
_08009A34:
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	adds r5, 0x1
_08009A56:
	ldr r0, [r6, 0x8]
	cmp r5, r0
	ble _08009A34
	movs r5, 0
	lsls r4, r1, 6
_08009A60:
	adds r0, r5, 0
	adds r0, 0xE0
	ldr r1, [r6, 0x10]
	adds r1, r4
	bl SetBGPaletteBufferColorArray
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08009A60
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8009A1C

	thumb_func_start sub_8009A7C
sub_8009A7C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	adds r5, r1, 0
	str r2, [sp, 0x4]
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x38]
	ldr r3, [sp, 0x40]
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _08009AB4
	ldr r1, [r0]
	movs r2, 0
	str r2, [sp, 0x10]
	cmp r1, 0
	bne _08009AA8
	movs r7, 0x1
	str r7, [sp, 0x10]
_08009AA8:
	ldr r1, [sp]
	ldr r0, [r1]
	cmp r5, r0
	blt _08009AB8
	movs r0, 0
	b _08009BCE
	.align 2, 0
_08009AB4: .4byte gUnknown_202D2A0
_08009AB8:
	lsls r5, 2
	mov r8, r5
	cmp r4, 0
	beq _08009AFA
	movs r0, 0
	ldr r2, _08009B74
	mov r10, r2
	ldr r4, _08009B78
	mov r9, r4
	ldr r1, [sp, 0x10]
	lsls r7, r1, 1
_08009ACE:
	ldr r2, [sp, 0x10]
	adds r4, r0, 0x1
	mov r12, r4
	cmp r2, 0x1D
	bgt _08009AF4
	mov r6, r10
	mov r5, r9
	movs r4, 0
	lsls r0, 6
	adds r1, r7, r0
_08009AE2:
	ldr r0, [r5]
	lsls r0, 11
	adds r0, r1, r0
	adds r0, r6
	strh r4, [r0]
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x1D
	ble _08009AE2
_08009AF4:
	mov r0, r12
	cmp r0, 0x13
	ble _08009ACE
_08009AFA:
	ldr r7, [sp]
	ldr r0, [r7, 0x4]
	add r0, r8
	ldr r5, [r0]
	ldrh r0, [r5, 0x4]
	mov r9, r0
	ldrh r1, [r5, 0x6]
	str r1, [sp, 0xC]
	ldr r2, [sp, 0x3C]
	cmp r2, 0
	beq _08009B14
	ldrh r0, [r5, 0x8]
	str r0, [r2]
_08009B14:
	cmp r3, 0
	beq _08009B28
	ldrh r0, [r5, 0xA]
	strh r0, [r3]
	ldrh r0, [r5, 0xC]
	strh r0, [r3, 0x2]
	ldrh r0, [r5, 0xE]
	strh r0, [r3, 0x4]
	ldrh r0, [r5, 0x10]
	strh r0, [r3, 0x6]
_08009B28:
	adds r5, 0x14
	ldr r4, [sp, 0x8]
	str r4, [sp, 0x14]
	movs r6, 0
	movs r0, 0
	ldr r7, [sp, 0xC]
	cmp r0, r7
	bge _08009BC4
	cmp r4, 0x13
	bgt _08009BC4
_08009B3C:
	ldr r3, [sp, 0x4]
	adds r0, 0x1
	mov r12, r0
	ldr r0, [sp, 0x14]
	adds r0, 0x1
	mov r8, r0
	mov r1, r9
	cmp r1, 0
	beq _08009BB4
	ldr r2, _08009B74
	mov r10, r2
	mov r2, r9
_08009B54:
	cmp r6, 0
	bne _08009B80
	ldrh r1, [r5]
	adds r5, 0x2
	adds r0, r1, 0
	movs r4, 0xF0
	lsls r4, 8
	ands r0, r4
	cmp r0, 0
	bne _08009B6E
	ldr r6, _08009B7C
	ands r6, r1
	movs r1, 0
_08009B6E:
	adds r4, r1, 0
	b _08009B82
	.align 2, 0
_08009B74: .4byte gUnknown_202B038
_08009B78: .4byte gUnknown_202D2A0
_08009B7C: .4byte 0x000003ff
_08009B80:
	movs r4, 0
_08009B82:
	cmp r6, 0
	beq _08009B88
	subs r6, 0x1
_08009B88:
	ldr r7, [sp, 0x10]
	cmp r3, r7
	blt _08009BAC
	cmp r3, 0x1D
	bgt _08009BAC
	ldr r0, [sp, 0x14]
	cmp r0, 0
	blt _08009BAC
	lsls r0, r3, 1
	ldr r7, [sp, 0x14]
	lsls r1, r7, 6
	adds r0, r1
	ldr r7, _08009BE0
	ldr r1, [r7]
	lsls r1, 11
	adds r0, r1
	add r0, r10
	strh r4, [r0]
_08009BAC:
	subs r2, 0x1
	adds r3, 0x1
	cmp r2, 0
	bne _08009B54
_08009BB4:
	mov r0, r12
	mov r1, r8
	str r1, [sp, 0x14]
	ldr r2, [sp, 0xC]
	cmp r0, r2
	bge _08009BC4
	cmp r1, 0x13
	ble _08009B3C
_08009BC4:
	ldr r4, _08009BE0
	ldr r0, [r4]
	bl sub_80098F8
	movs r0, 0x1
_08009BCE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08009BE0: .4byte gUnknown_202D2A0
	thumb_func_end sub_8009A7C

	thumb_func_start sub_8009BE4
sub_8009BE4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0x20
	mov r12, r0
	ldr r0, _08009C54
	ldr r1, [r0]
	movs r2, 0
	mov r10, r2
	mov r9, r0
	cmp r1, 0
	bne _08009C04
	movs r7, 0x1
	mov r10, r7
_08009C04:
	movs r0, 0
	mov r1, r10
	lsls r1, 1
	mov r8, r1
_08009C0C:
	mov r1, r10
	adds r3, r0, 0x1
	cmp r1, r12
	bge _08009C36
	ldr r6, _08009C58
	ldr r5, _08009C54
	movs r4, 0
	lsls r0, 6
	mov r7, r8
	adds r2, r7, r0
	mov r0, r12
	subs r1, r0, r1
_08009C24:
	ldr r0, [r5]
	lsls r0, 11
	adds r0, r2, r0
	adds r0, r6
	strh r4, [r0]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _08009C24
_08009C36:
	adds r0, r3, 0
	cmp r0, 0x1F
	ble _08009C0C
	mov r1, r9
	ldr r0, [r1]
	bl sub_80098F8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009C54: .4byte gUnknown_202D2A0
_08009C58: .4byte gUnknown_202B038
	thumb_func_end sub_8009BE4

	thumb_func_start sub_8009C5C
sub_8009C5C:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0xFF
	ble _08009C6C
	movs r1, 0x3
	bl __modsi3
	b _08009C72
_08009C6C:
	ldr r0, _08009C78
	adds r0, r1, r0
	ldrb r0, [r0]
_08009C72:
	pop {r1}
	bx r1
	.align 2, 0
_08009C78: .4byte gUnknown_80B88E4
	thumb_func_end sub_8009C5C

	thumb_func_start sub_8009C7C
sub_8009C7C:
	push {lr}
	adds r2, r0, 0
	movs r3, 0xC0
	lsls r3, 4
	adds r1, r2, 0
	ands r1, r3
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	beq _08009CB8
	cmp r1, r0
	bgt _08009C9A
	cmp r1, 0
	beq _08009CA8
	b _08009CFC
_08009C9A:
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	beq _08009CD0
	cmp r1, r3
	beq _08009CE0
	b _08009CFC
_08009CA8:
	ldr r0, _08009CB0
	ldr r1, _08009CB4
	ands r1, r2
	b _08009CBE
	.align 2, 0
_08009CB0: .4byte gUnknown_80B8AE4
_08009CB4: .4byte 0x000003ff
_08009CB8:
	ldr r0, _08009CC8
	ldr r1, _08009CCC
	bics r1, r2
_08009CBE:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	b _08009CFE
	.align 2, 0
_08009CC8: .4byte gUnknown_80B8AE4
_08009CCC: .4byte 0x000003ff
_08009CD0:
	ldr r0, _08009CD8
	ldr r1, _08009CDC
	ands r1, r2
	b _08009CE6
	.align 2, 0
_08009CD8: .4byte gUnknown_80B8AE4
_08009CDC: .4byte 0x000003ff
_08009CE0:
	ldr r0, _08009CF4
	ldr r1, _08009CF8
	bics r1, r2
_08009CE6:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	negs r0, r0
	b _08009CFE
	.align 2, 0
_08009CF4: .4byte gUnknown_80B8AE4
_08009CF8: .4byte 0x000003ff
_08009CFC:
	movs r0, 0
_08009CFE:
	pop {r1}
	bx r1
	thumb_func_end sub_8009C7C

	thumb_func_start sub_8009D04
sub_8009D04:
	push {lr}
	adds r2, r0, 0
	movs r3, 0xC0
	lsls r3, 4
	adds r1, r2, 0
	ands r1, r3
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	beq _08009D40
	cmp r1, r0
	bgt _08009D22
	cmp r1, 0
	beq _08009D30
	b _08009D84
_08009D22:
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	beq _08009D50
	cmp r1, r3
	beq _08009D6C
	b _08009D84
_08009D30:
	ldr r0, _08009D38
	ldr r1, _08009D3C
	bics r1, r2
	b _08009D72
	.align 2, 0
_08009D38: .4byte gUnknown_80B8AE4
_08009D3C: .4byte 0x000003ff
_08009D40:
	ldr r0, _08009D48
	ldr r1, _08009D4C
	ands r1, r2
	b _08009D56
	.align 2, 0
_08009D48: .4byte gUnknown_80B8AE4
_08009D4C: .4byte 0x000003ff
_08009D50:
	ldr r0, _08009D64
	ldr r1, _08009D68
	bics r1, r2
_08009D56:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	negs r0, r0
	b _08009D86
	.align 2, 0
_08009D64: .4byte gUnknown_80B8AE4
_08009D68: .4byte 0x000003ff
_08009D6C:
	ldr r0, _08009D7C
	ldr r1, _08009D80
	ands r1, r2
_08009D72:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	b _08009D86
	.align 2, 0
_08009D7C: .4byte gUnknown_80B8AE4
_08009D80: .4byte 0x000003ff
_08009D84:
	movs r0, 0
_08009D86:
	pop {r1}
	bx r1
	thumb_func_end sub_8009D04

	thumb_func_start sub_8009D8C
sub_8009D8C:
	push {lr}
	cmp r0, r2
	bcc _08009D9A
	cmp r0, r2
	bhi _08009D9E
	cmp r1, r3
	bcs _08009D9E
_08009D9A:
	movs r0, 0x1
	b _08009DA0
_08009D9E:
	movs r0, 0
_08009DA0:
	pop {r1}
	bx r1
	thumb_func_end sub_8009D8C

	thumb_func_start sub_8009DA4
sub_8009DA4:
	push {r4,r5,lr}
	lsrs r2, r0, 31
	adds r5, r2, 0
	lsrs r3, r1, 31
	adds r4, r3, 0
	cmp r0, 0
	beq _08009DB6
	cmp r1, 0
	bne _08009DBA
_08009DB6:
	movs r0, 0
	b _08009DD0
_08009DBA:
	cmp r2, 0
	beq _08009DC0
	negs r0, r0
_08009DC0:
	cmp r3, 0
	beq _08009DC6
	negs r1, r1
_08009DC6:
	bl sub_8009E14
	cmp r5, r4
	beq _08009DD0
	negs r0, r0
_08009DD0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8009DA4

	thumb_func_start sub_8009DD8
sub_8009DD8:
	push {r4,r5,lr}
	lsrs r2, r0, 31
	adds r5, r2, 0
	lsrs r3, r1, 31
	adds r4, r3, 0
	cmp r1, 0
	bne _08009DF0
	ldr r0, _08009DEC
	b _08009E0E
	.align 2, 0
_08009DEC: .4byte 0x7fffffff
_08009DF0:
	cmp r0, 0
	bne _08009DF8
	movs r0, 0
	b _08009E0E
_08009DF8:
	cmp r2, 0
	beq _08009DFE
	negs r0, r0
_08009DFE:
	cmp r3, 0
	beq _08009E04
	negs r1, r1
_08009E04:
	bl sub_8009EA0
	cmp r5, r4
	beq _08009E0E
	negs r0, r0
_08009E0E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8009DD8

	thumb_func_start sub_8009E14
sub_8009E14:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	cmp r0, 0
	beq _08009E24
	cmp r1, 0
	bne _08009E28
_08009E24:
	movs r0, 0
	b _08009E94
_08009E28:
	movs r5, 0
	adds r3, r0, 0
	mov r12, r5
	movs r6, 0
	movs r4, 0
	movs r0, 0x80
	lsls r0, 24
	mov r8, r0
	movs r7, 0x3F
	mov r9, r7
_08009E3C:
	adds r2, r4, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08009E50
	adds r4, r3
	adds r6, r5
	cmp r2, r4
	bls _08009E50
	adds r6, 0x1
_08009E50:
	lsrs r1, 1
	movs r2, 0x1
	mov r0, r12
	ands r0, r2
	cmp r0, 0
	beq _08009E60
	mov r0, r8
	orrs r1, r0
_08009E60:
	mov r7, r12
	lsrs r7, 1
	mov r12, r7
	lsls r5, 1
	adds r0, r3, 0
	mov r7, r8
	ands r0, r7
	cmp r0, 0
	beq _08009E74
	orrs r5, r2
_08009E74:
	lsls r3, 1
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r7, r9
	cmp r7, 0
	bge _08009E3C
	lsrs r1, r4, 7
	ands r1, r2
	lsrs r4, 8
	lsls r0, r6, 24
	orrs r4, r0
	cmp r1, 0
	beq _08009E92
	adds r4, 0x1
_08009E92:
	adds r0, r4, 0
_08009E94:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009E14

	thumb_func_start sub_8009EA0
sub_8009EA0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	cmp r1, 0
	bne _08009EB8
	ldr r0, _08009EB4
	b _08009F58
	.align 2, 0
_08009EB4: .4byte 0x7fffffff
_08009EB8:
	cmp r0, 0
	bne _08009EC0
	movs r0, 0
	b _08009F58
_08009EC0:
	lsrs r7, r0, 24
	lsls r6, r0, 8
	mov r10, r1
	movs r0, 0
	mov r9, r0
	movs r5, 0
	movs r4, 0
	movs r1, 0x1
	mov r8, r1
	movs r2, 0x3F
	str r2, [sp]
_08009ED6:
	lsls r5, 1
	adds r0, r4, 0
	movs r1, 0x80
	lsls r1, 24
	ands r0, r1
	cmp r0, 0
	beq _08009EE8
	mov r2, r8
	orrs r5, r2
_08009EE8:
	movs r1, 0x2
	negs r1, r1
	lsls r4, 1
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 24
	ands r0, r2
	cmp r0, 0
	beq _08009EFE
	mov r0, r8
	orrs r4, r0
_08009EFE:
	lsls r7, 1
	adds r0, r6, 0
	movs r2, 0x80
	lsls r2, 24
	ands r0, r2
	cmp r0, 0
	beq _08009F10
	mov r0, r8
	orrs r7, r0
_08009F10:
	lsls r6, 1
	ands r6, r1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	mov r3, r10
	bl sub_8009D8C
	lsls r0, 24
	cmp r0, 0
	bne _08009F3A
	adds r0, r4, 0
	movs r1, 0x1
	mov r2, r10
	subs r4, r2
	movs r2, 0
	subs r5, r2
	cmp r0, r4
	bcs _08009F3C
	subs r5, 0x1
	b _08009F3C
_08009F3A:
	movs r1, 0
_08009F3C:
	mov r0, r9
	lsls r0, 1
	mov r9, r0
	cmp r1, 0
	beq _08009F4C
	mov r1, r8
	orrs r0, r1
	mov r9, r0
_08009F4C:
	ldr r2, [sp]
	subs r2, 0x1
	str r2, [sp]
	cmp r2, 0
	bge _08009ED6
	mov r0, r9
_08009F58:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009EA0

	thumb_func_start sub_8009F68
sub_8009F68:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r6, 0
	cmp r6, 0
	bge _08009F76
	negs r4, r6
_08009F76:
	movs r7, 0x80
	lsls r7, 1
	cmp r4, 0
	beq _08009FA0
_08009F7E:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08009F90
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_8009DA4
	adds r7, r0, 0
_08009F90:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_8009DA4
	adds r5, r0, 0
	asrs r4, 1
	cmp r4, 0
	bne _08009F7E
_08009FA0:
	cmp r6, 0
	bge _08009FB0
	movs r0, 0x80
	lsls r0, 1
	adds r1, r7, 0
	bl sub_8009DD8
	b _08009FB2
_08009FB0:
	adds r0, r7, 0
_08009FB2:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009F68

	thumb_func_start sub_8009FB8
sub_8009FB8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r5, 0
	bge _08009FC4
	negs r5, r5
_08009FC4:
	cmp r6, 0
	bge _08009FCA
	negs r6, r6
_08009FCA:
	cmp r5, r6
	bge _08009FD4
	adds r4, r5, 0
	adds r5, r6, 0
	adds r6, r4, 0
_08009FD4:
	cmp r6, 0
	beq _0800A016
	movs r7, 0x2
_08009FDA:
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8009DD8
	adds r4, r0, 0
	adds r1, r4, 0
	bl sub_8009DA4
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 3
	adds r1, r4, r0
	adds r0, r4, 0
	bl sub_8009DD8
	adds r4, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8009DA4
	lsls r0, 1
	adds r5, r0
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8009DA4
	adds r6, r0, 0
	subs r7, 0x1
	cmp r7, 0
	bge _08009FDA
_0800A016:
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009FB8

	thumb_func_start sub_800A020
sub_800A020:
	push {r4,lr}
	adds r3, r0, 0
	ldr r4, _0800A044
	lsrs r2, r1, 16
	str r2, [r3]
	lsls r0, r1, 16
	str r0, [r3, 0x4]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _0800A03C
	orrs r2, r4
	str r2, [r3]
_0800A03C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A044: .4byte 0xffff0000
	thumb_func_end sub_800A020

	thumb_func_start sub_800A048
sub_800A048:
	push {lr}
	ldrh r1, [r0]
	lsls r2, r1, 16
	ldr r0, [r0, 0x4]
	lsrs r1, r0, 16
	orrs r2, r1
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0800A060
	adds r2, 0x1
_0800A060:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_800A048

	thumb_func_start sub_800A068
sub_800A068:
	push {lr}
	ldrb r1, [r0]
	lsls r2, r1, 24
	ldr r0, [r0, 0x4]
	lsrs r1, r0, 8
	orrs r2, r1
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0800A080
	adds r2, 0x1
_0800A080:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_800A068

	thumb_func_start sub_800A088
sub_800A088:
	push {lr}
	adds r2, r0, 0
	lsls r0, r1, 8
	str r0, [r2, 0x4]
	asrs r1, 24
	str r1, [r2]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0800A0A4
	movs r0, 0x80
	negs r0, r0
	orrs r1, r0
	b _0800A0A8
_0800A0A4:
	movs r0, 0x7F
	ands r1, r0
_0800A0A8:
	str r1, [r2]
	pop {r0}
	bx r0
	thumb_func_end sub_800A088

	thumb_func_start sub_800A0B0
sub_800A0B0:
	push {lr}
	ldr r2, [r0, 0x4]
	ldr r3, [r0]
	cmp r2, 0
	bne _0800A0C2
	cmp r3, 0
	bne _0800A0C2
	movs r0, 0
	b _0800A254
_0800A0C2:
	cmp r2, 0
	ble _0800A18C
	cmp r3, 0
	ble _0800A124
	cmp r2, r3
	bge _0800A0F0
	asrs r1, r3, 8
	cmp r1, 0
	beq _0800A0FE
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A0E2
	movs r2, 0xFF
_0800A0E2:
	ldr r0, _0800A0EC
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	b _0800A252
	.align 2, 0
_0800A0EC: .4byte gUnknown_80B92E4
_0800A0F0:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A0F8
	adds r1, 0xFF
_0800A0F8:
	asrs r1, 8
	cmp r1, 0
	bne _0800A104
_0800A0FE:
	movs r0, 0x80
	lsls r0, 2
	b _0800A254
_0800A104:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A112
	movs r2, 0xFF
_0800A112:
	ldr r1, _0800A120
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x40
	b _0800A250
	.align 2, 0
_0800A120: .4byte gUnknown_80B92E4
_0800A124:
	negs r3, r3
	cmp r2, r3
	bge _0800A158
	adds r1, r3, 0
	cmp r3, 0
	bge _0800A132
	adds r1, 0xFF
_0800A132:
	asrs r1, 8
	cmp r1, 0
	beq _0800A166
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A146
	movs r2, 0xFF
_0800A146:
	ldr r1, _0800A154
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	b _0800A250
	.align 2, 0
_0800A154: .4byte gUnknown_80B92E4
_0800A158:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A160
	adds r1, 0xFF
_0800A160:
	asrs r1, 8
	cmp r1, 0
	bne _0800A16C
_0800A166:
	movs r0, 0xC0
	lsls r0, 3
	b _0800A254
_0800A16C:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A17A
	movs r2, 0xFF
_0800A17A:
	ldr r0, _0800A188
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x40
	b _0800A252
	.align 2, 0
_0800A188: .4byte gUnknown_80B92E4
_0800A18C:
	negs r2, r2
	cmp r3, 0
	ble _0800A1F0
	cmp r2, r3
	bge _0800A1BC
	asrs r1, r3, 8
	cmp r1, 0
	beq _0800A1CA
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A1AA
	movs r2, 0xFF
_0800A1AA:
	ldr r1, _0800A1B8
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	b _0800A250
	.align 2, 0
_0800A1B8: .4byte gUnknown_80B92E4
_0800A1BC:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A1C4
	adds r1, 0xFF
_0800A1C4:
	asrs r1, 8
	cmp r1, 0
	bne _0800A1D0
_0800A1CA:
	movs r0, 0xE0
	lsls r0, 4
	b _0800A254
_0800A1D0:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A1DE
	movs r2, 0xFF
_0800A1DE:
	ldr r0, _0800A1EC
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0xC0
	b _0800A252
	.align 2, 0
_0800A1EC: .4byte gUnknown_80B92E4
_0800A1F0:
	negs r3, r3
	cmp r2, r3
	bge _0800A224
	adds r1, r3, 0
	cmp r3, 0
	bge _0800A1FE
	adds r1, 0xFF
_0800A1FE:
	asrs r1, 8
	cmp r1, 0
	beq _0800A232
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A212
	movs r2, 0xFF
_0800A212:
	ldr r0, _0800A220
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x80
	b _0800A252
	.align 2, 0
_0800A220: .4byte gUnknown_80B92E4
_0800A224:
	adds r0, r2, 0
	cmp r0, 0
	bge _0800A22C
	adds r0, 0xFF
_0800A22C:
	asrs r1, r0, 8
	cmp r1, 0
	bne _0800A238
_0800A232:
	movs r0, 0xA0
	lsls r0, 4
	b _0800A254
_0800A238:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A246
	movs r2, 0xFF
_0800A246:
	ldr r1, _0800A258
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0xC0
_0800A250:
	subs r0, r1
_0800A252:
	lsls r0, 4
_0800A254:
	pop {r1}
	bx r1
	.align 2, 0
_0800A258: .4byte gUnknown_80B92E4
	thumb_func_end sub_800A0B0

	thumb_func_start sub_800A25C
sub_800A25C:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	mvns r2, r0
	str r2, [r1]
	ldr r0, [r1, 0x4]
	mvns r0, r0
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A276
	adds r0, r2, 0x1
	str r0, [r1]
_0800A276:
	pop {r0}
	bx r0
	thumb_func_end sub_800A25C

	thumb_func_start sub_800A27C
sub_800A27C:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bge _0800A29A
	mvns r2, r0
	str r2, [r1]
	ldr r0, [r1, 0x4]
	mvns r0, r0
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A29A
	adds r0, r2, 0x1
	str r0, [r1]
_0800A29A:
	pop {r0}
	bx r0
	thumb_func_end sub_800A27C

	thumb_func_start sub_800A2A0
sub_800A2A0:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bne _0800A2B4
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A2B4
	movs r0, 0x1
	b _0800A2B6
_0800A2B4:
	movs r0, 0
_0800A2B6:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2A0

	thumb_func_start sub_800A2BC
sub_800A2BC:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _0800A2D6
	ldr r1, [r2, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bne _0800A2D6
	movs r0, 0x1
	b _0800A2D8
_0800A2D6:
	movs r0, 0
_0800A2D8:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2BC

	thumb_func_start sub_800A2DC
sub_800A2DC:
	push {lr}
	ldr r0, [r0]
	cmp r0, 0
	blt _0800A2E8
	movs r0, 0
	b _0800A2EA
_0800A2E8:
	movs r0, 0x1
_0800A2EA:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2DC

	thumb_func_start sub_800A2F0
sub_800A2F0:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r4, [r3]
	lsrs r1, r4, 31
	ldr r5, [r2]
	cmp r5, 0
	bge _0800A304
	movs r0, 0x2
	orrs r1, r0
_0800A304:
	cmp r1, 0x1
	beq _0800A326
	cmp r1, 0x1
	ble _0800A314
	cmp r1, 0x2
	beq _0800A32A
	cmp r1, 0x3
	beq _0800A32E
_0800A314:
	ldr r1, [r3, 0x4]
	ldr r3, [r2, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8009D8C
	lsls r0, 24
	lsrs r0, 24
	b _0800A346
_0800A326:
	movs r0, 0x1
	b _0800A346
_0800A32A:
	movs r0, 0
	b _0800A346
_0800A32E:
	ldr r1, [r3, 0x4]
	ldr r3, [r2, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8009D8C
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _0800A344
	movs r1, 0x1
_0800A344:
	adds r0, r1, 0
_0800A346:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800A2F0

	thumb_func_start sub_800A34C
sub_800A34C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	ldr r0, [r2]
	str r0, [sp, 0x8]
	ldr r0, [r2, 0x4]
	add r5, sp, 0x8
	str r0, [r5, 0x4]
	mov r0, sp
	bl sub_800A2DC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r10, r8
	adds r0, r5, 0
	bl sub_800A2DC
	lsls r0, 24
	lsrs r7, r0, 24
	mov r9, r7
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A39A
	movs r0, 0
	str r0, [r6]
	b _0800A3DE
_0800A39A:
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A3AC
	str r4, [r6]
	str r4, [r6, 0x4]
	b _0800A3E0
_0800A3AC:
	mov r0, r8
	cmp r0, 0
	beq _0800A3B8
	mov r0, sp
	bl sub_800A25C
_0800A3B8:
	cmp r7, 0
	beq _0800A3C2
	adds r0, r5, 0
	bl sub_800A25C
_0800A3C2:
	add r4, sp, 0x10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_800A4E4
	cmp r10, r9
	beq _0800A3D8
	adds r0, r4, 0
	bl sub_800A25C
_0800A3D8:
	ldr r0, [sp, 0x10]
	str r0, [r6]
	ldr r0, [r4, 0x4]
_0800A3DE:
	str r0, [r6, 0x4]
_0800A3E0:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A34C

	thumb_func_start sub_800A3F0
sub_800A3F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	ldr r0, [r2]
	str r0, [sp, 0x8]
	ldr r0, [r2, 0x4]
	add r5, sp, 0x8
	str r0, [r5, 0x4]
	mov r0, sp
	bl sub_800A2DC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r10, r8
	adds r0, r5, 0
	bl sub_800A2DC
	lsls r0, 24
	lsrs r7, r0, 24
	mov r9, r7
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A448
	ldr r0, _0800A444
	str r0, [r6]
	movs r0, 0x1
	negs r0, r0
	b _0800A48C
	.align 2, 0
_0800A444: .4byte 0x7fffffff
_0800A448:
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A45A
	str r4, [r6]
	str r4, [r6, 0x4]
	b _0800A48E
_0800A45A:
	mov r0, r8
	cmp r0, 0
	beq _0800A466
	mov r0, sp
	bl sub_800A25C
_0800A466:
	cmp r7, 0
	beq _0800A470
	adds r0, r5, 0
	bl sub_800A25C
_0800A470:
	add r4, sp, 0x10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_800A5A4
	cmp r10, r9
	beq _0800A486
	adds r0, r4, 0
	bl sub_800A25C
_0800A486:
	ldr r0, [sp, 0x10]
	str r0, [r6]
	ldr r0, [r4, 0x4]
_0800A48C:
	str r0, [r6, 0x4]
_0800A48E:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A3F0

	thumb_func_start sub_800A4A0
sub_800A4A0:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r0, [r5]
	str r0, [sp]
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A4C0
	movs r0, 0
	str r0, [r5]
	b _0800A4D8
_0800A4C0:
	mov r0, sp
	bl sub_800A27C
	add r4, sp, 0x8
	adds r0, r4, 0
	mov r1, sp
	mov r2, sp
	bl sub_800A4E4
	ldr r0, [sp, 0x8]
	str r0, [r5]
	ldr r0, [r4, 0x4]
_0800A4D8:
	str r0, [r5, 0x4]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800A4A0

	thumb_func_start sub_800A4E4
sub_800A4E4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A50C
	movs r0, 0
	mov r1, r8
	str r0, [r1]
	str r0, [r1, 0x4]
	b _0800A596
_0800A50C:
	adds r0, r6, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A520
	mov r7, r8
	str r4, [r7]
	str r4, [r7, 0x4]
	b _0800A596
_0800A520:
	ldr r1, [r5]
	ldr r4, [r5, 0x4]
	ldr r0, [r6]
	mov r10, r0
	ldr r2, [r6, 0x4]
	movs r6, 0
	movs r5, 0
	movs r7, 0x80
	lsls r7, 24
	mov r9, r7
	movs r0, 0x3F
	mov r12, r0
_0800A538:
	adds r3, r5, 0
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0800A54C
	adds r5, r4
	adds r6, r1
	cmp r3, r5
	bls _0800A54C
	adds r6, 0x1
_0800A54C:
	lsrs r2, 1
	movs r3, 0x1
	mov r0, r10
	ands r0, r3
	cmp r0, 0
	beq _0800A55C
	mov r7, r9
	orrs r2, r7
_0800A55C:
	mov r0, r10
	lsrs r0, 1
	mov r10, r0
	lsls r1, 1
	adds r0, r4, 0
	mov r7, r9
	ands r0, r7
	cmp r0, 0
	beq _0800A570
	orrs r1, r3
_0800A570:
	lsls r4, 1
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	mov r7, r12
	cmp r7, 0
	bge _0800A538
	lsrs r1, r5, 15
	ands r1, r3
	lsrs r5, 16
	lsls r0, r6, 16
	orrs r5, r0
	lsrs r6, 16
	cmp r1, 0
	beq _0800A590
	adds r5, 0x1
_0800A590:
	mov r0, r8
	str r6, [r0]
	str r5, [r0, 0x4]
_0800A596:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A4E4

	thumb_func_start sub_800A5A4
sub_800A5A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp]
	adds r5, r1, 0
	mov r8, r2
	mov r0, r8
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A5D8
	ldr r0, _0800A5D4
	ldr r1, [sp]
	str r0, [r1]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x4]
	b _0800A6BE
	.align 2, 0
_0800A5D4: .4byte 0x7fffffff
_0800A5D8:
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A5EC
	ldr r2, [sp]
	str r4, [r2]
	str r4, [r2, 0x4]
	b _0800A6BE
_0800A5EC:
	ldr r0, [r5]
	lsls r7, r0, 16
	ldr r1, [r5, 0x4]
	lsrs r0, r1, 16
	orrs r7, r0
	lsls r6, r1, 16
	movs r0, 0x80
	lsls r0, 8
	orrs r6, r0
	mov r0, r8
	ldr r0, [r0]
	str r0, [sp, 0x4]
	mov r1, r8
	ldr r1, [r1, 0x4]
	str r1, [sp, 0x8]
	movs r2, 0
	str r2, [sp, 0xC]
	mov r9, r2
	movs r5, 0
	movs r4, 0
	movs r0, 0x80
	lsls r0, 24
	mov r10, r0
	movs r1, 0x1
	mov r8, r1
	movs r2, 0x3F
	str r2, [sp, 0x10]
_0800A622:
	lsls r5, 1
	adds r0, r4, 0
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _0800A632
	mov r2, r8
	orrs r5, r2
_0800A632:
	movs r1, 0x2
	negs r1, r1
	lsls r4, 1
	adds r0, r7, 0
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A646
	mov r0, r8
	orrs r4, r0
_0800A646:
	lsls r7, 1
	adds r0, r6, 0
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A656
	mov r0, r8
	orrs r7, r0
_0800A656:
	lsls r6, 1
	ands r6, r1
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0x8]
	bl sub_8009D8C
	lsls r0, 24
	cmp r0, 0
	bne _0800A680
	adds r0, r4, 0
	movs r1, 0x1
	ldr r2, [sp, 0x8]
	subs r4, r2
	ldr r2, [sp, 0x4]
	subs r5, r2
	cmp r0, r4
	bcs _0800A682
	subs r5, 0x1
	b _0800A682
_0800A680:
	movs r1, 0
_0800A682:
	ldr r0, [sp, 0xC]
	lsls r0, 1
	str r0, [sp, 0xC]
	mov r0, r9
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A69A
	ldr r0, [sp, 0xC]
	mov r2, r8
	orrs r0, r2
	str r0, [sp, 0xC]
_0800A69A:
	mov r0, r9
	lsls r0, 1
	mov r9, r0
	cmp r1, 0
	beq _0800A6AA
	mov r1, r8
	orrs r0, r1
	mov r9, r0
_0800A6AA:
	ldr r2, [sp, 0x10]
	subs r2, 0x1
	str r2, [sp, 0x10]
	cmp r2, 0
	bge _0800A622
	ldr r0, [sp, 0xC]
	ldr r1, [sp]
	str r0, [r1]
	mov r2, r9
	str r2, [r1, 0x4]
_0800A6BE:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A5A4

	thumb_func_start sub_800A6D0
sub_800A6D0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r1]
	ldr r0, [r2]
	adds r3, r0
	ldr r1, [r1, 0x4]
	ldr r0, [r2, 0x4]
	adds r0, r1, r0
	cmp r0, r1
	bcs _0800A6E6
	adds r3, 0x1
_0800A6E6:
	str r3, [r4]
	str r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800A6D0

	thumb_func_start sub_800A6F0
sub_800A6F0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r1]
	ldr r0, [r2]
	subs r3, r0
	ldr r1, [r1, 0x4]
	ldr r0, [r2, 0x4]
	subs r0, r1, r0
	cmp r0, r1
	bls _0800A706
	subs r3, 0x1
_0800A706:
	str r3, [r4]
	str r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800A6F0

	thumb_func_start sub_800A710
sub_800A710:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	mov r8, r0
	adds r6, r2, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	adds r4, r6, 0
	cmp r6, 0
	bge _0800A72C
	negs r4, r6
_0800A72C:
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x80
	lsls r1, 9
	add r0, sp, 0x8
	str r1, [r0, 0x4]
	adds r7, r0, 0
	cmp r4, 0
	beq _0800A75E
	adds r5, r7, 0
_0800A740:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0800A752
	adds r0, r5, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_800A34C
_0800A752:
	mov r0, sp
	bl sub_800A4A0
	asrs r4, 1
	cmp r4, 0
	bne _0800A740
_0800A75E:
	cmp r6, 0
	bge _0800A776
	movs r0, 0
	str r0, [sp, 0x10]
	movs r0, 0x80
	lsls r0, 9
	add r1, sp, 0x10
	str r0, [r1, 0x4]
	adds r0, r7, 0
	adds r2, r7, 0
	bl sub_800A3F0
_0800A776:
	ldr r0, [sp, 0x8]
	mov r1, r8
	str r0, [r1]
	ldr r0, [r7, 0x4]
	str r0, [r1, 0x4]
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A710

	thumb_func_start sub_800A78C
sub_800A78C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r10, r0
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	mov r0, sp
	bl sub_800A27C
	add r4, sp, 0x8
	adds r0, r4, 0
	bl sub_800A27C
	mov r0, sp
	adds r1, r4, 0
	bl sub_800A2F0
	lsls r0, 24
	mov r8, r4
	cmp r0, 0
	beq _0800A7DC
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	str r2, [sp, 0x10]
	str r3, [sp, 0x14]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
_0800A7DC:
	mov r0, r8
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	bne _0800A878
	movs r0, 0
	mov r9, r0
	add r7, sp, 0x10
	add r6, sp, 0x18
	b _0800A800
_0800A7F2:
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	movs r2, 0x1
	add r9, r2
_0800A800:
	adds r4, r7, 0
	mov r1, r8
	adds r0, r4, 0
	mov r2, sp
	bl sub_800A3F0
	adds r0, r4, 0
	bl sub_800A4A0
	ldr r0, [sp, 0x10]
	str r0, [sp, 0x18]
	ldr r1, [r4, 0x4]
	movs r0, 0x80
	lsls r0, 11
	adds r1, r0
	adds r5, r6, 0
	str r1, [r5, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	bcs _0800A82E
	ldr r0, [sp, 0x18]
	adds r0, 0x1
	str r0, [sp, 0x18]
_0800A82E:
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A3F0
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_800A34C
	ldr r0, [sp, 0x18]
	lsls r1, r0, 1
	str r1, [sp, 0x18]
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _0800A854
	movs r0, 0x1
	orrs r1, r0
	str r1, [sp, 0x18]
_0800A854:
	ldr r0, [r6, 0x4]
	lsls r0, 1
	str r0, [r6, 0x4]
	ldr r2, [sp, 0x4]
	ldr r1, [sp]
	ldr r0, [sp, 0x18]
	adds r1, r0
	str r1, [sp]
	ldr r0, [r6, 0x4]
	adds r0, r2, r0
	str r0, [sp, 0x4]
	cmp r2, r0
	bls _0800A872
	adds r0, r1, 0x1
	str r0, [sp]
_0800A872:
	mov r2, r9
	cmp r2, 0x2
	bne _0800A7F2
_0800A878:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	mov r2, r10
	str r0, [r2]
	str r1, [r2, 0x4]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A78C

	.align 2, 0 @ Don't pad with nop.
