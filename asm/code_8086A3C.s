	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start ZapdosPreFightDialogue
ZapdosPreFightDialogue:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x70
	bl xxx_call_GetLeader
	mov r9, r0
	bl GetPartnerEntity
	adds r6, r0, 0
	movs r0, 0x8
	bl GetEntityFromClientType
	str r0, [sp, 0x68]
	bl sub_8086448
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl SpriteLookAroundEffect
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	movs r1, 0x4
	movs r2, 0x1
	movs r3, 0x2
	bl sub_80869E4
	mov r0, r9
	movs r1, 0x4
	movs r2, 0x2
	movs r3, 0x6
	bl sub_80869E4
	ldr r0, _08087470
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	movs r1, 0x4
	movs r2, 0x2
	movs r3, 0x4
	bl sub_80869E4
	mov r0, r9
	movs r1, 0x4
	movs r2, 0x1
	movs r3, 0x4
	bl sub_80869E4
	ldr r0, _08087474
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	movs r0, 0x3
	bl ZapdosScreenFlash
	bl DungeonStopBGM
	movs r0, 0xED
	lsls r0, 1
	bl PlaySoundEffect
	ldr r0, _08087478
	bl DisplayDungeonDialogue
	ldr r0, [sp, 0x68]
	bl ZapdosDropInEffect
	movs r0, 0x9
	bl DungeonStartNewBGM
	adds r0, r6, 0
	movs r1, 0x6
	movs r2, 0x4
	bl sub_806CDD4
	ldr r0, _0808747C
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	movs r1, 0x2
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80869E4
	mov r1, sp
	ldr r0, _08087480
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	mov r0, sp
	str r0, [sp, 0x58]
	str r6, [sp, 0x5C]
	add r4, sp, 0x18
	add r1, sp, 0x58
	add r2, sp, 0x5C
	adds r0, r4, 0
	movs r3, 0x1
	bl sub_8085B4C
	ldr r0, [r6, 0x70]
	ldr r2, _08087484
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
	add r7, sp, 0x28
	add r3, sp, 0x48
	mov r8, r3
	add r0, sp, 0x60
	mov r10, r0
	mov r1, sp
	adds r1, 0x64
	str r1, [sp, 0x6C]
	b _0808748E
	.align 2, 0
_08087470: .4byte gUnknown_81014B0
_08087474: .4byte gUnknown_8101504
_08087478: .4byte gUnknown_81015A0
_0808747C: .4byte gUnknown_81015D4
_08087480: .4byte gUnknown_810744C
_08087484: .4byte 0x0000015f
_08087488:
	movs r0, 0x46
	bl sub_803E46C
_0808748E:
	adds r0, r4, 0
	bl sub_8085B80
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08087488
	ldr r0, [r6, 0x70]
	ldr r2, _08087510
	adds r0, r2
	strb r5, [r0]
	ldr r0, [r6, 0x70]
	ldr r4, _08087514
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
	adds r0, r6, 0
	movs r1, 0x2
	movs r2, 0x2
	movs r3, 0x4
	bl sub_80869E4
	ldr r0, _08087518
	bl DisplayDungeonDialogue
	movs r0, 0x3C
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808751C
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	ldr r0, [r6, 0x70]
	adds r0, r4
	strb r5, [r0]
	adds r0, r6, 0
	movs r1, 0x2
	movs r2, 0x2
	movs r3, 0x5
	bl sub_80869E4
	adds r1, r7, 0
	ldr r0, _08087520
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r3,r4}
	stm r1!, {r3,r4}
	str r7, [sp, 0x60]
	str r6, [sp, 0x64]
	mov r0, r8
	mov r1, r10
	ldr r2, [sp, 0x6C]
	movs r3, 0x1
	bl sub_8085B4C
	mov r4, r9
	adds r4, 0xC
	b _0808752A
	.align 2, 0
_08087510: .4byte 0x0000015f
_08087514: .4byte 0x0000015d
_08087518: .4byte gUnknown_81015E8
_0808751C: .4byte gUnknown_8101624
_08087520: .4byte gUnknown_8107464
_08087524:
	movs r0, 0x46
	bl sub_803E46C
_0808752A:
	mov r0, r8
	bl sub_8085B80
	lsls r0, 24
	cmp r0, 0
	bne _08087524
	adds r0, r6, 0
	movs r1, 0x2
	movs r2, 0x1
	movs r3, 0x3
	bl sub_80869E4
	ldr r0, _080875B0
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	movs r0, 0x3
	bl ZapdosScreenFlash
	ldr r0, _080875B4
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	movs r0, 0x1
	bl ZapdosScreenFlash
	ldr r0, _080875B8
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	movs r0, 0x2
	bl ZapdosScreenFlash
	ldr r0, _080875BC
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	movs r1, 0x96
	lsls r1, 1
	ldr r0, [sp, 0x68]
	movs r2, 0xB
	bl SetupBossFightHP
	adds r0, r4, 0
	movs r1, 0x10
	bl ShiftCameraToPosition
	add sp, 0x70
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080875B0: .4byte gUnknown_810165C
_080875B4: .4byte gUnknown_8101750
_080875B8: .4byte gUnknown_810178C
_080875BC: .4byte gUnknown_81017B4
	thumb_func_end ZapdosPreFightDialogue

    .align 2,0
