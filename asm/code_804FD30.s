	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

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
	bl GetTile
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
	bl DungeonRandInt
	lsls r0, 2
	mov r1, sp
	adds r4, r1, r0
	ldrb r0, [r4]
	ldrb r1, [r4, 0x1]
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetTile
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
	bl DungeonRandRange
	adds r4, r0, 0
	cmp r4, 0
	bgt _080500BC
	movs r4, 0x1
_080500BC:
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTile
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
	bl DungeonRandRange
	adds r4, r0, 0
	cmp r4, 0
	ble _0805018E
	mov r0, sp
	mov r1, r8
	bl sub_804FED0
	mov r0, r8
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTile
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
	bl DungeonRandRange
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
	bl DungeonRandInt
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
_08050238: .4byte gDungeon
_0805023C: .4byte 0x0000e21c
_08050240: .4byte 0x0000e21e
_08050244: .4byte 0x0000fffd
_08050248: .4byte gUnknown_202F1B4
_0805024C: .4byte 0x00003a0c
_08050250: .4byte gUnknown_80F4DA0
_08050254:
	ldrb r1, [r7, 0x1]
	bl GetTileSafe
	adds r4, r0, 0
	movs r0, 0x2
	bl DungeonRandInt
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
	bl GetTile
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
	bl DungeonRandRange
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
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTile
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
	bl DungeonRandInt
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
_08050424: .4byte gDungeon
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
	bl DungeonRandRange
	adds r7, r0, 0
	cmp r7, 0
	bgt _0805047A
	movs r7, 0x1
	b _0805047A
	.align 2, 0
_08050470: .4byte 0xffffe3f8
_08050474: .4byte gDungeon
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
	bl GetTile
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
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTile
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
	bl DungeonRandRange
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
	bl DungeonRandInt
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
	bl GetTileSafe
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
_080506A8: .4byte gDungeon
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
	bl DungeonRandInt
	lsls r0, 2
	adds r0, r4
	ldr r4, [r0]
	cmp r4, 0
	bne _0805071C
	b _08050A7C
_0805071C:
	movs r0, 0x64
	bl DungeonRandInt
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
	bl DungeonRandInt
	adds r0, 0xA
	str r0, [sp, 0x78]
	movs r0, 0x2
	movs r1, 0x36
	bl DungeonRandRange
	mov r9, r0
	movs r2, 0
	str r2, [sp, 0x6C]
	subs r4, 0x1
	str r4, [sp, 0x98]
_08050762:
	movs r0, 0x6
	bl DungeonRandInt
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
	bl GetTile
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
	bl GetTileSafe
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
	bl DungeonRandInt
	subs r0, 0x3
	str r0, [sp, 0x84]
	movs r0, 0x7
	bl DungeonRandInt
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
	bl GetTile
	ldrh r1, [r0]
	movs r2, 0x3
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r4, 0
	adds r1, r5, 0
	str r2, [sp, 0x9C]
	bl GetTile
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	subs r7, r5, 0x1
	adds r0, r4, 0
	adds r1, r7, 0
	bl GetTile
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r6, 0
	mov r1, r8
	bl GetTile
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetTile
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	subs r4, r6, 0x1
	adds r0, r4, 0
	mov r1, r8
	bl GetTile
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r4, 0
	adds r1, r5, 0
	bl GetTile
	ldrh r1, [r0]
	ldr r2, [sp, 0x9C]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080508B2
	adds r0, r4, 0
	adds r1, r7, 0
	bl GetTile
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
	bl GetTileSafe
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
	bl GetTile
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
	bl GetTile
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
	bl GetTile
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
	bl GetTile
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
	bl GetTile
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
	bl GetTile
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
	bl GetTile
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
	bl GetTile
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
	bl GetTileSafe
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
	bl DungeonRandInt
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
	bl DungeonRandRange
	mov r9, r0
	movs r0, 0
	movs r1, 0x20
	bl DungeonRandRange
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
	bl DungeonRandInt
	adds r4, r0, 0
	adds r7, r4, 0x1
	movs r0, 0x8
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetTileSafe
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
_08050F44: .4byte gDungeon
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
	bl DungeonRandRange
	adds r6, r0, 0
	adds r0, r5, 0
	adds r1, r7, 0
	bl DungeonRandRange
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
	bl DungeonRandInt
	mov r2, r9
	adds r4, r0, r2
	subs r0, r7, r5
	bl DungeonRandInt
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
	bl GetTileSafe
	ldrh r1, [r0]
	mov r2, r9
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
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
	bl DungeonRandRange
	adds r5, r0, 0
	ldr r2, [sp, 0x34]
	mov r1, r10
	adds r0, r1, r2
	adds r1, r7
	mov r2, r8
	subs r1, r2
	bl DungeonRandRange
	adds r4, r0, 0
	strh r5, [r6]
	adds r0, r5, 0x1
	strh r0, [r6, 0x4]
	strh r4, [r6, 0x2]
	adds r0, r4, 0x1
	strh r0, [r6, 0x6]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
	ldrh r1, [r0]
	ldr r3, _080511EC
	adds r2, r3, 0
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strh r1, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetTileSafe
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
_08051374: .4byte gDungeon
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
	bl GetTileSafe
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
	bl GetTileSafe
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
_08051430: .4byte gDungeon
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
	bl GetTileSafe
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
_080515AC: .4byte gDungeon
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
	bl GetTileSafe
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
	bl DungeonRandRange
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
	bl DungeonRandRange
	mov r9, r0
	cmp r0, 0x2
	bgt _08051694
	movs r1, 0x3
	mov r9, r1
_08051694:
	movs r0, 0x2
	movs r1, 0x4
	bl DungeonRandRange
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
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl DungeonRandInt
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetTileSafe
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
_08051BFC: .4byte gDungeon
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
_08051C48: .4byte gDungeon
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
_08051CC8: .4byte gDungeon
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
_08051DB0: .4byte gDungeon
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
_08051E2C: .4byte gDungeon
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
	bl GetTileSafe
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
	bl GetTileSafe
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
	bl GetEntityRoom
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
_08051EF0: .4byte gDungeon
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
	bl GetTileSafe
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
_080520C0: .4byte gDungeon
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
_080521B4: .4byte gTeamInventoryRef
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
_08052208: .4byte gDungeon
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
_08052280: .4byte gDungeon
_08052284: .4byte 0x0001bdd4
_08052288: .4byte gUnknown_80F7AE8
_0805228C: .4byte 0x0001c05f
_08052290: .4byte 0x0001c066
_08052294: .4byte 0x0001c06c
_08052298: .4byte gUnknown_202EDD0
	thumb_func_end sub_8052210

    .align 2,0
