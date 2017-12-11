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
	bl sub_8011A38
	bl sub_801180C
	bl nullsub_1
	bl sub_8014144
	bl sub_808CDC0
	bl sub_8097670
	bl sub_8094F88
	bl sub_8094980
	bl sub_8094C14
	bl sub_8097F5C
	bl sub_80923A0
	bl sub_8090998
	bl sub_809207C
	bl sub_8092848
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
	bl nullsub_22
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
	bl sub_800AA14
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
	bl sub_80144C4
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
	bl sub_800A9EC
	ldr r1, _08000718
	str r0, [r1]
	mov r1, sp
	adds r0, r1, r4
	ldr r0, [r0]
	adds r1, r5, 0
	bl sub_800A9EC
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
	bl sub_800AA14
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

	thumb_func_start nullsub_1
nullsub_1:
	bx lr
	thumb_func_end nullsub_1

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
	bl nullsub_1
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
	bl sub_800451C
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
	bl sub_800451C
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
	bl sub_800451C
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
	bl sub_800451C
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
	bl sub_800451C
	movs r2, 0x2
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	b _08002A64
_08002A5E:
	movs r0, 0x8
	bl sub_800451C
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

	thumb_func_start InitHeap
InitHeap:
	push {lr}
	bl InitHeapInternal
	pop {r0}
	bx r0
	thumb_func_end InitHeap

	thumb_func_start MemoryClear8
MemoryClear8:
	push {lr}
	cmp r1, 0
	ble _08002EAA
	movs r2, 0
_08002EA0:
	subs r1, 0x1
	strb r2, [r0]
	adds r0, 0x1
	cmp r1, 0
	bgt _08002EA0
_08002EAA:
	pop {r0}
	bx r0
	thumb_func_end MemoryClear8

	thumb_func_start MemoryClear16
MemoryClear16:
	push {lr}
	cmp r1, 0
	ble _08002EC2
	movs r2, 0
_08002EB8:
	subs r1, 0x2
	strh r2, [r0]
	adds r0, 0x2
	cmp r1, 0
	bgt _08002EB8
_08002EC2:
	pop {r0}
	bx r0
	thumb_func_end MemoryClear16

	thumb_func_start MemoryClear32
MemoryClear32:
	push {lr}
	bl CpuClear
	pop {r0}
	bx r0
	thumb_func_end MemoryClear32

	thumb_func_start MemoryFill8
MemoryFill8:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	cmp r2, 0
	ble _08002EE8
_08002EDE:
	subs r2, 0x1
	strb r1, [r0]
	adds r0, 0x1
	cmp r2, 0
	bgt _08002EDE
_08002EE8:
	pop {r0}
	bx r0
	thumb_func_end MemoryFill8

	thumb_func_start MemoryFill16
MemoryFill16:
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	cmp r2, 0
	ble _08002F00
_08002EF6:
	subs r2, 0x2
	strh r1, [r0]
	adds r0, 0x2
	cmp r2, 0
	bgt _08002EF6
_08002F00:
	pop {r0}
	bx r0
	thumb_func_end MemoryFill16

	thumb_func_start MemoryFill32
MemoryFill32:
	push {lr}
	cmp r2, 0
	ble _08002F12
_08002F0A:
	subs r2, 0x4
	stm r0!, {r1}
	cmp r2, 0
	bgt _08002F0A
_08002F12:
	pop {r0}
	bx r0
	thumb_func_end MemoryFill32

	thumb_func_start MemoryCopy8
MemoryCopy8:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	ble _08002F2E
_08002F20:
	subs r2, 0x1
	ldrb r0, [r1]
	strb r0, [r3]
	adds r1, 0x1
	adds r3, 0x1
	cmp r2, 0
	bgt _08002F20
_08002F2E:
	pop {r0}
	bx r0
	thumb_func_end MemoryCopy8

	thumb_func_start MemoryCopy16
MemoryCopy16:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	ble _08002F4A
_08002F3C:
	subs r2, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	cmp r2, 0
	bgt _08002F3C
_08002F4A:
	pop {r0}
	bx r0
	thumb_func_end MemoryCopy16

	thumb_func_start MemoryCopy32
MemoryCopy32:
	push {lr}
	adds r3, r0, 0
	cmp r2, 0
	ble _08002F62
_08002F58:
	subs r2, 0x4
	ldm r1!, {r0}
	stm r3!, {r0}
	cmp r2, 0
	bgt _08002F58
_08002F62:
	pop {r0}
	bx r0
	thumb_func_end MemoryCopy32

	thumb_func_start InitHeapInternal
InitHeapInternal:
	push {lr}
	sub sp, 0x8
	ldr r0, _08002F90
	str r0, [sp]
	movs r0, 0x90
	lsls r0, 10
	str r0, [sp, 0x4]
	ldr r1, _08002F94
	movs r0, 0
	str r0, [r1]
	ldr r0, _08002F98
	ldr r2, _08002F9C
	mov r1, sp
	movs r3, 0x20
	bl DoInitHeap
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_08002F90: .4byte gUnknown_20011D0
_08002F94: .4byte gUnknown_2000EA8
_08002F98: .4byte gUnknown_2000EB0
_08002F9C: .4byte gUnknown_2000ED0
	thumb_func_end InitHeapInternal

	thumb_func_start DoInitHeap
DoInitHeap:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r4, [r1, 0x4]
	mov r9, r4
	movs r4, 0x4
	negs r4, r4
	mov r5, r9
	ands r5, r4
	mov r9, r5
	ldr r6, _08002FFC
	ldr r4, _08003000
	mov r8, r4
	ldr r5, [r4]
	lsls r4, r5, 2
	adds r4, r6
	str r0, [r4]
	adds r5, 0x1
	mov r4, r8
	str r5, [r4]
	ldr r5, [r1]
	str r5, [r0, 0x14]
	mov r1, r9
	str r1, [r0, 0x18]
	movs r1, 0x2
	str r1, [r0]
	movs r4, 0
	str r4, [r0, 0x4]
	str r2, [r0, 0x8]
	movs r1, 0x1
	str r1, [r0, 0xC]
	str r3, [r0, 0x10]
	str r4, [r2]
	str r4, [r2, 0x4]
	str r5, [r2, 0xC]
	mov r5, r9
	str r5, [r2, 0x10]
	str r4, [r2, 0x14]
	str r4, [r2, 0x8]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002FFC: .4byte gUnknown_2000E88
_08003000: .4byte gUnknown_2000EA8
	thumb_func_end DoInitHeap

	thumb_func_start InitSubHeap
InitSubHeap:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r2, 0
	lsls r4, r3, 1
	adds r4, r3
	movs r2, 0x4
	negs r2, r2
	lsls r4, 3
	ldr r5, [r1, 0x4]
	subs r5, r4
	ands r5, r2
	ldr r2, [r1]
	adds r4, r2, r4
	str r4, [sp]
	str r5, [sp, 0x4]
	mov r1, sp
	bl DoInitHeap
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end InitSubHeap

	thumb_func_start xxx_memory_attr_related
xxx_memory_attr_related:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	bne _0800303C
	movs r0, 0
	b _08003060
_0800303C:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08003048
	movs r0, 0x4
	b _08003060
_08003048:
	movs r2, 0x7
	ands r2, r1
	movs r0, 0x1
	cmp r2, 0x7
	beq _08003060
	movs r0, 0x2
	cmp r2, 0x1
	beq _08003060
	movs r0, 0x5
	cmp r2, 0x3
	bne _08003060
	movs r0, 0x3
_08003060:
	pop {r1}
	bx r1
	thumb_func_end xxx_memory_attr_related

	thumb_func_start MemorySearchFromFront
MemorySearchFromFront:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r2, 0
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080030CC
	movs r4, 0
	ldr r3, [r5, 0x8]
	ldr r2, [r5, 0xC]
	cmp r4, r2
	bge _08003104
	ldr r0, [r3, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08003090
	ldr r0, [r3, 0x10]
	cmp r0, r6
	blt _080030AC
	movs r0, 0
	b _08003108
_08003090:
	adds r4, 0x1
	adds r3, 0x18
	cmp r4, r2
	bge _08003104
	ldr r0, [r3, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08003090
	ldr r0, [r3, 0x10]
	cmp r0, r6
	blt _080030AC
_080030A8:
	adds r0, r4, 0
	b _08003108
_080030AC:
	cmp r4, r2
	bge _08003104
	movs r5, 0x1
	adds r1, r2, 0
_080030B4:
	ldr r0, [r3, 0x4]
	ands r0, r5
	cmp r0, 0
	bne _080030C2
	ldr r0, [r3, 0x10]
	cmp r0, r6
	bge _080030A8
_080030C2:
	adds r4, 0x1
	adds r3, 0x18
	cmp r4, r1
	blt _080030B4
	b _08003104
_080030CC:
	movs r7, 0x1
	negs r7, r7
	ldr r1, _08003100
	movs r4, 0
	ldr r3, [r5, 0x8]
	ldr r2, [r5, 0xC]
	cmp r4, r2
	bge _080030FC
	movs r5, 0x1
_080030DE:
	ldr r0, [r3, 0x4]
	ands r0, r5
	cmp r0, 0
	bne _080030F4
	ldr r0, [r3, 0x10]
	cmp r0, r6
	blt _080030F4
	cmp r0, r1
	bge _080030F4
	adds r7, r4, 0
	adds r1, r0, 0
_080030F4:
	adds r4, 0x1
	adds r3, 0x18
	cmp r4, r2
	blt _080030DE
_080030FC:
	adds r0, r7, 0
	b _08003108
	.align 2, 0
_08003100: .4byte 0x00024001
_08003104:
	movs r0, 0x1
	negs r0, r0
_08003108:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemorySearchFromFront

	thumb_func_start MemorySearchFromBack
MemorySearchFromBack:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r2, 0
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08003168
	ldr r0, [r4, 0xC]
	subs r3, r0, 0x1
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	ldr r1, [r4, 0x8]
	adds r2, r1, r0
	b _08003132
_0800312E:
	subs r3, 0x1
	subs r2, 0x18
_08003132:
	cmp r3, 0
	blt _080031A8
	ldr r0, [r2, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0800312E
	ldr r0, [r2, 0x10]
	cmp r0, r5
	blt _0800314A
_08003146:
	adds r0, r3, 0
	b _080031AC
_0800314A:
	cmp r3, 0
	blt _080031A8
	movs r1, 0x1
_08003150:
	ldr r0, [r2, 0x4]
	ands r0, r1
	cmp r0, 0
	bne _0800315E
	ldr r0, [r2, 0x10]
	cmp r0, r5
	bge _08003146
_0800315E:
	subs r3, 0x1
	subs r2, 0x18
	cmp r3, 0
	bge _08003150
	b _080031A8
_08003168:
	movs r7, 0x1
	negs r7, r7
	ldr r6, _080031A4
	ldr r0, [r4, 0xC]
	subs r3, r0, 0x1
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	ldr r1, [r4, 0x8]
	adds r2, r1, r0
	cmp r3, 0
	blt _080031A0
	movs r1, 0x1
_08003182:
	ldr r0, [r2, 0x4]
	ands r0, r1
	cmp r0, 0
	bne _08003198
	ldr r0, [r2, 0x10]
	cmp r0, r5
	blt _08003198
	cmp r0, r6
	bge _08003198
	adds r7, r3, 0
	adds r6, r0, 0
_08003198:
	subs r3, 0x1
	subs r2, 0x18
	cmp r3, 0
	bge _08003182
_080031A0:
	adds r0, r7, 0
	b _080031AC
	.align 2, 0
_080031A4: .4byte 0x00024001
_080031A8:
	movs r0, 0x1
	negs r0, r0
_080031AC:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemorySearchFromBack

	thumb_func_start MemorySplitFront
MemorySplitFront:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r2, [sp]
	str r3, [sp, 0x4]
	adds r0, r3, 0
	adds r0, 0x3
	str r0, [sp, 0x10]
	movs r0, 0x4
	negs r0, r0
	ldr r1, [sp, 0x10]
	ands r1, r0
	str r1, [sp, 0x10]
	ldr r2, [sp, 0xC]
	lsls r2, 1
	mov r12, r2
	ldr r0, [sp, 0xC]
	add r0, r12
	lsls r0, 3
	ldr r5, [sp, 0x8]
	ldr r2, [r5, 0x8]
	adds r4, r2, r0
	ldr r0, [r4, 0x10]
	cmp r0, r1
	ble _08003260
	ldr r3, [r5, 0xC]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	adds r1, r2, r0
	mov r9, r12
	mov r10, r2
	mov r12, r3
	ldr r6, [r5, 0x10]
	mov r8, r6
	ldr r7, [sp, 0xC]
	cmp r12, r7
	ble _08003222
_0800320A:
	adds r2, r1, 0
	subs r2, 0x18
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	subs r3, 0x1
	adds r1, r2, 0
	ldr r0, [sp, 0xC]
	cmp r3, r0
	bgt _0800320A
_08003222:
	mov r2, r12
	adds r2, 0x1
	ldr r1, [sp, 0x8]
	str r2, [r1, 0xC]
	cmp r2, r8
	ble _08003240
	ldr r0, _08003238
	ldr r1, _0800323C
	mov r3, r8
	bl FatalError
	.align 2, 0
_08003238: .4byte gUnknown_80B7EB8
_0800323C: .4byte gUnknown_80B7EC4
_08003240:
	ldr r0, [sp, 0xC]
	add r0, r9
	lsls r0, 3
	adds r0, 0x18
	mov r2, r10
	adds r1, r2, r0
	ldr r0, [r1, 0xC]
	ldr r5, [sp, 0x10]
	adds r0, r5
	str r0, [r1, 0xC]
	ldr r0, [r1, 0x10]
	subs r0, r5
	str r0, [r1, 0x10]
	str r5, [r4, 0x10]
	ldr r6, [sp, 0x4]
	str r6, [r4, 0x14]
_08003260:
	ldr r0, [sp]
	bl xxx_memory_attr_related
	str r0, [r4]
	ldr r7, [sp]
	str r7, [r4, 0x4]
	ldr r0, [sp, 0x34]
	str r0, [r4, 0x8]
	adds r0, r4, 0
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemorySplitFront

	thumb_func_start MemorySplitBack
MemorySplitBack:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	str r2, [sp]
	str r3, [sp, 0x4]
	adds r0, r3, 0
	adds r0, 0x3
	str r0, [sp, 0x10]
	movs r0, 0x4
	negs r0, r0
	ldr r1, [sp, 0x10]
	ands r1, r0
	str r1, [sp, 0x10]
	ldr r2, [sp, 0xC]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	ldr r5, [sp, 0x8]
	ldr r1, [r5, 0x8]
	adds r4, r1, r0
	ldr r0, [r4, 0x10]
	ldr r6, [sp, 0x10]
	cmp r0, r6
	ble _08003328
	ldr r3, [r5, 0xC]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 3
	adds r1, r0
	mov r12, r3
	ldr r7, [r5, 0x10]
	mov r8, r7
	ldr r0, [r4, 0xC]
	mov r9, r0
	movs r2, 0x18
	adds r2, r4
	mov r10, r2
	ldr r5, [sp, 0xC]
	cmp r12, r5
	ble _080032F6
_080032DE:
	adds r2, r1, 0
	subs r2, 0x18
	adds r0, r2, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	subs r3, 0x1
	adds r1, r2, 0
	ldr r6, [sp, 0xC]
	cmp r3, r6
	bgt _080032DE
_080032F6:
	mov r2, r12
	adds r2, 0x1
	ldr r7, [sp, 0x8]
	str r2, [r7, 0xC]
	cmp r2, r8
	ble _08003314
	ldr r0, _0800330C
	ldr r1, _08003310
	mov r3, r8
	bl FatalError
	.align 2, 0
_0800330C: .4byte gUnknown_80B7EFC
_08003310: .4byte gUnknown_80B7EC4
_08003314:
	ldr r0, [r4, 0x10]
	ldr r1, [sp, 0x10]
	subs r0, r1
	str r0, [r4, 0x10]
	add r0, r9
	mov r4, r10
	str r0, [r4, 0xC]
	str r1, [r4, 0x10]
	ldr r2, [sp, 0x4]
	str r2, [r4, 0x14]
_08003328:
	ldr r0, [sp]
	bl xxx_memory_attr_related
	str r0, [r4]
	ldr r5, [sp]
	str r5, [r4, 0x4]
	ldr r0, [sp, 0x34]
	str r0, [r4, 0x8]
	adds r0, r4, 0
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemorySplitBack

	thumb_func_start MemoryLocateSet
MemoryLocateSet:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	cmp r5, 0
	bne _0800335C
	ldr r5, _08003390
_0800335C:
	asrs r4, r6, 8
	movs r0, 0x1
	orrs r4, r0
	movs r0, 0xFF
	ands r6, r0
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _08003394
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl MemorySearchFromFront
	adds r1, r0, 0
	cmp r1, 0
	blt _080033B4
	str r6, [sp]
	adds r0, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl MemorySplitFront
	ldr r0, [r0, 0xC]
	b _080033CC
	.align 2, 0
_08003390: .4byte gUnknown_2000EB0
_08003394:
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl MemorySearchFromBack
	adds r1, r0, 0
	cmp r1, 0
	blt _080033B4
	str r6, [sp]
	adds r0, r5, 0
	adds r2, r4, 0
	adds r3, r7, 0
	bl MemorySplitBack
	ldr r0, [r0, 0xC]
	b _080033CC
_080033B4:
	ldr r0, _080033C4
	ldr r1, _080033C8
	str r4, [sp]
	str r6, [sp, 0x4]
	adds r2, r5, 0
	adds r3, r7, 0
	bl FatalError
	.align 2, 0
_080033C4: .4byte gUnknown_80B7F14
_080033C8: .4byte gUnknown_80B7F20
_080033CC:
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MemoryLocateSet

	thumb_func_start MemoryAlloc
MemoryAlloc:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080033E8
	adds r1, r3, 0
	bl DoAlloc
	pop {r1}
	bx r1
	.align 2, 0
_080033E8: .4byte gUnknown_2000EB0
	thumb_func_end MemoryAlloc

	thumb_func_start MemoryFree
MemoryFree:
	push {lr}
	adds r1, r0, 0
	ldr r0, _080033FC
	bl DoFree
	pop {r0}
	bx r0
	.align 2, 0
_080033FC: .4byte gUnknown_2000EB0
	thumb_func_end MemoryFree

	thumb_func_start CreateSubHeap
CreateSubHeap:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	cmp r4, 0
	bne _08003412
	ldr r4, _0800342C
_08003412:
	adds r0, r4, 0
	movs r1, 0x9
	adds r2, r5, 0
	bl MemorySearchFromBack
	adds r1, r0, 0
	cmp r1, 0
	bge _08003438
	ldr r0, _08003430
	ldr r1, _08003434
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_0800342C: .4byte gUnknown_2000EB0
_08003430: .4byte gUnknown_80B7F88
_08003434: .4byte gUnknown_80B7F94
_08003438:
	str r6, [sp]
	adds r0, r4, 0
	movs r2, 0x9
	adds r3, r5, 0
	bl MemorySplitBack
	ldr r1, [r0, 0xC]
	str r1, [sp, 0x4]
	ldr r0, [r0, 0x10]
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	adds r1, r7, 0
	bl DoCreateSubHeap
	str r4, [r0, 0x4]
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CreateSubHeap

	thumb_func_start DoCreateSubHeap
DoCreateSubHeap:
	push {r4,lr}
	sub sp, 0x8
	adds r2, r1, 0
	ldr r4, [r0]
	adds r1, r4, 0
	adds r1, 0x1C
	str r1, [sp]
	ldr r0, [r0, 0x4]
	subs r0, 0x1C
	str r0, [sp, 0x4]
	adds r0, r4, 0
	mov r1, sp
	bl InitSubHeap
	adds r0, r4, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end DoCreateSubHeap

	thumb_func_start xxx_unused_memory_free
xxx_unused_memory_free:
	push {r4-r7,lr}
	adds r4, r0, 0
	cmp r4, 0
	beq _08003504
	movs r1, 0
	ldr r0, [r4, 0xC]
	cmp r0, 0x1
	bne _080034A2
	ldr r0, [r4, 0x8]
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bne _080034A2
	movs r1, 0x1
_080034A2:
	cmp r1, 0
	beq _08003504
	movs r0, 0
	mov r12, r0
	movs r3, 0
	ldr r6, _080034E0
	ldr r0, [r6]
	cmp r12, r0
	bge _080034F2
	ldr r5, _080034E4
	adds r1, r6, 0
	adds r7, r5, 0
	movs r2, 0
_080034BC:
	adds r0, r2, r5
	ldr r0, [r0]
	cmp r0, r4
	bne _080034E8
	ldr r0, [r1]
	subs r0, 0x1
	str r0, [r1]
	cmp r3, r0
	bge _080034F8
	ldr r1, _080034E0
	adds r2, r7
_080034D2:
	ldr r0, [r2, 0x4]
	stm r2!, {r0}
	adds r3, 0x1
	ldr r0, [r1]
	cmp r3, r0
	blt _080034D2
	b _080034F8
	.align 2, 0
_080034E0: .4byte gUnknown_2000EA8
_080034E4: .4byte gUnknown_2000E88
_080034E8:
	adds r2, 0x4
	adds r3, 0x1
	ldr r0, [r6]
	cmp r3, r0
	blt _080034BC
_080034F2:
	mov r0, r12
	cmp r0, 0
	beq _08003504
_080034F8:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08003504
	adds r1, r4, 0
	bl DoFree
_08003504:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end xxx_unused_memory_free

	thumb_func_start DoAlloc
DoAlloc:
	push {lr}
	movs r3, 0x80
	lsls r3, 1
	orrs r3, r2
	adds r2, r3, 0
	bl MemoryLocateSet
	pop {r1}
	bx r1
	thumb_func_end DoAlloc

	thumb_func_start DoFree
DoFree:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	cmp r4, 0
	bne _0800352E
	ldr r4, _080035D4
_0800352E:
	cmp r1, 0
	beq _080035E4
	movs r0, 0
	mov r8, r0
	ldr r3, [r4, 0x8]
	mov r12, r3
	ldr r3, [r4, 0xC]
	cmp r8, r3
	bge _080035E4
	movs r2, 0
_08003542:
	mov r5, r12
	ldr r0, [r5, 0xC]
	cmp r0, r1
	bne _080035D8
	str r2, [r5]
	str r2, [r5, 0x4]
	str r2, [r5, 0x14]
	str r2, [r5, 0x8]
	ldr r0, [r4, 0xC]
	subs r0, 0x1
	cmp r8, r0
	bge _08003592
	mov r2, r12
	adds r2, 0x18
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _08003592
	ldr r0, [r5, 0x10]
	ldr r1, [r2, 0x10]
	adds r0, r1
	str r0, [r5, 0x10]
	ldr r0, [r4, 0xC]
	subs r0, 0x1
	str r0, [r4, 0xC]
	mov r3, r8
	adds r3, 0x1
	cmp r3, r0
	bge _08003592
_0800357A:
	adds r0, r2, 0
	adds r1, r2, 0
	adds r1, 0x18
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	adds r2, 0x18
	ldr r0, [r4, 0xC]
	cmp r3, r0
	blt _0800357A
_08003592:
	mov r6, r8
	cmp r6, 0
	ble _080035E4
	mov r2, r12
	subs r2, 0x18
	ldr r0, [r2, 0x4]
	cmp r0, 0
	bne _080035E4
	ldr r0, [r2, 0x10]
	mov r7, r12
	ldr r1, [r7, 0x10]
	adds r0, r1
	str r0, [r2, 0x10]
	ldr r0, [r4, 0xC]
	subs r0, 0x1
	str r0, [r4, 0xC]
	mov r2, r12
	mov r3, r8
	cmp r3, r0
	bge _080035E4
_080035BA:
	adds r0, r2, 0
	adds r1, r2, 0
	adds r1, 0x18
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r3, 0x1
	adds r2, 0x18
	ldr r0, [r4, 0xC]
	cmp r3, r0
	blt _080035BA
	b _080035E4
	.align 2, 0
_080035D4: .4byte gUnknown_2000EB0
_080035D8:
	movs r0, 0x1
	add r8, r0
	movs r5, 0x18
	add r12, r5
	cmp r8, r3
	blt _08003542
_080035E4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DoFree

	thumb_func_start nullsub_141
nullsub_141:
	bx lr
	thumb_func_end nullsub_141

	thumb_func_start nullsub_142
nullsub_142:
	bx lr
	thumb_func_end nullsub_142

	thumb_func_start sub_80035F8
sub_80035F8:
	push {lr}
	pop {r0}
	bx r0
	thumb_func_end sub_80035F8

	thumb_func_start sub_8003600
sub_8003600:
	push {r4-r6,lr}
	ldr r1, _08003650
	ldr r6, _08003654
	movs r2, 0
	ldr r0, _08003658
	movs r3, 0x80
	lsls r3, 2
_0800360E:
	strb r2, [r0]
	strb r2, [r0, 0x1]
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x3]
	adds r0, 0x4
	subs r3, 0x1
	cmp r3, 0
	bne _0800360E
	movs r0, 0
	movs r5, 0x80
	lsls r5, 1
	ldr r4, _0800365C
	movs r3, 0x20
	ldr r2, _08003660
_0800362A:
	strb r0, [r1]
	strh r5, [r1, 0x2]
	strb r0, [r1, 0x4]
	strb r0, [r1, 0x5]
	strb r0, [r1, 0x6]
	strb r0, [r1, 0x7]
	str r0, [r1, 0x8]
	str r4, [r1, 0xC]
	str r2, [r1, 0x10]
	subs r3, 0x1
	adds r1, 0x14
	cmp r3, 0
	bge _0800362A
	movs r0, 0x1
	strb r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003650: .4byte gUnknown_3000C00
_08003654: .4byte gUnknown_3001B58
_08003658: .4byte gUnknown_3000400
_0800365C: .4byte sub_8003A34
_08003660: .4byte sub_8003A74
	thumb_func_end sub_8003600

	thumb_func_start sub_8003664
sub_8003664:
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _0800369C
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	movs r0, 0
	strh r1, [r2, 0x2]
	strb r0, [r2, 0x4]
	strb r0, [r2, 0x5]
	strb r0, [r2, 0x6]
	strb r0, [r2, 0x7]
	str r3, [r2, 0x8]
	ldr r0, _080036A0
	str r0, [r2, 0xC]
	ldr r0, _080036A4
	str r0, [r2, 0x10]
	ldr r0, _080036A8
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800369C: .4byte gUnknown_3000C00
_080036A0: .4byte sub_8003AC0
_080036A4: .4byte sub_8003B50
_080036A8: .4byte gUnknown_3001B58
	thumb_func_end sub_8003664

	thumb_func_start sub_80036AC
sub_80036AC:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _080036E4
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _080036E8
	str r0, [r2, 0xC]
	ldr r0, _080036EC
	str r0, [r2, 0x10]
	ldr r0, _080036F0
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080036E4: .4byte gUnknown_3000C00
_080036E8: .4byte sub_8003C18
_080036EC: .4byte sub_8003D00
_080036F0: .4byte gUnknown_3001B58
	thumb_func_end sub_80036AC

	thumb_func_start sub_80036F4
sub_80036F4:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _0800372C
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _08003730
	str r0, [r2, 0xC]
	ldr r0, _08003734
	str r0, [r2, 0x10]
	ldr r0, _08003738
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800372C: .4byte gUnknown_3000C00
_08003730: .4byte sub_8003E2C
_08003734: .4byte sub_8003EC0
_08003738: .4byte gUnknown_3001B58
	thumb_func_end sub_80036F4

	thumb_func_start sub_800373C
sub_800373C:
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 2
	ldr r0, _08003770
	adds r3, r0
	movs r4, 0x1
	strb r4, [r3]
	movs r0, 0
	strh r1, [r3, 0x2]
	strb r0, [r3, 0x4]
	strb r0, [r3, 0x5]
	strb r0, [r3, 0x6]
	strb r0, [r3, 0x7]
	str r2, [r3, 0x8]
	ldr r0, _08003774
	str r0, [r3, 0xC]
	ldr r0, _08003778
	str r0, [r3, 0x10]
	ldr r0, _0800377C
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003770: .4byte gUnknown_3000C00
_08003774: .4byte sub_8003F60
_08003778: .4byte sub_8004034
_0800377C: .4byte gUnknown_3001B58
	thumb_func_end sub_800373C

	thumb_func_start sub_8003780
sub_8003780:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _080037B8
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _080037BC
	str r0, [r2, 0xC]
	ldr r0, _080037C0
	str r0, [r2, 0x10]
	ldr r0, _080037C4
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080037B8: .4byte gUnknown_3000C00
_080037BC: .4byte sub_8004170
_080037C0: .4byte sub_8004264
_080037C4: .4byte gUnknown_3001B58
	thumb_func_end sub_8003780

	thumb_func_start sub_80037C8
sub_80037C8:
	push {r4,lr}
	sub sp, 0x4
	str r2, [sp]
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _08003800
	adds r2, r0
	movs r3, 0
	movs r4, 0x1
	strb r4, [r2]
	strh r1, [r2, 0x2]
	ldr r0, [sp]
	str r0, [r2, 0x4]
	str r3, [r2, 0x8]
	ldr r0, _08003804
	str r0, [r2, 0xC]
	ldr r0, _08003808
	str r0, [r2, 0x10]
	ldr r0, _0800380C
	strb r4, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003800: .4byte gUnknown_3000C00
_08003804: .4byte sub_8004388
_08003808: .4byte sub_8004434
_0800380C: .4byte gUnknown_3001B58
	thumb_func_end sub_80037C8

	thumb_func_start sub_8003810
sub_8003810:
	sub sp, 0x4
	str r1, [sp]
	lsls r0, 16
	lsrs r2, r0, 20
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	ldr r2, _08003838
	adds r1, r2
	movs r2, 0x1
	strb r2, [r1]
	ldr r1, _0800383C
	lsrs r0, 14
	adds r0, r1
	ldr r1, [sp]
	str r1, [r0]
	ldr r0, _08003840
	strb r2, [r0]
	add sp, 0x4
	bx lr
	.align 2, 0
_08003838: .4byte gUnknown_3000C00
_0800383C: .4byte gUnknown_3000400
_08003840: .4byte gUnknown_3001B58
	thumb_func_end sub_8003810

	thumb_func_start sub_8003844
sub_8003844:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	lsrs r1, 16
	lsrs r0, 20
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 2
	ldr r0, _08003880
	adds r2, r0
	movs r5, 0x1
	strb r5, [r2]
	adds r0, r1, 0
	bl sub_80027A0
	str r0, [sp]
	ldr r0, _08003884
	lsls r4, 2
	adds r4, r0
	ldr r0, [sp]
	str r0, [r4]
	ldr r0, _08003888
	strb r5, [r0]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003880: .4byte gUnknown_3000C00
_08003884: .4byte gUnknown_3000400
_08003888: .4byte gUnknown_3001B58
	thumb_func_end sub_8003844

	thumb_func_start sub_800388C
sub_800388C:
	push {r4-r7,lr}
	adds r6, r1, 0
	lsls r0, 16
	lsrs r1, r0, 16
	lsrs r4, r0, 20
	adds r3, r1, r2
	subs r0, r3, 0x1
	cmp r0, 0
	bge _080038A0
	adds r0, 0xF
_080038A0:
	lsls r0, 12
	lsrs r3, r0, 16
	lsls r1, 2
	ldr r0, _080038E4
	adds r1, r0
	lsls r5, r4, 2
	ldr r7, _080038E8
	ldr r0, _080038EC
	mov r12, r0
	cmp r2, 0
	ble _080038C0
_080038B6:
	ldm r6!, {r0}
	stm r1!, {r0}
	subs r2, 0x1
	cmp r2, 0
	bne _080038B6
_080038C0:
	adds r0, r5, r4
	lsls r0, 2
	adds r0, r7
	adds r2, r4, 0
	cmp r2, r3
	bgt _080038D8
	movs r1, 0x1
_080038CE:
	strb r1, [r0]
	adds r2, 0x1
	adds r0, 0x14
	cmp r2, r3
	ble _080038CE
_080038D8:
	movs r0, 0x1
	mov r1, r12
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080038E4: .4byte gUnknown_3000400
_080038E8: .4byte gUnknown_3000C00
_080038EC: .4byte gUnknown_3001B58
	thumb_func_end sub_800388C

	thumb_func_start sub_80038F0
sub_80038F0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r5, r1, 0
	lsls r0, 16
	lsrs r1, r0, 16
	lsrs r6, r0, 20
	adds r3, r1, r2
	subs r0, r3, 0x1
	cmp r0, 0
	bge _0800390C
	adds r0, 0xF
_0800390C:
	lsls r0, 12
	lsrs r7, r0, 16
	lsls r1, 2
	ldr r0, _0800396C
	adds r1, r0
	mov r8, r1
	lsls r0, r6, 2
	mov r9, r0
	cmp r2, 0
	ble _0800393C
	adds r4, r2, 0
_08003922:
	ldrh r0, [r5]
	adds r5, 0x2
	bl sub_80027A0
	str r0, [sp]
	mov r1, r8
	adds r1, 0x4
	mov r8, r1
	subs r1, 0x4
	stm r1!, {r0}
	subs r4, 0x1
	cmp r4, 0
	bne _08003922
_0800393C:
	mov r1, r9
	adds r0, r1, r6
	lsls r0, 2
	ldr r1, _08003970
	adds r0, r1
	adds r4, r6, 0
	ldr r2, _08003974
	cmp r4, r7
	bgt _0800395A
	movs r1, 0x1
_08003950:
	strb r1, [r0]
	adds r4, 0x1
	adds r0, 0x14
	cmp r4, r7
	ble _08003950
_0800395A:
	movs r0, 0x1
	strb r0, [r2]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800396C: .4byte gUnknown_3000400
_08003970: .4byte gUnknown_3000C00
_08003974: .4byte gUnknown_3001B58
	thumb_func_end sub_80038F0

	thumb_func_start sub_8003978
sub_8003978:
	lsls r0, 16
	ldr r1, _08003984
	lsrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08003984: .4byte gUnknown_3000400
	thumb_func_end sub_8003978

	thumb_func_start sub_8003988
sub_8003988:
	push {lr}
	lsls r0, 16
	ldr r1, _080039A0
	lsrs r0, 14
	adds r0, r1
	ldr r0, [r0]
	bl sub_8002774
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.align 2, 0
_080039A0: .4byte gUnknown_3000400
	thumb_func_end sub_8003988

	thumb_func_start sub_80039A4
sub_80039A4:
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _080039B4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_080039B4: .4byte gUnknown_3001B5A
	thumb_func_end sub_80039A4

	thumb_func_start sub_80039B8
sub_80039B8:
	push {r4,r5,lr}
	ldr r0, _08003A28
	ldrb r0, [r0]
	cmp r0, 0
	beq _08003A20
	ldr r4, _08003A2C
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080039DA
	movs r0, 0xA0
	lsls r0, 2
	adds r1, r4, r0
	movs r0, 0x1
	strb r0, [r1]
_080039DA:
	movs r5, 0
_080039DC:
	ldrb r0, [r4]
	cmp r0, 0
	beq _080039F0
	lsls r0, r5, 16
	lsrs r0, 16
	ldr r1, [r4, 0x10]
	bl _call_via_r1
	movs r0, 0
	strb r0, [r4]
_080039F0:
	adds r5, 0x1
	adds r4, 0x14
	cmp r5, 0x1F
	ble _080039DC
	ldr r0, _08003A2C
	movs r1, 0xA0
	lsls r1, 2
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0
	beq _08003A14
	ldr r2, [r4, 0xC]
	movs r0, 0x20
	movs r1, 0xF0
	bl _call_via_r2
	movs r0, 0
	strb r0, [r5]
_08003A14:
	ldr r1, _08003A30
	movs r0, 0x3
	strh r0, [r1]
	ldr r1, _08003A28
	movs r0, 0
	strb r0, [r1]
_08003A20:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003A28: .4byte gUnknown_3001B58
_08003A2C: .4byte gUnknown_3000C00
_08003A30: .4byte gUnknown_3001B5A
	thumb_func_end sub_80039B8

	thumb_func_start sub_8003A34
sub_8003A34:
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, r1, 16
	lsrs r0, 16
	lsls r5, r0, 2
	ldr r1, _08003A70
	adds r5, r1
	ldrb r1, [r5, 0x2]
	movs r2, 0xF8
	adds r3, r2, 0
	ands r3, r1
	lsls r3, 7
	ldrb r4, [r5, 0x1]
	adds r1, r2, 0
	ands r1, r4
	lsls r1, 2
	orrs r3, r1
	ldrb r1, [r5]
	ands r2, r1
	lsrs r2, 3
	orrs r2, r3
	mov r1, sp
	strh r2, [r1]
	bl SetBGPaletteBufferColor
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003A70: .4byte gUnknown_3000400
	thumb_func_end sub_8003A34

	thumb_func_start sub_8003A74
sub_8003A74:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 20
	lsrs r6, r0, 16
	lsls r1, r6, 2
	ldr r0, _08003ABC
	adds r4, r1, r0
	movs r5, 0
	movs r7, 0xF8
_08003A86:
	ldrb r0, [r4, 0x2]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r7, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r7, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r6, r5
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003A86
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08003ABC: .4byte gUnknown_3000400
	thumb_func_end sub_8003A74

	thumb_func_start sub_8003AC0
sub_8003AC0:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003B04
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r6, r2, 0
	lsls r1, r7, 2
	ldr r0, _08003B08
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _08003B0C
	ldrb r0, [r4, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r4, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r4]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003B3A
	.align 2, 0
_08003B04: .4byte gUnknown_3000C00
_08003B08: .4byte gUnknown_3000400
_08003B0C:
	cmp r2, 0
	bne _08003B16
	mov r0, sp
	strh r2, [r0]
	b _08003B3E
_08003B16:
	ldrb r0, [r4, 0x2]
	muls r0, r2
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r5, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r2
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r5
	ldrb r0, [r4]
	muls r0, r6
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003B3A:
	mov r0, sp
	strh r1, [r0]
_08003B3E:
	adds r0, r7, 0
	mov r1, sp
	bl SetBGPaletteBufferColor
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003AC0

	thumb_func_start sub_8003B50
sub_8003B50:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _08003BAC
	adds r1, r2
	ldrh r6, [r1, 0x2]
	lsls r0, 20
	lsrs r7, r0, 16
	lsls r1, r7, 2
	ldr r0, _08003BB0
	adds r4, r1, r0
	cmp r6, 0xFF
	bls _08003BB4
	movs r5, 0
	movs r6, 0xF8
_08003B7A:
	ldrb r0, [r4, 0x2]
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r6, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r7, r5
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003B7A
	b _08003C0A
	.align 2, 0
_08003BAC: .4byte gUnknown_3000C00
_08003BB0: .4byte gUnknown_3000400
_08003BB4:
	cmp r6, 0
	bne _08003BCE
	mov r0, sp
	strh r6, [r0]
	movs r5, 0
_08003BBE:
	adds r0, r7, r5
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003BBE
	b _08003C0A
_08003BCE:
	movs r5, 0
	mov r8, sp
_08003BD2:
	ldrb r0, [r4, 0x2]
	muls r0, r6
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r2, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r6
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r2
	ldrb r0, [r4]
	muls r0, r6
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
	mov r0, r8
	strh r1, [r0]
	adds r0, r7, r5
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003BD2
_08003C0A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003B50

	thumb_func_start sub_8003C18
sub_8003C18:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003C68
	adds r1, r0
	ldrh r2, [r1, 0x2]
	mov r12, r2
	ldr r0, [r1, 0x4]
	str r0, [sp]
	mov r0, r8
	lsls r1, r0, 2
	ldr r0, _08003C6C
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _08003C70
	ldrb r0, [r4, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r4, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r4]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003CE8
	.align 2, 0
_08003C68: .4byte gUnknown_3000C00
_08003C6C: .4byte gUnknown_3000400
_08003C70:
	cmp r2, 0
	bne _08003C98
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003CE8
_08003C98:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	subs r0, r2
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	ldrb r1, [r1]
	adds r7, r1, 0
	muls r7, r0
	mov r1, sp
	ldrb r1, [r1, 0x1]
	adds r6, r1, 0
	muls r6, r0
	mov r1, sp
	ldrb r1, [r1, 0x2]
	muls r1, r0
	ldrb r0, [r4, 0x2]
	muls r0, r2
	adds r0, r1
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r5, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r2
	adds r0, r6
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r5
	ldrb r0, [r4]
	mov r2, r12
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003CE8:
	add r0, sp, 0x4
	strh r1, [r0]
	adds r1, r0, 0
	mov r0, r8
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003C18

	thumb_func_start sub_8003D00
sub_8003D00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _08003D68
	adds r1, r2
	ldrh r6, [r1, 0x2]
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r0, 16
	mov r8, r0
	lsls r1, r0, 2
	ldr r0, _08003D6C
	adds r4, r1, r0
	cmp r6, 0xFF
	bls _08003D70
	movs r5, 0
	movs r7, 0xF8
	add r6, sp, 0x4
_08003D36:
	ldrb r0, [r4, 0x2]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r7, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r7, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r6]
	mov r1, r8
	adds r0, r1, r5
	adds r1, r6, 0
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003D36
	b _08003E1C
	.align 2, 0
_08003D68: .4byte gUnknown_3000C00
_08003D6C: .4byte gUnknown_3000400
_08003D70:
	cmp r6, 0
	bne _08003DAE
	add r4, sp, 0x4
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	strh r1, [r4]
	movs r5, 0
_08003D9C:
	mov r2, r8
	adds r0, r2, r5
	adds r1, r4, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003D9C
	b _08003E1C
_08003DAE:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	subs r0, r6
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	ldrb r1, [r1]
	adds r2, r1, 0
	muls r2, r0
	str r2, [sp, 0x8]
	mov r1, sp
	ldrb r1, [r1, 0x1]
	adds r2, r1, 0
	muls r2, r0
	mov r10, r2
	mov r1, sp
	ldrb r1, [r1, 0x2]
	adds r2, r1, 0
	muls r2, r0
	mov r9, r2
	movs r5, 0
	add r7, sp, 0x4
_08003DDC:
	ldrb r0, [r4, 0x2]
	muls r0, r6
	add r0, r9
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r2, r0, 7
	ldrb r0, [r4, 0x1]
	muls r0, r6
	add r0, r10
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r2
	ldrb r0, [r4]
	muls r0, r6
	ldr r2, [sp, 0x8]
	adds r0, r2
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
	strh r1, [r7]
	mov r1, r8
	adds r0, r1, r5
	adds r1, r7, 0
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08003DDC
_08003E1C:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003D00

	thumb_func_start sub_8003E2C
sub_8003E2C:
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003E74
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r5, r2, 0
	ldr r0, [r1, 0x4]
	str r0, [sp]
	cmp r2, 0xFF
	bls _08003E78
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003EAC
	.align 2, 0
_08003E74: .4byte gUnknown_3000C00
_08003E78:
	cmp r2, 0
	bne _08003E82
	add r0, sp, 0x4
	strh r2, [r0]
	b _08003EB0
_08003E82:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r4, r0, 7
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r4
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r5
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003EAC:
	add r0, sp, 0x4
	strh r1, [r0]
_08003EB0:
	adds r1, r0, 0
	adds r0, r6, 0
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8003E2C

	thumb_func_start sub_8003EC0
sub_8003EC0:
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _08003F08
	adds r1, r2
	ldrh r2, [r1, 0x2]
	adds r5, r2, 0
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r6, r0, 16
	cmp r2, 0xFF
	bls _08003F0C
	mov r0, sp
	ldrb r0, [r0, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	mov r0, sp
	ldrb r3, [r0, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	mov r0, sp
	ldrb r0, [r0]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	b _08003F40
	.align 2, 0
_08003F08: .4byte gUnknown_3000C00
_08003F0C:
	cmp r2, 0
	bne _08003F16
	add r0, sp, 0x4
	strh r2, [r0]
	b _08003F44
_08003F16:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r4, r0, 7
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r4
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r5
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
_08003F40:
	add r0, sp, 0x4
	strh r1, [r0]
_08003F44:
	adds r5, r0, 0
	movs r4, 0
_08003F48:
	adds r0, r6, r4
	adds r1, r5, 0
	bl SetBGPaletteBufferColor
	adds r4, 0x1
	cmp r4, 0xF
	ble _08003F48
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8003EC0

	thumb_func_start sub_8003F60
sub_8003F60:
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _08003FA8
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r3, r2, 0
	movs r0, 0xF
	ands r0, r7
	lsls r0, 2
	ldr r1, [r1, 0x8]
	adds r5, r1, r0
	lsls r1, r7, 2
	ldr r0, _08003FAC
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _08003FB0
	ldrb r0, [r4, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r4, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r4]
	b _08003FCA
	.align 2, 0
_08003FA8: .4byte gUnknown_3000C00
_08003FAC: .4byte gUnknown_3000400
_08003FB0:
	cmp r2, 0
	bne _08003FD6
	ldrb r0, [r5, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r5, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r5]
_08003FCA:
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	mov r0, sp
	strh r1, [r0]
	b _08004024
_08003FD6:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	subs r0, r3
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r5]
	adds r2, r1, 0
	muls r2, r0
	ldrb r1, [r4]
	muls r1, r3
	adds r6, r2, r1
	ldrb r1, [r5, 0x1]
	adds r2, r1, 0
	muls r2, r0
	ldrb r1, [r4, 0x1]
	muls r1, r3
	adds r2, r1
	ldrb r1, [r5, 0x2]
	muls r1, r0
	ldrb r0, [r4, 0x2]
	muls r0, r3
	adds r0, r1, r0
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r1, r0, 7
	adds r0, r2, 0
	asrs r0, 8
	ands r0, r3
	lsls r2, r0, 2
	orrs r2, r1
	adds r0, r6, 0
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r2, r0
	mov r0, sp
	strh r2, [r0]
_08004024:
	adds r0, r7, 0
	mov r1, sp
	bl SetBGPaletteBufferColor
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8003F60

	thumb_func_start sub_8004034
sub_8004034:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _0800409C
	adds r1, r2
	ldrh r2, [r1, 0x2]
	mov r8, r2
	ldr r5, [r1, 0x8]
	lsls r0, 20
	lsrs r0, 16
	mov r10, r0
	lsls r1, r0, 2
	ldr r0, _080040A0
	adds r4, r1, r0
	cmp r2, 0xFF
	bls _080040A4
	movs r7, 0
	movs r5, 0xF8
_08004068:
	ldrb r0, [r4, 0x2]
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r4, 0x1]
	adds r0, r5, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r4]
	adds r0, r5, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r1, r10
	adds r0, r1, r7
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r7, 0x1
	cmp r7, 0xF
	ble _08004068
	b _0800415E
	.align 2, 0
_0800409C: .4byte gUnknown_3000C00
_080040A0: .4byte gUnknown_3000400
_080040A4:
	mov r2, r8
	cmp r2, 0
	bne _080040E2
	movs r7, 0
	mov r6, sp
	movs r4, 0xF8
_080040B0:
	ldrb r0, [r5, 0x2]
	adds r1, r4, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r5, 0x1]
	adds r0, r4, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r5]
	adds r0, r4, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r6]
	mov r1, r10
	adds r0, r1, r7
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r7, 0x1
	cmp r7, 0xF
	ble _080040B0
	b _0800415E
_080040E2:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	mov r1, r8
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	movs r7, 0
	mov r2, sp
	str r2, [sp, 0x4]
_080040F8:
	ldrb r0, [r5]
	mov r1, r9
	muls r1, r0
	ldrb r0, [r4]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r1, r0
	mov r12, r1
	ldrb r0, [r5, 0x1]
	mov r1, r9
	muls r1, r0
	ldrb r0, [r4, 0x1]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r6, r1, r0
	ldrb r0, [r5, 0x2]
	mov r1, r9
	muls r1, r0
	ldrb r0, [r4, 0x2]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r1, r0
	asrs r0, 8
	movs r3, 0xF8
	ands r0, r3
	lsls r2, r0, 7
	adds r0, r6, 0
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 2
	orrs r1, r2
	mov r0, r12
	asrs r0, 8
	ands r0, r3
	lsrs r0, 3
	orrs r1, r0
	ldr r0, [sp, 0x4]
	strh r1, [r0]
	mov r1, r10
	adds r0, r1, r7
	mov r1, sp
	bl SetBGPaletteBufferColor
	adds r4, 0x4
	adds r5, 0x4
	adds r7, 0x1
	cmp r7, 0xF
	ble _080040F8
_0800415E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8004034

	thumb_func_start sub_8004170
sub_8004170:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _080041C4
	adds r1, r0
	ldrh r2, [r1, 0x2]
	adds r4, r2, 0
	ldr r0, [r1, 0x4]
	str r0, [sp]
	mov r0, r9
	lsls r1, r0, 2
	ldr r0, _080041C8
	adds r6, r1, r0
	cmp r2, 0xFF
	bls _080041CC
	ldrb r0, [r6, 0x2]
	movs r1, 0xF8
	adds r2, r1, 0
	ands r2, r0
	lsls r2, 7
	ldrb r3, [r6, 0x1]
	adds r0, r1, 0
	ands r0, r3
	lsls r0, 2
	orrs r2, r0
	ldrb r0, [r6]
	ands r1, r0
	lsrs r1, 3
	orrs r1, r2
	add r0, sp, 0x4
	strh r1, [r0]
	b _0800424C
	.align 2, 0
_080041C4: .4byte gUnknown_3000C00
_080041C8: .4byte gUnknown_3000400
_080041CC:
	mov r0, sp
	ldrb r1, [r0]
	movs r3, 0xFF
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080041DC
	adds r0, 0xFF
_080041DC:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	mov r0, sp
	ldrb r1, [r0, 0x1]
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080041F4
	adds r0, 0xFF
_080041F4:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r7, r0, 16
	mov r0, sp
	ldrb r1, [r0, 0x2]
	subs r0, r3, r1
	muls r0, r4
	cmp r0, 0
	bge _0800420A
	adds r0, 0xFF
_0800420A:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r6, 0x2]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	movs r5, 0xF8
	ands r4, r5
	lsls r4, 7
	ldrb r0, [r6, 0x1]
	muls r0, r7
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r6]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsrs r0, 3
	orrs r4, r0
	add r0, sp, 0x4
	strh r4, [r0]
_0800424C:
	adds r1, r0, 0
	mov r0, r9
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8004170

	thumb_func_start sub_8004264
sub_8004264:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _080042CC
	adds r1, r2
	ldrh r2, [r1, 0x2]
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r0, 16
	mov r9, r0
	lsls r1, r0, 2
	ldr r0, _080042D0
	adds r5, r1, r0
	cmp r2, 0xFF
	bls _080042D4
	movs r6, 0
	movs r7, 0xF8
	add r4, sp, 0x4
_0800429A:
	ldrb r0, [r5, 0x2]
	adds r1, r7, 0
	ands r1, r0
	lsls r1, 7
	ldrb r2, [r5, 0x1]
	adds r0, r7, 0
	ands r0, r2
	lsls r0, 2
	orrs r1, r0
	ldrb r2, [r5]
	adds r0, r7, 0
	ands r0, r2
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r4]
	mov r1, r9
	adds r0, r1, r6
	adds r1, r4, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0xF
	ble _0800429A
	b _08004378
	.align 2, 0
_080042CC: .4byte gUnknown_3000C00
_080042D0: .4byte gUnknown_3000400
_080042D4:
	mov r0, sp
	ldrb r1, [r0]
	movs r3, 0xFF
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080042E4
	adds r0, 0xFF
_080042E4:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	mov r0, sp
	ldrb r1, [r0, 0x1]
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _080042FC
	adds r0, 0xFF
_080042FC:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r0, sp
	ldrb r1, [r0, 0x2]
	subs r0, r3, r1
	muls r0, r2
	cmp r0, 0
	bge _08004314
	adds r0, 0xFF
_08004314:
	asrs r0, 8
	adds r0, r1, r0
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	movs r6, 0
	add r7, sp, 0x4
	movs r0, 0xF8
	mov r8, r0
_08004326:
	ldrb r0, [r5, 0x2]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	mov r0, r8
	ands r4, r0
	lsls r4, 7
	ldrb r0, [r5, 0x1]
	ldr r1, [sp, 0xC]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r5]
	ldr r1, [sp, 0x8]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsrs r0, 3
	orrs r4, r0
	strh r4, [r7]
	mov r1, r9
	adds r0, r1, r6
	adds r1, r7, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0xF
	ble _08004326
_08004378:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8004264

	thumb_func_start sub_8004388
sub_8004388:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r0, _0800442C
	adds r1, r0
	ldrh r2, [r1, 0x2]
	ldr r0, [r1, 0x4]
	str r0, [sp]
	mov r0, r9
	lsls r1, r0, 2
	ldr r0, _08004430
	adds r6, r1, r0
	cmp r2, 0xFF
	bls _080043BC
	movs r2, 0x80
	lsls r2, 1
_080043BC:
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	mov r8, r0
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	lsls r0, 8
	lsrs r7, r0, 16
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	ldrb r1, [r6, 0x2]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	movs r5, 0xF8
	ands r4, r5
	lsls r4, 7
	ldrb r0, [r6, 0x1]
	muls r0, r7
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r6]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	ands r0, r5
	lsrs r0, 3
	orrs r4, r0
	add r1, sp, 0x4
	strh r4, [r1]
	mov r0, r9
	bl SetBGPaletteBufferColor
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800442C: .4byte gUnknown_3000C00
_08004430: .4byte gUnknown_3000400
	thumb_func_end sub_8004388

	thumb_func_start sub_8004434
sub_8004434:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	ldr r2, _080044F8
	adds r1, r2
	ldrh r2, [r1, 0x2]
	ldr r1, [r1, 0x4]
	str r1, [sp]
	lsls r0, 20
	lsrs r0, 16
	mov r9, r0
	lsls r1, r0, 2
	ldr r0, _080044FC
	adds r5, r1, r0
	cmp r2, 0xFF
	bls _08004468
	movs r2, 0x80
	lsls r2, 1
_08004468:
	mov r0, sp
	ldrb r0, [r0]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	str r0, [sp, 0x8]
	mov r0, sp
	ldrb r0, [r0, 0x1]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	muls r0, r2
	lsls r0, 8
	lsrs r0, 16
	mov r10, r0
	movs r6, 0
	movs r0, 0xF8
	mov r8, r0
	add r7, sp, 0x4
_08004494:
	ldrb r0, [r5, 0x2]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0xFF
	bl __divsi3
	adds r4, r0, 0
	mov r0, r8
	ands r4, r0
	lsls r4, 7
	ldrb r0, [r5, 0x1]
	ldr r1, [sp, 0xC]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsls r0, 2
	orrs r4, r0
	ldrb r0, [r5]
	ldr r1, [sp, 0x8]
	muls r0, r1
	movs r1, 0xFF
	bl __divsi3
	mov r1, r8
	ands r0, r1
	lsrs r0, 3
	orrs r4, r0
	strh r4, [r7]
	mov r1, r9
	adds r0, r1, r6
	adds r1, r7, 0
	bl SetBGPaletteBufferColor
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0xF
	ble _08004494
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080044F8: .4byte gUnknown_3000C00
_080044FC: .4byte gUnknown_3000400
	thumb_func_end sub_8004434

	thumb_func_start sub_8004500
sub_8004500:
	ldr r1, _08004514
	ldrh r2, [r1]
	movs r0, 0x6D
	muls r0, r2
	ldr r2, _08004518
	adds r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	bx lr
	.align 2, 0
_08004514: .4byte gUnknown_203B070
_08004518: .4byte 0x000003fd
	thumb_func_end sub_8004500

	thumb_func_start sub_800451C
sub_800451C:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_8004500
	muls r0, r4
	asrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800451C

	thumb_func_start sub_8004530
sub_8004530:
	push {r4,lr}
	adds r4, r0, 0
	subs r0, r1, r4
	bl sub_800451C
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8004530

	thumb_func_start sub_8004544
sub_8004544:
	push {r4,r5,lr}
	adds r3, r0, 0
	subs r4, r1, 0x1
	adds r2, r3, r4
	movs r5, 0
	cmp r5, r4
	bge _08004566
_08004552:
	ldrb r1, [r3]
	ldrb r0, [r2]
	strb r0, [r3]
	adds r3, 0x1
	strb r1, [r2]
	subs r2, 0x1
	adds r5, 0x1
	subs r4, 0x1
	cmp r5, r4
	blt _08004552
_08004566:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8004544

	thumb_func_start sub_800456C
sub_800456C:
	push {r4-r7,lr}
	adds r4, r1, 0
	cmp r4, 0
	ble _08004578
	movs r7, 0x1
	b _0800457E
_08004578:
	negs r4, r4
	movs r7, 0x1
	negs r7, r7
_0800457E:
	cmp r2, 0
	ble _080045A0
	adds r6, r0, 0
	adds r5, r2, 0
_08004586:
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	stm r6!, {r0}
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	subs r5, 0x1
	cmp r5, 0
	bne _08004586
_080045A0:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800456C

	thumb_func_start sub_80045A8
sub_80045A8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldm r4!, {r1}
	movs r3, 0xA
	cmp r2, 0x1
	ble _080045CA
	subs r2, 0x1
_080045B8:
	ldm r4!, {r0}
	muls r0, r3
	adds r1, r0
	subs r2, 0x1
	lsls r0, r3, 2
	adds r0, r3
	lsls r3, r0, 1
	cmp r2, 0
	bne _080045B8
_080045CA:
	adds r0, r1, 0
	cmp r5, 0
	bge _080045D2
	negs r0, r0
_080045D2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80045A8

	thumb_func_start ConvertFromBCD
ConvertFromBCD:
	push {r4,lr}
	adds r1, r0, 0
	movs r2, 0x1
	movs r3, 0
	cmp r1, 0
	ble _080045FA
	movs r4, 0xF
_080045E6:
	adds r0, r1, 0
	ands r0, r4
	muls r0, r2
	adds r3, r0
	lsls r0, r2, 2
	adds r0, r2
	lsls r2, r0, 1
	asrs r1, 4
	cmp r1, 0
	bgt _080045E6
_080045FA:
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ConvertFromBCD

	thumb_func_start ConvertToBCD
ConvertToBCD:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r5, 0
	movs r6, 0
	cmp r4, 0
	ble _0800462C
_08004610:
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	lsls r0, r5
	adds r6, r0
	adds r5, 0x4
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	cmp r4, 0
	bgt _08004610
_0800462C:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end ConvertToBCD

	thumb_func_start InitBGPaletteBuffer
InitBGPaletteBuffer:
	push {lr}
	movs r2, 0
	ldr r1, _0800465C
	movs r0, 0x80
	lsls r0, 2
_0800463E:
	strh r2, [r1]
	adds r1, 0x2
	subs r0, 0x1
	cmp r0, 0
	bne _0800463E
	ldr r1, _08004660
	movs r2, 0x1
	adds r0, r1, 0
	adds r0, 0x1F
_08004650:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08004650
	pop {r0}
	bx r0
	.align 2, 0
_0800465C: .4byte gUnknown_20251F0
_08004660: .4byte gUnknown_20251D0
	thumb_func_end InitBGPaletteBuffer

	thumb_func_start SetBGPaletteBufferColorRGB
SetBGPaletteBufferColorRGB:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	cmp r2, 0
	bge _08004670
	movs r2, 0
_08004670:
	cmp r2, 0x1F
	ble _08004676
	movs r2, 0x1F
_08004676:
	ldr r1, _080046CC
	adds r0, r4, 0
	cmp r4, 0
	bge _08004680
	adds r0, 0xF
_08004680:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	cmp r3, 0
	bne _080046D4
	ldr r0, _080046D0
	lsls r1, r4, 1
	adds r6, r1, r0
	ldrb r0, [r5, 0x2]
	muls r0, r2
	cmp r0, 0
	bge _0800469C
	adds r0, 0xFF
_0800469C:
	asrs r0, 8
	movs r3, 0x1F
	ands r0, r3
	lsls r4, r0, 10
	ldrb r0, [r5, 0x1]
	muls r0, r2
	cmp r0, 0
	bge _080046AE
	adds r0, 0xFF
_080046AE:
	asrs r0, 8
	ands r0, r3
	lsls r1, r0, 5
	orrs r1, r4
	ldrb r0, [r5]
	muls r0, r2
	cmp r0, 0
	bge _080046C0
	adds r0, 0xFF
_080046C0:
	asrs r0, 8
	ands r0, r3
	orrs r1, r0
	strh r1, [r6]
	b _08004722
	.align 2, 0
_080046CC: .4byte gUnknown_20251D0
_080046D0: .4byte gUnknown_20251F0
_080046D4:
	ldr r1, _08004728
	lsls r0, r4, 1
	adds r7, r0, r1
	ldrb r0, [r5, 0x2]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	muls r0, r2
	cmp r0, 0
	bge _080046EA
	adds r0, 0xFF
_080046EA:
	asrs r0, 8
	movs r4, 0x1F
	ands r0, r4
	lsls r6, r0, 10
	ldrb r0, [r5, 0x1]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	muls r0, r2
	cmp r0, 0
	bge _08004702
	adds r0, 0xFF
_08004702:
	asrs r0, 8
	ands r0, r4
	lsls r1, r0, 5
	orrs r1, r6
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0]
	muls r0, r2
	cmp r0, 0
	bge _0800471A
	adds r0, 0xFF
_0800471A:
	asrs r0, 8
	ands r0, r4
	orrs r1, r0
	strh r1, [r7]
_08004722:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004728: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColorRGB

	thumb_func_start SetBGPaletteBufferColorArray
SetBGPaletteBufferColorArray:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, _08004764
	cmp r2, 0
	bge _0800473A
	adds r0, 0xF
_0800473A:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _08004768
	lsls r2, 1
	adds r2, r0
	ldrb r1, [r3, 0x2]
	lsrs r1, 3
	lsls r1, 10
	ldrb r0, [r3, 0x1]
	lsrs r0, 3
	lsls r0, 5
	orrs r1, r0
	ldrb r0, [r3]
	lsrs r0, 3
	orrs r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_08004764: .4byte gUnknown_20251D0
_08004768: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColorArray

	thumb_func_start SetBGPaletteBufferColor
SetBGPaletteBufferColor:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, _08004790
	cmp r2, 0
	bge _0800477A
	adds r0, 0xF
_0800477A:
	asrs r0, 4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r1, _08004794
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r3]
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08004790: .4byte gUnknown_20251D0
_08004794: .4byte gUnknown_20251F0
	thumb_func_end SetBGPaletteBufferColor

	thumb_func_start nullsub_4
nullsub_4:
	bx lr
	thumb_func_end nullsub_4

	thumb_func_start nullsub_5
nullsub_5:
	bx lr
	thumb_func_end nullsub_5

	thumb_func_start nullsub_143
nullsub_143:
	bx lr
	thumb_func_end nullsub_143

	thumb_func_start TransferBGPaletteBuffer
TransferBGPaletteBuffer:
	push {r4-r6,lr}
	movs r6, 0
	movs r4, 0
	movs r5, 0xA0
	lsls r5, 19
_080047AE:
	ldr r0, _080047DC
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _080047CA
	movs r0, 0
	strb r0, [r1]
	lsls r1, r4, 1
	ldr r0, _080047E0
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0x20
	bl CpuCopy
_080047CA:
	adds r6, 0x1
	adds r5, 0x20
	adds r4, 0x10
	ldr r0, _080047E4
	cmp r4, r0
	ble _080047AE
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080047DC: .4byte gUnknown_20251D0
_080047E0: .4byte gUnknown_20251F0
_080047E4: .4byte 0x000001ff
	thumb_func_end TransferBGPaletteBuffer

	thumb_func_start sub_80047E8
sub_80047E8:
	ldr r0, _08004840
	movs r3, 0
	movs r2, 0
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r0, _08004844
	strh r2, [r0]
	strh r2, [r0, 0x2]
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	ldr r1, _08004848
	ldr r0, _0800484C
	str r0, [r1]
	ldr r0, _08004850
	str r2, [r0, 0x20]
	ldr r1, _08004854
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x1C]
	strh r1, [r0, 0x1E]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r3, [r1]
	adds r0, 0x29
	strb r3, [r0]
	ldr r0, _08004858
	strh r2, [r0]
	strh r2, [r0, 0x2]
	bx lr
	.align 2, 0
_08004840: .4byte gUnknown_20255F0
_08004844: .4byte gUnknown_2025638
_08004848: .4byte gUnknown_202562C
_0800484C: .4byte 0x004a14c1
_08004850: .4byte gUnknown_2025600
_08004854: .4byte 0x0000ffff
_08004858: .4byte gUnknown_2025668
	thumb_func_end sub_80047E8

	thumb_func_start sub_800485C
sub_800485C:
	push {r4,r5,lr}
	ldr r2, _080048A8
	ldr r1, _080048AC
	adds r0, r2, 0
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0
	movs r0, 0
	strh r0, [r2]
	strh r0, [r2, 0x2]
	strh r0, [r2, 0x4]
	strh r0, [r2, 0x6]
	ldr r0, _080048B0
	ldr r1, _080048B4
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r3, [r1]
	adds r0, 0x29
	strb r3, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080048A8: .4byte gUnknown_2025638
_080048AC: .4byte gUnknown_20255F0
_080048B0: .4byte gUnknown_2025600
_080048B4: .4byte 0x0000ffff
	thumb_func_end sub_800485C

	thumb_func_start sub_80048B8
sub_80048B8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048B8

	thumb_func_start sub_80048BC
sub_80048BC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048BC

	thumb_func_start sub_80048C0
sub_80048C0:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C0

	thumb_func_start sub_80048C4
sub_80048C4:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C4

	thumb_func_start sub_80048C8
sub_80048C8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048C8

	thumb_func_start sub_80048CC
sub_80048CC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80048CC

	thumb_func_start sub_80048D0
sub_80048D0:
	ldr r1, _080048E8
	movs r0, 0
	strh r0, [r1, 0x4]
	ldr r1, _080048EC
	str r0, [r1, 0xC]
	strh r0, [r1, 0x8]
	ldr r1, _080048F0
	ldr r0, _080048F4
	strh r0, [r1]
	strh r0, [r1, 0x2]
	bx lr
	.align 2, 0
_080048E8: .4byte gUnknown_20255F0
_080048EC: .4byte gUnknown_2025648
_080048F0: .4byte gUnknown_2025668
_080048F4: .4byte 0x000003e7
	thumb_func_end sub_80048D0

	thumb_func_start sub_80048F8
sub_80048F8:
	ldr r0, _08004908
	movs r1, 0
	strh r1, [r0, 0x2]
	ldr r0, _0800490C
	strh r1, [r0, 0x2]
	ldr r0, _08004910
	strh r1, [r0, 0x2]
	bx lr
	.align 2, 0
_08004908: .4byte gUnknown_20255F0
_0800490C: .4byte gUnknown_2025638
_08004910: .4byte gUnknown_2025648
	thumb_func_end sub_80048F8

	thumb_func_start sub_8004914
sub_8004914:
	ldr r0, _0800494C
	movs r1, 0x5
	str r1, [r0, 0x20]
	movs r2, 0
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r1, _08004950
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x16]
	adds r1, r0, 0
	adds r1, 0x28
	strb r2, [r1]
	adds r0, 0x29
	strb r2, [r0]
	bx lr
	.align 2, 0
_0800494C: .4byte gUnknown_2025600
_08004950: .4byte 0x0000ffff
	thumb_func_end sub_8004914

	thumb_func_start UpdateInput
UpdateInput:
	push {r4-r6,lr}
	ldr r4, _08004998
	ldr r5, _0800499C
	adds r1, r4, 0
	adds r0, r5, 0
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, 0
	bl ReadKeyInput
	ldrh r0, [r4]
	ldrh r3, [r5]
	eors r0, r3
	ands r0, r3
	strh r0, [r5, 0x2]
	lsls r0, r3, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080049A8
	ldrh r1, [r5, 0x8]
	movs r0, 0xF0
	adds r2, r0, 0
	ands r2, r3
	ands r0, r1
	cmp r0, r2
	bne _080049A0
	ldr r0, [r5, 0xC]
	cmp r0, 0x31
	bgt _080049AC
	adds r0, 0x1
	str r0, [r5, 0xC]
	b _080049AC
	.align 2, 0
_08004998: .4byte gUnknown_2025658
_0800499C: .4byte gUnknown_2025648
_080049A0:
	strh r2, [r5, 0x8]
	movs r0, 0x1
	str r0, [r5, 0xC]
	b _080049AC
_080049A8:
	str r0, [r5, 0xC]
	strh r0, [r5, 0x8]
_080049AC:
	ldr r0, _080049C4
	ldr r2, [r0, 0xC]
	adds r3, r0, 0
	cmp r2, 0x1
	bne _080049C8
	ldrh r0, [r3, 0x8]
	movs r1, 0xF0
	ands r1, r0
	ldrh r0, [r3, 0x2]
	orrs r1, r0
	strh r1, [r3, 0x4]
	b _080049E0
	.align 2, 0
_080049C4: .4byte gUnknown_2025648
_080049C8:
	cmp r2, 0x30
	bne _080049DC
	movs r0, 0x2B
	str r0, [r3, 0xC]
	ldrh r1, [r3, 0x8]
	movs r0, 0xF0
	ands r0, r1
	ldrh r1, [r3, 0x2]
	orrs r0, r1
	b _080049DE
_080049DC:
	movs r0, 0
_080049DE:
	strh r0, [r3, 0x4]
_080049E0:
	movs r0, 0
	strh r0, [r3, 0x6]
	ldrh r1, [r3]
	movs r5, 0x2
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08004A0C
	ldr r0, _08004A08
	ldrh r2, [r0]
	movs r4, 0
	ldrsh r1, [r0, r4]
	adds r4, r0, 0
	cmp r1, 0x63
	bgt _08004A20
	adds r0, r2, 0x1
	strh r0, [r4]
	b _08004A20
	.align 2, 0
_08004A08: .4byte gUnknown_2025668
_08004A0C:
	ldr r1, _08004A44
	ldrh r0, [r1]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	adds r4, r1, 0
	cmp r0, 0x9
	bhi _08004A1E
	strh r5, [r3, 0x6]
_08004A1E:
	strh r2, [r4]
_08004A20:
	ldrh r1, [r3]
	movs r5, 0x80
	lsls r5, 1
	adds r0, r5, 0
	ands r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _08004A48
	ldrh r1, [r4, 0x2]
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	cmp r0, 0x63
	bgt _08004A5E
	adds r0, r1, 0x1
	strh r0, [r4, 0x2]
	b _08004A5E
	.align 2, 0
_08004A44: .4byte gUnknown_2025668
_08004A48:
	ldrh r0, [r4, 0x2]
	subs r0, 0x2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x9
	bhi _08004A5C
	ldrh r1, [r3, 0x6]
	adds r0, r5, 0
	orrs r0, r1
	strh r0, [r3, 0x6]
_08004A5C:
	strh r2, [r4, 0x2]
_08004A5E:
	ldr r2, _08004A94
	ldrh r0, [r2]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2, 0x2]
	ldrh r1, [r3, 0x2]
	orrs r0, r1
	strh r0, [r2, 0x2]
	ldrh r0, [r2, 0x4]
	ldrh r1, [r3, 0x4]
	orrs r0, r1
	strh r0, [r2, 0x4]
	ldrh r0, [r2, 0x6]
	ldrh r1, [r3, 0x6]
	orrs r0, r1
	strh r0, [r2, 0x6]
	ldr r2, _08004A98
	ldrh r0, [r3]
	ldr r1, _08004A9C
	orrs r0, r1
	ldr r1, [r2]
	muls r0, r1
	str r0, [r2]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004A94: .4byte gUnknown_2025638
_08004A98: .4byte gUnknown_202562C
_08004A9C: .4byte 0x054a1c41
	thumb_func_end UpdateInput

	thumb_func_start nullsub_6
nullsub_6:
	bx lr
	thumb_func_end nullsub_6

	thumb_func_start sub_8004AA4
sub_8004AA4:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r4, [r1, 0x4]
	cmp r2, 0
	ble _08004AE8
_08004AAE:
	ldm r4!, {r1}
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r0, 0
	beq _08004ADE
	movs r0, 0x80
	lsls r0, 24
	str r0, [r3]
	ldrh r0, [r1, 0x2]
	strh r0, [r3, 0x6]
	ldrh r0, [r1, 0x2]
	strh r0, [r3, 0x4]
	adds r0, r1, 0x4
	str r0, [r3, 0x8]
	str r0, [r3, 0xC]
	movs r5, 0
	ldrsh r0, [r1, r5]
	lsls r0, 2
	adds r0, 0x4
	adds r0, r1, r0
	str r0, [r3, 0x10]
	ldr r0, [r1, 0x4]
	str r0, [r3, 0x14]
	b _08004AE0
_08004ADE:
	str r0, [r3]
_08004AE0:
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bne _08004AAE
_08004AE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8004AA4

	thumb_func_start sub_8004AF0
sub_8004AF0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	cmp r7, r3
	bge _08004B6A
	adds r5, r3, 0
_08004B08:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004B60
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004B60
	mov r1, r8
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004B4E
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004B42
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004B42:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r1, 0x1
	movs r7, 0x1
_08004B4E:
	cmp r1, 0
	beq _08004B60
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl SetBGPaletteBufferColorRGB
_08004B60:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bne _08004B08
_08004B6A:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8004AF0

	thumb_func_start sub_8004B78
sub_8004B78:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	cmp r7, r3
	bge _08004BF2
	adds r5, r3, 0
_08004B90:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004BE8
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004BE8
	mov r1, r8
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004BD6
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004BCA
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004BCA:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r1, 0x1
	movs r7, 0x1
_08004BD6:
	cmp r1, 0
	beq _08004BE8
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r6, 0
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	bl nullsub_4
_08004BE8:
	subs r5, 0x1
	adds r4, 0x18
	adds r6, 0x1
	cmp r5, 0
	bne _08004B90
_08004BF2:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8004B78

	thumb_func_start sub_8004C00
sub_8004C00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	mov r10, r3
	ldr r0, [sp, 0x28]
	mov r8, r0
	movs r1, 0
	mov r9, r1
	cmp r9, r2
	bge _08004CDC
	adds r6, r2, 0
_08004C20:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D14
	lsls r0, 24
	cmp r0, 0
	beq _08004CD2
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8004D40
	lsls r0, 24
	cmp r0, 0
	bne _08004CD2
	ldrh r0, [r4, 0x6]
	subs r0, 0x1
	strh r0, [r4, 0x6]
	lsls r0, 16
	cmp r0, 0
	bgt _08004C64
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x10]
	cmp r1, r0
	bcc _08004C58
	ldr r0, [r4, 0x8]
	str r0, [r4, 0xC]
_08004C58:
	ldr r1, [r4, 0xC]
	ldm r1!, {r0}
	str r0, [r4, 0x14]
	str r1, [r4, 0xC]
	movs r2, 0x1
	mov r9, r2
_08004C64:
	mov r3, r8
	movs r5, 0
	ldrsh r0, [r3, r5]
	ldrb r2, [r4, 0x14]
	adds r1, r0, r2
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	ldrb r2, [r4, 0x15]
	adds r3, r0, r2
	mov r5, r8
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	ldrb r2, [r4, 0x16]
	adds r5, r0, r2
	cmp r1, 0xFF
	ble _08004C86
	movs r1, 0xFF
_08004C86:
	cmp r3, 0xFF
	ble _08004C8C
	movs r3, 0xFF
_08004C8C:
	cmp r5, 0xFF
	ble _08004C92
	movs r5, 0xFF
_08004C92:
	cmp r1, 0
	bge _08004C98
	movs r1, 0
_08004C98:
	cmp r3, 0
	bge _08004C9E
	movs r3, 0
_08004C9E:
	cmp r5, 0
	bge _08004CA4
	movs r5, 0
_08004CA4:
	lsls r1, 24
	lsrs r1, 24
	ldr r2, _08004CF0
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r3, 24
	lsrs r2, 16
	ldr r1, _08004CF4
	ands r0, r1
	orrs r0, r2
	lsls r2, r5, 24
	lsrs r2, 8
	ldr r1, _08004CF8
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	adds r0, r7, 0
	mov r1, sp
	mov r2, r10
	ldr r3, [sp, 0x24]
	bl SetBGPaletteBufferColorRGB
_08004CD2:
	subs r6, 0x1
	adds r4, 0x18
	adds r7, 0x1
	cmp r6, 0
	bne _08004C20
_08004CDC:
	mov r0, r9
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08004CF0: .4byte 0xffffff00
_08004CF4: .4byte 0xffff00ff
_08004CF8: .4byte 0xff00ffff
	thumb_func_end sub_8004C00

	thumb_func_start sub_8004CFC
sub_8004CFC:
	push {lr}
	cmp r1, 0
	ble _08004D0E
	movs r2, 0
_08004D04:
	str r2, [r0]
	adds r0, 0x18
	subs r1, 0x1
	cmp r1, 0
	bne _08004D04
_08004D0E:
	pop {r0}
	bx r0
	thumb_func_end sub_8004CFC

	thumb_func_start sub_8004D14
sub_8004D14:
	push {r4,lr}
	adds r2, r0, 0
	movs r3, 0
	cmp r3, r1
	bge _08004D36
	movs r4, 0x80
	lsls r4, 24
_08004D22:
	ldr r0, [r2]
	ands r0, r4
	cmp r0, 0
	beq _08004D2E
	movs r0, 0x1
	b _08004D38
_08004D2E:
	adds r2, 0x18
	adds r3, 0x1
	cmp r3, r1
	blt _08004D22
_08004D36:
	movs r0, 0
_08004D38:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8004D14

	thumb_func_start sub_8004D40
sub_8004D40:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	movs r1, 0
	cmp r1, r4
	bge _08004D70
	movs r6, 0x80
	lsls r6, 24
	movs r5, 0x80
	lsls r5, 22
_08004D54:
	ldr r2, [r3]
	adds r0, r2, 0
	ands r0, r6
	cmp r0, 0
	beq _08004D6A
	ands r2, r5
	cmp r2, 0
	bne _08004D68
	movs r0, 0
	b _08004D72
_08004D68:
	adds r3, 0x18
_08004D6A:
	adds r1, 0x1
	cmp r1, r4
	blt _08004D54
_08004D70:
	movs r0, 0x1
_08004D72:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8004D40

	thumb_func_start sub_8004D78
sub_8004D78:
	push {lr}
	movs r0, 0x1
	bl sub_8004D8C
	movs r0, 0
	bl SetSavingIconCoords
	pop {r0}
	bx r0
	thumb_func_end sub_8004D78

	thumb_func_start sub_8004D8C
sub_8004D8C:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, _08004E68
	movs r0, 0
	str r0, [r1]
	ldr r1, _08004E6C
	ldr r0, _08004E70
	str r0, [r1]
	ldr r1, _08004E74
	ldr r0, _08004E78
	str r0, [r1]
	ldr r0, _08004E7C
	adds r1, r0, 0
	adds r1, 0x8
	adds r5, r0, 0
	movs r2, 0
	movs r3, 0xF0
_08004DB0:
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	str r1, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	adds r1, 0x8
	subs r3, 0x10
	cmp r3, 0
	bge _08004DB0
	cmp r4, 0
	beq _08004E50
	movs r2, 0
	ldr r1, _08004E80
	ldr r0, _08004E84
	movs r3, 0x7F
_08004E42:
	str r2, [r0]
	str r1, [r0, 0x4]
	adds r1, 0x8
	adds r0, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08004E42
_08004E50:
	movs r1, 0x80
	lsls r1, 4
	adds r0, r5, r1
	movs r1, 0
	str r1, [r0]
	ldr r2, _08004E88
	adds r0, r5, r2
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004E68: .4byte gUnknown_20266A8
_08004E6C: .4byte gUnknown_2026E30
_08004E70: .4byte 0x06010000
_08004E74: .4byte gUnknown_203B074
_08004E78: .4byte gUnknown_20266B0
_08004E7C: .4byte gUnknown_20256A0
_08004E80: .4byte gUnknown_20262A8
_08004E84: .4byte gUnknown_2025EA8
_08004E88: .4byte 0x00000804
	thumb_func_end sub_8004D8C

	thumb_func_start sub_8004E8C
sub_8004E8C:
	ldr r1, _08004EA4
	strh r1, [r0]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x2]
	strh r1, [r0, 0x4]
	movs r1, 0
	strh r1, [r0, 0x6]
	strh r1, [r0, 0x8]
	strh r1, [r0, 0xA]
	bx lr
	.align 2, 0
_08004EA4: .4byte 0x0000ffff
	thumb_func_end sub_8004E8C

	thumb_func_start sub_8004EA8
sub_8004EA8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	adds r5, r0, 0
	mov r8, r1
	adds r0, r2, 0
	adds r6, r3, 0
	cmp r0, 0
	beq _08004EC2
	bl sub_80052BC
_08004EC2:
	ldr r0, _08004F40
	ldr r7, [r0]
	mov r12, r0
	cmp r7, 0x7F
	ble _08004ECE
	b _08005082
_08004ECE:
	mov r2, sp
	ldrh r0, [r5]
	strh r0, [r2]
	ldrh r0, [r5, 0x2]
	strh r0, [r2, 0x2]
	ldrh r4, [r5, 0x4]
	ldr r0, _08004F44
	ands r0, r4
	strh r0, [r2, 0x4]
	ldrh r3, [r5, 0x6]
	ldr r0, _08004F48
	ands r0, r3
	strh r0, [r2, 0x6]
	ldrh r0, [r5, 0x8]
	strh r0, [r2, 0x8]
	movs r1, 0xE0
	lsls r1, 4
	ands r1, r3
	lsrs r1, 9
	ldr r0, _08004F4C
	ands r0, r4
	lsls r0, 4
	orrs r1, r0
	strh r1, [r2, 0xA]
	lsls r1, r7, 3
	ldr r0, _08004F50
	adds r3, r1, r0
	mov r0, r8
	movs r2, 0x16
	ldrsh r1, [r0, r2]
	mov r0, sp
	ldrb r0, [r0, 0x3]
	lsls r0, 24
	asrs r0, 24
	adds r7, r1, r0
	cmp r7, 0
	bge _08004F1A
	movs r7, 0
_08004F1A:
	cmp r7, 0xFF
	ble _08004F20
	movs r7, 0xFF
_08004F20:
	cmp r6, 0
	bne _08004F54
	add r2, sp, 0x4
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	ldrh r0, [r2]
	strh r0, [r3, 0x2]
	adds r2, 0x2
	adds r1, r3, 0x4
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, 0x2
	ldrh r0, [r2]
	strh r0, [r1, 0x2]
	b _08004F86
	.align 2, 0
_08004F40: .4byte gUnknown_20266A8
_08004F44: .4byte 0x0000fcff
_08004F48: .4byte 0x0000f1ff
_08004F4C: .4byte 0x000003ff
_08004F50: .4byte gUnknown_20262A8
_08004F54:
	add r4, sp, 0x4
	ldrh r1, [r4]
	ldrh r0, [r6]
	ands r0, r1
	ldrh r1, [r6, 0x6]
	orrs r0, r1
	strh r0, [r3]
	adds r4, 0x2
	ldrh r1, [r4]
	ldrh r0, [r6, 0x2]
	ands r0, r1
	ldrh r1, [r6, 0x8]
	orrs r0, r1
	strh r0, [r3, 0x2]
	adds r4, 0x2
	adds r2, r3, 0x4
	ldrh r1, [r4]
	ldrh r0, [r6, 0x4]
	ands r0, r1
	ldrh r1, [r6, 0xA]
	orrs r0, r1
	strh r0, [r2]
	adds r4, 0x2
	ldrh r0, [r4]
	strh r0, [r2, 0x2]
_08004F86:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _08004FB0
	ldr r1, _08004FA8
	mov r0, sp
	ldrb r0, [r0, 0x2]
	lsls r0, 1
	adds r1, r0, r1
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _08004FB0
	adds r1, r0, 0
	ldr r0, _08004FAC
	ands r1, r0
	b _08004FC0
	.align 2, 0
_08004FA8: .4byte gUnknown_2025672
_08004FAC: .4byte 0x000003ff
_08004FB0:
	ldrh r1, [r3, 0x4]
	ldr r2, _08005090
	ands r1, r2
	mov r6, r8
	movs r4, 0x14
	ldrsh r0, [r6, r4]
	adds r1, r0
	ands r1, r2
_08004FC0:
	ldrh r2, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r4, [r3, 0x2]
	ldr r5, _08005094
	adds r2, r5, 0
	ands r2, r4
	ldr r6, _08005098
	adds r1, r2, r6
	mov r2, r8
	movs r6, 0
	ldrsh r0, [r2, r6]
	adds r2, r1, r0
	movs r0, 0x40
	negs r0, r0
	mov r9, r0
	cmp r2, r9
	blt _08005082
	cmp r2, 0xEF
	bgt _08005082
	ands r2, r5
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r4
	orrs r0, r2
	strh r0, [r3, 0x2]
	ldrh r0, [r3, 0x6]
	lsls r4, r0, 16
	ldr r1, _0800509C
	adds r5, r1, 0
	lsrs r2, r4, 20
	ldr r6, _080050A0
	adds r1, r2, r6
	mov r2, r8
	movs r6, 0x2
	ldrsh r0, [r2, r6]
	adds r2, r1, r0
	cmp r2, r9
	blt _08005082
	cmp r2, 0x9F
	bgt _08005082
	movs r0, 0xFF
	ands r2, r0
	ldrh r1, [r3]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	lsrs r0, r4, 17
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08005044
	mov r0, r8
	ldrb r1, [r0, 0x1E]
	movs r0, 0xF
	ands r1, r0
	lsls r1, 12
	ldrh r0, [r3, 0x4]
	ands r0, r5
	orrs r0, r1
	strh r0, [r3, 0x4]
_08005044:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _08005068
	ldr r1, _080050A4
	mov r0, sp
	ldrb r0, [r0, 0x2]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0xF
	ands r1, r0
	lsls r1, 12
	ldrh r0, [r3, 0x4]
	ands r0, r5
	orrs r0, r1
	strh r0, [r3, 0x4]
_08005068:
	ldr r0, _080050A8
	mov r4, r12
	ldr r3, [r4]
	lsls r2, r3, 3
	adds r2, r0
	ldr r1, _080050AC
	lsls r0, r7, 3
	adds r0, r1
	ldr r1, [r0]
	str r1, [r2]
	str r2, [r0]
	adds r3, 0x1
	str r3, [r4]
_08005082:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005090: .4byte 0x000003ff
_08005094: .4byte 0x000001ff
_08005098: .4byte 0xffffff00
_0800509C: .4byte 0x00000fff
_080050A0: .4byte 0xfffffe00
_080050A4: .4byte gUnknown_2025682
_080050A8: .4byte gUnknown_2025EA8
_080050AC: .4byte gUnknown_20256A0
	thumb_func_end sub_8004EA8

	thumb_func_start AddSprite
AddSprite:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r7, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r0, _080050F4
	ldr r0, [r0]
	cmp r0, 0x7F
	bgt _08005168
	lsls r1, r0, 3
	ldr r0, _080050F8
	adds r5, r1, r0
	cmp r7, 0
	bge _080050D2
	movs r7, 0
_080050D2:
	cmp r7, 0xFF
	ble _080050D8
	movs r7, 0xFF
_080050D8:
	cmp r4, 0
	bne _080050FC
	ldrh r0, [r6]
	strh r0, [r5]
	ldrh r0, [r6, 0x2]
	strh r0, [r5, 0x2]
	adds r1, r6, 0x4
	adds r2, r5, 0x4
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x2]
	b _08005128
	.align 2, 0
_080050F4: .4byte gUnknown_20266A8
_080050F8: .4byte gUnknown_20262A8
_080050FC:
	ldrh r1, [r6]
	ldrh r0, [r4]
	ands r0, r1
	ldrh r1, [r4, 0x6]
	orrs r0, r1
	strh r0, [r5]
	ldrh r1, [r6, 0x2]
	ldrh r0, [r4, 0x2]
	ands r0, r1
	ldrh r1, [r4, 0x8]
	orrs r0, r1
	strh r0, [r5, 0x2]
	adds r2, r6, 0x4
	adds r3, r5, 0x4
	ldrh r1, [r2]
	ldrh r0, [r4, 0x4]
	ands r0, r1
	ldrh r1, [r4, 0xA]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2, 0x2]
	strh r0, [r3, 0x2]
_08005128:
	ldrh r4, [r5, 0x6]
	lsrs r4, 4
	adds r0, r4, 0
	movs r1, 0
	bl nullsub_3
	movs r0, 0xFF
	ands r4, r0
	ldrh r1, [r5]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	orrs r0, r4
	strh r0, [r5]
	mov r0, r8
	cmp r0, 0
	beq _0800514E
	bl sub_80052BC
_0800514E:
	ldr r0, _08005174
	ldr r4, _08005178
	ldr r3, [r4]
	lsls r2, r3, 3
	adds r2, r0
	ldr r1, _0800517C
	lsls r0, r7, 3
	adds r0, r1
	ldr r1, [r0]
	str r1, [r2]
	str r2, [r0]
	adds r3, 0x1
	str r3, [r4]
_08005168:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005174: .4byte gUnknown_2025EA8
_08005178: .4byte gUnknown_20266A8
_0800517C: .4byte gUnknown_20256A0
	thumb_func_end AddSprite

	thumb_func_start sub_8005180
sub_8005180:
	push {lr}
	ldr r2, _080051A8
	adds r1, r2, 0
	cmp r2, 0
	beq _0800519E
_0800518A:
	ldr r0, [r1, 0x4]
	cmp r0, 0
	beq _08005198
	cmp r2, 0
	beq _08005196
	str r1, [r2]
_08005196:
	adds r2, r1, 0
_08005198:
	ldr r1, [r1]
	cmp r1, 0
	bne _0800518A
_0800519E:
	movs r0, 0
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080051A8: .4byte gUnknown_20256A0
	thumb_func_end sub_8005180

	thumb_func_start CopySpritesToOam
CopySpritesToOam:
	push {r4-r6,lr}
	ldr r3, _08005204
	ldr r2, _08005208
	movs r4, 0
	ldr r6, _0800520C
	cmp r3, 0
	beq _080051E0
	ldr r5, _08005210
_080051BC:
	ldr r1, [r3, 0x4]
	cmp r1, 0
	beq _080051D6
	subs r2, 0x4
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x2
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	subs r2, 0x2
	ldrh r0, [r1]
	strh r0, [r2]
	adds r4, 0x1
_080051D6:
	ldr r3, [r3]
	cmp r3, 0
	beq _080051E0
	cmp r2, r5
	bhi _080051BC
_080051E0:
	ldr r1, _08005210
	cmp r2, r1
	bls _080051FA
	movs r0, 0
	movs r3, 0xA0
_080051EA:
	subs r2, 0x4
	strh r0, [r2]
	subs r2, 0x2
	strh r0, [r2]
	subs r2, 0x2
	strh r3, [r2]
	cmp r2, r1
	bhi _080051EA
_080051FA:
	strh r4, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08005204: .4byte gUnknown_20256A0
_08005208: .4byte 0x07000400
_0800520C: .4byte gUnknown_2025670
_08005210: .4byte 0x07000008
	thumb_func_end CopySpritesToOam

	thumb_func_start SetSavingIconCoords
SetSavingIconCoords:
	push {lr}
	adds r3, r0, 0
	cmp r3, 0
	bne _0800522C
	ldr r1, _08005228
	strh r3, [r1]
	movs r0, 0xA0
	strh r0, [r1, 0x2]
	b _0800523C
	.align 2, 0
_08005228: .4byte gUnknown_2025694
_0800522C:
	ldr r1, _08005240
	ldrh r0, [r3]
	movs r2, 0
	strh r0, [r1]
	ldrh r0, [r3, 0x2]
	strh r0, [r1, 0x2]
	ldr r0, _08005244
	str r2, [r0]
_0800523C:
	pop {r0}
	bx r0
	.align 2, 0
_08005240: .4byte gUnknown_2025694
_08005244: .4byte gUnknown_2025698
	thumb_func_end SetSavingIconCoords

	thumb_func_start BlinkSavingIcon
BlinkSavingIcon:
	push {r4,lr}
	movs r2, 0xE0
	lsls r2, 19
	ldr r0, _08005280
	ldr r1, [r0]
	adds r3, r1, 0
	adds r1, 0x1
	str r1, [r0]
	movs r0, 0x10
	ands r3, r0
	cmp r3, 0
	beq _08005288
	movs r0, 0xA0
	strh r0, [r2]
	adds r2, 0x2
	movs r1, 0x80
	lsls r1, 7
	adds r0, r1, 0
	strh r0, [r2]
	adds r2, 0x2
	ldr r4, _08005284
	adds r0, r4, 0
	strh r0, [r2]
	adds r2, 0x2
	movs r0, 0
	strh r0, [r2]
	b _080052A8
	.align 2, 0
_08005280: .4byte gUnknown_2025698
_08005284: .4byte 0x0000f3fc
_08005288:
	ldr r1, _080052B0
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	ldr r2, _080052B4
	movs r4, 0x80
	lsls r4, 7
	adds r0, r4, 0
	ldrh r1, [r1]
	adds r0, r1
	strh r0, [r2]
	adds r2, 0x2
	ldr r1, _080052B8
	adds r0, r1, 0
	strh r0, [r2]
	adds r2, 0x2
	strh r3, [r2]
_080052A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080052B0: .4byte gUnknown_2025694
_080052B4: .4byte 0x07000002
_080052B8: .4byte 0x0000f3fc
	thumb_func_end BlinkSavingIcon

	thumb_func_start sub_80052BC
sub_80052BC:
	push {r4-r6,lr}
	adds r3, r0, 0
	ldr r0, [r3, 0x4]
	cmp r0, 0
	beq _080052F2
	ldr r5, _080052F8
	ldr r6, _080052FC
	ldr r4, _08005300
_080052CC:
	ldr r2, [r5]
	cmp r2, r6
	bcs _080052F2
	ldr r0, [r3, 0x4]
	str r0, [r2]
	ldr r0, [r3]
	str r0, [r2, 0x4]
	ldr r1, [r4]
	str r1, [r2, 0x8]
	ldr r0, [r3, 0x4]
	adds r1, r0
	str r1, [r4]
	adds r0, r2, 0
	adds r0, 0xC
	str r0, [r5]
	adds r3, 0x8
	ldr r0, [r3, 0x4]
	cmp r0, 0
	bne _080052CC
_080052F2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080052F8: .4byte gUnknown_203B074
_080052FC: .4byte gUnknown_2026E30
_08005300: .4byte gUnknown_2026E30
	thumb_func_end sub_80052BC

	thumb_func_start sub_8005304
sub_8005304:
	push {r4,lr}
	ldr r4, _0800530C
	b _0800532A
	.align 2, 0
_0800530C: .4byte gUnknown_20266B0
_08005310:
	ldr r1, [r4, 0x4]
	cmp r1, 0
	beq _08005320
	ldr r0, [r4, 0x8]
	ldr r2, [r4]
	bl CpuCopy
	b _08005328
_08005320:
	ldr r0, [r4, 0x8]
	ldr r1, [r4]
	bl CpuClear
_08005328:
	adds r4, 0xC
_0800532A:
	ldr r0, _08005338
	ldr r0, [r0]
	cmp r4, r0
	bcc _08005310
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08005338: .4byte gUnknown_203B074
	thumb_func_end sub_8005304

	thumb_func_start sub_800533C
sub_800533C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, 0
	adds r7, r3, 0
	ldr r1, [sp, 0x18]
	lsls r1, 24
	lsrs r6, r1, 24
	movs r2, 0x18
	ldrsh r1, [r5, r2]
	lsls r1, 2
	adds r1, r0
	ldr r4, [r1]
	ldr r1, _08005368
	movs r2, 0x14
	ldrsh r0, [r5, r2]
	lsls r0, 5
	ldr r2, _0800536C
	adds r0, r2
	str r0, [r1]
	b _0800538E
	.align 2, 0
_08005368: .4byte gUnknown_2026E30
_0800536C: .4byte 0x06010000
_08005370:
	cmp r6, 0
	beq _08005382
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08005382
	lsls r0, 2
	add r0, r8
	ldr r2, [r0]
_08005382:
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r7, 0
	bl sub_8004EA8
	adds r4, 0xA
_0800538E:
	movs r2, 0
	ldrh r1, [r4]
	ldr r0, _080053A8
	cmp r1, r0
	bne _08005370
	ldrh r0, [r4, 0x2]
	cmp r0, r1
	bne _08005370
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080053A8: .4byte 0x0000ffff
	thumb_func_end sub_800533C

	thumb_func_start sub_80053AC
sub_80053AC:
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r5, [sp, 0x1C]
	ldr r6, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [r1, 0x4]
	str r5, [sp]
	str r6, [sp, 0x4]
	str r4, [sp, 0x8]
	bl sub_80053D0
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80053AC

	thumb_func_start sub_80053D0
sub_80053D0:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x1C]
	lsls r0, 24
	movs r2, 0
	movs r3, 0x80
	lsls r3, 8
	strh r3, [r4]
	cmp r0, 0
	beq _080053F6
	movs r0, 0x80
	lsls r0, 5
	adds r1, r0, 0
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r4]
_080053F6:
	strh r2, [r4, 0x2]
	ldr r0, [sp, 0x18]
	strh r0, [r4, 0x4]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	ldr r0, [sp, 0x14]
	strh r0, [r4, 0x1C]
	ldr r0, _08005438
	strh r0, [r4, 0x20]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x22]
	str r2, [r4, 0x14]
	str r2, [r4, 0x18]
	strh r2, [r4, 0x6]
	ldr r1, [r5, 0x4]
	lsls r0, r6, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	ldr r0, [r5]
	str r0, [r4, 0x34]
	ldr r0, [r5, 0xC]
	str r0, [r4, 0x38]
	ldr r0, [r5, 0x10]
	str r0, [r4, 0x30]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005438: .4byte 0x0000ffff
	thumb_func_end sub_80053D0

	thumb_func_start sub_800543C
sub_800543C:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, [sp, 0x14]
	ldr r4, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	ldr r1, [r1, 0x4]
	str r5, [sp]
	str r4, [sp, 0x4]
	bl sub_800545C
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800543C

	thumb_func_start sub_800545C
sub_800545C:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	ldr r0, [sp, 0x18]
	lsls r0, 24
	movs r2, 0
	movs r3, 0x80
	lsls r3, 8
	strh r3, [r4]
	cmp r0, 0
	beq _08005482
	movs r0, 0x80
	lsls r0, 5
	adds r1, r0, 0
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r4]
_08005482:
	strh r2, [r4, 0x2]
	ldr r0, [sp, 0x14]
	strh r0, [r4, 0x4]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	strh r5, [r4, 0x1C]
	ldr r0, _080054B8
	strh r0, [r4, 0x20]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r4, 0x22]
	str r2, [r4, 0x14]
	str r2, [r4, 0x18]
	strh r2, [r4, 0x6]
	ldr r1, [r6, 0x4]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	ldr r0, [r6]
	str r0, [r4, 0x34]
	str r2, [r4, 0x30]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080054B8: .4byte 0x0000ffff
	thumb_func_end sub_800545C

	thumb_func_start sub_80054BC
sub_80054BC:
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _080054D0
	movs r0, 0
	b _080054D2
_080054D0:
	lsrs r0, r1, 15
_080054D2:
	cmp r0, 0
	beq _08005586
	movs r1, 0x20
	ldrsh r0, [r4, r1]
	ldrh r3, [r4]
	cmp r0, 0
	blt _08005524
	movs r0, 0x80
	lsls r0, 7
	ands r0, r3
	cmp r0, 0
	bne _08005586
	ldrh r2, [r4, 0x6]
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	ldr r0, _0800550C
	cmp r1, r0
	bgt _080054FA
	adds r0, r2, 0x1
	strh r0, [r4, 0x6]
_080054FA:
	ldrh r1, [r4, 0x4]
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08005510
	subs r0, r1, 0x1
	strh r0, [r4, 0x4]
	b _08005586
	.align 2, 0
_0800550C: .4byte 0x0000752f
_08005510:
	ldrh r1, [r4, 0x2]
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08005524
	subs r0, r1, 0x1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _08005586
_08005524:
	ldr r0, [r4, 0x2C]
	ldrb r0, [r0]
	cmp r0, 0
	bne _08005550
	movs r0, 0x80
	lsls r0, 5
	ands r0, r3
	cmp r0, 0
	bne _08005542
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	orrs r0, r3
	strh r0, [r4]
	b _08005586
_08005542:
	ldr r0, [r4, 0x28]
	str r0, [r4, 0x2C]
	bl Random
	movs r1, 0x1
	ands r0, r1
	strh r0, [r4, 0x4]
_08005550:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, [r4, 0x2C]
	ldrb r0, [r1]
	strh r0, [r4, 0x2]
	ldrh r0, [r1, 0x2]
	strh r0, [r4, 0x20]
	ldrh r0, [r1, 0x4]
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x6]
	strh r0, [r4, 0xE]
	ldrh r0, [r1, 0x8]
	strh r0, [r4, 0x10]
	ldrh r0, [r1, 0xA]
	strh r0, [r4, 0x12]
	ldrb r0, [r1, 0x1]
	str r0, [r4, 0x14]
	ldrb r2, [r1, 0x1]
	ldr r0, [r4, 0x18]
	orrs r0, r2
	str r0, [r4, 0x18]
	adds r1, 0xC
	str r1, [r4, 0x2C]
_08005586:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80054BC

	thumb_func_start sub_800558C
sub_800558C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	movs r1, 0x20
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _080055AE
	adds r0, r5, 0
	bl sub_80054BC
_080055AE:
	ldrh r0, [r5]
	lsrs r0, 15
	cmp r0, 0
	beq _08005602
	ldrh r0, [r5, 0xC]
	adds r0, r4
	strh r0, [r5, 0x8]
	ldrh r0, [r5, 0xE]
	adds r0, r6
	strh r0, [r5, 0xA]
	adds r1, r5, 0
	adds r1, 0x26
	ldr r0, [sp, 0x18]
	strb r0, [r1]
	strh r7, [r5, 0x1E]
	ldr r0, [r5, 0x34]
	ldr r1, [r5, 0x38]
	adds r2, r5, 0
	adds r2, 0x8
	movs r3, 0x22
	ldrsh r4, [r5, r3]
	movs r6, 0x20
	ldrsh r3, [r5, r6]
	eors r4, r3
	negs r3, r4
	orrs r3, r4
	lsrs r3, 31
	str r3, [sp]
	ldr r3, [sp, 0x1C]
	bl sub_800533C
	ldrh r0, [r5, 0x20]
	strh r0, [r5, 0x22]
	ldrh r1, [r5]
	movs r0, 0x80
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	beq _08005602
	ldr r0, _0800560C
	ands r0, r1
	strh r0, [r5]
_08005602:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800560C: .4byte 0x0000f7ff
	thumb_func_end sub_800558C

	thumb_func_start sub_8005610
sub_8005610:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_800561C
	pop {r0}
	bx r0
	thumb_func_end sub_8005610

	thumb_func_start sub_800561C
sub_800561C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	ldr r1, [r5, 0x14]
	cmp r1, 0
	beq _0800563A
	lsls r0, 5
	ldr r2, _08005664
	adds r0, r2
	ldr r2, [r5, 0x1C]
	lsls r2, 5
	bl CpuCopy
_0800563A:
	ldr r0, [r5, 0x18]
	cmp r0, 0
	beq _0800565C
	movs r4, 0
_08005642:
	movs r1, 0xF0
	lsls r1, 1
	adds r0, r4, r1
	lsls r2, r4, 2
	ldr r1, [r5, 0x18]
	adds r1, r2
	adds r2, r7, 0
	adds r3, r6, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x1
	cmp r4, 0xF
	ble _08005642
_0800565C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005664: .4byte 0x06010000
	thumb_func_end sub_800561C

	thumb_func_start sub_8005668
sub_8005668:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_8005674
	pop {r1}
	bx r1
	thumb_func_end sub_8005668

	thumb_func_start sub_8005674
sub_8005674:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r4, 0x14]
	cmp r3, 0
	beq _0800568E
	lsls r0, r1, 5
	ldr r1, _08005698
	adds r0, r1
	ldr r2, [r4, 0x1C]
	lsls r2, 5
	adds r1, r3, 0
	bl CpuCopy
_0800568E:
	ldr r0, [r4, 0x18]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005698: .4byte 0x06010000
	thumb_func_end sub_8005674

	thumb_func_start sub_800569C
sub_800569C:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	strh r0, [r3]
	strh r0, [r3, 0x2]
	ldrh r0, [r4]
	lsrs r0, 15
	cmp r0, 0
	beq _080056F8
	cmp r2, 0x3
	bhi _080056F8
	ldr r1, [r4, 0x30]
	cmp r1, 0
	beq _080056F2
	movs r5, 0x20
	ldrsh r0, [r4, r5]
	lsls r0, 4
	adds r5, r1, r0
	lsls r0, r2, 2
	adds r2, r5, r0
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	movs r6, 0x2
	ldrsh r1, [r2, r6]
	cmp r1, 0x63
	bne _080056E0
	strh r1, [r3]
	strh r1, [r3, 0x2]
	b _080056F8
_080056E0:
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r4, 0xC]
	adds r1, r2
	strh r1, [r3]
	ldrh r0, [r0, 0x2]
	ldrh r4, [r4, 0xE]
	adds r0, r4
	b _080056F6
_080056F2:
	movs r0, 0x63
	strh r0, [r3]
_080056F6:
	strh r0, [r3, 0x2]
_080056F8:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_800569C

	thumb_func_start sub_8005700
sub_8005700:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldrh r0, [r1]
	lsrs r0, 15
	cmp r0, 0
	beq _0800575C
	ldr r2, [r1, 0x30]
	cmp r2, 0
	beq _0800574C
	movs r4, 0x20
	ldrsh r0, [r1, r4]
	lsls r0, 4
	adds r2, r0
	adds r4, r2, 0
	adds r4, 0xC
_0800571E:
	movs r5, 0
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	cmp r0, 0x63
	bne _08005732
	strh r0, [r3]
	b _08005740
_08005732:
	ldrh r0, [r2]
	ldrh r5, [r1, 0xC]
	adds r0, r5
	strh r0, [r3]
	ldrh r0, [r2, 0x2]
	ldrh r5, [r1, 0xE]
	adds r0, r5
_08005740:
	strh r0, [r3, 0x2]
	adds r3, 0x4
	adds r2, 0x4
	cmp r2, r4
	ble _0800571E
	b _0800575C
_0800574C:
	movs r1, 0x63
	movs r0, 0x3
_08005750:
	strh r1, [r3]
	strh r1, [r3, 0x2]
	adds r3, 0x4
	subs r0, 0x1
	cmp r0, 0
	bge _08005750
_0800575C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8005700

	thumb_func_start sub_8005764
sub_8005764:
	push {lr}
	ldr r1, [r1, 0x4]
	bl sub_8005770
	pop {r0}
	bx r0
	thumb_func_end sub_8005764

	thumb_func_start sub_8005770
sub_8005770:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	adds r7, r3, 0
	movs r5, 0
	adds r0, 0x10
	lsls r6, r0, 4
	adds r4, r1, 0
_08005782:
	adds r0, r6, r5
	adds r1, r4, 0
	mov r2, r8
	adds r3, r7, 0
	bl SetBGPaletteBufferColorRGB
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08005782
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8005770

	thumb_func_start nullsub_7
nullsub_7:
	bx lr
	thumb_func_end nullsub_7

	thumb_func_start nullsub_8
nullsub_8:
	bx lr
	thumb_func_end nullsub_8

	thumb_func_start nullsub_9
nullsub_9:
	bx lr
	thumb_func_end nullsub_9

	thumb_func_start nullsub_10
nullsub_10:
	bx lr
	thumb_func_end nullsub_10

	thumb_func_start nullsub_144
nullsub_144:
	bx lr
	thumb_func_end nullsub_144

	thumb_func_start nullsub_11
nullsub_11:
	bx lr
	thumb_func_end nullsub_11

	thumb_func_start nullsub_12
nullsub_12:
	bx lr
	thumb_func_end nullsub_12

	thumb_func_start nullsub_13
nullsub_13:
	bx lr
	thumb_func_end nullsub_13

	thumb_func_start nullsub_145
nullsub_145:
	bx lr
	thumb_func_end nullsub_145

	thumb_func_start nullsub_14
nullsub_14:
	bx lr
	thumb_func_end nullsub_14

	thumb_func_start nullsub_146
nullsub_146:
	bx lr
	thumb_func_end nullsub_146

	thumb_func_start nullsub_147
nullsub_147:
	bx lr
	thumb_func_end nullsub_147

	thumb_func_start nullsub_148
nullsub_148:
	bx lr
	thumb_func_end nullsub_148

	thumb_func_start nullsub_149
nullsub_149:
	bx lr
	thumb_func_end nullsub_149

	thumb_func_start sub_80057D8
sub_80057D8:
	movs r0, 0
	bx lr
	thumb_func_end sub_80057D8

	thumb_func_start sub_80057DC
sub_80057DC:
	movs r0, 0
	bx lr
	thumb_func_end sub_80057DC

	thumb_func_start nullsub_150
nullsub_150:
	bx lr
	thumb_func_end nullsub_150

	thumb_func_start nullsub_151
nullsub_151:
	bx lr
	thumb_func_end nullsub_151

	thumb_func_start sub_80057E8
sub_80057E8:
	ldr r1, _08005814
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _08005818
	movs r2, 0
	str r2, [r0]
	ldr r1, _0800581C
	movs r0, 0x1
	str r0, [r1]
	ldr r0, _08005820
	str r2, [r0]
	ldr r0, _08005824
	str r2, [r0]
	ldr r0, _08005828
	strb r2, [r0]
	ldr r1, _0800582C
	ldr r3, _08005830
	adds r0, r3, 0
	strh r0, [r1]
	ldr r0, _08005834
	str r2, [r0]
	bx lr
	.align 2, 0
_08005814: .4byte gUnknown_2026E4C
_08005818: .4byte gUnknown_2026E54
_0800581C: .4byte gUnknown_2026E50
_08005820: .4byte gUnknown_2026E58
_08005824: .4byte gUnknown_2026E3C
_08005828: .4byte gUnknown_2026E38
_0800582C: .4byte gUnknown_2026E4E
_08005830: .4byte 0x0000060c
_08005834: .4byte gUnknown_203B078
	thumb_func_end sub_80057E8

	thumb_func_start sub_8005838
sub_8005838:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, _08005880
	ldrb r0, [r0]
	cmp r0, 0
	bne _08005854
	movs r1, 0
_08005854:
	ldr r0, _08005884
	ldr r0, [r0]
	ldr r3, _08005888
	cmp r0, 0
	bne _08005860
	ldr r3, _0800588C
_08005860:
	ldr r0, _08005890
	ldr r2, [r0]
	cmp r2, 0
	bne _0800586A
	ldr r2, _08005894
_0800586A:
	ldr r0, _08005898
	str r3, [r0]
	cmp r1, 0x5
	bls _08005876
	bl _08006094
_08005876:
	lsls r0, r1, 2
	ldr r1, _0800589C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08005880: .4byte gUnknown_2026E4C
_08005884: .4byte gUnknown_2026E54
_08005888: .4byte gUnknown_20270E8
_0800588C: .4byte gUnknown_2026E60
_08005890: .4byte gUnknown_203B078
_08005894: .4byte gUnknown_80B83EA
_08005898: .4byte gUnknown_2026E58
_0800589C: .4byte _080058A0
	.align 2, 0
_080058A0:
	.4byte _080058B8
	.4byte _08005984
	.4byte _08005A98
	.4byte _08005BAC
	.4byte _08005D46
	.4byte _08005E58
_080058B8:
	movs r1, 0
	movs r7, 0x9
_080058BC:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _080058BC
	b _08006094
_08005984:
	ldr r1, _08005A94
	movs r7, 0x9
_08005988:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005A90
	b _08005988
_08005A90:
	b _08006094
	.align 2, 0
_08005A94: .4byte gUnknown_80B816A
_08005A98:
	ldr r1, _08005BA8
	movs r7, 0x9
_08005A9C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005BA4
	b _08005A9C
_08005BA4:
	b _08006094
	.align 2, 0
_08005BA8: .4byte gUnknown_80B802A
_08005BAC:
	ldr r0, [r5]
	mov r10, r0
	cmp r0, 0
	bge _08005BBA
	ldr r0, [r5, 0x8]
	cmp r0, 0
	blt _08005BDC
_08005BBA:
	ldr r1, [r5, 0x4]
	cmp r1, 0
	bge _08005BC6
	ldr r0, [r5, 0xC]
	cmp r0, 0
	blt _08005BDC
_08005BC6:
	mov r4, r10
	cmp r4, 0xEF
	ble _08005BD2
	ldr r0, [r5, 0x8]
	cmp r0, 0xEF
	bgt _08005BDC
_08005BD2:
	cmp r1, 0x9F
	ble _08005CA8
	ldr r0, [r5, 0xC]
	cmp r0, 0x9F
	ble _08005CA8
_08005BDC:
	movs r1, 0xF0
	movs r7, 0x9
_08005BE0:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005BE0
	b _08006094
_08005CA8:
	movs r7, 0
	mov r8, r1
	movs r6, 0x80
	lsls r6, 1
	mov r12, r6
	lsls r0, r1, 1
	ldr r1, _08005CCC
	subs r6, r1, r0
	mov r9, r10
_08005CBA:
	cmp r8, r7
	ble _08005CD0
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r4, r12
	strh r4, [r3]
	b _08005D3A
	.align 2, 0
_08005CCC: .4byte gUnknown_80B8008
_08005CD0:
	ldr r1, [r5, 0xC]
	cmp r1, r7
	bgt _08005CE2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r0, r12
	b _08005D38
_08005CE2:
	mov r4, r8
	subs r0, r7, r4
	cmp r0, 0xF
	bgt _08005CF0
	movs r0, 0
	ldrsh r1, [r6, r0]
	b _08005D00
_08005CF0:
	subs r0, r1, r7
	cmp r0, 0xF
	bgt _08005D10
	lsls r0, 1
	ldr r1, _08005D0C
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
_08005D00:
	mov r0, r9
	adds r4, r0, r1
	ldr r0, [r5, 0x8]
	subs r1, r0, r1
	b _08005D14
	.align 2, 0
_08005D0C: .4byte gUnknown_80B8008
_08005D10:
	mov r4, r10
	ldr r1, [r5, 0x8]
_08005D14:
	cmp r4, 0
	bge _08005D1A
	movs r4, 0
_08005D1A:
	cmp r4, 0xEF
	ble _08005D20
	movs r4, 0xEF
_08005D20:
	cmp r1, 0
	bgt _08005D26
	movs r1, 0x1
_08005D26:
	cmp r1, 0xF0
	ble _08005D2C
	movs r1, 0xF0
_08005D2C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	lsls r0, r1, 8
	orrs r0, r4
_08005D38:
	strh r0, [r3]
_08005D3A:
	adds r3, 0x2
	adds r6, 0x2
	adds r7, 0x1
	cmp r7, 0x9F
	ble _08005CBA
	b _08006094
_08005D46:
	ldr r1, _08005E54
	movs r7, 0xE
_08005D4A:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005E52
	b _08005D4A
_08005E52:
	b _08006094
	.align 2, 0
_08005E54: .4byte gUnknown_80B82AA
_08005E58:
	ldr r4, _08005FF4
	ldr r5, _08005FF8
	ldr r6, _08005FFC
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0, 0
	movs r7, 0xE
_08005E66:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005E66
	ldr r4, [r4]
	str r4, [sp]
	ldr r5, [r5]
	str r5, [sp, 0x4]
	ldr r6, [r6]
	str r6, [sp, 0x8]
	adds r1, r6, 0
	cmp r6, 0
	bge _08005F40
	adds r1, 0xFF
_08005F40:
	asrs r1, 8
	adds r1, 0x1
	movs r0, 0x80
	lsls r0, 3
	bl __divsi3
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _08005F56
	adds r0, 0xFF
_08005F56:
	asrs r4, r0, 8
	adds r5, r4, 0
	movs r3, 0
	lsls r0, r4, 2
	adds r7, r0, 0x2
	mov r9, r7
_08005F62:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009C7C
	ldr r1, [sp, 0x8]
	muls r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005F76
	adds r0, 0xFF
_08005F76:
	asrs r0, 8
	ldr r2, [sp, 0x4]
	adds r1, r2, r0
	cmp r1, 0
	bge _08005F82
	adds r1, 0xFF
_08005F82:
	asrs r1, 8
	str r1, [sp, 0x14]
	ldr r6, [sp, 0x4]
	subs r0, r6, r0
	cmp r0, 0
	bge _08005F90
	adds r0, 0xFF
_08005F90:
	asrs r0, 8
	mov r8, r0
	ldr r0, [sp, 0x14]
	cmp r5, r0
	blt _08005FA4
	ldr r1, [sp, 0xC]
	adds r1, r3
	mov r10, r1
	cmp r4, r8
	ble _0800608A
_08005FA4:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009D04
	ldr r2, [sp, 0x8]
	muls r0, r2
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005FB8
	adds r0, 0xFF
_08005FB8:
	asrs r0, 8
	ldr r6, [sp]
	subs r1, r6, r0
	cmp r1, 0
	bge _08005FC4
	adds r1, 0xFF
_08005FC4:
	asrs r1, 8
	ldr r2, [sp]
	adds r0, r2, r0
	cmp r0, 0
	bge _08005FD0
	adds r0, 0xFF
_08005FD0:
	asrs r0, 8
	cmp r1, 0
	bge _08005FD8
	movs r1, 0
_08005FD8:
	cmp r0, 0
	bge _08005FDE
	movs r0, 0
_08005FDE:
	cmp r1, 0xEF
	ble _08005FE4
	movs r1, 0x9F
_08005FE4:
	cmp r0, 0xEF
	ble _08005FEA
	movs r0, 0x9F
_08005FEA:
	cmp r1, r0
	ble _08006000
	lsls r2, r1, 8
	orrs r2, r0
	b _08006004
	.align 2, 0
_08005FF4: .4byte gUnknown_2026E40
_08005FF8: .4byte gUnknown_2026E44
_08005FFC: .4byte gUnknown_2026E48
_08006000:
	lsls r2, r0, 8
	orrs r2, r1
_08006004:
	ldr r6, [sp, 0xC]
	adds r3, r6
	mov r10, r3
	ldr r0, [sp, 0x14]
	cmp r5, r0
	bge _0800604E
	ldr r1, _08006030
	mov r12, r1
	ldr r3, _08006034
	add r3, r9
	ldr r1, _08006038
	add r1, r9
_0800601C:
	cmp r5, 0
	blt _0800603E
	cmp r5, 0x9F
	bgt _0800603E
	mov r6, r12
	ldr r0, [r6]
	cmp r0, 0
	bne _0800603C
	strh r2, [r1]
	b _0800603E
	.align 2, 0
_08006030: .4byte gUnknown_2026E54
_08006034: .4byte gUnknown_20270E8
_08006038: .4byte gUnknown_2026E60
_0800603C:
	strh r2, [r3]
_0800603E:
	adds r3, 0x4
	adds r1, 0x4
	movs r0, 0x4
	add r9, r0
	adds r5, 0x1
	ldr r6, [sp, 0x14]
	cmp r5, r6
	blt _0800601C
_0800604E:
	cmp r4, r8
	ble _0800608A
	ldr r6, _08006070
	ldr r0, _08006074
	adds r3, r7, r0
	ldr r0, _08006078
	adds r1, r7, r0
_0800605C:
	cmp r4, 0
	blt _0800607E
	cmp r4, 0x9F
	bgt _0800607E
	ldr r0, [r6]
	cmp r0, 0
	bne _0800607C
	strh r2, [r1]
	b _0800607E
	.align 2, 0
_08006070: .4byte gUnknown_2026E54
_08006074: .4byte gUnknown_20270E8
_08006078: .4byte gUnknown_2026E60
_0800607C:
	strh r2, [r3]
_0800607E:
	subs r3, 0x4
	subs r1, 0x4
	subs r7, 0x4
	subs r4, 0x1
	cmp r4, r8
	bgt _0800605C
_0800608A:
	mov r3, r10
	ldr r0, _080060A4
	cmp r3, r0
	bgt _08006094
	b _08005F62
_08006094:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080060A4: .4byte 0x000003ff
	thumb_func_end sub_8005838

	thumb_func_start sub_80060A8
sub_80060A8:
	push {lr}
	ldr r1, _080060D8
	ldr r0, _080060DC
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, _080060E0
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _080060BE
	movs r1, 0x1
_080060BE:
	str r1, [r2]
	ldr r2, _080060E4
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _080060CC
	movs r1, 0x1
_080060CC:
	str r1, [r2]
	ldr r1, _080060E8
	movs r0, 0
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080060D8: .4byte gUnknown_2026E3C
_080060DC: .4byte gUnknown_2026E58
_080060E0: .4byte gUnknown_2026E54
_080060E4: .4byte gUnknown_2026E50
_080060E8: .4byte gUnknown_2026E38
	thumb_func_end sub_80060A8

	thumb_func_start sub_80060EC
sub_80060EC:
	push {lr}
	ldr r1, _08006130
	ldr r0, _08006134
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, _08006138
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _08006102
	movs r1, 0x1
_08006102:
	str r1, [r2]
	ldr r2, _0800613C
	movs r1, 0
	ldr r0, [r2]
	cmp r0, 0
	bne _08006110
	movs r1, 0x1
_08006110:
	str r1, [r2]
	ldr r0, _08006140
	ldrh r2, [r0]
	movs r0, 0xF8
	lsls r0, 5
	ands r0, r2
	lsrs r0, 8
	movs r1, 0x1F
	ands r1, r2
	bl sub_800CC44
	ldr r1, _08006144
	movs r0, 0x1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08006130: .4byte gUnknown_2026E3C
_08006134: .4byte gUnknown_2026E58
_08006138: .4byte gUnknown_2026E54
_0800613C: .4byte gUnknown_2026E50
_08006140: .4byte gUnknown_2026E4E
_08006144: .4byte gUnknown_2026E38
	thumb_func_end sub_80060EC

	thumb_func_start SeedRng
SeedRng:
	push {r4,lr}
	ldr r4, _08006170
	ldrb r2, [r0]
	ldrb r1, [r0, 0x1]
	muls r2, r1
	ldrb r3, [r0, 0x2]
	ldrb r1, [r0, 0x3]
	muls r1, r3
	ldr r3, _08006174
	adds r1, r3
	adds r2, r1
	ldrb r1, [r0, 0x4]
	ldrb r0, [r0, 0x5]
	muls r0, r1
	adds r2, r0
	str r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006170: .4byte gUnknown_203B07C
_08006174: .4byte 0x0000d305
	thumb_func_end SeedRng

	thumb_func_start Random16
Random16:
	ldr r2, _08006188
	ldr r1, [r2]
	ldr r0, _0800618C
	muls r0, r1
	adds r0, 0x1
	str r0, [r2]
	asrs r0, 16
	bx lr
	.align 2, 0
_08006188: .4byte gUnknown_203B07C
_0800618C: .4byte 0x5d588b65
	thumb_func_end Random16

	thumb_func_start Random
Random:
	push {r4,lr}
	bl Random16
	adds r4, r0, 0
	lsls r4, 16
	asrs r4, 16
	bl Random16
	lsls r0, 16
	asrs r0, 16
	lsls r4, 16
	orrs r4, r0
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end Random

	thumb_func_start RandomCapped
RandomCapped:
	push {r4,lr}
	adds r4, r0, 0
	bl Random
	ldr r1, _080061C8
	ands r0, r1
	muls r0, r4
	asrs r0, 16
	ands r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080061C8: .4byte 0x0000ffff
	thumb_func_end RandomCapped

	thumb_func_start RandomRange
RandomRange:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r5, r4
	beq _080061EC
	cmp r5, r4
	blt _080061E4
	subs r0, r5, r4
	bl RandomCapped
	adds r0, r4
	b _080061EC
_080061E4:
	subs r0, r4, r5
	bl RandomCapped
	adds r0, r5
_080061EC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end RandomRange

	thumb_func_start GetRngState
GetRngState:
	ldr r0, _080061FC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080061FC: .4byte gUnknown_203B07C
	thumb_func_end GetRngState

	thumb_func_start ReseedRng
ReseedRng:
	push {r4,lr}
	ldr r4, _08006214
	str r0, [r4]
	bl Random
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006214: .4byte gUnknown_203B07C
	thumb_func_end ReseedRng

	thumb_func_start sub_8006218
sub_8006218:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r1, _080062F4
	movs r0, 0
	str r0, [r1]
	ldr r0, _080062F8
	ldr r5, _080062FC
	adds r1, r5, 0
	bl sub_800A9EC
	ldr r4, _08006300
	str r0, [r4]
	ldr r0, _08006304
	adds r1, r5, 0
	bl sub_800A9EC
	str r0, [r4, 0x4]
	ldr r2, _08006308
	ldr r1, [r4]
	ldr r1, [r1, 0x4]
	str r1, [r2]
	ldr r0, [r0, 0x4]
	str r0, [r2, 0x4]
	ldr r1, _0800630C
	movs r0, 0xB
	str r0, [r1]
	movs r0, 0xC
	str r0, [r1, 0x4]
	ldr r0, _08006310
	movs r4, 0
	movs r3, 0
	adds r2, r0, 0
	adds r2, 0x46
	adds r0, 0x4
	movs r1, 0x3
_08006264:
	strh r3, [r0]
	strh r3, [r0, 0x4]
	strb r4, [r2]
	adds r2, 0x48
	adds r0, 0x48
	subs r1, 0x1
	cmp r1, 0
	bge _08006264
	ldr r1, _08006314
	movs r0, 0
	strh r0, [r1]
	movs r3, 0
	ldr r0, _08006318
	mov r9, r0
	ldr r1, _0800631C
	mov r10, r1
	ldr r7, _08006320
	ldr r2, _08006324
	mov r8, r2
	movs r0, 0x80
	lsls r0, 4
	adds r6, r7, r0
	ldr r4, _08006328
	movs r5, 0
	mov r12, r6
_08006296:
	lsls r0, r3, 6
	adds r2, r0, r7
	mov r1, r8
	strh r1, [r2]
	adds r1, r0, r6
	strh r4, [r1]
	adds r3, 0x1
	add r0, r12
	adds r0, 0x2
	adds r2, 0x2
	movs r1, 0x1E
_080062AC:
	strh r5, [r2]
	strh r4, [r0]
	adds r0, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080062AC
	cmp r3, 0x13
	ble _08006296
	movs r1, 0
	movs r0, 0x1
	mov r2, r9
	strb r0, [r2]
	ldr r0, _0800632C
	mov r2, r10
	str r0, [r2]
	ldr r0, _08006330
	str r1, [r0]
	ldr r2, _08006334
	strb r1, [r2]
	movs r0, 0x1
	ldr r1, _08006338
	str r0, [r1]
	movs r0, 0x14
	ldr r2, _0800633C
	str r0, [r2]
	movs r0, 0
	bl xxx_update_some_bg_tiles
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080062F4: .4byte gUnknown_20274AC
_080062F8: .4byte gUnknown_80B87B4
_080062FC: .4byte gUnknown_8300500
_08006300: .4byte gUnknown_202AFB4
_08006304: .4byte gUnknown_80B87BC
_08006308: .4byte gUnknown_2027490
_0800630C: .4byte gUnknown_202B028
_08006310: .4byte gUnknown_2027370
_08006314: .4byte gUnknown_2027498
_08006318: .4byte gUnknown_202B034
_0800631C: .4byte gUnknown_202B030
_08006320: .4byte gUnknown_202B038
_08006324: .4byte 0x0000f279
_08006328: .4byte 0x0000f27a
_0800632C: .4byte 0x88888888
_08006330: .4byte gUnknown_203B078
_08006334: .4byte gUnknown_20274A5
_08006338: .4byte gUnknown_202B020
_0800633C: .4byte gUnknown_202B024
	thumb_func_end sub_8006218

	thumb_func_start xxx_update_some_bg_tiles
xxx_update_some_bg_tiles:
	push {r4,r5,lr}
	adds r1, r0, 0
	ldr r0, _08006360
	ldr r5, [r0]
	ldr r4, _08006364
	str r1, [r0]
	cmp r1, 0
	beq _08006354
	cmp r1, 0x2
	bne _0800636C
_08006354:
	movs r0, 0x2
	bl sub_800CDA8
	ldr r2, _08006368
	b _08006374
	.align 2, 0
_08006360: .4byte gUnknown_20274B0
_08006364: .4byte 0x06004f40
_08006368: .4byte gUnknown_80B87C4
_0800636C:
	movs r0, 0x1
	bl sub_800CDA8
	ldr r2, _080063A4
_08006374:
	ldr r1, _080063A8
	ldr r0, _080063AC
	str r0, [r1]
	ldm r2!, {r0}
	stm r4!, {r0}
	ldm r2!, {r0}
	stm r4!, {r0}
	ldm r2!, {r0}
	stm r4!, {r0}
	ldm r2!, {r0}
	stm r4!, {r0}
	ldm r2!, {r0}
	stm r4!, {r0}
	ldm r2!, {r0}
	stm r4!, {r0}
	ldm r2!, {r0}
	stm r4!, {r0}
	ldr r0, [r2]
	str r0, [r4]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080063A4: .4byte gUnknown_80B87E4
_080063A8: .4byte gUnknown_202B030
_080063AC: .4byte 0x88888888
	thumb_func_end xxx_update_some_bg_tiles

	thumb_func_start sub_80063B0
sub_80063B0:
	ldr r0, _080063B8
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080063B8: .4byte gUnknown_20274B0
	thumb_func_end sub_80063B0

	thumb_func_start sub_80063BC
sub_80063BC:
	ldr r1, _080063C8
	ldrb r2, [r1]
	strb r0, [r1]
	adds r0, r2, 0
	bx lr
	.align 2, 0
_080063C8: .4byte gUnknown_202B034
	thumb_func_end sub_80063BC

	thumb_func_start sub_80063CC
sub_80063CC:
	ldr r1, _080063D4
	str r0, [r1]
	bx lr
	.align 2, 0
_080063D4: .4byte gUnknown_20274AC
	thumb_func_end sub_80063CC

	thumb_func_start sub_80063D8
sub_80063D8:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0
	bne _080063F0
	ldr r0, _080063E8
	ldr r0, [r0]
	ldr r2, _080063EC
	b _08006410
	.align 2, 0
_080063E8: .4byte gUnknown_20274B0
_080063EC: .4byte 0x88888888
_080063F0:
	movs r0, 0xF
	ands r0, r1
	lsls r2, r0, 4
	orrs r2, r0
	lsls r1, r0, 8
	orrs r2, r1
	lsls r1, r0, 12
	orrs r2, r1
	lsls r1, r0, 16
	orrs r2, r1
	lsls r1, r0, 20
	orrs r2, r1
	lsls r1, r0, 24
	orrs r2, r1
	lsls r0, 28
	orrs r2, r0
_08006410:
	ldr r0, _08006418
	str r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08006418: .4byte gUnknown_202B030
	thumb_func_end sub_80063D8

	thumb_func_start sub_800641C
sub_800641C:
	push {lr}
	sub sp, 0x4
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0
	str r3, [sp]
	mov r3, sp
	bl sub_8006438
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_800641C

	thumb_func_start sub_8006438
sub_8006438:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r4, r0, 0
	mov r8, r3
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x2
	mov r9, r0
	cmp r4, 0
	bne _0800645C
	ldr r4, _080064F0
_0800645C:
	cmp r2, 0
	beq _08006464
	bl sub_8009388
_08006464:
	bl sub_800898C
	movs r6, 0
	adds r5, r4, 0
	adds r5, 0xC
	ldr r1, _080064F4
	str r1, [sp, 0x18]
_08006472:
	ldr r0, [sp, 0x18]
	adds r1, r4, 0
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	ldm r1!, {r2,r3,r7}
	stm r0!, {r2,r3,r7}
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080064C4
	ldr r1, _080064F8
	lsls r0, r6, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp]
	str r4, [sp, 0x4]
	mov r2, r10
	str r2, [sp, 0x8]
	mov r3, r9
	str r3, [sp, 0xC]
	mov r7, r8
	str r7, [sp, 0x10]
	movs r0, 0
	str r0, [sp, 0x14]
	ldr r0, _080064FC
	movs r1, 0xC0
	lsls r1, 19
	ldr r2, _08006500
	ldr r3, _08006504
	bl sub_8006554
	adds r0, r4, 0
	mov r1, r8
	bl sub_80089AC
	movs r0, 0
	ldrsh r1, [r5, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	muls r0, r1
	add r9, r0
_080064C4:
	adds r5, 0x18
	adds r4, 0x18
	ldr r3, [sp, 0x18]
	adds r3, 0x18
	str r3, [sp, 0x18]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08006472
	ldr r2, _08006508
	ldr r0, _0800650C
	ldr r1, _08006510
	str r0, [r2]
	movs r0, 0x1
	strb r0, [r1]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080064F0: .4byte gUnknown_80B857C
_080064F4: .4byte gUnknown_202AFC0
_080064F8: .4byte gUnknown_80B8804
_080064FC: .4byte gUnknown_2027370
_08006500: .4byte gUnknown_20274B4
_08006504: .4byte gUnknown_202B038
_08006508: .4byte gUnknown_203B078
_0800650C: .4byte gUnknown_3000E94
_08006510: .4byte gUnknown_20274A5
	thumb_func_end sub_8006438

	thumb_func_start nullsub_152
nullsub_152:
	bx lr
	thumb_func_end nullsub_152

	thumb_func_start sub_8006518
sub_8006518:
	push {r4-r7,lr}
	ldr r4, _0800653C
	adds r2, r0, 0
	movs r3, 0x3
_08006520:
	adds r1, r2, 0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r4, 0x18
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _08006520
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800653C: .4byte gUnknown_202AFC0
	thumb_func_end sub_8006518

	thumb_func_start nullsub_153
nullsub_153:
	bx lr
	thumb_func_end nullsub_153

	thumb_func_start sub_8006544
sub_8006544:
	ldr r1, _08006550
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08006550: .4byte gUnknown_80B8814
	thumb_func_end sub_8006544

	thumb_func_start sub_8006554
sub_8006554:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r0, [sp, 0x4]
	adds r7, r1, 0
	adds r6, r2, 0
	str r3, [sp, 0x8]
	ldr r1, [sp, 0x4C]
	ldr r3, [sp, 0x50]
	ldr r2, [sp, 0x54]
	ldr r0, [sp, 0x58]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xC]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	ldr r1, [sp, 0x44]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 3
	ldr r4, [sp, 0x4]
	adds r5, r4, r0
	ldr r0, [sp, 0x48]
	movs r4, 0x8
	ldrsh r1, [r0, r4]
	movs r4, 0
	ldrsh r0, [r2, r4]
	adds r1, r0
	str r1, [sp, 0x14]
	ldr r0, [sp, 0x48]
	movs r4, 0xA
	ldrsh r1, [r0, r4]
	movs r4, 0x2
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	mov r0, sp
	ldrh r0, [r0, 0x14]
	strh r0, [r5]
	strh r4, [r5, 0x2]
	ldr r1, [sp, 0x48]
	ldrh r0, [r1, 0xC]
	strh r0, [r5, 0x4]
	ldrh r0, [r1, 0x10]
	strh r0, [r5, 0x8]
	ldrh r0, [r1, 0xE]
	strh r0, [r5, 0x6]
	ldr r0, [r1, 0x4]
	str r0, [r5, 0xC]
	str r3, [r5, 0x10]
	cmp r0, 0x6
	bne _080065C6
	str r3, [r5, 0x14]
	b _080065D6
_080065C6:
	ldr r2, [sp, 0x48]
	movs r0, 0x12
	ldrsh r1, [r2, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	muls r0, r1
	adds r0, r3, r0
	str r0, [r5, 0x14]
_080065D6:
	ldr r0, [r5, 0x10]
	lsls r0, 5
	adds r0, r6, r0
	str r0, [r5, 0x18]
	ldr r0, [r5, 0x14]
	lsls r0, 5
	adds r1, r6, r0
	str r1, [r5, 0x1C]
	ldr r3, [sp, 0x48]
	movs r6, 0x12
	ldrsh r1, [r3, r6]
	str r1, [r5, 0x24]
	adds r0, r7, r0
	str r0, [r5, 0x28]
	ldr r3, [r5, 0xC]
	cmp r3, 0x6
	bne _0800660C
	movs r7, 0x4
	ldrsh r2, [r5, r7]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	ldr r6, [sp, 0x48]
	movs r7, 0x12
	ldrsh r1, [r6, r7]
	adds r0, r1
	muls r0, r2
	b _08006616
_0800660C:
	movs r0, 0x4
	ldrsh r1, [r5, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	muls r0, r1
_08006616:
	lsls r0, 5
	str r0, [r5, 0x2C]
	movs r0, 0
	str r0, [r5, 0x30]
	str r0, [r5, 0x34]
	str r0, [r5, 0x38]
	movs r6, 0x4
	ldrsh r0, [r5, r6]
	lsls r0, 3
	subs r0, 0x8
	str r0, [r5, 0x20]
	movs r1, 0
	cmp r3, 0
	bne _08006634
	movs r1, 0x1
_08006634:
	adds r0, r5, 0
	adds r0, 0x45
	strb r1, [r0]
	movs r7, 0x8
	ldrsh r0, [r5, r7]
	cmp r0, 0
	bne _08006644
	b _0800676C
_08006644:
	ldr r0, [sp, 0x48]
	ldrb r1, [r0]
	movs r0, 0xA0
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x46
	str r1, [sp, 0x1C]
	cmp r0, 0x80
	beq _08006752
	subs r7, r4, 0x1
	ldr r0, [r5, 0xC]
	cmp r0, 0x6
	bne _080066A8
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _0800666C
	ldr r6, [r5, 0x14]
	mov r8, r6
_0800666C:
	ldr r0, [sp, 0x48]
	ldr r3, [r0, 0x14]
	ldr r1, [sp, 0x8]
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8006E94
	adds r7, r4, 0x2
	ldr r2, [sp, 0xC]
	cmp r2, 0
	beq _0800669A
	movs r3, 0x4
	ldrsh r1, [r5, r3]
	ldr r4, [sp, 0x48]
	movs r6, 0x12
	ldrsh r0, [r4, r6]
	adds r0, 0x2
	muls r1, r0
	ldr r0, [r5, 0x14]
	adds r0, r1
	b _0800669C
_0800669A:
	movs r0, 0
_0800669C:
	mov r8, r0
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	subs r0, 0x2
	str r0, [sp, 0x18]
	b _080066CA
_080066A8:
	adds r0, r5, 0
	adds r1, r7, 0
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0x10]
	bl sub_800677C
	adds r7, r4, 0
	movs r2, 0
	mov r8, r2
	ldr r3, [sp, 0xC]
	cmp r3, 0
	beq _080066C4
	ldr r4, [r5, 0x14]
	mov r8, r4
_080066C4:
	movs r0, 0x6
	ldrsh r6, [r5, r0]
	str r6, [sp, 0x18]
_080066CA:
	movs r1, 0
	mov r9, r1
	adds r2, r5, 0
	adds r2, 0x46
	str r2, [sp, 0x1C]
	ldr r3, [sp, 0x18]
	cmp r9, r3
	bge _08006746
_080066DA:
	ldr r4, [sp, 0x14]
	subs r4, 0x1
	ldr r6, [sp, 0x8]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r9
	bl sub_80069CC
	ldr r4, [sp, 0x14]
	movs r6, 0
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	adds r2, r7, 0x1
	mov r10, r2
	mov r3, r9
	adds r3, 0x1
	str r3, [sp, 0x20]
	cmp r6, r0
	bge _0800672A
_08006704:
	ldr r0, [sp, 0x8]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_8006AC4
	adds r4, 0x1
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _08006720
	movs r2, 0x1
	add r8, r2
_08006720:
	adds r6, 0x1
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	cmp r6, r0
	blt _08006704
_0800672A:
	ldr r6, [sp, 0x8]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r9
	bl sub_8006B70
	mov r7, r10
	ldr r0, [sp, 0x20]
	mov r9, r0
	ldr r1, [sp, 0x18]
	cmp r9, r1
	blt _080066DA
_08006746:
	adds r0, r5, 0
	adds r1, r7, 0
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0x10]
	bl sub_8006C44
_08006752:
	ldr r2, [sp, 0x48]
	ldrb r1, [r2]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08006766
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	bl sub_8008C6C
_08006766:
	movs r0, 0
	ldr r3, [sp, 0x1C]
	strb r0, [r3]
_0800676C:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8006554

	thumb_func_start sub_800677C
sub_800677C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r1, 0
	ldrsh r0, [r6, r1]
	subs r3, r0, 0x1
	cmp r4, 0x1C
	ble _080067A0
	b _080069AE
_080067A0:
	cmp r4, 0
	bge _080067A6
	b _080069AE
_080067A6:
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bls _080067AE
	b _080069AE
_080067AE:
	lsls r0, 2
	ldr r1, _080067B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080067B8: .4byte _080067BC
	.align 2, 0
_080067BC:
	.4byte _080069AE
	.4byte _080069AE
	.4byte _080069AE
	.4byte _080067DC
	.4byte _0800689C
	.4byte _08006920
	.4byte _080069AE
	.4byte _0800696C
_080067DC:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r0, r2, r4
	adds r1, r0
	ldr r7, _08006800
	adds r0, r7, 0
	strh r0, [r1]
	adds r5, r2, 0
	mov r0, r9
	cmp r0, 0
	beq _08006808
	movs r2, 0x80
	lsls r2, 4
	adds r1, r2
	ldr r4, _08006804
	adds r0, r4, 0
	b _08006812
	.align 2, 0
_08006800: .4byte 0x0000f2d8
_08006804: .4byte 0x0000f293
_08006808:
	movs r7, 0x80
	lsls r7, 4
	adds r1, r7
	ldr r2, _08006878
	adds r0, r2, 0
_08006812:
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r4, r0
	bge _08006856
	ldr r0, _0800687C
	mov r8, r0
	lsls r0, r3, 1
	ldr r2, [sp]
	movs r7, 0x80
	lsls r7, 4
	adds r1, r2, r7
	adds r1, r5, r1
	adds r2, r0, r1
	ldr r7, [sp]
	adds r1, r5, r7
	adds r1, r0, r1
	ldr r0, _08006878
	mov r12, r0
_0800683C:
	mov r7, r8
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r10, r7
	cmp r4, r10
	blt _0800683C
_08006856:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r1, r0, r1
	ldr r4, _08006880
	adds r0, r4, 0
	strh r0, [r1]
	mov r7, r9
	cmp r7, 0
	beq _08006888
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006884
	adds r0, r2, 0
	strh r0, [r1]
	b _080069AE
	.align 2, 0
_08006878: .4byte 0x0000f2db
_0800687C: .4byte 0x0000f2d9
_08006880: .4byte 0x0000f6d8
_08006884: .4byte 0x0000f693
_08006888:
	movs r4, 0x80
	lsls r4, 4
	adds r1, r4
	ldr r7, _08006898
	adds r0, r7, 0
	strh r0, [r1]
	b _080069AE
	.align 2, 0
_08006898: .4byte 0x0000f2db
_0800689C:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r0, [sp]
	adds r0, r2
	mov r12, r0
	add r1, r12
	ldr r4, _08006910
	adds r0, r4, 0
	strh r0, [r1]
	movs r7, 0x80
	lsls r7, 4
	mov r8, r7
	add r1, r8
	ldr r0, _08006914
	mov r9, r0
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r4, r0
	bge _080068F6
	ldr r2, _08006918
	mov r10, r2
	lsls r1, r3, 1
	ldr r0, [sp]
	add r0, r8
	adds r0, r5, r0
	adds r2, r1, r0
	add r1, r12
	mov r12, r9
_080068DC:
	mov r7, r10
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r8, r7
	cmp r4, r8
	blt _080068DC
_080068F6:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r0, r1
	ldr r4, _0800691C
	adds r1, r4, 0
	strh r1, [r0]
	movs r7, 0x80
	lsls r7, 4
	adds r0, r7
	ldr r2, _08006914
	adds r1, r2, 0
	b _080069AC
	.align 2, 0
_08006910: .4byte 0x0000f2e8
_08006914: .4byte 0x0000f2db
_08006918: .4byte 0x0000f2e9
_0800691C: .4byte 0x0000f6e8
_08006920:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r4, r2
	mov r12, r4
	add r0, r12
	ldr r7, _08006960
	adds r1, r7, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r0, 0
	ble _08006954
	ldr r2, _08006964
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006948:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006948
_08006954:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _08006968
	b _080069AA
	.align 2, 0
_08006960: .4byte 0x0000f2dc
_08006964: .4byte 0x0000f2dd
_08006968: .4byte 0x0000f6dc
_0800696C:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r1, [sp]
	adds r1, r2
	mov r12, r1
	add r0, r12
	ldr r4, _080069C0
	adds r1, r4, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	adds r5, r2, 0
	cmp r0, 0
	ble _080069A0
	ldr r2, _080069C4
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006994:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006994
_080069A0:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _080069C8
_080069AA:
	adds r1, r7, 0
_080069AC:
	strh r1, [r0]
_080069AE:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080069C0: .4byte 0x0000f293
_080069C4: .4byte 0x0000f297
_080069C8: .4byte 0x0000f693
	thumb_func_end sub_800677C

	thumb_func_start sub_80069CC
sub_80069CC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [sp, 0x10]
	cmp r2, 0x1C
	bgt _08006ABA
	cmp r2, 0
	blt _08006ABA
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bhi _08006ABA
	lsls r0, 2
	ldr r1, _080069F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080069F0: .4byte _080069F4
	.align 2, 0
_080069F4:
	.4byte _08006A14
	.4byte _08006ABA
	.4byte _08006ABA
	.4byte _08006A60
	.4byte _08006A7C
	.4byte _08006A9C
	.4byte _08006A60
	.4byte _08006AAC
_08006A14:
	cmp r5, 0
	bne _08006A34
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A30
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	adds r2, 0x44
	b _08006A92
	.align 2, 0
_08006A30: .4byte 0x0000f297
_08006A34:
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	cmp r5, r0
	bne _08006A60
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A58
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006A5C
	b _08006A92
	.align 2, 0
_08006A58: .4byte 0x0000fa97
_08006A5C: .4byte 0x0000f2db
_08006A60:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A78
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	adds r2, 0x1
	b _08006A92
	.align 2, 0
_08006A78: .4byte 0x0000f2da
_08006A7C:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006A98
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	subs r2, 0xF
_08006A92:
	adds r0, r2, 0
	strh r0, [r1]
	b _08006ABA
	.align 2, 0
_08006A98: .4byte 0x0000f2ea
_08006A9C:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006AA8
	b _08006AB6
	.align 2, 0
_08006AA8: .4byte 0x0000f2de
_08006AAC:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006AC0
_08006AB6:
	adds r1, r2, 0
	strh r1, [r0]
_08006ABA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08006AC0: .4byte 0x0000f2b6
	thumb_func_end sub_80069CC

	thumb_func_start sub_8006AC4
sub_8006AC4:
	push {r4,r5,lr}
	adds r4, r1, 0
	ldr r5, [sp, 0xC]
	cmp r2, 0x1C
	bgt _08006B64
	cmp r2, 0
	blt _08006B64
	ldr r0, [r0, 0xC]
	cmp r0, 0x7
	bhi _08006B64
	lsls r0, 2
	ldr r1, _08006AE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006AE4: .4byte _08006AE8
	.align 2, 0
_08006AE8:
	.4byte _08006B2C
	.4byte _08006B2C
	.4byte _08006B08
	.4byte _08006B2C
	.4byte _08006B2C
	.4byte _08006B54
	.4byte _08006B2C
	.4byte _08006B54
_08006B08:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r5
	adds r1, r0
	ldr r2, _08006B24
	adds r0, r2, 0
	orrs r3, r0
	strh r3, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006B28
	b _08006B44
	.align 2, 0
_08006B24: .4byte 0xfffff000
_08006B28: .4byte 0x0000f278
_08006B2C:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r5
	adds r1, r0
	ldr r2, _08006B4C
	adds r0, r2, 0
	orrs r3, r0
	strh r3, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006B50
_08006B44:
	adds r0, r2, 0
	strh r0, [r1]
	b _08006B64
	.align 2, 0
_08006B4C: .4byte 0xfffff000
_08006B50: .4byte 0x0000f2db
_08006B54:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r5
	adds r0, r1
	ldr r2, _08006B6C
	adds r1, r2, 0
	orrs r3, r1
	strh r3, [r0]
_08006B64:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08006B6C: .4byte 0xfffff000
	thumb_func_end sub_8006AC4

	thumb_func_start sub_8006B70
sub_8006B70:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r3, 0
	ldr r3, [sp, 0x10]
	cmp r2, 0x1C
	bgt _08006C3A
	cmp r2, 0
	blt _08006C3A
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bhi _08006C3A
	lsls r0, 2
	ldr r1, _08006B94
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006B94: .4byte _08006B98
	.align 2, 0
_08006B98:
	.4byte _08006BB8
	.4byte _08006C3A
	.4byte _08006C3A
	.4byte _08006BE8
	.4byte _08006BF8
	.4byte _08006C1C
	.4byte _08006BE8
	.4byte _08006C2C
_08006BB8:
	cmp r5, 0
	bne _08006BCC
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006BC8
	b _08006C02
	.align 2, 0
_08006BC8: .4byte 0x0000f697
_08006BCC:
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	cmp r5, r0
	bne _08006BE8
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006BE4
	b _08006C02
	.align 2, 0
_08006BE4: .4byte 0x0000fe97
_08006BE8:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006BF4
	b _08006C02
	.align 2, 0
_08006BF4: .4byte 0x0000f6da
_08006BF8:
	lsls r1, r4, 1
	lsls r0, r2, 6
	adds r0, r3
	adds r1, r0
	ldr r2, _08006C14
_08006C02:
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006C18
	adds r0, r2, 0
	strh r0, [r1]
	b _08006C3A
	.align 2, 0
_08006C14: .4byte 0x0000f6ea
_08006C18: .4byte 0x0000f2db
_08006C1C:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006C28
	b _08006C36
	.align 2, 0
_08006C28: .4byte 0x0000f6de
_08006C2C:
	lsls r0, r4, 1
	lsls r1, r2, 6
	adds r1, r3
	adds r0, r1
	ldr r2, _08006C40
_08006C36:
	adds r1, r2, 0
	strh r1, [r0]
_08006C3A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08006C40: .4byte 0x0000f6b6
	thumb_func_end sub_8006B70

	thumb_func_start sub_8006C44
sub_8006C44:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	movs r1, 0
	ldrsh r0, [r6, r1]
	subs r3, r0, 0x1
	cmp r4, 0x1C
	ble _08006C68
	b _08006E76
_08006C68:
	cmp r4, 0
	bge _08006C6E
	b _08006E76
_08006C6E:
	ldr r0, [r6, 0xC]
	cmp r0, 0x7
	bls _08006C76
	b _08006E76
_08006C76:
	lsls r0, 2
	ldr r1, _08006C80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006C80: .4byte _08006C84
	.align 2, 0
_08006C84:
	.4byte _08006E76
	.4byte _08006E76
	.4byte _08006E76
	.4byte _08006CA4
	.4byte _08006D64
	.4byte _08006DE8
	.4byte _08006CA4
	.4byte _08006E34
_08006CA4:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r0, r2, r4
	adds r1, r0
	ldr r7, _08006CC8
	adds r0, r7, 0
	strh r0, [r1]
	adds r5, r2, 0
	mov r0, r9
	cmp r0, 0
	beq _08006CD0
	movs r2, 0x80
	lsls r2, 4
	adds r1, r2
	ldr r4, _08006CCC
	adds r0, r4, 0
	b _08006CDA
	.align 2, 0
_08006CC8: .4byte 0x0000fad8
_08006CCC: .4byte 0x0000fa93
_08006CD0:
	movs r7, 0x80
	lsls r7, 4
	adds r1, r7
	ldr r2, _08006D40
	adds r0, r2, 0
_08006CDA:
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r4, r0
	bge _08006D1E
	ldr r0, _08006D44
	mov r8, r0
	lsls r0, r3, 1
	ldr r2, [sp]
	movs r7, 0x80
	lsls r7, 4
	adds r1, r2, r7
	adds r1, r5, r1
	adds r2, r0, r1
	ldr r7, [sp]
	adds r1, r5, r7
	adds r1, r0, r1
	ldr r0, _08006D40
	mov r12, r0
_08006D04:
	mov r7, r8
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r10, r7
	cmp r4, r10
	blt _08006D04
_08006D1E:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r1, r0, r1
	ldr r4, _08006D48
	adds r0, r4, 0
	strh r0, [r1]
	mov r7, r9
	cmp r7, 0
	beq _08006D50
	movs r0, 0x80
	lsls r0, 4
	adds r1, r0
	ldr r2, _08006D4C
	adds r0, r2, 0
	strh r0, [r1]
	b _08006E76
	.align 2, 0
_08006D40: .4byte 0x0000f2db
_08006D44: .4byte 0x0000fad9
_08006D48: .4byte 0x0000fed8
_08006D4C: .4byte 0x0000fe93
_08006D50:
	movs r4, 0x80
	lsls r4, 4
	adds r1, r4
	ldr r7, _08006D60
	adds r0, r7, 0
	strh r0, [r1]
	b _08006E76
	.align 2, 0
_08006D60: .4byte 0x0000f2db
_08006D64:
	lsls r1, r3, 1
	lsls r2, r4, 6
	ldr r0, [sp]
	adds r0, r2
	mov r12, r0
	add r1, r12
	ldr r4, _08006DD8
	adds r0, r4, 0
	strh r0, [r1]
	movs r7, 0x80
	lsls r7, 4
	mov r8, r7
	add r1, r8
	ldr r0, _08006DDC
	mov r9, r0
	strh r0, [r1]
	adds r3, 0x1
	movs r4, 0
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r4, r0
	bge _08006DBE
	ldr r2, _08006DE0
	mov r10, r2
	lsls r1, r3, 1
	ldr r0, [sp]
	add r0, r8
	adds r0, r5, r0
	adds r2, r1, r0
	add r1, r12
	mov r12, r9
_08006DA4:
	mov r7, r10
	strh r7, [r1]
	mov r0, r12
	strh r0, [r2]
	adds r2, 0x2
	adds r1, 0x2
	adds r3, 0x1
	adds r4, 0x1
	movs r0, 0x4
	ldrsh r7, [r6, r0]
	mov r8, r7
	cmp r4, r8
	blt _08006DA4
_08006DBE:
	lsls r0, r3, 1
	ldr r2, [sp]
	adds r1, r5, r2
	adds r0, r1
	ldr r4, _08006DE4
	adds r1, r4, 0
	strh r1, [r0]
	movs r7, 0x80
	lsls r7, 4
	adds r0, r7
	ldr r2, _08006DDC
	adds r1, r2, 0
	b _08006E74
	.align 2, 0
_08006DD8: .4byte 0x0000fae8
_08006DDC: .4byte 0x0000f2db
_08006DE0: .4byte 0x0000fae9
_08006DE4: .4byte 0x0000fee8
_08006DE8:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r4, [sp]
	adds r4, r2
	mov r12, r4
	add r0, r12
	ldr r7, _08006E28
	adds r1, r7, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r5, r2, 0
	cmp r0, 0
	ble _08006E1C
	ldr r2, _08006E2C
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006E10:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006E10
_08006E1C:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _08006E30
	b _08006E72
	.align 2, 0
_08006E28: .4byte 0x0000fadc
_08006E2C: .4byte 0x0000fadd
_08006E30: .4byte 0x0000fedc
_08006E34:
	lsls r0, r3, 1
	lsls r2, r4, 6
	ldr r1, [sp]
	adds r1, r2
	mov r12, r1
	add r0, r12
	ldr r4, _08006E88
	adds r1, r4, 0
	strh r1, [r0]
	adds r3, 0x1
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	adds r5, r2, 0
	cmp r0, 0
	ble _08006E68
	ldr r2, _08006E8C
	adds r1, r2, 0
	adds r4, r0, 0
	lsls r0, r3, 1
	add r0, r12
_08006E5C:
	strh r1, [r0]
	adds r0, 0x2
	adds r3, 0x1
	subs r4, 0x1
	cmp r4, 0
	bne _08006E5C
_08006E68:
	lsls r0, r3, 1
	ldr r4, [sp]
	adds r1, r5, r4
	adds r0, r1
	ldr r7, _08006E90
_08006E72:
	adds r1, r7, 0
_08006E74:
	strh r1, [r0]
_08006E76:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006E88: .4byte 0x0000fa93
_08006E8C: .4byte 0x0000fa97
_08006E90: .4byte 0x0000fe93
	thumb_func_end sub_8006C44

	thumb_func_start sub_8006E94
sub_8006E94:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp]
	adds r4, r1, 0
	adds r7, r2, 0
	str r3, [sp, 0x4]
	movs r1, 0
	ldrsh r0, [r0, r1]
	mov r10, r0
	movs r2, 0x1
	negs r2, r2
	add r2, r10
	movs r3, 0
	str r3, [sp, 0x8]
	cmp r4, 0x1C
	ble _08006EBE
	b _080072FE
_08006EBE:
	cmp r4, 0
	bge _08006EC4
	b _080072FE
_08006EC4:
	lsls r1, r2, 1
	lsls r4, 6
	ldr r6, [sp, 0x50]
	adds r5, r4, r6
	adds r1, r5
	ldr r0, _08006F9C
	adds r3, r0, 0
	strh r3, [r1]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r1, r2
	ldr r6, _08006FA0
	adds r2, r6, 0
	strh r2, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	strh r3, [r0]
	movs r0, 0x84
	lsls r0, 4
	adds r0, r1, r0
	strh r2, [r0]
	adds r2, r1, 0
	adds r2, 0x80
	ldr r3, _08006FA4
	adds r0, r3, 0
	strh r0, [r2]
	movs r6, 0x88
	lsls r6, 4
	adds r1, r6
	ldr r2, _08006FA8
	adds r0, r2, 0
	strh r0, [r1]
	mov r12, r10
	movs r3, 0
	str r4, [sp, 0x18]
	ldr r4, [sp, 0x4]
	ldrb r4, [r4]
	cmp r3, r4
	blt _08006F14
	b _08007238
_08006F14:
	adds r2, r5, 0
	mov r5, r12
	lsls r1, r5, 1
	ldr r0, [sp, 0x50]
	adds r0, 0x80
	ldr r6, [sp, 0x18]
	adds r0, r6, r0
	adds r0, r1
	mov r9, r0
	ldr r0, [sp, 0x50]
	adds r0, 0x40
	adds r0, r6, r0
	adds r0, r1
	mov r8, r0
	ldr r4, [sp, 0x50]
	movs r5, 0x80
	lsls r5, 4
	adds r0, r4, r5
	adds r0, r6, r0
	adds r0, r1, r0
	str r0, [sp, 0x20]
	movs r6, 0x84
	lsls r6, 4
	adds r0, r4, r6
	ldr r4, [sp, 0x18]
	adds r0, r4, r0
	adds r0, r1
	mov r10, r0
	adds r4, r1, r2
	ldr r5, [sp, 0x18]
	str r5, [sp, 0x10]
	str r2, [sp, 0x1C]
	str r1, [sp, 0x24]
_08006F56:
	ldr r6, [sp, 0x4]
	ldrb r6, [r6, 0x1]
	cmp r3, r6
	bne _08006F60
	b _080070C8
_08006F60:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bne _08007008
	ldr r1, [sp, 0x4]
	ldrb r0, [r1, 0x3]
	asrs r0, r3
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08006FB8
	movs r1, 0x1F
	cmp r3, 0
	bne _08006F7C
	movs r1, 0x1B
_08006F7C:
	movs r2, 0x9E
	lsls r2, 2
	adds r0, r1, r2
	ldr r5, _08006FAC
	adds r1, r5, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r6, _08006FB0
	adds r0, r6, 0
	mov r1, r8
	strh r0, [r1]
	ldr r5, _08006FB4
	mov r2, r9
	strh r5, [r2]
	b _08006FDC
	.align 2, 0
_08006F9C: .4byte 0x0000f278
_08006FA0: .4byte 0x0000f27a
_08006FA4: .4byte 0x0000f2d8
_08006FA8: .4byte 0x0000f2db
_08006FAC: .4byte 0xfffff400
_08006FB0: .4byte 0x0000f2b6
_08006FB4: .4byte 0x0000f2d9
_08006FB8:
	movs r1, 0x6B
	cmp r3, 0
	bne _08006FC0
	movs r1, 0x67
_08006FC0:
	movs r6, 0x9E
	lsls r6, 2
	adds r0, r1, r6
	ldr r2, _08006FF4
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r5, _08006FF8
	adds r0, r5, 0
	mov r6, r8
	strh r0, [r6]
	ldr r1, _08006FFC
	mov r0, r9
	strh r1, [r0]
_08006FDC:
	ldr r2, _08007000
	adds r0, r2, 0
	ldr r5, [sp, 0x20]
	strh r0, [r5]
	ldr r0, _08007004
	mov r6, r10
	strh r0, [r6]
	movs r1, 0x88
	lsls r1, 4
	adds r0, r4, r1
	adds r2, 0x61
	b _0800708E
	.align 2, 0
_08006FF4: .4byte 0xfffff400
_08006FF8: .4byte 0x0000f2ef
_08006FFC: .4byte 0x0000f2d9
_08007000: .4byte 0x0000f27a
_08007004: .4byte 0x0000f2db
_08007008:
	ldr r5, [sp, 0x4]
	ldrb r0, [r5, 0x3]
	asrs r0, r3
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0800704C
	ldrb r0, [r5]
	subs r0, 0x1
	movs r1, 0x1F
	cmp r3, r0
	bne _08007022
	movs r1, 0x1B
_08007022:
	movs r6, 0x9E
	lsls r6, 2
	adds r0, r1, r6
	ldr r2, _08007040
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r5, _08007044
	adds r0, r5, 0
	mov r6, r8
	strh r0, [r6]
	ldr r1, _08007048
	mov r0, r9
	strh r1, [r0]
	b _08007076
	.align 2, 0
_08007040: .4byte 0xfffff000
_08007044: .4byte 0x0000f6b6
_08007048: .4byte 0x0000f2d9
_0800704C:
	ldr r2, [sp, 0x4]
	ldrb r0, [r2]
	subs r0, 0x1
	movs r1, 0x6B
	cmp r3, r0
	bne _0800705A
	movs r1, 0x67
_0800705A:
	movs r5, 0x9E
	lsls r5, 2
	adds r0, r1, r5
	ldr r6, _080070B0
	adds r1, r6, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _080070B4
	adds r0, r1, 0
	mov r2, r8
	strh r0, [r2]
	ldr r6, _080070B8
	mov r5, r9
	strh r6, [r5]
_08007076:
	ldr r1, _080070BC
	adds r0, r1, 0
	ldr r2, [sp, 0x20]
	strh r0, [r2]
	ldr r5, _080070C0
	adds r0, r5, 0
	mov r6, r10
	strh r0, [r6]
	movs r1, 0x88
	lsls r1, 4
	adds r0, r4, r1
	ldr r2, _080070C4
_0800708E:
	strh r2, [r0]
	movs r5, 0x2
	add r9, r5
	add r8, r5
	ldr r6, [sp, 0x20]
	adds r6, 0x2
	str r6, [sp, 0x20]
	add r10, r5
	adds r4, 0x2
	ldr r0, [sp, 0x24]
	adds r0, 0x2
	str r0, [sp, 0x24]
	movs r1, 0x1
	add r12, r1
	adds r3, 0x1
	str r3, [sp, 0x14]
	b _08007226
	.align 2, 0
_080070B0: .4byte 0xfffff000
_080070B4: .4byte 0x0000f6ef
_080070B8: .4byte 0x0000f2d9
_080070BC: .4byte 0x0000f27a
_080070C0: .4byte 0x0000f6db
_080070C4: .4byte 0x0000f2db
_080070C8:
	movs r2, 0x1
	str r2, [sp, 0x8]
	ldr r5, _08007128
	adds r0, r5, 0
	strh r0, [r4]
	ldr r6, _0800712C
	adds r0, r6, 0
	ldr r1, [sp, 0x20]
	strh r0, [r1]
	ldr r2, _08007130
	adds r0, r2, 0
	mov r5, r8
	strh r0, [r5]
	ldr r0, _08007134
	mov r6, r10
	strh r0, [r6]
	ldr r1, _08007138
	adds r0, r1, 0
	mov r2, r9
	strh r0, [r2]
	movs r5, 0x88
	lsls r5, 4
	adds r0, r4, r5
	ldr r6, _08007134
	strh r6, [r0]
	movs r0, 0x2
	add r9, r0
	add r8, r0
	ldr r1, [sp, 0x20]
	adds r1, 0x2
	str r1, [sp, 0x20]
	add r10, r0
	adds r4, 0x2
	ldr r2, [sp, 0x24]
	adds r2, 0x2
	str r2, [sp, 0x24]
	movs r5, 0x1
	add r12, r5
	cmp r7, 0
	beq _0800713C
	adds r7, 0x1
	cmp r7, 0
	beq _0800713C
	ldr r6, [sp]
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r2, r7, r0
	b _0800713E
	.align 2, 0
_08007128: .4byte 0x0000f2e0
_0800712C: .4byte 0x0000f2e2
_08007130: .4byte 0x0000f2da
_08007134: .4byte 0x0000f2db
_08007138: .4byte 0x0000f6e7
_0800713C:
	movs r2, 0
_0800713E:
	movs r5, 0
	str r5, [sp, 0xC]
	adds r3, 0x1
	str r3, [sp, 0x14]
	ldr r6, [sp, 0x4]
	ldrb r6, [r6, 0x2]
	cmp r5, r6
	bge _080071E0
	ldr r0, [sp, 0x50]
	adds r0, 0x80
	ldr r1, [sp, 0x10]
	adds r0, r1, r0
	ldr r3, [sp, 0x24]
	adds r0, r3, r0
	str r0, [sp, 0x2C]
	ldr r0, [sp, 0x50]
	adds r0, 0x40
	adds r0, r1, r0
	adds r5, r3, r0
	ldr r6, [sp, 0x1C]
	adds r3, r6
_08007168:
	ldr r1, _08007310
	adds r0, r1, 0
	strh r0, [r3]
	movs r6, 0x80
	lsls r6, 4
	adds r6, r3, r6
	str r6, [sp, 0x28]
	adds r1, 0x1
	adds r0, r1, 0
	strh r0, [r6]
	adds r0, r7, 0
	ldr r6, _08007314
	orrs r0, r6
	strh r0, [r5]
	movs r1, 0x84
	lsls r1, 4
	adds r0, r3, r1
	ldr r6, _08007318
	strh r6, [r0]
	adds r0, r2, 0
	ldr r1, _08007314
	orrs r0, r1
	ldr r6, [sp, 0x2C]
	strh r0, [r6]
	movs r1, 0x88
	lsls r1, 4
	adds r0, r3, r1
	ldr r6, _08007318
	strh r6, [r0]
	ldr r0, [sp, 0x2C]
	adds r0, 0x2
	str r0, [sp, 0x2C]
	adds r5, 0x2
	adds r3, 0x2
	movs r1, 0x2
	add r9, r1
	add r8, r1
	ldr r6, [sp, 0x20]
	adds r6, 0x2
	str r6, [sp, 0x20]
	add r10, r1
	adds r4, 0x2
	ldr r0, [sp, 0x24]
	adds r0, 0x2
	str r0, [sp, 0x24]
	movs r1, 0x1
	add r12, r1
	cmp r7, 0
	beq _080071CC
	adds r7, 0x1
_080071CC:
	cmp r2, 0
	beq _080071D2
	adds r2, 0x1
_080071D2:
	ldr r6, [sp, 0xC]
	adds r6, 0x1
	str r6, [sp, 0xC]
	ldr r0, [sp, 0x4]
	ldrb r0, [r0, 0x2]
	cmp r6, r0
	blt _08007168
_080071E0:
	ldr r1, _0800731C
	adds r0, r1, 0
	strh r0, [r4]
	ldr r2, _08007320
	adds r0, r2, 0
	ldr r3, [sp, 0x20]
	strh r0, [r3]
	ldr r5, _08007324
	adds r0, r5, 0
	mov r6, r8
	strh r0, [r6]
	ldr r1, _08007318
	mov r0, r10
	strh r1, [r0]
	adds r2, 0x5
	adds r0, r2, 0
	mov r3, r9
	strh r0, [r3]
	movs r5, 0x88
	lsls r5, 4
	adds r0, r4, r5
	strh r1, [r0]
	movs r6, 0x2
	add r9, r6
	add r8, r6
	ldr r0, [sp, 0x20]
	adds r0, 0x2
	str r0, [sp, 0x20]
	add r10, r6
	adds r4, 0x2
	ldr r1, [sp, 0x24]
	adds r1, 0x2
	str r1, [sp, 0x24]
	movs r2, 0x1
	add r12, r2
_08007226:
	cmp r7, 0
	beq _0800722C
	adds r7, 0x1
_0800722C:
	ldr r3, [sp, 0x14]
	ldr r5, [sp, 0x4]
	ldrb r5, [r5]
	cmp r3, r5
	bge _08007238
	b _08006F56
_08007238:
	ldr r6, [sp]
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	adds r0, r1, r0
	cmp r12, r0
	bge _080072BC
	ldr r3, _08007328
	adds r4, r3, 0
	mov r8, r0
	mov r5, r12
	lsls r1, r5, 1
	ldr r0, [sp, 0x50]
	adds r0, 0x80
	ldr r6, [sp, 0x18]
	adds r0, r6, r0
	adds r5, r1, r0
	ldr r0, [sp, 0x50]
	adds r0, 0x40
	adds r0, r6, r0
	adds r3, r1, r0
	ldr r0, [sp, 0x50]
	adds r6, r0
	adds r2, r1, r6
	movs r1, 0x80
	lsls r1, 4
	mov r10, r1
	movs r6, 0x84
	lsls r6, 4
	mov r9, r6
	mov r0, r8
	mov r1, r12
	subs r0, r1
	mov r12, r0
_0800727E:
	strh r4, [r2]
	mov r6, r10
	adds r0, r2, r6
	ldr r1, _0800732C
	strh r1, [r0]
	strh r4, [r3]
	mov r6, r9
	adds r0, r2, r6
	strh r1, [r0]
	adds r1, 0x5F
	adds r0, r1, 0
	strh r0, [r5]
	movs r6, 0x88
	lsls r6, 4
	adds r1, r2, r6
	ldr r6, _08007318
	adds r0, r6, 0
	strh r0, [r1]
	adds r5, 0x2
	adds r3, 0x2
	adds r2, 0x2
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	cmp r7, 0
	beq _080072B4
	adds r7, 0x1
_080072B4:
	mov r1, r12
	cmp r1, 0
	bne _0800727E
	mov r12, r8
_080072BC:
	mov r2, r12
	lsls r1, r2, 1
	ldr r3, [sp, 0x18]
	ldr r4, [sp, 0x50]
	adds r0, r3, r4
	adds r1, r0
	ldr r5, _08007328
	adds r3, r5, 0
	strh r3, [r1]
	movs r6, 0x80
	lsls r6, 4
	adds r0, r1, r6
	ldr r4, _0800732C
	adds r2, r4, 0
	strh r2, [r0]
	adds r0, r1, 0
	adds r0, 0x40
	strh r3, [r0]
	movs r5, 0x84
	lsls r5, 4
	adds r0, r1, r5
	strh r2, [r0]
	adds r2, r1, 0
	adds r2, 0x80
	ldr r6, _08007330
	adds r0, r6, 0
	strh r0, [r2]
	movs r0, 0x88
	lsls r0, 4
	adds r1, r0
	ldr r2, _08007318
	adds r0, r2, 0
	strh r0, [r1]
_080072FE:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007310: .4byte 0x0000f2e1
_08007314: .4byte 0xfffff000
_08007318: .4byte 0x0000f2db
_0800731C: .4byte 0x0000f6e0
_08007320: .4byte 0x0000f2e2
_08007324: .4byte 0x0000f6da
_08007328: .4byte 0x0000f278
_0800732C: .4byte 0x0000f27a
_08007330: .4byte 0x0000f6d8
	thumb_func_end sub_8006E94

	thumb_func_start sub_8007334
sub_8007334:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _080073AC
	adds r3, r1, r0
	ldr r5, [r3, 0x14]
	movs r0, 0x2
	ldrsh r6, [r3, r0]
	movs r2, 0
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bge _080073A0
	ldr r7, _080073B0
	mov r9, r7
_0800735A:
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r4, 0
	movs r7, 0x4
	ldrsh r0, [r3, r7]
	adds r7, r6, 0x1
	adds r2, 0x1
	mov r12, r2
	cmp r4, r0
	bge _08007394
	movs r0, 0xFC
	lsls r0, 8
	mov r8, r0
	lsls r1, 1
	lsls r0, r6, 6
	add r0, r9
	adds r2, r1, r0
_0800737C:
	ldrh r0, [r2]
	mov r1, r8
	ands r1, r0
	orrs r1, r5
	strh r1, [r2]
	adds r2, 0x2
	adds r5, 0x1
	adds r4, 0x1
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	cmp r4, r0
	blt _0800737C
_08007394:
	adds r6, r7, 0
	mov r2, r12
	movs r7, 0x6
	ldrsh r0, [r3, r7]
	cmp r2, r0
	blt _0800735A
_080073A0:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080073AC: .4byte gUnknown_2027370
_080073B0: .4byte gUnknown_202B038
	thumb_func_end sub_8007334

	thumb_func_start nullsub_154
nullsub_154:
	bx lr
	thumb_func_end nullsub_154

	thumb_func_start sub_80073B8
sub_80073B8:
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _080073D8
	adds r1, r0
	ldr r0, [r1, 0x2C]
	lsrs r0, 2
	lsls r0, 2
	ldr r2, [r1, 0x1C]
	adds r0, r2, r0
	str r0, [r1, 0x3C]
	str r2, [r1, 0x40]
	adds r1, 0x46
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_080073D8: .4byte gUnknown_2027370
	thumb_func_end sub_80073B8

	thumb_func_start nullsub_155
nullsub_155:
	bx lr
	thumb_func_end nullsub_155

	thumb_func_start sub_80073E0
sub_80073E0:
	push {r4,lr}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08007434
	adds r3, r1, r0
	adds r0, r3, 0
	adds r0, 0x44
	ldrb r4, [r0]
	cmp r4, 0
	bne _08007424
	ldr r2, [r3, 0x3C]
	ldr r0, [r3, 0x1C]
	subs r0, r2, r0
	asrs r0, 2
	lsls r0, 2
	ldr r1, [r3, 0x28]
	adds r1, r0
	str r1, [r3, 0x30]
	str r2, [r3, 0x34]
	ldr r0, [r3, 0x40]
	subs r0, r2
	asrs r0, 2
	adds r0, 0x1
	lsls r0, 2
	str r0, [r3, 0x38]
	ldr r1, [r3, 0x2C]
	cmp r0, r1
	blt _0800741C
	str r1, [r3, 0x38]
_0800741C:
	ldr r0, [r3, 0x38]
	cmp r0, 0
	bge _08007424
	str r4, [r3, 0x38]
_08007424:
	adds r1, r3, 0
	adds r1, 0x46
	movs r0, 0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08007434: .4byte gUnknown_2027370
	thumb_func_end sub_80073E0

	thumb_func_start nullsub_156
nullsub_156:
	bx lr
	thumb_func_end nullsub_156

	thumb_func_start sub_800743C
sub_800743C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007460
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_char
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007460: .4byte gUnknown_2027370
	thumb_func_end sub_800743C

	thumb_func_start sub_8007464
sub_8007464:
	movs r0, 0
	bx lr
	thumb_func_end sub_8007464

	thumb_func_start xxx_draw_char
xxx_draw_char:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r6, r1, 0
	mov r10, r2
	adds r4, r3, 0
	ldr r2, [sp, 0x48]
	ldr r3, [sp, 0x4C]
	lsls r1, r3, 3
	adds r1, r3
	lsls r1, 3
	adds r5, r0, r1
	ldr r1, _080074B8
	movs r0, 0xF
	ands r2, r0
	lsls r2, 2
	adds r2, r1
	ldr r2, [r2]
	str r2, [sp, 0x18]
	ldr r0, _080074BC
	ldr r0, [r0]
	cmp r0, 0x1
	bne _080074CC
	cmp r4, 0x70
	beq _080074B0
	cmp r4, 0x6A
	beq _080074B0
	cmp r4, 0x71
	beq _080074B0
	cmp r4, 0x79
	beq _080074B0
	cmp r4, 0x67
	bne _080074C0
_080074B0:
	movs r0, 0x2
	add r10, r0
	b _080074CC
	.align 2, 0
_080074B8: .4byte gUnknown_80B853C
_080074BC: .4byte gUnknown_20274AC
_080074C0:
	ldr r0, _080074F8
	cmp r4, r0
	bne _080074CC
	movs r1, 0x2
	negs r1, r1
	add r10, r1
_080074CC:
	adds r0, r4, 0
	bl sub_8008584
	str r0, [sp]
	ldr r2, [r0]
	str r2, [sp, 0x4]
	str r2, [sp, 0xC]
	adds r3, r2, 0
	subs r3, 0x6
	str r3, [sp, 0x8]
	ldr r0, _080074FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08007500
	ldr r4, [sp]
	ldrb r1, [r4, 0xA]
	lsrs r7, r1, 1
	movs r0, 0x1
	adds r2, r7, 0
	ands r2, r0
	str r2, [sp, 0x1C]
	b _08007508
	.align 2, 0
_080074F8: .4byte 0x00008199
_080074FC: .4byte gUnknown_202B034
_08007500:
	movs r3, 0
	str r3, [sp, 0x1C]
	ldr r4, [sp]
	ldrb r1, [r4, 0xA]
_08007508:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08007512
	b _08007670
_08007512:
	mov r0, r10
	cmp r0, 0
	bge _0800751A
	adds r0, 0x7
_0800751A:
	asrs r4, r0, 3
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	muls r0, r4
	adds r2, r6, 0
	cmp r6, 0
	bge _0800752A
	adds r2, r6, 0x7
_0800752A:
	asrs r2, 3
	adds r0, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r3, r1, r0
	lsls r0, r4, 3
	mov r1, r10
	subs r0, r1, r0
	lsls r0, 2
	adds r3, r0
	lsls r0, r2, 3
	subs r0, r6, r0
	lsls r0, 4
	ldr r1, _08007664
	adds r0, r1
	mov r12, r0
	mov r9, r2
	str r4, [sp, 0x14]
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r4, r0
	blt _08007558
	b _0800786C
_08007558:
	movs r4, 0
	str r4, [sp, 0x10]
	ldr r2, _08007668
	ldr r1, _0800766C
	ldr r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r4, r0
	blt _0800756E
	b _0800786C
_0800756E:
	adds r4, r2, 0
_08007570:
	ldr r6, [sp, 0x4]
	ldrh r0, [r6, 0x2]
	lsls r2, r0, 16
	ldrh r0, [r6]
	orrs r2, r0
	cmp r2, 0
	beq _080075CC
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	cmp r9, r0
	bge _080075A6
	mov r0, r12
	ldr r1, [r0]
	ands r1, r2
	ldr r0, [r0, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x3C]
	cmp r0, r3
	bls _0800759E
	str r3, [r5, 0x3C]
_0800759E:
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080075A6
	str r3, [r5, 0x40]
_080075A6:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _080075CC
	adds r3, 0x20
	mov r6, r12
	ldr r0, [r6, 0x4]
	ands r2, r0
	ldr r0, [r6, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080075CA
	str r3, [r5, 0x40]
_080075CA:
	subs r3, 0x20
_080075CC:
	ldr r7, [sp, 0x4]
	ldrh r2, [r7, 0x4]
	cmp r2, 0
	beq _08007620
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _080075FA
	adds r3, 0x20
	mov r6, r12
	ldr r1, [r6]
	ands r1, r2
	ldr r0, [r6, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080075F8
	str r3, [r5, 0x40]
_080075F8:
	subs r3, 0x20
_080075FA:
	movs r7, 0x4
	ldrsh r0, [r5, r7]
	subs r0, 0x2
	cmp r9, r0
	bge _08007620
	adds r3, 0x40
	mov r1, r12
	ldr r0, [r1, 0x4]
	ands r2, r0
	ldr r0, [r1, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _0800761E
	str r3, [r5, 0x40]
_0800761E:
	subs r3, 0x40
_08007620:
	ldr r2, [sp, 0x4]
	adds r2, 0x6
	str r2, [sp, 0x4]
	adds r3, 0x4
	movs r6, 0x1
	add r10, r6
	movs r0, 0x7
	mov r7, r10
	ands r0, r7
	cmp r0, 0
	bne _0800764E
	ldr r0, [r5, 0x20]
	lsls r0, 2
	adds r3, r0
	ldr r0, [sp, 0x14]
	adds r0, 0x1
	str r0, [sp, 0x14]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	ldr r2, [sp, 0x14]
	cmp r2, r0
	blt _0800764E
	b _0800786C
_0800764E:
	ldr r6, [sp, 0x10]
	adds r6, 0x1
	str r6, [sp, 0x10]
	ldr r7, _0800766C
	ldr r0, [r7]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	cmp r6, r0
	blt _08007570
	b _0800786C
	.align 2, 0
_08007664: .4byte gUnknown_80B85DC
_08007668: .4byte gUnknown_202B028
_0800766C: .4byte gUnknown_20274AC
_08007670:
	movs r0, 0
	str r0, [sp, 0x20]
	mov r0, r10
	cmp r0, 0
	bge _0800767C
	adds r0, 0x7
_0800767C:
	asrs r4, r0, 3
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	muls r1, r0
	adds r0, r6, 0
	cmp r6, 0
	bge _0800768E
	adds r0, r6, 0x7
_0800768E:
	asrs r2, r0, 3
	adds r0, r1, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r3, r1, r0
	lsls r0, r4, 3
	mov r7, r10
	subs r0, r7, r0
	lsls r0, 2
	adds r3, r0
	lsls r0, r2, 3
	subs r0, r6, r0
	lsls r0, 4
	ldr r1, _0800788C
	adds r0, r1
	mov r12, r0
	mov r9, r2
	str r4, [sp, 0x14]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _080076BC
	b _0800786C
_080076BC:
	movs r2, 0
	str r2, [sp, 0x10]
	ldr r2, _08007890
	ldr r1, _08007894
	ldr r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldr r4, [sp, 0x10]
	cmp r4, r0
	blt _080076D4
	b _0800786C
_080076D4:
	ldr r6, [sp, 0x4]
	ldrh r0, [r6, 0x2]
	lsls r4, r0, 16
	ldrh r0, [r6]
	orrs r4, r0
	ldr r1, _08007898
	ands r1, r4
	ldr r0, [sp, 0x18]
	ands r0, r4
	adds r2, r1, r0
	ldr r7, [sp, 0x1C]
	cmp r7, 0
	beq _08007724
	ldr r1, [sp, 0xC]
	ldrh r0, [r1, 0x2]
	lsls r0, 16
	ldrh r1, [r1]
	orrs r0, r1
	lsls r1, r0, 4
	mvns r6, r4
	mov r8, r6
	bics r1, r4
	ldr r7, _0800789C
	ldr r6, [r7]
	ands r1, r6
	orrs r2, r1
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _08007724
	ldr r1, [sp, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 16
	ldrh r1, [r1]
	orrs r0, r1
	lsls r1, r0, 4
	eors r1, r4
	mov r4, r8
	ands r1, r4
	ands r1, r6
	orrs r2, r1
_08007724:
	cmp r2, 0
	beq _08007776
	movs r6, 0x4
	ldrsh r0, [r5, r6]
	cmp r9, r0
	bge _08007750
	mov r7, r12
	ldr r1, [r7]
	ands r1, r2
	ldr r0, [r7, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x3C]
	cmp r0, r3
	bls _08007748
	str r3, [r5, 0x3C]
_08007748:
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007750
	str r3, [r5, 0x40]
_08007750:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _08007776
	adds r3, 0x20
	mov r4, r12
	ldr r0, [r4, 0x4]
	ands r2, r0
	ldr r0, [r4, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007774
	str r3, [r5, 0x40]
_08007774:
	subs r3, 0x20
_08007776:
	ldr r6, [sp, 0x4]
	ldrh r4, [r6, 0x4]
	ldr r1, _08007898
	ands r1, r4
	ldr r0, [sp, 0x18]
	ands r0, r4
	adds r2, r1, r0
	ldr r7, [sp, 0x1C]
	cmp r7, 0
	beq _080077CC
	ldr r1, [sp, 0xC]
	ldrh r0, [r1, 0x4]
	lsls r1, r0, 4
	ldr r6, [sp, 0xC]
	ldrh r0, [r6, 0x2]
	movs r7, 0xF
	mov r8, r7
	lsrs r0, 12
	orrs r1, r0
	mvns r0, r4
	str r0, [sp, 0x24]
	bics r1, r4
	ldr r7, _0800789C
	ldr r6, [r7]
	ands r1, r6
	orrs r2, r1
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _080077CC
	ldr r1, [sp, 0x8]
	ldrh r0, [r1, 0x4]
	lsls r1, r0, 4
	ldr r7, [sp, 0x8]
	ldrh r0, [r7, 0x2]
	lsrs r0, 12
	mov r7, r8
	ands r0, r7
	orrs r1, r0
	eors r1, r4
	ldr r0, [sp, 0x24]
	ands r1, r0
	ands r1, r6
	orrs r2, r1
_080077CC:
	cmp r2, 0
	beq _0800781C
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r9, r0
	bge _080077F6
	adds r3, 0x20
	mov r4, r12
	ldr r1, [r4]
	ands r1, r2
	ldr r0, [r4, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _080077F4
	str r3, [r5, 0x40]
_080077F4:
	subs r3, 0x20
_080077F6:
	movs r6, 0x4
	ldrsh r0, [r5, r6]
	subs r0, 0x2
	cmp r9, r0
	bge _0800781C
	adds r3, 0x40
	mov r7, r12
	ldr r0, [r7, 0x4]
	ands r2, r0
	ldr r0, [r7, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _0800781A
	str r3, [r5, 0x40]
_0800781A:
	subs r3, 0x40
_0800781C:
	movs r0, 0x1
	str r0, [sp, 0x20]
	ldr r1, [sp, 0x4]
	adds r1, 0x6
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x8]
	adds r2, 0x6
	str r2, [sp, 0x8]
	ldr r4, [sp, 0xC]
	adds r4, 0x6
	str r4, [sp, 0xC]
	adds r3, 0x4
	add r10, r0
	movs r0, 0x7
	mov r6, r10
	ands r0, r6
	cmp r0, 0
	bne _08007854
	ldr r0, [r5, 0x20]
	lsls r0, 2
	adds r3, r0
	ldr r7, [sp, 0x14]
	adds r7, 0x1
	str r7, [sp, 0x14]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r7, r0
	bge _0800786C
_08007854:
	ldr r2, [sp, 0x10]
	adds r2, 0x1
	str r2, [sp, 0x10]
	ldr r4, _08007894
	ldr r0, [r4]
	lsls r0, 2
	ldr r6, _08007890
	adds r0, r6
	ldr r0, [r0]
	cmp r2, r0
	bge _0800786C
	b _080076D4
_0800786C:
	ldr r7, [sp]
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	ldr r2, _080078A0
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800788C: .4byte gUnknown_80B85DC
_08007890: .4byte gUnknown_202B028
_08007894: .4byte gUnknown_20274AC
_08007898: .4byte 0x11111111
_0800789C: .4byte gUnknown_202B030
_080078A0: .4byte gUnknown_2027498
	thumb_func_end xxx_draw_char

	thumb_func_start sub_80078A4
sub_80078A4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r5, 0
	bl sub_800792C
	adds r4, 0x1
	ldr r0, _080078E4
	ldr r0, [r0]
	movs r1, 0xF
	ands r0, r1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	mov r3, r8
	bl sub_800792C
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080078E4: .4byte gUnknown_202B030
	thumb_func_end sub_80078A4

	thumb_func_start sub_80078E8
sub_80078E8:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r5, 0
	bl nullsub_129
	adds r4, 0x1
	ldr r0, _08007928
	ldr r0, [r0]
	movs r1, 0xF
	ands r0, r1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	mov r3, r8
	bl nullsub_129
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007928: .4byte gUnknown_202B030
	thumb_func_end sub_80078E8

	thumb_func_start sub_800792C
sub_800792C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007950
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007958
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007950: .4byte gUnknown_2027370
	thumb_func_end sub_800792C

	thumb_func_start nullsub_129
nullsub_129:
	bx lr
	thumb_func_end nullsub_129

	thumb_func_start sub_8007958
sub_8007958:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x24
	mov r8, r2
	adds r7, r3, 0
	ldr r2, [sp, 0x40]
	mov r12, r2
	ldr r3, [sp, 0x44]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r5, r0, r2
	ldr r1, _08007A68
	movs r0, 0xF
	ands r3, r0
	lsls r3, 2
	adds r3, r1
	ldr r3, [r3]
	mov r9, r3
	adds r0, r7, 0
	cmp r7, 0
	bge _0800798A
	adds r0, r7, 0x7
_0800798A:
	asrs r4, r0, 3
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	muls r0, r4
	mov r2, r8
	cmp r2, 0
	bge _0800799A
	adds r2, 0x7
_0800799A:
	asrs r2, 3
	adds r0, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r3, r1, r0
	lsls r0, r4, 3
	subs r0, r7, r0
	lsls r0, 2
	adds r3, r0
	adds r6, r2, 0
	movs r2, 0x8
	ldrsh r0, [r5, r2]
	cmp r4, r0
	bge _08007A58
	mov r1, sp
	ldr r0, _08007A6C
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	mov r4, r12
	cmp r4, 0
	ble _08007A58
	ldr r7, _08007A70
_080079CE:
	mov r1, r12
	cmp r1, 0x7
	ble _080079D6
	movs r1, 0x8
_080079D6:
	mov r0, r8
	cmp r0, 0
	bge _080079DE
	adds r0, 0x7
_080079DE:
	asrs r0, 3
	lsls r0, 3
	mov r2, r8
	subs r0, r2, r0
	lsls r0, 4
	adds r4, r0, r7
	lsls r0, r1, 2
	add r0, sp
	ldr r2, [r0]
	ldr r1, _08007A74
	ands r1, r2
	mov r0, r9
	ands r0, r2
	adds r2, r1, r0
	cmp r2, 0
	beq _08007A48
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r6, r0
	bge _08007A24
	ldr r1, [r4]
	ands r1, r2
	ldr r0, [r4, 0x8]
	lsls r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r5, 0x3C]
	cmp r0, r3
	bls _08007A1C
	str r3, [r5, 0x3C]
_08007A1C:
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007A24
	str r3, [r5, 0x40]
_08007A24:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	subs r0, 0x1
	cmp r6, r0
	bge _08007A48
	adds r3, 0x20
	ldr r0, [r4, 0x4]
	ands r2, r0
	ldr r0, [r4, 0xC]
	lsrs r2, r0
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r5, 0x40]
	cmp r0, r3
	bcs _08007A46
	str r3, [r5, 0x40]
_08007A46:
	subs r3, 0x20
_08007A48:
	adds r6, 0x1
	adds r3, 0x20
	movs r2, 0x8
	negs r2, r2
	add r12, r2
	mov r4, r12
	cmp r4, 0
	bgt _080079CE
_08007A58:
	add sp, 0x24
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007A68: .4byte gUnknown_80B853C
_08007A6C: .4byte gUnknown_80B8824
_08007A70: .4byte gUnknown_80B85DC
_08007A74: .4byte 0x11111111
	thumb_func_end sub_8007958

	thumb_func_start sub_8007A78
sub_8007A78:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007A9C
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007AA4
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007A9C: .4byte gUnknown_2027370
	thumb_func_end sub_8007A78

	thumb_func_start nullsub_157
nullsub_157:
	bx lr
	thumb_func_end nullsub_157

	thumb_func_start sub_8007AA4
sub_8007AA4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x20
	mov r9, r2
	adds r5, r3, 0
	ldr r7, [sp, 0x3C]
	ldr r3, [sp, 0x40]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r4, r0, r2
	ldr r1, _08007B28
	movs r0, 0xF
	ands r3, r0
	lsls r3, 2
	adds r3, r1
	ldr r0, [r3]
	ldr r1, _08007B2C
	adds r1, r0
	mov r12, r1
	mov r1, sp
	ldr r0, _08007B30
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3}
	stm r1!, {r2,r3}
	adds r0, r5, 0
	cmp r5, 0
	bge _08007AE8
	adds r0, r5, 0x7
_08007AE8:
	asrs r3, r0, 3
	movs r0, 0x4
	ldrsh r6, [r4, r0]
	mov r8, r6
	mov r0, r8
	muls r0, r3
	mov r2, r9
	cmp r2, 0
	bge _08007AFC
	adds r2, 0x7
_08007AFC:
	asrs r2, 3
	adds r0, r2
	lsls r0, 5
	ldr r1, [r4, 0x18]
	adds r1, r0
	lsls r0, r3, 3
	subs r0, r5, r0
	lsls r0, 2
	adds r1, r0
	movs r0, 0x7
	mov r6, r9
	ands r0, r6
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	mov r6, r12
	ands r6, r0
	mov r12, r6
	cmp r2, r8
	bge _08007B6E
	b _08007B48
	.align 2, 0
_08007B28: .4byte gUnknown_80B853C
_08007B2C: .4byte 0x11111111
_08007B30: .4byte gUnknown_80B8848
_08007B34:
	adds r5, 0x1
	adds r1, 0x4
	movs r0, 0x7
	ands r0, r5
	cmp r0, 0
	bne _08007B46
	ldr r0, [r4, 0x20]
	lsls r0, 2
	adds r1, r0
_08007B46:
	subs r7, 0x1
_08007B48:
	cmp r7, 0
	ble _08007B6E
	movs r2, 0x8
	ldrsh r0, [r4, r2]
	cmp r3, r0
	bge _08007B6E
	ldr r0, [r1]
	mov r6, r12
	orrs r0, r6
	str r0, [r1]
	ldr r0, [r4, 0x3C]
	cmp r0, r1
	bls _08007B64
	str r1, [r4, 0x3C]
_08007B64:
	ldr r0, [r4, 0x40]
	cmp r0, r1
	bcs _08007B34
	str r1, [r4, 0x40]
	b _08007B34
_08007B6E:
	add sp, 0x20
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007AA4

	thumb_func_start sub_8007B7C
sub_8007B7C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007BA0
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007BA8
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007BA0: .4byte gUnknown_2027370
	thumb_func_end sub_8007B7C

	thumb_func_start nullsub_158
nullsub_158:
	bx lr
	thumb_func_end nullsub_158

	thumb_func_start sub_8007BA8
sub_8007BA8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r2, [sp]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r0, r2
	mov r12, r0
	adds r0, r3, 0
	cmp r3, 0
	bge _08007BC8
	adds r0, r3, 0x7
_08007BC8:
	asrs r0, 3
	str r0, [sp, 0x8]
	mov r1, r12
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bge _08007CC4
	movs r7, 0x4
	ldrsh r0, [r1, r7]
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007BE8
	adds r0, 0x7
_08007BE8:
	asrs r0, 3
	adds r0, r1, r0
	lsls r0, 5
	mov r2, r12
	ldr r1, [r2, 0x18]
	adds r4, r1, r0
	ldr r7, [sp, 0x8]
	lsls r0, r7, 3
	subs r0, r3, r0
	lsls r0, 2
	adds r4, r0
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	cmp r0, r1
	bge _08007CC4
_08007C08:
	adds r2, r4, 0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007C12
	adds r0, 0x7
_08007C12:
	asrs r1, r0, 3
	movs r7, 0
	mov r8, r7
	adds r3, 0x1
	str r3, [sp, 0xC]
	adds r4, 0x4
	str r4, [sp, 0x14]
	ldr r0, [sp, 0x40]
	cmp r8, r0
	bge _08007C94
_08007C26:
	mov r3, r12
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bge _08007C94
	movs r6, 0xF0
	lsls r6, 24
	movs r5, 0xE0
	lsls r5, 24
	movs r7, 0
	str r7, [sp, 0x1C]
	ldr r4, [r2]
	adds r3, r4, 0
	mov r0, r12
	ldr r0, [r0, 0x3C]
	mov r9, r0
	mov r7, r12
	ldr r7, [r7, 0x40]
	mov r10, r7
	adds r1, 0x1
	str r1, [sp, 0x10]
	adds r0, r2, 0
	adds r0, 0x20
	str r0, [sp, 0x18]
	movs r1, 0x8
	add r8, r1
	movs r1, 0x7
_08007C5C:
	adds r0, r4, 0
	ands r0, r6
	cmp r0, 0
	bne _08007C6A
	ldr r7, [sp, 0x1C]
	orrs r7, r5
	str r7, [sp, 0x1C]
_08007C6A:
	lsrs r6, 4
	lsrs r5, 4
	subs r1, 0x1
	cmp r1, 0
	bge _08007C5C
	ldr r0, [sp, 0x1C]
	orrs r3, r0
	str r3, [r2]
	cmp r9, r2
	bls _08007C82
	mov r1, r12
	str r2, [r1, 0x3C]
_08007C82:
	cmp r10, r2
	bcs _08007C8A
	mov r3, r12
	str r2, [r3, 0x40]
_08007C8A:
	ldr r1, [sp, 0x10]
	ldr r2, [sp, 0x18]
	ldr r4, [sp, 0x40]
	cmp r8, r4
	blt _08007C26
_08007C94:
	ldr r3, [sp, 0xC]
	ldr r4, [sp, 0x14]
	movs r0, 0x7
	ands r0, r3
	cmp r0, 0
	bne _08007CB8
	mov r7, r12
	ldr r0, [r7, 0x20]
	lsls r0, 2
	adds r4, r0
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	ldr r2, [sp, 0x8]
	cmp r2, r0
	bge _08007CC4
_08007CB8:
	ldr r7, [sp, 0x4]
	adds r7, 0x1
	str r7, [sp, 0x4]
	ldr r0, [sp, 0x44]
	cmp r7, r0
	blt _08007C08
_08007CC4:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007BA8

	thumb_func_start sub_8007CD4
sub_8007CD4:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08007CF8
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8007D00
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007CF8: .4byte gUnknown_2027370
	thumb_func_end sub_8007CD4

	thumb_func_start nullsub_159
nullsub_159:
	bx lr
	thumb_func_end nullsub_159

	thumb_func_start sub_8007D00
sub_8007D00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r2, [sp]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r0, r2
	mov r12, r0
	adds r0, r3, 0
	cmp r3, 0
	bge _08007D20
	adds r0, r3, 0x7
_08007D20:
	asrs r0, 3
	str r0, [sp, 0x8]
	mov r1, r12
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bge _08007E0E
	movs r5, 0x4
	ldrsh r0, [r1, r5]
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007D40
	adds r0, 0x7
_08007D40:
	asrs r0, 3
	adds r0, r1, r0
	lsls r0, 5
	mov r2, r12
	ldr r1, [r2, 0x18]
	adds r4, r1, r0
	ldr r5, [sp, 0x8]
	lsls r0, r5, 3
	subs r0, r3, r0
	lsls r0, 2
	adds r4, r0
	movs r0, 0
	b _08007E06
_08007D5A:
	adds r2, r4, 0
	ldr r0, [sp]
	cmp r0, 0
	bge _08007D64
	adds r0, 0x7
_08007D64:
	asrs r1, r0, 3
	movs r5, 0
	mov r8, r5
	adds r3, 0x1
	str r3, [sp, 0xC]
	adds r4, 0x4
	str r4, [sp, 0x14]
	ldr r0, [sp, 0x40]
	cmp r8, r0
	bge _08007DE0
_08007D78:
	mov r3, r12
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bge _08007DE0
	movs r4, 0xF0
	lsls r4, 24
	movs r6, 0xE0
	lsls r6, 24
	movs r7, 0
	ldr r5, [r2]
	str r5, [sp, 0x1C]
	adds r3, r5, 0
	mov r0, r12
	ldr r0, [r0, 0x3C]
	mov r9, r0
	mov r5, r12
	ldr r5, [r5, 0x40]
	mov r10, r5
	adds r1, 0x1
	str r1, [sp, 0x10]
	adds r0, r2, 0
	adds r0, 0x20
	str r0, [sp, 0x18]
	movs r1, 0x8
	add r8, r1
	movs r1, 0x7
_08007DAE:
	ldr r0, [sp, 0x1C]
	ands r0, r4
	cmp r0, r6
	bne _08007DB8
	orrs r7, r4
_08007DB8:
	lsrs r4, 4
	lsrs r6, 4
	subs r1, 0x1
	cmp r1, 0
	bge _08007DAE
	bics r3, r7
	str r3, [r2]
	cmp r9, r2
	bls _08007DCE
	mov r3, r12
	str r2, [r3, 0x3C]
_08007DCE:
	cmp r10, r2
	bcs _08007DD6
	mov r4, r12
	str r2, [r4, 0x40]
_08007DD6:
	ldr r1, [sp, 0x10]
	ldr r2, [sp, 0x18]
	ldr r5, [sp, 0x40]
	cmp r8, r5
	blt _08007D78
_08007DE0:
	ldr r3, [sp, 0xC]
	ldr r4, [sp, 0x14]
	movs r0, 0x7
	ands r0, r3
	cmp r0, 0
	bne _08007E02
	mov r1, r12
	ldr r0, [r1, 0x20]
	lsls r0, 2
	adds r4, r0
	ldr r2, [sp, 0x8]
	adds r2, 0x1
	str r2, [sp, 0x8]
	movs r5, 0x8
	ldrsh r0, [r1, r5]
	cmp r2, r0
	bge _08007E0E
_08007E02:
	ldr r0, [sp, 0x4]
	adds r0, 0x1
_08007E06:
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x44]
	cmp r0, r1
	blt _08007D5A
_08007E0E:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007D00

	thumb_func_start sub_8007E20
sub_8007E20:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x14
	mov r8, r0
	mov r9, r1
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r0, _08007E58
	ldr r1, _08007E5C
	str r2, [sp]
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	str r6, [sp, 0x10]
	mov r2, r8
	mov r3, r9
	bl sub_8007E64
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007E58: .4byte gUnknown_2027370
_08007E5C: .4byte gUnknown_202B038
	thumb_func_end sub_8007E20

	thumb_func_start nullsub_160
nullsub_160:
	bx lr
	thumb_func_end nullsub_160

	thumb_func_start sub_8007E64
sub_8007E64:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r1, [sp]
	str r3, [sp, 0x4]
	ldr r7, [sp, 0x30]
	ldr r1, [sp, 0x34]
	mov r9, r1
	ldr r1, [sp, 0x38]
	mov r10, r1
	ldr r5, [sp, 0x3C]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r4, r0, r1
	adds r0, r3, 0
	cmp r0, 0
	bge _08007E90
	adds r0, 0x7
_08007E90:
	asrs r0, 3
	str r0, [sp, 0x4]
	adds r0, r7, 0
	cmp r7, 0
	bge _08007E9C
	adds r0, r7, 0x7
_08007E9C:
	asrs r7, r0, 3
	mov r0, r9
	cmp r0, 0
	bge _08007EA6
	adds r0, 0x7
_08007EA6:
	asrs r0, 3
	mov r9, r0
	mov r0, r10
	cmp r0, 0
	bge _08007EB2
	adds r0, 0x7
_08007EB2:
	asrs r0, 3
	mov r10, r0
	ldr r2, [sp, 0x40]
	lsls r2, 12
	str r2, [sp, 0x40]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r7, r0
	bge _08007F98
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	muls r0, r7
	ldr r1, [sp, 0x4]
	adds r0, r1
	lsls r0, 5
	ldr r1, [r4, 0x18]
	adds r1, r0
	mov r8, r1
	movs r2, 0
	b _08007F92
_08007EDA:
	ldr r6, [sp, 0x4]
	mov r3, r8
	adds r0, r7, 0x1
	str r0, [sp, 0xC]
	mov r1, r9
	cmp r1, 0
	ble _08007F7A
	mov r12, r9
_08007EEA:
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	cmp r6, r0
	bge _08007F68
	ldr r0, [r4, 0x3C]
	cmp r0, r3
	bls _08007EFA
	str r3, [r4, 0x3C]
_08007EFA:
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldm r5!, {r0}
	stm r3!, {r0}
	ldr r0, [r5]
	stm r3!, {r0}
	ldr r0, [r4, 0x40]
	cmp r0, r3
	bcs _08007F22
	str r3, [r4, 0x40]
_08007F22:
	adds r5, 0x4
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, r7
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r6
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, _08007F64
	ands r0, r2
	strh r0, [r1]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, r7
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r6
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, 0x40]
	orrs r0, r2
	strh r0, [r1]
	b _08007F6C
	.align 2, 0
_08007F64: .4byte 0x00000fff
_08007F68:
	adds r3, 0x20
	adds r5, 0x20
_08007F6C:
	adds r6, 0x1
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	mov r1, r12
	cmp r1, 0
	bne _08007EEA
_08007F7A:
	ldr r7, [sp, 0xC]
	ldr r0, [r4, 0x20]
	lsls r0, 2
	add r8, r0
	movs r2, 0x20
	add r8, r2
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r7, r0
	bge _08007F98
	ldr r2, [sp, 0x8]
	adds r2, 0x1
_08007F92:
	str r2, [sp, 0x8]
	cmp r2, r10
	blt _08007EDA
_08007F98:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8007E64

	thumb_func_start sub_8007FA8
sub_8007FA8:
	adds r3, r0, 0
	lsrs r0, r3, 28
	lsrs r1, r3, 20
	movs r2, 0xF0
	ands r1, r2
	orrs r0, r1
	lsrs r1, r3, 12
	movs r2, 0xF0
	lsls r2, 4
	ands r1, r2
	orrs r0, r1
	lsrs r1, r3, 4
	movs r2, 0xF0
	lsls r2, 8
	ands r1, r2
	orrs r0, r1
	lsls r1, r3, 4
	movs r2, 0xF0
	lsls r2, 12
	ands r1, r2
	orrs r0, r1
	lsls r1, r3, 12
	movs r2, 0xF0
	lsls r2, 16
	ands r1, r2
	orrs r0, r1
	lsls r1, r3, 20
	movs r2, 0xF0
	lsls r2, 20
	ands r1, r2
	orrs r0, r1
	lsls r3, 28
	orrs r0, r3
	bx lr
	thumb_func_end sub_8007FA8

	thumb_func_start sub_8007FEC
sub_8007FEC:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x14
	mov r8, r0
	mov r9, r1
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r0, _08008024
	ldr r1, _08008028
	str r2, [sp]
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	str r6, [sp, 0x10]
	mov r2, r8
	mov r3, r9
	bl sub_8008030
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008024: .4byte gUnknown_2027370
_08008028: .4byte gUnknown_202B038
	thumb_func_end sub_8007FEC

	thumb_func_start nullsub_161
nullsub_161:
	bx lr
	thumb_func_end nullsub_161

	thumb_func_start sub_8008030
sub_8008030:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r1, [sp]
	ldr r1, [sp, 0x30]
	mov r8, r1
	ldr r6, [sp, 0x3C]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r5, r0, r1
	adds r0, r3, 0
	cmp r3, 0
	bge _08008054
	adds r0, r3, 0x7
_08008054:
	asrs r3, r0, 3
	mov r0, r8
	cmp r0, 0
	bge _0800805E
	adds r0, 0x7
_0800805E:
	asrs r0, 3
	mov r8, r0
	ldr r0, [sp, 0x34]
	cmp r0, 0
	bge _0800806A
	adds r0, 0x7
_0800806A:
	asrs r0, 3
	str r0, [sp, 0x34]
	ldr r0, [sp, 0x38]
	cmp r0, 0
	bge _08008076
	adds r0, 0x7
_08008076:
	asrs r0, 3
	str r0, [sp, 0x38]
	ldr r2, [sp, 0x40]
	lsls r2, 12
	str r2, [sp, 0x40]
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r8, r0
	blt _0800808A
	b _08008194
_0800808A:
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r1, [sp, 0x34]
	adds r2, r3, r1
	adds r0, r2
	lsls r0, 5
	ldr r1, [r5, 0x18]
	adds r1, r0
	mov r10, r1
	movs r3, 0
	str r3, [sp, 0x4]
	str r2, [sp, 0xC]
	ldr r0, [sp, 0x38]
	cmp r3, r0
	bge _08008194
_080080AE:
	ldr r7, [sp, 0xC]
	mov r4, r10
	mov r1, r8
	adds r1, 0x1
	str r1, [sp, 0x8]
	ldr r2, [sp, 0x34]
	cmp r2, 0
	ble _08008172
	mov r9, r2
_080080C0:
	subs r7, 0x1
	subs r4, 0x20
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	cmp r7, r0
	bge _08008164
	ldr r0, [r5, 0x3C]
	cmp r0, r4
	bls _080080D4
	str r4, [r5, 0x3C]
_080080D4:
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x4]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x8]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0xC]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x10]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x14]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x18]
	ldm r6!, {r0}
	bl sub_8007FA8
	str r0, [r4, 0x1C]
	adds r1, r4, 0
	adds r1, 0x20
	ldr r0, [r5, 0x40]
	cmp r0, r1
	bcs _08008120
	str r1, [r5, 0x40]
_08008120:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	add r0, r8
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r1, r7
	lsls r1, 1
	lsls r0, 6
	ldr r3, [sp]
	adds r0, r3
	adds r1, r0
	ldrh r0, [r1]
	ldr r3, _08008160
	adds r2, r3, 0
	ands r0, r2
	strh r0, [r1]
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	add r0, r8
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r1, r7
	lsls r1, 1
	lsls r0, 6
	ldr r3, [sp]
	adds r0, r3
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, 0x40]
	orrs r0, r2
	strh r0, [r1]
	b _08008166
	.align 2, 0
_08008160: .4byte 0x00000fff
_08008164:
	adds r6, 0x20
_08008166:
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	bne _080080C0
_08008172:
	ldr r2, [sp, 0x8]
	mov r8, r2
	ldr r0, [r5, 0x20]
	lsls r0, 2
	add r10, r0
	movs r3, 0x20
	add r10, r3
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r8, r0
	bge _08008194
	ldr r2, [sp, 0x4]
	adds r2, 0x1
	str r2, [sp, 0x4]
	ldr r3, [sp, 0x38]
	cmp r2, r3
	blt _080080AE
_08008194:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8008030

	thumb_func_start sub_80081A4
sub_80081A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r1, [sp]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08008234
	adds r6, r1, r0
	lsls r3, 7
	ldr r0, _08008238
	adds r3, r0
	ldr r0, [sp]
	cmp r0, 0
	bge _080081CA
	adds r0, 0x7
_080081CA:
	asrs r0, 3
	str r0, [sp]
	adds r0, r2, 0
	cmp r2, 0
	bge _080081D6
	adds r0, r2, 0x7
_080081D6:
	asrs r2, r0, 3
	movs r0, 0x2
	mov r9, r0
	mov r10, r0
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r2, r0
	bge _08008262
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	muls r0, r2
	ldr r1, [sp]
	adds r0, r1
	lsls r0, 5
	ldr r1, [r6, 0x28]
	adds r5, r1, r0
	movs r7, 0
	mov r8, r7
_080081FA:
	ldr r4, [sp]
	adds r1, r5, 0
	adds r2, 0x1
	mov r12, r2
	mov r0, r9
	cmp r0, 0
	beq _08008248
	mov r2, r9
_0800820A:
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r4, r0
	bge _0800823C
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	b _08008240
	.align 2, 0
_08008234: .4byte gUnknown_2027370
_08008238: .4byte gUnknown_80B86B4
_0800823C:
	adds r1, 0x20
	adds r3, 0x20
_08008240:
	adds r4, 0x1
	subs r2, 0x1
	cmp r2, 0
	bne _0800820A
_08008248:
	mov r2, r12
	ldr r0, [r6, 0x20]
	lsls r0, 2
	adds r5, r0
	adds r5, 0x20
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	cmp r2, r0
	bge _08008262
	movs r7, 0x1
	add r8, r7
	cmp r8, r10
	blt _080081FA
_08008262:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80081A4

	thumb_func_start sub_8008274
sub_8008274:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r3, r1, 0
	ldr r0, _08008290
	ldr r1, _08008294
	str r2, [sp]
	adds r2, r4, 0
	bl sub_800829C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008290: .4byte gUnknown_2027370
_08008294: .4byte gUnknown_202B038
	thumb_func_end sub_8008274

	thumb_func_start nullsub_162
nullsub_162:
	bx lr
	thumb_func_end nullsub_162

	thumb_func_start sub_800829C
sub_800829C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	ldr r7, [sp, 0x18]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r4, r0, r1
	lsls r7, 12
	ldr r0, [r4, 0x18]
	movs r1, 0x4
	ldrsh r2, [r4, r1]
	movs r5, 0x8
	ldrsh r1, [r4, r5]
	lsls r1, 5
	muls r1, r2
	adds r2, r3, 0
	bl sub_800AAB4
	movs r2, 0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r2, r0
	bge _08008312
	movs r0, 0x4
	ldrsh r5, [r4, r0]
	mov r12, r5
_080082D4:
	adds r5, r2, 0x1
	mov r1, r12
	cmp r1, 0
	ble _08008308
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r4, r2]
	lsls r1, 6
	ldr r6, _08008330
	lsls r0, 1
	adds r0, r1
	mov r1, r8
	adds r2, r0, r1
	movs r0, 0x4
	ldrsh r3, [r4, r0]
_080082F6:
	ldrh r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	orrs r0, r7
	strh r0, [r2]
	adds r2, 0x2
	subs r3, 0x1
	cmp r3, 0
	bne _080082F6
_08008308:
	adds r2, r5, 0
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r2, r0
	blt _080082D4
_08008312:
	ldr r0, [r4, 0x28]
	str r0, [r4, 0x30]
	ldr r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	ldr r0, [r4, 0x2C]
	str r0, [r4, 0x38]
	adds r1, r4, 0
	adds r1, 0x44
	movs r0, 0x1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008330: .4byte 0x00000fff
	thumb_func_end sub_800829C

	thumb_func_start sub_8008334
sub_8008334:
	push {r4-r7,lr}
	adds r7, r0, 0
	mov r12, r1
	ldr r4, [r7]
	ldr r1, [r1]
	movs r3, 0
	movs r2, 0
	movs r6, 0xF
	movs r5, 0x1C
_08008346:
	lsls r2, 4
	lsls r3, 4
	adds r0, r4, 0
	ands r0, r6
	orrs r2, r0
	adds r0, r1, 0
	ands r0, r6
	orrs r3, r0
	lsrs r4, 4
	lsrs r1, 4
	subs r5, 0x4
	cmp r5, 0
	bge _08008346
	str r3, [r7]
	mov r0, r12
	str r2, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8008334

	thumb_func_start sub_800836C
sub_800836C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldr r0, _08008384
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800838C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08008384: .4byte gUnknown_2027370
	thumb_func_end sub_800836C

	thumb_func_start nullsub_163
nullsub_163:
	bx lr
	thumb_func_end nullsub_163

	thumb_func_start sub_800838C
sub_800838C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r4, r1, 3
	adds r4, r1
	lsls r4, 3
	adds r7, r0, r4
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	bl sub_8008274
	movs r0, 0
	mov r9, r0
	b _08008452
_080083AE:
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	mov r8, r0
	ldrh r1, [r7, 0x4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080083C8
	movs r0, 0x1
	add r8, r0
_080083C8:
	movs r6, 0
	movs r1, 0x1
	add r1, r9
	mov r10, r1
	cmp r6, r8
	bge _08008450
_080083D4:
	movs r0, 0x4
	ldrsh r1, [r7, r0]
	mov r0, r9
	muls r0, r1
	adds r4, r0, r6
	lsls r4, 5
	ldr r5, [r7, 0x18]
	adds r4, r5, r4
	subs r0, 0x1
	subs r1, r6
	adds r0, r1
	lsls r0, 5
	adds r5, r0
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r4, 0x4
	adds r1, r5, 0
	adds r5, 0x4
	bl sub_8008334
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8008334
	adds r6, 0x1
	cmp r6, r8
	blt _080083D4
_08008450:
	mov r9, r10
_08008452:
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	cmp r9, r0
	blt _080083AE
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800838C

	thumb_func_start sub_8008468
sub_8008468:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	adds r6, r0, 0
	mov r8, r1
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	ldr r0, _08008498
	ldr r1, _0800849C
	str r2, [sp]
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	str r5, [sp, 0xC]
	adds r2, r6, 0
	mov r3, r8
	bl sub_80084A4
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008498: .4byte gUnknown_2027370
_0800849C: .4byte gUnknown_202B038
	thumb_func_end sub_8008468

	thumb_func_start nullsub_164
nullsub_164:
	bx lr
	thumb_func_end nullsub_164

	thumb_func_start sub_80084A4
sub_80084A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r1, [sp]
	mov r10, r3
	ldr r6, [sp, 0x24]
	ldr r7, [sp, 0x28]
	ldr r1, [sp, 0x2C]
	mov r12, r1
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 3
	adds r4, r0, r1
	mov r0, r10
	cmp r0, 0
	bge _080084CC
	adds r0, 0x7
_080084CC:
	asrs r0, 3
	mov r10, r0
	adds r0, r6, 0
	cmp r6, 0
	bge _080084D8
	adds r0, r6, 0x7
_080084D8:
	asrs r6, r0, 3
	adds r0, r7, 0
	cmp r7, 0
	bge _080084E2
	adds r0, r7, 0x7
_080084E2:
	asrs r7, r0, 3
	mov r0, r12
	cmp r0, 0
	bge _080084EC
	adds r0, 0x7
_080084EC:
	asrs r0, 3
	mov r12, r0
	ldr r2, [sp, 0x30]
	lsls r2, 12
	str r2, [sp, 0x30]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r6, r0
	bge _08008570
	movs r2, 0
	mov r8, r2
	cmp r8, r12
	bge _08008570
_08008506:
	mov r3, r10
	adds r0, r6, 0x1
	mov r9, r0
	cmp r7, 0
	ble _0800855E
	adds r5, r7, 0
_08008512:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r3, r0
	bge _08008556
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r0, r6
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r3
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, _08008580
	ands r0, r2
	strh r0, [r1]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, r6
	movs r2, 0
	ldrsh r1, [r4, r2]
	adds r1, r3
	lsls r1, 1
	lsls r0, 6
	ldr r2, [sp]
	adds r0, r2
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, 0x30]
	orrs r0, r2
	strh r0, [r1]
_08008556:
	adds r3, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _08008512
_0800855E:
	mov r6, r9
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r6, r0
	bge _08008570
	movs r2, 0x1
	add r8, r2
	cmp r8, r12
	blt _08008506
_08008570:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008580: .4byte 0x00000fff
	thumb_func_end sub_80084A4

	thumb_func_start sub_8008584
sub_8008584:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r1, _080085C4
	ldr r0, _080085C8
	ldr r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	ldr r5, [r2, 0x4]
	ldr r0, _080085CC
	adds r1, r3, r0
	ldr r0, _080085D0
	cmp r1, r0
	bhi _080085D4
	movs r2, 0xFF
	ands r2, r3
	movs r1, 0xFF
	lsls r1, 8
	ands r1, r3
	asrs r1, 8
	subs r2, 0x20
	subs r1, 0xF8
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 5
	adds r0, r2
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5, r1
	b _08008624
	.align 2, 0
_080085C4: .4byte gUnknown_2027490
_080085C8: .4byte gUnknown_20274AC
_080085CC: .4byte 0xffff0800
_080085D0: .4byte 0x000007fe
_080085D4:
	movs r4, 0
	ldr r0, [r2]
	subs r2, r0, 0x1
	cmp r4, r2
	bge _08008614
	lsrs r0, r2, 31
	adds r0, r2, r0
	b _08008602
_080085E4:
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0, 0x4]
	cmp r0, r3
	bge _080085F6
	adds r4, r1, 0x1
	b _080085F8
_080085F6:
	adds r2, r1, 0
_080085F8:
	cmp r4, r2
	bge _08008614
	adds r0, r4, r2
	lsrs r1, r0, 31
	adds r0, r1
_08008602:
	asrs r1, r0, 1
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0, 0x4]
	cmp r0, r3
	bne _080085E4
	adds r4, r1, 0
_08008614:
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r1, r5, r0
	ldrh r0, [r1, 0x4]
	cmp r0, r3
	beq _08008624
	ldr r1, _0800862C
_08008624:
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800862C: .4byte gUnknown_80B86A4
	thumb_func_end sub_8008584

	thumb_func_start sub_8008630
sub_8008630:
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	adds r3, r1, 0
	adds r2, r1, 0
	subs r2, 0x30
	lsls r0, r2, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _08008648
	adds r0, r2, 0
	b _0800865C
_08008648:
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _08008658
	movs r0, 0x1
	b _0800865C
_08008658:
	adds r0, r3, 0
	subs r0, 0x57
_0800865C:
	pop {r1}
	bx r1
	thumb_func_end sub_8008630

	thumb_func_start xxx_get_next_char_from_string
xxx_get_next_char_from_string:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldrb r1, [r5]
	cmp r1, 0x7E
	bne _08008696
	adds r5, 0x1
	ldrb r0, [r5]
	bl sub_8008630
	adds r4, r0, 0
	ldrb r0, [r5, 0x1]
	bl sub_8008630
	lsls r4, 4
	adds r4, r0
	ldrb r0, [r5]
	cmp r0, 0
	beq _08008690
	adds r5, 0x1
	ldrb r0, [r5]
	cmp r0, 0
	beq _08008690
	adds r5, 0x1
_08008690:
	str r4, [r6]
	adds r0, r5, 0
	b _080086B2
_08008696:
	adds r0, r1, 0
	subs r0, 0x81
	cmp r0, 0x3
	bls _080086A2
	cmp r1, 0x87
	bne _080086AE
_080086A2:
	ldrb r0, [r5, 0x1]
	lsls r1, 8
	orrs r0, r1
	str r0, [r6]
	adds r0, r5, 0x2
	b _080086B2
_080086AE:
	str r1, [r6]
	adds r0, r5, 0x1
_080086B2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end xxx_get_next_char_from_string

	thumb_func_start nullsub_165
nullsub_165:
	bx lr
	thumb_func_end nullsub_165

	thumb_func_start nullsub_166
nullsub_166:
	bx lr
	thumb_func_end nullsub_166

	thumb_func_start nullsub_167
nullsub_167:
	bx lr
	thumb_func_end nullsub_167

	thumb_func_start nullsub_168
nullsub_168:
	bx lr
	thumb_func_end nullsub_168

	thumb_func_start sub_80086C8
sub_80086C8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r2
	ldr r7, [sp, 0x30]
	lsls r2, r1, 3
	adds r2, r1
	lsls r2, 3
	adds r0, r2
	mov r12, r0
	mov r0, r9
	cmp r0, 0
	bge _080086F2
	ldr r1, [sp, 0x2C]
	add r1, r9
	str r1, [sp, 0x2C]
	movs r2, 0
	mov r9, r2
_080086F2:
	cmp r3, 0
	bge _080086FA
	adds r7, r3
	movs r3, 0
_080086FA:
	ldr r0, [sp, 0x2C]
	add r0, r9
	mov r4, r12
	movs r5, 0x4
	ldrsh r2, [r4, r5]
	lsls r1, r2, 3
	cmp r0, r1
	ble _08008710
	mov r0, r9
	subs r0, r1, r0
	str r0, [sp, 0x2C]
_08008710:
	adds r1, r3, r7
	mov r4, r12
	movs r5, 0x8
	ldrsh r0, [r4, r5]
	lsls r0, 3
	cmp r1, r0
	ble _08008720
	subs r7, r0, r3
_08008720:
	adds r1, r3, 0
	cmp r3, 0
	bge _08008728
	adds r1, r3, 0x7
_08008728:
	asrs r1, 3
	muls r2, r1
	mov r0, r9
	cmp r0, 0
	bge _08008734
	adds r0, 0x7
_08008734:
	asrs r0, 3
	adds r0, r2, r0
	lsls r0, 3
	lsls r1, 3
	subs r1, r3, r1
	adds r0, r1
	lsls r0, 2
	mov r2, r12
	ldr r1, [r2, 0x18]
	b _080087D6
_08008748:
	adds r2, r5, 0
	ldr r4, [sp, 0x2C]
	mov r6, r9
	mov r1, r12
	ldr r0, [r1, 0x3C]
	cmp r0, r5
	bls _08008758
	str r5, [r1, 0x3C]
_08008758:
	subs r0, r7, 0x1
	str r0, [sp, 0x4]
	adds r3, 0x1
	str r3, [sp, 0x8]
	mov r1, r12
	ldr r1, [r1, 0x40]
	str r1, [sp]
	adds r0, r5, 0x4
	mov r10, r0
	cmp r4, 0
	ble _080087B6
	ldr r1, _0800878C
	mov r8, r1
	movs r7, 0x7
_08008774:
	cmp r4, 0x7
	bgt _08008790
	adds r3, r4, 0
	adds r0, r4, 0
	ands r0, r7
	adds r0, 0x8
	lsls r0, 2
	add r0, r8
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	b _080087AA
	.align 2, 0
_0800878C: .4byte gUnknown_80B8868
_08008790:
	adds r1, r6, 0
	ands r1, r7
	cmp r1, 0
	beq _080087A8
	movs r0, 0x8
	subs r3, r0, r1
	lsls r0, r1, 2
	add r0, r8
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	b _080087AA
_080087A8:
	movs r3, 0x8
_080087AA:
	str r1, [r2]
	adds r2, 0x20
	subs r4, r3
	adds r6, r3
	cmp r4, 0
	bgt _08008774
_080087B6:
	ldr r7, [sp, 0x4]
	ldr r3, [sp, 0x8]
	ldr r2, [sp]
	cmp r2, r5
	bcs _080087C4
	mov r4, r12
	str r5, [r4, 0x40]
_080087C4:
	mov r5, r10
	movs r0, 0x7
	ands r0, r3
	cmp r0, 0
	bne _080087D8
	mov r5, r12
	ldr r0, [r5, 0x20]
	lsls r0, 2
	mov r1, r10
_080087D6:
	adds r5, r1, r0
_080087D8:
	cmp r7, 0
	bgt _08008748
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80086C8

	thumb_func_start sub_80087EC
sub_80087EC:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x18]
	ldr r0, _08008810
	str r3, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8008818
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008810: .4byte gUnknown_2027370
	thumb_func_end sub_80087EC

	thumb_func_start nullsub_176
nullsub_176:
	bx lr
	thumb_func_end nullsub_176

	thumb_func_start sub_8008818
sub_8008818:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r3, 0
	ldr r7, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	mov r12, r3
	lsls r3, r1, 3
	adds r3, r1
	lsls r3, 3
	adds r4, r0, r3
	cmp r2, 0
	bge _08008834
	adds r2, 0x7
_08008834:
	asrs r2, 3
	mov r8, r2
	adds r3, r5, 0
	cmp r3, 0
	bge _08008840
	adds r3, 0x7
_08008840:
	asrs r3, 3
	movs r2, 0
	cmp r2, r12
	bge _08008892
_08008848:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	muls r0, r3
	add r0, r8
	lsls r0, 5
	ldr r1, [r4, 0x18]
	adds r1, r0
	movs r5, 0
	adds r3, 0x1
	adds r6, r2, 0
	adds r6, 0x8
	cmp r5, r7
	bge _0800888C
	movs r2, 0
_08008864:
	ldr r0, [r4, 0x3C]
	cmp r0, r1
	bls _0800886C
	str r1, [r4, 0x3C]
_0800886C:
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	stm r1!, {r2}
	str r2, [r1]
	ldr r0, [r4, 0x40]
	cmp r0, r1
	bcs _08008884
	str r1, [r4, 0x40]
_08008884:
	adds r1, 0x4
	adds r5, 0x8
	cmp r5, r7
	blt _08008864
_0800888C:
	adds r2, r6, 0
	cmp r2, r12
	blt _08008848
_08008892:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8008818

	thumb_func_start xxx_call_update_bg_vram
xxx_call_update_bg_vram:
	push {lr}
	movs r1, 0
	ldr r2, _080088C0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080088AE
	strb r1, [r2]
	bl sub_80099C0
_080088AE:
	ldr r0, _080088C4
	bl xxx_update_bg_vram
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r1, 0
	pop {r1}
	bx r1
	.align 2, 0
_080088C0: .4byte gUnknown_20274A5
_080088C4: .4byte gUnknown_2027370
	thumb_func_end xxx_call_update_bg_vram

	thumb_func_start xxx_update_bg_vram
xxx_update_bg_vram:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r2, 0
	movs r1, 0
	movs r7, 0xD0
	lsls r7, 4
_080088D8:
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 3
	mov r3, r8
	adds r4, r3, r0
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	adds r6, r1, 0x1
	cmp r0, 0
	beq _0800897A
	ldr r5, [r4, 0x38]
	cmp r5, 0
	beq _0800897A
	adds r0, r4, 0
	adds r0, 0x45
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800894C
	ldr r0, [r4, 0x28]
	ldr r1, [r4, 0x18]
	adds r2, r7, 0
	bl CpuCopy
	ldr r0, [r4, 0x18]
	adds r2, r0, r7
	ldr r0, [r4, 0x28]
	adds r1, r0, r7
	movs r3, 0
	b _08008938
_08008912:
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldm r2!, {r0}
	stm r1!, {r0}
	ldr r0, _08008944
	stm r1!, {r0}
	ldr r0, _08008948
	stm r1!, {r0}
	movs r0, 0x1
	negs r0, r0
	stm r1!, {r0}
	adds r2, 0xC
	adds r3, 0x1
_08008938:
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	cmp r3, r0
	blt _08008912
	movs r0, 0
	b _0800896A
	.align 2, 0
_08008944: .4byte 0xdddddddd
_08008948: .4byte 0xeeeeeeee
_0800894C:
	ldr r0, [r4, 0x30]
	ldr r1, [r4, 0x34]
	adds r2, r5, 0
	bl CpuCopy
	lsrs r1, r5, 2
	lsls r1, 2
	ldr r0, [r4, 0x34]
	adds r0, r1
	str r0, [r4, 0x34]
	ldr r0, [r4, 0x30]
	adds r0, r5
	str r0, [r4, 0x30]
	ldr r0, [r4, 0x38]
	subs r0, r5
_0800896A:
	str r0, [r4, 0x38]
	ldr r1, [r4, 0x38]
	cmp r1, 0
	bne _08008978
	adds r0, r4, 0
	adds r0, 0x44
	strb r1, [r0]
_08008978:
	movs r2, 0x1
_0800897A:
	adds r1, r6, 0
	cmp r1, 0x3
	ble _080088D8
	adds r0, r2, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end xxx_update_bg_vram

	thumb_func_start sub_800898C
sub_800898C:
	push {lr}
	ldr r1, _080089A4
	ldr r2, _080089A8
	movs r3, 0xA0
	lsls r3, 1
	adds r0, r1, r3
_08008998:
	strh r2, [r0]
	subs r0, 0x2
	cmp r0, r1
	bge _08008998
	pop {r0}
	bx r0
	.align 2, 0
_080089A4: .4byte gUnknown_3000E94
_080089A8: .4byte 0x0000f0f0
	thumb_func_end sub_800898C

	thumb_func_start sub_80089AC
sub_80089AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r1, [r4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080089C8
	b _08008C44
_080089C8:
	ldr r6, _08008A3C
	ldr r7, [r4, 0x4]
	cmp r7, 0x1
	bne _08008A60
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	movs r1, 0
	ldrsh r0, [r5, r1]
	adds r2, r0
	lsls r3, r2, 3
	mov r12, r3
	movs r7, 0xA
	ldrsh r1, [r4, r7]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	adds r1, r0
	lsls r5, r1, 3
	movs r7, 0xC
	ldrsh r0, [r4, r7]
	adds r2, r0
	lsls r7, r2, 3
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	adds r1, r0
	lsls r2, r1, 3
	cmp r0, 0
	bne _08008A00
	b _08008C44
_08008A00:
	cmp r5, 0
	bge _08008A06
	movs r5, 0
_08008A06:
	cmp r2, 0
	bge _08008A0C
	movs r2, 0
_08008A0C:
	cmp r5, 0xA0
	ble _08008A12
	movs r5, 0xA0
_08008A12:
	cmp r2, 0xA0
	ble _08008A18
	movs r2, 0xA0
_08008A18:
	cmp r5, r2
	blt _08008A1E
	b _08008C44
_08008A1E:
	lsls r3, r5, 1
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, 0xF0
	bne _08008A40
	ldrb r0, [r1, 0x1]
	cmp r0, 0xF0
	bne _08008A40
	strb r7, [r1]
	adds r3, 0x1
	adds r0, r6, r3
	mov r1, r12
	strb r1, [r0]
	b _08008A58
	.align 2, 0
_08008A3C: .4byte gUnknown_3000E94
_08008A40:
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, r7
	bge _08008A4A
	strb r7, [r1]
_08008A4A:
	adds r3, 0x1
	adds r3, r6, r3
	ldrb r0, [r3]
	cmp r0, r12
	ble _08008A58
	mov r0, r12
	strb r0, [r3]
_08008A58:
	adds r5, 0x1
	cmp r5, r2
	blt _08008A1E
	b _08008C44
_08008A60:
	cmp r7, 0x6
	beq _08008A66
	b _08008BA8
_08008A66:
	movs r2, 0x8
	ldrsh r1, [r4, r2]
	movs r3, 0
	ldrsh r0, [r5, r3]
	adds r1, r0
	lsls r3, r1, 3
	subs r7, r3, 0x5
	mov r9, r7
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	movs r7, 0x2
	ldrsh r2, [r5, r7]
	adds r0, r2
	lsls r2, r0, 3
	subs r5, r2, 0x4
	movs r7, 0xC
	ldrsh r2, [r4, r7]
	adds r1, r2
	lsls r1, 3
	adds r1, 0x5
	str r1, [sp]
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	adds r0, r1
	lsls r0, 3
	adds r0, 0x5
	mov r8, r0
	adds r3, 0x3
	mov r12, r3
	ldr r2, [r4, 0x14]
	ldrb r1, [r2, 0x2]
	subs r0, r1, 0x1
	ldrb r3, [r2]
	adds r0, r3
	adds r0, 0x2
	lsls r0, 3
	add r0, r12
	subs r0, 0x4
	mov r10, r0
	ldrb r0, [r2, 0x1]
	adds r0, 0x1
	lsls r0, 3
	mov r7, r9
	adds r4, r7, r0
	adds r1, 0x2
	lsls r1, 3
	adds r1, r4, r1
	subs r7, r1, 0x4
	cmp r5, 0
	bge _08008ACC
	movs r5, 0
_08008ACC:
	mov r0, r8
	cmp r0, 0
	bge _08008AD6
	movs r1, 0
	mov r8, r1
_08008AD6:
	cmp r5, 0xA0
	ble _08008ADC
	movs r5, 0xA0
_08008ADC:
	mov r2, r8
	cmp r2, 0xA0
	ble _08008AE6
	movs r3, 0xA0
	mov r8, r3
_08008AE6:
	movs r3, 0x3
_08008AE8:
	lsls r2, r5, 1
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, 0xF0
	bne _08008B02
	ldrb r0, [r1, 0x1]
	cmp r0, 0xF0
	bne _08008B02
	strb r7, [r1]
	adds r2, 0x1
	adds r0, r6, r2
	strb r4, [r0]
	b _08008B18
_08008B02:
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, r7
	bge _08008B0C
	strb r7, [r1]
_08008B0C:
	adds r2, 0x1
	adds r2, r6, r2
	ldrb r0, [r2]
	cmp r0, r4
	ble _08008B18
	strb r4, [r2]
_08008B18:
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08008AE8
	movs r3, 0x7
_08008B22:
	lsls r1, r5, 1
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, 0xF0
	bne _08008B40
	ldrb r0, [r2, 0x1]
	cmp r0, 0xF0
	bne _08008B40
	mov r7, r10
	strb r7, [r2]
	adds r1, 0x1
	adds r0, r6, r1
	mov r1, r12
	strb r1, [r0]
	b _08008B5A
_08008B40:
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, r10
	bge _08008B4C
	mov r7, r10
	strb r7, [r2]
_08008B4C:
	adds r1, 0x1
	adds r1, r6, r1
	ldrb r0, [r1]
	cmp r0, r12
	ble _08008B5A
	mov r0, r12
	strb r0, [r1]
_08008B5A:
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08008B22
	cmp r5, r8
	bge _08008C44
_08008B66:
	lsls r1, r5, 1
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, 0xF0
	bne _08008B86
	ldrb r0, [r2, 0x1]
	cmp r0, 0xF0
	bne _08008B86
	mov r3, sp
	ldrb r3, [r3]
	strb r3, [r2]
	adds r1, 0x1
	adds r0, r6, r1
	mov r7, r9
	strb r7, [r0]
	b _08008BA0
_08008B86:
	adds r2, r6, r1
	ldrb r0, [r2]
	ldr r3, [sp]
	cmp r0, r3
	bge _08008B92
	strb r3, [r2]
_08008B92:
	adds r1, 0x1
	adds r1, r6, r1
	ldrb r0, [r1]
	cmp r0, r9
	ble _08008BA0
	mov r0, r9
	strb r0, [r1]
_08008BA0:
	adds r5, 0x1
	cmp r5, r8
	blt _08008B66
	b _08008C44
_08008BA8:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	movs r2, 0
	ldrsh r1, [r5, r2]
	adds r0, r1
	lsls r1, r0, 3
	subs r1, 0x5
	mov r8, r1
	movs r3, 0xA
	ldrsh r2, [r4, r3]
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	adds r2, r1
	lsls r5, r2, 3
	mov r9, r5
	mov r3, r9
	subs r3, 0x5
	movs r5, 0xC
	ldrsh r1, [r4, r5]
	adds r0, r1
	lsls r0, 3
	adds r0, 0x5
	mov r12, r0
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	adds r2, r0
	lsls r1, r2, 3
	adds r5, r1, 0x5
	cmp r0, 0
	beq _08008C44
	cmp r7, 0
	bne _08008BEC
	adds r3, 0x8
	subs r5, r1, 0x3
_08008BEC:
	cmp r3, 0
	bge _08008BF2
	movs r3, 0
_08008BF2:
	cmp r5, 0
	bge _08008BF8
	movs r5, 0
_08008BF8:
	cmp r3, 0xA0
	ble _08008BFE
	movs r3, 0xA0
_08008BFE:
	cmp r5, 0xA0
	ble _08008C40
	movs r5, 0xA0
	b _08008C40
_08008C06:
	lsls r1, r3, 1
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, 0xF0
	bne _08008C24
	ldrb r0, [r2, 0x1]
	cmp r0, 0xF0
	bne _08008C24
	mov r7, r12
	strb r7, [r2]
	adds r1, 0x1
	adds r0, r6, r1
	mov r1, r8
	strb r1, [r0]
	b _08008C3E
_08008C24:
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, r12
	bge _08008C30
	mov r7, r12
	strb r7, [r2]
_08008C30:
	adds r1, 0x1
	adds r1, r6, r1
	ldrb r0, [r1]
	cmp r0, r8
	ble _08008C3E
	mov r0, r8
	strb r0, [r1]
_08008C3E:
	adds r3, 0x1
_08008C40:
	cmp r3, r5
	blt _08008C06
_08008C44:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80089AC

	thumb_func_start sub_8008C54
sub_8008C54:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08008C64
	bl sub_8008C6C
	pop {r0}
	bx r0
	.align 2, 0
_08008C64: .4byte gUnknown_2027370
	thumb_func_end sub_8008C54

	thumb_func_start nullsub_169
nullsub_169:
	bx lr
	thumb_func_end nullsub_169

	thumb_func_start sub_8008C6C
sub_8008C6C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r0
	mov r8, r1
	lsls r0, r1, 3
	add r0, r8
	lsls r0, 3
	mov r1, r9
	adds r6, r1, r0
	adds r0, r6, 0
	adds r0, 0x45
	ldrb r0, [r0]
	cmp r0, 0
	bne _08008CBE
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	movs r7, 0x8
	ldrsh r1, [r6, r7]
	muls r0, r1
	lsls r4, r0, 5
	movs r5, 0
	movs r0, 0x44
	adds r0, r6
	mov r10, r0
	cmp r5, r4
	bge _08008D1E
_08008CA8:
	lsrs r1, r5, 2
	lsls r1, 2
	ldr r0, [r6, 0x18]
	adds r0, r1
	movs r1, 0x20
	bl CpuClear
	adds r5, 0x20
	cmp r5, r4
	blt _08008CA8
	b _08008D1E
_08008CBE:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	movs r2, 0x8
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	muls r1, r0
	lsls r1, 5
	str r1, [sp, 0x8]
	ldr r4, [r6, 0x18]
	movs r5, 0
	movs r7, 0x44
	adds r7, r6
	mov r10, r7
	cmp r5, r0
	bge _08008D04
	movs r0, 0x1
	negs r0, r0
	mov r12, r0
	movs r1, 0
	ldr r3, _08008D84
	ldr r2, _08008D88
_08008CE8:
	mov r7, r12
	stm r4!, {r7}
	stm r4!, {r3}
	stm r4!, {r2}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	stm r4!, {r1}
	adds r5, 0x1
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	cmp r5, r0
	blt _08008CE8
_08008D04:
	movs r5, 0
	ldr r0, [sp, 0x8]
	cmp r5, r0
	bge _08008D1E
_08008D0C:
	adds r0, r4, 0
	movs r1, 0x20
	bl CpuClear
	adds r4, 0x20
	adds r5, 0x20
	ldr r1, [sp, 0x8]
	cmp r5, r1
	blt _08008D0C
_08008D1E:
	ldr r0, [r6, 0xC]
	cmp r0, 0x6
	bne _08008D60
	adds r5, r6, 0
	adds r5, 0x46
	movs r4, 0
	movs r0, 0x1
	strb r0, [r5]
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	lsls r0, 3
	str r0, [sp]
	movs r0, 0xE
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r2, 0
	movs r3, 0xA
	bl sub_8007958
	movs r7, 0x4
	ldrsh r0, [r6, r7]
	lsls r0, 3
	str r0, [sp]
	movs r0, 0xD
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r2, 0
	movs r3, 0xB
	bl sub_8007958
	strb r4, [r5]
_08008D60:
	ldr r0, [r6, 0x28]
	str r0, [r6, 0x30]
	ldr r0, [r6, 0x1C]
	str r0, [r6, 0x34]
	ldr r0, [r6, 0x2C]
	str r0, [r6, 0x38]
	movs r0, 0x1
	mov r1, r10
	strb r0, [r1]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008D84: .4byte 0xeeeeeeee
_08008D88: .4byte 0xdddddddd
	thumb_func_end sub_8008C6C

	thumb_func_start sub_8008D8C
sub_8008D8C:
	push {lr}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08008DA4
	adds r1, r0
	ldr r0, [r1, 0x38]
	cmp r0, 0
	beq _08008DA0
	movs r0, 0x1
_08008DA0:
	pop {r1}
	bx r1
	.align 2, 0
_08008DA4: .4byte gUnknown_2027370
	thumb_func_end sub_8008D8C

	thumb_func_start sub_8008DA8
sub_8008DA8:
	movs r0, 0
	bx lr
	thumb_func_end sub_8008DA8

	thumb_func_start sub_8008DAC
sub_8008DAC:
	ldr r3, _08008DC0
	lsls r0, 1
	lsls r1, 6
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	ldr r1, _08008DC4
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08008DC0: .4byte gUnknown_202B038
_08008DC4: .4byte gUnknown_20274A5
	thumb_func_end sub_8008DAC

	thumb_func_start sub_8008DC8
sub_8008DC8:
	push {r4,lr}
	ldr r4, _08008DEC
	lsls r0, 1
	lsls r1, 6
	adds r0, r1
	adds r1, r0, r4
	strh r2, [r1]
	movs r1, 0x80
	lsls r1, 4
	adds r4, r1
	adds r0, r4
	strh r3, [r0]
	ldr r1, _08008DF0
	movs r0, 0x1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008DEC: .4byte gUnknown_202B038
_08008DF0: .4byte gUnknown_20274A5
	thumb_func_end sub_8008DC8

	thumb_func_start sub_8008DF4
sub_8008DF4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldrb r0, [r3]
	ldr r1, _08008E4C
	mov r12, r1
	cmp r0, 0
	beq _08008E3E
	ldr r6, _08008E50
_08008E08:
	ldrb r1, [r3]
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _08008E1E
	adds r0, r1, 0
	subs r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_08008E1E:
	lsls r2, r4, 1
	lsls r0, r5, 6
	adds r2, r0
	adds r2, r6
	movs r7, 0x96
	lsls r7, 2
	adds r0, r1, r7
	ldr r7, _08008E54
	adds r1, r7, 0
	orrs r0, r1
	strh r0, [r2]
	adds r3, 0x1
	adds r4, 0x1
	ldrb r0, [r3]
	cmp r0, 0
	bne _08008E08
_08008E3E:
	movs r0, 0x1
	mov r1, r12
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008E4C: .4byte gUnknown_20274A5
_08008E50: .4byte gUnknown_202B038
_08008E54: .4byte 0xfffff000
	thumb_func_end sub_8008DF4

	thumb_func_start sub_8008E58
sub_8008E58:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	mov r8, r1
	adds r4, r2, 0
	ldrb r0, [r4]
	ldr r7, _08008EC4
	cmp r0, 0
	beq _08008EB4
	adds r1, r0, 0
	cmp r3, 0
	beq _08008EB4
	ldr r0, _08008EC8
	mov r12, r0
_08008E76:
	adds r0, r1, 0
	subs r0, 0x61
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _08008E8A
	adds r0, r1, 0
	subs r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_08008E8A:
	lsls r2, r5, 1
	mov r6, r8
	lsls r0, r6, 6
	adds r2, r0
	add r2, r12
	movs r6, 0x96
	lsls r6, 2
	adds r0, r1, r6
	ldr r6, _08008ECC
	adds r1, r6, 0
	orrs r0, r1
	strh r0, [r2]
	adds r4, 0x1
	adds r5, 0x1
	subs r3, 0x1
	ldrb r0, [r4]
	cmp r0, 0
	beq _08008EB4
	adds r1, r0, 0
	cmp r3, 0
	bne _08008E76
_08008EB4:
	movs r0, 0x1
	strb r0, [r7]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008EC4: .4byte gUnknown_20274A5
_08008EC8: .4byte gUnknown_202B038
_08008ECC: .4byte 0xfffff000
	thumb_func_end sub_8008E58

	thumb_func_start sub_8008ED0
sub_8008ED0:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r5, 0
	b _08008F64
_08008EDA:
	ldr r0, _08008F18
	cmp r1, r0
	beq _08008F64
	adds r0, 0x2
	cmp r1, r0
	beq _08008F64
	cmp r1, 0x1B
	beq _08008F7E
	cmp r1, 0x23
	bne _08008F44
	ldrb r0, [r2]
	cmp r0, 0x6E
	beq _08008F7E
	cmp r0, 0x5B
	beq _08008F7E
	cmp r0, 0x50
	beq _08008F7E
	cmp r0, 0x57
	beq _08008F40
	cmp r0, 0x57
	bgt _08008F22
	cmp r0, 0x43
	beq _08008F38
	cmp r0, 0x43
	bgt _08008F1C
	cmp r0, 0x2B
	beq _08008F40
	cmp r0, 0x3D
	beq _08008F34
	b _08008F64
	.align 2, 0
_08008F18: .4byte 0x000082a0
_08008F1C:
	cmp r0, 0x52
	beq _08008F3C
	b _08008F64
_08008F22:
	cmp r0, 0x72
	beq _08008F3C
	cmp r0, 0x72
	bgt _08008F30
	cmp r0, 0x63
	beq _08008F38
	b _08008F64
_08008F30:
	cmp r0, 0x7E
	bne _08008F64
_08008F34:
	adds r4, r2, 0x2
	b _08008F64
_08008F38:
	adds r4, 0x2
	b _08008F64
_08008F3C:
	adds r4, 0x1
	b _08008F64
_08008F40:
	adds r4, r2, 0x1
	b _08008F64
_08008F44:
	cmp r1, 0x60
	bne _08008F4C
	adds r5, 0x6
	b _08008F64
_08008F4C:
	adds r0, r1, 0
	bl sub_8008584
	cmp r0, 0
	beq _08008F64
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	ldr r1, _08008F88
	movs r2, 0
	ldrsh r1, [r1, r2]
	adds r0, r1
	adds r5, r0
_08008F64:
	adds r0, r4, 0
	mov r1, sp
	bl xxx_get_next_char_from_string
	adds r2, r0, 0
	adds r4, r2, 0
	ldr r1, [sp]
	cmp r1, 0
	beq _08008F7E
	cmp r1, 0xD
	beq _08008F7E
	cmp r1, 0xA
	bne _08008EDA
_08008F7E:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08008F88: .4byte gUnknown_2027498
	thumb_func_end sub_8008ED0

	thumb_func_start sub_8008F8C
sub_8008F8C:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r2, [sp, 0x24]
	ldr r0, _08008FB8
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008FB8: .4byte gUnknown_2027370
	thumb_func_end sub_8008F8C

	thumb_func_start xxx_call_draw_string
xxx_call_draw_string:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r0, _08008FE8
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0xD
	str r1, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008FE8: .4byte gUnknown_2027370
	thumb_func_end xxx_call_draw_string

	thumb_func_start nullsub_170
nullsub_170:
	bx lr
	thumb_func_end nullsub_170

	thumb_func_start sub_8008FF0
sub_8008FF0:
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r1, [sp, 0x20]
	ldr r0, _0800901C
	str r3, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0xD
	str r1, [sp, 0xC]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl xxx_draw_string
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800901C: .4byte gUnknown_2027370
	thumb_func_end sub_8008FF0

	thumb_func_start nullsub_171
nullsub_171:
	bx lr
	thumb_func_end nullsub_171

	thumb_func_start xxx_draw_string
xxx_draw_string:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x40
	adds r5, r0, 0
	adds r4, r3, 0
	ldr r0, [sp, 0x5C]
	mov r8, r0
	ldr r7, [sp, 0x64]
	add r0, sp, 0x8
	strh r1, [r0]
	strh r2, [r0, 0x2]
	str r1, [sp, 0x14]
	movs r0, 0x7
	str r0, [sp, 0x18]
	add r2, sp, 0x3C
	mov r9, r2
	b _08009128
_0800904A:
	ldr r0, _08009058
	cmp r3, r0
	bne _08009060
	ldr r1, _0800905C
	movs r0, 0
	str r0, [r1]
	b _08009128
	.align 2, 0
_08009058: .4byte 0x000082a0
_0800905C: .4byte gUnknown_20274AC
_08009060:
	ldr r0, _08009070
	cmp r3, r0
	bne _08009078
	ldr r1, _08009074
	movs r0, 0x1
	str r0, [r1]
	b _08009128
	.align 2, 0
_08009070: .4byte 0x000082a2
_08009074: .4byte gUnknown_20274AC
_08009078:
	cmp r3, 0x1B
	beq _0800914A
	cmp r3, 0xD
	beq _08009084
	cmp r3, 0xA
	bne _08009096
_08009084:
	add r1, sp, 0x8
	ldr r0, [sp, 0x14]
	strh r0, [r1]
	adds r0, r1, 0
	ldrh r0, [r0, 0x2]
	ldr r3, [sp, 0x68]
	adds r0, r3
	strh r0, [r1, 0x2]
	b _08009128
_08009096:
	cmp r3, 0x1D
	bne _080090AA
	add r1, sp, 0x8
	ldr r0, [sp, 0x14]
	strh r0, [r1]
	adds r0, r1, 0
	ldrh r0, [r0, 0x2]
	adds r0, 0x5
	strh r0, [r1, 0x2]
	b _08009128
_080090AA:
	cmp r3, 0x60
	bne _080090B8
	add r1, sp, 0x8
	adds r0, r1, 0
	ldrh r0, [r0]
	adds r0, 0x6
	b _08009126
_080090B8:
	cmp r7, 0
	bne _080090E0
	add r0, sp, 0x8
	movs r6, 0
	ldrsh r1, [r0, r6]
	movs r6, 0x2
	ldrsh r2, [r0, r6]
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	bl xxx_draw_char
	add r2, sp, 0x8
	adds r1, r2, 0
	ldrh r1, [r1]
	adds r1, r0
	strh r1, [r2]
	b _08009128
_080090E0:
	adds r0, r3, 0
	bl sub_8008584
	adds r2, r0, 0
	cmp r2, 0
	beq _08009128
	add r0, sp, 0x8
	movs r3, 0
	ldrsh r1, [r0, r3]
	ldr r0, _08009158
	movs r6, 0
	ldrsh r0, [r0, r6]
	adds r0, 0xA
	movs r3, 0x6
	ldrsh r2, [r2, r3]
	subs r0, r2
	lsrs r2, r0, 31
	adds r0, r2
	asrs r0, 1
	adds r1, r0
	add r0, sp, 0x8
	movs r6, 0x2
	ldrsh r2, [r0, r6]
	ldr r3, [sp, 0x3C]
	ldr r0, [sp, 0x18]
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	adds r0, r5, 0
	bl xxx_draw_char
	add r1, sp, 0x8
	adds r0, r1, 0
	ldrh r0, [r0]
	adds r0, r7
_08009126:
	strh r0, [r1]
_08009128:
	adds r0, r5, 0
	adds r1, r4, 0
	add r2, sp, 0x8
	bl sub_80091AC
	adds r4, r0, 0
	mov r1, r9
	bl xxx_get_next_char_from_string
	adds r4, r0, 0
	ldr r3, [sp, 0x3C]
	cmp r3, 0
	beq _0800914A
	ldr r2, [sp, 0x60]
	cmp r3, r2
	beq _0800914A
	b _0800904A
_0800914A:
	add sp, 0x40
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009158: .4byte gUnknown_2027498
	thumb_func_end xxx_draw_string

	thumb_func_start sub_800915C
sub_800915C:
	push {r4,lr}
	adds r3, r0, 0
	movs r2, 0
_08009162:
	ldrb r0, [r1]
	cmp r0, 0x2E
	beq _08009184
	subs r0, 0x30
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bhi _08009186
	lsls r0, r2, 2
	adds r0, r2
	lsls r2, r0, 1
	adds r0, r2, 0
	subs r0, 0x30
	ldrb r4, [r1]
	adds r2, r0, r4
	adds r1, 0x1
	b _08009162
_08009184:
	adds r1, 0x1
_08009186:
	strh r2, [r3]
	adds r0, r1, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800915C

	thumb_func_start sub_8009190
sub_8009190:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080091A4
	adds r1, r3, 0
	bl sub_80091AC
	pop {r1}
	bx r1
	.align 2, 0
_080091A4: .4byte gUnknown_2027370
	thumb_func_end sub_8009190

	thumb_func_start sub_80091A8
sub_80091A8:
	adds r0, 0x1
	bx lr
	thumb_func_end sub_80091A8

	thumb_func_start sub_80091AC
sub_80091AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	movs r0, 0
	mov r9, r0
	movs r7, 0x1
_080091C0:
	ldrb r0, [r4]
	cmp r0, 0x23
	beq _080091C8
	b _0800937A
_080091C8:
	ldrb r0, [r4, 0x1]
	adds r1, r0, 0
	cmp r1, 0x5B
	bne _08009216
	adds r2, r4, 0
	adds r4, 0x2
	adds r0, r5, 0
	adds r0, 0x21
	mov r1, r9
	strb r1, [r0]
	ldrb r1, [r4]
	adds r6, r0, 0
	cmp r1, 0
	beq _080091F6
	cmp r1, 0x5D
	beq _080091F4
_080091E8:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0
	beq _080091F6
	cmp r0, 0x5D
	bne _080091E8
_080091F4:
	adds r4, 0x1
_080091F6:
	ldr r3, [r5, 0x24]
	cmp r3, 0
	beq _0800920C
	adds r0, r2, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl _call_via_r3
	cmp r0, 0
	beq _0800920C
	adds r4, r0, 0
_0800920C:
	ldrb r0, [r6]
	cmp r0, 0
	beq _08009214
	b _0800937A
_08009214:
	b _080091C0
_08009216:
	cmp r1, 0x3D
	bne _08009220
	ldrb r0, [r4, 0x2]
	strh r0, [r5]
	b _080092BA
_08009220:
	cmp r1, 0x79
	bne _0800922A
	ldrb r0, [r4, 0x2]
	strh r0, [r5, 0x2]
	b _080092BA
_0800922A:
	cmp r1, 0x3E
	bne _0800923A
	adds r1, r4, 0x2
	adds r0, r5, 0
	bl sub_800915C
	adds r4, r0, 0
	b _080091C0
_0800923A:
	cmp r1, 0x2E
	bne _08009246
	ldrh r0, [r5]
	ldrb r2, [r4, 0x2]
	adds r0, r2
	b _0800926E
_08009246:
	cmp r1, 0x6E
	bne _08009258
	ldr r0, [r5, 0xC]
	strh r0, [r5]
	ldrh r0, [r5, 0x2]
	adds r0, 0xB
	strh r0, [r5, 0x2]
	adds r4, 0x2
	b _080091C0
_08009258:
	cmp r1, 0x3A
	bne _08009264
	ldrh r0, [r5]
	strh r0, [r5, 0x4]
	adds r4, 0x2
	b _080091C0
_08009264:
	cmp r1, 0x3B
	bne _08009274
	ldrh r0, [r5, 0x4]
	ldrb r3, [r4, 0x2]
	adds r0, r3
_0800926E:
	strh r0, [r5]
	adds r4, 0x3
	b _080091C0
_08009274:
	cmp r1, 0x2B
	bne _0800929A
	adds r4, 0x2
	adds r0, r4, 0
	bl sub_8008ED0
	mov r2, r8
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	lsls r1, 3
	subs r1, r0
	strh r1, [r5]
	movs r1, 0
	ldrsh r0, [r5, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r5]
	b _080091C0
_0800929A:
	cmp r1, 0x43
	bne _080092A4
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x14]
	b _080092DC
_080092A4:
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5F
	bne _080092CC
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x14]
	ldr r1, _080092C8
	ldrb r0, [r4, 0x2]
	adds r0, r1
	ldrb r0, [r0]
	str r0, [r5, 0x10]
_080092BA:
	adds r4, 0x3
	ldrb r0, [r4]
	cmp r0, 0x2E
	beq _080092C4
	b _080091C0
_080092C4:
	adds r4, 0x1
	b _080091C0
	.align 2, 0
_080092C8: .4byte gUnknown_202749A
_080092CC:
	cmp r0, 0x52
	bne _080092D4
	ldr r0, [r5, 0x14]
	b _080092EE
_080092D4:
	cmp r0, 0x63
	bne _080092E8
	ldr r0, [r5, 0x10]
	str r0, [r5, 0x18]
_080092DC:
	ldrb r0, [r4, 0x2]
	bl sub_800963C
	str r0, [r5, 0x10]
	adds r4, 0x3
	b _080091C0
_080092E8:
	cmp r0, 0x72
	bne _080092F4
	ldr r0, [r5, 0x18]
_080092EE:
	str r0, [r5, 0x10]
	adds r4, 0x2
	b _080091C0
_080092F4:
	cmp r0, 0x53
	bne _08009314
	ldr r3, _08009310
	ldrb r2, [r4, 0x2]
	movs r0, 0x7F
	adds r1, r0, 0
	ands r1, r2
	adds r1, r3
	ldrb r2, [r4, 0x3]
	ands r0, r2
	strb r0, [r1]
	adds r4, 0x4
	b _080091C0
	.align 2, 0
_08009310: .4byte gUnknown_20274A6
_08009314:
	cmp r0, 0x57
	bne _0800933A
	adds r4, 0x2
	mov r2, r8
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 3
	ldrh r1, [r5]
	adds r0, r1
	subs r0, 0x2
	strh r0, [r5, 0x8]
	movs r3, 0x2
	ldrsh r0, [r2, r3]
	lsls r0, 3
	ldrh r1, [r5, 0x2]
	adds r0, r1
	adds r0, 0x3
	strh r0, [r5, 0xA]
	b _0800935C
_0800933A:
	cmp r0, 0x50
	bne _08009350
	adds r4, 0x2
	ldr r0, _0800934C
	strh r0, [r5, 0x2]
	mov r2, r9
	str r2, [r5, 0x1C]
	b _0800935C
	.align 2, 0
_0800934C: .4byte 0x0000270f
_08009350:
	cmp r0, 0x70
	bne _08009368
	adds r4, 0x2
	ldr r0, _08009364
	strh r0, [r5, 0x2]
	str r7, [r5, 0x1C]
_0800935C:
	adds r0, r5, 0
	adds r0, 0x20
	strb r7, [r0]
	b _0800937A
	.align 2, 0
_08009364: .4byte 0x0000270f
_08009368:
	cmp r0, 0x7E
	bne _0800937A
	ldrb r0, [r4, 0x2]
	str r0, [r5, 0x2C]
	adds r0, r5, 0
	adds r0, 0x21
	strb r7, [r0]
	adds r4, 0x3
	b _080091C0
_0800937A:
	adds r0, r4, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80091AC

	thumb_func_start sub_8009388
sub_8009388:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r2, _080093F4
	ldr r6, _080093F8
	strh r6, [r2]
	movs r0, 0x80
	lsls r0, 4
	adds r5, r2, r0
	ldr r4, _080093FC
	strh r4, [r5]
	ldr r0, _08009400
	ldr r3, [r0]
	ldr r0, _08009404
	ldr r1, [r0]
	mov r9, r0
	cmp r3, r1
	bge _080093E6
	mov r8, r2
	mov r12, r6
	adds r6, r5, 0
	movs r5, 0
	adds r7, r6, 0
_080093B8:
	lsls r0, r3, 6
	mov r1, r8
	adds r2, r0, r1
	mov r1, r12
	strh r1, [r2]
	adds r1, r0, r6
	strh r4, [r1]
	adds r3, 0x1
	adds r0, r7
	adds r0, 0x2
	adds r2, 0x2
	movs r1, 0x1E
_080093D0:
	strh r5, [r2]
	strh r4, [r0]
	adds r0, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _080093D0
	mov r1, r9
	ldr r0, [r1]
	cmp r3, r0
	blt _080093B8
_080093E6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080093F4: .4byte gUnknown_202B038
_080093F8: .4byte 0x0000f279
_080093FC: .4byte 0x0000f27a
_08009400: .4byte gUnknown_202B020
_08009404: .4byte gUnknown_202B024
	thumb_func_end sub_8009388

	thumb_func_start sub_8009408
sub_8009408:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r1, 0
	ldr r1, _08009478
	ldr r6, _0800947C
	strh r6, [r1]
	movs r2, 0x80
	lsls r2, 4
	adds r4, r1, r2
	ldr r2, _08009480
	strh r2, [r4]
	adds r3, r0, 0
	ldr r0, _08009484
	mov r10, r0
	cmp r3, r5
	bge _08009464
	mov r9, r1
	mov r8, r6
	adds r7, r4, 0
	adds r4, r2, 0
	movs r6, 0
	mov r12, r7
_0800943A:
	lsls r0, r3, 6
	mov r1, r9
	adds r2, r0, r1
	mov r1, r8
	strh r1, [r2]
	adds r1, r0, r7
	strh r4, [r1]
	adds r3, 0x1
	add r0, r12
	adds r0, 0x2
	adds r2, 0x2
	movs r1, 0x1E
_08009452:
	strh r6, [r2]
	strh r4, [r0]
	adds r0, 0x2
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _08009452
	cmp r3, r5
	blt _0800943A
_08009464:
	movs r0, 0x1
	mov r2, r10
	strb r0, [r2]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009478: .4byte gUnknown_202B038
_0800947C: .4byte 0x0000f279
_08009480: .4byte 0x0000f27a
_08009484: .4byte gUnknown_20274A5
	thumb_func_end sub_8009408

	thumb_func_start sub_8009488
sub_8009488:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _08009514
	adds r4, r1, r0
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	movs r3, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r3, r0
	bge _08009506
	ldr r6, _08009518
	mov r9, r6
	ldr r0, _0800951C
	mov r8, r0
	movs r2, 0x80
	lsls r2, 4
	add r2, r8
	mov r10, r2
_080094BA:
	movs r6, 0
	ldrsh r2, [r4, r6]
	movs r5, 0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	adds r6, r1, 0x1
	adds r7, r3, 0x1
	cmp r5, r0
	bge _080094FA
	movs r0, 0xFC
	lsls r0, 8
	mov r12, r0
	lsls r2, 1
	lsls r1, 6
	mov r3, r10
	adds r0, r1, r3
	adds r3, r2, r0
	add r1, r8
	adds r2, r1
_080094E0:
	ldrh r0, [r2]
	mov r1, r12
	ands r1, r0
	strh r1, [r2]
	mov r0, r9
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _080094E0
_080094FA:
	adds r1, r6, 0
	adds r3, r7, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	cmp r3, r0
	blt _080094BA
_08009506:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009514: .4byte gUnknown_2027370
_08009518: .4byte 0x0000f27a
_0800951C: .4byte gUnknown_202B038
	thumb_func_end sub_8009488

	thumb_func_start nullsub_172
nullsub_172:
	bx lr
	thumb_func_end nullsub_172

	thumb_func_start sub_8009524
sub_8009524:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	ldr r0, _080095BC
	adds r4, r1, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	subs r1, r0, 0x1
	movs r3, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	adds r0, 0x2
	cmp r3, r0
	bge _080095AE
	ldr r6, _080095C0
	mov r9, r6
	ldr r0, _080095C4
	mov r8, r0
	movs r2, 0x80
	lsls r2, 4
	add r2, r8
	mov r10, r2
_0800955A:
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r2, r0, 0x1
	movs r5, 0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	adds r0, 0x2
	adds r6, r1, 0x1
	adds r7, r3, 0x1
	cmp r5, r0
	bge _080095A0
	movs r0, 0xFC
	lsls r0, 8
	mov r12, r0
	lsls r2, 1
	lsls r1, 6
	mov r3, r10
	adds r0, r1, r3
	adds r3, r2, r0
	add r1, r8
	adds r2, r1
_08009584:
	ldrh r0, [r2]
	mov r1, r12
	ands r1, r0
	strh r1, [r2]
	mov r0, r9
	strh r0, [r3]
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x1
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r0, 0x2
	cmp r5, r0
	blt _08009584
_080095A0:
	adds r1, r6, 0
	adds r3, r7, 0
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	adds r0, 0x2
	cmp r3, r0
	blt _0800955A
_080095AE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080095BC: .4byte gUnknown_2027370
_080095C0: .4byte 0x0000f27a
_080095C4: .4byte gUnknown_202B038
	thumb_func_end sub_8009524

	thumb_func_start nullsub_173
nullsub_173:
	bx lr
	thumb_func_end nullsub_173

	thumb_func_start sub_80095CC
sub_80095CC:
	ldr r2, _080095D8
	str r0, [r2]
	ldr r0, _080095DC
	str r1, [r0]
	bx lr
	.align 2, 0
_080095D8: .4byte gUnknown_202B020
_080095DC: .4byte gUnknown_202B024
	thumb_func_end sub_80095CC

	thumb_func_start nullsub_174
nullsub_174:
	bx lr
	thumb_func_end nullsub_174

	thumb_func_start sub_80095E4
sub_80095E4:
	push {lr}
	cmp r1, 0
	bne _080095EC
	movs r1, 0xA
_080095EC:
	muls r1, r0
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08009604
	adds r0, r1, 0
	cmp r1, 0
	bge _080095FE
	adds r0, r1, 0x7
_080095FE:
	asrs r0, 3
	adds r0, 0x1
	b _0800960E
_08009604:
	adds r0, r1, 0
	cmp r0, 0
	bge _0800960C
	adds r0, 0x7
_0800960C:
	asrs r0, 3
_0800960E:
	pop {r1}
	bx r1
	thumb_func_end sub_80095E4

	thumb_func_start sub_8009614
sub_8009614:
	push {lr}
	muls r1, r0
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0800962E
	adds r0, r1, 0
	cmp r1, 0
	bge _08009628
	adds r0, r1, 0x7
_08009628:
	asrs r0, 3
	adds r0, 0x1
	b _08009638
_0800962E:
	adds r0, r1, 0
	cmp r0, 0
	bge _08009636
	adds r0, 0x7
_08009636:
	asrs r0, 3
_08009638:
	pop {r1}
	bx r1
	thumb_func_end sub_8009614

	thumb_func_start sub_800963C
sub_800963C:
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r2, r0, 0
	cmp r0, 0xF
	bls _080096DA
	adds r1, r0, 0
	subs r1, 0x30
	lsls r0, r1, 24
	lsrs r0, 24
	cmp r0, 0xF
	bhi _08009658
	adds r0, r1, 0
	b _080096DA
_08009658:
	adds r0, r2, 0
	subs r0, 0x43
	cmp r0, 0x14
	bhi _080096D8
	lsls r0, 2
	ldr r1, _0800966C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800966C: .4byte _08009670
	.align 2, 0
_08009670:
	.4byte _080096D0
	.4byte _080096D0
	.4byte _080096C8
	.4byte _080096D8
	.4byte _080096CC
	.4byte _080096C4
	.4byte _080096C4
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096CC
	.4byte _080096D0
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096C8
	.4byte _080096C8
	.4byte _080096D8
	.4byte _080096D8
	.4byte _080096D4
_080096C4:
	movs r0, 0x4
	b _080096DA
_080096C8:
	movs r0, 0xF
	b _080096DA
_080096CC:
	movs r0, 0x5
	b _080096DA
_080096D0:
	movs r0, 0x6
	b _080096DA
_080096D4:
	movs r0, 0x2
	b _080096DA
_080096D8:
	movs r0, 0x7
_080096DA:
	pop {r1}
	bx r1
	thumb_func_end sub_800963C

	thumb_func_start sub_80096E0
sub_80096E0:
	push {r4-r6,lr}
	ldr r1, _0800978C
	movs r0, 0x1
	strb r0, [r1]
	movs r1, 0xC0
	lsls r1, 19
	movs r5, 0
	ldr r3, _08009790
	ldr r0, _08009794
	movs r2, 0
_080096F4:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, r3
	bls _080096F4
	movs r1, 0xA0
	lsls r1, 19
	movs r5, 0
	movs r2, 0
_08009704:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, 0xFF
	bls _08009704
	movs r1, 0xE0
	lsls r1, 19
	movs r5, 0
	ldr r2, _08009798
_08009714:
	stm r1!, {r2}
	adds r5, 0x1
	cmp r5, 0xFF
	bls _08009714
	ldr r4, _0800979C
	adds r1, r4, 0
	bl sub_800A9EC
	adds r6, r0, 0
	ldr r1, [r6, 0x4]
	ldm r1!, {r5}
	ldr r0, _080097A0
	lsls r2, r5, 5
	bl CpuCopy
	adds r0, r6, 0
	bl sub_800AA14
	ldr r0, _080097A4
	adds r1, r4, 0
	bl sub_800A9EC
	adds r6, r0, 0
	ldr r1, [r6, 0x4]
	ldm r1!, {r5}
	ldr r0, _080097A8
	lsls r2, r5, 5
	bl CpuCopy
	adds r0, r6, 0
	bl sub_800AA14
	bl sub_80097B0
	ldr r0, _080097AC
	adds r1, r4, 0
	bl sub_800A9EC
	adds r6, r0, 0
	ldr r4, [r6, 0x4]
	movs r5, 0
_08009766:
	movs r1, 0xF8
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r4, 0
	bl SetBGPaletteBufferColorArray
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08009766
	adds r0, r6, 0
	bl sub_800AA14
	bl TransferBGPaletteBuffer
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800978C: .4byte gUnknown_203B090
_08009790: .4byte 0x00005fff
_08009794: .4byte gUnknown_80B88B0
_08009798: .4byte 0x00a000a0
_0800979C: .4byte gUnknown_8300500
_080097A0: .4byte 0x06004f00
_080097A4: .4byte gUnknown_80B88B8
_080097A8: .4byte 0x06017e00
_080097AC: .4byte gUnknown_80B88C0
	thumb_func_end sub_80096E0

	thumb_func_start sub_80097B0
sub_80097B0:
	push {r4-r6,lr}
	ldr r0, _080097F8
	ldr r1, _080097FC
	bl sub_800A9EC
	adds r6, r0, 0
	ldr r4, _08009800
	ldr r1, [r6, 0x4]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r4, 0
	bl CpuCopy
	bl sub_80063B0
	adds r5, r4, 0
	adds r5, 0x40
	cmp r0, 0x1
	bne _080097D8
	adds r5, r4, 0
_080097D8:
	movs r4, 0
_080097DA:
	adds r0, r4, 0
	adds r0, 0xF0
	adds r1, r5, 0
	bl SetBGPaletteBufferColorArray
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xF
	ble _080097DA
	adds r0, r6, 0
	bl sub_800AA14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080097F8: .4byte gUnknown_80B88CC
_080097FC: .4byte gUnknown_8300500
_08009800: .4byte gUnknown_202D038
	thumb_func_end sub_80097B0

	thumb_func_start sub_8009804
sub_8009804:
	push {lr}
	movs r1, 0xC0
	lsls r1, 19
	movs r0, 0
	ldr r3, _0800987C
	movs r2, 0
_08009810:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009810
	ldr r1, _08009880
	movs r0, 0
	ldr r3, _08009884
	movs r2, 0
_08009820:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009820
	ldr r1, _08009888
	movs r0, 0
	ldr r3, _0800988C
	movs r2, 0
_08009830:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009830
	ldr r1, _08009890
	movs r0, 0
	ldr r3, _08009894
	movs r2, 0
_08009840:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, r3
	bls _08009840
	movs r1, 0xA0
	lsls r1, 19
	movs r0, 0
	movs r2, 0
_08009850:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, 0x77
	bls _08009850
	ldr r1, _08009898
	movs r0, 0
	movs r2, 0
_0800985E:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, 0x77
	bls _0800985E
	movs r1, 0xE0
	lsls r1, 19
	movs r0, 0
	ldr r2, _0800989C
_0800986E:
	stm r1!, {r2}
	adds r0, 0x1
	cmp r0, 0xFF
	bls _0800986E
	pop {r0}
	bx r0
	.align 2, 0
_0800987C: .4byte 0x000013bf
_08009880: .4byte 0x06007000
_08009884: .4byte 0x000003ff
_08009888: .4byte 0x06008000
_0800988C: .4byte 0x00001fff
_08009890: .4byte 0x06010000
_08009894: .4byte 0x00001f7f
_08009898: .4byte 0x05000200
_0800989C: .4byte 0x00a000a0
	thumb_func_end sub_8009804

	thumb_func_start sub_80098A0
sub_80098A0:
	ldr r0, _080098B4
	movs r1, 0
	str r1, [r0]
	ldr r0, _080098B8
	strb r1, [r0]
	strb r1, [r0, 0x1]
	strb r1, [r0, 0x2]
	strb r1, [r0, 0x3]
	bx lr
	.align 2, 0
_080098B4: .4byte gUnknown_202D23C
_080098B8: .4byte gUnknown_202D238
	thumb_func_end sub_80098A0

	thumb_func_start sub_80098BC
sub_80098BC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	ldr r7, _080098F0
	ldr r3, [r7]
	cmp r3, 0x7
	bgt _080098E8
	ldr r2, _080098F4
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r0, r1, r2
	str r4, [r0]
	adds r0, r2, 0x4
	adds r0, r1, r0
	str r5, [r0]
	adds r2, 0x8
	adds r1, r2
	str r6, [r1]
	adds r0, r3, 0x1
	str r0, [r7]
_080098E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080098F0: .4byte gUnknown_202D23C
_080098F4: .4byte gUnknown_202D240
	thumb_func_end sub_80098BC

	thumb_func_start sub_80098F8
sub_80098F8:
	ldr r1, _08009904
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08009904: .4byte gUnknown_202D238
	thumb_func_end sub_80098F8

	thumb_func_start sub_8009908
sub_8009908:
	push {r4-r7,lr}
	movs r5, 0
	ldr r0, _08009994
	ldr r0, [r0]
	cmp r5, r0
	bge _08009936
	ldr r4, _08009998
	adds r7, r4, 0
	movs r6, 0
_0800991A:
	ldr r0, [r4]
	adds r1, r7, 0x4
	adds r1, r6, r1
	ldr r1, [r1]
	ldr r2, [r4, 0x8]
	bl CpuCopy
	adds r4, 0xC
	adds r6, 0xC
	adds r5, 0x1
	ldr r0, _08009994
	ldr r0, [r0]
	cmp r5, r0
	blt _0800991A
_08009936:
	ldr r0, _08009994
	movs r5, 0
	str r5, [r0]
	ldr r4, _0800999C
	ldrb r0, [r4]
	cmp r0, 0
	beq _08009952
	strb r5, [r4]
	ldr r0, _080099A0
	ldr r1, _080099A4
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_08009952:
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08009966
	strb r5, [r4, 0x1]
	ldr r0, _080099A8
	ldr r1, _080099AC
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_08009966:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _0800997A
	strb r5, [r4, 0x2]
	ldr r0, _080099B0
	ldr r1, _080099B4
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_0800997A:
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _0800998E
	strb r5, [r4, 0x3]
	ldr r0, _080099B8
	ldr r1, _080099BC
	movs r2, 0x80
	lsls r2, 4
	bl CpuCopy
_0800998E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009994: .4byte gUnknown_202D23C
_08009998: .4byte gUnknown_202D240
_0800999C: .4byte gUnknown_202D238
_080099A0: .4byte 0x06006000
_080099A4: .4byte gUnknown_202B038
_080099A8: .4byte 0x06006800
_080099AC: .4byte gUnknown_202B838
_080099B0: .4byte 0x06007000
_080099B4: .4byte gUnknown_202C038
_080099B8: .4byte 0x06007800
_080099BC: .4byte gUnknown_202C838
	thumb_func_end sub_8009908

	thumb_func_start sub_80099C0
sub_80099C0:
	push {r4,r5,lr}
	ldr r0, _080099E4
	ldr r4, _080099E8
	movs r5, 0x80
	lsls r5, 4
	adds r1, r4, 0
	adds r2, r5, 0
	bl CpuCopy
	ldr r0, _080099EC
	adds r4, r5
	adds r1, r4, 0
	adds r2, r5, 0
	bl CpuCopy
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080099E4: .4byte 0x06006000
_080099E8: .4byte gUnknown_202B038
_080099EC: .4byte 0x06006800
	thumb_func_end sub_80099C0

	thumb_func_start sub_80099F0
sub_80099F0:
	push {lr}
	adds r2, r0, 0
	ldr r0, _08009A0C
	movs r1, 0x7
	movs r3, 0xE2
	lsls r3, 1
	adds r0, r3
_080099FE:
	str r2, [r0]
	subs r0, 0x40
	subs r1, 0x1
	cmp r1, 0
	bge _080099FE
	pop {r0}
	bx r0
	.align 2, 0
_08009A0C: .4byte gUnknown_202D038
	thumb_func_end sub_80099F0

	thumb_func_start sub_8009A10
sub_8009A10:
	push {lr}
	ldr r0, [r0, 0x4]
	bl sub_8009A1C
	pop {r0}
	bx r0
	thumb_func_end sub_8009A10

	thumb_func_start sub_8009A1C
sub_8009A1C:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r0, _08009A30
	str r3, [r0]
	ldr r3, [r6, 0xC]
	movs r0, 0xC0
	lsls r0, 19
	adds r2, r0
	movs r5, 0
	b _08009A56
	.align 2, 0
_08009A30: .4byte gUnknown_202D2A0
_08009A34:
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	ldm r3!, {r0}
	stm r2!, {r0}
	adds r5, 0x1
_08009A56:
	ldr r0, [r6, 0x8]
	cmp r5, r0
	ble _08009A34
	movs r5, 0
	lsls r4, r1, 6
_08009A60:
	adds r0, r5, 0
	adds r0, 0xE0
	ldr r1, [r6, 0x10]
	adds r1, r4
	bl SetBGPaletteBufferColorArray
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, 0xF
	ble _08009A60
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8009A1C

	thumb_func_start sub_8009A7C
sub_8009A7C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	adds r5, r1, 0
	str r2, [sp, 0x4]
	str r3, [sp, 0x8]
	ldr r0, [sp, 0x38]
	ldr r3, [sp, 0x40]
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _08009AB4
	ldr r1, [r0]
	movs r2, 0
	str r2, [sp, 0x10]
	cmp r1, 0
	bne _08009AA8
	movs r7, 0x1
	str r7, [sp, 0x10]
_08009AA8:
	ldr r1, [sp]
	ldr r0, [r1]
	cmp r5, r0
	blt _08009AB8
	movs r0, 0
	b _08009BCE
	.align 2, 0
_08009AB4: .4byte gUnknown_202D2A0
_08009AB8:
	lsls r5, 2
	mov r8, r5
	cmp r4, 0
	beq _08009AFA
	movs r0, 0
	ldr r2, _08009B74
	mov r10, r2
	ldr r4, _08009B78
	mov r9, r4
	ldr r1, [sp, 0x10]
	lsls r7, r1, 1
_08009ACE:
	ldr r2, [sp, 0x10]
	adds r4, r0, 0x1
	mov r12, r4
	cmp r2, 0x1D
	bgt _08009AF4
	mov r6, r10
	mov r5, r9
	movs r4, 0
	lsls r0, 6
	adds r1, r7, r0
_08009AE2:
	ldr r0, [r5]
	lsls r0, 11
	adds r0, r1, r0
	adds r0, r6
	strh r4, [r0]
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x1D
	ble _08009AE2
_08009AF4:
	mov r0, r12
	cmp r0, 0x13
	ble _08009ACE
_08009AFA:
	ldr r7, [sp]
	ldr r0, [r7, 0x4]
	add r0, r8
	ldr r5, [r0]
	ldrh r0, [r5, 0x4]
	mov r9, r0
	ldrh r1, [r5, 0x6]
	str r1, [sp, 0xC]
	ldr r2, [sp, 0x3C]
	cmp r2, 0
	beq _08009B14
	ldrh r0, [r5, 0x8]
	str r0, [r2]
_08009B14:
	cmp r3, 0
	beq _08009B28
	ldrh r0, [r5, 0xA]
	strh r0, [r3]
	ldrh r0, [r5, 0xC]
	strh r0, [r3, 0x2]
	ldrh r0, [r5, 0xE]
	strh r0, [r3, 0x4]
	ldrh r0, [r5, 0x10]
	strh r0, [r3, 0x6]
_08009B28:
	adds r5, 0x14
	ldr r4, [sp, 0x8]
	str r4, [sp, 0x14]
	movs r6, 0
	movs r0, 0
	ldr r7, [sp, 0xC]
	cmp r0, r7
	bge _08009BC4
	cmp r4, 0x13
	bgt _08009BC4
_08009B3C:
	ldr r3, [sp, 0x4]
	adds r0, 0x1
	mov r12, r0
	ldr r0, [sp, 0x14]
	adds r0, 0x1
	mov r8, r0
	mov r1, r9
	cmp r1, 0
	beq _08009BB4
	ldr r2, _08009B74
	mov r10, r2
	mov r2, r9
_08009B54:
	cmp r6, 0
	bne _08009B80
	ldrh r1, [r5]
	adds r5, 0x2
	adds r0, r1, 0
	movs r4, 0xF0
	lsls r4, 8
	ands r0, r4
	cmp r0, 0
	bne _08009B6E
	ldr r6, _08009B7C
	ands r6, r1
	movs r1, 0
_08009B6E:
	adds r4, r1, 0
	b _08009B82
	.align 2, 0
_08009B74: .4byte gUnknown_202B038
_08009B78: .4byte gUnknown_202D2A0
_08009B7C: .4byte 0x000003ff
_08009B80:
	movs r4, 0
_08009B82:
	cmp r6, 0
	beq _08009B88
	subs r6, 0x1
_08009B88:
	ldr r7, [sp, 0x10]
	cmp r3, r7
	blt _08009BAC
	cmp r3, 0x1D
	bgt _08009BAC
	ldr r0, [sp, 0x14]
	cmp r0, 0
	blt _08009BAC
	lsls r0, r3, 1
	ldr r7, [sp, 0x14]
	lsls r1, r7, 6
	adds r0, r1
	ldr r7, _08009BE0
	ldr r1, [r7]
	lsls r1, 11
	adds r0, r1
	add r0, r10
	strh r4, [r0]
_08009BAC:
	subs r2, 0x1
	adds r3, 0x1
	cmp r2, 0
	bne _08009B54
_08009BB4:
	mov r0, r12
	mov r1, r8
	str r1, [sp, 0x14]
	ldr r2, [sp, 0xC]
	cmp r0, r2
	bge _08009BC4
	cmp r1, 0x13
	ble _08009B3C
_08009BC4:
	ldr r4, _08009BE0
	ldr r0, [r4]
	bl sub_80098F8
	movs r0, 0x1
_08009BCE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08009BE0: .4byte gUnknown_202D2A0
	thumb_func_end sub_8009A7C

	thumb_func_start sub_8009BE4
sub_8009BE4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0x20
	mov r12, r0
	ldr r0, _08009C54
	ldr r1, [r0]
	movs r2, 0
	mov r10, r2
	mov r9, r0
	cmp r1, 0
	bne _08009C04
	movs r7, 0x1
	mov r10, r7
_08009C04:
	movs r0, 0
	mov r1, r10
	lsls r1, 1
	mov r8, r1
_08009C0C:
	mov r1, r10
	adds r3, r0, 0x1
	cmp r1, r12
	bge _08009C36
	ldr r6, _08009C58
	ldr r5, _08009C54
	movs r4, 0
	lsls r0, 6
	mov r7, r8
	adds r2, r7, r0
	mov r0, r12
	subs r1, r0, r1
_08009C24:
	ldr r0, [r5]
	lsls r0, 11
	adds r0, r2, r0
	adds r0, r6
	strh r4, [r0]
	adds r2, 0x2
	subs r1, 0x1
	cmp r1, 0
	bne _08009C24
_08009C36:
	adds r0, r3, 0
	cmp r0, 0x1F
	ble _08009C0C
	mov r1, r9
	ldr r0, [r1]
	bl sub_80098F8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009C54: .4byte gUnknown_202D2A0
_08009C58: .4byte gUnknown_202B038
	thumb_func_end sub_8009BE4

	thumb_func_start sub_8009C5C
sub_8009C5C:
	push {lr}
	adds r1, r0, 0
	cmp r1, 0xFF
	ble _08009C6C
	movs r1, 0x3
	bl __modsi3
	b _08009C72
_08009C6C:
	ldr r0, _08009C78
	adds r0, r1, r0
	ldrb r0, [r0]
_08009C72:
	pop {r1}
	bx r1
	.align 2, 0
_08009C78: .4byte gUnknown_80B88E4
	thumb_func_end sub_8009C5C

	thumb_func_start sub_8009C7C
sub_8009C7C:
	push {lr}
	adds r2, r0, 0
	movs r3, 0xC0
	lsls r3, 4
	adds r1, r2, 0
	ands r1, r3
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	beq _08009CB8
	cmp r1, r0
	bgt _08009C9A
	cmp r1, 0
	beq _08009CA8
	b _08009CFC
_08009C9A:
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	beq _08009CD0
	cmp r1, r3
	beq _08009CE0
	b _08009CFC
_08009CA8:
	ldr r0, _08009CB0
	ldr r1, _08009CB4
	ands r1, r2
	b _08009CBE
	.align 2, 0
_08009CB0: .4byte gUnknown_80B8AE4
_08009CB4: .4byte 0x000003ff
_08009CB8:
	ldr r0, _08009CC8
	ldr r1, _08009CCC
	bics r1, r2
_08009CBE:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	b _08009CFE
	.align 2, 0
_08009CC8: .4byte gUnknown_80B8AE4
_08009CCC: .4byte 0x000003ff
_08009CD0:
	ldr r0, _08009CD8
	ldr r1, _08009CDC
	ands r1, r2
	b _08009CE6
	.align 2, 0
_08009CD8: .4byte gUnknown_80B8AE4
_08009CDC: .4byte 0x000003ff
_08009CE0:
	ldr r0, _08009CF4
	ldr r1, _08009CF8
	bics r1, r2
_08009CE6:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	negs r0, r0
	b _08009CFE
	.align 2, 0
_08009CF4: .4byte gUnknown_80B8AE4
_08009CF8: .4byte 0x000003ff
_08009CFC:
	movs r0, 0
_08009CFE:
	pop {r1}
	bx r1
	thumb_func_end sub_8009C7C

	thumb_func_start sub_8009D04
sub_8009D04:
	push {lr}
	adds r2, r0, 0
	movs r3, 0xC0
	lsls r3, 4
	adds r1, r2, 0
	ands r1, r3
	movs r0, 0x80
	lsls r0, 3
	cmp r1, r0
	beq _08009D40
	cmp r1, r0
	bgt _08009D22
	cmp r1, 0
	beq _08009D30
	b _08009D84
_08009D22:
	movs r0, 0x80
	lsls r0, 4
	cmp r1, r0
	beq _08009D50
	cmp r1, r3
	beq _08009D6C
	b _08009D84
_08009D30:
	ldr r0, _08009D38
	ldr r1, _08009D3C
	bics r1, r2
	b _08009D72
	.align 2, 0
_08009D38: .4byte gUnknown_80B8AE4
_08009D3C: .4byte 0x000003ff
_08009D40:
	ldr r0, _08009D48
	ldr r1, _08009D4C
	ands r1, r2
	b _08009D56
	.align 2, 0
_08009D48: .4byte gUnknown_80B8AE4
_08009D4C: .4byte 0x000003ff
_08009D50:
	ldr r0, _08009D64
	ldr r1, _08009D68
	bics r1, r2
_08009D56:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	negs r0, r0
	b _08009D86
	.align 2, 0
_08009D64: .4byte gUnknown_80B8AE4
_08009D68: .4byte 0x000003ff
_08009D6C:
	ldr r0, _08009D7C
	ldr r1, _08009D80
	ands r1, r2
_08009D72:
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	b _08009D86
	.align 2, 0
_08009D7C: .4byte gUnknown_80B8AE4
_08009D80: .4byte 0x000003ff
_08009D84:
	movs r0, 0
_08009D86:
	pop {r1}
	bx r1
	thumb_func_end sub_8009D04

	thumb_func_start sub_8009D8C
sub_8009D8C:
	push {lr}
	cmp r0, r2
	bcc _08009D9A
	cmp r0, r2
	bhi _08009D9E
	cmp r1, r3
	bcs _08009D9E
_08009D9A:
	movs r0, 0x1
	b _08009DA0
_08009D9E:
	movs r0, 0
_08009DA0:
	pop {r1}
	bx r1
	thumb_func_end sub_8009D8C

	thumb_func_start sub_8009DA4
sub_8009DA4:
	push {r4,r5,lr}
	lsrs r2, r0, 31
	adds r5, r2, 0
	lsrs r3, r1, 31
	adds r4, r3, 0
	cmp r0, 0
	beq _08009DB6
	cmp r1, 0
	bne _08009DBA
_08009DB6:
	movs r0, 0
	b _08009DD0
_08009DBA:
	cmp r2, 0
	beq _08009DC0
	negs r0, r0
_08009DC0:
	cmp r3, 0
	beq _08009DC6
	negs r1, r1
_08009DC6:
	bl sub_8009E14
	cmp r5, r4
	beq _08009DD0
	negs r0, r0
_08009DD0:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8009DA4

	thumb_func_start sub_8009DD8
sub_8009DD8:
	push {r4,r5,lr}
	lsrs r2, r0, 31
	adds r5, r2, 0
	lsrs r3, r1, 31
	adds r4, r3, 0
	cmp r1, 0
	bne _08009DF0
	ldr r0, _08009DEC
	b _08009E0E
	.align 2, 0
_08009DEC: .4byte 0x7fffffff
_08009DF0:
	cmp r0, 0
	bne _08009DF8
	movs r0, 0
	b _08009E0E
_08009DF8:
	cmp r2, 0
	beq _08009DFE
	negs r0, r0
_08009DFE:
	cmp r3, 0
	beq _08009E04
	negs r1, r1
_08009E04:
	bl sub_8009EA0
	cmp r5, r4
	beq _08009E0E
	negs r0, r0
_08009E0E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8009DD8

	thumb_func_start sub_8009E14
sub_8009E14:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	cmp r0, 0
	beq _08009E24
	cmp r1, 0
	bne _08009E28
_08009E24:
	movs r0, 0
	b _08009E94
_08009E28:
	movs r5, 0
	adds r3, r0, 0
	mov r12, r5
	movs r6, 0
	movs r4, 0
	movs r0, 0x80
	lsls r0, 24
	mov r8, r0
	movs r7, 0x3F
	mov r9, r7
_08009E3C:
	adds r2, r4, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08009E50
	adds r4, r3
	adds r6, r5
	cmp r2, r4
	bls _08009E50
	adds r6, 0x1
_08009E50:
	lsrs r1, 1
	movs r2, 0x1
	mov r0, r12
	ands r0, r2
	cmp r0, 0
	beq _08009E60
	mov r0, r8
	orrs r1, r0
_08009E60:
	mov r7, r12
	lsrs r7, 1
	mov r12, r7
	lsls r5, 1
	adds r0, r3, 0
	mov r7, r8
	ands r0, r7
	cmp r0, 0
	beq _08009E74
	orrs r5, r2
_08009E74:
	lsls r3, 1
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r7, r9
	cmp r7, 0
	bge _08009E3C
	lsrs r1, r4, 7
	ands r1, r2
	lsrs r4, 8
	lsls r0, r6, 24
	orrs r4, r0
	cmp r1, 0
	beq _08009E92
	adds r4, 0x1
_08009E92:
	adds r0, r4, 0
_08009E94:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009E14

	thumb_func_start sub_8009EA0
sub_8009EA0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	cmp r1, 0
	bne _08009EB8
	ldr r0, _08009EB4
	b _08009F58
	.align 2, 0
_08009EB4: .4byte 0x7fffffff
_08009EB8:
	cmp r0, 0
	bne _08009EC0
	movs r0, 0
	b _08009F58
_08009EC0:
	lsrs r7, r0, 24
	lsls r6, r0, 8
	mov r10, r1
	movs r0, 0
	mov r9, r0
	movs r5, 0
	movs r4, 0
	movs r1, 0x1
	mov r8, r1
	movs r2, 0x3F
	str r2, [sp]
_08009ED6:
	lsls r5, 1
	adds r0, r4, 0
	movs r1, 0x80
	lsls r1, 24
	ands r0, r1
	cmp r0, 0
	beq _08009EE8
	mov r2, r8
	orrs r5, r2
_08009EE8:
	movs r1, 0x2
	negs r1, r1
	lsls r4, 1
	adds r0, r7, 0
	movs r2, 0x80
	lsls r2, 24
	ands r0, r2
	cmp r0, 0
	beq _08009EFE
	mov r0, r8
	orrs r4, r0
_08009EFE:
	lsls r7, 1
	adds r0, r6, 0
	movs r2, 0x80
	lsls r2, 24
	ands r0, r2
	cmp r0, 0
	beq _08009F10
	mov r0, r8
	orrs r7, r0
_08009F10:
	lsls r6, 1
	ands r6, r1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	mov r3, r10
	bl sub_8009D8C
	lsls r0, 24
	cmp r0, 0
	bne _08009F3A
	adds r0, r4, 0
	movs r1, 0x1
	mov r2, r10
	subs r4, r2
	movs r2, 0
	subs r5, r2
	cmp r0, r4
	bcs _08009F3C
	subs r5, 0x1
	b _08009F3C
_08009F3A:
	movs r1, 0
_08009F3C:
	mov r0, r9
	lsls r0, 1
	mov r9, r0
	cmp r1, 0
	beq _08009F4C
	mov r1, r8
	orrs r0, r1
	mov r9, r0
_08009F4C:
	ldr r2, [sp]
	subs r2, 0x1
	str r2, [sp]
	cmp r2, 0
	bge _08009ED6
	mov r0, r9
_08009F58:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009EA0

	thumb_func_start sub_8009F68
sub_8009F68:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r6, 0
	cmp r6, 0
	bge _08009F76
	negs r4, r6
_08009F76:
	movs r7, 0x80
	lsls r7, 1
	cmp r4, 0
	beq _08009FA0
_08009F7E:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08009F90
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_8009DA4
	adds r7, r0, 0
_08009F90:
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_8009DA4
	adds r5, r0, 0
	asrs r4, 1
	cmp r4, 0
	bne _08009F7E
_08009FA0:
	cmp r6, 0
	bge _08009FB0
	movs r0, 0x80
	lsls r0, 1
	adds r1, r7, 0
	bl sub_8009DD8
	b _08009FB2
_08009FB0:
	adds r0, r7, 0
_08009FB2:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009F68

	thumb_func_start sub_8009FB8
sub_8009FB8:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	cmp r5, 0
	bge _08009FC4
	negs r5, r5
_08009FC4:
	cmp r6, 0
	bge _08009FCA
	negs r6, r6
_08009FCA:
	cmp r5, r6
	bge _08009FD4
	adds r4, r5, 0
	adds r5, r6, 0
	adds r6, r4, 0
_08009FD4:
	cmp r6, 0
	beq _0800A016
	movs r7, 0x2
_08009FDA:
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8009DD8
	adds r4, r0, 0
	adds r1, r4, 0
	bl sub_8009DA4
	adds r4, r0, 0
	movs r0, 0x80
	lsls r0, 3
	adds r1, r4, r0
	adds r0, r4, 0
	bl sub_8009DD8
	adds r4, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8009DA4
	lsls r0, 1
	adds r5, r0
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8009DA4
	adds r6, r0, 0
	subs r7, 0x1
	cmp r7, 0
	bge _08009FDA
_0800A016:
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8009FB8

	thumb_func_start sub_800A020
sub_800A020:
	push {r4,lr}
	adds r3, r0, 0
	ldr r4, _0800A044
	lsrs r2, r1, 16
	str r2, [r3]
	lsls r0, r1, 16
	str r0, [r3, 0x4]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _0800A03C
	orrs r2, r4
	str r2, [r3]
_0800A03C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A044: .4byte 0xffff0000
	thumb_func_end sub_800A020

	thumb_func_start sub_800A048
sub_800A048:
	push {lr}
	ldrh r1, [r0]
	lsls r2, r1, 16
	ldr r0, [r0, 0x4]
	lsrs r1, r0, 16
	orrs r2, r1
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0800A060
	adds r2, 0x1
_0800A060:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_800A048

	thumb_func_start sub_800A068
sub_800A068:
	push {lr}
	ldrb r1, [r0]
	lsls r2, r1, 24
	ldr r0, [r0, 0x4]
	lsrs r1, r0, 8
	orrs r2, r1
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0800A080
	adds r2, 0x1
_0800A080:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_800A068

	thumb_func_start sub_800A088
sub_800A088:
	push {lr}
	adds r2, r0, 0
	lsls r0, r1, 8
	str r0, [r2, 0x4]
	asrs r1, 24
	str r1, [r2]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0800A0A4
	movs r0, 0x80
	negs r0, r0
	orrs r1, r0
	b _0800A0A8
_0800A0A4:
	movs r0, 0x7F
	ands r1, r0
_0800A0A8:
	str r1, [r2]
	pop {r0}
	bx r0
	thumb_func_end sub_800A088

	thumb_func_start sub_800A0B0
sub_800A0B0:
	push {lr}
	ldr r2, [r0, 0x4]
	ldr r3, [r0]
	cmp r2, 0
	bne _0800A0C2
	cmp r3, 0
	bne _0800A0C2
	movs r0, 0
	b _0800A254
_0800A0C2:
	cmp r2, 0
	ble _0800A18C
	cmp r3, 0
	ble _0800A124
	cmp r2, r3
	bge _0800A0F0
	asrs r1, r3, 8
	cmp r1, 0
	beq _0800A0FE
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A0E2
	movs r2, 0xFF
_0800A0E2:
	ldr r0, _0800A0EC
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	b _0800A252
	.align 2, 0
_0800A0EC: .4byte gUnknown_80B92E4
_0800A0F0:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A0F8
	adds r1, 0xFF
_0800A0F8:
	asrs r1, 8
	cmp r1, 0
	bne _0800A104
_0800A0FE:
	movs r0, 0x80
	lsls r0, 2
	b _0800A254
_0800A104:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A112
	movs r2, 0xFF
_0800A112:
	ldr r1, _0800A120
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x40
	b _0800A250
	.align 2, 0
_0800A120: .4byte gUnknown_80B92E4
_0800A124:
	negs r3, r3
	cmp r2, r3
	bge _0800A158
	adds r1, r3, 0
	cmp r3, 0
	bge _0800A132
	adds r1, 0xFF
_0800A132:
	asrs r1, 8
	cmp r1, 0
	beq _0800A166
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A146
	movs r2, 0xFF
_0800A146:
	ldr r1, _0800A154
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	b _0800A250
	.align 2, 0
_0800A154: .4byte gUnknown_80B92E4
_0800A158:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A160
	adds r1, 0xFF
_0800A160:
	asrs r1, 8
	cmp r1, 0
	bne _0800A16C
_0800A166:
	movs r0, 0xC0
	lsls r0, 3
	b _0800A254
_0800A16C:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A17A
	movs r2, 0xFF
_0800A17A:
	ldr r0, _0800A188
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x40
	b _0800A252
	.align 2, 0
_0800A188: .4byte gUnknown_80B92E4
_0800A18C:
	negs r2, r2
	cmp r3, 0
	ble _0800A1F0
	cmp r2, r3
	bge _0800A1BC
	asrs r1, r3, 8
	cmp r1, 0
	beq _0800A1CA
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A1AA
	movs r2, 0xFF
_0800A1AA:
	ldr r1, _0800A1B8
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	b _0800A250
	.align 2, 0
_0800A1B8: .4byte gUnknown_80B92E4
_0800A1BC:
	adds r1, r2, 0
	cmp r2, 0
	bge _0800A1C4
	adds r1, 0xFF
_0800A1C4:
	asrs r1, 8
	cmp r1, 0
	bne _0800A1D0
_0800A1CA:
	movs r0, 0xE0
	lsls r0, 4
	b _0800A254
_0800A1D0:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A1DE
	movs r2, 0xFF
_0800A1DE:
	ldr r0, _0800A1EC
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0xC0
	b _0800A252
	.align 2, 0
_0800A1EC: .4byte gUnknown_80B92E4
_0800A1F0:
	negs r3, r3
	cmp r2, r3
	bge _0800A224
	adds r1, r3, 0
	cmp r3, 0
	bge _0800A1FE
	adds r1, 0xFF
_0800A1FE:
	asrs r1, 8
	cmp r1, 0
	beq _0800A232
	adds r0, r2, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A212
	movs r2, 0xFF
_0800A212:
	ldr r0, _0800A220
	lsls r1, r2, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x80
	b _0800A252
	.align 2, 0
_0800A220: .4byte gUnknown_80B92E4
_0800A224:
	adds r0, r2, 0
	cmp r0, 0
	bge _0800A22C
	adds r0, 0xFF
_0800A22C:
	asrs r1, r0, 8
	cmp r1, 0
	bne _0800A238
_0800A232:
	movs r0, 0xA0
	lsls r0, 4
	b _0800A254
_0800A238:
	adds r0, r3, 0
	bl __divsi3
	adds r2, r0, 0
	cmp r2, 0xFF
	ble _0800A246
	movs r2, 0xFF
_0800A246:
	ldr r1, _0800A258
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0xC0
_0800A250:
	subs r0, r1
_0800A252:
	lsls r0, 4
_0800A254:
	pop {r1}
	bx r1
	.align 2, 0
_0800A258: .4byte gUnknown_80B92E4
	thumb_func_end sub_800A0B0

	thumb_func_start sub_800A25C
sub_800A25C:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	mvns r2, r0
	str r2, [r1]
	ldr r0, [r1, 0x4]
	mvns r0, r0
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A276
	adds r0, r2, 0x1
	str r0, [r1]
_0800A276:
	pop {r0}
	bx r0
	thumb_func_end sub_800A25C

	thumb_func_start sub_800A27C
sub_800A27C:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bge _0800A29A
	mvns r2, r0
	str r2, [r1]
	ldr r0, [r1, 0x4]
	mvns r0, r0
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A29A
	adds r0, r2, 0x1
	str r0, [r1]
_0800A29A:
	pop {r0}
	bx r0
	thumb_func_end sub_800A27C

	thumb_func_start sub_800A2A0
sub_800A2A0:
	push {lr}
	adds r1, r0, 0
	ldr r0, [r1]
	cmp r0, 0
	bne _0800A2B4
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _0800A2B4
	movs r0, 0x1
	b _0800A2B6
_0800A2B4:
	movs r0, 0
_0800A2B6:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2A0

	thumb_func_start sub_800A2BC
sub_800A2BC:
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _0800A2D6
	ldr r1, [r2, 0x4]
	ldr r0, [r3, 0x4]
	cmp r1, r0
	bne _0800A2D6
	movs r0, 0x1
	b _0800A2D8
_0800A2D6:
	movs r0, 0
_0800A2D8:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2BC

	thumb_func_start sub_800A2DC
sub_800A2DC:
	push {lr}
	ldr r0, [r0]
	cmp r0, 0
	blt _0800A2E8
	movs r0, 0
	b _0800A2EA
_0800A2E8:
	movs r0, 0x1
_0800A2EA:
	pop {r1}
	bx r1
	thumb_func_end sub_800A2DC

	thumb_func_start sub_800A2F0
sub_800A2F0:
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r4, [r3]
	lsrs r1, r4, 31
	ldr r5, [r2]
	cmp r5, 0
	bge _0800A304
	movs r0, 0x2
	orrs r1, r0
_0800A304:
	cmp r1, 0x1
	beq _0800A326
	cmp r1, 0x1
	ble _0800A314
	cmp r1, 0x2
	beq _0800A32A
	cmp r1, 0x3
	beq _0800A32E
_0800A314:
	ldr r1, [r3, 0x4]
	ldr r3, [r2, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8009D8C
	lsls r0, 24
	lsrs r0, 24
	b _0800A346
_0800A326:
	movs r0, 0x1
	b _0800A346
_0800A32A:
	movs r0, 0
	b _0800A346
_0800A32E:
	ldr r1, [r3, 0x4]
	ldr r3, [r2, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8009D8C
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _0800A344
	movs r1, 0x1
_0800A344:
	adds r0, r1, 0
_0800A346:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800A2F0

	thumb_func_start sub_800A34C
sub_800A34C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	ldr r0, [r2]
	str r0, [sp, 0x8]
	ldr r0, [r2, 0x4]
	add r5, sp, 0x8
	str r0, [r5, 0x4]
	mov r0, sp
	bl sub_800A2DC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r10, r8
	adds r0, r5, 0
	bl sub_800A2DC
	lsls r0, 24
	lsrs r7, r0, 24
	mov r9, r7
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A39A
	movs r0, 0
	str r0, [r6]
	b _0800A3DE
_0800A39A:
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A3AC
	str r4, [r6]
	str r4, [r6, 0x4]
	b _0800A3E0
_0800A3AC:
	mov r0, r8
	cmp r0, 0
	beq _0800A3B8
	mov r0, sp
	bl sub_800A25C
_0800A3B8:
	cmp r7, 0
	beq _0800A3C2
	adds r0, r5, 0
	bl sub_800A25C
_0800A3C2:
	add r4, sp, 0x10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_800A4E4
	cmp r10, r9
	beq _0800A3D8
	adds r0, r4, 0
	bl sub_800A25C
_0800A3D8:
	ldr r0, [sp, 0x10]
	str r0, [r6]
	ldr r0, [r4, 0x4]
_0800A3DE:
	str r0, [r6, 0x4]
_0800A3E0:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A34C

	thumb_func_start sub_800A3F0
sub_800A3F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	ldr r0, [r2]
	str r0, [sp, 0x8]
	ldr r0, [r2, 0x4]
	add r5, sp, 0x8
	str r0, [r5, 0x4]
	mov r0, sp
	bl sub_800A2DC
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r10, r8
	adds r0, r5, 0
	bl sub_800A2DC
	lsls r0, 24
	lsrs r7, r0, 24
	mov r9, r7
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A448
	ldr r0, _0800A444
	str r0, [r6]
	movs r0, 0x1
	negs r0, r0
	b _0800A48C
	.align 2, 0
_0800A444: .4byte 0x7fffffff
_0800A448:
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A45A
	str r4, [r6]
	str r4, [r6, 0x4]
	b _0800A48E
_0800A45A:
	mov r0, r8
	cmp r0, 0
	beq _0800A466
	mov r0, sp
	bl sub_800A25C
_0800A466:
	cmp r7, 0
	beq _0800A470
	adds r0, r5, 0
	bl sub_800A25C
_0800A470:
	add r4, sp, 0x10
	adds r0, r4, 0
	mov r1, sp
	adds r2, r5, 0
	bl sub_800A5A4
	cmp r10, r9
	beq _0800A486
	adds r0, r4, 0
	bl sub_800A25C
_0800A486:
	ldr r0, [sp, 0x10]
	str r0, [r6]
	ldr r0, [r4, 0x4]
_0800A48C:
	str r0, [r6, 0x4]
_0800A48E:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A3F0

	thumb_func_start sub_800A4A0
sub_800A4A0:
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r0, [r5]
	str r0, [sp]
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	mov r0, sp
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A4C0
	movs r0, 0
	str r0, [r5]
	b _0800A4D8
_0800A4C0:
	mov r0, sp
	bl sub_800A27C
	add r4, sp, 0x8
	adds r0, r4, 0
	mov r1, sp
	mov r2, sp
	bl sub_800A4E4
	ldr r0, [sp, 0x8]
	str r0, [r5]
	ldr r0, [r4, 0x4]
_0800A4D8:
	str r0, [r5, 0x4]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800A4A0

	thumb_func_start sub_800A4E4
sub_800A4E4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A50C
	movs r0, 0
	mov r1, r8
	str r0, [r1]
	str r0, [r1, 0x4]
	b _0800A596
_0800A50C:
	adds r0, r6, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A520
	mov r7, r8
	str r4, [r7]
	str r4, [r7, 0x4]
	b _0800A596
_0800A520:
	ldr r1, [r5]
	ldr r4, [r5, 0x4]
	ldr r0, [r6]
	mov r10, r0
	ldr r2, [r6, 0x4]
	movs r6, 0
	movs r5, 0
	movs r7, 0x80
	lsls r7, 24
	mov r9, r7
	movs r0, 0x3F
	mov r12, r0
_0800A538:
	adds r3, r5, 0
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0800A54C
	adds r5, r4
	adds r6, r1
	cmp r3, r5
	bls _0800A54C
	adds r6, 0x1
_0800A54C:
	lsrs r2, 1
	movs r3, 0x1
	mov r0, r10
	ands r0, r3
	cmp r0, 0
	beq _0800A55C
	mov r7, r9
	orrs r2, r7
_0800A55C:
	mov r0, r10
	lsrs r0, 1
	mov r10, r0
	lsls r1, 1
	adds r0, r4, 0
	mov r7, r9
	ands r0, r7
	cmp r0, 0
	beq _0800A570
	orrs r1, r3
_0800A570:
	lsls r4, 1
	movs r0, 0x1
	negs r0, r0
	add r12, r0
	mov r7, r12
	cmp r7, 0
	bge _0800A538
	lsrs r1, r5, 15
	ands r1, r3
	lsrs r5, 16
	lsls r0, r6, 16
	orrs r5, r0
	lsrs r6, 16
	cmp r1, 0
	beq _0800A590
	adds r5, 0x1
_0800A590:
	mov r0, r8
	str r6, [r0]
	str r5, [r0, 0x4]
_0800A596:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A4E4

	thumb_func_start sub_800A5A4
sub_800A5A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp]
	adds r5, r1, 0
	mov r8, r2
	mov r0, r8
	bl sub_800A2A0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800A5D8
	ldr r0, _0800A5D4
	ldr r1, [sp]
	str r0, [r1]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1, 0x4]
	b _0800A6BE
	.align 2, 0
_0800A5D4: .4byte 0x7fffffff
_0800A5D8:
	adds r0, r5, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0800A5EC
	ldr r2, [sp]
	str r4, [r2]
	str r4, [r2, 0x4]
	b _0800A6BE
_0800A5EC:
	ldr r0, [r5]
	lsls r7, r0, 16
	ldr r1, [r5, 0x4]
	lsrs r0, r1, 16
	orrs r7, r0
	lsls r6, r1, 16
	movs r0, 0x80
	lsls r0, 8
	orrs r6, r0
	mov r0, r8
	ldr r0, [r0]
	str r0, [sp, 0x4]
	mov r1, r8
	ldr r1, [r1, 0x4]
	str r1, [sp, 0x8]
	movs r2, 0
	str r2, [sp, 0xC]
	mov r9, r2
	movs r5, 0
	movs r4, 0
	movs r0, 0x80
	lsls r0, 24
	mov r10, r0
	movs r1, 0x1
	mov r8, r1
	movs r2, 0x3F
	str r2, [sp, 0x10]
_0800A622:
	lsls r5, 1
	adds r0, r4, 0
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _0800A632
	mov r2, r8
	orrs r5, r2
_0800A632:
	movs r1, 0x2
	negs r1, r1
	lsls r4, 1
	adds r0, r7, 0
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A646
	mov r0, r8
	orrs r4, r0
_0800A646:
	lsls r7, 1
	adds r0, r6, 0
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A656
	mov r0, r8
	orrs r7, r0
_0800A656:
	lsls r6, 1
	ands r6, r1
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x4]
	ldr r3, [sp, 0x8]
	bl sub_8009D8C
	lsls r0, 24
	cmp r0, 0
	bne _0800A680
	adds r0, r4, 0
	movs r1, 0x1
	ldr r2, [sp, 0x8]
	subs r4, r2
	ldr r2, [sp, 0x4]
	subs r5, r2
	cmp r0, r4
	bcs _0800A682
	subs r5, 0x1
	b _0800A682
_0800A680:
	movs r1, 0
_0800A682:
	ldr r0, [sp, 0xC]
	lsls r0, 1
	str r0, [sp, 0xC]
	mov r0, r9
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0800A69A
	ldr r0, [sp, 0xC]
	mov r2, r8
	orrs r0, r2
	str r0, [sp, 0xC]
_0800A69A:
	mov r0, r9
	lsls r0, 1
	mov r9, r0
	cmp r1, 0
	beq _0800A6AA
	mov r1, r8
	orrs r0, r1
	mov r9, r0
_0800A6AA:
	ldr r2, [sp, 0x10]
	subs r2, 0x1
	str r2, [sp, 0x10]
	cmp r2, 0
	bge _0800A622
	ldr r0, [sp, 0xC]
	ldr r1, [sp]
	str r0, [r1]
	mov r2, r9
	str r2, [r1, 0x4]
_0800A6BE:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A5A4

	thumb_func_start sub_800A6D0
sub_800A6D0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r1]
	ldr r0, [r2]
	adds r3, r0
	ldr r1, [r1, 0x4]
	ldr r0, [r2, 0x4]
	adds r0, r1, r0
	cmp r0, r1
	bcs _0800A6E6
	adds r3, 0x1
_0800A6E6:
	str r3, [r4]
	str r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800A6D0

	thumb_func_start sub_800A6F0
sub_800A6F0:
	push {r4,lr}
	adds r4, r0, 0
	ldr r3, [r1]
	ldr r0, [r2]
	subs r3, r0
	ldr r1, [r1, 0x4]
	ldr r0, [r2, 0x4]
	subs r0, r1, r0
	cmp r0, r1
	bls _0800A706
	subs r3, 0x1
_0800A706:
	str r3, [r4]
	str r0, [r4, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_800A6F0

	thumb_func_start sub_800A710
sub_800A710:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	mov r8, r0
	adds r6, r2, 0
	ldr r0, [r1]
	str r0, [sp]
	ldr r0, [r1, 0x4]
	str r0, [sp, 0x4]
	adds r4, r6, 0
	cmp r6, 0
	bge _0800A72C
	negs r4, r6
_0800A72C:
	movs r0, 0
	str r0, [sp, 0x8]
	movs r1, 0x80
	lsls r1, 9
	add r0, sp, 0x8
	str r1, [r0, 0x4]
	adds r7, r0, 0
	cmp r4, 0
	beq _0800A75E
	adds r5, r7, 0
_0800A740:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0800A752
	adds r0, r5, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_800A34C
_0800A752:
	mov r0, sp
	bl sub_800A4A0
	asrs r4, 1
	cmp r4, 0
	bne _0800A740
_0800A75E:
	cmp r6, 0
	bge _0800A776
	movs r0, 0
	str r0, [sp, 0x10]
	movs r0, 0x80
	lsls r0, 9
	add r1, sp, 0x10
	str r0, [r1, 0x4]
	adds r0, r7, 0
	adds r2, r7, 0
	bl sub_800A3F0
_0800A776:
	ldr r0, [sp, 0x8]
	mov r1, r8
	str r0, [r1]
	ldr r0, [r7, 0x4]
	str r0, [r1, 0x4]
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A710

	thumb_func_start sub_800A78C
sub_800A78C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r10, r0
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	mov r0, sp
	bl sub_800A27C
	add r4, sp, 0x8
	adds r0, r4, 0
	bl sub_800A27C
	mov r0, sp
	adds r1, r4, 0
	bl sub_800A2F0
	lsls r0, 24
	mov r8, r4
	cmp r0, 0
	beq _0800A7DC
	ldr r2, [sp]
	ldr r3, [sp, 0x4]
	str r2, [sp, 0x10]
	str r3, [sp, 0x14]
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
_0800A7DC:
	mov r0, r8
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	bne _0800A878
	movs r0, 0
	mov r9, r0
	add r7, sp, 0x10
	add r6, sp, 0x18
	b _0800A800
_0800A7F2:
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	movs r2, 0x1
	add r9, r2
_0800A800:
	adds r4, r7, 0
	mov r1, r8
	adds r0, r4, 0
	mov r2, sp
	bl sub_800A3F0
	adds r0, r4, 0
	bl sub_800A4A0
	ldr r0, [sp, 0x10]
	str r0, [sp, 0x18]
	ldr r1, [r4, 0x4]
	movs r0, 0x80
	lsls r0, 11
	adds r1, r0
	adds r5, r6, 0
	str r1, [r5, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	bcs _0800A82E
	ldr r0, [sp, 0x18]
	adds r0, 0x1
	str r0, [sp, 0x18]
_0800A82E:
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A3F0
	adds r0, r5, 0
	mov r1, sp
	adds r2, r4, 0
	bl sub_800A34C
	ldr r0, [sp, 0x18]
	lsls r1, r0, 1
	str r1, [sp, 0x18]
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _0800A854
	movs r0, 0x1
	orrs r1, r0
	str r1, [sp, 0x18]
_0800A854:
	ldr r0, [r6, 0x4]
	lsls r0, 1
	str r0, [r6, 0x4]
	ldr r2, [sp, 0x4]
	ldr r1, [sp]
	ldr r0, [sp, 0x18]
	adds r1, r0
	str r1, [sp]
	ldr r0, [r6, 0x4]
	adds r0, r2, r0
	str r0, [sp, 0x4]
	cmp r2, r0
	bls _0800A872
	adds r0, r1, 0x1
	str r0, [sp]
_0800A872:
	mov r2, r9
	cmp r2, 0x2
	bne _0800A7F2
_0800A878:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	mov r2, r10
	str r0, [r2]
	str r1, [r2, 0x4]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_800A78C

	thumb_func_start sub_800A894
sub_800A894:
	push {lr}
	adds r2, r0, 0
	adds r0, r1, 0
	cmp r0, 0
	bgt _0800A8A0
	movs r0, 0x1
_0800A8A0:
	ldr r1, _0800A8BC
	cmp r0, r1
	ble _0800A8A8
	adds r0, r1, 0
_0800A8A8:
	ldr r1, _0800A8C0
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2, 0x4]
	movs r0, 0
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0800A8BC: .4byte 0x0000012b
_0800A8C0: .4byte gUnknown_80B96E4
	thumb_func_end sub_800A894

	thumb_func_start sub_800A8C4
sub_800A8C4:
	push {r4,lr}
	ldr r3, _0800A8EC
	ldr r4, _0800A8F0
	movs r2, 0
	ldr r0, _0800A8F4
	movs r1, 0x3F
_0800A8D0:
	str r2, [r0]
	str r2, [r0, 0x4]
	adds r0, 0x8
	subs r1, 0x1
	cmp r1, 0
	bge _0800A8D0
	movs r0, 0
	str r0, [r3]
	movs r0, 0x1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A8EC: .4byte gUnknown_203B094
_0800A8F0: .4byte gUnknown_202D2A4
_0800A8F4: .4byte gUnknown_202D2A8
	thumb_func_end sub_800A8C4

	thumb_func_start sub_800A8F8
sub_800A8F8:
	ldr r1, _0800A904
	ldr r2, [r1]
	str r0, [r1]
	adds r0, r2, 0
	bx lr
	.align 2, 0
_0800A904: .4byte gUnknown_202D2A4
	thumb_func_end sub_800A8F8

	thumb_func_start sub_800A908
sub_800A908:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x12C
	mov r8, r0
	adds r4, r1, 0
	ldr r1, _0800A93C
	adds r0, r4, 0
	bl strcmp
	cmp r0, 0
	beq _0800A922
	movs r0, 0x1
_0800A922:
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _0800A92C
	movs r1, 0x1
_0800A92C:
	cmp r1, 0
	beq _0800A9B6
	ldr r7, [r4, 0xC]
	movs r6, 0
	ldr r0, [r4, 0x8]
	subs r5, r0, 0x1
	b _0800A94A
	.align 2, 0
_0800A93C: .4byte gUnknown_80B9B94
_0800A940:
	cmp r0, 0
	bge _0800A948
	adds r6, r4, 0x1
	b _0800A94A
_0800A948:
	adds r5, r4, 0
_0800A94A:
	cmp r6, r5
	bge _0800A968
	adds r0, r6, r5
	lsrs r1, r0, 31
	adds r0, r1
	asrs r4, r0, 1
	lsls r0, r4, 3
	adds r0, r7
	ldr r0, [r0]
	mov r1, r8
	bl strcmp
	cmp r0, 0
	bne _0800A940
	adds r6, r4, 0
_0800A968:
	lsls r0, r6, 3
	adds r6, r7, r0
	ldr r0, [r6]
	mov r1, r8
	bl strcmp
	cmp r0, 0
	beq _0800A994
	ldr r1, _0800A984
	mov r0, sp
	mov r2, r8
	bl sprintf
	b _0800A9B6
	.align 2, 0
_0800A984: .4byte gUnknown_80B9B9C
_0800A988:
	str r6, [r2]
	adds r0, r7, 0x4
	adds r0, r3, r0
	str r1, [r0]
	adds r0, r2, 0
	b _0800A9B8
_0800A994:
	ldr r0, _0800A9C4
	ldr r0, [r0]
	movs r4, 0
	ldr r5, _0800A9C8
	adds r7, r5, 0
_0800A99E:
	adds r0, 0x1
	cmp r0, 0x3F
	ble _0800A9A6
	movs r0, 0
_0800A9A6:
	lsls r3, r0, 3
	adds r2, r3, r5
	ldr r1, [r2]
	cmp r1, 0
	beq _0800A988
	adds r4, 0x1
	cmp r4, 0x3F
	ble _0800A99E
_0800A9B6:
	movs r0, 0
_0800A9B8:
	add sp, 0x12C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A9C4: .4byte gUnknown_203B094
_0800A9C8: .4byte gUnknown_202D2A8
	thumb_func_end sub_800A908

	thumb_func_start sub_800A9CC
sub_800A9CC:
	ldr r1, [r0]
	ldr r1, [r1, 0x4]
	str r1, [r0, 0x4]
	adds r0, r1, 0
	bx lr
	thumb_func_end sub_800A9CC

	thumb_func_start sub_800A9D8
sub_800A9D8:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_800A9CC
	adds r0, r4, 0
	bl sub_800AA48
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800A9D8

	thumb_func_start sub_800A9EC
sub_800A9EC:
	push {r4,lr}
	bl sub_800A908
	adds r4, r0, 0
	cmp r4, 0
	beq _0800A9FE
	movs r1, 0
	bl sub_800A9D8
_0800A9FE:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800A9EC

	thumb_func_start sub_800AA08
sub_800AA08:
	push {lr}
	bl sub_800A9EC
	pop {r1}
	bx r1
	thumb_func_end sub_800AA08

	thumb_func_start sub_800AA14
sub_800AA14:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0
	ldr r0, _0800AA30
	movs r3, 0
	ldr r5, _0800AA34
	adds r2, r0, 0x4
_0800AA22:
	cmp r0, r4
	bne _0800AA38
	str r3, [r0]
	str r3, [r2]
	str r1, [r5]
	b _0800AA42
	.align 2, 0
_0800AA30: .4byte gUnknown_202D2A8
_0800AA34: .4byte gUnknown_203B094
_0800AA38:
	adds r2, 0x8
	adds r0, 0x8
	adds r1, 0x1
	cmp r1, 0x3F
	ble _0800AA22
_0800AA42:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_800AA14

	thumb_func_start sub_800AA48
sub_800AA48:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, [r5, 0x4]
	ldr r1, [r4]
	ldr r0, _0800AA60
	cmp r1, r0
	beq _0800AA68
	ldr r0, _0800AA64
	cmp r1, r0
	beq _0800AA6E
	adds r0, r4, 0
	b _0800AA72
	.align 2, 0
_0800AA60: .4byte 0x30524953
_0800AA64: .4byte 0x4f524953
_0800AA68:
	adds r0, r4, 0
	bl nullsub_15
_0800AA6E:
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x4]
_0800AA72:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800AA48

	thumb_func_start sub_800AA78
sub_800AA78:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, [r4]
	ldr r0, _0800AA90
	cmp r1, r0
	bne _0800AA94
	adds r0, r4, 0
	bl nullsub_15
	ldr r0, [r4, 0x4]
	b _0800AA96
	.align 2, 0
_0800AA90: .4byte 0x30524953
_0800AA94:
	adds r0, r4, 0
_0800AA96:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_800AA78

	thumb_func_start nullsub_15
nullsub_15:
	bx lr
	thumb_func_end nullsub_15

	thumb_func_start nullsub_16
nullsub_16:
	bx lr
	thumb_func_end nullsub_16

	thumb_func_start nullsub_175
nullsub_175:
	bx lr
	thumb_func_end nullsub_175

	thumb_func_start sub_800AAA8
sub_800AAA8:
	push {lr}
	ldr r2, [r2, 0x4]
	bl sub_800AAB4
	pop {r1}
	bx r1
	thumb_func_end sub_800AAA8

	thumb_func_start sub_800AAB4
sub_800AAB4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r12, r0
	str r1, [sp, 0x24]
	mov r8, r2
	ldrb r0, [r2, 0x5]
	ldrb r1, [r2, 0x6]
	lsls r1, 8
	adds r0, r1
	str r0, [sp, 0x28]
	movs r6, 0
	mov r10, r6
	movs r0, 0x8
	mov r9, r0
	ldrb r0, [r2]
	cmp r0, 0x41
	bne _0800AB04
	ldrb r0, [r2, 0x1]
	adds r1, r0, 0
	cmp r1, 0x54
	bne _0800AB0C
	ldrb r0, [r2, 0x2]
	cmp r0, 0x34
	bne _0800AB0C
	ldrb r0, [r2, 0x3]
	cmp r0, 0x50
	bne _0800AB0C
	ldrb r1, [r2, 0x10]
	ldrb r0, [r2, 0x11]
	lsls r0, 8
	adds r1, r0
	ldr r2, [sp, 0x24]
	cmp r2, 0
	beq _0800AB08
	cmp r2, r1
	beq _0800AB08
_0800AB04:
	movs r0, 0
	b _0800AE16
_0800AB08:
	movs r1, 0x12
	b _0800AB26
_0800AB0C:
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, 0x41
	bne _0800AB04
	cmp r1, 0x54
	bne _0800AB04
	ldrb r0, [r3, 0x2]
	cmp r0, 0x33
	bne _0800AB04
	ldrb r0, [r3, 0x3]
	cmp r0, 0x50
	bne _0800AB04
	movs r1, 0x10
_0800AB26:
	mov r2, r8
	ldrb r0, [r2, 0x4]
	cmp r0, 0x4E
	bne _0800AB4A
	movs r7, 0
	b _0800AB40
_0800AB32:
	mov r1, r12
	adds r0, r1, r7
	mov r2, r8
	adds r1, r7, r2
	ldrb r1, [r1, 0x7]
	strb r1, [r0]
	adds r7, 0x1
_0800AB40:
	ldr r3, [sp, 0x28]
	cmp r7, r3
	blt _0800AB32
	adds r0, r7, 0
	b _0800AE16
_0800AB4A:
	mov r2, r8
	ldrb r0, [r2, 0x7]
	adds r0, 0x3
	str r0, [sp]
	ldrb r0, [r2, 0x8]
	adds r0, 0x3
	str r0, [sp, 0x4]
	ldrb r0, [r2, 0x9]
	adds r0, 0x3
	str r0, [sp, 0x8]
	ldrb r0, [r2, 0xA]
	adds r0, 0x3
	str r0, [sp, 0xC]
	ldrb r0, [r2, 0xB]
	adds r0, 0x3
	str r0, [sp, 0x10]
	ldrb r0, [r2, 0xC]
	adds r0, 0x3
	str r0, [sp, 0x14]
	ldrb r0, [r2, 0xD]
	adds r0, 0x3
	str r0, [sp, 0x18]
	ldrb r0, [r2, 0xE]
	adds r0, 0x3
	str r0, [sp, 0x1C]
	ldrb r0, [r2, 0xF]
	adds r0, 0x3
	str r0, [sp, 0x20]
	adds r7, r1, 0
	ldr r3, [sp, 0x28]
	cmp r7, r3
	blt _0800AB8C
	b _0800AE14
_0800AB8C:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	beq _0800AB96
	cmp r6, r0
	bge _0800AB04
_0800AB96:
	mov r1, r9
	cmp r1, 0x8
	bne _0800ABAA
	mov r2, r8
	adds r0, r2, r7
	ldrb r0, [r0]
	mov r10, r0
	adds r7, 0x1
	movs r3, 0
	mov r9, r3
_0800ABAA:
	movs r0, 0x80
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _0800ABB6
	b _0800ADF0
_0800ABB6:
	mov r3, r8
	adds r2, r3, r7
	ldrb r1, [r2]
	lsrs r0, r1, 4
	adds r3, r0, 0x3
	movs r0, 0xF
	ands r0, r1
	lsls r5, r0, 8
	ldr r0, [sp]
	cmp r3, r0
	bne _0800ABCE
	movs r3, 0x1F
_0800ABCE:
	ldr r0, [sp, 0x4]
	cmp r3, r0
	bne _0800ABD6
	movs r3, 0x1E
_0800ABD6:
	ldr r0, [sp, 0x8]
	cmp r3, r0
	bne _0800ABDE
	movs r3, 0x1D
_0800ABDE:
	ldr r0, [sp, 0xC]
	cmp r3, r0
	bne _0800ABE6
	movs r3, 0x1C
_0800ABE6:
	ldr r0, [sp, 0x10]
	cmp r3, r0
	bne _0800ABEE
	movs r3, 0x1B
_0800ABEE:
	ldr r0, [sp, 0x14]
	cmp r3, r0
	bne _0800ABF6
	movs r3, 0x1A
_0800ABF6:
	ldr r0, [sp, 0x18]
	cmp r3, r0
	bne _0800ABFE
	movs r3, 0x19
_0800ABFE:
	ldr r0, [sp, 0x1C]
	cmp r3, r0
	bne _0800AC06
	movs r3, 0x18
_0800AC06:
	ldr r0, [sp, 0x20]
	cmp r3, r0
	bne _0800AC0E
	movs r3, 0x17
_0800AC0E:
	adds r0, r3, 0
	subs r0, 0x17
	cmp r0, 0x8
	bls _0800AC18
	b _0800ADB0
_0800AC18:
	lsls r0, 2
	ldr r1, _0800AC24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800AC24: .4byte _0800AC28
	.align 2, 0
_0800AC28:
	.4byte _0800AD7C
	.4byte _0800AD48
	.4byte _0800AD20
	.4byte _0800ACFA
	.4byte _0800ACD6
	.4byte _0800ACB4
	.4byte _0800AC8C
	.4byte _0800AC66
	.4byte _0800AC4C
_0800AC4C:
	ldrb r1, [r2]
	movs r0, 0xF
	adds r7, 0x1
	mov r3, r12
	adds r2, r3, r6
	ands r0, r1
	lsls r1, r0, 4
	orrs r1, r0
	strb r1, [r2]
	adds r6, 0x1
	adds r0, r3, r6
	strb r1, [r0]
	b _0800ADA4
_0800AC66:
	ldrb r0, [r2]
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r3, r1, r6
	movs r2, 0xF
	lsls r0, r5, 4
	adds r1, r5, 0x1
	ands r1, r2
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r2, r3, r6
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	b _0800ADA4
_0800AC8C:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r4, r1, r6
	adds r2, r5, 0
	ands r2, r3
	lsls r1, r2, 4
	subs r0, r5, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r6, 0x1
	mov r3, r12
	adds r0, r3, r6
	orrs r1, r2
	strb r1, [r0]
	b _0800ADA4
_0800ACB4:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r2, r1, r6
	adds r1, r5, 0
	ands r1, r3
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	mov r0, r12
	adds r2, r0, r6
	subs r0, r5, 0x1
	b _0800AD68
_0800ACD6:
	ldrb r0, [r2]
	movs r4, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r2, r12
	adds r3, r2, r6
	adds r1, r5, 0
	ands r1, r4
	lsls r2, r1, 4
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r1, r3, r6
	subs r0, r5, 0x1
	b _0800AD9E
_0800ACFA:
	ldrb r0, [r2]
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r3, r1, r6
	movs r2, 0xF
	lsls r0, r5, 4
	subs r1, r5, 0x1
	ands r1, r2
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r2, r3, r6
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	b _0800ADA4
_0800AD20:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r4, r1, r6
	adds r2, r5, 0
	ands r2, r3
	lsls r1, r2, 4
	adds r0, r5, 0x1
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r6, 0x1
	mov r3, r12
	adds r0, r3, r6
	orrs r1, r2
	strb r1, [r0]
	b _0800ADA4
_0800AD48:
	ldrb r0, [r2]
	movs r3, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r1, r12
	adds r2, r1, r6
	adds r1, r5, 0
	ands r1, r3
	lsls r0, r1, 4
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	mov r0, r12
	adds r2, r0, r6
	adds r0, r5, 0x1
_0800AD68:
	ands r0, r3
	lsls r0, 4
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	mov r4, r9
	adds r4, 0x1
	mov r1, r10
	lsls r2, r1, 1
	b _0800AE08
_0800AD7C:
	ldrb r0, [r2]
	movs r4, 0xF
	movs r5, 0xF
	ands r5, r0
	adds r7, 0x1
	mov r2, r12
	adds r3, r2, r6
	adds r1, r5, 0
	ands r1, r4
	lsls r2, r1, 4
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3]
	adds r6, 0x1
	mov r3, r12
	adds r1, r3, r6
	adds r0, r5, 0x1
_0800AD9E:
	ands r0, r4
	orrs r2, r0
	strb r2, [r1]
_0800ADA4:
	adds r6, 0x1
	mov r4, r9
	adds r4, 0x1
	mov r0, r10
	lsls r2, r0, 1
	b _0800AE08
_0800ADB0:
	adds r7, 0x1
	mov r1, r8
	adds r0, r1, r7
	ldrb r0, [r0]
	adds r5, r0
	adds r7, 0x1
	ldr r2, _0800ADEC
	adds r0, r5, r2
	adds r5, r0, r6
	mov r4, r9
	adds r4, 0x1
	mov r0, r10
	lsls r2, r0, 1
	cmp r3, 0
	beq _0800AE08
_0800ADCE:
	mov r1, r12
	adds r1, r6
	mov r10, r1
	mov r0, r12
	adds r0, r5
	ldrb r1, [r0]
	mov r0, r10
	strb r1, [r0]
	adds r6, 0x1
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _0800ADCE
	b _0800AE08
	.align 2, 0
_0800ADEC: .4byte 0xfffff000
_0800ADF0:
	mov r1, r12
	adds r0, r1, r6
	mov r2, r8
	adds r1, r2, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	adds r7, 0x1
	mov r4, r9
	adds r4, 0x1
	mov r3, r10
	lsls r2, r3, 1
_0800AE08:
	mov r9, r4
	mov r10, r2
	ldr r0, [sp, 0x28]
	cmp r7, r0
	bge _0800AE14
	b _0800AB8C
_0800AE14:
	adds r0, r6, 0
_0800AE16:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800AAB4

	thumb_func_start sub_800AE28
sub_800AE28:
	push {lr}
	ldr r2, [r2, 0x4]
	bl sub_800AE34
	pop {r1}
	bx r1
	thumb_func_end sub_800AE28

	thumb_func_start sub_800AE34
sub_800AE34:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	str r1, [sp, 0x24]
	mov r10, r2
	ldrb r2, [r2, 0x5]
	mov r3, r10
	ldrb r1, [r3, 0x6]
	lsls r1, 8
	adds r2, r1
	str r2, [sp, 0x28]
	movs r1, 0
	mov r9, r1
	movs r2, 0
	str r2, [sp, 0x2C]
	movs r3, 0x8
	str r3, [sp, 0x30]
	bl sub_800B1BC
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800AE90
	ldrb r0, [r1, 0x1]
	adds r1, r0, 0
	cmp r1, 0x54
	bne _0800AE98
	mov r2, r10
	ldrb r0, [r2, 0x2]
	cmp r0, 0x34
	bne _0800AE98
	ldrb r0, [r2, 0x3]
	cmp r0, 0x50
	bne _0800AE98
	ldrb r1, [r2, 0x10]
	ldrb r0, [r2, 0x11]
	lsls r0, 8
	adds r1, r0
	ldr r3, [sp, 0x24]
	cmp r3, 0
	beq _0800AE94
	cmp r3, r1
	beq _0800AE94
_0800AE90:
	movs r0, 0
	b _0800B1AA
_0800AE94:
	movs r1, 0x12
	b _0800AEB2
_0800AE98:
	mov r2, r10
	ldrb r0, [r2]
	cmp r0, 0x41
	bne _0800AE90
	cmp r1, 0x54
	bne _0800AE90
	ldrb r0, [r2, 0x2]
	cmp r0, 0x33
	bne _0800AE90
	ldrb r0, [r2, 0x3]
	cmp r0, 0x50
	bne _0800AE90
	movs r1, 0x10
_0800AEB2:
	mov r3, r10
	ldrb r0, [r3, 0x4]
	cmp r0, 0x4E
	bne _0800AEE0
	movs r0, 0
	mov r8, r0
	ldr r1, [sp, 0x28]
	cmp r8, r1
	bge _0800AED8
_0800AEC4:
	mov r0, r8
	add r0, r10
	ldrb r0, [r0, 0x7]
	bl sub_800B220
	movs r2, 0x1
	add r8, r2
	ldr r3, [sp, 0x28]
	cmp r8, r3
	blt _0800AEC4
_0800AED8:
	bl sub_800B270
	mov r0, r8
	b _0800B1AA
_0800AEE0:
	mov r2, r10
	ldrb r0, [r2, 0x7]
	adds r0, 0x3
	str r0, [sp]
	ldrb r0, [r2, 0x8]
	adds r0, 0x3
	str r0, [sp, 0x4]
	ldrb r0, [r2, 0x9]
	adds r0, 0x3
	str r0, [sp, 0x8]
	ldrb r0, [r2, 0xA]
	adds r0, 0x3
	str r0, [sp, 0xC]
	ldrb r0, [r2, 0xB]
	adds r0, 0x3
	str r0, [sp, 0x10]
	ldrb r0, [r2, 0xC]
	adds r0, 0x3
	str r0, [sp, 0x14]
	ldrb r0, [r2, 0xD]
	adds r0, 0x3
	str r0, [sp, 0x18]
	ldrb r0, [r2, 0xE]
	adds r0, 0x3
	str r0, [sp, 0x1C]
	ldrb r0, [r2, 0xF]
	adds r0, 0x3
	str r0, [sp, 0x20]
	mov r8, r1
	ldr r3, [sp, 0x28]
	cmp r8, r3
	blt _0800AF22
	b _0800B1A4
_0800AF22:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	beq _0800AF2C
	cmp r9, r0
	bge _0800AE90
_0800AF2C:
	ldr r1, [sp, 0x30]
	cmp r1, 0x8
	bne _0800AF42
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	str r0, [sp, 0x2C]
	movs r2, 0x1
	add r8, r2
	movs r3, 0
	str r3, [sp, 0x30]
_0800AF42:
	movs r0, 0x80
	ldr r1, [sp, 0x2C]
	ands r0, r1
	cmp r0, 0
	beq _0800AF4E
	b _0800B180
_0800AF4E:
	mov r2, r10
	add r2, r8
	ldrb r1, [r2]
	lsrs r0, r1, 4
	adds r3, r0, 0x3
	movs r0, 0xF
	ands r0, r1
	lsls r7, r0, 8
	ldr r0, [sp]
	cmp r3, r0
	bne _0800AF66
	movs r3, 0x1F
_0800AF66:
	ldr r0, [sp, 0x4]
	cmp r3, r0
	bne _0800AF6E
	movs r3, 0x1E
_0800AF6E:
	ldr r0, [sp, 0x8]
	cmp r3, r0
	bne _0800AF76
	movs r3, 0x1D
_0800AF76:
	ldr r0, [sp, 0xC]
	cmp r3, r0
	bne _0800AF7E
	movs r3, 0x1C
_0800AF7E:
	ldr r0, [sp, 0x10]
	cmp r3, r0
	bne _0800AF86
	movs r3, 0x1B
_0800AF86:
	ldr r0, [sp, 0x14]
	cmp r3, r0
	bne _0800AF8E
	movs r3, 0x1A
_0800AF8E:
	ldr r0, [sp, 0x18]
	cmp r3, r0
	bne _0800AF96
	movs r3, 0x19
_0800AF96:
	ldr r0, [sp, 0x1C]
	cmp r3, r0
	bne _0800AF9E
	movs r3, 0x18
_0800AF9E:
	ldr r0, [sp, 0x20]
	cmp r3, r0
	bne _0800AFA6
	movs r3, 0x17
_0800AFA6:
	adds r0, r3, 0
	subs r0, 0x17
	cmp r0, 0x8
	bls _0800AFB0
	b _0800B13C
_0800AFB0:
	lsls r0, 2
	ldr r1, _0800AFBC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800AFBC: .4byte _0800AFC0
	.align 2, 0
_0800AFC0:
	.4byte _0800B104
	.4byte _0800B0DE
	.4byte _0800B0BA
	.4byte _0800B090
	.4byte _0800B06E
	.4byte _0800B048
	.4byte _0800B024
	.4byte _0800AFFE
	.4byte _0800AFE4
_0800AFE4:
	ldrb r0, [r2]
	movs r1, 0xF
	movs r2, 0x1
	add r8, r2
	ands r1, r0
	lsls r4, r1, 4
	orrs r4, r1
	adds r0, r4, 0
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	b _0800B128
_0800AFFE:
	ldrb r0, [r2]
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	movs r1, 0xF
	lsls r0, r6, 4
	adds r4, r6, 0x1
	ands r4, r1
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	lsls r0, r4, 4
	orrs r0, r4
	lsls r0, 24
	lsrs r0, 24
	b _0800B12A
_0800B024:
	ldrb r0, [r2]
	movs r1, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r5, r6, 0
	ands r5, r1
	lsls r4, r5, 4
	subs r0, r6, 0x1
	ands r0, r1
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	orrs r4, r5
	b _0800B128
_0800B048:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r4, r6, 0
	ands r4, r5
	lsls r0, r4, 4
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	subs r0, r6, 0x1
	ands r0, r5
	lsls r0, 4
	orrs r0, r4
	b _0800B12A
_0800B06E:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r1, r6, 0
	ands r1, r5
	lsls r4, r1, 4
	adds r0, r4, 0
	orrs r0, r1
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	subs r0, r6, 0x1
	b _0800B124
_0800B090:
	ldrb r0, [r2]
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	movs r1, 0xF
	lsls r0, r6, 4
	subs r4, r6, 0x1
	ands r4, r1
	orrs r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	lsls r0, r4, 4
	orrs r0, r4
	lsls r0, 24
	lsrs r0, 24
	b _0800B12A
_0800B0BA:
	ldrb r0, [r2]
	movs r1, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r5, r6, 0
	ands r5, r1
	lsls r4, r5, 4
	adds r0, r6, 0x1
	ands r0, r1
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	orrs r4, r5
	b _0800B128
_0800B0DE:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r4, r6, 0
	ands r4, r5
	lsls r0, r4, 4
	orrs r0, r4
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	adds r0, r6, 0x1
	ands r0, r5
	lsls r0, 4
	orrs r0, r4
	b _0800B12A
_0800B104:
	ldrb r0, [r2]
	movs r5, 0xF
	movs r6, 0xF
	ands r6, r0
	movs r2, 0x1
	add r8, r2
	adds r1, r6, 0
	ands r1, r5
	lsls r4, r1, 4
	adds r0, r4, 0
	orrs r0, r1
	bl sub_800B220
	movs r3, 0x1
	add r9, r3
	adds r0, r6, 0x1
_0800B124:
	ands r0, r5
	orrs r4, r0
_0800B128:
	adds r0, r4, 0
_0800B12A:
	bl sub_800B220
	movs r0, 0x1
	add r9, r0
	ldr r5, [sp, 0x30]
	adds r5, 0x1
	ldr r1, [sp, 0x2C]
	lsls r4, r1, 1
	b _0800B198
_0800B13C:
	movs r2, 0x1
	add r8, r2
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	adds r7, r0
	add r8, r2
	ldr r1, _0800B17C
	adds r0, r7, r1
	mov r2, r9
	adds r7, r0, r2
	ldr r5, [sp, 0x30]
	adds r5, 0x1
	ldr r0, [sp, 0x2C]
	lsls r4, r0, 1
	cmp r3, 0
	beq _0800B198
	adds r6, r3, 0
_0800B160:
	adds r0, r7, 0
	bl sub_800B1E0
	lsls r0, 24
	lsrs r0, 24
	bl sub_800B220
	movs r1, 0x1
	add r9, r1
	adds r7, 0x1
	subs r6, 0x1
	cmp r6, 0
	bne _0800B160
	b _0800B198
	.align 2, 0
_0800B17C: .4byte 0xfffff000
_0800B180:
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	bl sub_800B220
	movs r2, 0x1
	add r9, r2
	add r8, r2
	ldr r5, [sp, 0x30]
	adds r5, 0x1
	ldr r3, [sp, 0x2C]
	lsls r4, r3, 1
_0800B198:
	str r5, [sp, 0x30]
	str r4, [sp, 0x2C]
	ldr r0, [sp, 0x28]
	cmp r8, r0
	bge _0800B1A4
	b _0800AF22
_0800B1A4:
	bl sub_800B270
	mov r0, r9
_0800B1AA:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800AE34

	thumb_func_start sub_800B1BC
sub_800B1BC:
	ldr r1, _0800B1D0
	str r0, [r1]
	ldr r1, _0800B1D4
	str r0, [r1]
	ldr r0, _0800B1D8
	movs r1, 0
	str r1, [r0]
	ldr r0, _0800B1DC
	str r1, [r0]
	bx lr
	.align 2, 0
_0800B1D0: .4byte gUnknown_202D4A8
_0800B1D4: .4byte gUnknown_202D4AC
_0800B1D8: .4byte gUnknown_202D4B0
_0800B1DC: .4byte gUnknown_202D4B4
	thumb_func_end sub_800B1BC

	thumb_func_start sub_800B1E0
sub_800B1E0:
	push {lr}
	adds r2, r0, 0
	cmp r2, 0
	bge _0800B1EA
	adds r0, r2, 0x3
_0800B1EA:
	asrs r0, 2
	ldr r1, _0800B20C
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x3
	ands r1, r2
	cmp r1, 0x1
	beq _0800B210
	cmp r1, 0x1
	ble _0800B216
	cmp r1, 0x2
	beq _0800B214
	cmp r1, 0x3
	beq _0800B218
	b _0800B216
	.align 2, 0
_0800B20C: .4byte gUnknown_202D4AC
_0800B210:
	lsrs r0, 8
	b _0800B216
_0800B214:
	lsrs r0, 16
_0800B216:
	lsls r0, 24
_0800B218:
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_800B1E0

	thumb_func_start sub_800B220
sub_800B220:
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, _0800B260
	ldr r2, _0800B264
	ldr r3, _0800B268
	ldr r1, [r3]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	lsls r0, r1
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	ldr r2, _0800B26C
	ldr r0, [r2]
	str r1, [r0]
	ldr r0, [r3]
	adds r0, 0x1
	str r0, [r3]
	cmp r0, 0x4
	bne _0800B258
	ldr r0, [r2]
	adds r0, 0x4
	str r0, [r2]
	movs r0, 0
	str r0, [r4]
	str r0, [r3]
_0800B258:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B260: .4byte gUnknown_202D4B0
_0800B264: .4byte gUnknown_80B9BB8
_0800B268: .4byte gUnknown_202D4B4
_0800B26C: .4byte gUnknown_202D4A8
	thumb_func_end sub_800B220

	thumb_func_start sub_800B270
sub_800B270:
	push {lr}
	ldr r0, _0800B288
	ldr r0, [r0]
	cmp r0, 0
	beq _0800B284
	ldr r0, _0800B28C
	ldr r1, [r0]
	ldr r0, _0800B290
	ldr r0, [r0]
	str r0, [r1]
_0800B284:
	pop {r0}
	bx r0
	.align 2, 0
_0800B288: .4byte gUnknown_202D4B4
_0800B28C: .4byte gUnknown_202D4A8
_0800B290: .4byte gUnknown_202D4B0
	thumb_func_end sub_800B270

	thumb_func_start sub_800B294
sub_800B294:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800B2CC
	ldrb r0, [r1, 0x1]
	adds r2, r0, 0
	cmp r2, 0x54
	bne _0800B2B2
	ldrb r0, [r1, 0x2]
	cmp r0, 0x34
	bne _0800B2B2
	ldrb r0, [r1, 0x3]
	cmp r0, 0x50
	beq _0800B2C8
_0800B2B2:
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _0800B2CC
	cmp r2, 0x54
	bne _0800B2CC
	ldrb r0, [r1, 0x2]
	cmp r0, 0x33
	bne _0800B2CC
	ldrb r0, [r1, 0x3]
	cmp r0, 0x50
	bne _0800B2CC
_0800B2C8:
	movs r0, 0x1
	b _0800B2CE
_0800B2CC:
	movs r0, 0
_0800B2CE:
	pop {r1}
	bx r1
	thumb_func_end sub_800B294

	thumb_func_start sub_800B2D4
sub_800B2D4:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r4, r2, 0
	movs r2, 0
	cmp r2, r4
	bge _0800B324
_0800B2E2:
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r1, 0
	subs r0, 0x41
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _0800B2FE
	adds r0, r1, 0
	adds r0, 0x20
	lsls r0, 24
	lsrs r1, r0, 24
_0800B2FE:
	adds r0, r3, 0
	subs r0, 0x41
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x19
	bhi _0800B312
	adds r0, r3, 0
	adds r0, 0x20
	lsls r0, 24
	lsrs r3, r0, 24
_0800B312:
	cmp r1, r3
	beq _0800B31A
	movs r0, 0x1
	b _0800B326
_0800B31A:
	cmp r1, 0
	beq _0800B324
	adds r2, 0x1
	cmp r2, r4
	blt _0800B2E2
_0800B324:
	movs r0, 0
_0800B326:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_800B2D4

	.align 2, 0 @ Don't pad with nop.
