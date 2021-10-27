	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8057A0C
sub_8057A0C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r2, [r5, 0x70]
	mov r8, r2
	ldr r0, [r6, 0x70]
	adds r3, r0, 0
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	movs r4, 0xE
	ldrsh r1, [r3, r4]
	adds r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	strh r0, [r2, 0xE]
	strh r0, [r3, 0xE]
	movs r7, 0xE
	ldrsh r1, [r2, r7]
	ldrh r4, [r2, 0x10]
	movs r7, 0x10
	ldrsh r0, [r2, r7]
	cmp r1, r0
	ble _08057A42
	strh r4, [r2, 0xE]
_08057A42:
	movs r0, 0xE
	ldrsh r1, [r3, r0]
	ldrh r2, [r3, 0x10]
	movs r4, 0x10
	ldrsh r0, [r3, r4]
	cmp r1, r0
	ble _08057A52
	strh r2, [r3, 0xE]
_08057A52:
	ldr r4, _08057A90
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	mov r1, r8
	adds r1, 0xFB
	ldrb r0, [r1]
	cmp r0, 0
	bne _08057A78
	movs r0, 0x1
	strb r0, [r1]
_08057A78:
	ldr r0, _08057A94
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80522F4
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057A90: .4byte gAvailablePokemonNames
_08057A94: .4byte gUnknown_80FC7EC
	thumb_func_end sub_8057A0C

	thumb_func_start TormentMoveAction
TormentMoveAction:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r10, r0
	mov r8, r1
	ldr r0, [r1, 0x70]
	str r0, [sp, 0x8]
	movs r1, 0
	str r1, [sp, 0xC]
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r0, r1
	adds r5, r4, 0
	movs r0, 0x10
	mov r9, r0
	movs r7, 0x3
_08057ABE:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08057B12
	movs r6, 0x20
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08057B04
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _08057B12
	ldr r0, _08057AFC
	adds r1, r5, 0
	movs r2, 0
	bl sub_80928C0
	ldr r0, _08057B00
	ldr r2, [r0]
	mov r0, r10
	mov r1, r8
	bl sub_80522F4
	ldrb r0, [r4]
	orrs r0, r6
	strb r0, [r4]
	movs r1, 0x1
	str r1, [sp, 0xC]
	b _08057B12
	.align 2, 0
_08057AFC: .4byte gUnknown_202DE58
_08057B00: .4byte gUnknown_80FCFBC
_08057B04:
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _08057B12
	movs r0, 0xDF
	ands r0, r1
	strb r0, [r4]
_08057B12:
	adds r4, 0x8
	adds r5, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _08057ABE
	ldr r0, [sp, 0x8]
	movs r1, 0x9C
	lsls r1, 1
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08057B6C
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08057B7A
	movs r1, 0xB0
	lsls r1, 1
	mov r0, sp
	bl sub_8092A88
	ldrb r1, [r4]
	movs r0, 0x20
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x1
	str r0, [sp, 0xC]
	ldr r0, _08057B64
	mov r1, sp
	movs r2, 0
	bl sub_80928C0
	ldr r0, _08057B68
	ldr r2, [r0]
	mov r0, r10
	mov r1, r8
	bl sub_80522F4
	b _08057B7A
	.align 2, 0
_08057B64: .4byte gUnknown_202DE58
_08057B68: .4byte gUnknown_80FCFBC
_08057B6C:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08057B7A
	movs r0, 0xDF
	ands r0, r1
	strb r0, [r4]
_08057B7A:
	ldr r1, [sp, 0xC]
	cmp r1, 0
	beq _08057B90
	ldr r1, [sp, 0x8]
	adds r1, 0xC0
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _08057B9C
	movs r0, 0
	strb r0, [r1]
	b _08057B9C
_08057B90:
	ldr r0, _08057BB0
	ldr r2, [r0]
	mov r0, r10
	mov r1, r8
	bl sub_80522F4
_08057B9C:
	ldr r0, [sp, 0xC]
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057BB0: .4byte gUnknown_80FCFE4
	thumb_func_end TormentMoveAction

	thumb_func_start sub_8057BB4
sub_8057BB4:
	push {lr}
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80779F0
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_8057BB4

	thumb_func_start sub_8057BC4
sub_8057BC4:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8077AE4
	ldr r0, _08057BE8
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	movs r3, 0x2
	bl sub_8077084
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08057BE8: .4byte gUnknown_8106A4C
	thumb_func_end sub_8057BC4

	thumb_func_start sub_8057BEC
sub_8057BEC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	adds r6, r3, 0
	movs r0, 0
	mov r8, r0
	adds r0, r4, 0
	bl sub_8070B28
	lsls r0, 24
	cmp r0, 0
	beq _08057C48
	movs r3, 0x80
	lsls r3, 1
	str r6, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r7, 0
	bl sub_8055640
	cmp r0, 0
	beq _08057C54
	movs r1, 0x1
	mov r8, r1
	ldr r0, _08057C44
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08057C54
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_80776C0
	b _08057C54
	.align 2, 0
_08057C44: .4byte gUnknown_80F4E0A
_08057C48:
	ldr r0, _08057C64
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80522F4
_08057C54:
	mov r0, r8
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057C64: .4byte gUnknown_80FC734
	thumb_func_end sub_8057BEC

	thumb_func_start sub_8057C68
sub_8057C68:
	push {lr}
	sub sp, 0x4
	ldr r2, _08057C84
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	movs r3, 0x40
	bl sub_8077434
	movs r0, 0x1
	add sp, 0x4
	pop {r1}
	bx r1
	.align 2, 0
_08057C84: .4byte gUnknown_8106A4C
	thumb_func_end sub_8057C68

	thumb_func_start sub_8057C88
sub_8057C88:
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
	beq _08057CC2
	movs r7, 0x1
	ldr r0, _08057CCC
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08057CC2
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl sub_80776C0
_08057CC2:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057CCC: .4byte gUnknown_80F4DF6
	thumb_func_end sub_8057C88

	thumb_func_start sub_8057CD0
sub_8057CD0:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r1, 0
	mov r8, r2
	adds r5, r3, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _08057D18
	adds r1, r0, r1
	ldrb r2, [r1]
	ldr r1, _08057D1C
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp]
	str r5, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r6, 0
	mov r3, r8
	bl sub_80556BC
	cmp r0, 0
	beq _08057D0A
	movs r0, 0x1
_08057D0A:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08057D18: .4byte gUnknown_80F51E4
_08057D1C: .4byte gUnknown_80F51EC
	thumb_func_end sub_8057CD0

	thumb_func_start sub_8057D20
sub_8057D20:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r7, 0
	ldr r0, [r4, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	movs r6, 0x80
	lsls r6, 1
	cmp r0, 0x9
	bne _08057D3C
	movs r6, 0x80
	lsls r6, 2
_08057D3C:
	str r3, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r3, r6, 0
	bl sub_8055640
	cmp r0, 0
	beq _08057D6E
	movs r7, 0x1
	ldr r0, _08057D78
	movs r1, 0
	ldrsh r2, [r0, r1]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_805727C
	lsls r0, 24
	cmp r0, 0
	beq _08057D6E
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x3B
	movs r3, 0
	bl sub_80768DC
_08057D6E:
	adds r0, r7, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08057D78: .4byte gUnknown_80F4E08
	thumb_func_end sub_8057D20

	thumb_func_start sub_8057D7C
sub_8057D7C:
	push {lr}
	sub sp, 0x8
	ldr r2, _08057D98
	ldr r2, [r2]
	movs r3, 0x1
	str r3, [sp]
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl sub_8076F80
	movs r0, 0x1
	add sp, 0x8
	pop {r1}
	bx r1
	.align 2, 0
_08057D98: .4byte gUnknown_8106A50
	thumb_func_end sub_8057D7C

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
	bl sub_807723C
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
	bl sub_8092B00
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
	bl sub_80570AC
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
	bl sub_8092B00
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
	bl sub_8092B00
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
	bl sub_80570AC
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
	bl sub_8071824
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
	bl sub_807E580
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
	bl sub_80570AC
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
	bl sub_808411C
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
	bl sub_8071824
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
	bl sub_8092A88
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
	bl sub_8092B00
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
	bl sub_8092B00
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
	bl sub_8071824
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
	bl sub_8092B00
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
	bl sub_8071824
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
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _080592BA
	adds r0, r4, 0
	movs r1, 0x35
	bl sub_8071824
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
	bl sub_8092A88
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
	bl sub_8071824
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
	bl sub_8092B00
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
	bl sub_8092B00
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
	bl sub_807E580
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	beq _080596B6
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_80570AC
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
	bl sub_8092B00
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
	bl sub_80570AC
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
	bl sub_8092B00
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
	bl sub_8045128
	bl sub_804AF20
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
	bl sub_80570AC
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
	bl sub_8092B00
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
	bl sub_807E580
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
	bl sub_8092B00
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
	bl sub_8092B00
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
	bl sub_8071824
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
	bl sub_8071A1C
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
	bl sub_8071A1C
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
	bl sub_8071A1C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_8071A44
	adds r5, r0, 0
	adds r0, r7, 0
	bl sub_8092C24
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
	bl sub_80708B4
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
	bl sub_80570AC
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
	bl sub_8071A1C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_8071A44
	adds r5, r0, 0
	adds r0, r7, 0
	bl sub_8092C24
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
	bl sub_80708B4
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
	bl sub_8071824
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
	bl sub_8046CB0
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
	bl sub_8071824
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
	bl sub_8071824
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
	bl sub_8046CB0
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
_0805A7C8: .4byte gUnknown_80F4448
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
	bl sub_8049590
	ldr r5, [r0, 0x10]
	cmp r5, 0
	beq _0805AA4C
	adds r0, r5, 0
	bl sub_80450F8
	adds r7, r0, 0
	cmp r7, 0x1
	bne _0805A9FE
	add r4, sp, 0x1C
	ldr r1, _0805AA44
	adds r0, r4, 0
	bl sub_8092A88
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
	bl sub_8094450
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
	bl sub_8071598
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
	bl sub_80441BC
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
	bl sub_8071824
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
_0805B134: .4byte gUnknown_80F561C
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
	bl sub_8092B00
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
	bl sub_8092A88
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
	bl sub_8071824
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r4, 0
	bl sub_8070B28
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
	bl sub_8092B00
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
	bl sub_80570AC
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
	bl sub_8071824
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
	bl sub_8046CB0
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

	thumb_func_start sub_805BEA0
sub_805BEA0:
	push {lr}
	bl sub_804002C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805BEA0

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
	bl sub_8045128
	adds r4, r0, 0
	bl sub_80441BC
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
	bl sub_8049590
	ldr r4, [r0, 0x14]
	cmp r4, 0
	beq _0805C028
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x2
	bne _0805C028
	adds r0, r4, 0
	bl sub_8045104
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
	bl sub_8071598
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
	bl sub_8092B00
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

	thumb_func_start sub_805C1E4
sub_805C1E4:
	push {lr}
	ldr r2, _0805C1F4
	ldr r2, [r2]
	bl sub_80522F4
	movs r0, 0
	pop {r1}
	bx r1
	.align 2, 0
_0805C1F4: .4byte gUnknown_80FD454
	thumb_func_end sub_805C1E4

	thumb_func_start sub_805C1F8
sub_805C1F8:
	push {lr}
	movs r2, 0x1
	bl sub_8077BB4
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C1F8

	thumb_func_start sub_805C208
sub_805C208:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r7, r0, 0
	mov r9, r1
	adds r6, r2, 0
	mov r8, r3
	movs r5, 0
	add r0, sp, 0x18
	strb r5, [r0]
	ldr r0, [r1, 0x70]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	bl GetSizeOrbDmg
	mov r10, r0
	adds r0, r6, 0
	bl sub_8092B00
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
	adds r0, r7, 0
	mov r1, r9
	mov r2, r10
	movs r3, 0x1
	bl sub_806F370
	add r1, sp, 0x18
	movs r2, 0
	adds r0, r1, 0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805C270
	movs r2, 0x1
_0805C270:
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
	thumb_func_end sub_805C208

	thumb_func_start sub_805C288
sub_805C288:
	push {lr}
	ldr r2, _0805C29C
	movs r3, 0
	ldrsh r2, [r2, r3]
	movs r3, 0
	bl sub_8078A58
	movs r0, 0x1
	pop {r1}
	bx r1
	.align 2, 0
_0805C29C: .4byte gUnknown_80F4FC6
	thumb_func_end sub_805C288

	thumb_func_start sub_805C2A0
sub_805C2A0:
	push {lr}
	bl sub_807DC68
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C2A0

	thumb_func_start FillInOrbAction
FillInOrbAction:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r0
	adds r7, r1, 0
	movs r0, 0
	mov r9, r0
	ldr r5, [r7, 0x70]
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	beq _0805C2DC
	ldr r0, _0805C2D8
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	movs r0, 0
	b _0805C3CA
	.align 2, 0
_0805C2D8: .4byte gUnknown_80FD0B8
_0805C2DC:
	ldr r4, _0805C3A0
	adds r3, r5, 0
	adds r3, 0x46
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0]
	ldrh r1, [r7, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0805C3A4
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2]
	ldrh r2, [r7, 0x6]
	adds r0, r2
	lsls r0, 16
	ldr r2, _0805C3A8
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r4, sp
	mov r0, sp
	bl sub_8042A54
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_8049590
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	bne _0805C36C
	ldr r0, _0805C3AC
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	movs r5, 0x1
	negs r5, r5
	mov r6, sp
_0805C344:
	movs r4, 0x1
	negs r4, r4
_0805C348:
	movs r1, 0
	ldrsh r0, [r6, r1]
	adds r0, r4
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	adds r1, r5
	bl sub_80498A8
	adds r4, 0x1
	cmp r4, 0x1
	ble _0805C348
	adds r5, 0x1
	cmp r5, 0x1
	ble _0805C344
	movs r0, 0x1
	mov r9, r0
	bl sub_806CF60
_0805C36C:
	movs r5, 0
_0805C36E:
	movs r4, 0
	adds r6, r5, 0x1
_0805C372:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8049BB0
	adds r4, 0x1
	cmp r4, 0x37
	ble _0805C372
	adds r5, r6, 0
	cmp r5, 0x1F
	ble _0805C36E
	mov r1, r9
	cmp r1, 0
	beq _0805C3B4
	mov r0, sp
	bl sub_8042A64
	ldr r0, _0805C3B0
	ldr r2, [r0]
	mov r0, r8
	adds r1, r7, 0
	bl sub_80522F4
	b _0805C3C0
	.align 2, 0
_0805C3A0: .4byte gUnknown_80F4448
_0805C3A4: .4byte 0xffff0000
_0805C3A8: .4byte 0x0000ffff
_0805C3AC: .4byte 0x0000fffc
_0805C3B0: .4byte gUnknown_80FD0B4
_0805C3B4:
	ldr r0, _0805C3D8
	ldr r2, [r0]
	mov r0, r8
	adds r1, r7, 0
	bl sub_80522F4
_0805C3C0:
	bl sub_8040A84
	bl sub_8049ED4
	mov r0, r9
_0805C3CA:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805C3D8: .4byte gUnknown_80FD0B8
	thumb_func_end FillInOrbAction

	thumb_func_start sub_805C3DC
sub_805C3DC:
	push {lr}
	ldr r0, [r1, 0x70]
	ldrb r0, [r0, 0x6]
	movs r2, 0x1
	cmp r0, 0
	beq _0805C3EA
	movs r2, 0x2
_0805C3EA:
	adds r0, r1, 0x4
	movs r1, 0x14
	bl sub_807FC3C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C3DC

	thumb_func_start sub_805C3F8
sub_805C3F8:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r0, [r4, 0x4]
	str r0, [sp, 0x4]
	ldr r0, [r4, 0x70]
	adds r0, 0xA4
	ldrb r1, [r0]
	cmp r1, 0
	bne _0805C442
	adds r0, r4, 0
	adds r0, 0x20
	strb r1, [r0]
	movs r0, 0
	bl sub_803D73C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, sp
	movs r2, 0
	bl sub_8045C28
	add r1, sp, 0x4
	adds r0, r5, 0
	mov r2, sp
	bl sub_80464C8
	movs r1, 0x86
	lsls r1, 2
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8068FE0
	movs r0, 0x1
	b _0805C450
_0805C442:
	ldr r0, _0805C458
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
	movs r0, 0
_0805C450:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805C458: .4byte gUnknown_80FF678
	thumb_func_end sub_805C3F8

	thumb_func_start sub_805C45C
sub_805C45C:
	push {lr}
	bl sub_807F43C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C45C

	thumb_func_start sub_805C468
sub_805C468:
	push {lr}
	bl sub_8078F50
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C468

	thumb_func_start sub_805C474
sub_805C474:
	push {lr}
	bl sub_8077E4C
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C474

	thumb_func_start sub_805C480
sub_805C480:
	push {lr}
	bl sub_8079570
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C480

	thumb_func_start sub_805C48C
sub_805C48C:
	push {lr}
	bl sub_80795C4
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_805C48C

	thumb_func_start sub_805C498
sub_805C498:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r2, [r5, 0x70]
	ldrh r0, [r1, 0x2]
	subs r1, r0, 0x7
	ldr r0, _0805C4B8
	cmp r1, r0
	bls _0805C4AC
	bl _0805CEA8
_0805C4AC:
	lsls r0, r1, 2
	ldr r1, _0805C4BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805C4B8: .4byte 0x0000018f
_0805C4BC: .4byte _0805C4C0
	.align 2, 0
_0805C4C0:
	.4byte _0805CDE8
	.4byte _0805CCE4
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC70
	.4byte _0805CEA8
	.4byte _0805CB00
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB0C
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB12
	.4byte _0805CEA8
	.4byte _0805CB18
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDE8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD48
	.4byte _0805CEA8
	.4byte _0805CB12
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB1E
	.4byte _0805CD8A
	.4byte _0805CEA8
	.4byte _0805CB40
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB46
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB40
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CCA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB4C
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB56
	.4byte _0805CB5C
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD50
	.4byte _0805CEA8
	.4byte _0805CB62
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB72
	.4byte _0805CEA8
	.4byte _0805CB80
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC94
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC7C
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD90
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CCD8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD64
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB94
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD96
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDF4
	.4byte _0805CE00
	.4byte _0805CB40
	.4byte _0805CDE8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB1E
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB40
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD20
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDD2
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC88
	.4byte _0805CEA8
	.4byte _0805CD9C
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CCC2
	.4byte _0805CB9A
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CBBA
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CBD0
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CBDA
	.4byte _0805CB24
	.4byte _0805CB40
	.4byte _0805CB8E
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CBE0
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDE8
	.4byte _0805CDE8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDB0
	.4byte _0805CEA8
	.4byte _0805CDE8
	.4byte _0805CEA8
	.4byte _0805CBF0
	.4byte _0805CEA8
	.4byte _0805CC18
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDBC
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC54
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC62
	.4byte _0805CB40
	.4byte _0805CEA8
	.4byte _0805CD50
	.4byte _0805CC62
	.4byte _0805CEA8
	.4byte _0805CD34
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC1E
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC24
	.4byte _0805CBDA
	.4byte _0805CEA8
	.4byte _0805CDCA
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB1E
	.4byte _0805CDDC
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC32
	.4byte _0805CEA8
	.4byte _0805CB46
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CC38
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CB56
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CCB6
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDE8
	.4byte _0805CDE8
	.4byte _0805CDE8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDE8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD74
	.4byte _0805CEA8
	.4byte _0805CD50
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CD06
	.4byte _0805CEA8
	.4byte _0805CC9A
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CEA8
	.4byte _0805CDE8
_0805CB00:
	adds r0, r5, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	b _0805CC5A
_0805CB0C:
	adds r0, r2, 0
	adds r0, 0xC0
	b _0805CDF8
_0805CB12:
	adds r0, r2, 0
	adds r0, 0xC4
	b _0805CCAC
_0805CB18:
	adds r0, r2, 0
	adds r0, 0xC4
	b _0805CB76
_0805CB1E:
	movs r1, 0x1C
	ldrsh r0, [r2, r1]
	b _0805CDD6
_0805CB24:
	movs r3, 0x1C
	ldrsh r0, [r2, r3]
	cmp r0, 0x13
	bgt _0805CB6E
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0
	ble _0805CB3E
	b _0805CEA8
_0805CB3E:
	b _0805CB6E
_0805CB40:
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	b _0805CDD6
_0805CB46:
	adds r0, r2, 0
	adds r0, 0xC0
	b _0805CC9E
_0805CB4C:
	ldr r0, [r5, 0x70]
	movs r2, 0x82
	lsls r2, 1
	adds r0, r2
	b _0805CC4A
_0805CB56:
	adds r0, r2, 0
	adds r0, 0xDC
	b _0805CC9E
_0805CB5C:
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	b _0805CDCE
_0805CB62:
	adds r0, r2, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x9
	beq _0805CB6E
	b _0805CEA8
_0805CB6E:
	movs r0, 0
	b _0805CEAA
_0805CB72:
	adds r0, r2, 0
	adds r0, 0xC0
_0805CB76:
	ldrb r0, [r0]
	cmp r0, 0xB
	beq _0805CB7E
	b _0805CEA8
_0805CB7E:
	b _0805CB6E
_0805CB80:
	adds r0, r2, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _0805CB8C
	b _0805CEA8
_0805CB8C:
	b _0805CB6E
_0805CB8E:
	adds r0, r2, 0
	adds r0, 0xC4
	b _0805CDE0
_0805CB94:
	movs r3, 0x26
	ldrsh r0, [r2, r3]
	b _0805CDD6
_0805CB9A:
	adds r0, r2, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _0805CB6E
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r3, 0xE
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _0805CBB8
	b _0805CEA8
_0805CBB8:
	b _0805CB6E
_0805CBBA:
	movs r0, 0x10
	ldrsh r1, [r2, r0]
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _0805CB6E
	movs r1, 0x89
	lsls r1, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	b _0805CDC4
_0805CBD0:
	movs r3, 0x89
	lsls r3, 1
	adds r0, r2, r3
	ldrb r0, [r0]
	b _0805CDC4
_0805CBDA:
	adds r0, r2, 0
	adds r0, 0xDC
	b _0805CDE0
_0805CBE0:
	movs r1, 0x1C
	ldrsh r0, [r2, r1]
	cmp r0, 0x13
	bgt _0805CBEA
	b _0805CEA8
_0805CBEA:
	movs r3, 0x20
	ldrsh r0, [r2, r3]
	b _0805CDD6
_0805CBF0:
	ldr r1, _0805CC0C
	ldr r0, _0805CC10
	ldr r0, [r0]
	ldr r2, _0805CC14
	adds r0, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8071858
	b _0805CDEC
	.align 2, 0
_0805CC0C: .4byte gUnknown_80F561C
_0805CC10: .4byte gDungeonGlobalData
_0805CC14: .4byte 0x00003a0e
_0805CC18:
	movs r1, 0x1E
	ldrsh r0, [r2, r1]
	b _0805CDD6
_0805CC1E:
	adds r0, r2, 0
	adds r0, 0xD0
	b _0805CDB4
_0805CC24:
	adds r0, r2, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x8
	beq _0805CC30
	b _0805CEA8
_0805CC30:
	b _0805CB6E
_0805CC32:
	adds r0, r2, 0
	adds r0, 0xC4
	b _0805CC9E
_0805CC38:
	movs r3, 0x1C
	ldrsh r0, [r2, r3]
	cmp r0, 0x13
	bgt _0805CC42
	b _0805CEA8
_0805CC42:
	ldr r0, [r5, 0x70]
	movs r1, 0x82
	lsls r1, 1
	adds r0, r1
_0805CC4A:
	ldr r0, [r0]
	cmp r0, 0x3
	bgt _0805CC52
	b _0805CEA8
_0805CC52:
	b _0805CB6E
_0805CC54:
	adds r0, r2, 0
	adds r0, 0xC4
	ldrb r0, [r0]
_0805CC5A:
	cmp r0, 0x5
	beq _0805CC60
	b _0805CEA8
_0805CC60:
	b _0805CB6E
_0805CC62:
	adds r0, r2, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x7
	beq _0805CC6E
	b _0805CEA8
_0805CC6E:
	b _0805CB6E
_0805CC70:
	adds r0, r5, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	b _0805CCAE
_0805CC7C:
	adds r0, r5, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	b _0805CDB6
_0805CC88:
	adds r0, r5, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	b _0805CCA0
_0805CC94:
	adds r0, r2, 0
	adds r0, 0xC4
	b _0805CDB4
_0805CC9A:
	adds r0, r2, 0
	adds r0, 0xE4
_0805CC9E:
	ldrb r0, [r0]
_0805CCA0:
	cmp r0, 0x1
	beq _0805CCA6
	b _0805CEA8
_0805CCA6:
	b _0805CB6E
_0805CCA8:
	adds r0, r2, 0
	adds r0, 0xDC
_0805CCAC:
	ldrb r0, [r0]
_0805CCAE:
	cmp r0, 0x4
	beq _0805CCB4
	b _0805CEA8
_0805CCB4:
	b _0805CB6E
_0805CCB6:
	adds r0, r2, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	b _0805CDEE
_0805CCC2:
	adds r0, r5, 0
	bl sub_8070B48
	lsls r0, 24
	cmp r0, 0
	beq _0805CCD0
	b _0805CEA8
_0805CCD0:
	adds r0, r5, 0
	bl sub_8070A58
	b _0805CDC2
_0805CCD8:
	adds r0, r5, 0
	bl sub_8045128
	bl sub_804AF20
	b _0805CDEC
_0805CCE4:
	adds r0, r5, 0
	bl sub_8045128
	adds r4, r0, 0
	bl sub_804AF20
	lsls r0, 24
	cmp r0, 0
	bne _0805CCF8
	b _0805CB6E
_0805CCF8:
	ldrh r1, [r4]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _0805CD04
	b _0805CEA8
_0805CD04:
	b _0805CB6E
_0805CD06:
	adds r0, r5, 0
	bl sub_8045128
	ldr r0, [r0, 0x14]
	cmp r0, 0
	bne _0805CD14
	b _0805CB6E
_0805CD14:
	bl sub_80450F8
	cmp r0, 0x2
	bne _0805CD1E
	b _0805CEA8
_0805CD1E:
	b _0805CB6E
_0805CD20:
	ldr r0, _0805CD2C
	ldr r0, [r0]
	ldr r2, _0805CD30
	adds r0, r2
	ldrb r0, [r0]
	b _0805CDEE
	.align 2, 0
_0805CD2C: .4byte gDungeonGlobalData
_0805CD30: .4byte 0x0000e277
_0805CD34:
	ldr r0, _0805CD40
	ldr r0, [r0]
	ldr r3, _0805CD44
	adds r0, r3
	ldrb r0, [r0]
	b _0805CDEE
	.align 2, 0
_0805CD40: .4byte gDungeonGlobalData
_0805CD44: .4byte 0x0000e278
_0805CD48:
	adds r0, r2, 0
	adds r0, 0xF4
	ldrb r0, [r0]
	b _0805CDEE
_0805CD50:
	ldr r0, _0805CD5C
	ldr r0, [r0]
	ldr r1, _0805CD60
	adds r0, r1
	ldrb r0, [r0]
	b _0805CDEE
	.align 2, 0
_0805CD5C: .4byte gDungeonGlobalData
_0805CD60: .4byte 0x000037fc
_0805CD64:
	movs r3, 0x89
	lsls r3, 1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0x2
	bhi _0805CD72
	b _0805CEA8
_0805CD72:
	b _0805CB6E
_0805CD74:
	adds r0, r2, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805CD84
	b _0805CEA8
_0805CD84:
	movs r0, 0x8
	ands r0, r1
	b _0805CDC4
_0805CD8A:
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	b _0805CDD6
_0805CD90:
	movs r3, 0x1E
	ldrsh r0, [r2, r3]
	b _0805CDD6
_0805CD96:
	movs r1, 0x1C
	ldrsh r0, [r2, r1]
	b _0805CDD6
_0805CD9C:
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _0805CDA4
	b _0805CB6E
_0805CDA4:
	adds r0, r2, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _0805CEA8
	b _0805CB6E
_0805CDB0:
	adds r0, r2, 0
	adds r0, 0xE4
_0805CDB4:
	ldrb r0, [r0]
_0805CDB6:
	cmp r0, 0x2
	bne _0805CEA8
	b _0805CB6E
_0805CDBC:
	adds r0, r5, 0x4
	bl sub_807FC80
_0805CDC2:
	lsls r0, 24
_0805CDC4:
	cmp r0, 0
	bne _0805CEA8
	b _0805CB6E
_0805CDCA:
	movs r3, 0x1E
	ldrsh r0, [r2, r3]
_0805CDCE:
	cmp r0, 0x13
	ble _0805CEA8
_0805CDD2:
	movs r1, 0x22
	ldrsh r0, [r2, r1]
_0805CDD6:
	cmp r0, 0x13
	ble _0805CEA8
	b _0805CB6E
_0805CDDC:
	adds r0, r2, 0
	adds r0, 0xC8
_0805CDE0:
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0805CEA8
	b _0805CB6E
_0805CDE8:
	bl sub_80441BC
_0805CDEC:
	lsls r0, 24
_0805CDEE:
	cmp r0, 0
	beq _0805CEA8
	b _0805CB6E
_0805CDF4:
	adds r0, r2, 0
	adds r0, 0xC4
_0805CDF8:
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _0805CEA8
	b _0805CB6E
_0805CE00:
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _0805CE5C
	movs r6, 0
_0805CE08:
	ldr r0, _0805CE54
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0805CE58
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805CE46
	cmp r4, r5
	beq _0805CE46
	adds r0, r5, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0805CE46
	ldr r1, [r4, 0x70]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	cmp r0, 0x13
	bgt _0805CE46
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	cmp r0, 0x13
	ble _0805CE4C
_0805CE46:
	adds r6, 0x1
	cmp r6, 0xF
	ble _0805CE08
_0805CE4C:
	cmp r6, 0x10
	bne _0805CEA8
	b _0805CB6E
	.align 2, 0
_0805CE54: .4byte gDungeonGlobalData
_0805CE58: .4byte 0x0001358c
_0805CE5C:
	movs r6, 0
_0805CE5E:
	ldr r0, _0805CEB0
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r3, _0805CEB4
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805CE9C
	cmp r4, r5
	beq _0805CE9C
	adds r0, r5, 0
	adds r1, r4, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0805CE9C
	ldr r1, [r4, 0x70]
	movs r2, 0x1C
	ldrsh r0, [r1, r2]
	cmp r0, 0x13
	bgt _0805CE9C
	movs r3, 0x1E
	ldrsh r0, [r1, r3]
	cmp r0, 0x13
	ble _0805CEA2
_0805CE9C:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805CE5E
_0805CEA2:
	cmp r6, 0x4
	bne _0805CEA8
	b _0805CB6E
_0805CEA8:
	movs r0, 0x1
_0805CEAA:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805CEB0: .4byte gDungeonGlobalData
_0805CEB4: .4byte 0x0001357c
	thumb_func_end sub_805C498

	thumb_func_start sub_805CEB8
sub_805CEB8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r5, [r0, 0x70]
	ldr r4, [r6, 0x70]
	adds r0, r4, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0805CEE0
	adds r0, r7, 0
	bl sub_8092C3C
	lsls r0, 24
	cmp r0, 0
	beq _0805CEE0
	b _0805D540
_0805CEE0:
	ldrh r0, [r7, 0x2]
	subs r2, r0, 0x3
	ldr r0, _0805CEF8
	cmp r2, r0
	bls _0805CEEE
	bl _0805D802
_0805CEEE:
	lsls r0, r2, 2
	ldr r1, _0805CEFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805CEF8: .4byte 0x0000017b
_0805CEFC: .4byte _0805CF00
	.align 2, 0
_0805CF00:
	.4byte _0805D4FA
	.4byte _0805D4F0
	.4byte _0805D50E
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D516
	.4byte _0805D51C
	.4byte _0805D802
	.4byte _0805D7F6
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D520
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D52C
	.4byte _0805D532
	.4byte _0805D544
	.4byte _0805D55A
	.4byte _0805D7F6
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D566
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D56A
	.4byte _0805D4F0
	.4byte _0805D570
	.4byte _0805D802
	.4byte _0805D57E
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D584
	.4byte _0805D802
	.4byte _0805D7F6
	.4byte _0805D802
	.4byte _0805D596
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D59C
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D5C8
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D5D0
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D4F0
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D5E2
	.4byte _0805D4F0
	.4byte _0805D5E8
	.4byte _0805D5F8
	.4byte _0805D802
	.4byte _0805D5FE
	.4byte _0805D5F8
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D55A
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D4F0
	.4byte _0805D662
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D668
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D5DC
	.4byte _0805D802
	.4byte _0805D5C8
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D7AC
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D704
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D704
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D7F6
	.4byte _0805D70A
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D7F6
	.4byte _0805D5C8
	.4byte _0805D802
	.4byte _0805D5F8
	.4byte _0805D802
	.4byte _0805D7E4
	.4byte _0805D7DC
	.4byte _0805D802
	.4byte _0805D7E4
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D716
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D740
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D74A
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D5DC
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D4F0
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D75C
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D734
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D782
	.4byte _0805D740
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D704
	.4byte _0805D7F6
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D5C8
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D7A0
	.4byte _0805D7CA
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D78A
	.4byte _0805D59C
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D7BE
	.4byte _0805D7AC
	.4byte _0805D802
	.4byte _0805D794
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D55A
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D782
	.4byte _0805D802
	.4byte _0805D802
	.4byte _0805D7F6
_0805D4F0:
	adds r0, r6, 0
	bl sub_8070B28
	lsls r0, 24
	b _0805D7A6
_0805D4FA:
	adds r0, r4, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0805D540
	adds r0, r6, 0
	bl sub_8070B28
	lsls r0, 24
	b _0805D7A6
_0805D50E:
	adds r0, r4, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	b _0805D7F0
_0805D516:
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	b _0805D744
_0805D51C:
	ldr r0, [r4, 0x2C]
	b _0805D58E
_0805D520:
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _0805D540
	b _0805D7AC
_0805D52C:
	movs r3, 0xE
	ldrsh r0, [r4, r3]
	b _0805D78E
_0805D532:
	movs r7, 0xE
	ldrsh r1, [r4, r7]
	movs r2, 0xE
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble _0805D540
	b _0805D802
_0805D540:
	movs r0, 0
	b _0805D804
_0805D544:
	movs r3, 0x8C
	lsls r3, 1
	adds r4, r3
	adds r0, r4, 0
	bl sub_805D810
	lsls r0, 24
	cmp r0, 0
	bne _0805D540
	adds r0, r4, 0
	b _0805D7B2
_0805D55A:
	ldr r0, [r6, 0x70]
	movs r7, 0x82
	lsls r7, 1
	adds r0, r7
	ldr r0, [r0]
	b _0805D744
_0805D566:
	ldr r0, [r4, 0x34]
	b _0805D58E
_0805D56A:
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	b _0805D744
_0805D570:
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r4, r2
	bl sub_805D850
	lsls r0, 24
	b _0805D7A6
_0805D57E:
	adds r0, r4, 0
	adds r0, 0xDC
	b _0805D7FA
_0805D584:
	ldr r0, [r4, 0x2C]
	cmp r0, 0x3E
	ble _0805D58C
	b _0805D802
_0805D58C:
	ldr r0, [r4, 0x30]
_0805D58E:
	cmp r0, 0x3E
	ble _0805D594
	b _0805D802
_0805D594:
	b _0805D540
_0805D596:
	adds r0, r4, 0
	adds r0, 0xAC
	b _0805D798
_0805D59C:
	adds r0, r4, 0
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _0805D5B0
	adds r0, r4, 0
	adds r0, 0x5D
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _0805D5BC
_0805D5B0:
	adds r0, r4, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805D5BC
	b _0805D802
_0805D5BC:
	movs r3, 0x26
	ldrsh r0, [r4, r3]
	cmp r0, 0xA
	ble _0805D5C6
	b _0805D802
_0805D5C6:
	b _0805D540
_0805D5C8:
	adds r0, r4, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	b _0805D7D6
_0805D5D0:
	movs r7, 0xE
	ldrsh r0, [r4, r7]
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	subs r0, r1
	b _0805D744
_0805D5DC:
	movs r3, 0x20
	ldrsh r0, [r4, r3]
	b _0805D744
_0805D5E2:
	movs r7, 0x22
	ldrsh r0, [r4, r7]
	b _0805D744
_0805D5E8:
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _0805D5F2
	b _0805D802
_0805D5F2:
	movs r2, 0x20
	ldrsh r0, [r4, r2]
	b _0805D744
_0805D5F8:
	adds r0, r4, 0
	adds r0, 0xB0
	b _0805D7FA
_0805D5FE:
	movs r6, 0
	adds r2, r4, 0
	adds r2, 0x1C
	movs r3, 0x1C
	ldrsh r0, [r4, r3]
	cmp r0, 0x9
	ble _0805D6FC
	adds r1, r4, 0
	adds r1, 0x20
	movs r7, 0x20
	ldrsh r0, [r4, r7]
	cmp r0, 0x9
	ble _0805D6FC
	adds r3, r1, 0
	movs r5, 0
_0805D61C:
	adds r0, r4, 0
	adds r0, 0x24
	adds r0, r5
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x9
	ble _0805D6FC
	lsls r1, r6, 2
	adds r0, r4, 0
	adds r0, 0x2C
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xFF
	ble _0805D6FC
	adds r0, r4, 0
	adds r0, 0x34
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0xFF
	ble _0805D6FC
	adds r3, 0x2
	adds r2, 0x2
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, 0x1
	bgt _0805D6FC
	movs r7, 0
	ldrsh r0, [r2, r7]
	cmp r0, 0x9
	ble _0805D6FC
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0x9
	bgt _0805D61C
	b _0805D6FC
_0805D662:
	adds r0, r4, 0
	adds r0, 0xA8
	b _0805D7FA
_0805D668:
	movs r6, 0
	adds r3, r5, 0
	adds r3, 0x1C
	adds r2, r4, 0
	adds r2, 0x1C
	movs r7, 0x1C
	ldrsh r1, [r5, r7]
	movs r7, 0x1C
	ldrsh r0, [r4, r7]
	cmp r1, r0
	blt _0805D6FC
	mov r12, r2
	mov r8, r3
	movs r3, 0
_0805D684:
	adds r1, r5, 0
	adds r1, 0x20
	adds r1, r3
	adds r0, r4, 0
	adds r0, 0x20
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r7, 0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	blt _0805D6FC
	adds r1, r5, 0
	adds r1, 0x24
	adds r1, r3
	adds r0, r4, 0
	adds r0, 0x24
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r7, 0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	blt _0805D6FC
	lsls r2, r6, 2
	adds r1, r5, 0
	adds r1, 0x2C
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x2C
	adds r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	blt _0805D6FC
	adds r1, r5, 0
	adds r1, 0x34
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x34
	adds r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	blt _0805D6FC
	movs r0, 0x2
	add r12, r0
	add r8, r0
	adds r3, 0x2
	adds r6, 0x1
	cmp r6, 0x1
	bgt _0805D6FC
	mov r2, r8
	movs r7, 0
	ldrsh r1, [r2, r7]
	mov r2, r12
	movs r7, 0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _0805D684
_0805D6FC:
	cmp r6, 0x2
	beq _0805D702
	b _0805D802
_0805D702:
	b _0805D540
_0805D704:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	b _0805D744
_0805D70A:
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0805D802
	b _0805D540
_0805D716:
	adds r0, r5, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0805D728
	b _0805D540
_0805D728:
	adds r0, r4, 0
	adds r0, 0x60
	ldrb r1, [r0]
	adds r0, r2, 0
	ands r0, r1
	b _0805D7B8
_0805D734:
	adds r0, r4, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	b _0805D7B8
_0805D740:
	movs r2, 0x1C
	ldrsh r0, [r4, r2]
_0805D744:
	cmp r0, 0
	bgt _0805D802
	b _0805D540
_0805D74A:
	adds r0, r5, 0
	adds r0, 0x5E
	adds r1, r4, 0
	adds r1, 0x5E
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0805D802
	b _0805D540
_0805D75C:
	mov r0, r8
	movs r1, 0xE
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	beq _0805D770
	adds r0, r4, 0
	adds r0, 0xC8
	b _0805D798
_0805D770:
	movs r3, 0x1C
	ldrsh r0, [r5, r3]
	cmp r0, 0x13
	ble _0805D802
	movs r7, 0x20
	ldrsh r0, [r5, r7]
	cmp r0, 0x13
	ble _0805D802
	b _0805D540
_0805D782:
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	b _0805D7F0
_0805D78A:
	movs r1, 0xE
	ldrsh r0, [r4, r1]
_0805D78E:
	cmp r0, 0x1
	bgt _0805D802
	b _0805D540
_0805D794:
	adds r0, r4, 0
	adds r0, 0xD0
_0805D798:
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0805D802
	b _0805D540
_0805D7A0:
	adds r0, r4, 0
	adds r0, 0xFD
	ldrb r0, [r0]
_0805D7A6:
	cmp r0, 0
	beq _0805D802
	b _0805D540
_0805D7AC:
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r4, r2
_0805D7B2:
	bl sub_805D888
	lsls r0, 24
_0805D7B8:
	cmp r0, 0
	bne _0805D802
	b _0805D540
_0805D7BE:
	adds r0, r4, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _0805D802
	b _0805D540
_0805D7CA:
	adds r0, r4, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0805D7D6
	b _0805D540
_0805D7D6:
	cmp r0, 0x4
	bne _0805D802
	b _0805D540
_0805D7DC:
	adds r0, r4, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	b _0805D7F0
_0805D7E4:
	adds r0, r4, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0805D7F0
	b _0805D540
_0805D7F0:
	cmp r0, 0x3
	bne _0805D802
	b _0805D540
_0805D7F6:
	adds r0, r4, 0
	adds r0, 0xBC
_0805D7FA:
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0805D802
	b _0805D540
_0805D802:
	movs r0, 0x1
_0805D804:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805CEB8

	thumb_func_start sub_805D810
sub_805D810:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r3, 0
	movs r6, 0x1
	movs r5, 0x20
	adds r2, r4, 0
_0805D81C:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0805D82E
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0805D848
_0805D82E:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805D81C
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0805D848
	movs r0, 0
	b _0805D84A
_0805D848:
	movs r0, 0x1
_0805D84A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805D810

	thumb_func_start sub_805D850
sub_805D850:
	push {r4,r5,lr}
	movs r3, 0
	movs r5, 0x1
	adds r2, r0, 0
	movs r4, 0x10
_0805D85A:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0805D876
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0805D876
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	bne _0805D876
	movs r0, 0x1
	b _0805D880
_0805D876:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805D85A
	movs r0, 0
_0805D880:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_805D850

	thumb_func_start sub_805D888
sub_805D888:
	push {r4-r6,lr}
	adds r4, r0, 0
	movs r3, 0
	movs r6, 0x1
	movs r5, 0x10
	adds r2, r4, 0
_0805D894:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0805D8A6
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0805D8C0
_0805D8A6:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805D894
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0805D8C0
	movs r0, 0
	b _0805D8C2
_0805D8C0:
	movs r0, 0x1
_0805D8C2:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805D888

	thumb_func_start sub_805D8C8
sub_805D8C8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r4, _0805D90C
	ldr r1, [r4]
	ldr r0, _0805D910
	adds r0, r1, r0
	str r0, [sp, 0x10]
	movs r2, 0x3
	str r2, [sp, 0xC]
	movs r5, 0
	movs r0, 0
	strh r0, [r1, 0x12]
	bl sub_8083600
	movs r1, 0x1
	bl sub_806A2BC
	bl sub_8083600
	bl sub_80701A4
	lsls r0, 24
	cmp r0, 0
	beq _0805D928
	movs r0, 0x3C
	movs r1, 0x10
	bl sub_803E708
	bl _0805E2B0
	.align 2, 0
_0805D90C: .4byte gDungeonGlobalData
_0805D910: .4byte 0x000181e8
_0805D914:
	mov r1, r8
	adds r1, 0x44
	movs r2, 0
	movs r0, 0x2
	strh r0, [r1]
	mov r0, r8
	adds r0, 0x48
	strb r2, [r0]
	bl _0805E2B0
_0805D928:
	ldr r0, [r4]
	ldr r3, _0805D9D4
	adds r0, r3
	strb r5, [r0]
	bl sub_8040A78
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _0805D976
	strb r5, [r1, 0x1]
	bl sub_8083600
	movs r1, 0x1
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	bne _0805D976
	movs r0, 0x1
	bl sub_8044C10
	bl sub_805E804
	bl sub_8083600
	bl sub_80647F0
	bl ResetRepeatTimers
	bl ResetUnusedInputStruct
	bl sub_805F1AC
	lsls r0, 16
	cmp r0, 0
	beq _0805D976
	bl _0805E2B0
_0805D976:
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_806A914
_0805D980:
	bl sub_8083600
	mov r10, r0
	ldr r5, [r0, 0x70]
	mov r8, r5
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	bl sub_80978C8
	ldr r2, _0805D9D8
	ldr r0, [r2]
	ldr r3, _0805D9DC
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805D9AE
	bl sub_805E874
	lsls r0, 24
	cmp r0, 0
	bne _0805D914
	bl sub_805E804
_0805D9AE:
	ldr r0, _0805D9E0
	movs r1, 0
	strb r1, [r0]
	ldr r0, _0805D9E4
	strb r1, [r0]
	ldr r5, _0805D9D8
	ldr r0, [r5]
	movs r1, 0xB8
	lsls r1, 3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bge _0805D9CA
	b _0805DAE8
_0805D9CA:
	ldr r0, _0805D9E8
	ands r6, r0
	movs r2, 0x1
	orrs r6, r2
	b _0805DAEC
	.align 2, 0
_0805D9D4: .4byte 0x00000673
_0805D9D8: .4byte gDungeonGlobalData
_0805D9DC: .4byte 0x0000066c
_0805D9E0: .4byte gUnknown_202F22D
_0805D9E4: .4byte gUnknown_202F22C
_0805D9E8: .4byte 0xffffff00
_0805D9EC:
	movs r0, 0x1
	bl sub_8044C50
	ldr r3, _0805DA00
	ldr r0, [r3]
	ldr r5, _0805DA04
	adds r0, r5
	strb r4, [r0]
	b _0805E1AE
	.align 2, 0
_0805DA00: .4byte gDungeonGlobalData
_0805DA04: .4byte 0x00000673
_0805DA08:
	ldr r0, _0805DA14
	ldr r1, [r0]
	mov r0, r10
	bl SendMessage
	b _0805DBDA
	.align 2, 0
_0805DA14: .4byte gUnknown_80FD4B0
_0805DA18:
	ldr r0, _0805DA1C
	b _0805DCBC
	.align 2, 0
_0805DA1C: .4byte gUnknown_80F8A28
_0805DA20:
	ldr r0, [sp, 0x1C]
	movs r1, 0x17
	bl sub_8044C94
	b _0805E1AE
_0805DA2A:
	ldr r0, _0805DA38
	ands r6, r0
	movs r3, 0x1
	orrs r6, r3
	ldr r0, _0805DA3C
	ands r6, r0
	b _0805DAD6
	.align 2, 0
_0805DA38: .4byte 0xffffff00
_0805DA3C: .4byte 0xffff00ff
_0805DA40:
	ldr r5, _0805DA58
	ldr r0, [r5]
	movs r2, 0xB8
	lsls r2, 3
	adds r0, r2
	str r1, [r0]
	ldr r0, _0805DA5C
	ands r6, r0
	movs r3, 0x1
	orrs r6, r3
	b _0805DAA8
	.align 2, 0
_0805DA58: .4byte gDungeonGlobalData
_0805DA5C: .4byte 0xffffff00
_0805DA60:
	ldr r5, _0805DA78
	ldr r0, [r5]
	movs r1, 0xB8
	lsls r1, 3
	adds r0, r1
	movs r2, 0x1
	str r2, [r0]
	ldr r0, _0805DA7C
	ands r6, r0
	orrs r6, r2
	b _0805DAA8
	.align 2, 0
_0805DA78: .4byte gDungeonGlobalData
_0805DA7C: .4byte 0xffffff00
_0805DA80:
	ldr r3, _0805DA98
	ldr r0, [r3]
	movs r5, 0xB8
	lsls r5, 3
	adds r0, r5
	str r2, [r0]
	ldr r0, _0805DA9C
	ands r6, r0
	movs r0, 0x1
	orrs r6, r0
	b _0805DAA8
	.align 2, 0
_0805DA98: .4byte gDungeonGlobalData
_0805DA9C: .4byte 0xffffff00
_0805DAA0:
	ldr r0, _0805DAB8
	ands r6, r0
	movs r1, 0x1
	orrs r6, r1
_0805DAA8:
	ldr r0, _0805DABC
	ands r6, r0
	ldr r0, _0805DAC0
	ands r6, r0
	movs r0, 0x80
	lsls r0, 9
	orrs r6, r0
	b _0805E1AE
	.align 2, 0
_0805DAB8: .4byte 0xffffff00
_0805DABC: .4byte 0xffff00ff
_0805DAC0: .4byte 0xff00ffff
_0805DAC4:
	ldr r0, _0805DADC
	ands r6, r0
	movs r2, 0x1
	orrs r6, r2
	ldr r0, _0805DAE0
	ands r6, r0
	movs r0, 0x80
	lsls r0, 1
	orrs r6, r0
_0805DAD6:
	ldr r0, _0805DAE4
	ands r6, r0
	b _0805E1AE
	.align 2, 0
_0805DADC: .4byte 0xffffff00
_0805DAE0: .4byte 0xffff00ff
_0805DAE4: .4byte 0xff00ffff
_0805DAE8:
	ldr r0, _0805DB3C
	ands r6, r0
_0805DAEC:
	ldr r0, _0805DB40
	ands r6, r0
	ldr r0, _0805DB44
	ands r6, r0
	movs r3, 0
	str r3, [sp, 0x8]
	movs r0, 0
	bl sub_8044C50
	ldr r0, _0805DB48
	mov r5, sp
	ldrb r5, [r5, 0x8]
	strb r5, [r0]
	ldr r0, _0805DB4C
	mov r1, sp
	ldrb r1, [r1, 0x8]
	strb r1, [r0]
	lsls r0, r6, 24
	mov r2, r8
	adds r2, 0x44
	str r2, [sp, 0x1C]
	str r0, [sp, 0x14]
	ldr r3, [sp, 0x10]
	adds r3, 0x32
	str r3, [sp, 0x18]
	cmp r0, 0
	beq _0805DB24
	b _0805E1AE
_0805DB24:
	ldr r0, _0805DB50
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	ldr r5, [sp, 0x18]
	ldrb r0, [r5]
	cmp r0, 0
	beq _0805DB54
	movs r0, 0
	str r0, [sp, 0x8]
	b _0805DB5A
	.align 2, 0
_0805DB3C: .4byte 0xffffff00
_0805DB40: .4byte 0xffff00ff
_0805DB44: .4byte 0xff00ffff
_0805DB48: .4byte gUnknown_202F230
_0805DB4C: .4byte gUnknown_202F231
_0805DB50: .4byte gUnknown_202F22E
_0805DB54:
	ldr r1, [sp, 0x8]
	adds r1, 0x1
	str r1, [sp, 0x8]
_0805DB5A:
	ldr r2, [sp, 0xC]
	cmp r2, 0
	beq _0805DB6E
	subs r2, 0x1
	str r2, [sp, 0xC]
	cmp r2, 0
	bne _0805DB6E
	movs r0, 0
	bl sub_8075680
_0805DB6E:
	mov r0, r10
	bl sub_805E2C4
	movs r7, 0
	movs r1, 0
	add r0, sp, 0x4
_0805DB7A:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _0805DB7A
	ldr r0, _0805DBEC
	ldrh r1, [r0]
	movs r4, 0x1
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805DBAA
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805DBAA
	movs r0, 0x9E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0
	beq _0805DBAA
	b _0805D9EC
_0805DBAA:
	movs r3, 0
	mov r9, r3
	ldr r4, _0805DBEC
	ldrh r1, [r4, 0x2]
	movs r5, 0x1
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805DBBE
	b _0805DD02
_0805DBBE:
	ldrh r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805DBF8
	movs r0, 0x9E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0
	bne _0805DBDA
	b _0805DD02
_0805DBDA:
	movs r0, 0x1
	bl sub_8044C50
	ldr r1, _0805DBF0
	ldr r0, [r1]
	ldr r2, _0805DBF4
	adds r0, r2
	strb r5, [r0]
	b _0805E1AE
	.align 2, 0
_0805DBEC: .4byte gRealInputs
_0805DBF0: .4byte gDungeonGlobalData
_0805DBF4: .4byte 0x00000673
_0805DBF8:
	mov r0, r10
	movs r1, 0x1
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	beq _0805DC08
	b _0805DA08
_0805DC08:
	ldrh r0, [r4]
	movs r3, 0x80
	lsls r3, 2
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0805DCE8
	movs r4, 0
	movs r2, 0x8C
	lsls r2, 1
	add r2, r8
	movs r3, 0x8
_0805DC20:
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805DC32
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0805DC3A
_0805DC32:
	adds r2, 0x8
	adds r4, 0x1
	cmp r4, 0x3
	ble _0805DC20
_0805DC3A:
	cmp r4, 0x4
	bne _0805DC40
	b _0805DA18
_0805DC40:
	movs r3, 0
	movs r5, 0x8C
	lsls r5, 1
	movs r7, 0x1
	mov r2, r8
_0805DC4A:
	lsls r0, r3, 3
	add r0, r8
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0805DC66
	movs r1, 0x8E
	lsls r1, 1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805DC6E
_0805DC66:
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805DC4A
_0805DC6E:
	cmp r3, 0x4
	bne _0805DC74
	b _0805DA20
_0805DC74:
	movs r7, 0
	adds r3, r4, 0
	cmp r4, 0x3
	bgt _0805DCB6
	lsls r0, r4, 3
	adds r2, r0, 0
	add r2, r8
	mov r12, r2
	movs r5, 0x8E
	lsls r5, 1
	adds r0, r5
	mov r1, r8
	adds r2, r0, r1
	movs r5, 0x2
_0805DC90:
	ldrb r0, [r2]
	cmp r0, 0
	bne _0805DCCC
	movs r0, 0x8
	add r12, r0
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	bgt _0805DCB6
	cmp r3, r4
	beq _0805DC90
	movs r0, 0x8C
	lsls r0, 1
	add r0, r12
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0805DC90
_0805DCB6:
	cmp r7, 0
	bne _0805DCCC
	ldr r0, _0805DCC8
_0805DCBC:
	ldr r1, [r0]
	mov r0, r10
	bl SendMessage
	b _0805E1AE
	.align 2, 0
_0805DCC8: .4byte gUnknown_80F8A4C
_0805DCCC:
	ldr r0, [sp, 0x1C]
	movs r1, 0x14
	bl sub_8044C94
	mov r0, r10
	bl sub_8045B60
	mov r1, r8
	adds r1, 0x48
	strb r0, [r1]
	mov r0, r8
	adds r0, 0x50
	strb r4, [r0]
	b _0805E1AE
_0805DCE8:
	mov r0, r10
	mov r1, r8
	bl sub_805EF60
	lsls r0, 24
	cmp r0, 0
	beq _0805DCF8
	b _0805E1AE
_0805DCF8:
	ldr r0, [sp, 0x1C]
	movs r1, 0x32
	bl sub_8044C94
	b _0805E1AE
_0805DD02:
	ldr r3, _0805DDC8
	ldrh r1, [r3, 0x6]
	movs r2, 0x2
	adds r0, r2, 0
	ands r0, r1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0805DD16
	b _0805DA2A
_0805DD16:
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _0805DD20
	b _0805DA40
_0805DD20:
	mov r0, sp
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _0805DD2A
	b _0805DA60
_0805DD2A:
	mov r0, sp
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _0805DD34
	b _0805DA80
_0805DD34:
	mov r0, sp
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _0805DD3E
	b _0805DAA0
_0805DD3E:
	ldr r0, _0805DDCC
	ldr r1, [sp, 0x8]
	cmp r1, r0
	ble _0805DD48
	b _0805DAC4
_0805DD48:
	ldr r0, _0805DDD0
	ldr r0, [r0]
	ldrb r4, [r0, 0x9]
	cmp r4, 0
	bne _0805DD7E
	ldrh r1, [r3, 0x2]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0805DD66
	cmp r7, 0
	bne _0805DD7E
	movs r2, 0
	cmp r2, 0
	beq _0805DD7E
_0805DD66:
	ldr r3, [sp, 0x18]
	ldrb r0, [r3]
	cmp r0, 0
	beq _0805DD7E
	bl sub_804AA60
	ldr r0, _0805DDD4
	strb r4, [r0]
	bl ResetRepeatTimers
	bl ResetUnusedInputStruct
_0805DD7E:
	ldr r2, _0805DDC8
	ldrh r0, [r2]
	movs r5, 0x80
	lsls r5, 2
	adds r1, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0805DDA4
	ldrh r1, [r2, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805DDA4
	bl sub_80532B4
	bl ResetRepeatTimers
	bl ResetUnusedInputStruct
_0805DDA4:
	movs r4, 0
	ldr r0, _0805DDC8
	ldrh r0, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0805DDFA
	ldr r1, _0805DDD8
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805DDC2
	ldr r0, _0805DDDC
	strh r4, [r0]
_0805DDC2:
	movs r3, 0x1
	strb r3, [r1]
	b _0805DDFE
	.align 2, 0
_0805DDC8: .4byte gRealInputs
_0805DDCC: .4byte 0x00000707
_0805DDD0: .4byte gUnknown_203B46C
_0805DDD4: .4byte gUnknown_202F22D
_0805DDD8: .4byte gUnknown_202F22C
_0805DDDC: .4byte gUnknown_202F22E
_0805DDE0:
	movs r0, 0xB
	bl sub_8044C50
	adds r2, r4, 0x1
	mov r0, r8
	adds r0, 0x48
	movs r1, 0
	strb r2, [r0]
	adds r0, 0x4
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	b _0805DE92
_0805DDFA:
	ldr r0, _0805DEF8
	strb r4, [r0]
_0805DDFE:
	movs r3, 0
	ldr r0, _0805DEFC
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	bne _0805DE2C
	ldr r2, _0805DF00
	ldrh r0, [r2, 0x6]
	movs r5, 0x80
	lsls r5, 1
	adds r1, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0805DE2A
	mov r0, r9
	cmp r0, 0
	bne _0805DE2A
	ldrh r1, [r2, 0x2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0805DE2C
_0805DE2A:
	movs r3, 0x1
_0805DE2C:
	cmp r3, 0
	beq _0805DE54
	mov r0, r10
	bl sub_805E738
	ldr r0, _0805DF04
	movs r1, 0x1
	strb r1, [r0]
	mov r0, r8
	adds r0, 0x46
	ldrb r0, [r0]
	ldr r1, [sp, 0x10]
	adds r1, 0x33
	strb r0, [r1]
	ldr r1, [sp, 0x10]
	adds r1, 0x34
	movs r0, 0xFF
	strb r0, [r1]
	bl ResetRepeatTimers
_0805DE54:
	ldr r0, _0805DF00
	ldr r1, [r0]
	ldr r0, _0805DF08
	ands r1, r0
	cmp r1, r0
	bne _0805DE62
	movs r4, 0x1
_0805DE62:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805DE6C
	movs r4, 0x1
_0805DE6C:
	cmp r4, 0
	beq _0805DE9C
	movs r4, 0
	ldr r0, _0805DF0C
	ldr r2, [r0]
	movs r3, 0x10
_0805DE78:
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805DE8A
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0805DDE0
_0805DE8A:
	adds r2, 0x4
	adds r4, 0x1
	cmp r4, 0x13
	ble _0805DE78
_0805DE92:
	ldr r2, [sp, 0x1C]
	ldrh r0, [r2]
	cmp r0, 0
	beq _0805DE9C
	b _0805E1AE
_0805DE9C:
	ldr r5, _0805DF10
	ldr r3, [r5]
	ldr r1, _0805DF14
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805DF82
	ldr r0, _0805DEFC
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	cmp r0, 0x6
	beq _0805DF82
	ldr r0, _0805DF00
	ldrh r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805DF82
	ldrb r4, [r2, 0x4]
	ldr r0, _0805DF18
	movs r2, 0x1
	strb r2, [r0]
	ldr r5, _0805DF1C
	adds r0, r3, r5
	strb r2, [r0]
	bl sub_8094C48
	lsls r0, 24
	cmp r0, 0
	bne _0805DEDC
	bl sub_8094C88
_0805DEDC:
	movs r0, 0x1
	bl sub_8052210
	bl sub_8040A84
	movs r0, 0x1E
	bl SetBGOBJEnableFlags
	movs r0, 0xA
	movs r1, 0x2F
	bl sub_803E708
	b _0805DF3A
	.align 2, 0
_0805DEF8: .4byte gUnknown_202F22C
_0805DEFC: .4byte gUnknown_203B46C
_0805DF00: .4byte gRealInputs
_0805DF04: .4byte gUnknown_202F22D
_0805DF08: .4byte 0x01000200
_0805DF0C: .4byte gTeamInventory_203B460
_0805DF10: .4byte gDungeonGlobalData
_0805DF14: .4byte 0x0001820a
_0805DF18: .4byte gUnknown_202EE00
_0805DF1C: .4byte 0x00018214
_0805DF20:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805DF3A
	ldr r2, _0805DFA0
	movs r1, 0
	ldrb r0, [r2]
	cmp r0, 0
	bne _0805DF34
	movs r1, 0x1
_0805DF34:
	strb r1, [r2]
	bl sub_8040A84
_0805DF3A:
	movs r0, 0x2F
	bl sub_803E46C
	ldr r0, _0805DFA4
	ldrh r1, [r0, 0x2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _0805DF54
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805DF20
_0805DF54:
	ldr r1, _0805DFA8
	ldr r0, [r1]
	ldr r2, _0805DFAC
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	ldr r0, _0805DFB0
	ldr r0, [r0]
	strb r4, [r0, 0x4]
	ldr r0, _0805DFA0
	movs r3, 0x1
	strb r3, [r0]
	bl sub_8040A84
	movs r0, 0
	bl SetBGOBJEnableFlags
	movs r0, 0x2F
	bl sub_803E46C
	movs r0, 0x2F
	bl sub_803E46C
_0805DF82:
	ldr r5, _0805DFA8
	ldr r0, [r5]
	ldr r1, _0805DFB4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805DFBC
	ldr r0, _0805DFB8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805DFBC
	ldr r0, _0805DFA4
	ldrh r2, [r0, 0x2]
	adds r1, r2, 0
	b _0805DFCC
	.align 2, 0
_0805DFA0: .4byte gUnknown_202EE00
_0805DFA4: .4byte gRealInputs
_0805DFA8: .4byte gDungeonGlobalData
_0805DFAC: .4byte 0x00018214
_0805DFB0: .4byte gUnknown_203B46C
_0805DFB4: .4byte 0x0000066d
_0805DFB8: .4byte gUnknown_202F22C
_0805DFBC:
	ldr r3, _0805E05C
	ldrh r1, [r3]
	ldr r2, [sp, 0x18]
	ldrb r0, [r2]
	adds r2, r1, 0
	cmp r0, 0
	beq _0805DFCC
	ldrh r2, [r3, 0x2]
_0805DFCC:
	movs r0, 0xF0
	ands r1, r0
	ands r2, r0
	movs r5, 0x1
	negs r5, r5
	cmp r1, 0x50
	bne _0805DFDC
	movs r5, 0x3
_0805DFDC:
	cmp r1, 0x60
	bne _0805DFE2
	movs r5, 0x5
_0805DFE2:
	cmp r1, 0x90
	bne _0805DFE8
	movs r5, 0x1
_0805DFE8:
	cmp r1, 0xA0
	bne _0805DFEE
	movs r5, 0x7
_0805DFEE:
	cmp r2, 0x40
	bne _0805DFF4
	movs r5, 0x4
_0805DFF4:
	cmp r2, 0x80
	bne _0805DFFA
	movs r5, 0
_0805DFFA:
	cmp r2, 0x10
	bne _0805E000
	movs r5, 0x2
_0805E000:
	cmp r2, 0x20
	bne _0805E006
	movs r5, 0x6
_0805E006:
	cmp r5, 0
	bge _0805E00C
	b _0805E1A0
_0805E00C:
	ldr r0, _0805E060
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805E020
	adds r0, r5, 0
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	bne _0805E020
	b _0805E1A0
_0805E020:
	mov r2, r8
	adds r2, 0x46
	ldrb r1, [r2]
	eors r1, r5
	negs r0, r1
	orrs r0, r1
	lsrs r7, r0, 31
	movs r1, 0x7
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
	ldr r0, _0805E064
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805E068
	ldr r0, [sp, 0x10]
	adds r0, 0x33
	strb r5, [r0]
	mov r0, r10
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r10
	adds r2, r5, 0
	bl sub_806CDD4
	b _0805E1A0
	.align 2, 0
_0805E05C: .4byte gRealInputs
_0805E060: .4byte gUnknown_202F22C
_0805E064: .4byte gUnknown_202F22D
_0805E068:
	movs r4, 0
	movs r3, 0
	mov r0, r10
	movs r1, 0x1
	str r3, [sp, 0x20]
	bl sub_805EC4C
	lsls r0, 24
	ldr r3, [sp, 0x20]
	cmp r0, 0
	beq _0805E080
	b _0805E1AE
_0805E080:
	mov r0, r8
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0805E094
	ldr r0, _0805E090
	b _0805E0BE
	.align 2, 0
_0805E090: .4byte gUnknown_80F8A84
_0805E094:
	cmp r0, 0x7
	bne _0805E0A0
	ldr r0, _0805E09C
	b _0805E0BE
	.align 2, 0
_0805E09C: .4byte gUnknown_80F8A6C
_0805E0A0:
	cmp r0, 0x5
	bne _0805E0AC
	ldr r0, _0805E0A8
	b _0805E0BE
	.align 2, 0
_0805E0A8: .4byte gUnknown_80F8AB0
_0805E0AC:
	cmp r0, 0x3
	bne _0805E0B8
	ldr r0, _0805E0B4
	b _0805E0BE
	.align 2, 0
_0805E0B4: .4byte gUnknown_80F8ADC
_0805E0B8:
	cmp r0, 0x4
	bne _0805E0C2
	ldr r0, _0805E128
_0805E0BE:
	ldr r3, [r0]
	movs r4, 0x1
_0805E0C2:
	mov r0, r10
	adds r1, r5, 0
	str r3, [sp, 0x20]
	bl sub_8070D6C
	lsls r0, 24
	ldr r3, [sp, 0x20]
	cmp r0, 0
	bne _0805E0D8
	movs r0, 0x2
	orrs r4, r0
_0805E0D8:
	cmp r7, 0
	beq _0805E0F4
	mov r0, r10
	str r3, [sp, 0x20]
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r10
	adds r2, r5, 0
	bl sub_806CDD4
	ldr r3, [sp, 0x20]
_0805E0F4:
	movs r7, 0x2
	adds r0, r4, 0
	ands r0, r7
	cmp r0, 0
	bne _0805E192
	movs r5, 0x1
	mov r9, r5
	ands r5, r4
	cmp r5, 0
	beq _0805E134
	cmp r3, 0
	beq _0805E114
	mov r0, r10
	adds r1, r3, 0
	bl SendMessage
_0805E114:
	movs r0, 0x1
	bl sub_8044C50
	ldr r1, _0805E12C
	ldr r0, [r1]
	ldr r2, _0805E130
	adds r0, r2
	mov r3, r9
	strb r3, [r0]
	b _0805E1AE
	.align 2, 0
_0805E128: .4byte gUnknown_80F8B0C
_0805E12C: .4byte gDungeonGlobalData
_0805E130: .4byte 0x00000673
_0805E134:
	movs r0, 0x2
	bl sub_8044C50
	ldr r0, _0805E17C
	ldrh r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _0805E14C
	movs r0, 0
	cmp r0, 0
	beq _0805E188
_0805E14C:
	movs r0, 0x9E
	lsls r0, 1
	add r0, r8
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0
	beq _0805E188
	mov r1, r10
	ldr r0, [r1, 0x70]
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0805E174
	ldr r2, _0805E180
	ldr r0, [r2]
	ldr r3, _0805E184
	adds r0, r3
	mov r1, r9
	strb r1, [r0]
_0805E174:
	mov r0, r8
	adds r0, 0x48
	strb r5, [r0]
	b _0805E1AE
	.align 2, 0
_0805E17C: .4byte gRealInputs
_0805E180: .4byte gDungeonGlobalData
_0805E184: .4byte 0x0000066c
_0805E188:
	mov r0, r8
	adds r0, 0x48
	movs r2, 0x1
	strb r2, [r0]
	b _0805E1AE
_0805E192:
	movs r3, 0x1
	ands r4, r3
	cmp r4, 0
	beq _0805E1A0
	movs r0, 0x23
	bl sub_803E724
_0805E1A0:
	movs r0, 0xF
	bl sub_803E46C
	ldr r5, [sp, 0x14]
	cmp r5, 0
	bne _0805E1AE
	b _0805DB24
_0805E1AE:
	ldr r1, [sp, 0x18]
	ldrb r0, [r1]
	cmp r0, 0
	beq _0805E1BA
	bl sub_804AA60
_0805E1BA:
	ldr r4, [sp, 0x1C]
	ldrh r0, [r4]
	cmp r0, 0x2D
	beq _0805E1C6
	cmp r0, 0x13
	bne _0805E1E0
_0805E1C6:
	mov r0, r10
	bl sub_8067510
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0805E2B0
	movs r0, 0
	bl sub_8044C50
	bl _0805D980
_0805E1E0:
	lsls r0, r6, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0805E222
	ldr r2, _0805E210
	ldr r0, [r2]
	ldr r3, _0805E214
	adds r0, r3
	strb r1, [r0]
	ldrh r0, [r4]
	cmp r0, 0
	beq _0805E218
	mov r0, r10
	movs r1, 0
	bl sub_8045028
	lsls r0, 24
	cmp r0, 0
	bne _0805E2B0
	movs r0, 0xF
	bl sub_803E46C
	b _0805E2B0
	.align 2, 0
_0805E210: .4byte gDungeonGlobalData
_0805E214: .4byte 0x0000066d
_0805E218:
	movs r0, 0xF
	bl sub_803E46C
	bl _0805D980
_0805E222:
	movs r0, 0xF
	bl sub_803E46C
	bl sub_8047158
	movs r2, 0
	lsrs r0, r6, 8
	lsls r0, 24
	cmp r0, 0
	bne _0805E238
	movs r2, 0x1
_0805E238:
	lsrs r1, r6, 16
	lsls r1, 24
	lsrs r1, 24
	adds r0, r2, 0
	bl ShowFieldMenu
	bl ResetRepeatTimers
	bl ResetUnusedInputStruct
	ldr r1, _0805E294
	movs r0, 0
	strb r0, [r1]
	movs r0, 0
	ldr r5, [sp, 0x18]
	strb r0, [r5]
	bl sub_804AA60
	bl sub_8044B28
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0805E2B0
	ldrh r0, [r4]
	cmp r0, 0
	beq _0805E29C
	cmp r0, 0x2B
	bne _0805E27E
	ldr r2, _0805E298
	ldr r0, [r2]
	movs r3, 0x1
	strb r3, [r0, 0x4]
	ldr r0, [r2]
	strb r3, [r0, 0x3]
_0805E27E:
	ldr r5, [sp, 0x1C]
	ldrh r0, [r5]
	cmp r0, 0x2E
	bne _0805E2B0
	ldr r2, _0805E298
	ldr r0, [r2]
	movs r3, 0x1
	strb r3, [r0, 0x4]
	ldr r0, [r2]
	strb r1, [r0, 0x3]
	b _0805E2B0
	.align 2, 0
_0805E294: .4byte gUnknown_202F22D
_0805E298: .4byte gDungeonGlobalData
_0805E29C:
	movs r0, 0xF
	bl sub_803E46C
	ldr r5, _0805E2C0
	ldr r0, [r5]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _0805E2B0
	bl _0805D980
_0805E2B0:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805E2C0: .4byte gDungeonGlobalData
	thumb_func_end sub_805D8C8

	thumb_func_start sub_805E2C4
sub_805E2C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	str r0, [sp, 0x10]
	ldr r0, _0805E47C
	ldr r1, [r0]
	ldr r0, _0805E480
	adds r0, r1, r0
	str r0, [sp, 0x14]
	ldr r0, _0805E484
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805E2E6
	b _0805E4C4
_0805E2E6:
	movs r1, 0
	str r1, [sp, 0x18]
	mov r7, sp
	ldr r2, _0805E488
	mov r10, r2
_0805E2F0:
	ldrh r0, [r7]
	ldr r3, _0805E48C
	adds r1, r3, 0
	ands r1, r0
	ldr r0, [sp]
	mov r4, r10
	ands r0, r4
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r7]
	mov r2, r10
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	ldrh r0, [r7]
	ldr r5, _0805E490
	adds r1, r5, 0
	ands r1, r0
	mov r0, r10
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r2, [r7]
	mov r1, r10
	ands r1, r0
	orrs r1, r2
	str r1, [sp]
	ldrh r2, [r7]
	ldr r0, _0805E494
	ands r0, r2
	mov r3, r10
	ands r3, r1
	orrs r3, r0
	str r3, [sp]
	ldrh r1, [r7]
	movs r0, 0x80
	lsls r0, 3
	orrs r0, r1
	movs r6, 0
	orrs r0, r6
	mov r2, r10
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldrh r0, [r7]
	ldr r3, _0805E498
	adds r1, r3, 0
	ands r1, r0
	mov r0, r10
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r7]
	mov r2, r10
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	ldrh r0, [r7]
	ldr r4, _0805E49C
	adds r1, r4, 0
	ands r1, r0
	mov r0, r10
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r7]
	mov r2, r10
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	ldrh r1, [r7]
	ldr r0, _0805E4A0
	ands r0, r1
	mov r1, r10
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r2, [r7]
	mov r0, r10
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldr r1, _0805E4A4
	ldr r5, [sp, 0x18]
	lsls r0, r5, 3
	adds r0, r1
	mov r12, r0
	ldrb r1, [r0, 0x4]
	negs r0, r1
	orrs r0, r1
	asrs r1, r0, 31
	movs r0, 0x8
	ands r1, r0
	mov r6, r12
	ldrb r0, [r6, 0x5]
	cmp r0, 0
	beq _0805E3B4
	adds r1, 0x10
_0805E3B4:
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 9
	ldrh r3, [r7, 0x2]
	ldr r2, _0805E4A8
	adds r0, r2, 0
	ands r3, r0
	orrs r3, r1
	ldr r4, _0805E4A0
	ands r3, r4
	strh r3, [r7, 0x2]
	ldr r2, _0805E4AC
	ldrh r0, [r7, 0x4]
	movs r5, 0xFC
	lsls r5, 8
	adds r1, r5, 0
	ands r0, r1
	orrs r0, r2
	movs r6, 0
	orrs r0, r6
	movs r1, 0x80
	lsls r1, 4
	ldr r2, _0805E494
	ands r0, r2
	orrs r0, r1
	orrs r0, r6
	ldr r4, _0805E4B0
	mov r9, r4
	ands r0, r4
	strh r0, [r7, 0x4]
	ldrh r4, [r7, 0x6]
	ldr r5, _0805E4B4
	adds r0, r5, 0
	ands r4, r0
	ldr r6, _0805E4B8
	adds r0, r6, 0
	ands r4, r0
	strh r4, [r7, 0x6]
	mov r0, r12
	movs r1, 0
	ldrsh r5, [r0, r1]
	lsls r2, r5, 2
	adds r2, r5
	lsls r2, 1
	ldr r6, _0805E4BC
	mov r8, r6
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r6, 0x7
	ands r0, r6
	muls r0, r5
	adds r0, r2
	adds r0, 0x74
	ldr r1, _0805E4C0
	ands r0, r1
	movs r2, 0xFE
	lsls r2, 8
	adds r1, r2, 0
	ands r3, r1
	orrs r3, r0
	strh r3, [r7, 0x2]
	mov r5, r12
	movs r0, 0x2
	ldrsh r3, [r5, r0]
	lsls r2, r3, 2
	adds r2, r3
	lsls r2, 1
	mov r1, r8
	movs r5, 0
	ldrsh r0, [r1, r5]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	ands r0, r6
	muls r0, r3
	adds r0, r2
	adds r0, 0x52
	mov r6, r9
	ands r0, r6
	lsls r0, 4
	movs r1, 0xF
	ands r4, r1
	orrs r4, r0
	strh r4, [r7, 0x6]
	mov r0, sp
	adds r1, 0xF1
	movs r2, 0
	movs r3, 0
	bl AddSprite
	ldr r2, [sp, 0x18]
	adds r2, 0x1
	str r2, [sp, 0x18]
	cmp r2, 0x3
	bgt _0805E47A
	b _0805E2F0
_0805E47A:
	b _0805E6AC
	.align 2, 0
_0805E47C: .4byte gDungeonGlobalData
_0805E480: .4byte 0x000181e8
_0805E484: .4byte gUnknown_202F22C
_0805E488: .4byte 0xffff0000
_0805E48C: .4byte 0x0000feff
_0805E490: .4byte 0x0000fdff
_0805E494: .4byte 0x0000f3ff
_0805E498: .4byte 0x0000efff
_0805E49C: .4byte 0x0000dfff
_0805E4A0: .4byte 0x00003fff
_0805E4A4: .4byte gUnknown_8106AC8
_0805E4A8: .4byte 0x0000c1ff
_0805E4AC: .4byte 0x00000213
_0805E4B0: .4byte 0x00000fff
_0805E4B4: .4byte 0x0000fffe
_0805E4B8: .4byte 0x0000fffd
_0805E4BC: .4byte gUnknown_202F22E
_0805E4C0: .4byte 0x000001ff
_0805E4C4:
	ldr r3, _0805E6E4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805E4D0
	b _0805E6AC
_0805E4D0:
	ldr r4, _0805E6E8
	adds r0, r1, r4
	ldrb r0, [r0]
	str r0, [sp, 0x1C]
	cmp r0, 0x7
	bls _0805E4DE
	b _0805E6AC
_0805E4DE:
	ldr r0, _0805E6EC
	ldrb r0, [r0]
	movs r7, 0x1
	cmp r0, 0
	beq _0805E4F2
	ldr r0, _0805E6F0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805E4F2
	movs r7, 0x3
_0805E4F2:
	ldr r5, _0805E6F4
	mov r12, r5
	ldr r6, [sp, 0x1C]
	lsls r5, r6, 1
	adds r3, r5, r6
	lsls r3, 2
	add r3, r12
	movs r0, 0
	ldrsh r4, [r3, r0]
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 1
	ldr r0, _0805E6F8
	movs r6, 0
	ldrsh r2, [r0, r6]
	lsrs r0, r2, 31
	adds r2, r0
	asrs r2, 1
	movs r0, 0x7
	ands r2, r0
	adds r0, r4, 0
	muls r0, r2
	adds r0, r1
	adds r0, 0x74
	str r0, [sp, 0x20]
	movs r1, 0x2
	ldrsh r0, [r3, r1]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	muls r0, r2
	adds r0, r1
	adds r0, 0x52
	mov r10, r0
	str r5, [sp, 0x24]
	cmp r7, 0
	bne _0805E53E
	b _0805E6AC
_0805E53E:
	add r6, sp, 0x8
	ldr r2, _0805E6FC
	mov r8, r2
	mov r9, r7
_0805E546:
	ldrh r0, [r6]
	ldr r3, _0805E700
	adds r1, r3, 0
	ands r1, r0
	ldr r0, [sp, 0x8]
	mov r4, r8
	ands r0, r4
	orrs r0, r1
	str r0, [sp, 0x8]
	ldrh r1, [r6]
	mov r2, r8
	ands r2, r0
	orrs r2, r1
	str r2, [sp, 0x8]
	ldrh r0, [r6]
	ldr r5, _0805E704
	adds r1, r5, 0
	ands r1, r0
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x8]
	ldrh r2, [r6]
	mov r1, r8
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0x8]
	ldrh r2, [r6]
	ldr r0, _0805E708
	ands r0, r2
	mov r3, r8
	ands r3, r1
	orrs r3, r0
	str r3, [sp, 0x8]
	ldrh r1, [r6]
	movs r0, 0x80
	lsls r0, 3
	orrs r0, r1
	movs r1, 0
	orrs r0, r1
	mov r2, r8
	ands r2, r3
	orrs r2, r0
	str r2, [sp, 0x8]
	ldrh r0, [r6]
	ldr r3, _0805E70C
	adds r1, r3, 0
	ands r1, r0
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x8]
	ldrh r1, [r6]
	mov r2, r8
	ands r2, r0
	orrs r2, r1
	str r2, [sp, 0x8]
	ldrh r0, [r6]
	ldr r4, _0805E710
	adds r1, r4, 0
	ands r1, r0
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x8]
	ldrh r1, [r6]
	mov r2, r8
	ands r2, r0
	orrs r2, r1
	str r2, [sp, 0x8]
	ldrh r1, [r6]
	ldr r0, _0805E714
	ands r0, r1
	mov r1, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x8]
	ldrh r2, [r6]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x8]
	ldr r5, [sp, 0x24]
	ldr r1, [sp, 0x1C]
	adds r0, r5, r1
	lsls r2, r0, 2
	ldr r3, _0805E6F4
	adds r7, r2, r3
	ldrb r1, [r7, 0x8]
	negs r0, r1
	orrs r0, r1
	asrs r1, r0, 31
	movs r0, 0x8
	ands r1, r0
	ldrb r0, [r7, 0x9]
	cmp r0, 0
	beq _0805E60A
	adds r1, 0x10
_0805E60A:
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 9
	ldrh r3, [r6, 0x2]
	ldr r4, _0805E718
	adds r0, r4, 0
	ands r3, r0
	orrs r3, r1
	ldr r5, _0805E714
	ands r3, r5
	strh r3, [r6, 0x2]
	ldr r1, _0805E71C
	adds r0, r2, r1
	ldr r2, [r0]
	ldr r0, _0805E720
	ands r2, r0
	ldrh r0, [r6, 0x4]
	movs r4, 0xFC
	lsls r4, 8
	adds r1, r4, 0
	ands r0, r1
	orrs r0, r2
	movs r1, 0x80
	lsls r1, 4
	ldr r5, _0805E708
	ands r0, r5
	orrs r0, r1
	movs r1, 0
	orrs r0, r1
	movs r2, 0xF
	mov r12, r2
	ldr r4, _0805E724
	ands r0, r4
	strh r0, [r6, 0x4]
	ldrh r1, [r6, 0x6]
	ldr r5, _0805E728
	adds r0, r5, 0
	ands r1, r0
	ldr r2, _0805E72C
	adds r0, r2, 0
	ands r1, r0
	ldr r0, _0805E730
	ldr r5, [sp, 0x20]
	ands r0, r5
	movs r5, 0xFE
	lsls r5, 8
	adds r2, r5, 0
	ands r3, r2
	orrs r3, r0
	strh r3, [r6, 0x2]
	mov r0, r10
	ands r0, r4
	lsls r0, 4
	mov r2, r12
	ands r1, r2
	orrs r1, r0
	strh r1, [r6, 0x6]
	adds r0, r6, 0
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0
	movs r3, 0
	bl AddSprite
	movs r3, 0
	ldrsh r0, [r7, r3]
	lsls r0, 2
	ldr r4, [sp, 0x20]
	adds r4, r0
	str r4, [sp, 0x20]
	movs r5, 0x2
	ldrsh r0, [r7, r5]
	lsls r0, 2
	add r10, r0
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	beq _0805E6AC
	b _0805E546
_0805E6AC:
	ldr r4, _0805E734
	ldrb r0, [r4]
	cmp r0, 0
	beq _0805E6D4
	ldr r2, [sp, 0x14]
	adds r2, 0x34
	ldr r3, [sp, 0x14]
	adds r3, 0x33
	ldrb r1, [r3]
	ldrb r0, [r2]
	cmp r0, r1
	beq _0805E6D4
	strb r1, [r2]
	ldr r0, [sp, 0x10]
	adds r0, 0x4
	ldrb r1, [r3]
	ldrb r3, [r4]
	movs r2, 0
	bl sub_804A728
_0805E6D4:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805E6E4: .4byte 0x0001821a
_0805E6E8: .4byte 0x0001821b
_0805E6EC: .4byte gUnknown_202F231
_0805E6F0: .4byte gUnknown_202F230
_0805E6F4: .4byte gUnknown_8106AE8
_0805E6F8: .4byte gUnknown_202F22E
_0805E6FC: .4byte 0xffff0000
_0805E700: .4byte 0x0000feff
_0805E704: .4byte 0x0000fdff
_0805E708: .4byte 0x0000f3ff
_0805E70C: .4byte 0x0000efff
_0805E710: .4byte 0x0000dfff
_0805E714: .4byte 0x00003fff
_0805E718: .4byte 0x0000c1ff
_0805E71C: .4byte gUnknown_8106AEC
_0805E720: .4byte 0x000003ff
_0805E724: .4byte 0x00000fff
_0805E728: .4byte 0x0000fffe
_0805E72C: .4byte 0x0000fffd
_0805E730: .4byte 0x000001ff
_0805E734: .4byte gUnknown_202F22D
	thumb_func_end sub_805E2C4

	thumb_func_start sub_805E738
sub_805E738:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	ldr r1, [r6, 0x70]
	adds r0, r1, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _0805E7F6
	movs r0, 0
	mov r8, r0
	adds r1, 0x46
	mov r10, r1
_0805E75E:
	movs r1, 0
	mov r9, r1
	mov r3, r10
	ldrb r5, [r3]
	adds r5, 0x1
	movs r7, 0x1
_0805E76A:
	movs r0, 0x7
	ands r5, r0
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	ldr r1, _0805E7E8
	lsls r2, r5, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0805E7B8
	bl sub_80450F8
	cmp r0, 0x1
	bne _0805E7B8
	ldr r1, [r4, 0x10]
	ldr r4, [r1, 0x70]
	adds r0, r6, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0805E7B8
	mov r0, r8
	cmp r0, 0
	bne _0805E7C6
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _0805E7C6
_0805E7B8:
	adds r7, 0x1
	adds r5, 0x1
	cmp r7, 0x7
	ble _0805E76A
	mov r1, r9
	cmp r1, 0
	beq _0805E7EC
_0805E7C6:
	ldr r1, [r6, 0x70]
	movs r2, 0x7
	adds r0, r5, 0
	ands r0, r2
	adds r1, 0x46
	strb r0, [r1]
	adds r0, r6, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	adds r2, r5, 0
	bl sub_806CDD4
	b _0805E7F6
	.align 2, 0
_0805E7E8: .4byte gUnknown_80F4448
_0805E7EC:
	movs r3, 0x1
	add r8, r3
	mov r0, r8
	cmp r0, 0
	ble _0805E75E
_0805E7F6:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_805E738

	thumb_func_start sub_805E804
sub_805E804:
	push {r4,r5,lr}
	ldr r2, _0805E864
	ldr r1, [r2]
	ldr r5, _0805E868
	adds r3, r1, r5
	ldr r4, _0805E86C
	adds r1, r4
	ldrb r0, [r3]
	ldrb r1, [r1]
	orrs r0, r1
	movs r1, 0
	strb r0, [r3]
	ldr r0, [r2]
	adds r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805E85C
	ldr r0, _0805E870
	ldrh r1, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0805E85C
	adds r4, r2, 0
_0805E83E:
	movs r0, 0x54
	bl sub_803E46C
	ldr r0, _0805E864
	ldr r0, [r0]
	ldr r1, _0805E868
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805E85C
	ldr r0, _0805E870
	ldrh r0, [r0]
	ands r0, r4
	cmp r0, 0
	bne _0805E83E
_0805E85C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805E864: .4byte gDungeonGlobalData
_0805E868: .4byte 0x0000066d
_0805E86C: .4byte 0x0000066c
_0805E870: .4byte gRealInputs
	thumb_func_end sub_805E804

	thumb_func_start sub_805E874
sub_805E874:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r0, _0805E90C
	ldr r4, [r0]
	bl sub_8083600
	mov r9, r0
	ldr r0, [r0, 0x70]
	adds r0, 0x46
	ldrb r0, [r0]
	str r0, [sp, 0x18]
	mov r0, r9
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	mov r10, r0
	mov r2, r9
	movs r3, 0x6
	ldrsh r2, [r2, r3]
	str r2, [sp, 0x1C]
	adds r1, r2, 0
	bl sub_804954C
	adds r5, r0, 0
	ldr r1, _0805E910
	ldr r2, [sp, 0x18]
	lsls r0, r2, 2
	adds r0, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r2, r10
	adds r7, r2, r1
	movs r3, 0x2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, 0x1C]
	adds r6, r1, r0
	ldr r2, _0805E914
	adds r4, r2
	ldrb r0, [r4]
	cmp r0, 0
	beq _0805E906
	ldr r0, [r5, 0x14]
	cmp r0, 0
	bne _0805E906
	mov r0, r9
	mov r1, r10
	ldr r2, [sp, 0x1C]
	bl sub_805EC2C
	lsls r0, 24
	cmp r0, 0
	bne _0805E906
	mov r0, r9
	ldr r1, [sp, 0x18]
	bl sub_8070F14
	lsls r0, 24
	cmp r0, 0
	beq _0805E906
	ldrb r3, [r5, 0x9]
	str r3, [sp, 0x20]
	cmp r3, 0xFF
	bne _0805E918
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_804954C
	ldrb r0, [r0, 0x9]
	cmp r0, 0xFF
	beq _0805E922
_0805E906:
	movs r0, 0
	b _0805EC1A
	.align 2, 0
_0805E90C: .4byte gDungeonGlobalData
_0805E910: .4byte gUnknown_80F4448
_0805E914: .4byte 0x0000066c
_0805E918:
	ldrh r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0805E906
_0805E922:
	movs r4, 0x1
	negs r4, r4
	ldr r7, _0805EA54
	movs r5, 0x80
	lsls r5, 2
	adds r6, r5, 0
_0805E92E:
	ldr r0, [sp, 0x18]
	adds r1, r0, r4
	movs r5, 0x7
	ands r1, r5
	lsls r1, 2
	adds r1, r7
	movs r2, 0
	ldrsh r0, [r1, r2]
	add r0, r10
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	ldr r2, [sp, 0x1C]
	adds r1, r2, r1
	bl sub_804954C
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	cmp r0, 0
	bne _0805E906
	ldrh r0, [r1]
	ands r0, r6
	cmp r0, 0
	bne _0805E906
	adds r4, 0x1
	cmp r4, 0x1
	ble _0805E92E
	ldr r4, _0805EA54
	ldr r3, [sp, 0x18]
	adds r3, 0x3
	ands r3, r5
	lsls r3, 2
	adds r3, r4
	movs r1, 0
	ldrsh r0, [r3, r1]
	add r0, r10
	str r0, [sp]
	ldr r2, [sp, 0x18]
	adds r2, 0x4
	ands r2, r5
	lsls r2, 2
	adds r2, r4
	movs r1, 0
	ldrsh r0, [r2, r1]
	add r0, r10
	str r0, [sp, 0x4]
	ldr r1, [sp, 0x18]
	adds r1, 0x5
	ands r1, r5
	lsls r1, 2
	adds r1, r4
	movs r4, 0
	ldrsh r0, [r1, r4]
	add r0, r10
	str r0, [sp, 0x8]
	add r4, sp, 0xC
	movs r5, 0x2
	ldrsh r0, [r3, r5]
	ldr r3, [sp, 0x1C]
	adds r0, r3, r0
	str r0, [sp, 0xC]
	movs r5, 0x2
	ldrsh r0, [r2, r5]
	adds r0, r3, r0
	str r0, [r4, 0x4]
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	adds r0, r3, r0
	str r0, [r4, 0x8]
	movs r3, 0x1
	negs r3, r3
	mov r8, r3
_0805E9BC:
	movs r4, 0x1
	negs r4, r4
	mov r7, r10
	add r7, r8
	ldr r6, [sp, 0x1C]
	subs r6, 0x1
_0805E9C8:
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_804954C
	adds r5, r0, 0
	ldr r0, [r5, 0x14]
	cmp r0, 0
	beq _0805EA14
	movs r2, 0
	ldr r0, [sp]
	cmp r7, r0
	bne _0805E9E6
	ldr r0, [sp, 0xC]
	cmp r6, r0
	beq _0805EA04
_0805E9E6:
	adds r2, 0x1
	cmp r2, 0x2
	bgt _0805EA04
	lsls r1, r2, 2
	mov r3, sp
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r7, r0
	bne _0805E9E6
	mov r0, sp
	adds r0, r1
	adds r0, 0xC
	ldr r0, [r0]
	cmp r6, r0
	bne _0805E9E6
_0805EA04:
	cmp r2, 0x3
	bne _0805EA14
	ldr r0, [r5, 0x14]
	bl sub_80450F8
	cmp r0, 0x3
	bne _0805EA14
	b _0805E906
_0805EA14:
	movs r0, 0x1
	ldr r1, [sp, 0x18]
	ands r0, r1
	cmp r0, 0
	beq _0805EA60
	ldr r0, [r5, 0x14]
	cmp r0, 0
	beq _0805EA94
	bl sub_80450F8
	cmp r0, 0x2
	bne _0805EA94
	ldr r0, [r5, 0x14]
	bl sub_80450F8
	cmp r0, 0x2
	bne _0805EA94
	ldr r0, [r5, 0x14]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805EA42
	b _0805E906
_0805EA42:
	ldr r0, _0805EA58
	ldr r0, [r0]
	ldr r2, _0805EA5C
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805EA94
	b _0805E906
	.align 2, 0
_0805EA54: .4byte gUnknown_80F4448
_0805EA58: .4byte gDungeonGlobalData
_0805EA5C: .4byte 0x0001820f
_0805EA60:
	mov r3, r8
	cmp r3, 0
	beq _0805EA6A
	cmp r4, 0
	bne _0805EA94
_0805EA6A:
	ldr r0, [r5, 0x14]
	cmp r0, 0
	beq _0805EA94
	bl sub_80450F8
	cmp r0, 0x2
	bne _0805EA94
	ldr r0, [r5, 0x14]
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805EA84
	b _0805E906
_0805EA84:
	ldr r0, _0805EAA0
	ldr r0, [r0]
	ldr r1, _0805EAA4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805EA94
	b _0805E906
_0805EA94:
	mov r2, r8
	cmp r2, 0
	beq _0805EAA8
	cmp r4, 0
	bne _0805EAD6
	b _0805EAAC
	.align 2, 0
_0805EAA0: .4byte gDungeonGlobalData
_0805EAA4: .4byte 0x0001820f
_0805EAA8:
	cmp r4, 0
	beq _0805EAD6
_0805EAAC:
	ldr r0, [sp, 0x4]
	cmp r0, r7
	bne _0805EAB8
	ldr r0, [sp, 0x10]
	cmp r0, r6
	beq _0805EAD6
_0805EAB8:
	mov r0, r9
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_805EC2C
	lsls r0, 24
	cmp r0, 0
	bne _0805EAD6
	ldr r3, [sp, 0x20]
	cmp r3, 0xFF
	beq _0805EAD6
	ldrb r5, [r5, 0x9]
	cmp r3, r5
	beq _0805EAD6
	b _0805E906
_0805EAD6:
	adds r6, 0x1
	adds r4, 0x1
	cmp r4, 0x1
	bgt _0805EAE0
	b _0805E9C8
_0805EAE0:
	movs r4, 0x1
	add r8, r4
	mov r5, r8
	cmp r5, 0x1
	bgt _0805EAEC
	b _0805E9BC
_0805EAEC:
	movs r0, 0x1
	ldr r1, [sp, 0x18]
	ands r0, r1
	cmp r0, 0
	beq _0805EAF8
	b _0805EC18
_0805EAF8:
	cmp r1, 0
	beq _0805EB00
	cmp r1, 0x4
	bne _0805EB8C
_0805EB00:
	mov r4, r10
	subs r4, 0x1
	ldr r6, [sp, 0x1C]
	subs r6, 0x1
	mov r0, r9
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	adds r1, r4, 0
	ldr r2, [sp, 0x1C]
	bl sub_805EC2C
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, [sp, 0x1C]
	adds r5, 0x1
	mov r0, r9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	adds r2, r6, 0
	cmp r7, 0
	bne _0805EB4C
	mov r3, r8
	cmp r3, 0
	beq _0805EB46
	b _0805E906
_0805EB46:
	cmp r7, r0
	beq _0805EB4C
	b _0805E906
_0805EB4C:
	mov r4, r10
	adds r4, 0x1
	mov r0, r9
	adds r1, r4, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	adds r1, r4, 0
	ldr r2, [sp, 0x1C]
	bl sub_805EC2C
	lsls r0, 24
	lsrs r7, r0, 24
	mov r0, r9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	cmp r7, 0
	bne _0805EC18
	mov r4, r8
	cmp r4, 0
	beq _0805EB86
	b _0805E906
_0805EB86:
	cmp r7, r0
	beq _0805EC18
	b _0805E906
_0805EB8C:
	mov r6, r10
	subs r6, 0x1
	ldr r4, [sp, 0x1C]
	subs r4, 0x1
	mov r0, r9
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	mov r1, r10
	adds r2, r4, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r7, r0, 24
	mov r5, r10
	adds r5, 0x1
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r6, 0
	cmp r7, 0
	bne _0805EBD8
	mov r2, r8
	cmp r2, 0
	beq _0805EBD2
	b _0805E906
_0805EBD2:
	cmp r7, r0
	beq _0805EBD8
	b _0805E906
_0805EBD8:
	ldr r4, [sp, 0x1C]
	adds r4, 0x1
	mov r0, r9
	adds r2, r4, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, r9
	mov r1, r10
	adds r2, r4, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r7, r0, 24
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_805EC2C
	lsls r0, 24
	lsrs r0, 24
	cmp r7, 0
	bne _0805EC18
	mov r3, r8
	cmp r3, 0
	beq _0805EC12
	b _0805E906
_0805EC12:
	cmp r7, r0
	beq _0805EC18
	b _0805E906
_0805EC18:
	movs r0, 0x1
_0805EC1A:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_805E874

	thumb_func_start sub_805EC2C
sub_805EC2C:
	push {lr}
	sub sp, 0x4
	lsls r1, 16
	lsls r2, 16
	lsrs r1, 16
	orrs r1, r2
	str r1, [sp]
	mov r1, sp
	bl sub_8070564
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_805EC2C

	thumb_func_start sub_805EC4C
sub_805EC4C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	ldr r7, [r5, 0x70]
	ldr r1, _0805ECC8
	adds r0, r7, 0
	adds r0, 0x46
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r3, [r5, 0x4]
	adds r1, r3
	lsls r1, 16
	ldrh r0, [r0, 0x2]
	ldrh r3, [r5, 0x6]
	adds r0, r3
	lsls r0, 16
	lsrs r2, r1, 16
	orrs r2, r0
	lsls r0, r2, 16
	asrs r0, 16
	asrs r1, r2, 16
	bl sub_804954C
	ldr r0, [r0, 0x10]
	mov r8, r0
	cmp r0, 0
	bne _0805EC94
	b _0805ED96
_0805EC94:
	mov r0, r8
	bl sub_80450F8
	cmp r0, 0x1
	bne _0805ED96
	mov r0, r8
	ldr r6, [r0, 0x70]
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0805ECDC
	ldrb r0, [r6, 0x8]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _0805ECDC
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0805ECC2
	cmp r0, 0x47
	bne _0805ECCC
_0805ECC2:
	movs r0, 0x1
	b _0805ECCE
	.align 2, 0
_0805ECC8: .4byte gUnknown_80F4448
_0805ECCC:
	movs r0, 0
_0805ECCE:
	cmp r0, 0
	bne _0805ECDC
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0805ED96
_0805ECDC:
	adds r0, r7, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0805ED96
	cmp r0, 0x1
	beq _0805ED96
	cmp r0, 0x7
	beq _0805ED96
	cmp r0, 0x5
	beq _0805ED96
	cmp r0, 0x3
	beq _0805ED96
	cmp r0, 0x4
	beq _0805ED96
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0805ED96
	cmp r0, 0x1
	beq _0805ED96
	cmp r0, 0x7
	beq _0805ED96
	cmp r0, 0x5
	beq _0805ED96
	cmp r0, 0x3
	beq _0805ED96
	cmp r0, 0x4
	beq _0805ED96
	adds r0, r7, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0805ED96
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0805ED96
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805ED3E
	cmp r0, 0x2
	beq _0805ED3E
	cmp r0, 0x4
	bne _0805ED96
_0805ED3E:
	adds r0, r7, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805ED50
	cmp r0, 0x2
	beq _0805ED50
	cmp r0, 0x4
	bne _0805ED96
_0805ED50:
	mov r0, r8
	movs r1, 0
	bl IsCharging
	lsls r0, 24
	cmp r0, 0
	bne _0805ED96
	adds r4, r7, 0
	adds r4, 0x46
	ldrb r1, [r4]
	adds r0, r5, 0
	bl sub_8070F80
	lsls r0, 24
	mov r9, r4
	cmp r0, 0
	beq _0805ED96
	mov r1, r10
	cmp r1, 0
	beq _0805EDA0
	adds r1, r5, 0x4
	mov r0, r8
	bl sub_807049C
	lsls r0, 24
	cmp r0, 0
	beq _0805EDA0
	ldr r0, _0805ED9C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	cmp r0, 0
	bne _0805EDA0
_0805ED96:
	movs r0, 0
	b _0805EE1E
	.align 2, 0
_0805ED9C: .4byte gUnknown_8100208
_0805EDA0:
	adds r0, r7, 0
	adds r0, 0x44
	movs r1, 0x2
	bl sub_8044C94
	ldr r0, _0805EDC0
	ldrh r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805EDC4
	adds r1, r7, 0
	adds r1, 0x48
	movs r0, 0
	b _0805EDCA
	.align 2, 0
_0805EDC0: .4byte gRealInputs
_0805EDC4:
	adds r1, r7, 0
	adds r1, 0x48
	movs r0, 0x1
_0805EDCA:
	strb r0, [r1]
	ldrh r0, [r7]
	movs r2, 0x80
	lsls r2, 8
	adds r5, r2, 0
	movs r4, 0
	orrs r0, r5
	strh r0, [r7]
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x2
	bl sub_8044C94
	adds r0, r6, 0
	adds r0, 0x48
	strb r4, [r0]
	mov r3, r9
	ldrb r0, [r3]
	adds r0, 0x4
	movs r1, 0x7
	ands r0, r1
	adds r1, r6, 0
	adds r1, 0x46
	strb r0, [r1]
	ldrh r0, [r6]
	orrs r0, r5
	strh r0, [r6]
	mov r0, r8
	ldrh r1, [r0, 0x4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r6, r2
	strh r1, [r0]
	mov r3, r8
	ldrh r0, [r3, 0x6]
	adds r2, 0x2
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _0805EE2C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xE]
_0805EE1E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805EE2C: .4byte gDungeonGlobalData
	thumb_func_end sub_805EC4C

	thumb_func_start sub_805EE30
sub_805EE30:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl sub_8083600
	adds r5, r0, 0
	cmp r5, 0
	bne _0805EE42
	b _0805EF52
_0805EE42:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0805EE4E
	b _0805EF52
_0805EE4E:
	adds r0, r5, 0
	bl sub_8045128
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0xD
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0805EE82
	ldr r0, [r5, 0x70]
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _0805EE82
	adds r0, r5, 0
	movs r1, 0x9
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	bne _0805EE82
	adds r0, r5, 0x4
	bl sub_804AE84
_0805EE82:
	ldrh r1, [r4]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _0805EE96
	ldr r0, _0805EEB0
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x1]
_0805EE96:
	ldr r4, [r4, 0x14]
	cmp r4, 0
	beq _0805EF52
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x5
	bhi _0805EF52
	lsls r0, 2
	ldr r1, _0805EEB4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805EEB0: .4byte gDungeonGlobalData
_0805EEB4: .4byte _0805EEB8
	.align 2, 0
_0805EEB8:
	.4byte _0805EF52
	.4byte _0805EF52
	.4byte _0805EED0
	.4byte _0805EF2A
	.4byte _0805EF52
	.4byte _0805EF52
_0805EED0:
	adds r0, r4, 0
	bl sub_8045104
	adds r6, r0, 0
	movs r0, 0
	mov r8, r0
	movs r7, 0
	adds r0, r5, 0
	movs r1, 0x13
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0805EF00
	adds r1, r4, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805EF00
	movs r0, 0x1
	strb r0, [r1]
	bl sub_8049ED4
	movs r7, 0x1
_0805EF00:
	ldrb r0, [r6, 0x1]
	cmp r0, 0
	beq _0805EF18
	cmp r0, 0x1
	beq _0805EF52
	cmp r0, 0x2
	bne _0805EF12
	movs r1, 0x1
	mov r8, r1
_0805EF12:
	mov r0, r8
	cmp r0, 0
	beq _0805EF52
_0805EF18:
	cmp r7, 0
	bne _0805EF52
	adds r1, r5, 0x4
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_807FE9C
	b _0805EF52
_0805EF2A:
	adds r0, r4, 0
	bl sub_8045108
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0805EF44
	adds r0, r5, 0x4
	movs r1, 0x1
	bl sub_8045DB4
	b _0805EF52
_0805EF44:
	ldr r0, _0805EF5C
	ldr r0, [r0]
	movs r1, 0xB8
	lsls r1, 3
	adds r0, r1
	movs r1, 0x4
	str r1, [r0]
_0805EF52:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805EF5C: .4byte gDungeonGlobalData
	thumb_func_end sub_805EE30

	thumb_func_start sub_805EF60
sub_805EF60:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	bl sub_80696A8
	adds r4, r0, 0
	cmp r4, 0
	beq _0805EF9E
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0805EF9E
	adds r0, r5, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	beq _0805EF9E
	ldr r1, [r4, 0x70]
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0805EFA2
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0805EFA2
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	beq _0805EFA2
_0805EF9E:
	movs r0, 0
	b _0805EFAE
_0805EFA2:
	adds r0, r6, 0
	adds r0, 0x44
	movs r1, 0x13
	bl sub_8044C94
	movs r0, 0x1
_0805EFAE:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805EF60

	thumb_func_start sub_805EFB4
sub_805EFB4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	bl sub_8083654
	adds r6, r0, 0
	cmp r7, 0
	beq _0805EFE2
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0805EFE2
	adds r0, r6, 0
	adds r0, 0x46
	ldrb r1, [r0]
	adds r1, 0x4
	movs r2, 0x7
	ands r1, r2
	strb r1, [r0]
	b _0805F020
_0805EFE2:
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0805F020
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r5, 0
_0805EFF6:
	cmp r7, 0
	bne _0805F008
	mov r0, r8
	adds r1, r4, 0
	bl sub_8070D6C
	lsls r0, 24
	cmp r0, 0
	beq _0805F014
_0805F008:
	movs r0, 0x7
	ands r4, r0
	adds r0, r6, 0
	adds r0, 0x46
	strb r4, [r0]
	b _0805F020
_0805F014:
	adds r4, 0x1
	movs r0, 0x7
	ands r4, r0
	adds r5, 0x1
	cmp r5, 0x7
	ble _0805EFF6
_0805F020:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_805EFB4

	thumb_func_start sub_805F02C
sub_805F02C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r5, _0805F058
	ldr r0, [r5]
	adds r0, 0xBC
	ldr r7, [r0]
	bl sub_8083600
	mov r9, r0
	ldr r0, [r7, 0x70]
	mov r8, r0
	mov r1, r9
	ldr r4, [r1, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0805F060
	ldr r0, _0805F05C
	b _0805F08E
	.align 2, 0
_0805F058: .4byte gDungeonGlobalData
_0805F05C: .4byte gUnknown_80F9BD8
_0805F060:
	movs r0, 0x2
	bl sub_8047084
	lsls r0, 24
	cmp r0, 0
	bne _0805F076
	bl sub_807EF48
	lsls r0, 24
	cmp r0, 0
	beq _0805F080
_0805F076:
	ldr r0, _0805F07C
	b _0805F08E
	.align 2, 0
_0805F07C: .4byte gUnknown_80F9C08
_0805F080:
	ldr r2, [r5]
	ldr r3, _0805F098
	adds r0, r2, r3
	ldrb r1, [r0]
	cmp r1, 0
	beq _0805F0A0
	ldr r0, _0805F09C
_0805F08E:
	ldr r1, [r0]
	adds r0, r7, 0
	bl sub_805239C
	b _0805F184
	.align 2, 0
_0805F098: .4byte 0x0000066e
_0805F09C: .4byte gUnknown_80F9C2C
_0805F0A0:
	ldr r5, _0805F114
	adds r0, r2, r5
	strb r1, [r0]
	movs r0, 0x1
	mov r2, r8
	strb r0, [r2, 0x7]
	strb r1, [r4, 0x7]
	movs r6, 0
	movs r3, 0x44
	add r3, r8
	mov r10, r3
	adds r5, r4, 0
	adds r5, 0x44
	str r5, [sp]
	adds r2, 0x64
	str r2, [sp, 0x4]
	adds r4, 0x64
	str r4, [sp, 0x8]
	ldr r3, _0805F118
	movs r2, 0x1
_0805F0C8:
	movs r0, 0x64
	muls r0, r6
	ldr r1, _0805F11C
	adds r0, r1
	ldr r1, [r3]
	adds r4, r1, r0
	movs r5, 0
	ldrb r1, [r4]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0805F12A
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	str r2, [sp, 0xC]
	str r3, [sp, 0x10]
	bl sub_806A538
	lsls r0, 24
	ldr r2, [sp, 0xC]
	ldr r3, [sp, 0x10]
	cmp r0, 0
	bne _0805F102
	movs r5, 0xA
	ldrsh r1, [r4, r5]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r3]
	adds r5, r0, r1
_0805F102:
	mov r0, r8
	ldrb r0, [r0, 0xA]
	cmp r6, r0
	bne _0805F120
	strb r2, [r4, 0x2]
	cmp r5, 0
	beq _0805F12A
	strb r2, [r5, 0x2]
	b _0805F12A
	.align 2, 0
_0805F114: .4byte 0x00000679
_0805F118: .4byte gRecruitedPokemonRef
_0805F11C: .4byte 0x00008df8
_0805F120:
	movs r0, 0
	strb r0, [r4, 0x2]
	cmp r5, 0
	beq _0805F12A
	strb r0, [r5, 0x2]
_0805F12A:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805F0C8
	ldr r0, _0805F194
	movs r4, 0
	str r4, [r0]
	mov r1, r10
	ldr r0, [sp]
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	adds r0, r7, 0
	bl sub_803F508
	mov r0, r9
	bl sub_8041AD0
	bl sub_8083600
	bl sub_8041AE0
	ldr r0, _0805F198
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0805F19C
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	movs r0, 0
	bl sub_807EC28
	ldr r0, [sp, 0x4]
	strb r4, [r0]
	ldr r1, [sp, 0x8]
	strb r4, [r1]
	mov r0, r9
	bl sub_806A6E8
	adds r0, r7, 0
	bl sub_806A6E8
_0805F184:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805F194: .4byte gUnknown_203B450
_0805F198: .4byte gAvailablePokemonNames
_0805F19C: .4byte gUnknown_80F9BB0
	thumb_func_end sub_805F02C

	thumb_func_start sub_805F1A0
sub_805F1A0:
	push {lr}
	bl sub_8083654
	adds r0, 0x44
	pop {r1}
	bx r1
	thumb_func_end sub_805F1A0

	thumb_func_start sub_805F1AC
sub_805F1AC:
	push {lr}
	bl sub_8083654
	adds r0, 0x44
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_805F1AC

	thumb_func_start ShowFieldMenu
ShowFieldMenu:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	ldr r0, _0805F208
	ldr r1, [r0]
	movs r0, 0xB8
	lsls r0, 3
	adds r1, r0
	ldr r3, [r1]
	mov r10, r3
	movs r0, 0
	str r0, [sp, 0x10]
	mvns r0, r3
	lsrs r0, 31
	str r0, [sp, 0x14]
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	cmp r3, 0
	blt _0805F1F8
	mov r1, r10
	str r1, [sp, 0x10]
_0805F1F8:
	cmp r2, 0
	beq _0805F23C
	ldr r0, _0805F20C
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	b _0805F240
	.align 2, 0
_0805F208: .4byte gDungeonGlobalData
_0805F20C: .4byte 0x00000137
_0805F210:
	bl sub_8083600
	movs r1, 0x1
	bl sub_806675C
	b _0805F226
_0805F21C:
	bl sub_8083600
	movs r1, 0x1
	bl sub_806684C
_0805F226:
	movs r0, 0x1
	bl sub_8044C10
	movs r0, 0x50
	movs r1, 0x4D
	bl sub_803E708
	movs r0, 0
	bl sub_8052210
	b _0805F92A
_0805F23C:
	bl sub_8083D44
_0805F240:
	mov r2, r10
	cmp r2, 0
	bge _0805F2FA
	movs r0, 0x1
	bl sub_8044C10
	ldr r0, _0805F388
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
	ldr r0, [sp, 0xC]
	bl DrawFieldMenu
	bl sub_8083600
	movs r1, 0
	bl sub_806A2BC
	ldr r4, _0805F38C
	ldr r5, _0805F390
	adds r6, r4, 0
	adds r6, 0x2A
_0805F26C:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x1D
	bl sub_803E46C
	ldrh r1, [r5, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0805F290
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_0805F290:
	ldrh r1, [r5, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0805F2A8
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_0805F2A8:
	ldrh r1, [r5, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805F2BC
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805F2D0
_0805F2BC:
	ldr r0, _0805F394
	movs r3, 0x18
	ldrsh r1, [r4, r3]
	adds r1, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x7
	beq _0805F3A8
	bl sub_8083D30
_0805F2D0:
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0805F2E0
	ldrb r0, [r6]
	cmp r0, 0
	beq _0805F26C
_0805F2E0:
	bl sub_8083D30
	movs r0, 0x1
	negs r0, r0
_0805F2E8:
	str r0, [sp, 0x10]
	ldr r0, _0805F38C
	bl AddMenuCursorSprite
	movs r0, 0x1D
	bl sub_803E46C
	movs r1, 0x1
	str r1, [sp, 0xC]
_0805F2FA:
	ldr r2, [sp, 0x10]
	mov r10, r2
	cmp r2, 0x1
	beq _0805F304
	b _0805F428
_0805F304:
	movs r0, 0x1
	bl sub_8044C10
	ldr r1, _0805F398
	ldr r0, [sp, 0x4]
	ands r0, r1
	ldr r1, _0805F39C
	ands r0, r1
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	ldr r1, _0805F3A0
	ands r0, r1
	ldr r1, _0805F3A4
	ands r0, r1
	str r0, [sp, 0x4]
	bl sub_8083600
	add r1, sp, 0x4
	bl sub_805FD74
	lsls r0, 24
	cmp r0, 0
	beq _0805F33A
	movs r3, 0x1
	negs r3, r3
	mov r10, r3
_0805F33A:
	add r0, sp, 0x4
	bl sub_805FD3C
	lsls r0, 24
	cmp r0, 0
	beq _0805F35C
	bl sub_8083600
	add r1, sp, 0x4
	bl sub_805FD74
	lsls r0, 24
	cmp r0, 0
	beq _0805F35C
	movs r0, 0x1
	bl sub_8044C10
_0805F35C:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC
	bne _0805F3B2
	bl sub_8083600
	movs r1, 0
	movs r2, 0xC
	bl sub_8044D90
	ldrb r2, [r0]
	movs r1, 0x4
	orrs r1, r2
	strb r1, [r0]
	bl sub_805F1A0
	bl sub_8060D24
	b _0805F412
	.align 2, 0
_0805F388: .4byte gUnknown_202F260
_0805F38C: .4byte gUnknown_202EE10
_0805F390: .4byte gRealInputs
_0805F394: .4byte gUnknown_202749A
_0805F398: .4byte 0xffffff00
_0805F39C: .4byte 0xffff00ff
_0805F3A0: .4byte 0xff00ffff
_0805F3A4: .4byte 0x00ffffff
_0805F3A8:
	bl sub_8083D08
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	b _0805F2E8
_0805F3B2:
	cmp r0, 0x35
	bne _0805F3D0
	bl sub_8083600
	movs r1, 0
	movs r2, 0xD
	bl sub_8044D90
	adds r4, r0, 0
	bl sub_8083600
	adds r1, r4, 0
	bl sub_8048A68
	b _0805F40A
_0805F3D0:
	cmp r0, 0x10
	bne _0805F3EE
	bl sub_8083600
	movs r1, 0
	movs r2, 0xE
	bl sub_8044D90
	adds r4, r0, 0
	bl sub_8083600
	adds r1, r4, 0
	bl sub_8048950
	b _0805F40A
_0805F3EE:
	cmp r0, 0x2C
	bne _0805F41A
	bl sub_8083600
	movs r1, 0
	movs r2, 0xF
	bl sub_8044D90
	adds r4, r0, 0
	bl sub_8083600
	adds r1, r4, 0
	bl sub_8048B9C
_0805F40A:
	lsls r0, 24
	cmp r0, 0
	beq _0805F412
	b _0805F72C
_0805F412:
	movs r0, 0x1
	bl sub_8044C10
	b _0805F72C
_0805F41A:
	cmp r0, 0x3C
	bne _0805F420
	b _0805F210
_0805F420:
	cmp r0, 0x3D
	bne _0805F426
	b _0805F21C
_0805F426:
	b _0805F72C
_0805F428:
	ldr r2, [sp, 0x10]
	cmp r2, 0x2
	beq _0805F430
	b _0805F52E
_0805F430:
	movs r0, 0x1
	bl sub_8044C10
	bl sub_8083600
	bl sub_8060E38
	lsls r0, 24
	cmp r0, 0
	beq _0805F44A
	movs r3, 0x1
	negs r3, r3
	mov r10, r3
_0805F44A:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1B
	bne _0805F45E
	bl sub_805F1A0
	movs r1, 0
	b _0805F4B2
_0805F45E:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1C
	bne _0805F474
	bl sub_805F1A0
	bl sub_806752C
	b _0805F4B6
_0805F474:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x34
	bne _0805F48A
	bl sub_805F1A0
	bl sub_8067768
	b _0805F4B6
_0805F48A:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1A
	bne _0805F4A0
	bl sub_805F1A0
	bl sub_80615E8
	b _0805F4B6
_0805F4A0:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x30
	bne _0805F4BE
	bl sub_805F1A0
	movs r1, 0x1
_0805F4B2:
	bl sub_8061A38
_0805F4B6:
	movs r0, 0x1
	bl sub_8044C10
	b _0805F72C
_0805F4BE:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x19
	beq _0805F4CC
	b _0805F72C
_0805F4CC:
	bl sub_805F1A0
	bl sub_8062D8C
	movs r6, 0
	movs r4, 0
_0805F4D8:
	ldr r0, _0805F518
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _0805F51C
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805F526
	bl sub_805F1A0
	ldrb r0, [r0, 0x4]
	cmp r4, r0
	bne _0805F524
	ldr r0, _0805F520
	str r6, [r0]
	bl sub_805F1AC
	lsls r0, 16
	cmp r0, 0
	bne _0805F50C
	b _0805F72C
_0805F50C:
	adds r0, r5, 0
	movs r1, 0
	bl sub_806A2BC
	b _0805F72C
	.align 2, 0
_0805F518: .4byte gDungeonGlobalData
_0805F51C: .4byte 0x0001357c
_0805F520: .4byte gUnknown_202F260
_0805F524:
	adds r6, 0x1
_0805F526:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0805F4D8
	b _0805F72C
_0805F52E:
	ldr r3, [sp, 0x10]
	cmp r3, 0
	beq _0805F536
	b _0805F73A
_0805F536:
	movs r7, 0
	movs r0, 0x1
	bl sub_8044C10
	movs r5, 0
	b _0805F544
_0805F542:
	adds r5, 0x1
_0805F544:
	cmp r5, 0x3
	bgt _0805F56C
	ldr r0, _0805F600
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0805F604
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805F542
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0805F542
	adds r7, r5, 0
_0805F56C:
	movs r0, 0
	bl sub_8044C10
_0805F572:
	movs r6, 0
	mov r9, r6
	mov r8, r6
	movs r5, 0
_0805F57A:
	ldr r0, _0805F600
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r3, _0805F604
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl sub_8071A8C
	lsls r0, 24
	cmp r0, 0
	beq _0805F5A0
	cmp r5, r7
	bne _0805F59C
	mov r9, r8
	adds r6, r4, 0
_0805F59C:
	movs r0, 0x1
	add r8, r0
_0805F5A0:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0805F57A
	cmp r6, 0
	bne _0805F5B0
	bl sub_8083600
	adds r6, r0, 0
_0805F5B0:
	adds r0, r6, 0
	movs r1, 0
	bl sub_806A2BC
	adds r0, r6, 0x4
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
	bl sub_8083654
	adds r0, 0x48
	strb r7, [r0]
	movs r0, 0
	bl sub_8044C10
	mov r1, r8
	str r1, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x1
	mov r3, r9
	bl sub_8062F90
	lsls r0, 24
	cmp r0, 0
	beq _0805F5EE
	movs r2, 0x1
	negs r2, r2
	mov r10, r2
_0805F5EE:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bne _0805F63C
	adds r4, r7, 0
	movs r5, 0
	b _0805F60A
	.align 2, 0
_0805F600: .4byte gDungeonGlobalData
_0805F604: .4byte 0x0001357c
_0805F608:
	adds r5, 0x1
_0805F60A:
	cmp r5, 0x3
	bgt _0805F676
	adds r7, 0x1
	cmp r7, 0x3
	ble _0805F616
	movs r7, 0
_0805F616:
	ldr r0, _0805F634
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r3, _0805F638
	adds r0, r3
	adds r0, r1
	ldr r6, [r0]
	adds r0, r6, 0
	bl sub_8071A8C
	lsls r0, 24
	cmp r0, 0
	beq _0805F608
	b _0805F676
	.align 2, 0
_0805F634: .4byte gDungeonGlobalData
_0805F638: .4byte 0x0001357c
_0805F63C:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7
	bne _0805F694
	adds r4, r7, 0
	movs r5, 0
	b _0805F650
_0805F64E:
	adds r5, 0x1
_0805F650:
	cmp r5, 0x3
	bgt _0805F676
	subs r7, 0x1
	cmp r7, 0
	bge _0805F65C
	movs r7, 0x3
_0805F65C:
	ldr r0, _0805F68C
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _0805F690
	adds r0, r2
	adds r0, r1
	ldr r6, [r0]
	adds r0, r6, 0
	bl sub_8071A8C
	lsls r0, 24
	cmp r0, 0
	beq _0805F64E
_0805F676:
	bl sub_8083654
	adds r0, 0x48
	strb r7, [r0]
	cmp r4, r7
	bne _0805F684
	b _0805F572
_0805F684:
	movs r0, 0
	bl sub_8083CE0
	b _0805F572
	.align 2, 0
_0805F68C: .4byte gDungeonGlobalData
_0805F690: .4byte 0x0001357c
_0805F694:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bne _0805F6AA
	bl sub_805F1A0
	bl sub_80637E8
	b _0805F56C
_0805F6AA:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	beq _0805F6C2
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x33
	bne _0805F6CE
_0805F6C2:
	bl sub_805F1A0
	movs r1, 0
	bl sub_8063A70
	b _0805F56C
_0805F6CE:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1F
	bne _0805F6E4
	bl sub_805F1A0
	bl sub_8063B54
	b _0805F56C
_0805F6E4:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x20
	bne _0805F6FA
	bl sub_805F1A0
	bl sub_8063BB4
	b _0805F56C
_0805F6FA:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x21
	bne _0805F712
	bl sub_805F1A0
	movs r1, 0
	bl sub_8063CF0
	b _0805F56C
_0805F712:
	bl sub_8083600
	movs r1, 0
	bl sub_806A2BC
	bl sub_8083600
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
_0805F72C:
	bl sub_805F1AC
	lsls r0, 16
	cmp r0, 0
	beq _0805F738
	b _0805F92A
_0805F738:
	b _0805F904
_0805F73A:
	ldr r3, [sp, 0x10]
	cmp r3, 0x4
	beq _0805F742
	b _0805F8E0
_0805F742:
	bl sub_8083600
	movs r1, 0x4
	ldrsh r2, [r0, r1]
	movs r3, 0x6
	ldrsh r1, [r0, r3]
	adds r0, r2, 0
	bl sub_804954C
	ldr r4, [r0, 0x14]
	cmp r4, 0
	bne _0805F75C
	b _0805F88C
_0805F75C:
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x3
	beq _0805F768
	b _0805F872
_0805F768:
	movs r0, 0x1
	bl sub_8044C10
	ldr r1, _0805F7F0
	ldr r0, [sp, 0x8]
	ands r0, r1
	ldr r1, _0805F7F4
	ands r0, r1
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	ldr r1, _0805F7F8
	ands r0, r1
	movs r1, 0x80
	lsls r1, 9
	orrs r0, r1
	ldr r1, _0805F7FC
	ands r0, r1
	adds r1, 0x1
	orrs r0, r1
	str r0, [sp, 0x8]
	bl sub_8083600
	add r4, sp, 0x8
	adds r1, r4, 0
	bl sub_805FD74
	lsls r0, 24
	adds r0, r4, 0
	bl sub_805FD3C
	lsls r0, 24
	cmp r0, 0
	beq _0805F7C2
	bl sub_8083600
	adds r1, r4, 0
	bl sub_805FD74
	lsls r0, 24
	cmp r0, 0
	beq _0805F7C2
	movs r0, 0x1
	bl sub_8044C10
_0805F7C2:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, 0xC
	bne _0805F800
	bl sub_8083600
	movs r1, 0
	movs r2, 0x10
	bl sub_8044D90
	ldrb r2, [r0]
	movs r1, 0x4
	orrs r1, r2
	strb r1, [r0]
	bl sub_805F1A0
	bl sub_8060D24
	b _0805F840
	.align 2, 0
_0805F7F0: .4byte 0xffffff00
_0805F7F4: .4byte 0xffff00ff
_0805F7F8: .4byte 0xff00ffff
_0805F7FC: .4byte 0x00ffffff
_0805F800:
	cmp r0, 0x35
	bne _0805F81E
	bl sub_8083600
	movs r1, 0
	movs r2, 0x11
	bl sub_8044D90
	adds r4, r0, 0
	bl sub_8083600
	adds r1, r4, 0
	bl sub_8048A68
	b _0805F83A
_0805F81E:
	cmp r0, 0x10
	bne _0805F848
	bl sub_8083600
	movs r1, 0
	movs r2, 0x12
	bl sub_8044D90
	adds r4, r0, 0
	bl sub_8083600
	adds r1, r4, 0
	bl sub_8048950
_0805F83A:
	lsls r0, 24
	cmp r0, 0
	bne _0805F8A8
_0805F840:
	movs r0, 0x1
	bl sub_8044C10
	b _0805F8A8
_0805F848:
	cmp r1, 0x2C
	bne _0805F8A8
	bl sub_8083600
	movs r1, 0
	movs r2, 0x13
	bl sub_8044D90
	adds r4, r0, 0
	bl sub_8083600
	adds r1, r4, 0
	bl sub_8048B9C
	lsls r0, 24
	cmp r0, 0
	bne _0805F8A8
	movs r0, 0x1
	bl sub_8044C10
	b _0805F8A8
_0805F872:
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x2
	bne _0805F8CE
	movs r0, 0x1
	bl sub_8044C10
	bl sub_8083600
	bl sub_80643AC
	b _0805F8A8
_0805F88C:
	ldrh r0, [r0]
	movs r2, 0x80
	lsls r2, 2
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0805F8B4
	movs r0, 0x1
	bl sub_8044C10
	bl sub_8083600
	bl sub_80647F0
_0805F8A8:
	bl sub_805F1AC
	lsls r0, 16
	cmp r0, 0
	bne _0805F92A
	b _0805F8CE
_0805F8B4:
	bl sub_8083600
	adds r1, r0, 0
	ldr r0, _0805F8D8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0805F8DC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0805F8CE:
	movs r3, 0x1
	negs r3, r3
	mov r10, r3
	b _0805F904
	.align 2, 0
_0805F8D8: .4byte gAvailablePokemonNames
_0805F8DC: .4byte gUnknown_80FDE18
_0805F8E0:
	ldr r0, [sp, 0x10]
	cmp r0, 0x3
	bne _0805F904
	bl sub_8064BE0
	ldr r0, _0805F91C
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _0805F92A
	bl sub_805F1AC
	lsls r0, 16
	cmp r0, 0
	bne _0805F92A
	movs r1, 0x1
	negs r1, r1
	mov r10, r1
_0805F904:
	ldr r2, [sp, 0x10]
	cmp r2, 0
	blt _0805F92A
	ldr r3, [sp, 0x14]
	cmp r3, 0
	bne _0805F920
	bl ResetRepeatTimers
	bl ResetUnusedInputStruct
	b _0805F240
	.align 2, 0
_0805F91C: .4byte gDungeonGlobalData
_0805F920:
	bl sub_8083600
	movs r1, 0
	bl sub_806A2BC
_0805F92A:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	bl ResetRepeatTimers
	bl ResetUnusedInputStruct
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ShowFieldMenu

	thumb_func_start DrawFieldMenu
DrawFieldMenu:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, _0805F994
	movs r0, 0
	strh r0, [r4, 0x18]
	movs r1, 0x5
	strh r1, [r4, 0x1A]
	strh r1, [r4, 0x1C]
	strh r0, [r4, 0x1E]
	strh r0, [r4, 0x4]
	movs r1, 0x2
	strh r1, [r4, 0x6]
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	str r0, [r4]
	strh r0, [r4, 0x14]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	movs r1, 0x38
	bl sub_80137B0
	cmp r5, 0
	beq _0805F998
	movs r0, 0x7
	movs r1, 0
	bl sub_803EAF0
	b _0805F9A0
	.align 2, 0
_0805F994: .4byte gUnknown_202EE10
_0805F998:
	movs r0, 0x6
	movs r1, 0
	bl sub_803EAF0
_0805F9A0:
	movs r0, 0
	bl sub_80073B8
	bl sub_8083600
	movs r1, 0x1
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	beq _0805F9CC
	ldr r0, _0805F9C8
	movs r2, 0x2
	strb r2, [r0, 0x1]
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x3]
	movs r1, 0x7
	strb r1, [r0, 0x4]
	strb r2, [r0, 0x5]
	b _0805F9DA
	.align 2, 0
_0805F9C8: .4byte gUnknown_202749A
_0805F9CC:
	ldr r1, _0805FBA0
	movs r0, 0x7
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x3]
	strb r0, [r1, 0x4]
	strb r0, [r1, 0x5]
_0805F9DA:
	ldr r4, _0805FBA4
	adds r0, r4, 0
	movs r1, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _0805FBA8
	ldr r2, [r0]
	movs r6, 0
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_call_draw_string
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _0805FBAC
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_call_draw_string
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _0805FBB0
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_call_draw_string
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _0805FBB4
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_call_draw_string
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _0805FBB8
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_call_draw_string
	movs r0, 0
	bl sub_80073E0
	cmp r5, 0
	bne _0805FA62
	b _0805FB92
_0805FA62:
	bl sub_8083600
	ldr r7, [r0, 0x70]
	bl sub_805317C
	adds r5, r0, 0
	bl sub_8008ED0
	movs r4, 0x88
	subs r4, r0
	lsrs r0, r4, 31
	adds r4, r0
	asrs r4, 1
	movs r0, 0x1
	bl sub_80073B8
	str r6, [sp]
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	movs r3, 0x1
	bl xxx_call_draw_string
	movs r0, 0x1
	bl sub_80073E0
	movs r0, 0x2
	bl sub_80073B8
	ldr r0, _0805FBBC
	ldr r0, [r0]
	add r2, sp, 0x8
	add r3, sp, 0xC
	add r1, sp, 0x4
	bl DeconstructPlayTime
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r7, r1
	ldr r0, [r0]
	bl sub_8094450
	ldr r4, _0805FBC0
	str r0, [r4]
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	bl sub_8094450
	str r0, [r4, 0x4]
	ldr r0, _0805FBC4
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x73
	movs r1, 0
	movs r3, 0x2
	bl xxx_format_and_draw
	ldr r0, _0805FBC8
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4]
	ldr r0, _0805FBCC
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x73
	movs r1, 0xC
	movs r3, 0x2
	bl xxx_format_and_draw
	ldr r5, _0805FBD0
	movs r0, 0
	bl sub_807E580
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl GetWeatherName
	ldr r0, _0805FBD4
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x73
	movs r1, 0x18
	movs r3, 0x2
	bl xxx_format_and_draw
	ldr r0, [sp, 0x4]
	str r0, [r4]
	ldr r0, [sp, 0x8]
	str r0, [r4, 0x4]
	ldr r0, [sp, 0xC]
	str r0, [r4, 0x8]
	ldr r0, _0805FBD8
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x73
	movs r1, 0x24
	movs r3, 0x2
	bl xxx_format_and_draw
	movs r7, 0
	mov r8, r4
_0805FB3A:
	ldr r0, _0805FBDC
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0805FBE0
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0805FB86
	ldr r4, [r5, 0x70]
	ldr r0, _0805FBD0
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	mov r2, r8
	str r0, [r2]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	str r0, [r2, 0x4]
	ldr r0, _0805FBE4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	adds r1, r7, 0
	movs r3, 0x2
	bl xxx_format_and_draw
	adds r7, 0xC
	cmp r7, 0x2F
	bgt _0805FB8C
_0805FB86:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805FB3A
_0805FB8C:
	movs r0, 0x2
	bl sub_80073E0
_0805FB92:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805FBA0: .4byte gUnknown_202749A
_0805FBA4: .4byte gUnknown_202EE10
_0805FBA8: .4byte gFieldMenuMovesPtr
_0805FBAC: .4byte gFieldMenuItemsPtr
_0805FBB0: .4byte gFieldMenuTeamPtr
_0805FBB4: .4byte gFieldMenuOthersPtr
_0805FBB8: .4byte gFieldMenuGroundPtr
_0805FBBC: .4byte gPlayTimeRef
_0805FBC0: .4byte gUnknown_202DE30
_0805FBC4: .4byte gUnknown_80F9174
_0805FBC8: .4byte gTeamInventory_203B460
_0805FBCC: .4byte gUnknown_80F9190
_0805FBD0: .4byte gAvailablePokemonNames
_0805FBD4: .4byte gUnknown_80F91A8
_0805FBD8: .4byte gUnknown_80F91C8
_0805FBDC: .4byte gDungeonGlobalData
_0805FBE0: .4byte 0x0001357c
_0805FBE4: .4byte gUnknown_80F91E0
	thumb_func_end DrawFieldMenu

	thumb_func_start sub_805FBE8
sub_805FBE8:
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0x8
	adds r1, r5, 0
	bl sub_803EAF0
_0805FBF4:
	movs r0, 0xE
	bl sub_803E46C
	bl xxx_draw_string_80144C4
	bl sub_8016080
	adds r4, r0, 0
	cmp r4, 0
	beq _0805FBF4
	bl sub_80160D8
	movs r0, 0xE
	bl sub_803E46C
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	cmp r4, 0x3
	bne _0805FC28
	ldrb r0, [r5]
	cmp r0, 0
	beq _0805FC28
	movs r0, 0x1
	b _0805FC2A
_0805FC28:
	movs r0, 0
_0805FC2A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_805FBE8

	thumb_func_start sub_805FC30
sub_805FC30:
	push {r4-r6,lr}
	sub sp, 0x78
	adds r4, r0, 0
	adds r6, r1, 0
	add r5, sp, 0x4
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r3, 0x3
	str r3, [sp, 0x8]
	str r3, [sp, 0x20]
	movs r2, 0
	movs r0, 0x16
	strh r0, [r5, 0x20]
	movs r1, 0x4
	strh r1, [r5, 0x22]
	movs r0, 0x6
	strh r0, [r5, 0x24]
	strh r1, [r5, 0x26]
	strh r1, [r5, 0x28]
	str r3, [sp, 0x38]
	str r3, [sp, 0x50]
	add r0, sp, 0x4
	ldm r4!, {r1,r3,r5}
	stm r0!, {r1,r3,r5}
	ldm r4!, {r1,r3,r5}
	stm r0!, {r1,r3,r5}
	add r1, sp, 0x4
	movs r0, 0x80
	strb r0, [r1]
	ldr r4, _0805FD30
	strh r2, [r4, 0x18]
	ldr r5, _0805FD34
	ldr r0, [r5]
	strh r0, [r4, 0x1C]
	strh r0, [r4, 0x1A]
	strh r2, [r4, 0x1E]
	strh r2, [r4, 0x20]
	strh r2, [r4, 0x4]
	strh r2, [r4, 0x6]
	movs r0, 0x1
	str r0, [r4]
	strh r2, [r4, 0xC]
	strh r2, [r4, 0xE]
	ldr r0, [r4, 0x8]
	str r0, [r4, 0x14]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	add r0, sp, 0x4
	strh r6, [r0, 0x20]
	adds r1, r0, 0
	movs r0, 0x1C
	subs r0, r6
	strh r0, [r1, 0x24]
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	movs r1, 0
	bl sub_80095E4
	add r2, sp, 0x4
	adds r1, r2, 0
	strh r0, [r1, 0x28]
	strh r0, [r2, 0x26]
	adds r0, r1, 0
	movs r1, 0
	bl sub_803ECB4
	add r0, sp, 0x4
	movs r2, 0x26
	ldrsh r1, [r0, r2]
	lsls r1, 3
	adds r0, r4, 0
	bl sub_80137B0
	movs r0, 0x1
	bl sub_80073B8
	movs r6, 0
	ldr r0, [r5]
	cmp r6, r0
	bge _0805FD20
	add r5, sp, 0x64
_0805FCDC:
	adds r0, r6, 0
	bl sub_8044F3C
	lsls r0, 24
	movs r4, 0x2
	cmp r0, 0
	beq _0805FCEC
	movs r4, 0x7
_0805FCEC:
	adds r0, r6, 0
	bl sub_8044EC8
	adds r3, r0, 0
	adds r0, r5, 0
	ldr r1, _0805FD38
	adds r2, r4, 0
	bl ExpandPlaceholdersBuffer
	ldr r0, _0805FD30
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r2, r5, 0
	movs r3, 0x1
	bl xxx_call_draw_string
	adds r6, 0x1
	ldr r0, _0805FD34
	ldr r0, [r0]
	cmp r6, r0
	blt _0805FCDC
_0805FD20:
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x78
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805FD30: .4byte gUnknown_202EE10
_0805FD34: .4byte gUnknown_202EE6C
_0805FD38: .4byte gUnknown_8106B50
	thumb_func_end sub_805FC30

	thumb_func_start sub_805FD3C
sub_805FD3C:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	adds r2, r0, 0
	movs r1, 0
	strb r1, [r4]
	strb r1, [r4, 0x1]
	strb r1, [r4, 0x2]
	strb r1, [r4, 0x3]
	cmp r2, 0xA
	bne _0805FD5E
	movs r0, 0x1
	strb r0, [r4]
	strb r0, [r4, 0x3]
_0805FD5E:
	cmp r2, 0x3E
	bne _0805FD6A
	movs r0, 0x1
	strb r0, [r4]
	strb r1, [r4, 0x1]
	strb r0, [r4, 0x3]
_0805FD6A:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_805FD3C

	thumb_func_start sub_805FD74
sub_805FD74:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xE4
	mov r10, r0
	adds r7, r1, 0
	movs r0, 0
	mov r9, r0
	movs r1, 0x1
	str r1, [sp, 0xD0]
	movs r2, 0
	str r2, [sp, 0xD4]
	movs r5, 0
	str r5, [sp, 0xD8]
	str r0, [sp, 0xDC]
	mov r1, r10
	ldr r1, [r1, 0x70]
	str r1, [sp, 0xE0]
	add r4, sp, 0x68
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x6C]
	add r0, sp, 0x70
	movs r6, 0
	movs r1, 0x2
	strh r1, [r0]
	strh r1, [r0, 0x2]
	add r1, sp, 0x74
	movs r0, 0x12
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x76
	movs r1, 0x10
	strh r1, [r0]
	add r0, sp, 0x78
	strh r1, [r0]
	add r5, sp, 0xC8
	str r5, [sp, 0x7C]
	movs r1, 0x3
	str r1, [sp, 0x84]
	add r0, sp, 0x98
	str r1, [r0, 0x4]
	add r0, sp, 0xB0
	str r1, [r0, 0x4]
	add r0, sp, 0x8
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	ldr r0, _0805FE40
	strb r6, [r0]
	mov r2, r9
	strh r2, [r0, 0x4]
	strh r2, [r0, 0x6]
	cmp r7, 0
	beq _0805FE18
	ldrb r1, [r7]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	str r0, [sp, 0xD8]
	ldrb r1, [r7, 0x1]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	str r0, [sp, 0xD0]
	ldrb r1, [r7, 0x2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	str r0, [sp, 0xD4]
	ldrb r1, [r7, 0x3]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	str r0, [sp, 0xDC]
_0805FE18:
	ldr r0, _0805FE44
	mov r5, r10
	str r5, [sp]
	ldr r1, [sp, 0xD4]
	ldr r2, [sp, 0xD0]
	ldr r3, [sp, 0xDC]
	bl sub_8060D64
	ldr r1, _0805FE48
	str r0, [r1]
	cmp r0, 0
	bne _0805FEA6
	ldr r0, _0805FE4C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	movs r0, 0x1
	b _080603BE
	.align 2, 0
_0805FE40: .4byte gUnknown_202F238
_0805FE44: .4byte gUnknown_202F248
_0805FE48: .4byte gUnknown_202F258
_0805FE4C: .4byte gUnknown_80F8B24
_0805FE50:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x1
	mov r9, r0
	b _0806039C
_0805FE5E:
	ldr r0, [sp, 0xE0]
	adds r0, 0x44
	movs r1, 0xC
	bl sub_8044C94
	ldr r0, _0805FE78
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	ldr r2, [sp, 0xE0]
	str r0, [r2, 0x48]
	str r1, [r2, 0x4C]
	b _0805FE88
	.align 2, 0
_0805FE78: .4byte gUnknown_202F238
_0805FE7C:
	ldr r0, _0805FE98
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	ldr r2, [sp, 0xE0]
	str r0, [r2, 0x50]
	str r1, [r2, 0x54]
_0805FE88:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r5, 0
	mov r9, r5
	b _0806039C
	.align 2, 0
_0805FE98: .4byte gUnknown_202F238
_0805FE9C:
	ldr r1, [r1]
	ldr r0, [sp, 0xE0]
	adds r0, 0x50
	strb r1, [r0]
	b _0806033C
_0805FEA6:
	movs r1, 0
	mov r8, r1
	ldr r0, _0805FFA8
	mov r2, r9
	str r2, [r0]
_0805FEB0:
	movs r5, 0
	mov r9, r5
	movs r4, 0
	ldr r6, _0805FFAC
_0805FEB8:
	lsls r1, r4, 2
	ldr r0, [r6]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805FEEC
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805FEEC
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	ldr r1, _0805FFA8
	str r0, [r1]
_0805FEEC:
	adds r4, 0x1
	cmp r4, 0x13
	ble _0805FEB8
	movs r6, 0
_0805FEF4:
	ldr r0, _0805FFB0
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0805FFB4
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r5, r6, 0x1
	mov r12, r5
	cmp r0, 0
	beq _0805FF66
	ldr r0, [r4, 0x70]
	adds r2, r0, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805FF66
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805FF66
	movs r0, 0xFB
	ands r0, r1
	strb r0, [r2]
	movs r4, 0
	ldr r0, _0805FFB8
	ldr r1, [r0]
	adds r5, r0, 0
	ldr r7, _0805FFA8
	cmp r4, r1
	bge _0805FF62
	ldr r0, _0805FFBC
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r3, r0, 0
	adds r2, r6, 0x4
	cmp r1, r2
	beq _0805FF60
_0805FF4C:
	adds r4, 0x1
	ldr r0, [r5]
	cmp r4, r0
	bge _0805FF62
	lsls r0, r4, 1
	adds r0, r3
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	bne _0805FF4C
_0805FF60:
	mov r8, r4
_0805FF62:
	movs r0, 0
	str r0, [r7]
_0805FF66:
	mov r6, r12
	cmp r6, 0x3
	ble _0805FEF4
	add r2, sp, 0x8
	str r2, [sp]
	add r5, sp, 0xC8
	str r5, [sp, 0x4]
	mov r0, r8
	mov r1, r10
	ldr r2, [sp, 0xD8]
	ldr r3, [sp, 0xD4]
	bl CreateFieldItemMenu
	ldr r1, _0805FFBC
	ldr r0, _0805FFC0
	movs r2, 0x1E
	ldrsh r0, [r0, r2]
	lsls r0, 1
	adds r0, r1
	movs r5, 0
	ldrsh r2, [r0, r5]
	cmp r2, 0x3
	ble _0805FFE6
	ldr r0, _0805FFB0
	ldr r1, [r0]
	subs r0, r2, 0x4
	lsls r0, 2
	ldr r2, _0805FFB4
	adds r1, r2
	adds r1, r0
	ldr r4, [r1]
	b _0805FFE8
	.align 2, 0
_0805FFA8: .4byte gUnknown_202F240
_0805FFAC: .4byte gTeamInventory_203B460
_0805FFB0: .4byte gDungeonGlobalData
_0805FFB4: .4byte 0x0001357c
_0805FFB8: .4byte gUnknown_202F258
_0805FFBC: .4byte gUnknown_202F248
_0805FFC0: .4byte gUnknown_202EE10
_0805FFC4:
	bl sub_8083D44
	mov r0, r10
	adds r0, 0x4
	bl sub_8060890
	movs r5, 0x3
	mov r9, r5
	b _08060200
_0805FFD6:
	bl sub_8083D08
	ldr r0, [sp, 0xE0]
	adds r0, 0x44
	bl sub_8060CE8
	movs r0, 0
	b _080602F0
_0805FFE6:
	mov r4, r10
_0805FFE8:
	adds r0, r4, 0
	movs r1, 0
	bl sub_806A2BC
	adds r0, r4, 0x4
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
	ldr r6, _08060050
	adds r7, r6, 0
	adds r7, 0x2B
_08060002:
	adds r0, r6, 0
	bl AddMenuCursorSprite
	movs r0, 0x14
	bl sub_803E46C
	ldr r1, [sp, 0xD4]
	cmp r1, 0
	beq _08060016
	b _080601F4
_08060016:
	ldr r4, _08060054
	ldr r0, [r4]
	cmp r0, 0x1
	ble _0806008C
	ldr r0, _08060058
	ldrh r1, [r0, 0x2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08060034
	adds r0, r6, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806005C
_08060034:
	movs r0, 0
	bl sub_8083CE0
	movs r2, 0x1
	negs r2, r2
	add r8, r2
	mov r5, r8
	cmp r5, 0
	bge _0806007E
	ldr r0, [r4]
	subs r0, 0x1
	mov r8, r0
	b _0806007E
	.align 2, 0
_08060050: .4byte gUnknown_202EE10
_08060054: .4byte gUnknown_202F258
_08060058: .4byte gRealInputs
_0806005C:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0806006A
	ldrb r0, [r7]
	cmp r0, 0
	beq _0806008C
_0806006A:
	movs r0, 0
	bl sub_8083CE0
	movs r2, 0x1
	add r8, r2
	ldr r0, [r4]
	cmp r8, r0
	bne _0806007E
	movs r5, 0
	mov r8, r5
_0806007E:
	ldr r0, [sp, 0xD4]
	ldr r1, _08060088
	str r0, [r1]
	b _08060200
	.align 2, 0
_08060088: .4byte gUnknown_202F240
_0806008C:
	ldr r0, _08060134
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080600B2
	mov r0, r8
	bl sub_8060860
	lsls r0, 24
	cmp r0, 0
	beq _080600B2
	movs r0, 0x1
	bl sub_8083CE0
	ldr r0, _08060138
	movs r1, 0x1
	bl sub_80136E0
_080600B2:
	ldr r0, _08060134
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080600D8
	mov r0, r8
	bl sub_8060860
	lsls r0, 24
	cmp r0, 0
	beq _080600D8
	movs r0, 0x1
	bl sub_8083CE0
	ldr r0, _08060138
	movs r1, 0x1
	bl sub_8013744
_080600D8:
	ldr r0, _08060134
	ldrh r2, [r0, 0x2]
	movs r1, 0x4
	ands r1, r2
	adds r2, r0, 0
	cmp r1, 0
	beq _080601A0
	ldr r4, _0806013C
	mov r5, r8
	lsls r0, r5, 1
	adds r0, r4
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bgt _080601A0
	movs r7, 0x1
	movs r0, 0x99
	lsls r0, 1
	bl PlaySoundEffect
	bl sub_8047158
	bl ConvertMoneyItemToMoney
	movs r0, 0
	ldr r2, _08060140
	str r0, [r2]
	mov r5, r10
	str r5, [sp]
	add r0, sp, 0x68
	ldr r1, [sp, 0xD4]
	ldr r2, [sp, 0xD0]
	ldr r3, [sp, 0xDC]
	bl sub_8060D64
	adds r3, r0, 0
	ldr r0, _08060144
	ldr r0, [r0]
	cmp r0, r3
	bne _08060164
	movs r6, 0
	cmp r6, r3
	bge _0806015E
	add r2, sp, 0x68
	b _08060152
	.align 2, 0
_08060134: .4byte gRealInputs
_08060138: .4byte gUnknown_202EE10
_0806013C: .4byte gUnknown_202F248
_08060140: .4byte gUnknown_202F240
_08060144: .4byte gUnknown_202F258
_08060148:
	adds r4, 0x2
	adds r2, 0x2
	adds r6, 0x1
	cmp r6, r3
	bge _0806015E
_08060152:
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r5, 0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	beq _08060148
_0806015E:
	cmp r6, r3
	bne _08060164
	movs r7, 0
_08060164:
	cmp r7, 0
	beq _08060200
	movs r0, 0
	mov r8, r0
	ldr r1, _08060194
	str r0, [r1]
	ldr r0, _08060198
	str r3, [r0]
	movs r6, 0
	adds r5, r0, 0
	cmp r6, r3
	bge _08060200
	adds r3, r5, 0
	add r1, sp, 0x68
	ldr r2, _0806019C
_08060182:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, 0x2
	adds r2, 0x2
	adds r6, 0x1
	ldr r0, [r3]
	cmp r6, r0
	blt _08060182
	b _08060200
	.align 2, 0
_08060194: .4byte gUnknown_202F240
_08060198: .4byte gUnknown_202F258
_0806019C: .4byte gUnknown_202F248
_080601A0:
	ldrh r1, [r2, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080601B6
	ldr r2, _080601C8
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _080601CC
_080601B6:
	bl sub_8083D08
	mov r0, r10
	adds r0, 0x4
	bl sub_8060890
	movs r2, 0x1
	mov r9, r2
	b _08060200
	.align 2, 0
_080601C8: .4byte gUnknown_202EE10
_080601CC:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080601D6
	b _0805FFC4
_080601D6:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080601EA
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080601EA
	b _08060002
_080601EA:
	bl sub_8083D30
	movs r5, 0x2
	mov r9, r5
	b _08060200
_080601F4:
	mov r0, r10
	adds r0, 0x4
	bl sub_8060890
	movs r0, 0x1
	mov r9, r0
_08060200:
	ldr r4, _0806034C
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x14
	bl sub_803E46C
	ldr r1, _08060350
	movs r2, 0x1E
	ldrsh r0, [r4, r2]
	lsls r0, 1
	adds r0, r1
	movs r5, 0
	ldrsh r0, [r0, r5]
	cmp r0, 0x1
	bgt _08060232
	ldr r0, _08060354
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08060232
	movs r0, 0x2
	mov r9, r0
_08060232:
	mov r1, r9
	cmp r1, 0x2
	bne _0806023A
	b _0805FE50
_0806023A:
	cmp r1, 0
	bne _08060240
	b _0805FEB0
_08060240:
	cmp r1, 0x3
	bne _08060246
	b _0805FE5E
_08060246:
	ldr r4, _0806034C
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	ldr r5, _08060358
	str r0, [r5]
	ldr r0, [sp, 0xD8]
	cmp r0, 0
	beq _08060258
	b _0805FE7C
_08060258:
	mov r0, r10
	bl sub_8060900
	movs r2, 0x1E
	ldrsh r1, [r4, r2]
	add r0, sp, 0xC8
	bl sub_8060800
	add r0, sp, 0x8
	movs r1, 0x16
	bl sub_805FC30
	ldr r6, _0806035C
	adds r7, r4, 0
	adds r7, 0x2A
_08060276:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x14
	bl sub_803E46C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806029A
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_0806029A:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080602B2
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_080602B2:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080602C6
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _080602DA
_080602C6:
	movs r5, 0x18
	ldrsh r0, [r4, r5]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	beq _080602D6
	b _0805FFD6
_080602D6:
	bl sub_8083D30
_080602DA:
	ldrh r1, [r6, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080602EA
	ldrb r0, [r7]
	cmp r0, 0
	beq _08060276
_080602EA:
	bl sub_8083D30
	movs r0, 0x1
_080602F0:
	mov r9, r0
	ldr r0, _0806034C
	bl AddMenuCursorSprite
	movs r0, 0x14
	bl sub_803E46C
	ldr r0, _08060360
	ldr r0, [r0]
	ldr r1, _08060364
	adds r0, r1
	movs r1, 0
	strb r1, [r0]
	mov r2, r9
	cmp r2, 0x1
	bne _08060318
	ldr r5, [sp, 0xD4]
	cmp r5, 0
	bne _08060318
	b _0805FEB0
_08060318:
	ldr r0, [sp, 0xE0]
	adds r0, 0x44
	ldrh r1, [r0]
	adds r0, r1, 0
	subs r0, 0x37
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _08060330
	adds r0, r1, 0
	cmp r0, 0x3E
	bne _0806036C
_08060330:
	ldr r0, _08060368
	ldrb r0, [r0]
	subs r0, 0x90
	ldr r1, [sp, 0xE0]
	adds r1, 0x48
	strb r0, [r1]
_0806033C:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0
	mov r9, r0
	b _0806039C
	.align 2, 0
_0806034C: .4byte gUnknown_202EE10
_08060350: .4byte gUnknown_202F248
_08060354: .4byte gTeamInventory_203B460
_08060358: .4byte gUnknown_202F240
_0806035C: .4byte gRealInputs
_08060360: .4byte gDungeonGlobalData
_08060364: .4byte 0x00018212
_08060368: .4byte gUnknown_202F238
_0806036C:
	cmp r0, 0x36
	bne _08060390
	add r0, sp, 0xCC
	movs r1, 0x2
	bl DrawFieldGiveItemMenu
	add r1, sp, 0xCC
	cmp r0, 0
	beq _08060380
	b _0805FE9C
_08060380:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x1
	bl sub_8044C10
	b _0805FEB0
_08060390:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r1, 0
	mov r9, r1
_0806039C:
	ldr r0, _080603D0
	ldr r0, [r0]
	ldr r2, _080603D4
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x2
	movs r1, 0x61
	bl sub_803E708
	bl sub_804AA60
	movs r0, 0x2
	movs r1, 0x61
	bl sub_803E708
	mov r0, r9
_080603BE:
	add sp, 0xE4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080603D0: .4byte gDungeonGlobalData
_080603D4: .4byte 0x00018212
	thumb_func_end sub_805FD74

	thumb_func_start CreateFieldItemMenu
CreateFieldItemMenu:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x78
	adds r7, r0, 0
	mov r9, r1
	ldr r6, [sp, 0x98]
	ldr r0, [sp, 0x9C]
	mov r8, r0
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x6C]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x70]
	add r1, sp, 0x4
	ldr r0, _08060478
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	mov r0, r9
	ldr r0, [r0, 0x70]
	str r0, [sp, 0x74]
	mov r0, r8
	adds r1, r7, 0
	bl sub_8060800
	mov r10, r0
	ldr r5, _0806047C
	ldr r0, _08060480
	ldr r0, [r0]
	movs r4, 0
	movs r1, 0
	strh r0, [r5, 0x18]
	strh r1, [r5, 0x1A]
	strh r7, [r5, 0x1E]
	ldr r0, _08060484
	ldr r0, [r0]
	strh r0, [r5, 0x20]
	strh r1, [r5, 0x4]
	str r1, [r5]
	strh r1, [r5, 0x14]
	adds r0, r5, 0
	adds r0, 0x28
	bl sub_801317C
	ldr r3, _08060488
	ldr r0, [r3]
	ldr r2, _0806048C
	adds r0, r2
	strb r4, [r0]
	ldr r1, _08060490
	lsls r0, r7, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x2
	beq _08060494
	cmp r0, 0x2
	bgt _080604AA
	cmp r0, 0
	blt _080604AA
	movs r1, 0x10
	strh r1, [r6, 0x10]
	strh r1, [r6, 0xE]
	movs r0, 0xC
	mov r4, r8
	strb r0, [r4, 0x2]
	strh r1, [r5, 0x6]
	movs r0, 0xA
	strh r0, [r5, 0x1C]
	ldr r0, [r3]
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	b _080604C0
	.align 2, 0
_08060478: .4byte gUnknown_8106B6C
_0806047C: .4byte gUnknown_202EE10
_08060480: .4byte gUnknown_202F240
_08060484: .4byte gUnknown_202F258
_08060488: .4byte gDungeonGlobalData
_0806048C: .4byte 0x00018212
_08060490: .4byte gUnknown_202F248
_08060494:
	movs r0, 0x4
	strh r0, [r6, 0x10]
	strh r0, [r6, 0xE]
	movs r0, 0x6
	mov r1, r8
	strb r0, [r1, 0x2]
	movs r0, 0x12
	strh r0, [r5, 0x6]
	movs r0, 0x1
	strh r0, [r5, 0x1C]
	b _080604C0
_080604AA:
	movs r0, 0x4
	strh r0, [r6, 0x10]
	strh r0, [r6, 0xE]
	movs r0, 0xC
	mov r2, r8
	strb r0, [r2, 0x2]
	ldr r1, _080604DC
	movs r0, 0x12
	strh r0, [r1, 0x6]
	movs r0, 0x1
	strh r0, [r1, 0x1C]
_080604C0:
	ldr r3, [sp, 0x6C]
	cmp r3, 0
	beq _080604E0
	ldr r1, _080604DC
	ldrh r0, [r1, 0xC]
	adds r0, 0x40
	strh r0, [r1, 0xC]
	movs r0, 0xA
	strh r0, [r6, 0x8]
	adds r1, r6, 0
	adds r1, 0x18
	add r0, sp, 0x4
	b _080604EC
	.align 2, 0
_080604DC: .4byte gUnknown_202EE10
_080604E0:
	movs r0, 0x2
	strh r0, [r6, 0x8]
	adds r1, r6, 0
	adds r1, 0x18
	adds r0, r6, 0
	adds r0, 0x48
_080604EC:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_803ECB4
	ldr r1, _0806054C
	ldr r5, _08060550
	movs r4, 0
	ldrsh r0, [r1, r4]
	adds r0, 0x10
	lsls r0, 3
	movs r2, 0
	mov r8, r2
	strh r0, [r5, 0xC]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r5, 0xE]
	adds r0, r5, 0
	movs r1, 0x70
	bl sub_80137B0
	movs r0, 0
	bl sub_80073B8
	mov r4, r10
	subs r0, r7, r4
	lsls r0, 3
	adds r6, r0, 0
	adds r6, 0xC
	ldr r0, _08060554
	lsls r1, r7, 1
	adds r0, r1, r0
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r2, r1, 0
	cmp r0, 0x1
	beq _080605CC
	cmp r0, 0x1
	bgt _08060558
	cmp r0, 0
	beq _08060564
	b _08060718
	.align 2, 0
_0806054C: .4byte gUnknown_2027370
_08060550: .4byte gUnknown_202EE10
_08060554: .4byte gUnknown_202F248
_08060558:
	cmp r0, 0x2
	beq _0806063C
	cmp r0, 0x3
	bne _08060562
	b _080606B0
_08060562:
	b _08060718
_08060564:
	ldr r0, _080605C0
	ldr r2, [r0]
	mov r3, r8
	str r3, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	movs r4, 0
	adds r6, r5, 0
	movs r7, 0
	add r5, sp, 0x1C
_0806057E:
	lsls r1, r4, 2
	ldr r0, _080605C4
	ldr r0, [r0]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08060592
	b _08060794
_08060592:
	ldrh r0, [r6, 0x1A]
	adds r0, 0x1
	strh r0, [r6, 0x1A]
	adds r0, r5, 0
	adds r1, r2, 0
	ldr r2, _080605C8
	bl sub_8090E14
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8013800
	adds r1, r0, 0
	str r7, [sp]
	movs r0, 0x8
	adds r2, r5, 0
	movs r3, 0
	bl xxx_format_and_draw
	adds r4, 0x1
	cmp r4, 0x9
	ble _0806057E
	b _08060794
	.align 2, 0
_080605C0: .4byte gTeamToolboxAPtr
_080605C4: .4byte gTeamInventory_203B460
_080605C8: .4byte gUnknown_8106B60
_080605CC:
	ldr r0, _08060630
	ldr r2, [r0]
	mov r4, r8
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	movs r4, 0
	adds r6, r5, 0
	movs r7, 0
	add r5, sp, 0x1C
_080605E6:
	lsls r3, r4, 2
	ldr r0, _08060634
	ldr r2, [r0]
	adds r0, r3, r2
	adds r0, 0x28
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080605FC
	b _08060794
_080605FC:
	ldrh r0, [r6, 0x1A]
	adds r0, 0x1
	strh r0, [r6, 0x1A]
	adds r1, r3, 0
	adds r1, 0x28
	adds r1, r2, r1
	adds r0, r5, 0
	ldr r2, _08060638
	bl sub_8090E14
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8013800
	adds r1, r0, 0
	str r7, [sp]
	movs r0, 0x8
	adds r2, r5, 0
	movs r3, 0
	bl xxx_format_and_draw
	adds r4, 0x1
	cmp r4, 0x9
	ble _080605E6
	b _08060794
	.align 2, 0
_08060630: .4byte gTeamToolboxBPtr
_08060634: .4byte gTeamInventory_203B460
_08060638: .4byte gUnknown_8106B60
_0806063C:
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	movs r3, 0x6
	ldrsh r1, [r1, r3]
	bl sub_804954C
	ldr r0, [r0, 0x14]
	bl sub_8045108
	adds r7, r0, 0
	ldr r0, _080606A8
	ldr r2, [r0]
	mov r4, r8
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08060698
	ldrh r0, [r5, 0x1A]
	adds r0, 0x1
	strh r0, [r5, 0x1A]
	add r4, sp, 0x1C
	ldr r2, _080606AC
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_8090E14
	adds r0, r5, 0
	movs r1, 0
	bl sub_8013800
	adds r1, r0, 0
	mov r0, r8
	str r0, [sp]
	movs r0, 0x8
	adds r2, r4, 0
	movs r3, 0
	bl xxx_format_and_draw
_08060698:
	ldr r1, [sp, 0x70]
	cmp r1, 0
	beq _08060794
	mov r2, r8
	strh r2, [r5, 0xA]
	strh r2, [r5, 0x8]
	b _08060794
	.align 2, 0
_080606A8: .4byte gFieldItemMenuGroundTextPtr
_080606AC: .4byte gUnknown_8106B60
_080606B0:
	mov r3, r9
	ldr r0, [r3, 0x70]
	adds r7, r0, 0
	adds r7, 0x60
	ldr r0, _0806070C
	ldr r1, [sp, 0x74]
	movs r2, 0
	bl sub_80708B4
	ldr r0, _08060710
	ldr r2, [r0]
	mov r4, r8
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08060794
	ldrh r0, [r5, 0x1A]
	adds r0, 0x1
	strh r0, [r5, 0x1A]
	add r4, sp, 0x1C
	ldr r2, _08060714
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_8090E14
	adds r0, r5, 0
	movs r1, 0
	bl sub_8013800
	adds r1, r0, 0
	mov r0, r8
	str r0, [sp]
	movs r0, 0x8
	adds r2, r4, 0
	movs r3, 0
	bl xxx_format_and_draw
	b _08060794
	.align 2, 0
_0806070C: .4byte gAvailablePokemonNames
_08060710: .4byte gUnknown_80FE940
_08060714: .4byte gUnknown_8106B60
_08060718:
	ldr r0, _080607E0
	ldr r1, [r0]
	ldr r0, _080607E4
	adds r0, r2, r0
	movs r2, 0
	ldrsh r0, [r0, r2]
	subs r0, 0x4
	lsls r0, 2
	ldr r3, _080607E8
	adds r1, r3
	adds r1, r0
	ldr r4, [r1]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08060794
	ldr r1, [r4, 0x70]
	adds r7, r1, 0
	adds r7, 0x60
	ldr r0, _080607EC
	movs r2, 0
	bl sub_80708B4
	ldr r0, _080607F0
	ldr r2, [r0]
	movs r4, 0
	mov r8, r4
	str r4, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08060794
	ldr r4, _080607F4
	ldrh r0, [r4, 0x1A]
	adds r0, 0x1
	strh r0, [r4, 0x1A]
	add r5, sp, 0x1C
	ldr r2, _080607F8
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_8090E14
	adds r0, r4, 0
	movs r1, 0
	bl sub_8013800
	adds r1, r0, 0
	mov r0, r8
	str r0, [sp]
	movs r0, 0x8
	adds r2, r5, 0
	movs r3, 0
	bl xxx_format_and_draw
_08060794:
	ldr r2, _080607F4
	movs r3, 0x18
	ldrsh r1, [r2, r3]
	movs r4, 0x1A
	ldrsh r0, [r2, r4]
	cmp r1, r0
	blt _080607A6
	movs r0, 0
	strh r0, [r2, 0x18]
_080607A6:
	movs r0, 0
	bl sub_80073E0
	ldr r0, [sp, 0x6C]
	cmp r0, 0
	beq _080607D0
	movs r0, 0x1
	bl sub_80073B8
	ldr r0, _080607FC
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0x2
	movs r3, 0x1
	bl xxx_format_and_draw
	movs r0, 0x1
	bl sub_80073E0
_080607D0:
	add sp, 0x78
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080607E0: .4byte gDungeonGlobalData
_080607E4: .4byte gUnknown_202F248
_080607E8: .4byte 0x0001357c
_080607EC: .4byte gAvailablePokemonNames
_080607F0: .4byte gUnknown_80FE940
_080607F4: .4byte gUnknown_202EE10
_080607F8: .4byte gUnknown_8106B60
_080607FC: .4byte gWhichTextPtr1
	thumb_func_end CreateFieldItemMenu

	thumb_func_start sub_8060800
sub_8060800:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	ldr r0, _0806083C
	ldr r2, [r0]
	mov r12, r0
	ldr r6, _08060840
	cmp r1, r2
	bge _08060828
	adds r3, r6, 0
_08060816:
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r0, 0x1
	bgt _08060820
	adds r1, 0x1
_08060820:
	adds r3, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _08060816
_08060828:
	lsls r0, r4, 1
	adds r0, r6
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	bgt _08060844
	adds r3, r4, 0
	adds r2, r1, 0
	movs r1, 0
	b _0806084C
	.align 2, 0
_0806083C: .4byte gUnknown_202F258
_08060840: .4byte gUnknown_202F248
_08060844:
	subs r3, r4, r1
	mov r7, r12
	ldr r0, [r7]
	subs r2, r0, r1
_0806084C:
	cmp r5, 0
	beq _08060858
	movs r0, 0
	strb r2, [r5]
	strb r3, [r5, 0x1]
	strb r0, [r5, 0x3]
_08060858:
	adds r0, r1, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8060800

	thumb_func_start sub_8060860
sub_8060860:
	push {lr}
	adds r1, r0, 0
	ldr r0, _08060880
	movs r2, 0x1A
	ldrsh r0, [r0, r2]
	cmp r0, 0x1
	ble _0806087C
	ldr r0, _08060884
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	ble _08060888
_0806087C:
	movs r0, 0
	b _0806088A
	.align 2, 0
_08060880: .4byte gUnknown_202EE10
_08060884: .4byte gUnknown_202F248
_08060888:
	movs r0, 0x1
_0806088A:
	pop {r1}
	bx r1
	thumb_func_end sub_8060860

	thumb_func_start sub_8060890
sub_8060890:
	push {r4,lr}
	adds r3, r0, 0
	ldr r1, _080608B4
	ldr r2, _080608B8
	movs r4, 0x1E
	ldrsh r0, [r2, r4]
	lsls r0, 1
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	beq _080608D0
	cmp r0, 0x1
	bgt _080608BC
	cmp r0, 0
	beq _080608C2
	b _080608E8
	.align 2, 0
_080608B4: .4byte gUnknown_202F248
_080608B8: .4byte gUnknown_202EE10
_080608BC:
	cmp r0, 0x2
	beq _080608DC
	b _080608E8
_080608C2:
	ldr r1, _080608CC
	ldrb r0, [r2, 0x18]
	adds r0, 0x1
	b _080608EC
	.align 2, 0
_080608CC: .4byte gUnknown_202F238
_080608D0:
	ldr r1, _080608D8
	ldrb r0, [r2, 0x18]
	adds r0, 0xB
	b _080608EC
	.align 2, 0
_080608D8: .4byte gUnknown_202F238
_080608DC:
	ldr r1, _080608E4
	movs r0, 0x80
	b _080608EC
	.align 2, 0
_080608E4: .4byte gUnknown_202F238
_080608E8:
	ldr r1, _080608FC
	subs r0, 0x74
_080608EC:
	strb r0, [r1]
	ldrh r0, [r3]
	strh r0, [r1, 0x4]
	ldrh r0, [r3, 0x2]
	strh r0, [r1, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080608FC: .4byte gUnknown_202F238
	thumb_func_end sub_8060890

	thumb_func_start sub_8060900
sub_8060900:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	ldr r4, _08060964
	adds r1, r4, 0
	movs r2, 0xA
	bl sub_8044CC8
	adds r7, r0, 0
	mov r0, r9
	ldr r0, [r0, 0x70]
	mov r10, r0
	ldr r1, _08060968
	movs r0, 0
	str r0, [r1]
	ldrb r0, [r4]
	cmp r0, 0x8F
	bls _0806092C
	b _08060BD0
_0806092C:
	cmp r0, 0x80
	bne _080609B0
	ldrb r1, [r7, 0x2]
	movs r0, 0x9
	bl sub_8044F5C
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x6
	beq _08060992
	movs r2, 0
	ldr r0, _0806096C
	ldr r0, [r0]
	ldr r1, _08060970
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08060978
	ldr r0, _08060974
	ldr r0, [r0]
	adds r0, 0x4C
	ldrb r0, [r0]
	movs r2, 0x1
	ands r2, r0
	b _08060988
	.align 2, 0
_08060964: .4byte gUnknown_202F238
_08060968: .4byte gUnknown_202EE6C
_0806096C: .4byte gDungeonGlobalData
_08060970: .4byte 0x0000065b
_08060974: .4byte gTeamInventory_203B460
_08060978:
	mov r0, r10
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08060988
	movs r2, 0x1
_08060988:
	cmp r2, 0
	beq _08060992
	movs r0, 0x9
	bl sub_8044FF0
_08060992:
	ldr r0, _08060A20
	ldrb r0, [r0]
	cmp r0, 0x80
	bne _080609B0
	ldr r0, _08060A24
	ldr r0, [r0]
	ldr r2, _08060A28
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080609B0
	ldrb r1, [r7, 0x2]
	movs r0, 0xA
	bl sub_8044F5C
_080609B0:
	adds r0, r7, 0
	bl sub_8044DC8
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _080609E8
	ldrb r1, [r7, 0x2]
	adds r0, r4, 0
	bl sub_8044F5C
	ldrb r1, [r7]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080609D6
	adds r0, r4, 0
	bl sub_8044FF0
_080609D6:
	adds r0, r7, 0
	bl sub_8046F00
	lsls r0, 24
	cmp r0, 0
	bne _080609E8
	adds r0, r4, 0
	bl sub_8044FF0
_080609E8:
	ldr r0, _08060A20
	ldrb r0, [r0]
	cmp r0, 0x14
	bhi _08060A6C
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	beq _08060A0A
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08060A6C
_08060A0A:
	ldrb r1, [r7]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08060A3A
	ldrb r1, [r7, 0x2]
	movs r0, 0x3D
	bl sub_8044F5C
	b _08060A42
	.align 2, 0
_08060A20: .4byte gUnknown_202F238
_08060A24: .4byte gDungeonGlobalData
_08060A28: .4byte 0x0000065b
_08060A2C:
	movs r0, 0x3C
	bl sub_8044FF0
	movs r0, 0x3D
	bl sub_8044FF0
	b _08060A6C
_08060A3A:
	ldrb r1, [r7, 0x2]
	movs r0, 0x3C
	bl sub_8044F5C
_08060A42:
	movs r3, 0
	ldr r0, _08060AD4
	ldr r2, [r0]
	movs r4, 0x1
_08060A4A:
	ldrb r1, [r2]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08060A64
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08060A64
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08060A2C
_08060A64:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _08060A4A
_08060A6C:
	ldr r0, _08060AD8
	ldrb r0, [r0]
	cmp r0, 0x81
	beq _08060AE8
	cmp r0, 0x80
	beq _08060B3C
	movs r3, 0
	mov r8, r3
	ldrb r1, [r7, 0x2]
	movs r0, 0x36
	bl sub_8044F5C
	movs r6, 0
_08060A86:
	ldr r0, _08060ADC
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08060AE0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08060ABE
	ldr r0, [r4, 0x70]
	ldr r3, _08060AE4
	adds r5, r0, r3
	movs r0, 0
	strb r0, [r5]
	adds r0, r4, 0
	bl CannotUseItems
	lsls r0, 24
	cmp r0, 0
	bne _08060ABE
	movs r0, 0x1
	mov r8, r0
	mov r1, r8
	strb r1, [r5]
_08060ABE:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08060A86
	mov r2, r8
	cmp r2, 0
	bne _08060B3C
	movs r0, 0x36
	bl sub_8044FF0
	b _08060B3C
	.align 2, 0
_08060AD4: .4byte gTeamInventory_203B460
_08060AD8: .4byte gUnknown_202F238
_08060ADC: .4byte gDungeonGlobalData
_08060AE0: .4byte 0x0001357c
_08060AE4: .4byte 0x00000157
_08060AE8:
	ldr r0, _08060B10
	ldr r0, [r0]
	ldr r3, _08060B14
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _08060B3C
	ldr r0, _08060B18
	ldr r0, [r0]
	adds r0, 0x4C
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08060B1C
	ldrb r1, [r7, 0x2]
	movs r0, 0x3E
	bl sub_8044F5C
	b _08060B24
	.align 2, 0
_08060B10: .4byte gDungeonGlobalData
_08060B14: .4byte 0x0000065b
_08060B18: .4byte gTeamInventory_203B460
_08060B1C:
	ldrb r1, [r7, 0x2]
	movs r0, 0x37
	bl sub_8044F5C
_08060B24:
	mov r0, r9
	bl CannotUseItems
	lsls r0, 24
	cmp r0, 0
	beq _08060B3C
	movs r0, 0x37
	bl sub_8044FF0
	movs r0, 0x3E
	bl sub_8044FF0
_08060B3C:
	ldr r0, _08060B64
	ldrb r0, [r0]
	cmp r0, 0x14
	bhi _08060B78
	mov r1, r9
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	movs r3, 0x6
	ldrsh r1, [r1, r3]
	bl sub_804954C
	ldr r0, [r0, 0x14]
	cmp r0, 0
	bne _08060B68
	ldrb r1, [r7, 0x2]
	movs r0, 0x8
	bl sub_8044F5C
	b _08060B78
	.align 2, 0
_08060B64: .4byte gUnknown_202F238
_08060B68:
	bl sub_80450F8
	cmp r0, 0x3
	bne _08060B78
	ldrb r1, [r7, 0x2]
	movs r0, 0x3A
	bl sub_8044F5C
_08060B78:
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	bne _08060B8E
	ldrb r1, [r7, 0x2]
	movs r0, 0x27
	bl sub_8044F5C
	b _08060BAE
_08060B8E:
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08060BA6
	ldrb r1, [r7, 0x2]
	movs r0, 0x41
	bl sub_8044F5C
	b _08060BAE
_08060BA6:
	ldrb r1, [r7, 0x2]
	movs r0, 0xB
	bl sub_8044F5C
_08060BAE:
	mov r0, r10
	bl sub_8071A70
	lsls r0, 24
	cmp r0, 0
	beq _08060BBC
	b _08060CCC
_08060BBC:
	movs r0, 0x27
	bl sub_8044FF0
	movs r0, 0x41
	bl sub_8044FF0
	movs r0, 0xB
	bl sub_8044FF0
	b _08060CCC
_08060BD0:
	ldrb r1, [r4]
	subs r1, 0x90
	ldr r0, _08060C50
	mov r9, r0
	ldr r0, [r0]
	lsls r1, 2
	ldr r2, _08060C54
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08060CCC
	ldr r3, [r4, 0x70]
	mov r8, r3
	movs r5, 0
	adds r0, r4, 0
	bl CannotUseItems
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r6, r1, 31
	ldr r0, _08060C58
	ldr r0, [r0]
	adds r0, 0x4C
	ldrb r0, [r0]
	movs r4, 0x1
	ands r4, r0
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08060C22
	movs r5, 0x1
_08060C22:
	ldrb r0, [r7, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bne _08060C32
	movs r5, 0x1
_08060C32:
	mov r1, r9
	ldr r0, [r1]
	ldr r2, _08060C5C
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08060C78
	cmp r4, 0
	beq _08060C60
	ldrb r1, [r7, 0x2]
	movs r0, 0x3E
	bl sub_8044F5C
	b _08060C68
	.align 2, 0
_08060C50: .4byte gDungeonGlobalData
_08060C54: .4byte 0x0001357c
_08060C58: .4byte gTeamInventory_203B460
_08060C5C: .4byte 0x0000065b
_08060C60:
	ldrb r1, [r7, 0x2]
	movs r0, 0x37
	bl sub_8044F5C
_08060C68:
	cmp r6, 0
	beq _08060C78
	movs r0, 0x37
	bl sub_8044FF0
	movs r0, 0x3E
	bl sub_8044FF0
_08060C78:
	mov r3, r8
	ldrb r0, [r3, 0x7]
	cmp r0, 0
	beq _08060CBA
	adds r0, r7, 0
	bl sub_8044DC8
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _08060CCC
	ldrb r1, [r7, 0x2]
	adds r0, r4, 0
	bl sub_8044F5C
	ldrb r1, [r7]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08060CA6
	adds r0, r4, 0
	bl sub_8044FF0
_08060CA6:
	adds r0, r7, 0
	bl sub_8046F00
	lsls r0, 24
	cmp r0, 0
	bne _08060CCC
	adds r0, r4, 0
	bl sub_8044FF0
	b _08060CCC
_08060CBA:
	ldrb r1, [r7, 0x2]
	movs r0, 0x38
	bl sub_8044F5C
	cmp r5, 0
	beq _08060CCC
	movs r0, 0x38
	bl sub_8044FF0
_08060CCC:
	ldrb r1, [r7, 0x2]
	movs r0, 0xC
	bl sub_8044F5C
	bl sub_8045064
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8060900

	thumb_func_start sub_8060CE8
sub_8060CE8:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08060D18
	ldr r0, _08060D1C
	movs r2, 0x18
	ldrsh r0, [r0, r2]
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r4, 0
	bl sub_8044C94
	ldr r0, _08060D20
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r4, 0x4]
	str r1, [r4, 0x8]
	movs r0, 0
	strb r0, [r4, 0xC]
	strh r0, [r4, 0x10]
	strh r0, [r4, 0x12]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08060D18: .4byte gUnknown_202EE44
_08060D1C: .4byte gUnknown_202EE10
_08060D20: .4byte gUnknown_202F238
	thumb_func_end sub_8060CE8

	thumb_func_start sub_8060D24
sub_8060D24:
	push {r4,lr}
	bl sub_8083600
	movs r1, 0
	movs r2, 0xB
	bl sub_8044D90
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0
	bl sub_803ECB4
	adds r0, r4, 0
	bl sub_801B3C0
_08060D42:
	movs r0, 0x16
	bl sub_803E46C
	bl sub_801B410
	cmp r0, 0
	beq _08060D42
	bl sub_801B450
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8060D24

	thumb_func_start sub_8060D64
sub_8060D64:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	movs r7, 0
	ldr r0, _08060E28
	ldr r0, [r0]
	ldr r1, _08060E2C
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08060DB8
	cmp r6, 0
	bne _08060DB8
	ldr r5, _08060E30
	ldr r0, [r5]
	ldrb r1, [r0]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08060DA2
	strh r7, [r4]
	movs r7, 0x1
_08060DA2:
	ldr r0, [r5]
	adds r0, 0x28
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08060DB8
	lsls r0, r7, 1
	adds r0, r4
	strh r3, [r0]
	adds r7, 0x1
_08060DB8:
	cmp r2, 0
	beq _08060DD4
	ldr r0, [sp, 0x18]
	adds r0, 0x4
	bl sub_804ACE4
	lsls r0, 24
	cmp r0, 0
	beq _08060DD4
	lsls r0, r7, 1
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0]
	adds r7, 0x1
_08060DD4:
	cmp r6, 0
	bne _08060E1A
	mov r2, r8
	cmp r2, 0
	bne _08060E1A
	movs r5, 0
	lsls r0, r7, 1
	adds r6, r0, r4
_08060DE4:
	ldr r0, _08060E28
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08060E34
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08060E14
	ldr r0, [r4, 0x70]
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08060E14
	adds r0, r5, 0x4
	strh r0, [r6]
	adds r6, 0x2
	adds r7, 0x1
_08060E14:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08060DE4
_08060E1A:
	adds r0, r7, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08060E28: .4byte gDungeonGlobalData
_08060E2C: .4byte 0x0000065b
_08060E30: .4byte gTeamInventory_203B460
_08060E34: .4byte 0x0001357c
	thumb_func_end sub_8060D64

	thumb_func_start sub_8060E38
sub_8060E38:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x7C
	str r0, [sp, 0x78]
	add r4, sp, 0x18
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [r4, 0x4]
	movs r0, 0x2
	strh r0, [r4, 0x8]
	strh r0, [r4, 0xA]
	movs r0, 0xE
	strh r0, [r4, 0xC]
	movs r0, 0x10
	strh r0, [r4, 0xE]
	strh r0, [r4, 0x10]
	ldr r0, _08061018
	str r0, [r4, 0x14]
	movs r0, 0x3
	str r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	str r0, [r4, 0x4C]
	movs r5, 0
	mov r9, r4
	add r0, sp, 0x4
	mov r8, r0
_08060E7A:
	ldr r6, _0806101C
	ldr r0, [r6]
	lsls r1, r5, 2
	ldr r2, _08061020
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08060E9E
	ldr r0, [r4, 0x70]
	ldr r2, _08061024
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
_08060E9E:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08060E7A
	ldr r0, [r6]
	ldr r1, _08061028
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08060EBC
	movs r0, 0x3
	mov r2, r9
	str r0, [r2, 0x4]
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
_08060EBC:
	ldr r6, _0806102C
_08060EBE:
	movs r7, 0
	mov r0, sp
	mov r1, r9
	movs r2, 0x1
	bl DrawFieldTeamMenu
	movs r0, 0
	mov r10, r0
_08060ECE:
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	lsls r0, 2
	add r0, r8
	ldr r1, [r0]
	cmp r1, 0
	blt _08060F00
	ldr r0, _0806101C
	ldr r0, [r0]
	lsls r1, 2
	ldr r2, _08061020
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	movs r1, 0
	bl sub_806A2BC
	adds r4, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
_08060F00:
	adds r0, r6, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	ldr r4, _08061030
	ldrh r1, [r4, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08060F26
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80136E0
_08060F26:
	ldrh r1, [r4, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08060F3E
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8013744
_08060F3E:
	ldrh r1, [r4, 0x2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08060F5A
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	add r1, sp, 0x14
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08061046
	bl sub_8083D30
_08060F5A:
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08060F6C
	ldr r2, _08061034
	ldrb r0, [r2]
	cmp r0, 0
	beq _08060F7E
_08060F6C:
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	add r1, sp, 0x14
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08061040
	bl sub_8083D30
_08060F7E:
	ldr r0, _08061030
	ldrh r1, [r0, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08060F92
	ldr r2, _08061038
	ldrb r0, [r2]
	cmp r0, 0
	beq _08060ECE
_08060F92:
	bl sub_8083D30
	movs r7, 0x1
_08060F98:
	ldr r5, _0806102C
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	lsls r0, 2
	add r0, r8
	ldr r1, [r0]
	cmp r1, 0
	blt _08060FCC
	ldr r0, _0806101C
	ldr r0, [r0]
	lsls r1, 2
	ldr r2, _08061020
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	movs r1, 0
	bl sub_806A2BC
	adds r4, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
_08060FCC:
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	bl sub_804AA60
	cmp r7, 0
	beq _08060FE2
	b _0806110C
_08060FE2:
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	str r0, [sp]
	ldr r1, _0806103C
	movs r2, 0x18
	ldrsh r0, [r5, r2]
	str r0, [r1]
	mov r0, sp
	bl sub_806145C
	mov r0, r10
	cmp r0, 0
	beq _08061064
	ldr r1, [sp, 0x78]
	ldr r4, [r1, 0x70]
	adds r0, r4, 0
	adds r0, 0x44
	movs r1, 0x1B
	bl sub_8044C94
	ldr r0, [sp]
	lsls r0, 2
	add r0, r8
	ldr r0, [r0]
	adds r4, 0x48
	strb r0, [r4]
	b _08061116
	.align 2, 0
_08061018: .4byte gUnknown_202F270
_0806101C: .4byte gDungeonGlobalData
_08061020: .4byte 0x0001357c
_08061024: .4byte 0x00000157
_08061028: .4byte 0x0000065b
_0806102C: .4byte gUnknown_202EE10
_08061030: .4byte gRealInputs
_08061034: .4byte gUnknown_202EE39
_08061038: .4byte gUnknown_202EE3A
_0806103C: .4byte gUnknown_202F260
_08061040:
	bl sub_8083D08
	b _08060F98
_08061046:
	bl sub_8083D44
	movs r2, 0x1
	mov r10, r2
	b _08060F98
_08061050:
	ldr r1, [sp, 0x78]
	ldr r0, [r1, 0x70]
	adds r0, 0x44
	mov r1, sp
	bl sub_80615B4
	bl sub_8083D08
	movs r4, 0
	b _080610EA
_08061064:
	mov r0, r9
	movs r1, 0x12
	bl sub_805FC30
	adds r4, r5, 0
	ldr r5, _08061100
	adds r7, r4, 0
	adds r7, 0x2A
_08061074:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	ldrh r1, [r5, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08061098
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_08061098:
	ldrh r1, [r5, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080610B0
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_080610B0:
	ldrh r1, [r5, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080610C2
	ldr r2, _08061104
	ldrb r0, [r2]
	cmp r0, 0
	beq _080610D4
_080610C2:
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	bne _08061050
	bl sub_8083D30
_080610D4:
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080610E4
	ldrb r0, [r7]
	cmp r0, 0
	beq _08061074
_080610E4:
	bl sub_8083D30
	movs r4, 0x1
_080610EA:
	ldr r0, _08061108
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	cmp r4, 0x1
	bne _080610FC
	b _08060EBE
_080610FC:
	movs r7, 0
	b _08061116
	.align 2, 0
_08061100: .4byte gRealInputs
_08061104: .4byte gUnknown_202EE39
_08061108: .4byte gUnknown_202EE10
_0806110C:
	bl sub_8083600
	movs r1, 0
	bl sub_806A2BC
_08061116:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	adds r0, r7, 0
	add sp, 0x7C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8060E38

	thumb_func_start DrawFieldTeamMenu
DrawFieldTeamMenu:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r0
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x8]
	movs r7, 0
	movs r1, 0
	mov r2, r8
	ldr r0, [r2, 0x4]
	cmp r0, 0x6
	bne _08061154
	movs r1, 0x1
_08061154:
	mov r10, r1
	bl sub_8083600
	adds r1, r0, 0
	add r0, sp, 0x4
	bl sub_8069D18
	movs r6, 0
_08061164:
	ldr r0, _08061318
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r3, _0806131C
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080611AC
	lsls r1, r7, 2
	mov r0, r9
	adds r0, 0x4
	adds r0, r1
	str r6, [r0]
	ldr r0, [r4, 0x70]
	mov r1, r9
	adds r1, 0x14
	adds r1, r7
	ldr r5, _08061320
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r0, [r4, 0x4]
	cmp r1, r0
	bne _080611AA
	ldr r1, _08061324
	ldr r0, [r1]
	cmp r0, 0
	bge _080611AA
	str r7, [r1]
_080611AA:
	adds r7, 0x1
_080611AC:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08061164
	ldr r0, _08061324
	ldr r1, [r0]
	adds r5, r0, 0
	cmp r1, r7
	blt _080611C0
	subs r0, r7, 0x1
	str r0, [r5]
_080611C0:
	ldr r0, [r5]
	cmp r0, 0
	bge _080611CA
	movs r0, 0
	str r0, [r5]
_080611CA:
	adds r6, r7, 0
	mov r0, r10
	negs r3, r0
	cmp r7, 0x3
	bgt _080611F4
	movs r1, 0x1
	negs r1, r1
	mov r12, r1
	mov r2, r9
	adds r2, 0x14
	movs r4, 0
	lsls r0, r7, 2
	adds r1, r0, 0x4
	add r1, r9
_080611E6:
	mov r0, r12
	stm r1!, {r0}
	adds r0, r2, r6
	strb r4, [r0]
	adds r6, 0x1
	cmp r6, 0x3
	ble _080611E6
_080611F4:
	ldr r1, _08061328
	movs r4, 0
	movs r0, 0x1
	strb r0, [r1]
	strb r4, [r1, 0x1]
	strb r4, [r1, 0x3]
	ldr r0, _0806132C
	ldr r1, [r5]
	strh r1, [r0, 0x18]
	strh r7, [r0, 0x1A]
	strh r7, [r0, 0x1C]
	strh r4, [r0, 0x1E]
	strh r4, [r0, 0x20]
	strh r4, [r0, 0x4]
	mov r1, r10
	orrs r3, r1
	asrs r1, r3, 31
	movs r2, 0x10
	ands r1, r2
	strh r1, [r0, 0x6]
	strh r4, [r0, 0xC]
	strh r4, [r0, 0xE]
	strh r4, [r0, 0x14]
	str r4, [r0]
	adds r0, 0x28
	bl sub_801317C
	adds r0, r7, 0
	movs r1, 0
	bl sub_80095E4
	mov r2, r10
	cmp r2, 0
	beq _0806123A
	adds r0, 0x2
_0806123A:
	mov r3, r8
	strh r0, [r3, 0x10]
	strh r0, [r3, 0xE]
	movs r0, 0x8
	ldr r5, _08061328
	strb r0, [r5, 0x2]
	ldr r0, [sp, 0x8]
	cmp r0, 0
	beq _0806125C
	mov r1, r8
	adds r1, 0x18
	mov r0, r8
	adds r0, 0x48
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_0806125C:
	mov r0, r8
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, _0806132C
	movs r1, 0
	bl sub_80137B0
	movs r0, 0
	bl sub_80073B8
	mov r0, r10
	cmp r0, 0
	beq _08061286
	ldr r2, _08061330
	str r4, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
_08061286:
	movs r6, 0
	cmp r6, r7
	blt _0806128E
	b _08061440
_0806128E:
	lsls r1, r6, 2
	mov r0, r9
	adds r0, 0x4
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	bge _0806129E
	b _08061438
_0806129E:
	ldr r0, _08061318
	ldr r0, [r0]
	lsls r1, 2
	ldr r2, _0806131C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080612BA
	b _08061438
_080612BA:
	ldr r5, [r4, 0x70]
	mov r0, r9
	adds r0, 0x14
	adds r0, r6
	ldrb r0, [r0]
	movs r2, 0x2
	cmp r0, 0
	beq _080612CC
	movs r2, 0x6
_080612CC:
	ldr r4, _08061334
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8070968
	ldr r0, _08061338
	ldr r1, [r0]
	ldrb r2, [r5, 0xA]
	movs r0, 0x64
	muls r0, r2
	adds r1, r0
	ldr r3, _0806133C
	adds r1, r3
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl sub_806A538
	lsls r0, 24
	cmp r0, 0
	beq _08061388
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	adds r1, r2, 0
	cmp r2, 0
	bge _08061300
	adds r1, r2, 0x3
_08061300:
	movs r3, 0xE
	ldrsh r0, [r5, r3]
	asrs r1, 2
	cmp r0, r1
	bgt _08061344
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _08061340
	bl strcpy
	b _080613EE
	.align 2, 0
_08061318: .4byte gDungeonGlobalData
_0806131C: .4byte 0x0001357c
_08061320: .4byte 0x00000157
_08061324: .4byte gUnknown_202F260
_08061328: .4byte gUnknown_202F270
_0806132C: .4byte gUnknown_202EE10
_08061330: .4byte gUnknown_8106BB0
_08061334: .4byte gAvailablePokemonNames
_08061338: .4byte gRecruitedPokemonRef
_0806133C: .4byte 0x00008e02
_08061340: .4byte gUnknown_8106BB4
_08061344:
	movs r0, 0xE
	ldrsh r3, [r5, r0]
	lsls r0, r1, 1
	cmp r3, r0
	bgt _08061360
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _0806135C
	bl strcpy
	b _080613EE
	.align 2, 0
_0806135C: .4byte gUnknown_8106BB8
_08061360:
	adds r0, r1
	cmp r3, r0
	bgt _08061378
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _08061374
	bl strcpy
	b _080613EE
	.align 2, 0
_08061374: .4byte gUnknown_8106BBC
_08061378:
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _08061384
	bl strcpy
	b _080613EE
	.align 2, 0
_08061384: .4byte gUnknown_8106BC0
_08061388:
	movs r1, 0x10
	ldrsh r2, [r5, r1]
	adds r1, r2, 0
	cmp r2, 0
	bge _08061394
	adds r1, r2, 0x3
_08061394:
	movs r3, 0xE
	ldrsh r0, [r5, r3]
	asrs r1, 2
	cmp r0, r1
	bgt _080613B0
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _080613AC
	bl strcpy
	b _080613EE
	.align 2, 0
_080613AC: .4byte gUnknown_8106BC4
_080613B0:
	movs r0, 0xE
	ldrsh r3, [r5, r0]
	lsls r0, r1, 1
	cmp r3, r0
	bgt _080613CC
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _080613C8
	bl strcpy
	b _080613EE
	.align 2, 0
_080613C8: .4byte gUnknown_8106BC8
_080613CC:
	adds r0, r1
	cmp r3, r0
	bgt _080613E4
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _080613E0
	bl strcpy
	b _080613EE
	.align 2, 0
_080613E0: .4byte gUnknown_8106BCC
_080613E4:
	adds r0, r4, 0
	adds r0, 0x50
	ldr r1, _0806141C
	bl strcpy
_080613EE:
	ldr r0, _08061420
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	str r1, [r0]
	movs r3, 0x10
	ldrsh r1, [r5, r3]
	str r1, [r0, 0x4]
	ldr r0, _08061424
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0806142C
	movs r0, 0
	str r0, [sp]
	movs r0, 0x9
	ldr r2, _08061428
	movs r3, 0
	bl xxx_format_and_draw
	b _08061438
	.align 2, 0
_0806141C: .4byte gUnknown_8106BD0
_08061420: .4byte gUnknown_202DE30
_08061424: .4byte gUnknown_202EE10
_08061428: .4byte gUnknown_8106BD4
_0806142C:
	str r0, [sp]
	movs r0, 0x9
	ldr r2, _08061458
	movs r3, 0
	bl xxx_format_and_draw
_08061438:
	adds r6, 0x1
	cmp r6, r7
	bge _08061440
	b _0806128E
_08061440:
	movs r0, 0
	bl sub_80073E0
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061458: .4byte gUnknown_8106BE0
	thumb_func_end DrawFieldTeamMenu

	thumb_func_start sub_806145C
sub_806145C:
	push {r4-r6,lr}
	ldr r2, _08061560
	movs r1, 0
	str r1, [r2]
	ldr r5, _08061564
	ldr r2, [r5]
	ldr r1, _08061568
	movs r3, 0x18
	ldrsh r1, [r1, r3]
	lsls r1, 2
	adds r0, 0x4
	adds r0, r1
	ldr r0, [r0]
	lsls r0, 2
	ldr r1, _0806156C
	adds r2, r1
	adds r2, r0
	ldr r6, [r2]
	ldr r4, [r6, 0x70]
	movs r0, 0x1B
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0x19
	movs r1, 0
	bl sub_8044F5C
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _080614C8
	ldr r2, [r5]
	ldr r3, _08061570
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080614C0
	adds r0, r4, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	bne _080614B8
	ldr r1, _08061574
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080614C0
_080614B8:
	movs r0, 0x34
	movs r1, 0
	bl sub_8044F5C
_080614C0:
	movs r0, 0x1C
	movs r1, 0
	bl sub_8044F5C
_080614C8:
	movs r0, 0x30
	movs r1, 0
	bl sub_8044F5C
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _0806154C
	movs r0, 0x1A
	movs r1, 0
	bl sub_8044F5C
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _0806154C
	ldr r0, _08061564
	ldr r1, [r0]
	ldr r2, _08061574
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806154C
	ldr r3, _08061578
	adds r0, r1, r3
	ldrb r0, [r0]
	bl sub_8090158
	lsls r0, 24
	cmp r0, 0
	beq _0806154C
	movs r0, 0x3B
	movs r1, 0
	bl sub_8044F5C
	movs r5, 0x1
	ldrb r0, [r4, 0xA]
	cmp r0, 0x3
	bhi _08061530
	ldr r2, _0806157C
	ldrb r1, [r4, 0xA]
	movs r0, 0x64
	muls r1, r0
	ldr r0, _08061580
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	bl sub_806A538
	lsls r0, 24
	cmp r0, 0
	beq _08061532
_08061530:
	movs r5, 0
_08061532:
	adds r0, r6, 0
	movs r1, 0
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08061542
	movs r5, 0
_08061542:
	cmp r5, 0
	bne _0806154C
	movs r0, 0x3B
	bl sub_8044FF0
_0806154C:
	adds r0, r4, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0806155A
	cmp r0, 0x47
	bne _08061584
_0806155A:
	movs r0, 0x1
	b _08061586
	.align 2, 0
_08061560: .4byte gUnknown_202EE6C
_08061564: .4byte gDungeonGlobalData
_08061568: .4byte gUnknown_202EE10
_0806156C: .4byte 0x0001357c
_08061570: .4byte 0x0000065d
_08061574: .4byte 0x0000065c
_08061578: .4byte 0x00000644
_0806157C: .4byte gRecruitedPokemonRef
_08061580: .4byte 0x00008df8
_08061584:
	movs r0, 0
_08061586:
	cmp r0, 0
	beq _080615A8
	movs r0, 0x19
	bl sub_8044FF0
	movs r0, 0x3B
	bl sub_8044FF0
	movs r0, 0x1A
	bl sub_8044FF0
	movs r0, 0x30
	bl sub_8044FF0
	movs r0, 0x34
	bl sub_8044FF0
_080615A8:
	bl sub_8045064
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806145C

	thumb_func_start sub_80615B4
sub_80615B4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r1, _080615E0
	ldr r0, _080615E4
	movs r2, 0x18
	ldrsh r0, [r0, r2]
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_8044C94
	ldm r4!, {r0}
	lsls r0, 2
	adds r4, r0
	ldr r0, [r4]
	strb r0, [r5, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080615E0: .4byte gUnknown_202EE44
_080615E4: .4byte gUnknown_202EE10
	thumb_func_end sub_80615B4

	thumb_func_start sub_80615E8
sub_80615E8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x7C
	adds r5, r0, 0
	mov r4, sp
	mov r0, sp
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x4]
	movs r1, 0x2
	strh r1, [r4, 0x8]
	strh r1, [r4, 0xA]
	movs r2, 0x12
	strh r2, [r4, 0xC]
	movs r0, 0xE
	strh r0, [r4, 0xE]
	strh r2, [r4, 0x10]
	strh r1, [r4, 0x12]
	ldr r0, _08061720
	str r0, [sp, 0x14]
	movs r0, 0x3
	str r0, [sp, 0x1C]
	str r0, [sp, 0x34]
	str r0, [sp, 0x4C]
	ldr r0, _08061724
	ldr r1, [r0]
	ldrb r0, [r5, 0x4]
	lsls r0, 2
	ldr r2, _08061728
	adds r1, r2
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x74]
	ldr r0, [r1, 0x70]
	mov r8, r0
	movs r1, 0
	str r1, [sp, 0x70]
	movs r2, 0
	str r2, [sp, 0x6C]
	add r0, sp, 0x60
	mov r10, r0
_08061646:
	movs r1, 0x1
	str r1, [sp, 0x78]
	movs r7, 0
	ldr r0, _08061720
	strb r1, [r0]
	strb r7, [r0, 0x1]
	movs r1, 0xA
	strb r1, [r0, 0x2]
	strb r7, [r0, 0x3]
	mov r0, sp
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, [sp, 0x6C]
	mov r1, r10
	mov r2, r8
	movs r3, 0
	bl sub_806195C
	movs r2, 0
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0xB
	beq _08061684
_08061676:
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08061684
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xB
	bne _08061676
_08061684:
	ldr r4, _0806172C
	movs r1, 0
	strh r2, [r4, 0x1A]
	movs r0, 0x8
	strh r0, [r4, 0x1C]
	strh r1, [r4, 0x1E]
	strh r1, [r4, 0x20]
	strh r1, [r4, 0x4]
	movs r0, 0x10
	strh r0, [r4, 0x6]
	strh r1, [r4, 0xC]
	strh r1, [r4, 0xE]
	strh r1, [r4, 0x14]
	str r1, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	add r2, sp, 0x70
	ldrh r2, [r2]
	strh r2, [r4, 0x18]
	mov r9, r4
	mov r6, r10
_080616BA:
	mov r0, r9
	bl AddMenuCursorSprite
	ldrb r0, [r6, 0x8]
	cmp r0, 0xB
	beq _080616CA
	bl sub_80623B0
_080616CA:
	ldr r0, [sp, 0x6C]
	cmp r0, 0
	beq _080616D4
	bl sub_8062230
_080616D4:
	movs r0, 0x3D
	bl sub_803E46C
	ldr r0, _08061730
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08061740
	movs r0, 0x1
	bl sub_8083CE0
	mov r1, r9
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0x7
	bne _08061738
	ldrb r0, [r6, 0x8]
	cmp r0, 0xB
	beq _0806171A
	ldr r5, [sp, 0x6C]
	adds r5, 0x1
	ldr r6, _08061734
	movs r4, 0x5
_08061704:
	ldr r1, [r6]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x3D
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061704
	str r5, [sp, 0x6C]
_0806171A:
	movs r0, 0x7
	str r0, [sp, 0x70]
	b _08061926
	.align 2, 0
_08061720: .4byte gUnknown_202F270
_08061724: .4byte gDungeonGlobalData
_08061728: .4byte 0x0001357c
_0806172C: .4byte gUnknown_202EE10
_08061730: .4byte gRealInputs
_08061734: .4byte gUnknown_203B080
_08061738:
	mov r0, r9
	movs r1, 0
	bl sub_80136E0
_08061740:
	ldr r0, _08061788
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0806179C
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _0806178C
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08061794
	ldr r0, [sp, 0x6C]
	cmp r0, 0
	beq _08061780
	adds r5, r0, 0
	subs r5, 0x1
	ldr r6, _08061790
	movs r4, 0x5
_0806176A:
	ldr r1, [r6]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x3D
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _0806176A
	str r5, [sp, 0x6C]
_08061780:
	movs r1, 0
	str r1, [sp, 0x70]
	b _08061926
	.align 2, 0
_08061788: .4byte gRealInputs
_0806178C: .4byte gUnknown_202EE10
_08061790: .4byte gUnknown_203B084
_08061794:
	adds r0, r1, 0
	movs r1, 0
	bl sub_8013744
_0806179C:
	ldr r4, _080617C8
	ldrh r1, [r4, 0x2]
	movs r0, 0x8
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _080617DE
	mov r2, r9
	movs r1, 0x18
	ldrsh r0, [r2, r1]
	mov r2, r10
	adds r1, r2, r0
	ldrb r4, [r1]
	str r0, [sp, 0x70]
	bl sub_8083D44
	adds r0, r4, 0
	bl sub_8062748
_080617C4:
	movs r7, 0
	b _08061926
	.align 2, 0
_080617C8: .4byte gRealInputs
_080617CC:
	bl sub_8083D08
	mov r0, r9
	movs r1, 0x18
	ldrsh r4, [r0, r1]
	cmp r4, 0
	beq _080617DC
	b _08061900
_080617DC:
	b _080618C4
_080617DE:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080617F4
	ldr r2, _080618BC
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	bne _080617F4
	b _0806190C
_080617F4:
	mov r2, r9
	movs r0, 0x18
	ldrsh r1, [r2, r0]
	mov r2, r10
	adds r0, r2, r1
	ldrb r7, [r0]
	str r1, [sp, 0x70]
	bl sub_8062D68
	bl sub_8083D08
	ldr r0, _080618C0
	str r5, [r0]
	movs r0, 0x2F
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0xC
	movs r1, 0
	bl sub_8044F5C
	ldr r0, [sp, 0x74]
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08061832
	movs r0, 0x2F
	bl sub_8044FF0
_08061832:
	mov r0, sp
	movs r1, 0x16
	bl sub_805FC30
	ldr r5, _080618BC
	adds r6, r4, 0
	adds r4, r5, 0
	adds r4, 0x2A
_08061842:
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x3D
	bl sub_803E46C
	ldrh r1, [r6, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08061866
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80136E0
_08061866:
	ldrh r1, [r6, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0806187E
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8013744
_0806187E:
	ldrh r1, [r6, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08061892
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _080618A4
_08061892:
	movs r1, 0x18
	ldrsh r0, [r5, r1]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	bne _080617CC
	bl sub_8083D30
_080618A4:
	ldrh r1, [r6, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080618B4
	ldrb r0, [r4]
	cmp r0, 0
	beq _08061842
_080618B4:
	bl sub_8083D30
	b _080617C4
	.align 2, 0
_080618BC: .4byte gUnknown_202EE10
_080618C0: .4byte gUnknown_202EE6C
_080618C4:
	ldr r0, _080618FC
	bl PlaySoundEffect
	mov r0, r8
	adds r0, 0x94
	strb r7, [r0]
	mov r1, r8
	adds r1, 0x78
	movs r0, 0x6
	strb r0, [r1]
	mov r0, r8
	adds r0, 0x80
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	subs r0, 0x8
	strh r4, [r0]
	mov r2, r8
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _080618F0
	b _080617C4
_080618F0:
	ldr r0, [sp, 0x74]
	movs r1, 0x1
	bl MoveIfPossible
	b _080617C4
	.align 2, 0
_080618FC: .4byte 0x00000133
_08061900:
	adds r0, r7, 0
	bl sub_8062748
	movs r0, 0
	str r0, [sp, 0x78]
	b _080617C4
_0806190C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08061920
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _08061920
	b _080616BA
_08061920:
	bl sub_8083D30
	movs r7, 0x1
_08061926:
	ldr r1, [sp, 0x78]
	cmp r1, 0
	beq _08061932
	ldr r0, _08061958
	bl AddMenuCursorSprite
_08061932:
	movs r0, 0x3D
	bl sub_803E46C
	cmp r7, 0
	bne _0806193E
	b _08061646
_0806193E:
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
	.align 2, 0
_08061958: .4byte gUnknown_202EE10
	thumb_func_end sub_80615E8

	thumb_func_start sub_806195C
sub_806195C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r5, r0, 0
	mov r9, r1
	str r2, [sp, 0x10]
	adds r7, r3, 0
	subs r5, 0x1
	adds r0, r7, 0
	bl sub_80073B8
	ldr r0, _080619B4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	adds r3, r7, 0
	bl xxx_call_draw_string
	movs r0, 0x14
	mov r8, r0
	movs r1, 0xB
	mov r0, r9
	adds r0, 0x8
_08061994:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, r9
	bge _08061994
	bl sub_8083654
	ldrb r1, [r0, 0x9]
	add r0, sp, 0x4
	bl sub_808EB0C
	movs r6, 0x1
	negs r6, r6
	movs r1, 0
	mov r10, r1
	b _080619FC
	.align 2, 0
_080619B4: .4byte gUnknown_80FE954
_080619B8:
	ldr r0, _080619DC
	adds r1, r4, 0
	bl CopyTacticsNameToBuffer
	ldr r0, [sp, 0x10]
	adds r0, 0x94
	ldrb r0, [r0]
	cmp r0, r4
	bne _080619E4
	mov r0, r10
	str r0, [sp]
	movs r0, 0x10
	mov r1, r8
	ldr r2, _080619E0
	adds r3, r7, 0
	bl xxx_format_and_draw
	b _080619F4
	.align 2, 0
_080619DC: .4byte gAvailablePokemonNames
_080619E0: .4byte gUnknown_8106BEC
_080619E4:
	mov r1, r10
	str r1, [sp]
	movs r0, 0x10
	mov r1, r8
	ldr r2, _08061A34
	adds r3, r7, 0
	bl xxx_format_and_draw
_080619F4:
	adds r6, 0x1
	movs r0, 0xC
	add r8, r0
	adds r5, 0x1
_080619FC:
	cmp r6, 0x9
	bgt _08061A1E
	cmp r5, 0
	blt _080619F4
	cmp r5, 0xB
	bgt _080619F4
	mov r0, sp
	adds r0, r5
	adds r0, 0x4
	ldrb r4, [r0]
	cmp r6, 0x8
	bhi _08061A1A
	mov r1, r9
	adds r0, r1, r6
	strb r4, [r0]
_08061A1A:
	cmp r4, 0xB
	bne _080619B8
_08061A1E:
	adds r0, r7, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061A34: .4byte gUnknown_8106BF4
	thumb_func_end sub_806195C

	thumb_func_start sub_8061A38
sub_8061A38:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x130
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	add r4, sp, 0xB0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [r4, 0x4]
	movs r1, 0x2
	strh r1, [r4, 0x8]
	strh r1, [r4, 0xA]
	movs r2, 0x12
	strh r2, [r4, 0xC]
	movs r0, 0xE
	strh r0, [r4, 0xE]
	strh r2, [r4, 0x10]
	strh r1, [r4, 0x12]
	ldr r0, _08061AA4
	str r0, [r4, 0x14]
	movs r0, 0x3
	str r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	str r0, [r4, 0x4C]
	movs r0, 0
	str r0, [sp, 0x114]
	mov r8, r0
	ldr r0, _08061AA8
	ldr r1, [r0]
	ldrb r0, [r5, 0x4]
	lsls r0, 2
	ldr r2, _08061AAC
	adds r1, r2
	adds r1, r0
	ldr r1, [r1]
	str r1, [sp, 0x110]
	ldr r0, [r1, 0x70]
	str r0, [sp, 0x11C]
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08061AA0
	cmp r0, 0x47
	bne _08061AB0
_08061AA0:
	movs r0, 0x1
	b _08061AB2
	.align 2, 0
_08061AA4: .4byte gUnknown_202F270
_08061AA8: .4byte gDungeonGlobalData
_08061AAC: .4byte 0x0001357c
_08061AB0:
	movs r0, 0
_08061AB2:
	adds r1, r0, 0
	cmp r1, 0
	beq _08061ACE
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	str r0, [sp, 0x18]
	movs r1, 0x1
	str r1, [sp, 0x118]
	b _08061AFE
_08061ACE:
	cmp r6, 0
	beq _08061AE6
	movs r0, 0x4
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	str r1, [sp, 0x10]
	str r1, [sp, 0x14]
	str r1, [sp, 0x18]
	movs r2, 0x1
	str r2, [sp, 0x118]
	b _08061AFE
_08061AE6:
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x3
	str r0, [sp, 0xC]
	movs r0, 0x5
	str r0, [sp, 0x10]
	str r6, [sp, 0x14]
	str r6, [sp, 0x18]
	movs r0, 0x4
	str r0, [sp, 0x118]
_08061AFE:
	add r2, sp, 0x5C
	movs r0, 0
	strh r0, [r2]
	mov r1, sp
	adds r1, 0x72
	strh r0, [r1]
	ldr r3, _08061BB4
	strh r0, [r3, 0x18]
	subs r1, 0x56
	str r1, [sp, 0x12C]
	add r2, sp, 0x80
	mov r9, r2
	adds r7, r3, 0
_08061B18:
	movs r0, 0
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x120]
	movs r2, 0
	str r2, [sp, 0x124]
	movs r0, 0x1
	str r0, [sp, 0x128]
	ldr r4, _08061BB8
	ldr r1, _08061BBC
	add r2, sp, 0x118
	ldrb r2, [r2]
	strb r2, [r1]
	add r0, sp, 0x114
	ldrb r0, [r0]
	strb r0, [r1, 0x1]
	movs r0, 0xA
	strb r0, [r1, 0x2]
	mov r2, r10
	strb r2, [r1, 0x3]
	add r0, sp, 0xB0
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, [sp, 0x12C]
	ldr r1, [sp, 0x110]
	bl sub_8069844
	ldr r1, [sp, 0x114]
	lsls r0, r1, 2
	mov r5, sp
	adds r5, r0
	adds r5, 0x4
	ldr r0, [r5]
	mov r2, r10
	str r2, [sp]
	ldr r2, [sp, 0x12C]
	add r3, sp, 0x80
	bl CreatePokemonInfoTabScreen
	add r0, sp, 0x114
	ldrh r0, [r0]
	strh r0, [r7, 0x1E]
	add r1, sp, 0x118
	ldrh r1, [r1]
	strh r1, [r7, 0x20]
	movs r2, 0
	ldrsh r0, [r4, r2]
	adds r0, 0xF
	lsls r0, 3
	strh r0, [r7, 0xC]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r7, 0xE]
	mov r2, r10
	strh r2, [r7, 0x14]
	strh r2, [r7, 0x4]
	movs r0, 0x10
	strh r0, [r7, 0x6]
	mov r0, r10
	str r0, [r7]
	adds r0, r7, 0
	adds r0, 0x28
	bl sub_801317C
	mov r1, r10
	strh r1, [r7, 0x18]
	strh r1, [r7, 0x1A]
	strh r1, [r7, 0x1C]
	ldr r5, [r5]
	cmp r5, 0x1
	bne _08061C10
	movs r2, 0
	add r1, sp, 0x8C
	b _08061BC8
	.align 2, 0
_08061BB4: .4byte gUnknown_202EE10
_08061BB8: .4byte gUnknown_2027370
_08061BBC: .4byte gUnknown_202F270
_08061BC0:
	adds r1, 0x4
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08061BCE
_08061BC8:
	ldr r0, [r1]
	cmp r0, 0
	bne _08061BC0
_08061BCE:
	cmp r2, 0
	beq _08061C44
	movs r0, 0x1
	str r0, [sp, 0x124]
	strh r2, [r7, 0x1A]
	b _08061C38
_08061BDA:
	movs r0, 0x18
	ldrsh r2, [r7, r0]
	lsls r1, r2, 2
	add r0, sp, 0x8C
	adds r0, r1
	ldr r4, [r0]
	mov r8, r2
	bl sub_8083D44
	adds r0, r4, 0
	bl sub_806285C
	movs r1, 0
	str r1, [sp, 0x128]
	b _080621E4
_08061BF8:
	movs r2, 0x18
	ldrsh r0, [r7, r2]
	mov r2, r9
	adds r1, r2, r0
	ldrb r4, [r1]
	mov r8, r0
	bl sub_8083D44
	adds r0, r4, 0
	bl sub_806262C
	b _08062082
_08061C10:
	cmp r5, 0x4
	bne _08061C48
	movs r1, 0
	add r2, sp, 0x80
	ldrb r0, [r2]
	cmp r0, 0
	beq _08061C2E
	mov r2, r9
_08061C20:
	adds r1, 0x1
	cmp r1, 0x7
	bgt _08061C2E
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _08061C20
_08061C2E:
	cmp r1, 0
	beq _08061C44
	movs r0, 0x1
	str r0, [sp, 0x120]
	strh r1, [r7, 0x1A]
_08061C38:
	movs r0, 0x8
	strh r0, [r7, 0x1C]
	adds r0, r7, 0
	movs r1, 0
	bl sub_80137B0
_08061C44:
	mov r1, r8
	strh r1, [r7, 0x18]
_08061C48:
	ldr r0, _08061CF8
	bl AddMenuCursorSprite
	movs r0, 0
	ldr r1, _08061CFC
	bl sub_8014140
	adds r4, r0, 0
	movs r5, 0
	movs r6, 0
	ldr r2, [sp, 0x120]
	cmp r2, 0
	beq _08061C80
	mov r1, r9
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _08061C70
	movs r5, 0x1
	bl sub_80623B0
_08061C70:
	add r1, sp, 0x5C
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08061C80
	movs r6, 0x1
	bl sub_8062230
_08061C80:
	ldr r2, [sp, 0x124]
	cmp r2, 0
	beq _08061CA6
	mov r1, r9
	ldr r0, [r1, 0x2C]
	cmp r0, 0
	beq _08061C94
	movs r5, 0x1
	bl sub_80623B0
_08061C94:
	movs r1, 0x72
	add r1, sp
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08061CA6
	movs r6, 0x1
	bl sub_8062230
_08061CA6:
	movs r0, 0x1C
	bl sub_803E46C
	ldr r0, _08061D00
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _08061D4E
	bl sub_80048C8
	lsls r0, 24
	cmp r0, 0
	bne _08061D4E
	ldr r0, _08061D04
	ldrh r1, [r0, 0x2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08061CD6
	ldr r2, _08061CF8
	adds r0, r2, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _08061D08
_08061CD6:
	movs r0, 0
	bl sub_8083CE0
	ldr r2, [sp, 0x114]
	adds r2, 0x1
	str r2, [sp, 0x114]
	lsls r0, r2, 2
	add r0, sp
	adds r0, 0x4
	ldr r0, [r0]
	cmp r0, 0
	beq _08061CF0
	b _080621E6
_08061CF0:
	movs r0, 0
	str r0, [sp, 0x114]
	b _080621E6
	.align 2, 0
_08061CF8: .4byte gUnknown_202EE10
_08061CFC: .4byte gUnknown_8106B8C
_08061D00: .4byte gUnknown_202F270
_08061D04: .4byte gRealInputs
_08061D08:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08061D1A
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08061D4E
_08061D1A:
	movs r0, 0
	bl sub_8083CE0
	ldr r1, [sp, 0x114]
	subs r1, 0x1
	str r1, [sp, 0x114]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08061D30
	b _080621E6
_08061D30:
	movs r2, 0x5
	str r2, [sp, 0x114]
	ldr r0, [sp, 0x18]
	cmp r0, 0
	beq _08061D3C
	b _080621E6
_08061D3C:
	add r1, sp, 0x18
_08061D3E:
	subs r1, 0x4
	ldr r0, [sp, 0x114]
	subs r0, 0x1
	str r0, [sp, 0x114]
	ldr r0, [r1]
	cmp r0, 0
	beq _08061D3E
	b _080621E6
_08061D4E:
	ldr r1, [sp, 0x124]
	cmp r1, 0
	bne _08061D56
	b _08061E8A
_08061D56:
	cmp r4, 0x2
	bne _08061D98
	cmp r5, 0
	beq _08061D98
	movs r0, 0
	bl sub_8083CE0
	mov r2, r9
	ldr r0, [r2, 0x2C]
	cmp r0, 0
	beq _08061D8E
	ldr r5, _08061D94
	movs r4, 0x5
_08061D70:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061D70
	movs r1, 0x72
	add r1, sp
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_08061D8E:
	movs r2, 0x7
	mov r8, r2
	b _080621E6
	.align 2, 0
_08061D94: .4byte gUnknown_203B080
_08061D98:
	ldr r0, _08061DDC
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08061DF0
	movs r0, 0
	bl sub_8083CE0
	ldr r1, _08061DE0
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0x7
	bne _08061DE8
	mov r1, r9
	ldr r0, [r1, 0x2C]
	cmp r0, 0
	bne _08061DBE
	b _08061F04
_08061DBE:
	ldr r5, _08061DE4
	movs r4, 0x5
_08061DC2:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061DC2
	movs r2, 0x72
	add r2, sp
	b _08061EFE
	.align 2, 0
_08061DDC: .4byte gRealInputs
_08061DE0: .4byte gUnknown_202EE10
_08061DE4: .4byte gUnknown_203B080
_08061DE8:
	adds r0, r1, 0
	movs r1, 0
	bl sub_80136E0
_08061DF0:
	cmp r4, 0x1
	bne _08061E28
	cmp r6, 0
	beq _08061E28
	movs r2, 0x72
	add r2, sp
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _08061E06
	b _08061F96
_08061E06:
	ldr r5, _08061E24
	movs r4, 0x5
_08061E0A:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061E0A
	movs r1, 0x72
	add r1, sp
	b _08061F90
	.align 2, 0
_08061E24: .4byte gUnknown_203B084
_08061E28:
	ldr r0, _08061E74
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08061E36
	b _08061FB0
_08061E36:
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _08061E78
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08061E80
	movs r2, 0x72
	add r2, sp
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0
	bne _08061E54
	b _08061F96
_08061E54:
	ldr r5, _08061E7C
	movs r4, 0x5
_08061E58:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061E58
	movs r1, 0x72
	add r1, sp
	b _08061F90
	.align 2, 0
_08061E74: .4byte gRealInputs
_08061E78: .4byte gUnknown_202EE10
_08061E7C: .4byte gUnknown_203B084
_08061E80:
	adds r0, r1, 0
	movs r1, 0
	bl sub_8013744
	b _08061FB0
_08061E8A:
	ldr r0, [sp, 0x120]
	cmp r0, 0
	bne _08061E92
	b _08061FB0
_08061E92:
	cmp r4, 0x2
	bne _08061EC0
	cmp r5, 0
	beq _08061EC0
	mov r1, r9
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _08061F04
	ldr r5, _08061EBC
	movs r4, 0x5
_08061EA6:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061EA6
	b _08061EFC
	.align 2, 0
_08061EBC: .4byte gUnknown_203B080
_08061EC0:
	ldr r0, _08061F0C
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08061F20
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _08061F10
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0x7
	bne _08061F18
	mov r1, r9
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _08061F04
	ldr r5, _08061F14
	movs r4, 0x5
_08061EE8:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061EE8
_08061EFC:
	add r2, sp, 0x5C
_08061EFE:
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
_08061F04:
	movs r0, 0x7
	mov r8, r0
	b _080621E6
	.align 2, 0
_08061F0C: .4byte gRealInputs
_08061F10: .4byte gUnknown_202EE10
_08061F14: .4byte gUnknown_203B080
_08061F18:
	adds r0, r1, 0
	movs r1, 0
	bl sub_80136E0
_08061F20:
	cmp r4, 0x1
	bne _08061F50
	cmp r6, 0
	beq _08061F50
	add r2, sp, 0x5C
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _08061F96
	ldr r5, _08061F4C
	movs r4, 0x5
_08061F36:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061F36
	b _08061F8E
	.align 2, 0
_08061F4C: .4byte gUnknown_203B084
_08061F50:
	ldr r0, _08061F9C
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08061FB0
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _08061FA0
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08061FA8
	add r2, sp, 0x5C
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _08061F96
	ldr r5, _08061FA4
	movs r4, 0x5
_08061F7A:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08061F7A
_08061F8E:
	add r1, sp, 0x5C
_08061F90:
	ldrh r0, [r1]
	subs r0, 0x1
	strh r0, [r1]
_08061F96:
	movs r2, 0
	mov r8, r2
	b _080621E6
	.align 2, 0
_08061F9C: .4byte gRealInputs
_08061FA0: .4byte gUnknown_202EE10
_08061FA4: .4byte gUnknown_203B084
_08061FA8:
	adds r0, r1, 0
	movs r1, 0
	bl sub_8013744
_08061FB0:
	bl sub_80048C8
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08061FBE
	b _08061C48
_08061FBE:
	ldr r5, _0806208C
	ldrh r1, [r5, 0x2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08061FDA
	ldr r0, [sp, 0x124]
	cmp r0, 0
	beq _08061FD2
	b _08061BDA
_08061FD2:
	ldr r2, [sp, 0x120]
	cmp r2, 0
	beq _08061FDA
	b _08061BF8
_08061FDA:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08061FF0
	ldr r2, _08062090
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	bne _08061FF0
	b _080621CA
_08061FF0:
	ldr r0, [sp, 0x124]
	cmp r0, 0
	beq _080620BC
	movs r1, 0x18
	ldrsh r2, [r7, r1]
	lsls r1, r2, 2
	add r0, sp, 0x8C
	adds r0, r1
	ldr r6, [r0]
	mov r8, r2
	bl sub_8062D68
	ldr r0, _08062094
	str r4, [r0]
	bl sub_8083D08
	movs r0, 0xC
	movs r1, 0
	bl sub_8044F5C
	add r0, sp, 0xB0
	movs r1, 0x16
	bl sub_805FC30
	ldr r4, _08062090
	movs r2, 0x2A
	adds r2, r4
	mov r10, r2
_08062028:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x1C
	bl sub_803E46C
	ldrh r1, [r5, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806204C
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_0806204C:
	ldrh r1, [r5, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08062064
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_08062064:
	ldrh r1, [r5, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062078
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08062098
_08062078:
	bl sub_8083D08
	adds r0, r6, 0
	bl sub_806285C
_08062082:
	movs r0, 0
	str r0, [sp, 0x128]
	mov r10, r0
	b _080621E6
	.align 2, 0
_0806208C: .4byte gRealInputs
_08062090: .4byte gUnknown_202EE10
_08062094: .4byte gUnknown_202EE6C
_08062098:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080620A8
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0
	beq _08062028
_080620A8:
	bl sub_8083D30
	b _080621BA
_080620AE:
	bl sub_8083D08
	movs r1, 0x18
	ldrsh r0, [r7, r1]
	cmp r0, 0
	bne _080621B0
	b _08062198
_080620BC:
	ldr r2, [sp, 0x120]
	cmp r2, 0
	bne _080620C4
	b _080621C0
_080620C4:
	movs r0, 0x18
	ldrsh r1, [r7, r0]
	mov r2, r9
	adds r0, r2, r1
	ldrb r6, [r0]
	mov r8, r1
	bl sub_8062D68
	ldr r0, _08062190
	ldr r1, [sp, 0x124]
	str r1, [r0]
	bl sub_8083D08
	movs r0, 0x28
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0xC
	movs r1, 0
	bl sub_8044F5C
	ldr r0, [sp, 0x110]
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08062102
	movs r0, 0x28
	bl sub_8044FF0
_08062102:
	add r0, sp, 0xB0
	movs r1, 0x16
	bl sub_805FC30
	ldr r4, _08062194
	movs r2, 0x2A
	adds r2, r4
	mov r10, r2
_08062112:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x1C
	bl sub_803E46C
	ldrh r1, [r5, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08062136
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_08062136:
	ldrh r1, [r5, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0806214E
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_0806214E:
	ldrh r1, [r5, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062162
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08062174
_08062162:
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	bne _080620AE
	bl sub_8083D30
_08062174:
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08062186
	mov r2, r10
	ldrb r0, [r2]
	cmp r0, 0
	beq _08062112
_08062186:
	bl sub_8083D30
	movs r0, 0
	mov r10, r0
	b _080621E6
	.align 2, 0
_08062190: .4byte gUnknown_202EE6C
_08062194: .4byte gUnknown_202EE10
_08062198:
	ldr r0, _080621AC
	bl PlaySoundEffect
	ldr r0, [sp, 0x11C]
	adds r0, 0x8C
	adds r1, r6, 0
	bl sub_808EBF4
	b _080621BA
	.align 2, 0
_080621AC: .4byte 0x00000133
_080621B0:
	adds r0, r6, 0
	bl sub_806262C
	movs r1, 0
	str r1, [sp, 0x128]
_080621BA:
	movs r2, 0
	mov r10, r2
	b _080621E6
_080621C0:
	bl sub_8083D08
	movs r0, 0x1
	mov r10, r0
	b _080621E6
_080621CA:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080621DE
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080621DE
	b _08061C48
_080621DE:
	bl sub_8083D30
	movs r1, 0x1
_080621E4:
	mov r10, r1
_080621E6:
	ldr r2, [sp, 0x128]
	cmp r2, 0
	beq _08062204
	ldr r0, [sp, 0x120]
	cmp r0, 0
	bne _080621F8
	ldr r1, [sp, 0x124]
	cmp r1, 0
	beq _080621FE
_080621F8:
	ldr r0, _0806222C
	bl AddMenuCursorSprite
_080621FE:
	movs r0, 0x1C
	bl sub_803E46C
_08062204:
	mov r2, r10
	cmp r2, 0
	bne _0806220C
	b _08061B18
_0806220C:
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	ldr r0, [sp, 0x110]
	bl sub_807191C
	add sp, 0x130
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806222C: .4byte gUnknown_202EE10
	thumb_func_end sub_8061A38

	thumb_func_start sub_8062230
sub_8062230:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	ldr r0, _08062380
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08062248
	b _08062372
_08062248:
	ldr r0, _08062384
	mov r9, r0
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _08062388
	ands r1, r0
	ldr r3, _0806238C
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08062390
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r6, _08062394
	mov r8, r6
	mov r0, r8
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08062398
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0806239C
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r6, _080623A0
	adds r0, r6, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	movs r1, 0x80
	lsls r1, 6
	mov r5, sp
	ldrh r0, [r5, 0x2]
	ldr r2, _080623A4
	ands r2, r0
	orrs r2, r1
	ands r2, r6
	movs r3, 0xFC
	lsls r3, 2
	ldrh r1, [r5, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r3
	mov r1, r8
	ands r0, r1
	movs r3, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _080623A8
	ands r0, r4
	orrs r0, r1
	strh r0, [r5, 0x4]
	mov r6, r9
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x8
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r5, 0x6]
	ands r3, r1
	orrs r3, r0
	strh r3, [r5, 0x6]
	movs r3, 0
	ldrsh r0, [r6, r3]
	lsls r0, 3
	adds r0, 0x40
	ldr r1, _080623AC
	ands r0, r1
	movs r1, 0xFE
	lsls r1, 8
	ands r2, r1
	orrs r2, r0
	strh r2, [r5, 0x2]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08062372:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062380: .4byte gUnknown_202EDCC
_08062384: .4byte gUnknown_2027370
_08062388: .4byte 0x0000feff
_0806238C: .4byte 0xffff0000
_08062390: .4byte 0x0000fdff
_08062394: .4byte 0x0000f3ff
_08062398: .4byte 0x0000efff
_0806239C: .4byte 0x0000dfff
_080623A0: .4byte 0x00003fff
_080623A4: .4byte 0x0000c1ff
_080623A8: .4byte 0x00000fff
_080623AC: .4byte 0x000001ff
	thumb_func_end sub_8062230

	thumb_func_start sub_80623B0
sub_80623B0:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r0, _080624D4
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080623C2
	b _080624CA
_080623C2:
	ldr r6, _080624D8
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _080624DC
	ands r1, r0
	ldr r3, _080624E0
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080624E4
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r5, _080624E8
	adds r0, r5, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080624EC
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080624F0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080624F4
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r2, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _080624F8
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x70
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r3, 0x6]
	ands r2, r1
	orrs r2, r0
	strh r2, [r3, 0x6]
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x40
	ldr r1, _080624FC
	ands r0, r1
	strh r0, [r3, 0x2]
	subs r1, 0xFF
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080624CA:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080624D4: .4byte gUnknown_202EDCC
_080624D8: .4byte gUnknown_2027370
_080624DC: .4byte 0x0000feff
_080624E0: .4byte 0xffff0000
_080624E4: .4byte 0x0000fdff
_080624E8: .4byte 0x0000f3ff
_080624EC: .4byte 0x0000efff
_080624F0: .4byte 0x0000dfff
_080624F4: .4byte 0x00003fff
_080624F8: .4byte 0x00000fff
_080624FC: .4byte 0x000001ff
	thumb_func_end sub_80623B0

	thumb_func_start sub_8062500
sub_8062500:
	push {r4,r5,lr}
	ldr r0, _0806257C
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08062574
	ldr r5, _08062580
	ldr r0, _08062584
	ldrh r2, [r0]
	ldr r1, _08062588
	ands r1, r2
	ldr r2, _0806258C
	ands r1, r2
	ldr r4, _08062590
	ands r1, r4
	ldr r2, _08062594
	ands r1, r2
	ldr r2, _08062598
	ands r1, r2
	movs r3, 0x80
	lsls r3, 7
	ldr r2, _0806259C
	ands r1, r2
	orrs r1, r3
	strh r1, [r0]
	movs r3, 0xFC
	lsls r3, 2
	ldrh r2, [r0, 0x4]
	movs r1, 0xFC
	lsls r1, 8
	ands r1, r2
	orrs r1, r3
	ands r1, r4
	movs r3, 0xF
	movs r2, 0xF0
	lsls r2, 8
	ldr r4, _080625A0
	ands r1, r4
	orrs r1, r2
	strh r1, [r0, 0x4]
	movs r2, 0x2
	ldrsh r1, [r5, r2]
	lsls r1, 3
	adds r1, 0x60
	ands r1, r4
	lsls r1, 4
	ldrh r2, [r0, 0x6]
	ands r3, r2
	orrs r3, r1
	strh r3, [r0, 0x6]
	movs r1, 0x70
	strh r1, [r0, 0x2]
	adds r1, 0x90
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08062574:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806257C: .4byte gUnknown_202EDCC
_08062580: .4byte gUnknown_2027370
_08062584: .4byte gUnknown_202F268
_08062588: .4byte 0x0000feff
_0806258C: .4byte 0x0000fdff
_08062590: .4byte 0x0000f3ff
_08062594: .4byte 0x0000efff
_08062598: .4byte 0x0000dfff
_0806259C: .4byte 0x00003fff
_080625A0: .4byte 0x00000fff
	thumb_func_end sub_8062500

	thumb_func_start sub_80625A4
sub_80625A4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	adds r7, r0, 0
	mov r9, r1
	mov r0, sp
	bl sub_801317C
	movs r4, 0
	cmp r4, r7
	bge _0806261A
	subs r0, r7, 0x1
	mov r8, r0
	mov r5, sp
_080625C4:
	lsls r0, r4, 2
	add r0, r9
	ldr r0, [r0]
	mov r1, sp
	bl sub_80639E4
	adds r6, r4, 0x1
	b _080625E8
_080625D4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080625E2
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	beq _080625E8
_080625E2:
	bl sub_8083D30
	b _08062614
_080625E8:
	cmp r4, r8
	bge _080625F0
	bl sub_8062500
_080625F0:
	mov r0, sp
	movs r1, 0
	bl nullsub_34
	movs r0, 0x16
	bl sub_803E46C
	ldr r0, _08062628
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062610
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	beq _080625D4
_08062610:
	bl sub_8083D08
_08062614:
	adds r4, r6, 0
	cmp r4, r7
	blt _080625C4
_0806261A:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062628: .4byte gRealInputs
	thumb_func_end sub_80625A4

	thumb_func_start sub_806262C
sub_806262C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x88
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	mov r0, sp
	adds r0, 0x70
	str r0, [sp, 0x84]
	add r0, sp, 0x10
	mov r8, r0
	movs r0, 0
	mov r9, r0
	add r7, sp, 0x4
	add r6, sp, 0x80
_08062650:
	add r0, sp, 0x4
	bl sub_801317C
	mov r0, r8
	bl sub_80140B4
	mov r0, r8
	str r6, [r0, 0x14]
	movs r1, 0x1
	add r0, sp, 0x80
	strb r1, [r0]
	mov r0, r9
	strb r0, [r6, 0x1]
	movs r0, 0x10
	strb r0, [r6, 0x2]
	mov r0, r9
	strb r0, [r6, 0x3]
	mov r0, r8
	bl sub_803ECB4
	movs r0, 0
	bl sub_80073B8
	mov r0, r10
	bl GetIQSkillName
	adds r1, r0, 0
	ldr r0, _080626CC
	bl strcpy
	ldr r0, _080626D0
	ldr r2, [r0]
	mov r0, r9
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	mov r0, r10
	bl GetIQSkillDescription
	adds r2, r0, 0
	mov r0, r9
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x10
	movs r3, 0
	bl xxx_format_and_draw
	movs r0, 0
	bl sub_80073E0
	mov r0, r10
	bl GetIQSkillDescription
	ldr r1, [sp, 0x84]
	bl sub_8097DF0
	adds r5, r0, 0
	b _080626EA
	.align 2, 0
_080626CC: .4byte gUnknown_202DE58
_080626D0: .4byte gUnknown_80FE95C
_080626D4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080626E2
	ldrb r0, [r7, 0x2]
	cmp r0, 0
	beq _080626EA
_080626E2:
	movs r4, 0x1
	bl sub_8083D30
	b _08062718
_080626EA:
	cmp r5, 0
	beq _080626F2
	bl sub_8062500
_080626F2:
	add r0, sp, 0x4
	movs r1, 0
	bl nullsub_34
	movs r0, 0x16
	bl sub_803E46C
	ldr r0, _0806272C
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062712
	ldrb r0, [r7, 0x1]
	cmp r0, 0
	beq _080626D4
_08062712:
	movs r4, 0
	bl sub_8083D08
_08062718:
	cmp r4, 0
	bne _08062730
	cmp r5, 0
	beq _08062730
	adds r0, r5, 0
	ldr r1, [sp, 0x84]
	bl sub_80625A4
	b _08062650
	.align 2, 0
_0806272C: .4byte gRealInputs
_08062730:
	movs r0, 0x4
	movs r1, 0x3E
	bl sub_803E708
	add sp, 0x88
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806262C

	thumb_func_start sub_8062748
sub_8062748:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x88
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	mov r0, sp
	adds r0, 0x70
	str r0, [sp, 0x84]
	add r0, sp, 0x10
	mov r8, r0
	movs r0, 0
	mov r9, r0
	add r7, sp, 0x4
	add r6, sp, 0x80
_0806276C:
	add r0, sp, 0x4
	bl sub_801317C
	mov r0, r8
	bl sub_80140B4
	mov r0, r8
	str r6, [r0, 0x14]
	movs r1, 0x1
	add r0, sp, 0x80
	strb r1, [r0]
	mov r0, r9
	strb r0, [r6, 0x1]
	movs r0, 0x10
	strb r0, [r6, 0x2]
	mov r0, r9
	strb r0, [r6, 0x3]
	mov r0, r8
	bl sub_803ECB4
	movs r0, 0
	bl sub_80073B8
	ldr r0, _080627E0
	mov r1, r10
	bl CopyTacticsNameToBuffer
	ldr r0, _080627E4
	ldr r2, [r0]
	mov r0, r9
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	mov r0, r10
	bl GetTacticsDescription
	adds r2, r0, 0
	mov r0, r9
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x10
	movs r3, 0
	bl xxx_format_and_draw
	movs r0, 0
	bl sub_80073E0
	mov r0, r10
	bl GetTacticsDescription
	ldr r1, [sp, 0x84]
	bl sub_8097DF0
	adds r5, r0, 0
	b _080627FE
	.align 2, 0
_080627E0: .4byte gUnknown_202DE58
_080627E4: .4byte gUnknown_80FE960
_080627E8:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080627F6
	ldrb r0, [r7, 0x2]
	cmp r0, 0
	beq _080627FE
_080627F6:
	movs r4, 0x1
	bl sub_8083D30
	b _0806282C
_080627FE:
	cmp r5, 0
	beq _08062806
	bl sub_8062500
_08062806:
	add r0, sp, 0x4
	movs r1, 0
	bl nullsub_34
	movs r0, 0x3E
	bl sub_803E46C
	ldr r0, _08062840
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062826
	ldrb r0, [r7, 0x1]
	cmp r0, 0
	beq _080627E8
_08062826:
	movs r4, 0
	bl sub_8083D08
_0806282C:
	cmp r4, 0
	bne _08062844
	cmp r5, 0
	beq _08062844
	adds r0, r5, 0
	ldr r1, [sp, 0x84]
	bl sub_80625A4
	b _0806276C
	.align 2, 0
_08062840: .4byte gRealInputs
_08062844:
	movs r0, 0x4
	movs r1, 0x3E
	bl sub_803E708
	add sp, 0x88
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8062748

	thumb_func_start sub_806285C
sub_806285C:
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0xD4
	mov r10, r0
	add r0, sp, 0x10
	mov r8, r0
	add r5, sp, 0x70
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x74]
	add r1, sp, 0x78
	movs r6, 0
	movs r0, 0
	mov r9, r0
	movs r0, 0x2
	strh r0, [r1]
	strh r0, [r1, 0x2]
	add r1, sp, 0x7C
	movs r0, 0x1A
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x7E
	movs r1, 0xC
	strh r1, [r0]
	add r0, sp, 0x80
	strh r1, [r0]
	add r0, sp, 0x84
	add r4, sp, 0xD0
	str r4, [r0]
	add r0, sp, 0x88
	movs r1, 0x3
	str r1, [r0, 0x4]
	add r0, sp, 0xA0
	str r1, [r0, 0x4]
	add r0, sp, 0xB8
	str r1, [r0, 0x4]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x60
	bl memcpy
	add r0, sp, 0x4
	bl sub_801317C
	movs r0, 0x1
	strb r0, [r4]
	strb r6, [r4, 0x1]
	movs r0, 0x10
	strb r0, [r4, 0x2]
	strb r6, [r4, 0x3]
	mov r0, r8
	movs r1, 0x1
	bl sub_803ECB4
	movs r0, 0
	bl sub_80073B8
	mov r0, r10
	bl sub_808E4FC
	adds r1, r0, 0
	ldr r0, _0806291C
	bl strcpy
	ldr r0, _08062920
	ldr r2, [r0]
	mov r0, r9
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	mov r0, r10
	bl sub_808E51C
	adds r2, r0, 0
	mov r0, r9
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x10
	movs r3, 0
	bl xxx_format_and_draw
	movs r0, 0
	bl sub_80073E0
	add r4, sp, 0x4
	b _08062938
	.align 2, 0
_0806291C: .4byte gUnknown_202DE58
_08062920: .4byte gUnknown_80FE964
_08062924:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08062932
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _08062938
_08062932:
	bl sub_8083D30
	b _0806295C
_08062938:
	add r0, sp, 0x4
	movs r1, 0
	bl nullsub_34
	movs r0, 0x16
	bl sub_803E46C
	ldr r0, _08062974
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062958
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _08062924
_08062958:
	bl sub_8083D08
_0806295C:
	movs r0, 0x4
	movs r1, 0x3E
	bl sub_803E708
	add sp, 0xD4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062974: .4byte gRealInputs
	thumb_func_end sub_806285C

	thumb_func_start DrawFieldGiveItemMenu
DrawFieldGiveItemMenu:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x80
	mov r8, r0
	adds r6, r1, 0
	add r4, sp, 0x1C
	ldr r1, _080629AC
	adds r0, r4, 0
	movs r2, 0x60
	bl memcpy
	movs r0, 0
	str r0, [sp, 0x7C]
	mov r1, r8
	cmp r1, 0
	beq _080629A2
	subs r0, 0x1
	str r0, [r1]
_080629A2:
	cmp r6, 0x1
	bne _080629BA
	add r1, sp, 0x4C
	ldr r0, _080629B0
	b _080629C2
	.align 2, 0
_080629AC: .4byte gUnknown_8106C30
_080629B0: .4byte gUnknown_8106C00
_080629B4:
	bl sub_8083D08
	b _08062AF4
_080629BA:
	cmp r6, 0x2
	bne _080629CA
	add r1, sp, 0x4C
	ldr r0, _08062A38
_080629C2:
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
_080629CA:
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0
	bl DrawFieldTeamMenu
	movs r0, 0x1
	bl sub_80073B8
	ldr r0, _08062A3C
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0x3
	movs r3, 0x1
	bl xxx_call_draw_string
	movs r0, 0x1
	bl sub_80073E0
	ldr r0, _08062A40
	mov r9, r0
	add r7, sp, 0x8
	ldr r1, _08062A44
	mov r10, r1
_080629FC:
	mov r2, r10
	movs r3, 0x18
	ldrsh r0, [r2, r3]
	lsls r0, 2
	adds r0, r7, r0
	ldr r5, [r0]
	cmp r5, 0
	blt _08062A70
	ldr r0, _08062A48
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08062A4C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08062A5A
	cmp r9, r5
	beq _08062A5A
	cmp r6, 0x1
	bne _08062A50
	adds r0, r4, 0
	bl sub_8062B74
	b _08062A5A
	.align 2, 0
_08062A38: .4byte gUnknown_8106C18
_08062A3C: .4byte gWhichTextPtr2
_08062A40: .4byte 0xfffffc27
_08062A44: .4byte gUnknown_202EE10
_08062A48: .4byte gDungeonGlobalData
_08062A4C: .4byte 0x0001357c
_08062A50:
	cmp r6, 0x2
	bne _08062A5A
	adds r0, r4, 0
	bl sub_8062CA8
_08062A5A:
	mov r9, r5
	adds r0, r4, 0
	movs r1, 0
	bl sub_806A2BC
	adds r0, r4, 0x4
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
_08062A70:
	ldr r5, _08062B40
	adds r0, r5, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	ldr r4, _08062B44
	ldrh r1, [r4, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08062A98
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80136E0
_08062A98:
	ldrh r1, [r4, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08062AB0
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8013744
_08062AB0:
	ldrh r1, [r4, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062AC4
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08062AD8
_08062AC4:
	movs r3, 0x18
	ldrsh r0, [r5, r3]
	add r1, sp, 0x18
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08062AD4
	b _080629B4
_08062AD4:
	bl sub_8083D30
_08062AD8:
	ldr r0, _08062B44
	ldrh r1, [r0, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08062AEC
	ldr r5, _08062B48
	ldrb r0, [r5]
	cmp r0, 0
	beq _080629FC
_08062AEC:
	bl sub_8083D30
	movs r0, 0x1
	str r0, [sp, 0x7C]
_08062AF4:
	ldr r4, _08062B40
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	bl sub_804AA60
	bl sub_8083600
	movs r1, 0
	bl sub_806A2BC
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x4
	movs r1, 0x3E
	bl sub_803E708
	ldr r1, [sp, 0x7C]
	cmp r1, 0
	bne _08062B3C
	movs r2, 0x18
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r7, r0
	ldr r5, [r0]
	mov r3, r8
	cmp r3, 0
	beq _08062B38
	str r5, [r3]
_08062B38:
	cmp r5, 0
	bge _08062B4C
_08062B3C:
	movs r0, 0
	b _08062B5A
	.align 2, 0
_08062B40: .4byte gUnknown_202EE10
_08062B44: .4byte gRealInputs
_08062B48: .4byte gUnknown_202EE3A
_08062B4C:
	ldr r0, _08062B6C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r5, _08062B70
	adds r0, r5
	adds r0, r1
	ldr r0, [r0]
_08062B5A:
	add sp, 0x80
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08062B6C: .4byte gDungeonGlobalData
_08062B70: .4byte 0x0001357c
	thumb_func_end DrawFieldGiveItemMenu

	thumb_func_start sub_8062B74
sub_8062B74:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r10, r0
	ldr r0, [r0, 0x70]
	mov r9, r0
	movs r0, 0x2
	bl sub_8008C54
	movs r0, 0x2
	bl sub_80073B8
	ldr r0, _08062BD0
	mov r1, r10
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08062BD4
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0x2
	bl xxx_format_and_draw
	movs r1, 0x10
	mov r8, r1
	mov r0, r9
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08062BDE
	mov r0, r9
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08062BCA
	cmp r0, 0x47
	bne _08062BD8
_08062BCA:
	movs r0, 0x1
	b _08062BDA
	.align 2, 0
_08062BD0: .4byte gAvailablePokemonNames
_08062BD4: .4byte gUnknown_80FE978
_08062BD8:
	movs r0, 0
_08062BDA:
	cmp r0, 0
	beq _08062BF4
_08062BDE:
	ldr r2, _08062BF0
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	mov r1, r8
	movs r3, 0x2
	bl xxx_format_and_draw
	b _08062C8A
	.align 2, 0
_08062BF0: .4byte gUnknown_8106C90
_08062BF4:
	movs r7, 0
	movs r4, 0x8C
	lsls r4, 1
	add r4, r9
	adds r5, r4, 0
_08062BFE:
	add r0, sp, 0x4
	movs r1, 0
	movs r2, 0xC
	bl memset
	movs r0, 0x6A
	str r0, [sp, 0x8]
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08062C80
	mov r1, r9
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08062C22
	movs r0, 0x2
	b _08062C24
_08062C22:
	movs r0, 0x4
_08062C24:
	str r0, [sp, 0x4]
	mov r0, r10
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_80573CC
	add r1, sp, 0x4
	movs r2, 0
	lsls r0, 24
	cmp r0, 0
	bne _08062C3C
	movs r2, 0x1
_08062C3C:
	strb r2, [r1, 0x8]
	ldr r0, _08062CA0
	adds r1, r5, 0
	add r2, sp, 0x4
	bl sub_80928C0
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	movs r6, 0xD
	cmp r0, 0
	bne _08062C6C
	movs r6, 0x8
	cmp r7, 0
	beq _08062C6C
	mov r2, r8
	subs r2, 0x2
	movs r0, 0x7
	str r0, [sp]
	movs r0, 0x2
	movs r1, 0xC
	movs r3, 0x78
	bl sub_80078A4
_08062C6C:
	movs r0, 0
	str r0, [sp]
	adds r0, r6, 0
	mov r1, r8
	ldr r2, _08062CA4
	movs r3, 0x2
	bl xxx_format_and_draw
	movs r0, 0xC
	add r8, r0
_08062C80:
	adds r4, 0x8
	adds r5, 0x8
	adds r7, 0x1
	cmp r7, 0x3
	ble _08062BFE
_08062C8A:
	movs r0, 0x2
	bl sub_80073E0
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062CA0: .4byte gUnknown_202DE58
_08062CA4: .4byte gUnknown_8106C98
	thumb_func_end sub_8062B74

	thumb_func_start sub_8062CA8
sub_8062CA8:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r5, [r4, 0x70]
	movs r0, 0x2
	bl sub_8008C54
	movs r0, 0x2
	bl sub_80073B8
	ldr r0, _08062CF8
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08062CFC
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0x2
	bl xxx_format_and_draw
	movs r7, 0x8
	movs r6, 0x12
	adds r0, r5, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08062D08
	adds r0, r5, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _08062CF4
	cmp r0, 0x47
	bne _08062D00
_08062CF4:
	movs r0, 0x1
	b _08062D02
	.align 2, 0
_08062CF8: .4byte gAvailablePokemonNames
_08062CFC: .4byte gUnknown_80FE940
_08062D00:
	movs r0, 0
_08062D02:
	adds r4, r0, 0
	cmp r4, 0
	beq _08062D18
_08062D08:
	ldr r2, _08062D14
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	b _08062D2C
	.align 2, 0
_08062D14: .4byte gUnknown_8106C90
_08062D18:
	adds r2, r5, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08062D3C
	ldr r2, _08062D38
	str r4, [sp]
	adds r0, r7, 0
_08062D2C:
	adds r1, r6, 0
	movs r3, 0x2
	bl xxx_format_and_draw
	b _08062D52
	.align 2, 0
_08062D38: .4byte gUnknown_8106C9C
_08062D3C:
	ldr r0, _08062D60
	adds r1, r2, 0
	bl sub_8045C18
	ldr r2, _08062D64
	str r4, [sp]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r3, 0x2
	bl xxx_format_and_draw
_08062D52:
	movs r0, 0x2
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062D60: .4byte gUnknown_202DE58
_08062D64: .4byte gUnknown_8106C98
	thumb_func_end sub_8062CA8

	thumb_func_start sub_8062D68
sub_8062D68:
	push {lr}
	ldr r0, _08062D84
	movs r1, 0
	strh r1, [r0, 0x1E]
	strh r1, [r0, 0x20]
	strh r1, [r0, 0xC]
	strh r1, [r0, 0xE]
	strh r1, [r0, 0x14]
	adds r0, 0x28
	bl sub_801317C
	pop {r0}
	bx r0
	.align 2, 0
_08062D84: .4byte gUnknown_202EE10
	thumb_func_end sub_8062D68

	thumb_func_start sub_8062D88
sub_8062D88:
	movs r0, 0x1
	bx lr
	thumb_func_end sub_8062D88

	thumb_func_start sub_8062D8C
sub_8062D8C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r10, r0
	ldrb r5, [r0, 0x4]
	ldr r0, _08062E24
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08062E28
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x4]
	adds r7, r0, 0
_08062DAE:
	movs r0, 0
	mov r9, r0
	movs r6, 0
	movs r4, 0
	adds r2, r7, 0x4
	mov r8, r2
_08062DBA:
	ldr r0, _08062E24
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _08062E28
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl sub_8071A8C
	lsls r0, 24
	cmp r0, 0
	beq _08062DDA
	cmp r4, r5
	bne _08062DD8
	mov r9, r6
_08062DD8:
	adds r6, 0x1
_08062DDA:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08062DBA
	adds r0, r7, 0
	movs r1, 0
	bl sub_806A2BC
	mov r0, r8
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
	movs r0, 0x1
	bl sub_8044C10
	str r6, [sp]
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0x1
	mov r3, r9
	bl sub_8062F90
	lsls r0, 24
	cmp r0, 0
	beq _08062E10
	b _08062F80
_08062E10:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x6
	bne _08062E6C
	adds r6, r5, 0
	movs r4, 0
	b _08062E2E
	.align 2, 0
_08062E24: .4byte gDungeonGlobalData
_08062E28: .4byte 0x0001357c
_08062E2C:
	adds r4, 0x1
_08062E2E:
	cmp r4, 0x3
	bgt _08062E54
	adds r5, 0x1
	cmp r5, 0x3
	ble _08062E3A
	movs r5, 0
_08062E3A:
	ldr r0, _08062E64
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08062E68
	adds r0, r2
	adds r0, r1
	ldr r7, [r0]
	adds r0, r7, 0
	bl sub_8071A8C
	lsls r0, 24
	cmp r0, 0
	beq _08062E2C
_08062E54:
	mov r0, r10
	strb r5, [r0, 0x4]
	cmp r6, r5
	beq _08062F32
	movs r0, 0
	bl sub_8083CE0
	b _08062F32
	.align 2, 0
_08062E64: .4byte gDungeonGlobalData
_08062E68: .4byte 0x0001357c
_08062E6C:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x7
	bne _08062EC0
	adds r6, r5, 0
	movs r4, 0
	b _08062E80
_08062E7E:
	adds r4, 0x1
_08062E80:
	cmp r4, 0x3
	bgt _08062EA6
	subs r5, 0x1
	cmp r5, 0
	bge _08062E8C
	movs r5, 0x3
_08062E8C:
	ldr r0, _08062EB8
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _08062EBC
	adds r0, r2
	adds r0, r1
	ldr r7, [r0]
	adds r0, r7, 0
	bl sub_8071A8C
	lsls r0, 24
	cmp r0, 0
	beq _08062E7E
_08062EA6:
	mov r0, r10
	strb r5, [r0, 0x4]
	cmp r6, r5
	beq _08062F32
	movs r0, 0
	bl sub_8083CE0
	b _08062F32
	.align 2, 0
_08062EB8: .4byte gDungeonGlobalData
_08062EBC: .4byte 0x0001357c
_08062EC0:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1D
	bne _08062ED6
	bl sub_805F1A0
	bl sub_80637E8
	b _08062F32
_08062ED6:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bne _08062EF6
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	bl sub_805F1A0
	movs r1, 0x1
	bl sub_8063A70
	b _08062F32
_08062EF6:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x33
	bne _08062F16
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	bl sub_805F1A0
	movs r1, 0
	bl sub_8063A70
	b _08062F32
_08062F16:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1F
	bne _08062F3A
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	bl sub_805F1A0
	bl sub_8063B54
_08062F32:
	movs r0, 0x1
	bl sub_8044C10
	b _08062F5E
_08062F3A:
	bl sub_805F1AC
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x21
	bne _08062F5E
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	bl sub_805F1A0
	movs r1, 0x1
	bl sub_8063CF0
	movs r0, 0x1
	bl sub_8044C10
_08062F5E:
	bl sub_805F1AC
	lsls r0, 16
	cmp r0, 0
	bne _08062F6A
	b _08062DAE
_08062F6A:
	ldr r0, [sp, 0x4]
	movs r1, 0
	bl sub_806A2BC
	ldr r0, [sp, 0x4]
	adds r0, 0x4
	movs r1, 0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_804A728
_08062F80:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8062D8C

	thumb_func_start sub_8062F90
sub_8062F90:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xE8
	mov r8, r0
	str r3, [sp, 0xDC]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xD4]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0xD8]
	ldr r0, [r0, 0x70]
	mov r9, r0
	bl sub_8083600
	ldr r0, [r0, 0x70]
	str r0, [sp, 0xE4]
	add r4, sp, 0x70
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [sp, 0x74]
	add r0, sp, 0x78
	movs r6, 0
	movs r1, 0x2
	strh r1, [r0]
	strh r1, [r0, 0x2]
	add r1, sp, 0x7C
	movs r0, 0x12
	strh r0, [r1]
	mov r0, sp
	adds r0, 0x7E
	movs r1, 0x10
	strh r1, [r0]
	add r0, sp, 0x80
	strh r1, [r0]
	add r5, sp, 0xD0
	str r5, [sp, 0x84]
	movs r1, 0x3
	str r1, [sp, 0x8C]
	add r0, sp, 0xA0
	str r1, [r0, 0x4]
	add r0, sp, 0xB8
	str r1, [r0, 0x4]
	add r0, sp, 0x10
	adds r1, r4, 0
	movs r2, 0x60
	bl memcpy
	ldr r0, _080630A4
	str r6, [r0]
	movs r3, 0
	ldr r7, [sp, 0xE4]
	adds r7, 0x44
_08063008:
	lsls r0, r3, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	mov r1, r9
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08063032
	ldrb r1, [r2, 0x1]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08063032
	movs r0, 0xFD
	ands r0, r1
	strb r0, [r2, 0x1]
	ldr r0, _080630A4
	str r3, [r0]
_08063032:
	adds r3, 0x1
	cmp r3, 0x3
	ble _08063008
_08063038:
	movs r5, 0
	movs r2, 0
	str r2, [sp, 0xE0]
	mov r10, r2
	add r0, sp, 0xD0
	str r0, [sp]
	add r1, sp, 0x70
	str r1, [sp, 0x4]
	ldr r2, [sp, 0xDC]
	str r2, [sp, 0x8]
	ldr r0, [sp, 0x108]
	str r0, [sp, 0xC]
	mov r0, r8
	mov r1, r9
	ldr r2, [sp, 0xD4]
	add r3, sp, 0x10
	bl sub_80633E4
_0806305C:
	ldr r0, _080630A8
	add r1, sp, 0x70
	bl AddMenuCursorSprite_
	movs r0, 0x1E
	bl sub_803E46C
	ldr r2, _080630AC
	ldrh r1, [r2, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080630DE
	ldrh r0, [r2]
	lsrs r0, 8
	movs r1, 0x1
	ands r0, r1
	ldr r1, _080630A8
	movs r2, 0x18
	ldrsh r6, [r1, r2]
	cmp r0, 0
	beq _080630BA
	movs r0, 0x8C
	lsls r0, 1
	add r0, r9
	adds r1, r6, 0
	bl sub_8092F80
	ldr r1, _080630A4
	str r0, [r1]
	cmp r6, r0
	beq _080630B0
	movs r0, 0
	bl sub_8083CE0
	b _080630B4
	.align 2, 0
_080630A4: .4byte gUnknown_202F2D8
_080630A8: .4byte gUnknown_202EE10
_080630AC: .4byte gRealInputs
_080630B0:
	bl sub_8083D30
_080630B4:
	movs r0, 0x1
	mov r10, r0
	b _080631F4
_080630BA:
	movs r0, 0x8C
	lsls r0, 1
	add r0, r9
	adds r1, r6, 0
	bl sub_8092D80
	adds r1, r0, 0
	ldr r0, _08063118
	bl sub_8013780
	ldr r1, _08063118
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r6, r0
	beq _080630DE
	movs r0, 0
	bl sub_8083CE0
_080630DE:
	ldr r2, _0806311C
	ldrh r1, [r2, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08063150
	ldrh r0, [r2]
	lsrs r0, 8
	movs r1, 0x1
	ands r0, r1
	ldr r4, _08063118
	movs r1, 0x18
	ldrsh r6, [r4, r1]
	cmp r0, 0
	beq _0806312E
	movs r0, 0x8C
	lsls r0, 1
	add r0, r9
	adds r1, r6, 0
	bl sub_8093130
	ldr r1, _08063120
	str r0, [r1]
	cmp r6, r0
	beq _08063124
	movs r0, 0
	bl sub_8083CE0
	b _08063128
	.align 2, 0
_08063118: .4byte gUnknown_202EE10
_0806311C: .4byte gRealInputs
_08063120: .4byte gUnknown_202F2D8
_08063124:
	bl sub_8083D30
_08063128:
	movs r2, 0x1
	mov r10, r2
	b _080631F4
_0806312E:
	movs r0, 0x8C
	lsls r0, 1
	add r0, r9
	adds r1, r6, 0
	bl sub_8092DB8
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8013780
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	cmp r6, r0
	beq _08063150
	movs r0, 0
	bl sub_8083CE0
_08063150:
	ldr r4, _08063174
	ldrh r1, [r4, 0x4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08063168
	ldr r6, _08063178
	adds r0, r6, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806317C
_08063168:
	adds r0, r7, 0
	movs r1, 0x6
	bl sub_8044C94
	b _080631F4
	.align 2, 0
_08063174: .4byte gRealInputs
_08063178: .4byte gUnknown_202EE10
_0806317C:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0806318E
	adds r0, r6, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _08063198
_0806318E:
	adds r0, r7, 0
	movs r1, 0x7
	bl sub_8044C94
	b _080631F4
_08063198:
	bl sub_8062D88
	ldrh r1, [r4, 0x2]
	ands r0, r1
	cmp r0, 0
	bne _080631AE
	adds r0, r6, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _080631C8
_080631AE:
	ldr r2, [sp, 0xD4]
	cmp r2, 0
	beq _080631C2
	ldrh r0, [r4]
	lsrs r0, 8
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080631C2
	movs r5, 0x3
_080631C2:
	bl sub_8083D08
	b _080631F4
_080631C8:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806321C
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08063214
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080631EC
	adds r0, r6, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080631EC
	b _0806305C
_080631EC:
	bl sub_8083D30
	movs r0, 0x1
	str r0, [sp, 0xE0]
_080631F4:
	ldr r4, _08063210
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x1E
	bl sub_803E46C
	ldrh r0, [r7]
	subs r0, 0x6
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _08063224
	b _080633CC
	.align 2, 0
_08063210: .4byte gUnknown_202EE10
_08063214:
	movs r5, 0x2
	bl sub_8083D44
	b _080631F4
_0806321C:
	movs r5, 0x1
	bl sub_8083D44
	b _080631F4
_08063224:
	mov r1, r10
	cmp r1, 0
	beq _0806322C
	b _08063038
_0806322C:
	ldr r2, [sp, 0xE0]
	cmp r2, 0
	beq _08063234
	b _080633B6
_08063234:
	ldr r6, _08063270
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	str r0, [r6]
	cmp r5, 0x1
	bne _08063274
	adds r0, r7, 0
	movs r1, 0x1D
	bl sub_8044C94
	mov r0, r8
	adds r0, 0x24
	ldrb r1, [r0]
	ldr r0, [sp, 0xE4]
	adds r0, 0x48
	strb r1, [r0]
	ldr r1, [r6]
	ldr r0, [sp, 0xE4]
	adds r0, 0x50
	strb r1, [r0]
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x8
	movs r1, 0x1B
	bl sub_803E708
	b _080633B6
	.align 2, 0
_08063270: .4byte gUnknown_202F2D8
_08063274:
	mov r0, r8
	ldr r1, [sp, 0xD4]
	ldr r2, [sp, 0xD8]
	bl sub_8063698
	cmp r5, 0x3
	bne _08063298
	movs r0, 0x20
	bl sub_8044FB4
	adds r6, r0, 0
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	bne _080632CC
	movs r0, 0x21
	b _080632BC
_08063298:
	cmp r5, 0x2
	bne _080632DE
	mov r2, r9
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	beq _080632BA
	movs r0, 0x1E
	bl sub_8044FB4
	adds r6, r0, 0
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	bne _080632CC
	movs r0, 0x33
	b _080632BC
_080632BA:
	movs r0, 0x1F
_080632BC:
	bl sub_8044FB4
	adds r6, r0, 0
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	beq _080632DE
_080632CC:
	mov r0, r8
	bl sub_8045B60
	adds r2, r0, 0
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80637BC
	b _080633B6
_080632DE:
	movs r0, 0x2
	bl sub_8009524
	add r0, sp, 0x10
	movs r1, 0x16
	bl sub_805FC30
	ldr r6, _0806337C
	ldr r5, _08063380
	movs r0, 0x2A
	adds r0, r6
	mov r10, r0
	adds r4, r7, 0
_080632F8:
	adds r0, r6, 0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	ldrh r1, [r5, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806331C
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_80136E0
_0806331C:
	ldrh r1, [r5, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08063334
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8013744
_08063334:
	bl sub_8062D88
	ldrh r1, [r5, 0x2]
	ands r1, r0
	cmp r1, 0
	bne _0806334A
	adds r0, r6, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08063388
_0806334A:
	movs r1, 0x18
	ldrsh r0, [r6, r1]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	beq _08063384
	mov r0, r8
	bl sub_8045B60
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_80637A4
	ldrh r0, [r4]
	subs r0, 0x14
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _08063376
	bl sub_8083D08
_08063376:
	movs r6, 0
	b _080633A0
	.align 2, 0
_0806337C: .4byte gUnknown_202EE10
_08063380: .4byte gRealInputs
_08063384:
	bl sub_8083D30
_08063388:
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0806339A
	mov r2, r10
	ldrb r0, [r2]
	cmp r0, 0
	beq _080632F8
_0806339A:
	bl sub_8083D30
	movs r6, 0x1
_080633A0:
	ldr r0, _080633E0
	bl AddMenuCursorSprite
	movs r0, 0x1B
	bl sub_803E46C
	cmp r6, 0x1
	bne _080633B2
	b _08063038
_080633B2:
	movs r0, 0
	str r0, [sp, 0xE0]
_080633B6:
	movs r0, 0x1
	cmp r0, 0
	beq _080633CC
	movs r0, 0
	movs r1, 0
	bl sub_803EAF0
	movs r0, 0x8
	movs r1, 0x1E
	bl sub_803E708
_080633CC:
	ldr r0, [sp, 0xE0]
	add sp, 0xE8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080633E0: .4byte gUnknown_202EE10
	thumb_func_end sub_8062F90

	thumb_func_start sub_80633E4
sub_80633E4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	str r0, [sp, 0x20]
	adds r7, r1, 0
	adds r4, r3, 0
	ldr r0, [sp, 0x44]
	mov r8, r0
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	add r1, sp, 0x8
	ldr r0, _08063508
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	movs r0, 0
	add r5, sp, 0x50
	ldrb r6, [r5]
	mov r5, r8
	strb r6, [r5]
	add r6, sp, 0x4C
	ldrb r6, [r6]
	strb r6, [r5, 0x1]
	strb r0, [r5, 0x3]
	movs r6, 0
	ldr r5, _0806350C
	ldr r0, _08063510
	mov r9, r0
	movs r1, 0x1
	mov r12, r1
	movs r3, 0x8C
	lsls r3, 1
	adds r2, r7, r3
	movs r3, 0x3
_08063432:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _0806343E
	adds r6, 0x1
_0806343E:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08063432
	movs r3, 0x4
	mov r1, r9
	ldr r0, [r1]
	movs r1, 0
	strh r0, [r5, 0x18]
	strh r6, [r5, 0x1A]
	strh r3, [r5, 0x1C]
	add r2, sp, 0x4C
	ldrh r2, [r2]
	strh r2, [r5, 0x1E]
	add r3, sp, 0x50
	ldrh r3, [r3]
	strh r3, [r5, 0x20]
	strh r1, [r5, 0x4]
	movs r0, 0x10
	strh r0, [r5, 0x6]
	strh r1, [r5, 0x14]
	str r1, [r5]
	adds r0, r5, 0
	adds r0, 0x28
	bl sub_801317C
	movs r0, 0x4
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	strh r0, [r4, 0x10]
	strh r0, [r4, 0xE]
	movs r0, 0xD
	mov r6, r8
	strb r0, [r6, 0x2]
	movs r0, 0x2
	strh r0, [r4, 0x8]
	adds r1, r4, 0
	adds r1, 0x18
	adds r0, r4, 0
	adds r0, 0x48
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	adds r1, r4, 0
	adds r1, 0x30
	add r0, sp, 0x8
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_803ECB4
	adds r0, r5, 0
	movs r1, 0
	bl sub_80137B0
	ldr r1, _08063514
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0x10
	lsls r0, 3
	strh r0, [r5, 0xC]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r5, 0xE]
	ldr r0, _08063518
	adds r1, r7, 0
	movs r2, 0
	bl sub_80708B4
	movs r3, 0
	movs r5, 0x1
_080634DE:
	lsls r1, r3, 3
	movs r4, 0x8C
	lsls r4, 1
	adds r1, r4
	adds r1, r7, r1
	ldr r6, [sp, 0x48]
	adds r4, r6, r3
	movs r0, 0
	strb r0, [r4]
	ldrb r1, [r1]
	adds r2, r5, 0
	ands r2, r1
	cmp r2, 0
	bne _0806351C
	ldr r1, _0806350C
	movs r4, 0x18
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _08063526
	strh r2, [r1, 0x18]
	b _08063526
	.align 2, 0
_08063508: .4byte gUnknown_8106CAC
_0806350C: .4byte gUnknown_202EE10
_08063510: .4byte gUnknown_202F2D8
_08063514: .4byte gUnknown_2027370
_08063518: .4byte gAvailablePokemonNames
_0806351C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08063526
	strb r5, [r4]
_08063526:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080634DE
	movs r5, 0x8C
	lsls r5, 1
	adds r2, r7, r5
	mov r6, r10
	str r6, [sp]
	ldr r0, [sp, 0x4C]
	str r0, [sp, 0x4]
	movs r0, 0x4
	ldr r1, [sp, 0x20]
	movs r3, 0
	bl sub_8063578
	movs r0, 0x2
	bl sub_80073B8
	ldr r0, _08063574
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r1, 0
	movs r3, 0x2
	bl xxx_format_and_draw
	movs r0, 0x2
	bl sub_80073E0
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063574: .4byte gUnknown_80FDFE8
	thumb_func_end sub_80633E4

	thumb_func_start sub_8063578
sub_8063578:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	str r0, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r5, r2, 0
	mov r8, r3
	ldr r0, [sp, 0x40]
	ldr r4, [sp, 0x44]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	ldr r0, [r1, 0x70]
	str r0, [sp, 0x1C]
	mov r0, r8
	bl sub_80073B8
	ldr r0, _080635FC
	ldr r1, [sp, 0x14]
	movs r2, 0
	bl SetMessageArgument
	lsls r4, 3
	adds r4, 0xA
	ldr r0, _08063600
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0
	mov r3, r8
	bl xxx_format_and_draw
	movs r1, 0
	mov r9, r1
	ldr r0, [sp, 0x10]
	cmp r9, r0
	bge _08063676
	add r1, sp, 0x4
	mov r10, r1
	adds r7, r5, 0
_080635D0:
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x6A
	str r0, [sp, 0x8]
	movs r0, 0
	mov r1, r10
	strb r0, [r1, 0x8]
	mov r1, sp
	ldrb r0, [r1, 0x18]
	mov r1, r10
	strb r0, [r1, 0x9]
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08063668
	ldr r1, [sp, 0x1C]
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _08063604
	movs r0, 0x2
	b _08063606
	.align 2, 0
_080635FC: .4byte gAvailablePokemonNames
_08063600: .4byte gUnknown_80FE978
_08063604:
	movs r0, 0x4
_08063606:
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x14]
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_80573CC
	add r1, sp, 0x4
	movs r2, 0
	lsls r0, 24
	cmp r0, 0
	bne _0806361E
	movs r2, 0x1
_0806361E:
	strb r2, [r1, 0x8]
	ldr r0, _0806368C
	adds r1, r5, 0
	add r2, sp, 0x4
	bl sub_80928C0
	ldr r0, _08063690
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	ldrb r1, [r7]
	movs r0, 0x2
	ands r0, r1
	movs r6, 0xD
	cmp r0, 0
	bne _08063658
	movs r6, 0x8
	mov r0, r9
	cmp r0, 0
	beq _08063658
	subs r2, r4, 0x2
	movs r0, 0x7
	str r0, [sp]
	mov r0, r8
	movs r1, 0xC
	movs r3, 0x78
	bl sub_80078A4
_08063658:
	movs r1, 0
	str r1, [sp]
	adds r0, r6, 0
	adds r1, r4, 0
	ldr r2, _08063694
	mov r3, r8
	bl xxx_format_and_draw
_08063668:
	adds r7, 0x8
	adds r5, 0x8
	movs r0, 0x1
	add r9, r0
	ldr r1, [sp, 0x10]
	cmp r9, r1
	blt _080635D0
_08063676:
	mov r0, r8
	bl sub_80073E0
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806368C: .4byte gUnknown_202DE58
_08063690: .4byte gUnknown_202EE10
_08063694: .4byte gUnknown_8106CC4
	thumb_func_end sub_8063578

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
	bl sub_8057348
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
	bl sub_8044C94
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
_08063828: .4byte gDungeonGlobalData
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
	bl sub_8093DE8
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
	bl xxx_format_and_draw
	ldr r2, [r5, 0x4]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	movs r3, 0
	bl xxx_format_and_draw
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
_08063A64: .4byte gAvailablePokemonNames
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
	bl sub_80928C0
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
	bl sub_80936D8
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
	bl SendMessage
	b _08063B3A
	.align 2, 0
_08063B1C: .4byte gDungeonGlobalData
_08063B20: .4byte 0x0001357c
_08063B24: .4byte gUnknown_202DE58
_08063B28: .4byte 0x00000133
_08063B2C: .4byte gUnknown_80F8B40
_08063B30:
	ldr r0, _08063B50
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
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
	bl sub_80928C0
	ldrb r0, [r4]
	movs r1, 0x4
	eors r0, r1
	strb r0, [r4]
	adds r5, r6
	adds r0, r5, 0
	bl sub_80936D8
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
_08063BA4: .4byte gDungeonGlobalData
_08063BA8: .4byte 0x0001357c
_08063BAC: .4byte gUnknown_202DE58
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
	bl sub_80928C0
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
	bl sub_80928C0
_08063C5C:
	adds r0, r6, r4
	bl sub_80936D8
	ldr r0, _08063C84
	bl PlaySoundEffect
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063C70: .4byte gDungeonGlobalData
_08063C74: .4byte 0x0001357c
_08063C78: .4byte gUnknown_202DE58
_08063C7C: .4byte 0x00000119
_08063C80: .4byte gUnknown_202DEA8
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
	bl sub_809422C
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
	bl sub_809422C
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
	bl sub_80928C0
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
	bl sub_80936D8
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
	bl SendMessage
	b _08063DBA
	.align 2, 0
_08063D98: .4byte gDungeonGlobalData
_08063D9C: .4byte 0x0001357c
_08063DA0: .4byte gUnknown_202DE58
_08063DA4: .4byte 0x00000119
_08063DA8: .4byte 0x00000133
_08063DAC: .4byte gUnknown_80F8B88
_08063DB0:
	ldr r0, _08063DD0
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
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
	bl sub_80936F4
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
	bl sub_8092E1C
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
	bl sub_8092E8C
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
	bl sub_80928C0
	cmp r4, 0
	beq _0806414C
	ldr r0, _08064148
	b _0806414E
	.align 2, 0
_08064140: .4byte gUnknown_202F2D8
_08064144: .4byte gUnknown_202DE58
_08064148: .4byte gUnknown_80FDF00
_0806414C:
	ldr r0, _0806415C
_0806414E:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
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
	bl sub_80708B4
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
_0806430C: .4byte gAvailablePokemonNames
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
	bl sub_8044C94
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
	bl sub_804954C
	adds r4, r0, 0
	ldr r0, _080645D0
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0
	bl xxx_call_draw_string
	ldr r0, [r4, 0x14]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080645C0
	ldr r1, [r4, 0x14]
	add r0, sp, 0x4
	movs r2, 0
	bl SetMessageArgument
	str r5, [sp]
	movs r0, 0x8
	movs r1, 0x12
	add r2, sp, 0x4
	movs r3, 0
	bl xxx_call_draw_string
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
	bl sub_804954C
	ldr r4, [r0, 0x14]
	cmp r4, 0
	bne _080646B8
	b _080647D8
_080646B8:
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x2
	beq _080646C4
	b _080647D8
_080646C4:
	ldr r0, [sp, 0xE8]
	movs r1, 0
	bl sub_803ECB4
	adds r0, r4, 0
	bl sub_8045104
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
	bl xxx_call_draw_string
	ldr r5, _08064720
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r5
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r1, 0x18
	movs r3, 0
	bl xxx_call_draw_string
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
	bl sub_8044C94
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
	bl sub_8043D10
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
	bl xxx_call_draw_string
	str r4, [sp]
	movs r0, 0x8
	movs r1, 0x12
	adds r2, r5, 0
	movs r3, 0
	bl xxx_call_draw_string
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
	bl sub_8043D10
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
	bl xxx_call_draw_string
	ldr r0, _08064B10
	adds r4, r0
	ldr r4, [r4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x18
	adds r2, r4, 0
	movs r3, 0
	bl xxx_call_draw_string
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
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	bne _08064CA4
_08064C8C:
	bl sub_8083D08
	b _08064CC0
	.align 2, 0
_08064C94: .4byte gDungeonGlobalData
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
	bl sub_80532B4
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
	bl sub_80441BC
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
	bl sub_805F1AC
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
_08064D70: .4byte gDungeonGlobalData
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
_08064E30: .4byte gUnknown_203B46C
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
	bl sub_8052B8C
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
_08065094: .4byte gUnknown_203B46C
_08065098: .4byte gUnknown_202F2E8
	thumb_func_end sub_8065040

	thumb_func_start sub_806509C
sub_806509C:
	push {lr}
	ldr r0, _080650BC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
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
	bl sub_805F1AC
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
_080651CC: .4byte gDungeonGlobalData
	thumb_func_end sub_806519C

	thumb_func_start sub_80651D0
sub_80651D0:
	push {lr}
	ldr r0, _080651F0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0
	bl sub_8052B8C
	cmp r0, 0x1
	bne _080651F4
	bl sub_805F1A0
	movs r1, 0x2B
	bl sub_8044C94
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
	bl sub_8052B8C
	adds r5, r0, 0
	cmp r5, 0x1
	bne _08065248
	bl sub_805F1A0
	movs r1, 0x2E
	bl sub_8044C94
	ldr r4, _0806523C
	bl sub_8083600
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
_08065240: .4byte gDungeonGlobalData
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
	bl xxx_format_and_draw
	adds r0, r4, 0
	movs r1, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _080653E0
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _080653E4
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _080653E8
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	movs r5, 0x4
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _080653EC
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, _080653D8
	ldr r0, [r1]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806540E
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	bne _080653F4
	movs r5, 0x5
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _080653F0
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	b _0806540E
	.align 2, 0
_080653D0: .4byte gUnknown_202EE10
_080653D4: .4byte gUnknown_202F2E0
_080653D8: .4byte gDungeonGlobalData
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
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _08065440
	ldr r2, [r0]
	str r7, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
_0806540E:
	ldr r0, _08065444
	adds r1, r5, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, _08065448
	ldr r2, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
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
	bl xxx_format_and_draw
	adds r0, r4, 0
	movs r1, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r6, _08065570
	movs r2, 0xAC
	lsls r2, 1
	adds r0, r6, r2
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013800
	adds r1, r0, 0
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r6, r2
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
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
	bl sub_8013800
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013800
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_8013800
	str r0, [sp, 0xC]
	movs r0, 0
	bl sub_80073B8
	ldr r0, _080656B0
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0x4]
	ldr r0, _080656B4
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0x8]
	ldr r0, _080656B8
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0xC]
	ldr r0, _080656BC
	ldr r2, [r0]
	str r6, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
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
	bl sub_8013800
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013800
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x2
	bl sub_8013800
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_8013800
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_8013800
	str r0, [sp, 0x14]
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08065844
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x10
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0x4]
	ldr r0, _08065848
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0x8]
	ldr r0, _0806584C
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0xC]
	ldr r0, _08065850
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0x10]
	ldr r0, _08065854
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
	ldr r1, [sp, 0x14]
	ldr r0, _08065858
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
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
	bl sub_8013800
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
	bl xxx_format_and_draw
	ldr r1, [r6]
	ldr r0, _08065A84
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
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
	bl xxx_format_and_draw
	movs r4, 0
	ldr r5, _08065DB8
_08065D7A:
	ldr r0, _08065DB0
	adds r1, r4, 0
	bl sub_8013800
	adds r1, r0, 0
	ldm r5!, {r2}
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r3, 0
	bl xxx_format_and_draw
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
	bl xxx_format_and_draw
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
	bl xxx_format_and_draw
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
_08065F28: .4byte gUnknown_203B46C
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
	bl GetRecruitable
	lsls r0, 24
	cmp r0, 0
	bne _08065FF0
	ldr r0, _08065FEC
	b _08065FFE
	.align 2, 0
_08065FE0: .4byte 0xfffff608
_08065FE4: .4byte gDungeonGlobalData
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
	bl PrintFieldMessage
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
	bl xxx_call_draw_string
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
	bl xxx_call_draw_string
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
	bl ExpandPlaceholdersBuffer
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
	bl xxx_format_and_draw
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
_0806625C: .4byte gAvailablePokemonNames
_08066260:
	ldr r0, _08066284
	ldr r2, [r0]
	str r1, [sp]
	movs r0, 0x8
	mov r1, r8
	movs r3, 0
	bl xxx_call_draw_string
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
	bl ExpandPlaceholdersBuffer
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
	bl xxx_format_and_draw
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
_0806634C: .4byte gAvailablePokemonNames
_08066350: .4byte gUnknown_203B084
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
	bl ExpandPlaceholdersBuffer
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
	bl xxx_format_and_draw
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
_08066428: .4byte gAvailablePokemonNames
_0806642C: .4byte gUnknown_203B080
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
	bl sub_808E9B8
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
	bl GetBaseRecruit
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
_08066608: .4byte gDungeonGlobalData
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

	thumb_func_start sub_8066744
sub_8066744:
	push {lr}
	ldr r1, [r0, 0x70]
	adds r1, 0x48
	movs r2, 0x1
	strb r2, [r1]
	adds r0, 0x4
	movs r1, 0
	bl sub_8045DB4
	pop {r0}
	bx r0
	thumb_func_end sub_8066744

	thumb_func_start sub_806675C
sub_806675C:
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	movs r1, 0
	movs r2, 0xFE
	bl sub_8044D90
	adds r4, r0, 0
	movs r3, 0
	ldr r6, _080667C0
_08066772:
	lsls r1, r3, 2
	ldr r0, [r6]
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08066798
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _08066798
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	bne _080667EC
	movs r0, 0xEF
	ands r0, r2
	strb r0, [r1]
_08066798:
	adds r3, 0x1
	cmp r3, 0x13
	ble _08066772
	ldr r0, _080667C4
	adds r1, r4, 0
	bl sub_8045BF8
	ldr r0, _080667C8
	bl PlaySoundEffect
	cmp r7, 0
	beq _08066812
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080667D0
	ldr r0, _080667CC
	b _080667DE
	.align 2, 0
_080667C0: .4byte gTeamInventory_203B460
_080667C4: .4byte gUnknown_202DE58
_080667C8: .4byte 0x00000133
_080667CC: .4byte gUnknown_80F8D04
_080667D0:
	ldrb r0, [r4, 0x2]
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	bne _08066808
	ldr r0, _080667E8
_080667DE:
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _08066812
	.align 2, 0
_080667E8: .4byte gUnknown_80F8CE4
_080667EC:
	ldr r0, _08066800
	bl sub_8045BF8
	ldr r0, _08066804
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _08066838
	.align 2, 0
_08066800: .4byte gUnknown_202DE58
_08066804: .4byte gUnknown_80F8C7C
_08066808:
	ldr r0, _08066840
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_08066812:
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r1, r0
	strb r1, [r4]
	movs r0, 0x8
	ands r1, r0
	cmp r1, 0
	beq _08066838
	cmp r7, 0
	beq _08066838
	ldr r0, _08066844
	adds r1, r4, 0
	bl sub_8045BF8
	ldr r0, _08066848
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_08066838:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066840: .4byte gUnknown_80F8CE8
_08066844: .4byte gUnknown_202DE58
_08066848: .4byte gUnknown_80F8BE0
	thumb_func_end sub_806675C

	thumb_func_start sub_806684C
sub_806684C:
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	movs r4, 0
_08066856:
	ldr r0, _0806688C
	lsls r1, r4, 2
	ldr r0, [r0]
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _080668B8
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _080668B8
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _08066898
	ldr r0, _08066890
	bl sub_8045BF8
	ldr r0, _08066894
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _080668BE
	.align 2, 0
_0806688C: .4byte gTeamInventory_203B460
_08066890: .4byte gUnknown_202DE58
_08066894: .4byte gUnknown_80F8C7C
_08066898:
	movs r0, 0xEF
	ands r0, r2
	strb r0, [r1]
	ldr r0, _080668C4
	bl sub_8045BF8
	ldr r0, _080668C8
	bl PlaySoundEffect
	cmp r6, 0
	beq _080668B8
	ldr r0, _080668CC
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_080668B8:
	adds r4, 0x1
	cmp r4, 0x13
	ble _08066856
_080668BE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080668C4: .4byte gUnknown_202DE58
_080668C8: .4byte 0x00000133
_080668CC: .4byte gUnknown_80F8D20
	thumb_func_end sub_806684C

	thumb_func_start sub_80668D0
sub_80668D0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	adds r6, r0, 0
	movs r1, 0x1
	bl sub_8044DA4
	mov r8, r0
	ldr r4, [r6, 0x70]
	ldr r7, [r0, 0x70]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x2
	bl sub_8044D90
	adds r5, r0, 0
	adds r4, 0x48
	ldrb r0, [r4]
	movs r1, 0
	mov r9, r1
	cmp r0, 0x80
	bne _08066904
	movs r2, 0x1
	mov r9, r2
_08066904:
	mov r0, r9
	cmp r0, 0
	bne _08066928
	ldrb r1, [r5]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0x18
	bne _08066928
	ldr r0, _08066920
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08066924
	b _08066950
	.align 2, 0
_08066920: .4byte gUnknown_202DEA8
_08066924: .4byte gUnknown_80F8C44
_08066928:
	ldr r0, _0806695C
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	adds r1, r7, 0
	adds r1, 0x60
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08066A04
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _08066968
	ldr r0, _08066960
	bl sub_8045BF8
	ldr r0, _08066964
_08066950:
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _08066A96
	.align 2, 0
_0806695C: .4byte gUnknown_202DFE8
_08066960: .4byte gUnknown_202DEA8
_08066964: .4byte gUnknown_80F8C40
_08066968:
	ldr r1, [r7, 0x60]
	str r1, [sp]
	ldr r2, [r5]
	str r2, [sp, 0x4]
	movs r4, 0xEF
	mov r0, sp
	ldrb r0, [r0]
	ands r0, r4
	ldr r3, _080669A8
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	add r5, sp, 0x4
	ldrb r0, [r5]
	ands r0, r4
	ands r2, r3
	orrs r2, r0
	str r2, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x64
	bl sub_8044DF0
	mov r1, r9
	cmp r1, 0
	beq _080669AC
	adds r0, r6, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_80460F8
	b _080669B2
	.align 2, 0
_080669A8: .4byte 0xffffff00
_080669AC:
	mov r0, sp
	bl AddItemToInventory
_080669B2:
	ldr r0, [sp, 0x4]
	str r0, [r7, 0x60]
	ldr r4, _080669F4
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8045BF8
	adds r4, 0x50
	adds r0, r4, 0
	mov r1, sp
	bl sub_8045BF8
	ldr r0, _080669F8
	bl PlaySoundEffect
	ldr r0, _080669FC
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	add r0, sp, 0x4
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08066A52
	ldr r0, _08066A00
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _08066A52
	.align 2, 0
_080669F4: .4byte gUnknown_202DE58
_080669F8: .4byte 0x0000014d
_080669FC: .4byte gUnknown_80F8CA8
_08066A00: .4byte gUnknown_80F8BE0
_08066A04:
	ldr r2, [r5]
	str r2, [sp, 0x8]
	movs r1, 0xEF
	add r4, sp, 0x8
	ldrb r0, [r4]
	ands r0, r1
	ldr r1, _08066AA4
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x8]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x65
	bl sub_8044DF0
	ldr r0, [sp, 0x8]
	str r0, [r7, 0x60]
	ldr r0, _08066AA8
	adds r1, r4, 0
	bl sub_8045BF8
	ldr r0, _08066AAC
	bl PlaySoundEffect
	ldr r0, _08066AB0
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08066A52
	ldr r0, _08066AB4
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
_08066A52:
	mov r0, r8
	bl sub_806A6E8
	mov r1, r8
	adds r1, 0x4
	mov r0, r8
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _08066A74
	adds r0, r6, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_08066A74:
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _08066A86
	ldrh r1, [r7]
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r7]
_08066A86:
	ldr r0, _08066AB8
	ldr r0, [r0]
	ldr r1, _08066ABC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_807AB38
_08066A96:
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066AA4: .4byte 0xffffff00
_08066AA8: .4byte gUnknown_202DE58
_08066AAC: .4byte 0x0000014d
_08066AB0: .4byte gUnknown_80F8D44
_08066AB4: .4byte gUnknown_80F8BE0
_08066AB8: .4byte gDungeonGlobalData
_08066ABC: .4byte 0x00003a08
	thumb_func_end sub_80668D0

	thumb_func_start sub_8066AC0
sub_8066AC0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r0, 0
	movs r1, 0
	bl sub_8044DA4
	adds r6, r0, 0
	ldr r2, [r6, 0x70]
	mov r8, r2
	adds r5, r2, 0
	adds r5, 0x60
	ldr r0, _08066AF0
	ldr r0, [r0]
	adds r0, 0x4C
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08066AF8
	ldr r0, _08066AF4
	b _08066B10
	.align 2, 0
_08066AF0: .4byte gTeamInventory_203B460
_08066AF4: .4byte gUnknown_80F8D60
_08066AF8:
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08066B24
	ldr r0, _08066B1C
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08066B20
_08066B10:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _08066BAC
	.align 2, 0
_08066B1C: .4byte gUnknown_202DE58
_08066B20: .4byte gUnknown_80F8BE0
_08066B24:
	ldr r2, [r2, 0x60]
	str r2, [sp]
	movs r1, 0xEF
	mov r0, sp
	ldrb r0, [r0]
	ands r0, r1
	ldr r1, _08066BB8
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldr r0, _08066BBC
	mov r1, sp
	bl sub_8045BF8
	ldr r0, _08066BC0
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	strb r4, [r5, 0x2]
	strb r4, [r5, 0x1]
	strb r4, [r5]
	mov r0, sp
	bl AddItemToInventory
	ldr r0, _08066BC4
	bl PlaySoundEffect
	ldr r0, _08066BC8
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	adds r0, r6, 0
	bl sub_806A6E8
	adds r1, r6, 0x4
	adds r0, r6, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _08066B86
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_08066B86:
	mov r1, r8
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _08066B9C
	ldrh r1, [r1]
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
_08066B9C:
	ldr r0, _08066BCC
	ldr r0, [r0]
	ldr r2, _08066BD0
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_807AB38
_08066BAC:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066BB8: .4byte 0xffffff00
_08066BBC: .4byte gUnknown_202DE58
_08066BC0: .4byte gAvailablePokemonNames
_08066BC4: .4byte 0x0000014d
_08066BC8: .4byte gUnknown_80F8D7C
_08066BCC: .4byte gDungeonGlobalData
_08066BD0: .4byte 0x00003a08
	thumb_func_end sub_8066AC0

	thumb_func_start sub_8066BD4
sub_8066BD4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	movs r1, 0
	bl sub_8044DA4
	mov r9, r0
	ldr r0, [r0, 0x70]
	mov r8, r0
	mov r10, r8
	mov r6, r8
	adds r6, 0x60
	ldr r2, _08066C10
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_8044D90
	adds r5, r0, 0
	ldrb r2, [r6]
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _08066C18
	ldr r0, _08066C14
	adds r1, r6, 0
	b _08066C26
	.align 2, 0
_08066C10: .4byte 0x00001565
_08066C14: .4byte gUnknown_202DE58
_08066C18:
	ldrb r1, [r5]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0x18
	bne _08066C40
	ldr r0, _08066C38
	adds r1, r5, 0
_08066C26:
	bl sub_8045BF8
	ldr r0, _08066C3C
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _08066CC8
	.align 2, 0
_08066C38: .4byte gUnknown_202DE58
_08066C3C: .4byte gUnknown_80F8BE0
_08066C40:
	movs r1, 0xEF
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r6]
	ldrb r0, [r5]
	ands r1, r0
	strb r1, [r5]
	ldr r4, _08066CD8
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8045BF8
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8045BF8
	ldr r0, _08066CDC
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	mov r2, r8
	ldr r1, [r2, 0x60]
	ldr r0, [r5]
	str r0, [r2, 0x60]
	str r1, [r5]
	ldr r0, _08066CE0
	bl PlaySoundEffect
	ldr r0, _08066CE4
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	mov r1, r9
	adds r1, 0x4
	mov r0, r9
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _08066CA2
	adds r0, r7, 0
	mov r1, r9
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_08066CA2:
	mov r1, r10
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	bne _08066CB8
	ldrh r1, [r1]
	movs r2, 0x80
	lsls r2, 7
	adds r0, r2, 0
	orrs r0, r1
	mov r1, r10
	strh r0, [r1]
_08066CB8:
	ldr r0, _08066CE8
	ldr r0, [r0]
	ldr r2, _08066CEC
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_807AB38
_08066CC8:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066CD8: .4byte gUnknown_202DE58
_08066CDC: .4byte gUnknown_202DFE8
_08066CE0: .4byte 0x0000014d
_08066CE4: .4byte gUnknown_80F8DB4
_08066CE8: .4byte gDungeonGlobalData
_08066CEC: .4byte 0x00003a08
	thumb_func_end sub_8066BD4

	thumb_func_start sub_8066CF0
sub_8066CF0:
	push {lr}
	movs r1, 0
	bl sub_8044DA4
	ldr r0, [r0, 0x70]
	adds r0, 0xFC
	movs r1, 0x1
	strb r1, [r0]
	pop {r0}
	bx r0
	thumb_func_end sub_8066CF0

	thumb_func_start sub_8066D04
sub_8066D04:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, [r4, 0x70]
	movs r1, 0
	movs r2, 0x4
	bl sub_8044D90
	adds r5, r0, 0
	ldr r0, _08066D2C
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r6, 0
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x80
	bne _08066D34
	ldr r0, _08066D30
	b _08066DB2
	.align 2, 0
_08066D2C: .4byte gUnknown_202DE58
_08066D30: .4byte gUnknown_80F8DE0
_08066D34:
	cmp r0, 0x14
	bhi _08066D4C
	ldrb r1, [r5]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0x18
	bne _08066D4C
	ldr r0, _08066D48
	b _08066DB2
	.align 2, 0
_08066D48: .4byte gUnknown_80F8BE0
_08066D4C:
	adds r0, r6, 0
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x81
	bne _08066D68
	ldrb r1, [r5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08066D68
	ldr r0, _08066D64
	b _08066DB2
	.align 2, 0
_08066D64: .4byte gUnknown_80F8BE0
_08066D68:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl sub_804954C
	adds r2, r0, 0
	ldrh r1, [r2]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _08066DB0
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x1
	bne _08066DB0
	ldr r6, [r2, 0x14]
	cmp r6, 0
	bne _08066DB0
	ldrb r1, [r5]
	movs r0, 0xEF
	ands r0, r1
	strb r0, [r5]
	ldr r0, _08066DBC
	adds r1, r5, 0
	bl sub_8045BF8
	adds r0, r4, 0x4
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_80460F8
	lsls r0, 24
	cmp r0, 0
	bne _08066DC4
_08066DB0:
	ldr r0, _08066DC0
_08066DB2:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _08066DF8
	.align 2, 0
_08066DBC: .4byte gUnknown_202DE58
_08066DC0: .4byte gUnknown_80F8E04
_08066DC4:
	strb r6, [r5, 0x2]
	strb r6, [r5, 0x1]
	strb r6, [r5]
	bl FillInventoryGaps
	ldr r0, _08066E00
	bl PlaySoundEffect
	ldr r0, _08066E04
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08066E08
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	ldr r0, _08066E0C
	ldr r0, [r0]
	ldr r1, _08066E10
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_807AB38
_08066DF8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08066E00: .4byte 0x0000014d
_08066E04: .4byte gAvailablePokemonNames
_08066E08: .4byte gUnknown_80F8E28
_08066E0C: .4byte gDungeonGlobalData
_08066E10: .4byte 0x00003a08
	thumb_func_end sub_8066D04

	thumb_func_start sub_8066E14
sub_8066E14:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	mov r9, r0
	ldr r0, [r0, 0x70]
	mov r10, r0
	mov r0, r9
	movs r1, 0
	movs r2, 0x5
	bl sub_8044D90
	adds r6, r0, 0
	mov r0, r9
	movs r1, 0x1
	movs r2, 0x6
	bl sub_8044D90
	adds r2, r0, 0
	adds r7, r2, 0
	mov r0, r10
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x80
	beq _08066E54
	ldr r0, _08066E50
	b _08066F1E
	.align 2, 0
_08066E50: .4byte gUnknown_80F8E2C
_08066E54:
	mov r0, r10
	adds r0, 0x50
	ldrb r1, [r0]
	str r0, [sp, 0x8]
	cmp r1, 0x14
	bhi _08066E80
	ldrb r1, [r2]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0x18
	bne _08066E80
	ldr r0, _08066E78
	adds r1, r2, 0
	bl sub_8045BF8
	ldr r0, _08066E7C
	b _08066F1E
	.align 2, 0
_08066E78: .4byte gUnknown_202DE58
_08066E7C: .4byte gUnknown_80F8BE0
_08066E80:
	ldr r1, [sp, 0x8]
	ldrb r0, [r1]
	cmp r0, 0x81
	bne _08066EA8
	adds r2, r7, 0
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08066EA8
	ldr r0, _08066EA0
	adds r1, r2, 0
	bl sub_8045BF8
	ldr r0, _08066EA4
	b _08066F1E
	.align 2, 0
_08066EA0: .4byte gUnknown_202DEA8
_08066EA4: .4byte gUnknown_80F8C48
_08066EA8:
	mov r2, r9
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl sub_804954C
	ldr r0, [r0, 0x14]
	cmp r0, 0
	beq _08066ECC
	bl sub_80450F8
	cmp r0, 0x3
	beq _08066ECC
	ldr r0, _08066EC8
	b _08066F1E
	.align 2, 0
_08066EC8: .4byte gUnknown_80F8E54
_08066ECC:
	adds r0, r6, 0
	ldr r5, [r0]
	str r5, [sp]
	adds r4, r7, 0
	ldr r6, [r4]
	mov r8, sp
	str r6, [sp, 0x4]
	movs r3, 0xEF
	mov r0, sp
	ldrb r2, [r0]
	ands r2, r3
	ldr r1, _08066F28
	adds r0, r1, 0
	ands r0, r5
	orrs r0, r2
	str r0, [sp]
	mov r2, r8
	ldrb r0, [r2, 0x4]
	ands r0, r3
	ands r1, r6
	orrs r1, r0
	str r1, [sp, 0x4]
	mov r5, r10
	adds r5, 0x4C
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80461C8
	movs r0, 0
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x1]
	strb r0, [r4]
	add r1, sp, 0x4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_80460F8
	lsls r0, 24
	cmp r0, 0
	bne _08066F30
	ldr r0, _08066F2C
_08066F1E:
	ldr r1, [r0]
	mov r0, r9
	bl SendMessage
	b _08066F7E
	.align 2, 0
_08066F28: .4byte 0xffffff00
_08066F2C: .4byte gUnknown_80F8E78
_08066F30:
	ldr r3, [sp, 0x8]
	ldrb r0, [r3]
	cmp r0, 0x81
	bne _08066F40
	ldr r0, [sp]
	mov r1, r10
	str r0, [r1, 0x60]
	b _08066F46
_08066F40:
	mov r0, sp
	bl AddItemToInventory
_08066F46:
	bl FillInventoryGaps
	ldr r4, _08066F90
	add r1, sp, 0x4
	adds r0, r4, 0
	bl sub_8045BF8
	adds r4, 0x50
	adds r0, r4, 0
	mov r1, sp
	bl sub_8045BF8
	ldr r0, _08066F94
	bl PlaySoundEffect
	ldr r0, _08066F98
	ldr r1, [r0]
	mov r0, r9
	bl SendMessage
	ldr r0, _08066F9C
	ldr r0, [r0]
	ldr r2, _08066FA0
	adds r0, r2
	ldrb r1, [r0]
	mov r0, r9
	bl sub_807AB38
_08066F7E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066F90: .4byte gUnknown_202DE58
_08066F94: .4byte 0x0000014d
_08066F98: .4byte gUnknown_80F8EAC
_08066F9C: .4byte gDungeonGlobalData
_08066FA0: .4byte 0x00003a08
	thumb_func_end sub_8066E14

	thumb_func_start sub_8066FA4
sub_8066FA4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r7, r0, 0
	ldr r0, [r7, 0x70]
	mov r9, r0
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	movs r2, 0x6
	ldrsh r1, [r7, r2]
	bl sub_804954C
	mov r10, r0
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0x7
	bl sub_8044D90
	adds r4, r0, 0
	adds r5, r4, 0
	ldr r0, _08067000
	mov r8, r0
	adds r1, r4, 0
	bl sub_8045BF8
	mov r0, r9
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x14
	bhi _08067008
	ldrb r1, [r4]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0x18
	bne _08067008
	mov r0, r8
	adds r0, 0x50
	adds r1, r4, 0
	bl sub_8045BF8
	ldr r0, _08067004
	b _0806709E
	.align 2, 0
_08067000: .4byte gUnknown_202DE58
_08067004: .4byte gUnknown_80F8C48
_08067008:
	mov r0, r9
	adds r0, 0x48
	ldrb r1, [r0]
	str r0, [sp, 0x8]
	cmp r1, 0x81
	bne _08067028
	adds r0, r5, 0
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08067028
	ldr r0, _08067024
	b _0806709E
	.align 2, 0
_08067024: .4byte gUnknown_80F8C44
_08067028:
	mov r1, r10
	ldr r0, [r1, 0x14]
	cmp r0, 0
	beq _08067040
	bl sub_80450F8
	cmp r0, 0x3
	beq _08067040
	ldr r0, _0806703C
	b _0806709E
	.align 2, 0
_0806703C: .4byte gUnknown_80F8E54
_08067040:
	mov r2, r10
	ldr r0, [r2, 0x14]
	bl sub_8045108
	adds r4, r0, 0
	ldr r0, _080670A8
	adds r1, r4, 0
	bl sub_8045BF8
	ldr r6, [r5]
	str r6, [sp]
	ldr r4, [r4]
	mov r8, sp
	str r4, [sp, 0x4]
	movs r3, 0xEF
	mov r0, sp
	ldrb r2, [r0]
	ands r2, r3
	ldr r1, _080670AC
	adds r0, r1, 0
	ands r0, r6
	orrs r0, r2
	str r0, [sp]
	mov r2, r8
	ldrb r0, [r2, 0x4]
	ands r0, r3
	ands r1, r4
	orrs r1, r0
	str r1, [sp, 0x4]
	adds r4, r7, 0x4
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80461C8
	movs r0, 0
	strb r0, [r5, 0x2]
	strb r0, [r5, 0x1]
	strb r0, [r5]
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_80460F8
	lsls r0, 24
	cmp r0, 0
	bne _080670B4
	ldr r0, _080670B0
_0806709E:
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	b _080670EE
	.align 2, 0
_080670A8: .4byte gUnknown_202DEA8
_080670AC: .4byte 0xffffff00
_080670B0: .4byte gUnknown_80F8E78
_080670B4:
	ldr r1, [sp, 0x8]
	ldrb r0, [r1]
	cmp r0, 0x81
	bne _080670C4
	ldr r0, [sp, 0x4]
	mov r2, r9
	str r0, [r2, 0x60]
	b _080670CA
_080670C4:
	add r0, sp, 0x4
	bl AddItemToInventory
_080670CA:
	bl FillInventoryGaps
	ldr r0, _08067100
	bl PlaySoundEffect
	ldr r0, _08067104
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	ldr r0, _08067108
	ldr r0, [r0]
	ldr r1, _0806710C
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_807AB38
_080670EE:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067100: .4byte 0x0000014d
_08067104: .4byte gUnknown_80F8EAC
_08067108: .4byte gDungeonGlobalData
_0806710C: .4byte 0x00003a08
	thumb_func_end sub_8066FA4

	thumb_func_start sub_8067110
sub_8067110:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	ldr r4, [r5, 0x70]
	movs r1, 0
	movs r2, 0x8
	bl sub_8044D90
	adds r6, r0, 0
	ldr r0, _08067190
	adds r1, r6, 0
	bl sub_8045BF8
	ldr r0, _08067194
	adds r1, r4, 0
	movs r2, 0
	bl sub_80708B4
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8048D50
	lsls r0, 24
	cmp r0, 0
	beq _08067188
	adds r0, r6, 0
	bl sub_80464AC
	adds r1, r0, 0
	adds r0, r5, 0
	bl SendMessage
	ldr r0, [r6]
	str r0, [sp, 0x8]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x66
	bl sub_8044DF0
	movs r0, 0x1E
	movs r1, 0x11
	bl sub_803E708
	str r5, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl sub_80479B8
	ldr r0, _08067198
	ldr r0, [r0]
	ldr r1, _0806719C
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_807AB38
_08067188:
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08067190: .4byte gUnknown_202DE58
_08067194: .4byte gAvailablePokemonNames
_08067198: .4byte gDungeonGlobalData
_0806719C: .4byte 0x00003a08
	thumb_func_end sub_8067110

	thumb_func_start sub_80671A0
sub_80671A0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r6, r0, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x9
	bl sub_8044D90
	adds r4, r0, 0
	mov r0, r8
	adds r0, 0x48
	ldrb r0, [r0]
	cmp r0, 0x81
	bne _080671E8
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080671E8
	ldr r0, _080671E0
	adds r1, r4, 0
	bl sub_8045BF8
	ldr r0, _080671E4
	b _08067230
	.align 2, 0
_080671E0: .4byte gUnknown_202DE58
_080671E4: .4byte gUnknown_80F8BE0
_080671E8:
	ldrb r0, [r4, 0x2]
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	beq _08067202
	ldrb r0, [r4, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08067220
_08067202:
	ldrb r1, [r4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08067220
	ldr r0, _08067218
	adds r1, r4, 0
	bl sub_8045BF8
	ldr r0, _0806721C
	b _08067230
	.align 2, 0
_08067218: .4byte gUnknown_202DE58
_0806721C: .4byte gUnknown_80F8BE0
_08067220:
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_8071518
	lsls r0, 24
	cmp r0, 0
	beq _08067248
	ldr r0, _08067244
_08067230:
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	movs r0, 0x14
	movs r1, 0x4C
	bl sub_803E708
	b _080674F8
	.align 2, 0
_08067244: .4byte gUnknown_80FF76C
_08067248:
	ldr r2, [r4]
	str r2, [sp, 0x4]
	movs r1, 0xEF
	add r0, sp, 0x4
	ldrb r0, [r0]
	ands r0, r1
	ldr r1, _080672C0
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	mov r0, r8
	adds r0, 0x48
	ldrb r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x80
	bne _08067272
	movs r4, 0
	adds r0, 0x4
	movs r1, 0x1
	bl sub_80461C8
_08067272:
	movs r7, 0x1
	ldr r0, [sp, 0x4]
	lsrs r0, 16
	lsls r0, 24
	lsrs r0, 24
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	beq _0806729A
	ldr r0, [sp, 0x4]
	lsrs r0, 16
	lsls r0, 24
	lsrs r0, 24
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080672A8
_0806729A:
	ldr r0, [sp, 0x4]
	lsrs r0, 8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080672A8
	movs r7, 0
_080672A8:
	cmp r7, 0
	beq _080672C4
	ldrb r0, [r5]
	cmp r0, 0x80
	beq _080672F6
	movs r0, 0
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x1]
	strb r0, [r4]
	bl FillInventoryGaps
	b _080672F6
	.align 2, 0
_080672C0: .4byte 0xffffff00
_080672C4:
	ldrb r0, [r5]
	cmp r0, 0x80
	bne _080672F0
	ldr r2, [sp, 0x4]
	lsrs r0, r2, 8
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 16
	ldr r1, _080672EC
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	mov r0, r8
	adds r0, 0x4C
	add r1, sp, 0x4
	movs r2, 0x1
	bl sub_80460F8
	b _080672F6
	.align 2, 0
_080672EC: .4byte 0xffff00ff
_080672F0:
	ldrb r0, [r4, 0x1]
	subs r0, 0x1
	strb r0, [r4, 0x1]
_080672F6:
	adds r0, r6, 0
	movs r1, 0x29
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08067310
	movs r0, 0x8
	bl DungeonRandomCapped
	mov r1, r8
	adds r1, 0x46
	strb r0, [r1]
_08067310:
	adds r0, r6, 0
	bl sub_8045888
	lsls r0, 24
	movs r1, 0xE0
	add r1, r8
	mov r10, r1
	adds r1, r6, 0x4
	str r1, [sp, 0x10]
	add r1, sp, 0xC
	mov r9, r1
	cmp r0, 0
	beq _08067364
	mov r0, r8
	adds r0, 0x46
	ldrb r4, [r0]
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r6, 0
	bl sub_80421C0
	movs r7, 0x7
	movs r5, 0x7
_0806733E:
	subs r4, 0x1
	ands r4, r7
	adds r0, r6, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_806CDD4
	movs r0, 0x2
	movs r1, 0x15
	bl sub_803E708
	subs r5, 0x1
	cmp r5, 0
	bge _0806733E
	movs r1, 0xB3
	lsls r1, 1
	add r1, r8
	movs r0, 0x4
	strb r0, [r1]
_08067364:
	add r4, sp, 0x4
	ldrb r0, [r4, 0x2]
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	beq _08067380
	ldrb r0, [r4, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08067384
_08067380:
	movs r0, 0x1
	strb r0, [r4, 0x1]
_08067384:
	ldr r0, _080673B0
	add r4, sp, 0x4
	adds r1, r4, 0
	bl sub_8045C08
	ldr r0, _080673B4
	mov r1, r8
	movs r2, 0
	bl sub_80708B4
	ldrb r0, [r4, 0x2]
	bl GetItemType
	lsls r0, 24
	cmp r0, 0
	bne _080673BC
	ldr r0, _080673B8
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _080673C6
	.align 2, 0
_080673B0: .4byte gUnknown_202DE58
_080673B4: .4byte gAvailablePokemonNames
_080673B8: .4byte gUnknown_80F8EC8
_080673BC:
	ldr r0, _080673F8
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
_080673C6:
	add r0, sp, 0x4
	ldrb r0, [r0, 0x2]
	bl GetItemType
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_8042208
	adds r0, r6, 0
	movs r1, 0x27
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08067400
	ldr r0, _080673FC
	ldr r1, [sp, 0xC]
	ands r1, r0
	movs r0, 0x80
	lsls r0, 1
	orrs r1, r0
	str r1, [sp, 0xC]
	b _08067408
	.align 2, 0
_080673F8: .4byte gUnknown_80F8EC4
_080673FC: .4byte 0xffff00ff
_08067400:
	ldr r1, _0806741C
	ldr r0, [sp, 0xC]
	ands r0, r1
	str r0, [sp, 0xC]
_08067408:
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _08067440
	cmp r0, 0x1
	bgt _08067420
	cmp r0, 0
	beq _08067426
	b _08067462
	.align 2, 0
_0806741C: .4byte 0xffff00ff
_08067420:
	cmp r0, 0x2
	beq _0806744C
	b _08067462
_08067426:
	ldr r1, _08067438
	ldr r0, [sp, 0xC]
	ands r0, r1
	ldr r1, _0806743C
	ands r0, r1
	movs r1, 0xA0
	lsls r1, 12
	b _0806745E
	.align 2, 0
_08067438: .4byte 0xffffff00
_0806743C: .4byte 0x0000ffff
_08067440:
	ldr r1, _08067448
	ldr r0, [sp, 0xC]
	ands r0, r1
	b _08067456
	.align 2, 0
_08067448: .4byte 0xffffff00
_0806744C:
	ldr r1, _080674B4
	ldr r0, [sp, 0xC]
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
_08067456:
	ldr r1, _080674B8
	ands r0, r1
	movs r1, 0xC6
	lsls r1, 15
_0806745E:
	orrs r0, r1
	str r0, [sp, 0xC]
_08067462:
	adds r0, r6, 0
	movs r1, 0xF
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _08067486
	ldr r1, _080674B4
	ldr r0, [sp, 0xC]
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	ldr r1, _080674B8
	ands r0, r1
	movs r1, 0xC6
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0xC]
_08067486:
	add r0, sp, 0x4
	ldrb r0, [r0, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080674BC
	add r4, sp, 0x8
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_8083904
	mov r0, r9
	str r0, [sp]
	adds r0, r6, 0
	add r1, sp, 0x4
	ldr r2, [sp, 0x10]
	adds r3, r4, 0
	bl sub_80475C4
	b _080674D0
	.align 2, 0
_080674B4: .4byte 0xffffff00
_080674B8: .4byte 0x0000ffff
_080674BC:
	mov r0, r8
	adds r0, 0x46
	ldrb r3, [r0]
	mov r1, r9
	str r1, [sp]
	adds r0, r6, 0
	add r1, sp, 0x4
	ldr r2, [sp, 0x10]
	bl sub_8047190
_080674D0:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080674F8
	mov r0, r8
	adds r0, 0x46
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_806CE68
	ldr r0, _08067508
	ldr r0, [r0]
	ldr r1, _0806750C
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_807AB38
_080674F8:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067508: .4byte gDungeonGlobalData
_0806750C: .4byte 0x00003a08
	thumb_func_end sub_80671A0

	thumb_func_start sub_8067510
sub_8067510:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_806773C
	adds r1, r0, 0
	movs r2, 0x1
	negs r2, r2
	adds r0, r4, 0
	bl sub_8067558
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8067510

	thumb_func_start sub_806752C
sub_806752C:
	push {r4,lr}
	ldr r1, _08067550
	ldr r1, [r1]
	ldrb r0, [r0, 0x4]
	lsls r0, 2
	ldr r2, _08067554
	adds r1, r2
	adds r1, r0
	ldr r4, [r1]
	bl sub_8083600
	adds r1, r4, 0
	movs r2, 0
	bl sub_8067558
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08067550: .4byte gDungeonGlobalData
_08067554: .4byte 0x0001357c
	thumb_func_end sub_806752C

	thumb_func_start sub_8067558
sub_8067558:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x12C
	adds r6, r0, 0
	adds r5, r1, 0
	mov r9, r2
	ldr r0, [r6, 0x70]
	mov r8, r0
	cmp r5, 0
	bne _0806757C
	ldr r0, _08067578
	ldr r1, [r0]
	movs r0, 0
	b _08067716
	.align 2, 0
_08067578: .4byte gUnknown_80F8EE4
_0806757C:
	adds r0, r6, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	bne _08067594
	ldr r0, _08067590
	ldr r1, [r0]
	movs r0, 0
	b _08067716
	.align 2, 0
_08067590: .4byte gUnknown_80F8EE4
_08067594:
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080675AA
	b _0806771E
_080675AA:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8071598
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080675C0
	b _0806771E
_080675C0:
	ldr r7, [r5, 0x70]
	ldr r4, _08067608
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl sub_80708B4
	adds r4, 0x50
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0x7
	bl sub_80708B4
	bl sub_8084778
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_807A96C
	adds r0, r5, 0
	bl sub_8070BC0
	lsls r0, 24
	cmp r0, 0
	beq _08067600
	adds r0, r5, 0
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _08067610
_08067600:
	ldr r0, _0806760C
	ldr r1, [r0]
	movs r0, 0
	b _08067716
	.align 2, 0
_08067608: .4byte gAvailablePokemonNames
_0806760C: .4byte gUnknown_80FE008
_08067610:
	adds r0, r6, 0x4
	adds r1, r5, 0x4
	bl sub_80983D8
	adds r1, r0, 0
	adds r0, r6, 0
	bl sub_806CEFC
	mov r1, r9
	cmp r1, 0
	blt _0806762E
	adds r0, r5, 0
	bl sub_806CEFC
	b _0806763C
_0806762E:
	mov r0, r8
	adds r0, 0x46
	ldrb r1, [r0]
	adds r1, 0x4
	adds r0, r5, 0
	bl sub_806CEFC
_0806763C:
	ldrb r0, [r7, 0x8]
	cmp r0, 0x1
	bne _08067648
	bl sub_807EF84
	b _0806772A
_08067648:
	adds r0, r7, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08067694
	ldr r0, _08067668
	ldr r1, [r0]
	ldr r2, _0806766C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067674
	ldr r0, _08067670
	ldr r1, [r0]
	movs r0, 0
	b _08067716
	.align 2, 0
_08067668: .4byte gDungeonGlobalData
_0806766C: .4byte 0x0000066e
_08067670: .4byte gUnknown_80FF674
_08067674:
	ldr r3, _08067688
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806768C
	adds r0, r5, 0
	bl sub_80845E0
	b _0806772A
	.align 2, 0
_08067688: .4byte 0x00000677
_0806768C:
	adds r0, r5, 0
	bl sub_8084448
	b _0806772A
_08067694:
	movs r0, 0x4
	ldrsh r5, [r7, r0]
	movs r6, 0
	adds r0, r7, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	bne _080676AA
	movs r5, 0xD2
	lsls r5, 1
	b _080676CC
_080676AA:
	cmp r0, 0x47
	bne _080676B8
	ldr r5, _080676B4
	b _080676CC
	.align 2, 0
_080676B4: .4byte 0x000001a5
_080676B8:
	cmp r0, 0x41
	bne _080676CC
	ldr r0, _080676E8
	ldr r0, [r0]
	ldr r1, _080676EC
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080676CC
	movs r6, 0x1
_080676CC:
	movs r3, 0x10
	ldrsh r2, [r7, r3]
	adds r0, r2, 0
	cmp r2, 0
	bge _080676D8
	adds r0, r2, 0x3
_080676D8:
	movs r3, 0xE
	ldrsh r1, [r7, r3]
	asrs r0, 2
	cmp r1, r0
	bgt _080676F0
	movs r2, 0x2
	b _08067708
	.align 2, 0
_080676E8: .4byte gDungeonGlobalData
_080676EC: .4byte 0x0000065c
_080676F0:
	movs r0, 0xE
	ldrsh r4, [r7, r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 1
	movs r1, 0xA
	bl __divsi3
	movs r2, 0
	cmp r4, r0
	bgt _08067708
	movs r2, 0x1
_08067708:
	mov r0, sp
	adds r1, r5, 0
	adds r3, r6, 0
	bl sub_806A3D4
	movs r0, 0
	mov r1, sp
_08067716:
	movs r2, 0x1
	bl PrintFieldMessage
	b _0806772A
_0806771E:
	ldr r0, _08067738
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806772A:
	add sp, 0x12C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067738: .4byte gUnknown_80F8EE4
	thumb_func_end sub_8067558

	thumb_func_start sub_806773C
sub_806773C:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_80696A8
	adds r4, r0, 0
	cmp r4, 0
	beq _08067760
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _08067760
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _08067760
	adds r0, r4, 0
	b _08067762
_08067760:
	movs r0, 0
_08067762:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806773C

	thumb_func_start sub_8067768
sub_8067768:
	push {r4,lr}
	ldr r1, _0806778C
	ldr r1, [r1]
	ldrb r0, [r0, 0x4]
	lsls r0, 2
	ldr r2, _08067790
	adds r1, r2
	adds r1, r0
	ldr r4, [r1]
	bl sub_8083600
	adds r1, r4, 0
	movs r2, 0
	bl sub_8067794
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806778C: .4byte gDungeonGlobalData
_08067790: .4byte 0x0001357c
	thumb_func_end sub_8067768

	thumb_func_start sub_8067794
sub_8067794:
	push {r4-r7,lr}
	sub sp, 0x40
	adds r7, r1, 0
	ldr r4, [r7, 0x70]
	cmp r7, 0
	bne _080677B4
	ldr r0, _080677B0
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _0806786C
	.align 2, 0
_080677B0: .4byte gUnknown_80F8F08
_080677B4:
	ldr r0, _080677F0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080677F4
	ldr r5, [r0]
	ldr r0, _080677F8
	ldr r6, [r0]
	ldrb r2, [r4, 0xA]
	cmp r2, 0
	blt _08067834
	ldr r1, _080677FC
	movs r0, 0x64
	muls r0, r2
	ldr r2, _08067800
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	bl sub_806A564
	lsls r0, 24
	cmp r0, 0
	beq _0806780C
	ldr r0, _08067804
	ldr r5, [r0]
	ldr r0, _08067808
	b _08067832
	.align 2, 0
_080677F0: .4byte gAvailablePokemonNames
_080677F4: .4byte gUnknown_80F9094
_080677F8: .4byte gUnknown_80F913C
_080677FC: .4byte gRecruitedPokemonRef
_08067800: .4byte 0x00008df8
_08067804: .4byte gUnknown_80F9114
_08067808: .4byte gUnknown_80F9154
_0806780C:
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _08067834
	bl sub_8044210
	lsls r0, 24
	cmp r0, 0
	beq _0806782C
	ldr r0, _08067828
	b _0806782E
	.align 2, 0
_08067828: .4byte gUnknown_80F90DC
_0806782C:
	ldr r0, _08067874
_0806782E:
	ldr r5, [r0]
	ldr r0, _08067878
_08067832:
	ldr r6, [r0]
_08067834:
	movs r0, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_8052B8C
	cmp r0, 0x1
	bne _0806786C
	ldr r4, _0806787C
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x40
	bl strncpy
	ldr r1, _08067880
	adds r0, r7, 0
	movs r2, 0
	bl sub_8068FE0
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0x40
	bl strncpy
	movs r0, 0
	adds r1, r6, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806786C:
	add sp, 0x40
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067874: .4byte gUnknown_80F90C8
_08067878: .4byte gUnknown_80F9150
_0806787C: .4byte gAvailablePokemonNames
_08067880: .4byte 0x0000021d
	thumb_func_end sub_8067794

	thumb_func_start sub_8067884
sub_8067884:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
	b _0806789A
_0806788E:
	ldr r1, _08067900
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080678C6
	adds r6, 0x1
_0806789A:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8070828
	cmp r6, r0
	bge _080678C6
	ldr r4, [r5, 0x70]
	adds r0, r4, 0
	adds r0, 0x50
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8055A00
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _0806788E
_080678C6:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8057588
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _080678F6
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080678F0
	ldr r0, [r5, 0x70]
	adds r0, 0x50
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_806A9B4
_080678F0:
	adds r0, r5, 0
	bl sub_806A1B0
_080678F6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08067900: .4byte 0x00000159
	thumb_func_end sub_8067884

	thumb_func_start sub_8067904
sub_8067904:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r5, r0, 0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldr r6, [r5, 0x70]
	ldr r1, _08067940
	movs r0, 0
	str r0, [r1]
	add r0, sp, 0x8
	mov r1, r9
	bl sub_8092A88
	adds r0, r6, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806794C
	ldr r0, _08067944
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08067948
	b _08067962
	.align 2, 0
_08067940: .4byte gUnknown_202F208
_08067944: .4byte gAvailablePokemonNames
_08067948: .4byte gUnknown_80F8F20
_0806794C:
	adds r0, r6, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _08067974
	ldr r0, _0806796C
	adds r1, r5, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08067970
_08067962:
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _08067A56
	.align 2, 0
_0806796C: .4byte gAvailablePokemonNames
_08067970: .4byte gUnknown_80F8F38
_08067974:
	movs r0, 0xB0
	lsls r0, 1
	movs r1, 0
	mov r10, r1
	cmp r9, r0
	bne _08067984
	movs r2, 0x1
	mov r10, r2
_08067984:
	movs r0, 0
	mov r8, r0
	movs r7, 0
	add r4, sp, 0x8
	b _080679D2
_0806798E:
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r6, r1
	strh r7, [r0]
	ldrb r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	orrs r0, r7
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0xA
	strb r0, [r4, 0x4]
	str r7, [sp]
	str r4, [sp, 0x4]
	adds r0, r5, 0
	mov r1, r10
	movs r2, 0
	movs r3, 0
	bl sub_8055FA0
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080679DE
	ldr r2, _08067A68
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080679DE
	movs r0, 0x1
	add r8, r0
_080679D2:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8070828
	cmp r8, r0
	blt _0806798E
_080679DE:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08067A56
	movs r0, 0xB0
	lsls r0, 1
	cmp r9, r0
	bne _08067A04
	ldr r0, _08067A6C
	ldr r0, [r0]
	cmp r0, 0
	bne _08067A04
	ldr r0, _08067A70
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
_08067A04:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _08067A50
	movs r0, 0xB0
	lsls r0, 1
	cmp r9, r0
	beq _08067A50
	ldr r4, _08067A74
	adds r3, r6, 0
	adds r3, 0x46
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0]
	ldrh r1, [r5, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _08067A78
	ldr r1, [sp, 0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x10]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2]
	ldrh r2, [r5, 0x6]
	adds r0, r2
	lsls r0, 16
	ldr r2, _08067A7C
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x10]
	add r0, sp, 0x10
	movs r1, 0x1
	bl sub_807FE44
_08067A50:
	adds r0, r5, 0
	bl sub_8071DA4
_08067A56:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067A68: .4byte 0x00000159
_08067A6C: .4byte gUnknown_202F208
_08067A70: .4byte gUnknown_80FC690
_08067A74: .4byte gUnknown_80F4448
_08067A78: .4byte 0xffff0000
_08067A7C: .4byte 0x0000ffff
	thumb_func_end sub_8067904

	thumb_func_start sub_8067A80
sub_8067A80:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x6C
	str r1, [sp, 0x68]
	mov r8, r2
	mov r9, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x64]
	ldr r1, _08067AC8
	add r0, sp, 0x4
	movs r2, 0x60
	bl memcpy
	ldr r1, _08067ACC
	movs r0, 0
	str r0, [r1]
	mov r10, r0
	cmp r10, r8
	blt _08067AB0
	b _08067ED8
_08067AB0:
	ldr r5, _08067AD0
	mov r4, r9
	mov r3, r8
_08067AB6:
	ldm r4!, {r2}
	ldrh r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	strh r0, [r2]
	subs r3, 0x1
	cmp r3, 0
	bne _08067AB6
	b _08067ED8
	.align 2, 0
_08067AC8: .4byte gUnknown_8106DC8
_08067ACC: .4byte gUnknown_202F30C
_08067AD0: .4byte 0x00007fff
_08067AD4:
	movs r7, 0
	ldr r1, _08067B98
	movs r0, 0x1
	strb r0, [r1]
	strb r7, [r1, 0x1]
	movs r0, 0xE
	strb r0, [r1, 0x2]
	strb r7, [r1, 0x3]
	add r0, sp, 0x4
	movs r1, 0x1
	bl sub_803ECB4
	ldr r5, _08067B9C
	ldr r2, [r5]
	ldr r0, [sp, 0x68]
	str r0, [sp]
	ldr r0, [sp, 0x64]
	mov r1, r9
	mov r3, r8
	bl sub_8067F00
	ldr r4, _08067BA0
	mov r0, r8
	cmp r0, 0x8
	ble _08067B08
	movs r0, 0x8
_08067B08:
	strh r0, [r4, 0x1A]
	mov r1, r10
	strh r1, [r4, 0x18]
	movs r0, 0x8
	strh r0, [r4, 0x1C]
	strh r7, [r4, 0x1E]
	strh r7, [r4, 0x20]
	strh r7, [r4, 0x4]
	movs r0, 0x12
	strh r0, [r4, 0x6]
	strh r7, [r4, 0xC]
	strh r7, [r4, 0xE]
	strh r7, [r4, 0x14]
	str r7, [r4]
	adds r0, r4, 0
	adds r0, 0x28
	bl sub_801317C
	adds r0, r4, 0
	movs r1, 0
	bl sub_80137B0
	adds r6, r5, 0
_08067B36:
	ldr r0, _08067BA0
	bl AddMenuCursorSprite
	movs r5, 0
	movs r7, 0
	ldr r0, [r6]
	mov r2, r8
	subs r0, r2, r0
	cmp r0, 0x8
	ble _08067B50
	movs r5, 0x1
	bl sub_80684C4
_08067B50:
	ldr r0, [r6]
	cmp r0, 0
	beq _08067B5C
	movs r7, 0x1
	bl sub_8068344
_08067B5C:
	movs r0, 0
	ldr r1, _08067BA4
	bl sub_8014140
	adds r4, r0, 0
	movs r0, 0x37
	bl sub_803E46C
	cmp r4, 0x2
	bne _08067BAC
	cmp r5, 0
	beq _08067BAC
	ldr r0, [r6]
	mov r3, r8
	subs r0, r3, r0
	cmp r0, 0x8
	ble _08067BF0
	ldr r5, _08067BA8
	movs r4, 0x5
_08067B82:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067B82
	b _08067BEA
	.align 2, 0
_08067B98: .4byte gUnknown_202F308
_08067B9C: .4byte gUnknown_202F30C
_08067BA0: .4byte gUnknown_202EE10
_08067BA4: .4byte gUnknown_8106DA4
_08067BA8: .4byte gUnknown_203B080
_08067BAC:
	ldr r0, _08067BF8
	ldrh r1, [r0, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08067C0C
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _08067BFC
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0x7
	bne _08067C04
	ldr r0, [r6]
	mov r3, r8
	subs r0, r3, r0
	cmp r0, 0x8
	ble _08067BF0
	ldr r5, _08067C00
	movs r4, 0x5
_08067BD6:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067BD6
_08067BEA:
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
_08067BF0:
	movs r7, 0
	movs r0, 0x7
	mov r10, r0
	b _08067CF6
	.align 2, 0
_08067BF8: .4byte gRealInputs
_08067BFC: .4byte gUnknown_202EE10
_08067C00: .4byte gUnknown_203B080
_08067C04:
	adds r0, r1, 0
	movs r1, 0
	bl sub_80136E0
_08067C0C:
	cmp r4, 0x1
	bne _08067C44
	cmp r7, 0
	beq _08067C44
	ldr r0, [r6]
	cmp r0, 0
	beq _08067C38
	ldr r5, _08067C40
	movs r4, 0x5
_08067C1E:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067C1E
	ldr r0, [r6]
	subs r0, 0x1
	str r0, [r6]
_08067C38:
	movs r7, 0
	movs r1, 0
	mov r10, r1
	b _08067CF6
	.align 2, 0
_08067C40: .4byte gUnknown_203B084
_08067C44:
	ldr r0, _08067C8C
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08067CA0
	movs r0, 0x1
	bl sub_8083CE0
	ldr r1, _08067C90
	movs r2, 0x18
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _08067C98
	ldr r0, [r6]
	cmp r0, 0
	beq _08067C84
	ldr r5, _08067C94
	movs r4, 0x5
_08067C6A:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x37
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08067C6A
	ldr r0, [r6]
	subs r0, 0x1
	str r0, [r6]
_08067C84:
	movs r7, 0
	movs r3, 0
	mov r10, r3
	b _08067CF6
	.align 2, 0
_08067C8C: .4byte gRealInputs
_08067C90: .4byte gUnknown_202EE10
_08067C94: .4byte gUnknown_203B084
_08067C98:
	adds r0, r1, 0
	movs r1, 0
	bl sub_8013744
_08067CA0:
	bl sub_80048C8
	lsls r0, 24
	cmp r0, 0
	beq _08067CAC
	b _08067B36
_08067CAC:
	ldr r0, _08067CD4
	ldrh r1, [r0, 0x2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08067D40
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08067CCC
	ldr r2, _08067CD8
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067CDC
_08067CCC:
	bl sub_8083D08
	movs r7, 0x1
	b _08067CF6
	.align 2, 0
_08067CD4: .4byte gRealInputs
_08067CD8: .4byte gUnknown_202EE10
_08067CDC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08067CF0
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _08067CF0
	b _08067B36
_08067CF0:
	bl sub_8083D30
	movs r7, 0x2
_08067CF6:
	ldr r4, _08067D34
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x37
	bl sub_803E46C
	cmp r7, 0
	bne _08067D0A
	b _08067AD4
_08067D0A:
	cmp r7, 0x2
	bne _08067D48
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	mov r10, r0
	ldr r0, _08067D38
	ldr r0, [r0]
	ldr r2, [sp, 0x68]
	cmp r0, r2
	bge _08067D20
	b _08067AD4
_08067D20:
	ldr r0, _08067D3C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08067D32
	b _08067ED8
_08067D32:
	b _08067AD4
	.align 2, 0
_08067D34: .4byte gUnknown_202EE10
_08067D38: .4byte gUnknown_202F310
_08067D3C: .4byte gUnknown_80FDFB8
_08067D40:
	bl sub_8083D1C
	movs r7, 0x3
	b _08067CF6
_08067D48:
	cmp r7, 0x3
	bne _08067D64
	movs r0, 0x18
	ldrsh r3, [r4, r0]
	mov r10, r3
	ldr r0, _08067D60
	ldr r0, [r0]
	add r0, r10
	lsls r0, 2
	add r0, r9
	b _08067ED0
	.align 2, 0
_08067D60: .4byte gUnknown_202F30C
_08067D64:
	movs r2, 0x18
	ldrsh r1, [r4, r2]
	mov r10, r1
	ldr r0, _08067DAC
	ldr r0, [r0]
	adds r4, r0, r1
	ldr r1, _08067DB0
	movs r0, 0
	str r0, [r1]
	movs r0, 0x29
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0x2A
	movs r1, 0
	bl sub_8044F5C
	movs r0, 0x40
	movs r1, 0
	bl sub_8044F5C
	lsls r0, r4, 2
	add r0, r9
	ldr r0, [r0]
	ldrh r0, [r0]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08067DBC
	movs r0, 0x29
	bl sub_8044FF0
	b _08067DC2
	.align 2, 0
_08067DAC: .4byte gUnknown_202F30C
_08067DB0: .4byte gUnknown_202EE6C
_08067DB4:
	bl sub_8083D08
	movs r7, 0x1
	b _08067E6E
_08067DBC:
	movs r0, 0x2A
	bl sub_8044FF0
_08067DC2:
	lsls r0, r4, 2
	mov r2, r9
	adds r1, r0, r2
	ldr r2, [r1]
	ldrb r1, [r2, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	bne _08067DDC
	ldrb r1, [r2, 0x4]
	cmp r1, 0x40
	beq _08067DDC
	cmp r1, 0x41
	bne _08067DE2
_08067DDC:
	movs r0, 0x29
	bl sub_8044FF0
_08067DE2:
	bl sub_8045064
	add r0, sp, 0x4
	movs r1, 0x15
	bl sub_805FC30
	ldr r4, _08067EA0
	ldr r5, _08067EA4
	adds r7, r4, 0
	adds r7, 0x2A
_08067DF6:
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x37
	bl sub_803E46C
	ldrh r1, [r5, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08067E1A
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_80136E0
_08067E1A:
	ldrh r1, [r5, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08067E32
	movs r0, 0x1
	bl sub_8083CE0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8013744
_08067E32:
	ldrh r1, [r5, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08067E46
	adds r0, r4, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067E58
_08067E46:
	movs r3, 0x18
	ldrsh r0, [r4, r3]
	bl sub_8044F3C
	lsls r0, 24
	cmp r0, 0
	bne _08067DB4
	bl sub_8083D30
_08067E58:
	ldrh r1, [r5, 0x2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08067E68
	ldrb r0, [r7]
	cmp r0, 0
	beq _08067DF6
_08067E68:
	bl sub_8083D30
	movs r7, 0
_08067E6E:
	ldr r4, _08067EA0
	adds r0, r4, 0
	bl AddMenuCursorSprite
	movs r0, 0x37
	bl sub_803E46C
	cmp r7, 0
	bne _08067E82
	b _08067AD4
_08067E82:
	movs r1, 0x18
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08067EA8
	mov r2, r9
	adds r0, r6, r2
	ldr r1, [r0]
	ldrh r2, [r1]
	movs r3, 0x80
	lsls r3, 8
	adds r0, r3, 0
	orrs r0, r2
	strh r0, [r1]
	b _08067EBC
	.align 2, 0
_08067EA0: .4byte gUnknown_202EE10
_08067EA4: .4byte gRealInputs
_08067EA8:
	cmp r0, 0x1
	bne _08067ECC
	mov r1, r9
	adds r0, r6, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	ldr r3, _08067EC8
	adds r1, r3, 0
	ands r0, r1
	strh r0, [r2]
_08067EBC:
	mov r0, r8
	mov r1, r9
	bl sub_8068310
	b _08067AD4
	.align 2, 0
_08067EC8: .4byte 0x00007fff
_08067ECC:
	mov r1, r9
	adds r0, r6, r1
_08067ED0:
	ldr r0, [r0]
	bl sub_806806C
	b _08067AD4
_08067ED8:
	mov r0, r8
	mov r1, r9
	bl sub_8068310
	ldr r0, _08067EFC
	ldr r0, [r0]
	ldr r2, [sp, 0x68]
	cmp r0, r2
	bge _08067EEC
	b _08067AD4
_08067EEC:
	add sp, 0x6C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067EFC: .4byte gUnknown_202F310
	thumb_func_end sub_8067A80

	thumb_func_start sub_8067F00
sub_8067F00:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	mov r9, r1
	str r3, [sp, 0x4]
	lsls r4, 24
	lsrs r4, 24
	subs r7, r2, 0x1
	movs r0, 0x16
	mov r8, r0
	movs r0, 0
	bl sub_80073B8
	ldr r0, _08067F44
	adds r1, r4, 0
	movs r2, 0
	bl sub_8092578
	ldr r2, _08067F48
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	movs r3, 0
	bl xxx_format_and_draw
	movs r1, 0
	mov r10, r1
	b _08067FF6
	.align 2, 0
_08067F44: .4byte gAvailablePokemonNames
_08067F48: .4byte gUnknown_8106E28
_08067F4C:
	ldr r4, _08067F8C
	lsls r6, r7, 2
	mov r0, r9
	adds r5, r6, r0
	ldr r1, [r5]
	adds r0, r4, 0
	movs r2, 0
	bl sub_808D9AC
	adds r4, 0x50
	ldr r0, [r5]
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl sub_808D930
	ldr r1, _08067F90
	adds r0, r7, 0x1
	str r0, [r1]
	ldr r0, [r5]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	beq _08067F9C
	ldr r0, _08067F94
	ldr r1, _08067F98
	bl strcpy
	b _08067FA4
	.align 2, 0
_08067F8C: .4byte gAvailablePokemonNames
_08067F90: .4byte gUnknown_202DE30
_08067F94: .4byte gUnknown_202DE58
_08067F98: .4byte gUnknown_8106E2C
_08067F9C:
	ldr r0, _08067FCC
	ldr r1, _08067FD0
	bl strcpy
_08067FA4:
	mov r1, r9
	adds r0, r6, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 7
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08067FD8
	ldr r2, _08067FD4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x7
	mov r1, r8
	movs r3, 0
	bl xxx_format_and_draw
	b _08067FE6
	.align 2, 0
_08067FCC: .4byte gUnknown_202DE58
_08067FD0: .4byte gUnknown_8106E30
_08067FD4: .4byte gUnknown_8106E34
_08067FD8:
	ldr r2, _08068028
	str r0, [sp]
	movs r0, 0x7
	mov r1, r8
	movs r3, 0
	bl xxx_format_and_draw
_08067FE6:
	movs r2, 0x1
	add r10, r2
	movs r0, 0xC
	add r8, r0
	adds r7, 0x1
	mov r1, r10
	cmp r1, 0x9
	bgt _08068000
_08067FF6:
	cmp r7, 0
	blt _08067FE6
	ldr r2, [sp, 0x4]
	cmp r7, r2
	blt _08067F4C
_08068000:
	movs r0, 0
	bl sub_80073E0
	movs r0, 0x1
	bl sub_80073B8
	ldr r0, _0806802C
	ldr r0, [r0]
	ldr r1, [sp, 0x28]
	cmp r0, r1
	blt _08068034
	ldr r2, _08068030
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x2
	movs r3, 0x1
	bl xxx_format_and_draw
	b _0806804C
	.align 2, 0
_08068028: .4byte gUnknown_8106E48
_0806802C: .4byte gUnknown_202F310
_08068030: .4byte gUnknown_8106E5C
_08068034:
	ldr r1, _08068064
	ldr r2, [sp, 0x28]
	subs r0, r2, r0
	str r0, [r1]
	ldr r2, _08068068
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x2
	movs r3, 0x1
	bl xxx_format_and_draw
_0806804C:
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068064: .4byte gUnknown_202DE30
_08068068: .4byte gUnknown_8106E6C
	thumb_func_end sub_8067F00

	thumb_func_start sub_806806C
sub_806806C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x110
	str r0, [sp, 0x108]
	add r4, sp, 0x98
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x60
	bl memset
	movs r0, 0x6
	str r0, [r4, 0x4]
	movs r1, 0x2
	strh r1, [r4, 0x8]
	strh r1, [r4, 0xA]
	movs r2, 0x12
	strh r2, [r4, 0xC]
	movs r0, 0xE
	strh r0, [r4, 0xE]
	strh r2, [r4, 0x10]
	strh r1, [r4, 0x12]
	ldr r0, _080681B4
	str r0, [r4, 0x14]
	movs r0, 0x3
	str r0, [r4, 0x1C]
	str r0, [r4, 0x34]
	str r0, [r4, 0x4C]
	movs r7, 0
	add r1, sp, 0x44
	strh r7, [r1]
	mov r0, sp
	adds r0, 0x5A
	strh r7, [r0]
	ldr r0, _080681B8
	strh r7, [r0, 0x18]
	mov r9, r1
	adds r1, 0xB4
	str r1, [sp, 0x10C]
	add r2, sp, 0x68
	mov r10, r2
	adds r6, r0, 0
_080680C4:
	movs r3, 0
	mov r8, r3
	add r1, sp, 0xF8
	ldr r0, _080681BC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080681B4
	movs r2, 0x4
	strb r2, [r1]
	strb r7, [r1, 0x1]
	movs r0, 0xA
	strb r0, [r1, 0x2]
	mov r4, r8
	strb r4, [r1, 0x3]
	strh r7, [r6, 0x1E]
	strh r2, [r6, 0x20]
	mov r0, r8
	strh r0, [r6, 0x1A]
	strh r0, [r6, 0x18]
	strh r0, [r6, 0x1C]
	strh r0, [r6, 0x4]
	movs r0, 0x10
	strh r0, [r6, 0x6]
	mov r1, r8
	strh r1, [r6, 0x14]
	mov r2, r8
	str r2, [r6]
	adds r0, r6, 0
	adds r0, 0x28
	bl sub_801317C
	add r0, sp, 0x98
	movs r1, 0x1
	bl sub_803ECB4
	ldr r0, _080681C0
	ldr r0, [r0]
	ldr r3, _080681C4
	adds r0, r3
	ldrb r2, [r0]
	add r0, sp, 0x4
	ldr r1, [sp, 0x108]
	bl sub_808FF20
	lsls r4, r7, 2
	mov r0, sp
	adds r0, r4
	adds r0, 0xF8
	ldr r0, [r0]
	mov r1, r8
	str r1, [sp]
	adds r1, r7, 0
	add r2, sp, 0x4
	mov r3, r10
	bl CreatePokemonInfoTabScreen
	ldr r1, _080681C8
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r0, 0xF
	lsls r0, 3
	strh r0, [r6, 0xC]
	movs r3, 0x2
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	lsls r0, 3
	subs r0, 0x2
	strh r0, [r6, 0xE]
_08068150:
	ldr r0, _080681B8
	bl AddMenuCursorSprite
	ldr r1, [sp, 0x10C]
	adds r0, r1, r4
	ldr r0, [r0]
	cmp r0, 0x4
	bne _0806817A
	mov r2, r10
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0806816C
	bl sub_80684C4
_0806816C:
	mov r3, r9
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0806817A
	bl sub_8068344
_0806817A:
	movs r0, 0
	ldr r1, _080681CC
	bl sub_8014140
	adds r5, r0, 0
	movs r0, 0x1C
	bl sub_803E46C
	ldr r3, _080681D0
	ldrh r1, [r3, 0x2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080681A2
	ldr r2, _080681B8
	adds r0, r2, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0
	beq _080681D4
_080681A2:
	movs r0, 0
	bl sub_8083CE0
	adds r7, 0x1
	cmp r7, 0x4
	beq _080681B0
	b _080682E8
_080681B0:
	movs r7, 0
	b _080682E8
	.align 2, 0
_080681B4: .4byte gUnknown_202F308
_080681B8: .4byte gUnknown_202EE10
_080681BC: .4byte gUnknown_8106E80
_080681C0: .4byte gDungeonGlobalData
_080681C4: .4byte 0x0000065a
_080681C8: .4byte gUnknown_2027370
_080681CC: .4byte gUnknown_8106DA4
_080681D0: .4byte gRealInputs
_080681D4:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _080681E6
	adds r0, r2, 0
	adds r0, 0x2C
	ldrb r0, [r0]
	cmp r0, 0
	beq _080681FA
_080681E6:
	movs r0, 0
	bl sub_8083CE0
	subs r7, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r7, r0
	bne _080682E8
	movs r7, 0x3
	b _080682E8
_080681FA:
	ldr r2, [sp, 0x10C]
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08068294
	ldrh r1, [r3, 0x4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08068212
	cmp r5, 0x2
	bne _08068248
_08068212:
	mov r3, r10
	ldrb r0, [r3, 0x8]
	cmp r0, 0
	beq _08068248
	movs r0, 0
	bl sub_8083CE0
	ldr r5, _08068244
	movs r4, 0x5
_08068224:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _08068224
	mov r4, r9
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _080682E8
	.align 2, 0
_08068244: .4byte gUnknown_203B080
_08068248:
	ldr r0, _0806828C
	ldrh r1, [r0, 0x4]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08068258
	cmp r5, 0x1
	bne _08068294
_08068258:
	mov r1, r9
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _08068294
	movs r0, 0
	bl sub_8083CE0
	ldr r5, _08068290
	movs r4, 0x5
_0806826C:
	ldr r1, [r5]
	movs r0, 0
	bl _call_via_r1
	movs r0, 0x1C
	bl sub_803E46C
	subs r4, 0x1
	cmp r4, 0
	bge _0806826C
	mov r3, r9
	ldrh r0, [r3]
	subs r0, 0x1
	strh r0, [r3]
	b _080682E8
	.align 2, 0
_0806828C: .4byte gRealInputs
_08068290: .4byte gUnknown_203B084
_08068294:
	bl sub_80048C8
	lsls r0, 24
	cmp r0, 0
	beq _080682A0
	b _08068150
_080682A0:
	ldr r0, _080682C4
	ldrh r1, [r0, 0x2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080682B8
	ldr r2, _080682C8
	adds r0, r2, 0
	adds r0, 0x29
	ldrb r0, [r0]
	cmp r0, 0
	beq _080682CC
_080682B8:
	bl sub_8083D08
	movs r4, 0x1
	mov r8, r4
	b _080682E8
	.align 2, 0
_080682C4: .4byte gRealInputs
_080682C8: .4byte gUnknown_202EE10
_080682CC:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080682E0
	adds r0, r2, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, 0
	bne _080682E0
	b _08068150
_080682E0:
	bl sub_8083D30
	movs r0, 0x1
	mov r8, r0
_080682E8:
	movs r0, 0x37
	bl sub_803E46C
	mov r1, r8
	cmp r1, 0
	bne _080682F6
	b _080680C4
_080682F6:
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
	thumb_func_end sub_806806C

	thumb_func_start sub_8068310
sub_8068310:
	push {r4-r6,lr}
	movs r4, 0
	ldr r6, _08068340
	cmp r4, r0
	bge _08068338
	movs r5, 0x80
	lsls r5, 8
	adds r3, r1, 0
	adds r2, r0, 0
_08068322:
	ldr r0, [r3]
	ldrh r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08068330
	adds r4, 0x1
_08068330:
	adds r3, 0x4
	subs r2, 0x1
	cmp r2, 0
	bne _08068322
_08068338:
	str r4, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068340: .4byte gUnknown_202F310
	thumb_func_end sub_8068310

	thumb_func_start sub_8068344
sub_8068344:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	ldr r0, _08068494
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806835C
	b _08068486
_0806835C:
	ldr r0, _08068498
	mov r9, r0
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _0806849C
	ands r1, r0
	ldr r3, _080684A0
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080684A4
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r6, _080684A8
	mov r8, r6
	mov r0, r8
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080684AC
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080684B0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r6, _080684B4
	adds r0, r6, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	movs r1, 0x80
	lsls r1, 6
	mov r5, sp
	ldrh r0, [r5, 0x2]
	ldr r2, _080684B8
	ands r2, r0
	orrs r2, r1
	ands r2, r6
	movs r3, 0xFC
	lsls r3, 2
	ldrh r1, [r5, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r3
	mov r1, r8
	ands r0, r1
	movs r3, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _080684BC
	ands r0, r4
	orrs r0, r1
	strh r0, [r5, 0x4]
	mov r6, r9
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x8
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r5, 0x6]
	ands r3, r1
	orrs r3, r0
	strh r3, [r5, 0x6]
	movs r3, 0
	ldrsh r0, [r6, r3]
	lsls r0, 3
	adds r0, 0x40
	ldr r1, _080684C0
	ands r0, r1
	movs r1, 0xFE
	lsls r1, 8
	ands r2, r1
	orrs r2, r0
	strh r2, [r5, 0x2]
	movs r1, 0x80
	lsls r1, 1
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
_08068486:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068494: .4byte gUnknown_202EDCC
_08068498: .4byte gUnknown_2027370
_0806849C: .4byte 0x0000feff
_080684A0: .4byte 0xffff0000
_080684A4: .4byte 0x0000fdff
_080684A8: .4byte 0x0000f3ff
_080684AC: .4byte 0x0000efff
_080684B0: .4byte 0x0000dfff
_080684B4: .4byte 0x00003fff
_080684B8: .4byte 0x0000c1ff
_080684BC: .4byte 0x00000fff
_080684C0: .4byte 0x000001ff
	thumb_func_end sub_8068344

	thumb_func_start sub_80684C4
sub_80684C4:
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r0, _080685E8
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080684D6
	b _080685DE
_080684D6:
	ldr r6, _080685EC
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, _080685F0
	ands r1, r0
	ldr r3, _080685F4
	ldr r0, [sp]
	ands r0, r3
	orrs r0, r1
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	adds r2, r3, 0
	ands r2, r0
	orrs r2, r1
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080685F8
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r5, _080685FC
	adds r0, r5, 0
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08068600
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08068604
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	adds r2, r3, 0
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r4, 0x80
	lsls r4, 7
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08068608
	ands r0, r1
	adds r1, r3, 0
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	ldrh r0, [r0]
	orrs r4, r0
	ands r3, r1
	orrs r3, r4
	str r3, [sp]
	mov r3, sp
	movs r2, 0xFC
	lsls r2, 2
	ldrh r1, [r3, 0x4]
	movs r0, 0xFC
	lsls r0, 8
	ands r0, r1
	orrs r0, r2
	ands r0, r5
	movs r2, 0xF
	movs r1, 0xF0
	lsls r1, 8
	ldr r4, _0806860C
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, 0x4]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x70
	ands r0, r4
	lsls r0, 4
	ldrh r1, [r3, 0x6]
	ands r2, r1
	orrs r2, r0
	strh r2, [r3, 0x6]
	movs r1, 0
	ldrsh r0, [r6, r1]
	lsls r0, 3
	adds r0, 0x40
	ldr r1, _08068610
	ands r0, r1
	strh r0, [r3, 0x2]
	subs r1, 0xFF
	mov r0, sp
	movs r2, 0
	movs r3, 0
	bl AddSprite
_080685DE:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080685E8: .4byte gUnknown_202EDCC
_080685EC: .4byte gUnknown_2027370
_080685F0: .4byte 0x0000feff
_080685F4: .4byte 0xffff0000
_080685F8: .4byte 0x0000fdff
_080685FC: .4byte 0x0000f3ff
_08068600: .4byte 0x0000efff
_08068604: .4byte 0x0000dfff
_08068608: .4byte 0x00003fff
_0806860C: .4byte 0x00000fff
_08068610: .4byte 0x000001ff
	thumb_func_end sub_80684C4

	thumb_func_start sub_8068614
sub_8068614:
	push {lr}
	ldr r0, _0806862C
	ldr r1, _08068630
	bl OpenFileAndGetFileDataPtr
	ldr r1, _08068634
	ldr r1, [r1]
	ldr r2, _08068638
	adds r1, r2
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0806862C: .4byte gUnknown_8106E98
_08068630: .4byte gMonsterFileArchive
_08068634: .4byte gDungeonGlobalData
_08068638: .4byte 0x000181e4
	thumb_func_end sub_8068614

	thumb_func_start sub_806863C
sub_806863C:
	push {lr}
	ldr r0, _08068650
	ldr r0, [r0]
	ldr r1, _08068654
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	pop {r0}
	bx r0
	.align 2, 0
_08068650: .4byte gDungeonGlobalData
_08068654: .4byte 0x000181e4
	thumb_func_end sub_806863C

	thumb_func_start sub_8068658
sub_8068658:
	push {r4-r6,lr}
	movs r4, 0
	ldr r6, _08068740
	ldr r5, _08068744
	ldr r3, _08068748
	movs r2, 0
_08068664:
	ldr r0, [r5]
	lsls r1, r4, 2
	adds r0, r3
	adds r0, r1
	str r2, [r0]
	adds r4, 0x1
	cmp r4, r6
	ble _08068664
	ldr r0, _0806874C
	movs r1, 0x1
	bl sub_8068838
	movs r4, 0
	ldr r1, _08068744
	ldr r0, [r1]
	ldr r2, _08068750
	adds r0, r2
	ldr r0, [r0]
	cmp r4, r0
	bge _080686B2
	adds r6, r1, 0
	ldr r5, _08068754
_08068690:
	ldr r0, [r6]
	adds r0, r5
	bl sub_808E9B8
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x1
	bl sub_8068838
	adds r5, 0x8
	adds r4, 0x1
	ldr r0, [r6]
	ldr r1, _08068750
	adds r0, r1
	ldr r0, [r0]
	cmp r4, r0
	blt _08068690
_080686B2:
	ldr r0, _08068744
	ldr r0, [r0]
	movs r2, 0xD1
	lsls r2, 3
	adds r1, r0, r2
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080686CA
	movs r1, 0x1
	bl sub_8068838
_080686CA:
	movs r4, 0
	ldr r6, _08068758
	movs r5, 0x1
_080686D0:
	movs r0, 0x64
	muls r0, r4
	ldr r1, _0806875C
	adds r0, r1
	ldr r1, [r6]
	adds r1, r0
	ldrh r2, [r1]
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _080686F8
	lsrs r0, r2, 1
	ands r0, r5
	cmp r0, 0
	beq _080686F8
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	movs r1, 0
	bl sub_8068838
_080686F8:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080686D0
	ldr r0, _08068744
	ldr r0, [r0]
	ldr r1, _08068760
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0x31
	bne _08068738
	movs r4, 0
	ldr r5, _08068758
_08068712:
	movs r0, 0x58
	muls r0, r4
	ldr r1, _08068764
	adds r0, r1
	ldr r1, [r5]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068732
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	movs r1, 0x1
	bl sub_8068838
_08068732:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08068712
_08068738:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068740: .4byte 0x000001a7
_08068744: .4byte gDungeonGlobalData
_08068748: .4byte 0x00017b44
_0806874C: .4byte 0x000001a5
_08068750: .4byte 0x000037e4
_08068754: .4byte 0x0000343c
_08068758: .4byte gRecruitedPokemonRef
_0806875C: .4byte 0x00008df8
_08068760: .4byte 0x00003a14
_08068764: .4byte 0x00008f88
	thumb_func_end sub_8068658

	thumb_func_start sub_8068768
sub_8068768:
	push {r4,r5,lr}
	movs r5, 0
_0806876C:
	ldr r0, _080687A4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080687A8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _08068796
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08068796
	ldr r0, [r4, 0x70]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0
	bl sub_8068838
_08068796:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806876C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080687A4: .4byte gDungeonGlobalData
_080687A8: .4byte 0x000135cc
	thumb_func_end sub_8068768

	thumb_func_start sub_80687AC
sub_80687AC:
	ldr r0, _080687C4
	ldr r1, [r0]
	ldr r0, _080687C8
	adds r2, r1, r0
	movs r0, 0x80
	lsls r0, 3
	str r0, [r2]
	ldr r0, _080687CC
	adds r1, r0
	movs r0, 0xA
	str r0, [r1]
	bx lr
	.align 2, 0
_080687C4: .4byte gDungeonGlobalData
_080687C8: .4byte 0x000037f0
_080687CC: .4byte 0x000037f4
	thumb_func_end sub_80687AC

	thumb_func_start sub_80687D0
sub_80687D0:
	lsls r0, 16
	ldr r1, _080687E4
	ldr r1, [r1]
	asrs r0, 14
	ldr r2, _080687E8
	adds r1, r2
	adds r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_080687E4: .4byte gDungeonGlobalData
_080687E8: .4byte 0x00017b44
	thumb_func_end sub_80687D0

	thumb_func_start sub_80687EC
sub_80687EC:
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 16
	asrs r2, r0, 16
	ldr r5, _08068828
	ldr r0, [r5]
	lsls r4, r2, 2
	ldr r1, _0806882C
	adds r0, r1
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	bne _08068820
	ldr r1, _08068830
	mov r0, sp
	bl sprintf
	ldr r1, _08068834
	mov r0, sp
	bl OpenFileAndGetFileDataPtr
	ldr r1, [r5]
	ldr r2, _0806882C
	adds r1, r2
	adds r1, r4
	str r0, [r1]
_08068820:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068828: .4byte gDungeonGlobalData
_0806882C: .4byte 0x00017b44
_08068830: .4byte gUnknown_8106EA0
_08068834: .4byte gMonsterFileArchive
	thumb_func_end sub_80687EC

	thumb_func_start sub_8068838
sub_8068838:
	push {r4,lr}
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	cmp r1, 0
	bne _08068864
	movs r0, 0xCF
	lsls r0, 1
	cmp r4, r0
	beq _0806885E
	adds r0, 0x3
	cmp r4, r0
	beq _0806885E
	adds r0, 0x1
	cmp r4, r0
	beq _0806885E
	adds r0, 0x1
	cmp r4, r0
	bne _08068864
_0806885E:
	bl sub_80688B0
	b _0806887A
_08068864:
	adds r0, r4, 0
	bl sub_80687EC
	ldr r1, _08068880
	adds r0, r4, r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x3
	bhi _0806887A
	bl sub_8068884
_0806887A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08068880: .4byte 0xfffffe88
	thumb_func_end sub_8068838

	thumb_func_start sub_8068884
sub_8068884:
	push {lr}
	movs r0, 0xBC
	lsls r0, 1
	bl sub_80687EC
	ldr r0, _080688A8
	bl sub_80687EC
	movs r0, 0xBD
	lsls r0, 1
	bl sub_80687EC
	ldr r0, _080688AC
	bl sub_80687EC
	pop {r0}
	bx r0
	.align 2, 0
_080688A8: .4byte 0x00000179
_080688AC: .4byte 0x0000017b
	thumb_func_end sub_8068884

	thumb_func_start sub_80688B0
sub_80688B0:
	push {lr}
	ldr r0, _080688C8
	ldr r0, [r0]
	movs r1, 0xE0
	lsls r1, 6
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl sub_80687EC
	pop {r0}
	bx r0
	.align 2, 0
_080688C8: .4byte gDungeonGlobalData
	thumb_func_end sub_80688B0

	thumb_func_start sub_80688CC
sub_80688CC:
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, _08068900
_080688D2:
	ldr r0, [r6]
	lsls r4, r5, 2
	ldr r1, _08068904
	adds r0, r1
	adds r0, r4
	ldr r0, [r0]
	cmp r0, 0
	beq _080688F2
	bl CloseFile
	ldr r0, [r6]
	ldr r1, _08068904
	adds r0, r1
	adds r0, r4
	movs r1, 0
	str r1, [r0]
_080688F2:
	adds r5, 0x1
	ldr r0, _08068908
	cmp r5, r0
	ble _080688D2
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068900: .4byte gDungeonGlobalData
_08068904: .4byte 0x00017b44
_08068908: .4byte 0x000001a7
	thumb_func_end sub_80688CC

	thumb_func_start sub_806890C
sub_806890C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x64
	movs r0, 0
	mov r8, r0
	mov r10, r0
	ldr r6, _08068A60
	add r5, sp, 0x8
_08068922:
	movs r0, 0x58
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	ldr r2, [r6]
	adds r7, r2, r0
	ldrh r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068A1C
	lsrs r0, r1, 1
	movs r3, 0x1
	ands r0, r3
	cmp r0, 0
	beq _08068A1C
	movs r0, 0x64
	mov r4, r8
	muls r4, r0
	ldr r0, _08068A64
	adds r0, r4
	mov r9, r0
	adds r0, r2, r0
	mov r1, r10
	bl xxx_pokemonstruct_index_to_pokemon2_808DE30
	ldr r0, _08068A68
	ldr r0, [r0]
	ldr r1, _08068A6C
	adds r0, r1
	ldrb r0, [r0]
	bl GetLevelCondition
	lsls r0, 24
	cmp r0, 0
	beq _08068A06
	movs r0, 0x80
	lsls r0, 1
	str r0, [sp, 0x60]
	movs r2, 0x8
	ldrsh r1, [r7, r2]
	add r0, sp, 0x60
	str r0, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	add r0, sp, 0x8
	movs r2, 0
	bl sub_808CFD0
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x3]
	ldr r2, _08068A70
	adds r0, r2
	strb r1, [r0]
	ldr r1, [r6]
	adds r1, r4
	ldrh r2, [r5, 0x14]
	movs r3, 0x8E
	lsls r3, 8
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, 0x16]
	adds r3, 0x8
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, 0x16]
	adds r3, 0x2
	adds r0, r1, r3
	strh r2, [r0]
	ldrb r0, [r5, 0x18]
	ldr r2, _08068A74
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x19]
	adds r3, 0x3
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x1A]
	adds r2, 0x2
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, r4
	ldrb r1, [r5, 0x1B]
	adds r3, 0x2
	adds r0, r3
	strb r1, [r0]
	ldr r2, [r6]
	ldr r1, _08068A78
	adds r0, r2, r1
	adds r0, r4
	ldr r1, [sp, 0x24]
	str r1, [r0]
	adds r2, r4
	adds r3, 0x35
	adds r1, r2, r3
	ldr r0, [sp, 0x28]
	str r0, [r1]
	add r0, sp, 0x2C
	ldrb r0, [r0]
	ldr r1, _08068A7C
	adds r2, r1
	strb r0, [r2]
	ldr r0, [r6]
	add r0, r9
	adds r0, 0x1C
	add r1, sp, 0x34
	bl sub_8093F50
_08068A06:
	ldr r0, [r6]
	adds r0, r4
	ldr r2, _08068A80
	adds r0, r2
	mov r3, r8
	strh r3, [r0]
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x4
	beq _08068A2A
_08068A1C:
	movs r2, 0x1
	add r10, r2
	movs r0, 0xCE
	lsls r0, 1
	cmp r10, r0
	bgt _08068A2A
	b _08068922
_08068A2A:
	mov r3, r8
	cmp r3, 0x3
	bgt _08068A50
	ldr r4, _08068A60
	ldr r3, _08068A64
	movs r2, 0
	movs r0, 0x64
	mov r1, r8
	muls r1, r0
_08068A3C:
	ldr r0, [r4]
	adds r0, r1
	adds r0, r3
	strh r2, [r0]
	adds r1, 0x64
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08068A3C
_08068A50:
	add sp, 0x64
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068A60: .4byte gRecruitedPokemonRef
_08068A64: .4byte 0x00008df8
_08068A68: .4byte gDungeonGlobalData
_08068A6C: .4byte 0x00000644
_08068A70: .4byte 0x00008dfb
_08068A74: .4byte 0x00008e0c
_08068A78: .4byte 0x00008e10
_08068A7C: .4byte 0x00008e48
_08068A80: .4byte 0x00008e04
	thumb_func_end sub_806890C

	thumb_func_start sub_8068A84
sub_8068A84:
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r4, 0
	movs r5, 0
	ldr r7, _08068AE0
_08068A8E:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08068AE4
	adds r0, r1
	ldr r1, [r7]
	adds r2, r1, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068AB2
	movs r1, 0xE
	ldrsh r0, [r2, r1]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0
_08068AB2:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08068A8E
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0
	cmp r4, 0x6
	ble _08068B04
	ldr r0, _08068AE8
	adds r1, r6, 0
	movs r2, 0
	bl sub_808D9AC
	ldrb r0, [r6, 0x4]
	cmp r0, 0x4A
	bne _08068AF0
	ldr r0, _08068AEC
	b _08068BB2
	.align 2, 0
_08068AE0: .4byte gRecruitedPokemonRef
_08068AE4: .4byte 0x00008df8
_08068AE8: .4byte gAvailablePokemonNames
_08068AEC: .4byte gUnknown_80FE0F4
_08068AF0:
	cmp r0, 0x47
	bne _08068AFC
	ldr r0, _08068AF8
	b _08068BB2
	.align 2, 0
_08068AF8: .4byte gUnknown_80FE0F8
_08068AFC:
	ldr r0, _08068B00
	b _08068BB2
	.align 2, 0
_08068B00: .4byte gUnknown_80FE0AC
_08068B04:
	movs r5, 0
	ldr r2, _08068B6C
_08068B08:
	movs r0, 0x64
	muls r0, r5
	ldr r1, _08068B70
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08068B80
	adds r0, r4, 0
	adds r1, r6, 0
	ldr r2, _08068B74
	bl xxx_pokemonstruct_to_pokemon2_808DE50
	ldrh r0, [r4]
	movs r1, 0x1
	movs r2, 0
	orrs r1, r0
	strh r1, [r4]
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0x19
	bgt _08068B3E
	movs r0, 0x1A
	strh r0, [r4, 0x8]
_08068B3E:
	ldrh r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r4]
	strh r5, [r4, 0xC]
	adds r0, r4, 0
	adds r0, 0x40
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x1]
	strb r2, [r0]
	ldr r0, _08068B78
	adds r1, r6, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldrb r0, [r6, 0x4]
	cmp r0, 0x4A
	beq _08068BB0
	cmp r0, 0x47
	beq _08068BD0
	ldr r0, _08068B7C
	b _08068BB2
	.align 2, 0
_08068B6C: .4byte gRecruitedPokemonRef
_08068B70: .4byte 0x00008df8
_08068B74: .4byte 0x000055aa
_08068B78: .4byte gAvailablePokemonNames
_08068B7C: .4byte gUnknown_80FE134
_08068B80:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08068B08
	ldr r0, _08068B9C
	adds r1, r6, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldrb r0, [r6, 0x4]
	cmp r0, 0x4A
	bne _08068BA4
	ldr r0, _08068BA0
	b _08068BB2
	.align 2, 0
_08068B9C: .4byte gAvailablePokemonNames
_08068BA0: .4byte gUnknown_80FE0F4
_08068BA4:
	cmp r0, 0x47
	bne _08068BC4
	ldr r0, _08068BAC
	b _08068BB2
	.align 2, 0
_08068BAC: .4byte gUnknown_80FE0F8
_08068BB0:
	ldr r0, _08068BC0
_08068BB2:
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _08068BD0
	.align 2, 0
_08068BC0: .4byte gUnknown_80FE168
_08068BC4:
	ldr r0, _08068BD8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_08068BD0:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068BD8: .4byte gUnknown_80FE0AC
	thumb_func_end sub_8068A84

	thumb_func_start sub_8068BDC
sub_8068BDC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08068CC4
	add sp, r4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x220]
	movs r1, 0
	mov r0, sp
	adds r0, 0x39
_08068BF6:
	strb r1, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _08068BF6
	movs r6, 0
	ldr r0, _08068CC8
	mov r8, r0
	movs r7, 0x1
_08068C06:
	movs r0, 0x64
	muls r0, r6
	ldr r1, _08068CCC
	adds r0, r1
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r0
	ldrb r1, [r4]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08068C50
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A564
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _08068C50
	adds r4, 0x40
	ldrb r1, [r4]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08068C50
	ldrb r0, [r4, 0x2]
	cmp r0, 0x69
	bne _08068C50
	adds r0, r4, 0
	bl GetMoneyValue
	bl AddToTeamMoney
	strb r5, [r4, 0x2]
	strb r5, [r4, 0x1]
	strb r5, [r4]
_08068C50:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068C06
	movs r6, 0
	movs r5, 0x1
_08068C5A:
	ldr r1, _08068CC8
	movs r0, 0x64
	muls r0, r6
	ldr r2, _08068CCC
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r1, [r4]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08068CFE
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A564
	lsls r0, 24
	cmp r0, 0
	bne _08068CFE
	ldr r1, _08068CD0
	adds r0, r1, 0
	ldrh r2, [r4, 0xE]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _08068C96
	movs r0, 0xBC
	lsls r0, 1
	strh r0, [r4, 0xE]
_08068C96:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _08068CE8
	ldr r0, _08068CD4
	ldr r0, [r0]
	ldr r1, _08068CD8
	adds r0, r1
	ldrb r0, [r0]
	bl GetLevelCondition
	lsls r0, 24
	cmp r0, 0
	beq _08068CDC
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r1, r4, 0
	bl sub_808DFDC
	b _08068CFE
	.align 2, 0
_08068CC4: .4byte 0xfffffdd8
_08068CC8: .4byte gRecruitedPokemonRef
_08068CCC: .4byte 0x00008df8
_08068CD0: .4byte 0xfffffe87
_08068CD4: .4byte gDungeonGlobalData
_08068CD8: .4byte 0x00000644
_08068CDC:
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	adds r1, r4, 0
	bl xxx_pokemon2_to_pokemonstruct_index_808DF2C
	b _08068CFE
_08068CE8:
	ldr r0, [sp, 0x220]
	cmp r0, 0
	beq _08068CFE
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	add r0, sp
	strb r5, [r0]
_08068CFE:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068C5A
	movs r1, 0
_08068D06:
	lsls r0, r1, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, sp
	add r0, r8
	ldrb r0, [r0]
	adds r1, 0x1
	str r1, [sp, 0x224]
	cmp r0, 0
	bne _08068D1C
	b _08068F08
_08068D1C:
	mov r0, r8
	add r1, sp, 0x1F0
	movs r2, 0x1
	movs r3, 0x1
	bl sub_8092404
	mov r0, r8
	add r1, sp, 0x214
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	movs r7, 0
	add r1, sp, 0x1F0
	ldrh r0, [r1]
	ldr r2, _08068E10
	cmp r0, r2
	beq _08068D60
	ldr r0, _08068E14
	ldr r3, [r0]
	adds r5, r2, 0
	add r2, sp, 0x3C
	movs r4, 0x58
_08068D4A:
	ldrh r0, [r1]
	muls r0, r4
	adds r0, r3, r0
	stm r2!, {r0}
	adds r1, 0x2
	adds r7, 0x1
	cmp r7, 0x14
	bgt _08068D60
	ldrh r0, [r1]
	cmp r0, r5
	bne _08068D4A
_08068D60:
	movs r6, 0
	ldr r2, _08068E14
	mov r10, r2
	movs r3, 0
	mov r9, r3
_08068D6A:
	movs r0, 0x64
	muls r0, r6
	ldr r1, _08068E18
	adds r0, r1
	mov r2, r10
	ldr r1, [r2]
	adds r5, r1, r0
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068DD6
	movs r3, 0xA
	ldrsh r0, [r5, r3]
	bl sub_806A5A4
	lsls r0, 24
	cmp r0, 0
	beq _08068DD6
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r8
	bne _08068DD6
	ldr r2, [sp, 0x220]
	cmp r2, 0
	beq _08068DD6
	add r4, sp, 0x3C
	lsls r0, r7, 2
	adds r4, r0
	add r0, sp, 0x90
	movs r1, 0x58
	muls r1, r6
	adds r0, r1
	str r0, [r4]
	adds r1, r5, 0
	bl xxx_pokemon2_to_pokemonstruct_808DF44
	ldr r2, [r4]
	ldrh r0, [r2]
	movs r3, 0x80
	lsls r3, 7
	adds r1, r3, 0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, [r4]
	mov r1, r9
	strb r1, [r0, 0xC]
	ldr r0, [r4]
	strb r1, [r0, 0x10]
	adds r7, 0x1
_08068DD6:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068D6A
	add r0, sp, 0x214
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bgt _08068E1C
	cmp r7, 0
	bgt _08068DEC
	b _08068F08
_08068DEC:
	add r5, sp, 0x3C
	movs r3, 0x80
	lsls r3, 7
	adds r6, r3, 0
	adds r4, r7, 0
_08068DF6:
	ldr r1, [r5]
	ldrh r0, [r1]
	ands r0, r6
	cmp r0, 0
	beq _08068E06
	adds r0, r1, 0
	bl sub_808D1DC
_08068E06:
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bne _08068DF6
	b _08068F08
	.align 2, 0
_08068E10: .4byte 0x0000ffff
_08068E14: .4byte gRecruitedPokemonRef
_08068E18: .4byte 0x00008df8
_08068E1C:
	ldr r0, _08068E78
	mov r1, r8
	movs r2, 0
	bl sub_8092578
	ldr r0, _08068E7C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	add r4, sp, 0x3C
_08068E34:
	add r0, sp, 0x214
	movs r2, 0
	ldrsh r1, [r0, r2]
	subs r1, r7, r1
	mov r0, r8
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_8067A80
	movs r6, 0
	cmp r6, r7
	bge _08068E8E
	movs r5, 0x80
	lsls r5, 8
	adds r3, r4, 0
_08068E52:
	ldr r2, [r3]
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068E86
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08068E86
	ldrb r0, [r2, 0x4]
	subs r0, 0x44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08068E80
	movs r0, 0x1
	b _08068E82
	.align 2, 0
_08068E78: .4byte gUnknown_202DE58
_08068E7C: .4byte gUnknown_80FE1A4
_08068E80:
	movs r0, 0
_08068E82:
	cmp r0, 0
	bne _08068E8E
_08068E86:
	adds r3, 0x4
	adds r6, 0x1
	cmp r6, r7
	blt _08068E52
_08068E8E:
	cmp r6, r7
	beq _08068EA2
	ldr r0, _08068F24
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _08068E34
_08068EA2:
	cmp r7, 0
	ble _08068ED4
	movs r3, 0x80
	lsls r3, 8
	mov r9, r3
	adds r3, r4, 0
	movs r0, 0x1
	mov r8, r0
	movs r5, 0
	adds r6, r7, 0
_08068EB6:
	ldr r2, [r3]
	ldrh r1, [r2]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _08068ECC
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _08068ECC
	strh r5, [r2]
_08068ECC:
	adds r3, 0x4
	subs r6, 0x1
	cmp r6, 0
	bne _08068EB6
_08068ED4:
	cmp r7, 0
	ble _08068F08
	movs r1, 0x80
	lsls r1, 7
	adds r5, r1, 0
	adds r6, r7, 0
_08068EE0:
	ldr r2, [r4]
	ldrh r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068F00
	adds r0, r1, 0
	ands r0, r5
	cmp r0, 0
	beq _08068F00
	adds r0, r2, 0
	bl sub_808D1DC
	ldr r1, [r4]
	movs r0, 0
	strh r0, [r1]
_08068F00:
	adds r4, 0x4
	subs r6, 0x1
	cmp r6, 0
	bne _08068EE0
_08068F08:
	ldr r1, [sp, 0x224]
	cmp r1, 0x39
	bgt _08068F10
	b _08068D06
_08068F10:
	movs r3, 0x8A
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068F24: .4byte gUnknown_80FE20C
	thumb_func_end sub_8068BDC

	thumb_func_start sub_8068F28
sub_8068F28:
	push {r4-r7,lr}
	movs r6, 0
	ldr r7, _08068F5C
_08068F2E:
	movs r0, 0x64
	muls r0, r6
	ldr r1, _08068F60
	adds r0, r1
	ldr r1, [r7]
	adds r4, r1, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08068F74
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	bl sub_806A564
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _08068F64
	movs r0, 0
	strh r0, [r4]
	b _08068F74
	.align 2, 0
_08068F5C: .4byte gRecruitedPokemonRef
_08068F60: .4byte 0x00008df8
_08068F64:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	bl sub_806A538
	lsls r0, 24
	cmp r0, 0
	beq _08068F74
	strh r5, [r4]
_08068F74:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08068F2E
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8068F28

	thumb_func_start sub_8068F80
sub_8068F80:
	push {r4,r5,lr}
	bl sub_8083600
	adds r5, r0, 0
	ldr r0, _08068FD4
	ldr r4, [r0]
	ldr r1, _08068FD8
	adds r0, r4, r1
	movs r1, 0
	strb r1, [r0]
	ldr r2, _08068FDC
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, 0x6
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, 0
	adds r0, 0xC0
	str r1, [r0]
	cmp r5, 0
	beq _08068FCC
	adds r0, r5, 0
	bl sub_8045128
	ldrh r0, [r0]
	lsrs r0, 5
	movs r1, 0x1
	ands r0, r1
	movs r2, 0xD3
	lsls r2, 3
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, 0x1
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r5, 0x4
	bl sub_804AC20
_08068FCC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068FD4: .4byte gDungeonGlobalData
_08068FD8: .4byte 0x0000066c
_08068FDC: .4byte 0x0000066d
	thumb_func_end sub_8068F80

	thumb_func_start sub_8068FE0
sub_8068FE0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x84
	mov r8, r0
	str r2, [sp, 0x74]
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	ldr r7, [r0, 0x70]
	bl sub_8045128
	adds r4, r0, 0
	ldr r0, [sp, 0x74]
	cmp r0, 0
	bne _0806900E
	mov r0, sp
	bl sub_80457DC
	mov r1, sp
	str r1, [sp, 0x74]
_0806900E:
	ldr r0, [r4, 0x10]
	cmp r0, r8
	bne _08069018
	movs r0, 0
	str r0, [r4, 0x10]
_08069018:
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	movs r3, 0x6
	ldrsh r1, [r2, r3]
	bl sub_80402AC
	movs r5, 0
	adds r6, r7, 0
	adds r6, 0xC8
	movs r0, 0xB0
	adds r0, r7
	mov r10, r0
	mov r1, r8
	adds r1, 0x22
	str r1, [sp, 0x80]
	mov r2, r8
	adds r2, 0x20
	str r2, [sp, 0x7C]
	adds r3, r7, 0
	adds r3, 0x40
	str r3, [sp, 0x78]
_08069044:
	ldr r0, _080690E4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _080690E8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _08069072
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08069072
	ldr r0, [r4, 0x70]
	adds r1, r0, 0
	adds r1, 0x80
	ldr r0, [r1]
	cmp r0, r8
	bne _08069072
	movs r0, 0
	str r0, [r1]
_08069072:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08069044
	ldrb r0, [r6]
	cmp r0, 0x2
	bne _0806908A
	ldr r0, _080690E4
	ldr r0, [r0]
	ldr r3, _080690EC
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
_0806908A:
	mov r1, r10
	ldrb r0, [r1]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080690A2
	adds r0, r7, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_080690A2:
	mov r0, r8
	bl sub_8078084
	movs r0, 0
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	ldr r3, [sp, 0x7C]
	strb r0, [r3]
	ldr r1, _080690F0
	str r0, [r1]
	ldr r1, [sp, 0x78]
	ldrb r0, [r1]
	cmp r0, 0x41
	bne _080690FC
	ldr r3, _080690E4
	ldr r2, [r3]
	ldr r1, _080690F4
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, 0
	bne _080690FC
	movs r0, 0x1
	strb r0, [r2, 0x10]
	strh r1, [r7, 0xE]
	ldr r0, [r3]
	ldr r2, _080690F8
	adds r0, r2
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	b _08069484
	.align 2, 0
_080690E4: .4byte gDungeonGlobalData
_080690E8: .4byte 0x000135cc
_080690EC: .4byte 0x000037fc
_080690F0: .4byte gUnknown_203B450
_080690F4: .4byte 0x0000065c
_080690F8: .4byte 0x000005f4
_080690FC:
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _08069104
	b _0806928E
_08069104:
	movs r0, 0x3C
	movs r1, 0x49
	bl sub_803E708
	bl sub_80532B4
	ldr r5, _08069198
	ldr r2, [r5]
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	bne _080691C8
	ldr r3, _0806919C
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _080691E0
	movs r0, 0x87
	lsls r0, 2
	cmp r9, r0
	beq _080691E0
	adds r0, 0x6
	cmp r9, r0
	beq _080691E0
	subs r0, 0x4
	cmp r9, r0
	beq _080691E0
	ldr r1, _080691A0
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080691E0
	ldr r6, _080691A4
	adds r0, r2, r6
	movs r1, 0
	ldrsb r1, [r0, r1]
	cmp r1, 0
	blt _080691E0
	adds r3, 0xA
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080691E0
	cmp r1, 0
	ble _080691B4
	ldr r0, _080691A8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	adds r4, r0, 0
	cmp r4, 0x1
	bne _080691E0
	ldr r0, _080691AC
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	ldr r0, [r5]
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	strb r4, [r0, 0x6]
	ldr r0, [r5]
	ldr r1, _080691B0
	adds r0, r1
	strb r4, [r0]
	ldr r1, [r5]
	adds r1, r6
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	b _08069484
	.align 2, 0
_08069198: .4byte gDungeonGlobalData
_0806919C: .4byte 0x0000066e
_080691A0: .4byte 0x00003a0d
_080691A4: .4byte 0x0000067b
_080691A8: .4byte gUnknown_80FE268
_080691AC: .4byte gUnknown_80FE28C
_080691B0: .4byte 0x00000654
_080691B4:
	ldr r0, _080691C4
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
	b _080691E0
	.align 2, 0
_080691C4: .4byte gUnknown_80FE2D0
_080691C8:
	movs r1, 0x1
	strb r1, [r2, 0x4]
	ldr r0, [r5]
	strb r1, [r0, 0x6]
	ldr r0, [r5]
	ldr r2, _080691DC
	adds r0, r2
	strb r1, [r0]
	b _08069484
	.align 2, 0
_080691DC: .4byte 0x00000654
_080691E0:
	mov r0, r9
	ldr r1, [sp, 0x74]
	mov r2, r8
	bl sub_8083AB0
	ldr r0, _080691F8
	cmp r9, r0
	bne _0806928E
	movs r6, 0
	movs r5, 0
	b _080691FE
	.align 2, 0
_080691F8: .4byte 0x0000021f
_080691FC:
	adds r5, 0x1
_080691FE:
	cmp r5, 0x3
	bgt _08069228
	ldr r0, _080692C4
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r3, _080692C8
	adds r0, r3
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080691FC
	ldr r6, [r4, 0x70]
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x41
	bne _080691FC
_08069228:
	cmp r6, 0
	beq _0806928E
	ldr r5, _080692CC
	ldrb r0, [r6, 0xA]
	movs r1, 0x64
	muls r1, r0
	ldr r2, _080692D0
	adds r1, r2
	ldr r2, [r5]
	adds r4, r2, r1
	adds r1, r6, 0
	bl sub_806C264
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _0806928A
	ldr r0, _080692C4
	ldr r0, [r0]
	ldr r1, _080692D4
	adds r0, r1
	ldrb r0, [r0]
	bl GetLevelCondition
	lsls r0, 24
	cmp r0, 0
	bne _0806926E
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r1, r4, 0
	bl xxx_pokemon2_to_pokemonstruct_index_808DF2C
_0806926E:
	bl sub_8044210
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0806928A
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	movs r0, 0x58
	muls r0, r1
	ldr r1, [r5]
	adds r0, r1
	adds r0, 0x28
	strb r2, [r0]
_0806928A:
	movs r0, 0
	strh r0, [r4]
_0806928E:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _080692DC
	movs r5, 0
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r7, r1
	movs r2, 0x98
	adds r2, r7
	mov r10, r2
	ldrb r3, [r0]
	cmp r5, r3
	bge _0806930A
	ldr r4, _080692D8
	subs r1, 0x1
	adds r2, r7, r1
	movs r3, 0
	adds r1, r0, 0
_080692B2:
	ldrb r0, [r2]
	adds r0, r5
	adds r0, r4
	strb r3, [r0]
	adds r5, 0x1
	ldrb r0, [r1]
	cmp r5, r0
	blt _080692B2
	b _0806930A
	.align 2, 0
_080692C4: .4byte gDungeonGlobalData
_080692C8: .4byte 0x0001357c
_080692CC: .4byte gRecruitedPokemonRef
_080692D0: .4byte 0x00008df8
_080692D4: .4byte 0x00000644
_080692D8: .4byte gUnknown_202EE76
_080692DC:
	movs r5, 0
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r7, r1
	movs r2, 0x98
	adds r2, r7
	mov r10, r2
	ldrb r3, [r0]
	cmp r5, r3
	bge _0806930A
	ldr r4, _0806932C
	subs r1, 0x1
	adds r2, r7, r1
	movs r3, 0
	adds r1, r0, 0
_080692FA:
	ldrb r0, [r2]
	adds r0, r5
	adds r0, r4
	strb r3, [r0]
	adds r5, 0x1
	ldrb r0, [r1]
	cmp r5, r0
	blt _080692FA
_0806930A:
	ldr r1, [sp, 0x78]
	ldrb r0, [r1]
	cmp r0, 0x4A
	bne _08069338
	ldr r2, _08069330
	ldr r1, [r2]
	movs r0, 0x2
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	ldr r2, _08069334
	adds r0, r2
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	b _08069352
	.align 2, 0
_0806932C: .4byte gUnknown_202EE70
_08069330: .4byte gDungeonGlobalData
_08069334: .4byte 0x000005f4
_08069338:
	cmp r0, 0x47
	bne _08069352
	ldr r2, _08069494
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	ldr r3, _08069498
	adds r0, r3
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
_08069352:
	bl sub_8083600
	cmp r0, 0
	beq _080693C6
	movs r0, 0x87
	lsls r0, 2
	cmp r9, r0
	beq _080693C6
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _080693C6
	ldr r4, _08069494
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _080693C6
	adds r0, r7, 0
	adds r0, 0xA4
	ldrb r1, [r0]
	movs r2, 0
	movs r0, 0xFA
	lsls r0, 1
	cmp r9, r0
	bne _08069384
	movs r2, 0x1
_08069384:
	mov r0, r8
	bl sub_8084E00
	ldr r1, _0806949C
	adds r0, r1, 0
	ldrh r2, [r7, 0x4]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _080693C6
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	bne _080693C6
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	beq _080693CC
	ldr r0, [r4]
	ldr r3, _080694A0
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, _080694A4
	ldr r1, [r0]
	mov r0, r8
	bl sub_805239C
	bl sub_803E178
	bl sub_8049ED4
_080693C6:
	ldrb r0, [r7, 0x6]
	cmp r0, 0
	bne _08069466
_080693CC:
	ldr r6, _080694A8
	ldrb r0, [r7, 0xA]
	movs r1, 0x64
	muls r1, r0
	ldr r2, _080694AC
	adds r1, r2
	ldr r2, [r6]
	adds r4, r2, r1
	adds r1, r7, 0
	bl sub_806C264
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _08069462
	ldr r5, _08069494
	ldr r0, [r5]
	ldr r1, _080694B0
	adds r0, r1
	ldrb r0, [r0]
	bl GetLevelCondition
	lsls r0, 24
	cmp r0, 0
	bne _0806940E
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	adds r1, r4, 0
	bl xxx_pokemon2_to_pokemonstruct_index_808DF2C
_0806940E:
	bl sub_8044210
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	bne _0806942A
	movs r3, 0xA
	ldrsh r1, [r4, r3]
	movs r0, 0x58
	muls r0, r1
	ldr r1, [r6]
	adds r0, r1
	adds r0, 0x28
	strb r2, [r0]
_0806942A:
	ldrb r1, [r7, 0x7]
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
	ldr r0, [r5]
	ldr r2, _080694B4
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _08069448
	ldr r3, [sp, 0x78]
	ldrb r0, [r3]
	cmp r0, 0x41
	bne _08069448
	movs r1, 0x1
_08069448:
	cmp r1, 0
	bne _08069462
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0x58
	muls r1, r0
	ldr r0, _080694A8
	ldr r0, [r0]
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, _080694B8
	ands r0, r2
	strh r0, [r1]
_08069462:
	movs r0, 0
	strh r0, [r4]
_08069466:
	mov r1, r10
	ldr r0, [r1]
	bl sub_800F934
	ldr r0, _080694BC
	movs r2, 0
	str r2, [r0]
	ldr r0, _08069494
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xC]
	mov r3, r8
	str r2, [r3]
	bl sub_8045ACC
_08069484:
	add sp, 0x84
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069494: .4byte gDungeonGlobalData
_08069498: .4byte 0x000005f4
_0806949C: .4byte 0xfffffe5f
_080694A0: .4byte 0x000037fe
_080694A4: .4byte gUnknown_80FA580
_080694A8: .4byte gRecruitedPokemonRef
_080694AC: .4byte 0x00008df8
_080694B0: .4byte 0x00000644
_080694B4: .4byte 0x0000065c
_080694B8: .4byte 0x0000fffd
_080694BC: .4byte gUnknown_203B450
	thumb_func_end sub_8068FE0

	thumb_func_start sub_80694C0
sub_80694C0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	adds r7, r1, 0
	mov r8, r2
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	adds r0, r7, 0
	mov r1, r8
	bl sub_8049590
	mov r10, r0
	ldr r5, [r4, 0x70]
	adds r6, r5, 0
	adds r6, 0xB0
	ldrb r0, [r6]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _080694FC
	adds r0, r5, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_080694FC:
	ldrb r0, [r6]
	cmp r0, 0x7
	beq _0806950A
	cmp r0, 0x5
	beq _0806950A
	cmp r0, 0x2
	bne _08069512
_0806950A:
	adds r0, r4, 0
	adds r1, r4, 0
	bl SendImmobilizeEndMessage
_08069512:
	movs r0, 0x4
	ldrsh r2, [r4, r0]
	cmp r7, r2
	bne _08069522
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r8, r0
	beq _080695DE
_08069522:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08069552
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r0, 0
	blt _08069552
	adds r1, r0, 0
	adds r0, r2, 0
	bl sub_8049590
	adds r1, r0, 0
	ldr r0, [r1, 0x10]
	cmp r0, r4
	bne _08069546
	movs r0, 0
	str r0, [r1, 0x10]
_08069546:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	movs r2, 0x6
	ldrsh r1, [r4, r2]
	bl sub_80402AC
_08069552:
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	strh r0, [r4, 0xA]
	strh r7, [r4, 0x4]
	mov r0, r8
	strh r0, [r4, 0x6]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0806956E
	ldr r0, _0806959C
	strh r7, [r0]
	mov r1, r8
	strh r1, [r0, 0x2]
_0806956E:
	mov r2, r10
	str r4, [r2, 0x10]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08069588
	ldr r0, _080695A0
	strh r7, [r0]
	mov r1, r8
	strh r1, [r0, 0x2]
	ldr r0, _080695A4
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x1]
_08069588:
	adds r0, r7, 0
	mov r1, r8
	bl sub_80402AC
	mov r2, r9
	cmp r2, 0
	beq _080695A8
	cmp r2, 0x1
	beq _080695C4
	b _080695CE
	.align 2, 0
_0806959C: .4byte gUnknown_203B410
_080695A0: .4byte gUnknown_202EE0C
_080695A4: .4byte gDungeonGlobalData
_080695A8:
	ldr r0, [r5, 0x70]
	str r0, [r5, 0x74]
	ldr r0, [r5, 0x6C]
	str r0, [r5, 0x70]
	ldr r0, [r5, 0x68]
	str r0, [r5, 0x6C]
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080695CE
	ldr r0, [r4, 0x8]
	str r0, [r5, 0x68]
	b _080695CE
_080695C4:
	ldr r0, [r4, 0x4]
	str r0, [r5, 0x68]
	str r0, [r5, 0x6C]
	str r0, [r5, 0x70]
	str r0, [r5, 0x74]
_080695CE:
	mov r1, r10
	ldrb r0, [r1, 0x9]
	adds r1, r4, 0
	adds r1, 0x25
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_806CF98
_080695DE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80694C0

	thumb_func_start sub_80695EC
sub_80695EC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	ldr r1, [r4, 0x70]
	adds r5, r1, 0
	adds r0, r1, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08069612
	adds r0, r1, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_08069612:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r6, r0
	bne _08069622
	movs r1, 0x6
	ldrsh r0, [r4, r1]
	cmp r7, r0
	beq _08069658
_08069622:
	ldrh r0, [r4, 0x4]
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	strh r0, [r4, 0xA]
	strh r6, [r4, 0x4]
	strh r7, [r4, 0x6]
	ldr r0, [r5, 0x70]
	str r0, [r5, 0x74]
	ldr r0, [r5, 0x6C]
	str r0, [r5, 0x70]
	ldr r0, [r5, 0x68]
	str r0, [r5, 0x6C]
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08069648
	ldr r0, [r4, 0x8]
	str r0, [r5, 0x68]
_08069648:
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_804954C
	ldrb r1, [r0, 0x9]
	adds r0, r4, 0
	adds r0, 0x25
	strb r1, [r0]
_08069658:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80695EC

	thumb_func_start sub_8069660
sub_8069660:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	adds r5, r0, 0
	adds r5, 0x46
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_8070F80
	lsls r0, 24
	cmp r0, 0
	bne _0806967C
	movs r0, 0
	b _0806969E
_0806967C:
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, _080696A4
	ldrb r2, [r5]
	lsls r2, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl sub_804954C
	ldr r0, [r0, 0x10]
_0806969E:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080696A4: .4byte gUnknown_80F4448
	thumb_func_end sub_8069660

	thumb_func_start sub_80696A8
sub_80696A8:
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	adds r5, r0, 0
	adds r5, 0x46
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_8071138
	lsls r0, 24
	cmp r0, 0
	beq _080696F4
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	ldr r1, _080696F0
	ldrb r2, [r5]
	lsls r2, 2
	adds r2, r1
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r1
	movs r3, 0x6
	ldrsh r1, [r4, r3]
	movs r3, 0x2
	ldrsh r2, [r2, r3]
	adds r1, r2
	bl sub_804954C
	ldr r1, [r0, 0x10]
	cmp r1, 0
	beq _080696F4
	ldr r0, [r1]
	cmp r0, 0x1
	bne _080696F4
	adds r0, r1, 0
	b _080696F6
	.align 2, 0
_080696F0: .4byte gUnknown_80F4448
_080696F4:
	movs r0, 0
_080696F6:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80696A8

	thumb_func_start sub_80696FC
sub_80696FC:
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r3, [r4, 0x70]
	ldr r5, _08069764
	adds r3, 0x46
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08069768
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r5
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x6]
	adds r0, r1
	lsls r0, 16
	ldr r1, _0806976C
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 16
	bl sub_804954C
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, sp
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	bne _08069770
	ldr r1, [r5, 0x10]
	cmp r1, 0
	beq _08069770
	ldr r0, [r1]
	cmp r0, 0x1
	bne _08069770
	adds r0, r1, 0
	b _08069772
	.align 2, 0
_08069764: .4byte gUnknown_80F4448
_08069768: .4byte 0xffff0000
_0806976C: .4byte 0x0000ffff
_08069770:
	movs r0, 0
_08069772:
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80696FC

	thumb_func_start sub_806977C
sub_806977C:
	push {r4-r7,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, [r4, 0x70]
	ldr r7, _0806982C
	adds r5, r0, 0
	adds r5, 0x46
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	ldrh r0, [r0]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r1, _08069830
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	ldrh r0, [r0, 0x2]
	ldrh r1, [r4, 0x6]
	adds r0, r1
	lsls r0, 16
	ldr r1, _08069834
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	ldrsh r0, [r0, r2]
	asrs r1, 16
	bl sub_804954C
	mov r6, sp
	adds r0, r4, 0
	mov r1, sp
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	bne _08069838
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	movs r1, 0
	ldrsh r0, [r0, r1]
	lsls r0, 1
	ldrh r2, [r4, 0x4]
	adds r0, r2
	mov r1, sp
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	lsls r0, 1
	ldrh r2, [r4, 0x6]
	adds r0, r2
	strh r0, [r6, 0x2]
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl sub_804954C
	adds r5, r0, 0
	adds r0, r4, 0
	mov r1, sp
	bl sub_80705F0
	lsls r0, 24
	cmp r0, 0
	bne _08069838
	ldr r1, [r5, 0x10]
	cmp r1, 0
	beq _08069838
	ldr r0, [r1]
	cmp r0, 0x1
	bne _08069838
	adds r0, r1, 0
	b _0806983A
	.align 2, 0
_0806982C: .4byte gUnknown_80F4448
_08069830: .4byte 0xffff0000
_08069834: .4byte 0x0000ffff
_08069838:
	movs r0, 0
_0806983A:
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806977C

	thumb_func_start sub_8069844
sub_8069844:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r5, [r1, 0x70]
	adds r0, r6, 0x2
	adds r1, r5, 0
	movs r2, 0
	bl sub_80708B4
	ldrh r0, [r5, 0x2]
	strh r0, [r6]
	movs r1, 0xE
	ldrsh r0, [r5, r1]
	str r0, [r6, 0x24]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	str r0, [r6, 0x28]
	ldrb r0, [r5, 0x9]
	str r0, [r6, 0x2C]
	ldr r0, [r5, 0x18]
	str r0, [r6, 0x30]
	movs r2, 0
_08069874:
	adds r1, r6, 0
	adds r1, 0x34
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x14
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x36
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x16
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x16
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x5C
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x18
	adds r1, r2
	adds r0, r5, 0
	adds r0, 0x5E
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x1
	ble _08069874
	ldrb r2, [r5, 0x7]
	adds r1, r6, 0
	adds r1, 0x38
	movs r0, 0
	strb r2, [r1]
	adds r2, r6, 0
	adds r2, 0x39
	strb r0, [r2]
	adds r3, r6, 0
	adds r3, 0x3A
	strb r0, [r3]
	adds r4, r6, 0
	adds r4, 0x3B
	strb r0, [r4]
	movs r7, 0x3C
	adds r7, r6
	mov r12, r7
	strb r0, [r7]
	adds r0, r5, 0
	adds r0, 0x60
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806995C
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806995C
	adds r1, r5, 0
	adds r1, 0x62
	ldrb r0, [r1]
	cmp r0, 0x13
	bne _08069908
	ldr r0, _080699A4
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r0, r7
	strb r0, [r2]
_08069908:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08069918
	ldr r0, _080699A8
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r0, r7
	strb r0, [r2]
_08069918:
	ldrb r0, [r1]
	cmp r0, 0x21
	bne _08069928
	ldr r0, _080699AC
	ldrb r0, [r0]
	ldrb r2, [r3]
	adds r0, r2
	strb r0, [r3]
_08069928:
	ldrb r0, [r1]
	cmp r0, 0x2B
	bne _08069938
	ldr r0, _080699A8
	ldrb r0, [r0]
	ldrb r7, [r3]
	adds r0, r7
	strb r0, [r3]
_08069938:
	ldrb r0, [r1]
	cmp r0, 0x1E
	bne _08069948
	ldr r0, _080699B0
	ldrb r0, [r0]
	ldrb r2, [r4]
	adds r0, r2
	strb r0, [r4]
_08069948:
	ldrb r0, [r1]
	cmp r0, 0x22
	bne _0806995C
	ldr r0, _080699B4
	ldrb r0, [r0]
	mov r7, r12
	ldrb r7, [r7]
	adds r0, r7
	mov r1, r12
	strb r0, [r1]
_0806995C:
	adds r0, r5, 0
	adds r0, 0x94
	ldrb r1, [r0]
	adds r0, r6, 0
	adds r0, 0x54
	strb r1, [r0]
	ldr r0, [r5, 0x60]
	str r0, [r6, 0x20]
	ldrh r0, [r5, 0xC]
	movs r1, 0
	strh r0, [r6, 0x3E]
	ldr r0, [r5, 0x40]
	str r0, [r6, 0x1C]
	adds r0, r6, 0
	adds r0, 0x44
	strb r1, [r0]
	adds r0, 0x4
	strb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x8C
	ldr r0, [r0]
	str r0, [r6, 0x50]
	ldr r0, _080699B8
	ldr r0, [r0]
	ldr r2, _080699BC
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080699C0
	adds r0, r5, 0
	bl sub_806A4DC
	adds r1, r6, 0
	adds r1, 0x4C
	b _080699C6
	.align 2, 0
_080699A4: .4byte gUnknown_810AC60
_080699A8: .4byte gUnknown_810AC68
_080699AC: .4byte gUnknown_810AC62
_080699B0: .4byte gUnknown_810AC64
_080699B4: .4byte gUnknown_810AC66
_080699B8: .4byte gDungeonGlobalData
_080699BC: .4byte 0x0000065a
_080699C0:
	adds r1, r6, 0
	adds r1, 0x4C
	movs r0, 0x3
_080699C6:
	strb r0, [r1]
	movs r4, 0
	movs r7, 0x10
	ldrsh r0, [r5, r7]
	cmp r0, 0
	bge _080699D4
	adds r0, 0x3
_080699D4:
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	asrs r0, 2
	cmp r1, r0
	bgt _080699E8
	adds r1, r6, 0
	adds r1, 0x58
	movs r0, 0x6
	strb r0, [r1]
	movs r4, 0x1
_080699E8:
	ldr r0, _08069A24
	ldr r0, [r0]
	ldr r7, _08069A28
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069A02
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0xB
	strb r1, [r0]
	adds r4, 0x1
_08069A02:
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r5, r1
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0
	bne _08069A38
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _08069A2C
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x13
	b _08069A34
	.align 2, 0
_08069A24: .4byte gDungeonGlobalData
_08069A28: .4byte 0x00000676
_08069A2C:
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x3B
_08069A34:
	strb r1, [r0]
	adds r4, 0x1
_08069A38:
	mov r2, r8
	ldr r0, [r2, 0x70]
	movs r7, 0x82
	lsls r7, 1
	adds r2, r0, r7
	ldr r0, [r2]
	cmp r0, 0x1
	ble _08069A54
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x1B
	strb r1, [r0]
	adds r4, 0x1
_08069A54:
	ldr r0, [r2]
	cmp r0, 0
	bgt _08069A66
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x28
	strb r1, [r0]
	adds r4, 0x1
_08069A66:
	ldr r0, [r5, 0x2C]
	cmp r0, 0xFF
	ble _08069AAE
	ldr r0, [r5, 0x30]
	cmp r0, 0xFF
	ble _08069AAE
	ldr r0, [r5, 0x34]
	cmp r0, 0xFF
	ble _08069AAE
	ldr r0, [r5, 0x38]
	cmp r0, 0xFF
	ble _08069AAE
	movs r1, 0x1C
	ldrsh r0, [r5, r1]
	cmp r0, 0x9
	ble _08069AAE
	movs r2, 0x1E
	ldrsh r0, [r5, r2]
	cmp r0, 0x9
	ble _08069AAE
	movs r7, 0x20
	ldrsh r0, [r5, r7]
	cmp r0, 0x9
	ble _08069AAE
	movs r1, 0x22
	ldrsh r0, [r5, r1]
	cmp r0, 0x9
	ble _08069AAE
	movs r2, 0x24
	ldrsh r0, [r5, r2]
	cmp r0, 0x9
	ble _08069AAE
	movs r7, 0x26
	ldrsh r0, [r5, r7]
	cmp r0, 0x9
	bgt _08069ABA
_08069AAE:
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x37
	strb r1, [r0]
	adds r4, 0x1
_08069ABA:
	adds r0, r5, 0
	adds r0, 0xA8
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069AD2
	cmp r4, 0xB
	bgt _08069AD2
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	strb r1, [r0]
	adds r4, 0x1
_08069AD2:
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069AEC
	cmp r4, 0xB
	bgt _08069AEC
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x6
	strb r1, [r0]
	adds r4, 0x1
_08069AEC:
	adds r0, r5, 0
	adds r0, 0xB0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B06
	cmp r4, 0xB
	bgt _08069B06
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0xB
	strb r1, [r0]
	adds r4, 0x1
_08069B06:
	adds r0, r5, 0
	adds r0, 0xBC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B20
	cmp r4, 0xB
	bgt _08069B20
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x13
	strb r1, [r0]
	adds r4, 0x1
_08069B20:
	adds r0, r5, 0
	adds r0, 0xC0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B3A
	cmp r4, 0xB
	bgt _08069B3A
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x1B
	strb r1, [r0]
	adds r4, 0x1
_08069B3A:
	adds r0, r5, 0
	adds r0, 0xC4
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B54
	cmp r4, 0xB
	bgt _08069B54
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x28
	strb r1, [r0]
	adds r4, 0x1
_08069B54:
	adds r0, r5, 0
	adds r0, 0xC8
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B6E
	cmp r4, 0xB
	bgt _08069B6E
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x37
	strb r1, [r0]
	adds r4, 0x1
_08069B6E:
	adds r0, r5, 0
	adds r0, 0xD0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069B88
	cmp r4, 0xB
	bgt _08069B88
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x3B
	strb r1, [r0]
	adds r4, 0x1
_08069B88:
	adds r0, r5, 0
	adds r0, 0xDC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BA2
	cmp r4, 0xB
	bgt _08069BA2
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x3E
	strb r1, [r0]
	adds r4, 0x1
_08069BA2:
	adds r0, r5, 0
	adds r0, 0xE0
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BBC
	cmp r4, 0xB
	bgt _08069BBC
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x43
	strb r1, [r0]
	adds r4, 0x1
_08069BBC:
	adds r0, r5, 0
	adds r0, 0xE4
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BD6
	cmp r4, 0xB
	bgt _08069BD6
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x46
	strb r1, [r0]
	adds r4, 0x1
_08069BD6:
	adds r0, r5, 0
	adds r0, 0xE8
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069BF0
	cmp r4, 0xB
	bgt _08069BF0
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x4A
	strb r1, [r0]
	adds r4, 0x1
_08069BF0:
	adds r0, r5, 0
	adds r0, 0xEC
	ldrb r1, [r0]
	cmp r1, 0
	beq _08069C0A
	cmp r4, 0xB
	bgt _08069C0A
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	adds r1, 0x4E
	strb r1, [r0]
	adds r4, 0x1
_08069C0A:
	movs r1, 0x89
	lsls r1, 1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C26
	cmp r4, 0xB
	bgt _08069C26
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x50
	strb r1, [r0]
	adds r4, 0x1
_08069C26:
	adds r0, r5, 0
	adds r0, 0xF0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C40
	cmp r4, 0xB
	bgt _08069C40
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x51
	strb r1, [r0]
	adds r4, 0x1
_08069C40:
	adds r0, r5, 0
	adds r0, 0xF1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C5A
	cmp r4, 0xB
	bgt _08069C5A
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x52
	strb r1, [r0]
	adds r4, 0x1
_08069C5A:
	adds r0, r5, 0
	adds r0, 0xF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C74
	cmp r4, 0xB
	bgt _08069C74
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x53
	strb r1, [r0]
	adds r4, 0x1
_08069C74:
	adds r0, r5, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069C8E
	cmp r4, 0xB
	bgt _08069C8E
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x54
	strb r1, [r0]
	adds r4, 0x1
_08069C8E:
	mov r0, r8
	bl ShouldAvoidEnemies
	lsls r0, 24
	cmp r0, 0
	beq _08069CAA
	cmp r4, 0xB
	bgt _08069CAA
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x55
	strb r1, [r0]
	adds r4, 0x1
_08069CAA:
	adds r0, r5, 0
	adds r0, 0xFD
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069CC4
	cmp r4, 0xB
	bgt _08069CC4
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x56
	strb r1, [r0]
	adds r4, 0x1
_08069CC4:
	mov r0, r8
	movs r1, 0
	bl sub_8070828
	cmp r0, 0x1
	ble _08069CE0
	cmp r4, 0xB
	bgt _08069CE0
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x57
	strb r1, [r0]
	adds r4, 0x1
_08069CE0:
	adds r0, r5, 0
	adds r0, 0xF2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069CFA
	cmp r4, 0xB
	bgt _08069D0E
	adds r0, r6, 0
	adds r0, 0x58
	adds r0, r4
	movs r1, 0x58
	strb r1, [r0]
	adds r4, 0x1
_08069CFA:
	cmp r4, 0xB
	bgt _08069D0E
	adds r1, r6, 0
	adds r1, 0x58
	movs r2, 0
_08069D04:
	adds r0, r1, r4
	strb r2, [r0]
	adds r4, 0x1
	cmp r4, 0xB
	ble _08069D04
_08069D0E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8069844

	thumb_func_start sub_8069D18
sub_8069D18:
	push {r4,r5,lr}
	ldr r3, [r1, 0x70]
	ldr r4, _08069D48
	adds r3, 0x46
	ldrb r2, [r3]
	lsls r2, 2
	adds r2, r4
	ldrh r2, [r2]
	ldrh r5, [r1, 0x4]
	adds r2, r5
	strh r2, [r0]
	ldrb r2, [r3]
	lsls r2, 2
	adds r2, r4
	ldrh r2, [r2, 0x2]
	ldrh r1, [r1, 0x6]
	adds r2, r1
	strh r2, [r0, 0x2]
	ldrb r1, [r3]
	movs r0, 0x1
	ands r0, r1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08069D48: .4byte gUnknown_80F4448
	thumb_func_end sub_8069D18

	thumb_func_start sub_8069D4C
sub_8069D4C:
	push {r4-r6,lr}
	sub sp, 0xC
	adds r5, r0, 0
	ldr r4, [r1, 0x70]
	ldrh r0, [r4, 0x2]
	strh r0, [r5]
	ldr r0, [r1, 0x4]
	str r0, [r5, 0x4]
	adds r0, r4, 0
	adds r0, 0xF7
	ldrb r0, [r0]
	cmp r0, 0
	beq _08069D6A
	ldrh r0, [r4, 0x12]
	b _08069D6C
_08069D6A:
	ldrh r0, [r4, 0x10]
_08069D6C:
	strh r0, [r5, 0x8]
	ldrb r0, [r4, 0x9]
	strh r0, [r5, 0xE]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldrb r2, [r4, 0x9]
	mov r0, sp
	bl GetPokemonLevelData
	ldr r0, [sp]
	str r0, [r5, 0x10]
	ldrb r0, [r4, 0x14]
	strb r0, [r5, 0xA]
	ldrb r0, [r4, 0x15]
	strb r0, [r5, 0xB]
	ldrb r0, [r4, 0x16]
	strb r0, [r5, 0xC]
	ldrb r0, [r4, 0x17]
	strb r0, [r5, 0xD]
	ldr r0, [r4, 0x60]
	str r0, [r5, 0x1C]
	adds r1, r5, 0
	adds r1, 0x20
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r4, r2
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	movs r3, 0x9E
	lsls r3, 1
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [r5, 0x14]
	movs r6, 0xA0
	lsls r6, 1
	adds r0, r4, r6
	ldr r0, [r0]
	str r0, [r5, 0x18]
	ldr r0, [r4, 0x3C]
	str r0, [r5, 0x44]
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8069D4C

	thumb_func_start sub_8069DCC
sub_8069DCC:
	push {r4,lr}
	ldr r1, [r0, 0x70]
	mov r12, r1
	ldr r3, _08069E08
	mov r4, r12
	adds r4, 0x46
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r3
	ldrh r1, [r1]
	ldrh r2, [r0, 0x4]
	adds r1, r2
	movs r2, 0xB6
	lsls r2, 1
	add r2, r12
	strh r1, [r2]
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r3
	ldrh r1, [r1, 0x2]
	ldrh r0, [r0, 0x6]
	adds r1, r0
	movs r0, 0xB7
	lsls r0, 1
	add r0, r12
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069E08: .4byte gUnknown_80F4448
	thumb_func_end sub_8069DCC

	thumb_func_start sub_8069E0C
sub_8069E0C:
	push {r4-r7,lr}
	adds r4, r0, 0
	ldr r5, [r4, 0x70]
	movs r1, 0x25
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08069E44
	adds r0, r4, 0
	bl sub_807E580
	ldr r1, _08069E40
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x5C
	movs r2, 0
	strb r1, [r0]
	adds r0, 0x1
	strb r2, [r0]
	adds r6, r5, 0
	adds r6, 0x5E
	b _08069E62
	.align 2, 0
_08069E40: .4byte gUnknown_80F520C
_08069E44:
	movs r4, 0
	adds r7, r5, 0
	adds r7, 0x5C
	adds r6, r5, 0
	adds r6, 0x5E
_08069E4E:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	bl GetPokemonType
	adds r1, r7, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x1
	ble _08069E4E
_08069E62:
	movs r4, 0
_08069E64:
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	adds r1, r4, 0
	bl GetPokemonAbility
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x1
	ble _08069E64
	ldr r0, _08069E88
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xC]
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069E88: .4byte gDungeonGlobalData
	thumb_func_end sub_8069E0C

	thumb_func_start sub_8069E8C
sub_8069E8C:
	push {r4-r7,lr}
	ldr r3, _08069ED8
	ldr r2, [r3]
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	beq _08069F44
	movs r1, 0
	strb r1, [r2, 0xC]
	ldr r0, [r3]
	ldr r2, _08069EDC
	adds r0, r2
	strb r1, [r0]
	movs r7, 0
	adds r5, r3, 0
	movs r6, 0x1
_08069EAA:
	ldr r0, [r5]
	lsls r1, r7, 2
	ldr r2, _08069EE0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08069F3E
	adds r0, r4, 0
	movs r1, 0x4
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08069EE8
	ldr r0, [r5]
	ldr r1, _08069EE4
	b _08069F16
	.align 2, 0
_08069ED8: .4byte gDungeonGlobalData
_08069EDC: .4byte 0x0000e279
_08069EE0: .4byte 0x000135cc
_08069EE4: .4byte 0x0000e273
_08069EE8:
	adds r0, r4, 0
	movs r1, 0x1C
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08069F04
	ldr r0, [r5]
	ldr r2, _08069F00
	adds r0, r2
	b _08069F18
	.align 2, 0
_08069F00: .4byte 0x0000e271
_08069F04:
	adds r0, r4, 0
	movs r1, 0x31
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08069F1A
	ldr r0, [r5]
	ldr r1, _08069F4C
_08069F16:
	adds r0, r1
_08069F18:
	strb r6, [r0]
_08069F1A:
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _08069F36
	adds r0, r4, 0
	movs r1, 0x2D
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08069F3E
_08069F36:
	ldr r0, [r5]
	ldr r2, _08069F50
	adds r0, r2
	strb r6, [r0]
_08069F3E:
	adds r7, 0x1
	cmp r7, 0x13
	ble _08069EAA
_08069F44:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069F4C: .4byte 0x0000e270
_08069F50: .4byte 0x0000e279
	thumb_func_end sub_8069E8C

	thumb_func_start sub_8069F54
sub_8069F54:
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	asrs r0, r1, 16
	ldr r2, _08069F88
	adds r1, r2
	lsrs r1, 16
	cmp r1, 0x3
	bhi _08069F94
	adds r0, r5, 0
	movs r1, 0x25
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _08069F90
	ldr r4, _08069F8C
	adds r0, r5, 0
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	b _08069F94
	.align 2, 0
_08069F88: .4byte 0xfe880000
_08069F8C: .4byte gUnknown_80F520C
_08069F90:
	movs r0, 0xBC
	lsls r0, 1
_08069F94:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8069F54

	thumb_func_start sub_8069F9C
sub_8069F9C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	mov r8, r0
	adds r6, r1, 0
	mov r9, r2
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08069FB8
	b _0806A0FA
_08069FB8:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08069FC6
	b _0806A0FA
_08069FC6:
	cmp r8, r6
	bne _08069FCC
	b _0806A0FA
_08069FCC:
	mov r0, r8
	ldr r2, [r0, 0x70]
	adds r3, r2, 0
	ldr r7, [r6, 0x70]
	movs r4, 0x1
	negs r4, r4
	adds r0, r7, 0
	adds r0, 0x5E
	ldrb r0, [r0]
	cmp r0, 0x28
	bne _08069FE4
	movs r4, 0
_08069FE4:
	adds r0, r7, 0
	adds r0, 0x5F
	ldrb r0, [r0]
	cmp r0, 0x28
	bne _08069FF0
	movs r4, 0x1
_08069FF0:
	cmp r4, 0
	blt _0806A068
	movs r1, 0
	adds r0, r2, 0
	adds r0, 0x5E
	ldrb r2, [r0]
	cmp r2, 0
	beq _0806A006
	mov r0, sp
	strb r2, [r0]
	movs r1, 0x1
_0806A006:
	adds r0, r3, 0
	adds r0, 0x5F
	ldrb r2, [r0]
	cmp r2, 0
	beq _0806A018
	mov r3, sp
	adds r0, r3, r1
	strb r2, [r0]
	adds r1, 0x1
_0806A018:
	cmp r1, 0
	beq _0806A068
	cmp r1, 0x1
	bne _0806A024
	movs r1, 0
	b _0806A030
_0806A024:
	adds r0, r1, 0
	bl DungeonRandomCapped
	adds r1, r0, 0
	cmp r1, 0
	blt _0806A068
_0806A030:
	adds r0, r7, 0
	adds r0, 0x5E
	adds r0, r4
	add r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, _0806A108
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xC]
	ldr r0, _0806A10C
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806A110
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	adds r0, r6, 0
	bl sub_8042900
	mov r0, r8
	adds r1, r6, 0
	bl sub_806ABAC
_0806A068:
	movs r0, 0xAD
	lsls r0, 1
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _0806A0FA
	movs r0, 0
	strb r0, [r1]
	adds r0, r6, 0
	movs r1, 0x3B
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806A0FA
	mov r0, r8
	mov r1, r9
	bl sub_8071A1C
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r9
	ldrh r0, [r1, 0x2]
	cmp r0, 0x1F
	bne _0806A0AA
	mov r0, r8
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _0806A114
	adds r0, r1
	ldrb r5, [r0]
_0806A0AA:
	cmp r5, 0
	beq _0806A0FA
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_8071858
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0806A0FA
	adds r4, r7, 0
	adds r4, 0x5C
	strb r5, [r4]
	adds r1, r7, 0
	adds r1, 0x5D
	strb r0, [r1]
	adds r1, 0x99
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0806A10C
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r4]
	bl GetUnformattedTypeString
	adds r1, r0, 0
	ldr r0, _0806A118
	bl strcpy
	ldr r0, _0806A11C
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	adds r0, r6, 0
	bl sub_8042968
_0806A0FA:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A108: .4byte gDungeonGlobalData
_0806A10C: .4byte gAvailablePokemonNames
_0806A110: .4byte gUnknown_80FCC7C
_0806A114: .4byte gUnknown_80F51E4
_0806A118: .4byte gUnknown_202DE58
_0806A11C: .4byte gUnknown_80FCCAC
	thumb_func_end sub_8069F9C

	thumb_func_start sub_806A120
sub_806A120:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r6, r1, 0
	adds r4, r2, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A19C
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A19C
	cmp r7, r6
	beq _0806A19C
	ldr r5, [r6, 0x70]
	adds r0, r5, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _0806A19C
	adds r0, r7, 0
	adds r1, r4, 0
	bl sub_8071A1C
	lsls r0, 24
	lsrs r0, 24
	bl sub_8092364
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0806A19C
	adds r0, r5, 0
	adds r0, 0x5C
	movs r1, 0
	strb r4, [r0]
	adds r0, 0x1
	strb r1, [r0]
	adds r0, r6, 0
	bl sub_8041BBC
	ldr r0, _0806A1A4
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	adds r0, r4, 0
	bl GetUnformattedTypeString
	adds r1, r0, 0
	ldr r0, _0806A1A8
	bl strcpy
	ldr r0, _0806A1AC
	ldr r2, [r0]
	adds r0, r7, 0
	adds r1, r6, 0
	bl sub_80522F4
_0806A19C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A1A4: .4byte gAvailablePokemonNames
_0806A1A8: .4byte gUnknown_202DE58
_0806A1AC: .4byte gUnknown_80FDCC8
	thumb_func_end sub_806A120

	thumb_func_start sub_806A1B0
sub_806A1B0:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A1DE
	adds r0, r4, 0
	movs r1, 0x2A
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806A1DE
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8076090
_0806A1DE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806A1B0

	thumb_func_start sub_806A1E8
sub_806A1E8:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A234
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806A210
	ldr r0, [r4, 0x70]
	movs r1, 0
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0806A20E
	movs r1, 0x1
_0806A20E:
	adds r5, r1, 0
_0806A210:
	ldr r0, _0806A23C
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0806A21C
	movs r5, 0
_0806A21C:
	cmp r5, 0
	beq _0806A234
	adds r0, r4, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	bne _0806A234
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806A2BC
_0806A234:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A23C: .4byte gUnknown_203B46C
	thumb_func_end sub_806A1E8

	thumb_func_start sub_806A240
sub_806A240:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A2B4
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806A26A
	ldr r0, [r4, 0x70]
	movs r1, 0
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0806A268
	movs r1, 0x1
_0806A268:
	adds r6, r1, 0
_0806A26A:
	cmp r6, 0
	beq _0806A284
	adds r0, r4, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	bne _0806A284
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806A2BC
	b _0806A2B4
_0806A284:
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806A29C
	ldr r0, [r5, 0x70]
	movs r1, 0
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	bne _0806A29A
	movs r1, 0x1
_0806A29A:
	adds r6, r1, 0
_0806A29C:
	cmp r6, 0
	beq _0806A2B4
	adds r0, r5, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	bne _0806A2B4
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_806A2BC
_0806A2B4:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806A240

	thumb_func_start sub_806A2BC
sub_806A2BC:
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A328
	adds r0, r4, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806A328
	ldr r5, _0806A2F4
	ldr r0, [r5]
	ldr r1, _0806A2F8
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r4
	beq _0806A328
	adds r7, r4, 0x4
	cmp r6, 0
	beq _0806A30C
	movs r0, 0x1
	bl sub_804178C
	b _0806A302
	.align 2, 0
_0806A2F4: .4byte gDungeonGlobalData
_0806A2F8: .4byte 0x000181f8
_0806A2FC:
	movs r0, 0x34
	bl sub_803E46C
_0806A302:
	ldr r0, [r5]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	cmp r0, 0x3B
	ble _0806A2FC
_0806A30C:
	movs r0, 0x4
	movs r1, 0x44
	bl sub_803E708
	adds r0, r4, 0
	bl sub_803F508
	adds r0, r7, 0
	bl sub_804AC20
	ldr r0, _0806A330
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x12]
_0806A328:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A330: .4byte gDungeonGlobalData
	thumb_func_end sub_806A2BC

	thumb_func_start nullsub_95
nullsub_95:
	bx lr
	thumb_func_end nullsub_95

	thumb_func_start sub_806A338
sub_806A338:
	push {r4-r6,lr}
	movs r5, 0
	ldr r6, _0806A378
_0806A33E:
	ldr r0, [r6]
	lsls r1, r5, 2
	ldr r2, _0806A37C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A384
	ldr r0, [r4, 0x70]
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806A384
	ldr r1, [r6]
	ldr r2, _0806A380
	adds r0, r1, r2
	str r4, [r0]
	ldr r0, [r4, 0x70]
	adds r2, 0xC
	adds r1, r2
	adds r0, 0x98
	ldr r0, [r0]
	str r0, [r1]
	b _0806A38A
	.align 2, 0
_0806A378: .4byte gDungeonGlobalData
_0806A37C: .4byte 0x000135cc
_0806A380: .4byte 0x00017b30
_0806A384:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806A33E
_0806A38A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806A338

	thumb_func_start sub_806A390
sub_806A390:
	push {r4-r7,lr}
	ldr r0, [r0, 0x70]
	movs r7, 0
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r0, r1
	adds r5, r4, 0
	movs r6, 0x3
_0806A3A0:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806A3C2
	ldrb r1, [r4, 0x1]
	movs r0, 0xF7
	ands r0, r1
	movs r1, 0xEF
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8092BF4
	strb r0, [r4, 0x4]
_0806A3C2:
	adds r4, 0x8
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _0806A3A0
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806A390

	thumb_func_start sub_806A3D4
sub_806A3D4:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	adds r6, r2, 0
	lsls r1, 16
	asrs r5, r1, 16
	lsls r3, 24
	cmp r3, 0
	beq _0806A404
	ldr r4, _0806A400
	adds r0, r5, 0
	movs r1, 0xA
	bl __divsi3
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	adds r1, r4, 0
	bl sprintf
	b _0806A41C
	.align 2, 0
_0806A400: .4byte gUnknown_8106EA8
_0806A404:
	ldr r4, _0806A450
	adds r0, r5, 0
	movs r1, 0xA
	bl __divsi3
	adds r2, r0, 0
	lsls r2, 16
	asrs r2, 16
	mov r0, sp
	adds r1, r4, 0
	bl sprintf
_0806A41C:
	ldr r1, _0806A454
	mov r0, sp
	bl OpenFileAndGetFileDataPtr
	adds r4, r0, 0
	adds r0, r5, 0
	movs r1, 0xA
	bl __modsi3
	lsls r0, 16
	ldr r1, [r4, 0x4]
	asrs r0, 12
	adds r0, r1
	lsls r1, r6, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r7, 0
	bl strcpy
	adds r0, r4, 0
	bl CloseFile
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A450: .4byte gUnknown_8106EB0
_0806A454: .4byte gDungeonFileArchive
	thumb_func_end sub_806A3D4

	thumb_func_start sub_806A458
sub_806A458:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	movs r0, 0
	mov r9, r0
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x6]
	mov r10, r0
	adds r0, r6, 0
	bl sub_80696A8
	cmp r0, 0
	bne _0806A47C
	movs r0, 0
	b _0806A4CC
_0806A47C:
	movs r7, 0x1
	negs r7, r7
_0806A480:
	movs r5, 0x1
	negs r5, r5
	adds r1, r7, 0x1
	mov r8, r1
_0806A488:
	movs r2, 0x4
	ldrsh r0, [r6, r2]
	adds r0, r5
	movs r2, 0x6
	ldrsh r1, [r6, r2]
	adds r1, r7
	bl sub_8049590
	adds r4, r0, 0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0806A4B6
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806A4B6
	ldr r0, [r4, 0x10]
	ldr r0, [r0, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, r10
	beq _0806A4B6
	movs r0, 0x1
	add r9, r0
_0806A4B6:
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806A488
	mov r7, r8
	cmp r7, 0x1
	ble _0806A480
	movs r0, 0
	mov r1, r9
	cmp r1, 0x1
	ble _0806A4CC
	movs r0, 0x1
_0806A4CC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806A458

	thumb_func_start sub_806A4DC
sub_806A4DC:
	push {r4,lr}
	sub sp, 0x64
	adds r4, r0, 0
	ldr r1, _0806A530
	ldr r0, [sp, 0x60]
	ands r0, r1
	ldr r1, _0806A534
	ands r0, r1
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp, 0x60]
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	add r0, sp, 0x60
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	movs r2, 0
	movs r3, 0
	bl sub_808CFD0
	add r1, sp, 0x8
	ldrh r0, [r4, 0x2]
	strh r0, [r1, 0x8]
	ldrb r0, [r4, 0x9]
	strb r0, [r1, 0x3]
	ldrh r0, [r4, 0xC]
	strh r0, [r1, 0x14]
	ldrb r0, [r4, 0x14]
	strb r0, [r1, 0x18]
	ldrb r0, [r4, 0x16]
	strb r0, [r1, 0x1A]
	adds r0, r1, 0
	bl sub_808F700
	add sp, 0x64
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0806A530: .4byte 0xffffff00
_0806A534: .4byte 0xffff00ff
	thumb_func_end sub_806A4DC

	thumb_func_start sub_806A538
sub_806A538:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	adds r2, r1, 0
	ldr r0, _0806A554
	cmp r1, r0
	beq _0806A550
	ldr r0, _0806A558
	cmp r1, r0
	beq _0806A550
	cmp r2, 0
	bge _0806A55C
_0806A550:
	movs r0, 0x1
	b _0806A55E
	.align 2, 0
_0806A554: .4byte 0x000055aa
_0806A558: .4byte 0x00005aa5
_0806A55C:
	movs r0, 0
_0806A55E:
	pop {r1}
	bx r1
	thumb_func_end sub_806A538

	thumb_func_start sub_806A564
sub_806A564:
	push {lr}
	lsls r0, 16
	asrs r1, r0, 16
	ldr r0, _0806A57C
	cmp r1, r0
	beq _0806A584
	ldr r0, _0806A580
	cmp r1, r0
	beq _0806A584
	movs r0, 0
	b _0806A586
	.align 2, 0
_0806A57C: .4byte 0x000055aa
_0806A580: .4byte 0x00005aa5
_0806A584:
	movs r0, 0x1
_0806A586:
	pop {r1}
	bx r1
	thumb_func_end sub_806A564

	thumb_func_start sub_806A58C
sub_806A58C:
	push {lr}
	lsls r0, 16
	movs r1, 0xCE
	lsls r1, 17
	cmp r0, r1
	bls _0806A59C
	movs r0, 0
	b _0806A59E
_0806A59C:
	movs r0, 0x1
_0806A59E:
	pop {r1}
	bx r1
	thumb_func_end sub_806A58C

	thumb_func_start sub_806A5A4
sub_806A5A4:
	push {lr}
	lsls r0, 16
	cmp r0, 0
	blt _0806A5B0
	movs r0, 0
	b _0806A5B2
_0806A5B0:
	movs r0, 0x1
_0806A5B2:
	pop {r1}
	bx r1
	thumb_func_end sub_806A5A4

	thumb_func_start sub_806A5B8
sub_806A5B8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r6, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806A5CE
	b _0806A6D2
_0806A5CE:
	adds r0, r6, 0
	bl sub_8045128
	ldrh r0, [r0]
	movs r1, 0x3
	ands r1, r0
	cmp r1, 0x2
	bne _0806A664
	ldr r4, [r6, 0x70]
	ldr r1, _0806A640
	ldr r0, _0806A644
	ldr r0, [r0]
	ldr r2, _0806A648
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A650
	adds r0, r4, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A608
	adds r0, r6, 0
	adds r1, r6, 0
	bl SendImmobilizeEndMessage
_0806A608:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl GetWalkableTiles
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _0806A6D2
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	ldr r0, _0806A64C
	cmp r1, r0
	beq _0806A6D2
	cmp r1, 0x92
	beq _0806A6D2
	adds r0, r4, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806A6D2
	adds r0, r6, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8076210
	b _0806A6D2
	.align 2, 0
_0806A640: .4byte gUnknown_810ACC0
_0806A644: .4byte gDungeonGlobalData
_0806A648: .4byte 0x00003a0e
_0806A64C: .4byte 0x00000113
_0806A650:
	adds r0, r4, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A6D2
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_807A290
	b _0806A6D2
_0806A664:
	cmp r1, 0
	bne _0806A6D2
	ldr r7, [r6, 0x70]
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0806A6D2
	movs r0, 0x9E
	lsls r0, 1
	adds r4, r7, r0
	ldr r5, [r4]
	mov r0, sp
	adds r1, r5, 0
	movs r2, 0x5
	bl sub_80942C0
	ldr r0, [sp]
	str r0, [r4]
	movs r1, 0
	mov r8, r1
	adds r0, r5, 0
	bl sub_8094450
	cmp r0, 0x13
	ble _0806A6A4
	ldr r0, [r4]
	bl sub_8094450
	cmp r0, 0x13
	bgt _0806A6A4
	ldr r0, _0806A6E0
	ldr r0, [r0]
	mov r8, r0
_0806A6A4:
	adds r0, r5, 0
	bl sub_8094450
	cmp r0, 0x9
	ble _0806A6C4
	movs r2, 0x9E
	lsls r2, 1
	adds r0, r7, r2
	ldr r0, [r0]
	bl sub_8094450
	cmp r0, 0x9
	bgt _0806A6C4
	ldr r0, _0806A6E4
	ldr r0, [r0]
	mov r8, r0
_0806A6C4:
	mov r0, r8
	cmp r0, 0
	beq _0806A6D2
	adds r0, r6, 0
	mov r1, r8
	bl SendMessage
_0806A6D2:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A6E0: .4byte gUnknown_80FD594
_0806A6E4: .4byte gUnknown_80FD5B8
	thumb_func_end sub_806A5B8

	thumb_func_start sub_806A6E8
sub_806A6E8:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	ldr r6, [r7, 0x70]
	adds r0, r6, 0
	adds r0, 0x64
	adds r1, r6, 0
	adds r1, 0x62
	ldrb r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	beq _0806A77A
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806A764
	cmp r1, 0xA
	beq _0806A70E
	cmp r1, 0x2B
	bne _0806A72E
_0806A70E:
	movs r0, 0x9E
	lsls r0, 1
	adds r5, r6, r0
	ldr r4, [r5]
	mov r0, sp
	movs r1, 0xA
	bl sub_80943A0
	ldr r2, [sp]
	add r0, sp, 0x4
	adds r1, r4, 0
	bl sub_80942C0
	ldr r0, [sp, 0x4]
	str r0, [r5]
	b _0806A744
_0806A72E:
	cmp r1, 0x1B
	bne _0806A744
	add r0, sp, 0x8
	movs r1, 0
	bl sub_80943A0
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	ldr r0, [sp, 0x8]
	str r0, [r1]
_0806A744:
	ldr r0, _0806A75C
	ldr r0, [r0]
	ldr r1, _0806A760
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806A776
	adds r0, r7, 0
	bl sub_80418D4
	b _0806A776
	.align 2, 0
_0806A75C: .4byte gDungeonGlobalData
_0806A760: .4byte 0x00000676
_0806A764:
	cmp r1, 0x11
	beq _0806A76C
	cmp r2, 0x11
	bne _0806A776
_0806A76C:
	movs r0, 0x1
	bl sub_803F580
	bl sub_8040A84
_0806A776:
	bl sub_807AA30
_0806A77A:
	adds r0, r6, 0
	adds r0, 0x60
	ldrb r0, [r0]
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0806A792
	adds r0, r6, 0
	adds r0, 0x62
	ldrb r1, [r0]
	adds r0, 0x2
	b _0806A796
_0806A792:
	adds r0, r6, 0
	adds r0, 0x64
_0806A796:
	strb r1, [r0]
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806A6E8

	thumb_func_start sub_806A7A0
sub_806A7A0:
	push {r4,r5,lr}
	movs r5, 0
_0806A7A4:
	ldr r0, _0806A7E0
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806A7E4
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A7D2
	ldr r2, [r4, 0x70]
	movs r1, 0xC
	ldrsh r0, [r2, r1]
	cmp r0, 0x1
	ble _0806A7D2
	adds r1, r0, 0
	subs r1, 0x1
	adds r0, r2, 0
	bl sub_806A7E8
_0806A7D2:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806A7A4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A7E0: .4byte gDungeonGlobalData
_0806A7E4: .4byte 0x0001357c
	thumb_func_end sub_806A7A0

	thumb_func_start sub_806A7E8
sub_806A7E8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x30
	adds r5, r0, 0
	mov r0, sp
	bl sub_808EBA8
	mov r9, r0
	add r4, sp, 0x18
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	adds r0, r4, 0
	bl sub_808EBA8
	adds r6, r0, 0
	ldr r0, _0806A828
	adds r1, r5, 0
	movs r2, 0
	bl sub_80708B4
	movs r2, 0x1
	mov r8, r4
_0806A818:
	movs r3, 0
	movs r5, 0
	movs r1, 0
	adds r4, r2, 0x1
	cmp r3, r9
	bge _0806A83E
	mov r0, sp
	b _0806A836
	.align 2, 0
_0806A828: .4byte gAvailablePokemonNames
_0806A82C:
	adds r1, 0x1
	cmp r1, r9
	bge _0806A83E
	mov r7, sp
	adds r0, r7, r1
_0806A836:
	ldrb r0, [r0]
	cmp r0, r2
	bne _0806A82C
	movs r3, 0x1
_0806A83E:
	movs r1, 0
	cmp r1, r6
	bge _0806A85C
	mov r7, r8
	ldrb r0, [r7]
	b _0806A856
_0806A84A:
	adds r1, 0x1
	cmp r1, r6
	bge _0806A85C
	mov r7, r8
	adds r0, r7, r1
	ldrb r0, [r0]
_0806A856:
	cmp r0, r2
	bne _0806A84A
	movs r5, 0x1
_0806A85C:
	cmp r3, r5
	beq _0806A87A
	lsls r0, r2, 24
	lsrs r0, 24
	bl GetIQSkillName
	adds r1, r0, 0
	ldr r0, _0806A890
	bl strcpy
	ldr r0, _0806A894
	ldr r1, [r0]
	movs r0, 0
	bl sub_805239C
_0806A87A:
	adds r2, r4, 0
	cmp r2, 0x17
	ble _0806A818
	add sp, 0x30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A890: .4byte gUnknown_202DE58
_0806A894: .4byte gUnknown_80FEAC4
	thumb_func_end sub_806A7E8

	thumb_func_start sub_806A898
sub_806A898:
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r1, r2, 24
	ldr r5, [r4, 0x70]
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _0806A8C2
	ldrh r1, [r4, 0x4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r5, r2
	strh r1, [r0]
	ldrh r0, [r4, 0x6]
	adds r0, 0x1
	adds r2, 0x2
	adds r1, r5, r2
	strh r0, [r1]
	b _0806A8C8
_0806A8C2:
	adds r0, r4, 0
	bl MoveIfPossible
_0806A8C8:
	movs r0, 0xB6
	lsls r0, 1
	adds r6, r5, r0
	ldr r0, [r6]
	cmp r0, 0
	beq _0806A90E
	adds r0, r4, 0
	movs r1, 0x1
	bl CannotMove
	lsls r0, 24
	cmp r0, 0
	beq _0806A8EE
	adds r0, r4, 0
	bl CannotAct
	lsls r0, 24
	cmp r0, 0
	bne _0806A90E
_0806A8EE:
	adds r0, r4, 0x4
	adds r1, r6, 0
	bl sub_80983D8
	adds r2, r0, 0
	movs r1, 0x7
	ands r0, r1
	adds r1, r5, 0
	adds r1, 0x46
	strb r0, [r1]
	cmp r7, 0
	beq _0806A90E
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_806CE68
_0806A90E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806A898

	thumb_func_start sub_806A914
sub_806A914:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	movs r5, 0
_0806A92A:
	ldr r0, _0806A96C
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806A970
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A95C
	ldr r0, [r4, 0x70]
	cmp r7, 0
	beq _0806A952
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806A95C
_0806A952:
	adds r0, r4, 0
	mov r1, r8
	adds r2, r6, 0
	bl sub_806A898
_0806A95C:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806A92A
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A96C: .4byte gDungeonGlobalData
_0806A970: .4byte 0x000135cc
	thumb_func_end sub_806A914

	thumb_func_start sub_806A974
sub_806A974:
	push {r4,r5,lr}
	movs r5, 0
_0806A978:
	ldr r0, _0806A9AC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806A9B0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806A99E
	ldr r0, [r4, 0x70]
	adds r0, 0x46
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_806CE68
_0806A99E:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806A978
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A9AC: .4byte gDungeonGlobalData
_0806A9B0: .4byte 0x000135cc
	thumb_func_end sub_806A974

	thumb_func_start sub_806A9B4
sub_806A9B4:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806AA02
	ldr r0, [r4, 0x70]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r1, r5, 0
	bl sub_80935B8
	cmp r0, 0
	bne _0806A9E0
	ldr r0, _0806A9DC
	b _0806A9E6
	.align 2, 0
_0806A9DC: .4byte gPtrLinkedMovesComeApartMessage
_0806A9E0:
	cmp r0, 0x1
	bne _0806A9F4
	ldr r0, _0806A9F0
_0806A9E6:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _0806AA02
	.align 2, 0
_0806A9F0: .4byte gPtrLinkMoveOneUseWarningMessage
_0806A9F4:
	cmp r0, 0x2
	bne _0806AA02
	ldr r0, _0806AA08
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_0806AA02:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806AA08: .4byte gPtrLinkMoveTwoUsesWarningMessage
	thumb_func_end sub_806A9B4

	thumb_func_start sub_806AA0C
sub_806AA0C:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	adds r0, r4, 0
	bl IsExclusivePokemonUnlocked
	lsls r0, 24
	cmp r0, 0
	beq _0806AA56
	ldr r0, _0806AA5C
	ldr r0, [r0]
	ldr r1, _0806AA60
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806AA40
	adds r0, r4, 0
	bl GetBaseSpecies
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	beq _0806AA56
_0806AA40:
	cmp r4, 0x97
	bne _0806AA68
	ldr r0, _0806AA5C
	ldr r0, [r0]
	ldr r1, _0806AA64
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806AA56
	cmp r5, 0
	bne _0806AA68
_0806AA56:
	movs r0, 0
	b _0806AA6A
	.align 2, 0
_0806AA5C: .4byte gDungeonGlobalData
_0806AA60: .4byte 0x000037fd
_0806AA64: .4byte 0x000037ff
_0806AA68:
	movs r0, 0x1
_0806AA6A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806AA0C

	thumb_func_start sub_806AA70
sub_806AA70:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r7, 0
	ldr r0, _0806AAB4
	mov r8, r0
_0806AA7C:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r7, 2
	ldr r2, _0806AAB8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806AB12
	ldr r0, [r4, 0x70]
	ldrb r2, [r0, 0xA]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0806AAC4
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x11]
	cmp r0, 0x1
	bne _0806AABC
	adds r0, r4, 0
	bl sub_8042B20
	b _0806AB0A
	.align 2, 0
_0806AAB4: .4byte gDungeonGlobalData
_0806AAB8: .4byte 0x0001357c
_0806AABC:
	adds r0, r4, 0
	bl sub_8042B0C
	b _0806AB0A
_0806AAC4:
	cmp r2, 0
	blt _0806AB12
	movs r6, 0
	ldr r1, _0806AB24
	movs r0, 0x64
	muls r0, r2
	ldr r2, _0806AB28
	adds r0, r2
	ldr r1, [r1]
	adds r5, r1, r0
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x11]
	cmp r0, 0
	bne _0806AB04
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	bl sub_806A564
	lsls r0, 24
	cmp r0, 0
	bne _0806AB04
	movs r1, 0xA
	ldrsh r0, [r5, r1]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _0806AB00
	movs r6, 0x1
_0806AB00:
	cmp r6, 0
	beq _0806AB12
_0806AB04:
	adds r0, r4, 0
	bl sub_8042B0C
_0806AB0A:
	adds r1, r4, 0
	adds r1, 0x20
	movs r0, 0
	strb r0, [r1]
_0806AB12:
	adds r7, 0x1
	cmp r7, 0x3
	ble _0806AA7C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AB24: .4byte gRecruitedPokemonRef
_0806AB28: .4byte 0x00008df8
	thumb_func_end sub_806AA70

	thumb_func_start sub_806AB2C
sub_806AB2C:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r4, 0
	ldr r0, _0806ABA4
	mov r9, r0
_0806AB3A:
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r4, 2
	ldr r2, _0806ABA8
	adds r0, r2
	adds r0, r1
	ldr r7, [r0]
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	adds r4, 0x1
	mov r8, r4
	cmp r0, 0
	beq _0806AB92
	ldr r5, [r7, 0x70]
	movs r6, 0
_0806AB5C:
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r6, 2
	ldr r2, _0806ABA8
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806AB8C
	cmp r7, r4
	beq _0806AB8C
	adds r0, r5, 0
	adds r0, 0x7C
	ldrh r0, [r0]
	ldrh r1, [r4, 0x26]
	cmp r0, r1
	bne _0806AB8C
	adds r0, r5, 0
	adds r0, 0x80
	str r4, [r0]
_0806AB8C:
	adds r6, 0x1
	cmp r6, 0x13
	ble _0806AB5C
_0806AB92:
	mov r4, r8
	cmp r4, 0x13
	ble _0806AB3A
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806ABA4: .4byte gDungeonGlobalData
_0806ABA8: .4byte 0x000135cc
	thumb_func_end sub_806AB2C

	thumb_func_start sub_806ABAC
sub_806ABAC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	ldr r5, [r4, 0x70]
	adds r0, r4, 0
	movs r1, 0x16
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806ABD4
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806ABD4
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A290
_0806ABD4:
	adds r0, r4, 0
	movs r1, 0x40
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806ABF4
	adds r0, r5, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0806ABF4
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A400
_0806ABF4:
	adds r0, r4, 0
	movs r1, 0x42
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806AC14
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806AC14
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A290
_0806AC14:
	adds r0, r4, 0
	movs r1, 0x29
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806AC34
	adds r0, r5, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _0806AC34
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A400
_0806AC34:
	adds r0, r4, 0
	movs r1, 0x36
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _0806AC50
	adds r0, r4, 0
	movs r1, 0x49
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806AC72
_0806AC50:
	adds r0, r4, 0
	bl sub_8070B28
	lsls r0, 24
	cmp r0, 0
	bne _0806AC66
	adds r0, r5, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806AC72
_0806AC66:
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_807A124
_0806AC72:
	adds r0, r4, 0
	movs r1, 0x41
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806AC92
	adds r0, r5, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806AC92
	adds r0, r6, 0
	adds r1, r4, 0
	bl SendImmobilizeEndMessage
_0806AC92:
	adds r0, r4, 0
	movs r1, 0x45
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806ACB8
	adds r0, r5, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806ACB8
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A290
_0806ACB8:
	adds r0, r4, 0
	movs r1, 0x25
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806ACE0
	adds r1, r5, 0
	adds r1, 0xF6
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _0806ACE0
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_807A4C8
_0806ACE0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806ABAC

	thumb_func_start sub_806ACE8
sub_806ACE8:
	push {r4,r5,lr}
	adds r4, r1, 0
	ldr r0, [r0, 0x70]
	mov r12, r0
	movs r5, 0xEF
	movs r2, 0x8C
	lsls r2, 1
	add r2, r12
	movs r3, 0x3
_0806ACFA:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2]
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0806ACFA
	movs r2, 0x9C
	lsls r2, 1
	add r2, r12
	ldrb r0, [r2]
	movs r3, 0xEF
	ands r3, r0
	movs r5, 0
	strb r3, [r2]
	ldrh r1, [r4, 0x2]
	movs r0, 0xB0
	lsls r0, 1
	cmp r1, r0
	bne _0806AD2E
	movs r1, 0x10
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
	b _0806AD36
_0806AD2E:
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4]
_0806AD36:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806ACE8

	thumb_func_start sub_806AD3C
sub_806AD3C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0806AE1C
	add sp, r4
	ldr r0, _0806AE20
	ldr r0, [r0]
	ldr r1, _0806AE24
	adds r4, r0, r1
	mov r0, sp
	movs r1, 0
	bl sub_803D808
	str r0, [sp, 0x200]
	movs r7, 0
	cmp r7, r0
	bge _0806ADEC
	mov r6, sp
	adds r7, r0, 0
_0806AD66:
	adds r0, r6, 0
	bl sub_808E9B8
	strh r0, [r4]
	adds r0, r6, 0
	bl sub_808E9E4
	strh r0, [r4, 0x2]
	adds r0, r4, 0x4
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x2
	ldrsh r2, [r4, r3]
	bl sub_8072AC8
	ldrh r0, [r4, 0x4]
	cmp r0, 0
	bne _0806AD90
	movs r0, 0xB8
	lsls r0, 1
	strh r0, [r4, 0x4]
_0806AD90:
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	bl sub_806C444
	strh r0, [r4, 0xC]
	movs r5, 0
	movs r3, 0xE
	adds r3, r4
	mov r9, r3
	movs r0, 0x10
	adds r0, r4
	mov r8, r0
	movs r1, 0x14
	adds r1, r4
	mov r10, r1
_0806ADB2:
	movs r2, 0
	ldrsh r0, [r4, r2]
	movs r3, 0x2
	ldrsh r1, [r4, r3]
	adds r2, r5, 0
	bl sub_806C488
	mov r2, r9
	adds r1, r2, r5
	strb r0, [r1]
	movs r3, 0
	ldrsh r0, [r4, r3]
	movs r2, 0x2
	ldrsh r1, [r4, r2]
	adds r2, r5, 0
	bl sub_806C4D4
	mov r3, r8
	adds r1, r3, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806ADB2
	mov r4, r10
	adds r6, 0x8
	subs r7, 0x1
	cmp r7, 0
	bne _0806AD66
	ldr r7, [sp, 0x200]
_0806ADEC:
	cmp r7, 0x3F
	bgt _0806ADFC
	movs r0, 0
_0806ADF2:
	strh r0, [r4]
	adds r4, 0x14
	adds r7, 0x1
	cmp r7, 0x3F
	ble _0806ADF2
_0806ADFC:
	movs r7, 0
	ldr r4, _0806AE28
	ldr r3, _0806AE20
	ldr r2, _0806AE2C
	movs r1, 0
_0806AE06:
	ldr r0, [r3]
	adds r0, r2
	adds r0, r7
	strb r1, [r0]
	adds r7, 0x1
	cmp r7, r4
	ble _0806AE06
	movs r0, 0x1
	mov r10, r0
	movs r7, 0
	b _0806AE94
	.align 2, 0
_0806AE1C: .4byte 0xfffffdfc
_0806AE20: .4byte gDungeonGlobalData
_0806AE24: .4byte 0x00002f3c
_0806AE28: .4byte 0x000001a7
_0806AE2C: .4byte 0x0000363c
_0806AE30:
	movs r2, 0x1
	negs r2, r2
	mov r8, r2
	mov r9, r8
	ldr r3, [sp, 0x200]
	cmp r3, 0
	ble _0806AE7A
	mov r5, sp
	adds r6, r3, 0
_0806AE42:
	adds r0, r5, 0
	bl sub_808E9B8
	lsls r0, 16
	asrs r4, r0, 16
	ldr r1, _0806AECC
	ldr r0, [r1]
	ldr r2, _0806AED0
	adds r0, r2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806AE72
	adds r0, r5, 0
	bl sub_808E9E4
	adds r1, r0, 0
	adds r0, r4, 0
	bl CalculateEXPGain
	cmp r9, r0
	bge _0806AE72
	mov r9, r0
	mov r8, r4
_0806AE72:
	adds r5, 0x8
	subs r6, 0x1
	cmp r6, 0
	bne _0806AE42
_0806AE7A:
	mov r3, r8
	cmp r3, 0
	blt _0806AE9A
	ldr r1, _0806AECC
	ldr r0, [r1]
	ldr r2, _0806AED0
	adds r0, r2
	add r0, r8
	mov r3, r10
	strb r3, [r0]
	movs r0, 0x2
	add r10, r0
	adds r7, 0x1
_0806AE94:
	ldr r1, [sp, 0x200]
	cmp r7, r1
	blt _0806AE30
_0806AE9A:
	movs r7, 0
	ldr r5, _0806AECC
	ldr r4, _0806AED0
	movs r3, 0x1
	ldr r2, _0806AED4
_0806AEA4:
	ldr r0, [r5]
	adds r0, r4
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, 0
	bne _0806AEB2
	strb r3, [r1]
_0806AEB2:
	adds r7, 0x1
	cmp r7, r2
	ble _0806AEA4
	movs r3, 0x81
	lsls r3, 2
	add sp, r3
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AECC: .4byte gDungeonGlobalData
_0806AED0: .4byte 0x0000363c
_0806AED4: .4byte 0x000001a7
	thumb_func_end sub_806AD3C

	thumb_func_start sub_806AED8
sub_806AED8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	mov r10, r0
	str r1, [sp, 0x8]
	str r2, [sp, 0xC]
	str r3, [sp, 0x10]
	ldr r0, [sp, 0x38]
	ldr r1, [sp, 0x3C]
	mov r8, r1
	lsls r0, 16
	asrs r7, r0, 16
	ldr r1, _0806AF04
	ldr r0, [r1]
	ldr r4, _0806AF08
	adds r6, r0, r4
	movs r3, 0
	b _0806AF7A
	.align 2, 0
_0806AF04: .4byte gDungeonGlobalData
_0806AF08: .4byte 0x00002f3c
_0806AF0C:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, r7
	bne _0806AF6E
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	cmp r0, r8
	bne _0806AF6E
	movs r5, 0xE
	adds r5, r6
	mov r8, r5
	movs r0, 0x10
	adds r0, r6
	mov r9, r0
	mov r1, r10
	adds r1, 0x20
	str r1, [sp, 0x14]
	adds r5, r6, 0x4
	mov r4, r10
	movs r7, 0x3
_0806AF34:
	ldrh r1, [r5]
	adds r0, r4, 0
	bl sub_8092AA8
	adds r5, 0x2
	adds r4, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _0806AF34
	ldrh r0, [r6, 0xC]
	ldr r2, [sp, 0x8]
	strh r0, [r2]
	movs r5, 0
	mov r3, r8
	mov r2, r9
_0806AF52:
	ldr r0, [sp, 0xC]
	adds r1, r0, r5
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	adds r1, r0, r5
	adds r0, r2, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806AF52
	b _0806B084
_0806AF6E:
	adds r4, 0x14
	adds r3, 0x1
	cmp r3, 0x3F
	bgt _0806AF84
	ldr r0, [r1]
	adds r6, r0, r4
_0806AF7A:
	ldrh r2, [r6]
	movs r5, 0
	ldrsh r0, [r6, r5]
	cmp r0, 0
	bne _0806AF0C
_0806AF84:
	cmp r3, 0x40
	bne _0806AFE6
	mov r0, sp
	adds r1, r7, 0
	mov r2, r8
	bl sub_8072AC8
	mov r0, r10
	adds r0, 0x20
	str r0, [sp, 0x14]
	mov r5, sp
	mov r4, r10
	movs r6, 0x3
_0806AF9E:
	ldrh r1, [r5]
	adds r0, r4, 0
	bl sub_8092AA8
	adds r5, 0x2
	adds r4, 0x8
	subs r6, 0x1
	cmp r6, 0
	bge _0806AF9E
	adds r0, r7, 0
	mov r1, r8
	bl sub_806C444
	ldr r1, [sp, 0x8]
	strh r0, [r1]
	movs r5, 0
_0806AFBE:
	adds r0, r7, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_806C488
	ldr r2, [sp, 0xC]
	adds r1, r2, r5
	strb r0, [r1]
	adds r0, r7, 0
	mov r1, r8
	adds r2, r5, 0
	bl sub_806C4D4
	ldr r2, [sp, 0x10]
	adds r1, r2, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806AFBE
	b _0806B084
_0806AFE6:
	strh r7, [r6]
	mov r5, r8
	strh r5, [r6, 0x2]
	adds r4, r6, 0x4
	adds r0, r4, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8072AC8
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	bl sub_806C444
	strh r0, [r6, 0xC]
	movs r5, 0
	movs r0, 0xE
	adds r0, r6
	mov r8, r0
	movs r1, 0x10
	adds r1, r6
	mov r9, r1
	mov r2, r10
	adds r2, 0x20
	str r2, [sp, 0x14]
_0806B01A:
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	adds r2, r5, 0
	bl sub_806C488
	mov r2, r8
	adds r1, r2, r5
	strb r0, [r1]
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	adds r2, r5, 0
	bl sub_806C4D4
	mov r2, r9
	adds r1, r2, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806B01A
	mov r5, r10
	movs r7, 0x3
_0806B04C:
	ldrh r1, [r4]
	adds r0, r5, 0
	bl sub_8092AA8
	adds r4, 0x2
	adds r5, 0x8
	subs r7, 0x1
	cmp r7, 0
	bge _0806B04C
	ldrh r0, [r6, 0xC]
	ldr r5, [sp, 0x8]
	strh r0, [r5]
	movs r5, 0
	mov r3, r8
	mov r2, r9
_0806B06A:
	ldr r0, [sp, 0xC]
	adds r1, r0, r5
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [sp, 0x10]
	adds r1, r0, r5
	adds r0, r2, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806B06A
_0806B084:
	movs r0, 0
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806AED8

	thumb_func_start sub_806B09C
sub_806B09C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r7, 0
	movs r2, 0
	mov r6, r8
	adds r6, 0x2
	mov r9, r8
_0806B0BA:
	movs r0, 0x64
	muls r0, r2
	ldr r1, _0806B0E4
	adds r0, r1
	ldr r3, _0806B0E8
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, 0x1
	ands r0, r1
	adds r2, 0x1
	mov r10, r2
	cmp r0, 0
	beq _0806B124
	lsrs r0, r1, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806B124
	movs r4, 0
	b _0806B0EE
	.align 2, 0
_0806B0E4: .4byte 0x00008df8
_0806B0E8: .4byte gRecruitedPokemonRef
_0806B0EC:
	adds r4, 0x1
_0806B0EE:
	cmp r4, r7
	bge _0806B106
	lsls r0, r4, 3
	add r0, r8
	bl sub_808E9B8
	lsls r0, 16
	asrs r0, 16
	movs r2, 0xE
	ldrsh r1, [r5, r2]
	cmp r0, r1
	bne _0806B0EC
_0806B106:
	cmp r4, r7
	bne _0806B124
	movs r3, 0xE
	ldrsh r2, [r5, r3]
	mov r0, r9
	movs r1, 0
	bl sub_808E9D8
	movs r0, 0
	strh r0, [r6]
	strh r0, [r6, 0x2]
	adds r6, 0x8
	movs r0, 0x8
	add r9, r0
	adds r7, 0x1
_0806B124:
	mov r2, r10
	cmp r2, 0x3
	ble _0806B0BA
	mov r0, r8
	adds r1, r7, 0
	bl sub_803D808
	adds r7, r0, 0
	ldr r1, [sp]
	cmp r1, 0
	beq _0806B150
	lsls r4, r7, 3
	add r4, r8
	ldr r2, _0806B164
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_808E9D8
	movs r0, 0
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	adds r7, 0x1
_0806B150:
	adds r0, r7, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806B164: .4byte 0x000001a5
	thumb_func_end sub_806B09C

	thumb_func_start sub_806B168
sub_806B168:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	ldr r0, _0806B324
	ldr r1, [r0]
	ldr r2, _0806B328
	adds r0, r1, r2
	movs r3, 0
	ldrsh r0, [r0, r3]
	ldr r4, _0806B32C
	adds r1, r4
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl sub_804954C
	ldrb r0, [r0, 0x9]
	str r0, [sp, 0x2C]
	movs r3, 0
	mov r4, sp
	adds r4, 0x1C
	str r4, [sp, 0x30]
	ldr r2, _0806B330
	ldr r1, _0806B334
_0806B19C:
	ldr r0, [r2]
	adds r0, r1
	strh r3, [r0, 0xC]
	adds r1, 0x64
	adds r3, 0x1
	cmp r3, 0x3
	ble _0806B19C
	movs r4, 0
	movs r3, 0
	ldr r0, _0806B324
	mov r8, r0
	ldr r0, _0806B330
	ldr r7, [r0]
	movs r5, 0x1
	add r6, sp, 0xC
_0806B1BA:
	movs r0, 0x64
	muls r0, r3
	ldr r1, _0806B334
	adds r0, r1
	adds r2, r7, r0
	ldrh r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0806B1DA
	lsrs r0, r1, 1
	ands r0, r5
	cmp r0, 0
	beq _0806B1DA
	stm r6!, {r2}
	adds r4, 0x1
_0806B1DA:
	adds r3, 0x1
	cmp r3, 0x3
	ble _0806B1BA
	cmp r4, 0x3
	bgt _0806B1F4
	movs r1, 0
	lsls r0, r4, 2
	add r0, sp
	adds r0, 0xC
_0806B1EC:
	stm r0!, {r1}
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806B1EC
_0806B1F4:
	movs r4, 0
	movs r6, 0
	add r2, sp, 0xC
	ldr r5, [sp, 0x30]
	movs r3, 0x3
_0806B1FE:
	ldr r1, [r2]
	cmp r1, 0
	beq _0806B210
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _0806B210
	str r6, [r2]
	stm r5!, {r1}
	adds r4, 0x1
_0806B210:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0806B1FE
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _0806B338
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806B24C
	movs r6, 0
	add r2, sp, 0xC
	lsls r0, r4, 2
	ldr r1, [sp, 0x30]
	adds r5, r0, r1
	movs r3, 0x3
_0806B232:
	ldr r1, [r2]
	cmp r1, 0
	beq _0806B244
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _0806B244
	str r6, [r2]
	stm r5!, {r1}
	adds r4, 0x1
_0806B244:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0806B232
_0806B24C:
	movs r5, 0
	add r2, sp, 0xC
	lsls r0, r4, 2
	ldr r3, [sp, 0x30]
	adds r0, r3
	movs r3, 0x3
_0806B258:
	ldr r1, [r2]
	cmp r1, 0
	beq _0806B264
	str r5, [r2]
	stm r0!, {r1}
	adds r4, 0x1
_0806B264:
	adds r2, 0x4
	subs r3, 0x1
	cmp r3, 0
	bge _0806B258
	cmp r4, 0x3
	bgt _0806B280
	movs r1, 0
	lsls r0, r4, 2
	ldr r2, [sp, 0x30]
	adds r0, r2
_0806B278:
	stm r0!, {r1}
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806B278
_0806B280:
	movs r3, 0
_0806B282:
	lsls r0, r3, 2
	ldr r4, [sp, 0x30]
	adds r0, r4, r0
	ldr r0, [r0]
	mov r8, r0
	adds r0, r3, 0x1
	str r0, [sp, 0x34]
	mov r1, r8
	cmp r1, 0
	bne _0806B298
	b _0806B3E8
_0806B298:
	movs r2, 0xE
	ldrsh r1, [r1, r2]
	ldr r0, _0806B33C
	cmp r1, r0
	beq _0806B2AE
	adds r0, 0x2
	cmp r1, r0
	beq _0806B2AE
	subs r0, 0x1
	cmp r1, r0
	bne _0806B2B6
_0806B2AE:
	movs r0, 0xBC
	lsls r0, 1
	mov r4, r8
	strh r0, [r4, 0xE]
_0806B2B6:
	ldr r0, _0806B340
	ldr r2, [r0]
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r3, 0x1
	str r3, [sp, 0x34]
	ldr r3, _0806B340
	cmp r0, 0x63
	beq _0806B350
	ldr r4, _0806B324
	mov r9, r4
	ldr r0, _0806B328
	mov r10, r0
	adds r5, r3, 0
_0806B2D2:
	lsls r0, r2, 16
	asrs r7, r0, 16
	mov r4, r9
	ldr r1, [r4]
	mov r4, r10
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r0, r7, r0
	asrs r6, r2, 16
	ldr r2, _0806B32C
	adds r1, r2
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r1, r6, r1
	str r3, [sp, 0x38]
	bl sub_804954C
	adds r1, r0, 0
	ldrb r0, [r1, 0x9]
	ldr r3, [sp, 0x38]
	ldr r2, [sp, 0x2C]
	cmp r0, r2
	bne _0806B344
	mov r4, r8
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r3, [sp, 0x38]
	cmp r4, 0
	bne _0806B344
	mov r3, r8
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	mov r3, r9
	ldr r2, [r3]
	mov r3, r10
	b _0806B3A8
	.align 2, 0
_0806B324: .4byte gDungeonGlobalData
_0806B328: .4byte 0x0000e218
_0806B32C: .4byte 0x0000e21a
_0806B330: .4byte gRecruitedPokemonRef
_0806B334: .4byte 0x00008df8
_0806B338: .4byte 0x0000065c
_0806B33C: .4byte 0x00000179
_0806B340: .4byte gUnknown_80F4598
_0806B344:
	adds r5, 0x4
	ldr r2, [r5]
	movs r4, 0
	ldrsh r0, [r5, r4]
	cmp r0, 0x63
	bne _0806B2D2
_0806B350:
	movs r0, 0
	cmp r0, 0
	bne _0806B3E8
	ldr r2, [r3]
	movs r1, 0
	ldrsh r0, [r3, r1]
	cmp r0, 0x63
	beq _0806B3E8
	ldr r3, _0806B3CC
	mov r9, r3
	ldr r5, _0806B3D0
_0806B366:
	lsls r0, r2, 16
	asrs r7, r0, 16
	mov r4, r9
	ldr r1, [r4]
	ldr r3, _0806B3D4
	adds r0, r1, r3
	movs r4, 0
	ldrsh r0, [r0, r4]
	adds r0, r7, r0
	asrs r6, r2, 16
	ldr r2, _0806B3D8
	adds r1, r2
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r1, r6, r1
	bl sub_804954C
	adds r1, r0, 0
	mov r4, r8
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0806B3DC
	mov r3, r8
	movs r1, 0xE
	ldrsh r0, [r3, r1]
	mov r3, r9
	ldr r2, [r3]
	ldr r3, _0806B3D4
_0806B3A8:
	adds r1, r2, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r1, r7, r1
	ldr r3, _0806B3D8
	adds r2, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r2, r6, r2
	str r4, [sp]
	movs r3, 0x1
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	mov r3, r8
	bl sub_806B8CC
	b _0806B3E8
	.align 2, 0
_0806B3CC: .4byte gDungeonGlobalData
_0806B3D0: .4byte gUnknown_80F4598
_0806B3D4: .4byte 0x0000e218
_0806B3D8: .4byte 0x0000e21a
_0806B3DC:
	adds r5, 0x4
	ldr r2, [r5]
	movs r4, 0
	ldrsh r0, [r5, r4]
	cmp r0, 0x63
	bne _0806B366
_0806B3E8:
	ldr r3, [sp, 0x34]
	cmp r3, 0x3
	bgt _0806B3F0
	b _0806B282
_0806B3F0:
	bl sub_806B678
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806B168

	thumb_func_start sub_806B404
sub_806B404:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	movs r5, 0
	movs r2, 0
	ldr r0, _0806B480
	mov r9, r0
	ldr r0, _0806B484
	ldr r7, [r0]
	movs r6, 0x1
	ldr r1, _0806B488
	mov r8, r1
_0806B422:
	movs r0, 0x64
	muls r0, r2
	ldr r3, _0806B48C
	adds r0, r3
	adds r3, r7, r0
	ldrh r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0806B446
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _0806B446
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	cmp r0, r8
	beq _0806B490
_0806B446:
	adds r2, 0x1
	cmp r2, 0x3
	ble _0806B422
_0806B44C:
	cmp r5, 0x3
	bgt _0806B460
	movs r1, 0
	lsls r0, r5, 2
	add r0, sp
	adds r0, 0xC
_0806B458:
	stm r0!, {r1}
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806B458
_0806B460:
	movs r0, 0
	mov r2, r9
	str r0, [r2]
	bl sub_8083600
	adds r5, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806B49C
	ldrh r0, [r5, 0x6]
	lsls r0, 16
	ldrh r4, [r5, 0x4]
	b _0806B4AE
	.align 2, 0
_0806B480: .4byte gUnknown_203B450
_0806B484: .4byte gRecruitedPokemonRef
_0806B488: .4byte 0x000055aa
_0806B48C: .4byte 0x00008df8
_0806B490:
	lsls r0, r5, 2
	add r0, sp
	adds r0, 0xC
	str r3, [r0]
	adds r5, 0x1
	b _0806B44C
_0806B49C:
	ldr r0, _0806B560
	ldr r0, [r0]
	ldr r3, _0806B564
	adds r1, r0, r3
	ldr r2, _0806B568
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 16
	ldrh r4, [r1]
_0806B4AE:
	orrs r4, r0
	lsls r5, r4, 16
	asrs r0, r5, 16
	asrs r4, 16
	adds r1, r4, 0
	bl sub_804954C
	ldrb r0, [r0, 0x9]
	str r0, [sp, 0x20]
	movs r2, 0
	str r5, [sp, 0x24]
	mov r10, r4
_0806B4C6:
	lsls r0, r2, 2
	add r0, sp
	adds r0, 0xC
	ldr r6, [r0]
	adds r2, 0x1
	str r2, [sp, 0x28]
	cmp r6, 0
	bne _0806B4D8
	b _0806B65E
_0806B4D8:
	ldrh r1, [r6]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0806B4E6
	b _0806B65E
_0806B4E6:
	lsrs r0, r1, 1
	ands r0, r2
	cmp r0, 0
	bne _0806B4F0
	b _0806B65E
_0806B4F0:
	movs r3, 0xA
	ldrsh r1, [r6, r3]
	ldr r0, _0806B56C
	cmp r1, r0
	beq _0806B4FC
	b _0806B65E
_0806B4FC:
	ldr r0, _0806B570
	strh r0, [r6, 0xA]
	movs r7, 0
	ldr r2, _0806B574
	ldr r0, [r2]
	str r0, [sp, 0x1C]
	add r0, sp, 0x1C
	movs r3, 0
	ldrsh r1, [r0, r3]
	mov r9, r2
	adds r2, r0, 0
	cmp r1, 0x63
	beq _0806B58C
	ldr r0, [sp, 0x24]
	asrs r0, 16
	mov r8, r0
_0806B51C:
	movs r1, 0
	ldrsh r0, [r2, r1]
	add r0, r8
	ldr r1, [sp, 0x1C]
	asrs r1, 16
	mov r5, r10
	adds r1, r5
	str r2, [sp, 0x2C]
	bl sub_804954C
	adds r1, r0, 0
	ldrb r0, [r1, 0x9]
	ldr r2, [sp, 0x2C]
	ldr r3, [sp, 0x20]
	cmp r0, r3
	bne _0806B578
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, [sp, 0x2C]
	cmp r4, 0
	bne _0806B578
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	add r1, r8
	ldr r2, [sp, 0x1C]
	asrs r2, 16
	adds r2, r5
	b _0806B642
	.align 2, 0
_0806B560: .4byte gDungeonGlobalData
_0806B564: .4byte 0x0000e218
_0806B568: .4byte 0x0000e21a
_0806B56C: .4byte 0x000055aa
_0806B570: .4byte 0x00005aa5
_0806B574: .4byte gUnknown_80F4598
_0806B578:
	adds r7, 0x1
	ldr r1, _0806B5E4
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x1C]
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x63
	bne _0806B51C
_0806B58C:
	movs r3, 0
	cmp r3, 0
	bne _0806B65E
	movs r7, 0
	mov r1, r9
	ldr r0, [r1]
	str r0, [sp, 0x1C]
	movs r3, 0
	ldrsh r0, [r2, r3]
	cmp r0, 0x63
	beq _0806B5FC
	ldr r0, [sp, 0x24]
	asrs r0, 16
	mov r8, r0
_0806B5A8:
	movs r1, 0
	ldrsh r0, [r2, r1]
	add r0, r8
	ldr r1, [sp, 0x1C]
	asrs r1, 16
	mov r5, r10
	adds r1, r5
	str r2, [sp, 0x2C]
	bl sub_804954C
	adds r1, r0, 0
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, [sp, 0x2C]
	cmp r4, 0
	bne _0806B5E8
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	add r1, r8
	ldr r2, [sp, 0x1C]
	asrs r2, 16
	adds r2, r5
	b _0806B642
	.align 2, 0
_0806B5E4: .4byte gUnknown_80F4598
_0806B5E8:
	adds r7, 0x1
	ldr r1, _0806B654
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x1C]
	movs r1, 0
	ldrsh r0, [r2, r1]
	cmp r0, 0x63
	bne _0806B5A8
_0806B5FC:
	movs r3, 0
	cmp r3, 0
	bne _0806B65E
	movs r7, 0
	adds r5, r2, 0
_0806B606:
	adds r0, r5, 0
	str r2, [sp, 0x2C]
	bl sub_8083660
	lsls r0, 24
	ldr r2, [sp, 0x2C]
	cmp r0, 0
	beq _0806B658
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	bl sub_804954C
	adds r1, r0, 0
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, [sp, 0x2C]
	cmp r4, 0
	bne _0806B658
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	movs r3, 0
	ldrsh r1, [r2, r3]
	movs r3, 0x2
	ldrsh r2, [r5, r3]
_0806B642:
	str r4, [sp]
	movs r3, 0x1
	str r3, [sp, 0x4]
	str r4, [sp, 0x8]
	adds r3, r6, 0
	bl sub_806B8CC
	b _0806B65E
	.align 2, 0
_0806B654: .4byte gUnknown_80F4598
_0806B658:
	adds r7, 0x1
	cmp r7, 0x63
	ble _0806B606
_0806B65E:
	ldr r2, [sp, 0x28]
	cmp r2, 0x3
	bgt _0806B666
	b _0806B4C6
_0806B666:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806B404

	thumb_func_start sub_806B678
sub_806B678:
	push {r4,r5,lr}
	movs r5, 0
_0806B67C:
	ldr r0, _0806B6AC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806B6B0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806B6B8
	ldr r0, [r4, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	beq _0806B6B8
	adds r0, r4, 0
	bl sub_803F4A0
	ldr r1, _0806B6B4
	ldr r0, [r4, 0x4]
	str r0, [r1]
	b _0806B6BE
	.align 2, 0
_0806B6AC: .4byte gDungeonGlobalData
_0806B6B0: .4byte 0x0001357c
_0806B6B4: .4byte gUnknown_202EE0C
_0806B6B8:
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806B67C
_0806B6BE:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806B678

	thumb_func_start sub_806B6C4
sub_806B6C4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r4, _0806B708
	ldr r0, [r4]
	movs r1, 0xD1
	lsls r1, 3
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r8, r0
	movs r0, 0x7A
	bl sub_80860A8
	lsls r0, 24
	cmp r0, 0
	beq _0806B710
	movs r0, 0x97
	bl HasRecruitedMon
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0806B710
	ldr r0, [r4]
	ldr r2, _0806B70C
	adds r0, r2
	b _0806B71A
	.align 2, 0
_0806B708: .4byte gDungeonGlobalData
_0806B70C: .4byte 0x000037ff
_0806B710:
	ldr r0, _0806B77C
	ldr r0, [r0]
	ldr r1, _0806B780
	adds r0, r1
	movs r1, 0x1
_0806B71A:
	strb r1, [r0]
	movs r0, 0x38
	bl DungeonRandomCapped
	adds r5, r0, 0
	movs r0, 0x20
	bl DungeonRandomCapped
	adds r7, r0, 0
	movs r0, 0
_0806B72E:
	adds r7, 0x1
	cmp r7, 0x20
	bne _0806B736
	movs r7, 0
_0806B736:
	adds r0, 0x1
	mov r10, r0
	mov r4, sp
	movs r2, 0x37
	mov r9, r2
_0806B740:
	adds r5, 0x1
	cmp r5, 0x38
	bne _0806B748
	movs r5, 0
_0806B748:
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_804954C
	ldrh r1, [r0, 0x4]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806B7C2
	movs r6, 0
	mov r0, r8
	cmp r0, 0
	beq _0806B784
	ldr r0, _0806B77C
	ldr r0, [r0]
	movs r1, 0xD1
	lsls r1, 3
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	movs r1, 0x1
	movs r0, 0x1
	strh r0, [r4, 0x8]
	strb r1, [r4, 0x2]
	movs r6, 0x1
	b _0806B794
	.align 2, 0
_0806B77C: .4byte gDungeonGlobalData
_0806B780: .4byte 0x000037ff
_0806B784:
	movs r0, 0
	bl sub_803D970
	movs r1, 0
	strh r0, [r4]
	mov r2, r8
	strh r2, [r4, 0x8]
	strb r1, [r4, 0x2]
_0806B794:
	movs r0, 0
	str r0, [sp, 0x4]
	strb r0, [r4, 0x10]
	strh r5, [r4, 0xC]
	strh r7, [r4, 0xE]
	cmp r6, 0
	bne _0806B7B2
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x1
	bl sub_806AA0C
	lsls r0, 24
	cmp r0, 0
	beq _0806B7C2
_0806B7B2:
	mov r0, sp
	movs r1, 0
	bl sub_806B7F8
	cmp r0, 0
	beq _0806B7C2
	movs r2, 0
	mov r8, r2
_0806B7C2:
	movs r0, 0x1
	negs r0, r0
	add r9, r0
	mov r1, r9
	cmp r1, 0
	bge _0806B740
	mov r0, r10
	cmp r0, 0x1F
	ble _0806B72E
	mov r2, r8
	cmp r2, 0
	beq _0806B7E2
	ldr r0, _0806B7F4
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0xA]
_0806B7E2:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806B7F4: .4byte gDungeonGlobalData
	thumb_func_end sub_806B6C4

	thumb_func_start sub_806B7F8
sub_806B7F8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0xC
	ldrsh r0, [r6, r1]
	movs r2, 0xE
	ldrsh r1, [r6, r2]
	bl sub_804954C
	adds r1, r0, 0
	movs r3, 0
	ldrsh r0, [r6, r3]
	bl sub_807034C
	lsls r0, 24
	cmp r0, 0
	bne _0806B834
	movs r4, 0
	ldrsh r0, [r6, r4]
	bl sub_804550C
	adds r7, r0, 0
	cmp r7, 0
	bne _0806B838
_0806B834:
	movs r0, 0
	b _0806B8B8
_0806B838:
	ldr r3, _0806B8C8
	movs r0, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_806BC68
	ldr r5, [r7, 0x70]
	movs r0, 0x1
	strb r0, [r5, 0x6]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r5, 0
	adds r1, 0x10
	adds r2, r5, 0
	adds r2, 0x14
	movs r3, 0x16
	adds r3, r5
	mov r9, r3
	movs r3, 0x2
	ldrsh r4, [r5, r3]
	str r4, [sp]
	ldrb r4, [r5, 0x9]
	str r4, [sp, 0x4]
	mov r3, r9
	bl sub_806AED8
	ldrh r0, [r5, 0x10]
	strh r0, [r5, 0xE]
	movs r4, 0x8A
	lsls r4, 1
	adds r1, r5, r4
	ldr r0, [r6, 0x4]
	str r0, [r1]
	ldrb r0, [r6, 0x2]
	cmp r0, 0
	bne _0806B8B6
	mov r0, r8
	cmp r0, 0
	bne _0806B8B6
	ldrb r0, [r6, 0x10]
	cmp r0, 0
	bne _0806B8B6
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r6, r1]
	bl GetUnk1D
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	ble _0806B8B6
	adds r0, r7, 0
	movs r1, 0x7F
	bl sub_8075BF4
	adds r0, r7, 0
	movs r1, 0x8
	bl sub_806CE68
_0806B8B6:
	adds r0, r7, 0
_0806B8B8:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806B8C8: .4byte gUnknown_202EE0C
	thumb_func_end sub_806B7F8

	thumb_func_start sub_806B8CC
sub_806B8CC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r9, r1
	mov r10, r2
	adds r5, r3, 0
	ldr r1, [sp, 0x50]
	ldr r2, [sp, 0x54]
	lsls r0, 16
	asrs r4, r0, 16
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x18]
	ldrb r1, [r5, 0x2]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	mov r8, r0
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0806B906
	movs r0, 0
	ldr r1, [sp, 0x4C]
	str r0, [r1]
_0806B906:
	adds r0, r4, 0
	bl GetBaseSpecies
	lsls r0, 16
	asrs r1, r0, 16
	movs r0, 0xCF
	lsls r0, 1
	cmp r1, r0
	bne _0806B932
	cmp r6, 0
	beq _0806B930
	ldr r0, _0806B92C
	ldr r0, [r0]
	movs r2, 0xE0
	lsls r2, 6
	adds r0, r2
	movs r3, 0
	ldrsh r4, [r0, r3]
	b _0806B932
	.align 2, 0
_0806B92C: .4byte gDungeonGlobalData
_0806B930:
	adds r4, r1, 0
_0806B932:
	mov r0, r9
	mov r1, r10
	bl sub_804954C
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_807034C
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0806B956
	adds r0, r4, 0
	bl sub_80453AC
	str r0, [sp, 0x1C]
	cmp r0, 0
	bne _0806B95A
_0806B956:
	movs r0, 0
	b _0806BB3C
_0806B95A:
	mov r0, sp
	movs r7, 0
	mov r1, r9
	strh r1, [r0, 0xC]
	mov r2, r10
	strh r2, [r0, 0xE]
	strh r4, [r0]
	mov r1, sp
	ldrb r0, [r5, 0x3]
	strh r0, [r1, 0x8]
	mov r0, sp
	strb r7, [r0, 0x2]
	str r6, [sp, 0x4]
	strb r7, [r0, 0x10]
	ldr r4, _0806BB4C
	ldr r3, _0806BB50
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0]
	add r0, r9
	lsls r0, 16
	lsrs r0, 16
	ldr r2, _0806BB54
	ldr r1, [sp, 0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x14]
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r4
	ldrh r0, [r0, 0x2]
	add r0, r10
	lsls r0, 16
	ldr r2, _0806BB58
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x14]
	ldr r3, _0806BB5C
	mov r0, r8
	cmp r0, 0
	beq _0806B9B0
	add r3, sp, 0x14
_0806B9B0:
	movs r0, 0x1
	ldr r1, [sp, 0x1C]
	mov r2, sp
	bl sub_806BC68
	ldr r1, [sp, 0x1C]
	ldr r4, [r1, 0x70]
	strb r7, [r4, 0x6]
	strb r7, [r4, 0x8]
	mov r2, r8
	strb r2, [r4, 0x7]
	adds r0, r4, 0
	adds r0, 0xF9
	mov r3, sp
	ldrb r3, [r3, 0x18]
	strb r3, [r0]
	ldr r0, _0806BB60
	str r6, [r0]
	mov r6, r8
	cmp r6, 0
	beq _0806B9E4
	ldr r0, _0806BB5C
	mov r7, r9
	strh r7, [r0]
	mov r1, r10
	strh r1, [r0, 0x2]
_0806B9E4:
	ldrh r0, [r5, 0x10]
	strh r0, [r4, 0xE]
	ldrh r0, [r5, 0x12]
	strh r0, [r4, 0x10]
	ldr r0, [r5, 0x18]
	str r0, [r4, 0x18]
	movs r3, 0
	movs r2, 0x1C
	adds r2, r5
	mov r8, r2
	movs r6, 0x50
	adds r6, r5
	mov r10, r6
	movs r7, 0x94
	adds r7, r4
	mov r9, r7
	adds r0, r4, 0
	adds r0, 0x8C
	str r0, [sp, 0x20]
	adds r1, r4, 0
	adds r1, 0xF3
	str r1, [sp, 0x24]
	adds r2, r4, 0
	adds r2, 0x64
	str r2, [sp, 0x28]
	movs r6, 0x14
	adds r6, r4
	mov r12, r6
	adds r7, r5, 0
	adds r7, 0x14
	adds r6, r4, 0
	adds r6, 0x16
	adds r2, r5, 0
	adds r2, 0x16
_0806BA28:
	mov r0, r12
	adds r1, r0, r3
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r6, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, 0x1
	ble _0806BA28
	movs r1, 0x8C
	lsls r1, 1
	adds r2, r4, r1
	adds r1, r2, 0
	mov r0, r8
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	ldm r0!, {r3,r6,r7}
	stm r1!, {r3,r6,r7}
	movs r0, 0x1
	mov r8, r0
	movs r7, 0xEF
	movs r6, 0xDF
	movs r3, 0x3
_0806BA60:
	ldrb r1, [r2]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0806BA72
	adds r0, r7, 0
	ands r0, r1
	ands r0, r6
	strb r0, [r2]
_0806BA72:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0806BA60
	movs r1, 0x9C
	lsls r1, 1
	adds r2, r4, r1
	ldrb r1, [r2]
	movs r0, 0xEF
	ands r0, r1
	movs r1, 0xDF
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r5, 0x3]
	strb r0, [r4, 0x9]
	ldrh r0, [r5, 0x8]
	movs r2, 0
	strh r0, [r4, 0xC]
	mov r3, r10
	ldrb r0, [r3]
	mov r6, r9
	strb r0, [r6]
	ldr r0, [r5, 0x4C]
	ldr r7, [sp, 0x20]
	str r0, [r7]
	ldr r0, [r5, 0x54]
	str r0, [r4, 0x3C]
	ldr r0, [r5, 0x4]
	str r0, [r4, 0x40]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, [r5, 0x44]
	str r0, [r1]
	movs r3, 0xA0
	lsls r3, 1
	adds r1, r4, r3
	ldr r0, [r5, 0x48]
	str r0, [r1]
	ldrh r0, [r5, 0xC]
	strb r0, [r4, 0xA]
	ldr r0, [r5, 0x40]
	str r0, [r4, 0x60]
	ldr r0, [sp, 0x24]
	strb r2, [r0]
	ldr r6, [sp, 0x28]
	strb r2, [r6]
	ldr r7, _0806BB64
	ldr r0, [r7]
	ldr r1, _0806BB68
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806BB24
	bl sub_80441BC
	lsls r0, 24
	cmp r0, 0
	bne _0806BB24
	adds r0, r4, 0
	adds r0, 0x5E
	ldrb r0, [r0]
	cmp r0, 0x47
	beq _0806BAFC
	adds r0, r4, 0
	adds r0, 0x5F
	ldrb r0, [r0]
	cmp r0, 0x47
	bne _0806BB24
_0806BAFC:
	adds r4, 0x60
	ldrb r1, [r4]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _0806BB24
	movs r0, 0
	bl sub_803D73C
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x69
	beq _0806BB24
	adds r0, r4, 0
	movs r2, 0
	bl xxx_init_itemslot_8090A8C
	ldr r2, [sp, 0x24]
	strb r5, [r2]
_0806BB24:
	ldr r0, [sp, 0x1C]
	bl sub_806A6E8
	ldr r0, [sp, 0x1C]
	bl sub_807191C
	ldr r3, [sp, 0x4C]
	cmp r3, 0
	beq _0806BB3A
	ldr r6, [sp, 0x1C]
	str r6, [r3]
_0806BB3A:
	movs r0, 0x1
_0806BB3C:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806BB4C: .4byte gUnknown_80F4448
_0806BB50: .4byte gUnknown_202F32C
_0806BB54: .4byte 0xffff0000
_0806BB58: .4byte 0x0000ffff
_0806BB5C: .4byte gUnknown_202EE0C
_0806BB60: .4byte gUnknown_203B450
_0806BB64: .4byte gDungeonGlobalData
_0806BB68: .4byte 0x00000644
	thumb_func_end sub_806B8CC

	thumb_func_start sub_806BB6C
sub_806BB6C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r7, r0, 0
	lsls r4, r1, 16
	asrs r4, 16
	ldr r0, [r7, 0x70]
	mov r9, r0
	mov r8, r9
	adds r0, 0x98
	ldr r0, [r0]
	bl sub_800F934
	add r0, sp, 0x8
	movs r1, 0
	mov r10, r1
	movs r6, 0
	lsls r5, r4, 16
	lsrs r5, 16
	strh r5, [r0]
	strh r6, [r0, 0x8]
	mov r2, r10
	strb r2, [r0, 0x2]
	ldr r0, [r7, 0x4]
	str r0, [sp, 0x14]
	str r6, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	bl sub_8069F54
	lsls r0, 16
	adds r1, r7, 0
	adds r1, 0x22
	mov r2, r10
	strb r2, [r1]
	ldr r1, [r7, 0x70]
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1, 0x4]
	ldr r0, [r7, 0x70]
	strh r5, [r0, 0x2]
	adds r0, r2, 0
	bl sub_80687D0
	str r0, [r7, 0x64]
	adds r1, r7, 0
	adds r1, 0x6A
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6C
	mov r5, r10
	strb r5, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r1, 0x2
	movs r0, 0x1
	strb r0, [r1]
	adds r1, 0x2
	strb r0, [r1]
	str r6, [r7, 0x1C]
	mov r0, r9
	adds r0, 0xB0
	ldrb r0, [r0]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806BC08
	mov r0, r9
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_0806BC08:
	movs r1, 0
	mov r6, r9
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _0806BC14
	movs r1, 0x1
_0806BC14:
	adds r0, r1, 0
	adds r1, r7, 0
	add r2, sp, 0x8
	movs r3, 0
	bl sub_806BC68
	movs r0, 0x8C
	lsls r0, 1
	add r0, r8
	mov r1, r8
	adds r1, 0x10
	mov r2, r8
	adds r2, 0x14
	mov r3, r8
	adds r3, 0x16
	mov r5, r8
	movs r6, 0x2
	ldrsh r4, [r5, r6]
	str r4, [sp]
	ldrb r4, [r5, 0x9]
	str r4, [sp, 0x4]
	bl sub_806AED8
	ldrh r0, [r5, 0x10]
	strh r0, [r5, 0xE]
	mov r0, r10
	strb r0, [r5, 0x8]
	adds r0, r7, 0
	bl sub_80429E8
	adds r0, r7, 0
	bl sub_80418D4
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806BB6C

	thumb_func_start sub_806BC68
sub_806BC68:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r4, r0, 0
	mov r8, r1
	adds r7, r2, 0
	mov r10, r3
	lsls r4, 24
	lsrs r4, 24
	ldr r1, _0806BD0C
	ldr r0, [r1]
	movs r5, 0
	movs r2, 0x1
	mov r9, r2
	mov r3, r9
	strb r3, [r0, 0xC]
	mov r0, r8
	ldr r6, [r0, 0x70]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_806BFC0
	ldrb r1, [r7, 0x2]
	adds r0, r6, 0
	adds r0, 0xA4
	strb r1, [r0]
	mov r0, r8
	adds r0, 0x20
	mov r1, r9
	strb r1, [r0]
	adds r0, 0x2
	strb r5, [r0]
	ldr r0, _0806BD10
	mov r2, r8
	strh r0, [r2, 0x8]
	movs r0, 0x1
	negs r0, r0
	strh r0, [r2, 0xA]
	ldr r0, _0806BD14
	strh r0, [r2, 0x4]
	strh r0, [r2, 0x6]
	movs r3, 0xC
	ldrsh r1, [r7, r3]
	movs r0, 0xE
	ldrsh r2, [r7, r0]
	mov r0, r8
	movs r3, 0x1
	bl sub_80694C0
	mov r0, r8
	movs r1, 0
	bl sub_804535C
	cmp r4, 0
	bne _0806BD5E
	movs r2, 0
	ldrsh r1, [r7, r2]
	movs r0, 0xBE
	lsls r0, 1
	cmp r1, r0
	bne _0806BD20
	ldr r3, _0806BD0C
	ldr r1, [r3]
	ldr r4, _0806BD18
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806BD20
	ldr r2, _0806BD1C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806BD20
	ldrb r0, [r7, 0x2]
	cmp r0, 0
	bne _0806BD20
	mov r3, r9
	strb r3, [r6, 0x8]
	b _0806BD24
	.align 2, 0
_0806BD0C: .4byte gDungeonGlobalData
_0806BD10: .4byte 0x0000ffff
_0806BD14: .4byte 0x0000fffe
_0806BD18: .4byte 0x0000066e
_0806BD1C: .4byte 0x00003a0a
_0806BD20:
	movs r0, 0
	strb r0, [r6, 0x8]
_0806BD24:
	movs r4, 0x2
	ldrsh r0, [r6, r4]
	bl GetBaseSpecies
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	bne _0806BD42
	ldr r0, _0806BD94
	ldr r0, [r0]
	ldr r1, _0806BD98
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_0806BD42:
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	bl GetBaseSpecies
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x97
	bne _0806BD5E
	ldr r0, _0806BD94
	ldr r0, [r0]
	ldr r3, _0806BD9C
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
_0806BD5E:
	adds r2, r6, 0
	adds r2, 0x98
	ldr r0, _0806BD94
	ldr r1, [r0]
	ldr r4, _0806BDA0
	adds r1, r4
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	adds r1, r6, 0
	adds r1, 0x9C
	movs r0, 0
	str r0, [r1]
	ldrh r1, [r7, 0x8]
	movs r3, 0x8
	ldrsh r0, [r7, r3]
	mov r9, r2
	cmp r0, 0
	bne _0806BDA4
	movs r4, 0
	ldrsh r0, [r7, r4]
	bl sub_803DA20
	strb r0, [r6, 0x9]
	b _0806BDA6
	.align 2, 0
_0806BD94: .4byte gDungeonGlobalData
_0806BD98: .4byte 0x000037fd
_0806BD9C: .4byte 0x000037ff
_0806BDA0: .4byte 0x000037f0
_0806BDA4:
	strb r1, [r6, 0x9]
_0806BDA6:
	movs r0, 0x8A
	lsls r0, 1
	adds r1, r6, r0
	ldr r0, [r7, 0x4]
	str r0, [r1]
	movs r4, 0x1
	strh r4, [r6, 0xC]
	adds r0, r6, 0
	adds r0, 0x8C
	movs r1, 0
	bl sub_808EC94
	adds r0, r6, 0
	adds r0, 0x3C
	bl sub_808E6F4
	strh r4, [r6, 0x10]
	strh r4, [r6, 0xE]
	mov r0, sp
	movs r1, 0x64
	bl sub_80943A0
	movs r2, 0x9E
	lsls r2, 1
	adds r1, r6, r2
	ldr r0, [sp]
	str r0, [r1]
	add r0, sp, 0x4
	movs r1, 0x64
	bl sub_80943A0
	movs r3, 0xA0
	lsls r3, 1
	adds r1, r6, r3
	ldr r0, [sp, 0x4]
	str r0, [r1]
	mov r4, r10
	cmp r4, 0
	beq _0806BE00
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r6, r0
	ldr r0, [r4]
	str r0, [r1]
	b _0806BE12
_0806BE00:
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r6, r1
	mov r2, r10
	strh r2, [r0]
	movs r3, 0xB7
	lsls r3, 1
	adds r0, r6, r3
	strh r2, [r0]
_0806BE12:
	movs r7, 0
	movs r4, 0
	strh r4, [r6]
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r6, r1
	strb r7, [r0]
	ldr r2, _0806BFB4
	adds r0, r6, r2
	strb r7, [r0]
	movs r3, 0xFA
	lsls r3, 1
	adds r0, r6, r3
	strh r4, [r0]
	adds r1, 0xB2
	adds r0, r6, r1
	strh r4, [r0]
	adds r0, r6, 0
	adds r0, 0x78
	strb r7, [r0]
	adds r1, r6, 0
	adds r1, 0x88
	mov r2, r8
	ldr r0, [r2, 0x4]
	str r0, [r1]
	adds r0, r6, 0
	adds r0, 0x80
	str r4, [r0]
	adds r0, 0x4
	str r4, [r0]
	subs r0, 0x8
	strh r4, [r0]
	adds r0, 0x83
	strb r7, [r0]
	subs r3, 0x80
	adds r0, r6, r3
	str r4, [r0]
	movs r1, 0x80
	lsls r1, 1
	adds r0, r6, r1
	strb r7, [r0]
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_806BFC0
	adds r0, r6, 0
	adds r0, 0x60
	strb r7, [r0, 0x2]
	strb r7, [r0, 0x1]
	strb r7, [r0]
	adds r0, 0x4
	strb r7, [r0]
	movs r2, 0x80
	lsls r2, 2
	adds r0, r6, r2
	str r4, [r0]
	movs r3, 0xB2
	lsls r3, 1
	adds r1, r6, r3
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, 0x66
	adds r1, r6, r0
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r6, r1
	str r4, [r0]
	subs r2, 0xB9
	adds r0, r6, r2
	strb r7, [r0]
	subs r3, 0x1E
	adds r0, r6, r3
	strb r7, [r0]
	subs r1, 0x96
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, 0xB1
	adds r0, r6, r2
	strh r4, [r0]
	adds r3, 0xB4
	adds r0, r6, r3
	strh r4, [r0]
	subs r1, 0x1E
	adds r0, r6, r1
	strb r7, [r0]
	subs r2, 0xAF
	adds r0, r6, r2
	strb r7, [r0]
	subs r3, 0x82
	adds r0, r6, r3
	strh r4, [r0]
	adds r0, r6, 0
	adds r0, 0xFA
	strb r7, [r0]
	adds r0, 0x2
	strb r7, [r0]
	adds r1, 0x3
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, 0x3
	adds r0, r6, r2
	movs r5, 0x1
	strb r5, [r0]
	subs r3, 0x2A
	adds r0, r6, r3
	strh r4, [r0]
	adds r1, 0x5
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, 0x6
	adds r0, r6, r2
	strb r7, [r0]
	adds r3, 0x5
	adds r0, r6, r3
	strb r7, [r0]
	movs r4, 0xAA
	lsls r4, 1
	adds r0, r6, r4
	strb r7, [r0]
	adds r1, 0x5
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, 0x17
	adds r0, r6, r2
	strb r7, [r0]
	adds r0, r6, 0
	adds r0, 0xFD
	strb r7, [r0]
	adds r1, r6, 0
	adds r1, 0xFE
	movs r0, 0x63
	strb r0, [r1]
	adds r3, 0x5
	adds r0, r6, r3
	strb r7, [r0]
	adds r4, 0x5
	adds r0, r6, r4
	strb r7, [r0]
	movs r1, 0xAD
	lsls r1, 1
	adds r0, r6, r1
	strb r7, [r0]
	mov r0, r8
	bl sub_8070774
	movs r2, 0xAB
	lsls r2, 1
	adds r1, r6, r2
	strb r5, [r1]
	movs r3, 0xAE
	lsls r3, 1
	adds r0, r6, r3
	strb r7, [r0]
	adds r4, 0x5
	adds r0, r6, r4
	strb r7, [r0]
	adds r2, 0x7
	adds r0, r6, r2
	strb r7, [r0]
	adds r3, 0x3
	adds r0, r6, r3
	strb r7, [r0]
	adds r4, 0x2
	adds r0, r6, r4
	strb r7, [r0]
	ldrh r0, [r6, 0x4]
	subs r0, 0x32
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bhi _0806BF70
	strb r7, [r1]
_0806BF70:
	mov r0, r8
	ldrh r1, [r0, 0x6]
	lsls r1, 16
	ldrh r0, [r0, 0x4]
	orrs r0, r1
	str r0, [sp, 0x8]
	mov r1, r9
	ldr r0, [r1]
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	add r2, sp, 0x8
	ldr r3, _0806BFB8
	ldr r3, [r3]
	ldr r4, _0806BFBC
	adds r3, r4
	ldrb r3, [r3]
	bl sub_800F8D0
	mov r0, r8
	bl sub_807191C
	mov r0, r8
	movs r1, 0
	movs r2, 0
	bl sub_806A898
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806BFB4: .4byte 0x00000145
_0806BFB8: .4byte gDungeonGlobalData
_0806BFBC: .4byte 0x00018208
	thumb_func_end sub_806BC68

	thumb_func_start sub_806BFC0
sub_806BFC0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	adds r1, r4, 0
	adds r1, 0xA8
	movs r0, 0
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x8
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r2, r4, 0
	adds r2, 0xB4
	movs r1, 0x22
	str r1, [r2]
	adds r1, r4, 0
	adds r1, 0xBC
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x9
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x2
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x4
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x3
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	adds r1, 0x1
	strb r0, [r1]
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0xFF
	strb r0, [r1]
	ldr r2, _0806C168
	adds r1, r4, r2
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1]
	movs r1, 0
	movs r7, 0x84
	lsls r7, 1
	adds r0, r4, r7
	movs r5, 0x4
_0806C080:
	strb r1, [r0]
	strb r1, [r0, 0x5]
	adds r0, 0x1
	subs r5, 0x1
	cmp r5, 0
	bge _0806C080
	movs r0, 0
	str r0, [sp, 0x4]
	movs r5, 0
	adds r1, r4, 0
	adds r1, 0x5E
	str r1, [sp, 0x8]
	movs r2, 0x5C
	adds r2, r4
	mov r10, r2
	adds r7, r4, 0
	adds r7, 0xFD
	str r7, [sp, 0x20]
	adds r0, r4, 0
	adds r0, 0xF4
	str r0, [sp, 0xC]
	adds r1, 0x9D
	str r1, [sp, 0x1C]
	adds r2, r4, 0
	adds r2, 0xF5
	str r2, [sp, 0x10]
	subs r7, 0x7
	str r7, [sp, 0x14]
	adds r0, 0x3
	str r0, [sp, 0x18]
	adds r1, 0x4
	str r1, [sp, 0x24]
	movs r2, 0x1
	mov r9, r2
	movs r3, 0xA
	subs r7, 0xC2
	str r7, [sp, 0x28]
	subs r0, 0xCB
	str r0, [sp, 0x2C]
	adds r2, r4, 0
	adds r2, 0x24
	subs r1, 0xDF
	str r1, [sp, 0x38]
	adds r6, r4, 0
	adds r6, 0x1C
	movs r7, 0x80
	lsls r7, 1
	mov r8, r7
_0806C0E0:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	adds r1, r5, 0
	str r2, [sp, 0x30]
	str r3, [sp, 0x34]
	bl GetPokemonAbility
	ldr r7, [sp, 0x8]
	adds r1, r7, r5
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x30]
	ldr r3, [sp, 0x34]
	cmp r0, 0x25
	bne _0806C104
	movs r0, 0x1
	str r0, [sp, 0x4]
_0806C104:
	ldr r1, [sp]
	cmp r1, 0
	beq _0806C11E
	adds r0, r4, 0
	adds r0, 0x14
	adds r0, r5
	mov r7, r9
	strb r7, [r0]
	adds r0, r4, 0
	adds r0, 0x16
	adds r0, r5
	mov r1, r9
	strb r1, [r0]
_0806C11E:
	strh r3, [r6]
	ldr r7, [sp, 0x38]
	strh r3, [r7]
	strh r3, [r2]
	ldr r1, [sp, 0x2C]
	mov r0, r8
	stm r1!, {r0}
	str r1, [sp, 0x2C]
	ldr r7, [sp, 0x28]
	stm r7!, {r0}
	str r7, [sp, 0x28]
	adds r2, 0x2
	ldr r0, [sp, 0x38]
	adds r0, 0x2
	str r0, [sp, 0x38]
	adds r6, 0x2
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806C0E0
	ldr r1, [sp, 0x4]
	cmp r1, 0
	beq _0806C170
	movs r0, 0
	bl sub_807E580
	ldr r1, _0806C16C
	lsls r0, 24
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	mov r2, r10
	strb r0, [r2]
	adds r0, r4, 0
	adds r0, 0x5D
	strb r1, [r0]
	b _0806C188
	.align 2, 0
_0806C168: .4byte 0x00000165
_0806C16C: .4byte gUnknown_80F520C
_0806C170:
	movs r5, 0
_0806C172:
	movs r7, 0x2
	ldrsh r0, [r4, r7]
	adds r1, r5, 0
	bl GetPokemonType
	mov r2, r10
	adds r1, r2, r5
	strb r0, [r1]
	adds r5, 0x1
	cmp r5, 0x1
	ble _0806C172
_0806C188:
	ldr r0, _0806C1D0
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1, 0xC]
	movs r0, 0
	strh r2, [r4, 0x28]
	movs r7, 0x89
	lsls r7, 1
	adds r1, r4, r7
	strb r0, [r1]
	ldr r1, [sp, 0x20]
	strb r0, [r1]
	ldr r2, _0806C1D4
	adds r1, r4, r2
	strb r0, [r1]
	ldr r7, [sp, 0xC]
	strb r0, [r7]
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldr r2, [sp, 0x10]
	strb r0, [r2]
	ldr r7, [sp, 0x14]
	strb r0, [r7]
	ldr r1, [sp, 0x18]
	strb r0, [r1]
	ldr r2, [sp, 0x24]
	strb r0, [r2]
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C1D0: .4byte gDungeonGlobalData
_0806C1D4: .4byte 0x00000113
	thumb_func_end sub_806BFC0

	thumb_func_start sub_806C1D8
sub_806C1D8:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
_0806C1E2:
	ldr r0, _0806C258
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806C25C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r5, 0x1
	mov r9, r5
	cmp r0, 0
	beq _0806C244
	ldr r4, [r4, 0x70]
	ldrb r6, [r4, 0xA]
	cmp r6, 0
	blt _0806C244
	movs r5, 0
	movs r0, 0x8C
	lsls r0, 1
	mov r12, r0
	movs r2, 0x1
	mov r8, r2
	adds r3, r4, 0
	movs r7, 0xFE
_0806C218:
	lsls r0, r5, 3
	adds r0, r4
	add r0, r12
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0806C234
	ldr r0, _0806C260
	adds r2, r3, r0
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r2]
_0806C234:
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806C218
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_806C264
_0806C244:
	mov r5, r9
	cmp r5, 0x3
	ble _0806C1E2
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C258: .4byte gDungeonGlobalData
_0806C25C: .4byte 0x0001357c
_0806C260: .4byte 0x00000119
	thumb_func_end sub_806C1D8

	thumb_func_start sub_806C264
sub_806C264:
	push {r4,r5,lr}
	mov r12, r1
	ldr r2, _0806C31C
	movs r1, 0x64
	muls r0, r1
	ldr r1, _0806C320
	adds r0, r1
	ldr r1, [r2]
	adds r3, r1, r0
	mov r2, r12
	ldrh r0, [r2, 0xE]
	strh r0, [r3, 0x10]
	ldrh r0, [r2, 0x10]
	strh r0, [r3, 0x12]
	ldr r0, [r2, 0x18]
	str r0, [r3, 0x18]
	adds r2, 0x14
	adds r1, r3, 0
	adds r1, 0x14
	movs r4, 0x1
_0806C28C:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, 0x2]
	strb r0, [r1, 0x2]
	adds r2, 0x1
	adds r1, 0x1
	subs r4, 0x1
	cmp r4, 0
	bge _0806C28C
	ldr r4, _0806C324
	adds r0, r4, 0
	mov r5, r12
	ldrh r5, [r5, 0x4]
	adds r0, r5
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0806C2B6
	movs r0, 0xBC
	lsls r0, 1
	strh r0, [r3, 0xE]
_0806C2B6:
	adds r1, r3, 0
	adds r1, 0x1C
	movs r0, 0x8C
	lsls r0, 1
	add r0, r12
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	mov r1, r12
	ldrb r0, [r1, 0x9]
	strb r0, [r3, 0x3]
	ldrh r0, [r1, 0xC]
	strh r0, [r3, 0x8]
	mov r0, r12
	adds r0, 0x8C
	ldr r0, [r0]
	str r0, [r3, 0x4C]
	mov r0, r12
	adds r0, 0x94
	ldrb r1, [r0]
	adds r0, r3, 0
	adds r0, 0x50
	strb r1, [r0]
	mov r2, r12
	ldr r0, [r2, 0x3C]
	str r0, [r3, 0x54]
	movs r0, 0x9E
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	str r0, [r3, 0x44]
	movs r0, 0xA0
	lsls r0, 1
	add r0, r12
	ldr r0, [r0]
	str r0, [r3, 0x48]
	ldr r0, [r2, 0x60]
	str r0, [r3, 0x40]
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	ldr r0, _0806C328
	cmp r1, r0
	bne _0806C316
	ldr r0, _0806C32C
	strh r0, [r3, 0xA]
_0806C316:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806C31C: .4byte gRecruitedPokemonRef
_0806C320: .4byte 0x00008df8
_0806C324: .4byte 0xfffffe87
_0806C328: .4byte 0x000055aa
_0806C32C: .4byte 0x00005aa5
	thumb_func_end sub_806C264

	thumb_func_start sub_806C330
sub_806C330:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 16
	asrs r2, 16
	mov r12, r2
	lsls r3, 24
	lsrs r7, r3, 24
	ldr r0, _0806C370
	ldr r0, [r0]
	ldr r1, _0806C374
	adds r2, r0, r1
	movs r3, 0
	ldr r0, [r2, 0x40]
	cmp r3, r0
	bge _0806C382
	mov r1, r12
	lsls r0, r1, 16
	lsrs r6, r0, 16
	adds r1, r2, 0
_0806C358:
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	beq _0806C378
	ldrb r0, [r1, 0x4]
	cmp r0, r4
	bne _0806C378
	ldrb r0, [r1, 0x5]
	cmp r0, r5
	bne _0806C378
	strh r6, [r1]
	strb r7, [r1, 0x2]
	b _0806C3B8
	.align 2, 0
_0806C370: .4byte gDungeonGlobalData
_0806C374: .4byte 0x0000057c
_0806C378:
	adds r1, 0x8
	adds r3, 0x1
	ldr r0, [r2, 0x40]
	cmp r3, r0
	blt _0806C358
_0806C382:
	ldr r0, [r2, 0x40]
	cmp r0, 0x7
	bgt _0806C3B8
	lsls r0, 3
	adds r0, r2, r0
	movs r1, 0x1
	strb r1, [r0, 0x3]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r4, [r0, 0x4]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r5, [r0, 0x5]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	mov r1, r12
	strh r1, [r0]
	ldr r0, [r2, 0x40]
	lsls r0, 3
	adds r0, r2, r0
	strb r7, [r0, 0x2]
	ldr r0, [r2, 0x40]
	adds r0, 0x1
	str r0, [r2, 0x40]
_0806C3B8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806C330

	thumb_func_start sub_806C3C0
sub_806C3C0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	ldr r0, _0806C424
	ldr r0, [r0]
	ldr r1, _0806C428
	adds r7, r0, r1
	movs r6, 0
	ldr r0, [r7, 0x40]
	cmp r6, r0
	bge _0806C416
	mov r5, sp
	movs r0, 0
	mov r8, r0
	movs r2, 0
	adds r4, r7, 0
_0806C3E2:
	ldrb r0, [r4, 0x3]
	cmp r0, 0
	beq _0806C40C
	ldrh r0, [r4]
	strh r0, [r5]
	strh r2, [r5, 0x8]
	ldrb r0, [r4, 0x4]
	strh r0, [r5, 0xC]
	ldrb r0, [r4, 0x5]
	strh r0, [r5, 0xE]
	ldrb r0, [r4, 0x2]
	strb r0, [r5, 0x2]
	str r2, [sp, 0x4]
	mov r1, r8
	strb r1, [r5, 0x10]
	mov r0, sp
	movs r1, 0x1
	str r2, [sp, 0x14]
	bl sub_806B7F8
	ldr r2, [sp, 0x14]
_0806C40C:
	adds r4, 0x8
	adds r6, 0x1
	ldr r0, [r7, 0x40]
	cmp r6, r0
	blt _0806C3E2
_0806C416:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806C424: .4byte gDungeonGlobalData
_0806C428: .4byte 0x0000057c
	thumb_func_end sub_806C3C0

	thumb_func_start sub_806C42C
sub_806C42C:
	ldr r0, _0806C43C
	ldr r0, [r0]
	ldr r1, _0806C440
	adds r0, r1
	movs r1, 0
	str r1, [r0, 0x40]
	bx lr
	.align 2, 0
_0806C43C: .4byte gDungeonGlobalData
_0806C440: .4byte 0x0000057c
	thumb_func_end sub_806C42C

	thumb_func_start sub_806C444
sub_806C444:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	bl GetBaseHP
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C478
	mov r8, sp
_0806C462:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrh r0, [r1, 0x4]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C462
_0806C478:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C444

	thumb_func_start sub_806C488
sub_806C488:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	mov r1, r8
	bl GetPokemonAttSpatt
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C4C4
	mov r0, sp
	adds r0, 0x6
	add r8, r0
_0806C4AE:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrb r0, [r1]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C4AE
_0806C4C4:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C488

	thumb_func_start sub_806C4D4
sub_806C4D4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	adds r7, r1, 0
	mov r8, r2
	lsls r0, 16
	asrs r6, r0, 16
	adds r0, r6, 0
	mov r1, r8
	bl GetPokemonDefSpdef
	adds r5, r0, 0
	movs r4, 0x2
	cmp r4, r7
	bgt _0806C50E
	add r0, sp, 0x8
	add r8, r0
_0806C4F8:
	mov r0, sp
	adds r1, r6, 0
	adds r2, r4, 0
	bl GetPokemonLevelData
	mov r1, r8
	ldrb r0, [r1]
	adds r5, r0
	adds r4, 0x1
	cmp r4, r7
	ble _0806C4F8
_0806C50E:
	adds r0, r5, 0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806C4D4

	thumb_func_start sub_806C51C
sub_806C51C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x50
	adds r6, r0, 0
	ldr r0, [r6, 0x70]
	mov r8, r0
	ldr r0, _0806C544
	ldr r1, [r0]
	ldr r2, _0806C548
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, r6
	bne _0806C54C
	movs r3, 0
	str r3, [sp, 0x38]
	b _0806C554
	.align 2, 0
_0806C544: .4byte gDungeonGlobalData
_0806C548: .4byte 0x000181f8
_0806C54C:
	ldr r4, _0806C5AC
	adds r0, r1, r4
	ldrb r0, [r0]
	str r0, [sp, 0x38]
_0806C554:
	mov r0, r8
	adds r0, 0xC8
	ldrb r1, [r0]
	str r0, [sp, 0x40]
	cmp r1, 0x2
	bne _0806C564
	movs r7, 0x1
	str r7, [sp, 0x38]
_0806C564:
	adds r0, r6, 0
	adds r0, 0x6B
	adds r1, r6, 0
	adds r1, 0x6A
	ldrb r2, [r0]
	str r0, [sp, 0x48]
	mov r9, r1
	adds r5, r6, 0
	adds r5, 0x6D
	adds r0, 0x1
	str r0, [sp, 0x4C]
	adds r4, r6, 0
	adds r4, 0x6F
	subs r1, 0x47
	str r1, [sp, 0x44]
	mov r3, r9
	ldrb r3, [r3]
	cmp r2, r3
	bne _0806C676
	ldrb r0, [r5]
	ldr r7, [sp, 0x4C]
	ldrb r7, [r7]
	cmp r0, r7
	bne _0806C654
	ldrb r0, [r4]
	cmp r0, 0
	bne _0806C654
	movs r2, 0
	ldrh r1, [r6, 0x28]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _0806C5B0
	movs r0, 0
	b _0806C5B2
	.align 2, 0
_0806C5AC: .4byte 0x00018210
_0806C5B0:
	lsrs r0, r1, 15
_0806C5B2:
	cmp r0, 0
	bne _0806C5B8
	movs r2, 0x1
_0806C5B8:
	adds r0, r6, 0
	adds r0, 0x23
	str r0, [sp, 0x44]
	cmp r2, 0
	beq _0806C654
	adds r0, r6, 0
	bl sub_806CEBC
	lsls r0, 24
	lsrs r3, r0, 24
	adds r1, r6, 0
	adds r1, 0x21
	movs r0, 0x1
	strb r0, [r1]
	mov r1, r8
	adds r1, 0xFE
	ldrb r0, [r1]
	cmp r0, 0x63
	bne _0806C620
	ldr r1, [sp, 0x48]
	ldrb r0, [r1]
	cmp r0, 0xC
	bhi _0806C61C
	mov r0, r8
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806C5F4
	movs r2, 0x2
	b _0806C600
_0806C5F4:
	ldr r2, [sp, 0x44]
	ldrb r0, [r2]
	movs r2, 0x1
	cmp r0, 0x2
	bhi _0806C600
	movs r2, 0
_0806C600:
	ldr r1, _0806C618
	movs r0, 0xD
	muls r0, r2
	ldr r7, [sp, 0x48]
	ldrb r7, [r7]
	adds r0, r7
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _0806C622
	adds r0, r3, 0
	b _0806C622
	.align 2, 0
_0806C618: .4byte gUnknown_8106EC8
_0806C61C:
	movs r0, 0x63
	b _0806C622
_0806C620:
	ldrb r0, [r1]
_0806C622:
	cmp r0, 0x63
	beq _0806C654
	mov r1, r9
	strb r0, [r1]
	ldrb r1, [r5]
	movs r0, 0x7
	ands r0, r1
	ldr r2, [sp, 0x4C]
	strb r0, [r2]
	movs r0, 0x1
	strb r0, [r4]
	mov r7, r9
	ldrb r0, [r7]
	cmp r0, 0x6
	bne _0806C654
	adds r1, r6, 0
	adds r1, 0x6E
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	bne _0806C654
	strb r3, [r7]
_0806C654:
	ldr r1, [sp, 0x48]
	ldrb r0, [r1]
	mov r2, r9
	ldrb r2, [r2]
	cmp r0, r2
	bne _0806C676
	ldrb r0, [r5]
	ldr r3, [sp, 0x4C]
	ldrb r3, [r3]
	cmp r0, r3
	bne _0806C676
	ldrb r0, [r4]
	movs r7, 0x28
	adds r7, r6
	mov r10, r7
	cmp r0, 0
	beq _0806C714
_0806C676:
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, [sp, 0x48]
	strb r0, [r2]
	ldr r3, [sp, 0x4C]
	mov r10, r3
	ldrb r0, [r3]
	strb r0, [r5]
	movs r7, 0
	strb r7, [r4]
	adds r0, r6, 0
	adds r0, 0x68
	movs r1, 0
	ldrsh r7, [r0, r1]
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	mov r4, r9
	ldrb r1, [r4]
	bl sub_808DA44
	lsls r0, 24
	cmp r0, 0
	beq _0806C6A8
	movs r7, 0
_0806C6A8:
	ldr r0, [sp, 0x38]
	cmp r0, 0
	bne _0806C6D6
	bl Random
	movs r4, 0x3
	ands r4, r0
	adds r5, r6, 0
	adds r5, 0x28
	ldr r1, [r6, 0x64]
	mov r3, r9
	ldrb r2, [r3]
	mov r0, r10
	ldrb r3, [r0]
	str r7, [sp]
	str r4, [sp, 0x4]
	ldr r4, [sp, 0x38]
	str r4, [sp, 0x8]
	adds r0, r5, 0
	bl sub_80053AC
	mov r10, r5
	b _0806C704
_0806C6D6:
	ldr r0, _0806C774
	bl sub_80687D0
	adds r5, r0, 0
	bl Random
	movs r1, 0x3
	ands r1, r0
	adds r4, r6, 0
	adds r4, 0x28
	mov r0, r9
	ldrb r2, [r0]
	ldr r0, [sp, 0x4C]
	ldrb r3, [r0]
	str r7, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80053AC
	mov r10, r4
_0806C704:
	mov r2, r9
	ldrb r0, [r2]
	cmp r0, 0x6
	beq _0806C714
	adds r1, r6, 0
	adds r1, 0x6E
	movs r0, 0
	strb r0, [r1]
_0806C714:
	ldr r0, _0806C778
	ldr r1, [r0]
	ldr r3, _0806C77C
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C784
	ldr r4, [sp, 0x48]
	ldrb r0, [r4]
	cmp r0, 0x7
	bne _0806C73C
	mov r7, r8
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl GetWalkableTiles
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0806C7E2
_0806C73C:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C76A
	movs r0, 0xB0
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C7E2
	ldr r0, _0806C780
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C76A
	mov r0, r10
	bl sub_80054BC
	mov r0, r10
	bl sub_80054BC
_0806C76A:
	mov r0, r10
	bl sub_80054BC
	b _0806C7E2
	.align 2, 0
_0806C774: .4byte 0x000001a5
_0806C778: .4byte gDungeonGlobalData
_0806C77C: .4byte 0x0001356c
_0806C780: .4byte 0x0000015f
_0806C784:
	mov r0, r8
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806C7E2
	cmp r0, 0x6
	beq _0806C7E2
	ldr r2, _0806C7B4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C7BC
	ldr r3, _0806C7B8
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C7BC
	mov r0, r10
	bl sub_80054BC
	mov r0, r10
	bl sub_80054BC
	b _0806C7DC
	.align 2, 0
_0806C7B4: .4byte 0x0000066c
_0806C7B8: .4byte 0x0001c05f
_0806C7BC:
	ldr r4, [sp, 0x48]
	ldrb r0, [r4]
	cmp r0, 0
	beq _0806C7C8
	cmp r0, 0x7
	bne _0806C7DC
_0806C7C8:
	ldr r0, [r6, 0x70]
	movs r7, 0x82
	lsls r7, 1
	adds r0, r7
	ldr r0, [r0]
	cmp r0, 0x1
	ble _0806C7DC
	mov r0, r10
	bl sub_80054BC
_0806C7DC:
	mov r0, r10
	bl sub_80054BC
_0806C7E2:
	ldr r1, [r6, 0xC]
	ldr r0, [r6, 0x14]
	cmp r1, r0
	bne _0806C800
	ldr r1, [r6, 0x10]
	ldr r0, [r6, 0x18]
	cmp r1, r0
	bne _0806C800
	ldr r1, [sp, 0x44]
	ldrb r0, [r1]
	cmp r0, 0x9
	bhi _0806C806
	adds r0, 0x1
	strb r0, [r1]
	b _0806C806
_0806C800:
	movs r0, 0
	ldr r2, [sp, 0x44]
	strb r0, [r2]
_0806C806:
	ldr r0, [r6, 0xC]
	str r0, [r6, 0x14]
	ldr r2, [r6, 0x10]
	str r2, [r6, 0x18]
	cmp r0, 0
	bge _0806C814
	adds r0, 0xFF
_0806C814:
	asrs r1, r0, 8
	ldr r0, _0806C88C
	ldr r3, [r0]
	ldr r4, _0806C890
	adds r0, r3, r4
	movs r7, 0
	ldrsh r0, [r0, r7]
	subs r1, r0
	str r1, [sp, 0x2C]
	ldr r0, [r6, 0x1C]
	subs r0, r2, r0
	movs r1, 0xBA
	lsls r1, 1
	add r1, r8
	ldr r1, [r1]
	subs r0, r1
	cmp r0, 0
	bge _0806C83A
	adds r0, 0xFF
_0806C83A:
	asrs r1, r0, 8
	ldr r4, _0806C894
	adds r0, r3, r4
	movs r7, 0
	ldrsh r3, [r0, r7]
	subs r1, r3
	str r1, [sp, 0x30]
	adds r0, r2, 0
	cmp r0, 0
	bge _0806C850
	adds r0, 0xFF
_0806C850:
	asrs r0, 8
	subs r0, r3
	mov r9, r0
	lsrs r0, 31
	add r0, r9
	asrs r0, 1
	mov r9, r0
	movs r0, 0xAB
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C870
	movs r0, 0x1
	negs r0, r0
	add r9, r0
_0806C870:
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C898
	adds r0, r6, 0
	bl sub_8042768
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x34]
	b _0806C8D8
	.align 2, 0
_0806C88C: .4byte gDungeonGlobalData
_0806C890: .4byte 0x000181f0
_0806C894: .4byte 0x000181f2
_0806C898:
	ldr r0, _0806C8B8
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806C8C6
	ldr r0, _0806C8BC
	ldr r0, [r0]
	movs r1, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0806C8C0
	ldr r1, [sp, 0x2C]
	adds r1, 0x1
	str r1, [sp, 0x2C]
	b _0806C8C6
	.align 2, 0
_0806C8B8: .4byte 0x0000015d
_0806C8BC: .4byte gUnknown_202EDCC
_0806C8C0:
	ldr r2, [sp, 0x2C]
	subs r2, 0x1
	str r2, [sp, 0x2C]
_0806C8C6:
	movs r1, 0
	movs r0, 0xAF
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806C8D6
	movs r1, 0x1
_0806C8D6:
	str r1, [sp, 0x34]
_0806C8D8:
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0806C8E0
	adds r0, 0xFF
_0806C8E0:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _0806C998
	ldr r2, [sp, 0x28]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x28]
	ldr r1, [r6, 0x10]
	ldr r0, [r6, 0x1C]
	subs r1, r0
	movs r5, 0xBA
	lsls r5, 1
	add r5, r8
	ldr r0, [r5]
	subs r0, r1, r0
	cmp r0, 0
	bge _0806C904
	adds r0, 0xFF
_0806C904:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _0806C99C
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x28]
	add r0, sp, 0xC
	mov r1, r10
	bl sub_8005700
	mov r4, r8
	adds r4, 0x98
	ldr r0, [r4]
	add r1, sp, 0x28
	ldr r2, _0806C9A0
	ldr r2, [r2]
	ldr r3, _0806C9A4
	adds r2, r3
	ldrb r3, [r2]
	add r2, sp, 0xC
	bl sub_800F958
	adds r0, r6, 0
	bl sub_804187C
	adds r2, r0, 0
	ldr r4, [r4]
	mov r0, r8
	movs r1, 0x4
	ldrsh r7, [r0, r1]
	movs r3, 0
	ldr r0, [sp, 0x34]
	cmp r0, 0
	beq _0806C958
	movs r0, 0xA6
	lsls r0, 1
	add r0, r8
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r3, r0, 31
_0806C958:
	adds r0, r4, 0
	adds r1, r7, 0
	bl sub_800F75C
	adds r0, r6, 0
	mov r1, r9
	bl sub_8042EC8
	movs r0, 0xAE
	lsls r0, 1
	add r0, r8
	ldrb r1, [r0]
	cmp r1, 0
	bne _0806C9BA
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806C9AC
	ldr r1, [r5]
	ldr r0, _0806C9A8
	cmp r1, r0
	bgt _0806C9BA
	movs r2, 0x80
	lsls r2, 4
	adds r0, r1, r2
	str r0, [r5]
	movs r1, 0xC8
	lsls r1, 8
	cmp r0, r1
	ble _0806C9BA
	b _0806C9B8
	.align 2, 0
_0806C998: .4byte 0xffff0000
_0806C99C: .4byte 0x0000ffff
_0806C9A0: .4byte gDungeonGlobalData
_0806C9A4: .4byte 0x00018208
_0806C9A8: .4byte 0x0000c7ff
_0806C9AC:
	ldr r0, [r5]
	ldr r3, _0806CA5C
	adds r0, r3
	str r0, [r5]
	cmp r0, 0
	bge _0806C9BA
_0806C9B8:
	str r1, [r5]
_0806C9BA:
	ldr r4, [sp, 0x34]
	cmp r4, 0
	bne _0806C9C2
	b _0806CBDE
_0806C9C2:
	movs r4, 0
	adds r0, r6, 0
	bl sub_806CF54
	lsls r0, 24
	lsrs r7, r0, 24
	add r1, sp, 0x1C
	ldr r2, _0806CA60
	strh r2, [r1]
	ldr r0, _0806CA64
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	strh r4, [r1, 0x6]
	strh r4, [r1, 0x8]
	ldr r0, _0806CA68
	ldr r0, [r0]
	ldr r2, _0806CA6C
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 10
	strh r0, [r1, 0xA]
	mov r3, r8
	ldrb r0, [r3, 0x6]
	adds r5, r1, 0
	cmp r0, 0
	beq _0806CA08
	ldr r1, _0806CA70
	adds r0, r1, 0
	ldrh r2, [r3, 0x4]
	adds r0, r2
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bhi _0806CA08
	movs r4, 0x1
_0806CA08:
	mov r0, r8
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806CA22
	ldr r0, _0806CA68
	ldr r0, [r0]
	ldr r3, _0806CA74
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806CA22
	movs r4, 0x1
_0806CA22:
	cmp r4, 0
	beq _0806CA32
	ldrh r1, [r5, 0x6]
	movs r4, 0x80
	lsls r4, 3
	adds r0, r4, 0
	orrs r0, r1
	strh r0, [r5, 0x6]
_0806CA32:
	movs r0, 0
	str r0, [sp, 0x3C]
	mov r1, r8
	ldrb r0, [r1, 0x6]
	cmp r0, 0
	beq _0806CA46
	ldr r2, [sp, 0x40]
	ldrb r0, [r2]
	cmp r0, 0x2
	bne _0806CA4A
_0806CA46:
	movs r3, 0x1
	str r3, [sp, 0x3C]
_0806CA4A:
	mov r0, r8
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0806CA58
	cmp r0, 0x47
	bne _0806CA78
_0806CA58:
	movs r0, 0x1
	b _0806CA7A
	.align 2, 0
_0806CA5C: .4byte 0xfffff400
_0806CA60: .4byte 0x0000f3ff
_0806CA64: .4byte 0x0000ffff
_0806CA68: .4byte gDungeonGlobalData
_0806CA6C: .4byte 0x00018208
_0806CA70: .4byte 0xfffffe5f
_0806CA74: .4byte 0x0001820f
_0806CA78:
	movs r0, 0
_0806CA7A:
	cmp r0, 0
	bne _0806CA88
	mov r0, r8
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806CA8C
_0806CA88:
	movs r4, 0x1
	str r4, [sp, 0x3C]
_0806CA8C:
	mov r0, r8
	adds r0, 0xFF
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0806CB16
	mov r0, r8
	adds r0, 0xB0
	ldrb r1, [r0]
	cmp r1, 0x6
	beq _0806CAAC
	subs r0, 0x4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _0806CAAC
	cmp r1, 0x2
	bne _0806CABA
_0806CAAC:
	ldr r0, _0806CAC4
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	ldr r1, [sp, 0x2C]
	adds r1, r0
	str r1, [sp, 0x2C]
_0806CABA:
	ldr r2, [sp, 0x38]
	cmp r2, 0
	beq _0806CACC
	ldr r0, _0806CAC8
	b _0806CAD2
	.align 2, 0
_0806CAC4: .4byte gUnknown_202EDCC
_0806CAC8: .4byte 0x000001a5
_0806CACC:
	mov r3, r8
	movs r4, 0x4
	ldrsh r0, [r3, r4]
_0806CAD2:
	movs r1, 0
	bl GetPokemonOverworldPalette
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r6, 0
	adds r0, 0x22
	ldrb r1, [r0]
	cmp r1, 0
	bne _0806CAF8
	str r2, [sp]
	str r5, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	mov r3, r9
	bl sub_800558C
	b _0806CB16
_0806CAF8:
	cmp r1, 0x1
	bne _0806CB16
	ldr r0, _0806CBF0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	beq _0806CB16
	str r2, [sp]
	str r5, [sp, 0x4]
	mov r0, r10
	ldr r1, [sp, 0x2C]
	ldr r2, [sp, 0x30]
	mov r3, r9
	bl sub_800558C
_0806CB16:
	ldr r0, [r6, 0xC]
	cmp r0, 0
	bge _0806CB1E
	adds r0, 0xFF
_0806CB1E:
	asrs r0, 8
	ldrh r1, [r6, 0x38]
	adds r0, r1
	movs r1, 0xB8
	lsls r1, 1
	add r1, r8
	strh r0, [r1]
	ldr r0, [r6, 0x10]
	cmp r0, 0
	bge _0806CB34
	adds r0, 0xFF
_0806CB34:
	asrs r0, 8
	ldrh r2, [r6, 0x3A]
	adds r0, r2
	movs r3, 0xB9
	lsls r3, 1
	add r3, r8
	strh r0, [r3]
	movs r4, 0
	ldrsh r2, [r1, r4]
	ldr r0, _0806CBF4
	ldr r1, [r0]
	ldr r4, _0806CBF8
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	subs r4, r2, r0
	movs r0, 0
	ldrsh r2, [r3, r0]
	ldr r3, _0806CBFC
	adds r1, r3
	movs r3, 0
	ldrsh r0, [r1, r3]
	subs r5, r2, r0
	movs r0, 0x20
	negs r0, r0
	cmp r4, r0
	blt _0806CBDE
	cmp r5, r0
	blt _0806CBDE
	ldr r0, _0806CC00
	cmp r4, r0
	bgt _0806CBDE
	cmp r5, 0xBF
	bgt _0806CBDE
	cmp r7, 0x6
	beq _0806CBDE
	adds r0, r6, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806CBDE
	ldr r0, [sp, 0x3C]
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 3
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	ldr r1, _0806CC04
	adds r0, r1
	adds r3, r2, r0
	movs r0, 0xAB
	lsls r0, 1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806CBDE
	movs r2, 0x8
	ldrsh r1, [r3, r2]
	adds r1, r4, r1
	ldr r0, _0806CC08
	ands r1, r0
	ldrh r2, [r3, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x2]
	movs r4, 0xA
	ldrsh r1, [r3, r4]
	adds r1, r5, r1
	ldr r0, _0806CC0C
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r3, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x6]
	adds r0, r3, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AddSprite
_0806CBDE:
	add sp, 0x50
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806CBF0: .4byte gUnknown_202EDCC
_0806CBF4: .4byte gDungeonGlobalData
_0806CBF8: .4byte 0x000181f0
_0806CBFC: .4byte 0x000181f2
_0806CC00: .4byte 0x0000010f
_0806CC04: .4byte gUnknown_202ED28
_0806CC08: .4byte 0x000001ff
_0806CC0C: .4byte 0x00000fff
	thumb_func_end sub_806C51C

	thumb_func_start sub_806CC10
sub_806CC10:
	push {r4,r5,lr}
	movs r5, 0
_0806CC14:
	ldr r0, _0806CC68
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806CC6C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806CC5C
	ldr r2, [r4, 0x70]
	movs r1, 0xB3
	lsls r1, 1
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, 0
	beq _0806CC5C
	subs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	bne _0806CC5C
	adds r0, r2, 0
	adds r0, 0x46
	ldrb r2, [r0]
	subs r2, 0x1
	movs r0, 0x7
	ands r2, r0
	adds r0, r4, 0
	movs r1, 0
	bl sub_806CDD4
_0806CC5C:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806CC14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CC68: .4byte gDungeonGlobalData
_0806CC6C: .4byte 0x000135cc
	thumb_func_end sub_806CC10

	thumb_func_start sub_806CC70
sub_806CC70:
	push {r4,r5,lr}
	movs r5, 0
_0806CC74:
	ldr r0, _0806CCAC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806CCB0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806CCA0
	adds r0, r4, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806CCB4
_0806CCA0:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806CC74
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CCAC: .4byte gDungeonGlobalData
_0806CCB0: .4byte 0x000135cc
	thumb_func_end sub_806CC70

	thumb_func_start sub_806CCB4
sub_806CCB4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xC
	adds r5, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r7, [r5, 0x70]
	ldr r0, _0806CD40
	ldr r0, [r0]
	ldr r2, _0806CD44
	adds r1, r0, r2
	ldrb r6, [r1]
	ldr r3, _0806CD48
	adds r0, r3
	ldr r0, [r0]
	cmp r5, r0
	bne _0806CCDC
	movs r6, 0
_0806CCDC:
	adds r0, r5, 0
	adds r0, 0x6B
	movs r3, 0
	strb r4, [r0]
	adds r2, r5, 0
	adds r2, 0x6A
	strb r4, [r2]
	adds r4, r7, 0
	adds r4, 0x46
	ldrb r0, [r4]
	adds r1, r5, 0
	adds r1, 0x6D
	strb r0, [r1]
	ldrb r0, [r4]
	subs r1, 0x1
	strb r0, [r1]
	adds r0, r5, 0
	adds r0, 0x6F
	strb r3, [r0]
	subs r0, 0x7
	movs r3, 0
	ldrsh r4, [r0, r3]
	mov r9, r4
	adds r0, r7, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	adds r7, r2, 0
	mov r8, r1
	cmp r0, 0x2
	beq _0806CD4C
	cmp r6, 0
	bne _0806CD4C
	bl Random
	movs r4, 0x3
	ands r4, r0
	adds r0, r5, 0
	adds r0, 0x28
	ldr r1, [r5, 0x64]
	ldrb r2, [r7]
	mov r7, r8
	ldrb r3, [r7]
	mov r7, r9
	str r7, [sp]
	str r4, [sp, 0x4]
	str r6, [sp, 0x8]
	bl sub_80053AC
	b _0806CD76
	.align 2, 0
_0806CD40: .4byte gDungeonGlobalData
_0806CD44: .4byte 0x00018210
_0806CD48: .4byte 0x000181f8
_0806CD4C:
	ldr r0, _0806CD8C
	bl sub_80687D0
	adds r4, r0, 0
	bl Random
	movs r1, 0x3
	ands r1, r0
	adds r0, r5, 0
	adds r0, 0x28
	ldrb r2, [r7]
	mov r6, r8
	ldrb r3, [r6]
	mov r7, r9
	str r7, [sp]
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r1, r4, 0
	bl sub_80053AC
_0806CD76:
	adds r1, r5, 0
	adds r1, 0x6E
	movs r0, 0
	strb r0, [r1]
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806CD8C: .4byte 0x000001a5
	thumb_func_end sub_806CCB4

	thumb_func_start sub_806CD90
sub_806CD90:
	push {r4,r5,lr}
	movs r5, 0
_0806CD94:
	ldr r0, _0806CDCC
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806CDD0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806CDC0
	adds r0, r4, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806CCB4
_0806CDC0:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806CD94
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CDCC: .4byte gDungeonGlobalData
_0806CDD0: .4byte 0x000135cc
	thumb_func_end sub_806CD90

	thumb_func_start sub_806CDD4
sub_806CDD4:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r2, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806CDF4
	adds r0, r4, 0
	adds r0, 0x6A
	strb r5, [r0]
	cmp r6, 0x7
	bhi _0806CDF4
	adds r0, 0x2
	strb r6, [r0]
_0806CDF4:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806CDD4

	thumb_func_start sub_806CDFC
sub_806CDFC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r2, 0
	lsls r1, 24
	lsrs r5, r1, 24
	adds r7, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806CE2E
	adds r0, r4, 0
	adds r0, 0x6B
	ldrb r0, [r0]
	cmp r0, r5
	bne _0806CE24
	adds r0, r4, 0
	adds r0, 0x6D
	ldrb r0, [r0]
	cmp r0, r6
	beq _0806CE2E
_0806CE24:
	adds r0, r4, 0
	adds r1, r7, 0
	adds r2, r6, 0
	bl sub_806CDD4
_0806CE2E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806CDFC

	thumb_func_start sub_806CE34
sub_806CE34:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806CE62
	adds r0, r4, 0
	bl sub_806CEBC
	adds r1, r4, 0
	adds r1, 0x6A
	strb r0, [r1]
	cmp r5, 0x7
	bhi _0806CE62
	ldr r0, [r4, 0x70]
	movs r1, 0x7
	ands r1, r5
	adds r0, 0x46
	strb r1, [r0]
	adds r0, r4, 0
	adds r0, 0x6C
	strb r1, [r0]
_0806CE62:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806CE34

	thumb_func_start sub_806CE68
sub_806CE68:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806CE8C
	adds r0, r4, 0
	bl sub_806CEBC
	adds r1, r4, 0
	adds r1, 0x6A
	strb r0, [r1]
	cmp r5, 0x7
	bhi _0806CE8C
	adds r0, r4, 0
	adds r0, 0x6C
	strb r5, [r0]
_0806CE8C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806CE68

	thumb_func_start sub_806CE94
sub_806CE94:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806CEB4
	adds r1, r4, 0
	adds r1, 0x6A
	movs r0, 0x6
	strb r0, [r1]
	cmp r5, 0x7
	bhi _0806CEB4
	adds r0, r4, 0
	adds r0, 0x6C
	strb r5, [r0]
_0806CEB4:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806CE94

	thumb_func_start sub_806CEBC
sub_806CEBC:
	push {lr}
	ldr r0, [r0, 0x70]
	adds r1, r0, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806CED2
	cmp r0, 0x5
	beq _0806CED2
	cmp r0, 0x3
	bne _0806CEE8
_0806CED2:
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	cmp r0, 0xB9
	bne _0806CEE4
	adds r0, r1, 0
	adds r0, 0xA9
	ldrb r0, [r0]
	cmp r0, 0x7F
	beq _0806CEF2
_0806CEE4:
	movs r0, 0x5
	b _0806CEF8
_0806CEE8:
	adds r0, r1, 0
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806CEF6
_0806CEF2:
	movs r0, 0x7
	b _0806CEF8
_0806CEF6:
	movs r0, 0xB
_0806CEF8:
	pop {r1}
	bx r1
	thumb_func_end sub_806CEBC

	thumb_func_start sub_806CEFC
sub_806CEFC:
	push {r4,lr}
	adds r4, r1, 0
	ldr r2, [r0, 0x70]
	movs r3, 0x7
	ands r1, r3
	adds r2, 0x46
	strb r1, [r2]
	movs r1, 0x7
	ands r1, r4
	bl sub_806CE68
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806CEFC

	thumb_func_start sub_806CF18
sub_806CF18:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806CF4C
	ldr r6, [r4, 0x70]
	movs r5, 0
	b _0806CF2E
_0806CF2C:
	adds r5, 0x1
_0806CF2E:
	cmp r5, 0x63
	bgt _0806CF4C
	movs r0, 0x21
	bl sub_803E46C
	movs r1, 0x4
	ldrsh r0, [r6, r1]
	adds r1, r4, 0
	adds r1, 0x6B
	ldrb r1, [r1]
	bl sub_808DA44
	lsls r0, 24
	cmp r0, 0
	bne _0806CF2C
_0806CF4C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806CF18

	thumb_func_start sub_806CF54
sub_806CF54:
	ldr r0, [r0, 0x70]
	movs r1, 0x81
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	thumb_func_end sub_806CF54

	thumb_func_start sub_806CF60
sub_806CF60:
	push {r4,r5,lr}
	movs r5, 0
_0806CF64:
	ldr r0, _0806CF90
	ldr r0, [r0]
	lsls r1, r5, 2
	ldr r2, _0806CF94
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806CF84
	adds r0, r4, 0
	bl sub_806CF98
_0806CF84:
	adds r5, 0x1
	cmp r5, 0x13
	ble _0806CF64
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806CF90: .4byte gDungeonGlobalData
_0806CF94: .4byte 0x000135cc
	thumb_func_end sub_806CF60

	thumb_func_start sub_806CF98
sub_806CF98:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl sub_8045128
	ldrh r0, [r0]
	movs r5, 0x3
	ands r5, r0
	adds r6, r5, 0
	ldr r7, [r4, 0x70]
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	bl GetShadowSize
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r5, 0x3
	bne _0806CFBE
	movs r0, 0x6
	b _0806CFF8
_0806CFBE:
	cmp r5, 0x1
	bne _0806CFCE
	bl sub_804AF74
	lsls r0, 24
	cmp r0, 0
	beq _0806CFEE
	b _0806CFE8
_0806CFCE:
	cmp r6, 0x2
	bne _0806CFEE
	ldr r1, _0806D000
	ldr r0, _0806D004
	ldr r0, [r0]
	ldr r2, _0806D008
	adds r0, r2
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806CFEE
_0806CFE8:
	ldr r0, _0806D00C
	adds r0, r4, r0
	ldrb r4, [r0]
_0806CFEE:
	movs r1, 0x81
	lsls r1, 2
	adds r0, r7, r1
	strb r4, [r0]
	adds r0, r4, 0
_0806CFF8:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806D000: .4byte gUnknown_810ACC0
_0806D004: .4byte gDungeonGlobalData
_0806D008: .4byte 0x00003a0e
_0806D00C: .4byte gUnknown_8106EEF
	thumb_func_end sub_806CF98

	thumb_func_start sub_806D010
sub_806D010:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r6, r0, 0
	adds r5, r1, 0
	mov r8, r2
	ldr r0, [sp, 0x40]
	lsls r0, 16
	asrs r0, 16
	mov r10, r0
	movs r7, 0
	ldr r0, [sp, 0x3C]
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x48]
	str r2, [sp, 0x8]
	adds r0, r6, 0
	adds r1, r5, 0
	mov r2, r8
	bl sub_806D528
	lsls r0, 24
	cmp r0, 0
	beq _0806D04A
	b _0806D514
_0806D04A:
	mov r3, r8
	ldrb r0, [r3, 0xF]
	cmp r0, 0
	beq _0806D054
	b _0806D514
_0806D054:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D062
	b _0806D514
_0806D062:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D070
	b _0806D514
_0806D070:
	adds r0, r6, 0
	bl sub_80450F8
	cmp r0, 0x1
	beq _0806D07C
	b _0806D514
_0806D07C:
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	beq _0806D088
	b _0806D514
_0806D088:
	ldr r0, [sp, 0x44]
	mov r9, r0
	adds r0, r5, 0
	bl CannotAct
	lsls r0, 24
	cmp r0, 0
	bne _0806D0A2
	ldr r0, [r5, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806D0A6
_0806D0A2:
	movs r1, 0
	mov r9, r1
_0806D0A6:
	mov r2, r9
	cmp r2, 0
	beq _0806D100
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D0BC
	negs r1, r1
_0806D0BC:
	cmp r1, 0x1
	bgt _0806D100
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D0D0
	negs r1, r1
_0806D0D0:
	cmp r1, 0x1
	bgt _0806D100
	cmp r6, r5
	beq _0806D100
	mov r3, r8
	ldrb r0, [r3, 0xC]
	bl sub_8092354
	lsls r0, 24
	cmp r0, 0
	beq _0806D100
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xD
	bne _0806D100
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8042730
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_807F43C
_0806D100:
	ldr r0, [r5, 0x70]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _0806D118
	ldr r0, _0806D3BC
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	movs r3, 0x1
	bl sub_8077084
_0806D118:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D126
	b _0806D514
_0806D126:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D134
	b _0806D514
_0806D134:
	mov r0, r9
	cmp r0, 0
	beq _0806D216
	cmp r6, r5
	beq _0806D216
	movs r2, 0x4
	ldrsh r1, [r6, r2]
	movs r3, 0x4
	ldrsh r0, [r5, r3]
	subs r1, r0
	cmp r1, 0
	bge _0806D14E
	negs r1, r1
_0806D14E:
	cmp r1, 0x1
	bgt _0806D216
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D162
	negs r1, r1
_0806D162:
	cmp r1, 0x1
	bgt _0806D216
	mov r3, r8
	ldrb r0, [r3, 0xC]
	bl sub_8092354
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806D188
	cmp r4, 0
	beq _0806D188
	adds r0, r5, 0
	bl sub_8041B18
	adds r7, 0x4
_0806D188:
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xA
	bne _0806D19E
	cmp r4, 0
	beq _0806D19E
	adds r0, r5, 0
	bl sub_8041B18
	adds r7, 0x1
_0806D19E:
	ldr r0, [r5, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _0806D1B4
	cmp r4, 0
	bne _0806D1B4
	adds r0, r5, 0
	bl sub_8041B90
	adds r7, 0x4
_0806D1B4:
	adds r0, r5, 0
	movs r1, 0x12
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D1C4
	adds r7, 0x2
_0806D1C4:
	cmp r7, 0
	beq _0806D216
	ldr r0, _0806D3C0
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_80522F4
	mov r1, r8
	ldr r0, [r1]
	muls r0, r7
	cmp r0, 0
	bge _0806D1E0
	adds r0, 0x3
_0806D1E0:
	asrs r0, 2
	str r0, [sp, 0xC]
	add r2, sp, 0xC
	mov r3, r8
	ldrb r0, [r3, 0xC]
	movs r1, 0
	strb r0, [r2, 0xC]
	movs r0, 0x6
	str r0, [sp, 0x10]
	movs r0, 0x2
	str r0, [sp, 0x14]
	adds r0, r2, 0
	strb r1, [r0, 0xD]
	strb r1, [r0, 0xE]
	strb r1, [r0, 0xF]
	ldr r0, [sp, 0x3C]
	str r0, [sp]
	mov r1, r10
	str r1, [sp, 0x4]
	ldr r2, [sp, 0x48]
	str r2, [sp, 0x8]
	adds r0, r5, 0
	adds r1, r6, 0
	add r2, sp, 0xC
	movs r3, 0
	bl sub_806D528
_0806D216:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D224
	b _0806D514
_0806D224:
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806D232
	b _0806D514
_0806D232:
	mov r3, r9
	cmp r3, 0
	bne _0806D23A
	b _0806D48A
_0806D23A:
	cmp r6, r5
	bne _0806D240
	b _0806D48A
_0806D240:
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D250
	negs r1, r1
_0806D250:
	cmp r1, 0x1
	ble _0806D256
	b _0806D48A
_0806D256:
	movs r3, 0x6
	ldrsh r1, [r6, r3]
	movs r2, 0x6
	ldrsh r0, [r5, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806D266
	negs r1, r1
_0806D266:
	cmp r1, 0x1
	ble _0806D26C
	b _0806D48A
_0806D26C:
	mov r3, r8
	ldrb r0, [r3, 0xC]
	bl sub_8092354
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r4, [r6, 0x70]
	adds r0, r5, 0
	movs r1, 0x5
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D2C2
	adds r0, r6, 0
	movs r1, 0xA
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	bne _0806D2C2
	adds r0, r6, 0
	movs r1, 0x37
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _0806D2C2
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3C4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D2C2
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r2]
_0806D2C2:
	adds r0, r5, 0
	movs r1, 0xA
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D2EE
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3C8
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D2EE
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x2
	orrs r0, r1
	strh r0, [r2]
_0806D2EE:
	adds r0, r5, 0
	movs r1, 0x17
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D328
	adds r0, r6, 0
	movs r1, 0x11
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	beq _0806D328
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3CC
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D328
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x4
	orrs r0, r1
	strh r0, [r2]
_0806D328:
	adds r0, r5, 0
	movs r1, 0x20
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D358
	cmp r7, 0
	beq _0806D358
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3D0
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D358
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x8
	orrs r0, r1
	strh r0, [r2]
_0806D358:
	adds r0, r5, 0
	movs r1, 0x27
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D384
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3D4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D384
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x20
	orrs r0, r1
	strh r0, [r2]
_0806D384:
	adds r0, r5, 0
	movs r1, 0x3D
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D3FA
	cmp r7, 0
	beq _0806D3FA
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D3D8
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D3FA
	movs r0, 0x3
	bl DungeonRandomCapped
	cmp r0, 0
	bgt _0806D3DC
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, 0x40
	b _0806D3F6
	.align 2, 0
_0806D3BC: .4byte gUnknown_8106A4C
_0806D3C0: .4byte gUnknown_80FCFA4
_0806D3C4: .4byte gUnknown_80F4E10
_0806D3C8: .4byte gUnknown_80F4E12
_0806D3CC: .4byte gUnknown_80F4E14
_0806D3D0: .4byte gUnknown_80F4E16
_0806D3D4: .4byte gUnknown_80F4E18
_0806D3D8: .4byte gUnknown_80F4E1A
_0806D3DC:
	cmp r0, 0x1
	bgt _0806D3EC
	movs r0, 0xBC
	lsls r0, 1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, 0x10
	b _0806D3F6
_0806D3EC:
	movs r1, 0xBC
	lsls r1, 1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r0, 0x80
_0806D3F6:
	orrs r0, r1
	strh r0, [r2]
_0806D3FA:
	adds r0, r5, 0
	movs r1, 0x3E
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D428
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D4D4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D428
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	subs r3, 0x78
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r2]
_0806D428:
	adds r0, r5, 0
	movs r1, 0x44
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D45A
	cmp r7, 0
	beq _0806D45A
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D4D8
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D45A
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	adds r3, 0x88
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r2]
_0806D45A:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D48A
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _0806D4DC
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _0806D48A
	movs r3, 0xBC
	lsls r3, 1
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r3, 0x80
	lsls r3, 3
	adds r0, r3, 0
	orrs r0, r1
	strh r0, [r2]
_0806D48A:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806D514
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806D514
	mov r0, r9
	cmp r0, 0
	beq _0806D514
	ldr r2, [r5, 0x70]
	adds r6, r2, 0
	adds r3, r2, 0
	adds r3, 0xD0
	ldrb r0, [r3]
	cmp r0, 0x2
	bne _0806D514
	ldr r0, _0806D4E0
	ldr r1, [r0]
	adds r0, r2, 0
	adds r0, 0xD8
	ldrb r0, [r0]
	lsls r0, 2
	ldr r2, _0806D4E4
	adds r1, r2
	adds r1, r0
	ldr r4, [r1]
	cmp r4, 0
	bne _0806D4E8
	strb r4, [r3]
	b _0806D514
	.align 2, 0
_0806D4D4: .4byte gUnknown_80F4E1C
_0806D4D8: .4byte gUnknown_80F4E1E
_0806D4DC: .4byte gUnknown_80F4E20
_0806D4E0: .4byte gDungeonGlobalData
_0806D4E4: .4byte 0x000135cc
_0806D4E8:
	ldr r0, [r4, 0x70]
	adds r0, 0x98
	adds r1, r6, 0
	adds r1, 0xD4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	beq _0806D4FE
	movs r0, 0
	strb r0, [r3]
	b _0806D514
_0806D4FE:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8041D00
	mov r3, r8
	ldr r1, [r3]
	ldr r3, _0806D524
	adds r0, r4, 0
	movs r2, 0xC
	bl sub_806F324
_0806D514:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D524: .4byte 0x000001f9
	thumb_func_end sub_806D010

	thumb_func_start sub_806D528
sub_806D528:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x58
	mov r9, r0
	adds r7, r1, 0
	adds r5, r2, 0
	str r3, [sp, 0x4C]
	ldr r0, [sp, 0x7C]
	lsls r0, 16
	asrs r0, 16
	str r0, [sp, 0x50]
	movs r0, 0
	str r0, [sp, 0x54]
	mov r10, r0
	mov r8, r0
	mov r1, r10
	strb r1, [r5, 0xF]
	adds r0, r7, 0
	bl sub_80450F8
	cmp r0, 0x1
	beq _0806D55C
	b _0806D754
_0806D55C:
	ldr r6, [r7, 0x70]
	mov r0, r9
	adds r1, r7, 0
	bl sub_807A96C
	mov r0, r9
	adds r1, r7, 0
	bl sub_806F450
	mov r0, r9
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806D592
	mov r2, r9
	ldr r0, [r2, 0x70]
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806D592
	ldrb r0, [r5, 0xE]
	cmp r0, 0
	bne _0806D592
	ldr r0, _0806D5C8
	movs r3, 0
	ldrsh r0, [r0, r3]
	str r0, [r5]
_0806D592:
	ldr r0, _0806D5CC
	ldr r1, [sp, 0x50]
	cmp r1, r0
	beq _0806D5DC
	adds r0, r7, 0
	movs r1, 0xD
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D5DC
	ldr r1, [r5]
	ldr r0, _0806D5D0
	cmp r1, r0
	bne _0806D5DC
	ldr r0, _0806D5D4
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806D5D8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D71E
	.align 2, 0
_0806D5C8: .4byte gUnknown_80F4F8C
_0806D5CC: .4byte 0x0000020e
_0806D5D0: .4byte 0x0000270f
_0806D5D4: .4byte gUnknown_202DFE8
_0806D5D8: .4byte gUnknown_80FCA90
_0806D5DC:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r4, [r0]
	mov r10, r0
	cmp r4, 0x1
	bne _0806D618
	ldr r0, _0806D610
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806D614
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	mov r0, r9
	adds r1, r7, 0
	bl sub_8042238
	strb r4, [r5, 0xF]
_0806D608:
	movs r0, 0
	bl _0806E0F0
	.align 2, 0
_0806D610: .4byte gUnknown_202DFE8
_0806D614: .4byte gUnknown_80F9600
_0806D618:
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806D62A
	cmp r0, 0x5
	beq _0806D62A
	cmp r0, 0x3
	bne _0806D63A
_0806D62A:
	adds r0, r6, 0
	adds r0, 0xA9
	ldrb r0, [r0]
	cmp r0, 0x7F
	bne _0806D63A
	adds r0, r7, 0
	bl sub_807A9B0
_0806D63A:
	adds r0, r7, 0
	movs r1, 0x23
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D660
	ldrb r0, [r5, 0xC]
	cmp r0, 0x5
	bne _0806D660
_0806D64E:
	ldr r2, [r5]
	movs r0, 0
	str r0, [sp]
	mov r0, r9
	adds r1, r7, 0
	movs r3, 0
	bl HealTargetHP
	b _0806D754
_0806D660:
	adds r0, r7, 0
	movs r1, 0x24
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806D674
	ldrb r0, [r5, 0xC]
	cmp r0, 0x3
	beq _0806D64E
_0806D674:
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D6D0
	ldrb r0, [r5, 0xD]
	cmp r0, 0
	beq _0806D692
	ldr r0, _0806D6A4
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D692:
	ldr r0, [r5, 0x8]
	cmp r0, 0x1
	beq _0806D6B0
	cmp r0, 0x1
	bcc _0806D6A8
	cmp r0, 0x3
	beq _0806D6C4
	b _0806D6D0
	.align 2, 0
_0806D6A4: .4byte gUnknown_80F9614
_0806D6A8:
	ldr r0, _0806D6AC
	b _0806D6B2
	.align 2, 0
_0806D6AC: .4byte gUnknown_80F9630
_0806D6B0:
	ldr r0, _0806D6C0
_0806D6B2:
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D6D0
	.align 2, 0
_0806D6C0: .4byte gUnknown_80F9654
_0806D6C4:
	ldr r0, _0806D728
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D6D0:
	ldr r4, _0806D72C
	adds r0, r4, 0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r1, [r5]
	cmp r1, 0
	bne _0806D760
	mov r0, r9
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D734
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D734
	movs r3, 0xA9
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D71E
	ldr r0, _0806D730
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D71E:
	mov r0, r9
	adds r1, r7, 0
	bl sub_8042238
	b _0806D754
	.align 2, 0
_0806D728: .4byte gUnknown_80F9670
_0806D72C: .4byte gAvailablePokemonNames
_0806D730: .4byte gUnknown_80F9688
_0806D734:
	movs r1, 0xA9
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D74C
	ldr r0, _0806D75C
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D74C:
	movs r0, 0x1E
	movs r1, 0x18
	bl sub_803E708
_0806D754:
	movs r0, 0x1
	strb r0, [r5, 0xF]
	b _0806D608
	.align 2, 0
_0806D75C: .4byte gUnknown_80F9688
_0806D760:
	ldr r0, _0806D7B8
	cmp r1, r0
	bne _0806D7C4
	ldr r0, [sp, 0x80]
	cmp r0, 0
	beq _0806D796
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D796
	adds r0, r7, 0
	bl sub_8045128
	mov r8, r0
	movs r0, 0x14
	movs r1, 0x18
	bl sub_803E708
	mov r2, r8
	ldrh r1, [r2, 0x4]
	movs r0, 0x4
	orrs r0, r1
	strh r0, [r2, 0x4]
	bl sub_8049ED4
_0806D796:
	movs r3, 0xA9
	lsls r3, 1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D7AE
	ldr r0, _0806D7BC
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D7AE:
	adds r1, r6, 0
	adds r1, 0xA0
	ldr r0, _0806D7C0
	str r0, [r1]
	b _0806D84A
	.align 2, 0
_0806D7B8: .4byte 0x0000270f
_0806D7BC: .4byte gUnknown_80F96A8
_0806D7C0: .4byte 0x000003e7
_0806D7C4:
	ldr r0, _0806D824
	str r1, [r0]
	ldr r1, _0806D828
	ldr r0, [r5, 0x4]
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	adds r2, r6, 0
	adds r2, 0xA0
	ldr r0, [r2]
	ldr r1, [r5]
	adds r0, r1
	str r0, [r2]
	ldr r1, _0806D82C
	cmp r0, r1
	ble _0806D7E6
	str r1, [r2]
_0806D7E6:
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D830
	ldr r0, [r5, 0x4]
	cmp r0, 0xE
	beq _0806D808
	ldr r0, [r5]
	negs r0, r0
	movs r3, 0x1
	negs r3, r3
	adds r1, r7, 0
	movs r2, 0x1
	bl sub_803ED30
_0806D808:
	movs r1, 0xA9
	lsls r1, 1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D84A
	cmp r4, 0
	beq _0806D84A
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80522F4
	b _0806D84A
	.align 2, 0
_0806D824: .4byte gUnknown_202DE30
_0806D828: .4byte gUnknown_80F9764
_0806D82C: .4byte 0x000003e7
_0806D830:
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806D84A
	cmp r4, 0
	beq _0806D84A
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_80522F4
_0806D84A:
	ldr r0, [r5, 0x4]
	cmp r0, 0xE
	bne _0806D858
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	cmp r0, 0x1
	bgt _0806D900
_0806D858:
	mov r0, r8
	cmp r0, 0
	bne _0806D900
	adds r0, r7, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0806D900
	mov r2, r9
	ldr r1, [r2, 0x4]
	ldr r0, [r7, 0x4]
	cmp r1, r0
	beq _0806D8E6
	mov r0, r9
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806D8E6
	movs r4, 0
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806D8B4
	ldr r0, _0806D8B0
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _0806D8B6
	adds r0, r7, 0
	bl sub_806A458
	lsls r0, 24
	cmp r0, 0
	bne _0806D8B6
	adds r0, r7, 0
	mov r1, r9
	bl CanSee
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r4, r1, 31
	b _0806D8B6
	.align 2, 0
_0806D8B0: .4byte gUnknown_203B46C
_0806D8B4:
	movs r4, 0
_0806D8B6:
	adds r0, r6, 0
	adds r0, 0xE8
	ldrb r0, [r0]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806D8C8
	movs r4, 0
_0806D8C8:
	cmp r4, 0
	beq _0806D8E0
	ldr r4, [r7, 0x70]
	adds r0, r7, 0x4
	mov r1, r9
	adds r1, 0x4
	bl sub_80983D8
	movs r1, 0x7
	ands r0, r1
	adds r4, 0x46
	strb r0, [r4]
_0806D8E0:
	adds r0, r7, 0
	bl sub_8069DCC
_0806D8E6:
	ldr r0, [r7, 0x70]
	adds r0, 0x46
	ldrb r2, [r0]
	adds r0, r7, 0
	movs r1, 0x6
	bl sub_806CDD4
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_80420E8
	movs r3, 0x1
	str r3, [sp, 0x54]
_0806D900:
	movs r0, 0xE
	ldrsh r4, [r6, r0]
	ldr r1, [r5]
	cmp r4, r1
	ble _0806D910
	ldrh r0, [r6, 0xE]
	subs r0, r1
	b _0806D912
_0806D910:
	movs r0, 0
_0806D912:
	strh r0, [r6, 0xE]
	adds r0, r6, 0
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x9
	bne _0806D93C
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _0806D958
	movs r0, 0x1
	strh r0, [r6, 0xE]
	ldr r0, _0806D938
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806D958
	.align 2, 0
_0806D938: .4byte gUnknown_8100548
_0806D93C:
	ldr r2, [sp, 0x4C]
	cmp r2, 0x1
	bne _0806D958
	movs r3, 0xE
	ldrsh r0, [r6, r3]
	cmp r0, 0
	bne _0806D958
	strh r2, [r6, 0xE]
	ldr r0, _0806D9C8
	ldr r2, [r0]
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
_0806D958:
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	subs r4, r0
	cmp r4, 0
	bge _0806D964
	movs r4, 0
_0806D964:
	ldr r2, [sp, 0x54]
	cmp r2, 0
	bne _0806D970
	mov r3, r8
	cmp r3, 0
	beq _0806D978
_0806D970:
	movs r0, 0xA
	movs r1, 0x18
	bl sub_803E708
_0806D978:
	movs r1, 0xE
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _0806D9D4
	ldr r2, [sp, 0x54]
	cmp r2, 0
	beq _0806D98E
	adds r0, r7, 0
	movs r1, 0x8
	bl sub_806CE68
_0806D98E:
	adds r0, r7, 0
	movs r1, 0x10
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806D9B2
	cmp r4, 0
	ble _0806D9B2
	ldr r1, [r5]
	ldr r0, _0806D9CC
	cmp r1, r0
	beq _0806D9B2
	mov r0, r9
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_8071D4C
_0806D9B2:
	mov r3, r8
	cmp r3, 0
	bne _0806D9BA
	b _0806D608
_0806D9BA:
	ldrh r1, [r3, 0x4]
	ldr r0, _0806D9D0
	ands r0, r1
	strh r0, [r3, 0x4]
	bl sub_8049ED4
	b _0806D608
	.align 2, 0
_0806D9C8: .4byte gUnknown_810056C
_0806D9CC: .4byte 0x0000270f
_0806D9D0: .4byte 0x0000fffb
_0806D9D4:
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0806D9E6
	mov r0, r9
	adds r1, r7, 0
	bl sub_807A7C8
_0806D9E6:
	mov r0, r8
	cmp r0, 0
	beq _0806DA18
	movs r0, 0x14
	movs r1, 0x18
	bl sub_803E708
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0x2
	strb r0, [r1]
	movs r0, 0xA
	movs r1, 0x18
	bl sub_803E708
	mov r2, r8
	ldrh r1, [r2, 0x4]
	ldr r0, _0806DA14
	ands r0, r1
	strh r0, [r2, 0x4]
	bl sub_8049ED4
	b _0806DA2E
	.align 2, 0
_0806DA14: .4byte 0x0000fffb
_0806DA18:
	ldr r3, [sp, 0x54]
	cmp r3, 0
	beq _0806DA2E
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1E
	movs r1, 0x18
	bl sub_803E708
_0806DA2E:
	movs r0, 0x1
	mov r8, r0
	mov r0, r9
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806DA50
	mov r0, r9
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806DA50
	cmp r9, r7
	beq _0806DA50
	movs r1, 0
	mov r8, r1
_0806DA50:
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0
	strb r0, [r1]
	ldr r4, _0806DA88
	adds r0, r4, 0
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, [r5, 0x4]
	subs r0, 0x13
	cmp r0, 0x1
	bhi _0806DA9C
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806DA90
	ldr r0, _0806DA8C
	ldr r2, [r0]
	b _0806DAC2
	.align 2, 0
_0806DA88: .4byte gAvailablePokemonNames
_0806DA8C: .4byte gUnknown_80F9E44
_0806DA90:
	ldr r0, _0806DA98
	ldr r1, [r0]
	b _0806DB86
	.align 2, 0
_0806DA98: .4byte gUnknown_80F9E44
_0806DA9C:
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806DAD0
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806DAB8
	ldr r0, _0806DAB4
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DAB4: .4byte gUnknown_80F9DF0
_0806DAB8:
	ldr r0, _0806DACC
	mov r2, r8
	lsls r1, r2, 2
	adds r1, r0
	ldr r2, [r1]
_0806DAC2:
	mov r0, r9
	adds r1, r7, 0
	bl sub_80522F4
	b _0806DBA4
	.align 2, 0
_0806DACC: .4byte gUnknown_80F9CC0
_0806DAD0:
	ldr r2, _0806DB04
	ldrb r1, [r6, 0xA]
	movs r0, 0x64
	muls r0, r1
	ldr r3, _0806DB08
	adds r0, r3
	ldr r1, [r2]
	adds r3, r1, r0
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806DB00
	adds r0, r6, 0
	adds r0, 0x40
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0x41
	bne _0806DB18
	ldr r0, _0806DB0C
	ldr r0, [r0]
	ldr r1, _0806DB10
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806DB18
_0806DB00:
	ldr r0, _0806DB14
	b _0806DB7E
	.align 2, 0
_0806DB04: .4byte gRecruitedPokemonRef
_0806DB08: .4byte 0x00008df8
_0806DB0C: .4byte gDungeonGlobalData
_0806DB10: .4byte 0x0000065c
_0806DB14: .4byte gUnknown_80F9CEC
_0806DB18:
	ldrb r0, [r2]
	cmp r0, 0x4A
	beq _0806DB22
	cmp r0, 0x47
	bne _0806DB26
_0806DB22:
	movs r0, 0x1
	b _0806DB28
_0806DB26:
	movs r0, 0
_0806DB28:
	cmp r0, 0
	beq _0806DB38
	ldr r0, _0806DB34
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DB34: .4byte gUnknown_80F9DAC
_0806DB38:
	adds r0, r6, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806DB4C
	ldr r0, _0806DB48
	b _0806DB7E
	.align 2, 0
_0806DB48: .4byte gUnknown_80F9DF0
_0806DB4C:
	movs r1, 0xA
	ldrsh r0, [r3, r1]
	bl sub_806A58C
	lsls r0, 24
	cmp r0, 0
	beq _0806DB94
	ldr r0, _0806DB70
	ldr r0, [r0]
	ldr r2, _0806DB74
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DB7C
	ldr r0, _0806DB78
	mov r3, r8
	lsls r1, r3, 2
	b _0806DB82
	.align 2, 0
_0806DB70: .4byte gDungeonGlobalData
_0806DB74: .4byte 0x0000065d
_0806DB78: .4byte gUnknown_80F9D8C
_0806DB7C:
	ldr r0, _0806DB90
_0806DB7E:
	mov r2, r8
	lsls r1, r2, 2
_0806DB82:
	adds r1, r0
	ldr r1, [r1]
_0806DB86:
	mov r0, r9
	bl sub_805239C
	b _0806DBA4
	.align 2, 0
_0806DB90: .4byte gUnknown_80F9D84
_0806DB94:
	ldr r0, _0806DC4C
	mov r3, r8
	lsls r1, r3, 2
	adds r1, r0
	ldr r1, [r1]
	mov r0, r9
	bl sub_805239C
_0806DBA4:
	mov r1, r10
	ldrb r0, [r1]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0806DBBC
	adds r0, r6, 0
	adds r0, 0x9C
	ldr r0, [r0]
	bl sub_8076CB4
_0806DBBC:
	adds r1, r6, 0
	adds r1, 0x60
	ldrb r3, [r1]
	movs r2, 0x1
	mov r8, r2
	mov r0, r8
	ands r0, r3
	adds r5, r1, 0
	cmp r0, 0
	beq _0806DC5C
	movs r0, 0x8
	ands r0, r3
	cmp r0, 0
	bne _0806DC5C
	movs r0, 0x2
	ands r0, r3
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0806DC5C
	ldrb r0, [r5, 0x2]
	cmp r0, 0xD2
	bne _0806DC5C
	adds r0, r7, 0
	bl sub_8042148
	adds r0, r7, 0
	adds r0, 0x22
	strb r4, [r0]
	ldrh r0, [r6, 0x10]
	movs r2, 0
	strh r0, [r6, 0xE]
	movs r3, 0xAC
	lsls r3, 1
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	mov r3, r8
	strb r3, [r0]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	movs r3, 0xA0
	lsls r3, 1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DC36
	ldr r0, _0806DC50
	ldr r1, [r0]
	ldr r3, _0806DC54
	adds r1, r3
	strb r2, [r1]
	ldr r0, [r0]
	ldr r1, _0806DC58
	adds r0, r1
	strb r2, [r0]
_0806DC36:
	strb r2, [r5, 0x2]
	strb r2, [r5, 0x1]
	strb r2, [r5]
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DC48
	b _0806DEC8
_0806DC48:
	b _0806DEE4
	.align 2, 0
_0806DC4C: .4byte gUnknown_80F9D28
_0806DC50: .4byte gDungeonGlobalData
_0806DC54: .4byte 0x00000679
_0806DC58: .4byte 0x00000676
_0806DC5C:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806DC64
	b _0806DDFC
_0806DC64:
	mov r10, r5
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0806DC72
	b _0806DDFC
_0806DC72:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806DC7C
	b _0806DDFC
_0806DC7C:
	ldrb r0, [r5, 0x2]
	cmp r0, 0xD8
	beq _0806DC84
	b _0806DDFC
_0806DC84:
	movs r4, 0
_0806DC86:
	ldr r0, _0806DD80
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _0806DD84
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806DCDE
	cmp r8, r7
	beq _0806DCDE
	adds r0, r7, 0
	mov r1, r8
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	beq _0806DCDE
	mov r3, r8
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	movs r2, 0x4
	ldrsh r0, [r7, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806DCC4
	negs r1, r1
_0806DCC4:
	cmp r1, 0x1
	bgt _0806DCDE
	mov r3, r8
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0x6
	ldrsh r0, [r7, r2]
	subs r1, r0
	cmp r1, 0
	bge _0806DCDA
	negs r1, r1
_0806DCDA:
	cmp r1, 0x1
	ble _0806DCE4
_0806DCDE:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806DC86
_0806DCE4:
	cmp r4, 0x4
	bne _0806DCEA
	b _0806DDFC
_0806DCEA:
	adds r0, r7, 0
	bl sub_8042148
	mov r3, r8
	ldr r4, [r3, 0x4]
	ldr r1, _0806DD88
	mov r0, r8
	adds r2, r7, 0
	bl sub_8068FE0
	lsls r1, r4, 16
	asrs r1, 16
	asrs r4, 16
	adds r0, r7, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_80694C0
	adds r0, r7, 0
	movs r1, 0
	bl sub_804535C
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r6, 0x10]
	movs r4, 0
	strh r0, [r6, 0xE]
	adds r0, r7, 0
	bl sub_8042A24
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r6, r1
	strb r4, [r0]
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0x1
	strb r0, [r1]
	movs r3, 0x9E
	lsls r3, 1
	adds r1, r6, r3
	subs r2, 0xC
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DD62
	ldr r0, _0806DD80
	ldr r1, [r0]
	ldr r3, _0806DD8C
	adds r1, r3
	strb r4, [r1]
	ldr r0, [r0]
	ldr r1, _0806DD90
	adds r0, r1
	strb r4, [r0]
_0806DD62:
	mov r2, r10
	strb r4, [r2, 0x2]
	strb r4, [r2, 0x1]
	strb r4, [r2]
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DD94
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x3
	bl sub_807A5D0
	b _0806DDA2
	.align 2, 0
_0806DD80: .4byte gDungeonGlobalData
_0806DD84: .4byte 0x0001357c
_0806DD88: .4byte 0x00000221
_0806DD8C: .4byte 0x00000679
_0806DD90: .4byte 0x00000676
_0806DD94:
	cmp r0, 0x2
	bne _0806DDA2
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x2
	bl sub_807A5D0
_0806DDA2:
	adds r0, r7, 0
	bl sub_8078084
	adds r0, r6, 0
	movs r1, 0
	bl sub_806BFC0
	bl sub_800DBBC
	adds r0, r7, 0
	bl sub_806A390
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	adds r0, r7, 0
	bl sub_80418D4
	ldr r4, _0806DDF0
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	adds r4, 0x50
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806DDF4
	b _0806DF2E
	.align 2, 0
_0806DDF0: .4byte gAvailablePokemonNames
_0806DDF4: .4byte gUnknown_80FD484
_0806DDF8:
	mov r4, r8
	b _0806DE64
_0806DDFC:
	adds r0, r7, 0
	movs r1, 0x16
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	bne _0806DE0C
	b _0806DF48
_0806DE0C:
	movs r4, 0
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806DE28
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806DE28
	ldrb r0, [r5, 0x2]
	cmp r0, 0x3A
	bne _0806DE28
	adds r4, r5, 0
_0806DE28:
	cmp r4, 0
	bne _0806DE68
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	bne _0806DE64
	movs r3, 0
	ldr r0, _0806DED4
	ldr r2, [r0]
	mov r12, r2
	movs r0, 0x1
	mov r10, r0
_0806DE3E:
	lsls r0, r3, 2
	add r0, r12
	mov r8, r0
	ldrb r1, [r2]
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	beq _0806DE5C
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806DE5C
	ldrb r0, [r2, 0x2]
	cmp r0, 0x3A
	beq _0806DDF8
_0806DE5C:
	adds r2, 0x4
	adds r3, 0x1
	cmp r3, 0x13
	ble _0806DE3E
_0806DE64:
	cmp r4, 0
	beq _0806DF48
_0806DE68:
	adds r0, r7, 0
	bl sub_8042148
	adds r0, r4, 0
	movs r1, 0x46
	movs r2, 0x2
	bl sub_8045C28
	adds r1, r7, 0
	adds r1, 0x22
	movs r0, 0
	strb r0, [r1]
	ldrh r0, [r6, 0x10]
	movs r2, 0
	strh r0, [r6, 0xE]
	movs r1, 0xAC
	lsls r1, 1
	adds r0, r6, r1
	strb r2, [r0]
	movs r3, 0xA6
	lsls r3, 1
	adds r1, r6, r3
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	subs r3, 0xC
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _0806DEBE
	ldr r0, _0806DED8
	ldr r1, [r0]
	ldr r3, _0806DEDC
	adds r1, r3
	strb r2, [r1]
	ldr r0, [r0]
	ldr r1, _0806DEE0
	adds r0, r1
	strb r2, [r0]
_0806DEBE:
	adds r0, r6, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806DEE4
_0806DEC8:
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x3
	bl sub_807A5D0
	b _0806DEF2
	.align 2, 0
_0806DED4: .4byte gTeamInventory_203B460
_0806DED8: .4byte gDungeonGlobalData
_0806DEDC: .4byte 0x00000679
_0806DEE0: .4byte 0x00000676
_0806DEE4:
	cmp r0, 0x2
	bne _0806DEF2
	mov r0, r9
	adds r1, r7, 0
	movs r2, 0x2
	bl sub_807A5D0
_0806DEF2:
	adds r0, r7, 0
	bl sub_8078084
	adds r0, r6, 0
	movs r1, 0
	bl sub_806BFC0
	bl sub_800DBBC
	adds r0, r7, 0
	bl sub_806A390
	adds r0, r7, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl sub_806CCB4
	adds r0, r7, 0
	bl sub_80418D4
	ldr r0, _0806DF40
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806DF44
_0806DF2E:
	ldr r1, [r0]
	mov r0, r9
	bl sub_805239C
	adds r0, r7, 0
	bl sub_806F63C
	bl _0806D608
	.align 2, 0
_0806DF40: .4byte gUnknown_202DFE8
_0806DF44: .4byte gUnknown_80FD46C
_0806DF48:
	ldrb r4, [r6, 0x7]
	cmp r4, 0
	bne _0806DF68
	ldrb r1, [r5]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806DF68
	adds r1, r7, 0x4
	adds r0, r7, 0
	adds r2, r5, 0
	bl sub_80464C8
	strb r4, [r5, 0x2]
	strb r4, [r5, 0x1]
	strb r4, [r5]
_0806DF68:
	adds r0, r6, 0
	adds r0, 0xF7
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DF7E
	ldr r0, _0806E02C
	ldr r0, [r0]
	ldr r2, _0806E030
	adds r0, r2
	ldr r1, _0806E034
	strh r1, [r0]
_0806DF7E:
	movs r3, 0
	mov r10, r3
	mov r0, r9
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806E066
	mov r0, r9
	ldr r4, [r0, 0x70]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	ldrb r1, [r6, 0x9]
	bl CalculateEXPGain
	adds r5, r0, 0
	adds r0, r6, 0
	adds r0, 0xFB
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DFAE
	cmp r0, 0x2
	bne _0806DFB4
	lsls r0, r5, 1
	adds r5, r0, r5
_0806DFAE:
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
_0806DFB4:
	cmp r5, 0
	bne _0806DFBA
	movs r5, 0x1
_0806DFBA:
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	beq _0806DFC8
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	bl sub_80980B4
_0806DFC8:
	adds r0, r6, 0
	adds r0, 0xF4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806DFDA
	ldr r3, _0806E038
	adds r1, r4, r3
	movs r0, 0x1
	strb r0, [r1]
_0806DFDA:
	ldr r0, [sp, 0x78]
	cmp r0, 0x1
	bne _0806E066
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _0806E040
	ldrb r0, [r6, 0x6]
	cmp r0, 0
	beq _0806E066
	mov r0, r9
	mov r1, r9
	adds r2, r5, 0
	bl sub_8071D4C
	movs r6, 0
_0806DFF8:
	ldr r0, _0806E02C
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0806E03C
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E020
	cmp r4, r9
	beq _0806E020
	mov r0, r9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_8071D4C
_0806E020:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0806DFF8
	movs r3, 0x1
	mov r10, r3
	b _0806E066
	.align 2, 0
_0806E02C: .4byte gDungeonGlobalData
_0806E030: .4byte 0x0000066a
_0806E034: .4byte 0x000003e7
_0806E038: .4byte 0x0000014b
_0806E03C: .4byte 0x0001357c
_0806E040:
	ldr r5, _0806E0BC
	ldr r0, [r5]
	ldr r1, _0806E0C0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_809033C
	lsls r0, 24
	cmp r0, 0
	beq _0806E066
	ldr r2, _0806E0C4
	adds r0, r4, r2
	add r3, sp, 0x78
	ldrb r3, [r3]
	strb r3, [r0]
	ldr r0, [r5]
	add r1, sp, 0x78
	ldrb r1, [r1]
	strb r1, [r0, 0xD]
_0806E066:
	mov r0, r9
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E08A
	mov r0, r9
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806E08A
	mov r2, r9
	ldr r0, [r2, 0x70]
	ldrb r0, [r0, 0x7]
	cmp r0, 0
	bne _0806E08A
	movs r3, 0
	mov r10, r3
_0806E08A:
	mov r0, r10
	cmp r0, 0
	beq _0806E0E4
	add r0, sp, 0x4
	adds r1, r7, 0
	bl sub_8069D4C
	mov r0, r9
	adds r1, r7, 0
	bl sub_806F660
	lsls r0, 24
	cmp r0, 0
	beq _0806E0D8
	mov r0, r9
	adds r1, r7, 0
	add r2, sp, 0x4
	bl sub_806FA5C
	lsls r0, 24
	cmp r0, 0
	bne _0806E0CC
	ldr r1, _0806E0C8
	adds r0, r7, 0
	b _0806E0DC
	.align 2, 0
_0806E0BC: .4byte gDungeonGlobalData
_0806E0C0: .4byte 0x00000644
_0806E0C4: .4byte 0x00000149
_0806E0C8: .4byte 0x000001f5
_0806E0CC:
	ldr r1, _0806E0D4
	movs r0, 0x1
	strb r0, [r1]
	b _0806E0EE
	.align 2, 0
_0806E0D4: .4byte gUnknown_202F221
_0806E0D8:
	adds r0, r7, 0
	ldr r1, [sp, 0x50]
_0806E0DC:
	mov r2, r9
	bl sub_8068FE0
	b _0806E0EE
_0806E0E4:
	adds r0, r7, 0
	ldr r1, [sp, 0x50]
	mov r2, r9
	bl sub_8068FE0
_0806E0EE:
	movs r0, 0x1
_0806E0F0:
	add sp, 0x58
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806D528

	thumb_func_start sub_806E100
sub_806E100:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r6, r0, 0
	mov r8, r1
	str r2, [sp, 0x18]
	lsls r3, 24
	lsrs r7, r3, 24
	movs r0, 0
	mov r9, r0
	movs r1, 0
	str r1, [sp, 0x20]
	mov r2, r8
	ldr r2, [r2, 0x70]
	str r2, [sp, 0x24]
	ldr r3, [sp, 0x18]
	ldr r3, [r3, 0x70]
	mov r10, r3
	adds r0, r6, 0
	movs r1, 0x1
	bl sub_800A020
	mov r0, r9
	ldr r4, [sp, 0x48]
	strb r0, [r4, 0xD]
	strb r0, [r4, 0xE]
	movs r1, 0
	str r1, [sp, 0x1C]
	ldr r0, [sp, 0x18]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806E14E
	movs r0, 0x1
	b _0806E61A
_0806E14E:
	cmp r7, 0x1
	beq _0806E156
	cmp r7, 0x7
	bne _0806E15A
_0806E156:
	movs r2, 0x1
	str r2, [sp, 0x20]
_0806E15A:
	ldr r0, [sp, 0x18]
	movs r1, 0x35
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E170
	cmp r7, 0
	beq _0806E170
	movs r3, 0x1
	str r3, [sp, 0x1C]
_0806E170:
	movs r0, 0x2
	ldr r4, [sp, 0x48]
	str r0, [r4, 0x8]
	movs r5, 0
	add r0, sp, 0x10
	mov r9, r0
	b _0806E1F2
_0806E17E:
	mov r1, r10
	adds r1, 0x5C
	ldr r2, [sp, 0x20]
	cmp r2, 0
	beq _0806E1B4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _0806E1B4
	mov r0, r10
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806E1B4
	movs r4, 0
	ldr r0, _0806E1AC
	ldr r0, [r0]
	ldr r3, _0806E1B0
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	b _0806E1CA
	.align 2, 0
_0806E1AC: .4byte gDungeonGlobalData
_0806E1B0: .4byte 0x00000179
_0806E1B4:
	ldr r2, _0806E4E4
	adds r0, r1, r5
	ldrb r1, [r0]
	lsls r1, 1
	lsls r0, r7, 3
	adds r0, r7
	lsls r0, 2
	adds r1, r0
	adds r1, r2
	movs r0, 0
	ldrsh r4, [r1, r0]
_0806E1CA:
	cmp r4, 0x2
	beq _0806E1DC
	lsls r0, r4, 2
	add r0, sp
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E1DC:
	lsls r0, r5, 2
	add r0, r9
	str r4, [r0]
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r1, 0x9E
	lsls r1, 1
	adds r0, r1
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0806E1F2:
	cmp r5, 0x1
	bgt _0806E20E
	mov r1, sp
	ldr r0, _0806E4EC
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r6, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	beq _0806E17E
_0806E20E:
	ldr r2, _0806E4F0
	mov r1, r9
	ldr r0, [r1, 0x4]
	lsls r0, 2
	ldr r1, [sp, 0x10]
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [sp, 0x48]
	str r0, [r2, 0x8]
	movs r3, 0x1
	mov r9, r3
	cmp r0, 0x3
	beq _0806E240
	movs r4, 0
	mov r9, r4
	ldr r0, [sp, 0x1C]
	cmp r0, 0
	beq _0806E240
	ldr r0, _0806E4F4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r6]
	str r1, [r6, 0x4]
_0806E240:
	cmp r7, 0x2
	beq _0806E248
	cmp r7, 0x6
	bne _0806E26C
_0806E248:
	ldr r0, [sp, 0x18]
	movs r1, 0x2
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E26C
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r2, _0806E4F8
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E4FC
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E26C:
	cmp r7, 0x2
	bne _0806E2A0
	ldr r0, [sp, 0x18]
	bl sub_807723C
	lsls r0, 24
	cmp r0, 0
	beq _0806E2A0
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r3, 0xB7
	lsls r3, 1
	adds r0, r3
	movs r4, 0
	movs r5, 0x1
	strb r5, [r0]
	adds r0, r6, 0
	movs r1, 0
	bl sub_800A020
	ldr r0, [sp, 0x48]
	str r4, [r0, 0x8]
	strb r4, [r0, 0xD]
	strb r5, [r0, 0xE]
	movs r1, 0
	mov r9, r1
_0806E2A0:
	cmp r7, 0x9
	bne _0806E2D2
	ldr r0, [sp, 0x18]
	movs r1, 0x37
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E2D2
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r2, _0806E500
	adds r0, r2
	movs r4, 0
	movs r5, 0x1
	strb r5, [r0]
	adds r0, r6, 0
	movs r1, 0
	bl sub_800A020
	ldr r3, [sp, 0x48]
	str r4, [r3, 0x8]
	strb r4, [r3, 0xD]
	strb r5, [r3, 0xE]
	mov r9, r4
_0806E2D2:
	cmp r7, 0x3
	bne _0806E340
	mov r0, r8
	movs r1, 0x10
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E340
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E2F2
	adds r1, 0x3
_0806E2F2:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E300
	movs r4, 0x1
_0806E300:
	ldr r0, [sp, 0x24]
	movs r1, 0x80
	adds r2, r4, 0
	bl sub_8071ACC
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E32A
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r3
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E32A:
	cmp r5, 0
	beq _0806E340
	mov r0, r8
	bl sub_80428EC
	ldr r0, _0806E508
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E340:
	cmp r7, 0x4
	bne _0806E3AC
	mov r0, r8
	movs r1, 0x1A
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E3AC
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E360
	adds r1, 0x3
_0806E360:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E36E
	movs r4, 0x1
_0806E36E:
	ldr r0, [sp, 0x24]
	movs r1, 0x2
	adds r2, r4, 0
	bl sub_8071ACC
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E396
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r3, _0806E50C
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E396:
	cmp r5, 0
	beq _0806E3AC
	mov r0, r8
	bl sub_80428D8
	ldr r0, _0806E510
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E3AC:
	cmp r7, 0xC
	bne _0806E41A
	mov r0, r8
	movs r1, 0x43
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E41A
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E3CC
	adds r1, 0x3
_0806E3CC:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E3DA
	movs r4, 0x1
_0806E3DA:
	ldr r0, [sp, 0x24]
	movs r1, 0x10
	adds r2, r4, 0
	bl sub_8071ACC
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E404
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r3, 0xB9
	lsls r3, 1
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E404:
	cmp r5, 0
	beq _0806E41A
	mov r0, r8
	bl sub_8042978
	ldr r0, _0806E514
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E41A:
	cmp r7, 0x2
	bne _0806E486
	mov r0, r8
	movs r1, 0x46
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E486
	movs r4, 0
	ldr r0, [sp, 0x24]
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E43A
	adds r1, 0x3
_0806E43A:
	asrs r1, 2
	ldr r3, [sp, 0x24]
	movs r2, 0xE
	ldrsh r0, [r3, r2]
	cmp r1, r0
	blt _0806E448
	movs r4, 0x1
_0806E448:
	ldr r0, [sp, 0x24]
	movs r1, 0x20
	adds r2, r4, 0
	bl sub_8071ACC
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r4, 0
	beq _0806E470
	ldr r0, _0806E4E8
	ldr r0, [r0]
	ldr r3, _0806E518
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E504
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E470:
	cmp r5, 0
	beq _0806E486
	mov r0, r8
	bl sub_804298C
	ldr r0, _0806E51C
	ldr r2, [r0]
	mov r0, r8
	ldr r1, [sp, 0x18]
	bl sub_80522F4
_0806E486:
	adds r0, r6, 0
	bl sub_800A2A0
	lsls r0, 24
	cmp r0, 0
	bne _0806E4B8
	mov r0, r8
	adds r1, r7, 0
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	beq _0806E4B8
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r4, 0xBA
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strb r1, [r0]
	ldr r2, _0806E520
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E4B8:
	mov r0, r8
	bl sub_807E580
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0806E53E
	cmp r7, 0x2
	bne _0806E524
	ldr r0, _0806E4E8
	ldr r0, [r0]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	strb r4, [r0]
	ldr r2, _0806E520
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
	b _0806E53E
	.align 2, 0
_0806E4E4: .4byte gUnknown_80F522C
_0806E4E8: .4byte gDungeonGlobalData
_0806E4EC: .4byte gUnknown_8106F54
_0806E4F0: .4byte gUnknown_80F54B4
_0806E4F4: .4byte gUnknown_8106EFC
_0806E4F8: .4byte 0x0000016d
_0806E4FC: .4byte gUnknown_8106F1C
_0806E500: .4byte 0x0000016f
_0806E504: .4byte gUnknown_8106F0C
_0806E508: .4byte gUnknown_80FEDA8
_0806E50C: .4byte 0x00000171
_0806E510: .4byte gUnknown_80FED88
_0806E514: .4byte gUnknown_80FEDC8
_0806E518: .4byte 0x00000173
_0806E51C: .4byte gUnknown_80FEDE8
_0806E520: .4byte gUnknown_8106F14
_0806E524:
	cmp r7, 0x3
	bne _0806E53E
	ldr r0, _0806E560
	ldr r0, [r0]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	strb r4, [r0]
	ldr r2, _0806E564
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E53E:
	cmp r4, 0x4
	bne _0806E586
	cmp r7, 0x2
	bne _0806E56C
	ldr r0, _0806E560
	ldr r0, [r0]
	ldr r3, _0806E568
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E564
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
	b _0806E586
	.align 2, 0
_0806E560: .4byte gDungeonGlobalData
_0806E564: .4byte gUnknown_8106F1C
_0806E568: .4byte 0x0000016b
_0806E56C:
	cmp r7, 0x3
	bne _0806E586
	ldr r0, _0806E62C
	ldr r0, [r0]
	ldr r2, _0806E630
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E634
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E586:
	cmp r4, 0x3
	bne _0806E5A6
	cmp r7, 0x1
	beq _0806E5A6
	ldr r2, _0806E638
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
	ldr r0, _0806E62C
	ldr r0, [r0]
	movs r3, 0xB5
	lsls r3, 1
	adds r1, r0, r3
	movs r0, 0x1
	strb r0, [r1]
_0806E5A6:
	ldr r0, _0806E62C
	ldr r1, [r0]
	ldr r2, _0806E63C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806E5B8
	cmp r4, 0x6
	bne _0806E5CE
_0806E5B8:
	cmp r7, 0x5
	bne _0806E5CE
	ldr r3, _0806E640
	adds r1, r3
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E644
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E5CE:
	ldr r0, _0806E62C
	ldr r1, [r0]
	ldr r4, _0806E648
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806E5F4
	cmp r7, 0x2
	bne _0806E5F4
	movs r0, 0xBB
	lsls r0, 1
	adds r1, r0
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E644
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E5F4:
	cmp r7, 0x5
	bne _0806E618
	ldr r0, [sp, 0x24]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0xB
	bne _0806E618
	ldr r0, _0806E62C
	ldr r0, [r0]
	ldr r2, _0806E64C
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
	ldr r2, _0806E650
	adds r0, r6, 0
	adds r1, r6, 0
	bl sub_800A34C
_0806E618:
	mov r0, r9
_0806E61A:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806E62C: .4byte gDungeonGlobalData
_0806E630: .4byte 0x0000016b
_0806E634: .4byte gUnknown_8106F14
_0806E638: .4byte gUnknown_8106F64
_0806E63C: .4byte 0x0000e277
_0806E640: .4byte 0x00000175
_0806E644: .4byte gUnknown_8106F1C
_0806E648: .4byte 0x0000e278
_0806E64C: .4byte 0x00000177
_0806E650: .4byte gUnknown_8106F0C
	thumb_func_end sub_806E100

	thumb_func_start sub_806E654
sub_806E654:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	mov r9, r0
	str r1, [sp, 0x14]
	lsls r2, 24
	lsrs r4, r2, 24
	movs r5, 0x1
	movs r0, 0
	str r0, [sp, 0x10]
	adds r0, r1, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0806E6DC
	cmp r4, 0x1
	beq _0806E682
	cmp r4, 0x7
	bne _0806E686
_0806E682:
	movs r1, 0x1
	str r1, [sp, 0x10]
_0806E686:
	mov r2, r9
	ldr r2, [r2, 0x70]
	mov r8, r2
	ldr r3, [sp, 0x14]
	ldr r3, [r3, 0x70]
	mov r10, r3
	cmp r4, 0x2
	bne _0806E6A2
	ldr r0, [sp, 0x14]
	bl sub_807723C
	lsls r0, 24
	cmp r0, 0
	bne _0806E6C6
_0806E6A2:
	cmp r4, 0x5
	bne _0806E6B4
	ldr r0, [sp, 0x14]
	movs r1, 0x23
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _0806E6C6
_0806E6B4:
	cmp r4, 0x3
	bne _0806E6CA
	ldr r0, [sp, 0x14]
	movs r1, 0x24
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E6CA
_0806E6C6:
	movs r0, 0
	b _0806E894
_0806E6CA:
	cmp r4, 0x9
	bne _0806E6E0
	ldr r0, [sp, 0x14]
	movs r1, 0x37
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E6E0
_0806E6DC:
	movs r0, 0x1
	b _0806E894
_0806E6E0:
	mov r6, r10
	adds r6, 0x5C
	str r6, [sp, 0x18]
	lsls r0, r4, 3
	adds r0, r4
	lsls r0, 2
	mov r12, r0
	adds r2, r6, 0
_0806E6F0:
	mov r0, sp
	ldr r1, _0806E724
	ldm r1!, {r3,r6,r7}
	stm r0!, {r3,r6,r7}
	ldr r1, [r1]
	str r1, [r0]
	ldr r7, [sp, 0x10]
	cmp r7, 0
	beq _0806E730
	ldrb r0, [r2]
	cmp r0, 0xE
	bne _0806E730
	mov r0, r10
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806E730
	movs r3, 0
	ldr r0, _0806E728
	ldr r0, [r0]
	ldr r6, _0806E72C
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
	b _0806E73E
	.align 2, 0
_0806E724: .4byte gUnknown_8106F6C
_0806E728: .4byte gDungeonGlobalData
_0806E72C: .4byte 0x00000179
_0806E730:
	ldrb r0, [r2]
	lsls r0, 1
	add r0, r12
	ldr r7, _0806E854
	adds r0, r7
	movs r1, 0
	ldrsh r3, [r0, r1]
_0806E73E:
	cmp r5, 0
	beq _0806E75E
	lsls r0, r3, 2
	add r0, sp
	ldr r0, [r0]
	muls r5, r0
	lsrs r0, r5, 31
	adds r0, r5, r0
	asrs r5, r0, 1
	cmp r5, 0
	beq _0806E84E
	adds r2, 0x1
	ldr r0, [sp, 0x18]
	adds r0, 0x1
	cmp r2, r0
	ble _0806E6F0
_0806E75E:
	cmp r4, 0x2
	beq _0806E766
	cmp r4, 0x6
	bne _0806E774
_0806E766:
	ldr r0, [sp, 0x14]
	movs r1, 0x2
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _0806E84E
_0806E774:
	cmp r4, 0x3
	bne _0806E7A0
	mov r0, r9
	movs r1, 0x10
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E7A0
	mov r2, r8
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	cmp r1, 0
	bge _0806E792
	adds r1, 0x3
_0806E792:
	asrs r1, 2
	mov r6, r8
	movs r7, 0xE
	ldrsh r0, [r6, r7]
	cmp r1, r0
	blt _0806E7A0
	lsls r5, 1
_0806E7A0:
	cmp r4, 0x4
	bne _0806E7CC
	mov r0, r9
	movs r1, 0x1A
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E7CC
	mov r0, r8
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bge _0806E7BE
	adds r1, 0x3
_0806E7BE:
	asrs r1, 2
	mov r3, r8
	movs r6, 0xE
	ldrsh r0, [r3, r6]
	cmp r1, r0
	blt _0806E7CC
	lsls r5, 1
_0806E7CC:
	cmp r4, 0xC
	bne _0806E7F8
	mov r0, r9
	movs r1, 0x43
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E7F8
	mov r7, r8
	movs r0, 0x10
	ldrsh r1, [r7, r0]
	cmp r1, 0
	bge _0806E7EA
	adds r1, 0x3
_0806E7EA:
	asrs r1, 2
	mov r2, r8
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _0806E7F8
	lsls r5, 1
_0806E7F8:
	cmp r4, 0x2
	bne _0806E824
	mov r0, r9
	movs r1, 0x46
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E824
	mov r6, r8
	movs r7, 0x10
	ldrsh r1, [r6, r7]
	cmp r1, 0
	bge _0806E816
	adds r1, 0x3
_0806E816:
	asrs r1, 2
	mov r2, r8
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _0806E824
	lsls r5, 1
_0806E824:
	cmp r5, 0
	beq _0806E84E
	mov r0, r9
	adds r1, r4, 0
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	beq _0806E838
	lsls r5, 1
_0806E838:
	mov r0, r9
	bl sub_807E580
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0806E85A
	cmp r4, 0x2
	beq _0806E858
	cmp r4, 0x3
	bne _0806E85A
_0806E84E:
	movs r0, 0x2
	b _0806E894
	.align 2, 0
_0806E854: .4byte gUnknown_80F522C
_0806E858:
	lsls r5, 1
_0806E85A:
	ldr r0, _0806E8A4
	ldr r1, [r0]
	ldr r6, _0806E8A8
	adds r1, r6
	ldrb r1, [r1]
	cmp r1, 0
	beq _0806E86C
	cmp r4, 0x5
	beq _0806E84E
_0806E86C:
	ldr r0, [r0]
	ldr r7, _0806E8AC
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806E87C
	cmp r4, 0x2
	beq _0806E84E
_0806E87C:
	cmp r4, 0x5
	bne _0806E88C
	mov r0, r8
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0xB
	bne _0806E88C
	lsls r5, 1
_0806E88C:
	cmp r5, 0x2
	ble _0806E892
	movs r5, 0x3
_0806E892:
	adds r0, r5, 0x2
_0806E894:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806E8A4: .4byte gDungeonGlobalData
_0806E8A8: .4byte 0x0000e277
_0806E8AC: .4byte 0x0000e278
	thumb_func_end sub_806E654

	thumb_func_start sub_806E8B0
sub_806E8B0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r6, r0, 0
	mov r9, r1
	adds r0, r2, 0
	str r3, [sp]
	lsls r0, 24
	lsrs r0, 24
	movs r7, 0x1
	movs r1, 0x1
	mov r8, r1
	movs r2, 0x1
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	bl sub_8092354
	movs r2, 0
	mov r10, r2
	lsls r0, 24
	cmp r0, 0
	bne _0806E8E6
	movs r0, 0x1
	mov r10, r0
_0806E8E6:
	adds r0, r6, 0
	movs r1, 0x11
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E92C
	ldr r5, [r6, 0x70]
	adds r0, r6, 0
	bl sub_8070A58
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_8071ACC
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0
	beq _0806E916
	movs r7, 0x2
_0806E916:
	cmp r0, 0
	beq _0806E92C
	adds r0, r6, 0
	bl sub_80428B0
	ldr r0, _0806EADC
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
_0806E92C:
	adds r0, r6, 0
	movs r1, 0x22
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _0806E948
	adds r0, r6, 0
	movs r1, 0x4B
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E98E
_0806E948:
	ldr r2, [r6, 0x70]
	movs r4, 0
	ldr r0, [sp, 0x30]
	cmp r0, 0x20
	bgt _0806E95A
	mov r1, r10
	cmp r1, 0
	bne _0806E95A
	movs r4, 0x1
_0806E95A:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r2, 0
	adds r2, r4, 0
	bl sub_8071ACC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0
	beq _0806E978
	lsls r0, r7, 1
	adds r7, r0, r7
	mov r2, r8
	lsls r2, 1
	mov r8, r2
_0806E978:
	cmp r1, 0
	beq _0806E98E
	adds r0, r6, 0
	bl sub_80428C4
	ldr r0, _0806EAE0
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
_0806E98E:
	adds r0, r6, 0
	movs r1, 0x30
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E9AC
	mov r0, r10
	cmp r0, 0
	bne _0806E9AC
	lsls r0, r7, 1
	adds r7, r0, r7
	mov r1, r8
	lsls r1, 1
	mov r8, r1
_0806E9AC:
	ldr r0, [r6, 0x70]
	ldrb r0, [r0, 0x6]
	movs r4, 0x1
	cmp r0, 0
	beq _0806E9B8
	movs r4, 0
_0806E9B8:
	adds r0, r6, 0
	movs r1, 0x38
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806E9EA
	mov r2, r10
	cmp r2, 0x1
	bne _0806E9EA
	ldr r0, _0806EAE4
	ldr r0, [r0]
	ldr r1, _0806EAE8
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806E9EA
	lsls r0, r7, 4
	subs r7, r0, r7
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 1
	mov r8, r0
_0806E9EA:
	adds r0, r6, 0
	movs r1, 0x3F
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806EA1C
	mov r0, r10
	cmp r0, 0x1
	bne _0806EA1C
	ldr r0, _0806EAE4
	ldr r0, [r0]
	ldr r1, _0806EAEC
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806EA1C
	lsls r0, r7, 4
	subs r7, r0, r7
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 1
	mov r8, r0
_0806EA1C:
	mov r0, r9
	movs r1, 0x6
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806EA38
	mov r0, r10
	cmp r0, 0
	bne _0806EA38
	lsls r7, 2
	mov r1, r8
	lsls r0, r1, 2
	add r8, r0
_0806EA38:
	mov r0, r9
	movs r1, 0x34
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806EA90
	mov r2, r10
	cmp r2, 0
	bne _0806EA90
	mov r0, r9
	ldr r5, [r0, 0x70]
	bl sub_8070A58
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x8
	adds r2, r4, 0
	bl sub_8071ACC
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r4, 0
	beq _0806EA7A
	ldr r2, [sp, 0x4]
	lsls r0, r2, 1
	adds r2, r0, r2
	str r2, [sp, 0x4]
	ldr r0, [sp, 0x8]
	lsls r0, 1
	str r0, [sp, 0x8]
_0806EA7A:
	cmp r1, 0
	beq _0806EA90
	mov r0, r9
	bl sub_8042940
	ldr r0, _0806EAF0
	ldr r2, [r0]
	adds r0, r6, 0
	mov r1, r9
	bl sub_80522F4
_0806EA90:
	ldr r1, [sp]
	ldr r0, [r1]
	muls r0, r7
	str r0, [r1]
	ldr r2, [sp, 0x2C]
	ldr r0, [r2]
	ldr r1, [sp, 0x4]
	muls r0, r1
	str r0, [r2]
	mov r2, r8
	cmp r2, 0x1
	beq _0806EAB6
	ldr r1, [sp]
	ldr r0, [r1]
	mov r1, r8
	bl __divsi3
	ldr r2, [sp]
	str r0, [r2]
_0806EAB6:
	ldr r0, [sp, 0x8]
	cmp r0, 0x1
	beq _0806EACA
	ldr r1, [sp, 0x2C]
	ldr r0, [r1]
	ldr r1, [sp, 0x8]
	bl __divsi3
	ldr r2, [sp, 0x2C]
	str r0, [r2]
_0806EACA:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806EADC: .4byte gUnknown_80FEE04
_0806EAE0: .4byte gUnknown_80FEE2C
_0806EAE4: .4byte gDungeonGlobalData
_0806EAE8: .4byte 0x000037fa
_0806EAEC: .4byte 0x000037f8
_0806EAF0: .4byte gUnknown_80FEE54
	thumb_func_end sub_806E8B0

	thumb_func_start sub_806EAF4
sub_806EAF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8C
	str r0, [sp, 0x70]
	mov r9, r1
	adds r7, r3, 0
	ldr r0, [sp, 0xB8]
	ldr r1, [sp, 0xBC]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x74]
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x78]
	ldr r0, [sp, 0x70]
	ldr r0, [r0, 0x70]
	mov r10, r0
	mov r1, r9
	ldr r1, [r1, 0x70]
	str r1, [sp, 0x7C]
	adds r0, r2, 0
	bl sub_8092354
	movs r2, 0
	str r2, [sp, 0x80]
	lsls r0, 24
	cmp r0, 0
	bne _0806EB3A
	movs r3, 0x1
	str r3, [sp, 0x80]
_0806EB3A:
	bl sub_806F500
	mov r6, r10
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806EB72
	movs r0, 0x9E
	lsls r0, 1
	add r0, r10
	ldr r0, [r0]
	bl sub_8094450
	adds r1, r0, 0
	cmp r1, 0
	bne _0806EB72
	movs r0, 0x1
	ldr r2, [sp, 0xB0]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x2
	str r0, [r2, 0x8]
	add r3, sp, 0x74
	ldrb r3, [r3]
	strb r3, [r2, 0xC]
	strb r1, [r2, 0xD]
	strb r1, [r2, 0xE]
	strb r1, [r2, 0xF]
	b _0806F294
_0806EB72:
	ldr r0, _0806EBA4
	cmp r4, r0
	bne _0806EBA8
	mov r0, r9
	movs r1, 0x35
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806EBA8
	movs r0, 0x1
	ldr r6, [sp, 0xB0]
	str r0, [r6]
	movs r1, 0
	str r1, [r6, 0x4]
	movs r0, 0x2
	str r0, [r6, 0x8]
	add r0, sp, 0x74
	ldrb r0, [r0]
	strb r0, [r6, 0xC]
	strb r1, [r6, 0xD]
	strb r1, [r6, 0xE]
	strb r1, [r6, 0xF]
	b _0806F294
	.align 2, 0
_0806EBA4: .4byte 0x00000163
_0806EBA8:
	add r1, sp, 0x74
	ldrb r2, [r1]
	ldr r1, [sp, 0xB0]
	strb r2, [r1, 0xC]
	ldr r1, _0806EDA4
	ldr r0, [r1]
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	add r3, sp, 0x74
	ldrb r3, [r3]
	strb r3, [r0]
	ldr r2, [r1]
	movs r6, 0x9C
	lsls r6, 1
	adds r0, r2, r6
	ldr r1, [sp, 0x80]
	str r1, [r0]
	lsls r1, 1
	mov r0, r10
	adds r0, 0x1C
	adds r0, r1
	movs r3, 0
	ldrsh r4, [r0, r3]
	mov r8, r1
	ldr r6, [sp, 0x78]
	cmp r6, 0
	beq _0806EBF8
	ldr r0, [sp, 0x74]
	cmp r0, 0x2
	bne _0806EBF8
	mov r1, r10
	movs r3, 0x28
	ldrsh r0, [r1, r3]
	adds r4, r0
	ldrh r1, [r1, 0x28]
	movs r6, 0xA2
	lsls r6, 1
	adds r0, r2, r6
	strh r1, [r0]
_0806EBF8:
	mov r0, r10
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r0, _0806EDA8
	cmp r1, r0
	bne _0806EC06
	adds r4, 0x2
_0806EC06:
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0806EC10
	subs r4, 0x2
_0806EC10:
	ldr r0, _0806EDAC
	cmp r1, r0
	bne _0806EC18
	subs r4, 0x2
_0806EC18:
	cmp r4, 0
	bge _0806EC1E
	movs r4, 0
_0806EC1E:
	cmp r4, 0x14
	ble _0806EC24
	movs r4, 0x14
_0806EC24:
	ldr r6, _0806EDA4
	ldr r0, [r6]
	movs r3, 0x9F
	lsls r3, 1
	adds r0, r3
	strb r4, [r0]
	ldr r1, [r6]
	mov r5, r10
	adds r5, 0x14
	ldr r0, [sp, 0x80]
	adds r2, r5, r0
	ldrb r0, [r2]
	adds r0, r7
	adds r3, 0x2
	adds r1, r3
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, r7
	lsls r0, 8
	ldr r2, _0806EDB0
	lsls r1, r4, 2
	adds r1, r2
	ldr r1, [r1]
	bl sub_8009DA4
	adds r2, r0, 0
	ldr r0, [sp, 0x80]
	lsls r4, r0, 2
	mov r0, r10
	adds r0, 0x2C
	adds r0, r4
	ldr r1, [r0]
	adds r0, r2, 0
	bl sub_8009DA4
	adds r2, r0, 0
	str r5, [sp, 0x88]
	cmp r2, 0
	bge _0806EC74
	adds r0, 0xFF
_0806EC74:
	asrs r0, 8
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x7C]
	adds r0, 0x20
	add r0, r8
	movs r1, 0
	ldrsh r3, [r0, r1]
	ldr r2, [sp, 0x80]
	cmp r2, 0
	bne _0806ECA0
	ldr r0, [sp, 0x7C]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _0806ECA0
	ldr r0, [r6]
	movs r6, 0xBD
	lsls r6, 1
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
	adds r3, 0x1
_0806ECA0:
	ldr r0, [sp, 0x7C]
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r0, _0806EDA8
	cmp r1, r0
	bne _0806ECAE
	subs r3, 0x2
_0806ECAE:
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0806ECB8
	adds r3, 0x2
_0806ECB8:
	ldr r0, _0806EDAC
	cmp r1, r0
	bne _0806ECC0
	subs r3, 0x2
_0806ECC0:
	cmp r3, 0
	bge _0806ECC6
	movs r3, 0
_0806ECC6:
	cmp r3, 0x14
	ble _0806ECCC
	movs r3, 0x14
_0806ECCC:
	ldr r5, _0806EDA4
	ldr r0, [r5]
	ldr r6, _0806EDB4
	adds r0, r6
	strb r3, [r0]
	ldr r2, [r5]
	ldr r0, [sp, 0x7C]
	adds r0, 0x16
	ldr r1, [sp, 0x80]
	adds r0, r1
	ldrb r1, [r0]
	adds r6, 0x3
	adds r2, r6
	strh r1, [r2]
	ldrb r0, [r0]
	lsls r0, 8
	ldr r2, _0806EDB8
	lsls r1, r3, 2
	adds r1, r2
	ldr r1, [r1]
	bl sub_8009DA4
	adds r2, r0, 0
	ldr r0, [sp, 0x7C]
	adds r0, 0x34
	adds r0, r4
	ldr r1, [r0]
	adds r0, r2, 0
	bl sub_8009DA4
	cmp r0, 0
	bge _0806ED0E
	adds r0, 0xFF
_0806ED0E:
	asrs r0, 8
	str r0, [sp, 0xC]
	movs r0, 0x64
	bl DungeonRandomCapped
	str r0, [sp, 0x84]
	ldr r0, [sp, 0x80]
	cmp r0, 0
	bne _0806EDC8
	ldr r0, [sp, 0x70]
	movs r1, 0x13
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806ED4A
	ldr r2, _0806EDBC
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r5]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806ED4A:
	ldr r0, [sp, 0x70]
	movs r1, 0x2B
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806ED74
	ldr r2, _0806EDC0
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r5]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806ED74:
	ldr r3, [sp, 0x78]
	cmp r3, 0
	beq _0806EE4A
	mov r0, r9
	movs r1, 0x1E
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806EE4A
	ldr r2, _0806EDC4
	movs r6, 0
	ldrsh r1, [r2, r6]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r5]
	movs r3, 0xB1
	lsls r3, 1
	adds r1, r0, r3
	ldrb r0, [r2]
	ldrb r6, [r1]
	adds r0, r6
	b _0806EE48
	.align 2, 0
_0806EDA4: .4byte gDungeonGlobalData
_0806EDA8: .4byte 0x000001a1
_0806EDAC: .4byte 0x000001a3
_0806EDB0: .4byte gUnknown_80F504C
_0806EDB4: .4byte 0x0000013f
_0806EDB8: .4byte gUnknown_80F50A0
_0806EDBC: .4byte gUnknown_810AC60
_0806EDC0: .4byte gUnknown_810AC68
_0806EDC4: .4byte gUnknown_810AC64
_0806EDC8:
	ldr r0, [sp, 0x78]
	cmp r0, 0
	beq _0806EDF6
	mov r0, r9
	movs r1, 0x22
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806EDF6
	ldr r2, _0806EEF8
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r5]
	ldr r6, _0806EEFC
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806EDF6:
	ldr r0, [sp, 0x70]
	movs r1, 0x21
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806EE20
	ldr r2, _0806EF00
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r0, _0806EF04
	ldr r0, [r0]
	ldr r6, _0806EF08
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806EE20:
	ldr r0, [sp, 0x70]
	movs r1, 0x2B
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806EE4A
	ldr r2, _0806EF0C
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r0, _0806EF04
	ldr r0, [r0]
	ldr r6, _0806EF08
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
_0806EE48:
	strb r0, [r1]
_0806EE4A:
	ldr r0, _0806EF04
	ldr r2, [r0]
	movs r3, 0xA3
	lsls r3, 1
	adds r1, r2, r3
	add r0, sp, 0x8
	ldrh r0, [r0]
	strh r0, [r1]
	movs r6, 0xA4
	lsls r6, 1
	adds r1, r2, r6
	add r4, sp, 0xC
	ldrh r0, [r4]
	strh r0, [r1]
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bge _0806EE70
	movs r0, 0
	str r0, [sp, 0x8]
_0806EE70:
	ldr r1, _0806EF10
	ldr r0, [sp, 0x8]
	cmp r0, r1
	ble _0806EE7C
	ldr r0, _0806EF14
	str r0, [sp, 0x8]
_0806EE7C:
	movs r3, 0xA8
	lsls r3, 1
	add r3, r10
	ldrh r2, [r3]
	ldr r1, _0806EF18
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r3]
	movs r2, 0xA7
	lsls r2, 1
	add r2, r10
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	str r4, [sp]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x70]
	mov r1, r9
	ldr r2, [sp, 0x74]
	add r3, sp, 0x8
	bl sub_806E8B0
	add r5, sp, 0x10
	ldr r1, [sp, 0x8]
	ldr r0, [sp, 0xC]
	subs r1, r0
	adds r0, r5, 0
	bl sub_800A020
	add r4, sp, 0x18
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_800A020
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_800A3F0
	mov r1, r10
	ldrb r6, [r1, 0x6]
	mov r8, r5
	adds r7, r4, 0
	cmp r6, 0
	bne _0806EF20
	ldrb r1, [r1, 0x9]
	adds r0, r7, 0
	bl sub_800A020
	str r6, [sp, 0x20]
	ldr r0, _0806EF1C
	add r2, sp, 0x20
	str r0, [r2, 0x4]
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	mov r2, r10
	ldrb r0, [r2, 0x9]
	lsls r0, 1
	b _0806EF60
	.align 2, 0
_0806EEF8: .4byte gUnknown_810AC66
_0806EEFC: .4byte 0x00000163
_0806EF00: .4byte gUnknown_810AC62
_0806EF04: .4byte gDungeonGlobalData
_0806EF08: .4byte 0x00000161
_0806EF0C: .4byte gUnknown_810AC68
_0806EF10: .4byte 0x000003e6
_0806EF14: .4byte 0x000003e7
_0806EF18: .4byte 0x0000feff
_0806EF1C: .4byte 0x0000aaaa
_0806EF20:
	ldr r3, [sp, 0x88]
	ldr r6, [sp, 0x80]
	adds r0, r3, r6
	ldrb r0, [r0]
	str r0, [sp, 0x28]
	movs r0, 0x1
	str r0, [sp, 0x2C]
	add r3, sp, 0x28
	add r0, sp, 0x2C
	str r0, [sp]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x70]
	mov r1, r9
	ldr r2, [sp, 0x74]
	bl sub_806E8B0
	ldr r1, [sp, 0x28]
	adds r0, r7, 0
	bl sub_800A020
	add r4, sp, 0x20
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_800A020
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_800A3F0
	ldr r0, [sp, 0x28]
_0806EF60:
	movs r1, 0x3
	bl __divsi3
	adds r6, r0, 0
	add r5, sp, 0x30
	adds r0, r5, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A6D0
	ldr r4, _0806F098
	ldr r0, [r4]
	movs r1, 0xA5
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	mov r8, r2
	strh r6, [r0]
	adds r0, r5, 0
	bl sub_800A048
	ldr r1, [r4]
	movs r3, 0xA6
	lsls r3, 1
	adds r1, r3
	strh r0, [r1]
	ldr r0, [sp, 0x30]
	ldr r1, [sp, 0x34]
	str r0, [sp, 0x38]
	str r1, [sp, 0x3C]
	str r0, [sp, 0x48]
	str r1, [sp, 0x4C]
	add r6, sp, 0x38
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r6, 0
	bl sub_800A34C
	mov r0, r8
	str r0, [sp, 0x40]
	ldr r0, _0806F09C
	add r5, sp, 0x40
	str r0, [r5, 0x4]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_800A34C
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_800A020
	add r4, sp, 0x48
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A34C
	ldr r1, [sp, 0xC]
	adds r0, r5, 0
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A6F0
	adds r0, r5, 0
	movs r1, 0xA
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A6D0
	add r5, sp, 0x50
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_800A6D0
	ldr r4, _0806F0A0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800A2F0
	lsls r0, 24
	mov r8, r5
	cmp r0, 0
	beq _0806F01E
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
_0806F01E:
	ldr r4, _0806F0A4
	mov r0, r8
	adds r1, r4, 0
	bl sub_800A2F0
	lsls r0, 24
	cmp r0, 0
	beq _0806F036
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
_0806F036:
	add r4, sp, 0x58
	ldr r1, [sp, 0xB0]
	str r1, [sp]
	adds r0, r4, 0
	ldr r1, [sp, 0x70]
	mov r2, r9
	ldr r3, [sp, 0x74]
	bl sub_806E100
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r4, 0
	ldr r2, [sp, 0x74]
	cmp r2, 0x2
	bne _0806F0BC
	mov r0, r9
	bl sub_807723C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0806F0BC
	ldr r3, [sp, 0x7C]
	movs r6, 0xA9
	lsls r6, 1
	adds r1, r3, r6
	ldrb r0, [r1]
	cmp r0, 0
	bne _0806F0BC
	ldr r0, [sp, 0x78]
	cmp r0, 0
	beq _0806F118
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0806F0A8
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	cmp r4, 0x1
	bne _0806F0B0
	ldr r0, _0806F0AC
	ldr r2, [r0]
	ldr r0, [sp, 0x70]
	mov r1, r9
	bl sub_80522F4
	b _0806F0BC
	.align 2, 0
_0806F098: .4byte gDungeonGlobalData
_0806F09C: .4byte 0x00000ccc
_0806F0A0: .4byte gUnknown_8106F24
_0806F0A4: .4byte gUnknown_8106F04
_0806F0A8: .4byte gUnknown_202DFE8
_0806F0AC: .4byte gUnknown_80FAE00
_0806F0B0:
	ldr r0, _0806F15C
	ldr r2, [r0]
	ldr r0, [sp, 0x70]
	mov r1, r9
	bl sub_80522F4
_0806F0BC:
	ldr r1, [sp, 0x78]
	cmp r1, 0
	beq _0806F118
	ldr r2, [sp, 0x80]
	cmp r2, 0
	bne _0806F0EE
	ldr r0, [sp, 0x7C]
	adds r0, 0xC4
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _0806F0EE
	mov r0, r9
	bl sub_8041B74
	ldr r2, _0806F160
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	ldr r0, _0806F164
	ldr r0, [r0]
	movs r3, 0xB3
	lsls r3, 1
	adds r0, r3
	strb r4, [r0]
_0806F0EE:
	ldr r6, [sp, 0x80]
	cmp r6, 0x1
	bne _0806F118
	ldr r0, [sp, 0x7C]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806F118
	mov r0, r9
	bl sub_8041B5C
	ldr r2, _0806F160
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	ldr r0, _0806F164
	ldr r0, [r0]
	ldr r1, _0806F168
	adds r0, r1
	strb r6, [r0]
_0806F118:
	mov r0, r9
	movs r1, 0xC
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _0806F1F4
	mov r0, r9
	movs r1, 0x13
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	bne _0806F1F4
	mov r3, r10
	ldrb r0, [r3, 0x6]
	ldr r4, [sp, 0xAC]
	cmp r0, 0
	beq _0806F140
	movs r4, 0
_0806F140:
	mov r0, r10
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806F170
	ldr r4, _0806F16C
	ldr r0, _0806F164
	ldr r0, [r0]
	movs r6, 0xB4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	strb r1, [r0]
	b _0806F1DA
	.align 2, 0
_0806F15C: .4byte gUnknown_80FADD8
_0806F160: .4byte gUnknown_8106F1C
_0806F164: .4byte gDungeonGlobalData
_0806F168: .4byte 0x00000167
_0806F16C: .4byte 0x000003e7
_0806F170:
	ldr r0, [sp, 0x70]
	movs r1, 0xC
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806F194
	ldr r0, _0806F2A4
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r4, r0
	ldr r0, _0806F2A8
	ldr r0, [r0]
	movs r2, 0xB2
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
_0806F194:
	mov r0, r9
	movs r1, 0xD
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806F1B6
	ldr r0, _0806F2A4
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r4, r0
	ldr r0, _0806F2A8
	ldr r0, [r0]
	ldr r6, _0806F2AC
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
_0806F1B6:
	cmp r5, 0
	beq _0806F1DA
	ldr r0, [sp, 0x70]
	movs r1, 0x1
	bl HasIQSkill
	lsls r0, 24
	cmp r0, 0
	beq _0806F1DA
	ldr r0, _0806F2B0
	movs r1, 0
	ldrsh r4, [r0, r1]
	ldr r0, _0806F2A8
	ldr r0, [r0]
	ldr r2, _0806F2B4
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
_0806F1DA:
	movs r0, 0x64
	bl DungeonRandomCapped
	cmp r0, r4
	bge _0806F1F4
	ldr r2, _0806F2B8
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	movs r0, 0x1
	ldr r3, [sp, 0xB0]
	strb r0, [r3, 0xD]
_0806F1F4:
	mov r0, r8
	bl sub_800A048
	ldr r5, _0806F2A8
	ldr r1, [r5]
	movs r6, 0xAA
	lsls r6, 1
	adds r1, r6
	str r0, [r1]
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	ldr r0, [r5]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	ldr r2, [sp, 0xB4]
	str r2, [r0]
	add r4, sp, 0x60
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_800A088
	mov r0, r8
	mov r1, r8
	adds r2, r4, 0
	bl sub_800A34C
	mov r0, r8
	bl sub_800A048
	ldr r1, [r5]
	movs r3, 0xA8
	lsls r3, 1
	adds r1, r3
	str r0, [r1]
	movs r0, 0x80
	lsls r0, 7
	bl DungeonRandomCapped
	movs r6, 0
	str r6, [sp, 0x58]
	movs r1, 0xE0
	lsls r1, 8
	adds r0, r1
	str r0, [r7, 0x4]
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	add r4, sp, 0x68
	adds r0, r4, 0
	movs r1, 0x64
	bl sub_800A020
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_800A34C
	adds r0, r7, 0
	bl sub_800A048
	ldr r1, [r5]
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2
	str r0, [r1]
	mov r0, r8
	bl sub_800A048
	ldr r3, [sp, 0xB0]
	str r0, [r3]
	str r6, [r3, 0x4]
	cmp r0, 0
	bne _0806F294
	strb r0, [r3, 0xD]
_0806F294:
	add sp, 0x8C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F2A4: .4byte gUnknown_80F4DAE
_0806F2A8: .4byte gDungeonGlobalData
_0806F2AC: .4byte 0x00000165
_0806F2B0: .4byte gUnknown_80F4DB0
_0806F2B4: .4byte 0x00000169
_0806F2B8: .4byte gUnknown_8106F14
	thumb_func_end sub_806EAF4

	thumb_func_start sub_806F2BC
sub_806F2BC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r5, r0, 0
	mov r12, r1
	ldr r7, [sp, 0x2C]
	lsls r2, 24
	lsrs r4, r2, 24
	adds r6, r3, 0
	cmp r6, 0
	bgt _0806F2D6
	movs r6, 0x1
_0806F2D6:
	ldr r0, _0806F320
	cmp r6, r0
	ble _0806F2DE
	adds r6, r0, 0
_0806F2DE:
	movs r0, 0
	mov r8, r0
	strb r4, [r7, 0xC]
	str r7, [sp]
	add r0, sp, 0x4
	adds r1, r5, 0
	mov r2, r12
	adds r3, r4, 0
	bl sub_806E100
	add r4, sp, 0xC
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_800A34C
	adds r0, r4, 0
	bl sub_800A048
	str r0, [r7]
	mov r0, r8
	str r0, [r7, 0x4]
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F320: .4byte 0x000003e7
	thumb_func_end sub_806F2BC

	thumb_func_start sub_806F324
sub_806F324:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x94
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, r3, 16
	asrs r4, 16
	add r0, sp, 0x10
	bl sub_80457DC
	add r2, sp, 0x84
	str r5, [sp, 0x84]
	movs r0, 0x2
	str r0, [r2, 0x8]
	movs r0, 0
	strb r0, [r2, 0xC]
	str r6, [r2, 0x4]
	strb r0, [r2, 0xD]
	strb r0, [r2, 0xE]
	strb r0, [r2, 0xF]
	str r0, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	mov r1, r8
	movs r3, 0
	bl sub_806D010
	add sp, 0x94
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806F324

	thumb_func_start sub_806F370
sub_806F370:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r10, r0
	adds r7, r1, 0
	mov r9, r3
	ldr r0, [sp, 0x50]
	ldr r1, [sp, 0x54]
	ldr r3, [sp, 0x58]
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	adds r5, r2, 0
	movs r0, 0x2
	str r0, [sp, 0x18]
	str r3, [sp, 0x14]
	add r0, sp, 0x10
	movs r1, 0
	strb r4, [r0, 0xC]
	strb r1, [r0, 0xD]
	strb r1, [r0, 0xE]
	cmp r4, 0
	beq _0806F3FC
	ldr r1, [r7, 0x70]
	movs r2, 0
	lsls r0, r4, 3
	mov r3, sp
	adds r3, 0x20
	str r3, [sp, 0x28]
	ldr r6, _0806F408
	mov r12, r6
	adds r1, 0x5C
	adds r0, r4
	lsls r3, r0, 2
	ldr r4, [sp, 0x28]
_0806F3C0:
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r3
	add r0, r12
	movs r6, 0
	ldrsh r0, [r0, r6]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806F3C0
	adds r0, r7, 0
	movs r1, 0x35
	bl sub_8071824
	lsls r0, 24
	cmp r0, 0
	beq _0806F3FC
	ldr r2, _0806F40C
	ldr r1, [sp, 0x28]
	ldr r0, [r1, 0x4]
	lsls r0, 2
	ldr r1, [sp, 0x20]
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	beq _0806F3FC
	movs r5, 0
_0806F3FC:
	str r5, [sp, 0x10]
	cmp r5, 0
	bne _0806F410
	add r1, sp, 0x10
	movs r0, 0x1
	b _0806F414
	.align 2, 0
_0806F408: .4byte gUnknown_80F522C
_0806F40C: .4byte gUnknown_80F54B4
_0806F410:
	add r1, sp, 0x10
	movs r0, 0
_0806F414:
	strb r0, [r1, 0xF]
	mov r3, r9
	str r3, [sp]
	mov r6, r8
	str r6, [sp, 0x4]
	ldr r0, [sp, 0x5C]
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x60]
	str r0, [sp, 0xC]
	mov r0, r10
	adds r1, r7, 0
	add r2, sp, 0x10
	movs r3, 0
	bl sub_806D010
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0806F440
	add r0, sp, 0x10
	ldrb r0, [r0, 0xF]
	ldr r1, [sp, 0x4C]
	strb r0, [r1]
_0806F440:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806F370

	thumb_func_start sub_806F450
sub_806F450:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, [r1, 0x70]
	adds r6, r4, 0
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _0806F47A
	adds r0, r5, 0
	bl sub_80450F8
	cmp r0, 0x1
	bne _0806F47A
	ldr r0, [r5, 0x70]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0806F476
	movs r0, 0x2
	strb r0, [r4, 0x8]
	b _0806F47A
_0806F476:
	movs r0, 0x3
	strb r0, [r6, 0x8]
_0806F47A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_806F450

	thumb_func_start sub_806F480
sub_806F480:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	ldr r2, [r0, 0x70]
	adds r3, r2, 0
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0806F49E
	cmp r1, 0
	beq _0806F49A
	movs r0, 0x2
	strb r0, [r2, 0x8]
	b _0806F49E
_0806F49A:
	movs r0, 0x3
	strb r0, [r3, 0x8]
_0806F49E:
	pop {r0}
	bx r0
	thumb_func_end sub_806F480

	thumb_func_start sub_806F4A4
sub_806F4A4:
	push {r4-r6,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r5, [r0, 0x70]
	movs r1, 0xE
	bl sub_8071858
	lsls r0, 24
	cmp r0, 0
	beq _0806F4CE
	cmp r4, 0x1
	beq _0806F4C0
	cmp r4, 0x7
	bne _0806F4CE
_0806F4C0:
	adds r0, r5, 0
	adds r0, 0xF5
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806F4CE
_0806F4CA:
	movs r0, 0
	b _0806F4F6
_0806F4CE:
	movs r2, 0
	lsls r0, r4, 3
	ldr r6, _0806F4FC
	adds r3, r5, 0
	adds r3, 0x5C
	adds r0, r4
	lsls r1, r0, 2
_0806F4DC:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	adds r0, r6
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	beq _0806F4CA
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806F4DC
	movs r0, 0x1
_0806F4F6:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0806F4FC: .4byte gUnknown_80F522C
	thumb_func_end sub_806F4A4

	thumb_func_start sub_806F500
sub_806F500:
	ldr r0, _0806F5F4
	ldr r0, [r0]
	mov r12, r0
	movs r0, 0x9A
	lsls r0, 1
	add r0, r12
	movs r1, 0
	strb r1, [r0]
	str r1, [r0, 0x4]
	strb r1, [r0, 0x8]
	strb r1, [r0, 0x9]
	movs r2, 0xA
	strb r2, [r0, 0xA]
	strb r2, [r0, 0xB]
	movs r2, 0
	movs r3, 0x1
	strh r3, [r0, 0xC]
	strh r3, [r0, 0xE]
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x14]
	strh r1, [r0, 0x12]
	strh r1, [r0, 0x16]
	strh r1, [r0, 0x18]
	str r1, [r0, 0x1C]
	str r1, [r0, 0x24]
	str r1, [r0, 0x28]
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F5F8
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB1
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F5FC
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB2
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F600
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB3
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F604
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB4
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F608
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB5
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB6
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F60C
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F610
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB7
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F614
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB8
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F618
	add r0, r12
	strb r2, [r0]
	movs r0, 0xB9
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F61C
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBA
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F620
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBB
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F624
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBC
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	ldr r0, _0806F628
	add r0, r12
	strb r2, [r0]
	movs r0, 0xBD
	lsls r0, 1
	add r0, r12
	strb r2, [r0]
	bx lr
	.align 2, 0
_0806F5F4: .4byte gDungeonGlobalData
_0806F5F8: .4byte 0x00000161
_0806F5FC: .4byte 0x00000163
_0806F600: .4byte 0x00000165
_0806F604: .4byte 0x00000167
_0806F608: .4byte 0x00000169
_0806F60C: .4byte 0x0000016b
_0806F610: .4byte 0x0000016d
_0806F614: .4byte 0x0000016f
_0806F618: .4byte 0x00000171
_0806F61C: .4byte 0x00000173
_0806F620: .4byte 0x00000175
_0806F624: .4byte 0x00000177
_0806F628: .4byte 0x00000179
	thumb_func_end sub_806F500

	thumb_func_start sub_806F62C
sub_806F62C:
	ldr r1, _0806F638
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0806F638: .4byte gUnknown_8106F7C
	thumb_func_end sub_806F62C

	thumb_func_start sub_806F63C
sub_806F63C:
	push {lr}
	ldr r1, _0806F658
	ldr r1, [r1]
	ldr r2, _0806F65C
	adds r1, r2
	ldr r1, [r1, 0x10]
	cmp r1, r0
	bne _0806F652
	adds r0, r1, 0
	bl sub_803F508
_0806F652:
	pop {r0}
	bx r0
	.align 2, 0
_0806F658: .4byte gDungeonGlobalData
_0806F65C: .4byte 0x000181e8
	thumb_func_end sub_806F63C

	thumb_func_start sub_806F660
sub_806F660:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	mov r8, r1
	ldr r0, [r6, 0x70]
	mov r10, r0
	ldr r4, [r1, 0x70]
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	movs r2, 0x4
	ldrsh r0, [r4, r2]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, _0806F6C0
	ldr r3, [r0]
	ldr r1, _0806F6C4
	adds r0, r3, r1
	ldrh r2, [r0]
	subs r0, r2, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _0806F702
	lsls r0, r2, 16
	asrs r1, r0, 16
	cmp r1, 0x9
	beq _0806F702
	cmp r1, 0xF
	beq _0806F702
	adds r0, r2, 0
	subs r0, 0x2C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bhi _0806F6CC
	ldr r2, _0806F6C8
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806F702
	b _0806F8FC
	.align 2, 0
_0806F6C0: .4byte gDungeonGlobalData
_0806F6C4: .4byte 0x00003a14
_0806F6C8: .4byte 0x0000065c
_0806F6CC:
	cmp r1, 0x31
	bne _0806F6F0
	ldr r1, _0806F6EC
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0806F6DC
	b _0806F8FC
_0806F6DC:
	movs r0, 0xCF
	lsls r0, 1
	bl sub_8097900
	lsls r0, 24
	cmp r0, 0
	bne _0806F702
	b _0806F8FC
	.align 2, 0
_0806F6EC: .4byte 0x00000659
_0806F6F0:
	ldr r2, _0806F834
	adds r0, r3, r2
	ldrb r0, [r0]
	bl GetRecruitable
	lsls r0, 24
	cmp r0, 0
	bne _0806F702
	b _0806F8FC
_0806F702:
	ldr r0, _0806F838
	ldr r0, [r0]
	ldr r3, _0806F83C
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806F712
	b _0806F8FC
_0806F712:
	ldrh r1, [r4, 0x2]
	adds r0, r1, 0
	subs r0, 0x90
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	bls _0806F766
	lsls r0, r1, 16
	asrs r1, r0, 16
	ldr r0, _0806F840
	cmp r1, r0
	beq _0806F766
	subs r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x2
	cmp r1, r0
	beq _0806F766
	adds r0, 0x8A
	cmp r1, r0
	beq _0806F766
	adds r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x4
	cmp r1, r0
	beq _0806F766
	subs r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x2
	cmp r1, r0
	beq _0806F766
	subs r0, 0x9
	cmp r1, r0
	beq _0806F766
	adds r0, 0x1
	cmp r1, r0
	beq _0806F766
	adds r0, 0x1
	cmp r1, r0
	bne _0806F776
_0806F766:
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl HasRecruitedMon
	lsls r0, 24
	cmp r0, 0
	beq _0806F776
	b _0806F8FC
_0806F776:
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	bl sub_806F9BC
	lsls r0, 24
	cmp r0, 0
	bne _0806F786
	b _0806F8FC
_0806F786:
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	mov r2, r8
	movs r3, 0x4
	ldrsh r0, [r2, r3]
	subs r1, r0
	cmp r1, 0
	bge _0806F798
	negs r1, r1
_0806F798:
	cmp r1, 0x1
	ble _0806F79E
	b _0806F8FC
_0806F79E:
	movs r0, 0x6
	ldrsh r1, [r6, r0]
	mov r2, r8
	movs r3, 0x6
	ldrsh r0, [r2, r3]
	subs r1, r0
	cmp r1, 0
	bge _0806F7B0
	negs r1, r1
_0806F7B0:
	cmp r1, 0x1
	ble _0806F7B6
	b _0806F8FC
_0806F7B6:
	adds r0, r4, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	bne _0806F7C2
	b _0806F8FC
_0806F7C2:
	adds r0, r4, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806F7CE
	b _0806F8FC
_0806F7CE:
	mov r0, r8
	adds r1, r6, 0
	bl CanSee
	lsls r0, 24
	cmp r0, 0
	bne _0806F7DE
	b _0806F8FC
_0806F7DE:
	bl sub_806F910
	movs r0, 0xFA
	lsls r0, 2
	bl DungeonRandomCapped
	adds r7, r0, 0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl GetBaseRecruit
	lsls r0, 16
	asrs r4, r0, 16
	ldr r0, _0806F844
	cmp r4, r0
	bne _0806F800
	b _0806F8FC
_0806F800:
	adds r0, r6, 0
	movs r1, 0x2E
	bl sub_8046CB0
	lsls r0, 24
	cmp r0, 0
	beq _0806F816
	ldr r0, _0806F848
	movs r2, 0
	ldrsh r0, [r0, r2]
	adds r4, r0
_0806F816:
	ldr r0, _0806F84C
	mov r3, r10
	ldrb r1, [r3, 0x9]
	lsls r1, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	adds r4, r0
	cmp r7, r4
	bge _0806F8FC
	movs r4, 0
	movs r0, 0x6
	subs r3, r0, r5
	ldr r7, _0806F850
	b _0806F856
	.align 2, 0
_0806F834: .4byte 0x00000644
_0806F838: .4byte gDungeonGlobalData
_0806F83C: .4byte 0x0000065d
_0806F840: .4byte 0x0000010d
_0806F844: .4byte 0xfffffc19
_0806F848: .4byte gUnknown_80F5008
_0806F84C: .4byte gUnknown_80F5700
_0806F850: .4byte gUnknown_202EE70
_0806F854:
	adds r4, 0x1
_0806F856:
	cmp r4, r3
	bgt _0806F878
	movs r2, 0
	cmp r2, r5
	bge _0806F872
	adds r1, r4, r7
	b _0806F86C
_0806F864:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r5
	bge _0806F872
_0806F86C:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0806F864
_0806F872:
	cmp r2, r5
	bne _0806F854
	mov r9, r4
_0806F878:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0806F8F4
	movs r4, 0
	ldr r3, _0806F8BC
	ldr r0, [r3]
	ldr r2, _0806F8C0
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806F8B4
	adds r7, r3, 0
	adds r5, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806F89C:
	adds r2, 0x64
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0806F8B4
	ldr r0, [r7]
	adds r0, r2, r0
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806F89C
_0806F8B4:
	cmp r4, 0x4
	beq _0806F8F4
	movs r4, 0
	b _0806F8C6
	.align 2, 0
_0806F8BC: .4byte gRecruitedPokemonRef
_0806F8C0: .4byte 0x00008df8
_0806F8C4:
	adds r4, 0x1
_0806F8C6:
	cmp r4, 0x3
	bgt _0806F8E2
	ldr r0, _0806F8EC
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r3, _0806F8F0
	adds r0, r3
	adds r0, r1
	ldr r0, [r0]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806F8C4
_0806F8E2:
	cmp r4, 0x4
	beq _0806F8F4
	movs r0, 0x1
	b _0806F8FE
	.align 2, 0
_0806F8EC: .4byte gDungeonGlobalData
_0806F8F0: .4byte 0x0001357c
_0806F8F4:
	adds r0, r6, 0
	mov r1, r8
	bl nullsub_96
_0806F8FC:
	movs r0, 0
_0806F8FE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806F660

	thumb_func_start nullsub_96
nullsub_96:
	bx lr
	thumb_func_end nullsub_96

	thumb_func_start sub_806F910
sub_806F910:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
	movs r6, 0
	movs r7, 0x40
_0806F91C:
	ldr r0, _0806F9AC
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _0806F9B0
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	adds r1, r6, 0x1
	mov r8, r1
	cmp r0, 0
	beq _0806F98A
	ldr r0, [r4, 0x70]
	movs r2, 0x4
	ldrsh r0, [r0, r2]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r4, 0
	adds r0, 0x68
	strh r7, [r0]
	ldr r0, [r4, 0x70]
	ldr r2, _0806F9B4
	adds r0, r2
	strb r6, [r0]
	ldr r0, [r4, 0x70]
	adds r2, 0x1
	adds r0, r2
	strb r1, [r0]
	cmp r1, 0
	beq _0806F978
	ldr r3, _0806F9B8
	movs r2, 0x1
_0806F966:
	cmp r5, 0x5
	bgt _0806F972
	adds r0, r5, r3
	strb r2, [r0]
	adds r7, 0x10
	adds r5, 0x1
_0806F972:
	subs r1, 0x1
	cmp r1, 0
	bne _0806F966
_0806F978:
	adds r0, r4, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806CCB4
_0806F98A:
	mov r6, r8
	cmp r6, 0x3
	ble _0806F91C
	cmp r5, 0x5
	bgt _0806F9A2
	ldr r2, _0806F9B8
	movs r1, 0
_0806F998:
	adds r0, r5, r2
	strb r1, [r0]
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806F998
_0806F9A2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F9AC: .4byte gDungeonGlobalData
_0806F9B0: .4byte 0x0001357c
_0806F9B4: .4byte 0x00000167
_0806F9B8: .4byte gUnknown_202EE70
	thumb_func_end sub_806F910

	thumb_func_start sub_806F9BC
sub_806F9BC:
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 16
	asrs r4, r0, 16
	ldr r5, _0806FA40
	ldr r0, [r5]
	movs r1, 0xCB
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806FA3C
	adds r0, r4, 0
	bl sub_808529C
	lsls r0, 24
	cmp r0, 0
	beq _0806FA3C
	cmp r4, 0x97
	bne _0806F9F2
	ldr r0, [r5]
	movs r1, 0xCF
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0806FA3C
_0806F9F2:
	movs r0, 0xCC
	lsls r0, 1
	cmp r4, r0
	beq _0806FA3C
	ldr r0, _0806FA44
	cmp r4, r0
	beq _0806FA3C
	ldr r0, _0806FA48
	cmp r4, r0
	beq _0806FA3C
	movs r0, 0xD1
	lsls r0, 1
	cmp r4, r0
	beq _0806FA3C
	ldr r0, _0806FA4C
	cmp r4, r0
	beq _0806FA3C
	adds r0, r4, 0
	bl GetUnk12
	lsls r0, 24
	cmp r0, 0
	bne _0806FA50
	adds r0, r4, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	mov r0, sp
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	bne _0806FA50
_0806FA3C:
	movs r0, 0
	b _0806FA52
	.align 2, 0
_0806FA40: .4byte gDungeonGlobalData
_0806FA44: .4byte 0x00000199
_0806FA48: .4byte 0x000001a1
_0806FA4C: .4byte 0x000001a3
_0806FA50:
	movs r0, 0x1
_0806FA52:
	add sp, 0xC
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806F9BC

	thumb_func_start sub_806FA5C
sub_806FA5C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	adds r0, r5, 0x4
	mov r1, r8
	adds r1, 0x4
	bl sub_80983D8
	adds r4, r0, 0
	movs r0, 0
	mov r10, r0
	movs r1, 0
	ldrsh r0, [r6, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	adds r0, r5, 0
	adds r0, 0x22
	mov r2, r10
	strb r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_807A0CC
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806CE68
	ldr r0, _0806FAD4
	movs r3, 0
	ldrsh r1, [r6, r3]
	bl CopyCyanSpeciesNametoBuffer
	ldr r0, _0806FAD8
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0
	bne _0806FAE4
	movs r4, 0
	ldrsh r1, [r6, r4]
	ldr r0, _0806FADC
	cmp r1, r0
	beq _0806FB28
	ldr r0, _0806FAE0
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	b _0806FB28
	.align 2, 0
_0806FAD4: .4byte gAvailablePokemonNames
_0806FAD8: .4byte gUnknown_80F9FE8
_0806FADC: .4byte 0x0000019d
_0806FAE0: .4byte gUnknown_80FA004
_0806FAE4:
	movs r7, 0
	ldr r3, _0806FB2C
	ldr r0, [r3]
	ldr r2, _0806FB30
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806FB1A
	mov r12, r3
	adds r4, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806FB00:
	adds r2, 0x64
	adds r7, 0x1
	cmp r7, 0x3
	bgt _0806FB1A
	mov r1, r12
	ldr r0, [r1]
	adds r0, r2, r0
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806FB00
_0806FB1A:
	cmp r7, 0x4
	bne _0806FB38
	ldr r0, _0806FB34
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
_0806FB28:
	movs r0, 0
	b _0806FCF0
	.align 2, 0
_0806FB2C: .4byte gRecruitedPokemonRef
_0806FB30: .4byte 0x00008df8
_0806FB34: .4byte gUnknown_80FA030
_0806FB38:
	mov r0, r9
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _0806FB4E
	mov r0, r9
	bl UnlockFriendArea
	movs r2, 0x1
	mov r10, r2
_0806FB4E:
	movs r1, 0xFA
	lsls r1, 1
	adds r0, r5, 0
	mov r2, r8
	bl sub_8068FE0
	ldr r1, _0806FC40
	movs r0, 0x64
	muls r0, r7
	ldr r3, _0806FC44
	adds r0, r3
	ldr r1, [r1]
	adds r5, r1, r0
	movs r4, 0
	movs r0, 0x3
	strh r0, [r5]
	strb r4, [r5, 0x2]
	ldrh r0, [r6, 0xE]
	strb r0, [r5, 0x3]
	movs r0, 0x1
	strh r0, [r5, 0x8]
	adds r0, r5, 0
	adds r0, 0x4C
	movs r1, 0
	bl sub_808EC94
	ldr r0, [r6, 0x44]
	str r0, [r5, 0x54]
	adds r0, r5, 0
	adds r0, 0x50
	strb r4, [r0]
	ldr r0, _0806FC48
	strh r0, [r5, 0xA]
	strh r7, [r5, 0xC]
	ldrh r0, [r6]
	strh r0, [r5, 0xE]
	ldr r0, _0806FC4C
	ldr r0, [r0]
	ldr r4, _0806FC50
	adds r0, r4
	ldr r0, [r0]
	str r0, [r5, 0x4]
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x10]
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x12]
	ldr r0, [r6, 0x14]
	str r0, [r5, 0x44]
	ldr r0, [r6, 0x18]
	str r0, [r5, 0x48]
	movs r2, 0
	adds r7, r6, 0
	adds r7, 0x20
	adds r4, r6, 0
	adds r4, 0xA
	adds r3, r6, 0
	adds r3, 0xC
	adds r1, r5, 0
	adds r1, 0x14
_0806FBC4:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806FBC4
	ldr r0, [r6, 0x10]
	str r0, [r5, 0x18]
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r7, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r6, 0x1C]
	str r0, [r5, 0x40]
	adds r4, r5, 0
	adds r4, 0x58
	movs r1, 0
	ldrsh r0, [r6, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
	bl sub_8097848
	movs r2, 0
	ldrsh r0, [r6, r2]
	movs r3, 0x4
	ldrsh r1, [r6, r3]
	movs r3, 0x6
	ldrsh r2, [r6, r3]
	add r3, sp, 0xC
	str r3, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	movs r3, 0x1
	str r3, [sp, 0x8]
	adds r3, r5, 0
	bl sub_806B8CC
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0
	bne _0806FC58
	ldr r0, _0806FC54
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	strh r7, [r5]
	b _0806FCEE
	.align 2, 0
_0806FC40: .4byte gRecruitedPokemonRef
_0806FC44: .4byte 0x00008df8
_0806FC48: .4byte 0x0000ffff
_0806FC4C: .4byte gDungeonGlobalData
_0806FC50: .4byte 0x00000644
_0806FC54: .4byte gUnknown_80FA058
_0806FC58:
	bl sub_8083D88
	movs r0, 0xA0
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0806FC78
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _0806FC94
	b _0806FC88
	.align 2, 0
_0806FC78: .4byte gUnknown_80FA090
_0806FC7C:
	ldr r0, _0806FD00
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FC88:
	adds r0, r4, 0
	bl sub_805FBE8
	lsls r0, 24
	cmp r0, 0
	beq _0806FC7C
_0806FC94:
	ldr r4, _0806FD04
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	bl sub_808D9DC
	ldr r0, _0806FD08
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	mov r0, r10
	cmp r0, 0
	beq _0806FCD8
	bl sub_8085480
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0806FD0C
	mov r1, r9
	bl sub_8092558
	movs r0, 0xCE
	bl PlaySound
	ldr r0, _0806FD10
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FCD8:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x97
	bne _0806FCEE
	ldr r2, _0806FD14
	ldr r1, [r2]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1, 0x11]
_0806FCEE:
	movs r0, 0x1
_0806FCF0:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806FD00: .4byte gUnknown_80FA0C8
_0806FD04: .4byte gAvailablePokemonNames
_0806FD08: .4byte gUnknown_80FA0F0
_0806FD0C: .4byte gUnknown_202E628
_0806FD10: .4byte gUnknown_80FA120
_0806FD14: .4byte gDungeonGlobalData
	thumb_func_end sub_806FA5C

	thumb_func_start sub_806FD18
sub_806FD18:
	push {r4-r7,lr}
	ldr r4, [r0, 0x70]
	movs r6, 0x1
	negs r6, r6
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl GetPokemonSize
	lsls r0, 24
	lsrs r5, r0, 24
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	bl sub_806F9BC
	lsls r0, 24
	cmp r0, 0
	beq _0806FDEC
	bl sub_806F910
	movs r4, 0
	movs r0, 0x6
	subs r3, r0, r5
	ldr r7, _0806FD48
	b _0806FD4E
	.align 2, 0
_0806FD48: .4byte gUnknown_202EE70
_0806FD4C:
	adds r4, 0x1
_0806FD4E:
	cmp r4, r3
	bgt _0806FD70
	movs r2, 0
	cmp r2, r5
	bge _0806FD6A
	adds r1, r4, r7
	b _0806FD64
_0806FD5C:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r5
	bge _0806FD6A
_0806FD64:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0806FD5C
_0806FD6A:
	cmp r2, r5
	bne _0806FD4C
	adds r6, r4, 0
_0806FD70:
	movs r0, 0x1
	negs r0, r0
	cmp r6, r0
	beq _0806FDEC
	movs r4, 0
	ldr r3, _0806FDB4
	ldr r0, [r3]
	ldr r2, _0806FDB8
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806FDAC
	adds r6, r3, 0
	adds r5, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806FD94:
	adds r2, 0x64
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0806FDAC
	ldr r0, [r6]
	adds r0, r2, r0
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806FD94
_0806FDAC:
	cmp r4, 0x4
	beq _0806FDEC
	movs r4, 0
	b _0806FDBE
	.align 2, 0
_0806FDB4: .4byte gRecruitedPokemonRef
_0806FDB8: .4byte 0x00008df8
_0806FDBC:
	adds r4, 0x1
_0806FDBE:
	cmp r4, 0x3
	bgt _0806FDDA
	ldr r0, _0806FDE4
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _0806FDE8
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0806FDBC
_0806FDDA:
	cmp r4, 0x4
	beq _0806FDEC
	movs r0, 0x1
	b _0806FDEE
	.align 2, 0
_0806FDE4: .4byte gDungeonGlobalData
_0806FDE8: .4byte 0x0001357c
_0806FDEC:
	movs r0, 0
_0806FDEE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_806FD18

	thumb_func_start sub_806FDF4
sub_806FDF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x60
	str r0, [sp, 0x58]
	mov r10, r1
	str r2, [sp, 0x5C]
	movs r0, 0
	mov r9, r0
	str r0, [r2]
	add r0, sp, 0xC
	bl sub_8069D4C
	movs r6, 0
	ldr r3, _0806FE50
	ldr r0, [r3]
	ldr r2, _0806FE54
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806FE46
	adds r5, r3, 0
	adds r4, r2, 0
	movs r2, 0
	movs r3, 0x1
_0806FE2E:
	adds r2, 0x64
	adds r6, 0x1
	cmp r6, 0x3
	bgt _0806FE46
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0806FE2E
_0806FE46:
	cmp r6, 0x4
	bne _0806FE58
	movs r0, 0
	b _0806FFF8
	.align 2, 0
_0806FE50: .4byte gRecruitedPokemonRef
_0806FE54: .4byte 0x00008df8
_0806FE58:
	add r0, sp, 0xC
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, _0806FF74
	movs r0, 0x64
	muls r0, r6
	ldr r2, _0806FF78
	adds r0, r2
	ldr r1, [r1]
	adds r5, r1, r0
	movs r4, 0
	movs r0, 0x3
	strh r0, [r5]
	strb r4, [r5, 0x2]
	add r0, sp, 0xC
	ldrh r0, [r0, 0xE]
	strb r0, [r5, 0x3]
	movs r0, 0x1
	strh r0, [r5, 0x8]
	adds r0, r5, 0
	adds r0, 0x4C
	movs r1, 0
	bl sub_808EC94
	ldr r0, [sp, 0x50]
	str r0, [r5, 0x54]
	adds r0, r5, 0
	adds r0, 0x50
	strb r4, [r0]
	ldr r0, _0806FF7C
	strh r0, [r5, 0xA]
	strh r6, [r5, 0xC]
	add r0, sp, 0xC
	ldrh r0, [r0]
	strh r0, [r5, 0xE]
	ldr r0, _0806FF80
	ldr r0, [r0]
	ldr r3, _0806FF84
	adds r0, r3
	ldr r0, [r0]
	str r0, [r5, 0x4]
	add r0, sp, 0xC
	ldrh r0, [r0, 0x8]
	strh r0, [r5, 0x10]
	add r0, sp, 0xC
	ldrh r0, [r0, 0x8]
	strh r0, [r5, 0x12]
	ldr r0, [sp, 0x20]
	str r0, [r5, 0x44]
	ldr r0, [sp, 0x24]
	str r0, [r5, 0x48]
	movs r2, 0
	add r6, sp, 0x2C
	add r4, sp, 0x54
	mov r8, r4
	mov r4, sp
	adds r4, 0x16
	add r3, sp, 0x18
	adds r1, r5, 0
	adds r1, 0x14
_0806FED8:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806FED8
	ldr r0, [sp, 0x1C]
	str r0, [r5, 0x18]
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r6, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [sp, 0x28]
	str r0, [r5, 0x40]
	adds r4, r5, 0
	adds r4, 0x58
	add r0, sp, 0xC
	movs r1, 0
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
	adds r0, r7, 0
	bl GetFriendAreaStatus
	lsls r0, 24
	cmp r0, 0
	bne _0806FF34
	adds r0, r7, 0
	bl UnlockFriendArea
	movs r2, 0x1
	mov r9, r2
_0806FF34:
	bl sub_8097848
	movs r1, 0xFA
	lsls r1, 1
	mov r0, r10
	ldr r2, [sp, 0x58]
	bl sub_8068FE0
	add r0, sp, 0xC
	movs r3, 0
	ldrsh r0, [r0, r3]
	add r1, sp, 0xC
	movs r2, 0x4
	ldrsh r1, [r1, r2]
	add r2, sp, 0xC
	movs r3, 0x6
	ldrsh r2, [r2, r3]
	mov r3, r8
	str r3, [sp]
	movs r3, 0
	str r3, [sp, 0x4]
	str r3, [sp, 0x8]
	adds r3, r5, 0
	bl sub_806B8CC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0806FF88
	strh r0, [r5]
	b _0806FFF6
	.align 2, 0
_0806FF74: .4byte gRecruitedPokemonRef
_0806FF78: .4byte 0x00008df8
_0806FF7C: .4byte 0x0000ffff
_0806FF80: .4byte gDungeonGlobalData
_0806FF84: .4byte 0x00000644
_0806FF88:
	ldr r0, _0806FF9C
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl sub_8052B8C
	cmp r0, 0x1
	bne _0806FFB8
	b _0806FFAC
	.align 2, 0
_0806FF9C: .4byte gUnknown_80FA090
_0806FFA0:
	ldr r0, _08070008
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FFAC:
	adds r0, r4, 0
	bl sub_805FBE8
	lsls r0, 24
	cmp r0, 0
	beq _0806FFA0
_0806FFB8:
	mov r4, r9
	cmp r4, 0
	beq _0806FFE6
	bl sub_8085480
	adds r1, r0, 0
	ldr r0, _0807000C
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08070010
	adds r1, r7, 0
	bl sub_8092558
	movs r0, 0xCE
	bl PlaySound
	ldr r0, _08070014
	ldr r1, [r0]
	movs r0, 0
	movs r2, 0x1
	bl PrintFieldMessage
_0806FFE6:
	ldr r0, _08070018
	adds r1, r5, 0
	movs r2, 0
	bl sub_808D9DC
	ldr r0, [sp, 0x54]
	ldr r1, [sp, 0x5C]
	str r0, [r1]
_0806FFF6:
	movs r0, 0x1
_0806FFF8:
	add sp, 0x60
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08070008: .4byte gUnknown_80FA0C8
_0807000C: .4byte gAvailablePokemonNames
_08070010: .4byte gUnknown_202E628
_08070014: .4byte gUnknown_80FA120
_08070018: .4byte gUnknown_202E088
	thumb_func_end sub_806FDF4


        .align 2,0
