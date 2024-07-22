	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start HandleAction
HandleAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x148
	adds r7, r0, 0
	movs r1, 0x26
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _0809DA8A
	bl _0809EAB8
_0809DA8A:
	movs r2, 0x26
	ldrsh r0, [r7, r2]
	cmp r0, 0x4
	bls _0809DA96
	bl _0809E9CC
_0809DA96:
	lsls r0, 2
	ldr r1, _0809DAA0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809DAA0: .4byte _0809DAA4
	.align 2, 0
_0809DAA4:
	.4byte _0809E9C6
	.4byte _0809E9C6
	.4byte _0809DAB8
	.4byte _0809E900
	.4byte _0809E9C6
_0809DAB8:
	adds r1, r7, 0
	adds r1, 0x44
	ldrb r0, [r1]
	subs r0, 0x3
	adds r6, r1, 0
	cmp r0, 0xED
	bls _0809DACA
	bl _0809E9D6
_0809DACA:
	lsls r0, 2
	ldr r1, _0809DAD4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809DAD4: .4byte _0809DAD8
	.align 2, 0
_0809DAD8:
	.4byte _0809E382
	.4byte _0809E3C4
	.4byte _0809E524
	.4byte _0809E464
	.4byte _0809E4B4
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809DED6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E308
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E308
	.4byte _0809E31C
	.4byte _0809E75C
	.4byte _0809E33C
	.4byte _0809E368
	.4byte _0809E658
	.4byte _0809E6B4
	.4byte _0809E6E8
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809DF60
	.4byte _0809E0A2
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809DFDC
	.4byte _0809E0A2
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E078
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E08C
	.4byte _0809E0E8
	.4byte _0809E0E8
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E146
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809E9D6
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E2D0
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E798
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E864
	.4byte _0809E9D6
	.4byte _0809E8D8
	.4byte _0809DE90
	.4byte _0809DE90
	.4byte _0809DEA6
	.4byte _0809DEBE
	.4byte _0809DED6
	.4byte _0809DEE8
	.4byte _0809DF24
	.4byte _0809DF24
	.4byte _0809E2DE
	.4byte _0809E9D6
	.4byte _0809E2DE
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
	.4byte _0809E9D6
_0809DE90:
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r3, 0
	ldrsh r0, [r1, r3]
	cmp r0, 0
	ble _0809DEA2
	bl _0809EAB2
_0809DEA2:
	bl _0809E8F4
_0809DEA6:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r1, [r1, 0x4C]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0809DEBA
	bl _0809E9D6
_0809DEBA:
	bl _0809E8F4
_0809DEBE:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r1, [r1, 0x50]
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	beq _0809DED2
	bl _0809E9D6
_0809DED2:
	bl _0809E8F4
_0809DED6:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809DEE4
	bl _0809E9D6
_0809DEE4:
	bl _0809E8F4
_0809DEE8:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrh r0, [r0, 0x2]
	bl IsEqualtoBGTrack
	lsls r0, 24
	cmp r0, 0
	bne _0809DF06
	bl _0809E8F4
_0809DF06:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r1, [r2]
	adds r0, r1, 0x1
	strh r0, [r2]
	lsls r1, 16
	ldr r0, _0809DF20
	cmp r1, r0
	bgt _0809DF1C
	bl _0809E9D6
_0809DF1C:
	bl _0809E8F4
	.align 2, 0
_0809DF20: .4byte 0x2a2f0000
_0809DF24:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrh r0, [r0, 0x2]
	bl IsFanfareSEPlaying_1
	lsls r0, 24
	cmp r0, 0
	bne _0809DF42
	bl _0809E8F4
_0809DF42:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r1, [r2]
	adds r0, r1, 0x1
	strh r0, [r2]
	lsls r1, 16
	ldr r0, _0809DF5C
	cmp r1, r0
	bgt _0809DF58
	bl _0809E9D6
_0809DF58:
	bl _0809E8F4
	.align 2, 0
_0809DF5C: .4byte 0x0e0f0000
_0809DF60:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0xA4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7, 0x60]
	ldr r0, [r5]
	subs r1, r0
	add r4, sp, 0xAC
	str r1, [r4]
	ldr r0, [r7, 0x64]
	ldr r1, [r5, 0x4]
	subs r0, r1
	str r0, [r4, 0x4]
	ldr r1, [r7, 0x54]
	adds r0, r4, 0
	bl sub_800290C
	ldr r0, [r4]
	cmp r0, 0
	bne _0809DF98
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bne _0809DF98
	bl _0809E8F4
_0809DF98:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0x9
	ands r1, r0
	cmp r1, 0
	beq _0809DFB0
	bl _0809E8F4
_0809DFB0:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r2, r7, 0
	adds r2, 0x4E
	ldrh r0, [r2]
	movs r5, 0
	ldrsh r1, [r2, r5]
	cmp r1, 0
	bge _0809DFD0
	bl _0809E9D6
_0809DFD0:
	cmp r1, 0
	ble _0809DFD8
	bl _0809EAAC
_0809DFD8:
	bl _0809E8F4
_0809DFDC:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0xB4
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7, 0x60]
	ldr r0, [r5]
	subs r1, r0
	add r4, sp, 0xBC
	str r1, [r4]
	ldr r0, [r7, 0x64]
	ldr r1, [r5, 0x4]
	subs r0, r1
	str r0, [r4, 0x4]
	ldr r1, [r7, 0x54]
	adds r0, r4, 0
	bl sub_800290C
	ldr r0, [r4]
	adds r5, r4, 0
	cmp r0, 0
	bne _0809E016
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bne _0809E016
	bl _0809E8F4
_0809E016:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x48]
	adds r1, r5, 0
	bl _call_via_r2
	adds r4, r0, 0
	adds r0, r5, 0
	bl sub_8002C60
	lsls r0, 24
	adds r2, r7, 0
	adds r2, 0x4A
	asrs r1, r0, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	movs r0, 0x9
	ands r0, r4
	cmp r0, 0
	beq _0809E04C
	bl _0809E8F4
_0809E04C:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r2, r7, 0
	adds r2, 0x4E
	ldrh r0, [r2]
	movs r6, 0
	ldrsh r1, [r2, r6]
	cmp r1, 0
	bge _0809E06C
	bl _0809E9D6
_0809E06C:
	cmp r1, 0
	ble _0809E074
	bl _0809EAAC
_0809E074:
	bl _0809E8F4
_0809E078:
	adds r6, r7, 0
	adds r6, 0x4E
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	ble _0809E088
	bl _0809EA62
_0809E088:
	bl _0809E8F4
_0809E08C:
	movs r2, 0x4E
	adds r2, r7
	mov r8, r2
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0
	ble _0809E09E
	bl _0809E9DA
_0809E09E:
	bl _0809E8F4
_0809E0A2:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xE4
	add r2, sp, 0xE8
	ldr r3, [r1, 0x10]
	adds r1, r4, 0
	bl _call_via_r3
	ldr r0, [r7, 0x6C]
	ldr r1, [r4]
	subs r0, r1
	adds r2, r4, 0
	cmp r0, 0
	bne _0809E0C2
	bl _0809E8F4
_0809E0C2:
	ldr r4, [r7, 0x54]
	cmn r0, r4
	bge _0809E0CC
	subs r0, r1, r4
	b _0809E0D4
_0809E0CC:
	cmp r0, r4
	ble _0809E0D2
	adds r0, r4, 0
_0809E0D2:
	adds r0, r1, r0
_0809E0D4:
	str r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0xE4
	ldr r1, [r1]
	ldr r2, [r2, 0x28]
	bl _call_via_r2
	bl _0809E9D6
_0809E0E8:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0x14
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	movs r1, 0
	ldrsb r1, [r4, r1]
	ldr r2, [r7, 0x54]
	add r4, sp, 0xEC
	adds r0, r4, 0
	bl sub_8002BB8
	ldr r2, [r4]
	ldr r3, [r4, 0x4]
	add r1, sp, 0xF4
	str r2, [r1]
	str r3, [r1, 0x4]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x48]
	bl _call_via_r2
	movs r1, 0x9
	ands r1, r0
	cmp r1, 0
	beq _0809E124
	bl _0809E8F4
_0809E124:
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r4, 0
	ldrsh r0, [r1, r4]
	cmp r0, 0
	ble _0809E144
	bl _0809EAB2
_0809E144:
	b _0809E8F4
_0809E146:
	adds r1, r7, 0
	adds r1, 0x4E
	ldrh r2, [r1]
	movs r5, 0
	ldrsh r0, [r1, r5]
	mov r10, r1
	cmp r0, 0
	ble _0809E15A
	bl _0809EAB2
_0809E15A:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	movs r4, 0x1
	negs r4, r4
	mov r8, r4
	movs r5, 0
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	mov r4, sp
	adds r4, 0x15
	ldr r2, [r1, 0x14]
	adds r1, r4, 0
	bl _call_via_r2
	add r0, sp, 0x4
	ldrb r0, [r0]
	subs r0, 0x91
	mov r9, r4
	cmp r0, 0x4
	bhi _0809E234
	lsls r0, 2
	ldr r1, _0809E194
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809E194: .4byte _0809E198
	.align 2, 0
_0809E198:
	.4byte _0809E1AC
	.4byte _0809E1AC
	.4byte _0809E1BA
	.4byte _0809E1E0
	.4byte _0809E20C
_0809E1AC:
	adds r0, r7, 0
	adds r0, 0x71
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	b _0809E234
_0809E1BA:
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r4, r0, 16
	cmp r4, 0
	blt _0809E234
	movs r5, 0x1
	add r1, sp, 0xFC
	adds r0, r4, 0
	bl sub_80A8FD8
	add r1, sp, 0x104
	adds r0, r4, 0
	bl sub_80A8F9C
	b _0809E234
_0809E1E0:
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	bl sub_80A7AE8
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	blt _0809E234
	movs r5, 0x1
	add r1, sp, 0xFC
	bl sub_80A8FD8
	ldr r0, _0809E208
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	add r2, sp, 0x104
	str r0, [r2]
	str r1, [r2, 0x4]
	b _0809E234
	.align 2, 0
_0809E208: .4byte gUnknown_81164DC
_0809E20C:
	movs r5, 0x1
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xFC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	add r1, sp, 0x104
	ldr r2, [r2, 0x8]
	bl _call_via_r2
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r0, 16
	adds r1, r4, 0
	bl sub_80AD8B4
_0809E234:
	cmp r5, 0
	beq _0809E282
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r5, sp, 0x10C
	ldr r2, [r1, 0xC]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0x114
	ldr r2, [r1, 0x8]
	adds r1, r4, 0
	bl _call_via_r2
	add r6, sp, 0xFC
	add r3, sp, 0x104
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_8002DF0
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _0809E28C
	ldr r3, _0809E2CC
	adds r0, r5, 0
	adds r1, r3, 0
	adds r2, r6, 0
	bl sub_8002D54
	lsls r0, 24
	asrs r0, 24
	mov r8, r0
_0809E282:
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _0809E28C
	b _0809E8F4
_0809E28C:
	mov r5, r9
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r8, r0
	bne _0809E298
	b _0809E8F4
_0809E298:
	mov r6, r9
	movs r0, 0
	ldrsb r0, [r6, r0]
	add r1, sp, 0x4
	ldrh r2, [r1, 0x2]
	lsls r2, 24
	lsrs r2, 24
	mov r1, r8
	bl sub_8002A70
	adds r1, r7, 0
	adds r1, 0x4A
	strb r0, [r1]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	add r0, sp, 0x4
	ldrb r0, [r0, 0x1]
	mov r1, r10
	strh r0, [r1]
	b _0809E9CC
	.align 2, 0
_0809E2CC: .4byte gUnknown_81164DC
_0809E2D0:
	bl sub_809D234
	lsls r0, 24
	cmp r0, 0
	beq _0809E2DC
	b _0809E9D6
_0809E2DC:
	b _0809E8F4
_0809E2DE:
	adds r0, r7, 0
	adds r0, 0x46
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E2F0
	b _0809E9D6
_0809E2F0:
	ldr r1, _0809E304
	adds r0, r7, 0
	adds r0, 0x4C
	movs r3, 0
	ldrsh r0, [r0, r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	b _0809E8EC
	.align 2, 0
_0809E304: .4byte gUnknown_2039B48
_0809E308:
	adds r0, r7, 0
	adds r0, 0x46
	movs r4, 0
	ldrsh r1, [r0, r4]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E31A
	b _0809E9D6
_0809E31A:
	b _0809E8CA
_0809E31C:
	adds r0, r7, 0
	adds r0, 0x46
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E32E
	b _0809E9D6
_0809E32E:
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	beq _0809E33A
	b _0809E9D6
_0809E33A:
	b _0809E8CA
_0809E33C:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	ldrb r1, [r0, 0x1]
	movs r4, 0x2
	ldrsh r2, [r0, r4]
	ldr r3, [sp, 0x8]
	adds r0, r7, 0
	bl sub_80A14E8
	adds r1, r0, 0
	cmp r1, 0
	bge _0809E360
	b _0809E9D6
_0809E360:
	movs r0, 0x3
	strh r0, [r7, 0x26]
	adds r0, r7, 0
	b _0809E60C
_0809E368:
	add r0, sp, 0x11C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E376
	b _0809E9D6
_0809E376:
	add r0, sp, 0x11C
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
_0809E382:
	add r0, sp, 0x120
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E390
	b _0809E9D6
_0809E390:
	add r4, sp, 0x120
	ldr r0, [r4]
	cmp r0, 0
	blt _0809E3BA
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r4]
	bl sub_8002694
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x4
	movs r3, 0x2
	ldrsh r2, [r1, r3]
	movs r1, 0
	bl GroundMainGroundRequest
_0809E3BA:
	ldr r1, [r4]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
_0809E3C4:
	adds r4, r7, 0
	adds r4, 0x4C
	movs r5, 0
	ldrsh r0, [r4, r5]
	cmp r0, 0
	bne _0809E40C
	add r0, sp, 0x124
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E3DE
	b _0809E9D6
_0809E3DE:
	add r0, sp, 0x124
	ldr r0, [r0]
	cmp r0, 0
	blt _0809E400
	lsls r0, 16
	asrs r0, 16
	bl sub_80A26B8
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	movs r0, 0
	movs r1, 0x12
	bl sub_80018D8
	movs r0, 0x1
	b _0809E402
_0809E400:
	ldr r0, _0809E408
_0809E402:
	strh r0, [r4]
	b _0809E8CE
	.align 2, 0
_0809E408: .4byte 0x0000ffff
_0809E40C:
	cmp r0, 0x1
	bne _0809E464
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0
	movs r1, 0x12
	bl sub_8001658
	adds r2, r0, 0
	lsls r2, 16
	asrs r4, r2, 16
	lsrs r2, 16
	movs r0, 0
	movs r1, 0x30
	bl sub_8001784
	cmp r4, 0x13
	bne _0809E43C
	cmp r0, 0
	beq _0809E45A
_0809E43C:
	add r0, sp, 0x4
	movs r5, 0x2
	ldrsh r0, [r0, r5]
	bl sub_8098DCC
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A2460
	str r0, [r7, 0x28]
	movs r0, 0
	movs r1, 0
	bl sub_80A87AC
	b _0809E8F4
_0809E45A:
	movs r0, 0
	movs r1, 0x13
	movs r2, 0x13
	bl sub_80018D8
_0809E464:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r5, r0, 0
	cmp r1, 0
	bne _0809E4B4
	add r0, sp, 0x128
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E480
	b _0809E9D6
_0809E480:
	add r0, sp, 0x128
	ldr r1, [r0]
	cmp r1, 0
	blt _0809E4AA
	ldrb r0, [r6]
	cmp r0, 0x4
	bne _0809E49A
	lsls r0, r1, 16
	asrs r0, 16
	bl sub_80A26B8
	lsls r0, 16
	b _0809E49C
_0809E49A:
	lsls r0, r1, 16
_0809E49C:
	asrs r2, r0, 16
	movs r0, 0
	movs r1, 0x13
	bl sub_80018D8
	movs r0, 0x1
	b _0809E4AC
_0809E4AA:
	ldr r0, _0809E4B0
_0809E4AC:
	strh r0, [r5]
	b _0809E8CE
	.align 2, 0
_0809E4B0: .4byte 0x0000ffff
_0809E4B4:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r5, r0, 0
	cmp r1, 0x1
	beq _0809E4C4
	b _0809E5B8
_0809E4C4:
	movs r0, 0
	movs r1, 0x13
	bl sub_8001658
	lsls r0, 16
	asrs r6, r0, 16
	add r4, sp, 0x18
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80990EC
	lsls r0, 24
	cmp r0, 0
	beq _0809E580
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8099220
	movs r0, 0x6
	bl sub_80023E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4]
	ldr r4, _0809E51C
	ldr r2, [r4]
	movs r1, 0
	str r1, [sp]
	bl sub_809034C
	adds r1, r0, 0
	ldr r0, _0809E520
	str r1, [r0]
	cmp r1, 0x1
	beq _0809E586
	cmp r1, 0x1
	bcc _0809E580
	cmp r1, 0x2
	bne _0809E5AE
	strh r1, [r5]
	ldr r2, [r4]
	movs r0, 0x9
	b _0809E58E
	.align 2, 0
_0809E51C: .4byte gUnknown_203B4B0
_0809E520: .4byte gUnknown_2039DA4
_0809E524:
	adds r0, r7, 0
	adds r0, 0x4C
	movs r4, 0
	ldrsh r6, [r0, r4]
	adds r5, r0, 0
	cmp r6, 0x1
	bne _0809E5B8
	movs r0, 0
	movs r1, 0x14
	bl sub_8001658
	lsls r0, 24
	lsrs r0, 24
	bl GetMailatIndex
	adds r4, r0, 0
	movs r0, 0x6
	bl sub_80023E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldrb r0, [r4, 0x4]
	ldr r4, _0809E578
	ldr r2, [r4]
	str r6, [sp]
	movs r1, 0
	bl sub_809034C
	adds r1, r0, 0
	ldr r0, _0809E57C
	str r1, [r0]
	cmp r1, 0x1
	beq _0809E586
	cmp r1, 0x1
	bcc _0809E580
	cmp r1, 0x2
	bne _0809E5AE
	strh r1, [r5]
	ldr r2, [r4]
	movs r0, 0x9
	b _0809E58E
	.align 2, 0
_0809E578: .4byte gUnknown_203B4B0
_0809E57C: .4byte gUnknown_2039DA4
_0809E580:
	movs r0, 0x3
	strh r0, [r5]
	b _0809E9CC
_0809E586:
	movs r0, 0x4
	strh r0, [r5]
	ldr r2, [r4]
	movs r0, 0xA
_0809E58E:
	movs r1, 0x1
	bl sub_809B1C0
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	bne _0809E5A4
	b _0809E9CC
_0809E5A4:
	movs r0, 0
	movs r1, 0xB
	bl sub_80A87AC
	b _0809E9CC
_0809E5AE:
	ldr r0, _0809E5B4
	strh r0, [r5]
	b _0809E9CC
	.align 2, 0
_0809E5B4: .4byte 0x0000ffff
_0809E5B8:
	movs r6, 0
	ldrsh r2, [r5, r6]
	cmp r2, 0x2
	bne _0809E5DA
	add r0, sp, 0x12C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E5CE
	b _0809E9D6
_0809E5CE:
	add r0, sp, 0x12C
	ldr r0, [r0]
	cmp r0, 0
	beq _0809E626
	movs r0, 0x3
	b _0809E628
_0809E5DA:
	cmp r2, 0x3
	bne _0809E614
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldr r0, [r0]
	str r0, [r1]
	strh r2, [r7, 0x26]
	add r0, sp, 0x4
	movs r6, 0x2
	ldrsh r0, [r0, r6]
	bl sub_80999FC
	movs r0, 0x70
	movs r1, 0
	bl GroundMap_ExecuteEvent
	movs r1, 0x8
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _0809E608
	b _0809E9CC
_0809E608:
	adds r0, r7, 0
	movs r1, 0x1
_0809E60C:
	bl sub_80A2460
	str r0, [r7, 0x28]
	b _0809E9CC
_0809E614:
	cmp r2, 0x4
	bne _0809E63C
	add r0, sp, 0x130
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E626
	b _0809E9D6
_0809E626:
	ldr r0, _0809E638
_0809E628:
	strh r0, [r5]
	movs r0, 0
	movs r1, 0
	bl sub_80A87AC
	bl sub_809A76C
	b _0809E9CC
	.align 2, 0
_0809E638: .4byte 0x0000ffff
_0809E63C:
	movs r0, 0
	movs r1, 0
	bl sub_8099220
	movs r4, 0x1
	negs r4, r4
	movs r0, 0
	movs r1, 0x13
	adds r2, r4, 0
	bl sub_80018D8
	adds r0, r7, 0
	adds r1, r4, 0
	b _0809E8EE
_0809E658:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x134
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E672
	b _0809E9D6
_0809E672:
	add r0, sp, 0x134
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809E6A4
	ldr r0, [sp, 0x8]
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E6A4
	adds r0, r1, 0
	bl sub_80A8D54
	movs r2, 0
	adds r3, r0, 0
	adds r3, 0x4C
	ldr r4, _0809E6B0
_0809E696:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _0809E696
_0809E6A4:
	add r0, sp, 0x134
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E6B0: .4byte gUnknown_2039D98
_0809E6B4:
	add r0, sp, 0x138
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E6C2
	b _0809E9D6
_0809E6C2:
	add r4, sp, 0x138
	ldr r0, [r4]
	cmp r0, 0x1
	bne _0809E6D0
	ldr r0, _0809E6DC
	bl SetRescueTeamName
_0809E6D0:
	ldr r1, [r4]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E6DC: .4byte gUnknown_2039D98
_0809E6E0:
	movs r1, 0x2
	add r0, sp, 0x13C
	str r1, [r0]
	b _0809E74A
_0809E6E8:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	ldr r5, [sp, 0x10]
	add r0, sp, 0x13C
	bl sub_809B260
	lsls r0, 24
	cmp r0, 0
	bne _0809E704
	b _0809E9D6
_0809E704:
	add r0, sp, 0x13C
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0809E74A
	add r4, sp, 0x18
	ldr r0, _0809E758
	adds r3, r4, 0
	movs r2, 0
	mov r1, sp
	adds r1, 0x27
_0809E718:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, r3
	bge _0809E718
	adds r1, r4, 0
	bl CopyStringtoBuffer
	movs r2, 0
	ldrb r0, [r4]
	ldrb r3, [r5]
	cmp r0, r3
	bne _0809E6E0
	cmp r0, 0
	beq _0809E74A
_0809E734:
	adds r2, 0x1
	cmp r2, 0xF
	bgt _0809E74A
	adds r0, r4, r2
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0809E6E0
	cmp r0, 0
	bne _0809E734
_0809E74A:
	add r0, sp, 0x13C
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_80A2460
	b _0809E8C8
	.align 2, 0
_0809E758: .4byte gUnknown_2039D98
_0809E75C:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r3, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	bne _0809E76C
	b _0809E872
_0809E76C:
	add r4, sp, 0xA0
	adds r0, r4, 0
	bl sub_809AFFC
	lsls r0, 24
	cmp r0, 0
	bne _0809E77C
	b _0809E9D6
_0809E77C:
	ldrb r0, [r4]
	cmp r0, 0
	bne _0809E784
	b _0809E8CA
_0809E784:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	movs r4, 0x2
	ldrsh r1, [r0, r4]
	b _0809E8C2
_0809E798:
	add r1, sp, 0x4
	ldr r0, [r7, 0x40]
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r0, [r0]
	str r0, [r1]
	adds r2, r7, 0
	adds r2, 0x50
	movs r3, 0
	ldrsh r0, [r2, r3]
	adds r4, r2, 0
	cmp r0, 0
	bne _0809E84C
	movs r3, 0
	adds r0, r7, 0
	adds r0, 0x4C
	movs r5, 0
	ldrsh r2, [r0, r5]
	adds r5, r0, 0
	cmp r2, 0
	bge _0809E7CC
	ldr r0, [r7, 0x28]
	ldrb r0, [r0]
	cmp r0, 0xD1
	beq _0809E812
	b _0809E8F4
_0809E7CC:
	ldr r1, [r7, 0x28]
	ldrb r0, [r1]
	cmp r0, 0xD0
	bne _0809E7F8
	movs r6, 0x2
	ldrsh r0, [r1, r6]
	cmp r0, r2
	beq _0809E812
_0809E7DC:
	ldr r0, [r7, 0x28]
	adds r1, r0, 0
	adds r1, 0x10
	str r1, [r7, 0x28]
	ldrb r0, [r0, 0x10]
	cmp r0, 0xD0
	bne _0809E7F8
	movs r0, 0x2
	ldrsh r1, [r1, r0]
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bne _0809E7DC
	movs r3, 0x1
_0809E7F8:
	cmp r3, 0
	bne _0809E812
	ldr r1, [r7, 0x28]
	ldrb r0, [r1]
	cmp r0, 0xD1
	bne _0809E8F4
_0809E804:
	adds r0, r1, 0
	adds r1, 0x10
	str r1, [r7, 0x28]
	ldrb r0, [r0, 0x10]
	cmp r0, 0xD1
	beq _0809E804
	b _0809E8F4
_0809E812:
	add r0, sp, 0x4
	ldrb r0, [r0, 0x1]
	ldr r1, [sp, 0x8]
	lsls r1, 16
	asrs r1, 16
	ldr r2, [r7, 0x28]
	ldr r2, [r2, 0xC]
	bl sub_809AE90
	lsls r0, 24
	cmp r0, 0
	beq _0809E844
	movs r0, 0
	movs r1, 0xA
	bl sub_80A87AC
	adds r0, r7, 0
	movs r1, 0
	bl sub_809D8EC
	lsls r0, 24
	cmp r0, 0
	beq _0809E844
	movs r0, 0x1
	strh r0, [r4]
_0809E844:
	ldr r0, [r7, 0x28]
	adds r0, 0x10
	str r0, [r7, 0x28]
	b _0809E9CC
_0809E84C:
	adds r0, r7, 0
	adds r0, 0x46
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E85E
	b _0809E9D6
_0809E85E:
	movs r0, 0
	strh r0, [r2]
	b _0809E8D0
_0809E864:
	adds r2, r7, 0
	adds r2, 0x50
	ldrh r3, [r2]
	movs r4, 0
	ldrsh r0, [r2, r4]
	cmp r0, 0
	bne _0809E88A
_0809E872:
	adds r0, r7, 0
	adds r0, 0x46
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E884
	b _0809E9D6
_0809E884:
	adds r0, r3, 0x1
	strh r0, [r2]
	b _0809E9CC
_0809E88A:
	add r0, sp, 0x140
	bl sub_809B18C
	lsls r0, 24
	cmp r0, 0
	bne _0809E898
	b _0809E9D6
_0809E898:
	add r0, sp, 0x140
	ldr r3, [r0]
	cmp r3, 0
	ble _0809E8CA
	adds r0, r7, 0
	adds r0, 0x4C
	movs r6, 0
	ldrsh r2, [r0, r6]
	ldr r1, [r7, 0x40]
	lsls r0, r3, 4
	lsls r2, 4
	adds r2, r1
	add r1, sp, 0x4
	adds r0, r2
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, 0x4
	movs r5, 0x2
	ldrsh r1, [r0, r5]
_0809E8C2:
	adds r0, r7, 0
	bl sub_80A242C
_0809E8C8:
	str r0, [r7, 0x28]
_0809E8CA:
	movs r0, 0x3
	strh r0, [r7, 0x26]
_0809E8CE:
	movs r0, 0
_0809E8D0:
	movs r1, 0
	bl sub_80A87AC
	b _0809E9CC
_0809E8D8:
	adds r0, r7, 0
	adds r0, 0x46
	movs r6, 0
	ldrsh r1, [r0, r6]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0809E9D6
	ldr r0, _0809E8FC
	ldr r1, [r0, 0x4]
_0809E8EC:
	adds r0, r7, 0
_0809E8EE:
	bl sub_80A2460
	str r0, [r7, 0x28]
_0809E8F4:
	movs r0, 0x3
	strh r0, [r7, 0x26]
	b _0809E9CC
	.align 2, 0
_0809E8FC: .4byte gUnknown_2039B48
_0809E900:
	adds r0, r7, 0
	bl ExecuteScriptCommand
	strh r0, [r7, 0x26]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	bhi _0809E9BC
	lsls r0, 2
	ldr r1, _0809E91C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809E91C: .4byte _0809E920
	.align 2, 0
_0809E920:
	.4byte _0809E934
	.4byte _0809E9B8
	.4byte _0809E9BC
	.4byte _0809E9D6
	.4byte _0809E9B4
_0809E934:
	adds r0, r7, 0
	adds r0, 0x86
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _0809E9AA
	adds r4, r7, 0
	adds r4, 0x84
	adds r0, r7, 0
	adds r0, 0x24
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	ldr r2, [r7]
	ldr r0, [r2, 0x2C]
	cmp r0, 0
	beq _0809E98E
	adds r5, r7, 0
	adds r5, 0x4A
	movs r1, 0
	ldrsb r1, [r5, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0809E98E
	ldr r0, [r7, 0x4]
	add r1, sp, 0x144
	ldr r2, [r2, 0x18]
	bl _call_via_r2
	add r0, sp, 0x144
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0809E98E
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0
	ldrsb r1, [r5, r1]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
_0809E98E:
	ldr r0, [r7]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq _0809E9A2
	ldr r0, [r7, 0x4]
	adds r1, r7, 0
	adds r1, 0x48
	ldrh r1, [r1]
	bl _call_via_r2
_0809E9A2:
	adds r0, r4, 0
	bl InitScriptData
	b _0809E9D6
_0809E9AA:
	adds r0, r7, 0
	adds r0, 0x24
	bl InitScriptData
	b _0809E9D6
_0809E9B4:
	movs r0, 0x4
	b _0809EABA
_0809E9B8:
	movs r0, 0x1
	b _0809EABA
_0809E9BC:
	adds r1, r7, 0
	adds r1, 0x50
	movs r0, 0
	strh r0, [r1]
	b _0809E9CC
_0809E9C6:
	movs r2, 0x26
	ldrsh r0, [r7, r2]
	b _0809EABA
_0809E9CC:
	movs r3, 0x1
	cmp r3, 0
	beq _0809E9D6
	bl _0809DA8A
_0809E9D6:
	movs r0, 0x3
	b _0809EABA
_0809E9DA:
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	add r4, sp, 0xCC
	ldr r2, [r1, 0xC]
	adds r1, r4, 0
	bl _call_via_r2
	add r5, sp, 0xD4
	adds r1, r7, 0
	adds r1, 0x58
	adds r2, r7, 0
	adds r2, 0x60
	mov r6, r8
	movs r0, 0
	ldrsh r6, [r6, r0]
	mov r9, r6
	adds r6, r7, 0
	adds r6, 0x50
	movs r3, 0
	ldrsh r0, [r6, r3]
	str r0, [sp]
	adds r0, r5, 0
	mov r3, r9
	bl sub_8002934
	ldr r1, [r5]
	ldr r0, [r4]
	subs r1, r0
	add r0, sp, 0xDC
	str r1, [r0]
	ldr r1, [r5, 0x4]
	ldr r2, [r4, 0x4]
	subs r1, r2
	str r1, [r0, 0x4]
	bl sub_8002C60
	lsls r0, 24
	adds r2, r7, 0
	adds r2, 0x4A
	asrs r1, r0, 24
	lsrs r0, 24
	strb r0, [r2]
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r2, 0x2C]
	bl _call_via_r2
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	mov r4, r8
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	b _0809E9D6
_0809EA62:
	add r5, sp, 0xC4
	adds r1, r7, 0
	adds r1, 0x58
	adds r2, r7, 0
	adds r2, 0x60
	movs r3, 0
	ldrsh r0, [r6, r3]
	mov r8, r0
	adds r4, r7, 0
	adds r4, 0x50
	movs r3, 0
	ldrsh r0, [r4, r3]
	str r0, [sp]
	adds r0, r5, 0
	mov r3, r8
	bl sub_8002934
	ldr r1, [r7]
	ldr r0, [r7, 0x4]
	ldr r2, [r1, 0x24]
	adds r1, r5, 0
	bl _call_via_r2
	ldr r2, [r7]
	ldr r0, [r7, 0x4]
	movs r1, 0x80
	lsls r1, 5
	ldr r2, [r2, 0x30]
	bl _call_via_r2
	ldrh r0, [r6]
	subs r0, 0x1
	strh r0, [r6]
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _0809E9D6
_0809EAAC:
	subs r0, 0x1
	strh r0, [r2]
	b _0809E9D6
_0809EAB2:
	subs r0, r2, 0x1
	strh r0, [r1]
	b _0809E9D6
_0809EAB8:
	movs r0, 0
_0809EABA:
	add sp, 0x148
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end HandleAction
	.align 2, 0
