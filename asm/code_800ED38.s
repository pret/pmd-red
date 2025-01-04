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

	thumb_func_start sub_800F034
sub_800F034:
	push {r4-r6,lr}
	ldr r4, _0800F074
	ldr r0, [r4]
	cmp r0, 0
	bne _0800F04E
	movs r0, 0x10
	movs r1, 0xB
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x10
	bl MemoryClear8
_0800F04E:
	movs r3, 0
	adds r6, r4, 0
	movs r5, 0x1
	negs r5, r5
	movs r4, 0
_0800F058:
	ldr r0, [r6]
	lsls r2, r3, 3
	adds r1, r0, r2
	str r5, [r1]
	adds r0, 0x4
	adds r0, r2
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F058
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F074: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F034

	thumb_func_start sub_800F078
sub_800F078:
	push {r4,lr}
	ldr r4, _0800F090
	ldr r0, [r4]
	cmp r0, 0
	beq _0800F08A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0800F08A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F090: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F078

	thumb_func_start sub_800F094
sub_800F094:
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, _0800F0BC
	movs r5, 0x1
	negs r5, r5
	movs r4, 0
_0800F0A0:
	ldr r0, [r6]
	lsls r2, r3, 3
	adds r1, r0, r2
	str r5, [r1]
	adds r0, 0x4
	adds r0, r2
	str r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F0A0
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800F0BC: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F094

	thumb_func_start sub_800F0C0
sub_800F0C0:
	push {lr}
	cmp r0, 0x3
	bne _0800F0D8
	ldr r0, _0800F0D4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, r1
	bne _0800F0EC
	movs r0, 0
	b _0800F0F0
	.align 2, 0
_0800F0D4: .4byte gUnknown_203B0D4
_0800F0D8:
	ldr r0, _0800F0E8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	cmp r0, r1
	bne _0800F0EC
	movs r0, 0x1
	b _0800F0F0
	.align 2, 0
_0800F0E8: .4byte gUnknown_203B0D4
_0800F0EC:
	movs r0, 0x3
	negs r0, r0
_0800F0F0:
	pop {r1}
	bx r1
	thumb_func_end sub_800F0C0

	thumb_func_start sub_800F0F4
sub_800F0F4:
	push {lr}
	cmp r0, 0x3
	bne _0800F114
	ldr r0, _0800F110
	ldr r2, [r0]
	ldr r0, [r2]
	cmp r0, r1
	beq _0800F11E
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _0800F132
	movs r0, 0
	b _0800F136
	.align 2, 0
_0800F110: .4byte gUnknown_203B0D4
_0800F114:
	ldr r0, _0800F124
	ldr r2, [r0]
	ldr r0, [r2, 0x8]
	cmp r0, r1
	bne _0800F128
_0800F11E:
	movs r0, 0x2
	negs r0, r0
	b _0800F136
	.align 2, 0
_0800F124: .4byte gUnknown_203B0D4
_0800F128:
	ldr r0, [r2, 0xC]
	cmp r0, 0
	bne _0800F132
	movs r0, 0x1
	b _0800F136
_0800F132:
	movs r0, 0x1
	negs r0, r0
_0800F136:
	pop {r1}
	bx r1
	thumb_func_end sub_800F0F4

	thumb_func_start sub_800F13C
sub_800F13C:
	push {lr}
	ldr r1, _0800F158
	ldr r3, [r1]
	lsls r1, r0, 3
	adds r0, r3, 0x4
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0800F154
	adds r1, r3, r1
	ldr r0, [r2, 0x4]
	str r0, [r1]
_0800F154:
	pop {r0}
	bx r0
	.align 2, 0
_0800F158: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F13C

	thumb_func_start sub_800F15C
sub_800F15C:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r3, 0
	ldr r5, _0800F17C
_0800F164:
	ldr r1, [r5]
	lsls r2, r3, 3
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _0800F180
	adds r1, 0x4
	adds r1, r2
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	b _0800F186
	.align 2, 0
_0800F17C: .4byte gUnknown_203B0D4
_0800F180:
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800F164
_0800F186:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800F15C

	thumb_func_start sub_800F18C
sub_800F18C:
	ldr r1, _0800F198
	lsls r0, 3
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.align 2, 0
_0800F198: .4byte gUnknown_203B0D4
	thumb_func_end sub_800F18C

	thumb_func_start sub_800F19C
sub_800F19C:
	push {lr}
	ldr r1, _0800F1B4
	ldr r1, [r1]
	lsls r0, 3
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _0800F1B8
	movs r0, 0x1
	b _0800F1BA
	.align 2, 0
_0800F1B4: .4byte gUnknown_203B0D4
_0800F1B8:
	movs r0, 0
_0800F1BA:
	pop {r1}
	bx r1
	thumb_func_end sub_800F19C

    .align 2,0
