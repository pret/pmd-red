	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start SetDungeonBGColorRGB
SetDungeonBGColorRGB:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	str r0, [sp, 0x14]
	mov r10, r1
	mov r9, r2
	ldr r4, [sp, 0x48]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x18]
	lsls r4, 24
	lsrs r4, 24
	bl sub_8085E98
	movs r0, 0
	mov r8, r0
	ldr r0, _08085E70
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	cmp r4, 0
	beq _08085CAE
	ldr r1, [sp, 0x14]
	cmp r1, 0
	blt _08085C92
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r0, 1
	str r0, [sp, 0x14]
_08085C92:
	mov r2, r10
	cmp r2, 0
	blt _08085CA0
	lsrs r0, r2, 31
	add r0, r10
	asrs r0, 1
	mov r10, r0
_08085CA0:
	mov r3, r9
	cmp r3, 0
	blt _08085CAE
	lsrs r0, r3, 31
	add r0, r9
	asrs r0, 1
	mov r9, r0
_08085CAE:
	ldr r1, _08085E74
	ldr r0, [sp, 0x8]
	ands r0, r1
	ldr r1, _08085E78
	ands r0, r1
	ldr r1, _08085E7C
	ands r0, r1
	str r0, [sp, 0x8]
	ldr r0, _08085E80
	ldr r2, [r0]
	ldr r0, _08085E84
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	mov r0, r8
	add r1, sp, 0x8
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
	ldr r2, [sp, 0x14]
	lsls r2, 16
	str r2, [sp, 0x1C]
	mov r3, r10
	lsls r3, 16
	str r3, [sp, 0x20]
	mov r0, r9
	lsls r0, 16
	str r0, [sp, 0x24]
	add r7, sp, 0xC
	movs r1, 0xA0
	cmp r1, 0x1
	ble _08085D56
	add r6, sp, 0x8
	movs r4, 0xA0
	subs r4, 0x1
_08085CFA:
	ldrb r0, [r5]
	ldr r3, [sp, 0x14]
	adds r2, r0, r3
	ldrb r0, [r5, 0x1]
	mov r3, r10
	adds r1, r0, r3
	ldrb r0, [r5, 0x2]
	add r0, r9
	cmp r2, 0xFF
	ble _08085D10
	movs r2, 0xFF
_08085D10:
	cmp r1, 0xFF
	ble _08085D16
	movs r1, 0xFF
_08085D16:
	cmp r0, 0xFF
	ble _08085D1C
	movs r0, 0xFF
_08085D1C:
	cmp r2, 0
	bge _08085D22
	movs r2, 0
_08085D22:
	cmp r1, 0
	bge _08085D28
	movs r1, 0
_08085D28:
	cmp r0, 0
	bge _08085D2E
	movs r0, 0
_08085D2E:
	strb r2, [r6]
	strb r1, [r6, 0x1]
	strb r0, [r6, 0x2]
	ldr r0, _08085E80
	ldr r2, [r0]
	ldr r0, _08085E84
	ldr r3, [r0]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	mov r0, r8
	add r1, sp, 0x8
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
	subs r4, 0x1
	cmp r4, 0
	bne _08085CFA
_08085D56:
	ldr r2, _08085E88
	ldr r3, [sp, 0x1C]
	lsrs r0, r3, 16
	ldr r1, [sp, 0x20]
	orrs r0, r1
	str r0, [sp, 0xC]
	ldr r3, [sp, 0x24]
	lsrs r1, r3, 16
	ldr r0, [r7, 0x4]
	ands r0, r2
	orrs r0, r1
	str r0, [r7, 0x4]
	ldr r0, _08085E8C
	ldr r1, _08085E80
	ldr r3, [r1]
	ldr r1, _08085E84
	ldr r1, [r1]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r2
	str r1, [sp]
	str r7, [sp, 0x4]
	movs r1, 0xA0
	movs r2, 0x20
	bl sub_8004C00
	movs r3, 0x20
	add r8, r3
	ldr r5, _08085E90
	add r6, sp, 0x8
	movs r4, 0x20
_08085D94:
	ldrb r0, [r5]
	ldr r1, [sp, 0x14]
	adds r2, r0, r1
	ldrb r0, [r5, 0x1]
	mov r3, r10
	adds r1, r0, r3
	ldrb r0, [r5, 0x2]
	add r0, r9
	cmp r2, 0xFF
	ble _08085DAA
	movs r2, 0xFF
_08085DAA:
	cmp r1, 0xFF
	ble _08085DB0
	movs r1, 0xFF
_08085DB0:
	cmp r0, 0xFF
	ble _08085DB6
	movs r0, 0xFF
_08085DB6:
	cmp r2, 0
	bge _08085DBC
	movs r2, 0
_08085DBC:
	cmp r1, 0
	bge _08085DC2
	movs r1, 0
_08085DC2:
	cmp r0, 0
	bge _08085DC8
	movs r0, 0
_08085DC8:
	strb r2, [r6]
	strb r1, [r6, 0x1]
	strb r0, [r6, 0x2]
	ldr r0, _08085E80
	ldr r2, [r0]
	ldr r7, _08085E84
	ldr r3, [r7]
	movs r0, 0xBE
	lsls r0, 1
	adds r3, r0
	mov r0, r8
	add r1, sp, 0x8
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r1, 0x1
	add r8, r1
	subs r4, 0x1
	cmp r4, 0
	bne _08085D94
	ldr r2, [sp, 0x18]
	cmp r2, 0
	beq _08085E5E
	ldr r0, [r7]
	ldr r3, _08085E94
	adds r0, r3
	ldr r0, [r0]
	ldr r5, [r0, 0x4]
	movs r0, 0x80
	lsls r0, 1
	mov r8, r0
	add r6, sp, 0x8
	movs r4, 0xD0
_08085E0A:
	ldrb r0, [r5]
	ldr r1, [sp, 0x14]
	adds r2, r0, r1
	ldrb r0, [r5, 0x1]
	mov r3, r10
	adds r1, r0, r3
	ldrb r0, [r5, 0x2]
	add r0, r9
	cmp r2, 0xFF
	ble _08085E20
	movs r2, 0xFF
_08085E20:
	cmp r1, 0xFF
	ble _08085E26
	movs r1, 0xFF
_08085E26:
	cmp r0, 0xFF
	ble _08085E2C
	movs r0, 0xFF
_08085E2C:
	cmp r2, 0
	bge _08085E32
	movs r2, 0
_08085E32:
	cmp r1, 0
	bge _08085E38
	movs r1, 0
_08085E38:
	cmp r0, 0
	bge _08085E3E
	movs r0, 0
_08085E3E:
	strb r2, [r6]
	strb r1, [r6, 0x1]
	strb r0, [r6, 0x2]
	ldr r0, _08085E80
	ldr r2, [r0]
	mov r0, r8
	add r1, sp, 0x8
	movs r3, 0
	bl SetBGPaletteBufferColorRGB
	adds r5, 0x4
	movs r0, 0x1
	add r8, r0
	subs r4, 0x1
	cmp r4, 0
	bne _08085E0A
_08085E5E:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085E70: .4byte gDungeonPaletteFile
_08085E74: .4byte 0xffffff00
_08085E78: .4byte 0xffff00ff
_08085E7C: .4byte 0xff00ffff
_08085E80: .4byte gDungeonBrightness
_08085E84: .4byte gDungeon
_08085E88: .4byte 0xffff0000
_08085E8C: .4byte gUnknown_202EE8C
_08085E90: .4byte gUnknown_202ECA4
_08085E94: .4byte 0x000181e4
	thumb_func_end SetDungeonBGColorRGB
