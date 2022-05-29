	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_807BB78
sub_807BB78:
	ldr r3, [r0, 0x70]
	adds r1, r3, 0
	adds r1, 0x78
	movs r2, 0
	strb r2, [r1]
	adds r1, 0x10
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x80
	str r2, [r0]
	subs r0, 0x4
	strh r2, [r0]
	bx lr
	thumb_func_end sub_807BB78

	.align 2, 0