	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8099360
sub_8099360:
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0x13
	bl GetScriptVarValue
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x52
	beq _08099378
	movs r0, 0
	b _0809938E
_08099378:
	movs r0, 0
	movs r1, 0x14
	bl GetScriptVarValue
	lsls r0, 16
	asrs r0, 16
	bl GetDungeonInfo_80A2608
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
	bl GetScriptVarValue
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x50
	beq _080993AC
	movs r0, 0
	b _080993B8
_080993AC:
	movs r0, 0
	movs r1, 0x14
	bl GetScriptVarValue
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
	bl FadeOutAllMusic
	ldr r1, _0809948C
	ldr r2, _08099490
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	bl UpdateFadeInTile
	movs r0, 0
	movs r1, 0x14
	bl sub_80095CC
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
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
	bl AllocGroundMapAction
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
	bl xxx_call_save_unk_text_struct_800641C
	bl GroundMap_Reset
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
_0809953C: .4byte gRealInputs
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
	bl SetVecFromDirectionSpeed
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
	bl DrawDialogueBoxString
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
	bl LoadBufferedInputs
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
_08099620: .4byte gGameOptionsRef
_08099624:
	movs r0, 0x10
	bl FadeOutAllMusic
	bl FreeGroundMapAction
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
_0809968C: .4byte gSystemFileArchive
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
_080996C0: .4byte gSystemFileArchive
_080996C4: .4byte gGameOptionsRef
_080996C8: .4byte gFontPaletteAlt
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

        .align 2,0
