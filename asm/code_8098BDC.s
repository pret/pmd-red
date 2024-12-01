	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80990EC
sub_80990EC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x80
	adds r7, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	adds r0, r4, 0
	bl GetDungeonInfo_80A2608
	mov r8, r0
	ldrb r0, [r0, 0xC]
	movs r5, 0
	strb r0, [r7]
	movs r0, 0x1
	strb r0, [r7, 0x1]
	strb r5, [r7, 0xC]
	adds r0, r4, 0
	bl sub_80A2750
	lsls r0, 16
	asrs r6, r0, 16
	cmp r6, 0x2
	beq _080991C8
	cmp r6, 0x2
	bgt _08099126
	cmp r6, 0x1
	beq _0809912C
	b _080991CA
_08099126:
	cmp r6, 0x4
	beq _080991C4
	b _080991CA
_0809912C:
	movs r1, 0
	strb r5, [r7, 0xB]
	adds r0, r4, 0
	subs r0, 0x25
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0809913E
	movs r1, 0x1
_0809913E:
	cmp r1, 0
	beq _080991CA
	strb r6, [r7, 0xC]
	mov r0, sp
	movs r1, 0x5B
	bl sub_80A8EC0
	add r4, sp, 0x18
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
	add r5, sp, 0x30
	str r4, [sp, 0x58]
	add r1, sp, 0x5C
	movs r2, 0
	movs r0, 0x5E
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x5E
	strb r2, [r0]
	add r0, sp, 0x60
	movs r1, 0x47
	strb r1, [r0]
	strb r2, [r0, 0x1]
	add r1, sp, 0x64
	movs r0, 0x82
	lsls r0, 1
	strh r0, [r1]
	movs r0, 0xE0
	strh r0, [r1, 0x2]
	movs r0, 0xAC
	strh r0, [r1, 0x4]
	movs r0, 0xBE
	strh r0, [r1, 0x6]
	add r1, sp, 0x6C
	movs r0, 0x50
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6E
	movs r2, 0xF
	strh r2, [r0]
	add r0, sp, 0x70
	strh r6, [r0]
	adds r0, 0x2
	movs r1, 0x19
	strh r1, [r0]
	strh r1, [r0, 0x2]
	adds r0, 0x4
	strh r2, [r0]
	strh r2, [r0, 0x2]
	ldr r0, _080991C0
	str r0, [sp, 0x7C]
	add r1, sp, 0x58
	adds r0, r5, 0
	movs r2, 0x28
	bl memcpy
	adds r0, r7, 0
	adds r0, 0x18
	adds r1, r5, 0
	bl sub_808D144
	b _080991CA
	.align 2, 0
_080991C0: .4byte 0x000061a8
_080991C4:
	strb r5, [r7, 0xB]
	b _080991CA
_080991C8:
	strb r6, [r7, 0xB]
_080991CA:
	movs r0, 0
	strb r0, [r7, 0x4]
	strb r0, [r7, 0xD]
	mov r1, r8
	ldrb r0, [r1, 0x11]
	add sp, 0x80
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80990EC

	thumb_func_start sub_80991E0
sub_80991E0:
	push {lr}
	adds r2, r0, 0
	ldr r3, _08099204
	ldrh r0, [r3]
	strh r0, [r1]
	ldr r0, _08099208
	ldrb r0, [r0]
	cmp r0, 0
	bne _0809920C
	movs r0, 0
	ldrsh r1, [r3, r0]
	adds r0, r2, 0
	bl sub_80990EC
	lsls r0, 24
	lsrs r0, 24
	b _08099218
	.align 2, 0
_08099204: .4byte gUnknown_20398C4
_08099208: .4byte gUnknown_203B49C
_0809920C:
	ldr r1, _0809921C
	adds r0, r2, 0
	movs r2, 0x88
	bl memcpy
	movs r0, 0x1
_08099218:
	pop {r1}
	bx r1
	.align 2, 0
_0809921C: .4byte gUnknown_20398C8
	thumb_func_end sub_80991E0

	thumb_func_start sub_8099220
sub_8099220:
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	asrs r3, r1, 16
	cmp r2, 0
	beq _08099258
	ldr r1, _08099248
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, _0809924C
	movs r0, 0
	strb r0, [r1]
	ldr r0, _08099250
	strh r3, [r0]
	ldr r0, _08099254
	adds r1, r2, 0
	movs r2, 0x88
	bl memcpy
	b _0809926A
	.align 2, 0
_08099248: .4byte gUnknown_203B49C
_0809924C: .4byte gUnknown_203B49D
_08099250: .4byte gUnknown_20398C4
_08099254: .4byte gUnknown_20398C8
_08099258:
	ldr r0, _08099270
	strb r2, [r0]
	ldr r0, _08099274
	strb r2, [r0]
	ldr r1, _08099278
	movs r2, 0x1
	negs r2, r2
	adds r0, r2, 0
	strh r0, [r1]
_0809926A:
	pop {r0}
	bx r0
	.align 2, 0
_08099270: .4byte gUnknown_203B49C
_08099274: .4byte gUnknown_203B49D
_08099278: .4byte gUnknown_20398C4
	thumb_func_end sub_8099220

	thumb_func_start sub_809927C
sub_809927C:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, _080992CC
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _080992D0
	strb r1, [r0]
	ldr r1, _080992D4
	movs r0, 0x50
	strh r0, [r1]
	ldr r4, _080992D8
	strb r5, [r4]
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x50
	bl SetScriptVarValue
	ldrb r2, [r4]
	movs r0, 0
	movs r1, 0x14
	bl SetScriptVarValue
	ldr r4, _080992DC
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8095494
	subs r4, 0x10
	movs r1, 0
	movs r0, 0x1
	strb r0, [r4, 0xB]
	strb r1, [r4, 0xC]
	strb r1, [r4, 0x4]
	strb r1, [r4, 0xD]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080992CC: .4byte gUnknown_203B49C
_080992D0: .4byte gUnknown_203B49D
_080992D4: .4byte gUnknown_20398C4
_080992D8: .4byte gUnknown_2039950
_080992DC: .4byte gUnknown_20398C8 + 0x10
	thumb_func_end sub_809927C

	thumb_func_start sub_80992E0
sub_80992E0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r0, 0
	movs r1, 0x13
	bl GetScriptVarValue
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08099316
	cmp r1, 0x50
	beq _08099316
	cmp r1, 0x51
	beq _08099316
	cmp r1, 0x52
	beq _08099316
	strh r1, [r4]
	movs r0, 0
	movs r1, 0x14
	bl GetScriptVarValue
	strh r0, [r5]
	movs r0, 0x1
	b _08099322
_08099316:
	movs r1, 0x1
	negs r1, r1
	adds r0, r1, 0
	strh r0, [r4]
	strh r0, [r5]
	movs r0, 0
_08099322:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80992E0

