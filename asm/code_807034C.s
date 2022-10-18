	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_807034C
sub_807034C:
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	asrs r2, r0, 16
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _08070398
	ldrh r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070398
	adds r0, r2, 0
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r2, r0, 24
	ldrh r0, [r4]
	movs r1, 0x3
	ands r1, r0
	cmp r2, 0x1
	beq _08070388
	cmp r2, 0x1
	bgt _08070382
	cmp r2, 0
	beq _0807038C
	b _08070390
_08070382:
	cmp r2, 0x2
	beq _08070394
	b _08070390
_08070388:
	cmp r1, 0x2
	beq _08070390
_0807038C:
	cmp r1, 0x1
	bne _08070398
_08070390:
	movs r0, 0
	b _0807039A
_08070394:
	cmp r1, 0
	bne _08070390
_08070398:
	movs r0, 0x1
_0807039A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_807034C

	thumb_func_start sub_80703A0
sub_80703A0:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_1
	adds r5, r0, 0
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08070456
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	cmp r1, 0
	blt _08070456
	cmp r0, 0x37
	bgt _08070456
	cmp r1, 0x1F
	bgt _08070456
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _08070456
	ldrh r1, [r5]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08070456
	bl IsFixedDungeon
	lsls r0, 24
	cmp r0, 0
	bne _08070400
	adds r0, r7, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _0807044E
	adds r0, r6, 0
	movs r1, 0x9
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	bne _0807044E
_08070400:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	bl GetCrossableTerrain
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r5]
	movs r5, 0x3
	ands r5, r0
	adds r0, r6, 0
	movs r1, 0xC
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070422
	movs r4, 0x2
_08070422:
	adds r0, r6, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _08070432
	movs r4, 0x3
_08070432:
	cmp r4, 0x1
	beq _08070446
	cmp r4, 0x1
	bgt _08070440
	cmp r4, 0
	beq _0807044A
	b _0807044E
_08070440:
	cmp r4, 0x2
	beq _08070452
	b _0807044E
_08070446:
	cmp r5, 0x2
	beq _0807044E
_0807044A:
	cmp r5, 0x1
	bne _08070456
_0807044E:
	movs r0, 0
	b _08070458
_08070452:
	cmp r5, 0
	bne _0807044E
_08070456:
	movs r0, 0x1
_08070458:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80703A0

	.align 2, 0