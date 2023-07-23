	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CreateFelicityBankShopMenu
CreateFelicityBankShopMenu:
	push {r4-r7,lr}
	ldr r4, _08016980
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08016984
	ldr r0, [r0]
	str r0, [r3, 0x14]
	movs r0, 0x2
	str r0, [r3, 0x18]
	movs r1, 0x1
	ldr r0, _08016988
	ldr r0, [r0]
	str r0, [r3, 0x1C]
	movs r0, 0x3
	str r0, [r3, 0x20]
	ldr r0, _0801698C
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x4
	str r0, [r3, 0x28]
	ldr r0, _08016990
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	str r1, [r3, 0x30]
	movs r6, 0x4
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x18
	mov r2, r12
	adds r2, 0x54
_0801694C:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0801695C
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x10]
	cmp r1, r0
	beq _080169B6
_0801695C:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0801694C
	movs r5, 0
	cmp r5, r6
	bge _080169B6
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x54
	ldrh r0, [r0]
	cmp r0, 0
	bne _08016994
	ldr r0, [r1, 0x18]
	str r0, [r1, 0x10]
	b _080169B6
	.align 2, 0
_08016980: .4byte gFelicityBankWork
_08016984: .4byte gUnknown_80D4958
_08016988: .4byte gUnknown_80D4964
_0801698C: .4byte gUnknown_80D4970
_08016990: .4byte gUnknown_80D4934
_08016994:
	adds r5, 0x1
	cmp r5, r6
	bge _080169B6
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x54
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08016994
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x18
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x10]
_080169B6:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateFelicityBankShopMenu

        .align 2,0
