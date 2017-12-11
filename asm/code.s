	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80001DC
sub_80001DC:
	mov r0, sp
	bx lr
	thumb_func_end sub_80001DC

	thumb_func_start sub_80001E0
sub_80001E0:
	ldr r0, _080001E4
	bx lr
	.align 2, 0
_080001E4: .4byte gUnknown_3004000
	thumb_func_end sub_80001E0

	arm_func_start sub_80001E8
sub_80001E8:
	stmdb sp!, {r4-r11}
	mov r12, 0x4000000
	ldr r11, _08000224
	add r10, r11, 0x40
	mov r9, 0x1
	mov r8, 0
	strb r8, [r12, 0x208]
	ldmia r10, {r0-r7}
	stmia r10!, {r4-r7}
	stmia r10!, {r0-r3}
	ldr r0, [r11, 0x4]
	str r8, [r11, 0x4]
	strb r9, [r12, 0x208]
	ldmia sp!, {r4-r11}
	bx lr
	.align 2, 0
_08000224: .4byte gUnknown_202DCF8
	arm_func_end sub_80001E8

	arm_func_start sub_8000228
sub_8000228:
	mov r12, 0x4000000
	add r12, r12, 0x120
	ldmia r12, {r0,r1}
	stmdb sp!, {r7-r11}
	ldr r11, _08000340
	mov r9, 0xFE
	add r9, r9, 0xFE00
	ldrh r3, [r12, 0x8]
	and r3, r3, 0x40
	strb r3, [r11, 0x9]
	ldr r10, [r11, 0x14]
	adds r3, r10, 0x1
	blt _08000284
	bne _08000278
	strh r9, [r12, 0xA]
	add r8, r11, 0x28
	ldmia r8, {r2,r3}
	mov r7, r2
	stmia r8, {r3,r7}
	b _08000284
_08000278:
	ldr r3, [r11, 0x2C]
	ldr r2, [r3, r10, lsl 1]
	strh r2, [r12, 0xA]
_08000284:
	cmp r10, 0xB
	addlt r10, r10, 0x1
	strlt r10, [r11, 0x14]
	stmdb sp!, {r0,r1,r5,r6}
	mov r6, 0x3
_08000298:
	add r8, r11, 0x18
	add r8, r8, r6, lsl 2
	ldr r10, [r8]
	mov r3, r6, lsl 1
	ldrh r5, [sp, r3]
	cmp r5, r9
	bne _080002C8
	cmp r10, 0x9
	ble _080002C8
	mov r0, 0x1
	sub r10, r0, 0x2
	b _080002F4
_080002C8:
	ldr r0, [r8, 0x18]
	mov r3, r10, lsl 1
	strh r5, [r0, r3]
	cmp r10, 0x9
	bne _080002F4
	ldr r1, [r8, 0x28]
	str r0, [r8, 0x28]
	str r1, [r8, 0x18]
	add r3, r11, 0x4
	mov r0, 0x1
	strb r0, [r3, r6]
_080002F4:
	cmp r10, 0xB
	addlt r10, r10, 0x1
	str r10, [r8]
	subs r6, r6, 0x1
	bge _08000298
	ldrb r0, [r11]
	cmp r0, 0
	beq _08000334
	ldr r7, _08000344
	mov r0, 0
	strh r0, [r7]
	ldrh r0, [r12, 0x8]
	orr r0, r0, 0x80
	strh r0, [r12, 0x8]
	mov r0, 0xC0
	strh r0, [r7]
_08000334:
	add sp, sp, 0x8
	ldmia sp!, {r5-r11}
	bx lr
	.align 2, 0
_08000340: .4byte gUnknown_202DCF8
_08000344: .4byte 0x0400010e
	arm_func_end sub_8000228

	thumb_func_start GameLoop
GameLoop:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0x1
	mov r9, r0
	bl InitHeap
	bl NDS_DebugInit
	bl sub_801180C
	bl NDS_LoadOverlay_GroundMain
	bl sub_8014144
	bl LoadMonsterParameters
	bl sub_8097670
	bl sub_8094F88
	bl sub_8094980
	bl sub_8094C14
	bl sub_8097F5C
	bl sub_80923A0
	bl sub_8090998
	bl sub_809207C
	bl LoadWazaParameters
	bl sub_80950BC
	bl sub_80958E8
	movs r0, 0x80
	lsls r0, 8
	movs r1, 0
	bl sub_800CD64
	bl sub_8012284
	movs r0, 0x1
	bl sub_8094998
	ldr r0, _08000498
	bl SetWindowTitle
	bl sub_800DAAC
	movs r0, 0
	bl SetSavingIconCoords
	movs r0, 0
	str r0, [sp]
	mov r0, sp
	bl sub_8011DAC
	cmp r0, 0
	beq _080003D2
	bl sub_800135C
_080003D2:
	movs r0, 0xE
	bl sub_8001334
	movs r0, 0xF
	bl sub_8001334
	movs r0, 0
	movs r1, 0x39
	bl sub_80015C0
	movs r0, 0x10
	bl sub_8001334
	movs r0, 0
	movs r1, 0x39
	bl sub_8001658
	cmp r0, 0
	bne _080003FE
	movs r0, 0x11
	bl sub_8001334
_080003FE:
	movs r1, 0
	mov r10, r1
	ldr r2, _0800049C
	mov r8, r2
_08000406:
	ldr r0, _080004A0
	mov r1, r10
	str r1, [r0]
	movs r0, 0x2
	bl sub_800A8F8
	movs r0, 0x1
	bl sub_8004D8C
	movs r0, 0
	bl xxx_update_some_bg_tiles
	bl sub_80097B0
	movs r0, 0x2
	bl sub_800CDA8
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, _080004A4
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	bl sub_8000634
	movs r0, 0
	movs r1, 0
	bl sub_800CCA0
	movs r0, 0
	movs r1, 0
	bl sub_800CCAC
	mov r0, r10
	mov r1, r8
	str r0, [r1]
_08000456:
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0x1
	str r0, [r2]
	movs r4, 0
_08000460:
	ldr r0, _080004A8
	ldr r0, [r0]
	lsls r2, r4, 2
	ldr r1, [r0, 0x4]
	adds r1, r2
	mov r0, r8
	ldr r2, [r0]
	adds r0, r4, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x1
	cmp r4, 0xEF
	ble _08000460
	movs r0, 0
	bl xxx_update_stuff
	mov r1, r8
	ldr r0, [r1]
	cmp r0, 0x1F
	ble _08000456
	mov r2, r9
	cmp r2, 0
	beq _080004C0
	bl sub_8012468
	b _080004B2
	.align 2, 0
_08000498: .4byte gUnknown_80B69BC
_0800049C: .4byte gUnknown_2000A80
_080004A0: .4byte gUnknown_203B03C
_080004A4: .4byte gUnknown_2026E4E
_080004A8: .4byte gUnknown_203B038
_080004AC:
	movs r0, 0
	bl xxx_update_stuff
_080004B2:
	bl sub_8012484
	lsls r0, 24
	cmp r0, 0
	bne _080004AC
	bl sub_8012558
_080004C0:
	movs r0, 0x1
	mov r9, r0
	movs r0, 0x8
	bl sub_800BDFC
	movs r4, 0x1
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	bl InitMainMenu
_080004D8:
	bl sub_80363E0
	lsls r0, 24
	cmp r0, 0
	beq _08000522
	ldr r3, _080004FC
	ldrh r1, [r3, 0x2]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08000500
	movs r4, 0
	movs r0, 0x13
	bl SetBGOBJEnableFlags
	b _08000516
	.align 2, 0
_080004FC: .4byte gUnknown_20255F0
_08000500:
	cmp r4, 0
	bne _08000522
	ldrh r1, [r3]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08000516
	movs r4, 0x1
	movs r0, 0
	bl SetBGOBJEnableFlags
_08000516:
	cmp r4, 0
	bne _08000522
	movs r0, 0
	bl xxx_update_stuff
	b _080004D8
_08000522:
	bl SetUpMenu
	movs r0, 0
	bl xxx_update_stuff
	bl UpdateMenu
	adds r5, r0, 0
	bl CleanUpMenu
	cmp r5, 0x2
	beq _08000542
	cmp r5, 0x4
	beq _08000542
	cmp r5, 0x3
	bne _080004D8
_08000542:
	bl sub_80357D0
	mov r1, r8
	ldr r0, [r1]
	cmp r0, 0
	ble _08000580
	ldr r7, _08000598
	adds r6, r7, 0
_08000552:
	ldr r0, [r6]
	subs r0, 0x1
	str r0, [r6]
	movs r4, 0
_0800055A:
	ldr r0, _0800059C
	ldr r0, [r0]
	lsls r2, r4, 2
	ldr r1, [r0, 0x4]
	adds r1, r2
	ldr r2, [r6]
	adds r0, r4, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0800055A
	movs r0, 0
	bl xxx_update_stuff
	ldr r0, [r7]
	cmp r0, 0
	bgt _08000552
_08000580:
	ldr r0, _0800059C
	ldr r0, [r0]
	bl CloseFile
	cmp r5, 0x3
	beq _080005CA
	cmp r5, 0x3
	bhi _080005A0
	cmp r5, 0x2
	beq _080005A6
	b _08000406
	.align 2, 0
_08000598: .4byte gUnknown_2000A80
_0800059C: .4byte gUnknown_203B038
_080005A0:
	cmp r5, 0x4
	beq _080005C6
	b _08000406
_080005A6:
	movs r0, 0x7
	bl sub_80953D4
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080005C2
	lsls r0, r1, 24
	lsrs r0, 24
	bl sub_8095240
	movs r0, 0x2
	b _080005D4
_080005C2:
	movs r0, 0x1
	b _080005D4
_080005C6:
	movs r0, 0x3
	b _080005D4
_080005CA:
	bl sub_80122A8
	bl nullsub_33
	movs r0, 0
_080005D4:
	bl sub_80009D0
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	b _08000406
	thumb_func_end GameLoop

	thumb_func_start xxx_update_stuff
xxx_update_stuff:
	push {lr}
	bl xxx_draw_string_80144C4
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	ldr r0, _08000630
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl sub_80060EC
	bl sub_8011860
	bl sub_800CB20
	bl sub_800485C
	bl CopySpritesToOam
	bl sub_8005304
	bl TransferBGPaletteBuffer
	bl xxx_call_update_bg_vram
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	movs r0, 0
	bl sub_8004D8C
	pop {r0}
	bx r0
	.align 2, 0
_08000630: .4byte gUnknown_203B46C
	thumb_func_end xxx_update_stuff

	thumb_func_start sub_8000634
sub_8000634:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	mov r1, sp
	ldr r0, _08000708
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	add r5, sp, 0xC
	adds r1, r5, 0
	ldr r0, _0800070C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, _08000710
	movs r1, 0
	bl MemoryAlloc
	adds r7, r0, 0
	movs r0, 0x3
	bl RandomCapped
	adds r4, r0, 0
	lsls r4, 2
	adds r5, r4
	ldr r0, [r5]
	ldr r5, _08000714
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	ldr r1, _08000718
	str r0, [r1]
	mov r1, sp
	adds r0, r1, r4
	ldr r0, [r0]
	adds r1, r5, 0
	bl OpenFileAndGetFileDataPtr
	mov r8, r0
	adds r0, r7, 0
	movs r1, 0
	mov r2, r8
	bl sub_800AAA8
	movs r2, 0
	ldr r0, _0800071C
	movs r3, 0xC0
	lsls r3, 5
	adds r3, r0
	mov r9, r3
	movs r4, 0x80
	lsls r4, 5
	adds r4, r0
	mov r12, r4
_080006A0:
	movs r5, 0
	lsls r1, r2, 6
	adds r6, r2, 0x1
	mov r0, r9
	adds r4, r1, r0
	mov r2, r12
	adds r3, r1, r2
	movs r2, 0x80
	lsls r2, 4
	adds r0, r7, r2
	adds r2, r1, r0
	adds r1, r7
_080006B8:
	ldrh r0, [r1]
	strh r0, [r3]
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, 0x2
	adds r3, 0x2
	adds r2, 0x2
	adds r1, 0x2
	adds r5, 0x1
	cmp r5, 0x1F
	ble _080006B8
	adds r2, r6, 0
	cmp r2, 0x1F
	ble _080006A0
	movs r0, 0x2
	bl sub_80098F8
	movs r0, 0x3
	bl sub_80098F8
	ldr r0, _08000720
	movs r3, 0x80
	lsls r3, 5
	adds r1, r7, r3
	ldr r2, _08000724
	bl CpuCopy
	mov r0, r8
	bl CloseFile
	adds r0, r7, 0
	bl MemoryFree
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08000708: .4byte gUnknown_80B69F8
_0800070C: .4byte gUnknown_80B6A28
_08000710: .4byte 0x00005b20
_08000714: .4byte gUnknown_8380000
_08000718: .4byte gUnknown_203B038
_0800071C: .4byte gUnknown_202B038
_08000720: .4byte 0x06008000
_08000724: .4byte 0x00004b20
	thumb_func_end sub_8000634

	thumb_func_start sub_8000728
sub_8000728:
	ldr r0, _08000730
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08000730: .4byte gUnknown_203B03C
	thumb_func_end sub_8000728

	thumb_func_start sub_8000734
sub_8000734:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	movs r4, 0
	movs r6, 0
	movs r0, 0
	bl xxx_update_some_bg_tiles
	bl sub_8014144
	bl sub_80097B0
	movs r0, 0x2
	bl sub_800CDA8
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
	ldr r0, _080007AC
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2, 0
	strh r1, [r0]
	bl sub_8099648
	bl sub_8094C14
	movs r0, 0
	bl sub_8099690
	bl sub_8099744
	bl sub_8099750
	movs r0, 0x3
	bl sub_80063D8
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	ldr r0, _080007B0
	movs r1, 0
	movs r2, 0
	movs r3, 0x20
	bl sub_80141B4
	b _08000892
	.align 2, 0
_080007AC: .4byte gUnknown_2026E4E
_080007B0: .4byte gUnknown_80B6A34
_080007B4:
	cmp r4, 0x1
	beq _0800086C
	cmp r4, 0x1
	bgt _080007C2
	cmp r4, 0
	beq _080007CC
	b _0800088E
_080007C2:
	cmp r4, 0x2
	beq _08000884
	cmp r4, 0x3
	beq _08000892
	b _0800088E
_080007CC:
	str r4, [sp, 0x4]
	movs r0, 0x3F
	str r0, [sp]
	mov r0, sp
	bl sub_8097688
	bl sub_80140DC
	cmp r5, 0x3
	bhi _080007EC
	add r0, sp, 0x4
	movs r1, 0x1
	bl sub_801203C
	adds r4, r0, 0
	b _080007EE
_080007EC:
	movs r4, 0x2
_080007EE:
	cmp r4, 0
	bne _080007FA
	ldr r0, _08000818
	bl sub_80121E0
	adds r4, r0, 0
_080007FA:
	bl sub_8014114
	cmp r4, 0
	bne _0800083C
	cmp r5, 0x1
	beq _08000812
	cmp r5, 0x1
	bcc _08000820
	cmp r5, 0x2
	beq _08000820
	cmp r5, 0x3
	bne _08000820
_08000812:
	ldr r0, _0800081C
	b _08000822
	.align 2, 0
_08000818: .4byte 0x000f1206
_0800081C: .4byte gUnknown_80B6A7C
_08000820:
	ldr r0, _08000834
_08000822:
	movs r1, 0
	movs r2, 0
	ldr r3, _08000838
	bl sub_80141B4
	movs r6, 0x3C
	movs r4, 0x1
	b _08000892
	.align 2, 0
_08000834: .4byte gUnknown_80B6AA0
_08000838: .4byte 0x00000321
_0800083C:
	cmp r4, 0x1
	bne _08000854
	ldr r0, _08000850
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	movs r4, 0x3
	b _08000892
	.align 2, 0
_08000850: .4byte gUnknown_80B6B14
_08000854:
	ldr r0, _08000864
	movs r1, 0
	movs r2, 0
	ldr r3, _08000868
	bl sub_80141B4
_08000860:
	movs r4, 0x2
	b _08000892
	.align 2, 0
_08000864: .4byte gUnknown_80B6B78
_08000868: .4byte 0x00000301
_0800086C:
	cmp r6, 0
	ble _08000860
	ldr r0, _08000880
	ldrh r1, [r0, 0x2]
	subs r6, 0x1
	movs r0, 0x3
	ands r1, r0
	cmp r1, 0
	beq _08000892
	b _08000860
	.align 2, 0
_08000880: .4byte gUnknown_20255F0
_08000884:
	add r0, sp, 0x8
	bl sub_80144A4
	cmp r0, 0
	bne _08000892
_0800088E:
	movs r4, 0x1
	negs r4, r4
_08000892:
	movs r0, 0
	bl xxx_update_stuff
	cmp r4, 0
	bge _080007B4
	bl sub_8014490
	movs r0, 0
	bl xxx_update_stuff
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl xxx_update_stuff
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8000734

	thumb_func_start sub_80008C0
sub_80008C0:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r4, 0
	movs r6, 0
	movs r0, 0
	bl xxx_update_some_bg_tiles
	bl sub_8014144
	bl sub_80097B0
	movs r0, 0x2
	bl sub_800CDA8
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
	ldr r1, _08000930
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	strh r0, [r1]
	bl sub_8099648
	bl sub_8094C14
	movs r0, 0
	bl sub_8099690
	bl sub_8099744
	bl sub_8099750
	movs r0, 0x3
	bl sub_80063D8
	cmp r5, 0x1
	beq _08000948
	cmp r5, 0x1
	bcc _08000934
	cmp r5, 0x2
	beq _08000950
	cmp r5, 0x3
	beq _08000950
	b _080009A2
	.align 2, 0
_08000930: .4byte gUnknown_2026E4E
_08000934:
	ldr r0, _08000944
	movs r1, 0
	movs r2, 0
	movs r3, 0x20
	bl sub_80141B4
	movs r4, 0x2
	b _080009A2
	.align 2, 0
_08000944: .4byte gUnknown_80B6B88
_08000948:
	ldr r0, _0800094C
	b _08000952
	.align 2, 0
_0800094C: .4byte gUnknown_80B6BDC
_08000950:
	ldr r0, _08000960
_08000952:
	ldr r3, _08000964
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0800095C:
	movs r4, 0x1
	b _080009A2
	.align 2, 0
_08000960: .4byte gUnknown_80B6CB8
_08000964: .4byte 0x00000301
_08000968:
	cmp r4, 0x1
	beq _08000994
	cmp r4, 0x1
	bgt _08000976
	cmp r4, 0
	beq _0800097C
	b _0800099E
_08000976:
	cmp r4, 0x2
	beq _080009A2
	b _0800099E
_0800097C:
	cmp r6, 0
	ble _0800095C
	ldr r0, _08000990
	ldrh r1, [r0, 0x2]
	subs r6, 0x1
	movs r0, 0x3
	ands r1, r0
	cmp r1, 0
	beq _080009A2
	b _0800095C
	.align 2, 0
_08000990: .4byte gUnknown_20255F0
_08000994:
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080009A2
_0800099E:
	movs r4, 0x1
	negs r4, r4
_080009A2:
	movs r0, 0
	bl xxx_update_stuff
	cmp r4, 0
	bge _08000968
	bl sub_8014490
	movs r0, 0
	bl xxx_update_stuff
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl xxx_update_stuff
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80008C0

	thumb_func_start sub_80009D0
sub_80009D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08000A04
	add sp, r4
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x18
	bl sub_8001658
	adds r7, r0, 0
	movs r0, 0
	mov r10, r0
	bl sub_801180C
	movs r0, 0x10
	bl sub_80118C4
	cmp r7, 0x7
	bne _08000A30
	cmp r4, 0x2
	bne _08000A08
	movs r7, 0x8
	b _08000A3A
	.align 2, 0
_08000A04: .4byte 0xfffffdd4
_08000A08:
	cmp r4, 0x3
	bne _08000A3A
	movs r7, 0xB
	movs r0, 0
	movs r1, 0x18
	movs r2, 0xB
	bl sub_80018D8
	bl sub_8096BD0
	movs r0, 0x3
	bl sub_8000734
	b _08000A3A
_08000A24:
	movs r3, 0x1
	mov r10, r3
	b _08000EC6
_08000A2A:
	movs r0, 0x1
	mov r10, r0
	b _08000EC6
_08000A30:
	cmp r7, 0
	beq _08000A3A
	cmp r7, 0xB
	beq _08000A3A
	movs r7, 0x1
_08000A3A:
	movs r0, 0
	movs r1, 0x41
	bl sub_80015C0
_08000A42:
	cmp r7, 0x4
	bne _08000AB6
	movs r0, 0
	movs r1, 0xD
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, _08000A9C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [sp, 0x8]
	mov r0, sp
	strb r4, [r0, 0x4]
	movs r0, 0x9
	bl sub_80023E4
	mov r1, sp
	strb r0, [r1, 0x5]
	mov r0, sp
	bl sub_800F990
	ldr r0, [sp, 0x8]
	bl MemoryFree
	mov r0, sp
	ldrb r0, [r0, 0xC]
	cmp r0, 0x3A
	beq _08000B70
	mov r0, sp
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	beq _08000AA0
	bl sub_8002694
	lsls r0, 16
	asrs r2, r0, 16
	b _08000AA2
	.align 2, 0
_08000A9C: .4byte 0x00004e30
_08000AA0:
	movs r2, 0x9
_08000AA2:
	movs r0, 0
	movs r1, 0xD
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xE
	movs r2, 0
	bl sub_80018D8
	b _08000B70
_08000AB6:
	cmp r7, 0x5
	bne _08000B9C
	movs r0, 0
	movs r1, 0x12
	bl sub_8001658
	lsls r0, 16
	asrs r0, 16
	mov r8, r0
	bl sub_80A2740
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	ldr r5, _08000B18
	add r5, sp
_08000AD6:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_80A28F0
	adds r1, r5, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x3E
	ble _08000AD6
	cmp r6, 0x63
	beq _08000B70
	add r4, sp, 0xB8
	movs r0, 0x3F
	strb r0, [r4, 0x4]
	add r0, sp, 0xC0
	adds r1, r6, 0
	bl sub_80011CC
	ldrb r1, [r4, 0xD]
	add r0, sp, 0x128
	strb r1, [r0]
	mov r0, r8
	bl sub_80A2750
	lsls r0, 16
	asrs r0, 16
	adds r5, r4, 0
	cmp r0, 0x1
	beq _08000B1C
	cmp r0, 0x2
	beq _08000B3C
	b _08000B50
	.align 2, 0
_08000B18: .4byte 0x00000129
_08000B1C:
	add r4, sp, 0x170
	add r0, sp, 0x174
	mov r1, r8
	bl sub_80990EC
	lsls r0, 24
	cmp r0, 0
	beq _08000B50
	ldrb r0, [r4, 0x10]
	strb r0, [r5, 0x14]
	add r0, sp, 0xD0
	add r1, sp, 0x18C
	movs r2, 0x58
	bl memcpy
	b _08000B50
_08000B3C:
	ldrb r0, [r5, 0x8]
	add r1, sp, 0xD0
	bl sub_8096A08
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08000B4E
	movs r0, 0x1
_08000B4E:
	strb r0, [r5, 0x14]
_08000B50:
	ldr r0, _08000B74
	movs r1, 0x8
	bl MemoryAlloc
	add r4, sp, 0x168
	str r0, [r4]
	adds r0, r5, 0
	bl sub_8010268
	ldr r0, [r4]
	bl MemoryFree
	add r0, sp, 0x16C
	ldrb r0, [r0]
	cmp r0, 0
	bne _08000B78
_08000B70:
	movs r7, 0x2
	b _08000A42
	.align 2, 0
_08000B74: .4byte 0x00006474
_08000B78:
	movs r0, 0
	movs r1, 0x13
	mov r2, r8
	bl sub_80018D8
	ldr r1, _08000B98
	movs r0, 0x2
	str r0, [r1]
	movs r0, 0x4
	bl sub_800A8F8
	movs r0, 0x5
	bl sub_8001334
	adds r5, r0, 0
	b _08000BEC
	.align 2, 0
_08000B98: .4byte gUnknown_203B03C
_08000B9C:
	cmp r7, 0x8
	bne _08000BA4
	movs r5, 0
	b _08000BEC
_08000BA4:
	cmp r7, 0x7
	bne _08000BAC
	movs r5, 0x2
	b _08000BEC
_08000BAC:
	cmp r7, 0xB
	bne _08000BB6
	bl sub_80012C0
	b _08000BBE
_08000BB6:
	cmp r7, 0xC
	bne _08000BBE
	bl sub_8001248
_08000BBE:
	ldr r1, _08000BE0
	movs r0, 0x2
	str r0, [r1]
	movs r0, 0x4
	bl sub_800A8F8
	adds r0, r7, 0
	bl sub_8001334
	adds r5, r0, 0
	cmp r5, 0xE
	bne _08000BD8
	b _08000EC6
_08000BD8:
	cmp r5, 0x5
	bne _08000BE4
	movs r7, 0x4
	b _08000A42
	.align 2, 0
_08000BE0: .4byte gUnknown_203B03C
_08000BE4:
	cmp r5, 0x6
	bne _08000BEC
	movs r7, 0x5
	b _08000A42
_08000BEC:
	add r6, sp, 0x170
	movs r4, 0
	strb r4, [r6, 0x11]
	strb r4, [r6, 0x10]
	movs r3, 0xC6
	lsls r3, 1
	add r3, sp
	mov r8, r3
	mov r0, r8
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	movs r0, 0
	mov r9, r0
	strh r4, [r6, 0x24]
	cmp r5, 0x7
	beq _08000C3C
	cmp r5, 0x8
	bne _08000C38
	add r0, sp, 0x174
	add r1, sp, 0x228
	bl sub_80991E0
	lsls r0, 24
	cmp r0, 0
	beq _08000C4C
	ldrb r0, [r6, 0x4]
	mov r1, r8
	bl sub_8096A08
	lsls r0, 24
	cmp r0, 0
	bne _08000C32
	b _08000D98
_08000C32:
	movs r0, 0x1
	strb r0, [r6, 0x10]
	b _08000D98
_08000C38:
	cmp r5, 0xA
	bne _08000C52
_08000C3C:
	add r0, sp, 0x174
	add r1, sp, 0x228
	bl sub_80991E0
	lsls r0, 24
	cmp r0, 0
	beq _08000C4C
	b _08000D98
_08000C4C:
	movs r5, 0xD
	movs r7, 0x9
	b _08000D98
_08000C52:
	cmp r5, 0x9
	bne _08000C6C
	add r0, sp, 0x174
	add r1, sp, 0x228
	bl sub_80991E0
	lsls r0, 24
	cmp r0, 0
	beq _08000C66
	b _08000D98
_08000C66:
	movs r5, 0xB
	movs r7, 0xC
	b _08000D98
_08000C6C:
	cmp r5, 0
	bne _08000D04
	bl sub_8011FA8
	adds r1, r0, 0
	ldr r0, _08000CA0
	cmp r1, r0
	bne _08000CC8
	movs r2, 0x1
	strb r2, [r6, 0x11]
	strb r2, [r6, 0x8]
	mov r3, r9
	strb r3, [r6, 0xF]
	ldr r0, _08000CA4
	ldr r1, [r0]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _08000CA8
	strb r2, [r6, 0x10]
	adds r1, 0x4
	mov r0, r8
	movs r2, 0x58
	bl memcpy
	b _08000CAC
	.align 2, 0
_08000CA0: .4byte 0x000f1207
_08000CA4: .4byte gUnknown_203B484
_08000CA8:
	mov r0, r9
	strb r0, [r6, 0x10]
_08000CAC:
	ldr r4, _08000CC4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0xC]
	b _08000CE4
	.align 2, 0
_08000CC4: .4byte gUnknown_203B484
_08000CC8:
	ldr r0, _08000CD8
	cmp r1, r0
	bne _08000CDC
	movs r5, 0x1
	movs r7, 0xB
	bl sub_8096BD0
	b _08000CE4
	.align 2, 0
_08000CD8: .4byte 0x000f1208
_08000CDC:
	movs r5, 0x1
	movs r7, 0xB
	bl sub_8096BD0
_08000CE4:
	cmp r5, 0x1
	bne _08000D98
	ldr r4, _08000D00
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1, 0xC]
	b _08000D98
	.align 2, 0
_08000D00: .4byte gUnknown_203B484
_08000D04:
	cmp r5, 0x2
	bne _08000D98
	bl sub_8011C1C
	cmp r0, 0x2
	bne _08000D34
	bl sub_8011FA8
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r6, 0x8]
	mov r3, r9
	strb r3, [r6, 0x11]
	ldr r0, _08000D30
	cmp r1, r0
	beq _08000D36
	adds r0, 0x1
	movs r5, 0x1
	movs r7, 0xB
	bl sub_8096BD0
	b _08000D36
	.align 2, 0
_08000D30: .4byte 0x000f1207
_08000D34:
	movs r5, 0x3
_08000D36:
	cmp r5, 0x3
	bne _08000D7A
	bl sub_8001170
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0x1
	movs r7, 0xB
	bl sub_8096BD0
	cmp r4, 0x3F
	beq _08000D70
	cmp r4, 0x63
	beq _08000D70
	adds r0, r4, 0
	bl sub_80900E4
	lsls r0, 24
	cmp r0, 0
	beq _08000D70
	bl sub_8011C1C
	cmp r0, 0x2
	bne _08000D6C
	movs r5, 0x3
	movs r7, 0x7
	b _08000D70
_08000D6C:
	movs r5, 0xC
	movs r7, 0xA
_08000D70:
	cmp r5, 0x1
	bne _08000D98
	bl sub_8011C1C
	b _08000D98
_08000D7A:
	cmp r5, 0x4
	bne _08000D8E
	movs r5, 0x1
	movs r7, 0xB
	bl sub_8096BD0
	movs r0, 0x1
	bl sub_80008C0
	b _08000D98
_08000D8E:
	cmp r5, 0x1
	bne _08000D98
	movs r7, 0xB
	bl sub_8096BD0
_08000D98:
	subs r0, r5, 0x7
	cmp r0, 0x3
	bls _08000DAC
	cmp r5, 0
	beq _08000E1E
	cmp r5, 0x2
	beq _08000DAC
	cmp r5, 0x3
	beq _08000DAC
	b _08000A42
_08000DAC:
	cmp r5, 0
	beq _08000E1E
	cmp r5, 0x2
	beq _08000E1E
	cmp r5, 0x3
	beq _08000E1E
	bl sub_8001170
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_8097758
	cmp r5, 0x9
	bne _08000E00
	ldr r4, _08000DF4
	add r4, sp
	adds r0, r4, 0
	bl sub_8099394
	lsls r0, 24
	cmp r0, 0
	beq _08000E00
	ldrb r0, [r4]
	bl sub_8095228
	adds r2, r0, 0
	adds r0, 0x2C
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	ble _08000DF8
	subs r1, 0x1
	b _08000DFA
	.align 2, 0
_08000DF4: .4byte 0x0000022a
_08000DF8:
	movs r1, 0
_08000DFA:
	adds r0, r2, 0
	adds r0, 0x2C
	strb r1, [r0]
_08000E00:
	cmp r6, 0x3F
	bne _08000E0C
	movs r0, 0
	bl sub_8000734
	b _08000E1E
_08000E0C:
	adds r0, r6, 0
	bl sub_80900E4
	lsls r0, 24
	cmp r0, 0
	bne _08000E1E
	movs r0, 0
	bl sub_8000734
_08000E1E:
	ldr r0, _08000E70
	movs r4, 0x1
	str r4, [r0]
	movs r0, 0x3
	bl sub_800A8F8
	add r5, sp, 0x170
	str r4, [r5]
	add r0, sp, 0x174
	bl sub_80011E8
	adds r0, r5, 0
	bl sub_8000EDC
	add r4, sp, 0x1EC
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0x3
	bne _08000E46
	b _08000A24
_08000E46:
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	bne _08000E50
	b _08000A2A
_08000E50:
	movs r0, 0
	movs r1, 0x41
	bl sub_80015C0
	ldrh r0, [r4]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bhi _08000EBE
	lsls r0, 2
	ldr r1, _08000E74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08000E70: .4byte gUnknown_203B03C
_08000E74: .4byte _08000E78
	.align 2, 0
_08000E78:
	.4byte _08000EB6
	.4byte _08000EBE
	.4byte _08000E94
	.4byte _08000EB2
	.4byte _08000EBE
	.4byte _08000E94
	.4byte _08000EBE
_08000E94:
	movs r7, 0x9
	movs r0, 0xF7
	lsls r0, 1
	add r0, sp
	ldrb r0, [r0]
	movs r3, 0x1
	cmp r0, 0
	beq _08000EA6
	movs r3, 0x2
_08000EA6:
	movs r0, 0
	movs r1, 0x41
	movs r2, 0
	bl sub_800199C
	b _08000A42
_08000EB2:
	movs r7, 0xA
	b _08000A42
_08000EB6:
	movs r7, 0xC
	bl sub_8096BD0
	b _08000A42
_08000EBE:
	movs r7, 0xB
	bl sub_8096BD0
	b _08000A42
_08000EC6:
	mov r0, r10
	movs r3, 0x8B
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80009D0

	thumb_func_start sub_8000EDC
sub_8000EDC:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r5, 0x1
	ldr r0, _08000F24
	str r5, [r0]
	movs r0, 0x3
	bl sub_800A8F8
	bl sub_8014144
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8043D50
	ldr r0, [sp]
	movs r1, 0x7
	bl MemoryAlloc
	str r0, [r4, 0x74]
	ldr r0, [sp, 0x4]
	movs r1, 0x7
	bl MemoryAlloc
	str r0, [r4, 0x78]
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _08000F68
	ldr r0, [r4, 0x74]
	ldr r1, [sp]
	bl sub_801277C
	adds r7, r4, 0
	adds r7, 0x7C
	b _08000F2E
	.align 2, 0
_08000F24: .4byte gUnknown_203B03C
_08000F28:
	movs r0, 0
	bl xxx_update_stuff
_08000F2E:
	bl sub_80127A8
	lsls r0, 24
	cmp r0, 0
	bne _08000F28
	bl sub_8012828
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8012834
	bl sub_8011830
	cmp r5, 0
	beq _08000F58
	ldr r0, _08000F54
	bl sub_80121E0
	b _08000F5E
	.align 2, 0
_08000F54: .4byte 0x000f1208
_08000F58:
	ldr r0, _08000F64
	bl sub_80121E0
_08000F5E:
	bl sub_8011854
	b _08000F78
	.align 2, 0
_08000F64: .4byte 0x000f1209
_08000F68:
	bl sub_809674C
	bl sub_80961B4
	bl sub_808ED00
	adds r7, r4, 0
	adds r7, 0x7C
_08000F78:
	cmp r5, 0
	beq _08000F92
	adds r0, r4, 0
	bl sub_8001340
	bl sub_8099648
	bl sub_8094C14
	movs r0, 0
	bl sub_8099690
	b _08000F96
_08000F92:
	movs r0, 0x5
	strh r0, [r7]
_08000F96:
	adds r5, r7, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r6, 0x2
	negs r6, r6
	cmp r0, r6
	bne _08000FAC
	adds r0, r4, 0
	adds r0, 0x84
	bl sub_809542C
_08000FAC:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x3
	beq _08000FB8
	cmp r0, r6
	bne _0800100C
_08000FB8:
	adds r0, r4, 0
	adds r0, 0x80
	bl sub_8097688
	bl sub_8011924
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, r6
	bne _08000FD8
	ldr r0, [r4, 0x74]
	ldr r1, [sp]
	movs r2, 0x1
	bl sub_8012850
	b _08000FFA
_08000FD8:
	ldr r0, [r4, 0x74]
	ldr r1, [sp]
	movs r2, 0
	bl sub_8012850
	b _08000FFA
_08000FE4:
	cmp r0, 0x1
	bne _08000FF4
	ldr r0, [r4, 0x78]
	bl MemoryFree
	ldr r0, [r4, 0x74]
	bl MemoryFree
_08000FF4:
	movs r0, 0
	bl xxx_update_stuff
_08000FFA:
	bl sub_80128B0
	cmp r0, 0x2
	beq _08001006
	cmp r0, 0x3
	bne _08000FE4
_08001006:
	bl sub_80129FC
	b _0800101C
_0800100C:
	bl sub_808ED00
	ldr r0, [r4, 0x78]
	bl MemoryFree
	ldr r0, [r4, 0x74]
	bl MemoryFree
_0800101C:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8000EDC

	thumb_func_start sub_8001024
sub_8001024:
	push {r4,lr}
	ldr r1, _08001040
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001040: .4byte gUnknown_203B040
	thumb_func_end sub_8001024

	thumb_func_start sub_8001044
sub_8001044:
	push {r4,lr}
	ldr r1, _08001060
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001060: .4byte gUnknown_203B040
	thumb_func_end sub_8001044

	thumb_func_start sub_8001064
sub_8001064:
	push {r4,r5,lr}
	sub sp, 0x28
	bl sub_808D33C
	cmp r0, 0
	bne _080010AE
	ldr r5, _0800109C
	ldrb r0, [r5, 0x8]
	cmp r0, 0
	bne _080010A0
	add r4, sp, 0x14
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_808D8BC
	mov r0, sp
	adds r1, r4, 0
	bl sub_80922F4
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r1, 0x1
	mov r2, sp
	bl sub_808CE74
	b _080010AE
	.align 2, 0
_0800109C: .4byte gUnknown_203B040
_080010A0:
	movs r4, 0x4
	ldrsh r0, [r5, r4]
	adds r2, r5, 0
	adds r2, 0x8
	movs r1, 0x1
	bl sub_808CE74
_080010AE:
	bl sub_808D378
	cmp r0, 0
	bne _080010F2
	ldr r5, _080010E0
	ldrb r0, [r5, 0x1C]
	cmp r0, 0
	bne _080010E4
	add r4, sp, 0x14
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_808D8BC
	mov r0, sp
	adds r1, r4, 0
	bl sub_80922F4
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	movs r1, 0
	mov r2, sp
	bl sub_808CE74
	b _080010F2
	.align 2, 0
_080010E0: .4byte gUnknown_203B040
_080010E4:
	movs r4, 0x6
	ldrsh r0, [r5, r4]
	adds r2, r5, 0
	adds r2, 0x1C
	movs r1, 0
	bl sub_808CE74
_080010F2:
	ldr r3, _08001164
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _08001126
	ldr r2, _08001168
	movs r4, 0x4
	ldrsh r0, [r2, r4]
	cmp r0, 0
	beq _0800111C
	cmp r1, r0
	beq _0800111C
_0800110A:
	adds r2, 0x8
	movs r0, 0x4
	ldrsh r1, [r2, r0]
	cmp r1, 0
	beq _0800111C
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	cmp r0, r1
	bne _0800110A
_0800111C:
	ldr r2, [r2]
	movs r0, 0
	movs r1, 0x27
	bl sub_80018D8
_08001126:
	ldr r3, _08001164
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	cmp r1, 0
	beq _0800115A
	ldr r2, _0800116C
	movs r4, 0x4
	ldrsh r0, [r2, r4]
	cmp r0, 0
	beq _08001150
	cmp r1, r0
	beq _08001150
_0800113E:
	adds r2, 0x8
	movs r0, 0x4
	ldrsh r1, [r2, r0]
	cmp r1, 0
	beq _08001150
	movs r4, 0x6
	ldrsh r0, [r3, r4]
	cmp r0, r1
	bne _0800113E
_08001150:
	ldr r2, [r2]
	movs r0, 0
	movs r1, 0x26
	bl sub_80018D8
_0800115A:
	add sp, 0x28
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001164: .4byte gUnknown_203B040
_08001168: .4byte gUnknown_80B690C
_0800116C: .4byte gUnknown_80B6994
	thumb_func_end sub_8001064

	thumb_func_start sub_8001170
sub_8001170:
	push {r4,lr}
	sub sp, 0x8
	add r4, sp, 0x4
	movs r0, 0x63
	strb r0, [r4]
	mov r1, sp
	adds r1, 0x2
	mov r0, sp
	bl sub_80992E0
	lsls r0, 24
	cmp r0, 0
	beq _08001196
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80A2740
	b _080011BE
_08001196:
	adds r0, r4, 0
	bl sub_8099328
	lsls r0, 24
	cmp r0, 0
	bne _080011C0
	adds r0, r4, 0
	bl sub_8099360
	lsls r0, 24
	cmp r0, 0
	bne _080011C0
	mov r0, sp
	adds r0, 0x5
	bl sub_8099394
	lsls r0, 24
	cmp r0, 0
	beq _080011C0
	movs r0, 0x3F
_080011BE:
	strb r0, [r4]
_080011C0:
	ldrb r0, [r4]
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8001170

	thumb_func_start sub_80011CC
sub_80011CC:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	strb r1, [r4]
	strb r5, [r4, 0x1]
	bl sub_80011E8
	strb r5, [r4, 0xB]
	strb r5, [r4, 0x4]
	strb r5, [r4, 0xC]
	strb r5, [r4, 0xD]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80011CC

	thumb_func_start sub_80011E8
sub_80011E8:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x8
	bl sub_80023E4
	strb r0, [r4, 0x5]
	movs r0, 0x3
	bl sub_80023E4
	strb r0, [r4, 0x6]
	movs r0, 0x7
	bl sub_80023E4
	strb r0, [r4, 0x8]
	movs r0, 0
	bl sub_80023E4
	strb r0, [r4, 0x9]
	movs r0, 0x5
	bl sub_80023E4
	strb r0, [r4, 0xA]
	movs r0, 0x18
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0800123C
	movs r0, 0x19
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0800123C
	movs r0, 0x1A
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0800123C
	movs r0, 0x1
	b _0800123E
_0800123C:
	movs r0, 0
_0800123E:
	strb r0, [r4, 0x7]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80011E8

	thumb_func_start sub_8001248
sub_8001248:
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0
_0800124E:
	movs r0, 0x64
	bl RandomCapped
	cmp r0, 0x31
	bgt _08001266
	lsls r0, r4, 2
	ldr r1, _080012B8
	ldr r1, [r1]
	adds r0, r1
	strb r5, [r0, 0x2]
	strb r5, [r0, 0x1]
	strb r5, [r0]
_08001266:
	adds r4, 0x1
	cmp r4, 0x13
	ble _0800124E
	bl sub_80910B4
	movs r4, 0
	ldr r5, _080012BC
	movs r3, 0x1
_08001276:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _08001298
	lsrs r0, r2, 1
	ands r0, r3
	cmp r0, 0
	beq _08001298
	adds r1, 0x28
	movs r0, 0
	strb r0, [r1]
_08001298:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08001276
	ldr r0, _080012B8
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080012B8: .4byte gUnknown_203B460
_080012BC: .4byte gUnknown_203B45C
	thumb_func_end sub_8001248

	thumb_func_start sub_80012C0
sub_80012C0:
	push {r4,r5,lr}
	movs r3, 0
	ldr r4, _08001324
	movs r2, 0
_080012C8:
	lsls r1, r3, 2
	ldr r0, [r4]
	adds r1, r0
	strb r2, [r1, 0x2]
	strb r2, [r1, 0x1]
	strb r2, [r1]
	adds r3, 0x1
	cmp r3, 0x13
	ble _080012C8
	bl sub_80910B4
	movs r3, 0
	ldr r5, _08001328
	movs r4, 0x1
_080012E4:
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r4, 0
	ands r0, r2
	cmp r0, 0
	beq _08001306
	lsrs r0, r2, 1
	ands r0, r4
	cmp r0, 0
	beq _08001306
	adds r1, 0x28
	movs r0, 0
	strb r0, [r1]
_08001306:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _080012E4
	ldr r0, _08001324
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001324: .4byte gUnknown_203B460
_08001328: .4byte gUnknown_203B45C
	thumb_func_end sub_80012C0

	thumb_func_start NDS_LoadOverlay_GroundMain
NDS_LoadOverlay_GroundMain:
	bx lr
	thumb_func_end NDS_LoadOverlay_GroundMain

	thumb_func_start nullsub_2
nullsub_2:
	bx lr
	thumb_func_end nullsub_2

	thumb_func_start sub_8001334
sub_8001334:
	push {lr}
	bl sub_8098468
	pop {r1}
	bx r1
	thumb_func_end sub_8001334

	thumb_func_start sub_8001340
sub_8001340:
	push {r4,lr}
	adds r4, r0, 0
	bl nullsub_2
	adds r0, r4, 0
	bl sub_8042F6C
	bl NDS_LoadOverlay_GroundMain
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8001340

	thumb_func_start nullsub_3
nullsub_3:
	bx lr
	thumb_func_end nullsub_3

	thumb_func_start sub_800135C
sub_800135C:
	push {r4-r7,lr}
	movs r1, 0
	ldr r4, _0800138C
	ldr r3, _08001390
	movs r2, 0
_08001366:
	adds r0, r1, r3
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, r4
	ble _08001366
	movs r6, 0
_08001372:
	lsls r1, r6, 4
	ldr r0, _08001394
	adds r5, r1, r0
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r7, r6, 0x1
	cmp r0, 0
	beq _080013B4
	cmp r0, 0x8
	beq _080013B4
	movs r4, 0
	b _080013AC
	.align 2, 0
_0800138C: .4byte 0x000003ff
_08001390: .4byte gUnknown_2000A88
_08001394: .4byte gUnknown_80B7394
_08001398:
	movs r0, 0xA
	ldrsh r3, [r5, r0]
	movs r0, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_800199C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080013AC:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _08001398
_080013B4:
	lsls r0, r7, 16
	asrs r6, r0, 16
	cmp r6, 0x50
	ble _08001372
	movs r0, 0
	movs r1, 0x1
	bl sub_80015C0
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x4
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x5
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x6
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x8
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0x9
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xA
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xB
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0
	movs r1, 0xD
	movs r2, 0xA2
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xE
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0xF
	movs r2, 0xA2
	bl sub_80018D8
	movs r4, 0x1
	negs r4, r4
	movs r0, 0
	movs r1, 0x10
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x11
	movs r2, 0x24
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x12
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x13
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x14
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x16
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x18
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x19
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1B
	adds r2, r4, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1C
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1D
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1E
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x1F
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x24
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x25
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x26
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x27
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x29
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x2A
	movs r2, 0
	bl sub_80018D8
	movs r0, 0
	movs r1, 0x2B
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2C
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2D
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2E
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x2F
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x30
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x31
	bl sub_80015C0
	movs r0, 0
	movs r1, 0x41
	bl sub_80015C0
	bl sub_80972F4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800135C

	thumb_func_start sub_8001564
sub_8001564:
	push {lr}
	bl nullsub_128
	pop {r0}
	bx r0
	thumb_func_end sub_8001564

	thumb_func_start sub_8001570
sub_8001570:
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _08001584
	cmp r6, r0
	bgt _0800158C
	lsls r1, r6, 4
	ldr r0, _08001588
	b _08001590
	.align 2, 0
_08001584: .4byte 0x000003ff
_08001588: .4byte gUnknown_80B7394
_0800158C:
	lsls r1, r6, 4
	ldr r0, _08001598
_08001590:
	adds r5, r1, r0
	movs r4, 0
	b _080015B0
	.align 2, 0
_08001598: .4byte 0x080b2d30
_0800159C:
	movs r0, 0xA
	ldrsh r3, [r5, r0]
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_800199C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080015B0:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _0800159C
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8001570

	thumb_func_start sub_80015C0
sub_80015C0:
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _080015D4
	cmp r6, r0
	bgt _080015DC
	lsls r1, r6, 4
	ldr r0, _080015D8
	b _080015E0
	.align 2, 0
_080015D4: .4byte 0x000003ff
_080015D8: .4byte gUnknown_80B7394
_080015DC:
	lsls r1, r6, 4
	ldr r0, _080015E8
_080015E0:
	adds r5, r1, r0
	movs r4, 0
	b _080015FE
	.align 2, 0
_080015E8: .4byte 0x080b2d30
_080015EC:
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_800199C
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080015FE:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _080015EC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80015C0

	thumb_func_start sub_800160C
sub_800160C:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 16
	asrs r1, r2, 16
	ldr r0, _08001630
	cmp r1, r0
	bgt _0800163C
	lsls r1, 4
	ldr r0, _08001634
	adds r1, r0
	str r1, [r3]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	ldr r1, _08001638
	adds r0, r1
	b _0800164C
	.align 2, 0
_08001630: .4byte 0x000003ff
_08001634: .4byte gUnknown_80B7394
_08001638: .4byte gUnknown_2000A88
_0800163C:
	lsls r1, 4
	ldr r0, _08001654
	adds r1, r0
	str r1, [r3]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	lsls r0, 2
	adds r0, r4, r0
_0800164C:
	str r0, [r3, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001654: .4byte 0x080b2d30
	thumb_func_end sub_800160C

	thumb_func_start sub_8001658
sub_8001658:
	push {r4,lr}
	sub sp, 0x8
	adds r2, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	mov r0, sp
	adds r1, r2, 0
	adds r2, r4, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _0800167C
	b _08001778
_0800167C:
	lsls r0, 2
	ldr r1, _08001688
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001688: .4byte _0800168C
	.align 2, 0
_0800168C:
	.4byte _080016AC
	.4byte _080016C2
	.4byte _080016C8
	.4byte _080016D2
	.4byte _080016D8
	.4byte _080016E0
	.4byte _080016C2
	.4byte _080016E6
_080016AC:
	ldr r0, [sp]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	ands r1, r0
	b _0800173E
_080016C2:
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	b _0800177A
_080016C8:
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	b _0800177A
_080016D2:
	ldr r0, [sp, 0x4]
	ldrh r0, [r0]
	b _0800177A
_080016D8:
	ldr r0, [sp, 0x4]
	movs r1, 0
	ldrsh r0, [r0, r1]
	b _0800177A
_080016E0:
	ldr r0, [sp, 0x4]
	ldr r0, [r0]
	b _0800177A
_080016E6:
	adds r0, r4, 0
	subs r0, 0x17
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _08001778
	lsls r0, 2
	ldr r1, _080016FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080016FC: .4byte _08001700
	.align 2, 0
_08001700:
	.4byte _08001734
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001746
	.4byte _0800174C
	.4byte _08001754
	.4byte _08001764
_08001734:
	bl sub_8098F94
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
_0800173E:
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _0800177A
_08001746:
	bl sub_808D480
	b _0800177A
_0800174C:
	movs r0, 0
	bl sub_808D544
	b _0800177A
_08001754:
	ldr r0, _08001760
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	b _0800176C
	.align 2, 0
_08001760: .4byte gUnknown_203B460
_08001764:
	ldr r0, _08001774
	ldr r0, [r0]
	movs r1, 0x99
	lsls r1, 2
_0800176C:
	adds r0, r1
	ldr r0, [r0]
	b _0800177A
	.align 2, 0
_08001774: .4byte gUnknown_203B460
_08001778:
	movs r0, 0
_0800177A:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8001658

	thumb_func_start sub_8001784
sub_8001784:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	mov r0, sp
	adds r1, r3, 0
	adds r2, r5, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _080017AC
	b _080018CC
_080017AC:
	lsls r0, 2
	ldr r1, _080017B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080017B8: .4byte _080017BC
	.align 2, 0
_080017BC:
	.4byte _080017DC
	.4byte _08001800
	.4byte _08001808
	.4byte _08001814
	.4byte _0800181E
	.4byte _0800182A
	.4byte _08001800
	.4byte _08001834
_080017DC:
	ldr r0, [sp]
	ldrh r1, [r0, 0x6]
	adds r1, r4, r1
	lsls r1, 16
	lsrs r0, r1, 19
	ldr r2, [sp, 0x4]
	adds r2, r0
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldrb r0, [r2]
	ands r1, r0
	b _0800188E
_08001800:
	ldr r0, [sp, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	b _080018CE
_08001808:
	ldr r0, [sp, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	b _080018CE
_08001814:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	b _080018CE
_0800181E:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	b _080018CE
_0800182A:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 2
	adds r1, r0
	ldr r0, [r1]
	b _080018CE
_08001834:
	adds r0, r5, 0
	subs r0, 0x17
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _080018CC
	lsls r0, 2
	ldr r1, _0800184C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800184C: .4byte _08001850
	.align 2, 0
_08001850:
	.4byte _08001884
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _08001896
	.4byte _0800189C
	.4byte _080018A4
	.4byte _080018B8
_08001884:
	bl sub_8098F94
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
_0800188E:
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _080018CE
_08001896:
	bl sub_808D480
	b _080018CE
_0800189C:
	movs r0, 0
	bl sub_808D544
	b _080018CE
_080018A4:
	ldr r0, _080018B4
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	b _080018CE
	.align 2, 0
_080018B4: .4byte gUnknown_203B460
_080018B8:
	ldr r0, _080018C8
	ldr r0, [r0]
	movs r2, 0x99
	lsls r2, 2
	adds r0, r2
	ldr r0, [r0]
	b _080018CE
	.align 2, 0
_080018C8: .4byte gUnknown_203B460
_080018CC:
	movs r0, 0
_080018CE:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8001784

	thumb_func_start sub_80018D8
sub_80018D8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r2, 0
	lsls r1, 16
	asrs r5, r1, 16
	mov r0, sp
	adds r1, r3, 0
	adds r2, r5, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _08001990
	lsls r0, 2
	ldr r1, _08001908
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001908: .4byte _0800190C
	.align 2, 0
_0800190C:
	.4byte _0800192C
	.4byte _08001958
	.4byte _08001958
	.4byte _0800195E
	.4byte _0800195E
	.4byte _08001964
	.4byte _08001958
	.4byte _08001968
_0800192C:
	ldr r0, [sp]
	movs r2, 0x6
	ldrsh r1, [r0, r2]
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r3, r0, 24
	cmp r4, 0
	beq _0800194A
	ldr r2, [sp, 0x4]
	ldrb r1, [r2]
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
	b _08001990
_0800194A:
	ldr r2, [sp, 0x4]
	ldrb r1, [r2]
	adds r0, r3, 0
	orrs r0, r1
	eors r0, r3
	strb r0, [r2]
	b _08001990
_08001958:
	ldr r0, [sp, 0x4]
	strb r4, [r0]
	b _08001990
_0800195E:
	ldr r0, [sp, 0x4]
	strh r4, [r0]
	b _08001990
_08001964:
	ldr r0, [sp, 0x4]
	b _0800198E
_08001968:
	cmp r5, 0x22
	beq _08001972
	cmp r5, 0x23
	beq _08001984
	b _08001990
_08001972:
	ldr r0, _08001980
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	b _0800198E
	.align 2, 0
_08001980: .4byte gUnknown_203B460
_08001984:
	ldr r0, _08001998
	ldr r0, [r0]
	movs r2, 0x99
	lsls r2, 2
	adds r0, r2
_0800198E:
	str r4, [r0]
_08001990:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001998: .4byte gUnknown_203B460
	thumb_func_end sub_80018D8

	thumb_func_start sub_800199C
sub_800199C:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	mov r0, sp
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_800160C
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _08001A68
	lsls r0, 2
	ldr r1, _080019D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080019D0: .4byte _080019D4
	.align 2, 0
_080019D4:
	.4byte _080019F4
	.4byte _08001A2C
	.4byte _08001A2C
	.4byte _08001A34
	.4byte _08001A34
	.4byte _08001A3E
	.4byte _08001A2C
	.4byte _08001A44
_080019F4:
	ldr r0, [sp]
	ldrh r0, [r0, 0x6]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r2, r0, 19
	ldr r1, [sp, 0x4]
	adds r3, r1, r2
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	lsrs r1, 16
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r2, r0, 24
	cmp r6, 0
	beq _08001A20
	ldrb r1, [r3]
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3]
	b _08001A68
_08001A20:
	ldrb r1, [r3]
	adds r0, r2, 0
	orrs r0, r1
	eors r0, r2
	strb r0, [r3]
	b _08001A68
_08001A2C:
	ldr r0, [sp, 0x4]
	adds r0, r5
	strb r6, [r0]
	b _08001A68
_08001A34:
	ldr r1, [sp, 0x4]
	lsls r0, r5, 1
	adds r0, r1
	strh r6, [r0]
	b _08001A68
_08001A3E:
	ldr r1, [sp, 0x4]
	lsls r0, r5, 2
	b _08001A64
_08001A44:
	cmp r7, 0x22
	beq _08001A4E
	cmp r7, 0x23
	beq _08001A5C
	b _08001A68
_08001A4E:
	ldr r0, _08001A58
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	b _08001A64
	.align 2, 0
_08001A58: .4byte gUnknown_203B460
_08001A5C:
	ldr r0, _08001A70
	ldr r0, [r0]
	movs r1, 0x99
	lsls r1, 2
_08001A64:
	adds r0, r1
	str r6, [r0]
_08001A68:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001A70: .4byte gUnknown_203B460
	thumb_func_end sub_800199C

	thumb_func_start sub_8001A74
sub_8001A74:
	push {lr}
	sub sp, 0x8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r1, 0
	bl sub_800160C
	ldr r0, [sp, 0x4]
	add sp, 0x8
	pop {r1}
	bx r1
	thumb_func_end sub_8001A74

	thumb_func_start sub_8001A90
sub_8001A90:
	push {lr}
	sub sp, 0x8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	movs r1, 0
	bl sub_800160C
	ldr r0, [sp]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	add sp, 0x8
	pop {r1}
	bx r1
	thumb_func_end sub_8001A90

	thumb_func_start sub_8001AB0
sub_8001AB0:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r7, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	movs r6, 0
	mov r0, sp
	movs r1, 0
	adds r2, r5, 0
	bl sub_800160C
	movs r4, 0
	ldr r0, [sp]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _08001AEC
_08001AD2:
	lsls r2, r4, 16
	lsrs r2, 16
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_8001784
	adds r6, r0
	adds r4, 0x1
	ldr r0, [sp]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _08001AD2
_08001AEC:
	adds r0, r6, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001AB0

	thumb_func_start sub_8001AF8
sub_8001AF8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r3, 16
	asrs r3, 16
	mov r0, sp
	movs r1, 0
	adds r2, r3, 0
	bl sub_800160C
	ldr r1, [sp, 0x4]
	movs r2, 0
	b _08001B1C
_08001B16:
	strb r0, [r4]
	adds r4, 0x1
	adds r2, 0x1
_08001B1C:
	cmp r2, r5
	bge _08001B28
	ldrb r0, [r1]
	adds r1, 0x1
	cmp r0, 0
	bne _08001B16
_08001B28:
	movs r0, 0
	strb r0, [r4]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8001AF8

	thumb_func_start sub_8001B34
sub_8001B34:
	push {r4,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r2, 0
	lsls r3, 16
	asrs r3, 16
	mov r0, sp
	movs r1, 0
	adds r2, r3, 0
	bl sub_800160C
	ldr r1, [sp, 0x4]
	movs r2, 0
	b _08001B56
_08001B50:
	strb r0, [r1]
	adds r1, 0x1
	adds r2, 0x1
_08001B56:
	cmp r2, r4
	bge _08001B62
	ldrb r0, [r1]
	adds r1, 0x1
	cmp r0, 0
	bne _08001B50
_08001B62:
	ldr r0, [sp]
	movs r3, 0x8
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bge _08001B7E
	movs r3, 0
_08001B6E:
	strb r3, [r1]
	adds r1, 0x1
	adds r2, 0x1
	ldr r0, [sp]
	movs r4, 0x8
	ldrsh r0, [r0, r4]
	cmp r2, r0
	blt _08001B6E
_08001B7E:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8001B34

	thumb_func_start sub_8001B88
sub_8001B88:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	str r0, [r5]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	str r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8001B88

	thumb_func_start sub_8001BB4
sub_8001BB4:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r0, 16
	asrs r4, r0, 16
	add r2, sp, 0x10
	adds r0, r4, 0
	add r1, sp, 0xC
	bl sub_8001B88
	ldr r1, _08001C20
	ldr r3, [sp, 0xC]
	ldr r0, [sp, 0x10]
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0x6
	adds r2, r4, 0
	bl Log
	cmp r4, 0x3
	bne _08001BF8
	ldr r0, [sp, 0xC]
	cmp r5, r0
	bne _08001BEE
	ldr r0, [sp, 0x10]
	cmp r6, r0
	beq _08001BF8
_08001BEE:
	movs r0, 0
	movs r1, 0x19
	movs r2, 0
	bl sub_80018D8
_08001BF8:
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_800199C
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	adds r3, r6, 0
	bl sub_800199C
	cmp r4, 0x4
	beq _08001C76
	cmp r4, 0x4
	bgt _08001C24
	cmp r4, 0x3
	beq _08001C2A
	b _08001CBA
	.align 2, 0
_08001C20: .4byte gUnknown_80B72CC
_08001C24:
	cmp r4, 0xC
	beq _08001CA4
	b _08001CBA
_08001C2A:
	subs r0, r5, 0x1
	cmp r0, 0x1A
	bhi _08001CBA
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x8
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001C48
	movs r0, 0
	bl sub_80976F8
_08001C48:
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001C5E
	movs r0, 0x1
	bl sub_80976F8
_08001C5E:
	movs r0, 0x3
	movs r1, 0x11
	movs r2, 0
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001CBA
	movs r0, 0x2
	bl sub_80976F8
	b _08001CBA
_08001C76:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08001C8C
	movs r0, 0x4
	bl sub_80976F8
_08001C8C:
	movs r0, 0x4
	movs r1, 0x20
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08001CBA
	movs r0, 0x5
	bl sub_80976F8
	b _08001CBA
_08001CA4:
	movs r0, 0xC
	movs r1, 0x37
	movs r2, 0x2
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08001CBA
	movs r0, 0x3
	bl sub_80976F8
_08001CBA:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8001BB4

	thumb_func_start sub_8001CC4
sub_8001CC4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	adds r5, r0, 0
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	cmp r5, 0x3A
	beq _08001CFE
	cmp r5, r6
	bcc _08001CFA
	cmp r7, 0
	blt _08001CFE
	cmp r5, r6
	bne _08001CFE
	cmp r0, r7
	bge _08001CFE
_08001CFA:
	movs r0, 0x1
	b _08001D00
_08001CFE:
	movs r0, 0
_08001D00:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001CC4

	thumb_func_start sub_8001D08
sub_8001D08:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	adds r5, r0, 0
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	cmp r5, r6
	bne _08001D3A
	cmp r7, 0
	blt _08001D36
	cmp r0, r7
	bne _08001D3A
_08001D36:
	movs r0, 0x1
	b _08001D3C
_08001D3A:
	movs r0, 0
_08001D3C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001D08

	thumb_func_start sub_8001D44
sub_8001D44:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_8001784
	adds r5, r0, 0
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8001784
	cmp r5, 0x3A
	beq _08001D7E
	cmp r5, r6
	bhi _08001D7A
	cmp r7, 0
	blt _08001D7E
	cmp r5, r6
	bne _08001D7E
	cmp r0, r7
	ble _08001D7E
_08001D7A:
	movs r0, 0x1
	b _08001D80
_08001D7E:
	movs r0, 0
_08001D80:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8001D44

	thumb_func_start sub_8001D88
sub_8001D88:
	push {lr}
	sub sp, 0x8
	add r2, sp, 0x4
	movs r0, 0x3
	mov r1, sp
	bl sub_8001B88
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x1A
	bls _08001DA0
	b _080020D4
_08001DA0:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	beq _08001E08
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0x7
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001DDE
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001BB4
	movs r0, 0xE
	movs r1, 0x1
	bl sub_8097418
	movs r0, 0
	movs r1, 0x28
	movs r2, 0x2
	bl sub_80018D8
	b _08001E08
_08001DDE:
	movs r0, 0x4
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001E08
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001E08
	movs r0, 0x4
	movs r1, 0x1D
	movs r2, 0x1
	bl sub_8001BB4
_08001E08:
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001E36
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001E36
	movs r0, 0x4
	movs r1, 0x1F
	movs r2, 0x1
	bl sub_8001BB4
	movs r0, 0xF
	movs r1, 0x1
	bl sub_809733C
_08001E36:
	ldr r0, [sp]
	cmp r0, 0x11
	bhi _08001E3E
	b _080020D4
_08001E3E:
	movs r0, 0x25
	movs r1, 0x1
	bl sub_80973A8
	movs r0, 0xE7
	bl sub_8091130
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08001E72
	ldr r0, _080020DC
	ldr r0, [r0]
	ldr r1, _080020E0
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _08001E72
	movs r0, 0x5
	movs r1, 0x21
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08001E7A
_08001E72:
	movs r0, 0x22
	movs r1, 0x1
	bl sub_80973A8
_08001E7A:
	movs r0, 0x2B
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001E8E
	movs r0, 0x1F
	movs r1, 0x1
	bl sub_80973A8
_08001E8E:
	movs r0, 0x24
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001EA2
	movs r0, 0x20
	movs r1, 0x1
	bl sub_80973A8
_08001EA2:
	movs r0, 0x23
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001EB6
	movs r0, 0x21
	movs r1, 0x1
	bl sub_80973A8
_08001EB6:
	movs r0, 0x19
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001ECA
	movs r0, 0x23
	movs r1, 0x1
	bl sub_80973A8
_08001ECA:
	movs r0, 0x3
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001EE6
	movs r0, 0x24
	movs r1, 0x1
	bl sub_80973A8
	movs r0, 0x28
	movs r1, 0x1
	bl sub_80973A8
_08001EE6:
	movs r0, 0x2C
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001F06
	movs r0, 0x2D
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001F06
	movs r0, 0x26
	movs r1, 0x1
	bl sub_80973A8
_08001F06:
	movs r0, 0x5
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001F20
	movs r0, 0x5
	movs r1, 0x21
	movs r2, 0x1
	bl sub_8001BB4
_08001F20:
	movs r0, 0xE2
	bl sub_8091130
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _08001F3E
	ldr r0, _080020DC
	ldr r0, [r0]
	movs r1, 0x85
	lsls r1, 2
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _08001F7E
_08001F3E:
	movs r0, 0x7
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001F58
	movs r0, 0x7
	movs r1, 0x26
	movs r2, 0x1
	bl sub_8001BB4
_08001F58:
	movs r0, 0x9
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001F7E
	movs r0, 0x37
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08001F7E
	movs r0, 0x9
	movs r1, 0x2E
	movs r2, 0x1
	bl sub_8001BB4
_08001F7E:
	movs r0, 0x9
	movs r1, 0x30
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _0800202A
	movs r0, 0x5
	movs r1, 0x22
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x90
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x91
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x92
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _08001FCC
	movs r0, 0x5
	movs r1, 0x22
	movs r2, 0x1
	bl sub_8001BB4
_08001FCC:
	movs r0, 0xB
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08002002
	movs r0, 0x5
	movs r1, 0x21
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08002002
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08002002
	movs r0, 0xB
	movs r1, 0x33
	movs r2, 0x1
	bl sub_8001BB4
_08002002:
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _08002016
	movs r0, 0x27
	movs r1, 0x1
	bl sub_80973A8
_08002016:
	movs r0, 0xE
	bl sub_8092600
	lsls r0, 24
	cmp r0, 0
	beq _0800202A
	movs r0, 0x29
	movs r1, 0x1
	bl sub_80973A8
_0800202A:
	movs r0, 0x5
	movs r1, 0x22
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08002086
	movs r0, 0xA
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _0800205C
	movs r0, 0xA
	movs r1, 0x31
	movs r2, 0x1
	bl sub_8001BB4
	movs r0, 0x1B
	movs r1, 0x1
	bl sub_809733C
_0800205C:
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _08002086
	movs r0, 0xB
	movs r1, 0x34
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	cmp r0, 0
	bne _08002086
	movs r0, 0xC
	movs r1, 0x35
	movs r2, 0x1
	bl sub_8001BB4
_08002086:
	movs r0, 0x6
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _080020AE
	movs r0, 0x89
	lsls r0, 1
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _080020AE
	movs r0, 0x6
	movs r1, 0x24
	movs r2, 0x1
	bl sub_8001BB4
_080020AE:
	movs r0, 0x8
	movs r1, 0
	movs r2, 0
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	beq _080020D4
	ldr r0, _080020E4
	bl sub_808E734
	lsls r0, 24
	cmp r0, 0
	beq _080020D4
	movs r0, 0x8
	movs r1, 0x2C
	movs r2, 0x1
	bl sub_8001BB4
_080020D4:
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_080020DC: .4byte gUnknown_203B460
_080020E0: .4byte 0x0000021e
_080020E4: .4byte 0x00000113
	thumb_func_end sub_8001D88

	thumb_func_start sub_80020E8
sub_80020E8:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0xB
	bhi _08002182
	lsls r0, r2, 2
	ldr r1, _080020FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080020FC: .4byte _08002100
	.align 2, 0
_08002100:
	.4byte _08002130
	.4byte _08002134
	.4byte _08002138
	.4byte _0800213C
	.4byte _08002142
	.4byte _0800214C
	.4byte _08002156
	.4byte _0800215C
	.4byte _08002162
	.4byte _08002168
	.4byte _08002170
	.4byte _0800217A
_08002130:
	adds r0, r4, 0
	b _08002194
_08002134:
	subs r0, r3, r4
	b _08002194
_08002138:
	adds r0, r3, r4
	b _08002194
_0800213C:
	adds r0, r3, 0
	muls r0, r4
	b _08002194
_08002142:
	adds r0, r3, 0
	adds r1, r4, 0
	bl __divsi3
	b _08002194
_0800214C:
	adds r0, r3, 0
	adds r1, r4, 0
	bl __modsi3
	b _08002194
_08002156:
	ands r3, r4
	adds r0, r3, 0
	b _08002194
_0800215C:
	orrs r3, r4
	adds r0, r3, 0
	b _08002194
_08002162:
	eors r3, r4
	adds r0, r3, 0
	b _08002194
_08002168:
	movs r0, 0x1
	lsls r0, r4
	orrs r0, r3
	b _08002194
_08002170:
	movs r0, 0x1
	lsls r0, r4
	bics r3, r0
	adds r0, r3, 0
	b _08002194
_0800217A:
	adds r0, r4, 0
	bl OtherRandomCapped
	b _08002194
_08002182:
	ldr r0, _0800218C
	ldr r1, _08002190
	bl FatalError
	.align 2, 0
_0800218C: .4byte gUnknown_80B7318
_08002190: .4byte gUnknown_80B7324
_08002194:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80020E8

	thumb_func_start sub_800219C
sub_800219C:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0xA
	bhi _08002248
	lsls r0, r2, 2
	ldr r1, _080021B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080021B0: .4byte _080021B4
	.align 2, 0
_080021B4:
	.4byte _080021E0
	.4byte _080021E4
	.4byte _080021E8
	.4byte _080021FE
	.4byte _08002212
	.4byte _08002208
	.4byte _0800221C
	.4byte _080021F2
	.4byte _08002226
	.4byte _08002232
	.4byte _0800223E
_080021E0:
	movs r0, 0x1
	b _08002258
_080021E4:
	movs r0, 0
	b _08002258
_080021E8:
	movs r0, 0
	cmp r3, r4
	bne _08002258
	movs r0, 0x1
	b _08002258
_080021F2:
	adds r1, r3, 0
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _08002258
_080021FE:
	movs r0, 0
	cmp r3, r4
	ble _08002258
	movs r0, 0x1
	b _08002258
_08002208:
	movs r0, 0
	cmp r3, r4
	blt _08002258
	movs r0, 0x1
	b _08002258
_08002212:
	movs r0, 0
	cmp r3, r4
	bge _08002258
	movs r0, 0x1
	b _08002258
_0800221C:
	movs r0, 0
	cmp r3, r4
	bgt _08002258
	movs r0, 0x1
	b _08002258
_08002226:
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _08002258
	movs r0, 0x1
	b _08002258
_08002232:
	adds r0, r3, 0
	eors r0, r4
	cmp r0, 0
	beq _08002258
	movs r0, 0x1
	b _08002258
_0800223E:
	asrs r3, r4
	movs r0, 0x1
	ands r3, r0
	adds r0, r3, 0
	b _08002258
_08002248:
	ldr r0, _08002250
	ldr r1, _08002254
	bl FatalError
	.align 2, 0
_08002250: .4byte gUnknown_80B7350
_08002254: .4byte gUnknown_80B735C
_08002258:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800219C

	thumb_func_start sub_8002260
sub_8002260:
	push {lr}
	bl sub_80020E8
	pop {r1}
	bx r1
	thumb_func_end sub_8002260

	thumb_func_start sub_800226C
sub_800226C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r4, 16
	asrs r4, 16
	adds r1, r4, 0
	bl sub_8001658
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80020E8
	adds r2, r0, 0
	mov r0, r8
	adds r1, r4, 0
	bl sub_80018D8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800226C

	thumb_func_start sub_80022A0
sub_80022A0:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	mov r9, r3
	lsls r5, 16
	asrs r5, 16
	lsls r4, 16
	asrs r4, 16
	adds r1, r5, 0
	bl sub_8001658
	adds r6, r0, 0
	mov r0, r8
	adds r1, r4, 0
	bl sub_8001658
	adds r1, r0, 0
	adds r0, r6, 0
	mov r2, r9
	bl sub_80020E8
	adds r2, r0, 0
	mov r0, r8
	adds r1, r5, 0
	bl sub_80018D8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80022A0

	thumb_func_start sub_80022E8
sub_80022E8:
	push {lr}
	bl sub_800219C
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80022E8

	thumb_func_start sub_80022F8
sub_80022F8:
	push {r4,r5,lr}
	adds r4, r2, 0
	adds r5, r3, 0
	lsls r1, 16
	asrs r1, 16
	bl sub_8001658
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800219C
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80022F8

	thumb_func_start sub_8002318
sub_8002318:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	adds r4, r2, 0
	mov r8, r3
	lsls r1, 16
	asrs r1, 16
	lsls r4, 16
	asrs r4, 16
	bl sub_8001658
	adds r5, r0, 0
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8001658
	adds r1, r0, 0
	adds r0, r5, 0
	mov r2, r8
	bl sub_800219C
	lsls r0, 24
	lsrs r0, 24
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8002318

	thumb_func_start sub_8002354
sub_8002354:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x3A
	bls _08002362
	movs r0, 0x1
	negs r0, r0
	b _0800236C
_08002362:
	ldr r0, _08002370
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
_0800236C:
	pop {r1}
	bx r1
	.align 2, 0
_08002370: .4byte gUnknown_80B6D90
	thumb_func_end sub_8002354

	thumb_func_start sub_8002374
sub_8002374:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x3A
	bls _08002384
	ldr r0, _08002380
	b _0800238C
	.align 2, 0
_08002380: .4byte gUnknown_80B7378
_08002384:
	ldr r0, _08002390
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
_0800238C:
	pop {r1}
	bx r1
	.align 2, 0
_08002390: .4byte gUnknown_80B6D90
	thumb_func_end sub_8002374

	thumb_func_start sub_8002394
sub_8002394:
	push {lr}
	adds r1, r0, 0
	subs r1, 0x12
	cmp r1, 0x8
	bhi _080023AC
	ldr r0, _080023A8
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	b _080023BA
	.align 2, 0
_080023A8: .4byte gUnknown_80B714C
_080023AC:
	cmp r0, 0xF
	beq _080023B8
	ldr r0, _080023B4
	b _080023BA
	.align 2, 0
_080023B4: .4byte gUnknown_80B7144
_080023B8:
	ldr r0, _080023C0
_080023BA:
	pop {r1}
	bx r1
	.align 2, 0
_080023C0: .4byte gUnknown_80B7388
	thumb_func_end sub_8002394

	thumb_func_start sub_80023C4
sub_80023C4:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0x3
	bls _080023D4
	ldr r0, _080023D0
	b _080023DC
	.align 2, 0
_080023D0: .4byte gUnknown_80B7144
_080023D4:
	ldr r0, _080023E0
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
_080023DC:
	pop {r1}
	bx r1
	.align 2, 0
_080023E0: .4byte gUnknown_80B71A0
	thumb_func_end sub_80023C4

	thumb_func_start sub_80023E4
sub_80023E4:
	push {r4,lr}
	cmp r0, 0x1D
	bls _080023EC
	b _0800264E
_080023EC:
	lsls r0, 2
	ldr r1, _080023F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080023F8: .4byte _080023FC
	.align 2, 0
_080023FC:
	.4byte _08002474
	.4byte _08002482
	.4byte _0800248E
	.4byte _0800249A
	.4byte _080024A6
	.4byte _080024BE
	.4byte _080024E6
	.4byte _080024F4
	.4byte _08002500
	.4byte _0800250C
	.4byte _0800251A
	.4byte _08002526
	.4byte _08002532
	.4byte _0800255A
	.4byte _08002566
	.4byte _0800257A
	.4byte _0800258E
	.4byte _0800259C
	.4byte _080025AA
	.4byte _080025B8
	.4byte _080025C6
	.4byte _080025D4
	.4byte _080025E2
	.4byte _080025F0
	.4byte _080025FE
	.4byte _0800260C
	.4byte _0800261A
	.4byte _08002628
	.4byte _08002630
	.4byte _08002644
_08002474:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x2
	bl sub_8001D44
	b _08002648
_08002482:
	movs r0, 0x3
	movs r1, 0x3
	movs r2, 0x3
	bl sub_8001D44
	b _08002648
_0800248E:
	movs r0, 0x3
	movs r1, 0x4
	movs r2, 0x3
	bl sub_8001D44
	b _08002648
_0800249A:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0
	bl sub_8001D44
	b _08002648
_080024A6:
	movs r4, 0
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08002556
	movs r0, 0x3
	movs r1, 0xD
	b _080024D4
_080024BE:
	movs r4, 0
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x3
	bl sub_8001D44
	lsls r0, 24
	cmp r0, 0
	beq _08002556
	movs r0, 0x3
	movs r1, 0xF
_080024D4:
	movs r2, 0
	bl sub_8001CC4
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	b _08002556
_080024E6:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x11
	bl sub_8001D44
	b _08002648
_080024F4:
	movs r0, 0x3
	movs r1, 0x12
	movs r2, 0x2
	bl sub_8001D44
	b _08002648
_08002500:
	movs r0, 0x3
	movs r1, 0x12
	movs r2, 0x3
	bl sub_8001D44
	b _08002648
_0800250C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x12
	bl sub_8001D44
	b _08002648
_0800251A:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0x4
	bl sub_8001D44
	b _08002648
_08002526:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0x4
	bl sub_8001D44
	b _08002648
_08002532:
	movs r4, 0
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x2
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	bne _08002556
	movs r0, 0x3
	movs r1, 0xB
	movs r2, 0x3
	bl sub_8001D08
	lsls r0, 24
	cmp r0, 0
	bne _08002556
	movs r4, 0x1
_08002556:
	adds r0, r4, 0
	b _08002650
_0800255A:
	movs r0, 0x3
	movs r1, 0x10
	movs r2, 0x2
	bl sub_8001D08
	b _08002648
_08002566:
	movs r0, 0x3
	movs r1, 0x5
	movs r2, 0x7
	bl sub_8001CC4
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08002640
	b _0800263E
_0800257A:
	movs r0, 0x3
	movs r1, 0xF
	movs r2, 0
	bl sub_8001CC4
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _08002640
	b _0800263E
_0800258E:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x7
	bl sub_8001D44
	b _08002648
_0800259C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xC
	bl sub_8001D44
	b _08002648
_080025AA:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xD
	bl sub_8001D44
	b _08002648
_080025B8:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0xF
	bl sub_8001D44
	b _08002648
_080025C6:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x3
	movs r1, 0x10
	bl sub_8001D44
	b _08002648
_080025D4:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x5
	movs r1, 0x21
	bl sub_8001D44
	b _08002648
_080025E2:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x5
	movs r1, 0x22
	bl sub_8001D44
	b _08002648
_080025F0:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x6
	movs r1, 0x24
	bl sub_8001D44
	b _08002648
_080025FE:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x7
	movs r1, 0x2A
	bl sub_8001D44
	b _08002648
_0800260C:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0x8
	movs r1, 0x2C
	bl sub_8001D44
	b _08002648
_0800261A:
	movs r2, 0x1
	negs r2, r2
	movs r0, 0xA
	movs r1, 0x31
	bl sub_8001D44
	b _08002648
_08002628:
	movs r0, 0x29
	bl sub_80973F4
	b _08002648
_08002630:
	bl sub_8092178
	movs r1, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	bne _08002640
_0800263E:
	movs r1, 0x1
_08002640:
	adds r0, r1, 0
	b _08002650
_08002644:
	bl sub_809761C
_08002648:
	lsls r0, 24
	lsrs r0, 24
	b _08002650
_0800264E:
	movs r0, 0
_08002650:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80023E4

	thumb_func_start sub_8002658
sub_8002658:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0800267C
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	movs r3, 0x1
	negs r3, r3
	cmp r0, r3
	beq _0800268C
_0800266E:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r4
	bne _08002680
	ldrb r0, [r1, 0x2]
	b _0800268E
	.align 2, 0
_0800267C: .4byte gUnknown_80B71E4
_08002680:
	adds r1, 0x4
	ldrh r2, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, r3
	bne _0800266E
_0800268C:
	movs r0, 0
_0800268E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002658

	thumb_func_start sub_8002694
sub_8002694:
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, _080026B4
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	beq _080026C2
_080026A8:
	ldrb r0, [r1, 0x2]
	cmp r0, r3
	bne _080026B8
	movs r4, 0
	ldrsh r0, [r1, r4]
	b _080026C6
	.align 2, 0
_080026B4: .4byte gUnknown_80B71E4
_080026B8:
	adds r1, 0x4
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	bne _080026A8
_080026C2:
	movs r0, 0x1
	negs r0, r0
_080026C6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002694

	thumb_func_start sub_80026CC
sub_80026CC:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092600
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80026CC

	thumb_func_start sub_80026E8
sub_80026E8:
	push {lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	lsls r0, 24
	lsrs r0, 24
	bl sub_80925EC
	pop {r0}
	bx r0
	thumb_func_end sub_80026E8

	thumb_func_start sub_8002700
sub_8002700:
	push {lr}
	ldr r1, _08002714
	movs r2, 0x80
	lsls r2, 3
	bl MemoryCopy8
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08002714: .4byte gUnknown_2000A88
	thumb_func_end sub_8002700

	thumb_func_start sub_8002718
sub_8002718:
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl sub_800160C
	ldr r0, _08002748
	movs r2, 0x80
	lsls r2, 3
	adds r1, r4, 0
	bl MemoryCopy8
	ldr r0, [sp]
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	ldr r0, [sp, 0x4]
	ldr r0, [r0]
	cmp r1, r0
	bne _0800274C
	movs r0, 0x1
	b _0800274E
	.align 2, 0
_08002748: .4byte gUnknown_2000A88
_0800274C:
	movs r0, 0
_0800274E:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002718

	thumb_func_start sub_8002758
sub_8002758:
	push {lr}
	adds r2, r0, 0
	movs r0, 0
	movs r1, 0x1
	movs r3, 0x9
	bl sub_800226C
	pop {r0}
	bx r0
	thumb_func_end sub_8002758

	thumb_func_start sub_800276C
sub_800276C:
	movs r0, 0
	bx lr
	thumb_func_end sub_800276C

	thumb_func_start nullsub_140
nullsub_140:
	bx lr
	thumb_func_end nullsub_140

	thumb_func_start sub_8002774
sub_8002774:
	sub sp, 0x4
	str r0, [sp]
	mov r0, sp
	ldrb r1, [r0, 0x2]
	movs r0, 0xF8
	adds r2, r0, 0
	ands r2, r1
	lsls r2, 7
	mov r1, sp
	ldrb r3, [r1, 0x1]
	adds r1, r0, 0
	ands r1, r3
	lsls r1, 2
	orrs r2, r1
	mov r1, sp
	ldrb r1, [r1]
	ands r0, r1
	lsrs r0, 3
	orrs r0, r2
	add sp, 0x4
	bx lr
	thumb_func_end sub_8002774

	thumb_func_start sub_80027A0
sub_80027A0:
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r2, r0, 16
	adds r3, r2, 0
	mov r4, sp
	movs r0, 0x1F
	ands r0, r2
	lsls r1, r0, 3
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _080027BE
	movs r0, 0x7
	orrs r1, r0
_080027BE:
	strb r1, [r4]
	mov r4, sp
	movs r0, 0xF8
	lsls r0, 2
	ands r0, r2
	lsrs r1, r0, 2
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _080027D6
	movs r0, 0x7
	orrs r1, r0
_080027D6:
	strb r1, [r4, 0x1]
	mov r2, sp
	movs r0, 0xF8
	lsls r0, 7
	ands r0, r3
	lsrs r1, r0, 7
	movs r0, 0x80
	lsls r0, 3
	ands r3, r0
	cmp r3, 0
	beq _080027F0
	movs r0, 0x7
	orrs r1, r0
_080027F0:
	strb r1, [r2, 0x2]
	mov r0, sp
	movs r1, 0
	strb r1, [r0, 0x3]
	ldr r0, [sp]
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80027A0

	thumb_func_start sub_8002804
sub_8002804:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r3, 0
_0800280C:
	adds r1, r5, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	muls r0, r4
	cmp r0, 0
	bge _0800281A
	adds r0, 0xFF
_0800281A:
	asrs r0, 8
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0x3
	ble _0800280C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8002804

	thumb_func_start sub_800282C
sub_800282C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	mov r9, r0
	str r1, [sp, 0x20]
	adds r7, r2, 0
	mov r8, r3
	adds r0, r1, 0
	bl __floatsisf
	adds r1, r0, 0
	ldr r0, _08002904
	bl __divsf3
	str r0, [sp, 0x24]
	movs r5, 0
	mov r0, sp
	adds r0, 0x10
	str r0, [sp, 0x2C]
	str r0, [sp, 0x34]
	mov r10, sp
_0800285C:
	adds r6, r7, r5
	movs r4, 0
	ldrsb r4, [r6, r4]
	adds r0, r4, 0
	bl __floatsisf
	cmp r4, 0
	bge _08002872
	ldr r1, _08002908
	bl __addsf3
_08002872:
	mov r1, r10
	adds r1, 0x4
	mov r10, r1
	subs r1, 0x4
	stm r1!, {r0}
	mov r1, r8
	adds r0, r1, r5
	ldrb r0, [r0]
	ldrb r1, [r6]
	subs r0, r1
	bl __floatsisf
	ldr r1, [sp, 0x24]
	bl __mulsf3
	ldr r1, [sp, 0x34]
	stm r1!, {r0}
	str r1, [sp, 0x34]
	adds r5, 0x1
	cmp r5, 0x3
	ble _0800285C
	ldr r0, [r7]
	mov r1, r9
	adds r1, 0x4
	mov r9, r1
	subs r1, 0x4
	stm r1!, {r0}
	movs r5, 0x1
	ldr r0, [sp, 0x20]
	subs r0, 0x1
	str r0, [sp, 0x28]
	mov r1, r8
	ldr r1, [r1]
	str r1, [sp, 0x30]
	cmp r5, r0
	bge _080028EE
_080028BA:
	movs r6, 0
	adds r5, 0x1
	mov r10, r5
	movs r0, 0x4
	add r0, r9
	mov r8, r0
	mov r5, sp
	ldr r7, [sp, 0x2C]
_080028CA:
	mov r1, r9
	adds r4, r1, r6
	ldr r0, [r5]
	ldm r7!, {r1}
	bl __addsf3
	stm r5!, {r0}
	bl __fixunssfsi
	strb r0, [r4]
	adds r6, 0x1
	cmp r6, 0x3
	ble _080028CA
	mov r9, r8
	mov r5, r10
	ldr r0, [sp, 0x28]
	cmp r5, r0
	blt _080028BA
_080028EE:
	ldr r1, [sp, 0x30]
	mov r0, r9
	str r1, [r0]
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002904: .4byte 0x3f800000
_08002908: .4byte 0x43800000
	thumb_func_end sub_800282C

	thumb_func_start sub_800290C
sub_800290C:
	push {lr}
	ldr r3, [r0]
	cmp r3, r1
	ble _08002918
	str r1, [r0]
	b _08002920
_08002918:
	negs r2, r1
	cmp r3, r2
	bge _08002920
	str r2, [r0]
_08002920:
	ldr r2, [r0, 0x4]
	cmp r2, r1
	bgt _0800292C
	negs r1, r1
	cmp r2, r1
	bge _0800292E
_0800292C:
	str r1, [r0, 0x4]
_0800292E:
	pop {r0}
	bx r0
	thumb_func_end sub_800290C

	thumb_func_start sub_8002934
sub_8002934:
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	mov r10, r0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x1C]
	adds r0, r4, r5
	mov r9, r0
	ldr r0, [r6]
	muls r0, r4
	ldr r1, [r2]
	muls r1, r5
	adds r0, r1
	mov r1, r9
	bl __divsi3
	mov r1, r10
	str r0, [r1]
	ldr r0, [r6, 0x4]
	muls r0, r4
	mov r2, r8
	ldr r1, [r2, 0x4]
	muls r1, r5
	adds r0, r1
	mov r1, r9
	bl __divsi3
	mov r1, r10
	str r0, [r1, 0x4]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8002934

	thumb_func_start sub_8002984
sub_8002984:
	push {r4,lr}
	lsls r0, 24
	asrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	subs r0, r1, 0x1
	cmp r0, 0x8
	bhi _08002A68
	lsls r0, 2
	ldr r1, _080029A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080029A0: .4byte _080029A4
	.align 2, 0
_080029A4:
	.4byte _080029C8
	.4byte _080029D0
	.4byte _080029D8
	.4byte _080029E0
	.4byte _080029E8
	.4byte _080029F4
	.4byte _08002A34
	.4byte _08002A4E
	.4byte _08002A5E
_080029C8:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x7
	b _080029EE
_080029D0:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x1
	b _080029EE
_080029D8:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x6
	b _080029EE
_080029E0:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x2
	b _080029EE
_080029E8:
	cmp r4, 0
	blt _08002A68
	adds r4, 0x4
_080029EE:
	movs r0, 0x7
	ands r4, r0
	b _08002A68
_080029F4:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08002A18
	movs r0, 0x2
	bl OtherRandomCapped
	adds r1, r4, 0x7
	lsls r0, 1
	adds r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002A10
	adds r0, r1, 0x7
_08002A10:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	b _08002A64
_08002A18:
	movs r0, 0x3
	bl OtherRandomCapped
	adds r1, r4, 0x6
	lsls r0, 1
	adds r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002A2C
	adds r0, r1, 0x7
_08002A2C:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	b _08002A64
_08002A34:
	movs r0, 0x3
	bl OtherRandomCapped
	adds r1, r4, 0x7
	adds r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002A46
	adds r0, r1, 0x7
_08002A46:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	b _08002A64
_08002A4E:
	movs r0, 0x8
	bl OtherRandomCapped
	movs r2, 0x2
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	b _08002A64
_08002A5E:
	movs r0, 0x8
	bl OtherRandomCapped
_08002A64:
	lsls r0, 24
	asrs r4, r0, 24
_08002A68:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002984

	thumb_func_start sub_8002A70
sub_8002A70:
	push {r4,lr}
	lsls r0, 24
	asrs r3, r0, 24
	lsls r1, 24
	asrs r4, r1, 24
	lsls r2, 24
	lsrs r0, r2, 24
	cmp r3, r4
	beq _08002AFC
	subs r0, 0x1
	cmp r0, 0xA
	bhi _08002AFC
	lsls r0, 2
	ldr r1, _08002A94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08002A94: .4byte _08002A98
	.align 2, 0
_08002A98:
	.4byte _08002AC4
	.4byte _08002ACC
	.4byte _08002AD4
	.4byte _08002ADC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AFC
	.4byte _08002AF2
	.4byte _08002AE8
_08002AC4:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x7
	b _08002AE2
_08002ACC:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x1
	b _08002AE2
_08002AD4:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x6
	b _08002AE2
_08002ADC:
	cmp r3, 0
	blt _08002AFC
	adds r3, 0x2
_08002AE2:
	movs r0, 0x7
	ands r3, r0
	b _08002AFC
_08002AE8:
	adds r0, r3, 0
	adds r1, r4, 0
	bl sub_8002B04
	adds r3, r0, 0
_08002AF2:
	adds r0, r3, 0
	adds r1, r4, 0
	bl sub_8002B04
	adds r3, r0, 0
_08002AFC:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002A70

	thumb_func_start sub_8002B04
sub_8002B04:
	push {lr}
	lsls r0, 24
	asrs r2, r0, 24
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08002B56
	adds r0, r2, 0
	subs r0, 0x8
	subs r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B24
	adds r0, r1, 0x7
_08002B24:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	cmp r0, 0
	beq _08002B56
	cmp r0, 0x3
	bgt _08002B40
	adds r1, r2, 0x1
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B4C
	adds r0, r2, 0
	adds r0, 0x8
	b _08002B4C
_08002B40:
	adds r1, r2, 0x7
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B4C
	adds r0, r2, 0
	adds r0, 0xE
_08002B4C:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	lsls r0, 24
	asrs r2, r0, 24
_08002B56:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8002B04

	thumb_func_start sub_8002B5C
sub_8002B5C:
	push {lr}
	lsls r0, 24
	asrs r2, r0, 24
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08002BAE
	adds r0, r2, 0
	subs r0, 0x8
	subs r1, r0
	adds r0, r1, 0
	cmp r1, 0
	bge _08002B7C
	adds r0, r1, 0x7
_08002B7C:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	cmp r0, 0
	beq _08002BAE
	cmp r0, 0x3
	bgt _08002B98
	adds r1, r2, 0x2
	adds r0, r1, 0
	cmp r1, 0
	bge _08002BA4
	adds r0, r2, 0
	adds r0, 0x9
	b _08002BA4
_08002B98:
	adds r1, r2, 0x6
	adds r0, r1, 0
	cmp r1, 0
	bge _08002BA4
	adds r0, r2, 0
	adds r0, 0xD
_08002BA4:
	asrs r0, 3
	lsls r0, 3
	subs r0, r1, r0
	lsls r0, 24
	asrs r2, r0, 24
_08002BAE:
	movs r0, 0x6
	ands r2, r0
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8002B5C

	thumb_func_start sub_8002BB8
sub_8002BB8:
	push {r4,r5,lr}
	lsls r1, 24
	asrs r1, 21
	ldr r3, _08002BD8
	adds r1, r3
	ldr r5, [r1]
	adds r3, r5, 0
	muls r3, r2
	ldr r1, [r1, 0x4]
	adds r4, r1, 0
	muls r4, r2
	str r3, [r0]
	str r4, [r0, 0x4]
	pop {r4,r5}
	pop {r2}
	bx r2
	.align 2, 0
_08002BD8: .4byte gUnknown_80B7E3C
	thumb_func_end sub_8002BB8

	thumb_func_start sub_8002BDC
sub_8002BDC:
	push {lr}
	ldr r1, [r0]
	cmp r1, 0
	bge _08002BFA
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002BEE
	movs r0, 0x5
	b _08002C2A
_08002BEE:
	cmp r0, 0
	ble _08002BF6
	movs r0, 0x7
	b _08002C2A
_08002BF6:
	movs r0, 0x6
	b _08002C2A
_08002BFA:
	cmp r1, 0
	ble _08002C14
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002C08
	movs r0, 0x3
	b _08002C2A
_08002C08:
	cmp r0, 0
	ble _08002C10
	movs r0, 0x1
	b _08002C2A
_08002C10:
	movs r0, 0x2
	b _08002C2A
_08002C14:
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08002C1E
	movs r0, 0x4
	b _08002C2A
_08002C1E:
	cmp r0, 0
	bgt _08002C28
	movs r0, 0x1
	negs r0, r0
	b _08002C2A
_08002C28:
	movs r0, 0
_08002C2A:
	pop {r1}
	bx r1
	thumb_func_end sub_8002BDC

	thumb_func_start sub_8002C30
sub_8002C30:
	push {lr}
	ldr r1, [r0, 0x4]
	cmp r1, 0
	bge _08002C3C
	movs r0, 0x4
	b _08002C5A
_08002C3C:
	cmp r1, 0
	ble _08002C44
	movs r0, 0
	b _08002C5A
_08002C44:
	ldr r0, [r0]
	cmp r0, 0
	bge _08002C4E
	movs r0, 0x6
	b _08002C5A
_08002C4E:
	cmp r0, 0
	bgt _08002C58
	movs r0, 0x1
	negs r0, r0
	b _08002C5A
_08002C58:
	movs r0, 0x2
_08002C5A:
	pop {r1}
	bx r1
	thumb_func_end sub_8002C30

	thumb_func_start sub_8002C60
sub_8002C60:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4]
	cmp r0, 0
	bge _08002C6C
	negs r0, r0
_08002C6C:
	adds r1, r0, 0
	ldr r3, [r4, 0x4]
	adds r5, r3, 0
	cmp r3, 0
	bge _08002C78
	negs r5, r3
_08002C78:
	adds r2, r5, 0
	ldr r4, [r4]
	cmp r4, 0
	bge _08002CA8
	cmp r3, 0
	bge _08002C94
	lsls r0, 1
	cmp r2, r0
	bgt _08002CD8
	lsls r0, r5, 1
	cmp r1, r0
	bgt _08002CA0
	movs r0, 0x5
	b _08002CE8
_08002C94:
	lsls r0, 1
	cmp r2, r0
	bgt _08002CE6
	lsls r0, r5, 1
	cmp r1, r0
	ble _08002CA4
_08002CA0:
	movs r0, 0x6
	b _08002CE8
_08002CA4:
	movs r0, 0x7
	b _08002CE8
_08002CA8:
	cmp r4, 0
	ble _08002CD4
	cmp r3, 0
	bge _08002CC0
	lsls r0, 1
	cmp r2, r0
	bgt _08002CD8
	lsls r0, r5, 1
	cmp r1, r0
	bgt _08002CCC
	movs r0, 0x3
	b _08002CE8
_08002CC0:
	lsls r0, 1
	cmp r2, r0
	bgt _08002CE6
	lsls r0, r5, 1
	cmp r1, r0
	ble _08002CD0
_08002CCC:
	movs r0, 0x2
	b _08002CE8
_08002CD0:
	movs r0, 0x1
	b _08002CE8
_08002CD4:
	cmp r3, 0
	bge _08002CDC
_08002CD8:
	movs r0, 0x4
	b _08002CE8
_08002CDC:
	cmp r3, 0
	bgt _08002CE6
	movs r0, 0x1
	negs r0, r0
	b _08002CE8
_08002CE6:
	movs r0, 0
_08002CE8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002C60

	thumb_func_start sub_8002CF0
sub_8002CF0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r4]
	cmp r3, 0
	bge _08002CFC
	negs r3, r3
_08002CFC:
	adds r1, r3, 0
	ldr r3, [r4, 0x4]
	adds r0, r3, 0
	cmp r3, 0
	bge _08002D08
	negs r0, r3
_08002D08:
	adds r2, r0, 0
	ldr r0, [r4]
	cmp r0, 0
	bge _08002D22
	cmp r3, 0
	bge _08002D1A
	cmp r2, r1
	bgt _08002D3C
	b _08002D1E
_08002D1A:
	cmp r2, r1
	bgt _08002D4A
_08002D1E:
	movs r0, 0x6
	b _08002D4C
_08002D22:
	cmp r0, 0
	ble _08002D38
	cmp r3, 0
	bge _08002D30
	cmp r2, r1
	bgt _08002D3C
	b _08002D34
_08002D30:
	cmp r2, r1
	bgt _08002D4A
_08002D34:
	movs r0, 0x2
	b _08002D4C
_08002D38:
	cmp r3, 0
	bge _08002D40
_08002D3C:
	movs r0, 0x4
	b _08002D4C
_08002D40:
	cmp r3, 0
	bgt _08002D4A
	movs r0, 0x1
	negs r0, r0
	b _08002D4C
_08002D4A:
	movs r0, 0
_08002D4C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8002CF0

	thumb_func_start sub_8002D54
sub_8002D54:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [r2]
	ldr r1, [r0]
	subs r3, r1
	str r3, [sp]
	ldr r1, [r2, 0x4]
	ldr r0, [r0, 0x4]
	subs r1, r0
	str r1, [sp, 0x4]
	adds r2, r3, 0
	cmp r2, 0
	blt _08002D8A
	adds r2, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp]
	cmp r2, 0
	bge _08002DA4
	b _08002DA0
_08002D8A:
	subs r2, r3, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp]
	cmp r2, 0
	ble _08002DA4
_08002DA0:
	movs r0, 0
	str r0, [sp]
_08002DA4:
	ldr r2, [sp, 0x4]
	cmp r2, 0
	blt _08002DC2
	adds r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	bge _08002DDC
	b _08002DD8
_08002DC2:
	subs r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	ble _08002DDC
_08002DD8:
	movs r0, 0
	str r0, [sp, 0x4]
_08002DDC:
	mov r0, sp
	bl sub_8002CF0
	lsls r0, 24
	asrs r0, 24
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002D54

	thumb_func_start sub_8002DF0
sub_8002DF0:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [r2]
	ldr r1, [r0]
	subs r3, r1
	str r3, [sp]
	ldr r1, [r2, 0x4]
	ldr r0, [r0, 0x4]
	subs r1, r0
	str r1, [sp, 0x4]
	adds r2, r3, 0
	cmp r2, 0
	blt _08002E26
	adds r2, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp]
	cmp r2, 0
	bge _08002E40
	b _08002E3C
_08002E26:
	subs r2, r3, 0x1
	ldr r0, [r4]
	ldr r1, [r5]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp]
	cmp r2, 0
	ble _08002E40
_08002E3C:
	movs r0, 0
	str r0, [sp]
_08002E40:
	ldr r2, [sp, 0x4]
	cmp r2, 0
	blt _08002E5E
	adds r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	bge _08002E78
	b _08002E74
_08002E5E:
	subs r2, 0x1
	ldr r0, [r4, 0x4]
	ldr r1, [r5, 0x4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	str r2, [sp, 0x4]
	cmp r2, 0
	ble _08002E78
_08002E74:
	movs r0, 0
	str r0, [sp, 0x4]
_08002E78:
	mov r0, sp
	bl sub_8002C60
	lsls r0, 24
	asrs r0, 24
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8002DF0

	.align 2, 0 @ Don't pad with nop.
