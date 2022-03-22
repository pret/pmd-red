	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start GroundMap_GetStationScript
GroundMap_GetStationScript:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	lsls r4, 16
	asrs r4, 16
	lsls r6, 16
	asrs r6, 16
	lsls r5, 24
	asrs r5, 24
	adds r0, r4, 0
	bl sub_80A77A0
	ldr r1, _080A4BE0
	adds r0, r4, 0
	bl sub_80A77D0
	mov r9, r0
	ldr r1, _080A4BE4
	str r5, [sp]
	movs r0, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl Log
	lsls r1, r6, 3
	mov r2, r9
	ldr r0, [r2, 0x4]
	adds r0, r1
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	ldr r0, [r0, 0x4]
	adds r0, r1
	ldr r0, [r0, 0x24]
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	mov r1, r8
	str r0, [r1]
	movs r0, 0x2
	strh r0, [r1, 0x4]
	strh r6, [r1, 0x6]
	strb r5, [r1, 0x8]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4BE0: .4byte gUnknown_8117560
_080A4BE4: .4byte gUnknown_811756C
	thumb_func_end GroundMap_GetStationScript
