	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CpuSet
CpuSet:
	swi 0xB
	bx lr
	thumb_func_end CpuSet

	thumb_func_start SoundBiasReset
SoundBiasReset:
	movs r0, 0
	swi 0x19
	bx lr
	thumb_func_end SoundBiasReset

	thumb_func_start SoundBiasSet
SoundBiasSet:
	movs r0, 0x1
	swi 0x19
	bx lr
	thumb_func_end SoundBiasSet

	thumb_func_start VBlankIntrWait
VBlankIntrWait:
	movs r2, 0
	swi 0x5
	bx lr
	thumb_func_end VBlankIntrWait

	.align 2, 0 @ Don't pad with nop.
