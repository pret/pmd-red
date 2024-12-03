        #include "asm/constants/gba_constants.inc"
        #include "asm/macros.inc"

        .syntax unified

        .text

	thumb_func_start GetUnitSum_808D544
GetUnitSum_808D544:
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r0, _0808D57C
	ldr r3, [r0]
	movs r5, 0
	movs r2, 0
	movs r7, 0x1
	movs r6, 0xCE
	lsls r6, 1
	adds r1, r4, 0
_0808D558:
	ldrh r0, [r3]
	lsrs r0, 1
	ands r0, r7
	cmp r0, 0
	beq _0808D56C
	cmp r4, 0
	beq _0808D568
	str r2, [r1]
_0808D568:
	adds r1, 0x4
	adds r5, 0x1
_0808D56C:
	adds r2, 0x1
	adds r3, 0x58
	cmp r2, r6
	ble _0808D558
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808D57C: .4byte gRecruitedPokemonRef
	thumb_func_end GetUnitSum_808D544

	thumb_func_start sub_808D580
sub_808D580:
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, _0808D5AC
	ldr r2, [r0]
	movs r5, 0
	movs r4, 0
	mov r12, r0
	adds r3, r6, 0
_0808D590:
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	beq _0808D5B0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808D5B0
	cmp r6, 0
	beq _0808D5B0
	str r4, [r3]
	adds r5, 0x1
	b _0808D5BC
	.align 2, 0
_0808D5AC: .4byte gRecruitedPokemonRef
_0808D5B0:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D590
_0808D5BC:
	mov r0, r12
	ldr r2, [r0]
	movs r4, 0
	lsls r0, r5, 2
	adds r7, r0, r6
_0808D5C6:
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D5D0
	movs r1, 0x1
_0808D5D0:
	cmp r1, 0
	beq _0808D5F8
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D5F8
	ldrh r1, [r2]
	lsrs r0, r1, 1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0808D5F8
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D5F8
	cmp r6, 0
	beq _0808D5F8
	str r4, [r7]
	adds r5, 0x1
	b _0808D604
_0808D5F8:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D5C6
_0808D604:
	mov r0, r12
	ldr r2, [r0]
	movs r4, 0
	movs r3, 0x1
	lsls r0, r5, 2
	adds r7, r0, r6
_0808D610:
	ldrh r1, [r2]
	lsrs r0, r1, 1
	ands r0, r3
	cmp r0, 0
	beq _0808D63E
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0808D63E
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _0808D63E
	movs r1, 0
	ldrb r0, [r2, 0x4]
	cmp r0, 0x41
	bne _0808D632
	movs r1, 0x1
_0808D632:
	cmp r1, 0
	bne _0808D63E
	cmp r6, 0
	beq _0808D63E
	stm r7!, {r4}
	adds r5, 0x1
_0808D63E:
	adds r4, 0x1
	adds r2, 0x58
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _0808D610
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_808D580

    .align 2,0
