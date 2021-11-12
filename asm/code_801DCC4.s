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

        .align 2,0
