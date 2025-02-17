	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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

