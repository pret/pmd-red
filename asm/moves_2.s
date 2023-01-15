	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80935B8
sub_80935B8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	movs r0, 0x63
	mov r12, r0
	movs r0, 0
	mov r8, r0
	movs r6, 0
	adds r4, r1, 0
	cmp r4, 0
	blt _08093606
	lsls r0, r4, 3
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093606
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093606
	movs r7, 0x1
	movs r3, 0x2
_080935EC:
	subs r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	blt _08093606
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093606
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080935EC
_08093606:
	adds r2, r4, 0x1
	mov r9, r2
	cmp r2, 0x3
	bgt _08093642
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093642
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093642
	movs r6, 0x1
	movs r7, 0x2
_08093628:
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08093642
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08093642
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _08093628
_08093642:
	cmp r6, 0
	bne _0809364A
	movs r0, 0x63
	b _080936CC
_0809364A:
	movs r6, 0
	b _08093668
_0809364E:
	ldrb r0, [r3, 0x4]
	cmp r12, r0
	ble _08093656
	mov r12, r0
_08093656:
	cmp r0, 0
	bne _0809365C
	movs r6, 0x1
_0809365C:
	ldrb r1, [r3, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08093668
	movs r6, 0x1
_08093668:
	subs r2, 0x1
	cmp r2, r4
	blt _0809367C
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0809364E
_0809367C:
	cmp r6, 0
	beq _080936C6
	mov r2, r9
	cmp r2, 0x3
	bgt _080936C0
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080936C0
	movs r6, 0x2
	movs r4, 0xFD
_08093698:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080936C0
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r3]
	movs r0, 0x1
	mov r8, r0
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080936C0
	lsls r0, r2, 3
	adds r3, r5, r0
	ldrb r1, [r3]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	bne _08093698
_080936C0:
	mov r0, r8
	cmp r0, 0
	bne _080936CA
_080936C6:
	mov r0, r12
	b _080936CC
_080936CA:
	movs r0, 0
_080936CC:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80935B8

	thumb_func_start sub_80936D8
sub_80936D8:
	push {r4,lr}
	sub sp, 0x80
	adds r4, r0, 0
	mov r1, sp
	bl sub_8093784
	adds r0, r4, 0
	mov r1, sp
	bl sub_80937E0
	add sp, 0x80
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80936D8

	thumb_func_start sub_80936F4
sub_80936F4:
	push {r4,lr}
	ldr r4, _08093718
	add sp, r4
	adds r4, r0, 0
	mov r1, sp
	bl sub_8093974
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093A2C
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093718: .4byte 0xfffffe00
	thumb_func_end sub_80936F4

	thumb_func_start sub_809371C
sub_809371C:
	push {r4,lr}
	ldr r4, _08093740
	add sp, r4
	adds r4, r0, 0
	mov r1, sp
	bl sub_80939D0
	adds r0, r4, 0
	mov r1, sp
	bl sub_8093B40
	movs r3, 0x80
	lsls r3, 2
	add sp, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093740: .4byte 0xfffffe00
	thumb_func_end sub_809371C

	thumb_func_start sub_8093744
sub_8093744:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_0809374E:
	movs r3, 0
	lsls r0, r4, 5
	adds r2, r0, r7
_08093754:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809376A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809376A
	adds r0, r4, 0
	b _0809377C
_0809376A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08093754
	adds r4, 0x1
	cmp r4, 0x3
	ble _0809374E
	movs r0, 0x1
	negs r0, r0
_0809377C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093744

	thumb_func_start sub_8093784
sub_8093784:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_0809378C:
	lsls r0, r2, 5
	adds r2, 0x1
	movs r3, 0x3
	adds r0, r1
	adds r0, 0x18
_08093796:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093796
	cmp r2, 0x3
	ble _0809378C
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x20
	movs r7, 0x2
_080937AE:
	cmp r5, 0
	beq _080937BC
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080937C0
_080937BC:
	adds r4, 0x20
	movs r3, 0
_080937C0:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x3
	ble _080937AE
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093784

	thumb_func_start sub_80937E0
sub_80937E0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r0, [sp, 0x8]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x4
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_080937FE:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x4
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 5
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x3
_0809381E:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0809383E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093832
	strb r3, [r7]
_08093832:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0809383E
	strb r3, [r5]
_0809383E:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _0809381E
	cmp r6, 0x3
	ble _080937FE
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0xC]
_08093852:
	movs r4, 0
	lsls r0, r6, 5
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x8]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093866:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080938D6
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093884
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _0809388A
_08093884:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_0809388A:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _080938B0
	cmp r4, 0
	bne _080938B0
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_080938B0:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _080938C4
	cmp r4, 0
	bne _080938C4
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080938C4:
	adds r2, 0x8
	ldr r7, [sp, 0xC]
	adds r7, 0x8
	str r7, [sp, 0xC]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x4
	beq _080938E4
_080938D6:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08093866
	adds r6, 0x1
	cmp r6, 0x3
	ble _08093852
_080938E4:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80937E0

	thumb_func_start sub_80938F4
sub_80938F4:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_080938FE:
	movs r3, 0
	lsls r0, r4, 6
	adds r2, r0, r7
_08093904:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809391A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809391A
	adds r0, r4, 0
	b _0809392C
_0809391A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093904
	adds r4, 0x1
	cmp r4, 0x7
	ble _080938FE
	movs r0, 0x1
	negs r0, r0
_0809392C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80938F4

	thumb_func_start sub_8093934
sub_8093934:
	push {r4-r7,lr}
	adds r7, r0, 0
	movs r4, 0
	movs r6, 0x1
	movs r5, 0x80
_0809393E:
	movs r3, 0
	lsls r0, r4, 6
	adds r2, r0, r7
_08093944:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0809395A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809395A
	adds r0, r4, 0
	b _0809396C
_0809395A:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _08093944
	adds r4, 0x1
	cmp r4, 0x7
	ble _0809393E
	movs r0, 0x1
	negs r0, r0
_0809396C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8093934

	thumb_func_start sub_8093974
sub_8093974:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_0809397C:
	lsls r0, r2, 6
	adds r2, 0x1
	movs r3, 0x7
	adds r0, r1
	adds r0, 0x38
_08093986:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093986
	cmp r2, 0x7
	ble _0809397C
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x40
	movs r7, 0x2
_0809399E:
	cmp r5, 0
	beq _080939AC
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080939B0
_080939AC:
	adds r4, 0x40
	movs r3, 0
_080939B0:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x7
	ble _0809399E
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093974

	thumb_func_start sub_80939D0
sub_80939D0:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
	movs r4, 0
_080939D8:
	lsls r0, r2, 6
	adds r2, 0x1
	movs r3, 0x7
	adds r0, r1
	adds r0, 0x38
_080939E2:
	strb r4, [r0]
	subs r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _080939E2
	cmp r2, 0x7
	ble _080939D8
	movs r3, 0
	movs r5, 0
	adds r4, r1, 0
	subs r4, 0x40
	movs r7, 0x2
_080939FA:
	cmp r5, 0
	beq _08093A08
	ldrb r1, [r6]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _08093A0C
_08093A08:
	adds r4, 0x40
	movs r3, 0
_08093A0C:
	lsls r2, r3, 3
	adds r2, r4
	ldm r6!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2]
	adds r3, 0x1
	adds r5, 0x1
	cmp r5, 0x7
	ble _080939FA
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80939D0

	thumb_func_start sub_8093A2C
sub_8093A2C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x8
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_08093A4A:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x8
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 6
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x7
_08093A6A:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08093A8A
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093A7E
	strb r3, [r7]
_08093A7E:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08093A8A
	strb r3, [r5]
_08093A8A:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _08093A6A
	cmp r6, 0x7
	ble _08093A4A
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0x14]
_08093A9E:
	movs r4, 0
	lsls r0, r6, 6
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x10]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093AB2:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093B22
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093AD0
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _08093AD6
_08093AD0:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_08093AD6:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08093AFC
	cmp r4, 0
	bne _08093AFC
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_08093AFC:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _08093B10
	cmp r4, 0
	bne _08093B10
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08093B10:
	adds r2, 0x8
	ldr r7, [sp, 0x14]
	adds r7, 0x8
	str r7, [sp, 0x14]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x8
	beq _08093B30
_08093B22:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093AB2
	adds r6, 0x1
	cmp r6, 0x7
	ble _08093A9E
_08093B30:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093A2C

	thumb_func_start sub_8093B40
sub_8093B40:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x10]
	mov r9, r1
	movs r0, 0
	mov r8, r0
	movs r6, 0
	add r1, sp, 0x8
	mov r10, r1
	mov r12, r6
	movs r3, 0x1
_08093B5E:
	mov r2, sp
	adds r0, r2, r6
	mov r7, r12
	strb r7, [r0]
	mov r1, sp
	adds r1, r6
	adds r1, 0x8
	mov r2, r12
	strb r2, [r1]
	adds r7, r0, 0
	lsls r0, r6, 6
	adds r6, 0x1
	adds r5, r1, 0
	mov r1, r9
	adds r2, r0, r1
	movs r4, 0x7
_08093B7E:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08093B9E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08093B92
	strb r3, [r7]
_08093B92:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08093B9E
	strb r3, [r5]
_08093B9E:
	adds r2, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _08093B7E
	cmp r6, 0x7
	ble _08093B5E
	movs r6, 0
	mov r2, r8
	lsls r2, 3
	str r2, [sp, 0x14]
_08093BB2:
	movs r4, 0
	lsls r0, r6, 6
	mov r7, r9
	adds r5, r0, r7
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x10]
	adds r2, r0, r1
	mov r7, r10
	adds r7, r6
	mov r12, r7
_08093BC6:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093C36
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	cmp r4, 0
	bne _08093BE4
	ldrb r1, [r2]
	movs r0, 0xFD
	ands r0, r1
	b _08093BEA
_08093BE4:
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
_08093BEA:
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0xF7
	ands r3, r0
	movs r1, 0
	movs r0, 0xFB
	ands r3, r0
	strb r3, [r2]
	mov r7, sp
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _08093C10
	cmp r4, 0
	bne _08093C10
	movs r1, 0x8
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
_08093C10:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	beq _08093C24
	cmp r4, 0
	bne _08093C24
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_08093C24:
	adds r2, 0x8
	ldr r7, [sp, 0x14]
	adds r7, 0x8
	str r7, [sp, 0x14]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x8
	beq _08093C44
_08093C36:
	adds r5, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093BC6
	adds r6, 0x1
	cmp r6, 0x7
	ble _08093BB2
_08093C44:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093B40

	thumb_func_start sub_8093C54
sub_8093C54:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093C86:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093CA6
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CA6
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093C86
_08093CA6:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093CB0:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093CC2
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093CC2:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093CB0
	cmp r4, 0x7
	bgt _08093CDE
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093CD4:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093CD4
_08093CDE:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093CE4:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093CE4
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093C54

	thumb_func_start sub_8093CF8
sub_8093CF8:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r6, r0, 0
	lsls r0, r1, 3
	adds r0, r6
	movs r2, 0
	strb r2, [r0]
	adds r3, r1, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	lsls r0, r3, 3
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	mov r12, r2
	movs r7, 0x1
	adds r2, r4, 0
	movs r5, 0x2
_08093D2A:
	mov r0, r12
	strb r0, [r4]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	bgt _08093D4A
	adds r4, r2, 0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D4A
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08093D2A
_08093D4A:
	movs r4, 0
	movs r7, 0x1
	adds r2, r6, 0
	mov r5, sp
	movs r3, 0x7
_08093D54:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08093D66
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_08093D66:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093D54
	cmp r4, 0x7
	bgt _08093D82
	movs r1, 0
	lsls r0, r4, 3
	add r0, sp
_08093D78:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x7
	ble _08093D78
_08093D82:
	mov r4, sp
	adds r2, r6, 0
	movs r3, 0x7
_08093D88:
	ldm r4!, {r0,r1}
	stm r2!, {r0,r1}
	subs r3, 0x1
	cmp r3, 0
	bge _08093D88
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093CF8

	thumb_func_start sub_8093D9C
sub_8093D9C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r1, 16
	lsrs r1, 16
	mov r0, sp
	bl InitPokemonMove
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093D9C

	thumb_func_start sub_8093DC4
sub_8093DC4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r2, 0
	adds r6, r3, 0
	mov r0, sp
	bl sub_8093F10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8093DE8
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8093DC4

	thumb_func_start sub_8093DE8
sub_8093DE8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08093E80
	add sp, r4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	adds r0, r5, 0
	bl sub_80073B8
	ldr r0, _08093E84
	adds r1, r6, 0
	movs r2, 0
	bl sub_80928C0
	lsls r4, 3
	adds r4, 0x10
	ldr r2, _08093E88
	movs r7, 0
	str r7, [sp]
	adds r0, r4, 0
	movs r1, 0
	adds r3, r5, 0
	bl xxx_format_and_draw
	movs r3, 0x13
	ldrh r1, [r6, 0x2]
	ldr r4, _08093E8C
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0, 0x1C]
	ldrb r0, [r2]
	cmp r0, 0x2A
	bne _08093E3A
	movs r3, 0x10
	adds r2, 0x1
_08093E3A:
	str r7, [sp]
	movs r0, 0x4
	adds r1, r3, 0
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8093E90
	adds r0, r5, 0
	bl sub_80073E0
	ldrh r1, [r6, 0x2]
	ldr r2, [r4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0, 0x1C]
	add r0, sp, 0x4
	bl strcpy
	add r0, sp, 0x4
	mov r1, r8
	bl sub_8097DF0
	movs r3, 0xC9
	lsls r3, 2
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08093E80: .4byte 0xfffffcdc
_08093E84: .4byte gAvailablePokemonNames
_08093E88: .4byte gUnknown_8109930
_08093E8C: .4byte gMovesData
	thumb_func_end sub_8093DE8

	thumb_func_start sub_8093E90
sub_8093E90:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0x7
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0x4
	movs r2, 0x48
	movs r3, 0xC8
	bl sub_80078A4
	ldr r0, _08093F00
	adds r1, r6, 0
	bl sub_8092D54
	ldr r0, _08093F04
	ldr r2, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x4A
	adds r3, r5, 0
	bl xxx_format_and_draw
	ldr r0, _08093F08
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x56
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl GetMoveType
	lsls r0, 24
	lsrs r0, 24
	bl GetUnformattedTypeString 
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x40
	movs r1, 0x56
	adds r3, r5, 0
	bl xxx_format_and_draw
	adds r0, r6, 0
	bl GetMovePower
	ldr r1, _08093F0C
	str r0, [r1]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093F00: .4byte gAvailablePokemonNames
_08093F04: .4byte gUnknown_810CF00
_08093F08: .4byte gPtrTypeText
_08093F0C: .4byte gUnknown_202DE30
	thumb_func_end sub_8093E90

	thumb_func_start sub_8093F10
sub_8093F10:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F48
	movs r0, 0
	strb r1, [r3]
	strb r0, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F44
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F4A
	.align 2, 0
_08093F44: .4byte gMovesData
_08093F48:
	strb r0, [r3]
_08093F4A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F10

	thumb_func_start sub_8093F50
sub_8093F50:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r7, 0
	adds r3, r6, 0
	adds r4, r1, 0
	movs r5, 0x3
_08093F5C:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08093F8C
	strb r1, [r3]
	strb r7, [r3, 0x1]
	ldrh r0, [r4, 0x2]
	strh r0, [r3, 0x2]
	ldrh r1, [r4, 0x2]
	ldr r0, _08093F88
	ldr r2, [r0]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0xC]
	strb r0, [r3, 0x4]
	ldrb r0, [r4, 0x4]
	strb r0, [r3, 0x5]
	b _08093F8E
	.align 2, 0
_08093F88: .4byte gMovesData
_08093F8C:
	strb r0, [r3]
_08093F8E:
	adds r3, 0x8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08093F5C
	adds r1, r6, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093F50

	thumb_func_start sub_8093FA8
sub_8093FA8:
	push {lr}
	adds r2, r0, 0
	movs r3, 0x3
_08093FAE:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x2]
	ldrb r0, [r1, 0x5]
	strb r0, [r2, 0x4]
	adds r2, 0x8
	adds r1, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08093FAE
	pop {r0}
	bx r0
	thumb_func_end sub_8093FA8

	thumb_func_start sub_8093FC8
sub_8093FC8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r2, r1, 0
	movs r3, 0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094002
	movs r7, 0xFB
	movs r6, 0x1
	adds r4, r2, 0
	adds r2, r5, 0
_08093FE2:
	ldm r4!, {r0,r1}
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r1, [r2, 0x1]
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2, 0x1]
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08094002
	ldrb r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08093FE2
_08094002:
	cmp r3, 0x7
	bgt _08094016
	movs r1, 0
	lsls r0, r3, 3
	adds r0, r5
_0809400C:
	strb r1, [r0]
	adds r0, 0x8
	adds r3, 0x1
	cmp r3, 0x7
	ble _0809400C
_08094016:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8093FC8

	thumb_func_start sub_809401C
sub_809401C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	movs r2, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094046
	movs r6, 0x1
	adds r4, r5, 0
_08094032:
	ldm r3!, {r0,r1}
	stm r4!, {r0,r1}
	adds r2, 0x1
	cmp r2, 0x3
	bgt _08094046
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08094032
_08094046:
	cmp r2, 0x7
	bgt _0809405A
	movs r1, 0
	lsls r0, r2, 3
	adds r0, r5
_08094050:
	strb r1, [r0]
	adds r0, 0x8
	adds r2, 0x1
	cmp r2, 0x7
	ble _08094050
_0809405A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809401C

	thumb_func_start sub_8094060
sub_8094060:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	movs r4, 0
	movs r5, 0
	adds r3, r6, 0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
_08094076:
	lsls r2, r4, 3
	adds r2, r7, r2
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r4, 0x1
_08094084:
	adds r5, 0x1
	cmp r5, 0x7
	bgt _0809409C
	lsls r0, r5, 3
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08094084
	cmp r4, 0x3
	ble _08094076
_0809409C:
	cmp r4, 0x3
	bgt _080940B0
	movs r1, 0
	lsls r0, r4, 3
	adds r0, r7
_080940A6:
	strb r1, [r0]
	adds r0, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _080940A6
_080940B0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8094060

        .align 2,0
