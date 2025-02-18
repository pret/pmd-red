	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_8067F00
sub_8067F00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	mov r9, r1
	str r3, [sp, 0x4]
	lsls r4, 24
	lsrs r4, 24
	subs r7, r2, 0x1
	movs r0, 0x16
	mov r8, r0
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08067F44
	adds r1, r4, 0
	movs r2, 0
	bl WriteFriendAreaName
	ldr r2, _08067F48
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r1, 0
	mov r10, r1
	b _08067FF6
	.align 2, 0
_08067F44: .4byte gFormatBuffer_Monsters
_08067F48: .4byte gUnknown_8106E28
_08067F4C:
	ldr r4, _08067F8C
	lsls r6, r7, 2
	mov r0, r9
	adds r5, r6, r0
	ldr r1, [r5]
	adds r0, r4, 0
	movs r2, 0
	bl PrintColoredPokeNameToBuffer
	adds r4, 0x50
	ldr r0, [r5]
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_808D930
	ldr r1, _08067F90
	adds r0, r7, 0x1
	str r0, [r1]
	ldr r0, [r5]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08067F9C
	ldr r0, _08067F94
	ldr r1, _08067F98
	bl strcpy
	b _08067FA4
	.align 2, 0
_08067F8C: .4byte gFormatBuffer_Monsters
_08067F90: .4byte gFormatArgs
_08067F94: .4byte gFormatBuffer_Items
_08067F98: .4byte gUnknown_8106E2C
_08067F9C:
	ldr r0, _08067FCC
	ldr r1, _08067FD0
	bl strcpy
_08067FA4:
	mov r1, r9
	adds r0, r6, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08067FD8
	ldr r2, _08067FD4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x7
	mov r1, r8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	b _08067FE6
	.align 2, 0
_08067FCC: .4byte gFormatBuffer_Items
_08067FD0: .4byte gUnknown_8106E30
_08067FD4: .4byte gUnknown_8106E34
_08067FD8:
	ldr r2, _08068028
	str r0, [sp]
	movs r0, 0x7
	mov r1, r8
	movs r3, 0
	bl PrintFormattedStringOnWindow
_08067FE6:
	movs r2, 0x1
	add r10, r2
	movs r0, 0xC
	add r8, r0
	adds r7, 0x1
	mov r1, r10
	cmp r1, 0x9
	bgt _08068000
_08067FF6:
	cmp r7, 0
	blt _08067FE6
	ldr r2, [sp, 0x4]
	cmp r7, r2
	blt _08067F4C
_08068000:
	movs r0, 0
	bl sub_80073E0
	movs r0, 0x1
	bl sub_80073B8
	ldr r0, _0806802C
	ldr r0, [r0]
	ldr r1, [sp, 0x28]
	cmp r0, r1
	blt _08068034
	ldr r2, _08068030
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x2
	movs r3, 0x1
	bl PrintFormattedStringOnWindow
	b _0806804C
	.align 2, 0
_08068028: .4byte gUnknown_8106E48
_0806802C: .4byte gUnknown_202F310
_08068030: .4byte gUnknown_8106E5C
_08068034:
	ldr r1, _08068064
	ldr r2, [sp, 0x28]
	subs r0, r2, r0
	str r0, [r1]
	ldr r2, _08068068
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x2
	movs r3, 0x1
	bl PrintFormattedStringOnWindow
_0806804C:
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068064: .4byte gFormatArgs
_08068068: .4byte gUnknown_8106E6C
	thumb_func_end sub_8067F00

	thumb_func_start sub_806806C
sub_806806C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x110
	str r0, [sp, 0x108]
	add r4, sp, 0x98
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [r4, 0x4]
	movs r1, 0x2
	strh r1, [r4, 0x8]
	strh r1, [r4, 0xA]
	movs r2, 0x12
	strh r2, [r4, 0xC]
	movs r0, 0xE
	strh r0, [r4, 0xE]
	strh r2, [r4, 0x10]
	strh r1, [r4, 0x12]
	ldr r0, _080681B4
	str r0, [r4, 0x14]
	movs r0, 0x3
	str r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	str r0, [r4, 0x4C]
	movs r7, 0
	add r1, sp, 0x44
	strh r7, [r1]
	mov r0, sp
	adds r0, 0x5A
	strh r7, [r0]
	ldr r0, _080681B8
	strh r7, [r0, 0x18]
	mov r9, r1
	adds r1, 0xB4
	str r1, [sp, 0x10C]
	add r2, sp, 0x68
	mov r10, r2
	adds r6, r0, 0
_080680C4:
	movs r3, 0
	mov r8, r3
	add r1, sp, 0xF8
	ldr r0, _080681BC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080681B4
	movs r2, 0x4
	strb r2, [r1]
	strb r7, [r1, 0x1]
	movs r0, 0xA
	strb r0, [r1, 0x2]
	mov r4, r8
	strb r4, [r1, 0x3]
	strh r7, [r6, 0x1E]
	strh r2, [r6, 0x20]
	mov r0, r8
	strh r0, [r6, 0x1A]
	strh r0, [r6, 0x18]
	strh r0, [r6, 0x1C]
	strh r0, [r6, 0x4]
	movs r0, 0x10
	strh r0, [r6, 0x6]
	mov r1, r8
	strh r1, [r6, 0x14]
	mov r2, r8
	str r2, [r6]
	adds r0, r6, 0
	adds r0, 0x28
	bl sub_801317C
	add r0, sp, 0x98
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, _080681C0
	ldr r0, [r0]
	ldr r3, _080681C4
	adds r0, r3
	ldrb r2, [r0]
	add r0, sp, 0x4
	ldr r1, [sp, 0x108]
	bl sub_808FF20
	lsls r4, r7, 2
	mov r0, sp
	adds r0, r4
	adds r0, 0xF8
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r7, 0
	add r2, sp, 0x4
	mov r3, r10
	bl CreatePokemonInfoTabScreen
	ldr r1, _080681C8
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0xF
	lsls r0, 3
	strh r0, [r6, 0xC]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r6, 0xE]
_08068150:
	ldr r0, _080681B8
	bl AddMenuCursorSprite
	ldr r1, [sp, 0x10C]
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0806817A
	mov r2, r10
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0806816C
	bl sub_80684C4
_0806816C:
	mov r3, r9
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0806817A
	bl sub_8068344
_0806817A:
	movs r0, 0
	ldr r1, _080681CC
	bl sub_8014140
	adds r5, r0, 0
	movs r0, 0x1C
	bl sub_803E46C
	ldr r3, _080681D0
	ldrh r1, [r3, 0x2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080681A2
	ldr r2, _080681B8
	adds r0, r2, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _080681D4
_080681A2:
	movs r0, 0
	bl sub_8083CE0
	adds r7, 0x1
	cmp r7, 0x4
	beq _080681B0
	b _080682E8
_080681B0:
	movs r7, 0
	b _080682E8
	.align 2, 0
_080681B4: .4byte gUnknown_202F308
_080681B8: .4byte gUnknown_202EE10
_080681BC: .4byte gUnknown_8106E80
_080681C0: .4byte gDungeon
_080681C4: .4byte 0x0000065a
_080681C8: .4byte gUnknown_2027370
_080681CC: .4byte gUnknown_8106DA4
_080681D0: .4byte gRealInputs
_080681D4:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080681E6
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080681FA
_080681E6:
	movs r0, 0
	bl sub_8083CE0
	subs r7, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r7, r0
	bne _080682E8
	movs r7, 0x3
	b _080682E8
_080681FA:
	ldr r2, [sp, 0x10C]
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08068294
	ldrh r1, [r3, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08068212
	cmp r5, 0x2
	bne _08068248
_08068212:
	mov r3, r10
	ldrb r0, [r3, 0x8]
	cmp r0, 0
	beq _08068248
	movs r0, 0
	bl sub_8083CE0
	ldr r5, _08068244
	movs r4, 0x5
_08068224:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08068224
	mov r4, r9
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080682E8
	.align 2, 0
_08068244: .4byte gIwramTextFunc1
_08068248:
	ldr r0, _0806828C
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08068258
	cmp r5, 0x1
	bne _08068294
_08068258:
	mov r1, r9
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08068294
	movs r0, 0
	bl sub_8083CE0
	ldr r5, _08068290
	movs r4, 0x5
_0806826C:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _0806826C
	mov r3, r9
	ldrh r0, [r3]
	subs r0, 0x1
	strh r0, [r3]
	b _080682E8
	.align 2, 0
_0806828C: .4byte gRealInputs
_08068290: .4byte gIwramTextFunc2
_08068294:
	bl sub_80048C8
	lsls r0, 24
	cmp r0, 0
	beq _080682A0
	b _08068150
_080682A0:
	ldr r0, _080682C4
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080682B8
	ldr r2, _080682C8
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _080682CC
_080682B8:
	bl sub_8083D08
	movs r4, 0x1
	mov r8, r4
	b _080682E8
	.align 2, 0
_080682C4: .4byte gRealInputs
_080682C8: .4byte gUnknown_202EE10
_080682CC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080682E0
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080682E0
	b _08068150
_080682E0:
	bl sub_8083D30
	movs r0, 0x1
	mov r8, r0
_080682E8:
	movs r0, 0x37
	bl sub_803E46C
	mov r1, r8
	cmp r1, 0
	bne _080682F6
	b _080680C4
_080682F6:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	add sp, 0x110
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806806C

    .align 2,0
