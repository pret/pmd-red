	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_8002B5C
sub_8002B5C:
	push {lr}
	lsls r0, 24
	asrs r2, r0, 24
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08002BAE
	adds r0, r2, 0
	subs r0, 0x8
	subs r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B7C
	adds r0, r1, 0x7
_08002B7C:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	cmp r0, 0
	beq _08002BAE
	cmp r0, 0x3
	bgt _08002B98
	adds r1, r2, 0x2
	adds r0, r1, 0
	cmp r1, 0
	bge _08002BA4
	adds r0, r2, 0
	adds r0, 0x9
	b _08002BA4
_08002B98:
	adds r1, r2, 0x6
	adds r0, r1, 0
	cmp r1, 0
	bge _08002BA4
	adds r0, r2, 0
	adds r0, 0xD
_08002BA4:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	lsls r0, 24
	asrs r2, r0, 24
_08002BAE:
	movs r0, 0x6
	ands r2, r0
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8002B5C

	thumb_func_start SetVecFromDirectionSpeed
SetVecFromDirectionSpeed:
	push {r4,r5,lr}
	lsls r1, 24
	asrs r1, 21
	ldr r3, _08002BD8
	adds r1, r3
	ldr r5, [r1]
	adds r3, r5, 0
	muls r3, r2
	ldr r1, [r1, 0x4]
	adds r4, r1, 0
	muls r4, r2
	str r3, [r0]
	str r4, [r0, 0x4]
	pop {r4,r5}
	pop {r2}
	bx r2
	.align 2, 0
_08002BD8: .4byte gVectorDirections
	thumb_func_end SetVecFromDirectionSpeed

	thumb_func_start VecDirection8Sign
VecDirection8Sign:
	push {lr}
	ldr r1, [r0]
	cmp r1, 0
	bge _08002BFA
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002BEE
	movs r0, 0x5
	b _08002C2A
_08002BEE:
	cmp r0, 0
	ble _08002BF6
	movs r0, 0x7
	b _08002C2A
_08002BF6:
	movs r0, 0x6
	b _08002C2A
_08002BFA:
	cmp r1, 0
	ble _08002C14
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002C08
	movs r0, 0x3
	b _08002C2A
_08002C08:
	cmp r0, 0
	ble _08002C10
	movs r0, 0x1
	b _08002C2A
_08002C10:
	movs r0, 0x2
	b _08002C2A
_08002C14:
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002C1E
	movs r0, 0x4
	b _08002C2A
_08002C1E:
	cmp r0, 0
	bgt _08002C28
	movs r0, 0x1
	negs r0, r0
	b _08002C2A
_08002C28:
	movs r0, 0
_08002C2A:
	pop {r1}
	bx r1
	thumb_func_end VecDirection8Sign

	thumb_func_start VecDirection4SignYX
VecDirection4SignYX:
	push {lr}
	ldr r1, [r0, 0x4]
	cmp r1, 0
	bge _08002C3C
	movs r0, 0x4
	b _08002C5A
_08002C3C:
	cmp r1, 0
	ble _08002C44
	movs r0, 0
	b _08002C5A
_08002C44:
	ldr r0, [r0]
	cmp r0, 0
	bge _08002C4E
	movs r0, 0x6
	b _08002C5A
_08002C4E:
	cmp r0, 0
	bgt _08002C58
	movs r0, 0x1
	negs r0, r0
	b _08002C5A
_08002C58:
	movs r0, 0x2
_08002C5A:
	pop {r1}
	bx r1
	thumb_func_end VecDirection4SignYX

	thumb_func_start VecDirection8Radial
VecDirection8Radial:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	cmp r0, 0
	bge _08002C6C
	negs r0, r0
_08002C6C:
	adds r1, r0, 0
	ldr r3, [r4, 0x4]
	adds r5, r3, 0
	cmp r3, 0
	bge _08002C78
	negs r5, r3
_08002C78:
	adds r2, r5, 0
	ldr r4, [r4]
	cmp r4, 0
	bge _08002CA8
	cmp r3, 0
	bge _08002C94
	lsls r0, 1
	cmp r2, r0
	bgt _08002CD8
	lsls r0, r5, 1
	cmp r1, r0
	bgt _08002CA0
	movs r0, 0x5
	b _08002CE8
_08002C94:
	lsls r0, 1
	cmp r2, r0
	bgt _08002CE6
	lsls r0, r5, 1
	cmp r1, r0
	ble _08002CA4
_08002CA0:
	movs r0, 0x6
	b _08002CE8
_08002CA4:
	movs r0, 0x7
	b _08002CE8
_08002CA8:
	cmp r4, 0
	ble _08002CD4
	cmp r3, 0
	bge _08002CC0
	lsls r0, 1
	cmp r2, r0
	bgt _08002CD8
	lsls r0, r5, 1
	cmp r1, r0
	bgt _08002CCC
	movs r0, 0x3
	b _08002CE8
_08002CC0:
	lsls r0, 1
	cmp r2, r0
	bgt _08002CE6
	lsls r0, r5, 1
	cmp r1, r0
	ble _08002CD0
_08002CCC:
	movs r0, 0x2
	b _08002CE8
_08002CD0:
	movs r0, 0x1
	b _08002CE8
_08002CD4:
	cmp r3, 0
	bge _08002CDC
_08002CD8:
	movs r0, 0x4
	b _08002CE8
_08002CDC:
	cmp r3, 0
	bgt _08002CE6
	movs r0, 0x1
	negs r0, r0
	b _08002CE8
_08002CE6:
	movs r0, 0
_08002CE8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end VecDirection8Radial

	thumb_func_start VecDirection4Radial
VecDirection4Radial:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r4]
	cmp r3, 0
	bge _08002CFC
	negs r3, r3
_08002CFC:
	adds r1, r3, 0
	ldr r3, [r4, 0x4]
	adds r0, r3, 0
	cmp r3, 0
	bge _08002D08
	negs r0, r3
_08002D08:
	adds r2, r0, 0
	ldr r0, [r4]
	cmp r0, 0
	bge _08002D22
	cmp r3, 0
	bge _08002D1A
	cmp r2, r1
	bgt _08002D3C
	b _08002D1E
_08002D1A:
	cmp r2, r1
	bgt _08002D4A
_08002D1E:
	movs r0, 0x6
	b _08002D4C
_08002D22:
	cmp r0, 0
	ble _08002D38
	cmp r3, 0
	bge _08002D30
	cmp r2, r1
	bgt _08002D3C
	b _08002D34
_08002D30:
	cmp r2, r1
	bgt _08002D4A
_08002D34:
	movs r0, 0x2
	b _08002D4C
_08002D38:
	cmp r3, 0
	bge _08002D40
_08002D3C:
	movs r0, 0x4
	b _08002D4C
_08002D40:
	cmp r3, 0
	bgt _08002D4A
	movs r0, 0x1
	negs r0, r0
	b _08002D4C
_08002D4A:
	movs r0, 0
_08002D4C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end VecDirection4Radial

	thumb_func_start SizedDeltaDirection4
SizedDeltaDirection4:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [r2]
	ldr r1, [r0]
	subs r3, r1
	str r3, [sp]
	ldr r1, [r2, 0x4]
	ldr r0, [r0, 0x4]
	subs r1, r0
	str r1, [sp, 0x4]
	adds r2, r3, 0
	cmp r2, 0
	blt _08002D8A
	adds r2, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp]
	cmp r2, 0
	bge _08002DA4
	b _08002DA0
_08002D8A:
	subs r2, r3, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp]
	cmp r2, 0
	ble _08002DA4
_08002DA0:
	movs r0, 0
	str r0, [sp]
_08002DA4:
	ldr r2, [sp, 0x4]
	cmp r2, 0
	blt _08002DC2
	adds r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	bge _08002DDC
	b _08002DD8
_08002DC2:
	subs r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	ble _08002DDC
_08002DD8:
	movs r0, 0
	str r0, [sp, 0x4]
_08002DDC:
	mov r0, sp
	bl VecDirection4Radial
	lsls r0, 24
	asrs r0, 24
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end SizedDeltaDirection4

	thumb_func_start SizedDeltaDirection8
SizedDeltaDirection8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [r2]
	ldr r1, [r0]
	subs r3, r1
	str r3, [sp]
	ldr r1, [r2, 0x4]
	ldr r0, [r0, 0x4]
	subs r1, r0
	str r1, [sp, 0x4]
	adds r2, r3, 0
	cmp r2, 0
	blt _08002E26
	adds r2, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp]
	cmp r2, 0
	bge _08002E40
	b _08002E3C
_08002E26:
	subs r2, r3, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp]
	cmp r2, 0
	ble _08002E40
_08002E3C:
	movs r0, 0
	str r0, [sp]
_08002E40:
	ldr r2, [sp, 0x4]
	cmp r2, 0
	blt _08002E5E
	adds r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	bge _08002E78
	b _08002E74
_08002E5E:
	subs r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	ble _08002E78
_08002E74:
	movs r0, 0
	str r0, [sp, 0x4]
_08002E78:
	mov r0, sp
	bl VecDirection8Radial
	lsls r0, 24
	asrs r0, 24
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end SizedDeltaDirection8

	.align 2, 0 @ Don't pad with nop.
