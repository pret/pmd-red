	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_800C298
sub_800C298:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, _0800C2F0
	mov r8, r0
	cmp r5, r8
	bne _0800C2FC
	bl DisableInterrupts
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r4, _0800C2F4
	ldr r0, _0800C2F8
	movs r1, 0
	mov r10, r1
	movs r7, 0
	adds r6, r0, 0
	adds r6, 0x18
	movs r5, 0x4
_0800C2C8:
	ldr r0, [r6]
	bl m4aMPlayStop
	strh r7, [r4]
	mov r2, r8
	strh r2, [r4, 0x2]
	strh r7, [r4, 0x4]
	mov r0, r10
	strb r0, [r4, 0x6]
	adds r6, 0xC
	subs r5, 0x1
	adds r4, 0x8
	cmp r5, 0
	bge _0800C2C8
	mov r1, r9
	cmp r1, 0
	beq _0800C3DE
	bl EnableInterrupts
	b _0800C3DE
	.align 2, 0
_0800C2F0: .4byte 0x000003e5
_0800C2F4: .4byte gUnknown_3000FE8
_0800C2F8: .4byte gMPlayTable
_0800C2FC:
	adds r0, r5, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C364
	adds r0, r5, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0800C330
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r7, [r1]
	lsls r2, r0, 3
	ldr r1, _0800C334
	adds r4, r2, r1
	cmp r0, 0x1
	bhi _0800C338
	adds r0, r5, 0
	bl nullsub_21
	b _0800C3DE
	.align 2, 0
_0800C330: .4byte gMPlayTable
_0800C334: .4byte gUnknown_3000FD8
_0800C338:
	bl DisableInterrupts
	lsls r0, 24
	lsrs r6, r0, 24
	ldrh r0, [r4, 0x2]
	cmp r0, r5
	bne _0800C35A
	adds r0, r7, 0
	bl m4aMPlayStop
	movs r1, 0
	movs r0, 0
	strh r0, [r4]
	mov r2, r8
	strh r2, [r4, 0x2]
	strh r0, [r4, 0x4]
	strb r1, [r4, 0x6]
_0800C35A:
	cmp r6, 0
	beq _0800C3DE
	bl EnableInterrupts
	b _0800C3DE
_0800C364:
	ldr r0, _0800C398
	cmp r5, r0
	bne _0800C3A8
	bl DisableInterrupts
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0800C39C
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C38C
	ldr r1, _0800C3A0
	ldrh r0, [r1]
	cmp r0, r8
	beq _0800C38C
	mov r0, r8
	strh r0, [r1]
	ldr r0, _0800C3A4
	bl m4aMPlayStop
_0800C38C:
	cmp r4, 0
	beq _0800C3DE
	bl EnableInterrupts
	b _0800C3DE
	.align 2, 0
_0800C398: .4byte 0x000003e6
_0800C39C: .4byte gUnknown_202D690
_0800C3A0: .4byte gUnknown_202D68E
_0800C3A4: .4byte gUnknown_2000970
_0800C3A8:
	adds r0, r5, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800C3DE
	bl DisableInterrupts
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, _0800C3EC
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C3D6
	ldr r1, _0800C3F0
	ldrh r0, [r1]
	cmp r0, r5
	bne _0800C3D6
	mov r2, r8
	strh r2, [r1]
	ldr r0, _0800C3F4
	bl m4aMPlayStop
_0800C3D6:
	cmp r4, 0
	beq _0800C3DE
	bl EnableInterrupts
_0800C3DE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C3EC: .4byte gUnknown_202D690
_0800C3F0: .4byte gUnknown_202D68E
_0800C3F4: .4byte gUnknown_2000970
	thumb_func_end sub_800C298

	thumb_func_start sub_800C3F8
sub_800C3F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	cmp r1, r0
	bls _0800C416
	movs r0, 0x10
	mov r9, r0
	b _0800C422
_0800C416:
	lsrs r1, 20
	mov r9, r1
	cmp r1, 0
	bne _0800C422
	movs r1, 0x1
	mov r9, r1
_0800C422:
	ldr r0, _0800C460
	mov r8, r0
	cmp r4, r8
	bne _0800C496
	bl DisableInterrupts
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r7, 0x2
	ldr r5, _0800C464
	ldr r0, _0800C468
	adds r6, r0, 0
	adds r6, 0x18
_0800C43E:
	ldrh r0, [r5, 0x2]
	cmp r0, r8
	beq _0800C47E
	lsls r0, r7, 16
	lsrs r0, 16
	bl sub_800CAF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800C46C
	ldr r0, [r6]
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C47E
	.align 2, 0
_0800C460: .4byte 0x000003e5
_0800C464: .4byte gUnknown_3000FE8
_0800C468: .4byte gMPlayTable
_0800C46C:
	ldr r0, [r6]
	bl m4aMPlayStop
	strh r4, [r5]
	mov r1, r8
	strh r1, [r5, 0x2]
	strh r4, [r5, 0x4]
	movs r0, 0
	strb r0, [r5, 0x6]
_0800C47E:
	adds r6, 0xC
	adds r7, 0x1
	adds r5, 0x8
	cmp r7, 0x6
	ble _0800C43E
	mov r1, r10
	cmp r1, 0
	bne _0800C490
	b _0800C5BE
_0800C490:
	bl EnableInterrupts
	b _0800C5BE
_0800C496:
	adds r0, r4, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C508
	adds r0, r4, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, r4, 3
	ldr r0, _0800C4E4
	adds r5, r1, r0
	ldr r1, _0800C4E8
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldr r6, [r0]
	bl DisableInterrupts
	lsls r0, 24
	lsrs r7, r0, 24
	ldrh r0, [r5, 0x2]
	cmp r0, r8
	beq _0800C4FE
	adds r0, r4, 0
	bl sub_800CAF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0800C4EC
	adds r0, r6, 0
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C4FE
	.align 2, 0
_0800C4E4: .4byte gUnknown_3000FD8
_0800C4E8: .4byte gMPlayTable
_0800C4EC:
	adds r0, r6, 0
	bl m4aMPlayStop
	movs r0, 0
	strh r4, [r5]
	mov r1, r8
	strh r1, [r5, 0x2]
	strh r4, [r5, 0x4]
	strb r0, [r5, 0x6]
_0800C4FE:
	cmp r7, 0
	beq _0800C5BE
	bl EnableInterrupts
	b _0800C5BE
_0800C508:
	ldr r0, _0800C53C
	cmp r4, r0
	bne _0800C564
	bl DisableInterrupts
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _0800C540
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C556
	ldr r4, _0800C544
	ldrh r0, [r4]
	cmp r0, r8
	beq _0800C556
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C54C
	ldr r0, _0800C548
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C556
	.align 2, 0
_0800C53C: .4byte 0x000003e6
_0800C540: .4byte gUnknown_202D690
_0800C544: .4byte gUnknown_202D68E
_0800C548: .4byte gUnknown_2000970
_0800C54C:
	ldr r0, _0800C560
	bl m4aMPlayStop
	mov r0, r8
	strh r0, [r4]
_0800C556:
	cmp r5, 0
	beq _0800C5BE
	bl EnableInterrupts
	b _0800C5BE
	.align 2, 0
_0800C560: .4byte gUnknown_2000970
_0800C564:
	adds r0, r4, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800C5BE
	bl DisableInterrupts
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, _0800C5A0
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C5B6
	ldr r5, _0800C5A4
	ldrh r0, [r5]
	cmp r0, r4
	bne _0800C5B6
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C5AC
	ldr r0, _0800C5A8
	mov r1, r9
	bl m4aMPlayFadeOut
	b _0800C5B6
	.align 2, 0
_0800C5A0: .4byte gUnknown_202D690
_0800C5A4: .4byte gUnknown_202D68E
_0800C5A8: .4byte gUnknown_2000970
_0800C5AC:
	ldr r0, _0800C5CC
	bl m4aMPlayStop
	mov r1, r8
	strh r1, [r5]
_0800C5B6:
	cmp r6, 0
	beq _0800C5BE
	bl EnableInterrupts
_0800C5BE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C5CC: .4byte gUnknown_2000970
	thumb_func_end sub_800C3F8

	thumb_func_start sub_800C5D0
sub_800C5D0:
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	adds r0, r4, 0
	bl sub_800CACC
	lsls r0, 24
	cmp r0, 0
	beq _0800C600
	ldr r0, _0800C5F8
	ldrh r0, [r0]
	cmp r0, 0
	beq _0800C630
	ldr r0, _0800C5FC
	ldrh r0, [r0]
	cmp r0, r4
	bne _0800C630
	movs r0, 0x1
	b _0800C632
	.align 2, 0
_0800C5F8: .4byte gUnknown_202D690
_0800C5FC: .4byte gUnknown_202D68E
_0800C600:
	adds r0, r4, 0
	bl sub_800CAAC
	lsls r0, 24
	cmp r0, 0
	beq _0800C630
	adds r0, r4, 0
	bl sub_800CAE0
	lsls r0, 16
	lsrs r0, 16
	lsls r2, r0, 3
	ldr r1, _0800C62C
	adds r2, r1
	cmp r0, 0x1
	bls _0800C630
	ldrh r0, [r2, 0x2]
	cmp r0, r5
	bne _0800C630
	movs r0, 0x1
	b _0800C632
	.align 2, 0
_0800C62C: .4byte gUnknown_3000FD8
_0800C630:
	movs r0, 0
_0800C632:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_800C5D0

	thumb_func_start SoundVSync
SoundVSync:
	push {r4,lr}
	bl DisableInterrupts
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl m4aSoundVSync
	cmp r4, 0
	beq _0800C650
	bl EnableInterrupts
_0800C650:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SoundVSync

	thumb_func_start nullsub_18
nullsub_18:
	bx lr
	thumb_func_end nullsub_18

	thumb_func_start UpdateSound
UpdateSound:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl m4aSoundMain
	ldr r4, _0800C680
	ldrh r0, [r4]
	cmp r0, 0
	bne _0800C670
	b _0800C7E0
_0800C670:
	cmp r0, 0x2
	beq _0800C6C0
	cmp r0, 0x2
	bgt _0800C684
	cmp r0, 0x1
	beq _0800C68E
	b _0800C8A2
	.align 2, 0
_0800C680: .4byte gUnknown_202D690
_0800C684:
	cmp r0, 0x3
	beq _0800C700
	cmp r0, 0x4
	beq _0800C730
	b _0800C8A2
_0800C68E:
	ldr r2, _0800C69C
	ldrh r0, [r2]
	cmp r0, 0
	beq _0800C6A0
	subs r0, 0x1
	strh r0, [r2]
	b _0800C8A2
	.align 2, 0
_0800C69C: .4byte gUnknown_202D692
_0800C6A0:
	ldr r3, _0800C6B4
	ldrh r1, [r3]
	ldr r0, _0800C6B8
	cmp r1, r0
	bne _0800C6BC
	movs r0, 0x4
	strh r0, [r4]
	movs r0, 0x20
	strh r0, [r2]
	b _0800C8A2
	.align 2, 0
_0800C6B4: .4byte gUnknown_202D68E
_0800C6B8: .4byte 0x000003e5
_0800C6BC:
	ldrh r0, [r3]
	b _0800C6E4
_0800C6C0:
	ldr r0, _0800C6F0
	ldrh r1, [r0]
	ldr r0, _0800C6F4
	cmp r1, r0
	beq _0800C6D8
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C6D8
	b _0800C8A2
_0800C6D8:
	ldr r2, _0800C6F8
	ldrh r1, [r2]
	ldr r0, _0800C6FC
	cmp r1, r0
	beq _0800C718
	ldrh r0, [r2]
_0800C6E4:
	bl m4aSongNumStart
	movs r0, 0x3
	strh r0, [r4]
	b _0800C8A2
	.align 2, 0
_0800C6F0: .4byte gCurrentBGSong
_0800C6F4: .4byte 0x000003e7
_0800C6F8: .4byte gUnknown_202D68E
_0800C6FC: .4byte 0x000003e5
_0800C700:
	ldr r0, _0800C724
	ldrh r1, [r0]
	ldr r0, _0800C728
	cmp r1, r0
	beq _0800C718
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	bne _0800C718
	b _0800C8A2
_0800C718:
	movs r0, 0x4
	strh r0, [r4]
	ldr r1, _0800C72C
	movs r0, 0x20
	strh r0, [r1]
	b _0800C8A2
	.align 2, 0
_0800C724: .4byte gUnknown_202D68E
_0800C728: .4byte 0x000003e5
_0800C72C: .4byte gUnknown_202D692
_0800C730:
	ldr r0, _0800C74C
	ldrh r1, [r0]
	ldr r0, _0800C750
	cmp r1, r0
	beq _0800C754
	movs r0, 0x1
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C748
	b _0800C8A2
_0800C748:
	b _0800C75A
	.align 2, 0
_0800C74C: .4byte gUnknown_202D68E
_0800C750: .4byte 0x000003e5
_0800C754:
	ldr r0, _0800C76C
	bl m4aMPlayStop
_0800C75A:
	ldr r1, _0800C770
	ldrh r0, [r1]
	adds r2, r0, 0
	cmp r2, 0
	beq _0800C774
	subs r0, 0x1
	strh r0, [r1]
	b _0800C8A2
	.align 2, 0
_0800C76C: .4byte gUnknown_2000970
_0800C770: .4byte gUnknown_202D692
_0800C774:
	ldr r3, _0800C794
	ldrh r1, [r3]
	ldr r0, _0800C798
	cmp r1, r0
	beq _0800C7B4
	ldr r1, _0800C79C
	movs r0, 0x1
	strh r0, [r1]
	ldr r0, _0800C7A0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800C7A4
	ldrh r0, [r3]
	bl m4aSongNumStart
	b _0800C7BE
	.align 2, 0
_0800C794: .4byte gCurrentBGSong
_0800C798: .4byte 0x000003e7
_0800C79C: .4byte gBGMusicPlayerState
_0800C7A0: .4byte gUnknown_202D694
_0800C7A4:
	ldr r0, _0800C7B0
	movs r1, 0x4
	bl m4aMPlayFadeIn
	b _0800C7BE
	.align 2, 0
_0800C7B0: .4byte gUnknown_20008F0
_0800C7B4:
	ldr r0, _0800C7CC
	strh r2, [r0]
	ldr r0, _0800C7D0
	bl m4aMPlayStop
_0800C7BE:
	ldr r1, _0800C7D4
	movs r0, 0
	strh r0, [r1]
	ldr r1, _0800C7D8
	ldr r2, _0800C7DC
	b _0800C84C
	.align 2, 0
_0800C7CC: .4byte gBGMusicPlayerState
_0800C7D0: .4byte gUnknown_20008F0
_0800C7D4: .4byte gUnknown_202D690
_0800C7D8: .4byte gUnknown_202D68E
_0800C7DC: .4byte 0x000003e5
_0800C7E0:
	ldr r5, _0800C810
	ldrh r0, [r5]
	cmp r0, 0
	beq _0800C864
	cmp r0, 0x3
	bgt _0800C8A2
	cmp r0, 0x2
	bge _0800C81C
	cmp r0, 0x1
	bne _0800C8A2
	ldr r0, _0800C814
	ldrh r1, [r0]
	ldr r0, _0800C818
	cmp r1, r0
	beq _0800C80A
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C8A2
_0800C80A:
	movs r0, 0x2
	strh r0, [r5]
	b _0800C8A2
	.align 2, 0
_0800C810: .4byte gBGMusicPlayerState
_0800C814: .4byte gCurrentBGSong
_0800C818: .4byte 0x000003e7
_0800C81C:
	ldr r0, _0800C834
	ldrh r1, [r0]
	ldr r0, _0800C838
	cmp r1, r0
	beq _0800C83C
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	bne _0800C8A2
	b _0800C842
	.align 2, 0
_0800C834: .4byte gCurrentBGSong
_0800C838: .4byte 0x000003e7
_0800C83C:
	ldr r0, _0800C854
	bl m4aMPlayStop
_0800C842:
	ldr r1, _0800C858
	movs r0, 0
	strh r0, [r1]
	ldr r1, _0800C85C
	ldr r2, _0800C860
_0800C84C:
	adds r0, r2, 0
	strh r0, [r1]
	b _0800C8A2
	.align 2, 0
_0800C854: .4byte gUnknown_20008F0
_0800C858: .4byte gBGMusicPlayerState
_0800C85C: .4byte gCurrentBGSong
_0800C860: .4byte 0x000003e7
_0800C864:
	movs r0, 0
	bl sub_800CAF0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0800C8A2
	ldr r6, _0800C890
	ldrh r2, [r6]
	adds r1, r2, 0
	ldr r4, _0800C894
	cmp r1, r4
	beq _0800C89C
	movs r0, 0x1
	strh r0, [r5]
	ldr r0, _0800C898
	strh r2, [r0]
	adds r0, r1, 0
	bl m4aSongNumStart
	strh r4, [r6]
	b _0800C8A2
	.align 2, 0
_0800C890: .4byte gUnknown_202D68C
_0800C894: .4byte 0x000003e7
_0800C898: .4byte gCurrentBGSong
_0800C89C:
	strh r0, [r5]
	ldr r0, _0800C8C4
	strh r1, [r0]
_0800C8A2:
	movs r5, 0x2
	ldr r4, _0800C8C8
	ldr r0, _0800C8CC
	mov r8, r0
	movs r6, 0x18
	movs r7, 0
_0800C8AE:
	ldrh r1, [r4, 0x2]
	cmp r1, r8
	beq _0800C926
	ldrh r0, [r4]
	cmp r0, 0x1
	beq _0800C8D0
	cmp r0, 0x1
	ble _0800C926
	cmp r0, 0x2
	beq _0800C8F0
	b _0800C926
	.align 2, 0
_0800C8C4: .4byte gCurrentBGSong
_0800C8C8: .4byte gUnknown_3000FE8
_0800C8CC: .4byte 0x000003e5
_0800C8D0:
	ldr r0, _0800C8EC
	cmp r1, r0
	beq _0800C8E4
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_800CAF0
	lsls r0, 24
	cmp r0, 0
	beq _0800C926
_0800C8E4:
	movs r0, 0x2
	strh r0, [r4]
	b _0800C926
	.align 2, 0
_0800C8EC: .4byte 0x000003e7
_0800C8F0:
	lsls r0, r5, 16
	lsrs r0, 16
	bl sub_800CAF0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0800C91C
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	beq _0800C926
	strb r7, [r4, 0x6]
	ldr r0, _0800C918
	adds r0, r6, r0
	ldr r0, [r0]
	ldrh r2, [r4, 0x4]
	movs r1, 0xFF
	bl m4aMPlayVolumeControl
	b _0800C926
	.align 2, 0
_0800C918: .4byte gMPlayTable
_0800C91C:
	strh r0, [r4]
	mov r1, r8
	strh r1, [r4, 0x2]
	strh r0, [r4, 0x4]
	strb r7, [r4, 0x6]
_0800C926:
	adds r6, 0xC
	adds r5, 0x1
	adds r4, 0x8
	cmp r5, 0x6
	ble _0800C8AE
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end UpdateSound

        .align 2,0
