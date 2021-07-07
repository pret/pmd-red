	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text
	
	thumb_func_start sub_8097FA8
sub_8097FA8:
	lsls r0, 24
	ldr r1, _08097FCC
	ldr r3, [r1]
	lsrs r1, r0, 29
	lsls r1, 2
	adds r3, 0x48
	adds r3, r1
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	bx lr
	.align 2, 0
_08097FCC: .4byte gUnknown_203B498
	thumb_func_end sub_8097FA8

	thumb_func_start sub_8097FD0
sub_8097FD0:
	lsls r0, 24
	ldr r1, _08097FF4
	ldr r3, [r1]
	lsrs r1, r0, 29
	lsls r1, 2
	adds r3, 0x3C
	adds r3, r1
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	bx lr
	.align 2, 0
_08097FF4: .4byte gUnknown_203B498
	thumb_func_end sub_8097FD0

	thumb_func_start sub_8097FF8
sub_8097FF8:
	push {r4-r7,lr}
	movs r4, 0
	ldr r6, _08098040
	movs r7, 0x1
_08098000:
	ldr r5, [r6]
	adds r0, r4, 0
	cmp r4, 0
	bge _0809800A
	adds r0, 0x1F
_0809800A:
	asrs r0, 5
	lsls r3, r0, 2
	adds r1, r5, 0
	adds r1, 0x48
	adds r1, r3
	lsls r0, 5
	subs r0, r4, r0
	adds r2, r7, 0
	lsls r2, r0
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	beq _08098030
	adds r1, r5, 0
	adds r1, 0x3C
	adds r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08098030:
	adds r4, 0x1
	cmp r4, 0x3F
	ble _08098000
	bl sub_8098080
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098040: .4byte gUnknown_203B498
	thumb_func_end sub_8097FF8

	thumb_func_start sub_8098044
sub_8098044:
	push {r4,r5,lr}
	lsls r0, 24
	ldr r1, _0809807C
	ldr r3, [r1]
	lsrs r5, r0, 29
	lsls r5, 2
	adds r4, r3, 0
	adds r4, 0x3C
	adds r4, r5
	movs r1, 0xF8
	lsls r1, 21
	ands r1, r0
	lsrs r1, 24
	movs r2, 0x1
	lsls r2, r1
	mvns r2, r2
	ldr r0, [r4]
	ands r0, r2
	str r0, [r4]
	adds r3, 0x48
	adds r3, r5
	ldr r0, [r3]
	ands r0, r2
	str r0, [r3]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809807C: .4byte gUnknown_203B498
	thumb_func_end sub_8098044

	thumb_func_start sub_8098080
sub_8098080:
	push {r4,lr}
	movs r2, 0
	ldr r4, _080980A0
	movs r3, 0
_08098088:
	ldr r0, [r4]
	lsls r1, r2, 2
	adds r0, 0x48
	adds r0, r1
	str r3, [r0]
	adds r2, 0x1
	cmp r2, 0x2
	ble _08098088
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080980A0: .4byte gUnknown_203B498
	thumb_func_end sub_8098080

	thumb_func_start sub_80980A4
sub_80980A4:
	ldr r0, _080980B0
	ldr r2, [r0]
	ldrb r0, [r2]
	movs r1, 0x1
	strb r1, [r2]
	bx lr
	.align 2, 0
_080980B0: .4byte gUnknown_203B498
	thumb_func_end sub_80980A4

	thumb_func_start sub_80980B4
sub_80980B4:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r3, r1, 0
	ldr r0, _080980F8
	cmp r1, r0
	beq _080980F4
	adds r0, 0x1
	cmp r1, r0
	beq _080980F4
	adds r0, 0x1
	cmp r1, r0
	beq _080980F4
	ldr r0, _080980FC
	ldr r2, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _080980DA
	adds r0, 0x1F
_080980DA:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x4
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080980F4:
	pop {r0}
	bx r0
	.align 2, 0
_080980F8: .4byte 0x000001a5
_080980FC: .4byte gUnknown_203B498
	thumb_func_end sub_80980B4

	thumb_func_start sub_8098100
sub_8098100:
	push {lr}
	lsls r1, r0, 24
	lsrs r3, r1, 24
	cmp r3, 0x3F
	bls _0809810E
	movs r0, 0
	b _0809812C
_0809810E:
	ldr r0, _08098130
	ldr r2, [r0]
	lsrs r0, r1, 29
	lsls r0, 2
	adds r2, 0x3C
	adds r2, r0
	movs r0, 0x1F
	ands r0, r3
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _0809812C
	movs r0, 0x1
_0809812C:
	pop {r1}
	bx r1
	.align 2, 0
_08098130: .4byte gUnknown_203B498
	thumb_func_end sub_8098100

	thumb_func_start sub_8098134
sub_8098134:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r3, r1, 0
	ldr r0, _0809816C
	ldr r2, [r0]
	adds r0, r1, 0
	cmp r1, 0
	bge _08098148
	adds r0, 0x1F
_08098148:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x4
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	beq _08098166
	movs r0, 0x1
_08098166:
	pop {r1}
	bx r1
	.align 2, 0
_0809816C: .4byte gUnknown_203B498
	thumb_func_end sub_8098134

	thumb_func_start sub_8098170
sub_8098170:
	push {lr}
	adds r3, r0, 0
	ldr r0, _0809819C
	ldr r2, [r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _08098180
	adds r0, 0x1F
_08098180:
	asrs r0, 5
	lsls r1, r0, 2
	adds r2, 0x54
	adds r2, r1
	lsls r0, 5
	subs r0, r3, r0
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0809819C: .4byte gUnknown_203B498
	thumb_func_end sub_8098170

	thumb_func_start sub_80981A0
sub_80981A0:
	push {lr}
	adds r3, r0, 0
	cmp r3, 0x1E
	ble _080981AC
	movs r0, 0
	b _080981D4
_080981AC:
	ldr r0, _080981D8
	ldr r2, [r0]
	adds r1, r3, 0
	cmp r3, 0
	bge _080981B8
	adds r1, 0x1F
_080981B8:
	asrs r1, 5
	lsls r0, r1, 2
	adds r2, 0x54
	adds r2, r0
	lsls r1, 5
	subs r1, r3, r1
	movs r0, 0x1
	lsls r0, r1
	ldr r2, [r2]
	ands r2, r0
	cmp r2, 0
	beq _080981D2
	movs r2, 0x1
_080981D2:
	adds r0, r2, 0
_080981D4:
	pop {r1}
	bx r1
	.align 2, 0
_080981D8: .4byte gUnknown_203B498
	thumb_func_end sub_80981A0

        .align 2,0
