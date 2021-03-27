        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8036FDC
sub_8036FDC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r6, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0
	bl ResetSprites
	ldr r5, _080370C0
	ldr r0, [r5]
	cmp r0, 0
	bne _08037016
	ldr r4, _080370C4
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08037016:
	ldr r0, [r5]
	str r6, [r0]
	movs r1, 0
	str r1, [r0, 0x4]
	str r1, [r0, 0x8]
	movs r3, 0
	adds r7, r5, 0
	movs r6, 0xE0
	lsls r6, 1
	movs r4, 0
	movs r5, 0xDE
	lsls r5, 1
_0803702E:
	ldr r0, [r7]
	lsls r2, r3, 3
	adds r1, r0, r6
	adds r1, r2
	str r4, [r1]
	adds r0, r2
	adds r0, r5
	strb r4, [r0]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0803702E
	ldr r0, _080370C0
	mov r12, r0
	movs r5, 0xAE
	lsls r5, 1
	mov r8, r5
	ldr r4, _080370C8
	movs r3, 0
	movs r2, 0x3
_08037054:
	mov r6, r12
	ldr r1, [r6]
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
	bge _08037054
	movs r6, 0
	bl ResetUnusedInputStruct
	ldr r5, _080370C0
	ldr r0, [r5]
	movs r4, 0xAE
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x1C
	adds r1, r4
	ldr r3, _080370CC
	ldr r2, _080370D0
	str r2, [sp]
	str r6, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r6, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r0, [r5]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	bl sub_80376CC
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080370C0: .4byte gUnknown_203B35C
_080370C4: .4byte 0x00000504
_080370C8: .4byte gUnknown_80E653C
_080370CC: .4byte gUnknown_80E6CD0
_080370D0: .4byte gUnknown_80E6CE8
	thumb_func_end sub_8036FDC

	thumb_func_start sub_80370D4
sub_80370D4:
	push {r4,lr}
	ldr r4, _080370EC
	ldr r0, [r4]
	cmp r0, 0
	beq _080370E6
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080370E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080370EC: .4byte gUnknown_203B35C
	thumb_func_end sub_80370D4

	thumb_func_start sub_80370F0
sub_80370F0:
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0x4
	str r0, [sp]
	ldr r5, _08037110
	ldr r4, _08037114
	ldr r1, [r4]
	ldr r0, [r1, 0x8]
	cmp r0, 0x1
	beq _08037148
	cmp r0, 0x1
	bcc _08037118
	cmp r0, 0x2
	beq _08037158
	b _080371A8
	.align 2, 0
_08037110: .4byte 0x0000ffdc
_08037114: .4byte gUnknown_203B35C
_08037118:
	adds r0, r1, 0
	adds r0, 0x1C
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _08037130
	ldr r0, [r4]
	adds r0, 0x1C
	mov r1, sp
	bl sub_8013114
_08037130:
	ldr r0, [sp]
	cmp r0, 0x4
	bne _0803713C
	bl sub_8037748
	b _080371A8
_0803713C:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1, 0x8]
	bl sub_8037900
	b _080371A8
_08037148:
	bl sub_80376CC
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x8]
	bl sub_80371B8
	b _080371A8
_08037158:
	ldr r0, [r1]
	cmp r0, 0x1
	bhi _08037172
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _08037172
	movs r0, 0
	bl sub_8037C10
	cmp r0, 0
	bne _08037172
	movs r0, 0x29
	b _080371AA
_08037172:
	ldr r4, _080371B4
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _0803718C
	ldr r0, [r4]
	adds r0, 0x1C
	mov r1, sp
	bl sub_8013114
_0803718C:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080371A4
	movs r0, 0x3
	bl PlayMenuSoundEffect
	bl sub_8037798
	adds r5, r0, 0
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0x8]
_080371A4:
	bl sub_8037748
_080371A8:
	adds r0, r5, 0
_080371AA:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080371B4: .4byte gUnknown_203B35C
	thumb_func_end sub_80370F0

	thumb_func_start sub_80371B8
sub_80371B8:
	push {r4-r7,lr}
	sub sp, 0x10
	movs r6, 0
	movs r5, 0
	bl sub_8037400
	ldr r7, _0803721C
	ldr r1, [r7]
	ldr r0, [r1]
	cmp r0, 0x1
	bhi _08037228
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bne _08037228
	movs r0, 0
	bl sub_8037C10
	cmp r0, 0
	bne _080371E0
	b _080373AC
_080371E0:
	bl sub_80376CC
	ldr r0, [r7]
	movs r4, 0xAE
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	bl sub_8035CC0
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x1C
	adds r1, r4
	ldr r3, _08037220
	ldr r2, _08037224
	str r2, [sp]
	str r6, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r6, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r0, [r7]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	b _080373AC
	.align 2, 0
_0803721C: .4byte gUnknown_203B35C
_08037220: .4byte gUnknown_80E6C50
_08037224: .4byte gUnknown_80E6C68
_08037228:
	bl sub_80376CC
	ldr r4, _08037250
	ldr r0, [r4]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	cmp r0, 0xF
	bls _08037246
	b _0803734C
_08037246:
	lsls r0, 2
	ldr r1, _08037254
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037250: .4byte gUnknown_203B35C
_08037254: .4byte _08037258
	.align 2, 0
_08037258:
	.4byte _08037298
	.4byte _080372D8
	.4byte _080372B8
	.4byte _080372A8
	.4byte _080372C8
	.4byte _080372D8
	.4byte _080372E8
	.4byte _080372F8
	.4byte _0803734C
	.4byte _08037308
	.4byte _0803734C
	.4byte _08037318
	.4byte _0803734C
	.4byte _08037328
	.4byte _08037338
	.4byte _08037348
_08037298:
	ldr r6, _080372A0
	ldr r5, _080372A4
	b _0803734C
	.align 2, 0
_080372A0: .4byte gUnknown_80E66BC
_080372A4: .4byte gUnknown_80E66D4
_080372A8:
	ldr r6, _080372B0
	ldr r5, _080372B4
	b _0803734C
	.align 2, 0
_080372B0: .4byte gUnknown_80E6D54
_080372B4: .4byte gUnknown_80E6D6C
_080372B8:
	ldr r6, _080372C0
	ldr r5, _080372C4
	b _0803734C
	.align 2, 0
_080372C0: .4byte gUnknown_80E6DDC
_080372C4: .4byte gUnknown_80E6DF4
_080372C8:
	ldr r6, _080372D0
	ldr r5, _080372D4
	b _0803734C
	.align 2, 0
_080372D0: .4byte gUnknown_80E67D4
_080372D4: .4byte gUnknown_80E67EC
_080372D8:
	ldr r6, _080372E0
	ldr r5, _080372E4
	b _0803734C
	.align 2, 0
_080372E0: .4byte gUnknown_80E6748
_080372E4: .4byte gUnknown_80E6760
_080372E8:
	ldr r6, _080372F0
	ldr r5, _080372F4
	b _0803734C
	.align 2, 0
_080372F0: .4byte gUnknown_80E689C
_080372F4: .4byte gUnknown_80E68B4
_080372F8:
	ldr r6, _08037300
	ldr r5, _08037304
	b _0803734C
	.align 2, 0
_08037300: .4byte gUnknown_80E6938
_08037304: .4byte gUnknown_80E6950
_08037308:
	ldr r6, _08037310
	ldr r5, _08037314
	b _0803734C
	.align 2, 0
_08037310: .4byte gUnknown_80E69B0
_08037314: .4byte gUnknown_80E69C8
_08037318:
	ldr r6, _08037320
	ldr r5, _08037324
	b _0803734C
	.align 2, 0
_08037320: .4byte gUnknown_80E6A10
_08037324: .4byte gUnknown_80E6A28
_08037328:
	ldr r6, _08037330
	ldr r5, _08037334
	b _0803734C
	.align 2, 0
_08037330: .4byte gUnknown_80E6A74
_08037334: .4byte gUnknown_80E6A8C
_08037338:
	ldr r6, _08037340
	ldr r5, _08037344
	b _0803734C
	.align 2, 0
_08037340: .4byte gUnknown_80E6B78
_08037344: .4byte gUnknown_80E6B90
_08037348:
	ldr r6, _080373B4
	ldr r5, _080373B8
_0803734C:
	ldr r4, _080373BC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	str r5, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	movs r2, 0
	adds r3, r6, 0
	bl SetMenuItems
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r4, [r4]
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _080373AC
	ldr r0, [r4]
	cmp r0, 0
	bne _080373AC
	bl sub_8035D94
	adds r2, r0, 0
	ldrb r0, [r2]
	cmp r0, 0
	beq _080373AC
	ldr r3, [r2, 0x4]
	cmp r3, 0
	beq _080373AC
	ldr r0, _080373C0
	ldr r1, [r0]
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, r3
	strh r0, [r1]
_080373AC:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080373B4: .4byte gUnknown_80E6BF4
_080373B8: .4byte gUnknown_80E6C0C
_080373BC: .4byte gUnknown_203B35C
_080373C0: .4byte gUnknown_203B460
	thumb_func_end sub_80371B8

	thumb_func_start sub_80373C4
sub_80373C4:
	push {lr}
	movs r0, 0
	movs r1, 0
	bl sub_8005838
	bl sub_80060EC
	bl sub_800CB20
	bl LoadBufferedInputs
	bl TransferBGPaletteBuffer
	bl xxx_call_update_bg_vram
	bl sub_8009908
	bl xxx_call_update_bg_sound_input
	movs r0, 0
	bl ResetSprites
	pop {r0}
	bx r0
	thumb_func_end sub_80373C4

	thumb_func_start sub_80373F4
sub_80373F4:
	ldr r0, _080373FC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080373FC: .4byte gUnknown_203B35C
	thumb_func_end sub_80373F4

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
_080375D4: .4byte gUnknown_203B45C
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
	bl sub_8035D4C
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

	thumb_func_start CreateAdventureLogMenu
CreateAdventureLogMenu:
	push {lr}
	movs r0, 0
	bl CreateAdventureLogScreen
	pop {r0}
	bx r0
	thumb_func_end CreateAdventureLogMenu

	thumb_func_start CleanAdventureLogMenu
CleanAdventureLogMenu:
	push {lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	thumb_func_end CleanAdventureLogMenu

	thumb_func_start UpdateAdventureLogMenu
UpdateAdventureLogMenu:
	push {r4,lr}
	ldr r4, _080382E0
	movs r0, 0x1
	bl HandleAdventureLogInput
	cmp r0, 0x1
	bls _080382D8
	cmp r0, 0x3
	bhi _080382D8
	bl sub_803203C
	movs r4, 0x1
_080382D8:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080382E0: .4byte 0x0000ffdc
	thumb_func_end UpdateAdventureLogMenu

	thumb_func_start sub_80382E4
sub_80382E4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	ldr r5, _08038398
	ldr r0, [r5]
	cmp r0, 0
	bne _0803830E
	movs r4, 0xDA
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_0803830E:
	mov r12, r5
	movs r0, 0xA4
	lsls r0, 1
	mov r9, r0
	ldr r4, _0803839C
	movs r3, 0
	movs r2, 0x3
_0803831C:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0803831C
	bl ResetUnusedInputStruct
	ldr r5, _08038398
	ldr r0, [r5]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	mov r7, r8
	cmp r7, 0x25
	bne _08038370
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x8
	adds r1, r6
	ldr r3, _080383A0
	ldr r2, _080383A4
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x4
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08038370:
	ldr r0, [r5]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r5]
	mov r0, r8
	str r0, [r1]
	movs r0, 0
	str r0, [r1, 0x4]
	bl sub_8038440
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038398: .4byte gUnknown_203B360
_0803839C: .4byte gUnknown_80E6E7C
_080383A0: .4byte gUnknown_80E6E94
_080383A4: .4byte gUnknown_80E6EAC
	thumb_func_end sub_80382E4

	thumb_func_start sub_80383A8
sub_80383A8:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _080383D0
	ldr r0, [r4]
	cmp r0, 0
	beq _080383C8
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080383C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080383D0: .4byte gUnknown_203B360
	thumb_func_end sub_80383A8

	thumb_func_start sub_80383D4
sub_80383D4:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0x2
	str r0, [sp]
	ldr r6, _08038410
	ldr r4, _08038414
	ldr r0, [r4]
	ldr r5, [r0, 0x4]
	cmp r5, 0
	bne _08038434
	adds r0, 0x8
	bl sub_80130A8
	lsls r0, 24
	cmp r0, 0
	bne _080383FE
	ldr r0, [r4]
	adds r0, 0x8
	mov r1, sp
	bl sub_8013114
_080383FE:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803842C
	cmp r0, 0x2
	bhi _08038418
	cmp r0, 0x1
	beq _0803841C
	b _08038430
	.align 2, 0
_08038410: .4byte 0x0000ffdc
_08038414: .4byte gUnknown_203B360
_08038418:
	cmp r0, 0x3
	bne _08038430
_0803841C:
	ldr r0, _08038428
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x4]
	movs r6, 0x1
	b _08038430
	.align 2, 0
_08038428: .4byte gUnknown_203B360
_0803842C:
	ldr r0, [r4]
	str r5, [r0, 0x4]
_08038430:
	bl sub_80384D0
_08038434:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80383D4

	thumb_func_start sub_8038440
sub_8038440:
	push {r4,r5,lr}
	movs r5, 0
	ldr r0, _080384B0
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0xD4
	lsls r3, 1
	add r3, r12
	ldrh r1, [r3]
	ldr r0, _080384B4
	ands r0, r1
	ldr r1, _080384B8
	ands r0, r1
	ldr r4, _080384BC
	ands r0, r4
	ldr r1, _080384C0
	ands r0, r1
	ldr r1, _080384C4
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _080384C8
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
	ldr r1, _080384CC
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x4]
	movs r0, 0x70
	strh r0, [r3, 0x2]
	movs r1, 0xE0
	lsls r1, 3
	ldrh r0, [r3, 0x6]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x6]
	movs r0, 0xD8
	lsls r0, 1
	add r0, r12
	str r5, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080384B0: .4byte gUnknown_203B360
_080384B4: .4byte 0x0000feff
_080384B8: .4byte 0x0000fdff
_080384BC: .4byte 0x0000f3ff
_080384C0: .4byte 0x0000efff
_080384C4: .4byte 0x0000dfff
_080384C8: .4byte 0x00003fff
_080384CC: .4byte 0x00000fff
	thumb_func_end sub_8038440

	thumb_func_start sub_80384D0
sub_80384D0:
	push {r4,r5,lr}
	ldr r5, _08038508
	ldr r2, [r5]
	movs r4, 0xD8
	lsls r4, 1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080384F6
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r2, r1
	subs r1, 0xA8
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080384F6:
	ldr r1, [r5]
	adds r1, r4
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038508: .4byte gUnknown_203B360
	thumb_func_end sub_80384D0

	thumb_func_start sub_803850C
sub_803850C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	ldr r5, _0803859C
	ldr r0, [r5]
	cmp r0, 0
	bne _08038536
	movs r4, 0xDA
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08038536:
	mov r12, r5
	movs r0, 0xA4
	lsls r0, 1
	mov r9, r0
	ldr r4, _080385A0
	movs r3, 0
	movs r2, 0x3
_08038544:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08038544
	bl ResetUnusedInputStruct
	ldr r4, _0803859C
	ldr r0, [r4]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	mov r7, r8
	cmp r7, 0x2E
	bne _080385AC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	adds r1, r6
	ldr r3, _080385A4
	ldr r2, _080385A8
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _080385CE
	.align 2, 0
_0803859C: .4byte gUnknown_203B364
_080385A0: .4byte gUnknown_80E6F20
_080385A4: .4byte gUnknown_80E6F38
_080385A8: .4byte gUnknown_80E7090
_080385AC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _080385F8
	ldr r2, _080385FC
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_080385CE:
	ldr r4, _08038600
	ldr r0, [r4]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x4]
	mov r5, r8
	str r5, [r1]
	bl sub_8038830
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080385F8: .4byte gUnknown_80E6F38
_080385FC: .4byte gUnknown_80E6F50
_08038600: .4byte gUnknown_203B364
	thumb_func_end sub_803850C

	thumb_func_start sub_8038604
sub_8038604:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _0803862C
	ldr r0, [r4]
	cmp r0, 0
	beq _08038624
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08038624:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803862C: .4byte gUnknown_203B364
	thumb_func_end sub_8038604

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
	bl sub_801203C
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
	bl sub_8035D4C
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
