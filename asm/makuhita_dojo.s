        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start UpdateMakuhitaDialogue
UpdateMakuhitaDialogue:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _0802FFA4
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r5, r1, 0
	cmp r0, 0xD
	bls _0802FF9A
	b _080301A0
_0802FF9A:
	lsls r0, 2
	ldr r1, _0802FFA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802FFA4: .4byte gUnknown_203B318
_0802FFA8: .4byte _0802FFAC
	.align 2, 0
_0802FFAC:
	.4byte _0802FFE4
	.4byte _08030000
	.4byte _08030038
	.4byte _08030050
	.4byte _08030068
	.4byte _08030074
	.4byte _080300DC
	.4byte _080300C4
	.4byte _080300F4
	.4byte _0803010C
	.4byte _08030148
	.4byte _08030174
	.4byte _08030180
	.4byte _080301A0
_0802FFE4:
	bl sub_80301B0
	ldr r2, _0802FFF8
	ldr r0, _0802FFFC
	ldr r5, [r0]
	ldr r1, [r5, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	b _0803000E
	.align 2, 0
_0802FFF8: .4byte gMakuhitaDialogue
_0802FFFC: .4byte gUnknown_203B318
_08030000:
	ldr r2, _08030034
	ldr r5, [r5]
	ldr r1, [r5, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x4
_0803000E:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r5, 0x14]
	adds r3, r5, 0
	adds r3, 0x18
	movs r4, 0
	str r4, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	ldr r1, [r5, 0x68]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080301A0
	.align 2, 0
_08030034: .4byte gMakuhitaDialogue
_08030038:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _0803004C
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x8
	b _0803015A
	.align 2, 0
_0803004C: .4byte gMakuhitaDialogue
_08030050:
	ldr r3, [r5]
	movs r0, 0x4
	str r0, [r3, 0xC]
	ldr r2, _08030064
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0xC
	b _0803015A
	.align 2, 0
_08030064: .4byte gMakuhitaDialogue
_08030068:
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xA
	bl sub_80302E8
	b _080301A0
_08030074:
	ldr r1, [r5]
	movs r0, 0xD
	str r0, [r1, 0xC]
	movs r2, 0x10
	ldrsh r0, [r1, r2]
	bl sub_80A2740
	lsls r0, 24
	lsrs r0, 24
	ldr r2, _080300B4
	ldr r1, [sp, 0x14]
	ands r1, r2
	orrs r1, r0
	ldr r0, _080300B8
	ands r1, r0
	movs r0, 0x80
	lsls r0, 1
	orrs r1, r0
	str r1, [sp, 0x14]
	ldr r0, _080300BC
	add r1, sp, 0x14
	bl PrintYellowDungeonNametoBuffer
	ldr r2, _080300C0
	ldr r3, [r5]
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x10
	b _0803015A
	.align 2, 0
_080300B4: .4byte 0xffffff00
_080300B8: .4byte 0xffff00ff
_080300BC: .4byte gAvailablePokemonNames
_080300C0: .4byte gMakuhitaDialogue
_080300C4:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _080300D8
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x18
	b _0803015A
	.align 2, 0
_080300D8: .4byte gMakuhitaDialogue
_080300DC:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _080300F0
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x14
	b _0803015A
	.align 2, 0
_080300F0: .4byte gMakuhitaDialogue
_080300F4:
	ldr r3, [r5]
	movs r0, 0x9
	str r0, [r3, 0xC]
	ldr r2, _08030108
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x1C
	b _0803015A
	.align 2, 0
_08030108: .4byte gMakuhitaDialogue
_0803010C:
	ldr r4, _08030138
	bl GetPlayerPokemonStruct
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x6
	bl PrintColoredPokeNameToBuffer
	ldr r0, _0803013C
	ldr r1, [r0]
	movs r0, 0xB
	str r0, [r1, 0xC]
	movs r0, 0xCB
	bl PlaySound
	ldr r0, _08030140
	ldr r3, _08030144
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080301A0
	.align 2, 0
_08030138: .4byte gPlayerName
_0803013C: .4byte gUnknown_203B318
_08030140: .4byte gMakuhitaDojoBonslyDoll
_08030144: .4byte 0x00000101
_08030148:
	ldr r3, [r5]
	movs r0, 0xD
	str r0, [r3, 0xC]
	ldr r2, _0803016C
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x20
_0803015A:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x68]
	ldr r3, _08030170
	movs r1, 0
	bl sub_80141B4
	b _080301A0
	.align 2, 0
_0803016C: .4byte gMakuhitaDialogue
_08030170: .4byte 0x0000010d
_08030174:
	movs r0, 0x1
	movs r1, 0x49
	movs r2, 0x1
	bl sub_801B60C
	b _080301A0
_08030180:
	ldr r3, [r5]
	movs r0, 0x1
	str r0, [r3, 0xC]
	ldr r2, _080301A8
	ldr r1, [r3, 0x4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r2, 0x24
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r3, 0x68]
	ldr r3, _080301AC
	movs r1, 0
	bl sub_80141B4
_080301A0:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080301A8: .4byte gMakuhitaDialogue
_080301AC: .4byte 0x0000010d
	thumb_func_end UpdateMakuhitaDialogue

	thumb_func_start sub_80301B0
sub_80301B0:
	push {r4,lr}
	ldr r4, _080301F8
	ldr r1, [r4]
	movs r2, 0x2
	str r2, [r1, 0x14]
	ldr r0, _080301FC
	str r0, [r1, 0x18]
	str r2, [r1, 0x1C]
	bl sub_80306A4
	lsls r0, 24
	cmp r0, 0
	beq _080301D6
	ldr r0, [r4]
	movs r1, 0x1
	negs r1, r1
	str r1, [r0, 0x1C]
	movs r1, 0x1
	str r1, [r0, 0x14]
_080301D6:
	ldr r1, [r4]
	movs r2, 0x1
	ldr r0, _08030200
	ldr r0, [r0]
	str r0, [r1, 0x20]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08030204
	ldr r0, [r0]
	str r0, [r1, 0x28]
	str r2, [r1, 0x2C]
	movs r0, 0
	str r0, [r1, 0x30]
	str r2, [r1, 0x34]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080301F8: .4byte gUnknown_203B318
_080301FC: .4byte gMakuhitaDojoGoTrain
_08030200: .4byte gUnknown_80D4970
_08030204: .4byte gUnknown_80D4934
	thumb_func_end sub_80301B0

	thumb_func_start sub_8030208
sub_8030208:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08030250
	ldr r0, _08030230
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x14]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0803023A
	cmp r0, 0x2
	bgt _08030234
	cmp r0, 0x1
	beq _0803024A
	b _08030250
	.align 2, 0
_08030230: .4byte gUnknown_203B318
_08030234:
	cmp r0, 0x3
	beq _08030242
	b _08030250
_0803023A:
	movs r0, 0x3
	bl UpdateMakuhitaState
	b _08030250
_08030242:
	movs r0, 0xC
	bl UpdateMakuhitaState
	b _08030250
_0803024A:
	movs r0, 0x2
	bl UpdateMakuhitaState
_08030250:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8030208

	thumb_func_start sub_8030258
sub_8030258:
	push {lr}
	movs r0, 0x1
	bl sub_80303AC
	cmp r0, 0x2
	beq _08030288
	cmp r0, 0x2
	bcc _0803029A
	cmp r0, 0x3
	bne _0803029A
	bl sub_8030418
	ldr r1, _08030284
	ldr r1, [r1]
	strh r0, [r1, 0x10]
	bl sub_8030480
	movs r0, 0x5
	bl UpdateMakuhitaState
	b _0803029A
	.align 2, 0
_08030284: .4byte gUnknown_203B318
_08030288:
	bl sub_8030480
	ldr r0, _080302A0
	ldr r1, [r0]
	ldr r0, _080302A4
	strh r0, [r1, 0x10]
	movs r0, 0x1
	bl UpdateMakuhitaState
_0803029A:
	pop {r0}
	bx r0
	.align 2, 0
_080302A0: .4byte gUnknown_203B318
_080302A4: .4byte 0x0000ffff
	thumb_func_end sub_8030258

	thumb_func_start sub_80302A8
sub_80302A8:
	push {lr}
	bl sub_801B6AC
	cmp r0, 0x1
	bls _080302C0
	cmp r0, 0x3
	bhi _080302C0
	bl sub_801B72C
	movs r0, 0xA
	bl UpdateMakuhitaState
_080302C0:
	pop {r0}
	bx r0
	thumb_func_end sub_80302A8

	thumb_func_start sub_80302C4
sub_80302C4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080302DC
	ldr r0, _080302E4
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	bl UpdateMakuhitaState
_080302DC:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080302E4: .4byte gUnknown_203B318
	thumb_func_end sub_80302C4

	thumb_func_start sub_80302E8
sub_80302E8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	bl sub_80306A4
	lsls r0, 24
	cmp r0, 0
	beq _08030302
	movs r0, 0
	b _0803039A
_08030302:
	ldr r4, _080303A4
	ldr r0, [r4]
	cmp r0, 0
	bne _08030314
	movs r0, 0xD0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_08030314:
	ldr r0, [r4]
	str r5, [r0, 0x64]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x6C
	adds r1, r0, r1
	str r1, [r0, 0x68]
	adds r0, 0x6C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x64]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x6C
	ldr r0, _080303A8
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r4]
	ldr r1, [r2, 0x68]
	adds r0, r2, 0
	adds r0, 0xCC
	str r0, [r1, 0x14]
	cmp r6, 0
	beq _08030362
	ldr r1, [r2, 0x64]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x74
	adds r1, r0
	ldr r0, [r6]
	str r0, [r1]
_08030362:
	ldr r0, [r4]
	ldr r0, [r0, 0x68]
	mov r1, r8
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r4]
	adds r4, 0x30
	bl sub_8030668
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r5, 0
	bl sub_8013818
	bl sub_80304C8
	bl DrawDojoCourseList
	movs r0, 0x1
_0803039A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080303A4: .4byte gUnknown_203B31C
_080303A8: .4byte gUnknown_80E0804
	thumb_func_end sub_80302E8

	thumb_func_start sub_80303AC
sub_80303AC:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _080303C8
	ldr r0, _080303C4
	ldr r0, [r0]
	adds r0, 0x30
	bl sub_8013660
	movs r0, 0
	b _08030410
	.align 2, 0
_080303C4: .4byte gUnknown_203B31C
_080303C8:
	ldr r4, _080303E4
	ldr r0, [r4]
	adds r0, 0x30
	bl GetKeyPress
	cmp r0, 0x1
	beq _080303E8
	cmp r0, 0x2
	bne _080303F2
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08030410
	.align 2, 0
_080303E4: .4byte gUnknown_203B31C
_080303E8:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08030410
_080303F2:
	ldr r0, [r4]
	adds r0, 0x30
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08030406
	movs r0, 0
	b _08030410
_08030406:
	bl sub_80304C8
	bl DrawDojoCourseList
	movs r0, 0x1
_08030410:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80303AC

	thumb_func_start sub_8030418
sub_8030418:
	ldr r0, _08030440
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x4E
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x48
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	lsls r0, 1
	adds r0, r2, r0
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08030440: .4byte gUnknown_203B31C
	thumb_func_end sub_8030418

	thumb_func_start sub_8030444
sub_8030444:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_8030668
	adds r1, r0, 0
	ldr r5, _0803047C
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x52
	strh r1, [r2]
	adds r0, 0x30
	bl sub_8013984
	bl sub_80304C8
	bl DrawDojoCourseList
	cmp r4, 0
	beq _08030476
	ldr r0, [r5]
	adds r0, 0x30
	bl AddMenuCursorSprite
_08030476:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803047C: .4byte gUnknown_203B31C
	thumb_func_end sub_8030444

	thumb_func_start sub_8030480
sub_8030480:
	push {r4,r5,lr}
	ldr r4, _080304C0
	ldr r2, [r4]
	cmp r2, 0
	beq _080304BA
	ldr r0, [r2, 0x64]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6C
	ldr r0, _080304C4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080304BA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080304C0: .4byte gUnknown_203B31C
_080304C4: .4byte gUnknown_80E07EC
	thumb_func_end sub_8030480

	thumb_func_start sub_80304C8
sub_80304C8:
	push {r4,lr}
	ldr r4, _08030538
	ldr r0, [r4]
	adds r0, 0xCC
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xCD
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xCE
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xCF
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x4A
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x64]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x64]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x7C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030538: .4byte gUnknown_203B31C
	thumb_func_end sub_80304C8

        .align 2,0
