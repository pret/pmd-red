    #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80210C8
sub_80210C8:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _080210E0
	cmp r0, 0x3
	bhi _080210E0
	bl sub_801F8D0
	movs r0, 0x1F
	bl sub_801FDA8
_080210E0:
	pop {r0}
	bx r0
	thumb_func_end sub_80210C8

	thumb_func_start sub_80210E4
sub_80210E4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802112A
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08021108
	cmp r0, 0x10
	bgt _08021102
	cmp r0, 0x1
	beq _08021124
	b _0802112A
_08021102:
	cmp r0, 0x11
	beq _08021124
	b _0802112A
_08021108:
	ldr r0, _08021120
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x18]
	bl RemoveLinkSequenceFromMoves8
	movs r0, 0x23
	bl sub_801FDA8
	b _0802112A
	.align 2, 0
_08021120: .4byte gUnknown_203B27C
_08021124:
	movs r0, 0x1F
	bl sub_801FDA8
_0802112A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80210E4

	thumb_func_start sub_8021130
sub_8021130:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08021148
	ldr r0, _08021150
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_08021148:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021150: .4byte gUnknown_203B27C
	thumb_func_end sub_8021130

	thumb_func_start sub_8021154
sub_8021154:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0x4
	bne _0802116C
	ldr r0, _08021174
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_0802116C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021174: .4byte gUnknown_203B27C
	thumb_func_end sub_8021154

	thumb_func_start sub_8021178
sub_8021178:
	push {lr}
	mov r12, r4
	ldr r4, _08021198
	add sp, r4
	mov r4, r12
	ldr r0, _0802119C
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	mov r0, sp
	bl sub_808E218
	cmp r0, 0
	beq _080211A0
	movs r0, 0
	b _080211A2
	.align 2, 0
_08021198: .4byte 0xfffffcc0
_0802119C: .4byte gUnknown_203B27C
_080211A0:
	movs r0, 0x1
_080211A2:
	movs r3, 0xD0
	lsls r3, 2
	add sp, r3
	pop {r1}
	bx r1
	thumb_func_end sub_8021178

	thumb_func_start sub_80211AC
sub_80211AC:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _080211C0
	movs r0, 0
	b _08021258
_080211C0:
	ldr r5, _08021260
	movs r0, 0xE0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r4, [r0, 0x3C]
	str r6, [r0, 0x74]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x7C
	adds r1, r0, r1
	str r1, [r0, 0x78]
	adds r0, 0x7C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x74]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x7C
	ldr r0, _08021264
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x78]
	adds r0, 0xDC
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x40
	bl sub_8021664
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, _08021268
	ldr r2, [r5]
	ldr r1, [r0]
	ldr r0, [r2, 0x3C]
	cmp r1, r0
	bne _0802124E
	ldr r0, _0802126C
	ldrh r1, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	strh r1, [r0]
	ldr r0, _08021270
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x5E
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x40
	bl sub_8013984
_0802124E:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021258:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08021260: .4byte gUnknown_203B280
_08021264: .4byte gUnknown_80DC47C
_08021268: .4byte gUnknown_203B284
_0802126C: .4byte gUnknown_203B288
_08021270: .4byte gUnknown_203B28A
	thumb_func_end sub_80211AC

	thumb_func_start sub_8021274
sub_8021274:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08021290
	ldr r0, _0802128C
	ldr r0, [r0]
	adds r0, 0x40
	bl sub_8013660
	movs r0, 0
	b _08021326
	.align 2, 0
_0802128C: .4byte gUnknown_203B280
_08021290:
	ldr r4, _080212A8
	ldr r0, [r4]
	adds r0, 0x40
	bl GetKeyPress
	cmp r0, 0x2
	beq _080212B2
	cmp r0, 0x2
	bgt _080212AC
	cmp r0, 0x1
	beq _080212BC
	b _08021300
	.align 2, 0
_080212A8: .4byte gUnknown_203B280
_080212AC:
	cmp r0, 0x4
	beq _080212F6
	b _08021300
_080212B2:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08021326
_080212BC:
	ldr r0, [r4]
	ldr r0, [r0, 0x3C]
	cmp r0, 0x2
	bne _080212EC
	bl sub_802132C
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaPrice
	ldr r1, _080212E8
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _080212EC
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _080212F2
	.align 2, 0
_080212E8: .4byte gTeamInventory_203B460
_080212EC:
	movs r0, 0
	bl PlayMenuSoundEffect
_080212F2:
	movs r0, 0x3
	b _08021326
_080212F6:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _08021326
_08021300:
	ldr r0, _08021318
	ldr r0, [r0]
	adds r0, 0x40
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802131C
	movs r0, 0
	b _08021326
	.align 2, 0
_08021318: .4byte gUnknown_203B280
_0802131C:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021326:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8021274

	thumb_func_start sub_802132C
sub_802132C:
	ldr r0, _08021350
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	adds r0, r2, r0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08021350: .4byte gUnknown_203B280
	thumb_func_end sub_802132C

	thumb_func_start sub_8021354
sub_8021354:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802139C
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8021664
	adds r1, r0, 0
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x62
	strh r1, [r2]
	adds r0, 0x40
	bl sub_8013984
	bl sub_8021410
	bl sub_8021494
	cmp r4, 0
	beq _08021396
	ldr r0, [r5]
	adds r0, 0x40
	bl AddMenuCursorSprite
_08021396:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802139C: .4byte gUnknown_203B280
	thumb_func_end sub_8021354

	thumb_func_start sub_80213A0
sub_80213A0:
	push {r4,r5,lr}
	ldr r4, _080213FC
	ldr r2, [r4]
	cmp r2, 0
	beq _080213F4
	ldr r1, _08021400
	ldr r0, [r2, 0x3C]
	str r0, [r1]
	ldr r1, _08021404
	adds r0, r2, 0
	adds r0, 0x58
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08021408
	adds r0, r2, 0
	adds r0, 0x5E
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r2, 0x74]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7C
	ldr r0, _0802140C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080213F4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080213FC: .4byte gUnknown_203B280
_08021400: .4byte gUnknown_203B284
_08021404: .4byte gUnknown_203B288
_08021408: .4byte gUnknown_203B28A
_0802140C: .4byte gUnknown_80DC464
	thumb_func_end sub_80213A0

	thumb_func_start sub_8021410
sub_8021410:
	push {r4,lr}
	ldr r4, _08021490
	ldr r0, [r4]
	adds r0, 0xDC
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDD
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xDE
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDF
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x74]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x8A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x74]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x8C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021490: .4byte gUnknown_203B280
	thumb_func_end sub_8021410

	thumb_func_start sub_8021494
sub_8021494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA8
	ldr r4, _08021568
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r2, _0802156C
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0xDE
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0x5E
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	ldr r1, [r3, 0x74]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r0, 0
	mov r9, r0
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	blt _080214FC
	b _08021646
_080214FC:
	mov r8, r4
	add r2, sp, 0x58
	mov r10, r2
_08021502:
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r5, 0
	ldrsh r1, [r0, r5]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	add r0, r9
	adds r0, r2, r0
	ldrb r5, [r0]
	adds r7, r5, 0
	ldr r6, [r2, 0x3C]
	cmp r6, 0x2
	bne _0802159C
	add r0, sp, 0x8
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8092578
	adds r0, r5, 0
	bl GetFriendAreaPrice
	ldr r1, _08021570
	ldr r1, [r1]
	movs r5, 0x98
	lsls r5, 2
	adds r1, r5
	ldr r1, [r1]
	cmp r0, r1
	bgt _08021574
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r2, r8
	ldr r0, [r2]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021568: .4byte gUnknown_203B280
_0802156C: .4byte gUnknown_80DC494
_08021570: .4byte gTeamInventory_203B460
_08021574:
	mov r0, r10
	ldr r1, _08021598
	add r2, sp, 0x8
	bl sprintfStatic
	mov r3, r8
	ldr r0, [r3]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	b _080215FE
	.align 2, 0
_08021598: .4byte gUnknown_80DC4A4
_0802159C:
	cmp r6, 0
	bne _0802160C
	ldr r0, _080215D4
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080215D8
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x74]
	str r6, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_080215D4: .4byte gFriendAreas
_080215D8:
	adds r0, r5, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r0, r10
	ldr r1, _08021608
	bl sprintfStatic
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [r0, 0x74]
	str r6, [sp]
_080215FE:
	movs r0, 0x8
	mov r2, r10
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021608: .4byte gUnknown_80DC4AC
_0802160C:
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r7, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
_08021632:
	movs r0, 0x1
	add r9, r0
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x5A
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r9, r0
	bge _08021646
	b _08021502
_08021646:
	ldr r0, _08021660
	ldr r0, [r0]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	add sp, 0xA8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021660: .4byte gUnknown_203B280
	thumb_func_end sub_8021494

    .align  2,0
