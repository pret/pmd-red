	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
_0800C6B4: .4byte gCurrentFanfareSong
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
	bl IsMusicPlayerPlaying
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
_0800C6F8: .4byte gCurrentFanfareSong
_0800C6FC: .4byte 0x000003e5
_0800C700:
	ldr r0, _0800C724
	ldrh r1, [r0]
	ldr r0, _0800C728
	cmp r1, r0
	beq _0800C718
	movs r0, 0x1
	bl IsMusicPlayerPlaying
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
_0800C724: .4byte gCurrentFanfareSong
_0800C728: .4byte 0x000003e5
_0800C72C: .4byte gUnknown_202D692
_0800C730:
	ldr r0, _0800C74C
	ldrh r1, [r0]
	ldr r0, _0800C750
	cmp r1, r0
	beq _0800C754
	movs r0, 0x1
	bl IsMusicPlayerPlaying
	lsls r0, 24
	cmp r0, 0
	beq _0800C748
	b _0800C8A2
_0800C748:
	b _0800C75A
	.align 2, 0
_0800C74C: .4byte gCurrentFanfareSong
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
_0800C76C: .4byte gMPlayInfo_Fanfare
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
_0800C7A0: .4byte gRestartBGM
_0800C7A4:
	ldr r0, _0800C7B0
	movs r1, 0x4
	bl m4aMPlayFadeIn
	b _0800C7BE
	.align 2, 0
_0800C7B0: .4byte gMPlayInfo_BGM
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
_0800C7D0: .4byte gMPlayInfo_BGM
_0800C7D4: .4byte gUnknown_202D690
_0800C7D8: .4byte gCurrentFanfareSong
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
	bl IsMusicPlayerPlaying
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
	bl IsMusicPlayerPlaying
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
_0800C854: .4byte gMPlayInfo_BGM
_0800C858: .4byte gBGMusicPlayerState
_0800C85C: .4byte gCurrentBGSong
_0800C860: .4byte 0x000003e7
_0800C864:
	movs r0, 0
	bl IsMusicPlayerPlaying
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
	bl IsMusicPlayerPlaying
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
	bl IsMusicPlayerPlaying
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
