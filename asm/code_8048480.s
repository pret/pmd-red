	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8048A68
sub_8048A68:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	mov r8, r1
	ldrb r1, [r1]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08048A90
	ldr r0, _08048A8C
_08048A80:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08048B8C
	.align 2, 0
_08048A8C: .4byte gUnknown_80FE3E8
_08048A90:
	ldr r0, _08048AA4
	ldr r0, [r0]
	ldr r1, _08048AA8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08048AB0
	ldr r0, _08048AAC
	b _08048A80
	.align 2, 0
_08048AA4: .4byte gDungeon
_08048AA8: .4byte 0x0000065c
_08048AAC: .4byte gUnknown_80F9BD8
_08048AB0:
	movs r7, 0
_08048AB2:
	ldr r0, _08048B24
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08048B28
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048B4A
	ldr r5, [r4, 0x70]
	movs r6, 0x1
	ldrb r0, [r5, 0xA]
	cmp r0, 0x3
	bhi _08048AF4
	ldr r2, _08048B2C
	ldrb r1, [r5, 0xA]
	movs r0, 0x64
	muls r1, r0
	ldr r0, _08048B30
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	bl sub_806A538
	lsls r0, 24
	cmp r0, 0
	beq _08048AF6
_08048AF4:
	movs r6, 0
_08048AF6:
	adds r0, r4, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08048B06
	movs r6, 0
_08048B06:
	adds r0, r5, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08048B12
	movs r6, 0
_08048B12:
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08048B20
	cmp r0, 0x47
	bne _08048B34
_08048B20:
	movs r0, 0x1
	b _08048B36
	.align 2, 0
_08048B24: .4byte gDungeon
_08048B28: .4byte 0x0001357c
_08048B2C: .4byte gRecruitedPokemonRef
_08048B30: .4byte 0x00008df8
_08048B34:
	movs r0, 0
_08048B36:
	cmp r0, 0
	beq _08048B3C
	movs r6, 0
_08048B3C:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08048B44
	movs r6, 0
_08048B44:
	ldr r2, _08048B84
	adds r0, r5, r2
	strb r6, [r0]
_08048B4A:
	adds r7, 0x1
	cmp r7, 0x3
	ble _08048AB2
	movs r0, 0
	movs r1, 0x1
	bl DrawFieldGiveItemMenu
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048B8C
	mov r0, r9
	mov r1, r8
	bl sub_804245C
	ldr r0, _08048B88
	ldr r0, [r0]
	adds r0, 0xBC
	str r4, [r0]
	movs r2, 0xA1
	lsls r2, 1
	mov r0, r9
	movs r1, 0
	bl sub_8044E24
	movs r0, 0x1
	b _08048B8E
	.align 2, 0
_08048B84: .4byte 0x00000157
_08048B88: .4byte gDungeon
_08048B8C:
	movs r0, 0
_08048B8E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8048A68

	.align 2, 0
