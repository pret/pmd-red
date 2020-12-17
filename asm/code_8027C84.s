        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8027CA0
sub_8027CA0:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08027CFA
	lsls r0, 2
	ldr r1, _08027CB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027CB8: .4byte _08027CBC
	.align 2, 0
_08027CBC:
	.4byte _08027CFA
	.4byte _08027CFA
	.4byte _08027CF0
	.4byte _08027CD0
	.4byte _08027CD0
_08027CD0:
	bl sub_801F194
	ldr r1, _08027CEC
	ldr r1, [r1]
	str r0, [r1, 0x20]
	lsls r0, 3
	adds r0, r1, r0
	ldrh r0, [r0, 0x2A]
	strh r0, [r1, 0x24]
	movs r0, 0x10
	bl sub_8027184
	b _08027CFA
	.align 2, 0
_08027CEC: .4byte gUnknown_203B2BC
_08027CF0:
	bl sub_801F214
	movs r0, 0x2
	bl sub_8027184
_08027CFA:
	pop {r0}
	bx r0
	thumb_func_end sub_8027CA0

	thumb_func_start sub_8027D00
sub_8027D00:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08027D18
	cmp r0, 0x3
	bhi _08027D18
	bl sub_801F8D0
	movs r0, 0xF
	bl sub_8027184
_08027D18:
	pop {r0}
	bx r0
	thumb_func_end sub_8027D00

	thumb_func_start sub_8027D1C
sub_8027D1C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08027D34
	ldr r0, _08027D3C
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_8027184
_08027D34:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08027D3C: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027D1C

	thumb_func_start sub_8027D40
sub_8027D40:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8008C54
	adds r0, r6, 0
	bl sub_80073B8
	add r4, sp, 0x10
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8090B64
	movs r5, 0
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	strb r5, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08027D94
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_8090E14
	ldr r2, _08027D98
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x3
	adds r3, r6, 0
	bl sub_8014FF0
	adds r0, r6, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08027D94: .4byte gUnknown_202DE58
_08027D98: .4byte gUnknown_80DD958
	thumb_func_end sub_8027D40

	thumb_func_start sub_8027D9C
sub_8027D9C:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08027DC0
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08027DB0
	movs r2, 0x1
_08027DB0:
	cmp r2, 0
	beq _08027DC4
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08027DC4
_08027DC0:
	movs r0, 0
	b _08027DC6
_08027DC4:
	movs r0, 0x1
_08027DC6:
	pop {r1}
	bx r1
	thumb_func_end sub_8027D9C

	thumb_func_start sub_8027DCC
sub_8027DCC:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	beq _08027E0E
	bl sub_808D3F8
	cmp r0, r4
	beq _08027E0E
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _08027E0E
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _08027DF0
	movs r1, 0x1
_08027DF0:
	cmp r1, 0
	beq _08027E00
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08027E0E
_08027E00:
	adds r0, r4, 0
	bl sub_8027E18
	cmp r0, 0x3
	beq _08027E0E
	movs r0, 0x1
	b _08027E10
_08027E0E:
	movs r0, 0
_08027E10:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8027DCC

	thumb_func_start sub_8027E18
sub_8027E18:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	bne _08027E28
	movs r0, 0
	b _08027E46
_08027E28:
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08027E34
	movs r0, 0x1
	b _08027E46
_08027E34:
	adds r0, r4, 0
	bl sub_8027E4C
	lsls r0, 24
	cmp r0, 0
	bne _08027E44
	movs r0, 0x3
	b _08027E46
_08027E44:
	movs r0, 0x2
_08027E46:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8027E18

	thumb_func_start sub_8027E4C
sub_8027E4C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x28
	ldrb r0, [r4]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _08027E88
	ldrb r0, [r4]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08027E94
	ldr r0, _08027E8C
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	adds r1, r0
	ldr r0, _08027E90
	cmp r1, r0
	ble _08027EA8
_08027E88:
	movs r0, 0
	b _08027EAA
	.align 2, 0
_08027E8C: .4byte gUnknown_203B460
_08027E90: .4byte 0x000003e7
_08027E94:
	ldr r0, _08027EB0
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	ldr r0, _08027EB4
	cmp r1, r0
	bhi _08027E88
_08027EA8:
	movs r0, 0x1
_08027EAA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08027EB0: .4byte gUnknown_203B460
_08027EB4: .4byte 0x000003e6
	thumb_func_end sub_8027E4C

	thumb_func_start sub_8027EB8
sub_8027EB8:
	push {r4,lr}
	ldr r4, _08027ED4
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_8027E18
	cmp r0, 0x1
	beq _08027ED8
	cmp r0, 0x1
	bcc _08027F7C
	cmp r0, 0x2
	beq _08027F0C
	b _08027F7C
	.align 2, 0
_08027ED4: .4byte gUnknown_203B2BC
_08027ED8:
	ldr r0, _08027F08
	bl sub_8011988
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_8091274
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0x6
	bl sub_8027184
	b _08027F82
	.align 2, 0
_08027F08: .4byte 0x0000014d
_08027F0C:
	ldr r0, _08027F38
	bl sub_8011988
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08027F40
	ldr r0, _08027F3C
	ldr r1, [r0]
	ldr r2, [r4]
	ldrb r0, [r2, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	ldrb r2, [r2, 0x15]
	adds r0, r2
	b _08027F52
	.align 2, 0
_08027F38: .4byte 0x0000014d
_08027F3C: .4byte gUnknown_203B460
_08027F40:
	ldr r0, _08027F74
	ldr r1, [r0]
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
_08027F52:
	strh r0, [r1]
	ldr r1, _08027F78
	ldr r0, [r1]
	movs r2, 0
	strb r2, [r0, 0x14]
	ldr r0, [r1]
	strb r2, [r0, 0x15]
	ldr r1, [r1]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0x7
	bl sub_8027184
	b _08027F82
	.align 2, 0
_08027F74: .4byte gUnknown_203B460
_08027F78: .4byte gUnknown_203B2BC
_08027F7C:
	movs r0, 0x2
	bl sub_8027184
_08027F82:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027EB8

	thumb_func_start sub_8027F88
sub_8027F88:
	push {r4-r6,lr}
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08028050
	movs r4, 0xA9
	lsls r4, 3
	adds r0, r4, 0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	adds r2, r4, 0
	bl MemoryFill8
	ldr r1, [r5]
	ldr r2, _08028054
	adds r0, r1, r2
	movs r6, 0
	str r6, [r0]
	movs r3, 0x86
	lsls r3, 2
	adds r1, r3
	movs r0, 0xFF
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _08028058
	adds r0, r1
	ldr r1, _0802805C
	strh r1, [r0]
	ldr r0, _08028060
	movs r4, 0x98
	lsls r4, 1
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl sub_808D994
	adds r1, r0, 0
	ldr r0, _08028064
	bl strcpy
	adds r0, r4, 0
	bl sub_808DDD0
	ldr r2, [r5]
	movs r3, 0x84
	lsls r3, 3
	adds r1, r2, r3
	str r0, [r1]
	adds r3, 0x4
	adds r1, r2, r3
	ldr r0, [r0, 0x4]
	str r0, [r1]
	ldr r0, _08028068
	adds r2, r0
	strb r6, [r2]
	ldr r0, [r5]
	ldr r1, _0802806C
	adds r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	ldr r2, _08028070
	adds r0, r2
	strb r6, [r0]
	ldr r1, [r5]
	adds r3, 0x4
	adds r2, r1, r3
	movs r0, 0x2
	strh r0, [r2]
	ldr r0, _08028074
	adds r1, r0
	movs r0, 0x8
	strh r0, [r1]
	movs r2, 0
	movs r3, 0
	adds r1, r5, 0
_0802802E:
	ldr r0, [r5]
	adds r0, 0x8
	adds r0, r2
	strb r3, [r0]
	adds r2, 0x1
	cmp r2, 0x35
	ble _0802802E
	ldr r1, [r1]
	movs r0, 0x3D
	str r0, [r1]
	movs r0, 0
	bl sub_8028B04
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08028050: .4byte gUnknown_203B2C0
_08028054: .4byte 0x0000053c
_08028058: .4byte 0x00000544
_0802805C: .4byte 0x0000ffff
_08028060: .4byte gUnknown_202E5D8
_08028064: .4byte gUnknown_202DF98
_08028068: .4byte 0x0000042c
_0802806C: .4byte 0x0000042d
_08028070: .4byte 0x0000042e
_08028074: .4byte 0x0000042a
	thumb_func_end sub_8027F88

	thumb_func_start sub_8028078
sub_8028078:
	push {lr}
	ldr r0, _08028090
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x3C
	bls _08028086
	b _080282D4
_08028086:
	lsls r0, 2
	ldr r1, _08028094
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028090: .4byte gUnknown_203B2C0
_08028094: .4byte _08028098
	.align 2, 0
_08028098:
	.4byte _080282C4
	.4byte _080282C4
	.4byte _080282CA
	.4byte _080282D0
	.4byte _08028222
	.4byte _08028234
	.4byte _08028228
	.4byte _0802822E
	.4byte _0802823A
	.4byte _080281FE
	.4byte _08028272
	.4byte _08028278
	.4byte _0802828C
	.4byte _0802827E
	.4byte _0802828C
	.4byte _0802827E
	.4byte _0802828C
	.4byte _08028286
	.4byte _08028294
	.4byte _0802829A
	.4byte _080282B2
	.4byte _080282B8
	.4byte _080282BE
	.4byte _080282A0
	.4byte _080282A6
	.4byte _080282AC
	.4byte _08028240
	.4byte _08028248
	.4byte _0802824E
	.4byte _0802824E
	.4byte _0802825A
	.4byte _0802826C
	.4byte _08028260
	.4byte _08028266
	.4byte _08028254
	.4byte _08028204
	.4byte _0802820A
	.4byte _080282CA
	.4byte _08028210
	.4byte _08028216
	.4byte _0802821C
	.4byte _080281E0
	.4byte _080281F2
	.4byte _080281E6
	.4byte _080281EC
	.4byte _080281DA
	.4byte _080281D4
	.4byte _080281F8
	.4byte _080281CE
	.4byte _080281C2
	.4byte _080281AA
	.4byte _080281B0
	.4byte _080281B6
	.4byte _080281BC
	.4byte _080281C8
	.4byte _080281A4
	.4byte _0802819E
	.4byte _080282CA
	.4byte _08028192
	.4byte _08028198
	.4byte _0802818C
_0802818C:
	bl sub_8029B34
	b _080282D4
_08028192:
	bl sub_8029AD8
	b _080282D4
_08028198:
	bl sub_8029AF4
	b _080282D4
_0802819E:
	bl sub_8029A88
	b _080282D4
_080281A4:
	bl sub_8029AB0
	b _080282D4
_080281AA:
	bl sub_80297B8
	b _080282D4
_080281B0:
	bl sub_80297D4
	b _080282D4
_080281B6:
	bl sub_8029884
	b _080282D4
_080281BC:
	bl sub_8029944
	b _080282D4
_080281C2:
	bl sub_80299AC
	b _080282D4
_080281C8:
	bl sub_80299D8
	b _080282D4
_080281CE:
	bl sub_8029A6C
	b _080282D4
_080281D4:
	bl sub_8029A18
	b _080282D4
_080281DA:
	bl sub_80295A8
	b _080282D4
_080281E0:
	bl sub_8029668
	b _080282D4
_080281E6:
	bl sub_8029684
	b _080282D4
_080281EC:
	bl sub_8029740
	b _080282D4
_080281F2:
	bl sub_80295D8
	b _080282D4
_080281F8:
	bl sub_802979C
	b _080282D4
_080281FE:
	bl sub_8029358
	b _080282D4
_08028204:
	bl sub_8029374
	b _080282D4
_0802820A:
	bl sub_802939C
	b _080282D4
_08028210:
	bl sub_80293D8
	b _080282D4
_08028216:
	bl sub_80293F4
	b _080282D4
_0802821C:
	bl sub_802955C
	b _080282D4
_08028222:
	bl sub_80292A4
	b _080282D4
_08028228:
	bl sub_80292EC
	b _080282D4
_0802822E:
	bl sub_802933C
	b _080282D4
_08028234:
	bl sub_802958C
	b _080282D4
_0802823A:
	bl sub_8029208
	b _080282D4
_08028240:
	movs r0, 0x1
	bl sub_8028DE8
	b _080282D4
_08028248:
	bl sub_8028F80
	b _080282D4
_0802824E:
	bl sub_8028FC0
	b _080282D4
_08028254:
	bl sub_8028FDC
	b _080282D4
_0802825A:
	bl sub_80290D4
	b _080282D4
_08028260:
	bl sub_80290F0
	b _080282D4
_08028266:
	bl sub_80291AC
	b _080282D4
_0802826C:
	bl sub_8029044
	b _080282D4
_08028272:
	bl sub_8028CFC
	b _080282D4
_08028278:
	bl sub_8028D4C
	b _080282D4
_0802827E:
	movs r0, 0xA
	bl sub_8028DE8
	b _080282D4
_08028286:
	bl sub_8028E08
	b _080282D4
_0802828C:
	movs r0, 0x19
	bl sub_8028DE8
	b _080282D4
_08028294:
	bl sub_8028E24
	b _080282D4
_0802829A:
	bl sub_8028E54
	b _080282D4
_080282A0:
	bl sub_8028E84
	b _080282D4
_080282A6:
	bl sub_8028EAC
	b _080282D4
_080282AC:
	bl sub_8028ED4
	b _080282D4
_080282B2:
	bl sub_8028F04
	b _080282D4
_080282B8:
	bl sub_8028F30
	b _080282D4
_080282BE:
	bl sub_8028F58
	b _080282D4
_080282C4:
	bl sub_8028BF0
	b _080282D4
_080282CA:
	bl sub_8028CE0
	b _080282D4
_080282D0:
	movs r0, 0x3
	b _080282D6
_080282D4:
	movs r0, 0
_080282D6:
	pop {r1}
	bx r1
	thumb_func_end sub_8028078

	thumb_func_start sub_80282DC
sub_80282DC:
	ldr r1, _080282F4
	ldr r1, [r1]
	movs r3, 0x86
	lsls r3, 2
	adds r2, r1, r3
	ldrb r2, [r2]
	strb r2, [r0]
	ldr r0, _080282F8
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_080282F4: .4byte gUnknown_203B2C0
_080282F8: .4byte 0x0000053c
	thumb_func_end sub_80282DC

	thumb_func_start sub_80282FC
sub_80282FC:
	push {r4,lr}
	ldr r4, _08028340
	ldr r0, [r4]
	cmp r0, 0
	beq _08028338
	movs r1, 0x84
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	bl sub_8031E10
	bl sub_8023C60
	bl sub_803084C
	bl sub_80155F0
	bl sub_80310B4
	bl sub_8030DE4
	bl sub_802453C
_08028338:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028340: .4byte gUnknown_203B2C0
	thumb_func_end sub_80282FC

	thumb_func_start nullsub_130
nullsub_130:
	bx lr
	thumb_func_end nullsub_130

	thumb_func_start sub_8028348
sub_8028348:
	push {r4-r6,lr}
	sub sp, 0x14
	ldr r1, _08028368
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r6, r1, 0
	cmp r0, 0x3C
	bls _0802835C
	bl _08028AF2
_0802835C:
	lsls r0, 2
	ldr r1, _0802836C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028368: .4byte gUnknown_203B2C0
_0802836C: .4byte _08028370
	.align 2, 0
_08028370:
	.4byte _08028A84
	.4byte _08028AB4
	.4byte _08028AE0
	.4byte _08028AF2
	.4byte _08028650
	.4byte _08028660
	.4byte _08028678
	.4byte _08028AF2
	.4byte _08028802
	.4byte _08028640
	.4byte _0802890C
	.4byte _08028948
	.4byte _08028988
	.4byte _08028978
	.4byte _080289A0
	.4byte _08028990
	.4byte _080289B8
	.4byte _080289B0
	.4byte _080289C8
	.4byte _080289E8
	.4byte _08028A48
	.4byte _08028A58
	.4byte _08028A68
	.4byte _080289F8
	.4byte _08028A08
	.4byte _08028A18
	.4byte _08028850
	.4byte _08028860
	.4byte _08028868
	.4byte _08028878
	.4byte _08028890
	.4byte _080288A0
	.4byte _080288C6
	.4byte _08028AF2
	.4byte _08028888
	.4byte _08028790
	.4byte _08028AF2
	.4byte _080287C4
	.4byte _080287D4
	.4byte _080287DC
	.4byte _08028AF2
	.4byte _080285CC
	.4byte _080285DC
	.4byte _080288C6
	.4byte _08028AF2
	.4byte _080285AC
	.4byte _08028610
	.4byte _080285F8
	.4byte _08028600
	.4byte _0802856C
	.4byte _080284F4
	.4byte _0802850C
	.4byte _08028532
	.4byte _08028AF2
	.4byte _0802859C
	.4byte _080284B8
	.4byte _080284A8
	.4byte _080284EC
	.4byte _080284A0
	.4byte _08028464
	.4byte _08028490
_08028464:
	ldr r0, [r6]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r6]
	movs r2, 0x86
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8031D70
	b _08028AF2
_08028490:
	ldr r0, _0802849C
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_0802849C: .4byte gUnknown_80DDBA8
_080284A0:
	ldr r0, _080284A4
	b _08028A6A
	.align 2, 0
_080284A4: .4byte gUnknown_80DDBFC
_080284A8:
	ldr r0, _080284B4
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_080284B4: .4byte gUnknown_80DDC30
_080284B8:
	ldr r0, [r6]
	ldr r2, _080284D0
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0xE
	bne _080284C6
	b _08028AF2
_080284C6:
	cmp r0, 0xE
	bhi _080284D4
	cmp r0, 0xD
	beq _080284DA
	b _08028AF2
	.align 2, 0
_080284D0: .4byte 0x00000534
_080284D4:
	cmp r0, 0x10
	bls _080284DA
	b _08028AF2
_080284DA:
	ldr r0, _080284E8
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_080284E8: .4byte gUnknown_80DDC70
_080284EC:
	ldr r0, _080284F0
	b _08028A6A
	.align 2, 0
_080284F0: .4byte gUnknown_80DDC30
_080284F4:
	ldr r0, _08028504
	ldr r3, _08028508
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08028AF2
	.align 2, 0
_08028504: .4byte gUnknown_80DDCBC
_08028508: .4byte 0x00000101
_0802850C:
	bl sub_8023CE8
	cmp r0, 0
	beq _08028516
	b _08028AF2
_08028516:
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	movs r3, 0x9
	bl sub_8023868
	b _08028AF2
_08028532:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _08028564
	ldr r2, _08028568
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_8023DA4
	b _080288F6
	.align 2, 0
_08028564: .4byte gUnknown_80DDAE4
_08028568: .4byte gUnknown_80DDAFC
_0802856C:
	ldr r0, _08028594
	ldr r3, _08028598
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xA
	bl sub_8014248
	b _08028AF2
	.align 2, 0
_08028594: .4byte gUnknown_80DDD2C
_08028598: .4byte gUnknown_80DDAA0
_0802859C:
	ldr r0, _080285A4
	ldr r3, _080285A8
	b _08028A1C
	.align 2, 0
_080285A4: .4byte gUnknown_80DDD88
_080285A8: .4byte gUnknown_80DDA80
_080285AC:
	ldr r0, _080285C4
	ldr r3, _080285C8
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	b _08028A2E
	.align 2, 0
_080285C4: .4byte gUnknown_80DDDBC
_080285C8: .4byte gUnknown_80DDA64
_080285CC:
	ldr r0, _080285D8
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_080285D8: .4byte gUnknown_80DDDD8
_080285DC:
	bl sub_8030894
	cmp r0, 0
	beq _080285E6
	b _08028AF2
_080285E6:
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x4
	b _080288BA
_080285F8:
	ldr r0, _080285FC
	b _08028A6A
	.align 2, 0
_080285FC: .4byte gUnknown_80DDE20
_08028600:
	ldr r0, _0802860C
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_0802860C: .4byte gUnknown_80DDE58
_08028610:
	ldr r0, _08028638
	ldr r3, _0802863C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x11
	bl sub_8014248
	b _08028AF2
	.align 2, 0
_08028638: .4byte gUnknown_80DDEC0
_0802863C: .4byte gUnknown_80DDB60
_08028640:
	ldr r0, _0802864C
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_0802864C: .4byte gUnknown_80DDF2C
_08028650:
	ldr r0, _08028658
	ldr r3, _0802865C
	b _08028A1C
	.align 2, 0
_08028658: .4byte gUnknown_80DDFB8
_0802865C: .4byte gUnknown_80DDA48
_08028660:
	movs r0, 0
	bl nullsub_23
	ldr r0, _08028674
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	b _08028AF2
	.align 2, 0
_08028674: .4byte gUnknown_80DE01C
_08028678:
	ldr r1, [r6]
	movs r0, 0
	str r0, [r1, 0x44]
	bl sub_8011830
	ldr r0, [r6]
	ldr r0, [r0, 0x40]
	bl sub_8037B28
	adds r4, r0, 0
	ldr r0, [r6]
	str r4, [r0, 0x44]
	cmp r4, 0
	bne _0802878A
	ldr r1, [r0, 0x40]
	cmp r1, 0x3
	beq _080286A0
	cmp r1, 0x4
	beq _080286C2
	b _08028748
_080286A0:
	adds r0, 0x48
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	adds r0, 0x78
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	b _08028740
_080286C2:
	adds r0, 0xA8
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r0, [r6]
	movs r5, 0x98
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x88
	bl MemoryFill8
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xE0
	strh r4, [r0]
	movs r2, 0xB4
	lsls r2, 1
	adds r0, r1, r2
	strh r4, [r0]
	movs r3, 0x86
	lsls r3, 2
	adds r0, r1, r3
	ldrb r0, [r0]
	bl sub_8095228
	ldr r1, [r6]
	adds r1, 0xA8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	ldr r4, _08028760
	adds r3, r2, r4
	movs r0, 0
	ldrsh r1, [r3, r0]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08028736
	adds r0, r2, 0
	adds r0, 0xD8
	ldr r1, _08028764
	ldr r1, [r1]
	movs r2, 0
	ldrsh r3, [r3, r2]
	movs r2, 0x58
	muls r2, r3
	adds r1, r2
	movs r2, 0x58
	bl memcpy
_08028736:
	ldr r2, [r6]
	ldr r0, [r2, 0x40]
	adds r1, r2, 0
	adds r1, 0xA8
	adds r2, r5
_08028740:
	bl sub_8037D64
	ldr r1, [r6]
	str r0, [r1, 0x44]
_08028748:
	ldr r4, _08028768
	ldr r2, [r4]
	ldr r0, [r2, 0x44]
	cmp r0, 0
	bne _0802878A
	ldr r0, [r2, 0x40]
	cmp r0, 0x3
	beq _0802876C
	cmp r0, 0x4
	beq _08028776
	b _0802878A
	.align 2, 0
_08028760: .4byte 0x00000544
_08028764: .4byte gUnknown_203B45C
_08028768: .4byte gUnknown_203B2C0
_0802876C:
	adds r1, r2, 0
	adds r1, 0x48
	adds r2, 0x78
	movs r0, 0x3
	b _08028782
_08028776:
	adds r1, r2, 0
	adds r1, 0xA8
	movs r3, 0x98
	lsls r3, 1
	adds r2, r3
	movs r0, 0x4
_08028782:
	bl sub_80381F4
	ldr r1, [r4]
	str r0, [r1, 0x44]
_0802878A:
	bl sub_8011854
	b _08028AF2
_08028790:
	ldr r0, [r6]
	ldr r4, _080287A8
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0xE
	bne _0802879E
	b _08028AF2
_0802879E:
	cmp r0, 0xE
	bhi _080287AC
	cmp r0, 0xD
	beq _080287B2
	b _08028AF2
	.align 2, 0
_080287A8: .4byte 0x00000534
_080287AC:
	cmp r0, 0x10
	bls _080287B2
	b _08028AF2
_080287B2:
	ldr r0, _080287C0
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_080287C0: .4byte gUnknown_80DE06C
_080287C4:
	ldr r0, _080287D0
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_080287D0: .4byte gUnknown_80DE0C0
_080287D4:
	ldr r0, _080287D8
	b _08028A6A
	.align 2, 0
_080287D8: .4byte gUnknown_80DE124
_080287DC:
	ldr r0, [r6]
	movs r1, 0xEF
	lsls r1, 2
	adds r0, r1
	bl sub_8006518
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r6]
	adds r1, 0x8
	movs r0, 0x4
	bl sub_80151C0
	b _08028AF2
_08028802:
	ldr r4, [r6]
	movs r2, 0xA7
	lsls r2, 3
	adds r0, r4, r2
	ldr r2, [r0]
	cmp r2, 0
	beq _08028816
	cmp r2, 0x2
	beq _08028824
	b _08028AF2
_08028816:
	ldr r0, _0802881C
	ldr r3, _08028820
	b _0802882A
	.align 2, 0
_0802881C: .4byte gUnknown_80DE178
_08028820: .4byte gUnknown_80DDB24
_08028824:
	ldr r0, _08028848
	ldr r3, _0802884C
	movs r2, 0
_0802882A:
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r4, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xD
	bl sub_8014248
	b _08028AF2
	.align 2, 0
_08028848: .4byte gUnknown_80DE1B4
_0802884C: .4byte gUnknown_80DDB24
_08028850:
	ldr r0, _0802885C
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_0802885C: .4byte gUnknown_80DE1E4
_08028860:
	ldr r0, _08028864
	b _08028A6A
	.align 2, 0
_08028864: .4byte gUnknown_80DE280
_08028868:
	ldr r0, _08028874
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_08028874: .4byte gUnknown_80DE2B0
_08028878:
	ldr r0, _08028884
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_08028884: .4byte gUnknown_80DE368
_08028888:
	ldr r0, _0802888C
	b _08028A1A
	.align 2, 0
_0802888C: .4byte gUnknown_80DDDBC
_08028890:
	ldr r0, _0802889C
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_0802889C: .4byte gUnknown_80DE430
_080288A0:
	bl sub_8030894
	cmp r0, 0
	beq _080288AA
	b _08028AF2
_080288AA:
	bl sub_8004914
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	movs r0, 0x2
_080288BA:
	movs r1, 0
	movs r2, 0
	movs r3, 0x6
	bl sub_80306A8
	b _08028AF2
_080288C6:
	ldr r0, [r6]
	movs r4, 0xD7
	lsls r4, 2
	adds r0, r4
	bl sub_8006518
	ldr r1, [r6]
	movs r5, 0x87
	lsls r5, 2
	adds r0, r1, r5
	adds r1, r4
	ldr r3, _08028904
	ldr r2, _08028908
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0x3
	bl SetMenuItems
	bl sub_803092C
_080288F6:
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8035CF4
	b _08028AF2
	.align 2, 0
_08028904: .4byte gUnknown_80DDACC
_08028908: .4byte gUnknown_80DDAFC
_0802890C:
	bl sub_8095350
	ldr r1, _0802893C
	ldr r1, [r1]
	movs r3, 0xA8
	lsls r3, 3
	adds r2, r1, r3
	str r0, [r2]
	movs r4, 0xA7
	lsls r4, 3
	adds r1, r4
	ldr r1, [r1]
	cmp r1, 0x6
	beq _08028940
	cmp r1, 0x6
	bls _0802892E
	b _08028AF2
_0802892E:
	cmp r1, 0x5
	beq _08028934
	b _08028AF2
_08028934:
	movs r0, 0x2
	bl sub_8030F58
	b _08028AF2
	.align 2, 0
_0802893C: .4byte gUnknown_203B2C0
_08028940:
	movs r0, 0x4
	bl sub_8030F58
	b _08028AF2
_08028948:
	ldr r0, _08028970
	ldr r3, _08028974
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _08028AF2
	.align 2, 0
_08028970: .4byte gUnknown_80DE48C
_08028974: .4byte gUnknown_80DD9EC
_08028978:
	ldr r0, _08028984
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_08028984: .4byte gUnknown_80DE4B8
_08028988:
	ldr r0, _0802898C
	b _08028A6A
	.align 2, 0
_0802898C: .4byte gUnknown_80DE4F0
_08028990:
	ldr r0, _0802899C
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_0802899C: .4byte gUnknown_80DE524
_080289A0:
	ldr r0, _080289AC
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_080289AC: .4byte gUnknown_80DE614
_080289B0:
	ldr r0, _080289B4
	b _08028A6A
	.align 2, 0
_080289B4: .4byte gUnknown_80DE648
_080289B8:
	ldr r0, _080289C4
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_080289C4: .4byte gUnknown_80DE694
_080289C8:
	ldr r0, _080289E0
	ldr r3, _080289E4
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	b _08028A2E
	.align 2, 0
_080289E0: .4byte gUnknown_80DE6D4
_080289E4: .4byte gUnknown_80DDA48
_080289E8:
	ldr r0, _080289F0
	ldr r3, _080289F4
	b _08028A1C
	.align 2, 0
_080289F0: .4byte gUnknown_80DE754
_080289F4: .4byte gUnknown_80DDA48
_080289F8:
	ldr r0, _08028A04
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_08028A04: .4byte gUnknown_80DE7B8
_08028A08:
	ldr r0, _08028A14
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_08028A14: .4byte gUnknown_80DE7E8
_08028A18:
	ldr r0, _08028A40
_08028A1A:
	ldr r3, _08028A44
_08028A1C:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r4
_08028A2E:
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x8
	bl sub_8014248
	b _08028AF2
	.align 2, 0
_08028A40: .4byte gUnknown_80DE808
_08028A44: .4byte gUnknown_80DDA64
_08028A48:
	ldr r0, _08028A54
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	b _08028A72
	.align 2, 0
_08028A54: .4byte gUnknown_80DE830
_08028A58:
	ldr r0, _08028A64
	ldr r2, [r6]
	movs r3, 0x84
	lsls r3, 3
	adds r2, r3
	b _08028A72
	.align 2, 0
_08028A64: .4byte gUnknown_80DE864
_08028A68:
	ldr r0, _08028A7C
_08028A6A:
	ldr r2, [r6]
	movs r4, 0x84
	lsls r4, 3
	adds r2, r4
_08028A72:
	ldr r3, _08028A80
	movs r1, 0
	bl sub_80141B4
	b _08028AF2
	.align 2, 0
_08028A7C: .4byte gUnknown_80DE7E8
_08028A80: .4byte 0x0000010d
_08028A84:
	ldr r0, _08028AAC
	ldr r3, _08028AB0
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r2, 0x84
	lsls r2, 3
	adds r1, r2
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0
	bl sub_8014248
	b _08028AF2
	.align 2, 0
_08028AAC: .4byte gUnknown_80DE8B4
_08028AB0: .4byte gUnknown_80DD970
_08028AB4:
	ldr r0, _08028AD8
	ldr r3, _08028ADC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	ldr r1, [r6]
	movs r4, 0x84
	lsls r4, 3
	adds r1, r4
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08028AF2
	.align 2, 0
_08028AD8: .4byte gUnknown_80DE918
_08028ADC: .4byte gUnknown_80DD970
_08028AE0:
	ldr r0, _08028AFC
	ldr r2, [r6]
	movs r1, 0x84
	lsls r1, 3
	adds r2, r1
	ldr r3, _08028B00
	movs r1, 0
	bl sub_80141B4
_08028AF2:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028AFC: .4byte gUnknown_80DE93C
_08028B00: .4byte 0x0000010d
	thumb_func_end sub_8028348

        .align 2,0
