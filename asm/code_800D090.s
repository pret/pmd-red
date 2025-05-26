	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text




	thumb_func_start sub_800D600
sub_800D600:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r0, _0800D64C
	mov r8, r0
	ldr r7, _0800D650
	ldr r0, [r7]
	lsrs r0, 1
	subs r0, 0x2
	mov r12, r0
	movs r5, 0
_0800D618:
	movs r4, 0
	mov r2, r8
	adds r1, r5, r2
	movs r3, 0
	cmp r4, r12
	bcs _0800D636
	ldr r0, [r7]
	lsrs r0, 1
	subs r2, r0, 0x2
_0800D62A:
	ldrh r0, [r1]
	adds r4, r0
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, r2
	bcc _0800D62A
_0800D636:
	ldr r0, [r7]
	lsrs r0, 1
	ldr r2, _0800D654
	adds r1, r2, 0
	subs r1, r0
	lsls r0, r4, 16
	lsls r1, 16
	cmp r0, r1
	beq _0800D658
	movs r0, 0
	b _0800D666
	.align 2, 0
_0800D64C: .4byte gUnknown_202D910
_0800D650: .4byte gUnknown_202DB74
_0800D654: .4byte 0x0000ffff
_0800D658:
	movs r0, 0x84
	lsls r0, 1
	adds r5, r0
	adds r6, 0x1
	cmp r6, 0x1
	bls _0800D618
	movs r0, 0x1
_0800D666:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800D600

	thumb_func_start sub_800D670
sub_800D670:
	push {lr}
	adds r3, r1, 0
	lsls r1, r0, 5
	adds r1, r0
	lsls r1, 3
	ldr r0, _0800D688
	adds r1, r0
	adds r0, r3, 0
	bl CpuCopy
	pop {r0}
	bx r0
	.align 2, 0
_0800D688: .4byte gUnknown_202D914
	thumb_func_end sub_800D670

	thumb_func_start sub_800D68C
sub_800D68C:
	push {lr}
	adds r1, r0, 0
	lsls r0, r1, 5
	adds r0, r1
	lsls r0, 3
	ldr r1, _0800D6A8
	adds r0, r1
	movs r2, 0x84
	lsls r2, 1
	movs r1, 0
	bl MemoryFill8
	pop {r0}
	bx r0
	.align 2, 0
_0800D6A8: .4byte gUnknown_202D910
	thumb_func_end sub_800D68C

	thumb_func_start sub_800D6AC
sub_800D6AC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _0800D784
	movs r4, 0
	strh r4, [r3]
	ldr r2, _0800D788
	ldrh r1, [r2]
	ldr r0, _0800D78C
	ands r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	ldr r0, _0800D790
	strh r4, [r0]
	subs r2, 0xD8
	movs r0, 0x80
	lsls r0, 6
	str r0, [r2]
	ldrh r0, [r2]
	ldr r3, _0800D794
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0
	str r0, [sp]
	ldr r4, _0800D798
	ldr r2, _0800D79C
	mov r0, sp
	adds r1, r4, 0
	bl CpuSet
	ldr r0, _0800D7A0
	ldr r1, _0800D7A4
	ldr r2, _0800D7A8
	bl CpuSet
	ldr r0, _0800D7AC
	ldr r1, _0800D7B0
	ldr r2, _0800D7B4
	bl CpuSet
	movs r0, 0x1
	negs r0, r0
	str r0, [r4, 0x14]
	adds r0, r4, 0
	adds r0, 0x60
	str r0, [r4, 0x28]
	adds r0, 0x18
	str r0, [r4, 0x2C]
	movs r3, 0
	adds r5, r4, 0
	adds r5, 0xC0
	movs r2, 0
	movs r7, 0x30
	adds r7, r4
	mov r8, r7
	movs r0, 0x90
	adds r0, r4
	mov r12, r0
	adds r6, r4, 0
	adds r6, 0xA8
	movs r7, 0x40
	adds r7, r4
	mov r9, r7
_0800D732:
	lsls r1, r3, 2
	mov r7, r12
	adds r0, r2, r7
	mov r7, r8
	adds r7, 0x4
	mov r8, r7
	subs r7, 0x4
	stm r7!, {r0}
	adds r0, r2, r6
	mov r7, r9
	adds r7, 0x4
	mov r9, r7
	subs r7, 0x4
	stm r7!, {r0}
	adds r0, r4, 0
	adds r0, 0x50
	adds r1, r0
	str r5, [r1]
	adds r5, 0x48
	adds r2, 0x48
	adds r3, 0x1
	cmp r3, 0x1
	ble _0800D732
	movs r0, 0
	ldr r3, _0800D784
	strh r0, [r3]
	ldr r2, _0800D788
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D784: .4byte 0x04000208
_0800D788: .4byte 0x04000200
_0800D78C: .4byte 0x0000ff3f
_0800D790: .4byte 0x04000134
_0800D794: .4byte 0x00004003
_0800D798: .4byte gUnknown_202DCF8
_0800D79C: .4byte 0x05000048
_0800D7A0: .4byte sub_80001E8
_0800D7A4: .4byte gUnknown_202DB78
_0800D7A8: .4byte 0x04000010
_0800D7AC: .4byte sub_8000228
_0800D7B0: .4byte gUnknown_202DBB8
_0800D7B4: .4byte 0x04000050
	thumb_func_end sub_800D6AC

	thumb_func_start sub_800D7B8
sub_800D7B8:
	push {lr}
	ldr r1, _0800D7CC
	ldrb r0, [r1]
	cmp r0, 0
	beq _0800D7C6
	movs r0, 0x1
	strb r0, [r1, 0x8]
_0800D7C6:
	pop {r0}
	bx r0
	.align 2, 0
_0800D7CC: .4byte gUnknown_202DCF8
	thumb_func_end sub_800D7B8

	thumb_func_start sub_800D7D0
sub_800D7D0:
	push {r4,lr}
	ldr r3, _0800D804
	movs r4, 0
	strh r4, [r3]
	ldr r2, _0800D808
	ldrh r1, [r2]
	ldr r0, _0800D80C
	ands r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	ldr r1, _0800D810
	ldr r2, _0800D814
	adds r0, r2, 0
	strh r0, [r1]
	subs r1, 0x1C
	ldr r0, _0800D818
	str r0, [r1]
	adds r1, 0xF6
	movs r0, 0xC0
	strh r0, [r1]
	ldr r0, _0800D81C
	strb r4, [r0, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800D804: .4byte 0x04000208
_0800D808: .4byte 0x04000200
_0800D80C: .4byte 0x0000ff3f
_0800D810: .4byte 0x04000128
_0800D814: .4byte 0x00002003
_0800D818: .4byte 0x0000b1fc
_0800D81C: .4byte gUnknown_202DCF8
	thumb_func_end sub_800D7D0

	thumb_func_start sub_800D820
sub_800D820:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov r12, r1
	ldr r5, _0800D844
	ldr r6, [r5]
	ldr r0, _0800D848
	ldrb r2, [r0, 0x1]
	adds r7, r0, 0
	cmp r2, 0x1
	beq _0800D8AA
	cmp r2, 0x1
	bgt _0800D84C
	cmp r2, 0
	beq _0800D852
	b _0800D8E8
	.align 2, 0
_0800D844: .4byte 0x04000128
_0800D848: .4byte gUnknown_202DCF8
_0800D84C:
	cmp r2, 0x2
	beq _0800D8DC
	b _0800D8E8
_0800D852:
	ldr r1, [r7, 0x14]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0800D8A6
	movs r0, 0x88
	adds r4, r6, 0
	ands r4, r0
	cmp r4, 0x8
	bne _0800D8E8
	movs r1, 0x4
	adds r0, r6, 0
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0800D8A6
	ldr r3, _0800D8C0
	strh r0, [r3]
	ldr r2, _0800D8C4
	ldrh r1, [r2]
	ldr r0, _0800D8C8
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, 0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, 0x1
	strh r0, [r3]
	ldrb r1, [r5, 0x1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldr r1, _0800D8CC
	movs r0, 0xC0
	strh r0, [r1]
	subs r1, 0xF6
	ldr r0, _0800D8D0
	str r0, [r1]
	strb r4, [r7]
_0800D8A6:
	movs r0, 0x1
	strb r0, [r7, 0x1]
_0800D8AA:
	ldr r1, _0800D8D4
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0800D8DC
	ldrb r0, [r1, 0xA]
	cmp r0, 0x7
	bhi _0800D8D8
	adds r0, 0x1
	strb r0, [r1, 0xA]
	b _0800D8DC
	.align 2, 0
_0800D8C0: .4byte 0x04000208
_0800D8C4: .4byte 0x04000200
_0800D8C8: .4byte 0x0000ff7f
_0800D8CC: .4byte 0x04000202
_0800D8D0: .4byte 0x0000b1fc
_0800D8D4: .4byte gUnknown_202DCF8
_0800D8D8:
	movs r0, 0x2
	strb r0, [r1, 0x1]
_0800D8DC:
	mov r0, r12
	bl sub_800D9B8
	mov r0, r8
	bl sub_800D944
_0800D8E8:
	ldr r1, _0800D908
	ldrb r0, [r1, 0xB]
	adds r0, 0x1
	strb r0, [r1, 0xB]
	ldrb r3, [r1, 0x3]
	ldrb r0, [r1, 0x2]
	lsls r2, r0, 8
	ldrb r0, [r1]
	adds r7, r1, 0
	cmp r0, 0x8
	bne _0800D90C
	movs r0, 0x80
	orrs r0, r2
	orrs r0, r3
	b _0800D910
	.align 2, 0
_0800D908: .4byte gUnknown_202DCF8
_0800D90C:
	adds r0, r3, 0
	orrs r0, r2
_0800D910:
	adds r2, r0, 0
	ldrb r0, [r7, 0x9]
	cmp r0, 0
	beq _0800D91E
	movs r0, 0x80
	lsls r0, 5
	orrs r2, r0
_0800D91E:
	ldrb r0, [r7, 0xA]
	lsrs r0, 3
	lsls r1, r0, 15
	lsls r0, r6, 26
	lsrs r0, 30
	cmp r0, 0x1
	bls _0800D936
	movs r0, 0x80
	lsls r0, 6
	orrs r0, r1
	orrs r0, r2
	b _0800D93A
_0800D936:
	adds r0, r2, 0
	orrs r0, r1
_0800D93A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_800D820

	thumb_func_start sub_800D944
sub_800D944:
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, _0800D9AC
	ldr r2, [r4, 0x28]
	ldrb r1, [r4, 0xB]
	strb r1, [r2]
	ldr r3, [r4, 0x28]
	ldrb r1, [r4, 0x2]
	ldrb r2, [r4, 0x3]
	eors r1, r2
	strb r1, [r3, 0x1]
	ldr r1, [r4, 0x28]
	strh r5, [r1, 0x2]
	ldr r1, [r4, 0x28]
	adds r1, 0x4
	ldr r2, _0800D9B0
	bl CpuSet
	movs r2, 0
	ldr r1, [r4, 0x28]
_0800D96C:
	ldrh r0, [r1]
	adds r5, r0
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x9
	bls _0800D96C
	adds r2, r4, 0
	ldr r1, [r2, 0x28]
	mvns r0, r5
	subs r0, 0xC
	strh r0, [r1, 0x2]
	ldrb r0, [r2]
	cmp r0, 0
	beq _0800D98E
	ldr r1, _0800D9B4
	movs r0, 0
	strh r0, [r1]
_0800D98E:
	movs r0, 0x1
	negs r0, r0
	str r0, [r4, 0x14]
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800D9A6
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0800D9A6
	ldr r1, _0800D9B4
	movs r0, 0xC0
	strh r0, [r1]
_0800D9A6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D9AC: .4byte gUnknown_202DCF8
_0800D9B0: .4byte 0x04000004
_0800D9B4: .4byte 0x0400010e
	thumb_func_end sub_800D944

	thumb_func_start sub_800D9B8
sub_800D9B8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r0, [sp, 0x8]
	ldr r0, _0800DA68
	bl _call_via_r0
	str r0, [sp]
	ldr r1, _0800DA6C
	movs r0, 0
	strb r0, [r1, 0x3]
	movs r6, 0
	add r0, sp, 0x4
	mov r10, r0
	mov r9, r1
	movs r1, 0x50
	add r1, r9
	mov r8, r1
_0800D9E2:
	movs r3, 0
	movs r2, 0
	lsls r5, r6, 2
	mov r0, sp
	adds r4, r0, r6
	adds r7, r6, 0x1
	mov r1, r8
	adds r0, r5, r1
	ldr r1, [r0]
_0800D9F4:
	ldrh r0, [r1]
	adds r3, r0
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x9
	bls _0800D9F4
	ldrb r0, [r4]
	cmp r0, 0
	beq _0800DA32
	lsls r0, r3, 16
	asrs r0, 16
	movs r2, 0xD
	negs r2, r2
	cmp r0, r2
	bne _0800DA32
	mov r1, r8
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, 0x4
	lsls r1, r6, 4
	ldr r2, [sp, 0x8]
	adds r1, r2, r1
	ldr r2, _0800DA70
	bl CpuSet
	movs r0, 0x1
	lsls r0, r6
	mov r2, r9
	ldrb r1, [r2, 0x3]
	orrs r0, r1
	strb r0, [r2, 0x3]
_0800DA32:
	movs r0, 0
	str r0, [sp, 0x4]
	mov r1, r8
	adds r0, r5, r1
	ldr r1, [r0]
	adds r1, 0x4
	mov r0, r10
	ldr r2, _0800DA74
	bl CpuSet
	adds r6, r7, 0
	cmp r6, 0x1
	ble _0800D9E2
	ldr r1, _0800DA6C
	ldrb r0, [r1, 0x2]
	ldrb r2, [r1, 0x3]
	orrs r0, r2
	strb r0, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800DA68: .4byte gUnknown_202DB78
_0800DA6C: .4byte gUnknown_202DCF8
_0800DA70: .4byte 0x04000004
_0800DA74: .4byte 0x05000004
	thumb_func_end sub_800D9B8

	.align 2, 0 @ Don't pad with nop.
