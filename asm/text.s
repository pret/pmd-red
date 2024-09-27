	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text



	thumb_func_start CallPrepareTextbox_8008C54
CallPrepareTextbox_8008C54:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08008C64
	bl PrepareTextbox_8008C6C
	pop {r0}
	bx r0
	.align 2, 0
_08008C64: .4byte gUnknown_2027370
	thumb_func_end CallPrepareTextbox_8008C54

	thumb_func_start nullsub_169
nullsub_169:
	bx lr
	thumb_func_end nullsub_169

	thumb_func_start PrepareTextbox_8008C6C
PrepareTextbox_8008C6C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r0
	mov r8, r1
	lsls r0, r1, 3
	add r0, r8
	lsls r0, 3
	mov r1, r9
	adds r6, r1, r0
	adds r0, r6, 0
	adds r0, 0x45
	ldrb r0, [r0]
	cmp r0, 0
	bne _08008CBE
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	movs r7, 0x8
	ldrsh r1, [r6, r7]
	muls r0, r1
	lsls r4, r0, 5
	movs r5, 0
	movs r0, 0x44
	adds r0, r6
	mov r10, r0
	cmp r5, r4
	bge _08008D1E
_08008CA8:
	lsrs r1, r5, 2
	lsls r1, 2
	ldr r0, [r6, 0x18]
	adds r0, r1
	movs r1, 0x20
	bl CpuClear
	adds r5, 0x20
	cmp r5, r4
	blt _08008CA8
	b _08008D1E
_08008CBE:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	movs r2, 0x8
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	muls r1, r0
	lsls r1, 5
	str r1, [sp, 0x8]
	ldr r4, [r6, 0x18]
	movs r5, 0
	movs r7, 0x44
	adds r7, r6
	mov r10, r7
	cmp r5, r0
	bge _08008D04
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r1, 0
	ldr r3, _08008D84
	ldr r2, _08008D88
_08008CE8:
	mov r7, r12
	stm r4!, {r7}
	stm r4!, {r3}
	stm r4!, {r2}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	adds r5, 0x1
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r5, r0
	blt _08008CE8
_08008D04:
	movs r5, 0
	ldr r0, [sp, 0x8]
	cmp r5, r0
	bge _08008D1E
_08008D0C:
	adds r0, r4, 0
	movs r1, 0x20
	bl CpuClear
	adds r4, 0x20
	adds r5, 0x20
	ldr r1, [sp, 0x8]
	cmp r5, r1
	blt _08008D0C
_08008D1E:
	ldr r0, [r6, 0xC]
	cmp r0, 0x6
	bne _08008D60
	adds r5, r6, 0
	adds r5, 0x46
	movs r4, 0
	movs r0, 0x1
	strb r0, [r5]
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	lsls r0, 3
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r2, 0
	movs r3, 0xA
	bl sub_8007958
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	lsls r0, 3
	str r0, [sp]
	movs r0, 0xD
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r2, 0
	movs r3, 0xB
	bl sub_8007958
	strb r4, [r5]
_08008D60:
	ldr r0, [r6, 0x28]
	str r0, [r6, 0x30]
	ldr r0, [r6, 0x1C]
	str r0, [r6, 0x34]
	ldr r0, [r6, 0x2C]
	str r0, [r6, 0x38]
	movs r0, 0x1
	mov r1, r10
	strb r0, [r1]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008D84: .4byte 0xeeeeeeee
_08008D88: .4byte 0xdddddddd
	thumb_func_end PrepareTextbox_8008C6C

	thumb_func_start sub_8008D8C
sub_8008D8C:
	push {lr}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08008DA4
	adds r1, r0
	ldr r0, [r1, 0x38]
	cmp r0, 0
	beq _08008DA0
	movs r0, 0x1
_08008DA0:
	pop {r1}
	bx r1
	.align 2, 0
_08008DA4: .4byte gUnknown_2027370
	thumb_func_end sub_8008D8C

	thumb_func_start sub_8008DA8
sub_8008DA8:
	movs r0, 0
	bx lr
	thumb_func_end sub_8008DA8

	thumb_func_start sub_8008DAC
sub_8008DAC:
	ldr r3, _08008DC0
	lsls r0, 1
	lsls r1, 6
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	ldr r1, _08008DC4
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08008DC0: .4byte gUnknown_202B038
_08008DC4: .4byte gUnknown_20274A5
	thumb_func_end sub_8008DAC

	thumb_func_start sub_8008DC8
sub_8008DC8:
	push {r4,lr}
	ldr r4, _08008DEC
	lsls r0, 1
	lsls r1, 6
	adds r0, r1
	adds r1, r0, r4
	strh r2, [r1]
	movs r1, 0x80
	lsls r1, 4
	adds r4, r1
	adds r0, r4
	strh r3, [r0]
	ldr r1, _08008DF0
	movs r0, 0x1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008DEC: .4byte gUnknown_202B038
_08008DF0: .4byte gUnknown_20274A5
	thumb_func_end sub_8008DC8

	thumb_func_start sub_8008DF4
sub_8008DF4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldrb r0, [r3]
	ldr r1, _08008E4C
	mov r12, r1
	cmp r0, 0
	beq _08008E3E
	ldr r6, _08008E50
_08008E08:
	ldrb r1, [r3]
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _08008E1E
	adds r0, r1, 0
	subs r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_08008E1E:
	lsls r2, r4, 1
	lsls r0, r5, 6
	adds r2, r0
	adds r2, r6
	movs r7, 0x96
	lsls r7, 2
	adds r0, r1, r7
	ldr r7, _08008E54
	adds r1, r7, 0
	orrs r0, r1
	strh r0, [r2]
	adds r3, 0x1
	adds r4, 0x1
	ldrb r0, [r3]
	cmp r0, 0
	bne _08008E08
_08008E3E:
	movs r0, 0x1
	mov r1, r12
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008E4C: .4byte gUnknown_20274A5
_08008E50: .4byte gUnknown_202B038
_08008E54: .4byte 0xfffff000
	thumb_func_end sub_8008DF4

	thumb_func_start sub_8008E58
sub_8008E58:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r1
	adds r4, r2, 0
	ldrb r0, [r4]
	ldr r7, _08008EC4
	cmp r0, 0
	beq _08008EB4
	adds r1, r0, 0
	cmp r3, 0
	beq _08008EB4
	ldr r0, _08008EC8
	mov r12, r0
_08008E76:
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _08008E8A
	adds r0, r1, 0
	subs r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_08008E8A:
	lsls r2, r5, 1
	mov r6, r8
	lsls r0, r6, 6
	adds r2, r0
	add r2, r12
	movs r6, 0x96
	lsls r6, 2
	adds r0, r1, r6
	ldr r6, _08008ECC
	adds r1, r6, 0
	orrs r0, r1
	strh r0, [r2]
	adds r4, 0x1
	adds r5, 0x1
	subs r3, 0x1
	ldrb r0, [r4]
	cmp r0, 0
	beq _08008EB4
	adds r1, r0, 0
	cmp r3, 0
	bne _08008E76
_08008EB4:
	movs r0, 0x1
	strb r0, [r7]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008EC4: .4byte gUnknown_20274A5
_08008EC8: .4byte gUnknown_202B038
_08008ECC: .4byte 0xfffff000
	thumb_func_end sub_8008E58

	thumb_func_start sub_8008ED0
sub_8008ED0:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r5, 0
	b _08008F64
_08008EDA:
	ldr r0, _08008F18
	cmp r1, r0
	beq _08008F64
	adds r0, 0x2
	cmp r1, r0
	beq _08008F64
	cmp r1, 0x1B
	beq _08008F7E
	cmp r1, 0x23
	bne _08008F44
	ldrb r0, [r2]
	cmp r0, 0x6E
	beq _08008F7E
	cmp r0, 0x5B
	beq _08008F7E
	cmp r0, 0x50
	beq _08008F7E
	cmp r0, 0x57
	beq _08008F40
	cmp r0, 0x57
	bgt _08008F22
	cmp r0, 0x43
	beq _08008F38
	cmp r0, 0x43
	bgt _08008F1C
	cmp r0, 0x2B
	beq _08008F40
	cmp r0, 0x3D
	beq _08008F34
	b _08008F64
	.align 2, 0
_08008F18: .4byte 0x000082a0
_08008F1C:
	cmp r0, 0x52
	beq _08008F3C
	b _08008F64
_08008F22:
	cmp r0, 0x72
	beq _08008F3C
	cmp r0, 0x72
	bgt _08008F30
	cmp r0, 0x63
	beq _08008F38
	b _08008F64
_08008F30:
	cmp r0, 0x7E
	bne _08008F64
_08008F34:
	adds r4, r2, 0x2
	b _08008F64
_08008F38:
	adds r4, 0x2
	b _08008F64
_08008F3C:
	adds r4, 0x1
	b _08008F64
_08008F40:
	adds r4, r2, 0x1
	b _08008F64
_08008F44:
	cmp r1, 0x60
	bne _08008F4C
	adds r5, 0x6
	b _08008F64
_08008F4C:
	adds r0, r1, 0
	bl GetCharacter
	cmp r0, 0
	beq _08008F64
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	ldr r1, _08008F88
	movs r2, 0
	ldrsh r1, [r1, r2]
	adds r0, r1
	adds r5, r0
_08008F64:
	adds r0, r4, 0
	mov r1, sp
	bl xxx_get_next_char_from_string
	adds r2, r0, 0
	adds r4, r2, 0
	ldr r1, [sp]
	cmp r1, 0
	beq _08008F7E
	cmp r1, 0xD
	beq _08008F7E
	cmp r1, 0xA
	bne _08008EDA
_08008F7E:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08008F88: .4byte gCharacterSpacing
	thumb_func_end sub_8008ED0

	thumb_func_start sub_8008F8C
sub_8008F8C:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r0, _08008FB8
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008FB8: .4byte gUnknown_2027370
	thumb_func_end sub_8008F8C

	thumb_func_start PrintStringOnWindow
PrintStringOnWindow:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r0, _08008FE8
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0xD
	str r1, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008FE8: .4byte gUnknown_2027370
	thumb_func_end PrintStringOnWindow

	thumb_func_start nullsub_170
nullsub_170:
	bx lr
	thumb_func_end nullsub_170

	thumb_func_start sub_8008FF0
sub_8008FF0:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r0, _0800901C
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0xD
	str r1, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800901C: .4byte gUnknown_2027370
	thumb_func_end sub_8008FF0

	thumb_func_start nullsub_171
nullsub_171:
	bx lr
	thumb_func_end nullsub_171

	thumb_func_start xxx_draw_string
xxx_draw_string:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x40
	adds r5, r0, 0
	adds r4, r3, 0
	ldr r0, [sp, 0x5C]
	mov r8, r0
	ldr r7, [sp, 0x64]
	add r0, sp, 0x8
	strh r1, [r0]
	strh r2, [r0, 0x2]
	str r1, [sp, 0x14]
	movs r0, 0x7
	str r0, [sp, 0x18]
	add r2, sp, 0x3C
	mov r9, r2
	b _08009128
_0800904A:
	ldr r0, _08009058
	cmp r3, r0
	bne _08009060
	ldr r1, _0800905C
	movs r0, 0
	str r0, [r1]
	b _08009128
	.align 2, 0
_08009058: .4byte 0x000082a0
_0800905C: .4byte gCurrentCharmap
_08009060:
	ldr r0, _08009070
	cmp r3, r0
	bne _08009078
	ldr r1, _08009074
	movs r0, 0x1
	str r0, [r1]
	b _08009128
	.align 2, 0
_08009070: .4byte 0x000082a2
_08009074: .4byte gCurrentCharmap
_08009078:
	cmp r3, 0x1B
	beq _0800914A
	cmp r3, 0xD
	beq _08009084
	cmp r3, 0xA
	bne _08009096
_08009084:
	add r1, sp, 0x8
	ldr r0, [sp, 0x14]
	strh r0, [r1]
	adds r0, r1, 0
	ldrh r0, [r0, 0x2]
	ldr r3, [sp, 0x68]
	adds r0, r3
	strh r0, [r1, 0x2]
	b _08009128
_08009096:
	cmp r3, 0x1D
	bne _080090AA
	add r1, sp, 0x8
	ldr r0, [sp, 0x14]
	strh r0, [r1]
	adds r0, r1, 0
	ldrh r0, [r0, 0x2]
	adds r0, 0x5
	strh r0, [r1, 0x2]
	b _08009128
_080090AA:
	cmp r3, 0x60
	bne _080090B8
	add r1, sp, 0x8
	adds r0, r1, 0
	ldrh r0, [r0]
	adds r0, 0x6
	b _08009126
_080090B8:
	cmp r7, 0
	bne _080090E0
	add r0, sp, 0x8
	movs r6, 0
	ldrsh r1, [r0, r6]
	movs r6, 0x2
	ldrsh r2, [r0, r6]
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	bl xxx_draw_char
	add r2, sp, 0x8
	adds r1, r2, 0
	ldrh r1, [r1]
	adds r1, r0
	strh r1, [r2]
	b _08009128
_080090E0:
	adds r0, r3, 0
	bl GetCharacter
	adds r2, r0, 0
	cmp r2, 0
	beq _08009128
	add r0, sp, 0x8
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r0, _08009158
	movs r6, 0
	ldrsh r0, [r0, r6]
	adds r0, 0xA
	movs r3, 0x6
	ldrsh r2, [r2, r3]
	subs r0, r2
	lsrs r2, r0, 31
	adds r0, r2
	asrs r0, 1
	adds r1, r0
	add r0, sp, 0x8
	movs r6, 0x2
	ldrsh r2, [r0, r6]
	ldr r3, [sp, 0x3C]
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	bl xxx_draw_char
	add r1, sp, 0x8
	adds r0, r1, 0
	ldrh r0, [r0]
	adds r0, r7
_08009126:
	strh r0, [r1]
_08009128:
	adds r0, r5, 0
	adds r1, r4, 0
	add r2, sp, 0x8
	bl HandleTextFormat
	adds r4, r0, 0
	mov r1, r9
	bl xxx_get_next_char_from_string
	adds r4, r0, 0
	ldr r3, [sp, 0x3C]
	cmp r3, 0
	beq _0800914A
	ldr r2, [sp, 0x60]
	cmp r3, r2
	beq _0800914A
	b _0800904A
_0800914A:
	add sp, 0x40
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009158: .4byte gCharacterSpacing
	thumb_func_end xxx_draw_string

	thumb_func_start sub_800915C
sub_800915C:
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
_08009162:
	ldrb r0, [r1]
	cmp r0, 0x2E
	beq _08009184
	subs r0, 0x30
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _08009186
	lsls r0, r2, 2
	adds r0, r2
	lsls r2, r0, 1
	adds r0, r2, 0
	subs r0, 0x30
	ldrb r4, [r1]
	adds r2, r0, r4
	adds r1, 0x1
	b _08009162
_08009184:
	adds r1, 0x1
_08009186:
	strh r2, [r3]
	adds r0, r1, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800915C

	thumb_func_start xxx_handle_format_global
xxx_handle_format_global:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080091A4
	adds r1, r3, 0
	bl HandleTextFormat
	pop {r1}
	bx r1
	.align 2, 0
_080091A4: .4byte gUnknown_2027370
	thumb_func_end xxx_handle_format_global

	thumb_func_start sub_80091A8
sub_80091A8:
	adds r0, 0x1
	bx lr
	thumb_func_end sub_80091A8

	thumb_func_start HandleTextFormat
HandleTextFormat:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	movs r0, 0
	mov r9, r0
	movs r7, 0x1
_080091C0:
	ldrb r0, [r4]
	cmp r0, 0x23
	beq _080091C8
	b _0800937A
_080091C8:
	ldrb r0, [r4, 0x1]
	adds r1, r0, 0
	cmp r1, 0x5B
	bne _08009216
	adds r2, r4, 0
	adds r4, 0x2
	adds r0, r5, 0
	adds r0, 0x21
	mov r1, r9
	strb r1, [r0]
	ldrb r1, [r4]
	adds r6, r0, 0
	cmp r1, 0
	beq _080091F6
	cmp r1, 0x5D
	beq _080091F4
_080091E8:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0
	beq _080091F6
	cmp r0, 0x5D
	bne _080091E8
_080091F4:
	adds r4, 0x1
_080091F6:
	ldr r3, [r5, 0x24]
	cmp r3, 0
	beq _0800920C
	adds r0, r2, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	cmp r0, 0
	beq _0800920C
	adds r4, r0, 0
_0800920C:
	ldrb r0, [r6]
	cmp r0, 0
	beq _08009214
	b _0800937A
_08009214:
	b _080091C0
_08009216:
	cmp r1, 0x3D
	bne _08009220
	ldrb r0, [r4, 0x2]
	strh r0, [r5]
	b _080092BA
_08009220:
	cmp r1, 0x79
	bne _0800922A
	ldrb r0, [r4, 0x2]
	strh r0, [r5, 0x2]
	b _080092BA
_0800922A:
	cmp r1, 0x3E
	bne _0800923A
	adds r1, r4, 0x2
	adds r0, r5, 0
	bl sub_800915C
	adds r4, r0, 0
	b _080091C0
_0800923A:
	cmp r1, 0x2E
	bne _08009246
	ldrh r0, [r5]
	ldrb r2, [r4, 0x2]
	adds r0, r2
	b _0800926E
_08009246:
	cmp r1, 0x6E
	bne _08009258
	ldr r0, [r5, 0xC]
	strh r0, [r5]
	ldrh r0, [r5, 0x2]
	adds r0, 0xB
	strh r0, [r5, 0x2]
	adds r4, 0x2
	b _080091C0
_08009258:
	cmp r1, 0x3A
	bne _08009264
	ldrh r0, [r5]
	strh r0, [r5, 0x4]
	adds r4, 0x2
	b _080091C0
_08009264:
	cmp r1, 0x3B
	bne _08009274
	ldrh r0, [r5, 0x4]
	ldrb r3, [r4, 0x2]
	adds r0, r3
_0800926E:
	strh r0, [r5]
	adds r4, 0x3
	b _080091C0
_08009274:
	cmp r1, 0x2B
	bne _0800929A
	adds r4, 0x2
	adds r0, r4, 0
	bl sub_8008ED0
	mov r2, r8
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	lsls r1, 3
	subs r1, r0
	strh r1, [r5]
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r5]
	b _080091C0
_0800929A:
	cmp r1, 0x43
	bne _080092A4
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x14]
	b _080092DC
_080092A4:
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5F
	bne _080092CC
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x14]
	ldr r1, _080092C8
	ldrb r0, [r4, 0x2]
	adds r0, r1
	ldrb r0, [r0]
	str r0, [r5, 0x10]
_080092BA:
	adds r4, 0x3
	ldrb r0, [r4]
	cmp r0, 0x2E
	beq _080092C4
	b _080091C0
_080092C4:
	adds r4, 0x1
	b _080091C0
	.align 2, 0
_080092C8: .4byte gUnknown_202749A
_080092CC:
	cmp r0, 0x52
	bne _080092D4
	ldr r0, [r5, 0x14]
	b _080092EE
_080092D4:
	cmp r0, 0x63
	bne _080092E8
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x18]
_080092DC:
	ldrb r0, [r4, 0x2]
	bl InterpretColorChar
	str r0, [r5, 0x10]
	adds r4, 0x3
	b _080091C0
_080092E8:
	cmp r0, 0x72
	bne _080092F4
	ldr r0, [r5, 0x18]
_080092EE:
	str r0, [r5, 0x10]
	adds r4, 0x2
	b _080091C0
_080092F4:
	cmp r0, 0x53
	bne _08009314
	ldr r3, _08009310
	ldrb r2, [r4, 0x2]
	movs r0, 0x7F
	adds r1, r0, 0
	ands r1, r2
	adds r1, r3
	ldrb r2, [r4, 0x3]
	ands r0, r2
	strb r0, [r1]
	adds r4, 0x4
	b _080091C0
	.align 2, 0
_08009310: .4byte gUnknown_20274A6
_08009314:
	cmp r0, 0x57
	bne _0800933A
	adds r4, 0x2
	mov r2, r8
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 3
	ldrh r1, [r5]
	adds r0, r1
	subs r0, 0x2
	strh r0, [r5, 0x8]
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r0, 3
	ldrh r1, [r5, 0x2]
	adds r0, r1
	adds r0, 0x3
	strh r0, [r5, 0xA]
	b _0800935C
_0800933A:
	cmp r0, 0x50
	bne _08009350
	adds r4, 0x2
	ldr r0, _0800934C
	strh r0, [r5, 0x2]
	mov r2, r9
	str r2, [r5, 0x1C]
	b _0800935C
	.align 2, 0
_0800934C: .4byte 0x0000270f
_08009350:
	cmp r0, 0x70
	bne _08009368
	adds r4, 0x2
	ldr r0, _08009364
	strh r0, [r5, 0x2]
	str r7, [r5, 0x1C]
_0800935C:
	adds r0, r5, 0
	adds r0, 0x20
	strb r7, [r0]
	b _0800937A
	.align 2, 0
_08009364: .4byte 0x0000270f
_08009368:
	cmp r0, 0x7E
	bne _0800937A
	ldrb r0, [r4, 0x2]
	str r0, [r5, 0x2C]
	adds r0, r5, 0
	adds r0, 0x21
	strb r7, [r0]
	adds r4, 0x3
	b _080091C0
_0800937A:
	adds r0, r4, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end HandleTextFormat

	thumb_func_start sub_8009388
sub_8009388:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, _080093F4
	ldr r6, _080093F8
	strh r6, [r2]
	movs r0, 0x80
	lsls r0, 4
	adds r5, r2, r0
	ldr r4, _080093FC
	strh r4, [r5]
	ldr r0, _08009400
	ldr r3, [r0]
	ldr r0, _08009404
	ldr r1, [r0]
	mov r9, r0
	cmp r3, r1
	bge _080093E6
	mov r8, r2
	mov r12, r6
	adds r6, r5, 0
	movs r5, 0
	adds r7, r6, 0
_080093B8:
	lsls r0, r3, 6
	mov r1, r8
	adds r2, r0, r1
	mov r1, r12
	strh r1, [r2]
	adds r1, r0, r6
	strh r4, [r1]
	adds r3, 0x1
	adds r0, r7
	adds r0, 0x2
	adds r2, 0x2
	movs r1, 0x1E
_080093D0:
	strh r5, [r2]
	strh r4, [r0]
	adds r0, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080093D0
	mov r1, r9
	ldr r0, [r1]
	cmp r3, r0
	blt _080093B8
_080093E6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080093F4: .4byte gUnknown_202B038
_080093F8: .4byte 0x0000f279
_080093FC: .4byte 0x0000f27a
_08009400: .4byte gUnknown_202B020
_08009404: .4byte gUnknown_202B024
	thumb_func_end sub_8009388

	thumb_func_start sub_8009408
sub_8009408:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r1, 0
	ldr r1, _08009478
	ldr r6, _0800947C
	strh r6, [r1]
	movs r2, 0x80
	lsls r2, 4
	adds r4, r1, r2
	ldr r2, _08009480
	strh r2, [r4]
	adds r3, r0, 0
	ldr r0, _08009484
	mov r10, r0
	cmp r3, r5
	bge _08009464
	mov r9, r1
	mov r8, r6
	adds r7, r4, 0
	adds r4, r2, 0
	movs r6, 0
	mov r12, r7
_0800943A:
	lsls r0, r3, 6
	mov r1, r9
	adds r2, r0, r1
	mov r1, r8
	strh r1, [r2]
	adds r1, r0, r7
	strh r4, [r1]
	adds r3, 0x1
	add r0, r12
	adds r0, 0x2
	adds r2, 0x2
	movs r1, 0x1E
_08009452:
	strh r6, [r2]
	strh r4, [r0]
	adds r0, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08009452
	cmp r3, r5
	blt _0800943A
_08009464:
	movs r0, 0x1
	mov r2, r10
	strb r0, [r2]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009478: .4byte gUnknown_202B038
_0800947C: .4byte 0x0000f279
_08009480: .4byte 0x0000f27a
_08009484: .4byte gUnknown_20274A5
	thumb_func_end sub_8009408

	thumb_func_start sub_8009488
sub_8009488:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08009514
	adds r4, r1, r0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r3, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r3, r0
	bge _08009506
	ldr r6, _08009518
	mov r9, r6
	ldr r0, _0800951C
	mov r8, r0
	movs r2, 0x80
	lsls r2, 4
	add r2, r8
	mov r10, r2
_080094BA:
	movs r6, 0
	ldrsh r2, [r4, r6]
	movs r5, 0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	adds r6, r1, 0x1
	adds r7, r3, 0x1
	cmp r5, r0
	bge _080094FA
	movs r0, 0xFC
	lsls r0, 8
	mov r12, r0
	lsls r2, 1
	lsls r1, 6
	mov r3, r10
	adds r0, r1, r3
	adds r3, r2, r0
	add r1, r8
	adds r2, r1
_080094E0:
	ldrh r0, [r2]
	mov r1, r12
	ands r1, r0
	strh r1, [r2]
	mov r0, r9
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _080094E0
_080094FA:
	adds r1, r6, 0
	adds r3, r7, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r3, r0
	blt _080094BA
_08009506:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009514: .4byte gUnknown_2027370
_08009518: .4byte 0x0000f27a
_0800951C: .4byte gUnknown_202B038
	thumb_func_end sub_8009488

	thumb_func_start nullsub_172
nullsub_172:
	bx lr
	thumb_func_end nullsub_172

	thumb_func_start sub_8009524
sub_8009524:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _080095BC
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	subs r1, r0, 0x1
	movs r3, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	adds r0, 0x2
	cmp r3, r0
	bge _080095AE
	ldr r6, _080095C0
	mov r9, r6
	ldr r0, _080095C4
	mov r8, r0
	movs r2, 0x80
	lsls r2, 4
	add r2, r8
	mov r10, r2
_0800955A:
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r2, r0, 0x1
	movs r5, 0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	adds r0, 0x2
	adds r6, r1, 0x1
	adds r7, r3, 0x1
	cmp r5, r0
	bge _080095A0
	movs r0, 0xFC
	lsls r0, 8
	mov r12, r0
	lsls r2, 1
	lsls r1, 6
	mov r3, r10
	adds r0, r1, r3
	adds r3, r2, r0
	add r1, r8
	adds r2, r1
_08009584:
	ldrh r0, [r2]
	mov r1, r12
	ands r1, r0
	strh r1, [r2]
	mov r0, r9
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r0, 0x2
	cmp r5, r0
	blt _08009584
_080095A0:
	adds r1, r6, 0
	adds r3, r7, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	adds r0, 0x2
	cmp r3, r0
	blt _0800955A
_080095AE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080095BC: .4byte gUnknown_2027370
_080095C0: .4byte 0x0000f27a
_080095C4: .4byte gUnknown_202B038
	thumb_func_end sub_8009524

	thumb_func_start nullsub_173
nullsub_173:
	bx lr
	thumb_func_end nullsub_173

	thumb_func_start sub_80095CC
sub_80095CC:
	ldr r2, _080095D8
	str r0, [r2]
	ldr r0, _080095DC
	str r1, [r0]
	bx lr
	.align 2, 0
_080095D8: .4byte gUnknown_202B020
_080095DC: .4byte gUnknown_202B024
	thumb_func_end sub_80095CC

	thumb_func_start nullsub_174
nullsub_174:
	bx lr
	thumb_func_end nullsub_174

@ https://decomp.me/scratch/A63Io
	thumb_func_start sub_80095E4
sub_80095E4:
	push {lr}
	cmp r1, 0
	bne _080095EC
	movs r1, 0xA
_080095EC:
	muls r1, r0
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08009604
	adds r0, r1, 0
	cmp r1, 0
	bge _080095FE
	adds r0, r1, 0x7
_080095FE:
	asrs r0, 3
	adds r0, 0x1
	b _0800960E
_08009604:
	adds r0, r1, 0
	cmp r0, 0
	bge _0800960C
	adds r0, 0x7
_0800960C:
	asrs r0, 3
_0800960E:
	pop {r1}
	bx r1
	thumb_func_end sub_80095E4

	thumb_func_start sub_8009614
sub_8009614:
	push {lr}
	muls r1, r0
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0800962E
	adds r0, r1, 0
	cmp r1, 0
	bge _08009628
	adds r0, r1, 0x7
_08009628:
	asrs r0, 3
	adds r0, 0x1
	b _08009638
_0800962E:
	adds r0, r1, 0
	cmp r0, 0
	bge _08009636
	adds r0, 0x7
_08009636:
	asrs r0, 3
_08009638:
	pop {r1}
	bx r1
	thumb_func_end sub_8009614

	thumb_func_start InterpretColorChar
InterpretColorChar:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	cmp r0, 0xF
	bls _080096DA
	adds r1, r0, 0
	subs r1, 0x30
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0xF
	bhi _08009658
	adds r0, r1, 0
	b _080096DA
_08009658:
	adds r0, r2, 0
	subs r0, 0x43
	cmp r0, 0x14
	bhi _080096D8
	lsls r0, 2
	ldr r1, _0800966C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800966C: .4byte _08009670
	.align 2, 0
_08009670:
	.4byte _080096D0
	.4byte _080096D0
	.4byte _080096C8
	.4byte _080096D8
	.4byte _080096CC
	.4byte _080096C4
	.4byte _080096C4
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096CC
	.4byte _080096D0
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096C8
	.4byte _080096C8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D4
_080096C4:
	movs r0, 0x4
	b _080096DA
_080096C8:
	movs r0, 0xF
	b _080096DA
_080096CC:
	movs r0, 0x5
	b _080096DA
_080096D0:
	movs r0, 0x6
	b _080096DA
_080096D4:
	movs r0, 0x2
	b _080096DA
_080096D8:
	movs r0, 0x7
_080096DA:
	pop {r1}
	bx r1
	thumb_func_end InterpretColorChar

	thumb_func_start InitGraphics
InitGraphics:
	push {r4-r6,lr}
	ldr r1, _0800978C
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0xC0
	lsls r1, 19
	movs r5, 0
	ldr r3, _08009790
	ldr r0, _08009794
	movs r2, 0
_080096F4:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, r3
	bls _080096F4
	movs r1, 0xA0
	lsls r1, 19
	movs r5, 0
	movs r2, 0
_08009704:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, 0xFF
	bls _08009704
	movs r1, 0xE0
	lsls r1, 19
	movs r5, 0
	ldr r2, _08009798
_08009714:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, 0xFF
	bls _08009714
	ldr r4, _0800979C
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r1, [r6, 0x4]
	ldm r1!, {r5}
	ldr r0, _080097A0
	lsls r2, r5, 5
	bl CpuCopy
	adds r0, r6, 0
	bl CloseFile
	ldr r0, _080097A4
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r1, [r6, 0x4]
	ldm r1!, {r5}
	ldr r0, _080097A8
	lsls r2, r5, 5
	bl CpuCopy
	adds r0, r6, 0
	bl CloseFile
	bl InitFontPalette
	ldr r0, _080097AC
	adds r1, r4, 0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r4, [r6, 0x4]
	movs r5, 0
_08009766:
	movs r1, 0xF8
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r4, 0
	bl SetBGPaletteBufferColorArray
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08009766
	adds r0, r6, 0
	bl CloseFile
	bl TransferBGPaletteBuffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800978C: .4byte gUnknown_203B090
_08009790: .4byte 0x00005fff
_08009794: .4byte gUnknown_80B88B0
_08009798: .4byte 0x00a000a0
_0800979C: .4byte gSystemFileArchive
_080097A0: .4byte 0x06004f00
_080097A4: .4byte gUnknown_80B88B8
_080097A8: .4byte 0x06017e00
_080097AC: .4byte gUnknown_80B88C0
	thumb_func_end InitGraphics

	.align 2, 0 @ Don't pad with nop.
