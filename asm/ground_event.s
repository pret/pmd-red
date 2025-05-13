	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



	thumb_func_start sub_80ADFB8
sub_80ADFB8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	ldr r4, [sp, 0x5C]
	movs r7, 0
	ldr r0, [sp, 0x50]
	str r0, [sp]
	ldr r1, [sp, 0x54]
	str r1, [sp, 0x4]
	mov r0, r9
	mov r1, r10
	bl sub_80ADF8C
	str r0, [sp, 0x28]
	cmp r4, 0x3F
	ble _080AE000
	mov r0, r9
	cmp r0, 0x17
	bgt _080ADFFC
	mov r1, r10
	cmp r1, 0x17
	bgt _080ADFFC
	lsls r0, r1, 1
	add r0, r10
	lsls r0, 3
	add r0, r9
	b _080AE24E
_080ADFFC:
	ldr r0, [sp, 0x54]
	b _080AE254
_080AE000:
	mov r0, r10
	adds r0, 0x1
	str r0, [sp, 0x2C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x8]
	mov r4, r9
	adds r4, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0xC]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x10]
	mov r5, r10
	subs r5, 0x1
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x14]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	mov r0, r9
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x18]
	subs r4, 0x2
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x1C]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r10
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x50]
	str r1, [sp]
	ldr r0, [sp, 0x54]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	ldr r1, [sp, 0x2C]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80ADF8C
	adds r1, r0, 0
	str r1, [sp, 0x24]
	ldr r0, [sp, 0x28]
	cmp r0, 0x1
	bne _080AE12A
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE0D2
	movs r7, 0xFE
_080AE0D2:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE0DE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE0DE:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE0EA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE0EA:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE0F6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE0F6:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE102
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE102:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE10E
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE10E:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE11A
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE11A:
	cmp r1, 0
	bne _080AE124
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE124:
	movs r0, 0x80
	lsls r0, 2
	b _080AE248
_080AE12A:
	ldr r0, [sp, 0x28]
	cmp r0, 0x2
	bne _080AE192
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x2
	beq _080AE13A
	movs r7, 0xFE
_080AE13A:
	ldr r0, [sp, 0xC]
	cmp r0, 0x2
	beq _080AE146
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE146:
	ldr r0, [sp, 0x10]
	cmp r0, 0x2
	beq _080AE152
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE152:
	ldr r0, [sp, 0x14]
	cmp r0, 0x2
	beq _080AE15E
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE15E:
	ldr r0, [sp, 0x18]
	cmp r0, 0x2
	beq _080AE16A
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE16A:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x2
	beq _080AE176
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE176:
	ldr r0, [sp, 0x20]
	cmp r0, 0x2
	beq _080AE182
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE182:
	cmp r1, 0x2
	beq _080AE18C
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE18C:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE192:
	ldr r1, [sp, 0x28]
	cmp r1, 0x3
	bne _080AE1FC
	movs r7, 0xFF
	ldr r0, [sp, 0x8]
	cmp r0, 0x3
	beq _080AE1A2
	movs r7, 0xFE
_080AE1A2:
	ldr r0, [sp, 0xC]
	cmp r0, 0x3
	beq _080AE1AE
	movs r0, 0x3
	negs r0, r0
	ands r7, r0
_080AE1AE:
	ldr r0, [sp, 0x10]
	cmp r0, 0x3
	beq _080AE1BA
	movs r0, 0x5
	negs r0, r0
	ands r7, r0
_080AE1BA:
	ldr r0, [sp, 0x14]
	cmp r0, 0x3
	beq _080AE1C6
	movs r0, 0x9
	negs r0, r0
	ands r7, r0
_080AE1C6:
	ldr r0, [sp, 0x18]
	cmp r0, 0x3
	beq _080AE1D2
	movs r0, 0x11
	negs r0, r0
	ands r7, r0
_080AE1D2:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x3
	beq _080AE1DE
	movs r0, 0x21
	negs r0, r0
	ands r7, r0
_080AE1DE:
	ldr r0, [sp, 0x20]
	cmp r0, 0x3
	beq _080AE1EA
	movs r0, 0x41
	negs r0, r0
	ands r7, r0
_080AE1EA:
	ldr r0, [sp, 0x24]
	cmp r0, 0x3
	beq _080AE1F6
	movs r0, 0x81
	negs r0, r0
	ands r7, r0
_080AE1F6:
	movs r0, 0x80
	lsls r0, 1
	b _080AE248
_080AE1FC:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _080AE204
	movs r7, 0x1
_080AE204:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080AE20E
	movs r0, 0x2
	orrs r7, r0
_080AE20E:
	ldr r0, [sp, 0x10]
	cmp r0, 0
	bne _080AE218
	movs r0, 0x4
	orrs r7, r0
_080AE218:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _080AE222
	movs r0, 0x8
	orrs r7, r0
_080AE222:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _080AE22C
	movs r0, 0x10
	orrs r7, r0
_080AE22C:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _080AE236
	movs r0, 0x20
	orrs r7, r0
_080AE236:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	bne _080AE240
	movs r0, 0x40
	orrs r7, r0
_080AE240:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	bne _080AE24A
	movs r0, 0x80
_080AE248:
	orrs r7, r0
_080AE24A:
	lsls r0, r7, 1
	adds r0, r7
_080AE24E:
	ldr r1, [sp, 0x58]
	adds r0, r1, r0
	ldrb r0, [r0]
_080AE254:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80ADFB8

        .align 2,0
