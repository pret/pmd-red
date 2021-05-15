        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8037400
sub_8037400:
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
	bl sub_8037810
	bl sub_8011830
	ldr r4, _08037434
	ldr r0, [r4]
	ldr r0, [r0]
	bl sub_8037B28
	ldr r4, [r4]
	str r0, [r4, 0x4]
	cmp r0, 0
	beq _08037422
	b _080376BE
_08037422:
	ldr r0, [r4]
	cmp r0, 0xA
	bls _0803742A
	b _080375E8
_0803742A:
	lsls r0, 2
	ldr r1, _08037438
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037434: .4byte gUnknown_203B35C
_08037438: .4byte _0803743C
	.align 2, 0
_0803743C:
	.4byte _08037494
	.4byte _080374B8
	.4byte _08037534
	.4byte _0803751C
	.4byte _0803756C
	.4byte _080375D8
	.4byte _080374E4
	.4byte _080374D0
	.4byte _080375E8
	.4byte _08037480
	.4byte _08037468
_08037468:
	ldr r0, _0803747C
	ldr r0, [r0]
	movs r1, 0xE7
	lsls r1, 2
	adds r6, r0, r1
	movs r2, 0x8A
	lsls r2, 3
	adds r5, r0, r2
	b _080375E8
	.align 2, 0
_0803747C: .4byte gUnknown_203B35C
_08037480:
	ldr r0, _08037490
	ldr r0, [r0]
	movs r3, 0xE7
	lsls r3, 2
	adds r6, r0, r3
	movs r4, 0x8A
	lsls r4, 3
	b _080375E6
	.align 2, 0
_08037490: .4byte gUnknown_203B35C
_08037494:
	bl sub_8035D94
	ldr r1, _080374B4
	ldr r3, [r1]
	movs r5, 0xDE
	lsls r5, 1
	adds r2, r3, r5
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r6, r2, 0
	movs r0, 0xE2
	lsls r0, 1
	adds r5, r3, r0
	b _080375E8
	.align 2, 0
_080374B4: .4byte gUnknown_203B35C
_080374B8:
	ldr r0, _080374CC
	ldr r0, [r0]
	movs r1, 0xDE
	lsls r1, 1
	adds r6, r0, r1
	movs r2, 0xE2
	lsls r2, 1
	adds r5, r0, r2
	b _080375E8
	.align 2, 0
_080374CC: .4byte gUnknown_203B35C
_080374D0:
	ldr r0, _080374E0
	ldr r0, [r0]
	movs r3, 0xE6
	lsls r3, 1
	adds r6, r0, r3
	movs r4, 0xFE
	lsls r4, 1
	b _080375E6
	.align 2, 0
_080374E0: .4byte gUnknown_203B35C
_080374E4:
	bl sub_8035D74
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	ldr r3, _08037518
	ldr r1, [r3]
	movs r2, 0xE6
	lsls r2, 1
	adds r1, r2
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r6, r0, r2
	movs r1, 0xFE
	lsls r1, 1
	adds r5, r0, r1
	b _080375E8
	.align 2, 0
_08037518: .4byte gUnknown_203B35C
_0803751C:
	ldr r0, _08037530
	ldr r0, [r0]
	movs r2, 0x8B
	lsls r2, 2
	adds r6, r0, r2
	movs r3, 0x97
	lsls r3, 2
	adds r5, r0, r3
	b _080375E8
	.align 2, 0
_08037530: .4byte gUnknown_203B35C
_08037534:
	bl sub_8035D74
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	ldr r3, _08037568
	ldr r1, [r3]
	movs r2, 0x8B
	lsls r2, 2
	adds r1, r2
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r3]
	adds r6, r0, r2
	movs r1, 0x97
	lsls r1, 2
	adds r5, r0, r1
	b _080375E8
	.align 2, 0
_08037568: .4byte gUnknown_203B35C
_0803756C:
	bl sub_8035D74
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	ldr r4, _080375CC
	ldr r1, [r4]
	movs r5, 0xA3
	lsls r5, 2
	adds r1, r5
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl sub_8035D3C
	lsls r0, 16
	ldr r1, _080375D0
	cmp r0, r1
	beq _080375BE
	bl sub_8035D3C
	ldr r3, [r4]
	movs r1, 0xAF
	lsls r1, 2
	adds r3, r1
	ldr r1, _080375D4
	ldr r1, [r1]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x58
	muls r0, r2
	adds r1, r0
	adds r0, r3, 0
	bl memcpy
_080375BE:
	ldr r0, [r4]
	adds r6, r0, r5
	movs r2, 0xC5
	lsls r2, 2
	adds r5, r0, r2
	b _080375E8
	.align 2, 0
_080375CC: .4byte gUnknown_203B35C
_080375D0: .4byte 0xffff0000
_080375D4: .4byte gRecruitedPokemonRef
_080375D8:
	ldr r0, _08037610
	ldr r0, [r0]
	movs r3, 0xA3
	lsls r3, 2
	adds r6, r0, r3
	movs r4, 0xC5
	lsls r4, 2
_080375E6:
	adds r5, r0, r4
_080375E8:
	ldr r4, _08037610
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_8037D64
	ldr r1, [r4]
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _080376BE
	ldr r0, [r1]
	cmp r0, 0xA
	bhi _080376AE
	lsls r0, 2
	ldr r1, _08037614
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037610: .4byte gUnknown_203B35C
_08037614: .4byte _08037618
	.align 2, 0
_08037618:
	.4byte _08037644
	.4byte _08037644
	.4byte _08037658
	.4byte _08037658
	.4byte _0803766C
	.4byte _0803766C
	.4byte _08037684
	.4byte _08037684
	.4byte _080376AE
	.4byte _0803769C
	.4byte _0803769C
_08037644:
	ldr r0, _08037654
	ldr r2, [r0]
	movs r5, 0xDE
	lsls r5, 1
	adds r6, r2, r5
	movs r1, 0xE2
	lsls r1, 1
	b _0803767A
	.align 2, 0
_08037654: .4byte gUnknown_203B35C
_08037658:
	ldr r0, _08037668
	ldr r2, [r0]
	movs r3, 0x8B
	lsls r3, 2
	adds r6, r2, r3
	movs r4, 0x97
	lsls r4, 2
	b _08037692
	.align 2, 0
_08037668: .4byte gUnknown_203B35C
_0803766C:
	ldr r0, _08037680
	ldr r2, [r0]
	movs r5, 0xA3
	lsls r5, 2
	adds r6, r2, r5
	movs r1, 0xC5
	lsls r1, 2
_0803767A:
	adds r5, r2, r1
	adds r4, r0, 0
	b _080376AE
	.align 2, 0
_08037680: .4byte gUnknown_203B35C
_08037684:
	ldr r0, _08037698
	ldr r2, [r0]
	movs r3, 0xE6
	lsls r3, 1
	adds r6, r2, r3
	movs r4, 0xFE
	lsls r4, 1
_08037692:
	adds r5, r2, r4
	adds r4, r0, 0
	b _080376AE
	.align 2, 0
_08037698: .4byte gUnknown_203B35C
_0803769C:
	ldr r1, _080376C8
	ldr r0, [r1]
	movs r5, 0xE7
	lsls r5, 2
	adds r6, r0, r5
	movs r2, 0x8A
	lsls r2, 3
	adds r5, r0, r2
	adds r4, r1, 0
_080376AE:
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x4]
_080376BE:
	bl xxx_call_start_bg_music
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080376C8: .4byte gUnknown_203B35C
	thumb_func_end sub_8037400

	thumb_func_start sub_80376CC
sub_80376CC:
	push {r4,lr}
	ldr r0, _08037728
	ldr r3, [r0]
	ldrh r1, [r3, 0xC]
	ldr r0, _0803772C
	ands r0, r1
	ldr r1, _08037730
	ands r0, r1
	ldr r4, _08037734
	ands r0, r4
	ldr r1, _08037738
	ands r0, r1
	ldr r1, _0803773C
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _08037740
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0xC]
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x10]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r2, 0xF
	movs r4, 0xF0
	lsls r4, 8
	ldr r1, _08037744
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x10]
	movs r0, 0
	strh r0, [r3, 0xE]
	movs r1, 0xC0
	lsls r1, 4
	ldrh r0, [r3, 0x12]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x12]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037728: .4byte gUnknown_203B35C
_0803772C: .4byte 0x0000feff
_08037730: .4byte 0x0000fdff
_08037734: .4byte 0x0000f3ff
_08037738: .4byte 0x0000efff
_0803773C: .4byte 0x0000dfff
_08037740: .4byte 0x00003fff
_08037744: .4byte 0x00000fff
	thumb_func_end sub_80376CC

	thumb_func_start sub_8037748
sub_8037748:
	push {r4,lr}
	ldr r4, _08037794
	ldr r3, [r4]
	ldrh r1, [r3, 0xE]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r1
	movs r1, 0x70
	orrs r0, r1
	strh r0, [r3, 0xE]
	movs r2, 0xD0
	lsls r2, 3
	ldrh r1, [r3, 0x12]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, 0x12]
	ldr r0, [r3, 0x14]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08037782
	adds r0, r3, 0
	adds r0, 0xC
	adds r1, 0xF8
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08037782:
	bl xxx_draw_string_80144C4
	ldr r1, [r4]
	ldr r0, [r1, 0x14]
	adds r0, 0x1
	str r0, [r1, 0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037794: .4byte gUnknown_203B35C
	thumb_func_end sub_8037748

	thumb_func_start sub_8037798
sub_8037798:
	push {lr}
	ldr r2, _080377B4
	ldr r1, _080377B8
	ldr r0, [r1]
	ldr r0, [r0]
	adds r3, r1, 0
	cmp r0, 0xA
	bhi _0803780A
	lsls r0, 2
	ldr r1, _080377BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080377B4: .4byte 0x0000ffdc
_080377B8: .4byte gUnknown_203B35C
_080377BC: .4byte _080377C0
	.align 2, 0
_080377C0:
	.4byte _080377EC
	.4byte _080377EC
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _080377F0
	.4byte _0803780A
	.4byte _080377FE
	.4byte _080377FE
_080377EC:
	movs r2, 0x1
	b _0803780A
_080377F0:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	movs r2, 0x1
	cmp r0, 0
	bne _0803780A
	movs r2, 0x2A
	b _0803780A
_080377FE:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	movs r2, 0xD
	cmp r0, 0
	bne _0803780A
	movs r2, 0x2B
_0803780A:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8037798

	thumb_func_start sub_8037810
sub_8037810:
	push {r4-r6,lr}
	ldr r6, _080378FC
	ldr r0, [r6]
	movs r5, 0xDE
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	movs r4, 0xE2
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	adds r5, r0, r5
	movs r1, 0
	movs r2, 0
	str r1, [r5]
	str r2, [r5, 0x4]
	adds r4, r0, r4
	str r1, [r4]
	str r2, [r4, 0x4]
	movs r2, 0xE6
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xFE
	lsls r3, 1
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0x8B
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x97
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xA3
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xC5
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0xAF
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xD1
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xE7
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x8A
	lsls r2, 3
	adds r0, r2
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r2, [r6]
	movs r3, 0xB1
	lsls r3, 2
	adds r0, r2, r3
	movs r1, 0
	strh r1, [r0]
	adds r3, 0x88
	adds r0, r2, r3
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080378FC: .4byte gUnknown_203B35C
	thumb_func_end sub_8037810

	thumb_func_start sub_8037900
sub_8037900:
	push {r4,lr}
	sub sp, 0x10
	ldr r4, _08037928
	ldr r0, [r4]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xA
	bls _0803791E
	b _08037A14
_0803791E:
	lsls r0, 2
	ldr r1, _0803792C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037928: .4byte gUnknown_203B35C
_0803792C: .4byte _08037930
	.align 2, 0
_08037930:
	.4byte _0803795C
	.4byte _0803795C
	.4byte _0803797C
	.4byte _0803797C
	.4byte _0803799C
	.4byte _0803799C
	.4byte _080379BC
	.4byte _080379BC
	.4byte _08037A14
	.4byte _080379F0
	.4byte _080379F0
_0803795C:
	ldr r0, _08037970
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037974
	ldr r2, _08037978
	b _080379CE
	.align 2, 0
_08037970: .4byte gUnknown_203B35C
_08037974: .4byte gUnknown_80E6554
_08037978: .4byte gUnknown_80E656C
_0803797C:
	ldr r0, _08037990
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037994
	ldr r2, _08037998
	b _080379CE
	.align 2, 0
_08037990: .4byte gUnknown_203B35C
_08037994: .4byte gUnknown_80E6554
_08037998: .4byte gUnknown_80E65D8
_0803799C:
	ldr r0, _080379B0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379B4
	ldr r2, _080379B8
	b _080379CE
	.align 2, 0
_080379B0: .4byte gUnknown_203B35C
_080379B4: .4byte gUnknown_80E6554
_080379B8: .4byte gUnknown_80E661C
_080379BC:
	ldr r0, _080379E4
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379E8
	ldr r2, _080379EC
_080379CE:
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08037A14
	.align 2, 0
_080379E4: .4byte gUnknown_203B35C
_080379E8: .4byte gUnknown_80E6554
_080379EC: .4byte gUnknown_80E665C
_080379F0:
	ldr r0, _08037A38
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037A3C
	ldr r2, _08037A40
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08037A14:
	ldr r4, _08037A38
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	bl sub_80373C4
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_80130A8
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037A38: .4byte gUnknown_203B35C
_08037A3C: .4byte gUnknown_80E6554
_08037A40: .4byte gUnknown_80E667C
	thumb_func_end sub_8037900

	thumb_func_start nullsub_202
nullsub_202:
	bx lr
	thumb_func_end nullsub_202

	thumb_func_start sub_8037A48
sub_8037A48:
	push {r4-r6,lr}
	sub sp, 0x28
	movs r6, 0x1
	movs r0, 0
	mov r1, sp
	movs r2, 0x14
	bl sub_800D670
	add r4, sp, 0x14
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x14
	bl sub_800D670
	ldr r1, _08037AAC
	movs r3, 0x8
	adds r2, r1, 0
	adds r0, r2, 0x4
_08037A6C:
	str r3, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _08037A6C
	ldr r0, [sp, 0x10]
	str r0, [r2]
	ldr r0, [r4, 0x10]
	str r0, [r2, 0x4]
	ldr r5, _08037AB0
	mov r0, sp
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037A8C
	movs r0, 0x1
_08037A8C:
	lsls r0, 24
	cmp r0, 0
	bne _08037AA6
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037AA0
	movs r0, 0x1
_08037AA0:
	lsls r0, 24
	cmp r0, 0
	beq _08037AB4
_08037AA6:
	movs r0, 0
	b _08037B1E
	.align 2, 0
_08037AAC: .4byte gUnknown_202EC40
_08037AB0: .4byte gUnknown_80E6E50
_08037AB4:
	ldr r1, [sp, 0x10]
	cmp r1, 0
	bne _08037AC0
	ldr r0, [r4, 0x10]
	cmp r0, 0x1
	beq _08037B1C
_08037AC0:
	cmp r1, 0x1
	bne _08037ACA
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _08037B1C
_08037ACA:
	cmp r1, 0x2
	bne _08037AD4
	ldr r0, [r4, 0x10]
	cmp r0, 0x3
	beq _08037B1C
_08037AD4:
	cmp r1, 0x3
	bne _08037ADE
	ldr r0, [r4, 0x10]
	cmp r0, 0x2
	beq _08037B1C
_08037ADE:
	cmp r1, 0x9
	bne _08037AE8
	ldr r0, [r4, 0x10]
	cmp r0, 0xA
	beq _08037B1C
_08037AE8:
	cmp r1, 0xA
	bne _08037AF2
	ldr r0, [r4, 0x10]
	cmp r0, 0x9
	beq _08037B1C
_08037AF2:
	cmp r1, 0x4
	bne _08037AFC
	ldr r0, [r4, 0x10]
	cmp r0, 0x5
	beq _08037B1C
_08037AFC:
	cmp r1, 0x5
	bne _08037B06
	ldr r0, [r4, 0x10]
	cmp r0, 0x4
	beq _08037B1C
_08037B06:
	cmp r1, 0x6
	bne _08037B10
	ldr r0, [r4, 0x10]
	cmp r0, 0x7
	beq _08037B1C
_08037B10:
	cmp r1, 0x7
	bne _08037B1A
	ldr r0, [r4, 0x10]
	cmp r0, 0x6
	beq _08037B1C
_08037B1A:
	movs r6, 0
_08037B1C:
	adds r0, r6, 0
_08037B1E:
	add sp, 0x28
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8037A48

	thumb_func_start sub_8037B28
sub_8037B28:
	push {r4,r5,lr}
	sub sp, 0x14
	adds r4, r0, 0
	movs r5, 0
	bl sub_800D414
	ldr r0, _08037B58
	str r5, [r0]
	ldr r5, _08037B5C
	mov r0, sp
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill8
	mov r0, sp
	adds r1, r5, 0
	bl strcpy
	str r4, [sp, 0x10]
	mov r0, sp
	movs r1, 0x14
	bl sub_800D59C
	b _08037B7A
	.align 2, 0
_08037B58: .4byte gUnknown_202EC38
_08037B5C: .4byte gUnknown_80E6E50
_08037B60:
	cmp r5, 0x3
	beq _08037BCC
	cmp r5, 0x4
	beq _08037BD8
	cmp r5, 0x5
	beq _08037BF0
	ldr r2, _08037BC0
	ldr r1, [r2]
	ldr r0, _08037BC4
	cmp r1, r0
	bgt _08037BE4
	adds r0, r1, 0x1
	str r0, [r2]
_08037B7A:
	movs r4, 0
_08037B7C:
	bl sub_80373C4
	bl sub_8012AE8
	cmp r0, 0x3
	bgt _08037B8C
	cmp r0, 0x2
	bge _08037BF0
_08037B8C:
	adds r4, 0x1
	cmp r4, 0
	ble _08037B7C
	bl sub_800D33C
	adds r5, r0, 0
	bl sub_800D570
	cmp r5, 0x2
	bne _08037B60
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08037BFC
	bl sub_8037A48
	lsls r0, 24
	cmp r0, 0
	bne _08037BC8
	movs r4, 0x4
	bl sub_800D520
	bl sub_800D510
	b _08037C06
	.align 2, 0
_08037BC0: .4byte gUnknown_202EC38
_08037BC4: .4byte 0x00000707
_08037BC8:
	movs r4, 0
	b _08037C06
_08037BCC:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x2
	b _08037C08
_08037BD8:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x3
	b _08037C08
_08037BE4:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08037C08
_08037BF0:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08037C08
_08037BFC:
	movs r4, 0x5
	bl sub_800D520
	bl sub_800D510
_08037C06:
	adds r0, r4, 0
_08037C08:
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8037B28

	thumb_func_start sub_8037C10
sub_8037C10:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _08037C24
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037C38
	b _08037C2E
_08037C24:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _08037C38
_08037C2E:
	ldr r0, _08037C34
	ldr r0, [r0, 0x4]
	b _08037C3C
	.align 2, 0
_08037C34: .4byte gUnknown_202EC40
_08037C38:
	ldr r0, _08037C40
	ldr r0, [r0]
_08037C3C:
	pop {r1}
	bx r1
	.align 2, 0
_08037C40: .4byte gUnknown_202EC40
	thumb_func_end sub_8037C10

	thumb_func_start sub_8037C44
sub_8037C44:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r4, 0
_08037C4C:
	adds r0, r4, 0
	bl sub_800D68C
	adds r4, 0x1
	cmp r4, 0x1
	ble _08037C4C
	cmp r6, 0xA
	bhi _08037CBE
	lsls r0, r6, 2
	ldr r1, _08037C68
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037C68: .4byte _08037C6C
	.align 2, 0
_08037C6C:
	.4byte _08037C98
	.4byte _08037C98
	.4byte _08037CA2
	.4byte _08037CA2
	.4byte _08037CAC
	.4byte _08037CAC
	.4byte _08037CA2
	.4byte _08037CA2
	.4byte _08037CBE
	.4byte _08037CB6
	.4byte _08037CB6
_08037C98:
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_800D59C
	b _08037CBE
_08037CA2:
	adds r0, r5, 0
	movs r1, 0x30
	bl sub_800D59C
	b _08037CBE
_08037CAC:
	adds r0, r5, 0
	movs r1, 0x88
	bl sub_800D59C
	b _08037CBE
_08037CB6:
	adds r0, r5, 0
	movs r1, 0xB4
	bl sub_800D59C
_08037CBE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8037C44

	thumb_func_start sub_8037CC4
sub_8037CC4:
	push {r4,lr}
	adds r3, r1, 0
	adds r4, r2, 0
	cmp r0, 0xA
	bhi _08037D5E
	lsls r0, 2
	ldr r1, _08037CD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037CD8: .4byte _08037CDC
	.align 2, 0
_08037CDC:
	.4byte _08037D08
	.4byte _08037D08
	.4byte _08037D1E
	.4byte _08037D1E
	.4byte _08037D34
	.4byte _08037D34
	.4byte _08037D1E
	.4byte _08037D1E
	.4byte _08037D5E
	.4byte _08037D4A
	.4byte _08037D4A
_08037D08:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x8
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x8
	bl sub_800D670
	b _08037D5E
_08037D1E:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x30
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x30
	bl sub_800D670
	b _08037D5E
_08037D34:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x88
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x88
	bl sub_800D670
	b _08037D5E
_08037D4A:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0xB4
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xB4
	bl sub_800D670
_08037D5E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8037CC4

	thumb_func_start sub_8037D64
sub_8037D64:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r4, 0
	ldr r0, _08037D80
	str r4, [r0]
	bl sub_800D494
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8037C44
	b _08037D96
	.align 2, 0
_08037D80: .4byte gUnknown_202EC48
_08037D84:
	subs r0, r4, 0x3
	cmp r0, 0x2
	bls _08037DBC
	ldr r1, _08037DB8
	ldr r0, [r1]
	cmp r0, 0x63
	bgt _08037DC8
	adds r0, 0x1
	str r0, [r1]
_08037D96:
	bl sub_80373C4
	bl sub_800D33C
	adds r4, r0, 0
	bl sub_800D570
	cmp r4, 0x2
	bne _08037D84
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08037DD4
	movs r4, 0
	b _08037DDE
	.align 2, 0
_08037DB8: .4byte gUnknown_202EC48
_08037DBC:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08037DEA
_08037DC8:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08037DEA
_08037DD4:
	bl sub_800D520
	bl sub_800D510
	movs r4, 0x5
_08037DDE:
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8037CC4
	adds r0, r4, 0
_08037DEA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8037D64

	thumb_func_start sub_8037DF0
sub_8037DF0:
	push {r4,lr}
	sub sp, 0x8
	movs r4, 0
	movs r0, 0
	mov r1, sp
	movs r2, 0x4
	bl sub_800D670
	add r1, sp, 0x4
	movs r0, 0x1
	movs r2, 0x4
	bl sub_800D670
	ldr r0, [sp]
	cmp r0, 0
	bne _08037E16
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _08037E2C
_08037E16:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037E24
	ldr r4, [sp, 0x4]
	b _08037E26
_08037E24:
	ldr r4, [sp]
_08037E26:
	cmp r4, 0
	bne _08037E2C
	movs r4, 0xE
_08037E2C:
	adds r0, r4, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8037DF0

	thumb_func_start sub_8037E38
sub_8037E38:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r4, r6, 0
	cmp r0, 0
	bne _08037E4C
	adds r4, r5, 0
_08037E4C:
	bl sub_800D588
	lsls r0, 24
	adds r3, r5, 0
	cmp r0, 0
	bne _08037E5A
	adds r3, r6, 0
_08037E5A:
	ldrb r0, [r4]
	ldrb r1, [r3]
	cmp r0, r1
	bne _08037E70
	ldr r0, _08037E6C
	ldr r1, [r0]
	ldrb r0, [r4]
	b _08037E76
	.align 2, 0
_08037E6C: .4byte gUnknown_203B460
_08037E70:
	ldr r0, _08037E8C
	ldr r1, [r0]
	ldrb r0, [r3]
_08037E76:
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [r3, 0x4]
	adds r2, r0
	strh r2, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037E8C: .4byte gUnknown_203B460
	thumb_func_end sub_8037E38

	thumb_func_start sub_8037E90
sub_8037E90:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037EA2
	adds r4, r5, 0
_08037EA2:
	movs r0, 0x2
	strb r0, [r4]
	adds r0, r4, 0
	bl sub_80951BC
	ldr r0, [r4, 0x10]
	bl sub_8095274
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8037E90

	thumb_func_start nullsub_53
nullsub_53:
	bx lr
	thumb_func_end nullsub_53

	thumb_func_start sub_8037EBC
sub_8037EBC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r5, r4, 0
	cmp r0, 0
	bne _08037ED0
	adds r5, r6, 0
_08037ED0:
	ldr r1, [r5, 0x10]
	movs r0, 0x1
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r4, r0, 0
	adds r1, r4, 0
	adds r0, r5, 0
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	movs r0, 0x5
	strb r0, [r4]
	adds r0, r4, 0
	bl sub_80951FC
	movs r0, 0x7
	strb r0, [r4]
	movs r0, 0x38
	ldrsh r6, [r5, r0]
	cmp r6, 0
	beq _08037F30
	ldr r4, _08037F2C
	ldr r0, [r4]
	ldr r1, [r5, 0x10]
	stm r0!, {r1}
	adds r1, r5, 0
	adds r1, 0x30
	movs r2, 0x58
	bl memcpy
	ldr r1, [r4]
	movs r0, 0x42
	strb r0, [r1, 0x8]
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	b _08037F40
	.align 2, 0
_08037F2C: .4byte gUnknown_203B484
_08037F30:
	ldr r4, _08037F48
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	ldr r0, [r4]
	strh r6, [r0, 0xC]
_08037F40:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037F48: .4byte gUnknown_203B484
	thumb_func_end sub_8037EBC

	thumb_func_start sub_8037F4C
sub_8037F4C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037F5E
	adds r4, r5, 0
_08037F5E:
	ldr r1, [r4, 0x10]
	movs r0, 0x4
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	adds r1, r4, 0
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	movs r1, 0x6
	strb r1, [r0]
	bl GetMainMenu
	cmp r0, 0
	beq _08037F96
	adds r1, r0, 0
	adds r1, 0x3A
	movs r0, 0x1
	strb r0, [r1]
_08037F96:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8037F4C

	thumb_func_start sub_8037F9C
sub_8037F9C:
	push {lr}
	adds r3, r1, 0
	cmp r0, 0xA
	bhi _08038010
	lsls r0, 2
	ldr r1, _08037FB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037FB0: .4byte _08037FB4
	.align 2, 0
_08037FB4:
	.4byte _08037FE0
	.4byte _08037FE0
	.4byte _08038010
	.4byte _08037FF4
	.4byte _08038010
	.4byte _08037FFE
	.4byte _08038010
	.4byte _08037FEA
	.4byte _08038010
	.4byte _08038010
	.4byte _08038008
_08037FE0:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037E38
	b _08038010
_08037FEA:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037F4C
	b _08038010
_08037FF4:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037E90
	b _08038010
_08037FFE:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037EBC
	b _08038010
_08038008:
	adds r0, r3, 0
	adds r1, r2, 0
	bl nullsub_53
_08038010:
	pop {r0}
	bx r0
	thumb_func_end sub_8037F9C

	thumb_func_start sub_8038014
sub_8038014:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r4, r6, 0
	cmp r0, 0
	bne _08038028
	adds r4, r5, 0
_08038028:
	bl sub_800D588
	lsls r0, 24
	adds r3, r5, 0
	cmp r0, 0
	bne _08038036
	adds r3, r6, 0
_08038036:
	ldrb r0, [r4]
	ldrb r1, [r3]
	cmp r0, r1
	bne _0803804C
	ldr r0, _08038048
	ldr r1, [r0]
	ldrb r0, [r4]
	b _08038052
	.align 2, 0
_08038048: .4byte gUnknown_203B460
_0803804C:
	ldr r0, _08038070
	ldr r1, [r0]
	ldrb r0, [r3]
_08038052:
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [r3, 0x4]
	adds r2, r0
	ldr r0, _08038074
	movs r1, 0
	cmp r2, r0
	ble _08038068
	movs r1, 0x6
_08038068:
	adds r0, r1, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08038070: .4byte gUnknown_203B460
_08038074: .4byte 0x000003e7
	thumb_func_end sub_8038014

	thumb_func_start sub_8038078
sub_8038078:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _0803808A
	adds r4, r5, 0
_0803808A:
	ldr r6, [r4, 0x10]
	ldr r0, _08038098
	ldr r0, [r0]
	cmp r0, 0
	beq _0803809C
	ldr r5, [r0, 0x50]
	b _080380A2
	.align 2, 0
_08038098: .4byte gUnknown_203B184
_0803809C:
	bl sub_8011C34
	adds r5, r0, 0
_080380A2:
	movs r0, 0x4
	adds r1, r6, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	beq _080380BA
	ldr r0, [r4, 0x28]
	cmp r0, r5
	bne _080380BA
	movs r0, 0
	b _080380BC
_080380BA:
	movs r0, 0xB
_080380BC:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8038078

	thumb_func_start sub_80380C4
sub_80380C4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r5, r4, 0
	cmp r0, 0
	bne _080380D8
	adds r5, r6, 0
_080380D8:
	ldr r4, [r5, 0x10]
	movs r0, 0x2
	adds r1, r4, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038110
	movs r0, 0x4
	adds r1, r4, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038110
	movs r0, 0x6
	adds r1, r4, 0
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038110
	ldr r0, [r5, 0x10]
	bl sub_8095298
	lsls r0, 24
	cmp r0, 0
	beq _08038114
_08038110:
	movs r0, 0x7
	b _08038126
_08038114:
	bl sub_8095190
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _08038124
	movs r0, 0
	b _08038126
_08038124:
	movs r0, 0xD
_08038126:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80380C4

	thumb_func_start sub_803812C
sub_803812C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _0803813E
	adds r4, r5, 0
_0803813E:
	ldr r1, [r4, 0x10]
	movs r0, 0x1
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08038150
	movs r0, 0x9
	b _08038152
_08038150:
	movs r0, 0
_08038152:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803812C

	thumb_func_start sub_8038158
sub_8038158:
	movs r0, 0
	bx lr
	thumb_func_end sub_8038158

	thumb_func_start sub_803815C
sub_803815C:
	push {r4,lr}
	adds r3, r1, 0
	movs r4, 0
	cmp r0, 0xA
	bhi _080381D2
	lsls r0, 2
	ldr r1, _08038170
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038170: .4byte _08038174
	.align 2, 0
_08038174:
	.4byte _080381A0
	.4byte _080381A0
	.4byte _080381D2
	.4byte _080381B4
	.4byte _080381D2
	.4byte _080381BE
	.4byte _080381D2
	.4byte _080381AA
	.4byte _080381D2
	.4byte _080381D2
	.4byte _080381C8
_080381A0:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8038014
	b _080381D0
_080381AA:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8038078
	b _080381D0
_080381B4:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_80380C4
	b _080381D0
_080381BE:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_803812C
	b _080381D0
_080381C8:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8038158
_080381D0:
	adds r4, r0, 0
_080381D2:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_803815C

	thumb_func_start sub_80381DC
sub_80381DC:
	push {lr}
	bl sub_8037F9C
	pop {r0}
	bx r0
	thumb_func_end sub_80381DC

	thumb_func_start sub_80381E8
sub_80381E8:
	push {lr}
	bl sub_803815C
	pop {r1}
	bx r1
	thumb_func_end sub_80381E8

	thumb_func_start sub_80381F4
sub_80381F4:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r4, 0
	bl sub_803815C
	str r0, [sp]
	ldr r0, _08038218
	str r4, [r0]
	bl sub_800D494
	mov r0, sp
	movs r1, 0x4
	bl sub_800D59C
	b _0803822E
	.align 2, 0
_08038218: .4byte gUnknown_202EC4C
_0803821C:
	subs r0, r4, 0x3
	cmp r0, 0x2
	bls _08038272
	ldr r1, _08038250
	ldr r0, [r1]
	cmp r0, 0x63
	bgt _0803827E
	adds r0, 0x1
	str r0, [r1]
_0803822E:
	bl sub_80373C4
	bl sub_800D33C
	adds r4, r0, 0
	bl sub_800D570
	cmp r4, 0x2
	bne _0803821C
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08038254
	bl sub_8037DF0
	b _0803825E
	.align 2, 0
_08038250: .4byte gUnknown_202EC4C
_08038254:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x5
_0803825E:
	str r0, [sp]
	ldr r0, [sp]
	cmp r0, 0
	bne _0803828A
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8037F9C
	b _08038292
_08038272:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08038298
_0803827E:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08038298
_0803828A:
	bl sub_800D520
	bl sub_800D510
_08038292:
	bl sub_800D520
	ldr r0, [sp]
_08038298:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80381F4

        .align 2,0
