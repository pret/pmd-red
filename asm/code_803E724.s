	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text




	thumb_func_start sub_803FF18
sub_803FF18:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r3, r1, 0
	lsls r2, 24
	lsrs r2, 24
	movs r6, 0
	cmp r2, 0
	bne _0803FF2E
	movs r6, 0x1
_0803FF2E:
	movs r1, 0
	cmp r2, 0
	bne _0803FF36
	movs r1, 0x37
_0803FF36:
	ldr r0, _0803FF54
	cmp r5, r0
	ble _0803FF7C
	ldr r0, _0803FF58
	lsls r1, r6, 3
	adds r1, r6
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
	adds r3, 0x2
	strh r0, [r3]
	strh r0, [r3, 0x2]
	b _0804001A
	.align 2, 0
_0803FF54: .4byte 0x000003e7
_0803FF58: .4byte gUnknown_80F6544
_0803FF5C:
	ldr r1, _0803FF78
	lsls r0, r6, 3
	adds r0, r6
	adds r0, r4
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, 0x2
	subs r5, r2
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	b _0803FF98
	.align 2, 0
_0803FF78: .4byte gUnknown_80F6544
_0803FF7C:
	movs r7, 0x20
	movs r4, 0
	adds r1, 0x30
	mov r8, r1
	ldr r2, _0803FFC0
	mov r12, r2
	ldr r0, _0803FFC4
_0803FF8A:
	ldr r2, [r0]
	cmp r2, r5
	ble _0803FF5C
	adds r0, 0x4
	adds r4, 0x1
	cmp r4, 0x8
	ble _0803FF8A
_0803FF98:
	cmp r4, 0x9
	bne _0803FFAC
	movs r1, 0x96
	lsls r1, 2
	adds r0, r7, r1
	ldr r2, _0803FFC8
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
_0803FFAC:
	movs r4, 0
	mov r0, r12
	ldr r2, [r0]
	cmp r2, r5
	bgt _0803FFD0
	ldr r0, _0803FFCC
	lsls r1, r6, 3
	adds r1, r6
	b _0803FFE8
	.align 2, 0
_0803FFC0: .4byte gUnknown_80F6520
_0803FFC4: .4byte gUnknown_80F64FC
_0803FFC8: .4byte 0xfffff000
_0803FFCC: .4byte gUnknown_80F6544
_0803FFD0:
	adds r4, 0x1
	cmp r4, 0x8
	bgt _0803FFF4
	lsls r0, r4, 2
	add r0, r12
	ldr r2, [r0]
	cmp r2, r5
	bgt _0803FFD0
	ldr r0, _08040024
	lsls r1, r6, 3
	adds r1, r6
	adds r1, r4
_0803FFE8:
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
	adds r3, 0x2
	subs r5, r2
_0803FFF4:
	cmp r4, 0x9
	bne _08040008
	movs r1, 0x96
	lsls r1, 2
	adds r0, r7, r1
	ldr r2, _08040028
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
	adds r3, 0x2
_08040008:
	mov r1, r8
	adds r0, r5, r1
	movs r2, 0x96
	lsls r2, 2
	adds r0, r2
	ldr r2, _08040028
	adds r1, r2, 0
	orrs r0, r1
	strh r0, [r3]
_0804001A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040024: .4byte gUnknown_80F6544
_08040028: .4byte 0xfffff000
	thumb_func_end sub_803FF18

        .align 2,0 @ Don't pad with nop
