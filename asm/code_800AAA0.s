	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800AAA8
sub_800AAA8:
	push {lr}
	ldr r2, [r2, 0x4]
	bl sub_800AAB4
	pop {r1}
	bx r1
	thumb_func_end sub_800AAA8

	thumb_func_start sub_800AAB4
sub_800AAB4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r12, r0
	str r1, [sp, 0x24]
	mov r8, r2
	ldrb r0, [r2, 0x5]
	ldrb r1, [r2, 0x6]
	lsls r1, 8
	adds r0, r1
	str r0, [sp, 0x28]
	movs r6, 0
	mov r10, r6
	movs r0, 0x8
	mov r9, r0
	ldrb r0, [r2]
	cmp r0, 0x41
	bne _0800AB04
	ldrb r0, [r2, 0x1]
	adds r1, r0, 0
	cmp r1, 0x54
	bne _0800AB0C
	ldrb r0, [r2, 0x2]
	cmp r0, 0x34
	bne _0800AB0C
	ldrb r0, [r2, 0x3]
	cmp r0, 0x50
	bne _0800AB0C
	ldrb r1, [r2, 0x10]
	ldrb r0, [r2, 0x11]
	lsls r0, 8
	adds r1, r0
	ldr r2, [sp, 0x24]
	cmp r2, 0
	beq _0800AB08
	cmp r2, r1
	beq _0800AB08
_0800AB04:
	movs r0, 0
	b _0800AE16
_0800AB08:
	movs r1, 0x12
	b _0800AB26
_0800AB0C:
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, 0x41
	bne _0800AB04
	cmp r1, 0x54
	bne _0800AB04
	ldrb r0, [r3, 0x2]
	cmp r0, 0x33
	bne _0800AB04
	ldrb r0, [r3, 0x3]
	cmp r0, 0x50
	bne _0800AB04
	movs r1, 0x10
_0800AB26:
	mov r2, r8
	ldrb r0, [r2, 0x4]
	cmp r0, 0x4E
	bne _0800AB4A
	movs r7, 0
	b _0800AB40
_0800AB32:
	mov r1, r12
	adds r0, r1, r7
	mov r2, r8
	adds r1, r7, r2
	ldrb r1, [r1, 0x7]
	strb r1, [r0]
	adds r7, 0x1
_0800AB40:
	ldr r3, [sp, 0x28]
	cmp r7, r3
	blt _0800AB32
	adds r0, r7, 0
	b _0800AE16
_0800AB4A:
	mov r2, r8
	ldrb r0, [r2, 0x7]
	adds r0, 0x3
	str r0, [sp]
	ldrb r0, [r2, 0x8]
	adds r0, 0x3
	str r0, [sp, 0x4]
	ldrb r0, [r2, 0x9]
	adds r0, 0x3
	str r0, [sp, 0x8]
	ldrb r0, [r2, 0xA]
	adds r0, 0x3
	str r0, [sp, 0xC]
	ldrb r0, [r2, 0xB]
	adds r0, 0x3
	str r0, [sp, 0x10]
	ldrb r0, [r2, 0xC]
	adds r0, 0x3
	str r0, [sp, 0x14]
	ldrb r0, [r2, 0xD]
	adds r0, 0x3
	str r0, [sp, 0x18]
	ldrb r0, [r2, 0xE]
	adds r0, 0x3
	str r0, [sp, 0x1C]
	ldrb r0, [r2, 0xF]
	adds r0, 0x3
	str r0, [sp, 0x20]
	adds r7, r1, 0
	ldr r3, [sp, 0x28]
	cmp r7, r3
	blt _0800AB8C
	b _0800AE14
_0800AB8C:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	beq _0800AB96
	cmp r6, r0
	bge _0800AB04
_0800AB96:
	mov r1, r9
	cmp r1, 0x8
	bne _0800ABAA
	mov r2, r8
	adds r0, r2, r7
	ldrb r0, [r0]
	mov r10, r0
	adds r7, 0x1
	movs r3, 0
	mov r9, r3
_0800ABAA:
	movs r0, 0x80
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _0800ABB6
	b _0800ADF0
_0800ABB6:
	mov r3, r8
	adds r2, r3, r7
	ldrb r1, [r2]
	lsrs r0, r1, 4
	adds r3, r0, 0x3
	movs r0, 0xF
	ands r0, r1
	lsls r5, r0, 8
	ldr r0, [sp]
	cmp r3, r0
	bne _0800ABCE
	movs r3, 0x1F
_0800ABCE:
	ldr r0, [sp, 0x4]
	cmp r3, r0
	bne _0800ABD6
	movs r3, 0x1E
_0800ABD6:
	ldr r0, [sp, 0x8]
	cmp r3, r0
	bne _0800ABDE
	movs r3, 0x1D
_0800ABDE:
	ldr r0, [sp, 0xC]
	cmp r3, r0
	bne _0800ABE6
	movs r3, 0x1C
_0800ABE6:
	ldr r0, [sp, 0x10]
	cmp r3, r0
	bne _0800ABEE
	movs r3, 0x1B
_0800ABEE:
	ldr r0, [sp, 0x14]
	cmp r3, r0
	bne _0800ABF6
	movs r3, 0x1A
_0800ABF6:
	ldr r0, [sp, 0x18]
	cmp r3, r0
	bne _0800ABFE
	movs r3, 0x19
_0800ABFE:
	ldr r0, [sp, 0x1C]
	cmp r3, r0
	bne _0800AC06
	movs r3, 0x18
_0800AC06:
	ldr r0, [sp, 0x20]
	cmp r3, r0
	bne _0800AC0E
	movs r3, 0x17
_0800AC0E:
	adds r0, r3, 0
	subs r0, 0x17
	cmp r0, 0x8
	bls _0800AC18
	b _0800ADB0
_0800AC18:
	lsls r0, 2
	ldr r1, _0800AC24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800AC24: .4byte _0800AC28
	.align 2, 0
_0800AC28:
	.4byte _0800AD7C
	.4byte _0800AD48
	.4byte _0800AD20
	.4byte _0800ACFA
	.4byte _0800ACD6
	.4byte _0800ACB4
	.4byte _0800AC8C
	.4byte _0800AC66
	.4byte _0800AC4C
_0800AC4C:
	ldrb r1, [r2]
	movs r0, 0xF
	adds r7, 0x1
	mov r3, r12
	adds r2, r3, r6
	ands r0, r1
	lsls r1, r0, 4
	orrs r1, r0
	strb r1, [r2]
	adds r6, 0x1
	adds r0, r3, r6
	strb r1, [r0]
	b _0800ADA4
_0800AC66:
	ldrb r0, [r2]
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r3, r1, r6
	movs r2, 0xF
	lsls r0, r5, 4
	adds r1, r5, 0x1
	ands r1, r2
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r2, r3, r6
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	b _0800ADA4
_0800AC8C:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r4, r1, r6
	adds r2, r5, 0
	ands r2, r3
	lsls r1, r2, 4
	subs r0, r5, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r6, 0x1
	mov r3, r12
	adds r0, r3, r6
	orrs r1, r2
	strb r1, [r0]
	b _0800ADA4
_0800ACB4:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r2, r1, r6
	adds r1, r5, 0
	ands r1, r3
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	mov r0, r12
	adds r2, r0, r6
	subs r0, r5, 0x1
	b _0800AD68
_0800ACD6:
	ldrb r0, [r2]
	movs r4, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r2, r12
	adds r3, r2, r6
	adds r1, r5, 0
	ands r1, r4
	lsls r2, r1, 4
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r1, r3, r6
	subs r0, r5, 0x1
	b _0800AD9E
_0800ACFA:
	ldrb r0, [r2]
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r3, r1, r6
	movs r2, 0xF
	lsls r0, r5, 4
	subs r1, r5, 0x1
	ands r1, r2
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r2, r3, r6
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	b _0800ADA4
_0800AD20:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r4, r1, r6
	adds r2, r5, 0
	ands r2, r3
	lsls r1, r2, 4
	adds r0, r5, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r6, 0x1
	mov r3, r12
	adds r0, r3, r6
	orrs r1, r2
	strb r1, [r0]
	b _0800ADA4
_0800AD48:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r2, r1, r6
	adds r1, r5, 0
	ands r1, r3
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	mov r0, r12
	adds r2, r0, r6
	adds r0, r5, 0x1
_0800AD68:
	ands r0, r3
	lsls r0, 4
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	mov r4, r9
	adds r4, 0x1
	mov r1, r10
	lsls r2, r1, 1
	b _0800AE08
_0800AD7C:
	ldrb r0, [r2]
	movs r4, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r2, r12
	adds r3, r2, r6
	adds r1, r5, 0
	ands r1, r4
	lsls r2, r1, 4
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r1, r3, r6
	adds r0, r5, 0x1
_0800AD9E:
	ands r0, r4
	orrs r2, r0
	strb r2, [r1]
_0800ADA4:
	adds r6, 0x1
	mov r4, r9
	adds r4, 0x1
	mov r0, r10
	lsls r2, r0, 1
	b _0800AE08
_0800ADB0:
	adds r7, 0x1
	mov r1, r8
	adds r0, r1, r7
	ldrb r0, [r0]
	adds r5, r0
	adds r7, 0x1
	ldr r2, _0800ADEC
	adds r0, r5, r2
	adds r5, r0, r6
	mov r4, r9
	adds r4, 0x1
	mov r0, r10
	lsls r2, r0, 1
	cmp r3, 0
	beq _0800AE08
_0800ADCE:
	mov r1, r12
	adds r1, r6
	mov r10, r1
	mov r0, r12
	adds r0, r5
	ldrb r1, [r0]
	mov r0, r10
	strb r1, [r0]
	adds r6, 0x1
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _0800ADCE
	b _0800AE08
	.align 2, 0
_0800ADEC: .4byte 0xfffff000
_0800ADF0:
	mov r1, r12
	adds r0, r1, r6
	mov r2, r8
	adds r1, r2, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	adds r7, 0x1
	mov r4, r9
	adds r4, 0x1
	mov r3, r10
	lsls r2, r3, 1
_0800AE08:
	mov r9, r4
	mov r10, r2
	ldr r0, [sp, 0x28]
	cmp r7, r0
	bge _0800AE14
	b _0800AB8C
_0800AE14:
	adds r0, r6, 0
_0800AE16:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800AAB4

	thumb_func_start sub_800AE28
sub_800AE28:
	push {lr}
	ldr r2, [r2, 0x4]
	bl sub_800AE34
	pop {r1}
	bx r1
	thumb_func_end sub_800AE28

	thumb_func_start sub_800AE34
sub_800AE34:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	str r1, [sp, 0x24]
	mov r10, r2
	ldrb r2, [r2, 0x5]
	mov r3, r10
	ldrb r1, [r3, 0x6]
	lsls r1, 8
	adds r2, r1
	str r2, [sp, 0x28]
	movs r1, 0
	mov r9, r1
	movs r2, 0
	str r2, [sp, 0x2C]
	movs r3, 0x8
	str r3, [sp, 0x30]
	bl sub_800B1BC
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800AE90
	ldrb r0, [r1, 0x1]
	adds r1, r0, 0
	cmp r1, 0x54
	bne _0800AE98
	mov r2, r10
	ldrb r0, [r2, 0x2]
	cmp r0, 0x34
	bne _0800AE98
	ldrb r0, [r2, 0x3]
	cmp r0, 0x50
	bne _0800AE98
	ldrb r1, [r2, 0x10]
	ldrb r0, [r2, 0x11]
	lsls r0, 8
	adds r1, r0
	ldr r3, [sp, 0x24]
	cmp r3, 0
	beq _0800AE94
	cmp r3, r1
	beq _0800AE94
_0800AE90:
	movs r0, 0
	b _0800B1AA
_0800AE94:
	movs r1, 0x12
	b _0800AEB2
_0800AE98:
	mov r2, r10
	ldrb r0, [r2]
	cmp r0, 0x41
	bne _0800AE90
	cmp r1, 0x54
	bne _0800AE90
	ldrb r0, [r2, 0x2]
	cmp r0, 0x33
	bne _0800AE90
	ldrb r0, [r2, 0x3]
	cmp r0, 0x50
	bne _0800AE90
	movs r1, 0x10
_0800AEB2:
	mov r3, r10
	ldrb r0, [r3, 0x4]
	cmp r0, 0x4E
	bne _0800AEE0
	movs r0, 0
	mov r8, r0
	ldr r1, [sp, 0x28]
	cmp r8, r1
	bge _0800AED8
_0800AEC4:
	mov r0, r8
	add r0, r10
	ldrb r0, [r0, 0x7]
	bl sub_800B220
	movs r2, 0x1
	add r8, r2
	ldr r3, [sp, 0x28]
	cmp r8, r3
	blt _0800AEC4
_0800AED8:
	bl sub_800B270
	mov r0, r8
	b _0800B1AA
_0800AEE0:
	mov r2, r10
	ldrb r0, [r2, 0x7]
	adds r0, 0x3
	str r0, [sp]
	ldrb r0, [r2, 0x8]
	adds r0, 0x3
	str r0, [sp, 0x4]
	ldrb r0, [r2, 0x9]
	adds r0, 0x3
	str r0, [sp, 0x8]
	ldrb r0, [r2, 0xA]
	adds r0, 0x3
	str r0, [sp, 0xC]
	ldrb r0, [r2, 0xB]
	adds r0, 0x3
	str r0, [sp, 0x10]
	ldrb r0, [r2, 0xC]
	adds r0, 0x3
	str r0, [sp, 0x14]
	ldrb r0, [r2, 0xD]
	adds r0, 0x3
	str r0, [sp, 0x18]
	ldrb r0, [r2, 0xE]
	adds r0, 0x3
	str r0, [sp, 0x1C]
	ldrb r0, [r2, 0xF]
	adds r0, 0x3
	str r0, [sp, 0x20]
	mov r8, r1
	ldr r3, [sp, 0x28]
	cmp r8, r3
	blt _0800AF22
	b _0800B1A4
_0800AF22:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	beq _0800AF2C
	cmp r9, r0
	bge _0800AE90
_0800AF2C:
	ldr r1, [sp, 0x30]
	cmp r1, 0x8
	bne _0800AF42
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	str r0, [sp, 0x2C]
	movs r2, 0x1
	add r8, r2
	movs r3, 0
	str r3, [sp, 0x30]
_0800AF42:
	movs r0, 0x80
	ldr r1, [sp, 0x2C]
	ands r0, r1
	cmp r0, 0
	beq _0800AF4E
	b _0800B180
_0800AF4E:
	mov r2, r10
	add r2, r8
	ldrb r1, [r2]
	lsrs r0, r1, 4
	adds r3, r0, 0x3
	movs r0, 0xF
	ands r0, r1
	lsls r7, r0, 8
	ldr r0, [sp]
	cmp r3, r0
	bne _0800AF66
	movs r3, 0x1F
_0800AF66:
	ldr r0, [sp, 0x4]
	cmp r3, r0
	bne _0800AF6E
	movs r3, 0x1E
_0800AF6E:
	ldr r0, [sp, 0x8]
	cmp r3, r0
	bne _0800AF76
	movs r3, 0x1D
_0800AF76:
	ldr r0, [sp, 0xC]
	cmp r3, r0
	bne _0800AF7E
	movs r3, 0x1C
_0800AF7E:
	ldr r0, [sp, 0x10]
	cmp r3, r0
	bne _0800AF86
	movs r3, 0x1B
_0800AF86:
	ldr r0, [sp, 0x14]
	cmp r3, r0
	bne _0800AF8E
	movs r3, 0x1A
_0800AF8E:
	ldr r0, [sp, 0x18]
	cmp r3, r0
	bne _0800AF96
	movs r3, 0x19
_0800AF96:
	ldr r0, [sp, 0x1C]
	cmp r3, r0
	bne _0800AF9E
	movs r3, 0x18
_0800AF9E:
	ldr r0, [sp, 0x20]
	cmp r3, r0
	bne _0800AFA6
	movs r3, 0x17
_0800AFA6:
	adds r0, r3, 0
	subs r0, 0x17
	cmp r0, 0x8
	bls _0800AFB0
	b _0800B13C
_0800AFB0:
	lsls r0, 2
	ldr r1, _0800AFBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800AFBC: .4byte _0800AFC0
	.align 2, 0
_0800AFC0:
	.4byte _0800B104
	.4byte _0800B0DE
	.4byte _0800B0BA
	.4byte _0800B090
	.4byte _0800B06E
	.4byte _0800B048
	.4byte _0800B024
	.4byte _0800AFFE
	.4byte _0800AFE4
_0800AFE4:
	ldrb r0, [r2]
	movs r1, 0xF
	movs r2, 0x1
	add r8, r2
	ands r1, r0
	lsls r4, r1, 4
	orrs r4, r1
	adds r0, r4, 0
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	b _0800B128
_0800AFFE:
	ldrb r0, [r2]
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	movs r1, 0xF
	lsls r0, r6, 4
	adds r4, r6, 0x1
	ands r4, r1
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	lsls r0, r4, 4
	orrs r0, r4
	lsls r0, 24
	lsrs r0, 24
	b _0800B12A
_0800B024:
	ldrb r0, [r2]
	movs r1, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r5, r6, 0
	ands r5, r1
	lsls r4, r5, 4
	subs r0, r6, 0x1
	ands r0, r1
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	orrs r4, r5
	b _0800B128
_0800B048:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r4, r6, 0
	ands r4, r5
	lsls r0, r4, 4
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	subs r0, r6, 0x1
	ands r0, r5
	lsls r0, 4
	orrs r0, r4
	b _0800B12A
_0800B06E:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r1, r6, 0
	ands r1, r5
	lsls r4, r1, 4
	adds r0, r4, 0
	orrs r0, r1
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	subs r0, r6, 0x1
	b _0800B124
_0800B090:
	ldrb r0, [r2]
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	movs r1, 0xF
	lsls r0, r6, 4
	subs r4, r6, 0x1
	ands r4, r1
	orrs r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	lsls r0, r4, 4
	orrs r0, r4
	lsls r0, 24
	lsrs r0, 24
	b _0800B12A
_0800B0BA:
	ldrb r0, [r2]
	movs r1, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r5, r6, 0
	ands r5, r1
	lsls r4, r5, 4
	adds r0, r6, 0x1
	ands r0, r1
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	orrs r4, r5
	b _0800B128
_0800B0DE:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r4, r6, 0
	ands r4, r5
	lsls r0, r4, 4
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	adds r0, r6, 0x1
	ands r0, r5
	lsls r0, 4
	orrs r0, r4
	b _0800B12A
_0800B104:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r1, r6, 0
	ands r1, r5
	lsls r4, r1, 4
	adds r0, r4, 0
	orrs r0, r1
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	adds r0, r6, 0x1
_0800B124:
	ands r0, r5
	orrs r4, r0
_0800B128:
	adds r0, r4, 0
_0800B12A:
	bl sub_800B220
	movs r0, 0x1
	add r9, r0
	ldr r5, [sp, 0x30]
	adds r5, 0x1
	ldr r1, [sp, 0x2C]
	lsls r4, r1, 1
	b _0800B198
_0800B13C:
	movs r2, 0x1
	add r8, r2
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	adds r7, r0
	add r8, r2
	ldr r1, _0800B17C
	adds r0, r7, r1
	mov r2, r9
	adds r7, r0, r2
	ldr r5, [sp, 0x30]
	adds r5, 0x1
	ldr r0, [sp, 0x2C]
	lsls r4, r0, 1
	cmp r3, 0
	beq _0800B198
	adds r6, r3, 0
_0800B160:
	adds r0, r7, 0
	bl sub_800B1E0
	lsls r0, 24
	lsrs r0, 24
	bl sub_800B220
	movs r1, 0x1
	add r9, r1
	adds r7, 0x1
	subs r6, 0x1
	cmp r6, 0
	bne _0800B160
	b _0800B198
	.align 2, 0
_0800B17C: .4byte 0xfffff000
_0800B180:
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	bl sub_800B220
	movs r2, 0x1
	add r9, r2
	add r8, r2
	ldr r5, [sp, 0x30]
	adds r5, 0x1
	ldr r3, [sp, 0x2C]
	lsls r4, r3, 1
_0800B198:
	str r5, [sp, 0x30]
	str r4, [sp, 0x2C]
	ldr r0, [sp, 0x28]
	cmp r8, r0
	bge _0800B1A4
	b _0800AF22
_0800B1A4:
	bl sub_800B270
	mov r0, r9
_0800B1AA:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800AE34

	thumb_func_start sub_800B1BC
sub_800B1BC:
	ldr r1, _0800B1D0
	str r0, [r1]
	ldr r1, _0800B1D4
	str r0, [r1]
	ldr r0, _0800B1D8
	movs r1, 0
	str r1, [r0]
	ldr r0, _0800B1DC
	str r1, [r0]
	bx lr
	.align 2, 0
_0800B1D0: .4byte gUnknown_202D4A8
_0800B1D4: .4byte gUnknown_202D4AC
_0800B1D8: .4byte gUnknown_202D4B0
_0800B1DC: .4byte gUnknown_202D4B4
	thumb_func_end sub_800B1BC

	thumb_func_start sub_800B1E0
sub_800B1E0:
	push {lr}
	adds r2, r0, 0
	cmp r2, 0
	bge _0800B1EA
	adds r0, r2, 0x3
_0800B1EA:
	asrs r0, 2
	ldr r1, _0800B20C
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x3
	ands r1, r2
	cmp r1, 0x1
	beq _0800B210
	cmp r1, 0x1
	ble _0800B216
	cmp r1, 0x2
	beq _0800B214
	cmp r1, 0x3
	beq _0800B218
	b _0800B216
	.align 2, 0
_0800B20C: .4byte gUnknown_202D4AC
_0800B210:
	lsrs r0, 8
	b _0800B216
_0800B214:
	lsrs r0, 16
_0800B216:
	lsls r0, 24
_0800B218:
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_800B1E0

	thumb_func_start sub_800B220
sub_800B220:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, _0800B260
	ldr r2, _0800B264
	ldr r3, _0800B268
	ldr r1, [r3]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	lsls r0, r1
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	ldr r2, _0800B26C
	ldr r0, [r2]
	str r1, [r0]
	ldr r0, [r3]
	adds r0, 0x1
	str r0, [r3]
	cmp r0, 0x4
	bne _0800B258
	ldr r0, [r2]
	adds r0, 0x4
	str r0, [r2]
	movs r0, 0
	str r0, [r4]
	str r0, [r3]
_0800B258:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B260: .4byte gUnknown_202D4B0
_0800B264: .4byte gUnknown_80B9BB8
_0800B268: .4byte gUnknown_202D4B4
_0800B26C: .4byte gUnknown_202D4A8
	thumb_func_end sub_800B220

	thumb_func_start sub_800B270
sub_800B270:
	push {lr}
	ldr r0, _0800B288
	ldr r0, [r0]
	cmp r0, 0
	beq _0800B284
	ldr r0, _0800B28C
	ldr r1, [r0]
	ldr r0, _0800B290
	ldr r0, [r0]
	str r0, [r1]
_0800B284:
	pop {r0}
	bx r0
	.align 2, 0
_0800B288: .4byte gUnknown_202D4B4
_0800B28C: .4byte gUnknown_202D4A8
_0800B290: .4byte gUnknown_202D4B0
	thumb_func_end sub_800B270

	thumb_func_start sub_800B294
sub_800B294:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800B2CC
	ldrb r0, [r1, 0x1]
	adds r2, r0, 0
	cmp r2, 0x54
	bne _0800B2B2
	ldrb r0, [r1, 0x2]
	cmp r0, 0x34
	bne _0800B2B2
	ldrb r0, [r1, 0x3]
	cmp r0, 0x50
	beq _0800B2C8
_0800B2B2:
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800B2CC
	cmp r2, 0x54
	bne _0800B2CC
	ldrb r0, [r1, 0x2]
	cmp r0, 0x33
	bne _0800B2CC
	ldrb r0, [r1, 0x3]
	cmp r0, 0x50
	bne _0800B2CC
_0800B2C8:
	movs r0, 0x1
	b _0800B2CE
_0800B2CC:
	movs r0, 0
_0800B2CE:
	pop {r1}
	bx r1
	thumb_func_end sub_800B294

	thumb_func_start sub_800B2D4
sub_800B2D4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r2, 0
	cmp r2, r4
	bge _0800B324
_0800B2E2:
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r1, 0
	subs r0, 0x41
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _0800B2FE
	adds r0, r1, 0
	adds r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_0800B2FE:
	adds r0, r3, 0
	subs r0, 0x41
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _0800B312
	adds r0, r3, 0
	adds r0, 0x20
	lsls r0, 24
	lsrs r3, r0, 24
_0800B312:
	cmp r1, r3
	beq _0800B31A
	movs r0, 0x1
	b _0800B326
_0800B31A:
	cmp r1, 0
	beq _0800B324
	adds r2, 0x1
	cmp r2, r4
	blt _0800B2E2
_0800B324:
	movs r0, 0
_0800B326:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800B2D4

	.align 2, 0 @ Don't pad with nop.
