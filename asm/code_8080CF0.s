	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_80819F0
sub_80819F0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r4, 0x3]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80819F0

	thumb_func_start sub_8081A24
sub_8081A24:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldr r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083078
	ldrb r1, [r4, 0x8]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x9]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0xA]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A24

	thumb_func_start sub_8081A58
sub_8081A58:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A58

	thumb_func_start sub_8081A74
sub_8081A74:
	push {lr}
	movs r2, 0x1
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_8081A74

	thumb_func_start sub_8081A80
sub_8081A80:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A80

	thumb_func_start sub_8081A9C
sub_8081A9C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081A9C

	thumb_func_start sub_8081AB8
sub_8081AB8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081AB8

	thumb_func_start sub_8081AD4
sub_8081AD4:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	bl sub_8083060
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x2
	bl sub_8082FA8
	ldrb r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x5]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081AD4

	thumb_func_start sub_8081B08
sub_8081B08:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_08081B12:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8081AD4
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08081B12
	adds r0, r7, 0
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8083060
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B08

	thumb_func_start sub_8081B34
sub_8081B34:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_8083048
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B34

	thumb_func_start sub_8081B54
sub_8081B54:
	push {lr}
	movs r2, 0x3
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_8081B54

	thumb_func_start sub_8081B60
sub_8081B60:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrh r1, [r4]
	bl sub_8083030
	ldrh r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083030
	adds r1, r4, 0
	adds r1, 0x9
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0xE
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B60

	thumb_func_start sub_8081B94
sub_8081B94:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x1
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	movs r4, 0
_08081BAC:
	adds r0, r5, 0x3
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8083060
	adds r0, r5, 0
	adds r0, 0xB
	adds r0, r4
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8083060
	adds r4, 0x1
	cmp r4, 0x7
	ble _08081BAC
	ldrb r1, [r5, 0x2]
	adds r0, r6, 0
	bl sub_8083060
	ldrb r1, [r5, 0x13]
	adds r0, r6, 0
	bl sub_8083060
	ldrb r1, [r5, 0x14]
	adds r0, r6, 0
	bl sub_8083060
	ldrb r1, [r5, 0x15]
	adds r0, r6, 0
	bl sub_80830B4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8081B94

	thumb_func_start sub_8081BF4
sub_8081BF4:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_8082FD4
	add r1, sp, 0xC
	mov r0, sp
	movs r2, 0x4
	bl sub_8082FE0
	mov r0, sp
	bl sub_8081C50
	mov r0, sp
	bl sub_8081C7C
	mov r0, sp
	bl sub_8081F2C
	mov r0, sp
	bl sub_808201C
	mov r0, sp
	bl sub_8082060
	mov r0, sp
	bl sub_80820D8
	mov r0, sp
	bl sub_808217C
	ldr r1, _08081C4C
	mov r0, sp
	bl sub_8083018
	mov r0, sp
	bl nullsub_98
	add sp, 0x10
	pop {r0}
	bx r0
	.align 2, 0
_08081C4C: .4byte gUnknown_81071D4
	thumb_func_end sub_8081BF4

	thumb_func_start sub_8081C50
sub_8081C50:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08081C70
	bl sub_8083018
	ldr r0, _08081C74
	ldr r1, [r0]
	ldr r0, _08081C78
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0x58
	bl sub_8082FE0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08081C70: .4byte gUnknown_81071E0
_08081C74: .4byte gDungeon
_08081C78: .4byte 0x00000644
	thumb_func_end sub_8081C50

	thumb_func_start sub_8081C7C
sub_8081C7C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	ldr r1, _08081E20
	bl sub_8083018
	adds r0, r7, 0
	bl sub_80831DC
	ldr r4, _08081E24
	ldr r1, [r4]
	ldr r2, _08081E28
	adds r1, r2
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r3, _08081E2C
	adds r1, r3
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08081E30
	adds r1, r2
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r3, _08081E34
	adds r1, r3
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r2, _08081E38
	adds r1, r2
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r3, _08081E3C
	adds r1, r3
	strb r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08081E40
	adds r1, r2
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r3, _08081E44
	adds r1, r3
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08081E48
	adds r1, r2
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r3, _08081E4C
	adds r1, r3
	strh r0, [r1]
	adds r0, r7, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08081E50
	adds r1, r2
	strh r0, [r1]
	movs r1, 0
	mov r9, r4
_08081D2E:
	lsls r0, r1, 2
	adds r3, r1, 0x1
	mov r8, r3
	adds r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081E54
	adds r6, r0, r1
	movs r5, 0
	movs r4, 0x37
_08081D44:
	mov r2, r9
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081E7C
	adds r5, 0x18
	subs r4, 0x1
	cmp r4, 0
	bge _08081D44
	mov r1, r8
	cmp r1, 0x1F
	ble _08081D2E
	ldr r4, _08081E24
	ldr r1, [r4]
	ldr r3, _08081E58
	adds r1, r3
	adds r0, r7, 0
	bl sub_80831F8
	ldr r1, [r4]
	ldr r0, _08081E5C
	adds r1, r0
	adds r0, r7, 0
	bl sub_80831F8
	ldr r6, _08081E60
	movs r5, 0x7
_08081D7E:
	ldr r1, [r4]
	adds r1, r6
	adds r0, r7, 0
	bl sub_80831F8
	adds r6, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08081D7E
	ldr r4, _08081E24
	ldr r1, [r4]
	ldr r2, _08081E64
	adds r1, r2
	adds r0, r7, 0
	bl sub_8083220
	ldr r1, [r4]
	ldr r3, _08081E68
	adds r1, r3
	adds r0, r7, 0
	bl sub_8083220
	ldr r1, [r4]
	ldr r0, _08081E6C
	adds r1, r0
	adds r0, r7, 0
	bl sub_8083260
	movs r1, 0
	mov r10, r4
_08081DBA:
	movs r4, 0
	adds r2, r1, 0x1
	mov r8, r2
	lsls r0, r1, 1
	lsls r3, r1, 3
	mov r9, r3
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081E70
	adds r6, r0, r1
	movs r5, 0
_08081DD0:
	mov r2, r10
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081E7C
	adds r0, r7, 0
	bl sub_8083188
	mov r3, r10
	ldr r1, [r3]
	mov r3, r9
	adds r2, r4, r3
	ldr r3, _08081E74
	adds r1, r3
	adds r1, r2
	strb r0, [r1]
	adds r5, 0x18
	adds r4, 0x1
	cmp r4, 0x7
	ble _08081DD0
	mov r1, r8
	cmp r1, 0x7
	ble _08081DBA
	ldr r0, _08081E24
	ldr r1, [r0]
	ldr r0, _08081E78
	adds r1, r0
	adds r0, r7, 0
	bl sub_8081EC0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081E20: .4byte gUnknown_81071E0
_08081E24: .4byte gDungeon
_08081E28: .4byte 0x00003a08
_08081E2C: .4byte 0x00003a09
_08081E30: .4byte 0x00003a0a
_08081E34: .4byte 0x00003a0b
_08081E38: .4byte 0x00003a0c
_08081E3C: .4byte 0x00003a0d
_08081E40: .4byte 0x00003a0e
_08081E44: .4byte 0x00003a10
_08081E48: .4byte 0x00003a12
_08081E4C: .4byte 0x00003a14
_08081E50: .4byte 0x00003a16
_08081E54: .4byte 0x00003a18
_08081E58: .4byte 0x0000e218
_08081E5C: .4byte 0x0000e21c
_08081E60: .4byte 0x0000e220
_08081E64: .4byte 0x0000e240
_08081E68: .4byte 0x0000e250
_08081E6C: .4byte 0x0000e260
_08081E70: .4byte 0x0000e27c
_08081E74: .4byte 0x0000e87c
_08081E78: .4byte 0x0000e264
	thumb_func_end sub_8081C7C

	thumb_func_start sub_8081E7C
sub_8081E7C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x18
	bl memset
	adds r0, r5, 0
	bl sub_8083158
	movs r6, 0
	strh r0, [r4]
	adds r0, r5, 0
	bl sub_8083158
	strh r0, [r4, 0x4]
	adds r1, r4, 0
	adds r1, 0x9
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0
	adds r1, 0xE
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	str r6, [r4, 0x10]
	str r6, [r4, 0x14]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8081E7C

	thumb_func_start sub_8081EC0
sub_8081EC0:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0x18
	bl memset
	adds r0, r6, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r5, 0x1
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FE0
	movs r4, 0
_08081EE6:
	adds r0, r6, 0
	bl sub_8083188
	adds r1, r5, 0x3
	adds r1, r4
	strb r0, [r1]
	adds r0, r6, 0
	bl sub_8083188
	adds r1, r5, 0
	adds r1, 0xB
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x7
	ble _08081EE6
	adds r0, r6, 0
	bl sub_8083188
	strb r0, [r5, 0x2]
	adds r0, r6, 0
	bl sub_8083188
	strb r0, [r5, 0x13]
	adds r0, r6, 0
	bl sub_8083188
	strb r0, [r5, 0x14]
	adds r0, r6, 0
	bl sub_80831DC
	strb r0, [r5, 0x15]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8081EC0

	thumb_func_start sub_8081F2C
sub_8081F2C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08081FE4
	bl sub_8083018
	ldr r4, _08081FE8
	ldr r0, [r4]
	ldr r1, _08081FEC
	adds r0, r1
	movs r1, 0
	str r1, [r0]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r2, _08081FF0
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [r4]
	ldr r2, _08081FF4
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08081FF8
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08081FFC
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082000
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082004
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082008
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _0808200C
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082010
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082014
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082018
	adds r1, r2
	strb r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081FE4: .4byte gUnknown_81071E0
_08081FE8: .4byte gDungeon
_08081FEC: .4byte 0x000181f8
_08081FF0: .4byte 0x00018208
_08081FF4: .4byte 0x00018209
_08081FF8: .4byte 0x0001820a
_08081FFC: .4byte 0x0001820b
_08082000: .4byte 0x0001820c
_08082004: .4byte 0x0001820d
_08082008: .4byte 0x0001820e
_0808200C: .4byte 0x0001820f
_08082010: .4byte 0x00018210
_08082014: .4byte 0x00018211
_08082018: .4byte 0x00018213
	thumb_func_end sub_8081F2C

	thumb_func_start sub_808201C
sub_808201C:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8083170
	ldr r4, _08082050
	ldr r1, [r4]
	ldr r2, _08082054
	adds r1, r2
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _08082058
	adds r1, r2
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	ldr r1, [r4]
	ldr r2, _0808205C
	adds r1, r2
	strh r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082050: .4byte gDungeon
_08082054: .4byte 0x0001ced6
_08082058: .4byte 0x0001ced8
_0808205C: .4byte 0x0001ceda
	thumb_func_end sub_808201C

	thumb_func_start sub_8082060
sub_8082060:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r1, _080820A4
	bl sub_8083018
	add r4, sp, 0x4
	mov r7, sp
	movs r6, 0x3F
_08082072:
	adds r0, r5, 0
	mov r1, sp
	bl sub_80820A8
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	ldrb r1, [r7]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08082096
	adds r0, r4, 0
	mov r1, sp
	movs r2, 0
	bl sub_80460F8
_08082096:
	subs r6, 0x1
	cmp r6, 0
	bge _08082072
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080820A4: .4byte gUnknown_81071E0
	thumb_func_end sub_8082060

	thumb_func_start sub_80820A8
sub_80820A8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	str r0, [r4]
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0x1
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80820A8

	thumb_func_start sub_80820D8
sub_80820D8:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r1, _08082178
	bl sub_8083018
	movs r0, 0x1
	add r0, sp
	mov r9, r0
	add r1, sp, 0x4
	mov r8, r1
	mov r7, sp
	movs r2, 0x3F
	mov r10, r2
_080820FC:
	movs r0, 0x6
	strb r0, [r7]
	movs r0, 0
	mov r3, sp
	strb r0, [r3, 0x1]
	adds r0, r5, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r5, 0
	mov r1, sp
	adds r1, 0x1
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r5, 0
	bl sub_80831DC
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0
	add r1, sp, 0x4
	bl sub_80831F8
	ldrb r0, [r7]
	cmp r0, 0xFF
	beq _0808215C
	mov r1, r8
	movs r2, 0
	ldrsh r0, [r1, r2]
	mov r3, sp
	movs r2, 0x6
	ldrsh r1, [r3, r2]
	bl GetTileSafe
	adds r4, r0, 0
	ldrb r0, [r7]
	mov r3, r9
	ldrb r2, [r3]
	mov r1, r8
	bl sub_8045684
	cmp r0, 0
	beq _0808215C
	str r0, [r4, 0x14]
	adds r0, 0x20
	strb r6, [r0]
_0808215C:
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r1, r10
	cmp r1, 0
	bge _080820FC
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082178: .4byte gUnknown_81071E0
	thumb_func_end sub_80820D8

	thumb_func_start sub_808217C
sub_808217C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08082250
	bl sub_8083018
	adds r0, r5, 0
	bl sub_80831A0
	ldr r4, _08082254
	ldr r1, [r4]
	ldr r2, _08082258
	adds r1, r2
	str r0, [r1]
	adds r0, r5, 0
	bl sub_80831A0
	ldr r1, [r4]
	ldr r2, _0808225C
	adds r1, r2
	str r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082260
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082264
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082268
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _0808226C
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082270
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082274
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _08082278
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [r4]
	ldr r2, _0808227C
	adds r1, r2
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	ldr r1, [r4]
	movs r2, 0xE0
	lsls r2, 6
	adds r1, r2
	strh r0, [r1]
	movs r4, 0
_08082226:
	adds r0, r5, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl sub_8082280
	adds r4, 0x1
	cmp r4, 0x3
	ble _08082226
	movs r4, 0
_08082238:
	adds r0, r5, 0
	movs r1, 0
	adds r2, r4, 0
	bl sub_8082280
	adds r4, 0x1
	cmp r4, 0xF
	ble _08082238
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082250: .4byte gUnknown_81071E0
_08082254: .4byte gDungeon
_08082258: .4byte 0x000037f0
_0808225C: .4byte 0x000037f4
_08082260: .4byte 0x000037f8
_08082264: .4byte 0x000037f9
_08082268: .4byte 0x000037fa
_0808226C: .4byte 0x000037fb
_08082270: .4byte 0x000037fc
_08082274: .4byte 0x000037fd
_08082278: .4byte 0x000037fe
_0808227C: .4byte 0x000037ff
	thumb_func_end sub_808217C

	thumb_func_start sub_8082280
sub_8082280:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _0808266C
	add sp, r4
	adds r5, r0, 0
	str r2, [sp, 0x210]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x20C]
	movs r2, 0x82
	lsls r2, 2
	mov r0, sp
	movs r1, 0
	bl memset
	adds r0, r5, 0
	bl sub_8083188
	adds r0, r5, 0
	bl sub_8083188
	adds r0, r5, 0
	bl sub_8083188
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x214]
	add r4, sp, 0x208
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	adds r0, r5, 0
	bl sub_80831DC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x218]
	adds r0, r5, 0
	bl sub_8083158
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x21C]
	ldr r1, _08082670
	movs r0, 0
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8082BC0
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r5, 0
	bl sub_8082BC0
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r5, 0
	bl sub_80831DC
	mov r1, sp
	strb r0, [r1, 0x6]
	adds r0, r5, 0
	bl sub_80831DC
	mov r1, sp
	strb r0, [r1, 0x7]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x8]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x9]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0xA]
	add r1, sp, 0x40
	adds r0, r5, 0
	bl sub_8082F64
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0xC]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0xE]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x10]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x12]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x14]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x15]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x16]
	adds r0, r5, 0
	bl sub_8083188
	mov r1, sp
	strb r0, [r1, 0x17]
	adds r0, r5, 0
	bl sub_80831A0
	str r0, [sp, 0x18]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x1C]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x1E]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x20]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x22]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x24]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x26]
	adds r0, r5, 0
	bl sub_8083170
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x2C]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x30]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x34]
	adds r0, r5, 0
	bl sub_80831C8
	str r0, [sp, 0x38]
	add r1, sp, 0x44
	adds r0, r5, 0
	bl sub_8082CBC
	adds r0, r5, 0
	bl sub_8082BFC
	add r1, sp, 0x5C
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082BFC
	mov r1, sp
	adds r1, 0x5D
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C18
	mov r1, sp
	adds r1, 0x5E
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C18
	mov r1, sp
	adds r1, 0x5F
	strb r0, [r1]
	add r1, sp, 0x60
	adds r0, r5, 0
	bl sub_80820A8
	adds r0, r5, 0
	bl sub_8082BE0
	add r1, sp, 0x64
	strb r0, [r1]
	add r7, sp, 0x78
	add r0, sp, 0x8C
	mov r8, r0
	add r1, sp, 0x90
	mov r9, r1
	add r2, sp, 0x94
	mov r10, r2
	mov r3, sp
	adds r3, 0x3C
	str r3, [sp, 0x270]
	mov r0, sp
	adds r0, 0x98
	str r0, [sp, 0x274]
	mov r1, sp
	adds r1, 0x9C
	str r1, [sp, 0x278]
	mov r2, sp
	adds r2, 0xA0
	str r2, [sp, 0x27C]
	adds r3, 0x6C
	str r3, [sp, 0x284]
	adds r0, 0x14
	str r0, [sp, 0x288]
	adds r1, 0x14
	str r1, [sp, 0x28C]
	adds r2, 0x1C
	str r2, [sp, 0x290]
	adds r3, 0x18
	str r3, [sp, 0x294]
	adds r0, 0x18
	str r0, [sp, 0x298]
	adds r1, 0x18
	str r1, [sp, 0x29C]
	adds r2, 0x14
	str r2, [sp, 0x220]
	adds r3, 0x1C
	str r3, [sp, 0x224]
	adds r0, 0x1C
	str r0, [sp, 0x228]
	adds r1, 0x1C
	str r1, [sp, 0x22C]
	adds r2, 0x18
	str r2, [sp, 0x230]
	adds r3, 0x10
	str r3, [sp, 0x234]
	adds r0, 0x10
	str r0, [sp, 0x238]
	adds r1, 0xD
	str r1, [sp, 0x23C]
	adds r2, 0xA
	str r2, [sp, 0x240]
	adds r3, 0x7
	str r3, [sp, 0x244]
	adds r0, 0x4
	str r0, [sp, 0x248]
	adds r1, 0xA
	str r1, [sp, 0x25C]
	adds r2, 0x3
	str r2, [sp, 0x24C]
	adds r3, 0x3
	str r3, [sp, 0x250]
	adds r0, 0x3
	str r0, [sp, 0x254]
	subs r1, 0x1
	str r1, [sp, 0x258]
	adds r2, 0x7
	str r2, [sp, 0x260]
	adds r3, 0x7
	str r3, [sp, 0x264]
	adds r0, 0x7
	str r0, [sp, 0x268]
	adds r1, 0x5
	str r1, [sp, 0x26C]
	subs r2, 0x58
	str r2, [sp, 0x280]
	add r4, sp, 0x68
	movs r6, 0x3
_080824DC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	adds r4, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _080824DC
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_8082CE4
	adds r0, r5, 0
	mov r1, r8
	bl sub_8082D28
	adds r0, r5, 0
	mov r1, r9
	bl sub_8082D28
	adds r0, r5, 0
	bl sub_8082C84
	movs r4, 0
	mov r3, r10
	strb r0, [r3]
	adds r0, r5, 0
	ldr r1, [sp, 0x270]
	bl sub_8082F80
	adds r0, r5, 0
	bl sub_80831A0
	ldr r1, [sp, 0x274]
	str r0, [r1]
	adds r0, r5, 0
	bl sub_80831A0
	ldr r2, [sp, 0x278]
	str r0, [r2]
	adds r0, r5, 0
	bl sub_80831A0
	ldr r3, [sp, 0x27C]
	str r0, [r3]
	adds r0, r5, 0
	ldr r1, [sp, 0x284]
	bl sub_8082D34
	adds r0, r5, 0
	ldr r1, [sp, 0x288]
	bl sub_8082D50
	adds r0, r5, 0
	ldr r1, [sp, 0x28C]
	bl sub_8082D7C
	adds r0, r5, 0
	ldr r1, [sp, 0x290]
	bl sub_8082DA8
	adds r0, r5, 0
	ldr r1, [sp, 0x294]
	bl sub_8082DC4
	adds r0, r5, 0
	ldr r1, [sp, 0x298]
	bl sub_8082DE8
	adds r0, r5, 0
	ldr r1, [sp, 0x29C]
	bl sub_8082E04
	adds r0, r5, 0
	ldr r1, [sp, 0x220]
	bl sub_8082E38
	adds r0, r5, 0
	ldr r1, [sp, 0x224]
	bl sub_8082E6C
	adds r0, r5, 0
	ldr r1, [sp, 0x228]
	bl sub_8082E88
	adds r0, r5, 0
	ldr r1, [sp, 0x22C]
	bl sub_8082E94
	adds r0, r5, 0
	ldr r1, [sp, 0x230]
	bl sub_8082EB0
	adds r0, r5, 0
	ldr r1, [sp, 0x234]
	bl sub_8082ECC
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [sp, 0x238]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x23C]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r3, [sp, 0x240]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [sp, 0x244]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x248]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_8083188
	ldr r3, [sp, 0x25C]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, [sp, 0x24C]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x250]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r3, [sp, 0x254]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [sp, 0x258]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r2, [sp, 0x260]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_8083188
	ldr r3, [sp, 0x264]
	strb r0, [r3]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, [sp, 0x268]
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C34
	ldr r2, [sp, 0x26C]
	strb r0, [r2]
	adds r0, r5, 0
	bl sub_8082C50
	add r1, sp, 0x100
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8082C6C
	add r1, sp, 0x104
	str r0, [r1]
	add r1, sp, 0x108
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_8083288
	ldr r1, _08082674
	add r1, sp
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_8083288
	adds r0, r5, 0
	bl sub_8083188
	movs r1, 0x89
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	b _08082678
	.align 2, 0
_0808266C: .4byte 0xfffffd60
_08082670: .4byte gLeaderPointer
_08082674: .4byte 0x0000010d
_08082678:
	ldr r1, _08082818
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	add r1, sp, 0x114
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	add r1, sp, 0x118
	adds r0, r5, 0
	bl sub_8082F1C
	add r1, sp, 0x13C
	adds r0, r5, 0
	bl sub_8082F48
	add r1, sp, 0x140
	adds r0, r5, 0
	bl sub_8082F48
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x144
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _0808281C
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082820
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xA3
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x148
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082824
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xA5
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082828
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x14C
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	movs r1, 0xA7
	lsls r1, 1
	add r1, sp
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	add r1, sp, 0x150
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xA9
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _0808282C
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	add r1, sp, 0x154
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	ldr r1, _08082830
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_80831DC
	movs r1, 0xAB
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	add r1, sp, 0x164
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _08082834
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	movs r1, 0xB3
	lsls r1, 1
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _08082838
	add r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	add r1, sp, 0x168
	strb r0, [r1]
	adds r0, r5, 0
	bl sub_8083188
	ldr r1, _0808283C
	add r1, sp
	strb r0, [r1]
	add r1, sp, 0x16C
	adds r0, r5, 0
	bl sub_80831F8
	adds r0, r5, 0
	bl sub_80831C8
	add r1, sp, 0x174
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8083158
	add r1, sp, 0x178
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	add r1, sp, 0x1F8
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_8083170
	movs r1, 0xFD
	lsls r1, 1
	add r1, sp
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_80831A0
	add r1, sp, 0x1FC
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8082CA0
	ldr r3, [sp, 0x280]
	strb r0, [r3]
	ldr r0, _08082840
	str r4, [r0]
	ldr r0, [sp, 0x214]
	cmp r0, 0
	beq _080828BE
	ldr r1, [sp, 0x20C]
	cmp r1, 0
	beq _08082844
	mov r0, sp
	movs r2, 0x2
	ldrsh r0, [r0, r2]
	mov r1, sp
	movs r3, 0x4
	ldrsh r1, [r1, r3]
	ldr r2, [sp, 0x210]
	bl sub_80828E0
	b _08082856
	.align 2, 0
_08082818: .4byte 0x00000113
_0808281C: .4byte 0x00000145
_08082820: .4byte 0x00000147
_08082824: .4byte 0x00000149
_08082828: .4byte 0x0000014b
_0808282C: .4byte 0x00000153
_08082830: .4byte 0x00000155
_08082834: .4byte 0x00000165
_08082838: .4byte 0x00000167
_0808283C: .4byte 0x00000169
_08082840: .4byte gLeaderPointer
_08082844:
	mov r0, sp
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, 0x4
	ldrsh r1, [r1, r2]
	ldr r2, [sp, 0x210]
	bl sub_8082A08
_08082856:
	adds r7, r0, 0
	cmp r7, 0
	beq _080828BE
	ldr r6, [r7, 0x70]
	movs r5, 0x82
	lsls r5, 2
	mov r3, sp
	adds r4, r3, r5
	movs r1, 0
	ldrsh r0, [r4, r1]
	ldr r3, _080828D4
	add r3, sp
	movs r2, 0
	ldrsh r1, [r3, r2]
	bl GetTileSafe
	ldr r1, [r4]
	str r1, [r7, 0x8]
	ldr r1, [r4]
	str r1, [r7, 0x4]
	str r7, [r0, 0x10]
	adds r0, r7, 0
	adds r0, 0x20
	movs r4, 0
	add r1, sp, 0x218
	ldrb r1, [r1]
	strb r1, [r0]
	add r2, sp, 0x21C
	ldrh r2, [r2]
	strh r2, [r7, 0x26]
	adds r0, r6, 0
	mov r1, sp
	adds r2, r5, 0
	bl memcpy
	ldr r0, _080828D8
	str r4, [r0]
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _080828B0
	ldr r0, _080828DC
	ldrh r1, [r7, 0x4]
	strh r1, [r0]
	ldrh r1, [r7, 0x6]
	strh r1, [r0, 0x2]
_080828B0:
	adds r0, r7, 0
	bl LoadIQSkills
	adds r0, r7, 0
	movs r1, 0
	bl sub_804535C
_080828BE:
	movs r3, 0xA8
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
_080828D4: .4byte 0x0000020a
_080828D8: .4byte gLeaderPointer
_080828DC: .4byte gUnknown_203B410
	thumb_func_end sub_8082280

	thumb_func_start sub_80828E0
sub_80828E0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r2, 0
	lsls r0, 16
	asrs r0, 16
	mov r10, r0
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	movs r4, 0x1
	negs r4, r4
	mov r0, r8
	bl GetBodySize
	lsls r0, 24
	lsrs r6, r0, 24
	movs r3, 0
	movs r0, 0x6
	subs r7, r0, r6
	ldr r0, _08082914
	mov r9, r0
	b _0808291A
	.align 2, 0
_08082914: .4byte gUnknown_202EE70
_08082918:
	adds r3, 0x1
_0808291A:
	cmp r3, r7
	bgt _0808293E
	movs r2, 0
	cmp r2, r6
	bge _08082938
	mov r0, r9
	adds r1, r3, r0
	b _08082932
_0808292A:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r6
	bge _08082938
_08082932:
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808292A
_08082938:
	cmp r2, r6
	bne _08082918
	adds r4, r3, 0
_0808293E:
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0808294A
	movs r0, 0
	b _080829E6
_0808294A:
	ldr r2, _080829F4
	ldr r0, [r2]
	lsls r1, r5, 2
	ldr r3, _080829F8
	adds r0, r3
	adds r0, r1
	ldr r7, [r0]
	movs r0, 0x1
	mov r9, r0
	str r0, [r7]
	adds r0, r7, 0
	adds r0, 0x24
	strb r5, [r0]
	lsls r0, r5, 6
	adds r0, r5
	lsls r0, 3
	ldr r1, _080829FC
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r7, 0x70]
	movs r5, 0
	mov r3, r10
	strh r3, [r1, 0x2]
	ldr r0, [r7, 0x70]
	mov r1, r8
	strh r1, [r0, 0x4]
	ldr r0, [r7, 0x70]
	strb r5, [r0, 0x6]
	mov r0, r8
	bl sub_80687D0
	str r0, [r7, 0x64]
	lsls r0, r4, 4
	adds r0, 0x40
	adds r1, r7, 0
	adds r1, 0x68
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6C
	strb r5, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6D
	mov r3, r9
	strb r3, [r0]
	adds r0, 0x2
	strb r3, [r0]
	movs r0, 0
	str r0, [r7, 0x1C]
	bl sub_8045ACC
	ldr r0, [r7, 0x70]
	ldr r1, _08082A00
	adds r0, r1
	strb r4, [r0]
	ldr r0, [r7, 0x70]
	movs r3, 0xB4
	lsls r3, 1
	adds r0, r3
	strb r6, [r0]
	cmp r6, 0
	beq _080829E4
	ldr r3, _08082A04
	movs r2, 0x1
	adds r1, r6, 0
_080829D8:
	adds r0, r4, r3
	strb r2, [r0]
	adds r4, 0x1
	subs r1, 0x1
	cmp r1, 0
	bne _080829D8
_080829E4:
	adds r0, r7, 0
_080829E6:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080829F4: .4byte gDungeon
_080829F8: .4byte 0x0001357c
_080829FC: .4byte 0x0000069c
_08082A00: .4byte 0x00000167
_08082A04: .4byte gUnknown_202EE70
	thumb_func_end sub_80828E0

	thumb_func_start sub_8082A08
sub_8082A08:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r2, 0
	lsls r0, 16
	asrs r0, 16
	str r0, [sp]
	lsls r1, 16
	asrs r1, 16
	mov r9, r1
	movs r0, 0x1
	negs r0, r0
	mov r8, r0
	mov r0, r9
	bl GetBodySize
	lsls r0, 24
	lsrs r6, r0, 24
	movs r3, 0
	movs r0, 0x10
	subs r4, r0, r6
	ldr r7, _08082A3C
	b _08082A42
	.align 2, 0
_08082A3C: .4byte gUnknown_202EE76
_08082A40:
	adds r3, 0x1
_08082A42:
	cmp r3, r4
	bgt _08082A64
	movs r2, 0
	cmp r2, r6
	bge _08082A5E
	adds r1, r3, r7
	b _08082A58
_08082A50:
	adds r1, 0x1
	adds r2, 0x1
	cmp r2, r6
	bge _08082A5E
_08082A58:
	ldrb r0, [r1]
	cmp r0, 0
	beq _08082A50
_08082A5E:
	cmp r2, r6
	bne _08082A40
	mov r8, r3
_08082A64:
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	bne _08082A70
	movs r0, 0
	b _08082B1C
_08082A70:
	ldr r2, _08082B2C
	ldr r0, [r2]
	lsls r1, r5, 2
	ldr r3, _08082B30
	adds r0, r3
	adds r0, r1
	ldr r7, [r0]
	movs r4, 0x1
	str r4, [r7]
	adds r0, r7, 0
	adds r0, 0x24
	movs r1, 0
	mov r10, r1
	strb r5, [r0]
	subs r0, 0x2
	mov r3, r10
	strb r3, [r0]
	lsls r0, r5, 6
	adds r0, r5
	lsls r0, 3
	ldr r1, _08082B34
	adds r0, r1
	ldr r1, [r2]
	adds r1, r0
	str r1, [r7, 0x70]
	movs r5, 0
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r1, 0x2]
	ldr r0, [r7, 0x70]
	mov r3, r9
	strh r3, [r0, 0x4]
	ldr r0, [r7, 0x70]
	strb r4, [r0, 0x6]
	mov r0, r9
	bl sub_80687D0
	str r0, [r7, 0x64]
	mov r1, r8
	lsls r0, r1, 4
	adds r0, 0xA0
	adds r1, r7, 0
	adds r1, 0x68
	strh r0, [r1]
	adds r1, 0x2
	movs r0, 0x7
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6C
	strb r5, [r0]
	adds r1, 0x1
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r7, 0
	adds r0, 0x6D
	strb r4, [r0]
	adds r0, 0x2
	strb r4, [r0]
	mov r2, r10
	str r2, [r7, 0x1C]
	ldr r0, [r7, 0x70]
	ldr r3, _08082B38
	adds r0, r3
	mov r4, r8
	strb r4, [r0]
	ldr r0, [r7, 0x70]
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r1
	strb r6, [r0]
	cmp r6, 0
	beq _08082B16
	ldr r3, _08082B3C
	movs r2, 0x1
	adds r1, r6, 0
_08082B06:
	mov r4, r8
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, 0x1
	add r8, r0
	subs r1, 0x1
	cmp r1, 0
	bne _08082B06
_08082B16:
	bl sub_8045ACC
	adds r0, r7, 0
_08082B1C:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08082B2C: .4byte gDungeon
_08082B30: .4byte 0x0001358c
_08082B34: .4byte 0x00000ebc
_08082B38: .4byte 0x00000167
_08082B3C: .4byte gUnknown_202EE76
	thumb_func_end sub_8082A08

	thumb_func_start sub_8082B40
sub_8082B40:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r6, 0
_08082B46:
	ldr r0, _08082BB8
	ldr r0, [r0]
	lsls r1, r6, 2
	ldr r2, _08082BBC
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r5, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08082BA8
	ldr r4, [r5, 0x70]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl sub_80687D0
	str r0, [r5, 0x64]
	adds r0, r5, 0
	bl sub_806CEBC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_806CCB4
	ldr r0, [r5, 0x4]
	str r0, [sp]
	adds r0, r4, 0
	adds r0, 0x98
	ldr r0, [r0]
	movs r2, 0x4
	ldrsh r1, [r4, r2]
	mov r2, sp
	movs r3, 0x3
	bl AddPokemonDungeonSprite
	movs r1, 0x4
	ldrsh r0, [r5, r1]
	movs r2, 0x6
	ldrsh r1, [r5, r2]
	bl GetTileSafe
	ldrb r1, [r0, 0x9]
	adds r0, r5, 0
	adds r0, 0x25
	strb r1, [r0]
_08082BA8:
	adds r6, 0x1
	cmp r6, 0x13
	ble _08082B46
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082BB8: .4byte gDungeon
_08082BBC: .4byte 0x000135cc
	thumb_func_end sub_8082B40

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	thumb_func_start sub_8082BC0
sub_8082BC0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FE0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082BC0

	thumb_func_start sub_8082BE0
sub_8082BE0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082BE0

	thumb_func_start sub_8082BFC
sub_8082BFC:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082BFC

	thumb_func_start sub_8082C18
sub_8082C18:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C18

	thumb_func_start sub_8082C34
sub_8082C34:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C34

	thumb_func_start sub_8082C50
sub_8082C50:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C50

	thumb_func_start sub_8082C6C
sub_8082C6C:
	push {lr}
	sub sp, 0x4
	movs r1, 0
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C6C

	thumb_func_start sub_8082C84
sub_8082C84:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082C84

	thumb_func_start sub_8082CA0
sub_8082CA0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	movs r1, 0
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8082CA0

	thumb_func_start sub_8082CBC
sub_8082CBC:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strh r0, [r4]
	adds r1, r4, 0x2
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	movs r0, 0x7
	strb r0, [r4, 0x3]
	adds r4, 0x14
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082CBC

	thumb_func_start sub_8082CE4
sub_8082CE4:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r5, 0
	bl sub_80831DC
	movs r6, 0
	strb r0, [r4, 0x1]
	adds r0, r5, 0
	bl sub_80831DC
	strb r0, [r4, 0x2]
	adds r0, r5, 0
	bl sub_80831DC
	strb r0, [r4, 0x3]
	adds r0, r5, 0
	bl sub_8083158
	strh r0, [r4, 0x4]
	str r6, [r4, 0x8]
	str r6, [r4, 0xC]
	adds r4, 0x10
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80831F8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8082CE4

	thumb_func_start sub_8082D28
sub_8082D28:
	push {lr}
	movs r2, 0x3
	bl sub_8082FE0
	pop {r0}
	bx r0
	thumb_func_end sub_8082D28

	thumb_func_start sub_8082D34
sub_8082D34:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082D34

	thumb_func_start sub_8082D50
sub_8082D50:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x2]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x3]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082D50

	thumb_func_start sub_8082D7C
sub_8082D7C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x8]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x9]
	adds r0, r4, 0
	bl sub_80831A0
	str r0, [r5, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082D7C

	thumb_func_start sub_8082DA8
sub_8082DA8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082DA8

	thumb_func_start sub_8082DC4
sub_8082DC4:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082DC4

	thumb_func_start sub_8082DE8
sub_8082DE8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082DE8

	thumb_func_start sub_8082E04
sub_8082E04:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_80831DC
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	bl sub_80831DC
	strb r0, [r5, 0x2]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x3]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x4]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E04

	thumb_func_start sub_8082E38
sub_8082E38:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_80831A0
	str r0, [r5, 0x4]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x8]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x9]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0xA]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E38

	thumb_func_start sub_8082E6C
sub_8082E6C:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E6C

	thumb_func_start sub_8082E88
sub_8082E88:
	push {lr}
	movs r2, 0x1
	bl sub_8082FE0
	pop {r0}
	bx r0
	thumb_func_end sub_8082E88

	thumb_func_start sub_8082E94
sub_8082E94:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082E94

	thumb_func_start sub_8082EB0
sub_8082EB0:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082EB0

	thumb_func_start sub_8082ECC
sub_8082ECC:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082ECC

	thumb_func_start sub_8082EE8
sub_8082EE8:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083188
	strb r0, [r5]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	adds r1, r5, 0x2
	adds r0, r4, 0
	movs r2, 0x2
	bl sub_8082FE0
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x4]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082EE8

	thumb_func_start sub_8082F1C
sub_8082F1C:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	adds r4, r7, 0
	movs r5, 0x3
_08082F26:
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_8082EE8
	adds r4, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _08082F26
	adds r0, r6, 0
	bl sub_8083188
	adds r1, r7, 0
	adds r1, 0x20
	strb r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F1C

	thumb_func_start sub_8082F48
sub_8082F48:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083170
	strh r0, [r5]
	adds r0, r4, 0
	bl sub_8083170
	strh r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F48

	thumb_func_start sub_8082F64
sub_8082F64:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083188
	strb r0, [r5]
	adds r0, r4, 0
	bl sub_8083188
	strb r0, [r5, 0x1]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F64

	thumb_func_start sub_8082F80
sub_8082F80:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl sub_8083170
	strh r0, [r5]
	adds r0, r4, 0
	bl sub_8082BFC
	strb r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8082F80

	thumb_func_start sub_8082F9C
sub_8082F9C:
	str r1, [r0]
	movs r3, 0
	str r3, [r0, 0x8]
	adds r1, r2
	str r1, [r0, 0x4]
	bx lr
	thumb_func_end sub_8082F9C

	thumb_func_start sub_8082FA8
sub_8082FA8:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0
	beq _08082FCC
_08082FB2:
	ldr r1, [r3]
	ldrb r0, [r4]
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x1
	str r0, [r3]
	adds r4, 0x1
	subs r2, 0x1
	ldr r0, [r3, 0x8]
	adds r0, 0x1
	str r0, [r3, 0x8]
	cmp r2, 0
	bne _08082FB2
_08082FCC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8082FA8

	thumb_func_start sub_8082FD4
sub_8082FD4:
	str r1, [r0]
	movs r3, 0
	str r3, [r0, 0x8]
	adds r1, r2
	str r1, [r0, 0x4]
	bx lr
	thumb_func_end sub_8082FD4

	thumb_func_start sub_8082FE0
sub_8082FE0:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	cmp r2, 0
	beq _08083002
_08082FEA:
	ldr r1, [r3]
	ldrb r0, [r1]
	strb r0, [r4]
	adds r1, 0x1
	str r1, [r3]
	adds r4, 0x1
	subs r2, 0x1
	ldr r0, [r3, 0x8]
	adds r0, 0x1
	str r0, [r3, 0x8]
	cmp r2, 0
	bne _08082FEA
_08083002:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8082FE0

    .align 2,0
