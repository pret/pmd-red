        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
	bl unk_FindMoveEnabledForAIAfter8_v2
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
	bl unk_FindMoveEnabledForAIBefore8_v2
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
	bl unk_SetMoveToLastInLinkedSequence8_v2
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
	bl unk_SetMoveToFirstInLinkedSequence8_v2
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
	bl TryLinkMovesAfter
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
_0801F0CC: .4byte gTeamInventoryRef
_0801F0D0:
	ldr r0, _0801F0E0
	ldr r1, [r0]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl UnlinkMovesAfter
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
	bl ToggleSetMove
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
	bl ToggleMoveEnabled
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

        .align 2,0
