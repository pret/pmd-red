        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_803AA34
sub_803AA34:
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, _0803AA64
	ldr r1, [r0]
	ldr r2, _0803AA68
	ldr r3, [r2]
	ldrb r0, [r3, 0x4]
	adds r1, r0
	ldrb r0, [r1]
	adds r5, r2, 0
	cmp r0, 0
	beq _0803AA7A
	ldr r0, _0803AA6C
	str r0, [r3, 0xC]
	bl sub_803ABC8
	lsls r0, 24
	cmp r0, 0
	beq _0803AA70
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x10]
	b _0803AA82
	.align 2, 0
_0803AA64: .4byte gFriendAreas
_0803AA68: .4byte gUnknown_203B3F4
_0803AA6C: .4byte gDebug_CloseText
_0803AA70:
	ldr r1, [r5]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x10]
	b _0803AA82
_0803AA7A:
	ldr r0, _0803AABC
	str r0, [r3, 0xC]
	movs r0, 0x2
	str r0, [r3, 0x10]
_0803AA82:
	adds r4, 0x1
	ldr r5, [r5]
	mov r12, r5
	lsls r1, r4, 3
	mov r3, r12
	adds r3, 0xC
	adds r2, r3, r1
	ldr r0, _0803AAC0
	ldr r0, [r0]
	str r0, [r2]
	mov r2, r12
	adds r2, 0x10
	adds r1, r2, r1
	movs r0, 0x4
	str r0, [r1]
	adds r4, 0x1
	lsls r1, r4, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r2, r1
	movs r0, 0x1
	str r0, [r2]
	mov r1, r12
	ldr r0, [r1, 0x10]
	str r0, [r1, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803AABC: .4byte gDebug_OpenText
_0803AAC0: .4byte gUnknown_80D4970
	thumb_func_end sub_803AA34

	thumb_func_start sub_803AAC4
sub_803AAC4:
	push {lr}
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x4
	bhi _0803AB2E
	lsls r0, 2
	ldr r1, _0803AADC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803AADC: .4byte _0803AAE0
	.align 2, 0
_0803AAE0:
	.4byte _0803AB2E
	.4byte _0803AB2E
	.4byte _0803AB24
	.4byte _0803AAF4
	.4byte _0803AB0C
_0803AAF4:
	bl sub_802132C
	ldr r1, _0803AB08
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x2
	bl sub_803A924
	b _0803AB2E
	.align 2, 0
_0803AB08: .4byte gUnknown_203B3F4
_0803AB0C:
	bl sub_802132C
	ldr r1, _0803AB20
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x3
	bl sub_803A924
	b _0803AB2E
	.align 2, 0
_0803AB20: .4byte gUnknown_203B3F4
_0803AB24:
	bl sub_80213A0
	movs r0, 0x4
	bl sub_803A924
_0803AB2E:
	pop {r0}
	bx r0
	thumb_func_end sub_803AAC4

	thumb_func_start sub_803AB34
sub_803AB34:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8021274
	ldr r4, _0803AB6C
	ldr r0, [r4]
	adds r0, 0x4C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0803AB5A
	ldr r0, [r4]
	adds r0, 0x4C
	mov r1, sp
	bl sub_8013114
_0803AB5A:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803AB7A
	cmp r0, 0x2
	bgt _0803AB70
	cmp r0, 0x1
	beq _0803AB9E
	b _0803ABA4
	.align 2, 0
_0803AB6C: .4byte gUnknown_203B3F4
_0803AB70:
	cmp r0, 0x3
	beq _0803AB84
	cmp r0, 0x4
	beq _0803AB96
	b _0803ABA4
_0803AB7A:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl UnlockFriendArea
	b _0803AB8E
_0803AB84:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	movs r1, 0x1
	bl sub_809249C
_0803AB8E:
	movs r0, 0x1
	bl sub_803A924
	b _0803ABA4
_0803AB96:
	movs r0, 0x3
	bl sub_803A924
	b _0803ABA4
_0803AB9E:
	movs r0, 0x1
	bl sub_803A924
_0803ABA4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_803AB34

	thumb_func_start sub_803ABAC
sub_803ABAC:
	push {lr}
	bl sub_80217EC
	cmp r0, 0x1
	bls _0803ABC4
	cmp r0, 0x3
	bhi _0803ABC4
	bl sub_8021830
	movs r0, 0x1
	bl sub_803A924
_0803ABC4:
	pop {r0}
	bx r0
	thumb_func_end sub_803ABAC

	thumb_func_start sub_803ABC8
sub_803ABC8:
	push {r4-r6,lr}
	movs r5, 0
	movs r6, 0x1
_0803ABCE:
	ldr r2, _0803AC08
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0803AC10
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _0803AC10
	ldr r0, _0803AC0C
	ldr r4, [r0]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl GetFriendArea
	ldrb r1, [r4, 0x4]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0803AC10
	movs r0, 0
	b _0803AC1C
	.align 2, 0
_0803AC08: .4byte gRecruitedPokemonRef
_0803AC0C: .4byte gUnknown_203B3F4
_0803AC10:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _0803ABCE
	movs r0, 0x1
_0803AC1C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_803ABC8

        .align 2,0
