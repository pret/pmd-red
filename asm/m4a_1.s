	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/m4a_constants.inc"

	.syntax unified

	.text

	thumb_func_start umul3232H32
umul3232H32:
	adr r2, __umul3232H32
	bx r2
	.arm
__umul3232H32:
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

	thumb_func_start SoundMainBTM
SoundMainBTM:
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
	thumb_func_end SoundMainBTM

	thumb_func_start RealClearChain
RealClearChain:
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
	thumb_func_end RealClearChain

	thumb_func_start ply_fine
ply_fine:
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq ply_fine_done
ply_fine_loop:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq ply_fine_ok
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
ply_fine_ok:
	adds r0, r4, 0
	bl RealClearChain
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne ply_fine_loop
ply_fine_done:
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end ply_fine

	thumb_func_start MPlayJumpTableCopy
MPlayJumpTableCopy:
	mov r12, lr
	movs r1, 0x24
	ldr r2, lt_MPlayJumpTableTemplate
MPlayJumpTableCopy_Loop:
	ldr r3, [r2]
	bl chk_adr_r2
	stm r0!, {r3}
	adds r2, 0x4
	subs r1, 0x1
	bgt MPlayJumpTableCopy_Loop
	bx r12
	thumb_func_end MPlayJumpTableCopy

	.align 2, 0
	.thumb_func
ldrb_r3_r2:
	ldrb r3, [r2]

	.thumb_func
chk_adr_r2:
	push {r0}
	lsrs r0, r2, 25
	bne chk_adr_r2_done 
	ldr r0, lt_MPlayJumpTableTemplate
	cmp r2, r0
	bcc chk_adr_r2_reject
	lsrs r0, r2, 14
	beq chk_adr_r2_done 
chk_adr_r2_reject:
	movs r3, 0
chk_adr_r2_done:
	pop {r0}
	bx lr
	.align 2, 0
lt_MPlayJumpTableTemplate: .word gMPlayJumpTableTemplate

	thumb_func_start ld_r3_tp_adr_i
ld_r3_tp_adr_i:
	ldr r2, [r1, 0x40]
_080AE73A:
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	b chk_adr_r2
	thumb_func_end ld_r3_tp_adr_i

	thumb_func_start ply_goto
ply_goto:
	push {lr}
ply_goto_1:
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	ldrb r3, [r2, 0x2]
	orrs r0, r3
	lsls r0, 8
	ldrb r3, [r2, 0x1]
	orrs r0, r3
	lsls r0, 8
	bl ldrb_r3_r2
	orrs r0, r3
	str r0, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0
	thumb_func_end ply_goto

	thumb_func_start ply_patt
ply_patt:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 0x3
	bcs _080AE77C
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	adds r2, 0x4
	str r2, [r3, o_MusicPlayerTrack_patternStack]
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	adds r2, 0x1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	b ply_goto
_080AE77C:
	b ply_fine
	thumb_func_end ply_patt

	thumb_func_start ply_pend
ply_pend:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 0
	beq ply_pend_done
	subs r2, 1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r3, o_MusicPlayerTrack_patternStack]
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
ply_pend_done:
	bx lr
	thumb_func_end ply_pend

	thumb_func_start ply_rept
ply_rept:
	push {lr}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0
	bne ply_rept_1
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b ply_goto_1
ply_rept_1:
	ldrb r3, [r1, o_MusicPlayerTrack_repN]
	adds r3, 1
	strb r3, [r1, o_MusicPlayerTrack_repN]
	mov r12, r3
	bl ld_r3_tp_adr_i
	cmp r12, r3
	bhs ply_rept_2
	b ply_goto_1
ply_rept_2:
	movs r3, 0
	strb r3, [r1, o_MusicPlayerTrack_repN]
	adds r2, 5
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0
	thumb_func_end ply_rept

	thumb_func_start ply_prio
ply_prio:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_priority]
	bx r12
	thumb_func_end ply_prio

	thumb_func_start ply_tempo
ply_tempo:
	mov r12, lr
	bl ld_r3_tp_adr_i
	lsls r3, 1
	strh r3, [r0, o_MusicPlayerInfo_tempoD]
	ldrh r2, [r0, o_MusicPlayerInfo_tempoU]
	muls r3, r2
	lsrs r3, 8
	strh r3, [r0, o_MusicPlayerInfo_tempoI]
	bx r12
	thumb_func_end ply_tempo

	thumb_func_start ply_keysh
ply_keysh:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_keyShift]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_keysh

	thumb_func_start ply_voice
ply_voice:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 2
	ldr r3, [r0, o_MusicPlayerInfo_tone]
	adds r2, r3
	ldr r3, [r2]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_type]
	ldr r3, [r2, 0x4]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_wav]
	ldr r3, [r2, 0x8]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_attack]
	bx r12
	thumb_func_end ply_voice

	thumb_func_start ply_vol
ply_vol:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_vol]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_vol

	thumb_func_start ply_pan
ply_pan:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_pan]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_pan

	thumb_func_start ply_bend
ply_bend:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_bend]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_bend

	thumb_func_start ply_bendr
ply_bendr:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_bendRange]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_bendr

	thumb_func_start ply_lfodl
ply_lfodl:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_lfoDelay]
	bx r12
	thumb_func_end ply_lfodl

	thumb_func_start ply_modt
ply_modt:
	mov r12, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, o_MusicPlayerTrack_modT]
	cmp r0, r3
	beq _080AE89A
	strb r3, [r1, o_MusicPlayerTrack_modT]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xF
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
_080AE89A:
	bx r12
	thumb_func_end ply_modt

	thumb_func_start ply_tune
ply_tune:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_tune]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	thumb_func_end ply_tune

	thumb_func_start ply_port
ply_port:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 0x1
	ldr r0, =REG_SOUND1CNT_L @ sound register base address
	adds r0, r3
	bl _080AE73A
	strb r3, [r0]
	bx r12
	.pool
	thumb_func_end ply_port

	thumb_func_start m4aSoundVSync
m4aSoundVSync:
	ldr r0, lt2_SOUND_INFO_PTR
	ldr r0, [r0]

	@ Exit the function if ident is not ID_NUMBER or ID_NUMBER+1.
	ldr r2, lt2_ID_NUMBER
	ldr r3, [r0, o_SoundInfo_ident]
	subs r3, r2
	cmp r3, 0x1
	bhi m4aSoundVSync_Done

	@ Decrement the PCM DMA counter. If it reaches 0, we need to do a DMA.
	ldrb r1, [r0, o_SoundInfo_pcmDmaCounter]
	subs r1, 0x1
	strb r1, [r0, o_SoundInfo_pcmDmaCounter]
	bgt m4aSoundVSync_Done
	
	@ Reload the PCM DMA counter.
	ldrb r1, [r0, o_SoundInfo_pcmDmaPeriod]
	strb r1, [r0, o_SoundInfo_pcmDmaCounter]

	ldr r2, =REG_DMA1

	ldr r1, [r2, 0x8] @ DMA1CNT
	lsls r1, 7
	bcc m4aSoundVSync_SkipDMA1 

	ldr r1, =((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4
	str r1, [r2, 0x8] @ DMA1CNT

m4aSoundVSync_SkipDMA1:
	ldr r1, [r2, 0xC + 0x8] @ DMA2CNT
	lsls r1, 7
	bcc m4aSoundVSync_SkipDMA2
	ldr r1, =((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4
	str r1, [r2, 0xC + 0x8] @ DMA2CNT

m4aSoundVSync_SkipDMA2:
	movs r1, DMA_32BIT >> 8
	lsls r1, 8
	strh r1, [r2, 0xA]       @ DMA1CNT_H
	strh r1, [r2, 0xC + 0xA] @ DMA2CNT_H

	movs r1, (DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT) >> 8
	lsls r1, 8 @ LSB is 0, so DMA_SRC_INC is used (destination is always fixed in FIFO mode)
	strh r1, [r2, 0xA]       @ DMA1CNT_H
	strh r1, [r2, 0xC + 0xA] @ DMA2CNT_H

m4aSoundVSync_Done:
	bx lr

	.pool
	thumb_func_end m4aSoundVSync

	thumb_func_start MPlayMain
MPlayMain:
	ldr r2, lt2_ID_NUMBER
	ldr r3, [r0, o_MusicPlayerInfo_ident]
	cmp r2, r3
	beq _080AE91E
	bx lr
_080AE91E:
	adds r3, 0x1
	str r3, [r0, o_MusicPlayerInfo_ident]
	push {r0,lr}
	ldr r3, [r0, o_MusicPlayerInfo_func]
	cmp r3, 0
	beq _080AE930
	ldr r0, [r0, o_MusicPlayerInfo_intp]
	bl call_r3_2
_080AE930:
	pop {r0}
	push {r4-r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	adds r7, r0, 0
	ldr r0, [r7, o_MusicPlayerInfo_status]
	cmp r0, 0
	bge _080AE948
	b _080AEB5C
_080AE948:
	ldr r0, lt2_SOUND_INFO_PTR
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, 0
	bl FadeOutBody
	ldr r0, [r7, o_MusicPlayerInfo_status]
	cmp r0, 0
	bge _080AE95C
	b _080AEB5C
_080AE95C:
	ldrh r0, [r7, o_MusicPlayerInfo_tempoC]
	ldrh r1, [r7, o_MusicPlayerInfo_tempoI]
	adds r0, r1
	b _080AEAAC
_080AE964:
	ldrb r6, [r7, o_MusicPlayerInfo_trackCount]
	ldr r5, [r7, o_MusicPlayerInfo_tracks]
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
	ldr r4, [r5, o_MusicPlayerTrack_chan]
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
	bl ClearChain
_080AE9A4:
	ldr r4, [r4, 0x34]
	cmp r4, 0
	bne _080AE982
_080AE9AA:
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x40
	tst r0, r3
	beq _080AEA28
	adds r0, r5, 0
	bl Clear64byte
	movs r0, 0x80
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, o_MusicPlayerTrack_bendRange]
	movs r0, 0x40
	strb r0, [r5, o_MusicPlayerTrack_volX]
	movs r0, 0x16
	strb r0, [r5, o_MusicPlayerTrack_lfoSpeed]
	movs r0, 0x1
	adds r1, r5, 0x6
	strb r0, [r1, o_MusicPlayerTrack_ToneData_type - 0x6]
	b _080AEA28
_080AE9D0:
	ldr r2, [r5, o_MusicPlayerTrack_cmdPtr]
	ldrb r1, [r2]
	cmp r1, 0x80
	bcs _080AE9DC
	ldrb r1, [r5, o_MusicPlayerTrack_runningStatus]
	b _080AE9E6
_080AE9DC:
	adds r2, 0x1
	str r2, [r5, o_MusicPlayerTrack_cmdPtr]
	cmp r1, 0xBD
	bcc _080AE9E6
	strb r1, [r5, o_MusicPlayerTrack_runningStatus]
_080AE9E6:
	cmp r1, 0xCF
	bcc _080AE9FC
	mov r0, r8
	ldr r3, [r0, o_SoundInfo_plynote]
	adds r0, r1, 0
	subs r0, 0xCF
	adds r1, r7, 0
	adds r2, r5, 0
	bl call_r3_2
	b _080AEA28
_080AE9FC:
	cmp r1, 0xB0
	bls _080AEA1E
	adds r0, r1, 0
	subs r0, 0xB1
	strb r0, [r7, o_MusicPlayerInfo_cmd]
	mov r3, r8
	ldr r3, [r3, o_SoundInfo_MPlayJumpTable]
	lsls r0, 2
	ldr r3, [r3, r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl call_r3_2
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	cmp r0, 0
	beq _080AEA84
	b _080AEA28
_080AEA1E:
	ldr r0, lt_gClockTable
	subs r1, 0x80
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r5, o_MusicPlayerTrack_wait]
_080AEA28:
	ldrb r0, [r5, o_MusicPlayerTrack_wait]
	cmp r0, 0
	beq _080AE9D0
	subs r0, 0x1
	strb r0, [r5, o_MusicPlayerTrack_wait]
	ldrb r1, [r5, o_MusicPlayerTrack_lfoSpeed]
	cmp r1, 0
	beq _080AEA84
	ldrb r0, [r5, o_MusicPlayerTrack_mod]
	cmp r0, 0
	beq _080AEA84
	ldrb r0, [r5, o_MusicPlayerTrack_lfoDelayC]
	cmp r0, 0
	beq _080AEA4A
	subs r0, 0x1
	strb r0, [r5, o_MusicPlayerTrack_lfoDelayC]
	b _080AEA84
_080AEA4A:
	ldrb r0, [r5, o_MusicPlayerTrack_lfoSpeedC]
	adds r0, r1
	strb r0, [r5, o_MusicPlayerTrack_lfoSpeedC]
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
	ldrb r0, [r5, o_MusicPlayerTrack_mod]
	muls r0, r2
	asrs r2, r0, 6
	ldrb r0, [r5, o_MusicPlayerTrack_modM]
	eors r0, r2
	lsls r0, 24
	beq _080AEA84
	strb r2, [r5, o_MusicPlayerTrack_modM]
	ldrb r0, [r5]
	ldrb r1, [r5, o_MusicPlayerTrack_modT]
	cmp r1, 0
	bne _080AEA7E
	movs r1, 0xC
	b _080AEA80
_080AEA7E:
	movs r1, 0x3
_080AEA80:
	orrs r0, r1
	strb r0, [r5, o_MusicPlayerTrack_flags]
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
	ldr r0, [r7, o_MusicPlayerInfo_clock]
	adds r0, 0x1
	str r0, [r7, o_MusicPlayerInfo_clock]
	cmp r4, 0
	bne _080AEAA6
	movs r0, 0x80
	lsls r0, 24
	str r0, [r7, o_MusicPlayerInfo_status]
	b _080AEB5C
_080AEAA6:
	str r4, [r7, o_MusicPlayerInfo_status]
	ldrh r0, [r7, o_MusicPlayerInfo_tempoC]
	subs r0, 0x96
_080AEAAC:
	strh r0, [r7, o_MusicPlayerInfo_tempoC]
	cmp r0, 0x96
	bcc _080AEAB4
	b _080AE964
_080AEAB4:
	ldrb r2, [r7, o_MusicPlayerInfo_trackCount]
	ldr r5, [r7, o_MusicPlayerInfo_tracks]
_080AEAB8:
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	movs r1, 0x80
	tst r1, r0
	beq _080AEB52
	movs r1, 0xF
	tst r1, r0
	beq _080AEB52
	mov r9, r2
	adds r0, r7, 0
	adds r1, r5, 0
	bl TrkVolPitSet
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq _080AEB48
_080AEAD6:
	ldrb r1, [r4, o_SoundChannel_status]
	movs r0, 0xC7
	tst r0, r1
	bne _080AEAE6
	adds r0, r4, 0
	bl ClearChain
	b _080AEB42
_080AEAE6:
	ldrb r0, [r4, o_SoundChannel_type]
	movs r6, 0x7
	ands r6, r0
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x3
	tst r0, r3
	beq _080AEB04
	bl ChnVolSetAsm
	cmp r6, 0
	beq _080AEB04
	ldrb r0, [r4, o_CgbChannel_mo]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, o_CgbChannel_mo]
_080AEB04:
	ldrb r3, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0xC
	tst r0, r3
	beq _080AEB42
	ldrb r1, [r4, o_SoundChannel_ky]
	movs r0, 0x8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _080AEB18
	movs r2, 0
_080AEB18:
	cmp r6, 0
	beq _080AEB36
	mov r0, r8
	ldr r3, [r0, o_SoundInfo_MidiKeyToCgbFreq]
	adds r1, r2, 0
	ldrb r2, [r5, o_MusicPlayerTrack_pitM]
	adds r0, r6, 0
	bl call_r3_2
	str r0, [r4, o_CgbChannel_fr]
	ldrb r0, [r4, o_CgbChannel_mo]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4, o_CgbChannel_mo]
	b _080AEB42
_080AEB36:
	adds r1, r2, 0
	ldrb r2, [r5, o_MusicPlayerTrack_pitM]
	ldr r0, [r4, o_SoundChannel_wav]
	bl MidiKeyToFreq
	str r0, [r4, o_SoundChannel_freq]
_080AEB42:
	ldr r4, [r4, o_SoundChannel_np]
	cmp r4, 0
	bne _080AEAD6
_080AEB48:
	ldrb r0, [r5, o_MusicPlayerTrack_flags]
	movs r1, 0xF0
	ands r0, r1
	strb r0, [r5, o_MusicPlayerTrack_flags]
	mov r2, r9
_080AEB52:
	subs r2, 0x1
	ble _080AEB5C
	movs r0, 0x50
	adds r5, r0
	bgt _080AEAB8
_080AEB5C:
	ldr r0, lt2_ID_NUMBER
	str r0, [r7, o_MusicPlayerInfo_ident]
	pop {r0-r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}
call_r3_2:
	bx r3
	.align 2, 0

lt_gClockTable:     .word gClockTable
lt2_SOUND_INFO_PTR: .word SOUND_INFO_PTR
lt2_ID_NUMBER:      .word ID_NUMBER
	thumb_func_end MPlayMain

	thumb_func_start TrackStop
TrackStop:
	push {r4-r6,lr}
	adds r5, r1, 0
	ldrb r1, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x80
	tst r0, r1
	beq TrackStop_Done
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq TrackStop_3
	movs r6, 0
TrackStop_Loop:
	ldrb r0, [r4, o_SoundChannel_status]
	cmp r0, 0
	beq TrackStop_2
	ldrb r0, [r4, o_SoundChannel_type]
	movs r3, 0x7
	ands r0, r3
	beq TrackStop_1
	ldr r3, =SOUND_INFO_PTR
	ldr r3, [r3]
	ldr r3, [r3, o_SoundInfo_CgbOscOff]
	bl call_r3_2
TrackStop_1:
	strb r6, [r4, o_SoundChannel_status]
TrackStop_2:
	str r6, [r4, o_SoundChannel_track]
	ldr r4, [r4, o_SoundChannel_np]
	cmp r4, 0
	bne TrackStop_Loop
TrackStop_3:
	str r4, [r5, o_MusicPlayerTrack_chan]
TrackStop_Done:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TrackStop

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm:
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
	thumb_func_end ChnVolSetAsm

	thumb_func_start ply_note
ply_note:
	push {r4-r7,lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	sub sp, 0x18
	str r1, [sp]
	adds r5, r2, 0
	ldr r1, =SOUND_INFO_PTR
	ldr r1, [r1]
	str r1, [sp, 0x4]
	ldr r1, =gClockTable
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r5, o_MusicPlayerTrack_gateTime]
	ldr r3, [r5, o_MusicPlayerTrack_cmdPtr]
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _080AEC36
	strb r0, [r5, o_MusicPlayerTrack_key]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _080AEC34
	strb r0, [r5, o_MusicPlayerTrack_velocity]
	adds r3, 0x1
	ldrb r0, [r3]
	cmp r0, 0x80
	bcs _080AEC34
	ldrb r1, [r5, o_MusicPlayerTrack_gateTime]
	adds r1, r0
	strb r1, [r5, o_MusicPlayerTrack_gateTime]
	adds r3, 0x1
_080AEC34:
	str r3, [r5, o_MusicPlayerTrack_cmdPtr]
_080AEC36:
	movs r0, 0
	str r0, [sp, 0x14]
	adds r4, r5, 0
	adds r4, o_MusicPlayerTrack_ToneData_type
	ldrb r2, [r4]
	movs r0, TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL
	tst r0, r2
	beq _080AEC88
	ldrb r3, [r5, o_MusicPlayerTrack_key]
	movs r0, TONEDATA_TYPE_SPL
	tst r0, r2
	beq _080AEC56
	ldr r1, [r5, o_MusicPlayerTrack_ToneData_keySplitTable]
	adds r1, r3
	ldrb r0, [r1]
	b _080AEC58
_080AEC56:
	adds r0, r3, 0
_080AEC58:
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, [r5, o_MusicPlayerTrack_ToneData_wav]
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
	bl ClearChain
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
	bl clear_modM
_080AED56:
	ldr r0, [sp]
	adds r1, r5, 0
	bl TrkVolPitSet
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
	bl ChnVolSetAsm
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
	bl call_r3_2
	b _080AEDC8
_080AEDBE:
	ldrb r2, [r5, 0x9]
	adds r1, r3, 0
	adds r0, r7, 0
	bl MidiKeyToFreq
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
	.pool
	thumb_func_end ply_note

	thumb_func_start ply_endtie
ply_endtie:
	push {r4,r5}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0x80
	bcs _080AEE02
	strb r3, [r1, o_MusicPlayerTrack_key]
	adds r2, 0x1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b _080AEE04
_080AEE02:
	ldrb r3, [r1, o_MusicPlayerTrack_key]
_080AEE04:
	ldr r1, [r1, o_MusicPlayerTrack_chan]
	cmp r1, 0
	beq _080AEE2C
	movs r4, 0x83
	movs r5, 0x40
_080AEE0E:
	ldrb r2, [r1, o_SoundChannel_status]
	tst r2, r4
	beq _080AEE26
	tst r2, r5
	bne _080AEE26
	ldrb r0, [r1, o_SoundChannel_mk]
	cmp r0, r3
	bne _080AEE26
	movs r0, 0x40
	orrs r2, r0
	strb r2, [r1, o_SoundChannel_status]
	b _080AEE2C
_080AEE26:
	ldr r1, [r1, o_SoundChannel_np]
	cmp r1, 0
	bne _080AEE0E
_080AEE2C:
	pop {r4,r5}
	bx lr
	thumb_func_end ply_endtie

	thumb_func_start clear_modM
clear_modM:
	movs r2, 0
	strb r2, [r1, o_MusicPlayerTrack_modM]
	strb r2, [r1, o_MusicPlayerTrack_lfoSpeedC]
	ldrb r2, [r1, o_MusicPlayerTrack_modT]
	cmp r2, 0
	bne _080AEE40
	movs r2, 0xC
	b _080AEE42
_080AEE40:
	movs r2, 0x3
_080AEE42:
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx lr
	thumb_func_end clear_modM

	thumb_func_start ld_r3_tp_adr_i_unchecked
ld_r3_tp_adr_i_unchecked:
	ldr r2, [r1, 0x40]
	adds r3, r2, 0x1
	str r3, [r1, 0x40]
	ldrb r3, [r2]
	bx lr
	thumb_func_end ld_r3_tp_adr_i_unchecked

	thumb_func_start ply_lfos
ply_lfos:
	mov r12, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, o_MusicPlayerTrack_lfoSpeed]
	cmp r3, 0
	bne _080AEE68
	bl clear_modM
_080AEE68:
	bx r12
	thumb_func_end ply_lfos

	thumb_func_start ply_mod
ply_mod:
	mov r12, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, o_MusicPlayerTrack_mod]
	cmp r3, 0
	bne _080AEE7C
	bl clear_modM
_080AEE7C:
	bx r12
	thumb_func_end ply_mod

	.align 2, 0 @ Don't pad with nop.
