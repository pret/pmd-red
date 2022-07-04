	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80175FC
sub_80175FC:
	push {r4-r7,lr}
	ldr r4, _0801767C
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017680
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _08017684
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x3
	str r0, [r3, 0x30]
	ldr r0, _08017688
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x6
	str r0, [r3, 0x38]
	ldr r0, _0801768C
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	str r1, [r3, 0x40]
	movs r6, 0x4
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017648:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017658
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _080176B2
_08017658:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017648
	movs r5, 0
	cmp r5, r6
	bge _080176B2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017690
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x18]
	b _080176B2
	.align 2, 0
_0801767C: .4byte gUnknown_203B208
_08017680: .4byte gUnknown_80D4958
_08017684: .4byte gUnknown_80D4964
_08017688: .4byte gUnknown_80D4970
_0801768C: .4byte gUnknown_80D4934
_08017690:
	adds r5, 0x1
	cmp r5, r6
	bge _080176B2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017690
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_080176B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80175FC

	thumb_func_start sub_80176B8
sub_80176B8:
	push {r4-r7,lr}
	ldr r4, _08017724
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017728
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _0801772C
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_080176F2:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017702
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x1C]
	cmp r1, r0
	beq _08017752
_08017702:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080176F2
	movs r5, 0
	cmp r5, r6
	bge _08017752
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017730
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x1C]
	b _08017752
	.align 2, 0
_08017724: .4byte gUnknown_203B208
_08017728: .4byte gUnknown_80D4958
_0801772C: .4byte gUnknown_80D4970
_08017730:
	adds r5, 0x1
	cmp r5, r6
	bge _08017752
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017730
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
_08017752:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80176B8

	thumb_func_start sub_8017758
sub_8017758:
	push {r4-r7,lr}
	ldr r4, _080177C4
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080177C8
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x3
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _080177CC
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017792:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080177A2
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x20]
	cmp r1, r0
	beq _080177F2
_080177A2:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017792
	movs r5, 0
	cmp r5, r6
	bge _080177F2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _080177D0
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x20]
	b _080177F2
	.align 2, 0
_080177C4: .4byte gUnknown_203B208
_080177C8: .4byte gUnknown_80D4964
_080177CC: .4byte gUnknown_80D4970
_080177D0:
	adds r5, 0x1
	cmp r5, r6
	bge _080177F2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080177D0
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
_080177F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8017758

        .align 2,0
