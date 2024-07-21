	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8085EB0
sub_8085EB0:
	ldr r0, _08085EC0
	ldr r0, [r0]
	ldr r1, _08085EC4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08085EC0: .4byte gDungeon
_08085EC4: .4byte 0x00018215
	thumb_func_end sub_8085EB0

	thumb_func_start sub_8085EC8
sub_8085EC8:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x28
	adds r4, r0, 0
	mov r8, r1
	mov r9, r2
	adds r6, r3, 0
	ldr r5, [sp, 0x40]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	bl sub_800EE5C
	bl sub_800EF64
	movs r0, 0x46
	bl sub_803E46C
	str r4, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r2, r9
	str r2, [sp, 0x8]
	mov r1, sp
	ldrh r0, [r6]
	movs r2, 0
	strh r0, [r1, 0xC]
	ldrh r0, [r6, 0x2]
	strh r0, [r1, 0xE]
	mov r0, sp
	strh r2, [r0, 0x10]
	strh r2, [r0, 0x12]
	ldr r0, _08085F3C
	str r0, [sp, 0x18]
	add r1, sp, 0x1C
	ldr r0, _08085F40
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	mov r0, sp
	bl sub_800E890
	cmp r5, 0
	beq _08085F2E
	bl sub_8085F44
	movs r0, 0x1
	negs r0, r0
_08085F2E:
	add sp, 0x28
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08085F3C: .4byte 0x0000ffff
_08085F40: .4byte gUnknown_8107374
	thumb_func_end sub_8085EC8

	thumb_func_start sub_8085F44
sub_8085F44:
	push {r4,lr}
	adds r4, r0, 0
	b _08085F5C
_08085F4A:
	ldr r0, _08085F70
	ldr r0, [r0]
	ldr r1, _08085F74
	adds r0, r1
	bl sub_800E90C
	movs r0, 0x46
	bl sub_803E46C
_08085F5C:
	adds r0, r4, 0
	bl sub_800E9A8
	lsls r0, 24
	cmp r0, 0
	bne _08085F4A
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085F70: .4byte gDungeon
_08085F74: .4byte 0x000181f0
	thumb_func_end sub_8085F44

	thumb_func_start sub_8085F78
sub_8085F78:
	push {lr}
	ldr r0, _08085F94
	ldr r0, [r0]
	ldr r1, _08085F98
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3C
	bls _08085F8A
	b _080860A4
_08085F8A:
	lsls r0, 2
	ldr r1, _08085F9C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08085F94: .4byte gDungeon
_08085F98: .4byte 0x00003a0d
_08085F9C: .4byte _08085FA0
	.align 2, 0
_08085FA0:
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _08086094
	.4byte _08086094
	.4byte _08086094
	.4byte _0808609A
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A0
	.4byte _080860A0
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
	.4byte _080860A4
_08086094:
	bl sub_8088848
	b _080860A4
_0808609A:
	bl sub_8088EE8
	b _080860A4
_080860A0:
	bl sub_808A718
_080860A4:
	pop {r0}
	bx r0
	thumb_func_end sub_8085F78

	thumb_func_start sub_80860A8
sub_80860A8:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r0, _08086108
	ldr r2, [r0]
	movs r3, 0x1
_080860B6:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080860C6
	ldrb r0, [r2, 0x2]
	cmp r0, r6
	beq _08086104
_080860C6:
	adds r2, 0x4
	adds r5, 0x1
	cmp r5, 0x13
	ble _080860B6
	movs r5, 0
_080860D0:
	ldr r0, _0808610C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08086110
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08086114
	ldr r2, [r4, 0x70]
	adds r0, r2, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08086114
	adds r0, r2, 0
	adds r0, 0x62
	ldrb r0, [r0]
	cmp r0, r6
	bne _08086114
_08086104:
	movs r0, 0x1
	b _0808611C
	.align 2, 0
_08086108: .4byte gTeamInventoryRef
_0808610C: .4byte gDungeon
_08086110: .4byte 0x0001357c
_08086114:
	adds r5, 0x1
	cmp r5, 0x3
	ble _080860D0
	movs r0, 0
_0808611C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80860A8

	thumb_func_start sub_8086124
sub_8086124:
	ldr r0, [r0, 0x70]
	movs r2, 0xB0
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_8086124

	thumb_func_start sub_8086130
sub_8086130:
	push {lr}
	movs r0, 0x3C
	bl DungeonFadeOutBGM
	movs r0, 0x3C
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _08086194
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _08086198
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808619C
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _080861A0
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _080861A4
	ldr r0, [r0]
	bl sub_8052FB8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	pop {r0}
	bx r0
	.align 2, 0
_08086194: .4byte gUnknown_810665C
_08086198: .4byte gUnknown_810668C
_0808619C: .4byte gUnknown_81066D4
_080861A0: .4byte gUnknown_81066F0
_080861A4: .4byte gUnknown_810671C
	thumb_func_end sub_8086130
