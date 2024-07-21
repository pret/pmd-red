	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_803E490
sub_803E490:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r1, _0803E4D8
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bl xxx_draw_string_80524F0
	bl sub_8085F78
	movs r0, 0x1
	bl sub_803F580
	ldr r2, _0803E4DC
	ldr r1, [r2]
	ldr r3, _0803E4E0
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803E4EC
	ldr r4, _0803E4E4
	adds r1, r4
	movs r0, 0x2
	strb r0, [r1]
	ldr r1, [r2]
	ldr r2, _0803E4E8
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r4, 0x16
	adds r1, r4
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl SetBG2RegOffsets
	b _0803E4FC
	.align 2, 0
_0803E4D8: .4byte gUnknown_202EDD4
_0803E4DC: .4byte gDungeon
_0803E4E0: .4byte 0x0001821a
_0803E4E4: .4byte 0x00018208
_0803E4E8: .4byte 0x000181f0
_0803E4EC:
	ldr r3, _0803E628
	adds r1, r3
	movs r0, 0x3
	strb r0, [r1]
	movs r0, 0
	movs r1, 0
	bl SetBG2RegOffsets
_0803E4FC:
	ldr r4, _0803E62C
	ldr r2, [r4]
	ldr r5, _0803E630
	adds r0, r2, r5
	movs r1, 0
	ldrsh r0, [r0, r1]
	ldr r3, _0803E634
	adds r1, r2, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	ldr r3, _0803E638
	adds r2, r3
	ldr r2, [r2]
	subs r1, r2
	bl SetBG3RegOffsets
	bl sub_806CC10
	bl sub_804522C
	bl sub_803F9CC
	ldr r0, [r4]
	adds r0, r5
	bl sub_800F7D0
	ldr r1, [r4]
	ldrh r2, [r1, 0x12]
	movs r3, 0x12
	ldrsh r0, [r1, r3]
	cmp r0, 0x63
	bgt _0803E540
	adds r0, r2, 0x1
	strh r0, [r1, 0x12]
_0803E540:
	ldr r0, [r4]
	adds r0, r5
	bl sub_800E90C
	bl sub_8042E5C
	ldr r0, _0803E63C
	ldr r0, [r0]
	cmp r0, 0
	beq _0803E562
	cmp r0, 0x3
	beq _0803E562
	ldr r0, _0803E640
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0x6
	bne _0803E566
_0803E562:
	bl sub_8040894
_0803E566:
	bl sub_803ECE0
	bl sub_803EDF0
	ldr r0, _0803E62C
	ldr r3, [r0]
	ldr r4, _0803E644
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0803E5A2
	ldr r1, _0803E648
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, 0x3
	beq _0803E5A2
	ldr r0, _0803E64C
	ldrb r0, [r0]
	ldr r1, _0803E650
	ldr r2, _0803E654
	ldr r2, [r2]
	str r2, [sp]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r3, r4
	str r2, [sp, 0x4]
	movs r2, 0xA0
	movs r3, 0x20
	bl sub_8004AF0
_0803E5A2:
	ldr r0, _0803E640
	ldr r0, [r0]
	ldrb r0, [r0, 0xA]
	bl nullsub_8
	bl sub_8005180
	bl nullsub_12
	bl sub_80060EC
	ldr r1, _0803E658
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, _0803E65C
	ldr r0, [r0]
	bl IncrementPlayTime
	bl sub_800CB20
	bl LoadBufferedInputs
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	bl TransferBGPaletteBuffer
	bl sub_8009908
	bl xxx_call_update_bg_vram
	bl sub_8040788
	bl xxx_call_update_bg_sound_input
	ldr r0, _0803E62C
	ldr r0, [r0]
	ldr r1, _0803E660
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	bl UpdateDungeonMusic
	bl sub_8011860
	bl sub_8040B60
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	ldr r1, _0803E664
	ldr r0, [r1]
	subs r0, 0x1
	str r0, [r1]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E628: .4byte 0x00018208
_0803E62C: .4byte gDungeon
_0803E630: .4byte 0x000181f0
_0803E634: .4byte 0x000181f2
_0803E638: .4byte 0x000181fc
_0803E63C: .4byte gUnknown_202EDD0
_0803E640: .4byte gGameOptionsRef
_0803E644: .4byte 0x00018215
_0803E648: .4byte 0x0001c06c
_0803E64C: .4byte gUnknown_203B40D
_0803E650: .4byte gUnknown_202EE8C
_0803E654: .4byte gUnknown_202EDC8
_0803E658: .4byte gUnknown_202EDCC
_0803E65C: .4byte gPlayTimeRef
_0803E660: .4byte 0x00018213
_0803E664: .4byte gUnknown_202EDD4
	thumb_func_end sub_803E490

@ https://decomp.me/scratch/biQXr (kermalis 100%) `void sub_803E668(u32)`
	.align 2, 0