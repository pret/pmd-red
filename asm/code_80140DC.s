	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CreateMenuDialogueBoxAndPortrait
CreateMenuDialogueBoxAndPortrait:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r1, 0
	mov r9, r2
	mov r8, r3
	ldr r5, [sp, 0x28]
	ldr r7, [sp, 0x30]
	ldr r1, [sp, 0x34]
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	movs r1, 0
	str r1, [sp]
	ldr r4, _080142B8
	ldr r3, _080142BC
	adds r2, r4, r3
	adds r1, r4, 0
	mov r3, r10
	bl xxx_format_string
	ldr r0, _080142C0
	str r4, [r0]
	ldr r0, _080142C4
	str r6, [r0, 0x24]
	ldr r0, _080142C8
	str r5, [r0]
	ldr r0, _080142CC
	mov r4, r8
	str r4, [r0]
	ldr r0, _080142D0
	ldr r5, [sp, 0x24]
	str r5, [r0]
	ldr r0, _080142D4
	mov r6, r9
	str r6, [r0]
	ldr r0, _080142D8
	bl sub_801317C
	movs r0, 0x10
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _080142E4
	ldr r2, _080142DC
	adds r1, r2, 0
	ldr r0, _080142E0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	b _080142F2
	.align 2, 0
_080142B8: .4byte gUnknown_202E798
_080142BC: .4byte 0x000003e7
_080142C0: .4byte gUnknown_202E794
_080142C4: .4byte gUnknown_202E748
_080142C8: .4byte gUnknown_202EC10
_080142CC: .4byte gUnknown_202EC14
_080142D0: .4byte gUnknown_202EC18
_080142D4: .4byte gUnknown_202EC1C
_080142D8: .4byte gUnknown_202EC28
_080142DC: .4byte gUnknown_203B198
_080142E0: .4byte gUnknown_80D48DC
_080142E4:
	ldr r2, _08014358
	adds r1, r2, 0
	ldr r0, _0801435C
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
_080142F2:
	adds r4, r2, 0
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x28]
	movs r0, 0x40
	strb r0, [r4, 0x18]
	cmp r7, 0
	beq _08014368
	ldr r1, [r7, 0x4]
	cmp r1, 0
	beq _08014368
	ldrb r0, [r7, 0xC]
	lsls r0, 3
	adds r1, 0x4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _08014368
	ldrh r0, [r7, 0x8]
	strh r0, [r4, 0x20]
	ldrh r0, [r7, 0xA]
	strh r0, [r4, 0x22]
	movs r0, 0x5
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	strh r0, [r4, 0x28]
	movs r4, 0
_0801432A:
	adds r0, r4, 0
	adds r0, 0xE0
	ldr r2, [r7, 0x4]
	ldrb r1, [r7, 0xC]
	lsls r1, 3
	adds r2, r1
	lsls r3, r4, 2
	ldr r1, [r2]
	adds r1, r3
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0xF
	ble _0801432A
	movs r0, 0x1
	str r0, [sp]
	ldrb r0, [r7, 0xE]
	cmp r0, 0
	beq _08014360
	ldr r1, _08014358
	movs r0, 0x7
	b _08014364
	.align 2, 0
_08014358: .4byte gUnknown_203B198
_0801435C: .4byte gUnknown_80D48C4
_08014360:
	ldr r1, _080143E8
	movs r0, 0x5
_08014364:
	str r0, [r1, 0x1C]
	adds r4, r1, 0
_08014368:
	ldr r2, _080143EC
	adds r1, r4, 0
	adds r1, 0x30
	adds r0, r2, 0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	adds r0, r4, 0
	adds r0, 0x48
	ldm r2!, {r1,r3,r5}
	stm r0!, {r1,r3,r5}
	ldm r2!, {r1,r3,r6}
	stm r0!, {r1,r3,r6}
	bl ResetUnusedInputStruct
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	ldr r1, _080143F0
	movs r4, 0
	movs r2, 0
	movs r0, 0x4
	strh r0, [r1]
	strh r0, [r1, 0x2]
	movs r0, 0x70
	strh r0, [r1, 0x8]
	ldr r0, _080143F4
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	lsls r0, 3
	adds r0, 0x22
	strh r0, [r1, 0xA]
	movs r0, 0x7
	str r0, [r1, 0x10]
	str r2, [r1, 0x1C]
	adds r1, 0x20
	strb r4, [r1]
	movs r0, 0x10
	mov r6, r10
	ands r0, r6
	movs r1, 0x3
	cmp r0, 0
	beq _080143C6
	movs r1, 0x8
_080143C6:
	adds r0, r1, 0
	bl SetCharacterMask
	ldr r0, _080143F8
	movs r1, 0x1
	str r1, [r0]
	ldr r0, _080143FC
	mov r2, r10
	strh r2, [r0]
	movs r0, 0x20
	mov r3, r10
	ands r0, r3
	cmp r0, 0
	beq _08014404
	ldr r0, _08014400
	strb r1, [r0]
	b _08014408
	.align 2, 0
_080143E8: .4byte gUnknown_203B198
_080143EC: .4byte gUnknown_80D48AC
_080143F0: .4byte gUnknown_202E748
_080143F4: .4byte gUnknown_2027370
_080143F8: .4byte gUnknown_202E744
_080143FC: .4byte gUnknown_202E77C
_08014400: .4byte gUnknown_202E790
_08014404:
	ldr r0, _0801445C
	strb r4, [r0]
_08014408:
	movs r0, 0x80
	lsls r0, 3
	mov r4, r10
	ands r0, r4
	cmp r0, 0
	beq _08014418
	bl SetWindowBGColor
_08014418:
	ldr r0, _08014460
	movs r1, 0x1
	str r1, [r0]
	ldr r0, _08014464
	str r1, [r0]
	bl UnpressButtons
	ldr r1, _08014468
	movs r0, 0
	strb r0, [r1]
	ldr r1, _0801446C
	movs r0, 0
	str r0, [r1]
	ldr r5, [sp]
	cmp r5, 0
	beq _08014480
	ldr r0, [r7, 0x4]
	ldrb r1, [r7, 0xC]
	lsls r1, 3
	adds r0, 0x4
	adds r0, r1
	ldr r4, [r0]
	movs r0, 0x1
	bl sub_80073B8
	ldrb r0, [r7, 0xD]
	cmp r0, 0
	bne _08014470
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xE
	bl sub_8008274
	b _0801447A
	.align 2, 0
_0801445C: .4byte gUnknown_202E790
_08014460: .4byte gUnknown_202E788
_08014464: .4byte gUnknown_202E78C
_08014468: .4byte gUnknown_202E791
_0801446C: .4byte gUnknown_202E784
_08014470:
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xE
	bl sub_800836C
_0801447A:
	movs r0, 0x1
	bl sub_80073E0
_08014480:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateMenuDialogueBoxAndPortrait

	thumb_func_start sub_8014490
sub_8014490:
	ldr r0, _0801449C
	movs r1, 0
	str r1, [r0]
	ldr r0, _080144A0
	str r1, [r0]
	bx lr
	.align 2, 0
_0801449C: .4byte gUnknown_202E744
_080144A0: .4byte gUnknown_202EC1C
	thumb_func_end sub_8014490

	thumb_func_start sub_80144A4
sub_80144A4:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	beq _080144B2
	ldr r0, _080144BC
	ldr r0, [r0]
	str r0, [r1]
_080144B2:
	ldr r0, _080144C0
	ldr r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_080144BC: .4byte gUnknown_202EC1C
_080144C0: .4byte gUnknown_202E744
	thumb_func_end sub_80144A4

	thumb_func_start xxx_draw_string_80144C4
xxx_draw_string_80144C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0x1
	mov r10, r0
	ldr r1, _080144F4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_080144DC:
	ldr r0, _080144F8
	ldr r1, [r0]
	adds r3, r0, 0
	cmp r1, 0xB
	bls _080144E8
	b _08014A6A
_080144E8:
	lsls r0, r1, 2
	ldr r1, _080144FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080144F4: .4byte gUnknown_202E784
_080144F8: .4byte gUnknown_202E744
_080144FC: .4byte _08014500
	.align 2, 0
_08014500:
	.4byte _08014A72
	.4byte _08014530
	.4byte _08014708
	.4byte _08014A38
	.4byte _08014A48
	.4byte _08014A60
	.4byte _08014778
	.4byte _080147E2
	.4byte _080147E2
	.4byte _080147E2
	.4byte _080149D8
	.4byte _08014A04
_08014530:
	ldr r0, _08014540
	ldr r6, [r0]
	ldr r0, _08014544
	ldrb r0, [r0]
	cmp r0, 0
	beq _0801457C
	ldr r7, _08014548
	b _08014580
	.align 2, 0
_08014540: .4byte gUnknown_202E794
_08014544: .4byte gUnknown_202E790
_08014548: .4byte 0x0001869f
_0801454C:
	str r2, [r3, 0x1C]
	adds r1, r3, 0
	adds r1, 0x20
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0801456C
	movs r0, 0x8
	str r0, [r1]
	ldr r0, _08014570
	strb r2, [r0]
	ldr r1, _08014574
	ldr r0, _08014578
	ldr r0, [r0]
	str r0, [r1]
	b _0801466C
	.align 2, 0
_0801456C: .4byte gUnknown_202E744
_08014570: .4byte gUnknown_202E791
_08014574: .4byte gUnknown_202E780
_08014578: .4byte gUnknown_202E738
_0801457C:
	ldr r0, _08014594
	ldr r7, [r0]
_08014580:
	ldr r1, _08014598
	movs r0, 0
	str r0, [r1, 0x2C]
	bl sub_80073B8
	ldr r1, _0801459C
	mov r8, r1
	ldr r2, _080145A0
	mov r9, r2
	b _08014652
	.align 2, 0
_08014594: .4byte gUnknown_202E788
_08014598: .4byte gUnknown_202E748
_0801459C: .4byte gUnknown_202E744
_080145A0: .4byte gUnknown_202E780
_080145A4:
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r5, [r0]
	cmp r5, 0
	beq _080145EC
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	cmp r0, 0x22
	ble _080145CC
	movs r0, 0x8
	mov r4, r8
	str r0, [r4]
	ldr r0, _080145C8
	ldr r0, [r0]
	mov r1, r9
	str r0, [r1]
	b _080145DA
	.align 2, 0
_080145C8: .4byte gUnknown_202E738
_080145CC:
	movs r0, 0x7
	mov r2, r8
	str r0, [r2]
	ldr r0, _080145E4
	ldr r0, [r0]
	mov r3, r9
	str r0, [r3]
_080145DA:
	ldr r1, _080145E8
	movs r0, 0
	strb r0, [r1]
	b _0801466C
	.align 2, 0
_080145E4: .4byte gUnknown_202E73C
_080145E8: .4byte gUnknown_202E791
_080145EC:
	ldrb r0, [r6]
	cmp r0, 0
	beq _0801466C
	cmp r0, 0xD
	beq _080145FA
	cmp r0, 0xA
	bne _08014608
_080145FA:
	movs r0, 0x4
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	adds r0, 0xB
	strh r0, [r4, 0x2]
	adds r6, 0x1
	b _08014630
_08014608:
	adds r0, r6, 0
	add r1, sp, 0x4
	bl xxx_get_next_char_from_string
	adds r6, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r2, [sp, 0x4]
	ldr r3, [r4, 0x10]
	str r5, [sp]
	bl xxx_call_draw_char
	ldrh r1, [r4]
	adds r1, r0
	strh r1, [r4]
	ldr r0, _08014694
	ldr r0, [r0]
	str r0, [r4, 0x2C]
_08014630:
	ldr r3, _08014698
	movs r4, 0x2
	ldrsh r0, [r3, r4]
	cmp r0, 0x22
	ble _08014650
	ldr r0, _0801469C
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	bne _0801464C
	b _0801454C
_0801464C:
	movs r0, 0x4
	strh r0, [r3, 0x2]
_08014650:
	subs r7, 0x1
_08014652:
	cmp r7, 0
	ble _0801466C
	ldr r4, _08014698
	adds r0, r6, 0
	adds r1, r4, 0
	bl xxx_handle_format_global
	adds r6, r0, 0
	adds r0, r4, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0
	beq _080145A4
_0801466C:
	movs r0, 0
	bl sub_80073E0
	ldr r4, _080146A0
	str r6, [r4]
	ldr r0, _080146A4
	bl sub_801317C
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, 0
	bne _080146BC
	ldr r0, _080146A8
	ldr r0, [r0]
	cmp r0, 0
	beq _080146B0
	ldr r1, _080146AC
	movs r0, 0x3
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014694: .4byte gUnknown_202E78C
_08014698: .4byte gUnknown_202E748
_0801469C: .4byte gUnknown_202E77C
_080146A0: .4byte gUnknown_202E794
_080146A4: .4byte gUnknown_202EC28
_080146A8: .4byte gUnknown_202EC14
_080146AC: .4byte gUnknown_202E744
_080146B0:
	ldr r1, _080146B8
	movs r0, 0x6
	str r0, [r1]
	b _08014A72
	.align 2, 0
_080146B8: .4byte gUnknown_202E744
_080146BC:
	ldr r0, _080146E8
	movs r2, 0
	str r2, [r0, 0x30]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _080146FC
	ldr r1, _080146EC
	ldr r0, [r1]
	cmp r0, 0x1
	beq _080146D4
	b _08014A72
_080146D4:
	movs r0, 0x7
	str r0, [r1]
	ldr r0, _080146F0
	strb r2, [r0]
	ldr r1, _080146F4
	ldr r0, _080146F8
	ldr r0, [r0]
	str r0, [r1]
	b _08014A72
	.align 2, 0
_080146E8: .4byte gUnknown_202E748
_080146EC: .4byte gUnknown_202E744
_080146F0: .4byte gUnknown_202E791
_080146F4: .4byte gUnknown_202E780
_080146F8: .4byte gUnknown_202E738
_080146FC:
	ldr r1, _08014704
	movs r0, 0x2
	b _08014A68
	.align 2, 0
_08014704: .4byte gUnknown_202E744
_08014708:
	ldr r4, _08014760
	ldrh r1, [r4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08014718
	bl sub_8011A04
_08014718:
	ldrh r1, [r4]
	movs r0, 0x2
	ands r0, r1
	ldr r2, _08014764
	cmp r0, 0
	bne _08014742
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08014742
	ldr r0, _08014768
	ldrh r1, [r0, 0x2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08014742
	ldr r0, _0801476C
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08014770
	str r0, [r2, 0x30]
_08014742:
	ldr r1, [r2, 0x30]
	adds r1, 0x1
	str r1, [r2, 0x30]
	ldr r0, [r2, 0x2C]
	cmp r1, r0
	bgt _08014750
	b _08014A72
_08014750:
	ldr r1, _08014774
	movs r0, 0x1
	str r0, [r1]
	adds r1, r2, 0
	adds r1, 0x21
	movs r0, 0
	strb r0, [r1]
	b _08014A6A
	.align 2, 0
_08014760: .4byte gUnknown_202E77C
_08014764: .4byte gUnknown_202E748
_08014768: .4byte gRealInputs
_0801476C: .4byte gUnknown_202E790
_08014770: .4byte 0x0001869f
_08014774: .4byte gUnknown_202E744
_08014778:
	ldr r0, _080147B4
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080147DC
	movs r0, 0x9
	str r0, [r3]
	ldr r1, _080147B8
	movs r0, 0
	strb r0, [r1]
	ldr r0, _080147BC
	ldr r1, [r0]
	cmp r1, 0
	ble _080147C8
	ldr r2, _080147C0
	ldr r0, _080147C4
	ldr r0, [r0]
	subs r0, r1, r0
	str r0, [r2]
	cmp r0, 0
	blt _080147A8
	b _08014A6A
_080147A8:
	movs r0, 0xB
	str r0, [r3]
	movs r0, 0
	str r0, [r2]
	b _08014A6A
	.align 2, 0
_080147B4: .4byte gUnknown_202E77C
_080147B8: .4byte gUnknown_202E791
_080147BC: .4byte gUnknown_202E740
_080147C0: .4byte gUnknown_202E780
_080147C4: .4byte gUnknown_202E784
_080147C8:
	ldr r0, _080147D4
	ldr r1, _080147D8
	ldr r1, [r1]
	str r1, [r0]
	b _08014A6A
	.align 2, 0
_080147D4: .4byte gUnknown_202E780
_080147D8: .4byte gUnknown_202E738
_080147DC:
	movs r0, 0xB
	str r0, [r3]
	b _08014A6A
_080147E2:
	movs r5, 0
	ldr r0, _0801481C
	adds r0, 0x20
	strb r5, [r0]
	ldr r4, _08014820
	adds r0, r4, 0
	movs r1, 0
	bl nullsub_34
	ldr r0, _08014824
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08014802
	b _0801494C
_08014802:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0801482C
	ldr r1, _08014828
	ldr r0, [r1]
	cmp r0, 0
	bgt _08014814
	b _0801494C
_08014814:
	subs r0, 0x1
	str r0, [r1]
	b _08014856
	.align 2, 0
_0801481C: .4byte gUnknown_202E748
_08014820: .4byte gUnknown_202EC28
_08014824: .4byte gUnknown_202E77C
_08014828: .4byte gUnknown_202E780
_0801482C:
	ldr r2, _080148E4
	ldrh r1, [r2, 0x2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0801483A
	b _0801494C
_0801483A:
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08014842
	b _0801494C
_08014842:
	ldrh r1, [r2]
	movs r0, 0xF2
	ands r0, r1
	cmp r0, 0x2
	bne _0801484E
	b _0801494C
_0801484E:
	ldrb r0, [r4, 0x5]
	cmp r0, 0
	beq _08014856
	movs r5, 0x1
_08014856:
	cmp r5, 0
	bne _0801494C
	ldr r1, _080148E8
	ldrb r0, [r1]
	adds r2, r0, 0x1
	strb r2, [r1]
	ldr r0, _080148EC
	ldrh r7, [r0]
	movs r0, 0x2
	ands r0, r7
	cmp r0, 0
	beq _08014870
	b _08014A72
_08014870:
	movs r0, 0x8
	ands r2, r0
	cmp r2, 0
	bne _0801487A
	b _08014A72
_0801487A:
	ldr r3, _080148F0
	ldrh r1, [r3]
	ldr r0, _080148F4
	ands r0, r1
	ldr r1, _080148F8
	ands r0, r1
	ldr r4, _080148FC
	ands r0, r4
	ldr r1, _08014900
	ands r0, r1
	ldr r1, _08014904
	ands r0, r1
	movs r1, 0x80
	lsls r1, 7
	ldr r2, _08014908
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r3, 0x2]
	ldr r5, _0801490C
	ands r5, r0
	ands r5, r2
	strh r5, [r3, 0x2]
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r6, 0xF
	lsls r1, r6, 12
	ldr r2, _08014910
	ands r0, r2
	movs r4, 0
	mov r8, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r0, 0x10
	ands r0, r7
	adds r4, r3, 0
	cmp r0, 0
	beq _08014914
	movs r2, 0xF0
	lsls r2, 3
	ldrh r1, [r4, 0x6]
	adds r0, r6, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, 0x6]
	movs r0, 0x70
	b _08014932
	.align 2, 0
_080148E4: .4byte gRealInputs
_080148E8: .4byte gUnknown_202E791
_080148EC: .4byte gUnknown_202E77C
_080148F0: .4byte gUnknown_202E6E0
_080148F4: .4byte 0x0000feff
_080148F8: .4byte 0x0000fdff
_080148FC: .4byte 0x0000f3ff
_08014900: .4byte 0x0000efff
_08014904: .4byte 0x0000dfff
_08014908: .4byte 0x00003fff
_0801490C: .4byte 0x0000c1ff
_08014910: .4byte 0x00000fff
_08014914:
	ldr r3, _08014944
	movs r0, 0xA
	ldrsh r1, [r3, r0]
	adds r1, 0x1
	ands r1, r2
	lsls r1, 4
	ldrh r2, [r4, 0x6]
	adds r0, r6, 0
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x6]
	movs r1, 0x8
	ldrsh r0, [r3, r1]
	ldr r1, _08014948
	ands r0, r1
_08014932:
	strh r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
	b _08014A72
	.align 2, 0
_08014944: .4byte gUnknown_202E748
_08014948: .4byte 0x000001ff
_0801494C:
	ldr r0, _08014960
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0
	bne _08014968
	ldr r1, _08014964
	movs r0, 0xB
	str r0, [r1]
	b _080149BA
	.align 2, 0
_08014960: .4byte gUnknown_202E794
_08014964: .4byte gUnknown_202E744
_08014968:
	ldr r4, _08014974
	ldr r0, [r4]
	cmp r0, 0x9
	bne _08014978
	movs r0, 0xB
	b _080149B8
	.align 2, 0
_08014974: .4byte gUnknown_202E744
_08014978:
	cmp r0, 0x8
	bne _080149B6
	ldr r2, _080149A0
	movs r1, 0x4
	strh r1, [r2]
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	cmp r0, 0x22
	ble _080149B6
	strh r1, [r2, 0x2]
	ldr r0, _080149A4
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080149A8
_08014998:
	movs r0, 0
	bl CallPrepareTextbox_8008C54
	b _080149B6
	.align 2, 0
_080149A0: .4byte gUnknown_202E748
_080149A4: .4byte gUnknown_202E77C
_080149A8:
	ldr r1, [r2, 0x1C]
	cmp r1, 0
	bne _08014998
	movs r0, 0xA
	str r0, [r4]
	str r1, [r2, 0x28]
	b _080149BA
_080149B6:
	movs r0, 0x1
_080149B8:
	str r0, [r4]
_080149BA:
	ldr r1, _080149D0
	movs r0, 0x70
	strh r0, [r1, 0x8]
	ldr r0, _080149D4
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	lsls r0, 3
	adds r0, 0x22
	strh r0, [r1, 0xA]
	b _08014A72
	.align 2, 0
_080149D0: .4byte gUnknown_202E748
_080149D4: .4byte gUnknown_2027370
_080149D8:
	ldr r4, _080149F8
	ldr r0, [r4, 0x28]
	adds r0, 0x1
	str r0, [r4, 0x28]
	ldr r0, _080149FC
	ldr r1, [r0]
	movs r0, 0
	bl _call_via_r1
	ldr r0, [r4, 0x28]
	cmp r0, 0x11
	ble _08014A72
	ldr r1, _08014A00
	movs r0, 0x1
	str r0, [r1]
	b _08014A72
	.align 2, 0
_080149F8: .4byte gUnknown_202E748
_080149FC: .4byte gUnknown_203B088
_08014A00: .4byte gUnknown_202E744
_08014A04:
	ldr r0, _08014A2C
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08014A34
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	ldr r1, _08014A30
	movs r0, 0
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014A2C: .4byte gUnknown_202E77C
_08014A30: .4byte gUnknown_202E744
_08014A34:
	str r0, [r3]
	b _08014A72
_08014A38:
	bl sub_8014A88
	ldr r1, _08014A44
	movs r0, 0x4
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014A44: .4byte gUnknown_202E744
_08014A48:
	bl sub_8014B94
	lsls r0, 24
	cmp r0, 0
	beq _08014A72
	ldr r1, _08014A5C
	movs r0, 0x5
	str r0, [r1]
	b _08014A72
	.align 2, 0
_08014A5C: .4byte gUnknown_202E744
_08014A60:
	bl nullsub_35
	ldr r1, _08014A84
	movs r0, 0xB
_08014A68:
	str r0, [r1]
_08014A6A:
	mov r0, r10
	cmp r0, 0
	beq _08014A72
	b _080144DC
_08014A72:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014A84: .4byte gUnknown_202E744
	thumb_func_end xxx_draw_string_80144C4

	thumb_func_start sub_8014A88
sub_8014A88:
	push {r4-r7,lr}
	sub sp, 0x88
	ldr r0, _08014A98
	ldr r4, [r0]
	movs r5, 0
	movs r7, 0
	movs r6, 0
	b _08014ABE
	.align 2, 0
_08014A98: .4byte gUnknown_202EC14
_08014A9C:
	adds r5, 0xC
	ldr r0, [r4]
	add r1, sp, 0x8
	add r2, sp, 0x88
	movs r3, 0
	bl xxx_format_string
	add r0, sp, 0x8
	bl sub_8008ED0
	cmp r7, r0
	bge _08014AB6
	adds r7, r0, 0
_08014AB6:
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0x9
	bgt _08014AC4
_08014ABE:
	ldr r0, [r4]
	cmp r0, 0
	bne _08014A9C
_08014AC4:
	adds r0, r5, 0
	cmp r5, 0
	bge _08014ACC
	adds r0, r5, 0x7
_08014ACC:
	asrs r2, r0, 3
	movs r0, 0x7
	ands r5, r0
	cmp r5, 0
	beq _08014AD8
	adds r2, 0x1
_08014AD8:
	ldr r4, _08014B74
	ldr r0, _08014B78
	ldr r0, [r0]
	str r0, [r4, 0x34]
	adds r1, r7, 0
	cmp r1, 0
	bge _08014AE8
	adds r1, 0x7
_08014AE8:
	asrs r1, 3
	adds r1, 0x2
	strh r1, [r4, 0x3C]
	adds r0, r4, 0
	adds r0, 0x40
	strh r2, [r0]
	strh r2, [r4, 0x3E]
	movs r0, 0x1C
	subs r0, r1
	strh r0, [r4, 0x38]
	movs r0, 0xE
	subs r0, r2
	strh r0, [r4, 0x3A]
	movs r0, 0x80
	strb r0, [r4]
	movs r0, 0xC0
	strb r0, [r4, 0x18]
	ldr r5, _08014B7C
	ldr r0, [r5]
	cmp r0, 0
	beq _08014B1E
	adds r1, r4, 0
	adds r1, 0x48
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
_08014B1E:
	bl ResetUnusedInputStruct
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl xxx_call_save_unk_text_struct_800641C
	ldr r0, _08014B80
	ldr r1, _08014B84
	ldr r1, [r1]
	ldr r2, _08014B88
	ldr r3, _08014B8C
	ldr r3, [r3]
	ldr r4, _08014B90
	ldr r4, [r4]
	str r4, [sp]
	movs r4, 0x2
	str r4, [sp, 0x4]
	bl sub_8012D60
	ldr r0, [r5]
	cmp r0, 0
	beq _08014B6A
	movs r0, 0x3
	bl sub_80073B8
	ldr r0, [r5]
	ldr r2, [r0, 0x18]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0x2
	movs r3, 0x3
	bl PrintStringOnWindow
	movs r0, 0x3
	bl sub_80073E0
_08014B6A:
	add sp, 0x88
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014B74: .4byte gUnknown_203B198
_08014B78: .4byte gUnknown_202EC10
_08014B7C: .4byte gUnknown_202EC20
_08014B80: .4byte gUnknown_202EBC0
_08014B84: .4byte gUnknown_202EC14
_08014B88: .4byte gUnknown_80D48A0
_08014B8C: .4byte gUnknown_202EC18
_08014B90: .4byte gUnknown_202EC1C
	thumb_func_end sub_8014A88

	thumb_func_start sub_8014B94
sub_8014B94:
	push {r4,lr}
	ldr r4, _08014BA8
	adds r0, r4, 0
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	beq _08014BAC
	movs r0, 0
	b _08014BB6
	.align 2, 0
_08014BA8: .4byte gUnknown_202EBC0
_08014BAC:
	ldr r1, _08014BBC
	adds r0, r4, 0
	bl sub_8013114
	movs r0, 0x1
_08014BB6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08014BBC: .4byte gUnknown_202EC1C
	thumb_func_end sub_8014B94

	thumb_func_start nullsub_35
nullsub_35:
	bx lr
	thumb_func_end nullsub_35

	thumb_func_start xxx_format_string
xxx_format_string:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r5, r0, 0
	str r1, [sp, 0x3C]
	adds r7, r2, 0
	lsls r3, 16
	lsrs r3, 16
	mov r8, r3
	movs r0, 0x1
	mov r10, r0
	mov r9, r0
	subs r7, 0x1
	b _08014F62
_08014BE6:
	movs r1, 0x1
	b _08014C2C
_08014BEA:
	mov r0, r10
	cmp r0, 0
	beq _08014C24
	movs r1, 0
	mov r10, r1
	mov r9, r1
	movs r0, 0x8
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _08014C2E
	ldr r0, _08014C1C
	add r4, sp, 0x3C
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl AppendString_8014FA8
	ldr r0, _08014C20
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl AppendString_8014FA8
	b _08014C2E
	.align 2, 0
_08014C1C: .4byte gUnknown_202E5D8
_08014C20: .4byte gUnknown_80D48F4
_08014C24:
	mov r0, r9
	cmp r0, 0
	beq _08014C2E
	movs r1, 0
_08014C2C:
	mov r9, r1
_08014C2E:
	cmp r6, 0x23
	bne _08014C5A
	ldrb r3, [r5, 0x1]
	cmp r3, 0x50
	beq _08014C3C
	cmp r3, 0x70
	bne _08014C42
_08014C3C:
	movs r0, 0x1
	mov r10, r0
	mov r9, r0
_08014C42:
	ldr r1, [sp, 0x3C]
	adds r2, r1, 0x1
	cmp r2, r7
	bcs _08014C56
	movs r0, 0x23
	strb r0, [r1]
	str r2, [sp, 0x3C]
	strb r3, [r1, 0x1]
	adds r0, r2, 0x1
	str r0, [sp, 0x3C]
_08014C56:
	adds r5, 0x2
	b _08014F62
_08014C5A:
	cmp r6, 0x24
	beq _08014C60
	b _08014F26
_08014C60:
	movs r4, 0
	adds r5, 0x1
	ldrb r0, [r5]
	subs r0, 0x24
	cmp r0, 0x52
	bls _08014C6E
	b _08014F0E
_08014C6E:
	lsls r0, 2
	ldr r1, _08014C78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08014C78: .4byte _08014C7C
	.align 2, 0
_08014C7C:
	.4byte _08014F04
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0C
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014EC4
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014E60
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014E54
	.4byte _08014DC8
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014DDC
	.4byte _08014E10
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014F0E
	.4byte _08014E24
	.4byte _08014F0E
	.4byte _08014E84
_08014DC8:
	adds r5, 0x1
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08014DD8
	adds r4, r1, r0
	b _08014F0C
	.align 2, 0
_08014DD8: .4byte gUnknown_202CF58
_08014DDC:
	adds r5, 0x1
	ldrb r0, [r5]
	cmp r0, 0x6D
	bne _08014DFC
	bl sub_808D3BC
	adds r1, r0, 0
	ldr r4, _08014DF8
	adds r0, r4, 0
	movs r2, 0
	bl PrintColoredPokeNameToBuffer
	b _08014F0E
	.align 2, 0
_08014DF8: .4byte gUnknown_202EB80
_08014DFC:
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08014E0C
	adds r4, r1, r0
	b _08014F0C
	.align 2, 0
_08014E0C: .4byte gUnknown_202D098
_08014E10:
	adds r5, 0x1
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08014E20
	adds r4, r1, r0
	b _08014F0C
	.align 2, 0
_08014E20: .4byte gFileCache + 0x110
_08014E24:
	adds r5, 0x1
	movs r0, 0
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08014E40
	ldr r0, _08014E3C
	bl sub_80920D8
	b _08014E48
	.align 2, 0
_08014E3C: .4byte gTeamName
_08014E40:
	ldr r0, _08014E4C
	ldr r1, _08014E50
	bl strcpy
_08014E48:
	ldr r4, _08014E4C
	b _08014F0E
	.align 2, 0
_08014E4C: .4byte gTeamName
_08014E50: .4byte gUnknown_80D48F8
_08014E54:
	adds r5, 0x1
	ldr r4, _08014E5C
	b _08014F0E
	.align 2, 0
_08014E5C: .4byte gUnknown_202E628
_08014E60:
	adds r5, 0x1
	ldr r1, _08014E7C
	ldr r2, _08014E80
	ldrb r0, [r5]
	subs r0, 0x30
	lsls r0, 2
	adds r0, r2
	adds r5, 0x1
	ldr r2, [r0]
	mov r0, sp
	bl sprintfStatic
_08014E78:
	mov r4, sp
	b _08014F0E
	.align 2, 0
_08014E7C: .4byte gUnknown_80D4900
_08014E80: .4byte gFormatData_202DE30
_08014E84:
	adds r5, 0x1
	ldr r1, _08014EBC
	ldrb r0, [r5]
	subs r0, 0x30
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r5, 0x1
	ldr r1, _08014EC0
	ldrb r2, [r5]
	subs r2, 0x30
	adds r5, 0x1
	mov r0, sp
	bl sprintfStatic
	mov r0, sp
	ldrb r1, [r0]
	cmp r1, 0
	beq _08014E78
	movs r2, 0x60
_08014EAC:
	cmp r1, 0x20
	bne _08014EB2
	strb r2, [r0]
_08014EB2:
	adds r0, 0x1
	ldrb r1, [r0]
	cmp r1, 0
	bne _08014EAC
	b _08014E78
	.align 2, 0
_08014EBC: .4byte gFormatData_202DE30
_08014EC0: .4byte gUnknown_80D4904
_08014EC4:
	adds r5, 0x1
	ldr r1, _08014EFC
	ldrb r0, [r5]
	subs r0, 0x30
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	adds r5, 0x1
	ldr r1, _08014F00
	ldrb r2, [r5]
	subs r2, 0x30
	adds r5, 0x1
	mov r0, sp
	bl sprintfStatic
	mov r0, sp
	ldrb r1, [r0]
	cmp r1, 0
	beq _08014E78
	movs r2, 0x60
_08014EEC:
	cmp r1, 0x20
	bne _08014EF2
	strb r2, [r0]
_08014EF2:
	adds r0, 0x1
	ldrb r1, [r0]
	cmp r1, 0
	bne _08014EEC
	b _08014E78
	.align 2, 0
_08014EFC: .4byte gFormatData_202DE30
_08014F00: .4byte gUnknown_80D4908
_08014F04:
	ldr r4, _08014F08
	b _08014F0E
	.align 2, 0
_08014F08: .4byte gUnknown_80D4910
_08014F0C:
	adds r5, 0x1
_08014F0E:
	cmp r4, 0
	beq _08014F62
	add r1, sp, 0x3C
	adds r0, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl AppendString_8014FA8
	lsls r0, 24
	cmp r0, 0
	bne _08014F7E
	b _08014F62
_08014F26:
	adds r0, r6, 0
	adds r0, 0x7F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _08014F36
	cmp r6, 0x87
	bne _08014F54
_08014F36:
	ldr r0, [sp, 0x3C]
	cmp r0, r7
	bcs _08014F42
	strb r6, [r0]
	adds r0, 0x1
	str r0, [sp, 0x3C]
_08014F42:
	adds r5, 0x1
	ldrb r1, [r5]
	cmp r1, 0
	beq _08014F7E
	ldr r0, [sp, 0x3C]
	cmp r0, r7
	bcs _08014F60
	strb r1, [r0]
	b _08014F5C
_08014F54:
	ldr r0, [sp, 0x3C]
	cmp r0, r7
	bcs _08014F60
	strb r6, [r0]
_08014F5C:
	adds r0, 0x1
	str r0, [sp, 0x3C]
_08014F60:
	adds r5, 0x1
_08014F62:
	ldrb r6, [r5]
	cmp r6, 0
	beq _08014F7E
	cmp r6, 0xD
	beq _08014F72
	cmp r6, 0xA
	beq _08014F72
	b _08014BEA
_08014F72:
	movs r0, 0x80
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _08014F7E
	b _08014BE6
_08014F7E:
	ldr r0, [sp, 0x3C]
	movs r1, 0
	strb r1, [r0]
	ldrb r0, [r5]
	cmp r0, 0xD
	bne _08014F8C
	adds r5, 0x1
_08014F8C:
	ldrb r0, [r5]
	cmp r0, 0xA
	bne _08014F94
	adds r5, 0x1
_08014F94:
	adds r0, r5, 0
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_format_string

	thumb_func_start AppendString_8014FA8
AppendString_8014FA8:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r3, 16
	lsrs r3, 16
	ldr r2, [r5]
	ldrb r1, [r4]
	cmp r1, 0
	beq _08014FE4
	movs r0, 0x80
	ands r0, r3
	lsls r0, 16
	lsrs r3, r0, 16
_08014FC4:
	cmp r3, 0
	beq _08014FD2
	cmp r1, 0xD
	bne _08014FD2
	str r2, [r5]
	movs r0, 0x1
	b _08014FE8
_08014FD2:
	cmp r2, r6
	bcs _08014FDC
	ldrb r0, [r4]
	strb r0, [r2]
	adds r2, 0x1
_08014FDC:
	adds r4, 0x1
	ldrb r1, [r4]
	cmp r1, 0
	bne _08014FC4
_08014FE4:
	str r2, [r5]
	movs r0, 0
_08014FE8:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end AppendString_8014FA8

	thumb_func_start PrintFormatStringOnWindow
PrintFormatStringOnWindow:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x1F8
	adds r5, r0, 0
	adds r6, r1, 0
	adds r0, r2, 0
	mov r8, r3
	ldr r4, [sp, 0x20C]
	add r2, sp, 0x1F8
	add r1, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	ldr r1, _08015030
	add r1, sp
	movs r0, 0
	strb r0, [r1]
	str r4, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	add r2, sp, 0x4
	mov r3, r8
	bl PrintStringOnWindow
	add sp, 0x1F8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08015030: .4byte 0x000001f7
	thumb_func_end PrintFormatStringOnWindow

	thumb_func_start sub_8015034
sub_8015034:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x1FC
	adds r6, r0, 0
	mov r8, r1
	adds r0, r2, 0
	mov r9, r3
	ldr r4, [sp, 0x214]
	ldr r5, [sp, 0x218]
	add r2, sp, 0x1FC
	add r1, sp, 0x8
	movs r3, 0
	bl xxx_format_string
	ldr r1, _0801507C
	add r1, sp
	movs r0, 0
	strb r0, [r1]
	str r4, [sp]
	str r5, [sp, 0x4]
	adds r0, r6, 0
	mov r1, r8
	add r2, sp, 0x8
	mov r3, r9
	bl sub_8008F8C
	add sp, 0x1FC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801507C: .4byte 0x000001fb
	thumb_func_end sub_8015034

    .align 2,0
