	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_80128B0
sub_80128B0:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _080128CC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _080128C2
	b _080129F0
_080128C2:
	lsls r0, 2
	ldr r1, _080128D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080128CC: .4byte gUnknown_203B194
_080128D0: .4byte _080128D4
	.align 2, 0
_080128D4:
	.4byte _080128EC
	.4byte _080128F4
	.4byte _0801291C
	.4byte _080129C8
	.4byte _080129F0
	.4byte _080129E0
_080128EC:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
	b _080129F0
_080128F4:
	bl sub_80140DC
	movs r0, 0x10
	str r0, [sp]
	ldr r4, _08012918
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	ldr r2, [r0, 0x8]
	mov r0, sp
	bl sub_80121D4
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x2
	str r0, [r1]
	movs r0, 0x1
	b _080129F2
	.align 2, 0
_08012918: .4byte gUnknown_203B194
_0801291C:
	movs r0, 0
	str r0, [sp]
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	bne _08012934
	mov r0, sp
	movs r1, 0x2
	bl sub_801203C
	ldr r1, [r4]
	str r0, [r1, 0x10]
_08012934:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _08012964
	cmp r0, 0x1
	beq _080129AC
	ldr r0, _08012958
	bl sub_80121E0
	ldr r0, _0801295C
	ldr r3, _08012960
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x3
	b _080129BC
	.align 2, 0
_08012958: .4byte 0x000f1209
_0801295C: .4byte gUnknown_80D47A0
_08012960: .4byte 0x00000301
_08012964:
	ldr r0, _08012980
	bl sub_80121E0
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	beq _0801298C
	ldr r0, _08012984
	ldr r3, _08012988
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08012998
	.align 2, 0
_08012980: .4byte 0x000f1207
_08012984: .4byte gUnknown_80D45F4
_08012988: .4byte 0x00000301
_0801298C:
	ldr r0, _080129A0
	ldr r3, _080129A4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08012998:
	ldr r0, _080129A8
	ldr r1, [r0]
	movs r0, 0x3
	b _080129BC
	.align 2, 0
_080129A0: .4byte gUnknown_80D4668
_080129A4: .4byte 0x00000301
_080129A8: .4byte gUnknown_203B194
_080129AC:
	ldr r0, _080129C4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x4
_080129BC:
	str r0, [r1]
	bl sub_8014114
	b _080129F0
	.align 2, 0
_080129C4: .4byte gUnknown_80D473C
_080129C8:
	add r0, sp, 0x4
	bl sub_80144A4
	cmp r0, 0
	bne _080129F0
	ldr r0, _080129DC
	ldr r1, [r0]
	movs r0, 0x5
	str r0, [r1]
	b _080129F0
	.align 2, 0
_080129DC: .4byte gUnknown_203B194
_080129E0:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	bne _080129EC
	movs r0, 0x2
	b _080129F2
_080129EC:
	movs r0, 0x3
	b _080129F2
_080129F0:
	movs r0, 0
_080129F2:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80128B0

        .align 2,0
