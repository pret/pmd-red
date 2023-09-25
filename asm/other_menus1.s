        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8037810
sub_8037810:
	push {r4-r6,lr}
	ldr r6, _080378FC
	ldr r0, [r6]
	movs r5, 0xDE
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	movs r4, 0xE2
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	adds r5, r0, r5
	movs r1, 0
	movs r2, 0
	str r1, [r5]
	str r2, [r5, 0x4]
	adds r4, r0, r4
	str r1, [r4]
	str r2, [r4, 0x4]
	movs r2, 0xE6
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xFE
	lsls r3, 1
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0x8B
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x97
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xA3
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xC5
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0xAF
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xD1
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xE7
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x8A
	lsls r2, 3
	adds r0, r2
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r2, [r6]
	movs r3, 0xB1
	lsls r3, 2
	adds r0, r2, r3
	movs r1, 0
	strh r1, [r0]
	adds r3, 0x88
	adds r0, r2, r3
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080378FC: .4byte sUnknown_203B35C
	thumb_func_end sub_8037810

	thumb_func_start sub_8037900
sub_8037900:
	push {r4,lr}
	sub sp, 0x10
	ldr r4, _08037928
	ldr r0, [r4]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xA
	bls _0803791E
	b _08037A14
_0803791E:
	lsls r0, 2
	ldr r1, _0803792C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037928: .4byte sUnknown_203B35C
_0803792C: .4byte _08037930
	.align 2, 0
_08037930:
	.4byte _0803795C
	.4byte _0803795C
	.4byte _0803797C
	.4byte _0803797C
	.4byte _0803799C
	.4byte _0803799C
	.4byte _080379BC
	.4byte _080379BC
	.4byte _08037A14
	.4byte _080379F0
	.4byte _080379F0
_0803795C:
	ldr r0, _08037970
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037974
	ldr r2, _08037978
	b _080379CE
	.align 2, 0
_08037970: .4byte sUnknown_203B35C
_08037974: .4byte sUnknown_80E6554
_08037978: .4byte sUnknown_80E656C
_0803797C:
	ldr r0, _08037990
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037994
	ldr r2, _08037998
	b _080379CE
	.align 2, 0
_08037990: .4byte sUnknown_203B35C
_08037994: .4byte sUnknown_80E6554
_08037998: .4byte sUnknown_80E65D8
_0803799C:
	ldr r0, _080379B0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379B4
	ldr r2, _080379B8
	b _080379CE
	.align 2, 0
_080379B0: .4byte sUnknown_203B35C
_080379B4: .4byte sUnknown_80E6554
_080379B8: .4byte sUnknown_80E661C
_080379BC:
	ldr r0, _080379E4
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379E8
	ldr r2, _080379EC
_080379CE:
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08037A14
	.align 2, 0
_080379E4: .4byte sUnknown_203B35C
_080379E8: .4byte sUnknown_80E6554
_080379EC: .4byte sUnknown_80E665C
_080379F0:
	ldr r0, _08037A38
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037A3C
	ldr r2, _08037A40
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08037A14:
	ldr r4, _08037A38
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	bl sub_80373C4
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_80130A8
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037A38: .4byte sUnknown_203B35C
_08037A3C: .4byte sUnknown_80E6554
_08037A40: .4byte sUnknown_80E667C
	thumb_func_end sub_8037900

	thumb_func_start nullsub_202
nullsub_202:
	bx lr
	thumb_func_end nullsub_202


	.align 2, 0