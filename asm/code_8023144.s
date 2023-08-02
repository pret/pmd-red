    #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
