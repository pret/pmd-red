        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start UpdateRescuePasswordMenu
UpdateRescuePasswordMenu:
	push {r4-r6,lr}
	sub sp, 0x34
	movs r0, 0xB
	str r0, [sp, 0x30]
	ldr r5, _08038AB4
	ldr r1, _08038AB8
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r6, r1, 0
	cmp r0, 0x9
	bls _08038AA8
	b _08038DB0
_08038AA8:
	lsls r0, 2
	ldr r1, _08038ABC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038AB4: .4byte 0x0000ffdc
_08038AB8: .4byte gRescuePasswordMenu
_08038ABC: .4byte _08038AC0
	.align 2, 0
_08038AC0:
	.4byte _08038AE8
	.4byte _08038AFC
	.4byte _08038AE8
	.4byte _08038AFC
	.4byte _08038AE8
	.4byte _08038AFC
	.4byte _08038C78
	.4byte _08038C8C
	.4byte _08038CC2
	.4byte _08038D38
_08038AE8:
	bl sub_8031DCC
	ldr r5, _08038AF8
	cmp r0, 0
	bne _08038AF4
	b _08038DB0
_08038AF4:
	movs r5, 0xB
	b _08038DB0
	.align 2, 0
_08038AF8: .4byte 0x0000ffdc
_08038AFC:
	bl sub_80154F0
	adds r4, r0, 0
	mov r0, sp
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	cmp r4, 0x1
	bne _08038B12
	b _08038CBC
_08038B12:
	cmp r4, 0x1
	bcs _08038B18
	b _08038CB0
_08038B18:
	cmp r4, 0x2
	beq _08038AF4
	cmp r4, 0x3
	beq _08038B22
	b _08038DB0
_08038B22:
	ldr r0, _08038B44
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, _08038B48
	mov r2, sp
	bl sub_8039068
	subs r0, 0x7
	cmp r0, 0x11
	bls _08038B38
	b _08038DB0
_08038B38:
	lsls r0, 2
	ldr r1, _08038B4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038B44: .4byte gRescuePasswordMenu
_08038B48: .4byte gUnknown_202EC50
_08038B4C: .4byte _08038B50
	.align 2, 0
_08038B50:
	.4byte _08038BA4
	.4byte _08038DB0
	.4byte _08038BD8
	.4byte _08038DB0
	.4byte _08038C28
	.4byte _08038DB0
	.4byte _08038B9C
	.4byte _08038DB0
	.4byte _08038DB0
	.4byte _08038DB0
	.4byte _08038B98
	.4byte _08038BA0
	.4byte _08038BD4
	.4byte _08038C24
	.4byte _08038DB0
	.4byte _08038BA8
	.4byte _08038BDC
	.4byte _08038C2C
_08038B98:
	movs r0, 0x11
	b _08038CA4
_08038B9C:
	movs r0, 0xD
	b _08038CA4
_08038BA0:
	movs r0, 0x12
	b _08038CA4
_08038BA4:
	movs r0, 0x7
	b _08038CA4
_08038BA8:
	ldr r0, [sp, 0x10]
	bl sub_8095274
	bl sub_8038F98
	ldr r0, _08038BCC
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038BD0
	mov r1, sp
	movs r0, 0x2
	strb r0, [r1]
	mov r0, sp
	bl sub_80951BC
	b _08038DB0
	.align 2, 0
_08038BCC: .4byte gRescuePasswordMenu
_08038BD0: .4byte 0x0000ffdc
_08038BD4:
	movs r0, 0x13
	b _08038CA4
_08038BD8:
	movs r0, 0x9
	b _08038CA4
_08038BDC:
	bl sub_8038F98
	ldr r0, _08038C18
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038C1C
	mov r1, sp
	movs r0, 0x5
	strb r0, [r1]
	mov r0, sp
	bl sub_80951FC
	ldr r1, [sp, 0x10]
	movs r0, 0x1
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	movs r1, 0x7
	strb r1, [r0]
	ldr r0, _08038C20
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	b _08038DB0
	.align 2, 0
_08038C18: .4byte gRescuePasswordMenu
_08038C1C: .4byte 0x0000ffdc
_08038C20: .4byte gUnknown_203B484
_08038C24:
	movs r0, 0x14
	b _08038CA4
_08038C28:
	movs r0, 0xB
	b _08038CA4
_08038C2C:
	bl sub_8038F98
	ldr r0, _08038C70
	ldr r1, [r0]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038C74
	ldr r1, [sp, 0x10]
	movs r0, 0x4
	bl sub_809539C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8095228
	adds r2, r0, 0
	mov r1, sp
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	ldm r1!, {r3,r4,r6}
	stm r2!, {r3,r4,r6}
	movs r1, 0x6
	strb r1, [r0]
	bl GetMainMenu
	adds r0, 0x3A
	movs r1, 0x1
	strb r1, [r0]
	b _08038DB0
	.align 2, 0
_08038C70: .4byte gRescuePasswordMenu
_08038C74: .4byte 0x0000ffdc
_08038C78:
	bl sub_8031DCC
	ldr r5, _08038C88
	cmp r0, 0
	bne _08038C84
	b _08038DB0
_08038C84:
	movs r5, 0xD
	b _08038DB0
	.align 2, 0
_08038C88: .4byte 0x0000ffdc
_08038C8C:
	bl sub_80154F0
	cmp r0, 0x1
	beq _08038CBC
	cmp r0, 0x1
	bcc _08038CB0
	cmp r0, 0x2
	beq _08038C84
	cmp r0, 0x3
	beq _08038CA2
	b _08038DB0
_08038CA2:
	movs r0, 0x15
_08038CA4:
	bl sub_8038DC0
	ldr r0, _08038CB4
	ldr r1, [r0]
	movs r0, 0x8
	str r0, [r1, 0x4]
_08038CB0:
	ldr r5, _08038CB8
	b _08038DB0
	.align 2, 0
_08038CB4: .4byte gRescuePasswordMenu
_08038CB8: .4byte 0x0000ffdc
_08038CBC:
	bl sub_8031E00
	b _08038CB0
_08038CC2:
	ldr r0, [r6]
	adds r0, 0x8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08038CDA
	ldr r0, [r6]
	adds r0, 0x8
	add r1, sp, 0x30
	bl sub_8013114
_08038CDA:
	ldr r0, [sp, 0x30]
	cmp r0, 0xB
	beq _08038D24
	cmp r0, 0xB
	bhi _08038CEA
	cmp r0, 0xA
	beq _08038CEE
	b _08038DB0
_08038CEA:
	cmp r0, 0xC
	bne _08038DB0
_08038CEE:
	bl sub_8039174
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, _08038D1C
	movs r0, 0x4
	bl sub_80151C0
	ldr r0, _08038D20
	ldr r1, [r0]
	movs r0, 0x8
	str r0, [r1, 0x4]
	ldr r0, [r1]
	subs r0, 0x21
	movs r5, 0xB
	cmp r0, 0x1
	bhi _08038DB0
	b _08038C84
	.align 2, 0
_08038D1C: .4byte gUnknown_202EC50
_08038D20: .4byte gRescuePasswordMenu
_08038D24:
	ldr r1, [r6]
	movs r0, 0x8
	str r0, [r1, 0x4]
	ldr r5, _08038D34
	bl sub_80391F8
	b _08038DB0
	.align 2, 0
_08038D34: .4byte 0x0000ffdc
_08038D38:
	adds r4, r6, 0
	ldr r0, [r4]
	adds r0, 0x8
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08038D52
	ldr r0, [r4]
	adds r0, 0x8
	add r1, sp, 0x30
	bl sub_8013114
_08038D52:
	ldr r0, [sp, 0x30]
	cmp r0, 0xB
	beq _08038DA4
	cmp r0, 0xB
	bhi _08038D62
	cmp r0, 0xA
	beq _08038D66
	b _08038DB0
_08038D62:
	cmp r0, 0xC
	bne _08038DB0
_08038D66:
	bl sub_8039174
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, _08038D9C
	movs r0, 0x4
	bl sub_80151C0
	ldr r4, _08038DA0
	ldr r0, [r4]
	ldr r0, [r0]
	bl ConvertMenutoRescuePasswordState
	ldr r1, [r4]
	str r0, [r1, 0x4]
	ldr r0, [r1]
	subs r0, 0x21
	movs r5, 0x2A
	cmp r0, 0x1
	bhi _08038DB0
	movs r5, 0x2B
	b _08038DB0
	.align 2, 0
_08038D9C: .4byte gUnknown_202EC50
_08038DA0: .4byte gRescuePasswordMenu
_08038DA4:
	ldr r1, [r6]
	movs r0, 0x9
	str r0, [r1, 0x4]
	ldr r5, _08038DBC
	bl sub_80391F8
_08038DB0:
	adds r0, r5, 0
	add sp, 0x34
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08038DBC: .4byte 0x0000ffdc
	thumb_func_end UpdateRescuePasswordMenu

	thumb_func_start sub_8038DC0
sub_8038DC0:
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	ldr r0, _08038DF8
	ldr r0, [r0]
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_80155F0
	subs r0, r4, 0x7
	cmp r0, 0xE
	bls _08038DEE
	b _08038F74
_08038DEE:
	lsls r0, 2
	ldr r1, _08038DFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038DF8: .4byte gRescuePasswordMenu
_08038DFC: .4byte _08038E00
	.align 2, 0
_08038E00:
	.4byte _08038E7C
	.4byte _08038F74
	.4byte _08038EDC
	.4byte _08038F74
	.4byte _08038F1C
	.4byte _08038F74
	.4byte _08038E9C
	.4byte _08038F74
	.4byte _08038F74
	.4byte _08038F74
	.4byte _08038E3C
	.4byte _08038E5C
	.4byte _08038EBC
	.4byte _08038EFC
	.4byte _08038F50
_08038E3C:
	ldr r0, _08038E50
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038E54
	ldr r2, _08038E58
	b _08038F2E
	.align 2, 0
_08038E50: .4byte gRescuePasswordMenu
_08038E54: .4byte gUnknown_80E71FC
_08038E58: .4byte gUnknown_80E7214
_08038E5C:
	ldr r0, _08038E70
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038E74
	ldr r2, _08038E78
	b _08038F2E
	.align 2, 0
_08038E70: .4byte gRescuePasswordMenu
_08038E74: .4byte gUnknown_80E72EC
_08038E78: .4byte gUnknown_80E7304
_08038E7C:
	ldr r0, _08038E90
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038E94
	ldr r2, _08038E98
	b _08038F2E
	.align 2, 0
_08038E90: .4byte gRescuePasswordMenu
_08038E94: .4byte gUnknown_80E7344
_08038E98: .4byte gUnknown_80E735C
_08038E9C:
	ldr r0, _08038EB0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038EB4
	ldr r2, _08038EB8
	b _08038F2E
	.align 2, 0
_08038EB0: .4byte gRescuePasswordMenu
_08038EB4: .4byte gUnknown_80E7588
_08038EB8: .4byte gUnknown_80E75A0
_08038EBC:
	ldr r0, _08038ED0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038ED4
	ldr r2, _08038ED8
	b _08038F2E
	.align 2, 0
_08038ED0: .4byte gRescuePasswordMenu
_08038ED4: .4byte gUnknown_80E73AC
_08038ED8: .4byte gUnknown_80E73C4
_08038EDC:
	ldr r0, _08038EF0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038EF4
	ldr r2, _08038EF8
	b _08038F2E
	.align 2, 0
_08038EF0: .4byte gRescuePasswordMenu
_08038EF4: .4byte gUnknown_80E7408
_08038EF8: .4byte gUnknown_80E7420
_08038EFC:
	ldr r0, _08038F10
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038F14
	ldr r2, _08038F18
	b _08038F2E
	.align 2, 0
_08038F10: .4byte gRescuePasswordMenu
_08038F14: .4byte gUnknown_80E7468
_08038F18: .4byte gUnknown_80E7480
_08038F1C:
	ldr r0, _08038F44
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038F48
	ldr r2, _08038F4C
_08038F2E:
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08038F74
	.align 2, 0
_08038F44: .4byte gRescuePasswordMenu
_08038F48: .4byte gUnknown_80E74C8
_08038F4C: .4byte gUnknown_80E74E0
_08038F50:
	ldr r0, _08038F8C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038F90
	ldr r2, _08038F94
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08038F74:
	ldr r0, _08038F8C
	ldr r0, [r0]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038F8C: .4byte gRescuePasswordMenu
_08038F90: .4byte gUnknown_80E752C
_08038F94: .4byte gUnknown_80E7544
	thumb_func_end sub_8038DC0

	thumb_func_start sub_8038F98
sub_8038F98:
	push {r4,r5,lr}
	sub sp, 0x10
	ldr r5, _08038FF4
	ldr r0, [r5]
	movs r1, 0xD4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_80155F0
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x8
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r2
	ldr r3, _08038FF8
	ldr r2, _08038FFC
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0xD
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	ldr r0, [r5]
	adds r0, 0x8
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038FF4: .4byte gRescuePasswordMenu
_08038FF8: .4byte gUnknown_80E7278
_08038FFC: .4byte gUnknown_80E7290
	thumb_func_end sub_8038F98

	thumb_func_start ConvertMenutoRescuePasswordState
ConvertMenutoRescuePasswordState:
	push {lr}
	movs r1, 0xB
	ldr r0, _0803901C
	ldr r0, [r0]
	ldr r0, [r0]
	subs r0, 0x1B
	cmp r0, 0x7
	bhi _08039062
	lsls r0, 2
	ldr r1, _08039020
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803901C: .4byte gRescuePasswordMenu
_08039020: .4byte _08039024
	.align 2, 0
_08039024:
	.4byte _08039044
	.4byte _08039054
	.4byte _0803904C
	.4byte _0803905C
	.4byte _08039048
	.4byte _08039058
	.4byte _08039050
	.4byte _08039060
_08039044:
	movs r1, 0
	b _08039062
_08039048:
	movs r1, 0x4
	b _08039062
_0803904C:
	movs r1, 0x2
	b _08039062
_08039050:
	movs r1, 0x6
	b _08039062
_08039054:
	movs r1, 0x1
	b _08039062
_08039058:
	movs r1, 0x5
	b _08039062
_0803905C:
	movs r1, 0x3
	b _08039062
_08039060:
	movs r1, 0x7
_08039062:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end ConvertMenutoRescuePasswordState

	thumb_func_start sub_8039068
sub_8039068:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r0, r1, 0
	adds r5, r2, 0
	adds r1, r5, 0
	bl sub_803D204
	lsls r0, 24
	cmp r0, 0
	beq _080390AC
	ldrb r0, [r5]
	cmp r0, 0x7
	bhi _080390AC
	ldrb r4, [r5, 0x5]
	ldrb r0, [r5, 0x4]
	bl sub_8090298
	cmp r4, r0
	bge _080390AC
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	cmp r1, 0
	beq _080390AC
	ldr r0, _080390B0
	cmp r1, r0
	bgt _080390AC
	adds r0, r5, 0
	adds r0, 0x22
	ldrb r0, [r0]
	bl IsInvalidItemReward
	lsls r0, 24
	cmp r0, 0
	beq _080390B4
_080390AC:
	movs r0, 0x11
	b _0803916E
	.align 2, 0
_080390B0: .4byte 0x000001a7
_080390B4:
	cmp r6, 0x1E
	beq _08039120
	cmp r6, 0x1E
	bhi _080390C2
	cmp r6, 0x1C
	beq _080390C8
	b _0803916A
_080390C2:
	cmp r6, 0x20
	beq _08039140
	b _0803916A
_080390C8:
	ldrb r0, [r5]
	cmp r0, 0x1
	beq _080390D2
	movs r0, 0x12
	b _0803916E
_080390D2:
	ldr r1, [r5, 0x10]
	movs r0, 0x2
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08039108
	ldr r1, [r5, 0x10]
	movs r0, 0x4
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08039108
	ldr r1, [r5, 0x10]
	movs r0, 0x6
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _08039108
	ldr r0, [r5, 0x10]
	bl sub_8095298
	lsls r0, 24
	cmp r0, 0
	beq _0803910C
_08039108:
	movs r0, 0x7
	b _0803916E
_0803910C:
	bl sub_8095190
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne _0803911C
	movs r0, 0xD
	b _0803916E
_0803911C:
	movs r0, 0x16
	b _0803916E
_08039120:
	ldrb r0, [r5]
	cmp r0, 0x4
	beq _0803912A
	movs r0, 0x13
	b _0803916E
_0803912A:
	ldr r1, [r5, 0x10]
	movs r0, 0x1
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	bne _0803913C
	movs r0, 0x9
	b _0803916E
_0803913C:
	movs r0, 0x17
	b _0803916E
_08039140:
	ldrb r0, [r5]
	cmp r0, 0x5
	beq _0803914A
	movs r0, 0x14
	b _0803916E
_0803914A:
	ldr r1, [r5, 0x10]
	movs r0, 0x4
	bl sub_80952F0
	lsls r0, 24
	cmp r0, 0
	beq _08039162
	bl sub_8011C34
	ldr r1, [r5, 0x28]
	cmp r1, r0
	beq _08039166
_08039162:
	movs r0, 0xB
	b _0803916E
_08039166:
	movs r0, 0x18
	b _0803916E
_0803916A:
	movs r0, 0x1
	negs r0, r0
_0803916E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8039068

	thumb_func_start sub_8039174
sub_8039174:
	push {r4,lr}
	ldr r0, _080391D8
	ldr r3, [r0]
	movs r0, 0x82
	lsls r0, 2
	adds r3, r0
	ldrh r1, [r3]
	ldr r0, _080391DC
	ands r0, r1
	ldr r1, _080391E0
	ands r0, r1
	ldr r4, _080391E4
	ands r0, r4
	ldr r1, _080391E8
	ands r0, r1
	ldr r1, _080391EC
	ands r0, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _080391F0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r4
	movs r2, 0xF
	movs r4, 0xF0
	lsls r4, 8
	ldr r1, _080391F4
	ands r0, r1
	orrs r0, r4
	strh r0, [r3, 0x4]
	movs r0, 0
	strh r0, [r3, 0x2]
	movs r1, 0xC0
	lsls r1, 4
	ldrh r0, [r3, 0x6]
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080391D8: .4byte gRescuePasswordMenu
_080391DC: .4byte 0x0000feff
_080391E0: .4byte 0x0000fdff
_080391E4: .4byte 0x0000f3ff
_080391E8: .4byte 0x0000efff
_080391EC: .4byte 0x0000dfff
_080391F0: .4byte 0x00003fff
_080391F4: .4byte 0x00000fff
	thumb_func_end sub_8039174

        .align 2,0
