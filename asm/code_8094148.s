	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8094268
sub_8094268:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	adds r0, r1
	lsls r0, 16
	ldr r6, _080942B0
	ands r3, r6
	orrs r3, r0
	adds r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r4, _080942B4
	ands r3, r4
	orrs r3, r2
	asrs r1, r3, 16
	ldr r0, _080942B8
	cmp r1, r0
	ble _080942A6
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r4
	orrs r3, r0
	asrs r0, r3, 16
	ldr r1, _080942BC
	adds r0, r1
	lsls r0, 16
	ands r3, r6
	orrs r3, r0
_080942A6:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080942B0: .4byte 0x0000ffff
_080942B4: .4byte 0xffff0000
_080942B8: .4byte 0x000003e7
_080942BC: .4byte 0xfffffc18
	thumb_func_end sub_8094268

	thumb_func_start sub_80942C0
sub_80942C0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	asrs r0, r3, 16
	asrs r1, r2, 16
	subs r0, r1
	lsls r0, 16
	ldr r4, _08094310
	ands r3, r4
	orrs r3, r0
	subs r2, r3, r2
	lsls r2, 16
	lsrs r2, 16
	ldr r1, _08094314
	ands r3, r1
	orrs r3, r2
	cmp r3, 0
	bge _080942FC
	subs r0, r3, 0x1
	lsls r0, 16
	lsrs r0, 16
	ands r3, r1
	orrs r3, r0
	asrs r0, r3, 16
	movs r2, 0xFA
	lsls r2, 2
	adds r0, r2
	lsls r0, 16
	ands r3, r4
	orrs r3, r0
_080942FC:
	lsls r0, r3, 16
	cmp r0, 0
	bge _08094304
	movs r3, 0
_08094304:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094310: .4byte 0x0000ffff
_08094314: .4byte 0xffff0000
	thumb_func_end sub_80942C0

	thumb_func_start sub_8094318
sub_8094318:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094336
	cmp r1, r0
	blt _0809433A
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _0809433A
_08094336:
	str r2, [r4]
	b _0809433C
_0809433A:
	str r3, [r4]
_0809433C:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094318

	thumb_func_start sub_8094344
sub_8094344:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r0, r3, 16
	asrs r1, r0, 16
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _08094362
	cmp r1, r0
	blt _08094366
	asrs r1, r3, 16
	asrs r0, r2, 16
	cmp r1, r0
	ble _08094366
_08094362:
	str r3, [r4]
	b _08094368
_08094366:
	str r2, [r4]
_08094368:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8094344

	thumb_func_start sub_8094370
sub_8094370:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsls r2, 16
	ldr r4, _08094398
	lsrs r3, r1, 16
	orrs r3, r2
	asrs r2, 16
	ldr r1, _0809439C
	asrs r0, r1, 16
	cmp r2, r0
	ble _0809438C
	ands r3, r4
	orrs r3, r1
_0809438C:
	str r3, [r5]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08094398: .4byte 0x0000ffff
_0809439C: .4byte 0x03e70000
	thumb_func_end sub_8094370

	thumb_func_start sub_80943A0
sub_80943A0:
	lsls r1, 16
	lsrs r2, r1, 16
	str r2, [r0]
	bx lr
	thumb_func_end sub_80943A0

	thumb_func_start sub_80943A8
sub_80943A8:
	push {r4,r5,lr}
	ldr r3, [r1, 0x4]
	lsrs r2, r3, 16
	ldr r1, _080943D4
	ands r5, r1
	orrs r5, r2
	ldr r4, _080943D8
	adds r2, r4, 0
	ands r2, r3
	lsls r1, r2, 5
	subs r1, r2
	lsls r1, 2
	adds r1, r2
	lsls r1, 3
	lsrs r1, 16
	lsls r1, 16
	ands r5, r4
	orrs r5, r1
	str r5, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080943D4: .4byte 0xffff0000
_080943D8: .4byte 0x0000ffff
	thumb_func_end sub_80943A8

	thumb_func_start sub_80943DC
sub_80943DC:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	lsls r1, r4, 16
	asrs r1, 16
	lsls r0, r1, 5
	subs r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 3
	asrs r1, r4, 16
	adds r0, r1
	lsls r3, r2, 16
	asrs r3, 16
	lsls r1, r3, 5
	subs r1, r3
	lsls r1, 2
	adds r1, r3
	lsls r1, 3
	asrs r2, 16
	adds r1, r2
	muls r0, r1
	movs r5, 0xFA
	lsls r5, 2
	adds r1, r5, 0
	bl __divsi3
	adds r6, r0, 0
	adds r1, r5, 0
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08094448
	ands r4, r1
	orrs r4, r0
	adds r0, r6, 0
	adds r1, r5, 0
	bl __modsi3
	lsls r0, 16
	ldr r1, _0809444C
	ands r1, r4
	orrs r0, r1
	mov r1, r8
	str r0, [r1]
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094448: .4byte 0xffff0000
_0809444C: .4byte 0x0000ffff
	thumb_func_end sub_80943DC

	.align 2, 0