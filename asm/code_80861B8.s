	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_80861B8
sub_80861B8:
	push {r4,r5,lr}
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, [r0, 0x70]
	adds r1, r4, 0
	bl sub_806CDD4
	adds r5, 0xFE
	strb r4, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80861B8

	thumb_func_start sub_80861D4
sub_80861D4:
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	bl sub_806CDD4
	adds r0, r4, 0
	bl sub_80861EC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80861D4

	thumb_func_start sub_80861EC
sub_80861EC:
	ldr r0, [r0, 0x70]
	adds r0, 0xFE
	movs r1, 0x63
	strb r1, [r0]
	bx lr
	thumb_func_end sub_80861EC

	thumb_func_start sub_80861F8
sub_80861F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	adds r6, r1, 0
	lsls r0, 16
	asrs r0, 16
	adds r5, r0, 0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	bl sub_800EE5C
	bl sub_800EF64
	movs r0, 0x46
	bl sub_803E46C
	ldr r0, [r6, 0x70]
	mov r8, r0
	movs r1, 0
	mov r9, r1
	str r1, [sp, 0x28]
	adds r0, r5, 0
	bl sub_800E700
	adds r7, r0, 0
	add r4, sp, 0x28
	movs r2, 0x1
	negs r2, r2
	cmp r7, r2
	beq _0808624A
	adds r1, r6, 0
	adds r1, 0x28
	lsls r2, r7, 24
	lsrs r2, 24
	adds r0, r4, 0
	bl sub_800569C
_0808624A:
	str r5, [sp]
	mov r3, r9
	str r3, [sp, 0x4]
	mov r0, r8
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	mov r1, sp
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _08086262
	adds r0, 0xFF
_08086262:
	asrs r0, 8
	strh r0, [r1, 0xC]
	mov r1, sp
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _08086270
	adds r0, 0xFF
_08086270:
	asrs r0, 8
	strh r0, [r1, 0xE]
	mov r1, sp
	ldrh r0, [r4]
	strh r0, [r1, 0x10]
	add r0, sp, 0x28
	ldrh r0, [r0, 0x2]
	strh r0, [r1, 0x12]
	str r7, [sp, 0x14]
	ldr r0, _080862B4
	str r0, [sp, 0x18]
	add r1, sp, 0x1C
	ldr r0, _080862B8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	mov r0, sp
	bl sub_800E890
	mov r4, r10
	cmp r4, 0
	beq _080862A2
	bl sub_8085F44
	movs r0, 0x1
	negs r0, r0
_080862A2:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080862B4: .4byte 0x0000ffff
_080862B8: .4byte gUnknown_8107380
	thumb_func_end sub_80861F8

        .align 2,0
