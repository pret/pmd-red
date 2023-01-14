        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start sub_801EE10
sub_801EE10:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r2
	adds r4, r3, 0
	ldr r0, [sp, 0x20]
	mov r8, r0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0801EF28
	movs r0, 0xBC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r2, 0
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	movs r1, 0x1
	strb r1, [r0, 0x5]
	ldr r0, [r5]
	strb r1, [r0, 0x6]
	ldr r0, [r5]
	strb r1, [r0, 0x7]
	ldr r0, [r5]
	str r6, [r0]
	cmp r6, 0x1
	bls _0801EE5E
	cmp r6, 0x3
	bhi _0801EE5E
	strb r2, [r0, 0x5]
	ldr r0, [r5]
	strb r2, [r0, 0x6]
	ldr r0, [r5]
	strb r2, [r0, 0x7]
_0801EE5E:
	ldr r4, _0801EF28
	ldr r3, [r4]
	ldr r2, _0801EF2C
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	str r0, [r3, 0x8]
	ldrb r0, [r0, 0x2]
	strb r0, [r3, 0xC]
	ldr r0, [r4]
	mov r1, r9
	str r1, [r0, 0x10]
	adds r0, 0xB8
	ldr r1, [sp, 0x1C]
	str r1, [r0]
	bl sub_801F3F8
	adds r5, r0, 0
	adds r6, r5, 0
	cmp r5, 0x4
	bge _0801EE8E
	movs r6, 0x4
_0801EE8E:
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8006518
	ldr r1, [r4]
	mov r2, r8
	str r2, [r1, 0x50]
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 3
	adds r1, r0
	adds r1, 0x58
	ldr r0, _0801EF30
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r0, [r4]
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801EED8
	mov r0, r8
	bl sub_8006544
	ldr r1, [r4]
	str r0, [r1, 0x54]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r1, r2
	adds r1, 0x58
	ldr r0, _0801EF34
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
_0801EED8:
	ldr r0, [r4]
	ldr r2, [r0, 0x50]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, 0x58
	adds r0, r1
	adds r1, r6, 0
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, 0x1C
	adds r1, r5, 0
	adds r2, r5, 0
	mov r3, r8
	bl sub_8013818
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	bl sub_8013780
	movs r0, 0x1
	bl sub_801F280
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801EF28: .4byte gUnknown_203B270
_0801EF2C: .4byte gRecruitedPokemonRef
_0801EF30: .4byte gUnknown_80DC25C
_0801EF34: .4byte gUnknown_80DC274
	thumb_func_end sub_801EE10

	thumb_func_start sub_801EF38
sub_801EF38:
	push {r4-r7,lr}
	lsls r0, 24
	movs r7, 0
	cmp r0, 0
	bne _0801EF54
	ldr r0, _0801EF50
	ldr r0, [r0]
	adds r0, 0x1C
	bl sub_8013660
	b _0801F18C
	.align 2, 0
_0801EF50: .4byte gUnknown_203B270
_0801EF54:
	ldr r0, _0801EF70
	ldr r0, [r0]
	adds r0, 0x1C
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0xC
	bls _0801EF66
	b _0801F12E
_0801EF66:
	lsls r0, 2
	ldr r1, _0801EF74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EF70: .4byte gUnknown_203B270
_0801EF74: .4byte _0801EF78
	.align 2, 0
_0801EF78:
	.4byte _0801EFB6
	.4byte _0801EFAC
	.4byte _0801F0E4
	.4byte _0801EFC0
	.4byte _0801F12E
	.4byte _0801F12E
	.4byte _0801EFE4
	.4byte _0801EFCA
	.4byte _0801F12E
	.4byte _0801F12E
	.4byte _0801F074
	.4byte _0801F04C
	.4byte _0801F018
_0801EFAC:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801F18E
_0801EFB6:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801F18E
_0801EFC0:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801F18E
_0801EFCA:
	ldr r5, _0801EFE0
	ldr r0, [r5]
	movs r1, 0x34
	ldrsh r6, [r0, r1]
	adds r4, r0, 0
	adds r4, 0x1C
	ldr r0, [r0, 0x10]
	adds r1, r6, 0
	bl sub_8092E54
	b _0801EFF8
	.align 2, 0
_0801EFE0: .4byte gUnknown_203B270
_0801EFE4:
	ldr r5, _0801F014
	ldr r0, [r5]
	movs r1, 0x34
	ldrsh r6, [r0, r1]
	adds r4, r0, 0
	adds r4, 0x1C
	ldr r0, [r0, 0x10]
	adds r1, r6, 0
	bl sub_8092EEC
_0801EFF8:
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8013780
	ldr r0, [r5]
	movs r2, 0x34
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bne _0801F00C
	b _0801F12E
_0801F00C:
	movs r0, 0x3
	bl PlayMenuSoundEffect
	b _0801F12E
	.align 2, 0
_0801F014: .4byte gUnknown_203B270
_0801F018:
	ldr r0, _0801F048
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	adds r5, r0, 0
	cmp r1, 0
	bne _0801F026
	b _0801F12E
_0801F026:
	movs r0, 0x34
	ldrsh r4, [r2, r0]
	ldr r0, [r2, 0x10]
	adds r1, r4, 0
	bl sub_809309C
_0801F032:
	ldr r1, [r5]
	strh r0, [r1, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	beq _0801F06C
	movs r0, 0x3
	bl PlayMenuSoundEffect
	b _0801F182
	.align 2, 0
_0801F048: .4byte gUnknown_203B270
_0801F04C:
	ldr r0, _0801F068
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	adds r5, r0, 0
	cmp r1, 0
	beq _0801F12E
	movs r1, 0x34
	ldrsh r4, [r2, r1]
	ldr r0, [r2, 0x10]
	adds r1, r4, 0
	bl sub_809324C
	b _0801F032
	.align 2, 0
_0801F068: .4byte gUnknown_203B270
_0801F06C:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801F182
_0801F074:
	ldr r0, _0801F0C8
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	adds r5, r0, 0
	cmp r1, 0
	beq _0801F12E
	ldr r0, _0801F0CC
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x95
	ble _0801F0D0
	movs r1, 0x34
	ldrsh r0, [r2, r1]
	ldr r1, [r2, 0x10]
	bl sub_8093318
	lsls r0, 24
	cmp r0, 0
	beq _0801F0D0
	ldr r1, [r5]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093400
	movs r0, 0x6
	bl PlayMenuSoundEffect
	movs r7, 0x1
	ldr r1, [r5]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _0801F12E
	strb r7, [r1, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySound
	b _0801F12E
	.align 2, 0
_0801F0C8: .4byte gUnknown_203B270
_0801F0CC: .4byte gTeamInventory_203B460
_0801F0D0:
	ldr r0, _0801F0E0
	ldr r1, [r0]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093468
	b _0801F0FE
	.align 2, 0
_0801F0E0: .4byte gUnknown_203B270
_0801F0E4:
	ldr r0, _0801F10C
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _0801F12E
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0801F110
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_80934DC
_0801F0FE:
	lsls r0, 24
	cmp r0, 0
	bne _0801F120
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801F12E
	.align 2, 0
_0801F10C: .4byte gUnknown_203B270
_0801F110:
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093544
	lsls r0, 24
	cmp r0, 0
	beq _0801F128
_0801F120:
	movs r0, 0x6
	bl PlayMenuSoundEffect
	b _0801F182
_0801F128:
	movs r0, 0x2
	bl PlayMenuSoundEffect
_0801F12E:
	cmp r7, 0
	bne _0801F182
	movs r3, 0
	ldr r5, _0801F160
	movs r4, 0x1
_0801F138:
	ldr r2, [r5]
	lsls r0, r3, 3
	ldr r1, [r2, 0x10]
	adds r1, r0
	ldrb r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0801F16C
	movs r0, 0x2
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0801F164
	adds r0, r2, 0
	adds r0, 0x14
	adds r0, r3
	strb r4, [r0]
	b _0801F16C
	.align 2, 0
_0801F160: .4byte gUnknown_203B270
_0801F164:
	adds r0, r2, 0
	adds r0, 0x14
	adds r0, r3
	strb r1, [r0]
_0801F16C:
	adds r3, 0x1
	cmp r3, 0x7
	ble _0801F138
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x1C
	adds r1, 0x14
	bl AddMenuCursorSprite_
	cmp r7, 0
	beq _0801F18C
_0801F182:
	movs r0, 0x1
	bl sub_801F280
	movs r0, 0x1
	b _0801F18E
_0801F18C:
	movs r0, 0
_0801F18E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801EF38

	thumb_func_start sub_801F194
sub_801F194:
	ldr r0, _0801F1A0
	ldr r0, [r0]
	movs r1, 0x34
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0801F1A0: .4byte gUnknown_203B270
	thumb_func_end sub_801F194

	thumb_func_start sub_801F1A4
sub_801F1A4:
	ldr r0, _0801F1AC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0801F1AC: .4byte gUnknown_203B270
	thumb_func_end sub_801F1A4

	thumb_func_start sub_801F1B0
sub_801F1B0:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r4, _0801F210
	ldr r2, [r4]
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	bne _0801F1C6
	strb r1, [r2, 0x4]
_0801F1C6:
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_801F3F8
	adds r1, r0, 0
	ldr r0, [r4]
	strh r1, [r0, 0x3E]
	adds r0, 0x1C
	bl sub_8013984
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	movs r2, 0x34
	ldrsh r1, [r1, r2]
	bl sub_8092F4C
	ldr r1, [r4]
	strh r0, [r1, 0x34]
	movs r0, 0x1
	bl sub_801F280
	cmp r5, 0
	beq _0801F208
	ldr r0, [r4]
	adds r0, 0x1C
	bl AddMenuCursorSprite
_0801F208:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F210: .4byte gUnknown_203B270
	thumb_func_end sub_801F1B0

	thumb_func_start sub_801F214
sub_801F214:
	push {r4-r6,lr}
	ldr r4, _0801F278
	ldr r2, [r4]
	cmp r2, 0
	beq _0801F272
	ldr r0, [r2, 0x50]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	ldr r3, _0801F27C
	adds r1, 0x58
	adds r0, r3, 0
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801F258
	ldr r0, [r2, 0x54]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x58
	adds r0, r3, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
_0801F258:
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801F272:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F278: .4byte gUnknown_203B270
_0801F27C: .4byte gUnknown_80DC240
	thumb_func_end sub_801F214

	thumb_func_start sub_801F280
sub_801F280:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, _0801F30C
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x4C
	add r0, sp, 0x4
	movs r2, 0xA
	bl sub_80922B4
	ldr r0, _0801F310
	add r1, sp, 0x4
	bl strcpy
	ldr r2, _0801F314
	ldr r0, [r4]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	bl xxx_format_and_draw
	movs r7, 0
	ldr r0, [r4]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _0801F394
	add r5, sp, 0x18
	mov r8, r4
	movs r0, 0x1
	mov r9, r0
_0801F2E0:
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xC
	bl memset
	movs r0, 0x6A
	str r0, [r5, 0x4]
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r7, 3
	ldr r0, [r2, 0x10]
	adds r4, r0, r1
	ldrb r1, [r4]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _0801F386
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	beq _0801F318
	movs r0, 0x2
	b _0801F31A
	.align 2, 0
_0801F30C: .4byte gUnknown_203B270
_0801F310: .4byte gAvailablePokemonNames
_0801F314: .4byte gUnknown_80DC28C
_0801F318:
	movs r0, 0x4
_0801F31A:
	str r0, [sp, 0x18]
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0801F328
	mov r0, r9
_0801F328:
	strb r0, [r5, 0x9]
	cmp r7, 0x3
	ble _0801F332
	mov r1, r9
	strb r1, [r5, 0x8]
_0801F332:
	ldr r0, _0801F3EC
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80928A0
	ldr r2, _0801F3F0
	ldr r0, [r2]
	adds r0, 0x1C
	adds r1, r7, 0
	str r2, [sp, 0x24]
	bl sub_8013800
	adds r6, r0, 0
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	movs r4, 0xD
	ldr r2, [sp, 0x24]
	cmp r0, 0
	bne _0801F372
	movs r4, 0x8
	cmp r7, 0
	beq _0801F372
	ldr r0, [r2]
	ldr r0, [r0, 0x50]
	subs r2, r6, 0x2
	movs r1, 0x7
	str r1, [sp]
	movs r1, 0xC
	movs r3, 0x78
	bl sub_800792C
_0801F372:
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	ldr r2, _0801F3F4
	bl xxx_format_and_draw
_0801F386:
	adds r7, 0x1
	mov r1, r8
	ldr r0, [r1]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _0801F2E0
_0801F394:
	ldr r4, _0801F3F0
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073E0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801F3DC
	mov r0, r10
	cmp r0, 0
	beq _0801F3DC
	ldr r0, [r1, 0x54]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073B8
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r2, [r0]
	ldr r3, [r1, 0x54]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0
	bl xxx_format_and_draw
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073E0
_0801F3DC:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F3EC: .4byte gUnknown_202DE58
_0801F3F0: .4byte gUnknown_203B270
_0801F3F4: .4byte gUnknown_80DC2A0
	thumb_func_end sub_801F280

	thumb_func_start sub_801F3F8
sub_801F3F8:
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, _0801F424
	ldr r0, [r0]
	movs r5, 0x1
	ldr r2, [r0, 0x10]
	movs r3, 0x7
_0801F406:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0801F412
	adds r4, 0x1
_0801F412:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0801F406
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801F424: .4byte gUnknown_203B270
	thumb_func_end sub_801F3F8

	thumb_func_start sub_801F428
sub_801F428:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	mov r9, r1
	lsls r4, 16
	asrs r4, 16
	ldr r5, _0801F50C
	movs r0, 0xFA
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	ldr r3, _0801F510
	movs r1, 0x58
	adds r2, r4, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0]
	adds r1, r0, 0
	adds r1, 0x8
	str r1, [r0, 0x4]
	movs r4, 0xDF
	lsls r4, 2
	adds r1, r0, r4
	mov r2, r9
	str r2, [r1]
	movs r6, 0xE0
	lsls r6, 2
	adds r2, r0, r6
	mov r3, r9
	lsls r1, r3, 1
	add r1, r9
	lsls r1, 3
	movs r3, 0xE1
	lsls r3, 2
	mov r8, r3
	add r1, r8
	adds r1, r0, r1
	str r1, [r2]
	add r0, r8
	bl sub_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	add r1, r8
	ldr r0, _0801F514
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r1, [r5]
	adds r6, r1, r6
	ldr r0, [r6]
	movs r4, 0xF9
	lsls r4, 2
	adds r1, r4
	str r1, [r0, 0x14]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0801F518
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r3, _0801F51C
	adds r0, r3
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r5]
	adds r4, 0x3
	adds r0, r4
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	add r0, r8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	movs r0, 0xD2
	lsls r0, 2
	adds r4, r0
	bl sub_801F7E4
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x4
	mov r3, r9
	bl sub_8013818
	bl sub_801F690
	bl sub_801F700
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801F50C: .4byte gUnknown_203B274
_0801F510: .4byte gRecruitedPokemonRef
_0801F514: .4byte gUnknown_80DC2C4
_0801F518: .4byte 0x000003e5
_0801F51C: .4byte 0x000003e6
	thumb_func_end sub_801F428

	thumb_func_start sub_801F520
sub_801F520:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801F540
	ldr r0, _0801F53C
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _0801F5AE
	.align 2, 0
_0801F53C: .4byte gUnknown_203B274
_0801F540:
	ldr r0, _0801F55C
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801F566
	cmp r0, 0x2
	bgt _0801F560
	cmp r0, 0x1
	beq _0801F570
	b _0801F584
	.align 2, 0
_0801F55C: .4byte gUnknown_203B274
_0801F560:
	cmp r0, 0x4
	beq _0801F57A
	b _0801F584
_0801F566:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801F5AE
_0801F570:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801F5AE
_0801F57A:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801F5AE
_0801F584:
	ldr r0, _0801F5A0
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801F5A4
	movs r0, 0
	b _0801F5AE
	.align 2, 0
_0801F5A0: .4byte gUnknown_203B274
_0801F5A4:
	bl sub_801F690
	bl sub_801F700
	movs r0, 0x1
_0801F5AE:
	pop {r1}
	bx r1
	thumb_func_end sub_801F520

	thumb_func_start sub_801F5B4
sub_801F5B4:
	push {r4,lr}
	ldr r0, _0801F5E8
	ldr r1, [r0]
	ldr r2, [r1, 0x4]
	ldr r3, _0801F5EC
	adds r0, r1, r3
	movs r4, 0
	ldrsh r3, [r0, r4]
	movs r4, 0xD9
	lsls r4, 2
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	muls r0, r3
	movs r3, 0xD8
	lsls r3, 2
	adds r1, r3
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r0, r1
	lsls r0, 1
	adds r2, r0
	ldrh r0, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801F5E8: .4byte gUnknown_203B274
_0801F5EC: .4byte 0x00000366
	thumb_func_end sub_801F5B4

	thumb_func_start sub_801F5F0
sub_801F5F0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801F638
	ldr r0, [r5]
	movs r1, 0xE1
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_801F690
	bl sub_801F700
	cmp r4, 0
	beq _0801F632
	ldr r0, [r5]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl AddMenuCursorSprite
_0801F632:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F638: .4byte gUnknown_203B274
	thumb_func_end sub_801F5F0

	thumb_func_start sub_801F63C
sub_801F63C:
	push {r4-r6,lr}
	ldr r5, _0801F688
	ldr r2, [r5]
	cmp r2, 0
	beq _0801F680
	movs r1, 0xDF
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE1
	lsls r4, 2
	adds r1, r4
	ldr r0, _0801F68C
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_0801F680:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F688: .4byte gUnknown_203B274
_0801F68C: .4byte gUnknown_80DC2AC
	thumb_func_end sub_801F63C

	thumb_func_start sub_801F690
sub_801F690:
	push {r4,r5,lr}
	ldr r5, _0801F6F4
	ldr r0, [r5]
	ldr r1, _0801F6F8
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r5]
	movs r1, 0xDF
	lsls r1, 2
	adds r4, r3, r1
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _0801F6FC
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0xE5
	lsls r0, 2
	adds r3, r0
	strh r2, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r1, 0xE1
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F6F4: .4byte gUnknown_203B274
_0801F6F8: .4byte 0x00000362
_0801F6FC: .4byte 0x00000392
	thumb_func_end sub_801F690

	thumb_func_start sub_801F700
sub_801F700:
	push {r4-r7,lr}
	sub sp, 0xB4
	ldr r6, _0801F7D4
	ldr r0, [r6]
	movs r4, 0xDF
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r6]
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073B8
	add r5, sp, 0x34
	ldr r1, _0801F7D8
	ldr r0, [r6]
	ldr r3, _0801F7DC
	adds r2, r0, r3
	movs r7, 0
	ldrsh r2, [r2, r7]
	adds r2, 0x1
	adds r3, 0x2
	adds r0, r3
	movs r7, 0
	ldrsh r3, [r0, r7]
	adds r0, r5, 0
	bl sprintf_2
	ldr r0, [r6]
	adds r0, r4
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
	movs r4, 0
	ldr r0, [r6]
	ldr r1, _0801F7E0
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r4, r0
	bge _0801F7BC
	adds r5, r6, 0
_0801F762:
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	ldr r3, _0801F7DC
	adds r0, r1, r3
	movs r6, 0
	ldrsh r3, [r0, r6]
	movs r7, 0xD9
	lsls r7, 2
	adds r1, r7
	movs r6, 0
	ldrsh r0, [r1, r6]
	muls r0, r3
	adds r0, r4
	lsls r0, 1
	adds r2, r0
	ldrh r1, [r2]
	add r0, sp, 0x4
	bl sub_8092C84
	ldr r0, [r5]
	subs r7, 0x1C
	adds r0, r7
	adds r1, r4, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r5]
	movs r2, 0xDF
	lsls r2, 2
	adds r0, r2
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	adds r4, 0x1
	ldr r0, [r5]
	ldr r3, _0801F7E0
	adds r0, r3
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r4, r0
	blt _0801F762
_0801F7BC:
	ldr r0, _0801F7D4
	ldr r0, [r0]
	movs r7, 0xDF
	lsls r7, 2
	adds r0, r7
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0xB4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F7D4: .4byte gUnknown_203B274
_0801F7D8: .4byte gUnknown_80DC2DC
_0801F7DC: .4byte 0x00000366
_0801F7E0: .4byte 0x00000362
	thumb_func_end sub_801F700

	thumb_func_start sub_801F7E4
sub_801F7E4:
	push {r4,lr}
	ldr r4, _0801F804
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	ldr r1, [r1]
	bl sub_808E218
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0xCF
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801F804: .4byte gUnknown_203B274
	thumb_func_end sub_801F7E4

	thumb_func_start sub_801F808
sub_801F808:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x1
	bl ResetSprites
	ldr r5, _0801F88C
	movs r0, 0xD4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	str r1, [r0, 0x5C]
	adds r1, r0, 0
	adds r1, 0x64
	str r1, [r0, 0x60]
	adds r0, r1, 0
	bl sub_80140B4
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	str r4, [r0, 0x4]
	movs r2, 0x4
	ldrh r0, [r4, 0x6]
	cmp r0, 0
	bne _0801F862
	adds r3, r5, 0
_0801F84C:
	subs r2, 0x1
	cmp r2, 0x1
	ble _0801F862
	ldr r0, [r3]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r1
	subs r0, 0x2
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801F84C
_0801F862:
	ldr r4, _0801F88C
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r3, [r1, 0x5C]
	adds r1, r2, 0
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	adds r0, 0xC8
	bl sub_801317C
	movs r0, 0
	bl sub_801F918
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801F88C: .4byte gUnknown_203B278
	thumb_func_end sub_801F808

	thumb_func_start sub_801F890
sub_801F890:
	push {lr}
	ldr r0, _0801F8A8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801F8BC
	cmp r0, 0x1
	bgt _0801F8AC
	cmp r0, 0
	beq _0801F8B6
	b _0801F8C6
	.align 2, 0
_0801F8A8: .4byte gUnknown_203B278
_0801F8AC:
	cmp r0, 0x2
	beq _0801F8C6
	cmp r0, 0x3
	beq _0801F8C2
	b _0801F8C6
_0801F8B6:
	bl sub_801FA58
	b _0801F8CA
_0801F8BC:
	bl sub_801FAD4
	b _0801F8CA
_0801F8C2:
	movs r0, 0x3
	b _0801F8CC
_0801F8C6:
	movs r0, 0x2
	b _0801F8CC
_0801F8CA:
	movs r0, 0
_0801F8CC:
	pop {r1}
	bx r1
	thumb_func_end sub_801F890

	thumb_func_start sub_801F8D0
sub_801F8D0:
	push {r4,r5,lr}
	ldr r4, _0801F910
	ldr r2, [r4]
	cmp r2, 0
	beq _0801F90A
	ldr r0, [r2, 0x5C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x64
	ldr r0, _0801F914
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801F90A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F910: .4byte gUnknown_203B278
_0801F914: .4byte gUnknown_80DC2F8
	thumb_func_end sub_801F8D0

	thumb_func_start sub_801F918
sub_801F918:
	push {lr}
	ldr r1, _0801F92C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801F930
	bl sub_801F9A4
	pop {r0}
	bx r0
	.align 2, 0
_0801F92C: .4byte gUnknown_203B278
	thumb_func_end sub_801F918

	thumb_func_start sub_801F930
sub_801F930:
	push {r4,lr}
	ldr r4, _0801F94C
	ldr r0, [r4]
	adds r0, 0x64
	bl sub_80140B4
	ldr r2, [r4]
	ldr r3, [r2]
	cmp r3, 0
	beq _0801F950
	cmp r3, 0x1
	beq _0801F98C
	b _0801F99C
	.align 2, 0
_0801F94C: .4byte gUnknown_203B278
_0801F950:
	ldr r0, [r2, 0x60]
	adds r1, r2, 0
	adds r1, 0xC4
	str r1, [r0, 0x14]
	adds r0, r2, 0
	adds r0, 0x48
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x46
	ldrh r1, [r1]
	adds r0, 0xC5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC6
	movs r1, 0x10
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC7
	strb r3, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801F99C
_0801F98C:
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801F99C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801F930

	thumb_func_start sub_801F9A4
sub_801F9A4:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0801F9EC
	ldr r0, [r5]
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0801F9F0
	cmp r4, 0x1
	bgt _0801FA48
	cmp r4, 0
	bne _0801FA48
	ldr r0, [r0, 0x5C]
	bl sub_8008C54
	ldr r3, [r5]
	adds r2, r3, 0
	adds r2, 0x46
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldr r1, [r3, 0x4]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3, 0x8]
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldrh r1, [r3, 0x8]
	ldr r2, [r3, 0x5C]
	adds r3, 0x14
	bl sub_8093D9C
	ldr r1, [r5]
	str r0, [r1, 0x10]
	str r4, [r1, 0x24]
	b _0801FA48
	.align 2, 0
_0801F9EC: .4byte gUnknown_203B278
_0801F9F0:
	ldr r0, [r0, 0x5C]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x5C]
	bl sub_80073B8
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	lsls r1, 2
	adds r0, 0x14
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _0801FA50
	ldr r1, [r1]
	bl strcpy
	ldr r2, _0801FA54
	ldr r0, [r5]
	ldr r3, [r0, 0x5C]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl xxx_format_and_draw
	ldr r3, [r5]
	ldr r1, [r3, 0xC]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x14
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	ldr r3, [r3, 0x5C]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	bl xxx_format_and_draw
	ldr r0, [r5]
	ldr r0, [r0, 0x5C]
	bl sub_80073E0
_0801FA48:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FA50: .4byte gAvailablePokemonNames
_0801FA54: .4byte gUnknown_80DC310
	thumb_func_end sub_801F9A4

	thumb_func_start sub_801FA58
sub_801FA58:
	push {r4,lr}
	ldr r0, _0801FAA4
	ldr r2, [r0]
	ldr r1, [r2, 0x10]
	adds r4, r0, 0
	cmp r1, 0
	beq _0801FA7C
	ldr r0, [r2, 0x24]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801FA74
	bl sub_8013F84
_0801FA74:
	ldr r1, [r4]
	ldr r0, [r1, 0x24]
	adds r0, 0x1
	str r0, [r1, 0x24]
_0801FA7C:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	ldr r1, [r1, 0x5C]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801FAA8
	cmp r0, 0x2
	beq _0801FAC2
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	beq _0801FACE
	movs r0, 0
	b _0801FACA
	.align 2, 0
_0801FAA4: .4byte gUnknown_203B278
_0801FAA8:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	cmp r0, 0
	beq _0801FABE
	movs r0, 0
	str r0, [r1, 0xC]
	movs r0, 0x1
	b _0801FACA
_0801FABE:
	movs r0, 0x3
	b _0801FACA
_0801FAC2:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
_0801FACA:
	bl sub_801F918
_0801FACE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801FA58

	thumb_func_start sub_801FAD4
sub_801FAD4:
	push {r4,lr}
	ldr r0, _0801FB14
	ldr r3, [r0]
	ldr r1, [r3, 0x10]
	subs r1, 0x1
	ldr r2, [r3, 0xC]
	adds r4, r0, 0
	cmp r2, r1
	bge _0801FAFC
	ldr r0, [r3, 0x24]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801FAF4
	bl sub_8013F84
_0801FAF4:
	ldr r1, [r4]
	ldr r0, [r1, 0x24]
	adds r0, 0x1
	str r0, [r1, 0x24]
_0801FAFC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	ldr r1, [r1, 0x5C]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801FB18
	cmp r0, 0x2
	beq _0801FB3C
	b _0801FB48
	.align 2, 0
_0801FB14: .4byte gUnknown_203B278
_0801FB18:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	adds r1, 0x1
	str r1, [r0, 0xC]
	ldr r0, [r0, 0x10]
	cmp r1, r0
	bge _0801FB34
	movs r0, 0x1
	bl sub_801F918
	b _0801FB48
_0801FB34:
	movs r0, 0
	bl sub_801F918
	b _0801FB48
_0801FB3C:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	bl sub_801F918
_0801FB48:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801FAD4

	thumb_func_start sub_801FB50
sub_801FB50:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r6, _0801FBC0
	movs r0, 0xF0
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	movs r7, 0
	str r7, [r0, 0x70]
	str r7, [r0, 0x74]
	str r7, [r0, 0x78]
	str r4, [r0]
	strb r7, [r0, 0x15]
	ldr r0, _0801FBC4
	ldr r4, _0801FBC8
	adds r1, r4, 0
	bl CopyYellowSpeciesNametoBuffer
	ldr r5, _0801FBCC
	adds r0, r5, 0
	adds r1, r4, 0
	bl CopyYellowSpeciesNametoBuffer
	adds r0, r4, 0
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r5, 0
	subs r0, 0x50
	bl strcpy
	subs r5, 0xF0
	bl GetPlayerPokemonStruct
	adds r1, r0, 0
	adds r0, r5, 0
	bl PrintPokeNameToBuffer
	ldr r2, [r6]
	ldr r0, [r2]
	cmp r0, 0x1
	bne _0801FBD0
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r2, r1
	str r7, [r0]
	b _0801FBDE
	.align 2, 0
_0801FBC0: .4byte gUnknown_203B27C
_0801FBC4: .4byte gUnknown_202E5D8
_0801FBC8: .4byte 0x00000155
_0801FBCC: .4byte gUnknown_202E1C8
_0801FBD0:
	movs r3, 0xBE
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0xB6
	lsls r4, 1
	adds r0, r2, r4
	str r0, [r1]
_0801FBDE:
	ldr r0, _0801FC34
	bl GetDialogueSpriteDataPtr
	ldr r2, _0801FC38
	ldr r3, [r2]
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r3, r4
	str r0, [r1]
	adds r4, 0x4
	adds r1, r3, r4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r3, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _0801FC3C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, 0xA
	adds r0, r4
	strb r1, [r0]
	ldr r2, [r2]
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x3
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_801FDA8
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801FC34: .4byte 0x00000155
_0801FC38: .4byte gUnknown_203B27C
_0801FC3C: .4byte 0x00000179
	thumb_func_end sub_801FB50

	thumb_func_start sub_801FC40
sub_801FC40:
	push {lr}
	ldr r1, _0801FC5C
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0x22
	bls _0801FC50
	b _0801FD70
_0801FC50:
	lsls r0, 2
	ldr r1, _0801FC60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FC5C: .4byte gUnknown_203B27C
_0801FC60: .4byte _0801FC64
	.align 2, 0
_0801FC64:
	.4byte _0801FCF0
	.4byte _0801FCF0
	.4byte _0801FCF6
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FCFC
	.4byte _0801FD02
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD50
	.4byte _0801FD70
	.4byte _0801FD08
	.4byte _0801FD08
	.4byte _0801FD0E
	.4byte _0801FD14
	.4byte _0801FD1A
	.4byte _0801FD70
	.4byte _0801FD20
	.4byte _0801FD20
	.4byte _0801FD26
	.4byte _0801FD2C
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD32
	.4byte _0801FD38
	.4byte _0801FD38
	.4byte _0801FD3E
	.4byte _0801FD44
	.4byte _0801FD4A
_0801FCF0:
	bl sub_8021154
	b _0801FD74
_0801FCF6:
	bl sub_80209AC
	b _0801FD74
_0801FCFC:
	bl sub_80209FC
	b _0801FD74
_0801FD02:
	bl sub_8020A34
	b _0801FD74
_0801FD08:
	bl sub_8020A80
	b _0801FD74
_0801FD0E:
	bl sub_8020B38
	b _0801FD74
_0801FD14:
	bl sub_8020C2C
	b _0801FD74
_0801FD1A:
	bl sub_8020C48
	b _0801FD74
_0801FD20:
	bl sub_8020C64
	b _0801FD74
_0801FD26:
	bl sub_8020CC0
	b _0801FD74
_0801FD2C:
	bl sub_8020D74
	b _0801FD74
_0801FD32:
	bl sub_8020D90
	b _0801FD74
_0801FD38:
	bl sub_8020DCC
	b _0801FD74
_0801FD3E:
	bl sub_8020EB4
	b _0801FD74
_0801FD44:
	bl sub_80210C8
	b _0801FD74
_0801FD4A:
	bl sub_80210E4
	b _0801FD74
_0801FD50:
	ldr r0, [r2]
	ldrb r0, [r0, 0x15]
	cmp r0, 0x1
	bne _0801FD68
	ldr r0, _0801FD6C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x96
	str r0, [r1]
_0801FD68:
	movs r0, 0x3
	b _0801FD76
	.align 2, 0
_0801FD6C: .4byte gTeamInventory_203B460
_0801FD70:
	bl sub_8021130
_0801FD74:
	movs r0, 0
_0801FD76:
	pop {r1}
	bx r1
	thumb_func_end sub_801FC40

	thumb_func_start sub_801FD7C
sub_801FD7C:
	push {r4,lr}
	ldr r4, _0801FDA4
	ldr r0, [r4]
	cmp r0, 0
	beq _0801FD9C
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801FD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FDA4: .4byte gUnknown_203B27C
	thumb_func_end sub_801FD7C

	thumb_func_start sub_801FDA8
sub_801FDA8:
	push {lr}
	ldr r1, _0801FDBC
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801FDC0
	bl sub_801FF28
	pop {r0}
	bx r0
	.align 2, 0
_0801FDBC: .4byte gUnknown_203B27C
	thumb_func_end sub_801FDA8

	thumb_func_start sub_801FDC0
sub_801FDC0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0801FDE8
	ldr r0, [r4]
	movs r5, 0xC0
	lsls r5, 1
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	cmp r1, 0x11
	beq _0801FE38
	cmp r1, 0x11
	bgt _0801FDEC
	cmp r1, 0x2
	beq _0801FDF6
	b _0801FED4
	.align 2, 0
_0801FDE8: .4byte gUnknown_203B27C
_0801FDEC:
	cmp r1, 0x17
	beq _0801FE6C
	cmp r1, 0x20
	beq _0801FE88
	b _0801FED4
_0801FDF6:
	adds r0, r5
	movs r1, 0x80
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, 0xCC
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	movs r3, 0xD8
	lsls r3, 1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r4]
	movs r6, 0xE4
	lsls r6, 1
	adds r1, r6
	ldr r0, _0801FE34
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FE34: .4byte gUnknown_80DC37C
_0801FE38:
	bl sub_80205D0
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE68
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	movs r6, 0xC0
	lsls r6, 1
	adds r0, r6
	b _0801FEC2
	.align 2, 0
_0801FE68: .4byte gUnknown_80DC334
_0801FE6C:
	bl sub_802069C
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE84
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	b _0801FEB0
	.align 2, 0
_0801FE84: .4byte gUnknown_80DC334
_0801FE88:
	bl CreateGulpinLinkMenu
	ldr r1, [r4]
	movs r7, 0xCC
	lsls r7, 1
	adds r1, r7
	ldr r0, _0801FECC
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FED0
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
_0801FEB0:
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, r5
_0801FEC2:
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FECC: .4byte gUnknown_80DC31C
_0801FED0: .4byte gUnknown_80DC34C
_0801FED4:
	ldr r5, _0801FF20
	mov r12, r5
	movs r6, 0xC0
	lsls r6, 1
	mov r8, r6
	ldr r4, _0801FF24
	movs r3, 0
	movs r2, 0x3
_0801FEE4:
	mov r7, r12
	ldr r1, [r7]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801FEE4
	bl ResetUnusedInputStruct
	ldr r0, _0801FF20
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801FF14:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FF20: .4byte gUnknown_203B27C
_0801FF24: .4byte gUnknown_80DC31C
	thumb_func_end sub_801FDC0

	thumb_func_start sub_801FF28
sub_801FF28:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801FF44
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r5, r1, 0
	cmp r0, 0x23
	bls _0801FF3A
	b _08020562
_0801FF3A:
	lsls r0, 2
	ldr r1, _0801FF48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FF44: .4byte gUnknown_203B27C
_0801FF48: .4byte _0801FF4C
	.align 2, 0
_0801FF4C:
	.4byte _0801FFDC
	.4byte _08020018
	.4byte _08020064
	.4byte _0802006C
	.4byte _08020090
	.4byte _080200B4
	.4byte _080200D8
	.4byte _080200FC
	.4byte _08020144
	.4byte _0802018C
	.4byte _080201B0
	.4byte _080201D4
	.4byte _080201F8
	.4byte _08020562
	.4byte _0802021C
	.4byte _08020240
	.4byte _0802024E
	.4byte _08020256
	.4byte _08020274
	.4byte _08020282
	.4byte _0802028E
	.4byte _080202B0
	.4byte _080202BE
	.4byte _080202C6
	.4byte _080202E4
	.4byte _08020304
	.4byte _08020344
	.4byte _080203B0
	.4byte _080203D4
	.4byte _0802038C
	.4byte _080203F8
	.4byte _08020428
	.4byte _08020434
	.4byte _08020460
	.4byte _08020478
	.4byte _08020500
_0801FFDC:
	ldr r0, [r5]
	movs r4, 0x2
	str r4, [r0, 0x6C]
	bl CreateGulpinShopMenu
	ldr r5, [r5]
	str r4, [r5, 0x8]
	ldr r2, _08020014
	ldr r1, [r5]
	movs r0, 0x64
	muls r0, r1
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r5, 0x6C]
	adds r3, r5, 0
	adds r3, 0x7C
	adds r1, r5, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r5, r4
	b _0802004C
	.align 2, 0
_08020014: .4byte gGulpinDialogue
_08020018:
	bl CreateGulpinShopMenu
	ldr r0, _0802005C
	ldr r4, [r0]
	movs r0, 0x2
	str r0, [r4, 0x8]
	ldr r1, _08020060
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r4, 0x6C]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_0802004C:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802005C: .4byte gUnknown_203B27C
_08020060: .4byte gGulpinDialogue
_08020064:
	movs r0, 0x3
	bl DrawTeamMoneyBox
	b _08020562
_0802006C:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _0802008C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802008C: .4byte gGulpinDialogue
_08020090:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200B0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0xC
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200B0: .4byte gGulpinDialogue
_080200B4:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200D4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x10
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200D4: .4byte gGulpinDialogue
_080200D8:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200F8
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x14
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200F8: .4byte gGulpinDialogue
_080200FC:
	bl sub_8020900
	ldr r1, _0802013C
	ldr r0, _08020140
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x18
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x10
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802013C: .4byte gGulpinDialogue
_08020140: .4byte gUnknown_203B27C
_08020144:
	bl sub_8020950
	ldr r1, _08020184
	ldr r0, _08020188
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x54
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xD
	bl sub_8014248
	b _08020562
	.align 2, 0
_08020184: .4byte gGulpinDialogue
_08020188: .4byte gUnknown_203B27C
_0802018C:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x58
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201AC: .4byte gGulpinDialogue
_080201B0:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x5C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201D0: .4byte gGulpinDialogue
_080201D4:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x60
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201F4: .4byte gGulpinDialogue
_080201F8:
	ldr r2, [r5]
	movs r0, 0xD
	str r0, [r2, 0x8]
	ldr r1, _08020218
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_08020218: .4byte gGulpinDialogue
_0802021C:
	ldr r2, [r5]
	movs r0, 0xF
	str r0, [r2, 0x8]
	ldr r1, _0802023C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x20
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802023C: .4byte gGulpinDialogue
_08020240:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _08020562
_0802024E:
	movs r0, 0x1
	bl sub_8023B7C
	b _08020562
_08020256:
	bl sub_8023DA4
	ldr r0, _08020270
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x70]
	b _0802044C
	.align 2, 0
_08020270: .4byte gUnknown_203B27C
_08020274:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0x2
	bl sub_8024458
	b _08020562
_08020282:
	ldr r0, [r5]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl sub_801BEEC
	b _08020562
_0802028E:
	ldr r2, [r5]
	movs r0, 0x15
	str r0, [r2, 0x8]
	ldr r1, _080202AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x24
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080202AC: .4byte gGulpinDialogue
_080202B0:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0
	bl sub_801F428
	b _08020562
_080202BE:
	movs r0, 0x1
	bl sub_801F5F0
	b _08020562
_080202C6:
	bl sub_801F700
	ldr r0, _080202E0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x74]
	b _0802044C
	.align 2, 0
_080202E0: .4byte gUnknown_203B27C
_080202E4:
	ldr r0, [r5]
	ldrh r1, [r0, 0x1C]
	adds r0, 0x64
	strh r1, [r0]
	movs r2, 0x1
	adds r4, r5, 0
	movs r3, 0
_080202F2:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r0, 0x64
	adds r0, r1
	strh r3, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080202F2
	b _0802046E
_08020304:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r1, [r5]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0802033C
	ldrh r1, [r1, 0x1E]
	bl sub_8092C84
	ldr r1, _08020340
	ldr r2, [r5]
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x28
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802033C: .4byte gAvailablePokemonNames
_08020340: .4byte gGulpinDialogue
_08020344:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r3, [r5]
	movs r0, 0x10
	str r0, [r3, 0x8]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020370
	ldr r1, _0802036C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x38
	b _08020520
	.align 2, 0
_0802036C: .4byte gGulpinDialogue
_08020370:
	ldr r1, _08020388
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x34
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	b _0802052A
	.align 2, 0
_08020388: .4byte gGulpinDialogue
_0802038C:
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _080203A2
	movs r5, 0xC
	ldrsh r1, [r2, r5]
	adds r2, 0x24
	movs r0, 0
	bl DisplayGulpinDialogueSprite
	b _08020562
_080203A2:
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	adds r2, 0x24
	movs r0, 0x1
	bl DisplayGulpinDialogueSprite
	b _08020562
_080203B0:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x3C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203D0: .4byte gGulpinDialogue
_080203D4:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x40
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203F4: .4byte gGulpinDialogue
_080203F8:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_809401C
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r1, [r0, r5]
	adds r2, r0, 0
	adds r2, 0x24
	ldrb r3, [r0, 0x15]
	ldr r0, _08020424
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x1
	bl sub_801EE10
	b _08020562
	.align 2, 0
_08020424: .4byte gUnknown_80DC394
_08020428:
	ldr r0, [r5]
	ldrb r1, [r0, 0x15]
	movs r0, 0x1
	bl sub_801F1B0
	b _08020562
_08020434:
	movs r0, 0
	bl sub_801F280
	ldr r0, _0802045C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x78]
_0802044C:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08020562
	.align 2, 0
_0802045C: .4byte gUnknown_203B27C
_08020460:
	ldr r2, [r5]
	ldr r0, [r2, 0x18]
	adds r1, r2, 0
	adds r1, 0x24
	adds r2, 0x64
	bl sub_8093560
_0802046E:
	ldr r0, [r5]
	adds r0, 0x64
	bl sub_801F808
	b _08020562
_08020478:
	bl sub_80208B0
	ldr r0, _080204B8
	ldr r4, _080204BC
	ldr r1, [r4]
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r4, [r4]
	ldrb r5, [r4, 0x14]
	cmp r5, 0
	beq _080204C4
	ldr r1, _080204C0
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	b _080204E8
	.align 2, 0
_080204B8: .4byte gUnknown_202DFE8
_080204BC: .4byte gUnknown_203B27C
_080204C0: .4byte gGulpinDialogue
_080204C4:
	ldr r1, _080204FC
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x44
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_080204E8:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x11
	bl sub_8014248
	b _08020562
	.align 2, 0
_080204FC: .4byte gGulpinDialogue
_08020500:
	ldr r1, [r5]
	movs r0, 0x1F
	str r0, [r1, 0x8]
	ldr r0, _08020538
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r3, [r5]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020544
	ldr r1, _0802053C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x50
_08020520:
	adds r0, r1
	ldr r0, [r0]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r3, r2
_0802052A:
	ldr r2, [r1]
_0802052C:
	ldr r3, _08020540
	movs r1, 0
	bl sub_80141B4
	b _08020562
	.align 2, 0
_08020538: .4byte gUnknown_202DFE8
_0802053C: .4byte gGulpinDialogue
_08020540: .4byte 0x0000010d
_08020544:
	ldr r1, _0802056C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	ldr r2, [r1]
	ldr r3, _08020570
	movs r1, 0
	bl sub_80141B4
_08020562:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802056C: .4byte gGulpinDialogue
_08020570: .4byte 0x0000010d
	thumb_func_end sub_801FF28

	thumb_func_start CreateGulpinShopMenu
CreateGulpinShopMenu:
	push {r4,lr}
	ldr r4, _080205C0
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080205C4
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080205C8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080205CC
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x90
	str r2, [r0]
	adds r0, 0x4
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080205C0: .4byte gUnknown_203B27C
_080205C4: .4byte gGulpinProceed
_080205C8: .4byte gGulpinInfo
_080205CC: .4byte gUnknown_80D4934
	thumb_func_end CreateGulpinShopMenu

	thumb_func_start sub_80205D0
sub_80205D0:
	push {r4-r7,lr}
	ldr r4, _08020660
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _08020664
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r2, r12
	adds r2, 0x80
	movs r0, 0x4
	str r0, [r2]
	movs r3, 0x1
	adds r1, 0x84
	ldr r0, _08020668
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802066C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xC
	str r0, [r1]
	movs r6, 0x3
	adds r1, 0x4
	ldr r0, _08020670
	str r0, [r1]
	mov r0, r12
	adds r0, 0x98
	str r6, [r0]
	movs r6, 0x4
	adds r0, 0x4
	str r5, [r0]
	adds r0, 0x4
	str r3, [r0]
	mov r3, r12
	adds r3, 0xBC
_0802062A:
	ldrh r0, [r3]
	cmp r0, 0
	bne _0802063A
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x70]
	cmp r1, r0
	beq _08020696
_0802063A:
	adds r2, 0x8
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0802062A
	movs r5, 0
	cmp r5, r6
	bge _08020696
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020674
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08020696
	.align 2, 0
_08020660: .4byte gUnknown_203B27C
_08020664: .4byte gUnknown_80DC3D8
_08020668: .4byte gUnknown_80DC3E0
_0802066C: .4byte gUnknown_80DC3E8
_08020670: .4byte gUnknown_80DC3F4
_08020674:
	adds r5, 0x1
	cmp r5, r6
	bge _08020696
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020674
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08020696:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80205D0

	thumb_func_start sub_802069C
sub_802069C:
	push {r4-r7,lr}
	ldr r4, _08020718
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _0802071C
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r3, r12
	adds r3, 0x80
	movs r0, 0x3
	str r0, [r3]
	movs r2, 0x1
	adds r1, 0x84
	ldr r0, _08020720
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	movs r6, 0x2
	mov r0, r12
	adds r0, 0x8C
	str r5, [r0]
	adds r0, 0x4
	str r2, [r0]
	mov r2, r12
	adds r2, 0xBC
_080206E0:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080206F0
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _08020746
_080206F0:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080206E0
	movs r5, 0
	cmp r5, r6
	bge _08020746
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020724
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _08020746
	.align 2, 0
_08020718: .4byte gUnknown_203B27C
_0802071C: .4byte gUnknown_80DC3F4
_08020720: .4byte gUnknown_80D4970
_08020724:
	adds r5, 0x1
	cmp r5, r6
	bge _08020746
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020724
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_08020746:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802069C

	thumb_func_start CreateGulpinLinkMenu
CreateGulpinLinkMenu:
	push {r4-r7,lr}
	movs r7, 0
	ldr r4, _08020780
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldrb r0, [r1, 0x16]
	cmp r0, 0
	beq _0802079C
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80932E0
	lsls r0, 24
	cmp r0, 0
	beq _08020788
	ldr r0, [r4]
	ldr r1, _08020784
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x6
	b _08020792
	.align 2, 0
_08020780: .4byte gUnknown_203B27C
_08020784: .4byte gGulpinDeselect
_08020788:
	ldr r0, [r4]
	ldr r1, _08020798
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x5
_08020792:
	str r1, [r0]
	mov r12, r4
	b _080207CA
	.align 2, 0
_08020798: .4byte gGulpinSet
_0802079C:
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80932FC
	lsls r0, 24
	cmp r0, 0
	beq _080207B4
	ldr r1, [r4]
	ldr r0, _080207B0
	b _080207B8
	.align 2, 0
_080207B0: .4byte gGulpinDeselect
_080207B4:
	ldr r1, [r4]
	ldr r0, _0802086C
_080207B8:
	str r0, [r1, 0x7C]
	ldr r2, _08020870
	ldr r0, [r2]
	lsls r1, r7, 3
	adds r0, 0x80
	adds r0, r1
	movs r1, 0x7
	str r1, [r0]
	mov r12, r2
_080207CA:
	adds r7, 0x1
	mov r0, r12
	ldr r4, [r0]
	lsls r1, r7, 3
	adds r3, r4, 0
	adds r3, 0x7C
	adds r2, r3, r1
	ldr r0, _08020874
	str r0, [r2]
	adds r6, r4, 0
	adds r6, 0x80
	adds r1, r6, r1
	movs r0, 0x8
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020878
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0x9
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802087C
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xA
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020880
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xB
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r6, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	cmp r3, r7
	bge _0802084C
	adds r5, r4, 0
	adds r4, 0xBC
	adds r2, r6, 0
_08020834:
	ldrh r0, [r4]
	cmp r0, 0
	bne _08020842
	ldr r1, [r2]
	ldr r0, [r5, 0x78]
	cmp r1, r0
	beq _080208A8
_08020842:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _08020834
_0802084C:
	movs r3, 0
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020884
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x78]
	b _080208A8
	.align 2, 0
_0802086C: .4byte gGulpinSet
_08020870: .4byte gUnknown_203B27C
_08020874: .4byte gGulpinLink
_08020878: .4byte gGulpinDelink
_0802087C: .4byte gGulpinForget
_08020880: .4byte gUnknown_80D4970
_08020884:
	adds r3, 0x1
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020884
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x78]
_080208A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateGulpinLinkMenu

	thumb_func_start sub_80208B0
sub_80208B0:
	push {r4,lr}
	ldr r4, _080208F4
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080208F8
	ldr r0, [r0]
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080208FC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x8C
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080208F4: .4byte gUnknown_203B27C
_080208F8: .4byte gUnknown_80D4920
_080208FC: .4byte gUnknown_80D4928
	thumb_func_end sub_80208B0

	thumb_func_start sub_8020900
sub_8020900:
	push {r4,lr}
	ldr r4, _08020944
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08020948
	ldr r0, [r0]
	str r0, [r3, 0x7C]
	adds r1, r3, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802094C
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x8C
	str r2, [r0]
	adds r1, 0x8
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020944: .4byte gUnknown_203B27C
_08020948: .4byte gUnknown_80D4920
_0802094C: .4byte gUnknown_80D4928
	thumb_func_end sub_8020900

	thumb_func_start sub_8020950
sub_8020950:
	push {r4,lr}
	ldr r4, _0802099C
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080209A0
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0xD
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080209A4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xE
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080209A8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xF
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x94
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802099C: .4byte gUnknown_203B27C
_080209A0: .4byte gUnknown_80DC428
_080209A4: .4byte gUnknown_80DC438
_080209A8: .4byte gUnknown_80DC448
	thumb_func_end sub_8020950

	thumb_func_start sub_80209AC
sub_80209AC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080209F4
	ldr r0, _080209D4
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x6C]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080209DE
	cmp r0, 0x2
	bgt _080209D8
	cmp r0, 0x1
	beq _080209EE
	b _080209F4
	.align 2, 0
_080209D4: .4byte gUnknown_203B27C
_080209D8:
	cmp r0, 0xB
	beq _080209E6
	b _080209F4
_080209DE:
	movs r0, 0xE
	bl sub_801FDA8
	b _080209F4
_080209E6:
	movs r0, 0x8
	bl sub_801FDA8
	b _080209F4
_080209EE:
	movs r0, 0xC
	bl sub_801FDA8
_080209F4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209AC

	thumb_func_start sub_80209FC
sub_80209FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A2E
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08020A20
	cmp r0, 0x10
	bgt _08020A1A
	cmp r0, 0x1
	beq _08020A28
	b _08020A2E
_08020A1A:
	cmp r0, 0x11
	beq _08020A28
	b _08020A2E
_08020A20:
	movs r0, 0xE
	bl sub_801FDA8
	b _08020A2E
_08020A28:
	movs r0, 0xC
	bl sub_801FDA8
_08020A2E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209FC

	thumb_func_start sub_8020A34
sub_8020A34:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A7A
	ldr r0, [sp]
	cmp r0, 0xD
	beq _08020A5C
	cmp r0, 0xD
	bgt _08020A52
	cmp r0, 0x1
	beq _08020A74
	b _08020A7A
_08020A52:
	cmp r0, 0xE
	beq _08020A64
	cmp r0, 0xF
	beq _08020A6C
	b _08020A7A
_08020A5C:
	movs r0, 0x9
	bl sub_801FDA8
	b _08020A7A
_08020A64:
	movs r0, 0xA
	bl sub_801FDA8
	b _08020A7A
_08020A6C:
	movs r0, 0xB
	bl sub_801FDA8
	b _08020A7A
_08020A74:
	movs r0, 0x1
	bl sub_801FDA8
_08020A7A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8020A34

	thumb_func_start sub_8020A80
sub_8020A80:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x4
	bhi _08020B32
	lsls r0, 2
	ldr r1, _08020A98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020A98: .4byte _08020A9C
	.align 2, 0
_08020A9C:
	.4byte _08020B32
	.4byte _08020B32
	.4byte _08020B28
	.4byte _08020AB0
	.4byte _08020AEC
_08020AB0:
	bl sub_8023B44
	ldr r4, _08020AE0
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020AE4
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020AE8
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl PrintPokeNameToBuffer
	movs r0, 0x11
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020AE0: .4byte gUnknown_203B27C
_08020AE4: .4byte gRecruitedPokemonRef
_08020AE8: .4byte gUnknown_202E128
_08020AEC:
	bl sub_8023B44
	ldr r4, _08020B1C
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020B20
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020B24
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl PrintPokeNameToBuffer
	movs r0, 0x12
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020B1C: .4byte gUnknown_203B27C
_08020B20: .4byte gRecruitedPokemonRef
_08020B24: .4byte gUnknown_202E128
_08020B28:
	bl sub_8023C60
	movs r0, 0x7
	bl sub_801FDA8
_08020B32:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020A80

	thumb_func_start sub_8020B38
sub_8020B38:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _08020B7C
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020B68
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020B68
	ldr r0, [r4]
	str r1, [r0, 0x70]
_08020B68:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bhi _08020C24
	lsls r0, 2
	ldr r1, _08020B80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020B7C: .4byte gUnknown_203B27C
_08020B80: .4byte _08020B84
	.align 2, 0
_08020B84:
	.4byte _08020BC8
	.4byte _08020C24
	.4byte _08020BD0
	.4byte _08020C0E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C16
	.4byte _08020C1E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020BC8
_08020BC8:
	movs r0, 0x10
	bl sub_801FDA8
	b _08020C24
_08020BD0:
	ldr r0, _08020BF0
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetBaseSpeciesNoUnown
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	bne _08020BF4
	movs r0, 0x1C
	bl sub_801FDA8
	b _08020C24
	.align 2, 0
_08020BF0: .4byte gUnknown_203B27C
_08020BF4:
	bl sub_8021178
	lsls r0, 24
	cmp r0, 0
	beq _08020C06
	movs r0, 0x1B
	bl sub_801FDA8
	b _08020C24
_08020C06:
	movs r0, 0x14
	bl sub_801FDA8
	b _08020C24
_08020C0E:
	movs r0, 0x1E
	bl sub_801FDA8
	b _08020C24
_08020C16:
	movs r0, 0x12
	bl sub_801FDA8
	b _08020C24
_08020C1E:
	movs r0, 0x13
	bl sub_801FDA8
_08020C24:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020B38

	thumb_func_start sub_8020C2C
sub_8020C2C:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08020C44
	cmp r0, 0x3
	bhi _08020C44
	bl sub_802453C
	movs r0, 0x10
	bl sub_801FDA8
_08020C44:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C2C

	thumb_func_start sub_8020C48
sub_8020C48:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08020C60
	cmp r0, 0x3
	bhi _08020C60
	bl sub_801BF98
	movs r0, 0x10
	bl sub_801FDA8
_08020C60:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C48

	thumb_func_start sub_8020C64
sub_8020C64:
	push {lr}
	movs r0, 0x1
	bl sub_801F520
	cmp r0, 0x3
	beq _08020C80
	cmp r0, 0x3
	bhi _08020C7A
	cmp r0, 0x2
	beq _08020CB0
	b _08020CBA
_08020C7A:
	cmp r0, 0x4
	beq _08020C98
	b _08020CBA
_08020C80:
	bl sub_801F5B4
	ldr r1, _08020C94
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x17
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020C94: .4byte gUnknown_203B27C
_08020C98:
	bl sub_801F5B4
	ldr r1, _08020CAC
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x18
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020CAC: .4byte gUnknown_203B27C
_08020CB0:
	bl sub_801F63C
	movs r0, 0x10
	bl sub_801FDA8
_08020CBA:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C64

	thumb_func_start sub_8020CC0
sub_8020CC0:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801F520
	ldr r4, _08020D00
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020CF0
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020CF0
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08020CF0:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08020D14
	cmp r0, 0x3
	bgt _08020D04
	cmp r0, 0x1
	beq _08020D0C
	b _08020D6C
	.align 2, 0
_08020D00: .4byte gUnknown_203B27C
_08020D04:
	cmp r0, 0xB
	beq _08020D66
	cmp r0, 0x11
	bne _08020D6C
_08020D0C:
	movs r0, 0x16
	bl sub_801FDA8
	b _08020D6C
_08020D14:
	bl sub_801F63C
	ldr r4, _08020D30
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_809401C
	movs r5, 0
	adds r6, r4, 0
	movs r4, 0x24
	b _08020D38
	.align 2, 0
_08020D30: .4byte gUnknown_203B27C
_08020D34:
	adds r4, 0x8
	adds r5, 0x1
_08020D38:
	cmp r5, 0x7
	bgt _08020D52
	ldr r3, [r6]
	adds r2, r3, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08020D34
	ldrh r1, [r3, 0x1E]
	adds r0, r2, 0
	bl InitZeroedPPPokemonMove
_08020D52:
	cmp r5, 0x3
	ble _08020D5E
	movs r0, 0x1D
	bl sub_801FDA8
	b _08020D6C
_08020D5E:
	movs r0, 0x19
	bl sub_801FDA8
	b _08020D6C
_08020D66:
	movs r0, 0x18
	bl sub_801FDA8
_08020D6C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8020CC0

	thumb_func_start sub_8020D74
sub_8020D74:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08020D8C
	cmp r0, 0x3
	bhi _08020D8C
	bl sub_801F8D0
	movs r0, 0x16
	bl sub_801FDA8
_08020D8C:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D74

	thumb_func_start sub_8020D90
sub_8020D90:
	push {lr}
	bl sub_801E8C0
	cmp r0, 0x2
	beq _08020DBC
	cmp r0, 0x2
	bcc _08020DC6
	cmp r0, 0x3
	bne _08020DC6
	bl sub_801E930
	ldr r1, _08020DB8
	ldr r1, [r1]
	strb r0, [r1, 0x14]
	bl sub_801E93C
	movs r0, 0x1A
	bl sub_801FDA8
	b _08020DC6
	.align 2, 0
_08020DB8: .4byte gUnknown_203B27C
_08020DBC:
	bl sub_801E93C
	movs r0, 0x10
	bl sub_801FDA8
_08020DC6:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D90

	thumb_func_start sub_8020DCC
sub_8020DCC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08020EAA
	lsls r0, 2
	ldr r1, _08020DE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020DE4: .4byte _08020DE8
	.align 2, 0
_08020DE8:
	.4byte _08020EAA
	.4byte _08020E98
	.4byte _08020E64
	.4byte _08020DFC
	.4byte _08020E30
_08020DFC:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E0E
	ldr r0, _08020E2C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E0E:
	bl sub_801F194
	ldr r1, _08020E2C
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x20
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E2C: .4byte gUnknown_203B27C
_08020E30:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E42
	ldr r0, _08020E60
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E42:
	bl sub_801F194
	ldr r1, _08020E60
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x21
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E60: .4byte gUnknown_203B27C
_08020E64:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E76
	ldr r0, _08020E94
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E76:
	bl sub_801F214
	ldr r0, _08020E94
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	movs r0, 0x10
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E94: .4byte gUnknown_203B27C
_08020E98:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020EAA
	ldr r0, _08020EB0
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020EAA:
	pop {r0}
	bx r0
	.align 2, 0
_08020EB0: .4byte gUnknown_203B27C
	thumb_func_end sub_8020DCC

	thumb_func_start sub_8020EB4
sub_8020EB4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801EF38
	ldr r4, _08020EF8
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020EE4
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020EE4
	ldr r0, [r4]
	str r1, [r0, 0x78]
_08020EE4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bls _08020EEE
	b _080210BE
_08020EEE:
	lsls r0, 2
	ldr r1, _08020EFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020EF8: .4byte gUnknown_203B27C
_08020EFC: .4byte _08020F00
	.align 2, 0
_08020F00:
	.4byte _08021068
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08020F44
	.4byte _08020F70
	.4byte _08020F8C
	.4byte _08020FB8
	.4byte _08021034
	.4byte _08021074
	.4byte _080210B8
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08021068
_08020F44:
	ldr r0, _08020F60
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80934DC
	lsls r0, 24
	cmp r0, 0
	beq _08020F68
	ldr r0, _08020F64
	bl PlaySound
	b _08021068
	.align 2, 0
_08020F60: .4byte gUnknown_203B27C
_08020F64: .4byte 0x00000133
_08020F68:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _08021068
_08020F70:
	ldr r0, _08020F84
	bl PlaySound
	ldr r0, _08020F88
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_809352C
	b _08021068
	.align 2, 0
_08020F84: .4byte 0x00000133
_08020F88: .4byte gUnknown_203B27C
_08020F8C:
	ldr r0, _08020FA8
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093544
	lsls r0, 24
	cmp r0, 0
	beq _08020FB0
	ldr r0, _08020FAC
	bl PlaySound
	b _08021068
	.align 2, 0
_08020FA8: .4byte gUnknown_203B27C
_08020FAC: .4byte 0x00000133
_08020FB0:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _08021068
_08020FB8:
	ldr r0, _08020FD8
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x95
	bgt _08020FDC
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x3
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FD8: .4byte gTeamInventory_203B460
_08020FDC:
	ldr r4, _08020FFC
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093318
	lsls r0, 24
	cmp r0, 0
	bne _08021000
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x4
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FFC: .4byte gUnknown_203B27C
_08021000:
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	cmp r0, 0
	bne _08021016
	movs r0, 0x1
	strb r0, [r1, 0x15]
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySound
	b _0802101C
_08021016:
	ldr r0, _0802102C
	bl PlaySound
_0802101C:
	ldr r0, _08021030
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093400
	b _08021068
	.align 2, 0
_0802102C: .4byte 0x00000133
_08021030: .4byte gUnknown_203B27C
_08021034:
	ldr r4, _08021054
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_809333C
	lsls r0, 24
	cmp r0, 0
	bne _08021058
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x5
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021054: .4byte gUnknown_203B27C
_08021058:
	ldr r0, _08021070
	bl PlaySound
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093468
_08021068:
	movs r0, 0x1F
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021070: .4byte 0x00000133
_08021074:
	ldr r4, _08021094
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80933A0
	lsls r0, 24
	cmp r0, 0
	bne _08021098
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x6
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021094: .4byte gUnknown_203B27C
_08021098:
	ldr r0, _080210B4
	bl PlaySound
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80934B0
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	movs r0, 0x22
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_080210B4: .4byte 0x00000133
_080210B8:
	movs r0, 0x21
	bl sub_801FDA8
_080210BE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020EB4

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
	bl sub_8093CF8
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
	bl sprintf_2
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
	bl sprintf_2
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

	thumb_func_start sub_8021664
sub_8021664:
	push {r4-r6,lr}
	movs r5, 0
	ldr r1, _0802167C
	ldr r0, [r1]
	ldr r0, [r0, 0x3C]
	cmp r0, 0x1
	beq _08021692
	cmp r0, 0x1
	bcc _08021680
	cmp r0, 0x2
	beq _080216B4
	b _080216F2
	.align 2, 0
_0802167C: .4byte gUnknown_203B280
_08021680:
	movs r4, 0x1
_08021682:
	ldr r0, [r1]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021682
	b _080216F2
_08021692:
	movs r4, 0x1
	ldr r2, _080216B0
_08021696:
	ldr r0, [r2]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080216A8
	ldr r0, [r1]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_080216A8:
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021696
	b _080216F2
	.align 2, 0
_080216B0: .4byte gFriendAreas
_080216B4:
	movs r4, 0x1
	adds r6, r1, 0
_080216B8:
	ldr r0, _080216FC
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080216EC
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetFriendAreaUnlockCondition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080216E4
	cmp r0, 0x1
	bne _080216EC
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080216EC
_080216E4:
	ldr r0, [r6]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_080216EC:
	adds r4, 0x1
	cmp r4, 0x39
	ble _080216B8
_080216F2:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080216FC: .4byte gFriendAreas
	thumb_func_end sub_8021664

	thumb_func_start sub_8021700
sub_8021700:
	push {r4,lr}
	cmp r0, 0x1
	beq _08021710
	cmp r0, 0x1
	bcc _08021754
	cmp r0, 0x2
	beq _0802172C
	b _0802176A
_08021710:
	movs r4, 0x1
	ldr r0, _08021728
	ldr r1, [r0]
_08021716:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08021754
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021716
	b _0802176A
	.align 2, 0
_08021728: .4byte gFriendAreas
_0802172C:
	movs r4, 0x1
_0802172E:
	ldr r0, _08021750
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08021764
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetFriendAreaUnlockCondition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08021754
	cmp r0, 0x1
	beq _08021758
	b _08021764
	.align 2, 0
_08021750: .4byte gFriendAreas
_08021754:
	movs r0, 0
	b _0802176C
_08021758:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08021754
_08021764:
	adds r4, 0x1
	cmp r4, 0x39
	ble _0802172E
_0802176A:
	movs r0, 0x1
_0802176C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8021700

        thumb_func_start sub_8021774
sub_8021774:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, _080217E4
	movs r0, 0xE0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	strb r5, [r0, 0xD]
	ldr r0, [r6]
	bl sub_801317C
	bl sub_8021A60
	ldr r0, [r6]
	mov r1, r8
	str r1, [r0, 0x74]
	lsls r1, 1
	add r1, r8
	lsls r1, 3
	adds r1, 0x7C
	adds r1, r0, r1
	str r1, [r0, 0x78]
	adds r0, 0x7C
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x74]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x7C
	ldr r0, _080217E8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8021820
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080217E4: .4byte gUnknown_203B28C
_080217E8: .4byte gUnknown_80DC4D8
	thumb_func_end sub_8021774

	thumb_func_start sub_80217EC
sub_80217EC:
	push {lr}
	ldr r0, _0802180C
	ldr r0, [r0]
	ldr r1, [r0, 0x74]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08021810
	cmp r0, 0x2
	bne _0802181A
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802181C
	.align 2, 0
_0802180C: .4byte gUnknown_203B28C
_08021810:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802181C
_0802181A:
	movs r0, 0
_0802181C:
	pop {r1}
	bx r1
	thumb_func_end sub_80217EC

	thumb_func_start sub_8021820
sub_8021820:
	push {lr}
	bl sub_8021878
	bl sub_8021894
	pop {r0}
	bx r0
	thumb_func_end sub_8021820

	thumb_func_start sub_8021830
sub_8021830:
	push {r4,r5,lr}
	ldr r4, _08021870
	ldr r2, [r4]
	cmp r2, 0
	beq _0802186A
	ldr r0, [r2, 0x74]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7C
	ldr r0, _08021874
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
_0802186A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021870: .4byte gUnknown_203B28C
_08021874: .4byte gUnknown_80DC4BC
	thumb_func_end sub_8021830

	thumb_func_start sub_8021878
sub_8021878:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08021890
	ldr r0, [r0]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08021890: .4byte gUnknown_203B28C
	thumb_func_end sub_8021878

	thumb_func_start sub_8021894
sub_8021894:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x168
	ldr r4, _080218F8
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	add r0, sp, 0x4
	movs r2, 0
	bl sub_8092578
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r5, 0
	str r5, [sp]
	movs r0, 0x14
	movs r1, 0
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl GetFriendAreaDescription
	adds r2, r0, 0
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	str r5, [sp]
	movs r0, 0xA
	movs r1, 0x14
	bl xxx_call_draw_string
	ldr r4, [r4]
	ldrb r0, [r4, 0xD]
	cmp r0, 0
	beq _08021900
	ldr r2, _080218FC
	ldr r3, [r4, 0x74]
	str r5, [sp]
	movs r0, 0x20
	movs r1, 0x3C
	bl xxx_call_draw_string
	b _0802190E
	.align 2, 0
_080218F8: .4byte gUnknown_203B28C
_080218FC: .4byte gUnknown_80DC4F0
_08021900:
	ldr r2, _0802193C
	ldr r3, [r4, 0x74]
	str r0, [sp]
	movs r0, 0x20
	movs r1, 0x3C
	bl xxx_call_draw_string
_0802190E:
	ldr r4, _08021940
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	movs r5, 0x4
	str r5, [sp]
	movs r1, 0x4
	movs r2, 0x40
	movs r3, 0x14
	bl sub_800792C
	ldr r4, [r4]
	ldrb r0, [r4, 0xD]
	cmp r0, 0
	beq _08021944
	ldr r0, [r4, 0x74]
	str r5, [sp]
	movs r1, 0xB8
	movs r2, 0x40
	movs r3, 0x14
	bl sub_800792C
	b _08021952
	.align 2, 0
_0802193C: .4byte gUnknown_80DC518
_08021940: .4byte gUnknown_203B28C
_08021944:
	ldr r0, [r4, 0x74]
	str r5, [sp]
	movs r1, 0x5E
	movs r2, 0x40
	movs r3, 0x6E
	bl sub_800792C
_08021952:
	ldr r5, _080219E8
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	movs r4, 0x4
	str r4, [sp]
	movs r1, 0x4
	movs r2, 0x82
	movs r3, 0xC8
	bl sub_800792C
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	str r4, [sp]
	movs r1, 0x3
	movs r2, 0x40
	movs r3, 0x43
	bl sub_8007A78
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	str r4, [sp]
	movs r1, 0xCC
	movs r2, 0x40
	movs r3, 0x43
	bl sub_8007A78
	movs r6, 0
	ldr r0, [r5]
	ldr r0, [r0, 0x70]
	cmp r6, r0
	bge _08021A40
	add r7, sp, 0x104
	mov r8, r5
	mov r9, r6
_08021996:
	adds r0, r6, 0
	movs r1, 0x3
	bl __modsi3
	lsls r1, r0, 6
	subs r1, r0
	adds r5, r1, 0x7
	adds r0, r6, 0
	movs r1, 0x3
	bl __divsi3
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r4, r1, 0
	adds r4, 0x47
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r6, 1
	adds r0, 0xE
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_808D930
	mov r0, r8
	ldr r3, [r0]
	lsls r1, r6, 2
	adds r0, r3, 0
	adds r0, 0x30
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	beq _08021A04
	cmp r0, 0x1
	bcc _080219EC
	cmp r0, 0x2
	beq _08021A16
	b _08021A34
	.align 2, 0
_080219E8: .4byte gUnknown_203B28C
_080219EC:
	ldr r0, _08021A00
	ldr r2, [r0]
	ldr r3, [r3, 0x74]
	mov r1, r9
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	bl xxx_call_draw_string
	b _08021A34
	.align 2, 0
_08021A00: .4byte gUnknown_80D49BC
_08021A04:
	ldr r3, [r3, 0x74]
	mov r2, r9
	str r2, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl xxx_call_draw_string
	b _08021A34
_08021A16:
	add r0, sp, 0x4
	ldr r1, _08021A58
	adds r2, r7, 0
	bl sprintf_2
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x74]
	mov r2, r9
	str r2, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	add r2, sp, 0x4
	bl xxx_call_draw_string
_08021A34:
	adds r6, 0x1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x70]
	cmp r6, r0
	blt _08021996
_08021A40:
	ldr r0, _08021A5C
	ldr r0, [r0]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	add sp, 0x168
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021A58: .4byte gUnknown_80DC524
_08021A5C: .4byte gUnknown_203B28C
	thumb_func_end sub_8021894

	thumb_func_start sub_8021A60
sub_8021A60:
	push {r4-r7,lr}
	ldr r2, _08021B4C
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x70]
	movs r6, 0
	adds r4, r2, 0
	movs r3, 0
_08021A70:
	ldr r1, [r4]
	lsls r2, r6, 1
	adds r0, r1, 0
	adds r0, 0xE
	adds r0, r2
	strh r3, [r0]
	lsls r0, r6, 2
	adds r1, 0x30
	adds r1, r0
	str r3, [r1]
	adds r6, 0x1
	cmp r6, 0xF
	ble _08021A70
	movs r6, 0
	ldr r7, _08021B4C
_08021A8E:
	lsls r0, r6, 16
	asrs r5, r0, 16
	ldr r4, [r7]
	adds r0, r5, 0
	bl GetFriendArea
	ldrb r1, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _08021AC4
	adds r0, r5, 0
	bl GetBaseSpeciesNoUnown
	lsls r0, 16
	asrs r0, 16
	cmp r5, r0
	bne _08021AC4
	ldr r3, [r7]
	ldr r1, [r3, 0x70]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0xE
	adds r0, r2
	strh r5, [r0]
	adds r1, 0x1
	str r1, [r3, 0x70]
_08021AC4:
	adds r6, 0x1
	ldr r0, _08021B50
	cmp r6, r0
	ble _08021A8E
	movs r6, 0
_08021ACE:
	lsls r0, r6, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _08021AFC
	adds r0, r4, 0
	bl sub_8021B58
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08021AFC
	ldr r0, _08021B4C
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, 0x30
	adds r1, r0
	movs r0, 0x1
	str r0, [r1]
_08021AFC:
	adds r6, 0x1
	ldr r0, _08021B50
	cmp r6, r0
	ble _08021ACE
	movs r6, 0
	ldr r4, _08021B54
_08021B08:
	movs r0, 0x58
	adds r1, r6, 0
	muls r1, r0
	ldr r0, [r4]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08021B3C
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl sub_8021B58
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08021B3C
	ldr r0, _08021B4C
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, 0x30
	adds r1, r0
	movs r0, 0x2
	str r0, [r1]
_08021B3C:
	adds r6, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r6, r0
	ble _08021B08
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021B4C: .4byte gUnknown_203B28C
_08021B50: .4byte 0x000001a7
_08021B54: .4byte gRecruitedPokemonRef
	thumb_func_end sub_8021A60

	thumb_func_start sub_8021B58
sub_8021B58:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r0, 16
	bl GetBaseSpeciesNoUnown
	lsls r0, 16
	asrs r4, r0, 16
	movs r2, 0
	ldr r0, _08021B84
	ldr r0, [r0]
	ldr r1, [r0, 0x70]
	cmp r2, r1
	bge _08021B90
	adds r3, r1, 0
	adds r1, r0, 0
	adds r1, 0xE
_08021B78:
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r4, r0
	bne _08021B88
	adds r0, r2, 0
	b _08021B94
	.align 2, 0
_08021B84: .4byte gUnknown_203B28C
_08021B88:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _08021B78
_08021B90:
	movs r0, 0x1
	negs r0, r0
_08021B94:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8021B58

	thumb_func_start CreateWigglytuffShop
CreateWigglytuffShop:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08021BF8
	movs r0, 0x9C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	str r6, [r0, 0x14]
	str r6, [r0, 0x18]
	str r4, [r0]
	ldr r0, _08021BFC
	movs r1, 0x28
	bl CopyYellowSpeciesNametoBuffer
	ldr r4, _08021C00
	adds r0, r4, 0
	movs r1, 0x28
	bl CopyYellowSpeciesNametoBuffer
	movs r0, 0x28
	bl GetMonSpecies
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r5, [r5]
	ldr r0, [r5]
	cmp r0, 0x1
	bne _08021C04
	adds r0, r5, 0
	adds r0, 0xCC
	str r6, [r0]
	b _08021C0E
	.align 2, 0
_08021BF8: .4byte gUnknown_203B290
_08021BFC: .4byte gUnknown_202E5D8
_08021C00: .4byte gUnknown_202E1C8
_08021C04:
	adds r1, r5, 0
	adds r1, 0xCC
	adds r0, r5, 0
	adds r0, 0xBC
	str r0, [r1]
_08021C0E:
	movs r0, 0x28
	bl GetDialogueSpriteDataPtr
	ldr r2, _08021C58
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0xBC
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xC8
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xC9
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xCA
	strb r1, [r0]
	ldr r1, [r2]
	adds r2, r1, 0
	adds r2, 0xC4
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0xC6
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_8021D44
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08021C58: .4byte gUnknown_203B290
	thumb_func_end CreateWigglytuffShop

	thumb_func_start sub_8021C5C
sub_8021C5C:
	push {lr}
	ldr r0, _08021C74
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x17
	bhi _08021D10
	lsls r0, 2
	ldr r1, _08021C78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021C74: .4byte gUnknown_203B290
_08021C78: .4byte _08021C7C
	.align 2, 0
_08021C7C:
	.4byte _08021CDC
	.4byte _08021CDC
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D0C
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021CE2
	.4byte _08021CE2
	.4byte _08021CE8
	.4byte _08021D10
	.4byte _08021CF4
	.4byte _08021CFA
	.4byte _08021D10
	.4byte _08021D00
	.4byte _08021CEE
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D06
	.4byte _08021D06
_08021CDC:
	bl sub_8022460
	b _08021D14
_08021CE2:
	bl sub_8022538
	b _08021D14
_08021CE8:
	bl sub_80225C8
	b _08021D14
_08021CEE:
	bl sub_80224D4
	b _08021D14
_08021CF4:
	bl sub_80226F0
	b _08021D14
_08021CFA:
	bl sub_8022790
	b _08021D14
_08021D00:
	bl sub_8022668
	b _08021D14
_08021D06:
	bl sub_8022684
	b _08021D14
_08021D0C:
	movs r0, 0x3
	b _08021D16
_08021D10:
	bl sub_80226CC
_08021D14:
	movs r0, 0
_08021D16:
	pop {r1}
	bx r1
	thumb_func_end sub_8021C5C

	thumb_func_start sub_8021D1C
sub_8021D1C:
	push {r4,lr}
	ldr r4, _08021D40
	ldr r0, [r4]
	cmp r0, 0
	beq _08021D38
	adds r0, 0xBC
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08021D38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021D40: .4byte gUnknown_203B290
	thumb_func_end sub_8021D1C

	thumb_func_start sub_8021D44
sub_8021D44:
	push {lr}
	ldr r1, _08021D58
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_8021D5C
	bl UpdateWigglytuffDialogue
	pop {r0}
	bx r0
	.align 2, 0
_08021D58: .4byte gUnknown_203B290
	thumb_func_end sub_8021D44

	thumb_func_start sub_8021D5C
sub_8021D5C:
	push {r4-r7,lr}
	ldr r4, _08021D7C
	ldr r0, [r4]
	adds r0, 0xD0
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x9
	blt _08021DC8
	cmp r0, 0xA
	ble _08021D80
	cmp r0, 0xB
	beq _08021DB0
	b _08021DC8
	.align 2, 0
_08021D7C: .4byte gUnknown_203B290
_08021D80:
	ldr r2, _08021DA8
	adds r1, 0xD0
	adds r0, r2, 0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldr r0, [r4]
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6
	ldm r2!, {r1,r3,r7}
	stm r0!, {r1,r3,r7}
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	ldr r1, [r4]
	adds r1, 0xE8
	ldr r0, _08021DAC
	b _08021DB8
	.align 2, 0
_08021DA8: .4byte gUnknown_80DC534
_08021DAC: .4byte gUnknown_80DC564
_08021DB0:
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0
	ldr r0, _08021DC4
_08021DB8:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _08021DEC
	.align 2, 0
_08021DC4: .4byte gUnknown_80DC54C
_08021DC8:
	ldr r0, _08021E04
	mov r12, r0
	ldr r4, _08021E08
	movs r3, 0
	movs r2, 0x3
_08021DD2:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0xD0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08021DD2
_08021DEC:
	bl ResetUnusedInputStruct
	ldr r0, _08021E04
	ldr r0, [r0]
	adds r0, 0xD0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021E04: .4byte gUnknown_203B290
_08021E08: .4byte gUnknown_80DC534
	thumb_func_end sub_8021D5C

	thumb_func_start UpdateWigglytuffDialogue
UpdateWigglytuffDialogue:
	push {r4,lr}
	sub sp, 0x20
	ldr r1, _08021E28
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x1C
	bls _08021E1E
	b _080222B6
_08021E1E:
	lsls r0, 2
	ldr r1, _08021E2C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021E28: .4byte gUnknown_203B290
_08021E2C: .4byte _08021E30
	.align 2, 0
_08021E30:
	.4byte _08021EA4
	.4byte _08021EC0
	.4byte _08021F38
	.4byte _08021F50
	.4byte _080222B6
	.4byte _08021F78
	.4byte _08021F90
	.4byte _08021F08
	.4byte _08021F20
	.4byte _08021FD8
	.4byte _08021FE2
	.4byte _08021FF0
	.4byte _0802208E
	.4byte _080220B8
	.4byte _080220D8
	.4byte _080220EA
	.4byte _08022080
	.4byte _08022024
	.4byte _08021FA8
	.4byte _08021FC0
	.4byte _08022138
	.4byte _08022150
	.4byte _08022168
	.4byte _08022176
	.4byte _0802217E
	.4byte _08022238
	.4byte _08022250
	.4byte _08022268
	.4byte _08022294
_08021EA4:
	bl sub_80222C8
	ldr r2, _08021EB8
	ldr r0, _08021EBC
	ldr r4, [r0]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	b _08021ED4
	.align 2, 0
_08021EB8: .4byte gWigglytuffDialogue
_08021EBC: .4byte gUnknown_203B290
_08021EC0:
	bl sub_80222C8
	ldr r2, _08021F00
	ldr r0, _08021F04
	ldr r4, [r0]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4
_08021ED4:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r4, 0x14]
	adds r3, r4, 0
	adds r3, 0x1C
	adds r1, r4, 0
	adds r1, 0x5C
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r1, r4, 0
	adds r1, 0xCC
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080222B6
	.align 2, 0
_08021F00: .4byte gWigglytuffDialogue
_08021F04: .4byte gUnknown_203B290
_08021F08:
	ldr r3, [r4]
	movs r0, 0x9
	str r0, [r3, 0x8]
	ldr r2, _08021F1C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0xC
	b _0802227A
	.align 2, 0
_08021F1C: .4byte gWigglytuffDialogue
_08021F20:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021F34
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x10
	b _0802227A
	.align 2, 0
_08021F34: .4byte gWigglytuffDialogue
_08021F38:
	ldr r3, [r4]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08021F4C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4C
	b _0802227A
	.align 2, 0
_08021F4C: .4byte gWigglytuffDialogue
_08021F50:
	ldr r3, [r4]
	movs r0, 0x4
	str r0, [r3, 0x8]
	ldr r2, _08021F70
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
	ldr r3, _08021F74
	b _08022284
	.align 2, 0
_08021F70: .4byte gWigglytuffDialogue
_08021F74: .4byte 0x0000030d
_08021F78:
	ldr r3, [r4]
	movs r0, 0x3
	str r0, [r3, 0x8]
	ldr r2, _08021F8C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x20
	b _0802227A
	.align 2, 0
_08021F8C: .4byte gWigglytuffDialogue
_08021F90:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021FA4
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x24
	b _0802227A
	.align 2, 0
_08021FA4: .4byte gWigglytuffDialogue
_08021FA8:
	ldr r3, [r4]
	movs r0, 0x3
	str r0, [r3, 0x8]
	ldr r2, _08021FBC
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x28
	b _0802227A
	.align 2, 0
_08021FBC: .4byte gWigglytuffDialogue
_08021FC0:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021FD4
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x2C
	b _0802227A
	.align 2, 0
_08021FD4: .4byte gWigglytuffDialogue
_08021FD8:
	movs r0, 0x2
	movs r1, 0x3
	bl sub_80211AC
	b _08021FE8
_08021FE2:
	movs r0, 0x1
	bl sub_8021354
_08021FE8:
	movs r0, 0x1
	bl DrawTeamMoneyBox
	b _080222B6
_08021FF0:
	bl sub_8021494
	movs r0, 0x1
	bl DrawTeamMoneyBox
	bl sub_8022380
	ldr r0, _08022020
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0x1C
	adds r3, r2, 0
	adds r3, 0x5C
	ldr r2, [r2, 0x18]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080222B6
	.align 2, 0
_08022020: .4byte gUnknown_203B290
_08022024:
	bl sub_8022420
	ldr r0, _08022070
	ldr r4, _08022074
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r1, _08022078
	ldr r4, [r4]
	ldr r0, [r4, 0xC]
	str r0, [r1]
	ldr r2, _0802207C
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x14
	adds r0, r2
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x1C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	adds r4, 0xCC
	ldr r1, [r4]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _080222B6
	.align 2, 0
_08022070: .4byte gUnknown_202E628
_08022074: .4byte gUnknown_203B290
_08022078: .4byte gUnknown_202DE30
_0802207C: .4byte gWigglytuffDialogue
_08022080:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	movs r1, 0
	movs r2, 0x2
	bl sub_8021774
	b _080222B6
_0802208E:
	ldr r1, [r4]
	movs r0, 0xD
	str r0, [r1, 0x8]
	ldr r0, _080220B0
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r2, _080220B4
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x18
	b _0802227A
	.align 2, 0
_080220B0: .4byte gUnknown_202E628
_080220B4: .4byte gWigglytuffDialogue
_080220B8:
	ldr r1, [r4]
	movs r0, 0xE
	str r0, [r1, 0x8]
	ldr r0, _080220D4
	bl PlaySound
	ldr r0, [r4]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	b _080222B6
	.align 2, 0
_080220D4: .4byte 0x0000025b
_080220D8:
	ldr r0, [r4]
	movs r1, 0xF
	str r1, [r0, 0x8]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1E
	str r1, [r0]
	b _080222B6
_080220EA:
	movs r0, 0x2
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _08022108
	bl sub_80213A0
	ldr r0, _08022104
	ldr r1, [r0]
	movs r0, 0x12
	b _0802210E
	.align 2, 0
_08022104: .4byte gUnknown_203B290
_08022108:
	ldr r0, _08022130
	ldr r1, [r0]
	movs r0, 0x8
_0802210E:
	str r0, [r1, 0x8]
	movs r0, 0xCE
	bl PlaySound
	ldr r3, _08022134
	ldr r0, _08022130
	ldr r2, [r0]
	ldr r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r3, 0x1C
	adds r0, r3
	ldr r0, [r0]
	adds r2, 0xCC
	ldr r2, [r2]
	b _08022282
	.align 2, 0
_08022130: .4byte gUnknown_203B290
_08022134: .4byte gWigglytuffDialogue
_08022138:
	ldr r3, [r4]
	movs r0, 0x16
	str r0, [r3, 0x8]
	ldr r2, _0802214C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x30
	b _0802227A
	.align 2, 0
_0802214C: .4byte gWigglytuffDialogue
_08022150:
	ldr r3, [r4]
	movs r0, 0x17
	str r0, [r3, 0x8]
	ldr r2, _08022164
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x34
	b _0802227A
	.align 2, 0
_08022164: .4byte gWigglytuffDialogue
_08022168:
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_8023144
	b _080222B6
_08022176:
	movs r0, 0x1
	bl sub_8023354
	b _080222B6
_0802217E:
	ldr r4, _080221A0
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	add r1, sp, 0x14
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	add r0, sp, 0x14
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080221A4
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x8]
	b _080221FA
	.align 2, 0
_080221A0: .4byte gUnknown_203B290
_080221A4:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl GetFriendAreaUnlockCondition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080221E0
	cmp r0, 0x2
	bgt _080221BE
	cmp r0, 0x1
	beq _080221C4
	b _080221F0
_080221BE:
	cmp r0, 0x3
	beq _080221E8
	b _080221F0
_080221C4:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080221D8
	ldr r1, [r4]
	movs r0, 0x15
	str r0, [r1, 0x8]
	b _080221FA
_080221D8:
	ldr r1, [r4]
	movs r0, 0x1A
	str r0, [r1, 0x8]
	b _080221FA
_080221E0:
	ldr r1, [r4]
	movs r0, 0x1B
	str r0, [r1, 0x8]
	b _080221FA
_080221E8:
	ldr r1, [r4]
	movs r0, 0x1C
	str r0, [r1, 0x8]
	b _080221FA
_080221F0:
	ldr r2, _08022228
	ldr r1, [r2]
	movs r0, 0x15
	str r0, [r1, 0x8]
	adds r4, r2, 0
_080221FA:
	ldr r0, [r4]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0802222C
	bl strcpy
	ldr r0, _08022230
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r2, _08022234
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x38
	b _0802227A
	.align 2, 0
_08022228: .4byte gUnknown_203B290
_0802222C: .4byte gAvailablePokemonNames
_08022230: .4byte gUnknown_202E628
_08022234: .4byte gWigglytuffDialogue
_08022238:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _0802224C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x3C
	b _0802227A
	.align 2, 0
_0802224C: .4byte gWigglytuffDialogue
_08022250:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _08022264
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x40
	b _0802227A
	.align 2, 0
_08022264: .4byte gWigglytuffDialogue
_08022268:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _0802228C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x44
_0802227A:
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
_08022282:
	ldr r3, _08022290
_08022284:
	movs r1, 0
	bl sub_80141B4
	b _080222B6
	.align 2, 0
_0802228C: .4byte gWigglytuffDialogue
_08022290: .4byte 0x0000010d
_08022294:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _080222C0
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x48
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
	ldr r3, _080222C4
	movs r1, 0
	bl sub_80141B4
_080222B6:
	add sp, 0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080222C0: .4byte gWigglytuffDialogue
_080222C4: .4byte 0x0000010d
	thumb_func_end UpdateWigglytuffDialogue

	thumb_func_start sub_80222C8
sub_80222C8:
	push {r4-r7,lr}
	ldr r4, _08022344
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r5, 0
	ldr r0, _08022348
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	adds r3, r1, 0
	adds r3, 0x20
	movs r0, 0x2
	str r0, [r1, 0x20]
	movs r2, 0x1
	ldr r0, _0802234C
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x3
	str r0, [r1, 0x28]
	ldr r0, _08022350
	ldr r0, [r0]
	str r0, [r1, 0x2C]
	movs r0, 0x4
	str r0, [r1, 0x30]
	ldr r0, _08022354
	ldr r0, [r0]
	str r0, [r1, 0x34]
	str r2, [r1, 0x38]
	movs r7, 0x4
	str r5, [r1, 0x3C]
	str r2, [r3, 0x20]
	adds r6, r1, 0
	adds r2, r6, 0
	adds r2, 0x5C
_08022314:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08022322
	ldr r1, [r3]
	ldr r0, [r6, 0x14]
	cmp r1, r0
	beq _0802237A
_08022322:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r7
	blt _08022314
	movs r5, 0
	cmp r5, r7
	bge _0802237A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08022358
	ldr r0, [r1, 0x20]
	str r0, [r1, 0x14]
	b _0802237A
	.align 2, 0
_08022344: .4byte gUnknown_203B290
_08022348: .4byte gUnknown_80D4978
_0802234C: .4byte gWigglytuffCheck
_08022350: .4byte gUnknown_80D4970
_08022354: .4byte gUnknown_80D4934
_08022358:
	adds r5, 0x1
	cmp r5, r7
	bge _0802237A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x5C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08022358
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_0802237A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80222C8

	thumb_func_start sub_8022380
sub_8022380:
	push {r4-r7,lr}
	ldr r4, _080223EC
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080223F0
	ldr r0, [r0]
	str r0, [r3, 0x1C]
	movs r0, 0x2
	str r0, [r3, 0x20]
	movs r1, 0x1
	ldr r0, _080223F4
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x4
	str r0, [r3, 0x28]
	movs r6, 0x2
	str r2, [r3, 0x2C]
	str r1, [r3, 0x30]
	movs r5, 0
	mov r12, r3
	adds r3, 0x20
	mov r2, r12
	adds r2, 0x5C
_080223BA:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080223CA
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _0802241A
_080223CA:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080223BA
	movs r5, 0
	cmp r5, r6
	bge _0802241A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrh r0, [r0]
	cmp r0, 0
	bne _080223F8
	ldr r0, [r1, 0x20]
	str r0, [r1, 0x18]
	b _0802241A
	.align 2, 0
_080223EC: .4byte gUnknown_203B290
_080223F0: .4byte gUnknown_80D4978
_080223F4: .4byte gUnknown_80D4970
_080223F8:
	adds r5, 0x1
	cmp r5, r6
	bge _0802241A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x5C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080223F8
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_0802241A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022380

	thumb_func_start sub_8022420
sub_8022420:
	push {r4,lr}
	ldr r4, _08022454
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _08022458
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	movs r0, 0x5
	str r0, [r1, 0x20]
	movs r2, 0x1
	ldr r0, _0802245C
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x6
	str r0, [r1, 0x28]
	str r3, [r1, 0x2C]
	str r2, [r1, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022454: .4byte gUnknown_203B290
_08022458: .4byte gUnknown_80D4920
_0802245C: .4byte gUnknown_80D4928
	thumb_func_end sub_8022420

	thumb_func_start sub_8022460
sub_8022460:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080224CC
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802247A
	ldr r0, _0802248C
	ldr r0, [r0]
	str r1, [r0, 0x14]
_0802247A:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802249A
	cmp r0, 0x2
	bgt _08022490
	cmp r0, 0x1
	beq _080224C6
	b _080224CC
	.align 2, 0
_0802248C: .4byte gUnknown_203B290
_08022490:
	cmp r0, 0x3
	beq _080224B6
	cmp r0, 0x4
	beq _080224BE
	b _080224CC
_0802249A:
	movs r0, 0x2
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _080224AE
	movs r0, 0x5
	bl sub_8021D44
	b _080224CC
_080224AE:
	movs r0, 0x7
	bl sub_8021D44
	b _080224CC
_080224B6:
	movs r0, 0x14
	bl sub_8021D44
	b _080224CC
_080224BE:
	movs r0, 0x2
	bl sub_8021D44
	b _080224CC
_080224C6:
	movs r0, 0x3
	bl sub_8021D44
_080224CC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8022460

	thumb_func_start sub_80224D4
sub_80224D4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08022532
	ldr r0, [sp]
	cmp r0, 0x5
	beq _080224F8
	cmp r0, 0x5
	bgt _080224F2
	cmp r0, 0x1
	beq _0802252C
	b _08022532
_080224F2:
	cmp r0, 0x6
	beq _0802252C
	b _08022532
_080224F8:
	ldr r0, _08022524
	ldr r2, [r0]
	movs r0, 0x98
	lsls r0, 2
	adds r2, r0
	ldr r0, _08022528
	ldr r3, [r0]
	ldr r0, [r2]
	ldr r1, [r3, 0xC]
	subs r0, r1
	str r0, [r2]
	ldrb r0, [r3, 0x10]
	bl UnlockFriendArea
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySound
	movs r0, 0xC
	bl sub_8021D44
	b _08022532
	.align 2, 0
_08022524: .4byte gTeamInventory_203B460
_08022528: .4byte gUnknown_203B290
_0802252C:
	movs r0, 0xA
	bl sub_8021D44
_08022532:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80224D4

	thumb_func_start sub_8022538
sub_8022538:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x4
	bhi _080225BC
	lsls r0, 2
	ldr r1, _08022550
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022550: .4byte _08022554
	.align 2, 0
_08022554:
	.4byte _080225C2
	.4byte _080225BC
	.4byte _080225B0
	.4byte _08022568
	.4byte _0802258C
_08022568:
	bl sub_802132C
	ldr r4, _08022588
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl GetFriendAreaPrice
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0xB
	bl sub_8021D44
	b _080225C2
	.align 2, 0
_08022588: .4byte gUnknown_203B290
_0802258C:
	bl sub_802132C
	ldr r4, _080225AC
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl GetFriendAreaPrice
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0x10
	bl sub_8021D44
	b _080225C2
	.align 2, 0
_080225AC: .4byte gUnknown_203B290
_080225B0:
	bl sub_80213A0
	movs r0, 0x1
	bl sub_8021D44
	b _080225C2
_080225BC:
	movs r0, 0x1
	bl DrawTeamMoneyBox
_080225C2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022538

	thumb_func_start sub_80225C8
sub_80225C8:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8021274
	ldr r4, _08022608
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080225F8
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080225F8
	ldr r0, [r4]
	str r1, [r0, 0x18]
_080225F8:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08022612
	cmp r0, 0x2
	bgt _0802260C
	cmp r0, 0x1
	beq _08022658
	b _0802265E
	.align 2, 0
_08022608: .4byte gUnknown_203B290
_0802260C:
	cmp r0, 0x4
	beq _08022650
	b _0802265E
_08022612:
	ldr r0, _0802262C
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08022630
	movs r0, 0x6
	bl sub_8021D44
	b _0802265E
	.align 2, 0
_0802262C: .4byte gTeamInventory_203B460
_08022630:
	ldr r0, _08022644
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	cmp r0, r1
	ble _08022648
	movs r0, 0x13
	bl sub_8021D44
	b _0802265E
	.align 2, 0
_08022644: .4byte gUnknown_203B290
_08022648:
	movs r0, 0x11
	bl sub_8021D44
	b _0802265E
_08022650:
	movs r0, 0x10
	bl sub_8021D44
	b _0802265E
_08022658:
	movs r0, 0xA
	bl sub_8021D44
_0802265E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80225C8

	thumb_func_start sub_8022668
sub_8022668:
	push {lr}
	bl sub_80217EC
	cmp r0, 0x1
	bls _08022680
	cmp r0, 0x3
	bhi _08022680
	bl sub_8021830
	movs r0, 0xA
	bl sub_8021D44
_08022680:
	pop {r0}
	bx r0
	thumb_func_end sub_8022668

	thumb_func_start sub_8022684
sub_8022684:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023278
	cmp r0, 0x2
	beq _080226BC
	cmp r0, 0x2
	bcc _080226C6
	cmp r0, 0x3
	bne _080226C6
	bl sub_802331C
	ldr r4, _080226B8
	ldr r1, [r4]
	strh r0, [r1, 0x12]
	movs r2, 0x12
	ldrsh r0, [r1, r2]
	bl GetFriendArea
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	movs r0, 0x18
	bl sub_8021D44
	b _080226C6
	.align 2, 0
_080226B8: .4byte gUnknown_203B290
_080226BC:
	bl sub_80233A0
	movs r0, 0x1
	bl sub_8021D44
_080226C6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022684

	thumb_func_start sub_80226CC
sub_80226CC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080226E4
	ldr r0, _080226EC
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8021D44
_080226E4:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080226EC: .4byte gUnknown_203B290
	thumb_func_end sub_80226CC

	thumb_func_start sub_80226F0
sub_80226F0:
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0
	movs r0, 0x80
	strb r0, [r1]
	strb r0, [r1, 0x1]
	movs r0, 0x10
	strb r0, [r1, 0x2]
	strb r2, [r1, 0x3]
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _08022782
	ldr r0, _08022728
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0802275C
	lsls r0, 2
	ldr r1, _0802272C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022728: .4byte gUnknown_203B290
_0802272C: .4byte _08022730
	.align 2, 0
_08022730:
	.4byte _0802275C
	.4byte _08022744
	.4byte _08022750
	.4byte _08022744
	.4byte _08022750
_08022744:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099AFC
	b _08022772
_08022750:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099A5C
	b _08022772
_0802275C:
	ldr r4, _0802278C
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	bl sub_8021D44
	ldr r0, [r4]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_08022772:
	ldr r0, _0802278C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 1
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08022782:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802278C: .4byte gUnknown_203B290
	thumb_func_end sub_80226F0

	thumb_func_start sub_8022790
sub_8022790:
	push {lr}
	ldr r0, _080227A8
	ldr r2, [r0]
	movs r0, 0x9A
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _080227AC
	subs r0, 0x1
	str r0, [r1]
	b _080227B2
	.align 2, 0
_080227A8: .4byte gUnknown_203B290
_080227AC:
	ldr r0, [r2, 0x8]
	bl sub_8021D44
_080227B2:
	pop {r0}
	bx r0
	thumb_func_end sub_8022790

	thumb_func_start sub_80227B8
sub_80227B8:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08022810
	movs r0, 0xD4
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	adds r2, r0, 0
	adds r2, 0xF4
	movs r1, 0
	str r1, [r2]
	str r5, [r0, 0x48]
	cmp r5, 0
	beq _08022820
	ldr r4, _08022814
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl PrintColoredPokeNameToBuffer
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x6
	bl PrintColoredPokeNameToBuffer
	bl HasGummiItem
	lsls r0, 24
	cmp r0, 0
	beq _08022818
	movs r0, 0
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022810: .4byte gUnknown_203B294
_08022814: .4byte gAvailablePokemonNames
_08022818:
	movs r0, 0x11
	bl sub_8022924
	b _08022856
_08022820:
	ldr r4, _08022848
	ldr r5, _0802284C
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _08022850
	movs r0, 0x12
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022848: .4byte gAvailablePokemonNames
_0802284C: .4byte gUnknown_80DC5EC
_08022850:
	movs r0, 0
	bl sub_8022924
_08022856:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80227B8

	thumb_func_start sub_8022860
sub_8022860:
	push {lr}
	ldr r0, _08022878
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x16
	bhi _080228FE
	lsls r0, 2
	ldr r1, _0802287C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022878: .4byte gUnknown_203B294
_0802287C: .4byte _08022880
	.align 2, 0
_08022880:
	.4byte _080228DC
	.4byte _080228DC
	.4byte _080228E2
	.4byte _080228E8
	.4byte _080228EE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228F4
	.4byte _080228FA
_080228DC:
	bl sub_8022E78
	b _08022902
_080228E2:
	bl sub_8022EF4
	b _08022902
_080228E8:
	bl sub_8023068
	b _08022902
_080228EE:
	bl sub_80230E8
	b _08022902
_080228F4:
	bl sub_8023104
	b _08022902
_080228FA:
	movs r0, 0x3
	b _08022904
_080228FE:
	bl sub_8023120
_08022902:
	movs r0, 0
_08022904:
	pop {r1}
	bx r1
	thumb_func_end sub_8022860

	thumb_func_start sub_8022908
sub_8022908:
	push {r4,lr}
	ldr r4, _08022920
	ldr r0, [r4]
	cmp r0, 0
	beq _0802291A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802291A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022920: .4byte gUnknown_203B294
	thumb_func_end sub_8022908

	thumb_func_start sub_8022924
sub_8022924:
	push {lr}
	ldr r1, _08022938
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802293C
	bl sub_8022A10
	pop {r0}
	bx r0
	.align 2, 0
_08022938: .4byte gUnknown_203B294
	thumb_func_end sub_8022924

	thumb_func_start sub_802293C
sub_802293C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08022964
	ldr r0, [r4]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _080229A4
	cmp r0, 0x3
	bgt _08022968
	cmp r0, 0x2
	beq _08022972
	b _080229BC
	.align 2, 0
_08022964: .4byte gUnknown_203B294
_08022968:
	cmp r0, 0x10
	bgt _080229BC
	cmp r0, 0xA
	blt _080229BC
	b _080229E6
_08022972:
	bl sub_8022D2C
	ldr r2, [r4]
	movs r0, 0xBC
	lsls r0, 1
	adds r2, r0
	ldr r1, _080229A0
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xF8
	bl sub_8012CAC
	ldr r0, [r4]
	movs r6, 0xC2
	lsls r6, 1
	adds r0, r6
	movs r1, 0x6
	strh r1, [r0]
	b _080229E6
	.align 2, 0
_080229A0: .4byte gUnknown_80DC5BC
_080229A4:
	movs r7, 0xB0
	lsls r7, 1
	adds r1, r7
	ldr r0, _080229B8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _080229E6
	.align 2, 0
_080229B8: .4byte gUnknown_80DC5D4
_080229BC:
	ldr r0, _08022A08
	mov r12, r0
	movs r1, 0xA4
	lsls r1, 1
	mov r8, r1
	ldr r4, _08022A0C
	movs r3, 0
	movs r2, 0x3
_080229CC:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080229CC
_080229E6:
	bl ResetUnusedInputStruct
	ldr r0, _08022A08
	ldr r0, [r0]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022A08: .4byte gUnknown_203B294
_08022A0C: .4byte gUnknown_80DC5A4
	thumb_func_end sub_802293C

	thumb_func_start sub_8022A10
sub_8022A10:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, _08022A2C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x16
	bls _08022A22
	b _08022D1E
_08022A22:
	lsls r0, 2
	ldr r1, _08022A30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022A2C: .4byte gUnknown_203B294
_08022A30: .4byte _08022A34
	.align 2, 0
_08022A34:
	.4byte _08022A90
	.4byte _08022AAA
	.4byte _08022AB2
	.4byte _08022AE0
	.4byte _08022B10
	.4byte _08022B1A
	.4byte _08022B24
	.4byte _08022B34
	.4byte _08022B44
	.4byte _08022B54
	.4byte _08022B64
	.4byte _08022C28
	.4byte _08022CA0
	.4byte _08022CA8
	.4byte _08022CB0
	.4byte _08022CB8
	.4byte _08022CC0
	.4byte _08022CC8
	.4byte _08022CD8
	.4byte _08022CE8
	.4byte _08022CF8
	.4byte _08022D14
	.4byte _08022D1E
_08022A90:
	ldr r0, [r4]
	ldr r0, [r0, 0x48]
	cmp r0, 0
	beq _08022A9C
	movs r0, 0x5
	b _08022A9E
_08022A9C:
	movs r0, 0x1
_08022A9E:
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08022D22
_08022AAA:
	movs r0, 0x1
	bl sub_801A8D0
	b _08022D22
_08022AB2:
	bl sub_801A9E0
	ldr r0, _08022ADC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x54
	adds r1, r2, 0
	adds r1, 0xF8
	movs r4, 0x9C
	lsls r4, 1
	adds r3, r2, r4
	adds r2, 0xF4
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022ADC: .4byte gUnknown_203B294
_08022AE0:
	bl sub_801A9E0
	ldr r4, _08022B08
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0
	bl sub_8012EA4
	ldr r0, [r4]
	adds r0, 0xA4
	ldr r1, _08022B0C
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022B08: .4byte gUnknown_203B294
_08022B0C: .4byte gUnknown_80DC584
_08022B10:
	ldr r0, [r4]
	adds r0, 0x50
	bl sub_801B3C0
	b _08022D22
_08022B1A:
	ldr r0, _08022B20
	b _08022D00
	.align 2, 0
_08022B20: .4byte gUnknown_80DC5F4
_08022B24:
	ldr r0, _08022B2C
	ldr r3, _08022B30
	b _08022D02
	.align 2, 0
_08022B2C: .4byte gUnknown_80DC618
_08022B30: .4byte 0x00000101
_08022B34:
	ldr r0, _08022B3C
	ldr r3, _08022B40
	b _08022D02
	.align 2, 0
_08022B3C: .4byte gUnknown_80DC674
_08022B40: .4byte 0x00000101
_08022B44:
	ldr r0, _08022B4C
	ldr r3, _08022B50
	b _08022D02
	.align 2, 0
_08022B4C: .4byte gUnknown_80DC6CC
_08022B50: .4byte 0x00000101
_08022B54:
	ldr r0, _08022B5C
	ldr r3, _08022B60
	b _08022D02
	.align 2, 0
_08022B5C: .4byte gUnknown_80DC728
_08022B60: .4byte 0x00000101
_08022B64:
	ldr r7, _08022B68
	b _08022B78
	.align 2, 0
_08022B68: .4byte gUnknown_203B294
_08022B6C:
	ldr r1, [r4]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	cmp r0, 0x17
	bgt _08022C10
_08022B78:
	movs r5, 0
	movs r6, 0
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r5, r0
	bge _08022BA4
	ldrb r1, [r2, 0x8]
	b _08022B9C
_08022B8A:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r3, r0
	bge _08022BA4
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r3
	ldrb r1, [r0]
_08022B9C:
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022B8A
	movs r5, 0x1
_08022BA4:
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	b _08022BC4
_08022BB4:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r3
_08022BC4:
	ldrb r1, [r0]
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022BB4
	movs r6, 0x1
_08022BCE:
	cmp r5, r6
	beq _08022B6C
	ldr r1, [r7]
	movs r0, 0xA
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x40]
	lsls r0, 24
	lsrs r0, 24
	bl GetIQSkillName
	adds r1, r0, 0
	ldr r0, _08022C18
	bl strcpy
	movs r0, 0xCB
	bl PlaySound
	ldr r0, _08022C1C
	movs r1, 0
	movs r2, 0
	ldr r3, _08022C20
	bl sub_80141B4
	ldr r1, [r7]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	ldr r0, _08022C24
	ldr r0, [r0]
	ldr r0, [r0, 0x40]
	cmp r0, 0x17
	bgt _08022C10
	b _08022D22
_08022C10:
	movs r0, 0xB
	bl sub_8022924
	b _08022D22
	.align 2, 0
_08022C18: .4byte gUnknown_202DEA8
_08022C1C: .4byte gUnknown_80DC788
_08022C20: .4byte 0x00000101
_08022C24: .4byte gUnknown_203B294
_08022C28:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	bl nullsub_104
	ldr r0, [r4]
	adds r0, 0x46
	ldrh r0, [r0]
	cmp r0, 0x8
	bhi _08022C98
	lsls r0, 2
	ldr r1, _08022C48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022C48: .4byte _08022C4C
	.align 2, 0
_08022C4C:
	.4byte _08022C70
	.4byte _08022C78
	.4byte _08022C80
	.4byte _08022C98
	.4byte _08022C88
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C90
_08022C70:
	movs r0, 0x16
	bl sub_8022924
	b _08022D22
_08022C78:
	movs r0, 0xD
	bl sub_8022924
	b _08022D22
_08022C80:
	movs r0, 0xE
	bl sub_8022924
	b _08022D22
_08022C88:
	movs r0, 0xF
	bl sub_8022924
	b _08022D22
_08022C90:
	movs r0, 0x10
	bl sub_8022924
	b _08022D22
_08022C98:
	movs r0, 0xC
	bl sub_8022924
	b _08022D22
_08022CA0:
	ldr r0, _08022CA4
	b _08022D00
	.align 2, 0
_08022CA4: .4byte gUnknown_80DC7B4
_08022CA8:
	ldr r0, _08022CAC
	b _08022D00
	.align 2, 0
_08022CAC: .4byte gUnknown_80DC7FC
_08022CB0:
	ldr r0, _08022CB4
	b _08022D00
	.align 2, 0
_08022CB4: .4byte gUnknown_80DC81C
_08022CB8:
	ldr r0, _08022CBC
	b _08022D00
	.align 2, 0
_08022CBC: .4byte gUnknown_80DC844
_08022CC0:
	ldr r0, _08022CC4
	b _08022D00
	.align 2, 0
_08022CC4: .4byte gUnknown_80DC864
_08022CC8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CD4
	b _08022D00
	.align 2, 0
_08022CD4: .4byte gUnknown_80DC88C
_08022CD8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CE4
	b _08022D00
	.align 2, 0
_08022CE4: .4byte gUnknown_80DC8AC
_08022CE8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CF4
	b _08022D00
	.align 2, 0
_08022CF4: .4byte gUnknown_80DC8C8
_08022CF8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022D0C
_08022D00:
	ldr r3, _08022D10
_08022D02:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08022D22
	.align 2, 0
_08022D0C: .4byte gUnknown_80DC8DC
_08022D10: .4byte 0x00000301
_08022D14:
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_801AFA4
	b _08022D22
_08022D1E:
	bl sub_801A928
_08022D22:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022A10

	thumb_func_start sub_8022D2C
sub_8022D2C:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _08022D78
	ldr r0, [r4]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r2, [r4]
	ldr r0, [r2, 0x48]
	cmp r0, 0
	beq _08022D80
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, _08022D7C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x52
	ldrb r0, [r0]
	bl IsGummiItem
	lsls r0, 24
	cmp r0, 0
	bne _08022D74
	ldr r0, [r4]
	movs r2, 0x9C
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0]
_08022D74:
	movs r6, 0x1
	b _08022DBE
	.align 2, 0
_08022D78: .4byte gUnknown_203B294
_08022D7C: .4byte gUnknown_80DC8F0
_08022D80:
	adds r0, r2, 0
	adds r0, 0x52
	ldrb r0, [r0]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08022DA4
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xF8
	ldr r0, _08022E38
	str r0, [r2]
	adds r1, 0xFC
	movs r0, 0x6
	str r0, [r1]
	movs r6, 0x1
_08022DA4:
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xF8
	adds r0, r3
	ldr r1, _08022E3C
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0xFC
	adds r2, r3
	movs r0, 0x4
	str r0, [r2]
	adds r6, 0x1
_08022DBE:
	ldr r4, _08022E40
	ldr r0, [r4]
	mov r12, r0
	lsls r1, r6, 3
	mov r2, r12
	adds r2, 0xF8
	adds r3, r2, r1
	ldr r0, _08022E44
	ldr r0, [r0]
	str r0, [r3]
	mov r3, r12
	adds r3, 0xFC
	adds r1, r3, r1
	movs r0, 0x7
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r1
	movs r0, 0
	str r0, [r2]
	adds r1, r3, r1
	movs r0, 0x1
	str r0, [r1]
	movs r5, 0
	adds r7, r4, 0
	cmp r5, r6
	bge _08022E16
	mov r4, r12
	adds r4, 0xF4
	movs r2, 0x9C
	lsls r2, 1
	add r2, r12
_08022DFE:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08022E0C
	ldr r1, [r3]
	ldr r0, [r4]
	cmp r1, r0
	beq _08022E70
_08022E0C:
	adds r2, 0x2
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, r6
	blt _08022DFE
_08022E16:
	movs r5, 0
	cmp r5, r6
	bge _08022E70
	ldr r1, [r7]
	movs r2, 0x9C
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _08022E48
	adds r0, r1, 0
	adds r0, 0xF4
	adds r1, 0xFC
	ldr r1, [r1]
	str r1, [r0]
	b _08022E70
	.align 2, 0
_08022E38: .4byte gUnknown_80DC8F8
_08022E3C: .4byte gUnknown_80D4940
_08022E40: .4byte gUnknown_203B294
_08022E44: .4byte gUnknown_80D4970
_08022E48:
	adds r5, 0x1
	cmp r5, r6
	bge _08022E70
	ldr r3, [r7]
	lsls r0, r5, 1
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r3, r2
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08022E48
	adds r2, r3, 0
	adds r2, 0xF4
	lsls r1, r5, 3
	adds r0, r3, 0
	adds r0, 0xFC
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
_08022E70:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022D2C

        .align 2,0
