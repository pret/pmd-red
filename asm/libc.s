	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start memcpy
memcpy:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r3, r1, 0
	cmp r2, 0xF
	bls _080B2700
	adds r0, r3, 0
	orrs r0, r5
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B2700
	adds r1, r5, 0
_080B26DA:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x10
	cmp r2, 0xF
	bhi _080B26DA
	cmp r2, 0x3
	bls _080B26FE
_080B26F4:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x4
	cmp r2, 0x3
	bhi _080B26F4
_080B26FE:
	adds r4, r1, 0
_080B2700:
	subs r2, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080B271A
	adds r1, r0, 0
_080B270C:
	ldrb r0, [r3]
	strb r0, [r4]
	adds r3, 0x1
	adds r4, 0x1
	subs r2, 0x1
	cmp r2, r1
	bne _080B270C
_080B271A:
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end memcpy

	thumb_func_start memset
memset:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r5, 0
	cmp r2, 0x3
	bls _080B2766
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0
	bne _080B2766
	adds r1, r5, 0
	movs r0, 0xFF
	ands r4, r0
	lsls r3, r4, 8
	orrs r3, r4
	lsls r0, r3, 16
	orrs r3, r0
	cmp r2, 0xF
	bls _080B275A
_080B2746:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, 0x10
	cmp r2, 0xF
	bhi _080B2746
	b _080B275A
_080B2756:
	stm r1!, {r3}
	subs r2, 0x4
_080B275A:
	cmp r2, 0x3
	bhi _080B2756
	adds r3, r1, 0
	b _080B2766
_080B2762:
	strb r4, [r3]
	adds r3, 0x1
_080B2766:
	adds r0, r2, 0
	subs r2, 0x1
	cmp r0, 0
	bne _080B2762
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end memset

	thumb_func_start _sprintf_r
_sprintf_r:
	push {r2,r3}
	push {r4,r5,lr}
	sub sp, 0x58
	ldr r4, [sp, 0x64]
	mov r3, sp
	movs r5, 0
	movs r2, 0x82
	lsls r2, 2
	strh r2, [r3, 0xC]
	str r1, [sp]
	str r1, [sp, 0x10]
	ldr r1, _080B27AC
	str r1, [sp, 0x8]
	str r1, [sp, 0x14]
	str r0, [sp, 0x54]
	add r2, sp, 0x68
	mov r0, sp
	adds r1, r4, 0
	bl vfprintf
	ldr r1, [sp]
	strb r5, [r1]
	add sp, 0x58
	pop {r4,r5}
	pop {r3}
	add sp, 0x8
	bx r3
	.align 2, 0
_080B27AC: .4byte 0x7fffffff
	thumb_func_end _sprintf_r

	thumb_func_start sprintf
sprintf:
	push {r1-r3}
	push {r4,lr}
	sub sp, 0x58
	ldr r1, [sp, 0x60]
	mov r3, sp
	movs r4, 0
	movs r2, 0x82
	lsls r2, 2
	strh r2, [r3, 0xC]
	str r0, [sp]
	str r0, [sp, 0x10]
	ldr r0, _080B27E8
	str r0, [sp, 0x8]
	str r0, [sp, 0x14]
	ldr r0, _080B27EC
	ldr r0, [r0]
	str r0, [sp, 0x54]
	add r2, sp, 0x64
	mov r0, sp
	bl vfprintf
	ldr r1, [sp]
	strb r4, [r1]
	add sp, 0x58
	pop {r4}
	pop {r3}
	add sp, 0xC
	bx r3
	.align 2, 0
_080B27E8: .4byte 0x7fffffff
_080B27EC: .4byte gUnknown_203B7A8
	thumb_func_end sprintf

	thumb_func_start strcat
strcat:
	push {r4-r6,lr}
	adds r2, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	movs r0, 0x3
	ands r0, r4
	cmp r0, 0
	bne _080B2826
	ldr r1, [r4]
	ldr r5, _080B280C
	adds r0, r1, r5
	bics r0, r1
	ldr r3, _080B2810
	b _080B281C
	.align 2, 0
_080B280C: .4byte 0xfefefeff
_080B2810: .4byte 0x80808080
_080B2814:
	adds r2, 0x4
	ldr r1, [r2]
	adds r0, r1, r5
	bics r0, r1
_080B281C:
	ands r0, r3
	cmp r0, 0
	beq _080B2814
	b _080B2826
_080B2824:
	adds r2, 0x1
_080B2826:
	ldrb r0, [r2]
	cmp r0, 0
	bne _080B2824
	adds r0, r2, 0
	adds r1, r6, 0
	bl strcpy
	adds r0, r4, 0
	pop {r4-r6,pc}
	thumb_func_end strcat

	thumb_func_start strcmp
strcmp:
	push {r4,r5,lr}
	adds r2, r0, 0
	adds r3, r1, 0
	orrs r0, r3
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B287E
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _080B287E
	ldr r5, _080B2864
	ldr r4, _080B2868
_080B2854:
	ldr r1, [r2]
	adds r0, r1, r5
	bics r0, r1
	ands r0, r4
	cmp r0, 0
	beq _080B286C
	movs r0, 0
	b _080B2890
	.align 2, 0
_080B2864: .4byte 0xfefefeff
_080B2868: .4byte 0x80808080
_080B286C:
	adds r2, 0x4
	adds r3, 0x4
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	beq _080B2854
	b _080B287E
_080B287A:
	adds r2, 0x1
	adds r3, 0x1
_080B287E:
	ldrb r0, [r2]
	cmp r0, 0
	beq _080B288A
	ldrb r1, [r3]
	cmp r0, r1
	beq _080B287A
_080B288A:
	ldrb r2, [r2]
	ldrb r3, [r3]
	subs r0, r2, r3
_080B2890:
	pop {r4,r5,pc}
	thumb_func_end strcmp

	thumb_func_start strcpy
strcpy:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r3, r6, 0
	adds r2, r1, 0
	adds r0, r2, 0
	orrs r0, r6
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B28CC
	ldr r1, [r2]
	ldr r5, _080B28B4
	adds r0, r1, r5
	bics r0, r1
	ldr r4, _080B28B8
	b _080B28C6
	.align 2, 0
_080B28B4: .4byte 0xfefefeff
_080B28B8: .4byte 0x80808080
_080B28BC:
	ldm r2!, {r0}
	stm r3!, {r0}
	ldr r1, [r2]
	adds r0, r1, r5
	bics r0, r1
_080B28C6:
	ands r0, r4
	cmp r0, 0
	beq _080B28BC
_080B28CC:
	ldrb r0, [r2]
	strb r0, [r3]
	lsls r0, 24
	adds r2, 0x1
	adds r3, 0x1
	cmp r0, 0
	bne _080B28CC
	adds r0, r6, 0
	pop {r4-r6,pc}
	thumb_func_end strcpy

	thumb_func_start strlen
strlen:
	push {r4,r5,lr}
	adds r1, r0, 0
	adds r5, r1, 0
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B2918
	adds r2, r1, 0
	ldr r1, [r2]
	ldr r4, _080B28FC
	adds r0, r1, r4
	bics r0, r1
	ldr r3, _080B2900
	b _080B290C
	.align 2, 0
_080B28FC: .4byte 0xfefefeff
_080B2900: .4byte 0x80808080
_080B2904:
	adds r2, 0x4
	ldr r1, [r2]
	adds r0, r1, r4
	bics r0, r1
_080B290C:
	ands r0, r3
	cmp r0, 0
	beq _080B2904
	adds r1, r2, 0
	b _080B2918
_080B2916:
	adds r1, 0x1
_080B2918:
	ldrb r0, [r1]
	cmp r0, 0
	bne _080B2916
	subs r0, r1, r5
	pop {r4,r5,pc}
	thumb_func_end strlen

	thumb_func_start strncpy
strncpy:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r7, 0
	adds r3, r1, 0
	adds r0, r3, 0
	orrs r0, r7
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B2966
	cmp r2, 0x3
	bls _080B2966
	ldr r1, [r3]
	ldr r6, _080B2948
	adds r0, r1, r6
	bics r0, r1
	ldr r5, _080B294C
	b _080B2960
	.align 2, 0
_080B2948: .4byte 0xfefefeff
_080B294C: .4byte 0x80808080
_080B2950:
	subs r2, 0x4
	ldm r3!, {r0}
	stm r4!, {r0}
	cmp r2, 0x3
	bls _080B2966
	ldr r1, [r3]
	adds r0, r1, r6
	bics r0, r1
_080B2960:
	ands r0, r5
	cmp r0, 0
	beq _080B2950
_080B2966:
	cmp r2, 0
	beq _080B297A
	subs r2, 0x1
	ldrb r0, [r3]
	strb r0, [r4]
	lsls r0, 24
	adds r3, 0x1
	adds r4, 0x1
	cmp r0, 0
	bne _080B2966
_080B297A:
	adds r0, r2, 0
	subs r2, 0x1
	cmp r0, 0
	beq _080B2990
	movs r1, 0
_080B2984:
	strb r1, [r4]
	adds r4, 0x1
	adds r0, r2, 0
	subs r2, 0x1
	cmp r0, 0
	bne _080B2984
_080B2990:
	adds r0, r7, 0
	pop {r4-r7,pc}
	thumb_func_end strncpy

	thumb_func_start __sprint
__sprint:
	push {r4,lr}
	adds r4, r1, 0
	ldr r1, [r4, 0x8]
	cmp r1, 0
	beq _080B29AC
	adds r1, r4, 0
	bl sub_80B4EA4
	movs r1, 0
	str r1, [r4, 0x8]
	str r1, [r4, 0x4]
	b _080B29B0
_080B29AC:
	str r1, [r4, 0x4]
	movs r0, 0
_080B29B0:
	pop {r4,pc}
	thumb_func_end __sprint

	thumb_func_start __sbprintf
__sbprintf:
	push {r4,r5,lr}
	ldr r4, _080B2A24
	add sp, r4
	adds r5, r0, 0
	ldr r0, [r5, 0x54]
	str r0, [sp, 0x54]
	mov r3, sp
	movs r0, 0x3
	negs r0, r0
	ldrh r4, [r5, 0xC]
	ands r0, r4
	movs r4, 0
	strh r0, [r3, 0xC]
	ldrh r0, [r5, 0xE]
	strh r0, [r3, 0xE]
	ldr r0, [r5, 0x1C]
	str r0, [sp, 0x1C]
	ldr r0, [r5, 0x24]
	str r0, [sp, 0x24]
	add r0, sp, 0x58
	str r0, [sp]
	str r0, [sp, 0x10]
	movs r0, 0x80
	lsls r0, 3
	str r0, [sp, 0x8]
	str r0, [sp, 0x14]
	str r4, [sp, 0x18]
	mov r0, sp
	bl vfprintf
	adds r4, r0, 0
	cmp r4, 0
	blt _080B2A04
	mov r0, sp
	bl sub_80B4A34
	cmp r0, 0
	beq _080B2A04
	movs r4, 0x1
	negs r4, r4
_080B2A04:
	mov r1, sp
	movs r0, 0x40
	ldrh r1, [r1, 0xC]
	ands r0, r1
	cmp r0, 0
	beq _080B2A18
	movs r0, 0x40
	ldrh r1, [r5, 0xC]
	orrs r0, r1
	strh r0, [r5, 0xC]
_080B2A18:
	adds r0, r4, 0
	movs r3, 0x8B
	lsls r3, 3
	add sp, r3
	pop {r4,r5,pc}
	.align 2, 0
_080B2A24: .4byte 0xfffffba8
	thumb_func_end __sbprintf

	thumb_func_start vfprintf
vfprintf:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r3, r2, 0
	ldr r0, [r4, 0x54]
	adds r1, r4, 0
	adds r2, r5, 0
	bl _vfprintf_r
	pop {r4,r5,pc}
	thumb_func_end vfprintf

	thumb_func_start _vfprintf_r
_vfprintf_r:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080B2AA4
	add sp, r4
	str r0, [sp, 0x1DC]
	str r1, [sp, 0x1E0]
	adds r4, r2, 0
	mov r10, r3
	bl sub_80B516C
	ldr r0, [r0]
	str r0, [sp, 0x1F8]
	movs r1, 0
	add r0, sp, 0x1D0
	str r1, [r0]
	ldr r1, [sp, 0x1E0]
	ldr r0, [r1, 0x54]
	cmp r0, 0
	bne _080B2A6E
	ldr r0, _080B2AA8
	ldr r0, [r0]
	str r0, [r1, 0x54]
_080B2A6E:
	ldr r2, [sp, 0x1E0]
	ldr r1, [r2, 0x54]
	ldr r0, [r1, 0x38]
	cmp r0, 0
	bne _080B2A7E
	adds r0, r1, 0
	bl sub_80B4BC4
_080B2A7E:
	movs r0, 0x8
	ldr r1, [sp, 0x1E0]
	ldrh r1, [r1, 0xC]
	ands r0, r1
	cmp r0, 0
	beq _080B2A92
	ldr r2, [sp, 0x1E0]
	ldr r0, [r2, 0x10]
	cmp r0, 0
	bne _080B2AAC
_080B2A92:
	ldr r0, [sp, 0x1E0]
	bl sub_80B3B34
	cmp r0, 0
	beq _080B2AAC
	movs r0, 0x1
	negs r0, r0
	bl _080B398C
	.align 2, 0
_080B2AA4: .4byte 0xfffffde0
_080B2AA8: .4byte gUnknown_203B7A8
_080B2AAC:
	movs r0, 0x1A
	ldr r1, [sp, 0x1E0]
	ldrh r1, [r1, 0xC]
	ands r0, r1
	cmp r0, 0xA
	bne _080B2AD0
	ldr r2, [sp, 0x1E0]
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	cmp r0, 0
	blt _080B2AD0
	adds r0, r2, 0
	adds r1, r4, 0
	mov r2, r10
	bl __sbprintf
	bl _080B398C
_080B2AD0:
	str r4, [sp, 0x1E4]
	add r1, sp, 0x1C
	add r5, sp, 0x28
	str r5, [sp, 0x1C]
	movs r0, 0
	str r0, [r1, 0x8]
	str r0, [r1, 0x4]
	movs r2, 0
	str r2, [sp, 0x1F0]
	mov r9, r1
	movs r4, 0xE6
	lsls r4, 1
	add r4, sp
	str r4, [sp, 0x214]
	movs r0, 0xE8
	lsls r0, 1
	add r0, sp
	str r0, [sp, 0x218]
_080B2AF4:
	ldr r1, [sp, 0x1E4]
	mov r8, r1
_080B2AF8:
	ldr r0, _080B2BA4
	ldr r0, [r0]
	ldr r1, _080B2BA8
	ldr r3, [r1]
	ldr r2, [sp, 0x218]
	str r2, [sp]
	ldr r1, [sp, 0x214]
	ldr r2, [sp, 0x1E4]
	bl sub_80B5774
	adds r4, r0, 0
	cmp r4, 0
	ble _080B2B26
	ldr r0, [sp, 0x1E4]
	adds r0, r4
	str r0, [sp, 0x1E4]
	add r0, sp, 0x1CC
	ldr r0, [r0]
	cmp r0, 0x25
	bne _080B2AF8
	ldr r1, [sp, 0x1E4]
	subs r1, 0x1
	str r1, [sp, 0x1E4]
_080B2B26:
	ldr r2, [sp, 0x1E4]
	mov r0, r8
	subs r6, r2, r0
	cmp r6, 0
	beq _080B2B5E
	str r0, [r5]
	str r6, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, r6
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B2B58
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	beq _080B2B56
	bl _080B3978
_080B2B56:
	add r5, sp, 0x28
_080B2B58:
	ldr r2, [sp, 0x1F0]
	adds r2, r6
	str r2, [sp, 0x1F0]
_080B2B5E:
	cmp r4, 0
	bgt _080B2B66
	bl _080B3960
_080B2B66:
	ldr r4, [sp, 0x1E4]
	adds r4, 0x1
	str r4, [sp, 0x1E4]
	movs r0, 0
	str r0, [sp, 0x1EC]
	movs r1, 0
	str r1, [sp, 0x208]
	movs r2, 0
	str r2, [sp, 0x1F4]
	movs r6, 0x1
	negs r6, r6
	ldr r0, _080B2BAC
	add r0, sp
	strb r2, [r0]
_080B2B82:
	ldr r0, [sp, 0x1E4]
	ldrb r0, [r0]
	str r0, [sp, 0x1E8]
	ldr r1, [sp, 0x1E4]
	adds r1, 0x1
	str r1, [sp, 0x1E4]
_080B2B8E:
	ldr r0, [sp, 0x1E8]
	subs r0, 0x20
	cmp r0, 0x58
	bls _080B2B98
	b _080B324A
_080B2B98:
	lsls r0, 2
	ldr r1, _080B2BB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B2BA4: .4byte gUnknown_203B7A8
_080B2BA8: .4byte gUnknown_203B7AC
_080B2BAC: .4byte 0x000001c9
_080B2BB0: .4byte _080B2BB4
	.align 2, 0
_080B2BB4:
	.4byte _080B2D18
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B2D30
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B2D34
	.4byte _080B2D4E
	.4byte _080B324A
	.4byte _080B2D4A
	.4byte _080B2D5C
	.4byte _080B324A
	.4byte _080B2DBC
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B2DC0
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B2E2A
	.4byte _080B2E7C
	.4byte _080B324A
	.4byte _080B2E7C
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B2DE4
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B3032
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B30CA
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B3106
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B2E18
	.4byte _080B2E32
	.4byte _080B2E7C
	.4byte _080B2E7C
	.4byte _080B2E7C
	.4byte _080B2DE8
	.4byte _080B2E32
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B2DEC
	.4byte _080B324A
	.4byte _080B2FEC
	.4byte _080B303A
	.4byte _080B3068
	.4byte _080B2E0E
	.4byte _080B324A
	.4byte _080B3088
	.4byte _080B324A
	.4byte _080B30D2
	.4byte _080B324A
	.4byte _080B324A
	.4byte _080B3110
_080B2D18:
	ldr r1, _080B2D2C
	add r1, sp
	ldrb r0, [r1]
	cmp r0, 0
	beq _080B2D24
	b _080B2B82
_080B2D24:
	movs r0, 0x20
	strb r0, [r1]
	b _080B2B82
	.align 2, 0
_080B2D2C: .4byte 0x000001c9
_080B2D30:
	movs r0, 0x1
	b _080B2DFC
_080B2D34:
	movs r4, 0x4
	add r10, r4
	mov r0, r10
	subs r0, 0x4
	ldr r0, [r0]
	str r0, [sp, 0x1F4]
	cmp r0, 0
	blt _080B2D46
	b _080B2B82
_080B2D46:
	negs r0, r0
	str r0, [sp, 0x1F4]
_080B2D4A:
	movs r0, 0x4
	b _080B2E10
_080B2D4E:
	ldr r1, _080B2D58
	add r1, sp
	movs r0, 0x2B
	strb r0, [r1]
	b _080B2B82
	.align 2, 0
_080B2D58: .4byte 0x000001c9
_080B2D5C:
	ldr r2, [sp, 0x1E4]
	ldrb r2, [r2]
	str r2, [sp, 0x1E8]
	ldr r4, [sp, 0x1E4]
	adds r4, 0x1
	str r4, [sp, 0x1E4]
	cmp r2, 0x2A
	bne _080B2D86
	movs r0, 0x4
	add r10, r0
	mov r0, r10
	subs r0, 0x4
	ldr r4, [r0]
	adds r6, r4, 0
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	blt _080B2D82
	b _080B2B82
_080B2D82:
	adds r6, r0, 0
	b _080B2B82
_080B2D86:
	movs r4, 0
	ldr r0, [sp, 0x1E8]
	b _080B2DA6
_080B2D8C:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 1
	subs r0, 0x30
	ldr r1, [sp, 0x1E8]
	adds r4, r0, r1
	ldr r2, [sp, 0x1E4]
	ldrb r2, [r2]
	str r2, [sp, 0x1E8]
	ldr r0, [sp, 0x1E4]
	adds r0, 0x1
	str r0, [sp, 0x1E4]
	adds r0, r2, 0
_080B2DA6:
	subs r0, 0x30
	cmp r0, 0x9
	bls _080B2D8C
	adds r6, r4, 0
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	blt _080B2DB8
	b _080B2B8E
_080B2DB8:
	adds r6, r0, 0
	b _080B2B8E
_080B2DBC:
	movs r0, 0x80
	b _080B2E10
_080B2DC0:
	movs r4, 0
_080B2DC2:
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 1
	subs r0, 0x30
	ldr r2, [sp, 0x1E8]
	adds r4, r0, r2
	ldr r0, [sp, 0x1E4]
	ldrb r0, [r0]
	str r0, [sp, 0x1E8]
	ldr r1, [sp, 0x1E4]
	adds r1, 0x1
	str r1, [sp, 0x1E4]
	subs r0, 0x30
	cmp r0, 0x9
	bls _080B2DC2
	str r4, [sp, 0x1F4]
	b _080B2B8E
_080B2DE4:
	movs r0, 0x8
	b _080B2DFC
_080B2DE8:
	movs r0, 0x40
	b _080B2E06
_080B2DEC:
	ldr r0, [sp, 0x1E4]
	ldrb r0, [r0]
	cmp r0, 0x6C
	bne _080B2E04
	ldr r1, [sp, 0x1E4]
	adds r1, 0x1
	str r1, [sp, 0x1E4]
	movs r0, 0x20
_080B2DFC:
	ldr r2, [sp, 0x1EC]
	orrs r2, r0
	str r2, [sp, 0x1EC]
	b _080B2B82
_080B2E04:
	movs r0, 0x10
_080B2E06:
	ldr r4, [sp, 0x1EC]
	orrs r4, r0
	str r4, [sp, 0x1EC]
	b _080B2B82
_080B2E0E:
	movs r0, 0x20
_080B2E10:
	ldr r1, [sp, 0x1EC]
	orrs r1, r0
	str r1, [sp, 0x1EC]
	b _080B2B82
_080B2E18:
	add r2, sp, 0x68
	mov r8, r2
	movs r4, 0x4
	add r10, r4
	mov r0, r10
	subs r0, 0x4
	ldr r0, [r0]
	strb r0, [r2]
	b _080B3258
_080B2E2A:
	movs r0, 0x10
	ldr r1, [sp, 0x1EC]
	orrs r1, r0
	str r1, [sp, 0x1EC]
_080B2E32:
	movs r0, 0x10
	ldr r2, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0
	beq _080B2E42
	movs r4, 0x4
	add r10, r4
	b _080B2E5E
_080B2E42:
	movs r0, 0x40
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B2E5A
	movs r2, 0x4
	add r10, r2
	mov r0, r10
	subs r0, 0x4
	movs r1, 0
	ldrsh r4, [r0, r1]
	b _080B2E64
_080B2E5A:
	movs r2, 0x4
	add r10, r2
_080B2E5E:
	mov r0, r10
	subs r0, 0x4
	ldr r4, [r0]
_080B2E64:
	cmp r4, 0
	bge _080B2E72
	negs r4, r4
	ldr r1, _080B2E78
	add r1, sp
	movs r0, 0x2D
	strb r0, [r1]
_080B2E72:
	movs r2, 0x1
	b _080B315E
	.align 2, 0
_080B2E78: .4byte 0x000001c9
_080B2E7C:
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	bne _080B2E88
	movs r6, 0x6
	b _080B2E98
_080B2E88:
	ldr r4, [sp, 0x1E8]
	cmp r4, 0x67
	beq _080B2E92
	cmp r4, 0x47
	bne _080B2E98
_080B2E92:
	cmp r6, 0
	bne _080B2E98
	movs r6, 0x1
_080B2E98:
	movs r0, 0x8
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	movs r2, 0x8
	add r10, r2
	mov r0, r10
	subs r0, 0x8
	ldr r1, [r0]
	ldr r2, [r0, 0x4]
	str r1, [sp, 0x1FC]
	str r2, [sp, 0x200]
	ldr r0, [sp, 0x1FC]
	ldr r1, [sp, 0x200]
	bl sub_80B6180
	cmp r0, 0
	beq _080B2EEC
	ldr r3, _080B2EE0
	ldr r2, _080B2EDC
	ldr r0, [sp, 0x1FC]
	ldr r1, [sp, 0x200]
	bl __ltdf2
	cmp r0, 0
	bge _080B2ED2
	ldr r1, _080B2EE4
	add r1, sp
	movs r0, 0x2D
	strb r0, [r1]
_080B2ED2:
	ldr r2, _080B2EE8
	mov r8, r2
	movs r3, 0x3
	b _080B3262
	.align 2, 0
_080B2EDC: .4byte 0x00000000
_080B2EE0: .4byte 0x00000000
_080B2EE4: .4byte 0x000001c9
_080B2EE8: .4byte gUnknown_826FE04
_080B2EEC:
	ldr r0, [sp, 0x1FC]
	ldr r1, [sp, 0x200]
	bl sub_80B61A4
	cmp r0, 0
	beq _080B2F04
	ldr r4, _080B2F00
	mov r8, r4
	movs r3, 0x3
	b _080B3262
	.align 2, 0
_080B2F00: .4byte gUnknown_826FE08
_080B2F04:
	movs r0, 0x80
	lsls r0, 1
	ldr r1, [sp, 0x1EC]
	orrs r1, r0
	str r1, [sp, 0x1EC]
	str r1, [sp]
	add r0, sp, 0x1C8
	str r0, [sp, 0x4]
	add r0, sp, 0x1D4
	str r0, [sp, 0x8]
	ldr r2, [sp, 0x1E8]
	str r2, [sp, 0xC]
	add r0, sp, 0x1D8
	str r0, [sp, 0x10]
	ldr r0, [sp, 0x1DC]
	ldr r1, [sp, 0x1FC]
	ldr r2, [sp, 0x200]
	adds r3, r6, 0
	bl sub_80B399C
	mov r8, r0
	ldr r4, [sp, 0x1E8]
	cmp r4, 0x67
	beq _080B2F38
	cmp r4, 0x47
	bne _080B2F5A
_080B2F38:
	add r0, sp, 0x1D4
	ldr r1, [r0]
	movs r0, 0x4
	negs r0, r0
	cmp r1, r0
	ble _080B2F48
	cmp r1, r6
	ble _080B2F56
_080B2F48:
	movs r0, 0x45
	ldr r1, [sp, 0x1E8]
	cmp r1, 0x67
	bne _080B2F52
	movs r0, 0x65
_080B2F52:
	str r0, [sp, 0x1E8]
	b _080B2F5A
_080B2F56:
	movs r2, 0x67
	str r2, [sp, 0x1E8]
_080B2F5A:
	ldr r4, [sp, 0x1E8]
	cmp r4, 0x65
	bgt _080B2F80
	add r0, sp, 0x1D4
	ldr r1, [r0]
	subs r1, 0x1
	str r1, [r0]
	add r0, sp, 0x14
	ldr r2, [sp, 0x1E8]
	bl sub_80B3A90
	str r0, [sp, 0x204]
	add r0, sp, 0x1D8
	ldr r0, [r0]
	ldr r1, [sp, 0x204]
	adds r3, r1, r0
	cmp r0, 0x1
	bgt _080B2FC0
	b _080B2FB6
_080B2F80:
	ldr r4, [sp, 0x1E8]
	cmp r4, 0x66
	bne _080B2FA8
	add r0, sp, 0x1D4
	ldr r0, [r0]
	cmp r0, 0
	ble _080B2FA4
	adds r3, r0, 0
	cmp r6, 0
	bne _080B2F9E
	movs r0, 0x1
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B2FD0
_080B2F9E:
	adds r0, r3, 0x1
	adds r3, r0, r6
	b _080B2FD0
_080B2FA4:
	adds r3, r6, 0x2
	b _080B2FD0
_080B2FA8:
	add r0, sp, 0x1D4
	ldr r1, [r0]
	add r0, sp, 0x1D8
	ldr r0, [r0]
	cmp r1, r0
	blt _080B2FC4
	adds r3, r1, 0
_080B2FB6:
	movs r0, 0x1
	ldr r2, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0
	beq _080B2FD0
_080B2FC0:
	adds r3, 0x1
	b _080B2FD0
_080B2FC4:
	cmp r1, 0
	bgt _080B2FCE
	adds r0, 0x2
	subs r3, r0, r1
	b _080B2FD0
_080B2FCE:
	adds r3, r0, 0x1
_080B2FD0:
	add r0, sp, 0x1C8
	ldrb r0, [r0]
	adds r7, r5, 0
	adds r7, 0x8
	cmp r0, 0
	bne _080B2FDE
	b _080B3266
_080B2FDE:
	ldr r1, _080B2FE8
	add r1, sp
	movs r0, 0x2D
	strb r0, [r1]
	b _080B3266
	.align 2, 0
_080B2FE8: .4byte 0x000001c9
_080B2FEC:
	movs r0, 0x10
	ldr r4, [sp, 0x1EC]
	ands r0, r4
	cmp r0, 0
	beq _080B3006
	movs r0, 0x4
	add r10, r0
	mov r0, r10
	subs r0, 0x4
	ldr r0, [r0]
	ldr r1, [sp, 0x1F0]
	str r1, [r0]
	b _080B2AF4
_080B3006:
	movs r0, 0x40
	ldr r2, [sp, 0x1EC]
	ands r2, r0
	cmp r2, 0
	beq _080B3022
	movs r4, 0x4
	add r10, r4
	mov r0, r10
	subs r0, 0x4
	ldr r0, [r0]
	add r1, sp, 0x1F0
	ldrh r1, [r1]
	strh r1, [r0]
	b _080B2AF4
_080B3022:
	movs r2, 0x4
	add r10, r2
	mov r0, r10
	subs r0, 0x4
	ldr r0, [r0]
	ldr r4, [sp, 0x1F0]
	str r4, [r0]
	b _080B2AF4
_080B3032:
	movs r0, 0x10
	ldr r1, [sp, 0x1EC]
	orrs r1, r0
	str r1, [sp, 0x1EC]
_080B303A:
	movs r0, 0x10
	ldr r2, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0
	bne _080B305A
	movs r0, 0x40
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B305A
	movs r2, 0x4
	add r10, r2
	mov r0, r10
	subs r0, 0x4
	ldrh r4, [r0]
	b _080B3064
_080B305A:
	movs r4, 0x4
	add r10, r4
	mov r0, r10
	subs r0, 0x4
	ldr r4, [r0]
_080B3064:
	movs r2, 0
	b _080B3156
_080B3068:
	movs r0, 0x4
	add r10, r0
	mov r0, r10
	subs r0, 0x4
	ldr r4, [r0]
	movs r2, 0x2
	ldr r1, _080B3084
	str r1, [sp, 0x210]
	ldr r0, [sp, 0x1EC]
	orrs r0, r2
	str r0, [sp, 0x1EC]
	movs r1, 0x78
	str r1, [sp, 0x1E8]
	b _080B3156
	.align 2, 0
_080B3084: .4byte gUnknown_826FE0C
_080B3088:
	movs r2, 0x4
	add r10, r2
	mov r0, r10
	subs r0, 0x4
	ldr r0, [r0]
	mov r8, r0
	cmp r0, 0
	bne _080B309C
	ldr r4, _080B30BC
	mov r8, r4
_080B309C:
	cmp r6, 0
	blt _080B30C0
	mov r0, r8
	movs r1, 0
	adds r2, r6, 0
	bl sub_80B57A0
	cmp r0, 0
	beq _080B30B8
	mov r1, r8
	subs r3, r0, r1
	cmp r3, r6
	bgt _080B30B8
	b _080B325A
_080B30B8:
	adds r3, r6, 0
	b _080B325A
	.align 2, 0
_080B30BC: .4byte gUnknown_826FE20
_080B30C0:
	mov r0, r8
	bl strlen
	adds r3, r0, 0
	b _080B325A
_080B30CA:
	movs r0, 0x10
	ldr r2, [sp, 0x1EC]
	orrs r2, r0
	str r2, [sp, 0x1EC]
_080B30D2:
	movs r0, 0x10
	ldr r4, [sp, 0x1EC]
	ands r0, r4
	cmp r0, 0
	beq _080B30E2
	movs r0, 0x4
	add r10, r0
	b _080B30FC
_080B30E2:
	movs r0, 0x40
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B30F8
	movs r2, 0x4
	add r10, r2
	mov r0, r10
	subs r0, 0x4
	ldrh r4, [r0]
	b _080B3102
_080B30F8:
	movs r4, 0x4
	add r10, r4
_080B30FC:
	mov r0, r10
	subs r0, 0x4
	ldr r4, [r0]
_080B3102:
	movs r2, 0x1
	b _080B3156
_080B3106:
	ldr r0, _080B310C
	str r0, [sp, 0x210]
	b _080B3114
	.align 2, 0
_080B310C: .4byte gUnknown_826FE28
_080B3110:
	ldr r1, _080B3134
	str r1, [sp, 0x210]
_080B3114:
	movs r0, 0x10
	ldr r2, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0
	bne _080B3138
	movs r0, 0x40
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B3138
	movs r2, 0x4
	add r10, r2
	mov r0, r10
	subs r0, 0x4
	ldrh r4, [r0]
	b _080B3142
	.align 2, 0
_080B3134: .4byte gUnknown_826FE0C
_080B3138:
	movs r4, 0x4
	add r10, r4
	mov r0, r10
	subs r0, 0x4
	ldr r4, [r0]
_080B3142:
	movs r2, 0x2
	movs r0, 0x1
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B3156
	cmp r4, 0
	beq _080B3156
	orrs r1, r2
	str r1, [sp, 0x1EC]
_080B3156:
	ldr r1, _080B31A0
	add r1, sp
	movs r0, 0
	strb r0, [r1]
_080B315E:
	str r6, [sp, 0x208]
	cmp r6, 0
	blt _080B316E
	movs r0, 0x81
	negs r0, r0
	ldr r1, [sp, 0x1EC]
	ands r1, r0
	str r1, [sp, 0x1EC]
_080B316E:
	movs r0, 0xE2
	lsls r0, 1
	add r0, sp
	mov r8, r0
	cmp r4, 0
	bne _080B3184
	adds r7, r5, 0
	adds r7, 0x8
	ldr r1, [sp, 0x208]
	cmp r1, 0
	beq _080B323C
_080B3184:
	cmp r2, 0x1
	beq _080B31E2
	cmp r2, 0x1
	bcc _080B31A8
	cmp r2, 0x2
	beq _080B321C
	ldr r2, _080B31A4
	mov r8, r2
	mov r0, r8
	bl strlen
	adds r3, r0, 0
	b _080B3262
	.align 2, 0
_080B31A0: .4byte 0x000001c9
_080B31A4: .4byte gUnknown_826FE3C
_080B31A8:
	adds r7, r5, 0
	adds r7, 0x8
	movs r2, 0x7
_080B31AE:
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	adds r0, r4, 0
	ands r0, r2
	adds r1, r0, 0
	adds r1, 0x30
	mov r0, r8
	strb r1, [r0]
	lsrs r4, 3
	cmp r4, 0
	bne _080B31AE
	movs r0, 0x1
	ldr r2, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0
	beq _080B323C
	cmp r1, 0x30
	beq _080B323C
	movs r4, 0x1
	negs r4, r4
	add r8, r4
	movs r0, 0x30
	mov r1, r8
	strb r0, [r1]
	b _080B323C
_080B31E2:
	adds r7, r5, 0
	adds r7, 0x8
	cmp r4, 0x9
	bls _080B320C
_080B31EA:
	movs r2, 0x1
	negs r2, r2
	add r8, r2
	adds r0, r4, 0
	movs r1, 0xA
	bl __umodsi3
	adds r0, 0x30
	mov r1, r8
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_80B688C
	adds r4, r0, 0
	cmp r4, 0x9
	bhi _080B31EA
_080B320C:
	movs r2, 0x1
	negs r2, r2
	add r8, r2
	adds r0, r4, 0
	adds r0, 0x30
	mov r4, r8
	strb r0, [r4]
	b _080B323C
_080B321C:
	adds r7, r5, 0
	adds r7, 0x8
	movs r1, 0xF
_080B3222:
	movs r0, 0x1
	negs r0, r0
	add r8, r0
	adds r0, r4, 0
	ands r0, r1
	ldr r2, [sp, 0x210]
	adds r0, r2, r0
	ldrb r0, [r0]
	mov r2, r8
	strb r0, [r2]
	lsrs r4, 4
	cmp r4, 0
	bne _080B3222
_080B323C:
	add r4, sp, 0x14
	mov r1, r8
	subs r0, r4, r1
	movs r2, 0xD8
	lsls r2, 1
	adds r3, r0, r2
	b _080B3266
_080B324A:
	ldr r4, [sp, 0x1E8]
	cmp r4, 0
	bne _080B3252
	b _080B3960
_080B3252:
	add r0, sp, 0x68
	mov r8, r0
	strb r4, [r0]
_080B3258:
	movs r3, 0x1
_080B325A:
	ldr r1, _080B3284
	add r1, sp
	movs r0, 0
	strb r0, [r1]
_080B3262:
	adds r7, r5, 0
	adds r7, 0x8
_080B3266:
	str r3, [sp, 0x20C]
	ldr r2, [sp, 0x208]
	cmp r3, r2
	bge _080B3270
	str r2, [sp, 0x20C]
_080B3270:
	ldr r0, _080B3284
	add r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _080B3288
	ldr r4, [sp, 0x20C]
	adds r4, 0x1
	str r4, [sp, 0x20C]
	b _080B3298
	.align 2, 0
_080B3284: .4byte 0x000001c9
_080B3288:
	movs r0, 0x2
	ldr r1, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B3298
	ldr r2, [sp, 0x20C]
	adds r2, 0x2
	str r2, [sp, 0x20C]
_080B3298:
	movs r0, 0x84
	ldr r4, [sp, 0x1EC]
	ands r0, r4
	cmp r0, 0
	bne _080B3318
	ldr r0, [sp, 0x1F4]
	ldr r1, [sp, 0x20C]
	subs r4, r0, r1
	cmp r4, 0
	ble _080B3318
	ldr r1, _080B3344
	cmp r4, 0x10
	ble _080B32EC
	mov r6, r9
_080B32B4:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, r7, 0
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B32E2
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	str r3, [sp, 0x21C]
	bl __sprint
	ldr r3, [sp, 0x21C]
	cmp r0, 0
	beq _080B32DE
	b _080B3978
_080B32DE:
	add r5, sp, 0x28
	ldr r1, _080B3344
_080B32E2:
	subs r4, 0x10
	adds r7, r5, 0
	adds r7, 0x8
	cmp r4, 0x10
	bgt _080B32B4
_080B32EC:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, r4
	str r0, [r2, 0x8]
	adds r5, r7, 0
	ldr r0, [r2, 0x4]
	adds r0, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0x7
	ble _080B3318
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	str r3, [sp, 0x21C]
	bl __sprint
	ldr r3, [sp, 0x21C]
	cmp r0, 0
	beq _080B3316
	b _080B3978
_080B3316:
	add r5, sp, 0x28
_080B3318:
	ldr r1, _080B3348
	add r1, sp
	ldrb r0, [r1]
	cmp r0, 0
	beq _080B334C
	str r1, [r5]
	movs r0, 0x1
	str r0, [r5, 0x4]
	mov r4, r9
	ldr r0, [r4, 0x8]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r5, 0x8
	ldr r0, [r4, 0x4]
	adds r0, 0x1
	str r0, [r4, 0x4]
	cmp r0, 0x7
	ble _080B338C
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	b _080B337C
	.align 2, 0
_080B3344: .4byte gUnknown_826FDE4
_080B3348: .4byte 0x000001c9
_080B334C:
	movs r2, 0x2
	ldr r0, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0
	beq _080B338C
	add r1, sp, 0x1C4
	movs r0, 0x30
	strb r0, [r1]
	add r0, sp, 0x1E8
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
	str r1, [r5]
	str r2, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, 0x2
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B338C
	ldr r0, [sp, 0x1E0]
_080B337C:
	str r3, [sp, 0x21C]
	bl __sprint
	ldr r3, [sp, 0x21C]
	cmp r0, 0
	beq _080B338A
	b _080B3978
_080B338A:
	add r5, sp, 0x28
_080B338C:
	movs r0, 0x84
	ldr r2, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0x80
	bne _080B3408
	ldr r0, [sp, 0x1F4]
	ldr r1, [sp, 0x20C]
	subs r4, r0, r1
	cmp r4, 0
	ble _080B3408
	ldr r1, _080B34A4
	cmp r4, 0x10
	ble _080B33DC
	mov r6, r9
_080B33A8:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, 0x8
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B33D6
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	str r3, [sp, 0x21C]
	bl __sprint
	ldr r3, [sp, 0x21C]
	cmp r0, 0
	beq _080B33D2
	b _080B3978
_080B33D2:
	add r5, sp, 0x28
	ldr r1, _080B34A4
_080B33D6:
	subs r4, 0x10
	cmp r4, 0x10
	bgt _080B33A8
_080B33DC:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, r4
	str r0, [r2, 0x8]
	adds r5, 0x8
	ldr r0, [r2, 0x4]
	adds r0, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0x7
	ble _080B3408
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	str r3, [sp, 0x21C]
	bl __sprint
	ldr r3, [sp, 0x21C]
	cmp r0, 0
	beq _080B3406
	b _080B3978
_080B3406:
	add r5, sp, 0x28
_080B3408:
	ldr r0, [sp, 0x208]
	subs r4, r0, r3
	cmp r4, 0
	ble _080B3476
	ldr r1, _080B34A4
	cmp r4, 0x10
	ble _080B344C
	mov r6, r9
_080B3418:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, 0x8
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B3446
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	str r3, [sp, 0x21C]
	bl __sprint
	ldr r3, [sp, 0x21C]
	cmp r0, 0
	beq _080B3442
	b _080B3978
_080B3442:
	add r5, sp, 0x28
	ldr r1, _080B34A4
_080B3446:
	subs r4, 0x10
	cmp r4, 0x10
	bgt _080B3418
_080B344C:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, r4
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B3476
	ldr r0, [sp, 0x1E0]
	str r3, [sp, 0x21C]
	bl __sprint
	ldr r3, [sp, 0x21C]
	cmp r0, 0
	beq _080B3474
	b _080B3978
_080B3474:
	add r5, sp, 0x28
_080B3476:
	movs r0, 0x80
	lsls r0, 1
	ldr r2, [sp, 0x1EC]
	ands r0, r2
	cmp r0, 0
	bne _080B34A8
	mov r4, r8
	str r4, [r5]
	str r3, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, r3
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	bgt _080B349E
	b _080B38BE
_080B349E:
	ldr r0, [sp, 0x1E0]
	b _080B38B4
	.align 2, 0
_080B34A4: .4byte gUnknown_826FDF4
_080B34A8:
	ldr r2, [sp, 0x1E8]
	cmp r2, 0x65
	bgt _080B34B0
	b _080B3794
_080B34B0:
	ldr r3, _080B357C
	ldr r2, _080B3578
	ldr r0, [sp, 0x1FC]
	ldr r1, [sp, 0x200]
	bl __eqdf2
	cmp r0, 0
	bne _080B3588
	ldr r0, _080B3580
	str r0, [r5]
	movs r6, 0x1
	str r6, [r5, 0x4]
	mov r4, r9
	ldr r0, [r4, 0x8]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r5, 0x8
	ldr r0, [r4, 0x4]
	adds r0, 0x1
	str r0, [r4, 0x4]
	cmp r0, 0x7
	ble _080B34EC
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B34EA
	b _080B3978
_080B34EA:
	add r5, sp, 0x28
_080B34EC:
	add r0, sp, 0x1D4
	ldr r1, [r0]
	add r4, sp, 0x1D8
	ldr r0, [r4]
	cmp r1, r0
	blt _080B3502
	ldr r0, [sp, 0x1EC]
	ands r0, r6
	cmp r0, 0
	bne _080B3502
	b _080B38BE
_080B3502:
	ldr r0, [sp, 0x1F8]
	str r0, [r5]
	str r6, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, 0x1
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B352A
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	beq _080B3528
	b _080B3978
_080B3528:
	add r5, sp, 0x28
_080B352A:
	ldr r0, [r4]
	subs r4, r0, 0x1
	cmp r4, 0
	bgt _080B3534
	b _080B38BE
_080B3534:
	ldr r1, _080B3584
	cmp r4, 0x10
	ble _080B356C
	mov r6, r9
_080B353C:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, 0x8
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B3566
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B3562
	b _080B3978
_080B3562:
	add r5, sp, 0x28
	ldr r1, _080B3584
_080B3566:
	subs r4, 0x10
	cmp r4, 0x10
	bgt _080B353C
_080B356C:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, r4
	b _080B38A2
	.align 2, 0
_080B3578: .4byte 0x00000000
_080B357C: .4byte 0x00000000
_080B3580: .4byte gUnknown_826FE58
_080B3584: .4byte gUnknown_826FDF4
_080B3588:
	add r6, sp, 0x1D4
	ldr r2, [r6]
	cmp r2, 0
	bgt _080B3670
	ldr r0, _080B3668
	str r0, [r5]
	movs r4, 0x1
	str r4, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, 0x1
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B35BA
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	beq _080B35B8
	b _080B3978
_080B35B8:
	add r5, sp, 0x28
_080B35BA:
	ldr r2, [sp, 0x1F8]
	str r2, [r5]
	str r4, [r5, 0x4]
	mov r4, r9
	ldr r0, [r4, 0x8]
	adds r0, 0x1
	str r0, [r4, 0x8]
	adds r5, 0x8
	ldr r0, [r4, 0x4]
	adds r0, 0x1
	str r0, [r4, 0x4]
	cmp r0, 0x7
	ble _080B35E4
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B35E2
	b _080B3978
_080B35E2:
	add r5, sp, 0x28
_080B35E4:
	ldr r0, [r6]
	negs r4, r0
	cmp r4, 0
	ble _080B364A
	ldr r1, _080B366C
	cmp r4, 0x10
	ble _080B3624
	mov r6, r9
_080B35F4:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, 0x8
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B361E
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B361A
	b _080B3978
_080B361A:
	add r5, sp, 0x28
	ldr r1, _080B366C
_080B361E:
	subs r4, 0x10
	cmp r4, 0x10
	bgt _080B35F4
_080B3624:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, r4
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B364A
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	beq _080B3648
	b _080B3978
_080B3648:
	add r5, sp, 0x28
_080B364A:
	mov r2, r8
	str r2, [r5]
	add r0, sp, 0x1D8
	ldr r1, [r0]
	str r1, [r5, 0x4]
	mov r4, r9
	ldr r0, [r4, 0x8]
	adds r0, r1
	str r0, [r4, 0x8]
	adds r5, 0x8
	ldr r0, [r4, 0x4]
	adds r0, 0x1
	str r0, [r4, 0x4]
	b _080B38AC
	.align 2, 0
_080B3668: .4byte gUnknown_826FE58
_080B366C: .4byte gUnknown_826FDF4
_080B3670:
	add r4, sp, 0x1D8
	ldr r1, [r4]
	cmp r2, r1
	blt _080B372C
	mov r0, r8
	str r0, [r5]
	str r1, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, r1
	str r0, [r2, 0x8]
	adds r5, 0x8
	ldr r0, [r2, 0x4]
	adds r0, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0x7
	ble _080B36A2
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B36A0
	b _080B3978
_080B36A0:
	add r5, sp, 0x28
_080B36A2:
	ldr r1, [r6]
	ldr r0, [r4]
	subs r4, r1, r0
	cmp r4, 0
	ble _080B370A
	ldr r1, _080B3724
	cmp r4, 0x10
	ble _080B36E4
	mov r6, r9
_080B36B4:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, 0x8
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B36DE
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B36DA
	b _080B3978
_080B36DA:
	add r5, sp, 0x28
	ldr r1, _080B3724
_080B36DE:
	subs r4, 0x10
	cmp r4, 0x10
	bgt _080B36B4
_080B36E4:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, r4
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B370A
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	beq _080B3708
	b _080B3978
_080B3708:
	add r5, sp, 0x28
_080B370A:
	movs r1, 0x1
	ldr r0, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	bne _080B3716
	b _080B38BE
_080B3716:
	ldr r0, _080B3728
	str r0, [r5]
	str r1, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, 0x1
	b _080B38A2
	.align 2, 0
_080B3724: .4byte gUnknown_826FDF4
_080B3728: .4byte gUnknown_826FE5C
_080B372C:
	mov r0, r8
	str r0, [r5]
	str r2, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, r2
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B3754
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	beq _080B3752
	b _080B3978
_080B3752:
	add r5, sp, 0x28
_080B3754:
	ldr r0, [r6]
	add r8, r0
	ldr r0, _080B3790
	str r0, [r5]
	movs r0, 0x1
	str r0, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, 0x1
	str r0, [r2, 0x8]
	adds r5, 0x8
	ldr r0, [r2, 0x4]
	adds r0, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0x7
	ble _080B3784
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B3782
	b _080B3978
_080B3782:
	add r5, sp, 0x28
_080B3784:
	mov r0, r8
	str r0, [r5]
	ldr r1, [r4]
	ldr r0, [r6]
	subs r1, r0
	b _080B389A
	.align 2, 0
_080B3790: .4byte gUnknown_826FE5C
_080B3794:
	add r4, sp, 0x1D8
	ldr r0, [r4]
	cmp r0, 0x1
	bgt _080B37A6
	movs r1, 0x1
	ldr r0, [sp, 0x1EC]
	ands r0, r1
	cmp r0, 0
	beq _080B386C
_080B37A6:
	add r1, sp, 0x1C4
	mov r2, r8
	ldrb r0, [r2]
	strb r0, [r1]
	movs r0, 0x1
	add r8, r0
	movs r0, 0x2E
	strb r0, [r1, 0x1]
	str r1, [r5]
	movs r0, 0x2
	str r0, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, 0x2
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B37DE
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	beq _080B37DC
	b _080B3978
_080B37DC:
	add r5, sp, 0x28
_080B37DE:
	ldr r3, _080B3808
	ldr r2, _080B3804
	ldr r0, [sp, 0x1FC]
	ldr r1, [sp, 0x200]
	bl __nedf2
	cmp r0, 0
	beq _080B380C
	mov r2, r8
	str r2, [r5]
	ldr r1, [r4]
	subs r0, r1, 0x1
	str r0, [r5, 0x4]
	mov r4, r9
	ldr r0, [r4, 0x8]
	subs r0, 0x1
	adds r0, r1
	b _080B3878
	.align 2, 0
_080B3804: .4byte 0x00000000
_080B3808: .4byte 0x00000000
_080B380C:
	ldr r0, [r4]
	subs r4, r0, 0x1
	cmp r4, 0
	ble _080B3894
	ldr r1, _080B3868
	cmp r4, 0x10
	ble _080B384C
	mov r6, r9
_080B381C:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, 0x8
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B3846
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	beq _080B3842
	b _080B3978
_080B3842:
	add r5, sp, 0x28
	ldr r1, _080B3868
_080B3846:
	subs r4, 0x10
	cmp r4, 0x10
	bgt _080B381C
_080B384C:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r1, r9
	ldr r0, [r1, 0x8]
	adds r0, r4
	str r0, [r1, 0x8]
	adds r5, 0x8
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x7
	ble _080B3894
	ldr r0, [sp, 0x1E0]
	b _080B388A
	.align 2, 0
_080B3868: .4byte gUnknown_826FDF4
_080B386C:
	mov r2, r8
	str r2, [r5]
	str r1, [r5, 0x4]
	mov r4, r9
	ldr r0, [r4, 0x8]
	adds r0, 0x1
_080B3878:
	str r0, [r4, 0x8]
	adds r5, 0x8
	ldr r0, [r4, 0x4]
	adds r0, 0x1
	str r0, [r4, 0x4]
	cmp r0, 0x7
	ble _080B3894
	ldr r0, [sp, 0x1E0]
	mov r1, r9
_080B388A:
	bl __sprint
	cmp r0, 0
	bne _080B3978
	add r5, sp, 0x28
_080B3894:
	add r0, sp, 0x14
	str r0, [r5]
	ldr r1, [sp, 0x204]
_080B389A:
	str r1, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, r1
_080B38A2:
	str r0, [r2, 0x8]
	adds r5, 0x8
	ldr r0, [r2, 0x4]
	adds r0, 0x1
	str r0, [r2, 0x4]
_080B38AC:
	cmp r0, 0x7
	ble _080B38BE
	ldr r0, [sp, 0x1E0]
	mov r1, r9
_080B38B4:
	bl __sprint
	cmp r0, 0
	bne _080B3978
	add r5, sp, 0x28
_080B38BE:
	movs r0, 0x4
	ldr r4, [sp, 0x1EC]
	ands r4, r0
	cmp r4, 0
	beq _080B392A
	ldr r0, [sp, 0x1F4]
	ldr r1, [sp, 0x20C]
	subs r4, r0, r1
	cmp r4, 0
	ble _080B392A
	ldr r1, _080B395C
	cmp r4, 0x10
	ble _080B3908
	mov r6, r9
_080B38DA:
	str r1, [r5]
	movs r0, 0x10
	str r0, [r5, 0x4]
	ldr r0, [r6, 0x8]
	adds r0, 0x10
	str r0, [r6, 0x8]
	adds r5, 0x8
	ldr r0, [r6, 0x4]
	adds r0, 0x1
	str r0, [r6, 0x4]
	cmp r0, 0x7
	ble _080B3902
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	bne _080B3978
	add r5, sp, 0x28
	ldr r1, _080B395C
_080B3902:
	subs r4, 0x10
	cmp r4, 0x10
	bgt _080B38DA
_080B3908:
	str r1, [r5]
	str r4, [r5, 0x4]
	mov r2, r9
	ldr r0, [r2, 0x8]
	adds r0, r4
	str r0, [r2, 0x8]
	ldr r0, [r2, 0x4]
	adds r0, 0x1
	str r0, [r2, 0x4]
	cmp r0, 0x7
	ble _080B392A
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	bne _080B3978
_080B392A:
	ldr r0, [sp, 0x20C]
	ldr r4, [sp, 0x1F4]
	cmp r0, r4
	bge _080B3934
	adds r0, r4, 0
_080B3934:
	ldr r1, [sp, 0x1F0]
	adds r1, r0
	str r1, [sp, 0x1F0]
	mov r2, r9
	ldr r0, [r2, 0x8]
	cmp r0, 0
	beq _080B394E
	ldr r0, [sp, 0x1E0]
	mov r1, r9
	bl __sprint
	cmp r0, 0
	bne _080B3978
_080B394E:
	movs r0, 0
	mov r4, r9
	str r0, [r4, 0x4]
	add r5, sp, 0x28
	bl _080B2AF4
	.align 2, 0
_080B395C: .4byte gUnknown_826FDE4
_080B3960:
	mov r1, r9
	ldr r0, [r1, 0x8]
	cmp r0, 0
	beq _080B3972
	ldr r0, [sp, 0x1E0]
	bl __sprint
	cmp r0, 0
	bne _080B3978
_080B3972:
	movs r0, 0
	mov r1, r9
	str r0, [r1, 0x4]
_080B3978:
	movs r0, 0x40
	ldr r2, [sp, 0x1E0]
	ldrh r2, [r2, 0xC]
	ands r0, r2
	movs r1, 0x1
	negs r1, r1
	cmp r0, 0
	bne _080B398A
	ldr r1, [sp, 0x1F0]
_080B398A:
	adds r0, r1, 0
_080B398C:
	movs r3, 0x88
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	thumb_func_end _vfprintf_r

	thumb_func_start sub_80B399C
sub_80B399C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	str r0, [sp, 0x18]
	adds r5, r2, 0
	adds r4, r1, 0
	mov r8, r3
	ldr r6, [sp, 0x3C]
	ldr r0, [sp, 0x44]
	mov r10, r0
	ldr r1, [sp, 0x48]
	mov r9, r1
	cmp r1, 0x66
	bne _080B39C2
	movs r7, 0x3
	b _080B39D2
_080B39C2:
	mov r0, r9
	cmp r0, 0x65
	beq _080B39CC
	cmp r0, 0x45
	bne _080B39D0
_080B39CC:
	movs r1, 0x1
	add r8, r1
_080B39D0:
	movs r7, 0x2
_080B39D2:
	lsls r0, r4, 31
	lsrs r0, 31
	cmp r0, 0
	beq _080B39E8
	adds r1, r5, 0
	adds r0, r4, 0
	bl __negdf2
	adds r5, r1, 0
	adds r4, r0, 0
	movs r0, 0x2D
_080B39E8:
	ldr r1, [sp, 0x40]
	strb r0, [r1]
	mov r0, r8
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	add r0, sp, 0x10
	str r0, [sp, 0x8]
	add r0, sp, 0x14
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x18]
	adds r2, r5, 0
	adds r1, r4, 0
	adds r3, r7, 0
	bl _dtoa_r
	adds r7, r0, 0
	mov r1, r9
	cmp r1, 0x67
	beq _080B3A14
	cmp r1, 0x47
	bne _080B3A1C
_080B3A14:
	movs r0, 0x1
	ands r6, r0
	cmp r6, 0
	beq _080B3A70
_080B3A1C:
	mov r0, r8
	adds r6, r7, r0
	mov r1, r9
	cmp r1, 0x66
	bne _080B3A4C
	ldrb r0, [r7]
	cmp r0, 0x30
	bne _080B3A46
	ldr r3, _080B3A8C
	ldr r2, _080B3A88
	adds r1, r5, 0
	adds r0, r4, 0
	bl __nedf2
	cmp r0, 0
	beq _080B3A46
	mov r1, r8
	negs r0, r1
	adds r0, 0x1
	mov r1, r10
	str r0, [r1]
_080B3A46:
	mov r1, r10
	ldr r0, [r1]
	adds r6, r0
_080B3A4C:
	ldr r3, _080B3A8C
	ldr r2, _080B3A88
	adds r1, r5, 0
	adds r0, r4, 0
	bl __eqdf2
	cmp r0, 0
	bne _080B3A5E
	str r6, [sp, 0x14]
_080B3A5E:
	ldr r0, [sp, 0x14]
	cmp r0, r6
	bcs _080B3A70
	movs r1, 0x30
_080B3A66:
	strb r1, [r0]
	adds r0, 0x1
	str r0, [sp, 0x14]
	cmp r0, r6
	bcc _080B3A66
_080B3A70:
	ldr r0, [sp, 0x14]
	subs r0, r7
	ldr r1, [sp, 0x4C]
	str r0, [r1]
	adds r0, r7, 0
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_080B3A88: .4byte 0x00000000
_080B3A8C: .4byte 0x00000000
	thumb_func_end sub_80B399C

	thumb_func_start sub_80B3A90
sub_80B3A90:
	push {r4-r7,lr}
	sub sp, 0x134
	adds r7, r0, 0
	adds r6, r1, 0
	strb r2, [r7]
	adds r5, r7, 0x1
	cmp r6, 0
	bge _080B3AA6
	negs r6, r6
	movs r0, 0x2D
	b _080B3AA8
_080B3AA6:
	movs r0, 0x2B
_080B3AA8:
	strb r0, [r7, 0x1]
	adds r5, 0x1
	add r4, sp, 0x134
	cmp r6, 0x9
	ble _080B3AEA
_080B3AB2:
	subs r4, 0x1
	adds r0, r6, 0
	movs r1, 0xA
	bl __modsi3
	adds r0, 0x30
	strb r0, [r4]
	adds r0, r6, 0
	movs r1, 0xA
	bl __divsi3
	adds r6, r0, 0
	cmp r6, 0x9
	bgt _080B3AB2
	subs r4, 0x1
	adds r0, 0x30
	strb r0, [r4]
	add r0, sp, 0x134
	cmp r4, r0
	bcs _080B3AF8
	adds r1, r0, 0
_080B3ADC:
	ldrb r0, [r4]
	strb r0, [r5]
	adds r4, 0x1
	adds r5, 0x1
	cmp r4, r1
	bcc _080B3ADC
	b _080B3AF8
_080B3AEA:
	movs r0, 0x30
	strb r0, [r5]
	adds r5, 0x1
	adds r0, r6, 0
	adds r0, 0x30
	strb r0, [r5]
	adds r5, 0x1
_080B3AF8:
	subs r0, r5, r7
	add sp, 0x134
	pop {r4-r7,pc}
	thumb_func_end sub_80B3A90

	thumb_func_start vsprintf
vsprintf:
	push {r4,r5,lr}
	sub sp, 0x58
	mov r4, sp
	movs r5, 0
	movs r3, 0x82
	lsls r3, 2
	strh r3, [r4, 0xC]
	str r0, [sp]
	str r0, [sp, 0x10]
	ldr r0, _080B3B2C
	str r0, [sp, 0x8]
	str r0, [sp, 0x14]
	ldr r0, _080B3B30
	ldr r0, [r0]
	str r0, [sp, 0x54]
	mov r0, sp
	bl vfprintf
	ldr r1, [sp]
	strb r5, [r1]
	add sp, 0x58
	pop {r4,r5,pc}
	.align 2, 0
_080B3B2C: .4byte 0x7fffffff
_080B3B30: .4byte gUnknown_203B7A8
	thumb_func_end vsprintf

	thumb_func_start sub_80B3B34
sub_80B3B34:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x54]
	cmp r0, 0
	bne _080B3B44
	ldr r0, _080B3B70
	ldr r0, [r0]
	str r0, [r4, 0x54]
_080B3B44:
	ldr r1, [r4, 0x54]
	ldr r0, [r1, 0x38]
	cmp r0, 0
	bne _080B3B52
	adds r0, r1, 0
	bl sub_80B4BC4
_080B3B52:
	ldrh r1, [r4, 0xC]
	movs r0, 0x8
	ands r0, r1
	lsls r0, 16
	asrs r5, r0, 16
	cmp r5, 0
	bne _080B3BAC
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080B3B74
	movs r0, 0x1
	negs r0, r0
	b _080B3BDE
	.align 2, 0
_080B3B70: .4byte gUnknown_203B7A8
_080B3B74:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080B3BA4
	ldr r1, [r4, 0x30]
	cmp r1, 0
	beq _080B3B92
	adds r0, r4, 0
	adds r0, 0x40
	cmp r1, r0
	beq _080B3B90
	ldr r0, [r4, 0x54]
	bl _free_r
_080B3B90:
	str r5, [r4, 0x30]
_080B3B92:
	movs r0, 0x25
	negs r0, r0
	ldrh r1, [r4, 0xC]
	ands r0, r1
	movs r1, 0
	strh r0, [r4, 0xC]
	str r1, [r4, 0x4]
	ldr r0, [r4, 0x10]
	str r0, [r4]
_080B3BA4:
	movs r0, 0x8
	ldrh r1, [r4, 0xC]
	orrs r0, r1
	strh r0, [r4, 0xC]
_080B3BAC:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	bne _080B3BB8
	adds r0, r4, 0
	bl sub_80B517C
_080B3BB8:
	ldrh r1, [r4, 0xC]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B3BCE
	movs r0, 0
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x14]
	negs r0, r0
	str r0, [r4, 0x18]
	b _080B3BDC
_080B3BCE:
	movs r0, 0x2
	ands r0, r1
	movs r1, 0
	cmp r0, 0
	bne _080B3BDA
	ldr r1, [r4, 0x14]
_080B3BDA:
	str r1, [r4, 0x8]
_080B3BDC:
	movs r0, 0
_080B3BDE:
	pop {r4,r5,pc}
	thumb_func_end sub_80B3B34

	thumb_func_start sub_80B3BE0
sub_80B3BE0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r7, [r1, 0x10]
	ldr r0, [r0, 0x10]
	cmp r0, r7
	bge _080B3BFC
	movs r0, 0
	b _080B3D30
_080B3BFC:
	ldr r0, [sp, 0x4]
	adds r0, 0x14
	mov r8, r0
	subs r7, 0x1
	lsls r0, r7, 2
	mov r1, r8
	adds r1, r0
	str r1, [sp, 0xC]
	ldr r4, [sp]
	adds r4, 0x14
	adds r5, r4, r0
	ldr r1, [r1]
	adds r1, 0x1
	ldr r2, [r5]
	mov r10, r2
	mov r0, r10
	bl sub_80B688C
	str r0, [sp, 0x8]
	mov r3, r8
	str r3, [sp, 0x14]
	str r4, [sp, 0x10]
	cmp r0, 0
	beq _080B3CA6
	movs r6, 0
	mov r9, r6
	ldr r0, _080B3C90
	mov r12, r0
_080B3C34:
	mov r2, r8
	adds r2, 0x4
	mov r8, r2
	subs r2, 0x4
	ldm r2!, {r1}
	adds r0, r1, 0
	mov r3, r12
	ands r0, r3
	ldr r2, [sp, 0x8]
	muls r0, r2
	mov r3, r9
	adds r2, r0, r3
	lsrs r0, r1, 16
	ldr r3, [sp, 0x8]
	adds r1, r0, 0
	muls r1, r3
	lsrs r0, r2, 16
	adds r3, r1, r0
	lsrs r0, r3, 16
	mov r9, r0
	ldr r0, [r4]
	mov r1, r12
	ands r0, r1
	ands r2, r1
	subs r0, r2
	adds r2, r0, r6
	asrs r6, r2, 16
	ldr r0, [r4]
	lsrs r1, r0, 16
	mov r0, r12
	ands r3, r0
	subs r1, r3
	adds r0, r1, r6
	asrs r6, r0, 16
	strh r0, [r4]
	strh r2, [r4, 0x2]
	adds r4, 0x4
	ldr r1, [sp, 0xC]
	cmp r8, r1
	bls _080B3C34
	mov r2, r10
	cmp r2, 0
	bne _080B3CA6
	ldr r4, [sp, 0x10]
	b _080B3C96
	.align 2, 0
_080B3C90: .4byte 0x0000ffff
_080B3C94:
	subs r7, 0x1
_080B3C96:
	subs r5, 0x4
	cmp r5, r4
	bls _080B3CA2
	ldr r0, [r5]
	cmp r0, 0
	beq _080B3C94
_080B3CA2:
	ldr r3, [sp]
	str r7, [r3, 0x10]
_080B3CA6:
	ldr r0, [sp]
	ldr r1, [sp, 0x4]
	bl sub_80B5DD0
	cmp r0, 0
	blt _080B3D2E
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
	movs r6, 0
	mov r9, r6
	ldr r4, [sp, 0x10]
	ldr r1, [sp, 0x14]
	mov r8, r1
	lsls r2, r7, 2
	mov r10, r2
	ldr r5, _080B3D18
_080B3CC8:
	mov r3, r8
	adds r3, 0x4
	mov r8, r3
	subs r3, 0x4
	ldm r3!, {r1}
	adds r0, r1, 0
	ands r0, r5
	mov r3, r9
	adds r2, r0, r3
	lsrs r1, 16
	lsrs r0, r2, 16
	adds r3, r1, r0
	lsrs r0, r3, 16
	mov r9, r0
	ldr r1, [r4]
	adds r0, r1, 0
	ands r0, r5
	ands r2, r5
	subs r0, r2
	adds r2, r0, r6
	asrs r6, r2, 16
	lsrs r1, 16
	ands r3, r5
	subs r1, r3
	adds r0, r1, r6
	asrs r6, r0, 16
	strh r0, [r4]
	strh r2, [r4, 0x2]
	adds r4, 0x4
	ldr r1, [sp, 0xC]
	cmp r8, r1
	bls _080B3CC8
	ldr r4, [sp, 0x10]
	mov r2, r10
	adds r5, r4, r2
	ldr r0, [r5]
	cmp r0, 0
	bne _080B3D2E
	b _080B3D1E
	.align 2, 0
_080B3D18: .4byte 0x0000ffff
_080B3D1C:
	subs r7, 0x1
_080B3D1E:
	subs r5, 0x4
	cmp r5, r4
	bls _080B3D2A
	ldr r0, [r5]
	cmp r0, 0
	beq _080B3D1C
_080B3D2A:
	ldr r3, [sp]
	str r7, [r3, 0x10]
_080B3D2E:
	ldr r0, [sp, 0x8]
_080B3D30:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	thumb_func_end sub_80B3BE0

	thumb_func_start _dtoa_r
_dtoa_r:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x84
	mov r10, r0
	str r3, [sp, 0xC]
	ldr r4, [sp, 0xAC]
	str r1, [sp, 0x40]
	str r2, [sp, 0x44]
	ldr r2, [r0, 0x40]
	cmp r2, 0
	beq _080B3D74
	ldr r0, [r0, 0x44]
	str r0, [r2, 0x4]
	mov r0, r10
	ldr r1, [r0, 0x44]
	movs r0, 0x1
	lsls r0, r1
	str r0, [r2, 0x8]
	mov r0, r10
	adds r1, r2, 0
	bl sub_80B5908
	movs r0, 0
	mov r1, r10
	str r0, [r1, 0x40]
_080B3D74:
	movs r0, 0x80
	lsls r0, 24
	ldr r1, [sp, 0x40]
	ands r0, r1
	cmp r0, 0
	beq _080B3D90
	movs r0, 0x1
	str r0, [r4]
	ldr r0, _080B3D8C
	ands r1, r0
	str r1, [sp, 0x40]
	b _080B3D92
	.align 2, 0
_080B3D8C: .4byte 0x7fffffff
_080B3D90:
	str r0, [r4]
_080B3D92:
	ldr r1, _080B3DD4
	ldr r2, [sp, 0x40]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	bne _080B3DE8
	ldr r0, _080B3DD8
	ldr r3, [sp, 0xA8]
	str r0, [r3]
	ldr r0, _080B3DDC
	mov r9, r0
	ldr r1, [sp, 0x44]
	cmp r1, 0
	bne _080B3DBA
	ldr r0, _080B3DE0
	ands r2, r0
	cmp r2, 0
	bne _080B3DBA
	ldr r2, _080B3DE4
	mov r9, r2
_080B3DBA:
	ldr r3, [sp, 0xB0]
	cmp r3, 0
	beq _080B3E0C
	mov r1, r9
	ldrb r0, [r1, 0x3]
	adds r1, 0x3
	cmp r0, 0
	beq _080B3DCC
	adds r1, 0x5
_080B3DCC:
	ldr r2, [sp, 0xB0]
	str r1, [r2]
	b _080B3E0C
	.align 2, 0
_080B3DD4: .4byte 0x7ff00000
_080B3DD8: .4byte 0x0000270f
_080B3DDC: .4byte gUnknown_826FE6C
_080B3DE0: .4byte 0x000fffff
_080B3DE4: .4byte gUnknown_826FE60
_080B3DE8:
	ldr r3, _080B3E18
	ldr r2, _080B3E14
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __eqdf2
	cmp r0, 0
	bne _080B3E20
	movs r0, 0x1
	ldr r3, [sp, 0xA8]
	str r0, [r3]
	ldr r0, _080B3E1C
	mov r9, r0
	ldr r1, [sp, 0xB0]
	cmp r1, 0
	beq _080B3E0C
	adds r0, 0x1
	str r0, [r1]
_080B3E0C:
	mov r0, r9
	bl _080B4A26
	.align 2, 0
_080B3E14: .4byte 0x00000000
_080B3E18: .4byte 0x00000000
_080B3E1C: .4byte gUnknown_826FE70
_080B3E20:
	add r0, sp, 0x8
	str r0, [sp]
	mov r0, r10
	ldr r1, [sp, 0x40]
	ldr r2, [sp, 0x44]
	add r3, sp, 0x4
	bl sub_80B6008
	str r0, [sp, 0x5C]
	ldr r2, [sp, 0x40]
	lsls r0, r2, 1
	lsrs r0, 21
	mov r8, r0
	cmp r0, 0
	beq _080B3E70
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	str r0, [sp, 0x48]
	str r1, [sp, 0x4C]
	ldr r0, _080B3E64
	ldr r1, [sp, 0x48]
	ands r1, r0
	str r1, [sp, 0x48]
	ldr r0, _080B3E68
	adds r2, r1, 0
	orrs r2, r0
	str r2, [sp, 0x48]
	ldr r3, _080B3E6C
	add r8, r3
	movs r0, 0
	str r0, [sp, 0x58]
	ldr r6, [sp, 0x8]
	b _080B3ED0
	.align 2, 0
_080B3E64: .4byte 0x000fffff
_080B3E68: .4byte 0x3ff00000
_080B3E6C: .4byte 0xfffffc01
_080B3E70:
	ldr r1, [sp, 0x8]
	ldr r0, [sp, 0x4]
	adds r2, r1, r0
	ldr r3, _080B3E98
	adds r3, r2
	mov r8, r3
	adds r6, r1, 0
	cmp r3, 0x20
	ble _080B3EA0
	movs r0, 0x40
	subs r0, r3
	ldr r4, [sp, 0x40]
	lsls r4, r0
	ldr r1, _080B3E9C
	adds r0, r2, r1
	ldr r2, [sp, 0x44]
	lsrs r2, r0
	adds r0, r2, 0
	orrs r4, r0
	b _080B3EAA
	.align 2, 0
_080B3E98: .4byte 0x00000432
_080B3E9C: .4byte 0x00000412
_080B3EA0:
	movs r0, 0x20
	mov r3, r8
	subs r0, r3
	ldr r4, [sp, 0x44]
	lsls r4, r0
_080B3EAA:
	adds r0, r4, 0
	bl __floatsidf
	cmp r4, 0
	bge _080B3EBC
	ldr r3, _080B3F80
	ldr r2, _080B3F7C
	bl __adddf3
_080B3EBC:
	str r0, [sp, 0x48]
	str r1, [sp, 0x4C]
	ldr r1, _080B3F84
	ldr r0, [sp, 0x48]
	adds r1, r0, r1
	str r1, [sp, 0x48]
	ldr r2, _080B3F88
	add r8, r2
	movs r3, 0x1
	str r3, [sp, 0x58]
_080B3ED0:
	ldr r2, _080B3F8C
	ldr r3, _080B3F90
	ldr r0, [sp, 0x48]
	ldr r1, [sp, 0x4C]
	bl __subdf3
	ldr r2, _080B3F94
	ldr r3, _080B3F98
	bl __muldf3
	ldr r2, _080B3F9C
	ldr r3, _080B3FA0
	bl __adddf3
	adds r5, r1, 0
	adds r4, r0, 0
	mov r0, r8
	bl __floatsidf
	ldr r2, _080B3FA4
	ldr r3, _080B3FA8
	bl __muldf3
	adds r3, r1, 0
	adds r2, r0, 0
	adds r1, r5, 0
	adds r0, r4, 0
	bl __adddf3
	str r0, [sp, 0x6C]
	str r1, [sp, 0x70]
	bl __fixdfsi
	str r0, [sp, 0x24]
	ldr r2, _080B3FAC
	ldr r3, _080B3FB0
	ldr r0, [sp, 0x6C]
	ldr r1, [sp, 0x70]
	bl __ltdf2
	cmp r0, 0
	bge _080B3F40
	ldr r0, [sp, 0x24]
	bl __floatsidf
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r0, [sp, 0x6C]
	ldr r1, [sp, 0x70]
	bl __nedf2
	cmp r0, 0
	beq _080B3F40
	ldr r0, [sp, 0x24]
	subs r0, 0x1
	str r0, [sp, 0x24]
_080B3F40:
	movs r1, 0x1
	str r1, [sp, 0x2C]
	ldr r2, [sp, 0x24]
	cmp r2, 0x16
	bhi _080B3F6A
	ldr r1, _080B3FB4
	lsls r0, r2, 3
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r0, 0x4]
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __ltdf2
	cmp r0, 0
	bge _080B3F66
	ldr r3, [sp, 0x24]
	subs r3, 0x1
	str r3, [sp, 0x24]
_080B3F66:
	movs r0, 0
	str r0, [sp, 0x2C]
_080B3F6A:
	mov r1, r8
	subs r0, r6, r1
	subs r4, r0, 0x1
	cmp r4, 0
	blt _080B3FB8
	movs r2, 0
	str r2, [sp, 0x10]
	str r4, [sp, 0x34]
	b _080B3FC0
	.align 2, 0
_080B3F7C: .4byte 0x41f00000
_080B3F80: .4byte 0x00000000
_080B3F84: .4byte 0xfe100000
_080B3F88: .4byte 0xfffffbcd
_080B3F8C: .4byte 0x3ff80000
_080B3F90: .4byte 0x00000000
_080B3F94: .4byte 0x3fd287a7
_080B3F98: .4byte 0x636f4361
_080B3F9C: .4byte 0x3fc68a28
_080B3FA0: .4byte 0x8b60c8b3
_080B3FA4: .4byte 0x3fd34413
_080B3FA8: .4byte 0x509f79fb
_080B3FAC: .4byte 0x00000000
_080B3FB0: .4byte 0x00000000
_080B3FB4: .4byte gUnknown_826FEC0
_080B3FB8:
	negs r4, r4
	str r4, [sp, 0x10]
	movs r3, 0
	str r3, [sp, 0x34]
_080B3FC0:
	ldr r0, [sp, 0x24]
	cmp r0, 0
	blt _080B3FD4
	movs r1, 0
	str r1, [sp, 0x14]
	str r0, [sp, 0x38]
	ldr r2, [sp, 0x34]
	adds r2, r0
	str r2, [sp, 0x34]
	b _080B3FE4
_080B3FD4:
	ldr r3, [sp, 0x10]
	ldr r0, [sp, 0x24]
	subs r3, r0
	str r3, [sp, 0x10]
	negs r1, r0
	str r1, [sp, 0x14]
	movs r2, 0
	str r2, [sp, 0x38]
_080B3FE4:
	ldr r3, [sp, 0xC]
	cmp r3, 0x9
	bls _080B3FEE
	movs r0, 0
	str r0, [sp, 0xC]
_080B3FEE:
	movs r5, 0x1
	ldr r1, [sp, 0xC]
	cmp r1, 0x5
	ble _080B3FFC
	subs r1, 0x4
	str r1, [sp, 0xC]
	movs r5, 0
_080B3FFC:
	movs r2, 0x1
	str r2, [sp, 0x30]
	ldr r3, [sp, 0xC]
	cmp r3, 0x5
	bhi _080B4076
	lsls r0, r3, 2
	ldr r1, _080B4010
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B4010: .4byte _080B4014
	.align 2, 0
_080B4014:
	.4byte _080B402C
	.4byte _080B402C
	.4byte _080B403E
	.4byte _080B405A
	.4byte _080B4042
	.4byte _080B405E
_080B402C:
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x18]
	str r0, [sp, 0x20]
	movs r1, 0x12
	mov r8, r1
	movs r2, 0
	str r2, [sp, 0xA4]
	b _080B4076
_080B403E:
	movs r3, 0
	str r3, [sp, 0x30]
_080B4042:
	ldr r0, [sp, 0xA4]
	cmp r0, 0
	bgt _080B404C
	movs r1, 0x1
	str r1, [sp, 0xA4]
_080B404C:
	ldr r2, [sp, 0xA4]
	mov r8, r2
	mov r3, r8
	str r3, [sp, 0x20]
	mov r0, r8
	str r0, [sp, 0x18]
	b _080B4076
_080B405A:
	movs r1, 0
	str r1, [sp, 0x30]
_080B405E:
	ldr r2, [sp, 0xA4]
	ldr r3, [sp, 0x24]
	adds r0, r2, r3
	adds r1, r0, 0x1
	mov r8, r1
	mov r2, r8
	str r2, [sp, 0x18]
	str r0, [sp, 0x20]
	cmp r1, 0
	bgt _080B4076
	movs r3, 0x1
	mov r8, r3
_080B4076:
	movs r4, 0x4
	movs r0, 0
	mov r1, r10
	str r0, [r1, 0x44]
	mov r2, r8
	cmp r2, 0x17
	bls _080B4096
	movs r1, 0
_080B4086:
	adds r1, 0x1
	lsls r4, 1
	adds r0, r4, 0
	adds r0, 0x14
	cmp r0, r8
	bls _080B4086
	mov r3, r10
	str r1, [r3, 0x44]
_080B4096:
	mov r0, r10
	ldr r1, [r0, 0x44]
	bl sub_80B58B0
	mov r1, r10
	str r0, [r1, 0x40]
	str r0, [sp, 0x74]
	mov r9, r0
	ldr r2, [sp, 0x18]
	cmp r2, 0xE
	bls _080B40AE
	b _080B4420
_080B40AE:
	cmp r5, 0
	bne _080B40B4
	b _080B4420
_080B40B4:
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	str r0, [sp, 0x78]
	str r1, [sp, 0x7C]
	str r0, [sp, 0x48]
	str r1, [sp, 0x4C]
	ldr r1, [sp, 0x24]
	str r1, [sp, 0x28]
	str r2, [sp, 0x1C]
	movs r7, 0x2
	cmp r1, 0
	ble _080B4144
	ldr r0, _080B413C
	movs r2, 0xF
	ands r1, r2
	lsls r1, 3
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [sp, 0x6C]
	str r1, [sp, 0x70]
	ldr r1, [sp, 0x24]
	asrs r4, r1, 4
	movs r0, 0x10
	ands r0, r4
	cmp r0, 0
	beq _080B4100
	ands r4, r2
	ldr r0, _080B4140
	ldr r2, [r0, 0x20]
	ldr r3, [r0, 0x24]
	ldr r0, [sp, 0x78]
	ldr r1, [sp, 0x7C]
	bl __divdf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	movs r7, 0x3
_080B4100:
	cmp r4, 0
	beq _080B4128
	ldr r5, _080B4140
_080B4106:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _080B4120
	adds r7, 0x1
	ldr r2, [r5]
	ldr r3, [r5, 0x4]
	ldr r0, [sp, 0x6C]
	ldr r1, [sp, 0x70]
	bl __muldf3
	str r0, [sp, 0x6C]
	str r1, [sp, 0x70]
_080B4120:
	asrs r4, 1
	adds r5, 0x8
	cmp r4, 0
	bne _080B4106
_080B4128:
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	ldr r2, [sp, 0x6C]
	ldr r3, [sp, 0x70]
	bl __divdf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	b _080B4190
	.align 2, 0
_080B413C: .4byte gUnknown_826FEC0
_080B4140: .4byte gUnknown_826FF88
_080B4144:
	ldr r2, [sp, 0x24]
	negs r6, r2
	cmp r6, 0
	beq _080B4190
	ldr r1, _080B4238
	movs r0, 0xF
	ands r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	ldr r2, [sp, 0x78]
	ldr r3, [sp, 0x7C]
	bl __muldf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	asrs r4, r6, 4
	cmp r4, 0
	beq _080B4190
	ldr r5, _080B423C
_080B416E:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _080B4188
	adds r7, 0x1
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x44]
	bl __muldf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
_080B4188:
	asrs r4, 1
	adds r5, 0x8
	cmp r4, 0
	bne _080B416E
_080B4190:
	ldr r3, [sp, 0x2C]
	cmp r3, 0
	beq _080B41CE
	ldr r2, _080B4240
	ldr r3, _080B4244
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __ltdf2
	cmp r0, 0
	bge _080B41CE
	ldr r0, [sp, 0x18]
	cmp r0, 0
	ble _080B41CE
	ldr r1, [sp, 0x20]
	cmp r1, 0
	bgt _080B41B4
	b _080B440C
_080B41B4:
	str r1, [sp, 0x18]
	ldr r2, [sp, 0x24]
	subs r2, 0x1
	str r2, [sp, 0x24]
	ldr r0, _080B4248
	ldr r1, _080B424C
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x44]
	bl __muldf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	adds r7, 0x1
_080B41CE:
	adds r0, r7, 0
	bl __floatsidf
	ldr r2, [sp, 0x40]
	ldr r3, [sp, 0x44]
	bl __muldf3
	ldr r2, _080B4250
	ldr r3, _080B4254
	bl __adddf3
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	ldr r0, _080B4258
	ldr r3, [sp, 0x50]
	adds r0, r3, r0
	str r0, [sp, 0x50]
	ldr r1, [sp, 0x18]
	cmp r1, 0
	bne _080B4264
	movs r2, 0
	str r2, [sp, 0x64]
	movs r3, 0
	str r3, [sp, 0x68]
	ldr r2, _080B425C
	ldr r3, _080B4260
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __subdf3
	adds r5, r1, 0
	adds r4, r0, 0
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __gtdf2
	cmp r0, 0
	ble _080B421C
	b _080B4796
_080B421C:
	ldr r0, [sp, 0x50]
	ldr r1, [sp, 0x54]
	bl __negdf2
	adds r3, r1, 0
	adds r2, r0, 0
	adds r1, r5, 0
	adds r0, r4, 0
	bl __ltdf2
	cmp r0, 0
	bge _080B4236
	b _080B478E
_080B4236:
	b _080B440C
	.align 2, 0
_080B4238: .4byte gUnknown_826FEC0
_080B423C: .4byte gUnknown_826FF88
_080B4240: .4byte 0x3ff00000
_080B4244: .4byte 0x00000000
_080B4248: .4byte 0x40240000
_080B424C: .4byte 0x00000000
_080B4250: .4byte 0x401c0000
_080B4254: .4byte 0x00000000
_080B4258: .4byte 0xfcc00000
_080B425C: .4byte 0x40140000
_080B4260: .4byte 0x00000000
_080B4264:
	ldr r0, [sp, 0x30]
	cmp r0, 0
	beq _080B4334
	ldr r1, _080B4294
	ldr r0, [sp, 0x18]
	subs r0, 0x1
	lsls r0, 3
	adds r0, r1
	ldr r2, [r0]
	ldr r3, [r0, 0x4]
	ldr r0, _080B4298
	ldr r1, _080B429C
	bl __divdf3
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __subdf3
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	movs r1, 0
	mov r8, r1
	b _080B42C0
	.align 2, 0
_080B4294: .4byte gUnknown_826FEC0
_080B4298: .4byte 0x3fe00000
_080B429C: .4byte 0x00000000
_080B42A0:
	ldr r1, _080B4328
	ldr r0, _080B4324
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __muldf3
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	ldr r1, _080B4328
	ldr r0, _080B4324
	adds r3, r5, 0
	adds r2, r4, 0
	bl __muldf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
_080B42C0:
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __fixdfsi
	adds r6, r0, 0
	bl __floatsidf
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __subdf3
	adds r5, r1, 0
	adds r4, r0, 0
	adds r0, r6, 0
	adds r0, 0x30
	mov r2, r9
	strb r0, [r2]
	movs r3, 0x1
	add r9, r3
	adds r1, r5, 0
	adds r0, r4, 0
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __ltdf2
	cmp r0, 0
	bge _080B42FC
	b _080B4A06
_080B42FC:
	ldr r0, _080B432C
	ldr r1, _080B4330
	adds r3, r5, 0
	adds r2, r4, 0
	bl __subdf3
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __ltdf2
	cmp r0, 0
	bge _080B4316
	b _080B4520
_080B4316:
	movs r0, 0x1
	add r8, r0
	ldr r1, [sp, 0x18]
	cmp r8, r1
	blt _080B42A0
	b _080B440C
	.align 2, 0
_080B4324: .4byte 0x40240000
_080B4328: .4byte 0x00000000
_080B432C: .4byte 0x3ff00000
_080B4330: .4byte 0x00000000
_080B4334:
	ldr r1, _080B4354
	ldr r0, [sp, 0x18]
	subs r0, 0x1
	lsls r0, 3
	adds r0, r1
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __muldf3
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
	movs r2, 0x1
	mov r8, r2
	b _080B436C
	.align 2, 0
_080B4354: .4byte gUnknown_826FEC0
_080B4358:
	movs r3, 0x1
	add r8, r3
	ldr r1, _080B4400
	ldr r0, _080B43FC
	adds r3, r5, 0
	adds r2, r4, 0
	bl __muldf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
_080B436C:
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __fixdfsi
	adds r6, r0, 0
	bl __floatsidf
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __subdf3
	adds r5, r1, 0
	adds r4, r0, 0
	adds r0, r6, 0
	adds r0, 0x30
	mov r1, r9
	strb r0, [r1]
	movs r2, 0x1
	add r9, r2
	ldr r3, [sp, 0x18]
	cmp r8, r3
	bne _080B4358
	ldr r6, _080B4404
	ldr r7, _080B4408
	adds r1, r7, 0
	adds r0, r6, 0
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __adddf3
	adds r3, r1, 0
	adds r2, r0, 0
	adds r1, r5, 0
	adds r0, r4, 0
	bl __gtdf2
	cmp r0, 0
	ble _080B43BE
	b _080B4520
_080B43BE:
	adds r1, r7, 0
	adds r0, r6, 0
	ldr r2, [sp, 0x50]
	ldr r3, [sp, 0x54]
	bl __subdf3
	adds r3, r1, 0
	adds r2, r0, 0
	adds r1, r5, 0
	adds r0, r4, 0
	bl __ltdf2
	cmp r0, 0
	bge _080B440C
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	ldrb r1, [r1]
	cmp r1, 0x30
	beq _080B43EA
	b _080B4546
_080B43EA:
	movs r2, 0x1
	negs r2, r2
	add r9, r2
	mov r3, r9
	ldrb r3, [r3]
	cmp r3, 0x30
	beq _080B43EA
	b _080B4546
	.align 2, 0
_080B43FC: .4byte 0x40240000
_080B4400: .4byte 0x00000000
_080B4404: .4byte 0x3fe00000
_080B4408: .4byte 0x00000000
_080B440C:
	ldr r1, [sp, 0x74]
	mov r9, r1
	ldr r2, [sp, 0x48]
	ldr r3, [sp, 0x4C]
	str r2, [sp, 0x40]
	str r3, [sp, 0x44]
	ldr r3, [sp, 0x28]
	str r3, [sp, 0x24]
	ldr r0, [sp, 0x1C]
	str r0, [sp, 0x18]
_080B4420:
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _080B4428
	b _080B455C
_080B4428:
	ldr r1, [sp, 0x24]
	cmp r1, 0xE
	ble _080B4430
	b _080B455C
_080B4430:
	ldr r1, _080B447C
	ldr r2, [sp, 0x24]
	lsls r0, r2, 3
	adds r0, r1
	ldr r1, [r0]
	ldr r2, [r0, 0x4]
	str r1, [sp, 0x6C]
	str r2, [sp, 0x70]
	ldr r2, [sp, 0xA4]
	cmp r2, 0
	bge _080B4488
	ldr r3, [sp, 0x18]
	cmp r3, 0
	bgt _080B4488
	movs r0, 0
	str r0, [sp, 0x64]
	movs r1, 0
	str r1, [sp, 0x68]
	cmp r3, 0
	bge _080B445A
	b _080B478E
_080B445A:
	ldr r2, _080B4480
	ldr r3, _080B4484
	ldr r0, [sp, 0x6C]
	ldr r1, [sp, 0x70]
	bl __muldf3
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __ledf2
	cmp r0, 0
	bgt _080B4478
	b _080B478E
_080B4478:
	b _080B4796
	.align 2, 0
_080B447C: .4byte gUnknown_826FEC0
_080B4480: .4byte 0x40140000
_080B4484: .4byte 0x00000000
_080B4488:
	movs r2, 0x1
	mov r8, r2
	b _080B44AC
_080B448E:
	ldr r1, _080B4550
	ldr r0, _080B454C
	bl __muldf3
	str r0, [sp, 0x40]
	str r1, [sp, 0x44]
	ldr r2, _080B4554
	ldr r3, _080B4558
	bl __eqdf2
	cmp r0, 0
	bne _080B44A8
	b _080B4A06
_080B44A8:
	movs r3, 0x1
	add r8, r3
_080B44AC:
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	ldr r2, [sp, 0x6C]
	ldr r3, [sp, 0x70]
	bl __divdf3
	bl __fixdfsi
	adds r6, r0, 0
	bl __floatsidf
	ldr r2, [sp, 0x6C]
	ldr r3, [sp, 0x70]
	bl __muldf3
	adds r3, r1, 0
	adds r2, r0, 0
	ldr r0, [sp, 0x40]
	ldr r1, [sp, 0x44]
	bl __subdf3
	adds r3, r1, 0
	adds r2, r0, 0
	adds r0, r6, 0
	adds r0, 0x30
	mov r1, r9
	strb r0, [r1]
	movs r0, 0x1
	add r9, r0
	ldr r1, [sp, 0x18]
	cmp r8, r1
	bne _080B448E
	adds r1, r3, 0
	adds r0, r2, 0
	bl __adddf3
	adds r5, r1, 0
	adds r4, r0, 0
	ldr r2, [sp, 0x6C]
	ldr r3, [sp, 0x70]
	bl __gtdf2
	cmp r0, 0
	bgt _080B4520
	adds r1, r5, 0
	adds r0, r4, 0
	ldr r2, [sp, 0x6C]
	ldr r3, [sp, 0x70]
	bl __eqdf2
	cmp r0, 0
	beq _080B4516
	b _080B4A06
_080B4516:
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	bne _080B4520
	b _080B4A06
_080B4520:
	movs r0, 0x30
_080B4522:
	movs r2, 0x1
	negs r2, r2
	add r9, r2
	mov r3, r9
	ldrb r3, [r3]
	cmp r3, 0x39
	bne _080B453E
	ldr r1, [sp, 0x74]
	cmp r9, r1
	bne _080B4522
	ldr r2, [sp, 0x24]
	adds r2, 0x1
	str r2, [sp, 0x24]
	strb r0, [r1]
_080B453E:
	mov r3, r9
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_080B4546:
	movs r0, 0x1
	add r9, r0
	b _080B4A06
	.align 2, 0
_080B454C: .4byte 0x40240000
_080B4550: .4byte 0x00000000
_080B4554: .4byte 0x00000000
_080B4558: .4byte 0x00000000
_080B455C:
	ldr r5, [sp, 0x10]
	ldr r6, [sp, 0x14]
	movs r1, 0
	str r1, [sp, 0x60]
	movs r2, 0
	str r2, [sp, 0x64]
	ldr r3, [sp, 0x30]
	cmp r3, 0
	beq _080B45D2
	ldr r1, [sp, 0xC]
	cmp r1, 0x1
	bgt _080B4590
	ldr r2, [sp, 0x58]
	cmp r2, 0
	beq _080B4588
	ldr r3, _080B4584
	adds r3, r0
	mov r8, r3
	b _080B45BC
	.align 2, 0
_080B4584: .4byte 0x00000433
_080B4588:
	ldr r1, [sp, 0x8]
	movs r0, 0x36
	subs r0, r1
	b _080B45BA
_080B4590:
	ldr r4, [sp, 0x18]
	subs r4, 0x1
	ldr r0, [sp, 0x14]
	cmp r0, r4
	blt _080B459E
	subs r6, r0, r4
	b _080B45AE
_080B459E:
	ldr r1, [sp, 0x14]
	subs r4, r1
	ldr r2, [sp, 0x38]
	adds r2, r4
	str r2, [sp, 0x38]
	adds r1, r4
	str r1, [sp, 0x14]
	movs r6, 0
_080B45AE:
	ldr r3, [sp, 0x18]
	mov r8, r3
	cmp r3, 0
	bge _080B45BC
	subs r5, r3
	movs r0, 0
_080B45BA:
	mov r8, r0
_080B45BC:
	ldr r1, [sp, 0x10]
	add r1, r8
	str r1, [sp, 0x10]
	ldr r2, [sp, 0x34]
	add r2, r8
	str r2, [sp, 0x34]
	mov r0, r10
	movs r1, 0x1
	bl sub_80B5B18
	str r0, [sp, 0x64]
_080B45D2:
	cmp r5, 0
	ble _080B45F4
	ldr r3, [sp, 0x34]
	cmp r3, 0
	ble _080B45F4
	mov r8, r3
	cmp r8, r5
	ble _080B45E4
	mov r8, r5
_080B45E4:
	ldr r0, [sp, 0x10]
	mov r1, r8
	subs r0, r1
	str r0, [sp, 0x10]
	subs r5, r1
	ldr r2, [sp, 0x34]
	subs r2, r1
	str r2, [sp, 0x34]
_080B45F4:
	ldr r3, [sp, 0x14]
	cmp r3, 0
	ble _080B4642
	ldr r0, [sp, 0x30]
	cmp r0, 0
	beq _080B4636
	cmp r6, 0
	ble _080B4626
	mov r0, r10
	ldr r1, [sp, 0x64]
	adds r2, r6, 0
	bl sub_80B5C98
	str r0, [sp, 0x64]
	mov r0, r10
	ldr r1, [sp, 0x64]
	ldr r2, [sp, 0x5C]
	bl sub_80B5B2C
	adds r4, r0, 0
	mov r0, r10
	ldr r1, [sp, 0x5C]
	bl sub_80B5908
	str r4, [sp, 0x5C]
_080B4626:
	ldr r1, [sp, 0x14]
	subs r4, r1, r6
	cmp r4, 0
	beq _080B4642
	mov r0, r10
	ldr r1, [sp, 0x5C]
	adds r2, r4, 0
	b _080B463C
_080B4636:
	mov r0, r10
	ldr r1, [sp, 0x5C]
	ldr r2, [sp, 0x14]
_080B463C:
	bl sub_80B5C98
	str r0, [sp, 0x5C]
_080B4642:
	mov r0, r10
	movs r1, 0x1
	bl sub_80B5B18
	str r0, [sp, 0x68]
	ldr r2, [sp, 0x38]
	cmp r2, 0
	ble _080B465C
	mov r0, r10
	ldr r1, [sp, 0x68]
	bl sub_80B5C98
	str r0, [sp, 0x68]
_080B465C:
	ldr r3, [sp, 0xC]
	cmp r3, 0x1
	bgt _080B4698
	ldr r0, [sp, 0x44]
	cmp r0, 0
	bne _080B4694
	ldr r0, _080B468C
	ldr r1, [sp, 0x40]
	ands r0, r1
	cmp r0, 0
	bne _080B4694
	ldr r0, _080B4690
	ands r1, r0
	cmp r1, 0
	beq _080B4694
	ldr r1, [sp, 0x10]
	adds r1, 0x1
	str r1, [sp, 0x10]
	ldr r2, [sp, 0x34]
	adds r2, 0x1
	str r2, [sp, 0x34]
	movs r3, 0x1
	str r3, [sp, 0x3C]
	b _080B4698
	.align 2, 0
_080B468C: .4byte 0x000fffff
_080B4690: .4byte 0x7ff00000
_080B4694:
	movs r0, 0
	str r0, [sp, 0x3C]
_080B4698:
	ldr r1, [sp, 0x38]
	cmp r1, 0
	beq _080B46C4
	ldr r2, [sp, 0x68]
	ldr r1, [r2, 0x10]
	subs r1, 0x1
	lsls r1, 2
	adds r0, r2, 0
	adds r0, 0x14
	adds r0, r1
	ldr r0, [r0]
	bl sub_80B5A3C
	ldr r1, [sp, 0x34]
	adds r1, 0x20
	subs r1, r0
	mov r8, r1
	movs r0, 0x1F
	mov r3, r8
	ands r3, r0
	mov r8, r3
	b _080B46D2
_080B46C4:
	ldr r0, [sp, 0x34]
	adds r0, 0x1
	mov r8, r0
	movs r0, 0x1F
	mov r1, r8
	ands r1, r0
	mov r8, r1
_080B46D2:
	mov r2, r8
	cmp r2, 0
	beq _080B46DE
	movs r0, 0x20
	subs r2, r0, r2
	mov r8, r2
_080B46DE:
	mov r3, r8
	cmp r3, 0x4
	ble _080B46EA
	movs r0, 0x4
	negs r0, r0
	b _080B46F2
_080B46EA:
	mov r3, r8
	cmp r3, 0x3
	bgt _080B4702
	movs r0, 0x1C
_080B46F2:
	add r8, r0
	ldr r1, [sp, 0x10]
	add r1, r8
	str r1, [sp, 0x10]
	add r5, r8
	ldr r2, [sp, 0x34]
	add r2, r8
	str r2, [sp, 0x34]
_080B4702:
	ldr r3, [sp, 0x10]
	cmp r3, 0
	ble _080B4714
	mov r0, r10
	ldr r1, [sp, 0x5C]
	adds r2, r3, 0
	bl sub_80B5D30
	str r0, [sp, 0x5C]
_080B4714:
	ldr r0, [sp, 0x34]
	cmp r0, 0
	ble _080B4726
	mov r0, r10
	ldr r1, [sp, 0x68]
	ldr r2, [sp, 0x34]
	bl sub_80B5D30
	str r0, [sp, 0x68]
_080B4726:
	ldr r1, [sp, 0x2C]
	cmp r1, 0
	beq _080B4764
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x68]
	bl sub_80B5DD0
	cmp r0, 0
	bge _080B4764
	ldr r2, [sp, 0x24]
	subs r2, 0x1
	str r2, [sp, 0x24]
	mov r0, r10
	ldr r1, [sp, 0x5C]
	movs r2, 0xA
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x5C]
	ldr r3, [sp, 0x30]
	cmp r3, 0
	beq _080B4760
	mov r0, r10
	ldr r1, [sp, 0x64]
	movs r2, 0xA
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x64]
_080B4760:
	ldr r0, [sp, 0x20]
	str r0, [sp, 0x18]
_080B4764:
	ldr r1, [sp, 0x18]
	cmp r1, 0
	bgt _080B47A8
	ldr r2, [sp, 0xC]
	cmp r2, 0x2
	ble _080B47A8
	cmp r1, 0
	blt _080B478E
	mov r0, r10
	ldr r1, [sp, 0x68]
	movs r2, 0x5
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x68]
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x68]
	bl sub_80B5DD0
	cmp r0, 0
	bgt _080B4796
_080B478E:
	ldr r3, [sp, 0xA4]
	mvns r3, r3
	str r3, [sp, 0x24]
	b _080B49DE
_080B4796:
	movs r0, 0x31
	mov r1, r9
	strb r0, [r1]
	movs r2, 0x1
	add r9, r2
	ldr r3, [sp, 0x24]
	adds r3, 0x1
	str r3, [sp, 0x24]
	b _080B49DE
_080B47A8:
	ldr r0, [sp, 0x30]
	cmp r0, 0
	bne _080B47B0
	b _080B4926
_080B47B0:
	cmp r5, 0
	ble _080B47C0
	mov r0, r10
	ldr r1, [sp, 0x64]
	adds r2, r5, 0
	bl sub_80B5D30
	str r0, [sp, 0x64]
_080B47C0:
	ldr r1, [sp, 0x64]
	str r1, [sp, 0x60]
	ldr r2, [sp, 0x3C]
	cmp r2, 0
	beq _080B47F2
	ldr r1, [r1, 0x4]
	mov r0, r10
	bl sub_80B58B0
	str r0, [sp, 0x64]
	adds r0, 0xC
	ldr r1, [sp, 0x60]
	adds r1, 0xC
	ldr r3, [sp, 0x60]
	ldr r2, [r3, 0x10]
	lsls r2, 2
	adds r2, 0x8
	bl memcpy
	mov r0, r10
	ldr r1, [sp, 0x64]
	movs r2, 0x1
	bl sub_80B5D30
	str r0, [sp, 0x64]
_080B47F2:
	movs r0, 0x1
	mov r8, r0
	mov r1, r8
	ldr r2, [sp, 0x44]
	ands r2, r1
	str r2, [sp, 0x80]
	b _080B4848
_080B4800:
	mov r0, r10
	ldr r1, [sp, 0x5C]
	movs r2, 0xA
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x5C]
	ldr r3, [sp, 0x60]
	ldr r0, [sp, 0x64]
	cmp r3, r0
	bne _080B4828
	mov r0, r10
	ldr r1, [sp, 0x64]
	movs r2, 0xA
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x64]
	str r0, [sp, 0x60]
	b _080B4844
_080B4828:
	mov r0, r10
	ldr r1, [sp, 0x60]
	movs r2, 0xA
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x60]
	mov r0, r10
	ldr r1, [sp, 0x64]
	movs r2, 0xA
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x64]
_080B4844:
	movs r1, 0x1
	add r8, r1
_080B4848:
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x68]
	bl sub_80B3BE0
	adds r7, r0, 0
	adds r7, 0x30
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x60]
	bl sub_80B5DD0
	adds r4, r0, 0
	mov r0, r10
	ldr r1, [sp, 0x68]
	ldr r2, [sp, 0x64]
	bl sub_80B5E10
	adds r5, r0, 0
	ldr r0, [r5, 0xC]
	cmp r0, 0
	bne _080B487C
	ldr r0, [sp, 0x5C]
	adds r1, r5, 0
	bl sub_80B5DD0
	adds r6, r0, 0
	b _080B487E
_080B487C:
	movs r6, 0x1
_080B487E:
	mov r0, r10
	adds r1, r5, 0
	bl sub_80B5908
	cmp r6, 0
	bne _080B48AA
	ldr r2, [sp, 0xC]
	cmp r2, 0
	bne _080B48AA
	ldr r3, [sp, 0x80]
	cmp r3, 0
	bne _080B48AA
	cmp r7, 0x39
	beq _080B48FC
	cmp r4, 0
	ble _080B48A0
	adds r7, 0x1
_080B48A0:
	mov r0, r9
	strb r7, [r0]
	movs r1, 0x1
	add r9, r1
	b _080B49DE
_080B48AA:
	cmp r4, 0
	blt _080B48BE
	cmp r4, 0
	bne _080B48F4
	ldr r2, [sp, 0xC]
	cmp r2, 0
	bne _080B48F4
	ldr r3, [sp, 0x80]
	cmp r3, 0
	bne _080B48F4
_080B48BE:
	cmp r6, 0
	ble _080B48EE
	mov r0, r10
	ldr r1, [sp, 0x5C]
	movs r2, 0x1
	bl sub_80B5D30
	str r0, [sp, 0x5C]
	ldr r1, [sp, 0x68]
	bl sub_80B5DD0
	adds r6, r0, 0
	cmp r6, 0
	bgt _080B48E8
	cmp r6, 0
	bne _080B48EE
	adds r0, r7, 0
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B48EE
_080B48E8:
	adds r7, 0x1
	cmp r7, 0x3A
	beq _080B48FC
_080B48EE:
	mov r2, r9
	strb r7, [r2]
	b _080B49A6
_080B48F4:
	cmp r6, 0
	ble _080B4914
	cmp r7, 0x39
	bne _080B4908
_080B48FC:
	movs r0, 0x39
	mov r1, r9
	strb r0, [r1]
	movs r2, 0x1
	add r9, r2
	b _080B497C
_080B4908:
	adds r0, r7, 0x1
	mov r3, r9
	strb r0, [r3]
	movs r0, 0x1
	add r9, r0
	b _080B49DE
_080B4914:
	mov r1, r9
	strb r7, [r1]
	movs r2, 0x1
	add r9, r2
	ldr r3, [sp, 0x18]
	cmp r8, r3
	beq _080B4924
	b _080B4800
_080B4924:
	b _080B4958
_080B4926:
	movs r0, 0x1
	mov r8, r0
	b _080B493E
_080B492C:
	mov r0, r10
	ldr r1, [sp, 0x5C]
	movs r2, 0xA
	movs r3, 0
	bl sub_80B5920
	str r0, [sp, 0x5C]
	movs r1, 0x1
	add r8, r1
_080B493E:
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x68]
	bl sub_80B3BE0
	adds r7, r0, 0
	adds r7, 0x30
	mov r2, r9
	strb r7, [r2]
	movs r3, 0x1
	add r9, r3
	ldr r0, [sp, 0x18]
	cmp r8, r0
	blt _080B492C
_080B4958:
	mov r0, r10
	ldr r1, [sp, 0x5C]
	movs r2, 0x1
	bl sub_80B5D30
	str r0, [sp, 0x5C]
	ldr r1, [sp, 0x68]
	bl sub_80B5DD0
	adds r4, r0, 0
	cmp r4, 0
	bgt _080B497C
	cmp r4, 0
	bne _080B49BE
	movs r0, 0x1
	ands r7, r0
	cmp r7, 0
	beq _080B49BE
_080B497C:
	movs r1, 0x1
	negs r1, r1
	add r9, r1
	mov r2, r9
	ldrb r2, [r2]
	cmp r2, 0x39
	bne _080B499E
_080B498A:
	ldr r3, [sp, 0x74]
	cmp r9, r3
	beq _080B49AC
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	ldrb r1, [r1]
	cmp r1, 0x39
	beq _080B498A
_080B499E:
	mov r2, r9
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
_080B49A6:
	movs r3, 0x1
	add r9, r3
	b _080B49DE
_080B49AC:
	ldr r0, [sp, 0x24]
	adds r0, 0x1
	str r0, [sp, 0x24]
	movs r0, 0x31
	ldr r1, [sp, 0x74]
	strb r0, [r1]
	adds r1, 0x1
	mov r9, r1
	b _080B49DE
_080B49BE:
	movs r2, 0x1
	negs r2, r2
	add r9, r2
	mov r3, r9
	ldrb r3, [r3]
	cmp r3, 0x30
	bne _080B49DA
_080B49CC:
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	ldrb r1, [r1]
	cmp r1, 0x30
	beq _080B49CC
_080B49DA:
	movs r2, 0x1
	add r9, r2
_080B49DE:
	mov r0, r10
	ldr r1, [sp, 0x68]
	bl sub_80B5908
	ldr r3, [sp, 0x64]
	cmp r3, 0
	beq _080B4A06
	ldr r0, [sp, 0x60]
	cmp r0, 0
	beq _080B49FE
	cmp r0, r3
	beq _080B49FE
	mov r0, r10
	ldr r1, [sp, 0x60]
	bl sub_80B5908
_080B49FE:
	mov r0, r10
	ldr r1, [sp, 0x64]
	bl sub_80B5908
_080B4A06:
	mov r0, r10
	ldr r1, [sp, 0x5C]
	bl sub_80B5908
	movs r0, 0
	mov r1, r9
	strb r0, [r1]
	ldr r0, [sp, 0x24]
	adds r0, 0x1
	ldr r2, [sp, 0xA8]
	str r0, [r2]
	ldr r3, [sp, 0xB0]
	cmp r3, 0
	beq _080B4A24
	str r1, [r3]
_080B4A24:
	ldr r0, [sp, 0x74]
_080B4A26:
	add sp, 0x84
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	thumb_func_end _dtoa_r

	thumb_func_start sub_80B4A34
sub_80B4A34:
	push {r4-r6,lr}
	adds r4, r0, 0
	cmp r4, 0
	bne _080B4A50
	ldr r0, _080B4A48
	ldr r0, [r0]
	ldr r1, _080B4A4C
	bl sub_80B50D0
	b _080B4AC6
	.align 2, 0
_080B4A48: .4byte gUnknown_203B7A8
_080B4A4C: .4byte sub_80B4A34
_080B4A50:
	ldr r0, [r4, 0x54]
	cmp r0, 0
	bne _080B4A5C
	ldr r0, _080B4A90
	ldr r0, [r0]
	str r0, [r4, 0x54]
_080B4A5C:
	ldr r1, [r4, 0x54]
	ldr r0, [r1, 0x38]
	cmp r0, 0
	bne _080B4A6A
	adds r0, r1, 0
	bl sub_80B4BC4
_080B4A6A:
	movs r0, 0xC
	ldrsh r1, [r4, r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080B4AC4
	ldr r6, [r4, 0x10]
	cmp r6, 0
	beq _080B4AC4
	ldr r0, [r4]
	subs r5, r0, r6
	str r6, [r4]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B4AA2
	ldr r0, [r4, 0x14]
	b _080B4AA4
	.align 2, 0
_080B4A90: .4byte gUnknown_203B7A8
_080B4A94:
	movs r0, 0x40
	ldrh r1, [r4, 0xC]
	orrs r0, r1
	strh r0, [r4, 0xC]
	movs r0, 0x1
	negs r0, r0
	b _080B4AC6
_080B4AA2:
	movs r0, 0
_080B4AA4:
	str r0, [r4, 0x8]
	cmp r5, 0
	ble _080B4AC4
_080B4AAA:
	ldr r0, [r4, 0x1C]
	ldr r3, [r4, 0x24]
	adds r1, r6, 0
	adds r2, r5, 0
	bl _call_via_r3
	adds r1, r0, 0
	cmp r1, 0
	ble _080B4A94
	adds r6, r1
	subs r5, r1
	cmp r5, 0
	bgt _080B4AAA
_080B4AC4:
	movs r0, 0
_080B4AC6:
	pop {r4-r6,pc}
	thumb_func_end sub_80B4A34

	thumb_func_start sub_80B4AC8
sub_80B4AC8:
	push {r4,lr}
	movs r4, 0
	str r4, [r0]
	str r4, [r0, 0x4]
	str r4, [r0, 0x8]
	strh r1, [r0, 0xC]
	strh r2, [r0, 0xE]
	str r4, [r0, 0x10]
	str r4, [r0, 0x18]
	str r0, [r0, 0x1C]
	ldr r1, _080B4AF0
	str r1, [r0, 0x20]
	ldr r1, _080B4AF4
	str r1, [r0, 0x24]
	ldr r1, _080B4AF8
	str r1, [r0, 0x28]
	ldr r1, _080B4AFC
	str r1, [r0, 0x2C]
	str r3, [r0, 0x54]
	pop {r4,pc}
	.align 2, 0
_080B4AF0: .4byte sub_80B61F0
_080B4AF4: .4byte sub_80B6224
_080B4AF8: .4byte sub_80B6264
_080B4AFC: .4byte sub_80B62A4
	thumb_func_end sub_80B4AC8

	thumb_func_start sub_80B4B00
sub_80B4B00:
	push {r4-r6,lr}
	adds r5, r1, 0
	movs r1, 0x58
	adds r6, r5, 0
	muls r6, r1
	adds r1, r6, 0
	adds r1, 0xC
	bl sub_80B53B4
	adds r4, r0, 0
	cmp r4, 0
	beq _080B4B2C
	adds r0, 0xC
	movs r1, 0
	str r1, [r4]
	str r5, [r4, 0x4]
	str r0, [r4, 0x8]
	adds r2, r6, 0
	bl memset
	adds r0, r4, 0
	b _080B4B2E
_080B4B2C:
	movs r0, 0
_080B4B2E:
	pop {r4-r6,pc}
	thumb_func_end sub_80B4B00

	thumb_func_start sub_80B4B30
sub_80B4B30:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, [r5, 0x38]
	cmp r0, 0
	bne _080B4B40
	adds r0, r5, 0
	bl sub_80B4BC4
_080B4B40:
	movs r0, 0xEC
	lsls r0, 1
	adds r4, r5, r0
	b _080B4B4A
_080B4B48:
	ldr r4, [r4]
_080B4B4A:
	ldr r2, [r4, 0x8]
	ldr r0, [r4, 0x4]
	b _080B4B5A
_080B4B50:
	movs r3, 0xC
	ldrsh r1, [r2, r3]
	cmp r1, 0
	beq _080B4B7C
	adds r2, 0x58
_080B4B5A:
	subs r0, 0x1
	cmp r0, 0
	bge _080B4B50
	ldr r0, [r4]
	cmp r0, 0
	bne _080B4B48
	adds r0, r5, 0
	movs r1, 0x4
	bl sub_80B4B00
	str r0, [r4]
	cmp r0, 0
	bne _080B4B48
	movs r0, 0xC
	str r0, [r5]
	movs r0, 0
	b _080B4B9C
_080B4B7C:
	movs r0, 0x1
	strh r0, [r2, 0xC]
	str r1, [r2]
	str r1, [r2, 0x8]
	str r1, [r2, 0x4]
	str r1, [r2, 0x10]
	str r1, [r2, 0x14]
	str r1, [r2, 0x18]
	ldr r0, _080B4BA0
	strh r0, [r2, 0xE]
	str r1, [r2, 0x30]
	str r1, [r2, 0x34]
	str r1, [r2, 0x44]
	str r1, [r2, 0x48]
	str r5, [r2, 0x54]
	adds r0, r2, 0
_080B4B9C:
	pop {r4,r5,pc}
	.align 2, 0
_080B4BA0: .4byte 0x0000ffff
	thumb_func_end sub_80B4B30

	thumb_func_start sub_80B4BA4
sub_80B4BA4:
	push {lr}
	ldr r1, _080B4BB0
	bl sub_80B50D0
	pop {pc}
	.align 2, 0
_080B4BB0: .4byte sub_80B4A34
	thumb_func_end sub_80B4BA4

	thumb_func_start sub_80B4BB4
sub_80B4BB4:
	push {lr}
	ldr r0, _080B4BC0
	ldr r0, [r0]
	bl sub_80B4BA4
	pop {pc}
	.align 2, 0
_080B4BC0: .4byte gUnknown_203B7A8
	thumb_func_end sub_80B4BB4

	thumb_func_start sub_80B4BC4
sub_80B4BC4:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, _080B4C20
	str r0, [r5, 0x3C]
	movs r0, 0x1
	str r0, [r5, 0x38]
	movs r0, 0xF2
	lsls r0, 1
	adds r4, r5, r0
	adds r0, r4, 0
	movs r1, 0x4
	movs r2, 0
	adds r3, r5, 0
	bl sub_80B4AC8
	movs r1, 0x8F
	lsls r1, 2
	adds r0, r5, r1
	movs r1, 0x9
	movs r2, 0x1
	adds r3, r5, 0
	bl sub_80B4AC8
	movs r1, 0xA5
	lsls r1, 2
	adds r0, r5, r1
	movs r1, 0xA
	movs r2, 0x2
	adds r3, r5, 0
	bl sub_80B4AC8
	movs r0, 0xEC
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0
	str r0, [r1]
	movs r0, 0xEE
	lsls r0, 1
	adds r1, r5, r0
	movs r0, 0x3
	str r0, [r1]
	movs r1, 0xF0
	lsls r1, 1
	adds r0, r5, r1
	str r4, [r0]
	pop {r4,r5,pc}
	.align 2, 0
_080B4C20: .4byte sub_80B4BA4
	thumb_func_end sub_80B4BC4

	thumb_func_start _free_r
_free_r:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	adds r4, r1, 0
	cmp r4, 0
	bne _080B4C36
	b _080B4DDA
_080B4C36:
	bl __malloc_lock
	adds r5, r4, 0
	subs r5, 0x8
	ldr r1, [r5, 0x4]
	movs r6, 0x2
	negs r6, r6
	ands r6, r1
	adds r7, r5, r6
	ldr r4, [r7, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r4, r0
	ldr r0, _080B4C98
	mov r12, r0
	ldr r0, [r0, 0x8]
	cmp r7, r0
	bne _080B4CA4
	adds r6, r4
	movs r4, 0x1
	ands r1, r4
	cmp r1, 0
	bne _080B4C72
	ldr r0, [r5]
	subs r5, r0
	adds r6, r0
	ldr r3, [r5, 0xC]
	ldr r2, [r5, 0x8]
	str r3, [r2, 0xC]
	str r2, [r3, 0x8]
_080B4C72:
	adds r0, r6, 0
	orrs r0, r4
	str r0, [r5, 0x4]
	mov r2, r12
	str r5, [r2, 0x8]
	ldr r0, _080B4C9C
	ldr r0, [r0]
	cmp r6, r0
	bcc _080B4C8E
	ldr r0, _080B4CA0
	ldr r1, [r0]
	mov r0, r9
	bl _malloc_trim_r
_080B4C8E:
	mov r0, r9
	bl nullsub_127
	b _080B4DDA
	.align 2, 0
_080B4C98: .4byte gUnknown_203B7C0
_080B4C9C: .4byte gUnknown_203BBC8
_080B4CA0: .4byte gUnknown_203BBCC
_080B4CA4:
	str r4, [r7, 0x4]
	movs r0, 0
	mov r8, r0
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	bne _080B4CD0
	ldr r0, [r5]
	subs r5, r0
	adds r6, r0
	ldr r1, [r5, 0x8]
	mov r0, r12
	adds r0, 0x8
	cmp r1, r0
	bne _080B4CC8
	movs r2, 0x1
	mov r8, r2
	b _080B4CD0
_080B4CC8:
	ldr r3, [r5, 0xC]
	adds r2, r1, 0
	str r3, [r2, 0xC]
	str r2, [r3, 0x8]
_080B4CD0:
	adds r0, r7, r4
	ldr r0, [r0, 0x4]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080B4D08
	adds r6, r4
	ldr r1, [r7, 0x8]
	mov r0, r8
	cmp r0, 0
	bne _080B4D00
	ldr r0, _080B4CFC
	cmp r1, r0
	bne _080B4D00
	movs r2, 0x1
	mov r8, r2
	str r5, [r1, 0xC]
	str r5, [r1, 0x8]
	str r1, [r5, 0xC]
	str r1, [r5, 0x8]
	b _080B4D08
	.align 2, 0
_080B4CFC: .4byte gUnknown_203B7C8
_080B4D00:
	ldr r3, [r7, 0xC]
	adds r2, r1, 0
	str r3, [r2, 0xC]
	str r2, [r3, 0x8]
_080B4D08:
	movs r1, 0x1
	adds r0, r6, 0
	orrs r0, r1
	str r0, [r5, 0x4]
	adds r0, r5, r6
	str r6, [r0]
	mov r0, r8
	cmp r0, 0
	bne _080B4DD4
	ldr r0, _080B4D38
	cmp r6, r0
	bhi _080B4D40
	lsrs r4, r6, 3
	ldr r2, _080B4D3C
	adds r0, r4, 0
	asrs r0, 2
	lsls r1, r0
	ldr r0, [r2, 0x4]
	orrs r0, r1
	str r0, [r2, 0x4]
	lsls r0, r4, 3
	adds r3, r0, r2
	ldr r2, [r3, 0x8]
	b _080B4DCC
	.align 2, 0
_080B4D38: .4byte 0x000001ff
_080B4D3C: .4byte gUnknown_203B7C0
_080B4D40:
	lsrs r1, r6, 9
	cmp r1, 0
	bne _080B4D4A
	lsrs r4, r6, 3
	b _080B4D92
_080B4D4A:
	cmp r1, 0x4
	bhi _080B4D56
	lsrs r0, r6, 6
	adds r4, r0, 0
	adds r4, 0x38
	b _080B4D92
_080B4D56:
	cmp r1, 0x14
	bhi _080B4D60
	adds r4, r1, 0
	adds r4, 0x5B
	b _080B4D92
_080B4D60:
	cmp r1, 0x54
	bhi _080B4D6C
	lsrs r0, r6, 12
	adds r4, r0, 0
	adds r4, 0x6E
	b _080B4D92
_080B4D6C:
	movs r0, 0xAA
	lsls r0, 1
	cmp r1, r0
	bhi _080B4D7C
	lsrs r0, r6, 15
	adds r4, r0, 0
	adds r4, 0x77
	b _080B4D92
_080B4D7C:
	ldr r0, _080B4D8C
	cmp r1, r0
	bhi _080B4D90
	lsrs r0, r6, 18
	adds r4, r0, 0
	adds r4, 0x7C
	b _080B4D92
	.align 2, 0
_080B4D8C: .4byte 0x00000554
_080B4D90:
	movs r4, 0x7E
_080B4D92:
	lsls r0, r4, 3
	ldr r7, _080B4DB0
	adds r3, r0, r7
	ldr r2, [r3, 0x8]
	cmp r2, r3
	bne _080B4DB4
	adds r0, r4, 0
	asrs r0, 2
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r7, 0x4]
	orrs r0, r1
	str r0, [r7, 0x4]
	b _080B4DCC
	.align 2, 0
_080B4DB0: .4byte gUnknown_203B7C0
_080B4DB4:
	ldr r0, [r2, 0x4]
	movs r1, 0x4
	negs r1, r1
	b _080B4DC4
_080B4DBC:
	ldr r2, [r2, 0x8]
	cmp r2, r3
	beq _080B4DCA
	ldr r0, [r2, 0x4]
_080B4DC4:
	ands r0, r1
	cmp r6, r0
	bcc _080B4DBC
_080B4DCA:
	ldr r3, [r2, 0xC]
_080B4DCC:
	str r3, [r5, 0xC]
	str r2, [r5, 0x8]
	str r5, [r3, 0x8]
	str r5, [r2, 0xC]
_080B4DD4:
	mov r0, r9
	bl nullsub_127
_080B4DDA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7,pc}
	thumb_func_end _free_r

	thumb_func_start _malloc_trim_r
_malloc_trim_r:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r4, r1, 0
	bl __malloc_lock
	ldr r0, _080B4E6C
	mov r8, r0
	ldr r0, [r0, 0x8]
	ldr r6, [r0, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r6, r0
	subs r4, r6, r4
	movs r5, 0x80
	lsls r5, 5
	ldr r1, _080B4E70
	adds r4, r1
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80B688C
	subs r0, 0x1
	lsls r4, r0, 12
	cmp r4, r5
	blt _080B4E62
	adds r0, r7, 0
	movs r1, 0
	bl _sbrk_r
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1, 0x8]
	adds r0, r6
	cmp r2, r0
	bne _080B4E62
	negs r1, r4
	adds r0, r7, 0
	bl _sbrk_r
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _080B4E7C
	adds r0, r7, 0
	movs r1, 0
	bl _sbrk_r
	adds r2, r0, 0
	mov r0, r8
	ldr r3, [r0, 0x8]
	subs r6, r2, r3
	cmp r6, 0xF
	ble _080B4E62
	ldr r1, _080B4E74
	ldr r0, _080B4E78
	ldr r0, [r0]
	subs r0, r2, r0
	str r0, [r1]
	movs r0, 0x1
	orrs r6, r0
	str r6, [r3, 0x4]
_080B4E62:
	adds r0, r7, 0
	bl nullsub_127
	movs r0, 0
	b _080B4E98
	.align 2, 0
_080B4E6C: .4byte gUnknown_203B7C0
_080B4E70: .4byte 0x00000fef
_080B4E74: .4byte gUnknown_203BBDC
_080B4E78: .4byte gUnknown_203BBD0
_080B4E7C:
	mov r1, r8
	ldr r2, [r1, 0x8]
	subs r0, r6, r4
	movs r1, 0x1
	orrs r0, r1
	str r0, [r2, 0x4]
	ldr r1, _080B4EA0
	ldr r0, [r1]
	subs r0, r4
	str r0, [r1]
	adds r0, r7, 0
	bl nullsub_127
	movs r0, 0x1
_080B4E98:
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	.align 2, 0
_080B4EA0: .4byte gUnknown_203BBDC
	thumb_func_end _malloc_trim_r

	thumb_func_start sub_80B4EA4
sub_80B4EA4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	mov r10, r1
	ldr r6, [r1, 0x8]
	cmp r6, 0
	bne _080B4EBC
	b _080B50B2
_080B4EBC:
	movs r0, 0x8
	ldrh r1, [r5, 0xC]
	ands r0, r1
	cmp r0, 0
	beq _080B4ECC
	ldr r0, [r5, 0x10]
	cmp r0, 0
	bne _080B4ED8
_080B4ECC:
	adds r0, r5, 0
	bl sub_80B3B34
	cmp r0, 0
	beq _080B4ED8
	b _080B50BE
_080B4ED8:
	mov r2, r10
	ldr r2, [r2]
	mov r8, r2
	movs r6, 0
	ldrh r1, [r5, 0xC]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080B4F2C
_080B4EEA:
	ldr r0, [r5, 0x1C]
	ldr r3, [r5, 0x24]
	cmp r6, 0
	bne _080B4F00
_080B4EF2:
	mov r1, r8
	ldr r7, [r1]
	ldr r6, [r1, 0x4]
	movs r2, 0x8
	add r8, r2
	cmp r6, 0
	beq _080B4EF2
_080B4F00:
	adds r2, r6, 0
	movs r1, 0x80
	lsls r1, 3
	cmp r6, r1
	bls _080B4F0C
	adds r2, r1, 0
_080B4F0C:
	adds r1, r7, 0
	bl _call_via_r3
	adds r4, r0, 0
	cmp r4, 0
	bgt _080B4F1A
	b _080B50B6
_080B4F1A:
	adds r7, r4
	subs r6, r4
	mov r1, r10
	ldr r0, [r1, 0x8]
	subs r0, r4
	str r0, [r1, 0x8]
	cmp r0, 0
	bne _080B4EEA
	b _080B50B2
_080B4F2C:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080B4FE6
_080B4F34:
	ldrh r1, [r5, 0xC]
	ldr r0, [r5, 0x8]
	ldr r3, [r5]
	cmp r6, 0
	bne _080B4F4C
_080B4F3E:
	mov r2, r8
	ldr r7, [r2]
	ldr r6, [r2, 0x4]
	movs r2, 0x8
	add r8, r2
	cmp r6, 0
	beq _080B4F3E
_080B4F4C:
	adds r4, r0, 0
	movs r2, 0x80
	lsls r2, 2
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _080B4F7A
	cmp r6, r4
	bcs _080B4F60
	adds r4, r6, 0
_080B4F60:
	adds r0, r3, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80B5820
	ldr r0, [r5, 0x8]
	subs r0, r4
	str r0, [r5, 0x8]
	ldr r0, [r5]
	adds r0, r4
	str r0, [r5]
	adds r4, r6, 0
	b _080B4FD4
_080B4F7A:
	ldr r0, [r5, 0x10]
	cmp r3, r0
	bls _080B4FA2
	cmp r6, r4
	bls _080B4FA2
	adds r0, r3, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80B5820
	ldr r0, [r5]
	adds r0, r4
	str r0, [r5]
	adds r0, r5, 0
	bl sub_80B4A34
	cmp r0, 0
	beq _080B4FA0
	b _080B50B6
_080B4FA0:
	b _080B4FD4
_080B4FA2:
	ldr r4, [r5, 0x14]
	cmp r6, r4
	bcc _080B4FBC
	ldr r0, [r5, 0x1C]
	ldr r3, [r5, 0x24]
	adds r1, r7, 0
	adds r2, r4, 0
	bl _call_via_r3
	adds r4, r0, 0
	cmp r4, 0
	ble _080B50B6
	b _080B4FD4
_080B4FBC:
	adds r4, r6, 0
	adds r0, r3, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80B5820
	ldr r0, [r5, 0x8]
	subs r0, r4
	str r0, [r5, 0x8]
	ldr r0, [r5]
	adds r0, r4
	str r0, [r5]
_080B4FD4:
	adds r7, r4
	subs r6, r4
	mov r1, r10
	ldr r0, [r1, 0x8]
	subs r0, r4
	str r0, [r1, 0x8]
	cmp r0, 0
	bne _080B4F34
	b _080B50B2
_080B4FE6:
	movs r2, 0
	str r2, [sp]
_080B4FEA:
	cmp r6, 0
	bne _080B5000
	movs r0, 0
	str r0, [sp]
_080B4FF2:
	mov r1, r8
	ldr r7, [r1]
	ldr r6, [r1, 0x4]
	movs r2, 0x8
	add r8, r2
	cmp r6, 0
	beq _080B4FF2
_080B5000:
	ldr r0, [sp]
	cmp r0, 0
	bne _080B5024
	adds r0, r7, 0
	movs r1, 0xA
	adds r2, r6, 0
	bl sub_80B57A0
	adds r1, r0, 0
	cmp r1, 0
	beq _080B501C
	subs r0, r7, 0x1
	subs r1, r0
	b _080B501E
_080B501C:
	adds r1, r6, 0x1
_080B501E:
	mov r9, r1
	movs r2, 0x1
	str r2, [sp]
_080B5024:
	mov r2, r9
	cmp r9, r6
	bls _080B502C
	adds r2, r6, 0
_080B502C:
	ldr r0, [r5, 0x8]
	ldr r1, [r5, 0x14]
	adds r4, r0, r1
	ldr r0, [r5, 0x10]
	ldr r3, [r5]
	cmp r3, r0
	bls _080B505A
	cmp r2, r4
	ble _080B505A
	adds r0, r3, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80B5820
	ldr r0, [r5]
	adds r0, r4
	str r0, [r5]
	adds r0, r5, 0
	bl sub_80B4A34
	cmp r0, 0
	bne _080B50B6
	b _080B508A
_080B505A:
	adds r4, r1, 0
	cmp r2, r4
	blt _080B5074
	ldr r0, [r5, 0x1C]
	ldr r3, [r5, 0x24]
	adds r1, r7, 0
	adds r2, r4, 0
	bl _call_via_r3
	adds r4, r0, 0
	cmp r4, 0
	ble _080B50B6
	b _080B508A
_080B5074:
	adds r4, r2, 0
	adds r0, r3, 0
	adds r1, r7, 0
	bl sub_80B5820
	ldr r0, [r5, 0x8]
	subs r0, r4
	str r0, [r5, 0x8]
	ldr r0, [r5]
	adds r0, r4
	str r0, [r5]
_080B508A:
	mov r0, r9
	subs r0, r4
	mov r9, r0
	cmp r0, 0
	bne _080B50A2
	adds r0, r5, 0
	bl sub_80B4A34
	cmp r0, 0
	bne _080B50B6
	movs r1, 0
	str r1, [sp]
_080B50A2:
	adds r7, r4
	subs r6, r4
	mov r2, r10
	ldr r0, [r2, 0x8]
	subs r0, r4
	str r0, [r2, 0x8]
	cmp r0, 0
	bne _080B4FEA
_080B50B2:
	movs r0, 0
	b _080B50C2
_080B50B6:
	movs r0, 0x40
	ldrh r1, [r5, 0xC]
	orrs r0, r1
	strh r0, [r5, 0xC]
_080B50BE:
	movs r0, 0x1
	negs r0, r0
_080B50C2:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	thumb_func_end sub_80B4EA4

	thumb_func_start sub_80B50D0
sub_80B50D0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	movs r7, 0
	movs r1, 0xEC
	lsls r1, 1
	adds r6, r0, r1
	cmp r6, 0
	beq _080B5108
_080B50E4:
	ldr r5, [r6, 0x8]
	ldr r4, [r6, 0x4]
	b _080B50FC
_080B50EA:
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080B50FA
	adds r0, r5, 0
	bl _call_via_r8
	orrs r7, r0
_080B50FA:
	adds r5, 0x58
_080B50FC:
	subs r4, 0x1
	cmp r4, 0
	bge _080B50EA
	ldr r6, [r6]
	cmp r6, 0
	bne _080B50E4
_080B5108:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	thumb_func_end sub_80B50D0

	thumb_func_start sub_80B5110
sub_80B5110:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	cmp r4, 0
	beq _080B5144
	ldr r1, _080B5138
	adds r0, r4, 0
	bl strcmp
	cmp r0, 0
	beq _080B5140
	ldr r1, _080B513C
	adds r0, r4, 0
	bl strcmp
	cmp r0, 0
	beq _080B5140
	movs r0, 0
	b _080B5146
	.align 2, 0
_080B5138: .4byte gUnknown_826FEB0
_080B513C: .4byte gUnknown_826FEA8
_080B5140:
	str r6, [r5, 0x30]
	str r4, [r5, 0x34]
_080B5144:
	ldr r0, _080B5148
_080B5146:
	pop {r4-r6,pc}
	.align 2, 0
_080B5148: .4byte gUnknown_826FEB0
	thumb_func_end sub_80B5110

	thumb_func_start sub_80B514C
sub_80B514C:
	ldr r0, _080B5150
	bx lr
	.align 2, 0
_080B5150: .4byte gUnknown_826FE78
	thumb_func_end sub_80B514C

	thumb_func_start sub_80B5154
sub_80B5154:
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, _080B5168
	ldr r0, [r0]
	adds r1, r3, 0
	bl sub_80B5110
	pop {pc}
	.align 2, 0
_080B5168: .4byte gUnknown_203B7A8
	thumb_func_end sub_80B5154

	thumb_func_start sub_80B516C
sub_80B516C:
	push {lr}
	ldr r0, _080B5178
	ldr r0, [r0]
	bl sub_80B514C
	pop {pc}
	.align 2, 0
_080B5178: .4byte gUnknown_203B7A8
	thumb_func_end sub_80B516C

	thumb_func_start sub_80B517C
sub_80B517C:
	push {r4-r7,lr}
	sub sp, 0x3C
	adds r4, r0, 0
	movs r0, 0x2
	ldrh r1, [r4, 0xC]
	ands r0, r1
	cmp r0, 0
	bne _080B5212
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _080B51A4
	ldr r0, [r4, 0x54]
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	mov r2, sp
	bl sub_80B67D8
	cmp r0, 0
	bge _080B51B6
_080B51A4:
	movs r7, 0
	movs r6, 0x80
	lsls r6, 3
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1, 0
	ldrh r2, [r4, 0xC]
	orrs r0, r2
	b _080B51FA
_080B51B6:
	movs r7, 0
	ldr r1, [sp, 0x4]
	movs r0, 0xF0
	lsls r0, 8
	ands r1, r0
	movs r0, 0x80
	lsls r0, 6
	cmp r1, r0
	bne _080B51CA
	movs r7, 0x1
_080B51CA:
	movs r6, 0x80
	lsls r6, 3
	movs r0, 0x80
	lsls r0, 8
	cmp r1, r0
	bne _080B51F0
	ldr r1, [r4, 0x28]
	ldr r0, _080B51EC
	cmp r1, r0
	bne _080B51F0
	adds r0, r6, 0
	ldrh r1, [r4, 0xC]
	orrs r0, r1
	strh r0, [r4, 0xC]
	str r6, [r4, 0x4C]
	b _080B51FC
	.align 2, 0
_080B51EC: .4byte sub_80B6264
_080B51F0:
	movs r2, 0x80
	lsls r2, 4
	adds r0, r2, 0
	ldrh r1, [r4, 0xC]
	orrs r0, r1
_080B51FA:
	strh r0, [r4, 0xC]
_080B51FC:
	ldr r0, [r4, 0x54]
	adds r1, r6, 0
	bl sub_80B53B4
	adds r2, r0, 0
	cmp r2, 0
	bne _080B5220
	movs r0, 0x2
	ldrh r2, [r4, 0xC]
	orrs r0, r2
	strh r0, [r4, 0xC]
_080B5212:
	adds r0, r4, 0
	adds r0, 0x43
	str r0, [r4]
	str r0, [r4, 0x10]
	movs r0, 0x1
	str r0, [r4, 0x14]
	b _080B524E
_080B5220:
	ldr r1, [r4, 0x54]
	ldr r0, _080B5254
	str r0, [r1, 0x3C]
	movs r0, 0x80
	movs r5, 0
	ldrh r1, [r4, 0xC]
	orrs r0, r1
	strh r0, [r4, 0xC]
	str r2, [r4]
	str r2, [r4, 0x10]
	str r6, [r4, 0x14]
	cmp r7, 0
	beq _080B524E
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	bl isatty
	cmp r0, 0
	beq _080B524E
	movs r0, 0x1
	ldrh r1, [r4, 0xC]
	orrs r0, r1
	strh r0, [r4, 0xC]
_080B524E:
	add sp, 0x3C
	pop {r4-r7,pc}
	.align 2, 0
_080B5254: .4byte sub_80B4BA4
	thumb_func_end sub_80B517C

	thumb_func_start sub_80B5258
sub_80B5258:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	str r0, [sp]
	ldr r0, _080B52CC
	ldr r0, [r0, 0x8]
	mov r8, r0
	ldr r7, [r0, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r7, r0
	mov r2, r8
	adds r4, r2, r7
	ldr r0, _080B52D0
	ldr r0, [r0]
	adds r1, r0
	adds r6, r1, 0
	adds r6, 0x10
	ldr r3, _080B52D4
	mov r10, r3
	ldr r0, [r3]
	movs r2, 0x1
	negs r2, r2
	mov r9, r2
	cmp r0, r9
	beq _080B529A
	ldr r3, _080B52D8
	adds r6, r1, r3
	ldr r0, _080B52DC
	ands r6, r0
_080B529A:
	ldr r0, [sp]
	adds r1, r6, 0
	bl _sbrk_r
	adds r5, r0, 0
	cmp r5, r9
	beq _080B539C
	cmp r5, r4
	bcs _080B52B2
	ldr r0, _080B52CC
	cmp r8, r0
	bne _080B539C
_080B52B2:
	ldr r1, _080B52E0
	ldr r0, [r1]
	adds r2, r0, r6
	str r2, [r1]
	cmp r5, r4
	bne _080B52E4
	adds r2, r6, r7
	ldr r3, _080B52CC
	ldr r1, [r3, 0x8]
	movs r0, 0x1
	orrs r2, r0
	str r2, [r1, 0x4]
	b _080B5384
	.align 2, 0
_080B52CC: .4byte gUnknown_203B7C0
_080B52D0: .4byte gUnknown_203BBCC
_080B52D4: .4byte gUnknown_203BBD0
_080B52D8: .4byte 0x0000100f
_080B52DC: .4byte 0xfffff000
_080B52E0: .4byte gUnknown_203BBDC
_080B52E4:
	mov r3, r10
	ldr r0, [r3]
	cmp r0, r9
	bne _080B52F0
	str r5, [r3]
	b _080B52F6
_080B52F0:
	subs r0, r5, r4
	adds r0, r2, r0
	str r0, [r1]
_080B52F6:
	adds r1, r5, 0
	adds r1, 0x8
	movs r0, 0x7
	ands r1, r0
	cmp r1, 0
	beq _080B530A
	movs r0, 0x8
	subs r4, r0, r1
	adds r5, r4
	b _080B530C
_080B530A:
	movs r4, 0
_080B530C:
	adds r0, r5, r6
	movs r1, 0x80
	lsls r1, 5
	subs r1, 0x1
	ands r0, r1
	movs r1, 0x80
	lsls r1, 5
	subs r0, r1, r0
	adds r4, r0
	ldr r0, [sp]
	adds r1, r4, 0
	bl _sbrk_r
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080B539C
	ldr r1, _080B5354
	ldr r0, [r1]
	adds r0, r4
	str r0, [r1]
	ldr r1, _080B5358
	str r5, [r1, 0x8]
	subs r0, r2, r5
	adds r2, r0, r4
	movs r3, 0x1
	orrs r2, r3
	str r2, [r5, 0x4]
	cmp r8, r1
	beq _080B5384
	cmp r7, 0xF
	bhi _080B535C
	str r3, [r5, 0x4]
	b _080B539C
	.align 2, 0
_080B5354: .4byte gUnknown_203BBDC
_080B5358: .4byte gUnknown_203B7C0
_080B535C:
	subs r7, 0xC
	movs r0, 0x8
	negs r0, r0
	ands r7, r0
	mov r2, r8
	ldr r0, [r2, 0x4]
	ands r0, r3
	orrs r0, r7
	str r0, [r2, 0x4]
	adds r1, r2, r7
	movs r0, 0x5
	str r0, [r1, 0x4]
	str r0, [r1, 0x8]
	cmp r7, 0xF
	bls _080B5384
	mov r1, r8
	adds r1, 0x8
	ldr r0, [sp]
	bl _free_r
_080B5384:
	ldr r0, _080B53A8
	ldr r2, _080B53AC
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r1, r0
	bls _080B5392
	str r1, [r2]
_080B5392:
	ldr r2, _080B53B0
	ldr r0, [r2]
	cmp r1, r0
	bls _080B539C
	str r1, [r2]
_080B539C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_080B53A8: .4byte gUnknown_203BBDC
_080B53AC: .4byte gUnknown_203BBD4
_080B53B0: .4byte gUnknown_203BBD8
	thumb_func_end sub_80B5258

	thumb_func_start sub_80B53B4
sub_80B53B4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r0, [sp]
	adds r1, 0xB
	cmp r1, 0x16
	ble _080B53D6
	movs r0, 0x8
	negs r0, r0
	mov r8, r0
	mov r2, r8
	ands r2, r1
	mov r8, r2
	b _080B53DA
_080B53D6:
	movs r3, 0x10
	mov r8, r3
_080B53DA:
	ldr r0, [sp]
	bl __malloc_lock
	ldr r0, _080B5420
	cmp r8, r0
	bhi _080B542E
	mov r4, r8
	lsrs r4, 3
	mov r12, r4
	ldr r0, _080B5424
	mov r7, r8
	adds r2, r7, r0
	ldr r5, [r2, 0xC]
	cmp r5, r2
	bne _080B5402
	adds r2, r5, 0
	adds r2, 0x8
	ldr r5, [r2, 0xC]
	cmp r5, r2
	beq _080B5428
_080B5402:
	ldr r2, [r5, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r2, r0
	ldr r6, [r5, 0xC]
	ldr r4, [r5, 0x8]
	str r6, [r4, 0xC]
	str r4, [r6, 0x8]
	adds r2, r5, r2
	ldr r0, [r2, 0x4]
	movs r1, 0x1
	orrs r0, r1
	str r0, [r2, 0x4]
	b _080B575A
	.align 2, 0
_080B5420: .4byte 0x000001f7
_080B5424: .4byte gUnknown_203B7C0
_080B5428:
	movs r0, 0x2
	add r12, r0
	b _080B54DA
_080B542E:
	mov r2, r8
	lsrs r1, r2, 9
	cmp r1, 0
	bne _080B543A
	lsrs r2, 3
	b _080B548A
_080B543A:
	cmp r1, 0x4
	bhi _080B5448
	mov r3, r8
	lsrs r0, r3, 6
	adds r0, 0x38
	mov r12, r0
	b _080B548C
_080B5448:
	cmp r1, 0x14
	bhi _080B5452
	adds r1, 0x5B
	mov r12, r1
	b _080B548C
_080B5452:
	cmp r1, 0x54
	bhi _080B5460
	mov r4, r8
	lsrs r0, r4, 12
	adds r0, 0x6E
	mov r12, r0
	b _080B548C
_080B5460:
	movs r0, 0xAA
	lsls r0, 1
	cmp r1, r0
	bhi _080B5472
	mov r7, r8
	lsrs r0, r7, 15
	adds r0, 0x77
	mov r12, r0
	b _080B548C
_080B5472:
	ldr r0, _080B5484
	cmp r1, r0
	bhi _080B5488
	mov r1, r8
	lsrs r0, r1, 18
	adds r0, 0x7C
	mov r12, r0
	b _080B548C
	.align 2, 0
_080B5484: .4byte 0x00000554
_080B5488:
	movs r2, 0x7E
_080B548A:
	mov r12, r2
_080B548C:
	mov r3, r12
	lsls r0, r3, 3
	ldr r1, _080B54B0
	adds r4, r0, r1
	ldr r5, [r4, 0xC]
	cmp r5, r4
	beq _080B54D6
	ldr r1, [r5, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, 0xF
	ble _080B54B4
	adds r0, 0x3
	add r12, r0
	b _080B54D6
	.align 2, 0
_080B54B0: .4byte gUnknown_203B7C0
_080B54B4:
	cmp r3, 0
	blt _080B54BA
	b _080B56F4
_080B54BA:
	ldr r5, [r5, 0xC]
	cmp r5, r4
	beq _080B54D6
	ldr r1, [r5, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r1, r0
	mov r2, r8
	subs r3, r1, r2
	cmp r3, 0xF
	ble _080B54B4
	movs r3, 0x1
	negs r3, r3
	add r12, r3
_080B54D6:
	movs r4, 0x1
	add r12, r4
_080B54DA:
	ldr r0, _080B5518
	ldr r5, [r0, 0x8]
	mov r10, r0
	cmp r5, r10
	bne _080B54E6
	b _080B55E8
_080B54E6:
	ldr r1, [r5, 0x4]
	movs r0, 0x4
	negs r0, r0
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, 0xF
	ble _080B551C
	adds r2, r5, r7
	movs r1, 0x1
	adds r0, r7, 0
	orrs r0, r1
	str r0, [r5, 0x4]
	mov r4, r10
	str r2, [r4, 0xC]
	str r2, [r4, 0x8]
	str r4, [r2, 0xC]
	str r4, [r2, 0x8]
	adds r0, r3, 0
	orrs r0, r1
	str r0, [r2, 0x4]
	adds r0, r2, r3
	str r3, [r0]
	b _080B575A
	.align 2, 0
_080B5518: .4byte gUnknown_203B7C8
_080B551C:
	mov r7, r10
	str r7, [r7, 0xC]
	str r7, [r7, 0x8]
	cmp r3, 0
	blt _080B5532
	adds r2, r5, r1
	ldr r0, [r2, 0x4]
	movs r1, 0x1
	orrs r0, r1
	str r0, [r2, 0x4]
	b _080B575A
_080B5532:
	ldr r0, _080B5554
	cmp r1, r0
	bhi _080B5558
	lsrs r2, r1, 3
	mov r3, r10
	subs r3, 0x8
	adds r0, r2, 0
	asrs r0, 2
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r3, 0x4]
	orrs r0, r1
	str r0, [r3, 0x4]
	lsls r0, r2, 3
	adds r6, r0, r3
	ldr r4, [r6, 0x8]
	b _080B55E0
	.align 2, 0
_080B5554: .4byte 0x000001ff
_080B5558:
	lsrs r2, r1, 9
	cmp r2, 0
	bne _080B5562
	lsrs r2, r1, 3
	b _080B55A6
_080B5562:
	cmp r2, 0x4
	bhi _080B556E
	lsrs r0, r1, 6
	adds r2, r0, 0
	adds r2, 0x38
	b _080B55A6
_080B556E:
	cmp r2, 0x14
	bhi _080B5576
	adds r2, 0x5B
	b _080B55A6
_080B5576:
	cmp r2, 0x54
	bhi _080B5582
	lsrs r0, r1, 12
	adds r2, r0, 0
	adds r2, 0x6E
	b _080B55A6
_080B5582:
	movs r0, 0xAA
	lsls r0, 1
	cmp r2, r0
	bhi _080B5592
	lsrs r0, r1, 15
	adds r2, r0, 0
	adds r2, 0x77
	b _080B55A6
_080B5592:
	ldr r0, _080B55A0
	cmp r2, r0
	bhi _080B55A4
	lsrs r0, r1, 18
	adds r2, r0, 0
	adds r2, 0x7C
	b _080B55A6
	.align 2, 0
_080B55A0: .4byte 0x00000554
_080B55A4:
	movs r2, 0x7E
_080B55A6:
	lsls r0, r2, 3
	ldr r3, _080B55C4
	adds r6, r0, r3
	ldr r4, [r6, 0x8]
	cmp r4, r6
	bne _080B55C8
	adds r0, r2, 0
	asrs r0, 2
	movs r1, 0x1
	lsls r1, r0
	ldr r7, _080B55C4
	ldr r0, [r7, 0x4]
	orrs r0, r1
	str r0, [r7, 0x4]
	b _080B55E0
	.align 2, 0
_080B55C4: .4byte gUnknown_203B7C0
_080B55C8:
	ldr r0, [r4, 0x4]
	movs r2, 0x4
	negs r2, r2
	b _080B55D8
_080B55D0:
	ldr r4, [r4, 0x8]
	cmp r4, r6
	beq _080B55DE
	ldr r0, [r4, 0x4]
_080B55D8:
	ands r0, r2
	cmp r1, r0
	bcc _080B55D0
_080B55DE:
	ldr r6, [r4, 0xC]
_080B55E0:
	str r6, [r5, 0xC]
	str r4, [r5, 0x8]
	str r5, [r6, 0x8]
	str r5, [r4, 0xC]
_080B55E8:
	mov r0, r12
	cmp r0, 0
	bge _080B55F0
	adds r0, 0x3
_080B55F0:
	asrs r0, 2
	movs r6, 0x1
	lsls r6, r0
	ldr r0, _080B5614
	ldr r1, [r0, 0x4]
	cmp r6, r1
	bhi _080B56B2
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _080B5626
	movs r0, 0x4
	negs r0, r0
	mov r2, r12
	ands r0, r2
	adds r0, 0x4
	mov r12, r0
	b _080B561C
	.align 2, 0
_080B5614: .4byte gUnknown_203B7C0
_080B5618:
	movs r3, 0x4
	add r12, r3
_080B561C:
	lsls r6, 1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080B5618
_080B5626:
	ldr r4, _080B56A4
	mov r9, r4
_080B562A:
	mov r7, r12
	str r7, [sp, 0x4]
	mov r1, r12
	lsls r0, r1, 3
	mov r3, r9
	adds r2, r0, r3
	adds r4, r2, 0
_080B5638:
	ldr r5, [r4, 0xC]
	cmp r5, r4
	beq _080B5658
	movs r0, 0x4
	negs r0, r0
_080B5642:
	ldr r1, [r5, 0x4]
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, 0xF
	bgt _080B5708
	cmp r3, 0
	bge _080B5730
	ldr r5, [r5, 0xC]
	cmp r5, r4
	bne _080B5642
_080B5658:
	adds r4, 0x8
	movs r0, 0x1
	add r12, r0
	mov r0, r12
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B5638
_080B5668:
	ldr r0, [sp, 0x4]
	ands r0, r1
	cmp r0, 0
	beq _080B56A8
	ldr r3, [sp, 0x4]
	subs r3, 0x1
	str r3, [sp, 0x4]
	subs r2, 0x8
	ldr r0, [r2, 0x8]
	cmp r0, r2
	beq _080B5668
_080B567E:
	lsls r6, 1
	mov r4, r9
	ldr r1, [r4, 0x4]
	cmp r6, r1
	bhi _080B56B2
	cmp r6, 0
	beq _080B56B2
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _080B562A
_080B5694:
	movs r7, 0x4
	add r12, r7
	lsls r6, 1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080B5694
	b _080B562A
	.align 2, 0
_080B56A4: .4byte gUnknown_203B7C0
_080B56A8:
	mov r1, r9
	ldr r0, [r1, 0x4]
	bics r0, r6
	str r0, [r1, 0x4]
	b _080B567E
_080B56B2:
	ldr r2, _080B56F0
	ldr r0, [r2, 0x8]
	ldr r0, [r0, 0x4]
	movs r4, 0x4
	negs r4, r4
	ands r0, r4
	mov r7, r8
	subs r3, r0, r7
	cmp r0, r8
	bcc _080B56CA
	cmp r3, 0xF
	bgt _080B5744
_080B56CA:
	ldr r0, [sp]
	mov r1, r8
	bl sub_80B5258
	ldr r1, _080B56F0
	ldr r0, [r1, 0x8]
	ldr r0, [r0, 0x4]
	ands r0, r4
	mov r2, r8
	subs r3, r0, r2
	cmp r0, r8
	bcc _080B56E6
	cmp r3, 0xF
	bgt _080B5744
_080B56E6:
	ldr r0, [sp]
	bl nullsub_127
	movs r0, 0
	b _080B5764
	.align 2, 0
_080B56F0: .4byte gUnknown_203B7C0
_080B56F4:
	ldr r6, [r5, 0xC]
	ldr r4, [r5, 0x8]
	str r6, [r4, 0xC]
	str r4, [r6, 0x8]
	adds r2, r5, r1
	ldr r0, [r2, 0x4]
	movs r1, 0x1
	orrs r0, r1
	str r0, [r2, 0x4]
	b _080B575A
_080B5708:
	mov r4, r8
	adds r2, r5, r4
	movs r1, 0x1
	orrs r4, r1
	str r4, [r5, 0x4]
	ldr r6, [r5, 0xC]
	ldr r4, [r5, 0x8]
	str r6, [r4, 0xC]
	str r4, [r6, 0x8]
	mov r7, r10
	str r2, [r7, 0xC]
	str r2, [r7, 0x8]
	str r7, [r2, 0xC]
	str r7, [r2, 0x8]
	adds r0, r3, 0
	orrs r0, r1
	str r0, [r2, 0x4]
	adds r0, r2, r3
	str r3, [r0]
	b _080B575A
_080B5730:
	adds r2, r5, r1
	ldr r0, [r2, 0x4]
	movs r1, 0x1
	orrs r0, r1
	str r0, [r2, 0x4]
	ldr r6, [r5, 0xC]
	ldr r4, [r5, 0x8]
	str r6, [r4, 0xC]
	str r4, [r6, 0x8]
	b _080B575A
_080B5744:
	ldr r2, _080B5770
	ldr r5, [r2, 0x8]
	movs r1, 0x1
	mov r0, r8
	orrs r0, r1
	str r0, [r5, 0x4]
	mov r4, r8
	adds r0, r5, r4
	str r0, [r2, 0x8]
	orrs r3, r1
	str r3, [r0, 0x4]
_080B575A:
	ldr r0, [sp]
	bl nullsub_127
	adds r0, r5, 0
	adds r0, 0x8
_080B5764:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_080B5770: .4byte gUnknown_203B7C0
	thumb_func_end sub_80B53B4

	thumb_func_start sub_80B5774
sub_80B5774:
	sub sp, 0x4
	cmp r1, 0
	bne _080B577C
	mov r1, sp
_080B577C:
	cmp r2, 0
	beq _080B5798
	cmp r3, 0
	bne _080B578A
	movs r0, 0x1
	negs r0, r0
	b _080B579A
_080B578A:
	ldrb r0, [r2]
	str r0, [r1]
	ldrb r0, [r2]
	cmp r0, 0
	beq _080B5798
	movs r0, 0x1
	b _080B579A
_080B5798:
	movs r0, 0
_080B579A:
	add sp, 0x4
	bx lr
	thumb_func_end sub_80B5774

	thumb_func_start sub_80B57A0
sub_80B57A0:
	push {r4-r7,lr}
	adds r5, r1, 0
	adds r1, r0, 0
	movs r0, 0xFF
	ands r5, r0
	cmp r2, 0x3
	bls _080B5814
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B5814
	adds r4, r1, 0
	movs r6, 0
	movs r1, 0
_080B57BC:
	lsls r0, r6, 8
	adds r6, r0, r5
	adds r1, 0x1
	cmp r1, 0x3
	bls _080B57BC
	cmp r2, 0x3
	bls _080B57FA
	ldr r0, _080B5800
	mov r12, r0
	ldr r7, _080B5804
_080B57D0:
	ldr r1, [r4]
	eors r1, r6
	mov r3, r12
	adds r0, r1, r3
	bics r0, r1
	ands r0, r7
	cmp r0, 0
	beq _080B57F2
	adds r1, r4, 0
	movs r3, 0
_080B57E4:
	ldrb r0, [r1]
	cmp r0, r5
	beq _080B580E
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x3
	bls _080B57E4
_080B57F2:
	subs r2, 0x4
	adds r4, 0x4
	cmp r2, 0x3
	bhi _080B57D0
_080B57FA:
	adds r1, r4, 0
	b _080B5814
	.align 2, 0
_080B5800: .4byte 0xfefefeff
_080B5804: .4byte 0x80808080
_080B5808:
	ldrb r0, [r1]
	cmp r0, r5
	bne _080B5812
_080B580E:
	adds r0, r1, 0
	b _080B581E
_080B5812:
	adds r1, 0x1
_080B5814:
	adds r0, r2, 0
	subs r2, 0x1
	cmp r0, 0
	bne _080B5808
	movs r0, 0
_080B581E:
	pop {r4-r7,pc}
	thumb_func_end sub_80B57A0

	thumb_func_start sub_80B5820
sub_80B5820:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r3, r1, 0
	cmp r3, r5
	bcs _080B5852
	adds r0, r3, r2
	cmp r5, r0
	bcs _080B5852
	adds r3, r0, 0
	adds r4, r5, r2
	subs r2, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080B58A4
	adds r1, r0, 0
_080B5842:
	subs r4, 0x1
	subs r3, 0x1
	ldrb r0, [r3]
	strb r0, [r4]
	subs r2, 0x1
	cmp r2, r1
	bne _080B5842
	b _080B58A4
_080B5852:
	cmp r2, 0xF
	bls _080B588A
	adds r0, r3, 0
	orrs r0, r4
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B588A
	adds r1, r3, 0
_080B5864:
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	subs r2, 0x10
	cmp r2, 0xF
	bhi _080B5864
	cmp r2, 0x3
	bls _080B5888
_080B587E:
	ldm r1!, {r0}
	stm r4!, {r0}
	subs r2, 0x4
	cmp r2, 0x3
	bhi _080B587E
_080B5888:
	adds r3, r1, 0
_080B588A:
	subs r2, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _080B58A4
	adds r1, r0, 0
_080B5896:
	ldrb r0, [r3]
	strb r0, [r4]
	adds r3, 0x1
	adds r4, 0x1
	subs r2, 0x1
	cmp r2, r1
	bne _080B5896
_080B58A4:
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end sub_80B5820

	thumb_func_start __malloc_lock
__malloc_lock:
	bx lr
	thumb_func_end __malloc_lock

	thumb_func_start nullsub_127
nullsub_127:
	bx lr
	thumb_func_end nullsub_127

	thumb_func_start sub_80B58B0
sub_80B58B0:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [r4, 0x4C]
	cmp r0, 0
	bne _080B58CC
	adds r0, r4, 0
	movs r1, 0x4
	movs r2, 0x10
	bl sub_80B6748
	str r0, [r4, 0x4C]
	cmp r0, 0
	beq _080B58F4
_080B58CC:
	ldr r1, [r4, 0x4C]
	lsls r0, r6, 2
	adds r2, r0, r1
	ldr r1, [r2]
	cmp r1, 0
	beq _080B58DE
	ldr r0, [r1]
	str r0, [r2]
	b _080B58FC
_080B58DE:
	movs r5, 0x1
	lsls r5, r6
	lsls r2, r5, 2
	adds r2, 0x14
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80B6748
	adds r1, r0, 0
	cmp r1, 0
	bne _080B58F8
_080B58F4:
	movs r0, 0
	b _080B5904
_080B58F8:
	str r6, [r1, 0x4]
	str r5, [r1, 0x8]
_080B58FC:
	movs r0, 0
	str r0, [r1, 0x10]
	str r0, [r1, 0xC]
	adds r0, r1, 0
_080B5904:
	pop {r4-r6,pc}
	thumb_func_end sub_80B58B0

	thumb_func_start sub_80B5908
sub_80B5908:
	adds r3, r0, 0
	adds r2, r1, 0
	cmp r2, 0
	beq _080B591E
	ldr r0, [r2, 0x4]
	ldr r1, [r3, 0x4C]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	str r1, [r2]
	str r2, [r0]
_080B591E:
	bx lr
	thumb_func_end sub_80B5908

	thumb_func_start sub_80B5920
sub_80B5920:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	adds r5, r1, 0
	adds r4, r2, 0
	mov r8, r3
	ldr r6, [r5, 0x10]
	adds r3, r5, 0
	adds r3, 0x14
	movs r7, 0
	ldr r0, _080B59B4
	mov r12, r0
_080B593C:
	ldr r1, [r3]
	adds r0, r1, 0
	mov r2, r12
	ands r0, r2
	adds r2, r0, 0
	muls r2, r4
	add r2, r8
	lsrs r1, 16
	adds r0, r1, 0
	muls r0, r4
	lsrs r1, r2, 16
	adds r0, r1
	lsrs r1, r0, 16
	mov r8, r1
	lsls r0, 16
	mov r1, r12
	ands r2, r1
	adds r0, r2
	stm r3!, {r0}
	adds r7, 0x1
	cmp r7, r6
	blt _080B593C
	mov r2, r8
	cmp r2, 0
	beq _080B59AA
	ldr r0, [r5, 0x8]
	cmp r6, r0
	blt _080B599A
	ldr r1, [r5, 0x4]
	adds r1, 0x1
	mov r0, r9
	bl sub_80B58B0
	adds r4, r0, 0
	adds r0, 0xC
	adds r1, r5, 0
	adds r1, 0xC
	ldr r2, [r5, 0x10]
	lsls r2, 2
	adds r2, 0x8
	bl memcpy
	mov r0, r9
	adds r1, r5, 0
	bl sub_80B5908
	adds r5, r4, 0
_080B599A:
	lsls r1, r6, 2
	adds r0, r5, 0
	adds r0, 0x14
	adds r0, r1
	mov r1, r8
	str r1, [r0]
	adds r6, 0x1
	str r6, [r5, 0x10]
_080B59AA:
	adds r0, r5, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7,pc}
	.align 2, 0
_080B59B4: .4byte 0x0000ffff
	thumb_func_end sub_80B5920

	thumb_func_start sub_80B59B8
sub_80B59B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	mov r8, r3
	mov r0, r8
	adds r0, 0x8
	movs r1, 0x9
	bl __divsi3
	movs r1, 0
	movs r2, 0x1
	cmp r0, 0x1
	ble _080B59E0
_080B59D8:
	lsls r2, 1
	adds r1, 0x1
	cmp r0, r2
	bgt _080B59D8
_080B59E0:
	adds r0, r7, 0
	bl sub_80B58B0
	adds r1, r0, 0
	ldr r0, [sp, 0x18]
	str r0, [r1, 0x14]
	movs r0, 0x1
	str r0, [r1, 0x10]
	movs r5, 0x9
	cmp r6, 0x9
	ble _080B5A12
	adds r4, 0x9
_080B59F8:
	ldrb r3, [r4]
	subs r3, 0x30
	adds r4, 0x1
	adds r0, r7, 0
	movs r2, 0xA
	bl sub_80B5920
	adds r1, r0, 0
	adds r5, 0x1
	cmp r5, r6
	blt _080B59F8
	adds r4, 0x1
	b _080B5A14
_080B5A12:
	adds r4, 0xA
_080B5A14:
	cmp r5, r8
	bge _080B5A32
	mov r0, r8
	subs r5, r0, r5
_080B5A1C:
	ldrb r3, [r4]
	subs r3, 0x30
	adds r4, 0x1
	adds r0, r7, 0
	movs r2, 0xA
	bl sub_80B5920
	adds r1, r0, 0
	subs r5, 0x1
	cmp r5, 0
	bne _080B5A1C
_080B5A32:
	adds r0, r1, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	thumb_func_end sub_80B59B8

	thumb_func_start sub_80B5A3C
sub_80B5A3C:
	adds r1, r0, 0
	movs r2, 0
	ldr r0, _080B5A8C
	ands r0, r1
	cmp r0, 0
	bne _080B5A4C
	movs r2, 0x10
	lsls r1, 16
_080B5A4C:
	movs r0, 0xFF
	lsls r0, 24
	ands r0, r1
	cmp r0, 0
	bne _080B5A5A
	adds r2, 0x8
	lsls r1, 8
_080B5A5A:
	movs r0, 0xF0
	lsls r0, 24
	ands r0, r1
	cmp r0, 0
	bne _080B5A68
	adds r2, 0x4
	lsls r1, 4
_080B5A68:
	movs r0, 0xC0
	lsls r0, 24
	ands r0, r1
	cmp r0, 0
	bne _080B5A76
	adds r2, 0x2
	lsls r1, 2
_080B5A76:
	cmp r1, 0
	blt _080B5A90
	adds r2, 0x1
	movs r0, 0x80
	lsls r0, 23
	ands r0, r1
	cmp r0, 0
	bne _080B5A90
	movs r0, 0x20
	b _080B5A92
	.align 2, 0
_080B5A8C: .4byte 0xffff0000
_080B5A90:
	adds r0, r2, 0
_080B5A92:
	bx lr
	thumb_func_end sub_80B5A3C

	thumb_func_start sub_80B5A94
sub_80B5A94:
	adds r3, r0, 0
	ldr r1, [r3]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _080B5AC4
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B5AAC
	movs r0, 0
	b _080B5B14
_080B5AAC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080B5ABC
	lsrs r0, r1, 1
	str r0, [r3]
	movs r0, 0x1
	b _080B5B14
_080B5ABC:
	lsrs r0, r1, 2
	str r0, [r3]
	movs r0, 0x2
	b _080B5B14
_080B5AC4:
	movs r2, 0
	ldr r0, _080B5B0C
	ands r0, r1
	cmp r0, 0
	bne _080B5AD2
	movs r2, 0x10
	lsrs r1, 16
_080B5AD2:
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	bne _080B5ADE
	adds r2, 0x8
	lsrs r1, 8
_080B5ADE:
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _080B5AEA
	adds r2, 0x4
	lsrs r1, 4
_080B5AEA:
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B5AF6
	adds r2, 0x2
	lsrs r1, 2
_080B5AF6:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080B5B10
	adds r2, 0x1
	lsrs r1, 1
	cmp r1, 0
	bne _080B5B10
	movs r0, 0x20
	b _080B5B14
	.align 2, 0
_080B5B0C: .4byte 0x0000ffff
_080B5B10:
	str r1, [r3]
	adds r0, r2, 0
_080B5B14:
	bx lr
	thumb_func_end sub_80B5A94

	thumb_func_start sub_80B5B18
sub_80B5B18:
	push {r4,lr}
	adds r4, r1, 0
	movs r1, 0x1
	bl sub_80B58B0
	str r4, [r0, 0x14]
	movs r1, 0x1
	str r1, [r0, 0x10]
	pop {r4,pc}
	thumb_func_end sub_80B5B18

	thumb_func_start sub_80B5B2C
sub_80B5B2C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	ldr r1, [r4, 0x10]
	ldr r0, [r5, 0x10]
	cmp r1, r0
	bge _080B5B4C
	str r4, [sp]
	adds r4, r5, 0
	ldr r5, [sp]
_080B5B4C:
	ldr r1, [r4, 0x4]
	ldr r6, [r4, 0x10]
	ldr r0, [r5, 0x10]
	mov r8, r0
	mov r2, r8
	adds r2, r6, r2
	str r2, [sp, 0x4]
	ldr r0, [r4, 0x8]
	cmp r2, r0
	ble _080B5B62
	adds r1, 0x1
_080B5B62:
	adds r0, r3, 0
	bl sub_80B58B0
	str r0, [sp]
	adds r7, r0, 0
	adds r7, 0x14
	ldr r1, [sp, 0x4]
	lsls r0, r1, 2
	adds r2, r7, r0
	str r2, [sp, 0x8]
	str r0, [sp, 0x18]
	adds r1, r4, 0
	adds r1, 0x14
	lsls r3, r6, 2
	adds r2, r5, 0
	adds r2, 0x14
	mov r5, r8
	lsls r4, r5, 2
	ldr r0, [sp, 0x8]
	cmp r7, r0
	bcs _080B5B96
	movs r0, 0
_080B5B8E:
	stm r7!, {r0}
	ldr r5, [sp, 0x8]
	cmp r7, r5
	bcc _080B5B8E
_080B5B96:
	str r1, [sp, 0x8]
	adds r3, r1, r3
	str r3, [sp, 0xC]
	mov r8, r2
	add r4, r8
	str r4, [sp, 0x10]
	ldr r0, [sp]
	adds r0, 0x14
	mov r9, r0
	mov r1, r9
	str r1, [sp, 0x20]
	cmp r8, r4
	bcs _080B5C5E
_080B5BB0:
	mov r2, r8
	ldm r2!, {r6}
	str r2, [sp, 0x14]
	ldr r0, _080B5C6C
	ands r6, r0
	mov r4, r9
	adds r4, 0x4
	str r4, [sp, 0x1C]
	cmp r6, 0
	beq _080B5C08
	ldr r7, [sp, 0x8]
	mov r5, r9
	movs r1, 0
	mov r12, r1
	mov r10, r0
_080B5BCE:
	ldm r7!, {r3}
	adds r0, r3, 0
	mov r2, r10
	ands r0, r2
	adds r1, r0, 0
	muls r1, r6
	ldr r2, [r5]
	adds r0, r2, 0
	mov r4, r10
	ands r0, r4
	adds r1, r0
	mov r0, r12
	adds r4, r1, r0
	lsrs r1, r4, 16
	lsrs r3, 16
	adds r0, r3, 0
	muls r0, r6
	lsrs r2, 16
	adds r0, r2
	adds r2, r0, r1
	lsrs r0, r2, 16
	mov r12, r0
	strh r2, [r5]
	strh r4, [r5, 0x2]
	adds r5, 0x4
	ldr r1, [sp, 0xC]
	cmp r7, r1
	bcc _080B5BCE
	str r0, [r5]
_080B5C08:
	mov r2, r8
	ldrh r6, [r2, 0x2]
	cmp r6, 0
	beq _080B5C50
	ldr r7, [sp, 0x8]
	mov r5, r9
	movs r4, 0
	mov r12, r4
	ldr r2, [r5]
	ldr r3, _080B5C6C
_080B5C1C:
	ldm r7!, {r1}
	adds r0, r1, 0
	ands r0, r3
	muls r0, r6
	ldrh r4, [r5, 0x2]
	adds r4, r0
	mov r8, r4
	add r4, r12
	lsrs r0, r4, 16
	mov r12, r0
	strh r4, [r5]
	strh r2, [r5, 0x2]
	adds r5, 0x4
	lsrs r1, 16
	muls r1, r6
	ldr r0, [r5]
	ands r0, r3
	adds r1, r0
	mov r4, r12
	adds r2, r1, r4
	lsrs r0, r2, 16
	mov r12, r0
	ldr r1, [sp, 0xC]
	cmp r7, r1
	bcc _080B5C1C
	str r2, [r5]
_080B5C50:
	ldr r2, [sp, 0x14]
	mov r8, r2
	ldr r4, [sp, 0x1C]
	mov r9, r4
	ldr r5, [sp, 0x10]
	cmp r8, r5
	bcc _080B5BB0
_080B5C5E:
	ldr r0, [sp, 0x20]
	ldr r1, [sp, 0x18]
	adds r5, r0, r1
	ldr r2, [sp, 0x4]
	cmp r2, 0
	ble _080B5C82
	b _080B5C7A
	.align 2, 0
_080B5C6C: .4byte 0x0000ffff
_080B5C70:
	ldr r4, [sp, 0x4]
	subs r4, 0x1
	str r4, [sp, 0x4]
	cmp r4, 0
	ble _080B5C82
_080B5C7A:
	subs r5, 0x4
	ldr r0, [r5]
	cmp r0, 0
	beq _080B5C70
_080B5C82:
	ldr r5, [sp, 0x4]
	ldr r0, [sp]
	str r5, [r0, 0x10]
	ldr r0, [sp]
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	thumb_func_end sub_80B5B2C

	thumb_func_start sub_80B5C98
sub_80B5C98:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, 0
	adds r6, r2, 0
	movs r1, 0x3
	ands r1, r6
	cmp r1, 0
	beq _080B5CC2
	ldr r0, _080B5CE4
	subs r1, 0x1
	lsls r1, 2
	adds r1, r0
	ldr r2, [r1]
	mov r0, r8
	adds r1, r7, 0
	movs r3, 0
	bl sub_80B5920
	adds r7, r0, 0
_080B5CC2:
	asrs r6, 2
	cmp r6, 0
	beq _080B5D28
	mov r0, r8
	ldr r5, [r0, 0x48]
	adds r4, r5, 0
	cmp r5, 0
	bne _080B5D04
	ldr r1, _080B5CE8
	bl sub_80B5B18
	mov r1, r8
	str r0, [r1, 0x48]
	adds r5, r0, 0
	str r4, [r5]
	b _080B5D04
	.align 2, 0
_080B5CE4: .4byte gUnknown_826FEB4
_080B5CE8: .4byte 0x00000271
_080B5CEC:
	ldr r0, [r5]
	adds r4, r0, 0
	cmp r0, 0
	bne _080B5D02
	mov r0, r8
	adds r1, r5, 0
	adds r2, r5, 0
	bl sub_80B5B2C
	str r0, [r5]
	str r4, [r0]
_080B5D02:
	adds r5, r0, 0
_080B5D04:
	movs r0, 0x1
	ands r0, r6
	cmp r0, 0
	beq _080B5D22
	mov r0, r8
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_80B5B2C
	adds r4, r0, 0
	mov r0, r8
	adds r1, r7, 0
	bl sub_80B5908
	adds r7, r4, 0
_080B5D22:
	asrs r6, 1
	cmp r6, 0
	bne _080B5CEC
_080B5D28:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	thumb_func_end sub_80B5C98

	thumb_func_start sub_80B5D30
sub_80B5D30:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	mov r8, r1
	adds r5, r2, 0
	asrs r6, r5, 5
	ldr r1, [r1, 0x4]
	mov r2, r8
	ldr r0, [r2, 0x10]
	adds r0, r6, r0
	adds r7, r0, 0x1
	ldr r2, [r2, 0x8]
	cmp r7, r2
	ble _080B5D5A
_080B5D52:
	adds r1, 0x1
	lsls r2, 1
	cmp r7, r2
	bgt _080B5D52
_080B5D5A:
	mov r0, r10
	bl sub_80B58B0
	mov r9, r0
	mov r4, r9
	adds r4, 0x14
	mov r0, r8
	adds r0, 0x14
	cmp r6, 0
	ble _080B5D7A
	movs r1, 0
	adds r2, r6, 0
_080B5D72:
	stm r4!, {r1}
	subs r2, 0x1
	cmp r2, 0
	bne _080B5D72
_080B5D7A:
	adds r3, r0, 0
	mov r1, r8
	ldr r0, [r1, 0x10]
	lsls r0, 2
	adds r6, r3, r0
	movs r0, 0x1F
	ands r5, r0
	cmp r5, 0
	beq _080B5DAC
	movs r0, 0x20
	subs r1, r0, r5
	movs r2, 0
_080B5D92:
	ldr r0, [r3]
	lsls r0, r5
	orrs r0, r2
	stm r4!, {r0}
	ldm r3!, {r2}
	lsrs r2, r1
	cmp r3, r6
	bcc _080B5D92
	str r2, [r4]
	cmp r2, 0
	beq _080B5DB4
	adds r7, 0x1
	b _080B5DB4
_080B5DAC:
	ldm r3!, {r0}
	stm r4!, {r0}
	cmp r3, r6
	bcc _080B5DAC
_080B5DB4:
	subs r0, r7, 0x1
	mov r2, r9
	str r0, [r2, 0x10]
	mov r0, r10
	mov r1, r8
	bl sub_80B5908
	mov r0, r9
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	thumb_func_end sub_80B5D30

	thumb_func_start sub_80B5DD0
sub_80B5DD0:
	push {r4,r5,lr}
	adds r2, r0, 0
	adds r5, r1, 0
	ldr r0, [r2, 0x10]
	ldr r1, [r5, 0x10]
	subs r0, r1
	cmp r0, 0
	bne _080B5E0C
	adds r4, r2, 0
	adds r4, 0x14
	lsls r1, 2
	adds r3, r4, r1
	adds r0, r5, 0
	adds r0, 0x14
	adds r1, r0, r1
_080B5DEE:
	subs r3, 0x4
	subs r1, 0x4
	ldr r0, [r3]
	ldr r2, [r1]
	cmp r0, r2
	beq _080B5E06
	movs r1, 0x1
	cmp r0, r2
	bcs _080B5E02
	subs r1, 0x2
_080B5E02:
	adds r0, r1, 0
	b _080B5E0C
_080B5E06:
	cmp r3, r4
	bhi _080B5DEE
	movs r0, 0
_080B5E0C:
	pop {r4,r5,pc}
	thumb_func_end sub_80B5DD0

	thumb_func_start sub_80B5E10
sub_80B5E10:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	mov r8, r2
	adds r0, r5, 0
	mov r1, r8
	bl sub_80B5DD0
	adds r4, r0, 0
	cmp r4, 0
	bne _080B5E42
	adds r0, r6, 0
	movs r1, 0
	bl sub_80B58B0
	adds r7, r0, 0
	movs r0, 0x1
	str r0, [r7, 0x10]
	str r4, [r7, 0x14]
	b _080B5EF2
_080B5E42:
	cmp r4, 0
	bge _080B5E50
	adds r7, r5, 0
	mov r5, r8
	mov r8, r7
	movs r4, 0x1
	b _080B5E52
_080B5E50:
	movs r4, 0
_080B5E52:
	ldr r1, [r5, 0x4]
	adds r0, r6, 0
	bl sub_80B58B0
	adds r7, r0, 0
	str r4, [r7, 0xC]
	ldr r0, [r5, 0x10]
	mov r9, r0
	adds r6, r5, 0
	adds r6, 0x14
	lsls r0, 2
	adds r0, r6
	mov r10, r0
	mov r1, r8
	ldr r0, [r1, 0x10]
	movs r3, 0x14
	add r3, r8
	mov r12, r3
	lsls r0, 2
	add r0, r12
	str r0, [sp]
	adds r4, r7, 0
	adds r4, 0x14
	movs r5, 0
	ldr r0, _080B5EDC
	mov r8, r0
_080B5E86:
	ldm r6!, {r1}
	str r1, [sp, 0x4]
	mov r3, r8
	ands r1, r3
	mov r0, r12
	adds r0, 0x4
	mov r12, r0
	subs r0, 0x4
	ldm r0!, {r2}
	adds r0, r2, 0
	ands r0, r3
	subs r1, r0
	adds r0, r1, r5
	asrs r5, r0, 16
	ldr r1, [sp, 0x4]
	lsrs r3, r1, 16
	lsrs r2, 16
	subs r3, r2
	adds r1, r3, r5
	asrs r5, r1, 16
	strh r1, [r4]
	strh r0, [r4, 0x2]
	adds r4, 0x4
	ldr r3, [sp]
	cmp r12, r3
	bcc _080B5E86
	cmp r6, r10
	bcs _080B5EE6
	ldr r2, _080B5EDC
_080B5EC0:
	ldm r6!, {r1}
	adds r0, r1, 0
	ands r0, r2
	adds r0, r5
	asrs r5, r0, 16
	lsrs r1, 16
	adds r1, r5
	asrs r5, r1, 16
	strh r1, [r4]
	strh r0, [r4, 0x2]
	adds r4, 0x4
	cmp r6, r10
	bcc _080B5EC0
	b _080B5EE6
	.align 2, 0
_080B5EDC: .4byte 0x0000ffff
_080B5EE0:
	movs r0, 0x1
	negs r0, r0
	add r9, r0
_080B5EE6:
	subs r4, 0x4
	ldr r0, [r4]
	cmp r0, 0
	beq _080B5EE0
	mov r1, r9
	str r1, [r7, 0x10]
_080B5EF2:
	adds r0, r7, 0
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	thumb_func_end sub_80B5E10

	thumb_func_start sub_80B5F00
sub_80B5F00:
	push {r4,lr}
	ldr r2, _080B5F14
	ands r2, r0
	ldr r0, _080B5F18
	adds r2, r0
	cmp r2, 0
	ble _080B5F1C
	adds r3, r2, 0
	movs r4, 0
	b _080B5F46
	.align 2, 0
_080B5F14: .4byte 0x7ff00000
_080B5F18: .4byte 0xfcc00000
_080B5F1C:
	negs r0, r2
	asrs r2, r0, 20
	cmp r2, 0x13
	bgt _080B5F30
	movs r0, 0x80
	lsls r0, 12
	adds r3, r0, 0
	asrs r3, r2
	movs r4, 0
	b _080B5F46
_080B5F30:
	movs r3, 0
	subs r2, 0x14
	cmp r2, 0x1E
	bgt _080B5F42
	movs r0, 0x1F
	subs r0, r2
	movs r1, 0x1
	lsls r1, r0
	b _080B5F44
_080B5F42:
	movs r1, 0x1
_080B5F44:
	adds r4, r1, 0
_080B5F46:
	adds r1, r4, 0
	adds r0, r3, 0
	pop {r4,pc}
	thumb_func_end sub_80B5F00

	thumb_func_start sub_80B5F4C
sub_80B5F4C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r1, 0
	movs r1, 0x14
	adds r1, r0
	mov r8, r1
	ldr r0, [r0, 0x10]
	lsls r0, 2
	adds r5, r1, r0
	subs r5, 0x4
	ldr r2, [r5]
	adds r0, r2, 0
	str r2, [sp]
	bl sub_80B5A3C
	adds r3, r0, 0
	movs r0, 0x20
	subs r0, r3
	str r0, [r4]
	ldr r2, [sp]
	cmp r3, 0xA
	bgt _080B5FAC
	movs r0, 0xB
	subs r0, r3
	adds r1, r2, 0
	lsrs r1, r0
	ldr r0, _080B5F94
	adds r6, r1, 0
	orrs r6, r0
	cmp r5, r8
	bls _080B5F98
	subs r5, 0x4
	ldr r1, [r5]
	b _080B5F9A
	.align 2, 0
_080B5F94: .4byte 0x3ff00000
_080B5F98:
	movs r1, 0
_080B5F9A:
	adds r0, r3, 0
	adds r0, 0x15
	lsls r2, r0
	movs r0, 0xB
	subs r0, r3
	lsrs r1, r0
	adds r7, r2, 0
	orrs r7, r1
	b _080B5FF8
_080B5FAC:
	cmp r5, r8
	bls _080B5FB6
	subs r5, 0x4
	ldr r4, [r5]
	b _080B5FB8
_080B5FB6:
	movs r4, 0
_080B5FB8:
	subs r3, 0xB
	cmp r3, 0
	beq _080B5FF0
	lsls r2, r3
	movs r0, 0x20
	subs r0, r3
	adds r1, r4, 0
	lsrs r1, r0
	ldr r0, _080B5FDC
	orrs r1, r0
	adds r6, r2, 0
	orrs r6, r1
	cmp r5, r8
	bls _080B5FE0
	subs r5, 0x4
	ldr r2, [r5]
	b _080B5FE2
	.align 2, 0
_080B5FDC: .4byte 0x3ff00000
_080B5FE0:
	movs r2, 0
_080B5FE2:
	lsls r4, r3
	movs r0, 0x20
	subs r0, r3
	lsrs r2, r0
	adds r7, r4, 0
	orrs r7, r2
	b _080B5FF8
_080B5FF0:
	ldr r0, _080B6004
	adds r6, r2, 0
	orrs r6, r0
	adds r7, r4, 0
_080B5FF8:
	adds r1, r7, 0
	adds r0, r6, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	.align 2, 0
_080B6004: .4byte 0x3ff00000
	thumb_func_end sub_80B5F4C

	thumb_func_start sub_80B6008
sub_80B6008:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r3
	ldr r3, [sp, 0x28]
	mov r10, r3
	adds r5, r2, 0
	adds r4, r1, 0
	movs r1, 0x1
	bl sub_80B58B0
	adds r6, r0, 0
	movs r0, 0x14
	adds r0, r6
	mov r8, r0
	ldr r2, _080B6070
	adds r1, r4, 0
	ands r2, r1
	str r2, [sp, 0x4]
	ldr r0, _080B6074
	ands r4, r0
	lsrs r7, r4, 20
	cmp r7, 0
	beq _080B6046
	movs r0, 0x80
	lsls r0, 13
	orrs r0, r2
	str r0, [sp, 0x4]
_080B6046:
	str r5, [sp]
	cmp r5, 0
	beq _080B6090
	mov r0, sp
	bl sub_80B5A94
	adds r2, r0, 0
	cmp r2, 0
	beq _080B6078
	movs r0, 0x20
	subs r0, r2
	ldr r1, [sp, 0x4]
	lsls r1, r0
	ldr r0, [sp]
	orrs r0, r1
	str r0, [r6, 0x14]
	ldr r0, [sp, 0x4]
	lsrs r0, r2
	str r0, [sp, 0x4]
	b _080B607C
	.align 2, 0
_080B6070: .4byte 0x000fffff
_080B6074: .4byte 0x7fffffff
_080B6078:
	ldr r0, [sp]
	str r0, [r6, 0x14]
_080B607C:
	ldr r0, [sp, 0x4]
	mov r1, r8
	str r0, [r1, 0x4]
	movs r1, 0x1
	cmp r0, 0
	beq _080B608A
	movs r1, 0x2
_080B608A:
	str r1, [r6, 0x10]
	adds r4, r1, 0
	b _080B60A4
_080B6090:
	add r0, sp, 0x4
	bl sub_80B5A94
	adds r2, r0, 0
	ldr r0, [sp, 0x4]
	str r0, [r6, 0x14]
	movs r0, 0x1
	str r0, [r6, 0x10]
	movs r4, 0x1
	adds r2, 0x20
_080B60A4:
	cmp r7, 0
	beq _080B60C0
	ldr r3, _080B60BC
	adds r0, r2, r3
	adds r0, r7, r0
	mov r1, r9
	str r0, [r1]
	movs r0, 0x35
	subs r0, r2
	mov r3, r10
	str r0, [r3]
	b _080B60DC
	.align 2, 0
_080B60BC: .4byte 0xfffffbcd
_080B60C0:
	ldr r1, _080B60EC
	adds r0, r2, r1
	mov r3, r9
	str r0, [r3]
	lsls r0, r4, 2
	add r0, r8
	subs r0, 0x4
	ldr r0, [r0]
	bl sub_80B5A3C
	lsls r1, r4, 5
	subs r1, r0
	mov r0, r10
	str r1, [r0]
_080B60DC:
	adds r0, r6, 0
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7,pc}
	.align 2, 0
_080B60EC: .4byte 0xfffffbce
	thumb_func_end sub_80B6008

	thumb_func_start sub_80B60F0
sub_80B60F0:
	push {r4-r7,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	mov r1, sp
	bl sub_80B5F4C
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	add r1, sp, 0x4
	adds r0, r5, 0
	bl sub_80B5F4C
	adds r7, r1, 0
	adds r6, r0, 0
	ldr r2, [sp]
	ldr r0, [sp, 0x4]
	subs r2, r0
	ldr r0, [r4, 0x10]
	ldr r1, [r5, 0x10]
	subs r0, r1
	lsls r0, 5
	adds r0, r2, r0
	cmp r0, 0
	ble _080B612C
	lsls r0, 20
	ldr r1, [sp, 0x8]
	adds r0, r1, r0
	str r0, [sp, 0x8]
	b _080B6130
_080B612C:
	lsls r0, 20
	subs r6, r0
_080B6130:
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0xC]
	adds r3, r7, 0
	adds r2, r6, 0
	bl __divdf3
	add sp, 0x10
	pop {r4-r7,pc}
	thumb_func_end sub_80B60F0

	thumb_func_start sub_80B6140
sub_80B6140:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _080B615C
	ldr r0, _080B6158
	cmp r4, 0x17
	bgt _080B6164
	ldr r0, _080B6160
	lsls r1, r4, 3
	adds r1, r0
	ldr r0, [r1]
	ldr r1, [r1, 0x4]
	b _080B6176
	.align 2, 0
_080B6158: .4byte 0x3ff00000
_080B615C: .4byte 0x00000000
_080B6160: .4byte gUnknown_826FEC0
_080B6164:
	cmp r4, 0
	ble _080B6176
_080B6168:
	ldr r3, _080B617C
	ldr r2, _080B6178
	bl __muldf3
	subs r4, 0x1
	cmp r4, 0
	bgt _080B6168
_080B6176:
	pop {r4,pc}
	.align 2, 0
_080B6178: .4byte 0x40240000
_080B617C: .4byte 0x00000000
	thumb_func_end sub_80B6140

	thumb_func_start sub_80B6180
sub_80B6180:
	ldr r3, _080B619C
	ands r3, r0
	negs r2, r1
	orrs r2, r1
	lsrs r2, 31
	orrs r3, r2
	ldr r0, _080B61A0
	subs r3, r0, r3
	negs r0, r3
	orrs r3, r0
	lsrs r3, 31
	movs r0, 0x1
	subs r0, r3
	bx lr
	.align 2, 0
_080B619C: .4byte 0x7fffffff
_080B61A0: .4byte 0x7ff00000
	thumb_func_end sub_80B6180

	thumb_func_start sub_80B61A4
sub_80B61A4:
	ldr r3, _080B61BC
	ands r3, r0
	negs r2, r1
	orrs r2, r1
	lsrs r2, 31
	orrs r3, r2
	ldr r0, _080B61C0
	subs r3, r0, r3
	lsrs r3, 31
	adds r0, r3, 0
	bx lr
	.align 2, 0
_080B61BC: .4byte 0x7fffffff
_080B61C0: .4byte 0x7ff00000
	thumb_func_end sub_80B61A4

	thumb_func_start _sbrk_r
_sbrk_r:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	ldr r4, _080B61EC
	movs r1, 0
	str r1, [r4]
	bl _sbrk
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B61E6
	ldr r0, [r4]
	cmp r0, 0
	beq _080B61E6
	str r0, [r5]
_080B61E6:
	adds r0, r1, 0
	pop {r4,r5,pc}
	.align 2, 0
_080B61EC: .4byte gUnknown_203B034
	thumb_func_end _sbrk_r

	thumb_func_start sub_80B61F0
sub_80B61F0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r2, 0
	ldr r0, [r5, 0x54]
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	adds r2, r4, 0
	bl sub_80B685C
	adds r1, r0, 0
	cmp r1, 0
	blt _080B6212
	ldr r0, [r5, 0x50]
	adds r0, r1
	str r0, [r5, 0x50]
	b _080B621A
_080B6212:
	ldr r0, _080B6220
	ldrh r2, [r5, 0xC]
	ands r0, r2
	strh r0, [r5, 0xC]
_080B621A:
	adds r0, r1, 0
	pop {r4,r5,pc}
	.align 2, 0
_080B6220: .4byte 0xffffefff
	thumb_func_end sub_80B61F0

	thumb_func_start sub_80B6224
sub_80B6224:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	movs r0, 0x80
	lsls r0, 1
	ldrh r1, [r4, 0xC]
	ands r0, r1
	cmp r0, 0
	beq _080B6246
	ldr r0, [r4, 0x54]
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0x2
	bl sub_80B682C
_080B6246:
	ldr r0, _080B6260
	ldrh r1, [r4, 0xC]
	ands r0, r1
	strh r0, [r4, 0xC]
	ldr r0, [r4, 0x54]
	movs r2, 0xE
	ldrsh r1, [r4, r2]
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80B6718
	pop {r4-r6,pc}
	.align 2, 0
_080B6260: .4byte 0xffffefff
	thumb_func_end sub_80B6224

	thumb_func_start sub_80B6264
sub_80B6264:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r2, 0
	ldr r0, [r5, 0x54]
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	adds r2, r4, 0
	bl sub_80B682C
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B6290
	ldr r0, _080B628C
	ldrh r2, [r5, 0xC]
	ands r0, r2
	strh r0, [r5, 0xC]
	b _080B629E
	.align 2, 0
_080B628C: .4byte 0xffffefff
_080B6290:
	movs r2, 0x80
	lsls r2, 5
	adds r0, r2, 0
	ldrh r2, [r5, 0xC]
	orrs r0, r2
	strh r0, [r5, 0xC]
	str r1, [r5, 0x50]
_080B629E:
	adds r0, r1, 0
	pop {r4,r5,pc}
	thumb_func_end sub_80B6264

	thumb_func_start sub_80B62A4
sub_80B62A4:
	push {lr}
	ldr r2, [r0, 0x54]
	movs r3, 0xE
	ldrsh r1, [r0, r3]
	adds r0, r2, 0
	bl sub_80B67A0
	pop {pc}
	thumb_func_end sub_80B62A4

	thumb_func_start findslot
findslot:
	adds r3, r0, 0
	movs r1, 0
	ldr r2, _080B62BC
	b _080B62C8
	.align 2, 0
_080B62BC: .4byte gUnknown_2039E28
_080B62C0:
	adds r2, 0x8
	adds r1, 0x1
	cmp r1, 0x13
	bgt _080B62CE
_080B62C8:
	ldr r0, [r2]
	cmp r0, r3
	bne _080B62C0
_080B62CE:
	adds r0, r1, 0
	bx lr
	thumb_func_end findslot

	thumb_func_start sub_80B62D4
sub_80B62D4:
	adds r2, r0, 0
	ldr r0, _080B62E8
	ldr r1, [r0]
	ldr r0, [r1, 0x4]
	movs r3, 0xE
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _080B62F0
	ldr r0, _080B62EC
	b _080B6316
	.align 2, 0
_080B62E8: .4byte gUnknown_203B7A8
_080B62EC: .4byte gUnknown_2039E1C
_080B62F0:
	ldr r0, [r1, 0x8]
	movs r3, 0xE
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _080B6304
	ldr r0, _080B6300
	b _080B6316
	.align 2, 0
_080B6300: .4byte gUnknown_2039E20
_080B6304:
	ldr r0, [r1, 0xC]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	cmp r2, r0
	beq _080B6314
	adds r0, r2, 0
	subs r0, 0x20
	b _080B6318
_080B6314:
	ldr r0, _080B631C
_080B6316:
	ldr r0, [r0]
_080B6318:
	bx lr
	.align 2, 0
_080B631C: .4byte gUnknown_2039E24
	thumb_func_end sub_80B62D4

	thumb_func_start sub_80B6320
sub_80B6320:
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r4, _080B637C
	str r4, [sp]
	movs r3, 0x3
	str r3, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r5, 0x1
	adds r0, r5, 0
	mov r1, sp
	swi 0xAB
	adds r2, r0, 0
	ldr r5, _080B6380
	str r2, [r5]
	str r4, [sp]
	str r3, [sp, 0x8]
	movs r0, 0x4
	str r0, [sp, 0x4]
	ldr r3, _080B6384
	movs r4, 0x1
	adds r0, r4, 0
	mov r1, sp
	swi 0xAB
	adds r2, r0, 0
	ldr r0, _080B6388
	str r2, [r0]
	str r2, [r3]
	ldr r2, _080B638C
	adds r1, r2, 0
	subs r4, 0x2
	adds r0, r2, 0
	adds r0, 0x98
_080B6362:
	str r4, [r0]
	subs r0, 0x8
	cmp r0, r1
	bge _080B6362
	movs r0, 0
	ldr r1, [r5]
	str r1, [r2]
	str r0, [r2, 0x4]
	ldr r1, [r3]
	str r1, [r2, 0x8]
	str r0, [r2, 0xC]
	add sp, 0xC
	pop {r4,r5,pc}
	.align 2, 0
_080B637C: .4byte gUnknown_826FFD8
_080B6380: .4byte gUnknown_2039E1C
_080B6384: .4byte gUnknown_2039E20
_080B6388: .4byte gUnknown_2039E24
_080B638C: .4byte gUnknown_2039E28
	thumb_func_end sub_80B6320

	thumb_func_start sub_80B6390
sub_80B6390:
	push {r4,lr}
	movs r3, 0x13
	movs r4, 0
	adds r0, r3, 0
	adds r1, r4, 0
	swi 0xAB
	adds r2, r0, 0
	adds r0, r2, 0
	pop {r4,pc}
	thumb_func_end sub_80B6390

	thumb_func_start sub_80B63A4
sub_80B63A4:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_80B67CC
	adds r4, r0, 0
	bl sub_80B6390
	str r0, [r4]
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end sub_80B63A4

	thumb_func_start sub_80B63B8
sub_80B63B8:
	push {lr}
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080B63C8
	adds r0, r1, 0
	b _080B63CE
_080B63C8:
	adds r0, r1, 0
	bl sub_80B63A4
_080B63CE:
	pop {pc}
	thumb_func_end sub_80B63B8

	thumb_func_start sub_80B63D0
sub_80B63D0:
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_80B62D4
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r3, 0x6
	adds r0, r3, 0
	mov r1, sp
	swi 0xAB
	adds r2, r0, 0
	adds r0, r2, 0
	add sp, 0xC
	pop {r4,r5,pc}
	thumb_func_end sub_80B63D0

	thumb_func_start sub_80B63F4
sub_80B63F4:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	bl sub_80B62D4
	bl findslot
	adds r6, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r7, 0
	bl sub_80B63D0
	cmp r0, 0
	bge _080B641E
	movs r0, 0x1
	negs r0, r0
	bl sub_80B63A4
	b _080B6434
_080B641E:
	subs r2, r7, r0
	cmp r6, 0x14
	beq _080B6432
	ldr r0, _080B6438
	lsls r1, r6, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
_080B6432:
	adds r0, r2, 0
_080B6434:
	pop {r4-r7,pc}
	.align 2, 0
_080B6438: .4byte gUnknown_2039E28
	thumb_func_end sub_80B63F4

	thumb_func_start sub_80B643C
sub_80B643C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	bl sub_80B62D4
	adds r7, r0, 0
	bl findslot
	adds r6, r0, 0
	cmp r4, 0x1
	bne _080B6472
	cmp r6, 0x14
	bne _080B6464
	movs r0, 0x1
	negs r0, r0
	b _080B64B4
_080B6464:
	ldr r0, _080B64BC
	lsls r1, r6, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	adds r5, r0
	movs r4, 0
_080B6472:
	cmp r4, 0x2
	bne _080B6484
	str r7, [sp]
	movs r3, 0xC
	adds r0, r3, 0
	mov r1, sp
	swi 0xAB
	adds r2, r0, 0
	adds r5, r2
_080B6484:
	mov r0, r8
	bl sub_80B62D4
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r3, 0xA
	adds r0, r3, 0
	mov r1, sp
	swi 0xAB
	adds r2, r0, 0
	cmp r6, 0x14
	beq _080B64AA
	cmp r2, 0
	bne _080B64AA
	ldr r0, _080B64BC
	lsls r1, r6, 3
	adds r0, 0x4
	adds r1, r0
	str r5, [r1]
_080B64AA:
	movs r0, 0x1
	negs r0, r0
	cmp r2, 0
	bne _080B64B4
	adds r0, r5, 0
_080B64B4:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	.align 2, 0
_080B64BC: .4byte gUnknown_2039E28
	thumb_func_end sub_80B643C

	thumb_func_start sub_80B64C0
sub_80B64C0:
	push {lr}
	bl sub_80B643C
	bl sub_80B63B8
	pop {pc}
	thumb_func_end sub_80B64C0

	thumb_func_start sub_80B64CC
sub_80B64CC:
	push {r4,r5,lr}
	sub sp, 0xC
	adds r4, r1, 0
	adds r5, r2, 0
	bl sub_80B62D4
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r3, 0x5
	adds r0, r3, 0
	mov r1, sp
	swi 0xAB
	adds r2, r0, 0
	adds r0, r2, 0
	add sp, 0xC
	pop {r4,r5,pc}
	thumb_func_end sub_80B64CC

	thumb_func_start _write
_write:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	bl sub_80B62D4
	bl findslot
	adds r7, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80B64CC
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _080B6518
	cmp r0, r6
	bne _080B6520
_080B6518:
	adds r0, r1, 0
	bl sub_80B63A4
	b _080B6536
_080B6520:
	subs r2, r6, r0
	cmp r7, 0x14
	beq _080B6534
	ldr r0, _080B6538
	lsls r1, r7, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	adds r0, r2
	str r0, [r1]
_080B6534:
	adds r0, r2, 0
_080B6536:
	pop {r4-r7,pc}
	.align 2, 0
_080B6538: .4byte gUnknown_2039E28
	thumb_func_end _write

	thumb_func_start _swiopen
_swiopen:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r0, 0
	adds r4, r1, 0
	movs r5, 0
	movs r6, 0x1
	negs r6, r6
	adds r0, r6, 0
	bl findslot
	mov r8, r0
	cmp r0, 0x14
	bne _080B655E
	adds r0, r6, 0
	b _080B65D2
_080B655E:
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _080B6568
	movs r5, 0x2
_080B6568:
	movs r0, 0x80
	lsls r0, 2
	ands r0, r4
	cmp r0, 0
	beq _080B6576
	movs r0, 0x4
	orrs r5, r0
_080B6576:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r4
	cmp r0, 0
	beq _080B6584
	movs r0, 0x4
	orrs r5, r0
_080B6584:
	movs r1, 0x8
	ands r4, r1
	cmp r4, 0
	beq _080B6594
	movs r0, 0x5
	negs r0, r0
	ands r5, r0
	orrs r5, r1
_080B6594:
	str r7, [sp]
	adds r0, r7, 0
	bl strlen
	str r0, [sp, 0x8]
	str r5, [sp, 0x4]
	movs r2, 0x1
	adds r0, r2, 0
	mov r1, sp
	swi 0xAB
	adds r3, r0, 0
	cmp r3, 0
	blt _080B65CC
	ldr r0, _080B65C8
	mov r1, r8
	lsls r2, r1, 3
	adds r1, r2, r0
	str r3, [r1]
	adds r0, 0x4
	adds r2, r0
	movs r0, 0
	str r0, [r2]
	adds r0, r3, 0
	adds r0, 0x20
	b _080B65D2
	.align 2, 0
_080B65C8: .4byte gUnknown_2039E28
_080B65CC:
	adds r0, r3, 0
	bl sub_80B63A4
_080B65D2:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7,pc}
	thumb_func_end _swiopen

	thumb_func_start sub_80B65DC
sub_80B65DC:
	push {r1-r3}
	push {lr}
	ldr r1, [sp, 0x4]
	bl _swiopen
	bl sub_80B63B8
	pop {r3}
	add sp, 0xC
	bx r3
	thumb_func_end sub_80B65DC

	thumb_func_start sub_80B65F0
sub_80B65F0:
	push {lr}
	sub sp, 0x4
	bl sub_80B62D4
	str r0, [sp]
	bl findslot
	adds r1, r0, 0
	cmp r1, 0x14
	beq _080B6610
	ldr r0, _080B6620
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
_080B6610:
	movs r3, 0x2
	adds r0, r3, 0
	mov r1, sp
	swi 0xAB
	adds r2, r0, 0
	adds r0, r2, 0
	add sp, 0x4
	pop {pc}
	.align 2, 0
_080B6620: .4byte gUnknown_2039E28
	thumb_func_end sub_80B65F0

	thumb_func_start sub_80B6624
sub_80B6624:
	push {lr}
	bl sub_80B65F0
	bl sub_80B63B8
	pop {pc}
	thumb_func_end sub_80B6624

	thumb_func_start sub_80B6630
sub_80B6630:
	mov r12, r3
	mov r3, r8
	push {r3}
	mov r3, r12
	movs r2, 0x18
	ldr r3, _080B664C
	adds r0, r2, 0
	adds r1, r3, 0
	swi 0xAB
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_080B664C: .4byte 0x00020026
	thumb_func_end sub_80B6630

	thumb_func_start sub_80B6650
sub_80B6650:
	mov r12, r3
	mov r3, r8
	push {r3}
	mov r3, r12
	movs r2, 0x18
	ldr r3, _080B666C
	adds r0, r2, 0
	adds r1, r3, 0
	swi 0xAB
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_080B666C: .4byte 0x00020026
	thumb_func_end sub_80B6650

	thumb_func_start sub_80B6670
sub_80B6670:
	movs r0, 0x1
	bx lr
	thumb_func_end sub_80B6670

	thumb_func_start _sbrk
_sbrk:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, _080B66A4
	ldr r0, [r4]
	cmp r0, 0
	bne _080B6684
	ldr r0, _080B66A8
	str r0, [r4]
_080B6684:
	ldr r5, [r4]
	adds r0, r5, r6
	cmp r0, sp
	bls _080B669A
	ldr r1, _080B66AC
	movs r0, 0x1
	movs r2, 0x20
	bl _write
	bl abort
_080B669A:
	ldr r0, [r4]
	adds r0, r6
	str r0, [r4]
	adds r0, r5, 0
	pop {r4-r6,pc}
	.align 2, 0
_080B66A4: .4byte gUnknown_2039E18
_080B66A8: .4byte end
_080B66AC: .4byte gUnknown_826FFDC
	thumb_func_end _sbrk

	thumb_func_start sub_80B66B0
sub_80B66B0:
	movs r0, 0x80
	lsls r0, 6
	str r0, [r1, 0x4]
	movs r0, 0
	bx lr
	thumb_func_end sub_80B66B0

	thumb_func_start sub_80B66BC
sub_80B66BC:
	movs r0, 0x1
	negs r0, r0
	bx lr
	thumb_func_end sub_80B66BC

	thumb_func_start nullsub_213
nullsub_213:
	bx lr
	thumb_func_end nullsub_213

	thumb_func_start sub_80B66C8
sub_80B66C8:
	push {r4,r5,lr}
	adds r2, r0, 0
	adds r3, r1, 0
	cmp r2, 0
	beq _080B66E6
	movs r4, 0x11
	movs r5, 0
	adds r0, r4, 0
	adds r1, r5, 0
	swi 0xAB
	adds r5, r0, 0
	adds r4, r5, 0
	str r4, [r2]
	movs r0, 0
	str r0, [r2, 0x4]
_080B66E6:
	cmp r3, 0
	beq _080B66F0
	movs r0, 0
	str r0, [r3]
	str r0, [r3, 0x4]
_080B66F0:
	movs r0, 0
	pop {r4,r5,pc}
	thumb_func_end sub_80B66C8

	thumb_func_start sub_80B66F4
sub_80B66F4:
	push {r4,r5,lr}
	adds r2, r0, 0
	movs r4, 0x10
	movs r5, 0
	adds r0, r4, 0
	adds r1, r5, 0
	swi 0xAB
	adds r3, r0, 0
	cmp r2, 0
	beq _080B6712
	str r3, [r2]
	movs r0, 0
	str r0, [r2, 0x4]
	str r0, [r2, 0x8]
	str r0, [r2, 0xC]
_080B6712:
	adds r0, r3, 0
	pop {r4,r5,pc}
	thumb_func_end sub_80B66F4

	thumb_func_start sub_80B6718
sub_80B6718:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	ldr r4, _080B6744
	movs r3, 0
	str r3, [r4]
	bl _write
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B673E
	ldr r0, [r4]
	cmp r0, 0
	beq _080B673E
	str r0, [r5]
_080B673E:
	adds r0, r1, 0
	pop {r4,r5,pc}
	.align 2, 0
_080B6744: .4byte gUnknown_203B034
	thumb_func_end sub_80B6718

	thumb_func_start sub_80B6748
sub_80B6748:
	push {r4,lr}
	muls r1, r2
	bl sub_80B53B4
	adds r4, r0, 0
	cmp r4, 0
	bne _080B675A
	movs r0, 0
	b _080B679E
_080B675A:
	adds r0, r4, 0
	subs r0, 0x8
	ldr r0, [r0, 0x4]
	movs r1, 0x4
	negs r1, r1
	ands r0, r1
	subs r2, r0, 0x4
	cmp r2, 0x24
	bhi _080B6794
	adds r1, r4, 0
	cmp r2, 0x13
	bls _080B678A
	movs r0, 0
	stm r1!, {r0}
	str r0, [r4, 0x4]
	adds r1, 0x4
	cmp r2, 0x1B
	bls _080B678A
	stm r1!, {r0}
	stm r1!, {r0}
	cmp r2, 0x23
	bls _080B678A
	stm r1!, {r0}
	stm r1!, {r0}
_080B678A:
	movs r0, 0
	stm r1!, {r0}
	stm r1!, {r0}
	str r0, [r1]
	b _080B679C
_080B6794:
	adds r0, r4, 0
	movs r1, 0
	bl memset
_080B679C:
	adds r0, r4, 0
_080B679E:
	pop {r4,pc}
	thumb_func_end sub_80B6748

	thumb_func_start sub_80B67A0
sub_80B67A0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	ldr r4, _080B67C8
	movs r1, 0
	str r1, [r4]
	bl sub_80B6624
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B67C2
	ldr r0, [r4]
	cmp r0, 0
	beq _080B67C2
	str r0, [r5]
_080B67C2:
	adds r0, r1, 0
	pop {r4,r5,pc}
	.align 2, 0
_080B67C8: .4byte gUnknown_203B034
	thumb_func_end sub_80B67A0

	thumb_func_start sub_80B67CC
sub_80B67CC:
	ldr r0, _080B67D4
	ldr r0, [r0]
	bx lr
	.align 2, 0
_080B67D4: .4byte gUnknown_203B7A8
	thumb_func_end sub_80B67CC

	thumb_func_start sub_80B67D8
sub_80B67D8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	ldr r4, _080B6800
	movs r2, 0
	str r2, [r4]
	bl sub_80B66B0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B67FC
	ldr r0, [r4]
	cmp r0, 0
	beq _080B67FC
	str r0, [r5]
_080B67FC:
	adds r0, r1, 0
	pop {r4,r5,pc}
	.align 2, 0
_080B6800: .4byte gUnknown_203B034
	thumb_func_end sub_80B67D8

	thumb_func_start abort
abort:
	mov r12, r3
	mov r3, r8
	push {r3}
	mov r3, r12
	movs r2, 0x18
	ldr r3, _080B6820
	adds r0, r2, 0
	adds r1, r3, 0
	swi 0xAB
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_080B6820: .4byte 0x00020022
	thumb_func_end abort

	thumb_func_start isatty
isatty:
	movs r0, 0x1
	bx lr
	thumb_func_end isatty

	thumb_func_start alarm
alarm:
	bx lr
	thumb_func_end alarm

	thumb_func_start sub_80B682C
sub_80B682C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	ldr r4, _080B6858
	movs r3, 0
	str r3, [r4]
	bl sub_80B64C0
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B6852
	ldr r0, [r4]
	cmp r0, 0
	beq _080B6852
	str r0, [r5]
_080B6852:
	adds r0, r1, 0
	pop {r4,r5,pc}
	.align 2, 0
_080B6858: .4byte gUnknown_203B034
	thumb_func_end sub_80B682C

	thumb_func_start sub_80B685C
sub_80B685C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r2, r3, 0
	ldr r4, _080B6888
	movs r3, 0
	str r3, [r4]
	bl sub_80B63F4
	adds r1, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _080B6882
	ldr r0, [r4]
	cmp r0, 0
	beq _080B6882
	str r0, [r5]
_080B6882:
	adds r0, r1, 0
	pop {r4,r5,pc}
	.align 2, 0
_080B6888: .4byte gUnknown_203B034
	thumb_func_end sub_80B685C

	thumb_func_start sub_80B688C
sub_80B688C:
	cmp r1, 0
	beq _080B68FA
	movs r3, 0x1
	movs r2, 0
	push {r4}
	cmp r0, r1
	bcc _080B68F4
	movs r4, 0x1
	lsls r4, 28
_080B689E:
	cmp r1, r4
	bcs _080B68AC
	cmp r1, r0
	bcs _080B68AC
	lsls r1, 4
	lsls r3, 4
	b _080B689E
_080B68AC:
	lsls r4, 3
_080B68AE:
	cmp r1, r4
	bcs _080B68BC
	cmp r1, r0
	bcs _080B68BC
	lsls r1, 1
	lsls r3, 1
	b _080B68AE
_080B68BC:
	cmp r0, r1
	bcc _080B68C4
	subs r0, r1
	orrs r2, r3
_080B68C4:
	lsrs r4, r1, 1
	cmp r0, r4
	bcc _080B68D0
	subs r0, r4
	lsrs r4, r3, 1
	orrs r2, r4
_080B68D0:
	lsrs r4, r1, 2
	cmp r0, r4
	bcc _080B68DC
	subs r0, r4
	lsrs r4, r3, 2
	orrs r2, r4
_080B68DC:
	lsrs r4, r1, 3
	cmp r0, r4
	bcc _080B68E8
	subs r0, r4
	lsrs r4, r3, 3
	orrs r2, r4
_080B68E8:
	cmp r0, 0
	beq _080B68F4
	lsrs r3, 4
	beq _080B68F4
	lsrs r1, 4
	b _080B68BC
_080B68F4:
	adds r0, r2, 0
	pop {r4}
	mov pc, lr
_080B68FA:
	push {lr}
	bl __div0
	movs r0, 0
	pop {pc}
	thumb_func_end sub_80B688C

	.align 2, 0 @ Don't pad with nop.
