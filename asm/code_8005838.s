	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8005838
sub_8005838:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, _08005880
	ldrb r0, [r0]
	cmp r0, 0
	bne _08005854
	movs r1, 0
_08005854:
	ldr r0, _08005884
	ldr r0, [r0]
	ldr r3, _08005888
	cmp r0, 0
	bne _08005860
	ldr r3, _0800588C
_08005860:
	ldr r0, _08005890
	ldr r2, [r0]
	cmp r2, 0
	bne _0800586A
	ldr r2, _08005894
_0800586A:
	ldr r0, _08005898
	str r3, [r0]
	cmp r1, 0x5
	bls _08005876
	bl _08006094
_08005876:
	lsls r0, r1, 2
	ldr r1, _0800589C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08005880: .4byte gUnknown_2026E4C
_08005884: .4byte gUnknown_2026E54
_08005888: .4byte gUnknown_20270E8
_0800588C: .4byte gUnknown_2026E60
_08005890: .4byte gUnknown_203B078
_08005894: .4byte gUnknown_80B83EA
_08005898: .4byte gUnknown_2026E58
_0800589C: .4byte _080058A0
	.align 2, 0
_080058A0:
	.4byte _080058B8
	.4byte _08005984
	.4byte _08005A98
	.4byte _08005BAC
	.4byte _08005D46
	.4byte _08005E58
_080058B8:
	movs r1, 0
	movs r7, 0x9
_080058BC:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _080058BC
	b _08006094
_08005984:
	ldr r1, _08005A94
	movs r7, 0x9
_08005988:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005A90
	b _08005988
_08005A90:
	b _08006094
	.align 2, 0
_08005A94: .4byte gUnknown_80B816A
_08005A98:
	ldr r1, _08005BA8
	movs r7, 0x9
_08005A9C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005BA4
	b _08005A9C
_08005BA4:
	b _08006094
	.align 2, 0
_08005BA8: .4byte gUnknown_80B802A
_08005BAC:
	ldr r0, [r5]
	mov r10, r0
	cmp r0, 0
	bge _08005BBA
	ldr r0, [r5, 0x8]
	cmp r0, 0
	blt _08005BDC
_08005BBA:
	ldr r1, [r5, 0x4]
	cmp r1, 0
	bge _08005BC6
	ldr r0, [r5, 0xC]
	cmp r0, 0
	blt _08005BDC
_08005BC6:
	mov r4, r10
	cmp r4, 0xEF
	ble _08005BD2
	ldr r0, [r5, 0x8]
	cmp r0, 0xEF
	bgt _08005BDC
_08005BD2:
	cmp r1, 0x9F
	ble _08005CA8
	ldr r0, [r5, 0xC]
	cmp r0, 0x9F
	ble _08005CA8
_08005BDC:
	movs r1, 0xF0
	movs r7, 0x9
_08005BE0:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005BE0
	b _08006094
_08005CA8:
	movs r7, 0
	mov r8, r1
	movs r6, 0x80
	lsls r6, 1
	mov r12, r6
	lsls r0, r1, 1
	ldr r1, _08005CCC
	subs r6, r1, r0
	mov r9, r10
_08005CBA:
	cmp r8, r7
	ble _08005CD0
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r4, r12
	strh r4, [r3]
	b _08005D3A
	.align 2, 0
_08005CCC: .4byte gUnknown_80B8008
_08005CD0:
	ldr r1, [r5, 0xC]
	cmp r1, r7
	bgt _08005CE2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	mov r0, r12
	b _08005D38
_08005CE2:
	mov r4, r8
	subs r0, r7, r4
	cmp r0, 0xF
	bgt _08005CF0
	movs r0, 0
	ldrsh r1, [r6, r0]
	b _08005D00
_08005CF0:
	subs r0, r1, r7
	cmp r0, 0xF
	bgt _08005D10
	lsls r0, 1
	ldr r1, _08005D0C
	adds r0, r1
	movs r4, 0
	ldrsh r1, [r0, r4]
_08005D00:
	mov r0, r9
	adds r4, r0, r1
	ldr r0, [r5, 0x8]
	subs r1, r0, r1
	b _08005D14
	.align 2, 0
_08005D0C: .4byte gUnknown_80B8008
_08005D10:
	mov r4, r10
	ldr r1, [r5, 0x8]
_08005D14:
	cmp r4, 0
	bge _08005D1A
	movs r4, 0
_08005D1A:
	cmp r4, 0xEF
	ble _08005D20
	movs r4, 0xEF
_08005D20:
	cmp r1, 0
	bgt _08005D26
	movs r1, 0x1
_08005D26:
	cmp r1, 0xF0
	ble _08005D2C
	movs r1, 0xF0
_08005D2C:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	lsls r0, r1, 8
	orrs r0, r4
_08005D38:
	strh r0, [r3]
_08005D3A:
	adds r3, 0x2
	adds r6, 0x2
	adds r7, 0x1
	cmp r7, 0x9F
	ble _08005CBA
	b _08006094
_08005D46:
	ldr r1, _08005E54
	movs r7, 0xE
_08005D4A:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, 0x2
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	blt _08005E52
	b _08005D4A
_08005E52:
	b _08006094
	.align 2, 0
_08005E54: .4byte gUnknown_80B82AA
_08005E58:
	ldr r4, _08005FF4
	ldr r5, _08005FF8
	ldr r6, _08005FFC
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0, 0
	movs r7, 0xE
_08005E66:
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	ldrh r0, [r2]
	strh r0, [r3]
	adds r2, 0x2
	adds r3, 0x2
	strh r1, [r3]
	adds r3, 0x2
	subs r7, 0x1
	cmp r7, 0
	bge _08005E66
	ldr r4, [r4]
	str r4, [sp]
	ldr r5, [r5]
	str r5, [sp, 0x4]
	ldr r6, [r6]
	str r6, [sp, 0x8]
	adds r1, r6, 0
	cmp r6, 0
	bge _08005F40
	adds r1, 0xFF
_08005F40:
	asrs r1, 8
	adds r1, 0x1
	movs r0, 0x80
	lsls r0, 3
	bl __divsi3
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bge _08005F56
	adds r0, 0xFF
_08005F56:
	asrs r4, r0, 8
	adds r5, r4, 0
	movs r3, 0
	lsls r0, r4, 2
	adds r7, r0, 0x2
	mov r9, r7
_08005F62:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009C7C
	ldr r1, [sp, 0x8]
	muls r0, r1
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005F76
	adds r0, 0xFF
_08005F76:
	asrs r0, 8
	ldr r2, [sp, 0x4]
	adds r1, r2, r0
	cmp r1, 0
	bge _08005F82
	adds r1, 0xFF
_08005F82:
	asrs r1, 8
	str r1, [sp, 0x14]
	ldr r6, [sp, 0x4]
	subs r0, r6, r0
	cmp r0, 0
	bge _08005F90
	adds r0, 0xFF
_08005F90:
	asrs r0, 8
	mov r8, r0
	ldr r0, [sp, 0x14]
	cmp r5, r0
	blt _08005FA4
	ldr r1, [sp, 0xC]
	adds r1, r3
	mov r10, r1
	cmp r4, r8
	ble _0800608A
_08005FA4:
	adds r0, r3, 0
	str r3, [sp, 0x10]
	bl sub_8009D04
	ldr r2, [sp, 0x8]
	muls r0, r2
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bge _08005FB8
	adds r0, 0xFF
_08005FB8:
	asrs r0, 8
	ldr r6, [sp]
	subs r1, r6, r0
	cmp r1, 0
	bge _08005FC4
	adds r1, 0xFF
_08005FC4:
	asrs r1, 8
	ldr r2, [sp]
	adds r0, r2, r0
	cmp r0, 0
	bge _08005FD0
	adds r0, 0xFF
_08005FD0:
	asrs r0, 8
	cmp r1, 0
	bge _08005FD8
	movs r1, 0
_08005FD8:
	cmp r0, 0
	bge _08005FDE
	movs r0, 0
_08005FDE:
	cmp r1, 0xEF
	ble _08005FE4
	movs r1, 0x9F
_08005FE4:
	cmp r0, 0xEF
	ble _08005FEA
	movs r0, 0x9F
_08005FEA:
	cmp r1, r0
	ble _08006000
	lsls r2, r1, 8
	orrs r2, r0
	b _08006004
	.align 2, 0
_08005FF4: .4byte gUnknown_2026E40
_08005FF8: .4byte gUnknown_2026E44
_08005FFC: .4byte gUnknown_2026E48
_08006000:
	lsls r2, r0, 8
	orrs r2, r1
_08006004:
	ldr r6, [sp, 0xC]
	adds r3, r6
	mov r10, r3
	ldr r0, [sp, 0x14]
	cmp r5, r0
	bge _0800604E
	ldr r1, _08006030
	mov r12, r1
	ldr r3, _08006034
	add r3, r9
	ldr r1, _08006038
	add r1, r9
_0800601C:
	cmp r5, 0
	blt _0800603E
	cmp r5, 0x9F
	bgt _0800603E
	mov r6, r12
	ldr r0, [r6]
	cmp r0, 0
	bne _0800603C
	strh r2, [r1]
	b _0800603E
	.align 2, 0
_08006030: .4byte gUnknown_2026E54
_08006034: .4byte gUnknown_20270E8
_08006038: .4byte gUnknown_2026E60
_0800603C:
	strh r2, [r3]
_0800603E:
	adds r3, 0x4
	adds r1, 0x4
	movs r0, 0x4
	add r9, r0
	adds r5, 0x1
	ldr r6, [sp, 0x14]
	cmp r5, r6
	blt _0800601C
_0800604E:
	cmp r4, r8
	ble _0800608A
	ldr r6, _08006070
	ldr r0, _08006074
	adds r3, r7, r0
	ldr r0, _08006078
	adds r1, r7, r0
_0800605C:
	cmp r4, 0
	blt _0800607E
	cmp r4, 0x9F
	bgt _0800607E
	ldr r0, [r6]
	cmp r0, 0
	bne _0800607C
	strh r2, [r1]
	b _0800607E
	.align 2, 0
_08006070: .4byte gUnknown_2026E54
_08006074: .4byte gUnknown_20270E8
_08006078: .4byte gUnknown_2026E60
_0800607C:
	strh r2, [r3]
_0800607E:
	subs r3, 0x4
	subs r1, 0x4
	subs r7, 0x4
	subs r4, 0x1
	cmp r4, r8
	bgt _0800605C
_0800608A:
	mov r3, r10
	ldr r0, _080060A4
	cmp r3, r0
	bgt _08006094
	b _08005F62
_08006094:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080060A4: .4byte 0x000003ff
	thumb_func_end sub_8005838

        .align 2,0
