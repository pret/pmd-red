	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8011398
sub_8011398:
	push {r4-r6,lr}
	sub sp, 0x12C
	ldr r5, _080113F4
	ldr r0, [r5]
	ldr r2, _080113F8
	adds r1, r0, r2
	ldr r1, [r1]
	ldr r3, _080113FC
	adds r0, r3
	lsls r1, 5
	ldr r0, [r0]
	adds r6, r0, r1
	add r4, sp, 0xCC
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r2, 0x3
	str r2, [r4, 0x4]
	movs r0, 0x7
	strh r0, [r4, 0x8]
	movs r1, 0x2
	strh r1, [r4, 0xA]
	movs r0, 0x15
	strh r0, [r4, 0xC]
	strh r1, [r4, 0xE]
	strh r1, [r4, 0x10]
	str r2, [r4, 0x1C]
	str r2, [r4, 0x34]
	str r2, [r4, 0x4C]
	ldr r0, [r5]
	ldr r2, _08011400
	adds r1, r0, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	subs r2, 0x4
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r1, r0
	cmp r1, 0x50
	bgt _08011404
	movs r0, 0x11
	b _08011406
	.align 2, 0
_080113F4: .4byte gUnknown_203B0E4
_080113F8: .4byte 0x00004a18
_080113FC: .4byte 0x00004014
_08011400: .4byte 0x00004dda
_08011404:
	movs r0, 0x1
_08011406:
	strh r0, [r4, 0xA]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	movs r0, 0
	bl sub_80073B8
	ldr r1, _0801147C
	ldr r2, [r6]
	add r0, sp, 0x4
	bl sprintfStatic
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0x2
	add r2, sp, 0x4
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	ldr r0, _08011480
	ldr r1, [r0]
	ldr r0, _08011484
	adds r2, r1, r0
	movs r3, 0x8
	ldrsh r0, [r4, r3]
	lsls r0, 3
	subs r0, 0x5
	str r0, [r2]
	ldr r0, _08011488
	adds r2, r1, r0
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r0, 0x5
	str r0, [r2]
	ldr r0, _0801148C
	adds r2, r1, r0
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	lsls r0, 3
	adds r0, 0xA
	str r0, [r2]
	ldr r0, _08011490
	adds r1, r0
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	lsls r0, 3
	adds r0, 0xA
	str r0, [r1]
	add sp, 0x12C
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801147C: .4byte gUnknown_80D40FC
_08011480: .4byte gUnknown_203B0E4
_08011484: .4byte 0x00004ddc
_08011488: .4byte 0x00004de0
_0801148C: .4byte 0x00004de4
_08011490: .4byte 0x00004de8
	thumb_func_end sub_8011398

	thumb_func_start sub_8011494
sub_8011494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC8
	ldr r0, _08011610
	ldr r2, [r0]
	ldr r1, _08011614
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r3, _08011618
	adds r1, r2, r3
	lsls r0, 5
	ldr r1, [r1]
	adds r1, r0
	mov r8, r1
	ldr r0, _0801161C
	adds r7, r2, r0
	add r4, sp, 0x64
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x68]
	add r1, sp, 0x6C
	movs r0, 0x7
	strh r0, [r1]
	movs r2, 0x2
	strh r2, [r1, 0x2]
	add r1, sp, 0x70
	movs r0, 0x15
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x72
	strh r2, [r0]
	add r0, sp, 0x74
	strh r2, [r0]
	add r5, sp, 0xC4
	str r5, [sp, 0x78]
	movs r1, 0x3
	str r1, [sp, 0x80]
	add r0, sp, 0x94
	str r1, [r0, 0x4]
	add r0, sp, 0xAC
	str r1, [r0, 0x4]
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	movs r1, 0
	mov r9, r1
	movs r6, 0
	mov r10, r5
_08011506:
	mov r0, r8
	adds r0, 0x8
	adds r4, r0, r6
	ldrb r0, [r4]
	bl sub_800FFE8
	lsls r0, 24
	cmp r0, 0
	beq _0801152A
	ldr r0, _08011610
	ldr r0, [r0]
	ldr r2, _08011620
	adds r0, r2
	add r0, r9
	ldrb r1, [r4]
	strb r1, [r0]
	movs r3, 0x1
	add r9, r3
_0801152A:
	adds r6, 0x1
	cmp r6, 0x7
	ble _08011506
	ldr r5, _08011610
	ldr r0, [r5]
	ldr r1, _08011624
	adds r0, r1
	mov r2, r9
	str r2, [r0]
	movs r4, 0
	movs r0, 0x1
	mov r3, r10
	strb r0, [r3]
	add r0, sp, 0xC4
	strb r4, [r0, 0x1]
	movs r1, 0x12
	strb r1, [r0, 0x2]
	strb r4, [r0, 0x3]
	strh r4, [r7, 0x18]
	strh r2, [r7, 0x1A]
	mov r0, r9
	strh r0, [r7, 0x1C]
	strh r4, [r7, 0x1E]
	strh r4, [r7, 0x20]
	strh r4, [r7, 0x4]
	movs r0, 0x10
	strh r0, [r7, 0x6]
	str r4, [r7]
	strh r4, [r7, 0xC]
	strh r4, [r7, 0xE]
	strh r4, [r7, 0x14]
	strh r4, [r7, 0x16]
	movs r0, 0x8
	strh r0, [r7, 0x8]
	strh r0, [r7, 0xA]
	adds r0, r7, 0
	adds r0, 0x28
	bl sub_801317C
	movs r1, 0x1C
	ldrsh r0, [r7, r1]
	movs r1, 0
	bl sub_80095E4
	adds r1, r0, 0
	add r3, sp, 0x4
	adds r2, r3, 0
	adds r0, r1, 0x2
	strh r0, [r2, 0xE]
	strh r0, [r3, 0x10]
	lsls r1, 3
	adds r0, r7, 0
	bl sub_80137B0
	add r0, sp, 0x4
	movs r1, 0x1
	movs r2, 0x1
	bl xxx_call_save_unk_text_struct_800641C
	ldr r1, [r5]
	ldr r2, _08011628
	adds r0, r1, r2
	str r4, [r0]
	ldr r3, _0801162C
	adds r0, r1, r3
	str r4, [r0]
	adds r2, 0x8
	adds r0, r1, r2
	str r4, [r0]
	adds r3, 0x8
	adds r1, r3
	str r4, [r1]
	movs r0, 0
	bl sub_80073B8
	ldr r2, _08011630
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r6, 0
	cmp r6, r9
	bge _08011678
	add r0, sp, 0x64
	mov r8, r0
	ldr r1, _08011634
	mov r10, r1
_080115DC:
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r2, _08011610
	ldr r0, [r2]
	ldr r3, _08011620
	adds r0, r3
	adds r0, r6
	ldrb r5, [r0]
	ldr r0, _08011638
	adds r1, r5, 0
	bl sub_80101F8
	cmp r5, 0
	bne _08011640
	str r5, [sp]
	movs r0, 0xC
	adds r1, r4, 0
	ldr r2, _0801163C
	movs r3, 0
	bl PrintFormattedStringOnWindow
	b _08011672
	.align 2, 0
_08011610: .4byte gUnknown_203B0E4
_08011614: .4byte 0x00004a18
_08011618: .4byte 0x00004014
_0801161C: .4byte 0x00004dfc
_08011620: .4byte 0x00004dec
_08011624: .4byte 0x00004df8
_08011628: .4byte 0x00004ddc
_0801162C: .4byte 0x00004de0
_08011630: .4byte gUnknown_80D4104
_08011634: .4byte gFormatArgs
_08011638: .4byte gFormatBuffer_Items
_0801163C: .4byte gUnknown_80D4120
_08011640:
	ldr r1, _08011690
	ldr r0, [r1]
	ldr r2, _08011694
	adds r0, r2
	ldrb r2, [r0]
	adds r0, r5, 0
	mov r1, r8
	bl sub_80926F8
	mov r3, r8
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	mov r2, r10
	str r0, [r2]
	movs r1, 0
	ldrsh r0, [r3, r1]
	str r0, [r2, 0x4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	adds r1, r4, 0
	ldr r2, _08011698
	movs r3, 0
	bl PrintFormattedStringOnWindow
_08011672:
	adds r6, 0x1
	cmp r6, r9
	blt _080115DC
_08011678:
	movs r0, 0
	bl sub_80073E0
	add sp, 0xC8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011690: .4byte gUnknown_203B0E4
_08011694: .4byte 0x00004a2c
_08011698: .4byte gUnknown_80D4124
	thumb_func_end sub_8011494

        .align 2,0
