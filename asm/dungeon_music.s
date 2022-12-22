	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_80840A4
sub_80840A4:
	ldr r3, _080840C8
	ldr r0, [r3]
	ldr r2, _080840CC
	adds r1, r0, 0
	muls r1, r2
	adds r1, 0x1
	lsrs r0, r1, 16
	muls r1, r2
	adds r1, 0x1
	str r1, [r3]
	ldr r2, _080840D0
	ands r1, r2
	orrs r0, r1
	ldr r1, _080840D4
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	bx lr
	.align 2, 0
_080840C8: .4byte gUnknown_203B458
_080840CC: .4byte 0x5d588b65
_080840D0: .4byte 0xffff0000
_080840D4: .4byte 0x00ffffff
	thumb_func_end sub_80840A4

        .align 2,0
