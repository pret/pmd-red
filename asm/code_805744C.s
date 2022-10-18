	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_80574C4
sub_80574C4:
	push {r4-r6,lr}
	sub sp, 0x104
	adds r4, r0, 0
	adds r5, r1, 0
	movs r3, 0
	movs r2, 0
	ldr r0, [r4]
	cmp r0, 0
	beq _08057502
	cmp r0, r5
	beq _080574EA
_080574DA:
	lsls r0, r3, 2
	mov r6, sp
	adds r1, r6, r0
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r3, 0x1
_080574EA:
	adds r2, 0x1
	cmp r2, 0x40
	bgt _08057502
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _08057502
	cmp r0, r5
	beq _080574EA
	cmp r3, 0x3F
	ble _080574DA
_08057502:
	movs r2, 0
	ldr r0, [r4]
	b _08057524
_08057508:
	lsls r0, r3, 2
	mov r6, sp
	adds r1, r6, r0
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r3, 0x1
_08057518:
	adds r2, 0x1
	cmp r2, 0x40
	bgt _08057530
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
_08057524:
	cmp r0, 0
	beq _08057530
	cmp r0, r5
	bne _08057518
	cmp r3, 0x3F
	ble _08057508
_08057530:
	cmp r3, 0x40
	bgt _08057542
	movs r1, 0
	lsls r0, r3, 2
	add r0, sp
_0805753A:
	stm r0!, {r1}
	adds r3, 0x1
	cmp r3, 0x40
	ble _0805753A
_08057542:
	mov r3, sp
	adds r1, r4, 0
	movs r2, 0x40
_08057548:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x1
	cmp r2, 0
	bge _08057548
	add sp, 0x104
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80574C4

        .align 2,0 @ Don't pad with nop
