    #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

    thumb_func_start sub_80227B8
sub_80227B8:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08022810
	movs r0, 0xD4
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	adds r2, r0, 0
	adds r2, 0xF4
	movs r1, 0
	str r1, [r2]
	str r5, [r0, 0x48]
	cmp r5, 0
	beq _08022820
	ldr r4, _08022814
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl PrintColoredPokeNameToBuffer
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x6
	bl PrintColoredPokeNameToBuffer
	bl HasGummiItem
	lsls r0, 24
	cmp r0, 0
	beq _08022818
	movs r0, 0
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022810: .4byte gUnknown_203B294
_08022814: .4byte gAvailablePokemonNames
_08022818:
	movs r0, 0x11
	bl sub_8022924
	b _08022856
_08022820:
	ldr r4, _08022848
	ldr r5, _0802284C
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	bl GetNumberOfFilledInventorySlots
	cmp r0, 0
	bne _08022850
	movs r0, 0x12
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022848: .4byte gAvailablePokemonNames
_0802284C: .4byte gUnknown_80DC5EC
_08022850:
	movs r0, 0
	bl sub_8022924
_08022856:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80227B8

	thumb_func_start sub_8022860
sub_8022860:
	push {lr}
	ldr r0, _08022878
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x16
	bhi _080228FE
	lsls r0, 2
	ldr r1, _0802287C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022878: .4byte gUnknown_203B294
_0802287C: .4byte _08022880
	.align 2, 0
_08022880:
	.4byte _080228DC
	.4byte _080228DC
	.4byte _080228E2
	.4byte _080228E8
	.4byte _080228EE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228F4
	.4byte _080228FA
_080228DC:
	bl sub_8022E78
	b _08022902
_080228E2:
	bl sub_8022EF4
	b _08022902
_080228E8:
	bl sub_8023068
	b _08022902
_080228EE:
	bl sub_80230E8
	b _08022902
_080228F4:
	bl sub_8023104
	b _08022902
_080228FA:
	movs r0, 0x3
	b _08022904
_080228FE:
	bl sub_8023120
_08022902:
	movs r0, 0
_08022904:
	pop {r1}
	bx r1
	thumb_func_end sub_8022860

	thumb_func_start sub_8022908
sub_8022908:
	push {r4,lr}
	ldr r4, _08022920
	ldr r0, [r4]
	cmp r0, 0
	beq _0802291A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802291A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022920: .4byte gUnknown_203B294
	thumb_func_end sub_8022908

	thumb_func_start sub_8022924
sub_8022924:
	push {lr}
	ldr r1, _08022938
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802293C
	bl sub_8022A10
	pop {r0}
	bx r0
	.align 2, 0
_08022938: .4byte gUnknown_203B294
	thumb_func_end sub_8022924

	thumb_func_start sub_802293C
sub_802293C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08022964
	ldr r0, [r4]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _080229A4
	cmp r0, 0x3
	bgt _08022968
	cmp r0, 0x2
	beq _08022972
	b _080229BC
	.align 2, 0
_08022964: .4byte gUnknown_203B294
_08022968:
	cmp r0, 0x10
	bgt _080229BC
	cmp r0, 0xA
	blt _080229BC
	b _080229E6
_08022972:
	bl sub_8022D2C
	ldr r2, [r4]
	movs r0, 0xBC
	lsls r0, 1
	adds r2, r0
	ldr r1, _080229A0
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xF8
	bl sub_8012CAC
	ldr r0, [r4]
	movs r6, 0xC2
	lsls r6, 1
	adds r0, r6
	movs r1, 0x6
	strh r1, [r0]
	b _080229E6
	.align 2, 0
_080229A0: .4byte gUnknown_80DC5BC
_080229A4:
	movs r7, 0xB0
	lsls r7, 1
	adds r1, r7
	ldr r0, _080229B8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _080229E6
	.align 2, 0
_080229B8: .4byte gUnknown_80DC5D4
_080229BC:
	ldr r0, _08022A08
	mov r12, r0
	movs r1, 0xA4
	lsls r1, 1
	mov r8, r1
	ldr r4, _08022A0C
	movs r3, 0
	movs r2, 0x3
_080229CC:
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
	bge _080229CC
_080229E6:
	bl ResetUnusedInputStruct
	ldr r0, _08022A08
	ldr r0, [r0]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022A08: .4byte gUnknown_203B294
_08022A0C: .4byte gUnknown_80DC5A4
	thumb_func_end sub_802293C

	thumb_func_start sub_8022A10
sub_8022A10:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, _08022A2C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x16
	bls _08022A22
	b _08022D1E
_08022A22:
	lsls r0, 2
	ldr r1, _08022A30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022A2C: .4byte gUnknown_203B294
_08022A30: .4byte _08022A34
	.align 2, 0
_08022A34:
	.4byte _08022A90
	.4byte _08022AAA
	.4byte _08022AB2
	.4byte _08022AE0
	.4byte _08022B10
	.4byte _08022B1A
	.4byte _08022B24
	.4byte _08022B34
	.4byte _08022B44
	.4byte _08022B54
	.4byte _08022B64
	.4byte _08022C28
	.4byte _08022CA0
	.4byte _08022CA8
	.4byte _08022CB0
	.4byte _08022CB8
	.4byte _08022CC0
	.4byte _08022CC8
	.4byte _08022CD8
	.4byte _08022CE8
	.4byte _08022CF8
	.4byte _08022D14
	.4byte _08022D1E
_08022A90:
	ldr r0, [r4]
	ldr r0, [r0, 0x48]
	cmp r0, 0
	beq _08022A9C
	movs r0, 0x5
	b _08022A9E
_08022A9C:
	movs r0, 0x1
_08022A9E:
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08022D22
_08022AAA:
	movs r0, 0x1
	bl sub_801A8D0
	b _08022D22
_08022AB2:
	bl sub_801A9E0
	ldr r0, _08022ADC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x54
	adds r1, r2, 0
	adds r1, 0xF8
	movs r4, 0x9C
	lsls r4, 1
	adds r3, r2, r4
	adds r2, 0xF4
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022ADC: .4byte gUnknown_203B294
_08022AE0:
	bl sub_801A9E0
	ldr r4, _08022B08
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0
	bl sub_8012EA4
	ldr r0, [r4]
	adds r0, 0xA4
	ldr r1, _08022B0C
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022B08: .4byte gUnknown_203B294
_08022B0C: .4byte gUnknown_80DC584
_08022B10:
	ldr r0, [r4]
	adds r0, 0x50
	bl sub_801B3C0
	b _08022D22
_08022B1A:
	ldr r0, _08022B20
	b _08022D00
	.align 2, 0
_08022B20: .4byte gUnknown_80DC5F4
_08022B24:
	ldr r0, _08022B2C
	ldr r3, _08022B30
	b _08022D02
	.align 2, 0
_08022B2C: .4byte gUnknown_80DC618
_08022B30: .4byte 0x00000101
_08022B34:
	ldr r0, _08022B3C
	ldr r3, _08022B40
	b _08022D02
	.align 2, 0
_08022B3C: .4byte gUnknown_80DC674
_08022B40: .4byte 0x00000101
_08022B44:
	ldr r0, _08022B4C
	ldr r3, _08022B50
	b _08022D02
	.align 2, 0
_08022B4C: .4byte gUnknown_80DC6CC
_08022B50: .4byte 0x00000101
_08022B54:
	ldr r0, _08022B5C
	ldr r3, _08022B60
	b _08022D02
	.align 2, 0
_08022B5C: .4byte gUnknown_80DC728
_08022B60: .4byte 0x00000101
_08022B64:
	ldr r7, _08022B68
	b _08022B78
	.align 2, 0
_08022B68: .4byte gUnknown_203B294
_08022B6C:
	ldr r1, [r4]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	cmp r0, 0x17
	bgt _08022C10
_08022B78:
	movs r5, 0
	movs r6, 0
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r5, r0
	bge _08022BA4
	ldrb r1, [r2, 0x8]
	b _08022B9C
_08022B8A:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r3, r0
	bge _08022BA4
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r3
	ldrb r1, [r0]
_08022B9C:
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022B8A
	movs r5, 0x1
_08022BA4:
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	b _08022BC4
_08022BB4:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r3
_08022BC4:
	ldrb r1, [r0]
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022BB4
	movs r6, 0x1
_08022BCE:
	cmp r5, r6
	beq _08022B6C
	ldr r1, [r7]
	movs r0, 0xA
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x40]
	lsls r0, 24
	lsrs r0, 24
	bl GetIQSkillName
	adds r1, r0, 0
	ldr r0, _08022C18
	bl strcpy
	movs r0, 0xCB
	bl PlaySound
	ldr r0, _08022C1C
	movs r1, 0
	movs r2, 0
	ldr r3, _08022C20
	bl sub_80141B4
	ldr r1, [r7]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	ldr r0, _08022C24
	ldr r0, [r0]
	ldr r0, [r0, 0x40]
	cmp r0, 0x17
	bgt _08022C10
	b _08022D22
_08022C10:
	movs r0, 0xB
	bl sub_8022924
	b _08022D22
	.align 2, 0
_08022C18: .4byte gUnknown_202DEA8
_08022C1C: .4byte gUnknown_80DC788
_08022C20: .4byte 0x00000101
_08022C24: .4byte gUnknown_203B294
_08022C28:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	bl nullsub_104
	ldr r0, [r4]
	adds r0, 0x46
	ldrh r0, [r0]
	cmp r0, 0x8
	bhi _08022C98
	lsls r0, 2
	ldr r1, _08022C48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022C48: .4byte _08022C4C
	.align 2, 0
_08022C4C:
	.4byte _08022C70
	.4byte _08022C78
	.4byte _08022C80
	.4byte _08022C98
	.4byte _08022C88
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C90
_08022C70:
	movs r0, 0x16
	bl sub_8022924
	b _08022D22
_08022C78:
	movs r0, 0xD
	bl sub_8022924
	b _08022D22
_08022C80:
	movs r0, 0xE
	bl sub_8022924
	b _08022D22
_08022C88:
	movs r0, 0xF
	bl sub_8022924
	b _08022D22
_08022C90:
	movs r0, 0x10
	bl sub_8022924
	b _08022D22
_08022C98:
	movs r0, 0xC
	bl sub_8022924
	b _08022D22
_08022CA0:
	ldr r0, _08022CA4
	b _08022D00
	.align 2, 0
_08022CA4: .4byte gUnknown_80DC7B4
_08022CA8:
	ldr r0, _08022CAC
	b _08022D00
	.align 2, 0
_08022CAC: .4byte gUnknown_80DC7FC
_08022CB0:
	ldr r0, _08022CB4
	b _08022D00
	.align 2, 0
_08022CB4: .4byte gUnknown_80DC81C
_08022CB8:
	ldr r0, _08022CBC
	b _08022D00
	.align 2, 0
_08022CBC: .4byte gUnknown_80DC844
_08022CC0:
	ldr r0, _08022CC4
	b _08022D00
	.align 2, 0
_08022CC4: .4byte gUnknown_80DC864
_08022CC8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CD4
	b _08022D00
	.align 2, 0
_08022CD4: .4byte gUnknown_80DC88C
_08022CD8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CE4
	b _08022D00
	.align 2, 0
_08022CE4: .4byte gUnknown_80DC8AC
_08022CE8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CF4
	b _08022D00
	.align 2, 0
_08022CF4: .4byte gUnknown_80DC8C8
_08022CF8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022D0C
_08022D00:
	ldr r3, _08022D10
_08022D02:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08022D22
	.align 2, 0
_08022D0C: .4byte gUnknown_80DC8DC
_08022D10: .4byte 0x00000301
_08022D14:
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_801AFA4
	b _08022D22
_08022D1E:
	bl sub_801A928
_08022D22:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022A10

    .align 2,0
