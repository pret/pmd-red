	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80487E0
sub_80487E0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r9, r0
	mov r8, r1
	lsls r3, r2, 24
	ldr r5, [r1, 0x70]
	ldr r4, _08048858
	lsrs r3, 23
	adds r0, r5, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r3, r1
	adds r0, r1, r4
	movs r2, 0
	ldrsh r6, [r0, r2]
	adds r0, r5, 0
	adds r0, 0x5D
	ldrb r2, [r0]
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	adds r3, r0
	adds r4, r3, r4
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r6, r0
	ldr r0, _0804885C
	adds r1, r0
	movs r4, 0
	ldrsh r2, [r1, r4]
	adds r3, r0
	movs r1, 0
	ldrsh r0, [r3, r1]
	adds r2, r0
	movs r0, 0x1
	str r0, [sp]
	mov r0, r9
	mov r1, r8
	movs r3, 0
	bl sub_8078B5C
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _08048906
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08048852
	cmp r0, 0x47
	bne _08048860
_08048852:
	movs r0, 0x1
	b _08048862
	.align 2, 0
_08048858: .4byte gTypeGummiIQBoost
_0804885C: .4byte gUnknown_810A808
_08048860:
	movs r0, 0
_08048862:
	cmp r0, 0
	bne _08048906
	movs r2, 0xC
	ldrsh r7, [r5, r2]
	ldrh r0, [r5, 0xC]
	adds r0, r6
	strh r0, [r5, 0xC]
	adds r2, r7, r6
	lsls r0, 16
	cmp r0, 0
	bgt _0804887C
	movs r0, 0x1
	strh r0, [r5, 0xC]
_0804887C:
	movs r4, 0xC
	ldrsh r0, [r5, r4]
	ldr r1, _080488A0
	cmp r0, r1
	ble _08048888
	strh r1, [r5, 0xC]
_08048888:
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r7, r0
	bne _080488A8
	ldr r0, _080488A4
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	b _08048906
	.align 2, 0
_080488A0: .4byte 0x000003e7
_080488A4: .4byte gUnknown_80FD644
_080488A8:
	subs r0, r2, r7
	movs r2, 0
	cmp r0, 0x8
	bgt _080488BE
	movs r2, 0x1
	cmp r0, 0x4
	bgt _080488BE
	movs r2, 0x3
	cmp r0, 0x2
	ble _080488BE
	movs r2, 0x2
_080488BE:
	movs r4, 0xC
	ldrsh r0, [r5, r4]
	subs r0, r7
	movs r4, 0
	cmp r0, 0x8
	bgt _080488D8
	movs r4, 0x1
	cmp r0, 0x4
	bgt _080488D8
	movs r4, 0x3
	cmp r0, 0x2
	ble _080488D8
	movs r4, 0x2
_080488D8:
	ldr r1, _08048914
	lsls r0, r2, 2
	adds r0, r1
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	ldr r1, _08048918
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
	mov r0, r9
	mov r1, r8
	bl sub_80522F4
	mov r0, r8
	bl LoadIQSkills
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_806A7E8
_08048906:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08048914: .4byte gUnknown_80FD648
_08048918: .4byte gUnknown_80FD6E8
	thumb_func_end sub_80487E0

	thumb_func_start sub_804891C
sub_804891C:
	push {lr}
	movs r2, 0x3
	bl sub_80793B0
	pop {r0}
	bx r0
	thumb_func_end sub_804891C

	thumb_func_start sub_8048928
sub_8048928:
	push {lr}
	movs r2, 0x3
	bl sub_8079420
	pop {r0}
	bx r0
	thumb_func_end sub_8048928

	thumb_func_start sub_8048934
sub_8048934:
	push {lr}
	movs r2, 0x3
	bl sub_8079490
	pop {r0}
	bx r0
	thumb_func_end sub_8048934

	thumb_func_start sub_8048940
sub_8048940:
	push {lr}
	movs r2, 0x3
	bl sub_8079500
	pop {r0}
	bx r0
	thumb_func_end sub_8048940

	thumb_func_start nullsub_94
nullsub_94:
	bx lr
	thumb_func_end nullsub_94

	thumb_func_start sub_8048950
sub_8048950:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	mov r8, r1
	ldrb r0, [r1, 0x2]
	bl GetItemMove
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08048988
	ldr r0, _08048984
_08048978:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08048A58
	.align 2, 0
_08048984: .4byte gUnknown_80FE3E8
_08048988:
	mov r1, r8
	ldrb r0, [r1, 0x2]
	bl IsHMItem
	lsls r0, 24
	cmp r0, 0
	beq _080489A0
	ldr r0, _0804899C
	b _08048978
	.align 2, 0
_0804899C: .4byte gPtrCantUseInDungeonMessage
_080489A0:
	movs r7, 0
_080489A2:
	ldr r0, _080489FC
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08048A00
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048A12
	ldr r6, [r4, 0x70]
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	mov r0, r9
	bl CanMonLearnMove
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _080489DC
	movs r5, 0
_080489DC:
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080489E8
	movs r5, 0
_080489E8:
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _080489F6
	cmp r0, 0x47
	bne _08048A04
_080489F6:
	movs r0, 0x1
	b _08048A06
	.align 2, 0
_080489FC: .4byte gDungeonGlobalData
_08048A00: .4byte 0x0001357c
_08048A04:
	movs r0, 0
_08048A06:
	cmp r0, 0
	beq _08048A0C
	movs r5, 0
_08048A0C:
	ldr r1, _08048A50
	adds r0, r6, r1
	strb r5, [r0]
_08048A12:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080489A2
	movs r0, 0
	movs r1, 0x1
	bl DrawFieldGiveItemMenu
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08048A58
	mov r0, r10
	mov r1, r8
	bl sub_804245C
	adds r0, r4, 0
	mov r1, r9
	bl sub_8072938
	lsls r0, 24
	cmp r0, 0
	beq _08048A58
	ldr r2, _08048A54
	mov r0, r10
	movs r1, 0
	bl sub_8044E24
	movs r0, 0x1
	b _08048A5A
	.align 2, 0
_08048A50: .4byte 0x00000157
_08048A54: .4byte 0x00000141
_08048A58:
	movs r0, 0
_08048A5A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8048950

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
_08048AA4: .4byte gDungeonGlobalData
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
_08048B24: .4byte gDungeonGlobalData
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
_08048B88: .4byte gDungeonGlobalData
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

	thumb_func_start sub_8048B9C
sub_8048B9C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x20
	mov r9, r0
	movs r0, 0
	mov r8, r0
	mov r2, r9
	ldr r0, [r2, 0x70]
	adds r6, r0, 0
	adds r6, 0x44
	ldrb r1, [r1]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08048BD4
	ldr r0, _08048BD0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	movs r0, 0
	b _08048D40
	.align 2, 0
_08048BD0: .4byte gUnknown_80FE3E8
_08048BD4:
	movs r2, 0
_08048BD6:
	ldr r0, _08048C28
	ldr r0, [r0]
	lsls r1, r2, 2
	ldr r3, _08048C2C
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	str r2, [sp, 0x1C]
	bl EntityExists
	lsls r0, 24
	ldr r2, [sp, 0x1C]
	cmp r0, 0
	beq _08048C3E
	ldr r5, [r4, 0x70]
	movs r7, 0x1
	adds r0, r4, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	ldr r2, [sp, 0x1C]
	cmp r0, 0
	beq _08048C0A
	movs r7, 0
_08048C0A:
	adds r0, r5, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08048C16
	movs r7, 0
_08048C16:
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08048C24
	cmp r0, 0x47
	bne _08048C30
_08048C24:
	movs r0, 0x1
	b _08048C32
	.align 2, 0
_08048C28: .4byte gDungeonGlobalData
_08048C2C: .4byte 0x0001357c
_08048C30:
	movs r0, 0
_08048C32:
	cmp r0, 0
	beq _08048C38
	movs r7, 0
_08048C38:
	ldr r4, _08048C5C
	adds r0, r5, r4
	strb r7, [r0]
_08048C3E:
	adds r2, 0x1
	cmp r2, 0x3
	ble _08048BD6
	movs r0, 0
	movs r1, 0x1
	bl DrawFieldGiveItemMenu
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08048C60
	movs r0, 0
	b _08048D40
	.align 2, 0
_08048C5C: .4byte 0x00000157
_08048C60:
	add r1, sp, 0x4
	adds r0, r6, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	b _08048CE2
_08048C6E:
	ldrh r0, [r6]
	cmp r0, 0x1D
	bne _08048C7C
	adds r0, r6, 0
	bl sub_80637E8
	b _08048CE2
_08048C7C:
	cmp r0, 0x20
	bne _08048C9A
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	bl sub_8063BB4
	movs r0, 0x1
	bl sub_8044C10
	movs r5, 0x1
	mov r8, r5
	b _08048CE2
_08048C9A:
	cmp r0, 0x21
	bne _08048CB6
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	movs r1, 0
	bl sub_8063CF0
	movs r0, 0x1
	bl sub_8044C10
	b _08048CE2
_08048CB6:
	cmp r0, 0x1E
	beq _08048CBE
	cmp r0, 0x33
	bne _08048CD0
_08048CBE:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	movs r1, 0
	bl sub_8063A70
	b _08048CE2
_08048CD0:
	cmp r0, 0x1F
	bne _08048CE2
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r6, 0
	bl sub_8063B54
_08048CE2:
	adds r0, r6, 0
	bl ResetAction
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl sub_8062F90
	lsls r0, 24
	cmp r0, 0
	beq _08048C6E
	mov r0, r8
	cmp r0, 0
	beq _08048D38
	ldr r0, _08048D34
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08048C6E
	adds r1, r6, 0
	add r0, sp, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	mov r0, r9
	movs r1, 0
	movs r2, 0x6E
	bl sub_8044DF0
	adds r0, r6, 0
	movs r1, 0x2C
	bl SetAction
	b _08048D3E
	.align 2, 0
_08048D34: .4byte gUnknown_80FECA0
_08048D38:
	movs r0, 0x1
	bl sub_8044C10
_08048D3E:
	mov r0, r8
_08048D40:
	add sp, 0x20
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8048B9C

	.align 2, 0
