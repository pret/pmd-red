	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_8010F28
sub_8010F28:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	add r0, sp, 0x8
	bl sub_8004E8C
	add r1, sp, 0x8
	ldr r0, _08011080
	strh r0, [r1, 0x4]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1, 0xA]
	ldr r6, _08011084
	ldr r0, [r6]
	ldr r2, _08011088
	adds r1, r0, r2
	ldr r1, [r1]
	mov r8, r1
	ldr r4, _0801108C
	adds r0, r4
	bl sub_80054BC
	ldr r3, [r6]
	adds r4, r3, r4
	ldr r7, _08011090
	adds r0, r3, r7
	movs r2, 0
	ldrsh r1, [r0, r2]
	mov r7, r8
	lsls r5, r7, 16
	asrs r5, 16
	subs r1, r5
	ldr r2, _08011094
	adds r0, r3, r2
	movs r7, 0
	ldrsh r2, [r0, r7]
	mov r7, r8
	asrs r0, r7, 16
	subs r2, r0
	ldr r0, _08011098
	adds r3, r0
	ldr r0, [r3]
	str r0, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	adds r0, r4, 0
	movs r3, 0x3
	bl DoAxFrame_800558C
	movs r7, 0
	mov r10, r6
	ldr r6, _0801109C
	mov r9, r5
_08010F98:
	mov r4, r10
	ldr r0, [r4]
	adds r4, r0, r6
	ldr r1, _080110A0
	adds r0, r1
	lsls r1, r7, 5
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _08010FD8
	adds r4, 0x14
	adds r0, r4, 0
	bl sub_80054BC
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	mov r3, r9
	subs r1, r3
	movs r0, 0x6
	ldrsh r2, [r5, r0]
	mov r3, r8
	asrs r0, r3, 16
	subs r2, r0
	movs r0, 0
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r3, 0x1
	bl DoAxFrame_800558C
_08010FD8:
	adds r6, 0x50
	adds r7, 0x1
	cmp r7, 0x1F
	ble _08010F98
	movs r5, 0
	ldr r1, _08011084
	mov r9, r1
	ldr r6, _080110A4
	movs r2, 0
	str r2, [sp, 0x14]
_08010FEC:
	mov r3, r9
	ldr r1, [r3]
	ldr r4, [sp, 0x14]
	adds r0, r4, r1
	ldr r7, _080110A4
	adds r0, r7
	ldrh r0, [r0]
	lsrs r0, 15
	cmp r0, 0
	beq _08011062
	adds r0, r1, r6
	bl sub_80054BC
	ldr r0, _080110A8
	ldrh r0, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0801101E
	movs r0, 0x1
	ands r0, r5
	cmp r0, 0
	beq _08011062
_0801101E:
	mov r3, r9
	ldr r4, [r3]
	adds r0, r4, r6
	ldr r1, _080110AC
	lsls r3, r5, 2
	adds r3, r1
	movs r7, 0
	ldrsh r1, [r3, r7]
	ldr r7, _08011090
	adds r2, r4, r7
	movs r7, 0
	ldrsh r2, [r2, r7]
	adds r1, r2
	mov r7, r8
	lsls r2, r7, 16
	asrs r2, 16
	subs r1, r2
	movs r7, 0x2
	ldrsh r2, [r3, r7]
	ldr r3, _08011094
	adds r3, r4
	movs r4, 0
	ldrsh r3, [r3, r4]
	adds r2, r3
	mov r7, r8
	asrs r3, r7, 16
	subs r2, r3
	movs r3, 0
	str r3, [sp]
	add r3, sp, 0x8
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl DoAxFrame_800558C
_08011062:
	adds r6, 0x3C
	ldr r4, [sp, 0x14]
	adds r4, 0x3C
	str r4, [sp, 0x14]
	adds r5, 0x1
	cmp r5, 0x7
	ble _08010FEC
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011080: .4byte 0x0000f3ff
_08011084: .4byte gUnknown_203B0E4
_08011088: .4byte 0x00004dd4
_0801108C: .4byte 0x00004c10
_08011090: .4byte 0x00004dd8
_08011094: .4byte 0x00004dda
_08011098: .4byte 0x00004dd0
_0801109C: .4byte 0x00004018
_080110A0: .4byte 0x00004014
_080110A4: .4byte 0x00004a30
_080110A8: .4byte gRealInputs
_080110AC: .4byte gUnknown_80D40C4
	thumb_func_end sub_8010F28

	thumb_func_start sub_80110B0
sub_80110B0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, _08011150
	ldr r1, [r0]
	ldr r2, _08011154
	adds r1, r2
	ldrh r1, [r1]
	lsls r1, 16
	asrs r6, r1, 19
	adds r2, r6, 0
	movs r3, 0
	mov r10, r0
	movs r0, 0x1F
	mov r9, r0
_080110D4:
	mov r1, r10
	ldr r0, [r1]
	ldr r1, _08011158
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 16
	asrs r4, r0, 19
	lsls r1, r2, 7
	adds r2, 0x1
	mov r12, r2
	adds r3, 0x1
	mov r8, r3
	movs r7, 0x1E
	lsls r0, r4, 1
	adds r5, r0, r1
_080110F2:
	mov r2, r9
	ands r4, r2
	ands r6, r2
	lsls r2, r4, 1
	lsls r0, r6, 6
	adds r2, r0
	ldr r3, _0801115C
	adds r3, r2, r3
	str r3, [sp]
	mov r0, r10
	ldr r1, [r0]
	ldr r3, _08011160
	adds r0, r1, r3
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, [sp]
	strh r0, [r3]
	ldr r0, _08011164
	adds r2, r0
	adds r1, 0x14
	adds r1, r5
	ldrh r0, [r1]
	strh r0, [r2]
	adds r5, 0x2
	adds r4, 0x1
	subs r7, 0x1
	cmp r7, 0
	bge _080110F2
	mov r2, r12
	adds r6, 0x1
	mov r3, r8
	cmp r3, 0x14
	ble _080110D4
	movs r0, 0x2
	bl sub_80098F8
	movs r0, 0x3
	bl sub_80098F8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011150: .4byte gUnknown_203B0E4
_08011154: .4byte 0x00004dd6
_08011158: .4byte 0x00004dd4
_0801115C: .4byte gUnknown_202C038
_08011160: .4byte 0x00002014
_08011164: .4byte gUnknown_202C838
	thumb_func_end sub_80110B0

	thumb_func_start sub_8011168
sub_8011168:
	push {r4,r5,lr}
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r3, _080111B0
	ldr r1, [r3]
	ldr r2, _080111B4
	adds r0, r1, r2
	movs r2, 0
	str r2, [r0]
	ldr r4, _080111B8
	adds r0, r1, r4
	str r2, [r0]
	adds r4, 0x4
	adds r0, r1, r4
	str r2, [r0]
	ldr r0, _080111BC
	adds r1, r0
	str r2, [r1]
	adds r5, r3, 0
	ldr r4, _080111C0
	movs r3, 0
	movs r1, 0x7
_0801119A:
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, r4
	strh r3, [r0]
	adds r2, 0x3C
	subs r1, 0x1
	cmp r1, 0
	bge _0801119A
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080111B0: .4byte gUnknown_203B0E4
_080111B4: .4byte 0x00004ddc
_080111B8: .4byte 0x00004de0
_080111BC: .4byte 0x00004de8
_080111C0: .4byte 0x00004a30
	thumb_func_end sub_8011168

	thumb_func_start sub_80111C4
sub_80111C4:
	push {r4-r6,lr}
	movs r3, 0
	ldr r6, _08011238
	ldr r0, [r6]
	ldr r2, _0801123C
	adds r1, r0, r2
	ldr r2, [r1]
	cmp r2, 0x1E
	bgt _0801122E
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	adds r0, r2, 0x1
	str r0, [r1]
	cmp r0, 0x1E
	ble _080111E6
	movs r0, 0x1F
	str r0, [r1]
_080111E6:
	movs r4, 0
_080111E8:
	ldr r0, [r6]
	ldr r1, _0801123C
	adds r0, r1
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xDF
	ble _080111E8
	ldr r0, _08011238
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	ldr r5, [r0, 0x4]
	movs r4, 0
_0801120C:
	movs r2, 0x80
	lsls r2, 1
	adds r0, r4, r2
	ldr r1, _08011238
	ldr r1, [r1]
	ldr r2, _0801123C
	adds r1, r2
	ldr r2, [r1]
	adds r1, r5, 0
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	adds r4, 0x1
	cmp r4, 0xEF
	ble _0801120C
	movs r3, 0x1
_0801122E:
	adds r0, r3, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08011238: .4byte gUnknown_203B0E4
_0801123C: .4byte 0x00004dcc
	thumb_func_end sub_80111C4

	thumb_func_start sub_8011240
sub_8011240:
	push {r4-r6,lr}
	ldr r2, _08011264
	ldr r0, [r2]
	ldr r1, _08011268
	adds r3, r0, r1
	movs r4, 0
	ldrsh r1, [r3, r4]
	ldr r5, _0801126C
	adds r4, r0, r5
	movs r6, 0
	ldrsh r0, [r4, r6]
	subs r1, r0
	adds r5, r2, 0
	cmp r1, 0x2F
	bgt _08011270
	ldrh r0, [r3]
	subs r0, 0x30
	b _08011278
	.align 2, 0
_08011264: .4byte gUnknown_203B0E4
_08011268: .4byte 0x00004dd8
_0801126C: .4byte 0x00004dd4
_08011270:
	cmp r1, 0xC0
	ble _0801127A
	ldrh r0, [r3]
	subs r0, 0xC0
_08011278:
	strh r0, [r4]
_0801127A:
	ldr r0, [r5]
	ldr r1, _08011298
	adds r3, r0, r1
	movs r2, 0
	ldrsh r1, [r3, r2]
	ldr r4, _0801129C
	adds r2, r0, r4
	movs r6, 0
	ldrsh r0, [r2, r6]
	subs r1, r0
	cmp r1, 0x2F
	bgt _080112A0
	ldrh r0, [r3]
	subs r0, 0x30
	b _080112A8
	.align 2, 0
_08011298: .4byte 0x00004dda
_0801129C: .4byte 0x00004dd6
_080112A0:
	cmp r1, 0x70
	ble _080112AA
	ldrh r0, [r3]
	subs r0, 0x70
_080112A8:
	strh r0, [r2]
_080112AA:
	adds r3, r5, 0
	ldr r0, [r3]
	ldr r4, _080112F8
	adds r1, r0, r4
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bge _080112BE
	movs r0, 0
	strh r0, [r1]
_080112BE:
	ldr r0, [r3]
	ldr r2, _080112FC
	adds r1, r0, r2
	movs r6, 0
	ldrsh r0, [r1, r6]
	cmp r0, 0
	bge _080112D0
	movs r0, 0
	strh r0, [r1]
_080112D0:
	ldr r0, [r3]
	adds r1, r0, r4
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0xEF
	ble _080112E0
	movs r0, 0xEF
	strh r0, [r1]
_080112E0:
	ldr r0, [r5]
	adds r2, r0, r2
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0x97
	ble _080112F0
	movs r0, 0x97
	strh r0, [r2]
_080112F0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080112F8: .4byte 0x00004dd4
_080112FC: .4byte 0x00004dd6
	thumb_func_end sub_8011240

	thumb_func_start sub_8011300
sub_8011300:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	ldr r0, _08011388
	ldr r2, [r0]
	ldr r1, _0801138C
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	ldr r3, _08011390
	adds r0, r3
	adds r2, r0
	mov r9, r2
	movs r4, 0
	ldr r0, _08011394
	mov r8, r0
	movs r7, 0
	mov r6, r8
	movs r5, 0
_0801132E:
	ldr r0, _08011388
	ldr r2, [r0]
	adds r0, r5, r2
	add r0, r8
	strh r7, [r0]
	lsls r1, r4, 1
	mov r0, r9
	adds r0, 0x2
	adds r1, r0, r1
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	blt _08011370
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 4
	ldr r0, _08011390
	adds r1, r0
	adds r1, r2, r1
	ldrb r0, [r1]
	cmp r0, 0
	beq _08011370
	adds r0, r2, r6
	ldr r1, [r2, 0x8]
	adds r2, r4, 0x4
	movs r3, 0x40
	str r3, [sp]
	str r7, [sp, 0x4]
	movs r3, 0x1
	str r3, [sp, 0x8]
	movs r3, 0
	bl sub_80053AC
_08011370:
	adds r6, 0x3C
	adds r5, 0x3C
	adds r4, 0x1
	cmp r4, 0x7
	ble _0801132E
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011388: .4byte gUnknown_203B0E4
_0801138C: .4byte 0x00004a18
_08011390: .4byte 0x00004018
_08011394: .4byte 0x00004a30
	thumb_func_end sub_8011300

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
	bl sub_800641C
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
	bl xxx_format_and_draw
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
	bl sub_800641C
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
	bl xxx_format_and_draw
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
	bl xxx_format_and_draw
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
_08011634: .4byte gUnknown_202DE30
_08011638: .4byte gUnknown_202DE58
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
	bl xxx_format_and_draw
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
