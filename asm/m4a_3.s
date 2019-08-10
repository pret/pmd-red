	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/m4a_constants.inc"

	.syntax unified

	.text

	thumb_func_start CgbSound
CgbSound:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, =SOUND_INFO_PTR
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _080AFB00
	subs r0, 0x1
	ldr r1, [sp, 0x4]
	strb r0, [r1, 0xA]
	b _080AFB06
	.pool
_080AFB00:
	movs r0, 0xE
	ldr r2, [sp, 0x4]
	strb r0, [r2, 0xA]
_080AFB06:
	movs r6, 0x1
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
_080AFB0C:
	ldrb r1, [r4]
	movs r0, 0xC7
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	bne _080AFB22
	b _080AFF0C
_080AFB22:
	cmp r6, 0x2
	beq _080AFB54
	cmp r6, 0x2
	bgt _080AFB30
	cmp r6, 0x1
	beq _080AFB36
	b _080AFB8C
_080AFB30:
	cmp r6, 0x3
	beq _080AFB6C
	b _080AFB8C
_080AFB36:
	ldr r0, =REG_NR10
	str r0, [sp, 0x8]
	ldr r7, =REG_NR11
	ldr r2, =REG_NR12
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _080AFB9C
	.pool
_080AFB54:
	ldr r0, =REG_NR10 + 1
	str r0, [sp, 0x8]
	ldr r7, =REG_NR21
	ldr r2, =REG_NR22
	b _080AFB94
	.pool
_080AFB6C:
	ldr r0, =REG_NR30
	str r0, [sp, 0x8]
	ldr r7, =REG_NR31
	ldr r2, =REG_NR32
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _080AFB9C
	.pool
_080AFB8C:
	ldr r0, =REG_NR30 + 1
	str r0, [sp, 0x8]
	ldr r7, =REG_NR41
	ldr r2, =REG_NR42
_080AFB94:
	str r2, [sp, 0xC]
	adds r0, 0xB
	str r0, [sp, 0x10]
	adds r2, 0x4
_080AFB9C:
	str r2, [sp, 0x14]
	ldr r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	str r0, [sp]
	ldr r2, [sp, 0xC]
	ldrb r0, [r2]
	mov r8, r0
	adds r2, r1, 0
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _080AFC92
	movs r3, 0x40
	adds r0, r3, 0
	ands r0, r2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0x1
	mov r10, r0
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r5, 0
	bne _080AFCB6
	movs r0, 0x3
	strb r0, [r4]
	strb r0, [r4, 0x1D]
	adds r0, r4, 0
	str r3, [sp, 0x18]
	bl CgbModVol
	ldr r3, [sp, 0x18]
	cmp r6, 0x2
	beq _080AFC04
	cmp r6, 0x2
	bgt _080AFBF8
	cmp r6, 0x1
	beq _080AFBFE
	b _080AFC58
	.pool
_080AFBF8:
	cmp r6, 0x3
	beq _080AFC10
	b _080AFC58
_080AFBFE:
	ldrb r0, [r4, 0x1F]
	ldr r2, [sp, 0x8]
	strb r0, [r2]
_080AFC04:
	ldr r0, [r4, 0x24]
	lsls r0, 6
	ldrb r1, [r4, 0x1E]
	adds r0, r1, r0
	strb r0, [r7]
	b _080AFC64
_080AFC10:
	ldr r1, [r4, 0x24]
	ldr r0, [r4, 0x28]
	cmp r1, r0
	beq _080AFC38
	ldr r2, [sp, 0x8]
	strb r3, [r2]
	ldr r1, =REG_WAVE_RAM
	ldr r2, [r4, 0x24]
	ldr r0, [r2]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x8]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0xC]
	str r0, [r1]
	str r2, [r4, 0x28]
_080AFC38:
	ldr r0, [sp, 0x8]
	strb r5, [r0]
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _080AFC50
	movs r0, 0xC0
	b _080AFC72
	.pool
_080AFC50:
	movs r1, 0x80
	negs r1, r1
	strb r1, [r4, 0x1A]
	b _080AFC74
_080AFC58:
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldr r0, [r4, 0x24]
	lsls r0, 3
	ldr r2, [sp, 0x10]
	strb r0, [r2]
_080AFC64:
	ldrb r0, [r4, 0x4]
	adds r0, 0x8
	mov r8, r0
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _080AFC72
	movs r0, 0x40
_080AFC72:
	strb r0, [r4, 0x1A]
_080AFC74:
	ldrb r1, [r4, 0x4]
	movs r2, 0
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	adds r1, r6, 0x1
	mov r10, r1
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r0, 0
	bne _080AFC8E
	b _080AFDCA
_080AFC8E:
	strb r2, [r4, 0x9]
	b _080AFDF8
_080AFC92:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _080AFCC4
	ldrb r0, [r4, 0xD]
	subs r0, 0x1
	strb r0, [r4, 0xD]
	movs r2, 0xFF
	ands r0, r2
	lsls r0, 24
	adds r1, r6, 0x1
	mov r10, r1
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	ble _080AFCB6
	b _080AFE0A
_080AFCB6:
	lsls r0, r6, 24
	lsrs r0, 24
	bl CgbOscOff
	movs r0, 0
	strb r0, [r4]
	b _080AFF08
_080AFCC4:
	movs r0, 0x40
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	beq _080AFD04
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080AFD04
	movs r0, 0xFC
	ands r0, r1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x7]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _080AFD36
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _080AFDF8
	ldrb r2, [r4, 0x7]
	mov r8, r2
	b _080AFDF8
_080AFD04:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _080AFDF8
	cmp r6, 0x3
	bne _080AFD16
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
_080AFD16:
	adds r0, r4, 0
	bl CgbModVol
	movs r0, 0x3
	ldrb r2, [r4]
	ands r0, r2
	cmp r0, 0
	bne _080AFD6A
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	cmp r0, 0
	bgt _080AFD66
_080AFD36:
	ldrb r2, [r4, 0xC]
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	muls r0, r1
	adds r0, 0xFF
	asrs r0, 8
	movs r1, 0
	strb r0, [r4, 0x9]
	lsls r0, 24
	cmp r0, 0
	beq _080AFCB6
	movs r0, 0x4
	ldrb r2, [r4]
	orrs r0, r2
	strb r0, [r4]
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _080AFE0A
	movs r2, 0x8
	mov r8, r2
	b _080AFE0A
_080AFD66:
	ldrb r0, [r4, 0x7]
	b _080AFDF6
_080AFD6A:
	cmp r0, 0x1
	bne _080AFD76
_080AFD6E:
	ldrb r0, [r4, 0x19]
	strb r0, [r4, 0x9]
	movs r0, 0x7
	b _080AFDF6
_080AFD76:
	cmp r0, 0x2
	bne _080AFDBA
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	ldrb r2, [r4, 0x19]
	lsls r1, r2, 24
	cmp r0, r1
	bgt _080AFDB6
_080AFD8E:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _080AFD9E
	movs r0, 0xFC
	ldrb r1, [r4]
	ands r0, r1
	strb r0, [r4]
	b _080AFD36
_080AFD9E:
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	orrs r0, r2
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _080AFD6E
	movs r0, 0x8
	mov r8, r0
	b _080AFD6E
_080AFDB6:
	ldrb r0, [r4, 0x5]
	b _080AFDF6
_080AFDBA:
	ldrb r0, [r4, 0x9]
	adds r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	ldrb r2, [r4, 0xA]
	cmp r0, r2
	bcc _080AFDF4
_080AFDCA:
	ldrb r0, [r4]
	subs r0, 0x1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x5]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _080AFD8E
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	cmp r6, 0x3
	beq _080AFDF8
	ldrb r2, [r4, 0x5]
	mov r8, r2
	b _080AFDF8
_080AFDF4:
	ldrb r0, [r4, 0x4]
_080AFDF6:
	strb r0, [r4, 0xB]
_080AFDF8:
	ldrb r0, [r4, 0xB]
	subs r0, 0x1
	strb r0, [r4, 0xB]
	ldr r0, [sp]
	cmp r0, 0
	bne _080AFE0A
	subs r0, 0x1
	str r0, [sp]
	b _080AFD04
_080AFE0A:
	movs r0, 0x2
	ldrb r1, [r4, 0x1D]
	ands r0, r1
	cmp r0, 0
	beq _080AFE82
	cmp r6, 0x3
	bgt _080AFE4A
	movs r0, 0x8
	ldrb r2, [r4, 0x1]
	ands r0, r2
	cmp r0, 0
	beq _080AFE4A
	ldr r0, =REG_SOUNDBIAS + 1
	ldrb r0, [r0]
	cmp r0, 0x3F
	bgt _080AFE3C
	ldr r0, [r4, 0x20]
	adds r0, 0x2
	ldr r1, =0x000007fc
	b _080AFE46
	.pool
_080AFE3C:
	cmp r0, 0x7F
	bgt _080AFE4A
	ldr r0, [r4, 0x20]
	adds r0, 0x1
	ldr r1, =0x000007fe
_080AFE46:
	ands r0, r1
	str r0, [r4, 0x20]
_080AFE4A:
	cmp r6, 0x4
	beq _080AFE5C
	ldr r0, [r4, 0x20]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	b _080AFE6A
	.pool
_080AFE5C:
	ldr r2, [sp, 0x10]
	ldrb r0, [r2]
	movs r1, 0x8
	ands r1, r0
	ldr r0, [r4, 0x20]
	orrs r0, r1
	strb r0, [r2]
_080AFE6A:
	movs r0, 0xC0
	ldrb r1, [r4, 0x1A]
	ands r0, r1
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r0, r1, r0
	strb r0, [r4, 0x1A]
	movs r2, 0xFF
	ands r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_080AFE82:
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	ands r0, r2
	cmp r0, 0
	beq _080AFF08
	ldr r1, =REG_NR51
	ldrb r0, [r1]
	ldrb r2, [r4, 0x1C]
	bics r0, r2
	ldrb r2, [r4, 0x1B]
	orrs r0, r2
	strb r0, [r1]
	cmp r6, 0x3
	bne _080AFED4
	ldr r0, =gCgb3Vol
	ldrb r1, [r4, 0x9]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, [sp, 0xC]
	strb r0, [r2]
	movs r1, 0x80
	adds r0, r1, 0
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	cmp r0, 0
	beq _080AFF08
	ldr r0, [sp, 0x8]
	strb r1, [r0]
	ldrb r0, [r4, 0x1A]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	movs r0, 0x7F
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	strb r0, [r4, 0x1A]
	b _080AFF08
	.pool
_080AFED4:
	movs r0, 0xF
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrb r2, [r4, 0x9]
	lsls r0, r2, 4
	add r0, r8
	ldr r1, [sp, 0xC]
	strb r0, [r1]
	movs r2, 0x80
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	cmp r6, 0x1
	bne _080AFF08
	ldr r0, [sp, 0x8]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080AFF08
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_080AFF08:
	movs r0, 0
	strb r0, [r4, 0x1D]
_080AFF0C:
	mov r6, r10
	mov r4, r9
	cmp r6, 0x4
	bgt _080AFF16
	b _080AFB0C
_080AFF16:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CgbSound

	.align 2, 0 @ Don't pad with nop.
