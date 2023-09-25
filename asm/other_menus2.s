        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8037A48
sub_8037A48:
	push {r4-r6,lr}
	sub sp, 0x28
	movs r6, 0x1
	movs r0, 0
	mov r1, sp
	movs r2, 0x14
	bl sub_800D670
	add r4, sp, 0x14
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x14
	bl sub_800D670
	ldr r1, _08037AAC
	movs r3, 0x8
	adds r2, r1, 0
	adds r0, r2, 0x4
_08037A6C:
	str r3, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _08037A6C
	ldr r0, [sp, 0x10]
	str r0, [r2]
	ldr r0, [r4, 0x10]
	str r0, [r2, 0x4]
	ldr r5, _08037AB0
	mov r0, sp
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037A8C
	movs r0, 0x1
_08037A8C:
	lsls r0, 24
	cmp r0, 0
	bne _08037AA6
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037AA0
	movs r0, 0x1
_08037AA0:
	lsls r0, 24
	cmp r0, 0
	beq _08037AB4
_08037AA6:
	movs r0, 0
	b _08037B1E
	.align 2, 0
_08037AAC: .4byte gUnknown_202EC40
_08037AB0: .4byte gUnknown_80E6E50
_08037AB4:
	ldr r1, [sp, 0x10]
	cmp r1, 0
	bne _08037AC0
	ldr r0, [r4, 0x10]
	cmp r0, 0x1
	beq _08037B1C
_08037AC0:
	cmp r1, 0x1
	bne _08037ACA
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _08037B1C
_08037ACA:
	cmp r1, 0x2
	bne _08037AD4
	ldr r0, [r4, 0x10]
	cmp r0, 0x3
	beq _08037B1C
_08037AD4:
	cmp r1, 0x3
	bne _08037ADE
	ldr r0, [r4, 0x10]
	cmp r0, 0x2
	beq _08037B1C
_08037ADE:
	cmp r1, 0x9
	bne _08037AE8
	ldr r0, [r4, 0x10]
	cmp r0, 0xA
	beq _08037B1C
_08037AE8:
	cmp r1, 0xA
	bne _08037AF2
	ldr r0, [r4, 0x10]
	cmp r0, 0x9
	beq _08037B1C
_08037AF2:
	cmp r1, 0x4
	bne _08037AFC
	ldr r0, [r4, 0x10]
	cmp r0, 0x5
	beq _08037B1C
_08037AFC:
	cmp r1, 0x5
	bne _08037B06
	ldr r0, [r4, 0x10]
	cmp r0, 0x4
	beq _08037B1C
_08037B06:
	cmp r1, 0x6
	bne _08037B10
	ldr r0, [r4, 0x10]
	cmp r0, 0x7
	beq _08037B1C
_08037B10:
	cmp r1, 0x7
	bne _08037B1A
	ldr r0, [r4, 0x10]
	cmp r0, 0x6
	beq _08037B1C
_08037B1A:
	movs r6, 0
_08037B1C:
	adds r0, r6, 0
_08037B1E:
	add sp, 0x28
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8037A48

	thumb_func_start sub_8037B28
sub_8037B28:
	push {r4,r5,lr}
	sub sp, 0x14
	adds r4, r0, 0
	movs r5, 0
	bl sub_800D414
	ldr r0, _08037B58
	str r5, [r0]
	ldr r5, _08037B5C
	mov r0, sp
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill8
	mov r0, sp
	adds r1, r5, 0
	bl strcpy
	str r4, [sp, 0x10]
	mov r0, sp
	movs r1, 0x14
	bl sub_800D59C
	b _08037B7A
	.align 2, 0
_08037B58: .4byte gUnknown_202EC38
_08037B5C: .4byte gUnknown_80E6E50
_08037B60:
	cmp r5, 0x3
	beq _08037BCC
	cmp r5, 0x4
	beq _08037BD8
	cmp r5, 0x5
	beq _08037BF0
	ldr r2, _08037BC0
	ldr r1, [r2]
	ldr r0, _08037BC4
	cmp r1, r0
	bgt _08037BE4
	adds r0, r1, 0x1
	str r0, [r2]
_08037B7A:
	movs r4, 0
_08037B7C:
	bl sub_80373C4
	bl sub_8012AE8
	cmp r0, 0x3
	bgt _08037B8C
	cmp r0, 0x2
	bge _08037BF0
_08037B8C:
	adds r4, 0x1
	cmp r4, 0
	ble _08037B7C
	bl sub_800D33C
	adds r5, r0, 0
	bl sub_800D570
	cmp r5, 0x2
	bne _08037B60
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08037BFC
	bl sub_8037A48
	lsls r0, 24
	cmp r0, 0
	bne _08037BC8
	movs r4, 0x4
	bl sub_800D520
	bl sub_800D510
	b _08037C06
	.align 2, 0
_08037BC0: .4byte gUnknown_202EC38
_08037BC4: .4byte 0x00000707
_08037BC8:
	movs r4, 0
	b _08037C06
_08037BCC:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x2
	b _08037C08
_08037BD8:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x3
	b _08037C08
_08037BE4:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08037C08
_08037BF0:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08037C08
_08037BFC:
	movs r4, 0x5
	bl sub_800D520
	bl sub_800D510
_08037C06:
	adds r0, r4, 0
_08037C08:
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8037B28

        .align 2,0
