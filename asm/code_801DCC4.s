        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801E198
sub_801E198:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0801E210
	movs r0, 0xAC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	stm r0!, {r5}
	bl sub_801317C
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x44]
	adds r0, r1, 0
	adds r0, 0x4C
	str r0, [r1, 0x48]
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x44]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x4C
	ldr r0, _0801E214
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r4]
	ldr r0, [r0, 0x48]
	movs r1, 0x1
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x10
	ldr r3, [r1, 0x44]
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8013818
	bl nullsub_38
	bl CreateOptionsMenu
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801E210: .4byte gUnknown_203B260
_0801E214: .4byte gUnknown_80DC03C
	thumb_func_end sub_801E198

	thumb_func_start sub_801E218
sub_801E218:
	push {r4,lr}
	movs r4, 0
	bl sub_8012AE8
	cmp r0, 0x2
	beq _0801E238
	cmp r0, 0x2
	bgt _0801E22E
	cmp r0, 0x1
	beq _0801E242
	b _0801E294
_0801E22E:
	cmp r0, 0x9
	beq _0801E24C
	cmp r0, 0xA
	beq _0801E26C
	b _0801E294
_0801E238:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801E2BE
_0801E242:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801E2BE
_0801E24C:
	ldr r0, _0801E264
	ldr r1, [r0]
	movs r2, 0x28
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0801E294
	ldr r1, [r1]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _0801E268
	movs r0, 0x2
	b _0801E28A
	.align 2, 0
_0801E264: .4byte gUnknown_203B260
_0801E268:
	subs r0, 0x1
	b _0801E28A
_0801E26C:
	ldr r0, _0801E284
	ldr r1, [r0]
	movs r2, 0x28
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0801E294
	ldr r1, [r1]
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	bls _0801E288
	strb r4, [r1, 0x8]
	b _0801E28C
	.align 2, 0
_0801E284: .4byte gUnknown_203B260
_0801E288:
	adds r0, 0x1
_0801E28A:
	strb r0, [r1, 0x8]
_0801E28C:
	movs r0, 0x3
	bl PlayMenuSoundEffect
	movs r4, 0x1
_0801E294:
	ldr r0, _0801E2B8
	ldr r0, [r0]
	adds r0, 0x10
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801E2AA
	cmp r4, 0x1
	bne _0801E2BC
_0801E2AA:
	bl nullsub_38
	bl CreateOptionsMenu
	movs r0, 0x1
	b _0801E2BE
	.align 2, 0
_0801E2B8: .4byte gUnknown_203B260
_0801E2BC:
	movs r0, 0
_0801E2BE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801E218

	thumb_func_start sub_801E2C4
sub_801E2C4:
	push {r4,r5,lr}
	ldr r4, _0801E304
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E2FE
	ldr r0, [r2, 0x44]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4C
	ldr r0, _0801E308
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E2FE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E304: .4byte gUnknown_203B260
_0801E308: .4byte gUnknown_80DC020
	thumb_func_end sub_801E2C4

	thumb_func_start nullsub_38
nullsub_38:
	bx lr
	thumb_func_end nullsub_38

	thumb_func_start CreateOptionsMenu
CreateOptionsMenu:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, _0801E368
	ldr r0, [r5]
	ldr r0, [r0, 0x44]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x44]
	bl sub_80073B8
	ldr r2, _0801E36C
	ldr r0, [r5]
	ldr r3, [r0, 0x44]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	adds r0, 0x10
	movs r1, 0
	bl sub_8013800
	adds r6, r0, 0
	ldr r2, _0801E370
	ldr r0, [r5]
	ldr r3, [r0, 0x44]
	str r4, [sp]
	movs r0, 0x8
	adds r1, r6, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1
	beq _0801E384
	cmp r0, 0x1
	bgt _0801E374
	cmp r0, 0
	beq _0801E37A
	b _0801E3D6
	.align 2, 0
_0801E368: .4byte gUnknown_203B260
_0801E36C: .4byte gWindowBGTitle
_0801E370: .4byte gUnknown_80DC064
_0801E374:
	cmp r0, 0x2
	beq _0801E3B0
	b _0801E3D6
_0801E37A:
	ldr r0, _0801E380
	b _0801E386
	.align 2, 0
_0801E380: .4byte gWindowBGBlueString
_0801E384:
	ldr r0, _0801E3AC
_0801E386:
	bl sub_8008ED0
	adds r4, r0, 0
	ldr r1, [r5]
	ldr r0, [r1, 0x44]
	ldr r1, [r1]
	ldrb r2, [r1, 0x8]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, 0x50
	adds r2, r6, 0
	adds r2, 0xA
	movs r3, 0x7
	str r3, [sp]
	adds r3, r4, 0
	bl sub_80078A4
	b _0801E3D6
	.align 2, 0
_0801E3AC: .4byte gWindowBGRedString
_0801E3B0:
	ldr r0, _0801E3E8
	bl sub_8008ED0
	adds r4, r0, 0
	ldr r1, [r5]
	ldr r0, [r1, 0x44]
	ldr r1, [r1]
	ldrb r2, [r1, 0x8]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, 0x50
	adds r2, r6, 0
	adds r2, 0xA
	movs r3, 0x7
	str r3, [sp]
	adds r3, r4, 0
	bl sub_80078A4
_0801E3D6:
	ldr r0, _0801E3EC
	ldr r0, [r0]
	ldr r0, [r0, 0x44]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E3E8: .4byte gWindowBGGreenString
_0801E3EC: .4byte gUnknown_203B260
	thumb_func_end CreateOptionsMenu

	thumb_func_start sub_801E3F0
sub_801E3F0:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0801E46C
	ldr r0, [r4]
	cmp r0, 0
	bne _0801E406
	movs r0, 0x9C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0801E406:
	ldr r0, [r4]
	str r5, [r0, 0x34]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801E470
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r4]
	ldr r0, [r0, 0x38]
	movs r1, 0xA
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x5
	movs r2, 0xA
	adds r3, r5, 0
	bl sub_8013818
	bl sub_801E594
	bl sub_801E5E8
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E46C: .4byte gUnknown_203B264
_0801E470: .4byte gUnknown_80DC0BC
	thumb_func_end sub_801E3F0

	thumb_func_start sub_801E474
sub_801E474:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801E48C
	ldr r0, _0801E488
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0801E4EE
	.align 2, 0
_0801E488: .4byte gUnknown_203B264
_0801E48C:
	ldr r0, _0801E4A4
	ldr r0, [r0]
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801E4AE
	cmp r0, 0x2
	bgt _0801E4A8
	cmp r0, 0x1
	beq _0801E4B8
	b _0801E4CC
	.align 2, 0
_0801E4A4: .4byte gUnknown_203B264
_0801E4A8:
	cmp r0, 0x4
	beq _0801E4C2
	b _0801E4CC
_0801E4AE:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801E4EE
_0801E4B8:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801E4EE
_0801E4C2:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801E4EE
_0801E4CC:
	ldr r0, _0801E4E0
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801E4E4
	movs r0, 0
	b _0801E4EE
	.align 2, 0
_0801E4E0: .4byte gUnknown_203B264
_0801E4E4:
	bl sub_801E594
	bl sub_801E5E8
	movs r0, 0x1
_0801E4EE:
	pop {r1}
	bx r1
	thumb_func_end sub_801E474

	thumb_func_start sub_801E4F4
sub_801E4F4:
	ldr r0, _0801E50C
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r2, 0x18
	ldrsh r1, [r1, r2]
	adds r0, r1
	bx lr
	.align 2, 0
_0801E50C: .4byte gUnknown_203B264
	thumb_func_end sub_801E4F4

	thumb_func_start sub_801E510
sub_801E510:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801E548
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	bl sub_8013984
	bl sub_801E594
	bl sub_801E5E8
	cmp r4, 0
	beq _0801E542
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801E542:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E548: .4byte gUnknown_203B264
	thumb_func_end sub_801E510

	thumb_func_start sub_801E54C
sub_801E54C:
	push {r4,r5,lr}
	ldr r4, _0801E58C
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E586
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801E590
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E586:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E58C: .4byte gUnknown_203B264
_0801E590: .4byte gUnknown_80DC0A0
	thumb_func_end sub_801E54C

	thumb_func_start sub_801E594
sub_801E594:
	push {r4,lr}
	ldr r4, _0801E5E4
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E5E4: .4byte gUnknown_203B264
	thumb_func_end sub_801E594

	thumb_func_start sub_801E5E8
sub_801E5E8:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r4, _0801E64C
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0801E650
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	bl xxx_call_draw_string
	movs r5, 0
	adds r6, r4, 0
	ldr r4, _0801E654
_0801E616:
	ldr r0, [r6]
	adds r1, r5, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4]
	ldr r0, [r6]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	bl xxx_call_draw_string
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x4
	ble _0801E616
	ldr r0, _0801E64C
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E64C: .4byte gUnknown_203B264
_0801E650: .4byte gUnknown_80DC0D4
_0801E654: .4byte gUnknown_80DAA98
	thumb_func_end sub_801E5E8

	thumb_func_start sub_801E658
sub_801E658:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0801E6C4
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x3C
	str r1, [r0, 0x38]
	adds r0, r1, 0
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801E6C8
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r1, 0x5
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	strh r5, [r0, 0x1E]
	bl sub_801E714
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E6C4: .4byte gUnknown_203B268
_0801E6C8: .4byte gUnknown_80DC0FC
	thumb_func_end sub_801E658

	thumb_func_start sub_801E6CC
sub_801E6CC:
	push {r4,lr}
	ldr r4, _0801E6E8
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0801E6EC
	cmp r0, 0x2
	bne _0801E6F6
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801E70C
	.align 2, 0
_0801E6E8: .4byte gUnknown_203B268
_0801E6EC:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801E70C
_0801E6F6:
	ldr r0, [r4]
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	bne _0801E706
	movs r0, 0
	b _0801E70C
_0801E706:
	bl sub_801E714
	movs r0, 0x1
_0801E70C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801E6CC

	thumb_func_start sub_801E714
sub_801E714:
	push {lr}
	bl sub_801E76C
	bl sub_801E7AC
	pop {r0}
	bx r0
	thumb_func_end sub_801E714

	thumb_func_start sub_801E724
sub_801E724:
	push {r4,r5,lr}
	ldr r4, _0801E764
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E75E
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801E768
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E75E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E764: .4byte gUnknown_203B268
_0801E768: .4byte gUnknown_80DC0E4
	thumb_func_end sub_801E724

	thumb_func_start sub_801E76C
sub_801E76C:
	push {r4,lr}
	ldr r4, _0801E7A8
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xF
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E7A8: .4byte gUnknown_203B268
	thumb_func_end sub_801E76C

	thumb_func_start sub_801E7AC
sub_801E7AC:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, _0801E804
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r3, [r5]
	movs r0, 0x1E
	ldrsh r1, [r3, r0]
	lsls r1, 3
	adds r0, r1, 0
	adds r0, 0x10
	ldr r4, _0801E808
	adds r1, r4
	ldr r2, [r1]
	ldr r3, [r3, 0x34]
	movs r6, 0
	str r6, [sp]
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r5]
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r4, 0x4
	adds r0, r4
	ldr r2, [r0]
	ldr r3, [r1, 0x34]
	str r6, [sp]
	movs r0, 0xA
	movs r1, 0x14
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E804: .4byte gUnknown_203B268
_0801E808: .4byte gUnknown_80DAA98
	thumb_func_end sub_801E7AC

        .align 2,0
