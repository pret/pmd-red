	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801D220
sub_801D220:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _0801D248
	ldr r0, [r4]
	adds r0, 0xB8
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _0801D250
	cmp r0, 0x1
	beq _0801D2C0
	movs r2, 0
	adds r7, r4, 0
	ldr r3, _0801D24C
	b _0801D368
	.align 2, 0
_0801D248: .4byte gUnknown_203B250
_0801D24C: .4byte gUnknown_80DBE7C
_0801D250:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D290
	adds r7, r4, 0
	ldr r0, _0801D288
	mov r9, r0
	mov r12, r7
	ldr r2, _0801D28C
	mov r8, r2
	movs r3, 0
	movs r2, 0x3
_0801D26C:
	mov r4, r12
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r8
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D26C
	b _0801D2F6
	.align 2, 0
_0801D288: .4byte gUnknown_80DBE98
_0801D28C: .4byte gUnknown_80DBE7C
_0801D290:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D2BC
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D29C:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D29C
	b _0801D34E
	.align 2, 0
_0801D2BC: .4byte gUnknown_80DBEB0
_0801D2C0:
	bl sub_801D4C0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801D324
	adds r7, r4, 0
	ldr r2, _0801D31C
	mov r9, r2
	mov r8, r7
	ldr r3, _0801D320
	mov r12, r3
	movs r3, 0
	movs r2, 0x3
_0801D2DC:
	mov r4, r8
	ldr r1, [r4]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r12
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D2DC
_0801D2F6:
	ldr r1, [r7]
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x9
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D31C: .4byte gUnknown_80DBE98
_0801D320: .4byte gUnknown_80DBE7C
_0801D324:
	adds r7, r4, 0
	mov r8, r7
	ldr r6, _0801D364
	mov r9, r6
	movs r3, 0
	movs r2, 0x3
_0801D330:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xB8
	mov r0, r9
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	movs r0, 0x18
	add r9, r0
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801D330
_0801D34E:
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xB8
	adds r1, 0x68
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC4
	movs r1, 0x8
	strh r1, [r0]
	b _0801D384
	.align 2, 0
_0801D364: .4byte gUnknown_80DBEB0
_0801D368:
	ldr r0, [r7]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	adds r0, 0xB8
	adds r1, r3, 0
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0801D368
_0801D384:
	bl ResetUnusedInputStruct
	ldr r0, _0801D3A4
	ldr r0, [r0]
	adds r0, 0xB8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D3A4: .4byte gUnknown_203B250
	thumb_func_end sub_801D220

        .align 2,0
