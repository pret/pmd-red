	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_8011940
sub_8011940:
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl sub_800C068
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, _08011960
	cmp r4, r0
	bne _08011964
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _0801196C
	.align 2, 0
_08011960: .4byte 0x000003e7
_08011964:
	movs r0, 0
	cmp r1, r4
	bne _0801196C
	movs r0, 0x1
_0801196C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8011940

	thumb_func_start sub_8011974
sub_8011974:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8011974

	thumb_func_start sub_8011988
sub_8011988:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	pop {r0}
	bx r0
	thumb_func_end sub_8011988

	thumb_func_start sub_801199C
sub_801199C:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C298
	pop {r0}
	bx r0
	thumb_func_end sub_801199C

	thumb_func_start sub_80119AC
sub_80119AC:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	bl sub_800C3F8
	pop {r0}
	bx r0
	thumb_func_end sub_80119AC

	thumb_func_start sub_80119C0
sub_80119C0:
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_800C5D0
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_80119C0

	thumb_func_start sub_80119D4
sub_80119D4:
	push {r4,lr}
	adds r2, r0, 0
	ldr r4, _080119FC
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _080119F6
	ldr r1, _08011A00
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
	movs r0, 0x4
	strh r0, [r4]
_080119F6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080119FC: .4byte gUnknown_202DE20
_08011A00: .4byte gUnknown_80D4144
	thumb_func_end sub_80119D4

	thumb_func_start sub_8011A04
sub_8011A04:
	push {lr}
	ldr r1, _08011A24
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bgt _08011A1E
	movs r0, 0x3
	strh r0, [r1]
	ldr r0, _08011A28
	movs r1, 0x80
	lsls r1, 1
	bl sub_800C074
_08011A1E:
	pop {r0}
	bx r0
	.align 2, 0
_08011A24: .4byte gUnknown_202DE22
_08011A28: .4byte 0x00000131
	thumb_func_end sub_8011A04

	thumb_func_start sub_8011A2C
sub_8011A2C:
	ldr r1, _08011A34
	str r0, [r1]
	bx lr
	.align 2, 0
_08011A34: .4byte gUnknown_202DE1C
	thumb_func_end sub_8011A2C

	thumb_func_start NDS_DebugInit
NDS_DebugInit:
	push {lr}
	bl nullsub_26
	bl nullsub_27
	bl nullsub_29
	bl nullsub_30
	bl nullsub_31
	bl nullsub_32
	bl nullsub_28
	ldr r1, _08011A60
	movs r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011A60: .4byte gUnknown_203B14C
	thumb_func_end NDS_DebugInit

	thumb_func_start nullsub_25
nullsub_25:
	bx lr
	thumb_func_end nullsub_25

	thumb_func_start nullsub_26
nullsub_26:
	bx lr
	thumb_func_end nullsub_26

	thumb_func_start PrintFuncFileLineOrNotEntry
PrintFuncFileLineOrNotEntry:
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r0, r1, 0
	cmp r0, 0
	beq _08011A90
	ldr r1, _08011A8C
	ldr r2, [r0, 0x8]
	ldr r3, [r0]
	ldr r0, [r0, 0x4]
	str r0, [sp]
	adds r0, r4, 0
	bl sprintf
	b _08011A98
	.align 2, 0
_08011A8C: .4byte gUnknown_80D418C
_08011A90:
	ldr r1, _08011AA0
	adds r0, r4, 0
	bl sprintf
_08011A98:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011AA0: .4byte gUnknown_80D41B0
	thumb_func_end PrintFuncFileLineOrNotEntry

	thumb_func_start PrintFuncFileLine
PrintFuncFileLine:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, _08011AC4
	ldr r3, [r1, 0x8]
	ldr r4, [r1]
	str r4, [sp]
	ldr r1, [r1, 0x4]
	str r1, [sp, 0x4]
	adds r1, r5, 0
	bl sprintf
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011AC4: .4byte gUnknown_80D41C4
	thumb_func_end PrintFuncFileLine

	thumb_func_start PrintMessageWithFuncFileLine
PrintMessageWithFuncFileLine:
	push {r2,r3}
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r1, [sp, 0x10]
	add r2, sp, 0x14
	bl vsprintf
	adds r0, r4, 0
	bl strlen
	adds r4, r0
	ldr r1, _08011AFC
	ldr r2, [r5, 0x8]
	ldr r3, [r5]
	ldr r0, [r5, 0x4]
	str r0, [sp]
	adds r0, r4, 0
	bl sprintf
	add sp, 0x4
	pop {r4,r5}
	pop {r3}
	add sp, 0x8
	bx r3
	.align 2, 0
_08011AFC: .4byte gUnknown_80D41EC
	thumb_func_end PrintMessageWithFuncFileLine

	thumb_func_start nullsub_199
nullsub_199:
	bx lr
	thumb_func_end nullsub_199

	thumb_func_start nullsub_27
nullsub_27:
	bx lr
	thumb_func_end nullsub_27

	thumb_func_start sub_8011B08
sub_8011B08:
	ldr r1, _08011B10
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08011B10: .4byte gUnknown_203B150
	thumb_func_end sub_8011B08

	thumb_func_start sub_8011B14
sub_8011B14:
	ldr r1, _08011B1C
	movs r0, 0
	strb r0, [r1]
	bx lr
	.align 2, 0
_08011B1C: .4byte gUnknown_203B150
	thumb_func_end sub_8011B14

	thumb_func_start sub_8011B20
sub_8011B20:
	push {lr}
	ldr r1, _08011B38
	movs r2, 0
	ldrb r0, [r1]
	cmp r0, 0
	bne _08011B2E
	movs r2, 0x1
_08011B2E:
	strb r2, [r1]
	ldrb r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08011B38: .4byte gUnknown_203B150
	thumb_func_end sub_8011B20

	thumb_func_start sub_8011B3C
sub_8011B3C:
	ldr r0, _08011B44
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08011B44: .4byte gUnknown_203B150
	thumb_func_end sub_8011B3C

	thumb_func_start nullsub_137
nullsub_137:
	bx lr
	thumb_func_end nullsub_137

	thumb_func_start FatalErrorPrintFuncFileLine
FatalErrorPrintFuncFileLine:
	push {lr}
	sub sp, 0x100
	adds r2, r0, 0
	cmp r2, 0
	beq _08011B5E
	mov r0, sp
	bl PrintFuncFileLine
	b _08011B66
_08011B5E:
	ldr r2, _08011B6C
	mov r0, sp
	bl PrintFuncFileLine
_08011B66:
	add sp, 0x100
	pop {r0}
	bx r0
	.align 2, 0
_08011B6C: .4byte gUnknown_80D421C
	thumb_func_end FatalErrorPrintFuncFileLine

	thumb_func_start FatalErrorFormatMessage
FatalErrorFormatMessage:
	push {r0-r3}
	push {lr}
	sub sp, 0x100
	ldr r1, [sp, 0x104]
	add r2, sp, 0x108
	mov r0, sp
	bl vsprintf
	add sp, 0x100
	pop {r3}
	add sp, 0x10
	bx r3
	thumb_func_end FatalErrorFormatMessage

	thumb_func_start sub_8011B88
sub_8011B88:
	push {r0-r3}
	push {lr}
	sub sp, 0x100
	ldr r1, [sp, 0x104]
	add r2, sp, 0x108
	mov r0, sp
	bl vsprintf
	add sp, 0x100
	pop {r3}
	add sp, 0x10
	bx r3
	thumb_func_end sub_8011B88

	thumb_func_start nullsub_28
nullsub_28:
	bx lr
	thumb_func_end nullsub_28

	thumb_func_start sub_8011BA4
sub_8011BA4:
	movs r0, 0
	bx lr
	thumb_func_end sub_8011BA4

	thumb_func_start sub_8011BA8
sub_8011BA8:
	movs r0, 0
	bx lr
	thumb_func_end sub_8011BA8

	thumb_func_start sub_8011BAC
sub_8011BAC:
	ldr r0, _08011BB0
	bx lr
	.align 2, 0
_08011BB0: .4byte gUnknown_80D4288
	thumb_func_end sub_8011BAC

	thumb_func_start sub_8011BB4
sub_8011BB4:
	push {lr}
	bl Hang
	pop {r0}
	bx r0
	thumb_func_end sub_8011BB4

	thumb_func_start Log
Log:
	push {r1-r3}
	add sp, 0xC
	bx lr
	thumb_func_end Log

	thumb_func_start sub_8011BC8
sub_8011BC8:
	push {r2,r3}
	add sp, 0x8
	bx lr
	thumb_func_end sub_8011BC8

	thumb_func_start nullsub_29
nullsub_29:
	bx lr
	thumb_func_end nullsub_29

	thumb_func_start nullsub_30
nullsub_30:
	bx lr
	thumb_func_end nullsub_30

	thumb_func_start nullsub_31
nullsub_31:
	bx lr
	thumb_func_end nullsub_31

	thumb_func_start nullsub_32
nullsub_32:
	bx lr
	thumb_func_end nullsub_32

	thumb_func_start FatalErrorHang
FatalErrorHang:
	push {lr}
	bl Hang
	pop {r0}
	bx r0
	thumb_func_end FatalErrorHang

	thumb_func_start FatalError
FatalError:
	push {r1-r3}
	push {r4,lr}
	sub sp, 0x100
	adds r1, r0, 0
	ldr r4, [sp, 0x108]
	ldr r0, _08011C14
	bl FatalErrorPrintFuncFileLine
	add r2, sp, 0x10C
	mov r0, sp
	adds r1, r4, 0
	bl vsprintf
	ldr r0, _08011C18
	mov r1, sp
	bl FatalErrorFormatMessage
	bl FatalErrorHang
	.align 2, 0
_08011C14: .4byte gUnknown_80D42C0
_08011C18: .4byte gUnknown_80D42D4
	thumb_func_end FatalError

        .align 2,0 @ Don't pad with nop
