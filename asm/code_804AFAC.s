	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_804AFAC
sub_804AFAC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	movs r0, 0
	mov r10, r0
	ldr r4, _0804B0E8
	ldr r0, [r4]
	ldr r1, _0804B0EC
	adds r1, r0
	mov r8, r1
	ldr r0, _0804B0F0
	ldr r1, _0804B0F4
	bl OpenFileAndGetFileDataPtr
	ldr r2, [r4]
	ldr r3, _0804B0F8
	adds r1, r2, r3
	str r0, [r1]
	ldr r0, _0804B0FC
	mov r6, r10
	strb r6, [r0]
	ldr r0, _0804B100
	strb r6, [r0]
	ldr r0, _0804B104
	strb r6, [r0]
	ldr r5, _0804B108
	movs r3, 0
	ldr r1, _0804B10C
	ldr r0, _0804B110
	adds r2, r0
	movs r6, 0
	ldrsh r0, [r2, r6]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0804AFFC
	movs r3, 0x1
_0804AFFC:
	strb r3, [r5]
	ldr r1, _0804B114
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, _0804B118
	mov r1, r10
	strb r1, [r0]
	ldr r1, _0804B11C
	mov r2, r8
	ldrb r0, [r2, 0x7]
	strh r0, [r1]
	ldr r1, _0804B120
	ldrb r0, [r2, 0x8]
	strh r0, [r1]
	ldr r1, _0804B124
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0804B128
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	str r0, [r1, 0x8]
	str r0, [r1, 0x4]
	str r0, [r1, 0xC]
	bl sub_804FD30
	ldr r3, [r4]
	mov r6, r8
	ldrb r2, [r6, 0x6]
	ldr r1, _0804B12C
	adds r0, r3, r1
	movs r1, 0
	strh r2, [r0]
	ldr r2, _0804B130
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0804B134
	adds r0, r3
	strb r1, [r0]
	ldr r1, _0804B138
	mov r6, r8
	ldrb r0, [r6, 0xC]
	str r0, [r1]
	movs r0, 0
	str r0, [sp, 0x40]
_0804B058:
	ldr r0, _0804B0E8
	ldr r2, [r0]
	ldr r3, _0804B13C
	adds r1, r2, r3
	ldr r0, _0804B140
	strh r0, [r1]
	ldr r6, _0804B144
	adds r1, r2, r6
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1]
	ldr r0, _0804B148
	adds r1, r2, r0
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1]
	ldr r1, _0804B14C
	adds r2, r1
	strh r0, [r2]
	movs r2, 0
	mov r9, r2
_0804B082:
	ldr r4, _0804B0E8
	ldr r0, [r4]
	ldr r3, _0804B150
	adds r0, r3
	movs r5, 0
	movs r1, 0
	mov r6, r9
	strh r6, [r0]
	mov r0, r9
	cmp r0, 0
	ble _0804B09C
	ldr r0, _0804B138
	str r1, [r0]
_0804B09C:
	ldr r0, _0804B154
	strb r5, [r0]
	ldr r1, _0804B158
	ldr r0, _0804B140
	strh r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1, 0x2]
	bl sub_804FD30
	ldr r1, [r4]
	ldr r3, _0804B13C
	adds r2, r1, r3
	movs r0, 0x1
	negs r0, r0
	strh r0, [r2]
	ldr r6, _0804B144
	adds r2, r1, r6
	strh r0, [r2]
	ldr r0, _0804B15C
	adds r1, r0
	strb r5, [r1]
	ldr r0, [r4]
	ldr r2, _0804B160
	adds r1, r0, r2
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	beq _0804B164
	mov r1, r8
	bl sub_804C70C
	lsls r0, 24
	cmp r0, 0
	beq _0804B0E4
	b _0804B376
_0804B0E4:
	b _0804B2F6
	.align 2, 0
_0804B0E8: .4byte gDungeonGlobalData
_0804B0EC: .4byte 0x0001c574
_0804B0F0: .4byte gUnknown_80F6DCC
_0804B0F4: .4byte gDungeonFileArchive
_0804B0F8: .4byte 0x00013568
_0804B0FC: .4byte gUnknown_202F1AA
_0804B100: .4byte gUnknown_202F1AB
_0804B104: .4byte gUnknown_202F1AC
_0804B108: .4byte gUnknown_202F1A8
_0804B10C: .4byte gDungeonWaterType
_0804B110: .4byte 0x00003a0e
_0804B114: .4byte gUnknown_202F1B4
_0804B118: .4byte gUnknown_202F1AE
_0804B11C: .4byte gUnknown_202F1B0
_0804B120: .4byte gUnknown_202F1B2
_0804B124: .4byte gUnknown_202F1AD
_0804B128: .4byte gUnknown_202F1B8
_0804B12C: .4byte 0x00000664
_0804B130: .4byte 0x00003a09
_0804B134: .4byte 0x00003a0a
_0804B138: .4byte gUnknown_202F1C8
_0804B13C: .4byte 0x0000e218
_0804B140: .4byte 0x0000ffff
_0804B144: .4byte 0x0000e21a
_0804B148: .4byte 0x0000e21c
_0804B14C: .4byte 0x0000e21e
_0804B150: .4byte 0x00003a16
_0804B154: .4byte gUnknown_202F1A9
_0804B158: .4byte gUnknown_202F1D8
_0804B15C: .4byte 0x00003a08
_0804B160: .4byte 0x00003a14
_0804B164:
	mov r0, r8
	ldrb r7, [r0]
	movs r6, 0x20
_0804B16A:
	cmp r7, 0x8
	beq _0804B17E
	movs r0, 0x2
	movs r1, 0x9
	bl DungeonRandomRange
	adds r5, r0, 0
	movs r0, 0x2
	movs r1, 0x8
	b _0804B18C
_0804B17E:
	movs r0, 0x2
	movs r1, 0x5
	bl DungeonRandomRange
	adds r5, r0, 0
	movs r0, 0x2
	movs r1, 0x4
_0804B18C:
	bl DungeonRandomRange
	adds r4, r0, 0
	cmp r5, 0x6
	bgt _0804B19A
	cmp r4, 0x4
	ble _0804B1A4
_0804B19A:
	subs r6, 0x1
	cmp r6, 0
	bne _0804B16A
	movs r5, 0x4
	movs r4, 0x4
_0804B1A4:
	movs r0, 0x38
	adds r1, r5, 0
	bl __divsi3
	cmp r0, 0x7
	bgt _0804B1B2
	movs r5, 0x1
_0804B1B2:
	movs r0, 0x20
	adds r1, r4, 0
	bl __divsi3
	cmp r0, 0x7
	bgt _0804B1C0
	movs r4, 0x1
_0804B1C0:
	ldr r2, _0804B1EC
	ldr r0, [r2]
	ldr r1, _0804B1F0
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _0804B1F4
	adds r0, r2
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, _0804B1F8
	str r7, [r0]
	movs r0, 0xF
	ands r0, r7
	cmp r0, 0xB
	bhi _0804B274
	lsls r0, 2
	ldr r1, _0804B1FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804B1EC: .4byte gDungeonGlobalData
_0804B1F0: .4byte 0x00003a08
_0804B1F4: .4byte 0x00003a0c
_0804B1F8: .4byte gUnknown_202F1D0
_0804B1FC: .4byte _0804B200
	.align 2, 0
_0804B200:
	.4byte _0804B274
	.4byte _0804B230
	.4byte _0804B280
	.4byte _0804B298
	.4byte _0804B2A4
	.4byte _0804B2B0
	.4byte _0804B2CC
	.4byte _0804B2D8
	.4byte _0804B274
	.4byte _0804B2E0
	.4byte _0804B2E8
	.4byte _0804B250
_0804B230:
	movs r0, 0x2
	bl DungeonRandomCapped
	adds r4, r0, 0x2
	ldr r1, _0804B24C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x4
	adds r1, r4, 0
	mov r2, r8
	bl sub_804B634
	b _0804B2AA
	.align 2, 0
_0804B24C: .4byte gUnknown_202F1AE
_0804B250:
	movs r0, 0x2
	bl DungeonRandomCapped
	adds r4, r0, 0x2
	ldr r1, _0804B270
	movs r0, 0x2
	strb r0, [r1]
	movs r0, 0x4
	adds r1, r4, 0
	mov r2, r8
	bl sub_804B634
	movs r6, 0x1
	mov r10, r6
	b _0804B2F6
	.align 2, 0
_0804B270: .4byte gUnknown_202F1AE
_0804B274:
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl sub_804B634
	b _0804B2D2
_0804B280:
	bl sub_804C918
	ldr r0, _0804B290
	ldr r0, [r0]
	ldr r1, _0804B294
	adds r0, r1
	b _0804B2BC
	.align 2, 0
_0804B290: .4byte gDungeonGlobalData
_0804B294: .4byte 0x00003a08
_0804B298:
	mov r0, r8
	bl sub_804B72C
	movs r2, 0x1
	mov r10, r2
	b _0804B2F6
_0804B2A4:
	mov r0, r8
	bl sub_804BC80
_0804B2AA:
	movs r3, 0x1
	mov r10, r3
	b _0804B2F6
_0804B2B0:
	bl sub_804C9D0
	ldr r0, _0804B2C4
	ldr r0, [r0]
	ldr r6, _0804B2C8
	adds r0, r6
_0804B2BC:
	movs r1, 0x1
	strb r1, [r0]
	b _0804B2F6
	.align 2, 0
_0804B2C4: .4byte gDungeonGlobalData
_0804B2C8: .4byte 0x00003a08
_0804B2CC:
	mov r0, r8
	bl sub_804C0A8
_0804B2D2:
	movs r0, 0x1
	mov r10, r0
	b _0804B2F6
_0804B2D8:
	mov r0, r8
	bl sub_804C190
	b _0804B2F6
_0804B2E0:
	mov r0, r8
	bl sub_804C2F4
	b _0804B2F6
_0804B2E8:
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl sub_804C53C
	movs r1, 0x1
	mov r10, r1
_0804B2F6:
	bl sub_80518F0
	bl sub_804FCCC
	ldr r0, _0804B4B4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0804B36A
	movs r7, 0
	movs r1, 0
	mov r0, sp
	adds r0, 0x3F
_0804B30E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0804B30E
	movs r5, 0
_0804B318:
	movs r4, 0
	adds r6, r5, 0x1
_0804B31C:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	adds r1, r0, 0
	ldrh r0, [r1]
	movs r2, 0x3
	ands r2, r0
	cmp r2, 0x1
	bne _0804B340
	ldrb r0, [r1, 0x9]
	cmp r0, 0xF0
	bhi _0804B340
	adds r7, 0x1
	cmp r0, 0x3F
	bhi _0804B340
	add r0, sp
	strb r2, [r0]
_0804B340:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0804B31C
	adds r5, r6, 0
	cmp r5, 0x37
	ble _0804B318
	movs r1, 0
	movs r4, 0
_0804B350:
	mov r2, sp
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804B35C
	adds r1, 0x1
_0804B35C:
	adds r4, 0x1
	cmp r4, 0x3F
	ble _0804B350
	cmp r7, 0x1D
	ble _0804B36A
	cmp r1, 0x1
	bgt _0804B376
_0804B36A:
	movs r3, 0x1
	add r9, r3
	mov r6, r9
	cmp r6, 0x9
	bgt _0804B376
	b _0804B082
_0804B376:
	mov r0, r9
	cmp r0, 0xA
	bne _0804B398
	ldr r1, _0804B4B8
	ldr r0, _0804B4BC
	strh r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1, 0x2]
	bl sub_804C918
	ldr r0, _0804B4C0
	ldr r0, [r0]
	ldr r1, _0804B4C4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_0804B398:
	bl sub_804E9DC
	mov r2, r10
	cmp r2, 0
	beq _0804B3AA
	movs r0, 0x1
	mov r1, r8
	bl sub_80506F0
_0804B3AA:
	movs r0, 0x64
	bl DungeonRandomCapped
	movs r4, 0
	mov r3, r8
	ldrb r3, [r3, 0x19]
	cmp r0, r3
	bge _0804B3BC
	movs r4, 0x1
_0804B3BC:
	mov r0, r8
	adds r1, r4, 0
	bl sub_804FF08
	mov r0, r8
	adds r1, r4, 0
	bl sub_8050438
	bl sub_804FBE8
	ldr r5, _0804B4C0
	ldr r1, [r5]
	ldr r6, _0804B4C8
	adds r0, r1, r6
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r4, 0x1
	negs r4, r4
	cmp r0, r4
	beq _0804B42A
	ldr r3, _0804B4CC
	adds r0, r1, r3
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, r4
	beq _0804B42A
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0804B436
	ldr r1, [r5]
	ldr r0, _0804B4D0
	adds r2, r1, r0
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, r4
	beq _0804B42A
	ldr r6, _0804B4D4
	adds r1, r6
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	beq _0804B42A
	movs r6, 0
	ldrsh r0, [r2, r6]
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r2, 0
	bl sub_8050C30
	lsls r0, 24
	cmp r0, 0
	bne _0804B436
_0804B42A:
	ldr r3, [sp, 0x40]
	adds r3, 0x1
	str r3, [sp, 0x40]
	cmp r3, 0x9
	bgt _0804B436
	b _0804B058
_0804B436:
	ldr r6, [sp, 0x40]
	cmp r6, 0xA
	bne _0804B474
	ldr r1, _0804B4B8
	ldr r0, _0804B4BC
	strh r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1, 0x2]
	bl sub_804FD30
	bl sub_804C918
	ldr r0, _0804B4C0
	ldr r0, [r0]
	ldr r1, _0804B4C4
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	bl sub_804E9DC
	mov r0, r8
	movs r1, 0
	bl sub_804FF08
	mov r0, r8
	movs r1, 0
	bl sub_8050438
	bl sub_804FBE8
_0804B474:
	ldr r1, _0804B4B8
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	blt _0804B498
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	cmp r0, 0
	blt _0804B498
	movs r6, 0
	ldrsh r0, [r1, r6]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	movs r2, 0xBE
	lsls r2, 1
	movs r3, 0
	bl sub_806C330
_0804B498:
	ldr r0, _0804B4D8
	ldr r0, [r0]
	cmp r0, 0
	blt _0804B4E0
	mov r0, r8
	bl sub_8051654
	ldr r0, _0804B4C0
	ldr r0, [r0]
	ldr r3, _0804B4DC
	adds r0, r3
	movs r1, 0x1
	b _0804B4EA
	.align 2, 0
_0804B4B4: .4byte gUnknown_202F1A9
_0804B4B8: .4byte gUnknown_202F1D8
_0804B4BC: .4byte 0x0000ffff
_0804B4C0: .4byte gDungeonGlobalData
_0804B4C4: .4byte 0x00003a08
_0804B4C8: .4byte 0x0000e218
_0804B4CC: .4byte 0x0000e21a
_0804B4D0: .4byte 0x0000e21c
_0804B4D4: .4byte 0x0000e21e
_0804B4D8: .4byte gUnknown_202F1B8
_0804B4DC: .4byte 0x00003a0a
_0804B4E0:
	ldr r0, _0804B524
	ldr r0, [r0]
	ldr r6, _0804B528
	adds r0, r6
	movs r1, 0
_0804B4EA:
	strb r1, [r0]
	movs r0, 0
	movs r1, 0
	movs r2, 0x38
	movs r3, 0x20
	bl sub_804B534
	ldr r0, _0804B52C
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804B504
	bl sub_804FC74
_0804B504:
	ldr r0, _0804B524
	ldr r0, [r0]
	ldr r1, _0804B530
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B524: .4byte gDungeonGlobalData
_0804B528: .4byte 0x00003a0a
_0804B52C: .4byte gUnknown_202F1A8
_0804B530: .4byte 0x00013568
	thumb_func_end sub_804AFAC

	thumb_func_start sub_804B534
sub_804B534:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	str r1, [sp]
	str r2, [sp, 0x4]
	mov r10, r3
	adds r5, r0, 0
	cmp r5, r2
	bge _0804B620
_0804B54C:
	ldr r4, [sp]
	adds r0, r5, 0x1
	mov r9, r0
	cmp r4, r10
	bge _0804B618
	movs r6, 0x3
	mov r8, r6
_0804B55A:
	movs r3, 0
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0xC]
	bl GetMapTile_2
	adds r2, r0, 0
	ldrh r0, [r2]
	ldr r6, _0804B630
	adds r1, r6, 0
	ands r1, r0
	strh r1, [r2]
	ldrb r0, [r2, 0x9]
	adds r6, r4, 0x1
	ldr r3, [sp, 0xC]
	cmp r0, 0xFF
	bne _0804B612
	movs r7, 0x3
	adds r0, r1, 0
	ands r0, r7
	cmp r0, 0x1
	bne _0804B612
	cmp r5, 0
	ble _0804B5A4
	subs r0, r5, 0x1
	adds r1, r4, 0
	str r2, [sp, 0x8]
	bl GetMapTile_1
	ldrh r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0xC]
	cmp r0, 0x1
	bne _0804B5A4
	movs r3, 0x1
_0804B5A4:
	cmp r4, 0
	ble _0804B5C4
	subs r1, r4, 0x1
	adds r0, r5, 0
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0xC]
	cmp r0, 0x1
	bne _0804B5C4
	adds r3, 0x1
_0804B5C4:
	cmp r5, 0x35
	bgt _0804B5E4
	mov r0, r9
	adds r1, r4, 0
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0xC]
	cmp r0, 0x1
	bne _0804B5E4
	adds r3, 0x1
_0804B5E4:
	adds r6, r4, 0x1
	cmp r5, 0x1D
	bgt _0804B606
	adds r0, r5, 0
	adds r1, r6, 0
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x8]
	ldr r3, [sp, 0xC]
	cmp r0, 0x1
	bne _0804B606
	adds r3, 0x1
_0804B606:
	cmp r3, 0x2
	ble _0804B612
	ldrh r1, [r2]
	movs r0, 0x8
	orrs r0, r1
	strh r0, [r2]
_0804B612:
	adds r4, r6, 0
	cmp r4, r10
	blt _0804B55A
_0804B618:
	mov r5, r9
	ldr r0, [sp, 0x4]
	cmp r5, r0
	blt _0804B54C
_0804B620:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B630: .4byte 0x0000fffb
	thumb_func_end sub_804B534

	thumb_func_start sub_804B634
sub_804B634:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	ldr r4, _0804B718
	add sp, r4
	adds r4, r0, 0
	adds r5, r1, 0
	mov r9, r2
	ldr r0, _0804B71C
	add r0, sp
	mov r8, r0
	ldr r6, _0804B720
	add r6, sp
	adds r1, r6, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_804D024
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804D084
	mov r1, r9
	movs r3, 0x1
	ldrsb r3, [r1, r3]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804D154
	str r6, [sp]
	mov r1, r9
	ldrb r0, [r1, 0xD]
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r8
	bl sub_804D2D0
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r9
	bl sub_804D5B0
	str r6, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r8
	bl sub_804D8C8
	str r6, [sp]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r8
	bl sub_804E590
	mov r0, r9
	ldrb r3, [r0, 0x9]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804F0D0
	ldr r0, _0804B724
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804EBC8
	ldr r0, _0804B728
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804EEE4
	mov r0, r9
	ldrb r3, [r0, 0x13]
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804CBEC
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804E03C
	add r0, sp, 0x8
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_804D534
	movs r3, 0xE5
	lsls r3, 5
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804B718: .4byte 0xffffe360
_0804B71C: .4byte 0x00001c28
_0804B720: .4byte 0x00001c64
_0804B724: .4byte gUnknown_202F1B0
_0804B728: .4byte gUnknown_202F1B2
	thumb_func_end sub_804B634

	thumb_func_start sub_804B72C
sub_804B72C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0804B9AC
	add sp, r4
	movs r1, 0xE5
	lsls r1, 5
	add r1, sp
	str r0, [r1]
	movs r5, 0
	movs r6, 0x1
	ldr r1, _0804B9B0
	add r1, sp
	str r5, [r1]
	movs r0, 0x5
	str r0, [r1, 0x4]
	movs r0, 0x1C
	str r0, [r1, 0xC]
	movs r0, 0x33
	str r0, [r1, 0x14]
	movs r0, 0x38
	str r0, [r1, 0x18]
	movs r2, 0x10
	str r2, [r1, 0x8]
	movs r0, 0x27
	str r0, [r1, 0x10]
	ldr r1, _0804B9B4
	add r1, sp
	movs r0, 0x2
	str r0, [r1]
	movs r0, 0x7
	str r0, [r1, 0x4]
	str r2, [r1, 0x8]
	movs r0, 0x19
	str r0, [r1, 0xC]
	movs r0, 0x1E
	str r0, [r1, 0x10]
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	bl sub_804D084
	mov r2, sp
	adds r2, 0x3B
	ldr r3, _0804B9B8
	add r3, sp
	str r2, [r3]
	mov r4, sp
	adds r4, 0x3C
	ldr r0, _0804B9BC
	add r0, sp
	str r4, [r0]
	mov r1, sp
	adds r1, 0x5B
	ldr r2, _0804B9C0
	add r2, sp
	str r1, [r2]
	mov r3, sp
	adds r3, 0x5C
	movs r4, 0xE6
	lsls r4, 5
	add r4, sp
	str r3, [r4]
	mov r0, sp
	adds r0, 0x7B
	ldr r1, _0804B9C4
	add r1, sp
	str r0, [r1]
	mov r2, sp
	adds r2, 0x7E
	ldr r3, _0804B9C8
	add r3, sp
	str r2, [r3]
	add r1, sp, 0x68
	add r0, sp, 0x8
	movs r2, 0xF0
	lsls r2, 1
	movs r4, 0x6
_0804B7CC:
	strb r5, [r0, 0xA]
	strb r5, [r1, 0xA]
	adds r1, r2
	adds r0, r2
	subs r4, 0x1
	cmp r4, 0
	bne _0804B7CC
	movs r2, 0x6
	subs r2, 0x1
	movs r4, 0x4
	cmp r4, 0
	beq _0804B80C
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	add r1, sp, 0x8
	ldr r3, _0804B9CC
	add r3, sp
	str r4, [r3]
_0804B7F6:
	strb r5, [r1, 0xA]
	strb r5, [r0, 0xA]
	adds r0, 0x20
	adds r1, 0x20
	ldr r3, _0804B9CC
	add r3, sp
	ldr r4, [r3]
	subs r4, 0x1
	str r4, [r3]
	cmp r4, 0
	bne _0804B7F6
_0804B80C:
	movs r4, 0x1
	cmp r4, r2
	bge _0804B848
	movs r1, 0x3
_0804B814:
	adds r5, r4, 0x1
	mov r8, r5
	cmp r1, 0x1
	ble _0804B842
	lsls r0, r4, 4
	subs r0, r4
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	adds r0, 0x20
	subs r3, r1, 0x1
	ldr r4, _0804B9CC
	add r4, sp
	str r3, [r4]
_0804B830:
	strb r6, [r0, 0xA]
	adds r0, 0x20
	ldr r3, _0804B9CC
	add r3, sp
	ldr r5, [r3]
	subs r5, 0x1
	str r5, [r3]
	cmp r5, 0
	bne _0804B830
_0804B842:
	mov r4, r8
	cmp r4, r2
	blt _0804B814
_0804B848:
	movs r4, 0
	ldr r5, _0804B9D0
	add r5, sp
	str r4, [r5]
	ldr r0, _0804B9CC
	add r0, sp
	str r4, [r0]
	cmp r4, 0x4
	blt _0804B85C
	b _0804BA8C
_0804B85C:
	movs r4, 0
	ldr r2, _0804B9CC
	add r2, sp
	ldr r1, [r2]
	adds r1, 0x1
	ldr r2, _0804B9D4
	add r2, sp
	str r1, [r2]
	cmp r4, 0x6
	blt _0804B872
	b _0804BA7A
_0804B872:
	ldr r3, _0804B9B0
	add r3, sp
	ldr r5, _0804B9D8
	add r5, sp
	str r3, [r5]
	ldr r0, _0804B9B4
	add r0, sp
	ldr r1, _0804B9DC
	add r1, sp
	str r0, [r1]
	ldr r2, _0804B9CC
	add r2, sp
	ldr r2, [r2]
	lsls r0, r2, 2
	ldr r3, [r1]
	adds r0, r3, r0
	ldr r3, _0804B9E0
	add r3, sp
	str r0, [r3]
_0804B898:
	lsls r0, r4, 4
	subs r0, r4
	ldr r5, _0804B9CC
	add r5, sp
	ldr r5, [r5]
	adds r0, r5
	lsls r0, 5
	mov r7, sp
	adds r7, r0
	adds r7, 0x8
	ldrb r0, [r7, 0xA]
	cmp r0, 0
	bne _0804B8B4
	b _0804B9F4
_0804B8B4:
	lsls r0, r4, 2
	ldr r1, _0804B9D8
	add r1, sp
	ldr r1, [r1]
	adds r0, r1, r0
	ldr r1, [r0]
	adds r2, r1, 0x2
	mov r10, r2
	ldr r3, _0804B9E0
	add r3, sp
	ldr r3, [r3]
	ldr r2, [r3]
	adds r5, r2, 0x2
	ldr r0, _0804B9E4
	add r0, sp
	str r5, [r0]
	adds r4, 0x1
	mov r9, r4
	lsls r0, r4, 2
	ldr r3, _0804B9D8
	add r3, sp
	ldr r3, [r3]
	adds r0, r3, r0
	ldr r4, [r0]
	subs r4, r1
	subs r4, 0x3
	ldr r5, _0804B9D4
	add r5, sp
	ldr r5, [r5]
	lsls r0, r5, 2
	ldr r1, _0804B9DC
	add r1, sp
	ldr r1, [r1]
	adds r0, r1, r0
	ldr r5, [r0]
	subs r5, r2
	subs r5, 0x3
	movs r0, 0x5
	adds r1, r4, 0
	bl DungeonRandomRange
	mov r8, r0
	movs r0, 0x4
	adds r1, r5, 0
	bl DungeonRandomRange
	adds r6, r0, 0
	mov r2, r8
	subs r4, r2
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	add r4, r10
	subs r5, r6
	adds r0, r5, 0
	bl DungeonRandomCapped
	ldr r5, _0804B9E4
	add r5, sp
	ldr r3, [r5]
	adds r3, r0
	mov r10, r3
	mov r0, r8
	adds r3, r4, r0
	add r6, r10
	strh r4, [r7]
	strh r3, [r7, 0x4]
	mov r1, r10
	strh r1, [r7, 0x2]
	strh r6, [r7, 0x6]
	mov r8, r9
	ldr r5, _0804B9D0
	add r5, sp
	ldr r2, [r5]
	adds r2, 0x1
	ldr r5, _0804B9E8
	add r5, sp
	str r2, [r5]
	cmp r4, r3
	bge _0804B99E
_0804B956:
	mov r5, r10
	adds r7, r4, 0x1
	cmp r5, r6
	bge _0804B998
	ldr r0, _0804B9EC
	mov r9, r0
_0804B962:
	adds r0, r4, 0
	adds r1, r5, 0
	ldr r2, _0804B9F0
	add r2, sp
	str r3, [r2]
	bl GetMapTile_2
	ldrh r1, [r0]
	mov r2, r9
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	ldr r1, _0804B9D0
	add r1, sp
	ldrb r1, [r1]
	strb r1, [r0, 0x9]
	adds r5, 0x1
	ldr r2, _0804B9F0
	add r2, sp
	ldr r3, [r2]
	cmp r5, r6
	blt _0804B962
_0804B998:
	adds r4, r7, 0
	cmp r4, r3
	blt _0804B956
_0804B99E:
	ldr r3, _0804B9E8
	add r3, sp
	ldr r3, [r3]
	ldr r4, _0804B9D0
	add r4, sp
	str r3, [r4]
	b _0804BA72
	.align 2, 0
_0804B9AC: .4byte 0xffffe320
_0804B9B0: .4byte 0x00001c28
_0804B9B4: .4byte 0x00001c64
_0804B9B8: .4byte 0x00001cd4
_0804B9BC: .4byte 0x00001cd8
_0804B9C0: .4byte 0x00001cbc
_0804B9C4: .4byte 0x00001cc4
_0804B9C8: .4byte 0x00001cc8
_0804B9CC: .4byte 0x00001ca4
_0804B9D0: .4byte 0x00001ca8
_0804B9D4: .4byte 0x00001ccc
_0804B9D8: .4byte 0x00001cac
_0804B9DC: .4byte 0x00001cb4
_0804B9E0: .4byte 0x00001cb8
_0804B9E4: .4byte 0x00001cb0
_0804B9E8: .4byte 0x00001cd0
_0804B9EC: .4byte 0x0000fffc
_0804B9F0: .4byte 0x00001cdc
_0804B9F4:
	lsls r0, r4, 2
	ldr r5, _0804BBE8
	add r5, sp
	ldr r5, [r5]
	adds r0, r5, r0
	ldr r2, [r0]
	adds r0, r2, 0x1
	ldr r1, _0804BBEC
	add r1, sp
	ldr r1, [r1]
	ldr r3, [r1]
	adds r6, r3, 0x1
	adds r4, 0x1
	mov r8, r4
	lsls r1, r4, 2
	adds r1, r5, r1
	ldr r1, [r1]
	subs r1, r2
	subs r1, 0x3
	ldr r5, _0804BBF0
	add r5, sp
	ldr r5, [r5]
	lsls r2, r5, 2
	ldr r4, _0804BBF4
	add r4, sp
	ldr r4, [r4]
	adds r2, r4, r2
	ldr r4, [r2]
	subs r4, r3
	subs r4, 0x3
	adds r1, r0, r1
	bl DungeonRandomRange
	adds r5, r0, 0
	adds r4, r6, r4
	adds r0, r6, 0
	adds r1, r4, 0
	bl DungeonRandomRange
	adds r4, r0, 0
	strh r5, [r7]
	adds r0, r5, 0x1
	strh r0, [r7, 0x4]
	strh r4, [r7, 0x2]
	adds r0, r4, 0x1
	strh r0, [r7, 0x6]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, _0804BBF8
	adds r2, r3, 0
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0xFF
	strb r1, [r0, 0x9]
_0804BA72:
	mov r4, r8
	cmp r4, 0x6
	bge _0804BA7A
	b _0804B898
_0804BA7A:
	ldr r4, _0804BBF0
	add r4, sp
	ldr r4, [r4]
	ldr r5, _0804BBFC
	add r5, sp
	str r4, [r5]
	cmp r4, 0x4
	bge _0804BA8C
	b _0804B85C
_0804BA8C:
	add r1, sp, 0x8
	movs r6, 0
	movs r0, 0x1
	strb r0, [r1, 0x16]
	ldr r1, _0804BC00
	add r1, sp
	strb r0, [r1]
	movs r1, 0xFF
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC04
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC08
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC0C
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC10
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC14
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC18
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC1C
	add r1, sp
	strb r0, [r1]
	add r1, sp, 0x8
	strb r0, [r1, 0x14]
	ldr r5, _0804BC20
	add r5, sp
	ldr r5, [r5]
	strb r0, [r5]
	ldr r1, _0804BC24
	add r1, sp
	ldr r1, [r1]
	strb r0, [r1]
	ldr r2, _0804BC28
	add r2, sp
	ldr r2, [r2]
	strb r0, [r2]
	movs r3, 0xE6
	lsls r3, 5
	add r3, sp
	ldr r3, [r3]
	strb r0, [r3]
	ldr r4, _0804BC2C
	add r4, sp
	ldr r4, [r4]
	strb r0, [r4]
	ldr r5, _0804BC30
	add r5, sp
	ldr r5, [r5]
	strb r0, [r5]
	ldr r1, _0804BC34
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC38
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC3C
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC40
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC44
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC48
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC4C
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC50
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC54
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC58
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC5C
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC60
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC64
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC68
	add r1, sp
	strb r0, [r1]
	ldr r1, _0804BC6C
	add r1, sp
	strb r0, [r1]
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	movs r4, 0xE5
	lsls r4, 5
	add r4, sp
	ldr r3, [r4]
	bl sub_804D5B0
	ldr r5, _0804BC70
	add r5, sp
	ldr r4, _0804BC74
	add r4, sp
	str r4, [sp]
	str r6, [sp, 0x4]
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	adds r3, r5, 0
	bl sub_804D8C8
	str r4, [sp]
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	adds r3, r5, 0
	bl sub_804E590
	ldr r0, _0804BC78
	movs r5, 0
	ldrsh r3, [r0, r5]
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	bl sub_804EBC8
	ldr r0, _0804BC7C
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	bl sub_804EEE4
	movs r2, 0xE5
	lsls r2, 5
	add r2, sp
	ldr r2, [r2]
	ldrb r3, [r2, 0x13]
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	bl sub_804CBEC
	add r0, sp, 0x8
	movs r1, 0x6
	movs r2, 0x4
	bl sub_804E03C
	movs r3, 0xE7
	lsls r3, 5
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804BBE8: .4byte 0x00001cac
_0804BBEC: .4byte 0x00001cb8
_0804BBF0: .4byte 0x00001ccc
_0804BBF4: .4byte 0x00001cb4
_0804BBF8: .4byte 0x0000fffc
_0804BBFC: .4byte 0x00001ca4
_0804BC00: .4byte 0x000001fd
_0804BC04: .4byte 0x000003dd
_0804BC08: .4byte 0x000003de
_0804BC0C: .4byte 0x000005bd
_0804BC10: .4byte 0x000005be
_0804BC14: .4byte 0x0000079d
_0804BC18: .4byte 0x0000079e
_0804BC1C: .4byte 0x0000097d
_0804BC20: .4byte 0x00001cd4
_0804BC24: .4byte 0x00001cd8
_0804BC28: .4byte 0x00001cbc
_0804BC2C: .4byte 0x00001cc4
_0804BC30: .4byte 0x00001cc8
_0804BC34: .4byte 0x0000025d
_0804BC38: .4byte 0x0000025e
_0804BC3C: .4byte 0x0000043d
_0804BC40: .4byte 0x0000043e
_0804BC44: .4byte 0x0000061d
_0804BC48: .4byte 0x0000061e
_0804BC4C: .4byte 0x000007fd
_0804BC50: .4byte 0x000007fe
_0804BC54: .4byte 0x000009dd
_0804BC58: .4byte 0x0000097c
_0804BC5C: .4byte 0x0000099b
_0804BC60: .4byte 0x0000099c
_0804BC64: .4byte 0x000009bb
_0804BC68: .4byte 0x000009bc
_0804BC6C: .4byte 0x000009db
_0804BC70: .4byte 0x00001c28
_0804BC74: .4byte 0x00001c64
_0804BC78: .4byte gUnknown_202F1B0
_0804BC7C: .4byte gUnknown_202F1B2
	thumb_func_end sub_804B72C

	thumb_func_start sub_804BC80
sub_804BC80:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0804BED0
	add sp, r4
	movs r1, 0xE5
	lsls r1, 5
	add r1, sp
	str r0, [r1]
	movs r4, 0x1
	movs r5, 0
	ldr r1, _0804BED4
	add r1, sp
	str r5, [r1]
	movs r0, 0xB
	str r0, [r1, 0x4]
	movs r0, 0x16
	str r0, [r1, 0x8]
	movs r0, 0x21
	str r0, [r1, 0xC]
	movs r0, 0x2C
	str r0, [r1, 0x10]
	movs r0, 0x38
	str r0, [r1, 0x14]
	ldr r1, _0804BED8
	add r1, sp
	str r4, [r1]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	movs r0, 0x17
	str r0, [r1, 0xC]
	movs r0, 0x1F
	str r0, [r1, 0x10]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x4
	bl sub_804D084
	add r6, sp, 0x70
	add r1, sp, 0x68
	add r0, sp, 0x8
	movs r3, 0xF0
	lsls r3, 1
	movs r2, 0x5
_0804BCE0:
	strb r4, [r0, 0xA]
	strb r4, [r1, 0xA]
	adds r1, r3
	adds r0, r3
	subs r2, 0x1
	cmp r2, 0
	bne _0804BCE0
	movs r3, 0x5
	subs r3, 0x1
	movs r2, 0x4
	cmp r2, 0
	beq _0804BD1A
	lsls r0, r3, 4
	subs r0, r3
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	add r1, sp, 0x8
	mov r10, r2
_0804BD06:
	strb r4, [r1, 0xA]
	strb r4, [r0, 0xA]
	adds r0, 0x20
	adds r1, 0x20
	movs r2, 0x1
	negs r2, r2
	add r10, r2
	mov r2, r10
	cmp r2, 0
	bne _0804BD06
_0804BD1A:
	movs r2, 0x1
	cmp r2, r3
	bge _0804BD58
	movs r1, 0x3
_0804BD22:
	adds r4, r2, 0x1
	ldr r0, _0804BEDC
	add r0, sp
	str r4, [r0]
	cmp r1, 0x1
	ble _0804BD4E
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	adds r0, 0x20
	subs r2, r1, 0x1
	mov r10, r2
_0804BD3E:
	strb r5, [r0, 0xA]
	adds r0, 0x20
	movs r4, 0x1
	negs r4, r4
	add r10, r4
	mov r2, r10
	cmp r2, 0
	bne _0804BD3E
_0804BD4E:
	ldr r4, _0804BEDC
	add r4, sp
	ldr r2, [r4]
	cmp r2, r3
	blt _0804BD22
_0804BD58:
	add r0, sp, 0x8
	movs r1, 0x1
	strb r1, [r0, 0x8]
	movs r0, 0xF2
	lsls r0, 3
	add r0, sp
	strb r1, [r0]
	strb r1, [r6]
	movs r0, 0xFE
	lsls r0, 3
	add r0, sp
	strb r1, [r0]
	movs r5, 0
	ldr r6, _0804BEE0
	add r6, sp
	str r5, [r6]
	mov r10, r5
	cmp r5, 0x4
	blt _0804BD80
	b _0804BFAC
_0804BD80:
	movs r0, 0x4
	movs r1, 0xE6
	lsls r1, 5
	add r1, sp
	str r0, [r1]
_0804BD8A:
	movs r2, 0
	cmp r2, 0x5
	blt _0804BD92
	b _0804BF94
_0804BD92:
	ldr r3, _0804BED4
	add r3, sp
	ldr r4, _0804BEE4
	add r4, sp
	str r3, [r4]
	ldr r5, _0804BED8
	add r5, sp
	ldr r6, _0804BEE8
	add r6, sp
	str r5, [r6]
	mov r1, r10
	lsls r0, r1, 2
	adds r0, r5, r0
	ldr r3, _0804BEEC
	add r3, sp
	str r0, [r3]
_0804BDB2:
	lsls r0, r2, 4
	subs r0, r2
	add r0, r10
	lsls r0, 5
	mov r7, sp
	adds r7, r0
	adds r7, 0x8
	ldrb r0, [r7, 0x8]
	adds r4, r2, 0x1
	ldr r5, _0804BEDC
	add r5, sp
	str r4, [r5]
	cmp r0, 0
	beq _0804BDD0
	b _0804BF88
_0804BDD0:
	ldrb r0, [r7, 0xA]
	cmp r0, 0
	bne _0804BDD8
	b _0804BF00
_0804BDD8:
	lsls r0, r2, 2
	ldr r6, _0804BEE4
	add r6, sp
	ldr r6, [r6]
	adds r0, r6, r0
	ldr r1, [r0]
	adds r0, r1, 0x2
	mov r9, r0
	ldr r3, _0804BEEC
	add r3, sp
	ldr r3, [r3]
	ldr r2, [r3]
	adds r4, r2, 0x2
	ldr r5, _0804BEF0
	add r5, sp
	str r4, [r5]
	ldr r6, _0804BEDC
	add r6, sp
	ldr r6, [r6]
	lsls r0, r6, 2
	ldr r3, _0804BEE4
	add r3, sp
	ldr r3, [r3]
	adds r0, r3, r0
	ldr r4, [r0]
	subs r4, r1
	subs r4, 0x3
	ldr r5, _0804BEE8
	add r5, sp
	ldr r5, [r5]
	movs r6, 0xE6
	lsls r6, 5
	add r6, sp
	ldr r6, [r6]
	adds r0, r5, r6
	ldr r5, [r0]
	subs r5, r2
	subs r5, 0x3
	movs r0, 0x5
	adds r1, r4, 0
	bl DungeonRandomRange
	mov r8, r0
	movs r0, 0x4
	adds r1, r5, 0
	bl DungeonRandomRange
	adds r6, r0, 0
	mov r0, r8
	subs r4, r0
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	add r4, r9
	subs r5, r6
	adds r0, r5, 0
	bl DungeonRandomCapped
	ldr r2, _0804BEF0
	add r2, sp
	ldr r1, [r2]
	adds r1, r0
	mov r9, r1
	mov r5, r8
	adds r3, r4, r5
	add r6, r9
	strh r4, [r7]
	strh r3, [r7, 0x4]
	strh r1, [r7, 0x2]
	strh r6, [r7, 0x6]
	ldr r1, _0804BEE0
	add r1, sp
	ldr r0, [r1]
	adds r0, 0x1
	ldr r1, _0804BEF4
	add r1, sp
	str r0, [r1]
	cmp r4, r3
	bge _0804BEC0
_0804BE78:
	mov r5, r9
	adds r7, r4, 0x1
	cmp r5, r6
	bge _0804BEBA
	ldr r2, _0804BEF8
	mov r8, r2
_0804BE84:
	adds r0, r4, 0
	adds r1, r5, 0
	ldr r2, _0804BEFC
	add r2, sp
	str r3, [r2]
	bl GetMapTile_2
	ldrh r1, [r0]
	mov r2, r8
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	ldr r1, _0804BEE0
	add r1, sp
	ldrb r1, [r1]
	strb r1, [r0, 0x9]
	adds r5, 0x1
	ldr r2, _0804BEFC
	add r2, sp
	ldr r3, [r2]
	cmp r5, r6
	blt _0804BE84
_0804BEBA:
	adds r4, r7, 0
	cmp r4, r3
	blt _0804BE78
_0804BEC0:
	ldr r3, _0804BEF4
	add r3, sp
	ldr r3, [r3]
	ldr r4, _0804BEE0
	add r4, sp
	str r3, [r4]
	b _0804BF88
	.align 2, 0
_0804BED0: .4byte 0xffffe338
_0804BED4: .4byte 0x00001c28
_0804BED8: .4byte 0x00001c64
_0804BEDC: .4byte 0x00001cb8
_0804BEE0: .4byte 0x00001ca4
_0804BEE4: .4byte 0x00001ca8
_0804BEE8: .4byte 0x00001cb0
_0804BEEC: .4byte 0x00001cb4
_0804BEF0: .4byte 0x00001cac
_0804BEF4: .4byte 0x00001cbc
_0804BEF8: .4byte 0x0000fffc
_0804BEFC: .4byte 0x00001cc4
_0804BF00:
	lsls r0, r2, 2
	ldr r4, _0804C080
	add r4, sp
	ldr r4, [r4]
	adds r0, r4, r0
	ldr r2, [r0]
	adds r0, r2, 0x1
	ldr r5, _0804C084
	add r5, sp
	ldr r5, [r5]
	ldr r3, [r5]
	adds r6, r3, 0x1
	mov r8, r6
	ldr r4, _0804C088
	add r4, sp
	ldr r4, [r4]
	lsls r1, r4, 2
	ldr r5, _0804C080
	add r5, sp
	ldr r5, [r5]
	adds r1, r5, r1
	ldr r1, [r1]
	subs r1, r2
	subs r1, 0x3
	ldr r6, _0804C08C
	add r6, sp
	ldr r6, [r6]
	movs r4, 0xE6
	lsls r4, 5
	add r4, sp
	ldr r4, [r4]
	adds r2, r6, r4
	ldr r4, [r2]
	subs r4, r3
	subs r4, 0x3
	adds r1, r0, r1
	bl DungeonRandomRange
	adds r5, r0, 0
	add r4, r8
	mov r0, r8
	adds r1, r4, 0
	bl DungeonRandomRange
	adds r4, r0, 0
	strh r5, [r7]
	adds r0, r5, 0x1
	strh r0, [r7, 0x4]
	strh r4, [r7, 0x2]
	adds r0, r4, 0x1
	strh r0, [r7, 0x6]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r6, _0804C090
	adds r2, r6, 0
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0xFF
	strb r1, [r0, 0x9]
_0804BF88:
	ldr r0, _0804C088
	add r0, sp
	ldr r2, [r0]
	cmp r2, 0x5
	bge _0804BF94
	b _0804BDB2
_0804BF94:
	movs r2, 0xE6
	lsls r2, 5
	add r2, sp
	ldr r1, [r2]
	adds r1, 0x4
	str r1, [r2]
	movs r3, 0x1
	add r10, r3
	mov r4, r10
	cmp r4, 0x4
	bge _0804BFAC
	b _0804BD8A
_0804BFAC:
	movs r2, 0x1
	movs r1, 0x1
	movs r3, 0xF
	add r4, sp, 0x1C
_0804BFB4:
	movs r5, 0
	mov r10, r5
	lsls r0, r3, 5
	adds r0, r4
_0804BFBC:
	strb r1, [r0]
	strb r1, [r0, 0x1F]
	adds r0, 0x20
	movs r6, 0x1
	add r10, r6
	mov r5, r10
	cmp r5, 0x2
	ble _0804BFBC
	movs r0, 0xF0
	lsls r0, 1
	adds r3, 0xF
	adds r2, 0x1
	cmp r2, 0x3
	ble _0804BFB4
	mov r10, r6
	movs r5, 0x1
	adds r4, r0, 0
	mov r6, sp
	adds r6, r4
	adds r6, 0x8
_0804BFE4:
	movs r2, 0
	mov r1, r10
	lsls r0, r1, 5
	mov r3, r10
	adds r3, 0x1
	adds r1, r0, r6
	add r0, sp
	adds r0, 0x8
_0804BFF4:
	strb r5, [r0, 0x16]
	strb r5, [r1, 0x15]
	adds r1, r4
	adds r0, r4
	adds r2, 0x1
	cmp r2, 0x3
	ble _0804BFF4
	mov r10, r3
	cmp r3, 0x2
	ble _0804BFE4
	ldr r5, _0804C094
	add r5, sp
	ldr r4, _0804C098
	add r4, sp
	str r4, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x4
	adds r3, r5, 0
	bl sub_804D8C8
	str r4, [sp]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x4
	adds r3, r5, 0
	bl sub_804E590
	ldr r0, _0804C09C
	movs r2, 0
	ldrsh r3, [r0, r2]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x4
	bl sub_804EBC8
	ldr r0, _0804C0A0
	movs r4, 0
	ldrsh r3, [r0, r4]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x4
	bl sub_804EEE4
	movs r5, 0xE5
	lsls r5, 5
	add r5, sp
	ldr r5, [r5]
	ldrb r3, [r5, 0x13]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x4
	bl sub_804CBEC
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x4
	bl sub_804E03C
	ldr r3, _0804C0A4
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C080: .4byte 0x00001ca8
_0804C084: .4byte 0x00001cb4
_0804C088: .4byte 0x00001cb8
_0804C08C: .4byte 0x00001cb0
_0804C090: .4byte 0x0000fffc
_0804C094: .4byte 0x00001c28
_0804C098: .4byte 0x00001c64
_0804C09C: .4byte gUnknown_202F1B0
_0804C0A0: .4byte gUnknown_202F1B2
_0804C0A4: .4byte 0x00001cc8
	thumb_func_end sub_804BC80

	thumb_func_start sub_804C0A8
sub_804C0A8:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r4, _0804C17C
	add sp, r4
	adds r6, r0, 0
	ldr r4, _0804C180
	add r4, sp
	movs r0, 0
	str r0, [r4]
	movs r0, 0xB
	str r0, [r4, 0x4]
	movs r0, 0x16
	str r0, [r4, 0x8]
	movs r0, 0x21
	str r0, [r4, 0xC]
	movs r0, 0x2C
	str r0, [r4, 0x10]
	movs r0, 0x38
	str r0, [r4, 0x14]
	ldr r5, _0804C184
	add r5, sp
	movs r0, 0x4
	str r0, [r5]
	movs r0, 0xF
	str r0, [r5, 0x4]
	movs r0, 0x1
	mov r8, r0
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	bl sub_804D084
	movs r3, 0x1
	ldrsb r3, [r6, r3]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	bl sub_804D154
	str r5, [sp]
	ldrb r0, [r6, 0xD]
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	adds r3, r4, 0
	bl sub_804D2D0
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	adds r3, r6, 0
	bl sub_804D5B0
	str r5, [sp]
	mov r1, r8
	str r1, [sp, 0x4]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	adds r3, r4, 0
	bl sub_804D8C8
	str r5, [sp]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	adds r3, r4, 0
	bl sub_804E590
	ldr r0, _0804C188
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	bl sub_804EBC8
	ldr r0, _0804C18C
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	bl sub_804EEE4
	ldrb r3, [r6, 0x13]
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	bl sub_804CBEC
	add r0, sp, 0x8
	movs r1, 0x5
	movs r2, 0x1
	bl sub_804E03C
	movs r3, 0xE5
	lsls r3, 5
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C17C: .4byte 0xffffe360
_0804C180: .4byte 0x00001c28
_0804C184: .4byte 0x00001c64
_0804C188: .4byte gUnknown_202F1B0
_0804C18C: .4byte gUnknown_202F1B2
	thumb_func_end sub_804C0A8

	thumb_func_start sub_804C190
sub_804C190:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0804C2CC
	add sp, r4
	mov r10, r0
	ldr r1, _0804C2D0
	add r1, sp
	movs r2, 0xB
	str r2, [r1]
	movs r0, 0x16
	str r0, [r1, 0x4]
	movs r0, 0x21
	str r0, [r1, 0x8]
	movs r0, 0x2C
	str r0, [r1, 0xC]
	ldr r1, _0804C2D4
	add r1, sp
	movs r0, 0x2
	str r0, [r1]
	str r2, [r1, 0x4]
	movs r0, 0x14
	str r0, [r1, 0x8]
	movs r0, 0x1E
	str r0, [r1, 0xC]
	movs r0, 0x3
	mov r8, r0
	movs r7, 0x3
	add r0, sp, 0x8
	movs r1, 0x3
	movs r2, 0x3
	bl sub_804D084
	movs r1, 0
	add r5, sp, 0x50
	movs r0, 0x3E
	add r0, sp
	mov r9, r0
	mov r0, r10
	ldrb r0, [r0, 0xD]
	mov r12, r0
_0804C1E6:
	adds r3, r1, 0x1
	cmp r7, 0
	beq _0804C204
	lsls r0, r1, 4
	subs r0, r1
	movs r2, 0x1
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	adds r1, r7, 0
_0804C1FA:
	strb r2, [r0, 0xA]
	adds r0, 0x20
	subs r1, 0x1
	cmp r1, 0
	bne _0804C1FA
_0804C204:
	adds r1, r3, 0
	cmp r1, r8
	blt _0804C1E6
	add r0, sp, 0x8
	movs r4, 0x1
	strb r4, [r0, 0x8]
	add r0, sp, 0x3D0
	strb r4, [r0]
	strb r4, [r5]
	movs r0, 0x82
	lsls r0, 3
	add r0, sp
	strb r4, [r0]
	ldr r6, _0804C2D0
	add r6, sp
	ldr r5, _0804C2D4
	add r5, sp
	str r5, [sp]
	mov r1, r12
	str r1, [sp, 0x4]
	add r0, sp, 0x8
	mov r1, r8
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_804D2D0
	mov r0, r9
	strb r4, [r0]
	ldr r0, _0804C2D8
	add r0, sp
	strb r4, [r0]
	ldr r0, _0804C2DC
	add r0, sp
	strb r4, [r0]
	ldr r0, _0804C2E0
	add r0, sp
	strb r4, [r0]
	add r0, sp, 0x1FC
	strb r4, [r0]
	ldr r0, _0804C2E4
	add r0, sp
	strb r4, [r0]
	add r0, sp, 0x21C
	strb r4, [r0]
	ldr r0, _0804C2E8
	add r0, sp
	strb r4, [r0]
	str r5, [sp]
	str r4, [sp, 0x4]
	add r0, sp, 0x8
	mov r1, r8
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_804D8C8
	str r5, [sp]
	add r0, sp, 0x8
	mov r1, r8
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_804E590
	ldr r0, _0804C2EC
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	mov r1, r8
	adds r2, r7, 0
	bl sub_804EBC8
	ldr r0, _0804C2F0
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	mov r1, r8
	adds r2, r7, 0
	bl sub_804EEE4
	mov r0, r10
	ldrb r3, [r0, 0x13]
	add r0, sp, 0x8
	mov r1, r8
	adds r2, r7, 0
	bl sub_804CBEC
	add r0, sp, 0x8
	mov r1, r8
	adds r2, r7, 0
	bl sub_804E03C
	movs r3, 0xE5
	lsls r3, 5
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C2CC: .4byte 0xffffe360
_0804C2D0: .4byte 0x00001c28
_0804C2D4: .4byte 0x00001c64
_0804C2D8: .4byte 0x0000021d
_0804C2DC: .4byte 0x0000021e
_0804C2E0: .4byte 0x000003fd
_0804C2E4: .4byte 0x0000021b
_0804C2E8: .4byte 0x0000023b
_0804C2EC: .4byte gUnknown_202F1B0
_0804C2F0: .4byte gUnknown_202F1B2
	thumb_func_end sub_804C190

	thumb_func_start sub_804C2F4
sub_804C2F4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0804C420
	add sp, r4
	mov r8, r0
	ldr r1, _0804C424
	add r1, sp
	movs r0, 0x5
	str r0, [r1]
	movs r0, 0xF
	str r0, [r1, 0x4]
	movs r0, 0x23
	str r0, [r1, 0x8]
	movs r0, 0x32
	str r0, [r1, 0xC]
	ldr r1, _0804C428
	add r1, sp
	movs r0, 0x2
	str r0, [r1]
	movs r0, 0xB
	str r0, [r1, 0x4]
	movs r0, 0x14
	str r0, [r1, 0x8]
	movs r0, 0x1E
	str r0, [r1, 0xC]
	movs r7, 0x3
	movs r6, 0x3
	add r0, sp, 0x8
	movs r1, 0x3
	movs r2, 0x3
	bl sub_804D084
	movs r1, 0
	mov r0, r8
	ldrb r4, [r0, 0xD]
_0804C33C:
	adds r3, r1, 0x1
	cmp r6, 0
	beq _0804C35A
	lsls r0, r1, 4
	subs r0, r1
	movs r2, 0x1
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	adds r1, r6, 0
_0804C350:
	strb r2, [r0, 0xA]
	adds r0, 0x20
	subs r1, 0x1
	cmp r1, 0
	bne _0804C350
_0804C35A:
	adds r1, r3, 0
	cmp r1, r7
	blt _0804C33C
	ldr r3, _0804C424
	add r3, sp
	ldr r0, _0804C428
	add r0, sp
	str r0, [sp]
	str r4, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804D2D0
	movs r4, 0x1
	ldr r3, _0804C42C
	add r3, sp
	ldr r0, _0804C430
	add r0, sp
	add r2, sp, 0x8
	movs r1, 0x2
_0804C384:
	strb r4, [r2, 0x16]
	strb r4, [r0]
	strb r4, [r0, 0x1]
	strb r4, [r3]
	adds r3, 0x20
	adds r0, 0x20
	adds r2, 0x20
	subs r1, 0x1
	cmp r1, 0
	bge _0804C384
	ldr r5, _0804C424
	add r5, sp
	ldr r4, _0804C428
	add r4, sp
	str r4, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_804D8C8
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	add r3, sp, 0x8
	bl sub_804C43C
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x2
	add r3, sp, 0x8
	bl sub_804C43C
	str r4, [sp]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_804E590
	ldr r0, _0804C434
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804EBC8
	ldr r0, _0804C438
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804EEE4
	mov r0, r8
	ldrb r3, [r0, 0x13]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804CBEC
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804E03C
	movs r3, 0xE5
	lsls r3, 5
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C420: .4byte 0xffffe360
_0804C424: .4byte 0x00001c28
_0804C428: .4byte 0x00001c64
_0804C42C: .4byte 0x000003dd
_0804C430: .4byte 0x000001fd
_0804C434: .4byte gUnknown_202F1B0
_0804C438: .4byte gUnknown_202F1B2
	thumb_func_end sub_804C2F4

	thumb_func_start sub_804C43C
sub_804C43C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp]
	str r3, [sp, 0x4]
	lsls r7, r1, 5
	lsls r0, 4
	str r0, [sp, 0xC]
	ldr r3, [sp]
	subs r0, r3
	lsls r0, 5
	ldr r4, [sp, 0x4]
	adds r0, r4
	adds r3, r7, r0
	adds r6, r1, r2
	lsls r1, r6, 5
	adds r2, r1, r0
	movs r5, 0
	ldrsh r1, [r2, r5]
	adds r4, r1, 0
	ldrh r0, [r3]
	mov r8, r0
	movs r5, 0
	ldrsh r0, [r3, r5]
	cmp r1, r0
	ble _0804C478
	mov r4, r8
_0804C478:
	lsls r0, r4, 16
	asrs r0, 16
	str r0, [sp, 0x8]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	mov r10, r0
	movs r4, 0x4
	ldrsh r1, [r2, r4]
	adds r4, r1, 0
	ldrh r5, [r3, 0x4]
	mov r8, r5
	movs r5, 0x4
	ldrsh r0, [r3, r5]
	cmp r1, r0
	bge _0804C498
	mov r4, r8
_0804C498:
	lsls r0, r4, 16
	asrs r0, 16
	str r0, [sp, 0x10]
	movs r1, 0x6
	ldrsh r0, [r2, r1]
	mov r8, r0
	movs r2, 0
	ldrsh r0, [r3, r2]
	mov r1, r10
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	mov r9, r0
	ldr r5, [sp, 0x8]
	str r7, [sp, 0x1C]
	ldr r3, [sp, 0xC]
	str r3, [sp, 0x18]
	str r6, [sp, 0x14]
	ldr r4, [sp, 0x10]
	cmp r5, r4
	bge _0804C4F2
_0804C4C2:
	mov r4, r10
	adds r6, r5, 0x1
	cmp r10, r8
	bge _0804C4EA
	ldr r0, _0804C538
	adds r7, r0, 0
_0804C4CE:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ands r1, r7
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r1, r9
	strb r1, [r0, 0x9]
	adds r4, 0x1
	cmp r4, r8
	blt _0804C4CE
_0804C4EA:
	adds r5, r6, 0
	ldr r2, [sp, 0x10]
	cmp r5, r2
	blt _0804C4C2
_0804C4F2:
	ldr r3, [sp, 0x18]
	ldr r4, [sp]
	subs r1, r3, r4
	lsls r1, 5
	ldr r5, [sp, 0x4]
	adds r1, r5
	ldr r0, [sp, 0x1C]
	adds r2, r0, r1
	movs r3, 0
	mov r4, sp
	ldrh r4, [r4, 0x8]
	strh r4, [r2]
	mov r5, sp
	ldrh r5, [r5, 0x10]
	strh r5, [r2, 0x4]
	mov r0, r10
	strh r0, [r2, 0x2]
	mov r4, r8
	strh r4, [r2, 0x6]
	ldr r5, [sp, 0x14]
	lsls r0, r5, 5
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0, 0x12]
	strb r1, [r2, 0x12]
	strb r3, [r0, 0xB]
	strb r1, [r0, 0x11]
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C538: .4byte 0x0000fffc
	thumb_func_end sub_804C43C

	thumb_func_start sub_804C53C
sub_804C53C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0804C6F8
	add sp, r4
	mov r10, r2
	adds r7, r0, 0
	adds r6, r1, 0
	ldr r0, _0804C6FC
	add r0, sp
	ldr r1, _0804C700
	add r1, sp
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_804D024
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804D084
	movs r2, 0
	cmp r2, r7
	bge _0804C594
_0804C570:
	adds r3, r2, 0x1
	cmp r6, 0
	ble _0804C58E
	lsls r0, r2, 4
	subs r0, r2
	movs r2, 0x1
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	adds r1, r6, 0
_0804C584:
	strb r2, [r0, 0xA]
	adds r0, 0x20
	subs r1, 0x1
	cmp r1, 0
	bne _0804C584
_0804C58E:
	adds r2, r3, 0
	cmp r2, r7
	blt _0804C570
_0804C594:
	movs r2, 0x1
	subs r0, r7, 0x1
	mov r8, r0
	subs r1, r6, 0x1
	mov r9, r1
	mov r0, r10
	ldrb r0, [r0, 0xD]
	mov r12, r0
	cmp r2, r8
	bge _0804C5D2
	mov r4, r9
	mov r5, r8
_0804C5AC:
	adds r3, r2, 0x1
	cmp r4, 0x1
	ble _0804C5CC
	lsls r0, r2, 4
	subs r0, r2
	movs r2, 0x1
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	adds r0, 0x20
	subs r1, r4, 0x1
_0804C5C2:
	strb r2, [r0, 0x8]
	adds r0, 0x20
	subs r1, 0x1
	cmp r1, 0
	bne _0804C5C2
_0804C5CC:
	adds r2, r3, 0
	cmp r2, r5
	blt _0804C5AC
_0804C5D2:
	ldr r3, _0804C6FC
	add r3, sp
	ldr r0, _0804C700
	add r0, sp
	str r0, [sp]
	mov r1, r12
	str r1, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804D2D0
	movs r2, 0
	cmp r2, r8
	bge _0804C636
	movs r4, 0x1
	mov r0, r9
	lsls r5, r0, 5
	subs r1, r7, 0x2
	mov r12, r1
_0804C5FA:
	cmp r2, 0
	beq _0804C614
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	mov r1, sp
	adds r1, r0
	adds r1, 0x8
	strb r4, [r1, 0x16]
	adds r0, r5, r0
	add r0, sp
	adds r0, 0x8
	strb r4, [r0, 0x16]
_0804C614:
	adds r3, r2, 0x1
	cmp r2, r12
	bge _0804C630
	lsls r0, r3, 4
	subs r0, r3
	lsls r0, 5
	mov r1, sp
	adds r1, r0
	adds r1, 0x8
	strb r4, [r1, 0x15]
	adds r0, r5, r0
	add r0, sp
	adds r0, 0x8
	strb r4, [r0, 0x15]
_0804C630:
	adds r2, r3, 0
	cmp r2, r8
	blt _0804C5FA
_0804C636:
	movs r1, 0
	cmp r1, r9
	bge _0804C66A
	movs r3, 0x1
	mov r2, r8
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	add r0, sp
	adds r0, 0x8
	add r2, sp, 0x8
	subs r5, r6, 0x2
	mov r4, r9
_0804C650:
	cmp r1, 0
	beq _0804C658
	strb r3, [r2, 0x13]
	strb r3, [r0, 0x13]
_0804C658:
	cmp r1, r5
	bge _0804C660
	strb r3, [r2, 0x14]
	strb r3, [r0, 0x14]
_0804C660:
	adds r0, 0x20
	adds r2, 0x20
	adds r1, 0x1
	cmp r1, r4
	blt _0804C650
_0804C66A:
	ldr r5, _0804C6FC
	add r5, sp
	ldr r4, _0804C700
	add r4, sp
	str r4, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_804D8C8
	str r4, [sp]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	adds r3, r5, 0
	bl sub_804E590
	mov r0, r10
	ldrb r3, [r0, 0x9]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804F0D0
	ldr r0, _0804C704
	movs r1, 0
	ldrsh r3, [r0, r1]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804EBC8
	ldr r0, _0804C708
	movs r2, 0
	ldrsh r3, [r0, r2]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804EEE4
	mov r0, r10
	ldrb r3, [r0, 0x13]
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804CBEC
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804E03C
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_804D534
	movs r3, 0xE5
	lsls r3, 5
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C6F8: .4byte 0xffffe360
_0804C6FC: .4byte 0x00001c28
_0804C700: .4byte 0x00001c64
_0804C704: .4byte gUnknown_202F1B0
_0804C708: .4byte gUnknown_202F1B2
	thumb_func_end sub_804C53C

	thumb_func_start sub_804C70C
sub_804C70C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r7, r0, 0
	mov r8, r1
	ldr r0, _0804C73C
	ldr r0, [r0]
	ldr r1, _0804C740
	adds r0, r1
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r5, [r0]
	ldrb r6, [r0, 0x1]
	cmp r5, 0
	beq _0804C736
	cmp r6, 0
	bne _0804C744
_0804C736:
	bl sub_804C918
	b _0804C782
	.align 2, 0
_0804C73C: .4byte gDungeonGlobalData
_0804C740: .4byte 0x00013568
_0804C744:
	cmp r7, 0x31
	bgt _0804C752
	adds r0, r7, 0
	bl sub_8051288
	movs r0, 0x1
	b _0804C784
_0804C752:
	adds r1, r5, 0x4
	movs r0, 0x38
	bl __divsi3
	adds r4, r0, 0
	cmp r4, 0x1
	bgt _0804C762
	movs r4, 0x1
_0804C762:
	adds r1, r6, 0x4
	movs r0, 0x20
	bl __divsi3
	adds r1, r0, 0
	cmp r1, 0x1
	bgt _0804C772
	movs r1, 0x1
_0804C772:
	str r7, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_804C790
_0804C782:
	movs r0, 0
_0804C784:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_804C70C

	thumb_func_start sub_804C790
sub_804C790:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0804C81C
	add sp, r4
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r0, _0804C820
	add r0, sp
	str r2, [r0]
	ldr r1, _0804C824
	add r1, sp
	str r3, [r1]
	movs r2, 0
	mov r10, r2
	mov r8, r2
	ldr r0, _0804C828
	add r0, sp
	ldr r1, _0804C82C
	add r1, sp
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_804D024
	add r0, sp, 0x10
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_804D084
	ldr r0, _0804C830
	add r0, sp
	ldr r0, [r0]
	movs r3, 0x1
	ldrsb r3, [r0, r3]
	add r0, sp, 0x10
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_804D154
	mov r6, r8
	cmp r8, r5
	bge _0804C818
_0804C7E8:
	movs r1, 0
	mov r8, r1
	adds r2, r6, 0x1
	cmp r8, r4
	bge _0804C812
	lsls r0, r6, 4
	subs r0, r6
	movs r1, 0x1
	lsls r0, 5
	add r0, sp
	adds r0, 0x10
	mov r8, r4
_0804C800:
	strb r1, [r0, 0x1B]
	adds r0, 0x20
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r3, r8
	cmp r3, 0
	bne _0804C800
	mov r8, r4
_0804C812:
	adds r6, r2, 0
	cmp r6, r5
	blt _0804C7E8
_0804C818:
	movs r7, 0
	b _0804C836
	.align 2, 0
_0804C81C: .4byte 0xffffe350
_0804C820: .4byte 0x00001ca8
_0804C824: .4byte 0x00001cac
_0804C828: .4byte 0x00001c30
_0804C82C: .4byte 0x00001c6c
_0804C830: .4byte 0x00001cd4
_0804C834:
	adds r7, 0x1
_0804C836:
	cmp r7, 0x3F
	bgt _0804C864
	adds r0, r5, 0
	bl DungeonRandomCapped
	adds r6, r0, 0
	adds r0, r4, 0
	bl DungeonRandomCapped
	mov r8, r0
	mov r0, r8
	muls r0, r5
	adds r0, r6
	mov r10, r0
	lsls r0, r6, 4
	subs r0, r6
	add r0, r8
	lsls r0, 5
	add r0, sp
	adds r0, 0x10
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _0804C834
_0804C864:
	ldr r0, _0804C8FC
	add r0, sp
	mov r9, r0
	ldr r7, _0804C900
	add r7, sp
	str r7, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r2, _0804C904
	add r2, sp
	ldr r2, [r2]
	str r2, [sp, 0x8]
	ldr r3, _0804C908
	add r3, sp
	ldr r3, [r3]
	str r3, [sp, 0xC]
	add r0, sp, 0x10
	adds r1, r5, 0
	adds r2, r4, 0
	mov r3, r9
	bl sub_8050F90
	cmp r5, 0x1
	bne _0804C898
	cmp r4, 0x1
	beq _0804C8D0
_0804C898:
	mov r0, r8
	str r0, [sp]
	ldr r1, _0804C90C
	add r1, sp
	ldr r1, [r1]
	str r1, [sp, 0x4]
	add r0, sp, 0x10
	adds r1, r5, 0
	adds r2, r4, 0
	adds r3, r6, 0
	bl sub_804D5F0
	str r7, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	add r0, sp, 0x10
	adds r1, r5, 0
	adds r2, r4, 0
	mov r3, r9
	bl sub_804D8C8
	str r7, [sp]
	add r0, sp, 0x10
	adds r1, r5, 0
	adds r2, r4, 0
	mov r3, r9
	bl sub_804E590
_0804C8D0:
	lsls r0, r6, 4
	subs r0, r6
	lsls r0, 5
	add r0, sp
	adds r0, 0x10
	mov r2, r8
	lsls r1, r2, 5
	adds r0, r1
	ldr r3, _0804C910
	add r3, sp
	ldr r1, [r3]
	bl sub_8051438
	ldr r3, _0804C914
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C8FC: .4byte 0x00001c30
_0804C900: .4byte 0x00001c6c
_0804C904: .4byte 0x00001ca8
_0804C908: .4byte 0x00001cac
_0804C90C: .4byte 0x00001cd4
_0804C910: .4byte 0x00001cd0
_0804C914: .4byte 0x00001cb0
	thumb_func_end sub_804C790

	thumb_func_start sub_804C918
sub_804C918:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _0804C9C4
	add sp, r4
	mov r0, sp
	movs r1, 0x1
	movs r2, 0x1
	bl sub_804D084
	mov r0, sp
	movs r3, 0
	movs r2, 0x2
	strh r2, [r0]
	mov r1, sp
	movs r0, 0x36
	strh r0, [r1, 0x4]
	mov r0, sp
	strh r2, [r0, 0x2]
	movs r0, 0x1E
	strh r0, [r1, 0x6]
	mov r0, sp
	movs r1, 0x1
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	strb r3, [r0, 0x8]
	movs r1, 0
	ldrsh r5, [r0, r1]
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge _0804C9A6
	mov r6, sp
_0804C95C:
	movs r0, 0x2
	ldrsh r4, [r6, r0]
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _0804C99C
	movs r2, 0
	mov r9, r2
	ldr r0, _0804C9C8
	mov r8, r0
_0804C972:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	mov r2, r8
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	mov r1, r9
	strb r1, [r0, 0x9]
	adds r4, 0x1
	movs r2, 0x6
	ldrsh r0, [r6, r2]
	cmp r4, r0
	blt _0804C972
_0804C99C:
	adds r5, r7, 0
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	cmp r5, r0
	blt _0804C95C
_0804C9A6:
	ldr r3, _0804C9CC
	mov r0, sp
	movs r1, 0x1
	movs r2, 0x1
	bl sub_804EEE4
	movs r3, 0xE1
	lsls r3, 5
	add sp, r3
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C9C4: .4byte 0xffffe3e0
_0804C9C8: .4byte 0x0000fffc
_0804C9CC: .4byte 0x000003e7
	thumb_func_end sub_804C918

	thumb_func_start sub_804C9D0
sub_804C9D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0804CBB4
	add sp, r4
	movs r0, 0
	movs r1, 0xE5
	lsls r1, 5
	add r1, sp
	str r0, [r1]
	ldr r1, _0804CBB8
	add r1, sp
	movs r2, 0x2
	str r2, [r1]
	movs r0, 0x1C
	str r0, [r1, 0x4]
	movs r0, 0x36
	str r0, [r1, 0x8]
	ldr r1, _0804CBBC
	add r1, sp
	str r2, [r1]
	movs r0, 0x1E
	str r0, [r1, 0x4]
	add r0, sp, 0x8
	movs r1, 0x2
	movs r2, 0x1
	bl sub_804D084
	movs r0, 0
	ldr r2, _0804CBB8
	add r2, sp
	ldr r3, _0804CBC0
	add r3, sp
	str r2, [r3]
	ldr r4, _0804CBBC
	add r4, sp
	ldr r1, _0804CBC4
	add r1, sp
	str r4, [r1]
_0804CA22:
	movs r7, 0
	lsls r2, r0, 2
	ldr r3, _0804CBC8
	add r3, sp
	str r2, [r3]
	adds r4, r0, 0x1
	ldr r1, _0804CBCC
	add r1, sp
	str r4, [r1]
	lsls r0, 5
	ldr r2, _0804CBD0
	add r2, sp
	str r0, [r2]
_0804CA3C:
	lsls r0, r7, 2
	ldr r3, _0804CBC0
	add r3, sp
	ldr r3, [r3]
	adds r0, r3, r0
	ldr r1, [r0]
	adds r4, r1, 0x1
	mov r10, r4
	ldr r2, _0804CBC4
	add r2, sp
	ldr r2, [r2]
	ldr r3, _0804CBC8
	add r3, sp
	ldr r3, [r3]
	adds r0, r2, r3
	ldr r2, [r0]
	adds r4, r2, 0x1
	ldr r0, _0804CBD4
	add r0, sp
	str r4, [r0]
	adds r3, r7, 0x1
	mov r9, r3
	lsls r0, r3, 2
	ldr r4, _0804CBC0
	add r4, sp
	ldr r4, [r4]
	adds r0, r4, r0
	ldr r4, [r0]
	subs r4, r1
	subs r4, 0x3
	ldr r1, _0804CBCC
	add r1, sp
	ldr r1, [r1]
	lsls r0, r1, 2
	ldr r3, _0804CBC4
	add r3, sp
	ldr r3, [r3]
	adds r0, r3, r0
	ldr r5, [r0]
	subs r5, r2
	subs r5, 0x3
	movs r0, 0xA
	adds r1, r4, 0
	bl DungeonRandomRange
	mov r8, r0
	movs r0, 0x10
	adds r1, r5, 0
	bl DungeonRandomRange
	adds r6, r0, 0
	mov r0, r8
	subs r4, r0
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	add r4, r10
	subs r5, r6
	adds r0, r5, 0
	bl DungeonRandomCapped
	ldr r2, _0804CBD4
	add r2, sp
	ldr r1, [r2]
	adds r1, r0
	mov r10, r1
	mov r0, r8
	adds r3, r4, r0
	add r6, r10
	lsls r0, r7, 4
	subs r0, r7
	lsls r0, 5
	ldr r1, _0804CBD0
	add r1, sp
	ldr r1, [r1]
	adds r0, r1, r0
	add r0, sp
	adds r0, 0x8
	movs r1, 0x1
	strb r1, [r0, 0xA]
	strh r4, [r0]
	strh r3, [r0, 0x4]
	mov r2, r10
	strh r2, [r0, 0x2]
	strh r6, [r0, 0x6]
	mov r0, r9
	ldr r1, _0804CBD8
	add r1, sp
	str r0, [r1]
	movs r0, 0xE5
	lsls r0, 5
	add r0, sp
	ldr r2, [r0]
	adds r2, 0x1
	mov r9, r2
	cmp r4, r3
	bge _0804CB4E
_0804CB00:
	mov r5, r10
	adds r7, r4, 0x1
	cmp r5, r6
	bge _0804CB48
	ldr r1, _0804CBDC
	mov r8, r1
_0804CB0C:
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0xE6
	lsls r2, 5
	add r2, sp
	str r3, [r2]
	bl GetMapTile_2
	ldrh r1, [r0]
	mov r2, r8
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	movs r1, 0xE5
	lsls r1, 5
	add r1, sp
	ldrb r1, [r1]
	strb r1, [r0, 0x9]
	adds r5, 0x1
	movs r2, 0xE6
	lsls r2, 5
	add r2, sp
	ldr r3, [r2]
	cmp r5, r6
	blt _0804CB0C
_0804CB48:
	adds r4, r7, 0
	cmp r4, r3
	blt _0804CB00
_0804CB4E:
	mov r3, r9
	movs r4, 0xE5
	lsls r4, 5
	add r4, sp
	str r3, [r4]
	ldr r0, _0804CBD8
	add r0, sp
	ldr r7, [r0]
	cmp r7, 0x1
	bgt _0804CB64
	b _0804CA3C
_0804CB64:
	ldr r1, _0804CBCC
	add r1, sp
	ldr r0, [r1]
	cmp r0, 0
	bgt _0804CB70
	b _0804CA22
_0804CB70:
	add r0, sp, 0x8
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0, 0x16]
	ldr r0, _0804CBE0
	add r0, sp
	strb r1, [r0]
	ldr r3, _0804CBB8
	add r3, sp
	ldr r0, _0804CBBC
	add r0, sp
	str r0, [sp]
	str r2, [sp, 0x4]
	add r0, sp, 0x8
	movs r1, 0x2
	movs r2, 0x1
	bl sub_804D8C8
	ldr r3, _0804CBE4
	add r0, sp, 0x8
	movs r1, 0x2
	movs r2, 0x1
	bl sub_804EEE4
	ldr r3, _0804CBE8
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804CBB4: .4byte 0xffffe33c
_0804CBB8: .4byte 0x00001c28
_0804CBBC: .4byte 0x00001c64
_0804CBC0: .4byte 0x00001ca4
_0804CBC4: .4byte 0x00001cac
_0804CBC8: .4byte 0x00001cb0
_0804CBCC: .4byte 0x00001cbc
_0804CBD0: .4byte 0x00001cb4
_0804CBD4: .4byte 0x00001ca8
_0804CBD8: .4byte 0x00001cb8
_0804CBDC: .4byte 0x0000fffc
_0804CBE0: .4byte 0x000001fd
_0804CBE4: .4byte 0x000003e7
_0804CBE8: .4byte 0x00001cc4
	thumb_func_end sub_804C9D0

	thumb_func_start sub_804CBEC
sub_804CBEC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	cmp r3, 0
	bne _0804CC06
	b _0804D006
_0804CC06:
	movs r5, 0
	cmp r5, r3
	blt _0804CC0E
	b _0804D006
_0804CC0E:
	ldr r0, [sp, 0x4]
	bl DungeonRandomCapped
	mov r9, r0
	ldr r0, [sp, 0x8]
	bl DungeonRandomCapped
	mov r10, r0
	lsls r0, 5
	mov r2, r9
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 5
	ldr r3, [sp]
	adds r1, r3
	adds r4, r0, r1
	ldrb r0, [r4, 0xA]
	adds r5, 0x1
	str r5, [sp, 0x18]
	cmp r0, 0
	bne _0804CC3A
	b _0804CFFC
_0804CC3A:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _0804CC42
	b _0804CFFC
_0804CC42:
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0804CC4A
	b _0804CFFC
_0804CC4A:
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq _0804CC52
	b _0804CFFC
_0804CC52:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	bl DungeonRandomRange
	adds r7, r0, 0
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl DungeonRandomRange
	adds r6, r0, 0
	movs r0, 0x4
	bl DungeonRandomCapped
	lsls r0, 1
	mov r8, r0
	ldr r1, [sp, 0x8]
	subs r1, 0x1
	movs r3, 0x2
	str r3, [sp, 0x10]
	ldr r0, [sp, 0x4]
	subs r0, 0x1
_0804CC84:
	mov r2, r8
	cmp r2, 0
	bne _0804CC92
	cmp r10, r1
	blt _0804CC92
	movs r3, 0x2
	mov r8, r3
_0804CC92:
	mov r2, r8
	cmp r2, 0x2
	bne _0804CCA0
	cmp r9, r0
	blt _0804CCA0
	movs r3, 0x4
	mov r8, r3
_0804CCA0:
	mov r2, r8
	cmp r2, 0x4
	bne _0804CCB0
	mov r3, r10
	cmp r3, 0
	bgt _0804CCB0
	movs r2, 0x6
	mov r8, r2
_0804CCB0:
	mov r3, r8
	cmp r3, 0x6
	bne _0804CCC0
	mov r2, r9
	cmp r2, 0
	bgt _0804CCC0
	movs r3, 0
	mov r8, r3
_0804CCC0:
	ldr r2, [sp, 0x10]
	subs r2, 0x1
	str r2, [sp, 0x10]
	cmp r2, 0
	bge _0804CC84
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrb r5, [r0, 0x9]
	ldr r1, _0804CCE0
	mov r3, r8
	lsls r0, r3, 2
	adds r4, r0, r1
	b _0804CCF0
	.align 2, 0
_0804CCE0: .4byte gAdjacentTileOffsets
_0804CCE4:
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r7, r0
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r6, r0
_0804CCF0:
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r5, r0
	beq _0804CCE4
	ldr r1, _0804CD08
	mov r3, r8
	lsls r0, r3, 2
	adds r4, r0, r1
	b _0804CD18
	.align 2, 0
_0804CD08: .4byte gAdjacentTileOffsets
_0804CD0C:
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r7, r0
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r6, r0
_0804CD18:
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r5, 0x3
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x1
	beq _0804CD0C
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x2
	bne _0804CD40
	b _0804CFFC
_0804CD40:
	movs r3, 0
	subs r2, r7, 0x2
	adds r4, r7, 0x2
	b _0804CD4A
_0804CD48:
	adds r2, 0x1
_0804CD4A:
	cmp r2, r4
	bgt _0804CD6C
	subs r0, r6, 0x2
	adds r1, r6, 0x2
	b _0804CD56
_0804CD54:
	adds r0, 0x1
_0804CD56:
	cmp r0, r1
	bgt _0804CD68
	cmp r2, 0x37
	bhi _0804CD66
	cmp r0, 0
	blt _0804CD66
	cmp r0, 0x1F
	ble _0804CD54
_0804CD66:
	movs r3, 0x1
_0804CD68:
	cmp r3, 0
	beq _0804CD48
_0804CD6C:
	cmp r3, 0
	beq _0804CD72
	b _0804CFFC
_0804CD72:
	ldr r2, _0804CDD4
	mov r1, r8
	adds r1, 0x2
	movs r4, 0x6
	ands r1, r4
	lsls r1, 2
	adds r1, r2
	movs r3, 0
	ldrsh r0, [r1, r3]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r0, r7, r0
	adds r1, r6, r1
	str r2, [sp, 0x1C]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r5, 0x3
	adds r0, r5, 0
	ands r0, r1
	ldr r2, [sp, 0x1C]
	cmp r0, 0x1
	bne _0804CDA2
	b _0804CFFC
_0804CDA2:
	mov r1, r8
	subs r1, 0x2
	ands r1, r4
	lsls r1, 2
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r0, r7, r0
	adds r1, r6, r1
	bl GetMapTile_1
	ldrh r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CDC8
	b _0804CFFC
_0804CDC8:
	movs r0, 0x3
	bl DungeonRandomCapped
	adds r0, 0x3
	str r0, [sp, 0x10]
	b _0804CFD4
	.align 2, 0
_0804CDD4: .4byte gAdjacentTileOffsets
_0804CDD8:
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0804CDEC
	b _0804CFFC
_0804CDEC:
	movs r0, 0x1
	str r0, [sp, 0x14]
	adds r4, r7, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r10
	ands r0, r1
	mov r9, r4
	cmp r0, 0x1
	bne _0804CE32
	adds r5, r6, 0x1
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r0, [r0]
	mov r4, r10
	ands r4, r0
	cmp r4, 0x1
	bne _0804CE32
	adds r0, r7, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r0, [r0]
	mov r1, r10
	ands r0, r1
	eors r0, r4
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x14]
_0804CE32:
	mov r0, r9
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r5, 0x3
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CE70
	subs r4, r6, 0x1
	mov r0, r9
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CE70
	adds r0, r7, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CE70
	movs r2, 0
	str r2, [sp, 0x14]
_0804CE70:
	subs r4, r7, 0x1
	adds r0, r4, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r2, 0x3
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CEB6
	adds r5, r6, 0x1
	adds r0, r4, 0
	adds r1, r5, 0
	str r2, [sp, 0x1C]
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x1C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CEB6
	adds r0, r7, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x1C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CEB6
	movs r3, 0
	str r3, [sp, 0x14]
_0804CEB6:
	adds r0, r4, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r2, 0x3
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CEFA
	subs r5, r6, 0x1
	adds r0, r4, 0
	adds r1, r5, 0
	str r2, [sp, 0x1C]
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x1C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CEFA
	adds r0, r7, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x1C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x1
	bne _0804CEFA
	movs r0, 0
	str r0, [sp, 0x14]
_0804CEFA:
	ldr r1, [sp, 0x14]
	cmp r1, 0
	beq _0804CF16
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, _0804D018
	adds r2, r3, 0
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
_0804CF16:
	ldr r2, _0804D01C
	movs r0, 0x2
	add r0, r8
	mov r9, r0
	movs r1, 0x6
	mov r10, r1
	mov r1, r9
	mov r3, r10
	ands r1, r3
	lsls r1, 2
	adds r1, r2
	movs r3, 0
	ldrsh r0, [r1, r3]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r0, r7, r0
	adds r1, r6, r1
	str r2, [sp, 0x1C]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r5, 0x3
	adds r0, r5, 0
	ands r0, r1
	ldr r2, [sp, 0x1C]
	cmp r0, 0x1
	beq _0804CFFC
	mov r4, r8
	subs r4, 0x2
	adds r1, r4, 0
	mov r0, r10
	ands r1, r0
	lsls r1, 2
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r0, r7, r0
	adds r1, r6, r1
	bl GetMapTile_1
	ldrh r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0x1
	beq _0804CFFC
	ldr r0, [sp, 0x10]
	subs r0, 0x1
	str r0, [sp, 0x10]
	cmp r0, 0
	bne _0804CFC0
	movs r0, 0x3
	bl DungeonRandomCapped
	adds r0, 0x3
	str r0, [sp, 0x10]
	movs r0, 0x64
	bl DungeonRandomCapped
	mov r8, r4
	cmp r0, 0x31
	bgt _0804CF96
	mov r8, r9
_0804CF96:
	mov r1, r8
	mov r2, r10
	ands r1, r2
	mov r8, r1
	cmp r7, 0x1F
	ble _0804CFAE
	ldr r0, _0804D020
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0804CFAE
	cmp r1, 0x2
	beq _0804CFFC
_0804CFAE:
	cmp r7, 0x2F
	ble _0804CFC0
	ldr r0, _0804D020
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0804CFC0
	mov r3, r8
	cmp r3, 0x2
	beq _0804CFFC
_0804CFC0:
	ldr r0, _0804D01C
	mov r2, r8
	lsls r1, r2, 2
	adds r1, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	adds r7, r0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r6, r0
_0804CFD4:
	cmp r7, 0x1
	ble _0804CFFC
	cmp r6, 0x1
	ble _0804CFFC
	cmp r7, 0x36
	bgt _0804CFFC
	cmp r6, 0x1E
	bgt _0804CFFC
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r3, 0x3
	mov r10, r3
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	beq _0804CFFC
	b _0804CDD8
_0804CFFC:
	ldr r5, [sp, 0x18]
	ldr r0, [sp, 0xC]
	cmp r5, r0
	bge _0804D006
	b _0804CC0E
_0804D006:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D018: .4byte 0x0000fffc
_0804D01C: .4byte gAdjacentTileOffsets
_0804D020: .4byte gUnknown_202F1AE
	thumb_func_end sub_804CBEC

	thumb_func_start sub_804D024
sub_804D024:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	mov r8, r1
	adds r5, r2, 0
	adds r6, r3, 0
	movs r4, 0
	cmp r4, r5
	bge _0804D04E
	movs r0, 0x38
	adds r1, r5, 0
	bl __divsi3
	adds r2, r7, 0
	adds r1, r5, 0
_0804D044:
	stm r2!, {r4}
	adds r4, r0
	subs r1, 0x1
	cmp r1, 0
	bne _0804D044
_0804D04E:
	lsls r0, r5, 2
	adds r0, r7
	str r4, [r0]
	movs r4, 0
	lsls r5, r6, 2
	cmp r4, r6
	bge _0804D072
	movs r0, 0x20
	adds r1, r6, 0
	bl __divsi3
	mov r2, r8
	adds r1, r6, 0
_0804D068:
	stm r2!, {r4}
	adds r4, r0
	subs r1, 0x1
	cmp r1, 0
	bne _0804D068
_0804D072:
	mov r1, r8
	adds r0, r5, r1
	str r4, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804D024

	thumb_func_start sub_804D084
sub_804D084:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	adds r5, r1, 0
	mov r9, r2
	movs r2, 0
	cmp r2, r5
	bge _0804D144
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r0, 1
	str r0, [sp]
	movs r3, 0
_0804D0A6:
	adds r0, r2, 0x1
	mov r10, r0
	mov r4, r9
	cmp r4, 0
	ble _0804D13E
	ldr r6, _0804D0D8
	ldrb r6, [r6]
	str r6, [sp, 0x4]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	mov r4, r8
	adds r1, r0, r4
	movs r7, 0
	movs r6, 0x1
	mov r12, r6
	mov r4, r9
_0804D0C8:
	ldr r0, [sp, 0x4]
	cmp r0, 0x1
	bne _0804D0DC
	ldr r6, [sp]
	cmp r2, r6
	blt _0804D0DC
	strb r0, [r1, 0x8]
	b _0804D102
	.align 2, 0
_0804D0D8: .4byte gUnknown_202F1AE
_0804D0DC:
	ldr r6, _0804D0FC
	ldrb r0, [r6]
	cmp r0, 0x2
	bne _0804D100
	lsls r0, r5, 1
	adds r0, r5
	cmp r0, 0
	bge _0804D0EE
	adds r0, 0x3
_0804D0EE:
	asrs r0, 2
	cmp r2, r0
	blt _0804D100
	mov r0, r12
	strb r0, [r1, 0x8]
	b _0804D102
	.align 2, 0
_0804D0FC: .4byte gUnknown_202F1AE
_0804D100:
	strb r3, [r1, 0x8]
_0804D102:
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	add r0, r8
	adds r0, r7, r0
	mov r6, r12
	strb r6, [r0, 0xA]
	strb r3, [r0, 0xB]
	strb r3, [r0, 0xF]
	strb r3, [r0, 0xE]
	strb r3, [r0, 0xC]
	strb r3, [r0, 0x16]
	strb r3, [r0, 0x15]
	strb r3, [r0, 0x14]
	strb r3, [r0, 0x13]
	strb r3, [r0, 0x1A]
	strb r3, [r0, 0x19]
	strb r3, [r0, 0x18]
	strb r3, [r0, 0x17]
	strb r3, [r0, 0x9]
	strb r3, [r0, 0x11]
	strb r3, [r0, 0x10]
	strb r3, [r0, 0x12]
	strb r3, [r0, 0x1C]
	strb r3, [r0, 0x1D]
	adds r1, 0x20
	adds r7, 0x20
	subs r4, 0x1
	cmp r4, 0
	bne _0804D0C8
_0804D13E:
	mov r2, r10
	cmp r2, r5
	blt _0804D0A6
_0804D144:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804D084

	thumb_func_start sub_804D154
sub_804D154:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x114
	str r0, [sp, 0x100]
	mov r9, r1
	mov r8, r2
	adds r4, r3, 0
	movs r0, 0x3
	bl DungeonRandomCapped
	adds r3, r0, 0
	cmp r4, 0
	bge _0804D17E
	negs r4, r4
	b _0804D180
_0804D178:
	movs r0, 0x1
	strb r0, [r4, 0xA]
	b _0804D2B6
_0804D17E:
	adds r4, r3
_0804D180:
	movs r3, 0
	mov r0, r8
	mov r2, r9
	muls r2, r0
	cmp r3, r4
	bge _0804D19A
	movs r1, 0x1
_0804D18E:
	mov r5, sp
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, r4
	blt _0804D18E
_0804D19A:
	cmp r3, 0xFF
	bgt _0804D1AC
	movs r1, 0
_0804D1A0:
	mov r6, sp
	adds r0, r6, r3
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0xFF
	ble _0804D1A0
_0804D1AC:
	adds r5, r2, 0
	movs r6, 0x3F
_0804D1B0:
	adds r0, r5, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r5, 0
	bl DungeonRandomCapped
	mov r1, sp
	adds r2, r1, r4
	ldrb r3, [r2]
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	subs r6, 0x1
	cmp r6, 0
	bge _0804D1B0
	movs r3, 0
	ldr r0, _0804D24C
	str r3, [r0]
	movs r7, 0
	mov r12, r0
	cmp r7, r9
	bge _0804D262
_0804D1E0:
	movs r5, 0
	adds r4, r7, 0x1
	str r4, [sp, 0x104]
	cmp r5, r8
	bge _0804D25C
	lsls r2, r7, 4
	subs r2, r7
	lsls r2, 5
	ldr r6, [sp, 0x100]
	adds r0, r2, r6
	mov r1, r9
	movs r4, 0x1
	ands r1, r4
	str r1, [sp, 0x110]
	mov r1, r9
	subs r1, 0x1
	adds r0, 0x20
	mov r10, r0
	adds r0, r6, 0
	adds r0, 0x8
	adds r2, r0
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
_0804D210:
	ldrb r4, [r2]
	cmp r4, 0
	bne _0804D254
	mov r6, r12
	ldr r0, [r6]
	cmp r0, 0x1F
	ble _0804D220
	strb r4, [r2, 0x2]
_0804D220:
	mov r6, sp
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804D250
	movs r0, 0x1
	strb r0, [r2, 0x2]
	mov r6, r12
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
	ldr r0, [sp, 0x110]
	cmp r0, 0
	beq _0804D252
	cmp r7, r1
	bne _0804D252
	cmp r5, 0x1
	bne _0804D252
	mov r6, r10
	strb r4, [r6, 0xA]
	b _0804D252
	.align 2, 0
_0804D24C: .4byte gUnknown_202F1CC
_0804D250:
	strb r0, [r2, 0x2]
_0804D252:
	adds r3, 0x1
_0804D254:
	adds r2, 0x20
	adds r5, 0x1
	cmp r5, r8
	blt _0804D210
_0804D25C:
	ldr r7, [sp, 0x104]
	cmp r7, r9
	blt _0804D1E0
_0804D262:
	mov r1, r12
	ldr r0, [r1]
	cmp r0, 0x1
	bgt _0804D2BC
	movs r1, 0
	movs r2, 0
_0804D26E:
	movs r7, 0
	cmp r2, r9
	bge _0804D2AC
	movs r6, 0
_0804D276:
	movs r5, 0
	cmp r5, r8
	bge _0804D2A4
	lsls r0, r6, 5
	ldr r3, [sp, 0x100]
	adds r4, r0, r3
_0804D282:
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _0804D29C
	movs r0, 0x64
	str r1, [sp, 0x108]
	str r2, [sp, 0x10C]
	bl DungeonRandomCapped
	ldr r1, [sp, 0x108]
	ldr r2, [sp, 0x10C]
	cmp r0, 0x3B
	bgt _0804D29C
	b _0804D178
_0804D29C:
	adds r4, 0x20
	adds r5, 0x1
	cmp r5, r8
	blt _0804D282
_0804D2A4:
	adds r6, 0xF
	adds r7, 0x1
	cmp r7, r9
	blt _0804D276
_0804D2AC:
	cmp r2, 0
	bne _0804D2B6
	adds r1, 0x1
	cmp r1, 0xC7
	ble _0804D26E
_0804D2B6:
	ldr r1, _0804D2CC
	movs r0, 0
	strb r0, [r1]
_0804D2BC:
	add sp, 0x114
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D2CC: .4byte gUnknown_202F1AD
	thumb_func_end sub_804D154

	thumb_func_start sub_804D2D0
sub_804D2D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	movs r1, 0
	str r1, [sp, 0x14]
	cmp r1, r2
	blt _0804D2F2
	b _0804D520
_0804D2F2:
	movs r2, 0
	mov r10, r2
	ldr r3, [sp, 0x14]
	adds r3, 0x1
	str r3, [sp, 0x28]
	ldr r4, [sp, 0x4]
	cmp r10, r4
	blt _0804D304
	b _0804D514
_0804D304:
	ldr r5, [sp, 0x14]
	lsls r5, 5
	str r5, [sp, 0x1C]
_0804D30A:
	mov r1, r10
	lsls r0, r1, 2
	ldr r2, [sp, 0xC]
	adds r0, r2
	ldr r3, [r0]
	adds r4, r3, 0x2
	mov r9, r4
	ldr r5, [sp, 0x14]
	lsls r1, r5, 2
	ldr r2, [sp, 0x58]
	adds r1, r2
	ldr r2, [r1]
	adds r4, r2, 0x2
	str r4, [sp, 0x18]
	ldr r0, [r0, 0x4]
	subs r0, r3
	subs r4, r0, 0x4
	ldr r0, [r1, 0x4]
	subs r0, r2
	subs r0, 0x3
	mov r8, r0
	mov r5, r10
	lsls r1, r5, 4
	subs r0, r1, r5
	lsls r0, 5
	ldr r2, [sp]
	adds r0, r2
	ldr r3, [sp, 0x1C]
	adds r7, r3, r0
	ldrb r0, [r7, 0x8]
	str r1, [sp, 0x2C]
	adds r5, 0x1
	str r5, [sp, 0x24]
	cmp r0, 0
	beq _0804D352
	b _0804D508
_0804D352:
	ldrb r0, [r7, 0xA]
	cmp r0, 0
	bne _0804D35A
	b _0804D48C
_0804D35A:
	movs r0, 0x5
	adds r1, r4, 0
	bl DungeonRandomRange
	adds r6, r0, 0
	movs r0, 0x4
	mov r1, r8
	bl DungeonRandomRange
	adds r5, r0, 0
	movs r1, 0x1
	adds r0, r6, 0
	orrs r0, r1
	cmp r0, r4
	bge _0804D37A
	adds r6, r0, 0
_0804D37A:
	adds r0, r5, 0
	orrs r0, r1
	cmp r0, r8
	bge _0804D384
	adds r5, r0, 0
_0804D384:
	lsls r0, r5, 1
	adds r0, r5
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r6, r0
	ble _0804D394
	adds r6, r0, 0
_0804D394:
	lsls r0, r6, 1
	adds r0, r6
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r5, r0
	ble _0804D3A4
	adds r5, r0, 0
_0804D3A4:
	subs r0, r4, r6
	bl DungeonRandomCapped
	adds r4, r0, 0
	add r4, r9
	mov r1, r8
	subs r0, r1, r5
	bl DungeonRandomCapped
	ldr r2, [sp, 0x18]
	adds r0, r2
	mov r8, r0
	adds r3, r4, r6
	adds r6, r0, r5
	strh r4, [r7]
	strh r3, [r7, 0x4]
	mov r5, r8
	strh r5, [r7, 0x2]
	strh r6, [r7, 0x6]
	ldr r0, [sp, 0x10]
	adds r0, 0x1
	str r0, [sp, 0x20]
	cmp r4, r3
	bge _0804D412
_0804D3D4:
	mov r5, r8
	adds r7, r4, 0x1
	cmp r5, r6
	bge _0804D40C
	ldr r1, _0804D484
	mov r9, r1
_0804D3E0:
	adds r0, r4, 0
	adds r1, r5, 0
	str r3, [sp, 0x34]
	bl GetMapTile_2
	ldrh r1, [r0]
	mov r2, r9
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	mov r1, sp
	ldrb r1, [r1, 0x10]
	strb r1, [r0, 0x9]
	adds r5, 0x1
	ldr r3, [sp, 0x34]
	cmp r5, r6
	blt _0804D3E0
_0804D40C:
	adds r4, r7, 0
	cmp r4, r3
	blt _0804D3D4
_0804D412:
	movs r5, 0x1
	movs r0, 0x64
	bl DungeonRandomCapped
	movs r1, 0
	cmp r0, 0x4F
	bgt _0804D422
	movs r1, 0x1
_0804D422:
	adds r4, r1, 0
	ldr r0, _0804D488
	ldr r0, [r0]
	cmp r0, 0
	bne _0804D42E
	movs r4, 0
_0804D42E:
	movs r0, 0x4
	ldr r2, [sp, 0x5C]
	ands r0, r2
	cmp r0, 0
	bne _0804D43A
	movs r5, 0
_0804D43A:
	cmp r5, 0
	beq _0804D466
	cmp r4, 0
	beq _0804D44E
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, 0x31
	ble _0804D466
	movs r4, 0
_0804D44E:
	cmp r5, 0
	beq _0804D466
	ldr r3, [sp, 0x2C]
	mov r5, r10
	subs r0, r3, r5
	lsls r0, 5
	ldr r1, [sp]
	adds r0, r1
	ldr r2, [sp, 0x1C]
	adds r0, r2, r0
	movs r1, 0x1
	strb r1, [r0, 0x1C]
_0804D466:
	cmp r4, 0
	beq _0804D47E
	ldr r3, [sp, 0x2C]
	mov r4, r10
	subs r0, r3, r4
	lsls r0, 5
	ldr r5, [sp]
	adds r0, r5
	ldr r1, [sp, 0x1C]
	adds r0, r1, r0
	movs r1, 0x1
	strb r1, [r0, 0x1D]
_0804D47E:
	ldr r2, [sp, 0x20]
	str r2, [sp, 0x10]
	b _0804D508
	.align 2, 0
_0804D484: .4byte 0x0000fffc
_0804D488: .4byte gUnknown_202F1C8
_0804D48C:
	movs r1, 0x2
	movs r3, 0x4
	movs r6, 0x2
	movs r2, 0x4
	mov r5, r10
	cmp r5, 0
	bne _0804D49C
	movs r1, 0x1
_0804D49C:
	ldr r0, [sp, 0x14]
	cmp r0, 0
	bne _0804D4A4
	movs r6, 0x1
_0804D4A4:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	cmp r10, r0
	bne _0804D4AE
	movs r3, 0x2
_0804D4AE:
	ldr r0, [sp, 0x8]
	subs r0, 0x1
	ldr r5, [sp, 0x14]
	cmp r5, r0
	bne _0804D4BA
	movs r2, 0x2
_0804D4BA:
	mov r5, r9
	adds r0, r5, r1
	adds r1, r5, r4
	subs r1, r3
	str r2, [sp, 0x30]
	bl DungeonRandomRange
	adds r5, r0, 0
	ldr r1, [sp, 0x18]
	adds r0, r1, r6
	add r1, r8
	ldr r2, [sp, 0x30]
	subs r1, r2
	bl DungeonRandomRange
	adds r4, r0, 0
	strh r5, [r7]
	adds r0, r5, 0x1
	strh r0, [r7, 0x4]
	strh r4, [r7, 0x2]
	adds r0, r4, 0x1
	strh r0, [r7, 0x6]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, _0804D530
	adds r2, r3, 0
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0xFE
	strb r1, [r0, 0x9]
_0804D508:
	ldr r4, [sp, 0x24]
	mov r10, r4
	ldr r5, [sp, 0x4]
	cmp r10, r5
	bge _0804D514
	b _0804D30A
_0804D514:
	ldr r0, [sp, 0x28]
	str r0, [sp, 0x14]
	ldr r1, [sp, 0x8]
	cmp r0, r1
	bge _0804D520
	b _0804D2F2
_0804D520:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D530: .4byte 0x0000fffc
	thumb_func_end sub_804D2D0

	thumb_func_start sub_804D534
sub_804D534:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r3, r0, 0
	adds r7, r1, 0
	mov r9, r2
	movs r1, 0
	cmp r1, r9
	bge _0804D5A0
_0804D54A:
	adds r0, r1, 0x1
	mov r8, r0
	cmp r7, 0
	ble _0804D59A
	lsls r1, 5
	adds r0, r1, 0
	adds r0, 0x8
	adds r4, r3, r0
	adds r5, r3, r1
	adds r6, r7, 0
_0804D55E:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0804D58C
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _0804D58C
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _0804D58C
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _0804D58C
	ldrb r0, [r4, 0x14]
	cmp r0, 0
	bne _0804D58C
	ldrb r0, [r4, 0x15]
	cmp r0, 0
	beq _0804D58C
	adds r0, r5, 0
	str r3, [sp]
	bl sub_804F694
	ldr r3, [sp]
_0804D58C:
	movs r0, 0xF0
	lsls r0, 1
	adds r4, r0
	adds r5, r0
	subs r6, 0x1
	cmp r6, 0
	bne _0804D55E
_0804D59A:
	mov r1, r8
	cmp r1, r9
	blt _0804D54A
_0804D5A0:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804D534

	thumb_func_start sub_804D5B0
sub_804D5B0:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	mov r9, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	adds r0, r4, 0
	bl DungeonRandomCapped
	mov r8, r0
	adds r0, r5, 0
	bl DungeonRandomCapped
	str r0, [sp]
	str r6, [sp, 0x4]
	mov r0, r9
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r8
	bl sub_804D5F0
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_804D5B0

	thumb_func_start sub_804D5F0
sub_804D5F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	adds r7, r3, 0
	ldr r6, [sp, 0x40]
	ldr r0, [sp, 0x44]
	ldrb r0, [r0, 0x5]
	str r0, [sp, 0xC]
	movs r0, 0x4
	bl DungeonRandomCapped
	adds r5, r0, 0
	movs r1, 0
	mov r10, r1
	ldr r2, [sp, 0xC]
	cmp r10, r2
	blt _0804D620
	b _0804D726
_0804D620:
	lsls r4, r6, 5
	mov r9, r4
	lsls r0, r7, 4
	subs r0, r7
	lsls r0, 5
	ldr r1, [sp]
	adds r0, r1
	mov r8, r0
_0804D630:
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x4
	bl DungeonRandomCapped
	cmp r4, 0x3
	bgt _0804D644
	adds r5, r0, 0
_0804D644:
	mov r4, r10
	adds r4, 0x1
_0804D648:
	movs r1, 0
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0x1
	beq _0804D670
	cmp r0, 0x1
	bgt _0804D65C
	cmp r0, 0
	beq _0804D666
	b _0804D686
_0804D65C:
	cmp r0, 0x2
	beq _0804D676
	cmp r0, 0x3
	beq _0804D67C
	b _0804D686
_0804D666:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	cmp r7, r0
	blt _0804D68A
	b _0804D684
_0804D670:
	cmp r6, 0
	bgt _0804D68A
	b _0804D684
_0804D676:
	cmp r7, 0
	bgt _0804D68A
	b _0804D684
_0804D67C:
	ldr r0, [sp, 0x8]
	subs r0, 0x1
	cmp r6, r0
	blt _0804D68A
_0804D684:
	adds r5, 0x1
_0804D686:
	cmp r1, 0
	beq _0804D648
_0804D68A:
	movs r1, 0x3
	ands r1, r5
	cmp r1, 0x1
	beq _0804D6C6
	cmp r1, 0x1
	bgt _0804D69C
	cmp r1, 0
	beq _0804D6A6
	b _0804D71E
_0804D69C:
	cmp r1, 0x2
	beq _0804D6E2
	cmp r1, 0x3
	beq _0804D704
	b _0804D71E
_0804D6A6:
	mov r1, r9
	add r1, r8
	movs r0, 0xF0
	lsls r0, 1
	adds r2, r1, r0
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D71E
	movs r0, 0x1
	strb r0, [r1, 0x16]
	strb r0, [r2, 0x15]
	movs r1, 0xF0
	lsls r1, 1
	add r8, r1
	adds r7, 0x1
	b _0804D71E
_0804D6C6:
	mov r2, r9
	add r2, r8
	adds r3, r2, 0
	subs r3, 0x20
	ldrb r0, [r3, 0x8]
	cmp r0, 0
	bne _0804D71E
	strb r1, [r2, 0x13]
	strb r1, [r3, 0x14]
	movs r2, 0x20
	negs r2, r2
	add r9, r2
	subs r6, 0x1
	b _0804D71E
_0804D6E2:
	mov r1, r9
	add r1, r8
	ldr r0, _0804D700
	adds r2, r1, r0
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D71E
	movs r0, 0x1
	strb r0, [r1, 0x15]
	strb r0, [r2, 0x16]
	ldr r1, _0804D700
	add r8, r1
	subs r7, 0x1
	b _0804D71E
	.align 2, 0
_0804D700: .4byte 0xfffffe20
_0804D704:
	mov r1, r9
	add r1, r8
	adds r2, r1, 0
	adds r2, 0x20
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D71E
	movs r0, 0x1
	strb r0, [r1, 0x14]
	strb r0, [r2, 0x13]
	movs r1, 0x20
	add r9, r1
	adds r6, 0x1
_0804D71E:
	mov r10, r4
	ldr r2, [sp, 0xC]
	cmp r10, r2
	blt _0804D630
_0804D726:
	ldr r4, [sp, 0x44]
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	beq _0804D730
	b _0804D8B8
_0804D730:
	movs r0, 0
	mov r9, r0
	movs r7, 0
	ldr r1, [sp, 0x4]
	cmp r9, r1
	blt _0804D73E
	b _0804D8B0
_0804D73E:
	movs r2, 0x1
	mov r8, r2
_0804D742:
	movs r6, 0
	adds r4, r7, 0x1
	str r4, [sp, 0x14]
	ldr r0, [sp, 0x8]
	cmp r6, r0
	blt _0804D750
	b _0804D8A6
_0804D750:
	lsls r1, r7, 4
	str r1, [sp, 0x10]
	subs r0, r1, r7
	lsls r0, 5
	ldr r2, [sp]
	adds r3, r0, r2
_0804D75C:
	lsls r0, r6, 5
	adds r2, r0, r3
	ldrb r1, [r2, 0x8]
	adds r4, r0, 0
	adds r0, r6, 0x1
	str r0, [sp, 0x18]
	cmp r1, 0
	beq _0804D76E
	b _0804D89C
_0804D76E:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804D776
	b _0804D89C
_0804D776:
	ldrb r0, [r2, 0x13]
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	ldrb r0, [r2, 0x14]
	cmp r0, 0
	beq _0804D786
	adds r1, 0x1
_0804D786:
	ldrb r0, [r2, 0x15]
	cmp r0, 0
	beq _0804D78E
	adds r1, 0x1
_0804D78E:
	ldrb r0, [r2, 0x16]
	cmp r0, 0
	beq _0804D796
	adds r1, 0x1
_0804D796:
	cmp r1, 0x1
	beq _0804D79C
	b _0804D89C
_0804D79C:
	movs r0, 0x4
	str r3, [sp, 0x1C]
	bl DungeonRandomCapped
	adds r5, r0, 0
	movs r2, 0
	mov r10, r2
	ldr r1, [sp, 0x10]
	subs r0, r1, r7
	lsls r0, 5
	ldr r1, [sp]
	adds r0, r1
	adds r1, r4, r0
	ldr r3, [sp, 0x1C]
_0804D7B8:
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0x1
	beq _0804D7E0
	cmp r0, 0x1
	bgt _0804D7CA
	cmp r0, 0
	beq _0804D7D4
	b _0804D800
_0804D7CA:
	cmp r0, 0x2
	beq _0804D7E8
	cmp r0, 0x3
	beq _0804D7F0
	b _0804D800
_0804D7D4:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	cmp r7, r0
	bge _0804D7FE
	ldrb r0, [r1, 0x16]
	b _0804D7FA
_0804D7E0:
	cmp r6, 0
	ble _0804D7FE
	ldrb r0, [r1, 0x13]
	b _0804D7FA
_0804D7E8:
	cmp r7, 0
	ble _0804D7FE
	ldrb r0, [r1, 0x15]
	b _0804D7FA
_0804D7F0:
	ldr r0, [sp, 0x8]
	subs r0, 0x1
	cmp r6, r0
	bge _0804D7FE
	ldrb r0, [r1, 0x14]
_0804D7FA:
	cmp r0, 0
	beq _0804D80E
_0804D7FE:
	adds r5, 0x1
_0804D800:
	mov r0, r10
	cmp r0, 0
	bne _0804D80E
	adds r2, 0x1
	cmp r2, 0x7
	ble _0804D7B8
	b _0804D89C
_0804D80E:
	movs r2, 0x3
	ands r2, r5
	cmp r2, 0x1
	beq _0804D844
	cmp r2, 0x1
	bgt _0804D820
	cmp r2, 0
	beq _0804D82A
	b _0804D89C
_0804D820:
	cmp r2, 0x2
	beq _0804D85C
	cmp r2, 0x3
	beq _0804D880
	b _0804D89C
_0804D82A:
	adds r1, r4, r3
	movs r4, 0xF0
	lsls r4, 1
	adds r2, r1, r4
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804D89C
	mov r0, r8
	strb r0, [r1, 0x16]
	strb r0, [r2, 0x15]
	movs r1, 0x1
	mov r9, r1
	b _0804D89C
_0804D844:
	adds r1, r4, r3
	movs r4, 0xF0
	lsls r4, 1
	adds r0, r1, r4
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0804D89C
	strb r2, [r1, 0x13]
	adds r0, r1, 0
	subs r0, 0x20
	strb r2, [r0, 0x14]
	b _0804D898
_0804D85C:
	adds r1, r4, r3
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0804D89C
	mov r4, r8
	strb r4, [r1, 0x15]
	ldr r2, _0804D87C
	adds r0, r1, r2
	strb r4, [r0, 0x16]
	movs r4, 0x1
	mov r9, r4
	b _0804D89C
	.align 2, 0
_0804D87C: .4byte 0xfffffe20
_0804D880:
	adds r1, r4, r3
	movs r2, 0xF0
	lsls r2, 1
	adds r0, r1, r2
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _0804D89C
	mov r4, r8
	strb r4, [r1, 0x14]
	adds r0, r1, 0
	adds r0, 0x20
	strb r4, [r0, 0x13]
_0804D898:
	movs r0, 0x1
	mov r9, r0
_0804D89C:
	ldr r6, [sp, 0x18]
	ldr r1, [sp, 0x8]
	cmp r6, r1
	bge _0804D8A6
	b _0804D75C
_0804D8A6:
	ldr r7, [sp, 0x14]
	ldr r2, [sp, 0x4]
	cmp r7, r2
	bge _0804D8B0
	b _0804D742
_0804D8B0:
	mov r4, r9
	cmp r4, 0
	beq _0804D8B8
	b _0804D730
_0804D8B8:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804D5F0

	thumb_func_start sub_804D8C8
sub_804D8C8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	str r2, [sp, 0x14]
	str r3, [sp, 0x18]
	ldr r0, [sp, 0x7C]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x1C]
	movs r0, 0
	str r0, [sp, 0x20]
	cmp r0, r1
	bge _0804D968
_0804D8EC:
	movs r1, 0
	mov r10, r1
	ldr r2, [sp, 0x20]
	adds r2, 0x1
	str r2, [sp, 0x38]
	ldr r3, [sp, 0x14]
	cmp r10, r3
	bge _0804D95E
	ldr r4, [sp, 0x20]
	lsls r1, r4, 4
	subs r1, r4
	movs r3, 0
	lsls r1, 5
	ldr r0, [sp, 0xC]
	adds r0, 0x8
	adds r1, r0
_0804D90C:
	ldrb r2, [r1]
	cmp r2, 0
	beq _0804D91C
	strb r3, [r1, 0xF]
	strb r3, [r1, 0x10]
	strb r3, [r1, 0x11]
	strb r3, [r1, 0x12]
	b _0804D952
_0804D91C:
	ldr r5, [sp, 0x20]
	cmp r5, 0
	bgt _0804D924
	strb r2, [r1, 0xD]
_0804D924:
	mov r6, r10
	cmp r6, 0
	bgt _0804D92C
	strb r2, [r1, 0xB]
_0804D92C:
	ldr r0, [sp, 0x10]
	subs r0, 0x1
	ldr r7, [sp, 0x20]
	cmp r7, r0
	blt _0804D938
	strb r2, [r1, 0xE]
_0804D938:
	ldr r0, [sp, 0x14]
	subs r0, 0x1
	cmp r10, r0
	blt _0804D942
	strb r2, [r1, 0xC]
_0804D942:
	ldrb r0, [r1, 0xB]
	strb r0, [r1, 0xF]
	ldrb r0, [r1, 0xC]
	strb r0, [r1, 0x10]
	ldrb r0, [r1, 0xD]
	strb r0, [r1, 0x11]
	ldrb r0, [r1, 0xE]
	strb r0, [r1, 0x12]
_0804D952:
	adds r1, 0x20
	movs r0, 0x1
	add r10, r0
	ldr r2, [sp, 0x14]
	cmp r10, r2
	blt _0804D90C
_0804D95E:
	ldr r3, [sp, 0x38]
	str r3, [sp, 0x20]
	ldr r4, [sp, 0x10]
	cmp r3, r4
	blt _0804D8EC
_0804D968:
	movs r5, 0
	str r5, [sp, 0x20]
	ldr r6, [sp, 0x10]
	cmp r5, r6
	blt _0804D974
	b _0804DBC6
_0804D974:
	movs r7, 0
	mov r10, r7
	ldr r0, [sp, 0x20]
	adds r0, 0x1
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x14]
	cmp r10, r1
	blt _0804D986
	b _0804DBBA
_0804D986:
	ldr r2, [sp, 0x20]
	lsls r2, 4
	str r2, [sp, 0x40]
	ldr r3, [sp, 0x20]
	subs r1, r2, r3
	lsls r1, 5
	movs r4, 0
	str r4, [sp, 0x48]
	ldr r5, [sp, 0xC]
	movs r6, 0xF0
	lsls r6, 1
	adds r0, r5, r6
	adds r0, r1
	mov r8, r0
	adds r5, r1, r5
	ldr r7, [sp, 0xC]
	ldr r2, _0804DA0C
	adds r0, r7, r2
	adds r7, r1, r0
	ldr r3, [sp, 0x78]
	str r3, [sp, 0x4C]
	ldr r0, [sp, 0xC]
	adds r0, 0x20
	adds r0, r1, r0
	str r0, [sp, 0x50]
	ldr r0, [sp, 0xC]
	subs r0, 0x20
	adds r6, r1, r0
	ldr r4, [sp, 0x20]
	lsls r0, r4, 2
	ldr r1, [sp, 0x18]
	adds r0, r1
	str r0, [sp, 0x24]
_0804D9C8:
	ldr r2, [sp, 0x20]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 5
	ldr r3, [sp, 0xC]
	adds r0, r3
	ldr r1, [sp, 0x48]
	adds r4, r1, r0
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0804D9E0
	b _0804DB92
_0804D9E0:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	beq _0804DA10
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r0, 0x1
	movs r3, 0x4
	ldrsh r1, [r4, r3]
	subs r1, 0x1
	bl DungeonRandomRange
	mov r9, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r4, r0, 0
	b _0804DA1A
	.align 2, 0
_0804DA0C: .4byte 0xfffffe20
_0804DA10:
	movs r0, 0
	ldrsh r3, [r4, r0]
	mov r9, r3
	movs r1, 0x2
	ldrsh r4, [r4, r1]
_0804DA1A:
	ldrb r0, [r5, 0x17]
	cmp r0, 0
	beq _0804DA74
	ldrb r0, [r6, 0x8]
	cmp r0, 0
	bne _0804DA68
	ldrb r0, [r6, 0xA]
	cmp r0, 0
	beq _0804DA40
	movs r2, 0
	ldrsh r0, [r6, r2]
	adds r0, 0x1
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r2, r0, 0
	b _0804DA44
_0804DA40:
	movs r0, 0
	ldrsh r2, [r6, r0]
_0804DA44:
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	movs r0, 0x6
	ldrsh r3, [r6, r0]
	subs r3, 0x1
	mov r12, r3
	movs r3, 0x1
	str r3, [sp]
	ldr r3, [sp, 0x24]
	ldr r0, [r3]
	str r0, [sp, 0x4]
	ldr r3, [sp, 0x4C]
	ldr r0, [r3]
	str r0, [sp, 0x8]
	mov r0, r9
	mov r3, r12
	bl sub_804E328
_0804DA68:
	movs r0, 0
	strb r0, [r5, 0x17]
	strb r0, [r6, 0x18]
	movs r1, 0x1
	strb r1, [r5, 0xB]
	strb r1, [r6, 0xB]
_0804DA74:
	ldrb r0, [r5, 0x18]
	cmp r0, 0
	beq _0804DAD4
	ldr r2, [sp, 0x50]
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804DAC6
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804DA9C
	movs r3, 0x20
	ldrsh r0, [r5, r3]
	adds r0, 0x1
	movs r2, 0x24
	ldrsh r1, [r5, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r2, r0, 0
	b _0804DAA0
_0804DA9C:
	movs r3, 0x20
	ldrsh r2, [r5, r3]
_0804DAA0:
	movs r0, 0x6
	ldrsh r1, [r5, r0]
	subs r1, 0x1
	movs r0, 0x22
	ldrsh r3, [r5, r0]
	mov r12, r3
	movs r3, 0x1
	str r3, [sp]
	ldr r3, [sp, 0x24]
	ldr r0, [r3]
	str r0, [sp, 0x4]
	ldr r3, [sp, 0x4C]
	ldr r0, [r3, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x8]
	mov r0, r9
	mov r3, r12
	bl sub_804E328
_0804DAC6:
	movs r0, 0
	strb r0, [r5, 0x18]
	ldr r1, [sp, 0x50]
	strb r0, [r1, 0x17]
	movs r2, 0x1
	strb r2, [r5, 0xB]
	strb r2, [r1, 0xB]
_0804DAD4:
	ldrb r0, [r5, 0x19]
	cmp r0, 0
	beq _0804DB2E
	ldrb r0, [r7, 0x8]
	cmp r0, 0
	bne _0804DB22
	ldrb r0, [r7, 0xA]
	cmp r0, 0
	beq _0804DAFA
	movs r3, 0x2
	ldrsh r0, [r7, r3]
	adds r0, 0x1
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r3, r0, 0
	b _0804DAFE
_0804DAFA:
	movs r0, 0x2
	ldrsh r3, [r7, r0]
_0804DAFE:
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0
	ldrsh r2, [r7, r1]
	subs r2, 0x1
	mov r9, r2
	movs r2, 0
	str r2, [sp]
	ldr r2, [sp, 0x24]
	ldr r1, [r2]
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x4C]
	ldr r1, [r2]
	str r1, [sp, 0x8]
	adds r1, r4, 0
	mov r2, r9
	bl sub_804E328
_0804DB22:
	movs r3, 0
	strb r3, [r5, 0x19]
	strb r3, [r7, 0x1A]
	movs r0, 0x1
	strb r0, [r5, 0xB]
	strb r0, [r7, 0xB]
_0804DB2E:
	ldrb r0, [r5, 0x1A]
	cmp r0, 0
	beq _0804DB92
	mov r1, r8
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _0804DB84
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	beq _0804DB56
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, 0x1
	movs r3, 0x6
	ldrsh r1, [r1, r3]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r3, r0, 0
	b _0804DB5C
_0804DB56:
	mov r0, r8
	movs r1, 0x2
	ldrsh r3, [r0, r1]
_0804DB5C:
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r0, 0x1
	mov r1, r8
	movs r2, 0
	ldrsh r1, [r1, r2]
	mov r9, r1
	movs r1, 0
	str r1, [sp]
	ldr r2, [sp, 0x24]
	ldr r1, [r2, 0x4]
	subs r1, 0x1
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x4C]
	ldr r1, [r2]
	str r1, [sp, 0x8]
	adds r1, r4, 0
	mov r2, r9
	bl sub_804E328
_0804DB84:
	movs r3, 0
	strb r3, [r5, 0x1A]
	mov r4, r8
	strb r3, [r4, 0x19]
	movs r0, 0x1
	strb r0, [r5, 0xB]
	strb r0, [r4, 0xB]
_0804DB92:
	ldr r1, [sp, 0x48]
	adds r1, 0x20
	str r1, [sp, 0x48]
	movs r2, 0x20
	add r8, r2
	adds r5, 0x20
	adds r7, 0x20
	ldr r3, [sp, 0x4C]
	adds r3, 0x4
	str r3, [sp, 0x4C]
	ldr r4, [sp, 0x50]
	adds r4, 0x20
	str r4, [sp, 0x50]
	adds r6, 0x20
	movs r0, 0x1
	add r10, r0
	ldr r1, [sp, 0x14]
	cmp r10, r1
	bge _0804DBBA
	b _0804D9C8
_0804DBBA:
	ldr r2, [sp, 0x38]
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x10]
	cmp r2, r3
	bge _0804DBC6
	b _0804D974
_0804DBC6:
	ldr r4, [sp, 0x1C]
	cmp r4, 0
	beq _0804DBCE
	b _0804E026
_0804DBCE:
	movs r5, 0
	str r5, [sp, 0x20]
	ldr r6, [sp, 0x10]
	cmp r5, r6
	blt _0804DBDA
	b _0804E026
_0804DBDA:
	movs r7, 0
	mov r10, r7
	ldr r0, [sp, 0x20]
	adds r0, 0x1
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x14]
	cmp r10, r1
	blt _0804DBEC
	b _0804E018
_0804DBEC:
	movs r0, 0x64
	bl DungeonRandomCapped
	mov r2, r10
	adds r2, 0x1
	str r2, [sp, 0x3C]
	cmp r0, 0x4
	ble _0804DBFE
	b _0804E00C
_0804DBFE:
	mov r3, r10
	lsls r1, r3, 5
	ldr r4, [sp, 0x20]
	lsls r2, r4, 4
	subs r0, r2, r4
	lsls r0, 5
	ldr r5, [sp, 0xC]
	adds r0, r5
	adds r4, r1, r0
	ldrb r0, [r4, 0x8]
	str r1, [sp, 0x44]
	str r2, [sp, 0x40]
	cmp r0, 0
	beq _0804DC1C
	b _0804E00C
_0804DC1C:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _0804DC24
	b _0804E00C
_0804DC24:
	ldrb r0, [r4, 0x12]
	cmp r0, 0
	beq _0804DC2C
	b _0804E00C
_0804DC2C:
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0804DC34
	b _0804E00C
_0804DC34:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _0804DC3C
	b _0804E00C
_0804DC3C:
	movs r0, 0x4
	bl DungeonRandomCapped
	cmp r0, 0x1
	bne _0804DC48
	b _0804DD50
_0804DC48:
	cmp r0, 0x1
	bgt _0804DC52
	cmp r0, 0
	beq _0804DC60
	b _0804E00C
_0804DC52:
	cmp r0, 0x2
	bne _0804DC58
	b _0804DE3C
_0804DC58:
	cmp r0, 0x3
	bne _0804DC5E
	b _0804DF30
_0804DC5E:
	b _0804E00C
_0804DC60:
	ldr r6, [sp, 0x20]
	cmp r6, 0
	bgt _0804DC68
	b _0804E00C
_0804DC68:
	ldr r7, _0804DD48
	adds r2, r4, r7
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _0804DC74
	b _0804E00C
_0804DC74:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0804DC7C
	b _0804E00C
_0804DC7C:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	bne _0804DC84
	b _0804E00C
_0804DC84:
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	beq _0804DC8C
	b _0804E00C
_0804DC8C:
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0804DC94
	b _0804E00C
_0804DC94:
	movs r1, 0
	ldrsh r0, [r2, r1]
	str r0, [sp, 0x28]
	ldrh r3, [r4, 0x2]
	movs r5, 0x2
	ldrsh r1, [r4, r5]
	ldrh r5, [r2, 0x2]
	movs r6, 0x2
	ldrsh r0, [r2, r6]
	cmp r1, r0
	ble _0804DCAC
	adds r3, r5, 0
_0804DCAC:
	lsls r0, r3, 16
	asrs r0, 16
	mov r9, r0
	movs r0, 0x4
	ldrsh r7, [r4, r0]
	mov r10, r7
	ldrh r3, [r4, 0x6]
	movs r5, 0x6
	ldrsh r1, [r4, r5]
	ldrh r5, [r2, 0x6]
	movs r6, 0x6
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bge _0804DCCA
	adds r3, r5, 0
_0804DCCA:
	lsls r0, r3, 16
	asrs r7, r0, 16
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	mov r8, r0
	ldr r5, [sp, 0x28]
	cmp r5, r10
	bge _0804DD16
_0804DCE4:
	mov r4, r9
	adds r6, r5, 0x1
	cmp r9, r7
	bge _0804DD10
	ldr r0, _0804DD4C
	adds r3, r0, 0
_0804DCF0:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, [sp, 0x54]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r1, r8
	strb r1, [r0, 0x9]
	adds r4, 0x1
	cmp r4, r7
	blt _0804DCF0
_0804DD10:
	adds r5, r6, 0
	cmp r5, r10
	blt _0804DCE4
_0804DD16:
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x20]
	subs r0, r2, r3
	lsls r0, 5
	ldr r4, [sp, 0xC]
	adds r0, r4
	ldr r5, [sp, 0x44]
	adds r0, r5, r0
	ldr r6, _0804DD48
	adds r3, r0, r6
	mov r1, sp
	ldrh r1, [r1, 0x28]
	strh r1, [r3]
	mov r2, r10
	strh r2, [r3, 0x4]
	mov r4, r9
	strh r4, [r3, 0x2]
	strh r7, [r3, 0x6]
	movs r5, 0x1
	strb r5, [r0, 0x12]
	strb r5, [r3, 0x12]
	movs r6, 0
	strb r6, [r0, 0xB]
	strb r5, [r0, 0x11]
	b _0804E00C
	.align 2, 0
_0804DD48: .4byte 0xfffffe20
_0804DD4C: .4byte 0x0000fffc
_0804DD50:
	mov r7, r10
	cmp r7, 0
	bgt _0804DD58
	b _0804E00C
_0804DD58:
	adds r2, r4, 0
	subs r2, 0x20
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _0804DD64
	b _0804E00C
_0804DD64:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0804DD6C
	b _0804E00C
_0804DD6C:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	bne _0804DD74
	b _0804E00C
_0804DD74:
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	beq _0804DD7C
	b _0804E00C
_0804DD7C:
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0804DD84
	b _0804E00C
_0804DD84:
	ldrh r3, [r4]
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldrh r5, [r2]
	movs r6, 0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	ble _0804DD96
	adds r3, r5, 0
_0804DD96:
	lsls r0, r3, 16
	asrs r0, 16
	str r0, [sp, 0x2C]
	movs r0, 0x2
	ldrsh r7, [r2, r0]
	mov r10, r7
	ldrh r3, [r4, 0x4]
	movs r5, 0x4
	ldrsh r1, [r4, r5]
	ldrh r5, [r2, 0x4]
	movs r6, 0x4
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bge _0804DDB4
	adds r3, r5, 0
_0804DDB4:
	lsls r0, r3, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x6
	ldrsh r7, [r4, r0]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	mov r9, r0
	ldr r5, [sp, 0x2C]
	cmp r5, r8
	bge _0804DE06
_0804DDD4:
	mov r4, r10
	adds r6, r5, 0x1
	cmp r10, r7
	bge _0804DE00
	ldr r0, _0804DE38
	adds r3, r0, 0
_0804DDE0:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, [sp, 0x54]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r1, r9
	strb r1, [r0, 0x9]
	adds r4, 0x1
	cmp r4, r7
	blt _0804DDE0
_0804DE00:
	adds r5, r6, 0
	cmp r5, r8
	blt _0804DDD4
_0804DE06:
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x20]
	subs r0, r2, r3
	lsls r0, 5
	ldr r4, [sp, 0xC]
	adds r0, r4
	ldr r5, [sp, 0x44]
	adds r0, r5, r0
	adds r3, r0, 0
	subs r3, 0x20
	mov r6, sp
	ldrh r6, [r6, 0x2C]
	strh r6, [r3]
	mov r1, r8
	strh r1, [r3, 0x4]
	mov r2, r10
	strh r2, [r3, 0x2]
	strh r7, [r3, 0x6]
	movs r4, 0x1
	strb r4, [r0, 0x12]
	strb r4, [r3, 0x12]
	movs r5, 0
	strb r5, [r0, 0xB]
	strb r4, [r0, 0x11]
	b _0804E00C
	.align 2, 0
_0804DE38: .4byte 0x0000fffc
_0804DE3C:
	ldr r0, [sp, 0x10]
	subs r0, 0x2
	ldr r6, [sp, 0x20]
	cmp r6, r0
	ble _0804DE48
	b _0804E00C
_0804DE48:
	movs r7, 0xF0
	lsls r7, 1
	adds r2, r4, r7
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	bne _0804DE56
	b _0804E00C
_0804DE56:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0804DE5E
	b _0804E00C
_0804DE5E:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	bne _0804DE66
	b _0804E00C
_0804DE66:
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	beq _0804DE6E
	b _0804E00C
_0804DE6E:
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	beq _0804DE76
	b _0804E00C
_0804DE76:
	movs r1, 0
	ldrsh r0, [r4, r1]
	str r0, [sp, 0x30]
	ldrh r3, [r2, 0x2]
	movs r5, 0x2
	ldrsh r1, [r2, r5]
	ldrh r5, [r4, 0x2]
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	cmp r1, r0
	ble _0804DE8E
	adds r3, r5, 0
_0804DE8E:
	lsls r0, r3, 16
	asrs r0, 16
	mov r9, r0
	movs r0, 0x4
	ldrsh r7, [r2, r0]
	mov r10, r7
	ldrh r3, [r2, 0x6]
	movs r5, 0x6
	ldrsh r1, [r2, r5]
	ldrh r2, [r4, 0x6]
	movs r6, 0x6
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bge _0804DEAC
	adds r3, r2, 0
_0804DEAC:
	lsls r0, r3, 16
	asrs r7, r0, 16
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, [sp, 0x30]
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	mov r8, r0
	ldr r5, [sp, 0x30]
	cmp r5, r10
	bge _0804DEF6
_0804DEC4:
	mov r4, r9
	adds r6, r5, 0x1
	cmp r9, r7
	bge _0804DEF0
	ldr r1, _0804DF2C
	adds r3, r1, 0
_0804DED0:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, [sp, 0x54]
	ands r1, r3
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r2, r8
	strb r2, [r0, 0x9]
	adds r4, 0x1
	cmp r4, r7
	blt _0804DED0
_0804DEF0:
	adds r5, r6, 0
	cmp r5, r10
	blt _0804DEC4
_0804DEF6:
	ldr r3, [sp, 0x40]
	ldr r4, [sp, 0x20]
	subs r0, r3, r4
	lsls r0, 5
	ldr r5, [sp, 0xC]
	adds r0, r5
	ldr r6, [sp, 0x44]
	adds r0, r6, r0
	mov r1, sp
	ldrh r1, [r1, 0x30]
	strh r1, [r0]
	mov r2, r10
	strh r2, [r0, 0x4]
	mov r3, r9
	strh r3, [r0, 0x2]
	strh r7, [r0, 0x6]
	movs r4, 0xF0
	lsls r4, 1
	adds r1, r0, r4
	movs r5, 0x1
	strb r5, [r1, 0x12]
	strb r5, [r0, 0x12]
	movs r6, 0
	strb r6, [r1, 0xB]
	strb r5, [r1, 0x11]
	b _0804E00C
	.align 2, 0
_0804DF2C: .4byte 0x0000fffc
_0804DF30:
	ldr r0, [sp, 0x14]
	subs r0, 0x2
	cmp r10, r0
	bgt _0804E00C
	adds r3, r4, 0
	adds r3, 0x20
	ldrb r0, [r3, 0xB]
	cmp r0, 0
	beq _0804E00C
	ldrb r0, [r3, 0x8]
	cmp r0, 0
	bne _0804E00C
	ldrb r0, [r3, 0xA]
	cmp r0, 0
	beq _0804E00C
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	bne _0804E00C
	ldrb r0, [r3, 0x12]
	cmp r0, 0
	bne _0804E00C
	ldrh r2, [r4, 0x20]
	movs r7, 0x20
	ldrsh r1, [r4, r7]
	ldrh r5, [r4]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r1, r0
	ble _0804DF6C
	adds r2, r5, 0
_0804DF6C:
	lsls r0, r2, 16
	asrs r0, 16
	str r0, [sp, 0x34]
	movs r7, 0x2
	ldrsh r6, [r4, r7]
	ldrh r2, [r3, 0x4]
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	ldrh r5, [r4, 0x4]
	movs r7, 0x4
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bge _0804DF88
	adds r2, r5, 0
_0804DF88:
	lsls r0, r2, 16
	asrs r0, 16
	mov r8, r0
	movs r0, 0x6
	ldrsh r3, [r3, r0]
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r1, r6, 0
	str r3, [sp, 0x54]
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	mov r10, r0
	ldr r5, [sp, 0x34]
	ldr r3, [sp, 0x54]
	cmp r5, r8
	bge _0804DFDE
_0804DFAA:
	adds r4, r6, 0
	adds r7, r5, 0x1
	cmp r6, r3
	bge _0804DFD8
	ldr r2, _0804E038
	mov r9, r2
_0804DFB6:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x54]
	bl GetMapTile_2
	ldrh r1, [r0]
	mov r2, r9
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	mov r1, r10
	strb r1, [r0, 0x9]
	adds r4, 0x1
	ldr r3, [sp, 0x54]
	cmp r4, r3
	blt _0804DFB6
_0804DFD8:
	adds r5, r7, 0
	cmp r5, r8
	blt _0804DFAA
_0804DFDE:
	ldr r2, [sp, 0x40]
	ldr r4, [sp, 0x20]
	subs r0, r2, r4
	lsls r0, 5
	ldr r5, [sp, 0xC]
	adds r0, r5
	ldr r7, [sp, 0x44]
	adds r0, r7, r0
	mov r1, sp
	ldrh r1, [r1, 0x34]
	strh r1, [r0]
	mov r2, r8
	strh r2, [r0, 0x4]
	strh r6, [r0, 0x2]
	strh r3, [r0, 0x6]
	adds r1, r0, 0
	adds r1, 0x20
	movs r3, 0x1
	strb r3, [r1, 0x12]
	strb r3, [r0, 0x12]
	movs r4, 0
	strb r4, [r1, 0xB]
	strb r3, [r1, 0x11]
_0804E00C:
	ldr r5, [sp, 0x3C]
	mov r10, r5
	ldr r6, [sp, 0x14]
	cmp r10, r6
	bge _0804E018
	b _0804DBEC
_0804E018:
	ldr r7, [sp, 0x38]
	str r7, [sp, 0x20]
	adds r0, r7, 0
	ldr r1, [sp, 0x10]
	cmp r0, r1
	bge _0804E026
	b _0804DBDA
_0804E026:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E038: .4byte 0x0000fffc
	thumb_func_end sub_804D8C8

	thumb_func_start sub_804E03C
sub_804E03C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	cmp r0, r1
	blt _0804E058
	b _0804E318
_0804E058:
	movs r2, 0
	ldr r1, [sp, 0xC]
	adds r1, 0x1
	str r1, [sp, 0x28]
	ldr r3, [sp, 0x8]
	cmp r2, r3
	blt _0804E068
	b _0804E30C
_0804E068:
	ldr r4, [sp, 0xC]
	lsls r4, 4
	str r4, [sp, 0x14]
	ldr r6, [sp, 0xC]
	subs r0, r4, r6
	lsls r0, 5
	ldr r1, [sp]
	adds r0, r1
	str r0, [sp, 0x18]
_0804E07A:
	lsls r0, r2, 5
	ldr r3, [sp, 0x18]
	adds r4, r0, r3
	ldrb r1, [r4, 0x8]
	str r0, [sp, 0x34]
	adds r2, 0x1
	str r2, [sp, 0x2C]
	cmp r1, 0
	beq _0804E08E
	b _0804E302
_0804E08E:
	ldrb r0, [r4, 0x11]
	cmp r0, 0
	beq _0804E096
	b _0804E302
_0804E096:
	ldrb r0, [r4, 0x12]
	cmp r0, 0
	beq _0804E09E
	b _0804E302
_0804E09E:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _0804E0A6
	b _0804E302
_0804E0A6:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _0804E0AE
	b _0804E302
_0804E0AE:
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0804E0B6
	b _0804E302
_0804E0B6:
	ldrb r0, [r4, 0x10]
	cmp r0, 0
	beq _0804E0BE
	b _0804E302
_0804E0BE:
	ldrb r0, [r4, 0x1C]
	cmp r0, 0
	bne _0804E0C6
	b _0804E302
_0804E0C6:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, 0x3B
	bgt _0804E0D2
	b _0804E302
_0804E0D2:
	movs r6, 0x4
	ldrsh r2, [r4, r6]
	movs r1, 0
	ldrsh r0, [r4, r1]
	subs r2, r0
	movs r3, 0x6
	ldrsh r0, [r4, r3]
	movs r6, 0x2
	ldrsh r1, [r4, r6]
	subs r0, r1
	adds r2, r0
	str r2, [sp, 0x10]
	adds r0, r2, 0
	cmp r2, 0
	bge _0804E0F2
	adds r0, 0x3
_0804E0F2:
	asrs r0, 2
	str r0, [sp, 0x10]
	cmp r0, 0
	bne _0804E0FE
	movs r0, 0x1
	str r0, [sp, 0x10]
_0804E0FE:
	movs r1, 0
	ldr r2, [sp, 0x10]
	cmp r1, r2
	blt _0804E108
	b _0804E302
_0804E108:
	ldr r3, [sp, 0x14]
	ldr r4, [sp, 0xC]
	subs r0, r3, r4
	lsls r0, 5
	ldr r6, [sp]
	adds r0, r6
	ldr r2, [sp, 0x34]
	adds r0, r2, r0
	str r0, [sp, 0x20]
_0804E11A:
	movs r4, 0
	adds r1, 0x1
	str r1, [sp, 0x30]
_0804E120:
	movs r0, 0x4
	bl DungeonRandomCapped
	str r0, [sp, 0x1C]
	cmp r0, 0x1
	beq _0804E14A
	cmp r0, 0x1
	ble _0804E138
	cmp r0, 0x2
	beq _0804E168
	cmp r0, 0x3
	beq _0804E182
_0804E138:
	ldr r3, [sp, 0x20]
	movs r6, 0
	ldrsh r7, [r3, r6]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	mov r8, r0
	cmp r4, 0
	bne _0804E19C
	b _0804E15C
_0804E14A:
	ldr r2, [sp, 0x20]
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	subs r7, r0, 0x1
	movs r0, 0x2
	ldrsh r6, [r2, r0]
	mov r8, r6
	cmp r4, 0
	beq _0804E162
_0804E15C:
	movs r3, 0
	movs r2, 0x1
	b _0804E1A0
_0804E162:
	movs r3, 0x1
	negs r3, r3
	b _0804E19E
_0804E168:
	ldr r1, [sp, 0x20]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	subs r7, r0, 0x1
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	subs r0, 0x1
	mov r8, r0
	cmp r4, 0
	beq _0804E194
	movs r3, 0x1
	negs r3, r3
	b _0804E19E
_0804E182:
	ldr r6, [sp, 0x20]
	movs r0, 0
	ldrsh r7, [r6, r0]
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	mov r8, r0
	cmp r4, 0
	beq _0804E19C
_0804E194:
	movs r3, 0
	movs r2, 0x1
	negs r2, r2
	b _0804E1A0
_0804E19C:
	movs r3, 0x1
_0804E19E:
	movs r2, 0
_0804E1A0:
	movs r6, 0
	mov r9, r6
	ldr r5, [sp, 0x34]
	ldr r0, [sp, 0x14]
	str r0, [sp, 0x40]
	ldr r6, [sp, 0x18]
	adds r1, r5, r6
	movs r6, 0
	ldrsh r0, [r1, r6]
	mov r10, r0
	adds r4, 0x1
	str r4, [sp, 0x24]
	cmp r7, r10
	bge _0804E1BE
	b _0804E2F0
_0804E1BE:
	movs r4, 0x4
	ldrsh r0, [r1, r4]
	cmp r7, r0
	blt _0804E1C8
	b _0804E2F0
_0804E1C8:
	ldr r6, [sp, 0x40]
	ldr r1, [sp, 0xC]
	subs r0, r6, r1
	lsls r0, 5
	ldr r4, [sp]
	adds r0, r4
	adds r4, r5, r0
	movs r6, 0x2
	ldrsh r0, [r4, r6]
	cmp r8, r0
	bge _0804E1E0
	b _0804E2F0
_0804E1E0:
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r8, r0
	blt _0804E1EA
	b _0804E2F0
_0804E1EA:
	adds r0, r7, 0
	mov r1, r8
	str r2, [sp, 0x38]
	str r3, [sp, 0x3C]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	ldr r2, [sp, 0x38]
	ldr r3, [sp, 0x3C]
	cmp r0, 0x1
	bne _0804E2D0
	movs r6, 0
_0804E206:
	ldr r1, _0804E228
	lsls r0, r6, 2
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r1, r7
	mov r10, r1
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	add r0, r8
	mov r9, r0
	movs r3, 0
	movs r5, 0x1
	negs r5, r5
_0804E222:
	movs r4, 0x1
	negs r4, r4
	b _0804E22E
	.align 2, 0
_0804E228: .4byte gAdjacentTileOffsets
_0804E22C:
	adds r4, 0x1
_0804E22E:
	cmp r4, 0x1
	bgt _0804E25A
	mov r1, r10
	adds r0, r1, r4
	mov r2, r9
	adds r1, r2, r5
	str r3, [sp, 0x3C]
	bl GetMapTile_1
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	ldr r3, [sp, 0x3C]
	cmp r0, 0x1
	bne _0804E22C
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	bne _0804E256
	movs r3, 0x1
_0804E256:
	cmp r3, 0
	beq _0804E22C
_0804E25A:
	cmp r3, 0
	bne _0804E26A
	adds r5, 0x1
	cmp r5, 0x1
	ble _0804E222
	adds r6, 0x1
	cmp r6, 0x7
	ble _0804E206
_0804E26A:
	cmp r6, 0x8
	bne _0804E2F0
	movs r6, 0
	ldr r3, [sp, 0x1C]
	lsls r1, r3, 3
	ldr r0, _0804E2C4
	adds r4, r1, r0
_0804E278:
	ldr r0, _0804E2C8
	lsls r1, r6, 2
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	adds r0, r7, r0
	add r1, r8
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	movs r1, 0
	cmp r0, 0x1
	bne _0804E29C
	movs r1, 0x1
_0804E29C:
	ldrb r0, [r4]
	cmp r0, r1
	bne _0804E2AA
	adds r4, 0x2
	adds r6, 0x2
	cmp r6, 0x7
	ble _0804E278
_0804E2AA:
	cmp r6, 0x8
	bne _0804E2F0
	adds r0, r7, 0
	mov r1, r8
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r4, _0804E2CC
	adds r1, r4, 0
	ands r2, r1
	strh r2, [r0]
	b _0804E2F0
	.align 2, 0
_0804E2C4: .4byte gUnknown_80F6DD5
_0804E2C8: .4byte gAdjacentTileOffsets
_0804E2CC: .4byte 0x0000fffc
_0804E2D0:
	adds r7, r3
	add r8, r2
	movs r6, 0x1
	add r9, r6
	mov r0, r9
	cmp r0, 0x9
	bgt _0804E2F0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r7, r0
	blt _0804E2F0
	movs r6, 0x4
	ldrsh r0, [r4, r6]
	cmp r7, r0
	bge _0804E2F0
	b _0804E1C8
_0804E2F0:
	ldr r4, [sp, 0x24]
	cmp r4, 0x1
	bgt _0804E2F8
	b _0804E120
_0804E2F8:
	ldr r1, [sp, 0x30]
	ldr r0, [sp, 0x10]
	cmp r1, r0
	bge _0804E302
	b _0804E11A
_0804E302:
	ldr r2, [sp, 0x2C]
	ldr r1, [sp, 0x8]
	cmp r2, r1
	bge _0804E30C
	b _0804E07A
_0804E30C:
	ldr r2, [sp, 0x28]
	str r2, [sp, 0xC]
	ldr r3, [sp, 0x4]
	cmp r2, r3
	bge _0804E318
	b _0804E058
_0804E318:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804E03C

	thumb_func_start sub_804E328
sub_804E328:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	ldr r0, [sp, 0x28]
	lsls r0, 24
	mov r10, r5
	mov r9, r4
	ldr r1, [sp, 0x2C]
	mov r8, r1
	ldr r7, [sp, 0x30]
	cmp r0, 0
	bne _0804E350
	b _0804E470
_0804E350:
	movs r6, 0
_0804E352:
	cmp r4, r7
	beq _0804E3A8
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E360
	b _0804E57E
_0804E360:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E390
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r3, _0804E38C
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E39C
	.align 2, 0
_0804E38C: .4byte 0x0000fffc
_0804E390:
	cmp r5, r10
	beq _0804E396
	b _0804E57E
_0804E396:
	cmp r4, r9
	beq _0804E39C
	b _0804E57E
_0804E39C:
	cmp r4, r7
	bge _0804E3A4
	adds r4, 0x1
	b _0804E352
_0804E3A4:
	subs r4, 0x1
	b _0804E352
_0804E3A8:
	movs r6, 0
	ldr r0, [sp]
	cmp r5, r0
	beq _0804E40A
	movs r7, 0
_0804E3B2:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E3BC
	b _0804E57E
_0804E3BC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E3EC
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r3, _0804E3E8
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E3F8
	.align 2, 0
_0804E3E8: .4byte 0x0000fffc
_0804E3EC:
	cmp r5, r10
	beq _0804E3F2
	b _0804E57E
_0804E3F2:
	cmp r4, r9
	beq _0804E3F8
	b _0804E57E
_0804E3F8:
	ldr r0, [sp]
	cmp r5, r0
	bge _0804E402
	adds r5, 0x1
	b _0804E404
_0804E402:
	subs r5, 0x1
_0804E404:
	ldr r1, [sp]
	cmp r5, r1
	bne _0804E3B2
_0804E40A:
	movs r6, 0
	ldr r3, [sp, 0x4]
	cmp r4, r3
	bne _0804E414
	b _0804E57E
_0804E414:
	movs r7, 0
_0804E416:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E420
	b _0804E57E
_0804E420:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E450
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r3, _0804E44C
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E45C
	.align 2, 0
_0804E44C: .4byte 0x0000fffc
_0804E450:
	cmp r5, r10
	beq _0804E456
	b _0804E57E
_0804E456:
	cmp r4, r9
	beq _0804E45C
	b _0804E57E
_0804E45C:
	ldr r0, [sp, 0x4]
	cmp r4, r0
	bge _0804E466
	adds r4, 0x1
	b _0804E468
_0804E466:
	subs r4, 0x1
_0804E468:
	ldr r1, [sp, 0x4]
	cmp r4, r1
	bne _0804E416
	b _0804E57E
_0804E470:
	movs r6, 0
	cmp r5, r8
	beq _0804E4C6
	movs r7, 0
_0804E478:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	ble _0804E482
	b _0804E57E
_0804E482:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E4B0
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r3, _0804E4AC
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E4B8
	.align 2, 0
_0804E4AC: .4byte 0x0000fffc
_0804E4B0:
	cmp r5, r10
	bne _0804E57E
	cmp r4, r9
	bne _0804E57E
_0804E4B8:
	cmp r5, r8
	bge _0804E4C0
	adds r5, 0x1
	b _0804E4C2
_0804E4C0:
	subs r5, 0x1
_0804E4C2:
	cmp r5, r8
	bne _0804E478
_0804E4C6:
	movs r6, 0
	ldr r0, [sp, 0x4]
	cmp r4, r0
	beq _0804E522
	movs r7, 0
_0804E4D0:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	bgt _0804E57E
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E508
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r3, _0804E504
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E510
	.align 2, 0
_0804E504: .4byte 0x0000fffc
_0804E508:
	cmp r5, r10
	bne _0804E57E
	cmp r4, r9
	bne _0804E57E
_0804E510:
	ldr r0, [sp, 0x4]
	cmp r4, r0
	bge _0804E51A
	adds r4, 0x1
	b _0804E51C
_0804E51A:
	subs r4, 0x1
_0804E51C:
	ldr r1, [sp, 0x4]
	cmp r4, r1
	bne _0804E4D0
_0804E522:
	movs r6, 0
	ldr r3, [sp]
	cmp r5, r3
	beq _0804E57E
	movs r7, 0
_0804E52C:
	adds r0, r6, 0
	adds r6, 0x1
	cmp r0, 0x37
	bgt _0804E57E
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804E564
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r3, _0804E560
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strh r2, [r0]
	b _0804E56C
	.align 2, 0
_0804E560: .4byte 0x0000fffc
_0804E564:
	cmp r5, r10
	bne _0804E57E
	cmp r4, r9
	bne _0804E57E
_0804E56C:
	ldr r0, [sp]
	cmp r5, r0
	bge _0804E576
	adds r5, 0x1
	b _0804E578
_0804E576:
	subs r5, 0x1
_0804E578:
	ldr r1, [sp]
	cmp r5, r1
	bne _0804E52C
_0804E57E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804E328

	thumb_func_start sub_804E590
sub_804E590:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	str r0, [sp, 0xC]
	str r1, [sp, 0x10]
	str r2, [sp, 0x14]
	str r3, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	cmp r0, r1
	blt _0804E5AE
	b _0804E8AA
_0804E5AE:
	movs r1, 0x1
	mov r10, r1
_0804E5B2:
	movs r2, 0
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x1C]
	adds r3, 0x1
	str r3, [sp, 0x2C]
	ldr r4, [sp, 0x14]
	cmp r2, r4
	blt _0804E5C4
	b _0804E89E
_0804E5C4:
	ldr r5, [sp, 0x1C]
	lsls r5, 4
	ldr r6, [sp, 0x1C]
	subs r1, r5, r6
	lsls r1, 5
	ldr r2, [sp, 0xC]
	movs r3, 0xF0
	lsls r3, 1
	adds r0, r2, r3
	adds r0, r1
	mov r8, r0
	adds r6, r1, r2
	ldr r4, _0804E6A4
	adds r0, r2, r4
	adds r7, r1, r0
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r1
	mov r9, r0
	ldr r5, [sp, 0x60]
	str r5, [sp, 0x34]
	adds r0, r2, 0
	subs r0, 0x20
	adds r1, r0
	str r1, [sp, 0x38]
	movs r0, 0
	str r0, [sp, 0x3C]
	ldr r1, [sp, 0x1C]
	lsls r0, r1, 2
	ldr r2, [sp, 0x18]
	adds r0, r2
	str r0, [sp, 0x28]
_0804E604:
	ldr r3, [sp, 0x1C]
	lsls r0, r3, 4
	subs r0, r3
	lsls r0, 5
	ldr r4, [sp, 0xC]
	adds r0, r4
	ldr r5, [sp, 0x3C]
	adds r4, r5, r0
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0804E61C
	b _0804E874
_0804E61C:
	ldrb r0, [r4, 0x11]
	cmp r0, 0
	beq _0804E624
	b _0804E874
_0804E624:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	beq _0804E62C
	b _0804E874
_0804E62C:
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _0804E634
	b _0804E848
_0804E634:
	ldrb r0, [r4, 0x9]
	cmp r0, 0
	beq _0804E63C
	b _0804E848
_0804E63C:
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	str r0, [sp, 0x24]
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	adds r0, 0x1
	movs r5, 0x6
	ldrsh r1, [r4, r5]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r5, r0, 0
	ldr r0, [sp, 0x20]
	cmp r0, 0
	ble _0804E6DC
	subs r4, 0x20
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	bne _0804E6DC
	ldrb r0, [r4, 0x12]
	cmp r0, 0
	bne _0804E6DC
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	beq _0804E6DC
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	beq _0804E6A8
	movs r1, 0
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r5, r0, 0
	movs r3, 0x2
	ldrsh r0, [r4, r3]
	adds r0, 0x1
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	b _0804E6AC
	.align 2, 0
_0804E6A4: .4byte 0xfffffe20
_0804E6A8:
	movs r3, 0
	ldrsh r5, [r4, r3]
_0804E6AC:
	movs r4, 0x2
	ldrsh r1, [r6, r4]
	ldr r0, [sp, 0x38]
	movs r2, 0x6
	ldrsh r3, [r0, r2]
	subs r3, 0x1
	mov r4, r10
	str r4, [sp]
	ldr r2, [sp, 0x28]
	ldr r0, [r2]
	str r0, [sp, 0x4]
	ldr r4, [sp, 0x34]
	ldr r0, [r4]
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x24]
	adds r2, r5, 0
	bl sub_804E328
	mov r5, r10
	strb r5, [r6, 0xB]
	strb r5, [r6, 0x13]
	ldr r0, [sp, 0x38]
	strb r5, [r0, 0x14]
	b _0804E874
_0804E6DC:
	ldr r0, [sp, 0x14]
	subs r0, 0x1
	ldr r1, [sp, 0x20]
	cmp r1, r0
	bge _0804E758
	mov r2, r9
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804E758
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	bne _0804E758
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804E758
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804E724
	movs r3, 0x20
	ldrsh r0, [r6, r3]
	adds r0, 0x1
	movs r4, 0x24
	ldrsh r1, [r6, r4]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r5, r0, 0
	movs r1, 0x22
	ldrsh r0, [r6, r1]
	adds r0, 0x1
	movs r2, 0x26
	ldrsh r1, [r6, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	b _0804E728
_0804E724:
	movs r3, 0x20
	ldrsh r5, [r6, r3]
_0804E728:
	movs r4, 0x6
	ldrsh r1, [r6, r4]
	subs r1, 0x1
	movs r0, 0x22
	ldrsh r3, [r6, r0]
	mov r2, r10
	str r2, [sp]
	ldr r4, [sp, 0x28]
	ldr r0, [r4]
	str r0, [sp, 0x4]
	ldr r2, [sp, 0x34]
	ldr r0, [r2, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x24]
	adds r2, r5, 0
	bl sub_804E328
	mov r3, r10
	strb r3, [r6, 0xB]
	strb r3, [r6, 0x14]
	mov r4, r9
	strb r3, [r4, 0x13]
	b _0804E874
_0804E758:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	ble _0804E7C8
	ldrb r0, [r7, 0x8]
	cmp r0, 0
	bne _0804E7C8
	ldrb r0, [r7, 0x12]
	cmp r0, 0
	bne _0804E7C8
	ldrb r0, [r7, 0xB]
	cmp r0, 0
	beq _0804E7C8
	ldrb r0, [r7, 0xA]
	cmp r0, 0
	beq _0804E79A
	movs r1, 0
	ldrsh r0, [r7, r1]
	adds r0, 0x1
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	subs r1, 0x1
	bl DungeonRandomRange
	movs r3, 0x2
	ldrsh r0, [r7, r3]
	adds r0, 0x1
	movs r4, 0x6
	ldrsh r1, [r7, r4]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r3, r0, 0
	b _0804E79E
_0804E79A:
	movs r0, 0x2
	ldrsh r3, [r7, r0]
_0804E79E:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r4, 0
	ldrsh r2, [r7, r4]
	subs r2, 0x1
	movs r1, 0
	str r1, [sp]
	ldr r4, [sp, 0x28]
	ldr r1, [r4]
	str r1, [sp, 0x4]
	ldr r4, [sp, 0x34]
	ldr r1, [r4]
	str r1, [sp, 0x8]
	adds r1, r5, 0
	bl sub_804E328
	mov r5, r10
	strb r5, [r6, 0xB]
	strb r5, [r6, 0x15]
	strb r5, [r7, 0x16]
	b _0804E874
_0804E7C8:
	ldr r0, [sp, 0x10]
	subs r0, 0x1
	ldr r1, [sp, 0x1C]
	cmp r1, r0
	bge _0804E874
	mov r2, r8
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804E874
	ldrb r0, [r2, 0x12]
	cmp r0, 0
	bne _0804E874
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804E874
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804E812
	movs r3, 0
	ldrsh r0, [r2, r3]
	adds r0, 0x1
	movs r4, 0x4
	ldrsh r1, [r2, r4]
	subs r1, 0x1
	bl DungeonRandomRange
	mov r1, r8
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, 0x1
	movs r3, 0x6
	ldrsh r1, [r1, r3]
	subs r1, 0x1
	bl DungeonRandomRange
	adds r3, r0, 0
	b _0804E818
_0804E812:
	mov r4, r8
	movs r0, 0x2
	ldrsh r3, [r4, r0]
_0804E818:
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	subs r0, 0x1
	mov r4, r8
	movs r1, 0
	ldrsh r2, [r4, r1]
	movs r1, 0
	str r1, [sp]
	ldr r4, [sp, 0x28]
	ldr r1, [r4, 0x4]
	subs r1, 0x1
	str r1, [sp, 0x4]
	ldr r4, [sp, 0x34]
	ldr r1, [r4]
	str r1, [sp, 0x8]
	adds r1, r5, 0
	bl sub_804E328
	mov r5, r10
	strb r5, [r6, 0xB]
	strb r5, [r6, 0x16]
	mov r0, r8
	strb r5, [r0, 0x15]
	b _0804E874
_0804E848:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, _0804E99C
	adds r2, r3, 0
	ands r1, r2
	strh r1, [r0]
	ldrh r1, [r0, 0x4]
	ldr r4, _0804E9A0
	adds r2, r4, 0
	ands r1, r2
	ldr r5, _0804E9A4
	adds r2, r5, 0
	ands r1, r2
	subs r3, 0x1
	adds r2, r3, 0
	ands r1, r2
	strh r1, [r0, 0x4]
_0804E874:
	movs r4, 0x20
	add r8, r4
	adds r6, 0x20
	adds r7, 0x20
	add r9, r4
	ldr r5, [sp, 0x34]
	adds r5, 0x4
	str r5, [sp, 0x34]
	ldr r0, [sp, 0x38]
	adds r0, 0x20
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x3C]
	adds r1, 0x20
	str r1, [sp, 0x3C]
	ldr r2, [sp, 0x20]
	adds r2, 0x1
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	cmp r2, r3
	bge _0804E89E
	b _0804E604
_0804E89E:
	ldr r4, [sp, 0x2C]
	str r4, [sp, 0x1C]
	ldr r5, [sp, 0x10]
	cmp r4, r5
	bge _0804E8AA
	b _0804E5B2
_0804E8AA:
	movs r6, 0
	str r6, [sp, 0x1C]
	ldr r0, [sp, 0x10]
	cmp r6, r0
	bge _0804E98A
_0804E8B4:
	movs r1, 0
	str r1, [sp, 0x20]
	ldr r2, [sp, 0x1C]
	adds r2, 0x1
	str r2, [sp, 0x2C]
	ldr r3, [sp, 0x14]
	cmp r1, r3
	bge _0804E980
	ldr r4, [sp, 0x1C]
	lsls r4, 4
	mov r9, r4
_0804E8CA:
	ldr r5, [sp, 0x20]
	lsls r2, r5, 5
	ldr r6, [sp, 0x1C]
	lsls r3, r6, 4
	subs r0, r3, r6
	lsls r0, 5
	ldr r1, [sp, 0xC]
	adds r4, r0, r1
	adds r1, r2, r4
	ldrb r0, [r1, 0x8]
	mov r8, r2
	adds r5, 0x1
	str r5, [sp, 0x30]
	cmp r0, 0
	bne _0804E976
	ldrb r0, [r1, 0x11]
	cmp r0, 0
	bne _0804E976
	ldrb r0, [r1, 0xB]
	cmp r0, 0
	bne _0804E976
	ldrb r0, [r1, 0xF]
	cmp r0, 0
	bne _0804E976
	movs r6, 0
	ldrsh r5, [r1, r6]
	movs r6, 0x4
	ldrsh r0, [r1, r6]
	cmp r5, r0
	bge _0804E976
	mov r10, r4
_0804E908:
	ldr r1, [sp, 0x1C]
	subs r0, r3, r1
	lsls r0, 5
	ldr r3, [sp, 0xC]
	adds r0, r3
	adds r0, r2, r0
	movs r6, 0x2
	ldrsh r4, [r0, r6]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _0804E95C
	mov r6, r8
	add r6, r10
_0804E926:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	ldr r3, _0804E99C
	adds r1, r3, 0
	ands r2, r1
	strh r2, [r0]
	ldrh r2, [r0, 0x4]
	adds r3, 0x1
	adds r1, r3, 0
	ands r2, r1
	adds r3, 0x1
	adds r1, r3, 0
	ands r2, r1
	subs r3, 0x3
	adds r1, r3, 0
	ands r2, r1
	strh r2, [r0, 0x4]
	movs r1, 0xFF
	strb r1, [r0, 0x9]
	adds r4, 0x1
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r4, r0
	blt _0804E926
_0804E95C:
	adds r5, r7, 0
	mov r2, r8
	mov r3, r9
	ldr r4, [sp, 0x1C]
	subs r0, r3, r4
	lsls r0, 5
	ldr r6, [sp, 0xC]
	adds r0, r6
	adds r0, r2, r0
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0804E908
_0804E976:
	ldr r2, [sp, 0x30]
	str r2, [sp, 0x20]
	ldr r3, [sp, 0x14]
	cmp r2, r3
	blt _0804E8CA
_0804E980:
	ldr r4, [sp, 0x2C]
	str r4, [sp, 0x1C]
	ldr r5, [sp, 0x10]
	cmp r4, r5
	blt _0804E8B4
_0804E98A:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E99C: .4byte 0x0000fffc
_0804E9A0: .4byte 0x0000fffe
_0804E9A4: .4byte 0x0000fffd
	thumb_func_end sub_804E590

	thumb_func_start sub_804E9A8
sub_804E9A8:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldrh r0, [r4]
	ldr r5, _0804E9D8
	adds r3, r5, 0
	ands r3, r0
	strh r3, [r4]
	cmp r1, 0
	beq _0804E9D0
	ldrb r0, [r4, 0x9]
	cmp r0, r2
	bne _0804E9D0
	adds r0, r3, 0
	ands r0, r5
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r4]
_0804E9D0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E9D8: .4byte 0x0000fffc
	thumb_func_end sub_804E9A8

	thumb_func_start sub_804E9DC
sub_804E9DC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r5, 0
	movs r0, 0x3
	mov r8, r0
	movs r7, 0x8
	ldr r3, _0804EAF0
	mov r9, r3
_0804E9F2:
	movs r4, 0
	adds r6, r5, 0x1
	mov r10, r6
_0804E9F8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	adds r6, r4, 0x1
	cmp r0, 0x1
	beq _0804EA0E
	b _0804EB0E
_0804EA0E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0804EAF4
	cmp r5, 0
	ble _0804EA4E
	subs r0, r5, 0x1
	adds r1, r4, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EA4E
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	strh r1, [r2]
	adds r0, r1, 0
	mov r6, r8
	ands r0, r6
	cmp r0, 0x2
	bne _0804EA4E
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
_0804EA4E:
	cmp r4, 0
	ble _0804EA82
	subs r1, r4, 0x1
	adds r0, r5, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EA82
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	orrs r1, r7
	strh r1, [r2]
	adds r0, r1, 0
	mov r6, r8
	ands r0, r6
	cmp r0, 0x2
	bne _0804EA82
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
_0804EA82:
	adds r6, r4, 0x1
	cmp r4, 0x1E
	bgt _0804EABA
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EABA
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	mov r12, r3
	orrs r1, r7
	strh r1, [r2]
	adds r0, r1, 0
	mov r3, r8
	ands r0, r3
	cmp r0, 0x2
	bne _0804EABA
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
_0804EABA:
	cmp r5, 0x36
	bgt _0804EB0E
	mov r0, r10
	adds r1, r4, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _0804EB0E
	ldrh r0, [r2]
	adds r1, r0, 0
	orrs r1, r7
	movs r3, 0
	orrs r1, r7
	strh r1, [r2]
	adds r0, r1, 0
	mov r4, r8
	ands r0, r4
	cmp r0, 0x2
	bne _0804EB0E
	mov r0, r9
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r2]
	b _0804EB0E
	.align 2, 0
_0804EAF0: .4byte 0x0000fffc
_0804EAF4:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFE
	bne _0804EB0E
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0xFF
	strb r1, [r0, 0x9]
_0804EB0E:
	adds r4, r6, 0
	cmp r4, 0x1F
	bgt _0804EB16
	b _0804E9F8
_0804EB16:
	mov r5, r10
	cmp r5, 0x37
	bgt _0804EB1E
	b _0804E9F2
_0804EB1E:
	bl sub_804EB30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804E9DC

	thumb_func_start sub_804EB30
sub_804EB30:
	push {r4-r7,lr}
	ldr r0, _0804EBB4
	ldr r6, [r0]
	movs r2, 0
	movs r1, 0x1F
	ldr r3, _0804EBB8
	adds r0, r6, r3
_0804EB3E:
	strh r2, [r0]
	subs r0, 0x2
	subs r1, 0x1
	cmp r1, 0
	bge _0804EB3E
	movs r5, 0
_0804EB4A:
	movs r4, 0
	adds r7, r5, 0x1
_0804EB4E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0804EBA2
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrb r3, [r0, 0x9]
	cmp r3, 0x1F
	bhi _0804EBA2
	lsls r0, r3, 1
	ldr r2, _0804EBBC
	adds r1, r6, r2
	adds r2, r1, r0
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x1F
	bgt _0804EBA2
	lsls r0, 2
	lsls r1, r3, 7
	adds r0, r1
	adds r0, r6, r0
	ldr r3, _0804EBC0
	adds r0, r3
	strh r5, [r0]
	movs r3, 0
	ldrsh r0, [r2, r3]
	lsls r0, 2
	adds r0, r1
	adds r0, r6, r0
	ldr r1, _0804EBC4
	adds r0, r1
	strh r4, [r0]
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
_0804EBA2:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0804EB4E
	adds r5, r7, 0
	cmp r5, 0x37
	ble _0804EB4A
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804EBB4: .4byte gDungeonGlobalData
_0804EBB8: .4byte 0x00010882
_0804EBBC: .4byte 0x00010844
_0804EBC0: .4byte 0x00010884
_0804EBC4: .4byte 0x00010886
	thumb_func_end sub_804EB30

	thumb_func_start sub_804EBC8
sub_804EBC8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	mov r10, r2
	adds r4, r3, 0
	ldr r0, _0804EE90
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _0804EE94
	ldr r0, _0804EE98
	strh r0, [r1]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1, 0x2]
	ldr r0, _0804EE9C
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804EBF8
	b _0804EED4
_0804EBF8:
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0804EC06
	b _0804EED4
_0804EC06:
	cmp r4, 0
	bne _0804EC0C
	b _0804EED4
_0804EC0C:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r4, r0
	bgt _0804EC18
	b _0804EED4
_0804EC18:
	movs r5, 0
	add r7, sp, 0x20
	adds r1, r7, 0
	mov r0, sp
_0804EC20:
	strh r5, [r0]
	strh r5, [r1]
	adds r1, 0x2
	adds r0, 0x2
	adds r5, 0x1
	cmp r5, 0xE
	ble _0804EC20
	movs r5, 0xC7
_0804EC30:
	movs r0, 0xF
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0xF
	bl DungeonRandomCapped
	lsls r4, 1
	mov r1, sp
	adds r2, r1, r4
	movs r4, 0
	ldrsh r3, [r2, r4]
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
	subs r5, 0x1
	cmp r5, 0
	bge _0804EC30
	adds r6, r7, 0
	movs r5, 0xC7
_0804EC5C:
	movs r0, 0xF
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0xF
	bl DungeonRandomCapped
	lsls r4, 1
	adds r4, r6, r4
	movs r1, 0
	ldrsh r2, [r4, r1]
	lsls r0, 1
	adds r0, r6, r0
	ldrh r1, [r0]
	strh r1, [r4]
	strh r2, [r0]
	subs r5, 0x1
	cmp r5, 0
	bge _0804EC5C
	movs r5, 0
_0804EC84:
	lsls r0, r5, 1
	add r0, sp
	movs r3, 0
	ldrsh r2, [r0, r3]
	mov r9, r2
	ldr r4, [sp, 0x44]
	cmp r9, r4
	blt _0804EC96
	b _0804EECC
_0804EC96:
	movs r4, 0
_0804EC98:
	lsls r0, r4, 1
	adds r0, r7, r0
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, r10
	blt _0804ECA6
	b _0804EEC4
_0804ECA6:
	lsls r1, 5
	mov r3, r9
	lsls r2, r3, 4
	subs r0, r2, r3
	lsls r0, 5
	ldr r3, [sp, 0x40]
	adds r0, r3
	adds r3, r1, r0
	ldrb r0, [r3, 0x8]
	str r1, [sp, 0x4C]
	str r2, [sp, 0x48]
	cmp r0, 0
	beq _0804ECC2
	b _0804EEC4
_0804ECC2:
	ldrb r0, [r3, 0x11]
	cmp r0, 0
	beq _0804ECCA
	b _0804EEC4
_0804ECCA:
	ldrb r0, [r3, 0x12]
	cmp r0, 0
	beq _0804ECD2
	b _0804EEC4
_0804ECD2:
	ldrb r0, [r3, 0xB]
	cmp r0, 0
	bne _0804ECDA
	b _0804EEC4
_0804ECDA:
	ldrb r0, [r3, 0xA]
	cmp r0, 0
	bne _0804ECE2
	b _0804EEC4
_0804ECE2:
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	beq _0804ECEA
	b _0804EEC4
_0804ECEA:
	ldrb r0, [r3, 0x10]
	cmp r0, 0
	beq _0804ECF2
	b _0804EEC4
_0804ECF2:
	ldrb r0, [r3, 0x1D]
	cmp r0, 0
	beq _0804ECFA
	b _0804EEC4
_0804ECFA:
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	movs r2, 0
	ldrsh r0, [r3, r2]
	subs r1, r0
	cmp r1, 0
	bge _0804ED0A
	negs r1, r1
_0804ED0A:
	cmp r1, 0x4
	bgt _0804ED10
	b _0804EEC4
_0804ED10:
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	subs r1, r0
	cmp r1, 0
	bge _0804ED20
	negs r1, r1
_0804ED20:
	cmp r1, 0x3
	bgt _0804ED26
	b _0804EEC4
_0804ED26:
	ldr r1, _0804EEA0
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r3, 0xC]
	ldr r2, _0804EEA4
	movs r4, 0
	ldrsh r0, [r3, r4]
	adds r0, 0x1
	str r0, [r2]
	movs r7, 0x4
	ldrsh r0, [r3, r7]
	subs r0, 0x1
	str r0, [r2, 0x8]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	adds r1, 0x1
	str r1, [r2, 0x4]
	movs r4, 0x6
	ldrsh r3, [r3, r4]
	subs r0, r3, 0x1
	str r0, [r2, 0xC]
	subs r0, r1
	mov r10, r2
	cmp r0, 0x2
	bgt _0804ED5C
	str r3, [r2, 0xC]
_0804ED5C:
	ldr r0, _0804EEA8
	add r0, r8
	ldr r1, _0804EEAC
	str r1, [r0]
	ldr r0, _0804EEB0
	add r0, r8
	str r1, [r0]
	ldr r0, _0804EEB4
	add r0, r8
	ldr r1, _0804EEB8
	str r1, [r0]
	ldr r0, _0804EEBC
	add r0, r8
	str r1, [r0]
	mov r7, r10
	ldr r5, [r7]
	ldr r0, [r7, 0x8]
	cmp r5, r0
	bge _0804EDFA
	mov r3, r10
_0804ED84:
	ldr r4, [r3, 0x4]
	ldr r0, [r3, 0xC]
	adds r1, r5, 0x1
	str r1, [sp, 0x54]
	cmp r4, r0
	bge _0804EDF0
	ldr r6, _0804EEA8
	add r6, r8
	ldr r2, _0804EEA4
	mov r10, r2
_0804ED98:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x50]
	bl GetMapTile_2
	ldrh r2, [r0]
	movs r1, 0x20
	orrs r1, r2
	strh r1, [r0]
	ldrh r2, [r0, 0x4]
	ldr r7, _0804EEC0
	adds r1, r7, 0
	ands r2, r1
	adds r7, 0x7
	adds r1, r7, 0
	ands r2, r1
	strh r2, [r0, 0x4]
	ldr r0, [r6]
	ldr r3, [sp, 0x50]
	cmp r0, r5
	ble _0804EDC4
	str r5, [r6]
_0804EDC4:
	ldr r1, _0804EEB0
	add r1, r8
	ldr r0, [r1]
	cmp r0, r4
	ble _0804EDD0
	str r4, [r1]
_0804EDD0:
	ldr r1, _0804EEB4
	add r1, r8
	ldr r0, [r1]
	cmp r0, r5
	bge _0804EDDC
	str r5, [r1]
_0804EDDC:
	ldr r1, _0804EEBC
	add r1, r8
	ldr r0, [r1]
	cmp r0, r4
	bge _0804EDE8
	str r4, [r1]
_0804EDE8:
	adds r4, 0x1
	ldr r0, [r3, 0xC]
	cmp r4, r0
	blt _0804ED98
_0804EDF0:
	ldr r5, [sp, 0x54]
	mov r1, r10
	ldr r0, [r1, 0x8]
	cmp r5, r0
	blt _0804ED84
_0804EDFA:
	ldr r3, [sp, 0x4C]
	ldr r2, [sp, 0x48]
	mov r4, r9
	subs r0, r2, r4
	lsls r0, 5
	ldr r7, [sp, 0x40]
	adds r1, r0, r7
	adds r0, r3, r1
	movs r4, 0
	ldrsh r5, [r0, r4]
	movs r7, 0x4
	ldrsh r0, [r0, r7]
	cmp r5, r0
	bge _0804EE6C
	mov r8, r1
_0804EE18:
	mov r1, r9
	subs r0, r2, r1
	lsls r0, 5
	ldr r2, [sp, 0x40]
	adds r0, r2
	adds r0, r3, r0
	movs r3, 0x2
	ldrsh r4, [r0, r3]
	movs r7, 0x6
	ldrsh r0, [r0, r7]
	adds r1, r5, 0x1
	str r1, [sp, 0x54]
	cmp r4, r0
	bge _0804EE52
	ldr r6, [sp, 0x4C]
	add r6, r8
_0804EE38:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x10
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x1
	movs r2, 0x6
	ldrsh r0, [r6, r2]
	cmp r4, r0
	blt _0804EE38
_0804EE52:
	ldr r5, [sp, 0x54]
	ldr r3, [sp, 0x4C]
	ldr r2, [sp, 0x48]
	mov r4, r9
	subs r0, r2, r4
	lsls r0, 5
	ldr r7, [sp, 0x40]
	adds r0, r7
	adds r0, r3, r0
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0804EE18
_0804EE6C:
	ldr r2, _0804EEA4
	ldr r0, [r2]
	ldr r1, [r2, 0x8]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r5, r0, 1
	ldr r0, [r2, 0x4]
	ldr r1, [r2, 0xC]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r4, r0, 1
	ldr r0, _0804EE94
	strh r5, [r0]
	strh r4, [r0, 0x2]
	b _0804EED4
	.align 2, 0
_0804EE90: .4byte gDungeonGlobalData
_0804EE94: .4byte gUnknown_202F1D8
_0804EE98: .4byte 0x0000ffff
_0804EE9C: .4byte gUnknown_202F1AB
_0804EEA0: .4byte gUnknown_202F1AA
_0804EEA4: .4byte gUnknown_202F1B8
_0804EEA8: .4byte 0x0000e240
_0804EEAC: .4byte 0x0000270f
_0804EEB0: .4byte 0x0000e244
_0804EEB4: .4byte 0x0000e248
_0804EEB8: .4byte 0xffffd8f1
_0804EEBC: .4byte 0x0000e24c
_0804EEC0: .4byte 0x0000fff7
_0804EEC4:
	adds r4, 0x1
	cmp r4, 0xE
	bgt _0804EECC
	b _0804EC98
_0804EECC:
	adds r5, 0x1
	cmp r5, 0xE
	bgt _0804EED4
	b _0804EC84
_0804EED4:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804EBC8

	thumb_func_start sub_804EEE4
sub_804EEE4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x108
	str r0, [sp, 0x100]
	mov r8, r1
	adds r7, r2, 0
	adds r4, r3, 0
	ldr r5, _0804F094
	ldr r0, [r5]
	str r0, [sp, 0x104]
	cmp r4, 0
	bne _0804EF04
	b _0804F0C0
_0804EF04:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r4, r0
	bgt _0804EF10
	b _0804F0C0
_0804EF10:
	ldr r0, _0804F098
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804EF1A
	b _0804F0C0
_0804EF1A:
	ldr r0, [r5]
	movs r1, 0xD1
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	beq _0804EF2C
	b _0804F0C0
_0804EF2C:
	bl sub_8043D10
	lsls r0, 24
	cmp r0, 0
	beq _0804EF38
	b _0804F0C0
_0804EF38:
	movs r6, 0
	movs r1, 0
	cmp r1, r8
	bge _0804EF94
_0804EF40:
	adds r2, r1, 0x1
	cmp r7, 0
	ble _0804EF8E
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	ldr r1, [sp, 0x100]
	adds r1, 0x8
	adds r1, r0, r1
	adds r3, r7, 0
_0804EF54:
	ldrb r0, [r1]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0804EF86
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0804EF86
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _0804EF86
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _0804EF86
	adds r6, 0x1
_0804EF86:
	adds r1, 0x20
	subs r3, 0x1
	cmp r3, 0
	bne _0804EF54
_0804EF8E:
	adds r1, r2, 0
	cmp r1, r8
	blt _0804EF40
_0804EF94:
	cmp r6, 0
	bne _0804EF9A
	b _0804F0C0
_0804EF9A:
	movs r1, 0
	mov r0, sp
	adds r0, 0xFF
_0804EFA0:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0804EFA0
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1]
	movs r5, 0x3F
_0804EFB0:
	adds r0, r6, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r6, 0
	bl DungeonRandomCapped
	mov r3, sp
	adds r2, r3, r4
	ldrb r3, [r2]
	mov r4, sp
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	subs r5, 0x1
	cmp r5, 0
	bge _0804EFB0
	movs r5, 0
	movs r1, 0
	cmp r1, r8
	bge _0804F0C0
	ldr r6, [sp, 0x100]
	mov r9, r6
	movs r4, 0
_0804EFE2:
	movs r3, 0
	cmp r3, r7
	bge _0804F0B2
	mov r10, r3
	lsls r0, r4, 5
	ldr r6, [sp, 0x100]
	adds r2, r0, r6
_0804EFF0:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0x11]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804F0A6
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804F0A6
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0xF]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0x10]
	cmp r0, 0
	bne _0804F0A6
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	bne _0804F0A6
	mov r6, sp
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804F0A4
	ldr r1, _0804F09C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r2, 0xE]
	movs r0, 0
	ldrsh r5, [r2, r0]
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	cmp r5, r0
	bge _0804F0C0
	mov r2, r10
	add r2, r9
	mov r8, r2
_0804F046:
	mov r1, r10
	add r1, r9
	movs r3, 0x2
	ldrsh r4, [r1, r3]
	movs r6, 0x6
	ldrsh r0, [r1, r6]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _0804F086
	adds r6, r1, 0
_0804F05A:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	movs r1, 0x40
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrb r1, [r0, 0x9]
	ldr r2, [sp, 0x104]
	ldr r3, _0804F0A0
	adds r0, r2, r3
	strb r1, [r0]
	adds r4, 0x1
	movs r1, 0x6
	ldrsh r0, [r6, r1]
	cmp r4, r0
	blt _0804F05A
_0804F086:
	adds r5, r7, 0
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	cmp r5, r0
	blt _0804F046
	b _0804F0C0
	.align 2, 0
_0804F094: .4byte gDungeonGlobalData
_0804F098: .4byte gUnknown_202F1AA
_0804F09C: .4byte gUnknown_202F1AB
_0804F0A0: .4byte 0x00003a0c
_0804F0A4:
	adds r5, 0x1
_0804F0A6:
	movs r6, 0x20
	add r10, r6
	adds r2, 0x20
	adds r3, 0x1
	cmp r3, r7
	blt _0804EFF0
_0804F0B2:
	movs r0, 0xF0
	lsls r0, 1
	add r9, r0
	adds r4, 0xF
	adds r1, 0x1
	cmp r1, r8
	blt _0804EFE2
_0804F0C0:
	add sp, 0x108
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804EEE4

	thumb_func_start sub_804F0D0
sub_804F0D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x104
	str r0, [sp, 0x100]
	mov r10, r1
	mov r9, r2
	adds r4, r3, 0
	ldr r0, _0804F244
	ldr r5, [r0]
	cmp r4, 0
	bne _0804F0EE
	b _0804F266
_0804F0EE:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r4, r0
	bgt _0804F0FA
	b _0804F266
_0804F0FA:
	ldr r1, _0804F248
	adds r0, r5, r1
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	blt _0804F108
	b _0804F266
_0804F108:
	movs r5, 0
	movs r6, 0
	cmp r6, r10
	bge _0804F184
_0804F110:
	adds r7, r6, 0x1
	mov r4, r9
	cmp r4, 0
	ble _0804F17E
	lsls r0, r6, 4
	subs r0, r6
	lsls r0, 5
	ldr r6, [sp, 0x100]
	adds r2, r0, r6
_0804F122:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0x11]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804F176
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804F176
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0xF]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0xE]
	cmp r0, 0
	bne _0804F176
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	bne _0804F176
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	subs r0, r1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0804F176
	movs r6, 0x6
	ldrsh r0, [r2, r6]
	movs r6, 0x2
	ldrsh r1, [r2, r6]
	subs r0, r1
	ands r0, r3
	cmp r0, 0
	beq _0804F176
	adds r5, 0x1
_0804F176:
	adds r2, 0x20
	subs r4, 0x1
	cmp r4, 0
	bne _0804F122
_0804F17E:
	adds r6, r7, 0
	cmp r6, r10
	blt _0804F110
_0804F184:
	cmp r5, 0
	beq _0804F266
	movs r1, 0
	mov r0, sp
	adds r0, 0xFF
_0804F18E:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0804F18E
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1]
	movs r7, 0x3F
	mov r8, r7
_0804F1A0:
	adds r0, r5, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r5, 0
	bl DungeonRandomCapped
	mov r1, sp
	adds r2, r1, r4
	ldrb r3, [r2]
	adds r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	movs r3, 0x1
	negs r3, r3
	add r8, r3
	mov r4, r8
	cmp r4, 0
	bge _0804F1A0
	movs r6, 0
	mov r8, r6
	cmp r6, r10
	bge _0804F266
	ldr r7, [sp, 0x100]
	mov r12, r7
_0804F1D4:
	movs r4, 0
	cmp r4, r9
	bge _0804F25A
	mov r2, r12
	mov r5, r12
_0804F1DE:
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0x11]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0xB]
	cmp r0, 0
	beq _0804F250
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	beq _0804F250
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0xF]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0xE]
	cmp r0, 0
	bne _0804F250
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	bne _0804F250
	movs r1, 0x4
	ldrsh r0, [r2, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	subs r0, r1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0804F250
	movs r7, 0x6
	ldrsh r0, [r2, r7]
	movs r7, 0x2
	ldrsh r1, [r2, r7]
	subs r0, r1
	ands r0, r3
	cmp r0, 0
	beq _0804F250
	mov r0, sp
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804F24C
	adds r0, r5, 0
	movs r1, 0
	bl sub_804F278
	b _0804F266
	.align 2, 0
_0804F244: .4byte gDungeonGlobalData
_0804F248: .4byte 0x00003a16
_0804F24C:
	movs r0, 0x1
	add r8, r0
_0804F250:
	adds r2, 0x20
	adds r5, 0x20
	adds r4, 0x1
	cmp r4, r9
	blt _0804F1DE
_0804F25A:
	movs r1, 0xF0
	lsls r1, 1
	add r12, r1
	adds r6, 0x1
	cmp r6, r10
	blt _0804F1D4
_0804F266:
	add sp, 0x104
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F0D0

	thumb_func_start sub_804F278
sub_804F278:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	ldr r1, _0804F2B0
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r4, 0x10]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	mov r9, r0
	movs r5, 0
	ldrsh r0, [r4, r5]
	adds r6, r0, 0x1
	b _0804F2F0
	.align 2, 0
_0804F2B0: .4byte gUnknown_202F1AC
_0804F2B4:
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	subs r1, 0x1
	adds r0, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F2EE
	movs r5, 0x2
	ldrsh r3, [r4, r5]
	subs r1, r3, 0x1
	movs r0, 0
	ldrsh r2, [r4, r0]
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r5, 0x6
	ldrsh r0, [r4, r5]
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	mov r5, r9
	str r5, [sp, 0xC]
	adds r0, r6, 0
	bl sub_804F494
_0804F2EE:
	adds r6, 0x2
_0804F2F0:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	subs r0, 0x1
	cmp r6, r0
	blt _0804F2B4
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r5, r0, 0x1
	movs r6, 0x6
	ldrsh r0, [r4, r6]
	b _0804F342
_0804F306:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F33C
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	movs r6, 0
	ldrsh r2, [r4, r6]
	movs r1, 0x2
	ldrsh r3, [r4, r1]
	str r0, [sp]
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	mov r6, r9
	str r6, [sp, 0xC]
	adds r1, r5, 0
	bl sub_804F494
_0804F33C:
	adds r5, 0x2
	movs r1, 0x6
	ldrsh r0, [r4, r1]
_0804F342:
	subs r0, 0x1
	cmp r5, r0
	blt _0804F306
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r6, r0, 0x1
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	b _0804F392
_0804F354:
	movs r0, 0x6
	ldrsh r1, [r4, r0]
	adds r0, r6, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F38C
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	movs r5, 0
	ldrsh r2, [r4, r5]
	movs r0, 0x2
	ldrsh r3, [r4, r0]
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	str r0, [sp]
	adds r0, r1, 0
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	mov r5, r9
	str r5, [sp, 0xC]
	adds r0, r6, 0
	bl sub_804F494
_0804F38C:
	adds r6, 0x2
	movs r1, 0x4
	ldrsh r0, [r4, r1]
_0804F392:
	subs r0, 0x1
	cmp r6, r0
	blt _0804F354
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	adds r5, r0, 0x1
	movs r6, 0x6
	ldrsh r0, [r4, r6]
	b _0804F3E4
_0804F3A4:
	movs r1, 0
	ldrsh r0, [r4, r1]
	subs r0, 0x1
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804F3DE
	movs r6, 0
	ldrsh r2, [r4, r6]
	subs r0, r2, 0x1
	movs r1, 0x2
	ldrsh r3, [r4, r1]
	movs r6, 0x4
	ldrsh r1, [r4, r6]
	str r1, [sp]
	movs r6, 0x6
	ldrsh r1, [r4, r6]
	str r1, [sp, 0x4]
	mov r1, r8
	str r1, [sp, 0x8]
	mov r6, r9
	str r6, [sp, 0xC]
	adds r1, r5, 0
	bl sub_804F494
_0804F3DE:
	adds r5, 0x2
	movs r1, 0x6
	ldrsh r0, [r4, r1]
_0804F3E4:
	subs r0, 0x1
	cmp r5, r0
	blt _0804F3A4
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r6, r0, 0x3
	b _0804F478
_0804F3F2:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r5, r0, 0x3
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	subs r0, 0x3
	adds r1, r6, 0x2
	mov r10, r1
	cmp r5, r0
	bge _0804F476
	ldr r2, _0804F434
	adds r7, r2, 0
_0804F40A:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0804F46A
	mov r0, r8
	cmp r0, 0
	beq _0804F438
	subs r0, r6, 0x1
	adds r1, r5, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ands r1, r7
	movs r2, 0x2
	orrs r1, r2
	b _0804F444
	.align 2, 0
_0804F434: .4byte 0x0000fffc
_0804F438:
	subs r0, r6, 0x1
	adds r1, r5, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ands r1, r7
_0804F444:
	strh r1, [r0]
	movs r1, 0
	ldrsh r2, [r4, r1]
	movs r0, 0x2
	ldrsh r3, [r4, r0]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	mov r1, r9
	str r1, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_804F494
_0804F46A:
	adds r5, 0x2
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	subs r0, 0x3
	cmp r5, r0
	blt _0804F40A
_0804F476:
	mov r6, r10
_0804F478:
	movs r5, 0x4
	ldrsh r0, [r4, r5]
	subs r0, 0x3
	cmp r6, r0
	blt _0804F3F2
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F278

	thumb_func_start sub_804F494
sub_804F494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	ldr r0, [sp, 0x30]
	ldr r1, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 24
	mov r8, r1
	movs r0, 0x3
	mov r10, r0
_0804F4BA:
	movs r0, 0x4
	bl DungeonRandomCapped
	adds r6, r0, 0
	movs r7, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
_0804F4D6:
	adds r0, r6, 0
	mov r1, r10
	ands r0, r1
	cmp r0, 0x1
	beq _0804F4F6
	cmp r0, 0x1
	bgt _0804F4EA
	cmp r0, 0
	beq _0804F4F0
	b _0804F506
_0804F4EA:
	cmp r0, 0x2
	beq _0804F4FE
	b _0804F506
_0804F4F0:
	movs r0, 0x2
	movs r1, 0
	b _0804F50A
_0804F4F6:
	movs r0, 0
	movs r1, 0x2
	negs r1, r1
	b _0804F50A
_0804F4FE:
	movs r0, 0x2
	negs r0, r0
	movs r1, 0
	b _0804F50A
_0804F506:
	movs r0, 0
	movs r1, 0x2
_0804F50A:
	adds r0, r5, r0
	ldr r2, [sp]
	cmp r2, r0
	bgt _0804F534
	ldr r3, [sp, 0x28]
	cmp r3, r0
	ble _0804F534
	adds r1, r4, r1
	ldr r2, [sp, 0x4]
	cmp r2, r1
	bgt _0804F534
	ldr r3, [sp, 0x2C]
	cmp r3, r1
	ble _0804F534
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r10
	ands r0, r1
	cmp r0, 0x1
	beq _0804F53E
_0804F534:
	adds r6, 0x1
	adds r7, 0x1
	cmp r7, 0x3
	bgt _0804F5B2
	b _0804F4D6
_0804F53E:
	mov r0, r10
	ands r0, r6
	cmp r0, 0x1
	beq _0804F570
	cmp r0, 0x1
	bgt _0804F550
	cmp r0, 0
	beq _0804F55A
	b _0804F4BA
_0804F550:
	cmp r0, 0x2
	beq _0804F586
	cmp r0, 0x3
	beq _0804F59C
	b _0804F4BA
_0804F55A:
	adds r0, r5, 0x1
	adds r1, r4, 0
	bl GetMapTile_2
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
	adds r5, 0x2
	b _0804F4BA
_0804F570:
	subs r1, r4, 0x1
	adds r0, r5, 0
	bl GetMapTile_2
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
	subs r4, 0x2
	b _0804F4BA
_0804F586:
	subs r0, r5, 0x1
	adds r1, r4, 0
	bl GetMapTile_2
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
	subs r5, 0x2
	b _0804F4BA
_0804F59C:
	adds r1, r4, 0x1
	adds r0, r5, 0
	bl GetMapTile_2
	mov r1, r9
	mov r3, r8
	lsrs r2, r3, 24
	bl sub_804E9A8
	adds r4, 0x2
	b _0804F4BA
_0804F5B2:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F494

	thumb_func_start sub_804F5C4
sub_804F5C4:
	ldrh r3, [r0]
	ldr r2, _0804F5D4
	ands r2, r3
	movs r3, 0x2
	orrs r2, r3
	orrs r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0
_0804F5D4: .4byte 0x0000fffc
	thumb_func_end sub_804F5C4

	thumb_func_start sub_804F5D8
sub_804F5D8:
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r0, 0
	ldrsh r6, [r5, r0]
	b _0804F60C
_0804F5E2:
	movs r0, 0x2
	ldrsh r4, [r5, r0]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	adds r7, r6, 0x1
	cmp r4, r0
	bge _0804F60A
_0804F5F0:
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x20
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x1
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _0804F5F0
_0804F60A:
	adds r6, r7, 0
_0804F60C:
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	cmp r6, r0
	blt _0804F5E2
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F5D8

	thumb_func_start sub_804F61C
sub_804F61C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	mov r8, r1
	movs r7, 0x1
	negs r7, r7
	b _0804F67A
_0804F62E:
	movs r5, 0x1
	negs r5, r5
	b _0804F666
_0804F634:
	cmp r7, 0
	beq _0804F63C
	cmp r5, 0
	bne _0804F660
_0804F63C:
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0804F660
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	bne _0804F660
	movs r0, 0x1
	b _0804F686
_0804F660:
	adds r5, 0x1
	cmp r5, 0x1
	bgt _0804F672
_0804F666:
	mov r0, r8
	adds r4, r0, r5
	cmp r4, 0
	blt _0804F660
	cmp r4, 0x1F
	ble _0804F634
_0804F672:
	adds r7, 0x1
	cmp r7, 0x1
	bgt _0804F684
	mov r0, r9
_0804F67A:
	adds r6, r0, r7
	cmp r6, 0
	blt _0804F672
	cmp r6, 0x37
	ble _0804F62E
_0804F684:
	movs r0, 0
_0804F686:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_804F61C

	thumb_func_start sub_804F694
sub_804F694:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r7, r0, 0
	movs r0, 0x6
	bl DungeonRandomCapped
	subs r0, 0x1
	cmp r0, 0x4
	bls _0804F6B0
	b _0804FBD6
_0804F6B0:
	lsls r0, 2
	ldr r1, _0804F6BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F6BC: .4byte _0804F6C0
	.align 2, 0
_0804F6C0:
	.4byte _0804FB24
	.4byte _0804FA98
	.4byte _0804F9DC
	.4byte _0804F826
	.4byte _0804F6D4
_0804F6D4:
	ldr r1, _0804F70C
	ldr r0, [r1]
	cmp r0, 0
	bne _0804F6DE
	b _0804FBD6
_0804F6DE:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl sub_804F5D8
	movs r0, 0x2
	bl DungeonRandomCapped
	cmp r0, 0
	beq _0804F78E
	movs r5, 0
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r2, 0x4
	ldrsh r1, [r7, r2]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	mov r8, r0
	movs r3, 0x2
	ldrsh r4, [r7, r3]
	b _0804F712
	.align 2, 0
_0804F70C: .4byte gUnknown_202F1C8
_0804F710:
	adds r4, 0x1
_0804F712:
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	cmp r4, r0
	bge _0804F72A
	mov r0, r8
	adds r1, r4, 0
	bl sub_804F61C
	lsls r0, 24
	cmp r0, 0
	beq _0804F710
	movs r5, 0x1
_0804F72A:
	cmp r5, 0
	beq _0804F730
	b _0804FBD6
_0804F730:
	movs r2, 0x2
	ldrsh r4, [r7, r2]
	movs r3, 0x6
	ldrsh r0, [r7, r3]
	cmp r4, r0
	bge _0804F754
_0804F73C:
	mov r0, r8
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
	adds r4, 0x1
	movs r5, 0x6
	ldrsh r0, [r7, r5]
	cmp r4, r0
	blt _0804F73C
_0804F754:
	movs r0, 0
	ldrsh r5, [r7, r0]
	cmp r5, r8
	blt _0804F75E
	b _0804FBD2
_0804F75E:
	movs r1, 0x2
	ldrsh r4, [r7, r1]
	movs r2, 0x6
	ldrsh r0, [r7, r2]
	adds r6, r5, 0x1
	cmp r4, r0
	bge _0804F786
_0804F76C:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strh r1, [r0]
	adds r4, 0x1
	movs r3, 0x6
	ldrsh r0, [r7, r3]
	cmp r4, r0
	blt _0804F76C
_0804F786:
	adds r5, r6, 0
	cmp r5, r8
	blt _0804F75E
	b _0804FBD2
_0804F78E:
	movs r5, 0
	movs r4, 0x2
	ldrsh r0, [r7, r4]
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	mov r8, r0
	movs r3, 0
	ldrsh r4, [r7, r3]
	b _0804F7AA
_0804F7A8:
	adds r4, 0x1
_0804F7AA:
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	cmp r4, r0
	bge _0804F7C2
	adds r0, r4, 0
	mov r1, r8
	bl sub_804F61C
	lsls r0, 24
	cmp r0, 0
	beq _0804F7A8
	movs r5, 0x1
_0804F7C2:
	cmp r5, 0
	beq _0804F7C8
	b _0804FBD6
_0804F7C8:
	movs r2, 0
	ldrsh r4, [r7, r2]
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	cmp r4, r0
	bge _0804F7EC
_0804F7D4:
	adds r0, r4, 0
	mov r1, r8
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
	adds r4, 0x1
	movs r5, 0x4
	ldrsh r0, [r7, r5]
	cmp r4, r0
	blt _0804F7D4
_0804F7EC:
	movs r0, 0x2
	ldrsh r5, [r7, r0]
	cmp r5, r8
	blt _0804F7F6
	b _0804FBD2
_0804F7F6:
	movs r1, 0
	ldrsh r4, [r7, r1]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	adds r6, r5, 0x1
	cmp r4, r0
	bge _0804F81E
_0804F804:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	movs r1, 0x80
	orrs r1, r2
	strh r1, [r0]
	adds r4, 0x1
	movs r3, 0x4
	ldrsh r0, [r7, r3]
	cmp r4, r0
	blt _0804F804
_0804F81E:
	adds r5, r6, 0
	cmp r5, r8
	blt _0804F7F6
	b _0804FBD2
_0804F826:
	movs r4, 0x4
	ldrsh r3, [r7, r4]
	movs r5, 0
	ldrsh r1, [r7, r5]
	subs r0, r3, r1
	cmp r0, 0x5
	bgt _0804F836
	b _0804FBD6
_0804F836:
	movs r0, 0x6
	ldrsh r4, [r7, r0]
	movs r5, 0x2
	ldrsh r2, [r7, r5]
	subs r0, r4, r2
	cmp r0, 0x5
	bgt _0804F846
	b _0804FBD6
_0804F846:
	adds r0, r1, r3
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp]
	adds r0, r2, r4
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp, 0x4]
	ldr r1, _0804F9D8
	ldr r0, [r1]
	cmp r0, 0
	bne _0804F864
	b _0804FBD6
_0804F864:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl sub_804F5D8
	ldr r5, [sp]
	subs r5, 0x2
	ldr r0, [sp, 0x4]
	subs r0, 0x2
	mov r10, r0
	adds r0, r5, 0
	mov r1, r10
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	ldr r1, [sp]
	subs r1, 0x1
	mov r9, r1
	mov r0, r9
	mov r1, r10
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	ldr r0, [sp]
	mov r1, r10
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	ldr r2, [sp]
	adds r2, 0x1
	mov r8, r2
	mov r0, r8
	mov r1, r10
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	ldr r6, [sp, 0x4]
	subs r6, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	adds r0, r5, 0
	ldr r1, [sp, 0x4]
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	ldr r4, [sp, 0x4]
	adds r4, 0x1
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r9
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	ldr r0, [sp]
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	mov r1, r10
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	adds r1, r6, 0
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	ldr r1, [sp, 0x4]
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r8
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0x4
	bl sub_804F5C4
	mov r0, r9
	adds r1, r6, 0
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x4
	orrs r1, r2
	strh r1, [r0, 0x4]
	mov r0, r9
	adds r1, r6, 0
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	movs r2, 0x40
	orrs r1, r2
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	adds r1, r6, 0
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	movs r4, 0x2
	orrs r1, r4
	strh r1, [r0, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x4]
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	mov r0, r9
	adds r1, r6, 0
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	movs r4, 0x10
	orrs r1, r4
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	adds r1, r6, 0
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	mov r0, r9
	ldr r1, [sp, 0x4]
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	orrs r1, r4
	strh r1, [r0, 0x4]
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	bl GetMapTile_2
	ldrh r1, [r0, 0x4]
	orrs r4, r1
	strh r4, [r0, 0x4]
	b _0804FBD2
	.align 2, 0
_0804F9D8: .4byte gUnknown_202F1C8
_0804F9DC:
	movs r4, 0x4
	ldrsh r3, [r7, r4]
	movs r5, 0
	ldrsh r2, [r7, r5]
	subs r0, r3, r2
	cmp r0, 0x4
	bgt _0804F9EC
	b _0804FBD6
_0804F9EC:
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r4, 0x2
	ldrsh r1, [r7, r4]
	subs r0, r1
	cmp r0, 0x4
	bgt _0804F9FC
	b _0804FBD6
_0804F9FC:
	adds r0, r2, 0x2
	subs r1, r3, 0x3
	bl DungeonRandomRange
	adds r4, r0, 0
	movs r5, 0x2
	ldrsh r0, [r7, r5]
	adds r0, 0x2
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	subs r1, 0x3
	bl DungeonRandomRange
	mov r10, r0
	movs r3, 0
	ldrsh r0, [r7, r3]
	adds r0, 0x2
	movs r5, 0x4
	ldrsh r1, [r7, r5]
	subs r1, 0x3
	bl DungeonRandomRange
	mov r9, r0
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	adds r0, 0x2
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	subs r1, 0x3
	bl DungeonRandomRange
	adds r6, r0, 0
	ldr r1, _0804FA94
	ldr r0, [r1]
	cmp r0, 0
	bne _0804FA46
	b _0804FBD6
_0804FA46:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl sub_804F5D8
	cmp r4, r9
	ble _0804FA5A
	adds r0, r4, 0
	mov r4, r9
	mov r9, r0
_0804FA5A:
	cmp r10, r6
	ble _0804FA64
	mov r0, r10
	mov r10, r6
	adds r6, r0, 0
_0804FA64:
	adds r5, r4, 0
	cmp r5, r9
	ble _0804FA6C
	b _0804FBD2
_0804FA6C:
	mov r4, r10
	adds r3, r5, 0x1
	mov r8, r3
	cmp r4, r6
	bgt _0804FA8A
_0804FA76:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
	adds r4, 0x1
	cmp r4, r6
	ble _0804FA76
_0804FA8A:
	mov r5, r8
	cmp r5, r9
	ble _0804FA6C
	b _0804FBD2
	.align 2, 0
_0804FA94: .4byte gUnknown_202F1C8
_0804FA98:
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r5, 0
	ldrsh r1, [r7, r5]
	subs r0, r1
	movs r2, 0x1
	ands r0, r2
	cmp r0, 0
	bne _0804FAAC
	b _0804FBD6
_0804FAAC:
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r3, 0x2
	ldrsh r1, [r7, r3]
	subs r0, r1
	ands r0, r2
	cmp r0, 0
	bne _0804FABE
	b _0804FBD6
_0804FABE:
	ldr r1, _0804FB20
	ldr r0, [r1]
	cmp r0, 0
	bne _0804FAC8
	b _0804FBD6
_0804FAC8:
	subs r0, 0x1
	str r0, [r1]
	adds r0, r7, 0
	bl sub_804F5D8
	movs r6, 0x3F
_0804FAD4:
	movs r4, 0x4
	ldrsh r0, [r7, r4]
	movs r5, 0
	ldrsh r1, [r7, r5]
	subs r0, r1
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r2, 0x2
	ldrsh r1, [r7, r2]
	subs r0, r1
	bl DungeonRandomCapped
	adds r2, r0, 0
	adds r0, r4, r2
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	beq _0804FB14
	movs r3, 0
	ldrsh r0, [r7, r3]
	adds r0, r4
	movs r4, 0x2
	ldrsh r1, [r7, r4]
	adds r1, r2
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
_0804FB14:
	subs r6, 0x1
	cmp r6, 0
	bge _0804FAD4
	strb r5, [r7, 0x9]
	b _0804FBD6
	.align 2, 0
_0804FB20: .4byte gUnknown_202F1C8
_0804FB24:
	ldr r1, _0804FBC0
	ldr r0, [r1]
	cmp r0, 0
	beq _0804FBD6
	subs r0, 0x1
	str r0, [r1]
	movs r5, 0x4
	ldrsh r3, [r7, r5]
	movs r0, 0
	ldrsh r2, [r7, r0]
	subs r6, r3, r2
	movs r4, 0x1
	adds r0, r6, 0
	ands r0, r4
	cmp r0, 0
	beq _0804FB54
	movs r1, 0x6
	ldrsh r0, [r7, r1]
	movs r5, 0x2
	ldrsh r1, [r7, r5]
	subs r0, r1
	ands r0, r4
	cmp r0, 0
	bne _0804FBC4
_0804FB54:
	adds r0, r2, r3
	lsrs r1, r0, 31
	adds r0, r1
	asrs r5, r0, 1
	movs r0, 0x2
	ldrsh r3, [r7, r0]
	movs r1, 0x6
	ldrsh r2, [r7, r1]
	adds r0, r3, r2
	lsrs r1, r0, 31
	adds r0, r1
	asrs r4, r0, 1
	cmp r6, 0x4
	ble _0804FBAE
	subs r0, r2, r3
	cmp r0, 0x4
	ble _0804FBAE
	adds r0, r5, 0x1
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
	adds r1, r4, 0x1
	adds r0, r5, 0
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
	subs r0, r5, 0x1
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
	subs r1, r4, 0x1
	adds r0, r5, 0
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
_0804FBAE:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0
	bl sub_804F5C4
	b _0804FBD2
	.align 2, 0
_0804FBC0: .4byte gUnknown_202F1C8
_0804FBC4:
	adds r0, r7, 0
	bl sub_804F5D8
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_804F278
_0804FBD2:
	movs r0, 0x1
	strb r0, [r7, 0x9]
_0804FBD6:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F694

	thumb_func_start sub_804FBE8
sub_804FBE8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r0, _0804FC6C
	adds r5, r0, 0
_0804FBF4:
	movs r4, 0
	adds r3, r6, 0x1
	mov r8, r3
_0804FBFA:
	adds r0, r6, 0
	adds r1, r4, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	beq _0804FC2A
	movs r7, 0x88
	lsls r7, 1
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0804FC24
	ldrh r0, [r2, 0x4]
	ldr r3, _0804FC70
	adds r1, r3, 0
	ands r0, r1
	strh r0, [r2, 0x4]
_0804FC24:
	ldrh r0, [r2, 0x4]
	ands r0, r5
	strh r0, [r2, 0x4]
_0804FC2A:
	ldrh r3, [r2, 0x4]
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0804FC46
	ldrh r0, [r2]
	movs r7, 0x80
	lsls r7, 2
	adds r1, r7, 0
	orrs r1, r0
	strh r1, [r2]
	adds r0, r3, 0
	ands r0, r5
	strh r0, [r2, 0x4]
_0804FC46:
	ldrh r1, [r2, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804FC56
	adds r0, r1, 0
	ands r0, r5
	strh r0, [r2, 0x4]
_0804FC56:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0804FBFA
	mov r6, r8
	cmp r6, 0x37
	ble _0804FBF4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FC6C: .4byte 0x0000fffb
_0804FC70: .4byte 0x0000fffd
	thumb_func_end sub_804FBE8

	thumb_func_start sub_804FC74
sub_804FC74:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
	movs r0, 0x3
	mov r8, r0
	ldr r0, _0804FCC8
	adds r7, r0, 0
_0804FC86:
	movs r4, 0
	adds r6, r5, 0x1
_0804FC8A:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0804FCAE
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ands r1, r7
	mov r2, r8
	orrs r1, r2
	strh r1, [r0]
_0804FCAE:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0804FC8A
	adds r5, r6, 0
	cmp r5, 0x37
	ble _0804FC86
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FCC8: .4byte 0x0000fffc
	thumb_func_end sub_804FC74

	thumb_func_start sub_804FCCC
sub_804FCCC:
	push {r4-r7,lr}
	movs r5, 0
	ldr r0, _0804FD0C
	adds r7, r0, 0
_0804FCD4:
	movs r4, 0
	adds r6, r5, 0x1
_0804FCD8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0804FCF8
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ands r1, r7
	strh r1, [r0]
_0804FCF8:
	adds r4, 0x1
	cmp r4, 0x1F
	ble _0804FCD8
	adds r5, r6, 0
	cmp r5, 0x37
	ble _0804FCD4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FD0C: .4byte 0x0000fffc
	thumb_func_end sub_804FCCC

	thumb_func_start sub_804FD10
sub_804FD10:
	movs r2, 0
	movs r3, 0
	strh r3, [r0]
	strh r3, [r0, 0x4]
	movs r1, 0xFF
	strb r1, [r0, 0x9]
	strb r2, [r0, 0x8]
	strb r2, [r0, 0xA]
	strb r2, [r0, 0xB]
	strb r2, [r0, 0xC]
	strb r2, [r0, 0xD]
	strb r2, [r0, 0xE]
	str r3, [r0, 0x10]
	str r3, [r0, 0x14]
	bx lr
	thumb_func_end sub_804FD10

	thumb_func_start sub_804FD30
sub_804FD30:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r6, 0
_0804FD3A:
	movs r7, 0
	adds r4, r6, 0x1
_0804FD3E:
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMapTile_2
	bl sub_804FD10
	subs r3, r7, 0x1
	cmp r6, 0
	blt _0804FD5C
	cmp r3, 0
	blt _0804FD5C
	cmp r6, 0x37
	bgt _0804FD5C
	cmp r3, 0x1F
	ble _0804FD60
_0804FD5C:
	movs r0, 0x1
	b _0804FD62
_0804FD60:
	movs r0, 0
_0804FD62:
	cmp r0, 0
	bne _0804FE24
	cmp r4, 0
	blt _0804FD76
	cmp r3, 0
	blt _0804FD76
	cmp r4, 0x37
	bgt _0804FD76
	cmp r3, 0x1F
	ble _0804FD7A
_0804FD76:
	movs r0, 0x1
	b _0804FD7C
_0804FD7A:
	movs r0, 0
_0804FD7C:
	cmp r0, 0
	bne _0804FE24
	cmp r4, 0
	blt _0804FD90
	cmp r3, 0
	blt _0804FD90
	cmp r4, 0x37
	bgt _0804FD90
	cmp r3, 0x1F
	ble _0804FD94
_0804FD90:
	movs r0, 0x1
	b _0804FD96
_0804FD94:
	movs r0, 0
_0804FD96:
	cmp r0, 0
	bne _0804FE24
	adds r2, r7, 0x1
	cmp r4, 0
	blt _0804FDAC
	cmp r2, 0
	blt _0804FDAC
	cmp r4, 0x37
	bgt _0804FDAC
	cmp r2, 0x1F
	ble _0804FDB0
_0804FDAC:
	movs r0, 0x1
	b _0804FDB2
_0804FDB0:
	movs r0, 0
_0804FDB2:
	cmp r0, 0
	bne _0804FE24
	cmp r6, 0
	blt _0804FDC6
	cmp r2, 0
	blt _0804FDC6
	cmp r6, 0x37
	bgt _0804FDC6
	cmp r2, 0x1F
	ble _0804FDCA
_0804FDC6:
	movs r0, 0x1
	b _0804FDCC
_0804FDCA:
	movs r0, 0
_0804FDCC:
	cmp r0, 0
	bne _0804FE24
	adds r0, r2, 0
	subs r1, r6, 0x1
	cmp r1, 0
	blt _0804FDE4
	cmp r0, 0
	blt _0804FDE4
	cmp r1, 0x37
	bgt _0804FDE4
	cmp r2, 0x1F
	ble _0804FDE8
_0804FDE4:
	movs r0, 0x1
	b _0804FDEA
_0804FDE8:
	movs r0, 0
_0804FDEA:
	cmp r0, 0
	bne _0804FE24
	cmp r1, 0
	blt _0804FDFE
	cmp r7, 0
	blt _0804FDFE
	cmp r1, 0x37
	bgt _0804FDFE
	cmp r7, 0x1F
	ble _0804FE02
_0804FDFE:
	movs r0, 0x1
	b _0804FE04
_0804FE02:
	movs r0, 0
_0804FE04:
	cmp r0, 0
	bne _0804FE24
	adds r0, r3, 0
	cmp r1, 0
	blt _0804FE1A
	cmp r0, 0
	blt _0804FE1A
	cmp r1, 0x37
	bgt _0804FE1A
	cmp r3, 0x1F
	ble _0804FE1E
_0804FE1A:
	movs r0, 0x1
	b _0804FE20
_0804FE1E:
	movs r0, 0
_0804FE20:
	cmp r0, 0
	beq _0804FE34
_0804FE24:
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	movs r1, 0x10
	orrs r1, r2
	strh r1, [r0]
_0804FE34:
	adds r7, 0x1
	cmp r7, 0x1F
	ble _0804FD3E
	adds r6, 0x1
	cmp r6, 0x37
	bgt _0804FE42
	b _0804FD3A
_0804FE42:
	ldr r3, _0804FEB4
	ldr r1, [r3]
	ldr r0, _0804FEB8
	adds r2, r1, r0
	ldr r0, _0804FEBC
	strh r0, [r2]
	ldr r2, _0804FEC0
	adds r1, r2
	movs r0, 0x1
	negs r0, r0
	strh r0, [r1]
	movs r6, 0
	mov r8, r3
	ldr r1, _0804FEC4
_0804FE5E:
	adds r5, r1, 0
	movs r4, 0
	movs r7, 0x7
_0804FE64:
	mov r2, r8
	ldr r0, [r2]
	adds r0, r5
	adds r0, r4
	str r1, [sp]
	bl sub_804FD10
	adds r4, 0x18
	subs r7, 0x1
	ldr r1, [sp]
	cmp r7, 0
	bge _0804FE64
	adds r1, 0xC0
	adds r6, 0x1
	cmp r6, 0x7
	ble _0804FE5E
	ldr r0, _0804FEB4
	ldr r1, [r0]
	ldr r2, _0804FEC8
	adds r1, r2
	movs r2, 0
	strh r2, [r1]
	movs r6, 0
	adds r4, r0, 0
	ldr r3, _0804FECC
_0804FE96:
	ldr r0, [r4]
	lsls r1, r6, 2
	adds r0, r3
	adds r0, r1
	ldr r0, [r0]
	str r2, [r0]
	adds r6, 0x1
	cmp r6, 0x3F
	ble _0804FE96
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FEB4: .4byte gDungeonGlobalData
_0804FEB8: .4byte 0x0000e21c
_0804FEBC: .4byte 0x0000ffff
_0804FEC0: .4byte 0x0000e21e
_0804FEC4: .4byte 0x0000e27c
_0804FEC8: .4byte 0x00003904
_0804FECC: .4byte 0x0001371c
	thumb_func_end sub_804FD30

	thumb_func_start sub_804FED0
sub_804FED0:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r5, r1, 0
	movs r6, 0
	b _0804FEFA
_0804FEDA:
	adds r0, r5, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r0, r5, 0
	bl DungeonRandomCapped
	lsls r4, 2
	adds r4, r7
	ldr r2, [r4]
	lsls r0, 2
	adds r0, r7
	ldr r1, [r0]
	str r1, [r4]
	str r2, [r0]
	adds r6, 0x1
_0804FEFA:
	lsls r0, r5, 1
	cmp r6, r0
	blt _0804FEDA
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804FED0

	thumb_func_start sub_804FF08
sub_804FF08:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08050234
	add sp, r4
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0xE0
	lsls r0, 5
	add r0, sp
	str r1, [r0]
	ldr r0, _08050238
	ldr r0, [r0]
	mov r9, r0
	ldr r0, _0805023C
	add r0, r9
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _0804FF46
	ldr r0, _08050240
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r1
	bne _08050038
_0804FF46:
	movs r0, 0
	mov r8, r0
	movs r6, 0
_0804FF4C:
	movs r5, 0
	mov r1, r8
	lsls r0, r1, 2
	mov r2, sp
	adds r4, r0, r2
_0804FF56:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	adds r1, r0, 0
	ldrh r2, [r1]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0x1
	bne _0804FFAA
	ldrb r0, [r1, 0x9]
	cmp r0, 0xFF
	beq _0804FFAA
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _0804FFAA
	ldrh r1, [r1, 0x4]
	movs r3, 0x8
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0804FFAA
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0804FFAA
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	bne _0804FFAA
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	bne _0804FFAA
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r2, 0x1
	add r8, r2
_0804FFAA:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0804FF56
	adds r6, 0x1
	cmp r6, 0x37
	ble _0804FF4C
	mov r0, r8
	cmp r0, 0
	beq _08050038
	bl DungeonRandomCapped
	lsls r0, 2
	mov r1, sp
	adds r4, r1, r0
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl GetMapTile_2
	adds r5, r0, 0
	ldrh r1, [r5, 0x4]
	movs r0, 0x1
	orrs r0, r1
	ldr r1, _08050244
	ands r0, r1
	strh r0, [r5, 0x4]
	ldr r1, _08050248
	ldrb r0, [r5, 0x9]
	strb r0, [r1]
	ldrb r1, [r4]
	ldr r0, _0805023C
	add r0, r9
	strh r1, [r0]
	ldrb r1, [r4, 0x1]
	ldr r0, _08050240
	add r0, r9
	strh r1, [r0]
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08050038
	ldrb r4, [r5, 0x9]
	movs r6, 0
_08050002:
	movs r5, 0
_08050004:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_2
	adds r1, r0, 0
	ldrh r2, [r1]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0x1
	bne _0805002C
	ldrb r0, [r1, 0x9]
	cmp r0, r4
	bne _0805002C
	movs r0, 0x40
	orrs r0, r2
	strh r0, [r1]
	ldrb r1, [r1, 0x9]
	ldr r0, _0805024C
	add r0, r9
	strb r1, [r0]
_0805002C:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _08050004
	adds r6, 0x1
	cmp r6, 0x37
	ble _08050002
_08050038:
	movs r2, 0
	mov r8, r2
	movs r6, 0
_0805003E:
	movs r5, 0
	adds r7, r6, 0x1
	mov r1, r8
	lsls r0, r1, 2
	mov r2, sp
	adds r4, r0, r2
_0805004A:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	adds r1, r0, 0
	ldrh r2, [r1]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0x1
	bne _08050092
	ldrb r0, [r1, 0x9]
	cmp r0, 0xFF
	beq _08050092
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _08050092
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	bne _08050092
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	bne _08050092
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	bne _08050092
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r2, 0x1
	add r8, r2
_08050092:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0805004A
	adds r6, r7, 0
	cmp r6, 0x37
	ble _0805003E
	mov r0, r8
	cmp r0, 0
	beq _080500FA
	mov r1, r10
	ldrb r4, [r1, 0xF]
	cmp r4, 0
	beq _080500FA
	subs r0, r4, 0x2
	adds r1, r4, 0x2
	bl DungeonRandomRange
	adds r4, r0, 0
	cmp r4, 0
	bgt _080500BC
	movs r4, 0x1
_080500BC:
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandomCapped
	adds r5, r0, 0
	cmp r4, 0
	ble _080500FA
	adds r6, r4, 0
	lsls r0, r5, 2
	mov r2, sp
	adds r4, r0, r2
_080500D8:
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x2
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r8
	bne _080500F4
	mov r4, sp
	movs r5, 0
_080500F4:
	subs r6, 0x1
	cmp r6, 0
	bne _080500D8
_080500FA:
	movs r0, 0
	mov r8, r0
	movs r6, 0
_08050100:
	movs r5, 0
	adds r7, r6, 0x1
	mov r1, r8
	lsls r0, r1, 2
	mov r2, sp
	adds r4, r0, r2
_0805010C:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08050128
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r0, 0x1
	add r8, r0
_08050128:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0805010C
	adds r6, r7, 0
	cmp r6, 0x37
	ble _08050100
	mov r1, r8
	cmp r1, 0
	beq _0805018E
	mov r2, r10
	ldrb r4, [r2, 0x14]
	cmp r4, 0
	beq _0805018E
	subs r0, r4, 0x2
	adds r1, r4, 0x2
	bl DungeonRandomRange
	adds r4, r0, 0
	cmp r4, 0
	ble _0805018E
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandomCapped
	adds r5, r0, 0
	cmp r4, 0
	ble _0805018E
	adds r6, r4, 0
	lsls r0, r5, 2
	mov r1, sp
	adds r4, r0, r1
_0805016C:
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x2
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r8
	bne _08050188
	mov r4, sp
	movs r5, 0
_08050188:
	subs r6, 0x1
	cmp r6, 0
	bne _0805016C
_0805018E:
	movs r2, 0
	mov r8, r2
	movs r0, 0xE0
	lsls r0, 5
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	bne _080501E4
	movs r6, 0
_080501A0:
	movs r5, 0
	adds r7, r6, 0x1
	mov r1, r8
	lsls r0, r1, 2
	mov r2, sp
	adds r4, r0, r2
_080501AC:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080501D8
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080501D8
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080501D8
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r0, 0x1
	add r8, r0
_080501D8:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _080501AC
	adds r6, r7, 0
	cmp r6, 0x37
	ble _080501A0
_080501E4:
	mov r1, r8
	cmp r1, 0
	beq _08050294
	lsrs r4, r1, 31
	add r4, r8
	asrs r4, 1
	lsls r0, r1, 3
	movs r1, 0xA
	bl __divsi3
	adds r1, r0, 0
	adds r0, r4, 0
	bl DungeonRandomRange
	adds r4, r0, 0
	cmp r4, 0x5
	bgt _08050208
	movs r4, 0x6
_08050208:
	ldr r0, _08050250
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r4, r0
	blt _08050214
	adds r4, r0, 0
_08050214:
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandomCapped
	adds r5, r0, 0
	cmp r4, 0
	ble _08050294
	adds r6, r4, 0
	lsls r0, r5, 2
	mov r1, sp
	adds r7, r0, r1
_08050230:
	ldrb r0, [r7]
	b _08050254
	.align 2, 0
_08050234: .4byte 0xffffe3fc
_08050238: .4byte gDungeonGlobalData
_0805023C: .4byte 0x0000e21c
_08050240: .4byte 0x0000e21e
_08050244: .4byte 0x0000fffd
_08050248: .4byte gUnknown_202F1B4
_0805024C: .4byte 0x00003a0c
_08050250: .4byte gUnknown_80F4DA0
_08050254:
	ldrb r1, [r7, 0x1]
	bl GetMapTile_2
	adds r4, r0, 0
	movs r0, 0x2
	bl DungeonRandomCapped
	cmp r0, 0
	beq _0805026C
	ldrh r0, [r4, 0x4]
	movs r1, 0x2
	b _0805027E
_0805026C:
	ldr r0, _08050424
	ldr r0, [r0]
	ldr r2, _08050428
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08050282
	ldrh r0, [r4, 0x4]
	movs r1, 0x4
_0805027E:
	orrs r0, r1
	strh r0, [r4, 0x4]
_08050282:
	adds r7, 0x4
	adds r5, 0x1
	cmp r5, r8
	bne _0805028E
	mov r7, sp
	movs r5, 0
_0805028E:
	subs r6, 0x1
	cmp r6, 0
	bne _08050230
_08050294:
	movs r0, 0
	mov r8, r0
	movs r6, 0
_0805029A:
	movs r5, 0
	adds r7, r6, 0x1
	mov r1, r8
	lsls r0, r1, 2
	mov r2, sp
	adds r4, r0, r2
_080502A6:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	adds r1, r0, 0
	ldrh r2, [r1]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0x1
	bne _080502F0
	ldrb r0, [r1, 0x9]
	cmp r0, 0xFF
	beq _080502F0
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _080502F0
	ldrh r1, [r1, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080502F0
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	bne _080502F0
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	bne _080502F0
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r2, 0x1
	add r8, r2
_080502F0:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _080502A6
	adds r6, r7, 0
	cmp r6, 0x37
	ble _0805029A
	mov r0, r8
	cmp r0, 0
	beq _08050356
	mov r2, r10
	ldrb r1, [r2, 0x10]
	lsrs r0, r1, 1
	bl DungeonRandomRange
	adds r4, r0, 0
	cmp r4, 0
	ble _08050356
	cmp r4, 0x37
	ble _08050318
	movs r4, 0x38
_08050318:
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandomCapped
	adds r5, r0, 0
	cmp r4, 0
	ble _08050356
	adds r6, r4, 0
	lsls r0, r5, 2
	mov r1, sp
	adds r4, r0, r1
_08050334:
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x4
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r8
	bne _08050350
	mov r4, sp
	movs r5, 0
_08050350:
	subs r6, 0x1
	cmp r6, 0
	bne _08050334
_08050356:
	ldr r0, _0805042C
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _08050372
	ldr r0, _08050430
	add r0, r9
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r1
	bne _08050410
_08050372:
	movs r0, 0
	mov r8, r0
	movs r6, 0
_08050378:
	movs r5, 0
	adds r7, r6, 0x1
	mov r1, r8
	lsls r0, r1, 2
	mov r2, sp
	adds r4, r0, r2
_08050384:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _080503E2
	ldrb r0, [r2, 0x9]
	cmp r0, 0xFF
	beq _080503E2
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080503E2
	movs r3, 0x8
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080503E2
	movs r0, 0x80
	lsls r0, 1
	mov r10, r0
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	bne _080503E2
	ldrh r1, [r2, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080503E2
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080503E2
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080503E2
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r1, 0x1
	add r8, r1
_080503E2:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _08050384
	adds r6, r7, 0
	cmp r6, 0x37
	ble _08050378
	mov r2, r8
	cmp r2, 0
	beq _08050410
	mov r0, r8
	bl DungeonRandomCapped
	lsls r0, 2
	mov r1, sp
	adds r2, r1, r0
	ldrb r1, [r2]
	ldr r0, _0805042C
	add r0, r9
	strh r1, [r0]
	ldrb r1, [r2, 0x1]
	ldr r0, _08050430
	add r0, r9
	strh r1, [r0]
_08050410:
	ldr r3, _08050434
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08050424: .4byte gDungeonGlobalData
_08050428: .4byte 0x0000065c
_0805042C: .4byte 0x0000e218
_08050430: .4byte 0x0000e21a
_08050434: .4byte 0x00001c04
	thumb_func_end sub_804FF08

	thumb_func_start sub_8050438
sub_8050438:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08050470
	add sp, r4
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0xE0
	lsls r2, 5
	add r2, sp
	str r1, [r2]
	ldr r1, _08050474
	ldr r1, [r1]
	mov r10, r1
	ldrb r1, [r0, 0x6]
	cmp r1, 0
	ble _08050478
	lsrs r0, r1, 1
	bl DungeonRandomRange
	adds r7, r0, 0
	cmp r7, 0
	bgt _0805047A
	movs r7, 0x1
	b _0805047A
	.align 2, 0
_08050470: .4byte 0xffffe3f8
_08050474: .4byte gDungeonGlobalData
_08050478:
	adds r7, r1, 0
_0805047A:
	movs r0, 0
	mov r8, r0
	movs r6, 0
_08050480:
	movs r5, 0
	adds r1, r6, 0x1
	mov r9, r1
	mov r2, r8
	lsls r0, r2, 2
	mov r1, sp
	adds r4, r0, r1
_0805048E:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	adds r1, r0, 0
	ldrh r3, [r1]
	movs r2, 0x3
	ands r2, r3
	cmp r2, 0x1
	bne _080504F6
	ldrb r0, [r1, 0x9]
	cmp r0, 0xFF
	beq _080504F6
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	bne _080504F6
	ldrh r1, [r1, 0x4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080504F6
	ands r2, r1
	cmp r2, 0
	bne _080504F6
	movs r0, 0x8
	ands r0, r3
	cmp r0, 0
	bne _080504F6
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	bne _080504F6
	ldr r0, _080506A0
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bne _080504EC
	ldr r0, _080506A4
	add r0, r10
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r5, r0
	beq _080504F6
_080504EC:
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r0, 0x1
	add r8, r0
_080504F6:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _0805048E
	mov r6, r9
	cmp r6, 0x37
	ble _08050480
	mov r1, r8
	cmp r1, 0
	beq _0805055E
	ldr r0, _080506A8
	ldr r0, [r0]
	movs r2, 0xD1
	lsls r2, 3
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0805051C
	adds r7, 0x1
_0805051C:
	cmp r7, 0
	beq _0805055E
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandomCapped
	adds r5, r0, 0
	cmp r7, 0
	ble _0805055E
	adds r6, r7, 0
	lsls r0, r5, 2
	mov r2, sp
	adds r4, r0, r2
_0805053C:
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x8
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r8
	bne _08050558
	mov r4, sp
	movs r5, 0
_08050558:
	subs r6, 0x1
	cmp r6, 0
	bne _0805053C
_0805055E:
	ldr r0, _080506AC
	add r0, r10
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805056A
	b _0805068C
_0805056A:
	ldr r0, _080506B0
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r2, _080506B4
	add r2, sp
	str r1, [r2]
	movs r0, 0
	mov r8, r0
	movs r1, 0xE0
	lsls r1, 5
	add r1, sp
	ldr r1, [r1]
	cmp r1, 0
	beq _0805058A
	movs r0, 0x3
	str r0, [r2]
_0805058A:
	ldr r1, _080506B4
	add r1, sp
	ldr r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	ldr r1, _080506B4
	add r1, sp
	str r0, [r1]
	movs r6, 0
_080505A2:
	movs r5, 0
	adds r2, r6, 0x1
	mov r9, r2
	mov r1, r8
	lsls r0, r1, 2
	mov r2, sp
	adds r4, r0, r2
_080505B0:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_1
	adds r1, r0, 0
	ldrh r2, [r1]
	movs r0, 0x3
	ands r0, r2
	cmp r0, 0x1
	bne _08050608
	ldrb r0, [r1, 0x9]
	cmp r0, 0xFF
	beq _08050608
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _08050608
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	bne _08050608
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _08050608
	ldr r0, _080506A0
	add r0, r10
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bne _080505FE
	ldr r0, _080506A4
	add r0, r10
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	beq _08050608
_080505FE:
	strb r6, [r4]
	strb r5, [r4, 0x1]
	adds r4, 0x4
	movs r2, 0x1
	add r8, r2
_08050608:
	adds r5, 0x1
	cmp r5, 0x1F
	ble _080505B0
	mov r6, r9
	cmp r6, 0x37
	ble _080505A2
	mov r0, r8
	cmp r0, 0
	beq _0805068C
	lsls r4, r0, 3
	subs r0, r4, r0
	movs r1, 0xA
	bl __divsi3
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r1, r0, 0
	adds r0, r5, 0
	bl DungeonRandomRange
	adds r7, r0, 0
	cmp r7, 0
	bne _0805063E
	movs r7, 0x1
_0805063E:
	ldr r1, _080506B4
	add r1, sp
	ldr r1, [r1]
	cmp r7, r1
	blt _0805064E
	ldr r2, _080506B4
	add r2, sp
	ldr r7, [r2]
_0805064E:
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandomCapped
	adds r5, r0, 0
	cmp r7, 0
	ble _0805068C
	adds r6, r7, 0
	lsls r0, r5, 2
	mov r1, sp
	adds r4, r0, r1
_0805066A:
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl GetMapTile_2
	ldrh r2, [r0, 0x4]
	movs r1, 0x8
	orrs r1, r2
	strh r1, [r0, 0x4]
	adds r4, 0x4
	adds r5, 0x1
	cmp r5, r8
	bne _08050686
	mov r4, sp
	movs r5, 0
_08050686:
	subs r6, 0x1
	cmp r6, 0
	bne _0805066A
_0805068C:
	ldr r3, _080506B8
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080506A0: .4byte 0x0000e218
_080506A4: .4byte 0x0000e21a
_080506A8: .4byte gDungeonGlobalData
_080506AC: .4byte 0x00003a08
_080506B0: .4byte gUnknown_80F4DA4
_080506B4: .4byte 0x00001c04
_080506B8: .4byte 0x00001c08
	thumb_func_end sub_8050438

	thumb_func_start sub_80506BC
sub_80506BC:
	push {lr}
	adds r3, r0, 0
	movs r2, 0x1
	ldrh r1, [r3]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080506CE
	movs r2, 0
_080506CE:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080506D8
	movs r2, 0
_080506D8:
	cmp r2, 0
	beq _080506E6
	ldr r0, _080506EC
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r3]
_080506E6:
	pop {r0}
	bx r0
	.align 2, 0
_080506EC: .4byte 0x0000fffc
	thumb_func_end sub_80506BC

	thumb_func_start sub_80506F0
sub_80506F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA4
	str r1, [sp, 0x64]
	ldrb r1, [r1, 0xD]
	ands r1, r0
	cmp r1, 0
	bne _08050708
	b _08050C20
_08050708:
	ldr r4, _08050738
	movs r0, 0x8
	bl DungeonRandomCapped
	lsls r0, 2
	adds r0, r4
	ldr r4, [r0]
	cmp r4, 0
	bne _0805071C
	b _08050A7C
_0805071C:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, 0x31
	bgt _0805073C
	movs r0, 0x1
	str r0, [sp, 0x74]
	movs r1, 0x1F
	mov r10, r1
	movs r2, 0x1
	negs r2, r2
	str r2, [sp, 0x70]
	b _08050746
	.align 2, 0
_08050738: .4byte gUnknown_80F6DF8
_0805073C:
	movs r0, 0
	str r0, [sp, 0x74]
	mov r10, r0
	movs r1, 0x1
	str r1, [sp, 0x70]
_08050746:
	movs r0, 0x32
	bl DungeonRandomCapped
	adds r0, 0xA
	str r0, [sp, 0x78]
	movs r0, 0x2
	movs r1, 0x36
	bl DungeonRandomRange
	mov r9, r0
	movs r2, 0
	str r2, [sp, 0x6C]
	subs r4, 0x1
	str r4, [sp, 0x98]
_08050762:
	movs r0, 0x6
	bl DungeonRandomCapped
	adds r0, 0x2
	str r0, [sp, 0x68]
	cmp r0, 0
	bne _08050772
	b _08050A38
_08050772:
	mov r0, r9
	cmp r0, 0x37
	bhi _080507B8
	mov r1, r10
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0805078A
	b _08050A74
_0805078A:
	mov r1, r9
	cmp r1, 0
	blt _080507A2
	mov r2, r10
	cmp r2, 0
	blt _080507A2
	mov r0, r9
	cmp r0, 0x37
	bgt _080507A2
	mov r1, r10
	cmp r1, 0x1F
	ble _080507A6
_080507A2:
	movs r0, 0x1
	b _080507A8
_080507A6:
	movs r0, 0
_080507A8:
	cmp r0, 0
	bne _080507B8
	mov r0, r9
	mov r1, r10
	bl GetMapTile_2
	bl sub_80506BC
_080507B8:
	ldr r2, [sp, 0x68]
	subs r2, 0x1
	str r2, [sp, 0x68]
	ldr r0, [sp, 0x6C]
	add r9, r0
	ldr r1, [sp, 0x70]
	add r10, r1
	mov r2, r10
	cmp r2, 0x1F
	bls _080507CE
	b _08050A38
_080507CE:
	ldr r0, [sp, 0x78]
	subs r0, 0x1
	str r0, [sp, 0x78]
	cmp r0, 0
	beq _080507DA
	b _08050A30
_080507DA:
	movs r1, 0x3F
	str r1, [sp, 0x7C]
_080507DE:
	movs r0, 0x7
	bl DungeonRandomCapped
	subs r0, 0x3
	str r0, [sp, 0x84]
	movs r0, 0x7
	bl DungeonRandomCapped
	subs r1, r0, 0x3
	ldr r6, [sp, 0x84]
	add r6, r9
	subs r0, r6, 0x2
	cmp r0, 0x33
	bhi _080508DA
	mov r2, r10
	adds r5, r1, r2
	cmp r5, 0x1
	ble _080508DA
	cmp r5, 0x1D
	bgt _080508DA
	adds r4, r6, 0x1
	adds r0, r5, 0x1
	mov r8, r0
	adds r0, r4, 0
	mov r1, r8
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r2, 0x3
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r4, 0
	adds r1, r5, 0
	str r2, [sp, 0x9C]
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	subs r7, r5, 0x1
	adds r0, r4, 0
	adds r1, r7, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r6, 0
	mov r1, r8
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	subs r4, r6, 0x1
	adds r0, r4, 0
	mov r1, r8
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r4, 0
	adds r1, r7, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	bne _080508DA
_080508B2:
	ldr r0, [sp, 0x84]
	add r0, r9
	cmp r0, 0
	blt _080508C6
	cmp r5, 0
	blt _080508C6
	cmp r0, 0x37
	bgt _080508C6
	cmp r5, 0x1F
	ble _080508CA
_080508C6:
	movs r1, 0x1
	b _080508CC
_080508CA:
	movs r1, 0
_080508CC:
	cmp r1, 0
	bne _080508DA
	adds r1, r5, 0
	bl GetMapTile_2
	bl sub_80506BC
_080508DA:
	ldr r1, [sp, 0x7C]
	subs r1, 0x1
	str r1, [sp, 0x7C]
	cmp r1, 0
	blt _080508E6
	b _080507DE
_080508E6:
	movs r0, 0x3
	negs r0, r0
_080508EA:
	movs r2, 0x3
	negs r2, r2
	str r2, [sp, 0x80]
	mov r1, r9
	adds r1, r0, r1
	str r1, [sp, 0x90]
	adds r0, 0x1
	str r0, [sp, 0x8C]
	adds r7, r1, 0
	mov r5, r10
	subs r5, 0x3
_08050900:
	movs r6, 0
	subs r0, r7, 0x2
	cmp r0, 0x33
	bls _0805090A
	b _08050A1A
_0805090A:
	str r5, [sp, 0x88]
	str r5, [sp, 0x94]
	cmp r5, 0x1
	bgt _08050914
	b _08050A1A
_08050914:
	cmp r5, 0x1D
	ble _0805091A
	b _08050A1A
_0805091A:
	adds r4, r7, 0x1
	adds r3, r5, 0x1
	adds r0, r4, 0
	adds r1, r3, 0
	str r3, [sp, 0xA0]
	bl GetMapTile_1
	ldrh r1, [r0]
	movs r2, 0x3
	mov r8, r2
	mov r0, r8
	ands r0, r1
	ldr r3, [sp, 0xA0]
	cmp r0, 0x2
	bne _0805093A
	movs r6, 0x1
_0805093A:
	adds r0, r4, 0
	adds r1, r5, 0
	str r3, [sp, 0xA0]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r3, [sp, 0xA0]
	cmp r0, 0x2
	bne _08050952
	adds r6, 0x1
_08050952:
	subs r2, r5, 0x1
	adds r0, r4, 0
	adds r1, r2, 0
	str r2, [sp, 0x9C]
	str r3, [sp, 0xA0]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x9C]
	ldr r3, [sp, 0xA0]
	cmp r0, 0x2
	bne _08050970
	adds r6, 0x1
_08050970:
	adds r0, r7, 0
	adds r1, r3, 0
	str r2, [sp, 0x9C]
	str r3, [sp, 0xA0]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x9C]
	ldr r3, [sp, 0xA0]
	cmp r0, 0x2
	bne _0805098C
	adds r6, 0x1
_0805098C:
	adds r0, r7, 0
	adds r1, r2, 0
	str r2, [sp, 0x9C]
	str r3, [sp, 0xA0]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x9C]
	ldr r3, [sp, 0xA0]
	cmp r0, 0x2
	bne _080509A8
	adds r6, 0x1
_080509A8:
	subs r4, r7, 0x1
	adds r0, r4, 0
	adds r1, r3, 0
	str r2, [sp, 0x9C]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x9C]
	cmp r0, 0x2
	bne _080509C2
	adds r6, 0x1
_080509C2:
	adds r0, r4, 0
	adds r1, r5, 0
	str r2, [sp, 0x9C]
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	ldr r2, [sp, 0x9C]
	cmp r0, 0x2
	bne _080509DA
	adds r6, 0x1
_080509DA:
	adds r0, r4, 0
	adds r1, r2, 0
	bl GetMapTile_1
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	cmp r0, 0x2
	bne _080509EE
	adds r6, 0x1
_080509EE:
	cmp r6, 0x3
	ble _08050A1A
	cmp r7, 0
	blt _08050A04
	cmp r5, 0
	blt _08050A04
	cmp r7, 0x37
	bgt _08050A04
	ldr r0, [sp, 0x88]
	cmp r0, 0x1F
	ble _08050A08
_08050A04:
	movs r0, 0x1
	b _08050A0A
_08050A08:
	movs r0, 0
_08050A0A:
	cmp r0, 0
	bne _08050A1A
	ldr r0, [sp, 0x90]
	ldr r1, [sp, 0x94]
	bl GetMapTile_2
	bl sub_80506BC
_08050A1A:
	adds r5, 0x1
	ldr r1, [sp, 0x80]
	adds r1, 0x1
	str r1, [sp, 0x80]
	cmp r1, 0x3
	bgt _08050A28
	b _08050900
_08050A28:
	ldr r0, [sp, 0x8C]
	cmp r0, 0x3
	bgt _08050A30
	b _080508EA
_08050A30:
	ldr r2, [sp, 0x68]
	cmp r2, 0
	beq _08050A38
	b _08050772
_08050A38:
	ldr r0, [sp, 0x6C]
	cmp r0, 0
	beq _08050A54
	movs r1, 0x1
	str r1, [sp, 0x70]
	ldr r2, [sp, 0x74]
	cmp r2, 0
	beq _08050A4E
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x70]
_08050A4E:
	movs r1, 0
	str r1, [sp, 0x6C]
	b _08050A6C
_08050A54:
	movs r0, 0x64
	bl DungeonRandomCapped
	movs r2, 0x1
	str r2, [sp, 0x6C]
	cmp r0, 0x31
	bgt _08050A68
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x6C]
_08050A68:
	movs r1, 0
	str r1, [sp, 0x70]
_08050A6C:
	mov r2, r10
	cmp r2, 0x1F
	bhi _08050A74
	b _08050762
_08050A74:
	ldr r4, [sp, 0x98]
	cmp r4, 0
	beq _08050A7C
	b _0805071C
_08050A7C:
	movs r0, 0
	ldr r1, [sp, 0x64]
	ldrb r1, [r1, 0x15]
	cmp r0, r1
	blt _08050A88
	b _08050BAE
_08050A88:
	movs r2, 0
	mov r8, r2
	mov r9, r2
	movs r5, 0
	adds r0, 0x1
	mov r10, r0
	b _08050A98
_08050A96:
	adds r5, 0x1
_08050A98:
	cmp r5, 0xC7
	bgt _08050AC2
	movs r0, 0
	movs r1, 0x38
	bl DungeonRandomRange
	mov r9, r0
	movs r0, 0
	movs r1, 0x20
	bl DungeonRandomRange
	mov r8, r0
	mov r0, r9
	subs r0, 0x1
	cmp r0, 0x35
	bhi _08050A96
	mov r0, r8
	cmp r0, 0
	ble _08050A96
	cmp r0, 0x1E
	bgt _08050A96
_08050AC2:
	cmp r5, 0xC8
	beq _08050BA2
	movs r7, 0
	movs r3, 0x1
	movs r1, 0
_08050ACC:
	movs r2, 0
	lsls r0, r7, 2
	adds r4, r7, 0x1
	adds r0, r7
	lsls r0, 1
	add r0, sp
_08050AD8:
	cmp r7, 0
	beq _08050AE8
	cmp r7, 0x9
	beq _08050AE8
	cmp r2, 0
	beq _08050AE8
	cmp r2, 0x9
	bne _08050AEC
_08050AE8:
	strb r3, [r0]
	b _08050AEE
_08050AEC:
	strb r1, [r0]
_08050AEE:
	adds r0, 0x1
	adds r2, 0x1
	cmp r2, 0x9
	ble _08050AD8
	adds r7, r4, 0
	cmp r7, 0x9
	ble _08050ACC
	movs r5, 0x4F
_08050AFE:
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	adds r7, r4, 0x1
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r2, r0, 0x1
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 1
	adds r0, r2, r0
	add r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _08050B50
	adds r1, r7, 0x1
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r2, r0
	add r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _08050B50
	lsls r0, r7, 2
	adds r0, r7
	lsls r1, r0, 1
	subs r0, r1, 0x1
	adds r0, r2, r0
	add r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	bne _08050B50
	adds r0, r1, 0x1
	adds r0, r2, r0
	add r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _08050B60
_08050B50:
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 1
	adds r0, r2, r0
	mov r2, sp
	adds r1, r2, r0
	movs r0, 0x1
	strb r0, [r1]
_08050B60:
	subs r5, 0x1
	cmp r5, 0
	bge _08050AFE
	movs r7, 0
_08050B68:
	lsls r0, r7, 2
	adds r4, r7, 0x1
	adds r0, r7
	lsls r0, 1
	mov r6, r8
	subs r6, 0x5
	mov r1, sp
	adds r5, r0, r1
	add r7, r9
	movs r2, 0x9
_08050B7C:
	ldrb r0, [r5]
	cmp r0, 0
	bne _08050B92
	subs r0, r7, 0x5
	adds r1, r6, 0
	str r2, [sp, 0x9C]
	bl GetMapTile_2
	bl sub_80506BC
	ldr r2, [sp, 0x9C]
_08050B92:
	adds r6, 0x1
	adds r5, 0x1
	subs r2, 0x1
	cmp r2, 0
	bge _08050B7C
	adds r7, r4, 0
	cmp r7, 0x9
	ble _08050B68
_08050BA2:
	mov r0, r10
	ldr r2, [sp, 0x64]
	ldrb r2, [r2, 0x15]
	cmp r0, r2
	bge _08050BAE
	b _08050A88
_08050BAE:
	movs r0, 0
	mov r9, r0
	movs r6, 0x1
	ldr r1, _08050BF4
	adds r5, r1, 0
_08050BB8:
	movs r2, 0
	mov r10, r2
	mov r4, r9
	adds r4, 0x1
_08050BC0:
	mov r0, r9
	mov r1, r10
	bl GetMapTile_2
	adds r2, r0, 0
	ldrh r3, [r2]
	movs r0, 0x3
	ands r0, r3
	cmp r0, 0x2
	bne _08050C10
	movs r1, 0xB0
	lsls r1, 1
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	bne _08050BEA
	ldrh r1, [r2, 0x4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08050BF8
_08050BEA:
	adds r0, r3, 0
	ands r0, r5
	orrs r0, r6
	b _08050C0E
	.align 2, 0
_08050BF4: .4byte 0x0000fffc
_08050BF8:
	mov r0, r9
	subs r0, 0x2
	cmp r0, 0x34
	bhi _08050C0A
	mov r0, r10
	cmp r0, 0x1
	ble _08050C0A
	cmp r0, 0x1E
	ble _08050C10
_08050C0A:
	ldrh r0, [r2]
	ands r0, r5
_08050C0E:
	strh r0, [r2]
_08050C10:
	movs r1, 0x1
	add r10, r1
	mov r2, r10
	cmp r2, 0x1F
	ble _08050BC0
	mov r9, r4
	cmp r4, 0x37
	ble _08050BB8
_08050C20:
	add sp, 0xA4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80506F0

	thumb_func_start sub_8050C30
sub_8050C30:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08050F3C
	add sp, r4
	mov r8, r0
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0xE0
	lsls r0, 3
	add r0, sp
	str r2, [r0]
	movs r7, 0
	mov r1, r8
	lsls r1, 5
	movs r2, 0xE2
	lsls r2, 3
	add r2, sp
	str r1, [r2]
_08050C5C:
	movs r6, 0
	lsls r2, r7, 5
	adds r3, r7, 0x1
	mov r10, r3
	mov r5, sp
	adds r4, r2, r5
_08050C68:
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrh r0, [r2]
	movs r3, 0x3
	ands r3, r0
	movs r0, 0
	strb r0, [r4]
	movs r0, 0xE0
	lsls r0, 3
	add r0, sp
	ldr r0, [r0]
	cmp r0, 0
	beq _08050C92
	ldrh r0, [r2]
	ldr r5, _08050F40
	adds r1, r5, 0
	ands r0, r1
	strh r0, [r2]
_08050C92:
	cmp r3, 0x1
	beq _08050CA8
	ldrh r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08050CA8
	ldrb r0, [r4]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4]
_08050CA8:
	cmp r3, 0x2
	bne _08050CBE
	ldrh r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08050CBE
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
_08050CBE:
	adds r4, 0x1
	adds r6, 0x1
	cmp r6, 0x1F
	ble _08050C68
	mov r7, r10
	cmp r7, 0x37
	ble _08050C5C
	movs r1, 0xE2
	lsls r1, 3
	add r1, sp
	ldr r0, [r1]
	add r0, r9
	mov r3, sp
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x50
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08050F44
	ldr r1, [r0]
	ldr r5, _08050F48
	adds r0, r1, r5
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, r8
	beq _08050CF4
	b _08050F36
_08050CF4:
	ldr r3, _08050F4C
	adds r0, r1, r3
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, r9
	beq _08050D02
	b _08050F36
_08050D02:
	ldr r1, _08050F50
	movs r0, 0
	str r0, [r1]
	movs r0, 0x40
	mov r9, r0
_08050D0C:
	movs r1, 0
	ldr r2, _08050F54
	add r2, sp
	str r1, [r2]
	ldr r3, _08050F50
	ldr r0, [r3]
	adds r0, 0x1
	str r0, [r3]
	movs r7, 0
_08050D1E:
	movs r6, 0
	lsls r2, r7, 5
	adds r5, r7, 0x1
	mov r10, r5
	subs r0, r7, 0x1
	movs r1, 0xE1
	lsls r1, 3
	add r1, sp
	str r0, [r1]
	lsls r0, 5
	mov r1, sp
	subs r1, 0x1
	adds r5, r2, r1
	add r0, sp
	mov r8, r0
	mov r2, r10
	ldr r3, _08050F58
	add r3, sp
	str r2, [r3]
	lsls r0, r2, 5
	add r0, sp
	mov r12, r0
_08050D4A:
	ldrb r1, [r5, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08050D56
	b _08050EDA
_08050D56:
	movs r3, 0x40
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _08050D62
	b _08050EDA
_08050D62:
	ldr r2, _08050F54
	add r2, sp
	ldr r0, [r2]
	adds r0, 0x1
	str r0, [r2]
	movs r0, 0xBF
	ands r0, r1
	movs r2, 0
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r5, 0x1]
	cmp r7, 0
	ble _08050D90
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x83
	ands r0, r1
	cmp r0, 0
	bne _08050D90
	adds r0, r1, 0
	orrs r0, r3
	mov r1, r8
	strb r0, [r1]
_08050D90:
	cmp r6, 0
	ble _08050DA4
	ldrb r1, [r5]
	movs r0, 0x83
	ands r0, r1
	cmp r0, 0
	bne _08050DA4
	mov r0, r9
	orrs r0, r1
	strb r0, [r5]
_08050DA4:
	cmp r7, 0x36
	bgt _08050DBA
	mov r2, r12
	ldrb r1, [r2]
	movs r0, 0x83
	ands r0, r1
	cmp r0, 0
	bne _08050DBA
	mov r0, r9
	orrs r0, r1
	strb r0, [r2]
_08050DBA:
	cmp r6, 0x1E
	bgt _08050DCE
	ldrb r1, [r5, 0x2]
	movs r0, 0x83
	ands r0, r1
	cmp r0, 0
	bne _08050DCE
	mov r0, r9
	orrs r0, r1
	strb r0, [r5, 0x2]
_08050DCE:
	cmp r7, 0
	ble _08050E12
	cmp r6, 0
	ble _08050E12
	movs r3, 0xE1
	lsls r3, 3
	add r3, sp
	ldr r3, [r3]
	lsls r1, r3, 5
	subs r0, r1, 0x1
	adds r0, r6, r0
	mov r2, sp
	adds r4, r2, r0
	ldrb r3, [r4]
	movs r0, 0x87
	ands r0, r3
	cmp r0, 0
	bne _08050E12
	adds r0, r6, r1
	add r0, sp
	ldrb r1, [r0]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050E12
	ldrb r1, [r5]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050E12
	mov r0, r9
	orrs r0, r3
	strb r0, [r4]
_08050E12:
	cmp r7, 0x36
	bgt _08050E54
	cmp r6, 0
	ble _08050E54
	ldr r3, _08050F58
	add r3, sp
	ldr r3, [r3]
	lsls r1, r3, 5
	subs r0, r1, 0x1
	adds r0, r6, r0
	mov r2, sp
	adds r4, r2, r0
	ldrb r3, [r4]
	movs r0, 0x87
	ands r0, r3
	cmp r0, 0
	bne _08050E54
	adds r0, r6, r1
	add r0, sp
	ldrb r1, [r0]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050E54
	ldrb r1, [r5]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050E54
	mov r0, r9
	orrs r0, r3
	strb r0, [r4]
_08050E54:
	cmp r7, 0
	ble _08050E98
	cmp r6, 0x1E
	bgt _08050E98
	movs r3, 0xE1
	lsls r3, 3
	add r3, sp
	ldr r3, [r3]
	lsls r1, r3, 5
	adds r0, r1, 0x1
	adds r0, r6, r0
	mov r2, sp
	adds r4, r2, r0
	ldrb r3, [r4]
	movs r0, 0x87
	ands r0, r3
	cmp r0, 0
	bne _08050E98
	adds r0, r6, r1
	add r0, sp
	ldrb r1, [r0]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050E98
	ldrb r1, [r5, 0x2]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050E98
	mov r0, r9
	orrs r0, r3
	strb r0, [r4]
_08050E98:
	cmp r7, 0x36
	bgt _08050EDA
	cmp r6, 0x1E
	bgt _08050EDA
	ldr r3, _08050F58
	add r3, sp
	ldr r3, [r3]
	lsls r1, r3, 5
	adds r0, r1, 0x1
	adds r0, r6, r0
	mov r2, sp
	adds r4, r2, r0
	ldrb r3, [r4]
	movs r0, 0x87
	ands r0, r3
	cmp r0, 0
	bne _08050EDA
	adds r0, r6, r1
	add r0, sp
	ldrb r1, [r0]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050EDA
	ldrb r1, [r5, 0x2]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050EDA
	mov r0, r9
	orrs r0, r3
	strb r0, [r4]
_08050EDA:
	adds r5, 0x1
	movs r3, 0x1
	add r8, r3
	add r12, r3
	adds r6, 0x1
	cmp r6, 0x1F
	bgt _08050EEA
	b _08050D4A
_08050EEA:
	mov r7, r10
	cmp r7, 0x37
	bgt _08050EF2
	b _08050D1E
_08050EF2:
	ldr r5, _08050F54
	add r5, sp
	ldr r5, [r5]
	cmp r5, 0
	beq _08050EFE
	b _08050D0C
_08050EFE:
	movs r7, 0
_08050F00:
	movs r6, 0
	lsls r2, r7, 5
	mov r0, sp
	adds r4, r2, r0
_08050F08:
	adds r0, r7, 0
	adds r1, r6, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrb r1, [r4]
	movs r0, 0x87
	ands r0, r1
	cmp r0, 0
	bne _08050F68
	movs r1, 0xE0
	lsls r1, 3
	add r1, sp
	ldr r1, [r1]
	cmp r1, 0
	bne _08050F5C
	ldrh r0, [r2]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08050F68
_08050F36:
	movs r0, 0
	b _08050F78
	.align 2, 0
_08050F3C: .4byte 0xfffff8ec
_08050F40: .4byte 0x00007fff
_08050F44: .4byte gDungeonGlobalData
_08050F48: .4byte 0x0000e21c
_08050F4C: .4byte 0x0000e21e
_08050F50: .4byte gUnknown_202F1D4
_08050F54: .4byte 0x00000704
_08050F58: .4byte 0x0000070c
_08050F5C:
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r2]
_08050F68:
	adds r4, 0x1
	adds r6, 0x1
	cmp r6, 0x1F
	ble _08050F08
	adds r7, 0x1
	cmp r7, 0x37
	ble _08050F00
	movs r0, 0x1
_08050F78:
	ldr r3, _08050F8C
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08050F8C: .4byte 0x00000714
	thumb_func_end sub_8050C30

	thumb_func_start sub_8050F90
sub_8050F90:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	str r0, [sp]
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	movs r1, 0
	str r1, [sp, 0x14]
	movs r2, 0
	b _080511D0
_08050FB0:
	movs r4, 0
	str r4, [sp, 0x18]
	ldr r5, [sp, 0x1C]
	adds r5, 0x1
	str r5, [sp, 0x28]
	ldr r6, [sp, 0x4]
	cmp r4, r6
	blt _08050FC2
	b _080511CE
_08050FC2:
	ldr r1, [sp, 0x18]
	lsls r0, r1, 2
	ldr r2, [sp, 0xC]
	adds r0, r2
	ldr r3, [r0]
	adds r4, r3, 0x2
	mov r9, r4
	ldr r5, [sp, 0x1C]
	lsls r1, r5, 2
	ldr r6, [sp, 0x5C]
	adds r1, r6
	ldr r2, [r1]
	adds r4, r2, 0x2
	mov r10, r4
	ldr r0, [r0, 0x4]
	subs r0, r3
	subs r4, r0, 0x4
	ldr r0, [r1, 0x4]
	subs r0, r2
	subs r7, r0, 0x4
	movs r3, 0x5
	movs r5, 0x5
	ldr r6, [sp, 0x4]
	cmp r6, 0x2
	bgt _08050FF8
	movs r3, 0xA
	movs r4, 0xE
_08050FF8:
	ldr r0, [sp, 0x8]
	cmp r0, 0x1
	bne _08051002
	movs r5, 0x10
	movs r7, 0x18
_08051002:
	ldr r2, [sp, 0x1C]
	lsls r1, r2, 5
	ldr r6, [sp, 0x18]
	lsls r2, r6, 4
	subs r0, r2, r6
	lsls r0, 5
	ldr r6, [sp]
	adds r0, r6
	adds r6, r1, r0
	ldrb r0, [r6, 0xA]
	str r1, [sp, 0x30]
	str r2, [sp, 0x2C]
	cmp r0, 0
	bne _08051020
	b _08051130
_08051020:
	ldr r0, [sp, 0x14]
	ldr r1, [sp, 0x60]
	cmp r0, r1
	beq _0805108C
	adds r0, r3, 0
	adds r1, r4, 0
	bl DungeonRandomRange
	adds r6, r0, 0
	adds r0, r5, 0
	adds r1, r7, 0
	bl DungeonRandomRange
	adds r5, r0, 0
	movs r1, 0x1
	adds r0, r6, 0
	orrs r0, r1
	cmp r0, r4
	bge _08051048
	adds r6, r0, 0
_08051048:
	adds r0, r5, 0
	orrs r0, r1
	cmp r0, r7
	bge _08051052
	adds r5, r0, 0
_08051052:
	lsls r0, r5, 1
	adds r0, r5
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r6, r0
	ble _08051062
	adds r6, r0, 0
_08051062:
	lsls r0, r6, 1
	adds r0, r6
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	cmp r5, r0
	ble _08051072
	adds r5, r0, 0
_08051072:
	subs r0, r4, r6
	bl DungeonRandomCapped
	mov r2, r9
	adds r4, r0, r2
	subs r0, r7, r5
	bl DungeonRandomCapped
	mov r3, r10
	adds r7, r0, r3
	adds r3, r4, r6
	adds r6, r7, r5
	b _08051098
_0805108C:
	mov r4, r9
	mov r7, r10
	ldr r5, [sp, 0x64]
	adds r3, r4, r5
	ldr r0, [sp, 0x68]
	adds r6, r7, r0
_08051098:
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x18]
	subs r0, r1, r2
	lsls r0, 5
	ldr r5, [sp]
	adds r0, r5
	ldr r1, [sp, 0x30]
	adds r0, r1, r0
	strh r4, [r0]
	strh r3, [r0, 0x4]
	strh r7, [r0, 0x2]
	strh r6, [r0, 0x6]
	adds r5, r4, 0
	ldr r2, [sp, 0x10]
	adds r2, 0x1
	str r2, [sp, 0x20]
	ldr r4, [sp, 0x14]
	adds r4, 0x1
	str r4, [sp, 0x24]
	ldr r0, [sp, 0x18]
	adds r0, 0x1
	mov r10, r0
	cmp r5, r3
	bge _08051108
_080510C8:
	adds r4, r7, 0
	adds r1, r5, 0x1
	mov r8, r1
	cmp r4, r6
	bge _08051102
	ldr r2, _0805112C
	mov r9, r2
_080510D6:
	adds r0, r5, 0
	adds r1, r4, 0
	str r3, [sp, 0x38]
	bl GetMapTile_2
	ldrh r1, [r0]
	mov r2, r9
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	mov r1, sp
	ldrb r1, [r1, 0x10]
	strb r1, [r0, 0x9]
	adds r4, 0x1
	ldr r3, [sp, 0x38]
	cmp r4, r6
	blt _080510D6
_08051102:
	mov r5, r8
	cmp r5, r3
	blt _080510C8
_08051108:
	ldr r2, [sp, 0x14]
	ldr r3, [sp, 0x60]
	cmp r2, r3
	beq _08051124
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x18]
	subs r0, r4, r5
	lsls r0, 5
	ldr r6, [sp]
	adds r0, r6
	ldr r1, [sp, 0x30]
	adds r0, r1, r0
	movs r1, 0x1
	strb r1, [r0, 0x1D]
_08051124:
	ldr r2, [sp, 0x20]
	str r2, [sp, 0x10]
	b _080511BE
	.align 2, 0
_0805112C: .4byte 0x0000fffc
_08051130:
	movs r1, 0x2
	movs r3, 0x4
	movs r2, 0x2
	mov r8, r3
	ldr r5, [sp, 0x18]
	cmp r5, 0
	bne _08051140
	movs r1, 0x1
_08051140:
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	bne _08051148
	movs r2, 0x1
_08051148:
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	ldr r5, [sp, 0x18]
	cmp r5, r0
	bne _08051154
	movs r3, 0x2
_08051154:
	ldr r0, [sp, 0x8]
	subs r0, 0x1
	ldr r5, [sp, 0x1C]
	cmp r5, r0
	bne _08051162
	movs r0, 0x2
	mov r8, r0
_08051162:
	mov r5, r9
	adds r0, r5, r1
	adds r1, r5, r4
	subs r1, r3
	str r2, [sp, 0x34]
	bl DungeonRandomRange
	adds r5, r0, 0
	ldr r2, [sp, 0x34]
	mov r1, r10
	adds r0, r1, r2
	adds r1, r7
	mov r2, r8
	subs r1, r2
	bl DungeonRandomRange
	adds r4, r0, 0
	strh r5, [r6]
	adds r0, r5, 0x1
	strh r0, [r6, 0x4]
	strh r4, [r6, 0x2]
	adds r0, r4, 0x1
	strh r0, [r6, 0x6]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r3, _080511EC
	adds r2, r3, 0
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMapTile_2
	movs r1, 0xFF
	strb r1, [r0, 0x9]
	ldr r4, [sp, 0x14]
	adds r4, 0x1
	str r4, [sp, 0x24]
	ldr r5, [sp, 0x18]
	adds r5, 0x1
	mov r10, r5
_080511BE:
	ldr r6, [sp, 0x24]
	str r6, [sp, 0x14]
	mov r0, r10
	str r0, [sp, 0x18]
	ldr r1, [sp, 0x4]
	cmp r0, r1
	bge _080511CE
	b _08050FC2
_080511CE:
	ldr r2, [sp, 0x28]
_080511D0:
	str r2, [sp, 0x1C]
	ldr r3, [sp, 0x8]
	cmp r2, r3
	bge _080511DA
	b _08050FB0
_080511DA:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080511EC: .4byte 0x0000fffc
	thumb_func_end sub_8050F90

	thumb_func_start sub_80511F0
sub_80511F0:
	push {r4-r6,lr}
	ldr r6, _08051204
	ldrb r0, [r6]
	cmp r0, 0
	beq _0805120C
	subs r0, 0x1
	strb r0, [r6]
	ldr r0, _08051208
	ldrb r0, [r0]
	b _08051244
	.align 2, 0
_08051204: .4byte gUnknown_202F1E1
_08051208: .4byte gUnknown_202F1E0
_0805120C:
	ldr r1, _0805122C
	ldr r5, _08051230
	ldr r2, [r5]
	ldrb r3, [r2]
	strb r3, [r1]
	adds r4, r2, 0x1
	str r4, [r5]
	lsls r0, r3, 24
	lsrs r0, 24
	cmp r0, 0xE
	bne _08051234
	ldrb r0, [r2, 0x1]
	strb r0, [r1]
	adds r0, r4, 0x1
	str r0, [r5]
	b _08051242
	.align 2, 0
_0805122C: .4byte gUnknown_202F1E0
_08051230: .4byte gUnknown_202F1DC
_08051234:
	movs r0, 0xF
	ands r0, r3
	strb r0, [r6]
	movs r0, 0xF0
	ands r0, r3
	lsrs r0, 4
	strb r0, [r1]
_08051242:
	ldrb r0, [r1]
_08051244:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80511F0

	thumb_func_start sub_805124C
sub_805124C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r5, [sp, 0x1C]
	lsls r1, 24
	lsrs r1, 24
	lsls r5, 24
	lsrs r5, 24
	ldrh r6, [r0]
	movs r7, 0x80
	lsls r7, 1
	adds r4, r7, 0
	movs r7, 0
	mov r8, r7
	orrs r4, r6
	strh r4, [r0]
	mov r4, r8
	strb r4, [r0, 0xE]
	str r5, [sp]
	bl sub_8051A74
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805124C

	thumb_func_start sub_8051288
sub_8051288:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp, 0x4]
	ldr r0, _08051374
	ldr r7, [r0]
	ldr r0, _08051378
	adds r3, r7, r0
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	ldr r2, [sp, 0x4]
	lsls r1, r2, 2
	adds r0, r1, r0
	ldr r0, [r0]
	ldrb r2, [r0]
	mov r10, r2
	ldrb r0, [r0, 0x1]
	mov r9, r0
	ldr r2, _0805137C
	adds r0, r7, r2
	movs r4, 0
	mov r2, r10
	strh r2, [r0]
	ldr r2, _08051380
	adds r0, r7, r2
	mov r2, r9
	strh r2, [r0]
	ldr r2, _08051384
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x3
	str r0, [r2]
	ldr r0, _08051388
	strb r4, [r0]
	movs r6, 0x5
	mov r0, r9
	adds r0, 0x5
	cmp r6, r0
	bge _0805132E
	movs r1, 0x5
	add r1, r10
	mov r8, r1
	str r0, [sp, 0x8]
_080512E8:
	movs r5, 0x5
	cmp r5, r8
	bge _08051326
_080512EE:
	bl sub_80511F0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMapTile_2
	movs r1, 0x1
	str r1, [sp]
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_805124C
	lsls r0, 24
	cmp r0, 0
	beq _08051320
	ldr r2, _0805138C
	adds r0, r7, r2
	strh r5, [r0]
	ldr r1, _08051390
	adds r0, r7, r1
	strh r6, [r0]
_08051320:
	adds r5, 0x1
	cmp r5, r8
	blt _080512EE
_08051326:
	adds r6, 0x1
	ldr r2, [sp, 0x8]
	cmp r6, r2
	blt _080512E8
_0805132E:
	movs r6, 0
	ldr r0, _08051394
	adds r7, r0, 0
_08051334:
	movs r5, 0
	adds r4, r6, 0x1
_08051338:
	cmp r5, 0x4
	ble _08051350
	mov r0, r10
	adds r0, 0x5
	cmp r5, r0
	bge _08051350
	cmp r6, 0x4
	ble _08051350
	mov r0, r9
	adds r0, 0x5
	cmp r6, r0
	blt _080513A0
_08051350:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x10
	movs r3, 0
	orrs r1, r0
	strh r1, [r2]
	ldr r0, _08051398
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805139C
	ands r1, r7
	movs r0, 0x3
	orrs r1, r0
	b _0805139E
	.align 2, 0
_08051374: .4byte gDungeonGlobalData
_08051378: .4byte 0x00013568
_0805137C: .4byte 0x0000e260
_08051380: .4byte 0x0000e262
_08051384: .4byte gUnknown_202F1DC
_08051388: .4byte gUnknown_202F1E1
_0805138C: .4byte 0x0000e21c
_08051390: .4byte 0x0000e21e
_08051394: .4byte 0x0000fffc
_08051398: .4byte gUnknown_202F1A8
_0805139C:
	ands r1, r7
_0805139E:
	strh r1, [r2]
_080513A0:
	adds r5, 0x1
	cmp r5, 0x37
	ble _08051338
	adds r6, r4, 0
	cmp r6, 0x1F
	ble _08051334
	ldr r1, [sp, 0x4]
	cmp r1, 0x4
	bne _080513DA
	movs r6, 0x5
	ldr r2, _0805142C
	adds r7, r2, 0
_080513B8:
	movs r5, 0x2
	adds r4, r6, 0x1
_080513BC:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMapTile_2
	ldrh r2, [r0]
	movs r1, 0x10
	orrs r1, r2
	ands r1, r7
	strh r1, [r0]
	adds r5, 0x1
	cmp r5, 0x4
	ble _080513BC
	adds r6, r4, 0
	cmp r6, 0x10
	ble _080513B8
_080513DA:
	ldr r0, _08051430
	ldr r0, [r0]
	ldr r1, _08051434
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x3F
	ble _08051416
	movs r6, 0
_080513EC:
	movs r5, 0
	adds r4, r6, 0x1
_080513F0:
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0805140A
	movs r0, 0x10
	orrs r0, r1
	strh r0, [r2]
_0805140A:
	adds r5, 0x1
	cmp r5, 0x37
	ble _080513F0
	adds r6, r4, 0
	cmp r6, 0x1F
	ble _080513EC
_08051416:
	bl sub_804E9DC
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805142C: .4byte 0x0000fffc
_08051430: .4byte gDungeonGlobalData
_08051434: .4byte 0x00003a0e
	thumb_func_end sub_8051288

	thumb_func_start sub_8051438
sub_8051438:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r9, r0
	ldr r0, _080515AC
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldr r2, _080515B0
	ldr r4, _080515B4
	adds r3, r0, r4
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	lsls r1, 2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r0, 0x3
	str r0, [r2]
	ldr r2, _080515B8
	movs r0, 0
	strb r0, [r2]
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldr r0, [r1]
	ldrb r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805147A
	b _080515D8
_0805147A:
	ldr r5, [sp, 0x4]
	ldr r0, _080515BC
	adds r1, r5, r0
	mov r2, r9
	movs r3, 0
	ldrsh r0, [r2, r3]
	str r0, [r1]
	ldr r4, _080515C0
	adds r1, r5, r4
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	str r0, [r1]
	ldr r0, [sp, 0x4]
	ldr r2, _080515C4
	adds r1, r0, r2
	mov r3, r9
	movs r4, 0x4
	ldrsh r0, [r3, r4]
	str r0, [r1]
	ldr r5, [sp, 0x4]
	ldr r0, _080515C8
	adds r1, r5, r0
	movs r2, 0x6
	ldrsh r0, [r3, r2]
	str r0, [r1]
	movs r3, 0
	str r3, [sp, 0x8]
	mov r4, r9
	movs r5, 0x2
	ldrsh r4, [r4, r5]
	mov r8, r4
	mov r1, r9
	movs r2, 0x6
	ldrsh r0, [r1, r2]
	cmp r8, r0
	blt _080514C4
	b _08051640
_080514C4:
	mov r3, r9
	movs r4, 0
	ldrsh r7, [r3, r4]
	movs r5, 0x4
	ldrsh r0, [r3, r5]
	ldr r1, [sp, 0x8]
	adds r1, 0x1
	str r1, [sp, 0x10]
	mov r2, r8
	adds r2, 0x1
	str r2, [sp, 0xC]
	cmp r7, r0
	bge _08051598
	ldr r4, _080515CC
	ldr r3, [sp, 0x4]
	adds r4, r3, r4
	str r4, [sp, 0x14]
	movs r5, 0
	str r5, [sp, 0x18]
	ldr r0, [sp, 0x8]
	mov r10, r0
_080514EE:
	bl sub_80511F0
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r7, 0
	mov r1, r8
	bl GetMapTile_2
	adds r6, r0, 0
	ldr r1, [sp, 0x4]
	ldr r2, _080515D0
	adds r0, r1, r2
	add r0, r10
	strb r5, [r0]
	ldr r3, [sp, 0x8]
	lsls r4, r3, 1
	adds r4, r3
	lsls r4, 3
	ldr r1, [sp, 0x14]
	adds r0, r1, r4
	movs r2, 0
	str r2, [sp]
	adds r1, r5, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_805124C
	ldrb r1, [r6, 0x9]
	ldr r3, [sp, 0x18]
	adds r4, r3
	ldr r5, [sp, 0x4]
	adds r4, r5, r4
	adds r0, r6, 0
	ldr r2, _080515CC
	adds r4, r2
	ldm r4!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	ldm r4!, {r2,r3,r5}
	stm r0!, {r2,r3,r5}
	mov r3, r9
	movs r4, 0
	ldrsh r0, [r3, r4]
	adds r0, 0x2
	cmp r7, r0
	blt _08051572
	movs r5, 0x4
	ldrsh r0, [r3, r5]
	subs r0, 0x2
	cmp r7, r0
	bge _08051572
	movs r2, 0x2
	ldrsh r0, [r3, r2]
	adds r0, 0x2
	cmp r8, r0
	blt _08051572
	movs r4, 0x6
	ldrsh r0, [r3, r4]
	subs r0, 0x2
	cmp r8, r0
	bge _08051572
	movs r0, 0x88
	lsls r0, 1
	strh r0, [r6]
	movs r0, 0xE
	strb r0, [r6, 0xE]
_08051572:
	strb r1, [r6, 0x9]
	ldr r5, [sp, 0x4]
	ldr r2, _080515D4
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, [sp, 0x14]
	adds r3, 0xC0
	str r3, [sp, 0x14]
	ldr r4, [sp, 0x18]
	adds r4, 0xC0
	str r4, [sp, 0x18]
	movs r5, 0x8
	add r10, r5
	adds r7, 0x1
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	cmp r7, r0
	blt _080514EE
_08051598:
	ldr r3, [sp, 0x10]
	str r3, [sp, 0x8]
	ldr r4, [sp, 0xC]
	mov r8, r4
	mov r5, r9
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	cmp r8, r0
	blt _080514C4
	b _08051640
	.align 2, 0
_080515AC: .4byte gDungeonGlobalData
_080515B0: .4byte gUnknown_202F1DC
_080515B4: .4byte 0x00013568
_080515B8: .4byte gUnknown_202F1E1
_080515BC: .4byte 0x0000e250
_080515C0: .4byte 0x0000e254
_080515C4: .4byte 0x0000e258
_080515C8: .4byte 0x0000e25c
_080515CC: .4byte 0x0000e27c
_080515D0: .4byte 0x0000e87c
_080515D4: .4byte 0x0000e8bc
_080515D8:
	mov r2, r9
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	mov r8, r2
	b _08051636
_080515E2:
	mov r0, r9
	movs r1, 0
	ldrsh r7, [r0, r1]
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	mov r3, r8
	adds r3, 0x1
	str r3, [sp, 0xC]
	cmp r7, r0
	bge _08051632
_080515F6:
	bl sub_80511F0
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	mov r1, r8
	bl GetMapTile_2
	adds r5, r0, 0
	ldrb r6, [r5, 0x9]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	mov r3, r8
	bl sub_805124C
	strb r6, [r5, 0x9]
	ldr r4, [sp, 0x4]
	ldr r5, _08051650
	adds r0, r4, r5
	strb r6, [r0]
	adds r7, 0x1
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	cmp r7, r0
	blt _080515F6
_08051632:
	ldr r3, [sp, 0xC]
	mov r8, r3
_08051636:
	mov r4, r9
	movs r5, 0x6
	ldrsh r0, [r4, r5]
	cmp r8, r0
	blt _080515E2
_08051640:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051650: .4byte 0x0000e8bc
	thumb_func_end sub_8051438

	thumb_func_start sub_8051654
sub_8051654:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp]
	ldr r4, _080516EC
	ldr r1, [r4, 0x8]
	ldr r0, [r4]
	subs r1, r0
	subs r1, 0x2
	movs r0, 0x3
	bl DungeonRandomRange
	mov r8, r0
	cmp r0, 0x2
	bgt _0805167C
	movs r0, 0x3
	mov r8, r0
_0805167C:
	ldr r1, [r4, 0xC]
	ldr r0, [r4, 0x4]
	subs r1, r0
	subs r1, 0x2
	movs r0, 0x3
	bl DungeonRandomRange
	mov r9, r0
	cmp r0, 0x2
	bgt _08051694
	movs r1, 0x3
	mov r9, r1
_08051694:
	movs r0, 0x2
	movs r1, 0x4
	bl DungeonRandomRange
	mov r10, r0
	movs r5, 0
	cmp r5, r10
	bge _08051734
	ldr r0, [r4, 0x8]
	ldr r1, [r4]
	subs r0, r1
	cmp r0, r8
	ble _08051734
	adds r6, r4, 0
_080516B0:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, 0x31
	bgt _080516F4
	ldr r4, [r6, 0x4]
	ldr r0, [r6, 0xC]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _080516E4
	ldr r5, _080516EC
	ldr r0, _080516F0
	adds r2, r0, 0
_080516CA:
	ldr r0, [r5]
	adds r1, r4, 0
	str r2, [sp, 0xC]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0xC]
	cmp r4, r0
	blt _080516CA
_080516E4:
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
	b _08051724
	.align 2, 0
_080516EC: .4byte gUnknown_202F1B8
_080516F0: .4byte 0x0000ffdf
_080516F4:
	ldr r0, [r6, 0x8]
	subs r0, 0x1
	str r0, [r6, 0x8]
	ldr r4, [r6, 0x4]
	ldr r0, [r6, 0xC]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _08051724
	ldr r5, _08051784
	ldr r1, _08051788
	adds r2, r1, 0
_0805170A:
	ldr r0, [r5, 0x8]
	adds r1, r4, 0
	str r2, [sp, 0xC]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0xC]
	cmp r4, r0
	blt _0805170A
_08051724:
	adds r5, r7, 0
	cmp r5, r10
	bge _08051734
	ldr r0, [r6, 0x8]
	ldr r1, [r6]
	subs r0, r1
	cmp r0, r8
	bgt _080516B0
_08051734:
	movs r5, 0
	ldr r3, _08051784
	cmp r5, r10
	bge _080517CE
	ldr r0, [r3, 0xC]
	ldr r1, [r3, 0x4]
	subs r0, r1
	cmp r0, r9
	ble _080517CE
	adds r6, r3, 0
_08051748:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, 0x31
	bgt _0805178C
	ldr r4, [r6]
	ldr r0, [r6, 0x8]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _0805177C
	ldr r5, _08051784
	ldr r0, _08051788
	adds r2, r0, 0
_08051762:
	ldr r1, [r5, 0x4]
	adds r0, r4, 0
	str r2, [sp, 0xC]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0x8]
	cmp r4, r0
	blt _08051762
_0805177C:
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	b _080517BC
	.align 2, 0
_08051784: .4byte gUnknown_202F1B8
_08051788: .4byte 0x0000ffdf
_0805178C:
	ldr r0, [r6, 0xC]
	subs r0, 0x1
	str r0, [r6, 0xC]
	ldr r4, [r6]
	ldr r0, [r6, 0x8]
	adds r7, r5, 0x1
	cmp r4, r0
	bge _080517BC
	ldr r5, _080518E4
	ldr r1, _080518E8
	adds r2, r1, 0
_080517A2:
	ldr r1, [r5, 0xC]
	adds r0, r4, 0
	str r2, [sp, 0xC]
	bl GetMapTile_2
	ldrh r1, [r0]
	ldr r2, [sp, 0xC]
	ands r1, r2
	strh r1, [r0]
	adds r4, 0x1
	ldr r0, [r5, 0x8]
	cmp r4, r0
	blt _080517A2
_080517BC:
	adds r5, r7, 0
	ldr r3, _080518E4
	cmp r5, r10
	bge _080517CE
	ldr r1, [r6, 0xC]
	ldr r0, [r6, 0x4]
	subs r1, r0
	cmp r1, r9
	bgt _08051748
_080517CE:
	ldr r7, [r3]
	ldr r0, [r3, 0x8]
	cmp r7, r0
	bge _08051824
	adds r4, r3, 0
	mov r9, r3
_080517DA:
	ldr r5, [r4, 0x4]
	ldr r0, [r4, 0xC]
	adds r1, r7, 0x1
	mov r8, r1
	cmp r5, r0
	bge _0805181A
	ldr r3, _080518E4
	ldr r0, _080518E8
	adds r6, r0, 0
_080517EC:
	adds r0, r7, 0
	adds r1, r5, 0
	str r3, [sp, 0x10]
	bl GetMapTile_2
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x20
	ands r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	beq _08051812
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08051812
	adds r0, r1, 0
	ands r0, r6
	strh r0, [r2]
_08051812:
	adds r5, 0x1
	ldr r0, [r4, 0xC]
	cmp r5, r0
	blt _080517EC
_0805181A:
	mov r7, r8
	mov r1, r9
	ldr r0, [r1, 0x8]
	cmp r7, r0
	blt _080517DA
_08051824:
	ldr r0, [r3]
	ldr r1, [r3, 0x8]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r2, r0, 1
	ldr r0, [r3, 0x4]
	ldr r1, [r3, 0xC]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	subs r0, 0x1
	mov r10, r0
	movs r0, 0
	mov r9, r0
	subs r7, r2, 0x1
	adds r0, r2, 0x2
	cmp r7, r0
	bge _080518D2
	adds r2, r0, 0
	str r2, [sp, 0x4]
_08051850:
	mov r5, r10
	adds r0, r5, 0x3
	adds r1, r7, 0x1
	mov r8, r1
	mov r1, r9
	adds r1, 0x1
	str r1, [sp, 0x8]
	cmp r5, r0
	bge _080518C6
	movs r3, 0
_08051864:
	adds r0, r7, 0
	adds r1, r5, 0
	str r3, [sp, 0x10]
	bl GetMapTile_2
	adds r6, r0, 0
	ldrh r1, [r6]
	movs r0, 0x20
	ands r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	beq _080518BA
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080518BA
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080518BA
	mov r0, r9
	lsls r2, r0, 1
	adds r2, r3
	ldr r0, [sp]
	ldrb r1, [r0, 0x18]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 1
	adds r2, r0
	ldr r1, _080518EC
	adds r2, r1
	movs r0, 0
	ldrsh r4, [r2, r0]
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r3, [sp, 0x10]
	cmp r4, r0
	ble _080518BA
	ldrh r1, [r6, 0x4]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r6, 0x4]
_080518BA:
	adds r5, 0x1
	adds r3, 0x6
	mov r0, r10
	adds r0, 0x3
	cmp r5, r0
	blt _08051864
_080518C6:
	mov r7, r8
	ldr r1, [sp, 0x8]
	mov r9, r1
	ldr r0, [sp, 0x4]
	cmp r7, r0
	blt _08051850
_080518D2:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080518E4: .4byte gUnknown_202F1B8
_080518E8: .4byte 0x0000ffdf
_080518EC: .4byte gUnknown_80F57D4
	thumb_func_end sub_8051654

	thumb_func_start sub_80518F0
sub_80518F0:
	push {r4-r7,lr}
	movs r5, 0
	movs r6, 0x10
	movs r7, 0
_080518F8:
	adds r0, r5, 0
	movs r1, 0x1
	bl GetMapTile_2
	adds r4, r0, 0
	bl sub_804FD10
	cmp r5, 0
	beq _0805190E
	cmp r5, 0x37
	bne _08051914
_0805190E:
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_08051914:
	adds r0, r5, 0
	movs r1, 0x1E
	bl GetMapTile_2
	adds r4, r0, 0
	bl sub_804FD10
	cmp r5, 0
	beq _0805192A
	cmp r5, 0x37
	bne _08051930
_0805192A:
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_08051930:
	adds r5, 0x1
	cmp r5, 0x37
	ble _080518F8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80518F0

	thumb_func_start sub_805193C
sub_805193C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r3, 0
	ldr r4, [sp, 0x18]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsls r2, 16
	lsrs r1, 16
	orrs r1, r2
	str r1, [sp, 0x4]
	adds r0, r5, 0
	bl sub_805210C
	lsls r0, 24
	cmp r0, 0
	beq _0805196A
	mov r0, sp
	movs r1, 0x76
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
	b _08051974
_0805196A:
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
_08051974:
	mov r0, sp
	ldrb r0, [r0]
	orrs r4, r0
	mov r0, sp
	strb r4, [r0]
	cmp r6, 0
	beq _08051984
	strb r6, [r0, 0x1]
_08051984:
	add r0, sp, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_80460F8
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_805193C

	thumb_func_start sub_8051998
sub_8051998:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	mov r8, r1
	mov r9, r2
	lsls r0, 16
	asrs r0, 16
	adds r1, r0, 0
	lsls r3, 24
	lsrs r6, r3, 24
	adds r7, r6, 0
	ldr r0, _080519E4
	cmp r1, r0
	bne _080519E8
	mov r1, sp
	movs r5, 0
	movs r4, 0
	movs r0, 0x3C
	strh r0, [r1]
	bl sub_803DA20
	mov r1, sp
	strh r0, [r1, 0x8]
	mov r0, sp
	strb r6, [r0, 0x2]
	str r4, [sp, 0x4]
	strb r5, [r0, 0x10]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	movs r1, 0x1
	bl sub_806B7F8
	b _08051A14
	.align 2, 0
_080519E4: .4byte 0x000001a5
_080519E8:
	cmp r1, 0
	beq _08051A14
	mov r0, sp
	movs r5, 0
	movs r4, 0
	strh r1, [r0]
	adds r0, r1, 0
	bl sub_803DA20
	mov r1, sp
	strh r0, [r1, 0x8]
	mov r0, sp
	strb r7, [r0, 0x2]
	str r4, [sp, 0x4]
	strb r5, [r0, 0x10]
	mov r1, r8
	strh r1, [r0, 0xC]
	mov r1, r9
	strh r1, [r0, 0xE]
	movs r1, 0x1
	bl sub_806B7F8
_08051A14:
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8051998

	thumb_func_start sub_8051A24
sub_8051A24:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	adds r7, r0, 0
	lsls r4, 16
	lsls r5, 16
	lsrs r4, 16
	orrs r4, r5
	str r4, [sp]
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0
	bl sub_8045684
	cmp r0, 0
	beq _08051A66
	str r0, [r7, 0x14]
	adds r0, 0x20
	mov r1, r8
	strb r1, [r0]
_08051A66:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8051A24

	thumb_func_start sub_8051A74
sub_8051A74:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r2, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x20]
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r1, 0xF
	bls _08051AA2
	ldrh r0, [r4]
	ldr r1, _08051AB4
	ands r1, r0
	movs r0, 0x1
	orrs r1, r0
	strh r1, [r4]
_08051AA2:
	mov r0, r8
	cmp r0, 0x45
	bls _08051AAA
	b _08051D68
_08051AAA:
	lsls r0, 2
	ldr r1, _08051AB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08051AB4: .4byte 0x0000fffc
_08051AB8: .4byte _08051ABC
	.align 2, 0
_08051ABC:
	.4byte _08051BF0
	.4byte _08051C0C
	.4byte _08051D50
	.4byte _08051E1A
	.4byte _08051C20
	.4byte _08051C54
	.4byte _08051C64
	.4byte _08051C74
	.4byte _08051C94
	.4byte _08051D00
	.4byte _08051C7E
	.4byte _08051D10
	.4byte _08051D24
	.4byte _08051D50
	.4byte _08051D50
	.4byte _08051E1A
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051D68
	.4byte _08051C94
	.4byte _08051CD4
	.4byte _08051BD4
_08051BD4:
	ldr r0, _08051BFC
	ldr r0, [r0]
	ldr r2, _08051C00
	adds r1, r0, r2
	strh r6, [r1]
	ldr r3, _08051C04
	adds r0, r3
	strh r7, [r0]
	movs r0, 0xB
	adds r1, r6, 0
	adds r2, r7, 0
	movs r3, 0
	bl sub_8051A24
_08051BF0:
	ldrh r1, [r4]
	ldr r0, _08051C08
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	b _08051D42
	.align 2, 0
_08051BFC: .4byte gDungeonGlobalData
_08051C00: .4byte 0x00000684
_08051C04: .4byte 0x00000686
_08051C08: .4byte 0x0000fffc
_08051C0C:
	ldrh r1, [r4]
	ldr r0, _08051C18
	ands r0, r1
	ldr r1, _08051C1C
	ands r0, r1
	b _08051D5A
	.align 2, 0
_08051C18: .4byte 0x0000fffc
_08051C1C: .4byte 0x0000feff
_08051C20:
	ldrh r1, [r4]
	ldr r0, _08051C44
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _08051C48
	ldr r0, [r0]
	ldr r3, _08051C4C
	adds r1, r0, r3
	strh r6, [r1]
	ldr r1, _08051C50
	adds r0, r1
	strh r7, [r0]
	strb r2, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051C44: .4byte 0x0000fffc
_08051C48: .4byte gDungeonGlobalData
_08051C4C: .4byte 0x0000e218
_08051C50: .4byte 0x0000e21a
_08051C54:
	ldrh r1, [r4]
	ldr r0, _08051C60
	ands r0, r1
	movs r2, 0
	movs r1, 0x2
	b _08051D42
	.align 2, 0
_08051C60: .4byte 0x0000fffc
_08051C64:
	ldrh r1, [r4]
	ldr r0, _08051C70
	ands r0, r1
	movs r1, 0x3
	b _08051D58
	.align 2, 0
_08051C70: .4byte 0x0000fffc
_08051C74:
	ldr r1, _08051C8C
	movs r0, 0x1
	strb r0, [r1]
	bl sub_8049840
_08051C7E:
	ldrh r1, [r4]
	ldr r0, _08051C90
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	b _08051D56
	.align 2, 0
_08051C8C: .4byte gUnknown_202F1A8
_08051C90: .4byte 0x0000fffc
_08051C94:
	ldrh r1, [r4]
	ldr r0, _08051CC0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r4, 0x4]
	movs r2, 0
	orrs r0, r1
	ldr r1, _08051CC4
	ands r0, r1
	strh r0, [r4, 0x4]
	strb r2, [r4, 0x9]
	ldr r0, _08051CC8
	ldr r0, [r0]
	ldr r2, _08051CCC
	adds r1, r0, r2
	strh r6, [r1]
	ldr r3, _08051CD0
	adds r0, r3
	strh r7, [r0]
	b _08051E1A
	.align 2, 0
_08051CC0: .4byte 0x0000fffc
_08051CC4: .4byte 0x0000fffd
_08051CC8: .4byte gDungeonGlobalData
_08051CCC: .4byte 0x0000e21c
_08051CD0: .4byte 0x0000e21e
_08051CD4:
	ldrh r1, [r4]
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	orrs r0, r1
	ldr r1, _08051CF8
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	orrs r0, r1
	strh r0, [r4]
	ldrh r1, [r4, 0x4]
	ldr r0, _08051CFC
	ands r0, r1
	strh r0, [r4, 0x4]
	strb r2, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051CF8: .4byte 0x0000fffc
_08051CFC: .4byte 0x0000fffd
_08051D00:
	ldrh r1, [r4]
	ldr r0, _08051D0C
	ands r0, r1
	movs r1, 0x1
	b _08051D58
	.align 2, 0
_08051D0C: .4byte 0x0000fffc
_08051D10:
	ldrh r1, [r4]
	ldr r0, _08051D20
	ands r0, r1
	movs r1, 0x1
	movs r2, 0
	orrs r0, r1
	b _08051D3C
	.align 2, 0
_08051D20: .4byte 0x0000fffc
_08051D24:
	ldrh r1, [r4]
	ldr r0, _08051D4C
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	movs r2, 0x80
	lsls r2, 5
	adds r1, r2, 0
	orrs r0, r1
	movs r1, 0x10
	orrs r0, r1
	movs r2, 0
_08051D3C:
	movs r3, 0x80
	lsls r3, 4
	adds r1, r3, 0
_08051D42:
	orrs r0, r1
	strh r0, [r4]
	strb r2, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051D4C: .4byte 0x0000fffc
_08051D50:
	ldrh r1, [r4]
	ldr r0, _08051D64
	ands r0, r1
_08051D56:
	movs r1, 0x10
_08051D58:
	orrs r0, r1
_08051D5A:
	strh r0, [r4]
	movs r0, 0xFF
	strb r0, [r4, 0x9]
	b _08051E1A
	.align 2, 0
_08051D64: .4byte 0x0000fffc
_08051D68:
	mov r0, r8
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xCB
	bhi _08051E1A
	mov r1, r8
	lsls r0, r1, 4
	ldr r1, _08051DA0
	adds r5, r0, r1
	ldrb r0, [r5, 0xC]
	strb r0, [r4, 0x9]
	ldrb r1, [r5]
	cmp r1, 0
	beq _08051DB8
	mov r2, r9
	cmp r2, 0
	beq _08051DA4
	ldrb r0, [r5]
	movs r1, 0x2
	ldrsh r3, [r5, r1]
	ldr r1, [r5, 0x4]
	str r1, [sp]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_805193C
	b _08051DDC
	.align 2, 0
_08051DA0: .4byte gUnknown_80F6D20
_08051DA4:
	ldr r0, _08051DB0
	ldr r0, [r0]
	ldr r2, _08051DB4
	adds r0, r2
	strb r1, [r0]
	b _08051DDC
	.align 2, 0
_08051DB0: .4byte gDungeonGlobalData
_08051DB4: .4byte 0x0000068b
_08051DB8:
	ldr r2, [r5, 0x4]
	cmp r2, 0
	beq _08051DDC
	ldr r0, _08051E2C
	ldr r1, [r0]
	subs r0, r2, 0x1
	lsls r0, 2
	adds r0, r1, r0
	ldr r3, _08051E30
	adds r0, r3
	strh r6, [r0]
	ldr r0, [r5, 0x4]
	subs r0, 0x1
	lsls r0, 2
	adds r1, r0
	ldr r0, _08051E34
	adds r1, r0
	strh r7, [r1]
_08051DDC:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _08051DF2
	ldrb r3, [r5, 0xA]
	mov r1, r8
	str r1, [sp]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8051998
_08051DF2:
	ldrb r0, [r5, 0xB]
	cmp r0, 0x14
	beq _08051E08
	mov r2, r9
	cmp r2, 0
	beq _08051E08
	ldrb r3, [r5, 0xD]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8051A24
_08051E08:
	ldrb r0, [r5, 0xE]
	cmp r0, 0
	beq _08051E1A
	ldrh r0, [r4]
	ldr r1, _08051E38
	ands r1, r0
	movs r0, 0x2
	orrs r1, r0
	strh r1, [r4]
_08051E1A:
	movs r0, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08051E2C: .4byte gDungeonGlobalData
_08051E30: .4byte 0x0000e220
_08051E34: .4byte 0x0000e222
_08051E38: .4byte 0x0000fffc
	thumb_func_end sub_8051A74

	thumb_func_start sub_8051E3C
sub_8051E3C:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r5, 0
_08051E42:
	movs r4, 0
	adds r6, r5, 0x1
_08051E46:
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetMapTile_2
	adds r2, r0, 0
	ldrb r0, [r2, 0xE]
	cmp r0, 0xF
	bls _08051E66
	adds r1, r0, 0
	movs r0, 0
	str r0, [sp]
	adds r0, r2, 0
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_8051A74
_08051E66:
	adds r4, 0x1
	cmp r4, 0x37
	ble _08051E46
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _08051E42
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8051E3C

	thumb_func_start sub_8051E7C
sub_8051E7C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r9, r0
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	mov r2, r9
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	subs r1, 0x1
	bl GetMapTile_2
	str r0, [sp, 0x8]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _08051EB8
	ldr r0, _08051EB4
	ldr r1, [r0]
	mov r0, r9
	bl SendMessage
	b _080520F6
	.align 2, 0
_08051EB4: .4byte gUnknown_80FDDF0
_08051EB8:
	ldr r0, _08051EF0
	ldr r0, [r0]
	ldr r1, _08051EF4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08051EC8
	b _080520EC
_08051EC8:
	mov r2, r9
	ldrh r1, [r2, 0x6]
	subs r1, 0x1
	lsls r1, 16
	ldrh r0, [r2, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, r9
	bl GetEntityRoomIndex
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	mov r3, r9
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	adds r6, r0, 0
	subs r6, 0x15
	b _08051FE0
	.align 2, 0
_08051EF0: .4byte gDungeonGlobalData
_08051EF4: .4byte 0x00003a09
_08051EF8:
	mov r2, r9
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	adds r5, r0, 0
	subs r5, 0x14
	adds r0, 0x14
	adds r1, r6, 0x1
	str r1, [sp, 0x10]
	cmp r5, r0
	bgt _08051FD8
	ldr r2, _080520C0
	mov r10, r2
_08051F10:
	mov r0, r10
	ldr r3, [r0]
	ldr r1, _080520C4
	adds r0, r3, r1
	ldr r1, [r0]
	subs r2, r5, r1
	mov r8, r2
	ldr r2, _080520C8
	adds r0, r3, r2
	ldr r2, [r0]
	subs r7, r6, r2
	mov r0, r8
	cmp r0, 0
	blt _08051FCA
	cmp r7, 0
	blt _08051FCA
	cmp r0, 0x7
	bgt _08051FCA
	cmp r7, 0x7
	bgt _08051FCA
	adds r0, r1, 0x1
	cmp r5, r0
	blt _08051FCA
	adds r0, r2, 0x1
	cmp r6, r0
	blt _08051FCA
	ldr r1, _080520CC
	adds r0, r3, r1
	ldr r0, [r0]
	subs r0, 0x1
	cmp r5, r0
	bge _08051FCA
	ldr r2, _080520D0
	adds r0, r3, r2
	ldr r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _08051FCA
	adds r0, r5, 0
	adds r1, r6, 0
	bl GetMapTile_2
	adds r4, r0, 0
	ldrh r0, [r4]
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08051F9A
	mov r0, r10
	ldr r2, [r0]
	lsls r1, r7, 1
	adds r1, r7
	lsls r1, 3
	mov r3, r8
	lsls r0, r3, 1
	add r0, r8
	lsls r0, 6
	adds r1, r0
	adds r2, r1
	ldr r1, _080520D4
	adds r0, r2, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldr r3, _080520D8
	adds r2, r3
	ldrh r0, [r2]
	strh r0, [r4, 0x4]
_08051F9A:
	mov r1, r10
	ldr r0, [r1]
	mov r2, r8
	lsls r1, r2, 3
	adds r1, r7, r1
	ldr r3, _080520DC
	adds r0, r3
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8051A74
	ldrh r1, [r4, 0x4]
	movs r0, 0x3
	orrs r0, r1
	strh r0, [r4, 0x4]
	ldr r0, [sp, 0xC]
	cmp r0, 0xFF
	beq _08051FCA
	strb r0, [r4, 0x9]
_08051FCA:
	adds r5, 0x1
	mov r2, r9
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	adds r0, 0x14
	cmp r5, r0
	ble _08051F10
_08051FD8:
	ldr r6, [sp, 0x10]
	mov r1, r9
	movs r2, 0x6
	ldrsh r0, [r1, r2]
_08051FE0:
	adds r0, 0x13
	cmp r6, r0
	ble _08051EF8
	mov r3, r9
	movs r1, 0x6
	ldrsh r0, [r3, r1]
	adds r6, r0, 0
	subs r6, 0x15
	adds r0, 0x13
	ldr r7, _080520C0
	cmp r6, r0
	bgt _0805207A
_08051FF8:
	mov r2, r9
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	adds r5, r0, 0
	subs r5, 0x14
	adds r0, 0x14
	adds r1, r6, 0x1
	str r1, [sp, 0x10]
	cmp r5, r0
	bgt _0805206C
	ldr r7, _080520C0
_0805200E:
	ldr r0, _080520C0
	ldr r4, [r0]
	ldr r2, _080520C4
	adds r0, r4, r2
	ldr r2, [r0]
	subs r1, r5, r2
	ldr r3, _080520C8
	adds r0, r4, r3
	ldr r3, [r0]
	subs r0, r6, r3
	cmp r1, 0
	blt _0805205E
	cmp r0, 0
	blt _0805205E
	cmp r1, 0x7
	bgt _0805205E
	cmp r0, 0x7
	bgt _0805205E
	adds r0, r2, 0x1
	cmp r5, r0
	blt _0805205E
	adds r0, r3, 0x1
	cmp r6, r0
	blt _0805205E
	ldr r1, _080520CC
	adds r0, r4, r1
	ldr r0, [r0]
	subs r0, 0x1
	cmp r5, r0
	bge _0805205E
	ldr r2, _080520D0
	adds r0, r4, r2
	ldr r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _0805205E
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80498A8
_0805205E:
	adds r5, 0x1
	mov r3, r9
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	adds r0, 0x14
	cmp r5, r0
	ble _0805200E
_0805206C:
	ldr r6, [sp, 0x10]
	mov r2, r9
	movs r3, 0x6
	ldrsh r0, [r2, r3]
	adds r0, 0x13
	cmp r6, r0
	ble _08051FF8
_0805207A:
	ldr r0, [r7]
	ldr r1, _080520E0
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, [sp, 0x8]
	ldrh r1, [r2]
	ldr r0, _080520E4
	ands r0, r1
	strh r0, [r2]
	mov r3, r9
	movs r1, 0x4
	ldrsh r0, [r3, r1]
	movs r2, 0x6
	ldrsh r1, [r3, r2]
	subs r1, 0x1
	bl sub_80498A8
	bl sub_8049B8C
	bl sub_8049ED4
	add r0, sp, 0x4
	bl sub_80429FC
	ldr r0, _080520E8
	ldr r1, [r0]
	mov r0, r9
	bl SendMessage
	movs r0, 0x14
	movs r1, 0x3C
	bl sub_803E708
	b _080520F6
	.align 2, 0
_080520C0: .4byte gDungeonGlobalData
_080520C4: .4byte 0x0000e250
_080520C8: .4byte 0x0000e254
_080520CC: .4byte 0x0000e258
_080520D0: .4byte 0x0000e25c
_080520D4: .4byte 0x0000e27c
_080520D8: .4byte 0x0000e280
_080520DC: .4byte 0x0000e87c
_080520E0: .4byte 0x00003a09
_080520E4: .4byte 0x0000efef
_080520E8: .4byte gUnknown_80FDDD0
_080520EC:
	ldr r0, _08052108
	ldr r1, [r0]
	mov r0, r9
	bl SendMessage
_080520F6:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052108: .4byte gUnknown_80FDDF0
	thumb_func_end sub_8051E7C

	thumb_func_start sub_805210C
sub_805210C:
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	ldr r7, _080521B4
	movs r4, 0x1
	ldr r2, [r7]
_0805211A:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0805212A
	ldrb r0, [r2, 0x2]
	cmp r0, r5
	beq _080521C8
_0805212A:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _0805211A
	movs r3, 0
	ldr r0, _080521B8
	ldr r4, [r0]
	movs r6, 0x1
_0805213A:
	movs r0, 0x64
	adds r2, r3, 0
	muls r2, r0
	adds r0, r2, r4
	ldr r1, _080521BC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0805216C
	adds r0, r2, r4
	ldr r1, _080521C0
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	adds r1, r2, r4
	cmp r0, 0
	beq _0805216C
	ldr r2, _080521C4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r5
	beq _080521C8
_0805216C:
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805213A
	movs r3, 0
	ldr r0, _080521B8
	ldr r4, [r0]
_08052178:
	movs r0, 0x58
	muls r0, r3
	adds r2, r0, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08052196
	adds r0, r2, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	beq _08052196
	cmp r0, r5
	beq _080521C8
_08052196:
	adds r3, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	ble _08052178
	ldr r0, [r7]
	lsls r1, r5, 1
	adds r0, 0x50
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _080521C8
	movs r0, 0
	b _080521CA
	.align 2, 0
_080521B4: .4byte gTeamInventory_203B460
_080521B8: .4byte gRecruitedPokemonRef
_080521BC: .4byte 0x00008df8
_080521C0: .4byte 0x00008e38
_080521C4: .4byte 0x00008e3a
_080521C8:
	movs r0, 0x1
_080521CA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805210C

        thumb_func_start sub_80521D0
sub_80521D0:
	push {r4-r6,lr}
	movs r1, 0
	ldr r5, _08052200
	ldr r6, _08052204
	ldr r4, _08052208
	ldr r3, _0805220C
	movs r2, 0
_080521DE:
	ldr r0, [r4]
	adds r0, r3
	adds r0, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, 0x9
	ble _080521DE
	movs r0, 0
	str r0, [r5]
	movs r0, 0x1
	strb r0, [r6]
	movs r0, 0
	bl sub_8052210
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08052200: .4byte gUnknown_202F1E8
_08052204: .4byte gUnknown_203B434
_08052208: .4byte gDungeonGlobalData
_0805220C: .4byte 0x0001c054
	thumb_func_end sub_80521D0

	thumb_func_start sub_8052210
sub_8052210:
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	ldr r5, _08052280
_0805221A:
	lsls r0, r4, 6
	ldr r1, [r5]
	adds r0, r1
	ldr r1, _08052284
	adds r0, r1
	ldr r1, _08052288
	bl strcpy
	adds r4, 0x1
	cmp r4, 0x9
	ble _0805221A
	ldr r1, _08052280
	ldr r0, [r1]
	ldr r2, _0805228C
	adds r0, r2
	movs r3, 0
	strb r3, [r0]
	ldr r0, [r1]
	adds r2, 0x1
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, 0x2
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, 0x2
	adds r1, r0, r2
	strh r3, [r1]
	ldr r1, _08052290
	adds r2, r0, r1
	movs r1, 0x4
	strh r1, [r2]
	ldr r2, _08052294
	adds r0, r2
	str r3, [r0]
	cmp r6, 0
	beq _08052278
	ldr r0, _08052298
	ldr r0, [r0]
	cmp r0, 0x3
	bne _08052278
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0xB
	bl sub_803E46C
_08052278:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08052280: .4byte gDungeonGlobalData
_08052284: .4byte 0x0001bdd4
_08052288: .4byte gUnknown_80F7AE8
_0805228C: .4byte 0x0001c05f
_08052290: .4byte 0x0001c066
_08052294: .4byte 0x0001c06c
_08052298: .4byte gUnknown_202EDD0
	thumb_func_end sub_8052210

        .align 2,0
