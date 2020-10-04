	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80001DC
sub_80001DC:
	mov r0, sp
	bx lr
	thumb_func_end sub_80001DC

	thumb_func_start sub_80001E0
sub_80001E0:
	ldr r0, _080001E4
	bx lr
	.align 2, 0
_080001E4: .4byte gUnknown_3004000
	thumb_func_end sub_80001E0

	.align 2, 0 @ Don't pad with nop.
