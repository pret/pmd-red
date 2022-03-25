        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start sub_8031D70
sub_8031D70:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, _08031DC4
	movs r0, 0x7C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	stm r0!, {r6}
	bl sub_801317C
	ldr r0, [r5]
	str r4, [r0, 0x10]
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 3
	adds r1, 0x18
	adds r1, r0, r1
	str r1, [r0, 0x14]
	adds r0, 0x18
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x10]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x18
	ldr r0, _08031DC8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8031E00
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08031DC4: .4byte gUnknown_203B334
_08031DC8: .4byte gUnknown_80E1FC4
	thumb_func_end sub_8031D70

	thumb_func_start sub_8031DCC
sub_8031DCC:
	push {lr}
	ldr r0, _08031DEC
	ldr r1, [r0]
	adds r0, r1, 0x4
	ldr r1, [r1, 0x10]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08031DF0
	cmp r0, 0x2
	bne _08031DFA
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08031DFC
	.align 2, 0
_08031DEC: .4byte gUnknown_203B334
_08031DF0:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08031DFC
_08031DFA:
	movs r0, 0
_08031DFC:
	pop {r1}
	bx r1
	thumb_func_end sub_8031DCC

	thumb_func_start sub_8031E00
sub_8031E00:
	push {lr}
	bl sub_8031E58
	bl sub_8031E74
	pop {r0}
	bx r0
	thumb_func_end sub_8031E00

	thumb_func_start sub_8031E10
sub_8031E10:
	push {r4,r5,lr}
	ldr r4, _08031E50
	ldr r2, [r4]
	cmp r2, 0
	beq _08031E4A
	ldr r0, [r2, 0x10]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x18
	ldr r0, _08031E54
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08031E4A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031E50: .4byte gUnknown_203B334
_08031E54: .4byte gUnknown_80E1FA8
	thumb_func_end sub_8031E10

	thumb_func_start sub_8031E58
sub_8031E58:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08031E70
	ldr r0, [r0]
	adds r0, 0x18
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08031E70: .4byte gUnknown_203B334
	thumb_func_end sub_8031E58

	thumb_func_start sub_8031E74
sub_8031E74:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x3C
	ldr r3, _08031EC0
	ldr r5, _08031EC4
	ldr r2, [r5]
	ldr r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 4
	ldr r4, [r3]
	adds r4, r0
	ldr r0, [r2, 0x10]
	bl sub_80073B8
	ldr r2, _08031EC8
	ldr r0, [r5]
	ldr r3, [r0, 0x10]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x14
	movs r1, 0
	bl xxx_call_draw_string
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_803D2C0
	movs r7, 0
	mov r8, r5
_08031EB2:
	cmp r7, 0x4
	ble _08031ED0
	cmp r7, 0xC
	bgt _08031ECC
	movs r6, 0x6
	movs r5, 0x16
	b _08031F00
	.align 2, 0
_08031EC0: .4byte gUnknown_203B480
_08031EC4: .4byte gUnknown_203B334
_08031EC8: .4byte gUnknown_80E1FDC
_08031ECC:
	cmp r7, 0x11
	bgt _08031ED6
_08031ED0:
	movs r6, 0x7
	movs r5, 0x15
	b _08031F00
_08031ED6:
	cmp r7, 0x16
	ble _08031EE8
	cmp r7, 0x1E
	bgt _08031EE4
	movs r6, 0x6
	movs r5, 0x25
	b _08031F00
_08031EE4:
	cmp r7, 0x23
	bgt _08031EEE
_08031EE8:
	movs r6, 0x7
	movs r5, 0x24
	b _08031F00
_08031EEE:
	cmp r7, 0x28
	ble _08031EFC
	cmp r7, 0x30
	bgt _08031EFC
	movs r6, 0x6
	movs r5, 0x34
	b _08031F00
_08031EFC:
	movs r6, 0x7
	movs r5, 0x33
_08031F00:
	adds r0, r7, 0
	movs r1, 0x12
	bl __modsi3
	movs r1, 0xB
	adds r4, r0, 0
	muls r4, r1
	adds r4, 0x6
	mov r0, sp
	adds r0, r7
	adds r0, 0x4
	ldrb r2, [r0]
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_8012C60
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x10]
	adds r2, r5, 0
	adds r2, 0xA
	movs r1, 0x5
	str r1, [sp]
	adds r1, r4, 0
	movs r3, 0xA
	bl sub_80078A4
	adds r7, 0x1
	cmp r7, 0x35
	ble _08031EB2
	ldr r0, _08031F5C
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	bl sub_80073E0
	add sp, 0x3C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031F5C: .4byte gUnknown_203B334
	thumb_func_end sub_8031E74

        .align 2,0
