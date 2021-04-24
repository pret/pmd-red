        .include "constants/gba_constants.inc"
        .include "asm/macros.inc"

        .syntax unified

        .text

	thumb_func_start sub_808DA44
sub_808DA44:
	push {r4-r6,lr}
	sub sp, 0x30
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r2, 0xC
	bls _0808DAA0
	mov r1, sp
	ldr r0, _0808DA98
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0808DA92
	mov r1, sp
	add r3, sp, 0x48
_0808DA76:
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r4
	bne _0808DA84
	ldr r0, [r1, 0x4]
	cmp r0, r2
	beq _0808DA9C
_0808DA84:
	adds r1, 0x8
	cmp r1, r3
	bgt _0808DA92
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, 0
	bne _0808DA76
_0808DA92:
	movs r0, 0
	b _0808DAA6
	.align 2, 0
_0808DA98: .4byte gUnknown_8107654
_0808DA9C:
	movs r0, 0x1
	b _0808DAA6
_0808DAA0:
	ldr r0, _0808DAB0
	adds r0, r2, r0
	ldrb r0, [r0]
_0808DAA6:
	add sp, 0x30
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0808DAB0: .4byte gUnknown_8107645
	thumb_func_end sub_808DA44

        .align 2,0
