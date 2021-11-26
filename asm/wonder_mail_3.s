        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802D5A4
sub_802D5A4:
	push {r4-r7,lr}
	ldr r4, _0802D630
	ldr r0, [r4]
	movs r5, 0xCC
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0
	movs r1, 0x8C
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D634
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x8E
	lsls r1, 1
	add r1, r12
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0x90
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D638
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x92
	lsls r1, 1
	add r1, r12
	movs r0, 0x5
	str r0, [r1]
	movs r7, 0x2
	movs r0, 0x94
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0x96
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r6, 0
	movs r3, 0x8E
	lsls r3, 1
	add r3, r12
	mov r0, r12
	adds r2, r0, r5
_0802D60A:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0802D61A
	ldr r1, [r3]
	mov r5, r12
	ldr r0, [r5, 0x6C]
	cmp r1, r0
	beq _0802D62A
_0802D61A:
	adds r3, 0x8
	adds r2, 0x2
	adds r6, 0x1
	cmp r6, r7
	blt _0802D60A
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x6C]
_0802D62A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D630: .4byte gUnknown_203B2F8
_0802D634: .4byte gUnknown_80D494C
_0802D638: .4byte gUnknown_80D4970
	thumb_func_end sub_802D5A4

	thumb_func_start sub_802D63C
sub_802D63C:
	ldr r0, _0802D684
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D688
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D68C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_0802D684: .4byte gUnknown_203B2F8
_0802D688: .4byte gUnknown_80D4920
_0802D68C: .4byte gUnknown_80D4928
	thumb_func_end sub_802D63C

	thumb_func_start sub_802D690
sub_802D690:
	push {r4,r5,lr}
	ldr r2, _0802D728
	ldr r0, [r2]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D72C
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r3, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D730
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D734
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0xB8
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D738
	str r0, [r1]
	movs r1, 0xBA
	lsls r1, 1
	add r1, r12
	movs r0, 0x7
	str r0, [r1]
	movs r5, 0x4
	movs r0, 0xBC
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBE
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r3, 0
	mov r0, r12
	ldr r4, [r0, 0x74]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D70E:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D722
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0802D70E
	ldr r1, [r2]
	movs r0, 0x4
	str r0, [r1, 0x74]
_0802D722:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D728: .4byte gUnknown_203B2F8
_0802D72C: .4byte gUnknown_80D4920
_0802D730: .4byte gUnknown_80D4928
_0802D734: .4byte gWonderMailText_NewMail
_0802D738: .4byte gWonderMailText_OldMail
	thumb_func_end sub_802D690

	thumb_func_start sub_802D73C
sub_802D73C:
	push {r4,r5,lr}
	ldr r3, _0802D7C0
	ldr r0, [r3]
	mov r12, r0
	movs r4, 0
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xB0
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7C8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xB2
	lsls r1, 1
	add r1, r12
	movs r0, 0x4
	str r0, [r1]
	movs r1, 0xB4
	lsls r1, 1
	add r1, r12
	ldr r0, _0802D7CC
	str r0, [r1]
	movs r1, 0xB6
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r5, 0x3
	movs r0, 0xB8
	lsls r0, 1
	add r0, r12
	str r4, [r0]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	movs r2, 0
	mov r0, r12
	ldr r4, [r0, 0x70]
	movs r1, 0xAE
	lsls r1, 1
	add r1, r12
_0802D7A6:
	ldr r0, [r1]
	cmp r0, r4
	beq _0802D7BA
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r5
	blt _0802D7A6
	ldr r1, [r3]
	movs r0, 0x4
	str r0, [r1, 0x70]
_0802D7BA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D7C0: .4byte gUnknown_203B2F8
_0802D7C4: .4byte gUnknown_80D4920
_0802D7C8: .4byte gUnknown_80D4928
_0802D7CC: .4byte gWonderMailText_NewMail
	thumb_func_end sub_802D73C

	thumb_func_start sub_802D7D0
sub_802D7D0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802D826
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D7EA
	ldr r0, _0802D800
	ldr r0, [r0]
	str r1, [r0, 0x70]
_0802D7EA:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _0802D804
	cmp r0, 0x3
	ble _0802D820
	cmp r0, 0x4
	beq _0802D820
	cmp r0, 0x6
	beq _0802D80C
	b _0802D820
	.align 2, 0
_0802D800: .4byte gUnknown_203B2F8
_0802D804:
	movs r0, 0x2
	bl sub_802D1A0
	b _0802D826
_0802D80C:
	ldr r0, _0802D81C
	ldr r1, [r0]
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl sub_802D1A0
	b _0802D826
	.align 2, 0
_0802D81C: .4byte gUnknown_203B2F8
_0802D820:
	movs r0, 0
	bl sub_802D1A0
_0802D826:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802D7D0

	thumb_func_start sub_802D82C
sub_802D82C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802D8C6
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D846
	ldr r0, _0802D858
	ldr r0, [r0]
	str r1, [r0, 0x74]
_0802D846:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bhi _0802D8C0
	lsls r0, 2
	ldr r1, _0802D85C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D858: .4byte gUnknown_203B2F8
_0802D85C: .4byte _0802D860
	.align 2, 0
_0802D860:
	.4byte _0802D8C0
	.4byte _0802D8C0
	.4byte _0802D87C
	.4byte _0802D8C0
	.4byte _0802D8C0
	.4byte _0802D898
	.4byte _0802D8AC
_0802D87C:
	ldr r0, _0802D894
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	bl sub_8096C3C
	bl sub_8096C80
	movs r0, 0x8
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D894: .4byte gUnknown_203B2F8
_0802D898:
	ldr r0, _0802D8A8
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D8A8: .4byte gUnknown_203B2F8
_0802D8AC:
	ldr r0, _0802D8BC
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D8C6
	.align 2, 0
_0802D8BC: .4byte gUnknown_203B2F8
_0802D8C0:
	movs r0, 0x1
	bl sub_802D1A0
_0802D8C6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_802D82C

	thumb_func_start sub_802D8CC
sub_802D8CC:
	push {lr}
	movs r0, 0x1
	bl sub_802C598
	cmp r0, 0x4
	bhi _0802D93A
	lsls r0, 2
	ldr r1, _0802D8E4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802D8E4: .4byte _0802D8E8
	.align 2, 0
_0802D8E8:
	.4byte _0802D93A
	.4byte _0802D93A
	.4byte _0802D930
	.4byte _0802D8FC
	.4byte _0802D914
_0802D8FC:
	bl sub_802C620
	ldr r1, _0802D910
	ldr r1, [r1]
	strb r0, [r1, 0x10]
	movs r0, 0xD
	bl sub_802D1A0
	b _0802D93A
	.align 2, 0
_0802D910: .4byte gUnknown_203B2F8
_0802D914:
	bl sub_802C620
	ldr r2, _0802D92C
	ldr r1, [r2]
	strb r0, [r1, 0x10]
	ldr r1, [r2]
	movs r0, 0xC
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D93A
	.align 2, 0
_0802D92C: .4byte gUnknown_203B2F8
_0802D930:
	bl sub_802C688
	movs r0, 0x1
	bl sub_802D1A0
_0802D93A:
	pop {r0}
	bx r0
	thumb_func_end sub_802D8CC

	thumb_func_start sub_802D940
sub_802D940:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802D980
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802D970
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802D970
	ldr r0, [r4]
	str r1, [r0, 0x6C]
_0802D970:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802D98A
	cmp r0, 0x2
	bgt _0802D984
	cmp r0, 0x1
	beq _0802D9E0
	b _0802D9E6
	.align 2, 0
_0802D980: .4byte gUnknown_203B2F8
_0802D984:
	cmp r0, 0x5
	beq _0802D9CC
	b _0802D9E6
_0802D98A:
	ldr r0, _0802D9BC
	ldr r3, [r0]
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	beq _0802D9C4
	ldr r2, _0802D9C0
	ldrb r1, [r3, 0x10]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, 0xF0
	ldr r1, [r2]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x5
	bls _0802D9C4
	ldrb r0, [r3, 0xA]
	ldrb r1, [r1, 0x4]
	cmp r0, r1
	bne _0802D9C4
	movs r0, 0x7
	bl sub_802D1A0
	b _0802D9E6
	.align 2, 0
_0802D9BC: .4byte gUnknown_203B2F8
_0802D9C0: .4byte gUnknown_203B490
_0802D9C4:
	movs r0, 0xE
	bl sub_802D1A0
	b _0802D9E6
_0802D9CC:
	ldr r0, _0802D9DC
	ldr r1, [r0]
	movs r0, 0xC
	str r0, [r1, 0x4]
	movs r0, 0xF
	bl sub_802D1A0
	b _0802D9E6
	.align 2, 0
_0802D9DC: .4byte gUnknown_203B2F8
_0802D9E0:
	movs r0, 0xC
	bl sub_802D1A0
_0802D9E6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D940

	thumb_func_start sub_802D9F0
sub_802D9F0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802DA30
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xC8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802DA1E
	ldr r0, [r4]
	adds r0, 0xC8
	mov r1, sp
	bl sub_8013114
_0802DA1E:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _0802DA40
	cmp r0, 0x3
	bgt _0802DA34
	cmp r0, 0x1
	beq _0802DA38
	b _0802DA56
	.align 2, 0
_0802DA30: .4byte gUnknown_203B2F8
_0802DA34:
	cmp r0, 0x4
	bne _0802DA56
_0802DA38:
	movs r0, 0xC
	bl sub_802D1A0
	b _0802DA56
_0802DA40:
	bl sub_802C688
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096C3C
	bl sub_8096C80
	movs r0, 0x8
	bl sub_802D1A0
_0802DA56:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802D9F0

	thumb_func_start sub_802DA60
sub_802DA60:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802DA7C
	cmp r0, 0x3
	bhi _0802DA7C
	bl sub_802DF24
	ldr r0, _0802DA80
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802D1A0
_0802DA7C:
	pop {r0}
	bx r0
	.align 2, 0
_0802DA80: .4byte gUnknown_203B2F8
	thumb_func_end sub_802DA60

	thumb_func_start sub_802DA84
sub_802DA84:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802DA9C
	ldr r0, _0802DAA4
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802D1A0
_0802DA9C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802DAA4: .4byte gUnknown_203B2F8
	thumb_func_end sub_802DA84

	thumb_func_start sub_802DAA8
sub_802DAA8:
	push {r4,lr}
	ldr r4, _0802DAD0
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl sub_8096AB4
	adds r1, r0, 0
	ldr r4, [r4]
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0802DAD4
	ldrb r0, [r1]
	cmp r0, 0x5
	beq _0802DAD4
	ldrb r0, [r4, 0xA]
	ldrb r1, [r1, 0x4]
	cmp r0, r1
	bne _0802DAD4
	movs r0, 0
	b _0802DAD6
	.align 2, 0
_0802DAD0: .4byte gUnknown_203B2F8
_0802DAD4:
	movs r0, 0x1
_0802DAD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802DAA8

	thumb_func_start sub_802DADC
sub_802DADC:
	push {r4,lr}
	ldr r3, _0802DAEC
	ldr r0, [r3]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	bne _0802DAF0
_0802DAE8:
	movs r0, 0x1
	b _0802DB1C
	.align 2, 0
_0802DAEC: .4byte gUnknown_203B2F8
_0802DAF0:
	ldr r0, _0802DB24
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0xF0
	movs r2, 0
_0802DAFA:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0802DAE8
	cmp r0, 0x5
	beq _0802DAE8
	cmp r0, 0x5
	bls _0802DB12
	ldr r0, [r3]
	ldrb r0, [r0, 0xA]
	ldrb r4, [r1, 0x4]
	cmp r0, r4
	bne _0802DAE8
_0802DB12:
	adds r1, 0x14
	adds r2, 0x1
	cmp r2, 0x7
	ble _0802DAFA
	movs r0, 0
_0802DB1C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802DB24: .4byte gUnknown_203B490
	thumb_func_end sub_802DADC

	thumb_func_start sub_802DB28
sub_802DB28:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r2, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r2, 24
	mov r0, sp
	adds r1, r6, 0
	bl sub_8096AF8
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _0802DB4A
	movs r0, 0
	b _0802DBC6
_0802DB4A:
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0802DBD0
	movs r0, 0xA8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	adds r0, 0x30
	movs r5, 0
	strb r6, [r0]
	adds r0, r6, 0
	bl sub_8096AB4
	ldr r1, [r4]
	str r0, [r1, 0x34]
	bl sub_8096EEC
	ldr r1, [r4]
	ldr r0, [r1, 0x34]
	adds r1, 0x8
	bl sub_803C21C
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl GetDialogueSpriteDataPtr
	ldr r1, [r4]
	str r0, [r1, 0x38]
	str r5, [r1, 0x3C]
	adds r1, 0x44
	strb r5, [r1]
	ldr r0, [r4]
	adds r0, 0x45
	strb r5, [r0]
	ldr r0, [r4]
	adds r0, 0x46
	strb r5, [r0]
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0x40
	movs r0, 0x2
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x8
	strh r0, [r1]
	ldr r0, [r2, 0x38]
	cmp r0, 0
	beq _0802DBBE
	ldr r0, [r0, 0x4]
	str r0, [r2, 0x3C]
_0802DBBE:
	movs r0, 0
	bl sub_802DC28
	movs r0, 0x1
_0802DBC6:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802DBD0: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DB28

	thumb_func_start sub_802DBD4
sub_802DBD4:
	push {lr}
	ldr r0, _0802DBEC
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0x6
	beq _0802DBF0
	cmp r1, 0x7
	bne _0802DBF6
	ldr r0, [r0, 0x34]
	strb r1, [r0]
	movs r0, 0x3
	b _0802DBFC
	.align 2, 0
_0802DBEC: .4byte gUnknown_203B2FC
_0802DBF0:
	bl sub_802DE44
	b _0802DBFA
_0802DBF6:
	bl sub_802DE60
_0802DBFA:
	movs r0, 0
_0802DBFC:
	pop {r1}
	bx r1
	thumb_func_end sub_802DBD4

	thumb_func_start sub_802DC00
sub_802DC00:
	push {r4,lr}
	ldr r4, _0802DC24
	ldr r0, [r4]
	cmp r0, 0
	beq _0802DC1E
	ldr r0, [r0, 0x38]
	cmp r0, 0
	beq _0802DC14
	bl CloseFile
_0802DC14:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802DC1E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC24: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DC00

	thumb_func_start sub_802DC28
sub_802DC28:
	push {lr}
	ldr r1, _0802DC3C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802DC40
	bl sub_802DC9C
	pop {r0}
	bx r0
	.align 2, 0
_0802DC3C: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DC28

	thumb_func_start sub_802DC40
sub_802DC40:
	push {r4-r7,lr}
	ldr r4, _0802DC94
	ldr r0, [r4]
	adds r0, 0x48
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0802DC58
	cmp r0, 0x7
	bne _0802DC7A
_0802DC58:
	mov r12, r4
	ldr r4, _0802DC98
	movs r3, 0
	movs r2, 0x3
_0802DC60:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0x48
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0802DC60
_0802DC7A:
	bl ResetUnusedInputStruct
	ldr r0, _0802DC94
	ldr r0, [r0]
	adds r0, 0x48
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC94: .4byte gUnknown_203B2FC
_0802DC98: .4byte gUnknown_80E016C
	thumb_func_end sub_802DC40

	thumb_func_start sub_802DC9C
sub_802DC9C:
	push {r4,r5,lr}
	ldr r1, _0802DCB8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r5, r1, 0
	cmp r0, 0x7
	bls _0802DCAC
	b _0802DE3E
_0802DCAC:
	lsls r0, 2
	ldr r1, _0802DCBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DCB8: .4byte gUnknown_203B2FC
_0802DCBC: .4byte _0802DCC0
	.align 2, 0
_0802DCC0:
	.4byte _0802DCE0
	.4byte _0802DDDC
	.4byte _0802DDE4
	.4byte _0802DDEC
	.4byte _0802DDFC
	.4byte _0802DDF4
	.4byte _0802DE34
	.4byte _0802DE3E
_0802DCE0:
	ldr r0, _0802DD60
	ldr r1, [r5]
	ldr r1, [r1, 0x34]
	movs r2, 0xC
	ldrsh r1, [r1, r2]
	bl CopyYellowSpeciesNametoBuffer
	ldr r4, _0802DD64
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl CopyYellowSpeciesNametoBuffer
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r2, _0802DD68
	adds r0, r4, r2
	bl strcpy
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r2, _0802DD6C
	adds r4, r2
	adds r0, r4, 0
	bl strcpy
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl UnlockExclusivePokemon
	ldr r0, _0802DD70
	ldr r1, [r5]
	ldr r1, [r1, 0x34]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8090DC4
	ldr r1, [r5]
	movs r0, 0x6
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x34]
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bhi _0802DDD4
	lsls r0, 2
	ldr r1, _0802DD74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802DD60: .4byte gUnknown_202E5D8
_0802DD64: .4byte gUnknown_202E1C8
_0802DD68: .4byte 0xfffffdd0
_0802DD6C: .4byte 0xfffffe20
_0802DD70: .4byte gUnknown_202DE58
_0802DD74: .4byte _0802DD78
	.align 2, 0
_0802DD78:
	.4byte _0802DDD4
	.4byte _0802DD9C
	.4byte _0802DDB8
	.4byte _0802DD94
	.4byte _0802DD8C
_0802DD8C:
	movs r0, 0x5
	bl sub_802DC28
	b _0802DE3E
_0802DD94:
	movs r0, 0x4
	bl sub_802DC28
	b _0802DE3E
_0802DD9C:
	movs r0, 0x2
	bl sub_802DC28
	ldr r0, _0802DDB4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	movs r2, 0xE
	ldrsh r0, [r0, r2]
	bl UnlockExclusivePokemon
	b _0802DE3E
	.align 2, 0
_0802DDB4: .4byte gUnknown_203B2FC
_0802DDB8:
	movs r0, 0x3
	bl sub_802DC28
	ldr r0, _0802DDD0
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	bl UnlockExclusivePokemon
	b _0802DE3E
	.align 2, 0
_0802DDD0: .4byte gUnknown_203B2FC
_0802DDD4:
	movs r0, 0x1
	bl sub_802DC28
	b _0802DE3E
_0802DDDC:
	ldr r0, _0802DDE0
	b _0802DE1C
	.align 2, 0
_0802DDE0: .4byte gWonderMailClientThanksForRescuingMe
_0802DDE4:
	ldr r0, _0802DDE8
	b _0802DE1C
	.align 2, 0
_0802DDE8: .4byte gWonderMailClientThanksForRescuingThem
_0802DDEC:
	ldr r0, _0802DDF0
	b _0802DE1C
	.align 2, 0
_0802DDF0: .4byte gWonderMailClientEscorted
_0802DDF4:
	ldr r0, _0802DDF8
	b _0802DE1C
	.align 2, 0
_0802DDF8: .4byte gWonderMailClientItemDelivered1
_0802DDFC:
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	ldrb r0, [r0, 0x10]
	bl FindItemInInventory
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0802DE1A
	adds r0, r1, 0
	bl ShiftItemsDownFrom
	bl FillInventoryGaps
_0802DE1A:
	ldr r0, _0802DE2C
_0802DE1C:
	ldr r2, [r5]
	adds r2, 0x38
	ldr r3, _0802DE30
	movs r1, 0
	bl sub_80141B4
	b _0802DE3E
	.align 2, 0
_0802DE2C: .4byte gWonderMailClientItemDelivered2
_0802DE30: .4byte 0x0000010d
_0802DE34:
	ldr r0, [r5]
	adds r0, 0x8
	movs r1, 0x1
	bl sub_802F204
_0802DE3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_802DC9C

	thumb_func_start sub_802DE44
sub_802DE44:
	push {lr}
	bl sub_802F298
	cmp r0, 0x1
	bls _0802DE5C
	cmp r0, 0x3
	bhi _0802DE5C
	bl sub_802F2C0
	movs r0, 0x7
	bl sub_802DC28
_0802DE5C:
	pop {r0}
	bx r0
	thumb_func_end sub_802DE44

	thumb_func_start sub_802DE60
sub_802DE60:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802DE78
	ldr r0, _0802DE80
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_802DC28
_0802DE78:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0802DE80: .4byte gUnknown_203B2FC
	thumb_func_end sub_802DE60

	thumb_func_start sub_802DE84
sub_802DE84:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0802DED8
	movs r0, 0x7C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0, 0xC]
	bl sub_801317C
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	ldr r2, [r1]
	str r2, [r0, 0x10]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _0802DEDC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_802DF14
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802DED8: .4byte gUnknown_203B300
_0802DEDC: .4byte gUnknown_80E0264
	thumb_func_end sub_802DE84

	thumb_func_start sub_802DEE0
sub_802DEE0:
	push {lr}
	ldr r0, _0802DF00
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0802DF04
	cmp r0, 0x2
	bne _0802DF0E
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802DF10
	.align 2, 0
_0802DF00: .4byte gUnknown_203B300
_0802DF04:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802DF10
_0802DF0E:
	movs r0, 0
_0802DF10:
	pop {r1}
	bx r1
	thumb_func_end sub_802DEE0

	thumb_func_start sub_802DF14
sub_802DF14:
	push {lr}
	bl sub_802DF6C
	bl sub_802DF88
	pop {r0}
	bx r0
	thumb_func_end sub_802DF14

	thumb_func_start sub_802DF24
sub_802DF24:
	push {r4,r5,lr}
	ldr r4, _0802DF64
	ldr r2, [r4]
	cmp r2, 0
	beq _0802DF5E
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _0802DF68
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802DF5E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802DF64: .4byte gUnknown_203B300
_0802DF68: .4byte gUnknown_80E0248
	thumb_func_end sub_802DF24

	thumb_func_start sub_802DF6C
sub_802DF6C:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _0802DF84
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_0802DF84: .4byte gUnknown_203B300
	thumb_func_end sub_802DF6C

	thumb_func_start sub_802DF88
sub_802DF88:
	push {r4,lr}
	ldr r4, _0802DFAC
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl CreateRescueDescription
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DFAC: .4byte gUnknown_203B300
	thumb_func_end sub_802DF88

        .align 2,0
