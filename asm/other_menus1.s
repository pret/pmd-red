        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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