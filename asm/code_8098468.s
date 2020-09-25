	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

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
	bl sub_80118C4
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
	bl sub_80A4A7C
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
	bl sub_809A76C
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
	bl sub_80A4AEC
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
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
	bl sub_8098F44
	movs r0, 0x1E
	bl sub_80118C4
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
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
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
_08098970: .4byte gUnknown_20255F0
_08098974: .4byte 0x0000030f
_08098978: .4byte gUnknown_203B47C
_0809897C:
	bl sub_80A4AEC
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
	bl sub_80A4AC4
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
	bl sub_80118C4
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
	bl sub_80118C4
	movs r0, 0xE
_08098BD2:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_script_related_8098468

	thumb_func_start sub_8098BDC
sub_8098BDC:
	push {lr}
	bl sub_809B57C
	bl GroundScript_Unlock
	bl sub_809D25C
	bl sub_80A59DC
	bl sub_809B614
	bl sub_809CA20
	bl sub_80A6E80
	bl sub_8099BE4
	bl sub_8099744
	bl sub_8011860
	ldr r0, _08098C54
	ldr r0, [r0]
	bl sub_8094FB4
	bl sub_800CB20
	bl sub_800485C
	bl nullsub_120
	bl sub_80A5E70
	bl sub_809B638
	bl nullsub_106
	bl sub_80A73EC
	bl sub_8099750
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	bl sub_80A6E68
	bl GroundMap_Action
	bl nullsub_124
	bl GroundLives_Action
	bl GroundObject_Action
	bl GroundEffect_Action
	pop {r0}
	bx r0
	.align 2, 0
_08098C54: .4byte gUnknown_203B47C
	thumb_func_end sub_8098BDC

	thumb_func_start sub_8098C58
sub_8098C58:
	push {lr}
	movs r0, 0
	movs r1, 0x36
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x39
	bl sub_80015C0
	bl sub_809CB8C
	bl sub_8001D88
	movs r0, 0
	movs r1, 0x2A
	bl sub_8001658
	cmp r0, 0
	beq _08098CA2
	movs r0, 0
	movs r1, 0x29
	bl sub_8001658
	adds r2, r0, 0
	adds r2, 0x1
	cmp r2, 0xF
	ble _08098C90
	movs r2, 0
_08098C90:
	movs r0, 0
	movs r1, 0x29
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x2A
	movs r2, 0
	bl sub_80018D8
_08098CA2:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	bl sub_8001784
	adds r3, r0, 0
	cmp r3, 0
	bgt _08098CB4
	movs r3, 0x1
_08098CB4:
	subs r3, 0x1
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	bl sub_800199C
	bl sub_8098CC8
	pop {r0}
	bx r0
	thumb_func_end sub_8098C58

	thumb_func_start sub_8098CC8
sub_8098CC8:
	push {lr}
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _08098CDE
	movs r1, 0
	b _08098D06
_08098CDE:
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _08098CF2
	movs r1, 0x1
	b _08098D06
_08098CF2:
	movs r0, 0x3
	movs r1, 0x12
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	movs r1, 0x3
	cmp r0, 0
	beq _08098D06
	movs r1, 0x2
_08098D06:
	adds r0, r1, 0
	bl sub_8091980
	bl sub_809674C
	bl sub_80961B4
	bl sub_8091FB4
	pop {r0}
	bx r0
	thumb_func_end sub_8098CC8

	thumb_func_start sub_8098D1C
sub_8098D1C:
	push {r4-r7,lr}
	adds r7, r1, 0
	adds r4, r2, 0
	lsls r0, 16
	asrs r5, r0, 16
	ldr r6, _08098D34
	ldr r0, [r6]
	cmp r0, 0
	beq _08098D38
	movs r0, 0
	b _08098D60
	.align 2, 0
_08098D34: .4byte gUnknown_20398A8
_08098D38:
	ldr r1, _08098D68
	movs r0, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl Log
	movs r1, 0x1
	str r1, [r6]
	ldr r0, _08098D6C
	str r1, [r0]
	ldr r0, _08098D70
	str r4, [r0]
	ldr r1, _08098D74
	movs r0, 0x2
	str r0, [r1]
	ldr r0, _08098D78
	strh r5, [r0]
	ldr r0, _08098D7C
	str r7, [r0]
	movs r0, 0x1
_08098D60:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08098D68: .4byte gUnknown_8115F5C
_08098D6C: .4byte gUnknown_20398AC
_08098D70: .4byte gUnknown_20398B0
_08098D74: .4byte gUnknown_20398B4
_08098D78: .4byte gUnknown_20398BE
_08098D7C: .4byte gUnknown_20398C0
	thumb_func_end sub_8098D1C

	thumb_func_start sub_8098D80
sub_8098D80:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08098DB8
	ldr r0, [r1]
	cmp r0, 0
	bne _08098DC4
	movs r0, 0x3
	str r0, [r1]
	ldr r1, _08098DBC
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098DC0
	str r4, [r0]
	bl sub_809C730
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08098DB2
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_80118C4
_08098DB2:
	movs r0, 0x1
	b _08098DC6
	.align 2, 0
_08098DB8: .4byte gUnknown_20398A8
_08098DBC: .4byte gUnknown_20398AC
_08098DC0: .4byte gUnknown_20398B0
_08098DC4:
	movs r0, 0
_08098DC6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098D80

	thumb_func_start sub_8098DCC
sub_8098DCC:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08098E04
	ldr r0, [r1]
	cmp r0, 0
	bne _08098E10
	movs r0, 0x4
	str r0, [r1]
	ldr r1, _08098E08
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098E0C
	str r4, [r0]
	bl sub_809C730
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08098DFE
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_80118C4
_08098DFE:
	movs r0, 0x1
	b _08098E12
	.align 2, 0
_08098E04: .4byte gUnknown_20398A8
_08098E08: .4byte gUnknown_20398AC
_08098E0C: .4byte gUnknown_20398B0
_08098E10:
	movs r0, 0
_08098E12:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098DCC

	thumb_func_start sub_8098E18
sub_8098E18:
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 16
	asrs r2, r0, 16
	adds r5, r2, 0
	ldr r4, _08098E40
	ldr r0, [r4]
	cmp r0, 0
	bne _08098EA8
	ldr r1, _08098E44
	movs r0, 0
	adds r3, r6, 0
	bl Log
	ldr r0, _08098E48
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098E4C
	movs r0, 0x7
	b _08098E8A
	.align 2, 0
_08098E40: .4byte gUnknown_20398A8
_08098E44: .4byte gUnknown_8115F80
_08098E48: .4byte gUnknown_203B49D
_08098E4C:
	ldr r0, _08098E74
	ldrb r0, [r0]
	ldr r1, _08098E78
	cmp r0, 0
	bne _08098E58
	strh r5, [r1]
_08098E58:
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_80A2750
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	beq _08098E88
	cmp r0, 0x2
	bgt _08098E7C
	cmp r0, 0x1
	beq _08098E84
	b _08098E8C
	.align 2, 0
_08098E74: .4byte gUnknown_203B49C
_08098E78: .4byte gUnknown_20398C4
_08098E7C:
	cmp r0, 0x4
	bne _08098E8C
	movs r0, 0x8
	b _08098E8A
_08098E84:
	movs r0, 0x5
	b _08098E8A
_08098E88:
	movs r0, 0x6
_08098E8A:
	str r0, [r4]
_08098E8C:
	ldr r0, _08098EA0
	movs r1, 0x1
	str r1, [r0]
	ldr r0, _08098EA4
	str r6, [r0]
	bl sub_809C730
	movs r0, 0x1
	b _08098EAA
	.align 2, 0
_08098EA0: .4byte gUnknown_20398AC
_08098EA4: .4byte gUnknown_20398B0
_08098EA8:
	movs r0, 0
_08098EAA:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8098E18

	thumb_func_start sub_8098EB0
sub_8098EB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08098EE4
	ldr r0, [r5]
	cmp r0, 0
	bne _08098EF8
	ldr r0, _08098EE8
	ldrb r0, [r0]
	cmp r0, 0
	beq _08098EF8
	ldr r1, _08098EEC
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0x7
	str r0, [r5]
	ldr r1, _08098EF0
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098EF4
	str r4, [r0]
	bl sub_809C730
	movs r0, 0x1
	b _08098EFA
	.align 2, 0
_08098EE4: .4byte gUnknown_20398A8
_08098EE8: .4byte gUnknown_203B49D
_08098EEC: .4byte gUnknown_8115FA4
_08098EF0: .4byte gUnknown_20398AC
_08098EF4: .4byte gUnknown_20398B0
_08098EF8:
	movs r0, 0
_08098EFA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8098EB0

	thumb_func_start sub_8098F00
sub_8098F00:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08098F10
	ldr r0, [r5]
	cmp r0, 0
	beq _08098F14
	movs r0, 0
	b _08098F32
	.align 2, 0
_08098F10: .4byte gUnknown_20398A8
_08098F14:
	ldr r1, _08098F38
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0x9
	str r0, [r5]
	ldr r1, _08098F3C
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098F40
	str r4, [r0]
	bl sub_809C730
	movs r0, 0x1
_08098F32:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08098F38: .4byte gUnknown_8115FC8
_08098F3C: .4byte gUnknown_20398AC
_08098F40: .4byte gUnknown_20398B0
	thumb_func_end sub_8098F00

	thumb_func_start sub_8098F44
sub_8098F44:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r5, _08098F54
	ldr r0, [r5]
	cmp r0, 0
	beq _08098F58
	movs r0, 0
	b _08098F76
	.align 2, 0
_08098F54: .4byte gUnknown_20398A8
_08098F58:
	ldr r1, _08098F7C
	movs r0, 0
	adds r2, r4, 0
	bl Log
	movs r0, 0xA
	str r0, [r5]
	ldr r1, _08098F80
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08098F84
	str r4, [r0]
	bl sub_809C730
	movs r0, 0x1
_08098F76:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08098F7C: .4byte gUnknown_8115FE8
_08098F80: .4byte gUnknown_20398AC
_08098F84: .4byte gUnknown_20398B0
	thumb_func_end sub_8098F44

	thumb_func_start sub_8098F88
sub_8098F88:
	ldr r0, _08098F90
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08098F90: .4byte gUnknown_20398B9
	thumb_func_end sub_8098F88

	thumb_func_start sub_8098F94
sub_8098F94:
	ldr r0, _08098F9C
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08098F9C: .4byte gUnknown_20398BA
	thumb_func_end sub_8098F94

	thumb_func_start sub_8098FA0
sub_8098FA0:
	push {lr}
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8098FA0

	thumb_func_start sub_8098FB4
sub_8098FB4:
	push {lr}
	movs r0, 0
	movs r1, 0x11
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2B18
	pop {r1}
	bx r1
	thumb_func_end sub_8098FB4

	thumb_func_start sub_8098FCC
sub_8098FCC:
	push {r4,lr}
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809909E
	cmp r1, 0x51
	bne _08098FF6
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	b _08098FF8
_08098FF6:
	adds r0, r2, 0
_08098FF8:
	bl sub_80A2608
	adds r4, r0, 0
	ldr r0, _0809900C
	ldr r0, [r0]
	cmp r0, 0x9
	bne _08099010
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	b _080990B2
	.align 2, 0
_0809900C: .4byte gUnknown_20398B4
_08099010:
	ldrh r0, [r4, 0x4]
	subs r0, 0xB2
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x17
	bhi _080990AE
	lsls r0, 2
	ldr r1, _08099028
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099028: .4byte _0809902C
	.align 2, 0
_0809902C:
	.4byte _0809908C
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990A2
	.4byte _080990AE
	.4byte _080990A2
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990A2
	.4byte _080990AE
	.4byte _080990AE
	.4byte _080990A2
_0809908C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x2
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _080990AE
_0809909E:
	movs r0, 0xC
	b _080990B2
_080990A2:
	movs r0, 0x5
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809909E
_080990AE:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
_080990B2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8098FCC

	thumb_func_start sub_80990B8
sub_80990B8:
	push {lr}
	movs r0, 0xB
	bl sub_8098FCC
	lsls r0, 16
	asrs r2, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bne _080990D2
	bl sub_8098FB4
	b _080990E4
_080990D2:
	ldr r1, _080990E8
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A2B18
_080990E4:
	pop {r1}
	bx r1
	.align 2, 0
_080990E8: .4byte gUnknown_811BAF4
	thumb_func_end sub_80990B8

	thumb_func_start sub_80990EC
sub_80990EC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	adds r7, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	adds r0, r4, 0
	bl sub_80A2608
	mov r8, r0
	ldrb r0, [r0, 0xC]
	movs r5, 0
	strb r0, [r7]
	movs r0, 0x1
	strb r0, [r7, 0x1]
	strb r5, [r7, 0xC]
	adds r0, r4, 0
	bl sub_80A2750
	lsls r0, 16
	asrs r6, r0, 16
	cmp r6, 0x2
	beq _080991C8
	cmp r6, 0x2
	bgt _08099126
	cmp r6, 0x1
	beq _0809912C
	b _080991CA
_08099126:
	cmp r6, 0x4
	beq _080991C4
	b _080991CA
_0809912C:
	movs r1, 0
	strb r5, [r7, 0xB]
	adds r0, r4, 0
	subs r0, 0x25
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0809913E
	movs r1, 0x1
_0809913E:
	cmp r1, 0
	beq _080991CA
	strb r6, [r7, 0xC]
	mov r0, sp
	movs r1, 0x5B
	bl sub_80A8EC0
	add r4, sp, 0x18
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0xA
	bl sub_8092310
	add r5, sp, 0x30
	str r4, [sp, 0x58]
	add r1, sp, 0x5C
	movs r2, 0
	movs r0, 0x5E
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x5E
	strb r2, [r0]
	add r0, sp, 0x60
	movs r1, 0x47
	strb r1, [r0]
	strb r2, [r0, 0x1]
	add r1, sp, 0x64
	movs r0, 0x82
	lsls r0, 1
	strh r0, [r1]
	movs r0, 0xE0
	strh r0, [r1, 0x2]
	movs r0, 0xAC
	strh r0, [r1, 0x4]
	movs r0, 0xBE
	strh r0, [r1, 0x6]
	add r1, sp, 0x6C
	movs r0, 0x50
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6E
	movs r2, 0xF
	strh r2, [r0]
	add r0, sp, 0x70
	strh r6, [r0]
	adds r0, 0x2
	movs r1, 0x19
	strh r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	strh r2, [r0]
	strh r2, [r0, 0x2]
	ldr r0, _080991C0
	str r0, [sp, 0x7C]
	add r1, sp, 0x58
	adds r0, r5, 0
	movs r2, 0x28
	bl memcpy
	adds r0, r7, 0
	adds r0, 0x18
	adds r1, r5, 0
	bl sub_808D144
	b _080991CA
	.align 2, 0
_080991C0: .4byte 0x000061a8
_080991C4:
	strb r5, [r7, 0xB]
	b _080991CA
_080991C8:
	strb r6, [r7, 0xB]
_080991CA:
	movs r0, 0
	strb r0, [r7, 0x4]
	strb r0, [r7, 0xD]
	mov r1, r8
	ldrb r0, [r1, 0x11]
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80990EC

	thumb_func_start sub_80991E0
sub_80991E0:
	push {lr}
	adds r2, r0, 0
	ldr r3, _08099204
	ldrh r0, [r3]
	strh r0, [r1]
	ldr r0, _08099208
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809920C
	movs r0, 0
	ldrsh r1, [r3, r0]
	adds r0, r2, 0
	bl sub_80990EC
	lsls r0, 24
	lsrs r0, 24
	b _08099218
	.align 2, 0
_08099204: .4byte gUnknown_20398C4
_08099208: .4byte gUnknown_203B49C
_0809920C:
	ldr r1, _0809921C
	adds r0, r2, 0
	movs r2, 0x88
	bl memcpy
	movs r0, 0x1
_08099218:
	pop {r1}
	bx r1
	.align 2, 0
_0809921C: .4byte gUnknown_20398C8
	thumb_func_end sub_80991E0

	thumb_func_start sub_8099220
sub_8099220:
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, 0
	beq _08099258
	ldr r1, _08099248
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0809924C
	movs r0, 0
	strb r0, [r1]
	ldr r0, _08099250
	strh r3, [r0]
	ldr r0, _08099254
	adds r1, r2, 0
	movs r2, 0x88
	bl memcpy
	b _0809926A
	.align 2, 0
_08099248: .4byte gUnknown_203B49C
_0809924C: .4byte gUnknown_203B49D
_08099250: .4byte gUnknown_20398C4
_08099254: .4byte gUnknown_20398C8
_08099258:
	ldr r0, _08099270
	strb r2, [r0]
	ldr r0, _08099274
	strb r2, [r0]
	ldr r1, _08099278
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
_0809926A:
	pop {r0}
	bx r0
	.align 2, 0
_08099270: .4byte gUnknown_203B49C
_08099274: .4byte gUnknown_203B49D
_08099278: .4byte gUnknown_20398C4
	thumb_func_end sub_8099220

	thumb_func_start sub_809927C
sub_809927C:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, _080992CC
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _080992D0
	strb r1, [r0]
	ldr r1, _080992D4
	movs r0, 0x50
	strh r0, [r1]
	ldr r4, _080992D8
	strb r5, [r4]
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x50
	bl sub_80018D8
	ldrb r2, [r4]
	movs r0, 0
	movs r1, 0x14
	bl sub_80018D8
	ldr r4, _080992DC
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095494
	subs r4, 0x10
	movs r1, 0
	movs r0, 0x1
	strb r0, [r4, 0xB]
	strb r1, [r4, 0xC]
	strb r1, [r4, 0x4]
	strb r1, [r4, 0xD]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080992CC: .4byte gUnknown_203B49C
_080992D0: .4byte gUnknown_203B49D
_080992D4: .4byte gUnknown_20398C4
_080992D8: .4byte gUnknown_2039950
_080992DC: .4byte gUnknown_20398D8
	thumb_func_end sub_809927C

	thumb_func_start sub_80992E0
sub_80992E0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08099316
	cmp r1, 0x50
	beq _08099316
	cmp r1, 0x51
	beq _08099316
	cmp r1, 0x52
	beq _08099316
	strh r1, [r4]
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	strh r0, [r5]
	movs r0, 0x1
	b _08099322
_08099316:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r4]
	strh r0, [r5]
	movs r0, 0
_08099322:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80992E0

	thumb_func_start sub_8099328
sub_8099328:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x51
	bne _08099358
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	cmp r0, 0x3E
	bhi _08099358
	strb r0, [r4]
	movs r0, 0x1
	b _0809935A
_08099358:
	movs r0, 0
_0809935A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8099328

	thumb_func_start sub_8099360
sub_8099360:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x52
	beq _08099378
	movs r0, 0
	b _0809938E
_08099378:
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	ldrb r0, [r0, 0xC]
	strb r0, [r4]
	movs r0, 0x1
_0809938E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8099360

	thumb_func_start sub_8099394
sub_8099394:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x50
	beq _080993AC
	movs r0, 0
	b _080993B8
_080993AC:
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	strb r0, [r4]
	movs r0, 0x1
_080993B8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8099394

	thumb_func_start sub_80993C0
sub_80993C0:
	push {lr}
	lsls r0, 24
	ldr r2, _080993D4
	movs r1, 0
	cmp r0, 0
	bne _080993CE
	movs r1, 0x1
_080993CE:
	strb r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080993D4: .4byte gUnknown_20398B8
	thumb_func_end sub_80993C0

	thumb_func_start sub_80993D8
sub_80993D8:
	push {lr}
	bl sub_80A4B38
	pop {r0}
	bx r0
	thumb_func_end sub_80993D8

	thumb_func_start sub_80993E4
sub_80993E4:
	push {lr}
	bl sub_80A4B54
	pop {r0}
	bx r0
	thumb_func_end sub_80993E4

	thumb_func_start sub_80993F0
sub_80993F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	movs r0, 0
	mov r10, r0
	bl sub_801180C
	movs r0, 0x10
	bl sub_80118C4
	ldr r1, _0809948C
	ldr r2, _08099490
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	bl xxx_update_some_bg_tiles
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	movs r1, 0x14
	bl sub_8009408
	bl sub_8099648
	bl sub_809975C
	bl sub_809D0AC
	bl sub_8014144
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80A4A7C
	mov r7, sp
	add r0, sp, 0x8
	mov r8, r0
_08099454:
	bl sub_801D9E4
	lsls r0, 24
	cmp r0, 0
	beq _0809949C
	mov r0, r10
	bl sub_801DA58
_08099464:
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	movs r0, 0
	bl sub_8012A18
	bl sub_801DA78
	cmp r0, 0x2
	beq _08099494
	cmp r0, 0x3
	bne _08099464
	bl sub_801DAC0
	lsls r0, 16
	asrs r0, 16
	mov r10, r0
	b _080994A2
	.align 2, 0
_0809948C: .4byte gUnknown_2026E4E
_08099490: .4byte 0x00000808
_08099494:
	movs r1, 0x1
	negs r1, r1
	mov r10, r1
	b _080994A2
_0809949C:
	movs r2, 0x1
	negs r2, r2
	mov r10, r2
_080994A2:
	bl sub_801DB0C
	movs r0, 0x1
	negs r0, r0
	cmp r10, r0
	bne _080994B0
	b _08099624
_080994B0:
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_80A4AEC
	bl sub_809D0BC
	mov r0, r10
	bl GroundMap_Select
	mov r0, sp
	mov r1, r8
	bl sub_80A579C
	ldr r0, [r7, 0x4]
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [r7, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	ldr r0, [sp]
	ldr r1, _08099520
	adds r0, r1
	str r0, [sp]
	ldr r0, [r7, 0x4]
	adds r0, r1
	str r0, [r7, 0x4]
	ldr r0, [sp, 0x8]
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r1, [r0, 0x4]
	adds r1, r2
	str r1, [r0, 0x4]
	ldr r2, [sp, 0x8]
	ldr r0, [sp]
	subs r0, r2, r0
	str r0, [sp, 0x20]
	ldr r0, [r7, 0x4]
	subs r0, r1, r0
	str r0, [sp, 0x24]
	movs r4, 0
	movs r5, 0
	movs r0, 0x4
	bl sub_80999E8
	mov r9, r5
	b _08099604
	.align 2, 0
_08099520: .4byte 0xfffffc00
_08099524:
	ldr r0, _0809953C
	ldrh r1, [r0, 0x2]
	ldrh r6, [r0]
	movs r0, 0x4
	ands r1, r0
	cmp r1, 0
	beq _08099540
	bl sub_80999FC
	movs r1, 0x1
	mov r9, r1
	b _080995AE
	.align 2, 0
_0809953C: .4byte gUnknown_20255F0
_08099540:
	adds r0, r6, 0
	bl sub_809CFE8
	lsls r0, 24
	asrs r1, r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r1, r2
	beq _0809959A
	add r0, sp, 0x10
	movs r2, 0x80
	lsls r2, 1
	bl sub_8002BB8
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	movs r0, 0x2
	ands r6, r0
	cmp r6, 0
	beq _0809956A
	movs r0, 0x4
_0809956A:
	adds r1, r0, 0
	muls r1, r2
	adds r1, r4
	adds r4, r1, 0
	muls r0, r3
	adds r5, r0
	cmp r1, 0
	bge _0809957E
	movs r4, 0
	b _08099588
_0809957E:
	ldr r0, [sp, 0x20]
	cmp r4, r0
	blt _08099588
	adds r4, r0, 0
	subs r4, 0x1
_08099588:
	cmp r5, 0
	bge _08099590
	movs r5, 0
	b _0809959A
_08099590:
	ldr r1, [sp, 0x24]
	cmp r5, r1
	blt _0809959A
	adds r5, r1, 0
	subs r5, 0x1
_0809959A:
	ldr r0, [sp]
	adds r0, r4
	str r0, [sp, 0x18]
	ldr r0, [r7, 0x4]
	adds r0, r5
	add r1, sp, 0x18
	str r0, [r1, 0x4]
	movs r0, 0
	bl sub_809D158
_080995AE:
	bl sub_809D25C
	bl sub_80A59DC
	bl xxx_draw_string_80144C4
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	ldr r0, _08099620
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl sub_8099BE4
	bl sub_8099744
	bl sub_8011860
	bl sub_800CB20
	bl sub_800485C
	bl nullsub_120
	bl sub_80A5E70
	bl xxx_call_update_bg_vram
	bl CopySpritesToOam
	bl sub_8005304
	bl sub_8099750
	bl sub_8009908
_08099604:
	bl xxx_call_update_bg_sound_input
	movs r0, 0
	bl ResetSprites
	mov r2, r9
	cmp r2, 0
	beq _08099524
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _080995AE
	b _08099454
	.align 2, 0
_08099620: .4byte gUnknown_203B46C
_08099624:
	movs r0, 0x10
	bl sub_80118C4
	bl sub_80A4AC4
	bl sub_8099768
	bl nullsub_103
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80993F0

	thumb_func_start sub_8099648
sub_8099648:
	push {lr}
	bl sub_8003600
	bl sub_809965C
	pop {r0}
	bx r0
	thumb_func_end sub_8099648

	thumb_func_start nullsub_103
nullsub_103:
	bx lr
	thumb_func_end nullsub_103

	thumb_func_start sub_809965C
sub_809965C:
	push {r4,lr}
	movs r0, 0
	bl sub_8099690
	ldr r0, _08099688
	ldr r1, _0809968C
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	movs r0, 0xF8
	lsls r0, 1
	ldr r1, [r4, 0x4]
	movs r2, 0x10
	bl sub_800388C
	adds r0, r4, 0
	bl CloseFile
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099688: .4byte gUnknown_811601C
_0809968C: .4byte gUnknown_8300500
	thumb_func_end sub_809965C

	thumb_func_start sub_8099690
sub_8099690:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r0, _080996BC
	ldr r1, _080996C0
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	cmp r4, 0x1
	beq _080996CC
	cmp r4, 0x2
	beq _080996D4
	ldr r0, _080996C4
	ldr r0, [r0]
	ldrb r0, [r0, 0xB]
	ldr r4, _080996C8
	cmp r0, 0
	beq _080996D6
	movs r0, 0x80
	lsls r0, 1
	adds r4, r0
	b _080996D6
	.align 2, 0
_080996BC: .4byte gUnknown_8116028
_080996C0: .4byte gUnknown_8300500
_080996C4: .4byte gUnknown_203B46C
_080996C8: .4byte gUnknown_202D078
_080996CC:
	ldr r4, _080996D0
	b _080996D6
	.align 2, 0
_080996D0: .4byte gUnknown_202D1B8
_080996D4:
	ldr r4, _08099704
_080996D6:
	movs r0, 0xF0
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_800388C
	adds r5, r4, 0
	movs r4, 0
_080996E4:
	adds r0, r4, 0
	adds r0, 0xF0
	adds r1, r5, 0
	adds r5, 0x4
	bl nullsub_5
	adds r4, 0x1
	cmp r4, 0xF
	ble _080996E4
	adds r0, r6, 0
	bl CloseFile
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08099704: .4byte gUnknown_202D1F8
	thumb_func_end sub_8099690

	thumb_func_start sub_8099708
sub_8099708:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	lsls r0, 16
	lsrs r0, 16
	bl sub_8003810
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8099708

	thumb_func_start sub_809971C
sub_809971C:
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r2, 0
	ble _0809973E
	adds r4, r2, 0
_0809972A:
	adds r0, r5, 0
	adds r1, r0, 0x1
	lsls r1, 16
	lsrs r5, r1, 16
	ldm r6!, {r1}
	bl sub_8003810
	subs r4, 0x1
	cmp r4, 0
	bne _0809972A
_0809973E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_809971C

	thumb_func_start sub_8099744
sub_8099744:
	push {lr}
	bl sub_80039B8
	pop {r0}
	bx r0
	thumb_func_end sub_8099744

	thumb_func_start sub_8099750
sub_8099750:
	push {lr}
	bl TransferBGPaletteBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_8099750

	thumb_func_start sub_809975C
sub_809975C:
	push {lr}
	bl sub_809977C
	pop {r0}
	bx r0
	thumb_func_end sub_809975C

	thumb_func_start sub_8099768
sub_8099768:
	push {lr}
	bl sub_809977C
	bl sub_8099744
	bl sub_8099750
	pop {r0}
	bx r0
	thumb_func_end sub_8099768

	thumb_func_start sub_809977C
sub_809977C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r1, _080997DC
	movs r0, 0
	strb r0, [r1]
	ldr r1, _080997E0
	movs r0, 0
	strh r0, [r1]
	ldr r6, _080997E4
	adds r0, r6, 0
	bl sub_8099838
	ldr r0, _080997E8
	mov r8, r0
	bl sub_8099838
	ldr r4, _080997EC
	adds r0, r4, 0
	bl sub_8099838
	subs r4, 0x8
	movs r0, 0
	str r0, [r4]
	movs r5, 0x80
	lsls r5, 1
	strh r5, [r4, 0x14]
	strh r0, [r6, 0xC]
	bl sub_8099DD0
	mov r0, r8
	strh r5, [r0, 0xC]
	adds r0, r5, 0
	bl sub_8099E58
	ldr r1, _080997F0
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0x40
_080997CA:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _080997CA
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080997DC: .4byte gUnknown_2039990
_080997E0: .4byte gUnknown_2039992
_080997E4: .4byte gUnknown_2039958
_080997E8: .4byte gUnknown_2039968
_080997EC: .4byte gUnknown_2039980
_080997F0: .4byte gUnknown_2039998
	thumb_func_end sub_809977C

	thumb_func_start sub_80997F4
sub_80997F4:
	push {lr}
	lsls r0, 16
	ldr r2, _08099818
	lsrs r0, 15
	adds r0, r2
	strh r1, [r0]
	ldr r0, _0809981C
	bl sub_8099848
	ldr r0, _08099820
	bl sub_8099848
	ldr r0, _08099824
	bl sub_8099848
	pop {r0}
	bx r0
	.align 2, 0
_08099818: .4byte gUnknown_2039998
_0809981C: .4byte gUnknown_2039958
_08099820: .4byte gUnknown_2039968
_08099824: .4byte gUnknown_2039980
	thumb_func_end sub_80997F4

	thumb_func_start sub_8099828
sub_8099828:
	lsls r0, 16
	ldr r1, _08099834
	lsrs r0, 15
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_08099834: .4byte gUnknown_2039998
	thumb_func_end sub_8099828

	thumb_func_start sub_8099838
sub_8099838:
	movs r1, 0x1
	str r1, [r0]
	movs r1, 0
	strh r1, [r0, 0xC]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	bx lr
	thumb_func_end sub_8099838

	thumb_func_start sub_8099848
sub_8099848:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bne _08099856
	movs r0, 0x1
	str r0, [r1]
_08099856:
	pop {r0}
	bx r0
	thumb_func_end sub_8099848

	thumb_func_start sub_809985C
sub_809985C:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	blt _08099872
	cmp r1, 0
	bne _08099874
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r2, 0xC]
	movs r0, 0x1
	b _08099876
_08099872:
	movs r1, 0x1E
_08099874:
	movs r0, 0x2
_08099876:
	str r0, [r2]
	strh r1, [r2, 0x4]
	strh r1, [r2, 0x6]
	pop {r0}
	bx r0
	thumb_func_end sub_809985C

	thumb_func_start sub_8099880
sub_8099880:
	push {lr}
	adds r2, r0, 0
	cmp r1, 0
	blt _08099892
	cmp r1, 0
	bne _08099894
	strh r1, [r2, 0xC]
	movs r0, 0x1
	b _08099896
_08099892:
	movs r1, 0x1E
_08099894:
	movs r0, 0x3
_08099896:
	str r0, [r2]
	strh r1, [r2, 0x4]
	strh r1, [r2, 0x6]
	pop {r0}
	bx r0
	thumb_func_end sub_8099880

	thumb_func_start sub_80998A0
sub_80998A0:
	push {r4,lr}
	adds r4, r0, 0
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	cmp r1, 0
	bge _080998B2
	movs r1, 0x1E
_080998B2:
	cmp r2, r3
	bls _080998BE
	movs r0, 0x5
	str r0, [r4]
	subs r0, r2, r3
	b _080998D0
_080998BE:
	cmp r2, r3
	bcs _080998CA
	movs r0, 0x4
	str r0, [r4]
	subs r0, r3, r2
	b _080998D0
_080998CA:
	movs r0, 0x1
	str r0, [r4]
	movs r0, 0
_080998D0:
	strh r0, [r4, 0xA]
	strh r1, [r4, 0x4]
	strh r1, [r4, 0x6]
	strh r2, [r4, 0xC]
	strh r3, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80998A0

	thumb_func_start sub_80998E0
sub_80998E0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	cmp r0, 0x5
	bhi _080999CA
	lsls r0, 2
	ldr r1, _080998F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080998F4: .4byte _080998F8
	.align 2, 0
_080998F8:
	.4byte _080999CA
	.4byte _080999C2
	.4byte _08099910
	.4byte _08099946
	.4byte _08099976
	.4byte _0809999A
_08099910:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _08099940
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	lsls r0, 8
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	ldrh r0, [r4, 0xC]
	cmp r0, r1
	bcs _080999C6
	strh r1, [r4, 0xC]
	b _080999C6
_08099940:
	movs r0, 0x80
	lsls r0, 1
	b _080999C0
_08099946:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	movs r1, 0
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _08099970
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	lsls r0, 8
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	ldrh r0, [r4, 0xC]
	cmp r0, r1
	bls _080999C6
	strh r1, [r4, 0xC]
	b _080999C6
_08099970:
	strh r1, [r4, 0xC]
	str r1, [r4]
	b _080999C6
_08099976:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _080999BE
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	ldrh r0, [r4, 0xA]
	muls r0, r1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	ldrh r1, [r4, 0x8]
	subs r1, r0
	strh r1, [r4, 0xC]
	b _080999C6
_0809999A:
	ldrh r0, [r4, 0x4]
	subs r0, 0x1
	strh r0, [r4, 0x4]
	lsls r0, 16
	cmp r0, 0
	ble _080999BE
	movs r0, 0x4
	ldrsh r1, [r4, r0]
	ldrh r0, [r4, 0xA]
	muls r0, r1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl __divsi3
	ldrh r1, [r4, 0x8]
	adds r1, r0
	strh r1, [r4, 0xC]
	b _080999C6
_080999BE:
	ldrh r0, [r4, 0x8]
_080999C0:
	strh r0, [r4, 0xC]
_080999C2:
	movs r0, 0
	str r0, [r4]
_080999C6:
	movs r0, 0x1
	b _080999CC
_080999CA:
	movs r0, 0
_080999CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80998E0

	thumb_func_start sub_80999D4
sub_80999D4:
	ldr r2, _080999E0
	movs r1, 0x1
	strb r1, [r2]
	ldr r1, _080999E4
	strh r0, [r1]
	bx lr
	.align 2, 0
_080999E0: .4byte gUnknown_2039990
_080999E4: .4byte gUnknown_2039992
	thumb_func_end sub_80999D4

	thumb_func_start sub_80999E8
sub_80999E8:
	push {lr}
	adds r1, r0, 0
	ldr r0, _080999F8
	bl sub_809985C
	pop {r0}
	bx r0
	.align 2, 0
_080999F8: .4byte gUnknown_2039958
	thumb_func_end sub_80999E8

	thumb_func_start sub_80999FC
sub_80999FC:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08099A0C
	bl sub_8099880
	pop {r0}
	bx r0
	.align 2, 0
_08099A0C: .4byte gUnknown_2039958
	thumb_func_end sub_80999FC

	thumb_func_start sub_8099A10
sub_8099A10:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r0, _08099A30
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_80998A0
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099A30: .4byte gUnknown_2039958
	thumb_func_end sub_8099A10

	thumb_func_start sub_8099A34
sub_8099A34:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08099A44
	bl sub_809985C
	pop {r0}
	bx r0
	.align 2, 0
_08099A44: .4byte gUnknown_2039968
	thumb_func_end sub_8099A34

	thumb_func_start sub_8099A48
sub_8099A48:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08099A58
	bl sub_8099880
	pop {r0}
	bx r0
	.align 2, 0
_08099A58: .4byte gUnknown_2039968
	thumb_func_end sub_8099A48

	thumb_func_start sub_8099A5C
sub_8099A5C:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	str r2, [sp]
	ldr r0, _08099A88
	str r4, [r0]
	ldr r2, [sp]
	str r2, [r0, 0x4]
	movs r2, 0
	strh r2, [r0, 0x14]
	adds r0, 0x8
	bl sub_809985C
	subs r0, r4, 0x1
	cmp r0, 0xD
	bhi _08099AF0
	lsls r0, 2
	ldr r1, _08099A8C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099A88: .4byte gUnknown_2039978
_08099A8C: .4byte _08099A90
	.align 2, 0
_08099A90:
	.4byte _08099AC8
	.4byte _08099AF0
	.4byte _08099AC8
	.4byte _08099AF0
	.4byte _08099AE8
	.4byte _08099AF0
	.4byte _08099AE8
	.4byte _08099AF0
	.4byte _08099AE0
	.4byte _08099AF0
	.4byte _08099AE0
	.4byte _08099AF0
	.4byte _08099AE8
	.4byte _08099AE8
_08099AC8:
	ldr r0, _08099AD8
	movs r1, 0x80
	lsls r1, 1
	strh r1, [r0, 0xC]
	ldr r0, _08099ADC
	strh r1, [r0, 0xC]
	b _08099AF0
	.align 2, 0
_08099AD8: .4byte gUnknown_2039968
_08099ADC: .4byte gUnknown_2039958
_08099AE0:
	ldr r1, _08099AE4
	b _08099AEA
	.align 2, 0
_08099AE4: .4byte gUnknown_2039968
_08099AE8:
	ldr r1, _08099AF8
_08099AEA:
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r1, 0xC]
_08099AF0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099AF8: .4byte gUnknown_2039958
	thumb_func_end sub_8099A5C

	thumb_func_start sub_8099AFC
sub_8099AFC:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	str r2, [sp]
	ldr r0, _08099B28
	str r4, [r0]
	ldr r2, [sp]
	str r2, [r0, 0x4]
	movs r2, 0x80
	lsls r2, 1
	strh r2, [r0, 0x14]
	adds r0, 0x8
	bl sub_8099880
	subs r0, r4, 0x2
	cmp r0, 0xC
	bhi _08099B86
	lsls r0, 2
	ldr r1, _08099B2C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099B28: .4byte gUnknown_2039978
_08099B2C: .4byte _08099B30
	.align 2, 0
_08099B30:
	.4byte _08099B64
	.4byte _08099B86
	.4byte _08099B64
	.4byte _08099B86
	.4byte _08099B80
	.4byte _08099B86
	.4byte _08099B80
	.4byte _08099B86
	.4byte _08099B78
	.4byte _08099B86
	.4byte _08099B78
	.4byte _08099B80
	.4byte _08099B80
_08099B64:
	ldr r0, _08099B70
	movs r1, 0
	strh r1, [r0, 0xC]
	ldr r0, _08099B74
	strh r1, [r0, 0xC]
	b _08099B86
	.align 2, 0
_08099B70: .4byte gUnknown_2039968
_08099B74: .4byte gUnknown_2039958
_08099B78:
	ldr r1, _08099B7C
	b _08099B82
	.align 2, 0
_08099B7C: .4byte gUnknown_2039968
_08099B80:
	ldr r1, _08099B90
_08099B82:
	movs r0, 0
	strh r0, [r1, 0xC]
_08099B86:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099B90: .4byte gUnknown_2039958
	thumb_func_end sub_8099AFC

	thumb_func_start sub_8099B94
sub_8099B94:
	push {lr}
	ldr r0, _08099BA4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08099BA8
	movs r0, 0x1
	b _08099BD6
	.align 2, 0
_08099BA4: .4byte gUnknown_2039990
_08099BA8:
	ldr r1, _08099BBC
	ldr r0, [r1]
	cmp r0, 0
	beq _08099BC0
	ldr r0, [r1, 0x8]
	cmp r0, 0
	beq _08099BD6
	movs r0, 0x1
	b _08099BD6
	.align 2, 0
_08099BBC: .4byte gUnknown_2039978
_08099BC0:
	movs r1, 0
	ldr r0, _08099BDC
	ldr r0, [r0]
	cmp r0, 0
	bne _08099BD2
	ldr r0, _08099BE0
	ldr r0, [r0]
	cmp r0, 0
	beq _08099BD4
_08099BD2:
	movs r1, 0x1
_08099BD4:
	adds r0, r1, 0
_08099BD6:
	pop {r1}
	bx r1
	.align 2, 0
_08099BDC: .4byte gUnknown_2039958
_08099BE0: .4byte gUnknown_2039968
	thumb_func_end sub_8099B94

	thumb_func_start sub_8099BE4
sub_8099BE4:
	push {r4,r5,lr}
	ldr r4, _08099C10
	ldr r0, [r4]
	cmp r0, 0
	bne _08099BF6
	ldr r0, [r4, 0x8]
	cmp r0, 0
	bne _08099BF6
	b _08099D08
_08099BF6:
	adds r0, r4, 0
	adds r0, 0x8
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099C14
	ldrh r0, [r4, 0x14]
	ldr r1, [r4, 0x4]
	bl sub_8099E80
	b _08099DC0
	.align 2, 0
_08099C10: .4byte gUnknown_2039978
_08099C14:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _08099C1C
	b _08099DC0
_08099C1C:
	ldr r0, [r4]
	cmp r0, 0xE
	bls _08099C24
	b _08099DC0
_08099C24:
	lsls r0, 2
	ldr r1, _08099C30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099C30: .4byte _08099C34
	.align 2, 0
_08099C34:
	.4byte _08099DC0
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099C70
	.4byte _08099CD8
	.4byte _08099CD8
	.4byte _08099CD8
_08099C70:
	ldr r0, _08099C80
	ldrh r1, [r0, 0x14]
	adds r3, r0, 0
	cmp r1, 0xFF
	bls _08099C84
	movs r0, 0
	str r0, [r3]
	b _08099DC0
	.align 2, 0
_08099C80: .4byte gUnknown_2039978
_08099C84:
	ldr r0, _08099CA0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08099C8E
	b _08099DC0
_08099C8E:
	movs r2, 0
	ldr r0, [r3]
	cmp r0, 0x3
	beq _08099CB2
	cmp r0, 0x3
	bhi _08099CA4
	cmp r0, 0x1
	beq _08099CAE
	b _08099CBC
	.align 2, 0
_08099CA0: .4byte gUnknown_2039990
_08099CA4:
	cmp r0, 0x5
	beq _08099CB6
	cmp r0, 0x7
	beq _08099CBA
	b _08099CBC
_08099CAE:
	movs r2, 0x2
	b _08099CC0
_08099CB2:
	movs r2, 0x4
	b _08099CC0
_08099CB6:
	movs r2, 0x6
	b _08099CC0
_08099CBA:
	movs r2, 0x8
_08099CBC:
	cmp r2, 0
	beq _08099CD4
_08099CC0:
	ldr r0, _08099CD0
	movs r4, 0
	ldrsh r1, [r0, r4]
	adds r0, r2, 0
	ldr r2, [r3, 0x4]
	bl sub_8099AFC
	b _08099DC0
	.align 2, 0
_08099CD0: .4byte gUnknown_2039992
_08099CD4:
	str r2, [r3]
	b _08099DC0
_08099CD8:
	ldr r2, _08099CE4
	ldrh r0, [r2, 0x14]
	cmp r0, 0
	bne _08099CE8
	str r0, [r2]
	b _08099DC0
	.align 2, 0
_08099CE4: .4byte gUnknown_2039978
_08099CE8:
	ldr r0, _08099D00
	ldrb r0, [r0]
	cmp r0, 0
	beq _08099DC0
	ldr r0, [r2]
	ldr r1, _08099D04
	movs r3, 0
	ldrsh r1, [r1, r3]
	ldr r2, [r2, 0x4]
	bl sub_8099AFC
	b _08099DC0
	.align 2, 0
_08099D00: .4byte gUnknown_2039990
_08099D04: .4byte gUnknown_2039992
_08099D08:
	ldr r0, _08099D88
	ldrb r0, [r0]
	cmp r0, 0
	beq _08099D98
	movs r5, 0x1
	ldr r4, _08099D8C
	ldrh r0, [r4, 0xC]
	cmp r0, 0
	bne _08099D20
	ldr r0, [r4]
	cmp r0, 0
	beq _08099D46
_08099D20:
	movs r5, 0
	ldr r0, [r4]
	cmp r0, 0x3
	beq _08099D34
	ldr r0, _08099D90
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_8099880
_08099D34:
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099D46
	ldrh r0, [r4, 0xC]
	bl sub_8099DD0
_08099D46:
	ldr r4, _08099D94
	ldrh r0, [r4, 0xC]
	cmp r0, 0
	bne _08099D54
	ldr r0, [r4]
	cmp r0, 0
	beq _08099D7A
_08099D54:
	movs r5, 0
	ldr r0, [r4]
	cmp r0, 0x3
	beq _08099D68
	ldr r0, _08099D90
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r0, r4, 0
	bl sub_8099880
_08099D68:
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099D7A
	ldrh r0, [r4, 0xC]
	bl sub_8099E58
_08099D7A:
	cmp r5, 0
	beq _08099DC0
	ldr r1, _08099D88
	movs r0, 0
	strb r0, [r1]
	b _08099DC0
	.align 2, 0
_08099D88: .4byte gUnknown_2039990
_08099D8C: .4byte gUnknown_2039958
_08099D90: .4byte gUnknown_2039992
_08099D94: .4byte gUnknown_2039968
_08099D98:
	ldr r4, _08099DC8
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099DAC
	ldrh r0, [r4, 0xC]
	bl sub_8099DD0
_08099DAC:
	ldr r4, _08099DCC
	adds r0, r4, 0
	bl sub_80998E0
	lsls r0, 24
	cmp r0, 0
	beq _08099DC0
	ldrh r0, [r4, 0xC]
	bl sub_8099E58
_08099DC0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099DC8: .4byte gUnknown_2039958
_08099DCC: .4byte gUnknown_2039968
	thumb_func_end sub_8099BE4

	thumb_func_start sub_8099DD0
sub_8099DD0:
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r7, r0, 16
	movs r4, 0
	ldr r6, _08099DF4
	movs r5, 0xD
_08099DDC:
	ldrh r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08099DF8
	lsrs r0, r4, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099E00
	.align 2, 0
_08099DF4: .4byte gUnknown_2039998
_08099DF8:
	lsrs r0, r4, 16
	adds r1, r7, 0
	bl sub_8003664
_08099E00:
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r6, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _08099DDC
	ldr r0, _08099E30
	movs r4, 0x80
	lsls r4, 13
	adds r6, r0, 0
	adds r6, 0x20
	movs r5, 0xE
_08099E1A:
	ldrh r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08099E34
	lsrs r0, r4, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099E3C
	.align 2, 0
_08099E30: .4byte gUnknown_2039998
_08099E34:
	lsrs r0, r4, 16
	adds r1, r7, 0
	bl sub_8003664
_08099E3C:
	movs r0, 0x80
	lsls r0, 9
	adds r4, r0
	adds r6, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _08099E1A
	movs r0, 0x20
	adds r1, r7, 0
	bl sub_8003664
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8099DD0

	thumb_func_start sub_8099E58
sub_8099E58:
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0xF
	adds r1, r4, 0
	bl sub_8003664
	movs r0, 0xE
	adds r1, r4, 0
	bl sub_8003664
	movs r0, 0x1F
	adds r1, r4, 0
	bl sub_8003664
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8099E58

	thumb_func_start sub_8099E80
sub_8099E80:
	push {r4-r7,lr}
	sub sp, 0x4
	str r1, [sp]
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, _08099EA0
	ldr r1, [r0]
	adds r2, r0, 0
	cmp r1, 0xE
	bls _08099E96
	b _0809A558
_08099E96:
	lsls r0, r1, 2
	ldr r1, _08099EA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099EA0: .4byte gUnknown_2039978
_08099EA4: .4byte _08099EA8
	.align 2, 0
_08099EA8:
	.4byte _0809A558
	.4byte _08099EE4
	.4byte _0809A05A
	.4byte _0809A1D2
	.4byte _0809A34A
	.4byte _08099FDE
	.4byte _0809A156
	.4byte _0809A2CE
	.4byte _0809A4BC
	.4byte _08099F5E
	.4byte _0809A0D6
	.4byte _0809A24E
	.4byte _0809A3EA
	.4byte _0809A48A
	.4byte _0809A48A
_08099EE4:
	movs r4, 0
	movs r5, 0
	ldr r7, _08099F00
_08099EEA:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F04
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F0E
	.align 2, 0
_08099F00: .4byte gUnknown_2039998
_08099F04:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F0E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _08099EEA
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _08099F40
	adds r7, r0, 0
	adds r7, 0x20
_08099F28:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F44
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F4E
	.align 2, 0
_08099F40: .4byte gUnknown_2039998
_08099F44:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F4E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08099F28
	b _0809A558
_08099F5E:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _08099F80
	adds r7, r0, 0
	adds r7, 0x1C
_08099F6A:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099F84
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099F8E
	.align 2, 0
_08099F80: .4byte gUnknown_2039998
_08099F84:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099F8E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _08099F6A
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _08099FC0
	adds r7, r0, 0
	adds r7, 0x3E
_08099FA8:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08099FC4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _08099FCE
	.align 2, 0
_08099FC0: .4byte gUnknown_2039998
_08099FC4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_08099FCE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _08099FA8
	b _0809A558
_08099FDE:
	movs r4, 0
	movs r5, 0
	ldr r7, _08099FFC
_08099FE4:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A000
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A00A
	.align 2, 0
_08099FFC: .4byte gUnknown_2039998
_0809A000:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_0809A00A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _08099FE4
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A03C
	adds r7, r0, 0
	adds r7, 0x20
_0809A024:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A040
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A04A
	.align 2, 0
_0809A03C: .4byte gUnknown_2039998
_0809A040:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036AC
_0809A04A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A024
	b _0809A558
_0809A05A:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A078
_0809A060:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A07C
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A086
	.align 2, 0
_0809A078: .4byte gUnknown_2039998
_0809A07C:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A086:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A060
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A0B8
	adds r7, r0, 0
	adds r7, 0x20
_0809A0A0:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A0BC
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A0C6
	.align 2, 0
_0809A0B8: .4byte gUnknown_2039998
_0809A0BC:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A0C6:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A0A0
	b _0809A558
_0809A0D6:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _0809A0F8
	adds r7, r0, 0
	adds r7, 0x1C
_0809A0E2:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A0FC
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A106
	.align 2, 0
_0809A0F8: .4byte gUnknown_2039998
_0809A0FC:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A106:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A0E2
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _0809A138
	adds r7, r0, 0
	adds r7, 0x3E
_0809A120:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A13C
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A146
	.align 2, 0
_0809A138: .4byte gUnknown_2039998
_0809A13C:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A146:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A120
	b _0809A558
_0809A156:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A174
_0809A15C:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A178
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A182
	.align 2, 0
_0809A174: .4byte gUnknown_2039998
_0809A178:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A182:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A15C
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A1B4
	adds r7, r0, 0
	adds r7, 0x20
_0809A19C:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A1B8
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A1C2
	.align 2, 0
_0809A1B4: .4byte gUnknown_2039998
_0809A1B8:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80036F4
_0809A1C2:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A19C
	b _0809A558
_0809A1D2:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A1F0
_0809A1D8:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A1F4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A1FE
	.align 2, 0
_0809A1F0: .4byte gUnknown_2039998
_0809A1F4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A1FE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A1D8
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A230
	adds r7, r0, 0
	adds r7, 0x20
_0809A218:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A234
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A23E
	.align 2, 0
_0809A230: .4byte gUnknown_2039998
_0809A234:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A23E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A218
	b _0809A558
_0809A24E:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
	ldr r0, _0809A270
	adds r7, r0, 0
	adds r7, 0x1C
_0809A25A:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A274
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A27E
	.align 2, 0
_0809A270: .4byte gUnknown_2039998
_0809A274:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A27E:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A25A
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
	ldr r0, _0809A2B0
	adds r7, r0, 0
	adds r7, 0x3E
_0809A298:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A2B4
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A2BE
	.align 2, 0
_0809A2B0: .4byte gUnknown_2039998
_0809A2B4:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A2BE:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A298
	b _0809A558
_0809A2CE:
	movs r4, 0
	movs r5, 0
	ldr r7, _0809A2EC
_0809A2D4:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A2F0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A2FA
	.align 2, 0
_0809A2EC: .4byte gUnknown_2039998
_0809A2F0:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A2FA:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A2D4
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
	ldr r0, _0809A32C
	adds r7, r0, 0
	adds r7, 0x20
_0809A314:
	ldrh r1, [r7]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A330
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A33A
	.align 2, 0
_0809A32C: .4byte gUnknown_2039998
_0809A330:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_8003780
_0809A33A:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r7, 0x2
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A314
	b _0809A558
_0809A34A:
	movs r4, 0
	movs r5, 0
_0809A34E:
	ldr r0, _0809A36C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A370
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A38C
	.align 2, 0
_0809A36C: .4byte gUnknown_2039998
_0809A370:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A382
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A38C
_0809A382:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A38C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A34E
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
_0809A39E:
	ldr r0, _0809A3BC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A3C0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A3DC
	.align 2, 0
_0809A3BC: .4byte gUnknown_2039998
_0809A3C0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A3D2
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A3DC
_0809A3D2:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A3DC:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A39E
	b _0809A558
_0809A3EA:
	movs r4, 0xE
	movs r5, 0xE0
	lsls r5, 12
_0809A3F0:
	ldr r0, _0809A40C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A410
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A42C
	.align 2, 0
_0809A40C: .4byte gUnknown_2039998
_0809A410:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A422
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A42C
_0809A422:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A42C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xF
	ble _0809A3F0
	movs r4, 0x1F
	movs r5, 0xF8
	lsls r5, 13
_0809A43E:
	ldr r0, _0809A45C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A460
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A47C
	.align 2, 0
_0809A45C: .4byte gUnknown_2039998
_0809A460:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A472
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A47C
_0809A472:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A47C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0809A43E
	b _0809A558
_0809A48A:
	ldr r0, [r2]
	cmp r0, 0xD
	beq _0809A496
	cmp r0, 0xE
	beq _0809A4AA
	b _0809A4BC
_0809A496:
	mov r0, sp
	movs r1, 0x90
	strb r1, [r0]
	strb r1, [r0, 0x1]
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1, 0x2]
	movs r0, 0x1
	negs r0, r0
	b _0809A4BA
_0809A4AA:
	mov r1, sp
	movs r0, 0xFF
	strb r0, [r1]
	movs r0, 0xC0
	strb r0, [r1, 0x1]
	movs r0, 0x80
	strb r0, [r1, 0x2]
	subs r0, 0x81
_0809A4BA:
	strb r0, [r1, 0x3]
_0809A4BC:
	movs r4, 0
	movs r5, 0
_0809A4C0:
	ldr r0, _0809A4DC
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A4E0
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A4FC
	.align 2, 0
_0809A4DC: .4byte gUnknown_2039998
_0809A4E0:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A4F2
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A4FC
_0809A4F2:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A4FC:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0xD
	ble _0809A4C0
	movs r4, 0x10
	movs r5, 0x80
	lsls r5, 13
_0809A50E:
	ldr r0, _0809A52C
	lsls r1, r4, 1
	adds r1, r0
	ldrh r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809A530
	lsrs r0, r5, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8003664
	b _0809A54C
	.align 2, 0
_0809A52C: .4byte gUnknown_2039998
_0809A530:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809A542
	lsrs r0, r5, 16
	adds r1, r6, 0
	bl sub_8003664
	b _0809A54C
_0809A542:
	lsrs r0, r5, 16
	adds r1, r6, 0
	ldr r2, [sp]
	bl sub_80037C8
_0809A54C:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x1E
	ble _0809A50E
_0809A558:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8099E80

	thumb_func_start sub_809A560
sub_809A560:
	push {r4-r6,lr}
	bl sub_8014144
	ldr r6, _0809A5F4
	movs r0, 0xB5
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r6]
	movs r4, 0
	str r4, [r0]
	movs r5, 0x1
	negs r5, r5
	str r5, [r0, 0x4]
	str r5, [r0, 0x8]
	ldr r0, _0809A5F8
	strh r4, [r0]
	ldr r0, _0809A5FC
	strh r4, [r0]
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	movs r1, 0x14
	bl sub_8009408
	bl sub_809B294
	ldr r0, [r6]
	ldr r2, _0809A600
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r4, [r1]
	adds r2, 0x4
	adds r1, r0, r2
	str r5, [r1]
	ldr r1, _0809A604
	adds r0, r1
	str r5, [r0]
	bl sub_809A7EC
	ldr r0, [r6]
	ldr r2, _0809A608
	adds r0, r2
	ldr r1, _0809A60C
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A5F4: .4byte gUnknown_3001B64
_0809A5F8: .4byte gUnknown_20399DC
_0809A5FC: .4byte gUnknown_20399DE
_0809A600: .4byte 0x00000414
_0809A604: .4byte 0x00000434
_0809A608: .4byte 0x000005a4
_0809A60C: .4byte 0x0000ffff
	thumb_func_end sub_809A560

	thumb_func_start sub_809A610
sub_809A610:
	push {r4,lr}
	bl sub_809A62C
	ldr r4, _0809A628
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A628: .4byte gUnknown_3001B64
	thumb_func_end sub_809A610

	thumb_func_start sub_809A62C
sub_809A62C:
	push {r4,lr}
	ldr r0, _0809A670
	ldr r0, [r0]
	movs r2, 0
	str r2, [r0]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	ldr r0, _0809A674
	strh r2, [r0]
	ldr r0, _0809A678
	strh r2, [r0]
	movs r4, 0
_0809A648:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_809A83C
	adds r4, 0x1
	cmp r4, 0x9
	ble _0809A648
	ldr r0, _0809A670
	ldr r0, [r0]
	ldr r1, _0809A67C
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A670: .4byte gUnknown_3001B64
_0809A674: .4byte gUnknown_20399DC
_0809A678: .4byte gUnknown_20399DE
_0809A67C: .4byte 0x00000414
	thumb_func_end sub_809A62C

	thumb_func_start sub_809A680
sub_809A680:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0x4
	bhi _0809A6C2
	lsls r0, r4, 2
	ldr r1, _0809A694
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809A694: .4byte _0809A698
	.align 2, 0
_0809A698:
	.4byte _0809A6AC
	.4byte _0809A6BC
	.4byte _0809A6BC
	.4byte _0809A6BC
	.4byte _0809A6BC
_0809A6AC:
	bl sub_809B294
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0809A6D0
_0809A6BC:
	bl sub_809B294
	b _0809A6D0
_0809A6C2:
	bl sub_809B294
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0809A6D0:
	ldr r0, _0809A6E0
	ldr r0, [r0]
	str r4, [r0]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809A6E0: .4byte gUnknown_3001B64
	thumb_func_end sub_809A680

	thumb_func_start sub_809A6E4
sub_809A6E4:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0809A6F4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_0809A6F4: .4byte gUnknown_20399DC
	thumb_func_end sub_809A6E4

	thumb_func_start sub_809A6F8
sub_809A6F8:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0809A708
	ldrh r1, [r2]
	bics r1, r0
	strh r1, [r2]
	bx lr
	.align 2, 0
_0809A708: .4byte gUnknown_20399DC
	thumb_func_end sub_809A6F8

	thumb_func_start sub_809A70C
sub_809A70C:
	ldr r0, _0809A714
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_0809A714: .4byte gUnknown_20399DC
	thumb_func_end sub_809A70C

	thumb_func_start nullsub_209
nullsub_209:
	bx lr
	thumb_func_end nullsub_209

	thumb_func_start sub_809A71C
sub_809A71C:
	push {lr}
	adds r1, r0, 0
	ldr r0, _0809A734
	ldr r0, [r0]
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	adds r0, r1, 0
	bl sub_801416C
	pop {r0}
	bx r0
	.align 2, 0
_0809A734: .4byte gUnknown_3001B64
	thumb_func_end sub_809A71C

	thumb_func_start sub_809A738
sub_809A738:
	push {lr}
	ldr r2, _0809A74C
	ldr r2, [r2]
	str r0, [r2, 0x4]
	str r1, [r2, 0x8]
	bl sub_801416C
	pop {r0}
	bx r0
	.align 2, 0
_0809A74C: .4byte gUnknown_3001B64
	thumb_func_end sub_809A738

	thumb_func_start sub_809A750
sub_809A750:
	push {lr}
	ldr r0, _0809A764
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_809B40C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_0809A764: .4byte gUnknown_3001B64
	thumb_func_end sub_809A750

	thumb_func_start sub_809A768
sub_809A768:
	movs r0, 0
	bx lr
	thumb_func_end sub_809A768

	thumb_func_start sub_809A76C
sub_809A76C:
	push {lr}
	ldr r0, _0809A78C
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0x1
	bcc _0809A7A4
	cmp r1, 0x2
	bls _0809A790
	cmp r1, 0x3
	bne _0809A7A4
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x4
	b _0809A798
	.align 2, 0
_0809A78C: .4byte gUnknown_3001B64
_0809A790:
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x84
_0809A798:
	movs r3, 0
	bl sub_809B2B8
	lsls r0, 24
	lsrs r0, 24
	b _0809A7AE
_0809A7A4:
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	movs r0, 0
_0809A7AE:
	pop {r1}
	bx r1
	thumb_func_end sub_809A76C

	thumb_func_start sub_809A7B4
sub_809A7B4:
	push {lr}
	ldr r0, _0809A7D8
	ldr r0, [r0]
	ldr r1, [r0]
	cmp r1, 0x3
	bhi _0809A7DC
	cmp r1, 0x1
	bcc _0809A7DC
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x4
	movs r3, 0
	bl sub_809B2B8
	lsls r0, 24
	lsrs r0, 24
	b _0809A7E6
	.align 2, 0
_0809A7D8: .4byte gUnknown_3001B64
_0809A7DC:
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	movs r0, 0
_0809A7E6:
	pop {r1}
	bx r1
	thumb_func_end sub_809A7B4

	thumb_func_start sub_809A7EC
sub_809A7EC:
	push {r4-r6,lr}
	ldr r0, _0809A830
	ldr r0, [r0]
	ldr r2, _0809A834
	adds r1, r0, r2
	ldr r0, _0809A838
	adds r6, r0, 0
	movs r3, 0
	movs r2, 0
	movs r4, 0x9
	movs r5, 0xFF
_0809A802:
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
	strh r2, [r1, 0x2]
	strb r3, [r1, 0x4]
	strb r3, [r1, 0x5]
	ldrb r0, [r1, 0x6]
	orrs r0, r5
	strb r0, [r1, 0x6]
	strb r3, [r1, 0x7]
	str r2, [r1, 0x8]
	str r2, [r1, 0xC]
	str r2, [r1, 0x10]
	str r2, [r1, 0x14]
	strb r3, [r1, 0x1C]
	str r2, [r1, 0x20]
	subs r4, 0x1
	adds r1, 0x24
	cmp r4, 0
	bge _0809A802
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A830: .4byte gUnknown_3001B64
_0809A834: .4byte 0x0000043c
_0809A838: .4byte 0x0000ffff
	thumb_func_end sub_809A7EC

	thumb_func_start sub_809A83C
sub_809A83C:
	push {r4-r7,lr}
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0809A8A0
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r3, _0809A8A4
	adds r1, r3
	ldr r2, [r2]
	adds r6, r2, r1
	ldr r1, _0809A8A8
	strh r1, [r6]
	movs r2, 0
	movs r7, 0
	strh r7, [r6, 0x2]
	strb r2, [r6, 0x4]
	strb r2, [r6, 0x5]
	movs r1, 0xFF
	strb r1, [r6, 0x6]
	strb r2, [r6, 0x7]
	str r7, [r6, 0x8]
	str r7, [r6, 0xC]
	str r7, [r6, 0x10]
	str r7, [r6, 0x14]
	strb r2, [r6, 0x1C]
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 4
	ldr r0, _0809A8AC
	adds r0, r4, r0
	ldr r5, _0809A8B0
	adds r1, r5, 0
	bl strcpy
	ldr r0, _0809A8B4
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	ldr r0, [r6, 0x20]
	cmp r0, 0
	beq _0809A89A
	bl CloseFile
	str r7, [r6, 0x20]
_0809A89A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A8A0: .4byte gUnknown_3001B64
_0809A8A4: .4byte 0x0000043c
_0809A8A8: .4byte 0x0000ffff
_0809A8AC: .4byte gUnknown_202DF98
_0809A8B0: .4byte gUnknown_811615C
_0809A8B4: .4byte gPlayerName
	thumb_func_end sub_809A83C

	thumb_func_start sub_809A8B8
sub_809A8B8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	mov r0, sp
	strh r1, [r0]
	ldr r1, _0809A928
	mov r2, r9
	lsls r0, r2, 3
	add r0, r9
	lsls r0, 2
	ldr r2, _0809A92C
	adds r0, r2
	ldr r1, [r1]
	adds r7, r1, r0
	movs r0, 0x1
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x4]
	ldr r0, [r7, 0x20]
	cmp r0, 0
	beq _0809A8F6
	bl CloseFile
	ldr r2, [sp, 0x4]
	str r2, [r7, 0x20]
_0809A8F6:
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl sub_80A7DDC
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0xA
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x13
	bhi _0809A9D6
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A8D54
	adds r5, r0, 0
	cmp r5, 0
	bne _0809A930
	movs r2, 0
	mov r10, r2
	b _0809A9D6
	.align 2, 0
_0809A928: .4byte gUnknown_3001B64
_0809A92C: .4byte 0x0000043c
_0809A930:
	bl sub_808D3BC
	cmp r5, r0
	bne _0809A940
	mov r1, sp
	movs r0, 0x21
	strh r0, [r1]
	b _0809A9D6
_0809A940:
	bl sub_808D3F8
	cmp r5, r0
	bne _0809A950
	mov r1, sp
	movs r0, 0x22
	strh r0, [r1]
	b _0809A9D6
_0809A950:
	ldrb r0, [r5, 0x4]
	subs r0, 0x43
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi _0809A990
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldr r0, _0809A978
	cmp r1, r0
	beq _0809A9D6
	cmp r1, r0
	ble _0809A97C
	adds r0, 0x16
	cmp r1, r0
	bgt _0809A98A
	subs r0, 0x1
	cmp r1, r0
	blt _0809A98A
	b _0809A9D6
	.align 2, 0
_0809A978: .4byte 0x00000183
_0809A97C:
	movs r0, 0x82
	lsls r0, 1
	cmp r1, r0
	beq _0809A9D6
	adds r0, 0x2F
	cmp r1, r0
	beq _0809A9D6
_0809A98A:
	movs r1, 0
	mov r10, r1
	b _0809A9D6
_0809A990:
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r0, 0x87
	lsls r0, 1
	cmp r1, r0
	bgt _0809A9B0
	subs r0, 0x2
	cmp r1, r0
	bge _0809A9D6
	cmp r1, 0x90
	blt _0809A9D2
	cmp r1, 0x92
	ble _0809A9D6
	cmp r1, 0x96
	beq _0809A9D6
	b _0809A9D2
_0809A9B0:
	movs r0, 0xCF
	lsls r0, 1
	cmp r1, r0
	bgt _0809A9CC
	subs r0, 0x4
	cmp r1, r0
	bge _0809A9D6
	subs r0, 0x87
	cmp r1, r0
	bgt _0809A9D2
	subs r0, 0x1
	cmp r1, r0
	blt _0809A9D2
	b _0809A9D6
_0809A9CC:
	ldr r0, _0809A9F0
	cmp r1, r0
	beq _0809A9D6
_0809A9D2:
	movs r0, 0
	mov r10, r0
_0809A9D6:
	mov r0, sp
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x21
	bhi _0809AA98
	lsls r0, 2
	ldr r1, _0809A9F4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809A9F0: .4byte 0x000001a7
_0809A9F4: .4byte _0809A9F8
	.align 2, 0
_0809A9F8:
	.4byte _0809AA80
	.4byte _0809AA80
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA80
	.4byte _0809AA80
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA98
	.4byte _0809AA80
	.4byte _0809AA80
_0809AA80:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_80A8CF0
	lsls r0, 24
	cmp r0, 0
	beq _0809AA94
	movs r2, 0x1
	str r2, [sp, 0x4]
	b _0809AA98
_0809AA94:
	movs r0, 0
	mov r10, r0
_0809AA98:
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809AB34
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A7AE8
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	blt _0809AACE
	mov r0, sp
	ldrh r0, [r0]
	movs r2, 0
	mov r8, r2
	movs r6, 0
	strh r0, [r7]
	adds r0, r1, 0
	bl sub_80A8BFC
	strh r0, [r7, 0x2]
	b _0809AAE6
_0809AACE:
	ldrh r1, [r4]
	movs r2, 0
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0809AB34
	mov r0, sp
	ldrh r0, [r0]
	movs r2, 0
	mov r8, r2
	movs r6, 0
	strh r0, [r7]
	strh r1, [r7, 0x2]
_0809AAE6:
	mov r0, r9
	lsls r4, r0, 2
	add r4, r9
	lsls r4, 4
	ldr r0, _0809AB28
	adds r0, r4, r0
	ldr r5, _0809AB2C
	adds r1, r5, 0
	bl strcpy
	ldr r0, _0809AB30
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	mov r1, r10
	strb r1, [r7, 0x4]
	mov r2, sp
	ldrb r2, [r2, 0x4]
	strb r2, [r7, 0x5]
	movs r0, 0xFF
	strb r0, [r7, 0x6]
	mov r0, r8
	strb r0, [r7, 0x7]
	str r6, [r7, 0x8]
	str r6, [r7, 0xC]
	str r6, [r7, 0x10]
	str r6, [r7, 0x14]
	strb r0, [r7, 0x1C]
	movs r0, 0x1
	b _0809AB3C
	.align 2, 0
_0809AB28: .4byte gUnknown_202DF98
_0809AB2C: .4byte gUnknown_811616C
_0809AB30: .4byte gPlayerName
_0809AB34:
	mov r0, r9
	bl sub_809A83C
	movs r0, 0
_0809AB3C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809A8B8

	thumb_func_start sub_809AB4C
sub_809AB4C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809AB78
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809AB7C
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809AB80
	movs r0, 0
	b _0809ABA0
	.align 2, 0
_0809AB78: .4byte gUnknown_3001B64
_0809AB7C: .4byte 0x0000043c
_0809AB80:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r0, _0809ABA8
	adds r0, r4, r0
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl sub_808D908
	ldr r0, _0809ABAC
	adds r4, r0
	ldr r1, _0809ABB0
	adds r0, r4, 0
	bl strcpy
	movs r0, 0x1
_0809ABA0:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809ABA8: .4byte gUnknown_202DF98
_0809ABAC: .4byte gPlayerName
_0809ABB0: .4byte gUnknown_811617C
	thumb_func_end sub_809AB4C

	thumb_func_start sub_809ABB4
sub_809ABB4:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809ABE0
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809ABE4
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809ABE8
	movs r0, 0
	b _0809AC0A
	.align 2, 0
_0809ABE0: .4byte gUnknown_3001B64
_0809ABE4: .4byte 0x0000043c
_0809ABE8:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r5, _0809AC10
	adds r5, r4, r5
	movs r0, 0x2
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_808D908
	ldr r0, _0809AC14
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	movs r0, 0x1
_0809AC0A:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AC10: .4byte gUnknown_202DF98
_0809AC14: .4byte gPlayerName
	thumb_func_end sub_809ABB4

	thumb_func_start sub_809AC18
sub_809AC18:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	lsls r1, 16
	asrs r1, 16
	ldr r2, _0809AC44
	lsls r0, r5, 3
	adds r0, r5
	lsls r0, 2
	ldr r3, _0809AC48
	adds r0, r3
	ldr r2, [r2]
	adds r6, r2, r0
	adds r0, r5, 0
	bl sub_809A8B8
	lsls r0, 24
	cmp r0, 0
	bne _0809AC4C
	movs r0, 0
	b _0809AC6E
	.align 2, 0
_0809AC44: .4byte gUnknown_3001B64
_0809AC48: .4byte 0x0000043c
_0809AC4C:
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 4
	ldr r0, _0809AC74
	adds r0, r4, r0
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl sub_808D908
	ldr r0, _0809AC78
	adds r4, r0
	movs r3, 0
	ldrsh r1, [r6, r3]
	adds r0, r4, 0
	bl sub_80A8EC0
	movs r0, 0x1
_0809AC6E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AC74: .4byte gUnknown_202DF98
_0809AC78: .4byte gPlayerName
	thumb_func_end sub_809AC18

	thumb_func_start sub_809AC7C
sub_809AC7C:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r0, 16
	lsls r1, 24
	asrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r2, _0809AD10
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, _0809AD14
	adds r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldr r0, [r4, 0x20]
	cmp r0, 0
	beq _0809ACA8
	bl CloseFile
	movs r0, 0
	str r0, [r4, 0x20]
_0809ACA8:
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bge _0809ACB2
	b _0809ADC0
_0809ACB2:
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0809ACBC
	b _0809ADC0
_0809ACBC:
	cmp r1, 0
	bne _0809ACC2
	b _0809ADC0
_0809ACC2:
	cmp r6, 0x15
	beq _0809ACCE
	movs r0, 0
	strb r6, [r4, 0x7]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
_0809ACCE:
	ldr r2, _0809AD18
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r4, 0x8]
	ldrh r0, [r0]
	adds r0, r1
	movs r6, 0
	movs r3, 0
	strh r0, [r4, 0x18]
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r4, 0xC]
	ldrh r0, [r0, 0x2]
	adds r0, r1
	strh r0, [r4, 0x1A]
	ldrb r0, [r4, 0x7]
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	strb r0, [r4, 0x1D]
	strb r6, [r4, 0x1E]
	movs r0, 0x2
	negs r0, r0
	cmp r5, r0
	bne _0809AD1C
	strb r5, [r4, 0x6]
	str r3, [r4, 0x10]
	str r3, [r4, 0x14]
	strb r6, [r4, 0x1C]
	movs r0, 0
	b _0809ADD2
	.align 2, 0
_0809AD10: .4byte gUnknown_3001B64
_0809AD14: .4byte 0x0000043c
_0809AD18: .4byte gUnknown_8116040
_0809AD1C:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _0809ADC0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_808DD90
	str r0, [r4, 0x20]
	cmp r0, 0
	beq _0809ADB6
	strb r5, [r4, 0x6]
	str r0, [r4, 0x10]
	movs r1, 0
	bl GetFileDataPtr
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0x4D
	beq _0809AD62
	cmp r0, 0x4D
	bgt _0809AD4C
	cmp r0, 0x47
	beq _0809AD56
	b _0809ADA8
_0809AD4C:
	cmp r0, 0x53
	beq _0809AD76
	cmp r0, 0x73
	beq _0809AD8A
	b _0809ADA8
_0809AD56:
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x5
	bgt _0809ADA8
	adds r0, r5, 0x6
	b _0809AD9C
_0809AD62:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x3
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x4
	b _0809AD9C
_0809AD76:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x1
	b _0809AD9C
_0809AD8A:
	ldrb r0, [r4, 0x1D]
	cmp r0, 0
	beq _0809ADA8
	movs r0, 0xF
	ands r0, r5
	cmp r0, 0x1
	bgt _0809ADA8
	strb r6, [r4, 0x1D]
	adds r0, r5, 0x2
_0809AD9C:
	lsls r0, 24
	asrs r5, r0, 24
	movs r0, 0x40
	orrs r5, r0
	lsls r0, r5, 24
	asrs r5, r0, 24
_0809ADA8:
	ldr r0, [r4, 0x20]
	ldr r0, [r0, 0x4]
	str r0, [r4, 0x14]
	movs r0, 0xF
	ands r5, r0
	strb r5, [r4, 0x1C]
	b _0809ADBC
_0809ADB6:
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	strb r6, [r4, 0x1C]
_0809ADBC:
	movs r0, 0x1
	b _0809ADD2
_0809ADC0:
	movs r0, 0xFF
	strb r0, [r4, 0x6]
	movs r0, 0
	strb r0, [r4, 0x7]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	strb r0, [r4, 0x1C]
_0809ADD2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809AC7C

	thumb_func_start sub_809ADD8
sub_809ADD8:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0809AE28
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, _0809AE2C
	adds r1, r0
	ldr r0, [r2]
	adds r3, r0, r1
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r0, 0
	blt _0809AE34
	cmp r0, 0
	beq _0809AE34
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r3, 0x8]
	str r1, [r3, 0xC]
	ldr r2, _0809AE30
	ldrb r0, [r3, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r3, 0x8]
	ldrh r0, [r0]
	adds r0, r1
	strh r0, [r3, 0x18]
	ldrb r0, [r3, 0x7]
	lsls r0, 3
	adds r0, r2
	ldr r1, [r3, 0xC]
	ldrh r0, [r0, 0x2]
	adds r0, r1
	strh r0, [r3, 0x1A]
	movs r0, 0x1
	b _0809AE36
	.align 2, 0
_0809AE28: .4byte gUnknown_3001B64
_0809AE2C: .4byte 0x0000043c
_0809AE30: .4byte gUnknown_8116040
_0809AE34:
	movs r0, 0
_0809AE36:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809ADD8

	thumb_func_start sub_809AE3C
sub_809AE3C:
	push {r4,lr}
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	blt _0809AE88
	ldr r1, _0809AE80
	lsls r0, r2, 3
	adds r0, r2
	lsls r0, 2
	ldr r3, _0809AE84
	adds r0, r3
	ldr r1, [r1]
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _0809AE74
	movs r1, 0x6
	ldrsb r1, [r4, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809AE74
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0
	bl sub_809AC7C
_0809AE74:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0809AE88
	adds r0, r4, 0
	adds r0, 0x10
	b _0809AE8A
	.align 2, 0
_0809AE80: .4byte gUnknown_3001B64
_0809AE84: .4byte 0x0000043c
_0809AE88:
	movs r0, 0
_0809AE8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AE3C

	thumb_func_start sub_809AE90
sub_809AE90:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	lsls r1, 16
	asrs r6, r1, 16
	cmp r4, 0
	bne _0809AEA4
	bl sub_809A76C
	b _0809AEE0
_0809AEA4:
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AEDC
	ldr r1, _0809AED0
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl sub_809A680
	ldr r0, _0809AED4
	ldr r0, [r0]
	adds r0, 0xC
	ldr r2, _0809AED8
	lsls r1, r5, 1
	adds r1, r2
	ldrh r1, [r1]
	adds r2, r6, 0
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AEE0
	.align 2, 0
_0809AED0: .4byte gUnknown_8116134
_0809AED4: .4byte gUnknown_3001B64
_0809AED8: .4byte gUnknown_8116148
_0809AEDC:
	bl sub_809A7B4
_0809AEE0:
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809AE90

	thumb_func_start sub_809AEEC
sub_809AEEC:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0809AF1C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF1C
	movs r0, 0x2
	movs r1, 0x1
	bl sub_809A680
	ldr r0, _0809AF18
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0xC2
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AF20
	.align 2, 0
_0809AF18: .4byte gUnknown_3001B64
_0809AF1C:
	bl sub_809A76C
_0809AF20:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AEEC

	thumb_func_start sub_809AF2C
sub_809AF2C:
	push {r4,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _0809AF5C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF5C
	movs r0, 0x2
	movs r1, 0x1
	bl sub_809A680
	ldr r0, _0809AF58
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0xC2
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AF60
	.align 2, 0
_0809AF58: .4byte gUnknown_3001B64
_0809AF5C:
	bl sub_809A76C
_0809AF60:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AF2C

	thumb_func_start sub_809AF6C
sub_809AF6C:
	push {r4,lr}
	adds r4, r1, 0
	cmp r4, 0
	beq _0809AF9C
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809AF9C
	movs r0, 0x3
	movs r1, 0x1
	bl sub_809A680
	ldr r0, _0809AF98
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0x65
	adds r3, r4, 0
	bl sub_809B2B8
	b _0809AFA0
	.align 2, 0
_0809AF98: .4byte gUnknown_3001B64
_0809AF9C:
	bl sub_809A76C
_0809AFA0:
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AF6C

	thumb_func_start sub_809AFAC
sub_809AFAC:
	push {lr}
	movs r1, 0
	ldr r0, _0809AFC4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0809AFBC
	movs r1, 0x1
_0809AFBC:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809AFC4: .4byte gUnknown_3001B64
	thumb_func_end sub_809AFAC

	thumb_func_start sub_809AFC8
sub_809AFC8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r1, 0
	adds r1, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	asrs r1, 16
	ldr r4, _0809AFF8
	negs r2, r0
	orrs r2, r0
	lsrs r2, 31
	str r1, [sp]
	str r3, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	adds r3, r5, 0
	bl sub_809B028
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AFF8: .4byte gUnknown_81160E8
	thumb_func_end sub_809AFC8

	thumb_func_start sub_809AFFC
sub_809AFFC:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	mov r0, sp
	bl sub_809B18C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r4, 0
	beq _0809B01C
	movs r1, 0
	ldr r0, [sp]
	cmp r0, 0x1
	bne _0809B01A
	movs r1, 0x1
_0809B01A:
	strb r1, [r4]
_0809B01C:
	adds r0, r2, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809AFFC

	thumb_func_start sub_809B028
sub_809B028:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	mov r8, r0
	adds r7, r2, 0
	adds r6, r3, 0
	ldr r0, [sp, 0x2C]
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0809B084
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0
	bl sub_809A680
	ldr r0, _0809B088
	ldr r1, [r0]
	ldr r0, _0809B08C
	adds r2, r1, r0
	movs r0, 0x1
	str r0, [r2]
	movs r0, 0x83
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0
	str r0, [r2]
	ldr r2, _0809B090
	adds r0, r1, r2
	mov r2, r8
	str r2, [r0]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r1, r2
	movs r2, 0x2
	str r2, [r0]
	ldr r0, _0809B094
	adds r1, r0
	cmp r5, 0
	beq _0809B098
	str r2, [r1]
	b _0809B09A
	.align 2, 0
_0809B084: .4byte gUnknown_8116134
_0809B088: .4byte gUnknown_3001B64
_0809B08C: .4byte 0x00000414
_0809B090: .4byte 0x0000041c
_0809B094: .4byte 0x00000424
_0809B098:
	str r5, [r1]
_0809B09A:
	ldr r0, _0809B0D4
	ldr r0, [r0]
	movs r1, 0x85
	lsls r1, 3
	adds r2, r0, r1
	movs r1, 0
	str r1, [r2]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	str r7, [r0]
	ldr r0, _0809B0D8
	lsls r2, r6, 1
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	adds r5, r2, 0
	cmp r0, 0
	beq _0809B0F6
	cmp r4, 0
	bge _0809B0E4
	ldr r0, _0809B0DC
	ldr r1, _0809B0E0
	bl strcpy
	b _0809B0F6
	.align 2, 0
_0809B0D4: .4byte gUnknown_3001B64
_0809B0D8: .4byte gUnknown_8116148
_0809B0DC: .4byte gUnknown_202E5D8
_0809B0E0: .4byte gUnknown_8116180
_0809B0E4:
	ldr r0, _0809B134
	ldr r1, _0809B138
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 4
	ldr r3, _0809B13C
	adds r2, r3
	bl sub_800D158
_0809B0F6:
	adds r0, r4, 0
	bl sub_809AE3C
	ldr r4, _0809B140
	movs r1, 0
	str r1, [sp]
	movs r3, 0x4
	str r3, [sp, 0x4]
	str r1, [sp, 0x8]
	str r0, [sp, 0xC]
	ldr r0, _0809B144
	adds r0, r5, r0
	ldrh r2, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r2
	cmp r0, 0
	beq _0809B11C
	movs r1, 0xC
_0809B11C:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	beq _0809B128
	orrs r1, r3
_0809B128:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _0809B148
	movs r0, 0x21
	b _0809B14A
	.align 2, 0
_0809B134: .4byte gUnknown_202E5D8
_0809B138: .4byte gUnknown_8116188
_0809B13C: .4byte gPlayerName
_0809B140: .4byte sub_809B428
_0809B144: .4byte gUnknown_8116148
_0809B148:
	movs r0, 0x1
_0809B14A:
	orrs r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	ldr r0, [sp, 0x30]
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8014248
	ldr r0, _0809B184
	ldr r0, [r0]
	ldr r1, _0809B188
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809B176
	movs r0, 0x1
	bl sub_809A6E4
_0809B176:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B184: .4byte gUnknown_3001B64
_0809B188: .4byte 0x00000424
	thumb_func_end sub_809B028

	thumb_func_start sub_809B18C
sub_809B18C:
	push {lr}
	adds r1, r0, 0
	ldr r2, _0809B1BC
	cmp r1, 0
	beq _0809B1A2
	ldr r0, [r2]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809B1A2:
	movs r1, 0
	ldr r0, [r2]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B1B4
	movs r1, 0x1
_0809B1B4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809B1BC: .4byte gUnknown_3001B64
	thumb_func_end sub_809B18C

	thumb_func_start sub_809B1C0
sub_809B1C0:
	push {lr}
	adds r3, r2, 0
	movs r2, 0
	bl sub_809B1D4
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_809B1C0

	thumb_func_start sub_809B1D4
sub_809B1D4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	cmp r4, 0xB
	beq _0809B1E8
	cmp r4, 0xC
	beq _0809B1F0
	b _0809B202
_0809B1E8:
	adds r0, r5, 0
	bl sub_8021700
	b _0809B1F8
_0809B1F0:
	bl sub_8001D88
	bl sub_802FCF0
_0809B1F8:
	lsls r0, 24
	cmp r0, 0
	beq _0809B202
	movs r0, 0
	b _0809B24C
_0809B202:
	movs r0, 0x4
	movs r1, 0
	bl sub_809A680
	ldr r0, _0809B254
	ldr r1, [r0]
	ldr r2, _0809B258
	adds r0, r1, r2
	str r4, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r1, r3
	movs r2, 0
	str r2, [r0]
	adds r3, 0x4
	adds r0, r1, r3
	str r2, [r0]
	movs r0, 0x84
	lsls r0, 3
	adds r2, r1, r0
	movs r0, 0x1
	str r0, [r2]
	ldr r2, _0809B25C
	adds r0, r1, r2
	str r5, [r0]
	adds r3, 0xC
	adds r0, r1, r3
	str r6, [r0]
	adds r2, 0x8
	adds r0, r1, r2
	str r7, [r0]
	adds r3, 0x8
	adds r1, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	movs r0, 0x1
_0809B24C:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B254: .4byte gUnknown_3001B64
_0809B258: .4byte 0x00000414
_0809B25C: .4byte 0x00000424
	thumb_func_end sub_809B1D4

	thumb_func_start sub_809B260
sub_809B260:
	push {lr}
	adds r1, r0, 0
	ldr r2, _0809B290
	cmp r1, 0
	beq _0809B276
	ldr r0, [r2]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	str r0, [r1]
_0809B276:
	movs r1, 0
	ldr r0, [r2]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B288
	movs r1, 0x1
_0809B288:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_0809B290: .4byte gUnknown_3001B64
	thumb_func_end sub_809B260

	thumb_func_start sub_809B294
sub_809B294:
	push {lr}
	movs r0, 0x3
	bl sub_80063D8
	ldr r0, _0809B2B4
	ldr r0, [r0]
	adds r0, 0xC
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	movs r3, 0
	bl sub_809B2B8
	pop {r0}
	bx r0
	.align 2, 0
_0809B2B4: .4byte gUnknown_3001B64
	thumb_func_end sub_809B294

	thumb_func_start sub_809B2B8
sub_809B2B8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r4, r0, 0
	adds r7, r3, 0
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 16
	asrs r6, r2, 16
	strh r5, [r4]
	cmp r7, 0
	bne _0809B2F6
	cmp r5, 0
	bne _0809B2DE
	str r7, [r4, 0x4]
	movs r0, 0
	b _0809B3FC
_0809B2DE:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	bne _0809B2E8
	b _0809B3FA
_0809B2E8:
	bl sub_8014490
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	b _0809B3FA
_0809B2F6:
	movs r0, 0x1
	str r0, [r4, 0x4]
	adds r0, 0xFF
	ands r0, r5
	cmp r0, 0
	beq _0809B32A
	cmp r6, 0
	bge _0809B318
	ldr r0, _0809B310
	ldr r1, _0809B314
	bl strcpy
	b _0809B32A
	.align 2, 0
_0809B310: .4byte gUnknown_202E5D8
_0809B314: .4byte gUnknown_8116180
_0809B318:
	ldr r0, _0809B3D0
	ldr r1, _0809B3D4
	lsls r2, r6, 2
	adds r2, r6
	lsls r2, 4
	ldr r3, _0809B3D8
	adds r2, r3
	bl sub_800D158
_0809B32A:
	ldr r0, _0809B3DC
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x3
	bne _0809B344
	adds r4, 0x8
	ldr r1, _0809B3E0
	adds r0, r4, 0
	adds r2, r7, 0
	bl sub_800D158
	adds r7, r4, 0
_0809B344:
	adds r0, r6, 0
	bl sub_809AE3C
	ldr r1, _0809B3E4
	mov r9, r1
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	movs r2, 0
	str r2, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r0, [sp, 0xC]
	movs r6, 0x80
	lsls r6, 1
	adds r0, r5, 0
	ands r0, r6
	movs r1, 0
	cmp r0, 0
	beq _0809B370
	movs r1, 0xC
_0809B370:
	movs r4, 0x80
	lsls r4, 2
	adds r0, r5, 0
	ands r0, r4
	cmp r0, 0
	beq _0809B380
	movs r0, 0x4
	orrs r1, r0
_0809B380:
	mov r0, r8
	ldr r3, [r0]
	ldr r2, [r3]
	cmp r2, 0x3
	bne _0809B38E
	movs r0, 0x10
	orrs r1, r0
_0809B38E:
	cmp r2, 0x2
	bne _0809B396
	movs r0, 0x10
	orrs r1, r0
_0809B396:
	adds r2, r1, 0
	movs r1, 0x20
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0809B3A4
	orrs r2, r1
_0809B3A4:
	lsrs r1, r5, 6
	movs r0, 0x1
	ands r1, r0
	orrs r1, r2
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	beq _0809B3B6
	orrs r1, r6
_0809B3B6:
	movs r0, 0x4
	ands r0, r5
	cmp r0, 0
	beq _0809B3C0
	orrs r1, r4
_0809B3C0:
	ldr r0, [r3, 0x4]
	cmp r0, r12
	beq _0809B3E8
	movs r0, 0x2
	orrs r0, r1
	lsls r0, 16
	b _0809B3EA
	.align 2, 0
_0809B3D0: .4byte gUnknown_202E5D8
_0809B3D4: .4byte gUnknown_8116188
_0809B3D8: .4byte gPlayerName
_0809B3DC: .4byte gUnknown_3001B64
_0809B3E0: .4byte gUnknown_8116190
_0809B3E4: .4byte sub_809B428
_0809B3E8:
	lsls r0, r1, 16
_0809B3EA:
	lsrs r0, 16
	str r0, [sp, 0x10]
	adds r0, r7, 0
	mov r1, r9
	mov r2, r12
	movs r3, 0
	bl sub_8014248
_0809B3FA:
	movs r0, 0x1
_0809B3FC:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809B2B8

	thumb_func_start sub_809B40C
sub_809B40C:
	push {lr}
	ldr r0, [r0, 0x4]
	cmp r0, 0
	beq _0809B41C
	cmp r0, 0x3
	bhi _0809B420
	cmp r0, 0x2
	bcc _0809B420
_0809B41C:
	movs r0, 0
	b _0809B422
_0809B420:
	movs r0, 0x1
_0809B422:
	pop {r1}
	bx r1
	thumb_func_end sub_809B40C

	thumb_func_start sub_809B428
sub_809B428:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r2, 0
	ldrb r0, [r5, 0x2]
	cmp r0, 0x4F
	beq _0809B44C
	cmp r0, 0x4F
	bgt _0809B43E
	cmp r0, 0x49
	beq _0809B444
	b _0809B46A
_0809B43E:
	cmp r0, 0x57
	beq _0809B454
	b _0809B46A
_0809B444:
	movs r0, 0x1E
	bl sub_8099A34
	b _0809B462
_0809B44C:
	movs r0, 0x1E
	bl sub_8099A48
	b _0809B462
_0809B454:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809B462
	adds r0, r5, 0
	b _0809B46C
_0809B462:
	adds r1, r4, 0
	adds r1, 0x21
	movs r0, 0x1
	strb r0, [r1]
_0809B46A:
	movs r0, 0
_0809B46C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809B428

	thumb_func_start sub_809B474
sub_809B474:
	push {r4-r6,lr}
	ldr r0, _0809B498
	ldr r1, [r0]
	ldr r2, [r1]
	adds r6, r0, 0
	cmp r2, 0x3
	bls _0809B56E
	cmp r2, 0x4
	bne _0809B56E
	movs r5, 0x84
	lsls r5, 3
	adds r0, r1, r5
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0809B49C
	cmp r0, 0x2
	beq _0809B508
	b _0809B56E
	.align 2, 0
_0809B498: .4byte gUnknown_3001B64
_0809B49C:
	bl sub_809B648
	lsls r0, 24
	cmp r0, 0
	bne _0809B4B0
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x3
	str r1, [r0]
	b _0809B4E8
_0809B4B0:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _0809B4F8
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0809B4F2
	bl sub_809B294
	ldr r0, [r4, 0x4]
	bl _call_via_r0
	lsls r0, 24
	cmp r0, 0
	bne _0809B4F2
	ldr r1, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r2, r1, r3
	movs r0, 0x1
	negs r0, r0
	str r0, [r2]
	adds r1, r5
	movs r0, 0x3
	str r0, [r1]
_0809B4E8:
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
	b _0809B56E
_0809B4F2:
	ldrh r0, [r4]
	bl sub_809A6E4
_0809B4F8:
	ldr r0, _0809B534
	ldr r1, [r0]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	movs r2, 0x2
	str r2, [r1]
	adds r6, r0, 0
_0809B508:
	ldr r0, [r6]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r4, [r0]
	cmp r4, 0
	beq _0809B54E
	ldr r0, [r4, 0xC]
	bl _call_via_r0
	adds r2, r0, 0
	cmp r2, 0x1
	bls _0809B56E
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r1, r0, r3
	cmp r2, 0x2
	bne _0809B538
	movs r0, 0x1
	negs r0, r0
	b _0809B53A
	.align 2, 0
_0809B534: .4byte gUnknown_3001B64
_0809B538:
	movs r0, 0
_0809B53A:
	str r0, [r1]
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0809B546
	bl _call_via_r0
_0809B546:
	ldrh r0, [r4]
	bl sub_809A6F8
	b _0809B558
_0809B54E:
	bl sub_809B648
	lsls r0, 24
	cmp r0, 0
	bne _0809B56E
_0809B558:
	ldr r0, _0809B578
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	movs r1, 0x3
	str r1, [r0]
	movs r0, 0
	movs r1, 0x1
	bl sub_809A680
_0809B56E:
	bl sub_809B57C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B578: .4byte gUnknown_3001B64
	thumb_func_end sub_809B474

	thumb_func_start sub_809B57C
sub_809B57C:
	push {r4,r5,lr}
	sub sp, 0x8
	bl xxx_draw_string_80144C4
	ldr r5, _0809B5C8
	ldr r0, [r5]
	ldr r1, [r0]
	cmp r1, 0x3
	bhi _0809B5E4
	cmp r1, 0x1
	bcc _0809B5E4
	movs r4, 0x84
	lsls r4, 3
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _0809B5CC
	cmp r0, 0x3
	beq _0809B5CC
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0809B5E4
	ldr r1, [sp]
	movs r0, 0x1
	bl sub_809D9E0
	ldr r1, [r5]
	adds r2, r1, r4
	movs r0, 0x3
	str r0, [r2]
	movs r0, 0x86
	lsls r0, 3
	adds r1, r0
	ldr r0, [sp]
	str r0, [r1]
	b _0809B5E4
	.align 2, 0
_0809B5C8: .4byte gUnknown_3001B64
_0809B5CC:
	add r0, sp, 0x4
	bl sub_80144A4
	adds r4, r0, 0
	cmp r4, 0
	bne _0809B5E4
	movs r0, 0
	bl sub_809D9B8
	ldr r0, _0809B5FC
	ldr r0, [r0]
	str r4, [r0]
_0809B5E4:
	ldr r0, _0809B5FC
	ldr r0, [r0]
	ldr r1, _0809B600
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bge _0809B604
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	b _0809B60C
	.align 2, 0
_0809B5FC: .4byte gUnknown_3001B64
_0809B600: .4byte 0x00000434
_0809B604:
	movs r0, 0
	movs r1, 0x5
	bl sub_8005838
_0809B60C:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809B57C

	thumb_func_start sub_809B614
sub_809B614:
	push {lr}
	bl sub_80060EC
	ldr r0, _0809B62C
	ldr r2, _0809B630
	ldrh r1, [r2]
	strh r1, [r0]
	ldr r0, _0809B634
	ands r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0809B62C: .4byte gUnknown_20399DE
_0809B630: .4byte gUnknown_20399DC
_0809B634: .4byte 0x0000fffd
	thumb_func_end sub_809B614

	thumb_func_start sub_809B638
sub_809B638:
	push {lr}
	bl xxx_call_update_bg_vram
	pop {r0}
	bx r0
	thumb_func_end sub_809B638

	thumb_func_start nullsub_210
nullsub_210:
	bx lr
	thumb_func_end nullsub_210

	thumb_func_start sub_809B648
sub_809B648:
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r0, _0809B66C
	ldr r1, [r0]
	ldr r2, _0809B670
	adds r1, r2
	ldr r1, [r1]
	subs r1, 0x2
	adds r6, r0, 0
	cmp r1, 0x2C
	bls _0809B662
	bl _0809C392
_0809B662:
	lsls r0, r1, 2
	ldr r1, _0809B674
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B66C: .4byte gUnknown_3001B64
_0809B670: .4byte 0x00000414
_0809B674: .4byte _0809B678
	.align 2, 0
_0809B678:
	.4byte _0809B72C
	.4byte _0809B772
	.4byte _0809B7AC
	.4byte _0809B834
	.4byte _0809B89C
	.4byte _0809B8FC
	.4byte _0809B91C
	.4byte _0809B944
	.4byte _0809B9D2
	.4byte _0809BA2A
	.4byte _0809BAA8
	.4byte _0809BB66
	.4byte _0809BBDA
	.4byte _0809BBDA
	.4byte _0809BC26
	.4byte _0809BC68
	.4byte _0809C1B4
	.4byte _0809BC78
	.4byte _0809C1C2
	.4byte _0809C1C2
	.4byte _0809C1C8
	.4byte _0809BCBC
	.4byte _0809BCBC
	.4byte _0809BD1C
	.4byte _0809BD64
	.4byte _0809BDE8
	.4byte _0809BE30
	.4byte _0809BE40
	.4byte _0809BE50
	.4byte _0809BE60
	.4byte _0809BE9C
	.4byte _0809BEB8
	.4byte _0809BED4
	.4byte _0809BF70
	.4byte _0809BFFC
	.4byte _0809C072
	.4byte _0809C0B8
	.4byte _0809C0FC
	.4byte _0809C148
	.4byte _0809C158
	.4byte _0809C168
	.4byte _0809C204
	.4byte _0809C238
	.4byte _0809C280
	.4byte _0809C32A
_0809B72C:
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0809B780
	ldr r0, _0809B754
	ldrh r0, [r0, 0x2]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0809B758
	movs r0, 0x86
	lsls r0, 3
	adds r1, r2, r0
	movs r0, 0x1
	str r0, [r1]
	bl _0809C392
	.align 2, 0
_0809B754: .4byte gUnknown_20255F0
_0809B758:
	bl sub_8094D14
	lsls r0, 24
	cmp r0, 0
	beq _0809B784
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x2
	str r1, [r0]
	bl _0809C392
_0809B772:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B78A
_0809B780:
	bl sub_809B294
_0809B784:
	movs r0, 0x1
	bl _0809C394
_0809B78A:
	ldr r0, _0809B7A8
	ldrh r1, [r0]
	ldrh r0, [r0, 0x2]
	movs r2, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0809B79C
	bl _0809C392
_0809B79C:
	ands r1, r2
	cmp r1, 0
	bne _0809B784
	bl _0809C392
	.align 2, 0
_0809B7A8: .4byte gUnknown_20255F0
_0809B7AC:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B7F4
	bl sub_809B294
	ldr r1, [r6]
	ldr r2, _0809B7D8
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B7E0
	ldr r3, _0809B7DC
	adds r0, r1, r3
	ldr r1, [r0]
	movs r0, 0
	bl sub_801602C
	b _0809B784
	.align 2, 0
_0809B7D8: .4byte 0x00000424
_0809B7DC: .4byte 0x0000042c
_0809B7E0:
	ldr r2, _0809B7F0
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, 0x2
	bl sub_801602C
	b _0809B784
	.align 2, 0
_0809B7F0: .4byte 0x0000042c
_0809B7F4:
	bl sub_8016080
	cmp r0, 0x3
	bne _0809B80C
	bl sub_80160D8
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809C1BC
_0809B80C:
	cmp r0, 0x2
	bne _0809B784
	ldr r0, [r6]
	ldr r1, _0809B830
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0809B784
	bl sub_80160D8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
_0809B828:
	movs r1, 0
	str r1, [r0]
	bl _0809C392
	.align 2, 0
_0809B830: .4byte 0x00000424
_0809B834:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B85C
	bl sub_809B294
	ldr r0, [r6]
	ldr r1, _0809B858
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x1
	bl sub_801602C
	b _0809B784
	.align 2, 0
_0809B858: .4byte 0x0000042c
_0809B85C:
	bl sub_8016080
	cmp r0, 0x3
	bne _0809B874
	bl sub_80160D8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	bl _0809C1BC
_0809B874:
	cmp r0, 0x2
	beq _0809B87A
	b _0809B784
_0809B87A:
	ldr r0, [r6]
	ldr r3, _0809B898
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B888
	b _0809B784
_0809B888:
	bl sub_80160D8
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	b _0809B828
	.align 2, 0
_0809B898: .4byte 0x00000424
_0809B89C:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B8C4
	bl sub_809B294
	ldr r0, [r6]
	ldr r3, _0809B8C0
	adds r0, r3
	ldr r1, [r0]
	movs r0, 0x4
	bl sub_80151C0
	b _0809B784
	.align 2, 0
_0809B8C0: .4byte 0x0000042c
_0809B8C4:
	bl sub_80154F0
	cmp r0, 0x3
	bne _0809B8D4
	bl sub_80155F0
	bl _0809C1B4
_0809B8D4:
	cmp r0, 0x2
	beq _0809B8DA
	b _0809B784
_0809B8DA:
	ldr r0, [r6]
	ldr r2, _0809B8F8
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0
	bne _0809B8E8
	b _0809B784
_0809B8E8:
	bl sub_80155F0
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B828
	.align 2, 0
_0809B8F8: .4byte 0x00000424
_0809B8FC:
	ldr r0, [r6]
	ldr r1, _0809B914
	adds r0, r1
	ldr r0, [r0]
	bl sub_801D014
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809B918
	b _0809B932
	.align 2, 0
_0809B914: .4byte 0x0000042c
_0809B918: .4byte gUnknown_81161A8
_0809B91C:
	ldr r0, [r6]
	ldr r3, _0809B93C
	adds r0, r3
	ldr r0, [r0]
	bl sub_801D014
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809B940
_0809B932:
	str r1, [r0]
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
	.align 2, 0
_0809B93C: .4byte 0x0000042c
_0809B940: .4byte gUnknown_81161B8
_0809B944:
	bl sub_809B294
	ldr r4, _0809B984
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809B998
	bl sub_809B294
	ldr r0, [r4]
	ldr r3, _0809B988
	adds r0, r3
	ldr r0, [r0]
	ldr r1, _0809B98C
	bl sub_8015080
	lsls r0, 24
	cmp r0, 0
	bne _0809B990
	ldr r0, [r4]
_0809B972:
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
_0809B978:
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl _0809C392
	.align 2, 0
_0809B984: .4byte gUnknown_3001B64
_0809B988: .4byte 0x0000042c
_0809B98C: .4byte gUnknown_811610C
_0809B990:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809B998:
	bl sub_801516C
	cmp r0, 0x2
	beq _0809B9BC
	cmp r0, 0x3
	beq _0809B9A6
	b _0809B784
_0809B9A6:
	bl sub_8015198
	ldr r1, [r4]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	str r0, [r1]
	bl sub_80151A4
	bl _0809C392
_0809B9BC:
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_80151A4
	bl _0809C392
_0809B9D2:
	bl sub_809B294
	ldr r4, _0809BA08
	ldr r0, [r4]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BA1C
	bl sub_809B294
	ldr r0, [r4]
	ldr r2, _0809BA0C
	adds r0, r2
	ldr r0, [r0]
	ldr r1, _0809BA10
	bl sub_8015080
	lsls r0, 24
	cmp r0, 0
	bne _0809BA14
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BA08: .4byte gUnknown_3001B64
_0809BA0C: .4byte 0x0000042c
_0809BA10: .4byte gUnknown_811612C
_0809BA14:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BA1C:
	bl sub_801516C
	cmp r0, 0x2
	beq _0809B9BC
	cmp r0, 0x3
	beq _0809B9A6
	b _0809B784
_0809BA2A:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BA68
	bl sub_809B294
	ldr r0, [r6]
	ldr r2, _0809BA5C
	adds r0, r2
	ldr r0, [r0]
	movs r1, 0x3
	bl sub_80211AC
	lsls r0, 24
	cmp r0, 0
	bne _0809BA60
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BA5C: .4byte 0x00000424
_0809BA60:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BA68:
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x2
	beq _0809BA92
	cmp r0, 0x3
	beq _0809BA78
	b _0809B784
_0809BA78:
	bl sub_802132C
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	bl sub_80213A0
	bl _0809C392
_0809BA92:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_80213A0
	bl _0809C392
_0809BAA8:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BB10
	movs r0, 0
	movs r1, 0x12
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2654
	lsls r0, 16
	asrs r4, r0, 16
	bl sub_809B294
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	movs r3, 0x1
	bl sub_802F73C
	lsls r0, 24
	cmp r0, 0
	bne _0809BAEA
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
_0809BAEA:
	movs r5, 0x1
	negs r5, r5
	cmp r4, r5
	beq _0809BB08
	adds r0, r4, 0
	bl sub_802F848
	lsls r0, 24
	cmp r0, 0
	bne _0809BB08
	movs r0, 0
	movs r1, 0x12
	adds r2, r5, 0
	bl sub_80018D8
_0809BB08:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BB10:
	movs r0, 0x1
	bl sub_802F8A0
	cmp r0, 0x2
	beq _0809BB50
	cmp r0, 0x3
	beq _0809BB20
	b _0809B784
_0809BB20:
	bl sub_802F90C
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	str r4, [r0]
	bl sub_802F974
	bl _0809C392
_0809BB50:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_802F974
	bl _0809C392
_0809BB66:
	ldr r0, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BB9A
	bl sub_809B294
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	bl sub_80302E8
	lsls r0, 24
	cmp r0, 0
	bne _0809BB92
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
_0809BB92:
	movs r0, 0x4
	bl sub_80119D4
	b _0809B784
_0809BB9A:
	movs r0, 0x1
	bl sub_80303AC
	cmp r0, 0x2
	beq _0809BBC4
	cmp r0, 0x3
	beq _0809BBAA
	b _0809B784
_0809BBAA:
	bl sub_8030418
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	str r0, [r1]
	bl sub_8030480
	bl _0809C392
_0809BBC4:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_8030480
	bl _0809C392
_0809BBDA:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BC14
	bl sub_809B294
	ldr r0, [r6]
	ldr r2, _0809BC10
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xE
	bne _0809BC02
	movs r0, 0
	movs r1, 0x18
	movs r2, 0x1
	bl sub_80018D8
_0809BC02:
	movs r0, 0x1
	bl sub_8011C28
	movs r0, 0
	bl sub_8012574
	b _0809B784
	.align 2, 0
_0809BC10: .4byte 0x00000414
_0809BC14:
	bl sub_8012600
	lsls r0, 24
	cmp r0, 0
	beq _0809BC20
	b _0809B784
_0809BC20:
	bl sub_8012750
	b _0809C392
_0809BC26:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_8016C94
	lsls r0, 24
	cmp r0, 0
	beq _0809BC5C
	ldr r0, _0809BC54
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BC58
	b _0809C266
	.align 2, 0
_0809BC54: .4byte gUnknown_3001B64
_0809BC58: .4byte gUnknown_81161C8
_0809BC5C:
	ldr r0, _0809BC64
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BC64: .4byte gUnknown_3001B64
_0809BC68:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BC74
	b _0809C266
	.align 2, 0
_0809BC74: .4byte gUnknown_81161D8
_0809BC78:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_80162E4
	lsls r0, 24
	cmp r0, 0
	beq _0809BCB0
	ldr r0, _0809BCA8
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BCAC
	b _0809C266
	.align 2, 0
_0809BCA8: .4byte gUnknown_3001B64
_0809BCAC: .4byte gUnknown_81161E8
_0809BCB0:
	ldr r0, _0809BCB8
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BCB8: .4byte gUnknown_3001B64
_0809BCBC:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_809B294
	ldr r0, _0809BCE0
	ldr r0, [r0]
	ldr r2, _0809BCE4
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x17
	bne _0809BCE8
	negs r0, r4
	orrs r0, r4
	lsrs r0, 31
	b _0809BCF0
	.align 2, 0
_0809BCE0: .4byte gUnknown_3001B64
_0809BCE4: .4byte 0x00000414
_0809BCE8:
	movs r0, 0x2
	cmp r4, 0
	beq _0809BCF0
	movs r0, 0x3
_0809BCF0:
	bl sub_8018B00
	lsls r0, 24
	cmp r0, 0
	beq _0809BD10
	ldr r0, _0809BD08
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BD0C
	b _0809C266
	.align 2, 0
_0809BD08: .4byte gUnknown_3001B64
_0809BD0C: .4byte gUnknown_81161F8
_0809BD10:
	ldr r0, _0809BD18
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809BD18: .4byte gUnknown_3001B64
_0809BD1C:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_801FB50
	lsls r0, 24
	cmp r0, 0
	beq _0809BD54
	ldr r0, _0809BD4C
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BD50
	b _0809C266
	.align 2, 0
_0809BD4C: .4byte gUnknown_3001B64
_0809BD50: .4byte gUnknown_8116208
_0809BD54:
	ldr r0, _0809BD60
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BD60: .4byte gUnknown_3001B64
_0809BD64:
	ldr r0, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809BD84
	bl sub_809B294
	movs r0, 0
	movs r1, 0x39
	bl sub_80015C0
	bl sub_802465C
	b _0809B784
_0809BD84:
	bl sub_80246F0
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x39
	bl sub_8001658
	cmp r0, 0
	bne _0809BDB2
	bl sub_80247B4
	lsls r0, 24
	cmp r0, 0
	beq _0809BDB2
	movs r0, 0
	movs r1, 0x39
	movs r2, 0x1
	bl sub_80018D8
	movs r0, 0x46
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809BDB2:
	cmp r4, 0x3
	bne _0809BDCC
	bl sub_80247C0
	ldr r0, _0809BDC8
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809C1BC
	.align 2, 0
_0809BDC8: .4byte gUnknown_3001B64
_0809BDCC:
	cmp r4, 0x2
	beq _0809BDD2
	b _0809B784
_0809BDD2:
	bl sub_80247C0
	ldr r0, _0809BDE4
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B828
	.align 2, 0
_0809BDE4: .4byte gUnknown_3001B64
_0809BDE8:
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	lsrs r4, 31
	bl sub_809B294
	adds r0, r4, 0
	bl sub_8021B9C
	lsls r0, 24
	cmp r0, 0
	beq _0809BE20
	ldr r0, _0809BE18
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE1C
	b _0809C266
	.align 2, 0
_0809BE18: .4byte gUnknown_3001B64
_0809BE1C: .4byte gUnknown_8116218
_0809BE20:
	ldr r0, _0809BE2C
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
	.align 2, 0
_0809BE2C: .4byte gUnknown_3001B64
_0809BE30:
	ldr r0, [r6]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BE3C
	b _0809C266
	.align 2, 0
_0809BE3C: .4byte gUnknown_8116228
_0809BE40:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE4C
	b _0809C266
	.align 2, 0
_0809BE4C: .4byte gUnknown_8116238
_0809BE50:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BE5C
	b _0809C266
	.align 2, 0
_0809BE5C: .4byte gUnknown_8116248
_0809BE60:
	bl sub_809B294
	movs r0, 0x98
	lsls r0, 1
	bl sub_80314B4
	lsls r0, 24
	cmp r0, 0
	bne _0809BE84
	ldr r0, _0809BE80
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	b _0809B978
	.align 2, 0
_0809BE80: .4byte gUnknown_3001B64
_0809BE84:
	ldr r0, _0809BE94
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809BE98
	b _0809C266
	.align 2, 0
_0809BE94: .4byte gUnknown_3001B64
_0809BE98: .4byte gUnknown_8116258
_0809BE9C:
	movs r0, 0x4
	bl sub_80119D4
	ldr r0, _0809BEB0
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BEB4
	b _0809C266
	.align 2, 0
_0809BEB0: .4byte gUnknown_3001B64
_0809BEB4: .4byte gUnknown_8116268
_0809BEB8:
	movs r0, 0x4
	bl sub_80119D4
	ldr r0, _0809BECC
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809BED0
	b _0809C266
	.align 2, 0
_0809BECC: .4byte gUnknown_3001B64
_0809BED0: .4byte gUnknown_8116278
_0809BED4:
	mov r0, sp
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	beq _0809BF4E
	add r1, sp, 0x4
	add r2, sp, 0x8
	movs r0, 0x2
	bl sub_8001B88
	ldr r0, [sp, 0x8]
	cmp r0, 0x7
	bgt _0809BF4E
	add r4, sp, 0xC
_0809BEF2:
	lsls r1, r0, 24
	lsrs r1, 24
	mov r0, sp
	ldrb r2, [r0]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	beq _0809BF44
	ldr r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	movs r0, 0x2
	bl sub_8001BB4
	ldr r0, _0809BF40
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r2, r0, r1
	ldrh r1, [r4, 0x2]
	lsls r1, 16
	asrs r1, 16
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
	movs r3, 0x4
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _0809BF30
	adds r1, 0x2
_0809BF30:
	str r1, [r2]
	cmp r1, 0
	beq _0809BF38
	b _0809C392
_0809BF38:
	movs r0, 0x3
	str r0, [r2]
	b _0809C392
	.align 2, 0
_0809BF40: .4byte gUnknown_3001B64
_0809BF44:
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
	cmp r0, 0x7
	ble _0809BEF2
_0809BF4E:
	ldr r0, _0809BF6C
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	bl sub_8096BD0
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	b _0809C392
	.align 2, 0
_0809BF6C: .4byte gUnknown_3001B64
_0809BF70:
	mov r5, sp
	adds r5, 0x1
	adds r0, r5, 0
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	bne _0809BF82
	b _0809C392
_0809BF82:
	add r1, sp, 0x14
	add r2, sp, 0x18
	movs r0, 0x2
	bl sub_8001B88
	add r4, sp, 0x1C
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r1, 24
	ldrb r2, [r5]
	adds r0, r4, 0
	bl sub_8096AF8
	ldrb r0, [r4]
	cmp r0, 0
	bne _0809BFA4
	b _0809C392
_0809BFA4:
	ldr r0, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r5]
	bl sub_802DB28
	lsls r0, 24
	cmp r0, 0
	bne _0809BFB8
	b _0809C392
_0809BFB8:
	movs r0, 0
	movs r1, 0x19
	bl sub_8001658
	cmp r0, 0x63
	bgt _0809BFCE
	adds r2, r0, 0x1
	movs r0, 0
	movs r1, 0x19
	bl sub_80018D8
_0809BFCE:
	movs r0, 0
	movs r1, 0x39
	movs r2, 0x1
	bl sub_80018D8
	ldr r1, [sp, 0x14]
	ldr r2, [sp, 0x18]
	adds r2, 0x1
	movs r0, 0x2
	bl sub_8001BB4
	ldr r0, _0809BFF4
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809BFF8
	b _0809C266
	.align 2, 0
_0809BFF4: .4byte gUnknown_3001B64
_0809BFF8: .4byte gUnknown_8116288
_0809BFFC:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C036
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	lsrs r0, 24
	negs r4, r0
	orrs r4, r0
	asrs r4, 31
	movs r0, 0x4
	ands r4, r0
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C032
	bl _0809B784
_0809C032:
	ldr r0, [r6]
	b _0809B972
_0809C036:
	bl sub_802FE58
	cmp r0, 0x2
	beq _0809C05E
	cmp r0, 0x3
	beq _0809C046
	bl _0809B784
_0809C046:
	bl sub_802FED0
	ldr r1, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	lsls r0, 16
	asrs r0, 16
	str r0, [r1]
	bl sub_802FEE0
	b _0809C392
_0809C05E:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_802FEE0
	b _0809C392
_0809C072:
	movs r4, 0x1
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C082
	movs r4, 0x5
_0809C082:
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C0A8
	ldr r0, _0809C0A0
	ldr r0, [r0]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C0A4
	b _0809C266
	.align 2, 0
_0809C0A0: .4byte gUnknown_3001B64
_0809C0A4: .4byte gUnknown_8116298
_0809C0A8:
	ldr r0, _0809C0B4
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	b _0809B978
	.align 2, 0
_0809C0B4: .4byte gUnknown_3001B64
_0809C0B8:
	movs r4, 0x2
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C0C8
	movs r4, 0x6
_0809C0C8:
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C0F0
	ldr r0, _0809C0E8
	ldr r0, [r0]
	movs r3, 0x83
	lsls r3, 3
	adds r0, r3
	ldr r1, _0809C0EC
	b _0809C266
	.align 2, 0
_0809C0E8: .4byte gUnknown_3001B64
_0809C0EC: .4byte gUnknown_81162A8
_0809C0F0:
	ldr r0, _0809C0F8
	ldr r0, [r0]
	b _0809B972
	.align 2, 0
_0809C0F8: .4byte gUnknown_3001B64
_0809C0FC:
	movs r4, 0x3
	movs r0, 0x4
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0809C10C
	movs r4, 0x7
_0809C10C:
	bl sub_809B294
	adds r0, r4, 0
	bl sub_802FD14
	lsls r0, 24
	cmp r0, 0
	beq _0809C134
	ldr r0, _0809C12C
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C130
	b _0809C266
	.align 2, 0
_0809C12C: .4byte gUnknown_3001B64
_0809C130: .4byte gUnknown_81162B8
_0809C134:
	ldr r0, _0809C144
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C144: .4byte gUnknown_3001B64
_0809C148:
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C154
	b _0809C266
	.align 2, 0
_0809C154: .4byte gUnknown_81162C8
_0809C158:
	ldr r0, [r6]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C164
	b _0809C266
	.align 2, 0
_0809C164: .4byte gUnknown_81162D8
_0809C168:
	bl sub_809B294
	bl sub_803B050
	lsls r0, 24
	cmp r0, 0
	beq _0809C1A0
	ldr r4, _0809C194
	ldr r0, [r4]
	ldr r3, _0809C198
	adds r0, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_803B100
	ldr r0, [r4]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C19C
	b _0809C266
	.align 2, 0
_0809C194: .4byte gUnknown_3001B64
_0809C198: .4byte 0x000005a4
_0809C19C: .4byte gUnknown_81162E8
_0809C1A0:
	ldr r0, _0809C1B0
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C1B0: .4byte gUnknown_3001B64
_0809C1B4:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
_0809C1BC:
	movs r1, 0x1
	str r1, [r0]
	b _0809C392
_0809C1C2:
	bl sub_809B294
	b _0809C392
_0809C1C8:
	movs r0, 0x2
	bl sub_80252F0
	lsls r0, 24
	cmp r0, 0
	beq _0809C1EC
	ldr r0, _0809C1E4
	ldr r0, [r0]
	movs r2, 0x83
	lsls r2, 3
	adds r0, r2
	ldr r1, _0809C1E8
	b _0809C266
	.align 2, 0
_0809C1E4: .4byte gUnknown_3001B64
_0809C1E8: .4byte gUnknown_81162F8
_0809C1EC:
	ldr r0, _0809C200
	ldr r0, [r0]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	movs r1, 0x2
	negs r1, r1
	str r1, [r0]
	b _0809C392
	.align 2, 0
_0809C200: .4byte gUnknown_3001B64
_0809C204:
	ldr r1, [r6]
	ldr r2, _0809C230
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, 0x85
	lsls r3, 3
	adds r1, r3
	ldr r1, [r1]
	bl sub_809CCDC
	ldr r1, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	movs r0, 0x83
	lsls r0, 3
	adds r1, r0
	ldr r0, _0809C234
	str r0, [r1]
	bl _0809B784
	.align 2, 0
_0809C230: .4byte 0x00000424
_0809C234: .4byte gUnknown_8116308
_0809C238:
	ldr r0, [r6]
	movs r2, 0x85
	lsls r2, 3
	adds r1, r0, r2
	ldr r5, [r1]
	ldr r3, _0809C26C
	adds r0, r3
	ldrb r4, [r0]
	bl sub_809B294
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_801B60C
	lsls r0, 24
	cmp r0, 0
	beq _0809C274
	ldr r0, [r6]
	movs r1, 0x83
	lsls r1, 3
	adds r0, r1
	ldr r1, _0809C270
_0809C266:
	str r1, [r0]
	bl _0809B784
	.align 2, 0
_0809C26C: .4byte 0x00000424
_0809C270: .4byte gUnknown_8116318
_0809C274:
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	bl _0809B978
_0809C280:
	ldr r0, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C2B8
	bl sub_809B294
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	lsls r0, 24
	cmp r0, 0
	beq _0809C2B2
	bl _0809B784
_0809C2B2:
	ldr r0, [r6]
	bl _0809B972
_0809C2B8:
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x2
	beq _0809C320
	cmp r0, 0x3
	beq _0809C2CA
	bl _0809B784
_0809C2CA:
	bl sub_801A8AC
	adds r5, r0, 0
	ldr r0, _0809C304
	ldr r0, [r0]
	lsls r1, r5, 2
	adds r0, r1
	ldrb r4, [r0, 0x2]
	adds r0, r4, 0
	bl sub_8091570
	lsls r0, 24
	cmp r0, 0
	beq _0809C30C
	ldr r0, _0809C308
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090DC4
	adds r0, r5, 0
	bl sub_80911F8
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	movs r1, 0x1
	b _0809C318
	.align 2, 0
_0809C304: .4byte gUnknown_203B460
_0809C308: .4byte gUnknown_202DE58
_0809C30C:
	ldr r0, [r6]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
_0809C314:
	movs r1, 0x1
	negs r1, r1
_0809C318:
	str r1, [r0]
	bl sub_801A928
	b _0809C392
_0809C320:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	b _0809C314
_0809C32A:
	adds r4, r6, 0
	ldr r0, [r4]
	movs r2, 0x84
	lsls r2, 3
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809C36C
	bl sub_809B294
	ldr r1, [r4]
	ldr r3, _0809C368
	adds r0, r1, r3
	ldr r0, [r0]
	movs r2, 0x85
	lsls r2, 3
	adds r1, r2
	ldr r1, [r1]
	bl sub_8035444
	lsls r0, 24
	cmp r0, 0
	beq _0809C35C
	bl _0809B784
_0809C35C:
	ldr r0, [r4]
	movs r3, 0x86
	lsls r3, 3
	adds r0, r3
	bl _0809B978
	.align 2, 0
_0809C368: .4byte 0x00000424
_0809C36C:
	bl sub_8035574
	cmp r0, 0x3
	bls _0809C378
	bl _0809B784
_0809C378:
	cmp r0, 0x2
	bcs _0809C380
	bl _0809B784
_0809C380:
	ldr r0, [r6]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl sub_803565C
_0809C392:
	movs r0, 0
_0809C394:
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809B648

	thumb_func_start sub_809C39C
sub_809C39C:
	push {lr}
	bl sub_801D178
	ldr r1, _0809C3D4
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	str r0, [r1]
	cmp r0, 0x3
	bne _0809C3CC
	bl sub_801D1D4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	bl sub_8098D1C
_0809C3CC:
	bl sub_801D1E0
	pop {r0}
	bx r0
	.align 2, 0
_0809C3D4: .4byte gUnknown_3001B64
	thumb_func_end sub_809C39C

	thumb_func_start sub_809C3D8
sub_809C3D8:
	push {lr}
	bl sub_801D178
	ldr r1, _0809C410
	ldr r1, [r1]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r2
	str r0, [r1]
	cmp r0, 0x3
	bne _0809C408
	bl sub_801D1D4
	lsls r0, 24
	lsrs r0, 24
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	bl sub_8098D1C
_0809C408:
	bl sub_801D1E0
	pop {r0}
	bx r0
	.align 2, 0
_0809C410: .4byte gUnknown_3001B64
	thumb_func_end sub_809C3D8

	thumb_func_start sub_809C414
sub_809C414:
	push {lr}
	bl sub_802540C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0809C448
	ldr r0, _0809C444
	ldr r0, [r0]
	movs r2, 0x86
	lsls r2, 3
	adds r0, r2
	str r1, [r0]
	adds r0, r1, 0
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x1
	negs r2, r2
	movs r1, 0
	bl sub_8098D1C
	b _0809C458
	.align 2, 0
_0809C444: .4byte gUnknown_3001B64
_0809C448:
	ldr r0, _0809C460
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0809C458:
	bl sub_8025418
	pop {r0}
	bx r0
	.align 2, 0
_0809C460: .4byte gUnknown_3001B64
	thumb_func_end sub_809C414

	thumb_func_start sub_809C464
sub_809C464:
	push {lr}
	bl sub_803C850
	bl sub_8001064
	bl sub_809965C
	pop {r0}
	bx r0
	thumb_func_end sub_809C464

	thumb_func_start sub_809C478
sub_809C478:
	push {lr}
	sub sp, 0x8
	bl sub_80356A0
	cmp r0, 0x3
	bne _0809C492
	ldr r0, _0809C4AC
	bl sub_8011988
	bl InitFlash
	bl ClearFlashData
_0809C492:
	bl sub_8035758
	add r2, sp, 0x4
	movs r0, 0x3
	mov r1, sp
	bl sub_8001B88
	movs r0, 0
	bl sub_80993C0
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_0809C4AC: .4byte 0x00000313
	thumb_func_end sub_809C478

	thumb_func_start sub_809C4B0
sub_809C4B0:
	push {r4,r5,lr}
	movs r4, 0x1
	negs r4, r4
	ldr r5, _0809C4FC
	ldr r0, [r5]
	movs r2, 0x86
	lsls r2, 3
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, 0
	bne _0809C4DE
	bl sub_803B168
	lsls r0, 16
	ldr r1, [r5]
	ldr r3, _0809C500
	adds r2, r1, r3
	asrs r4, r0, 16
	lsrs r0, 16
	strh r0, [r2]
	movs r0, 0x86
	lsls r0, 3
	adds r1, r0
_0809C4DE:
	str r4, [r1]
	bl sub_803B1BC
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809C4F4
	adds r0, r4, 0
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809C4F4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C4FC: .4byte gUnknown_3001B64
_0809C500: .4byte 0x000005a4
	thumb_func_end sub_809C4B0

	thumb_func_start sub_809C504
sub_809C504:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80282DC
	adds r4, r0, 0
	cmp r4, 0x1
	bne _0809C530
	mov r0, sp
	ldrb r0, [r0]
	bl sub_809927C
	ldr r0, _0809C52C
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	str r4, [r0]
	b _0809C540
	.align 2, 0
_0809C52C: .4byte gUnknown_3001B64
_0809C530:
	ldr r0, _0809C54C
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0809C540:
	bl sub_80282FC
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C54C: .4byte gUnknown_3001B64
	thumb_func_end sub_809C504

	thumb_func_start sub_809C550
sub_809C550:
	push {r4,r5,lr}
	bl sub_802E90C
	adds r4, r0, 0
	movs r5, 0
	bl sub_802E918
	cmp r4, 0x2
	beq _0809C586
	cmp r4, 0x2
	bhi _0809C56C
	cmp r4, 0x1
	beq _0809C572
	b _0809C5AC
_0809C56C:
	cmp r4, 0x3
	beq _0809C59A
	b _0809C5AC
_0809C572:
	movs r0, 0x4
	movs r1, 0x1D
	movs r2, 0x3
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _0809C5AC
	movs r5, 0x1
	b _0809C5AC
_0809C586:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0x2
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _0809C5AC
	movs r5, 0x2
	b _0809C5AC
_0809C59A:
	movs r0, 0xB
	movs r1, 0x33
	movs r2, 0x8
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _0809C5AC
	movs r5, 0x3
_0809C5AC:
	ldr r0, _0809C5C0
	ldr r0, [r0]
	movs r1, 0x86
	lsls r1, 3
	adds r0, r1
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C5C0: .4byte gUnknown_3001B64
	thumb_func_end sub_809C550

	thumb_func_start sub_809C5C4
sub_809C5C4:
	push {r4,lr}
	ldr r4, _0809C610
	movs r0, 0x24
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	movs r2, 0
	str r2, [r0]
	str r2, [r0, 0x4]
	movs r3, 0
	strh r2, [r0, 0x8]
	strh r2, [r0, 0xA]
	strb r3, [r0, 0xD]
	ldr r0, [r4]
	strb r3, [r0, 0xE]
	ldr r1, [r4]
	str r2, [r1, 0x10]
	ldr r0, _0809C614
	strh r0, [r1, 0x14]
	movs r0, 0x23
	strh r0, [r1, 0x16]
	strb r3, [r1, 0x18]
	ldr r1, [r4]
	movs r0, 0x3F
	strb r0, [r1, 0x19]
	ldr r0, [r4]
	str r2, [r0, 0x1C]
	adds r0, 0x20
	strb r3, [r0]
	bl nullsub_107
	bl sub_809C63C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C610: .4byte gUnknown_3001B68
_0809C614: .4byte 0x0000ffff
	thumb_func_end sub_809C5C4

	thumb_func_start sub_809C618
sub_809C618:
	push {r4,lr}
	bl sub_809C63C
	bl nullsub_107
	bl nullsub_108
	ldr r4, _0809C638
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C638: .4byte gUnknown_3001B68
	thumb_func_end sub_809C618

	thumb_func_start sub_809C63C
sub_809C63C:
	push {lr}
	bl nullsub_108
	ldr r0, _0809C654
	ldr r0, [r0]
	movs r1, 0
	str r1, [r0, 0x1C]
	adds r0, 0x20
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0809C654: .4byte gUnknown_3001B68
	thumb_func_end sub_809C63C

	thumb_func_start sub_809C658
sub_809C658:
	push {lr}
	ldr r0, _0809C670
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r0, 0x5
	bhi _0809C6C8
	lsls r0, 2
	ldr r1, _0809C674
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C670: .4byte gUnknown_3001B68
_0809C674: .4byte _0809C678
	.align 2, 0
_0809C678:
	.4byte _0809C6C0
	.4byte _0809C6C0
	.4byte _0809C6AC
	.4byte _0809C690
	.4byte _0809C69E
	.4byte _0809C6B6
_0809C690:
	bl nullsub_111
	bl nullsub_112
	bl nullsub_113
	b _0809C6C8
_0809C69E:
	bl nullsub_114
	bl nullsub_115
	bl nullsub_116
	b _0809C6C8
_0809C6AC:
	bl nullsub_109
	bl nullsub_110
	b _0809C6C8
_0809C6B6:
	bl nullsub_107
	bl nullsub_108
	b _0809C6C8
_0809C6C0:
	bl nullsub_107
	bl nullsub_108
_0809C6C8:
	pop {r0}
	bx r0
	thumb_func_end sub_809C658

	thumb_func_start sub_809C6CC
sub_809C6CC:
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, _0809C6E8
	ldr r1, [r0]
	ldrh r0, [r1, 0x8]
	cmp r0, r2
	beq _0809C6E2
	movs r0, 0
	strh r2, [r1, 0x8]
	strb r0, [r1, 0xE]
_0809C6E2:
	pop {r0}
	bx r0
	.align 2, 0
_0809C6E8: .4byte gUnknown_3001B68
	thumb_func_end sub_809C6CC

	thumb_func_start sub_809C6EC
sub_809C6EC:
	push {lr}
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	bne _0809C718
	ldr r0, _0809C70C
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	bne _0809C710
	movs r0, 0x4
	bl sub_809C6CC
	b _0809C71E
	.align 2, 0
_0809C70C: .4byte gUnknown_203B46C
_0809C710:
	movs r0, 0x3
	bl sub_809C6CC
	b _0809C71E
_0809C718:
	movs r0, 0x5
	bl sub_809C6CC
_0809C71E:
	pop {r0}
	bx r0
	thumb_func_end sub_809C6EC

	thumb_func_start sub_809C724
sub_809C724:
	ldr r0, _0809C72C
	ldr r0, [r0]
	ldrh r0, [r0, 0x8]
	bx lr
	.align 2, 0
_0809C72C: .4byte gUnknown_3001B68
	thumb_func_end sub_809C724

	thumb_func_start sub_809C730
sub_809C730:
	push {lr}
	bl sub_809C740
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_809C730

	thumb_func_start sub_809C740
sub_809C740:
	push {lr}
	ldr r0, _0809C750
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _0809C754
	movs r0, 0
	b _0809C756
	.align 2, 0
_0809C750: .4byte gUnknown_3001B68
_0809C754:
	movs r0, 0x1
_0809C756:
	pop {r1}
	bx r1
	thumb_func_end sub_809C740

	thumb_func_start nullsub_104
nullsub_104:
	bx lr
	thumb_func_end nullsub_104

	thumb_func_start sub_809C760
sub_809C760:
	ldr r0, _0809C76C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xE]
	bx lr
	.align 2, 0
_0809C76C: .4byte gUnknown_3001B68
	thumb_func_end sub_809C760

	thumb_func_start sub_809C770
sub_809C770:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r4, _0809C790
	ldr r1, [r4]
	ldrb r0, [r1, 0xE]
	cmp r0, 0
	beq _0809C794
	movs r0, 0
	strb r0, [r1, 0xE]
	b _0809CA10
	.align 2, 0
_0809C790: .4byte gUnknown_3001B68
_0809C794:
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	bne _0809C79E
	bl sub_809C6EC
_0809C79E:
	ldr r0, [r4]
	ldrb r5, [r0, 0x18]
	ldrb r7, [r0, 0x19]
	cmp r6, 0x26
	bls _0809C7AA
	b _0809C8C8
_0809C7AA:
	lsls r0, r6, 2
	ldr r1, _0809C7B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C7B4: .4byte _0809C7B8
	.align 2, 0
_0809C7B8:
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C854
	.4byte _0809C868
	.4byte _0809C868
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C8C8
	.4byte _0809C86E
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
_0809C854:
	mov r0, r8
	bl sub_8002658
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0809C864
	b _0809CA10
_0809C864:
	movs r4, 0x1
	b _0809C988
_0809C868:
	movs r4, 0x1
	movs r5, 0
	b _0809C988
_0809C86E:
	mov r0, r8
	subs r0, 0xA4
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xD
	bls _0809C87C
	b _0809CA10
_0809C87C:
	lsls r0, 2
	ldr r1, _0809C888
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C888: .4byte _0809C88C
	.align 2, 0
_0809C88C:
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809CA10
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
	.4byte _0809C8C4
_0809C8C4:
	movs r4, 0
	b _0809C988
_0809C8C8:
	adds r0, r6, 0
	subs r0, 0xC
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x16
	bhi _0809C968
	lsls r0, 2
	ldr r1, _0809C8E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C8E0: .4byte _0809C8E4
	.align 2, 0
_0809C8E4:
	.4byte _0809C968
	.4byte _0809C940
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C968
	.4byte _0809C944
	.4byte _0809C944
	.4byte _0809C948
	.4byte _0809C948
	.4byte _0809C94C
	.4byte _0809C968
	.4byte _0809C950
	.4byte _0809C950
	.4byte _0809C954
	.4byte _0809C954
	.4byte _0809C958
	.4byte _0809C958
	.4byte _0809C95C
	.4byte _0809C95C
	.4byte _0809C960
	.4byte _0809C960
	.4byte _0809C964
_0809C940:
	movs r1, 0
	b _0809C974
_0809C944:
	movs r1, 0x7
	b _0809C974
_0809C948:
	movs r1, 0x9
	b _0809C974
_0809C94C:
	movs r1, 0xA
	b _0809C974
_0809C950:
	movs r1, 0xB
	b _0809C974
_0809C954:
	movs r1, 0xD
	b _0809C974
_0809C958:
	movs r1, 0xF
	b _0809C974
_0809C95C:
	movs r1, 0x11
	b _0809C974
_0809C960:
	movs r1, 0x13
	b _0809C974
_0809C964:
	movs r1, 0x20
	b _0809C974
_0809C968:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r1, r0, 16
_0809C974:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809CA10
	adds r0, r1, 0
	bl sub_80A2740
	lsls r0, 24
	lsrs r7, r0, 24
	movs r4, 0x2
_0809C988:
	ldr r0, _0809C99C
	ldr r2, [r0]
	ldr r1, [r2, 0x10]
	adds r3, r0, 0
	cmp r1, r4
	beq _0809C9A0
	movs r0, 0x2
	str r0, [r2]
	b _0809C9DE
	.align 2, 0
_0809C99C: .4byte gUnknown_3001B68
_0809C9A0:
	cmp r4, 0x1
	bne _0809C9CC
	ldrb r0, [r2, 0x18]
	cmp r5, r0
	bne _0809C9B2
	movs r1, 0x14
	ldrsh r0, [r2, r1]
	cmp r0, r8
	beq _0809C9BC
_0809C9B2:
	strb r4, [r2, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r4, [r0]
	b _0809C9E8
_0809C9BC:
	cmp r5, 0
	bne _0809C9E8
	movs r1, 0x16
	ldrsh r0, [r2, r1]
	cmp r0, r6
	beq _0809C9E8
	strb r4, [r2, 0xC]
	b _0809C9E8
_0809C9CC:
	cmp r4, 0x2
	bne _0809C9E8
	ldrb r0, [r2, 0x19]
	cmp r7, r0
	bne _0809C9DE
	movs r1, 0x16
	ldrsh r0, [r2, r1]
	cmp r0, r6
	beq _0809C9E8
_0809C9DE:
	movs r1, 0x1
	strb r1, [r2, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r1, [r0]
_0809C9E8:
	ldr r1, [r3]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0809CA10
	str r4, [r1, 0x10]
	movs r2, 0
	mov r0, r8
	strh r0, [r1, 0x14]
	strh r6, [r1, 0x16]
	strb r5, [r1, 0x18]
	ldr r0, [r3]
	strb r7, [r0, 0x19]
	ldr r1, [r3]
	ldrh r0, [r1, 0x8]
	cmp r0, 0x4
	beq _0809CA10
	strb r2, [r1, 0xC]
	ldr r0, [r3]
	adds r0, 0x20
	strb r2, [r0]
_0809CA10:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809C770

	thumb_func_start nullsub_105
nullsub_105:
	bx lr
	thumb_func_end nullsub_105

	thumb_func_start sub_809CA20
sub_809CA20:
	push {lr}
	ldr r1, _0809CA74
	ldr r2, [r1]
	ldr r0, [r2]
	cmp r0, 0
	beq _0809CA38
	movs r0, 0
	str r0, [r2]
	movs r0, 0x1F
	str r0, [r2, 0x4]
	movs r0, 0x1
	strb r0, [r2, 0xC]
_0809CA38:
	ldr r1, [r1]
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0809CAE8
	ldrh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bne _0809CA5E
	ldr r2, [r1, 0x10]
	cmp r2, 0
	bne _0809CA5E
	movs r0, 0x2
	strh r0, [r1, 0xA]
	str r2, [r1, 0x1C]
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
_0809CA5E:
	ldr r0, _0809CA74
	ldr r0, [r0]
	ldrh r0, [r0, 0xA]
	cmp r0, 0x5
	bhi _0809CADA
	lsls r0, 2
	ldr r1, _0809CA78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CA74: .4byte gUnknown_3001B68
_0809CA78: .4byte _0809CA7C
	.align 2, 0
_0809CA7C:
	.4byte _0809CAD2
	.4byte _0809CAD2
	.4byte _0809CABE
	.4byte _0809CA94
	.4byte _0809CAB0
	.4byte _0809CAC8
_0809CA94:
	bl nullsub_111
	bl nullsub_113
	bl nullsub_112
	ldr r0, _0809CAAC
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	b _0809CADA
	.align 2, 0
_0809CAAC: .4byte gUnknown_3001B68
_0809CAB0:
	bl nullsub_114
	bl nullsub_115
	bl nullsub_116
	b _0809CADA
_0809CABE:
	bl nullsub_109
	bl nullsub_110
	b _0809CADA
_0809CAC8:
	bl nullsub_107
	bl nullsub_108
	b _0809CADA
_0809CAD2:
	bl nullsub_107
	bl nullsub_108
_0809CADA:
	ldr r0, _0809CAE4
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0xC]
	b _0809CB1E
	.align 2, 0
_0809CAE4: .4byte gUnknown_3001B68
_0809CAE8:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x5
	bhi _0809CB1E
	lsls r0, 2
	ldr r1, _0809CAF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CAF8: .4byte _0809CAFC
	.align 2, 0
_0809CAFC:
	.4byte _0809CB1E
	.4byte _0809CB1E
	.4byte _0809CB1E
	.4byte _0809CB14
	.4byte _0809CB1A
	.4byte _0809CB1E
_0809CB14:
	bl nullsub_113
	b _0809CB1E
_0809CB1A:
	bl nullsub_116
_0809CB1E:
	pop {r0}
	bx r0
	thumb_func_end sub_809CA20

	thumb_func_start nullsub_106
nullsub_106:
	bx lr
	thumb_func_end nullsub_106

	thumb_func_start nullsub_107
nullsub_107:
	bx lr
	thumb_func_end nullsub_107

	thumb_func_start nullsub_108
nullsub_108:
	bx lr
	thumb_func_end nullsub_108

	thumb_func_start nullsub_109
nullsub_109:
	bx lr
	thumb_func_end nullsub_109

	thumb_func_start nullsub_110
nullsub_110:
	bx lr
	thumb_func_end nullsub_110

	thumb_func_start nullsub_111
nullsub_111:
	bx lr
	thumb_func_end nullsub_111

	thumb_func_start nullsub_112
nullsub_112:
	bx lr
	thumb_func_end nullsub_112

	thumb_func_start nullsub_113
nullsub_113:
	bx lr
	thumb_func_end nullsub_113

	thumb_func_start nullsub_114
nullsub_114:
	bx lr
	thumb_func_end nullsub_114

	thumb_func_start nullsub_115
nullsub_115:
	bx lr
	thumb_func_end nullsub_115

	thumb_func_start nullsub_116
nullsub_116:
	bx lr
	thumb_func_end nullsub_116

	thumb_func_start sub_809CB50
sub_809CB50:
	push {r4,lr}
	ldr r4, _0809CB70
	movs r0, 0xC
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x4]
	movs r1, 0
	str r1, [r0, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809CB70: .4byte gUnknown_20399E0
	thumb_func_end sub_809CB50

	thumb_func_start sub_809CB74
sub_809CB74:
	push {r4,lr}
	ldr r4, _0809CB88
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809CB88: .4byte gUnknown_20399E0
	thumb_func_end sub_809CB74

	thumb_func_start sub_809CB8C
sub_809CB8C:
	push {lr}
	movs r0, 0
	movs r1, 0x3B
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x3D
	bl sub_80015C0
	pop {r0}
	bx r0
	thumb_func_end sub_809CB8C

	thumb_func_start sub_809CBA4
sub_809CBA4:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091130
	cmp r0, 0
	bge _0809CBB6
	movs r0, 0
	b _0809CBB8
_0809CBB6:
	movs r0, 0x1
_0809CBB8:
	pop {r1}
	bx r1
	thumb_func_end sub_809CBA4

	thumb_func_start sub_809CBBC
sub_809CBBC:
	push {r4-r7,lr}
	sub sp, 0x54
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	ldrb r1, [r4]
	cmp r1, 0x69
	bne _0809CC20
	ldr r1, _0809CC0C
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldr r0, _0809CC10
	ldr r0, [r0]
	movs r3, 0xD2
	lsls r3, 4
	adds r0, r3
	ldr r3, [r0]
	mov r0, sp
	bl sub_800D158
	ldr r0, _0809CC14
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r2, r0, r1
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	ldr r0, [r2]
	adds r1, r0, r1
	ldr r0, _0809CC18
	cmp r1, r0
	ble _0809CC1C
	cmp r6, 0
	beq _0809CC4E
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r6, 0
	b _0809CC4A
	.align 2, 0
_0809CC0C: .4byte gUnknown_81163E4
_0809CC10: .4byte gItemParametersFile + 4
_0809CC14: .4byte gUnknown_203B460
_0809CC18: .4byte 0x0001869f
_0809CC1C:
	str r1, [r2]
	b _0809CC5E
_0809CC20:
	ldrb r0, [r4, 0x2]
	lsls r1, 16
	lsls r0, 8
	orrs r0, r1
	str r0, [sp, 0x50]
	add r4, sp, 0x50
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0
	bl sub_8090E14
	bl sub_8090A34
	cmp r0, 0x13
	ble _0809CC52
	cmp r5, 0
	beq _0809CC4E
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r5, 0
_0809CC4A:
	bl sub_809AE90
_0809CC4E:
	movs r0, 0
	b _0809CC82
_0809CC52:
	ldrb r0, [r4, 0x2]
	movs r1, 0
	bl sub_809124C
	bl sub_80910B4
_0809CC5E:
	cmp r7, 0
	beq _0809CC80
	ldr r0, _0809CC8C
	mov r1, sp
	bl strcpy
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	adds r2, r7, 0
	bl sub_809AE90
	movs r1, 0x80
	lsls r1, 1
	movs r0, 0xCB
	bl sub_8011974
_0809CC80:
	movs r0, 0x1
_0809CC82:
	add sp, 0x54
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809CC8C: .4byte gUnknown_202DE58
	thumb_func_end sub_809CBBC

	thumb_func_start sub_809CC90
sub_809CC90:
	push {lr}
	lsls r0, 2
	ldr r1, _0809CCBC
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0x69
	bne _0809CCC8
	ldr r0, _0809CCC0
	ldr r0, [r0]
	movs r2, 0x98
	lsls r2, 2
	adds r0, r2
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	ldr r0, [r0]
	adds r0, r1
	ldr r1, _0809CCC4
	cmp r0, r1
	ble _0809CCD4
	movs r0, 0x2
	b _0809CCD6
	.align 2, 0
_0809CCBC: .4byte gUnknown_81163BC
_0809CCC0: .4byte gUnknown_203B460
_0809CCC4: .4byte 0x0001869f
_0809CCC8:
	bl sub_8090A34
	cmp r0, 0x13
	ble _0809CCD4
	movs r0, 0x2
	b _0809CCD6
_0809CCD4:
	movs r0, 0x1
_0809CCD6:
	pop {r1}
	bx r1
	thumb_func_end sub_809CC90

	thumb_func_start sub_809CCDC
sub_809CCDC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r1, r6, 2
	ldr r0, _0809CD20
	adds r5, r1, r0
	ldr r0, _0809CD24
	ldr r1, [r0]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x4]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r0, 0x2
	cmp r4, 0x63
	bgt _0809CD04
	movs r0, 0
	cmp r4, 0x1
	ble _0809CD04
	movs r0, 0x1
_0809CD04:
	ldr r1, _0809CD28
	ldr r2, _0809CD2C
	ldr r3, _0809CD30
	lsls r0, 2
	adds r0, r3
	ldr r3, [r0]
	adds r0, r5, 0
	bl sub_809CBBC
	lsls r0, 24
	cmp r0, 0
	bne _0809CD34
	movs r0, 0x2
	b _0809CD3E
	.align 2, 0
_0809CD20: .4byte gUnknown_81163BC
_0809CD24: .4byte gUnknown_20399E0
_0809CD28: .4byte gUnknown_81163F0
_0809CD2C: .4byte gUnknown_811642C
_0809CD30: .4byte gUnknown_203B4A0
_0809CD34:
	ldr r0, _0809CD44
	ldr r0, [r0]
	str r6, [r0, 0x4]
	str r4, [r0, 0x8]
	movs r0, 0x1
_0809CD3E:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809CD44: .4byte gUnknown_20399E0
	thumb_func_end sub_809CCDC

	thumb_func_start sub_809CD48
sub_809CD48:
	push {lr}
	bl sub_809A750
	lsls r0, 24
	cmp r0, 0
	bne _0809CD58
	movs r0, 0x3
	b _0809CD5A
_0809CD58:
	movs r0, 0
_0809CD5A:
	pop {r1}
	bx r1
	thumb_func_end sub_809CD48

	thumb_func_start nullsub_117
nullsub_117:
	bx lr
	thumb_func_end nullsub_117

	thumb_func_start nullsub_118
nullsub_118:
	bx lr
	thumb_func_end nullsub_118

	thumb_func_start sub_809CD68
sub_809CD68:
	movs r2, 0
	str r2, [r0]
	str r2, [r0, 0x4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	str r2, [r0, 0x14]
	str r2, [r0, 0x8]
	strb r2, [r0, 0x18]
	bx lr
	thumb_func_end sub_809CD68

	thumb_func_start sub_809CD7C
sub_809CD7C:
	movs r2, 0
	str r2, [r0]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x10]
	str r2, [r0, 0x14]
	str r2, [r0, 0x8]
	bx lr
	thumb_func_end sub_809CD7C

	thumb_func_start sub_809CD8C
sub_809CD8C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0x5
	bne _0809CD9E
	bl sub_809CD68
	str r4, [r5]
	b _0809CDB0
_0809CD9E:
	ldr r0, [r5, 0x4]
	cmp r0, r4
	beq _0809CDB0
	str r4, [r5, 0x4]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x10]
	movs r0, 0
	str r0, [r5, 0x14]
_0809CDB0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_809CD8C

	thumb_func_start sub_809CDB8
sub_809CDB8:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _0809CDC4
	ldr r0, [r1]
_0809CDC4:
	pop {r1}
	bx r1
	thumb_func_end sub_809CDB8

	thumb_func_start sub_809CDC8
sub_809CDC8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r1, [sp, 0x24]
	movs r0, 0x1
	negs r0, r0
	str r0, [r3]
	ldr r0, [r4]
	cmp r0, 0x1
	beq _0809CDEA
	cmp r0, 0x2
	beq _0809CDFE
	b _0809CE12
_0809CDEA:
	movs r0, 0x80
	lsls r0, 6
	ands r1, r0
	cmp r1, 0
	beq _0809CE12
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x2
	b _0809CE10
_0809CDFE:
	movs r0, 0x80
	lsls r0, 6
	ands r1, r0
	cmp r1, 0
	bne _0809CE12
	adds r0, r4, 0
	bl sub_809CD68
	movs r0, 0x1
_0809CE10:
	str r0, [r4]
_0809CE12:
	ldr r0, [r4, 0x4]
	mov r8, r0
	cmp r0, 0
	bne _0809CE1E
	ldr r1, [r4]
	mov r8, r1
_0809CE1E:
	mov r0, r8
	subs r0, 0x1
	cmp r0, 0x6
	bls _0809CE28
	b _0809CFCC
_0809CE28:
	lsls r0, 2
	ldr r1, _0809CE34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809CE34: .4byte _0809CE38
	.align 2, 0
_0809CE38:
	.4byte _0809CE54
	.4byte _0809CF74
	.4byte _0809CFCC
	.4byte _0809CFCC
	.4byte _0809CECC
	.4byte _0809CF5C
	.4byte _0809CF5C
_0809CE54:
	ldr r0, _0809CE70
	ldrh r2, [r0]
	ldrh r1, [r0, 0x2]
	movs r0, 0xF0
	ands r0, r2
	cmp r0, 0
	beq _0809CE74
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _0809CEA4
	movs r0, 0
	b _0809CEA8
	.align 2, 0
_0809CE70: .4byte gUnknown_20255F0
_0809CE74:
	movs r3, 0x2
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _0809CE82
	movs r0, 0x14
	b _0809CEA8
_0809CE82:
	ldr r0, [r4, 0x10]
	cmp r0, 0x1
	ble _0809CEA4
	subs r0, 0x1
	str r0, [r4, 0x10]
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	bne _0809CEAA
	movs r0, 0x13
	str r0, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strb r0, [r7]
	movs r0, 0x5
	b _0809CFDA
_0809CEA4:
	movs r0, 0x1
	negs r0, r0
_0809CEA8:
	str r0, [r4, 0x10]
_0809CEAA:
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0809CEB6
	movs r0, 0xA
	b _0809CEC2
_0809CEB6:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _0809CEC0
	movs r0, 0x8
	b _0809CEC2
_0809CEC0:
	movs r0, 0x7
_0809CEC2:
	str r0, [r6]
	adds r0, r2, 0
	bl sub_809CFE8
	b _0809CF4E
_0809CECC:
	mov r0, sp
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	beq _0809CFCC
	ldr r0, _0809CEEC
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	bne _0809CEF0
	movs r0, 0x4
	bl sub_809C6CC
	b _0809CEF6
	.align 2, 0
_0809CEEC: .4byte gUnknown_203B46C
_0809CEF0:
	movs r0, 0x3
	bl sub_809C6CC
_0809CEF6:
	bl nullsub_104
	adds r0, r4, 0
	bl sub_809CD7C
	movs r5, 0x1
	str r5, [r4]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0809CF1E
	cmp r0, 0x2
	bgt _0809CF14
	cmp r0, 0x1
	beq _0809CF2A
	b _0809CF54
_0809CF14:
	cmp r0, 0x3
	beq _0809CF2A
	cmp r0, 0x4
	beq _0809CF3C
	b _0809CF54
_0809CF1E:
	movs r0, 0x4
	str r0, [r4]
	movs r0, 0x1E
	bl sub_8098D80
	b _0809CF46
_0809CF2A:
	movs r0, 0x4
	str r0, [r4]
	str r5, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strb r0, [r7]
	movs r0, 0x4
	b _0809CFDA
_0809CF3C:
	str r0, [r4]
	movs r0, 0x45
	movs r1, 0
	bl GroundMap_ExecuteEvent
_0809CF46:
	str r5, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CF4E:
	strb r0, [r7]
	ldr r0, [r4]
	b _0809CFDA
_0809CF54:
	movs r0, 0x2
	bl sub_809D9B8
	b _0809CFCC
_0809CF5C:
	add r0, sp, 0x4
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	beq _0809CFCC
	adds r0, r4, 0
	bl sub_809CD7C
	movs r0, 0x1
	str r0, [r4]
	b _0809CFDA
_0809CF74:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	ble _0809CF86
	subs r0, 0x1
	str r0, [r4, 0x8]
	movs r0, 0x9
	str r0, [r6]
	ldrb r0, [r4, 0xC]
	b _0809CFD6
_0809CF86:
	ldr r0, _0809CFA0
	ldrh r1, [r0]
	movs r0, 0x9
	str r0, [r6]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _0809CFA4
	movs r0, 0x4
	b _0809CFB6
	.align 2, 0
_0809CFA0: .4byte gUnknown_20255F0
_0809CFA4:
	movs r0, 0x80
	ands r1, r0
	cmp r1, 0
	beq _0809CFB0
	strb r2, [r7]
	b _0809CFB8
_0809CFB0:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CFB6:
	strb r0, [r7]
_0809CFB8:
	ldrb r0, [r7]
	strb r0, [r4, 0xC]
	lsls r0, 24
	movs r1, 0xFF
	lsls r1, 24
	cmp r0, r1
	beq _0809CFD8
	movs r0, 0x20
	str r0, [r4, 0x8]
	b _0809CFD8
_0809CFCC:
	movs r0, 0
	str r0, [r6]
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
_0809CFD6:
	strb r0, [r7]
_0809CFD8:
	mov r0, r8
_0809CFDA:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_809CDC8

	thumb_func_start sub_809CFE8
sub_809CFE8:
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0809D014
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0809D004
	movs r0, 0x3
	b _0809D052
_0809D004:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0809D010
	movs r0, 0x5
	b _0809D052
_0809D010:
	movs r0, 0x4
	b _0809D052
_0809D014:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809D038
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0809D028
	movs r0, 0x1
	b _0809D052
_0809D028:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0809D034
	movs r0, 0x7
	b _0809D052
_0809D034:
	movs r0, 0
	b _0809D052
_0809D038:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0809D044
	movs r0, 0x2
	b _0809D052
_0809D044:
	movs r0, 0x20
	ands r2, r0
	cmp r2, 0
	bne _0809D050
	subs r0, 0x21
	b _0809D052
_0809D050:
	movs r0, 0x6
_0809D052:
	pop {r1}
	bx r1
	thumb_func_end sub_809CFE8

	thumb_func_start sub_809D058
sub_809D058:
	push {lr}
	ldr r1, [r0, 0x4]
	cmp r1, 0x3F
	bgt _0809D076
	ldr r0, [r0]
	cmp r0, 0x67
	bgt _0809D06A
	movs r0, 0x5
	b _0809D0A6
_0809D06A:
	cmp r0, 0x88
	ble _0809D072
	movs r0, 0x3
	b _0809D0A6
_0809D072:
	movs r0, 0x4
	b _0809D0A6
_0809D076:
	cmp r1, 0x60
	ble _0809D090
	ldr r0, [r0]
	cmp r0, 0x67
	bgt _0809D084
	movs r0, 0x7
	b _0809D0A6
_0809D084:
	cmp r0, 0x88
	ble _0809D08C
	movs r0, 0x1
	b _0809D0A6
_0809D08C:
	movs r0, 0
	b _0809D0A6
_0809D090:
	ldr r0, [r0]
	cmp r0, 0x67
	bgt _0809D09A
	movs r0, 0x6
	b _0809D0A6
_0809D09A:
	cmp r0, 0x88
	bgt _0809D0A4
	movs r0, 0x1
	negs r0, r0
	b _0809D0A6
_0809D0A4:
	movs r0, 0x2
_0809D0A6:
	pop {r1}
	bx r1
	thumb_func_end sub_809D058

	thumb_func_start sub_809D0AC
sub_809D0AC:
	push {lr}
	bl sub_809D0BC
	pop {r0}
	bx r0
	thumb_func_end sub_809D0AC

	thumb_func_start nullsub_119
nullsub_119:
	bx lr
	thumb_func_end nullsub_119

	thumb_func_start sub_809D0BC
sub_809D0BC:
	push {r4,r5,lr}
	ldr r5, _0809D0F8
	ldr r1, _0809D0FC
	ldr r2, [r1]
	ldr r3, [r1, 0x4]
	str r2, [r5, 0x3C]
	str r3, [r5, 0x40]
	adds r0, r5, 0
	adds r0, 0x44
	movs r4, 0
	strb r4, [r0]
	movs r0, 0
	bl sub_809D158
	str r4, [r5, 0x8]
	str r4, [r5, 0xC]
	str r4, [r5, 0x10]
	movs r0, 0x1
	negs r0, r0
	str r0, [r5, 0x4]
	str r4, [r5, 0x24]
	str r4, [r5, 0x28]
	str r4, [r5, 0x2C]
	str r4, [r5, 0x30]
	str r4, [r5, 0x34]
	str r4, [r5, 0x38]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809D0F8: .4byte gUnknown_20399E8
_0809D0FC: .4byte gUnknown_8116478
	thumb_func_end sub_809D0BC

	thumb_func_start sub_809D100
sub_809D100:
	push {lr}
	adds r2, r0, 0
	ldr r1, _0809D120
	ldr r0, [r1, 0x24]
	cmp r0, r2
	beq _0809D11A
	str r2, [r1, 0x24]
	movs r0, 0
	str r0, [r1, 0x28]
	str r0, [r1, 0x2C]
	str r0, [r1, 0x30]
	str r0, [r1, 0x34]
	str r0, [r1, 0x38]
_0809D11A:
	pop {r0}
	bx r0
	.align 2, 0
_0809D120: .4byte gUnknown_20399E8
	thumb_func_end sub_809D100

	thumb_func_start sub_809D124
sub_809D124:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, _0809D144
	ldr r0, [r3, 0x24]
	cmp r0, r4
	beq _0809D13A
	str r4, [r3, 0x24]
	movs r0, 0
	str r0, [r3, 0x30]
	str r0, [r3, 0x34]
	str r0, [r3, 0x38]
_0809D13A:
	str r1, [r3, 0x28]
	str r2, [r3, 0x2C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D144: .4byte gUnknown_20399E8
	thumb_func_end sub_809D124

	thumb_func_start sub_809D148
sub_809D148:
	ldr r1, _0809D154
	str r0, [r1]
	movs r0, 0
	str r0, [r1, 0x8]
	bx lr
	.align 2, 0
_0809D154: .4byte gUnknown_20399E8
	thumb_func_end sub_809D148

	thumb_func_start sub_809D158
sub_809D158:
	ldr r2, _0809D16C
	str r0, [r2]
	movs r0, 0
	str r0, [r2, 0x8]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r2, 0x1C]
	str r1, [r2, 0x20]
	bx lr
	.align 2, 0
_0809D16C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D158

	thumb_func_start sub_809D170
sub_809D170:
	ldr r2, _0809D17C
	str r0, [r2]
	movs r0, 0
	str r0, [r2, 0x8]
	str r1, [r2, 0x4]
	bx lr
	.align 2, 0
_0809D17C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D170

	thumb_func_start sub_809D180
sub_809D180:
	ldr r2, _0809D18C
	str r0, [r2]
	movs r0, 0x1
	str r0, [r2, 0x8]
	str r1, [r2, 0xC]
	bx lr
	.align 2, 0
_0809D18C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D180

	thumb_func_start sub_809D190
sub_809D190:
	ldr r3, _0809D1A4
	str r0, [r3]
	movs r0, 0x1
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r3, 0x14]
	str r1, [r3, 0x18]
	bx lr
	.align 2, 0
_0809D1A4: .4byte gUnknown_20399E8
	thumb_func_end sub_809D190

	thumb_func_start sub_809D1A8
sub_809D1A8:
	ldr r3, _0809D1B8
	str r0, [r3]
	movs r0, 0x1
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	str r1, [r3, 0x4]
	bx lr
	.align 2, 0
_0809D1B8: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1A8

	thumb_func_start sub_809D1BC
sub_809D1BC:
	ldr r2, _0809D1C8
	str r0, [r2]
	movs r0, 0x2
	str r0, [r2, 0x8]
	str r1, [r2, 0x10]
	bx lr
	.align 2, 0
_0809D1C8: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1BC

	thumb_func_start sub_809D1CC
sub_809D1CC:
	ldr r3, _0809D1E0
	str r0, [r3]
	movs r0, 0x2
	str r0, [r3, 0x8]
	str r2, [r3, 0x10]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r3, 0x14]
	str r1, [r3, 0x18]
	bx lr
	.align 2, 0
_0809D1E0: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1CC

	thumb_func_start sub_809D1E4
sub_809D1E4:
	ldr r3, _0809D1F4
	str r0, [r3]
	movs r0, 0x2
	str r0, [r3, 0x8]
	str r2, [r3, 0x10]
	str r1, [r3, 0x4]
	bx lr
	.align 2, 0
_0809D1F4: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1E4

	thumb_func_start sub_809D1F8
sub_809D1F8:
	ldr r2, _0809D204
	str r0, [r2]
	movs r0, 0x3
	str r0, [r2, 0x8]
	str r1, [r2, 0xC]
	bx lr
	.align 2, 0
_0809D204: .4byte gUnknown_20399E8
	thumb_func_end sub_809D1F8

	thumb_func_start sub_809D208
sub_809D208:
	ldr r3, _0809D21C
	str r0, [r3]
	movs r0, 0x3
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [r3, 0x14]
	str r1, [r3, 0x18]
	bx lr
	.align 2, 0
_0809D21C: .4byte gUnknown_20399E8
	thumb_func_end sub_809D208

	thumb_func_start sub_809D220
sub_809D220:
	ldr r3, _0809D230
	str r0, [r3]
	movs r0, 0x3
	str r0, [r3, 0x8]
	str r2, [r3, 0xC]
	str r1, [r3, 0x4]
	bx lr
	.align 2, 0
_0809D230: .4byte gUnknown_20399E8
	thumb_func_end sub_809D220

	thumb_func_start sub_809D234
sub_809D234:
	push {lr}
	ldr r0, _0809D244
	ldr r0, [r0, 0x8]
	cmp r0, 0
	beq _0809D240
	movs r0, 0x1
_0809D240:
	pop {r1}
	bx r1
	.align 2, 0
_0809D244: .4byte gUnknown_20399E8
	thumb_func_end sub_809D234

	thumb_func_start sub_809D248
sub_809D248:
	ldr r3, _0809D258
	ldr r1, [r3, 0x3C]
	ldr r2, [r3, 0x40]
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r3, 0x44
	ldrb r0, [r3]
	bx lr
	.align 2, 0
_0809D258: .4byte gUnknown_20399E8
	thumb_func_end sub_809D248

	thumb_func_start sub_809D25C
sub_809D25C:
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r4, _0809D274
	ldr r0, [r4]
	cmp r0, 0x2
	beq _0809D28C
	cmp r0, 0x2
	bhi _0809D278
	cmp r0, 0x1
	beq _0809D27E
	b _0809D2B2
	.align 2, 0
_0809D274: .4byte gUnknown_20399E8
_0809D278:
	cmp r0, 0x3
	beq _0809D29A
	b _0809D2B2
_0809D27E:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80A8FD8
	b _0809D2A6
_0809D28C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80AC448
	b _0809D2A6
_0809D29A:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r4, 0
	adds r1, 0x1C
	bl sub_80AD360
_0809D2A6:
	lsls r0, 16
	ldr r1, _0809D2C4
	cmp r0, r1
	bne _0809D2B2
	movs r0, 0
	str r0, [r4]
_0809D2B2:
	ldr r4, _0809D2C8
	ldr r0, [r4, 0x8]
	cmp r0, 0x2
	beq _0809D356
	cmp r0, 0x2
	bhi _0809D2CC
	cmp r0, 0x1
	beq _0809D2D2
	b _0809D388
	.align 2, 0
_0809D2C4: .4byte 0xffff0000
_0809D2C8: .4byte gUnknown_20399E8
_0809D2CC:
	cmp r0, 0x3
	beq _0809D314
	b _0809D388
_0809D2D2:
	ldr r0, [r4, 0x1C]
	ldr r1, [r4, 0x14]
	subs r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r4, 0x20]
	ldr r1, [r4, 0x18]
	subs r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r4, 0xC]
	add r0, sp, 0x4
	bl sub_800290C
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _0809D2FA
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _0809D2FA
	str r0, [r4, 0x8]
	b _0809D392
_0809D2FA:
	ldr r2, _0809D310
	ldr r0, [r2, 0x14]
	ldr r1, [sp, 0x4]
	adds r0, r1
	str r0, [r2, 0x14]
	ldr r0, [r2, 0x18]
	ldr r1, [sp, 0x8]
	adds r0, r1
	str r0, [r2, 0x18]
	b _0809D392
	.align 2, 0
_0809D310: .4byte gUnknown_20399E8
_0809D314:
	ldr r1, [r4, 0x1C]
	ldr r0, [r4, 0x14]
	subs r0, r1, r0
	cmp r0, 0
	bge _0809D320
	adds r0, 0xFF
_0809D320:
	asrs r2, r0, 8
	ldr r1, [r4, 0x20]
	ldr r0, [r4, 0x18]
	subs r1, r0
	cmp r1, 0
	bge _0809D32E
	adds r1, 0xFF
_0809D32E:
	asrs r1, 8
	lsls r0, r2, 8
	lsls r1, 8
	bl sub_8009FB8
	cmp r0, 0
	bge _0809D33E
	adds r0, 0xFF
_0809D33E:
	asrs r0, 8
	lsls r0, 8
	ldr r1, [r4, 0xC]
	bl __divsi3
	str r0, [r4, 0x10]
	cmp r0, 0
	bgt _0809D352
	movs r0, 0x1
	str r0, [r4, 0x10]
_0809D352:
	movs r0, 0x2
	str r0, [r4, 0x8]
_0809D356:
	add r0, sp, 0xC
	ldr r1, _0809D384
	adds r2, r1, 0
	adds r2, 0x8
	adds r5, r1, 0
	subs r5, 0x14
	ldr r3, [r5, 0x10]
	movs r4, 0x1
	str r4, [sp]
	bl sub_8002934
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	str r0, [r5, 0x14]
	str r1, [r5, 0x18]
	ldr r0, [r5, 0x10]
	subs r0, 0x1
	str r0, [r5, 0x10]
	cmp r0, 0
	bgt _0809D392
	movs r0, 0
	str r0, [r5, 0x8]
	b _0809D392
	.align 2, 0
_0809D384: .4byte gUnknown_20399FC
_0809D388:
	ldr r2, _0809D3A4
	ldr r0, [r2, 0x1C]
	ldr r1, [r2, 0x20]
	str r0, [r2, 0x14]
	str r1, [r2, 0x18]
_0809D392:
	ldr r5, _0809D3A4
	ldr r0, [r5, 0x24]
	cmp r0, 0x1
	beq _0809D3A8
	cmp r0, 0x2
	beq _0809D3D2
	movs r0, 0
	str r0, [r5, 0x34]
	b _0809D402
	.align 2, 0
_0809D3A4: .4byte gUnknown_20399E8
_0809D3A8:
	ldr r0, [r5, 0x30]
	subs r0, 0x1
	str r0, [r5, 0x30]
	cmp r0, 0
	bgt _0809D404
	movs r0, 0x4
	str r0, [r5, 0x30]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	lsls r0, 10
	str r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	lsls r0, 10
	b _0809D402
_0809D3D2:
	ldr r0, [r5, 0x30]
	subs r0, 0x1
	str r0, [r5, 0x30]
	cmp r0, 0
	bgt _0809D404
	ldr r0, [r5, 0x2C]
	str r0, [r5, 0x30]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	ldr r1, [r5, 0x28]
	muls r0, r1
	lsls r0, 8
	str r0, [r5, 0x34]
	adds r0, r4, 0
	movs r1, 0x2
	bl OtherRandomRange
	ldr r1, [r5, 0x28]
	muls r0, r1
	lsls r0, 8
_0809D402:
	str r0, [r5, 0x38]
_0809D404:
	add r5, sp, 0x14
	add r6, sp, 0x1C
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80A579C
	lsls r0, 24
	cmp r0, 0
	beq _0809D474
	ldr r4, _0809D47C
	ldr r0, [r4, 0x14]
	ldr r1, [r4, 0x34]
	adds r0, r1
	adds r2, r0, 0
	subs r2, 0x80
	ldr r0, [r4, 0x18]
	ldr r1, [r4, 0x38]
	adds r0, r1
	ldr r1, _0809D480
	adds r3, r0, r1
	ldr r0, [sp, 0x14]
	cmp r2, r0
	bge _0809D434
	adds r2, r0, 0
_0809D434:
	ldr r0, [sp, 0x1C]
	cmp r2, r0
	blt _0809D43C
	subs r2, r0, 0x1
_0809D43C:
	ldr r0, [r5, 0x4]
	cmp r3, r0
	bge _0809D444
	adds r3, r0, 0
_0809D444:
	ldr r1, [r6, 0x4]
	cmp r3, r1
	blt _0809D44C
	subs r3, r1, 0x1
_0809D44C:
	ldr r1, _0809D484
	adds r0, r2, r1
	cmp r0, 0
	bge _0809D458
	adds r1, 0xFF
	adds r0, r2, r1
_0809D458:
	asrs r0, 8
	str r0, [r4, 0x3C]
	ldr r1, _0809D488
	adds r0, r3, r1
	cmp r0, 0
	bge _0809D468
	adds r1, 0xFF
	adds r0, r3, r1
_0809D468:
	asrs r0, 8
	str r0, [r4, 0x40]
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x1
	strb r0, [r1]
_0809D474:
	add sp, 0x24
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D47C: .4byte gUnknown_20399E8
_0809D480: .4byte 0xfffff480
_0809D484: .4byte 0xffff8700
_0809D488: .4byte 0xffffb000
	thumb_func_end sub_809D25C

	thumb_func_start nullsub_120
nullsub_120:
	bx lr
	thumb_func_end nullsub_120

	thumb_func_start sub_809D490
sub_809D490:
	push {r4,lr}
	ldr r4, _0809D4AC
	movs r0, 0x80
	lsls r0, 3
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	bl sub_809D4B0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D4AC: .4byte gUnknown_203B4B0
	thumb_func_end sub_809D490

	thumb_func_start sub_809D4B0
sub_809D4B0:
	push {r4,r5,lr}
	ldr r0, _0809D4EC
	movs r2, 0x1
	negs r2, r2
	adds r1, r2, 0
	strh r1, [r0]
	ldr r0, _0809D4F0
	strh r1, [r0]
	ldr r0, _0809D4F4
	strh r1, [r0]
	ldr r1, _0809D4F8
	movs r0, 0
	strb r0, [r1]
	movs r1, 0
	ldr r5, _0809D4FC
	movs r2, 0
	ldr r3, _0809D500
	ldr r4, _0809D504
_0809D4D4:
	adds r0, r1, r5
	strb r2, [r0]
	adds r0, r1, r3
	strb r2, [r0]
	stm r4!, {r2}
	adds r1, 0x1
	cmp r1, 0x80
	ble _0809D4D4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809D4EC: .4byte gUnknown_2039A30
_0809D4F0: .4byte gUnknown_2039A32
_0809D4F4: .4byte gUnknown_2039A34
_0809D4F8: .4byte gUnknown_2039A36
_0809D4FC: .4byte gUnknown_2039A38
_0809D500: .4byte gUnknown_2039AC0
_0809D504: .4byte gUnknown_2039B48
	thumb_func_end sub_809D4B0

	thumb_func_start sub_809D508
sub_809D508:
	push {r4,lr}
	ldr r4, _0809D51C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D51C: .4byte gUnknown_203B4B0
	thumb_func_end sub_809D508

	thumb_func_start sub_809D520
sub_809D520:
	ldr r1, _0809D528
	strh r1, [r0]
	bx lr
	.align 2, 0
_0809D528: .4byte 0x0000ffff
	thumb_func_end sub_809D520

	thumb_func_start sub_809D52C
sub_809D52C:
	push {lr}
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0x1
	beq _0809D544
	cmp r1, 0x1
	ble _0809D562
	cmp r1, 0x2
	beq _0809D54E
	cmp r1, 0x3
	beq _0809D558
	b _0809D562
_0809D544:
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80A882C
	b _0809D564
_0809D54E:
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80AC240
	b _0809D564
_0809D558:
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80AD158
	b _0809D564
_0809D562:
	movs r0, 0
_0809D564:
	pop {r1}
	bx r1
	thumb_func_end sub_809D52C

	thumb_func_start sub_809D568
sub_809D568:
	push {lr}
	adds r3, r0, 0
	ldr r0, _0809D5B4
	strh r0, [r3]
	movs r2, 0
	movs r0, 0
	strh r0, [r3, 0x2]
	str r0, [r3, 0x8]
	str r0, [r3, 0x4]
	str r0, [r3, 0x14]
	str r0, [r3, 0x10]
	adds r1, r3, 0
	adds r1, 0x20
	strb r2, [r1]
	str r0, [r3, 0x1C]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r3, 0x22]
	strh r0, [r3, 0x24]
	adds r2, r3, 0
	adds r2, 0x26
	movs r1, 0xFF
	strb r1, [r2]
	strh r0, [r3, 0x28]
	strh r0, [r3, 0x2A]
	strh r0, [r3, 0x2C]
	str r0, [r3, 0x30]
	movs r2, 0
	movs r1, 0x3
	adds r0, r3, 0
	adds r0, 0x5C
_0809D5A6:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _0809D5A6
	pop {r0}
	bx r0
	.align 2, 0
_0809D5B4: .4byte 0x0000ffff
	thumb_func_end sub_809D568

	thumb_func_start sub_809D5B8
sub_809D5B8:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	ldr r0, _0809D5FC
	strh r0, [r4, 0x10]
	movs r0, 0xFF
	strb r0, [r4, 0x12]
	adds r0, r4, 0
	adds r0, 0xC
	bl sub_809D520
	movs r2, 0
	movs r1, 0x3
	adds r0, r4, 0
	adds r0, 0x20
_0809D5DA:
	str r2, [r0]
	subs r0, 0x4
	subs r1, 0x1
	cmp r1, 0
	bge _0809D5DA
	adds r0, r4, 0
	adds r0, 0x24
	bl sub_809D568
	adds r0, r4, 0
	adds r0, 0x84
	bl sub_809D568
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D5FC: .4byte 0x0000ffff
	thumb_func_end sub_809D5B8

	thumb_func_start sub_809D600
sub_809D600:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x18]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 24
	asrs r5, 24
	bl sub_809D5B8
	str r6, [r7]
	mov r0, r8
	str r0, [r7, 0x4]
	strh r4, [r7, 0x10]
	strb r5, [r7, 0x12]
	ldrh r0, [r6]
	strh r0, [r7, 0x8]
	ldr r1, [r6, 0x4]
	cmp r1, 0
	beq _0809D63A
	mov r0, r8
	bl _call_via_r1
	strh r0, [r7, 0xA]
	b _0809D63C
_0809D63A:
	strh r1, [r7, 0xA]
_0809D63C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809D600

	thumb_func_start sub_809D648
sub_809D648:
	push {lr}
	bl sub_809D5B8
	pop {r0}
	bx r0
	thumb_func_end sub_809D648

	thumb_func_start sub_809D654
sub_809D654:
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	bx lr
	thumb_func_end sub_809D654

	thumb_func_start sub_809D65C
sub_809D65C:
	push {lr}
	adds r1, r0, 0
	movs r2, 0x26
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809D66E
	movs r0, 0x1
	negs r0, r0
	b _0809D672
_0809D66E:
	movs r2, 0x24
	ldrsh r0, [r1, r2]
_0809D672:
	pop {r1}
	bx r1
	thumb_func_end sub_809D65C

	thumb_func_start sub_809D678
sub_809D678:
	movs r2, 0x26
	ldrsh r1, [r0, r2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bx lr
	thumb_func_end sub_809D678

	thumb_func_start sub_809D684
sub_809D684:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0809D6A4
	ldr r0, [r2, 0x34]
	cmp r0, 0
	beq _0809D69C
	ldr r1, [r2, 0x38]
	b _0809D69E
_0809D69C:
	ldr r1, [r2, 0x2C]
_0809D69E:
	ldr r0, [r3]
	cmp r1, r0
	beq _0809D6CC
_0809D6A4:
	adds r0, r2, 0
	adds r0, 0x86
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0809D6D0
	adds r0, r2, 0
	adds r0, 0x94
	ldr r0, [r0]
	cmp r0, 0
	beq _0809D6C0
	adds r0, r2, 0
	adds r0, 0x98
	b _0809D6C4
_0809D6C0:
	adds r0, r2, 0
	adds r0, 0x8C
_0809D6C4:
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bne _0809D6D0
_0809D6CC:
	movs r0, 0x1
	b _0809D6D2
_0809D6D0:
	movs r0, 0
_0809D6D2:
	pop {r1}
	bx r1
	thumb_func_end sub_809D684

	thumb_func_start sub_809D6D8
sub_809D6D8:
	lsls r1, 16
	asrs r1, 14
	adds r0, 0x14
	adds r0, r1
	str r2, [r0]
	bx lr
	thumb_func_end sub_809D6D8

	thumb_func_start sub_809D6E4
sub_809D6E4:
	push {r4,lr}
	lsls r2, 16
	asrs r2, 16
	lsls r4, r2, 2
	adds r3, r0, 0
	adds r3, 0x14
	adds r3, r4
	ldr r3, [r3]
	str r3, [r1]
	strh r2, [r1, 0x4]
	ldrh r2, [r0, 0x10]
	strh r2, [r1, 0x6]
	ldrb r0, [r0, 0x12]
	strb r0, [r1, 0x8]
	adds r0, r3, 0
	cmp r0, 0
	beq _0809D708
	movs r0, 0x1
_0809D708:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D6E4

	thumb_func_start sub_809D710
sub_809D710:
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	lsls r2, 16
	asrs r2, 16
	ldr r1, _0809D73C
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	str r0, [r3]
	movs r0, 0x2
	strh r0, [r3, 0x4]
	cmp r4, 0
	beq _0809D740
	ldrh r0, [r4, 0x10]
	strh r0, [r3, 0x6]
	ldrb r0, [r4, 0x12]
	b _0809D746
	.align 2, 0
_0809D73C: .4byte gUnknown_812F1F8
_0809D740:
	ldr r0, _0809D750
	strh r0, [r3, 0x6]
	movs r0, 0xFF
_0809D746:
	strb r0, [r3, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D750: .4byte 0x0000ffff
	thumb_func_end sub_809D710

	thumb_func_start sub_809D754
sub_809D754:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_809D568
	adds r4, 0x84
	adds r0, r4, 0
	bl sub_809D568
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D754

	thumb_func_start sub_809D770
sub_809D770:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x24
	bl sub_809D568
	adds r0, r4, 0
	adds r0, 0x84
	bl sub_809D568
	movs r0, 0x4
	strh r0, [r4, 0x26]
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D770

	thumb_func_start GroundScript_ExecutePP
GroundScript_ExecutePP:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	cmp r6, 0
	beq _0809D7A2
	ldr r0, [r6]
	cmp r0, 0
	bne _0809D7A6
_0809D7A2:
	movs r0, 0
	b _0809D8B8
_0809D7A6:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r0, 0x5
	bhi _0809D858
	lsls r0, 2
	ldr r1, _0809D7B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809D7B8: .4byte _0809D7BC
	.align 2, 0
_0809D7BC:
	.4byte _0809D830
	.4byte _0809D84A
	.4byte _0809D7D4
	.4byte _0809D7D4
	.4byte _0809D858
	.4byte _0809D7EE
_0809D7D4:
	movs r3, 0x24
	ldrsh r0, [r5, r3]
	cmp r0, 0x1
	beq _0809D838
	adds r4, r5, 0
	adds r4, 0x24
	cmp r0, 0x5
	bne _0809D86C
	adds r0, r5, 0
	adds r0, 0x84
	bl sub_809D568
	b _0809D86C
_0809D7EE:
	movs r1, 0x24
	ldrsh r0, [r5, r1]
	cmp r0, 0x2
	beq _0809D808
	ldr r0, _0809D800
	ldr r1, _0809D804
	bl FatalError
	.align 2, 0
_0809D800: .4byte gUnknown_8116538
_0809D804: .4byte gUnknown_8116544
_0809D808:
	adds r2, r5, 0
	adds r2, 0x84
	movs r3, 0
	ldrsh r1, [r2, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809D828
	ldr r0, _0809D820
	ldr r1, _0809D824
	bl FatalError
	.align 2, 0
_0809D820: .4byte gUnknown_8116560
_0809D824: .4byte gUnknown_811656C
_0809D828:
	adds r4, r5, 0
	adds r4, 0x24
	adds r0, r2, 0
	b _0809D840
_0809D830:
	movs r1, 0x24
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _0809D84A
_0809D838:
	adds r0, r5, 0
	adds r0, 0x84
	adds r4, r5, 0
	adds r4, 0x24
_0809D840:
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	b _0809D86C
_0809D84A:
	adds r0, r5, 0
	adds r0, 0x84
	bl sub_809D568
	adds r4, r5, 0
	adds r4, 0x24
	b _0809D86C
_0809D858:
	ldr r0, _0809D864
	ldr r1, _0809D868
	movs r3, 0x4
	ldrsh r2, [r6, r3]
	bl FatalError
	.align 2, 0
_0809D864: .4byte gUnknown_8116588
_0809D868: .4byte gUnknown_8116594
_0809D86C:
	adds r0, r4, 0
	bl sub_809D568
	cmp r7, 0
	beq _0809D87C
	ldr r0, [r7]
	str r0, [r5, 0xC]
	b _0809D884
_0809D87C:
	adds r0, r5, 0
	adds r0, 0xC
	bl sub_809D520
_0809D884:
	ldrh r0, [r6, 0x4]
	movs r1, 0
	strh r0, [r5, 0x24]
	movs r0, 0x3
	strh r0, [r5, 0x26]
	ldrh r0, [r6, 0x6]
	strh r0, [r5, 0x30]
	ldrb r0, [r6, 0x8]
	adds r2, r5, 0
	adds r2, 0x32
	strb r0, [r2]
	ldr r0, [r6]
	str r0, [r5, 0x28]
	str r0, [r5, 0x2C]
	str r1, [r5, 0x34]
	str r1, [r5, 0x38]
	ldr r0, [r5]
	ldr r2, [r0, 0x14]
	cmp r2, 0
	beq _0809D8B6
	ldr r0, [r5, 0x4]
	adds r1, r5, 0
	adds r1, 0x4A
	bl _call_via_r2
_0809D8B6:
	movs r0, 0x1
_0809D8B8:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GroundScript_ExecutePP

	thumb_func_start sub_809D8C0
sub_809D8C0:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 16
	mov r1, sp
	bl sub_809D6E4
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	adds r3, r6, 0
	bl GroundScript_ExecutePP
	lsls r0, 24
	lsrs r0, 24
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_809D8C0

	thumb_func_start sub_809D8EC
sub_809D8EC:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	cmp r5, 0
	bne _0809D910
	bl sub_809A750
	lsls r0, 24
	cmp r0, 0
	bne _0809D910
	adds r0, r4, 0
	movs r1, 0
	bl sub_80A2460
	str r0, [r4, 0x28]
	movs r0, 0
	b _0809D922
_0809D910:
	adds r0, r4, 0
	adds r0, 0x46
	strh r5, [r0]
	movs r0, 0x2
	strh r0, [r4, 0x26]
	ldr r1, _0809D928
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
_0809D922:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809D928: .4byte gUnknown_2039A36
	thumb_func_end sub_809D8EC

	thumb_func_start sub_809D92C
sub_809D92C:
	push {lr}
	ldr r1, _0809D93C
	bl sub_809D770
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.align 2, 0
_0809D93C: .4byte gUnknown_81165C8
	thumb_func_end sub_809D92C

	thumb_func_start sub_809D940
sub_809D940:
	push {r4,lr}
	bl sub_80A8B74
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80AC378
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	bl sub_80AD290
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_809D940

	thumb_func_start sub_809D968
sub_809D968:
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	movs r4, 0
	adds r2, r5, 0
	adds r2, 0x46
	ldrh r1, [r2]
	movs r0, 0
	ldrsh r3, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	beq _0809D98E
	cmp r3, r6
	bne _0809D98E
	ldr r0, _0809D9B4
	strh r0, [r2]
	movs r4, 0x1
_0809D98E:
	adds r2, r5, 0
	adds r2, 0xA6
	ldrh r1, [r2]
	movs r0, 0
	ldrsh r3, [r2, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r3, r0
	beq _0809D9AA
	cmp r3, r6
	bne _0809D9AA
	ldr r0, _0809D9B4
	strh r0, [r2]
	movs r4, 0x1
_0809D9AA:
	adds r0, r4, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809D9B4: .4byte 0x0000ffff
	thumb_func_end sub_809D968

	thumb_func_start sub_809D9B8
sub_809D9B8:
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0809D9D4
	adds r1, r0, r1
	movs r3, 0
	movs r2, 0x1
	strb r2, [r1]
	ldr r1, _0809D9D8
	lsls r0, 2
	adds r0, r1
	str r3, [r0]
	ldr r0, _0809D9DC
	strb r2, [r0]
	bx lr
	.align 2, 0
_0809D9D4: .4byte gUnknown_2039A38
_0809D9D8: .4byte gUnknown_2039B48
_0809D9DC: .4byte gUnknown_2039A36
	thumb_func_end sub_809D9B8

	thumb_func_start sub_809D9E0
sub_809D9E0:
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0809D9FC
	adds r2, r0, r2
	movs r3, 0x1
	strb r3, [r2]
	ldr r2, _0809DA00
	lsls r0, 2
	adds r0, r2
	str r1, [r0]
	ldr r0, _0809DA04
	strb r3, [r0]
	bx lr
	.align 2, 0
_0809D9FC: .4byte gUnknown_2039A38
_0809DA00: .4byte gUnknown_2039B48
_0809DA04: .4byte gUnknown_2039A36
	thumb_func_end sub_809D9E0

	thumb_func_start sub_809DA08
sub_809DA08:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	ldr r1, _0809DA2C
	lsls r0, r4, 2
	adds r0, r1
	str r2, [r0]
	cmp r4, 0
	bne _0809DA38
	bl sub_809A750
	lsls r0, 24
	cmp r0, 0
	bne _0809DA30
	movs r0, 0
	b _0809DA5E
	.align 2, 0
_0809DA2C: .4byte gUnknown_2039B48
_0809DA30:
	adds r0, r5, 0
	adds r0, 0x46
	strh r4, [r0]
	b _0809DA52
_0809DA38:
	movs r1, 0x80
	adds r2, r5, 0
	adds r2, 0x46
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0809DA64
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _0809DA68
	adds r0, r4, r0
	strb r1, [r0]
_0809DA52:
	movs r0, 0x2
	strh r0, [r5, 0x26]
	ldr r1, _0809DA6C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
_0809DA5E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809DA64: .4byte gUnknown_2039A38
_0809DA68: .4byte gUnknown_2039AC0
_0809DA6C: .4byte gUnknown_2039A36
	thumb_func_end sub_809DA08

	thumb_func_start HandleAction
HandleAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x148
	adds r7, r0, 0
	movs r1, 0x26
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _0809DA8A
	bl _0809EAB8
_0809DA8A:
	movs r2, 0x26
	ldrsh r0, [r7, r2]
	cmp r0, 0x4
	bls _0809DA96
	bl _0809E9CC
_0809DA96:
	lsls r0, 2
	ldr r1, _0809DAA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809DAA0: .4byte _0809DAA4
	.align 2, 0
_0809DAA4:
	.4byte _0809E9C6
	.4byte _0809E9C6
	.4byte _0809DAB8
	.4byte _0809E900
	.4byte _0809E9C6
_0809DAB8:
	adds r1, r7, 0
	adds r1, 0x44
	ldrb r0, [r1]
	subs r0, 0x3
	adds r6, r1, 0
	cmp r0, 0xED
	bls _0809DACA
	bl _0809E9D6
_0809DACA:
	lsls r0, 2
	ldr r1, _0809DAD4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809DAD4: .4byte _0809DAD8
	.align 2, 0
_0809DAD8:
	.4byte _0809E382
	.4byte _0809E3C4
	.4byte _0809E524
	.4byte _0809E464
	.4byte _0809E4B4
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E308
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E31C
	.4byte _0809E75C
	.4byte _0809E33C
	.4byte _0809E368
	.4byte _0809E658
	.4byte _0809E6B4
	.4byte _0809E6E8
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809E0A2
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809E0A2
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E0E8
	.4byte _0809E0E8
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E798
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E9D6
	.4byte _0809E8D8
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DEA6
	.4byte _0809DEBE
	.4byte _0809DED6
	.4byte _0809DEE8
	.4byte _0809DF24
	.4byte _0809DF24
	.4byte _0809E2DE
	.4byte _0809E9D6
	.4byte _0809E2DE
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
_0809DE90:
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	ble _0809DEA2
	bl _0809EAB2
_0809DEA2:
	bl _0809E8F4
_0809DEA6:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r1, [r1, 0x4C]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0809DEBA
	bl _0809E9D6
_0809DEBA:
	bl _0809E8F4
_0809DEBE:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r1, [r1, 0x50]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0809DED2
	bl _0809E9D6
_0809DED2:
	bl _0809E8F4
_0809DED6:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809DEE4
	bl _0809E9D6
_0809DEE4:
	bl _0809E8F4
_0809DEE8:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrh r0, [r0, 0x2]
	bl sub_8011940
	lsls r0, 24
	cmp r0, 0
	bne _0809DF06
	bl _0809E8F4
_0809DF06:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r1, [r2]
	adds r0, r1, 0x1
	strh r0, [r2]
	lsls r1, 16
	ldr r0, _0809DF20
	cmp r1, r0
	bgt _0809DF1C
	bl _0809E9D6
_0809DF1C:
	bl _0809E8F4
	.align 2, 0
_0809DF20: .4byte 0x2a2f0000
_0809DF24:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrh r0, [r0, 0x2]
	bl sub_80119C0
	lsls r0, 24
	cmp r0, 0
	bne _0809DF42
	bl _0809E8F4
_0809DF42:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r1, [r2]
	adds r0, r1, 0x1
	strh r0, [r2]
	lsls r1, 16
	ldr r0, _0809DF5C
	cmp r1, r0
	bgt _0809DF58
	bl _0809E9D6
_0809DF58:
	bl _0809E8F4
	.align 2, 0
_0809DF5C: .4byte 0x0e0f0000
_0809DF60:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0xA4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7, 0x60]
	ldr r0, [r5]
	subs r1, r0
	add r4, sp, 0xAC
	str r1, [r4]
	ldr r0, [r7, 0x64]
	ldr r1, [r5, 0x4]
	subs r0, r1
	str r0, [r4, 0x4]
	ldr r1, [r7, 0x54]
	adds r0, r4, 0
	bl sub_800290C
	ldr r0, [r4]
	cmp r0, 0
	bne _0809DF98
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bne _0809DF98
	bl _0809E8F4
_0809DF98:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0x9
	ands r1, r0
	cmp r1, 0
	beq _0809DFB0
	bl _0809E8F4
_0809DFB0:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r2, r7, 0
	adds r2, 0x4E
	ldrh r0, [r2]
	movs r5, 0
	ldrsh r1, [r2, r5]
	cmp r1, 0
	bge _0809DFD0
	bl _0809E9D6
_0809DFD0:
	cmp r1, 0
	ble _0809DFD8
	bl _0809EAAC
_0809DFD8:
	bl _0809E8F4
_0809DFDC:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0xB4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7, 0x60]
	ldr r0, [r5]
	subs r1, r0
	add r4, sp, 0xBC
	str r1, [r4]
	ldr r0, [r7, 0x64]
	ldr r1, [r5, 0x4]
	subs r0, r1
	str r0, [r4, 0x4]
	ldr r1, [r7, 0x54]
	adds r0, r4, 0
	bl sub_800290C
	ldr r0, [r4]
	adds r5, r4, 0
	cmp r0, 0
	bne _0809E016
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bne _0809E016
	bl _0809E8F4
_0809E016:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r5, 0
	bl _call_via_r2
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_8002C60
	lsls r0, 24
	adds r2, r7, 0
	adds r2, 0x4A
	asrs r1, r0, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	movs r0, 0x9
	ands r0, r4
	cmp r0, 0
	beq _0809E04C
	bl _0809E8F4
_0809E04C:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r2, r7, 0
	adds r2, 0x4E
	ldrh r0, [r2]
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0
	bge _0809E06C
	bl _0809E9D6
_0809E06C:
	cmp r1, 0
	ble _0809E074
	bl _0809EAAC
_0809E074:
	bl _0809E8F4
_0809E078:
	adds r6, r7, 0
	adds r6, 0x4E
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	ble _0809E088
	bl _0809EA62
_0809E088:
	bl _0809E8F4
_0809E08C:
	movs r2, 0x4E
	adds r2, r7
	mov r8, r2
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _0809E09E
	bl _0809E9DA
_0809E09E:
	bl _0809E8F4
_0809E0A2:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xE4
	add r2, sp, 0xE8
	ldr r3, [r1, 0x10]
	adds r1, r4, 0
	bl _call_via_r3
	ldr r0, [r7, 0x6C]
	ldr r1, [r4]
	subs r0, r1
	adds r2, r4, 0
	cmp r0, 0
	bne _0809E0C2
	bl _0809E8F4
_0809E0C2:
	ldr r4, [r7, 0x54]
	cmn r0, r4
	bge _0809E0CC
	subs r0, r1, r4
	b _0809E0D4
_0809E0CC:
	cmp r0, r4
	ble _0809E0D2
	adds r0, r4, 0
_0809E0D2:
	adds r0, r1, r0
_0809E0D4:
	str r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0xE4
	ldr r1, [r1]
	ldr r2, [r2, 0x28]
	bl _call_via_r2
	bl _0809E9D6
_0809E0E8:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0x14
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0
	ldrsb r1, [r4, r1]
	ldr r2, [r7, 0x54]
	add r4, sp, 0xEC
	adds r0, r4, 0
	bl sub_8002BB8
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	add r1, sp, 0xF4
	str r2, [r1]
	str r3, [r1, 0x4]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	movs r1, 0x9
	ands r1, r0
	cmp r1, 0
	beq _0809E124
	bl _0809E8F4
_0809E124:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	ble _0809E144
	bl _0809EAB2
_0809E144:
	b _0809E8F4
_0809E146:
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	mov r10, r1
	cmp r0, 0
	ble _0809E15A
	bl _0809EAB2
_0809E15A:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	movs r4, 0x1
	negs r4, r4
	mov r8, r4
	movs r5, 0
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	mov r4, sp
	adds r4, 0x15
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r0, sp, 0x4
	ldrb r0, [r0]
	subs r0, 0x91
	mov r9, r4
	cmp r0, 0x4
	bhi _0809E234
	lsls r0, 2
	ldr r1, _0809E194
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809E194: .4byte _0809E198
	.align 2, 0
_0809E198:
	.4byte _0809E1AC
	.4byte _0809E1AC
	.4byte _0809E1BA
	.4byte _0809E1E0
	.4byte _0809E20C
_0809E1AC:
	adds r0, r7, 0
	adds r0, 0x71
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	b _0809E234
_0809E1BA:
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _0809E234
	movs r5, 0x1
	add r1, sp, 0xFC
	adds r0, r4, 0
	bl sub_80A8FD8
	add r1, sp, 0x104
	adds r0, r4, 0
	bl sub_80A8F9C
	b _0809E234
_0809E1E0:
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _0809E234
	movs r5, 0x1
	add r1, sp, 0xFC
	bl sub_80A8FD8
	ldr r0, _0809E208
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x104
	str r0, [r2]
	str r1, [r2, 0x4]
	b _0809E234
	.align 2, 0
_0809E208: .4byte gUnknown_81164DC
_0809E20C:
	movs r5, 0x1
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xFC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0x104
	ldr r2, [r2, 0x8]
	bl _call_via_r2
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
_0809E234:
	cmp r5, 0
	beq _0809E282
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0x10C
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0x114
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r6, sp, 0xFC
	add r3, sp, 0x104
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _0809E28C
	ldr r3, _0809E2CC
	adds r0, r5, 0
	adds r1, r3, 0
	adds r2, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
_0809E282:
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _0809E28C
	b _0809E8F4
_0809E28C:
	mov r5, r9
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r8, r0
	bne _0809E298
	b _0809E8F4
_0809E298:
	mov r6, r9
	movs r0, 0
	ldrsb r0, [r6, r0]
	add r1, sp, 0x4
	ldrh r2, [r1, 0x2]
	lsls r2, 24
	lsrs r2, 24
	mov r1, r8
	bl sub_8002A70
	adds r1, r7, 0
	adds r1, 0x4A
	strb r0, [r1]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x4
	ldrb r0, [r0, 0x1]
	mov r1, r10
	strh r0, [r1]
	b _0809E9CC
	.align 2, 0
_0809E2CC: .4byte gUnknown_81164DC
_0809E2D0:
	bl sub_809D234
	lsls r0, 24
	cmp r0, 0
	beq _0809E2DC
	b _0809E9D6
_0809E2DC:
	b _0809E8F4
_0809E2DE:
	adds r0, r7, 0
	adds r0, 0x46
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E2F0
	b _0809E9D6
_0809E2F0:
	ldr r1, _0809E304
	adds r0, r7, 0
	adds r0, 0x4C
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _0809E8EC
	.align 2, 0
_0809E304: .4byte gUnknown_2039B48
_0809E308:
	adds r0, r7, 0
	adds r0, 0x46
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E31A
	b _0809E9D6
_0809E31A:
	b _0809E8CA
_0809E31C:
	adds r0, r7, 0
	adds r0, 0x46
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E32E
	b _0809E9D6
_0809E32E:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809E33A
	b _0809E9D6
_0809E33A:
	b _0809E8CA
_0809E33C:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrb r1, [r0, 0x1]
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	ldr r3, [sp, 0x8]
	adds r0, r7, 0
	bl sub_80A14E8
	adds r1, r0, 0
	cmp r1, 0
	bge _0809E360
	b _0809E9D6
_0809E360:
	movs r0, 0x3
	strh r0, [r7, 0x26]
	adds r0, r7, 0
	b _0809E60C
_0809E368:
	add r0, sp, 0x11C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E376
	b _0809E9D6
_0809E376:
	add r0, sp, 0x11C
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
_0809E382:
	add r0, sp, 0x120
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E390
	b _0809E9D6
_0809E390:
	add r4, sp, 0x120
	ldr r0, [r4]
	cmp r0, 0
	blt _0809E3BA
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r4]
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x4
	movs r3, 0x2
	ldrsh r2, [r1, r3]
	movs r1, 0
	bl sub_8098D1C
_0809E3BA:
	ldr r1, [r4]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
_0809E3C4:
	adds r4, r7, 0
	adds r4, 0x4C
	movs r5, 0
	ldrsh r0, [r4, r5]
	cmp r0, 0
	bne _0809E40C
	add r0, sp, 0x124
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E3DE
	b _0809E9D6
_0809E3DE:
	add r0, sp, 0x124
	ldr r0, [r0]
	cmp r0, 0
	blt _0809E400
	lsls r0, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	movs r0, 0x1
	b _0809E402
_0809E400:
	ldr r0, _0809E408
_0809E402:
	strh r0, [r4]
	b _0809E8CE
	.align 2, 0
_0809E408: .4byte 0x0000ffff
_0809E40C:
	cmp r0, 0x1
	bne _0809E464
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0
	movs r1, 0x12
	bl sub_8001658
	adds r2, r0, 0
	lsls r2, 16
	asrs r4, r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x30
	bl sub_8001784
	cmp r4, 0x13
	bne _0809E43C
	cmp r0, 0
	beq _0809E45A
_0809E43C:
	add r0, sp, 0x4
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_8098DCC
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A2460
	str r0, [r7, 0x28]
	movs r0, 0
	movs r1, 0
	bl sub_80A87AC
	b _0809E8F4
_0809E45A:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x13
	bl sub_80018D8
_0809E464:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r5, r0, 0
	cmp r1, 0
	bne _0809E4B4
	add r0, sp, 0x128
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E480
	b _0809E9D6
_0809E480:
	add r0, sp, 0x128
	ldr r1, [r0]
	cmp r1, 0
	blt _0809E4AA
	ldrb r0, [r6]
	cmp r0, 0x4
	bne _0809E49A
	lsls r0, r1, 16
	asrs r0, 16
	bl sub_80A26B8
	lsls r0, 16
	b _0809E49C
_0809E49A:
	lsls r0, r1, 16
_0809E49C:
	asrs r2, r0, 16
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	movs r0, 0x1
	b _0809E4AC
_0809E4AA:
	ldr r0, _0809E4B0
_0809E4AC:
	strh r0, [r5]
	b _0809E8CE
	.align 2, 0
_0809E4B0: .4byte 0x0000ffff
_0809E4B4:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r5, r0, 0
	cmp r1, 0x1
	beq _0809E4C4
	b _0809E5B8
_0809E4C4:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r6, r0, 16
	add r4, sp, 0x18
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80990EC
	lsls r0, 24
	cmp r0, 0
	beq _0809E580
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8099220
	movs r0, 0x6
	bl sub_80023E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4]
	ldr r4, _0809E51C
	ldr r2, [r4]
	movs r1, 0
	str r1, [sp]
	bl sub_809034C
	adds r1, r0, 0
	ldr r0, _0809E520
	str r1, [r0]
	cmp r1, 0x1
	beq _0809E586
	cmp r1, 0x1
	bcc _0809E580
	cmp r1, 0x2
	bne _0809E5AE
	strh r1, [r5]
	ldr r2, [r4]
	movs r0, 0x9
	b _0809E58E
	.align 2, 0
_0809E51C: .4byte gUnknown_203B4B0
_0809E520: .4byte gUnknown_2039DA4
_0809E524:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r4, 0
	ldrsh r6, [r0, r4]
	adds r5, r0, 0
	cmp r6, 0x1
	bne _0809E5B8
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_80023E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x4]
	ldr r4, _0809E578
	ldr r2, [r4]
	str r6, [sp]
	movs r1, 0
	bl sub_809034C
	adds r1, r0, 0
	ldr r0, _0809E57C
	str r1, [r0]
	cmp r1, 0x1
	beq _0809E586
	cmp r1, 0x1
	bcc _0809E580
	cmp r1, 0x2
	bne _0809E5AE
	strh r1, [r5]
	ldr r2, [r4]
	movs r0, 0x9
	b _0809E58E
	.align 2, 0
_0809E578: .4byte gUnknown_203B4B0
_0809E57C: .4byte gUnknown_2039DA4
_0809E580:
	movs r0, 0x3
	strh r0, [r5]
	b _0809E9CC
_0809E586:
	movs r0, 0x4
	strh r0, [r5]
	ldr r2, [r4]
	movs r0, 0xA
_0809E58E:
	movs r1, 0x1
	bl sub_809B1C0
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	bne _0809E5A4
	b _0809E9CC
_0809E5A4:
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	b _0809E9CC
_0809E5AE:
	ldr r0, _0809E5B4
	strh r0, [r5]
	b _0809E9CC
	.align 2, 0
_0809E5B4: .4byte 0x0000ffff
_0809E5B8:
	movs r6, 0
	ldrsh r2, [r5, r6]
	cmp r2, 0x2
	bne _0809E5DA
	add r0, sp, 0x12C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E5CE
	b _0809E9D6
_0809E5CE:
	add r0, sp, 0x12C
	ldr r0, [r0]
	cmp r0, 0
	beq _0809E626
	movs r0, 0x3
	b _0809E628
_0809E5DA:
	cmp r2, 0x3
	bne _0809E614
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	strh r2, [r7, 0x26]
	add r0, sp, 0x4
	movs r6, 0x2
	ldrsh r0, [r0, r6]
	bl sub_80999FC
	movs r0, 0x70
	movs r1, 0
	bl GroundMap_ExecuteEvent
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _0809E608
	b _0809E9CC
_0809E608:
	adds r0, r7, 0
	movs r1, 0x1
_0809E60C:
	bl sub_80A2460
	str r0, [r7, 0x28]
	b _0809E9CC
_0809E614:
	cmp r2, 0x4
	bne _0809E63C
	add r0, sp, 0x130
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E626
	b _0809E9D6
_0809E626:
	ldr r0, _0809E638
_0809E628:
	strh r0, [r5]
	movs r0, 0
	movs r1, 0
	bl sub_80A87AC
	bl sub_809A76C
	b _0809E9CC
	.align 2, 0
_0809E638: .4byte 0x0000ffff
_0809E63C:
	movs r0, 0
	movs r1, 0
	bl sub_8099220
	movs r4, 0x1
	negs r4, r4
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
	adds r0, r7, 0
	adds r1, r4, 0
	b _0809E8EE
_0809E658:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x134
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E672
	b _0809E9D6
_0809E672:
	add r0, sp, 0x134
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809E6A4
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E6A4
	adds r0, r1, 0
	bl sub_80A8D54
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _0809E6B0
_0809E696:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _0809E696
_0809E6A4:
	add r0, sp, 0x134
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E6B0: .4byte gUnknown_2039D98
_0809E6B4:
	add r0, sp, 0x138
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E6C2
	b _0809E9D6
_0809E6C2:
	add r4, sp, 0x138
	ldr r0, [r4]
	cmp r0, 0x1
	bne _0809E6D0
	ldr r0, _0809E6DC
	bl sub_80920EC
_0809E6D0:
	ldr r1, [r4]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E6DC: .4byte gUnknown_2039D98
_0809E6E0:
	movs r1, 0x2
	add r0, sp, 0x13C
	str r1, [r0]
	b _0809E74A
_0809E6E8:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	ldr r5, [sp, 0x10]
	add r0, sp, 0x13C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E704
	b _0809E9D6
_0809E704:
	add r0, sp, 0x13C
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809E74A
	add r4, sp, 0x18
	ldr r0, _0809E758
	adds r3, r4, 0
	movs r2, 0
	mov r1, sp
	adds r1, 0x27
_0809E718:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, r3
	bge _0809E718
	adds r1, r4, 0
	bl sub_80922F4
	movs r2, 0
	ldrb r0, [r4]
	ldrb r3, [r5]
	cmp r0, r3
	bne _0809E6E0
	cmp r0, 0
	beq _0809E74A
_0809E734:
	adds r2, 0x1
	cmp r2, 0xF
	bgt _0809E74A
	adds r0, r4, r2
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0809E6E0
	cmp r0, 0
	bne _0809E734
_0809E74A:
	add r0, sp, 0x13C
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E758: .4byte gUnknown_2039D98
_0809E75C:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r3, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	bne _0809E76C
	b _0809E872
_0809E76C:
	add r4, sp, 0xA0
	adds r0, r4, 0
	bl sub_809AFFC
	lsls r0, 24
	cmp r0, 0
	bne _0809E77C
	b _0809E9D6
_0809E77C:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0809E784
	b _0809E8CA
_0809E784:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _0809E8C2
_0809E798:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, r7, 0
	adds r2, 0x50
	movs r3, 0
	ldrsh r0, [r2, r3]
	adds r4, r2, 0
	cmp r0, 0
	bne _0809E84C
	movs r3, 0
	adds r0, r7, 0
	adds r0, 0x4C
	movs r5, 0
	ldrsh r2, [r0, r5]
	adds r5, r0, 0
	cmp r2, 0
	bge _0809E7CC
	ldr r0, [r7, 0x28]
	ldrb r0, [r0]
	cmp r0, 0xD1
	beq _0809E812
	b _0809E8F4
_0809E7CC:
	ldr r1, [r7, 0x28]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _0809E7F8
	movs r6, 0x2
	ldrsh r0, [r1, r6]
	cmp r0, r2
	beq _0809E812
_0809E7DC:
	ldr r0, [r7, 0x28]
	adds r1, r0, 0
	adds r1, 0x10
	str r1, [r7, 0x28]
	ldrb r0, [r0, 0x10]
	cmp r0, 0xD0
	bne _0809E7F8
	movs r0, 0x2
	ldrsh r1, [r1, r0]
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _0809E7DC
	movs r3, 0x1
_0809E7F8:
	cmp r3, 0
	bne _0809E812
	ldr r1, [r7, 0x28]
	ldrb r0, [r1]
	cmp r0, 0xD1
	bne _0809E8F4
_0809E804:
	adds r0, r1, 0
	adds r1, 0x10
	str r1, [r7, 0x28]
	ldrb r0, [r0, 0x10]
	cmp r0, 0xD1
	beq _0809E804
	b _0809E8F4
_0809E812:
	add r0, sp, 0x4
	ldrb r0, [r0, 0x1]
	ldr r1, [sp, 0x8]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [r7, 0x28]
	ldr r2, [r2, 0xC]
	bl sub_809AE90
	lsls r0, 24
	cmp r0, 0
	beq _0809E844
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	adds r0, r7, 0
	movs r1, 0
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	beq _0809E844
	movs r0, 0x1
	strh r0, [r4]
_0809E844:
	ldr r0, [r7, 0x28]
	adds r0, 0x10
	str r0, [r7, 0x28]
	b _0809E9CC
_0809E84C:
	adds r0, r7, 0
	adds r0, 0x46
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E85E
	b _0809E9D6
_0809E85E:
	movs r0, 0
	strh r0, [r2]
	b _0809E8D0
_0809E864:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r3, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	bne _0809E88A
_0809E872:
	adds r0, r7, 0
	adds r0, 0x46
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E884
	b _0809E9D6
_0809E884:
	adds r0, r3, 0x1
	strh r0, [r2]
	b _0809E9CC
_0809E88A:
	add r0, sp, 0x140
	bl sub_809B18C
	lsls r0, 24
	cmp r0, 0
	bne _0809E898
	b _0809E9D6
_0809E898:
	add r0, sp, 0x140
	ldr r3, [r0]
	cmp r3, 0
	ble _0809E8CA
	adds r0, r7, 0
	adds r0, 0x4C
	movs r6, 0
	ldrsh r2, [r0, r6]
	ldr r1, [r7, 0x40]
	lsls r0, r3, 4
	lsls r2, 4
	adds r2, r1
	add r1, sp, 0x4
	adds r0, r2
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	movs r5, 0x2
	ldrsh r1, [r0, r5]
_0809E8C2:
	adds r0, r7, 0
	bl sub_80A242C
_0809E8C8:
	str r0, [r7, 0x28]
_0809E8CA:
	movs r0, 0x3
	strh r0, [r7, 0x26]
_0809E8CE:
	movs r0, 0
_0809E8D0:
	movs r1, 0
	bl sub_80A87AC
	b _0809E9CC
_0809E8D8:
	adds r0, r7, 0
	adds r0, 0x46
	movs r6, 0
	ldrsh r1, [r0, r6]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809E9D6
	ldr r0, _0809E8FC
	ldr r1, [r0, 0x4]
_0809E8EC:
	adds r0, r7, 0
_0809E8EE:
	bl sub_80A2460
	str r0, [r7, 0x28]
_0809E8F4:
	movs r0, 0x3
	strh r0, [r7, 0x26]
	b _0809E9CC
	.align 2, 0
_0809E8FC: .4byte gUnknown_2039B48
_0809E900:
	adds r0, r7, 0
	bl ExecuteScriptCommand
	strh r0, [r7, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _0809E9BC
	lsls r0, 2
	ldr r1, _0809E91C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809E91C: .4byte _0809E920
	.align 2, 0
_0809E920:
	.4byte _0809E934
	.4byte _0809E9B8
	.4byte _0809E9BC
	.4byte _0809E9D6
	.4byte _0809E9B4
_0809E934:
	adds r0, r7, 0
	adds r0, 0x86
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0809E9AA
	adds r4, r7, 0
	adds r4, 0x84
	adds r0, r7, 0
	adds r0, 0x24
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	ldr r2, [r7]
	ldr r0, [r2, 0x2C]
	cmp r0, 0
	beq _0809E98E
	adds r5, r7, 0
	adds r5, 0x4A
	movs r1, 0
	ldrsb r1, [r5, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E98E
	ldr r0, [r7, 0x4]
	add r1, sp, 0x144
	ldr r2, [r2, 0x18]
	bl _call_via_r2
	add r0, sp, 0x144
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0809E98E
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0
	ldrsb r1, [r5, r1]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_0809E98E:
	ldr r0, [r7]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq _0809E9A2
	ldr r0, [r7, 0x4]
	adds r1, r7, 0
	adds r1, 0x48
	ldrh r1, [r1]
	bl _call_via_r2
_0809E9A2:
	adds r0, r4, 0
	bl sub_809D568
	b _0809E9D6
_0809E9AA:
	adds r0, r7, 0
	adds r0, 0x24
	bl sub_809D568
	b _0809E9D6
_0809E9B4:
	movs r0, 0x4
	b _0809EABA
_0809E9B8:
	movs r0, 0x1
	b _0809EABA
_0809E9BC:
	adds r1, r7, 0
	adds r1, 0x50
	movs r0, 0
	strh r0, [r1]
	b _0809E9CC
_0809E9C6:
	movs r2, 0x26
	ldrsh r0, [r7, r2]
	b _0809EABA
_0809E9CC:
	movs r3, 0x1
	cmp r3, 0
	beq _0809E9D6
	bl _0809DA8A
_0809E9D6:
	movs r0, 0x3
	b _0809EABA
_0809E9DA:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xCC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0xD4
	adds r1, r7, 0
	adds r1, 0x58
	adds r2, r7, 0
	adds r2, 0x60
	mov r6, r8
	movs r0, 0
	ldrsh r6, [r6, r0]
	mov r9, r6
	adds r6, r7, 0
	adds r6, 0x50
	movs r3, 0
	ldrsh r0, [r6, r3]
	str r0, [sp]
	adds r0, r5, 0
	mov r3, r9
	bl sub_8002934
	ldr r1, [r5]
	ldr r0, [r4]
	subs r1, r0
	add r0, sp, 0xDC
	str r1, [r0]
	ldr r1, [r5, 0x4]
	ldr r2, [r4, 0x4]
	subs r1, r2
	str r1, [r0, 0x4]
	bl sub_8002C60
	lsls r0, 24
	adds r2, r7, 0
	adds r2, 0x4A
	asrs r1, r0, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	mov r4, r8
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	b _0809E9D6
_0809EA62:
	add r5, sp, 0xC4
	adds r1, r7, 0
	adds r1, 0x58
	adds r2, r7, 0
	adds r2, 0x60
	movs r3, 0
	ldrsh r0, [r6, r3]
	mov r8, r0
	adds r4, r7, 0
	adds r4, 0x50
	movs r3, 0
	ldrsh r0, [r4, r3]
	str r0, [sp]
	adds r0, r5, 0
	mov r3, r8
	bl sub_8002934
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	ldrh r0, [r6]
	subs r0, 0x1
	strh r0, [r6]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0809E9D6
_0809EAAC:
	subs r0, 0x1
	strh r0, [r2]
	b _0809E9D6
_0809EAB2:
	subs r0, r2, 0x1
	strh r0, [r1]
	b _0809E9D6
_0809EAB8:
	movs r0, 0
_0809EABA:
	add sp, 0x148
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end HandleAction

	thumb_func_start ExecuteScriptCommand
ExecuteScriptCommand:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1BC
	mov r9, r0
	movs r0, 0x24
	add r0, r9
	mov r10, r0
_0809EAE0:
	mov r1, r10
	ldr r2, [r1, 0x4]
	str r2, [r1, 0x1C]
	add r1, sp, 0x8
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, 0x10
	mov r0, r10
	str r2, [r0, 0x4]
	add r0, sp, 0x8
	ldrb r0, [r0]
	mov r1, r10
	adds r1, 0x20
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	adds r2, r1, 0
	cmp r0, 0xF5
	bhi _0809EAE0
	lsls r0, 2
	ldr r1, _0809EB18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809EB18: .4byte _0809EB1C
	.align 2, 0
_0809EB1C:
	.4byte _0809EEF4
	.4byte _0809EF40
	.4byte _0809EFA2
	.4byte _0809EFD6
	.4byte _0809F064
	.4byte _0809F02A
	.4byte _0809F06C
	.4byte _0809F0D0
	.4byte _0809F0D0
	.4byte _0809F1FC
	.4byte _0809F2C8
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F2D6
	.4byte _0809F42A
	.4byte _0809F432
	.4byte _0809F43A
	.4byte _0809F442
	.4byte _0809F4FE
	.4byte _0809F5BE
	.4byte _0809F5AE
	.4byte _0809F5C6
	.4byte _0809F5C6
	.4byte _0809F660
	.4byte _0809F6EA
	.4byte _0809F786
	.4byte _0809F830
	.4byte _0809F842
	.4byte _0809F854
	.4byte _0809F872
	.4byte _0809F884
	.4byte _0809F896
	.4byte _0809F896
	.4byte _0809F8E8
	.4byte _0809F8F4
	.4byte _0809F900
	.4byte _0809F90C
	.4byte _0809F93E
	.4byte _0809FAF8
	.4byte _0809FB10
	.4byte _0809F92E
	.4byte _0809F936
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FB28
	.4byte _0809FBDA
	.4byte _0809FC12
	.4byte _0809FC40
	.4byte _0809FC2E
	.4byte _0809FC46
	.4byte _0809FCA4
	.4byte _0809FCC4
	.4byte _0809EAE0
	.4byte _080A0E3A
	.4byte _0809FCE8
	.4byte _0809FCF0
	.4byte _0809FD0A
	.4byte _0809FD38
	.4byte _0809FD6C
	.4byte _0809FDA0
	.4byte _0809FDA8
	.4byte _0809FDC2
	.4byte _0809FDD4
	.4byte _0809FDE2
	.4byte _0809FDC2
	.4byte _0809FDD4
	.4byte _0809FDE2
	.4byte _0809FE04
	.4byte _0809FE28
	.4byte _0809FE86
	.4byte _0809FEBE
	.4byte _0809FED0
	.4byte _0809FF00
	.4byte _0809FF32
	.4byte _0809FF46
	.4byte _0809FF62
	.4byte _0809FF78
	.4byte _0809FF9A
	.4byte _0809FFBA
	.4byte _0809FFE4
	.4byte _080A0010
	.4byte _080A0064
	.4byte _080A0096
	.4byte _080A010E
	.4byte _080A0186
	.4byte _080A0198
	.4byte _080A01B8
	.4byte _080A01F0
	.4byte _080A0220
	.4byte _080A0250
	.4byte _080A0282
	.4byte _080A0282
	.4byte _080A0560
	.4byte _080A0198
	.4byte _080A01B8
	.4byte _080A01F0
	.4byte _080A0220
	.4byte _080A0250
	.4byte _080A0282
	.4byte _080A0282
	.4byte _080A0560
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A02B2
	.4byte _080A0310
	.4byte _080A0370
	.4byte _080A03F8
	.4byte _080A0462
	.4byte _080A04F2
	.4byte _080A057C
	.4byte _080A05A4
	.4byte _080A05F0
	.4byte _080A060E
	.4byte _080A065C
	.4byte _080A068A
	.4byte _080A068A
	.4byte _080A068A
	.4byte _080A07CA
	.4byte _080A07DC
	.4byte _080A07C4
	.4byte _080A07C4
	.4byte _080A07C4
	.4byte _0809EAE0
	.4byte _080A080C
	.4byte _080A081E
	.4byte _080A086A
	.4byte _080A08BE
	.4byte _080A08CA
	.4byte _080A091E
	.4byte _080A0986
	.4byte _080A0998
	.4byte _080A09EA
	.4byte _080A0A52
	.4byte _080A0A64
	.4byte _080A0AB6
	.4byte _080A0B1E
	.4byte _080A0B30
	.4byte _080A0B42
	.4byte _080A0B54
	.4byte _080A0B6C
	.4byte _080A0B88
	.4byte _080A0BA2
	.4byte _080A0BB4
	.4byte _080A0BDA
	.4byte _080A0BF6
	.4byte _080A0C08
	.4byte _080A0C20
	.4byte _080A0C38
	.4byte _080A0C50
	.4byte _080A0C68
	.4byte _080A0C80
	.4byte _080A0C90
	.4byte _080A0CA2
	.4byte _080A0CC8
	.4byte _080A0CF2
	.4byte _080A0D16
	.4byte _080A0D40
	.4byte _080A0D6A
	.4byte _080A0D7A
	.4byte _080A0D94
	.4byte _080A0DAE
	.4byte _080A0DD6
	.4byte _080A0E08
	.4byte _080A0DE2
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _080A0E56
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _080A10A0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _080A10F8
	.4byte _0809EAE0
	.4byte _080A129E
	.4byte _080A12A8
	.4byte _080A12B4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _0809F0C4
	.4byte _080A12D0
	.4byte _080A12E6
	.4byte _080A12F4
	.4byte _080A1318
	.4byte _080A1324
	.4byte _080A1338
	.4byte _080A1344
	.4byte _080A1368
	.4byte _080A1374
	.4byte _080A13CA
	.4byte _080A13F8
	.4byte _080A1404
	.4byte _080A140C
	.4byte _080A1428
	.4byte _080A142C
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
	.4byte _0809EAE0
_0809EEF4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	adds r6, r4, 0
	add r0, sp, 0x8
	ldrb r5, [r0, 0x1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809EF26
	ldr r1, _0809EF38
	ldr r2, _0809EF3C
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r3, [r0]
	str r5, [sp]
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809EF26:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8098D1C
	b _0809EAE0
	.align 2, 0
_0809EF38: .4byte gUnknown_81165D4
_0809EF3C: .4byte gUnknown_811BAF4
_0809EF40:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	movs r5, 0x1
	negs r5, r5
	cmp r4, r5
	bne _0809EF5A
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
_0809EF5A:
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809EF70
	ldr r1, _0809EF90
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809EF70:
	cmp r4, r5
	beq _0809EF94
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_8098E18
	mov r0, r9
	movs r1, 0x1
	bl sub_80A2460
	mov r3, r9
	str r0, [r3, 0x28]
	b _0809EAE0
	.align 2, 0
_0809EF90: .4byte gUnknown_81165F4
_0809EF94:
	mov r0, r9
	movs r1, 0
	bl sub_80A2460
	mov r4, r9
	str r0, [r4, 0x28]
	b _0809EAE0
_0809EFA2:
	ldr r0, [sp, 0xC]
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _0809EFBE
	movs r1, 0x1
	negs r1, r1
	mov r0, r9
	bl sub_80A2460
	mov r5, r9
	str r0, [r5, 0x28]
	b _0809EAE0
_0809EFBE:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_8098D80
	mov r0, r9
	movs r1, 0
	bl sub_80A2460
	mov r2, r9
	str r0, [r2, 0x28]
	b _0809EAE0
_0809EFD6:
	ldr r1, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809F00C
	bl sub_802FCF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0809F0BC
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _0809F0BC
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	mov r0, r9
	adds r0, 0x4C
	strh r4, [r0]
	b _0809F0C4
_0809F00C:
	lsls r0, r1, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F02A:
	ldr r2, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	bne _0809F054
	movs r0, 0x24
	movs r1, 0
	movs r2, 0
	bl sub_809B1C0
	lsls r0, 24
	cmp r0, 0
	beq _0809F0BC
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0
	b _0809F0C2
_0809F054:
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F064:
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
_0809F06C:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r4, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0809F088
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	b _0809F092
_0809F088:
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
_0809F092:
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F0A8
	ldr r1, _0809F0B8
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809F0A8:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	beq _0809F0BC
	mov r1, r9
	adds r1, 0x4C
	movs r0, 0x1
	b _0809F0C2
	.align 2, 0
_0809F0B8: .4byte gUnknown_811660C
_0809F0BC:
	mov r1, r9
	adds r1, 0x4C
	ldr r0, _0809F0CC
_0809F0C2:
	strh r0, [r1]
_0809F0C4:
	movs r0, 0x2
	bl _080A142E
	.align 2, 0
_0809F0CC: .4byte 0x0000ffff
_0809F0D0:
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0809F130
	ldr r5, _0809F11C
	ldr r0, [sp, 0xC]
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A4D7C
	ldr r4, _0809F120
	strh r0, [r4]
	ldr r1, _0809F124
	strh r0, [r1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F16A
	ldr r1, _0809F128
	movs r3, 0
	ldrsh r2, [r5, r3]
	movs r5, 0
	ldrsh r3, [r4, r5]
	ldr r4, _0809F12C
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
	b _0809F16A
	.align 2, 0
_0809F11C: .4byte gUnknown_2039A30
_0809F120: .4byte gUnknown_2039A32
_0809F124: .4byte gUnknown_2039A34
_0809F128: .4byte gUnknown_8116628
_0809F12C: .4byte gUnknown_811BAF4
_0809F130:
	ldr r5, _0809F1E8
	ldr r4, _0809F1EC
	ldr r1, [sp, 0xC]
	strh r1, [r4]
	strh r1, [r5]
	ldr r0, _0809F1F0
	strh r1, [r0]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F16A
	ldr r1, _0809F1F4
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r4, 0
	ldrsh r3, [r5, r4]
	ldr r4, _0809F1F8
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
_0809F16A:
	ldr r5, _0809F1EC
	movs r0, 0
	ldrsh r2, [r5, r0]
	movs r0, 0
	movs r1, 0x10
	bl sub_80018D8
	ldr r6, _0809F1F8
	movs r2, 0
	ldrsh r1, [r5, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0
	movs r1, 0x11
	bl sub_80018D8
	ldr r4, _0809F1E8
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl GroundSprite_Reset
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl sub_809C770
	movs r5, 0
	ldrsh r0, [r4, r5]
	bl GroundMap_Select
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl GroundLink_Select
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r1, 0
	movs r2, 0
	bl GroundLives_Select
	movs r3, 0
	ldrsh r0, [r4, r3]
	b _0809F2A0
	.align 2, 0
_0809F1E8: .4byte gUnknown_2039A32
_0809F1EC: .4byte gUnknown_2039A30
_0809F1F0: .4byte gUnknown_2039A34
_0809F1F4: .4byte gUnknown_8116644
_0809F1F8: .4byte gUnknown_811BAF4
_0809F1FC:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	adds r6, r0, 0
	ldr r1, _0809F2AC
	ldr r5, _0809F2B0
	ldr r4, _0809F2B4
	ldr r0, [sp, 0x10]
	strh r0, [r4]
	strh r0, [r5]
	strh r0, [r1]
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F242
	ldr r1, _0809F2B8
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r4, 0
	ldrsh r3, [r5, r4]
	ldr r4, _0809F2BC
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x1
	bl Log
_0809F242:
	movs r1, 0
	ldrsh r0, [r5, r1]
	bl GroundSprite_Reset
	bl sub_809D0BC
	bl sub_80AD9D0
	bl sub_80A786C
	bl sub_80ABB98
	bl sub_80ACBD4
	ldrb r2, [r6, 0xC]
	ldr r1, _0809F2C0
	ldr r0, [sp, 0x58]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x58]
	add r1, sp, 0x8
	ldrh r2, [r1, 0x2]
	lsls r2, 24
	lsrs r2, 16
	ldr r1, _0809F2C4
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x58]
	movs r2, 0
	ldrsh r0, [r5, r2]
	add r1, sp, 0x58
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl GroundMap_SelectDungeon
	movs r3, 0
	ldrsh r0, [r5, r3]
	bl GroundLink_Select
	movs r4, 0
	ldrsh r0, [r5, r4]
	movs r1, 0
	movs r2, 0
	bl GroundLives_Select
	movs r1, 0
	ldrsh r0, [r5, r1]
_0809F2A0:
	movs r1, 0
	movs r2, 0
	bl GroundObject_Select
	b _0809EAE0
	.align 2, 0
_0809F2AC: .4byte gUnknown_2039A34
_0809F2B0: .4byte gUnknown_2039A32
_0809F2B4: .4byte gUnknown_2039A30
_0809F2B8: .4byte gUnknown_8116664
_0809F2BC: .4byte gUnknown_811BAF4
_0809F2C0: .4byte 0xffffff00
_0809F2C4: .4byte 0xffff00ff
_0809F2C8:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl GroundWeather_Select
	bl _0809EAE0
_0809F2D6:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809F2E8
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	b _0809F2EE
_0809F2E8:
	mov r3, r10
	movs r4, 0xC
	ldrsh r0, [r3, r4]
_0809F2EE:
	adds r6, r0, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F302
	add r0, sp, 0x8
	movs r1, 0x1
	ldrsb r1, [r0, r1]
	b _0809F308
_0809F302:
	mov r5, r10
	movs r1, 0xE
	ldrsb r1, [r5, r1]
_0809F308:
	adds r5, r1, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	subs r0, 0xC
	cmp r0, 0x9
	bls _0809F318
	bl _0809EAE0
_0809F318:
	lsls r0, 2
	ldr r1, _0809F324
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809F324: .4byte _0809F328
	.align 2, 0
_0809F328:
	.4byte _0809F350
	.4byte _0809F380
	.4byte _0809F398
	.4byte _0809F3B0
	.4byte _0809F3C8
	.4byte _0809F3E0
	.4byte _0809F3FA
	.4byte _0809F406
	.4byte _0809F412
	.4byte _0809F41E
_0809F350:
	ldr r4, _0809F37C
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundLives_Select
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundObject_Select
	movs r3, 0
	ldrsh r0, [r4, r3]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEffect_Select
	movs r1, 0
	ldrsh r0, [r4, r1]
	b _0809F3CE
	.align 2, 0
_0809F37C: .4byte gUnknown_2039A32
_0809F380:
	ldr r0, _0809F394
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundLives_Select
	bl _0809EAE0
	.align 2, 0
_0809F394: .4byte gUnknown_2039A32
_0809F398:
	ldr r0, _0809F3AC
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundObject_Select
	bl _0809EAE0
	.align 2, 0
_0809F3AC: .4byte gUnknown_2039A32
_0809F3B0:
	ldr r0, _0809F3C4
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEffect_Select
	bl _0809EAE0
	.align 2, 0
_0809F3C4: .4byte gUnknown_2039A32
_0809F3C8:
	ldr r0, _0809F3DC
	movs r1, 0
	ldrsh r0, [r0, r1]
_0809F3CE:
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundEvent_Select
	bl _0809EAE0
	.align 2, 0
_0809F3DC: .4byte gUnknown_2039A32
_0809F3E0:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundLives_Cancel
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundObject_Cancel
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEffect_Cancel
	b _0809F41E
_0809F3FA:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundLives_Cancel
	bl _0809EAE0
_0809F406:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundObject_Cancel
	bl _0809EAE0
_0809F412:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEffect_Cancel
	bl _0809EAE0
_0809F41E:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GroundEvent_Cancel
	bl _0809EAE0
_0809F42A:
	bl sub_80A79FC
	bl _0809EAE0
_0809F432:
	bl GroundObject_CancelBlank
	bl _0809EAE0
_0809F43A:
	bl GroundEffect_CancelBlank
	bl _0809EAE0
_0809F442:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x18
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r6, sp, 0x1C
	ldr r0, [sp, 0x10]
	add r5, sp, 0x34
	movs r2, 0
	strb r0, [r5]
	ldrb r1, [r4]
	mov r0, sp
	adds r0, 0x35
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	str r2, [sp, 0x38]
	add r4, sp, 0x3C
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x10
	bl memset
	ldr r2, _0809F4AC
	ldr r1, [sp, 0xC]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	str r0, [r4, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x18
	bl memcpy
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	adds r1, r6, 0
	cmp r0, 0
	blt _0809F4B0
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	b _0809F4B6
	.align 2, 0
_0809F4AC: .4byte gUnknown_812F1F8
_0809F4B0:
	mov r4, r10
	movs r5, 0xC
	ldrsh r2, [r4, r5]
_0809F4B6:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F4C8
	add r0, sp, 0x8
	movs r3, 0x1
	ldrsb r3, [r0, r3]
	b _0809F4CE
_0809F4C8:
	mov r0, r10
	movs r3, 0xE
	ldrsb r3, [r0, r3]
_0809F4CE:
	movs r0, 0x1
	negs r0, r0
	bl GroundObject_Add
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _0809F4E2
	bl _0809EAE0
_0809F4E2:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x5C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AC49C
	bl _0809EAE0
_0809F4FE:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r4, sp, 0x4C
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0x1C
	ldr r0, [sp, 0x10]
	add r1, sp, 0x28
	movs r3, 0
	strb r0, [r1]
	ldrb r2, [r4]
	mov r0, sp
	adds r0, 0x29
	strb r2, [r0]
	adds r0, 0x1
	movs r2, 0x1
	strb r2, [r0]
	adds r0, 0x1
	strb r2, [r0]
	str r3, [sp, 0x2C]
	ldr r3, _0809F55C
	ldr r2, [sp, 0xC]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, 0x8
	adds r0, r3
	ldr r0, [r0]
	str r0, [sp, 0x30]
	adds r0, r5, 0
	movs r2, 0xC
	bl memcpy
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	adds r1, r5, 0
	cmp r0, 0
	blt _0809F560
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	b _0809F566
	.align 2, 0
_0809F55C: .4byte gUnknown_812F1F8
_0809F560:
	mov r5, r10
	movs r0, 0xC
	ldrsh r2, [r5, r0]
_0809F566:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F578
	add r0, sp, 0x8
	movs r3, 0x1
	ldrsb r3, [r0, r3]
	b _0809F57E
_0809F578:
	mov r4, r10
	movs r3, 0xE
	ldrsb r3, [r4, r3]
_0809F57E:
	movs r0, 0x1
	negs r0, r0
	bl GroundEffect_Add
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _0809F592
	bl _0809EAE0
_0809F592:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	add r4, sp, 0x64
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AD3B4
	bl _0809EAE0
_0809F5AE:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	movs r1, 0x1
	bl GroundMap_ExecuteEvent
	bl _0809EAE0
_0809F5BE:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	b _0809F712
_0809F5C6:
	ldr r1, [sp, 0xC]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809F5D6
	lsls r0, r1, 16
	asrs r0, 16
	b _0809F5DC
_0809F5D6:
	ldr r0, _0809F5F0
	movs r3, 0
	ldrsh r0, [r0, r3]
_0809F5DC:
	adds r4, r0, 0
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809F5F4
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	b _0809F5FA
	.align 2, 0
_0809F5F0: .4byte gUnknown_2039A30
_0809F5F4:
	mov r0, r10
	movs r2, 0xC
	ldrsh r1, [r0, r2]
_0809F5FA:
	adds r6, r1, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _0809F60E
	add r0, sp, 0x8
	movs r5, 0x1
	ldrsb r5, [r0, r5]
	b _0809F614
_0809F60E:
	mov r3, r10
	movs r5, 0xE
	ldrsb r5, [r3, r5]
_0809F614:
	adds r0, r4, 0
	bl sub_80A4D7C
	lsls r0, 16
	asrs r4, r0, 16
	movs r3, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x1E
	bne _0809F62A
	movs r3, 0x1
_0809F62A:
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl GroundMap_ExecuteStation
	ldr r1, _0809F65C
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r4
	bne _0809F642
	bl _0809EAE0
_0809F642:
	strh r4, [r1]
	bl sub_809D940
	mov r1, r9
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809F656
	bl _0809EAE0
_0809F656:
	bl _080A142C
	.align 2, 0
_0809F65C: .4byte gUnknown_2039A34
_0809F660:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_80A2608
	adds r5, r0, 0
	lsls r2, r4, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x30
	bl sub_8001784
	cmp r0, 0
	bne _0809F68A
	movs r3, 0x6
	ldrsh r5, [r5, r3]
	b _0809F68E
_0809F68A:
	movs r0, 0x8
	ldrsh r5, [r5, r0]
_0809F68E:
	adds r0, r4, 0
	subs r0, 0x37
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x10
	bls _0809F6DC
	adds r0, r4, 0
	bl sub_80A2750
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _0809F6DC
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _0809F6D8
	movs r0, 0x1
	bl sub_8011BA4
	lsls r0, 24
	cmp r0, 0
	beq _0809F6C6
	ldr r1, _0809F6D4
	movs r0, 0x1
	adds r2, r4, 0
	bl Log
_0809F6C6:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8098E18
	bl _0809EAE0
	.align 2, 0
_0809F6D4: .4byte gUnknown_8116684
_0809F6D8:
	adds r0, r5, 0
	b _0809F712
_0809F6DC:
	movs r1, 0x1
	negs r1, r1
	adds r0, r4, 0
	bl sub_8098E18
	bl _0809EAE0
_0809F6EA:
	mov r1, r9
	movs r2, 0xC
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _0809F71C
	cmp r0, 0x1
	bgt _0809F700
	cmp r0, 0
	beq _0809F70C
	bl _0809EAE0
_0809F700:
	cmp r0, 0x2
	beq _0809F73E
	cmp r0, 0x3
	beq _0809F762
	bl _0809EAE0
_0809F70C:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
_0809F712:
	movs r1, 0
	bl GroundMap_ExecuteEvent
	bl _0809EAE0
_0809F71C:
	add r4, sp, 0x1C
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r1, r9
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundLives_ExecuteScript
	bl _0809EAE0
_0809F73E:
	add r4, sp, 0x28
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r5, r9
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	mov r1, r9
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundObject_ExecuteScript
	bl _0809EAE0
_0809F762:
	add r4, sp, 0x34
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	mov r0, r9
	adds r1, r4, 0
	bl sub_809D710
	mov r5, r9
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	mov r1, r9
	adds r1, 0x8
	adds r2, r4, 0
	bl GroundEffect_ExecuteScript
	bl _0809EAE0
_0809F786:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	cmp r0, 0
	bge _0809F79E
	bl _0809EAE0
_0809F79E:
	add r1, sp, 0x6C
	bl sub_80A8BD8
	ldr r0, [sp, 0x6C]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _0809F818
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r7, sp, 0x70
	ldr r2, [r1, 0xC]
	adds r1, r7, 0
	bl _call_via_r2
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r5, sp, 0x78
	ldr r2, [r1, 0x8]
	adds r1, r5, 0
	bl _call_via_r2
	add r6, sp, 0x80
	mov r0, r8
	adds r1, r6, 0
	bl sub_80A8FD8
	add r4, sp, 0x88
	mov r0, r8
	adds r1, r4, 0
	bl sub_80A8F9C
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r7, 0
	adds r3, r5, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	adds r4, r1, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809F812
	ldr r3, _0809F82C
	adds r0, r7, 0
	adds r1, r3, 0
	adds r2, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, r4
	beq _0809F818
_0809F812:
	mov r0, r8
	bl sub_80A9090
_0809F818:
	mov r4, r9
	movs r5, 0xA
	ldrsh r0, [r4, r5]
	mov r1, r8
	bl GroundLives_ExecutePlayerScriptActionLives
	movs r0, 0x3
	bl _080A142E
	.align 2, 0
_0809F82C: .4byte gUnknown_81164DC
_0809F830:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	bl sub_80999E8
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F842:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80999FC
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F854:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	lsrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	lsrs r2, 16
	bl sub_8099A10
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F872:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_8099A34
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F884:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_8099A48
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F896:
	ldr r0, [sp, 0x10]
	asrs r0, 16
	add r1, sp, 0x20
	movs r2, 0
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	asrs r0, 8
	adds r1, 0x1
	strb r0, [r1]
	ldr r1, [sp, 0x10]
	mov r0, sp
	adds r0, 0x22
	strb r1, [r0]
	adds r0, 0x1
	strb r2, [r0]
	ldr r2, [sp, 0x20]
	str r2, [sp, 0x1C]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x27
	beq _0809F8C6
	cmp r0, 0x28
	beq _0809F8D4
	b _0809F8E0
_0809F8C6:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	bl sub_8099A5C
	b _0809F8E0
_0809F8D4:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	bl sub_8099AFC
_0809F8E0:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A130C
_0809F8E8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	bl sub_809A6E4
	bl _0809EAE0
_0809F8F4:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	bl sub_809A6F8
	bl _0809EAE0
_0809F900:
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x10]
	bl sub_809A738
	bl _0809EAE0
_0809F90C:
	bl sub_809A768
	lsls r0, 24
	cmp r0, 0
	bne _0809F91A
	bl _0809EAE0
_0809F91A:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809F92E:
	bl sub_809A76C
	bl _0809EAE0
_0809F936:
	bl sub_809A7B4
	bl _0809EAE0
_0809F93E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0xA
	bls _0809F94A
	bl _0809EAE0
_0809F94A:
	lsls r0, 2
	ldr r1, _0809F954
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809F954: .4byte _0809F958
	.align 2, 0
_0809F958:
	.4byte _0809F984
	.4byte _0809F992
	.4byte _0809F9A4
	.4byte _0809F9B6
	.4byte _0809F9D8
	.4byte _0809F9EA
	.4byte _0809F9FC
	.4byte _0809FA44
	.4byte _0809FA56
	.4byte _0809FA68
	.4byte _0809FAB0
_0809F984:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_809A83C
	bl _0809EAE0
_0809F992:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A2500
	bl _0809EAE0
_0809F9A4:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A2500
	bl _0809EAE0
_0809F9B6:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	add r1, sp, 0x90
	lsls r0, 16
	movs r2, 0x1
	orrs r0, r2
	str r0, [r1]
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	bl sub_80A2500
	bl _0809EAE0
_0809F9D8:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A252C
	bl _0809EAE0
_0809F9EA:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A252C
	bl _0809EAE0
_0809F9FC:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	add r1, sp, 0x94
	ldrh r2, [r1]
	orrs r2, r0
	str r2, [r1]
	cmp r2, 0
	blt _0809FA30
	ldr r0, _0809FA2C
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	str r2, [r1]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_80A252C
	bl _0809EAE0
	.align 2, 0
_0809FA2C: .4byte 0xffff0000
_0809FA30:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_80A2584
	bl _0809EAE0
_0809FA44:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	mov r1, r9
	adds r1, 0x8
	bl sub_80A2558
	bl _0809EAE0
_0809FA56:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r1, r9
	adds r1, 0xC
	bl sub_80A2558
	bl _0809EAE0
_0809FA68:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	add r1, sp, 0x98
	ldrh r2, [r1]
	orrs r2, r0
	str r2, [r1]
	cmp r2, 0
	blt _0809FA9C
	ldr r0, _0809FA98
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	str r2, [r1]
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	bl sub_80A2558
	bl _0809EAE0
	.align 2, 0
_0809FA98: .4byte 0xffff0000
_0809FA9C:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_80A2598
	bl _0809EAE0
_0809FAB0:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2740
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	beq _0809FAD0
	cmp r0, 0x2
	beq _0809FAD4
	b _0809FAD8
_0809FAD0:
	movs r4, 0x1
	b _0809FAD8
_0809FAD4:
	movs r4, 0x1
	negs r4, r4
_0809FAD8:
	adds r0, r1, 0
	bl sub_8090298
	ldr r2, _0809FAF4
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	lsls r1, 2
	adds r1, r2
	adds r0, r4
	str r0, [r1]
	bl _0809EAE0
	.align 2, 0
_0809FAF4: .4byte gUnknown_202DE30
_0809FAF8:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	asrs r1, 24
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl sub_809AC7C
	bl _0809EAE0
_0809FB10:
	ldr r0, [sp, 0xC]
	add r1, sp, 0x9C
	str r0, [r1]
	ldr r0, [sp, 0x10]
	str r0, [r1, 0x4]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_809ADD8
	bl _0809EAE0
_0809FB28:
	movs r1, 0
	ldrb r0, [r2]
	subs r0, 0x32
	cmp r0, 0x6
	bhi _0809FBBE
	lsls r0, 2
	ldr r1, _0809FB3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809FB3C: .4byte _0809FB40
	.align 2, 0
_0809FB40:
	.4byte _0809FB5C
	.4byte _0809FB6C
	.4byte _0809FB7C
	.4byte _0809FB8C
	.4byte _0809FB9C
	.4byte _0809FBAC
	.4byte _0809FBB4
_0809FB5C:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0x14]
	movs r0, 0
	bl sub_809AE90
	b _0809FBBA
_0809FB6C:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	ldr r2, [sp, 0x14]
	movs r0, 0x1
	bl sub_809AE90
	b _0809FBBA
_0809FB7C:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	ldr r2, [sp, 0x14]
	movs r0, 0x2
	bl sub_809AE90
	b _0809FBBA
_0809FB8C:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	ldr r2, [sp, 0x14]
	movs r0, 0x3
	bl sub_809AE90
	b _0809FBBA
_0809FB9C:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0x14]
	movs r0, 0x4
	bl sub_809AE90
	b _0809FBBA
_0809FBAC:
	ldr r0, [sp, 0x14]
	bl sub_809AEEC
	b _0809FBBA
_0809FBB4:
	ldr r0, [sp, 0x14]
	bl sub_809AF2C
_0809FBBA:
	lsls r0, 24
	lsrs r1, r0, 24
_0809FBBE:
	cmp r1, 0
	bne _0809FBC6
	bl _0809EAE0
_0809FBC6:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809FBDA:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0x14]
	bl sub_809AF6C
	lsls r0, 24
	cmp r0, 0
	bne _0809FBF0
	bl _0809EAE0
_0809FBF0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _0809FBFE
	bl _0809EAE0
_0809FBFE:
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	mov r0, r9
	movs r1, 0
	bl sub_809D8EC
	bl _080A130A
_0809FC12:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	lsls r2, 16
	asrs r2, 16
	ldr r3, [sp, 0x14]
	bl sub_809AFC8
	bl _080A1280
_0809FC2E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	ldr r3, [sp, 0x14]
	bl sub_809B1D4
	bl _080A1292
_0809FC40:
	movs r0, 0
	bl _080A0654
_0809FC46:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809FC90
	adds r0, r1, 0
	bl sub_80A8D54
	cmp r0, 0
	bne _0809FC62
	bl _0809EAE0
_0809FC62:
	movs r3, 0
	ldr r2, _0809FC8C
	adds r5, r2, 0
	adds r4, r0, 0
	adds r4, 0x4C
_0809FC6C:
	adds r0, r3, r5
	adds r1, r4, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _0809FC6C
	movs r0, 0
	strb r0, [r2, 0xA]
	movs r0, 0x4
	movs r1, 0
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FC8C: .4byte gUnknown_2039D98
_0809FC90:
	ldr r2, _0809FCA0
	movs r0, 0x4
	movs r1, 0x1
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCA0: .4byte gUnknown_2039D98
_0809FCA4:
	ldr r4, _0809FCC0
	adds r0, r4, 0
	bl sub_80920B8
	movs r0, 0
	strb r0, [r4, 0xA]
	movs r0, 0x5
	movs r1, 0
	adds r2, r4, 0
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCC0: .4byte gUnknown_2039D98
_0809FCC4:
	ldr r2, _0809FCE4
	adds r3, r2, 0
	movs r1, 0
	adds r0, r2, 0
	adds r0, 0xB
_0809FCCE:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r3
	bge _0809FCCE
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	movs r0, 0x6
	bl sub_809B1C0
	bl _080A1292
	.align 2, 0
_0809FCE4: .4byte gUnknown_2039D98
_0809FCE8:
	bl sub_80118A4
	bl _0809EAE0
_0809FCF0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FD00
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _0809FD02
_0809FD00:
	movs r0, 0x1E
_0809FD02:
	bl sub_80118C4
	bl _0809EAE0
_0809FD0A:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD1E
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD20
_0809FD1E:
	ldr r0, [sp, 0xC]
_0809FD20:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _0809FD34
	cmp r1, r0
	beq _0809FDA0
	adds r0, r1, 0
	bl sub_80118F0
	bl _0809EAE0
	.align 2, 0
_0809FD34: .4byte 0x000003e7
_0809FD38:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD4C
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD4E
_0809FD4C:
	ldr r0, [sp, 0xC]
_0809FD4E:
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, _0809FD68
	cmp r2, r0
	beq _0809FDA0
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	adds r0, r2, 0
	bl sub_8011900
	bl _0809EAE0
	.align 2, 0
_0809FD68: .4byte 0x000003e7
_0809FD6C:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0809FD80
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_80A25AC
	b _0809FD82
_0809FD80:
	ldr r0, [sp, 0xC]
_0809FD82:
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _0809FD9C
	cmp r1, r0
	bne _0809FD90
	bl _0809EAE0
_0809FD90:
	adds r0, r1, 0
	bl sub_8011914
	bl _0809EAE0
	.align 2, 0
_0809FD9C: .4byte 0x000003e7
_0809FDA0:
	bl sub_8011924
	bl _0809EAE0
_0809FDA8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FDB8
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _0809FDBA
_0809FDB8:
	movs r0, 0x1E
_0809FDBA:
	bl sub_8011930
	bl _0809EAE0
_0809FDC2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_8011974
	bl _0809EAE0
_0809FDD4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r0, 16
	bl sub_801199C
	bl _0809EAE0
_0809FDE2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	lsrs r2, r0, 16
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _0809FDF8
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	b _0809FDFA
_0809FDF8:
	movs r1, 0x1E
_0809FDFA:
	adds r0, r2, 0
	bl sub_80119AC
	bl _0809EAE0
_0809FE04:
	mov r1, r9
	adds r1, 0x84
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, 0x1
	bne _0809FE16
	adds r0, r1, 0
	bl sub_809D568
_0809FE16:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x1C]
	movs r1, 0
	bl _call_via_r2
	bl _0809EAE0
_0809FE28:
	mov r0, r9
	adds r0, 0xC
	bl sub_809D52C
	adds r4, r0, 0
	cmp r4, 0
	bne _0809FE3A
	bl _0809EAE0
_0809FE3A:
	ldr r1, [r4]
	mov r2, r9
	ldr r0, [r2, 0x4]
	add r5, sp, 0xA4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r4]
	mov r3, r9
	ldr r0, [r3, 0x4]
	mov r4, sp
	adds r4, 0x4D
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldrb r0, [r4]
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r1, r9
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	movs r1, 0
	ldrsb r1, [r4, r1]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	bl _0809EAE0
_0809FE86:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r6, sp, 0xAC
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r4, sp, 0xB4
	add r5, sp, 0xBC
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80AD914
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r3, [r1, 0x20]
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	bl _0809EAE0
_0809FEBE:
	mov r1, r9
	ldr r2, [r1]
	ldr r0, [r1, 0x4]
	ldr r1, [sp, 0xC]
	ldr r2, [r2, 0x3C]
	bl _call_via_r2
	bl _0809EAE0
_0809FED0:
	ldr r0, [sp, 0xC]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0809FEEE
	mov r1, r9
	adds r1, 0x84
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _0809FEEE
	adds r0, r1, 0
	bl sub_809D568
_0809FEEE:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldr r1, [sp, 0xC]
	ldr r2, [r2, 0x40]
	bl _call_via_r2
	bl _0809EAE0
_0809FF00:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r9
	adds r1, 0x4A
	ldr r2, [r2, 0x14]
	bl _call_via_r2
	add r0, sp, 0x8
	ldrh r1, [r0, 0x2]
	cmp r1, 0
	beq _0809FF1E
	mov r0, r9
	adds r0, 0x48
	strh r1, [r0]
_0809FF1E:
	mov r5, r9
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	bl _0809EAE0
_0809FF32:
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	ldr r2, [r2, 0x34]
	bl _call_via_r2
	bl _0809EAE0
_0809FF46:
	mov r1, r9
	ldr r3, [r1]
	ldr r0, [r1, 0x4]
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	add r2, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r2, r4]
	ldr r3, [r3, 0x38]
	bl _call_via_r3
	bl _0809EAE0
_0809FF62:
	mov r5, r9
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	ldr r2, [r2, 0x44]
	bl _call_via_r2
	bl _0809EAE0
_0809FF78:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	add r1, sp, 0xC4
	str r0, [r1]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	str r0, [r1, 0x4]
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	ldr r2, [r2, 0x24]
	bl _call_via_r2
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	mov r5, r10
	b _080A05EA
_0809FF9A:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	lsls r0, 8
	add r1, sp, 0xCC
	str r0, [r1]
	ldr r0, [sp, 0xC]
	lsls r0, 8
	str r0, [r1, 0x4]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	b _080A0650
_0809FFBA:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl OtherRandomCapped
	lsls r0, 8
	add r4, sp, 0xD4
	str r0, [r4]
	ldr r0, [sp, 0xC]
	bl OtherRandomCapped
	lsls r0, 8
	str r0, [r4, 0x4]
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A07B4
_0809FFE4:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0xDC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A0650
_080A0010:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r6, sp, 0xE4
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	add r4, sp, 0xEC
	add r5, sp, 0xF4
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80AD914
	ldr r0, [r5]
	ldr r1, [r4]
	subs r0, r1
	bl OtherRandomCapped
	ldr r1, [r4]
	adds r1, r0
	str r1, [r6]
	ldr r0, [r5, 0x4]
	ldr r1, [r4, 0x4]
	subs r0, r1
	bl OtherRandomCapped
	ldr r1, [r4, 0x4]
	adds r1, r0
	str r1, [r6, 0x4]
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r6, 0
	bl _call_via_r2
	b _080A07B4
_080A0064:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A007A
	bl _0809EAE0
_080A007A:
	add r4, sp, 0xFC
	adds r1, r4, 0
	bl sub_80A8FD8
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r4, 0
	bl _call_via_r2
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	b _080A03F0
_080A0096:
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x32
	bl sub_8001784
	add r5, sp, 0x104
	str r0, [r5]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x33
	bl sub_8001784
	str r0, [r5, 0x4]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x34
	bl sub_8001784
	adds r6, r0, 0
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x35
	bl sub_8001784
	adds r4, r0, 0
	lsls r4, 24
	asrs r4, 24
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r2, [r1, 0x28]
	adds r1, r6, 0
	bl _call_via_r2
	mov r0, r9
	adds r0, 0x4A
	strb r4, [r0]
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r2, [r1, 0x2C]
	adds r1, r4, 0
	bl _call_via_r2
	b _080A0650
_080A010E:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r4, sp, 0x10C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r3, [r5]
	ldr r0, [r5, 0x4]
	add r1, sp, 0x114
	add r2, sp, 0x118
	ldr r3, [r3, 0x10]
	bl _call_via_r3
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r5, sp
	adds r5, 0x4E
	ldr r2, [r1, 0x14]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	add r0, sp, 0x10C
	ldr r3, [r0]
	movs r0, 0
	movs r1, 0x32
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	ldr r3, [r4, 0x4]
	movs r0, 0
	movs r1, 0x33
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	add r0, sp, 0x114
	ldr r3, [r0]
	movs r0, 0
	movs r1, 0x34
	bl sub_800199C
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	movs r3, 0
	ldrsb r3, [r5, r3]
	movs r0, 0
	movs r1, 0x35
	bl sub_800199C
	bl _0809EAE0
_080A0186:
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [sp, 0xC]
	lsls r1, 8
	ldr r2, [r2, 0x28]
	bl _call_via_r2
	b _080A07B4
_080A0198:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r2, r10
	str r0, [r2, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	str r0, [r2, 0x40]
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	str r0, [r2, 0x30]
	ldr r0, _080A01B4
	bl _080A12AE
	.align 2, 0
_080A01B4: .4byte 0x0000ffff
_080A01B8:
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x11C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r1, [sp, 0xC]
	lsls r1, 8
	add r0, sp, 0x11C
	ldr r0, [r0]
	adds r0, r1
	mov r5, r10
	str r0, [r5, 0x3C]
	ldr r1, [sp, 0x10]
	lsls r1, 8
	ldr r0, [r4, 0x4]
	adds r0, r1
	str r0, [r5, 0x40]
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r5, 0x30]
	ldr r0, _080A01EC
	b _080A05EA
	.align 2, 0
_080A01EC: .4byte 0x0000ffff
_080A01F0:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	mov r4, r10
	str r0, [r4, 0x30]
	ldr r0, _080A021C
	b _080A0656
	.align 2, 0
_080A021C: .4byte 0x0000ffff
_080A0220:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r2, r10
	str r0, [r2, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A12AE
_080A0250:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	mov r4, r10
	adds r4, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r5, r10
	str r0, [r5, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl OtherRandomCapped
	b _080A05EA
_080A0282:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A0298
	bl _0809EAE0
_080A0298:
	mov r1, r10
	adds r1, 0x3C
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r2, r10
	str r0, [r2, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	bl _080A12AE
_080A02B2:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r1, r0, 8
	mov r4, r10
	str r1, [r4, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r2, r0, 8
	str r2, [r4, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7D
	beq _080A02DC
	cmp r0, 0x83
	bne _080A0304
_080A02DC:
	mov r5, r10
	ldr r0, [r5, 0x34]
	subs r0, r1, r0
	ldr r1, [r5, 0x38]
	subs r1, r2, r1
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0300
	bl _0809F0C4
_080A0300:
	movs r0, 0x1
	b _080A05EA
_080A0304:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r3, r10
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A0310:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r5, r10
	ldr r4, [r5, 0x34]
	adds r3, r4, r0
	str r3, [r5, 0x3C]
	ldr r0, [sp, 0x10]
	lsls r0, 8
	ldr r2, [r5, 0x38]
	adds r1, r2, r0
	str r1, [r5, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7E
	beq _080A0342
	cmp r0, 0x84
	bne _080A036A
_080A0342:
	subs r0, r3, r4
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	mov r3, r10
	strh r0, [r3, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0362
	bl _0809F0C4
_080A0362:
	movs r0, 0x1
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A036A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A0654
_080A0370:
	ldr r4, [sp, 0xC]
	lsls r4, 1
	subs r4, 0x1
	ldr r5, [sp, 0x10]
	lsls r5, 1
	subs r5, 0x1
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	adds r0, r4, 0
	bl OtherRandomCapped
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	subs r0, r1
	lsls r0, 8
	mov r3, r10
	ldr r1, [r3, 0x34]
	adds r1, r0
	str r1, [r3, 0x3C]
	adds r0, r5, 0
	bl OtherRandomCapped
	ldr r1, [sp, 0xC]
	subs r0, r1
	lsls r0, 8
	mov r4, r10
	ldr r3, [r4, 0x38]
	adds r2, r3, r0
	str r2, [r4, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x7F
	beq _080A03C4
	cmp r0, 0x85
	bne _080A03EC
_080A03C4:
	mov r5, r10
	ldr r0, [r5, 0x3C]
	ldr r1, [r5, 0x34]
	subs r0, r1
	subs r1, r2, r3
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl __divsi3
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A03E8
	bl _0809F0C4
_080A03E8:
	movs r0, 0x1
	b _080A05EA
_080A03EC:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
_080A03F0:
	mov r3, r10
	strh r0, [r3, 0x2A]
	bl _0809F0C4
_080A03F8:
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	mov r5, r10
	ldr r0, [r5, 0x34]
	ldr r1, [r5, 0x38]
	mov r2, r10
	str r0, [r2, 0x3C]
	str r1, [r2, 0x40]
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	mov r1, r10
	adds r1, 0x3C
	bl sub_80AD8B4
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x80
	beq _080A042E
	cmp r0, 0x86
	bne _080A045C
_080A042E:
	mov r3, r10
	ldr r0, [r3, 0x3C]
	ldr r1, [r3, 0x34]
	subs r0, r1
	ldr r1, [r3, 0x40]
	ldr r2, [r3, 0x38]
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl __divsi3
	mov r5, r10
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0458
	bl _0809F0C4
_080A0458:
	movs r0, 0x1
	b _080A05EA
_080A045C:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A0462:
	ldr r4, [sp, 0xC]
	lsls r4, 1
	subs r4, 0x1
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r5, r10
	adds r5, 0x3C
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r0, [sp, 0x10]
	lsls r0, 16
	asrs r0, 16
	adds r1, r5, 0
	bl sub_80AD8B4
	adds r0, r4, 0
	bl OtherRandomCapped
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	subs r0, r1
	lsls r0, 8
	mov r5, r10
	ldr r1, [r5, 0x3C]
	adds r1, r0
	str r1, [r5, 0x3C]
	adds r0, r4, 0
	bl OtherRandomCapped
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	subs r0, r1
	lsls r0, 8
	ldr r1, [r5, 0x40]
	adds r2, r1, r0
	str r2, [r5, 0x40]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x81
	beq _080A04C0
	cmp r0, 0x87
	bne _080A04EC
_080A04C0:
	mov r3, r10
	ldr r0, [r3, 0x3C]
	ldr r1, [r3, 0x34]
	subs r0, r1
	ldr r1, [r3, 0x38]
	subs r1, r2, r1
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl __divsi3
	mov r5, r10
	strh r0, [r5, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A04E8
	bl _0809F0C4
_080A04E8:
	movs r0, 0x1
	b _080A05EA
_080A04EC:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A04F2:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	bge _080A0508
	bl _0809EAE0
_080A0508:
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	mov r1, r10
	adds r1, 0x34
	ldr r2, [r2, 0xC]
	bl _call_via_r2
	mov r1, r10
	adds r1, 0x3C
	adds r0, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x82
	beq _080A052E
	cmp r0, 0x88
	bne _080A055A
_080A052E:
	mov r4, r10
	ldr r0, [r4, 0x3C]
	ldr r1, [r4, 0x34]
	subs r0, r1
	ldr r1, [r4, 0x40]
	ldr r2, [r4, 0x38]
	subs r1, r2
	bl sub_8009FB8
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl __divsi3
	strh r0, [r4, 0x2A]
	lsls r0, 16
	cmp r0, 0
	ble _080A0556
	bl _0809F0C4
_080A0556:
	movs r0, 0x1
	b _080A0656
_080A055A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	b _080A07B8
_080A0560:
	ldr r0, [sp, 0xC]
	lsls r0, 8
	mov r2, r10
	str r0, [r2, 0x48]
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	str r0, [r2, 0x30]
	ldr r0, _080A0578
	bl _080A12AE
	.align 2, 0
_080A0578: .4byte 0x0000ffff
_080A057C:
	ldr r1, [sp, 0xC]
	mov r0, r9
	adds r0, 0x4A
	strb r1, [r0]
	mov r4, r9
	ldr r2, [r4]
	ldr r0, [r4, 0x4]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	mov r1, r10
	str r0, [r1, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	b _080A07BA
_080A05A4:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	mov r4, sp
	adds r4, 0x4F
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	mov r5, r10
	str r0, [r5, 0x30]
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A05EA:
	strh r0, [r5, 0x2A]
	bl _0809F0C4
_080A05F0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
_080A0600:
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	b _080A07B4
_080A060E:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080A0650
	add r4, sp, 0x50
	adds r1, r4, 0
	bl sub_80A9050
	movs r0, 0
	ldrsb r0, [r4, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_080A0650:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A0654:
	mov r4, r10
_080A0656:
	strh r0, [r4, 0x2A]
	bl _0809F0C4
_080A065C:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	mov r4, sp
	adds r4, 0x51
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	ldr r2, [r5]
	ldr r0, [r5, 0x4]
	b _080A0600
_080A068A:
	movs r5, 0
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0x8F
	beq _080A06CA
	cmp r0, 0x8F
	bgt _080A069E
	cmp r0, 0x8E
	beq _080A06A4
	b _080A0724
_080A069E:
	cmp r0, 0x90
	beq _080A06F8
	b _080A0724
_080A06A4:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _080A0724
	movs r5, 0x1
	add r1, sp, 0x124
	adds r0, r4, 0
	bl sub_80A8FD8
	add r1, sp, 0x12C
	adds r0, r4, 0
	bl sub_80A8F9C
	b _080A0724
_080A06CA:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _080A0724
	movs r5, 0x1
	add r1, sp, 0x124
	bl sub_80A8FD8
	ldr r0, _080A06F4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x12C
	str r0, [r2]
	str r1, [r2, 0x4]
	b _080A0724
	.align 2, 0
_080A06F4: .4byte gUnknown_81164DC
_080A06F8:
	movs r5, 0x1
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	add r4, sp, 0x124
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	mov r3, r9
	ldr r2, [r3]
	ldr r0, [r3, 0x4]
	add r1, sp, 0x12C
	ldr r2, [r2, 0x8]
	bl _call_via_r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
_080A0724:
	cmp r5, 0
	beq _080A07B4
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r5, sp, 0x134
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x13C
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r7, sp, 0x124
	add r3, sp, 0x12C
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_8002DF0
	mov r1, sp
	adds r1, 0x52
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	movs r4, 0
	ldrsb r4, [r1, r4]
	adds r6, r1, 0
	cmp r4, r0
	bne _080A078C
	ldr r3, _080A07C0
	adds r0, r5, 0
	adds r1, r3, 0
	adds r2, r7, 0
	bl sub_8002D54
	strb r0, [r6]
	movs r0, 0
	ldrsb r0, [r6, r0]
	cmp r0, r4
	bne _080A078C
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r2, [r1, 0x14]
	adds r1, r6, 0
	bl _call_via_r2
_080A078C:
	movs r0, 0
	ldrsb r0, [r6, r0]
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x4A
	strb r0, [r1]
	mov r0, r9
	ldr r2, [r0]
	ldr r0, [r0, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_080A07B4:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
_080A07B8:
	mov r1, r10
_080A07BA:
	strh r0, [r1, 0x2A]
	bl _0809F0C4
	.align 2, 0
_080A07C0: .4byte gUnknown_81164DC
_080A07C4:
	movs r0, 0
	bl _080A12AC
_080A07CA:
	ldr r0, [sp, 0xC]
	mov r1, r9
	adds r1, 0x71
	movs r2, 0
	strb r0, [r1]
	mov r3, r10
	strh r2, [r3, 0x2A]
	bl _0809F0C4
_080A07DC:
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	mov r4, sp
	adds r4, 0x53
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r0, 0
	ldrsb r0, [r4, r0]
	ldr r1, [sp, 0xC]
	lsls r1, 24
	lsrs r1, 24
	bl sub_8002984
	mov r1, r9
	adds r1, 0x71
	movs r2, 0
	strb r0, [r1]
	mov r5, r10
	strh r2, [r5, 0x2A]
	bl _0809F0C4
_080A080C:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_809D124
	bl _0809EAE0
_080A081E:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	mov r3, r9
	movs r4, 0x8
	ldrsh r0, [r3, r4]
	cmp r0, 0x2
	beq _080A0856
	cmp r0, 0x2
	bgt _080A0844
	cmp r0, 0x1
	beq _080A084C
	bl _0809EAE0
_080A0844:
	cmp r0, 0x3
	beq _080A0860
	bl _0809EAE0
_080A084C:
	movs r0, 0x1
	bl sub_809D170
	bl _0809EAE0
_080A0856:
	movs r0, 0x2
	bl sub_809D170
	bl _0809EAE0
_080A0860:
	movs r0, 0x3
	bl sub_809D170
	bl _0809EAE0
_080A086A:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x8
	ldrsh r1, [r5, r2]
	cmp r1, 0x2
	beq _080A08A0
	cmp r1, 0x2
	bgt _080A088E
	cmp r1, 0x1
	beq _080A0896
	bl _0809EAE0
_080A088E:
	cmp r1, 0x3
	beq _080A08AA
	bl _0809EAE0
_080A0896:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80A8FD8
	b _080A08B2
_080A08A0:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80AC448
	b _080A08B2
_080A08AA:
	add r4, sp, 0x144
	adds r1, r4, 0
	bl sub_80AD360
_080A08B2:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D158
	bl _0809EAE0
_080A08BE:
	movs r0, 0x1
	movs r1, 0
	bl sub_809D170
	bl _0809EAE0
_080A08CA:
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A08E2
	bl _0809EAE0
_080A08E2:
	mov r4, r9
	movs r5, 0x8
	ldrsh r0, [r4, r5]
	cmp r0, 0x2
	beq _080A090A
	cmp r0, 0x2
	bgt _080A08F8
	cmp r0, 0x1
	beq _080A0900
	bl _0809EAE0
_080A08F8:
	cmp r0, 0x3
	beq _080A0914
	bl _0809EAE0
_080A0900:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0990
_080A090A:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0990
_080A0914:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0990
_080A091E:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A095C
	cmp r1, 0x2
	bgt _080A0944
	cmp r1, 0x1
	beq _080A094C
	bl _0809EAE0
_080A0944:
	cmp r1, 0x3
	beq _080A096C
	bl _0809EAE0
_080A094C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A097A
_080A095C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A097A
_080A096C:
	add r4, sp, 0x14C
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A097A:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D190
	bl _0809F0C4
_080A0986:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0990:
	bl sub_809D1A8
	bl _0809F0C4
_080A0998:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A09B0
	bl _0809EAE0
_080A09B0:
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r0, 0x2
	beq _080A09D6
	cmp r0, 0x2
	bgt _080A09C4
	cmp r0, 0x1
	beq _080A09CC
	bl _0809EAE0
_080A09C4:
	cmp r0, 0x3
	beq _080A09E0
	bl _0809EAE0
_080A09CC:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0A5C
_080A09D6:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0A5C
_080A09E0:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0A5C
_080A09EA:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A0A28
	cmp r1, 0x2
	bgt _080A0A10
	cmp r1, 0x1
	beq _080A0A18
	bl _0809EAE0
_080A0A10:
	cmp r1, 0x3
	beq _080A0A38
	bl _0809EAE0
_080A0A18:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A0A46
_080A0A28:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A0A46
_080A0A38:
	add r4, sp, 0x154
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A0A46:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D1CC
	bl _0809F0C4
_080A0A52:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0A5C:
	bl sub_809D1E4
	bl _0809F0C4
_080A0A64:
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bge _080A0A7C
	bl _0809EAE0
_080A0A7C:
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r0, 0x2
	beq _080A0AA2
	cmp r0, 0x2
	bgt _080A0A90
	cmp r0, 0x1
	beq _080A0A98
	bl _0809EAE0
_080A0A90:
	cmp r0, 0x3
	beq _080A0AAC
	bl _0809EAE0
_080A0A98:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	movs r0, 0x1
	b _080A0B28
_080A0AA2:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x2
	b _080A0B28
_080A0AAC:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0x3
	b _080A0B28
_080A0AB6:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	ldr r1, [r1, 0x4]
	bl _call_via_r1
	lsls r0, 16
	asrs r0, 16
	mov r2, r9
	movs r3, 0x8
	ldrsh r1, [r2, r3]
	cmp r1, 0x2
	beq _080A0AF4
	cmp r1, 0x2
	bgt _080A0ADC
	cmp r1, 0x1
	beq _080A0AE4
	bl _0809EAE0
_080A0ADC:
	cmp r1, 0x3
	beq _080A0B04
	bl _0809EAE0
_080A0AE4:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80A8FD8
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	b _080A0B12
_080A0AF4:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80AC448
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r2, [r0, r1]
	b _080A0B12
_080A0B04:
	add r4, sp, 0x15C
	adds r1, r4, 0
	bl sub_80AD360
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
_080A0B12:
	movs r0, 0
	adds r1, r4, 0
	bl sub_809D208
	bl _0809F0C4
_080A0B1E:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0x1
	movs r1, 0
_080A0B28:
	bl sub_809D220
	bl _0809F0C4
_080A0B30:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl sub_8001570
	bl _0809EAE0
_080A0B42:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_80015C0
	bl _0809EAE0
_080A0B54:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	ldr r2, [sp, 0xC]
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_800226C
	bl _0809EAE0
_080A0B6C:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	asrs r2, 16
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_80022A0
	bl _0809EAE0
_080A0B88:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	ldr r2, [sp, 0xC]
	lsls r2, 16
	lsrs r2, 16
	ldr r3, [sp, 0x10]
	bl sub_800199C
	bl _0809EAE0
_080A0BA2:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001BB4
	bl _0809EAE0
_080A0BB4:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	add r1, sp, 0x164
	add r2, sp, 0x168
	bl sub_8001B88
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r1, sp, 0x164
	ldr r1, [r1]
	add r2, sp, 0x168
	ldr r2, [r2]
	adds r2, 0x1
	bl sub_8001BB4
	bl _0809EAE0
_080A0BDA:
	ldr r2, [sp, 0xC]
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	movs r0, 0
	movs r1, 0x16
	bl sub_80018D8
	bl _0809EAE0
_080A0BF6:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r2, [r0, r5]
	movs r0, 0
	movs r1, 0x1C
	bl sub_80018D8
	bl _0809EAE0
_080A0C08:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80026E8
	bl _0809EAE0
_080A0C20:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_809733C
	bl _0809EAE0
_080A0C38:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80973A8
	bl _0809EAE0
_080A0C50:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_8097418
	bl _0809EAE0
_080A0C68:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	add r1, sp, 0x8
	ldrb r2, [r1, 0x1]
	negs r1, r2
	orrs r1, r2
	lsrs r1, 31
	bl sub_80975A8
	bl _0809EAE0
_080A0C80:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80976F8
	bl _0809EAE0
_080A0C90:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	ldr r2, [sp, 0xC]
	movs r0, 0
	movs r3, 0x2
	bl sub_80022F8
	b _080A0E1E
_080A0CA2:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_80022F8
	lsls r0, 24
	cmp r0, 0
	bne _080A0CC0
	bl _0809EAE0
_080A0CC0:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _080A0D5C
_080A0CC8:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	asrs r2, 16
	add r3, sp, 0x8
	ldrb r3, [r3, 0x1]
	bl sub_8002318
	lsls r0, 24
	cmp r0, 0
	bne _080A0CEA
	bl _0809EAE0
_080A0CEA:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	b _080A0E2C
_080A0CF2:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [sp, 0x10]
	lsls r2, 16
	lsrs r2, 16
	bl sub_8001784
	cmp r0, 0
	bne _080A0D0E
	bl _0809EAE0
_080A0D0E:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _080A0D5C
_080A0D16:
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	bl sub_8001AB0
	ldr r1, [sp, 0x10]
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	bne _080A0D38
	bl _0809EAE0
_080A0D38:
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	b _080A0E2C
_080A0D40:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r0, [r0, r4]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _080A0D58
	bl _0809EAE0
_080A0D58:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
_080A0D5C:
	mov r0, r9
	bl sub_80A242C
	mov r5, r10
	str r0, [r5, 0x4]
	bl _0809EAE0
_080A0D6A:
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001D08
	b _080A0DBA
_080A0D7A:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x10]
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	bne _080A0D92
	bl _0809EAE0
_080A0D92:
	b _080A0DF6
_080A0D94:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A0DA8
	bl _0809EAE0
_080A0DA8:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	b _080A132A
_080A0DAE:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8098100
_080A0DBA:
	lsls r0, 24
	cmp r0, 0
	bne _080A0DC4
	bl _0809EAE0
_080A0DC4:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	mov r0, r9
	bl sub_80A242C
	mov r2, r10
	str r0, [r2, 0x4]
	bl _0809EAE0
_080A0DD6:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80026CC
	b _080A0E1E
_080A0DE2:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_809CBA4
	cmp r0, 0
	bgt _080A0DF6
	bl _0809EAE0
_080A0DF6:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
	mov r0, r9
	bl sub_80A242C
	mov r4, r10
	str r0, [r4, 0x4]
	bl _0809EAE0
_080A0E08:
	mov r5, r9
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	beq _080A0E16
	bl _0809EAE0
_080A0E16:
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	bl sub_80A8C98
_080A0E1E:
	lsls r0, 24
	cmp r0, 0
	bne _080A0E28
	bl _0809EAE0
_080A0E28:
	add r0, sp, 0x8
	ldrb r1, [r0, 0x1]
_080A0E2C:
	mov r0, r9
	bl sub_80A242C
	mov r3, r10
	str r0, [r3, 0x4]
	bl _0809EAE0
_080A0E3A:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl sub_8091130
	cmp r0, 0
	bge _080A0E4E
	bl _0809EAE0
_080A0E4E:
	bl sub_80911F8
	bl _0809EAE0
_080A0E56:
	add r0, sp, 0x8
	ldrb r2, [r0]
	adds r0, r2, 0
	subs r0, 0xC0
	cmp r0, 0xB
	bls _080A0E64
	b _080A1088
_080A0E64:
	lsls r0, 2
	ldr r1, _080A0E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0E70: .4byte _080A0E74
	.align 2, 0
_080A0E74:
	.4byte _080A0EA4
	.4byte _080A0EB6
	.4byte _080A0ECC
	.4byte _080A0EFA
	.4byte _080A0F08
	.4byte _080A0F14
	.4byte _080A0F26
	.4byte _080A0F36
	.4byte _080A0F98
	.4byte _080A1008
	.4byte _080A0F4C
	.4byte _080A107A
_080A0EA4:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r1, r4]
	bl sub_8001658
	adds r1, r0, 0
	b _080A1098
_080A0EB6:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r1, r5]
	bl sub_8001658
	ldr r1, [sp, 0xC]
	add r2, sp, 0x8
	ldrb r2, [r2, 0x1]
	b _080A0EF2
_080A0ECC:
	mov r4, r10
	adds r4, 0x50
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_8001658
	adds r5, r0, 0
	ldr r1, [sp, 0xC]
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8001658
	adds r1, r0, 0
	add r0, sp, 0x8
	ldrb r2, [r0, 0x1]
	adds r0, r5, 0
_080A0EF2:
	bl FlagCalc
	adds r1, r0, 0
	b _080A1098
_080A0EFA:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	bl OtherRandomCapped
	adds r1, r0, 0
	b _080A1098
_080A0F08:
	add r0, sp, 0x8
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	movs r0, 0
	movs r2, 0
	b _080A0F1E
_080A0F14:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	movs r0, 0
	movs r2, 0x1
_080A0F1E:
	bl sub_8001784
	adds r1, r0, 0
	b _080A1098
_080A0F26:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A8C2C
	lsls r0, 16
	asrs r1, r0, 16
	b _080A1098
_080A0F36:
	mov r0, r9
	ldr r1, [r0]
	ldr r0, [r0, 0x4]
	add r4, sp, 0x54
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0
	ldrsb r1, [r4, r1]
	b _080A1098
_080A0F4C:
	mov r2, r9
	ldr r1, [r2]
	ldr r0, [r2, 0x4]
	movs r3, 0xB6
	lsls r3, 1
	add r3, sp
	mov r8, r3
	ldr r2, [r1, 0xC]
	mov r1, r8
	bl _call_via_r2
	add r6, sp, 0x16C
	ldr r0, [r6]
	ldr r1, [r6, 0x4]
	add r4, sp, 0x174
	str r0, [r4]
	str r1, [r4, 0x4]
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	adds r5, r4, 0
	adds r1, r5, 0
	bl sub_80AD8B4
	ldr r1, [r4]
	ldr r0, [r6]
	subs r1, r0
	add r0, sp, 0x17C
	str r1, [r0]
	ldr r1, [r5, 0x4]
	mov r4, r8
	ldr r0, [r4, 0x4]
	subs r1, r0
	add r0, sp, 0x17C
	str r1, [r0, 0x4]
	bl sub_8002C60
	b _080A106A
_080A0F98:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r6, r0, 16
	cmp r6, 0
	blt _080A1074
	mov r5, r9
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	movs r2, 0xC2
	lsls r2, 1
	add r2, sp
	mov r8, r2
	ldr r2, [r1, 0xC]
	mov r1, r8
	bl _call_via_r2
	ldr r1, [r5]
	ldr r0, [r5, 0x4]
	add r5, sp, 0x18C
	ldr r2, [r1, 0x8]
	adds r1, r5, 0
	bl _call_via_r2
	add r7, sp, 0x194
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80A8FD8
	add r4, sp, 0x19C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80A8F9C
	mov r0, r8
	adds r1, r5, 0
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A1098
	ldr r3, _080A1004
	mov r0, r8
	adds r1, r3, 0
	adds r2, r7, 0
	b _080A1066
	.align 2, 0
_080A1004: .4byte gUnknown_81164DC
_080A1008:
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r7, r0, 16
	cmp r7, 0
	blt _080A1074
	mov r3, r9
	ldr r1, [r3]
	ldr r0, [r3, 0x4]
	add r6, sp, 0x1A4
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	mov r4, r9
	ldr r1, [r4]
	ldr r0, [r4, 0x4]
	add r4, sp, 0x1AC
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0x1B4
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80A8FD8
	ldr r7, _080A1070
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r7, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080A1098
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	adds r3, r7, 0
_080A1066:
	bl sub_8002D54
_080A106A:
	lsls r0, 24
	asrs r1, r0, 24
	b _080A1098
	.align 2, 0
_080A1070: .4byte gUnknown_81164DC
_080A1074:
	movs r1, 0x1
	negs r1, r1
	b _080A1098
_080A107A:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_809CC90
	adds r1, r0, 0
	b _080A1098
_080A1088:
	ldr r0, _080A1090
	ldr r1, _080A1094
	bl FatalError
	.align 2, 0
_080A1090: .4byte gUnknown_81166B4
_080A1094: .4byte gUnknown_81166C0
_080A1098:
	mov r0, r9
	bl sub_80A2460
	b _080A1330
_080A10A0:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_8001658
	adds r2, r0, 0
	mov r3, r10
	strh r2, [r3, 0x28]
	ldr r1, [r3, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _080A10DE
	lsls r0, r2, 16
	asrs r3, r0, 16
_080A10C0:
	adds r2, r1, 0
	movs r4, 0x2
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080A10CE
	bl _0809F0C4
_080A10CE:
	adds r0, r1, 0
	adds r0, 0x10
	mov r5, r10
	str r0, [r5, 0x4]
	adds r1, r0, 0
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD0
	beq _080A10C0
_080A10DE:
	mov r1, r10
	ldr r0, [r1, 0x4]
	ldrb r0, [r0]
	cmp r0, 0xD1
	beq _080A10EC
	bl _0809EAE0
_080A10EC:
	ldr r0, _080A10F4
	strh r0, [r1, 0x28]
	bl _0809F0C4
	.align 2, 0
_080A10F4: .4byte 0x0000ffff
_080A10F8:
	ldr r7, [sp, 0x14]
	ldr r1, _080A11F0
	movs r0, 0
	str r0, [r1]
	mov r2, r10
	strh r0, [r2, 0x28]
	add r0, sp, 0x8
	ldrb r0, [r0]
	cmp r0, 0xD8
	bgt _080A1176
	cmp r0, 0xD6
	blt _080A1176
	mov r0, r10
	adds r0, 0x50
	ldr r1, [sp, 0x10]
	lsls r1, 16
	asrs r1, 16
	bl sub_8001658
	adds r3, r0, 0
	mov r4, r10
	ldr r1, [r4, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _080A114E
_080A112A:
	adds r2, r1, 0
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	cmp r0, r3
	bne _080A1136
	ldr r7, [r2, 0xC]
_080A1136:
	adds r0, r1, 0
	adds r0, 0x10
	mov r1, r10
	str r0, [r1, 0x4]
	ldrh r1, [r1, 0x28]
	adds r1, 0x1
	mov r4, r10
	strh r1, [r4, 0x28]
	adds r1, r0, 0
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD0
	beq _080A112A
_080A114E:
	mov r5, r10
	ldr r1, [r5, 0x4]
	ldrb r0, [r1]
	cmp r0, 0xD1
	bne _080A1176
_080A1158:
	cmp r7, 0
	bne _080A115E
	ldr r7, [r1, 0xC]
_080A115E:
	mov r0, r10
	ldr r2, [r0, 0x4]
	adds r1, r2, 0
	adds r1, 0x10
	str r1, [r0, 0x4]
	ldrh r0, [r0, 0x28]
	adds r0, 0x1
	mov r3, r10
	strh r0, [r3, 0x28]
	ldrb r0, [r2, 0x10]
	cmp r0, 0xD1
	beq _080A1158
_080A1176:
	cmp r7, 0
	bne _080A117C
	ldr r7, _080A11F4
_080A117C:
	mov r4, r10
	ldr r5, [r4, 0x4]
	ldrb r0, [r5]
	cmp r0, 0xD9
	bne _080A11B8
	ldr r0, _080A11F8
	mov r8, r0
	ldr r6, _080A11F0
	movs r1, 0x4
	add r1, r8
	mov r12, r1
_080A1192:
	ldr r1, [r6]
	lsls r2, r1, 3
	mov r4, r8
	adds r3, r2, r4
	adds r4, r5, 0
	ldr r0, [r4, 0xC]
	str r0, [r3]
	add r2, r12
	adds r1, 0x1
	str r1, [r2]
	str r1, [r6]
	adds r0, r4, 0
	adds r0, 0x10
	mov r5, r10
	str r0, [r5, 0x4]
	adds r5, r0, 0
	ldrb r0, [r4, 0x10]
	cmp r0, 0xD9
	beq _080A1192
_080A11B8:
	ldr r0, _080A11F0
	ldr r1, [r0]
	cmp r1, 0
	bgt _080A11C4
	bl _0809EAE0
_080A11C4:
	ldr r3, _080A11F8
	lsls r2, r1, 3
	adds r1, r2, r3
	movs r0, 0
	str r0, [r1]
	adds r0, r3, 0x4
	adds r2, r0
	add r0, sp, 0x8
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	str r0, [r2]
	add r0, sp, 0x8
	ldrb r0, [r0]
	subs r0, 0xD2
	cmp r0, 0x6
	bhi _080A1280
	lsls r0, 2
	ldr r1, _080A11FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A11F0: .4byte gUnknown_203B4AC
_080A11F4: .4byte gUnknown_81166D8
_080A11F8: .4byte gUnknown_2039D50
_080A11FC: .4byte _080A1200
	.align 2, 0
_080A1200:
	.4byte _080A121C
	.4byte _080A121C
	.4byte _080A123E
	.4byte _080A1260
	.4byte _080A121C
	.4byte _080A123E
	.4byte _080A1260
_080A121C:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0
	bl sub_809B028
	b _080A1280
_080A123E:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0x1
	bl sub_809B028
	b _080A1280
_080A1260:
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	movs r2, 0x1
	negs r2, r2
	ldr r0, [sp, 0xC]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	str r7, [sp, 0x4]
	adds r0, r3, 0
	movs r3, 0x2
	bl sub_809B028
_080A1280:
	mov r0, r9
	movs r1, 0x1
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	bne _080A1292
	bl _0809EAE0
_080A1292:
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	bl _0809F0C4
_080A129E:
	mov r0, r9
	movs r1, 0x1
	bl sub_809D8EC
	b _080A130A
_080A12A8:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
_080A12AC:
	mov r2, r10
_080A12AE:
	strh r0, [r2, 0x2A]
	bl _0809F0C4
_080A12B4:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r1, [r0, r3]
	ldr r0, [sp, 0xC]
	subs r0, r1
	bl OtherRandomCapped
	add r1, sp, 0x8
	ldrh r1, [r1, 0x2]
	adds r1, r0
	mov r4, r10
	strh r1, [r4, 0x2A]
	bl _0809F0C4
_080A12D0:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r5, r10
	strh r0, [r5, 0x28]
	add r0, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	mov r0, r9
	bl sub_809D8EC
	b _080A130A
_080A12E6:
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	bl sub_809D9B8
	bl _0809EAE0
_080A12F4:
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	mov r4, r10
	strh r0, [r4, 0x28]
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	ldrb r2, [r0, 0x1]
	mov r0, r9
	bl sub_809DA08
_080A130A:
	lsls r0, 24
_080A130C:
	cmp r0, 0
	bne _080A1314
	bl _0809EAE0
_080A1314:
	bl _0809F0C4
_080A1318:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1324:
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
_080A132A:
	mov r0, r9
	bl sub_80A242C
_080A1330:
	mov r1, r10
	str r0, [r1, 0x4]
	bl _0809EAE0
_080A1338:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1344:
	ldr r2, _080A1364
	add r0, sp, 0x8
	movs r5, 0x2
	ldrsh r1, [r0, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	mov r1, r10
	str r0, [r1, 0x4]
	str r0, [r1, 0x8]
	bl _0809EAE0
	.align 2, 0
_080A1364: .4byte gUnknown_812F1F8
_080A1368:
	mov r1, r10
	adds r1, 0x10
	mov r0, r10
	adds r0, 0x4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
_080A1374:
	ldr r0, _080A138C
	movs r5, 0
	ldrsh r1, [r0, r5]
	add r0, sp, 0x8
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	cmp r0, 0
	blt _080A1390
	add r0, sp, 0x8
	movs r3, 0x2
	ldrsh r2, [r0, r3]
	b _080A1396
	.align 2, 0
_080A138C: .4byte gUnknown_2039A34
_080A1390:
	mov r4, r10
	movs r5, 0xC
	ldrsh r2, [r4, r5]
_080A1396:
	adds r5, r2, 0
	add r0, sp, 0x8
	ldrb r0, [r0, 0x1]
	lsls r0, 24
	cmp r0, 0
	blt _080A13AA
	add r0, sp, 0x8
	movs r4, 0x1
	ldrsb r4, [r0, r4]
	b _080A13B0
_080A13AA:
	mov r0, r10
	movs r4, 0xE
	ldrsb r4, [r0, r4]
_080A13B0:
	add r0, sp, 0x1C
	adds r2, r5, 0
	adds r3, r4, 0
	bl GroundMap_GetStationScript
	ldr r0, [sp, 0x1C]
	mov r1, r10
	str r0, [r1, 0x4]
	str r0, [r1, 0x8]
	strh r5, [r1, 0xC]
	strb r4, [r1, 0xE]
	bl _0809EAE0
_080A13CA:
	mov r0, r10
	adds r0, 0x50
	add r1, sp, 0x8
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A4D7C
	ldr r4, _080A13F4
	strh r0, [r4]
	bl sub_809D940
	movs r3, 0
	ldrsh r0, [r4, r3]
	bl GroundMap_ExecuteEnter
	bl _0809EAE0
	.align 2, 0
_080A13F4: .4byte gUnknown_2039A34
_080A13F8:
	movs r0, 0
	mov r4, r10
	str r0, [r4, 0x10]
	str r0, [r4, 0x14]
	bl _0809EAE0
_080A1404:
	mov r5, r10
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _080A1410
_080A140C:
	movs r0, 0
	b _080A142E
_080A1410:
	mov r0, r10
	adds r0, 0x4
	mov r1, r10
	adds r1, 0x10
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	movs r0, 0
	mov r5, r10
	str r0, [r5, 0x10]
	str r0, [r5, 0x14]
	bl _0809EAE0
_080A1428:
	movs r0, 0x1
	b _080A142E
_080A142C:
	movs r0, 0x4
_080A142E:
	add sp, 0x1BC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ExecuteScriptCommand

	thumb_func_start sub_80A1440
sub_80A1440:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A14E8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A1440

	thumb_func_start GroundScript_ExecuteTrigger
GroundScript_ExecuteTrigger:
	push {r4,r5,lr}
	sub sp, 0xF4
	lsls r0, 16
	asrs r4, r0, 16
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	ldr r1, _080A14C8
	adds r0, r1
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0xB
	bne _080A14C4
	add r5, sp, 0x10
	ldr r1, _080A14CC
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_809D600
	movs r0, 0
	add r1, sp, 0x4
	adds r2, r4, 0
	bl sub_809D710
	ldr r3, _080A14D0
	adds r0, r5, 0
	movs r1, 0
	add r2, sp, 0x4
	bl GroundScript_ExecutePP
	add r1, sp, 0x44
	add r0, sp, 0x38
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, _080A14D4
	str r0, [r5, 0x34]
	str r0, [r5, 0x38]
	ldr r1, _080A14D8
	adds r0, r5, 0
	bl HandleAction
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	adds r0, r5, 0
	bl sub_809D648
	cmp r4, 0
	beq _080A14DC
_080A14C4:
	movs r0, 0
	b _080A14DE
	.align 2, 0
_080A14C8: .4byte gUnknown_812F1F8
_080A14CC: .4byte gUnknown_8116488
_080A14D0: .4byte gUnknown_81166F8
_080A14D4: .4byte gUnknown_81164E4
_080A14D8: .4byte gUnknown_8116704
_080A14DC:
	movs r0, 0x1
_080A14DE:
	add sp, 0xF4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GroundScript_ExecuteTrigger

	thumb_func_start sub_80A14E8
sub_80A14E8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _080A1514
	add sp, r4
	adds r6, r0, 0
	adds r5, r2, 0
	adds r7, r3, 0
	lsls r1, 24
	lsrs r1, 24
	subs r0, r1, 0x1
	cmp r0, 0x49
	bls _080A1508
	bl _080A236A
_080A1508:
	lsls r0, 2
	ldr r1, _080A1518
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A1514: .4byte 0xfffffc80
_080A1518: .4byte _080A151C
	.align 2, 0
_080A151C:
	.4byte _080A1644
	.4byte _080A164C
	.4byte _080A1672
	.4byte _080A167A
	.4byte _080A1680
	.4byte _080A1688
	.4byte _080A1690
	.4byte _080A1698
	.4byte _080A169E
	.4byte _080A16C6
	.4byte _080A1730
	.4byte _080A1756
	.4byte _080A178C
	.4byte _080A1792
	.4byte _080A17C0
	.4byte _080A17C6
	.4byte _080A1800
	.4byte _080A1814
	.4byte _080A1824
	.4byte _080A1840
	.4byte _080A185E
	.4byte _080A18C2
	.4byte _080A18E2
	.4byte _080A18F2
	.4byte _080A1904
	.4byte _080A197C
	.4byte _080A1988
	.4byte _080A19DC
	.4byte _080A19FC
	.4byte _080A1A0E
	.4byte _080A1A18
	.4byte _080A1A70
	.4byte _080A1AF8
	.4byte _080A1B20
	.4byte _080A1B36
	.4byte _080A1B58
	.4byte _080A1B64
	.4byte _080A1BD8
	.4byte _080A1BE4
	.4byte _080A1C30
	.4byte _080A1C84
	.4byte _080A1DEC
	.4byte _080A1E30
	.4byte _080A1E3C
	.4byte _080A1ED0
	.4byte _080A1ED6
	.4byte _080A1F28
	.4byte _080A1F3C
	.4byte _080A1F44
	.4byte _080A1F50
	.4byte _080A1F80
	.4byte _080A1FDA
	.4byte _080A202C
	.4byte _080A2054
	.4byte _080A2060
	.4byte _080A204A
	.4byte _080A206C
	.4byte _080A2076
	.4byte _080A207C
	.4byte _080A2082
	.4byte _080A20D4
	.4byte _080A20F4
	.4byte _080A21E4
	.4byte _080A228C
	.4byte _080A229E
	.4byte _080A2298
	.4byte _080A22AE
	.4byte _080A22CC
	.4byte _080A22E4
	.4byte _080A2304
	.4byte _080A2320
	.4byte _080A232E
	.4byte _080A233A
	.4byte _080A2346
_080A1644:
	bl sub_8098C58
	bl _080A236A
_080A164C:
	bl sub_8011C34
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080A1660
	bl Random
	bl sub_8011C40
_080A1660:
	movs r0, 0x1
	bl sub_8011C28
	bl sub_8001064
	bl sub_809965C
	bl _080A236A
_080A1672:
	bl sub_8098CC8
	bl _080A236A
_080A167A:
	bl sub_80961D8
	b _080A1804
_080A1680:
	bl sub_8096028
	bl _080A236A
_080A1688:
	bl sub_80963FC
	bl _080A236A
_080A1690:
	bl sub_8096488
	bl _080A236A
_080A1698:
	bl sub_80964B4
	b _080A1804
_080A169E:
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A16B0
	bl sub_808D4B0
	b _080A16B4
_080A16B0:
	bl sub_808D500
_080A16B4:
	lsls r0, 24
	lsrs r4, r0, 24
	bl nullsub_104
	negs r0, r4
	orrs r0, r4
	lsrs r0, 31
	bl _080A236C
_080A16C6:
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080A16D2
	bl _080A236A
_080A16D2:
	movs r2, 0xE
	ldrsh r0, [r6, r2]
	add r1, sp, 0x314
	bl sub_80A8C4C
	lsls r0, 16
	asrs r1, r0, 16
	cmp r1, 0
	bne _080A16E8
	bl _080A236A
_080A16E8:
	add r0, sp, 0x314
	ldrb r0, [r0]
	cmp r0, 0x44
	bne _080A16FC
	movs r0, 0x82
	lsls r0, 1
	cmp r1, r0
	bne _080A16FC
	bl _080A203C
_080A16FC:
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_80A90C8
	lsls r0, 16
	ldr r1, _080A172C
	asrs r0, 14
	adds r0, r1
	ldr r1, [r0]
	add r0, sp, 0x4
	bl strcpy
	movs r0, 0
	movs r1, 0x1
	add r2, sp, 0x4
	bl sub_809AE90
_080A171E:
	lsls r0, 24
_080A1720:
	cmp r0, 0
	beq _080A1726
	b _080A1EBE
_080A1726:
	bl _080A236A
	.align 2, 0
_080A172C: .4byte gUnknown_813237C
_080A1730:
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2740
	lsls r0, 24
	lsrs r0, 24
	bl sub_80969D0
	movs r1, 0
	cmp r0, 0
	ble _080A1750
	movs r1, 0x1
_080A1750:
	adds r0, r1, 0
	bl _080A236C
_080A1756:
	add r4, sp, 0x104
	adds r0, r4, 0
	bl sub_8099394
	lsls r0, 24
	cmp r0, 0
	bne _080A1768
	bl _080A236A
_080A1768:
	ldr r0, _080A1788
	ldr r1, [r0]
	ldrb r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 4
	adds r1, r0
	adds r1, 0x2C
	movs r0, 0
	ldrsb r0, [r1, r0]
_080A177C:
	cmp r0, 0
	ble _080A1782
	b _080A1EBE
_080A1782:
	bl _080A236A
	.align 2, 0
_080A1788: .4byte gUnknown_203B480
_080A178C:
	bl sub_8097640
	b _080A1804
_080A1792:
	movs r5, 0x11
_080A1794:
	lsls r4, r5, 16
	asrs r0, r4, 16
	bl sub_809758C
	lsls r0, 24
	cmp r0, 0
	beq _080A17B6
	lsrs r4, 16
	movs r0, 0
	movs r1, 0x2F
	adds r2, r4, 0
	bl sub_8001784
	cmp r0, 0
	bne _080A17B6
	bl _080A234E
_080A17B6:
	adds r5, 0x1
	cmp r5, 0x16
	ble _080A1794
	bl _080A236A
_080A17C0:
	bl sub_80964E4
	b _080A1804
_080A17C6:
	movs r4, 0x8
	ldrsh r0, [r6, r4]
	cmp r0, 0x1
	beq _080A17D2
	bl _080A236A
_080A17D2:
	movs r5, 0xA
	ldrsh r0, [r6, r5]
	cmp r0, 0
	beq _080A17DE
	bl _080A236A
_080A17DE:
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	beq _080A17EA
	bl _080A236A
_080A17EA:
	movs r2, 0xA
	ldrsh r4, [r6, r2]
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_80A8E9C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_80A87E0
	b _080A171E
_080A1800:
	bl sub_80A8D20
_080A1804:
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	bl _080A236C
_080A1814:
	ldr r0, _080A1820
	ldrh r0, [r0]
	movs r1, 0xC0
	lsls r1, 2
	ands r0, r1
	b _080A1720
	.align 2, 0
_080A1820: .4byte gUnknown_20255F0
_080A1824:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_80A8D54
	cmp r0, 0
	bne _080A1834
	bl _080A236A
_080A1834:
	ldrh r0, [r0]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	bl _080A236C
_080A1840:
	movs r4, 0x8
	ldrsh r0, [r6, r4]
	cmp r0, 0x1
	beq _080A184C
	bl _080A236A
_080A184C:
	movs r5, 0xA
	ldrsh r0, [r6, r5]
	bl sub_80A8BFC
	lsls r0, 16
	asrs r0, 16
	bl sub_808DB48
	b _080A171E
_080A185E:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bge _080A1872
	bl _080A236A
_080A1872:
	lsls r4, r7, 8
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	add r7, sp, 0x318
	ldr r2, [r1, 0xC]
	adds r1, r7, 0
	bl _call_via_r2
	add r6, sp, 0x320
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80A8FD8
	add r0, sp, 0x318
	ldr r3, [r0]
	subs r1, r3, r4
	add r0, sp, 0x320
	ldr r2, [r0]
	cmp r1, r2
	ble _080A189E
	bl _080A236A
_080A189E:
	adds r0, r3, r4
	cmp r0, r2
	bge _080A18A8
	bl _080A236A
_080A18A8:
	ldr r2, [r7, 0x4]
	subs r0, r2, r4
	ldr r1, [r6, 0x4]
	cmp r0, r1
	ble _080A18B6
	bl _080A236A
_080A18B6:
	adds r0, r2, r4
	cmp r0, r1
	blt _080A18BE
	b _080A1EBE
_080A18BE:
	bl _080A236A
_080A18C2:
	movs r0, 0x1
	bl sub_80A8D54
	cmp r0, 0
	bne _080A18D0
	bl _080A236A
_080A18D0:
	adds r1, r0, 0
	adds r1, 0x4C
	movs r2, 0
	adds r0, 0x55
_080A18D8:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _080A18D8
	b _080A1EBE
_080A18E2:
	movs r0, 0xC
	bl sub_80925EC
	movs r0, 0x12
	bl sub_80925EC
	bl _080A236A
_080A18F2:
	ldr r0, _080A1900
	movs r1, 0x3C
_080A18F6:
	movs r2, 0xA
	bl sub_80A8F50
	bl _080A236A
	.align 2, 0
_080A1900: .4byte gUnknown_2039D98
_080A1904:
	movs r0, 0x51
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
	add r1, sp, 0x4
	ldr r0, _080A1970
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r4,r6}
	stm r1!, {r2,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r1!, {r3,r4,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r4, sp, 0x2C
	adds r0, r4, 0
	add r1, sp, 0x4
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A193C
	b _080A1EBE
_080A193C:
	movs r3, 0
	ldr r1, _080A1974
	mov r8, r1
	lsls r6, r5, 2
	ldr r2, _080A1978
	adds r4, r0, 0
	adds r4, 0x4C
	mov r7, r8
_080A194C:
	adds r0, r4, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _080A194C
_080A195A:
	adds r0, r6, r5
	lsls r0, 4
	adds r0, r2
	mov r1, r8
	movs r2, 0xA
	bl sub_80922B4
_080A1968:
	bl sub_8097848
	bl _080A236A
	.align 2, 0
_080A1970: .4byte gUnknown_8116710
_080A1974: .4byte gUnknown_2039D98
_080A1978: .4byte gPlayerName
_080A197C:
	ldr r0, _080A1984
	movs r1, 0x53
	b _080A18F6
	.align 2, 0
_080A1984: .4byte gUnknown_2039D98
_080A1988:
	ldr r0, _080A19D4
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
	add r1, sp, 0x84
	adds r2, r1, 0
	ldr r0, _080A19D8
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0xAC
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	adds r4, r0, 0
	cmp r4, 0
	bne _080A19C2
	b _080A1EBE
_080A19C2:
	bl sub_8097848
	ldrh r1, [r4]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r4]
	bl _080A236A
	.align 2, 0
_080A19D4: .4byte 0x00000183
_080A19D8: .4byte gUnknown_8116738
_080A19DC:
	ldr r0, _080A19F8
	movs r1, 0
	bl sub_808D434
	adds r2, r0, 0
	cmp r2, 0
	bne _080A19EC
	b _080A1EBE
_080A19EC:
	ldrh r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r2]
	bl _080A236A
	.align 2, 0
_080A19F8: .4byte 0x00000183
_080A19FC:
	movs r0, 0x82
	lsls r0, 1
_080A1A00:
	bl sub_808D278
	cmp r0, 0
	bne _080A1A0A
	b _080A1EBE
_080A1A0A:
	bl _080A236A
_080A1A0E:
	ldr r0, _080A1A14
	movs r1, 0x7C
	b _080A18F6
	.align 2, 0
_080A1A14: .4byte gUnknown_2039D98
_080A1A18:
	add r1, sp, 0x108
	adds r2, r1, 0
	ldr r0, _080A1A64
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x130
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1A42
	b _080A1EBE
_080A1A42:
	movs r3, 0
	ldr r4, _080A1A68
	mov r8, r4
	lsls r6, r5, 2
	ldr r2, _080A1A6C
	adds r4, r0, 0
	adds r4, 0x4C
	mov r7, r8
_080A1A52:
	adds r0, r4, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x9
	ble _080A1A52
	b _080A195A
	.align 2, 0
_080A1A64: .4byte gUnknown_8116760
_080A1A68: .4byte gUnknown_2039D98
_080A1A6C: .4byte gPlayerName
_080A1A70:
	movs r0, 0x9E
	movs r1, 0x1
	bl sub_80026E8
	movs r0, 0x91
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	bne _080A1A9A
	ldr r3, _080A1AEC
	str r0, [sp]
	movs r0, 0x91
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	beq _080A1A9A
	bl sub_8097848
_080A1A9A:
	movs r0, 0x92
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	bne _080A1ABC
	ldr r3, _080A1AF0
	str r0, [sp]
	movs r0, 0x92
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	beq _080A1ABC
	bl sub_8097848
_080A1ABC:
	movs r0, 0x90
	movs r1, 0
	bl sub_808D434
	cmp r0, 0
	beq _080A1ACC
	bl _080A236A
_080A1ACC:
	ldr r3, _080A1AF4
	str r0, [sp]
	movs r0, 0x90
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	bne _080A1AE2
	bl _080A236A
_080A1AE2:
	bl sub_8097848
	bl _080A236A
	.align 2, 0
_080A1AEC: .4byte gUnknown_8116788
_080A1AF0: .4byte gUnknown_811678C
_080A1AF4: .4byte gUnknown_8116790
_080A1AF8:
	movs r0, 0x90
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	bne _080A1B08
	bl _080A236A
_080A1B08:
	movs r0, 0x91
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	bne _080A1B18
	bl _080A236A
_080A1B18:
	movs r0, 0x92
	bl sub_808E734
	b _080A171E
_080A1B20:
	bl sub_808D33C
	ldrh r0, [r0, 0x8]
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080A1B32
	b _080A1EBE
_080A1B32:
	bl _080A236A
_080A1B36:
	bl sub_808D33C
	cmp r0, 0
	beq _080A1B4A
	movs r5, 0x8
	ldrsh r1, [r0, r5]
	ldr r0, _080A1B54
	cmp r1, r0
	bne _080A1B4A
	b _080A203C
_080A1B4A:
	ldr r0, _080A1B54
	bl sub_8098134
	b _080A171E
	.align 2, 0
_080A1B54: .4byte 0x00000113
_080A1B58:
	ldr r0, _080A1B60
	movs r1, 0x79
	b _080A18F6
	.align 2, 0
_080A1B60: .4byte gUnknown_2039D98
_080A1B64:
	ldr r4, _080A1BCC
	adds r0, r4, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1B88
	adds r0, r4, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
_080A1B88:
	add r1, sp, 0x188
	adds r2, r1, 0
	ldr r0, _080A1BD0
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r0!, {r4-r6}
	stm r2!, {r4-r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x1B0
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1BB2
	b _080A1EBE
_080A1BB2:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1BD4
_080A1BBA:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1BBA
	b _080A1968
	.align 2, 0
_080A1BCC: .4byte 0x00000199
_080A1BD0: .4byte gUnknown_8116794
_080A1BD4: .4byte gUnknown_2039D98
_080A1BD8:
	ldr r0, _080A1BE0
	movs r1, 0x7A
	b _080A18F6
	.align 2, 0
_080A1BE0: .4byte gUnknown_2039D98
_080A1BE4:
	add r1, sp, 0x208
	adds r2, r1, 0
	ldr r0, _080A1C28
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x230
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	bne _080A1C0E
	b _080A1EBE
_080A1C0E:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1C2C
_080A1C16:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1C16
	b _080A1968
	.align 2, 0
_080A1C28: .4byte gUnknown_81167BC
_080A1C2C: .4byte gUnknown_2039D98
_080A1C30:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080A1C70
	ldr r0, _080A1C64
	ldrb r4, [r0, 0x2]
	adds r0, r4, 0
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _080A1C4A
	b _080A236A
_080A1C4A:
	ldr r0, _080A1C68
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r1, r0, r1
	ldrh r2, [r1]
	ldr r0, _080A1C6C
	cmp r2, r0
	bls _080A1C5E
	b _080A236A
_080A1C5E:
	adds r0, r2, 0x1
	strh r0, [r1]
	b _080A236A
	.align 2, 0
_080A1C64: .4byte gUnknown_81167E4
_080A1C68: .4byte gUnknown_203B460
_080A1C6C: .4byte 0x000003e6
_080A1C70:
	ldr r0, _080A1C80
	ldrb r0, [r0, 0x2]
	movs r1, 0
	bl sub_809124C
	bl sub_80910B4
	b _080A236A
	.align 2, 0
_080A1C80: .4byte gUnknown_81167E4
_080A1C84:
	movs r0, 0xD1
	lsls r0, 1
	bl RandomCapped
	adds r0, 0x1
	lsls r0, 16
	asrs r5, r0, 16
	movs r0, 0x20
	bl RandomCapped
	adds r4, r0, 0
	movs r7, 0xD2
	lsls r7, 1
	movs r6, 0
	ldr r0, _080A1DE0
	mov r8, r0
_080A1CA4:
	adds r0, r5, 0x1
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, r8
	ble _080A1CB0
	movs r5, 0x1
_080A1CB0:
	subs r7, 0x1
	cmp r7, 0
	bge _080A1CCC
	cmp r6, 0
	bne _080A1CBC
	b _080A2360
_080A1CBC:
	cmp r4, r6
	blt _080A1CCC
	adds r0, r6, 0
	bl RandomCapped
	adds r4, r0, 0
	movs r7, 0xD2
	lsls r7, 1
_080A1CCC:
	adds r0, r5, 0
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _080A1CA4
	ldr r0, _080A1DE4
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0xB
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0xD
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x88
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x67
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x23
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x3
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	cmp r5, r8
	beq _080A1CA4
	cmp r5, 0x96
	beq _080A1CA4
	subs r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	cmp r5, 0x97
	beq _080A1CA4
	subs r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x8C
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x2
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x5
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x82
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	adds r0, 0x1
	cmp r5, r0
	beq _080A1CA4
	subs r0, 0x83
	cmp r5, r0
	beq _080A1CA4
	adds r0, r5, 0
	bl sub_80981DC
	lsls r0, 24
	cmp r0, 0
	beq _080A1CA4
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _080A1D9E
	adds r0, r5, 0
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	bne _080A1CA4
	adds r0, r5, 0
	bl sub_808D278
	cmp r0, 0
	beq _080A1CA4
_080A1D9E:
	adds r6, 0x1
	subs r4, 0x1
	cmp r4, 0
	blt _080A1DA8
	b _080A1CA4
_080A1DA8:
	movs r0, 0
	movs r1, 0x1F
	adds r2, r5, 0
	bl sub_80018D8
	ldr r4, _080A1DE8
	adds r0, r5, 0
	bl sub_808DBA8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
	b _080A203C
	.align 2, 0
_080A1DE0: .4byte 0x000001a3
_080A1DE4: .4byte 0x0000019b
_080A1DE8: .4byte gUnknown_202E628
_080A1DEC:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r5, r0, 16
	ldr r4, _080A1E2C
	adds r0, r5, 0
	bl sub_808DBA8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	cmp r5, 0
	bne _080A1E14
	b _080A236A
_080A1E14:
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
	b _080A203C
	.align 2, 0
_080A1E2C: .4byte gUnknown_202E628
_080A1E30:
	ldr r0, _080A1E38
	movs r1, 0x20
	b _080A18F6
	.align 2, 0
_080A1E38: .4byte gUnknown_2039D98
_080A1E3C:
	cmp r5, 0
	bne _080A1E42
	b _080A2360
_080A1E42:
	movs r0, 0
	movs r1, 0x1F
	bl sub_8001658
	lsls r0, 16
	asrs r5, r0, 16
	adds r6, r5, 0
	ldr r4, _080A1EC4
	adds r0, r5, 0
	bl sub_808DBA8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8092578
	cmp r5, 0
	bne _080A1E6C
	b _080A236A
_080A1E6C:
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	bne _080A1E8E
	adds r0, r5, 0
	bl sub_808DBA8
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
_080A1E8E:
	ldr r3, _080A1EC8
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	bl sub_808D2E8
	cmp r0, 0
	bne _080A1EA4
	b _080A236A
_080A1EA4:
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _080A1ECC
_080A1EAC:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _080A1EAC
	bl sub_8097848
_080A1EBE:
	movs r0, 0x1
	b _080A236C
	.align 2, 0
_080A1EC4: .4byte gUnknown_202E628
_080A1EC8: .4byte gUnknown_81167E8
_080A1ECC: .4byte gUnknown_2039D98
_080A1ED0:
	bl sub_809211C
	b _080A177C
_080A1ED6:
	bl sub_8092178
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_809211C
	cmp r0, 0
	bgt _080A1EE8
	b _080A236A
_080A1EE8:
	bl sub_8092158
	bl sub_8092178
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	bl sub_80921A8
	adds r1, r0, 0
	ldr r4, _080A1F30
	adds r0, r4, 0
	bl strcpy
	adds r0, r5, 0
	bl sub_80921A8
	adds r1, r0, 0
	adds r4, 0x50
	adds r0, r4, 0
	bl strcpy
	movs r1, 0x1
	negs r1, r1
	ldr r2, _080A1F34
	movs r0, 0
	bl sub_809AE90
	lsls r0, 24
	cmp r0, 0
	bne _080A1EBE
_080A1F28:
	ldr r0, _080A1F38
	bl sub_80913A0
	b _080A236A
	.align 2, 0
_080A1F30: .4byte gUnknown_202DE58
_080A1F34: .4byte gUnknown_81167EC
_080A1F38: .4byte 0x00002710
_080A1F3C:
	ldr r0, _080A1F40
	b _080A1A00
	.align 2, 0
_080A1F40: .4byte 0x00000133
_080A1F44:
	ldr r0, _080A1F4C
	movs r1, 0x52
	b _080A18F6
	.align 2, 0
_080A1F4C: .4byte gUnknown_2039D98
_080A1F50:
	add r1, sp, 0x288
	adds r2, r1, 0
	ldr r0, _080A1F7C
	ldm r0!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r0!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r0!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r0, [r0]
	str r0, [r2]
	add r4, sp, 0x2B0
	adds r0, r4, 0
	bl sub_808D144
	adds r0, r4, 0
	bl sub_808D1DC
	cmp r0, 0
	beq _080A1EBE
	b _080A1968
	.align 2, 0
_080A1F7C: .4byte gUnknown_811681C
_080A1F80:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x12
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	bne _080A1F94
	b _080A236A
_080A1F94:
	movs r0, 0
	movs r1, 0xF
	bl sub_8001658
	cmp r0, 0x4
	bne _080A1FA2
	b _080A236A
_080A1FA2:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	bl sub_8001784
	cmp r0, 0
	ble _080A1FB2
	b _080A236A
_080A1FB2:
	movs r0, 0x80
	lsls r0, 1
	bl OtherRandomCapped
	cmp r0, 0
	bne _080A1FCC
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	movs r3, 0x4
	bl sub_800199C
	b _080A1EBE
_080A1FCC:
	movs r0, 0
	movs r1, 0x42
	movs r2, 0
	movs r3, 0x1
	bl sub_800199C
	b _080A236A
_080A1FDA:
	ldr r6, _080A200C
	ldr r7, _080A2010
	movs r5, 0x2
_080A1FE0:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080A2018
	ldrb r4, [r6, 0x2]
	adds r0, r4, 0
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _080A2024
	ldr r0, _080A2014
	ldr r0, [r0]
	lsls r1, r4, 1
	adds r0, 0x50
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r7
	bhi _080A2024
	adds r0, 0x1
	strh r0, [r1]
	b _080A2024
	.align 2, 0
_080A200C: .4byte gUnknown_8116844
_080A2010: .4byte 0x000003e6
_080A2014: .4byte gUnknown_203B460
_080A2018:
	ldrb r0, [r6, 0x2]
	movs r1, 0
	bl sub_809124C
	bl sub_80910B4
_080A2024:
	subs r5, 0x1
	cmp r5, 0
	bge _080A1FE0
	b _080A236A
_080A202C:
	bl sub_808D33C
	cmp r0, 0
	beq _080A2040
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	cmp r0, 0x71
	bne _080A2040
_080A203C:
	movs r0, 0x2
	b _080A236C
_080A2040:
	movs r0, 0x71
	bl sub_8098134
	bl _080A171E
_080A204A:
	movs r0, 0
	movs r1, 0x1
	bl sub_80A56A0
	b _080A236A
_080A2054:
	add r0, sp, 0x328
	str r5, [r0]
	str r7, [r0, 0x4]
	bl sub_80A56F0
	b _080A236A
_080A2060:
	add r0, sp, 0x330
	str r5, [r0]
	str r7, [r0, 0x4]
	bl sub_80A5704
	b _080A236A
_080A206C:
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_809C6CC
	b _080A236A
_080A2076:
	bl sub_809C6EC
	b _080A236A
_080A207C:
	bl sub_809C760
	b _080A236A
_080A2082:
	movs r0, 0
	movs r4, 0x80
	lsls r4, 9
_080A2088:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80A86C8
	adds r0, r4, 0
	movs r5, 0x80
	lsls r5, 9
	adds r4, r5
	asrs r0, 16
	cmp r0, 0x17
	ble _080A2088
	movs r0, 0
	adds r4, r5, 0
_080A20A2:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80AC1B0
	adds r0, r4, 0
	movs r6, 0x80
	lsls r6, 9
	adds r4, r6
	asrs r0, 16
	cmp r0, 0xF
	ble _080A20A2
	movs r0, 0
	adds r4, r6, 0
_080A20BC:
	movs r1, 0x80
	lsls r1, 15
	bl sub_80AD0C8
	adds r0, r4, 0
	movs r1, 0x80
	lsls r1, 9
	adds r4, r1
	asrs r0, 16
	cmp r0, 0xF
	ble _080A20BC
	b _080A236A
_080A20D4:
	add r0, sp, 0x338
	str r5, [r0]
	adds r4, r0, 0
	str r7, [r4, 0x4]
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_80A5984
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0
	adds r1, r4, 0
	bl sub_80A59A0
	b _080A236A
_080A20F4:
	add r1, sp, 0x308
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	strb r2, [r1, 0x1]
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x3]
	str r2, [r1, 0x4]
	ldr r0, _080A21D8
	ldr r2, _080A21DC
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1, 0x8]
	movs r0, 0x1
	negs r0, r0
	lsls r2, r5, 16
	asrs r2, 16
	lsls r3, r7, 24
	asrs r3, 24
	bl GroundEffect_Add
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _080A2128
	b _080A236A
_080A2128:
	bl sub_80AD158
	adds r7, r0, 0
	add r4, sp, 0x340
	add r5, sp, 0x348
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80A579C
	ldr r0, [r4, 0x4]
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	str r0, [r4, 0x4]
	ldr r0, [r5, 0x4]
	adds r0, r1
	str r0, [r5, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	add r6, sp, 0x350
	ldr r2, [r1, 0xC]
	adds r1, r6, 0
	bl _call_via_r2
	add r1, sp, 0x350
	ldr r2, [r1]
	add r0, sp, 0x340
	ldr r0, [r0]
	cmp r2, r0
	blt _080A216E
	add r0, sp, 0x348
	ldr r0, [r0]
	cmp r2, r0
	blt _080A2170
	subs r0, 0x1
_080A216E:
	str r0, [r1]
_080A2170:
	ldr r1, [r6, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	blt _080A2180
	ldr r0, [r5, 0x4]
	cmp r1, r0
	blt _080A2182
	subs r0, 0x1
_080A2180:
	str r0, [r6, 0x4]
_080A2182:
	add r1, sp, 0x340
	ldr r0, [r1]
	ldr r2, _080A21E0
	adds r0, r2
	str r0, [r1]
	ldr r0, [r4, 0x4]
	adds r0, r2
	str r0, [r4, 0x4]
	add r1, sp, 0x348
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 3
	adds r0, r2
	str r0, [r1]
	ldr r0, [r5, 0x4]
	adds r0, r2
	str r0, [r5, 0x4]
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r3, [r1, 0x20]
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r6, 0
	bl _call_via_r2
	movs r0, 0
	movs r1, 0
	add r2, sp, 0x358
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0x358
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	b _080A1EBE
	.align 2, 0
_080A21D8: .4byte gUnknown_812F1F8
_080A21DC: .4byte 0x00001310
_080A21E0: .4byte 0xfffffc00
_080A21E4:
	ldr r0, _080A2288
	ldrh r4, [r0]
	ldrh r0, [r0, 0x2]
	movs r1, 0xC
	ands r0, r1
	cmp r0, 0
	beq _080A21F4
	b _080A236A
_080A21F4:
	adds r0, r4, 0
	bl sub_809CFE8
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A2282
	movs r2, 0x80
	lsls r2, 1
	add r0, sp, 0x360
	bl sub_8002BB8
	add r0, sp, 0x360
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x368
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x2
	ands r4, r0
	cmp r4, 0
	beq _080A2226
	movs r0, 0x4
_080A2226:
	cmp r0, 0
	beq _080A2282
	movs r3, 0xDA
	lsls r3, 2
	add r3, sp
	mov r9, r3
	add r7, sp, 0x370
	add r4, sp, 0x378
	mov r8, r0
_080A2238:
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	mov r1, r9
	bl _call_via_r2
	cmp r0, 0
	beq _080A2276
	movs r5, 0
	str r5, [r7]
	mov r1, r9
	ldr r0, [r1, 0x4]
	str r0, [r7, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r7, 0
	bl _call_via_r2
	cmp r0, 0
	beq _080A2276
	mov r2, r9
	ldr r0, [r2]
	str r0, [r4]
	str r5, [r4, 0x4]
	ldr r1, [r6]
	ldr r0, [r6, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
_080A2276:
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r5, r8
	cmp r5, 0
	bne _080A2238
_080A2282:
	movs r0, 0x1
	negs r0, r0
	b _080A236C
	.align 2, 0
_080A2288: .4byte gUnknown_20255F0
_080A228C:
	negs r0, r5
	orrs r0, r5
	lsrs r0, 31
	bl sub_80993C0
	b _080A236A
_080A2298:
	movs r0, 0x1
	bl sub_8011C28
_080A229E:
	adds r0, r5, 0
	bl sub_8098F00
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_80118C4
	b _080A236A
_080A22AE:
	bl sub_800C068
	ldr r1, _080A22C4
	strh r0, [r1]
	lsls r0, 16
	ldr r1, _080A22C8
	cmp r0, r1
	beq _080A22C0
	b _080A1EBE
_080A22C0:
	b _080A236A
	.align 2, 0
_080A22C4: .4byte gUnknown_2039DA8
_080A22C8: .4byte 0x03e70000
_080A22CC:
	ldr r4, _080A22DC
	ldrh r0, [r4]
	ldr r5, _080A22E0
	cmp r0, r5
	beq _080A236A
	bl sub_80118F0
	b _080A2312
	.align 2, 0
_080A22DC: .4byte gUnknown_2039DA8
_080A22E0: .4byte 0x000003e7
_080A22E4:
	ldr r4, _080A22FC
	ldrh r0, [r4]
	ldr r6, _080A2300
	cmp r0, r6
	beq _080A236A
	lsls r1, r5, 16
	lsrs r1, 16
	bl sub_8011900
	strh r6, [r4]
	b _080A1EBE
	.align 2, 0
_080A22FC: .4byte gUnknown_2039DA8
_080A2300: .4byte 0x000003e7
_080A2304:
	ldr r4, _080A2318
	ldrh r0, [r4]
	ldr r5, _080A231C
	cmp r0, r5
	beq _080A236A
	bl sub_8011914
_080A2312:
	strh r5, [r4]
	b _080A1EBE
	.align 2, 0
_080A2318: .4byte gUnknown_2039DA8
_080A231C: .4byte 0x000003e7
_080A2320:
	lsls r0, r5, 16
	lsrs r0, 16
	lsls r1, r7, 16
	lsrs r1, 16
	bl sub_80997F4
	b _080A236A
_080A232E:
	lsls r1, r5, 16
	lsrs r1, 16
	movs r0, 0x1E
	bl sub_80997F4
	b _080A236A
_080A233A:
	lsls r1, r5, 16
	lsrs r1, 16
	movs r0, 0
	bl GroundSprite_ExtendPaletteAdd
	b _080A236A
_080A2346:
	movs r0, 0
	bl GroundSprite_ExtendPaletteDelete
	b _080A236A
_080A234E:
	movs r0, 0
	movs r1, 0x2F
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_800199C
	adds r0, r5, 0
	subs r0, 0x10
	b _080A236C
_080A2360:
	movs r0, 0
	movs r1, 0x1F
	movs r2, 0
	bl sub_80018D8
_080A236A:
	movs r0, 0
_080A236C:
	movs r3, 0xE0
	lsls r3, 2
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A14E8

	thumb_func_start GroundScript_Unlock
GroundScript_Unlock:
	push {r4-r7,lr}
	ldr r1, _080A241C
	ldrb r0, [r1]
	cmp r0, 0
	beq _080A2414
	movs r0, 0
	strb r0, [r1]
	movs r6, 0
_080A2390:
	ldr r0, _080A2420
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, 0
	beq _080A240E
	movs r0, 0x1
	ldr r1, _080A2424
	adds r2, r6, 0
	bl Log
	lsls r5, r6, 16
	asrs r5, 16
	adds r0, r5, 0
	bl sub_80A4D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80A8B1C
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80AC320
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	bl sub_80AD238
	orrs r4, r0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _080A2428
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, 0
	beq _080A240C
	cmp r4, 0
	beq _080A240E
	movs r0, 0x80
	adds r4, r6, 0
	orrs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl sub_80A4D2C
	adds r0, r4, 0
	bl sub_80A8B1C
	adds r0, r4, 0
	bl sub_80AC320
	adds r0, r4, 0
	bl sub_80AD238
	movs r0, 0
	strb r0, [r5]
_080A240C:
	strb r0, [r7]
_080A240E:
	adds r6, 0x1
	cmp r6, 0x80
	ble _080A2390
_080A2414:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A241C: .4byte gUnknown_2039A36
_080A2420: .4byte gUnknown_2039A38
_080A2424: .4byte gUnknown_8116848
_080A2428: .4byte gUnknown_2039AC0
	thumb_func_end GroundScript_Unlock

	thumb_func_start sub_80A242C
sub_80A242C:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r1, 0
	ldr r0, [r0, 0x2C]
	adds r2, r0, 0
	adds r2, 0x10
	mov r3, sp
_080A243A:
	mov r1, sp
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, 0x10
	ldrb r0, [r3]
	cmp r0, 0xF4
	bne _080A243A
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	cmp r4, r0
	bne _080A243A
	adds r0, r2, 0
	add sp, 0x10
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A242C

	thumb_func_start sub_80A2460
sub_80A2460:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r5, r0, 0
	mov r8, r1
	ldr r6, [r5, 0x28]
	mov r4, sp
_080A2470:
	mov r0, sp
	adds r1, r6, 0
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldr r1, [r1]
	str r1, [r0]
	ldrb r0, [r4]
	cmp r0, 0xCC
	bne _080A249E
	ldr r1, [sp, 0x4]
	mov r0, r8
	movs r2, 0x2
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A249E:
	cmp r0, 0xCD
	bne _080A24BE
	ldr r1, [sp, 0x4]
	ldrb r2, [r4, 0x1]
	mov r0, r8
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A24BE:
	cmp r0, 0xCE
	bne _080A24EC
	ldr r1, [sp, 0x4]
	lsls r1, 16
	asrs r1, 16
	adds r0, r5, 0
	adds r0, 0x74
	bl sub_8001658
	adds r1, r0, 0
	ldrb r2, [r4, 0x1]
	mov r0, r8
	bl FlagJudge
	lsls r0, 24
	cmp r0, 0
	beq _080A24F0
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	adds r0, r5, 0
	bl sub_80A242C
	b _080A24F4
_080A24EC:
	adds r0, r6, 0
	b _080A24F4
_080A24F0:
	adds r6, 0x10
	b _080A2470
_080A24F4:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A2460

	thumb_func_start sub_80A2500
sub_80A2500:
	push {r4,lr}
	adds r4, r0, 0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _080A2524
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80A8BBC
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_809AB4C
_080A2524:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A2500

	thumb_func_start sub_80A252C
sub_80A252C:
	push {r4,lr}
	adds r4, r0, 0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _080A2550
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80A8BBC
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_809ABB4
_080A2550:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A252C

	thumb_func_start sub_80A2558
sub_80A2558:
	push {r4,lr}
	adds r4, r0, 0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	bne _080A257C
	lsls r4, 16
	asrs r4, 16
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	bl sub_80A8BBC
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_809AC18
_080A257C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A2558

	thumb_func_start sub_80A2584
sub_80A2584:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	lsls r0, 16
	asrs r0, 16
	bl sub_809ABB4
	pop {r0}
	bx r0
	thumb_func_end sub_80A2584

	thumb_func_start sub_80A2598
sub_80A2598:
	push {lr}
	lsls r1, 16
	asrs r1, 16
	lsls r0, 16
	asrs r0, 16
	bl sub_809AC18
	pop {r0}
	bx r0
	thumb_func_end sub_80A2598

	thumb_func_start sub_80A25AC
sub_80A25AC:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl sub_8098F88
	lsls r0, 24
	cmp r0, 0
	beq _080A25C2
	adds r0, r4, 0
	b _080A2602
_080A25C2:
	cmp r4, 0x32
	bne _080A25CA
	movs r0, 0x32
	b _080A2602
_080A25CA:
	movs r0, 0xC
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _080A25E0
	ldr r0, _080A25DC
	b _080A2602
	.align 2, 0
_080A25DC: .4byte 0x000003e7
_080A25E0:
	movs r0, 0xD
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080A25F0
	movs r0, 0x13
	b _080A2602
_080A25F0:
	cmp r4, 0x1
	bne _080A2600
	movs r0, 0
	movs r1, 0x28
	bl sub_8001658
	movs r0, 0x1
	b _080A2602
_080A2600:
	adds r0, r5, 0
_080A2602:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80A25AC

	thumb_func_start sub_80A2608
sub_80A2608:
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, _080A261C
	adds r0, r1
	bx lr
	.align 2, 0
_080A261C: .4byte gUnknown_81168A8
	thumb_func_end sub_80A2608

	thumb_func_start sub_80A2620
sub_80A2620:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, _080A2640
	adds r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_080A2640: .4byte gUnknown_81168A8
	thumb_func_end sub_80A2620

	thumb_func_start sub_80A2644
sub_80A2644:
	ldr r1, _080A2650
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A2650: .4byte gUnknown_8116F24
	thumb_func_end sub_80A2644

	thumb_func_start sub_80A2654
sub_80A2654:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_80A2608
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	pop {r1}
	bx r1
	thumb_func_end sub_80A2654

	thumb_func_start sub_80A2668
sub_80A2668:
	push {lr}
	lsls r0, 16
	ldr r2, _080A267C
	adds r1, r0, r2
	lsrs r0, r1, 16
	cmp r0, 0x18
	bls _080A2680
	movs r0, 0x1
	negs r0, r0
	b _080A2682
	.align 2, 0
_080A267C: .4byte 0xffc90000
_080A2680:
	asrs r0, r1, 16
_080A2682:
	pop {r1}
	bx r1
	thumb_func_end sub_80A2668

	thumb_func_start sub_80A2688
sub_80A2688:
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	adds r3, r1, 0
	adds r2, r1, 0
	subs r2, 0x4B
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x16
	bhi _080A26A0
	adds r0, r2, 0
	b _080A26B4
_080A26A0:
	cmp r1, 0x2F
	bne _080A26A8
	movs r0, 0x17
	b _080A26B4
_080A26A8:
	cmp r3, 0x30
	beq _080A26B2
	movs r0, 0x1
	negs r0, r0
	b _080A26B4
_080A26B2:
	movs r0, 0x18
_080A26B4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A2688

	thumb_func_start sub_80A26B8
sub_80A26B8:
	lsls r0, 16
	ldr r1, _080A26C8
	asrs r0, 15
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080A26C8: .4byte gUnknown_8116F9A
	thumb_func_end sub_80A26B8

        .align 2,0 @ Don't pad with nop
