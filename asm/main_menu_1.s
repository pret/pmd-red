        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8035D80
sub_8035D80:
	ldr r1, _08035D90
	ldr r2, [r1]
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2, 0x30]
	str r1, [r2, 0x34]
	bx lr
	.align 2, 0
_08035D90: .4byte gUnknown_203B348
	thumb_func_end sub_8035D80

	thumb_func_start sub_8035D94
sub_8035D94:
	ldr r0, _08035D9C
	ldr r0, [r0]
	adds r0, 0x30
	bx lr
	.align 2, 0
_08035D9C: .4byte gUnknown_203B348
	thumb_func_end sub_8035D94

	thumb_func_start sub_8035DA0
sub_8035DA0:
	ldr r2, _08035DB0
	ldr r0, [r2]
	adds r0, 0x30
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	str r1, [r0, 0x34]
	bx lr
	.align 2, 0
_08035DB0: .4byte gUnknown_203B348
	thumb_func_end sub_8035DA0

	thumb_func_start sub_8035DB4
sub_8035DB4:
	push {lr}
	movs r1, 0x8
	subs r0, 0x13
	cmp r0, 0x7
	bhi _08035E0A
	lsls r0, 2
	ldr r1, _08035DC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08035DC8: .4byte _08035DCC
	.align 2, 0
_08035DCC:
	.4byte _08035DEC
	.4byte _08035DF0
	.4byte _08035DF4
	.4byte _08035DF8
	.4byte _08035DFC
	.4byte _08035E00
	.4byte _08035E04
	.4byte _08035E08
_08035DEC:
	movs r1, 0
	b _08035E0A
_08035DF0:
	movs r1, 0x1
	b _08035E0A
_08035DF4:
	movs r1, 0x2
	b _08035E0A
_08035DF8:
	movs r1, 0x3
	b _08035E0A
_08035DFC:
	movs r1, 0x4
	b _08035E0A
_08035E00:
	movs r1, 0x5
	b _08035E0A
_08035E04:
	movs r1, 0x6
	b _08035E0A
_08035E08:
	movs r1, 0x7
_08035E0A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_8035DB4

        thumb_func_start DrawMainMenu
DrawMainMenu:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, _08035EB8
	ldr r0, [r5]
	cmp r0, 0
	bne _08035E34
	movs r4, 0xD4
	lsls r4, 1
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
_08035E34:
	mov r12, r5
	movs r0, 0xA2
	lsls r0, 1
	mov r8, r0
	ldr r4, _08035EBC
	movs r3, 0
	movs r2, 0x3
_08035E42:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08035E42
	bl ResetUnusedInputStruct
	ldr r4, _08035EB8
	ldr r0, [r4]
	movs r6, 0xA2
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl SetMainMenuItems
	ldr r0, [r4]
	movs r7, 0xD2
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl SetMainMenuText
	lsls r0, 24
	cmp r0, 0
	beq _08035E9A
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
_08035E9A:
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035EB8: .4byte gUnknown_203B34C
_08035EBC: .4byte gUnknown_80E59C8
	thumb_func_end DrawMainMenu

	thumb_func_start CleanMainMenu
CleanMainMenu:
	push {r4,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08035EE8
	ldr r0, [r4]
	cmp r0, 0
	beq _08035EE0
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08035EE0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035EE8: .4byte gUnknown_203B34C
	thumb_func_end CleanMainMenu

	thumb_func_start UpdateMainMenu
UpdateMainMenu:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, _08035F64
	str r6, [sp]
	ldr r4, _08035F68
	ldr r0, [r4]
	ldr r5, [r0]
	cmp r5, 0xC
	beq _08035FB8
	cmp r5, 0xC
	bls _08035F04
	b _0803601A
_08035F04:
	cmp r5, 0x1
	beq _08035F0A
	b _0803601A
_08035F0A:
	adds r0, 0xA4
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x4
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08035F28
	ldr r0, [r4]
	adds r0, 0x4
	mov r1, sp
	bl sub_8013114
_08035F28:
	bl SetMainMenuText
	lsls r0, 24
	cmp r0, 0
	beq _08035F4A
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
_08035F4A:
	ldr r1, [sp]
	cmp r1, 0xC
	beq _08035FA8
	cmp r1, 0xC
	bhi _08035F6C
	cmp r1, 0x3
	beq _08035FAC
	cmp r1, 0x3
	bcc _0803601A
	cmp r1, 0x6
	bcc _0803601A
	b _08035FAC
	.align 2, 0
_08035F64: .4byte 0x0000ffdc
_08035F68: .4byte gUnknown_203B34C
_08035F6C:
	cmp r1, r6
	beq _08035FF2
	cmp r1, r6
	bhi _08035F7A
	cmp r1, 0x10
	bhi _0803601A
	b _08035FAC
_08035F7A:
	ldr r0, _08035FA4
	cmp r1, r0
	bne _0803601A
	ldr r0, [r4]
	str r5, [r0]
	str r6, [sp]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
	b _0803601A
	.align 2, 0
_08035FA4: .4byte 0x0000ffdd
_08035FA8:
	bl sub_8035DA0
_08035FAC:
	ldr r1, _08035FB4
	ldr r0, [sp]
	str r0, [r1]
	b _0803601A
	.align 2, 0
_08035FB4: .4byte gUnknown_203B350
_08035FB8:
	adds r0, 0x54
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08035FCE
	ldr r0, [r4]
	adds r0, 0x54
	mov r1, sp
	bl sub_8013114
_08035FCE:
	ldr r1, [sp]
	cmp r1, 0x12
	beq _08036008
	cmp r1, 0x12
	bhi _08035FDE
	cmp r1, 0x11
	beq _08035FFC
	b _0803601A
_08035FDE:
	cmp r1, r6
	beq _08036018
	ldr r0, _08035FF8
	cmp r1, r0
	bne _0803601A
	bl sub_803623C
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
_08035FF2:
	str r6, [sp]
	b _0803601A
	.align 2, 0
_08035FF8: .4byte 0x0000ffdd
_08035FFC:
	ldr r0, _08036004
	str r1, [r0]
	str r5, [sp]
	b _0803601A
	.align 2, 0
_08036004: .4byte gUnknown_203B354
_08036008:
	ldr r0, _08036014
	str r1, [r0]
	movs r0, 0x14
	str r0, [sp]
	b _0803601A
	.align 2, 0
_08036014: .4byte gUnknown_203B354
_08036018:
	str r1, [sp]
_0803601A:
	ldr r0, [sp]
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end UpdateMainMenu

	thumb_func_start SetMainMenuText
SetMainMenuText:
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r6, _08036048
	ldr r2, [r6]
	ldr r0, [r2, 0x8]
	movs r3, 0x30
	ldrsh r1, [r2, r3]
	lsls r1, 3
	adds r1, r0
	ldr r5, [r1, 0x4]
	movs r0, 0xD2
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, r5
	bne _0803604C
	movs r0, 0
	b _08036226
	.align 2, 0
_08036048: .4byte gUnknown_203B34C
_0803604C:
	str r5, [r1]
	movs r4, 0xA2
	lsls r4, 1
	adds r0, r2, r4
	movs r1, 0x2
	bl sub_8035CC0
	ldr r0, [r6]
	adds r0, r4
	movs r1, 0x3
	bl sub_8035CC0
	subs r0, r5, 0x3
	cmp r0, 0xD
	bls _0803606C
	b _08036224
_0803606C:
	lsls r0, 2
	ldr r1, _08036078
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036078: .4byte _0803607C
	.align 2, 0
_0803607C:
	.4byte _08036114
	.4byte _08036224
	.4byte _08036224
	.4byte _080360F4
	.4byte _08036134
	.4byte _08036154
	.4byte _08036224
	.4byte _08036174
	.4byte _08036194
	.4byte _080361B4
	.4byte _080360D4
	.4byte _080361D4
	.4byte _080360B4
	.4byte _08036204
_080360B4:
	ldr r0, _080360C8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080360CC
	ldr r2, _080360D0
	b _080361E4
	.align 2, 0
_080360C8: .4byte gUnknown_203B34C
_080360CC: .4byte gUnknown_80E5CB4
_080360D0: .4byte gUnknown_80E6030
_080360D4:
	ldr r0, _080360E8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _080360EC
	ldr r2, _080360F0
	b _080361E4
	.align 2, 0
_080360E8: .4byte gUnknown_203B34C
_080360EC: .4byte gUnknown_80E5CB4
_080360F0: .4byte gUnknown_80E5F80
_080360F4:
	ldr r0, _08036108
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803610C
	ldr r2, _08036110
	b _080361E4
	.align 2, 0
_08036108: .4byte gUnknown_203B34C
_0803610C: .4byte gUnknown_80E5CB4
_08036110: .4byte gUnknown_80E5F1C
_08036114:
	ldr r0, _08036128
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _0803612C
	ldr r2, _08036130
	b _080361E4
	.align 2, 0
_08036128: .4byte gUnknown_203B34C
_0803612C: .4byte gUnknown_80E5CB4
_08036130: .4byte gUnknown_80E5CCC
_08036134:
	ldr r0, _08036148
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803614C
	ldr r2, _08036150
	b _080361E4
	.align 2, 0
_08036148: .4byte gUnknown_203B34C
_0803614C: .4byte gUnknown_80E5CB4
_08036150: .4byte gUnknown_80E5DA0
_08036154:
	ldr r0, _08036168
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _0803616C
	ldr r2, _08036170
	b _080361E4
	.align 2, 0
_08036168: .4byte gUnknown_203B34C
_0803616C: .4byte gUnknown_80E5CB4
_08036170: .4byte gUnknown_80E5DF0
_08036174:
	ldr r0, _08036188
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803618C
	ldr r2, _08036190
	b _080361E4
	.align 2, 0
_08036188: .4byte gUnknown_203B34C
_0803618C: .4byte gUnknown_80E5CB4
_08036190: .4byte gUnknown_80E5D0C
_08036194:
	ldr r0, _080361A8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _080361AC
	ldr r2, _080361B0
	b _080361E4
	.align 2, 0
_080361A8: .4byte gUnknown_203B34C
_080361AC: .4byte gUnknown_80E5CB4
_080361B0: .4byte gUnknown_80E5E5C
_080361B4:
	ldr r0, _080361C8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080361CC
	ldr r2, _080361D0
	b _080361E4
	.align 2, 0
_080361C8: .4byte gUnknown_203B34C
_080361CC: .4byte gUnknown_80E5CB4
_080361D0: .4byte gUnknown_80E5EBC
_080361D4:
	ldr r0, _080361F8
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r3, 0xA2
	lsls r3, 1
	adds r1, r3
	ldr r3, _080361FC
	ldr r2, _08036200
_080361E4:
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x2
	bl SetMenuItems
	b _08036224
	.align 2, 0
_080361F8: .4byte gUnknown_203B34C
_080361FC: .4byte gUnknown_80E5CB4
_08036200: .4byte gUnknown_80E5FCC
_08036204:
	ldr r0, _08036230
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _08036234
	ldr r2, _08036238
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x2
	bl SetMenuItems
_08036224:
	movs r0, 0x1
_08036226:
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08036230: .4byte gUnknown_203B34C
_08036234: .4byte gUnknown_80E5CB4
_08036238: .4byte gUnknown_80E5D48
	thumb_func_end SetMainMenuText

	thumb_func_start sub_803623C
sub_803623C:
	push {r4,lr}
	ldr r4, _08036288
	ldr r0, [r4]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	bl sub_8035CC0
	bl SetMainMenuItems
	ldr r0, [r4]
	movs r1, 0xD2
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	bl SetMainMenuText
	lsls r0, 24
	cmp r0, 0
	beq _08036276
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0x2
	movs r2, 0
	bl sub_8035CF4
_08036276:
	ldr r0, [r4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036288: .4byte gUnknown_203B34C
	thumb_func_end sub_803623C

	thumb_func_start SetMainMenuItems
SetMainMenuItems:
	push {r4,lr}
	sub sp, 0x10
	bl sub_8011C34
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803629E
	b _080363A4
_0803629E:
	movs r0, 0x1
	bl sub_8095324
	cmp r0, 0
	bne _08036344
	movs r0, 0x7
	bl sub_8095324
	cmp r0, 0
	beq _080362FC
	bl sub_803D0D8
	lsls r0, 24
	cmp r0, 0
	beq _080362DC
	ldr r0, _080362D0
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080362D4
	ldr r2, _080362D8
	b _0803637C
	.align 2, 0
_080362D0: .4byte gUnknown_203B34C
_080362D4: .4byte gUnknown_80E5A78
_080362D8: .4byte gUnknown_80E5C18
_080362DC:
	ldr r0, _080362F0
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080362F4
	ldr r2, _080362F8
	b _0803637C
	.align 2, 0
_080362F0: .4byte gUnknown_203B34C
_080362F4: .4byte gUnknown_80E5BC4
_080362F8: .4byte gUnknown_80E5BDC
_080362FC:
	bl sub_803D0D8
	lsls r0, 24
	cmp r0, 0
	beq _08036324
	ldr r0, _08036318
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803631C
	ldr r2, _08036320
	b _0803637C
	.align 2, 0
_08036318: .4byte gUnknown_203B34C
_0803631C: .4byte gUnknown_80E5A78
_08036320: .4byte gUnknown_80E5AFC
_08036324:
	ldr r0, _08036338
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _0803633C
	ldr r2, _08036340
	b _0803637C
	.align 2, 0
_08036338: .4byte gUnknown_203B34C
_0803633C: .4byte gUnknown_80E5A60
_08036340: .4byte gUnknown_80E5A90
_08036344:
	bl sub_803D0D8
	lsls r0, 24
	cmp r0, 0
	beq _0803636C
	ldr r0, _08036360
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _08036364
	ldr r2, _08036368
	b _0803637C
	.align 2, 0
_08036360: .4byte gUnknown_203B34C
_08036364: .4byte gUnknown_80E5A78
_08036368: .4byte gUnknown_80E5B8C
_0803636C:
	ldr r0, _08036394
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _08036398
	ldr r2, _0803639C
_0803637C:
	str r2, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	ldr r2, _080363A0
	ldr r2, [r2]
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _080363C8
	.align 2, 0
_08036394: .4byte gUnknown_203B34C
_08036398: .4byte gUnknown_80E5B34
_0803639C: .4byte gUnknown_80E5B4C
_080363A0: .4byte gUnknown_203B350
_080363A4:
	ldr r0, _080363D0
	ldr r1, [r0]
	adds r0, r1, 0x4
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r3, _080363D4
	ldr r2, _080363D8
	str r2, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	ldr r2, _080363DC
	ldr r2, [r2]
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_080363C8:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080363D0: .4byte gUnknown_203B34C
_080363D4: .4byte gUnknown_80E59E0
_080363D8: .4byte gUnknown_80E59F8
_080363DC: .4byte gUnknown_203B350
	thumb_func_end SetMainMenuItems

	thumb_func_start sub_80363E0
sub_80363E0:
	push {lr}
	ldr r0, _080363F4
	ldr r0, [r0]
	cmp r0, 0
	beq _080363F8
	ldr r0, [r0]
	cmp r0, 0xC
	beq _080363F8
	movs r0, 0x1
	b _080363FA
	.align 2, 0
_080363F4: .4byte gUnknown_203B34C
_080363F8:
	movs r0, 0
_080363FA:
	pop {r1}
	bx r1
	thumb_func_end sub_80363E0

        .align 2,0
