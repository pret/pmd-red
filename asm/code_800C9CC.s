	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

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
