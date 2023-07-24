    #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80226F0
sub_80226F0:
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0
	movs r0, 0x80
	strb r0, [r1]
	strb r0, [r1, 0x1]
	movs r0, 0x10
	strb r0, [r1, 0x2]
	strb r2, [r1, 0x3]
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _08022782
	ldr r0, _08022728
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0802275C
	lsls r0, 2
	ldr r1, _0802272C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022728: .4byte gUnknown_203B290
_0802272C: .4byte _08022730
	.align 2, 0
_08022730:
	.4byte _0802275C
	.4byte _08022744
	.4byte _08022750
	.4byte _08022744
	.4byte _08022750
_08022744:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099AFC
	b _08022772
_08022750:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099A5C
	b _08022772
_0802275C:
	ldr r4, _0802278C
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	bl UpdateWigglytuffState
	ldr r0, [r4]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_08022772:
	ldr r0, _0802278C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 1
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08022782:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802278C: .4byte gUnknown_203B290
	thumb_func_end sub_80226F0

	thumb_func_start sub_8022790
sub_8022790:
	push {lr}
	ldr r0, _080227A8
	ldr r2, [r0]
	movs r0, 0x9A
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _080227AC
	subs r0, 0x1
	str r0, [r1]
	b _080227B2
	.align 2, 0
_080227A8: .4byte gUnknown_203B290
_080227AC:
	ldr r0, [r2, 0x8]
	bl UpdateWigglytuffState
_080227B2:
	pop {r0}
	bx r0
	thumb_func_end sub_8022790

    .align 2,0
