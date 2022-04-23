	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8057D9C
sub_8057D9C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r0, [r4, 0x70]
	movs r5, 0
	ldr r1, _08057DF8
	mov r8, r1
	movs r1, 0x8C
	lsls r1, 1
	adds r2, r0, r1
	movs r0, 0x1
	mov r12, r0
	movs r7, 0x10
	movs r3, 0x3
_08057DBC:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _08057DD4
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08057DD4
	movs r0, 0
	strb r0, [r2, 0x4]
	movs r5, 0x1
_08057DD4:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08057DBC
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r5, 0
	beq _08057E00
	ldr r0, _08057DFC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08057E0C
	.align 2, 0
_08057DF8: .4byte gUnknown_202DFE8
_08057DFC: .4byte gUnknown_80FD350
_08057E00:
	ldr r0, _08057E18
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_08057E0C:
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057E18: .4byte gUnknown_80FD370
	thumb_func_end sub_8057D9C

	thumb_func_start sub_8057E1C
sub_8057E1C:
	push {lr}
	bl sub_8078348
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8057E1C

	thumb_func_start sub_8057E28
sub_8057E28:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _08057E4C
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807824C
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08057E4C: .4byte gUnknown_80F4EDC
	thumb_func_end sub_8057E28

	thumb_func_start sub_8057E50
sub_8057E50:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_807A9D8
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8079CA0
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8057E50

	thumb_func_start sub_8057E6C
sub_8057E6C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r7, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r4, r3, 0
	movs r0, 0
	mov r8, r0
	ldr r1, [r7, 0x70]
	mov r9, r1
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_807A9D8
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_8055640
	cmp r0, 0
	beq _08057EBC
	movs r0, 0x1
	mov r8, r0
	adds r0, r7, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _08057EBC
	ldr r0, _08057ECC
	add r0, r9
	mov r1, r8
	strb r1, [r0]
_08057EBC:
	mov r0, r8
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057ECC: .4byte 0x00000155
	thumb_func_end sub_8057E6C

	thumb_func_start sub_8057ED0
sub_8057ED0:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08057F12
	movs r7, 0x1
	ldr r0, _08057F1C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08057F12
	ldr r0, _08057F20
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x80
	bl sub_80772C0
_08057F12:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057F1C: .4byte gUnknown_80F4E04
_08057F20: .4byte gUnknown_8106A4C
	thumb_func_end sub_8057ED0

	thumb_func_start sub_8057F24
sub_8057F24:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	adds r6, r0, 0
	mov r8, r1
	ldr r5, [r6, 0x70]
	movs r0, 0x1
	mov r9, r0
	movs r4, 0x1
	strh r4, [r5, 0xE]
	ldr r0, _08057F74
	ldr r2, [r0]
	str r4, [sp]
	adds r0, r6, 0
	movs r3, 0x40
	bl sub_80772C0
	ldr r0, _08057F78
	ldr r2, [r0]
	str r4, [sp]
	adds r0, r6, 0
	mov r1, r8
	movs r3, 0x40
	bl sub_80772C0
	movs r0, 0xAA
	lsls r0, 1
	adds r5, r0
	mov r0, r9
	strb r0, [r5]
	movs r0, 0x1
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08057F74: .4byte gUnknown_8106A4C
_08057F78: .4byte gUnknown_8106A50
	thumb_func_end sub_8057F24

	thumb_func_start sub_8057F7C
sub_8057F7C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08057FBA
	movs r7, 0x1
	ldr r0, _08057FC4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08057FBA
	ldr r0, _08057FC8
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_80775DC
_08057FBA:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057FC4: .4byte gUnknown_80F4E02
_08057FC8: .4byte gUnknown_8106A4C
	thumb_func_end sub_8057F7C

	thumb_func_start sub_8057FCC
sub_8057FCC:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8077AE4
	ldr r0, _08057FF0
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_8077084
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08057FF0: .4byte gUnknown_8106A50
	thumb_func_end sub_8057FCC

	thumb_func_start sub_8057FF4
sub_8057FF4:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl GetFlashFireStatus
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _08058048
	ldr r0, [r4, 0x70]
	movs r2, 0xA9
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _08058054
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0805802C
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r6, 0x1
	bne _08058034
	ldr r0, _08058030
	b _08058036
	.align 2, 0
_0805802C: .4byte gUnknown_202DFE8
_08058030: .4byte gUnknown_80FAE00
_08058034:
	ldr r0, _08058044
_08058036:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _08058054
	.align 2, 0
_08058044: .4byte gUnknown_80FADD8
_08058048:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8076210
_08058054:
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8057FF4

	thumb_func_start sub_805805C
sub_805805C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r10, r0
	mov r9, r1
	adds r5, r2, 0
	mov r8, r3
	ldr r1, [r0, 0x70]
	movs r6, 0x1
	movs r2, 0
	ldr r4, _08058098
	movs r3, 0
	ldrsh r0, [r4, r3]
	cmp r0, 0
	blt _080580B0
	movs r7, 0xC
	ldrsh r3, [r1, r7]
	adds r1, r4, 0
	ldr r4, _0805809C
_08058088:
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r3, r0
	bge _080580A0
	movs r0, 0x2
	ldrsh r6, [r1, r0]
	b _080580B0
	.align 2, 0
_08058098: .4byte gUnknown_80F55BC
_0805809C: .4byte 0x000003e6
_080580A0:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, r4
	bgt _080580B0
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0
	bge _08058088
_080580B0:
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0
	str r1, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	mov r0, r10
	mov r1, r9
	adds r2, r6, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _080580F4
	movs r2, 0x1
_080580F4:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805805C

	thumb_func_start GrudgeMoveAction
GrudgeMoveAction:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r7, 0
	ldr r4, [r5, 0x70]
	ldr r0, _08058134
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0xF4
	ldrb r0, [r4]
	cmp r0, 0
	beq _0805813C
	ldr r0, _08058138
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	b _0805814E
	.align 2, 0
_08058134: .4byte gUnknown_202DFE8
_08058138: .4byte gUnknown_80FD2B4
_0805813C:
	movs r0, 0x1
	strb r0, [r4]
	movs r7, 0x1
	ldr r0, _08058158
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_0805814E:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058158: .4byte gUnknown_80FD294
	thumb_func_end GrudgeMoveAction

	thumb_func_start sub_805815C
sub_805815C:
	push {lr}
	movs r2, 0x4
	bl sub_80797A0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805815C

	thumb_func_start sub_805816C
sub_805816C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r6, 0
	bl sub_807A9D8
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _080581BE
	movs r1, 0x1
	mov r8, r1
	ldr r0, _080581CC
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080581BE
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0
	bl sub_8076210
_080581BE:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080581CC: .4byte gUnknown_80F4DB8
	thumb_func_end sub_805816C

	thumb_func_start sub_80581D0
sub_80581D0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r6, 0
	bl sub_807A9D8
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058222
	movs r1, 0x1
	mov r8, r1
	ldr r0, _08058230
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058222
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0
	bl sub_8076210
_08058222:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058230: .4byte gUnknown_80F4DBA
	thumb_func_end sub_80581D0

	thumb_func_start sub_8058234
sub_8058234:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldrh r1, [r2, 0x2]
	ldr r0, _08058258
	movs r2, 0x51
	cmp r1, r0
	bne _08058246
	movs r2, 0x7A
_08058246:
	adds r0, r3, 0
	adds r1, r4, 0
	bl sub_8078FDC
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08058258: .4byte 0x0000013b
	thumb_func_end sub_8058234

	thumb_func_start sub_805825C
sub_805825C:
	push {lr}
	ldr r2, _0805826C
	ldr r2, [r2]
	bl sub_8077540
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805826C: .4byte gUnknown_8106A50
	thumb_func_end sub_805825C

	thumb_func_start sub_8058270
sub_8058270:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r2, 0
	adds r2, r3, 0
	movs r3, 0x1
	ldr r0, [r1, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	subs r0, 0x7
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0805828E
	movs r3, 0x2
_0805828E:
	lsls r3, 8
	str r2, [sp]
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8058270

	thumb_func_start sub_80582AC
sub_80582AC:
	push {lr}
	ldr r2, _080582C0
	ldr r2, [r2]
	movs r3, 0x1
	bl sub_8077160
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_080582C0: .4byte gUnknown_8106A4C
	thumb_func_end sub_80582AC

	thumb_func_start sub_80582C4
sub_80582C4:
	push {lr}
	movs r2, 0x1
	bl sub_8077780
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_80582C4

	thumb_func_start sub_80582D4
sub_80582D4:
	push {lr}
	ldr r2, _080582E8
	ldr r2, [r2]
	movs r3, 0x1
	bl sub_8077084
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_080582E8: .4byte gUnknown_8106A4C
	thumb_func_end sub_80582D4

	thumb_func_start sub_80582EC
sub_80582EC:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	adds r1, r4, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _08058328
	ldr r0, _08058324
	ldr r3, [r0]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r5, 0
	bl sub_8079764
	b _0805833C
	.align 2, 0
_08058324: .4byte gUnknown_80F4F50
_08058328:
	ldr r0, _08058348
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x4
	adds r3, r4, 0
	bl sub_8079618
	movs r4, 0x1
_0805833C:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058348: .4byte gUnknown_80FAC54
	thumb_func_end sub_80582EC

	thumb_func_start sub_805834C
sub_805834C:
	push {lr}
	sub sp, 0x4
	adds r3, r2, 0
	ldr r2, _08058368
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x1
	bl sub_8079618
	movs r0, 0x1
	add sp, 0x4
	pop {r1}
	bx r1
	.align 2, 0
_08058368: .4byte gUnknown_80FAC74
	thumb_func_end sub_805834C

	thumb_func_start sub_805836C
sub_805836C:
	push {r4-r7,lr}
	sub sp, 0x1C
	adds r6, r0, 0
	adds r7, r1, 0
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	ldr r0, [r6, 0x70]
	adds r0, 0xA0
	ldr r0, [r0]
	lsls r4, r0, 1
	ldr r0, _080583D0
	cmp r4, r0
	ble _0805838A
	adds r4, r0, 0
_0805838A:
	adds r0, r2, 0
	bl GetMoveType
	lsls r0, 24
	lsrs r0, 24
	add r1, sp, 0x18
	str r1, [sp]
	str r0, [sp, 0x4]
	ldr r0, _080583D4
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r5, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _080583C0
	movs r2, 0x1
_080583C0:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080583D0: .4byte 0x000003e7
_080583D4: .4byte 0x000001ff
	thumb_func_end sub_805836C

	thumb_func_start sub_80583D8
sub_80583D8:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805841C
	movs r7, 0x1
	ldr r0, _08058428
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805841C
	ldr r0, _0805842C
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_8076F80
_0805841C:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058428: .4byte gUnknown_80F4DC2
_0805842C: .4byte gUnknown_8106A50
	thumb_func_end sub_80583D8

	thumb_func_start sub_8058430
sub_8058430:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805846A
	movs r7, 0x1
	ldr r0, _08058474
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805846A
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80776C0
_0805846A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058474: .4byte gUnknown_80F4DEE
	thumb_func_end sub_8058430

	thumb_func_start sub_8058478
sub_8058478:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080584B2
	movs r7, 0x1
	ldr r0, _080584BC
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080584B2
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
_080584B2:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080584BC: .4byte gUnknown_80F4DE6
	thumb_func_end sub_8058478

	thumb_func_start sub_80584C0
sub_80584C0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	movs r7, 0
	add r0, sp, 0x18
	strb r7, [r0]
	mov r0, r9
	ldr r2, [r0, 0x70]
	ldr r0, [r1, 0x70]
	movs r3, 0xE
	ldrsh r1, [r0, r3]
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	subs r5, r1, r0
	cmp r5, 0
	bge _080584F0
	movs r5, 0
_080584F0:
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r7, [sp, 0x14]
	mov r0, r9
	mov r1, r10
	adds r2, r5, 0
	movs r3, 0
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08058532
	movs r2, 0x1
_08058532:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80584C0

	thumb_func_start sub_8058548
sub_8058548:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r5, 0x80
	lsls r5, 1
	ldr r0, [r4, 0x70]
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08058560
	ldr r0, _0805857C
	ldr r5, [r0]
_08058560:
	str r3, [sp]
	adds r0, r4, 0
	adds r3, r5, 0
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805857C: .4byte gUnknown_80F4F6C
	thumb_func_end sub_8058548

	thumb_func_start sub_8058580
sub_8058580:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080585BC
	movs r7, 0x1
	ldr r0, _080585C8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080585BC
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_80779F0
_080585BC:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080585C8: .4byte gUnknown_80F4DD4
	thumb_func_end sub_8058580

	thumb_func_start sub_80585CC
sub_80585CC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	mov r8, r2
	adds r7, r3, 0
	movs r6, 0
	ldr r0, [r4, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080585EC
	cmp r0, 0x3
	bne _08058602
_080585EC:
	ldr r0, _08058620
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807A4C8
	movs r6, 0x1
_08058602:
	movs r3, 0x80
	lsls r3, 1
	str r7, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	mov r2, r8
	bl sub_8055640
	cmp r0, 0
	beq _08058624
	movs r0, 0x1
	orrs r0, r6
	lsls r0, 24
	b _08058626
	.align 2, 0
_08058620: .4byte gUnknown_80FD104
_08058624:
	lsls r0, r6, 24
_08058626:
	lsrs r0, 24
	adds r6, r0, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80585CC

	thumb_func_start sub_8058638
sub_8058638:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058670
	movs r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058670
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_80779F0
_08058670:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8058638

	thumb_func_start sub_805867C
sub_805867C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	adds r1, r4, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _080586B8
	ldr r0, _080586B4
	ldr r3, [r0]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r5, 0
	bl sub_8079764
	b _080586CC
	.align 2, 0
_080586B4: .4byte gUnknown_80F4F54
_080586B8:
	ldr r0, _080586D8
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x5
	adds r3, r4, 0
	bl sub_8079618
	movs r4, 0x1
_080586CC:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080586D8: .4byte gUnknown_80FACA4
	thumb_func_end sub_805867C

	thumb_func_start sub_80586DC
sub_80586DC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	adds r0, r4, 0
	movs r1, 0x3A
	bl HasAbility
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r3, 0x80
	lsls r3, 1
	str r5, [sp]
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_8055640
	adds r4, r0, 0
	negs r0, r4
	orrs r0, r4
	lsrs r5, r0, 31
	cmp r5, 0
	beq _08058762
	adds r0, r7, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _08058762
	lsrs r0, r4, 31
	adds r0, r4, r0
	asrs r2, r0, 1
	ldr r0, [r7, 0x70]
	movs r5, 0x1
	cmp r2, 0
	bgt _08058734
	movs r2, 0x1
_08058734:
	adds r1, r0, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _08058740
	strb r5, [r1]
_08058740:
	mov r0, r8
	cmp r0, 0
	beq _08058756
	movs r3, 0xFD
	lsls r3, 1
	adds r0, r7, 0
	adds r1, r2, 0
	movs r2, 0xD
	bl sub_806F324
	b _08058762
_08058756:
	str r5, [sp]
	adds r0, r7, 0
	adds r1, r7, 0
	movs r3, 0
	bl HealTargetHP
_08058762:
	adds r0, r5, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80586DC

	thumb_func_start sub_8058770
sub_8058770:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	mov r12, r2
	adds r5, r3, 0
	ldr r2, [r4, 0x70]
	movs r0, 0x10
	ldrsh r3, [r2, r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _0805878A
	adds r0, r3, 0x3
_0805878A:
	movs r7, 0xE
	ldrsh r1, [r2, r7]
	asrs r0, 2
	cmp r1, r0
	bgt _08058798
	movs r3, 0
	b _080587BE
_08058798:
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	lsrs r0, r3, 31
	adds r0, r3, r0
	asrs r0, 1
	cmp r1, r0
	bgt _080587AA
	movs r3, 0x1
	b _080587BE
_080587AA:
	lsls r0, r3, 1
	adds r0, r3
	cmp r0, 0
	bge _080587B4
	adds r0, 0x3
_080587B4:
	asrs r0, 2
	movs r3, 0x3
	cmp r1, r0
	bgt _080587BE
	movs r3, 0x2
_080587BE:
	ldr r1, _080587E4
	lsls r0, r3, 2
	adds r0, r1
	ldr r3, [r0]
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, r12
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080587E4: .4byte gUnknown_80F51A4
	thumb_func_end sub_8058770

	thumb_func_start sub_80587E8
sub_80587E8:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	adds r1, r3, 0
	ldr r0, [r5, 0x70]
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0805881A
	movs r3, 0x80
	lsls r3, 2
	str r1, [sp]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_807A290
	b _0805882E
_0805881A:
	movs r3, 0x80
	lsls r3, 1
	str r1, [sp]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
_0805882E:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80587E8

	thumb_func_start sub_8058838
sub_8058838:
	push {lr}
	sub sp, 0x8
	ldr r2, _08058854
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	movs r3, 0x3
	bl sub_8076F80
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_08058854: .4byte gUnknown_8106A50
	thumb_func_end sub_8058838

	thumb_func_start sub_8058858
sub_8058858:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	adds r6, r0, 0
	mov r8, r1
	ldr r0, _08058898
	ldr r5, [r0]
	movs r4, 0x1
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_8076E20
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_8076F80
	movs r0, 0x1
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08058898: .4byte gUnknown_8106A4C
	thumb_func_end sub_8058858

	thumb_func_start sub_805889C
sub_805889C:
	push {lr}
	bl sub_80769CC
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805889C

	thumb_func_start sub_80588A8
sub_80588A8:
	push {lr}
	movs r2, 0x1
	bl sub_8079E34
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_80588A8

	thumb_func_start sub_80588B8
sub_80588B8:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080588E4
	movs r6, 0x1
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _080588E4
	ldr r0, _080588F0
	strb r6, [r0]
_080588E4:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080588F0: .4byte gUnknown_202F219
	thumb_func_end sub_80588B8

	thumb_func_start sub_80588F4
sub_80588F4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	mov r8, r2
	adds r4, r3, 0
	ldr r0, [r5, 0x70]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl GetLowKickDmg
	adds r3, r0, 0
	str r4, [sp]
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, r8
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80588F4

	thumb_func_start sub_8058930
sub_8058930:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r0, 0
	movs r0, 0
	mov r8, r0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r0, r7, 0
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080589B8
	movs r2, 0x1
	mov r8, r2
	ldr r0, _080589C8
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _080589B8
	ldr r6, [r7, 0x70]
	adds r0, r7, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8077910
	ldr r0, _080589CC
	ldr r5, [r0]
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_8077084
	ldr r0, _080589D0
	ldr r4, [r0]
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077084
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_8077160
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077160
	adds r6, 0xFB
	ldrb r0, [r6]
	cmp r0, 0
	bne _080589B8
	mov r0, r8
	strb r0, [r6]
_080589B8:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080589C8: .4byte gUnknown_80F4DD6
_080589CC: .4byte gUnknown_8106A4C
_080589D0: .4byte gUnknown_8106A50
	thumb_func_end sub_8058930

	thumb_func_start sub_80589D4
sub_80589D4:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, _08058A04
	bl GetWeather
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08058A04: .4byte gUnknown_80F500A
	thumb_func_end sub_80589D4

	thumb_func_start sub_8058A08
sub_8058A08:
	push {lr}
	movs r2, 0
	movs r3, 0x1
	bl sub_8077910
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8058A08

	thumb_func_start sub_8058A18
sub_8058A18:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058A44
	movs r6, 0x1
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _08058A44
	ldr r0, _08058A50
	strb r6, [r0]
_08058A44:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08058A50: .4byte gUnknown_202F21A
	thumb_func_end sub_8058A18

	thumb_func_start sub_8058A54
sub_8058A54:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _08058A78
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80781DC
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08058A78: .4byte gUnknown_80F4EB8
	thumb_func_end sub_8058A54

	thumb_func_start sub_8058A7C
sub_8058A7C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _08058AA4
	ldr r2, [r0]
	adds r0, r4, 0
	movs r3, 0x1
	bl sub_8077160
	ldr r0, _08058AA8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_8077160
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08058AA4: .4byte gUnknown_8106A4C
_08058AA8: .4byte gUnknown_8106A50
	thumb_func_end sub_8058A7C

	thumb_func_start SkyAttackMoveAction
SkyAttackMoveAction:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _08058B14
	ldr r0, _08058B0C
	ldr r3, [r0]
	str r7, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058B04
	movs r1, 0x1
	mov r8, r1
	ldr r0, _08058B10
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058B04
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80776C0
_08058B04:
	adds r0, r4, 0
	bl sub_8079764
	b _08058B2A
	.align 2, 0
_08058B0C: .4byte gUnknown_80F4F4C
_08058B10: .4byte gUnknown_80F4DF4
_08058B14:
	ldr r0, _08058B38
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x3
	adds r3, r5, 0
	bl sub_8079618
	movs r0, 0x1
	mov r8, r0
_08058B2A:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058B38: .4byte gUnknown_80FACC4
	thumb_func_end SkyAttackMoveAction

	thumb_func_start sub_8058B3C
sub_8058B3C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058B76
	movs r7, 0x1
	ldr r0, _08058B80
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058B76
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80767B0
_08058B76:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058B80: .4byte gUnknown_80F4DBC
	thumb_func_end sub_8058B3C

	thumb_func_start sub_8058B84
sub_8058B84:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058BCC
	movs r6, 0x1
	ldr r0, _08058BD8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058BCC
	ldr r4, [r5, 0x70]
	ldr r0, _08058BDC
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_8077084
	adds r4, 0xFB
	ldrb r0, [r4]
	cmp r0, 0
	bne _08058BCC
	strb r6, [r4]
_08058BCC:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08058BD8: .4byte gUnknown_80F4DD0
_08058BDC: .4byte gUnknown_8106A4C
	thumb_func_end sub_8058B84

	thumb_func_start sub_8058BE0
sub_8058BE0:
	push {lr}
	adds r1, r0, 0
	bl sub_8079C24
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8058BE0

	thumb_func_start sub_8058BF0
sub_8058BF0:
	push {lr}
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80779F0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8058BF0

	thumb_func_start sub_8058C00
sub_8058C00:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058C3A
	movs r7, 0x1
	ldr r0, _08058C44
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058C3A
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077AE4
_08058C3A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058C44: .4byte gUnknown_80F4DF8
	thumb_func_end sub_8058C00

	thumb_func_start sub_8058C48
sub_8058C48:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	movs r1, 0xC0
	lsls r1, 1
	movs r0, 0x80
	bl DungeonRandomRange
	adds r3, r0, 0
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x9]
	muls r0, r3
	cmp r0, 0
	bge _08058C6C
	adds r0, 0xFF
_08058C6C:
	asrs r3, r0, 8
	cmp r3, 0
	bge _08058C74
	movs r3, 0x1
_08058C74:
	cmp r3, 0xC7
	ble _08058C7A
	movs r3, 0xC7
_08058C7A:
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8055864
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8058C48

	thumb_func_start sub_8058C98
sub_8058C98:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x1C]
	movs r6, 0
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	adds r0, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058CDE
	movs r6, 0x1
	ldr r0, _08058CE8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058CDE
	str r6, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r7, 0
	movs r3, 0x1
	bl sub_8076F80
_08058CDE:
	adds r0, r6, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058CE8: .4byte gUnknown_80F4DC0
	thumb_func_end sub_8058C98

	thumb_func_start sub_8058CEC
sub_8058CEC:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	movs r6, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058D28
	movs r6, 0x1
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _08058D28
	ldr r0, _08058D34
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r3, 0x2
	bl sub_8076E20
_08058D28:
	adds r0, r6, 0
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08058D34: .4byte gUnknown_8106A50
	thumb_func_end sub_8058CEC

	thumb_func_start sub_8058D38
sub_8058D38:
	push {lr}
	bl sub_8075FCC
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8058D38

	thumb_func_start sub_8058D44
sub_8058D44:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	mov r12, r2
	adds r5, r3, 0
	ldr r2, [r4, 0x70]
	movs r0, 0x10
	ldrsh r3, [r2, r0]
	adds r0, r3, 0
	cmp r3, 0
	bge _08058D5E
	adds r0, r3, 0x3
_08058D5E:
	movs r7, 0xE
	ldrsh r1, [r2, r7]
	asrs r0, 2
	cmp r1, r0
	bgt _08058D6C
	movs r3, 0
	b _08058D92
_08058D6C:
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	lsrs r0, r3, 31
	adds r0, r3, r0
	asrs r0, 1
	cmp r1, r0
	bgt _08058D7E
	movs r3, 0x1
	b _08058D92
_08058D7E:
	lsls r0, r3, 1
	adds r0, r3
	cmp r0, 0
	bge _08058D88
	adds r0, 0x3
_08058D88:
	asrs r0, 2
	movs r3, 0x3
	cmp r1, r0
	bgt _08058D92
	movs r3, 0x2
_08058D92:
	ldr r1, _08058DB8
	lsls r0, r3, 2
	adds r0, r1
	ldr r3, [r0]
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	mov r2, r12
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058DB8: .4byte gUnknown_80F51B4
	thumb_func_end sub_8058D44

	thumb_func_start sub_8058DBC
sub_8058DBC:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	ldr r5, [r7, 0x70]
	ldr r4, [r6, 0x70]
	adds r0, r6, 0
	bl nullsub_92
	movs r3, 0
_08058DCE:
	lsls r2, r3, 1
	adds r1, r5, 0
	adds r1, 0x1C
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, r5, 0
	adds r1, 0x20
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x20
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, r5, 0
	adds r1, 0x24
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x24
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r2, r3, 2
	adds r1, r5, 0
	adds r1, 0x2C
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x2C
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	adds r1, r5, 0
	adds r1, 0x34
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x34
	adds r0, r2
	ldr r0, [r0]
	str r0, [r1]
	adds r3, 0x1
	cmp r3, 0x1
	ble _08058DCE
	ldr r0, _08058E54
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08058E58
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80522F4
	adds r1, r5, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _08058E4C
	movs r0, 0x1
	strb r0, [r1]
_08058E4C:
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058E54: .4byte gAvailablePokemonNames
_08058E58: .4byte gUnknown_80FBD58
	thumb_func_end sub_8058DBC

	thumb_func_start sub_8058E5C
sub_8058E5C:
	push {r4-r7,lr}
	sub sp, 0x18
	adds r5, r0, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058ED0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08058ED0
	ldr r0, [r5, 0x70]
	movs r1, 0x10
	ldrsh r2, [r0, r1]
	cmp r2, 0
	bge _08058E8C
	adds r2, 0x7
_08058E8C:
	asrs r6, r2, 3
	cmp r6, 0
	bne _08058E94
	movs r6, 0x1
_08058E94:
	movs r7, 0x1
	adds r0, r5, 0
	movs r1, 0x7
	bl HasAbility
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08058ED0
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _08058ED0
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r0, _08058EDC
	str r0, [sp, 0x8]
	movs r0, 0x14
	str r0, [sp, 0xC]
	str r7, [sp, 0x10]
	str r4, [sp, 0x14]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0
	bl sub_806F370
_08058ED0:
	adds r0, r7, 0
	add sp, 0x18
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058EDC: .4byte 0x000001fd
	thumb_func_end sub_8058E5C

	thumb_func_start sub_8058EE0
sub_8058EE0:
	push {lr}
	sub sp, 0x4
	ldr r2, [r1, 0x70]
	movs r3, 0x10
	ldrsh r2, [r2, r3]
	lsrs r3, r2, 31
	adds r2, r3
	asrs r2, 1
	movs r3, 0x1
	str r3, [sp]
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8058EE0

	thumb_func_start sub_8058F04
sub_8058F04:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	adds r4, r1, 0
	mov r12, r2
	adds r5, r3, 0
	ldr r3, [r4, 0x70]
	movs r6, 0x1
	ldr r0, _08058F50
	ldr r1, [r0]
	movs r0, 0xC1
	lsls r0, 9
	adds r2, r1, r0
	movs r0, 0xC
	str r0, [r2]
	ldr r0, _08058F54
	adds r1, r0
	movs r0, 0
	str r0, [r1]
	adds r3, 0xC0
	ldrb r0, [r3]
	cmp r0, 0xA
	bne _08058F34
	movs r6, 0x2
_08058F34:
	lsls r3, r6, 8
	str r5, [sp]
	adds r0, r7, 0
	adds r1, r4, 0
	mov r2, r12
	bl sub_8055640
	cmp r0, 0
	beq _08058F48
	movs r0, 0x1
_08058F48:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058F50: .4byte gDungeonGlobalData
_08058F54: .4byte 0x00018204
	thumb_func_end sub_8058F04

	thumb_func_start sub_8058F58
sub_8058F58:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	adds r6, r0, 0
	adds r7, r1, 0
	mov r8, r3
	ldr r0, _08058FB0
	ldr r0, [r0]
	ldr r1, _08058FB4
	adds r0, r1
	movs r1, 0
	ldrsh r5, [r0, r1]
	cmp r5, 0
	bge _08058F78
	movs r5, 0
_08058F78:
	cmp r5, 0x4A
	ble _08058F7E
	movs r5, 0x4A
_08058F7E:
	ldr r4, _08058FB8
	lsls r5, 3
	adds r0, r5, r4
	ldrh r1, [r0]
	mov r0, sp
	bl InitPokemonMove
	adds r4, 0x4
	adds r5, r4
	ldr r4, [r5]
	adds r0, r6, 0
	adds r1, r7, 0
	mov r2, sp
	mov r3, r8
	bl _call_via_r4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058FB0: .4byte gDungeonGlobalData
_08058FB4: .4byte 0x00003a0e
_08058FB8: .4byte gUnknown_80F5D10
	thumb_func_end sub_8058F58

	thumb_func_start sub_8058FBC
sub_8058FBC:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08058FF6
	movs r7, 0x1
	ldr r0, _08059000
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08058FF6
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
_08058FF6:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059000: .4byte gUnknown_80F4DE4
	thumb_func_end sub_8058FBC

	thumb_func_start sub_8059004
sub_8059004:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	mov r9, r0
	mov r8, r1
	adds r5, r2, 0
	adds r6, r3, 0
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	mov r2, r8
	adds r2, 0x4
	str r4, [sp]
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r3, 0x1
	bl sub_807DF38
	movs r0, 0x1
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8059004

	thumb_func_start sub_8059050
sub_8059050:
	push {lr}
	movs r2, 0x1
	bl sub_8077780
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059050

	thumb_func_start sub_8059060
sub_8059060:
	push {lr}
	sub sp, 0x4
	adds r3, r2, 0
	ldr r2, _0805907C
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0xB
	bl sub_8079618
	movs r0, 0x1
	add sp, 0x4
	pop {r1}
	bx r1
	.align 2, 0
_0805907C: .4byte gUnknown_80FAD6C
	thumb_func_end sub_8059060

	thumb_func_start sub_8059080
sub_8059080:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080590BA
	movs r7, 0x1
	ldr r0, _080590C4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080590BA
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
_080590BA:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080590C4: .4byte gUnknown_80F4DE8
	thumb_func_end sub_8059080

	thumb_func_start sub_80590C8
sub_80590C8:
	push {lr}
	bl sub_80798B0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_80590C8

	thumb_func_start sub_80590D4
sub_80590D4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	mov r8, r0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	movs r0, 0
	mov r9, r0
	add r0, sp, 0x18
	mov r1, r9
	strb r1, [r0]
	adds r0, r5, 0
	bl GetMoveType
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_806F4A4
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r6, 0
	movs r1, 0x37
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805911C
	movs r4, 0
_0805911C:
	cmp r4, 0
	bne _08059134
	ldr r0, _08059130
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	b _0805917A
	.align 2, 0
_08059130: .4byte gUnknown_80FEB88
_08059134:
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0805918C
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	mov r0, r9
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	mov r0, r8
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059178
	movs r2, 0x1
_08059178:
	strb r2, [r1]
_0805917A:
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805918C: .4byte 0x0000270f
	thumb_func_end sub_80590D4

	thumb_func_start sub_8059190
sub_8059190:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080591CA
	movs r7, 0x1
	ldr r0, _080591D4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080591CA
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80776C0
_080591CA:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080591D4: .4byte gUnknown_80F4DEA
	thumb_func_end sub_8059190

	thumb_func_start sub_80591D8
sub_80591D8:
	push {lr}
	bl sub_8079834
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_80591D8

	thumb_func_start sub_80591E4
sub_80591E4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r5, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0x3A
	bl HasAbility
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r3, 0x80
	lsls r3, 1
	str r5, [sp]
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_8055640
	adds r1, r0, 0
	cmp r1, 0
	beq _0805927E
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r4, r0, 1
	cmp r4, 0
	bgt _0805922A
	movs r4, 0x1
_0805922A:
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805927E
	ldr r0, [r7, 0x70]
	movs r1, 0x1
	mov r8, r1
	adds r1, r0, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805924A
	mov r0, r8
	strb r0, [r1]
_0805924A:
	adds r0, r7, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _0805927E
	mov r1, r9
	cmp r1, 0
	beq _0805926E
	movs r3, 0xFD
	lsls r3, 1
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0xD
	bl sub_806F324
	b _0805927E
_0805926E:
	mov r0, r8
	str r0, [sp]
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r4, 0
	movs r3, 0
	bl HealTargetHP
_0805927E:
	mov r0, r8
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80591E4

	thumb_func_start SkillSwapMoveAction
SkillSwapMoveAction:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r7, [r4, 0x70]
	ldr r5, [r6, 0x70]
	adds r0, r6, 0
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _080592BA
	adds r0, r4, 0
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _080592D0
_080592BA:
	ldr r0, _080592CC
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _0805932E
	.align 2, 0
_080592CC: .4byte gUnknown_80FC8C0
_080592D0:
	movs r0, 0x5E
	adds r0, r5
	mov r12, r0
	ldrb r3, [r0]
	mov r8, r3
	adds r1, r5, 0
	adds r1, 0x5F
	ldrb r2, [r1]
	adds r5, r7, 0
	adds r5, 0x5E
	ldrb r0, [r5]
	mov r3, r12
	strb r0, [r3]
	movs r0, 0x5F
	adds r0, r7
	mov r12, r0
	ldrb r0, [r0]
	strb r0, [r1]
	mov r3, r8
	strb r3, [r5]
	mov r0, r12
	strb r2, [r0]
	ldr r0, _08059338
	ldr r0, [r0]
	movs r5, 0x1
	strb r5, [r0, 0xC]
	ldr r0, _0805933C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80522F4
	adds r1, r7, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805931C
	strb r5, [r1]
_0805931C:
	adds r0, r4, 0
	adds r1, r4, 0
	bl sub_806ABAC
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_806ABAC
	movs r0, 0x1
_0805932E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059338: .4byte gDungeonGlobalData
_0805933C: .4byte gUnknown_80FC888
	thumb_func_end SkillSwapMoveAction

	thumb_func_start SketchMoveAction
SketchMoveAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	movs r0, 0
	mov r10, r0
	ldr r1, [r6, 0x70]
	str r1, [sp]
	ldr r0, [r7, 0x70]
	movs r2, 0
	mov r12, r2
	movs r4, 0
	movs r1, 0x8C
	lsls r1, 1
	adds r3, r0, r1
	adds r1, r0, 0
	movs r2, 0x1
	mov r9, r2
	movs r0, 0x10
	mov r8, r0
_08059372:
	ldrb r2, [r3]
	mov r0, r9
	ands r0, r2
	cmp r0, 0
	beq _08059384
	mov r0, r8
	ands r0, r2
	cmp r0, 0
	bne _080593A8
_08059384:
	adds r3, 0x8
	adds r1, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _08059372
	movs r0, 0
	cmp r0, 0
	bne _080593B2
	ldr r0, _080593A4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	movs r0, 0
	b _0805940A
	.align 2, 0
_080593A4: .4byte gUnknown_80FE3BC
_080593A8:
	movs r2, 0x8D
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	mov r12, r0
_080593B2:
	mov r0, r12
	cmp r0, 0
	bne _080593CC
	ldr r0, _080593C8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _08059408
	.align 2, 0
_080593C8: .4byte gUnknown_80FE3BC
_080593CC:
	adds r0, r5, 0
	mov r1, r12
	bl InitPokemonMove
	ldr r0, _0805941C
	adds r1, r5, 0
	movs r2, 0
	bl sub_80928C0
	ldrb r1, [r5, 0x1]
	movs r0, 0x4
	orrs r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r5, 0x1]
	ldr r0, _08059420
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80522F4
	ldr r1, [sp]
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _08059404
	movs r0, 0x1
	strb r0, [r1]
_08059404:
	movs r1, 0x1
	mov r10, r1
_08059408:
	mov r0, r10
_0805940A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805941C: .4byte gUnknown_202DE58
_08059420: .4byte gUnknown_80FE38C
	thumb_func_end SketchMoveAction

	thumb_func_start sub_8059424
sub_8059424:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805945E
	movs r7, 0x1
	ldr r0, _08059468
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805945E
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80776C0
_0805945E:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059468: .4byte gUnknown_80F4DF0
	thumb_func_end sub_8059424

	thumb_func_start sub_805946C
sub_805946C:
	push {r4-r6,lr}
	sub sp, 0x18
	adds r5, r0, 0
	movs r6, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080594D2
	movs r6, 0x1
	adds r0, r5, 0
	movs r1, 0x7
	bl HasAbility
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080594D2
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _080594D2
	ldr r0, [r5, 0x70]
	movs r1, 0x10
	ldrsh r2, [r0, r1]
	cmp r2, 0
	bge _080594B0
	adds r2, 0x7
_080594B0:
	asrs r2, 3
	cmp r2, 0
	bne _080594B8
	movs r2, 0x1
_080594B8:
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r0, _080594DC
	str r0, [sp, 0x8]
	movs r0, 0x14
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	str r4, [sp, 0x14]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r3, 0
	bl sub_806F370
_080594D2:
	adds r0, r6, 0
	add sp, 0x18
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080594DC: .4byte 0x000001fd
	thumb_func_end sub_805946C

	thumb_func_start sub_80594E0
sub_80594E0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _08059518
	ldr r0, [r0]
	ldr r1, _0805951C
	ldrh r1, [r1]
	ldr r2, _08059520
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x1
	movs r1, 0
	bl sub_807EAA0
	lsls r0, 24
	cmp r0, 0
	bne _0805950E
	ldr r0, _08059524
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_0805950E:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08059518: .4byte gDungeonGlobalData
_0805951C: .4byte gUnknown_80F4F42
_08059520: .4byte 0x0000e269
_08059524: .4byte gUnknown_80FCF78
	thumb_func_end sub_80594E0

	thumb_func_start sub_8059528
sub_8059528:
	push {lr}
	ldr r2, _0805953C
	ldr r2, [r2]
	movs r3, 0x1
	bl sub_80775DC
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805953C: .4byte gUnknown_8106A4C
	thumb_func_end sub_8059528

	thumb_func_start sub_8059540
sub_8059540:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805957A
	movs r7, 0x1
	ldr r0, _08059584
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805957A
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80763F8
_0805957A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059584: .4byte gUnknown_80F4DC4
	thumb_func_end sub_8059540

	thumb_func_start sub_8059588
sub_8059588:
	push {lr}
	ldr r2, _0805959C
	ldr r2, [r2]
	movs r3, 0x1
	bl sub_8077084
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805959C: .4byte gUnknown_8106A50
	thumb_func_end sub_8059588

	thumb_func_start sub_80595A0
sub_80595A0:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080595DC
	movs r7, 0x1
	ldr r0, _080595E8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080595DC
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_8076210
_080595DC:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080595E8: .4byte gUnknown_80F4DE0
	thumb_func_end sub_80595A0

	thumb_func_start sub_80595EC
sub_80595EC:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	mov r9, r0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	movs r7, 0
	add r0, sp, 0x18
	strb r7, [r0]
	adds r0, r5, 0
	bl GetMoveType
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_806F4A4
	lsls r0, 24
	cmp r0, 0
	bne _08059630
	ldr r0, _0805962C
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _08059678
	.align 2, 0
_0805962C: .4byte gUnknown_80FEB8C
_08059630:
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r2, _08059688
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r7, [sp, 0x14]
	mov r0, r9
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059672
	movs r2, 0x1
_08059672:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
_08059678:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059688: .4byte 0x0000270f
	thumb_func_end sub_80595EC

	thumb_func_start sub_805968C
sub_805968C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r5, r0, 0
	mov r8, r1
	adds r6, r2, 0
	adds r7, r3, 0
	bl GetWeather
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	beq _080596B6
	adds r0, r5, 0
	adds r1, r6, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _080596EC
_080596B6:
	ldr r0, _080596E8
	ldr r3, [r0]
	cmp r4, 0x2
	beq _080596C6
	cmp r4, 0x4
	beq _080596C6
	cmp r4, 0x5
	bne _080596CC
_080596C6:
	lsrs r0, r3, 31
	adds r0, r3, r0
	asrs r3, r0, 1
_080596CC:
	str r7, [sp]
	adds r0, r5, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r5, 0
	bl sub_8079764
	b _08059700
	.align 2, 0
_080596E8: .4byte gUnknown_80F4F48
_080596EC:
	ldr r0, _08059710
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x2
	adds r3, r6, 0
	bl sub_8079618
	movs r4, 0x1
_08059700:
	adds r0, r4, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059710: .4byte gUnknown_80FACE4
	thumb_func_end sub_805968C

	thumb_func_start sub_8059714
sub_8059714:
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x1C
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0805978C
	movs r3, 0
	ldrsh r2, [r1, r3]
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r5, [sp, 0x14]
	mov r0, r9
	mov r1, r10
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059774
	movs r2, 0x1
_08059774:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805978C: .4byte gUnknown_80F4F7C
	thumb_func_end sub_8059714

	thumb_func_start sub_8059790
sub_8059790:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	adds r1, r4, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _080597CC
	ldr r0, _080597C8
	ldr r3, [r0]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r5, 0
	bl sub_8079764
	b _080597E0
	.align 2, 0
_080597C8: .4byte gUnknown_80F4F5C
_080597CC:
	ldr r0, _080597EC
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	movs r2, 0x7
	adds r3, r4, 0
	bl sub_8079618
	movs r4, 0x1
_080597E0:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080597EC: .4byte gUnknown_80FACFC
	thumb_func_end sub_8059790

	thumb_func_start sub_80597F0
sub_80597F0:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	mov r9, r0
	mov r8, r1
	adds r5, r2, 0
	adds r6, r3, 0
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	mov r2, r8
	adds r2, 0x4
	str r4, [sp]
	str r0, [sp, 0x4]
	mov r0, r9
	mov r1, r8
	movs r3, 0x2
	bl sub_807DF38
	movs r0, 0x1
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80597F0

	thumb_func_start DiveMoveAction
DiveMoveAction:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	mov r8, r3
	movs r6, 0
	bl GetMapTileForDungeonEntity_2
	bl IsTileGround
	lsls r0, 24
	cmp r0, 0
	beq _08059870
	ldr r0, _0805986C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_80522F4
	b _080598B8
	.align 2, 0
_0805986C: .4byte gUnknown_80FD128
_08059870:
	adds r0, r4, 0
	adds r1, r5, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _080598A4
	ldr r0, _080598A0
	ldr r3, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r6, r1, 31
	adds r0, r4, 0
	bl sub_8079764
	b _080598B8
	.align 2, 0
_080598A0: .4byte gUnknown_80F4F64
_080598A4:
	ldr r0, _080598C8
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x9
	adds r3, r5, 0
	bl sub_8079618
	movs r6, 0x1
_080598B8:
	adds r0, r6, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080598C8: .4byte gUnknown_80FAD2C
	thumb_func_end DiveMoveAction

	thumb_func_start sub_80598CC
sub_80598CC:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805990A
	movs r7, 0x1
	ldr r0, _08059914
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805990A
	ldr r0, _08059918
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_80775DC
_0805990A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059914: .4byte gUnknown_80F4E00
_08059918: .4byte gUnknown_8106A4C
	thumb_func_end sub_80598CC

	thumb_func_start sub_805991C
sub_805991C:
	push {lr}
	bl sub_80787E4
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805991C

	thumb_func_start sub_8059928
sub_8059928:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, r3, 0
	movs r3, 0x1
	movs r6, 0
	ldr r0, [r4, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	subs r0, 0x7
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08059948
	movs r3, 0x2
_08059948:
	lsls r3, 8
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059978
	movs r6, 0x1
	ldr r0, _08059984
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059978
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_80776C0
_08059978:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08059984: .4byte gUnknown_80F4DEC
	thumb_func_end sub_8059928

	thumb_func_start sub_8059988
sub_8059988:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _080599A8
	movs r7, 0x1
	ldr r0, _080599E0
	strb r7, [r0]
_080599A8:
	ldr r0, _080599E0
	ldrb r0, [r0]
	cmp r0, 0
	beq _080599D6
	ldr r0, _080599E4
	ldr r0, [r0]
	cmp r0, 0x2
	bne _080599D6
	ldr r0, _080599E8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _080599D6
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80763F8
_080599D6:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080599E0: .4byte gUnknown_202F218
_080599E4: .4byte gUnknown_202F214
_080599E8: .4byte gUnknown_80F4DC8
	thumb_func_end sub_8059988

	thumb_func_start sub_80599EC
sub_80599EC:
	push {r4,lr}
	sub sp, 0x4
	adds r3, r0, 0
	ldr r0, [r1, 0x70]
	movs r4, 0x10
	ldrsh r2, [r0, r4]
	cmp r2, 0
	bge _080599FE
	adds r2, 0x3
_080599FE:
	asrs r2, 2
	movs r0, 0x1
	str r0, [sp]
	adds r0, r3, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80599EC

	thumb_func_start sub_8059A18
sub_8059A18:
	push {lr}
	ldr r2, _08059A28
	ldr r2, [r2]
	bl sub_8077540
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08059A28: .4byte gUnknown_8106A50
	thumb_func_end sub_8059A18

	thumb_func_start sub_8059A2C
sub_8059A2C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r9, r0
	adds r7, r1, 0
	adds r6, r2, 0
	mov r8, r3
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	mov r1, r9
	ldr r0, [r1, 0x70]
	ldrb r0, [r0, 0x9]
	mov r10, r0
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r5, [sp, 0x14]
	mov r0, r9
	adds r1, r7, 0
	mov r2, r10
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059A90
	movs r2, 0x1
_08059A90:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8059A2C

	thumb_func_start sub_8059AA8
sub_8059AA8:
	push {lr}
	movs r2, 0x1
	bl sub_8077AE4
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059AA8

	thumb_func_start sub_8059AB8
sub_8059AB8:
	push {lr}
	bl sub_8078758
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059AB8

	thumb_func_start sub_8059AC4
sub_8059AC4:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, _08059AF4
	bl GetWeather
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08059AF4: .4byte gUnknown_80F501A
	thumb_func_end sub_8059AC4

	thumb_func_start sub_8059AF8
sub_8059AF8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x1C
	mov r9, r0
	adds r6, r1, 0
	adds r5, r2, 0
	mov r8, r3
	movs r7, 0
	add r0, sp, 0x18
	strb r7, [r0]
	adds r0, r5, 0
	bl GetMoveType
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_806F4A4
	lsls r0, 24
	cmp r0, 0
	bne _08059B3C
	ldr r0, _08059B38
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _08059B82
	.align 2, 0
_08059B38: .4byte gUnknown_80FEB90
_08059B3C:
	adds r0, r5, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r2, _08059B90
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r7, [sp, 0xC]
	str r7, [sp, 0x10]
	str r7, [sp, 0x14]
	mov r0, r9
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08059B7C
	movs r2, 0x1
_08059B7C:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
_08059B82:
	add sp, 0x1C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059B90: .4byte 0x0000270f
	thumb_func_end sub_8059AF8

	thumb_func_start sub_8059B94
sub_8059B94:
	push {lr}
	ldr r2, _08059BA8
	ldr r2, [r2]
	movs r3, 0x2
	bl sub_8077084
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08059BA8: .4byte gUnknown_8106A4C
	thumb_func_end sub_8059B94

	thumb_func_start sub_8059BAC
sub_8059BAC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r10, r0
	adds r5, r1, 0
	movs r0, 0
	mov r8, r0
	ldr r7, [r5, 0x70]
	adds r0, r5, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08059BD8
	ldr r0, _08059BD4
	b _08059C5E
	.align 2, 0
_08059BD4: .4byte gPtrForecastPreventsTypeSwitchMessage
_08059BD8:
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r7, r1
	mov r9, sp
	movs r6, 0x3
_08059BE2:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08059C08
	adds r0, r5, 0
	adds r1, r4, 0
	bl GetMoveTypeForPokemon
	lsls r0, 24
	cmp r0, 0
	beq _08059C08
	mov r0, r9
	adds r0, 0x4
	mov r9, r0
	subs r0, 0x4
	stm r0!, {r4}
	movs r1, 0x1
	add r8, r1
_08059C08:
	adds r4, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _08059BE2
	mov r0, r8
	cmp r0, 0
	beq _08059C5C
	bl DungeonRandomCapped
	lsls r0, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r1, [r4]
	adds r0, r5, 0
	bl GetMoveTypeForPokemon
	adds r1, r7, 0
	adds r1, 0x5C
	movs r2, 0
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x5D
	strb r2, [r0]
	adds r1, 0x9A
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _08059C54
	ldr r1, [r4]
	bl sub_80928C0
	ldr r0, _08059C58
	ldr r2, [r0]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0x1
	b _08059C6A
	.align 2, 0
_08059C54: .4byte gUnknown_202DE58
_08059C58: .4byte gUnknown_80FE330
_08059C5C:
	ldr r0, _08059C7C
_08059C5E:
	ldr r2, [r0]
	mov r0, r10
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0
_08059C6A:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059C7C: .4byte gUnknown_80FE36C
	thumb_func_end sub_8059BAC

	thumb_func_start sub_8059C80
sub_8059C80:
	push {lr}
	bl sub_8079D1C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059C80

	thumb_func_start HelpingHandMoveAction
HelpingHandMoveAction:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r6, 0
	cmp r5, r4
	bne _08059CA8
	ldr r0, _08059CA4
	ldr r2, [r0]
	adds r0, r4, 0
	bl sub_80522F4
	b _08059CC6
	.align 2, 0
_08059CA4: .4byte gUnknown_80FEB60
_08059CA8:
	ldr r0, _08059CD0
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8077084
	ldr r0, _08059CD4
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8077084
	movs r6, 0x1
_08059CC6:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08059CD0: .4byte gUnknown_8106A4C
_08059CD4: .4byte gUnknown_8106A50
	thumb_func_end HelpingHandMoveAction

	thumb_func_start sub_8059CD8
sub_8059CD8:
	push {lr}
	ldr r2, _08059CEC
	ldr r2, [r2]
	movs r3, 0x2
	bl sub_8077160
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_08059CEC: .4byte gUnknown_8106A4C
	thumb_func_end sub_8059CD8

	thumb_func_start sub_8059CF0
sub_8059CF0:
	push {lr}
	movs r2, 0
	movs r3, 0
	bl sub_807D148
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059CF0

	thumb_func_start sub_8059D00
sub_8059D00:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059D3A
	movs r7, 0x1
	ldr r0, _08059D44
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059D3A
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
_08059D3A:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059D44: .4byte gUnknown_80F4DE2
	thumb_func_end sub_8059D00

	thumb_func_start sub_8059D48
sub_8059D48:
	push {lr}
	movs r2, 0x1
	bl sub_8077780
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059D48

	thumb_func_start sub_8059D58
sub_8059D58:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059D8E
	movs r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059D8E
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
_08059D8E:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8059D58

	thumb_func_start sub_8059D98
sub_8059D98:
	push {lr}
	bl sub_80769CC
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059D98

	thumb_func_start sub_8059DA4
sub_8059DA4:
	push {lr}
	movs r2, 0x1
	bl sub_80763F8
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059DA4

	thumb_func_start sub_8059DB4
sub_8059DB4:
	push {lr}
	movs r2, 0x1
	bl sub_80765E0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8059DB4

	thumb_func_start sub_8059DC4
sub_8059DC4:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059DFE
	movs r7, 0x1
	ldr r0, _08059E08
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059DFE
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80765E0
_08059DFE:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059E08: .4byte gUnknown_80F4DCA
	thumb_func_end sub_8059DC4

	thumb_func_start sub_8059E0C
sub_8059E0C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059E46
	movs r7, 0x1
	ldr r0, _08059E50
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059E46
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80763F8
_08059E46:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059E50: .4byte gUnknown_80F4DBE
	thumb_func_end sub_8059E0C

	thumb_func_start sub_8059E54
sub_8059E54:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x2C
	adds r6, r0, 0
	mov r8, r1
	adds r7, r2, 0
	adds r1, r3, 0
	ldr r0, [sp, 0x48]
	lsls r0, 24
	movs r2, 0
	mov r9, r2
	cmp r0, 0
	bne _08059E8A
	movs r3, 0x80
	lsls r3, 1
	str r1, [sp]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	mov r9, r1
_08059E8A:
	mov r0, r9
	cmp r0, 0
	bne _08059F1A
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMoveTypeForPokemon
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r7, 0
	bl CalculateMovePower
	adds r5, r0, 0
	adds r0, r7, 0
	bl GetMoveCriticalHitChance
	str r0, [sp]
	add r2, sp, 0x18
	str r2, [sp, 0x4]
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp, 0x8]
	ldrh r0, [r7, 0x2]
	str r0, [sp, 0xC]
	mov r0, r9
	str r0, [sp, 0x10]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_806EAF4
	ldr r0, _08059F2C
	ldr r1, [r6, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _08059F30
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r8
	bl sub_80522F4
	ldr r0, [sp, 0x18]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp, 0x18]
	cmp r0, 0
	bne _08059EF6
	movs r0, 0x1
	str r0, [sp, 0x18]
_08059EF6:
	ldr r2, [sp, 0x18]
	add r0, sp, 0x28
	str r0, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	ldr r0, _08059F34
	str r0, [sp, 0x8]
	movs r0, 0x13
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	mov r0, r9
	str r0, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_806F370
_08059F1A:
	mov r0, r9
	add sp, 0x2C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059F2C: .4byte gAvailablePokemonNames
_08059F30: .4byte gUnknown_80FC7C8
_08059F34: .4byte 0x000001f7
	thumb_func_end sub_8059E54

	thumb_func_start sub_8059F38
sub_8059F38:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	adds r7, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r4, 0
	adds r1, r5, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _08059FA0
	ldr r0, _08059F98
	ldr r3, [r0]
	str r7, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _08059F90
	movs r1, 0x1
	mov r8, r1
	ldr r0, _08059F9C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08059F90
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
_08059F90:
	adds r0, r4, 0
	bl sub_8079764
	b _08059FB6
	.align 2, 0
_08059F98: .4byte gUnknown_80F4F60
_08059F9C: .4byte gUnknown_80F4DCC
_08059FA0:
	ldr r0, _08059FC4
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0x8
	adds r3, r5, 0
	bl sub_8079618
	movs r0, 0x1
	mov r8, r0
_08059FB6:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08059FC4: .4byte gUnknown_80FAD10
	thumb_func_end sub_8059F38

	thumb_func_start sub_8059FC8
sub_8059FC8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x2C
	adds r6, r0, 0
	mov r8, r1
	adds r7, r2, 0
	adds r1, r3, 0
	ldr r0, [sp, 0x48]
	lsls r0, 24
	movs r2, 0
	mov r9, r2
	cmp r0, 0
	bne _08059FFE
	movs r3, 0x80
	lsls r3, 2
	str r1, [sp]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	mov r9, r1
_08059FFE:
	mov r0, r9
	cmp r0, 0
	bne _0805A090
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMoveTypeForPokemon
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r7, 0
	bl CalculateMovePower
	adds r5, r0, 0
	adds r0, r7, 0
	bl GetMoveCriticalHitChance
	str r0, [sp]
	add r2, sp, 0x18
	str r2, [sp, 0x4]
	movs r0, 0x80
	lsls r0, 2
	str r0, [sp, 0x8]
	ldrh r0, [r7, 0x2]
	str r0, [sp, 0xC]
	mov r0, r9
	str r0, [sp, 0x10]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r4, 0
	adds r3, r5, 0
	bl sub_806EAF4
	ldr r0, _0805A0A0
	ldr r1, [r6, 0x70]
	movs r2, 0
	bl SetMessageArgument_2
	ldr r0, _0805A0A4
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r8
	bl sub_80522F4
	ldr r0, [sp, 0x18]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [sp, 0x18]
	cmp r0, 0
	bne _0805A06A
	movs r0, 0x1
	str r0, [sp, 0x18]
_0805A06A:
	ldr r2, [sp, 0x18]
	add r0, sp, 0x28
	str r0, [sp]
	mov r0, r9
	str r0, [sp, 0x4]
	movs r0, 0xFC
	lsls r0, 1
	str r0, [sp, 0x8]
	movs r0, 0x13
	str r0, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	mov r0, r9
	str r0, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_806F370
_0805A090:
	mov r0, r9
	add sp, 0x2C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A0A0: .4byte gAvailablePokemonNames
_0805A0A4: .4byte gUnknown_80FC7C8
	thumb_func_end sub_8059FC8

	thumb_func_start sub_805A0A8
sub_805A0A8:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A114
	movs r7, 0x1
	ldr r0, _0805A0F8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A114
	movs r0, 0x3
	bl DungeonRandomCapped
	cmp r0, 0x1
	beq _0805A0FC
	cmp r0, 0x1
	ble _0805A0EA
	cmp r0, 0x2
	beq _0805A10A
_0805A0EA:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
	b _0805A114
	.align 2, 0
_0805A0F8: .4byte gUnknown_80F4DFC
_0805A0FC:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_8076210
	b _0805A114
_0805A10A:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80767B0
_0805A114:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805A0A8

	thumb_func_start sub_805A120
sub_805A120:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0
	mov r10, r0
	ldr r1, [r6, 0x70]
	mov r9, r1
	mov r7, r9
	ldr r2, [r5, 0x70]
	mov r8, r2
	mov r0, r8
	str r0, [sp]
	ldr r4, _0805A16C
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	movs r1, 0x2C
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805A174
	ldr r0, _0805A170
	b _0805A1B8
	.align 2, 0
_0805A16C: .4byte gAvailablePokemonNames
_0805A170: .4byte gUnknown_80FCCE4
_0805A174:
	adds r0, r5, 0
	movs r1, 0x24
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0805A18C
	ldr r0, _0805A188
	b _0805A1B8
	.align 2, 0
_0805A188: .4byte gUnknown_80FD578
_0805A18C:
	mov r0, r9
	adds r0, 0x60
	mov r2, r8
	adds r2, 0x60
	ldrb r1, [r0]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _0805A1A2
	mov r10, r4
_0805A1A2:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _0805A1B0
	movs r1, 0x1
	mov r10, r1
_0805A1B0:
	mov r2, r10
	cmp r2, 0
	beq _0805A1CC
	ldr r0, _0805A1C8
_0805A1B8:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0
	b _0805A1FC
	.align 2, 0
_0805A1C8: .4byte gUnknown_80FC7AC
_0805A1CC:
	ldr r0, [r7, 0x60]
	ldr r2, [sp]
	ldr r1, [r2, 0x60]
	str r1, [r7, 0x60]
	str r0, [r2, 0x60]
	adds r0, r6, 0
	bl sub_806A6E8
	adds r0, r5, 0
	bl sub_806A6E8
	adds r1, r7, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805A1EE
	strb r4, [r1]
_0805A1EE:
	ldr r0, _0805A20C
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0x1
_0805A1FC:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A20C: .4byte gUnknown_80FC790
	thumb_func_end sub_805A120

	thumb_func_start sub_805A210
sub_805A210:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r3, 0
	ldr r4, _0805A238
	ldr r3, [r4]
	adds r3, 0x1
	str r3, [r4]
	lsls r3, 8
	str r5, [sp]
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A238: .4byte gUnknown_202F210
	thumb_func_end sub_805A210

	thumb_func_start sub_805A23C
sub_805A23C:
	push {lr}
	ldrh r0, [r2, 0x2]
	cmp r0, 0xD4
	bne _0805A24C
	movs r0, 0
	bl sub_807EA30
	b _0805A252
_0805A24C:
	movs r0, 0x1
	bl sub_807EA30
_0805A252:
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A23C

	thumb_func_start sub_805A258
sub_805A258:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A292
	movs r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A292
	ldr r0, _0805A29C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_80775DC
_0805A292:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A29C: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A258

	thumb_func_start sub_805A2A0
sub_805A2A0:
	push {lr}
	bl sub_805BA50
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_805A2A0

	thumb_func_start sub_805A2B0
sub_805A2B0:
	push {lr}
	ldr r2, _0805A2C4
	ldr r2, [r2]
	movs r3, 0x2
	bl sub_8077160
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805A2C4: .4byte gUnknown_8106A50
	thumb_func_end sub_805A2B0

	thumb_func_start sub_805A2C8
sub_805A2C8:
	push {lr}
	sub sp, 0x8
	ldr r2, _0805A2E4
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	bl sub_8076E20
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0805A2E4: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A2C8

	thumb_func_start sub_805A2E8
sub_805A2E8:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
	ldr r0, [r1, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	movs r4, 0x80
	lsls r4, 1
	cmp r0, 0x9
	bne _0805A302
	movs r4, 0x80
	lsls r4, 2
_0805A302:
	str r3, [sp]
	adds r0, r5, 0
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A312
	movs r6, 0x1
_0805A312:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805A2E8

	thumb_func_start sub_805A31C
sub_805A31C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, [r5, 0x70]
	ldr r7, [r6, 0x70]
	adds r0, r6, 0
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805A348
	ldr r0, _0805A344
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _0805A386
	.align 2, 0
_0805A344: .4byte gUnknown_80FC854
_0805A348:
	adds r0, r7, 0
	adds r0, 0x5E
	ldrb r0, [r0]
	adds r1, r4, 0
	adds r1, 0x5E
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x5F
	ldrb r0, [r0]
	adds r1, 0x1
	strb r0, [r1]
	ldr r0, _0805A38C
	ldr r0, [r0]
	movs r2, 0x1
	strb r2, [r0, 0xC]
	adds r1, 0x9C
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805A370
	strb r2, [r1]
_0805A370:
	ldr r0, _0805A390
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_806ABAC
	movs r0, 0x1
_0805A386:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A38C: .4byte gDungeonGlobalData
_0805A390: .4byte gUnknown_80FC81C
	thumb_func_end sub_805A31C

	thumb_func_start sub_805A394
sub_805A394:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _0805A3CC
	ldr r0, [r0]
	ldr r1, _0805A3D0
	ldrh r1, [r1]
	ldr r2, _0805A3D4
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x1
	movs r1, 0
	bl sub_807EAA0
	lsls r0, 24
	cmp r0, 0
	bne _0805A3C2
	ldr r0, _0805A3D8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_0805A3C2:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A3CC: .4byte gDungeonGlobalData
_0805A3D0: .4byte gUnknown_80F4F42
_0805A3D4: .4byte 0x0000e268
_0805A3D8: .4byte gUnknown_80FCF7C
	thumb_func_end sub_805A394

	thumb_func_start sub_805A3DC
sub_805A3DC:
	push {lr}
	sub sp, 0x8
	ldr r2, _0805A3F8
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	bl sub_8076F80
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0805A3F8: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A3DC

	thumb_func_start sub_805A3FC
sub_805A3FC:
	push {lr}
	bl sub_807992C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A3FC

	thumb_func_start sub_805A408
sub_805A408:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A442
	movs r7, 0x1
	ldr r0, _0805A44C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A442
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80776C0
_0805A442:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A44C: .4byte gUnknown_80F4DF2
	thumb_func_end sub_805A408

	thumb_func_start sub_805A450
sub_805A450:
	push {lr}
	ldr r2, _0805A460
	ldr r2, [r2]
	bl sub_80522F4
	movs r0, 0
	pop {r1}
	bx r1
	.align 2, 0
_0805A460: .4byte gUnknown_80FC730
	thumb_func_end sub_805A450

	thumb_func_start sub_805A464
sub_805A464:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A4B4
	movs r7, 0x1
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _0805A4B4
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805A4B4
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	movs r1, 0x69
	movs r2, 0x2
	bl sub_8045C28
	add r3, sp, 0x8
	adds r0, r5, 0
	adds r1, r6, 0
	add r2, sp, 0x4
	bl sub_805A7D4
_0805A4B4:
	adds r0, r7, 0
	add sp, 0xC
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805A464

	thumb_func_start sub_805A4C0
sub_805A4C0:
	push {lr}
	ldr r2, _0805A4D0
	ldr r2, [r2]
	bl sub_80522F4
	movs r0, 0
	pop {r1}
	bx r1
	.align 2, 0
_0805A4D0: .4byte gUnknown_80FC74C
	thumb_func_end sub_805A4C0

	thumb_func_start sub_805A4D4
sub_805A4D4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _0805A4F8
	adds r0, r4, 0
	movs r2, 0
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8075E74
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A4F8: .4byte gUnknown_80F4E94
	thumb_func_end sub_805A4D4

	thumb_func_start sub_805A4FC
sub_805A4FC:
	push {lr}
	bl sub_8076AA4
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A4FC

	thumb_func_start sub_805A508
sub_805A508:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r3, r1, 0
	ldr r0, [r3, 0x70]
	movs r1, 0x89
	lsls r1, 1
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0
	beq _0805A540
	ldr r1, _0805A53C
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r3, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0
	strb r0, [r4]
	b _0805A54C
	.align 2, 0
_0805A53C: .4byte gUnknown_80F51D4
_0805A540:
	ldr r0, _0805A558
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r3, 0
	bl sub_80522F4
_0805A54C:
	movs r0, 0x1
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805A558: .4byte gUnknown_80FC770
	thumb_func_end sub_805A508

	thumb_func_start sub_805A55C
sub_805A55C:
	push {lr}
	bl sub_8078594
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805A55C

	thumb_func_start sub_805A568
sub_805A568:
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_805A568

	thumb_func_start sub_805A588
sub_805A588:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A5D8
	movs r7, 0x1
	adds r0, r6, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A5D8
	ldr r0, _0805A5E4
	ldr r5, [r0]
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_8076E20
	str r4, [sp]
	str r4, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_8076F80
_0805A5D8:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A5E4: .4byte gUnknown_8106A4C
	thumb_func_end sub_805A588

	thumb_func_start sub_805A5E8
sub_805A5E8:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x18]
	movs r6, 0
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	adds r0, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A632
	movs r6, 0x1
	ldr r0, _0805A63C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A632
	ldr r4, [r5, 0x70]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r7, 0
	movs r3, 0x1
	bl sub_8077160
	adds r4, 0xFB
	ldrb r0, [r4]
	cmp r0, 0
	bne _0805A632
	strb r6, [r4]
_0805A632:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A63C: .4byte gUnknown_80F4DD2
	thumb_func_end sub_805A5E8

	thumb_func_start SpitUpMoveAction
SpitUpMoveAction:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	adds r1, r3, 0
	ldr r0, [r5, 0x70]
	movs r3, 0x89
	lsls r3, 1
	adds r4, r0, r3
	ldrb r0, [r4]
	cmp r0, 0
	beq _0805A66C
	adds r3, r0, 0
	lsls r3, 8
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8055640
	movs r0, 0
	strb r0, [r4]
	b _0805A678
_0805A66C:
	ldr r0, _0805A684
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
_0805A678:
	movs r0, 0x1
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805A684: .4byte gUnknown_80FCA3C
	thumb_func_end SpitUpMoveAction

	thumb_func_start sub_805A688
sub_805A688:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805A6BE
	movs r7, 0x1
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805A6BE
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077AE4
_0805A6BE:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805A688

	thumb_func_start sub_805A6C8
sub_805A6C8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	ldr r0, [r6, 0x70]
	mov r9, r0
	ldr r7, [r5, 0x70]
	mov r8, r7
	ldr r4, _0805A708
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	movs r1, 0x2C
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805A710
	ldr r0, _0805A70C
	b _0805A73A
	.align 2, 0
_0805A708: .4byte gAvailablePokemonNames
_0805A70C: .4byte gUnknown_80FCCE8
_0805A710:
	adds r0, r5, 0
	movs r1, 0x24
	bl HasItem
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _0805A728
	ldr r0, _0805A724
	b _0805A73A
	.align 2, 0
_0805A724: .4byte gUnknown_80FD57C
_0805A728:
	ldr r0, [r7, 0x60]
	str r0, [sp]
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805A74C
	ldr r0, _0805A748
_0805A73A:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0
	b _0805A7B4
	.align 2, 0
_0805A748: .4byte gUnknown_80FD18C
_0805A74C:
	mov r0, r8
	adds r0, 0x60
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x1]
	strb r2, [r0]
	ldr r0, _0805A7C4
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	ldr r4, _0805A7C8
	mov r3, r9
	adds r3, 0x46
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r2, [r0]
	ldr r0, _0805A7CC
	ldr r1, [sp, 0x4]
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0x4]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2]
	lsls r0, 16
	ldr r2, _0805A7D0
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x4]
	add r3, sp, 0x4
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, sp
	bl sub_805A7D4
	adds r1, r5, 0x4
	adds r0, r5, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _0805A7B2
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_0805A7B2:
	movs r0, 0x1
_0805A7B4:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A7C4: .4byte gUnknown_80FD170
_0805A7C8: .4byte gAdjacentTileOffsets
_0805A7CC: .4byte 0xffff0000
_0805A7D0: .4byte 0x0000ffff
	thumb_func_end sub_805A6C8

	thumb_func_start sub_805A7D4
sub_805A7D4:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x78
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	movs r0, 0x3
	str r0, [sp, 0x4]
	add r0, sp, 0x28
	movs r5, 0
	strb r5, [r0]
	add r1, sp, 0x24
	movs r0, 0x1
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x26
	strb r5, [r0]
	str r6, [sp, 0x74]
	add r1, sp, 0x4
	ldrh r0, [r3]
	ldrh r2, [r4, 0x4]
	adds r0, r2
	strh r0, [r1, 0x4]
	ldrh r0, [r3, 0x2]
	ldrh r2, [r4, 0x6]
	adds r0, r2
	strh r0, [r1, 0x6]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, 0x4
	lsls r1, 8
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r2, 0x4
	lsls r2, 8
	add r0, sp, 0x4
	bl sub_8045394
	add r0, sp, 0x4
	strh r5, [r0, 0x26]
	ldr r0, _0805A858
	add r1, sp, 0x4
	movs r2, 0
	bl SetMessageArgument
	str r5, [sp]
	mov r0, r8
	add r1, sp, 0x4
	adds r2, r6, 0
	movs r3, 0x1
	bl sub_804652C
	add sp, 0x78
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805A858: .4byte gUnknown_202DE58
	thumb_func_end sub_805A7D4

	thumb_func_start sub_805A85C
sub_805A85C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	mov r8, r0
	adds r6, r1, 0
	mov r10, r2
	str r3, [sp, 0x24]
	ldr r0, [r6, 0x4]
	str r0, [sp, 0x18]
	adds r0, r6, 0
	movs r1, 0xA
	movs r2, 0x8
	bl sub_806CDD4
	movs r5, 0
_0805A880:
	movs r0, 0x3
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r0, 0x3
	bl DungeonRandomCapped
	adds r2, r0, 0
	subs r4, 0x1
	subs r2, 0x1
	cmp r4, 0
	bne _0805A89C
	cmp r2, 0
	beq _0805A8BC
_0805A89C:
	ldrh r0, [r6, 0x4]
	adds r0, r4
	lsls r0, 16
	ldrh r1, [r6, 0x6]
	adds r1, r2
	lsls r1, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x18]
	adds r0, r6, 0
	add r1, sp, 0x18
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	beq _0805A8C2
_0805A8BC:
	adds r5, 0x1
	cmp r5, 0x27
	ble _0805A880
_0805A8C2:
	cmp r5, 0x28
	bne _0805A8DC
	ldr r0, _0805A8D8
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
	b _0805AAB8
	.align 2, 0
_0805A8D8: .4byte gUnknown_80FEBDC
_0805A8DC:
	add r0, sp, 0x18
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r3, 0xC0
	lsls r3, 4
	adds r0, r3
	ldr r1, [r6, 0xC]
	subs r0, r1
	movs r1, 0xC
	bl __divsi3
	str r0, [sp, 0x28]
	add r0, sp, 0x18
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r3, 0x80
	lsls r3, 5
	adds r0, r3
	ldr r1, [r6, 0x10]
	subs r0, r1
	movs r1, 0xC
	bl __divsi3
	str r0, [sp, 0x2C]
	adds r4, r6, 0x4
	adds r0, r4, 0
	bl sub_803F428
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	bne _0805A934
	add r0, sp, 0x18
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0805A94C
_0805A934:
	movs r5, 0xB
_0805A936:
	adds r0, r6, 0
	ldr r1, [sp, 0x28]
	ldr r2, [sp, 0x2C]
	bl sub_804539C
	movs r0, 0x2C
	bl sub_803E46C
	subs r5, 0x1
	cmp r5, 0
	bge _0805A936
_0805A94C:
	add r0, sp, 0x18
	movs r1, 0
	ldrsh r0, [r0, r1]
	add r4, sp, 0x18
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl GetMapTile_2
	ldr r5, [r0, 0x10]
	cmp r5, 0
	beq _0805AA4C
	adds r0, r5, 0
	bl GetEntityType
	adds r7, r0, 0
	cmp r7, 0x1
	bne _0805A9FE
	add r4, sp, 0x1C
	ldr r1, _0805AA44
	adds r0, r4, 0
	bl InitPokemonMove
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80571F0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805A9B0
	mov r0, r10
	ldr r1, [sp, 0x24]
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0805AA48
	movs r3, 0
	ldrsh r2, [r1, r3]
	str r4, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	str r7, [sp, 0x10]
	str r4, [sp, 0x14]
	mov r0, r8
	adds r1, r5, 0
	movs r3, 0
	bl sub_806F370
_0805A9B0:
	bl sub_8044B28
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805AAB6
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
	ldr r0, _0805AA48
	movs r1, 0
	ldrsh r2, [r0, r1]
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0xFF
	lsls r0, 1
	str r0, [sp, 0x8]
	str r4, [sp, 0xC]
	str r4, [sp, 0x10]
	str r4, [sp, 0x14]
	mov r0, r8
	mov r1, r8
	movs r3, 0
	bl sub_806F370
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0805AAB6
	mov r0, r8
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
_0805A9FE:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
	mov r0, r9
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	bne _0805AA22
	add r0, sp, 0x18
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0805AA5E
_0805AA22:
	ldr r2, [sp, 0x28]
	negs r7, r2
	ldr r3, [sp, 0x2C]
	negs r4, r3
	movs r5, 0xB
_0805AA2C:
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_804539C
	movs r0, 0x2C
	bl sub_803E46C
	subs r5, 0x1
	cmp r5, 0
	bge _0805AA2C
	b _0805AA5E
	.align 2, 0
_0805AA44: .4byte 0x00000163
_0805AA48: .4byte gUnknown_80F4F82
_0805AA4C:
	add r0, sp, 0x18
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	adds r0, r6, 0
	movs r3, 0
	bl sub_80694C0
_0805AA5E:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AAB6
	adds r0, r6, 0
	movs r1, 0
	bl sub_804535C
	mov r1, r9
	adds r0, r6, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _0805AA8C
	mov r0, r8
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_0805AA8C:
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0805AAA0
	mov r0, r9
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0805AAA0:
	adds r0, r6, 0
	bl sub_806A5B8
	ldr r0, _0805AAC8
	ldr r0, [r0]
	ldr r1, _0805AACC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8075900
_0805AAB6:
	movs r0, 0x1
_0805AAB8:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AAC8: .4byte gDungeonGlobalData
_0805AACC: .4byte 0x00003a08
	thumb_func_end sub_805A85C

	thumb_func_start sub_805AAD0
sub_805AAD0:
	push {lr}
	adds r1, r0, 0
	bl sub_80782CC
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805AAD0

	thumb_func_start sub_805AAE0
sub_805AAE0:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [r4, 0x70]
	movs r7, 0
	movs r1, 0x9E
	lsls r1, 1
	adds r5, r0, r1
	ldr r0, [r5]
	bl RoundUpFixedPoint
	cmp r0, 0x1
	ble _0805AB20
	ldr r0, _0805AB1C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	movs r3, 0x63
	bl sub_8077084
	mov r0, sp
	movs r1, 0x1
	bl sub_80943A0
	ldr r0, [sp]
	str r0, [r5]
	movs r7, 0x1
	b _0805AB36
	.align 2, 0
_0805AB1C: .4byte gUnknown_8106A4C
_0805AB20:
	ldr r0, _0805AB40
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0805AB44
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80522F4
_0805AB36:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AB40: .4byte gAvailablePokemonNames
_0805AB44: .4byte gUnknown_80FC5CC
	thumb_func_end sub_805AAE0

	thumb_func_start sub_805AB48
sub_805AB48:
	push {lr}
	bl sub_8079A24
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805AB48

	thumb_func_start sub_805AB54
sub_805AB54:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	bne _0805AB70
	b _0805AC86
_0805AB70:
	movs r7, 0x1
	ldr r0, _0805ABA8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	bne _0805AB88
	b _0805AC86
_0805AB88:
	ldr r1, _0805ABAC
	ldr r0, _0805ABB0
	ldr r0, [r0]
	ldr r2, _0805ABB4
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x8
	bhi _0805AC7C
	lsls r0, 2
	ldr r1, _0805ABB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805ABA8: .4byte gUnknown_80F4E06
_0805ABAC: .4byte gUnknown_80F5978
_0805ABB0: .4byte gDungeonGlobalData
_0805ABB4: .4byte 0x00003a0e
_0805ABB8: .4byte _0805ABBC
	.align 2, 0
_0805ABBC:
	.4byte _0805ABE0
	.4byte _0805ABEC
	.4byte _0805AC08
	.4byte _0805AC16
	.4byte _0805AC34
	.4byte _0805AC50
	.4byte _0805AC64
	.4byte _0805AC70
	.4byte _0805AC7C
_0805ABE0:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80763F8
	b _0805AC86
_0805ABEC:
	ldr r1, _0805AC04
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_8075C58
	b _0805AC86
	.align 2, 0
_0805AC04: .4byte gUnknown_80F4E74
_0805AC08:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_80779F0
	b _0805AC86
_0805AC16:
	ldr r0, _0805AC30
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_8076E20
	b _0805AC86
	.align 2, 0
_0805AC30: .4byte gUnknown_8106A4C
_0805AC34:
	ldr r0, _0805AC4C
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_8076F80
	b _0805AC86
	.align 2, 0
_0805AC4C: .4byte gUnknown_8106A4C
_0805AC50:
	ldr r0, _0805AC60
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0
	bl sub_80775DC
	b _0805AC86
	.align 2, 0
_0805AC60: .4byte gUnknown_8106A4C
_0805AC64:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077AE4
	b _0805AC86
_0805AC70:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80776C0
	b _0805AC86
_0805AC7C:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077780
_0805AC86:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805AB54

	thumb_func_start sub_805AC90
sub_805AC90:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805ACCA
	movs r7, 0x1
	ldr r0, _0805ACD4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805ACCA
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_8077AE4
_0805ACCA:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805ACD4: .4byte gUnknown_80F4DFA
	thumb_func_end sub_805AC90

	thumb_func_start sub_805ACD8
sub_805ACD8:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, _0805AD00
	ldr r4, [r0]
	adds r0, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077084
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077160
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805AD00: .4byte gUnknown_8106A4C
	thumb_func_end sub_805ACD8

	thumb_func_start sub_805AD04
sub_805AD04:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _0805AD30
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r3, r0, 0
	movs r0, 0x1
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8076090
	movs r0, 0x1
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805AD30: .4byte gUnknown_80F4EE0
	thumb_func_end sub_805AD04

	thumb_func_start sub_805AD34
sub_805AD34:
	push {lr}
	sub sp, 0x8
	ldr r2, _0805AD50
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl sub_8076E20
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_0805AD50: .4byte gUnknown_8106A4C
	thumb_func_end sub_805AD34

	thumb_func_start sub_805AD54
sub_805AD54:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	mov r9, r1
	movs r0, 0
	mov r10, r0
	ldr r1, [r5, 0x70]
	mov r8, r1
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0805AD88
	ldr r0, _0805AD80
	ldr r0, [r0]
	ldr r1, _0805AD84
	adds r7, r0, r1
	movs r0, 0x10
	b _0805AD92
	.align 2, 0
_0805AD80: .4byte gDungeonGlobalData
_0805AD84: .4byte 0x0001358c
_0805AD88:
	ldr r0, _0805AD98
	ldr r0, [r0]
	ldr r1, _0805AD9C
	adds r7, r0, r1
	movs r0, 0x4
_0805AD92:
	str r0, [sp]
	movs r6, 0
	b _0805AE0E
	.align 2, 0
_0805AD98: .4byte gDungeonGlobalData
_0805AD9C: .4byte 0x0001357c
_0805ADA0:
	lsls r0, r6, 2
	adds r0, r7
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805AE0C
	cmp r5, r4
	beq _0805AE0C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl CanTarget
	lsls r0, 24
	cmp r0, 0
	bne _0805AE0C
	ldr r1, [r4, 0x70]
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0805AE0C
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0805ADE2
	cmp r0, 0x47
	bne _0805ADE6
_0805ADE2:
	movs r0, 0x1
	b _0805ADE8
_0805ADE6:
	movs r0, 0
_0805ADE8:
	cmp r0, 0
	bne _0805AE0C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x2
	mov r3, r9
	adds r3, 0x4
	bl sub_807D148
	movs r0, 0x1
	mov r10, r0
	mov r1, r8
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805AE0C
	mov r0, r10
	strb r0, [r1]
_0805AE0C:
	adds r6, 0x1
_0805AE0E:
	ldr r1, [sp]
	cmp r6, r1
	blt _0805ADA0
	mov r0, r10
	cmp r0, 0
	bne _0805AE26
	ldr r0, _0805AE38
	ldr r2, [r0]
	adds r0, r5, 0
	mov r1, r9
	bl sub_80522F4
_0805AE26:
	mov r0, r10
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AE38: .4byte gUnknown_81004EC
	thumb_func_end sub_805AD54

	thumb_func_start sub_805AE3C
sub_805AE3C:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r4, r3, 0
	bl sub_807A9D8
	movs r3, 0x80
	lsls r3, 2
	str r4, [sp]
	adds r0, r5, 0
	adds r1, r6, 0
	mov r2, r8
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805AE3C

	thumb_func_start sub_805AE74
sub_805AE74:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805AEB8
	movs r7, 0x1
	ldr r0, _0805AEC4
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805AEB8
	ldr r0, _0805AEC8
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_8076F80
_0805AEB8:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AEC4: .4byte gUnknown_80F4DDA
_0805AEC8: .4byte gUnknown_8106A4C
	thumb_func_end sub_805AE74

	thumb_func_start sub_805AECC
sub_805AECC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	adds r7, r1, 0
	adds r5, r2, 0
	adds r4, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r6, 0
	bl sub_807A9D8
	movs r3, 0x80
	lsls r3, 1
	str r4, [sp]
	adds r0, r6, 0
	adds r1, r7, 0
	adds r2, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805AF1E
	movs r1, 0x1
	mov r8, r1
	ldr r0, _0805AF2C
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805AF1E
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	movs r3, 0
	bl sub_8076210
_0805AF1E:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805AF2C: .4byte gUnknown_80F4DFE
	thumb_func_end sub_805AECC

	thumb_func_start sub_805AF30
sub_805AF30:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r4, r3, 0
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r1, r0, 0
	cmp r0, 0x9
	bgt _0805AF54
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x78
	b _0805AF92
_0805AF54:
	cmp r0, 0x1D
	bgt _0805AF78
	ldr r0, [r5, 0x70]
	movs r1, 0x10
	ldrsh r2, [r0, r1]
	cmp r2, 0
	bge _0805AF64
	adds r2, 0x3
_0805AF64:
	asrs r2, 2
	movs r0, 0x1
	str r0, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	movs r3, 0
	bl HealTargetHP
	movs r0, 0x1
	b _0805AF9C
_0805AF78:
	cmp r1, 0x3B
	bgt _0805AF88
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x50
	b _0805AF92
_0805AF88:
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0x28
_0805AF92:
	bl sub_8055864
	negs r1, r0
	orrs r1, r0
	lsrs r0, r1, 31
_0805AF9C:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805AF30

	thumb_func_start sub_805AFA4
sub_805AFA4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	adds r6, r3, 0
	bl sub_807A9D8
	ldr r3, [r4, 0x70]
	movs r0, 0x10
	ldrsh r2, [r3, r0]
	adds r0, r2, 0
	cmp r2, 0
	bge _0805AFC6
	adds r0, r2, 0x3
_0805AFC6:
	movs r7, 0xE
	ldrsh r1, [r3, r7]
	asrs r0, 2
	cmp r1, r0
	bgt _0805AFD4
	movs r2, 0
	b _0805AFFA
_0805AFD4:
	movs r0, 0xE
	ldrsh r1, [r3, r0]
	lsrs r0, r2, 31
	adds r0, r2, r0
	asrs r0, 1
	cmp r1, r0
	bgt _0805AFE6
	movs r2, 0x1
	b _0805AFFA
_0805AFE6:
	lsls r0, r2, 1
	adds r0, r2
	cmp r0, 0
	bge _0805AFF0
	adds r0, 0x3
_0805AFF0:
	asrs r0, 2
	movs r2, 0x3
	cmp r1, r0
	bgt _0805AFFA
	movs r2, 0x2
_0805AFFA:
	ldr r1, _0805B024
	lsls r0, r2, 2
	adds r0, r1
	ldr r3, [r0]
	str r6, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, r8
	bl sub_8055640
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B024: .4byte gUnknown_80F51C4
	thumb_func_end sub_805AFA4

	thumb_func_start sub_805B028
sub_805B028:
	push {lr}
	movs r2, 0x1
	bl sub_8077780
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B028

	thumb_func_start TransformMoveAction
TransformMoveAction:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	bl IsBossBattle
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805B05A
	strb r0, [r4, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8078E18
	movs r0, 0x1
	b _0805B068
_0805B05A:
	ldr r0, _0805B070
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0
_0805B068:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B070: .4byte gUnknown_80FEFF4
	thumb_func_end TransformMoveAction

	thumb_func_start sub_805B074
sub_805B074:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805B0AE
	movs r7, 0x1
	ldr r0, _0805B0B8
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805B0AE
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80763F8
_0805B0AE:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B0B8: .4byte gUnknown_80F4DC6
	thumb_func_end sub_805B074

	thumb_func_start sub_805B0BC
sub_805B0BC:
	push {lr}
	ldr r2, [r0, 0x70]
	adds r2, 0x46
	ldrb r2, [r2]
	bl sub_807CD9C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B0BC

	thumb_func_start sub_805B0D0
sub_805B0D0:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r5, r1, 0
	ldr r4, [r5, 0x70]
	ldr r1, _0805B134
	ldr r0, _0805B138
	ldr r0, [r0]
	ldr r2, _0805B13C
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r6, [r0]
	adds r0, r5, 0
	movs r1, 0x25
	bl HasAbility
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0805B14C
	adds r0, r4, 0
	adds r0, 0x5C
	strb r6, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r1, r4, 0
	adds r1, 0xF6
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0805B140
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r6, 0
	bl GetUnformattedTypeString
	adds r1, r0, 0
	ldr r0, _0805B144
	bl strcpy
	ldr r0, _0805B148
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0x1
	b _0805B15A
	.align 2, 0
_0805B134: .4byte gDungeonCamouflageTypes
_0805B138: .4byte gDungeonGlobalData
_0805B13C: .4byte 0x00003a0e
_0805B140: .4byte gUnknown_202DFE8
_0805B144: .4byte gUnknown_202DE58
_0805B148: .4byte gUnknown_80FEB08
_0805B14C:
	ldr r0, _0805B160
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0
_0805B15A:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B160: .4byte gPtrForecastPreventsTypeSwitchMessage
	thumb_func_end sub_805B0D0

	thumb_func_start sub_805B164
sub_805B164:
	push {lr}
	ldr r2, _0805B178
	ldr r2, [r2]
	movs r3, 0x2
	bl sub_8077084
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805B178: .4byte gUnknown_8106A50
	thumb_func_end sub_805B164

	thumb_func_start sub_805B17C
sub_805B17C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	mov r8, r3
	movs r0, 0
	mov r9, r0
	ldrh r1, [r7, 0x2]
	ldr r0, _0805B1A8
	cmp r1, r0
	bne _0805B1AC
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_807A9D8
	movs r6, 0x9E
	lsls r6, 1
	b _0805B1BA
	.align 2, 0
_0805B1A8: .4byte 0x00000123
_0805B1AC:
	movs r6, 0x75
	cmp r1, 0x45
	beq _0805B1BA
	movs r6, 0xF1
	cmp r1, 0x7D
	bne _0805B1BA
	movs r6, 0x7E
_0805B1BA:
	movs r3, 0x80
	lsls r3, 1
	mov r1, r8
	str r1, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r7, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805B1F4
	movs r0, 0x1
	mov r9, r0
	ldr r0, _0805B204
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805B1F4
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	movs r3, 0
	bl sub_80768DC
_0805B1F4:
	mov r0, r9
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B204: .4byte gUnknown_80F4E08
	thumb_func_end sub_805B17C

	thumb_func_start sub_805B208
sub_805B208:
	push {lr}
	bl sub_80788E8
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B208

	thumb_func_start sub_805B214
sub_805B214:
	push {lr}
	bl sub_8076B48
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B214

	thumb_func_start TrapperOrbAction
TrapperOrbAction:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r6, 0
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x6]
	movs r2, 0x1
	cmp r0, 0
	beq _0805B234
	movs r2, 0x2
_0805B234:
	adds r0, r4, 0x4
	movs r1, 0x13
	bl sub_807FCD4
	lsls r0, 24
	cmp r0, 0
	beq _0805B246
	movs r6, 0x1
	b _0805B252
_0805B246:
	ldr r0, _0805B260
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_0805B252:
	bl sub_8049ED4
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B260: .4byte gUnknown_80FC5A8
	thumb_func_end TrapperOrbAction

	thumb_func_start sub_805B264
sub_805B264:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r0
	adds r7, r1, 0
	mov r9, r2
	mov r12, r3
	ldr r4, [r7, 0x70]
	ldr r0, _0805B2D0
	ldr r3, [r0]
	movs r6, 0
	ldr r0, _0805B2D4
	ldr r1, [r0]
	movs r0, 0xC1
	lsls r0, 9
	adds r5, r1, r0
	ldr r2, _0805B2D8
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	str r0, [r5]
	ldr r0, _0805B2DC
	adds r1, r0
	str r6, [r1]
	ldr r0, _0805B2E0
	lsls r3, 1
	adds r3, r0
	movs r0, 0
	ldrsh r3, [r3, r0]
	adds r4, 0xC0
	ldrb r0, [r4]
	cmp r0, 0xA
	bne _0805B2AC
	lsls r3, 1
_0805B2AC:
	mov r0, r12
	str r0, [sp]
	mov r0, r8
	adds r1, r7, 0
	mov r2, r9
	bl sub_8055864
	negs r1, r0
	orrs r1, r0
	lsrs r6, r1, 31
	adds r0, r6, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B2D0: .4byte gUnknown_202F224
_0805B2D4: .4byte gDungeonGlobalData
_0805B2D8: .4byte gUnknown_8106A8C
_0805B2DC: .4byte 0x00018204
_0805B2E0: .4byte gUnknown_80F4F94
	thumb_func_end sub_805B264

	thumb_func_start sub_805B2E4
sub_805B2E4:
	push {lr}
	bl sub_80799A8
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B2E4

	thumb_func_start sub_805B2F0
sub_805B2F0:
	push {lr}
	bl sub_8079B1C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B2F0

	thumb_func_start sub_805B2FC
sub_805B2FC:
	push {lr}
	ldr r2, _0805B310
	ldr r2, [r2]
	movs r3, 0x1
	bl sub_8077160
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805B310: .4byte gUnknown_8106A4C
	thumb_func_end sub_805B2FC

	thumb_func_start sub_805B314
sub_805B314:
	push {lr}
	movs r2, 0x1
	bl sub_80783C4
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B314

	thumb_func_start sub_805B324
sub_805B324:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805B368
	movs r7, 0x1
	ldr r0, _0805B374
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805B368
	ldr r0, _0805B378
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_8076E20
_0805B368:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B374: .4byte gUnknown_80F4DD8
_0805B378: .4byte gUnknown_8106A50
	thumb_func_end sub_805B324

	thumb_func_start sub_805B37C
sub_805B37C:
	push {lr}
	bl sub_80780E4
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B37C

	thumb_func_start sub_805B388
sub_805B388:
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805B39E
	movs r0, 0x1
_0805B39E:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_805B388

	thumb_func_start sub_805B3A8
sub_805B3A8:
	push {lr}
	bl sub_8079BA8
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B3A8

	thumb_func_start sub_805B3B4
sub_805B3B4:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r0, _0805B3DC
	ldr r4, [r0]
	adds r0, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077084
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_8077160
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B3DC: .4byte gUnknown_8106A50
	thumb_func_end sub_805B3B4

	thumb_func_start sub_805B3E0
sub_805B3E0:
	push {r4,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	movs r0, 0x1
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_805B3E0

	thumb_func_start sub_805B3FC
sub_805B3FC:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r3, 0
	ldr r0, [sp, 0x18]
	movs r6, 0
	movs r3, 0x80
	lsls r3, 1
	str r0, [sp]
	adds r0, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805B446
	movs r6, 0x1
	ldr r0, _0805B450
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r5, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805B446
	ldr r4, [r5, 0x70]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r7, 0
	movs r3, 0x1
	bl sub_8077084
	adds r4, 0xFB
	ldrb r0, [r4]
	cmp r0, 0
	bne _0805B446
	strb r6, [r4]
_0805B446:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B450: .4byte gUnknown_80F4DCE
	thumb_func_end sub_805B3FC

	thumb_func_start sub_805B454
sub_805B454:
	push {lr}
	movs r2, 0x1
	bl sub_807614C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B454

	thumb_func_start MimicMoveAction
MimicMoveAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	mov r9, r1
	movs r0, 0
	str r0, [sp]
	ldr r1, [r6, 0x70]
	mov r8, r1
	mov r1, r9
	ldr r0, [r1, 0x70]
	movs r5, 0
	ldr r1, _0805B50C
	mov r10, r1
	subs r1, 0x2F
	adds r4, r0, r1
	movs r7, 0x3
_0805B48C:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805B4D4
	ldrh r1, [r4, 0x2]
	adds r0, r6, 0
	bl sub_805755C
	lsls r0, 24
	cmp r0, 0
	bne _0805B4D4
	ldrh r2, [r4, 0x2]
	adds r0, r2, 0
	cmp r0, r10
	beq _0805B4D4
	cmp r0, 0xE5
	beq _0805B4D4
	cmp r0, 0x8A
	beq _0805B4D4
	cmp r0, 0x28
	beq _0805B4D4
	cmp r0, 0x11
	beq _0805B4D4
	ldrb r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0805B4D4
	lsls r1, r5, 1
	movs r0, 0xBD
	lsls r0, 1
	add r0, r8
	adds r0, r1
	strh r2, [r0]
	adds r5, 0x1
_0805B4D4:
	adds r4, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _0805B48C
	ldr r0, _0805B510
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	cmp r5, 0
	beq _0805B518
	mov r1, r8
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805B4F8
	movs r0, 0x1
	strb r0, [r1]
_0805B4F8:
	ldr r0, _0805B514
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
	movs r0, 0x1
	str r0, [sp]
	b _0805B524
	.align 2, 0
_0805B50C: .4byte 0x00000147
_0805B510: .4byte gAvailablePokemonNames
_0805B514: .4byte gUnknown_80FDCE4
_0805B518:
	ldr r0, _0805B538
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
_0805B524:
	ldr r0, [sp]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B538: .4byte gUnknown_80FDD00
	thumb_func_end MimicMoveAction

	thumb_func_start sub_805B53C
sub_805B53C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r10, r0
	mov r9, r1
	adds r6, r2, 0
	mov r8, r3
	movs r0, 0
	add r1, sp, 0x18
	strb r0, [r1]
	mov r0, r10
	ldr r1, [r0, 0x70]
	movs r5, 0x1
	movs r2, 0
	ldr r4, _0805B580
	movs r3, 0
	ldrsh r0, [r4, r3]
	cmp r0, 0
	blt _0805B598
	movs r7, 0xC
	ldrsh r3, [r1, r7]
	adds r1, r4, 0
	ldr r4, _0805B584
_0805B570:
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r3, r0
	bge _0805B588
	movs r0, 0x2
	ldrsh r5, [r1, r0]
	b _0805B598
	.align 2, 0
_0805B580: .4byte gUnknown_80F55EC
_0805B584: .4byte 0x000003e6
_0805B588:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, r4
	bgt _0805B598
	movs r7, 0
	ldrsh r0, [r1, r7]
	cmp r0, 0
	bge _0805B570
_0805B598:
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r1, 0
	str r1, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	mov r0, r10
	mov r1, r9
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805B5DC
	movs r2, 0x1
_0805B5DC:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805B53C

	thumb_func_start sub_805B5F4
sub_805B5F4:
	push {r4,lr}
	adds r4, r0, 0
	movs r2, 0x1
	bl sub_8077F40
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805B60E
	movs r0, 0x1
	strb r0, [r1]
_0805B60E:
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_805B5F4

	thumb_func_start sub_805B618
sub_805B618:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	adds r6, r0, 0
	mov r8, r1
	mov r9, r3
	ldr r0, _0805B660
	ldr r4, [r0]
	ldr r5, _0805B664
	lsls r4, 3
	adds r0, r4, r5
	ldrh r1, [r0]
	mov r0, sp
	bl InitPokemonMove
	adds r5, 0x4
	adds r4, r5
	ldr r4, [r4]
	adds r0, r6, 0
	mov r1, r8
	mov r2, sp
	mov r3, r9
	bl _call_via_r4
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B660: .4byte gUnknown_202F228
_0805B664: .4byte gUnknown_80F59C8
	thumb_func_end sub_805B618

	thumb_func_start sub_805B668
sub_805B668:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0x3A
	bl HasAbility
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r4, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	beq _0805B712
	movs r3, 0x80
	lsls r3, 1
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_8055640
	adds r1, r0, 0
	cmp r1, 0
	beq _0805B71E
	movs r0, 0x1
	mov r8, r0
	lsrs r0, r1, 31
	adds r0, r1, r0
	asrs r4, r0, 1
	cmp r4, 0
	bgt _0805B6BE
	movs r4, 0x1
_0805B6BE:
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _0805B71E
	ldr r0, [r5, 0x70]
	adds r1, r0, 0
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805B6DC
	mov r0, r8
	strb r0, [r1]
_0805B6DC:
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _0805B71E
	mov r0, r9
	cmp r0, 0
	beq _0805B700
	movs r3, 0xFD
	lsls r3, 1
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0xD
	bl sub_806F324
	b _0805B71E
_0805B700:
	mov r0, r8
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0
	bl HealTargetHP
	b _0805B71E
_0805B712:
	ldr r0, _0805B730
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_0805B71E:
	mov r0, r8
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B730: .4byte gPtrSleepingTargetOnlyMessage
	thumb_func_end sub_805B668

	thumb_func_start sub_805B734
sub_805B734:
	push {lr}
	bl sub_8078678
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B734

	thumb_func_start sub_805B740
sub_805B740:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r9, r0
	adds r6, r1, 0
	ldr r5, [r6, 0x70]
	movs r7, 0
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _0805B7C2
	movs r4, 0
	movs r0, 0x60
	adds r0, r5
	mov r8, r0
_0805B75E:
	lsls r1, r4, 2
	ldr r0, _0805B7D4
	ldr r0, [r0]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805B790
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0805B790
	ldrb r0, [r2, 0x2]
	cmp r0, 0x7C
	bne _0805B790
	ldrb r1, [r2, 0x1]
	adds r1, 0x7D
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
	movs r7, 0x1
_0805B790:
	adds r4, 0x1
	cmp r4, 0x13
	ble _0805B75E
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805B7C2
	adds r0, r5, 0
	adds r0, 0x62
	ldrb r0, [r0]
	cmp r0, 0x7C
	bne _0805B7C2
	adds r0, r5, 0
	adds r0, 0x61
	ldrb r1, [r0]
	adds r1, 0x7D
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
	movs r7, 0x1
_0805B7C2:
	cmp r7, 0
	beq _0805B7DC
	ldr r0, _0805B7D8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
	b _0805B7E8
	.align 2, 0
_0805B7D4: .4byte gTeamInventory_203B460
_0805B7D8: .4byte gUnknown_80FDC9C
_0805B7DC:
	ldr r0, _0805B7F8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r6, 0
	bl sub_80522F4
_0805B7E8:
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B7F8: .4byte gUnknown_80FDCA0
	thumb_func_end sub_805B740

	thumb_func_start sub_805B7FC
sub_805B7FC:
	push {lr}
	bl sub_8079AA0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805B7FC

	thumb_func_start sub_805B808
sub_805B808:
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x1C
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r1, _0805B880
	movs r3, 0
	ldrsh r2, [r1, r3]
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r5, [sp, 0x14]
	mov r0, r9
	mov r1, r10
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805B868
	movs r2, 0x1
_0805B868:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B880: .4byte gUnknown_80F4F7E
	thumb_func_end sub_805B808

	thumb_func_start sub_805B884
sub_805B884:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, _0805B8AC
	ldr r2, [r0]
	adds r0, r4, 0
	movs r3, 0x1
	bl sub_8077084
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8077910
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805B8AC: .4byte gUnknown_8106A4C
	thumb_func_end sub_805B884

	thumb_func_start SkullBashMoveAction
SkullBashMoveAction:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r7, r1, 0
	adds r4, r2, 0
	adds r6, r3, 0
	adds r1, r4, 0
	bl MoveMatchesChargingStatus
	lsls r0, 24
	cmp r0, 0
	beq _0805B8EC
	ldr r0, _0805B8E8
	ldr r3, [r0]
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8055640
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	adds r0, r5, 0
	bl sub_8079764
	b _0805B900
	.align 2, 0
_0805B8E8: .4byte gUnknown_80F4F58
_0805B8EC:
	ldr r0, _0805B90C
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	movs r2, 0x6
	adds r3, r4, 0
	bl sub_8079618
	movs r4, 0x1
_0805B900:
	adds r0, r4, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B90C: .4byte gUnknown_80FAFF0
	thumb_func_end SkullBashMoveAction

	thumb_func_start sub_805B910
sub_805B910:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r6, r1, 0
	movs r7, 0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805B954
	movs r7, 0x1
	ldr r0, _0805B960
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805B954
	ldr r0, _0805B964
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r3, 0x1
	bl sub_8076F80
_0805B954:
	adds r0, r7, 0
	add sp, 0x8
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B960: .4byte gUnknown_80F4DDC
_0805B964: .4byte gUnknown_8106A50
	thumb_func_end sub_805B910

	thumb_func_start sub_805B968
sub_805B968:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	adds r5, r0, 0
	adds r6, r2, 0
	adds r7, r3, 0
	movs r0, 0
	mov r8, r0
	movs r3, 0x80
	lsls r3, 1
	str r7, [sp]
	adds r0, r5, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805B9D8
	movs r1, 0x1
	mov r8, r1
	adds r0, r5, 0
	movs r1, 0
	bl sub_8057308
	lsls r0, 24
	cmp r0, 0
	beq _0805B9D8
	ldr r0, [r5, 0x70]
	movs r1, 0x10
	ldrsh r2, [r0, r1]
	cmp r2, 0
	bge _0805B9A8
	adds r2, 0x3
_0805B9A8:
	asrs r4, r2, 2
	cmp r4, 0
	bgt _0805B9B0
	movs r4, 0x1
_0805B9B0:
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	mov r0, r8
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_806F370
_0805B9D8:
	mov r0, r8
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805B968

	thumb_func_start sub_805B9E8
sub_805B9E8:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r6, 0
	mov r0, sp
	bl sub_8069D18
	lsls r0, 24
	cmp r0, 0
	beq _0805BA08
	ldr r0, _0805BA04
	b _0805BA18
	.align 2, 0
_0805BA04: .4byte gUnknown_80FD430
_0805BA08:
	mov r0, sp
	bl sub_804AD34
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	beq _0805BA28
	ldr r0, _0805BA24
_0805BA18:
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _0805BA34
	.align 2, 0
_0805BA24: .4byte gUnknown_80FD3F0
_0805BA28:
	ldr r0, _0805BA40
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_0805BA34:
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805BA40: .4byte gUnknown_80FD40C
	thumb_func_end sub_805B9E8

	thumb_func_start sub_805BA44
sub_805BA44:
	push {lr}
	bl sub_807D3CC
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BA44

	thumb_func_start sub_805BA50
sub_805BA50:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r6, r0, 0
	adds r5, r1, 0
	movs r0, 0
	mov r9, r0
	movs r4, 0x80
	lsls r4, 1
	str r3, [sp]
	adds r0, r6, 0
	adds r3, r4, 0
	bl sub_8055640
	cmp r0, 0
	beq _0805BB4C
	movs r1, 0x1
	mov r9, r1
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _0805BB4C
	ldr r0, [r6, 0x70]
	mov r8, r0
	mov r10, r8
	ldr r7, [r5, 0x70]
	str r7, [sp, 0x4]
	ldr r4, _0805BAC0
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r5, 0
	movs r1, 0x2C
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0805BAC4
	movs r0, 0x1
	b _0805BB4E
	.align 2, 0
_0805BAC0: .4byte gAvailablePokemonNames
_0805BAC4:
	adds r0, r5, 0
	movs r1, 0x24
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0805BADC
	ldr r0, _0805BAD8
	b _0805BB04
	.align 2, 0
_0805BAD8: .4byte gUnknown_80FD574
_0805BADC:
	mov r0, r8
	adds r0, 0x60
	adds r3, r7, 0
	adds r3, 0x60
	ldrb r0, [r0]
	mov r2, r9
	ands r2, r0
	cmp r2, 0
	beq _0805BAF8
	ldr r0, _0805BAF4
	b _0805BB04
	.align 2, 0
_0805BAF4: .4byte gUnknown_80FC654
_0805BAF8:
	ldrb r1, [r3]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _0805BB18
	ldr r0, _0805BB14
_0805BB04:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	movs r0, 0x1
	b _0805BB4E
	.align 2, 0
_0805BB14: .4byte gUnknown_80FC678
_0805BB18:
	ldr r1, [sp, 0x4]
	ldr r0, [r1, 0x60]
	mov r1, r10
	str r0, [r1, 0x60]
	strb r2, [r3, 0x2]
	strb r2, [r3, 0x1]
	strb r2, [r3]
	adds r0, r6, 0
	bl sub_806A6E8
	adds r0, r5, 0
	bl sub_806A6E8
	mov r1, r10
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805BB40
	mov r0, r9
	strb r0, [r1]
_0805BB40:
	ldr r0, _0805BB60
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
_0805BB4C:
	mov r0, r9
_0805BB4E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805BB60: .4byte gUnknown_80FC614
	thumb_func_end sub_805BA50

	thumb_func_start sub_805BB64
sub_805BB64:
	push {lr}
	movs r2, 0xA
	bl sub_80797A0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BB64

	thumb_func_start sub_805BB74
sub_805BB74:
	push {lr}
	adds r3, r0, 0
	ldr r0, [r3, 0x70]
	adds r2, r0, 0
	adds r2, 0xFB
	ldrb r0, [r2]
	cmp r0, 0
	bne _0805BB88
	movs r0, 0x1
	strb r0, [r2]
_0805BB88:
	adds r0, r3, 0
	movs r2, 0x1
	bl sub_807E254
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BB74

	thumb_func_start sub_805BB98
sub_805BB98:
	push {lr}
	movs r2, 0x1
	movs r3, 0
	bl sub_807D148
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BB98

	thumb_func_start CleanseOrbAction
CleanseOrbAction:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, 0
	ldr r0, [r6, 0x70]
	movs r7, 0
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0805BC30
	movs r5, 0
	ldr r3, _0805BC44
_0805BBC0:
	lsls r1, r5, 2
	ldr r0, [r3]
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0805BBE8
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _0805BBE8
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0805BBE8
	movs r0, 0xF7
	ands r0, r2
	strb r0, [r1]
	movs r7, 0x1
_0805BBE8:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0805BBC0
	movs r5, 0
_0805BBF0:
	ldr r0, _0805BC48
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0805BC4C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805BC2A
	ldr r0, [r4, 0x70]
	adds r2, r0, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805BC2A
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0805BC2A
	movs r0, 0xF7
	ands r0, r1
	strb r0, [r2]
	movs r7, 0x1
_0805BC2A:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0805BBF0
_0805BC30:
	cmp r7, 0
	beq _0805BC54
	ldr r0, _0805BC50
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	b _0805BC60
	.align 2, 0
_0805BC44: .4byte gTeamInventory_203B460
_0805BC48: .4byte gDungeonGlobalData
_0805BC4C: .4byte 0x0001357c
_0805BC50: .4byte gUnknown_80FC8F0
_0805BC54:
	ldr r0, _0805BC6C
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
_0805BC60:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805BC6C: .4byte gUnknown_80FC920
	thumb_func_end CleanseOrbAction

	thumb_func_start sub_805BC70
sub_805BC70:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _0805BC94
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_808417C
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8075C58
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805BC94: .4byte gUnknown_80F4E74
	thumb_func_end sub_805BC70

	thumb_func_start sub_805BC98
sub_805BC98:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	adds r6, r0, 0
	mov r8, r1
	mov r10, r2
	str r3, [sp, 0x1C]
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	mov r7, sp
	adds r7, 0x19
	strb r5, [r7]
	ldr r0, [r6, 0x70]
	mov r9, r0
	ldr r0, [r1, 0x70]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	subs r4, r0, 0x1
	cmp r4, 0
	bge _0805BCCA
	movs r4, 0
_0805BCCA:
	mov r0, r10
	ldr r1, [sp, 0x1C]
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	add r2, sp, 0x18
	str r2, [sp]
	str r5, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	str r5, [sp, 0x10]
	str r5, [sp, 0x14]
	adds r0, r6, 0
	mov r1, r8
	adds r2, r4, 0
	movs r3, 0
	bl sub_806F370
	mov r1, r9
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r4, r0, 1
	cmp r4, 0
	bge _0805BD02
	movs r4, 0
_0805BD02:
	mov r0, r10
	ldr r1, [sp, 0x1C]
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	str r7, [sp]
	str r5, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	str r5, [sp, 0x10]
	str r5, [sp, 0x14]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805BD34
	movs r2, 0x1
_0805BD34:
	strb r2, [r1]
	movs r1, 0
	ldrb r0, [r7]
	cmp r0, 0
	bne _0805BD40
	movs r1, 0x1
_0805BD40:
	strb r1, [r7]
	movs r2, 0
	add r0, sp, 0x18
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805BD50
	cmp r1, 0
	beq _0805BD52
_0805BD50:
	movs r2, 0x1
_0805BD52:
	adds r0, r2, 0
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805BC98

	thumb_func_start sub_805BD64
sub_805BD64:
	push {lr}
	bl sub_8078D8C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BD64

	thumb_func_start sub_805BD70
sub_805BD70:
	push {lr}
	bl sub_8077DDC
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BD70

	thumb_func_start sub_805BD7C
sub_805BD7C:
	push {lr}
	bl sub_8077ED0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BD7C

	thumb_func_start TransferOrbAction
TransferOrbAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r10, r0
	adds r7, r1, 0
	movs r0, 0
	str r0, [sp]
	ldr r1, [r7, 0x70]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0805BE60
	mov r9, r1
	movs r2, 0x2
	ldrsh r5, [r1, r2]
	mov r8, r5
	ldr r0, _0805BDD0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	mov r0, r9
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805BDD8
	ldr r0, _0805BDD4
	ldr r2, [r0]
	mov r0, r10
	adds r1, r7, 0
	bl sub_80522F4
	movs r0, 0
	b _0805BE78
	.align 2, 0
_0805BDD0: .4byte gAvailablePokemonNames
_0805BDD4: .4byte gUnknown_80FD450
_0805BDD8:
	movs r6, 0
	b _0805BDDE
_0805BDDC:
	adds r6, 0x1
_0805BDDE:
	cmp r6, 0x1D
	bgt _0805BE14
	movs r0, 0
	bl sub_803D970
	lsls r0, 16
	asrs r5, r0, 16
	adds r0, r5, 0
	movs r1, 0
	bl sub_806AA0C
	lsls r0, 24
	cmp r0, 0
	beq _0805BDDC
	cmp r8, r5
	beq _0805BDDC
	mov r0, r8
	bl GetPokemonSize
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetPokemonSize
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _0805BDDC
_0805BE14:
	cmp r6, 0x1E
	beq _0805BE22
	mov r1, r9
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	cmp r0, r5
	bne _0805BE34
_0805BE22:
	ldr r0, _0805BE30
	ldr r2, [r0]
	mov r0, r10
	adds r1, r7, 0
	bl sub_80522F4
	b _0805BE76
	.align 2, 0
_0805BE30: .4byte gUnknown_80FD450
_0805BE34:
	ldr r0, _0805BE58
	adds r1, r5, 0
	bl CopyCyanSpeciesNametoBuffer
	ldr r0, _0805BE5C
	ldr r2, [r0]
	mov r0, r10
	adds r1, r7, 0
	bl sub_80522F4
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_806BB6C
	movs r0, 0x1
	str r0, [sp]
	b _0805BE76
	.align 2, 0
_0805BE58: .4byte gUnknown_202DFE8
_0805BE5C: .4byte gUnknown_80FD434
_0805BE60:
	ldr r0, _0805BE88
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0805BE8C
	ldr r2, [r0]
	mov r0, r10
	adds r1, r7, 0
	bl sub_80522F4
_0805BE76:
	ldr r0, [sp]
_0805BE78:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805BE88: .4byte gAvailablePokemonNames
_0805BE8C: .4byte gUnknown_80FD450
	thumb_func_end TransferOrbAction

	thumb_func_start sub_805BE90
sub_805BE90:
	push {lr}
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80779F0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BE90

	thumb_func_start LuminousOrbAction
LuminousOrbAction:
	push {lr}
	bl HandleLuminousOrbAction
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end LuminousOrbAction

	thumb_func_start sub_805BEAC
sub_805BEAC:
	push {lr}
	bl sub_8076D10
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BEAC

	thumb_func_start sub_805BEB8
sub_805BEB8:
	push {lr}
	movs r2, 0x8
	bl sub_807DA14
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BEB8

	thumb_func_start sub_805BEC8
sub_805BEC8:
	push {lr}
	bl sub_807D510
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BEC8

	thumb_func_start EscapeOrbAction
EscapeOrbAction:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, _0805BF00
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r5, _0805BF04
	ldr r0, [r5]
	ldr r1, _0805BF08
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805BF10
	ldr r0, _0805BF0C
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80522F4
	b _0805BF26
	.align 2, 0
_0805BF00: .4byte gAvailablePokemonNames
_0805BF04: .4byte gDungeonGlobalData
_0805BF08: .4byte 0x0000066e
_0805BF0C: .4byte gUnknown_80FD4DC
_0805BF10:
	ldr r0, _0805BF30
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_80522F4
	ldr r0, [r5]
	movs r1, 0x1
	strb r1, [r0, 0x4]
	ldr r0, [r5]
	strb r1, [r0, 0x11]
_0805BF26:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805BF30: .4byte gUnknown_80FD4C4
	thumb_func_end EscapeOrbAction

	thumb_func_start sub_805BF34
sub_805BF34:
	push {lr}
	bl sub_807DB74
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BF34

	thumb_func_start TrapbustOrbAction
TrapbustOrbAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0x10]
	adds r0, r1, 0
	bl GetMapTileForDungeonEntity_2
	adds r4, r0, 0
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _0805BF78
	ldr r0, _0805BF74
	ldr r1, [r0]
	ldr r0, [sp, 0x4]
	bl SendMessage
	movs r0, 0
	b _0805C06A
	.align 2, 0
_0805BF74: .4byte gUnknown_80FD1EC
_0805BF78:
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	bne _0805BFAC
	ldr r2, [sp, 0x8]
	movs r3, 0x4
	ldrsh r1, [r2, r3]
	ldr r0, _0805BFA4
	ldr r0, [r0]
	ldr r4, _0805BFA8
	adds r0, r4
	ldrb r0, [r0]
	subs r2, r1, r0
	ldr r3, [sp, 0x8]
	movs r4, 0x6
	ldrsh r1, [r3, r4]
	subs r1, r0
	str r1, [sp, 0xC]
	adds r1, r2, r0
	mov r10, r1
	ldr r3, [sp, 0xC]
	adds r7, r3, r0
	b _0805BFDA
	.align 2, 0
_0805BFA4: .4byte gDungeonGlobalData
_0805BFA8: .4byte 0x00018209
_0805BFAC:
	ldr r2, _0805C050
	ldrb r1, [r4, 0x9]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r4, _0805C054
	adds r0, r4
	ldr r1, [r2]
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r2, r0, 0x1
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	subs r0, 0x1
	str r0, [sp, 0xC]
	movs r4, 0x6
	ldrsh r0, [r1, r4]
	adds r0, 0x1
	mov r10, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	adds r7, r0, 0x1
_0805BFDA:
	adds r6, r2, 0
	cmp r6, r10
	bgt _0805C034
_0805BFE0:
	ldr r5, [sp, 0xC]
	adds r4, r6, 0x1
	mov r9, r4
	cmp r5, r7
	bgt _0805C02E
	lsls r0, r6, 16
	lsrs r0, 16
	mov r8, r0
_0805BFF0:
	adds r0, r6, 0
	adds r1, r5, 0
	bl GetMapTile_2
	ldr r4, [r0, 0x14]
	cmp r4, 0
	beq _0805C028
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _0805C028
	adds r0, r4, 0
	bl GetTrapData
	ldrb r0, [r0]
	cmp r0, 0x11
	beq _0805C028
	lsls r0, r5, 16
	mov r1, r8
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	movs r1, 0
	bl sub_807FE04
	movs r2, 0x1
	str r2, [sp, 0x10]
_0805C028:
	adds r5, 0x1
	cmp r5, r7
	ble _0805BFF0
_0805C02E:
	mov r6, r9
	cmp r6, r10
	ble _0805BFE0
_0805C034:
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _0805C05C
	ldr r0, _0805C058
	ldr r2, [r0]
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x8]
	bl sub_80522F4
	bl sub_8040A84
	bl sub_8049ED4
	b _0805C068
	.align 2, 0
_0805C050: .4byte gDungeonGlobalData
_0805C054: .4byte 0x000104c4
_0805C058: .4byte gUnknown_80FD1B0
_0805C05C:
	ldr r0, _0805C07C
	ldr r2, [r0]
	ldr r0, [sp, 0x4]
	ldr r1, [sp, 0x8]
	bl sub_80522F4
_0805C068:
	ldr r0, [sp, 0x10]
_0805C06A:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805C07C: .4byte gUnknown_80FD1CC
	thumb_func_end TrapbustOrbAction

	thumb_func_start sub_805C080
sub_805C080:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	mov r9, r1
	movs r0, 0
	mov r8, r0
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0805C0AC
	ldr r0, _0805C0A4
	ldr r0, [r0]
	ldr r1, _0805C0A8
	adds r0, r1
	movs r1, 0x10
	b _0805C0BA
	.align 2, 0
_0805C0A4: .4byte gDungeonGlobalData
_0805C0A8: .4byte 0x0001358c
_0805C0AC:
	ldr r0, _0805C11C
	ldr r0, [r0]
	ldr r1, _0805C120
	adds r0, r1
	movs r1, 0x4
	cmp r1, 0
	beq _0805C0FA
_0805C0BA:
	adds r6, r0, 0
	adds r7, r1, 0
_0805C0BE:
	ldr r4, [r6]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805C0F2
	cmp r5, r4
	beq _0805C0F2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0
	bl CanTarget
	lsls r0, 24
	cmp r0, 0
	bne _0805C0F2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x2
	adds r3, r5, 0x4
	bl sub_807D148
	movs r0, 0x1
	mov r8, r0
_0805C0F2:
	adds r6, 0x4
	subs r7, 0x1
	cmp r7, 0
	bne _0805C0BE
_0805C0FA:
	mov r1, r8
	cmp r1, 0
	bne _0805C10C
	ldr r0, _0805C124
	ldr r2, [r0]
	adds r0, r5, 0
	mov r1, r9
	bl sub_80522F4
_0805C10C:
	mov r0, r8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805C11C: .4byte gDungeonGlobalData
_0805C120: .4byte 0x0001357c
_0805C124: .4byte gUnknown_81004F0
	thumb_func_end sub_805C080

	thumb_func_start sub_805C128
sub_805C128:
	push {lr}
	adds r1, r0, 0
	bl sub_807885C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C128

	thumb_func_start sub_805C138
sub_805C138:
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x1C
	mov r9, r0
	mov r10, r1
	adds r6, r2, 0
	mov r8, r3
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	adds r0, r6, 0
	bl GetMoveType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	mov r1, r8
	bl sub_8057600
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0805C1AC
	add r1, sp, 0x18
	str r1, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r5, [sp, 0xC]
	movs r0, 0x1
	str r0, [sp, 0x10]
	str r5, [sp, 0x14]
	mov r0, r9
	mov r1, r10
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805C194
	movs r2, 0x1
_0805C194:
	strb r2, [r1]
	add r0, sp, 0x18
	ldrb r0, [r0]
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805C1AC: .4byte 0x0000270f
	thumb_func_end sub_805C138

	thumb_func_start sub_805C1B0
sub_805C1B0:
	push {lr}
	bl sub_80790C8
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C1B0

	thumb_func_start sub_805C1BC
sub_805C1BC:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r4, _0805C1E0
	movs r5, 0
	ldrsh r4, [r4, r5]
	str r3, [sp]
	adds r3, r4, 0
	bl sub_8055864
	adds r1, r0, 0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805C1E0: .4byte gUnknown_80F4F80
	thumb_func_end sub_805C1BC

	.align 2, 0
