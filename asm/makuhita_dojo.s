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
	bl DrawMakuhitaMainMenu
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

        .align 2,0
