	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text


	thumb_func_start sub_8063698
sub_8063698:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r4, [r0, 0x70]
	ldr r0, _080636E8
	ldr r0, [r0]
	lsls r0, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r5, r4, r0
	ldr r1, _080636EC
	movs r0, 0
	str r0, [r1]
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _080636FA
	cmp r7, 0
	beq _080636D0
	movs r0, 0x14
	movs r1, 0
	bl sub_8044F5C
_080636D0:
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08063702
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080636F0
	movs r0, 0x33
	b _080636F2
	.align 2, 0
_080636E8: .4byte gUnknown_202F2D8
_080636EC: .4byte gUnknown_202EE6C
_080636F0:
	movs r0, 0x1E
_080636F2:
	movs r1, 0
	bl sub_8044F5C
	b _08063702
_080636FA:
	movs r0, 0x1F
	movs r1, 0
	bl sub_8044F5C
_08063702:
	cmp r6, 0
	beq _08063716
	movs r0, 0x20
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0x21
	movs r1, 0
	bl sub_8044F5C
_08063716:
	movs r0, 0x1D
	movs r1, 0
	bl sub_8044F5C
	cmp r6, 0
	bne _0806372A
	movs r0, 0x20
	bl sub_8044FF0
	b _08063754
_0806372A:
	ldr r5, _080637A0
	ldr r1, [r5]
	adds r0, r4, 0
	bl sub_8063C88
	lsls r0, 24
	cmp r0, 0
	bne _08063740
	movs r0, 0x20
	bl sub_8044FF0
_08063740:
	ldr r1, [r5]
	adds r0, r4, 0
	bl sub_8063DD4
	lsls r0, 24
	cmp r0, 0
	bne _08063754
	movs r0, 0x21
	bl sub_8044FF0
_08063754:
	ldr r5, _080637A0
	ldr r1, [r5]
	adds r0, r4, 0
	bl sub_8063DD4
	lsls r0, 24
	cmp r0, 0
	bne _0806376A
	movs r0, 0x21
	bl sub_8044FF0
_0806376A:
	cmp r7, 0
	beq _08063792
	movs r0, 0
	ldr r1, [r5]
	cmp r1, 0x3
	bgt _08063788
	mov r0, r8
	movs r2, 0x1
	bl CanAIUseMove
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r0, r1, 31
_08063788:
	cmp r0, 0
	bne _08063792
	movs r0, 0x14
	bl sub_8044FF0
_08063792:
	bl sub_8045064
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080637A0: .4byte gUnknown_202F2D8
	thumb_func_end sub_8063698

	thumb_func_start sub_80637A4
sub_80637A4:
	push {lr}
	adds r2, r1, 0
	ldr r1, _080637B8
	movs r3, 0x18
	ldrsh r1, [r1, r3]
	bl sub_80637BC
	pop {r0}
	bx r0
	.align 2, 0
_080637B8: .4byte gUnknown_202EE10
	thumb_func_end sub_80637A4

	thumb_func_start sub_80637BC
sub_80637BC:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r2, 0
	ldr r0, _080637E0
	lsls r1, 2
	adds r1, r0
	ldrh r1, [r1]
	adds r0, r4, 0
	bl SetMonsterActionFields
	strb r5, [r4, 0x4]
	ldr r0, _080637E4
	ldr r0, [r0]
	strb r0, [r4, 0xC]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080637E0: .4byte gUnknown_202EE44
_080637E4: .4byte gUnknown_202F2D8
	thumb_func_end sub_80637BC

	thumb_func_start sub_80637E8
sub_80637E8:
	push {lr}
	adds r3, r0, 0
	ldr r0, _08063828
	ldr r1, [r0]
	ldrb r0, [r3, 0x4]
	lsls r0, 2
	ldr r2, _0806382C
	adds r1, r2
	adds r1, r0
	ldr r0, [r1]
	ldr r0, [r0, 0x70]
	ldrb r1, [r3, 0xC]
	lsls r1, 3
	adds r1, r0, r1
	ldr r2, _08063830
	adds r2, r1
	mov r12, r2
	ldrb r2, [r2]
	movs r1, 0x2
	orrs r1, r2
	mov r2, r12
	strb r1, [r2]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	ldrb r1, [r3, 0xC]
	movs r2, 0x4
	bl sub_8063834
	pop {r0}
	bx r0
	.align 2, 0
_08063828: .4byte gDungeon
_0806382C: .4byte 0x0001357c
_08063830: .4byte 0x00000119
	thumb_func_end sub_80637E8

	thumb_func_start sub_8063834
sub_8063834:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x7C
	str r0, [sp, 0x74]
	str r1, [sp, 0x78]
	adds r4, r2, 0
	mov r0, sp
	bl sub_80140B4
	add r0, sp, 0x70
	str r0, [sp, 0x14]
	movs r1, 0x1
	mov r9, r1
	ldr r3, [sp, 0x78]
	adds r3, 0x1
	add r2, sp, 0x60
	mov r10, r2
	cmp r3, r4
	bge _08063894
	lsls r0, r3, 3
	ldr r1, [sp, 0x74]
	adds r2, r0, r1
	ldrb r1, [r2]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _08063894
	movs r6, 0x2
	movs r5, 0x1
_08063874:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08063894
	movs r0, 0x1
	add r9, r0
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r4
	bge _08063894
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08063874
_08063894:
	movs r4, 0
	ldr r6, _0806393C
_08063898:
	movs r7, 0
	mov r1, r9
	add r2, sp, 0x70
	strb r1, [r2]
	adds r1, r2, 0
	strb r4, [r1, 0x1]
	movs r0, 0xC
	strb r0, [r1, 0x2]
	strb r7, [r1, 0x3]
	strh r4, [r6, 0x1E]
	mov r0, r9
	strh r0, [r6, 0x20]
	ldr r1, _08063940
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x17
	lsls r0, 3
	strh r0, [r6, 0xC]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r6, 0xE]
	strh r7, [r6, 0x14]
	strh r7, [r6, 0x4]
	movs r0, 0x10
	strh r0, [r6, 0x6]
	str r7, [r6]
	adds r0, r6, 0
	adds r0, 0x28
	bl sub_801317C
	strh r7, [r6, 0x18]
	strh r7, [r6, 0x1A]
	strh r7, [r6, 0x1C]
	mov r0, sp
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, [sp, 0x78]
	adds r1, r0, r4
	lsls r1, 3
	ldr r2, [sp, 0x74]
	adds r1, r2, r1
	adds r0, r4, 0
	movs r2, 0
	mov r3, r10
	bl unk_PrintMoveDescription
	mov r8, r0
_080638FE:
	mov r0, r8
	cmp r0, 0
	beq _08063908
	bl sub_8062500
_08063908:
	ldr r5, _08063944
	adds r0, r5, 0
	movs r1, 0
	bl nullsub_34
	movs r0, 0x1C
	bl sub_803E46C
	bl sub_8062D88
	ldr r1, _08063948
	ldrh r1, [r1, 0x2]
	ands r0, r1
	cmp r0, 0
	bne _0806392C
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	beq _0806394C
_0806392C:
	bl sub_8083D08
	movs r7, 0x1
	mov r1, r8
	cmp r1, 0
	beq _080639AE
	movs r7, 0x2
	b _080639AE
	.align 2, 0
_0806393C: .4byte gUnknown_202EE10
_08063940: .4byte gUnknown_2027370
_08063944: .4byte gUnknown_202EE38
_08063948: .4byte gRealInputs
_0806394C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0806395A
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	beq _08063962
_0806395A:
	bl sub_8083D30
	movs r7, 0x1
	b _080639AE
_08063962:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08063970
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	beq _08063986
_08063970:
	adds r0, r4, 0
	cmp r4, 0
	bne _08063978
	mov r4, r9
_08063978:
	subs r4, 0x1
	cmp r0, r4
	beq _080639AE
	movs r0, 0
	bl sub_8083CE0
	b _080639AE
_08063986:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08063994
	ldrb r0, [r5, 0x3]
	cmp r0, 0
	beq _080638FE
_08063994:
	adds r1, r4, 0
	mov r0, r9
	subs r0, 0x1
	cmp r4, r0
	bne _080639A2
	movs r4, 0
	b _080639A4
_080639A2:
	adds r4, 0x1
_080639A4:
	cmp r1, r4
	beq _080639AE
	movs r0, 0
	bl sub_8083CE0
_080639AE:
	cmp r7, 0x1
	beq _080639CA
	cmp r7, 0
	bne _080639B8
	b _08063898
_080639B8:
	mov r2, r8
	cmp r2, 0
	bne _080639C0
	b _08063898
_080639C0:
	mov r0, r8
	mov r1, r10
	bl sub_80625A4
	b _08063898
_080639CA:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	add sp, 0x7C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8063834

	thumb_func_start sub_80639E4
sub_80639E4:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, _08063A5C
	adds r0, r4, 0
	bl sub_80140B4
	ldr r0, _08063A60
	str r0, [r4, 0x14]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_803ECB4
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08063A64
	ldr r1, [r5]
	bl strcpy
	ldr r2, _08063A68
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r2, [r5, 0x4]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	ldr r0, _08063A6C
	strh r4, [r0, 0x1E]
	strh r4, [r0, 0x20]
	strh r4, [r0, 0xC]
	strh r4, [r0, 0xE]
	strh r4, [r0, 0x14]
	strh r4, [r0, 0x4]
	movs r1, 0x10
	strh r1, [r0, 0x6]
	str r4, [r0]
	strh r4, [r0, 0x18]
	strh r4, [r0, 0x1A]
	strh r4, [r0, 0x1C]
	adds r0, r6, 0
	bl sub_801317C
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08063A5C: .4byte gUnknown_202F278
_08063A60: .4byte gUnknown_8106CC8
_08063A64: .4byte gFormatBuffer_Monsters
_08063A68: .4byte gUnknown_8106CCC
_08063A6C: .4byte gUnknown_202EE10
	thumb_func_end sub_80639E4

	thumb_func_start sub_8063A70
sub_8063A70:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	ldr r1, _08063B1C
	ldr r2, [r1]
	ldrb r1, [r0, 0x4]
	lsls r1, 2
	ldr r3, _08063B20
	adds r2, r3
	adds r2, r1
	ldr r6, [r2]
	ldr r5, [r6, 0x70]
	ldrb r0, [r0, 0xC]
	lsls r0, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r4, r5, r0
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	negs r0, r0
	lsrs r0, 31
	mov r8, r0
	ldr r0, _08063B24
	mov r9, r0
	movs r1, 0x1
	mov r12, r1
	adds r2, r5, r2
	movs r7, 0xF7
	movs r3, 0x3
_08063ABC:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _08063ACC
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2]
_08063ACC:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08063ABC
	mov r0, r9
	adds r1, r4, 0
	movs r2, 0
	bl BufferMoveName
	mov r3, r8
	cmp r3, 0
	bne _08063AEC
	ldrb r1, [r4]
	movs r0, 0x8
	orrs r0, r1
	strb r0, [r4]
_08063AEC:
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r5, r1
	bl unk_FixLinkedMovesSetEnabled4
	ldrb r1, [r4, 0x1]
	movs r0, 0x2
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, _08063B28
	bl PlaySoundEffect
	mov r3, r10
	cmp r3, 0
	beq _08063B42
	mov r0, r8
	cmp r0, 0
	bne _08063B30
	ldr r0, _08063B2C
	ldr r1, [r0]
	adds r0, r6, 0
	bl LogMessageByIdWithPopupCheckUser
	b _08063B3A
	.align 2, 0
_08063B1C: .4byte gDungeon
_08063B20: .4byte 0x0001357c
_08063B24: .4byte gFormatBuffer_Items
_08063B28: .4byte 0x00000133
_08063B2C: .4byte gUnknown_80F8B40
_08063B30:
	ldr r0, _08063B50
	ldr r1, [r0]
	adds r0, r6, 0
	bl LogMessageByIdWithPopupCheckUser
_08063B3A:
	movs r0, 0x78
	movs r1, 0x1F
	bl sub_803E708
_08063B42:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063B50: .4byte gUnknown_80F8B64
	thumb_func_end sub_8063A70

	thumb_func_start sub_8063B54
sub_8063B54:
	push {r4-r6,lr}
	ldr r1, _08063BA4
	ldr r2, [r1]
	ldrb r1, [r0, 0x4]
	lsls r1, 2
	ldr r3, _08063BA8
	adds r2, r3
	adds r2, r1
	ldr r1, [r2]
	ldr r5, [r1, 0x70]
	ldrb r4, [r0, 0xC]
	lsls r4, 3
	movs r6, 0x8C
	lsls r6, 1
	adds r4, r6
	adds r4, r5, r4
	ldr r0, _08063BAC
	adds r1, r4, 0
	movs r2, 0
	bl BufferMoveName
	ldrb r0, [r4]
	movs r1, 0x4
	eors r0, r1
	strb r0, [r4]
	adds r5, r6
	adds r0, r5, 0
	bl unk_FixLinkedMovesSetEnabled4
	ldrb r1, [r4, 0x1]
	movs r0, 0x2
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, _08063BB0
	bl PlaySoundEffect
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08063BA4: .4byte gDungeon
_08063BA8: .4byte 0x0001357c
_08063BAC: .4byte gFormatBuffer_Items
_08063BB0: .4byte 0x00000133
	thumb_func_end sub_8063B54

	thumb_func_start sub_8063BB4
sub_8063BB4:
	push {r4-r7,lr}
	ldr r1, _08063C70
	ldr r2, [r1]
	ldrb r1, [r0, 0x4]
	lsls r1, 2
	ldr r3, _08063C74
	adds r2, r3
	adds r2, r1
	ldr r1, [r2]
	ldr r6, [r1, 0x70]
	ldrb r5, [r0, 0xC]
	ldr r0, _08063C78
	lsls r4, r5, 3
	movs r7, 0x8C
	lsls r7, 1
	adds r1, r4, r7
	adds r1, r6, r1
	movs r2, 0
	bl BufferMoveName
	adds r4, r6, r4
	ldr r0, _08063C7C
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strb r0, [r2]
	movs r3, 0
	adds r5, 0x1
	cmp r5, 0x3
	bgt _08063C2C
	lsls r2, r5, 3
	adds r0, r2, r6
	adds r1, r7, 0
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08063C2C
	adds r0, r2, r7
	adds r2, r0, r6
	movs r4, 0x2
_08063C0A:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08063C2C
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08063C2C
	adds r2, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	bgt _08063C2C
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08063C0A
_08063C2C:
	lsls r0, r5, 3
	adds r0, r6
	movs r4, 0x8C
	lsls r4, 1
	adds r0, r4
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08063C42
	movs r5, 0x4
_08063C42:
	cmp r5, 0x3
	bgt _08063C5C
	lsls r1, r5, 3
	adds r1, r4
	adds r1, r6, r1
	ldrb r2, [r1]
	movs r0, 0x2
	orrs r0, r2
	strb r0, [r1]
	ldr r0, _08063C80
	movs r2, 0
	bl BufferMoveName
_08063C5C:
	adds r0, r6, r4
	bl unk_FixLinkedMovesSetEnabled4
	ldr r0, _08063C84
	bl PlaySoundEffect
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063C70: .4byte gDungeon
_08063C74: .4byte 0x0001357c
_08063C78: .4byte gFormatBuffer_Items
_08063C7C: .4byte 0x00000119
_08063C80: .4byte gFormatBuffer_Items + 0x50
_08063C84: .4byte 0x00000133
	thumb_func_end sub_8063BB4

	thumb_func_start sub_8063C88
sub_8063C88:
	push {r4-r7,lr}
	adds r4, r0, 0
	movs r7, 0
	adds r5, r1, 0
	lsls r0, r5, 3
	adds r0, r4, r0
	movs r1, 0x8D
	lsls r1, 1
	adds r0, r1
	ldrh r0, [r0]
	bl DoesMoveCharge
	lsls r0, 24
	cmp r0, 0
	beq _08063CAE
_08063CA6:
	movs r0, 0
	b _08063CEA
_08063CAA:
	movs r7, 0x1
	b _08063CE8
_08063CAE:
	adds r5, 0x1
	movs r6, 0
	lsls r0, r5, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r4, r0, r4
_08063CBC:
	ldrh r0, [r4, 0x2]
	bl DoesMoveCharge
	lsls r0, 24
	cmp r0, 0
	bne _08063CA6
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08063CE8
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08063CAA
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	bgt _08063CE8
	adds r6, 0x1
	cmp r6, 0x3
	ble _08063CBC
_08063CE8:
	adds r0, r7, 0
_08063CEA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8063C88

	thumb_func_start sub_8063CF0
sub_8063CF0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	ldr r1, _08063D98
	ldr r2, [r1]
	ldrb r1, [r0, 0x4]
	lsls r1, 2
	ldr r3, _08063D9C
	adds r2, r3
	adds r2, r1
	ldr r7, [r2]
	ldr r6, [r7, 0x70]
	ldrb r5, [r0, 0xC]
	movs r0, 0
	mov r8, r0
	ldr r0, _08063DA0
	lsls r4, r5, 3
	movs r1, 0x8C
	lsls r1, 1
	mov r9, r1
	adds r1, r4, r1
	adds r1, r6, r1
	movs r2, 0
	bl BufferMoveName
	adds r4, r6, r4
	ldr r3, _08063DA4
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strb r0, [r2]
	adds r5, 0x1
	movs r3, 0
	cmp r5, 0x3
	bgt _08063D70
	movs r0, 0x2
	mov r12, r0
	lsls r0, r5, 3
	add r0, r9
	adds r2, r0, r6
	movs r4, 0xFD
_08063D4E:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _08063D70
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2]
	movs r1, 0x1
	mov r8, r1
	adds r2, 0x8
	adds r5, 0x1
	adds r3, 0x1
	cmp r3, 0x3
	bgt _08063D70
	cmp r5, 0x3
	ble _08063D4E
_08063D70:
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r6, r2
	bl unk_FixLinkedMovesSetEnabled4
	ldr r0, _08063DA8
	bl PlaySoundEffect
	mov r3, r10
	cmp r3, 0
	beq _08063DC2
	mov r0, r8
	cmp r0, 0
	beq _08063DB0
	ldr r0, _08063DAC
	ldr r1, [r0]
	adds r0, r7, 0
	bl LogMessageByIdWithPopupCheckUser
	b _08063DBA
	.align 2, 0
_08063D98: .4byte gDungeon
_08063D9C: .4byte 0x0001357c
_08063DA0: .4byte gFormatBuffer_Items
_08063DA4: .4byte 0x00000119
_08063DA8: .4byte 0x00000133
_08063DAC: .4byte gUnknown_80F8B88
_08063DB0:
	ldr r0, _08063DD0
	ldr r1, [r0]
	adds r0, r7, 0
	bl LogMessageByIdWithPopupCheckUser
_08063DBA:
	movs r0, 0x78
	movs r1, 0x1F
	bl sub_803E708
_08063DC2:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063DD0: .4byte gUnknown_80F8BB4
	thumb_func_end sub_8063CF0

	thumb_func_start sub_8063DD4
sub_8063DD4:
	push {r4-r7,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	movs r5, 0
	adds r2, 0x1
	movs r4, 0
	cmp r2, 0x3
	bgt _08063E20
	lsls r0, r2, 3
	movs r6, 0x8C
	lsls r6, 1
	adds r0, r6
	adds r0, r3, r0
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08063E20
	movs r5, 0x1
	adds r2, 0x1
	movs r7, 0x2
	lsls r0, r2, 3
	adds r0, r6
	adds r3, r0, r3
_08063E04:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08063E20
	cmp r2, 0x3
	bgt _08063E20
	ldrb r1, [r3]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08063E20
	movs r5, 0x1
	adds r3, 0x8
	adds r2, 0x1
	b _08063E04
_08063E20:
	cmp r5, 0
	bne _08063E28
	movs r0, 0
	b _08063E2A
_08063E28:
	movs r0, 0x1
_08063E2A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8063DD4

	thumb_func_start sub_8063E30
sub_8063E30:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r1, 0x1
	movs r4, 0
	cmp r1, 0x7
	bgt _08063E62
	movs r7, 0x2
	movs r6, 0xFD
	lsls r0, r1, 3
	adds r3, r0, r5
_08063E44:
	ldrb r2, [r3]
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	beq _08063E62
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r3]
	adds r3, 0x8
	adds r1, 0x1
	adds r4, 0x1
	cmp r4, 0x7
	bgt _08063E62
	cmp r1, 0x7
	ble _08063E44
_08063E62:
	adds r0, r5, 0
	bl unk_FixLinkedMovesSetEnabled8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8063E30

	thumb_func_start sub_8063E70
sub_8063E70:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xD0
	str r0, [sp, 0xC4]
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0xC8]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0xCC]
	add r4, sp, 0x60
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x64]
	add r0, sp, 0x68
	movs r6, 0
	movs r1, 0x2
	strh r1, [r0]
	strh r1, [r0, 0x2]
	add r1, sp, 0x6C
	movs r0, 0x12
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x6E
	movs r1, 0x10
	strh r1, [r0]
	add r0, sp, 0x70
	strh r1, [r0]
	add r5, sp, 0xC0
	str r5, [sp, 0x74]
	movs r1, 0x3
	str r1, [sp, 0x7C]
	add r0, sp, 0x90
	str r1, [r0, 0x4]
	add r0, sp, 0xA8
	str r1, [r0, 0x4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	ldr r0, _08063F80
	str r6, [r0]
	ldr r1, _08063F84
	mov r8, r1
	mov r9, r0
	ldr r2, _08063F88
	mov r10, r2
_08063EE0:
	ldr r0, [sp, 0xC4]
	adds r1, r7, 0
	mov r2, sp
	add r3, sp, 0xC0
	bl sub_8064228
_08063EEC:
	mov r0, r8
	bl AddMenuCursorSprite
	movs r0, 0x1E
	bl sub_803E46C
	mov r0, r10
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08063F2A
	mov r1, r8
	movs r2, 0x18
	ldrsh r4, [r1, r2]
	adds r0, r7, 0
	adds r1, r4, 0
	bl unk_FindMoveEnabledForAIAfter8
	adds r1, r0, 0
	mov r0, r8
	bl sub_8013780
	mov r1, r8
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r4, r0
	beq _08063F2A
	movs r0, 0
	bl sub_8083CE0
_08063F2A:
	mov r0, r10
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08063F5C
	mov r1, r8
	movs r2, 0x18
	ldrsh r4, [r1, r2]
	adds r0, r7, 0
	adds r1, r4, 0
	bl unk_FindMoveEnabledForAIBefore8
	adds r1, r0, 0
	mov r0, r8
	bl sub_8013780
	mov r1, r8
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r4, r0
	beq _08063F5C
	movs r0, 0
	bl sub_8083CE0
_08063F5C:
	bl sub_8062D88
	mov r2, r10
	ldrh r1, [r2, 0x2]
	ands r0, r1
	cmp r0, 0
	bne _08063F76
	ldr r2, _08063F84
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08063F8C
_08063F76:
	bl sub_8083D08
	movs r4, 0
	b _08063FB2
	.align 2, 0
_08063F80: .4byte gUnknown_202F2D8
_08063F84: .4byte gUnknown_202EE10
_08063F88: .4byte gRealInputs
_08063F8C:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08063FD4
	ldr r0, [sp, 0xCC]
	cmp r0, 0
	beq _08063EEC
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08063FAC
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	beq _08063EEC
_08063FAC:
	bl sub_8083D30
	movs r4, 0x1
_08063FB2:
	ldr r5, _08063FD0
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x1E
	bl sub_803E46C
	cmp r4, 0x1
	bne _08063FDC
	movs r0, 0x1
	negs r0, r0
	mov r1, r9
	str r0, [r1]
	b _080640FA
	.align 2, 0
_08063FD0: .4byte gUnknown_202EE10
_08063FD4:
	bl sub_8083D44
	movs r4, 0x2
	b _08063FB2
_08063FDC:
	ldr r6, _08064004
	movs r2, 0x18
	ldrsh r0, [r5, r2]
	str r0, [r6]
	cmp r4, 0x2
	bne _08064008
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x8
	movs r1, 0x1B
	bl sub_803E708
	ldr r1, [r6]
	adds r0, r7, 0
	movs r2, 0x4
	bl sub_8063834
	b _08063EE0
	.align 2, 0
_08064004: .4byte gUnknown_202F2D8
_08064008:
	adds r0, r7, 0
	bl sub_8064310
	mov r0, sp
	movs r1, 0x16
	bl sub_805FC30
	adds r4, r5, 0
	ldr r6, _0806408C
	adds r5, 0x2A
_0806401C:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08064040
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_08064040:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08064058
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_08064058:
	bl sub_8062D88
	ldrh r1, [r6, 0x2]
	ands r1, r0
	cmp r1, 0
	bne _0806406E
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806409C
_0806406E:
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	beq _08064098
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	cmp r0, 0x2
	bne _08064090
	bl sub_8083D08
	b _08064094
	.align 2, 0
_0806408C: .4byte gRealInputs
_08064090:
	bl sub_8083D1C
_08064094:
	movs r4, 0
	b _080640B2
_08064098:
	bl sub_8083D30
_0806409C:
	ldrh r1, [r6, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080640AC
	ldrb r0, [r5]
	cmp r0, 0
	beq _0806401C
_080640AC:
	bl sub_8083D30
	movs r4, 0x1
_080640B2:
	ldr r6, _080640E4
	adds r0, r6, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	cmp r4, 0x1
	bne _080640CE
	b _08063EE0
_080640CE:
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	bne _080640E8
	mov r2, r9
	ldr r1, [r2]
	adds r0, r7, 0
	bl sub_8063E30
	b _08063EE0
	.align 2, 0
_080640E4: .4byte gUnknown_202EE10
_080640E8:
	cmp r0, 0x2
	bne _080640FA
	mov r0, r9
	ldr r1, [r0]
	adds r0, r7, 0
	movs r2, 0x8
	bl sub_8063834
	b _08063EE0
_080640FA:
	ldr r1, _08064140
	ldr r2, [r1]
	cmp r2, 0
	bge _08064104
	b _08064214
_08064104:
	ldr r0, [sp, 0xC8]
	cmp r0, 0
	beq _08064160
	movs r4, 0
	lsls r0, r2, 3
	adds r1, r7, r0
	adds r0, r2, 0x1
	cmp r0, 0x7
	bgt _08064130
	lsls r0, 3
	adds r0, r7
	ldrb r2, [r0]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08064130
	movs r0, 0x2
	ands r0, r2
	lsls r0, 24
	lsrs r0, 24
	negs r0, r0
	lsrs r4, r0, 31
_08064130:
	ldr r0, _08064144
	movs r2, 0
	bl BufferMoveName
	cmp r4, 0
	beq _0806414C
	ldr r0, _08064148
	b _0806414E
	.align 2, 0
_08064140: .4byte gUnknown_202F2D8
_08064144: .4byte gFormatBuffer_Items
_08064148: .4byte gUnknown_80FDF00
_0806414C:
	ldr r0, _0806415C
_0806414E:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl DisplayDungeonYesNoMessage
	adds r3, r0, 0
	b _08064162
	.align 2, 0
_0806415C: .4byte gUnknown_80FDF70
_08064160:
	movs r3, 0x1
_08064162:
	cmp r3, 0x1
	beq _08064168
	b _08063EE0
_08064168:
	mov r1, r9
	ldr r0, [r1]
	lsls r0, 3
	adds r0, r7
	movs r1, 0
	strb r1, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r2, r0, 0x1
	cmp r2, 0x7
	bgt _080641BC
	lsls r0, r2, 3
	adds r4, r7, r0
	ldrb r1, [r4]
	ands r3, r1
	cmp r3, 0
	beq _080641BC
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080641BC
	movs r0, 0
	mov r12, r0
	movs r6, 0x1
	adds r3, r4, 0
	movs r5, 0x2
_0806419C:
	mov r1, r12
	strb r1, [r4]
	adds r3, 0x8
	adds r2, 0x1
	cmp r2, 0x7
	bgt _080641BC
	adds r4, r3, 0
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080641BC
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0806419C
_080641BC:
	movs r4, 0
	movs r6, 0x1
	adds r3, r7, 0
	add r5, sp, 0x60
	movs r2, 0x7
_080641C6:
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080641D8
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	stm r5!, {r0,r1}
	adds r4, 0x1
_080641D8:
	adds r3, 0x8
	subs r2, 0x1
	cmp r2, 0
	bge _080641C6
	cmp r4, 0x7
	bgt _080641F4
	movs r1, 0
_080641E6:
	lsls r0, r4, 3
	add r0, sp
	adds r0, 0x60
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x7
	ble _080641E6
_080641F4:
	add r4, sp, 0x60
	adds r3, r7, 0
	movs r2, 0x7
_080641FA:
	ldm r4!, {r0,r1}
	stm r3!, {r0,r1}
	subs r2, 0x1
	cmp r2, 0
	bge _080641FA
	ldr r2, _08064210
	ldr r0, [r2]
	cmp r0, 0
	blt _08064214
	movs r0, 0x1
	b _08064216
	.align 2, 0
_08064210: .4byte gUnknown_202F2D8
_08064214:
	movs r0, 0
_08064216:
	add sp, 0xD0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8063E70

	thumb_func_start sub_8064228
sub_8064228:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	mov r10, r1
	adds r5, r2, 0
	adds r7, r3, 0
	movs r1, 0
	movs r0, 0x1
	strb r0, [r7]
	strb r1, [r7, 0x1]
	strb r1, [r7, 0x3]
	mov r8, r1
	ldr r6, _08064304
	ldr r0, _08064308
	mov r12, r0
	movs r4, 0x1
	mov r2, r10
	movs r3, 0x7
_08064254:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08064262
	movs r1, 0x1
	add r8, r1
_08064262:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08064254
	mov r2, r12
	ldr r0, [r2]
	movs r4, 0
	strh r0, [r6, 0x18]
	mov r3, r8
	strh r3, [r6, 0x1A]
	strh r3, [r6, 0x1C]
	strh r4, [r6, 0x1E]
	strh r4, [r6, 0x20]
	strh r4, [r6, 0x4]
	movs r0, 0x10
	strh r0, [r6, 0x6]
	strh r4, [r6, 0xC]
	strh r4, [r6, 0xE]
	strh r4, [r6, 0x14]
	str r4, [r6]
	adds r0, r6, 0
	adds r0, 0x28
	bl sub_801317C
	mov r0, r8
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	strh r0, [r5, 0x10]
	strh r0, [r5, 0xE]
	movs r0, 0xE
	strb r0, [r7, 0x2]
	movs r0, 0x2
	strh r0, [r5, 0x8]
	adds r1, r5, 0
	adds r1, 0x18
	adds r0, r5, 0
	adds r0, 0x48
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	adds r1, r5, 0
	adds r1, 0x30
	adds r0, r5, 0
	adds r0, 0x48
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r6, 0
	movs r1, 0
	bl sub_80137B0
	ldr r0, _0806430C
	mov r7, r9
	ldr r1, [r7, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	str r4, [sp]
	str r4, [sp, 0x4]
	mov r0, r8
	mov r1, r9
	mov r2, r10
	movs r3, 0
	bl sub_8063578
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08064304: .4byte gUnknown_202EE10
_08064308: .4byte gUnknown_202F2D8
_0806430C: .4byte gFormatBuffer_Monsters
	thumb_func_end sub_8064228

	thumb_func_start sub_8064310
sub_8064310:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08064350
	movs r0, 0
	str r0, [r1]
	movs r0, 0x22
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0x21
	movs r1, 0
	bl sub_8044F5C
	ldr r0, _08064354
	ldr r1, [r0]
	adds r0, r4, 0
	bl sub_8064358
	lsls r0, 24
	cmp r0, 0
	bne _08064340
	movs r0, 0x21
	bl sub_8044FF0
_08064340:
	movs r0, 0x1D
	movs r1, 0
	bl sub_8044F5C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064350: .4byte gUnknown_202EE6C
_08064354: .4byte gUnknown_202F2D8
	thumb_func_end sub_8064310

	thumb_func_start sub_8064358
sub_8064358:
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	movs r5, 0
	adds r2, 0x1
	movs r4, 0
	cmp r2, 0x7
	bgt _0806439C
	lsls r0, r2, 3
	adds r0, r3, r0
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806439C
	movs r5, 0x1
	adds r2, 0x1
	movs r6, 0x2
	lsls r0, r2, 3
	adds r3, r0, r3
_08064380:
	adds r4, 0x1
	cmp r4, 0x7
	bgt _0806439C
	cmp r2, 0x7
	bgt _0806439C
	ldrb r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0806439C
	movs r5, 0x1
	adds r3, 0x8
	adds r2, 0x1
	b _08064380
_0806439C:
	cmp r5, 0
	bne _080643A4
	movs r0, 0
	b _080643A6
_080643A4:
	movs r0, 0x1
_080643A6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8064358

	thumb_func_start sub_80643AC
sub_80643AC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xE4
	adds r7, r0, 0
	add r0, sp, 0x68
	mov r9, r0
	mov r1, sp
	adds r1, 0x6C
	str r1, [sp, 0xD0]
	mov r2, sp
	adds r2, 0x6E
	str r2, [sp, 0xD4]
	mov r0, sp
	adds r0, 0x70
	str r0, [sp, 0xD8]
	adds r1, 0xC
	str r1, [sp, 0xDC]
	adds r2, 0x22
	str r2, [sp, 0xE0]
	adds r0, 0x38
	str r0, [sp, 0xC8]
	subs r1, 0x18
	str r1, [sp, 0xC4]
	add r2, sp, 0xC0
	mov r10, r2
	ldr r5, _080644C8
	adds r0, r7, 0x4
	str r0, [sp, 0xCC]
	ldr r1, _080644CC
	mov r8, r1
	movs r6, 0
_080643F0:
	movs r4, 0
	ldr r0, [sp, 0xC4]
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x64]
	movs r0, 0x2
	mov r2, r9
	strh r0, [r2]
	strh r0, [r2, 0x2]
	movs r0, 0x12
	ldr r1, [sp, 0xD0]
	strh r0, [r1]
	movs r0, 0x4
	ldr r2, [sp, 0xD4]
	strh r0, [r2]
	movs r0, 0x10
	ldr r1, [sp, 0xD8]
	strh r0, [r1]
	mov r2, r10
	str r2, [sp, 0x74]
	movs r0, 0x3
	ldr r1, [sp, 0xDC]
	str r0, [r1, 0x4]
	ldr r2, [sp, 0xE0]
	str r0, [r2, 0x4]
	ldr r1, [sp, 0xC8]
	str r0, [r1, 0x4]
	mov r0, sp
	ldr r1, [sp, 0xC4]
	movs r2, 0x60
	bl memcpy
	bl sub_8083D44
	adds r0, r7, 0x4
	mov r1, sp
	mov r2, r10
	bl sub_806455C
	movs r0, 0x2D
	bl sub_803E46C
	adds r0, r7, 0
	bl sub_80645D4
	strh r4, [r5, 0x8]
	strh r4, [r5, 0xA]
	mov r0, sp
	movs r1, 0x16
	bl sub_805FC30
_0806445C:
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x2D
	bl sub_803E46C
	mov r2, r8
	ldrh r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08064482
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80136E0
_08064482:
	mov r0, r8
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0806449C
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8013744
_0806449C:
	mov r2, r8
	ldrh r1, [r2, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080644B2
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08064510
_080644B2:
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _080644D0
	bl sub_8083D08
	ldr r0, [sp, 0xCC]
	bl sub_80645F8
	movs r4, 0x2
	b _0806452A
	.align 2, 0
_080644C8: .4byte gUnknown_202EE10
_080644CC: .4byte gRealInputs
_080644D0:
	movs r2, 0x18
	ldrsh r0, [r5, r2]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	beq _0806450C
	ldr r4, [r7, 0x70]
	adds r4, 0x44
	ldr r1, _08064508
	movs r2, 0x18
	ldrsh r0, [r5, r2]
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	bl SetMonsterActionFields
	bl sub_8083D08
	strb r6, [r4, 0x4]
	strh r6, [r4, 0x8]
	strh r6, [r4, 0xA]
	strb r6, [r4, 0xC]
	strh r6, [r4, 0x10]
	strh r6, [r4, 0x12]
	movs r4, 0
	b _0806452A
	.align 2, 0
_08064508: .4byte gUnknown_202EE44
_0806450C:
	bl sub_8083D30
_08064510:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08064524
	ldr r1, _08064554
	ldrb r0, [r1]
	cmp r0, 0
	beq _0806445C
_08064524:
	bl sub_8083D30
	movs r4, 0x1
_0806452A:
	ldr r0, _08064558
	bl AddMenuCursorSprite
	movs r0, 0x2D
	bl sub_803E46C
	cmp r4, 0x2
	bne _0806453C
	b _080643F0
_0806453C:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	add sp, 0xE4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08064554: .4byte gUnknown_202EE3A
_08064558: .4byte gUnknown_202EE10
	thumb_func_end sub_80643AC

	thumb_func_start sub_806455C
sub_806455C:
	push {r4,r5,lr}
	sub sp, 0x54
	adds r4, r0, 0
	adds r0, r1, 0
	movs r5, 0
	movs r1, 0x1
	strb r1, [r2]
	strb r5, [r2, 0x1]
	movs r1, 0xC
	strb r1, [r2, 0x2]
	strb r5, [r2, 0x3]
	movs r1, 0x1
	bl sub_803ECB4
	movs r0, 0
	bl sub_80073B8
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetTile
	adds r4, r0, 0
	ldr r0, _080645D0
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0
	bl PrintStringOnWindow
	ldr r0, [r4, 0x14]
	bl EntityIsValid
	lsls r0, 24
	cmp r0, 0
	beq _080645C0
	ldr r1, [r4, 0x14]
	add r0, sp, 0x4
	movs r2, 0
	bl SubstitutePlaceholderStringTags
	str r5, [sp]
	movs r0, 0x8
	movs r1, 0x12
	add r2, sp, 0x4
	movs r3, 0
	bl PrintStringOnWindow
_080645C0:
	movs r0, 0
	bl sub_80073E0
	add sp, 0x54
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080645D0: .4byte gUnknown_80FE708
	thumb_func_end sub_806455C

	thumb_func_start sub_80645D4
sub_80645D4:
	push {lr}
	ldr r1, _080645F4
	movs r0, 0
	str r0, [r1]
	movs r0, 0x25
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0xC
	movs r1, 0
	bl sub_8044F5C
	bl sub_8045064
	pop {r0}
	bx r0
	.align 2, 0
_080645F4: .4byte gUnknown_202EE6C
	thumb_func_end sub_80645D4

	thumb_func_start sub_80645F8
sub_80645F8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x110
	str r0, [sp, 0xE4]
	mov r0, sp
	adds r0, 0x84
	str r0, [sp, 0xF4]
	mov r1, sp
	adds r1, 0x88
	str r1, [sp, 0xF8]
	mov r2, sp
	adds r2, 0x8C
	str r2, [sp, 0xFC]
	mov r3, sp
	adds r3, 0x8E
	str r3, [sp, 0x100]
	adds r0, 0xC
	str r0, [sp, 0x104]
	adds r1, 0xC
	str r1, [sp, 0x108]
	adds r2, 0xC
	str r2, [sp, 0x10C]
	adds r3, 0x22
	str r3, [sp, 0xEC]
	adds r0, 0x38
	str r0, [sp, 0xF0]
	add r6, sp, 0x14
	subs r1, 0x74
	str r1, [sp, 0xE8]
	add r2, sp, 0x80
	mov r10, r2
	add r3, sp, 0xE0
	mov r9, r3
_08064640:
	movs r7, 0
	mov r0, r10
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	ldr r1, [sp, 0xF4]
	str r0, [r1]
	movs r0, 0x2
	ldr r2, [sp, 0xF8]
	strh r0, [r2]
	strh r0, [r2, 0x2]
	movs r0, 0x1A
	ldr r3, [sp, 0xFC]
	strh r0, [r3]
	movs r0, 0xC
	ldr r1, [sp, 0x100]
	strh r0, [r1]
	ldr r2, [sp, 0x104]
	strh r0, [r2]
	mov r3, r9
	ldr r0, [sp, 0x108]
	str r3, [r0]
	movs r0, 0x3
	ldr r1, [sp, 0x10C]
	str r0, [r1, 0x4]
	ldr r2, [sp, 0xEC]
	str r0, [r2, 0x4]
	ldr r3, [sp, 0xF0]
	str r0, [r3, 0x4]
	ldr r0, [sp, 0xE8]
	mov r1, r10
	movs r2, 0x60
	bl memcpy
	adds r0, r6, 0
	bl sub_801317C
	movs r1, 0x1
	add r0, sp, 0xE0
	strb r1, [r0]
	movs r1, 0
	mov r0, r9
	strb r1, [r0, 0x1]
	movs r0, 0x10
	mov r2, r9
	strb r0, [r2, 0x2]
	strb r1, [r2, 0x3]
	ldr r3, [sp, 0xE4]
	movs r1, 0
	ldrsh r0, [r3, r1]
	movs r2, 0x2
	ldrsh r1, [r3, r2]
	bl GetTile
	ldr r4, [r0, 0x14]
	cmp r4, 0
	bne _080646B8
	b _080647D8
_080646B8:
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	beq _080646C4
	b _080647D8
_080646C4:
	ldr r0, [sp, 0xE8]
	movs r1, 0
	bl sub_803ECB4
	adds r0, r4, 0
	bl GetTrapData
	adds r4, r0, 0
	ldrb r1, [r4]
	mov r0, r10
	bl GetTrapName
	movs r0, 0
	bl sub_80073B8
	str r7, [sp]
	movs r0, 0x10
	movs r1, 0
	mov r2, r10
	movs r3, 0
	bl PrintStringOnWindow
	ldr r5, _08064720
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r5
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r1, 0x18
	movs r3, 0
	bl PrintStringOnWindow
	movs r0, 0
	bl sub_80073E0
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	add r1, sp, 0x4
	bl sub_8097DF0
	adds r5, r0, 0
	b _08064738
	.align 2, 0
_08064720: .4byte gTrapDescriptions
_08064724:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08064732
	ldrb r0, [r6, 0x2]
	cmp r0, 0
	beq _08064738
_08064732:
	bl sub_8083D30
	b _080647D8
_08064738:
	cmp r5, 0
	beq _08064740
	bl sub_8062500
_08064740:
	adds r0, r6, 0
	movs r1, 0
	bl nullsub_34
	movs r0, 0x16
	bl sub_803E46C
	ldr r0, _08064788
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08064760
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _08064724
_08064760:
	bl sub_8083D08
	cmp r5, 0
	beq _080647D8
	movs r4, 0
	cmp r4, r5
	blt _08064770
	b _08064640
_08064770:
	subs r3, r5, 0x1
	mov r8, r3
_08064774:
	lsls r0, r4, 2
	add r0, sp
	adds r0, 0x4
	ldr r0, [r0]
	adds r1, r6, 0
	bl sub_80639E4
	adds r7, r4, 0x1
	b _080647A0
	.align 2, 0
_08064788: .4byte gRealInputs
_0806478C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0806479A
	ldrb r0, [r6, 0x2]
	cmp r0, 0
	beq _080647A0
_0806479A:
	bl sub_8083D30
	b _080647CC
_080647A0:
	cmp r4, r8
	bge _080647A8
	bl sub_8062500
_080647A8:
	adds r0, r6, 0
	movs r1, 0
	bl nullsub_34
	movs r0, 0x16
	bl sub_803E46C
	ldr r0, _080647D4
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080647C8
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _0806478C
_080647C8:
	bl sub_8083D08
_080647CC:
	adds r4, r7, 0
	cmp r4, r5
	blt _08064774
	b _08064640
	.align 2, 0
_080647D4: .4byte gRealInputs
_080647D8:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	add sp, 0x110
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80645F8

	thumb_func_start sub_80647F0
sub_80647F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xE4
	adds r7, r0, 0
	add r0, sp, 0x68
	mov r9, r0
	mov r1, sp
	adds r1, 0x6C
	str r1, [sp, 0xD0]
	mov r2, sp
	adds r2, 0x6E
	str r2, [sp, 0xD4]
	mov r0, sp
	adds r0, 0x70
	str r0, [sp, 0xD8]
	adds r1, 0xC
	str r1, [sp, 0xDC]
	adds r2, 0x22
	str r2, [sp, 0xE0]
	adds r0, 0x38
	str r0, [sp, 0xC8]
	subs r1, 0x18
	str r1, [sp, 0xC4]
	add r2, sp, 0xC0
	mov r10, r2
	ldr r5, _0806490C
	adds r0, r7, 0x4
	str r0, [sp, 0xCC]
	ldr r1, _08064910
	mov r8, r1
	movs r6, 0
_08064834:
	movs r4, 0
	ldr r0, [sp, 0xC4]
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x64]
	movs r0, 0x2
	mov r2, r9
	strh r0, [r2]
	strh r0, [r2, 0x2]
	movs r0, 0x12
	ldr r1, [sp, 0xD0]
	strh r0, [r1]
	movs r0, 0x4
	ldr r2, [sp, 0xD4]
	strh r0, [r2]
	movs r0, 0x10
	ldr r1, [sp, 0xD8]
	strh r0, [r1]
	mov r2, r10
	str r2, [sp, 0x74]
	movs r0, 0x3
	ldr r1, [sp, 0xDC]
	str r0, [r1, 0x4]
	ldr r2, [sp, 0xE0]
	str r0, [r2, 0x4]
	ldr r1, [sp, 0xC8]
	str r0, [r1, 0x4]
	mov r0, sp
	ldr r1, [sp, 0xC4]
	movs r2, 0x60
	bl memcpy
	bl sub_8083D44
	adds r0, r7, 0x4
	mov r1, sp
	mov r2, r10
	bl sub_80649A0
	movs r0, 0x2E
	bl sub_803E46C
	adds r0, r7, 0
	bl sub_8064A18
	strh r4, [r5, 0x8]
	strh r4, [r5, 0xA]
	mov r0, sp
	movs r1, 0x16
	bl sub_805FC30
_080648A0:
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x2E
	bl sub_803E46C
	mov r2, r8
	ldrh r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080648C6
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80136E0
_080648C6:
	mov r0, r8
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080648E0
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8013744
_080648E0:
	mov r2, r8
	ldrh r1, [r2, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080648F6
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08064954
_080648F6:
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	cmp r0, 0x1
	bne _08064914
	bl sub_8083D08
	ldr r0, [sp, 0xCC]
	bl sub_8064A3C
	movs r4, 0x2
	b _0806496E
	.align 2, 0
_0806490C: .4byte gUnknown_202EE10
_08064910: .4byte gRealInputs
_08064914:
	movs r2, 0x18
	ldrsh r0, [r5, r2]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	beq _08064950
	ldr r4, [r7, 0x70]
	adds r4, 0x44
	ldr r1, _0806494C
	movs r2, 0x18
	ldrsh r0, [r5, r2]
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	bl SetMonsterActionFields
	bl sub_8083D08
	strb r6, [r4, 0x4]
	strh r6, [r4, 0x8]
	strh r6, [r4, 0xA]
	strb r6, [r4, 0xC]
	strh r6, [r4, 0x10]
	strh r6, [r4, 0x12]
	movs r4, 0
	b _0806496E
	.align 2, 0
_0806494C: .4byte gUnknown_202EE44
_08064950:
	bl sub_8083D30
_08064954:
	mov r0, r8
	ldrh r1, [r0, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08064968
	ldr r1, _08064998
	ldrb r0, [r1]
	cmp r0, 0
	beq _080648A0
_08064968:
	bl sub_8083D30
	movs r4, 0x1
_0806496E:
	ldr r0, _0806499C
	bl AddMenuCursorSprite
	movs r0, 0x2E
	bl sub_803E46C
	cmp r4, 0x2
	bne _08064980
	b _08064834
_08064980:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	add sp, 0xE4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08064998: .4byte gUnknown_202EE3A
_0806499C: .4byte gUnknown_202EE10
	thumb_func_end sub_80647F0

	thumb_func_start sub_80649A0
sub_80649A0:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r0, r1, 0
	movs r3, 0
	movs r1, 0x1
	strb r1, [r2]
	strb r3, [r2, 0x1]
	movs r1, 0xB
	strb r1, [r2, 0x2]
	strb r3, [r2, 0x3]
	movs r1, 0x1
	bl sub_803ECB4
	movs r0, 0
	bl sub_80073B8
	bl GetFloorType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080649E4
	cmp r0, 0x1
	ble _080649D4
	cmp r0, 0x2
	beq _080649DC
_080649D4:
	ldr r0, _080649D8
	b _080649E6
	.align 2, 0
_080649D8: .4byte gUnknown_80FE70C
_080649DC:
	ldr r0, _080649E0
	b _080649E6
	.align 2, 0
_080649E0: .4byte gUnknown_80FE720
_080649E4:
	ldr r0, _08064A14
_080649E6:
	ldr r5, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0xC
	movs r1, 0
	adds r2, r5, 0
	movs r3, 0
	bl PrintStringOnWindow
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x12
	adds r2, r5, 0
	movs r3, 0
	bl PrintStringOnWindow
	movs r0, 0
	bl sub_80073E0
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08064A14: .4byte gUnknown_80FE724
	thumb_func_end sub_80649A0

	thumb_func_start sub_8064A18
sub_8064A18:
	push {lr}
	ldr r1, _08064A38
	movs r0, 0
	str r0, [r1]
	movs r0, 0x26
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0xC
	movs r1, 0
	bl sub_8044F5C
	bl sub_8045064
	pop {r0}
	bx r0
	.align 2, 0
_08064A38: .4byte gUnknown_202EE6C
	thumb_func_end sub_8064A18

	thumb_func_start sub_8064A3C
sub_8064A3C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xE8
	mov r0, sp
	adds r0, 0x20
	str r0, [sp, 0xE4]
	add r1, sp, 0x80
	mov r10, r1
	add r0, sp, 0xE0
	mov r9, r0
	add r5, sp, 0x14
_08064A58:
	mov r0, r10
	movs r1, 0
	movs r2, 0x60
	bl memset
	add r1, sp, 0x84
	movs r0, 0x6
	str r0, [r1]
	add r0, sp, 0x88
	movs r1, 0x2
	strh r1, [r0]
	strh r1, [r0, 0x2]
	add r1, sp, 0x8C
	movs r0, 0x1A
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x8E
	movs r1, 0xC
	strh r1, [r0]
	add r0, sp, 0x90
	strh r1, [r0]
	add r0, sp, 0x94
	mov r1, r9
	str r1, [r0]
	add r0, sp, 0x98
	movs r1, 0x3
	str r1, [r0, 0x4]
	add r0, sp, 0xB0
	str r1, [r0, 0x4]
	add r0, sp, 0xC8
	str r1, [r0, 0x4]
	ldr r0, [sp, 0xE4]
	mov r1, r10
	movs r2, 0x60
	bl memcpy
	add r0, sp, 0x14
	bl sub_801317C
	movs r0, 0x1
	mov r1, r9
	strb r0, [r1]
	movs r0, 0
	strb r0, [r1, 0x1]
	movs r0, 0x10
	strb r0, [r1, 0x2]
	movs r0, 0
	strb r0, [r1, 0x3]
	ldr r0, [sp, 0xE4]
	movs r1, 0
	bl sub_803ECB4
	bl GetFloorType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08064B0C
	lsls r4, 2
	adds r0, r4, r0
	ldr r2, [r0]
	movs r1, 0
	str r1, [sp]
	movs r0, 0x10
	movs r3, 0
	bl PrintStringOnWindow
	ldr r0, _08064B10
	adds r4, r0
	ldr r4, [r4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x18
	adds r2, r4, 0
	movs r3, 0
	bl PrintStringOnWindow
	movs r0, 0
	bl sub_80073E0
	adds r0, r4, 0
	add r1, sp, 0x4
	bl sub_8097DF0
	adds r6, r0, 0
	b _08064B28
	.align 2, 0
_08064B0C: .4byte gUnknown_80F8104
_08064B10: .4byte gUnknown_80F7F70
_08064B14:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08064B22
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	beq _08064B28
_08064B22:
	bl sub_8083D30
	b _08064BC8
_08064B28:
	cmp r6, 0
	beq _08064B30
	bl sub_8062500
_08064B30:
	adds r0, r5, 0
	movs r1, 0
	bl nullsub_34
	movs r0, 0x16
	bl sub_803E46C
	ldr r0, _08064B78
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08064B50
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	beq _08064B14
_08064B50:
	bl sub_8083D08
	cmp r6, 0
	beq _08064BC8
	movs r4, 0
	cmp r4, r6
	blt _08064B60
	b _08064A58
_08064B60:
	subs r1, r6, 0x1
	mov r8, r1
_08064B64:
	lsls r0, r4, 2
	add r0, sp
	adds r0, 0x4
	ldr r0, [r0]
	adds r1, r5, 0
	bl sub_80639E4
	adds r7, r4, 0x1
	b _08064B90
	.align 2, 0
_08064B78: .4byte gRealInputs
_08064B7C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08064B8A
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	beq _08064B90
_08064B8A:
	bl sub_8083D30
	b _08064BBC
_08064B90:
	cmp r4, r8
	bge _08064B98
	bl sub_8062500
_08064B98:
	adds r0, r5, 0
	movs r1, 0
	bl nullsub_34
	movs r0, 0x16
	bl sub_803E46C
	ldr r0, _08064BC4
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08064BB8
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	beq _08064B7C
_08064BB8:
	bl sub_8083D08
_08064BBC:
	adds r4, r7, 0
	cmp r4, r6
	blt _08064B64
	b _08064A58
	.align 2, 0
_08064BC4: .4byte gRealInputs
_08064BC8:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	add sp, 0xE8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8064A3C

	thumb_func_start sub_8064BE0
sub_8064BE0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, _08064C94
	ldr r0, [r0]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x4
	mov r9, r1
	cmp r0, 0
	beq _08064C02
	movs r0, 0x5
	mov r9, r0
_08064C02:
	ldr r1, _08064C98
	movs r0, 0
	str r0, [r1]
	mov r10, r0
	ldr r6, _08064C9C
	ldr r7, _08064CA0
	movs r1, 0x2A
	adds r1, r6
	mov r8, r1
_08064C14:
	movs r5, 0
	bl sub_8065250
_08064C1A:
	adds r0, r6, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	ldrh r1, [r7, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08064C3E
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80136E0
_08064C3E:
	ldrh r1, [r7, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08064C56
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8013744
_08064C56:
	ldrh r1, [r7, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08064C6A
	adds r0, r6, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08064CAA
_08064C6A:
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	cmp r0, 0x4
	bne _08064C8C
	ldr r0, _08064C94
	ldr r0, [r0]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08064CA4
	bl IsBossFight
	lsls r0, 24
	cmp r0, 0
	bne _08064CA4
_08064C8C:
	bl sub_8083D08
	b _08064CC0
	.align 2, 0
_08064C94: .4byte gDungeon
_08064C98: .4byte gUnknown_202F2E0
_08064C9C: .4byte gUnknown_202EE10
_08064CA0: .4byte gRealInputs
_08064CA4:
	bl sub_8083D30
	b _08064CC0
_08064CAA:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08064CBA
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _08064C1A
_08064CBA:
	bl sub_8083D30
	movs r5, 0x1
_08064CC0:
	ldr r4, _08064D68
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	mov r0, r10
	cmp r0, 0
	bne _08064C14
	cmp r5, 0
	bne _08064D4C
	ldr r5, _08064D6C
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	str r0, [r5]
	cmp r0, 0
	bne _08064CE8
	bl sub_8064D74
_08064CE8:
	ldr r0, [r5]
	cmp r0, 0x1
	bne _08064CF2
	bl sub_80650C0
_08064CF2:
	ldr r0, [r5]
	cmp r0, 0x2
	bne _08064CFC
	bl DisplayMessageLog
_08064CFC:
	ldr r0, [r5]
	cmp r0, 0x3
	bne _08064D06
	bl sub_806519C
_08064D06:
	ldr r0, _08064D70
	ldr r0, [r0]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08064D2A
	bl IsBossFight
	lsls r0, 24
	cmp r0, 0
	bne _08064D2A
	ldr r0, [r5]
	cmp r0, 0x4
	bne _08064D2A
	bl sub_8065FB4
_08064D2A:
	ldr r0, _08064D6C
	ldr r0, [r0]
	cmp r0, r9
	bne _08064D36
	bl sub_8065BF4
_08064D36:
	ldr r0, _08064D70
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _08064D4C
	bl GetLeaderActionId
	lsls r0, 16
	cmp r0, 0
	bne _08064D4C
	b _08064C14
_08064D4C:
	bl sub_8040A84
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08064D68: .4byte gUnknown_202EE10
_08064D6C: .4byte gUnknown_202F2E0
_08064D70: .4byte gDungeon
	thumb_func_end sub_8064BE0

	thumb_func_start sub_8064D74
sub_8064D74:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r6, _08064DE0
	ldr r7, _08064DE4
	movs r0, 0x2A
	adds r0, r6
	mov r8, r0
_08064D84:
	movs r5, 0
	bl CreateFieldGameOptionsMenu
_08064D8A:
	adds r0, r6, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	ldrh r1, [r7, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08064DAE
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80136E0
_08064DAE:
	ldrh r1, [r7, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08064DC6
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8013744
_08064DC6:
	ldrh r1, [r7, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08064DDA
	adds r0, r6, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08064DE8
_08064DDA:
	bl sub_8083D08
	b _08064DFE
	.align 2, 0
_08064DE0: .4byte gUnknown_202EE10
_08064DE4: .4byte gRealInputs
_08064DE8:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08064DF8
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _08064D8A
_08064DF8:
	bl sub_8083D30
	movs r5, 0x1
_08064DFE:
	ldr r4, _08064E2C
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	cmp r5, 0
	bne _08064E56
	ldr r0, _08064E30
	ldr r1, _08064E34
	ldr r0, [r0]
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08064E38
	bl sub_8064E68
	b _08064E40
	.align 2, 0
_08064E2C: .4byte gUnknown_202EE10
_08064E30: .4byte gGameOptionsRef
_08064E34: .4byte gUnknown_202F2E8
_08064E38:
	cmp r0, 0x1
	bne _08064E4C
	bl sub_8064F50
_08064E40:
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_8065040
	b _08064D84
_08064E4C:
	cmp r0, 0x2
	bne _08064D84
	bl sub_806509C
	b _08064D84
_08064E56:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8064D74

	thumb_func_start sub_8064E68
sub_8064E68:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	ldr r0, _08064EDC
	strh r7, [r0, 0x18]
	adds r4, r0, 0
	ldr r6, _08064EE0
	movs r0, 0x2A
	adds r0, r4
	mov r8, r0
_08064E7E:
	movs r7, 0
	movs r5, 0
	bl CreateFieldDungeonMenu
_08064E86:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08064EAA
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_08064EAA:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08064EC2
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_08064EC2:
	ldrh r1, [r6, 0x4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08064EE4
	movs r0, 0
	bl sub_8083CE0
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	bl sub_8065A8C
	b _08064F2E
	.align 2, 0
_08064EDC: .4byte gUnknown_202EE10
_08064EE0: .4byte gRealInputs
_08064EE4:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08064EFC
	movs r0, 0
	bl sub_8083CE0
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	bl sub_8065B3C
	b _08064F2E
_08064EFC:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08064F0E
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0
	beq _08064F14
_08064F0E:
	bl sub_8083D08
	b _08064F30
_08064F14:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08064F24
	bl sub_8083D30
	movs r7, 0x1
	b _08064F30
_08064F24:
	bl sub_8065BEC
	lsls r0, 24
	cmp r0, 0
	beq _08064E86
_08064F2E:
	movs r5, 0x1
_08064F30:
	ldr r0, _08064F4C
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	cmp r5, 0
	bne _08064E7E
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08064F4C: .4byte gUnknown_202EE10
	thumb_func_end sub_8064E68

	thumb_func_start sub_8064F50
sub_8064F50:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	ldr r0, _08064FC8
	strh r7, [r0, 0x18]
	adds r4, r0, 0
	ldr r6, _08064FCC
	movs r0, 0x2A
	adds r0, r4
	mov r8, r0
_08064F66:
	movs r7, 0
	movs r5, 0
	bl CreateFieldOthersMenu
_08064F6E:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08064F92
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_08064F92:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08064FAA
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_08064FAA:
	ldrh r1, [r6, 0x4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08064FD0
	movs r0, 0
	bl sub_8083CE0
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	adds r0, 0x5
	bl sub_8065A8C
	b _0806501C
	.align 2, 0
_08064FC8: .4byte gUnknown_202EE10
_08064FCC: .4byte gRealInputs
_08064FD0:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08064FEA
	movs r0, 0
	bl sub_8083CE0
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	adds r0, 0x5
	bl sub_8065B3C
	b _0806501C
_08064FEA:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08064FFC
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0
	beq _08065002
_08064FFC:
	bl sub_8083D08
	b _0806501E
_08065002:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08065012
	bl sub_8083D30
	movs r7, 0x1
	b _0806501E
_08065012:
	bl sub_8065BF0
	lsls r0, 24
	cmp r0, 0
	beq _08064F6E
_0806501C:
	movs r5, 0x1
_0806501E:
	ldr r0, _0806503C
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	cmp r5, 0
	bne _08064F66
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806503C: .4byte gUnknown_202EE10
	thumb_func_end sub_8064F50

	thumb_func_start sub_8065040
sub_8065040:
	push {r4,lr}
	lsls r0, 24
	movs r4, 0
	cmp r0, 0
	beq _0806505C
	ldr r0, _08065058
	bl GameOptionsNotChange
	lsls r0, 24
	cmp r0, 0
	bne _0806505E
	b _08065062
	.align 2, 0
_08065058: .4byte gUnknown_202F2E8
_0806505C:
	movs r4, 0x1
_0806505E:
	cmp r4, 0
	beq _08065088
_08065062:
	ldr r0, _08065090
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonYesNoMessage
	cmp r0, 0x1
	bne _08065088
	ldr r0, _08065094
	ldr r1, [r0]
	ldr r0, _08065098
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	bl sub_803E13C
	bl sub_8040238
_08065088:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08065090: .4byte gUnknown_80FEBF8
_08065094: .4byte gGameOptionsRef
_08065098: .4byte gUnknown_202F2E8
	thumb_func_end sub_8065040

	thumb_func_start sub_806509C
sub_806509C:
	push {lr}
	ldr r0, _080650BC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl DisplayDungeonYesNoMessage
	cmp r0, 0x1
	bne _080650B8
	movs r0, 0
	bl InitializeGameOptions
	bl sub_803E13C
_080650B8:
	pop {r0}
	bx r0
	.align 2, 0
_080650BC: .4byte gUnknown_80FEC28
	thumb_func_end sub_806509C

	thumb_func_start sub_80650C0
sub_80650C0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0
	mov r9, r0
	ldr r5, _08065134
	ldr r6, _08065138
	movs r1, 0x2A
	adds r1, r5
	mov r8, r1
_080650D6:
	movs r7, 0
	bl sub_806544C
_080650DC:
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08065100
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80136E0
_08065100:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08065118
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8013744
_08065118:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0806512C
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806513C
_0806512C:
	bl sub_8083D08
	b _08065152
	.align 2, 0
_08065134: .4byte gUnknown_202EE10
_08065138: .4byte gRealInputs
_0806513C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0806514C
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _080650DC
_0806514C:
	bl sub_8083D30
	movs r7, 0x1
_08065152:
	ldr r4, _08065178
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	mov r0, r9
	cmp r0, 0
	bne _080650D6
	cmp r7, 0
	bne _0806518E
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _0806517C
	bl sub_80651D0
	b _08065184
	.align 2, 0
_08065178: .4byte gUnknown_202EE10
_0806517C:
	cmp r0, 0x1
	bne _08065184
	bl sub_80651FC
_08065184:
	bl GetLeaderActionId
	lsls r0, 16
	cmp r0, 0
	beq _080650D6
_0806518E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80650C0

	thumb_func_start sub_806519C
sub_806519C:
	push {lr}
	ldr r0, _080651CC
	ldr r1, [r0]
	movs r2, 0xCF
	lsls r2, 3
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r2, 0x34
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0
	bl sub_80319A4
_080651B6:
	movs r0, 0x47
	bl sub_803E46C
	bl sub_80319F8
	cmp r0, 0
	beq _080651B6
	bl sub_8031A3C
	pop {r0}
	bx r0
	.align 2, 0
_080651CC: .4byte gDungeon
	thumb_func_end sub_806519C

	thumb_func_start sub_80651D0
sub_80651D0:
	push {lr}
	ldr r0, _080651F0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl DisplayDungeonYesNoMessage
	cmp r0, 0x1
	bne _080651F4
	bl GetLeaderActionContainer
	movs r1, 0x2B
	bl SetMonsterActionFields
	movs r0, 0
	b _080651F6
	.align 2, 0
_080651F0: .4byte gUnknown_80FDE6C
_080651F4:
	movs r0, 0x1
_080651F6:
	pop {r1}
	bx r1
	thumb_func_end sub_80651D0

	thumb_func_start sub_80651FC
sub_80651FC:
	push {r4,r5,lr}
	ldr r0, _08065238
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl DisplayDungeonYesNoMessage
	adds r5, r0, 0
	cmp r5, 0x1
	bne _08065248
	bl GetLeaderActionContainer
	movs r1, 0x2E
	bl SetMonsterActionFields
	ldr r4, _0806523C
	bl GetLeader
	adds r2, r0, 0
	adds r0, r4, 0
	movs r1, 0
	bl sub_8083AB0
	ldr r0, _08065240
	ldr r0, [r0]
	ldr r1, _08065244
	adds r0, r1
	strb r5, [r0]
	movs r0, 0
	b _0806524A
	.align 2, 0
_08065238: .4byte gUnknown_80FDEB8
_0806523C: .4byte 0x0000021b
_08065240: .4byte gDungeon
_08065244: .4byte 0x00000654
_08065248:
	movs r0, 0x1
_0806524A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80651FC

	thumb_func_start sub_8065250
sub_8065250:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC8
	add r5, sp, 0x64
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x68]
	add r0, sp, 0x6C
	movs r4, 0
	movs r7, 0
	movs r1, 0x2
	mov r9, r1
	mov r1, r9
	strh r1, [r0]
	strh r1, [r0, 0x2]
	add r0, sp, 0x70
	movs r1, 0x12
	mov r10, r1
	mov r1, r10
	strh r1, [r0]
	adds r0, 0x2
	movs r1, 0x10
	mov r8, r1
	mov r1, r8
	strh r1, [r0]
	add r0, sp, 0x74
	strh r1, [r0]
	add r6, sp, 0xC4
	str r6, [sp, 0x78]
	movs r1, 0x3
	str r1, [sp, 0x80]
	add r0, sp, 0x94
	str r1, [r0, 0x4]
	add r0, sp, 0xAC
	str r1, [r0, 0x4]
	add r0, sp, 0x4
	adds r1, r5, 0
	movs r2, 0x60
	bl memcpy
	movs r0, 0x1
	strb r0, [r6]
	strb r4, [r6, 0x1]
	strb r4, [r6, 0x3]
	ldr r4, _080653D0
	ldr r0, _080653D4
	ldr r0, [r0]
	strh r0, [r4, 0x18]
	ldr r1, _080653D8
	ldr r0, [r1]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	movs r5, 0x5
	cmp r0, 0
	beq _080652D2
	movs r5, 0x6
_080652D2:
	strh r5, [r4, 0x1A]
	strh r5, [r4, 0x1C]
	strh r7, [r4, 0x1E]
	strh r7, [r4, 0x20]
	strh r7, [r4, 0x4]
	mov r0, r8
	strh r0, [r4, 0x6]
	strh r7, [r4, 0xC]
	strh r7, [r4, 0xE]
	strh r7, [r4, 0x14]
	str r7, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	add r0, sp, 0x4
	mov r1, r10
	strh r1, [r0, 0xC]
	adds r0, r5, 0
	movs r1, 0xC
	bl sub_80095E4
	add r2, sp, 0x4
	adds r1, r2, 0
	adds r0, 0x2
	strh r0, [r1, 0x10]
	strh r0, [r2, 0xE]
	movs r0, 0xA
	strb r0, [r6, 0x2]
	adds r0, r1, 0
	mov r1, r9
	strh r1, [r0, 0x8]
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	movs r0, 0
	bl sub_80073B8
	movs r5, 0
	ldr r0, _080653DC
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	adds r0, r4, 0
	movs r1, 0
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r0, _080653E0
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r0, _080653E4
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r0, _080653E8
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r5, 0x4
	adds r0, r4, 0
	movs r1, 0x3
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r0, _080653EC
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, _080653D8
	ldr r0, [r1]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806540E
	bl IsBossFight
	lsls r0, 24
	cmp r0, 0
	bne _080653F4
	movs r5, 0x5
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r0, _080653F0
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	b _0806540E
	.align 2, 0
_080653D0: .4byte gUnknown_202EE10
_080653D4: .4byte gUnknown_202F2E0
_080653D8: .4byte gDungeon
_080653DC: .4byte gUnknown_80FE8F8
_080653E0: .4byte gUnknown_80FE9CC
_080653E4: .4byte gUnknown_80FE9E8
_080653E8: .4byte gUnknown_80FE9F8
_080653EC: .4byte gUnknown_80FEA10
_080653F0: .4byte gUnknown_80FEA28
_080653F4:
	movs r5, 0x5
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r0, _08065440
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
_0806540E:
	ldr r0, _08065444
	adds r1, r5, 0
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r0, _08065448
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	add sp, 0xC8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065440: .4byte gUnknown_80FEA44
_08065444: .4byte gUnknown_202EE10
_08065448: .4byte gUnknown_80FEA50
	thumb_func_end sub_8065250

	thumb_func_start sub_806544C
sub_806544C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC8
	add r0, sp, 0x64
	mov r10, r0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x68]
	add r0, sp, 0x6C
	movs r4, 0
	movs r5, 0
	movs r1, 0x2
	mov r9, r1
	mov r2, r9
	strh r2, [r0]
	strh r2, [r0, 0x2]
	add r0, sp, 0x70
	movs r7, 0x12
	strh r7, [r0]
	adds r0, 0x2
	movs r6, 0x10
	strh r6, [r0]
	add r0, sp, 0x74
	strh r6, [r0]
	add r0, sp, 0xC4
	mov r8, r0
	str r0, [sp, 0x78]
	movs r1, 0x3
	str r1, [sp, 0x80]
	add r0, sp, 0x94
	str r1, [r0, 0x4]
	add r0, sp, 0xAC
	str r1, [r0, 0x4]
	add r0, sp, 0x4
	mov r1, r10
	movs r2, 0x60
	bl memcpy
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	strb r4, [r1, 0x1]
	strb r4, [r1, 0x3]
	ldr r4, _08065568
	strh r5, [r4, 0x18]
	mov r2, r9
	strh r2, [r4, 0x1A]
	strh r2, [r4, 0x1C]
	strh r5, [r4, 0x1E]
	strh r5, [r4, 0x20]
	strh r5, [r4, 0x4]
	strh r6, [r4, 0x6]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	strh r5, [r4, 0x14]
	str r5, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	add r0, sp, 0x4
	strh r7, [r0, 0xC]
	movs r0, 0x2
	movs r1, 0xC
	bl sub_80095E4
	add r2, sp, 0x4
	adds r1, r2, 0
	adds r0, 0x2
	strh r0, [r1, 0x10]
	strh r0, [r2, 0xE]
	movs r0, 0xA
	mov r1, r8
	strb r0, [r1, 0x2]
	adds r0, r2, 0
	mov r2, r9
	strh r2, [r0, 0x8]
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	movs r0, 0
	bl sub_80073B8
	ldr r0, _0806556C
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	adds r0, r4, 0
	movs r1, 0
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldr r6, _08065570
	movs r2, 0xAC
	lsls r2, 1
	adds r0, r6, r2
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r6, r2
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	add sp, 0xC8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065568: .4byte gUnknown_202EE10
_0806556C: .4byte gUnknown_80FE8F4
_08065570: .4byte gUnknown_80F7C50
	thumb_func_end sub_806544C

	thumb_func_start CreateFieldGameOptionsMenu
CreateFieldGameOptionsMenu:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xD4
	add r0, sp, 0x10
	mov r10, r0
	add r7, sp, 0x70
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x74]
	add r0, sp, 0x78
	movs r4, 0
	movs r6, 0
	movs r1, 0x2
	strh r1, [r0]
	strh r1, [r0, 0x2]
	add r0, sp, 0x7C
	movs r1, 0xC
	strh r1, [r0]
	adds r0, 0x2
	movs r1, 0x10
	mov r9, r1
	mov r1, r9
	strh r1, [r0]
	add r0, sp, 0x80
	strh r1, [r0]
	add r0, sp, 0x84
	add r1, sp, 0xD0
	mov r8, r1
	str r1, [r0]
	add r0, sp, 0x88
	movs r5, 0x3
	str r5, [r0, 0x4]
	add r0, sp, 0xA0
	str r5, [r0, 0x4]
	add r0, sp, 0xB8
	str r5, [r0, 0x4]
	mov r0, r10
	adds r1, r7, 0
	movs r2, 0x60
	bl memcpy
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	strb r4, [r1, 0x1]
	strb r4, [r1, 0x3]
	ldr r4, _080656AC
	strh r6, [r4, 0x18]
	strh r5, [r4, 0x1A]
	strh r5, [r4, 0x1C]
	strh r6, [r4, 0x1E]
	strh r6, [r4, 0x20]
	strh r6, [r4, 0x4]
	mov r0, r9
	strh r0, [r4, 0x6]
	strh r6, [r4, 0xC]
	strh r6, [r4, 0xE]
	strh r6, [r4, 0x14]
	str r6, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	movs r0, 0xC
	mov r1, r10
	strh r0, [r1, 0xC]
	movs r0, 0x3
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	mov r1, r10
	strh r0, [r1, 0x10]
	strh r0, [r1, 0xE]
	movs r0, 0xA
	mov r1, r8
	strb r0, [r1, 0x2]
	movs r1, 0x2
	mov r0, r10
	strh r1, [r0, 0x8]
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	adds r0, r4, 0
	movs r1, 0
	bl GetMenuEntryYCoord
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMenuEntryYCoord
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMenuEntryYCoord
	str r0, [sp, 0xC]
	movs r0, 0
	bl sub_80073B8
	ldr r0, _080656B0
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0x4]
	ldr r0, _080656B4
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0x8]
	ldr r0, _080656B8
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0xC]
	ldr r0, _080656BC
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	add sp, 0xD4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080656AC: .4byte gUnknown_202EE10
_080656B0: .4byte gGameOptionsTextPtr
_080656B4: .4byte gOptionsDungeonTextPtr
_080656B8: .4byte gOptionsOthersTextPtr
_080656BC: .4byte gUnknown_80FE748
	thumb_func_end CreateFieldGameOptionsMenu

	thumb_func_start CreateFieldDungeonMenu
CreateFieldDungeonMenu:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xDC
	add r0, sp, 0x18
	mov r9, r0
	add r7, sp, 0x78
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x7C]
	add r0, sp, 0x80
	movs r5, 0
	movs r1, 0x2
	mov r10, r1
	mov r2, r10
	strh r2, [r0]
	strh r2, [r0, 0x2]
	add r1, sp, 0x84
	movs r0, 0x12
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x86
	movs r3, 0x10
	mov r8, r3
	mov r4, r8
	strh r4, [r0]
	add r0, sp, 0x88
	strh r4, [r0]
	add r0, sp, 0x8C
	add r6, sp, 0xD8
	str r6, [r0]
	add r0, sp, 0x90
	movs r1, 0x3
	str r1, [r0, 0x4]
	add r0, sp, 0xA8
	str r1, [r0, 0x4]
	add r0, sp, 0xC0
	str r1, [r0, 0x4]
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x60
	bl memcpy
	adds r1, r7, 0
	ldr r0, _0806583C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	movs r0, 0x1
	strb r0, [r6]
	movs r0, 0
	strb r0, [r6, 0x1]
	strb r0, [r6, 0x3]
	ldr r4, _08065840
	movs r0, 0x5
	strh r0, [r4, 0x1A]
	strh r0, [r4, 0x1C]
	strh r5, [r4, 0x1E]
	strh r5, [r4, 0x20]
	strh r5, [r4, 0x4]
	mov r1, r8
	strh r1, [r4, 0x6]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	strh r5, [r4, 0x14]
	str r5, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	movs r0, 0x18
	mov r2, r9
	strh r0, [r2, 0xC]
	movs r0, 0x5
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	mov r3, r9
	strh r0, [r3, 0x10]
	strh r0, [r3, 0xE]
	movs r0, 0xA
	strb r0, [r6, 0x2]
	mov r0, r10
	strh r0, [r3, 0x8]
	mov r0, r9
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	adds r0, r4, 0
	movs r1, 0
	bl GetMenuEntryYCoord
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMenuEntryYCoord
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x2
	bl GetMenuEntryYCoord
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0x3
	bl GetMenuEntryYCoord
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x4
	bl GetMenuEntryYCoord
	str r0, [sp, 0x14]
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08065844
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0x4]
	ldr r0, _08065848
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0x8]
	ldr r0, _0806584C
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0xC]
	ldr r0, _08065850
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0x10]
	ldr r0, _08065854
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [sp, 0x14]
	ldr r0, _08065858
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r0, _0806585C
	ldrb r0, [r0]
	adds r4, r7, 0
	cmp r0, 0
	beq _08065860
	ldr r2, [sp, 0x4]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x88
	movs r3, 0x15
	bl sub_80078A4
	b _08065872
	.align 2, 0
_0806583C: .4byte gUnknown_8106CE8
_08065840: .4byte gUnknown_202EE10
_08065844: .4byte gOptionsDungeonTextPtr
_08065848: .4byte gUnknown_80FE764
_0806584C: .4byte gUnknown_80FE788
_08065850: .4byte gUnknown_80FE7A8
_08065854: .4byte gUnknown_80FE7C0
_08065858: .4byte gUnknown_80FE7E4
_0806585C: .4byte gUnknown_202F2E8
_08065860:
	ldr r2, [sp, 0x4]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x50
	movs r3, 0x16
	bl sub_80078A4
_08065872:
	ldr r0, _08065890
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08065894
	ldr r2, [sp, 0x8]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x88
	movs r3, 0x16
	bl sub_80078A4
	b _080658A6
	.align 2, 0
_08065890: .4byte gUnknown_202F2E8
_08065894:
	ldr r2, [sp, 0x8]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x50
	movs r3, 0x12
	bl sub_80078A4
_080658A6:
	ldr r0, _080658C4
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _080658C8
	ldr r2, [sp, 0xC]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x88
	movs r3, 0x10
	bl sub_80078A4
	b _080658DA
	.align 2, 0
_080658C4: .4byte gUnknown_202F2E8
_080658C8:
	ldr r2, [sp, 0xC]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x50
	movs r3, 0xC
	bl sub_80078A4
_080658DA:
	ldr r0, _080658F8
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _080658FC
	ldr r2, [sp, 0x10]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x88
	movs r3, 0xC
	bl sub_80078A4
	b _0806590E
	.align 2, 0
_080658F8: .4byte gUnknown_202F2E8
_080658FC:
	ldr r2, [sp, 0x10]
	adds r2, 0xA
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x50
	movs r3, 0x10
	bl sub_80078A4
_0806590E:
	ldr r0, _08065944
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 2
	adds r1, r0, r1
	lsls r1, 3
	adds r1, 0x50
	ldr r2, [sp, 0x14]
	adds r2, 0xA
	adds r0, r4, r0
	ldr r3, [r0]
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	bl sub_80078A4
	movs r0, 0
	bl sub_80073E0
	add sp, 0xDC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065944: .4byte gUnknown_202F2E8
	thumb_func_end CreateFieldDungeonMenu

	thumb_func_start CreateFieldOthersMenu
CreateFieldOthersMenu:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xCC
	add r0, sp, 0x64
	mov r10, r0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x68]
	add r0, sp, 0x6C
	movs r4, 0
	movs r5, 0
	movs r1, 0x2
	mov r9, r1
	mov r2, r9
	strh r2, [r0]
	strh r2, [r0, 0x2]
	add r1, sp, 0x70
	movs r0, 0x12
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x72
	movs r6, 0x10
	strh r6, [r0]
	add r0, sp, 0x74
	strh r6, [r0]
	add r3, sp, 0xC4
	mov r8, r3
	str r3, [sp, 0x78]
	movs r1, 0x3
	str r1, [sp, 0x80]
	add r0, sp, 0x94
	str r1, [r0, 0x4]
	add r0, sp, 0xAC
	str r1, [r0, 0x4]
	add r0, sp, 0x4
	mov r1, r10
	movs r2, 0x60
	bl memcpy
	mov r1, r10
	ldr r0, _08065A78
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	movs r0, 0x1
	mov r7, r8
	strb r0, [r7]
	strb r4, [r7, 0x1]
	strb r4, [r7, 0x3]
	ldr r4, _08065A7C
	strh r0, [r4, 0x1A]
	strh r0, [r4, 0x1C]
	strh r5, [r4, 0x1E]
	strh r5, [r4, 0x20]
	strh r5, [r4, 0x4]
	strh r6, [r4, 0x6]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	strh r5, [r4, 0x14]
	str r5, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	add r1, sp, 0x4
	movs r0, 0x18
	strh r0, [r1, 0xC]
	movs r0, 0x1
	movs r1, 0xC
	bl sub_80095E4
	add r2, sp, 0x4
	adds r1, r2, 0
	adds r0, 0x2
	strh r0, [r1, 0x10]
	strh r0, [r2, 0xE]
	movs r0, 0xA
	strb r0, [r7, 0x2]
	adds r0, r1, 0
	mov r1, r9
	strh r1, [r0, 0x8]
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	movs r4, 0
	mov r7, r10
	add r6, sp, 0xC8
	adds r5, r6, 0
_08065A0A:
	ldr r0, _08065A7C
	adds r1, r4, 0
	bl GetMenuEntryYCoord
	stm r5!, {r0}
	adds r4, 0x1
	cmp r4, 0
	ble _08065A0A
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08065A80
	ldr r2, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, [r6]
	ldr r0, _08065A84
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r0, _08065A88
	ldrb r1, [r0, 0x8]
	lsls r3, r1, 2
	adds r1, r3, r1
	lsls r1, 3
	adds r1, 0x50
	add r0, sp, 0xC8
	ldr r2, [r0]
	adds r2, 0xA
	adds r3, r7, r3
	ldr r3, [r3]
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0
	bl sub_80078A4
	movs r0, 0
	bl sub_80073E0
	add sp, 0xCC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065A78: .4byte gUnknown_8106CF4
_08065A7C: .4byte gUnknown_202EE10
_08065A80: .4byte gOptionsOthersTextPtr
_08065A84: .4byte gOptionsWindowColorPtr
_08065A88: .4byte gUnknown_202F2E8
	thumb_func_end CreateFieldOthersMenu

	thumb_func_start sub_8065A8C
sub_8065A8C:
	push {lr}
	cmp r0, 0x5
	bhi _08065B38
	lsls r0, 2
	ldr r1, _08065A9C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08065A9C: .4byte _08065AA0
	.align 2, 0
_08065AA0:
	.4byte _08065AB8
	.4byte _08065ACC
	.4byte _08065AE0
	.4byte _08065AF4
	.4byte _08065B08
	.4byte _08065B22
_08065AB8:
	ldr r2, _08065AC8
	movs r1, 0
	ldrb r0, [r2]
	cmp r0, 0
	bne _08065AC4
	movs r1, 0x1
_08065AC4:
	strb r1, [r2]
	b _08065B38
	.align 2, 0
_08065AC8: .4byte gUnknown_202F2E8
_08065ACC:
	ldr r2, _08065ADC
	movs r1, 0
	ldrb r0, [r2, 0x1]
	cmp r0, 0
	bne _08065AD8
	movs r1, 0x1
_08065AD8:
	strb r1, [r2, 0x1]
	b _08065B38
	.align 2, 0
_08065ADC: .4byte gUnknown_202F2E8
_08065AE0:
	ldr r2, _08065AF0
	movs r1, 0
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _08065AEC
	movs r1, 0x1
_08065AEC:
	strb r1, [r2, 0x2]
	b _08065B38
	.align 2, 0
_08065AF0: .4byte gUnknown_202F2E8
_08065AF4:
	ldr r2, _08065B04
	movs r1, 0
	ldrb r0, [r2, 0x3]
	cmp r0, 0
	bne _08065B00
	movs r1, 0x1
_08065B00:
	strb r1, [r2, 0x3]
	b _08065B38
	.align 2, 0
_08065B04: .4byte gUnknown_202F2E8
_08065B08:
	ldr r1, _08065B18
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08065B1C
	movs r0, 0x2
	strb r0, [r1, 0x4]
	b _08065B38
	.align 2, 0
_08065B18: .4byte gUnknown_202F2E8
_08065B1C:
	subs r0, 0x1
	strb r0, [r1, 0x4]
	b _08065B38
_08065B22:
	ldr r1, _08065B30
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _08065B34
	movs r0, 0x2
	b _08065B36
	.align 2, 0
_08065B30: .4byte gUnknown_202F2E8
_08065B34:
	subs r0, 0x1
_08065B36:
	strb r0, [r1, 0x8]
_08065B38:
	pop {r0}
	bx r0
	thumb_func_end sub_8065A8C

	thumb_func_start sub_8065B3C
sub_8065B3C:
	push {lr}
	cmp r0, 0x5
	bhi _08065BE8
	lsls r0, 2
	ldr r1, _08065B4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08065B4C: .4byte _08065B50
	.align 2, 0
_08065B50:
	.4byte _08065B68
	.4byte _08065B7C
	.4byte _08065B90
	.4byte _08065BA4
	.4byte _08065BB8
	.4byte _08065BD2
_08065B68:
	ldr r2, _08065B78
	movs r1, 0
	ldrb r0, [r2]
	cmp r0, 0
	bne _08065B74
	movs r1, 0x1
_08065B74:
	strb r1, [r2]
	b _08065BE8
	.align 2, 0
_08065B78: .4byte gUnknown_202F2E8
_08065B7C:
	ldr r2, _08065B8C
	movs r1, 0
	ldrb r0, [r2, 0x1]
	cmp r0, 0
	bne _08065B88
	movs r1, 0x1
_08065B88:
	strb r1, [r2, 0x1]
	b _08065BE8
	.align 2, 0
_08065B8C: .4byte gUnknown_202F2E8
_08065B90:
	ldr r2, _08065BA0
	movs r1, 0
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _08065B9C
	movs r1, 0x1
_08065B9C:
	strb r1, [r2, 0x2]
	b _08065BE8
	.align 2, 0
_08065BA0: .4byte gUnknown_202F2E8
_08065BA4:
	ldr r2, _08065BB4
	movs r1, 0
	ldrb r0, [r2, 0x3]
	cmp r0, 0
	bne _08065BB0
	movs r1, 0x1
_08065BB0:
	strb r1, [r2, 0x3]
	b _08065BE8
	.align 2, 0
_08065BB4: .4byte gUnknown_202F2E8
_08065BB8:
	ldr r1, _08065BC8
	ldrb r0, [r1, 0x4]
	cmp r0, 0x2
	bne _08065BCC
	movs r0, 0
	strb r0, [r1, 0x4]
	b _08065BE8
	.align 2, 0
_08065BC8: .4byte gUnknown_202F2E8
_08065BCC:
	adds r0, 0x1
	strb r0, [r1, 0x4]
	b _08065BE8
_08065BD2:
	ldr r1, _08065BE0
	ldrb r0, [r1, 0x8]
	cmp r0, 0x2
	bne _08065BE4
	movs r0, 0
	b _08065BE6
	.align 2, 0
_08065BE0: .4byte gUnknown_202F2E8
_08065BE4:
	adds r0, 0x1
_08065BE6:
	strb r0, [r1, 0x8]
_08065BE8:
	pop {r0}
	bx r0
	thumb_func_end sub_8065B3C

	thumb_func_start sub_8065BEC
sub_8065BEC:
	movs r0, 0
	bx lr
	thumb_func_end sub_8065BEC

	thumb_func_start sub_8065BF0
sub_8065BF0:
	movs r0, 0
	bx lr
	thumb_func_end sub_8065BF0

	thumb_func_start sub_8065BF4
sub_8065BF4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, _08065C60
	ldr r6, _08065C64
	movs r0, 0x2A
	adds r0, r5
	mov r8, r0
_08065C04:
	movs r7, 0
	bl sub_8065CAC
_08065C0A:
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08065C2E
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80136E0
_08065C2E:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08065C46
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8013744
_08065C46:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08065C5A
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08065C68
_08065C5A:
	bl sub_8083D08
	b _08065C7E
	.align 2, 0
_08065C60: .4byte gUnknown_202EE10
_08065C64: .4byte gRealInputs
_08065C68:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08065C78
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _08065C0A
_08065C78:
	bl sub_8083D30
	movs r7, 0x1
_08065C7E:
	ldr r4, _08065C9C
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	cmp r7, 0
	bne _08065CA0
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	bl sub_8065DBC
	b _08065C04
	.align 2, 0
_08065C9C: .4byte gUnknown_202EE10
_08065CA0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8065BF4

	thumb_func_start sub_8065CAC
sub_8065CAC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC8
	add r0, sp, 0x64
	mov r10, r0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x68]
	add r0, sp, 0x6C
	movs r4, 0
	movs r5, 0
	movs r1, 0x2
	mov r9, r1
	mov r1, r9
	strh r1, [r0]
	strh r1, [r0, 0x2]
	add r0, sp, 0x70
	movs r7, 0xC
	strh r7, [r0]
	adds r0, 0x2
	movs r6, 0x10
	strh r6, [r0]
	add r0, sp, 0x74
	strh r6, [r0]
	add r0, sp, 0xC4
	mov r8, r0
	str r0, [sp, 0x78]
	movs r1, 0x3
	str r1, [sp, 0x80]
	add r0, sp, 0x94
	str r1, [r0, 0x4]
	add r0, sp, 0xAC
	str r1, [r0, 0x4]
	add r0, sp, 0x4
	mov r1, r10
	movs r2, 0x60
	bl memcpy
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	strb r4, [r1, 0x1]
	strb r4, [r1, 0x3]
	ldr r4, _08065DB0
	strh r5, [r4, 0x18]
	movs r0, 0x7
	strh r0, [r4, 0x1A]
	strh r0, [r4, 0x1C]
	strh r5, [r4, 0x1E]
	strh r5, [r4, 0x20]
	strh r5, [r4, 0x4]
	strh r6, [r4, 0x6]
	strh r5, [r4, 0xC]
	strh r5, [r4, 0xE]
	strh r5, [r4, 0x14]
	str r5, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	add r0, sp, 0x4
	strh r7, [r0, 0xC]
	movs r0, 0x7
	movs r1, 0xC
	bl sub_80095E4
	add r2, sp, 0x4
	adds r1, r2, 0
	adds r0, 0x2
	strh r0, [r1, 0x10]
	strh r0, [r2, 0xE]
	movs r0, 0xA
	mov r1, r8
	strb r0, [r1, 0x2]
	adds r0, r2, 0
	mov r1, r9
	strh r1, [r0, 0x8]
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08065DB4
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r4, 0
	ldr r5, _08065DB8
_08065D7A:
	ldr r0, _08065DB0
	adds r1, r4, 0
	bl GetMenuEntryYCoord
	adds r1, r0, 0
	ldm r5!, {r2}
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r3, 0
	bl PrintFormattedStringOnWindow
	adds r4, 0x1
	cmp r4, 0x6
	ble _08065D7A
	movs r0, 0
	bl sub_80073E0
	add sp, 0xC8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065DB0: .4byte gUnknown_202EE10
_08065DB4: .4byte gUnknown_80FF770
_08065DB8: .4byte gUnknown_80FF774
	thumb_func_end sub_8065CAC

	thumb_func_start sub_8065DBC
sub_8065DBC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xEC
	adds r6, r0, 0
	ldr r0, _08065F28
	ldr r0, [r0]
	ldrb r1, [r0, 0x9]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	str r0, [sp, 0xC8]
	mov r0, sp
	adds r0, 0x6C
	str r0, [sp, 0xD4]
	mov r1, sp
	adds r1, 0x70
	str r1, [sp, 0xD8]
	mov r2, sp
	adds r2, 0x72
	str r2, [sp, 0xDC]
	adds r0, 0x8
	str r0, [sp, 0xE0]
	adds r1, 0xC
	str r1, [sp, 0xE4]
	adds r2, 0x22
	str r2, [sp, 0xE8]
	adds r0, 0x38
	str r0, [sp, 0xD0]
	subs r1, 0x18
	str r1, [sp, 0xCC]
	movs r2, 0x10
	mov r10, r2
	ldr r5, _08065F2C
	add r0, sp, 0xC4
	mov r9, r0
	add r1, sp, 0x4
	mov r8, r1
_08065E0C:
	movs r7, 0
	ldr r0, [sp, 0xCC]
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x68]
	movs r0, 0x2
	ldr r2, [sp, 0xD4]
	strh r0, [r2]
	strh r0, [r2, 0x2]
	movs r0, 0xC
	ldr r1, [sp, 0xD8]
	strh r0, [r1]
	mov r0, r10
	ldr r2, [sp, 0xDC]
	strh r0, [r2]
	ldr r1, [sp, 0xE0]
	strh r0, [r1]
	mov r2, r9
	str r2, [sp, 0x78]
	movs r0, 0x3
	ldr r1, [sp, 0xE4]
	str r0, [r1, 0x4]
	ldr r2, [sp, 0xE8]
	str r0, [r2, 0x4]
	ldr r1, [sp, 0xD0]
	str r0, [r1, 0x4]
	add r0, sp, 0x4
	ldr r1, [sp, 0xCC]
	movs r2, 0x60
	bl memcpy
	movs r1, 0x7
	add r0, sp, 0xC4
	strb r1, [r0]
	mov r2, r9
	strb r6, [r2, 0x1]
	movs r0, 0
	strb r0, [r2, 0x3]
	strh r6, [r5, 0x1E]
	strh r1, [r5, 0x20]
	strh r7, [r5, 0x1A]
	strh r7, [r5, 0x18]
	strh r7, [r5, 0x1C]
	strh r7, [r5, 0x4]
	mov r1, r10
	strh r1, [r5, 0x6]
	strh r7, [r5, 0x14]
	str r7, [r5]
	adds r0, r5, 0
	adds r0, 0x28
	bl sub_801317C
	movs r0, 0x18
	mov r2, r8
	strh r0, [r2, 0xC]
	movs r0, 0x8
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	mov r1, r8
	strh r0, [r1, 0x10]
	strh r0, [r1, 0xE]
	movs r0, 0xA
	mov r2, r9
	strb r0, [r2, 0x2]
	movs r0, 0x2
	strh r0, [r1, 0x8]
	add r0, sp, 0x4
	movs r1, 0x1
	bl sub_803ECB4
	ldr r1, _08065F30
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x13
	lsls r0, 3
	strh r0, [r5, 0xC]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r5, 0xE]
	movs r0, 0
	bl sub_80073B8
	lsls r0, r6, 3
	adds r0, 0x10
	ldr r1, _08065F34
	lsls r4, r6, 2
	adds r1, r4, r1
	ldr r2, [r1]
	str r7, [sp]
	movs r1, 0
	movs r3, 0
	bl PrintFormattedStringOnWindow
	ldr r1, _08065F38
	ldr r2, [sp, 0xC8]
	lsls r0, r2, 5
	adds r4, r0
	adds r4, r1
	ldr r2, [r4]
	str r7, [sp]
	movs r0, 0x8
	movs r1, 0x10
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
_08065EF4:
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x24
	bl sub_803E46C
	ldr r0, _08065F3C
	ldrh r1, [r0, 0x2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	bne _08065F16
	adds r0, r5, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _08065F40
_08065F16:
	movs r0, 0
	bl sub_8083CE0
	adds r6, 0x1
	cmp r6, 0x7
	bne _08065F64
	movs r6, 0
	b _08065F64
	.align 2, 0
_08065F28: .4byte gGameOptionsRef
_08065F2C: .4byte gUnknown_202EE10
_08065F30: .4byte gUnknown_2027370
_08065F34: .4byte gUnknown_80FF774
_08065F38: .4byte gUnknown_80FF7EC
_08065F3C: .4byte gRealInputs
_08065F40:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08065F52
	adds r0, r5, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08065F68
_08065F52:
	movs r0, 0
	bl sub_8083CE0
	subs r6, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	bne _08065F64
	movs r6, 0x6
_08065F64:
	movs r7, 0x1
	b _08065F94
_08065F68:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08065F7A
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08065F80
_08065F7A:
	bl sub_8083D08
	b _08065F94
_08065F80:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08065F90
	ldr r1, _08065FB0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08065EF4
_08065F90:
	bl sub_8083D30
_08065F94:
	movs r0, 0x24
	bl sub_803E46C
	cmp r7, 0
	beq _08065FA0
	b _08065E0C
_08065FA0:
	add sp, 0xEC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065FB0: .4byte gUnknown_202EE3A
	thumb_func_end sub_8065DBC

	thumb_func_start sub_8065FB4
sub_8065FB4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08065FE0
	add sp, r4
	movs r0, 0
	mov r10, r0
	ldr r4, _08065FE4
	ldr r0, [r4]
	ldr r1, _08065FE8
	adds r0, r1
	ldrb r0, [r0]
	bl IsRecruitingEnabled
	lsls r0, 24
	cmp r0, 0
	bne _08065FF0
	ldr r0, _08065FEC
	b _08065FFE
	.align 2, 0
_08065FE0: .4byte 0xfffff608
_08065FE4: .4byte gDungeon
_08065FE8: .4byte 0x00000644
_08065FEC: .4byte gUnknown_80FA5F4
_08065FF0:
	ldr r0, [r4]
	ldr r2, _0806600C
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08066014
	ldr r0, _08066010
_08065FFE:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl DisplayDungeonMessage
	b _08066194
	.align 2, 0
_0806600C: .4byte 0x0000065d
_08066010: .4byte gUnknown_80FA61C
_08066014:
	mov r0, sp
	bl sub_80664FC
	ldr r6, _08066130
_0806601C:
	movs r0, 0
	mov r8, r0
	mov r1, r10
	lsls r0, r1, 2
	add r0, r10
	lsls r0, 6
	subs r0, r1
	lsls r0, 2
	add r0, sp
	mov r9, r0
	ldr r0, _08066134
	strb r1, [r0, 0x1]
	ldr r0, _08066138
	movs r1, 0x1
	bl sub_803ECB4
	mov r2, r8
	strh r2, [r6, 0x1A]
	strh r2, [r6, 0x18]
	strh r2, [r6, 0x1C]
	mov r0, r10
	strh r0, [r6, 0x1E]
	movs r0, 0x2
	strh r0, [r6, 0x20]
	strh r2, [r6, 0x4]
	movs r0, 0x10
	strh r0, [r6, 0x6]
	strh r2, [r6, 0x14]
	mov r1, r8
	str r1, [r6]
	adds r0, r6, 0
	adds r0, 0x28
	bl sub_801317C
	ldr r0, _0806613C
	mov r2, r8
	str r2, [r0]
	movs r1, 0
	ldr r0, _08066140
	strb r1, [r0]
	mov r0, r9
	mov r1, r10
	bl sub_80661AC
	ldr r1, _08066144
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x10
	lsls r0, 3
	strh r0, [r6, 0xC]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r6, 0xE]
_0806608C:
	movs r5, 0
	ldr r0, _08066140
	strb r5, [r0]
	movs r0, 0
	ldr r1, _08066148
	bl sub_8014140
	adds r4, r0, 0
	mov r0, r9
	adds r1, r4, 0
	bl sub_8066288
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r5, r1, 31
	mov r0, r9
	adds r1, r4, 0
	bl sub_8066358
	lsls r0, 24
	cmp r0, 0
	beq _080660BE
	movs r5, 0x1
_080660BE:
	cmp r5, 0
	bne _080660CE
	ldr r0, _08066130
	bl AddMenuCursorSprite
	movs r0, 0x45
	bl sub_803E46C
_080660CE:
	ldr r2, _08066140
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080660E2
	movs r0, 0x1
	movs r1, 0x8
	bl sub_8066434
_080660E2:
	ldr r0, _08066140
	ldrb r1, [r0]
	movs r7, 0x2
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080660F8
	movs r0, 0
	movs r1, 0x70
	bl sub_8066434
_080660F8:
	ldr r5, _0806614C
	ldrh r1, [r5, 0x2]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	bne _0806611A
	ldr r4, _08066130
	adds r0, r4, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806611A
	adds r0, r4, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _08066150
_0806611A:
	movs r0, 0
	bl sub_8083CE0
	movs r0, 0
	mov r1, r10
	cmp r1, 0
	bne _0806612A
	movs r0, 0x1
_0806612A:
	mov r10, r0
	b _08066184
	.align 2, 0
_08066130: .4byte gUnknown_202EE10
_08066134: .4byte gUnknown_203B43C
_08066138: .4byte gUnknown_8106D08
_0806613C: .4byte gUnknown_202F2F8
_08066140: .4byte gUnknown_202F2FC
_08066144: .4byte gUnknown_2027370
_08066148: .4byte gUnknown_8106D68
_0806614C: .4byte gRealInputs
_08066150:
	bl sub_80048C8
	lsls r0, 24
	cmp r0, 0
	bne _0806608C
	ldrh r1, [r5, 0x2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _0806616E
	adds r0, r4, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	beq _08066174
_0806616E:
	bl sub_8083D30
	b _0806618C
_08066174:
	movs r0, 0xC
	ands r0, r1
	cmp r0, 0
	beq _0806608C
	bl sub_8083D08
	movs r2, 0x1
	mov r8, r2
_08066184:
	mov r0, r8
	cmp r0, 0
	bne _0806618C
	b _0806601C
_0806618C:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
_08066194:
	ldr r3, _080661A8
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080661A8: .4byte 0x000009f8
	thumb_func_end sub_8065FB4

	thumb_func_start sub_80661AC
sub_80661AC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x44
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r0, _080661DC
	ldr r4, [r0]
	movs r0, 0x20
	mov r8, r0
	movs r0, 0
	bl sub_80073B8
	cmp r5, 0
	bne _080661E4
	ldr r0, _080661E0
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0
	bl PrintStringOnWindow
	b _080661F6
	.align 2, 0
_080661DC: .4byte gUnknown_202F2F8
_080661E0: .4byte gUnknown_80FEA68
_080661E4:
	ldr r0, _08066254
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x14
	movs r1, 0
	movs r3, 0
	bl PrintStringOnWindow
_080661F6:
	movs r1, 0x9F
	lsls r1, 3
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, 0
	beq _08066260
	movs r7, 0x7
	lsls r0, r4, 1
	adds r5, r0, r6
_08066208:
	cmp r4, 0
	blt _08066244
	movs r1, 0x9F
	lsls r1, 3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r4, r0
	bge _08066244
	movs r1, 0xD4
	lsls r1, 2
	adds r0, r6, r1
	adds r0, r4
	ldrb r2, [r0]
	add r0, sp, 0x4
	ldr r1, _08066258
	bl sprintfStatic
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldr r0, _0806625C
	bl sub_808D930
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	mov r1, r8
	add r2, sp, 0x4
	movs r3, 0
	bl PrintFormattedStringOnWindow
_08066244:
	subs r7, 0x1
	adds r5, 0x2
	adds r4, 0x1
	movs r1, 0xC
	add r8, r1
	cmp r7, 0
	bge _08066208
	b _08066270
	.align 2, 0
_08066254: .4byte gUnknown_80FEA80
_08066258: .4byte gUnknown_8106D8C
_0806625C: .4byte gFormatBuffer_Monsters
_08066260:
	ldr r0, _08066284
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x8
	mov r1, r8
	movs r3, 0
	bl PrintStringOnWindow
_08066270:
	movs r0, 0
	bl sub_80073E0
	add sp, 0x44
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066284: .4byte gUnknown_80FEA8C
	thumb_func_end sub_80661AC

	thumb_func_start sub_8066288
sub_8066288:
	push {r4,r5,lr}
	sub sp, 0x44
	adds r5, r0, 0
	adds r3, r1, 0
	ldr r0, _080662B8
	ldr r4, [r0]
	cmp r4, 0
	beq _080662B4
	subs r4, 0x1
	ldr r2, _080662BC
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _080662C0
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080662C4
	cmp r3, 0x1
	beq _080662C4
_080662B4:
	movs r0, 0
	b _0806633E
	.align 2, 0
_080662B8: .4byte gUnknown_202F2F8
_080662BC: .4byte gUnknown_202F2FC
_080662C0: .4byte gRealInputs
_080662C4:
	movs r0, 0
	bl sub_8083CE0
	movs r0, 0
	bl sub_80073B8
	movs r0, 0x10
	str r0, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0x90
	bl sub_80087EC
	ldr r1, _08066348
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r5, r2
	adds r0, r4
	ldrb r2, [r0]
	add r0, sp, 0x4
	bl sprintfStatic
	ldr r0, _0806634C
	lsls r1, r4, 1
	adds r1, r5, r1
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl sub_808D930
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x14
	add r2, sp, 0x4
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	movs r0, 0x45
	bl sub_803E46C
	ldr r5, _08066350
	movs r4, 0x5
_08066320:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x45
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08066320
	ldr r1, _08066354
	ldr r0, [r1]
	subs r0, 0x1
	str r0, [r1]
	movs r0, 0x1
_0806633E:
	add sp, 0x44
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08066348: .4byte gUnknown_8106D8C
_0806634C: .4byte gFormatBuffer_Monsters
_08066350: .4byte gIwramTextFunc2
_08066354: .4byte gUnknown_202F2F8
	thumb_func_end sub_8066288

	thumb_func_start sub_8066358
sub_8066358:
	push {r4-r6,lr}
	sub sp, 0x44
	adds r5, r0, 0
	adds r3, r1, 0
	ldr r0, _08066394
	ldr r0, [r0]
	adds r4, r0, 0
	adds r4, 0x8
	movs r6, 0x80
	movs r1, 0x9F
	lsls r1, 3
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, r4
	ble _08066390
	ldr r2, _08066398
	ldrb r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0806639C
	ldrh r1, [r0, 0x4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _080663A0
	cmp r3, 0x2
	beq _080663A0
_08066390:
	movs r0, 0
	b _0806641A
	.align 2, 0
_08066394: .4byte gUnknown_202F2F8
_08066398: .4byte gUnknown_202F2FC
_0806639C: .4byte gRealInputs
_080663A0:
	movs r0, 0
	bl sub_8083CE0
	movs r0, 0
	bl sub_80073B8
	movs r0, 0x10
	str r0, [sp]
	movs r0, 0
	movs r1, 0
	adds r2, r6, 0
	movs r3, 0x48
	bl sub_80087EC
	ldr r1, _08066424
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r5, r2
	adds r0, r4
	ldrb r2, [r0]
	add r0, sp, 0x4
	bl sprintfStatic
	ldr r0, _08066428
	lsls r1, r4, 1
	adds r1, r5, r1
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl sub_808D930
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r6, 0
	add r2, sp, 0x4
	movs r3, 0
	bl PrintFormattedStringOnWindow
	movs r0, 0
	bl sub_80073E0
	movs r0, 0xD
	bl sub_803E46C
	ldr r5, _0806642C
	movs r4, 0x5
_080663FC:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0xD
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _080663FC
	ldr r1, _08066430
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	movs r0, 0x1
_0806641A:
	add sp, 0x44
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08066424: .4byte gUnknown_8106D8C
_08066428: .4byte gFormatBuffer_Monsters
_0806642C: .4byte gIwramTextFunc1
_08066430: .4byte gUnknown_202F2F8
	thumb_func_end sub_8066358

	thumb_func_start sub_8066434
sub_8066434:
	push {r4-r7,lr}
	mov r12, r1
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r7, _080664C8
	ldr r0, _080664CC
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080664C0
	ldr r0, _080664D0
	ldrh r1, [r0]
	ldr r3, _080664D4
	ands r3, r1
	ldr r1, _080664D8
	ands r3, r1
	ldr r1, _080664DC
	ands r3, r1
	ldr r1, _080664E0
	ands r3, r1
	ldr r1, _080664E4
	ands r3, r1
	negs r1, r2
	orrs r1, r2
	asrs r1, 31
	movs r2, 0x80
	lsls r2, 6
	ands r2, r1
	ldrh r1, [r0, 0x2]
	ldr r4, _080664E8
	ands r4, r1
	orrs r4, r2
	movs r5, 0xF
	ldr r2, _080664EC
	movs r6, 0x2
	ldrsh r1, [r7, r6]
	lsls r1, 3
	add r1, r12
	ands r1, r2
	lsls r1, 4
	ldrh r2, [r0, 0x6]
	ands r5, r2
	orrs r5, r1
	strh r5, [r0, 0x6]
	movs r2, 0
	ldrsh r1, [r7, r2]
	lsls r1, 3
	adds r1, 0x40
	ldr r2, _080664F0
	ands r1, r2
	movs r2, 0xFE
	lsls r2, 8
	ands r4, r2
	orrs r4, r1
	movs r2, 0x80
	lsls r2, 7
	ldr r1, _080664F4
	ands r3, r1
	orrs r3, r2
	strh r3, [r0]
	ands r4, r1
	strh r4, [r0, 0x2]
	ldr r1, _080664F8
	strh r1, [r0, 0x4]
	movs r1, 0x7F
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080664C0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080664C8: .4byte gUnknown_2027370
_080664CC: .4byte gUnknown_202EDCC
_080664D0: .4byte gUnknown_202F300
_080664D4: .4byte 0x0000feff
_080664D8: .4byte 0x0000fdff
_080664DC: .4byte 0x0000f3ff
_080664E0: .4byte 0x0000efff
_080664E4: .4byte 0x0000dfff
_080664E8: .4byte 0x0000c1ff
_080664EC: .4byte 0x00000fff
_080664F0: .4byte 0x000001ff
_080664F4: .4byte 0x00003fff
_080664F8: .4byte 0x0000f3f0
	thumb_func_end sub_8066434

	thumb_func_start sub_80664FC
sub_80664FC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C0
	str r0, [sp, 0x1A8]
	movs r7, 0
	ldr r2, _08066604
	ldr r3, _08066608
	movs r1, 0
_08066512:
	mov r4, sp
	adds r0, r4, r7
	strb r1, [r0]
	adds r7, 0x1
	cmp r7, r2
	ble _08066512
	movs r4, 0
	adds r1, r3, 0
	ldr r0, [r3]
	ldr r7, _0806660C
	adds r0, r7
	ldr r0, [r0]
	cmp r4, r0
	bge _08066578
	ldr r6, _08066610
_08066530:
	movs r5, 0x1
	ldr r2, [r1]
	lsls r0, r4, 3
	adds r0, r2, r0
	ldr r7, _08066614
	adds r1, r0, r7
	movs r7, 0
	ldrsh r1, [r1, r7]
	movs r7, 0xD1
	lsls r7, 6
	adds r0, r7
	movs r7, 0
	ldrsh r0, [r0, r7]
	cmp r1, 0
	bne _08066554
	cmp r0, 0
	beq _08066566
	movs r5, 0x2
_08066554:
	adds r0, r2, r6
	str r3, [sp, 0x1BC]
	bl ExtractSpeciesIndex
	lsls r0, 16
	asrs r0, 16
	add r0, sp
	strb r5, [r0]
	ldr r3, [sp, 0x1BC]
_08066566:
	adds r6, 0x8
	adds r4, 0x1
	ldr r1, _08066608
	ldr r0, [r1]
	ldr r2, _0806660C
	adds r0, r2
	ldr r0, [r0]
	cmp r4, r0
	blt _08066530
_08066578:
	ldr r0, [r3]
	ldr r4, _08066618
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806658A
	add r1, sp, 0x17C
	movs r0, 0x1
	strb r0, [r1]
_0806658A:
	movs r0, 0x5
_0806658C:
	subs r0, 0x1
	cmp r0, 0
	bge _0806658C
	movs r7, 0
_08066594:
	movs r0, 0
	mov r8, r0
	movs r1, 0x1
	adds r2, r7, 0x1
	str r2, [sp, 0x1AC]
	lsls r4, r7, 2
	str r4, [sp, 0x1B0]
_080665A2:
	lsls r0, r1, 16
	asrs r6, r0, 16
	movs r0, 0x7
	mov r10, r0
	movs r2, 0
	mov r9, r2
	mov r4, sp
	adds r0, r4, r6
	ldrb r0, [r0]
	adds r1, 0x1
	str r1, [sp, 0x1B4]
	cmp r0, 0
	bne _080665BE
	b _08066704
_080665BE:
	cmp r7, 0
	bne _08066620
	adds r0, r6, 0
	bl sub_806F9BC
	lsls r0, 24
	cmp r0, 0
	bne _080665D0
	b _08066704
_080665D0:
	adds r0, r6, 0
	bl IsExclusivePokemonUnlocked
	lsls r0, 24
	cmp r0, 0
	bne _080665DE
	b _08066704
_080665DE:
	adds r0, r6, 0
	bl GetRecruitRate
	lsls r0, 16
	ldr r1, _0806661C
	cmp r0, r1
	bne _080665EE
	b _08066704
_080665EE:
	cmp r6, 0x97
	bne _0806669E
	movs r0, 0x7A
	bl sub_80860A8
	lsls r0, 24
	cmp r0, 0
	bne _08066600
	b _08066704
_08066600:
	b _0806669E
	.align 2, 0
_08066604: .4byte 0x000001a7
_08066608: .4byte gDungeon
_0806660C: .4byte 0x000037e4
_08066610: .4byte 0x0000343c
_08066614: .4byte 0x0000343e
_08066618: .4byte 0x0000066e
_0806661C: .4byte 0xfc190000
_08066620:
	movs r5, 0
	ldr r0, _080666CC
	ldr r2, [r0]
	movs r4, 0x1
	movs r3, 0xCE
	lsls r3, 1
_0806662C:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0806663E
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	cmp r0, r6
	beq _08066646
_0806663E:
	adds r2, 0x58
	adds r5, 0x1
	cmp r5, r3
	ble _0806662C
_08066646:
	ldr r0, _080666D0
	cmp r5, r0
	beq _08066650
	movs r2, 0x1
	mov r9, r2
_08066650:
	mov r4, r9
	cmp r4, 0
	bne _0806669E
	movs r5, 0
	ldr r2, _080666CC
_0806665A:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, _080666D4
	adds r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806668C
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	str r2, [sp, 0x1B8]
	bl sub_806A564
	lsls r0, 24
	ldr r2, [sp, 0x1B8]
	cmp r0, 0
	bne _0806668C
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, r6
	beq _08066692
_0806668C:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806665A
_08066692:
	cmp r5, 0x4
	beq _0806669E
	movs r2, 0x1
	mov r9, r2
	movs r4, 0x6
	mov r10, r4
_0806669E:
	cmp r7, 0
	bne _080666D8
	mov r1, sp
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080666B0
	movs r2, 0x2
	mov r10, r2
_080666B0:
	mov r4, r8
	lsls r0, r4, 1
	ldr r1, [sp, 0x1A8]
	adds r0, r1, r0
	strh r6, [r0]
	movs r2, 0xD4
	lsls r2, 2
	adds r0, r1, r2
	add r0, r8
	mov r4, r10
	strb r4, [r0]
	movs r0, 0x1
	add r8, r0
	b _08066704
	.align 2, 0
_080666CC: .4byte gRecruitedPokemonRef
_080666D0: .4byte 0x0000019d
_080666D4: .4byte 0x00008df8
_080666D8:
	mov r1, r9
	cmp r1, 0
	beq _08066704
	ldr r2, [sp, 0x1B0]
	adds r0, r2, r7
	lsls r0, 6
	subs r0, r7
	lsls r0, 2
	ldr r4, [sp, 0x1A8]
	adds r0, r4
	mov r2, r8
	lsls r1, r2, 1
	adds r1, r0, r1
	strh r6, [r1]
	movs r4, 0xD4
	lsls r4, 2
	adds r0, r4
	add r0, r8
	mov r1, r10
	strb r1, [r0]
	movs r2, 0x1
	add r8, r2
_08066704:
	ldr r1, [sp, 0x1B4]
	ldr r0, _08066740
	cmp r1, r0
	bgt _0806670E
	b _080665A2
_0806670E:
	ldr r4, [sp, 0x1B0]
	adds r0, r4, r7
	lsls r0, 6
	subs r0, r7
	lsls r0, 2
	ldr r7, [sp, 0x1A8]
	adds r0, r7
	movs r1, 0x9F
	lsls r1, 3
	adds r0, r1
	mov r2, r8
	str r2, [r0]
	ldr r7, [sp, 0x1AC]
	cmp r7, 0x1
	bgt _0806672E
	b _08066594
_0806672E:
	add sp, 0x1C0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066740: .4byte 0x000001a3
	thumb_func_end sub_80664FC

	.align 2, 0
