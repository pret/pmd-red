	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start GenerateMailJobInfo
GenerateMailJobInfo:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _08095B44
	add sp, r4
	adds r4, r0, 0
	bl GenerateMailJobDungeonInfo
	lsls r0, 24
	cmp r0, 0
	bne _08095B48
	movs r0, 0
	b _08095CCC
	.align 2, 0
_08095B44: .4byte 0xfffffcb0
_08095B48:
	movs r0, 0x5
	strb r0, [r4]
	movs r0, 0x8
	bl RandInt
	ldr r1, _08095BC8
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4, 0x1]
	cmp r0, 0x2
	bne _08095B6C
	bl GetRescueTeamRank
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095B6C
	strb r0, [r4, 0x1]
_08095B6C:
	movs r0, 0
	strb r0, [r4, 0x2]
	bl Rand32Bit
	ldr r1, _08095BCC
	ands r1, r0
	str r1, [r4, 0x8]
	movs r7, 0
	movs r5, 0x1
	adds r0, r4, 0x4
	mov r8, r0
	movs r1, 0x12
	adds r1, r4
	mov r9, r1
	mov r6, sp
_08095B8A:
	lsls r0, r5, 16
	asrs r0, 16
	bl sub_803C110
	lsls r0, 24
	cmp r0, 0
	beq _08095B9E
	strh r5, [r6]
	adds r6, 0x2
	adds r7, 0x1
_08095B9E:
	adds r5, 0x1
	ldr r0, _08095BD0
	cmp r5, r0
	ble _08095B8A
	cmp r7, 0
	beq _08095BD4
	adds r0, r7, 0
	bl RandInt
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, 0xC]
	adds r0, r7, 0
	bl RandInt
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	b _08095BDC
	.align 2, 0
_08095BC8: .4byte gUnknown_8109984
_08095BCC: .4byte 0x00ffffff
_08095BD0: .4byte 0x000001a7
_08095BD4:
	movs r0, 0x10
	strh r0, [r4, 0xC]
	movs r0, 0x91
	lsls r0, 1
_08095BDC:
	strh r0, [r4, 0xE]
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _08095BEE
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095BEE:
	ldrb r0, [r4, 0x4]
	bl sub_8095F28
	strb r0, [r4, 0x10]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08095C10
	strb r0, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	adds r2, r4, 0
	adds r2, 0x10
	mov r0, r8
	movs r1, 0
	bl sub_803C37C
_08095C10:
	ldrb r0, [r4, 0x4]
	bl GetMaxItemCount
	adds r1, r0, 0
	cmp r1, 0
	bne _08095C28
	ldrb r0, [r4, 0x1]
	cmp r0, 0x4
	bne _08095C28
	strb r1, [r4, 0x1]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
_08095C28:
	ldrb r1, [r4, 0x1]
	mov r0, r8
	mov r2, r9
	bl sub_803C37C
	ldrb r0, [r4, 0x10]
	ldrb r1, [r4, 0x12]
	cmp r0, r1
	beq _08095C28
	movs r0, 0
	strb r0, [r4, 0x13]
	ldrb r0, [r4, 0x1]
	cmp r0, 0x2
	beq _08095C90
	cmp r0, 0x2
	bgt _08095C4E
	cmp r0, 0x1
	beq _08095C6C
	b _08095CCA
_08095C4E:
	cmp r0, 0x4
	bgt _08095CCA
	bl Rand32Bit
	adds r1, r0, 0
	movs r0, 0xE0
	lsls r0, 3
	ands r1, r0
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	beq _08095CC4
	cmp r1, r0
	bgt _08095CB4
	b _08095CAA
_08095C6C:
	bl Rand32Bit
	adds r1, r0, 0
	movs r0, 0x70
	ands r1, r0
	cmp r1, 0x10
	beq _08095C80
	cmp r1, 0x30
	beq _08095C88
	b _08095CCA
_08095C80:
	adds r0, r4, 0
	bl sub_803C3E0
	b _08095CCA
_08095C88:
	adds r0, r4, 0
	bl sub_803C45C
	b _08095CCA
_08095C90:
	bl Rand32Bit
	movs r1, 0xC0
	lsls r1, 6
	ands r1, r0
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _08095CCA
	adds r0, r4, 0
	bl sub_803C4F0
	b _08095CCA
_08095CAA:
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _08095CBC
	b _08095CCA
_08095CB4:
	movs r0, 0xC0
	lsls r0, 3
	cmp r1, r0
	bne _08095CCA
_08095CBC:
	adds r0, r4, 0
	bl sub_803C580
	b _08095CCA
_08095CC4:
	adds r0, r4, 0
	bl sub_803C610
_08095CCA:
	movs r0, 0x1
_08095CCC:
	movs r3, 0xD4
	lsls r3, 2
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GenerateMailJobInfo

        .align 2,0
