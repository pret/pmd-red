	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_800EF64
sub_800EF64:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, _0800EF9C
	mov r9, r0
	movs r1, 0x4
	mov r8, r1
	movs r7, 0
	movs r6, 0
	movs r5, 0x1
_0800EF7A:
	mov r0, r9
	ldr r1, [r0]
	adds r0, r1, 0x4
	adds r0, r7
	ldr r0, [r0]
	cmp r0, 0
	beq _0800F01A
	mov r0, r8
	adds r4, r1, r0
	ldr r0, [r4]
	cmp r0, 0x3
	beq _0800EFA0
	cmp r0, 0x3
	bls _0800F018
	cmp r0, 0x4
	beq _0800EFDA
	b _0800F018
	.align 2, 0
_0800EF9C: .4byte gUnknown_203B0D0
_0800EFA0:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0x18]
	bl sub_8005674
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	cmp r0, 0
	beq _0800EFCA
	cmp r0, 0x1
	bne _0800F00C
	ldr r0, [r4, 0x8]
	ldr r1, [r0, 0x18]
	ldr r0, [r4, 0xC]
	adds r0, 0x10
	lsls r0, 20
	lsrs r0, 16
	movs r2, 0x10
	bl sub_809971C
	b _0800F00C
_0800EFCA:
	ldr r0, [r4, 0xC]
	ldr r1, [r4, 0x8]
	ldr r1, [r1, 0x18]
	ldr r2, [r4, 0x1C]
	ldr r3, [r4, 0x20]
	bl sub_8005770
	b _0800F00C
_0800EFDA:
	bl sub_8000728
	cmp r0, 0x1
	bne _0800F000
	movs r0, 0
	movs r1, 0x1
	bl sub_800CD64
	movs r0, 0
	bl sub_8052210
	movs r0, 0x5
	movs r1, 0
	bl sub_803EAF0
	bl sub_800CB20
	bl xxx_call_update_bg_vram
_0800F000:
	ldr r0, [r4, 0x8]
	ldr r1, [r4, 0xC]
	ldr r2, [r4, 0x10]
	ldr r3, [r4, 0x14]
	bl sub_8009A1C
_0800F00C:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0800F018
	bl sub_800F204
	str r6, [r4, 0x4]
_0800F018:
	str r6, [r4]
_0800F01A:
	movs r0, 0x24
	add r8, r0
	adds r7, 0x24
	subs r5, 0x1
	cmp r5, 0
	bge _0800EF7A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800EF64

    .align 2,0
