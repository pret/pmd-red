        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8038630
sub_8038630:
	push {r4-r6,lr}
	sub sp, 0x18
	ldr r5, _080386A8
	movs r0, 0x3
	str r0, [sp, 0x14]
	ldr r6, _080386AC
	ldr r0, [r6]
	ldr r4, [r0, 0x4]
	cmp r4, 0x1
	bne _08038646
	b _08038798
_08038646:
	cmp r4, 0x1
	bcc _0803864C
	b _08038824
_0803864C:
	adds r0, 0x8
	bl sub_8012FD8
	movs r5, 0
	str r5, [sp, 0x10]
	bl sub_80140F8
	bl sub_8011C1C
	adds r1, r0, 0
	add r0, sp, 0x10
	bl WriteSavetoPak
	adds r4, r0, 0
	bl sub_8014114
	cmp r4, 0
	beq _080386B8
	cmp r4, 0x1
	beq _08038738
	ldr r0, [r6]
	movs r4, 0xA4
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	bl sub_8035CC0
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x2E
	bne _08038750
	adds r0, r1, 0
	adds r0, 0x8
	adds r1, r4
	ldr r3, _080386B0
	ldr r2, _080386B4
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _0803876E
	.align 2, 0
_080386A8: .4byte 0x0000ffdc
_080386AC: .4byte gUnknown_203B364
_080386B0: .4byte gUnknown_80E6F38
_080386B4: .4byte gUnknown_80E7114
_080386B8:
	ldr r0, [r6]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x2E
	bne _080386F8
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _080386F0
	ldr r2, _080386F4
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08038716
	.align 2, 0
_080386F0: .4byte gUnknown_80E6F38
_080386F4: .4byte gUnknown_80E70CC
_080386F8:
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038728
	ldr r2, _0803872C
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08038716:
	ldr r4, _08038730
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2D
	bne _08038734
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r0, 0x13
	b _08038826
	.align 2, 0
_08038728: .4byte gUnknown_80E6F38
_0803872C: .4byte gUnknown_80E6FBC
_08038730: .4byte gUnknown_203B364
_08038734:
	adds r0, r1, 0
	b _08038772
_08038738:
	ldr r0, _0803874C
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	ldr r1, [r6]
	movs r0, 0x5
	b _08038780
	.align 2, 0
_0803874C: .4byte gUnknown_80E7178
_08038750:
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038788
	ldr r2, _0803878C
	str r2, [sp]
	str r5, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_0803876E:
	ldr r4, _08038790
	ldr r0, [r4]
_08038772:
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r4]
	movs r0, 0x1
_08038780:
	str r0, [r1, 0x4]
	ldr r5, _08038794
	b _08038824
	.align 2, 0
_08038788: .4byte gUnknown_80E6F38
_0803878C: .4byte gUnknown_80E701C
_08038790: .4byte gUnknown_203B364
_08038794: .4byte 0x0000ffdc
_08038798:
	adds r0, 0x8
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _080387AE
	ldr r0, [r6]
	adds r0, 0x8
	add r1, sp, 0x14
	bl sub_8013114
_080387AE:
	ldr r0, [sp, 0x14]
	cmp r0, 0x3
	beq _0803881C
	cmp r0, 0x3
	bhi _080387BE
	cmp r0, 0x2
	beq _080387C2
	b _08038820
_080387BE:
	cmp r0, 0x4
	bne _08038820
_080387C2:
	ldr r4, _080387D8
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x29
	beq _080387D0
	cmp r0, 0x2E
	bne _080387DC
_080387D0:
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x1
	b _08038820
	.align 2, 0
_080387D8: .4byte gUnknown_203B364
_080387DC:
	cmp r0, 0x2D
	bne _080387E8
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x13
	b _08038820
_080387E8:
	cmp r0, 0x2C
	bne _080387F4
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x1F
	b _08038820
_080387F4:
	bl GetMainMenu
	adds r0, 0x3A
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803880A
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0x4]
	movs r5, 0x35
	b _08038820
_0803880A:
	ldr r0, [r4]
	movs r1, 0x1
	str r1, [r0, 0x4]
	ldr r0, [r0]
	movs r5, 0xB
	cmp r0, 0x2B
	bne _08038820
	movs r5, 0xD
	b _08038820
_0803881C:
	ldr r0, [r6]
	str r4, [r0, 0x4]
_08038820:
	bl sub_80388C4
_08038824:
	adds r0, r5, 0
_08038826:
	add sp, 0x18
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8038630

	thumb_func_start sub_8038830
sub_8038830:
	push {r4,r5,lr}
	movs r5, 0
	ldr r0, _080388A4
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0xD4
	lsls r3, 1
	add r3, r12
	ldrh r1, [r3]
	ldr r0, _080388A8
	ands r0, r1
	ldr r1, _080388AC
	ands r0, r1
	ldr r4, _080388B0
	ands r0, r4
	ldr r1, _080388B4
	ands r0, r1
	ldr r1, _080388B8
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _080388BC
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r2, 0xF
	movs r4, 0xF0
	lsls r4, 8
	ldr r1, _080388C0
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x4]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0xD0
	lsls r1, 3
	ldrh r0, [r3, 0x6]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x6]
	movs r0, 0xD8
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	movs r0, 0
	bl ResetSprites
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080388A4: .4byte gUnknown_203B364
_080388A8: .4byte 0x0000feff
_080388AC: .4byte 0x0000fdff
_080388B0: .4byte 0x0000f3ff
_080388B4: .4byte 0x0000efff
_080388B8: .4byte 0x0000dfff
_080388BC: .4byte 0x00003fff
_080388C0: .4byte 0x00000fff
	thumb_func_end sub_8038830

	thumb_func_start sub_80388C4
sub_80388C4:
	push {r4,r5,lr}
	ldr r5, _080388FC
	ldr r2, [r5]
	movs r4, 0xD8
	lsls r4, 1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080388EA
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r2, r1
	subs r1, 0xA8
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080388EA:
	ldr r1, [r5]
	adds r1, r4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080388FC: .4byte gUnknown_203B364
	thumb_func_end sub_80388C4

        .align 2,0
