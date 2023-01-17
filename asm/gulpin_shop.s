        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801EA28
sub_801EA28:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801EA44
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _0801EA3A
	b _0801EBB8
_0801EA3A:
	lsls r0, 2
	ldr r1, _0801EA48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EA44: .4byte gUnknown_203B26C
_0801EA48: .4byte _0801EA4C
	.align 2, 0
_0801EA4C:
	.4byte _0801EA60
	.4byte _0801EA80
	.4byte _0801EA8A
	.4byte _0801EAB4
	.4byte _0801EACA
_0801EA60:
	ldr r0, [r4]
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	ldr r2, [r0, 0x10]
	ldr r0, _0801EA7C
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r3, 0
	bl sub_801EE10
	b _0801EBB8
	.align 2, 0
_0801EA7C: .4byte gUnknown_80DC164
_0801EA80:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _0801EBB8
_0801EA8A:
	movs r0, 0
	bl sub_801F280
	ldr r0, _0801EAB0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	adds r1, r2, 0
	adds r1, 0x28
	adds r3, r2, 0
	adds r3, 0x68
	ldr r2, [r2, 0x24]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0801EBB8
	.align 2, 0
_0801EAB0: .4byte gUnknown_203B26C
_0801EAB4:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	adds r2, 0x14
	bl GetLinkedSequence
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_801F808
	b _0801EBB8
_0801EACA:
	bl sub_801EC7C
	ldr r4, _0801EAF8
	ldr r5, _0801EAFC
	ldr r0, [r5]
	ldrh r1, [r0, 0x1C]
	adds r0, r4, 0
	bl sub_8092C84
	adds r4, 0x50
	ldr r0, [r5]
	ldrh r1, [r0, 0x1E]
	adds r0, r4, 0
	bl sub_8092C84
	ldr r2, [r5]
	ldr r3, [r2]
	cmp r3, 0x1
	bls _0801EB00
	cmp r3, 0x2
	beq _0801EB68
	b _0801EBB8
	.align 2, 0
_0801EAF8: .4byte gAvailablePokemonNames
_0801EAFC: .4byte gUnknown_203B26C
_0801EB00:
	ldrb r4, [r2, 0xE]
	cmp r4, 0
	beq _0801EB38
	ldr r1, _0801EB34
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x30
	adds r0, r1
	ldr r0, [r0]
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r4, 0x94
	lsls r4, 1
	adds r1, r2, r4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	b _0801EB86
	.align 2, 0
_0801EB34: .4byte gGulpinDialogue
_0801EB38:
	ldr r1, _0801EB64
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x2C
	adds r0, r1
	ldr r0, [r0]
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r4, 0x94
	lsls r4, 1
	adds r1, r2, r4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	b _0801EB86
	.align 2, 0
_0801EB64: .4byte gGulpinDialogue
_0801EB68:
	ldrb r4, [r2, 0xE]
	cmp r4, 0
	beq _0801EB98
	ldr r0, _0801EB94
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r1, 0x20
_0801EB86:
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _0801EBB8
	.align 2, 0
_0801EB94: .4byte gUnknown_80DC1A0
_0801EB98:
	ldr r0, _0801EBC0
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
_0801EBB8:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801EBC0: .4byte gUnknown_80DC1FC
	thumb_func_end sub_801EA28

	thumb_func_start sub_801EBC4
sub_801EBC4:
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, _0801EC48
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _0801EC4C
	str r0, [r1, 0x28]
	movs r0, 0x2
	str r0, [r1, 0x2C]
	ldrh r0, [r1, 0x1E]
	ldr r1, [r1, 0x10]
	bl IsAnyMoveLinked
	lsls r0, 24
	cmp r0, 0
	beq _0801EBF6
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	cmp r0, 0x3
	ble _0801EBFE
_0801EBF6:
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0x1
	strh r1, [r0]
_0801EBFE:
	adds r5, 0x1
	ldr r4, _0801EC48
	ldr r0, [r4]
	mov r12, r0
	lsls r1, r5, 3
	mov r3, r12
	adds r3, 0x28
	adds r2, r3, r1
	ldr r0, _0801EC50
	ldr r0, [r0]
	str r0, [r2]
	mov r2, r12
	adds r2, 0x2C
	adds r1, r2, r1
	movs r0, 0x3
	str r0, [r1]
	adds r5, 0x1
	lsls r1, r5, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r2, r1
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r5
	bge _0801EC76
	mov r0, r12
	adds r0, 0x68
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801EC54
	mov r1, r12
	ldr r0, [r1, 0x2C]
	str r0, [r1, 0x24]
	b _0801EC76
	.align 2, 0
_0801EC48: .4byte gUnknown_203B26C
_0801EC4C: .4byte gUnknown_80DC230
_0801EC50: .4byte gUnknown_80D4970
_0801EC54:
	adds r3, 0x1
	cmp r3, r5
	bge _0801EC76
	ldr r2, [r4]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x68
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801EC54
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x2C
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x24]
_0801EC76:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801EBC4

	thumb_func_start sub_801EC7C
sub_801EC7C:
	push {r4,lr}
	ldr r4, _0801ECB0
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _0801ECB4
	ldr r0, [r0]
	str r0, [r1, 0x28]
	movs r0, 0x4
	str r0, [r1, 0x2C]
	movs r2, 0x1
	ldr r0, _0801ECB8
	ldr r0, [r0]
	str r0, [r1, 0x30]
	movs r0, 0x5
	str r0, [r1, 0x34]
	str r3, [r1, 0x38]
	str r2, [r1, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801ECB0: .4byte gUnknown_203B26C
_0801ECB4: .4byte gUnknown_80D4920
_0801ECB8: .4byte gUnknown_80D4928
	thumb_func_end sub_801EC7C

	thumb_func_start sub_801ECBC
sub_801ECBC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x3
	beq _0801ECD8
	cmp r0, 0x3
	bhi _0801ECD2
	cmp r0, 0x2
	beq _0801ED18
	b _0801ED22
_0801ECD2:
	cmp r0, 0x4
	beq _0801ECF8
	b _0801ED22
_0801ECD8:
	bl sub_801F194
	ldr r1, _0801ECF4
	ldr r2, [r1]
	str r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x1E]
	movs r0, 0x2
	bl UpdateGulpinShopState
	b _0801ED22
	.align 2, 0
_0801ECF4: .4byte gUnknown_203B26C
_0801ECF8:
	bl sub_801F194
	ldr r1, _0801ED14
	ldr r2, [r1]
	str r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x1E]
	movs r0, 0x3
	bl UpdateGulpinShopState
	b _0801ED22
	.align 2, 0
_0801ED14: .4byte gUnknown_203B26C
_0801ED18:
	bl sub_801F214
	movs r0, 0x6
	bl UpdateGulpinShopState
_0801ED22:
	pop {r0}
	bx r0
	thumb_func_end sub_801ECBC

        .align 2,0
