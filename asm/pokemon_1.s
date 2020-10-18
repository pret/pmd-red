        .include "constants/gba_constants.inc"
        .include "asm/macros.inc"

        .syntax unified

        .text


	thumb_func_start sub_808DC28
sub_808DC28:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0808DC44
	ldr r3, [r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	lsls r1, 1
	adds r2, 0x24
	adds r2, r1
	ldrh r0, [r2]
	bx lr
	.align 2, 0
_0808DC44: .4byte gMonsterParameters
	thumb_func_end sub_808DC28

	thumb_func_start sub_808DC48
sub_808DC48:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0808DC64
	ldr r3, [r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	lsls r1, 1
	adds r2, 0x28
	adds r2, r1
	ldrh r0, [r2]
	bx lr
	.align 2, 0
_0808DC64: .4byte gMonsterParameters
	thumb_func_end sub_808DC48

	thumb_func_start sub_808DC68
sub_808DC68:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0808DC80
	ldr r3, [r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	adds r2, 0x13
	adds r2, r1
	ldrb r0, [r2]
	bx lr
	.align 2, 0
_0808DC80: .4byte gMonsterParameters
	thumb_func_end sub_808DC68

	thumb_func_start sub_808DC84
sub_808DC84:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0808DC9C
	ldr r3, [r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	adds r2, 0x17
	adds r2, r1
	ldrb r0, [r2]
	bx lr
	.align 2, 0
_0808DC9C: .4byte gMonsterParameters
	thumb_func_end sub_808DC84

	thumb_func_start sub_808DCA0
sub_808DCA0:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0808DCBC
	ldr r3, [r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	lsls r1, 1
	adds r2, 0x3C
	adds r2, r1
	movs r1, 0
	ldrsh r0, [r2, r1]
	bx lr
	.align 2, 0
_0808DCBC: .4byte gMonsterParameters
	thumb_func_end sub_808DCA0

	thumb_func_start sub_808DCC0
sub_808DCC0:
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0808DCD8
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	adds r1, 0x40
	movs r2, 0
	ldrsh r0, [r1, r2]
	bx lr
	.align 2, 0
_0808DCD8: .4byte gMonsterParameters
	thumb_func_end sub_808DCC0

	thumb_func_start sub_808DCDC
sub_808DCDC:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0808DCF8
	ldr r3, [r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	lsls r1, 1
	adds r2, 0x42
	adds r2, r1
	movs r1, 0
	ldrsh r0, [r2, r1]
	bx lr
	.align 2, 0
_0808DCF8: .4byte gMonsterParameters
	thumb_func_end sub_808DCDC

	thumb_func_start sub_808DCFC
sub_808DCFC:
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0808DD14
	ldr r2, [r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r2, 0x3E
	ldrsh r0, [r1, r2]
	bx lr
	.align 2, 0
_0808DD14: .4byte gMonsterParameters
	thumb_func_end sub_808DCFC

	thumb_func_start sub_808DD18
sub_808DD18:
	push {r4,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0808DD44
	ldr r3, [r2]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	adds r2, r3
	ldr r4, [r2, 0x20]
	subs r1, 0x1
	adds r0, r4, 0
	muls r0, r1
	movs r1, 0xA
	bl __divsi3
	adds r4, r0
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808DD44: .4byte gMonsterParameters
	thumb_func_end sub_808DD18

        .align 2,0 @ don't pad with nop
