        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start CreateLoadScreen
CreateLoadScreen:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r5, _080392EC
	ldr r0, [r5]
	cmp r0, 0
	bne _0803927C
	movs r4, 0x9F
	lsls r4, 2
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_0803927C:
	ldr r0, [r5]
	str r6, [r0]
	mov r12, r5
	movs r0, 0xA2
	lsls r0, 1
	mov r8, r0
	ldr r4, _080392F0
	movs r3, 0
	movs r2, 0x3
_0803928E:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0803928E
	bl ResetUnusedInputStruct
	ldr r6, _080392EC
	ldr r0, [r6]
	movs r5, 0xA2
	lsls r5, 1
	adds r0, r5
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _080392F4
	ldr r2, _080392F8
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r7, 0x6
	str r7, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, 0x7
	beq _08039306
	cmp r0, 0x7
	bhi _080392FC
	cmp r0, 0x6
	beq _08039338
	b _08039382
	.align 2, 0
_080392EC: .4byte gUnknown_203B374
_080392F0: .4byte gUnknown_80E75F8
_080392F4: .4byte gUnknown_80E7610
_080392F8: .4byte gUnknown_203B378
_080392FC:
	cmp r0, 0x8
	beq _0803934C
	cmp r0, 0x9
	beq _0803936C
	b _08039382
_08039306:
	bl IsQuickSave
	lsls r0, 24
	cmp r0, 0
	beq _08039324
	ldr r1, [r6]
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _0803931C
	ldr r2, _08039320
	b _08039354
	.align 2, 0
_0803931C: .4byte gUnknown_80E762C
_08039320: .4byte gUnknown_80E7644
_08039324:
	ldr r1, [r6]
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _08039330
	ldr r2, _08039334
	b _08039354
	.align 2, 0
_08039330: .4byte gUnknown_80E762C
_08039334: .4byte gUnknown_80E7684
_08039338:
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _08039344
	ldr r2, _08039348
	b _08039354
	.align 2, 0
_08039344: .4byte gUnknown_80E762C
_08039348: .4byte gUnknown_80E76B8
_0803934C:
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _08039364
	ldr r2, _08039368
_08039354:
	str r2, [sp]
	str r4, [sp, 0x4]
	str r7, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0x1
	bl SetMenuItems
	b _08039382
	.align 2, 0
_08039364: .4byte gUnknown_80E762C
_08039368: .4byte gUnknown_80E76E8
_0803936C:
	adds r0, r1, 0x4
	adds r1, r5
	ldr r3, _080393DC
	ldr r2, _080393E0
	str r2, [sp]
	str r4, [sp, 0x4]
	str r7, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0x1
	bl SetMenuItems
_08039382:
	ldr r4, _080393E4
	ldr r1, [r4]
	adds r0, r1, 0x4
	movs r6, 0xA2
	lsls r6, 1
	adds r1, r6
	ldr r3, _080393E8
	ldr r2, _080393EC
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0x2
	str r2, [sp, 0x8]
	movs r2, 0
	str r2, [sp, 0xC]
	movs r2, 0x2
	bl SetMenuItems
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x1
	movs r2, 0
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0x1
	bl sub_8035CF4
	bl DrawLoadScreenText
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080393DC: .4byte gUnknown_80E762C
_080393E0: .4byte gUnknown_80E7730
_080393E4: .4byte gUnknown_203B374
_080393E8: .4byte gUnknown_80E7784
_080393EC: .4byte gUnknown_80E779C
	thumb_func_end CreateLoadScreen

	thumb_func_start CleanLoadScreen
CleanLoadScreen:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08039418
	ldr r0, [r4]
	cmp r0, 0
	beq _08039410
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08039410:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039418: .4byte gUnknown_203B374
	thumb_func_end CleanLoadScreen

	thumb_func_start sub_803941C
sub_803941C:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _08039458
	movs r0, 0x4
	str r0, [sp]
	ldr r4, _0803945C
	ldr r0, [r4]
	adds r0, 0x54
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xA4
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08039448
	ldr r0, [r4]
	adds r0, 0xA4
	mov r1, sp
	bl sub_8013114
_08039448:
	ldr r0, [sp]
	cmp r0, 0x3
	bhi _08039498
	cmp r0, 0x2
	bcs _08039460
	cmp r0, 0x1
	beq _08039464
	b _08039498
	.align 2, 0
_08039458: .4byte 0x0000ffdc
_0803945C: .4byte gUnknown_203B374
_08039460:
	movs r5, 0x1
	b _08039498
_08039464:
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x7
	beq _08039480
	cmp r0, 0x7
	bhi _08039476
	cmp r0, 0x6
	beq _08039484
	b _08039498
_08039476:
	cmp r0, 0x8
	beq _0803948E
	cmp r0, 0x9
	beq _08039492
	b _08039498
_08039480:
	movs r5, 0x2
	b _08039498
_08039484:
	movs r0, 0
	bl sub_8095240
	movs r5, 0x4
	b _08039498
_0803948E:
	movs r5, 0x9
	b _08039498
_08039492:
	bl sub_80122A8
	movs r5, 0x2E
_08039498:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_803941C

	thumb_func_start DrawLoadScreenText
DrawLoadScreenText:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x150
	bl sub_8011FA8
	mov r8, r0
	movs r0, 0
	bl sub_8008C54
	movs r0, 0
	bl sub_80073B8
	ldr r2, _0803952C
	movs r4, 0
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039530
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0xC
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039534
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x18
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039538
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x24
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _0803953C
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x30
	movs r3, 0
	bl xxx_call_draw_string
	ldr r2, _08039540
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x3C
	movs r3, 0
	bl xxx_call_draw_string
	movs r0, 0
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08039544
	add r4, sp, 0x68
	adds r0, r4, 0
	bl sub_80920D8
	adds r2, r4, 0
	b _0803954E
	.align 2, 0
_0803952C: .4byte gUnknown_80E77BC
_08039530: .4byte gUnknown_80E77C4
_08039534: .4byte gUnknown_80E77CC
_08039538: .4byte gUnknown_80E77D8
_0803953C: .4byte gUnknown_80E77E4
_08039540: .4byte gUnknown_80E77F0
_08039544:
	ldr r1, _08039588
	add r0, sp, 0x68
	bl strcpy
	add r2, sp, 0x68
_0803954E:
	ldr r5, _0803958C
	ldr r0, [r5]
	movs r4, 0xD2
	lsls r4, 1
	adds r0, r4
	ldr r1, _08039590
	bl sub_800D158
	ldr r2, [r5]
	adds r2, r4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x40
	movs r1, 0
	movs r3, 0
	bl xxx_call_draw_string
	bl sub_808D33C
	cmp r0, 0
	bne _08039598
	add r4, sp, 0x90
	ldr r1, _08039594
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	b _080395A6
	.align 2, 0
_08039588: .4byte gUnknown_80E77F8
_0803958C: .4byte gUnknown_203B374
_08039590: .4byte gUnknown_80E7804
_08039594: .4byte gUnknown_80E7808
_08039598:
	add r4, sp, 0x90
	adds r1, r0, 0
	adds r1, 0x4C
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
_080395A6:
	adds r2, r4, 0
	ldr r5, _080395F0
	ldr r0, [r5]
	movs r4, 0xE4
	lsls r4, 1
	adds r0, r4
	ldr r6, _080395F4
	adds r1, r6, 0
	bl sub_800D158
	ldr r2, [r5]
	adds r2, r4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x40
	movs r1, 0xC
	movs r3, 0
	bl xxx_call_draw_string
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _080395E0
	movs r0, 0x7
	bl sub_8095324
	cmp r0, 0
	beq _08039606
_080395E0:
	ldr r0, _080395F8
	cmp r8, r0
	bne _080395FC
	ldr r4, [r5]
	movs r0, 0xF6
	lsls r0, 1
	adds r4, r0
	b _08039676
	.align 2, 0
_080395F0: .4byte gUnknown_203B374
_080395F4: .4byte gUnknown_80E7804
_080395F8: .4byte 0x000f1207
_080395FC:
	ldr r0, [r5]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	b _08039690
_08039606:
	bl sub_8011C1C
	cmp r0, 0x1
	beq _08039624
	cmp r0, 0x2
	beq _08039668
	ldr r0, [r5]
	movs r2, 0xF6
	lsls r2, 1
	adds r0, r2
	ldr r1, _08039620
	b _08039692
	.align 2, 0
_08039620: .4byte gUnknown_80E7824
_08039624:
	movs r0, 0
	movs r1, 0x18
	bl sub_8001658
	cmp r0, 0x7
	beq _08039658
	cmp r0, 0xB
	beq _08039658
	bl sub_8098FB4
	adds r2, r0, 0
	add r0, sp, 0x4
	adds r1, r6, 0
	bl sub_800D158
	ldr r0, [r5]
	movs r3, 0xF6
	lsls r3, 1
	adds r1, r0, r3
	adds r3, 0x24
	adds r2, r0, r3
	add r0, sp, 0x4
	movs r3, 0
	bl xxx_format_string
	b _08039696
_08039658:
	ldr r0, _08039664
	ldr r0, [r0]
	movs r1, 0xF6
	lsls r1, 1
	adds r0, r1
	b _08039690
	.align 2, 0
_08039664: .4byte gUnknown_203B374
_08039668:
	ldr r0, _08039684
	cmp r8, r0
	bne _08039688
	ldr r4, [r5]
	movs r2, 0xF6
	lsls r2, 1
	adds r4, r2
_08039676:
	bl sub_809769C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8090228
	b _08039696
	.align 2, 0
_08039684: .4byte 0x000f1207
_08039688:
	ldr r0, [r5]
	movs r3, 0xF6
	lsls r3, 1
	adds r0, r3
_08039690:
	ldr r1, _0803974C
_08039692:
	bl sub_800D158
_08039696:
	ldr r7, _08039750
	ldr r2, [r7]
	movs r0, 0xF6
	lsls r0, 1
	adds r2, r0
	movs r6, 0
	str r6, [sp]
	movs r0, 0x40
	movs r1, 0x18
	movs r3, 0
	bl xxx_call_draw_string
	ldr r0, _08039754
	ldr r0, [r0]
	add r1, sp, 0x144
	add r2, sp, 0x148
	add r3, sp, 0x14C
	bl DeconstructPlayTime
	ldr r0, [r7]
	movs r5, 0x84
	lsls r5, 2
	adds r0, r5
	ldr r1, _08039758
	add r2, sp, 0x144
	ldr r2, [r2]
	add r3, sp, 0x148
	ldr r3, [r3]
	add r4, sp, 0x14C
	ldr r4, [r4]
	str r4, [sp]
	bl sub_800D158
	ldr r2, [r7]
	adds r2, r5
	str r6, [sp]
	movs r0, 0x40
	movs r1, 0x24
	movs r3, 0
	bl xxx_call_draw_string
	bl sub_8097778
	adds r2, r0, 0
	ldr r0, [r7]
	movs r4, 0x8D
	lsls r4, 2
	adds r0, r4
	ldr r1, _0803975C
	bl sub_800D158
	ldr r2, [r7]
	adds r2, r4
	str r6, [sp]
	movs r0, 0x40
	movs r1, 0x30
	movs r3, 0
	bl xxx_call_draw_string
	ldr r0, _08039760
	cmp r8, r0
	bne _0803976C
	ldr r0, _08039764
	ldr r6, [r0]
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0803976C
	add r5, sp, 0x130
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_808D930
	add r4, sp, 0xE0
	adds r1, r6, 0
	adds r1, 0x50
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_80922B4
	ldr r0, [r7]
	movs r3, 0x96
	lsls r3, 2
	adds r0, r3
	ldr r1, _08039768
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_800D158
	b _0803977C
	.align 2, 0
_0803974C: .4byte gUnknown_80E780C
_08039750: .4byte gUnknown_203B374
_08039754: .4byte gPlayTimeRef
_08039758: .4byte gUnknown_80E7838
_0803975C: .4byte gUnknown_80E7848
_08039760: .4byte 0x000f1207
_08039764: .4byte gUnknown_203B484
_08039768: .4byte gUnknown_80E784C
_0803976C:
	ldr r0, _080397AC
	ldr r0, [r0]
	movs r1, 0x96
	lsls r1, 2
	adds r0, r1
	ldr r1, _080397B0
	bl sub_800D158
_0803977C:
	ldr r0, _080397AC
	ldr r2, [r0]
	movs r3, 0x96
	lsls r3, 2
	adds r2, r3
	movs r0, 0
	str r0, [sp]
	movs r0, 0x40
	movs r1, 0x3C
	movs r3, 0
	bl xxx_call_draw_string
	bl sub_80397B4
	movs r0, 0
	bl sub_80073E0
	add sp, 0x150
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080397AC: .4byte gUnknown_203B374
_080397B0: .4byte gUnknown_80E7854
	thumb_func_end DrawLoadScreenText

	thumb_func_start sub_80397B4
sub_80397B4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	ldr r0, _08039834
	ldr r1, _08039838
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	movs r4, 0
_080397C8:
	adds r0, r4, 0
	adds r0, 0xB0
	ldr r1, [r6, 0x4]
	lsls r2, r4, 2
	ldr r1, [r1, 0x4]
	adds r1, r2
	bl SetBGPaletteBufferColorArray
	adds r4, 0x1
	cmp r4, 0x3F
	ble _080397C8
	movs r7, 0x8
	movs r0, 0x49
	mov r8, r0
	movs r4, 0
_080397E6:
	ldr r0, _0803983C
	lsls r5, r4, 2
	adds r0, r5, r0
	ldr r0, [r0]
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _0803981C
	movs r0, 0x10
	str r0, [sp]
	ldr r0, [r6, 0x4]
	lsls r1, r4, 7
	ldr r0, [r0]
	adds r0, r1
	str r0, [sp, 0x4]
	ldr r0, _08039840
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0
	adds r1, r7, 0
	mov r2, r8
	movs r3, 0x10
	bl sub_8007E20
	adds r7, 0x10
_0803981C:
	adds r4, 0x1
	cmp r4, 0xB
	ble _080397E6
	adds r0, r6, 0
	bl CloseFile
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039834: .4byte gUnknown_80E785C
_08039838: .4byte gTitleMenuFileArchive
_0803983C: .4byte gUnknown_203B3B8
_08039840: .4byte gUnknown_203B388
	thumb_func_end sub_80397B4

        .align 2,0
