	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start LoadTitleScreen
LoadTitleScreen:
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
	bl RandInt
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
	bl DecompressATFile
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
_08000708: .4byte gLoadScreenBackgroundFileNames
_0800070C: .4byte gLoadScreenBackgroundPaletteFileNames
_08000710: .4byte 0x00005b20
_08000714: .4byte gTitleMenuFileArchive
_08000718: .4byte gTitlePaletteFile
_0800071C: .4byte gUnknown_202B038
_08000720: .4byte 0x06008000
_08000724: .4byte 0x00004b20
	thumb_func_end LoadTitleScreen

	thumb_func_start sub_8000728
sub_8000728:
	ldr r0, _08000730
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08000730: .4byte gUnknown_203B03C
	thumb_func_end sub_8000728

	thumb_func_start QuickSave
QuickSave:
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
	bl SetWindowBGColor
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
_080007B0: .4byte gSaveTextQuicksaving
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
	bl SetDungeonLocationInfo
	bl sub_80140DC
	cmp r5, 0x3
	bhi _080007EC
	add r0, sp, 0x4
	movs r1, 0x1
	bl WriteSavetoPak
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
_0800081C: .4byte gSaveTextYourAdventureHasBeenSaved
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
_08000834: .4byte gSaveTextYourAdventureHasBeenSavedLong
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
_08000850: .4byte gSaveTextTheDataCouldNotBeWritten
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
_08000864: .4byte gSaveTextFailed
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
_08000880: .4byte gRealInputs
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
	thumb_func_end QuickSave

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
	bl SetWindowBGColor
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
_08000944: .4byte gSaveTextError
_08000948:
	ldr r0, _0800094C
	b _08000952
	.align 2, 0
_0800094C: .4byte gSaveTextCantResume
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
_08000960: .4byte gSaveTextMayNotResume
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
_08000990: .4byte gRealInputs
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
	bl FadeOutAllMusic
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
	bl QuickSave
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
	bl xxx_script_related_8001334
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
	bl xxx_script_related_8001334
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
	bl GetSaveBeforeEntering
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
	bl IncrementNumAdventures
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
	bl QuickSave
	b _08000E1E
_08000E0C:
	adds r0, r6, 0
	bl GetSaveBeforeEntering
	lsls r0, 24
	cmp r0, 0
	bne _08000E1E
	movs r0, 0
	bl QuickSave
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
	bl PrepareQuickSaveRead
	adds r7, r4, 0
	adds r7, 0x7C
	b _08000F2E
	.align 2, 0
_08000F24: .4byte gUnknown_203B03C
_08000F28:
	movs r0, 0
	bl xxx_update_stuff
_08000F2E:
	bl ReadQuickSave
	lsls r0, 24
	cmp r0, 0
	bne _08000F28
	bl IsQuickSaveValid
	lsls r0, 24
	lsrs r5, r0, 24
	bl FinishQuickSaveRead
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
	bl xxx_call_start_bg_music
	b _08000F78
	.align 2, 0
_08000F64: .4byte 0x000f1209
_08000F68:
	bl GeneratePelipperJobs
	bl sub_80961B4
	bl sub_808ED00
	adds r7, r4, 0
	adds r7, 0x7C
_08000F78:
	cmp r5, 0
	beq _08000F92
	adds r0, r4, 0
	bl xxx_dungeon_8001340
	bl sub_8099648
	bl SetWindowBGColor
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
	bl SetDungeonLocationInfo
	bl xxx_call_stop_bgm
	movs r1, 0
	ldrsh r0, [r7, r1]
	cmp r0, r6
	bne _08000FD8
	ldr r0, [r4, 0x74]
	ldr r1, [sp]
	movs r2, 0x1
	bl PrepareQuickSaveWrite
	b _08000FFA
_08000FD8:
	ldr r0, [r4, 0x74]
	ldr r1, [sp]
	movs r2, 0
	bl PrepareQuickSaveWrite
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
	bl WriteQuickSave
	cmp r0, 0x2
	beq _08001006
	cmp r0, 0x3
	bne _08000FE4
_08001006:
	bl FinishQuickSaveWrite
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
	bl GetPlayerPokemonStruct
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
	bl CopyMonsterNametoBuffer
	mov r0, sp
	adds r1, r4, 0
	bl CopyStringtoBuffer
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
	bl CopyMonsterNametoBuffer
	mov r0, sp
	adds r1, r4, 0
	bl CopyStringtoBuffer
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
	bl RandInt
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
	bl FillInventoryGaps
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
_080012B8: .4byte gTeamInventory_203B460
_080012BC: .4byte gRecruitedPokemonRef
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
	bl FillInventoryGaps
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
_08001324: .4byte gTeamInventory_203B460
_08001328: .4byte gRecruitedPokemonRef
	thumb_func_end sub_80012C0

        .align 2,0
