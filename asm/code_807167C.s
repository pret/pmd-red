	.include "constants/gba_constants.inc"
  	.include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_807167C
sub_807167C:
	push {lr}
	ldr r2, [r0, 0x70]
	ldr r1, [r1, 0x70]
	adds r0, r2, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080716D2
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0807169A
	cmp r0, 0x47
	bne _0807169E
_0807169A:
	movs r0, 0x1
	b _080716A0
_0807169E:
	movs r0, 0
_080716A0:
	cmp r0, 0
	bne _080716D2
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _080716D2
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080716D2
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _080716C2
	cmp r0, 0x47
	bne _080716C6
_080716C2:
	movs r0, 0x1
	b _080716C8
_080716C6:
	movs r0, 0
_080716C8:
	cmp r0, 0
	bne _080716D2
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _080716D6
_080716D2:
	movs r0, 0x2
	b _080716E4
_080716D6:
	ldrb r0, [r2, 0x6]
	ldrb r1, [r1, 0x6]
	cmp r0, r1
	bne _080716E2
	movs r0, 0
	b _080716E4
_080716E2:
	movs r0, 0x1
_080716E4:
	pop {r1}
	bx r1
	thumb_func_end sub_807167C

	.align 2, 0
