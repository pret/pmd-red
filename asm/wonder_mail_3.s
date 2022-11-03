        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802D5A4
sub_802D5A4:
	push {r4-r7,lr}
	ldr r4, _0802D630
	ldr r0, [r4]
	movs r5, 0xCC
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0
	movs r1, 0x8C
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D634
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x8E
	lsls r1, 1
	add r1, r12
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0x90
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D638
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x92
	lsls r1, 1
	add r1, r12
	movs r0, 0x5
	str r0, [r1]
	movs r7, 0x2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r6, 0
	movs r3, 0x8E
	lsls r3, 1
	add r3, r12
	mov r0, r12
	adds r2, r0, r5
_0802D60A:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0802D61A
	ldr r1, [r3]
	mov r5, r12
	ldr r0, [r5, 0x6C]
	cmp r1, r0
	beq _0802D62A
_0802D61A:
	adds r3, 0x8
	adds r2, 0x2
	adds r6, 0x1
	cmp r6, r7
	blt _0802D60A
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x6C]
_0802D62A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D630: .4byte gUnknown_203B2F8
_0802D634: .4byte gUnknown_80D494C
_0802D638: .4byte gUnknown_80D4970
	thumb_func_end sub_802D5A4

	thumb_func_start sub_802D63C
sub_802D63C:
	ldr r0, _0802D684
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D688
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D68C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_0802D684: .4byte gUnknown_203B2F8
_0802D688: .4byte gUnknown_80D4920
_0802D68C: .4byte gUnknown_80D4928
	thumb_func_end sub_802D63C

	thumb_func_start sub_802D690
sub_802D690:
	push {r4,r5,lr}
	ldr r2, _0802D728
	ldr r0, [r2]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D72C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r3, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D730
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D734
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0xB8
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D738
	str r0, [r1]
	movs r1, 0xBA
	lsls r1, 1
	add r1, r12
	movs r0, 0x7
	str r0, [r1]
	movs r5, 0x4
	movs r0, 0xBC
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBE
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r3, 0
	mov r0, r12
	ldr r4, [r0, 0x74]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D70E:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D722
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802D70E
	ldr r1, [r2]
	movs r0, 0x4
	str r0, [r1, 0x74]
_0802D722:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D728: .4byte gUnknown_203B2F8
_0802D72C: .4byte gUnknown_80D4920
_0802D730: .4byte gUnknown_80D4928
_0802D734: .4byte gUnknown_80E014C
_0802D738: .4byte gUnknown_80E0158
	thumb_func_end sub_802D690

	thumb_func_start sub_802D73C
sub_802D73C:
	push {r4,r5,lr}
	ldr r3, _0802D7C0
	ldr r0, [r3]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7CC
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r5, 0x3
	movs r0, 0xB8
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r2, 0
	mov r0, r12
	ldr r4, [r0, 0x70]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D7A6:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D7BA
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r5
	blt _0802D7A6
	ldr r1, [r3]
	movs r0, 0x4
	str r0, [r1, 0x70]
_0802D7BA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D7C0: .4byte gUnknown_203B2F8
_0802D7C4: .4byte gUnknown_80D4920
_0802D7C8: .4byte gUnknown_80D4928
_0802D7CC: .4byte gUnknown_80E014C
	thumb_func_end sub_802D73C

        .align 2,0
