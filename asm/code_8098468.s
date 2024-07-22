	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start xxx_script_related_8098468
xxx_script_related_8098468:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, _08098494
	str r0, [r1]
	ldr r4, _08098498
	movs r2, 0
	strb r2, [r4]
	ldr r3, _0809849C
	movs r1, 0x1
	strb r1, [r3]
	ldr r1, _080984A0
	strb r2, [r1]
	subs r0, 0xD
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _08098504
	lsls r0, 2
	ldr r1, _080984A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098494: .4byte gUnknown_20398B4
_08098498: .4byte gUnknown_20398B9
_0809849C: .4byte gUnknown_20398B8
_080984A0: .4byte gUnknown_20398BA
_080984A4: .4byte _080984A8
	.align 2, 0
_080984A8:
	.4byte _080984BC
	.4byte _080984C8
	.4byte _080984CE
	.4byte _080984D4
	.4byte _080984FC
_080984BC:
	movs r1, 0x1
	strb r1, [r2]
	movs r0, 0
	strb r0, [r3]
	strb r1, [r4]
	b _08098504
_080984C8:
	movs r0, 0x1
	strb r0, [r3]
	b _08098502
_080984CE:
	movs r0, 0x1
	strb r0, [r3]
	b _08098502
_080984D4:
	add r2, sp, 0x4
	movs r0, 0x3
	mov r1, sp
	bl sub_8001B88
	ldr r2, _080984F4
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0
	bne _080984EA
	movs r1, 0x1
_080984EA:
	strb r1, [r2]
	ldr r1, _080984F8
	movs r0, 0x1
	strb r0, [r1]
	b _08098504
	.align 2, 0
_080984F4: .4byte gUnknown_20398B8
_080984F8: .4byte gUnknown_20398B9
_080984FC:
	movs r0, 0
	strb r0, [r3]
	movs r0, 0x1
_08098502:
	strb r0, [r4]
_08098504:
	bl sub_801180C
	ldr r0, _080985B0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08098522
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08098522
	movs r0, 0x10
	bl FadeOutAllMusic
_08098522:
	ldr r1, _080985B4
	ldr r2, _080985B8
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	bl xxx_update_some_bg_tiles
	bl sub_8099648
	bl sub_809975C
	bl sub_809D0AC
	bl sub_80A7744
	bl sub_809D490
	bl sub_80A62F0
	bl sub_809C5C4
	bl sub_809A560
	bl sub_809CB50
	bl AllocGroundMapAction
	bl nullsub_117
	bl sub_80AD990
	bl sub_80A77F8
	bl sub_80ABB54
	bl sub_80ACB90
	bl sub_809A62C
	ldr r0, _080985BC
	movs r1, 0
	strb r1, [r0]
	ldr r0, _080985C0
	strb r1, [r0]
	ldr r6, _080985C4
	movs r0, 0x1
	str r0, [r6]
	ldr r1, _080985C8
	movs r0, 0
	str r0, [r1]
	ldr r0, _080985CC
	movs r4, 0x1
	negs r4, r4
	str r4, [r0]
	ldr r5, _080985D0
	movs r0, 0
	movs r1, 0xD
	bl sub_8001658
	strh r0, [r5]
	movs r0, 0
	movs r1, 0xE
	bl sub_8001658
	ldr r1, _080985D4
	str r0, [r1]
	ldr r0, _080985D8
	strh r4, [r0]
	adds r7, r4, 0
	ldr r0, [r6]
	b _08098988
	.align 2, 0
_080985B0: .4byte gUnknown_20398B9
_080985B4: .4byte gUnknown_2026E4E
_080985B8: .4byte 0x00000808
_080985BC: .4byte gUnknown_203B49C
_080985C0: .4byte gUnknown_203B49D
_080985C4: .4byte gUnknown_20398A8
_080985C8: .4byte gUnknown_20398AC
_080985CC: .4byte gUnknown_20398B0
_080985D0: .4byte gUnknown_20398BE
_080985D4: .4byte gUnknown_20398C0
_080985D8: .4byte gUnknown_20398C4
_080985DC:
	movs r0, 0x1
	negs r0, r0
	bl sub_809A71C
	bl ScriptPrintNullTextbox
	bl sub_809977C
	ldr r0, _08098600
	ldr r0, [r0]
	cmp r0, 0x11
	bls _080985F6
	b _08098756
_080985F6:
	lsls r0, 2
	ldr r1, _08098604
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098600: .4byte gUnknown_20398B4
_08098604: .4byte _08098608
	.align 2, 0
_08098608:
	.4byte _08098650
	.4byte _08098756
	.4byte _08098660
	.4byte _08098660
	.4byte _08098756
	.4byte _08098666
	.4byte _08098756
	.4byte _08098756
	.4byte _08098756
	.4byte _0809866A
	.4byte _0809866A
	.4byte _0809866A
	.4byte _0809866A
	.4byte _0809870C
	.4byte _08098748
	.4byte _0809874C
	.4byte _08098750
	.4byte _08098754
_08098650:
	bl sub_8098C58
	ldr r1, _0809865C
	movs r0, 0x1
	str r0, [r1]
	b _08098756
	.align 2, 0
_0809865C: .4byte gUnknown_20398B4
_08098660:
	bl sub_8001D88
	b _08098756
_08098666:
	movs r7, 0x70
	b _08098756
_0809866A:
	ldr r0, _080986BC
	ldr r2, [r0]
	movs r0, 0
	movs r1, 0x16
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x25
	movs r2, 0
	bl sub_80018D8
	bl sub_8098C58
	movs r0, 0
	movs r1, 0x15
	movs r2, 0x1
	movs r3, 0x2
	bl sub_800226C
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _08098756
	cmp r4, 0x51
	bne _080986C0
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	b _080986C6
	.align 2, 0
_080986BC: .4byte gUnknown_20398B4
_080986C0:
	adds r0, r4, 0
	bl sub_80A2608
_080986C6:
	movs r1, 0xA
	ldrsh r7, [r0, r1]
	ldr r5, _08098700
	ldr r0, [r5]
	cmp r0, 0x9
	bne _080986E0
	lsls r2, r4, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x31
	movs r3, 0x1
	bl sub_800199C
_080986E0:
	ldr r0, [r5]
	bl sub_8098FCC
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08098756
	ldr r0, _08098704
	strh r1, [r0]
	ldr r1, _08098708
	movs r0, 0
	str r0, [r1]
	b _08098756
	.align 2, 0
_08098700: .4byte gUnknown_20398B4
_08098704: .4byte gUnknown_20398BE
_08098708: .4byte gUnknown_20398C0
_0809870C:
	bl sub_8098C58
	ldr r1, _08098744
	movs r0, 0x1
	str r0, [r1]
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x1
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xF
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xD
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xE
	movs r2, 0
	bl sub_80018D8
	movs r7, 0x71
	b _08098756
	.align 2, 0
_08098744: .4byte gUnknown_20398B4
_08098748:
	movs r7, 0x73
	b _08098756
_0809874C:
	movs r7, 0x74
	b _08098756
_08098750:
	movs r7, 0x75
	b _08098756
_08098754:
	movs r7, 0x76
_08098756:
	ldr r0, _08098790
	ldrb r0, [r0]
	cmp r0, 0
	bne _080987C0
	movs r0, 0
	movs r1, 0xD
	bl sub_8001658
	adds r5, r0, 0
	ldr r4, _08098794
	ldr r2, [r4]
	movs r0, 0
	movs r1, 0x18
	bl sub_80018D8
	ldr r4, [r4]
	cmp r4, 0x1
	beq _080987A6
	cmp r4, 0x3
	bne _0809879C
	ldr r0, _08098798
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0xF
	bl sub_80018D8
	b _080987A6
	.align 2, 0
_08098790: .4byte gUnknown_20398B9
_08098794: .4byte gUnknown_20398B4
_08098798: .4byte gUnknown_20398BE
_0809879C:
	movs r0, 0
	movs r1, 0xF
	adds r2, r5, 0
	bl sub_80018D8
_080987A6:
	ldr r0, _0809882C
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0xD
	bl sub_80018D8
	ldr r0, _08098830
	ldr r2, [r0]
	movs r0, 0
	movs r1, 0xE
	bl sub_80018D8
_080987C0:
	ldr r1, _08098834
	movs r0, 0x2
	str r0, [r1]
	ldr r0, _08098838
	movs r1, 0
	str r1, [r0]
	ldr r0, _0809883C
	str r1, [r0]
	ldr r0, _08098840
	movs r4, 0x1
	negs r4, r4
	str r4, [r0]
	ldr r2, _08098844
	ldr r1, _0809882C
	ldrh r0, [r1]
	strh r0, [r2]
	strh r4, [r1]
	bl sub_809977C
	bl sub_809D4B0
	adds r0, r4, 0
	bl GroundSprite_Reset
	bl sub_809C63C
	bl sub_809A62C
	bl GroundMap_Reset
	bl sub_809D0BC
	bl DeleteBlankGroundEvents
	bl DeleteBlankGroundLives
	bl DeleteBlankGroundObjects
	bl DeleteBlankGroundEffects
	bl sub_809C658
	bl nullsub_16
	bl sub_8097944
	cmp r7, r4
	beq _08098848
	adds r0, r7, 0
	movs r1, 0
	bl GroundMap_ExecuteEvent
	b _08098850
	.align 2, 0
_0809882C: .4byte gUnknown_20398BE
_08098830: .4byte gUnknown_20398C0
_08098834: .4byte gUnknown_20398B4
_08098838: .4byte gUnknown_20398A8
_0809883C: .4byte gUnknown_20398AC
_08098840: .4byte gUnknown_20398B0
_08098844: .4byte gUnknown_20398BC
_08098848:
	movs r0, 0x66
	movs r1, 0
	bl GroundMap_ExecuteEvent
_08098850:
	bl GroundMap_Action
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	bl xxx_call_update_bg_sound_input
_08098864:
	bl xxx_call_update_bg_sound_input
	bl sub_80A6E68
	ldr r0, _08098890
	ldr r0, [r0]
	cmp r0, 0
	beq _080988B2
	ldr r1, _08098894
	ldr r0, [r1]
	cmp r0, 0
	ble _0809889C
	subs r0, 0x1
	str r0, [r1]
	cmp r0, 0
	bgt _080988F8
	ldr r0, _08098898
	ldr r0, [r0]
	bl sub_80999D4
	b _080988F8
	.align 2, 0
_08098890: .4byte gUnknown_20398A8
_08098894: .4byte gUnknown_20398AC
_08098898: .4byte gUnknown_20398B0
_0809889C:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _080988F8
	bl sub_809C740
	lsls r0, 24
	cmp r0, 0
	bne _0809897C
	b _080988F8
_080988B2:
	ldr r0, _08098968
	ldrb r0, [r0]
	cmp r0, 0
	beq _080988F8
	ldr r0, _0809896C
	ldrb r0, [r0]
	cmp r0, 0
	bne _080988F8
	bl sub_809AFAC
	lsls r0, 24
	cmp r0, 0
	bne _080988F8
	ldr r0, _08098970
	ldrh r0, [r0, 0x2]
	ldr r2, _08098974
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _080988E4
	bl sub_80048BC
	lsls r0, 24
	cmp r0, 0
	beq _080988F8
_080988E4:
	movs r0, 0x72
	movs r1, 0
	bl GroundMap_ExecuteEvent
	movs r0, 0x1E
	bl GroundMainGameCancelRequest
	movs r0, 0x1E
	bl FadeOutAllMusic
_080988F8:
	bl GroundMap_Action
	bl nullsub_124
	bl GroundLives_Action
	bl GroundObject_Action
	bl GroundEffect_Action
	bl nullsub_105
	bl sub_809B474
	bl GroundScript_Unlock
	bl sub_809D25C
	bl sub_80A59DC
	bl sub_809B614
	bl sub_809CA20
	bl sub_80A6E80
	bl sub_8099BE4
	bl sub_8099744
	bl sub_8011860
	ldr r0, _08098978
	ldr r0, [r0]
	bl IncrementPlayTime
	bl sub_800CB20
	bl LoadBufferedInputs
	bl nullsub_120
	bl sub_80A5E70
	bl sub_809B638
	bl nullsub_106
	bl sub_80A73EC
	bl sub_8099750
	bl sub_8009908
	b _08098864
	.align 2, 0
_08098968: .4byte gUnknown_20398B9
_0809896C: .4byte gUnknown_20398B8
_08098970: .4byte gRealInputs
_08098974: .4byte 0x0000030f
_08098978: .4byte gPlayTimeRef
_0809897C:
	bl GroundMap_Reset
	movs r7, 0x1
	negs r7, r7
	ldr r0, _080989E8
	ldr r0, [r0]
_08098988:
	subs r0, 0x1
	cmp r0, 0x1
	bhi _08098990
	b _080985DC
_08098990:
	bl FreeGroundMapAction
	bl nullsub_118
	bl sub_80A78F0
	bl sub_80ABBD4
	bl sub_80ACC10
	bl sub_80ADA08
	bl sub_809CB74
	bl sub_809A610
	bl sub_809C618
	bl sub_80A658C
	bl sub_809D508
	bl sub_80A7754
	bl nullsub_119
	bl sub_8099768
	bl nullsub_103
	bl nullsub_16
	ldr r0, _080989EC
	ldrb r0, [r0]
	cmp r0, 0
	beq _080989FA
	ldr r0, _080989E8
	ldr r0, [r0]
	cmp r0, 0x9
	beq _080989F0
	cmp r0, 0xA
	bne _080989F0
	movs r0, 0x10
	b _08098BD2
	.align 2, 0
_080989E8: .4byte gUnknown_20398A8
_080989EC: .4byte gUnknown_20398B9
_080989F0:
	movs r0, 0x1E
	bl FadeOutAllMusic
	movs r0, 0xF
	b _08098BD2
_080989FA:
	ldr r0, _08098A10
	ldr r0, [r0]
	subs r0, 0x3
	cmp r0, 0x5
	bls _08098A06
	b _08098BC0
_08098A06:
	lsls r0, 2
	ldr r1, _08098A14
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098A10: .4byte gUnknown_20398A8
_08098A14: .4byte _08098A18
	.align 2, 0
_08098A18:
	.4byte _08098A30
	.4byte _08098A72
	.4byte _08098AA0
	.4byte _08098B08
	.4byte _08098B58
	.4byte _08098B8C
_08098A30:
	movs r4, 0x1
	negs r4, r4
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x14
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x4
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x4
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xD
	bl sub_8001658
	adds r2, r0, 0
	movs r0, 0
	movs r1, 0xF
	bl sub_80018D8
	movs r0, 0x5
	b _08098BD2
_08098A72:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x5
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x5
	bl sub_80018D8
	movs r2, 0x1
	negs r2, r2
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	movs r0, 0x6
	b _08098BD2
_08098AA0:
	ldr r5, _08098B04
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl sub_80A2654
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	ldrsh r2, [r5, r0]
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x14
	adds r2, r4, 0
	bl sub_80018D8
	ldrh r2, [r5]
	movs r0, 0
	movs r1, 0x30
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08098B00
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	bl sub_80018D8
_08098B00:
	movs r0, 0x7
	b _08098BD2
	.align 2, 0
_08098B04: .4byte gUnknown_20398C4
_08098B08:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x51
	bl sub_80018D8
	ldr r0, _08098B54
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA
	bne _08098B4E
	movs r0, 0
	movs r1, 0x11
	movs r2, 0
	bl sub_80018D8
_08098B4E:
	movs r0, 0x8
	b _08098BD2
	.align 2, 0
_08098B54: .4byte gUnknown_20398C4
_08098B58:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x50
	bl sub_80018D8
	ldr r0, _08098B88
	ldrb r2, [r0]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0x9
	b _08098BD2
	.align 2, 0
_08098B88: .4byte gUnknown_2039950
_08098B8C:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x52
	bl sub_80018D8
	ldr r0, _08098BBC
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0x7
	bl sub_80018D8
	movs r0, 0xA
	b _08098BD2
	.align 2, 0
_08098BBC: .4byte gUnknown_20398C4
_08098BC0:
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x1
	bl sub_80018D8
	movs r0, 0x10
	bl FadeOutAllMusic
	movs r0, 0xE
_08098BD2:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_script_related_8098468

        .align 2,0 @ Don't pad with nop
