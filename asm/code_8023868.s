	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8023868
sub_8023868:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	mov r8, r1
	mov r9, r2
	mov r10, r3
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _08023888
	movs r0, 0
	b _08023A6E
_08023888:
	ldr r4, _080238AC
	ldr r0, [r4]
	cmp r0, 0
	bne _0802389C
	movs r0, 0xFE
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802389C:
	ldr r1, [r4]
	str r5, [r1]
	ldr r0, _080238B0
	ldr r0, [r0]
	cmp r0, r5
	beq _080238B4
	movs r0, 0x1
	b _080238B8
	.align 2, 0
_080238AC: .4byte gUnknown_3001B60
_080238B0: .4byte gUnknown_203B2A0
_080238B4:
	ldr r0, _080238E4
	ldr r0, [r0]
_080238B8:
	str r0, [r1, 0x4]
	ldr r2, _080238E8
	ldr r0, [r2]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r2]
	strb r1, [r0, 0x15]
	ldr r0, [r2]
	strb r1, [r0, 0x16]
	ldr r0, [r2]
	strb r1, [r0, 0x17]
	ldr r0, [r2]
	strb r1, [r0, 0x18]
	ldr r0, [r2]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _08023980
	lsls r0, 2
	ldr r1, _080238EC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080238E4: .4byte gUnknown_203B2A4
_080238E8: .4byte gUnknown_3001B60
_080238EC: .4byte _080238F0
	.align 2, 0
_080238F0:
	.4byte _08023958
	.4byte _08023904
	.4byte _08023914
	.4byte _08023924
	.4byte _0802393C
_08023904:
	ldr r0, _08023910
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x18]
	b _08023958
	.align 2, 0
_08023910: .4byte gUnknown_3001B60
_08023914:
	ldr r0, _08023920
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x14]
	b _08023958
	.align 2, 0
_08023920: .4byte gUnknown_3001B60
_08023924:
	ldr r2, _08023938
	ldr r0, [r2]
	movs r1, 0x1
	strb r1, [r0, 0x17]
	ldr r0, [r2]
	strb r1, [r0, 0x15]
	ldr r0, [r2]
	strb r1, [r0, 0x16]
	b _08023958
	.align 2, 0
_08023938: .4byte gUnknown_3001B60
_0802393C:
	ldr r5, _0802397C
	ldr r0, [r5]
	movs r4, 0x1
	strb r4, [r0, 0x18]
	ldr r0, [r5]
	strb r4, [r0, 0x15]
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08023958
	ldr r0, [r5]
	strb r4, [r0, 0x16]
_08023958:
	ldr r4, _0802397C
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08023980
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r1, [r4]
	movs r2, 0xD5
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	b _0802398E
	.align 2, 0
_0802397C: .4byte gUnknown_3001B60
_08023980:
	ldr r0, _08023A7C
	ldr r0, [r0]
	movs r3, 0xD5
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
_0802398E:
	ldr r5, _08023A7C
	ldr r0, [r5]
	movs r4, 0xE3
	lsls r4, 2
	adds r1, r0, r4
	mov r2, r8
	str r2, [r1]
	movs r7, 0xE4
	lsls r7, 2
	adds r2, r0, r7
	mov r3, r8
	lsls r1, r3, 1
	add r1, r8
	lsls r1, 3
	movs r6, 0xE5
	lsls r6, 2
	adds r1, r6
	adds r1, r0, r1
	str r1, [r2]
	adds r0, r6
	bl RestoreUnkTextStruct_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r6
	ldr r0, _08023A80
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r5]
	adds r0, r2, r7
	ldr r1, [r0]
	movs r4, 0xFD
	lsls r4, 2
	adds r0, r2, r4
	str r0, [r1, 0x14]
	mov r0, r9
	cmp r0, 0
	beq _08023A04
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	movs r3, 0xE7
	lsls r3, 2
	adds r1, r2, r3
	adds r1, r0
	mov r4, r9
	ldr r0, [r4]
	str r0, [r1]
_08023A04:
	ldr r0, [r5]
	adds r0, r7
	ldr r0, [r0]
	mov r1, r10
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl ShowWindows
	ldr r4, [r5]
	movs r0, 0xD6
	lsls r0, 2
	adds r4, r0
	bl sub_8023F8C
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r10
	mov r3, r8
	bl sub_8013818
	ldr r0, _08023A84
	ldr r4, [r5]
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	bne _08023A64
	ldr r0, _08023A88
	ldrh r1, [r0]
	movs r2, 0xDC
	lsls r2, 2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08023A8C
	ldrh r1, [r0]
	ldr r3, _08023A90
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r4, r1
	bl sub_8013984
_08023A64:
	bl sub_8023CF4
	bl sub_8023DA4
	movs r0, 0x1
_08023A6E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023A7C: .4byte gUnknown_3001B60
_08023A80: .4byte sUnknown_80DC968
_08023A84: .4byte gUnknown_203B2A0
_08023A88: .4byte gUnknown_203B2A8
_08023A8C: .4byte gUnknown_203B2AA
_08023A90: .4byte 0x00000376
	thumb_func_end sub_8023868

	thumb_func_start sub_8023A94
sub_8023A94:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08023AB4
	ldr r0, _08023AB0
	ldr r0, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _08023B3E
	.align 2, 0
_08023AB0: .4byte gUnknown_3001B60
_08023AB4:
	ldr r4, _08023AD0
	ldr r0, [r4]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _08023ADE
	cmp r0, 0x2
	bgt _08023AD4
	cmp r0, 0x1
	beq _08023AF2
	b _08023B16
	.align 2, 0
_08023AD0: .4byte gUnknown_3001B60
_08023AD4:
	cmp r0, 0x3
	beq _08023AFC
	cmp r0, 0x4
	beq _08023AE8
	b _08023B16
_08023ADE:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08023B3E
_08023AE8:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _08023B3E
_08023AF2:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08023B3E
_08023AFC:
	movs r0, 0x5
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	movs r2, 0x1
	cmp r1, 0x2
	bhi _08023B0E
	adds r2, r1, 0x1
_08023B0E:
	str r2, [r0, 0x4]
	bl sub_8023F8C
	b _08023B34
_08023B16:
	ldr r0, _08023B30
	ldr r0, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08023B34
	movs r0, 0
	b _08023B3E
	.align 2, 0
_08023B30: .4byte gUnknown_3001B60
_08023B34:
	bl sub_8023CF4
	bl sub_8023DA4
	movs r0, 0x1
_08023B3E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023A94

	thumb_func_start sub_8023B44
sub_8023B44:
	ldr r0, _08023B74
	ldr r0, [r0]
	ldr r2, _08023B78
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0xDD
	lsls r3, 2
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r1, r2
	movs r3, 0xDC
	lsls r3, 2
	adds r2, r0, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r1, r2
	lsls r1, 1
	adds r0, 0x1A
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08023B74: .4byte gUnknown_3001B60
_08023B78: .4byte 0x00000376
	thumb_func_end sub_8023B44

	thumb_func_start sub_8023B7C
sub_8023B7C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _08023BD0
	ldr r0, [r5]
	movs r1, 0xE5
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl ShowWindows
	bl sub_8023BD8
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, _08023BD4
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_8023CF4
	bl sub_8023DA4
	cmp r4, 0
	beq _08023BCA
	ldr r0, [r5]
	movs r3, 0xD6
	lsls r3, 2
	adds r0, r3
	bl AddMenuCursorSprite
_08023BCA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023BD0: .4byte gUnknown_3001B60
_08023BD4: .4byte 0x0000037a
	thumb_func_end sub_8023B7C

	thumb_func_start sub_8023BD8
sub_8023BD8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r3, 0
	ldr r1, _08023C58
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r7, r1, 0
	cmp r3, r0
	bge _08023C4A
	ldr r0, _08023C5C
	mov r8, r0
	mov r12, r7
_08023BF2:
	ldr r2, [r1]
	lsls r4, r3, 1
	adds r0, r2, 0
	adds r0, 0x1A
	adds r0, r4
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x58
	muls r0, r1
	mov r5, r8
	ldr r1, [r5]
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r6, r3, 0x1
	cmp r0, 0
	bne _08023C3E
	ldr r0, [r2, 0x8]
	subs r0, 0x1
	str r0, [r2, 0x8]
	cmp r3, r0
	bge _08023C3E
	mov r5, r12
	adds r4, 0x2
_08023C24:
	ldr r2, [r5]
	lsls r1, r3, 1
	adds r0, r2, 0
	adds r0, 0x1A
	adds r1, r0, r1
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, 0x2
	adds r3, 0x1
	ldr r0, [r2, 0x8]
	cmp r3, r0
	blt _08023C24
_08023C3E:
	adds r3, r6, 0
	adds r1, r7, 0
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	cmp r3, r0
	blt _08023BF2
_08023C4A:
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023C58: .4byte gUnknown_3001B60
_08023C5C: .4byte gRecruitedPokemonRef
	thumb_func_end sub_8023BD8

	thumb_func_start sub_8023C60
sub_8023C60:
	push {r4-r6,lr}
	ldr r5, _08023CCC
	ldr r2, [r5]
	cmp r2, 0
	beq _08023CC6
	ldr r1, _08023CD0
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _08023CD4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, _08023CD8
	movs r3, 0xDC
	lsls r3, 2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08023CDC
	ldr r6, _08023CE0
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE5
	lsls r4, 2
	adds r1, r4
	ldr r0, _08023CE4
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl ShowWindows
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_08023CC6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08023CCC: .4byte gUnknown_3001B60
_08023CD0: .4byte gUnknown_203B2A0
_08023CD4: .4byte gUnknown_203B2A4
_08023CD8: .4byte gUnknown_203B2A8
_08023CDC: .4byte gUnknown_203B2AA
_08023CE0: .4byte 0x00000376
_08023CE4: .4byte sUnknown_80DC950
	thumb_func_end sub_8023C60

	thumb_func_start sub_8023CE8
sub_8023CE8:
	ldr r0, _08023CF0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08023CF0: .4byte gUnknown_3001B60
	thumb_func_end sub_8023CE8

	thumb_func_start sub_8023CF4
sub_8023CF4:
	push {r4,r5,lr}
	ldr r2, _08023D28
	ldr r0, [r2]
	movs r1, 0xFD
	lsls r1, 2
	adds r0, r1
	movs r3, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08023D2C
	adds r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r1, 0x2
	adds r0, r1
	strb r3, [r0]
	ldr r1, [r2]
	ldr r0, [r1]
	adds r5, r2, 0
	cmp r0, 0x2
	bne _08023D34
	ldr r0, _08023D30
	adds r1, r0
	b _08023D38
	.align 2, 0
_08023D28: .4byte gUnknown_3001B60
_08023D2C: .4byte 0x000003f5
_08023D30: .4byte 0x000003f6
_08023D34:
	ldr r2, _08023D98
	adds r1, r2
_08023D38:
	movs r0, 0xC
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _08023D9C
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r3, [r5]
	movs r1, 0xE3
	lsls r1, 2
	adds r4, r3, r1
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _08023DA0
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r3, r1
	movs r1, 0xE9
	lsls r1, 2
	adds r3, r1
	strh r0, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r2, 0xE5
	lsls r2, 2
	adds r0, r2
	movs r1, 0x1
	movs r2, 0x1
	bl ShowWindows
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023D98: .4byte 0x000003f6
_08023D9C: .4byte 0x00000372
_08023DA0: .4byte 0x000003a2
	thumb_func_end sub_8023CF4

	thumb_func_start sub_8023DA4
sub_8023DA4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r4, _08023DD8
	ldr r0, [r4]
	movs r5, 0xE3
	lsls r5, 2
	adds r0, r5
	ldr r0, [r0]
	bl CallPrepareTextbox_8008C54
	ldr r0, [r4]
	adds r0, r5
	ldr r0, [r0]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r1, [r0]
	cmp r1, 0x2
	beq _08023DE0
	cmp r1, 0x4
	beq _08023E00
	ldr r2, _08023DDC
	b _08023E02
	.align 2, 0
_08023DD8: .4byte gUnknown_3001B60
_08023DDC: .4byte sUnknown_80DC988
_08023DE0:
	add r0, sp, 0x8
	bl sub_80920D8
	ldr r0, [r4]
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r1
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	add r2, sp, 0x8
	bl PrintStringOnWindow
	b _08023E3C
_08023E00:
	ldr r2, _08023EBC
_08023E02:
	adds r0, r5
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl PrintStringOnWindow
	ldr r1, [r4]
	ldr r2, _08023EC0
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 3
	adds r3, r0, 0x4
	ldr r4, _08023EC4
	adds r0, r1, r4
	movs r4, 0
	ldrsh r2, [r0, r4]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	adds r1, r5
	ldr r0, [r1]
	str r0, [sp, 0x4]
	adds r0, r3, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
_08023E3C:
	movs r7, 0
	ldr r1, _08023EC8
	ldr r0, [r1]
	ldr r2, _08023ECC
	adds r0, r2
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r7, r0
	blt _08023E50
	b _08023F62
_08023E50:
	mov r8, r1
	add r0, sp, 0x30
	mov r9, r0
_08023E56:
	ldr r3, [r1]
	ldr r1, _08023EC4
	adds r0, r3, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r4, 0xDD
	lsls r4, 2
	adds r0, r3, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	muls r1, r0
	adds r1, r7
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r1
	movs r4, 0
	ldrsh r5, [r0, r4]
	ldr r2, _08023ED0
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r6, 0x7
	ldrh r0, [r4]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08023ED4
	movs r0, 0
	ldrb r1, [r4, 0x4]
	cmp r1, 0x41
	bne _08023E9E
	movs r0, 0x1
_08023E9E:
	cmp r0, 0
	beq _08023EA4
	movs r6, 0x6
_08023EA4:
	movs r0, 0
	cmp r1, 0x40
	bne _08023EAC
	movs r0, 0x1
_08023EAC:
	cmp r0, 0
	beq _08023EB2
	movs r6, 0x6
_08023EB2:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _08023EEA
	movs r6, 0x5
	b _08023EEA
	.align 2, 0
_08023EBC: .4byte sUnknown_80DC980
_08023EC0: .4byte 0x000003f6
_08023EC4: .4byte 0x00000376
_08023EC8: .4byte gUnknown_3001B60
_08023ECC: .4byte 0x00000372
_08023ED0: .4byte gRecruitedPokemonRef
_08023ED4:
	ldrb r0, [r3, 0x18]
	cmp r0, 0
	beq _08023EEA
	adds r0, r5, 0
	bl sub_808D750
	lsls r0, 24
	movs r6, 0x2
	cmp r0, 0
	beq _08023EEA
	movs r6, 0x4
_08023EEA:
	mov r0, r8
	ldr r1, [r0]
	ldr r0, [r1]
	cmp r0, 0x4
	bne _08023F02
	movs r2, 0xD5
	lsls r2, 2
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8024184
_08023F02:
	adds r1, r4, 0
	adds r1, 0x4C
	mov r0, r9
	movs r2, 0xA
	bl sub_80922B4
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	add r0, sp, 0x44
	bl sub_808D930
	add r0, sp, 0x8
	ldr r1, _08023F80
	adds r2, r6, 0
	mov r3, r9
	bl sprintfStatic
	mov r1, r8
	ldr r0, [r1]
	movs r2, 0xD6
	lsls r2, 2
	adds r0, r2
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	mov r4, r8
	ldr r0, [r4]
	movs r2, 0xE3
	lsls r2, 2
	adds r0, r2
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl PrintStringOnWindow
	adds r7, 0x1
	mov r1, r8
	ldr r0, [r4]
	ldr r4, _08023F84
	adds r0, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _08023F62
	b _08023E56
_08023F62:
	ldr r0, _08023F88
	ldr r0, [r0]
	movs r4, 0xE3
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023F80: .4byte sUnknown_80DC998
_08023F84: .4byte 0x00000372
_08023F88: .4byte gUnknown_3001B60
	thumb_func_end sub_8023DA4

	thumb_func_start sub_8023F8C
sub_8023F8C:
	push {r4-r7,lr}
	ldr r2, _08023FD0
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x8]
	ldrb r0, [r1, 0x15]
	adds r6, r2, 0
	cmp r0, 0
	bne _08023FE2
	movs r4, 0
	ldr r2, _08023FD4
_08023FA2:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08023FD8
	ldrb r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08023FD8
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	b _08023FE2
	.align 2, 0
_08023FD0: .4byte gUnknown_3001B60
_08023FD4: .4byte gRecruitedPokemonRef
_08023FD8:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08023FA2
_08023FE2:
	ldr r0, [r6]
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	bne _08024042
	movs r4, 0
	ldr r3, _08024034
_08023FEE:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r3]
	adds r1, r0, r1
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08024002
	movs r2, 0x1
_08024002:
	cmp r2, 0
	beq _08024038
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08024038
	ldrh r1, [r1]
	lsrs r0, r1, 1
	movs r2, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08024038
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08024038
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	b _08024042
	.align 2, 0
_08024034: .4byte gRecruitedPokemonRef
_08024038:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08023FEE
_08024042:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	str r1, [r0, 0xC]
	ldrb r0, [r0, 0x17]
	cmp r0, 0
	bne _080240A4
	movs r4, 0
	ldr r7, _08024100
	movs r5, 0x1
_08024054:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r7]
	adds r1, r0, r1
	ldrh r2, [r1]
	lsrs r0, r2, 1
	ands r0, r5
	cmp r0, 0
	beq _0802409A
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _0802409A
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _0802409A
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08024080
	movs r2, 0x1
_08024080:
	cmp r2, 0
	bne _0802409A
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	cmp r1, 0x3
	bgt _080240A4
_0802409A:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08024054
_080240A4:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	str r1, [r0, 0x10]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080240EE
	movs r4, 0
	ldr r7, _08024100
	movs r5, 0x1
_080240B6:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r7]
	adds r1, r0, r1
	ldrh r1, [r1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080240E4
	lsrs r0, r1, 1
	ands r0, r5
	cmp r0, 0
	bne _080240E4
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
_080240E4:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _080240B6
_080240EE:
	bl sub_80241A8
	ldr r0, _08024104
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08024100: .4byte gRecruitedPokemonRef
_08024104: .4byte gUnknown_3001B60
	thumb_func_end sub_8023F8C

	thumb_func_start sub_8024108
sub_8024108:
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r7, 0
	movs r6, 0x1
_08024110:
	ldr r2, _08024134
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08024172
	cmp r5, 0x2
	bne _08024138
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _08024172
	b _0802416E
	.align 2, 0
_08024134: .4byte gRecruitedPokemonRef
_08024138:
	cmp r5, 0x3
	bne _08024140
	lsrs r0, r1, 1
	b _08024168
_08024140:
	cmp r5, 0x4
	bne _0802416E
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _08024172
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0802416E
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _08024160
	movs r1, 0x1
_08024160:
	cmp r1, 0
	beq _0802416E
	ldrh r0, [r4]
	lsrs r0, 1
_08024168:
	ands r0, r6
	cmp r0, 0
	bne _08024172
_0802416E:
	movs r0, 0
	b _0802417E
_08024172:
	adds r7, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r7, r0
	ble _08024110
	movs r0, 0x1
_0802417E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8024108

        .align 2,0