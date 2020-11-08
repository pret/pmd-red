	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_800CA38
sub_800CA38:
	push {r4,lr}
	adds r4, r0, 0
	bl IsBGSong
	lsls r0, 24
	cmp r0, 0
	beq _0800CA54
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_800CAE0
	lsls r0, 16
	cmp r0, 0
	beq _0800CA70
_0800CA54:
	adds r0, r4, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800CA74
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0800CA90
_0800CA70:
	movs r0, 0x1
	b _0800CA92
_0800CA74:
	adds r0, r4, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800CA90
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0800CA70
_0800CA90:
	movs r0, 0
_0800CA92:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800CA38

	thumb_func_start nullsub_19
nullsub_19:
	bx lr
	thumb_func_end nullsub_19

	thumb_func_start IsBGSong
IsBGSong:
	push {lr}
	cmp r0, 128 @ Anything less than/equal 128 is a BG song
	bls _0800CAA6
	movs r0, 0
	b _0800CAA8
_0800CAA6:
	movs r0, 0x1
_0800CAA8:
	pop {r1}
	bx r1
	thumb_func_end IsBGSong

	thumb_func_start sub_800CAAC
sub_800CAAC:
	push {lr}
	ldr r1, _0800CABC
	adds r0, r1
	ldr r1, _0800CAC0
	cmp r0, r1
	bls _0800CAC4
	movs r0, 0
	b _0800CAC6
	.align 2, 0
_0800CABC: .4byte 0xfffffed4 @ -299
_0800CAC0: .4byte 0x0000027f
_0800CAC4:
	movs r0, 0x1
_0800CAC6:
	pop {r1}
	bx r1
	thumb_func_end sub_800CAAC

	thumb_func_start sub_800CACC
sub_800CACC:
	push {lr}
        @ Checking a table between 200 and 219... level up/trap sound effects?
	subs r0, 0xC8
	cmp r0, 0x13
	bls _0800CAD8
	movs r0, 0
	b _0800CADA
_0800CAD8:
	movs r0, 0x1
_0800CADA:
	pop {r1}
	bx r1
	thumb_func_end sub_800CACC

	thumb_func_start sub_800CAE0
sub_800CAE0:
	lsls r0, 16
	ldr r1, _0800CAEC
	lsrs r0, 13
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0800CAEC: .4byte gSongTable
	thumb_func_end sub_800CAE0

	thumb_func_start sub_800CAF0
sub_800CAF0:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0800CB0C
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, [r1]
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	beq _0800CB10
	movs r0, 0x1
	b _0800CB12
	.align 2, 0
_0800CB0C: .4byte gMPlayTable
_0800CB10:
	movs r0, 0
_0800CB12:
	pop {r1}
	bx r1
	thumb_func_end sub_800CAF0

	thumb_func_start nullsub_20
nullsub_20:
	bx lr
	thumb_func_end nullsub_20

	thumb_func_start nullsub_21
nullsub_21:
	bx lr
	thumb_func_end nullsub_21

	thumb_func_start sub_800CB20
sub_800CB20:
	push {lr}
	bl sub_800BA5C
	ldr r1, _0800CB48
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, _0800CB4C
	ldrh r1, [r0]
	movs r0, 0x5
	ands r0, r1
	cmp r0, 0
	beq _0800CB3E
	bl Random
_0800CB3E:
	bl Random
	pop {r0}
	bx r0
	.align 2, 0
_0800CB48: .4byte gUnknown_203B0B8
_0800CB4C: .4byte gUnknown_203B0BC
	thumb_func_end sub_800CB20

	thumb_func_start sub_800CB50
sub_800CB50:
	ldr r0, _0800CB58
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800CB58: .4byte gUnknown_203B0B8
	thumb_func_end sub_800CB50

	thumb_func_start nullsub_180
nullsub_180:
	bx lr
	thumb_func_end nullsub_180

	thumb_func_start xxx_call_update_bg_sound_input
xxx_call_update_bg_sound_input:
	push {lr}
	bl xxx_update_bg_sound_input
	pop {r0}
	bx r0
	thumb_func_end xxx_call_update_bg_sound_input

	thumb_func_start nullsub_181
nullsub_181:
	bx lr
	thumb_func_end nullsub_181

	thumb_func_start sub_800CB70
sub_800CB70:
	movs r0, 0
	bx lr
	thumb_func_end sub_800CB70

	thumb_func_start ReadKeyInput
ReadKeyInput:
	push {r4,lr}
	adds r2, r0, 0
	ldr r0, _0800CC38
	ldrh r1, [r0]
	ldr r3, _0800CC3C
	adds r0, r3, 0
	adds r3, r0, 0
	eors r3, r1
	movs r0, 0
	strh r0, [r2]
	movs r1, 0x40
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0800CB94
	strh r1, [r2]
_0800CB94:
	movs r0, 0x80
	ands r0, r3
	cmp r0, 0
	beq _0800CBA4
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
_0800CBA4:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _0800CBB4
	ldrh r0, [r2]
	movs r1, 0x20
	orrs r0, r1
	strh r0, [r2]
_0800CBB4:
	movs r0, 0x10
	ands r0, r3
	cmp r0, 0
	beq _0800CBC4
	ldrh r0, [r2]
	movs r1, 0x10
	orrs r0, r1
	strh r0, [r2]
_0800CBC4:
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0800CBD4
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
_0800CBD4:
	movs r0, 0x2
	ands r0, r3
	cmp r0, 0
	beq _0800CBE4
	ldrh r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r2]
_0800CBE4:
	movs r0, 0x8
	ands r0, r3
	cmp r0, 0
	beq _0800CBF4
	ldrh r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strh r0, [r2]
_0800CBF4:
	movs r0, 0x4
	ands r0, r3
	cmp r0, 0
	beq _0800CC04
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
_0800CC04:
	movs r4, 0x80
	lsls r4, 1
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _0800CC18
	ldrh r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
_0800CC18:
	movs r4, 0x80
	lsls r4, 2
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _0800CC2C
	ldrh r1, [r2]
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
_0800CC2C:
	ldr r0, _0800CC40
	strh r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CC38: .4byte 0x04000130
_0800CC3C: .4byte 0x000003ff
_0800CC40: .4byte gUnknown_203B0BC
	thumb_func_end ReadKeyInput

	thumb_func_start sub_800CC44
sub_800CC44:
	push {lr}
	adds r2, r1, 0
	cmp r0, 0
	bge _0800CC50
	movs r0, 0
	b _0800CC56
_0800CC50:
	cmp r0, 0x10
	ble _0800CC56
	movs r0, 0x10
_0800CC56:
	cmp r2, 0
	bge _0800CC5E
	movs r2, 0
	b _0800CC64
_0800CC5E:
	cmp r2, 0x10
	ble _0800CC64
	movs r2, 0x10
_0800CC64:
	ldr r1, _0800CC7C
	strb r0, [r1]
	ldr r0, _0800CC80
	strb r2, [r0]
	ldr r2, _0800CC84
	ldrb r1, [r1]
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	strh r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0800CC7C: .4byte gUnknown_202D6B8
_0800CC80: .4byte gUnknown_202D6B9
_0800CC84: .4byte gUnknown_202D7FA
	thumb_func_end sub_800CC44

	thumb_func_start sub_800CC88
sub_800CC88:
	ldr r2, _0800CC90
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CC90: .4byte gUnknown_202D698
	thumb_func_end sub_800CC88

	thumb_func_start sub_800CC94
sub_800CC94:
	ldr r2, _0800CC9C
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CC9C: .4byte gUnknown_202D6A0
	thumb_func_end sub_800CC94

	thumb_func_start sub_800CCA0
sub_800CCA0:
	ldr r2, _0800CCA8
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CCA8: .4byte gUnknown_202D6A8
	thumb_func_end sub_800CCA0

	thumb_func_start sub_800CCAC
sub_800CCAC:
	ldr r2, _0800CCB4
	strh r0, [r2, 0x4]
	strh r1, [r2, 0x6]
	bx lr
	.align 2, 0
_0800CCB4: .4byte gUnknown_202D6B0
	thumb_func_end sub_800CCAC

	thumb_func_start sub_800CCB8
sub_800CCB8:
	push {lr}
	cmp r0, 0x1
	beq _0800CCD4
	cmp r0, 0x1
	ble _0800CCCA
	cmp r0, 0x2
	beq _0800CCDE
	cmp r0, 0x3
	beq _0800CCE8
_0800CCCA:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CC88
	b _0800CCF0
_0800CCD4:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CC94
	b _0800CCF0
_0800CCDE:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CCA0
	b _0800CCF0
_0800CCE8:
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_800CCAC
_0800CCF0:
	pop {r0}
	bx r0
	thumb_func_end sub_800CCB8

	thumb_func_start sub_800CCF4
sub_800CCF4:
	push {lr}
	cmp r0, 0x1
	beq _0800CD10
	cmp r0, 0x1
	ble _0800CD06
	cmp r0, 0x2
	beq _0800CD18
	cmp r0, 0x3
	beq _0800CD20
_0800CD06:
	ldr r0, _0800CD0C
	b _0800CD22
	.align 2, 0
_0800CD0C: .4byte gUnknown_202D698
_0800CD10:
	ldr r0, _0800CD14
	b _0800CD22
	.align 2, 0
_0800CD14: .4byte gUnknown_202D6A0
_0800CD18:
	ldr r0, _0800CD1C
	b _0800CD22
	.align 2, 0
_0800CD1C: .4byte gUnknown_202D6A8
_0800CD20:
	ldr r0, _0800CD28
_0800CD22:
	strh r1, [r0, 0x4]
	pop {r0}
	bx r0
	.align 2, 0
_0800CD28: .4byte gUnknown_202D6B0
	thumb_func_end sub_800CCF4

	thumb_func_start sub_800CD2C
sub_800CD2C:
	push {lr}
	cmp r0, 0x1
	beq _0800CD48
	cmp r0, 0x1
	ble _0800CD3E
	cmp r0, 0x2
	beq _0800CD50
	cmp r0, 0x3
	beq _0800CD58
_0800CD3E:
	ldr r0, _0800CD44
	b _0800CD5A
	.align 2, 0
_0800CD44: .4byte gUnknown_202D698
_0800CD48:
	ldr r0, _0800CD4C
	b _0800CD5A
	.align 2, 0
_0800CD4C: .4byte gUnknown_202D6A0
_0800CD50:
	ldr r0, _0800CD54
	b _0800CD5A
	.align 2, 0
_0800CD54: .4byte gUnknown_202D6A8
_0800CD58:
	ldr r0, _0800CD60
_0800CD5A:
	strh r1, [r0, 0x6]
	pop {r0}
	bx r0
	.align 2, 0
_0800CD60: .4byte gUnknown_202D6B0
	thumb_func_end sub_800CD2C

	thumb_func_start sub_800CD64
sub_800CD64:
	ldr r2, _0800CD7C
	strb r1, [r2]
	ldr r2, _0800CD80
	negs r1, r0
	orrs r1, r0
	asrs r1, 31
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	ands r1, r0
	strh r1, [r2, 0x2]
	bx lr
	.align 2, 0
_0800CD7C: .4byte gUnknown_202D7FE
_0800CD80: .4byte gUnknown_202D6A8
	thumb_func_end sub_800CD64

	thumb_func_start SetBGOBJEnableFlags
SetBGOBJEnableFlags:
	push {r4,lr}
	movs r3, 0x80
	lsls r3, 19
	ldrh r1, [r3]
	ldr r2, _0800CDA4
	ands r2, r1
	lsls r0, 8
	movs r4, 0xF8
	lsls r4, 5
	adds r1, r4, 0
	bics r1, r0
	orrs r2, r1
	strh r2, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CDA4: .4byte 0x0000e0ff
	thumb_func_end SetBGOBJEnableFlags

	thumb_func_start sub_800CDA8
sub_800CDA8:
	ldr r1, _0800CDBC
	str r0, [r1]
	ldr r2, _0800CDC0
	ldr r1, _0800CDC4
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.align 2, 0
_0800CDBC: .4byte gUnknown_202D800
_0800CDC0: .4byte gUnknown_202D7FC
_0800CDC4: .4byte gUnknown_203B0BE
	thumb_func_end sub_800CDA8

	thumb_func_start sub_800CDC8
sub_800CDC8:
	ldr r0, _0800CDD0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800CDD0: .4byte gUnknown_202D800
	thumb_func_end sub_800CDC8

	thumb_func_start SetWindowTitle
SetWindowTitle:
	bx lr
	thumb_func_end SetWindowTitle

	thumb_func_start nullsub_23
nullsub_23:
	bx lr
	thumb_func_end nullsub_23

	thumb_func_start nullsub_182
nullsub_182:
	bx lr
	thumb_func_end nullsub_182

	thumb_func_start sub_800CDE0
sub_800CDE0:
	movs r0, 0x1
	bx lr
	thumb_func_end sub_800CDE0

	thumb_func_start CpuCopy
CpuCopy:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	bge _0800CDEE
	adds r2, 0x3
_0800CDEE:
	lsls r2, 9
	lsrs r2, 11
	movs r0, 0x80
	lsls r0, 19
	orrs r2, r0
	adds r0, r1, 0
	adds r1, r3, 0
	bl CpuSet
	pop {r0}
	bx r0
	thumb_func_end CpuCopy

	thumb_func_start CpuClear
CpuClear:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	movs r0, 0
	str r0, [sp]
	cmp r1, 0
	bge _0800CE14
	adds r1, 0x3
_0800CE14:
	lsls r2, r1, 9
	lsrs r2, 11
	movs r0, 0xA0
	lsls r0, 19
	orrs r2, r0
	mov r0, sp
	adds r1, r3, 0
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end CpuClear

	thumb_func_start CpuFill
CpuFill:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	str r1, [sp]
	cmp r2, 0
	bge _0800CE3A
	adds r2, 0x3
_0800CE3A:
	lsls r2, 9
	lsrs r2, 11
	movs r0, 0xA0
	lsls r0, 19
	orrs r2, r0
	mov r0, sp
	adds r1, r3, 0
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end CpuFill

	thumb_func_start sub_800CE54
sub_800CE54:
	push {lr}
	ldr r2, _0800CEC0
	ldrh r0, [r2]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	orrs r0, r1
	ldr r1, _0800CEC4
	ands r0, r1
	strh r0, [r2]
	mov r8, r8
	mov r8, r8
	mov r8, r8
	mov r8, r8
	ldr r1, _0800CEC8
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0800CECC
	ldr r2, _0800CED0
	adds r0, r2, 0
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x3D
	strh r0, [r1]
	adds r1, 0x6
	ldr r0, _0800CED4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, 0x2
	ldr r0, _0800CED8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _0800CEDC
	ldrb r1, [r0]
	cmp r1, 0
	beq _0800CEF4
	ldr r1, _0800CEE0
	ldr r0, _0800CEE4
	ldr r2, [r0]
	adds r0, r2, 0x4
	str r0, [r1]
	ldr r3, _0800CEE8
	str r3, [r1, 0x4]
	ldr r0, _0800CEEC
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	ldrh r0, [r2]
	strh r0, [r3]
	subs r1, 0x6E
	ldrh r0, [r2, 0x2]
	strh r0, [r1]
	ldr r0, _0800CEF0
	movs r1, 0xA0
	b _0800CEFE
	.align 2, 0
_0800CEC0: .4byte 0x040000ba
_0800CEC4: .4byte 0x0000cdff
_0800CEC8: .4byte 0x00007fff
_0800CECC: .4byte 0x04000048
_0800CED0: .4byte 0x00003f3f
_0800CED4: .4byte gUnknown_202D7FC
_0800CED8: .4byte gUnknown_202D7FA
_0800CEDC: .4byte gUnknown_2026E38
_0800CEE0: .4byte 0x040000b0
_0800CEE4: .4byte gUnknown_2026E3C
_0800CEE8: .4byte 0x04000040
_0800CEEC: .4byte 0xa2600002
_0800CEF0: .4byte 0x04000044
_0800CEF4:
	ldr r0, _0800CF08
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r0, 0x2
_0800CEFE:
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0800CF08: .4byte 0x04000040
	thumb_func_end sub_800CE54

        .align 2,0
