	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

 	.text

@ https://decomp.me/scratch/aIvCa - SpriteOAM memes
	thumb_func_start InitShadowSprites
InitShadowSprites:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	str r1, [sp]
	ldr r0, _0808E628
	ldr r1, _0808E62C
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	ldr r4, [r7, 0x4]
	movs r6, 0x7
	adds r4, 0x4
	mov r1, r8
	lsls r0, r1, 5
	ldr r2, _0808E630
	adds r5, r0, r2
_0808E564:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x20
	bl CpuCopy
	adds r5, 0x20
	adds r4, 0x20
	subs r6, 0x1
	cmp r6, 0
	bne _0808E564
	adds r0, r7, 0
	bl CloseFile
	movs r6, 0
	movs r0, 0x3
	mov r12, r0
	ldr r1, _0808E634
	mov r10, r1
	ldr r2, _0808E638
	mov r9, r2
	ldr r5, _0808E63C
	movs r7, 0
	mov r4, r12
	ldr r0, [sp]
	ands r4, r0
	lsls r4, 10
_0808E598:
	lsls r3, r6, 3
	ldr r0, _0808E640
	adds r3, r0
	ldrh r1, [r3]
	ldr r0, _0808E644
	ands r0, r1
	ldr r1, _0808E648
	ands r0, r1
	mov r2, r10
	ands r0, r2
	ldr r1, _0808E64C
	ands r0, r1
	ldr r1, _0808E650
	ands r0, r1
	strh r0, [r3]
	ldr r1, [r5]
	mov r2, r12
	ands r1, r2
	lsls r1, 14
	mov r2, r9
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r3, 0x2]
	ldr r1, _0808E654
	ands r1, r0
	strh r1, [r3, 0x2]
	ldr r0, _0808E63C
	adds r0, 0x4
	adds r0, r7, r0
	ldr r0, [r0]
	mov r2, r12
	ands r0, r2
	lsls r0, 14
	mov r2, r9
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x2]
	ldr r1, [r5, 0x8]
	add r1, r8
	ldr r0, _0808E658
	ands r1, r0
	ldrh r2, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	mov r1, r10
	ands r0, r1
	orrs r0, r4
	ldr r1, _0808E65C
	ands r0, r1
	strh r0, [r3, 0x4]
	ldrh r1, [r3, 0x6]
	ldr r0, _0808E660
	ands r0, r1
	ldr r1, _0808E664
	ands r0, r1
	strh r0, [r3, 0x6]
	adds r5, 0xC
	adds r7, 0xC
	adds r6, 0x1
	cmp r6, 0x2
	ble _0808E598
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E628: .4byte gUnknown_81076BC
_0808E62C: .4byte gDungeonFileArchive
_0808E630: .4byte 0x06010000
_0808E634: .4byte 0x0000f3ff
_0808E638: .4byte 0x00003fff
_0808E63C: .4byte gShadowSpriteSizeFlags_8107698
_0808E640: .4byte gShadowSprites
_0808E644: .4byte 0x0000feff
_0808E648: .4byte 0x0000fdff
_0808E64C: .4byte 0x0000efff
_0808E650: .4byte 0x0000dfff
_0808E654: .4byte 0x0000c1ff
_0808E658: .4byte 0x000003ff
_0808E65C: .4byte 0x00000fff
_0808E660: .4byte 0x0000fffe
_0808E664: .4byte 0x0000fffd
	thumb_func_end InitShadowSprites
	
	.align 2, 0 @ Don't pad with nop.
