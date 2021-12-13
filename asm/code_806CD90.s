	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_806CEBC
sub_806CEBC:
	push {lr}
	ldr r0, [r0, 0x70]
	adds r1, r0, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806CED2
	cmp r0, 0x5
	beq _0806CED2
	cmp r0, 0x3
	bne _0806CEE8
_0806CED2:
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	cmp r0, 0xB9
	bne _0806CEE4
	adds r0, r1, 0
	adds r0, 0xA9
	ldrb r0, [r0]
	cmp r0, 0x7F
	beq _0806CEF2
_0806CEE4:
	movs r0, 0x5
	b _0806CEF8
_0806CEE8:
	adds r0, r1, 0
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806CEF6
_0806CEF2:
	movs r0, 0x7
	b _0806CEF8
_0806CEF6:
	movs r0, 0xB
_0806CEF8:
	pop {r1}
	bx r1
	thumb_func_end sub_806CEBC

	thumb_func_start sub_806CEFC
sub_806CEFC:
	push {r4,lr}
	adds r4, r1, 0
	ldr r2, [r0, 0x70]
	movs r3, 0x7
	ands r1, r3
	adds r2, 0x46
	strb r1, [r2]
	movs r1, 0x7
	ands r1, r4
	bl sub_806CE68
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806CEFC

	thumb_func_start sub_806CF18
sub_806CF18:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806CF4C
	ldr r6, [r4, 0x70]
	movs r5, 0
	b _0806CF2E
_0806CF2C:
	adds r5, 0x1
_0806CF2E:
	cmp r5, 0x63
	bgt _0806CF4C
	movs r0, 0x21
	bl sub_803E46C
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r1, r4, 0
	adds r1, 0x6B
	ldrb r1, [r1]
	bl sub_808DA44
	lsls r0, 24
	cmp r0, 0
	bne _0806CF2C
_0806CF4C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806CF18

	thumb_func_start sub_806CF54
sub_806CF54:
	ldr r0, [r0, 0x70]
	movs r1, 0x81
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	thumb_func_end sub_806CF54

	thumb_func_start sub_806CF60
sub_806CF60:
	push {r4,r5,lr}
	movs r5, 0
_0806CF64:
	ldr r0, _0806CF90
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806CF94
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806CF84
	adds r0, r4, 0
	bl sub_806CF98
_0806CF84:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806CF64
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CF90: .4byte gDungeonGlobalData
_0806CF94: .4byte 0x000135cc
	thumb_func_end sub_806CF60

	thumb_func_start sub_806CF98
sub_806CF98:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_8045128
	ldrh r0, [r0]
	movs r5, 0x3
	ands r5, r0
	adds r6, r5, 0
	ldr r7, [r4, 0x70]
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl GetShadowSize
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r5, 0x3
	bne _0806CFBE
	movs r0, 0x6
	b _0806CFF8
_0806CFBE:
	cmp r5, 0x1
	bne _0806CFCE
	bl IsWaterTileset
	lsls r0, 24
	cmp r0, 0
	beq _0806CFEE
	b _0806CFE8
_0806CFCE:
	cmp r6, 0x2
	bne _0806CFEE
	ldr r1, _0806D000
	ldr r0, _0806D004
	ldr r0, [r0]
	ldr r2, _0806D008
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806CFEE
_0806CFE8:
	ldr r0, _0806D00C
	adds r0, r4, r0
	ldrb r4, [r0]
_0806CFEE:
	movs r1, 0x81
	lsls r1, 2
	adds r0, r7, r1
	strb r4, [r0]
	adds r0, r4, 0
_0806CFF8:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806D000: .4byte gDungeonWaterType
_0806D004: .4byte gDungeonGlobalData
_0806D008: .4byte 0x00003a0e
_0806D00C: .4byte gUnknown_8106EEF
	thumb_func_end sub_806CF98

	thumb_func_start sub_806D010
sub_806D010:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r6, r0, 0
	adds r5, r1, 0
	mov r8, r2
	ldr r0, [sp, 0x40]
	lsls r0, 16
	asrs r0, 16
	mov r10, r0
	movs r7, 0
	ldr r0, [sp, 0x3C]
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x48]
	str r2, [sp, 0x8]
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, r8
	bl sub_806D528
	lsls r0, 24
	cmp r0, 0
	beq _0806D04A
	b _0806D514
_0806D04A:
	mov r3, r8
	ldrb r0, [r3, 0xF]
	cmp r0, 0
	beq _0806D054
	b _0806D514
_0806D054:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D062
	b _0806D514
_0806D062:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D070
	b _0806D514
_0806D070:
	adds r0, r6, 0
	bl GetEntityType
	cmp r0, 0x1
	beq _0806D07C
	b _0806D514
_0806D07C:
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	beq _0806D088
	b _0806D514
_0806D088:
	ldr r0, [sp, 0x44]
	mov r9, r0
	adds r0, r5, 0
	bl CannotAct
	lsls r0, 24
	cmp r0, 0
	bne _0806D0A2
	ldr r0, [r5, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806D0A6
_0806D0A2:
	movs r1, 0
	mov r9, r1
_0806D0A6:
	mov r2, r9
	cmp r2, 0
	beq _0806D100
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D0BC
	negs r1, r1
_0806D0BC:
	cmp r1, 0x1
	bgt _0806D100
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D0D0
	negs r1, r1
_0806D0D0:
	cmp r1, 0x1
	bgt _0806D100
	cmp r6, r5
	beq _0806D100
	mov r3, r8
	ldrb r0, [r3, 0xC]
	bl sub_8092354
	lsls r0, 24
	cmp r0, 0
	beq _0806D100
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xD
	bne _0806D100
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8042730
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_807F43C
_0806D100:
	ldr r0, [r5, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _0806D118
	ldr r0, _0806D3BC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_8077084
_0806D118:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D126
	b _0806D514
_0806D126:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D134
	b _0806D514
_0806D134:
	mov r0, r9
	cmp r0, 0
	beq _0806D216
	cmp r6, r5
	beq _0806D216
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	subs r1, r0
	cmp r1, 0
	bge _0806D14E
	negs r1, r1
_0806D14E:
	cmp r1, 0x1
	bgt _0806D216
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D162
	negs r1, r1
_0806D162:
	cmp r1, 0x1
	bgt _0806D216
	mov r3, r8
	ldrb r0, [r3, 0xC]
	bl sub_8092354
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806D188
	cmp r4, 0
	beq _0806D188
	adds r0, r5, 0
	bl sub_8041B18
	adds r7, 0x4
_0806D188:
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xA
	bne _0806D19E
	cmp r4, 0
	beq _0806D19E
	adds r0, r5, 0
	bl sub_8041B18
	adds r7, 0x1
_0806D19E:
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0806D1B4
	cmp r4, 0
	bne _0806D1B4
	adds r0, r5, 0
	bl sub_8041B90
	adds r7, 0x4
_0806D1B4:
	adds r0, r5, 0
	movs r1, 0x12
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D1C4
	adds r7, 0x2
_0806D1C4:
	cmp r7, 0
	beq _0806D216
	ldr r0, _0806D3C0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	mov r1, r8
	ldr r0, [r1]
	muls r0, r7
	cmp r0, 0
	bge _0806D1E0
	adds r0, 0x3
_0806D1E0:
	asrs r0, 2
	str r0, [sp, 0xC]
	add r2, sp, 0xC
	mov r3, r8
	ldrb r0, [r3, 0xC]
	movs r1, 0
	strb r0, [r2, 0xC]
	movs r0, 0x6
	str r0, [sp, 0x10]
	movs r0, 0x2
	str r0, [sp, 0x14]
	adds r0, r2, 0
	strb r1, [r0, 0xD]
	strb r1, [r0, 0xE]
	strb r1, [r0, 0xF]
	ldr r0, [sp, 0x3C]
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x48]
	str r2, [sp, 0x8]
	adds r0, r5, 0
	adds r1, r6, 0
	add r2, sp, 0xC
	movs r3, 0
	bl sub_806D528
_0806D216:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D224
	b _0806D514
_0806D224:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D232
	b _0806D514
_0806D232:
	mov r3, r9
	cmp r3, 0
	bne _0806D23A
	b _0806D48A
_0806D23A:
	cmp r6, r5
	bne _0806D240
	b _0806D48A
_0806D240:
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D250
	negs r1, r1
_0806D250:
	cmp r1, 0x1
	ble _0806D256
	b _0806D48A
_0806D256:
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D266
	negs r1, r1
_0806D266:
	cmp r1, 0x1
	ble _0806D26C
	b _0806D48A
_0806D26C:
	mov r3, r8
	ldrb r0, [r3, 0xC]
	bl sub_8092354
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r4, [r6, 0x70]
	adds r0, r5, 0
	movs r1, 0x5
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D2C2
	adds r0, r6, 0
	movs r1, 0xA
	bl HasType
	lsls r0, 24
	cmp r0, 0
	bne _0806D2C2
	adds r0, r6, 0
	movs r1, 0x37
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806D2C2
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3C4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D2C2
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r2]
_0806D2C2:
	adds r0, r5, 0
	movs r1, 0xA
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D2EE
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3C8
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D2EE
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r2]
_0806D2EE:
	adds r0, r5, 0
	movs r1, 0x17
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D328
	adds r0, r6, 0
	movs r1, 0x11
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _0806D328
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3CC
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D328
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x4
	orrs r0, r1
	strh r0, [r2]
_0806D328:
	adds r0, r5, 0
	movs r1, 0x20
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D358
	cmp r7, 0
	beq _0806D358
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3D0
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D358
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x8
	orrs r0, r1
	strh r0, [r2]
_0806D358:
	adds r0, r5, 0
	movs r1, 0x27
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D384
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3D4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D384
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x20
	orrs r0, r1
	strh r0, [r2]
_0806D384:
	adds r0, r5, 0
	movs r1, 0x3D
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D3FA
	cmp r7, 0
	beq _0806D3FA
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3D8
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D3FA
	movs r0, 0x3
	bl DungeonRandomCapped
	cmp r0, 0
	bgt _0806D3DC
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x40
	b _0806D3F6
	.align 2, 0
_0806D3BC: .4byte gUnknown_8106A4C
_0806D3C0: .4byte gUnknown_80FCFA4
_0806D3C4: .4byte gUnknown_80F4E10
_0806D3C8: .4byte gUnknown_80F4E12
_0806D3CC: .4byte gUnknown_80F4E14
_0806D3D0: .4byte gUnknown_80F4E16
_0806D3D4: .4byte gUnknown_80F4E18
_0806D3D8: .4byte gUnknown_80F4E1A
_0806D3DC:
	cmp r0, 0x1
	bgt _0806D3EC
	movs r0, 0xBC
	lsls r0, 1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, 0x10
	b _0806D3F6
_0806D3EC:
	movs r1, 0xBC
	lsls r1, 1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r0, 0x80
_0806D3F6:
	orrs r0, r1
	strh r0, [r2]
_0806D3FA:
	adds r0, r5, 0
	movs r1, 0x3E
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D428
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D4D4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D428
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	subs r3, 0x78
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r2]
_0806D428:
	adds r0, r5, 0
	movs r1, 0x44
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D45A
	cmp r7, 0
	beq _0806D45A
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D4D8
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D45A
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r3, 0x88
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r2]
_0806D45A:
	adds r0, r5, 0
	movs r1, 0x1
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D48A
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D4DC
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D48A
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 3
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r2]
_0806D48A:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806D514
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806D514
	mov r0, r9
	cmp r0, 0
	beq _0806D514
	ldr r2, [r5, 0x70]
	adds r6, r2, 0
	adds r3, r2, 0
	adds r3, 0xD0
	ldrb r0, [r3]
	cmp r0, 0x2
	bne _0806D514
	ldr r0, _0806D4E0
	ldr r1, [r0]
	adds r0, r2, 0
	adds r0, 0xD8
	ldrb r0, [r0]
	lsls r0, 2
	ldr r2, _0806D4E4
	adds r1, r2
	adds r1, r0
	ldr r4, [r1]
	cmp r4, 0
	bne _0806D4E8
	strb r4, [r3]
	b _0806D514
	.align 2, 0
_0806D4D4: .4byte gUnknown_80F4E1C
_0806D4D8: .4byte gUnknown_80F4E1E
_0806D4DC: .4byte gUnknown_80F4E20
_0806D4E0: .4byte gDungeonGlobalData
_0806D4E4: .4byte 0x000135cc
_0806D4E8:
	ldr r0, [r4, 0x70]
	adds r0, 0x98
	adds r1, r6, 0
	adds r1, 0xD4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _0806D4FE
	movs r0, 0
	strb r0, [r3]
	b _0806D514
_0806D4FE:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8041D00
	mov r3, r8
	ldr r1, [r3]
	ldr r3, _0806D524
	adds r0, r4, 0
	movs r2, 0xC
	bl sub_806F324
_0806D514:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D524: .4byte 0x000001f9
	thumb_func_end sub_806D010

	thumb_func_start sub_806D528
sub_806D528:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	mov r9, r0
	adds r7, r1, 0
	adds r5, r2, 0
	str r3, [sp, 0x4C]
	ldr r0, [sp, 0x7C]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0x50]
	movs r0, 0
	str r0, [sp, 0x54]
	mov r10, r0
	mov r8, r0
	mov r1, r10
	strb r1, [r5, 0xF]
	adds r0, r7, 0
	bl GetEntityType
	cmp r0, 0x1
	beq _0806D55C
	b _0806D754
_0806D55C:
	ldr r6, [r7, 0x70]
	mov r0, r9
	adds r1, r7, 0
	bl sub_807A96C
	mov r0, r9
	adds r1, r7, 0
	bl SetShopkeeperAggression
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806D592
	mov r2, r9
	ldr r0, [r2, 0x70]
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806D592
	ldrb r0, [r5, 0xE]
	cmp r0, 0
	bne _0806D592
	ldr r0, _0806D5C8
	movs r3, 0
	ldrsh r0, [r0, r3]
	str r0, [r5]
_0806D592:
	ldr r0, _0806D5CC
	ldr r1, [sp, 0x50]
	cmp r1, r0
	beq _0806D5DC
	adds r0, r7, 0
	movs r1, 0xD
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D5DC
	ldr r1, [r5]
	ldr r0, _0806D5D0
	cmp r1, r0
	bne _0806D5DC
	ldr r0, _0806D5D4
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806D5D8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D71E
	.align 2, 0
_0806D5C8: .4byte gUnknown_80F4F8C
_0806D5CC: .4byte 0x0000020e
_0806D5D0: .4byte 0x0000270f
_0806D5D4: .4byte gUnknown_202DFE8
_0806D5D8: .4byte gUnknown_80FCA90
_0806D5DC:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r4, [r0]
	mov r10, r0
	cmp r4, 0x1
	bne _0806D618
	ldr r0, _0806D610
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806D614
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	mov r0, r9
	adds r1, r7, 0
	bl sub_8042238
	strb r4, [r5, 0xF]
_0806D608:
	movs r0, 0
	bl _0806E0F0
	.align 2, 0
_0806D610: .4byte gUnknown_202DFE8
_0806D614: .4byte gUnknown_80F9600
_0806D618:
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806D62A
	cmp r0, 0x5
	beq _0806D62A
	cmp r0, 0x3
	bne _0806D63A
_0806D62A:
	adds r0, r6, 0
	adds r0, 0xA9
	ldrb r0, [r0]
	cmp r0, 0x7F
	bne _0806D63A
	adds r0, r7, 0
	bl sub_807A9B0
_0806D63A:
	adds r0, r7, 0
	movs r1, 0x23
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D660
	ldrb r0, [r5, 0xC]
	cmp r0, 0x5
	bne _0806D660
_0806D64E:
	ldr r2, [r5]
	movs r0, 0
	str r0, [sp]
	mov r0, r9
	adds r1, r7, 0
	movs r3, 0
	bl HealTargetHP
	b _0806D754
_0806D660:
	adds r0, r7, 0
	movs r1, 0x24
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806D674
	ldrb r0, [r5, 0xC]
	cmp r0, 0x3
	beq _0806D64E
_0806D674:
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D6D0
	ldrb r0, [r5, 0xD]
	cmp r0, 0
	beq _0806D692
	ldr r0, _0806D6A4
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D692:
	ldr r0, [r5, 0x8]
	cmp r0, 0x1
	beq _0806D6B0
	cmp r0, 0x1
	bcc _0806D6A8
	cmp r0, 0x3
	beq _0806D6C4
	b _0806D6D0
	.align 2, 0
_0806D6A4: .4byte gUnknown_80F9614
_0806D6A8:
	ldr r0, _0806D6AC
	b _0806D6B2
	.align 2, 0
_0806D6AC: .4byte gUnknown_80F9630
_0806D6B0:
	ldr r0, _0806D6C0
_0806D6B2:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D6D0
	.align 2, 0
_0806D6C0: .4byte gUnknown_80F9654
_0806D6C4:
	ldr r0, _0806D728
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D6D0:
	ldr r4, _0806D72C
	adds r0, r4, 0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r1, [r5]
	cmp r1, 0
	bne _0806D760
	mov r0, r9
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D734
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D734
	movs r3, 0xA9
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D71E
	ldr r0, _0806D730
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D71E:
	mov r0, r9
	adds r1, r7, 0
	bl sub_8042238
	b _0806D754
	.align 2, 0
_0806D728: .4byte gUnknown_80F9670
_0806D72C: .4byte gAvailablePokemonNames
_0806D730: .4byte gUnknown_80F9688
_0806D734:
	movs r1, 0xA9
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D74C
	ldr r0, _0806D75C
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D74C:
	movs r0, 0x1E
	movs r1, 0x18
	bl sub_803E708
_0806D754:
	movs r0, 0x1
	strb r0, [r5, 0xF]
	b _0806D608
	.align 2, 0
_0806D75C: .4byte gUnknown_80F9688
_0806D760:
	ldr r0, _0806D7B8
	cmp r1, r0
	bne _0806D7C4
	ldr r0, [sp, 0x80]
	cmp r0, 0
	beq _0806D796
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D796
	adds r0, r7, 0
	bl sub_8045128
	mov r8, r0
	movs r0, 0x14
	movs r1, 0x18
	bl sub_803E708
	mov r2, r8
	ldrh r1, [r2, 0x4]
	movs r0, 0x4
	orrs r0, r1
	strh r0, [r2, 0x4]
	bl sub_8049ED4
_0806D796:
	movs r3, 0xA9
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D7AE
	ldr r0, _0806D7BC
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D7AE:
	adds r1, r6, 0
	adds r1, 0xA0
	ldr r0, _0806D7C0
	str r0, [r1]
	b _0806D84A
	.align 2, 0
_0806D7B8: .4byte 0x0000270f
_0806D7BC: .4byte gUnknown_80F96A8
_0806D7C0: .4byte 0x000003e7
_0806D7C4:
	ldr r0, _0806D824
	str r1, [r0]
	ldr r1, _0806D828
	ldr r0, [r5, 0x4]
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r2, r6, 0
	adds r2, 0xA0
	ldr r0, [r2]
	ldr r1, [r5]
	adds r0, r1
	str r0, [r2]
	ldr r1, _0806D82C
	cmp r0, r1
	ble _0806D7E6
	str r1, [r2]
_0806D7E6:
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D830
	ldr r0, [r5, 0x4]
	cmp r0, 0xE
	beq _0806D808
	ldr r0, [r5]
	negs r0, r0
	movs r3, 0x1
	negs r3, r3
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_803ED30
_0806D808:
	movs r1, 0xA9
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D84A
	cmp r4, 0
	beq _0806D84A
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80522F4
	b _0806D84A
	.align 2, 0
_0806D824: .4byte gUnknown_202DE30
_0806D828: .4byte gUnknown_80F9764
_0806D82C: .4byte 0x000003e7
_0806D830:
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D84A
	cmp r4, 0
	beq _0806D84A
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80522F4
_0806D84A:
	ldr r0, [r5, 0x4]
	cmp r0, 0xE
	bne _0806D858
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	cmp r0, 0x1
	bgt _0806D900
_0806D858:
	mov r0, r8
	cmp r0, 0
	bne _0806D900
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D900
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r7, 0x4]
	cmp r1, r0
	beq _0806D8E6
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806D8E6
	movs r4, 0
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806D8B4
	ldr r0, _0806D8B0
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _0806D8B6
	adds r0, r7, 0
	bl sub_806A458
	lsls r0, 24
	cmp r0, 0
	bne _0806D8B6
	adds r0, r7, 0
	mov r1, r9
	bl CanSee
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	b _0806D8B6
	.align 2, 0
_0806D8B0: .4byte gUnknown_203B46C
_0806D8B4:
	movs r4, 0
_0806D8B6:
	adds r0, r6, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806D8C8
	movs r4, 0
_0806D8C8:
	cmp r4, 0
	beq _0806D8E0
	ldr r4, [r7, 0x70]
	adds r0, r7, 0x4
	mov r1, r9
	adds r1, 0x4
	bl CalculateFacingDir
	movs r1, 0x7
	ands r0, r1
	adds r4, 0x46
	strb r0, [r4]
_0806D8E0:
	adds r0, r7, 0
	bl TargetTileInFront
_0806D8E6:
	ldr r0, [r7, 0x70]
	adds r0, 0x46
	ldrb r2, [r0]
	adds r0, r7, 0
	movs r1, 0x6
	bl sub_806CDD4
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80420E8
	movs r3, 0x1
	str r3, [sp, 0x54]
_0806D900:
	movs r0, 0xE
	ldrsh r4, [r6, r0]
	ldr r1, [r5]
	cmp r4, r1
	ble _0806D910
	ldrh r0, [r6, 0xE]
	subs r0, r1
	b _0806D912
_0806D910:
	movs r0, 0
_0806D912:
	strh r0, [r6, 0xE]
	adds r0, r6, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x9
	bne _0806D93C
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0806D958
	movs r0, 0x1
	strh r0, [r6, 0xE]
	ldr r0, _0806D938
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D958
	.align 2, 0
_0806D938: .4byte gUnknown_8100548
_0806D93C:
	ldr r2, [sp, 0x4C]
	cmp r2, 0x1
	bne _0806D958
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	cmp r0, 0
	bne _0806D958
	strh r2, [r6, 0xE]
	ldr r0, _0806D9C8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D958:
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	subs r4, r0
	cmp r4, 0
	bge _0806D964
	movs r4, 0
_0806D964:
	ldr r2, [sp, 0x54]
	cmp r2, 0
	bne _0806D970
	mov r3, r8
	cmp r3, 0
	beq _0806D978
_0806D970:
	movs r0, 0xA
	movs r1, 0x18
	bl sub_803E708
_0806D978:
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0806D9D4
	ldr r2, [sp, 0x54]
	cmp r2, 0
	beq _0806D98E
	adds r0, r7, 0
	movs r1, 0x8
	bl sub_806CE68
_0806D98E:
	adds r0, r7, 0
	movs r1, 0x10
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806D9B2
	cmp r4, 0
	ble _0806D9B2
	ldr r1, [r5]
	ldr r0, _0806D9CC
	cmp r1, r0
	beq _0806D9B2
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8071D4C
_0806D9B2:
	mov r3, r8
	cmp r3, 0
	bne _0806D9BA
	b _0806D608
_0806D9BA:
	ldrh r1, [r3, 0x4]
	ldr r0, _0806D9D0
	ands r0, r1
	strh r0, [r3, 0x4]
	bl sub_8049ED4
	b _0806D608
	.align 2, 0
_0806D9C8: .4byte gUnknown_810056C
_0806D9CC: .4byte 0x0000270f
_0806D9D0: .4byte 0x0000fffb
_0806D9D4:
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0806D9E6
	mov r0, r9
	adds r1, r7, 0
	bl sub_807A7C8
_0806D9E6:
	mov r0, r8
	cmp r0, 0
	beq _0806DA18
	movs r0, 0x14
	movs r1, 0x18
	bl sub_803E708
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0x2
	strb r0, [r1]
	movs r0, 0xA
	movs r1, 0x18
	bl sub_803E708
	mov r2, r8
	ldrh r1, [r2, 0x4]
	ldr r0, _0806DA14
	ands r0, r1
	strh r0, [r2, 0x4]
	bl sub_8049ED4
	b _0806DA2E
	.align 2, 0
_0806DA14: .4byte 0x0000fffb
_0806DA18:
	ldr r3, [sp, 0x54]
	cmp r3, 0
	beq _0806DA2E
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1E
	movs r1, 0x18
	bl sub_803E708
_0806DA2E:
	movs r0, 0x1
	mov r8, r0
	mov r0, r9
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806DA50
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806DA50
	cmp r9, r7
	beq _0806DA50
	movs r1, 0
	mov r8, r1
_0806DA50:
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0
	strb r0, [r1]
	ldr r4, _0806DA88
	adds r0, r4, 0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, [r5, 0x4]
	subs r0, 0x13
	cmp r0, 0x1
	bhi _0806DA9C
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806DA90
	ldr r0, _0806DA8C
	ldr r2, [r0]
	b _0806DAC2
	.align 2, 0
_0806DA88: .4byte gAvailablePokemonNames
_0806DA8C: .4byte gUnknown_80F9E44
_0806DA90:
	ldr r0, _0806DA98
	ldr r1, [r0]
	b _0806DB86
	.align 2, 0
_0806DA98: .4byte gUnknown_80F9E44
_0806DA9C:
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806DAD0
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806DAB8
	ldr r0, _0806DAB4
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DAB4: .4byte gUnknown_80F9DF0
_0806DAB8:
	ldr r0, _0806DACC
	mov r2, r8
	lsls r1, r2, 2
	adds r1, r0
	ldr r2, [r1]
_0806DAC2:
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806DBA4
	.align 2, 0
_0806DACC: .4byte gUnknown_80F9CC0
_0806DAD0:
	ldr r2, _0806DB04
	ldrb r1, [r6, 0xA]
	movs r0, 0x64
	muls r0, r1
	ldr r3, _0806DB08
	adds r0, r3
	ldr r1, [r2]
	adds r3, r1, r0
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806DB00
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0x41
	bne _0806DB18
	ldr r0, _0806DB0C
	ldr r0, [r0]
	ldr r1, _0806DB10
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806DB18
_0806DB00:
	ldr r0, _0806DB14
	b _0806DB7E
	.align 2, 0
_0806DB04: .4byte gRecruitedPokemonRef
_0806DB08: .4byte 0x00008df8
_0806DB0C: .4byte gDungeonGlobalData
_0806DB10: .4byte 0x0000065c
_0806DB14: .4byte gUnknown_80F9CEC
_0806DB18:
	ldrb r0, [r2]
	cmp r0, 0x4A
	beq _0806DB22
	cmp r0, 0x47
	bne _0806DB26
_0806DB22:
	movs r0, 0x1
	b _0806DB28
_0806DB26:
	movs r0, 0
_0806DB28:
	cmp r0, 0
	beq _0806DB38
	ldr r0, _0806DB34
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DB34: .4byte gUnknown_80F9DAC
_0806DB38:
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806DB4C
	ldr r0, _0806DB48
	b _0806DB7E
	.align 2, 0
_0806DB48: .4byte gUnknown_80F9DF0
_0806DB4C:
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _0806DB94
	ldr r0, _0806DB70
	ldr r0, [r0]
	ldr r2, _0806DB74
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DB7C
	ldr r0, _0806DB78
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DB70: .4byte gDungeonGlobalData
_0806DB74: .4byte 0x0000065d
_0806DB78: .4byte gUnknown_80F9D8C
_0806DB7C:
	ldr r0, _0806DB90
_0806DB7E:
	mov r2, r8
	lsls r1, r2, 2
_0806DB82:
	adds r1, r0
	ldr r1, [r1]
_0806DB86:
	mov r0, r9
	bl sub_805239C
	b _0806DBA4
	.align 2, 0
_0806DB90: .4byte gUnknown_80F9D84
_0806DB94:
	ldr r0, _0806DC4C
	mov r3, r8
	lsls r1, r3, 2
	adds r1, r0
	ldr r1, [r1]
	mov r0, r9
	bl sub_805239C
_0806DBA4:
	mov r1, r10
	ldrb r0, [r1]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806DBBC
	adds r0, r6, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_0806DBBC:
	adds r1, r6, 0
	adds r1, 0x60
	ldrb r3, [r1]
	movs r2, 0x1
	mov r8, r2
	mov r0, r8
	ands r0, r3
	adds r5, r1, 0
	cmp r0, 0
	beq _0806DC5C
	movs r0, 0x8
	ands r0, r3
	cmp r0, 0
	bne _0806DC5C
	movs r0, 0x2
	ands r0, r3
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0806DC5C
	ldrb r0, [r5, 0x2]
	cmp r0, 0xD2
	bne _0806DC5C
	adds r0, r7, 0
	bl sub_8042148
	adds r0, r7, 0
	adds r0, 0x22
	strb r4, [r0]
	ldrh r0, [r6, 0x10]
	movs r2, 0
	strh r0, [r6, 0xE]
	movs r3, 0xAC
	lsls r3, 1
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	mov r3, r8
	strb r3, [r0]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	movs r3, 0xA0
	lsls r3, 1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DC36
	ldr r0, _0806DC50
	ldr r1, [r0]
	ldr r3, _0806DC54
	adds r1, r3
	strb r2, [r1]
	ldr r0, [r0]
	ldr r1, _0806DC58
	adds r0, r1
	strb r2, [r0]
_0806DC36:
	strb r2, [r5, 0x2]
	strb r2, [r5, 0x1]
	strb r2, [r5]
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DC48
	b _0806DEC8
_0806DC48:
	b _0806DEE4
	.align 2, 0
_0806DC4C: .4byte gUnknown_80F9D28
_0806DC50: .4byte gDungeonGlobalData
_0806DC54: .4byte 0x00000679
_0806DC58: .4byte 0x00000676
_0806DC5C:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806DC64
	b _0806DDFC
_0806DC64:
	mov r10, r5
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0806DC72
	b _0806DDFC
_0806DC72:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806DC7C
	b _0806DDFC
_0806DC7C:
	ldrb r0, [r5, 0x2]
	cmp r0, 0xD8
	beq _0806DC84
	b _0806DDFC
_0806DC84:
	movs r4, 0
_0806DC86:
	ldr r0, _0806DD80
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _0806DD84
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806DCDE
	cmp r8, r7
	beq _0806DCDE
	adds r0, r7, 0
	mov r1, r8
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0806DCDE
	mov r3, r8
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806DCC4
	negs r1, r1
_0806DCC4:
	cmp r1, 0x1
	bgt _0806DCDE
	mov r3, r8
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0x6
	ldrsh r0, [r7, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806DCDA
	negs r1, r1
_0806DCDA:
	cmp r1, 0x1
	ble _0806DCE4
_0806DCDE:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806DC86
_0806DCE4:
	cmp r4, 0x4
	bne _0806DCEA
	b _0806DDFC
_0806DCEA:
	adds r0, r7, 0
	bl sub_8042148
	mov r3, r8
	ldr r4, [r3, 0x4]
	ldr r1, _0806DD88
	mov r0, r8
	adds r2, r7, 0
	bl sub_8068FE0
	lsls r1, r4, 16
	asrs r1, 16
	asrs r4, 16
	adds r0, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_80694C0
	adds r0, r7, 0
	movs r1, 0
	bl sub_804535C
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r6, 0x10]
	movs r4, 0
	strh r0, [r6, 0xE]
	adds r0, r7, 0
	bl sub_8042A24
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r6, r1
	strb r4, [r0]
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0x1
	strb r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r6, r3
	subs r2, 0xC
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DD62
	ldr r0, _0806DD80
	ldr r1, [r0]
	ldr r3, _0806DD8C
	adds r1, r3
	strb r4, [r1]
	ldr r0, [r0]
	ldr r1, _0806DD90
	adds r0, r1
	strb r4, [r0]
_0806DD62:
	mov r2, r10
	strb r4, [r2, 0x2]
	strb r4, [r2, 0x1]
	strb r4, [r2]
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DD94
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x3
	bl sub_807A5D0
	b _0806DDA2
	.align 2, 0
_0806DD80: .4byte gDungeonGlobalData
_0806DD84: .4byte 0x0001357c
_0806DD88: .4byte 0x00000221
_0806DD8C: .4byte 0x00000679
_0806DD90: .4byte 0x00000676
_0806DD94:
	cmp r0, 0x2
	bne _0806DDA2
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x2
	bl sub_807A5D0
_0806DDA2:
	adds r0, r7, 0
	bl sub_8078084
	adds r0, r6, 0
	movs r1, 0
	bl sub_806BFC0
	bl sub_800DBBC
	adds r0, r7, 0
	bl sub_806A390
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	adds r0, r7, 0
	bl DungeonEntityUpdateStatusSprites
	ldr r4, _0806DDF0
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806DDF4
	b _0806DF2E
	.align 2, 0
_0806DDF0: .4byte gAvailablePokemonNames
_0806DDF4: .4byte gUnknown_80FD484
_0806DDF8:
	mov r4, r8
	b _0806DE64
_0806DDFC:
	adds r0, r7, 0
	movs r1, 0x16
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0806DE0C
	b _0806DF48
_0806DE0C:
	movs r4, 0
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806DE28
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806DE28
	ldrb r0, [r5, 0x2]
	cmp r0, 0x3A
	bne _0806DE28
	adds r4, r5, 0
_0806DE28:
	cmp r4, 0
	bne _0806DE68
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _0806DE64
	movs r3, 0
	ldr r0, _0806DED4
	ldr r2, [r0]
	mov r12, r2
	movs r0, 0x1
	mov r10, r0
_0806DE3E:
	lsls r0, r3, 2
	add r0, r12
	mov r8, r0
	ldrb r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	beq _0806DE5C
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806DE5C
	ldrb r0, [r2, 0x2]
	cmp r0, 0x3A
	beq _0806DDF8
_0806DE5C:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _0806DE3E
_0806DE64:
	cmp r4, 0
	beq _0806DF48
_0806DE68:
	adds r0, r7, 0
	bl sub_8042148
	adds r0, r4, 0
	movs r1, 0x46
	movs r2, 0x2
	bl sub_8045C28
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r6, 0x10]
	movs r2, 0
	strh r0, [r6, 0xE]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r6, r1
	strb r2, [r0]
	movs r3, 0xA6
	lsls r3, 1
	adds r1, r6, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	subs r3, 0xC
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DEBE
	ldr r0, _0806DED8
	ldr r1, [r0]
	ldr r3, _0806DEDC
	adds r1, r3
	strb r2, [r1]
	ldr r0, [r0]
	ldr r1, _0806DEE0
	adds r0, r1
	strb r2, [r0]
_0806DEBE:
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DEE4
_0806DEC8:
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x3
	bl sub_807A5D0
	b _0806DEF2
	.align 2, 0
_0806DED4: .4byte gTeamInventory_203B460
_0806DED8: .4byte gDungeonGlobalData
_0806DEDC: .4byte 0x00000679
_0806DEE0: .4byte 0x00000676
_0806DEE4:
	cmp r0, 0x2
	bne _0806DEF2
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x2
	bl sub_807A5D0
_0806DEF2:
	adds r0, r7, 0
	bl sub_8078084
	adds r0, r6, 0
	movs r1, 0
	bl sub_806BFC0
	bl sub_800DBBC
	adds r0, r7, 0
	bl sub_806A390
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	adds r0, r7, 0
	bl DungeonEntityUpdateStatusSprites
	ldr r0, _0806DF40
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806DF44
_0806DF2E:
	ldr r1, [r0]
	mov r0, r9
	bl sub_805239C
	adds r0, r7, 0
	bl sub_806F63C
	bl _0806D608
	.align 2, 0
_0806DF40: .4byte gUnknown_202DFE8
_0806DF44: .4byte gUnknown_80FD46C
_0806DF48:
	ldrb r4, [r6, 0x7]
	cmp r4, 0
	bne _0806DF68
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806DF68
	adds r1, r7, 0x4
	adds r0, r7, 0
	adds r2, r5, 0
	bl sub_80464C8
	strb r4, [r5, 0x2]
	strb r4, [r5, 0x1]
	strb r4, [r5]
_0806DF68:
	adds r0, r6, 0
	adds r0, 0xF7
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DF7E
	ldr r0, _0806E02C
	ldr r0, [r0]
	ldr r2, _0806E030
	adds r0, r2
	ldr r1, _0806E034
	strh r1, [r0]
_0806DF7E:
	movs r3, 0
	mov r10, r3
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806E066
	mov r0, r9
	ldr r4, [r0, 0x70]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	ldrb r1, [r6, 0x9]
	bl CalculateEXPGain
	adds r5, r0, 0
	adds r0, r6, 0
	adds r0, 0xFB
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DFAE
	cmp r0, 0x2
	bne _0806DFB4
	lsls r0, r5, 1
	adds r5, r0, r5
_0806DFAE:
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_0806DFB4:
	cmp r5, 0
	bne _0806DFBA
	movs r5, 0x1
_0806DFBA:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _0806DFC8
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	bl sub_80980B4
_0806DFC8:
	adds r0, r6, 0
	adds r0, 0xF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DFDA
	ldr r3, _0806E038
	adds r1, r4, r3
	movs r0, 0x1
	strb r0, [r1]
_0806DFDA:
	ldr r0, [sp, 0x78]
	cmp r0, 0x1
	bne _0806E066
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _0806E040
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806E066
	mov r0, r9
	mov r1, r9
	adds r2, r5, 0
	bl sub_8071D4C
	movs r6, 0
_0806DFF8:
	ldr r0, _0806E02C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0806E03C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E020
	cmp r4, r9
	beq _0806E020
	mov r0, r9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8071D4C
_0806E020:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0806DFF8
	movs r3, 0x1
	mov r10, r3
	b _0806E066
	.align 2, 0
_0806E02C: .4byte gDungeonGlobalData
_0806E030: .4byte 0x0000066a
_0806E034: .4byte 0x000003e7
_0806E038: .4byte 0x0000014b
_0806E03C: .4byte 0x0001357c
_0806E040:
	ldr r5, _0806E0BC
	ldr r0, [r5]
	ldr r1, _0806E0C0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_809033C
	lsls r0, 24
	cmp r0, 0
	beq _0806E066
	ldr r2, _0806E0C4
	adds r0, r4, r2
	add r3, sp, 0x78
	ldrb r3, [r3]
	strb r3, [r0]
	ldr r0, [r5]
	add r1, sp, 0x78
	ldrb r1, [r1]
	strb r1, [r0, 0xD]
_0806E066:
	mov r0, r9
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E08A
	mov r0, r9
	bl GetEntityType
	cmp r0, 0x1
	bne _0806E08A
	mov r2, r9
	ldr r0, [r2, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _0806E08A
	movs r3, 0
	mov r10, r3
_0806E08A:
	mov r0, r10
	cmp r0, 0
	beq _0806E0E4
	add r0, sp, 0x4
	adds r1, r7, 0
	bl sub_8069D4C
	mov r0, r9
	adds r1, r7, 0
	bl sub_806F660
	lsls r0, 24
	cmp r0, 0
	beq _0806E0D8
	mov r0, r9
	adds r1, r7, 0
	add r2, sp, 0x4
	bl sub_806FA5C
	lsls r0, 24
	cmp r0, 0
	bne _0806E0CC
	ldr r1, _0806E0C8
	adds r0, r7, 0
	b _0806E0DC
	.align 2, 0
_0806E0BC: .4byte gDungeonGlobalData
_0806E0C0: .4byte 0x00000644
_0806E0C4: .4byte 0x00000149
_0806E0C8: .4byte 0x000001f5
_0806E0CC:
	ldr r1, _0806E0D4
	movs r0, 0x1
	strb r0, [r1]
	b _0806E0EE
	.align 2, 0
_0806E0D4: .4byte gUnknown_202F221
_0806E0D8:
	adds r0, r7, 0
	ldr r1, [sp, 0x50]
_0806E0DC:
	mov r2, r9
	bl sub_8068FE0
	b _0806E0EE
_0806E0E4:
	adds r0, r7, 0
	ldr r1, [sp, 0x50]
	mov r2, r9
	bl sub_8068FE0
_0806E0EE:
	movs r0, 0x1
_0806E0F0:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806D528

	thumb_func_start sub_806E100
sub_806E100:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r6, r0, 0
	mov r8, r1
	str r2, [sp, 0x18]
	lsls r3, 24
	lsrs r7, r3, 24
	movs r0, 0
	mov r9, r0
	movs r1, 0
	str r1, [sp, 0x20]
	mov r2, r8
	ldr r2, [r2, 0x70]
	str r2, [sp, 0x24]
	ldr r3, [sp, 0x18]
	ldr r3, [r3, 0x70]
	mov r10, r3
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_800A020
	mov r0, r9
	ldr r4, [sp, 0x48]
	strb r0, [r4, 0xD]
	strb r0, [r4, 0xE]
	movs r1, 0
	str r1, [sp, 0x1C]
	ldr r0, [sp, 0x18]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806E14E
	movs r0, 0x1
	b _0806E61A
_0806E14E:
	cmp r7, 0x1
	beq _0806E156
	cmp r7, 0x7
	bne _0806E15A
_0806E156:
	movs r2, 0x1
	str r2, [sp, 0x20]
_0806E15A:
	ldr r0, [sp, 0x18]
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E170
	cmp r7, 0
	beq _0806E170
	movs r3, 0x1
	str r3, [sp, 0x1C]
_0806E170:
	movs r0, 0x2
	ldr r4, [sp, 0x48]
	str r0, [r4, 0x8]
	movs r5, 0
	add r0, sp, 0x10
	mov r9, r0
	b _0806E1F2
_0806E17E:
	mov r1, r10
	adds r1, 0x5C
	ldr r2, [sp, 0x20]
	cmp r2, 0
	beq _0806E1B4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _0806E1B4
	mov r0, r10
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806E1B4
	movs r4, 0
	ldr r0, _0806E1AC
	ldr r0, [r0]
	ldr r3, _0806E1B0
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	b _0806E1CA
	.align 2, 0
_0806E1AC: .4byte gDungeonGlobalData
_0806E1B0: .4byte 0x00000179
_0806E1B4:
	ldr r2, _0806E4E4
	adds r0, r1, r5
	ldrb r1, [r0]
	lsls r1, 1
	lsls r0, r7, 3
	adds r0, r7
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	movs r0, 0
	ldrsh r4, [r1, r0]
_0806E1CA:
	cmp r4, 0x2
	beq _0806E1DC
	lsls r0, r4, 2
	add r0, sp
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E1DC:
	lsls r0, r5, 2
	add r0, r9
	str r4, [r0]
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r1
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0806E1F2:
	cmp r5, 0x1
	bgt _0806E20E
	mov r1, sp
	ldr r0, _0806E4EC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0806E17E
_0806E20E:
	ldr r2, _0806E4F0
	mov r1, r9
	ldr r0, [r1, 0x4]
	lsls r0, 2
	ldr r1, [sp, 0x10]
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [sp, 0x48]
	str r0, [r2, 0x8]
	movs r3, 0x1
	mov r9, r3
	cmp r0, 0x3
	beq _0806E240
	movs r4, 0
	mov r9, r4
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	beq _0806E240
	ldr r0, _0806E4F4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r6]
	str r1, [r6, 0x4]
_0806E240:
	cmp r7, 0x2
	beq _0806E248
	cmp r7, 0x6
	bne _0806E26C
_0806E248:
	ldr r0, [sp, 0x18]
	movs r1, 0x2
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E26C
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r2, _0806E4F8
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E4FC
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E26C:
	cmp r7, 0x2
	bne _0806E2A0
	ldr r0, [sp, 0x18]
	bl GetFlashFireStatus
	lsls r0, 24
	cmp r0, 0
	beq _0806E2A0
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r3, 0xB7
	lsls r3, 1
	adds r0, r3
	movs r4, 0
	movs r5, 0x1
	strb r5, [r0]
	adds r0, r6, 0
	movs r1, 0
	bl sub_800A020
	ldr r0, [sp, 0x48]
	str r4, [r0, 0x8]
	strb r4, [r0, 0xD]
	strb r5, [r0, 0xE]
	movs r1, 0
	mov r9, r1
_0806E2A0:
	cmp r7, 0x9
	bne _0806E2D2
	ldr r0, [sp, 0x18]
	movs r1, 0x37
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E2D2
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r2, _0806E500
	adds r0, r2
	movs r4, 0
	movs r5, 0x1
	strb r5, [r0]
	adds r0, r6, 0
	movs r1, 0
	bl sub_800A020
	ldr r3, [sp, 0x48]
	str r4, [r3, 0x8]
	strb r4, [r3, 0xD]
	strb r5, [r3, 0xE]
	mov r9, r4
_0806E2D2:
	cmp r7, 0x3
	bne _0806E340
	mov r0, r8
	movs r1, 0x10
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E340
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E2F2
	adds r1, 0x3
_0806E2F2:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E300
	movs r4, 0x1
_0806E300:
	ldr r0, [sp, 0x24]
	movs r1, 0x80
	adds r2, r4, 0
	bl SetVisualFlags
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E32A
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E32A:
	cmp r5, 0
	beq _0806E340
	mov r0, r8
	bl sub_80428EC
	ldr r0, _0806E508
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E340:
	cmp r7, 0x4
	bne _0806E3AC
	mov r0, r8
	movs r1, 0x1A
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E3AC
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E360
	adds r1, 0x3
_0806E360:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E36E
	movs r4, 0x1
_0806E36E:
	ldr r0, [sp, 0x24]
	movs r1, 0x2
	adds r2, r4, 0
	bl SetVisualFlags
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E396
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r3, _0806E50C
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E396:
	cmp r5, 0
	beq _0806E3AC
	mov r0, r8
	bl sub_80428D8
	ldr r0, _0806E510
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E3AC:
	cmp r7, 0xC
	bne _0806E41A
	mov r0, r8
	movs r1, 0x43
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E41A
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E3CC
	adds r1, 0x3
_0806E3CC:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E3DA
	movs r4, 0x1
_0806E3DA:
	ldr r0, [sp, 0x24]
	movs r1, 0x10
	adds r2, r4, 0
	bl SetVisualFlags
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E404
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r3, 0xB9
	lsls r3, 1
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E404:
	cmp r5, 0
	beq _0806E41A
	mov r0, r8
	bl sub_8042978
	ldr r0, _0806E514
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E41A:
	cmp r7, 0x2
	bne _0806E486
	mov r0, r8
	movs r1, 0x46
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E486
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E43A
	adds r1, 0x3
_0806E43A:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E448
	movs r4, 0x1
_0806E448:
	ldr r0, [sp, 0x24]
	movs r1, 0x20
	adds r2, r4, 0
	bl SetVisualFlags
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E470
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r3, _0806E518
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E470:
	cmp r5, 0
	beq _0806E486
	mov r0, r8
	bl sub_804298C
	ldr r0, _0806E51C
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E486:
	adds r0, r6, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	bne _0806E4B8
	mov r0, r8
	adds r1, r7, 0
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _0806E4B8
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r4, 0xBA
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0806E520
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E4B8:
	mov r0, r8
	bl GetWeather
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0806E53E
	cmp r7, 0x2
	bne _0806E524
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	strb r4, [r0]
	ldr r2, _0806E520
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
	b _0806E53E
	.align 2, 0
_0806E4E4: .4byte gTypeEffectivenessChart
_0806E4E8: .4byte gDungeonGlobalData
_0806E4EC: .4byte gUnknown_8106F54
_0806E4F0: .4byte gUnknown_80F54B4
_0806E4F4: .4byte gUnknown_8106EFC
_0806E4F8: .4byte 0x0000016d
_0806E4FC: .4byte gUnknown_8106F1C
_0806E500: .4byte 0x0000016f
_0806E504: .4byte gUnknown_8106F0C
_0806E508: .4byte gUnknown_80FEDA8
_0806E50C: .4byte 0x00000171
_0806E510: .4byte gUnknown_80FED88
_0806E514: .4byte gUnknown_80FEDC8
_0806E518: .4byte 0x00000173
_0806E51C: .4byte gUnknown_80FEDE8
_0806E520: .4byte gUnknown_8106F14
_0806E524:
	cmp r7, 0x3
	bne _0806E53E
	ldr r0, _0806E560
	ldr r0, [r0]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	strb r4, [r0]
	ldr r2, _0806E564
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E53E:
	cmp r4, 0x4
	bne _0806E586
	cmp r7, 0x2
	bne _0806E56C
	ldr r0, _0806E560
	ldr r0, [r0]
	ldr r3, _0806E568
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E564
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
	b _0806E586
	.align 2, 0
_0806E560: .4byte gDungeonGlobalData
_0806E564: .4byte gUnknown_8106F1C
_0806E568: .4byte 0x0000016b
_0806E56C:
	cmp r7, 0x3
	bne _0806E586
	ldr r0, _0806E62C
	ldr r0, [r0]
	ldr r2, _0806E630
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E634
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E586:
	cmp r4, 0x3
	bne _0806E5A6
	cmp r7, 0x1
	beq _0806E5A6
	ldr r2, _0806E638
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
	ldr r0, _0806E62C
	ldr r0, [r0]
	movs r3, 0xB5
	lsls r3, 1
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
_0806E5A6:
	ldr r0, _0806E62C
	ldr r1, [r0]
	ldr r2, _0806E63C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806E5B8
	cmp r4, 0x6
	bne _0806E5CE
_0806E5B8:
	cmp r7, 0x5
	bne _0806E5CE
	ldr r3, _0806E640
	adds r1, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E644
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E5CE:
	ldr r0, _0806E62C
	ldr r1, [r0]
	ldr r4, _0806E648
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806E5F4
	cmp r7, 0x2
	bne _0806E5F4
	movs r0, 0xBB
	lsls r0, 1
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E644
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E5F4:
	cmp r7, 0x5
	bne _0806E618
	ldr r0, [sp, 0x24]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0xB
	bne _0806E618
	ldr r0, _0806E62C
	ldr r0, [r0]
	ldr r2, _0806E64C
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E650
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E618:
	mov r0, r9
_0806E61A:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806E62C: .4byte gDungeonGlobalData
_0806E630: .4byte 0x0000016b
_0806E634: .4byte gUnknown_8106F14
_0806E638: .4byte gUnknown_8106F64
_0806E63C: .4byte 0x0000e277
_0806E640: .4byte 0x00000175
_0806E644: .4byte gUnknown_8106F1C
_0806E648: .4byte 0x0000e278
_0806E64C: .4byte 0x00000177
_0806E650: .4byte gUnknown_8106F0C
	thumb_func_end sub_806E100

	thumb_func_start WeightWeakTypePicker
WeightWeakTypePicker:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r9, r0
	str r1, [sp, 0x14]
	lsls r2, 24
	lsrs r4, r2, 24
	movs r5, 0x1
	movs r0, 0
	str r0, [sp, 0x10]
	adds r0, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E6DC
	cmp r4, 0x1
	beq _0806E682
	cmp r4, 0x7
	bne _0806E686
_0806E682:
	movs r1, 0x1
	str r1, [sp, 0x10]
_0806E686:
	mov r2, r9
	ldr r2, [r2, 0x70]
	mov r8, r2
	ldr r3, [sp, 0x14]
	ldr r3, [r3, 0x70]
	mov r10, r3
	cmp r4, 0x2
	bne _0806E6A2
	ldr r0, [sp, 0x14]
	bl GetFlashFireStatus
	lsls r0, 24
	cmp r0, 0
	bne _0806E6C6
_0806E6A2:
	cmp r4, 0x5
	bne _0806E6B4
	ldr r0, [sp, 0x14]
	movs r1, 0x23
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806E6C6
_0806E6B4:
	cmp r4, 0x3
	bne _0806E6CA
	ldr r0, [sp, 0x14]
	movs r1, 0x24
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E6CA
_0806E6C6:
	movs r0, 0
	b _0806E894
_0806E6CA:
	cmp r4, 0x9
	bne _0806E6E0
	ldr r0, [sp, 0x14]
	movs r1, 0x37
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E6E0
_0806E6DC:
	movs r0, 0x1
	b _0806E894
_0806E6E0:
	mov r6, r10
	adds r6, 0x5C
	str r6, [sp, 0x18]
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	mov r12, r0
	adds r2, r6, 0
_0806E6F0:
	mov r0, sp
	ldr r1, _0806E724
	ldm r1!, {r3,r6,r7}
	stm r0!, {r3,r6,r7}
	ldr r1, [r1]
	str r1, [r0]
	ldr r7, [sp, 0x10]
	cmp r7, 0
	beq _0806E730
	ldrb r0, [r2]
	cmp r0, 0xE
	bne _0806E730
	mov r0, r10
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806E730
	movs r3, 0
	ldr r0, _0806E728
	ldr r0, [r0]
	ldr r6, _0806E72C
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
	b _0806E73E
	.align 2, 0
_0806E724: .4byte gTypeEffectivenessMultipliers
_0806E728: .4byte gDungeonGlobalData
_0806E72C: .4byte 0x00000179
_0806E730:
	ldrb r0, [r2]
	lsls r0, 1
	add r0, r12
	ldr r7, _0806E854
	adds r0, r7
	movs r1, 0
	ldrsh r3, [r0, r1]
_0806E73E:
	cmp r5, 0
	beq _0806E75E
	lsls r0, r3, 2
	add r0, sp
	ldr r0, [r0]
	muls r5, r0
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
	cmp r5, 0
	beq _0806E84E
	adds r2, 0x1
	ldr r0, [sp, 0x18]
	adds r0, 0x1
	cmp r2, r0
	ble _0806E6F0
_0806E75E:
	cmp r4, 0x2
	beq _0806E766
	cmp r4, 0x6
	bne _0806E774
_0806E766:
	ldr r0, [sp, 0x14]
	movs r1, 0x2
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806E84E
_0806E774:
	cmp r4, 0x3
	bne _0806E7A0
	mov r0, r9
	movs r1, 0x10
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E7A0
	mov r2, r8
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	cmp r1, 0
	bge _0806E792
	adds r1, 0x3
_0806E792:
	asrs r1, 2
	mov r6, r8
	movs r7, 0xE
	ldrsh r0, [r6, r7]
	cmp r1, r0
	blt _0806E7A0
	lsls r5, 1
_0806E7A0:
	cmp r4, 0x4
	bne _0806E7CC
	mov r0, r9
	movs r1, 0x1A
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E7CC
	mov r0, r8
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E7BE
	adds r1, 0x3
_0806E7BE:
	asrs r1, 2
	mov r3, r8
	movs r6, 0xE
	ldrsh r0, [r3, r6]
	cmp r1, r0
	blt _0806E7CC
	lsls r5, 1
_0806E7CC:
	cmp r4, 0xC
	bne _0806E7F8
	mov r0, r9
	movs r1, 0x43
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E7F8
	mov r7, r8
	movs r0, 0x10
	ldrsh r1, [r7, r0]
	cmp r1, 0
	bge _0806E7EA
	adds r1, 0x3
_0806E7EA:
	asrs r1, 2
	mov r2, r8
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _0806E7F8
	lsls r5, 1
_0806E7F8:
	cmp r4, 0x2
	bne _0806E824
	mov r0, r9
	movs r1, 0x46
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E824
	mov r6, r8
	movs r7, 0x10
	ldrsh r1, [r6, r7]
	cmp r1, 0
	bge _0806E816
	adds r1, 0x3
_0806E816:
	asrs r1, 2
	mov r2, r8
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _0806E824
	lsls r5, 1
_0806E824:
	cmp r5, 0
	beq _0806E84E
	mov r0, r9
	adds r1, r4, 0
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _0806E838
	lsls r5, 1
_0806E838:
	mov r0, r9
	bl GetWeather
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0806E85A
	cmp r4, 0x2
	beq _0806E858
	cmp r4, 0x3
	bne _0806E85A
_0806E84E:
	movs r0, 0x2
	b _0806E894
	.align 2, 0
_0806E854: .4byte gTypeEffectivenessChart
_0806E858:
	lsls r5, 1
_0806E85A:
	ldr r0, _0806E8A4
	ldr r1, [r0]
	ldr r6, _0806E8A8
	adds r1, r6
	ldrb r1, [r1]
	cmp r1, 0
	beq _0806E86C
	cmp r4, 0x5
	beq _0806E84E
_0806E86C:
	ldr r0, [r0]
	ldr r7, _0806E8AC
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806E87C
	cmp r4, 0x2
	beq _0806E84E
_0806E87C:
	cmp r4, 0x5
	bne _0806E88C
	mov r0, r8
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0xB
	bne _0806E88C
	lsls r5, 1
_0806E88C:
	cmp r5, 0x2
	ble _0806E892
	movs r5, 0x3
_0806E892:
	adds r0, r5, 0x2
_0806E894:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806E8A4: .4byte gDungeonGlobalData
_0806E8A8: .4byte 0x0000e277
_0806E8AC: .4byte 0x0000e278
	thumb_func_end WeightWeakTypePicker

	thumb_func_start sub_806E8B0
sub_806E8B0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r6, r0, 0
	mov r9, r1
	adds r0, r2, 0
	str r3, [sp]
	lsls r0, 24
	lsrs r0, 24
	movs r7, 0x1
	movs r1, 0x1
	mov r8, r1
	movs r2, 0x1
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	bl sub_8092354
	movs r2, 0
	mov r10, r2
	lsls r0, 24
	cmp r0, 0
	bne _0806E8E6
	movs r0, 0x1
	mov r10, r0
_0806E8E6:
	adds r0, r6, 0
	movs r1, 0x11
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E92C
	ldr r5, [r6, 0x70]
	adds r0, r6, 0
	bl HasNegativeStatus
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl SetVisualFlags
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0
	beq _0806E916
	movs r7, 0x2
_0806E916:
	cmp r0, 0
	beq _0806E92C
	adds r0, r6, 0
	bl sub_80428B0
	ldr r0, _0806EADC
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
_0806E92C:
	adds r0, r6, 0
	movs r1, 0x22
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806E948
	adds r0, r6, 0
	movs r1, 0x4B
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E98E
_0806E948:
	ldr r2, [r6, 0x70]
	movs r4, 0
	ldr r0, [sp, 0x30]
	cmp r0, 0x20
	bgt _0806E95A
	mov r1, r10
	cmp r1, 0
	bne _0806E95A
	movs r4, 0x1
_0806E95A:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r2, 0
	adds r2, r4, 0
	bl SetVisualFlags
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0
	beq _0806E978
	lsls r0, r7, 1
	adds r7, r0, r7
	mov r2, r8
	lsls r2, 1
	mov r8, r2
_0806E978:
	cmp r1, 0
	beq _0806E98E
	adds r0, r6, 0
	bl sub_80428C4
	ldr r0, _0806EAE0
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
_0806E98E:
	adds r0, r6, 0
	movs r1, 0x30
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E9AC
	mov r0, r10
	cmp r0, 0
	bne _0806E9AC
	lsls r0, r7, 1
	adds r7, r0, r7
	mov r1, r8
	lsls r1, 1
	mov r8, r1
_0806E9AC:
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x6]
	movs r4, 0x1
	cmp r0, 0
	beq _0806E9B8
	movs r4, 0
_0806E9B8:
	adds r0, r6, 0
	movs r1, 0x38
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806E9EA
	mov r2, r10
	cmp r2, 0x1
	bne _0806E9EA
	ldr r0, _0806EAE4
	ldr r0, [r0]
	ldr r1, _0806EAE8
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806E9EA
	lsls r0, r7, 4
	subs r7, r0, r7
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 1
	mov r8, r0
_0806E9EA:
	adds r0, r6, 0
	movs r1, 0x3F
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806EA1C
	mov r0, r10
	cmp r0, 0x1
	bne _0806EA1C
	ldr r0, _0806EAE4
	ldr r0, [r0]
	ldr r1, _0806EAEC
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806EA1C
	lsls r0, r7, 4
	subs r7, r0, r7
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 1
	mov r8, r0
_0806EA1C:
	mov r0, r9
	movs r1, 0x6
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806EA38
	mov r0, r10
	cmp r0, 0
	bne _0806EA38
	lsls r7, 2
	mov r1, r8
	lsls r0, r1, 2
	add r8, r0
_0806EA38:
	mov r0, r9
	movs r1, 0x34
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806EA90
	mov r2, r10
	cmp r2, 0
	bne _0806EA90
	mov r0, r9
	ldr r5, [r0, 0x70]
	bl HasNegativeStatus
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x8
	adds r2, r4, 0
	bl SetVisualFlags
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0
	beq _0806EA7A
	ldr r2, [sp, 0x4]
	lsls r0, r2, 1
	adds r2, r0, r2
	str r2, [sp, 0x4]
	ldr r0, [sp, 0x8]
	lsls r0, 1
	str r0, [sp, 0x8]
_0806EA7A:
	cmp r1, 0
	beq _0806EA90
	mov r0, r9
	bl sub_8042940
	ldr r0, _0806EAF0
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
_0806EA90:
	ldr r1, [sp]
	ldr r0, [r1]
	muls r0, r7
	str r0, [r1]
	ldr r2, [sp, 0x2C]
	ldr r0, [r2]
	ldr r1, [sp, 0x4]
	muls r0, r1
	str r0, [r2]
	mov r2, r8
	cmp r2, 0x1
	beq _0806EAB6
	ldr r1, [sp]
	ldr r0, [r1]
	mov r1, r8
	bl __divsi3
	ldr r2, [sp]
	str r0, [r2]
_0806EAB6:
	ldr r0, [sp, 0x8]
	cmp r0, 0x1
	beq _0806EACA
	ldr r1, [sp, 0x2C]
	ldr r0, [r1]
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r2, [sp, 0x2C]
	str r0, [r2]
_0806EACA:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806EADC: .4byte gUnknown_80FEE04
_0806EAE0: .4byte gUnknown_80FEE2C
_0806EAE4: .4byte gDungeonGlobalData
_0806EAE8: .4byte 0x000037fa
_0806EAEC: .4byte 0x000037f8
_0806EAF0: .4byte gUnknown_80FEE54
	thumb_func_end sub_806E8B0

	thumb_func_start sub_806EAF4
sub_806EAF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8C
	str r0, [sp, 0x70]
	mov r9, r1
	adds r7, r3, 0
	ldr r0, [sp, 0xB8]
	ldr r1, [sp, 0xBC]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x74]
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x78]
	ldr r0, [sp, 0x70]
	ldr r0, [r0, 0x70]
	mov r10, r0
	mov r1, r9
	ldr r1, [r1, 0x70]
	str r1, [sp, 0x7C]
	adds r0, r2, 0
	bl sub_8092354
	movs r2, 0
	str r2, [sp, 0x80]
	lsls r0, 24
	cmp r0, 0
	bne _0806EB3A
	movs r3, 0x1
	str r3, [sp, 0x80]
_0806EB3A:
	bl sub_806F500
	mov r6, r10
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806EB72
	movs r0, 0x9E
	lsls r0, 1
	add r0, r10
	ldr r0, [r0]
	bl GetBellyRoundedUp
	adds r1, r0, 0
	cmp r1, 0
	bne _0806EB72
	movs r0, 0x1
	ldr r2, [sp, 0xB0]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x2
	str r0, [r2, 0x8]
	add r3, sp, 0x74
	ldrb r3, [r3]
	strb r3, [r2, 0xC]
	strb r1, [r2, 0xD]
	strb r1, [r2, 0xE]
	strb r1, [r2, 0xF]
	b _0806F294
_0806EB72:
	ldr r0, _0806EBA4
	cmp r4, r0
	bne _0806EBA8
	mov r0, r9
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806EBA8
	movs r0, 0x1
	ldr r6, [sp, 0xB0]
	str r0, [r6]
	movs r1, 0
	str r1, [r6, 0x4]
	movs r0, 0x2
	str r0, [r6, 0x8]
	add r0, sp, 0x74
	ldrb r0, [r0]
	strb r0, [r6, 0xC]
	strb r1, [r6, 0xD]
	strb r1, [r6, 0xE]
	strb r1, [r6, 0xF]
	b _0806F294
	.align 2, 0
_0806EBA4: .4byte 0x00000163
_0806EBA8:
	add r1, sp, 0x74
	ldrb r2, [r1]
	ldr r1, [sp, 0xB0]
	strb r2, [r1, 0xC]
	ldr r1, _0806EDA4
	ldr r0, [r1]
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	add r3, sp, 0x74
	ldrb r3, [r3]
	strb r3, [r0]
	ldr r2, [r1]
	movs r6, 0x9C
	lsls r6, 1
	adds r0, r2, r6
	ldr r1, [sp, 0x80]
	str r1, [r0]
	lsls r1, 1
	mov r0, r10
	adds r0, 0x1C
	adds r0, r1
	movs r3, 0
	ldrsh r4, [r0, r3]
	mov r8, r1
	ldr r6, [sp, 0x78]
	cmp r6, 0
	beq _0806EBF8
	ldr r0, [sp, 0x74]
	cmp r0, 0x2
	bne _0806EBF8
	mov r1, r10
	movs r3, 0x28
	ldrsh r0, [r1, r3]
	adds r4, r0
	ldrh r1, [r1, 0x28]
	movs r6, 0xA2
	lsls r6, 1
	adds r0, r2, r6
	strh r1, [r0]
_0806EBF8:
	mov r0, r10
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r0, _0806EDA8
	cmp r1, r0
	bne _0806EC06
	adds r4, 0x2
_0806EC06:
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0806EC10
	subs r4, 0x2
_0806EC10:
	ldr r0, _0806EDAC
	cmp r1, r0
	bne _0806EC18
	subs r4, 0x2
_0806EC18:
	cmp r4, 0
	bge _0806EC1E
	movs r4, 0
_0806EC1E:
	cmp r4, 0x14
	ble _0806EC24
	movs r4, 0x14
_0806EC24:
	ldr r6, _0806EDA4
	ldr r0, [r6]
	movs r3, 0x9F
	lsls r3, 1
	adds r0, r3
	strb r4, [r0]
	ldr r1, [r6]
	mov r5, r10
	adds r5, 0x14
	ldr r0, [sp, 0x80]
	adds r2, r5, r0
	ldrb r0, [r2]
	adds r0, r7
	adds r3, 0x2
	adds r1, r3
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, r7
	lsls r0, 8
	ldr r2, _0806EDB0
	lsls r1, r4, 2
	adds r1, r2
	ldr r1, [r1]
	bl sub_8009DA4
	adds r2, r0, 0
	ldr r0, [sp, 0x80]
	lsls r4, r0, 2
	mov r0, r10
	adds r0, 0x2C
	adds r0, r4
	ldr r1, [r0]
	adds r0, r2, 0
	bl sub_8009DA4
	adds r2, r0, 0
	str r5, [sp, 0x88]
	cmp r2, 0
	bge _0806EC74
	adds r0, 0xFF
_0806EC74:
	asrs r0, 8
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x7C]
	adds r0, 0x20
	add r0, r8
	movs r1, 0
	ldrsh r3, [r0, r1]
	ldr r2, [sp, 0x80]
	cmp r2, 0
	bne _0806ECA0
	ldr r0, [sp, 0x7C]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _0806ECA0
	ldr r0, [r6]
	movs r6, 0xBD
	lsls r6, 1
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
	adds r3, 0x1
_0806ECA0:
	ldr r0, [sp, 0x7C]
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r0, _0806EDA8
	cmp r1, r0
	bne _0806ECAE
	subs r3, 0x2
_0806ECAE:
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0806ECB8
	adds r3, 0x2
_0806ECB8:
	ldr r0, _0806EDAC
	cmp r1, r0
	bne _0806ECC0
	subs r3, 0x2
_0806ECC0:
	cmp r3, 0
	bge _0806ECC6
	movs r3, 0
_0806ECC6:
	cmp r3, 0x14
	ble _0806ECCC
	movs r3, 0x14
_0806ECCC:
	ldr r5, _0806EDA4
	ldr r0, [r5]
	ldr r6, _0806EDB4
	adds r0, r6
	strb r3, [r0]
	ldr r2, [r5]
	ldr r0, [sp, 0x7C]
	adds r0, 0x16
	ldr r1, [sp, 0x80]
	adds r0, r1
	ldrb r1, [r0]
	adds r6, 0x3
	adds r2, r6
	strh r1, [r2]
	ldrb r0, [r0]
	lsls r0, 8
	ldr r2, _0806EDB8
	lsls r1, r3, 2
	adds r1, r2
	ldr r1, [r1]
	bl sub_8009DA4
	adds r2, r0, 0
	ldr r0, [sp, 0x7C]
	adds r0, 0x34
	adds r0, r4
	ldr r1, [r0]
	adds r0, r2, 0
	bl sub_8009DA4
	cmp r0, 0
	bge _0806ED0E
	adds r0, 0xFF
_0806ED0E:
	asrs r0, 8
	str r0, [sp, 0xC]
	movs r0, 0x64
	bl DungeonRandomCapped
	str r0, [sp, 0x84]
	ldr r0, [sp, 0x80]
	cmp r0, 0
	bne _0806EDC8
	ldr r0, [sp, 0x70]
	movs r1, 0x13
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806ED4A
	ldr r2, _0806EDBC
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r5]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806ED4A:
	ldr r0, [sp, 0x70]
	movs r1, 0x2B
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806ED74
	ldr r2, _0806EDC0
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r5]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806ED74:
	ldr r3, [sp, 0x78]
	cmp r3, 0
	beq _0806EE4A
	mov r0, r9
	movs r1, 0x1E
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EE4A
	ldr r2, _0806EDC4
	movs r6, 0
	ldrsh r1, [r2, r6]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r5]
	movs r3, 0xB1
	lsls r3, 1
	adds r1, r0, r3
	ldrb r0, [r2]
	ldrb r6, [r1]
	adds r0, r6
	b _0806EE48
	.align 2, 0
_0806EDA4: .4byte gDungeonGlobalData
_0806EDA8: .4byte 0x000001a1
_0806EDAC: .4byte 0x000001a3
_0806EDB0: .4byte gUnknown_80F504C
_0806EDB4: .4byte 0x0000013f
_0806EDB8: .4byte gUnknown_80F50A0
_0806EDBC: .4byte gUnknown_810AC60
_0806EDC0: .4byte gUnknown_810AC68
_0806EDC4: .4byte gUnknown_810AC64
_0806EDC8:
	ldr r0, [sp, 0x78]
	cmp r0, 0
	beq _0806EDF6
	mov r0, r9
	movs r1, 0x22
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EDF6
	ldr r2, _0806EEF8
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r5]
	ldr r6, _0806EEFC
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806EDF6:
	ldr r0, [sp, 0x70]
	movs r1, 0x21
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EE20
	ldr r2, _0806EF00
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r0, _0806EF04
	ldr r0, [r0]
	ldr r6, _0806EF08
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806EE20:
	ldr r0, [sp, 0x70]
	movs r1, 0x2B
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EE4A
	ldr r2, _0806EF0C
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r0, _0806EF04
	ldr r0, [r0]
	ldr r6, _0806EF08
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
_0806EE48:
	strb r0, [r1]
_0806EE4A:
	ldr r0, _0806EF04
	ldr r2, [r0]
	movs r3, 0xA3
	lsls r3, 1
	adds r1, r2, r3
	add r0, sp, 0x8
	ldrh r0, [r0]
	strh r0, [r1]
	movs r6, 0xA4
	lsls r6, 1
	adds r1, r2, r6
	add r4, sp, 0xC
	ldrh r0, [r4]
	strh r0, [r1]
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bge _0806EE70
	movs r0, 0
	str r0, [sp, 0x8]
_0806EE70:
	ldr r1, _0806EF10
	ldr r0, [sp, 0x8]
	cmp r0, r1
	ble _0806EE7C
	ldr r0, _0806EF14
	str r0, [sp, 0x8]
_0806EE7C:
	movs r3, 0xA8
	lsls r3, 1
	add r3, r10
	ldrh r2, [r3]
	ldr r1, _0806EF18
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r3]
	movs r2, 0xA7
	lsls r2, 1
	add r2, r10
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	str r4, [sp]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x70]
	mov r1, r9
	ldr r2, [sp, 0x74]
	add r3, sp, 0x8
	bl sub_806E8B0
	add r5, sp, 0x10
	ldr r1, [sp, 0x8]
	ldr r0, [sp, 0xC]
	subs r1, r0
	adds r0, r5, 0
	bl sub_800A020
	add r4, sp, 0x18
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_800A020
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_800A3F0
	mov r1, r10
	ldrb r6, [r1, 0x6]
	mov r8, r5
	adds r7, r4, 0
	cmp r6, 0
	bne _0806EF20
	ldrb r1, [r1, 0x9]
	adds r0, r7, 0
	bl sub_800A020
	str r6, [sp, 0x20]
	ldr r0, _0806EF1C
	add r2, sp, 0x20
	str r0, [r2, 0x4]
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	mov r2, r10
	ldrb r0, [r2, 0x9]
	lsls r0, 1
	b _0806EF60
	.align 2, 0
_0806EEF8: .4byte gUnknown_810AC66
_0806EEFC: .4byte 0x00000163
_0806EF00: .4byte gUnknown_810AC62
_0806EF04: .4byte gDungeonGlobalData
_0806EF08: .4byte 0x00000161
_0806EF0C: .4byte gUnknown_810AC68
_0806EF10: .4byte 0x000003e6
_0806EF14: .4byte 0x000003e7
_0806EF18: .4byte 0x0000feff
_0806EF1C: .4byte 0x0000aaaa
_0806EF20:
	ldr r3, [sp, 0x88]
	ldr r6, [sp, 0x80]
	adds r0, r3, r6
	ldrb r0, [r0]
	str r0, [sp, 0x28]
	movs r0, 0x1
	str r0, [sp, 0x2C]
	add r3, sp, 0x28
	add r0, sp, 0x2C
	str r0, [sp]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x70]
	mov r1, r9
	ldr r2, [sp, 0x74]
	bl sub_806E8B0
	ldr r1, [sp, 0x28]
	adds r0, r7, 0
	bl sub_800A020
	add r4, sp, 0x20
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_800A020
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_800A3F0
	ldr r0, [sp, 0x28]
_0806EF60:
	movs r1, 0x3
	bl __divsi3
	adds r6, r0, 0
	add r5, sp, 0x30
	adds r0, r5, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A6D0
	ldr r4, _0806F098
	ldr r0, [r4]
	movs r1, 0xA5
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	mov r8, r2
	strh r6, [r0]
	adds r0, r5, 0
	bl sub_800A048
	ldr r1, [r4]
	movs r3, 0xA6
	lsls r3, 1
	adds r1, r3
	strh r0, [r1]
	ldr r0, [sp, 0x30]
	ldr r1, [sp, 0x34]
	str r0, [sp, 0x38]
	str r1, [sp, 0x3C]
	str r0, [sp, 0x48]
	str r1, [sp, 0x4C]
	add r6, sp, 0x38
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r6, 0
	bl sub_800A34C
	mov r0, r8
	str r0, [sp, 0x40]
	ldr r0, _0806F09C
	add r5, sp, 0x40
	str r0, [r5, 0x4]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_800A34C
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_800A020
	add r4, sp, 0x48
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A34C
	ldr r1, [sp, 0xC]
	adds r0, r5, 0
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A6F0
	adds r0, r5, 0
	movs r1, 0xA
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A6D0
	add r5, sp, 0x50
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_800A6D0
	ldr r4, _0806F0A0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800A2F0
	lsls r0, 24
	mov r8, r5
	cmp r0, 0
	beq _0806F01E
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
_0806F01E:
	ldr r4, _0806F0A4
	mov r0, r8
	adds r1, r4, 0
	bl sub_800A2F0
	lsls r0, 24
	cmp r0, 0
	beq _0806F036
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
_0806F036:
	add r4, sp, 0x58
	ldr r1, [sp, 0xB0]
	str r1, [sp]
	adds r0, r4, 0
	ldr r1, [sp, 0x70]
	mov r2, r9
	ldr r3, [sp, 0x74]
	bl sub_806E100
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r4, 0
	ldr r2, [sp, 0x74]
	cmp r2, 0x2
	bne _0806F0BC
	mov r0, r9
	bl GetFlashFireStatus
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0806F0BC
	ldr r3, [sp, 0x7C]
	movs r6, 0xA9
	lsls r6, 1
	adds r1, r3, r6
	ldrb r0, [r1]
	cmp r0, 0
	bne _0806F0BC
	ldr r0, [sp, 0x78]
	cmp r0, 0
	beq _0806F118
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0806F0A8
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	cmp r4, 0x1
	bne _0806F0B0
	ldr r0, _0806F0AC
	ldr r2, [r0]
	ldr r0, [sp, 0x70]
	mov r1, r9
	bl sub_80522F4
	b _0806F0BC
	.align 2, 0
_0806F098: .4byte gDungeonGlobalData
_0806F09C: .4byte 0x00000ccc
_0806F0A0: .4byte gUnknown_8106F24
_0806F0A4: .4byte gUnknown_8106F04
_0806F0A8: .4byte gUnknown_202DFE8
_0806F0AC: .4byte gUnknown_80FAE00
_0806F0B0:
	ldr r0, _0806F15C
	ldr r2, [r0]
	ldr r0, [sp, 0x70]
	mov r1, r9
	bl sub_80522F4
_0806F0BC:
	ldr r1, [sp, 0x78]
	cmp r1, 0
	beq _0806F118
	ldr r2, [sp, 0x80]
	cmp r2, 0
	bne _0806F0EE
	ldr r0, [sp, 0x7C]
	adds r0, 0xC4
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _0806F0EE
	mov r0, r9
	bl sub_8041B74
	ldr r2, _0806F160
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	ldr r0, _0806F164
	ldr r0, [r0]
	movs r3, 0xB3
	lsls r3, 1
	adds r0, r3
	strb r4, [r0]
_0806F0EE:
	ldr r6, [sp, 0x80]
	cmp r6, 0x1
	bne _0806F118
	ldr r0, [sp, 0x7C]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806F118
	mov r0, r9
	bl sub_8041B5C
	ldr r2, _0806F160
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	ldr r0, _0806F164
	ldr r0, [r0]
	ldr r1, _0806F168
	adds r0, r1
	strb r6, [r0]
_0806F118:
	mov r0, r9
	movs r1, 0xC
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806F1F4
	mov r0, r9
	movs r1, 0x13
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806F1F4
	mov r3, r10
	ldrb r0, [r3, 0x6]
	ldr r4, [sp, 0xAC]
	cmp r0, 0
	beq _0806F140
	movs r4, 0
_0806F140:
	mov r0, r10
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806F170
	ldr r4, _0806F16C
	ldr r0, _0806F164
	ldr r0, [r0]
	movs r6, 0xB4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	strb r1, [r0]
	b _0806F1DA
	.align 2, 0
_0806F15C: .4byte gUnknown_80FADD8
_0806F160: .4byte gUnknown_8106F1C
_0806F164: .4byte gDungeonGlobalData
_0806F168: .4byte 0x00000167
_0806F16C: .4byte 0x000003e7
_0806F170:
	ldr r0, [sp, 0x70]
	movs r1, 0xC
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806F194
	ldr r0, _0806F2A4
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r4, r0
	ldr r0, _0806F2A8
	ldr r0, [r0]
	movs r2, 0xB2
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
_0806F194:
	mov r0, r9
	movs r1, 0xD
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806F1B6
	ldr r0, _0806F2A4
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r4, r0
	ldr r0, _0806F2A8
	ldr r0, [r0]
	ldr r6, _0806F2AC
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
_0806F1B6:
	cmp r5, 0
	beq _0806F1DA
	ldr r0, [sp, 0x70]
	movs r1, 0x1
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0806F1DA
	ldr r0, _0806F2B0
	movs r1, 0
	ldrsh r4, [r0, r1]
	ldr r0, _0806F2A8
	ldr r0, [r0]
	ldr r2, _0806F2B4
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
_0806F1DA:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, r4
	bge _0806F1F4
	ldr r2, _0806F2B8
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	movs r0, 0x1
	ldr r3, [sp, 0xB0]
	strb r0, [r3, 0xD]
_0806F1F4:
	mov r0, r8
	bl sub_800A048
	ldr r5, _0806F2A8
	ldr r1, [r5]
	movs r6, 0xAA
	lsls r6, 1
	adds r1, r6
	str r0, [r1]
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	ldr r0, [r5]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	ldr r2, [sp, 0xB4]
	str r2, [r0]
	add r4, sp, 0x60
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_800A088
	mov r0, r8
	mov r1, r8
	adds r2, r4, 0
	bl sub_800A34C
	mov r0, r8
	bl sub_800A048
	ldr r1, [r5]
	movs r3, 0xA8
	lsls r3, 1
	adds r1, r3
	str r0, [r1]
	movs r0, 0x80
	lsls r0, 7
	bl DungeonRandomCapped
	movs r6, 0
	str r6, [sp, 0x58]
	movs r1, 0xE0
	lsls r1, 8
	adds r0, r1
	str r0, [r7, 0x4]
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	add r4, sp, 0x68
	adds r0, r4, 0
	movs r1, 0x64
	bl sub_800A020
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_800A34C
	adds r0, r7, 0
	bl sub_800A048
	ldr r1, [r5]
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2
	str r0, [r1]
	mov r0, r8
	bl sub_800A048
	ldr r3, [sp, 0xB0]
	str r0, [r3]
	str r6, [r3, 0x4]
	cmp r0, 0
	bne _0806F294
	strb r0, [r3, 0xD]
_0806F294:
	add sp, 0x8C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F2A4: .4byte gUnknown_80F4DAE
_0806F2A8: .4byte gDungeonGlobalData
_0806F2AC: .4byte 0x00000165
_0806F2B0: .4byte gUnknown_80F4DB0
_0806F2B4: .4byte 0x00000169
_0806F2B8: .4byte gUnknown_8106F14
	thumb_func_end sub_806EAF4

	thumb_func_start sub_806F2BC
sub_806F2BC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r5, r0, 0
	mov r12, r1
	ldr r7, [sp, 0x2C]
	lsls r2, 24
	lsrs r4, r2, 24
	adds r6, r3, 0
	cmp r6, 0
	bgt _0806F2D6
	movs r6, 0x1
_0806F2D6:
	ldr r0, _0806F320
	cmp r6, r0
	ble _0806F2DE
	adds r6, r0, 0
_0806F2DE:
	movs r0, 0
	mov r8, r0
	strb r4, [r7, 0xC]
	str r7, [sp]
	add r0, sp, 0x4
	adds r1, r5, 0
	mov r2, r12
	adds r3, r4, 0
	bl sub_806E100
	add r4, sp, 0xC
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_800A34C
	adds r0, r4, 0
	bl sub_800A048
	str r0, [r7]
	mov r0, r8
	str r0, [r7, 0x4]
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F320: .4byte 0x000003e7
	thumb_func_end sub_806F2BC

	thumb_func_start sub_806F324
sub_806F324:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x94
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, r3, 16
	asrs r4, 16
	add r0, sp, 0x10
	bl sub_80457DC
	add r2, sp, 0x84
	str r5, [sp, 0x84]
	movs r0, 0x2
	str r0, [r2, 0x8]
	movs r0, 0
	strb r0, [r2, 0xC]
	str r6, [r2, 0x4]
	strb r0, [r2, 0xD]
	strb r0, [r2, 0xE]
	strb r0, [r2, 0xF]
	str r0, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	mov r1, r8
	movs r3, 0
	bl sub_806D010
	add sp, 0x94
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806F324

	thumb_func_start sub_806F370
sub_806F370:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r10, r0
	adds r7, r1, 0
	mov r9, r3
	ldr r0, [sp, 0x50]
	ldr r1, [sp, 0x54]
	ldr r3, [sp, 0x58]
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	adds r5, r2, 0
	movs r0, 0x2
	str r0, [sp, 0x18]
	str r3, [sp, 0x14]
	add r0, sp, 0x10
	movs r1, 0
	strb r4, [r0, 0xC]
	strb r1, [r0, 0xD]
	strb r1, [r0, 0xE]
	cmp r4, 0
	beq _0806F3FC
	ldr r1, [r7, 0x70]
	movs r2, 0
	lsls r0, r4, 3
	mov r3, sp
	adds r3, 0x20
	str r3, [sp, 0x28]
	ldr r6, _0806F408
	mov r12, r6
	adds r1, 0x5C
	adds r0, r4
	lsls r3, r0, 2
	ldr r4, [sp, 0x28]
_0806F3C0:
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r3
	add r0, r12
	movs r6, 0
	ldrsh r0, [r0, r6]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806F3C0
	adds r0, r7, 0
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806F3FC
	ldr r2, _0806F40C
	ldr r1, [sp, 0x28]
	ldr r0, [r1, 0x4]
	lsls r0, 2
	ldr r1, [sp, 0x20]
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	beq _0806F3FC
	movs r5, 0
_0806F3FC:
	str r5, [sp, 0x10]
	cmp r5, 0
	bne _0806F410
	add r1, sp, 0x10
	movs r0, 0x1
	b _0806F414
	.align 2, 0
_0806F408: .4byte gTypeEffectivenessChart
_0806F40C: .4byte gUnknown_80F54B4
_0806F410:
	add r1, sp, 0x10
	movs r0, 0
_0806F414:
	strb r0, [r1, 0xF]
	mov r3, r9
	str r3, [sp]
	mov r6, r8
	str r6, [sp, 0x4]
	ldr r0, [sp, 0x5C]
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x60]
	str r0, [sp, 0xC]
	mov r0, r10
	adds r1, r7, 0
	add r2, sp, 0x10
	movs r3, 0
	bl sub_806D010
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0806F440
	add r0, sp, 0x10
	ldrb r0, [r0, 0xF]
	ldr r1, [sp, 0x4C]
	strb r0, [r1]
_0806F440:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806F370

	thumb_func_start SetShopkeeperAggression
SetShopkeeperAggression:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, [r1, 0x70]
	adds r6, r4, 0
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0806F47A
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x1
	bne _0806F47A
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0806F476
	movs r0, 0x2
	strb r0, [r4, 0x8]
	b _0806F47A
_0806F476:
	movs r0, 0x3
	strb r0, [r6, 0x8]
_0806F47A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end SetShopkeeperAggression

	thumb_func_start sub_806F480
sub_806F480:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	ldr r2, [r0, 0x70]
	adds r3, r2, 0
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0806F49E
	cmp r1, 0
	beq _0806F49A
	movs r0, 0x2
	strb r0, [r2, 0x8]
	b _0806F49E
_0806F49A:
	movs r0, 0x3
	strb r0, [r3, 0x8]
_0806F49E:
	pop {r0}
	bx r0
	thumb_func_end sub_806F480

	thumb_func_start sub_806F4A4
sub_806F4A4:
	push {r4-r6,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r5, [r0, 0x70]
	movs r1, 0xE
	bl HasType
	lsls r0, 24
	cmp r0, 0
	beq _0806F4CE
	cmp r4, 0x1
	beq _0806F4C0
	cmp r4, 0x7
	bne _0806F4CE
_0806F4C0:
	adds r0, r5, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806F4CE
_0806F4CA:
	movs r0, 0
	b _0806F4F6
_0806F4CE:
	movs r2, 0
	lsls r0, r4, 3
	ldr r6, _0806F4FC
	adds r3, r5, 0
	adds r3, 0x5C
	adds r0, r4
	lsls r1, r0, 2
_0806F4DC:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	adds r0, r6
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	beq _0806F4CA
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806F4DC
	movs r0, 0x1
_0806F4F6:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0806F4FC: .4byte gTypeEffectivenessChart
	thumb_func_end sub_806F4A4

	thumb_func_start sub_806F500
sub_806F500:
	ldr r0, _0806F5F4
	ldr r0, [r0]
	mov r12, r0
	movs r0, 0x9A
	lsls r0, 1
	add r0, r12
	movs r1, 0
	strb r1, [r0]
	str r1, [r0, 0x4]
	strb r1, [r0, 0x8]
	strb r1, [r0, 0x9]
	movs r2, 0xA
	strb r2, [r0, 0xA]
	strb r2, [r0, 0xB]
	movs r2, 0
	movs r3, 0x1
	strh r3, [r0, 0xC]
	strh r3, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x16]
	strh r1, [r0, 0x18]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x24]
	str r1, [r0, 0x28]
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F5F8
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB1
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F5FC
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F600
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB3
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F604
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F608
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB5
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F60C
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F610
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB7
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F614
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB8
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F618
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB9
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F61C
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F620
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBB
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F624
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBC
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F628
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBD
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	bx lr
	.align 2, 0
_0806F5F4: .4byte gDungeonGlobalData
_0806F5F8: .4byte 0x00000161
_0806F5FC: .4byte 0x00000163
_0806F600: .4byte 0x00000165
_0806F604: .4byte 0x00000167
_0806F608: .4byte 0x00000169
_0806F60C: .4byte 0x0000016b
_0806F610: .4byte 0x0000016d
_0806F614: .4byte 0x0000016f
_0806F618: .4byte 0x00000171
_0806F61C: .4byte 0x00000173
_0806F620: .4byte 0x00000175
_0806F624: .4byte 0x00000177
_0806F628: .4byte 0x00000179
	thumb_func_end sub_806F500

	thumb_func_start sub_806F62C
sub_806F62C:
	ldr r1, _0806F638
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0806F638: .4byte gUnknown_8106F7C
	thumb_func_end sub_806F62C

	thumb_func_start sub_806F63C
sub_806F63C:
	push {lr}
	ldr r1, _0806F658
	ldr r1, [r1]
	ldr r2, _0806F65C
	adds r1, r2
	ldr r1, [r1, 0x10]
	cmp r1, r0
	bne _0806F652
	adds r0, r1, 0
	bl sub_803F508
_0806F652:
	pop {r0}
	bx r0
	.align 2, 0
_0806F658: .4byte gDungeonGlobalData
_0806F65C: .4byte 0x000181e8
	thumb_func_end sub_806F63C

	thumb_func_start sub_806F660
sub_806F660:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r0, [r6, 0x70]
	mov r10, r0
	ldr r4, [r1, 0x70]
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _0806F6C0
	ldr r3, [r0]
	ldr r1, _0806F6C4
	adds r0, r3, r1
	ldrh r2, [r0]
	subs r0, r2, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _0806F702
	lsls r0, r2, 16
	asrs r1, r0, 16
	cmp r1, 0x9
	beq _0806F702
	cmp r1, 0xF
	beq _0806F702
	adds r0, r2, 0
	subs r0, 0x2C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bhi _0806F6CC
	ldr r2, _0806F6C8
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806F702
	b _0806F8FC
	.align 2, 0
_0806F6C0: .4byte gDungeonGlobalData
_0806F6C4: .4byte 0x00003a14
_0806F6C8: .4byte 0x0000065c
_0806F6CC:
	cmp r1, 0x31
	bne _0806F6F0
	ldr r1, _0806F6EC
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806F6DC
	b _0806F8FC
_0806F6DC:
	movs r0, 0xCF
	lsls r0, 1
	bl sub_8097900
	lsls r0, 24
	cmp r0, 0
	bne _0806F702
	b _0806F8FC
	.align 2, 0
_0806F6EC: .4byte 0x00000659
_0806F6F0:
	ldr r2, _0806F834
	adds r0, r3, r2
	ldrb r0, [r0]
	bl GetRecruitable
	lsls r0, 24
	cmp r0, 0
	bne _0806F702
	b _0806F8FC
_0806F702:
	ldr r0, _0806F838
	ldr r0, [r0]
	ldr r3, _0806F83C
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806F712
	b _0806F8FC
_0806F712:
	ldrh r1, [r4, 0x2]
	adds r0, r1, 0
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _0806F766
	lsls r0, r1, 16
	asrs r1, r0, 16
	ldr r0, _0806F840
	cmp r1, r0
	beq _0806F766
	subs r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x2
	cmp r1, r0
	beq _0806F766
	adds r0, 0x8A
	cmp r1, r0
	beq _0806F766
	adds r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x4
	cmp r1, r0
	beq _0806F766
	subs r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x2
	cmp r1, r0
	beq _0806F766
	subs r0, 0x9
	cmp r1, r0
	beq _0806F766
	adds r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x1
	cmp r1, r0
	bne _0806F776
_0806F766:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl HasRecruitedMon
	lsls r0, 24
	cmp r0, 0
	beq _0806F776
	b _0806F8FC
_0806F776:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	bl sub_806F9BC
	lsls r0, 24
	cmp r0, 0
	bne _0806F786
	b _0806F8FC
_0806F786:
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	subs r1, r0
	cmp r1, 0
	bge _0806F798
	negs r1, r1
_0806F798:
	cmp r1, 0x1
	ble _0806F79E
	b _0806F8FC
_0806F79E:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r8
	movs r3, 0x6
	ldrsh r0, [r2, r3]
	subs r1, r0
	cmp r1, 0
	bge _0806F7B0
	negs r1, r1
_0806F7B0:
	cmp r1, 0x1
	ble _0806F7B6
	b _0806F8FC
_0806F7B6:
	adds r0, r4, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	bne _0806F7C2
	b _0806F8FC
_0806F7C2:
	adds r0, r4, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806F7CE
	b _0806F8FC
_0806F7CE:
	mov r0, r8
	adds r1, r6, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	bne _0806F7DE
	b _0806F8FC
_0806F7DE:
	bl sub_806F910
	movs r0, 0xFA
	lsls r0, 2
	bl DungeonRandomCapped
	adds r7, r0, 0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl GetBaseRecruit
	lsls r0, 16
	asrs r4, r0, 16
	ldr r0, _0806F844
	cmp r4, r0
	bne _0806F800
	b _0806F8FC
_0806F800:
	adds r0, r6, 0
	movs r1, 0x2E
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0806F816
	ldr r0, _0806F848
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r4, r0
_0806F816:
	ldr r0, _0806F84C
	mov r3, r10
	ldrb r1, [r3, 0x9]
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r4, r0
	cmp r7, r4
	bge _0806F8FC
	movs r4, 0
	movs r0, 0x6
	subs r3, r0, r5
	ldr r7, _0806F850
	b _0806F856
	.align 2, 0
_0806F834: .4byte 0x00000644
_0806F838: .4byte gDungeonGlobalData
_0806F83C: .4byte 0x0000065d
_0806F840: .4byte 0x0000010d
_0806F844: .4byte 0xfffffc19
_0806F848: .4byte gUnknown_80F5008
_0806F84C: .4byte gUnknown_80F5700
_0806F850: .4byte gUnknown_202EE70
_0806F854:
	adds r4, 0x1
_0806F856:
	cmp r4, r3
	bgt _0806F878
	movs r2, 0
	cmp r2, r5
	bge _0806F872
	adds r1, r4, r7
	b _0806F86C
_0806F864:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r5
	bge _0806F872
_0806F86C:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0806F864
_0806F872:
	cmp r2, r5
	bne _0806F854
	mov r9, r4
_0806F878:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0806F8F4
	movs r4, 0
	ldr r3, _0806F8BC
	ldr r0, [r3]
	ldr r2, _0806F8C0
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806F8B4
	adds r7, r3, 0
	adds r5, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806F89C:
	adds r2, 0x64
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0806F8B4
	ldr r0, [r7]
	adds r0, r2, r0
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806F89C
_0806F8B4:
	cmp r4, 0x4
	beq _0806F8F4
	movs r4, 0
	b _0806F8C6
	.align 2, 0
_0806F8BC: .4byte gRecruitedPokemonRef
_0806F8C0: .4byte 0x00008df8
_0806F8C4:
	adds r4, 0x1
_0806F8C6:
	cmp r4, 0x3
	bgt _0806F8E2
	ldr r0, _0806F8EC
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r3, _0806F8F0
	adds r0, r3
	adds r0, r1
	ldr r0, [r0]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806F8C4
_0806F8E2:
	cmp r4, 0x4
	beq _0806F8F4
	movs r0, 0x1
	b _0806F8FE
	.align 2, 0
_0806F8EC: .4byte gDungeonGlobalData
_0806F8F0: .4byte 0x0001357c
_0806F8F4:
	adds r0, r6, 0
	mov r1, r8
	bl nullsub_96
_0806F8FC:
	movs r0, 0
_0806F8FE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806F660

	thumb_func_start nullsub_96
nullsub_96:
	bx lr
	thumb_func_end nullsub_96

	thumb_func_start sub_806F910
sub_806F910:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	movs r6, 0
	movs r7, 0x40
_0806F91C:
	ldr r0, _0806F9AC
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0806F9B0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r1, r6, 0x1
	mov r8, r1
	cmp r0, 0
	beq _0806F98A
	ldr r0, [r4, 0x70]
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r4, 0
	adds r0, 0x68
	strh r7, [r0]
	ldr r0, [r4, 0x70]
	ldr r2, _0806F9B4
	adds r0, r2
	strb r6, [r0]
	ldr r0, [r4, 0x70]
	adds r2, 0x1
	adds r0, r2
	strb r1, [r0]
	cmp r1, 0
	beq _0806F978
	ldr r3, _0806F9B8
	movs r2, 0x1
_0806F966:
	cmp r5, 0x5
	bgt _0806F972
	adds r0, r5, r3
	strb r2, [r0]
	adds r7, 0x10
	adds r5, 0x1
_0806F972:
	subs r1, 0x1
	cmp r1, 0
	bne _0806F966
_0806F978:
	adds r0, r4, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806CCB4
_0806F98A:
	mov r6, r8
	cmp r6, 0x3
	ble _0806F91C
	cmp r5, 0x5
	bgt _0806F9A2
	ldr r2, _0806F9B8
	movs r1, 0
_0806F998:
	adds r0, r5, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806F998
_0806F9A2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F9AC: .4byte gDungeonGlobalData
_0806F9B0: .4byte 0x0001357c
_0806F9B4: .4byte 0x00000167
_0806F9B8: .4byte gUnknown_202EE70
	thumb_func_end sub_806F910

	thumb_func_start sub_806F9BC
sub_806F9BC:
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 16
	asrs r4, r0, 16
	ldr r5, _0806FA40
	ldr r0, [r5]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806FA3C
	adds r0, r4, 0
	bl sub_808529C
	lsls r0, 24
	cmp r0, 0
	beq _0806FA3C
	cmp r4, 0x97
	bne _0806F9F2
	ldr r0, [r5]
	movs r1, 0xCF
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806FA3C
_0806F9F2:
	movs r0, 0xCC
	lsls r0, 1
	cmp r4, r0
	beq _0806FA3C
	ldr r0, _0806FA44
	cmp r4, r0
	beq _0806FA3C
	ldr r0, _0806FA48
	cmp r4, r0
	beq _0806FA3C
	movs r0, 0xD1
	lsls r0, 1
	cmp r4, r0
	beq _0806FA3C
	ldr r0, _0806FA4C
	cmp r4, r0
	beq _0806FA3C
	adds r0, r4, 0
	bl GetUnk12
	lsls r0, 24
	cmp r0, 0
	bne _0806FA50
	adds r0, r4, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _0806FA50
_0806FA3C:
	movs r0, 0
	b _0806FA52
	.align 2, 0
_0806FA40: .4byte gDungeonGlobalData
_0806FA44: .4byte 0x00000199
_0806FA48: .4byte 0x000001a1
_0806FA4C: .4byte 0x000001a3
_0806FA50:
	movs r0, 0x1
_0806FA52:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806F9BC

	thumb_func_start sub_806FA5C
sub_806FA5C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0x4
	mov r1, r8
	adds r1, 0x4
	bl CalculateFacingDir
	adds r4, r0, 0
	movs r0, 0
	mov r10, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r5, 0
	adds r0, 0x22
	mov r2, r10
	strb r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_807A0CC
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806CE68
	ldr r0, _0806FAD4
	movs r3, 0
	ldrsh r1, [r6, r3]
	bl CopyCyanSpeciesNametoBuffer
	ldr r0, _0806FAD8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0
	bne _0806FAE4
	movs r4, 0
	ldrsh r1, [r6, r4]
	ldr r0, _0806FADC
	cmp r1, r0
	beq _0806FB28
	ldr r0, _0806FAE0
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	b _0806FB28
	.align 2, 0
_0806FAD4: .4byte gAvailablePokemonNames
_0806FAD8: .4byte gUnknown_80F9FE8
_0806FADC: .4byte 0x0000019d
_0806FAE0: .4byte gUnknown_80FA004
_0806FAE4:
	movs r7, 0
	ldr r3, _0806FB2C
	ldr r0, [r3]
	ldr r2, _0806FB30
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806FB1A
	mov r12, r3
	adds r4, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806FB00:
	adds r2, 0x64
	adds r7, 0x1
	cmp r7, 0x3
	bgt _0806FB1A
	mov r1, r12
	ldr r0, [r1]
	adds r0, r2, r0
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806FB00
_0806FB1A:
	cmp r7, 0x4
	bne _0806FB38
	ldr r0, _0806FB34
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
_0806FB28:
	movs r0, 0
	b _0806FCF0
	.align 2, 0
_0806FB2C: .4byte gRecruitedPokemonRef
_0806FB30: .4byte 0x00008df8
_0806FB34: .4byte gUnknown_80FA030
_0806FB38:
	mov r0, r9
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _0806FB4E
	mov r0, r9
	bl UnlockFriendArea
	movs r2, 0x1
	mov r10, r2
_0806FB4E:
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r5, 0
	mov r2, r8
	bl sub_8068FE0
	ldr r1, _0806FC40
	movs r0, 0x64
	muls r0, r7
	ldr r3, _0806FC44
	adds r0, r3
	ldr r1, [r1]
	adds r5, r1, r0
	movs r4, 0
	movs r0, 0x3
	strh r0, [r5]
	strb r4, [r5, 0x2]
	ldrh r0, [r6, 0xE]
	strb r0, [r5, 0x3]
	movs r0, 0x1
	strh r0, [r5, 0x8]
	adds r0, r5, 0
	adds r0, 0x4C
	movs r1, 0
	bl SetDefaultIQSkills
	ldr r0, [r6, 0x44]
	str r0, [r5, 0x54]
	adds r0, r5, 0
	adds r0, 0x50
	strb r4, [r0]
	ldr r0, _0806FC48
	strh r0, [r5, 0xA]
	strh r7, [r5, 0xC]
	ldrh r0, [r6]
	strh r0, [r5, 0xE]
	ldr r0, _0806FC4C
	ldr r0, [r0]
	ldr r4, _0806FC50
	adds r0, r4
	ldr r0, [r0]
	str r0, [r5, 0x4]
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x10]
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x12]
	ldr r0, [r6, 0x14]
	str r0, [r5, 0x44]
	ldr r0, [r6, 0x18]
	str r0, [r5, 0x48]
	movs r2, 0
	adds r7, r6, 0
	adds r7, 0x20
	adds r4, r6, 0
	adds r4, 0xA
	adds r3, r6, 0
	adds r3, 0xC
	adds r1, r5, 0
	adds r1, 0x14
_0806FBC4:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806FBC4
	ldr r0, [r6, 0x10]
	str r0, [r5, 0x18]
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r7, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r6, 0x1C]
	str r0, [r5, 0x40]
	adds r4, r5, 0
	adds r4, 0x58
	movs r1, 0
	ldrsh r0, [r6, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
	bl sub_8097848
	movs r2, 0
	ldrsh r0, [r6, r2]
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	movs r3, 0x6
	ldrsh r2, [r6, r3]
	add r3, sp, 0xC
	str r3, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r3, 0x1
	str r3, [sp, 0x8]
	adds r3, r5, 0
	bl sub_806B8CC
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _0806FC58
	ldr r0, _0806FC54
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	strh r7, [r5]
	b _0806FCEE
	.align 2, 0
_0806FC40: .4byte gRecruitedPokemonRef
_0806FC44: .4byte 0x00008df8
_0806FC48: .4byte 0x0000ffff
_0806FC4C: .4byte gDungeonGlobalData
_0806FC50: .4byte 0x00000644
_0806FC54: .4byte gUnknown_80FA058
_0806FC58:
	bl sub_8083D88
	movs r0, 0xA0
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0806FC78
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _0806FC94
	b _0806FC88
	.align 2, 0
_0806FC78: .4byte gUnknown_80FA090
_0806FC7C:
	ldr r0, _0806FD00
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FC88:
	adds r0, r4, 0
	bl sub_805FBE8
	lsls r0, 24
	cmp r0, 0
	beq _0806FC7C
_0806FC94:
	ldr r4, _0806FD04
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_808D9DC
	ldr r0, _0806FD08
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	mov r0, r10
	cmp r0, 0
	beq _0806FCD8
	bl xxx_call_GetLeaderEntity
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806FD0C
	mov r1, r9
	bl sub_8092558
	movs r0, 0xCE
	bl PlaySound
	ldr r0, _0806FD10
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FCD8:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x97
	bne _0806FCEE
	ldr r2, _0806FD14
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1, 0x11]
_0806FCEE:
	movs r0, 0x1
_0806FCF0:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806FD00: .4byte gUnknown_80FA0C8
_0806FD04: .4byte gAvailablePokemonNames
_0806FD08: .4byte gUnknown_80FA0F0
_0806FD0C: .4byte gUnknown_202E628
_0806FD10: .4byte gUnknown_80FA120
_0806FD14: .4byte gDungeonGlobalData
	thumb_func_end sub_806FA5C

	thumb_func_start sub_806FD18
sub_806FD18:
	push {r4-r7,lr}
	ldr r4, [r0, 0x70]
	movs r6, 0x1
	negs r6, r6
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	bl sub_806F9BC
	lsls r0, 24
	cmp r0, 0
	beq _0806FDEC
	bl sub_806F910
	movs r4, 0
	movs r0, 0x6
	subs r3, r0, r5
	ldr r7, _0806FD48
	b _0806FD4E
	.align 2, 0
_0806FD48: .4byte gUnknown_202EE70
_0806FD4C:
	adds r4, 0x1
_0806FD4E:
	cmp r4, r3
	bgt _0806FD70
	movs r2, 0
	cmp r2, r5
	bge _0806FD6A
	adds r1, r4, r7
	b _0806FD64
_0806FD5C:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r5
	bge _0806FD6A
_0806FD64:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0806FD5C
_0806FD6A:
	cmp r2, r5
	bne _0806FD4C
	adds r6, r4, 0
_0806FD70:
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	beq _0806FDEC
	movs r4, 0
	ldr r3, _0806FDB4
	ldr r0, [r3]
	ldr r2, _0806FDB8
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806FDAC
	adds r6, r3, 0
	adds r5, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806FD94:
	adds r2, 0x64
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0806FDAC
	ldr r0, [r6]
	adds r0, r2, r0
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806FD94
_0806FDAC:
	cmp r4, 0x4
	beq _0806FDEC
	movs r4, 0
	b _0806FDBE
	.align 2, 0
_0806FDB4: .4byte gRecruitedPokemonRef
_0806FDB8: .4byte 0x00008df8
_0806FDBC:
	adds r4, 0x1
_0806FDBE:
	cmp r4, 0x3
	bgt _0806FDDA
	ldr r0, _0806FDE4
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _0806FDE8
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806FDBC
_0806FDDA:
	cmp r4, 0x4
	beq _0806FDEC
	movs r0, 0x1
	b _0806FDEE
	.align 2, 0
_0806FDE4: .4byte gDungeonGlobalData
_0806FDE8: .4byte 0x0001357c
_0806FDEC:
	movs r0, 0
_0806FDEE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806FD18

	thumb_func_start sub_806FDF4
sub_806FDF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x60
	str r0, [sp, 0x58]
	mov r10, r1
	str r2, [sp, 0x5C]
	movs r0, 0
	mov r9, r0
	str r0, [r2]
	add r0, sp, 0xC
	bl sub_8069D4C
	movs r6, 0
	ldr r3, _0806FE50
	ldr r0, [r3]
	ldr r2, _0806FE54
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806FE46
	adds r5, r3, 0
	adds r4, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806FE2E:
	adds r2, 0x64
	adds r6, 0x1
	cmp r6, 0x3
	bgt _0806FE46
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806FE2E
_0806FE46:
	cmp r6, 0x4
	bne _0806FE58
	movs r0, 0
	b _0806FFF8
	.align 2, 0
_0806FE50: .4byte gRecruitedPokemonRef
_0806FE54: .4byte 0x00008df8
_0806FE58:
	add r0, sp, 0xC
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, _0806FF74
	movs r0, 0x64
	muls r0, r6
	ldr r2, _0806FF78
	adds r0, r2
	ldr r1, [r1]
	adds r5, r1, r0
	movs r4, 0
	movs r0, 0x3
	strh r0, [r5]
	strb r4, [r5, 0x2]
	add r0, sp, 0xC
	ldrh r0, [r0, 0xE]
	strb r0, [r5, 0x3]
	movs r0, 0x1
	strh r0, [r5, 0x8]
	adds r0, r5, 0
	adds r0, 0x4C
	movs r1, 0
	bl SetDefaultIQSkills
	ldr r0, [sp, 0x50]
	str r0, [r5, 0x54]
	adds r0, r5, 0
	adds r0, 0x50
	strb r4, [r0]
	ldr r0, _0806FF7C
	strh r0, [r5, 0xA]
	strh r6, [r5, 0xC]
	add r0, sp, 0xC
	ldrh r0, [r0]
	strh r0, [r5, 0xE]
	ldr r0, _0806FF80
	ldr r0, [r0]
	ldr r3, _0806FF84
	adds r0, r3
	ldr r0, [r0]
	str r0, [r5, 0x4]
	add r0, sp, 0xC
	ldrh r0, [r0, 0x8]
	strh r0, [r5, 0x10]
	add r0, sp, 0xC
	ldrh r0, [r0, 0x8]
	strh r0, [r5, 0x12]
	ldr r0, [sp, 0x20]
	str r0, [r5, 0x44]
	ldr r0, [sp, 0x24]
	str r0, [r5, 0x48]
	movs r2, 0
	add r6, sp, 0x2C
	add r4, sp, 0x54
	mov r8, r4
	mov r4, sp
	adds r4, 0x16
	add r3, sp, 0x18
	adds r1, r5, 0
	adds r1, 0x14
_0806FED8:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806FED8
	ldr r0, [sp, 0x1C]
	str r0, [r5, 0x18]
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r6, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [sp, 0x28]
	str r0, [r5, 0x40]
	adds r4, r5, 0
	adds r4, 0x58
	add r0, sp, 0xC
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
	adds r0, r7, 0
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _0806FF34
	adds r0, r7, 0
	bl UnlockFriendArea
	movs r2, 0x1
	mov r9, r2
_0806FF34:
	bl sub_8097848
	movs r1, 0xFA
	lsls r1, 1
	mov r0, r10
	ldr r2, [sp, 0x58]
	bl sub_8068FE0
	add r0, sp, 0xC
	movs r3, 0
	ldrsh r0, [r0, r3]
	add r1, sp, 0xC
	movs r2, 0x4
	ldrsh r1, [r1, r2]
	add r2, sp, 0xC
	movs r3, 0x6
	ldrsh r2, [r2, r3]
	mov r3, r8
	str r3, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	str r3, [sp, 0x8]
	adds r3, r5, 0
	bl sub_806B8CC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0806FF88
	strh r0, [r5]
	b _0806FFF6
	.align 2, 0
_0806FF74: .4byte gRecruitedPokemonRef
_0806FF78: .4byte 0x00008df8
_0806FF7C: .4byte 0x0000ffff
_0806FF80: .4byte gDungeonGlobalData
_0806FF84: .4byte 0x00000644
_0806FF88:
	ldr r0, _0806FF9C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _0806FFB8
	b _0806FFAC
	.align 2, 0
_0806FF9C: .4byte gUnknown_80FA090
_0806FFA0:
	ldr r0, _08070008
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FFAC:
	adds r0, r4, 0
	bl sub_805FBE8
	lsls r0, 24
	cmp r0, 0
	beq _0806FFA0
_0806FFB8:
	mov r4, r9
	cmp r4, 0
	beq _0806FFE6
	bl xxx_call_GetLeaderEntity
	adds r1, r0, 0
	ldr r0, _0807000C
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08070010
	adds r1, r7, 0
	bl sub_8092558
	movs r0, 0xCE
	bl PlaySound
	ldr r0, _08070014
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FFE6:
	ldr r0, _08070018
	adds r1, r5, 0
	movs r2, 0
	bl sub_808D9DC
	ldr r0, [sp, 0x54]
	ldr r1, [sp, 0x5C]
	str r0, [r1]
_0806FFF6:
	movs r0, 0x1
_0806FFF8:
	add sp, 0x60
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08070008: .4byte gUnknown_80FA0C8
_0807000C: .4byte gAvailablePokemonNames
_08070010: .4byte gUnknown_202E628
_08070014: .4byte gUnknown_80FA120
_08070018: .4byte gUnknown_202E088
	thumb_func_end sub_806FDF4

        .align 2,0
