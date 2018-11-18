	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/m4a_constants.inc"

	.syntax unified

	.text

	thumb_func_start umul3232H32
umul3232H32:
	adr r2, _080AE268
	bx r2
	.arm
_080AE268:
	umull r2, r3, r0, r1
	add r0, r3, 0
	bx lr
	thumb_func_end umul3232H32

	thumb_func_start SoundMain
SoundMain:
	ldr r0, lt_SOUND_INFO_PTR
	ldr r0, [r0]
	ldr r2, lt_ID_NUMBER
	ldr r3, [r0, o_SoundInfo_ident]
	cmp r2, r3
	beq SoundMain_1
	bx lr @ Exit the function if ident doesn't match ID_NUMBER.
SoundMain_1:
	adds r3, 1
	str r3, [r0, o_SoundInfo_ident]
	push {r4-r7,lr}
	mov r1, r8
	mov r2, r9
	mov r3, r10
	mov r4, r11
	push {r0-r4}
	sub sp, 0x18
	ldrb r1, [r0, o_SoundInfo_maxLines]
	cmp r1, 0 @ if maxLines is 0, there is no maximum
	beq SoundMain_3
	ldr r2, lt_REG_VCOUNT
	ldrb r2, [r2]
	cmp r2, VCOUNT_VBLANK
	bhs SoundMain_2
	adds r2, TOTAL_SCANLINES
SoundMain_2:
	adds r1, r2
SoundMain_3:
	str r1, [sp, 0x14]
	ldr r3, [r0, o_SoundInfo_func]
	cmp r3, 0
	beq SoundMain_4
	ldr r0, [r0, o_SoundInfo_intp]
	bl call_r3
	ldr r0, [sp, 0x18]
SoundMain_4:
	ldr r3, [r0, o_SoundInfo_CgbSound]
	bl call_r3
	ldr r0, [sp, 0x18]
	ldr r3, [r0, o_SoundInfo_pcmSamplesPerVBlank]
	mov r8, r3
	ldr r5, lt_o_SoundInfo_pcmBuffer
	adds r5, r0
	ldrb r4, [r0, o_SoundInfo_pcmDmaCounter]
	subs r7, r4, 1
	bls SoundMain_5
	ldrb r1, [r0, o_SoundInfo_pcmDmaPeriod]
	subs r1, r7
	mov r2, r8
	muls r2, r1
	adds r5, r2
SoundMain_5:
	str r5, [sp, 0x8]
	ldr r6, lt_PCM_DMA_BUF_SIZE
	ldr r3, lt_SoundMainRAM_Buffer
	bx r3

	.align 2, 0
lt_SOUND_INFO_PTR:        .word SOUND_INFO_PTR
lt_ID_NUMBER:             .word ID_NUMBER
lt_SoundMainRAM_Buffer:   .word SoundMainRAM_Buffer + 1
lt_REG_VCOUNT:            .word REG_VCOUNT
lt_o_SoundInfo_pcmBuffer: .word o_SoundInfo_pcmBuffer
lt_PCM_DMA_BUF_SIZE:      .word PCM_DMA_BUF_SIZE
	thumb_func_end SoundMain

	thumb_func_start SoundMainRAM
SoundMainRAM:
	ldrb r3, [r0, o_SoundInfo_reverb]
	cmp r3, 0
	beq SoundMainRAM_NoReverb
	adr r1, SoundMainRAM_Reverb
	bx r1
	.arm
SoundMainRAM_Reverb:
	cmp r4, 0x2
	addeq r7, r0, o_SoundInfo_pcmBuffer
	addne r7, r5, r8
	mov r4, r8
_080AE314:
	ldrsb r0, [r5, r6]
	ldrsb r1, [r5]
	add r0, r0, r1
	ldrsb r1, [r7, r6]
	add r0, r0, r1
	ldrsb r1, [r7], 0x1
	add r0, r0, r1
	mul r1, r0, r3
	mov r0, r1, asr 9
	tst r0, 0x80
	addne r0, r0, 0x1
	strb r0, [r5, r6]
	strb r0, [r5], 0x1
	subs r4, r4, 0x1
	bgt _080AE314
	add r0, pc, 0x2F
	bx r0
	.thumb
SoundMainRAM_NoReverb:
	movs r0, 0
	mov r1, r8
	adds r6, r5
	lsrs r1, 3
	bcc SoundMainRAM_NoReverb_Ok
	stm r5!, {r0}
	stm r6!, {r0}
SoundMainRAM_NoReverb_Ok:
	lsrs r1, 1
	bcc SoundMainRAM_NoReverb_Loop
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
SoundMainRAM_NoReverb_Loop:
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	subs r1, 0x1
	bgt SoundMainRAM_NoReverb_Loop
_080AE386:
	ldr r4, [sp, 0x18]
	ldr r0, [r4, o_SoundInfo_divFreq]
	mov r12, r0
	ldrb r0, [r4, o_SoundInfo_maxChans]
	adds r4, o_SoundInfo_chans
SoundMainRAM_ChanLoop:
	str r0, [sp, 0x4]
	ldr r3, [r4, o_SoundChannel_wav]
	ldr r0, [sp, 0x14]
	cmp r0, 0
	beq _080AE3B0
	ldr r1, =REG_VCOUNT
	ldrb r1, [r1]
	cmp r1, VCOUNT_VBLANK
	bhs _080AE3A4
	adds r1, TOTAL_SCANLINES
_080AE3A4:
	cmp r1, r0
	bcc _080AE3B0
	b _080AE682

	.pool

_080AE3B0:
	ldrb r6, [r4, o_SoundChannel_status]
	movs r0, 0xC7
	tst r0, r6
	bne _080AE3BA
	b _080AE678
_080AE3BA:
	movs r0, 0x80
	tst r0, r6
	beq _080AE3EA
	movs r0, 0x40
	tst r0, r6
	bne _080AE3FA
	movs r6, 0x3
	strb r6, [r4, o_SoundChannel_status]
	adds r0, r3, 0
	adds r0, 0x10
	str r0, [r4, o_SoundChannel_cp]
	ldr r0, [r3, 0xC]
	str r0, [r4, o_SoundChannel_ct]
	movs r5, 0
	strb r5, [r4, o_SoundChannel_ev]
	str r5, [r4, o_SoundChannel_fw]
	ldrb r2, [r3, 0x3]
	movs r0, 0xC0
	tst r0, r2
	beq _080AE442
	movs r0, 0x10
	orrs r6, r0
	strb r6, [r4, o_SoundChannel_status]
	b _080AE442
_080AE3EA:
	ldrb r5, [r4, o_SoundChannel_ev]
	movs r0, 0x4
	tst r0, r6
	beq _080AE400
	ldrb r0, [r4, o_SoundChannel_iel]
	subs r0, 0x1
	strb r0, [r4, o_SoundChannel_iel]
	bhi _080AE450
_080AE3FA:
	movs r0, 0
	strb r0, [r4, o_SoundChannel_status]
	b _080AE678
_080AE400:
	movs r0, 0x40
	tst r0, r6
	beq _080AE420
	ldrb r0, [r4, o_SoundChannel_release]
	muls r5, r0
	lsrs r5, 8
	ldrb r0, [r4, o_SoundChannel_iev]
	cmp r5, r0
	bhi _080AE450
_080AE412:
	ldrb r5, [r4, o_SoundChannel_iev]
	cmp r5, 0
	beq _080AE3FA
	movs r0, 0x4
	orrs r6, r0
	strb r6, [r4, o_SoundChannel_status]
	b _080AE450
_080AE420:
	movs r2, 0x3
	ands r2, r6
	cmp r2, 0x2
	bne _080AE43E
	ldrb r0, [r4, o_SoundChannel_decay]
	muls r5, r0
	lsrs r5, 8
	ldrb r0, [r4, o_SoundChannel_sustain]
	cmp r5, r0
	bhi _080AE450
	adds r5, r0, 0
	beq _080AE412
	subs r6, 0x1
	strb r6, [r4, o_SoundChannel_status]
	b _080AE450
_080AE43E:
	cmp r2, 0x3
	bne _080AE450
_080AE442:
	ldrb r0, [r4, o_SoundChannel_attack]
	adds r5, r0
	cmp r5, 0xFF
	bcc _080AE450
	movs r5, 0xFF
	subs r6, 0x1
	strb r6, [r4, o_SoundChannel_status]
_080AE450:
	strb r5, [r4, o_SoundChannel_ev]
	ldr r0, [sp, 0x18]
	ldrb r0, [r0, o_SoundChannel_release]
	adds r0, 0x1
	muls r0, r5
	lsrs r5, r0, 4
	ldrb r0, [r4, o_SoundChannel_rightVolume]
	muls r0, r5
	lsrs r0, 8
	strb r0, [r4, o_SoundChannel_er]
	ldrb r0, [r4, o_SoundChannel_leftVolume]
	muls r0, r5
	lsrs r0, 8
	strb r0, [r4, o_SoundChannel_el]
	movs r0, 0x10
	ands r0, r6
	str r0, [sp, 0x10]
	beq _080AE484
	adds r0, r3, 0
	adds r0, 0x10
	ldr r1, [r3, 0x8]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r3, 0xC]
	subs r0, r1
	str r0, [sp, 0x10]
_080AE484:
	ldr r5, [sp, 0x8]
	ldr r2, [r4, o_SoundChannel_ct]
	ldr r3, [r4, o_SoundChannel_cp]
	adr r0, _080AE490
	bx r0
	.arm
_080AE490:
	str r8, [sp]
	ldrb r10, [r4, o_SoundChannel_er]
	ldrb r11, [r4, o_SoundChannel_el]
	mov r10, r10, lsl 16
	mov r11, r11, lsl 16
	ldrb r0, [r4, o_SoundChannel_type]
	tst r0, 0x8
	beq _080AE5D0
_080AE4B0:
	cmp r2, 0x4
	ble _080AE520
	subs r2, r2, r8
	movgt lr, 0
	bgt _080AE4DC
	mov lr, r8
	add r2, r2, r8
	sub r8, r2, 0x4
	sub lr, lr, r8
	ands r2, r2, 0x3
	moveq r2, 0x4
_080AE4DC:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_080AE4E4:
	ldrsb r0, [r3], 0x1
	mul r1, r10, r0
	bic r1, r1, 0xFF0000
	add r6, r1, r6, ror 8
	mul r1, r11, r0
	bic r1, r1, 0xFF0000
	add r7, r1, r7, ror 8
	adds r5, r5, 0x40000000
	bcc _080AE4E4
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt _080AE4DC
	adds r8, r8, lr
	beq _080AE664
_080AE520:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_080AE528:
	ldrsb r0, [r3], 0x1
	mul r1, r10, r0
	bic r1, r1, 0xFF0000
	add r6, r1, r6, ror 8
	mul r1, r11, r0
	bic r1, r1, 0xFF0000
	add r7, r1, r7, ror 8
	subs r2, r2, 0x1
	beq _080AE598
_080AE54C:
	adds r5, r5, 0x40000000
	bcc _080AE528
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt _080AE4B0
	b _080AE664
_080AE568:
	ldr r0, [sp, 0x18]
	cmp r0, 0
	beq _080AE58C
	ldr r3, [sp, 0x14]
	rsb r9, r2, 0
_080AE57C:
	adds r2, r0, r2
	bgt _080AE634
	sub r9, r9, r0
	b _080AE57C
_080AE58C:
	ldmia sp!, {r4,r12}
	mov r2, 0
	b _080AE5A8
_080AE598:
	ldr r2, [sp, 0x10]
	cmp r2, 0
	ldrne r3, [sp, 0xC]
	bne _080AE54C
_080AE5A8:
	strb r2, [r4, o_SoundChannel_status]
	mov r0, r5, lsr 30
	bic r5, r5, 0xC0000000
	rsb r0, r0, 0x3
	mov r0, r0, lsl 3
	mov r6, r6, ror r0
	mov r7, r7, ror r0
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	b _080AE66C
_080AE5D0:
	stmdb sp!, {r4,r12}
	ldr lr, [r4, o_SoundChannel_fw]
	ldr r1, [r4, o_SoundChannel_freq]
	mul r4, r12, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, 0x1]!
	sub r1, r1, r0
_080AE5EC:
	ldr r6, [r5]
	ldr r7, [r5, 0x630]
_080AE5F4:
	mul r9, lr, r1
	add r9, r0, r9, asr 23
	mul r12, r10, r9
	bic r12, r12, 0xFF0000
	add r6, r12, r6, ror 8
	mul r12, r11, r9
	bic r12, r12, 0xFF0000
	add r7, r12, r7, ror 8
	add lr, lr, r4
	movs r9, lr, lsr 23
	beq _080AE640
	bic lr, lr, 0x3F800000
	subs r2, r2, r9
	ble _080AE568
	subs r9, r9, 0x1
	addeq r0, r0, r1
_080AE634:
	ldrsbne r0, [r3, r9]!
	ldrsb r1, [r3, 0x1]!
	sub r1, r1, r0
_080AE640:
	adds r5, r5, 0x40000000
	bcc _080AE5F4
	str r7, [r5, 0x630]
	str r6, [r5], 0x4
	subs r8, r8, 0x4
	bgt _080AE5EC
	sub r3, r3, 0x1
	ldmia sp!, {r4,r12}
	str lr, [r4, o_SoundChannel_fw]
_080AE664:
	str r2, [r4, o_SoundChannel_ct]
	str r3, [r4, o_SoundChannel_cp]
_080AE66C:
	ldr r8, [sp]
	add r0, pc, 0x1
	bx r0
	.thumb
_080AE678:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	ble _080AE682
	adds r4, SoundChannel_size
	b SoundMainRAM_ChanLoop
_080AE682:
	ldr r0, [sp, 0x18]
	ldr r3, =ID_NUMBER
	str r3, [r0]
	add sp, 0x1C
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}

call_r3:
	bx r3
	.pool
	thumb_func_end SoundMainRAM

	thumb_func_start sub_80AE69C
sub_80AE69C:
	mov r12, r4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	movs r4, 0
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	mov r4, r12
	bx lr
	thumb_func_end sub_80AE69C

	thumb_func_start sub_80AE6B4
sub_80AE6B4:
	ldr r3, [r0, 0x2C]
	cmp r3, 0
	beq _080AE6D2
	ldr r1, [r0, 0x34]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq _080AE6C6
	str r1, [r2, 0x34]
	b _080AE6C8
_080AE6C6:
	str r1, [r3, 0x20]
_080AE6C8:
	cmp r1, 0
	beq _080AE6CE
	str r2, [r1, 0x30]
_080AE6CE:
	movs r1, 0
	str r1, [r0, 0x2C]
_080AE6D2:
	bx lr
	thumb_func_end sub_80AE6B4

	thumb_func_start sub_80AE6D4
sub_80AE6D4:
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _080AE6F8
_080AE6DE:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _080AE6EC
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
_080AE6EC:
	adds r0, r4, 0
	bl sub_80AE6B4
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _080AE6DE
_080AE6F8:
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80AE6D4

	thumb_func_start sub_80AE704
sub_80AE704:
	mov r12, lr
	movs r1, 0x24
	ldr r2, _080AE734
_080AE70A:
	ldr r3, [r2]
	bl _080AE71E
	stm r0!, {r3}
	adds r2, 0x4
	subs r1, 0x1
	bgt _080AE70A
	bx r12
	thumb_func_end sub_80AE704

	.align 2, 0
	.thumb_func
_080AE71C:
	ldrb r3, [r2]

	.thumb_func
_080AE71E:
	push {r0}
	lsrs r0, r2, 25
	bne _080AE730
	ldr r0, _080AE734
	cmp r2, r0
	bcc _080AE72E
	lsrs r0, r2, 14
	beq _080AE730
_080AE72E:
	movs r3, 0
_080AE730:
	pop {r0}
	bx lr
	.align 2, 0
_080AE734: .4byte gUnknown_826F98C

	thumb_func_start sub_80AE738
sub_80AE738:
	ldr r2, [r1, 0x40]
_080AE73A:
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	b _080AE71E
	thumb_func_end sub_80AE738

	thumb_func_start sub_80AE744
sub_80AE744:
	push {lr}
_080AE746:
	ldr r2, [r1, 0x40]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	ldrb r3, [r2, 0x2]
	orrs r0, r3
	lsls r0, 8
	ldrb r3, [r2, 0x1]
	orrs r0, r3
	lsls r0, 8
	bl _080AE71C
	orrs r0, r3
	str r0, [r1, 0x40]
	pop {r0}
	bx r0
	thumb_func_end sub_80AE744

	thumb_func_start sub_80AE764
sub_80AE764:
	ldrb r2, [r1, 0x2]
	cmp r2, 0x3
	bcs _080AE77C
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r1, 0x40]
	adds r2, 0x4
	str r2, [r3, 0x44]
	ldrb r2, [r1, 0x2]
	adds r2, 0x1
	strb r2, [r1, 0x2]
	b sub_80AE744
_080AE77C:
	b sub_80AE6D4
	thumb_func_end sub_80AE764

	thumb_func_start sub_80AE780
sub_80AE780:
	ldrb r2, [r1, 0x2]
	cmp r2, 0
	beq _080AE792
	subs r2, 0x1
	strb r2, [r1, 0x2]
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r3, 0x44]
	str r2, [r1, 0x40]
_080AE792:
	bx lr
	thumb_func_end sub_80AE780

	thumb_func_start sub_80AE794
sub_80AE794:
	push {lr}
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	cmp r3, 0
	bne _080AE7A4
	adds r2, 0x1
	str r2, [r1, 0x40]
	b _080AE746
_080AE7A4:
	ldrb r3, [r1, 0x3]
	adds r3, 0x1
	strb r3, [r1, 0x3]
	mov r12, r3
	bl sub_80AE738
	cmp r12, r3
	bcs _080AE7B6
	b _080AE746
_080AE7B6:
	movs r3, 0
	strb r3, [r1, 0x3]
	adds r2, 0x5
	str r2, [r1, 0x40]
	pop {r0}
	bx r0
	thumb_func_end sub_80AE794

	thumb_func_start sub_80AE7C4
sub_80AE7C4:
	mov r12, lr
	bl sub_80AE738
	strb r3, [r1, 0x1D]
	bx r12
	thumb_func_end sub_80AE7C4

	thumb_func_start sub_80AE7D0
sub_80AE7D0:
	mov r12, lr
	bl sub_80AE738
	lsls r3, 1
	strh r3, [r0, 0x1C]
	ldrh r2, [r0, 0x1E]
	muls r3, r2
	lsrs r3, 8
	strh r3, [r0, 0x20]
	bx r12
	thumb_func_end sub_80AE7D0

	thumb_func_start sub_80AE7E4
sub_80AE7E4:
	mov r12, lr
	bl sub_80AE738
	strb r3, [r1, 0xA]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end sub_80AE7E4

	thumb_func_start sub_80AE7F8
sub_80AE7F8:
	mov r12, lr
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	adds r2, 0x1
	str r2, [r1, 0x40]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 2
	ldr r3, [r0, 0x30]
	adds r2, r3
	ldr r3, [r2]
	bl _080AE71E
	str r3, [r1, 0x24]
	ldr r3, [r2, 0x4]
	bl _080AE71E
	str r3, [r1, 0x28]
	ldr r3, [r2, 0x8]
	bl _080AE71E
	str r3, [r1, 0x2C]
	bx r12
	thumb_func_end sub_80AE7F8

	thumb_func_start sub_80AE828
sub_80AE828:
	mov r12, lr
	bl sub_80AE738
	strb r3, [r1, 0x12]
	ldrb r3, [r1]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end sub_80AE828

	thumb_func_start sub_80AE83C
sub_80AE83C:
	mov r12, lr
	bl sub_80AE738
	subs r3, 0x40
	strb r3, [r1, 0x14]
	ldrb r3, [r1]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end sub_80AE83C

	thumb_func_start sub_80AE850
sub_80AE850:
	mov r12, lr
	bl sub_80AE738
	subs r3, 0x40
	strb r3, [r1, 0xE]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end sub_80AE850

	thumb_func_start sub_80AE864
sub_80AE864:
	mov r12, lr
	bl sub_80AE738
	strb r3, [r1, 0xF]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end sub_80AE864

	thumb_func_start sub_80AE878
sub_80AE878:
	mov r12, lr
	bl sub_80AE738
	strb r3, [r1, 0x1B]
	bx r12
	thumb_func_end sub_80AE878

	thumb_func_start sub_80AE884
sub_80AE884:
	mov r12, lr
	bl sub_80AE738
	ldrb r0, [r1, 0x18]
	cmp r0, r3
	beq _080AE89A
	strb r3, [r1, 0x18]
	ldrb r3, [r1]
	movs r2, 0xF
	orrs r3, r2
	strb r3, [r1]
_080AE89A:
	bx r12
	thumb_func_end sub_80AE884

	thumb_func_start sub_80AE89C
sub_80AE89C:
	mov r12, lr
	bl sub_80AE738
	subs r3, 0x40
	strb r3, [r1, 0xC]
	ldrb r3, [r1]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1]
	bx r12
	thumb_func_end sub_80AE89C

	thumb_func_start sub_80AE8B0
sub_80AE8B0:
	mov r12, lr
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	adds r2, 0x1
	ldr r0, _080AE8C4
	adds r0, r3
	bl _080AE73A
	strb r3, [r0]
	bx r12
	.align 2, 0
_080AE8C4: .4byte 0x04000060
	thumb_func_end sub_80AE8B0

	thumb_func_start m4aSoundVSync
m4aSoundVSync:
	ldr r0, _080AEB74
	ldr r0, [r0]
	ldr r2, _080AEB78
	ldr r3, [r0]
	subs r3, r2
	cmp r3, 0x1
	bhi _080AE908
	ldrb r1, [r0, 0x4]
	subs r1, 0x1
	strb r1, [r0, 0x4]
	bgt _080AE908
	ldrb r1, [r0, 0xB]
	strb r1, [r0, 0x4]
	ldr r2, _080AE90C
	ldr r1, [r2, 0x8]
	lsls r1, 7
	bcc _080AE8EE
	ldr r1, _080AE910
	str r1, [r2, 0x8]
_080AE8EE:
	ldr r1, [r2, 0x14]
	lsls r1, 7
	bcc _080AE8F8
	ldr r1, _080AE910
	str r1, [r2, 0x14]
_080AE8F8:
	movs r1, 0x4
	lsls r1, 8
	strh r1, [r2, 0xA]
	strh r1, [r2, 0x16]
	movs r1, 0xB6
	lsls r1, 8
	strh r1, [r2, 0xA]
	strh r1, [r2, 0x16]
_080AE908:
	bx lr
	.align 2, 0
_080AE90C: .4byte 0x040000bc
_080AE910: .4byte 0x84400004
	thumb_func_end m4aSoundVSync

	thumb_func_start sub_80AE914
sub_80AE914:
	ldr r2, _080AEB78
	ldr r3, [r0, 0x34]
	cmp r2, r3
	beq _080AE91E
	bx lr
_080AE91E:
	adds r3, 0x1
	str r3, [r0, 0x34]
	push {r0,lr}
	ldr r3, [r0, 0x38]
	cmp r3, 0
	beq _080AE930
	ldr r0, [r0, 0x3C]
	bl _080AEB6C
_080AE930:
	pop {r0}
	push {r4-r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	adds r7, r0, 0
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080AE948
	b _080AEB5C
_080AE948:
	ldr r0, _080AEB74
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, 0
	bl sub_80AF800
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bge _080AE95C
	b _080AEB5C
_080AE95C:
	ldrh r0, [r7, 0x22]
	ldrh r1, [r7, 0x20]
	adds r0, r1
	b _080AEAAC
_080AE964:
	ldrb r6, [r7, 0x8]
	ldr r5, [r7, 0x2C]
	movs r3, 0x1
	movs r4, 0
_080AE96C:
	ldrb r0, [r5]
	movs r1, 0x80
	tst r1, r0
	bne _080AE976
	b _080AEA88
_080AE976:
	mov r10, r3
	orrs r4, r3
	mov r11, r4
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _080AE9AA
_080AE982:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _080AE99E
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq _080AE9A4
	subs r0, 0x1
	strb r0, [r4, 0x10]
	bne _080AE9A4
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
	b _080AE9A4
_080AE99E:
	adds r0, r4, 0
	bl sub_80AF2FC
_080AE9A4:
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _080AE982
_080AE9AA:
	ldrb r3, [r5]
	movs r0, 0x40
	tst r0, r3
	beq _080AEA28
	adds r0, r5, 0
	bl sub_80AF310
	movs r0, 0x80
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, 0xF]
	movs r0, 0x40
	strb r0, [r5, 0x13]
	movs r0, 0x16
	strb r0, [r5, 0x19]
	movs r0, 0x1
	adds r1, r5, 0x6
	strb r0, [r1, 0x1E]
	b _080AEA28
_080AE9D0:
	ldr r2, [r5, 0x40]
	ldrb r1, [r2]
	cmp r1, 0x80
	bcs _080AE9DC
	ldrb r1, [r5, 0x7]
	b _080AE9E6
_080AE9DC:
	adds r2, 0x1
	str r2, [r5, 0x40]
	cmp r1, 0xBD
	bcc _080AE9E6
	strb r1, [r5, 0x7]
_080AE9E6:
	cmp r1, 0xCF
	bcc _080AE9FC
	mov r0, r8
	ldr r3, [r0, 0x38]
	adds r0, r1, 0
	subs r0, 0xCF
	adds r1, r7, 0
	adds r2, r5, 0
	bl _080AEB6C
	b _080AEA28
_080AE9FC:
	cmp r1, 0xB0
	bls _080AEA1E
	adds r0, r1, 0
	subs r0, 0xB1
	strb r0, [r7, 0xA]
	mov r3, r8
	ldr r3, [r3, 0x34]
	lsls r0, 2
	ldr r3, [r3, r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl _080AEB6C
	ldrb r0, [r5]
	cmp r0, 0
	beq _080AEA84
	b _080AEA28
_080AEA1E:
	ldr r0, _080AEB70
	subs r1, 0x80
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r5, 0x1]
_080AEA28:
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	beq _080AE9D0
	subs r0, 0x1
	strb r0, [r5, 0x1]
	ldrb r1, [r5, 0x19]
	cmp r1, 0
	beq _080AEA84
	ldrb r0, [r5, 0x17]
	cmp r0, 0
	beq _080AEA84
	ldrb r0, [r5, 0x1C]
	cmp r0, 0
	beq _080AEA4A
	subs r0, 0x1
	strb r0, [r5, 0x1C]
	b _080AEA84
_080AEA4A:
	ldrb r0, [r5, 0x1A]
	adds r0, r1
	strb r0, [r5, 0x1A]
	adds r1, r0, 0
	subs r0, 0x40
	lsls r0, 24
	bpl _080AEA5E
	lsls r2, r1, 24
	asrs r2, 24
	b _080AEA62
_080AEA5E:
	movs r0, 0x80
	subs r2, r0, r1
_080AEA62:
	ldrb r0, [r5, 0x17]
	muls r0, r2
	asrs r2, r0, 6
	ldrb r0, [r5, 0x16]
	eors r0, r2
	lsls r0, 24
	beq _080AEA84
	strb r2, [r5, 0x16]
	ldrb r0, [r5]
	ldrb r1, [r5, 0x18]
	cmp r1, 0
	bne _080AEA7E
	movs r1, 0xC
	b _080AEA80
_080AEA7E:
	movs r1, 0x3
_080AEA80:
	orrs r0, r1
	strb r0, [r5]
_080AEA84:
	mov r3, r10
	mov r4, r11
_080AEA88:
	subs r6, 0x1
	ble _080AEA94
	movs r0, 0x50
	adds r5, r0
	lsls r3, 1
	b _080AE96C
_080AEA94:
	ldr r0, [r7, 0xC]
	adds r0, 0x1
	str r0, [r7, 0xC]
	cmp r4, 0
	bne _080AEAA6
	movs r0, 0x80
	lsls r0, 24
	str r0, [r7, 0x4]
	b _080AEB5C
_080AEAA6:
	str r4, [r7, 0x4]
	ldrh r0, [r7, 0x22]
	subs r0, 0x96
_080AEAAC:
	strh r0, [r7, 0x22]
	cmp r0, 0x96
	bcc _080AEAB4
	b _080AE964
_080AEAB4:
	ldrb r2, [r7, 0x8]
	ldr r5, [r7, 0x2C]
_080AEAB8:
	ldrb r0, [r5]
	movs r1, 0x80
	tst r1, r0
	beq _080AEB52
	movs r1, 0xF
	tst r1, r0
	beq _080AEB52
	mov r9, r2
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80AF8C8
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _080AEB48
_080AEAD6:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	bne _080AEAE6
	adds r0, r4, 0
	bl sub_80AF2FC
	b _080AEB42
_080AEAE6:
	ldrb r0, [r4, 0x1]
	movs r6, 0x7
	ands r6, r0
	ldrb r3, [r5]
	movs r0, 0x3
	tst r0, r3
	beq _080AEB04
	bl sub_80AEBC0
	cmp r6, 0
	beq _080AEB04
	ldrb r0, [r4, 0x1D]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1D]
_080AEB04:
	ldrb r3, [r5]
	movs r0, 0xC
	tst r0, r3
	beq _080AEB42
	ldrb r1, [r4, 0x8]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _080AEB18
	movs r2, 0
_080AEB18:
	cmp r6, 0
	beq _080AEB36
	mov r0, r8
	ldr r3, [r0, 0x30]
	adds r1, r2, 0
	ldrb r2, [r5, 0x9]
	adds r0, r6, 0
	bl _080AEB6C
	str r0, [r4, 0x20]
	ldrb r0, [r4, 0x1D]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, 0x1D]
	b _080AEB42
_080AEB36:
	adds r1, r2, 0
	ldrb r2, [r5, 0x9]
	ldr r0, [r4, 0x24]
	bl sub_80AEE80
	str r0, [r4, 0x20]
_080AEB42:
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _080AEAD6
_080AEB48:
	ldrb r0, [r5]
	movs r1, 0xF0
	ands r0, r1
	strb r0, [r5]
	mov r2, r9
_080AEB52:
	subs r2, 0x1
	ble _080AEB5C
	movs r0, 0x50
	adds r5, r0
	bgt _080AEAB8
_080AEB5C:
	ldr r0, _080AEB78
	str r0, [r7, 0x34]
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}
_080AEB6C:
	bx r3
	.align 2, 0
_080AEB70: .4byte gUnknown_826FC00
_080AEB74: .4byte SOUND_INFO_PTR
_080AEB78: .4byte 0x68736d53
	thumb_func_end sub_80AE914

	thumb_func_start sub_80AEB7C
sub_80AEB7C:
	push {r4-r6,lr}
	adds r5, r1, 0
	ldrb r1, [r5]
	movs r0, 0x80
	tst r0, r1
	beq _080AEBB4
	ldr r4, [r5, 0x20]
	cmp r4, 0
	beq _080AEBB2
	movs r6, 0
_080AEB90:
	ldrb r0, [r4]
	cmp r0, 0
	beq _080AEBAA
	ldrb r0, [r4, 0x1]
	movs r3, 0x7
	ands r0, r3
	beq _080AEBA8
	ldr r3, _080AEBBC
	ldr r3, [r3]
	ldr r3, [r3, 0x2C]
	bl _080AEB6C
_080AEBA8:
	strb r6, [r4]
_080AEBAA:
	str r6, [r4, 0x2C]
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _080AEB90
_080AEBB2:
	str r4, [r5, 0x20]
_080AEBB4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AEBBC: .4byte SOUND_INFO_PTR
	thumb_func_end sub_80AEB7C

	thumb_func_start sub_80AEBC0
sub_80AEBC0:
	ldrb r1, [r4, 0x12]
	movs r0, 0x14
	ldrsb r2, [r4, r0]
	movs r3, 0x80
	adds r3, r2
	muls r3, r1
	ldrb r0, [r5, 0x10]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls _080AEBD8
	movs r0, 0xFF
_080AEBD8:
	strb r0, [r4, 0x2]
	movs r3, 0x7F
	subs r3, r2
	muls r3, r1
	ldrb r0, [r5, 0x11]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls _080AEBEC
	movs r0, 0xFF
_080AEBEC:
	strb r0, [r4, 0x3]
	bx lr
	thumb_func_end sub_80AEBC0

	thumb_func_start sub_80AEBF0
sub_80AEBF0:
	push {r4-r7,lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	sub sp, 0x18
	str r1, [sp]
	adds r5, r2, 0
	ldr r1, _080AEDE8
	ldr r1, [r1]
	str r1, [sp, 0x4]
	ldr r1, _080AEDEC
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r5, 0x4]
	ldr r3, [r5, 0x40]
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _080AEC36
	strb r0, [r5, 0x5]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _080AEC34
	strb r0, [r5, 0x6]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _080AEC34
	ldrb r1, [r5, 0x4]
	adds r1, r0
	strb r1, [r5, 0x4]
	adds r3, 0x1
_080AEC34:
	str r3, [r5, 0x40]
_080AEC36:
	movs r0, 0
	str r0, [sp, 0x14]
	adds r4, r5, 0
	adds r4, 0x24
	ldrb r2, [r4]
	movs r0, 0xC0
	tst r0, r2
	beq _080AEC88
	ldrb r3, [r5, 0x5]
	movs r0, 0x40
	tst r0, r2
	beq _080AEC56
	ldr r1, [r5, 0x2C]
	adds r1, r3
	ldrb r0, [r1]
	b _080AEC58
_080AEC56:
	adds r0, r3, 0
_080AEC58:
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, [r5, 0x28]
	adds r1, r0
	mov r9, r1
	mov r6, r9
	ldrb r1, [r6]
	movs r0, 0xC0
	tst r0, r1
	beq _080AEC70
	b _080AEDD6
_080AEC70:
	movs r0, 0x80
	tst r0, r2
	beq _080AEC8C
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	beq _080AEC84
	subs r1, 0xC0
	lsls r1, 1
	str r1, [sp, 0x14]
_080AEC84:
	ldrb r3, [r6, 0x1]
	b _080AEC8C
_080AEC88:
	mov r9, r4
	ldrb r3, [r5, 0x5]
_080AEC8C:
	str r3, [sp, 0x8]
	ldr r6, [sp]
	ldrb r1, [r6, 0x9]
	ldrb r0, [r5, 0x1D]
	adds r0, r1
	cmp r0, 0xFF
	bls _080AEC9C
	movs r0, 0xFF
_080AEC9C:
	str r0, [sp, 0x10]
	mov r6, r9
	ldrb r0, [r6]
	movs r6, 0x7
	ands r6, r0
	str r6, [sp, 0xC]
	beq _080AECDC
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
	cmp r4, 0
	bne _080AECB4
	b _080AEDD6
_080AECB4:
	subs r6, 0x1
	lsls r0, r6, 6
	adds r4, r0
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _080AED30
	movs r0, 0x40
	tst r0, r1
	bne _080AED30
	ldrb r1, [r4, 0x13]
	ldr r0, [sp, 0x10]
	cmp r1, r0
	bcc _080AED30
	beq _080AECD4
	b _080AEDD6
_080AECD4:
	ldr r0, [r4, 0x2C]
	cmp r0, r5
	bcs _080AED30
	b _080AEDD6
_080AECDC:
	ldr r6, [sp, 0x10]
	adds r7, r5, 0
	movs r2, 0
	mov r8, r2
	ldr r4, [sp, 0x4]
	ldrb r3, [r4, 0x6]
	adds r4, 0x50
_080AECEA:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq _080AED30
	movs r0, 0x40
	tst r0, r1
	beq _080AED04
	cmp r2, 0
	bne _080AED08
	adds r2, 0x1
	ldrb r6, [r4, 0x13]
	ldr r7, [r4, 0x2C]
	b _080AED22
_080AED04:
	cmp r2, 0
	bne _080AED24
_080AED08:
	ldrb r0, [r4, 0x13]
	cmp r0, r6
	bcs _080AED14
	adds r6, r0, 0
	ldr r7, [r4, 0x2C]
	b _080AED22
_080AED14:
	bhi _080AED24
	ldr r0, [r4, 0x2C]
	cmp r0, r7
	bls _080AED20
	adds r7, r0, 0
	b _080AED22
_080AED20:
	bcc _080AED24
_080AED22:
	mov r8, r4
_080AED24:
	adds r4, 0x40
	subs r3, 0x1
	bgt _080AECEA
	mov r4, r8
	cmp r4, 0
	beq _080AEDD6
_080AED30:
	adds r0, r4, 0
	bl sub_80AF2FC
	movs r1, 0
	str r1, [r4, 0x30]
	ldr r3, [r5, 0x20]
	str r3, [r4, 0x34]
	cmp r3, 0
	beq _080AED44
	str r4, [r3, 0x30]
_080AED44:
	str r4, [r5, 0x20]
	str r5, [r4, 0x2C]
	ldrb r0, [r5, 0x1B]
	strb r0, [r5, 0x1C]
	cmp r0, r1
	beq _080AED56
	adds r1, r5, 0
	bl sub_80AEE30
_080AED56:
	ldr r0, [sp]
	adds r1, r5, 0
	bl sub_80AF8C8
	ldr r0, [r5, 0x4]
	str r0, [r4, 0x10]
	ldr r0, [sp, 0x10]
	strb r0, [r4, 0x13]
	ldr r0, [sp, 0x8]
	strb r0, [r4, 0x8]
	ldr r0, [sp, 0x14]
	strb r0, [r4, 0x14]
	mov r6, r9
	ldrb r0, [r6]
	strb r0, [r4, 0x1]
	ldr r7, [r6, 0x4]
	str r7, [r4, 0x24]
	ldr r0, [r6, 0x8]
	str r0, [r4, 0x4]
	ldrh r0, [r5, 0x1E]
	strh r0, [r4, 0xC]
	bl sub_80AEBC0
	ldrb r1, [r4, 0x8]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl _080AED90
	movs r3, 0
_080AED90:
	ldr r6, [sp, 0xC]
	cmp r6, 0
	beq _080AEDBE
	mov r6, r9
	ldrb r0, [r6, 0x2]
	strb r0, [r4, 0x1E]
	ldrb r1, [r6, 0x3]
	movs r0, 0x80
	tst r0, r1
	bne _080AEDAA
	movs r0, 0x70
	tst r0, r1
	bne _080AEDAC
_080AEDAA:
	movs r1, 0x8
_080AEDAC:
	strb r1, [r4, 0x1F]
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	ldr r0, [sp, 0xC]
	ldr r3, [sp, 0x4]
	ldr r3, [r3, 0x30]
	bl _080AEB6C
	b _080AEDC8
_080AEDBE:
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	adds r0, r7, 0
	bl sub_80AEE80
_080AEDC8:
	str r0, [r4, 0x20]
	movs r0, 0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, 0xF0
	ands r0, r1
	strb r0, [r5]
_080AEDD6:
	add sp, 0x18
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r0}
	bx r0
	.align 2, 0
_080AEDE8: .4byte SOUND_INFO_PTR
_080AEDEC: .4byte gUnknown_826FC00
	thumb_func_end sub_80AEBF0

	thumb_func_start sub_80AEDF0
sub_80AEDF0:
	push {r4,r5}
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	cmp r3, 0x80
	bcs _080AEE02
	strb r3, [r1, 0x5]
	adds r2, 0x1
	str r2, [r1, 0x40]
	b _080AEE04
_080AEE02:
	ldrb r3, [r1, 0x5]
_080AEE04:
	ldr r1, [r1, 0x20]
	cmp r1, 0
	beq _080AEE2C
	movs r4, 0x83
	movs r5, 0x40
_080AEE0E:
	ldrb r2, [r1]
	tst r2, r4
	beq _080AEE26
	tst r2, r5
	bne _080AEE26
	ldrb r0, [r1, 0x11]
	cmp r0, r3
	bne _080AEE26
	movs r0, 0x40
	orrs r2, r0
	strb r2, [r1]
	b _080AEE2C
_080AEE26:
	ldr r1, [r1, 0x34]
	cmp r1, 0
	bne _080AEE0E
_080AEE2C:
	pop {r4,r5}
	bx lr
	thumb_func_end sub_80AEDF0

	thumb_func_start sub_80AEE30
sub_80AEE30:
	movs r2, 0
	strb r2, [r1, 0x16]
	strb r2, [r1, 0x1A]
	ldrb r2, [r1, 0x18]
	cmp r2, 0
	bne _080AEE40
	movs r2, 0xC
	b _080AEE42
_080AEE40:
	movs r2, 0x3
_080AEE42:
	ldrb r3, [r1]
	orrs r3, r2
	strb r3, [r1]
	bx lr
	thumb_func_end sub_80AEE30

	thumb_func_start sub_80AEE4C
sub_80AEE4C:
	ldr r2, [r1, 0x40]
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	bx lr
	thumb_func_end sub_80AEE4C

	thumb_func_start sub_80AEE58
sub_80AEE58:
	mov r12, lr
	bl sub_80AEE4C
	strb r3, [r1, 0x19]
	cmp r3, 0
	bne _080AEE68
	bl sub_80AEE30
_080AEE68:
	bx r12
	thumb_func_end sub_80AEE58

	thumb_func_start sub_80AEE6C
sub_80AEE6C:
	mov r12, lr
	bl sub_80AEE4C
	strb r3, [r1, 0x17]
	cmp r3, 0
	bne _080AEE7C
	bl sub_80AEE30
_080AEE7C:
	bx r12
	thumb_func_end sub_80AEE6C

	thumb_func_start sub_80AEE80
sub_80AEE80:
	push {r4-r7,lr}
	mov r12, r0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r7, r2, 24
	cmp r6, 0xB2
	bls _080AEE94
	movs r6, 0xB2
	movs r7, 0xFF
	lsls r7, 24
_080AEE94:
	ldr r3, _080AEEDC
	adds r0, r6, r3
	ldrb r5, [r0]
	ldr r4, _080AEEE0
	movs r2, 0xF
	adds r0, r5, 0
	ands r0, r2
	lsls r0, 2
	adds r0, r4
	lsrs r1, r5, 4
	ldr r5, [r0]
	lsrs r5, r1
	adds r0, r6, 0x1
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r1, 0
	ands r0, r2
	lsls r0, 2
	adds r0, r4
	lsrs r1, 4
	ldr r0, [r0]
	lsrs r0, r1
	mov r1, r12
	ldr r4, [r1, 0x4]
	subs r0, r5
	adds r1, r7, 0
	bl umul3232H32
	adds r1, r0, 0
	adds r1, r5, r1
	adds r0, r4, 0
	bl umul3232H32
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AEEDC: .4byte gUnknown_826FA1C
_080AEEE0: .4byte gUnknown_826FAD0
	thumb_func_end sub_80AEE80

	thumb_func_start nullsub_212
nullsub_212:
	bx lr
	thumb_func_end nullsub_212

	thumb_func_start sub_80AEEE8
sub_80AEEE8:
	adds r2, r0, 0
	ldr r3, [r2, 0x34]
	ldr r0, _080AEEFC
	cmp r3, r0
	bne _080AEEFA
	ldr r0, [r2, 0x4]
	ldr r1, _080AEF00
	ands r0, r1
	str r0, [r2, 0x4]
_080AEEFA:
	bx lr
	.align 2, 0
_080AEEFC: .4byte 0x68736d53
_080AEF00: .4byte 0x7fffffff
	thumb_func_end sub_80AEEE8

	thumb_func_start sub_80AEF04
sub_80AEF04:
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _080AEF20
	cmp r3, r0
	bne _080AEF1C
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r2, 0x28]
_080AEF1C:
	bx lr
	.align 2, 0
_080AEF20: .4byte 0x68736d53
	thumb_func_end sub_80AEF04

	thumb_func_start sub_80AEF24
sub_80AEF24:
	push {r4-r6,lr}
	ldr r0, _080AEF78
	movs r1, 0x2
	negs r1, r1
	ands r0, r1
	ldr r1, _080AEF7C
	ldr r2, _080AEF80
	bl CpuSet
	ldr r0, _080AEF84
	bl sub_80AF324
	ldr r0, _080AEF88
	bl sub_80AF1E0
	ldr r0, _080AEF8C
	bl sub_80AF4C0
	ldr r0, _080AEF90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080AEF72
	ldr r5, _080AEF94
	adds r6, r0, 0
_080AEF56:
	ldr r4, [r5]
	ldr r1, [r5, 0x4]
	ldrb r2, [r5, 0x8]
	adds r0, r4, 0
	bl sub_80AF664
	ldrh r0, [r5, 0xA]
	strb r0, [r4, 0xB]
	ldr r0, _080AEF98
	str r0, [r4, 0x18]
	adds r5, 0xC
	subs r6, 0x1
	cmp r6, 0
	bne _080AEF56
_080AEF72:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AEF78: .4byte SoundMainRAM
_080AEF7C: .4byte SoundMainRAM_Buffer
_080AEF80: .4byte 0x04000100
_080AEF84: .4byte gUnknown_2039ED0
_080AEF88: .4byte gUnknown_203AF10
_080AEF8C: .4byte 0x0096e500
_080AEF90: .4byte 0x00000008
_080AEF94: .4byte 0x09e8665c
_080AEF98: .4byte gUnknown_2000A30
	thumb_func_end sub_80AEF24

	thumb_func_start m4aSoundMain
m4aSoundMain:
	push {lr}
	bl SoundMain
	pop {r0}
	bx r0
	thumb_func_end m4aSoundMain

	thumb_func_start sub_80AEFA8
sub_80AEFA8:
	push {lr}
	lsls r0, 16
	ldr r2, _080AEFCC
	ldr r1, _080AEFD0
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, [r0]
	adds r0, r2, 0
	bl sub_80AF6DC
	pop {r0}
	bx r0
	.align 2, 0
_080AEFCC: .4byte 0x09e8665c
_080AEFD0: .4byte 0x09e866bc
	thumb_func_end sub_80AEFA8

	thumb_func_start sub_80AEFD4
sub_80AEFD4:
	push {lr}
	lsls r0, 16
	ldr r2, _080AF000
	ldr r1, _080AF004
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r2, [r0]
	cmp r3, r2
	beq _080AF008
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_80AF6DC
	b _080AF01C
	.align 2, 0
_080AF000: .4byte 0x09e8665c
_080AF004: .4byte 0x09e866bc
_080AF008:
	ldr r2, [r1, 0x4]
	ldrh r0, [r1, 0x4]
	cmp r0, 0
	beq _080AF014
	cmp r2, 0
	bge _080AF01C
_080AF014:
	adds r0, r1, 0
	adds r1, r3, 0
	bl sub_80AF6DC
_080AF01C:
	pop {r0}
	bx r0
	thumb_func_end sub_80AEFD4

	thumb_func_start sub_80AF020
sub_80AF020:
	push {lr}
	lsls r0, 16
	ldr r2, _080AF04C
	ldr r1, _080AF050
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	ldr r3, [r1]
	ldr r2, [r0]
	cmp r3, r2
	beq _080AF054
	adds r0, r1, 0
	adds r1, r2, 0
	bl sub_80AF6DC
	b _080AF070
	.align 2, 0
_080AF04C: .4byte 0x09e8665c
_080AF050: .4byte 0x09e866bc
_080AF054:
	ldr r2, [r1, 0x4]
	ldrh r0, [r1, 0x4]
	cmp r0, 0
	bne _080AF066
	adds r0, r1, 0
	adds r1, r3, 0
	bl sub_80AF6DC
	b _080AF070
_080AF066:
	cmp r2, 0
	bge _080AF070
	adds r0, r1, 0
	bl sub_80AEEE8
_080AF070:
	pop {r0}
	bx r0
	thumb_func_end sub_80AF020

	thumb_func_start sub_80AF074
sub_80AF074:
	push {lr}
	lsls r0, 16
	ldr r2, _080AF0A0
	ldr r1, _080AF0A4
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	bne _080AF09A
	adds r0, r2, 0
	bl sub_80AF7C0
_080AF09A:
	pop {r0}
	bx r0
	.align 2, 0
_080AF0A0: .4byte 0x09e8665c
_080AF0A4: .4byte 0x09e866bc
	thumb_func_end sub_80AF074

	thumb_func_start sub_80AF0A8
sub_80AF0A8:
	push {lr}
	lsls r0, 16
	ldr r2, _080AF0D4
	ldr r1, _080AF0D8
	lsrs r0, 13
	adds r0, r1
	ldrh r3, [r0, 0x4]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r2
	ldr r2, [r1]
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	bne _080AF0CE
	adds r0, r2, 0
	bl sub_80AEEE8
_080AF0CE:
	pop {r0}
	bx r0
	.align 2, 0
_080AF0D4: .4byte 0x09e8665c
_080AF0D8: .4byte 0x09e866bc
	thumb_func_end sub_80AF0A8

	thumb_func_start sub_80AF0DC
sub_80AF0DC:
	push {r4,r5,lr}
	ldr r0, _080AF100
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080AF0FA
	ldr r5, _080AF104
	adds r4, r0, 0
_080AF0EC:
	ldr r0, [r5]
	bl sub_80AF7C0
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bne _080AF0EC
_080AF0FA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF100: .4byte 0x00000008
_080AF104: .4byte 0x09e8665c
	thumb_func_end sub_80AF0DC

	thumb_func_start sub_80AF108
sub_80AF108:
	push {lr}
	bl sub_80AEEE8
	pop {r0}
	bx r0
	thumb_func_end sub_80AF108

	thumb_func_start sub_80AF114
sub_80AF114:
	push {r4,r5,lr}
	ldr r0, _080AF138
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080AF132
	ldr r5, _080AF13C
	adds r4, r0, 0
_080AF124:
	ldr r0, [r5]
	bl sub_80AEEE8
	adds r5, 0xC
	subs r4, 0x1
	cmp r4, 0
	bne _080AF124
_080AF132:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF138: .4byte 0x00000008
_080AF13C: .4byte 0x09e8665c
	thumb_func_end sub_80AF114

	thumb_func_start sub_80AF140
sub_80AF140:
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	bl sub_80AEF04
	pop {r0}
	bx r0
	thumb_func_end sub_80AF140

	thumb_func_start sub_80AF150
sub_80AF150:
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _080AF168
	cmp r3, r0
	bne _080AF166
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	ldr r0, _080AF16C
	strh r0, [r2, 0x28]
_080AF166:
	bx lr
	.align 2, 0
_080AF168: .4byte 0x68736d53
_080AF16C: .4byte 0x00000101
	thumb_func_end sub_80AF150

	thumb_func_start sub_80AF170
sub_80AF170:
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _080AF190
	cmp r3, r0
	bne _080AF18E
	strh r1, [r2, 0x26]
	strh r1, [r2, 0x24]
	movs r0, 0x2
	strh r0, [r2, 0x28]
	ldr r0, [r2, 0x4]
	ldr r1, _080AF194
	ands r0, r1
	str r0, [r2, 0x4]
_080AF18E:
	bx lr
	.align 2, 0
_080AF190: .4byte 0x68736d53
_080AF194: .4byte 0x7fffffff
	thumb_func_end sub_80AF170

	thumb_func_start sub_80AF198
sub_80AF198:
	push {r4-r7,lr}
	ldrb r5, [r0, 0x8]
	ldr r4, [r0, 0x2C]
	cmp r5, 0
	ble _080AF1DA
	movs r7, 0x80
_080AF1A4:
	ldrb r1, [r4]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080AF1D2
	movs r6, 0x40
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080AF1D2
	adds r0, r4, 0
	bl sub_80AF310
	strb r7, [r4]
	movs r0, 0x2
	strb r0, [r4, 0xF]
	strb r6, [r4, 0x13]
	movs r0, 0x16
	strb r0, [r4, 0x19]
	adds r1, r4, 0
	adds r1, 0x24
	movs r0, 0x1
	strb r0, [r1]
_080AF1D2:
	subs r5, 0x1
	adds r4, 0x50
	cmp r5, 0
	bgt _080AF1A4
_080AF1DA:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF198

	thumb_func_start sub_80AF1E0
sub_80AF1E0:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r1, _080AF2A8
	movs r0, 0x8F
	strh r0, [r1]
	ldr r3, _080AF2AC
	movs r2, 0
	strh r2, [r3]
	ldr r0, _080AF2B0
	movs r1, 0x8
	strb r1, [r0]
	adds r0, 0x6
	strb r1, [r0]
	adds r0, 0x10
	strb r1, [r0]
	subs r0, 0x14
	movs r1, 0x80
	strb r1, [r0]
	adds r0, 0x8
	strb r1, [r0]
	adds r0, 0x10
	strb r1, [r0]
	subs r0, 0xD
	strb r2, [r0]
	movs r0, 0x77
	strb r0, [r3]
	ldr r0, _080AF2B4
	ldr r4, [r0]
	ldr r6, [r4]
	ldr r0, _080AF2B8
	cmp r6, r0
	bne _080AF2A0
	adds r0, r6, 0x1
	str r0, [r4]
	ldr r1, _080AF2BC
	ldr r0, _080AF2C0
	str r0, [r1, 0x20]
	ldr r0, _080AF2C4
	str r0, [r1, 0x44]
	ldr r0, _080AF2C8
	str r0, [r1, 0x4C]
	ldr r0, _080AF2CC
	str r0, [r1, 0x70]
	ldr r0, _080AF2D0
	str r0, [r1, 0x74]
	ldr r0, _080AF2D4
	str r0, [r1, 0x78]
	ldr r0, _080AF2D8
	str r0, [r1, 0x7C]
	adds r2, r1, 0
	adds r2, 0x80
	ldr r0, _080AF2DC
	str r0, [r2]
	adds r1, 0x84
	ldr r0, _080AF2E0
	str r0, [r1]
	str r5, [r4, 0x1C]
	ldr r0, _080AF2E4
	str r0, [r4, 0x28]
	ldr r0, _080AF2E8
	str r0, [r4, 0x2C]
	ldr r0, _080AF2EC
	str r0, [r4, 0x30]
	ldr r0, _080AF2F0
	movs r1, 0
	strb r0, [r4, 0xC]
	str r1, [sp]
	ldr r2, _080AF2F4
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
	movs r0, 0x1
	strb r0, [r5, 0x1]
	movs r0, 0x11
	strb r0, [r5, 0x1C]
	adds r1, r5, 0
	adds r1, 0x41
	movs r0, 0x2
	strb r0, [r1]
	adds r1, 0x1B
	movs r0, 0x22
	strb r0, [r1]
	adds r1, 0x25
	movs r0, 0x3
	strb r0, [r1]
	adds r1, 0x1B
	movs r0, 0x44
	strb r0, [r1]
	adds r1, 0x24
	movs r0, 0x4
	strb r0, [r1, 0x1]
	movs r0, 0x88
	strb r0, [r1, 0x1C]
	str r6, [r4]
_080AF2A0:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF2A8: .4byte 0x04000084
_080AF2AC: .4byte 0x04000080
_080AF2B0: .4byte 0x04000063
_080AF2B4: .4byte SOUND_INFO_PTR
_080AF2B8: .4byte 0x68736d53
_080AF2BC: .4byte gUnknown_203AE80
_080AF2C0: .4byte sub_80B019C
_080AF2C4: .4byte sub_80AEE58
_080AF2C8: .4byte sub_80AEE6C
_080AF2CC: .4byte sub_80B02F4
_080AF2D0: .4byte sub_80AEDF0
_080AF2D4: .4byte sub_80AF41C
_080AF2D8: .4byte sub_80AEB7C
_080AF2DC: .4byte sub_80AF800
_080AF2E0: .4byte sub_80AF8C8
_080AF2E4: .4byte sub_80AFADC
_080AF2E8: .4byte sub_80AFA24
_080AF2EC: .4byte sub_80AF97C
_080AF2F0: .4byte 0x00000000
_080AF2F4: .4byte 0x05000040
	thumb_func_end sub_80AF1E0

	thumb_func_start sub_80AF2F8
sub_80AF2F8:
	swi 0x2A
	bx lr
	thumb_func_end sub_80AF2F8

	thumb_func_start sub_80AF2FC
sub_80AF2FC:
	push {lr}
	ldr r1, _080AF30C
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF30C: .4byte gUnknown_203AF08
	thumb_func_end sub_80AF2FC

	thumb_func_start sub_80AF310
sub_80AF310:
	push {lr}
	ldr r1, _080AF320
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF320: .4byte gUnknown_203AF0C
	thumb_func_end sub_80AF310

	thumb_func_start sub_80AF324
sub_80AF324:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r3, 0
	str r3, [r5]
	ldr r1, _080AF3DC
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 18
	ands r0, r2
	cmp r0, 0
	beq _080AF340
	ldr r0, _080AF3E0
	str r0, [r1]
_080AF340:
	ldr r1, _080AF3E4
	ldr r0, [r1]
	ands r0, r2
	cmp r0, 0
	beq _080AF34E
	ldr r0, _080AF3E0
	str r0, [r1]
_080AF34E:
	ldr r0, _080AF3E8
	movs r2, 0x80
	lsls r2, 3
	adds r1, r2, 0
	strh r1, [r0]
	adds r0, 0xC
	strh r1, [r0]
	ldr r1, _080AF3EC
	movs r0, 0x8F
	strh r0, [r1]
	subs r1, 0x2
	ldr r2, _080AF3F0
	adds r0, r2, 0
	strh r0, [r1]
	ldr r2, _080AF3F4
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080AF3F8
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r5, r2
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080AF3FC
	str r0, [r1]
	adds r1, 0x8
	movs r2, 0x98
	lsls r2, 4
	adds r0, r5, r2
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080AF400
	str r0, [r1]
	ldr r0, _080AF404
	str r5, [r0]
	str r3, [sp]
	ldr r2, _080AF408
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
	movs r0, 0x8
	strb r0, [r5, 0x6]
	movs r0, 0xF
	strb r0, [r5, 0x7]
	ldr r0, _080AF40C
	str r0, [r5, 0x38]
	ldr r0, _080AF410
	str r0, [r5, 0x28]
	str r0, [r5, 0x2C]
	str r0, [r5, 0x30]
	str r0, [r5, 0x3C]
	ldr r4, _080AF414
	adds r0, r4, 0
	bl sub_80AE704
	str r4, [r5, 0x34]
	movs r0, 0x80
	lsls r0, 11
	bl sub_80AF41C
	ldr r0, _080AF418
	str r0, [r5]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF3DC: .4byte 0x040000c4
_080AF3E0: .4byte 0x84400004
_080AF3E4: .4byte 0x040000d0
_080AF3E8: .4byte 0x040000c6
_080AF3EC: .4byte 0x04000084
_080AF3F0: .4byte 0x0000a90e
_080AF3F4: .4byte 0x04000089
_080AF3F8: .4byte 0x040000bc
_080AF3FC: .4byte 0x040000a0
_080AF400: .4byte 0x040000a4
_080AF404: .4byte SOUND_INFO_PTR
_080AF408: .4byte 0x050003ec
_080AF40C: .4byte sub_80AEBF0
_080AF410: .4byte nullsub_139
_080AF414: .4byte gUnknown_203AE80
_080AF418: .4byte 0x68736d53
	thumb_func_end sub_80AF324

	thumb_func_start sub_80AF41C
sub_80AF41C:
	push {r4-r6,lr}
	adds r2, r0, 0
	ldr r0, _080AF49C
	ldr r4, [r0]
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r2
	lsrs r2, r0, 16
	movs r6, 0
	strb r2, [r4, 0x8]
	ldr r1, _080AF4A0
	subs r0, r2, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r5, [r0]
	str r5, [r4, 0x10]
	movs r0, 0xC6
	lsls r0, 3
	adds r1, r5, 0
	bl __divsi3
	strb r0, [r4, 0xB]
	ldr r0, _080AF4A4
	muls r0, r5
	ldr r1, _080AF4A8
	adds r0, r1
	ldr r1, _080AF4AC
	bl __divsi3
	adds r1, r0, 0
	str r1, [r4, 0x14]
	movs r0, 0x80
	lsls r0, 17
	bl __divsi3
	adds r0, 0x1
	asrs r0, 1
	str r0, [r4, 0x18]
	ldr r0, _080AF4B0
	strh r6, [r0]
	ldr r4, _080AF4B4
	ldr r0, _080AF4B8
	adds r1, r5, 0
	bl __divsi3
	negs r0, r0
	strh r0, [r4]
	bl sub_80AF628
	ldr r1, _080AF4BC
_080AF480:
	ldrb r0, [r1]
	cmp r0, 0x9F
	beq _080AF480
	ldr r1, _080AF4BC
_080AF488:
	ldrb r0, [r1]
	cmp r0, 0x9F
	bne _080AF488
	ldr r1, _080AF4B0
	movs r0, 0x80
	strh r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF49C: .4byte SOUND_INFO_PTR
_080AF4A0: .4byte gUnknown_826FB00
_080AF4A4: .4byte 0x00091d1b
_080AF4A8: .4byte 0x00001388
_080AF4AC: .4byte 0x00002710
_080AF4B0: .4byte 0x04000102
_080AF4B4: .4byte 0x04000100
_080AF4B8: .4byte 0x00044940
_080AF4BC: .4byte 0x04000006
	thumb_func_end sub_80AF41C

	thumb_func_start sub_80AF4C0
sub_80AF4C0:
	push {r4,r5,lr}
	adds r3, r0, 0
	ldr r0, _080AF54C
	ldr r5, [r0]
	ldr r1, [r5]
	ldr r0, _080AF550
	cmp r1, r0
	bne _080AF546
	adds r0, r1, 0x1
	str r0, [r5]
	movs r4, 0xFF
	ands r4, r3
	cmp r4, 0
	beq _080AF4E2
	movs r0, 0x7F
	ands r4, r0
	strb r4, [r5, 0x5]
_080AF4E2:
	movs r4, 0xF0
	lsls r4, 4
	ands r4, r3
	cmp r4, 0
	beq _080AF502
	lsrs r0, r4, 8
	strb r0, [r5, 0x6]
	movs r4, 0xC
	adds r0, r5, 0
	adds r0, 0x50
	movs r1, 0
_080AF4F8:
	strb r1, [r0]
	subs r4, 0x1
	adds r0, 0x40
	cmp r4, 0
	bne _080AF4F8
_080AF502:
	movs r4, 0xF0
	lsls r4, 8
	ands r4, r3
	cmp r4, 0
	beq _080AF510
	lsrs r0, r4, 12
	strb r0, [r5, 0x7]
_080AF510:
	movs r4, 0xB0
	lsls r4, 16
	ands r4, r3
	cmp r4, 0
	beq _080AF52E
	movs r0, 0xC0
	lsls r0, 14
	ands r0, r4
	lsrs r4, r0, 14
	ldr r2, _080AF554
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	orrs r0, r4
	strb r0, [r2]
_080AF52E:
	movs r4, 0xF0
	lsls r4, 12
	ands r4, r3
	cmp r4, 0
	beq _080AF542
	bl sub_80AF5AC
	adds r0, r4, 0
	bl sub_80AF41C
_080AF542:
	ldr r0, _080AF550
	str r0, [r5]
_080AF546:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF54C: .4byte SOUND_INFO_PTR
_080AF550: .4byte 0x68736d53
_080AF554: .4byte 0x04000089
	thumb_func_end sub_80AF4C0

	thumb_func_start sub_80AF558
sub_80AF558:
	push {r4-r7,lr}
	ldr r0, _080AF5A4
	ldr r6, [r0]
	ldr r1, [r6]
	ldr r0, _080AF5A8
	cmp r1, r0
	bne _080AF59E
	adds r0, r1, 0x1
	str r0, [r6]
	movs r5, 0xC
	adds r4, r6, 0
	adds r4, 0x50
	movs r0, 0
_080AF572:
	strb r0, [r4]
	subs r5, 0x1
	adds r4, 0x40
	cmp r5, 0
	bgt _080AF572
	ldr r4, [r6, 0x1C]
	cmp r4, 0
	beq _080AF59A
	movs r5, 0x1
	movs r7, 0
_080AF586:
	lsls r0, r5, 24
	lsrs r0, 24
	ldr r1, [r6, 0x2C]
	bl _call_via_r1
	strb r7, [r4]
	adds r5, 0x1
	adds r4, 0x40
	cmp r5, 0x4
	ble _080AF586
_080AF59A:
	ldr r0, _080AF5A8
	str r0, [r6]
_080AF59E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF5A4: .4byte SOUND_INFO_PTR
_080AF5A8: .4byte 0x68736d53
	thumb_func_end sub_80AF558

	thumb_func_start sub_80AF5AC
sub_80AF5AC:
	push {lr}
	sub sp, 0x4
	ldr r0, _080AF60C
	ldr r2, [r0]
	ldr r1, [r2]
	ldr r3, _080AF610
	adds r0, r1, r3
	cmp r0, 0x1
	bhi _080AF604
	adds r0, r1, 0
	adds r0, 0xA
	str r0, [r2]
	ldr r1, _080AF614
	ldr r0, [r1]
	movs r3, 0x80
	lsls r3, 18
	ands r0, r3
	cmp r0, 0
	beq _080AF5D6
	ldr r0, _080AF618
	str r0, [r1]
_080AF5D6:
	ldr r1, _080AF61C
	ldr r0, [r1]
	ands r0, r3
	cmp r0, 0
	beq _080AF5E4
	ldr r0, _080AF618
	str r0, [r1]
_080AF5E4:
	ldr r0, _080AF620
	movs r3, 0x80
	lsls r3, 3
	adds r1, r3, 0
	strh r1, [r0]
	adds r0, 0xC
	strh r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xD4
	lsls r0, 2
	adds r1, r2, r0
	ldr r2, _080AF624
	mov r0, sp
	bl CpuSet
_080AF604:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080AF60C: .4byte SOUND_INFO_PTR
_080AF610: .4byte 0x978c92ad
_080AF614: .4byte 0x040000c4
_080AF618: .4byte 0x84400004
_080AF61C: .4byte 0x040000d0
_080AF620: .4byte 0x040000c6
_080AF624: .4byte 0x05000318
	thumb_func_end sub_80AF5AC

	thumb_func_start sub_80AF628
sub_80AF628:
	push {r4,lr}
	ldr r0, _080AF658
	ldr r2, [r0]
	ldr r3, [r2]
	ldr r0, _080AF65C
	cmp r3, r0
	beq _080AF650
	ldr r0, _080AF660
	movs r4, 0xB6
	lsls r4, 8
	adds r1, r4, 0
	strh r1, [r0]
	adds r0, 0xC
	strh r1, [r0]
	ldrb r0, [r2, 0x4]
	movs r0, 0
	strb r0, [r2, 0x4]
	adds r0, r3, 0
	subs r0, 0xA
	str r0, [r2]
_080AF650:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF658: .4byte SOUND_INFO_PTR
_080AF65C: .4byte 0x68736d53
_080AF660: .4byte 0x040000c6
	thumb_func_end sub_80AF628

	thumb_func_start sub_80AF664
sub_80AF664:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r4, r2, 24
	cmp r4, 0
	beq _080AF6C8
	cmp r4, 0x10
	bls _080AF678
	movs r4, 0x10
_080AF678:
	ldr r0, _080AF6D0
	ldr r5, [r0]
	ldr r1, [r5]
	ldr r0, _080AF6D4
	cmp r1, r0
	bne _080AF6C8
	adds r0, r1, 0x1
	str r0, [r5]
	adds r0, r7, 0
	bl sub_80AF310
	str r6, [r7, 0x2C]
	strb r4, [r7, 0x8]
	movs r0, 0x80
	lsls r0, 24
	str r0, [r7, 0x4]
	cmp r4, 0
	beq _080AF6AC
	movs r1, 0
_080AF69E:
	strb r1, [r6]
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, 0x50
	cmp r4, 0
	bne _080AF69E
_080AF6AC:
	ldr r0, [r5, 0x20]
	cmp r0, 0
	beq _080AF6BC
	str r0, [r7, 0x38]
	ldr r0, [r5, 0x24]
	str r0, [r7, 0x3C]
	movs r0, 0
	str r0, [r5, 0x20]
_080AF6BC:
	str r7, [r5, 0x24]
	ldr r0, _080AF6D8
	str r0, [r5, 0x20]
	ldr r0, _080AF6D4
	str r0, [r5]
	str r0, [r7, 0x34]
_080AF6C8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF6D0: .4byte SOUND_INFO_PTR
_080AF6D4: .4byte 0x68736d53
_080AF6D8: .4byte sub_80AE914
	thumb_func_end sub_80AF664

	thumb_func_start sub_80AF6DC
sub_80AF6DC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r7, r1, 0
	ldr r1, [r5, 0x34]
	ldr r0, _080AF7BC
	cmp r1, r0
	bne _080AF7B2
	ldrb r0, [r5, 0xB]
	ldrb r2, [r7, 0x2]
	cmp r0, 0
	beq _080AF71E
	ldr r0, [r5]
	cmp r0, 0
	beq _080AF708
	ldr r1, [r5, 0x2C]
	movs r0, 0x40
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _080AF714
_080AF708:
	ldr r1, [r5, 0x4]
	ldrh r0, [r5, 0x4]
	cmp r0, 0
	beq _080AF71E
	cmp r1, 0
	blt _080AF71E
_080AF714:
	ldrb r0, [r7, 0x2]
	adds r2, r0, 0
	ldrb r0, [r5, 0x9]
	cmp r0, r2
	bhi _080AF7B2
_080AF71E:
	ldr r0, [r5, 0x34]
	adds r0, 0x1
	str r0, [r5, 0x34]
	movs r1, 0
	str r1, [r5, 0x4]
	str r7, [r5]
	ldr r0, [r7, 0x4]
	str r0, [r5, 0x30]
	strb r2, [r5, 0x9]
	str r1, [r5, 0xC]
	movs r0, 0x96
	strh r0, [r5, 0x1C]
	strh r0, [r5, 0x20]
	adds r0, 0x6A
	strh r0, [r5, 0x1E]
	strh r1, [r5, 0x22]
	strh r1, [r5, 0x24]
	movs r6, 0
	ldr r4, [r5, 0x2C]
	ldrb r1, [r7]
	cmp r6, r1
	bge _080AF77E
	ldrb r0, [r5, 0x8]
	cmp r6, r0
	bge _080AF79E
	mov r8, r6
_080AF752:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AEB7C
	movs r0, 0xC0
	strb r0, [r4]
	mov r1, r8
	str r1, [r4, 0x20]
	lsls r1, r6, 2
	adds r0, r7, 0
	adds r0, 0x8
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4, 0x40]
	adds r6, 0x1
	adds r4, 0x50
	ldrb r0, [r7]
	cmp r6, r0
	bge _080AF77E
	ldrb r1, [r5, 0x8]
	cmp r6, r1
	blt _080AF752
_080AF77E:
	ldrb r0, [r5, 0x8]
	cmp r6, r0
	bge _080AF79E
	movs r1, 0
	mov r8, r1
_080AF788:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80AEB7C
	mov r0, r8
	strb r0, [r4]
	adds r6, 0x1
	adds r4, 0x50
	ldrb r1, [r5, 0x8]
	cmp r6, r1
	blt _080AF788
_080AF79E:
	movs r0, 0x80
	ldrb r1, [r7, 0x3]
	ands r0, r1
	cmp r0, 0
	beq _080AF7AE
	ldrb r0, [r7, 0x3]
	bl sub_80AF4C0
_080AF7AE:
	ldr r0, _080AF7BC
	str r0, [r5, 0x34]
_080AF7B2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF7BC: .4byte 0x68736d53
	thumb_func_end sub_80AF6DC

	thumb_func_start sub_80AF7C0
sub_80AF7C0:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r1, [r6, 0x34]
	ldr r0, _080AF7FC
	cmp r1, r0
	bne _080AF7F6
	adds r0, r1, 0x1
	str r0, [r6, 0x34]
	ldr r0, [r6, 0x4]
	movs r1, 0x80
	lsls r1, 24
	orrs r0, r1
	str r0, [r6, 0x4]
	ldrb r4, [r6, 0x8]
	ldr r5, [r6, 0x2C]
	cmp r4, 0
	ble _080AF7F2
_080AF7E2:
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80AEB7C
	subs r4, 0x1
	adds r5, 0x50
	cmp r4, 0
	bgt _080AF7E2
_080AF7F2:
	ldr r0, _080AF7FC
	str r0, [r6, 0x34]
_080AF7F6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF7FC: .4byte 0x68736d53
	thumb_func_end sub_80AF7C0

	thumb_func_start sub_80AF800
sub_80AF800:
	push {r4-r7,lr}
	adds r6, r0, 0
	ldrh r1, [r6, 0x24]
	cmp r1, 0
	beq _080AF8C2
	ldrh r0, [r6, 0x26]
	subs r0, 0x1
	strh r0, [r6, 0x26]
	ldr r3, _080AF840
	adds r2, r3, 0
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _080AF8C2
	strh r1, [r6, 0x26]
	ldrh r1, [r6, 0x28]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080AF844
	adds r0, r1, 0
	adds r0, 0x10
	strh r0, [r6, 0x28]
	ands r0, r2
	cmp r0, 0xFF
	bls _080AF896
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r6, 0x28]
	strh r3, [r6, 0x24]
	b _080AF896
	.align 2, 0
_080AF840: .4byte 0x0000ffff
_080AF844:
	adds r0, r1, 0
	subs r0, 0x10
	strh r0, [r6, 0x28]
	ands r0, r2
	lsls r0, 16
	cmp r0, 0
	bgt _080AF896
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	cmp r5, 0
	ble _080AF876
_080AF85A:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80AEB7C
	movs r0, 0x1
	ldrh r7, [r6, 0x28]
	ands r0, r7
	cmp r0, 0
	bne _080AF86E
	strb r0, [r4]
_080AF86E:
	subs r5, 0x1
	adds r4, 0x50
	cmp r5, 0
	bgt _080AF85A
_080AF876:
	movs r0, 0x1
	ldrh r1, [r6, 0x28]
	ands r0, r1
	cmp r0, 0
	beq _080AF88A
	ldr r0, [r6, 0x4]
	movs r1, 0x80
	lsls r1, 24
	orrs r0, r1
	b _080AF88E
_080AF88A:
	movs r0, 0x80
	lsls r0, 24
_080AF88E:
	str r0, [r6, 0x4]
	movs r0, 0
	strh r0, [r6, 0x24]
	b _080AF8C2
_080AF896:
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	cmp r5, 0
	ble _080AF8C2
	movs r3, 0x80
	movs r7, 0
	movs r2, 0x3
_080AF8A4:
	ldrb r1, [r4]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080AF8BA
	ldrh r7, [r6, 0x28]
	lsrs r0, r7, 2
	strb r0, [r4, 0x13]
	adds r0, r1, 0
	orrs r0, r2
	strb r0, [r4]
_080AF8BA:
	subs r5, 0x1
	adds r4, 0x50
	cmp r5, 0
	bgt _080AF8A4
_080AF8C2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF800

	thumb_func_start sub_80AF8C8
sub_80AF8C8:
	push {r4,lr}
	adds r2, r1, 0
	movs r0, 0x1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, 0
	beq _080AF92C
	ldrb r3, [r2, 0x13]
	ldrb r1, [r2, 0x12]
	adds r0, r3, 0
	muls r0, r1
	lsrs r3, r0, 5
	ldrb r4, [r2, 0x18]
	cmp r4, 0x1
	bne _080AF8F0
	movs r0, 0x16
	ldrsb r0, [r2, r0]
	adds r0, 0x80
	muls r0, r3
	lsrs r3, r0, 7
_080AF8F0:
	movs r0, 0x14
	ldrsb r0, [r2, r0]
	lsls r0, 1
	movs r1, 0x15
	ldrsb r1, [r2, r1]
	adds r1, r0, r1
	cmp r4, 0x2
	bne _080AF906
	movs r0, 0x16
	ldrsb r0, [r2, r0]
	adds r1, r0
_080AF906:
	movs r0, 0x80
	negs r0, r0
	cmp r1, r0
	bge _080AF912
	adds r1, r0, 0
	b _080AF918
_080AF912:
	cmp r1, 0x7F
	ble _080AF918
	movs r1, 0x7F
_080AF918:
	adds r0, r1, 0
	adds r0, 0x80
	muls r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x10]
	movs r0, 0x7F
	subs r0, r1
	muls r0, r3
	lsrs r0, 8
	strb r0, [r2, 0x11]
_080AF92C:
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	adds r3, r1, 0
	cmp r0, 0
	beq _080AF970
	movs r0, 0xE
	ldrsb r0, [r2, r0]
	ldrb r1, [r2, 0xF]
	muls r0, r1
	movs r1, 0xC
	ldrsb r1, [r2, r1]
	adds r1, r0
	lsls r1, 2
	movs r0, 0xA
	ldrsb r0, [r2, r0]
	lsls r0, 8
	adds r1, r0
	movs r0, 0xB
	ldrsb r0, [r2, r0]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0xD]
	adds r1, r0, r1
	ldrb r0, [r2, 0x18]
	cmp r0, 0
	bne _080AF96A
	movs r0, 0x16
	ldrsb r0, [r2, r0]
	lsls r0, 4
	adds r1, r0
_080AF96A:
	asrs r0, r1, 8
	strb r0, [r2, 0x8]
	strb r1, [r2, 0x9]
_080AF970:
	movs r0, 0xFA
	ands r0, r3
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AF8C8

	thumb_func_start sub_80AF97C
sub_80AF97C:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r12, r2
	cmp r0, 0x4
	bne _080AF9B4
	cmp r5, 0x14
	bhi _080AF998
	movs r5, 0
	b _080AF9A6
_080AF998:
	adds r0, r5, 0
	subs r0, 0x15
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3B
	bls _080AF9A6
	movs r5, 0x3B
_080AF9A6:
	ldr r0, _080AF9B0
	adds r0, r5, r0
	ldrb r0, [r0]
	b _080AFA16
	.align 2, 0
_080AF9B0: .4byte gUnknown_826FBB4
_080AF9B4:
	cmp r5, 0x23
	bhi _080AF9C0
	movs r0, 0
	mov r12, r0
	movs r5, 0
	b _080AF9D2
_080AF9C0:
	adds r0, r5, 0
	subs r0, 0x24
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x82
	bls _080AF9D2
	movs r5, 0x82
	movs r1, 0xFF
	mov r12, r1
_080AF9D2:
	ldr r3, _080AFA1C
	adds r0, r5, r3
	ldrb r6, [r0]
	ldr r4, _080AFA20
	movs r2, 0xF
	adds r0, r6, 0
	ands r0, r2
	lsls r0, 1
	adds r0, r4
	movs r7, 0
	ldrsh r1, [r0, r7]
	asrs r0, r6, 4
	adds r6, r1, 0
	asrs r6, r0
	adds r0, r5, 0x1
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r1, 0
	ands r0, r2
	lsls r0, 1
	adds r0, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 4
	asrs r0, r1
	subs r0, r6
	mov r7, r12
	muls r7, r0
	adds r0, r7, 0
	asrs r0, 8
	adds r0, r6, r0
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1
_080AFA16:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AFA1C: .4byte gUnknown_826FB18
_080AFA20: .4byte gUnknown_826FB9C
	thumb_func_end sub_80AF97C

	thumb_func_start sub_80AFA24
sub_80AFA24:
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x2
	beq _080AFA4C
	cmp r0, 0x2
	bgt _080AFA38
	cmp r0, 0x1
	beq _080AFA3E
	b _080AFA60
_080AFA38:
	cmp r1, 0x3
	beq _080AFA54
	b _080AFA60
_080AFA3E:
	ldr r1, _080AFA48
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x2
	b _080AFA68
	.align 2, 0
_080AFA48: .4byte 0x04000063
_080AFA4C:
	ldr r1, _080AFA50
	b _080AFA62
	.align 2, 0
_080AFA50: .4byte 0x04000069
_080AFA54:
	ldr r1, _080AFA5C
	movs r0, 0
	b _080AFA6A
	.align 2, 0
_080AFA5C: .4byte 0x04000070
_080AFA60:
	ldr r1, _080AFA70
_080AFA62:
	movs r0, 0x8
	strb r0, [r1]
	adds r1, 0x4
_080AFA68:
	movs r0, 0x80
_080AFA6A:
	strb r0, [r1]
	bx lr
	.align 2, 0
_080AFA70: .4byte 0x04000079
	thumb_func_end sub_80AFA24

	thumb_func_start sub_80AFA74
sub_80AFA74:
	push {r4,lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	lsls r2, r0, 24
	lsrs r4, r2, 24
	ldrb r3, [r1, 0x3]
	lsls r0, r3, 24
	lsrs r3, r0, 24
	cmp r4, r3
	bcc _080AFA94
	lsrs r0, r2, 25
	cmp r0, r3
	bcc _080AFAA0
	movs r0, 0xF
	strb r0, [r1, 0x1B]
	b _080AFAAE
_080AFA94:
	lsrs r0, 25
	cmp r0, r4
	bcc _080AFAA0
	movs r0, 0xF0
	strb r0, [r1, 0x1B]
	b _080AFAAE
_080AFAA0:
	movs r0, 0xFF
	strb r0, [r1, 0x1B]
	ldrb r2, [r1, 0x3]
	ldrb r3, [r1, 0x2]
	adds r0, r2, r3
	lsrs r0, 4
	b _080AFABE
_080AFAAE:
	ldrb r2, [r1, 0x3]
	ldrb r3, [r1, 0x2]
	adds r0, r2, r3
	lsrs r0, 4
	strb r0, [r1, 0xA]
	cmp r0, 0xF
	bls _080AFAC0
	movs r0, 0xF
_080AFABE:
	strb r0, [r1, 0xA]
_080AFAC0:
	ldrb r2, [r1, 0x6]
	ldrb r3, [r1, 0xA]
	adds r0, r2, 0
	muls r0, r3
	adds r0, 0xF
	asrs r0, 4
	strb r0, [r1, 0x19]
	ldrb r0, [r1, 0x1C]
	ldrb r2, [r1, 0x1B]
	ands r0, r2
	strb r0, [r1, 0x1B]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80AFA74

	thumb_func_start sub_80AFADC
sub_80AFADC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, _080AFAFC
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _080AFB00
	subs r0, 0x1
	ldr r1, [sp, 0x4]
	strb r0, [r1, 0xA]
	b _080AFB06
	.align 2, 0
_080AFAFC: .4byte SOUND_INFO_PTR
_080AFB00:
	movs r0, 0xE
	ldr r2, [sp, 0x4]
	strb r0, [r2, 0xA]
_080AFB06:
	movs r6, 0x1
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
_080AFB0C:
	ldrb r1, [r4]
	movs r0, 0xC7
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	bne _080AFB22
	b _080AFF0C
_080AFB22:
	cmp r6, 0x2
	beq _080AFB54
	cmp r6, 0x2
	bgt _080AFB30
	cmp r6, 0x1
	beq _080AFB36
	b _080AFB8C
_080AFB30:
	cmp r6, 0x3
	beq _080AFB6C
	b _080AFB8C
_080AFB36:
	ldr r0, _080AFB48
	str r0, [sp, 0x8]
	ldr r7, _080AFB4C
	ldr r2, _080AFB50
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _080AFB9C
	.align 2, 0
_080AFB48: .4byte 0x04000060
_080AFB4C: .4byte 0x04000062
_080AFB50: .4byte 0x04000063
_080AFB54:
	ldr r0, _080AFB60
	str r0, [sp, 0x8]
	ldr r7, _080AFB64
	ldr r2, _080AFB68
	b _080AFB94
	.align 2, 0
_080AFB60: .4byte 0x04000061
_080AFB64: .4byte 0x04000068
_080AFB68: .4byte 0x04000069
_080AFB6C:
	ldr r0, _080AFB80
	str r0, [sp, 0x8]
	ldr r7, _080AFB84
	ldr r2, _080AFB88
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _080AFB9C
	.align 2, 0
_080AFB80: .4byte 0x04000070
_080AFB84: .4byte 0x04000072
_080AFB88: .4byte 0x04000073
_080AFB8C:
	ldr r0, _080AFBEC
	str r0, [sp, 0x8]
	ldr r7, _080AFBF0
	ldr r2, _080AFBF4
_080AFB94:
	str r2, [sp, 0xC]
	adds r0, 0xB
	str r0, [sp, 0x10]
	adds r2, 0x4
_080AFB9C:
	str r2, [sp, 0x14]
	ldr r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	str r0, [sp]
	ldr r2, [sp, 0xC]
	ldrb r0, [r2]
	mov r8, r0
	adds r2, r1, 0
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _080AFC92
	movs r3, 0x40
	adds r0, r3, 0
	ands r0, r2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0x1
	mov r10, r0
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r5, 0
	bne _080AFCB6
	movs r0, 0x3
	strb r0, [r4]
	strb r0, [r4, 0x1D]
	adds r0, r4, 0
	str r3, [sp, 0x18]
	bl sub_80AFA74
	ldr r3, [sp, 0x18]
	cmp r6, 0x2
	beq _080AFC04
	cmp r6, 0x2
	bgt _080AFBF8
	cmp r6, 0x1
	beq _080AFBFE
	b _080AFC58
	.align 2, 0
_080AFBEC: .4byte 0x04000071
_080AFBF0: .4byte 0x04000078
_080AFBF4: .4byte 0x04000079
_080AFBF8:
	cmp r6, 0x3
	beq _080AFC10
	b _080AFC58
_080AFBFE:
	ldrb r0, [r4, 0x1F]
	ldr r2, [sp, 0x8]
	strb r0, [r2]
_080AFC04:
	ldr r0, [r4, 0x24]
	lsls r0, 6
	ldrb r1, [r4, 0x1E]
	adds r0, r1, r0
	strb r0, [r7]
	b _080AFC64
_080AFC10:
	ldr r1, [r4, 0x24]
	ldr r0, [r4, 0x28]
	cmp r1, r0
	beq _080AFC38
	ldr r2, [sp, 0x8]
	strb r3, [r2]
	ldr r1, _080AFC4C
	ldr r2, [r4, 0x24]
	ldr r0, [r2]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x8]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0xC]
	str r0, [r1]
	str r2, [r4, 0x28]
_080AFC38:
	ldr r0, [sp, 0x8]
	strb r5, [r0]
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _080AFC50
	movs r0, 0xC0
	b _080AFC72
	.align 2, 0
_080AFC4C: .4byte 0x04000090
_080AFC50:
	movs r1, 0x80
	negs r1, r1
	strb r1, [r4, 0x1A]
	b _080AFC74
_080AFC58:
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldr r0, [r4, 0x24]
	lsls r0, 3
	ldr r2, [sp, 0x10]
	strb r0, [r2]
_080AFC64:
	ldrb r0, [r4, 0x4]
	adds r0, 0x8
	mov r8, r0
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _080AFC72
	movs r0, 0x40
_080AFC72:
	strb r0, [r4, 0x1A]
_080AFC74:
	ldrb r1, [r4, 0x4]
	movs r2, 0
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	adds r1, r6, 0x1
	mov r10, r1
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r0, 0
	bne _080AFC8E
	b _080AFDCA
_080AFC8E:
	strb r2, [r4, 0x9]
	b _080AFDF8
_080AFC92:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _080AFCC4
	ldrb r0, [r4, 0xD]
	subs r0, 0x1
	strb r0, [r4, 0xD]
	movs r2, 0xFF
	ands r0, r2
	lsls r0, 24
	adds r1, r6, 0x1
	mov r10, r1
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	ble _080AFCB6
	b _080AFE0A
_080AFCB6:
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_80AFA24
	movs r0, 0
	strb r0, [r4]
	b _080AFF08
_080AFCC4:
	movs r0, 0x40
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	beq _080AFD04
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080AFD04
	movs r0, 0xFC
	ands r0, r1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x7]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _080AFD36
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _080AFDF8
	ldrb r2, [r4, 0x7]
	mov r8, r2
	b _080AFDF8
_080AFD04:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _080AFDF8
	cmp r6, 0x3
	bne _080AFD16
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
_080AFD16:
	adds r0, r4, 0
	bl sub_80AFA74
	movs r0, 0x3
	ldrb r2, [r4]
	ands r0, r2
	cmp r0, 0
	bne _080AFD6A
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	cmp r0, 0
	bgt _080AFD66
_080AFD36:
	ldrb r2, [r4, 0xC]
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	muls r0, r1
	adds r0, 0xFF
	asrs r0, 8
	movs r1, 0
	strb r0, [r4, 0x9]
	lsls r0, 24
	cmp r0, 0
	beq _080AFCB6
	movs r0, 0x4
	ldrb r2, [r4]
	orrs r0, r2
	strb r0, [r4]
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _080AFE0A
	movs r2, 0x8
	mov r8, r2
	b _080AFE0A
_080AFD66:
	ldrb r0, [r4, 0x7]
	b _080AFDF6
_080AFD6A:
	cmp r0, 0x1
	bne _080AFD76
_080AFD6E:
	ldrb r0, [r4, 0x19]
	strb r0, [r4, 0x9]
	movs r0, 0x7
	b _080AFDF6
_080AFD76:
	cmp r0, 0x2
	bne _080AFDBA
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	ldrb r2, [r4, 0x19]
	lsls r1, r2, 24
	cmp r0, r1
	bgt _080AFDB6
_080AFD8E:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _080AFD9E
	movs r0, 0xFC
	ldrb r1, [r4]
	ands r0, r1
	strb r0, [r4]
	b _080AFD36
_080AFD9E:
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	orrs r0, r2
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _080AFD6E
	movs r0, 0x8
	mov r8, r0
	b _080AFD6E
_080AFDB6:
	ldrb r0, [r4, 0x5]
	b _080AFDF6
_080AFDBA:
	ldrb r0, [r4, 0x9]
	adds r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	ldrb r2, [r4, 0xA]
	cmp r0, r2
	bcc _080AFDF4
_080AFDCA:
	ldrb r0, [r4]
	subs r0, 0x1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x5]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _080AFD8E
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	cmp r6, 0x3
	beq _080AFDF8
	ldrb r2, [r4, 0x5]
	mov r8, r2
	b _080AFDF8
_080AFDF4:
	ldrb r0, [r4, 0x4]
_080AFDF6:
	strb r0, [r4, 0xB]
_080AFDF8:
	ldrb r0, [r4, 0xB]
	subs r0, 0x1
	strb r0, [r4, 0xB]
	ldr r0, [sp]
	cmp r0, 0
	bne _080AFE0A
	subs r0, 0x1
	str r0, [sp]
	b _080AFD04
_080AFE0A:
	movs r0, 0x2
	ldrb r1, [r4, 0x1D]
	ands r0, r1
	cmp r0, 0
	beq _080AFE82
	cmp r6, 0x3
	bgt _080AFE4A
	movs r0, 0x8
	ldrb r2, [r4, 0x1]
	ands r0, r2
	cmp r0, 0
	beq _080AFE4A
	ldr r0, _080AFE34
	ldrb r0, [r0]
	cmp r0, 0x3F
	bgt _080AFE3C
	ldr r0, [r4, 0x20]
	adds r0, 0x2
	ldr r1, _080AFE38
	b _080AFE46
	.align 2, 0
_080AFE34: .4byte 0x04000089
_080AFE38: .4byte 0x000007fc
_080AFE3C:
	cmp r0, 0x7F
	bgt _080AFE4A
	ldr r0, [r4, 0x20]
	adds r0, 0x1
	ldr r1, _080AFE58
_080AFE46:
	ands r0, r1
	str r0, [r4, 0x20]
_080AFE4A:
	cmp r6, 0x4
	beq _080AFE5C
	ldr r0, [r4, 0x20]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	b _080AFE6A
	.align 2, 0
_080AFE58: .4byte 0x000007fe
_080AFE5C:
	ldr r2, [sp, 0x10]
	ldrb r0, [r2]
	movs r1, 0x8
	ands r1, r0
	ldr r0, [r4, 0x20]
	orrs r0, r1
	strb r0, [r2]
_080AFE6A:
	movs r0, 0xC0
	ldrb r1, [r4, 0x1A]
	ands r0, r1
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r0, r1, r0
	strb r0, [r4, 0x1A]
	movs r2, 0xFF
	ands r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_080AFE82:
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	ands r0, r2
	cmp r0, 0
	beq _080AFF08
	ldr r1, _080AFECC
	ldrb r0, [r1]
	ldrb r2, [r4, 0x1C]
	bics r0, r2
	ldrb r2, [r4, 0x1B]
	orrs r0, r2
	strb r0, [r1]
	cmp r6, 0x3
	bne _080AFED4
	ldr r0, _080AFED0
	ldrb r1, [r4, 0x9]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, [sp, 0xC]
	strb r0, [r2]
	movs r1, 0x80
	adds r0, r1, 0
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	cmp r0, 0
	beq _080AFF08
	ldr r0, [sp, 0x8]
	strb r1, [r0]
	ldrb r0, [r4, 0x1A]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	movs r0, 0x7F
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	strb r0, [r4, 0x1A]
	b _080AFF08
	.align 2, 0
_080AFECC: .4byte 0x04000081
_080AFED0: .4byte gUnknown_826FBF0
_080AFED4:
	movs r0, 0xF
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrb r2, [r4, 0x9]
	lsls r0, r2, 4
	add r0, r8
	ldr r1, [sp, 0xC]
	strb r0, [r1]
	movs r2, 0x80
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	cmp r6, 0x1
	bne _080AFF08
	ldr r0, [sp, 0x8]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080AFF08
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_080AFF08:
	movs r0, 0
	strb r0, [r4, 0x1D]
_080AFF0C:
	mov r6, r10
	mov r4, r9
	cmp r6, 0x4
	bgt _080AFF16
	b _080AFB0C
_080AFF16:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80AFADC

	thumb_func_start sub_80AFF28
sub_80AFF28:
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, [r2, 0x34]
	ldr r0, _080AFF4C
	cmp r3, r0
	bne _080AFF44
	strh r1, [r2, 0x1E]
	ldrh r4, [r2, 0x1C]
	adds r0, r1, 0
	muls r0, r4
	asrs r0, 8
	strh r0, [r2, 0x20]
_080AFF44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AFF4C: .4byte 0x68736d53
	thumb_func_end sub_80AFF28

	thumb_func_start sub_80AFF50
sub_80AFF50:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r6, r2, 16
	ldr r3, [r4, 0x34]
	ldr r0, _080AFFB4
	cmp r3, r0
	bne _080AFFA8
	adds r0, r3, 0x1
	str r0, [r4, 0x34]
	ldrb r2, [r4, 0x8]
	ldr r1, [r4, 0x2C]
	movs r5, 0x1
	cmp r2, 0
	ble _080AFFA4
	movs r0, 0x80
	mov r8, r0
	lsrs r6, 18
	movs r0, 0x3
	mov r12, r0
_080AFF80:
	adds r0, r7, 0
	ands r0, r5
	cmp r0, 0
	beq _080AFF9A
	ldrb r3, [r1]
	mov r0, r8
	ands r0, r3
	cmp r0, 0
	beq _080AFF9A
	strb r6, [r1, 0x13]
	mov r0, r12
	orrs r0, r3
	strb r0, [r1]
_080AFF9A:
	subs r2, 0x1
	adds r1, 0x50
	lsls r5, 1
	cmp r2, 0
	bgt _080AFF80
_080AFFA4:
	ldr r0, _080AFFB4
	str r0, [r4, 0x34]
_080AFFA8:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFFB4: .4byte 0x68736d53
	thumb_func_end sub_80AFF50

	thumb_func_start sub_80AFFB8
sub_80AFFB8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r12, r1
	lsls r2, 16
	lsrs r6, r2, 16
	ldr r3, [r4, 0x34]
	ldr r0, _080B0028
	cmp r3, r0
	bne _080B001A
	adds r0, r3, 0x1
	str r0, [r4, 0x34]
	ldrb r2, [r4, 0x8]
	ldr r3, [r4, 0x2C]
	movs r5, 0x1
	cmp r2, 0
	ble _080B0016
	movs r0, 0x80
	mov r9, r0
	lsls r0, r6, 16
	asrs r7, r0, 24
	movs r0, 0xC
	mov r8, r0
_080AFFF0:
	mov r0, r12
	ands r0, r5
	cmp r0, 0
	beq _080B000C
	ldrb r1, [r3]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _080B000C
	strb r7, [r3, 0xB]
	strb r6, [r3, 0xD]
	mov r0, r8
	orrs r0, r1
	strb r0, [r3]
_080B000C:
	subs r2, 0x1
	adds r3, 0x50
	lsls r5, 1
	cmp r2, 0
	bgt _080AFFF0
_080B0016:
	ldr r0, _080B0028
	str r0, [r4, 0x34]
_080B001A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0028: .4byte 0x68736d53
	thumb_func_end sub_80AFFB8

	thumb_func_start sub_80B002C
sub_80B002C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r3, [r4, 0x34]
	ldr r0, _080B0090
	cmp r3, r0
	bne _080B0084
	adds r0, r3, 0x1
	str r0, [r4, 0x34]
	ldrb r2, [r4, 0x8]
	ldr r1, [r4, 0x2C]
	movs r5, 0x1
	cmp r2, 0
	ble _080B0080
	movs r0, 0x80
	mov r8, r0
	movs r0, 0x3
	mov r12, r0
_080B005C:
	adds r0, r7, 0
	ands r0, r5
	cmp r0, 0
	beq _080B0076
	ldrb r3, [r1]
	mov r0, r8
	ands r0, r3
	cmp r0, 0
	beq _080B0076
	strb r6, [r1, 0x15]
	mov r0, r12
	orrs r0, r3
	strb r0, [r1]
_080B0076:
	subs r2, 0x1
	adds r1, 0x50
	lsls r5, 1
	cmp r2, 0
	bgt _080B005C
_080B0080:
	ldr r0, _080B0090
	str r0, [r4, 0x34]
_080B0084:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0090: .4byte 0x68736d53
	thumb_func_end sub_80B002C

	thumb_func_start sub_80B0094
sub_80B0094:
	adds r1, r0, 0
	movs r2, 0
	movs r0, 0
	strb r0, [r1, 0x1A]
	strb r0, [r1, 0x16]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	bne _080B00A8
	movs r0, 0xC
	b _080B00AA
_080B00A8:
	movs r0, 0x3
_080B00AA:
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	thumb_func_end sub_80B0094

	thumb_func_start sub_80B00B4
sub_80B00B4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r1, [r6, 0x34]
	ldr r0, _080B0124
	cmp r1, r0
	bne _080B0114
	adds r0, r1, 0x1
	str r0, [r6, 0x34]
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	movs r7, 0x1
	cmp r5, 0
	ble _080B0110
	mov r9, r8
_080B00E4:
	mov r0, r10
	ands r0, r7
	cmp r0, 0
	beq _080B0106
	movs r0, 0x80
	ldrb r1, [r4]
	ands r0, r1
	cmp r0, 0
	beq _080B0106
	mov r0, r8
	strb r0, [r4, 0x17]
	mov r1, r9
	cmp r1, 0
	bne _080B0106
	adds r0, r4, 0
	bl sub_80B0094
_080B0106:
	subs r5, 0x1
	adds r4, 0x50
	lsls r7, 1
	cmp r5, 0
	bgt _080B00E4
_080B0110:
	ldr r0, _080B0124
	str r0, [r6, 0x34]
_080B0114:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0124: .4byte 0x68736d53
	thumb_func_end sub_80B00B4

	thumb_func_start sub_80B0128
sub_80B0128:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r1, [r6, 0x34]
	ldr r0, _080B0198
	cmp r1, r0
	bne _080B0188
	adds r0, r1, 0x1
	str r0, [r6, 0x34]
	ldrb r5, [r6, 0x8]
	ldr r4, [r6, 0x2C]
	movs r7, 0x1
	cmp r5, 0
	ble _080B0184
	mov r9, r8
_080B0158:
	mov r0, r10
	ands r0, r7
	cmp r0, 0
	beq _080B017A
	movs r0, 0x80
	ldrb r1, [r4]
	ands r0, r1
	cmp r0, 0
	beq _080B017A
	mov r0, r8
	strb r0, [r4, 0x19]
	mov r1, r9
	cmp r1, 0
	bne _080B017A
	adds r0, r4, 0
	bl sub_80B0094
_080B017A:
	subs r5, 0x1
	adds r4, 0x50
	lsls r7, 1
	cmp r5, 0
	bgt _080B0158
_080B0184:
	ldr r0, _080B0198
	str r0, [r6, 0x34]
_080B0188:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0198: .4byte 0x68736d53
	thumb_func_end sub_80B0128

	thumb_func_start sub_80B019C
sub_80B019C:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r1, [r6, 0x40]
	ldrb r5, [r1]
	adds r2, r1, 0x1
	str r2, [r6, 0x40]
	ldr r0, [r4, 0x18]
	ldrb r1, [r1, 0x1]
	adds r3, r1, r0
	adds r0, r2, 0x1
	str r0, [r6, 0x40]
	ldrb r2, [r2, 0x1]
	adds r0, 0x1
	str r0, [r6, 0x40]
	cmp r5, 0x11
	bls _080B01C0
	b _080B02EE
_080B01C0:
	lsls r0, r5, 2
	ldr r1, _080B01CC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B01CC: .4byte _080B01D0
	.align 2, 0
_080B01D0:
	.4byte _080B0218
	.4byte _080B021C
	.4byte _080B0224
	.4byte _080B022C
	.4byte _080B0236
	.4byte _080B0244
	.4byte _080B0252
	.4byte _080B025A
	.4byte _080B0262
	.4byte _080B026A
	.4byte _080B0272
	.4byte _080B027A
	.4byte _080B0282
	.4byte _080B0290
	.4byte _080B029E
	.4byte _080B02AC
	.4byte _080B02BA
	.4byte _080B02C8
_080B0218:
	strb r2, [r3]
	b _080B02EE
_080B021C:
	ldrb r1, [r3]
	adds r0, r1, r2
	strb r0, [r3]
	b _080B02EE
_080B0224:
	ldrb r1, [r3]
	subs r0, r1, r2
	strb r0, [r3]
	b _080B02EE
_080B022C:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	b _080B02EE
_080B0236:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r1, [r3]
	ldrb r0, [r0]
	adds r0, r1, r0
	strb r0, [r3]
	b _080B02EE
_080B0244:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r1, [r3]
	ldrb r0, [r0]
	subs r0, r1, r0
	strb r0, [r3]
	b _080B02EE
_080B0252:
	ldrb r3, [r3]
	cmp r3, r2
	beq _080B02D4
	b _080B02E8
_080B025A:
	ldrb r3, [r3]
	cmp r3, r2
	bne _080B02D4
	b _080B02E8
_080B0262:
	ldrb r3, [r3]
	cmp r3, r2
	bhi _080B02D4
	b _080B02E8
_080B026A:
	ldrb r3, [r3]
	cmp r3, r2
	bcs _080B02D4
	b _080B02E8
_080B0272:
	ldrb r3, [r3]
	cmp r3, r2
	bls _080B02D4
	b _080B02E8
_080B027A:
	ldrb r3, [r3]
	cmp r3, r2
	bcc _080B02D4
	b _080B02E8
_080B0282:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	beq _080B02D4
	b _080B02E8
_080B0290:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bne _080B02D4
	b _080B02E8
_080B029E:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bhi _080B02D4
	b _080B02E8
_080B02AC:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bcs _080B02D4
	b _080B02E8
_080B02BA:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bls _080B02D4
	b _080B02E8
_080B02C8:
	ldr r0, [r4, 0x18]
	adds r0, r2
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bcs _080B02E8
_080B02D4:
	ldr r0, _080B02E4
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl _call_via_r2
	b _080B02EE
	.align 2, 0
_080B02E4: .4byte gUnknown_203AE84
_080B02E8:
	ldr r0, [r6, 0x40]
	adds r0, 0x4
	str r0, [r6, 0x40]
_080B02EE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80B019C

	thumb_func_start sub_80B02F4
sub_80B02F4:
	push {lr}
	ldr r2, [r1, 0x40]
	ldrb r3, [r2]
	adds r2, 0x1
	str r2, [r1, 0x40]
	ldr r2, _080B0310
	lsls r3, 2
	adds r3, r2
	ldr r2, [r3]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_080B0310: .4byte gUnknown_826FC34
	thumb_func_end sub_80B02F4

	thumb_func_start sub_80B0314
sub_80B0314:
	push {lr}
	ldr r2, _080B0324
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_080B0324: .4byte gUnknown_203AE80
	thumb_func_end sub_80B0314

	thumb_func_start sub_80B0328
sub_80B0328:
	push {r4,lr}
	ldr r2, [r1, 0x40]
	ldr r0, _080B0360
	ands r4, r0
	ldrb r0, [r2]
	orrs r4, r0
	ldrb r0, [r2, 0x1]
	lsls r3, r0, 8
	ldr r0, _080B0364
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, 0x2]
	lsls r3, r0, 16
	ldr r0, _080B0368
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, 0x3]
	lsls r3, r0, 24
	ldr r0, _080B036C
	ands r4, r0
	orrs r4, r3
	str r4, [r1, 0x28]
	adds r2, 0x4
	str r2, [r1, 0x40]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B0360: .4byte 0xffffff00
_080B0364: .4byte 0xffff00ff
_080B0368: .4byte 0xff00ffff
_080B036C: .4byte 0x00ffffff
	thumb_func_end sub_80B0328

	thumb_func_start sub_80B0370
sub_80B0370:
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	strb r2, [r0]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B0370

	thumb_func_start sub_80B0384
sub_80B0384:
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	adds r0, r1, 0
	adds r0, 0x2C
	strb r2, [r0]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B0384

	thumb_func_start sub_80B0398
sub_80B0398:
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x2D
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B0398

	thumb_func_start sub_80B03AC
sub_80B03AC:
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x2E
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B03AC

	thumb_func_start sub_80B03C0
sub_80B03C0:
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x2F
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B03C0

	thumb_func_start sub_80B03D4
sub_80B03D4:
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	strb r2, [r1, 0x1E]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B03D4

	thumb_func_start sub_80B03E0
sub_80B03E0:
	ldr r0, [r1, 0x40]
	ldrb r2, [r0]
	strb r2, [r1, 0x1F]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B03E0

	thumb_func_start sub_80B03EC
sub_80B03EC:
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x26
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end sub_80B03EC

	thumb_func_start ply_xswee
ply_xswee:
	ldr r0, [r1, 0x40]
	ldrb r0, [r0]
	adds r2, r1, 0
	adds r2, 0x27
	strb r0, [r2]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	bx lr
	thumb_func_end ply_xswee

	thumb_func_start nullsub_139
nullsub_139:
	bx lr
	thumb_func_end nullsub_139

	.align 2, 0 @ Don't pad with nop.
