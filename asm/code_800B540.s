	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800B540
sub_800B540:
	push {r4,lr}
	ldr r1, _0800B5C8
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x14
_0800B54A:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _0800B54A
	bl nullsub_17
	bl sub_800BD08
	ldr r1, _0800B5CC
_0800B55C:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bls _0800B55C
	ldr r4, _0800B5D0
	ldrh r0, [r4]
	movs r1, 0x45
	eors r0, r1
	strh r0, [r4]
	movs r2, 0x80
	lsls r2, 19
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0800B5D4
	bl sub_800B6B0
	ldr r1, _0800B5D8
	movs r0, 0xC1
	lsls r0, 16
	str r0, [r1]
	ldrh r0, [r4]
	ldr r2, _0800B5DC
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _0800B5E0
	movs r0, 0x28
	strh r0, [r1]
	ldr r1, _0800B5E4
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, _0800B5E8
	movs r0, 0
	strh r0, [r1]
	bl sub_800D6AC
	bl sub_800D7D0
	ldr r1, _0800B5EC
	movs r0, 0x1
	strb r0, [r1]
	bl EnableInterrupts
	ldr r1, _0800B5CC
_0800B5BA:
	ldrh r0, [r1]
	cmp r0, 0x9F
	bls _0800B5BA
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B5C8: .4byte gUnknown_202D5F0
_0800B5CC: .4byte 0x04000006
_0800B5D0: .4byte 0x04000200
_0800B5D4: .4byte gUnknown_80B9C00
_0800B5D8: .4byte 0x0400010c
_0800B5DC: .4byte 0x00002045
_0800B5E0: .4byte 0x04000004
_0800B5E4: .4byte gUnknown_203B0AE
_0800B5E8: .4byte gUnknown_203B0AC
_0800B5EC: .4byte gInterruptsEnabled
	thumb_func_end sub_800B540


	.align 2, 0 @ Don't pad with nop.
