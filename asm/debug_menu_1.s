        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
