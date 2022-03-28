        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802CAA4
sub_802CAA4:
	push {r4-r7,lr}
	movs r7, 0
	ldr r5, _0802CAC8
	ldr r0, [r5]
	ldrb r0, [r0, 0xC]
	bl GetJobSlotInfo
	adds r4, r0, 0
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _0802CB26
	ldrb r0, [r4]
	cmp r0, 0x5
	beq _0802CACC
	cmp r0, 0x6
	beq _0802CB10
	b _0802CB26
	.align 2, 0
_0802CAC8: .4byte gUnknown_203B2F0
_0802CACC:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CAFC
	str r0, [r1]
	adds r0, r4, 0
	bl sub_809693C
	lsls r0, 24
	cmp r0, 0
	bne _0802CAEE
	ldrb r0, [r4, 0x4]
	bl sub_80A2824
	lsls r0, 24
	cmp r0, 0
	bne _0802CB00
_0802CAEE:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	b _0802CB0A
	.align 2, 0
_0802CAFC: .4byte gUnknown_80DFD70
_0802CB00:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x2
_0802CB0A:
	str r1, [r0]
	adds r7, 0x1
	b _0802CB26
_0802CB10:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CB9C
	str r0, [r1]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x3
	str r0, [r1]
	movs r7, 0x1
_0802CB26:
	ldr r4, _0802CBA0
	ldr r6, [r4]
	lsls r1, r7, 3
	movs r0, 0x86
	lsls r0, 1
	adds r3, r6, r0
	adds r2, r3, r1
	ldr r0, _0802CBA4
	ldr r0, [r0]
	str r0, [r2]
	movs r0, 0x88
	lsls r0, 1
	adds r5, r6, r0
	adds r1, r5, r1
	movs r0, 0x4
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802CBA8
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r5, r1
	movs r0, 0x7
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r5, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r7
	bge _0802CB8C
	adds r4, r6, 0
	adds r1, r5, 0
	movs r5, 0x1
	negs r5, r5
_0802CB78:
	ldr r2, [r1]
	cmp r2, r5
	beq _0802CB84
	ldr r0, [r4, 0x68]
	cmp r2, r0
	beq _0802CB94
_0802CB84:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _0802CB78
_0802CB8C:
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x7
	str r0, [r1, 0x68]
_0802CB94:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CB9C: .4byte gUnknown_80DFD7C
_0802CBA0: .4byte gUnknown_203B2F0
_0802CBA4: .4byte gUnknown_80D494C
_0802CBA8: .4byte gUnknown_80D4970
	thumb_func_end sub_802CAA4

	thumb_func_start sub_802CBAC
sub_802CBAC:
	ldr r0, _0802CBF4
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xA6
	lsls r1, 1
	add r1, r12
	ldr r0, _0802CBF8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xA8
	lsls r1, 1
	add r1, r12
	movs r0, 0x5
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xAA
	lsls r1, 1
	add r1, r12
	ldr r0, _0802CBFC
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r0, 0xAE
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_0802CBF4: .4byte gUnknown_203B2F0
_0802CBF8: .4byte gUnknown_80D4920
_0802CBFC: .4byte gUnknown_80D4928
	thumb_func_end sub_802CBAC

	thumb_func_start sub_802CC00
sub_802CC00:
	push {lr}
	movs r0, 0x1
	bl sub_802C598
	cmp r0, 0x4
	bhi _0802CC6A
	lsls r0, 2
	ldr r1, _0802CC18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CC18: .4byte _0802CC1C
	.align 2, 0
_0802CC1C:
	.4byte _0802CC6A
	.4byte _0802CC6A
	.4byte _0802CC60
	.4byte _0802CC30
	.4byte _0802CC48
_0802CC30:
	bl sub_802C620
	ldr r1, _0802CC44
	ldr r1, [r1]
	strb r0, [r1, 0xC]
	movs r0, 0x2
	bl sub_802C910
	b _0802CC6A
	.align 2, 0
_0802CC44: .4byte gUnknown_203B2F0
_0802CC48:
	bl sub_802C620
	ldr r1, _0802CC5C
	ldr r1, [r1]
	strb r0, [r1, 0xC]
	movs r0, 0x4
	bl sub_802C910
	b _0802CC6A
	.align 2, 0
_0802CC5C: .4byte gUnknown_203B2F0
_0802CC60:
	bl sub_802C688
	movs r0, 0x5
	bl sub_802C910
_0802CC6A:
	pop {r0}
	bx r0
	thumb_func_end sub_802CC00

	thumb_func_start sub_802CC70
sub_802CC70:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802CCB4
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802CCA0
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802CCA0
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802CCA0:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bhi _0802CD2E
	lsls r0, 2
	ldr r1, _0802CCB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CCB4: .4byte gUnknown_203B2F0
_0802CCB8: .4byte _0802CCBC
	.align 2, 0
_0802CCBC:
	.4byte _0802CD28
	.4byte _0802CCD8
	.4byte _0802CCF4
	.4byte _0802CD18
	.4byte _0802CD2E
	.4byte _0802CD2E
	.4byte _0802CD20
_0802CCD8:
	ldr r0, _0802CCEC
	bl PlaySound
	ldr r0, _0802CCF0
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bl GetJobSlotInfo
	movs r1, 0x6
	b _0802CD06
	.align 2, 0
_0802CCEC: .4byte 0x00000133
_0802CCF0: .4byte gUnknown_203B2F0
_0802CCF4:
	ldr r0, _0802CD10
	bl PlaySound
	ldr r0, _0802CD14
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bl GetJobSlotInfo
	movs r1, 0x5
_0802CD06:
	strb r1, [r0]
	movs r0, 0x1
	bl sub_802C910
	b _0802CD2E
	.align 2, 0
_0802CD10: .4byte 0x00000133
_0802CD14: .4byte gUnknown_203B2F0
_0802CD18:
	movs r0, 0x3
	bl sub_802C910
	b _0802CD2E
_0802CD20:
	movs r0, 0x4
	bl sub_802C910
	b _0802CD2E
_0802CD28:
	movs r0, 0x1
	bl sub_802C910
_0802CD2E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802CC70

	thumb_func_start sub_802CD38
sub_802CD38:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802CD78
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xBC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802CD66
	ldr r0, [r4]
	adds r0, 0xBC
	mov r1, sp
	bl sub_8013114
_0802CD66:
	ldr r0, [sp]
	cmp r0, 0x5
	beq _0802CD88
	cmp r0, 0x5
	bgt _0802CD7C
	cmp r0, 0x1
	beq _0802CD80
	b _0802CDB0
	.align 2, 0
_0802CD78: .4byte gUnknown_203B2F0
_0802CD7C:
	cmp r0, 0x6
	bne _0802CDB0
_0802CD80:
	movs r0, 0x1
	bl sub_802C910
	b _0802CDB0
_0802CD88:
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_8096C3C
	bl sub_8096C80
	bl HasNoAcceptedJobs
	lsls r0, 24
	cmp r0, 0
	beq _0802CDAA
	bl sub_802C688
	movs r0, 0x5
	bl sub_802C910
	b _0802CDB0
_0802CDAA:
	movs r0, 0x1
	bl sub_802C910
_0802CDB0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802CD38

	thumb_func_start sub_802CDB8
sub_802CDB8:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802CDD0
	cmp r0, 0x3
	bhi _0802CDD0
	bl sub_802DF24
	movs r0, 0x1
	bl sub_802C910
_0802CDD0:
	pop {r0}
	bx r0
	thumb_func_end sub_802CDB8

	thumb_func_start sub_802CDD4
sub_802CDD4:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0802CE54
	ldr r0, [r4]
	cmp r0, 0
	bne _0802CDEA
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802CDEA:
	ldr r0, [r4]
	str r5, [r0, 0x34]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0802CE58
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r1, [r4]
	ldr r0, [r1, 0x38]
	adds r1, 0x9C
	str r1, [r0, 0x14]
	movs r1, 0x4
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x5
	movs r2, 0x4
	adds r3, r5, 0
	bl sub_8013848
	bl sub_802CF5C
	bl sub_802CFD0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802CE54: .4byte gUnknown_203B2F4
_0802CE58: .4byte gUnknown_80DFDA4
	thumb_func_end sub_802CDD4

	thumb_func_start sub_802CE5C
sub_802CE5C:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802CE74
	ldr r0, _0802CE70
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0802CEB4
	.align 2, 0
_0802CE70: .4byte gUnknown_203B2F4
_0802CE74:
	ldr r4, _0802CE90
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0802CE94
	cmp r0, 0x2
	bne _0802CE98
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802CEB4
	.align 2, 0
_0802CE90: .4byte gUnknown_203B2F4
_0802CE94:
	movs r0, 0x3
	b _0802CEB4
_0802CE98:
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802CEAA
	movs r0, 0
	b _0802CEB4
_0802CEAA:
	bl sub_802CF5C
	bl sub_802CFD0
	movs r0, 0x1
_0802CEB4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802CE5C

	thumb_func_start sub_802CEBC
sub_802CEBC:
	ldr r0, _0802CED4
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	ldrb r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_0802CED4: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CEBC

	thumb_func_start sub_802CED8
sub_802CED8:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802CF10
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	bl sub_8013984
	bl sub_802CF5C
	bl sub_802CFD0
	cmp r4, 0
	beq _0802CF0A
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0802CF0A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CF10: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CED8

	thumb_func_start sub_802CF14
sub_802CF14:
	push {r4,r5,lr}
	ldr r4, _0802CF54
	ldr r2, [r4]
	cmp r2, 0
	beq _0802CF4E
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0802CF58
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802CF4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CF54: .4byte gUnknown_203B2F4
_0802CF58: .4byte gUnknown_80DFD8C
	thumb_func_end sub_802CF14

	thumb_func_start sub_802CF5C
sub_802CF5C:
	push {r4,lr}
	ldr r4, _0802CFCC
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802CFCC: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CF5C

	thumb_func_start sub_802CFD0
sub_802CFD0:
	push {r4-r6,lr}
	sub sp, 0x60
	ldr r6, _0802D02C
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r0, [r6]
	movs r1, 0x1E
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0802D030
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r5, 0
	b _0802D076
	.align 2, 0
_0802D02C: .4byte gUnknown_203B2F4
_0802D030: .4byte gUnknown_80DFDBC
_0802D034:
	ldr r0, [r6]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl sub_803B344
	adds r4, r0, 0
	ldr r0, [r6]
	ldr r1, [r0, 0x34]
	str r1, [sp, 0x8]
	adds r1, r5, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	adds r0, r4, 0
	add r1, sp, 0x8
	bl sub_803B35C
	mov r1, sp
	adds r1, 0x4B
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4, 0x14]
	str r0, [sp, 0x54]
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r5, 0x1
_0802D076:
	ldr r0, [r6]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0802D034
	ldr r0, _0802D094
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802D094: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CFD0

        .align 2,0
