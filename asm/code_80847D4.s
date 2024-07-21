	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_80847D4
sub_80847D4:
	push {r4,r5,lr}
	ldr r2, _08084820
	ldr r0, [r2]
	ldr r1, _08084824
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _08084828
	adds r0, r2
	strb r1, [r0]
	bl sub_8040A84
	movs r4, 0
	ldr r0, _0808482C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08084846
	movs r3, 0
_080847FA:
	ldr r0, _08084820
	ldr r0, [r0]
	ldr r5, _08084830
	adds r0, r5
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r1, 0
	subs r0, 0x1C
	cmp r0, 0x15
	bhi _08084810
	movs r1, 0x1B
_08084810:
	ldr r2, _0808482C
	adds r0, r3, r2
	ldrb r5, [r0]
	cmp r1, r5
	bne _08084834
	bl sub_8084854
	b _08084846
	.align 2, 0
_08084820: .4byte gDungeon
_08084824: .4byte 0x00003a0d
_08084828: .4byte 0x0001356c
_0808482C: .4byte gUnknown_8107234
_08084830: .4byte 0x00003a14
_08084834:
	adds r3, 0x8
	adds r4, 0x1
	ldr r0, _08084850
	cmp r4, r0
	bgt _08084846
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080847FA
_08084846:
	bl sub_8097FF8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084850: .4byte 0x000003e6
	thumb_func_end sub_80847D4

	.align 2,0
