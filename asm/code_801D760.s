	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

	thumb_func_start sub_801D9E4
sub_801D9E4:
	push {r4,r5,lr}
	ldr r4, _0801DA50
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x84
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801DA54
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r1, 0xE5
	movs r2, 0xA
	bl sub_8013818
	bl sub_801DB54
	bl sub_801DBD4
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801DA50: .4byte gUnknown_203B258
_0801DA54: .4byte gUnknown_80DBF88
	thumb_func_end sub_801D9E4

	thumb_func_start sub_801DA58
sub_801DA58:
	push {lr}
	adds r1, r0, 0
	lsls r1, 16
	asrs r1, 16
	ldr r0, _0801DA74
	ldr r0, [r0]
	bl sub_8013878
	bl sub_801DB54
	bl sub_801DBD4
	pop {r0}
	bx r0
	.align 2, 0
_0801DA74: .4byte gUnknown_203B258
	thumb_func_end sub_801DA58

	thumb_func_start sub_801DA78
sub_801DA78:
	push {r4,lr}
	ldr r4, _0801DA94
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0801DA98
	cmp r0, 0x2
	bne _0801DA9C
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801DAB8
	.align 2, 0
_0801DA94: .4byte gUnknown_203B258
_0801DA98:
	movs r0, 0x3
	b _0801DAB8
_0801DA9C:
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801DAAE
	movs r0, 0
	b _0801DAB8
_0801DAAE:
	bl sub_801DB54
	bl sub_801DBD4
	movs r0, 0x1
_0801DAB8:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801DA78

	thumb_func_start sub_801DAC0
sub_801DAC0:
	ldr r0, _0801DAD8
	ldr r1, [r0]
	ldrh r2, [r1, 0x1E]
	ldrh r0, [r1, 0x1C]
	adds r3, r0, 0
	muls r3, r2
	adds r0, r3, 0
	ldrh r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 16
	asrs r0, 16
	bx lr
	.align 2, 0
_0801DAD8: .4byte gUnknown_203B258
	thumb_func_end sub_801DAC0

	thumb_func_start sub_801DADC
sub_801DADC:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0801DB08
	ldr r0, [r5]
	movs r1, 0xE5
	strh r1, [r0, 0x22]
	bl sub_8013984
	bl sub_801DB54
	bl sub_801DBD4
	cmp r4, 0
	beq _0801DB02
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801DB02:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801DB08: .4byte gUnknown_203B258
	thumb_func_end sub_801DADC

	thumb_func_start sub_801DB0C
sub_801DB0C:
	push {r4,r5,lr}
	ldr r4, _0801DB4C
	ldr r2, [r4]
	cmp r2, 0
	beq _0801DB46
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801DB50
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801DB46:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801DB4C: .4byte gUnknown_203B258
_0801DB50: .4byte gUnknown_80DBF70
	thumb_func_end sub_801DB0C

	thumb_func_start sub_801DB54
sub_801DB54:
	push {r4,lr}
	ldr r4, _0801DBD0
	ldr r0, [r4]
	adds r0, 0x9C
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9D
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0x8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DBD0: .4byte gUnknown_203B258
	thumb_func_end sub_801DB54

	thumb_func_start sub_801DBD4
sub_801DBD4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r5, _0801DCB4
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0801DCB8
	ldr r0, [r5]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r4, [r0]
	lsls r4, 3
	subs r4, 0x2
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r6, 0
	ldr r0, [r5]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _0801DC9C
	adds r7, r5, 0
	mov r8, r6
_0801DC34:
	ldr r0, [r7]
	ldrh r2, [r0, 0x1E]
	ldrh r1, [r0, 0x1C]
	adds r3, r2, 0
	muls r3, r1
	adds r1, r3, 0
	adds r1, r6
	lsls r1, 16
	asrs r1, 16
	lsls r5, r1, 1
	adds r5, r1
	lsls r5, 2
	ldr r1, _0801DCBC
	adds r5, r1
	movs r2, 0x4
	ldrsh r1, [r5, r2]
	lsls r4, r1, 3
	subs r4, r1
	lsls r4, 2
	ldr r1, _0801DCC0
	adds r4, r1
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4]
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x8
	bl xxx_call_draw_string
	ldr r0, [r7]
	adds r1, r6, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r5, 0x8]
	ldr r0, [r7]
	ldr r3, [r0, 0x34]
	mov r0, r8
	str r0, [sp]
	movs r0, 0x3E
	bl xxx_call_draw_string
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0801DC34
_0801DC9C:
	ldr r0, _0801DCB4
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DCB4: .4byte gUnknown_203B258
_0801DCB8: .4byte gUnknown_80DBFA0
_0801DCBC: .4byte gUnknown_811BAF4
_0801DCC0: .4byte gUnknown_81188F0
	thumb_func_end sub_801DBD4

	thumb_func_start sub_801DCC4
sub_801DCC4:
	push {r4,lr}
	ldr r4, _0801DCE4
	movs r0, 0x8E
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r0, 0
	bl sub_801DD6C
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801DCE4: .4byte gUnknown_203B25C
	thumb_func_end sub_801DCC4

	thumb_func_start sub_801DCE8
sub_801DCE8:
	push {lr}
	ldr r0, _0801DD00
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x7
	bhi _0801DD48
	lsls r0, 2
	ldr r1, _0801DD04
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801DD00: .4byte gUnknown_203B25C
_0801DD04: .4byte _0801DD08
	.align 2, 0
_0801DD08:
	.4byte _0801DD2C
	.4byte _0801DD2C
	.4byte _0801DD28
	.4byte _0801DD32
	.4byte _0801DD32
	.4byte _0801DD38
	.4byte _0801DD3E
	.4byte _0801DD44
_0801DD28:
	movs r0, 0x3
	b _0801DD4A
_0801DD2C:
	bl sub_801E028
	b _0801DD48
_0801DD32:
	bl sub_801E088
	b _0801DD48
_0801DD38:
	bl sub_801E0E0
	b _0801DD48
_0801DD3E:
	bl sub_801E0FC
	b _0801DD48
_0801DD44:
	bl sub_801E138
_0801DD48:
	movs r0, 0
_0801DD4A:
	pop {r1}
	bx r1
	thumb_func_end sub_801DCE8

	thumb_func_start sub_801DD50
sub_801DD50:
	push {r4,lr}
	ldr r4, _0801DD68
	ldr r0, [r4]
	cmp r0, 0
	beq _0801DD62
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801DD62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DD68: .4byte gUnknown_203B25C
	thumb_func_end sub_801DD50

	thumb_func_start sub_801DD6C
sub_801DD6C:
	push {lr}
	ldr r1, _0801DD80
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801DD84
	bl sub_801DED0
	pop {r0}
	bx r0
	.align 2, 0
_0801DD80: .4byte gUnknown_203B25C
	thumb_func_end sub_801DD6C

	thumb_func_start sub_801DD84
sub_801DD84:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, _0801DDAC
	ldr r0, [r4]
	adds r0, 0xBC
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0
	beq _0801DDB4
	cmp r0, 0x1
	beq _0801DE38
	movs r3, 0
	adds r7, r4, 0
	ldr r2, _0801DDB0
	b _0801DE90
	.align 2, 0
_0801DDAC: .4byte gUnknown_203B25C
_0801DDB0: .4byte gUnknown_80DBFB0
_0801DDB4:
	bl CreateOthersMenu
	movs r3, 0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xAC
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801DDCE
	ldr r0, [r1, 0x70]
	str r0, [r1, 0x18]
	adds r7, r4, 0
	b _0801DDF2
_0801DDCE:
	adds r3, 0x1
	ldr r7, _0801DE2C
	cmp r3, 0x7
	bgt _0801DDF2
	ldr r2, [r7]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xAC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801DDCE
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x70
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_0801DDF2:
	ldr r0, _0801DE30
	mov r9, r0
	ldr r2, _0801DE2C
	mov r12, r2
	ldr r3, _0801DE34
	mov r8, r3
	movs r2, 0
	movs r3, 0x3
_0801DE02:
	mov r4, r12
	ldr r1, [r4]
	adds r1, r2
	adds r1, 0xBC
	mov r0, r8
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0801DE02
	ldr r1, [r7]
	adds r1, 0xBC
	mov r0, r9
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	b _0801DE70
	.align 2, 0
_0801DE2C: .4byte gUnknown_203B25C
_0801DE30: .4byte gUnknown_80DBFCC
_0801DE34: .4byte gUnknown_80DBFB0
_0801DE38:
	bl CreateOthersMenu
	mov r8, r4
	ldr r6, _0801DE88
	mov r12, r6
	mov r7, r8
	movs r2, 0
	movs r3, 0x3
_0801DE48:
	mov r0, r8
	ldr r1, [r0]
	adds r1, r2
	adds r1, 0xBC
	mov r0, r12
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0801DE48
	ldr r1, [r7]
	adds r1, 0xBC
	ldr r0, _0801DE8C
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
_0801DE70:
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xBC
	adds r1, 0x6C
	bl sub_8012CAC
	ldr r0, [r7]
	adds r0, 0xC8
	movs r1, 0xA
	strh r1, [r0]
	b _0801DEAC
	.align 2, 0
_0801DE88: .4byte gUnknown_80DBFB0
_0801DE8C: .4byte gUnknown_80DBFCC
_0801DE90:
	ldr r0, [r7]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r0, r1
	adds r0, 0xBC
	adds r1, r2, 0
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	ldm r1!, {r4-r6}
	stm r0!, {r4-r6}
	adds r3, 0x1
	cmp r3, 0x3
	ble _0801DE90
_0801DEAC:
	bl ResetUnusedInputStruct
	ldr r0, _0801DECC
	ldr r0, [r0]
	adds r0, 0xBC
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DECC: .4byte gUnknown_203B25C
	thumb_func_end sub_801DD84

	thumb_func_start sub_801DED0
sub_801DED0:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801DEEC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r3, r1, 0
	cmp r0, 0x7
	bhi _0801DF94
	lsls r0, 2
	ldr r1, _0801DEF0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801DEEC: .4byte gUnknown_203B25C
_0801DEF0: .4byte _0801DEF4
	.align 2, 0
_0801DEF4:
	.4byte _0801DF14
	.4byte _0801DF14
	.4byte _0801DF94
	.4byte _0801DF38
	.4byte _0801DF40
	.4byte _0801DF48
	.4byte _0801DF52
	.4byte _0801DF70
_0801DF14:
	ldr r2, [r3]
	ldr r0, _0801DF34
	str r0, [r2, 0x1C]
	adds r0, r2, 0
	adds r0, 0x1C
	adds r1, r2, 0
	adds r1, 0x6C
	adds r3, r2, 0
	adds r3, 0xAC
	ldr r2, [r2, 0x18]
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	bl sub_8012D60
	b _0801DF94
	.align 2, 0
_0801DF34: .4byte gOthers_MenuOption
_0801DF38:
	movs r0, 0
	bl sub_801E3F0
	b _0801DF94
_0801DF40:
	movs r0, 0x1
	bl sub_801E510
	b _0801DF94
_0801DF48:
	ldr r0, [r3]
	ldr r0, [r0, 0x4]
	bl sub_801E658
	b _0801DF94
_0801DF52:
	ldr r1, [r3]
	ldr r0, _0801DF6C
	adds r1, 0x8
	ldr r0, [r0]
	ldm r0!, {r2,r4,r5}
	stm r1!, {r2,r4,r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r3]
	adds r0, 0x8
	bl sub_801E198
	b _0801DF94
	.align 2, 0
_0801DF6C: .4byte gUnknown_203B46C
_0801DF70:
	bl sub_801DFE4
	ldr r0, _0801DF9C
	ldr r1, _0801DFA0
	ldr r3, [r1]
	adds r3, 0x6C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x4
	bl sub_8014248
_0801DF94:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801DF9C: .4byte gUnknown_80DBFEC
_0801DFA0: .4byte gUnknown_203B25C
	thumb_func_end sub_801DED0

	thumb_func_start CreateOthersMenu
CreateOthersMenu:
	push {r4,lr}
	ldr r4, _0801DFD8
	ldr r0, [r4]
	adds r0, 0xAC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	movs r3, 0
	ldr r1, _0801DFDC
	str r1, [r0, 0x6C]
	movs r1, 0x3
	str r1, [r0, 0x70]
	movs r2, 0x1
	ldr r1, _0801DFE0
	str r1, [r0, 0x74]
	movs r1, 0x2
	str r1, [r0, 0x78]
	str r3, [r0, 0x7C]
	adds r0, 0x80
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801DFD8: .4byte gUnknown_203B25C
_0801DFDC: .4byte gOthers_GameOptions
_0801DFE0: .4byte gOthers_Hints
	thumb_func_end CreateOthersMenu

	thumb_func_start sub_801DFE4
sub_801DFE4:
	push {r4,lr}
	ldr r4, _0801E01C
	ldr r0, [r4]
	adds r0, 0xAC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _0801E020
	ldr r0, [r0]
	str r0, [r1, 0x6C]
	movs r0, 0x4
	str r0, [r1, 0x70]
	movs r2, 0x1
	ldr r0, _0801E024
	ldr r0, [r0]
	str r0, [r1, 0x74]
	movs r0, 0x5
	str r0, [r1, 0x78]
	str r3, [r1, 0x7C]
	adds r1, 0x80
	str r2, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E01C: .4byte gUnknown_203B25C
_0801E020: .4byte gUnknown_80D4920
_0801E024: .4byte gUnknown_80D4928
	thumb_func_end sub_801DFE4

	thumb_func_start sub_801E028
sub_801E028:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0801E060
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801E050
	ldr r0, [r4]
	adds r0, 0x1C
	mov r1, sp
	bl sub_8013114
	ldr r1, [r4]
	ldr r0, [sp]
	str r0, [r1, 0x18]
_0801E050:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801E06A
	cmp r0, 0x2
	bgt _0801E064
	cmp r0, 0x1
	beq _0801E07A
	b _0801E080
	.align 2, 0
_0801E060: .4byte gUnknown_203B25C
_0801E064:
	cmp r0, 0x3
	beq _0801E072
	b _0801E080
_0801E06A:
	movs r0, 0x3
	bl sub_801DD6C
	b _0801E080
_0801E072:
	movs r0, 0x6
	bl sub_801DD6C
	b _0801E080
_0801E07A:
	movs r0, 0x2
	bl sub_801DD6C
_0801E080:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E028

	thumb_func_start sub_801E088
sub_801E088:
	push {lr}
	movs r0, 0x1
	bl sub_801E474
	cmp r0, 0x4
	bhi _0801E0DA
	lsls r0, 2
	ldr r1, _0801E0A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801E0A0: .4byte _0801E0A4
	.align 2, 0
_0801E0A4:
	.4byte _0801E0DA
	.4byte _0801E0DA
	.4byte _0801E0D0
	.4byte _0801E0B8
	.4byte _0801E0B8
_0801E0B8:
	bl sub_801E4F4
	ldr r1, _0801E0CC
	ldr r1, [r1]
	str r0, [r1, 0x4]
	movs r0, 0x5
	bl sub_801DD6C
	b _0801E0DA
	.align 2, 0
_0801E0CC: .4byte gUnknown_203B25C
_0801E0D0:
	bl sub_801E54C
	movs r0, 0x1
	bl sub_801DD6C
_0801E0DA:
	pop {r0}
	bx r0
	thumb_func_end sub_801E088

	thumb_func_start sub_801E0E0
sub_801E0E0:
	push {lr}
	bl sub_801E6CC
	cmp r0, 0x1
	bls _0801E0F8
	cmp r0, 0x3
	bhi _0801E0F8
	bl sub_801E724
	movs r0, 0x4
	bl sub_801DD6C
_0801E0F8:
	pop {r0}
	bx r0
	thumb_func_end sub_801E0E0

	thumb_func_start sub_801E0FC
sub_801E0FC:
	push {lr}
	bl sub_801E218
	cmp r0, 0x1
	bls _0801E132
	cmp r0, 0x3
	bhi _0801E132
	bl sub_801E2C4
	ldr r0, _0801E128
	ldr r0, [r0]
	adds r0, 0x8
	bl sub_80949DC
	lsls r0, 24
	cmp r0, 0
	beq _0801E12C
	movs r0, 0x1
	bl sub_801DD6C
	b _0801E132
	.align 2, 0
_0801E128: .4byte gUnknown_203B25C
_0801E12C:
	movs r0, 0x7
	bl sub_801DD6C
_0801E132:
	pop {r0}
	bx r0
	thumb_func_end sub_801E0FC

	thumb_func_start sub_801E138
sub_801E138:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801E18E
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801E15C
	cmp r0, 0x4
	bgt _0801E156
	cmp r0, 0x1
	beq _0801E188
	b _0801E18E
_0801E156:
	cmp r0, 0x5
	beq _0801E188
	b _0801E18E
_0801E15C:
	ldr r1, _0801E180
	ldr r0, _0801E184
	ldr r0, [r0]
	ldr r1, [r1]
	adds r0, 0x8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r0]
	str r0, [r1]
	bl sub_8094C14
	movs r0, 0
	bl sub_8099690
	movs r0, 0x1
	bl sub_801DD6C
	b _0801E18E
	.align 2, 0
_0801E180: .4byte gUnknown_203B46C
_0801E184: .4byte gUnknown_203B25C
_0801E188:
	movs r0, 0x1
	bl sub_801DD6C
_0801E18E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801E138

	thumb_func_start sub_801E198
sub_801E198:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _0801E210
	movs r0, 0xAC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	stm r0!, {r5}
	bl sub_801317C
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x44]
	adds r0, r1, 0
	adds r0, 0x4C
	str r0, [r1, 0x48]
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x44]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x4C
	ldr r0, _0801E214
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldr r0, [r4]
	ldr r0, [r0, 0x48]
	movs r1, 0x1
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x10
	ldr r3, [r1, 0x44]
	movs r1, 0x1
	movs r2, 0x1
	bl sub_8013818
	bl nullsub_38
	bl CreateOptionsMenu
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801E210: .4byte gUnknown_203B260
_0801E214: .4byte gUnknown_80DC03C
	thumb_func_end sub_801E198

	thumb_func_start sub_801E218
sub_801E218:
	push {r4,lr}
	movs r4, 0
	bl sub_8012AE8
	cmp r0, 0x2
	beq _0801E238
	cmp r0, 0x2
	bgt _0801E22E
	cmp r0, 0x1
	beq _0801E242
	b _0801E294
_0801E22E:
	cmp r0, 0x9
	beq _0801E24C
	cmp r0, 0xA
	beq _0801E26C
	b _0801E294
_0801E238:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801E2BE
_0801E242:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801E2BE
_0801E24C:
	ldr r0, _0801E264
	ldr r1, [r0]
	movs r2, 0x28
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0801E294
	ldr r1, [r1]
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	bne _0801E268
	movs r0, 0x2
	b _0801E28A
	.align 2, 0
_0801E264: .4byte gUnknown_203B260
_0801E268:
	subs r0, 0x1
	b _0801E28A
_0801E26C:
	ldr r0, _0801E284
	ldr r1, [r0]
	movs r2, 0x28
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0801E294
	ldr r1, [r1]
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	bls _0801E288
	strb r4, [r1, 0x8]
	b _0801E28C
	.align 2, 0
_0801E284: .4byte gUnknown_203B260
_0801E288:
	adds r0, 0x1
_0801E28A:
	strb r0, [r1, 0x8]
_0801E28C:
	movs r0, 0x3
	bl PlayMenuSoundEffect
	movs r4, 0x1
_0801E294:
	ldr r0, _0801E2B8
	ldr r0, [r0]
	adds r0, 0x10
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801E2AA
	cmp r4, 0x1
	bne _0801E2BC
_0801E2AA:
	bl nullsub_38
	bl CreateOptionsMenu
	movs r0, 0x1
	b _0801E2BE
	.align 2, 0
_0801E2B8: .4byte gUnknown_203B260
_0801E2BC:
	movs r0, 0
_0801E2BE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801E218

	thumb_func_start sub_801E2C4
sub_801E2C4:
	push {r4,r5,lr}
	ldr r4, _0801E304
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E2FE
	ldr r0, [r2, 0x44]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4C
	ldr r0, _0801E308
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E2FE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E304: .4byte gUnknown_203B260
_0801E308: .4byte gUnknown_80DC020
	thumb_func_end sub_801E2C4

	thumb_func_start nullsub_38
nullsub_38:
	bx lr
	thumb_func_end nullsub_38

	thumb_func_start CreateOptionsMenu
CreateOptionsMenu:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, _0801E368
	ldr r0, [r5]
	ldr r0, [r0, 0x44]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x44]
	bl sub_80073B8
	ldr r2, _0801E36C
	ldr r0, [r5]
	ldr r3, [r0, 0x44]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	adds r0, 0x10
	movs r1, 0
	bl sub_8013800
	adds r6, r0, 0
	ldr r2, _0801E370
	ldr r0, [r5]
	ldr r3, [r0, 0x44]
	str r4, [sp]
	movs r0, 0x8
	adds r1, r6, 0
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1
	beq _0801E384
	cmp r0, 0x1
	bgt _0801E374
	cmp r0, 0
	beq _0801E37A
	b _0801E3D6
	.align 2, 0
_0801E368: .4byte gUnknown_203B260
_0801E36C: .4byte gWindowBGTitle
_0801E370: .4byte gUnknown_80DC064
_0801E374:
	cmp r0, 0x2
	beq _0801E3B0
	b _0801E3D6
_0801E37A:
	ldr r0, _0801E380
	b _0801E386
	.align 2, 0
_0801E380: .4byte gWindowBGBlueString
_0801E384:
	ldr r0, _0801E3AC
_0801E386:
	bl sub_8008ED0
	adds r4, r0, 0
	ldr r1, [r5]
	ldr r0, [r1, 0x44]
	ldr r1, [r1]
	ldrb r2, [r1, 0x8]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, 0x50
	adds r2, r6, 0
	adds r2, 0xA
	movs r3, 0x7
	str r3, [sp]
	adds r3, r4, 0
	bl sub_80078A4
	b _0801E3D6
	.align 2, 0
_0801E3AC: .4byte gWindowBGRedString
_0801E3B0:
	ldr r0, _0801E3E8
	bl sub_8008ED0
	adds r4, r0, 0
	ldr r1, [r5]
	ldr r0, [r1, 0x44]
	ldr r1, [r1]
	ldrb r2, [r1, 0x8]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, 0x50
	adds r2, r6, 0
	adds r2, 0xA
	movs r3, 0x7
	str r3, [sp]
	adds r3, r4, 0
	bl sub_80078A4
_0801E3D6:
	ldr r0, _0801E3EC
	ldr r0, [r0]
	ldr r0, [r0, 0x44]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E3E8: .4byte gWindowBGGreenString
_0801E3EC: .4byte gUnknown_203B260
	thumb_func_end CreateOptionsMenu

	thumb_func_start sub_801E3F0
sub_801E3F0:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0801E46C
	ldr r0, [r4]
	cmp r0, 0
	bne _0801E406
	movs r0, 0x9C
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0801E406:
	ldr r0, [r4]
	str r5, [r0, 0x34]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0x3C
	adds r1, r0, r1
	str r1, [r0, 0x38]
	adds r0, 0x3C
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801E470
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r4]
	ldr r0, [r0, 0x38]
	movs r1, 0xA
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x5
	movs r2, 0xA
	adds r3, r5, 0
	bl sub_8013818
	bl sub_801E594
	bl sub_801E5E8
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E46C: .4byte gUnknown_203B264
_0801E470: .4byte gUnknown_80DC0BC
	thumb_func_end sub_801E3F0

	thumb_func_start sub_801E474
sub_801E474:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801E48C
	ldr r0, _0801E488
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0801E4EE
	.align 2, 0
_0801E488: .4byte gUnknown_203B264
_0801E48C:
	ldr r0, _0801E4A4
	ldr r0, [r0]
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801E4AE
	cmp r0, 0x2
	bgt _0801E4A8
	cmp r0, 0x1
	beq _0801E4B8
	b _0801E4CC
	.align 2, 0
_0801E4A4: .4byte gUnknown_203B264
_0801E4A8:
	cmp r0, 0x4
	beq _0801E4C2
	b _0801E4CC
_0801E4AE:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801E4EE
_0801E4B8:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801E4EE
_0801E4C2:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801E4EE
_0801E4CC:
	ldr r0, _0801E4E0
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801E4E4
	movs r0, 0
	b _0801E4EE
	.align 2, 0
_0801E4E0: .4byte gUnknown_203B264
_0801E4E4:
	bl sub_801E594
	bl sub_801E5E8
	movs r0, 0x1
_0801E4EE:
	pop {r1}
	bx r1
	thumb_func_end sub_801E474

	thumb_func_start sub_801E4F4
sub_801E4F4:
	ldr r0, _0801E50C
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r2, 0x18
	ldrsh r1, [r1, r2]
	adds r0, r1
	bx lr
	.align 2, 0
_0801E50C: .4byte gUnknown_203B264
	thumb_func_end sub_801E4F4

	thumb_func_start sub_801E510
sub_801E510:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801E548
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	bl sub_8013984
	bl sub_801E594
	bl sub_801E5E8
	cmp r4, 0
	beq _0801E542
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0801E542:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E548: .4byte gUnknown_203B264
	thumb_func_end sub_801E510

	thumb_func_start sub_801E54C
sub_801E54C:
	push {r4,r5,lr}
	ldr r4, _0801E58C
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E586
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801E590
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E586:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E58C: .4byte gUnknown_203B264
_0801E590: .4byte gUnknown_80DC0A0
	thumb_func_end sub_801E54C

	thumb_func_start sub_801E594
sub_801E594:
	push {r4,lr}
	ldr r4, _0801E5E4
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x34]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x34]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x4C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E5E4: .4byte gUnknown_203B264
	thumb_func_end sub_801E594

	thumb_func_start sub_801E5E8
sub_801E5E8:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r4, _0801E64C
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r2, _0801E650
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	bl xxx_call_draw_string
	movs r5, 0
	adds r6, r4, 0
	ldr r4, _0801E654
_0801E616:
	ldr r0, [r6]
	adds r1, r5, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r2, [r4]
	ldr r0, [r6]
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	bl xxx_call_draw_string
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x4
	ble _0801E616
	ldr r0, _0801E64C
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E64C: .4byte gUnknown_203B264
_0801E650: .4byte gUnknown_80DC0D4
_0801E654: .4byte gUnknown_80DAA98
	thumb_func_end sub_801E5E8

	thumb_func_start sub_801E658
sub_801E658:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0801E6C4
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x34]
	adds r1, r0, 0
	adds r1, 0x3C
	str r1, [r0, 0x38]
	adds r0, r1, 0
	bl sub_8006518
	ldr r1, [r4]
	ldr r2, [r1, 0x34]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x3C
	ldr r0, _0801E6C8
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r0, [r4]
	ldr r1, [r0, 0x38]
	adds r0, 0x9C
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	ldr r3, [r0, 0x34]
	movs r1, 0x5
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	strh r5, [r0, 0x1E]
	bl sub_801E714
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E6C4: .4byte gUnknown_203B268
_0801E6C8: .4byte gUnknown_80DC0FC
	thumb_func_end sub_801E658

	thumb_func_start sub_801E6CC
sub_801E6CC:
	push {r4,lr}
	ldr r4, _0801E6E8
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0801E6EC
	cmp r0, 0x2
	bne _0801E6F6
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801E70C
	.align 2, 0
_0801E6E8: .4byte gUnknown_203B268
_0801E6EC:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801E70C
_0801E6F6:
	ldr r0, [r4]
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	bne _0801E706
	movs r0, 0
	b _0801E70C
_0801E706:
	bl sub_801E714
	movs r0, 0x1
_0801E70C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_801E6CC

	thumb_func_start sub_801E714
sub_801E714:
	push {lr}
	bl sub_801E76C
	bl sub_801E7AC
	pop {r0}
	bx r0
	thumb_func_end sub_801E714

	thumb_func_start sub_801E724
sub_801E724:
	push {r4,r5,lr}
	ldr r4, _0801E764
	ldr r2, [r4]
	cmp r2, 0
	beq _0801E75E
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0801E768
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E75E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E764: .4byte gUnknown_203B268
_0801E768: .4byte gUnknown_80DC0E4
	thumb_func_end sub_801E724

	thumb_func_start sub_801E76C
sub_801E76C:
	push {r4,lr}
	ldr r4, _0801E7A8
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	adds r0, 0x9C
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	adds r0, 0x9D
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9E
	movs r1, 0xF
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E7A8: .4byte gUnknown_203B268
	thumb_func_end sub_801E76C

	thumb_func_start sub_801E7AC
sub_801E7AC:
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, _0801E804
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r3, [r5]
	movs r0, 0x1E
	ldrsh r1, [r3, r0]
	lsls r1, 3
	adds r0, r1, 0
	adds r0, 0x10
	ldr r4, _0801E808
	adds r1, r4
	ldr r2, [r1]
	ldr r3, [r3, 0x34]
	movs r6, 0
	str r6, [sp]
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r5]
	movs r2, 0x1E
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r4, 0x4
	adds r0, r4
	ldr r2, [r0]
	ldr r3, [r1, 0x34]
	str r6, [sp]
	movs r0, 0xA
	movs r1, 0x14
	bl xxx_call_draw_string
	ldr r0, [r5]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E804: .4byte gUnknown_203B268
_0801E808: .4byte gUnknown_80DAA98
	thumb_func_end sub_801E7AC

	thumb_func_start DisplayGulpinDialogueSprite
DisplayGulpinDialogueSprite:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	asrs r4, 16
	ldr r5, _0801E84C
	movs r0, 0xC6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	adds r2, r0, 0
	str r2, [r5]
	mov r0, r8
	str r0, [r2]
	strh r4, [r2, 0xC]
	str r6, [r2, 0x10]
	ldrh r0, [r6, 0x22]
	strh r0, [r2, 0x1C]
	mov r1, r8
	cmp r1, 0
	bne _0801E850
	movs r3, 0x94
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0x8C
	lsls r4, 1
	adds r0, r2, r4
	b _0801E858
	.align 2, 0
_0801E84C: .4byte gUnknown_203B26C
_0801E850:
	movs r0, 0x94
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0
_0801E858:
	str r0, [r1]
	ldr r0, _0801E8B4
	bl GetDialogueSpriteDataPtr
	ldr r2, _0801E8B8
	ldr r3, [r2]
	movs r4, 0x8C
	lsls r4, 1
	adds r1, r3, r4
	str r0, [r1]
	adds r4, 0x4
	adds r1, r3, r4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r1, 0x92
	lsls r1, 1
	adds r0, r3, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _0801E8BC
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, 0xA
	adds r0, r4
	strb r1, [r0]
	ldr r2, [r2]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x3
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_801E968
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801E8B4: .4byte 0x00000155
_0801E8B8: .4byte gUnknown_203B26C
_0801E8BC: .4byte 0x00000125
	thumb_func_end DisplayGulpinDialogueSprite

	thumb_func_start sub_801E8C0
sub_801E8C0:
	push {lr}
	ldr r0, _0801E8D8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x6
	bhi _0801E928
	lsls r0, 2
	ldr r1, _0801E8DC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801E8D8: .4byte gUnknown_203B26C
_0801E8DC: .4byte _0801E8E0
	.align 2, 0
_0801E8E0:
	.4byte _0801E8FC
	.4byte _0801E8FC
	.4byte _0801E902
	.4byte _0801E908
	.4byte _0801E90E
	.4byte _0801E91C
	.4byte _0801E924
_0801E8FC:
	bl sub_801ECBC
	b _0801E928
_0801E902:
	bl sub_801ED28
	b _0801E928
_0801E908:
	bl sub_801EDA4
	b _0801E928
_0801E90E:
	bl sub_801EDC0
	ldr r0, _0801E920
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x5
	bne _0801E928
_0801E91C:
	movs r0, 0x3
	b _0801E92A
	.align 2, 0
_0801E920: .4byte gUnknown_203B26C
_0801E924:
	movs r0, 0x2
	b _0801E92A
_0801E928:
	movs r0, 0
_0801E92A:
	pop {r1}
	bx r1
	thumb_func_end sub_801E8C0

	thumb_func_start sub_801E930
sub_801E930:
	ldr r0, _0801E938
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	bx lr
	.align 2, 0
_0801E938: .4byte gUnknown_203B26C
	thumb_func_end sub_801E930

	thumb_func_start sub_801E93C
sub_801E93C:
	push {r4,lr}
	ldr r4, _0801E964
	ldr r0, [r4]
	cmp r0, 0
	beq _0801E95C
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801E95C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801E964: .4byte gUnknown_203B26C
	thumb_func_end sub_801E93C

	thumb_func_start sub_801E968
sub_801E968:
	push {lr}
	ldr r1, _0801E97C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801E980
	bl sub_801EA28
	pop {r0}
	bx r0
	.align 2, 0
_0801E97C: .4byte gUnknown_203B26C
	thumb_func_end sub_801E968

	thumb_func_start sub_801E980
sub_801E980:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0801E9D0
	ldr r0, [r4]
	movs r5, 0x96
	lsls r5, 1
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	cmp r0, 0x2
	bne _0801E9DC
	bl sub_801EBC4
	ldr r1, [r4]
	movs r0, 0xA2
	lsls r0, 1
	adds r1, r0
	ldr r0, _0801E9D4
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	ldr r2, [r4]
	movs r0, 0xAE
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801E9D8
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x28
	bl sub_8012CAC
	b _0801EA00
	.align 2, 0
_0801E9D0: .4byte gUnknown_203B26C
_0801E9D4: .4byte gUnknown_80DC11C
_0801E9D8: .4byte gUnknown_80DC134
_0801E9DC:
	mov r12, r4
	mov r8, r5
	ldr r4, _0801EA20
	movs r2, 0
	movs r3, 0x3
_0801E9E6:
	mov r6, r12
	ldr r1, [r6]
	adds r1, r2
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r2, 0x18
	subs r3, 0x1
	cmp r3, 0
	bge _0801E9E6
_0801EA00:
	bl ResetUnusedInputStruct
	ldr r0, _0801EA24
	ldr r0, [r0]
	movs r7, 0x96
	lsls r7, 1
	adds r0, r7
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801EA20: .4byte gUnknown_80DC11C
_0801EA24: .4byte gUnknown_203B26C
	thumb_func_end sub_801E980

	thumb_func_start sub_801EA28
sub_801EA28:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801EA44
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x4
	bls _0801EA3A
	b _0801EBB8
_0801EA3A:
	lsls r0, 2
	ldr r1, _0801EA48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EA44: .4byte gUnknown_203B26C
_0801EA48: .4byte _0801EA4C
	.align 2, 0
_0801EA4C:
	.4byte _0801EA60
	.4byte _0801EA80
	.4byte _0801EA8A
	.4byte _0801EAB4
	.4byte _0801EACA
_0801EA60:
	ldr r0, [r4]
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	ldr r2, [r0, 0x10]
	ldr r0, _0801EA7C
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r3, 0
	bl sub_801EE10
	b _0801EBB8
	.align 2, 0
_0801EA7C: .4byte gUnknown_80DC164
_0801EA80:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _0801EBB8
_0801EA8A:
	movs r0, 0
	bl sub_801F280
	ldr r0, _0801EAB0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	adds r1, r2, 0
	adds r1, 0x28
	adds r3, r2, 0
	adds r3, 0x68
	ldr r2, [r2, 0x24]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0801EBB8
	.align 2, 0
_0801EAB0: .4byte gUnknown_203B26C
_0801EAB4:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	adds r2, 0x14
	bl sub_8093560
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_801F808
	b _0801EBB8
_0801EACA:
	bl sub_801EC7C
	ldr r4, _0801EAF8
	ldr r5, _0801EAFC
	ldr r0, [r5]
	ldrh r1, [r0, 0x1C]
	adds r0, r4, 0
	bl sub_8092C84
	adds r4, 0x50
	ldr r0, [r5]
	ldrh r1, [r0, 0x1E]
	adds r0, r4, 0
	bl sub_8092C84
	ldr r2, [r5]
	ldr r3, [r2]
	cmp r3, 0x1
	bls _0801EB00
	cmp r3, 0x2
	beq _0801EB68
	b _0801EBB8
	.align 2, 0
_0801EAF8: .4byte gAvailablePokemonNames
_0801EAFC: .4byte gUnknown_203B26C
_0801EB00:
	ldrb r4, [r2, 0xE]
	cmp r4, 0
	beq _0801EB38
	ldr r1, _0801EB34
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x30
	adds r0, r1
	ldr r0, [r0]
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r4, 0x94
	lsls r4, 1
	adds r1, r2, r4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	b _0801EB86
	.align 2, 0
_0801EB34: .4byte gGulpinDialogue
_0801EB38:
	ldr r1, _0801EB64
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x2C
	adds r0, r1
	ldr r0, [r0]
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	movs r4, 0x94
	lsls r4, 1
	adds r1, r2, r4
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	b _0801EB86
	.align 2, 0
_0801EB64: .4byte gGulpinDialogue
_0801EB68:
	ldrb r4, [r2, 0xE]
	cmp r4, 0
	beq _0801EB98
	ldr r0, _0801EB94
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r1, 0x20
_0801EB86:
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _0801EBB8
	.align 2, 0
_0801EB94: .4byte gUnknown_80DC1A0
_0801EB98:
	ldr r0, _0801EBC0
	adds r3, r2, 0
	adds r3, 0x28
	adds r1, r2, 0
	adds r1, 0x68
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r1, 0x20
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
_0801EBB8:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801EBC0: .4byte gUnknown_80DC1FC
	thumb_func_end sub_801EA28

	thumb_func_start sub_801EBC4
sub_801EBC4:
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, _0801EC48
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, _0801EC4C
	str r0, [r1, 0x28]
	movs r0, 0x2
	str r0, [r1, 0x2C]
	ldrh r0, [r1, 0x1E]
	ldr r1, [r1, 0x10]
	bl sub_80933A0
	lsls r0, 24
	cmp r0, 0
	beq _0801EBF6
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	cmp r0, 0x3
	ble _0801EBFE
_0801EBF6:
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0x1
	strh r1, [r0]
_0801EBFE:
	adds r5, 0x1
	ldr r4, _0801EC48
	ldr r0, [r4]
	mov r12, r0
	lsls r1, r5, 3
	mov r3, r12
	adds r3, 0x28
	adds r2, r3, r1
	ldr r0, _0801EC50
	ldr r0, [r0]
	str r0, [r2]
	mov r2, r12
	adds r2, 0x2C
	adds r1, r2, r1
	movs r0, 0x3
	str r0, [r1]
	adds r5, 0x1
	lsls r1, r5, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r2, r1
	movs r0, 0x1
	str r0, [r2]
	movs r3, 0
	cmp r3, r5
	bge _0801EC76
	mov r0, r12
	adds r0, 0x68
	ldrh r0, [r0]
	cmp r0, 0
	bne _0801EC54
	mov r1, r12
	ldr r0, [r1, 0x2C]
	str r0, [r1, 0x24]
	b _0801EC76
	.align 2, 0
_0801EC48: .4byte gUnknown_203B26C
_0801EC4C: .4byte gUnknown_80DC230
_0801EC50: .4byte gUnknown_80D4970
_0801EC54:
	adds r3, 0x1
	cmp r3, r5
	bge _0801EC76
	ldr r2, [r4]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x68
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0801EC54
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x2C
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x24]
_0801EC76:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_801EBC4

	thumb_func_start sub_801EC7C
sub_801EC7C:
	push {r4,lr}
	ldr r4, _0801ECB0
	ldr r0, [r4]
	adds r0, 0x68
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _0801ECB4
	ldr r0, [r0]
	str r0, [r1, 0x28]
	movs r0, 0x4
	str r0, [r1, 0x2C]
	movs r2, 0x1
	ldr r0, _0801ECB8
	ldr r0, [r0]
	str r0, [r1, 0x30]
	movs r0, 0x5
	str r0, [r1, 0x34]
	str r3, [r1, 0x38]
	str r2, [r1, 0x3C]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801ECB0: .4byte gUnknown_203B26C
_0801ECB4: .4byte gUnknown_80D4920
_0801ECB8: .4byte gUnknown_80D4928
	thumb_func_end sub_801EC7C

	thumb_func_start sub_801ECBC
sub_801ECBC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x3
	beq _0801ECD8
	cmp r0, 0x3
	bhi _0801ECD2
	cmp r0, 0x2
	beq _0801ED18
	b _0801ED22
_0801ECD2:
	cmp r0, 0x4
	beq _0801ECF8
	b _0801ED22
_0801ECD8:
	bl sub_801F194
	ldr r1, _0801ECF4
	ldr r2, [r1]
	str r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x1E]
	movs r0, 0x2
	bl sub_801E968
	b _0801ED22
	.align 2, 0
_0801ECF4: .4byte gUnknown_203B26C
_0801ECF8:
	bl sub_801F194
	ldr r1, _0801ED14
	ldr r2, [r1]
	str r0, [r2, 0x20]
	ldr r1, [r2, 0x10]
	lsls r0, 3
	adds r1, r0
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x1E]
	movs r0, 0x3
	bl sub_801E968
	b _0801ED22
	.align 2, 0
_0801ED14: .4byte gUnknown_203B26C
_0801ED18:
	bl sub_801F214
	movs r0, 0x6
	bl sub_801E968
_0801ED22:
	pop {r0}
	bx r0
	thumb_func_end sub_801ECBC

	thumb_func_start sub_801ED28
sub_801ED28:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801EF38
	ldr r4, _0801ED60
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801ED4E
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
_0801ED4E:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801ED74
	cmp r0, 0x2
	bgt _0801ED64
	cmp r0, 0x1
	beq _0801ED6C
	b _0801ED9A
	.align 2, 0
_0801ED60: .4byte gUnknown_203B26C
_0801ED64:
	cmp r0, 0x3
	beq _0801ED94
	cmp r0, 0x5
	bne _0801ED9A
_0801ED6C:
	movs r0, 0x1
	bl sub_801E968
	b _0801ED9A
_0801ED74:
	ldr r0, _0801ED90
	bl sub_8011988
	ldr r1, [r4]
	ldr r0, [r1, 0x20]
	ldr r1, [r1, 0x10]
	bl sub_80934B0
	ldr r1, [r4]
	strb r0, [r1, 0xE]
	movs r0, 0x4
	bl sub_801E968
	b _0801ED9A
	.align 2, 0
_0801ED90: .4byte 0x00000133
_0801ED94:
	movs r0, 0x3
	bl sub_801E968
_0801ED9A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801ED28

	thumb_func_start sub_801EDA4
sub_801EDA4:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _0801EDBC
	cmp r0, 0x3
	bhi _0801EDBC
	bl sub_801F8D0
	movs r0, 0x1
	bl sub_801E968
_0801EDBC:
	pop {r0}
	bx r0
	thumb_func_end sub_801EDA4

	thumb_func_start sub_801EDC0
sub_801EDC0:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801EE06
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801EDE4
	cmp r0, 0x4
	bgt _0801EDDE
	cmp r0, 0x1
	beq _0801EE00
	b _0801EE06
_0801EDDE:
	cmp r0, 0x5
	beq _0801EE00
	b _0801EE06
_0801EDE4:
	bl sub_801F214
	ldr r4, _0801EDFC
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	ldr r1, [r1, 0x20]
	bl sub_8093CF8
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x4]
	b _0801EE06
	.align 2, 0
_0801EDFC: .4byte gUnknown_203B26C
_0801EE00:
	movs r0, 0x1
	bl sub_801E968
_0801EE06:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801EDC0

	thumb_func_start sub_801EE10
sub_801EE10:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	mov r9, r2
	adds r4, r3, 0
	ldr r0, [sp, 0x20]
	mov r8, r0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r4, 24
	lsrs r4, 24
	ldr r5, _0801EF28
	movs r0, 0xBC
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r2, 0
	strb r4, [r0, 0x4]
	ldr r0, [r5]
	movs r1, 0x1
	strb r1, [r0, 0x5]
	ldr r0, [r5]
	strb r1, [r0, 0x6]
	ldr r0, [r5]
	strb r1, [r0, 0x7]
	ldr r0, [r5]
	str r6, [r0]
	cmp r6, 0x1
	bls _0801EE5E
	cmp r6, 0x3
	bhi _0801EE5E
	strb r2, [r0, 0x5]
	ldr r0, [r5]
	strb r2, [r0, 0x6]
	ldr r0, [r5]
	strb r2, [r0, 0x7]
_0801EE5E:
	ldr r4, _0801EF28
	ldr r3, [r4]
	ldr r2, _0801EF2C
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	str r0, [r3, 0x8]
	ldrb r0, [r0, 0x2]
	strb r0, [r3, 0xC]
	ldr r0, [r4]
	mov r1, r9
	str r1, [r0, 0x10]
	adds r0, 0xB8
	ldr r1, [sp, 0x1C]
	str r1, [r0]
	bl sub_801F3F8
	adds r5, r0, 0
	adds r6, r5, 0
	cmp r5, 0x4
	bge _0801EE8E
	movs r6, 0x4
_0801EE8E:
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8006518
	ldr r1, [r4]
	mov r2, r8
	str r2, [r1, 0x50]
	lsls r0, r2, 1
	add r0, r8
	lsls r0, 3
	adds r1, r0
	adds r1, 0x58
	ldr r0, _0801EF30
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r0, [r4]
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801EED8
	mov r0, r8
	bl sub_8006544
	ldr r1, [r4]
	str r0, [r1, 0x54]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 3
	adds r1, r2
	adds r1, 0x58
	ldr r0, _0801EF34
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
_0801EED8:
	ldr r0, [r4]
	ldr r2, [r0, 0x50]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, 0x58
	adds r0, r1
	adds r1, r6, 0
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, 0x1C
	adds r1, r5, 0
	adds r2, r5, 0
	mov r3, r8
	bl sub_8013818
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	bl sub_8013780
	movs r0, 0x1
	bl sub_801F280
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801EF28: .4byte gUnknown_203B270
_0801EF2C: .4byte gUnknown_203B45C
_0801EF30: .4byte gUnknown_80DC25C
_0801EF34: .4byte gUnknown_80DC274
	thumb_func_end sub_801EE10

	thumb_func_start sub_801EF38
sub_801EF38:
	push {r4-r7,lr}
	lsls r0, 24
	movs r7, 0
	cmp r0, 0
	bne _0801EF54
	ldr r0, _0801EF50
	ldr r0, [r0]
	adds r0, 0x1C
	bl sub_8013660
	b _0801F18C
	.align 2, 0
_0801EF50: .4byte gUnknown_203B270
_0801EF54:
	ldr r0, _0801EF70
	ldr r0, [r0]
	adds r0, 0x1C
	bl GetKeyPress
	subs r0, 0x1
	cmp r0, 0xC
	bls _0801EF66
	b _0801F12E
_0801EF66:
	lsls r0, 2
	ldr r1, _0801EF74
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EF70: .4byte gUnknown_203B270
_0801EF74: .4byte _0801EF78
	.align 2, 0
_0801EF78:
	.4byte _0801EFB6
	.4byte _0801EFAC
	.4byte _0801F0E4
	.4byte _0801EFC0
	.4byte _0801F12E
	.4byte _0801F12E
	.4byte _0801EFE4
	.4byte _0801EFCA
	.4byte _0801F12E
	.4byte _0801F12E
	.4byte _0801F074
	.4byte _0801F04C
	.4byte _0801F018
_0801EFAC:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801F18E
_0801EFB6:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801F18E
_0801EFC0:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801F18E
_0801EFCA:
	ldr r5, _0801EFE0
	ldr r0, [r5]
	movs r1, 0x34
	ldrsh r6, [r0, r1]
	adds r4, r0, 0
	adds r4, 0x1C
	ldr r0, [r0, 0x10]
	adds r1, r6, 0
	bl sub_8092E54
	b _0801EFF8
	.align 2, 0
_0801EFE0: .4byte gUnknown_203B270
_0801EFE4:
	ldr r5, _0801F014
	ldr r0, [r5]
	movs r1, 0x34
	ldrsh r6, [r0, r1]
	adds r4, r0, 0
	adds r4, 0x1C
	ldr r0, [r0, 0x10]
	adds r1, r6, 0
	bl sub_8092EEC
_0801EFF8:
	adds r1, r0, 0
	adds r0, r4, 0
	bl sub_8013780
	ldr r0, [r5]
	movs r2, 0x34
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bne _0801F00C
	b _0801F12E
_0801F00C:
	movs r0, 0x3
	bl PlayMenuSoundEffect
	b _0801F12E
	.align 2, 0
_0801F014: .4byte gUnknown_203B270
_0801F018:
	ldr r0, _0801F048
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	adds r5, r0, 0
	cmp r1, 0
	bne _0801F026
	b _0801F12E
_0801F026:
	movs r0, 0x34
	ldrsh r4, [r2, r0]
	ldr r0, [r2, 0x10]
	adds r1, r4, 0
	bl sub_809309C
_0801F032:
	ldr r1, [r5]
	strh r0, [r1, 0x34]
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	beq _0801F06C
	movs r0, 0x3
	bl PlayMenuSoundEffect
	b _0801F182
	.align 2, 0
_0801F048: .4byte gUnknown_203B270
_0801F04C:
	ldr r0, _0801F068
	ldr r2, [r0]
	ldrb r1, [r2, 0x5]
	adds r5, r0, 0
	cmp r1, 0
	beq _0801F12E
	movs r1, 0x34
	ldrsh r4, [r2, r1]
	ldr r0, [r2, 0x10]
	adds r1, r4, 0
	bl sub_809324C
	b _0801F032
	.align 2, 0
_0801F068: .4byte gUnknown_203B270
_0801F06C:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801F182
_0801F074:
	ldr r0, _0801F0C8
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	adds r5, r0, 0
	cmp r1, 0
	beq _0801F12E
	ldr r0, _0801F0CC
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x95
	ble _0801F0D0
	movs r1, 0x34
	ldrsh r0, [r2, r1]
	ldr r1, [r2, 0x10]
	bl sub_8093318
	lsls r0, 24
	cmp r0, 0
	beq _0801F0D0
	ldr r1, [r5]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093400
	movs r0, 0x6
	bl PlayMenuSoundEffect
	movs r7, 0x1
	ldr r1, [r5]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _0801F12E
	strb r7, [r1, 0x4]
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	b _0801F12E
	.align 2, 0
_0801F0C8: .4byte gUnknown_203B270
_0801F0CC: .4byte gUnknown_203B460
_0801F0D0:
	ldr r0, _0801F0E0
	ldr r1, [r0]
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093468
	b _0801F0FE
	.align 2, 0
_0801F0E0: .4byte gUnknown_203B270
_0801F0E4:
	ldr r0, _0801F10C
	ldr r1, [r0]
	ldrb r0, [r1, 0x7]
	cmp r0, 0
	beq _0801F12E
	ldrb r0, [r1, 0xC]
	cmp r0, 0
	beq _0801F110
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_80934DC
_0801F0FE:
	lsls r0, 24
	cmp r0, 0
	bne _0801F120
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801F12E
	.align 2, 0
_0801F10C: .4byte gUnknown_203B270
_0801F110:
	movs r2, 0x34
	ldrsh r0, [r1, r2]
	ldr r1, [r1, 0x10]
	bl sub_8093544
	lsls r0, 24
	cmp r0, 0
	beq _0801F128
_0801F120:
	movs r0, 0x6
	bl PlayMenuSoundEffect
	b _0801F182
_0801F128:
	movs r0, 0x2
	bl PlayMenuSoundEffect
_0801F12E:
	cmp r7, 0
	bne _0801F182
	movs r3, 0
	ldr r5, _0801F160
	movs r4, 0x1
_0801F138:
	ldr r2, [r5]
	lsls r0, r3, 3
	ldr r1, [r2, 0x10]
	adds r1, r0
	ldrb r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0801F16C
	movs r0, 0x2
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0801F164
	adds r0, r2, 0
	adds r0, 0x14
	adds r0, r3
	strb r4, [r0]
	b _0801F16C
	.align 2, 0
_0801F160: .4byte gUnknown_203B270
_0801F164:
	adds r0, r2, 0
	adds r0, 0x14
	adds r0, r3
	strb r1, [r0]
_0801F16C:
	adds r3, 0x1
	cmp r3, 0x7
	ble _0801F138
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x1C
	adds r1, 0x14
	bl AddMenuCursorSprite_
	cmp r7, 0
	beq _0801F18C
_0801F182:
	movs r0, 0x1
	bl sub_801F280
	movs r0, 0x1
	b _0801F18E
_0801F18C:
	movs r0, 0
_0801F18E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801EF38

	thumb_func_start sub_801F194
sub_801F194:
	ldr r0, _0801F1A0
	ldr r0, [r0]
	movs r1, 0x34
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0801F1A0: .4byte gUnknown_203B270
	thumb_func_end sub_801F194

	thumb_func_start sub_801F1A4
sub_801F1A4:
	ldr r0, _0801F1AC
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	bx lr
	.align 2, 0
_0801F1AC: .4byte gUnknown_203B270
	thumb_func_end sub_801F1A4

	thumb_func_start sub_801F1B0
sub_801F1B0:
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r4, _0801F210
	ldr r2, [r4]
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	bne _0801F1C6
	strb r1, [r2, 0x4]
_0801F1C6:
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	bl sub_801F3F8
	adds r1, r0, 0
	ldr r0, [r4]
	strh r1, [r0, 0x3E]
	adds r0, 0x1C
	bl sub_8013984
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	movs r2, 0x34
	ldrsh r1, [r1, r2]
	bl sub_8092F4C
	ldr r1, [r4]
	strh r0, [r1, 0x34]
	movs r0, 0x1
	bl sub_801F280
	cmp r5, 0
	beq _0801F208
	ldr r0, [r4]
	adds r0, 0x1C
	bl AddMenuCursorSprite
_0801F208:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F210: .4byte gUnknown_203B270
	thumb_func_end sub_801F1B0

	thumb_func_start sub_801F214
sub_801F214:
	push {r4-r6,lr}
	ldr r4, _0801F278
	ldr r2, [r4]
	cmp r2, 0
	beq _0801F272
	ldr r0, [r2, 0x50]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	ldr r3, _0801F27C
	adds r1, 0x58
	adds r0, r3, 0
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldm r0!, {r2,r5,r6}
	stm r1!, {r2,r5,r6}
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801F258
	ldr r0, [r2, 0x54]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x58
	adds r0, r3, 0
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
_0801F258:
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x58
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801F272:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F278: .4byte gUnknown_203B270
_0801F27C: .4byte gUnknown_80DC240
	thumb_func_end sub_801F214

	thumb_func_start sub_801F280
sub_801F280:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, _0801F30C
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r1, [r0, 0x8]
	adds r1, 0x4C
	add r0, sp, 0x4
	movs r2, 0xA
	bl sub_80922B4
	ldr r0, _0801F310
	add r1, sp, 0x4
	bl strcpy
	ldr r2, _0801F314
	ldr r0, [r4]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	movs r1, 0
	bl sub_8014FF0
	movs r7, 0
	ldr r0, [r4]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _0801F394
	add r5, sp, 0x18
	mov r8, r4
	movs r0, 0x1
	mov r9, r0
_0801F2E0:
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xC
	bl memset
	movs r0, 0x6A
	str r0, [r5, 0x4]
	mov r1, r8
	ldr r2, [r1]
	lsls r1, r7, 3
	ldr r0, [r2, 0x10]
	adds r4, r0, r1
	ldrb r1, [r4]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	beq _0801F386
	ldrb r0, [r2, 0xC]
	cmp r0, 0
	beq _0801F318
	movs r0, 0x2
	b _0801F31A
	.align 2, 0
_0801F30C: .4byte gUnknown_203B270
_0801F310: .4byte gAvailablePokemonNames
_0801F314: .4byte gUnknown_80DC28C
_0801F318:
	movs r0, 0x4
_0801F31A:
	str r0, [sp, 0x18]
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x6]
	cmp r0, 0
	beq _0801F328
	mov r0, r9
_0801F328:
	strb r0, [r5, 0x9]
	cmp r7, 0x3
	ble _0801F332
	mov r1, r9
	strb r1, [r5, 0x8]
_0801F332:
	ldr r0, _0801F3EC
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80928A0
	ldr r2, _0801F3F0
	ldr r0, [r2]
	adds r0, 0x1C
	adds r1, r7, 0
	str r2, [sp, 0x24]
	bl sub_8013800
	adds r6, r0, 0
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	movs r4, 0xD
	ldr r2, [sp, 0x24]
	cmp r0, 0
	bne _0801F372
	movs r4, 0x8
	cmp r7, 0
	beq _0801F372
	ldr r0, [r2]
	ldr r0, [r0, 0x50]
	subs r2, r6, 0x2
	movs r1, 0x7
	str r1, [sp]
	movs r1, 0xC
	movs r3, 0x78
	bl sub_800792C
_0801F372:
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x50]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r6, 0
	ldr r2, _0801F3F4
	bl sub_8014FF0
_0801F386:
	adds r7, 0x1
	mov r1, r8
	ldr r0, [r1]
	movs r1, 0x36
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _0801F2E0
_0801F394:
	ldr r4, _0801F3F0
	ldr r0, [r4]
	ldr r0, [r0, 0x50]
	bl sub_80073E0
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r0, [r0]
	cmp r0, 0
	beq _0801F3DC
	mov r0, r10
	cmp r0, 0
	beq _0801F3DC
	ldr r0, [r1, 0x54]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073B8
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xB8
	ldr r2, [r0]
	ldr r3, [r1, 0x54]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0
	bl sub_8014FF0
	ldr r0, [r4]
	ldr r0, [r0, 0x54]
	bl sub_80073E0
_0801F3DC:
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F3EC: .4byte gUnknown_202DE58
_0801F3F0: .4byte gUnknown_203B270
_0801F3F4: .4byte gUnknown_80DC2A0
	thumb_func_end sub_801F280

	thumb_func_start sub_801F3F8
sub_801F3F8:
	push {r4,r5,lr}
	movs r4, 0
	ldr r0, _0801F424
	ldr r0, [r0]
	movs r5, 0x1
	ldr r2, [r0, 0x10]
	movs r3, 0x7
_0801F406:
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0801F412
	adds r4, 0x1
_0801F412:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _0801F406
	adds r0, r4, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801F424: .4byte gUnknown_203B270
	thumb_func_end sub_801F3F8

	thumb_func_start sub_801F428
sub_801F428:
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	mov r9, r1
	lsls r4, 16
	asrs r4, 16
	ldr r5, _0801F50C
	movs r0, 0xFA
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	ldr r3, _0801F510
	movs r1, 0x58
	adds r2, r4, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0]
	adds r1, r0, 0
	adds r1, 0x8
	str r1, [r0, 0x4]
	movs r4, 0xDF
	lsls r4, 2
	adds r1, r0, r4
	mov r2, r9
	str r2, [r1]
	movs r6, 0xE0
	lsls r6, 2
	adds r2, r0, r6
	mov r3, r9
	lsls r1, r3, 1
	add r1, r9
	lsls r1, 3
	movs r3, 0xE1
	lsls r3, 2
	mov r8, r3
	add r1, r8
	adds r1, r0, r1
	str r1, [r2]
	add r0, r8
	bl sub_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	add r1, r8
	ldr r0, _0801F514
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r1, [r5]
	adds r6, r1, r6
	ldr r0, [r6]
	movs r4, 0xF9
	lsls r4, 2
	adds r1, r4
	str r1, [r0, 0x14]
	movs r2, 0
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0801F518
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r3, _0801F51C
	adds r0, r3
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r5]
	adds r4, 0x3
	adds r0, r4
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	add r0, r8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	movs r0, 0xD2
	lsls r0, 2
	adds r4, r0
	bl sub_801F7E4
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x4
	mov r3, r9
	bl sub_8013818
	bl sub_801F690
	bl sub_801F700
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801F50C: .4byte gUnknown_203B274
_0801F510: .4byte gUnknown_203B45C
_0801F514: .4byte gUnknown_80DC2C4
_0801F518: .4byte 0x000003e5
_0801F51C: .4byte 0x000003e6
	thumb_func_end sub_801F428

	thumb_func_start sub_801F520
sub_801F520:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801F540
	ldr r0, _0801F53C
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _0801F5AE
	.align 2, 0
_0801F53C: .4byte gUnknown_203B274
_0801F540:
	ldr r0, _0801F55C
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801F566
	cmp r0, 0x2
	bgt _0801F560
	cmp r0, 0x1
	beq _0801F570
	b _0801F584
	.align 2, 0
_0801F55C: .4byte gUnknown_203B274
_0801F560:
	cmp r0, 0x4
	beq _0801F57A
	b _0801F584
_0801F566:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801F5AE
_0801F570:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801F5AE
_0801F57A:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801F5AE
_0801F584:
	ldr r0, _0801F5A0
	ldr r0, [r0]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801F5A4
	movs r0, 0
	b _0801F5AE
	.align 2, 0
_0801F5A0: .4byte gUnknown_203B274
_0801F5A4:
	bl sub_801F690
	bl sub_801F700
	movs r0, 0x1
_0801F5AE:
	pop {r1}
	bx r1
	thumb_func_end sub_801F520

	thumb_func_start sub_801F5B4
sub_801F5B4:
	push {r4,lr}
	ldr r0, _0801F5E8
	ldr r1, [r0]
	ldr r2, [r1, 0x4]
	ldr r3, _0801F5EC
	adds r0, r1, r3
	movs r4, 0
	ldrsh r3, [r0, r4]
	movs r4, 0xD9
	lsls r4, 2
	adds r0, r1, r4
	movs r4, 0
	ldrsh r0, [r0, r4]
	muls r0, r3
	movs r3, 0xD8
	lsls r3, 2
	adds r1, r3
	movs r4, 0
	ldrsh r1, [r1, r4]
	adds r0, r1
	lsls r0, 1
	adds r2, r0
	ldrh r0, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801F5E8: .4byte gUnknown_203B274
_0801F5EC: .4byte 0x00000366
	thumb_func_end sub_801F5B4

	thumb_func_start sub_801F5F0
sub_801F5F0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801F638
	ldr r0, [r5]
	movs r1, 0xE1
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_801F690
	bl sub_801F700
	cmp r4, 0
	beq _0801F632
	ldr r0, [r5]
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r1
	bl AddMenuCursorSprite
_0801F632:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F638: .4byte gUnknown_203B274
	thumb_func_end sub_801F5F0

	thumb_func_start sub_801F63C
sub_801F63C:
	push {r4-r6,lr}
	ldr r5, _0801F688
	ldr r2, [r5]
	cmp r2, 0
	beq _0801F680
	movs r1, 0xDF
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE1
	lsls r4, 2
	adds r1, r4
	ldr r0, _0801F68C
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_0801F680:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F688: .4byte gUnknown_203B274
_0801F68C: .4byte gUnknown_80DC2AC
	thumb_func_end sub_801F63C

	thumb_func_start sub_801F690
sub_801F690:
	push {r4,r5,lr}
	ldr r5, _0801F6F4
	ldr r0, [r5]
	ldr r1, _0801F6F8
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r3, [r5]
	movs r1, 0xDF
	lsls r1, 2
	adds r4, r3, r1
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _0801F6FC
	adds r1, r2
	asrs r2, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r3, r0
	adds r2, 0x2
	movs r0, 0xE5
	lsls r0, 2
	adds r3, r0
	strh r2, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r1, 0xE1
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F6F4: .4byte gUnknown_203B274
_0801F6F8: .4byte 0x00000362
_0801F6FC: .4byte 0x00000392
	thumb_func_end sub_801F690

	thumb_func_start sub_801F700
sub_801F700:
	push {r4-r7,lr}
	sub sp, 0xB4
	ldr r6, _0801F7D4
	ldr r0, [r6]
	movs r4, 0xDF
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r6]
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073B8
	add r5, sp, 0x34
	ldr r1, _0801F7D8
	ldr r0, [r6]
	ldr r3, _0801F7DC
	adds r2, r0, r3
	movs r7, 0
	ldrsh r2, [r2, r7]
	adds r2, 0x1
	adds r3, 0x2
	adds r0, r3
	movs r7, 0
	ldrsh r3, [r0, r7]
	adds r0, r5, 0
	bl sub_800D158
	ldr r0, [r6]
	adds r0, r4
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r1, 0
	adds r2, r5, 0
	bl xxx_call_draw_string
	movs r4, 0
	ldr r0, [r6]
	ldr r1, _0801F7E0
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r4, r0
	bge _0801F7BC
	adds r5, r6, 0
_0801F762:
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	ldr r3, _0801F7DC
	adds r0, r1, r3
	movs r6, 0
	ldrsh r3, [r0, r6]
	movs r7, 0xD9
	lsls r7, 2
	adds r1, r7
	movs r6, 0
	ldrsh r0, [r1, r6]
	muls r0, r3
	adds r0, r4
	lsls r0, 1
	adds r2, r0
	ldrh r1, [r2]
	add r0, sp, 0x4
	bl sub_8092C84
	ldr r0, [r5]
	subs r7, 0x1C
	adds r0, r7
	adds r1, r4, 0
	bl sub_8013800
	adds r1, r0, 0
	ldr r0, [r5]
	movs r2, 0xDF
	lsls r2, 2
	adds r0, r2
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x4
	bl xxx_call_draw_string
	adds r4, 0x1
	ldr r0, [r5]
	ldr r3, _0801F7E0
	adds r0, r3
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r4, r0
	blt _0801F762
_0801F7BC:
	ldr r0, _0801F7D4
	ldr r0, [r0]
	movs r7, 0xDF
	lsls r7, 2
	adds r0, r7
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0xB4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F7D4: .4byte gUnknown_203B274
_0801F7D8: .4byte gUnknown_80DC2DC
_0801F7DC: .4byte 0x00000366
_0801F7E0: .4byte 0x00000362
	thumb_func_end sub_801F700

	thumb_func_start sub_801F7E4
sub_801F7E4:
	push {r4,lr}
	ldr r4, _0801F804
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	ldr r1, [r1]
	bl sub_808E218
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0xCF
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801F804: .4byte gUnknown_203B274
	thumb_func_end sub_801F7E4

	thumb_func_start sub_801F808
sub_801F808:
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x1
	bl ResetSprites
	ldr r5, _0801F88C
	movs r0, 0xD4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r1, 0
	str r1, [r0, 0x5C]
	adds r1, r0, 0
	adds r1, 0x64
	str r1, [r0, 0x60]
	adds r0, r1, 0
	bl sub_80140B4
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	str r4, [r0, 0x4]
	movs r2, 0x4
	ldrh r0, [r4, 0x6]
	cmp r0, 0
	bne _0801F862
	adds r3, r5, 0
_0801F84C:
	subs r2, 0x1
	cmp r2, 0x1
	ble _0801F862
	ldr r0, [r3]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r1
	subs r0, 0x2
	ldrh r0, [r0]
	cmp r0, 0
	beq _0801F84C
_0801F862:
	ldr r4, _0801F88C
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r3, [r1, 0x5C]
	adds r1, r2, 0
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	adds r0, 0xC8
	bl sub_801317C
	movs r0, 0
	bl sub_801F918
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801F88C: .4byte gUnknown_203B278
	thumb_func_end sub_801F808

	thumb_func_start sub_801F890
sub_801F890:
	push {lr}
	ldr r0, _0801F8A8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	beq _0801F8BC
	cmp r0, 0x1
	bgt _0801F8AC
	cmp r0, 0
	beq _0801F8B6
	b _0801F8C6
	.align 2, 0
_0801F8A8: .4byte gUnknown_203B278
_0801F8AC:
	cmp r0, 0x2
	beq _0801F8C6
	cmp r0, 0x3
	beq _0801F8C2
	b _0801F8C6
_0801F8B6:
	bl sub_801FA58
	b _0801F8CA
_0801F8BC:
	bl sub_801FAD4
	b _0801F8CA
_0801F8C2:
	movs r0, 0x3
	b _0801F8CC
_0801F8C6:
	movs r0, 0x2
	b _0801F8CC
_0801F8CA:
	movs r0, 0
_0801F8CC:
	pop {r1}
	bx r1
	thumb_func_end sub_801F890

	thumb_func_start sub_801F8D0
sub_801F8D0:
	push {r4,r5,lr}
	ldr r4, _0801F910
	ldr r2, [r4]
	cmp r2, 0
	beq _0801F90A
	ldr r0, [r2, 0x5C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x64
	ldr r0, _0801F914
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801F90A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F910: .4byte gUnknown_203B278
_0801F914: .4byte gUnknown_80DC2F8
	thumb_func_end sub_801F8D0

	thumb_func_start sub_801F918
sub_801F918:
	push {lr}
	ldr r1, _0801F92C
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801F930
	bl sub_801F9A4
	pop {r0}
	bx r0
	.align 2, 0
_0801F92C: .4byte gUnknown_203B278
	thumb_func_end sub_801F918

	thumb_func_start sub_801F930
sub_801F930:
	push {r4,lr}
	ldr r4, _0801F94C
	ldr r0, [r4]
	adds r0, 0x64
	bl sub_80140B4
	ldr r2, [r4]
	ldr r3, [r2]
	cmp r3, 0
	beq _0801F950
	cmp r3, 0x1
	beq _0801F98C
	b _0801F99C
	.align 2, 0
_0801F94C: .4byte gUnknown_203B278
_0801F950:
	ldr r0, [r2, 0x60]
	adds r1, r2, 0
	adds r1, 0xC4
	str r1, [r0, 0x14]
	adds r0, r2, 0
	adds r0, 0x48
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x46
	ldrh r1, [r1]
	adds r0, 0xC5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC6
	movs r1, 0x10
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC7
	strb r3, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801F99C
_0801F98C:
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x64
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801F99C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801F930

	thumb_func_start sub_801F9A4
sub_801F9A4:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, _0801F9EC
	ldr r0, [r5]
	ldr r4, [r0]
	cmp r4, 0x1
	beq _0801F9F0
	cmp r4, 0x1
	bgt _0801FA48
	cmp r4, 0
	bne _0801FA48
	ldr r0, [r0, 0x5C]
	bl sub_8008C54
	ldr r3, [r5]
	adds r2, r3, 0
	adds r2, 0x46
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldr r1, [r3, 0x4]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3, 0x8]
	movs r1, 0
	ldrsh r0, [r2, r1]
	ldrh r1, [r3, 0x8]
	ldr r2, [r3, 0x5C]
	adds r3, 0x14
	bl sub_8093D9C
	ldr r1, [r5]
	str r0, [r1, 0x10]
	str r4, [r1, 0x24]
	b _0801FA48
	.align 2, 0
_0801F9EC: .4byte gUnknown_203B278
_0801F9F0:
	ldr r0, [r0, 0x5C]
	bl sub_8008C54
	ldr r0, [r5]
	ldr r0, [r0, 0x5C]
	bl sub_80073B8
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	lsls r1, 2
	adds r0, 0x14
	adds r0, r1
	ldr r1, [r0]
	ldr r0, _0801FA50
	ldr r1, [r1]
	bl strcpy
	ldr r2, _0801FA54
	ldr r0, [r5]
	ldr r3, [r0, 0x5C]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x10
	movs r1, 0
	bl sub_8014FF0
	ldr r3, [r5]
	ldr r1, [r3, 0xC]
	lsls r1, 2
	adds r0, r3, 0
	adds r0, 0x14
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	ldr r3, [r3, 0x5C]
	str r4, [sp]
	movs r0, 0x4
	movs r1, 0x10
	bl sub_8014FF0
	ldr r0, [r5]
	ldr r0, [r0, 0x5C]
	bl sub_80073E0
_0801FA48:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FA50: .4byte gAvailablePokemonNames
_0801FA54: .4byte gUnknown_80DC310
	thumb_func_end sub_801F9A4

	thumb_func_start sub_801FA58
sub_801FA58:
	push {r4,lr}
	ldr r0, _0801FAA4
	ldr r2, [r0]
	ldr r1, [r2, 0x10]
	adds r4, r0, 0
	cmp r1, 0
	beq _0801FA7C
	ldr r0, [r2, 0x24]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801FA74
	bl sub_8013F84
_0801FA74:
	ldr r1, [r4]
	ldr r0, [r1, 0x24]
	adds r0, 0x1
	str r0, [r1, 0x24]
_0801FA7C:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	ldr r1, [r1, 0x5C]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801FAA8
	cmp r0, 0x2
	beq _0801FAC2
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	beq _0801FACE
	movs r0, 0
	b _0801FACA
	.align 2, 0
_0801FAA4: .4byte gUnknown_203B278
_0801FAA8:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r1, [r4]
	ldr r0, [r1, 0x10]
	cmp r0, 0
	beq _0801FABE
	movs r0, 0
	str r0, [r1, 0xC]
	movs r0, 0x1
	b _0801FACA
_0801FABE:
	movs r0, 0x3
	b _0801FACA
_0801FAC2:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
_0801FACA:
	bl sub_801F918
_0801FACE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801FA58

	thumb_func_start sub_801FAD4
sub_801FAD4:
	push {r4,lr}
	ldr r0, _0801FB14
	ldr r3, [r0]
	ldr r1, [r3, 0x10]
	subs r1, 0x1
	ldr r2, [r3, 0xC]
	adds r4, r0, 0
	cmp r2, r1
	bge _0801FAFC
	ldr r0, [r3, 0x24]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0801FAF4
	bl sub_8013F84
_0801FAF4:
	ldr r1, [r4]
	ldr r0, [r1, 0x24]
	adds r0, 0x1
	str r0, [r1, 0x24]
_0801FAFC:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC8
	ldr r1, [r1, 0x5C]
	bl sub_8012A64
	cmp r0, 0x1
	beq _0801FB18
	cmp r0, 0x2
	beq _0801FB3C
	b _0801FB48
	.align 2, 0
_0801FB14: .4byte gUnknown_203B278
_0801FB18:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	adds r1, 0x1
	str r1, [r0, 0xC]
	ldr r0, [r0, 0x10]
	cmp r1, r0
	bge _0801FB34
	movs r0, 0x1
	bl sub_801F918
	b _0801FB48
_0801FB34:
	movs r0, 0
	bl sub_801F918
	b _0801FB48
_0801FB3C:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	bl sub_801F918
_0801FB48:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801FAD4

	thumb_func_start sub_801FB50
sub_801FB50:
	push {r4-r7,lr}
	adds r4, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r6, _0801FBC0
	movs r0, 0xF0
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	movs r7, 0
	str r7, [r0, 0x70]
	str r7, [r0, 0x74]
	str r7, [r0, 0x78]
	str r4, [r0]
	strb r7, [r0, 0x15]
	ldr r0, _0801FBC4
	ldr r4, _0801FBC8
	adds r1, r4, 0
	bl sub_808D8E0
	ldr r5, _0801FBCC
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808D8E0
	adds r0, r4, 0
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r5, 0
	subs r0, 0x50
	bl strcpy
	subs r5, 0xF0
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_808DA34
	ldr r2, [r6]
	ldr r0, [r2]
	cmp r0, 0x1
	bne _0801FBD0
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r2, r1
	str r7, [r0]
	b _0801FBDE
	.align 2, 0
_0801FBC0: .4byte gUnknown_203B27C
_0801FBC4: .4byte gUnknown_202E5D8
_0801FBC8: .4byte 0x00000155
_0801FBCC: .4byte gUnknown_202E1C8
_0801FBD0:
	movs r3, 0xBE
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0xB6
	lsls r4, 1
	adds r0, r2, r4
	str r0, [r1]
_0801FBDE:
	ldr r0, _0801FC34
	bl GetDialogueSpriteDataPtr
	ldr r2, _0801FC38
	ldr r3, [r2]
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r3, r4
	str r0, [r1]
	adds r4, 0x4
	adds r1, r3, r4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r3, r1
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _0801FC3C
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, 0xA
	adds r0, r4
	strb r1, [r0]
	ldr r2, [r2]
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x2
	strh r0, [r1]
	subs r3, 0x3
	adds r1, r2, r3
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_801FDA8
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801FC34: .4byte 0x00000155
_0801FC38: .4byte gUnknown_203B27C
_0801FC3C: .4byte 0x00000179
	thumb_func_end sub_801FB50

	thumb_func_start sub_801FC40
sub_801FC40:
	push {lr}
	ldr r1, _0801FC5C
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r2, r1, 0
	cmp r0, 0x22
	bls _0801FC50
	b _0801FD70
_0801FC50:
	lsls r0, 2
	ldr r1, _0801FC60
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FC5C: .4byte gUnknown_203B27C
_0801FC60: .4byte _0801FC64
	.align 2, 0
_0801FC64:
	.4byte _0801FCF0
	.4byte _0801FCF0
	.4byte _0801FCF6
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FCFC
	.4byte _0801FD02
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD50
	.4byte _0801FD70
	.4byte _0801FD08
	.4byte _0801FD08
	.4byte _0801FD0E
	.4byte _0801FD14
	.4byte _0801FD1A
	.4byte _0801FD70
	.4byte _0801FD20
	.4byte _0801FD20
	.4byte _0801FD26
	.4byte _0801FD2C
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD70
	.4byte _0801FD32
	.4byte _0801FD38
	.4byte _0801FD38
	.4byte _0801FD3E
	.4byte _0801FD44
	.4byte _0801FD4A
_0801FCF0:
	bl sub_8021154
	b _0801FD74
_0801FCF6:
	bl sub_80209AC
	b _0801FD74
_0801FCFC:
	bl sub_80209FC
	b _0801FD74
_0801FD02:
	bl sub_8020A34
	b _0801FD74
_0801FD08:
	bl sub_8020A80
	b _0801FD74
_0801FD0E:
	bl sub_8020B38
	b _0801FD74
_0801FD14:
	bl sub_8020C2C
	b _0801FD74
_0801FD1A:
	bl sub_8020C48
	b _0801FD74
_0801FD20:
	bl sub_8020C64
	b _0801FD74
_0801FD26:
	bl sub_8020CC0
	b _0801FD74
_0801FD2C:
	bl sub_8020D74
	b _0801FD74
_0801FD32:
	bl sub_8020D90
	b _0801FD74
_0801FD38:
	bl sub_8020DCC
	b _0801FD74
_0801FD3E:
	bl sub_8020EB4
	b _0801FD74
_0801FD44:
	bl sub_80210C8
	b _0801FD74
_0801FD4A:
	bl sub_80210E4
	b _0801FD74
_0801FD50:
	ldr r0, [r2]
	ldrb r0, [r0, 0x15]
	cmp r0, 0x1
	bne _0801FD68
	ldr r0, _0801FD6C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	subs r0, 0x96
	str r0, [r1]
_0801FD68:
	movs r0, 0x3
	b _0801FD76
	.align 2, 0
_0801FD6C: .4byte gUnknown_203B460
_0801FD70:
	bl sub_8021130
_0801FD74:
	movs r0, 0
_0801FD76:
	pop {r1}
	bx r1
	thumb_func_end sub_801FC40

	thumb_func_start sub_801FD7C
sub_801FD7C:
	push {r4,lr}
	ldr r4, _0801FDA4
	ldr r0, [r4]
	cmp r0, 0
	beq _0801FD9C
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801FD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FDA4: .4byte gUnknown_203B27C
	thumb_func_end sub_801FD7C

	thumb_func_start sub_801FDA8
sub_801FDA8:
	push {lr}
	ldr r1, _0801FDBC
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801FDC0
	bl sub_801FF28
	pop {r0}
	bx r0
	.align 2, 0
_0801FDBC: .4byte gUnknown_203B27C
	thumb_func_end sub_801FDA8

	thumb_func_start sub_801FDC0
sub_801FDC0:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0801FDE8
	ldr r0, [r4]
	movs r5, 0xC0
	lsls r5, 1
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	cmp r1, 0x11
	beq _0801FE38
	cmp r1, 0x11
	bgt _0801FDEC
	cmp r1, 0x2
	beq _0801FDF6
	b _0801FED4
	.align 2, 0
_0801FDE8: .4byte gUnknown_203B27C
_0801FDEC:
	cmp r1, 0x17
	beq _0801FE6C
	cmp r1, 0x20
	beq _0801FE88
	b _0801FED4
_0801FDF6:
	adds r0, r5
	movs r1, 0x80
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, 0xCC
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	movs r3, 0xD8
	lsls r3, 1
	adds r0, r3
	strb r1, [r0]
	ldr r1, [r4]
	movs r6, 0xE4
	lsls r6, 1
	adds r1, r6
	ldr r0, _0801FE34
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, r5
	movs r1, 0x1
	movs r2, 0
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FE34: .4byte gUnknown_80DC37C
_0801FE38:
	bl sub_80205D0
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE68
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	movs r6, 0xC0
	lsls r6, 1
	adds r0, r6
	b _0801FEC2
	.align 2, 0
_0801FE68: .4byte gUnknown_80DC334
_0801FE6C:
	bl sub_802069C
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FE84
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	b _0801FEB0
	.align 2, 0
_0801FE84: .4byte gUnknown_80DC334
_0801FE88:
	bl CreateGulpinLinkMenu
	ldr r1, [r4]
	movs r7, 0xCC
	lsls r7, 1
	adds r1, r7
	ldr r0, _0801FECC
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801FED0
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
_0801FEB0:
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0x7C
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, r5
_0801FEC2:
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801FF14
	.align 2, 0
_0801FECC: .4byte gUnknown_80DC31C
_0801FED0: .4byte gUnknown_80DC34C
_0801FED4:
	ldr r5, _0801FF20
	mov r12, r5
	movs r6, 0xC0
	lsls r6, 1
	mov r8, r6
	ldr r4, _0801FF24
	movs r3, 0
	movs r2, 0x3
_0801FEE4:
	mov r7, r12
	ldr r1, [r7]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801FEE4
	bl ResetUnusedInputStruct
	ldr r0, _0801FF20
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801FF14:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FF20: .4byte gUnknown_203B27C
_0801FF24: .4byte gUnknown_80DC31C
	thumb_func_end sub_801FDC0

	thumb_func_start sub_801FF28
sub_801FF28:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _0801FF44
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r5, r1, 0
	cmp r0, 0x23
	bls _0801FF3A
	b _08020562
_0801FF3A:
	lsls r0, 2
	ldr r1, _0801FF48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801FF44: .4byte gUnknown_203B27C
_0801FF48: .4byte _0801FF4C
	.align 2, 0
_0801FF4C:
	.4byte _0801FFDC
	.4byte _08020018
	.4byte _08020064
	.4byte _0802006C
	.4byte _08020090
	.4byte _080200B4
	.4byte _080200D8
	.4byte _080200FC
	.4byte _08020144
	.4byte _0802018C
	.4byte _080201B0
	.4byte _080201D4
	.4byte _080201F8
	.4byte _08020562
	.4byte _0802021C
	.4byte _08020240
	.4byte _0802024E
	.4byte _08020256
	.4byte _08020274
	.4byte _08020282
	.4byte _0802028E
	.4byte _080202B0
	.4byte _080202BE
	.4byte _080202C6
	.4byte _080202E4
	.4byte _08020304
	.4byte _08020344
	.4byte _080203B0
	.4byte _080203D4
	.4byte _0802038C
	.4byte _080203F8
	.4byte _08020428
	.4byte _08020434
	.4byte _08020460
	.4byte _08020478
	.4byte _08020500
_0801FFDC:
	ldr r0, [r5]
	movs r4, 0x2
	str r4, [r0, 0x6C]
	bl CreateGulpinShopMenu
	ldr r5, [r5]
	str r4, [r5, 0x8]
	ldr r2, _08020014
	ldr r1, [r5]
	movs r0, 0x64
	muls r0, r1
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r5, 0x6C]
	adds r3, r5, 0
	adds r3, 0x7C
	adds r1, r5, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r5, r4
	b _0802004C
	.align 2, 0
_08020014: .4byte gGulpinDialogue
_08020018:
	bl CreateGulpinShopMenu
	ldr r0, _0802005C
	ldr r4, [r0]
	movs r0, 0x2
	str r0, [r4, 0x8]
	ldr r1, _08020060
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4
	adds r0, r1
	ldr r0, [r0]
	ldr r2, [r4, 0x6C]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_0802004C:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802005C: .4byte gUnknown_203B27C
_08020060: .4byte gGulpinDialogue
_08020064:
	movs r0, 0x3
	bl sub_8016C40
	b _08020562
_0802006C:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _0802008C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802008C: .4byte gGulpinDialogue
_08020090:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200B0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0xC
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200B0: .4byte gGulpinDialogue
_080200B4:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200D4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x10
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200D4: .4byte gGulpinDialogue
_080200D8:
	ldr r2, [r5]
	movs r0, 0x1F
	str r0, [r2, 0x8]
	ldr r1, _080200F8
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x14
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080200F8: .4byte gGulpinDialogue
_080200FC:
	bl sub_8020900
	ldr r1, _0802013C
	ldr r0, _08020140
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x18
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x10
	bl sub_8014248
	b _08020562
	.align 2, 0
_0802013C: .4byte gGulpinDialogue
_08020140: .4byte gUnknown_203B27C
_08020144:
	bl sub_8020950
	ldr r1, _08020184
	ldr r0, _08020188
	ldr r4, [r0]
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x54
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0xD
	bl sub_8014248
	b _08020562
	.align 2, 0
_08020184: .4byte gGulpinDialogue
_08020188: .4byte gUnknown_203B27C
_0802018C:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x58
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201AC: .4byte gGulpinDialogue
_080201B0:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x5C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201D0: .4byte gGulpinDialogue
_080201D4:
	ldr r2, [r5]
	movs r0, 0x1
	str r0, [r2, 0x8]
	ldr r1, _080201F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x60
	adds r0, r1
	ldr r0, [r0]
	movs r5, 0xBE
	lsls r5, 1
	adds r2, r5
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080201F4: .4byte gGulpinDialogue
_080201F8:
	ldr r2, [r5]
	movs r0, 0xD
	str r0, [r2, 0x8]
	ldr r1, _08020218
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x1C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_08020218: .4byte gGulpinDialogue
_0802021C:
	ldr r2, [r5]
	movs r0, 0xF
	str r0, [r2, 0x8]
	ldr r1, _0802023C
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x20
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802023C: .4byte gGulpinDialogue
_08020240:
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _08020562
_0802024E:
	movs r0, 0x1
	bl sub_8023B7C
	b _08020562
_08020256:
	bl sub_8023DA4
	ldr r0, _08020270
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x70]
	b _0802044C
	.align 2, 0
_08020270: .4byte gUnknown_203B27C
_08020274:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0x2
	bl sub_8024458
	b _08020562
_08020282:
	ldr r0, [r5]
	movs r1, 0xC
	ldrsh r0, [r0, r1]
	bl sub_801BEEC
	b _08020562
_0802028E:
	ldr r2, [r5]
	movs r0, 0x15
	str r0, [r2, 0x8]
	ldr r1, _080202AC
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x24
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080202AC: .4byte gGulpinDialogue
_080202B0:
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r0, [r0, r5]
	movs r1, 0
	bl sub_801F428
	b _08020562
_080202BE:
	movs r0, 0x1
	bl sub_801F5F0
	b _08020562
_080202C6:
	bl sub_801F700
	ldr r0, _080202E0
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x74]
	b _0802044C
	.align 2, 0
_080202E0: .4byte gUnknown_203B27C
_080202E4:
	ldr r0, [r5]
	ldrh r1, [r0, 0x1C]
	adds r0, 0x64
	strh r1, [r0]
	movs r2, 0x1
	adds r4, r5, 0
	movs r3, 0
_080202F2:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r0, 0x64
	adds r0, r1
	strh r3, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080202F2
	b _0802046E
_08020304:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r1, [r5]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0802033C
	ldrh r1, [r1, 0x1E]
	bl sub_8092C84
	ldr r1, _08020340
	ldr r2, [r5]
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x28
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_0802033C: .4byte gAvailablePokemonNames
_08020340: .4byte gGulpinDialogue
_08020344:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	ldr r3, [r5]
	movs r0, 0x10
	str r0, [r3, 0x8]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020370
	ldr r1, _0802036C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x38
	b _08020520
	.align 2, 0
_0802036C: .4byte gGulpinDialogue
_08020370:
	ldr r1, _08020388
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x34
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	b _0802052A
	.align 2, 0
_08020388: .4byte gGulpinDialogue
_0802038C:
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _080203A2
	movs r5, 0xC
	ldrsh r1, [r2, r5]
	adds r2, 0x24
	movs r0, 0
	bl DisplayGulpinDialogueSprite
	b _08020562
_080203A2:
	movs r0, 0xC
	ldrsh r1, [r2, r0]
	adds r2, 0x24
	movs r0, 0x1
	bl DisplayGulpinDialogueSprite
	b _08020562
_080203B0:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203D0
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x3C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xBE
	lsls r1, 1
	adds r2, r1
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203D0: .4byte gGulpinDialogue
_080203D4:
	ldr r2, [r5]
	movs r0, 0x10
	str r0, [r2, 0x8]
	ldr r1, _080203F4
	ldr r3, [r2]
	movs r0, 0x64
	muls r0, r3
	adds r1, 0x40
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r2, r4
	ldr r2, [r2]
	b _0802052C
	.align 2, 0
_080203F4: .4byte gGulpinDialogue
_080203F8:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_809401C
	ldr r0, [r5]
	movs r5, 0xC
	ldrsh r1, [r0, r5]
	adds r2, r0, 0
	adds r2, 0x24
	ldrb r3, [r0, 0x15]
	ldr r0, _08020424
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r0, 0x1
	bl sub_801EE10
	b _08020562
	.align 2, 0
_08020424: .4byte gUnknown_80DC394
_08020428:
	ldr r0, [r5]
	ldrb r1, [r0, 0x15]
	movs r0, 0x1
	bl sub_801F1B0
	b _08020562
_08020434:
	movs r0, 0
	bl sub_801F280
	ldr r0, _0802045C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	adds r1, r2, 0
	adds r1, 0x7C
	adds r3, r2, 0
	adds r3, 0xBC
	ldr r2, [r2, 0x78]
_0802044C:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08020562
	.align 2, 0
_0802045C: .4byte gUnknown_203B27C
_08020460:
	ldr r2, [r5]
	ldr r0, [r2, 0x18]
	adds r1, r2, 0
	adds r1, 0x24
	adds r2, 0x64
	bl sub_8093560
_0802046E:
	ldr r0, [r5]
	adds r0, 0x64
	bl sub_801F808
	b _08020562
_08020478:
	bl sub_80208B0
	ldr r0, _080204B8
	ldr r4, _080204BC
	ldr r1, [r4]
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r4, [r4]
	ldrb r5, [r4, 0x14]
	cmp r5, 0
	beq _080204C4
	ldr r1, _080204C0
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r4, r2
	b _080204E8
	.align 2, 0
_080204B8: .4byte gUnknown_202DFE8
_080204BC: .4byte gUnknown_203B27C
_080204C0: .4byte gGulpinDialogue
_080204C4:
	ldr r1, _080204FC
	ldr r2, [r4]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x44
	adds r0, r1
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x7C
	adds r1, r4, 0
	adds r1, 0xBC
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r5, 0xBE
	lsls r5, 1
	adds r1, r4, r5
_080204E8:
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x11
	bl sub_8014248
	b _08020562
	.align 2, 0
_080204FC: .4byte gGulpinDialogue
_08020500:
	ldr r1, [r5]
	movs r0, 0x1F
	str r0, [r1, 0x8]
	ldr r0, _08020538
	ldrh r1, [r1, 0x20]
	bl sub_8092C84
	ldr r3, [r5]
	ldrb r0, [r3, 0x14]
	cmp r0, 0
	beq _08020544
	ldr r1, _0802053C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x50
_08020520:
	adds r0, r1
	ldr r0, [r0]
	movs r2, 0xBE
	lsls r2, 1
	adds r1, r3, r2
_0802052A:
	ldr r2, [r1]
_0802052C:
	ldr r3, _08020540
	movs r1, 0
	bl sub_80141B4
	b _08020562
	.align 2, 0
_08020538: .4byte gUnknown_202DFE8
_0802053C: .4byte gGulpinDialogue
_08020540: .4byte 0x0000010d
_08020544:
	ldr r1, _0802056C
	ldr r2, [r3]
	movs r0, 0x64
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r4, 0xBE
	lsls r4, 1
	adds r1, r3, r4
	ldr r2, [r1]
	ldr r3, _08020570
	movs r1, 0
	bl sub_80141B4
_08020562:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802056C: .4byte gGulpinDialogue
_08020570: .4byte 0x0000010d
	thumb_func_end sub_801FF28

	thumb_func_start CreateGulpinShopMenu
CreateGulpinShopMenu:
	push {r4,lr}
	ldr r4, _080205C0
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080205C4
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080205C8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080205CC
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x90
	str r2, [r0]
	adds r0, 0x4
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080205C0: .4byte gUnknown_203B27C
_080205C4: .4byte gGulpinProceed
_080205C8: .4byte gGulpinInfo
_080205CC: .4byte gUnknown_80D4934
	thumb_func_end CreateGulpinShopMenu

	thumb_func_start sub_80205D0
sub_80205D0:
	push {r4-r7,lr}
	ldr r4, _08020660
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _08020664
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r2, r12
	adds r2, 0x80
	movs r0, 0x4
	str r0, [r2]
	movs r3, 0x1
	adds r1, 0x84
	ldr r0, _08020668
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802066C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xC
	str r0, [r1]
	movs r6, 0x3
	adds r1, 0x4
	ldr r0, _08020670
	str r0, [r1]
	mov r0, r12
	adds r0, 0x98
	str r6, [r0]
	movs r6, 0x4
	adds r0, 0x4
	str r5, [r0]
	adds r0, 0x4
	str r3, [r0]
	mov r3, r12
	adds r3, 0xBC
_0802062A:
	ldrh r0, [r3]
	cmp r0, 0
	bne _0802063A
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x70]
	cmp r1, r0
	beq _08020696
_0802063A:
	adds r2, 0x8
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _0802062A
	movs r5, 0
	cmp r5, r6
	bge _08020696
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020674
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08020696
	.align 2, 0
_08020660: .4byte gUnknown_203B27C
_08020664: .4byte gUnknown_80DC3D8
_08020668: .4byte gUnknown_80DC3E0
_0802066C: .4byte gUnknown_80DC3E8
_08020670: .4byte gUnknown_80DC3F4
_08020674:
	adds r5, 0x1
	cmp r5, r6
	bge _08020696
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020674
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08020696:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80205D0

	thumb_func_start sub_802069C
sub_802069C:
	push {r4-r7,lr}
	ldr r4, _08020718
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r0, [r4]
	mov r12, r0
	movs r5, 0
	ldr r0, _0802071C
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r3, r12
	adds r3, 0x80
	movs r0, 0x3
	str r0, [r3]
	movs r2, 0x1
	adds r1, 0x84
	ldr r0, _08020720
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xB
	str r0, [r1]
	movs r6, 0x2
	mov r0, r12
	adds r0, 0x8C
	str r5, [r0]
	adds r0, 0x4
	str r2, [r0]
	mov r2, r12
	adds r2, 0xBC
_080206E0:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080206F0
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _08020746
_080206F0:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080206E0
	movs r5, 0
	cmp r5, r6
	bge _08020746
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020724
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _08020746
	.align 2, 0
_08020718: .4byte gUnknown_203B27C
_0802071C: .4byte gUnknown_80DC3F4
_08020720: .4byte gUnknown_80D4970
_08020724:
	adds r5, 0x1
	cmp r5, r6
	bge _08020746
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020724
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_08020746:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802069C

	thumb_func_start CreateGulpinLinkMenu
CreateGulpinLinkMenu:
	push {r4-r7,lr}
	movs r7, 0
	ldr r4, _08020780
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	ldrb r0, [r1, 0x16]
	cmp r0, 0
	beq _0802079C
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80932E0
	lsls r0, 24
	cmp r0, 0
	beq _08020788
	ldr r0, [r4]
	ldr r1, _08020784
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x6
	b _08020792
	.align 2, 0
_08020780: .4byte gUnknown_203B27C
_08020784: .4byte gGulpinDeselect
_08020788:
	ldr r0, [r4]
	ldr r1, _08020798
	str r1, [r0, 0x7C]
	adds r0, 0x80
	movs r1, 0x5
_08020792:
	str r1, [r0]
	mov r12, r4
	b _080207CA
	.align 2, 0
_08020798: .4byte gGulpinSet
_0802079C:
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80932FC
	lsls r0, 24
	cmp r0, 0
	beq _080207B4
	ldr r1, [r4]
	ldr r0, _080207B0
	b _080207B8
	.align 2, 0
_080207B0: .4byte gGulpinDeselect
_080207B4:
	ldr r1, [r4]
	ldr r0, _0802086C
_080207B8:
	str r0, [r1, 0x7C]
	ldr r2, _08020870
	ldr r0, [r2]
	lsls r1, r7, 3
	adds r0, 0x80
	adds r0, r1
	movs r1, 0x7
	str r1, [r0]
	mov r12, r2
_080207CA:
	adds r7, 0x1
	mov r0, r12
	ldr r4, [r0]
	lsls r1, r7, 3
	adds r3, r4, 0
	adds r3, 0x7C
	adds r2, r3, r1
	ldr r0, _08020874
	str r0, [r2]
	adds r6, r4, 0
	adds r6, 0x80
	adds r1, r6, r1
	movs r0, 0x8
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020878
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0x9
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802087C
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xA
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08020880
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xB
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r6, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	cmp r3, r7
	bge _0802084C
	adds r5, r4, 0
	adds r4, 0xBC
	adds r2, r6, 0
_08020834:
	ldrh r0, [r4]
	cmp r0, 0
	bne _08020842
	ldr r1, [r2]
	ldr r0, [r5, 0x78]
	cmp r1, r0
	beq _080208A8
_08020842:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _08020834
_0802084C:
	movs r3, 0
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xBC
	ldrh r0, [r0]
	cmp r0, 0
	bne _08020884
	adds r0, r1, 0
	adds r0, 0x80
	ldr r0, [r0]
	str r0, [r1, 0x78]
	b _080208A8
	.align 2, 0
_0802086C: .4byte gGulpinSet
_08020870: .4byte gUnknown_203B27C
_08020874: .4byte gGulpinLink
_08020878: .4byte gGulpinDelink
_0802087C: .4byte gGulpinForget
_08020880: .4byte gUnknown_80D4970
_08020884:
	adds r3, 0x1
	cmp r3, r7
	bge _080208A8
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0xBC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08020884
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0x80
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x78]
_080208A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateGulpinLinkMenu

	thumb_func_start sub_80208B0
sub_80208B0:
	push {r4,lr}
	ldr r4, _080208F4
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080208F8
	ldr r0, [r0]
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080208FC
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x8C
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080208F4: .4byte gUnknown_203B27C
_080208F8: .4byte gUnknown_80D4920
_080208FC: .4byte gUnknown_80D4928
	thumb_func_end sub_80208B0

	thumb_func_start sub_8020900
sub_8020900:
	push {r4,lr}
	ldr r4, _08020944
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08020948
	ldr r0, [r0]
	str r0, [r3, 0x7C]
	adds r1, r3, 0
	adds r1, 0x80
	movs r0, 0x10
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0802094C
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x11
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0x8C
	str r2, [r0]
	adds r1, 0x8
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020944: .4byte gUnknown_203B27C
_08020948: .4byte gUnknown_80D4920
_0802094C: .4byte gUnknown_80D4928
	thumb_func_end sub_8020900

	thumb_func_start sub_8020950
sub_8020950:
	push {r4,lr}
	ldr r4, _0802099C
	ldr r0, [r4]
	adds r0, 0xBC
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	ldr r0, _080209A0
	str r0, [r4, 0x7C]
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0xD
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _080209A4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xE
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _080209A8
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xF
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0x94
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802099C: .4byte gUnknown_203B27C
_080209A0: .4byte gUnknown_80DC428
_080209A4: .4byte gUnknown_80DC438
_080209A8: .4byte gUnknown_80DC448
	thumb_func_end sub_8020950

	thumb_func_start sub_80209AC
sub_80209AC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080209F4
	ldr r0, _080209D4
	ldr r1, [r0]
	ldr r0, [sp]
	str r0, [r1, 0x6C]
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080209DE
	cmp r0, 0x2
	bgt _080209D8
	cmp r0, 0x1
	beq _080209EE
	b _080209F4
	.align 2, 0
_080209D4: .4byte gUnknown_203B27C
_080209D8:
	cmp r0, 0xB
	beq _080209E6
	b _080209F4
_080209DE:
	movs r0, 0xE
	bl sub_801FDA8
	b _080209F4
_080209E6:
	movs r0, 0x8
	bl sub_801FDA8
	b _080209F4
_080209EE:
	movs r0, 0xC
	bl sub_801FDA8
_080209F4:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209AC

	thumb_func_start sub_80209FC
sub_80209FC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A2E
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08020A20
	cmp r0, 0x10
	bgt _08020A1A
	cmp r0, 0x1
	beq _08020A28
	b _08020A2E
_08020A1A:
	cmp r0, 0x11
	beq _08020A28
	b _08020A2E
_08020A20:
	movs r0, 0xE
	bl sub_801FDA8
	b _08020A2E
_08020A28:
	movs r0, 0xC
	bl sub_801FDA8
_08020A2E:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80209FC

	thumb_func_start sub_8020A34
sub_8020A34:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08020A7A
	ldr r0, [sp]
	cmp r0, 0xD
	beq _08020A5C
	cmp r0, 0xD
	bgt _08020A52
	cmp r0, 0x1
	beq _08020A74
	b _08020A7A
_08020A52:
	cmp r0, 0xE
	beq _08020A64
	cmp r0, 0xF
	beq _08020A6C
	b _08020A7A
_08020A5C:
	movs r0, 0x9
	bl sub_801FDA8
	b _08020A7A
_08020A64:
	movs r0, 0xA
	bl sub_801FDA8
	b _08020A7A
_08020A6C:
	movs r0, 0xB
	bl sub_801FDA8
	b _08020A7A
_08020A74:
	movs r0, 0x1
	bl sub_801FDA8
_08020A7A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8020A34

	thumb_func_start sub_8020A80
sub_8020A80:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x4
	bhi _08020B32
	lsls r0, 2
	ldr r1, _08020A98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020A98: .4byte _08020A9C
	.align 2, 0
_08020A9C:
	.4byte _08020B32
	.4byte _08020B32
	.4byte _08020B28
	.4byte _08020AB0
	.4byte _08020AEC
_08020AB0:
	bl sub_8023B44
	ldr r4, _08020AE0
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020AE4
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020AE8
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl sub_808DA34
	movs r0, 0x11
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020AE0: .4byte gUnknown_203B27C
_08020AE4: .4byte gUnknown_203B45C
_08020AE8: .4byte gUnknown_202E128
_08020AEC:
	bl sub_8023B44
	ldr r4, _08020B1C
	ldr r1, [r4]
	strh r0, [r1, 0xC]
	ldr r3, _08020B20
	movs r0, 0xC
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x10]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x16]
	ldr r0, _08020B24
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	bl sub_808DA34
	movs r0, 0x12
	bl sub_801FDA8
	b _08020B32
	.align 2, 0
_08020B1C: .4byte gUnknown_203B27C
_08020B20: .4byte gUnknown_203B45C
_08020B24: .4byte gUnknown_202E128
_08020B28:
	bl sub_8023C60
	movs r0, 0x7
	bl sub_801FDA8
_08020B32:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020A80

	thumb_func_start sub_8020B38
sub_8020B38:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _08020B7C
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020B68
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020B68
	ldr r0, [r4]
	str r1, [r0, 0x70]
_08020B68:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bhi _08020C24
	lsls r0, 2
	ldr r1, _08020B80
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020B7C: .4byte gUnknown_203B27C
_08020B80: .4byte _08020B84
	.align 2, 0
_08020B84:
	.4byte _08020BC8
	.4byte _08020C24
	.4byte _08020BD0
	.4byte _08020C0E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C16
	.4byte _08020C1E
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020C24
	.4byte _08020BC8
_08020BC8:
	movs r0, 0x10
	bl sub_801FDA8
	b _08020C24
_08020BD0:
	ldr r0, _08020BF0
	ldr r0, [r0]
	ldr r0, [r0, 0x10]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_808E858
	lsls r0, 16
	movs r1, 0xCF
	lsls r1, 17
	cmp r0, r1
	bne _08020BF4
	movs r0, 0x1C
	bl sub_801FDA8
	b _08020C24
	.align 2, 0
_08020BF0: .4byte gUnknown_203B27C
_08020BF4:
	bl sub_8021178
	lsls r0, 24
	cmp r0, 0
	beq _08020C06
	movs r0, 0x1B
	bl sub_801FDA8
	b _08020C24
_08020C06:
	movs r0, 0x14
	bl sub_801FDA8
	b _08020C24
_08020C0E:
	movs r0, 0x1E
	bl sub_801FDA8
	b _08020C24
_08020C16:
	movs r0, 0x12
	bl sub_801FDA8
	b _08020C24
_08020C1E:
	movs r0, 0x13
	bl sub_801FDA8
_08020C24:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020B38

	thumb_func_start sub_8020C2C
sub_8020C2C:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08020C44
	cmp r0, 0x3
	bhi _08020C44
	bl sub_802453C
	movs r0, 0x10
	bl sub_801FDA8
_08020C44:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C2C

	thumb_func_start sub_8020C48
sub_8020C48:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08020C60
	cmp r0, 0x3
	bhi _08020C60
	bl sub_801BF98
	movs r0, 0x10
	bl sub_801FDA8
_08020C60:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C48

	thumb_func_start sub_8020C64
sub_8020C64:
	push {lr}
	movs r0, 0x1
	bl sub_801F520
	cmp r0, 0x3
	beq _08020C80
	cmp r0, 0x3
	bhi _08020C7A
	cmp r0, 0x2
	beq _08020CB0
	b _08020CBA
_08020C7A:
	cmp r0, 0x4
	beq _08020C98
	b _08020CBA
_08020C80:
	bl sub_801F5B4
	ldr r1, _08020C94
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x17
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020C94: .4byte gUnknown_203B27C
_08020C98:
	bl sub_801F5B4
	ldr r1, _08020CAC
	ldr r1, [r1]
	strh r0, [r1, 0x1C]
	strh r0, [r1, 0x1E]
	movs r0, 0x18
	bl sub_801FDA8
	b _08020CBA
	.align 2, 0
_08020CAC: .4byte gUnknown_203B27C
_08020CB0:
	bl sub_801F63C
	movs r0, 0x10
	bl sub_801FDA8
_08020CBA:
	pop {r0}
	bx r0
	thumb_func_end sub_8020C64

	thumb_func_start sub_8020CC0
sub_8020CC0:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801F520
	ldr r4, _08020D00
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020CF0
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020CF0
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08020CF0:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08020D14
	cmp r0, 0x3
	bgt _08020D04
	cmp r0, 0x1
	beq _08020D0C
	b _08020D6C
	.align 2, 0
_08020D00: .4byte gUnknown_203B27C
_08020D04:
	cmp r0, 0xB
	beq _08020D66
	cmp r0, 0x11
	bne _08020D6C
_08020D0C:
	movs r0, 0x16
	bl sub_801FDA8
	b _08020D6C
_08020D14:
	bl sub_801F63C
	ldr r4, _08020D30
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_809401C
	movs r5, 0
	adds r6, r4, 0
	movs r4, 0x24
	b _08020D38
	.align 2, 0
_08020D30: .4byte gUnknown_203B27C
_08020D34:
	adds r4, 0x8
	adds r5, 0x1
_08020D38:
	cmp r5, 0x7
	bgt _08020D52
	ldr r3, [r6]
	adds r2, r3, r4
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08020D34
	ldrh r1, [r3, 0x1E]
	adds r0, r2, 0
	bl sub_8092AD4
_08020D52:
	cmp r5, 0x3
	ble _08020D5E
	movs r0, 0x1D
	bl sub_801FDA8
	b _08020D6C
_08020D5E:
	movs r0, 0x19
	bl sub_801FDA8
	b _08020D6C
_08020D66:
	movs r0, 0x18
	bl sub_801FDA8
_08020D6C:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8020CC0

	thumb_func_start sub_8020D74
sub_8020D74:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08020D8C
	cmp r0, 0x3
	bhi _08020D8C
	bl sub_801F8D0
	movs r0, 0x16
	bl sub_801FDA8
_08020D8C:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D74

	thumb_func_start sub_8020D90
sub_8020D90:
	push {lr}
	bl sub_801E8C0
	cmp r0, 0x2
	beq _08020DBC
	cmp r0, 0x2
	bcc _08020DC6
	cmp r0, 0x3
	bne _08020DC6
	bl sub_801E930
	ldr r1, _08020DB8
	ldr r1, [r1]
	strb r0, [r1, 0x14]
	bl sub_801E93C
	movs r0, 0x1A
	bl sub_801FDA8
	b _08020DC6
	.align 2, 0
_08020DB8: .4byte gUnknown_203B27C
_08020DBC:
	bl sub_801E93C
	movs r0, 0x10
	bl sub_801FDA8
_08020DC6:
	pop {r0}
	bx r0
	thumb_func_end sub_8020D90

	thumb_func_start sub_8020DCC
sub_8020DCC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08020EAA
	lsls r0, 2
	ldr r1, _08020DE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020DE4: .4byte _08020DE8
	.align 2, 0
_08020DE8:
	.4byte _08020EAA
	.4byte _08020E98
	.4byte _08020E64
	.4byte _08020DFC
	.4byte _08020E30
_08020DFC:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E0E
	ldr r0, _08020E2C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E0E:
	bl sub_801F194
	ldr r1, _08020E2C
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x20
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E2C: .4byte gUnknown_203B27C
_08020E30:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E42
	ldr r0, _08020E60
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E42:
	bl sub_801F194
	ldr r1, _08020E60
	ldr r2, [r1]
	str r0, [r2, 0x18]
	lsls r0, 3
	adds r0, r2, r0
	ldrh r1, [r0, 0x26]
	strh r1, [r2, 0x1C]
	ldrh r0, [r0, 0x26]
	strh r0, [r2, 0x20]
	movs r0, 0x21
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E60: .4byte gUnknown_203B27C
_08020E64:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020E76
	ldr r0, _08020E94
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020E76:
	bl sub_801F214
	ldr r0, _08020E94
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x10]
	adds r1, 0x2C
	bl sub_8094060
	movs r0, 0x10
	bl sub_801FDA8
	b _08020EAA
	.align 2, 0
_08020E94: .4byte gUnknown_203B27C
_08020E98:
	bl sub_801F1A4
	lsls r0, 24
	cmp r0, 0
	beq _08020EAA
	ldr r0, _08020EB0
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x15]
_08020EAA:
	pop {r0}
	bx r0
	.align 2, 0
_08020EB0: .4byte gUnknown_203B27C
	thumb_func_end sub_8020DCC

	thumb_func_start sub_8020EB4
sub_8020EB4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801EF38
	ldr r4, _08020EF8
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08020EE4
	ldr r0, [r4]
	adds r0, 0xCC
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08020EE4
	ldr r0, [r4]
	str r1, [r0, 0x78]
_08020EE4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x10
	bls _08020EEE
	b _080210BE
_08020EEE:
	lsls r0, 2
	ldr r1, _08020EFC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020EF8: .4byte gUnknown_203B27C
_08020EFC: .4byte _08020F00
	.align 2, 0
_08020F00:
	.4byte _08021068
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08020F44
	.4byte _08020F70
	.4byte _08020F8C
	.4byte _08020FB8
	.4byte _08021034
	.4byte _08021074
	.4byte _080210B8
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _080210BE
	.4byte _08021068
_08020F44:
	ldr r0, _08020F60
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80934DC
	lsls r0, 24
	cmp r0, 0
	beq _08020F68
	ldr r0, _08020F64
	bl sub_8011988
	b _08021068
	.align 2, 0
_08020F60: .4byte gUnknown_203B27C
_08020F64: .4byte 0x00000133
_08020F68:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _08021068
_08020F70:
	ldr r0, _08020F84
	bl sub_8011988
	ldr r0, _08020F88
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_809352C
	b _08021068
	.align 2, 0
_08020F84: .4byte 0x00000133
_08020F88: .4byte gUnknown_203B27C
_08020F8C:
	ldr r0, _08020FA8
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093544
	lsls r0, 24
	cmp r0, 0
	beq _08020FB0
	ldr r0, _08020FAC
	bl sub_8011988
	b _08021068
	.align 2, 0
_08020FA8: .4byte gUnknown_203B27C
_08020FAC: .4byte 0x00000133
_08020FB0:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _08021068
_08020FB8:
	ldr r0, _08020FD8
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x95
	bgt _08020FDC
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x3
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FD8: .4byte gUnknown_203B460
_08020FDC:
	ldr r4, _08020FFC
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093318
	lsls r0, 24
	cmp r0, 0
	bne _08021000
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x4
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08020FFC: .4byte gUnknown_203B27C
_08021000:
	ldr r1, [r4]
	ldrb r0, [r1, 0x15]
	cmp r0, 0
	bne _08021016
	movs r0, 0x1
	strb r0, [r1, 0x15]
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	b _0802101C
_08021016:
	ldr r0, _0802102C
	bl sub_8011988
_0802101C:
	ldr r0, _08021030
	ldr r1, [r0]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093400
	b _08021068
	.align 2, 0
_0802102C: .4byte 0x00000133
_08021030: .4byte gUnknown_203B27C
_08021034:
	ldr r4, _08021054
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_809333C
	lsls r0, 24
	cmp r0, 0
	bne _08021058
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x5
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021054: .4byte gUnknown_203B27C
_08021058:
	ldr r0, _08021070
	bl sub_8011988
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_8093468
_08021068:
	movs r0, 0x1F
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021070: .4byte 0x00000133
_08021074:
	ldr r4, _08021094
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80933A0
	lsls r0, 24
	cmp r0, 0
	bne _08021098
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x6
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_08021094: .4byte gUnknown_203B27C
_08021098:
	ldr r0, _080210B4
	bl sub_8011988
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	adds r1, 0x24
	bl sub_80934B0
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	movs r0, 0x22
	bl sub_801FDA8
	b _080210BE
	.align 2, 0
_080210B4: .4byte 0x00000133
_080210B8:
	movs r0, 0x21
	bl sub_801FDA8
_080210BE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8020EB4

	thumb_func_start sub_80210C8
sub_80210C8:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _080210E0
	cmp r0, 0x3
	bhi _080210E0
	bl sub_801F8D0
	movs r0, 0x1F
	bl sub_801FDA8
_080210E0:
	pop {r0}
	bx r0
	thumb_func_end sub_80210C8

	thumb_func_start sub_80210E4
sub_80210E4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0802112A
	ldr r0, [sp]
	cmp r0, 0x10
	beq _08021108
	cmp r0, 0x10
	bgt _08021102
	cmp r0, 0x1
	beq _08021124
	b _0802112A
_08021102:
	cmp r0, 0x11
	beq _08021124
	b _0802112A
_08021108:
	ldr r0, _08021120
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x18]
	bl sub_8093CF8
	movs r0, 0x23
	bl sub_801FDA8
	b _0802112A
	.align 2, 0
_08021120: .4byte gUnknown_203B27C
_08021124:
	movs r0, 0x1F
	bl sub_801FDA8
_0802112A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80210E4

	thumb_func_start sub_8021130
sub_8021130:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08021148
	ldr r0, _08021150
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_08021148:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021150: .4byte gUnknown_203B27C
	thumb_func_end sub_8021130

	thumb_func_start sub_8021154
sub_8021154:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0x4
	bne _0802116C
	ldr r0, _08021174
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801FDA8
_0802116C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08021174: .4byte gUnknown_203B27C
	thumb_func_end sub_8021154

	thumb_func_start sub_8021178
sub_8021178:
	push {lr}
	mov r12, r4
	ldr r4, _08021198
	add sp, r4
	mov r4, r12
	ldr r0, _0802119C
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	mov r0, sp
	bl sub_808E218
	cmp r0, 0
	beq _080211A0
	movs r0, 0
	b _080211A2
	.align 2, 0
_08021198: .4byte 0xfffffcc0
_0802119C: .4byte gUnknown_203B27C
_080211A0:
	movs r0, 0x1
_080211A2:
	movs r3, 0xD0
	lsls r3, 2
	add sp, r3
	pop {r1}
	bx r1
	thumb_func_end sub_8021178

	thumb_func_start sub_80211AC
sub_80211AC:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _080211C0
	movs r0, 0
	b _08021258
_080211C0:
	ldr r5, _08021260
	movs r0, 0xE0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r4, [r0, 0x3C]
	str r6, [r0, 0x74]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x7C
	adds r1, r0, r1
	str r1, [r0, 0x78]
	adds r0, 0x7C
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x74]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x7C
	ldr r0, _08021264
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r0, [r5]
	ldr r1, [r0, 0x78]
	adds r0, 0xDC
	str r0, [r1, 0x14]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x40
	bl sub_8021664
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	adds r3, r6, 0
	bl sub_8013818
	ldr r0, _08021268
	ldr r2, [r5]
	ldr r1, [r0]
	ldr r0, [r2, 0x3C]
	cmp r1, r0
	bne _0802124E
	ldr r0, _0802126C
	ldrh r1, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	strh r1, [r0]
	ldr r0, _08021270
	ldrh r0, [r0]
	adds r1, r2, 0
	adds r1, 0x5E
	strh r0, [r1]
	adds r0, r2, 0
	adds r0, 0x40
	bl sub_8013984
_0802124E:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021258:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08021260: .4byte gUnknown_203B280
_08021264: .4byte gUnknown_80DC47C
_08021268: .4byte gUnknown_203B284
_0802126C: .4byte gUnknown_203B288
_08021270: .4byte gUnknown_203B28A
	thumb_func_end sub_80211AC

	thumb_func_start sub_8021274
sub_8021274:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08021290
	ldr r0, _0802128C
	ldr r0, [r0]
	adds r0, 0x40
	bl sub_8013660
	movs r0, 0
	b _08021326
	.align 2, 0
_0802128C: .4byte gUnknown_203B280
_08021290:
	ldr r4, _080212A8
	ldr r0, [r4]
	adds r0, 0x40
	bl GetKeyPress
	cmp r0, 0x2
	beq _080212B2
	cmp r0, 0x2
	bgt _080212AC
	cmp r0, 0x1
	beq _080212BC
	b _08021300
	.align 2, 0
_080212A8: .4byte gUnknown_203B280
_080212AC:
	cmp r0, 0x4
	beq _080212F6
	b _08021300
_080212B2:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08021326
_080212BC:
	ldr r0, [r4]
	ldr r0, [r0, 0x3C]
	cmp r0, 0x2
	bne _080212EC
	bl sub_802132C
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaPrice
	ldr r1, _080212E8
	ldr r1, [r1]
	movs r2, 0x98
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _080212EC
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _080212F2
	.align 2, 0
_080212E8: .4byte gUnknown_203B460
_080212EC:
	movs r0, 0
	bl PlayMenuSoundEffect
_080212F2:
	movs r0, 0x3
	b _08021326
_080212F6:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _08021326
_08021300:
	ldr r0, _08021318
	ldr r0, [r0]
	adds r0, 0x40
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802131C
	movs r0, 0
	b _08021326
	.align 2, 0
_08021318: .4byte gUnknown_203B280
_0802131C:
	bl sub_8021410
	bl sub_8021494
	movs r0, 0x1
_08021326:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8021274

	thumb_func_start sub_802132C
sub_802132C:
	ldr r0, _08021350
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x58
	movs r3, 0
	ldrsh r1, [r1, r3]
	adds r0, r1
	adds r0, r2, r0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08021350: .4byte gUnknown_203B280
	thumb_func_end sub_802132C

	thumb_func_start sub_8021354
sub_8021354:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802139C
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8021664
	adds r1, r0, 0
	ldr r0, [r5]
	adds r2, r0, 0
	adds r2, 0x62
	strh r1, [r2]
	adds r0, 0x40
	bl sub_8013984
	bl sub_8021410
	bl sub_8021494
	cmp r4, 0
	beq _08021396
	ldr r0, [r5]
	adds r0, 0x40
	bl AddMenuCursorSprite
_08021396:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802139C: .4byte gUnknown_203B280
	thumb_func_end sub_8021354

	thumb_func_start sub_80213A0
sub_80213A0:
	push {r4,r5,lr}
	ldr r4, _080213FC
	ldr r2, [r4]
	cmp r2, 0
	beq _080213F4
	ldr r1, _08021400
	ldr r0, [r2, 0x3C]
	str r0, [r1]
	ldr r1, _08021404
	adds r0, r2, 0
	adds r0, 0x58
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08021408
	adds r0, r2, 0
	adds r0, 0x5E
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r2, 0x74]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7C
	ldr r0, _0802140C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080213F4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080213FC: .4byte gUnknown_203B280
_08021400: .4byte gUnknown_203B284
_08021404: .4byte gUnknown_203B288
_08021408: .4byte gUnknown_203B28A
_0802140C: .4byte gUnknown_80DC464
	thumb_func_end sub_80213A0

	thumb_func_start sub_8021410
sub_8021410:
	push {r4,lr}
	ldr r4, _08021490
	ldr r0, [r4]
	adds r0, 0xDC
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDD
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xDE
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xDF
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x74]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x8A
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x74]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x8C
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021490: .4byte gUnknown_203B280
	thumb_func_end sub_8021410

	thumb_func_start sub_8021494
sub_8021494:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xA8
	ldr r4, _08021568
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r2, _0802156C
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r4]
	adds r0, r3, 0
	adds r0, 0xDE
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	adds r1, r3, 0
	adds r1, 0x5E
	movs r5, 0
	ldrsh r2, [r1, r5]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	ldr r1, [r3, 0x74]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r0, 0
	mov r9, r0
	ldr r0, [r4]
	adds r0, 0x5A
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r9, r0
	blt _080214FC
	b _08021646
_080214FC:
	mov r8, r4
	add r2, sp, 0x58
	mov r10, r2
_08021502:
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, 0
	adds r0, 0x5E
	movs r5, 0
	ldrsh r1, [r0, r5]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	add r0, r9
	adds r0, r2, r0
	ldrb r5, [r0]
	adds r7, r5, 0
	ldr r6, [r2, 0x3C]
	cmp r6, 0x2
	bne _0802159C
	add r0, sp, 0x8
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8092578
	adds r0, r5, 0
	bl GetFriendAreaPrice
	ldr r1, _08021570
	ldr r1, [r1]
	movs r5, 0x98
	lsls r5, 2
	adds r1, r5
	ldr r1, [r1]
	cmp r0, r1
	bgt _08021574
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r2, r8
	ldr r0, [r2]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021568: .4byte gUnknown_203B280
_0802156C: .4byte gUnknown_80DC494
_08021570: .4byte gUnknown_203B460
_08021574:
	mov r0, r10
	ldr r1, _08021598
	add r2, sp, 0x8
	bl sub_800D158
	mov r3, r8
	ldr r0, [r3]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	b _080215FE
	.align 2, 0
_08021598: .4byte gUnknown_80DC4A4
_0802159C:
	cmp r6, 0
	bne _0802160C
	ldr r0, _080215D4
	ldr r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080215D8
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r5, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x74]
	str r6, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_080215D4: .4byte gFriendAreas
_080215D8:
	adds r0, r5, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r0, r10
	ldr r1, _08021608
	bl sub_800D158
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r1, r0, 0
	mov r3, r8
	ldr r0, [r3]
	ldr r3, [r0, 0x74]
	str r6, [sp]
_080215FE:
	movs r0, 0x8
	mov r2, r10
	bl xxx_call_draw_string
	b _08021632
	.align 2, 0
_08021608: .4byte gUnknown_80DC4AC
_0802160C:
	adds r0, r2, 0
	adds r0, 0x40
	mov r1, r9
	bl sub_8013800
	adds r4, r0, 0
	adds r0, r7, 0
	bl GetFriendAreaName
	adds r2, r0, 0
	mov r5, r8
	ldr r0, [r5]
	ldr r3, [r0, 0x74]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	adds r1, r4, 0
	bl xxx_call_draw_string
_08021632:
	movs r0, 0x1
	add r9, r0
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x5A
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r9, r0
	bge _08021646
	b _08021502
_08021646:
	ldr r0, _08021660
	ldr r0, [r0]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	add sp, 0xA8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021660: .4byte gUnknown_203B280
	thumb_func_end sub_8021494

	thumb_func_start sub_8021664
sub_8021664:
	push {r4-r6,lr}
	movs r5, 0
	ldr r1, _0802167C
	ldr r0, [r1]
	ldr r0, [r0, 0x3C]
	cmp r0, 0x1
	beq _08021692
	cmp r0, 0x1
	bcc _08021680
	cmp r0, 0x2
	beq _080216B4
	b _080216F2
	.align 2, 0
_0802167C: .4byte gUnknown_203B280
_08021680:
	movs r4, 0x1
_08021682:
	ldr r0, [r1]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021682
	b _080216F2
_08021692:
	movs r4, 0x1
	ldr r2, _080216B0
_08021696:
	ldr r0, [r2]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _080216A8
	ldr r0, [r1]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_080216A8:
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021696
	b _080216F2
	.align 2, 0
_080216B0: .4byte gFriendAreas
_080216B4:
	movs r4, 0x1
	adds r6, r1, 0
_080216B8:
	ldr r0, _080216FC
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080216EC
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetFriendAreaUnlockCondition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080216E4
	cmp r0, 0x1
	bne _080216EC
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080216EC
_080216E4:
	ldr r0, [r6]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_080216EC:
	adds r4, 0x1
	cmp r4, 0x39
	ble _080216B8
_080216F2:
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080216FC: .4byte gFriendAreas
	thumb_func_end sub_8021664

	thumb_func_start sub_8021700
sub_8021700:
	push {r4,lr}
	cmp r0, 0x1
	beq _08021710
	cmp r0, 0x1
	bcc _08021754
	cmp r0, 0x2
	beq _0802172C
	b _0802176A
_08021710:
	movs r4, 0x1
	ldr r0, _08021728
	ldr r1, [r0]
_08021716:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08021754
	adds r4, 0x1
	cmp r4, 0x39
	ble _08021716
	b _0802176A
	.align 2, 0
_08021728: .4byte gFriendAreas
_0802172C:
	movs r4, 0x1
_0802172E:
	ldr r0, _08021750
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08021764
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetFriendAreaUnlockCondition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08021754
	cmp r0, 0x1
	beq _08021758
	b _08021764
	.align 2, 0
_08021750: .4byte gFriendAreas
_08021754:
	movs r0, 0
	b _0802176C
_08021758:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08021754
_08021764:
	adds r4, 0x1
	cmp r4, 0x39
	ble _0802172E
_0802176A:
	movs r0, 0x1
_0802176C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8021700

	thumb_func_start sub_8021774
sub_8021774:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	adds r5, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r6, _080217E4
	movs r0, 0xE0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	strb r4, [r0, 0xC]
	ldr r0, [r6]
	strb r5, [r0, 0xD]
	ldr r0, [r6]
	bl sub_801317C
	bl sub_8021A60
	ldr r0, [r6]
	mov r1, r8
	str r1, [r0, 0x74]
	lsls r1, 1
	add r1, r8
	lsls r1, 3
	adds r1, 0x7C
	adds r1, r0, r1
	str r1, [r0, 0x78]
	adds r0, 0x7C
	bl sub_8006518
	ldr r1, [r6]
	ldr r2, [r1, 0x74]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x7C
	ldr r0, _080217E8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	bl sub_8021820
	movs r0, 0x1
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080217E4: .4byte gUnknown_203B28C
_080217E8: .4byte gUnknown_80DC4D8
	thumb_func_end sub_8021774

	thumb_func_start sub_80217EC
sub_80217EC:
	push {lr}
	ldr r0, _0802180C
	ldr r0, [r0]
	ldr r1, [r0, 0x74]
	bl sub_8012A64
	cmp r0, 0x1
	beq _08021810
	cmp r0, 0x2
	bne _0802181A
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802181C
	.align 2, 0
_0802180C: .4byte gUnknown_203B28C
_08021810:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802181C
_0802181A:
	movs r0, 0
_0802181C:
	pop {r1}
	bx r1
	thumb_func_end sub_80217EC

	thumb_func_start sub_8021820
sub_8021820:
	push {lr}
	bl sub_8021878
	bl sub_8021894
	pop {r0}
	bx r0
	thumb_func_end sub_8021820

	thumb_func_start sub_8021830
sub_8021830:
	push {r4,r5,lr}
	ldr r4, _08021870
	ldr r2, [r4]
	cmp r2, 0
	beq _0802186A
	ldr r0, [r2, 0x74]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x7C
	ldr r0, _08021874
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802186A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021870: .4byte gUnknown_203B28C
_08021874: .4byte gUnknown_80DC4BC
	thumb_func_end sub_8021830

	thumb_func_start sub_8021878
sub_8021878:
	push {lr}
	bl ResetUnusedInputStruct
	ldr r0, _08021890
	ldr r0, [r0]
	adds r0, 0x7C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r0}
	bx r0
	.align 2, 0
_08021890: .4byte gUnknown_203B28C
	thumb_func_end sub_8021878

	thumb_func_start sub_8021894
sub_8021894:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x168
	ldr r4, _080218F8
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	bl sub_80073B8
	ldr r0, [r4]
	ldrb r1, [r0, 0xC]
	add r0, sp, 0x4
	movs r2, 0
	bl sub_8092578
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	movs r5, 0
	str r5, [sp]
	movs r0, 0x14
	movs r1, 0
	add r2, sp, 0x4
	bl xxx_call_draw_string
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl GetFriendAreaDescription
	adds r2, r0, 0
	ldr r0, [r4]
	ldr r3, [r0, 0x74]
	str r5, [sp]
	movs r0, 0xA
	movs r1, 0x14
	bl xxx_call_draw_string
	ldr r4, [r4]
	ldrb r0, [r4, 0xD]
	cmp r0, 0
	beq _08021900
	ldr r2, _080218FC
	ldr r3, [r4, 0x74]
	str r5, [sp]
	movs r0, 0x20
	movs r1, 0x3C
	bl xxx_call_draw_string
	b _0802190E
	.align 2, 0
_080218F8: .4byte gUnknown_203B28C
_080218FC: .4byte gUnknown_80DC4F0
_08021900:
	ldr r2, _0802193C
	ldr r3, [r4, 0x74]
	str r0, [sp]
	movs r0, 0x20
	movs r1, 0x3C
	bl xxx_call_draw_string
_0802190E:
	ldr r4, _08021940
	ldr r0, [r4]
	ldr r0, [r0, 0x74]
	movs r5, 0x4
	str r5, [sp]
	movs r1, 0x4
	movs r2, 0x40
	movs r3, 0x14
	bl sub_800792C
	ldr r4, [r4]
	ldrb r0, [r4, 0xD]
	cmp r0, 0
	beq _08021944
	ldr r0, [r4, 0x74]
	str r5, [sp]
	movs r1, 0xB8
	movs r2, 0x40
	movs r3, 0x14
	bl sub_800792C
	b _08021952
	.align 2, 0
_0802193C: .4byte gUnknown_80DC518
_08021940: .4byte gUnknown_203B28C
_08021944:
	ldr r0, [r4, 0x74]
	str r5, [sp]
	movs r1, 0x5E
	movs r2, 0x40
	movs r3, 0x6E
	bl sub_800792C
_08021952:
	ldr r5, _080219E8
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	movs r4, 0x4
	str r4, [sp]
	movs r1, 0x4
	movs r2, 0x82
	movs r3, 0xC8
	bl sub_800792C
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	str r4, [sp]
	movs r1, 0x3
	movs r2, 0x40
	movs r3, 0x43
	bl sub_8007A78
	ldr r0, [r5]
	ldr r0, [r0, 0x74]
	str r4, [sp]
	movs r1, 0xCC
	movs r2, 0x40
	movs r3, 0x43
	bl sub_8007A78
	movs r6, 0
	ldr r0, [r5]
	ldr r0, [r0, 0x70]
	cmp r6, r0
	bge _08021A40
	add r7, sp, 0x104
	mov r8, r5
	mov r9, r6
_08021996:
	adds r0, r6, 0
	movs r1, 0x3
	bl __modsi3
	lsls r1, r0, 6
	subs r1, r0
	adds r5, r1, 0x7
	adds r0, r6, 0
	movs r1, 0x3
	bl __divsi3
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r4, r1, 0
	adds r4, 0x47
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r6, 1
	adds r0, 0xE
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_808D930
	mov r0, r8
	ldr r3, [r0]
	lsls r1, r6, 2
	adds r0, r3, 0
	adds r0, 0x30
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x1
	beq _08021A04
	cmp r0, 0x1
	bcc _080219EC
	cmp r0, 0x2
	beq _08021A16
	b _08021A34
	.align 2, 0
_080219E8: .4byte gUnknown_203B28C
_080219EC:
	ldr r0, _08021A00
	ldr r2, [r0]
	ldr r3, [r3, 0x74]
	mov r1, r9
	str r1, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	bl xxx_call_draw_string
	b _08021A34
	.align 2, 0
_08021A00: .4byte gUnknown_80D49BC
_08021A04:
	ldr r3, [r3, 0x74]
	mov r2, r9
	str r2, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl xxx_call_draw_string
	b _08021A34
_08021A16:
	add r0, sp, 0x4
	ldr r1, _08021A58
	adds r2, r7, 0
	bl sub_800D158
	mov r1, r8
	ldr r0, [r1]
	ldr r3, [r0, 0x74]
	mov r2, r9
	str r2, [sp]
	adds r0, r5, 0
	adds r1, r4, 0
	add r2, sp, 0x4
	bl xxx_call_draw_string
_08021A34:
	adds r6, 0x1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x70]
	cmp r6, r0
	blt _08021996
_08021A40:
	ldr r0, _08021A5C
	ldr r0, [r0]
	ldr r0, [r0, 0x74]
	bl sub_80073E0
	add sp, 0x168
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021A58: .4byte gUnknown_80DC524
_08021A5C: .4byte gUnknown_203B28C
	thumb_func_end sub_8021894

	thumb_func_start sub_8021A60
sub_8021A60:
	push {r4-r7,lr}
	ldr r2, _08021B4C
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x70]
	movs r6, 0
	adds r4, r2, 0
	movs r3, 0
_08021A70:
	ldr r1, [r4]
	lsls r2, r6, 1
	adds r0, r1, 0
	adds r0, 0xE
	adds r0, r2
	strh r3, [r0]
	lsls r0, r6, 2
	adds r1, 0x30
	adds r1, r0
	str r3, [r1]
	adds r6, 0x1
	cmp r6, 0xF
	ble _08021A70
	movs r6, 0
	ldr r7, _08021B4C
_08021A8E:
	lsls r0, r6, 16
	asrs r5, r0, 16
	ldr r4, [r7]
	adds r0, r5, 0
	bl GetFriendArea
	ldrb r1, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _08021AC4
	adds r0, r5, 0
	bl sub_808E858
	lsls r0, 16
	asrs r0, 16
	cmp r5, r0
	bne _08021AC4
	ldr r3, [r7]
	ldr r1, [r3, 0x70]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0xE
	adds r0, r2
	strh r5, [r0]
	adds r1, 0x1
	str r1, [r3, 0x70]
_08021AC4:
	adds r6, 0x1
	ldr r0, _08021B50
	cmp r6, r0
	ble _08021A8E
	movs r6, 0
_08021ACE:
	lsls r0, r6, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _08021AFC
	adds r0, r4, 0
	bl sub_8021B58
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08021AFC
	ldr r0, _08021B4C
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, 0x30
	adds r1, r0
	movs r0, 0x1
	str r0, [r1]
_08021AFC:
	adds r6, 0x1
	ldr r0, _08021B50
	cmp r6, r0
	ble _08021ACE
	movs r6, 0
	ldr r4, _08021B54
_08021B08:
	movs r0, 0x58
	adds r1, r6, 0
	muls r1, r0
	ldr r0, [r4]
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08021B3C
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl sub_8021B58
	adds r2, r0, 0
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _08021B3C
	ldr r0, _08021B4C
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r1, 0x30
	adds r1, r0
	movs r0, 0x2
	str r0, [r1]
_08021B3C:
	adds r6, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r6, r0
	ble _08021B08
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021B4C: .4byte gUnknown_203B28C
_08021B50: .4byte 0x000001a7
_08021B54: .4byte gUnknown_203B45C
	thumb_func_end sub_8021A60

	thumb_func_start sub_8021B58
sub_8021B58:
	push {r4,r5,lr}
	lsls r0, 16
	asrs r0, 16
	bl sub_808E858
	lsls r0, 16
	asrs r4, r0, 16
	movs r2, 0
	ldr r0, _08021B84
	ldr r0, [r0]
	ldr r1, [r0, 0x70]
	cmp r2, r1
	bge _08021B90
	adds r3, r1, 0
	adds r1, r0, 0
	adds r1, 0xE
_08021B78:
	movs r5, 0
	ldrsh r0, [r1, r5]
	cmp r4, r0
	bne _08021B88
	adds r0, r2, 0
	b _08021B94
	.align 2, 0
_08021B84: .4byte gUnknown_203B28C
_08021B88:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _08021B78
_08021B90:
	movs r0, 0x1
	negs r0, r0
_08021B94:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8021B58

	thumb_func_start sub_8021B9C
sub_8021B9C:
	push {r4-r6,lr}
	adds r4, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _08021BF8
	movs r0, 0x9C
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	str r6, [r0, 0x14]
	str r6, [r0, 0x18]
	str r4, [r0]
	ldr r0, _08021BFC
	movs r1, 0x28
	bl sub_808D8E0
	ldr r4, _08021C00
	adds r0, r4, 0
	movs r1, 0x28
	bl sub_808D8E0
	movs r0, 0x28
	bl GetMonSpecies
	adds r1, r0, 0
	subs r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r5, [r5]
	ldr r0, [r5]
	cmp r0, 0x1
	bne _08021C04
	adds r0, r5, 0
	adds r0, 0xCC
	str r6, [r0]
	b _08021C0E
	.align 2, 0
_08021BF8: .4byte gUnknown_203B290
_08021BFC: .4byte gUnknown_202E5D8
_08021C00: .4byte gUnknown_202E1C8
_08021C04:
	adds r1, r5, 0
	adds r1, 0xCC
	adds r0, r5, 0
	adds r0, 0xBC
	str r0, [r1]
_08021C0E:
	movs r0, 0x28
	bl GetDialogueSpriteDataPtr
	ldr r2, _08021C58
	ldr r3, [r2]
	adds r1, r3, 0
	adds r1, 0xBC
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r0, 0x4]
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xC8
	movs r1, 0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xC9
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, 0xCA
	strb r1, [r0]
	ldr r1, [r2]
	adds r2, r1, 0
	adds r2, 0xC4
	movs r0, 0x2
	strh r0, [r2]
	adds r1, 0xC6
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_8021D44
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08021C58: .4byte gUnknown_203B290
	thumb_func_end sub_8021B9C

	thumb_func_start sub_8021C5C
sub_8021C5C:
	push {lr}
	ldr r0, _08021C74
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x17
	bhi _08021D10
	lsls r0, 2
	ldr r1, _08021C78
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021C74: .4byte gUnknown_203B290
_08021C78: .4byte _08021C7C
	.align 2, 0
_08021C7C:
	.4byte _08021CDC
	.4byte _08021CDC
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D0C
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021CE2
	.4byte _08021CE2
	.4byte _08021CE8
	.4byte _08021D10
	.4byte _08021CF4
	.4byte _08021CFA
	.4byte _08021D10
	.4byte _08021D00
	.4byte _08021CEE
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D10
	.4byte _08021D06
	.4byte _08021D06
_08021CDC:
	bl sub_8022460
	b _08021D14
_08021CE2:
	bl sub_8022538
	b _08021D14
_08021CE8:
	bl sub_80225C8
	b _08021D14
_08021CEE:
	bl sub_80224D4
	b _08021D14
_08021CF4:
	bl sub_80226F0
	b _08021D14
_08021CFA:
	bl sub_8022790
	b _08021D14
_08021D00:
	bl sub_8022668
	b _08021D14
_08021D06:
	bl sub_8022684
	b _08021D14
_08021D0C:
	movs r0, 0x3
	b _08021D16
_08021D10:
	bl sub_80226CC
_08021D14:
	movs r0, 0
_08021D16:
	pop {r1}
	bx r1
	thumb_func_end sub_8021C5C

	thumb_func_start sub_8021D1C
sub_8021D1C:
	push {r4,lr}
	ldr r4, _08021D40
	ldr r0, [r4]
	cmp r0, 0
	beq _08021D38
	adds r0, 0xBC
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08021D38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021D40: .4byte gUnknown_203B290
	thumb_func_end sub_8021D1C

	thumb_func_start sub_8021D44
sub_8021D44:
	push {lr}
	ldr r1, _08021D58
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_8021D5C
	bl sub_8021E0C
	pop {r0}
	bx r0
	.align 2, 0
_08021D58: .4byte gUnknown_203B290
	thumb_func_end sub_8021D44

	thumb_func_start sub_8021D5C
sub_8021D5C:
	push {r4-r7,lr}
	ldr r4, _08021D7C
	ldr r0, [r4]
	adds r0, 0xD0
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x9
	blt _08021DC8
	cmp r0, 0xA
	ble _08021D80
	cmp r0, 0xB
	beq _08021DB0
	b _08021DC8
	.align 2, 0
_08021D7C: .4byte gUnknown_203B290
_08021D80:
	ldr r2, _08021DA8
	adds r1, 0xD0
	adds r0, r2, 0
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r3,r5,r7}
	stm r1!, {r3,r5,r7}
	ldr r0, [r4]
	movs r6, 0x80
	lsls r6, 1
	adds r0, r6
	ldm r2!, {r1,r3,r7}
	stm r0!, {r1,r3,r7}
	ldm r2!, {r5-r7}
	stm r0!, {r5-r7}
	ldr r1, [r4]
	adds r1, 0xE8
	ldr r0, _08021DAC
	b _08021DB8
	.align 2, 0
_08021DA8: .4byte gUnknown_80DC534
_08021DAC: .4byte gUnknown_80DC564
_08021DB0:
	movs r0, 0x80
	lsls r0, 1
	adds r1, r0
	ldr r0, _08021DC4
_08021DB8:
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _08021DEC
	.align 2, 0
_08021DC4: .4byte gUnknown_80DC54C
_08021DC8:
	ldr r0, _08021E04
	mov r12, r0
	ldr r4, _08021E08
	movs r3, 0
	movs r2, 0x3
_08021DD2:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	adds r1, 0xD0
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08021DD2
_08021DEC:
	bl ResetUnusedInputStruct
	ldr r0, _08021E04
	ldr r0, [r0]
	adds r0, 0xD0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021E04: .4byte gUnknown_203B290
_08021E08: .4byte gUnknown_80DC534
	thumb_func_end sub_8021D5C

	thumb_func_start sub_8021E0C
sub_8021E0C:
	push {r4,lr}
	sub sp, 0x20
	ldr r1, _08021E28
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x1C
	bls _08021E1E
	b _080222B6
_08021E1E:
	lsls r0, 2
	ldr r1, _08021E2C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021E28: .4byte gUnknown_203B290
_08021E2C: .4byte _08021E30
	.align 2, 0
_08021E30:
	.4byte _08021EA4
	.4byte _08021EC0
	.4byte _08021F38
	.4byte _08021F50
	.4byte _080222B6
	.4byte _08021F78
	.4byte _08021F90
	.4byte _08021F08
	.4byte _08021F20
	.4byte _08021FD8
	.4byte _08021FE2
	.4byte _08021FF0
	.4byte _0802208E
	.4byte _080220B8
	.4byte _080220D8
	.4byte _080220EA
	.4byte _08022080
	.4byte _08022024
	.4byte _08021FA8
	.4byte _08021FC0
	.4byte _08022138
	.4byte _08022150
	.4byte _08022168
	.4byte _08022176
	.4byte _0802217E
	.4byte _08022238
	.4byte _08022250
	.4byte _08022268
	.4byte _08022294
_08021EA4:
	bl sub_80222C8
	ldr r2, _08021EB8
	ldr r0, _08021EBC
	ldr r4, [r0]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	b _08021ED4
	.align 2, 0
_08021EB8: .4byte gWigglytuffDialogue
_08021EBC: .4byte gUnknown_203B290
_08021EC0:
	bl sub_80222C8
	ldr r2, _08021F00
	ldr r0, _08021F04
	ldr r4, [r0]
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4
_08021ED4:
	adds r0, r2
	ldr r0, [r0]
	ldr r2, [r4, 0x14]
	adds r3, r4, 0
	adds r3, 0x1C
	adds r1, r4, 0
	adds r1, 0x5C
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	adds r1, r4, 0
	adds r1, 0xCC
	ldr r1, [r1]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _080222B6
	.align 2, 0
_08021F00: .4byte gWigglytuffDialogue
_08021F04: .4byte gUnknown_203B290
_08021F08:
	ldr r3, [r4]
	movs r0, 0x9
	str r0, [r3, 0x8]
	ldr r2, _08021F1C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0xC
	b _0802227A
	.align 2, 0
_08021F1C: .4byte gWigglytuffDialogue
_08021F20:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021F34
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x10
	b _0802227A
	.align 2, 0
_08021F34: .4byte gWigglytuffDialogue
_08021F38:
	ldr r3, [r4]
	movs r0, 0x1
	str r0, [r3, 0x8]
	ldr r2, _08021F4C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x4C
	b _0802227A
	.align 2, 0
_08021F4C: .4byte gWigglytuffDialogue
_08021F50:
	ldr r3, [r4]
	movs r0, 0x4
	str r0, [r3, 0x8]
	ldr r2, _08021F70
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x8
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
	ldr r3, _08021F74
	b _08022284
	.align 2, 0
_08021F70: .4byte gWigglytuffDialogue
_08021F74: .4byte 0x0000030d
_08021F78:
	ldr r3, [r4]
	movs r0, 0x3
	str r0, [r3, 0x8]
	ldr r2, _08021F8C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x20
	b _0802227A
	.align 2, 0
_08021F8C: .4byte gWigglytuffDialogue
_08021F90:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021FA4
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x24
	b _0802227A
	.align 2, 0
_08021FA4: .4byte gWigglytuffDialogue
_08021FA8:
	ldr r3, [r4]
	movs r0, 0x3
	str r0, [r3, 0x8]
	ldr r2, _08021FBC
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x28
	b _0802227A
	.align 2, 0
_08021FBC: .4byte gWigglytuffDialogue
_08021FC0:
	ldr r3, [r4]
	movs r0, 0xA
	str r0, [r3, 0x8]
	ldr r2, _08021FD4
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x2C
	b _0802227A
	.align 2, 0
_08021FD4: .4byte gWigglytuffDialogue
_08021FD8:
	movs r0, 0x2
	movs r1, 0x3
	bl sub_80211AC
	b _08021FE8
_08021FE2:
	movs r0, 0x1
	bl sub_8021354
_08021FE8:
	movs r0, 0x1
	bl sub_8016C40
	b _080222B6
_08021FF0:
	bl sub_8021494
	movs r0, 0x1
	bl sub_8016C40
	bl sub_8022380
	ldr r0, _08022020
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	adds r1, r2, 0
	adds r1, 0x1C
	adds r3, r2, 0
	adds r3, 0x5C
	ldr r2, [r2, 0x18]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080222B6
	.align 2, 0
_08022020: .4byte gUnknown_203B290
_08022024:
	bl sub_8022420
	ldr r0, _08022070
	ldr r4, _08022074
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r1, _08022078
	ldr r4, [r4]
	ldr r0, [r4, 0xC]
	str r0, [r1]
	ldr r2, _0802207C
	ldr r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x14
	adds r0, r2
	ldr r0, [r0]
	adds r3, r4, 0
	adds r3, 0x1C
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	adds r4, 0xCC
	ldr r1, [r4]
	str r1, [sp, 0xC]
	movs r1, 0xC
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x5
	bl sub_8014248
	b _080222B6
	.align 2, 0
_08022070: .4byte gUnknown_202E628
_08022074: .4byte gUnknown_203B290
_08022078: .4byte gUnknown_202DE30
_0802207C: .4byte gWigglytuffDialogue
_08022080:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	movs r1, 0
	movs r2, 0x2
	bl sub_8021774
	b _080222B6
_0802208E:
	ldr r1, [r4]
	movs r0, 0xD
	str r0, [r1, 0x8]
	ldr r0, _080220B0
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r2, _080220B4
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x18
	b _0802227A
	.align 2, 0
_080220B0: .4byte gUnknown_202E628
_080220B4: .4byte gWigglytuffDialogue
_080220B8:
	ldr r1, [r4]
	movs r0, 0xE
	str r0, [r1, 0x8]
	ldr r0, _080220D4
	bl sub_8011988
	ldr r0, [r4]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	str r1, [r0]
	b _080222B6
	.align 2, 0
_080220D4: .4byte 0x0000025b
_080220D8:
	ldr r0, [r4]
	movs r1, 0xF
	str r1, [r0, 0x8]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1E
	str r1, [r0]
	b _080222B6
_080220EA:
	movs r0, 0x2
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _08022108
	bl sub_80213A0
	ldr r0, _08022104
	ldr r1, [r0]
	movs r0, 0x12
	b _0802210E
	.align 2, 0
_08022104: .4byte gUnknown_203B290
_08022108:
	ldr r0, _08022130
	ldr r1, [r0]
	movs r0, 0x8
_0802210E:
	str r0, [r1, 0x8]
	movs r0, 0xCE
	bl sub_8011988
	ldr r3, _08022134
	ldr r0, _08022130
	ldr r2, [r0]
	ldr r1, [r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r3, 0x1C
	adds r0, r3
	ldr r0, [r0]
	adds r2, 0xCC
	ldr r2, [r2]
	b _08022282
	.align 2, 0
_08022130: .4byte gUnknown_203B290
_08022134: .4byte gWigglytuffDialogue
_08022138:
	ldr r3, [r4]
	movs r0, 0x16
	str r0, [r3, 0x8]
	ldr r2, _0802214C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x30
	b _0802227A
	.align 2, 0
_0802214C: .4byte gWigglytuffDialogue
_08022150:
	ldr r3, [r4]
	movs r0, 0x17
	str r0, [r3, 0x8]
	ldr r2, _08022164
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x34
	b _0802227A
	.align 2, 0
_08022164: .4byte gWigglytuffDialogue
_08022168:
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_8023144
	b _080222B6
_08022176:
	movs r0, 0x1
	bl sub_8023354
	b _080222B6
_0802217E:
	ldr r4, _080221A0
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	add r1, sp, 0x14
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	add r0, sp, 0x14
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080221A4
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x8]
	b _080221FA
	.align 2, 0
_080221A0: .4byte gUnknown_203B290
_080221A4:
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl GetFriendAreaUnlockCondition
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080221E0
	cmp r0, 0x2
	bgt _080221BE
	cmp r0, 0x1
	beq _080221C4
	b _080221F0
_080221BE:
	cmp r0, 0x3
	beq _080221E8
	b _080221F0
_080221C4:
	movs r0, 0x6
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080221D8
	ldr r1, [r4]
	movs r0, 0x15
	str r0, [r1, 0x8]
	b _080221FA
_080221D8:
	ldr r1, [r4]
	movs r0, 0x1A
	str r0, [r1, 0x8]
	b _080221FA
_080221E0:
	ldr r1, [r4]
	movs r0, 0x1B
	str r0, [r1, 0x8]
	b _080221FA
_080221E8:
	ldr r1, [r4]
	movs r0, 0x1C
	str r0, [r1, 0x8]
	b _080221FA
_080221F0:
	ldr r2, _08022228
	ldr r1, [r2]
	movs r0, 0x15
	str r0, [r1, 0x8]
	adds r4, r2, 0
_080221FA:
	ldr r0, [r4]
	movs r1, 0x12
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r0, _0802222C
	bl strcpy
	ldr r0, _08022230
	ldr r1, [r4]
	ldrb r1, [r1, 0x10]
	movs r2, 0
	bl sub_8092578
	ldr r2, _08022234
	ldr r3, [r4]
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x38
	b _0802227A
	.align 2, 0
_08022228: .4byte gUnknown_203B290
_0802222C: .4byte gAvailablePokemonNames
_08022230: .4byte gUnknown_202E628
_08022234: .4byte gWigglytuffDialogue
_08022238:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _0802224C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x3C
	b _0802227A
	.align 2, 0
_0802224C: .4byte gWigglytuffDialogue
_08022250:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _08022264
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x40
	b _0802227A
	.align 2, 0
_08022264: .4byte gWigglytuffDialogue
_08022268:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _0802228C
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x44
_0802227A:
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
_08022282:
	ldr r3, _08022290
_08022284:
	movs r1, 0
	bl sub_80141B4
	b _080222B6
	.align 2, 0
_0802228C: .4byte gWigglytuffDialogue
_08022290: .4byte 0x0000010d
_08022294:
	ldr r3, [r4]
	movs r0, 0x15
	str r0, [r3, 0x8]
	ldr r2, _080222C0
	ldr r1, [r3]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 4
	adds r2, 0x48
	adds r0, r2
	ldr r0, [r0]
	adds r3, 0xCC
	ldr r2, [r3]
	ldr r3, _080222C4
	movs r1, 0
	bl sub_80141B4
_080222B6:
	add sp, 0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080222C0: .4byte gWigglytuffDialogue
_080222C4: .4byte 0x0000010d
	thumb_func_end sub_8021E0C

	thumb_func_start sub_80222C8
sub_80222C8:
	push {r4-r7,lr}
	ldr r4, _08022344
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r5, 0
	ldr r0, _08022348
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	adds r3, r1, 0
	adds r3, 0x20
	movs r0, 0x2
	str r0, [r1, 0x20]
	movs r2, 0x1
	ldr r0, _0802234C
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x3
	str r0, [r1, 0x28]
	ldr r0, _08022350
	ldr r0, [r0]
	str r0, [r1, 0x2C]
	movs r0, 0x4
	str r0, [r1, 0x30]
	ldr r0, _08022354
	ldr r0, [r0]
	str r0, [r1, 0x34]
	str r2, [r1, 0x38]
	movs r7, 0x4
	str r5, [r1, 0x3C]
	str r2, [r3, 0x20]
	adds r6, r1, 0
	adds r2, r6, 0
	adds r2, 0x5C
_08022314:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08022322
	ldr r1, [r3]
	ldr r0, [r6, 0x14]
	cmp r1, r0
	beq _0802237A
_08022322:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r7
	blt _08022314
	movs r5, 0
	cmp r5, r7
	bge _0802237A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08022358
	ldr r0, [r1, 0x20]
	str r0, [r1, 0x14]
	b _0802237A
	.align 2, 0
_08022344: .4byte gUnknown_203B290
_08022348: .4byte gUnknown_80D4978
_0802234C: .4byte gWigglytuffCheck
_08022350: .4byte gUnknown_80D4970
_08022354: .4byte gUnknown_80D4934
_08022358:
	adds r5, 0x1
	cmp r5, r7
	bge _0802237A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x5C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08022358
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x14]
_0802237A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80222C8

	thumb_func_start sub_8022380
sub_8022380:
	push {r4-r7,lr}
	ldr r4, _080223EC
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080223F0
	ldr r0, [r0]
	str r0, [r3, 0x1C]
	movs r0, 0x2
	str r0, [r3, 0x20]
	movs r1, 0x1
	ldr r0, _080223F4
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x4
	str r0, [r3, 0x28]
	movs r6, 0x2
	str r2, [r3, 0x2C]
	str r1, [r3, 0x30]
	movs r5, 0
	mov r12, r3
	adds r3, 0x20
	mov r2, r12
	adds r2, 0x5C
_080223BA:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080223CA
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _0802241A
_080223CA:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080223BA
	movs r5, 0
	cmp r5, r6
	bge _0802241A
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x5C
	ldrh r0, [r0]
	cmp r0, 0
	bne _080223F8
	ldr r0, [r1, 0x20]
	str r0, [r1, 0x18]
	b _0802241A
	.align 2, 0
_080223EC: .4byte gUnknown_203B290
_080223F0: .4byte gUnknown_80D4978
_080223F4: .4byte gUnknown_80D4970
_080223F8:
	adds r5, 0x1
	cmp r5, r6
	bge _0802241A
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x5C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080223F8
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_0802241A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022380

	thumb_func_start sub_8022420
sub_8022420:
	push {r4,lr}
	ldr r4, _08022454
	ldr r0, [r4]
	adds r0, 0x5C
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _08022458
	ldr r0, [r0]
	str r0, [r1, 0x1C]
	movs r0, 0x5
	str r0, [r1, 0x20]
	movs r2, 0x1
	ldr r0, _0802245C
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x6
	str r0, [r1, 0x28]
	str r3, [r1, 0x2C]
	str r2, [r1, 0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022454: .4byte gUnknown_203B290
_08022458: .4byte gUnknown_80D4920
_0802245C: .4byte gUnknown_80D4928
	thumb_func_end sub_8022420

	thumb_func_start sub_8022460
sub_8022460:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080224CC
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802247A
	ldr r0, _0802248C
	ldr r0, [r0]
	str r1, [r0, 0x14]
_0802247A:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0802249A
	cmp r0, 0x2
	bgt _08022490
	cmp r0, 0x1
	beq _080224C6
	b _080224CC
	.align 2, 0
_0802248C: .4byte gUnknown_203B290
_08022490:
	cmp r0, 0x3
	beq _080224B6
	cmp r0, 0x4
	beq _080224BE
	b _080224CC
_0802249A:
	movs r0, 0x2
	bl sub_8021700
	lsls r0, 24
	cmp r0, 0
	beq _080224AE
	movs r0, 0x5
	bl sub_8021D44
	b _080224CC
_080224AE:
	movs r0, 0x7
	bl sub_8021D44
	b _080224CC
_080224B6:
	movs r0, 0x14
	bl sub_8021D44
	b _080224CC
_080224BE:
	movs r0, 0x2
	bl sub_8021D44
	b _080224CC
_080224C6:
	movs r0, 0x3
	bl sub_8021D44
_080224CC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8022460

	thumb_func_start sub_80224D4
sub_80224D4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08022532
	ldr r0, [sp]
	cmp r0, 0x5
	beq _080224F8
	cmp r0, 0x5
	bgt _080224F2
	cmp r0, 0x1
	beq _0802252C
	b _08022532
_080224F2:
	cmp r0, 0x6
	beq _0802252C
	b _08022532
_080224F8:
	ldr r0, _08022524
	ldr r2, [r0]
	movs r0, 0x98
	lsls r0, 2
	adds r2, r0
	ldr r0, _08022528
	ldr r3, [r0]
	ldr r0, [r2]
	ldr r1, [r3, 0xC]
	subs r0, r1
	str r0, [r2]
	ldrb r0, [r3, 0x10]
	bl UnlockFriendArea
	movs r0, 0xA6
	lsls r0, 1
	bl sub_8011988
	movs r0, 0xC
	bl sub_8021D44
	b _08022532
	.align 2, 0
_08022524: .4byte gUnknown_203B460
_08022528: .4byte gUnknown_203B290
_0802252C:
	movs r0, 0xA
	bl sub_8021D44
_08022532:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80224D4

	thumb_func_start sub_8022538
sub_8022538:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8021274
	cmp r0, 0x4
	bhi _080225BC
	lsls r0, 2
	ldr r1, _08022550
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022550: .4byte _08022554
	.align 2, 0
_08022554:
	.4byte _080225C2
	.4byte _080225BC
	.4byte _080225B0
	.4byte _08022568
	.4byte _0802258C
_08022568:
	bl sub_802132C
	ldr r4, _08022588
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl GetFriendAreaPrice
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0xB
	bl sub_8021D44
	b _080225C2
	.align 2, 0
_08022588: .4byte gUnknown_203B290
_0802258C:
	bl sub_802132C
	ldr r4, _080225AC
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	bl GetFriendAreaPrice
	ldr r1, [r4]
	str r0, [r1, 0xC]
	movs r0, 0x10
	bl sub_8021D44
	b _080225C2
	.align 2, 0
_080225AC: .4byte gUnknown_203B290
_080225B0:
	bl sub_80213A0
	movs r0, 0x1
	bl sub_8021D44
	b _080225C2
_080225BC:
	movs r0, 0x1
	bl sub_8016C40
_080225C2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022538

	thumb_func_start sub_80225C8
sub_80225C8:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8021274
	ldr r4, _08022608
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080225F8
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080225F8
	ldr r0, [r4]
	str r1, [r0, 0x18]
_080225F8:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08022612
	cmp r0, 0x2
	bgt _0802260C
	cmp r0, 0x1
	beq _08022658
	b _0802265E
	.align 2, 0
_08022608: .4byte gUnknown_203B290
_0802260C:
	cmp r0, 0x4
	beq _08022650
	b _0802265E
_08022612:
	ldr r0, _0802262C
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08022630
	movs r0, 0x6
	bl sub_8021D44
	b _0802265E
	.align 2, 0
_0802262C: .4byte gUnknown_203B460
_08022630:
	ldr r0, _08022644
	ldr r0, [r0]
	ldr r0, [r0, 0xC]
	cmp r0, r1
	ble _08022648
	movs r0, 0x13
	bl sub_8021D44
	b _0802265E
	.align 2, 0
_08022644: .4byte gUnknown_203B290
_08022648:
	movs r0, 0x11
	bl sub_8021D44
	b _0802265E
_08022650:
	movs r0, 0x10
	bl sub_8021D44
	b _0802265E
_08022658:
	movs r0, 0xA
	bl sub_8021D44
_0802265E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80225C8

	thumb_func_start sub_8022668
sub_8022668:
	push {lr}
	bl sub_80217EC
	cmp r0, 0x1
	bls _08022680
	cmp r0, 0x3
	bhi _08022680
	bl sub_8021830
	movs r0, 0xA
	bl sub_8021D44
_08022680:
	pop {r0}
	bx r0
	thumb_func_end sub_8022668

	thumb_func_start sub_8022684
sub_8022684:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023278
	cmp r0, 0x2
	beq _080226BC
	cmp r0, 0x2
	bcc _080226C6
	cmp r0, 0x3
	bne _080226C6
	bl sub_802331C
	ldr r4, _080226B8
	ldr r1, [r4]
	strh r0, [r1, 0x12]
	movs r2, 0x12
	ldrsh r0, [r1, r2]
	bl GetFriendArea
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	movs r0, 0x18
	bl sub_8021D44
	b _080226C6
	.align 2, 0
_080226B8: .4byte gUnknown_203B290
_080226BC:
	bl sub_80233A0
	movs r0, 0x1
	bl sub_8021D44
_080226C6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8022684

	thumb_func_start sub_80226CC
sub_80226CC:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080226E4
	ldr r0, _080226EC
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8021D44
_080226E4:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_080226EC: .4byte gUnknown_203B290
	thumb_func_end sub_80226CC

	thumb_func_start sub_80226F0
sub_80226F0:
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0
	movs r0, 0x80
	strb r0, [r1]
	strb r0, [r1, 0x1]
	movs r0, 0x10
	strb r0, [r1, 0x2]
	strb r2, [r1, 0x3]
	bl sub_8099B94
	lsls r0, 24
	cmp r0, 0
	bne _08022782
	ldr r0, _08022728
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0802275C
	lsls r0, 2
	ldr r1, _0802272C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022728: .4byte gUnknown_203B290
_0802272C: .4byte _08022730
	.align 2, 0
_08022730:
	.4byte _0802275C
	.4byte _08022744
	.4byte _08022750
	.4byte _08022744
	.4byte _08022750
_08022744:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099AFC
	b _08022772
_08022750:
	movs r0, 0x5
	movs r1, 0x2
	ldr r2, [sp]
	bl sub_8099A5C
	b _08022772
_0802275C:
	ldr r4, _0802278C
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	bl sub_8021D44
	ldr r0, [r4]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_08022772:
	ldr r0, _0802278C
	ldr r1, [r0]
	movs r0, 0x98
	lsls r0, 1
	adds r1, r0
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08022782:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802278C: .4byte gUnknown_203B290
	thumb_func_end sub_80226F0

	thumb_func_start sub_8022790
sub_8022790:
	push {lr}
	ldr r0, _080227A8
	ldr r2, [r0]
	movs r0, 0x9A
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, [r1]
	cmp r0, 0
	beq _080227AC
	subs r0, 0x1
	str r0, [r1]
	b _080227B2
	.align 2, 0
_080227A8: .4byte gUnknown_203B290
_080227AC:
	ldr r0, [r2, 0x8]
	bl sub_8021D44
_080227B2:
	pop {r0}
	bx r0
	thumb_func_end sub_8022790

	thumb_func_start sub_80227B8
sub_80227B8:
	push {r4,r5,lr}
	adds r5, r0, 0
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, _08022810
	movs r0, 0xD4
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	adds r2, r0, 0
	adds r2, 0xF4
	movs r1, 0
	str r1, [r2]
	str r5, [r0, 0x48]
	cmp r5, 0
	beq _08022820
	ldr r4, _08022814
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x6
	bl sub_808D9AC
	bl sub_809177C
	lsls r0, 24
	cmp r0, 0
	beq _08022818
	movs r0, 0
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022810: .4byte gUnknown_203B294
_08022814: .4byte gAvailablePokemonNames
_08022818:
	movs r0, 0x11
	bl sub_8022924
	b _08022856
_08022820:
	ldr r4, _08022848
	ldr r5, _0802284C
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	adds r4, 0x50
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcpy
	bl sub_8090A34
	cmp r0, 0
	bne _08022850
	movs r0, 0x12
	bl sub_8022924
	b _08022856
	.align 2, 0
_08022848: .4byte gAvailablePokemonNames
_0802284C: .4byte gUnknown_80DC5EC
_08022850:
	movs r0, 0
	bl sub_8022924
_08022856:
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80227B8

	thumb_func_start sub_8022860
sub_8022860:
	push {lr}
	ldr r0, _08022878
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x16
	bhi _080228FE
	lsls r0, 2
	ldr r1, _0802287C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022878: .4byte gUnknown_203B294
_0802287C: .4byte _08022880
	.align 2, 0
_08022880:
	.4byte _080228DC
	.4byte _080228DC
	.4byte _080228E2
	.4byte _080228E8
	.4byte _080228EE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228FE
	.4byte _080228F4
	.4byte _080228FA
_080228DC:
	bl sub_8022E78
	b _08022902
_080228E2:
	bl sub_8022EF4
	b _08022902
_080228E8:
	bl sub_8023068
	b _08022902
_080228EE:
	bl sub_80230E8
	b _08022902
_080228F4:
	bl sub_8023104
	b _08022902
_080228FA:
	movs r0, 0x3
	b _08022904
_080228FE:
	bl sub_8023120
_08022902:
	movs r0, 0
_08022904:
	pop {r1}
	bx r1
	thumb_func_end sub_8022860

	thumb_func_start sub_8022908
sub_8022908:
	push {r4,lr}
	ldr r4, _08022920
	ldr r0, [r4]
	cmp r0, 0
	beq _0802291A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802291A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08022920: .4byte gUnknown_203B294
	thumb_func_end sub_8022908

	thumb_func_start sub_8022924
sub_8022924:
	push {lr}
	ldr r1, _08022938
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802293C
	bl sub_8022A10
	pop {r0}
	bx r0
	.align 2, 0
_08022938: .4byte gUnknown_203B294
	thumb_func_end sub_8022924

	thumb_func_start sub_802293C
sub_802293C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _08022964
	ldr r0, [r4]
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _080229A4
	cmp r0, 0x3
	bgt _08022968
	cmp r0, 0x2
	beq _08022972
	b _080229BC
	.align 2, 0
_08022964: .4byte gUnknown_203B294
_08022968:
	cmp r0, 0x10
	bgt _080229BC
	cmp r0, 0xA
	blt _080229BC
	b _080229E6
_08022972:
	bl sub_8022D2C
	ldr r2, [r4]
	movs r0, 0xBC
	lsls r0, 1
	adds r2, r0
	ldr r1, _080229A0
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xF8
	bl sub_8012CAC
	ldr r0, [r4]
	movs r6, 0xC2
	lsls r6, 1
	adds r0, r6
	movs r1, 0x6
	strh r1, [r0]
	b _080229E6
	.align 2, 0
_080229A0: .4byte gUnknown_80DC5BC
_080229A4:
	movs r7, 0xB0
	lsls r7, 1
	adds r1, r7
	ldr r0, _080229B8
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _080229E6
	.align 2, 0
_080229B8: .4byte gUnknown_80DC5D4
_080229BC:
	ldr r0, _08022A08
	mov r12, r0
	movs r1, 0xA4
	lsls r1, 1
	mov r8, r1
	ldr r4, _08022A0C
	movs r3, 0
	movs r2, 0x3
_080229CC:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080229CC
_080229E6:
	bl ResetUnusedInputStruct
	ldr r0, _08022A08
	ldr r0, [r0]
	movs r6, 0xA4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022A08: .4byte gUnknown_203B294
_08022A0C: .4byte gUnknown_80DC5A4
	thumb_func_end sub_802293C

	thumb_func_start sub_8022A10
sub_8022A10:
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, _08022A2C
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x16
	bls _08022A22
	b _08022D1E
_08022A22:
	lsls r0, 2
	ldr r1, _08022A30
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022A2C: .4byte gUnknown_203B294
_08022A30: .4byte _08022A34
	.align 2, 0
_08022A34:
	.4byte _08022A90
	.4byte _08022AAA
	.4byte _08022AB2
	.4byte _08022AE0
	.4byte _08022B10
	.4byte _08022B1A
	.4byte _08022B24
	.4byte _08022B34
	.4byte _08022B44
	.4byte _08022B54
	.4byte _08022B64
	.4byte _08022C28
	.4byte _08022CA0
	.4byte _08022CA8
	.4byte _08022CB0
	.4byte _08022CB8
	.4byte _08022CC0
	.4byte _08022CC8
	.4byte _08022CD8
	.4byte _08022CE8
	.4byte _08022CF8
	.4byte _08022D14
	.4byte _08022D1E
_08022A90:
	ldr r0, [r4]
	ldr r0, [r0, 0x48]
	cmp r0, 0
	beq _08022A9C
	movs r0, 0x5
	b _08022A9E
_08022A9C:
	movs r0, 0x1
_08022A9E:
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08022D22
_08022AAA:
	movs r0, 0x1
	bl sub_801A8D0
	b _08022D22
_08022AB2:
	bl sub_801A9E0
	ldr r0, _08022ADC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x54
	adds r1, r2, 0
	adds r1, 0xF8
	movs r4, 0x9C
	lsls r4, 1
	adds r3, r2, r4
	adds r2, 0xF4
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022ADC: .4byte gUnknown_203B294
_08022AE0:
	bl sub_801A9E0
	ldr r4, _08022B08
	ldr r0, [r4]
	adds r0, 0x54
	movs r1, 0
	bl sub_8012EA4
	ldr r0, [r4]
	adds r0, 0xA4
	ldr r1, _08022B0C
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _08022D22
	.align 2, 0
_08022B08: .4byte gUnknown_203B294
_08022B0C: .4byte gUnknown_80DC584
_08022B10:
	ldr r0, [r4]
	adds r0, 0x50
	bl sub_801B3C0
	b _08022D22
_08022B1A:
	ldr r0, _08022B20
	b _08022D00
	.align 2, 0
_08022B20: .4byte gUnknown_80DC5F4
_08022B24:
	ldr r0, _08022B2C
	ldr r3, _08022B30
	b _08022D02
	.align 2, 0
_08022B2C: .4byte gUnknown_80DC618
_08022B30: .4byte 0x00000101
_08022B34:
	ldr r0, _08022B3C
	ldr r3, _08022B40
	b _08022D02
	.align 2, 0
_08022B3C: .4byte gUnknown_80DC674
_08022B40: .4byte 0x00000101
_08022B44:
	ldr r0, _08022B4C
	ldr r3, _08022B50
	b _08022D02
	.align 2, 0
_08022B4C: .4byte gUnknown_80DC6CC
_08022B50: .4byte 0x00000101
_08022B54:
	ldr r0, _08022B5C
	ldr r3, _08022B60
	b _08022D02
	.align 2, 0
_08022B5C: .4byte gUnknown_80DC728
_08022B60: .4byte 0x00000101
_08022B64:
	ldr r7, _08022B68
	b _08022B78
	.align 2, 0
_08022B68: .4byte gUnknown_203B294
_08022B6C:
	ldr r1, [r4]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	cmp r0, 0x17
	bgt _08022C10
_08022B78:
	movs r5, 0
	movs r6, 0
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r5, r0
	bge _08022BA4
	ldrb r1, [r2, 0x8]
	b _08022B9C
_08022B8A:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x38]
	cmp r3, r0
	bge _08022BA4
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r3
	ldrb r1, [r0]
_08022B9C:
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022B8A
	movs r5, 0x1
_08022BA4:
	movs r3, 0
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	b _08022BC4
_08022BB4:
	adds r3, 0x1
	ldr r2, [r4]
	ldr r0, [r2, 0x3C]
	cmp r3, r0
	bge _08022BCE
	adds r0, r2, 0
	adds r0, 0x20
	adds r0, r3
_08022BC4:
	ldrb r1, [r0]
	ldr r0, [r2, 0x40]
	cmp r1, r0
	bne _08022BB4
	movs r6, 0x1
_08022BCE:
	cmp r5, r6
	beq _08022B6C
	ldr r1, [r7]
	movs r0, 0xA
	str r0, [r1, 0x4]
	ldr r0, [r1, 0x40]
	lsls r0, 24
	lsrs r0, 24
	bl sub_808EAB0
	adds r1, r0, 0
	ldr r0, _08022C18
	bl strcpy
	movs r0, 0xCB
	bl sub_8011988
	ldr r0, _08022C1C
	movs r1, 0
	movs r2, 0
	ldr r3, _08022C20
	bl sub_80141B4
	ldr r1, [r7]
	ldr r0, [r1, 0x40]
	adds r0, 0x1
	str r0, [r1, 0x40]
	ldr r0, _08022C24
	ldr r0, [r0]
	ldr r0, [r0, 0x40]
	cmp r0, 0x17
	bgt _08022C10
	b _08022D22
_08022C10:
	movs r0, 0xB
	bl sub_8022924
	b _08022D22
	.align 2, 0
_08022C18: .4byte gUnknown_202DEA8
_08022C1C: .4byte gUnknown_80DC788
_08022C20: .4byte 0x00000101
_08022C24: .4byte gUnknown_203B294
_08022C28:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	bl nullsub_104
	ldr r0, [r4]
	adds r0, 0x46
	ldrh r0, [r0]
	cmp r0, 0x8
	bhi _08022C98
	lsls r0, 2
	ldr r1, _08022C48
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022C48: .4byte _08022C4C
	.align 2, 0
_08022C4C:
	.4byte _08022C70
	.4byte _08022C78
	.4byte _08022C80
	.4byte _08022C98
	.4byte _08022C88
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C98
	.4byte _08022C90
_08022C70:
	movs r0, 0x16
	bl sub_8022924
	b _08022D22
_08022C78:
	movs r0, 0xD
	bl sub_8022924
	b _08022D22
_08022C80:
	movs r0, 0xE
	bl sub_8022924
	b _08022D22
_08022C88:
	movs r0, 0xF
	bl sub_8022924
	b _08022D22
_08022C90:
	movs r0, 0x10
	bl sub_8022924
	b _08022D22
_08022C98:
	movs r0, 0xC
	bl sub_8022924
	b _08022D22
_08022CA0:
	ldr r0, _08022CA4
	b _08022D00
	.align 2, 0
_08022CA4: .4byte gUnknown_80DC7B4
_08022CA8:
	ldr r0, _08022CAC
	b _08022D00
	.align 2, 0
_08022CAC: .4byte gUnknown_80DC7FC
_08022CB0:
	ldr r0, _08022CB4
	b _08022D00
	.align 2, 0
_08022CB4: .4byte gUnknown_80DC81C
_08022CB8:
	ldr r0, _08022CBC
	b _08022D00
	.align 2, 0
_08022CBC: .4byte gUnknown_80DC844
_08022CC0:
	ldr r0, _08022CC4
	b _08022D00
	.align 2, 0
_08022CC4: .4byte gUnknown_80DC864
_08022CC8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CD4
	b _08022D00
	.align 2, 0
_08022CD4: .4byte gUnknown_80DC88C
_08022CD8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CE4
	b _08022D00
	.align 2, 0
_08022CE4: .4byte gUnknown_80DC8AC
_08022CE8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022CF4
	b _08022D00
	.align 2, 0
_08022CF4: .4byte gUnknown_80DC8C8
_08022CF8:
	ldr r1, [r4]
	movs r0, 0x16
	str r0, [r1, 0x4]
	ldr r0, _08022D0C
_08022D00:
	ldr r3, _08022D10
_08022D02:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08022D22
	.align 2, 0
_08022D0C: .4byte gUnknown_80DC8DC
_08022D10: .4byte 0x00000301
_08022D14:
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_801AFA4
	b _08022D22
_08022D1E:
	bl sub_801A928
_08022D22:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022A10

	thumb_func_start sub_8022D2C
sub_8022D2C:
	push {r4-r7,lr}
	movs r6, 0
	ldr r4, _08022D78
	ldr r0, [r4]
	movs r1, 0x9C
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r2, [r4]
	ldr r0, [r2, 0x48]
	cmp r0, 0
	beq _08022D80
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r0, _08022D7C
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	adds r0, r2, 0
	adds r0, 0x52
	ldrb r0, [r0]
	bl sub_8091764
	lsls r0, 24
	cmp r0, 0
	bne _08022D74
	ldr r0, [r4]
	movs r2, 0x9C
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0]
_08022D74:
	movs r6, 0x1
	b _08022DBE
	.align 2, 0
_08022D78: .4byte gUnknown_203B294
_08022D7C: .4byte gUnknown_80DC8F0
_08022D80:
	adds r0, r2, 0
	adds r0, 0x52
	ldrb r0, [r0]
	bl sub_8090BD0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bne _08022DA4
	ldr r1, [r4]
	adds r2, r1, 0
	adds r2, 0xF8
	ldr r0, _08022E38
	str r0, [r2]
	adds r1, 0xFC
	movs r0, 0x6
	str r0, [r1]
	movs r6, 0x1
_08022DA4:
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xF8
	adds r0, r3
	ldr r1, _08022E3C
	ldr r1, [r1]
	str r1, [r0]
	adds r2, 0xFC
	adds r2, r3
	movs r0, 0x4
	str r0, [r2]
	adds r6, 0x1
_08022DBE:
	ldr r4, _08022E40
	ldr r0, [r4]
	mov r12, r0
	lsls r1, r6, 3
	mov r2, r12
	adds r2, 0xF8
	adds r3, r2, r1
	ldr r0, _08022E44
	ldr r0, [r0]
	str r0, [r3]
	mov r3, r12
	adds r3, 0xFC
	adds r1, r3, r1
	movs r0, 0x7
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r1
	movs r0, 0
	str r0, [r2]
	adds r1, r3, r1
	movs r0, 0x1
	str r0, [r1]
	movs r5, 0
	adds r7, r4, 0
	cmp r5, r6
	bge _08022E16
	mov r4, r12
	adds r4, 0xF4
	movs r2, 0x9C
	lsls r2, 1
	add r2, r12
_08022DFE:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08022E0C
	ldr r1, [r3]
	ldr r0, [r4]
	cmp r1, r0
	beq _08022E70
_08022E0C:
	adds r2, 0x2
	adds r3, 0x8
	adds r5, 0x1
	cmp r5, r6
	blt _08022DFE
_08022E16:
	movs r5, 0
	cmp r5, r6
	bge _08022E70
	ldr r1, [r7]
	movs r2, 0x9C
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _08022E48
	adds r0, r1, 0
	adds r0, 0xF4
	adds r1, 0xFC
	ldr r1, [r1]
	str r1, [r0]
	b _08022E70
	.align 2, 0
_08022E38: .4byte gUnknown_80DC8F8
_08022E3C: .4byte gUnknown_80D4940
_08022E40: .4byte gUnknown_203B294
_08022E44: .4byte gUnknown_80D4970
_08022E48:
	adds r5, 0x1
	cmp r5, r6
	bge _08022E70
	ldr r3, [r7]
	lsls r0, r5, 1
	movs r2, 0x9C
	lsls r2, 1
	adds r1, r3, r2
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08022E48
	adds r2, r3, 0
	adds r2, 0xF4
	lsls r1, r5, 3
	adds r0, r3, 0
	adds r0, 0xFC
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
_08022E70:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8022D2C

	thumb_func_start sub_8022E78
sub_8022E78:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08022E94
	cmp r0, 0x3
	bhi _08022E8E
	cmp r0, 0x2
	beq _08022EE8
	b _08022EEE
_08022E8E:
	cmp r0, 0x4
	beq _08022EBC
	b _08022EEE
_08022E94:
	bl sub_801A8AC
	ldr r1, _08022EB4
	ldr r2, [r1]
	str r0, [r2, 0x4C]
	ldr r1, _08022EB8
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x50]
	movs r0, 0x2
	bl sub_8022924
	b _08022EEE
	.align 2, 0
_08022EB4: .4byte gUnknown_203B294
_08022EB8: .4byte gUnknown_203B460
_08022EBC:
	bl sub_801A8AC
	ldr r1, _08022EE0
	ldr r2, [r1]
	str r0, [r2, 0x4C]
	ldr r1, _08022EE4
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x50]
	movs r0, 0
	bl sub_8099690
	movs r0, 0x4
	bl sub_8022924
	b _08022EEE
	.align 2, 0
_08022EE0: .4byte gUnknown_203B294
_08022EE4: .4byte gUnknown_203B460
_08022EE8:
	movs r0, 0x16
	bl sub_8022924
_08022EEE:
	pop {r0}
	bx r0
	thumb_func_end sub_8022E78

	thumb_func_start sub_8022EF4
sub_8022EF4:
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08022F3C
	ldr r0, [r4]
	adds r0, 0x54
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08022F26
	ldr r0, [r4]
	adds r0, 0x54
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08022F26
	ldr r0, [r4]
	adds r0, 0xF4
	str r1, [r0]
_08022F26:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bls _08022F30
	b _08023060
_08022F30:
	lsls r0, 2
	ldr r1, _08022F40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022F3C: .4byte gUnknown_203B294
_08022F40: .4byte _08022F44
	.align 2, 0
_08022F44:
	.4byte _08022F60
	.4byte _08023060
	.4byte _08023060
	.4byte _0802304C
	.4byte _08022F68
	.4byte _08023044
	.4byte _08023054
_08022F60:
	movs r0, 0x1
	bl sub_8022924
	b _08023060
_08022F68:
	ldr r4, _08022FEC
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x8
	ldr r1, [r1, 0x48]
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	ldr r3, [r4]
	str r0, [r3, 0x38]
	ldr r0, [r3, 0x48]
	adds r1, r3, 0
	adds r1, 0x52
	ldrb r1, [r1]
	adds r3, 0x44
	movs r2, 0
	bl sub_80915F4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x20
	ldr r1, [r1, 0x48]
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	ldr r1, [r4]
	str r0, [r1, 0x3C]
	movs r0, 0x1
	str r0, [r1, 0x40]
	adds r0, r1, 0
	adds r0, 0x44
	movs r2, 0
	ldrsh r5, [r0, r2]
	ldr r0, _08022FF0
	ldr r3, _08022FF4
	ldr r2, [r1, 0x4C]
	lsls r2, 2
	ldr r1, [r3]
	adds r1, r2
	movs r2, 0
	bl sub_8090E14
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _08022FD0
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_80911F8
_08022FD0:
	movs r0, 0
	bl sub_8099690
	ldr r1, [r4]
	movs r0, 0xA
	str r0, [r1, 0x4]
	adds r0, r5, 0x1
	cmp r0, 0x4
	bhi _08023030
	lsls r0, 2
	ldr r1, _08022FF8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08022FEC: .4byte gUnknown_203B294
_08022FF0: .4byte gUnknown_202DE58
_08022FF4: .4byte gUnknown_203B460
_08022FF8: .4byte _08022FFC
	.align 2, 0
_08022FFC:
	.4byte _08023030
	.4byte _08023010
	.4byte _08023018
	.4byte _08023020
	.4byte _08023028
_08023010:
	movs r0, 0x6
	bl sub_8022924
	b _08023060
_08023018:
	movs r0, 0x7
	bl sub_8022924
	b _08023060
_08023020:
	movs r0, 0x8
	bl sub_8022924
	b _08023060
_08023028:
	movs r0, 0x9
	bl sub_8022924
	b _08023060
_08023030:
	ldr r0, _08023040
	ldr r1, [r0]
	movs r0, 0x16
	str r0, [r1, 0x4]
	movs r0, 0x5
	bl sub_8022924
	b _08023060
	.align 2, 0
_08023040: .4byte gUnknown_203B294
_08023044:
	movs r0, 0x15
	bl sub_8022924
	b _08023060
_0802304C:
	movs r0, 0x3
	bl sub_8022924
	b _08023060
_08023054:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x4
	bl sub_8022924
_08023060:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8022EF4

	thumb_func_start sub_8023068
sub_8023068:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _080230A8
	ldr r0, [r4]
	adds r0, 0x54
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xA4
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08023096
	ldr r0, [r4]
	adds r0, 0xA4
	mov r1, sp
	bl sub_8013114
_08023096:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080230B8
	cmp r0, 0x2
	bgt _080230AC
	cmp r0, 0x1
	beq _080230B0
	b _080230E0
	.align 2, 0
_080230A8: .4byte gUnknown_203B294
_080230AC:
	cmp r0, 0x3
	bne _080230E0
_080230B0:
	movs r0, 0x1
	bl sub_8022924
	b _080230E0
_080230B8:
	ldr r0, [r4]
	ldr r0, [r0, 0x4C]
	bl sub_80911F8
	bl sub_8090A34
	cmp r0, 0
	bne _080230DA
	movs r0, 0
	bl sub_8099690
	bl sub_801A928
	movs r0, 0x14
	bl sub_8022924
	b _080230E0
_080230DA:
	movs r0, 0x1
	bl sub_8022924
_080230E0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8023068

	thumb_func_start sub_80230E8
sub_80230E8:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08023100
	cmp r0, 0x3
	bhi _08023100
	bl sub_801B450
	movs r0, 0x1
	bl sub_8022924
_08023100:
	pop {r0}
	bx r0
	thumb_func_end sub_80230E8

	thumb_func_start sub_8023104
sub_8023104:
	push {lr}
	bl sub_801B00C
	cmp r0, 0x1
	bls _0802311C
	cmp r0, 0x3
	bhi _0802311C
	bl sub_801B048
	movs r0, 0x1
	bl sub_8022924
_0802311C:
	pop {r0}
	bx r0
	thumb_func_end sub_8023104

	thumb_func_start sub_8023120
sub_8023120:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08023138
	ldr r0, _08023140
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_8022924
_08023138:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08023140: .4byte gUnknown_203B294
	thumb_func_end sub_8023120

	thumb_func_start sub_8023144
sub_8023144:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r1, 0
	mov r9, r2
	mov r10, r3
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl sub_8023704
	lsls r0, 24
	cmp r0, 0
	beq _08023168
	movs r0, 0
	b _08023252
_08023168:
	ldr r6, _08023260
	ldr r0, [r6]
	cmp r0, 0
	bne _0802317C
	movs r0, 0xFF
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
_0802317C:
	ldr r0, [r6]
	strb r4, [r0]
	ldr r0, [r6]
	ldr r1, _08023264
	ldr r1, [r1]
	str r1, [r0, 0x4]
	movs r4, 0xE4
	lsls r4, 2
	adds r1, r0, r4
	str r7, [r1]
	movs r1, 0xE5
	lsls r1, 2
	mov r8, r1
	adds r2, r0, r1
	lsls r1, r7, 1
	adds r1, r7
	lsls r1, 3
	movs r5, 0xE6
	lsls r5, 2
	adds r1, r5
	adds r1, r0, r1
	str r1, [r2]
	adds r0, r5
	bl sub_8006518
	ldr r1, [r6]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r5
	ldr r0, _08023268
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	mov r1, r8
	adds r0, r2, r1
	ldr r1, [r0]
	movs r3, 0xFE
	lsls r3, 2
	adds r0, r2, r3
	str r0, [r1, 0x14]
	mov r4, r9
	cmp r4, 0
	beq _080231F6
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	subs r3, 0x58
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_080231F6:
	ldr r0, [r6]
	add r0, r8
	ldr r0, [r0]
	mov r1, r10
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r6]
	adds r0, r5
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r6]
	movs r5, 0xD7
	lsls r5, 2
	adds r4, r5
	bl sub_80236A4
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r10
	adds r3, r7, 0
	bl sub_8013818
	ldr r0, [r6]
	ldr r1, _0802326C
	ldrh r2, [r1]
	movs r4, 0xDD
	lsls r4, 2
	adds r1, r0, r4
	strh r2, [r1]
	ldr r1, _08023270
	ldrh r2, [r1]
	ldr r3, _08023274
	adds r1, r0, r3
	strh r2, [r1]
	adds r0, r5
	bl sub_8013984
	bl sub_8023420
	bl sub_80234BC
	movs r0, 0x1
_08023252:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023260: .4byte gUnknown_3001B5C
_08023264: .4byte gUnknown_203B298
_08023268: .4byte gUnknown_80DC91C
_0802326C: .4byte gUnknown_203B29C
_08023270: .4byte gUnknown_203B29E
_08023274: .4byte 0x0000037a
	thumb_func_end sub_8023144

	thumb_func_start sub_8023278
sub_8023278:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08023298
	ldr r0, _08023294
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _08023316
	.align 2, 0
_08023294: .4byte gUnknown_3001B5C
_08023298:
	ldr r4, _080232B4
	ldr r0, [r4]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _080232BE
	cmp r0, 0x2
	bgt _080232B8
	cmp r0, 0x1
	beq _080232C8
	b _080232EC
	.align 2, 0
_080232B4: .4byte gUnknown_3001B5C
_080232B8:
	cmp r0, 0x3
	beq _080232D2
	b _080232EC
_080232BE:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08023316
_080232C8:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08023316
_080232D2:
	movs r0, 0x5
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	movs r2, 0x1
	cmp r1, 0x1
	bhi _080232E4
	adds r2, r1, 0x1
_080232E4:
	str r2, [r0, 0x4]
	bl sub_80236A4
	b _0802330C
_080232EC:
	ldr r0, _08023308
	ldr r0, [r0]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802330C
	movs r0, 0
	b _08023316
	.align 2, 0
_08023308: .4byte gUnknown_3001B5C
_0802330C:
	bl sub_8023420
	bl sub_80234BC
	movs r0, 0x1
_08023316:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023278

	thumb_func_start sub_802331C
sub_802331C:
	ldr r0, _0802334C
	ldr r0, [r0]
	ldr r2, _08023350
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0xDE
	lsls r3, 2
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r1, r2
	movs r3, 0xDD
	lsls r3, 2
	adds r2, r0, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r1, r2
	lsls r1, 1
	adds r0, 0xC
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0802334C: .4byte gUnknown_3001B5C
_08023350: .4byte 0x0000037a
	thumb_func_end sub_802331C

	thumb_func_start sub_8023354
sub_8023354:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802339C
	ldr r0, [r5]
	movs r1, 0xE6
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_8023420
	bl sub_80234BC
	cmp r4, 0
	beq _08023396
	ldr r0, [r5]
	movs r1, 0xD7
	lsls r1, 2
	adds r0, r1
	bl AddMenuCursorSprite
_08023396:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802339C: .4byte gUnknown_3001B5C
	thumb_func_end sub_8023354

	thumb_func_start sub_80233A0
sub_80233A0:
	push {r4-r6,lr}
	ldr r5, _08023408
	ldr r2, [r5]
	cmp r2, 0
	beq _08023400
	ldr r1, _0802340C
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, _08023410
	movs r3, 0xDD
	lsls r3, 2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08023414
	ldr r6, _08023418
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE6
	lsls r4, 2
	adds r1, r4
	ldr r0, _0802341C
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_08023400:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08023408: .4byte gUnknown_3001B5C
_0802340C: .4byte gUnknown_203B298
_08023410: .4byte gUnknown_203B29C
_08023414: .4byte gUnknown_203B29E
_08023418: .4byte 0x0000037a
_0802341C: .4byte gUnknown_80DC904
	thumb_func_end sub_80233A0

	thumb_func_start sub_8023420
sub_8023420:
	push {r4,r5,lr}
	ldr r4, _080234A8
	ldr r0, [r4]
	movs r1, 0xFE
	lsls r1, 2
	adds r0, r1
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080234AC
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, 0x1
	adds r0, r1
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080234B0
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _080234B4
	adds r0, r2
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r3, [r4]
	movs r2, 0xE4
	lsls r2, 2
	adds r5, r3, r2
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _080234B8
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r2, [r5]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r3, r1
	movs r1, 0xEA
	lsls r1, 2
	adds r3, r1
	strh r0, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	movs r2, 0xE6
	lsls r2, 2
	adds r0, r2
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080234A8: .4byte gUnknown_3001B5C
_080234AC: .4byte 0x000003f9
_080234B0: .4byte 0x000003fb
_080234B4: .4byte 0x00000376
_080234B8: .4byte 0x000003a6
	thumb_func_end sub_8023420

	thumb_func_start sub_80234BC
sub_80234BC:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x178
	ldr r5, _0802368C
	ldr r0, [r5]
	movs r4, 0xE4
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r5]
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073B8
	ldr r2, _08023690
	ldr r0, [r5]
	adds r0, r4
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r3, [r5]
	ldr r1, _08023694
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, 0x4
	ldr r2, _08023698
	adds r1, r3, r2
	movs r6, 0
	ldrsh r2, [r1, r6]
	adds r2, 0x1
	movs r1, 0x7
	str r1, [sp]
	adds r3, r4
	ldr r1, [r3]
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r0, 0
	mov r10, r0
	ldr r0, [r5]
	ldr r1, _0802369C
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r10, r0
	blt _08023532
	b _0802366C
_08023532:
	ldr r3, _0802368C
	ldr r0, [r3]
	movs r6, 0xD7
	lsls r6, 2
	adds r0, r6
	mov r1, r10
	bl sub_8013800
	mov r8, r0
	ldr r0, _0802368C
	ldr r1, [r0]
	ldr r2, _08023698
	adds r0, r1, r2
	movs r3, 0
	ldrsh r2, [r0, r3]
	adds r6, 0x1C
	adds r0, r1, r6
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r2
	add r0, r10
	lsls r0, 1
	adds r1, 0xC
	adds r1, r0
	movs r6, 0
	ldrsh r5, [r1, r6]
	adds r0, r5, 0
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	add r4, sp, 0x16C
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_8092638
	movs r7, 0x7
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _08023594
	adds r0, r5, 0
	bl HasRecruitedMon
	lsls r0, 24
	movs r7, 0x4
	cmp r0, 0
	beq _08023594
	movs r7, 0x5
_08023594:
	adds r0, r5, 0
	movs r1, 0
	bl sub_808DCA0
	lsls r0, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	movs r1, 0xA
	bl __modsi3
	adds r2, r0, 0
	adds r2, 0x30
	lsls r2, 24
	lsrs r2, 24
	ldr r6, _0802368C
	ldr r0, [r6]
	movs r1, 0xE4
	lsls r1, 2
	mov r9, r1
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x14
	mov r1, r8
	adds r3, r7, 0
	bl sub_8012C60
	cmp r4, 0x9
	ble _08023628
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	adds r4, r0, 0
	movs r1, 0xA
	bl __modsi3
	adds r2, r0, 0
	adds r2, 0x30
	lsls r2, 24
	lsrs r2, 24
	ldr r0, [r6]
	movs r3, 0xE4
	lsls r3, 2
	adds r0, r3
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0xD
	mov r1, r8
	adds r3, r7, 0
	bl sub_8012C60
	cmp r4, 0x9
	ble _08023628
	adds r0, r4, 0
	movs r1, 0xA
	bl __divsi3
	movs r1, 0xA
	bl __modsi3
	adds r2, r0, 0
	adds r2, 0x30
	lsls r2, 24
	lsrs r2, 24
	ldr r0, [r6]
	add r0, r9
	ldr r0, [r0]
	str r0, [sp]
	movs r0, 0x6
	mov r1, r8
	adds r3, r7, 0
	bl sub_8012C60
_08023628:
	add r4, sp, 0x108
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_808D930
	add r0, sp, 0x8
	ldr r1, _080236A0
	adds r2, r7, 0
	adds r3, r4, 0
	bl sub_800D158
	ldr r6, _0802368C
	ldr r0, [r6]
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r1
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x24
	mov r1, r8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	movs r2, 0x1
	add r10, r2
	ldr r0, [r6]
	ldr r3, _0802369C
	adds r0, r3
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r10, r0
	bge _0802366C
	b _08023532
_0802366C:
	ldr r0, _0802368C
	ldr r0, [r0]
	movs r1, 0xE4
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x178
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802368C: .4byte gUnknown_3001B5C
_08023690: .4byte gUnknown_80DC934
_08023694: .4byte 0x000003fa
_08023698: .4byte 0x0000037a
_0802369C: .4byte 0x00000376
_080236A0: .4byte gUnknown_80DC93C
	thumb_func_end sub_80234BC

	thumb_func_start sub_80236A4
sub_80236A4:
	push {r4,r5,lr}
	ldr r0, _080236FC
	ldr r1, [r0]
	movs r0, 0
	str r0, [r1, 0x8]
	movs r5, 0
_080236B0:
	lsls r0, r5, 16
	asrs r4, r0, 16
	adds r0, r4, 0
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _080236E2
	adds r0, r4, 0
	bl sub_808E858
	lsls r0, 16
	asrs r0, 16
	cmp r4, r0
	bne _080236E2
	ldr r0, _080236FC
	ldr r3, [r0]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0xC
	adds r0, r2
	strh r5, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
_080236E2:
	adds r5, 0x1
	ldr r0, _08023700
	cmp r5, r0
	ble _080236B0
	bl sub_8023730
	ldr r0, _080236FC
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080236FC: .4byte gUnknown_3001B5C
_08023700: .4byte 0x000001a7
	thumb_func_end sub_80236A4

	thumb_func_start sub_8023704
sub_8023704:
	push {r4,lr}
	movs r4, 0
_08023708:
	lsls r0, r4, 16
	asrs r0, 16
	bl sub_8098134
	lsls r0, 24
	cmp r0, 0
	beq _0802371A
	movs r0, 0
	b _08023724
_0802371A:
	adds r4, 0x1
	ldr r0, _0802372C
	cmp r4, r0
	ble _08023708
	movs r0, 0x1
_08023724:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802372C: .4byte 0x000001a7
	thumb_func_end sub_8023704

	thumb_func_start sub_8023730
sub_8023730:
	push {lr}
	ldr r0, _08023744
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x1
	beq _08023748
	cmp r0, 0x2
	beq _0802374E
	b _08023752
	.align 2, 0
_08023744: .4byte gUnknown_3001B5C
_08023748:
	bl sub_8023758
	b _08023752
_0802374E:
	bl sub_80237E0
_08023752:
	pop {r0}
	bx r0
	thumb_func_end sub_8023730

	thumb_func_start sub_8023758
sub_8023758:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _080237DC
	ldr r2, [r3]
	ldr r1, [r2, 0x8]
	lsls r0, r1, 1
	adds r0, 0xA
	adds r2, r0
	mov r9, r2
	movs r2, 0
	subs r1, 0x1
	cmp r2, r1
	bge _080237CC
_08023778:
	mov r5, r9
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r7, r0, 0x1
	adds r0, r2, 0x1
	mov r8, r0
	cmp r7, r2
	ble _080237BE
_08023788:
	subs r6, r5, 0x2
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0x1
	str r2, [sp]
	bl sub_808DCDC
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0x1
	bl sub_808DCDC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp]
	cmp r4, r0
	ble _080237B6
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_080237B6:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08023788
_080237BE:
	mov r2, r8
	ldr r3, _080237DC
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r0, 0x1
	cmp r2, r0
	blt _08023778
_080237CC:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080237DC: .4byte gUnknown_3001B5C
	thumb_func_end sub_8023758

	thumb_func_start sub_80237E0
sub_80237E0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r3, _08023864
	ldr r2, [r3]
	ldr r1, [r2, 0x8]
	lsls r0, r1, 1
	adds r0, 0xA
	adds r2, r0
	mov r9, r2
	movs r2, 0
	subs r1, 0x1
	cmp r2, r1
	bge _08023854
_08023800:
	mov r5, r9
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r7, r0, 0x1
	adds r0, r2, 0x1
	mov r8, r0
	cmp r7, r2
	ble _08023846
_08023810:
	subs r6, r5, 0x2
	movs r1, 0
	ldrsh r0, [r6, r1]
	movs r1, 0
	str r2, [sp]
	bl sub_808DCDC
	adds r4, r0, 0
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r1, 0
	bl sub_808DCDC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp]
	cmp r4, r0
	ble _0802383E
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_0802383E:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08023810
_08023846:
	mov r2, r8
	ldr r3, _08023864
	ldr r0, [r3]
	ldr r0, [r0, 0x8]
	subs r0, 0x1
	cmp r2, r0
	blt _08023800
_08023854:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023864: .4byte gUnknown_3001B5C
	thumb_func_end sub_80237E0

	thumb_func_start sub_8023868
sub_8023868:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	mov r8, r1
	mov r9, r2
	mov r10, r3
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _08023888
	movs r0, 0
	b _08023A6E
_08023888:
	ldr r4, _080238AC
	ldr r0, [r4]
	cmp r0, 0
	bne _0802389C
	movs r0, 0xFE
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802389C:
	ldr r1, [r4]
	str r5, [r1]
	ldr r0, _080238B0
	ldr r0, [r0]
	cmp r0, r5
	beq _080238B4
	movs r0, 0x1
	b _080238B8
	.align 2, 0
_080238AC: .4byte gUnknown_3001B60
_080238B0: .4byte gUnknown_203B2A0
_080238B4:
	ldr r0, _080238E4
	ldr r0, [r0]
_080238B8:
	str r0, [r1, 0x4]
	ldr r2, _080238E8
	ldr r0, [r2]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r2]
	strb r1, [r0, 0x15]
	ldr r0, [r2]
	strb r1, [r0, 0x16]
	ldr r0, [r2]
	strb r1, [r0, 0x17]
	ldr r0, [r2]
	strb r1, [r0, 0x18]
	ldr r0, [r2]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _08023980
	lsls r0, 2
	ldr r1, _080238EC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080238E4: .4byte gUnknown_203B2A4
_080238E8: .4byte gUnknown_3001B60
_080238EC: .4byte _080238F0
	.align 2, 0
_080238F0:
	.4byte _08023958
	.4byte _08023904
	.4byte _08023914
	.4byte _08023924
	.4byte _0802393C
_08023904:
	ldr r0, _08023910
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x18]
	b _08023958
	.align 2, 0
_08023910: .4byte gUnknown_3001B60
_08023914:
	ldr r0, _08023920
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x14]
	b _08023958
	.align 2, 0
_08023920: .4byte gUnknown_3001B60
_08023924:
	ldr r2, _08023938
	ldr r0, [r2]
	movs r1, 0x1
	strb r1, [r0, 0x17]
	ldr r0, [r2]
	strb r1, [r0, 0x15]
	ldr r0, [r2]
	strb r1, [r0, 0x16]
	b _08023958
	.align 2, 0
_08023938: .4byte gUnknown_3001B60
_0802393C:
	ldr r5, _0802397C
	ldr r0, [r5]
	movs r4, 0x1
	strb r4, [r0, 0x18]
	ldr r0, [r5]
	strb r4, [r0, 0x15]
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08023958
	ldr r0, [r5]
	strb r4, [r0, 0x16]
_08023958:
	ldr r4, _0802397C
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x4
	bne _08023980
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r1, [r4]
	movs r2, 0xD5
	lsls r2, 2
	adds r1, r2
	strb r0, [r1]
	b _0802398E
	.align 2, 0
_0802397C: .4byte gUnknown_3001B60
_08023980:
	ldr r0, _08023A7C
	ldr r0, [r0]
	movs r3, 0xD5
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
_0802398E:
	ldr r5, _08023A7C
	ldr r0, [r5]
	movs r4, 0xE3
	lsls r4, 2
	adds r1, r0, r4
	mov r2, r8
	str r2, [r1]
	movs r7, 0xE4
	lsls r7, 2
	adds r2, r0, r7
	mov r3, r8
	lsls r1, r3, 1
	add r1, r8
	lsls r1, 3
	movs r6, 0xE5
	lsls r6, 2
	adds r1, r6
	adds r1, r0, r1
	str r1, [r2]
	adds r0, r6
	bl sub_8006518
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r2, [r4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, r6
	ldr r0, _08023A80
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r5]
	adds r0, r2, r7
	ldr r1, [r0]
	movs r4, 0xFD
	lsls r4, 2
	adds r0, r2, r4
	str r0, [r1, 0x14]
	mov r0, r9
	cmp r0, 0
	beq _08023A04
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	movs r3, 0xE7
	lsls r3, 2
	adds r1, r2, r3
	adds r1, r0
	mov r4, r9
	ldr r0, [r4]
	str r0, [r1]
_08023A04:
	ldr r0, [r5]
	adds r0, r7
	ldr r0, [r0]
	mov r1, r10
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	movs r0, 0xD6
	lsls r0, 2
	adds r4, r0
	bl sub_8023F8C
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r10
	mov r3, r8
	bl sub_8013818
	ldr r0, _08023A84
	ldr r4, [r5]
	ldr r1, [r0]
	ldr r0, [r4]
	cmp r1, r0
	bne _08023A64
	ldr r0, _08023A88
	ldrh r1, [r0]
	movs r2, 0xDC
	lsls r2, 2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08023A8C
	ldrh r1, [r0]
	ldr r3, _08023A90
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r4, r1
	bl sub_8013984
_08023A64:
	bl sub_8023CF4
	bl sub_8023DA4
	movs r0, 0x1
_08023A6E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023A7C: .4byte gUnknown_3001B60
_08023A80: .4byte gUnknown_80DC968
_08023A84: .4byte gUnknown_203B2A0
_08023A88: .4byte gUnknown_203B2A8
_08023A8C: .4byte gUnknown_203B2AA
_08023A90: .4byte 0x00000376
	thumb_func_end sub_8023868

	thumb_func_start sub_8023A94
sub_8023A94:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _08023AB4
	ldr r0, _08023AB0
	ldr r0, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl sub_8013660
	movs r0, 0
	b _08023B3E
	.align 2, 0
_08023AB0: .4byte gUnknown_3001B60
_08023AB4:
	ldr r4, _08023AD0
	ldr r0, [r4]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl GetKeyPress
	cmp r0, 0x2
	beq _08023ADE
	cmp r0, 0x2
	bgt _08023AD4
	cmp r0, 0x1
	beq _08023AF2
	b _08023B16
	.align 2, 0
_08023AD0: .4byte gUnknown_3001B60
_08023AD4:
	cmp r0, 0x3
	beq _08023AFC
	cmp r0, 0x4
	beq _08023AE8
	b _08023B16
_08023ADE:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08023B3E
_08023AE8:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _08023B3E
_08023AF2:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08023B3E
_08023AFC:
	movs r0, 0x5
	bl PlayMenuSoundEffect
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	movs r2, 0x1
	cmp r1, 0x2
	bhi _08023B0E
	adds r2, r1, 0x1
_08023B0E:
	str r2, [r0, 0x4]
	bl sub_8023F8C
	b _08023B34
_08023B16:
	ldr r0, _08023B30
	ldr r0, [r0]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _08023B34
	movs r0, 0
	b _08023B3E
	.align 2, 0
_08023B30: .4byte gUnknown_3001B60
_08023B34:
	bl sub_8023CF4
	bl sub_8023DA4
	movs r0, 0x1
_08023B3E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8023A94

	thumb_func_start sub_8023B44
sub_8023B44:
	ldr r0, _08023B74
	ldr r0, [r0]
	ldr r2, _08023B78
	adds r1, r0, r2
	movs r3, 0
	ldrsh r2, [r1, r3]
	movs r3, 0xDD
	lsls r3, 2
	adds r1, r0, r3
	movs r3, 0
	ldrsh r1, [r1, r3]
	muls r1, r2
	movs r3, 0xDC
	lsls r3, 2
	adds r2, r0, r3
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r1, r2
	lsls r1, 1
	adds r0, 0x1A
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_08023B74: .4byte gUnknown_3001B60
_08023B78: .4byte 0x00000376
	thumb_func_end sub_8023B44

	thumb_func_start sub_8023B7C
sub_8023B7C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _08023BD0
	ldr r0, [r5]
	movs r1, 0xE5
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_8023BD8
	adds r2, r0, 0
	ldr r0, [r5]
	ldr r3, _08023BD4
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, 0xD6
	lsls r1, 2
	adds r0, r1
	bl sub_8013984
	bl sub_8023CF4
	bl sub_8023DA4
	cmp r4, 0
	beq _08023BCA
	ldr r0, [r5]
	movs r3, 0xD6
	lsls r3, 2
	adds r0, r3
	bl AddMenuCursorSprite
_08023BCA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023BD0: .4byte gUnknown_3001B60
_08023BD4: .4byte 0x0000037a
	thumb_func_end sub_8023B7C

	thumb_func_start sub_8023BD8
sub_8023BD8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r3, 0
	ldr r1, _08023C58
	ldr r0, [r1]
	ldr r0, [r0, 0x8]
	adds r7, r1, 0
	cmp r3, r0
	bge _08023C4A
	ldr r0, _08023C5C
	mov r8, r0
	mov r12, r7
_08023BF2:
	ldr r2, [r1]
	lsls r4, r3, 1
	adds r0, r2, 0
	adds r0, 0x1A
	adds r0, r4
	movs r5, 0
	ldrsh r1, [r0, r5]
	movs r0, 0x58
	muls r0, r1
	mov r5, r8
	ldr r1, [r5]
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	adds r6, r3, 0x1
	cmp r0, 0
	bne _08023C3E
	ldr r0, [r2, 0x8]
	subs r0, 0x1
	str r0, [r2, 0x8]
	cmp r3, r0
	bge _08023C3E
	mov r5, r12
	adds r4, 0x2
_08023C24:
	ldr r2, [r5]
	lsls r1, r3, 1
	adds r0, r2, 0
	adds r0, 0x1A
	adds r1, r0, r1
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, 0x2
	adds r3, 0x1
	ldr r0, [r2, 0x8]
	cmp r3, r0
	blt _08023C24
_08023C3E:
	adds r3, r6, 0
	adds r1, r7, 0
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	cmp r3, r0
	blt _08023BF2
_08023C4A:
	ldr r0, [r7]
	ldr r0, [r0, 0x8]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08023C58: .4byte gUnknown_3001B60
_08023C5C: .4byte gUnknown_203B45C
	thumb_func_end sub_8023BD8

	thumb_func_start sub_8023C60
sub_8023C60:
	push {r4-r6,lr}
	ldr r5, _08023CCC
	ldr r2, [r5]
	cmp r2, 0
	beq _08023CC6
	ldr r1, _08023CD0
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _08023CD4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, _08023CD8
	movs r3, 0xDC
	lsls r3, 2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _08023CDC
	ldr r6, _08023CE0
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r1]
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	movs r4, 0xE5
	lsls r4, 2
	adds r1, r4
	ldr r0, _08023CE4
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, r4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r5]
	bl MemoryFree
	movs r0, 0
	str r0, [r5]
_08023CC6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08023CCC: .4byte gUnknown_3001B60
_08023CD0: .4byte gUnknown_203B2A0
_08023CD4: .4byte gUnknown_203B2A4
_08023CD8: .4byte gUnknown_203B2A8
_08023CDC: .4byte gUnknown_203B2AA
_08023CE0: .4byte 0x00000376
_08023CE4: .4byte gUnknown_80DC950
	thumb_func_end sub_8023C60

	thumb_func_start sub_8023CE8
sub_8023CE8:
	ldr r0, _08023CF0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08023CF0: .4byte gUnknown_3001B60
	thumb_func_end sub_8023CE8

	thumb_func_start sub_8023CF4
sub_8023CF4:
	push {r4,r5,lr}
	ldr r2, _08023D28
	ldr r0, [r2]
	movs r1, 0xFD
	lsls r1, 2
	adds r0, r1
	movs r3, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08023D2C
	adds r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r1, 0x2
	adds r0, r1
	strb r3, [r0]
	ldr r1, [r2]
	ldr r0, [r1]
	adds r5, r2, 0
	cmp r0, 0x2
	bne _08023D34
	ldr r0, _08023D30
	adds r1, r0
	b _08023D38
	.align 2, 0
_08023D28: .4byte gUnknown_3001B60
_08023D2C: .4byte 0x000003f5
_08023D30: .4byte 0x000003f6
_08023D34:
	ldr r2, _08023D98
	adds r1, r2
_08023D38:
	movs r0, 0xC
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _08023D9C
	adds r0, r1
	movs r2, 0
	ldrsh r0, [r0, r2]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r3, [r5]
	movs r1, 0xE3
	lsls r1, 2
	adds r4, r3, r1
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r1, r3, r1
	ldr r2, _08023DA0
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r3, r1
	movs r1, 0xE9
	lsls r1, 2
	adds r3, r1
	strh r0, [r3]
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	movs r2, 0xE5
	lsls r2, 2
	adds r0, r2
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023D98: .4byte 0x000003f6
_08023D9C: .4byte 0x00000372
_08023DA0: .4byte 0x000003a2
	thumb_func_end sub_8023CF4

	thumb_func_start sub_8023DA4
sub_8023DA4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	ldr r4, _08023DD8
	ldr r0, [r4]
	movs r5, 0xE3
	lsls r5, 2
	adds r0, r5
	ldr r0, [r0]
	bl sub_8008C54
	ldr r0, [r4]
	adds r0, r5
	ldr r0, [r0]
	bl sub_80073B8
	ldr r0, [r4]
	ldr r1, [r0]
	cmp r1, 0x2
	beq _08023DE0
	cmp r1, 0x4
	beq _08023E00
	ldr r2, _08023DDC
	b _08023E02
	.align 2, 0
_08023DD8: .4byte gUnknown_3001B60
_08023DDC: .4byte gUnknown_80DC988
_08023DE0:
	add r0, sp, 0x8
	bl sub_80920D8
	ldr r0, [r4]
	movs r1, 0xE3
	lsls r1, 2
	adds r0, r1
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	add r2, sp, 0x8
	bl xxx_call_draw_string
	b _08023E3C
_08023E00:
	ldr r2, _08023EBC
_08023E02:
	adds r0, r5
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xA
	movs r1, 0
	bl xxx_call_draw_string
	ldr r1, [r4]
	ldr r2, _08023EC0
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 3
	adds r3, r0, 0x4
	ldr r4, _08023EC4
	adds r0, r1, r4
	movs r4, 0
	ldrsh r2, [r0, r4]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	adds r1, r5
	ldr r0, [r1]
	str r0, [sp, 0x4]
	adds r0, r3, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
_08023E3C:
	movs r7, 0
	ldr r1, _08023EC8
	ldr r0, [r1]
	ldr r2, _08023ECC
	adds r0, r2
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r7, r0
	blt _08023E50
	b _08023F62
_08023E50:
	mov r8, r1
	add r0, sp, 0x30
	mov r9, r0
_08023E56:
	ldr r3, [r1]
	ldr r1, _08023EC4
	adds r0, r3, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r4, 0xDD
	lsls r4, 2
	adds r0, r3, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	muls r1, r0
	adds r1, r7
	lsls r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r1
	movs r4, 0
	ldrsh r5, [r0, r4]
	ldr r2, _08023ED0
	movs r0, 0x58
	adds r1, r5, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	movs r6, 0x7
	ldrh r0, [r4]
	lsrs r0, 1
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08023ED4
	movs r0, 0
	ldrb r1, [r4, 0x4]
	cmp r1, 0x41
	bne _08023E9E
	movs r0, 0x1
_08023E9E:
	cmp r0, 0
	beq _08023EA4
	movs r6, 0x6
_08023EA4:
	movs r0, 0
	cmp r1, 0x40
	bne _08023EAC
	movs r0, 0x1
_08023EAC:
	cmp r0, 0
	beq _08023EB2
	movs r6, 0x6
_08023EB2:
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	beq _08023EEA
	movs r6, 0x5
	b _08023EEA
	.align 2, 0
_08023EBC: .4byte gUnknown_80DC980
_08023EC0: .4byte 0x000003f6
_08023EC4: .4byte 0x00000376
_08023EC8: .4byte gUnknown_3001B60
_08023ECC: .4byte 0x00000372
_08023ED0: .4byte gUnknown_203B45C
_08023ED4:
	ldrb r0, [r3, 0x18]
	cmp r0, 0
	beq _08023EEA
	adds r0, r5, 0
	bl sub_808D750
	lsls r0, 24
	movs r6, 0x2
	cmp r0, 0
	beq _08023EEA
	movs r6, 0x4
_08023EEA:
	mov r0, r8
	ldr r1, [r0]
	ldr r0, [r1]
	cmp r0, 0x4
	bne _08023F02
	movs r2, 0xD5
	lsls r2, 2
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8024184
_08023F02:
	adds r1, r4, 0
	adds r1, 0x4C
	mov r0, r9
	movs r2, 0xA
	bl sub_80922B4
	movs r0, 0x8
	ldrsh r1, [r4, r0]
	add r0, sp, 0x44
	bl sub_808D930
	add r0, sp, 0x8
	ldr r1, _08023F80
	adds r2, r6, 0
	mov r3, r9
	bl sub_800D158
	mov r1, r8
	ldr r0, [r1]
	movs r2, 0xD6
	lsls r2, 2
	adds r0, r2
	adds r1, r7, 0
	bl sub_8013800
	adds r1, r0, 0
	mov r4, r8
	ldr r0, [r4]
	movs r2, 0xE3
	lsls r2, 2
	adds r0, r2
	ldr r3, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	add r2, sp, 0x8
	bl xxx_call_draw_string
	adds r7, 0x1
	mov r1, r8
	ldr r0, [r4]
	ldr r4, _08023F84
	adds r0, r4
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _08023F62
	b _08023E56
_08023F62:
	ldr r0, _08023F88
	ldr r0, [r0]
	movs r4, 0xE3
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl sub_80073E0
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023F80: .4byte gUnknown_80DC998
_08023F84: .4byte 0x00000372
_08023F88: .4byte gUnknown_3001B60
	thumb_func_end sub_8023DA4

	thumb_func_start sub_8023F8C
sub_8023F8C:
	push {r4-r7,lr}
	ldr r2, _08023FD0
	ldr r1, [r2]
	movs r0, 0
	str r0, [r1, 0x8]
	ldrb r0, [r1, 0x15]
	adds r6, r2, 0
	cmp r0, 0
	bne _08023FE2
	movs r4, 0
	ldr r2, _08023FD4
_08023FA2:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r2]
	adds r1, r0, r1
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	beq _08023FD8
	ldrb r1, [r1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08023FD8
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	b _08023FE2
	.align 2, 0
_08023FD0: .4byte gUnknown_3001B60
_08023FD4: .4byte gUnknown_203B45C
_08023FD8:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08023FA2
_08023FE2:
	ldr r0, [r6]
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	bne _08024042
	movs r4, 0
	ldr r3, _08024034
_08023FEE:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r3]
	adds r1, r0, r1
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08024002
	movs r2, 0x1
_08024002:
	cmp r2, 0
	beq _08024038
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08024038
	ldrh r1, [r1]
	lsrs r0, r1, 1
	movs r2, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08024038
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08024038
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	b _08024042
	.align 2, 0
_08024034: .4byte gUnknown_203B45C
_08024038:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08023FEE
_08024042:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	str r1, [r0, 0xC]
	ldrb r0, [r0, 0x17]
	cmp r0, 0
	bne _080240A4
	movs r4, 0
	ldr r7, _08024100
	movs r5, 0x1
_08024054:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r7]
	adds r1, r0, r1
	ldrh r2, [r1]
	lsrs r0, r2, 1
	ands r0, r5
	cmp r0, 0
	beq _0802409A
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _0802409A
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _0802409A
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08024080
	movs r2, 0x1
_08024080:
	cmp r2, 0
	bne _0802409A
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
	cmp r1, 0x3
	bgt _080240A4
_0802409A:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _08024054
_080240A4:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	str r1, [r0, 0x10]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080240EE
	movs r4, 0
	ldr r7, _08024100
	movs r5, 0x1
_080240B6:
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	ldr r0, [r7]
	adds r1, r0, r1
	ldrh r1, [r1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080240E4
	lsrs r0, r1, 1
	ands r0, r5
	cmp r0, 0
	bne _080240E4
	ldr r3, [r6]
	ldr r1, [r3, 0x8]
	lsls r2, r1, 1
	adds r0, r3, 0
	adds r0, 0x1A
	adds r0, r2
	strh r4, [r0]
	adds r1, 0x1
	str r1, [r3, 0x8]
_080240E4:
	adds r4, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	ble _080240B6
_080240EE:
	bl sub_80241A8
	ldr r0, _08024104
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_08024100: .4byte gUnknown_203B45C
_08024104: .4byte gUnknown_3001B60
	thumb_func_end sub_8023F8C

	thumb_func_start sub_8024108
sub_8024108:
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r7, 0
	movs r6, 0x1
_08024110:
	ldr r2, _08024134
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r1, [r4]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08024172
	cmp r5, 0x2
	bne _08024138
	lsrs r0, r1, 1
	ands r0, r6
	cmp r0, 0
	beq _08024172
	b _0802416E
	.align 2, 0
_08024134: .4byte gUnknown_203B45C
_08024138:
	cmp r5, 0x3
	bne _08024140
	lsrs r0, r1, 1
	b _08024168
_08024140:
	cmp r5, 0x4
	bne _0802416E
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _08024172
	movs r0, 0x9
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _0802416E
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _08024160
	movs r1, 0x1
_08024160:
	cmp r1, 0
	beq _0802416E
	ldrh r0, [r4]
	lsrs r0, 1
_08024168:
	ands r0, r6
	cmp r0, 0
	bne _08024172
_0802416E:
	movs r0, 0
	b _0802417E
_08024172:
	adds r7, 0x1
	movs r0, 0xCE
	lsls r0, 1
	cmp r7, r0
	ble _08024110
	movs r0, 0x1
_0802417E:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8024108

	thumb_func_start sub_8024184
sub_8024184:
	push {r4,lr}
	lsls r4, r1, 24
	lsrs r4, 24
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _0802419E
	movs r0, 0
	b _080241A0
_0802419E:
	movs r0, 0x1
_080241A0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8024184

	thumb_func_start sub_80241A8
sub_80241A8:
	push {r4,lr}
	ldr r4, _080241C0
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x2
	beq _080241CA
	cmp r0, 0x2
	bhi _080241C4
	cmp r0, 0x1
	beq _08024206
	b _08024222
	.align 2, 0
_080241C0: .4byte gUnknown_3001B60
_080241C4:
	cmp r0, 0x3
	beq _080241E8
	b _08024222
_080241CA:
	ldr r0, [r1, 0xC]
	ldr r1, [r1, 0x10]
	cmp r0, r1
	beq _080241D6
	bl sub_80242D0
_080241D6:
	ldr r0, [r4]
	ldr r2, [r0, 0x10]
	ldr r1, [r0, 0x8]
	cmp r2, r1
	beq _08024222
	adds r0, r2, 0
	bl sub_80242D0
	b _08024222
_080241E8:
	ldr r0, [r1, 0xC]
	ldr r1, [r1, 0x10]
	cmp r0, r1
	beq _080241F4
	bl sub_802437C
_080241F4:
	ldr r0, [r4]
	ldr r2, [r0, 0x10]
	ldr r1, [r0, 0x8]
	cmp r2, r1
	beq _08024222
	adds r0, r2, 0
	bl sub_802437C
	b _08024222
_08024206:
	ldr r0, [r1, 0xC]
	ldr r1, [r1, 0x10]
	cmp r0, r1
	beq _08024212
	bl sub_8024228
_08024212:
	ldr r0, [r4]
	ldr r2, [r0, 0x10]
	ldr r1, [r0, 0x8]
	cmp r2, r1
	beq _08024222
	adds r0, r2, 0
	bl sub_8024228
_08024222:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80241A8

	thumb_func_start sub_8024228
sub_8024228:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r3, _080242C8
	lsls r2, r1, 1
	adds r2, 0x18
	ldr r3, [r3]
	adds r3, r2
	str r3, [sp]
	adds r2, r0, 0
	subs r1, 0x1
	cmp r2, r1
	bge _080242B8
	str r1, [sp, 0x4]
_0802424A:
	ldr r5, [sp]
	adds r7, r1, 0
	adds r0, r2, 0x1
	mov r10, r0
	cmp r7, r2
	ble _080242B0
	ldr r3, _080242CC
	mov r9, r3
	movs r0, 0x58
	mov r8, r0
_0802425E:
	mov r3, r9
	ldr r1, [r3]
	subs r6, r5, 0x2
	movs r3, 0
	ldrsh r0, [r6, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	str r2, [sp, 0x8]
	bl sub_808DCFC
	adds r4, r0, 0
	mov r0, r9
	ldr r1, [r0]
	movs r3, 0
	ldrsh r0, [r5, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	bl sub_808DCFC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp, 0x8]
	cmp r4, r0
	ble _080242A8
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_080242A8:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _0802425E
_080242B0:
	mov r2, r10
	ldr r1, [sp, 0x4]
	cmp r2, r1
	blt _0802424A
_080242B8:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080242C8: .4byte gUnknown_3001B60
_080242CC: .4byte gUnknown_203B45C
	thumb_func_end sub_8024228

	thumb_func_start sub_80242D0
sub_80242D0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r3, _08024374
	lsls r2, r1, 1
	adds r2, 0x18
	ldr r3, [r3]
	adds r3, r2
	str r3, [sp]
	adds r2, r0, 0
	subs r1, 0x1
	cmp r2, r1
	bge _08024364
	str r1, [sp, 0x4]
_080242F2:
	ldr r5, [sp]
	adds r7, r1, 0
	adds r0, r2, 0x1
	mov r10, r0
	cmp r7, r2
	ble _0802435C
	ldr r3, _08024378
	mov r9, r3
	movs r0, 0x58
	mov r8, r0
_08024306:
	mov r3, r9
	ldr r1, [r3]
	subs r6, r5, 0x2
	movs r3, 0
	ldrsh r0, [r6, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	movs r1, 0
	str r2, [sp, 0x8]
	bl sub_808DCDC
	adds r4, r0, 0
	mov r0, r9
	ldr r1, [r0]
	movs r3, 0
	ldrsh r0, [r5, r3]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	movs r1, 0
	bl sub_808DCDC
	lsls r4, 16
	lsls r0, 16
	ldr r2, [sp, 0x8]
	cmp r4, r0
	ble _08024354
	movs r0, 0
	ldrsh r1, [r5, r0]
	ldrh r0, [r6]
	strh r0, [r5]
	strh r1, [r6]
_08024354:
	adds r5, r6, 0
	subs r7, 0x1
	cmp r7, r2
	bgt _08024306
_0802435C:
	mov r2, r10
	ldr r1, [sp, 0x4]
	cmp r2, r1
	blt _080242F2
_08024364:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024374: .4byte gUnknown_3001B60
_08024378: .4byte gUnknown_203B45C
	thumb_func_end sub_80242D0

	thumb_func_start sub_802437C
sub_802437C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r3, _080243E4
	lsls r2, r1, 1
	adds r2, 0x18
	ldr r3, [r3]
	adds r3, r2
	mov r10, r3
	adds r7, r0, 0
	subs r1, 0x1
	cmp r7, r1
	bge _080243D6
	mov r9, r1
_0802439C:
	mov r4, r10
	adds r6, r1, 0
	adds r0, r7, 0x1
	mov r8, r0
	cmp r6, r7
	ble _080243CE
_080243A8:
	subs r5, r4, 0x2
	movs r1, 0
	ldrsh r0, [r5, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl sub_808D864
	lsls r0, 24
	cmp r0, 0
	beq _080243C6
	movs r0, 0
	ldrsh r1, [r4, r0]
	ldrh r0, [r5]
	strh r0, [r4]
	strh r1, [r5]
_080243C6:
	adds r4, r5, 0
	subs r6, 0x1
	cmp r6, r7
	bgt _080243A8
_080243CE:
	mov r7, r8
	mov r1, r9
	cmp r7, r1
	blt _0802439C
_080243D6:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080243E4: .4byte gUnknown_3001B60
	thumb_func_end sub_802437C

	thumb_func_start sub_80243E8
sub_80243E8:
	push {r4,r5,lr}
	sub sp, 0x3C
	ldr r3, _08024448
	ldr r0, _0802444C
	ldr r0, [r0]
	ldr r2, _08024450
	adds r1, r0, r2
	movs r4, 0
	ldrsh r2, [r1, r4]
	movs r4, 0xDD
	lsls r4, 2
	adds r1, r0, r4
	movs r4, 0
	ldrsh r1, [r1, r4]
	muls r1, r2
	movs r4, 0xDC
	lsls r4, 2
	adds r2, r0, r4
	movs r4, 0
	ldrsh r2, [r2, r4]
	adds r1, r2
	lsls r1, 1
	adds r0, 0x1A
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r0, r1
	ldr r4, [r3]
	adds r4, r0
	add r5, sp, 0x28
	adds r1, r4, 0
	adds r1, 0x4C
	adds r0, r5, 0
	movs r2, 0xA
	bl sub_80922B4
	ldr r1, _08024454
	mov r0, sp
	adds r2, r5, 0
	bl sub_800D158
	adds r0, r4, 0
	add sp, 0x3C
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08024448: .4byte gUnknown_203B45C
_0802444C: .4byte gUnknown_3001B60
_08024450: .4byte 0x00000376
_08024454: .4byte gUnknown_80DC9A4
	thumb_func_end sub_80243E8

	thumb_func_start sub_8024458
sub_8024458:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r4, 16
	asrs r4, 16
	ldr r6, _080244DC
	movs r0, 0xA6
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	adds r1, r0, 0
	adds r1, 0x48
	strh r4, [r1]
	adds r1, 0x98
	str r5, [r1]
	adds r2, r0, 0
	adds r2, 0xE4
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 3
	adds r1, 0xE8
	adds r1, r0, r1
	str r1, [r2]
	adds r0, 0xE8
	bl sub_8006518
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xE0
	ldr r2, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0xE8
	ldr r0, _080244E0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xE4
	ldr r1, [r0]
	movs r3, 0xA4
	lsls r3, 1
	adds r0, r2, r3
	str r0, [r1, 0x14]
	movs r4, 0xA5
	lsls r4, 1
	adds r1, r2, r4
	movs r0, 0xA
	strb r0, [r1]
	bl sub_8024604
	bl sub_802452C
	ldr r0, [r6]
	bl sub_8013984
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_080244DC: .4byte gUnknown_203B2AC
_080244E0: .4byte gUnknown_80DC9C8
	thumb_func_end sub_8024458

	thumb_func_start sub_80244E4
sub_80244E4:
	push {r4,lr}
	ldr r4, _08024500
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _08024504
	cmp r0, 0x2
	bne _0802450E
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _08024524
	.align 2, 0
_08024500: .4byte gUnknown_203B2AC
_08024504:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _08024524
_0802450E:
	ldr r0, [r4]
	bl sub_8013938
	lsls r0, 24
	cmp r0, 0
	bne _0802451E
	movs r0, 0
	b _08024524
_0802451E:
	bl sub_802452C
	movs r0, 0x1
_08024524:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80244E4

	thumb_func_start sub_802452C
sub_802452C:
	push {lr}
	bl sub_8024588
	bl sub_80245D0
	pop {r0}
	bx r0
	thumb_func_end sub_802452C

	thumb_func_start sub_802453C
sub_802453C:
	push {r4,r5,lr}
	ldr r4, _08024580
	ldr r2, [r4]
	cmp r2, 0
	beq _0802457A
	adds r0, r2, 0
	adds r0, 0xE0
	ldr r0, [r0]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0xE8
	ldr r0, _08024584
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xE8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802457A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08024580: .4byte gUnknown_203B2AC
_08024584: .4byte gUnknown_80DC9B0
	thumb_func_end sub_802453C

	thumb_func_start sub_8024588
sub_8024588:
	push {r4,lr}
	ldr r4, _080245C4
	ldr r0, [r4]
	ldrh r1, [r0, 0x20]
	movs r2, 0xA4
	lsls r2, 1
	adds r0, r2
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x1E]
	ldr r3, _080245C8
	adds r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080245CC
	adds r0, r1
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xE8
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080245C4: .4byte gUnknown_203B2AC
_080245C8: .4byte 0x00000149
_080245CC: .4byte 0x0000014b
	thumb_func_end sub_8024588

	thumb_func_start sub_80245D0
sub_80245D0:
	push {r4,lr}
	sub sp, 0x4
	ldr r0, _08024600
	ldr r4, [r0]
	movs r0, 0x1E
	ldrsh r1, [r4, r0]
	lsls r2, r1, 2
	adds r0, r4, 0
	adds r0, 0x34
	adds r0, r2
	ldr r0, [r0]
	adds r2, r4, 0
	adds r2, 0x4C
	adds r3, r4, 0
	adds r3, 0xB0
	adds r4, 0xE0
	ldr r4, [r4]
	str r4, [sp]
	bl sub_808F844
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024600: .4byte gUnknown_203B2AC
	thumb_func_end sub_80245D0

	thumb_func_start sub_8024604
sub_8024604:
	push {r4,r5,lr}
	ldr r4, _08024654
	ldr r0, [r4]
	movs r1, 0x2
	str r1, [r0, 0x34]
	movs r1, 0x3
	str r1, [r0, 0x38]
	movs r1, 0x5
	str r1, [r0, 0x3C]
	adds r1, r0, 0
	adds r1, 0xE0
	ldr r3, [r1]
	movs r1, 0x3
	movs r2, 0x1
	bl sub_8013818
	ldr r0, [r4]
	adds r5, r0, 0
	adds r5, 0x4C
	ldr r2, _08024658
	adds r0, 0x48
	movs r3, 0
	ldrsh r1, [r0, r3]
	movs r0, 0x58
	muls r0, r1
	ldr r4, [r2]
	adds r4, r0
	movs r0, 0x7
	bl sub_80023E4
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808FF20
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08024654: .4byte gUnknown_203B2AC
_08024658: .4byte gUnknown_203B45C
	thumb_func_end sub_8024604

	thumb_func_start sub_802465C
sub_802465C:
	push {r4,r5,lr}
	bl ResetUnusedInputStruct
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r5, _080246E8
	movs r0, 0xBA
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	movs r4, 0
	str r4, [r0, 0x28]
	str r4, [r0, 0x2C]
	str r4, [r0, 0x30]
	bl sub_808D33C
	ldr r1, [r5]
	str r0, [r1, 0xC]
	bl sub_808D824
	ldr r1, [r5]
	strb r0, [r1, 0x10]
	ldr r0, [r5]
	strb r4, [r0]
	ldr r0, _080246EC
	bl GetDialogueSpriteDataPtr
	ldr r2, [r5]
	movs r3, 0x82
	lsls r3, 1
	adds r1, r2, r3
	str r0, [r1]
	adds r3, 0x4
	adds r1, r2, r3
	ldr r0, [r0, 0x4]
	str r0, [r1]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r2, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r3, 0x9
	adds r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, 0x2
	adds r0, r1
	strb r4, [r0]
	ldr r2, [r5]
	subs r3, 0x5
	adds r1, r2, r3
	movs r0, 0x2
	strh r0, [r1]
	movs r0, 0x87
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x8
	strh r0, [r1]
	movs r0, 0
	bl sub_80247EC
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_080246E8: .4byte gUnknown_203B2B0
_080246EC: .4byte 0x00000155
	thumb_func_end sub_802465C

	thumb_func_start sub_80246F0
sub_80246F0:
	push {lr}
	ldr r0, _08024708
	ldr r0, [r0]
	ldr r0, [r0, 0x20]
	cmp r0, 0x15
	bhi _080247A8
	lsls r0, 2
	ldr r1, _0802470C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08024708: .4byte gUnknown_203B2B0
_0802470C: .4byte _08024710
	.align 2, 0
_08024710:
	.4byte _08024768
	.4byte _08024768
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A4
	.4byte _0802476E
	.4byte _08024774
	.4byte _08024774
	.4byte _0802477A
	.4byte _08024780
	.4byte _08024786
	.4byte _0802478C
	.4byte _0802478C
	.4byte _08024792
	.4byte _08024798
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _080247A8
	.4byte _0802479E
_08024768:
	bl sub_8024E9C
	b _080247AC
_0802476E:
	bl sub_8024F00
	b _080247AC
_08024774:
	bl sub_8024FD4
	b _080247AC
_0802477A:
	bl sub_80250EC
	b _080247AC
_08024780:
	bl sub_80251CC
	b _080247AC
_08024786:
	bl sub_8024F70
	b _080247AC
_0802478C:
	bl sub_8025058
	b _080247AC
_08024792:
	bl sub_802515C
	b _080247AC
_08024798:
	bl sub_80251E8
	b _080247AC
_0802479E:
	bl sub_8025204
	b _080247AC
_080247A4:
	movs r0, 0x3
	b _080247AE
_080247A8:
	bl sub_8025230
_080247AC:
	movs r0, 0
_080247AE:
	pop {r1}
	bx r1
	thumb_func_end sub_80246F0

	thumb_func_start sub_80247B4
sub_80247B4:
	ldr r0, _080247BC
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080247BC: .4byte gUnknown_203B2B0
	thumb_func_end sub_80247B4

	thumb_func_start sub_80247C0
sub_80247C0:
	push {r4,lr}
	ldr r4, _080247E8
	ldr r0, [r4]
	cmp r0, 0
	beq _080247E0
	movs r1, 0x82
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	bl CloseFile
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_080247E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080247E8: .4byte gUnknown_203B2B0
	thumb_func_end sub_80247C0

	thumb_func_start sub_80247EC
sub_80247EC:
	push {lr}
	ldr r1, _08024800
	ldr r1, [r1]
	str r0, [r1, 0x20]
	bl sub_8024804
	bl sub_80248FC
	pop {r0}
	bx r0
	.align 2, 0
_08024800: .4byte gUnknown_203B2B0
	thumb_func_end sub_80247EC

	thumb_func_start sub_8024804
sub_8024804:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802482C
	ldr r0, [r4]
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0, 0x20]
	subs r0, 0x8
	cmp r0, 0x14
	bhi _080248A8
	lsls r0, 2
	ldr r1, _08024830
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802482C: .4byte gUnknown_203B2B0
_08024830: .4byte _08024834
	.align 2, 0
_08024834:
	.4byte _08024888
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248A8
	.4byte _08024888
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248A8
	.4byte _080248A8
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
	.4byte _080248D2
_08024888:
	ldr r0, _080248A0
	ldr r1, [r0]
	movs r2, 0xA2
	lsls r2, 1
	adds r1, r2
	ldr r0, _080248A4
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	b _080248D2
	.align 2, 0
_080248A0: .4byte gUnknown_203B2B0
_080248A4: .4byte gUnknown_80DCA00
_080248A8:
	ldr r3, _080248F4
	mov r12, r3
	movs r4, 0x8A
	lsls r4, 1
	mov r8, r4
	ldr r4, _080248F8
	movs r3, 0
	movs r2, 0x3
_080248B8:
	mov r5, r12
	ldr r1, [r5]
	adds r1, r3
	add r1, r8
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080248B8
_080248D2:
	bl ResetUnusedInputStruct
	ldr r0, _080248F4
	ldr r0, [r0]
	movs r6, 0x8A
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080248F4: .4byte gUnknown_203B2B0
_080248F8: .4byte gUnknown_80DC9E8
	thumb_func_end sub_8024804

	thumb_func_start sub_80248FC
sub_80248FC:
	push {r4,r5,lr}
	sub sp, 0x14
	ldr r1, _08024918
	ldr r0, [r1]
	ldr r0, [r0, 0x20]
	adds r5, r1, 0
	cmp r0, 0x1D
	bls _0802490E
	b _08024CF4
_0802490E:
	lsls r0, 2
	ldr r1, _0802491C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08024918: .4byte gUnknown_203B2B0
_0802491C: .4byte _08024920
	.align 2, 0
_08024920:
	.4byte _08024998
	.4byte _080249D0
	.4byte _080249E8
	.4byte _080249F8
	.4byte _08024CF4
	.4byte _08024A14
	.4byte _08024A20
	.4byte _08024A2E
	.4byte _08024A94
	.4byte _08024AC0
	.4byte _08024A36
	.4byte _08024A68
	.4byte _08024A76
	.4byte _08024A94
	.4byte _08024AC0
	.4byte _08024ACA
	.4byte _08024AD8
	.4byte _08024AE8
	.4byte _08024B4C
	.4byte _08024B74
	.4byte _08024C9C
	.4byte _08024CC8
	.4byte _08024C1C
	.4byte _08024C2C
	.4byte _08024C3C
	.4byte _08024C4C
	.4byte _08024C5C
	.4byte _08024C6C
	.4byte _08024C7C
	.4byte _08024C8C
_08024998:
	bl sub_80252B8
	lsls r0, 24
	cmp r0, 0
	beq _080249B0
	ldr r0, _080249AC
	ldr r1, [r0]
	movs r0, 0x3
	b _080249B6
	.align 2, 0
_080249AC: .4byte gUnknown_203B2B0
_080249B0:
	ldr r0, _080249C8
	ldr r1, [r0]
	movs r0, 0x1
_080249B6:
	str r0, [r1, 0x28]
	bl sub_8024CFC
	ldr r0, _080249CC
	ldr r1, _080249C8
	ldr r1, [r1]
	ldr r2, [r1, 0x28]
	b _08024A42
	.align 2, 0
_080249C8: .4byte gUnknown_203B2B0
_080249CC: .4byte gUnknown_80DCA34
_080249D0:
	bl sub_8024CFC
	ldr r0, _080249E0
	ldr r1, _080249E4
	ldr r1, [r1]
	ldr r2, [r1, 0x28]
	b _08024A42
	.align 2, 0
_080249E0: .4byte gUnknown_80DCAB8
_080249E4: .4byte gUnknown_203B2B0
_080249E8:
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x24]
	ldr r0, _080249F4
	b _08024CAE
	.align 2, 0
_080249F4: .4byte gUnknown_80DCAD0
_080249F8:
	ldr r1, [r5]
	movs r0, 0x4
	str r0, [r1, 0x24]
	movs r0, 0x8
	movs r1, 0x3C
	bl xxx_call_fade_in_new_bgm
	ldr r0, _08024A0C
	ldr r3, _08024A10
	b _08024CB0
	.align 2, 0
_08024A0C: .4byte gUnknown_80DCD5C
_08024A10: .4byte 0x00000305
_08024A14:
	bl sub_8024D48
	ldr r0, _08024A1C
	b _08024A3C
	.align 2, 0
_08024A1C: .4byte gUnknown_80DCD90
_08024A20:
	movs r0, 0x2
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08024CF4
_08024A2E:
	movs r0, 0x1
	bl sub_801A8D0
	b _08024CF4
_08024A36:
	bl sub_8024DBC
	ldr r0, _08024A60
_08024A3C:
	ldr r1, _08024A64
	ldr r1, [r1]
	ldr r2, [r1, 0x2C]
_08024A42:
	adds r3, r1, 0
	adds r3, 0x34
	adds r1, 0x74
	str r1, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	movs r1, 0x5
	str r1, [sp, 0x10]
	movs r1, 0
	bl sub_8014248
	b _08024CF4
	.align 2, 0
_08024A60: .4byte gUnknown_80DCDB8
_08024A64: .4byte gUnknown_203B2B0
_08024A68:
	movs r0, 0x2
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08024A7C
_08024A76:
	movs r0, 0x1
	bl sub_801A8D0
_08024A7C:
	ldr r0, _08024A90
	ldr r0, [r0]
	ldr r0, [r0, 0x14]
	movs r1, 0x1
	bl sub_801AEE4
	bl sub_801A9E0
	b _08024CF4
	.align 2, 0
_08024A90: .4byte gUnknown_203B2B0
_08024A94:
	bl sub_801A9E0
	bl sub_8024E30
	ldr r0, _08024ABC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x84
	adds r1, r2, 0
	adds r1, 0x34
	adds r3, r2, 0
	adds r3, 0x74
	ldr r2, [r2, 0x30]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08024CF4
	.align 2, 0
_08024ABC: .4byte gUnknown_203B2B0
_08024AC0:
	ldr r0, [r5]
	adds r0, 0x1C
	bl sub_801B3C0
	b _08024CF4
_08024ACA:
	ldr r1, [r5]
	movs r0, 0x5
	str r0, [r1, 0x24]
	ldr r0, _08024AD4
	b _08024CAE
	.align 2, 0
_08024AD4: .4byte gUnknown_80DCDDC
_08024AD8:
	ldr r1, [r5]
	movs r0, 0xA
	str r0, [r1, 0x24]
	ldr r0, _08024AE4
	b _08024CAE
	.align 2, 0
_08024AE4: .4byte gUnknown_80DCE18
_08024AE8:
	bl sub_8025254
	ldr r0, _08024B00
	ldr r1, [r0]
	ldrh r2, [r1, 0x8]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08024B04
	movs r0, 0x12
	b _08024B3A
	.align 2, 0
_08024B00: .4byte gUnknown_203B2B0
_08024B04:
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r0, 0x4
	bne _08024B10
	movs r0, 0x18
	b _08024B3A
_08024B10:
	cmp r0, 0x2
	bne _08024B18
	movs r0, 0x17
	b _08024B3A
_08024B18:
	cmp r0, 0x10
	bne _08024B20
	movs r0, 0x1B
	b _08024B3A
_08024B20:
	cmp r0, 0x20
	bne _08024B28
	movs r0, 0x19
	b _08024B3A
_08024B28:
	cmp r0, 0x40
	bne _08024B30
	movs r0, 0x1A
	b _08024B3A
_08024B30:
	cmp r0, 0x8
	bne _08024B38
	movs r0, 0x1C
	b _08024B3A
_08024B38:
	movs r0, 0x1D
_08024B3A:
	str r0, [r1, 0x24]
	movs r0, 0x3C
	bl sub_8011930
	ldr r0, _08024B48
	b _08024CAE
	.align 2, 0
_08024B48: .4byte gUnknown_80DCE38
_08024B4C:
	ldr r0, _08024B68
	ldr r1, [r5]
	ldr r1, [r1, 0xC]
	movs r2, 0x5
	bl sub_808D9AC
	ldr r0, _08024B6C
	bl sub_8011988
	ldr r1, [r5]
	movs r0, 0x13
	str r0, [r1, 0x24]
	ldr r0, _08024B70
	b _08024CAE
	.align 2, 0
_08024B68: .4byte gPlayerName
_08024B6C: .4byte 0x000001ff
_08024B70: .4byte gUnknown_80DCE68
_08024B74:
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	ldr r4, _08024C10
	adds r0, r4, 0
	bl strcpy
	ldr r0, [r5]
	movs r2, 0xA
	ldrsh r0, [r0, r2]
	bl GetMonSpecies
	adds r1, r0, 0
	adds r4, 0x50
	adds r0, r4, 0
	bl strcpy
	ldr r1, [r5]
	movs r0, 0x1
	strb r0, [r1]
	bl sub_80977D0
	ldr r1, [r5]
	ldr r0, [r1, 0xC]
	movs r2, 0xA
	ldrsh r1, [r1, r2]
	bl sub_808F734
	bl nullsub_104
	bl sub_808D33C
	ldr r1, [r5]
	str r0, [r1, 0xC]
	ldr r0, [r1, 0x14]
	cmp r0, 0x14
	beq _08024BCA
	bl sub_8091234
_08024BCA:
	ldr r0, [r5]
	ldr r0, [r0, 0x18]
	cmp r0, 0x14
	beq _08024BD6
	bl sub_8091234
_08024BD6:
	bl sub_80910B4
	ldr r0, _08024C14
	bl sub_801199C
	movs r0, 0xD2
	bl sub_8011988
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _08024C06
	ldr r0, [r1, 0xC]
	adds r4, r0, 0
	adds r4, 0x4C
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
_08024C06:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C18
	b _08024CAE
	.align 2, 0
_08024C10: .4byte gAvailablePokemonNames
_08024C14: .4byte 0x000001ff
_08024C18: .4byte gUnknown_80DCEB0
_08024C1C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C28
	b _08024CAE
	.align 2, 0
_08024C28: .4byte gUnknown_80DCEDC
_08024C2C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C38
	b _08024CAE
	.align 2, 0
_08024C38: .4byte gUnknown_80DCF44
_08024C3C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C48
	b _08024CAE
	.align 2, 0
_08024C48: .4byte gUnknown_80DCF88
_08024C4C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C58
	b _08024CAE
	.align 2, 0
_08024C58: .4byte gUnknown_80DCFAC
_08024C5C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C68
	b _08024CAE
	.align 2, 0
_08024C68: .4byte gUnknown_80DCFF4
_08024C6C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C78
	b _08024CAE
	.align 2, 0
_08024C78: .4byte gUnknown_80DD054
_08024C7C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C88
	b _08024CAE
	.align 2, 0
_08024C88: .4byte gUnknown_80DD098
_08024C8C:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1, 0x24]
	ldr r0, _08024C98
	b _08024CAE
	.align 2, 0
_08024C98: .4byte gUnknown_80DD0E0
_08024C9C:
	movs r0, 0x8
	movs r1, 0x3C
	bl xxx_call_fade_in_new_bgm
	ldr r0, _08024CBC
	ldr r1, [r0]
	movs r0, 0x15
	str r0, [r1, 0x24]
	ldr r0, _08024CC0
_08024CAE:
	ldr r3, _08024CC4
_08024CB0:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08024CF4
	.align 2, 0
_08024CBC: .4byte gUnknown_203B2B0
_08024CC0: .4byte gUnknown_80DD104
_08024CC4: .4byte 0x00000105
_08024CC8:
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	cmp r0, 0
	beq _08024CE8
	ldr r0, [r1, 0xC]
	adds r4, r0, 0
	adds r4, 0x4C
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
_08024CE8:
	ldr r0, [r5]
	ldr r1, [r0, 0xC]
	adds r1, 0x4C
	movs r0, 0
	bl sub_801602C
_08024CF4:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80248FC

	thumb_func_start sub_8024CFC
sub_8024CFC:
	push {r4,lr}
	ldr r4, _08024D38
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r4]
	movs r3, 0
	ldr r0, _08024D3C
	str r0, [r1, 0x34]
	movs r0, 0x3
	str r0, [r1, 0x38]
	movs r2, 0x1
	ldr r0, _08024D40
	ldr r0, [r0]
	str r0, [r1, 0x3C]
	movs r0, 0x2
	str r0, [r1, 0x40]
	ldr r0, _08024D44
	ldr r0, [r0]
	str r0, [r1, 0x44]
	str r2, [r1, 0x48]
	str r3, [r1, 0x4C]
	str r2, [r1, 0x50]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024D38: .4byte gUnknown_203B2B0
_08024D3C: .4byte gUnknown_80DCA18
_08024D40: .4byte gUnknown_80D4970
_08024D44: .4byte gUnknown_80D4934
	thumb_func_end sub_8024CFC

	thumb_func_start sub_8024D48
sub_8024D48:
	push {r4-r7,lr}
	ldr r4, _08024DAC
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08024DB0
	str r0, [r3, 0x34]
	movs r0, 0x4
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08024DB4
	str r0, [r3, 0x3C]
	movs r0, 0x5
	str r0, [r3, 0x40]
	ldr r0, _08024DB8
	ldr r0, [r0]
	str r0, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r6, 0x3
	str r2, [r3, 0x4C]
	str r1, [r3, 0x50]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_08024D86:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08024D96
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x2C]
	cmp r1, r0
	beq _08024DA6
_08024D96:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08024D86
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0x2C]
_08024DA6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024DAC: .4byte gUnknown_203B2B0
_08024DB0: .4byte gUnknown_80DCA24
_08024DB4: .4byte gUnknown_80DCA2C
_08024DB8: .4byte gUnknown_80D4934
	thumb_func_end sub_8024D48

	thumb_func_start sub_8024DBC
sub_8024DBC:
	push {r4-r7,lr}
	ldr r4, _08024E20
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08024E24
	str r0, [r3, 0x34]
	movs r0, 0x4
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08024E28
	str r0, [r3, 0x3C]
	movs r0, 0x5
	str r0, [r3, 0x40]
	ldr r0, _08024E2C
	ldr r0, [r0]
	str r0, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r6, 0x3
	str r2, [r3, 0x4C]
	str r1, [r3, 0x50]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_08024DFA:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08024E0A
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x2C]
	cmp r1, r0
	beq _08024E1A
_08024E0A:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08024DFA
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1, 0x2C]
_08024E1A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024E20: .4byte gUnknown_203B2B0
_08024E24: .4byte gUnknown_80DCA24
_08024E28: .4byte gUnknown_80DCA2C
_08024E2C: .4byte gUnknown_80D4934
	thumb_func_end sub_8024DBC

	thumb_func_start sub_8024E30
sub_8024E30:
	push {r4-r7,lr}
	ldr r4, _08024E90
	ldr r0, [r4]
	adds r0, 0x74
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08024E94
	str r0, [r3, 0x34]
	movs r0, 0x5
	str r0, [r3, 0x38]
	movs r1, 0x1
	ldr r0, _08024E98
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	movs r0, 0x2
	str r0, [r3, 0x40]
	movs r6, 0x2
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x38
	mov r2, r12
	adds r2, 0x74
_08024E68:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08024E78
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x30]
	cmp r1, r0
	beq _08024E88
_08024E78:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08024E68
	ldr r1, [r4]
	movs r0, 0x5
	str r0, [r1, 0x30]
_08024E88:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024E90: .4byte gUnknown_203B2B0
_08024E94: .4byte gUnknown_80DCA2C
_08024E98: .4byte gUnknown_80D4970
	thumb_func_end sub_8024E30

	thumb_func_start sub_8024E9C
sub_8024E9C:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08024EF8
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08024EB6
	ldr r0, _08024EC8
	ldr r0, [r0]
	str r1, [r0, 0x28]
_08024EB6:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08024EEA
	cmp r0, 0x2
	bgt _08024ECC
	cmp r0, 0x1
	beq _08024EF2
	b _08024EF8
	.align 2, 0
_08024EC8: .4byte gUnknown_203B2B0
_08024ECC:
	cmp r0, 0x3
	bne _08024EF8
	bl sub_80252B8
	lsls r0, 24
	cmp r0, 0
	beq _08024EE2
	movs r0, 0x5
	bl sub_80247EC
	b _08024EF8
_08024EE2:
	movs r0, 0x16
	bl sub_80247EC
	b _08024EF8
_08024EEA:
	movs r0, 0x2
	bl sub_80247EC
	b _08024EF8
_08024EF2:
	movs r0, 0x3
	bl sub_80247EC
_08024EF8:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8024E9C

	thumb_func_start sub_8024F00
sub_8024F00:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08024F6A
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08024F1A
	ldr r0, _08024F2C
	ldr r0, [r0]
	str r1, [r0, 0x2C]
_08024F1A:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08024F36
	cmp r0, 0x4
	bgt _08024F30
	cmp r0, 0x1
	beq _08024F64
	b _08024F6A
	.align 2, 0
_08024F2C: .4byte gUnknown_203B2B0
_08024F30:
	cmp r0, 0x5
	beq _08024F4C
	b _08024F6A
_08024F36:
	ldr r0, _08024F48
	ldr r1, [r0]
	movs r0, 0x14
	str r0, [r1, 0x14]
	str r0, [r1, 0x18]
	movs r0, 0x11
	bl sub_80247EC
	b _08024F6A
	.align 2, 0
_08024F48: .4byte gUnknown_203B2B0
_08024F4C:
	bl sub_8090A34
	cmp r0, 0
	bne _08024F5C
	movs r0, 0xF
	bl sub_80247EC
	b _08024F6A
_08024F5C:
	movs r0, 0x6
	bl sub_80247EC
	b _08024F6A
_08024F64:
	movs r0, 0x1
	bl sub_80247EC
_08024F6A:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8024F00

	thumb_func_start sub_8024F70
sub_8024F70:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08024FCC
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08024F8A
	ldr r0, _08024F9C
	ldr r0, [r0]
	str r1, [r0, 0x2C]
_08024F8A:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08024FA6
	cmp r0, 0x4
	bgt _08024FA0
	cmp r0, 0x1
	beq _08024FC6
	b _08024FCC
	.align 2, 0
_08024F9C: .4byte gUnknown_203B2B0
_08024FA0:
	cmp r0, 0x5
	beq _08024FAE
	b _08024FCC
_08024FA6:
	movs r0, 0x11
	bl sub_80247EC
	b _08024FCC
_08024FAE:
	bl sub_8090A34
	cmp r0, 0x1
	bgt _08024FBE
	movs r0, 0x10
	bl sub_80247EC
	b _08024FCC
_08024FBE:
	movs r0, 0xB
	bl sub_80247EC
	b _08024FCC
_08024FC6:
	movs r0, 0x1
	bl sub_80247EC
_08024FCC:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8024F70

	thumb_func_start sub_8024FD4
sub_8024FD4:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08024FF0
	cmp r0, 0x3
	bhi _08024FEA
	cmp r0, 0x2
	beq _08025048
	b _08025052
_08024FEA:
	cmp r0, 0x4
	beq _0802501C
	b _08025052
_08024FF0:
	bl sub_801A8AC
	ldr r1, _08025014
	ldr r2, [r1]
	str r0, [r2, 0x14]
	movs r1, 0x14
	str r1, [r2, 0x18]
	ldr r1, _08025018
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0x8
	bl sub_80247EC
	b _08025052
	.align 2, 0
_08025014: .4byte gUnknown_203B2B0
_08025018: .4byte gUnknown_203B460
_0802501C:
	bl sub_801A8AC
	ldr r1, _08025040
	ldr r2, [r1]
	ldr r1, _08025044
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0
	bl sub_8099690
	movs r0, 0x9
	bl sub_80247EC
	b _08025052
	.align 2, 0
_08025040: .4byte gUnknown_203B2B0
_08025044: .4byte gUnknown_203B460
_08025048:
	bl sub_801A928
	movs r0, 0x5
	bl sub_80247EC
_08025052:
	pop {r0}
	bx r0
	thumb_func_end sub_8024FD4

	thumb_func_start sub_8025058
sub_8025058:
	push {r4,r5,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08025074
	cmp r0, 0x3
	bhi _0802506E
	cmp r0, 0x2
	beq _080250DC
	b _080250E6
_0802506E:
	cmp r0, 0x4
	beq _080250B0
	b _080250E6
_08025074:
	ldr r5, _080250A0
	ldr r4, [r5]
	bl sub_801A8AC
	ldr r1, [r4, 0x14]
	cmp r1, r0
	beq _080250A8
	bl sub_801A8AC
	ldr r2, [r5]
	str r0, [r2, 0x18]
	ldr r1, _080250A4
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0xD
	bl sub_80247EC
	b _080250E6
	.align 2, 0
_080250A0: .4byte gUnknown_203B2B0
_080250A4: .4byte gUnknown_203B460
_080250A8:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _080250E6
_080250B0:
	bl sub_801A8AC
	ldr r1, _080250D4
	ldr r2, [r1]
	ldr r1, _080250D8
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_80247EC
	b _080250E6
	.align 2, 0
_080250D4: .4byte gUnknown_203B2B0
_080250D8: .4byte gUnknown_203B460
_080250DC:
	bl sub_801A928
	movs r0, 0xA
	bl sub_80247EC
_080250E6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8025058

	thumb_func_start sub_80250EC
sub_80250EC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0802512C
	ldr r0, [r4]
	adds r0, 0x84
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802511C
	ldr r0, [r4]
	adds r0, 0x84
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802511C
	ldr r0, [r4]
	str r1, [r0, 0x30]
_0802511C:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08025140
	cmp r0, 0x2
	bgt _08025130
	cmp r0, 0x1
	beq _0802514E
	b _08025154
	.align 2, 0
_0802512C: .4byte gUnknown_203B2B0
_08025130:
	cmp r0, 0x5
	bne _08025154
	bl sub_801A928
	movs r0, 0xA
	bl sub_80247EC
	b _08025154
_08025140:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x9
	bl sub_80247EC
	b _08025154
_0802514E:
	movs r0, 0x7
	bl sub_80247EC
_08025154:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80250EC

	thumb_func_start sub_802515C
sub_802515C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0802519C
	ldr r0, [r4]
	adds r0, 0x84
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802518C
	ldr r0, [r4]
	adds r0, 0x84
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802518C
	ldr r0, [r4]
	str r1, [r0, 0x30]
_0802518C:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _080251B0
	cmp r0, 0x2
	bgt _080251A0
	cmp r0, 0x1
	beq _080251BE
	b _080251C4
	.align 2, 0
_0802519C: .4byte gUnknown_203B2B0
_080251A0:
	cmp r0, 0x5
	bne _080251C4
	bl sub_801A928
	movs r0, 0x11
	bl sub_80247EC
	b _080251C4
_080251B0:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_80247EC
	b _080251C4
_080251BE:
	movs r0, 0xC
	bl sub_80247EC
_080251C4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802515C

	thumb_func_start sub_80251CC
sub_80251CC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _080251E4
	cmp r0, 0x3
	bhi _080251E4
	bl sub_801B450
	movs r0, 0x7
	bl sub_80247EC
_080251E4:
	pop {r0}
	bx r0
	thumb_func_end sub_80251CC

	thumb_func_start sub_80251E8
sub_80251E8:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08025200
	cmp r0, 0x3
	bhi _08025200
	bl sub_801B450
	movs r0, 0xC
	bl sub_80247EC
_08025200:
	pop {r0}
	bx r0
	thumb_func_end sub_80251E8

	thumb_func_start sub_8025204
sub_8025204:
	push {r4,lr}
	bl sub_8016080
	cmp r0, 0x3
	bne _08025226
	bl sub_80160D8
	ldr r4, _0802522C
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_808D824
	ldr r1, [r4]
	strb r0, [r1, 0x10]
	movs r0, 0x3
	bl sub_80247EC
_08025226:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802522C: .4byte gUnknown_203B2B0
	thumb_func_end sub_8025204

	thumb_func_start sub_8025230
sub_8025230:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08025248
	ldr r0, _08025250
	ldr r0, [r0]
	ldr r0, [r0, 0x24]
	bl sub_80247EC
_08025248:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08025250: .4byte gUnknown_203B2B0
	thumb_func_end sub_8025230

	thumb_func_start sub_8025254
sub_8025254:
	push {lr}
	ldr r0, _08025268
	ldr r2, [r0]
	ldr r1, [r2, 0x14]
	adds r3, r0, 0
	cmp r1, 0x14
	bne _0802526C
	movs r0, 0
	b _08025276
	.align 2, 0
_08025268: .4byte gUnknown_203B2B0
_0802526C:
	ldr r0, _08025284
	ldr r0, [r0]
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
_08025276:
	strb r0, [r2, 0x4]
	ldr r2, [r3]
	ldr r1, [r2, 0x18]
	cmp r1, 0x14
	bne _08025288
	movs r0, 0
	b _08025292
	.align 2, 0
_08025284: .4byte gUnknown_203B460
_08025288:
	ldr r0, _080252B0
	ldr r0, [r0]
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
_08025292:
	strb r0, [r2, 0x5]
	movs r0, 0xFF
	bl RandomCapped
	ldr r2, _080252B4
	ldr r1, [r2]
	strb r0, [r1, 0x6]
	ldr r1, [r2]
	ldr r0, [r1, 0xC]
	adds r1, 0x4
	movs r2, 0x1
	bl sub_808F468
	pop {r0}
	bx r0
	.align 2, 0
_080252B0: .4byte gUnknown_203B460
_080252B4: .4byte gUnknown_203B2B0
	thumb_func_end sub_8025254

	thumb_func_start sub_80252B8
sub_80252B8:
	push {r4,lr}
	ldr r0, _080252E0
	ldr r1, [r0]
	movs r3, 0
	movs r4, 0x1
	ldr r2, _080252E4
_080252C4:
	ldrh r0, [r1]
	lsrs r0, 1
	ands r0, r4
	cmp r0, 0
	beq _080252D0
	adds r3, 0x1
_080252D0:
	subs r2, 0x1
	adds r1, 0x58
	cmp r2, 0
	bne _080252C4
	cmp r3, 0x1
	beq _080252E8
	movs r0, 0
	b _080252EA
	.align 2, 0
_080252E0: .4byte gUnknown_203B45C
_080252E4: .4byte 0x0000019d
_080252E8:
	movs r0, 0x1
_080252EA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80252B8

	thumb_func_start sub_80252F0
sub_80252F0:
	push {r4-r6,lr}
	adds r6, r0, 0
	cmp r6, 0x2
	bne _08025308
	movs r0, 0x4
	bl sub_8024108
	lsls r0, 24
	cmp r0, 0
	beq _08025308
	movs r0, 0
	b _0802534C
_08025308:
	ldr r4, _08025340
	movs r0, 0xBC
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r5, 0
	str r5, [r0, 0x70]
	str r6, [r0]
	bl sub_80A5728
	lsls r0, 16
	asrs r0, 16
	bl sub_8002658
	ldr r1, [r4]
	strb r0, [r1, 0xC]
	ldr r0, [r4]
	strb r5, [r0, 0xD]
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x2
	bne _08025344
	movs r0, 0
	bl sub_8025434
	b _0802534A
	.align 2, 0
_08025340: .4byte gUnknown_203B2B4
_08025344:
	movs r0, 0x1
	bl sub_8025434
_0802534A:
	movs r0, 0x1
_0802534C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80252F0

	thumb_func_start sub_8025354
sub_8025354:
	push {lr}
	ldr r0, _0802536C
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	subs r0, 0x1
	cmp r0, 0x12
	bhi _08025400
	lsls r0, 2
	ldr r1, _08025370
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802536C: .4byte gUnknown_203B2B4
_08025370: .4byte _08025374
	.align 2, 0
_08025374:
	.4byte _080253C4
	.4byte _080253C4
	.4byte _080253CA
	.4byte _080253D0
	.4byte _080253D6
	.4byte _08025400
	.4byte _08025400
	.4byte _08025400
	.4byte _08025400
	.4byte _08025400
	.4byte _080253DC
	.4byte _080253DC
	.4byte _080253E2
	.4byte _080253E8
	.4byte _080253EE
	.4byte _080253EE
	.4byte _080253F4
	.4byte _080253FA
	.4byte _080253C0
_080253C0:
	movs r0, 0x3
	b _08025406
_080253C4:
	bl sub_80259F0
	b _08025404
_080253CA:
	bl sub_8025A84
	b _08025404
_080253D0:
	bl sub_8025BCC
	b _08025404
_080253D6:
	bl sub_8025BE8
	b _08025404
_080253DC:
	bl sub_8025C04
	b _08025404
_080253E2:
	bl sub_8025CB4
	b _08025404
_080253E8:
	bl sub_8025D90
	b _08025404
_080253EE:
	bl sub_8025DAC
	b _08025404
_080253F4:
	bl sub_8025E08
	b _08025404
_080253FA:
	bl sub_8025E24
	b _08025404
_08025400:
	bl sub_8025E44
_08025404:
	movs r0, 0
_08025406:
	pop {r1}
	bx r1
	thumb_func_end sub_8025354

	thumb_func_start sub_802540C
sub_802540C:
	ldr r0, _08025414
	ldr r0, [r0]
	ldrb r0, [r0, 0xD]
	bx lr
	.align 2, 0
_08025414: .4byte gUnknown_203B2B4
	thumb_func_end sub_802540C

	thumb_func_start sub_8025418
sub_8025418:
	push {r4,lr}
	ldr r4, _08025430
	ldr r0, [r4]
	cmp r0, 0
	beq _0802542A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802542A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08025430: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025418

	thumb_func_start sub_8025434
sub_8025434:
	push {lr}
	ldr r1, _08025448
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_802544C
	bl sub_8025518
	pop {r0}
	bx r0
	.align 2, 0
_08025448: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025434

	thumb_func_start sub_802544C
sub_802544C:
	push {r4-r7,lr}
	ldr r4, _08025470
	ldr r0, [r4]
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x3
	beq _08025478
	cmp r0, 0xD
	beq _080254B0
	movs r2, 0
	ldr r3, _08025474
	b _080254D8
	.align 2, 0
_08025470: .4byte gUnknown_203B2B4
_08025474: .4byte gUnknown_80DD148
_08025478:
	ldr r0, [r1]
	cmp r0, 0
	bne _0802548E
	movs r2, 0xB0
	lsls r2, 1
	adds r1, r2
	ldr r0, _080254A8
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
_0802548E:
	bl sub_8025728
	ldr r2, [r4]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r0
	ldr r1, _080254AC
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	b _080254C6
	.align 2, 0
_080254A8: .4byte gUnknown_80DD190
_080254AC: .4byte gUnknown_80DD160
_080254B0:
	bl sub_802591C
	ldr r2, [r4]
	movs r0, 0xA4
	lsls r0, 1
	adds r2, r0
	ldr r1, _080254D4
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldm r1!, {r3,r6,r7}
	stm r2!, {r3,r6,r7}
_080254C6:
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xC8
	bl sub_8012CAC
	b _080254F8
	.align 2, 0
_080254D4: .4byte gUnknown_80DD178
_080254D8:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	movs r5, 0x8C
	lsls r5, 1
	adds r0, r5
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _080254D8
_080254F8:
	bl ResetUnusedInputStruct
	ldr r0, _08025514
	ldr r0, [r0]
	movs r6, 0x8C
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025514: .4byte gUnknown_203B2B4
	thumb_func_end sub_802544C

	thumb_func_start sub_8025518
sub_8025518:
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r1, _08025534
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r5, r1, 0
	cmp r0, 0x13
	bls _0802552A
	b _08025720
_0802552A:
	lsls r0, 2
	ldr r1, _08025538
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025534: .4byte gUnknown_203B2B4
_08025538: .4byte _0802553C
	.align 2, 0
_0802553C:
	.4byte _0802558C
	.4byte _080255A0
	.4byte _080255BA
	.4byte _080255C2
	.4byte _0802560C
	.4byte _0802561A
	.4byte _08025720
	.4byte _080256A8
	.4byte _0802567A
	.4byte _08025688
	.4byte _08025698
	.4byte _08025626
	.4byte _08025634
	.4byte _0802563C
	.4byte _08025668
	.4byte _080256CC
	.4byte _080256F2
	.4byte _080256FC
	.4byte _08025714
	.4byte _08025720
_0802558C:
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x8]
	ldr r0, _08025598
	ldr r3, _0802559C
	b _080256B8
	.align 2, 0
_08025598: .4byte gUnknown_80DD1A8
_0802559C: .4byte 0x00000301
_080255A0:
	movs r1, 0x4
	ldr r0, [r5]
	ldr r0, [r0]
	cmp r0, 0
	bne _080255AC
	movs r1, 0x2
_080255AC:
	adds r0, r1, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_8023868
	b _08025720
_080255BA:
	movs r0, 0x1
	bl sub_8023B7C
	b _08025720
_080255C2:
	ldr r1, [r5]
	ldr r0, [r1]
	cmp r0, 0
	bne _080255D2
	adds r1, 0x18
	movs r0, 0x3
	bl sub_8025E68
_080255D2:
	bl sub_8023DA4
	ldr r4, _08025608
	ldr r0, [r5]
	ldr r1, [r0, 0x1C]
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x1C]
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x78
	adds r1, r2, 0
	adds r1, 0xC8
	movs r4, 0x84
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x70]
	b _08025654
	.align 2, 0
_08025608: .4byte gAvailablePokemonNames
_0802560C:
	ldr r0, [r5]
	movs r1, 0xE
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _08025720
_0802561A:
	ldr r0, [r5]
	movs r4, 0xE
	ldrsh r0, [r0, r4]
	bl sub_801BEEC
	b _08025720
_08025626:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _08025720
_08025634:
	movs r0, 0x1
	bl sub_801A8D0
	b _08025720
_0802563C:
	bl sub_801A9E0
	ldr r0, _08025664
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x78
	adds r1, r2, 0
	adds r1, 0xC8
	movs r4, 0x84
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x74]
_08025654:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _08025720
	.align 2, 0
_08025664: .4byte gUnknown_203B2B4
_08025668:
	ldr r1, [r5]
	adds r1, 0x14
	add r0, sp, 0x8
	bl sub_8090B64
	add r0, sp, 0x8
	bl sub_801B3C0
	b _08025720
_0802567A:
	ldr r1, [r5]
	movs r0, 0x2
	str r0, [r1, 0x8]
	ldr r0, _08025684
	b _080256B6
	.align 2, 0
_08025684: .4byte gUnknown_80DD1C8
_08025688:
	ldr r1, [r5]
	movs r0, 0x2
	str r0, [r1, 0x8]
	ldr r0, _08025694
	b _080256B6
	.align 2, 0
_08025694: .4byte gUnknown_80DD1EC
_08025698:
	ldr r1, [r5]
	movs r0, 0x2
	str r0, [r1, 0x8]
	ldr r0, _080256A4
	b _080256B6
	.align 2, 0
_080256A4: .4byte gUnknown_80DD240
_080256A8:
	ldr r1, [r5]
	movs r0, 0x1
	str r0, [r1, 0x8]
	movs r0, 0xCF
	bl sub_8011988
	ldr r0, _080256C4
_080256B6:
	ldr r3, _080256C8
_080256B8:
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08025720
	.align 2, 0
_080256C4: .4byte gUnknown_80DD270
_080256C8: .4byte 0x00000101
_080256CC:
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x1C]
	adds r1, 0x2C
	bl sub_809401C
	ldr r2, [r5]
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	adds r2, 0x28
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl sub_801EE10
	b _08025720
_080256F2:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _08025720
_080256FC:
	ldr r2, [r5]
	ldr r0, [r2, 0x20]
	adds r1, r2, 0
	adds r1, 0x28
	adds r2, 0x68
	bl sub_8093560
	ldr r0, [r5]
	adds r0, 0x68
	bl sub_801F808
	b _08025720
_08025714:
	ldr r0, [r5]
	ldr r1, [r0, 0x1C]
	adds r1, 0x4C
	movs r0, 0x2
	bl sub_801602C
_08025720:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8025518

	thumb_func_start sub_8025728
sub_8025728:
	push {r4-r7,lr}
	ldr r3, _080257CC
	ldr r5, _080257D0
	ldr r0, [r5]
	movs r1, 0xE
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r7, r1, r2
	movs r2, 0x84
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r4, [r5]
	ldr r0, [r4]
	cmp r0, 0
	bne _080257E0
	adds r1, r4, 0
	adds r1, 0xC8
	ldr r0, _080257D4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0xA
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _08025774
	ldr r0, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_08025774:
	movs r6, 0x1
	ldr r1, [r5]
	adds r2, r1, 0
	adds r2, 0xD0
	ldr r0, _080257D8
	str r0, [r2]
	adds r1, 0xD4
	movs r0, 0xB
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08025796
	ldr r0, [r5]
	ldrb r0, [r0, 0x18]
	cmp r0, 0
	bne _080257A0
_08025796:
	ldr r0, [r5]
	movs r1, 0x85
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_080257A0:
	adds r6, 0x1
	adds r0, r7, 0
	bl sub_8025EC4
	lsls r0, 24
	cmp r0, 0
	beq _08025810
	ldr r0, _080257D0
	ldr r2, [r0]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xC8
	adds r0, r3
	ldr r1, _080257DC
	str r1, [r0]
	adds r2, 0xCC
	adds r2, r3
	movs r0, 0x9
	str r0, [r2]
	adds r6, 0x1
	b _08025810
	.align 2, 0
_080257CC: .4byte gUnknown_203B45C
_080257D0: .4byte gUnknown_203B2B4
_080257D4: .4byte gUnknown_80DD2B0
_080257D8: .4byte gUnknown_80DD2B8
_080257DC: .4byte gUnknown_80DD2C0
_080257E0:
	adds r1, r4, 0
	adds r1, 0xC8
	ldr r0, _080258D4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	ldr r0, [r4, 0x1C]
	movs r2, 0x8
	ldrsh r0, [r0, r2]
	bl GetFriendArea
	ldrb r1, [r4, 0xC]
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	bne _0802580E
	ldr r0, [r5]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_0802580E:
	movs r6, 0x1
_08025810:
	movs r0, 0x8
	ldrsh r1, [r7, r0]
	ldr r0, _080258D8
	cmp r1, r0
	bne _08025840
	adds r0, r7, 0
	bl sub_808D824
	lsls r0, 24
	cmp r0, 0
	beq _08025840
	ldr r0, _080258DC
	ldr r2, [r0]
	lsls r3, r6, 3
	adds r0, r2, 0
	adds r0, 0xC8
	adds r0, r3
	ldr r1, _080258E0
	str r1, [r0]
	adds r2, 0xCC
	adds r2, r3
	movs r0, 0x8
	str r0, [r2]
	adds r6, 0x1
_08025840:
	ldr r4, _080258DC
	ldr r5, [r4]
	lsls r1, r6, 3
	adds r3, r5, 0
	adds r3, 0xC8
	adds r2, r3, r1
	ldr r0, _080258E4
	str r0, [r2]
	adds r7, r5, 0
	adds r7, 0xCC
	adds r1, r7, r1
	movs r0, 0x4
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _080258E8
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x6
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _080258EC
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r7, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r6
	bge _080258B2
	movs r1, 0x84
	lsls r1, 1
	adds r4, r5, r1
	adds r2, r7, 0
_0802589A:
	ldrh r0, [r4]
	cmp r0, 0
	bne _080258A8
	ldr r1, [r2]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _08025916
_080258A8:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0802589A
_080258B2:
	movs r3, 0
	cmp r3, r6
	bge _08025916
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0x84
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _080258F0
	adds r0, r1, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08025916
	.align 2, 0
_080258D4: .4byte gUnknown_80DD2CC
_080258D8: .4byte 0x0000013d
_080258DC: .4byte gUnknown_203B2B4
_080258E0: .4byte gUnknown_80DD2D4
_080258E4: .4byte gUnknown_80DD2DC
_080258E8: .4byte gUnknown_80DD2E4
_080258EC: .4byte gUnknown_80DD2EC
_080258F0:
	adds r3, 0x1
	cmp r3, r6
	bge _08025916
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r3, 1
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080258F0
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xCC
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08025916:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8025728

	thumb_func_start sub_802591C
sub_802591C:
	push {r4-r7,lr}
	ldr r5, _080259B8
	ldr r0, [r5]
	movs r7, 0x84
	lsls r7, 1
	adds r0, r7
	movs r1, 0
	movs r2, 0x10
	bl MemoryFill16
	ldr r1, [r5]
	adds r2, r1, 0
	adds r2, 0xC8
	ldr r0, _080259BC
	str r0, [r2]
	adds r1, 0xCC
	movs r0, 0xA
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _08025952
	ldr r0, [r5]
	adds r1, r7, 0
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08025952:
	ldr r4, [r5]
	movs r2, 0x1
	adds r1, r4, 0
	adds r1, 0xD0
	ldr r0, _080259C0
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	adds r1, 0x4
	movs r0, 0
	str r0, [r1]
	adds r0, r4, 0
	adds r0, 0xDC
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	adds r4, r7
	mov r2, r12
	adds r2, 0xCC
_0802597E:
	ldrh r0, [r4]
	cmp r0, 0
	bne _0802598E
	ldr r1, [r2]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _080259E8
_0802598E:
	adds r4, 0x2
	adds r2, 0x8
	adds r3, 0x1
	cmp r3, r6
	blt _0802597E
	movs r3, 0
	cmp r3, r6
	bge _080259E8
	ldr r1, [r5]
	movs r2, 0x84
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _080259C4
	adds r0, r1, 0
	adds r0, 0xCC
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _080259E8
	.align 2, 0
_080259B8: .4byte gUnknown_203B2B4
_080259BC: .4byte gUnknown_80DD2B0
_080259C0: .4byte gUnknown_80D4970
_080259C4:
	adds r3, 0x1
	cmp r3, r6
	bge _080259E8
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0x84
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080259C4
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xCC
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_080259E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802591C

	thumb_func_start sub_80259F0
sub_80259F0:
	push {lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x3
	beq _08025A0C
	cmp r0, 0x3
	bhi _08025A06
	cmp r0, 0x2
	beq _08025A74
	b _08025A7E
_08025A06:
	cmp r0, 0x4
	beq _08025A40
	b _08025A7E
_08025A0C:
	bl sub_8023B44
	ldr r1, _08025A38
	ldr r1, [r1]
	strh r0, [r1, 0xE]
	ldr r3, _08025A3C
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x1C]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl sub_808D7DC
	movs r0, 0x3
	bl sub_8025434
	b _08025A7E
	.align 2, 0
_08025A38: .4byte gUnknown_203B2B4
_08025A3C: .4byte gUnknown_203B45C
_08025A40:
	bl sub_8023B44
	ldr r1, _08025A6C
	ldr r1, [r1]
	strh r0, [r1, 0xE]
	ldr r3, _08025A70
	movs r0, 0xE
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x1C]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl sub_808D7DC
	movs r0, 0x4
	bl sub_8025434
	b _08025A7E
	.align 2, 0
_08025A6C: .4byte gUnknown_203B2B4
_08025A70: .4byte gUnknown_203B45C
_08025A74:
	bl sub_8023C60
	movs r0, 0x13
	bl sub_8025434
_08025A7E:
	pop {r0}
	bx r0
	thumb_func_end sub_80259F0

	thumb_func_start sub_8025A84
sub_8025A84:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _08025AC8
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08025AB4
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08025AB4
	ldr r0, [r4]
	str r1, [r0, 0x70]
_08025AB4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xA
	bls _08025ABE
	b _08025BC2
_08025ABE:
	lsls r0, 2
	ldr r1, _08025ACC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025AC8: .4byte gUnknown_203B2B4
_08025ACC: .4byte _08025AD0
	.align 2, 0
_08025AD0:
	.4byte _08025BBC
	.4byte _08025BC2
	.4byte _08025BC2
	.4byte _08025BAC
	.4byte _08025BB4
	.4byte _08025B9C
	.4byte _08025AFC
	.4byte _08025BA4
	.4byte _08025B70
	.4byte _08025B20
	.4byte _08025B28
_08025AFC:
	ldr r4, _08025B1C
	ldr r0, [r4]
	ldr r0, [r0, 0x1C]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl GetFriendArea
	ldr r1, [r4]
	strb r0, [r1, 0xD]
	bl sub_8023C60
	movs r0, 0x13
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B1C: .4byte gUnknown_203B2B4
_08025B20:
	movs r0, 0xB
	bl sub_8025434
	b _08025BC2
_08025B28:
	ldr r0, _08025B68
	bl sub_8011988
	ldr r4, _08025B6C
	ldr r1, [r4]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	beq _08025B40
	adds r0, r1, 0
	adds r0, 0x18
	bl sub_8091274
_08025B40:
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x18]
	ldr r0, [r4]
	strb r1, [r0, 0x19]
	ldr r1, [r4]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x18
	bl sub_808D800
	bl nullsub_104
	movs r0, 0xA
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B68: .4byte 0x0000014d
_08025B6C: .4byte gUnknown_203B2B4
_08025B70:
	ldr r0, _08025B94
	ldr r0, [r0]
	ldr r2, [r0, 0x1C]
	ldrh r1, [r2]
	ldr r0, _08025B98
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	bl sub_8023C60
	movs r0, 0x7
	bl sub_8025434
	b _08025BC2
	.align 2, 0
_08025B94: .4byte gUnknown_203B2B4
_08025B98: .4byte 0x0000fffd
_08025B9C:
	movs r0, 0xF
	bl sub_8025434
	b _08025BC2
_08025BA4:
	movs r0, 0x12
	bl sub_8025434
	b _08025BC2
_08025BAC:
	movs r0, 0x4
	bl sub_8025434
	b _08025BC2
_08025BB4:
	movs r0, 0x5
	bl sub_8025434
	b _08025BC2
_08025BBC:
	movs r0, 0x2
	bl sub_8025434
_08025BC2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8025A84

	thumb_func_start sub_8025BCC
sub_8025BCC:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08025BE4
	cmp r0, 0x3
	bhi _08025BE4
	bl sub_802453C
	movs r0, 0x2
	bl sub_8025434
_08025BE4:
	pop {r0}
	bx r0
	thumb_func_end sub_8025BCC

	thumb_func_start sub_8025BE8
sub_8025BE8:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08025C00
	cmp r0, 0x3
	bhi _08025C00
	bl sub_801BF98
	movs r0, 0x2
	bl sub_8025434
_08025C00:
	pop {r0}
	bx r0
	thumb_func_end sub_8025BE8

	thumb_func_start sub_8025C04
sub_8025C04:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08025CAE
	lsls r0, 2
	ldr r1, _08025C1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025C1C: .4byte _08025C20
	.align 2, 0
_08025C20:
	.4byte _08025CAE
	.4byte _08025CAE
	.4byte _08025CA4
	.4byte _08025C34
	.4byte _08025C68
_08025C34:
	bl sub_801A8AC
	ldr r4, _08025C60
	ldr r2, [r4]
	str r0, [r2, 0x10]
	ldr r3, _08025C64
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x14]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0x10]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x15]
	movs r0, 0xD
	bl sub_8025434
	b _08025CAE
	.align 2, 0
_08025C60: .4byte gUnknown_203B2B4
_08025C64: .4byte gUnknown_203B460
_08025C68:
	bl sub_801A8AC
	ldr r4, _08025C9C
	ldr r2, [r4]
	str r0, [r2, 0x10]
	ldr r3, _08025CA0
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x14]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0x10]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x15]
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_8025434
	b _08025CAE
	.align 2, 0
_08025C9C: .4byte gUnknown_203B2B4
_08025CA0: .4byte gUnknown_203B460
_08025CA4:
	bl sub_801A928
	movs r0, 0x2
	bl sub_8025434
_08025CAE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8025C04

	thumb_func_start sub_8025CB4
sub_8025CB4:
	push {r4-r6,lr}
	sub sp, 0x14
	movs r0, 0
	str r0, [sp, 0xC]
	bl sub_801A6E8
	ldr r4, _08025CF4
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08025CE4
	ldr r0, [r4]
	adds r0, 0x78
	add r1, sp, 0xC
	bl sub_8013114
	ldr r1, [sp, 0xC]
	cmp r1, 0x1
	beq _08025CE4
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08025CE4:
	ldr r0, [sp, 0xC]
	cmp r0, 0x4
	beq _08025D74
	cmp r0, 0x4
	bgt _08025CF8
	cmp r0, 0x1
	beq _08025D82
	b _08025D88
	.align 2, 0
_08025CF4: .4byte gUnknown_203B2B4
_08025CF8:
	cmp r0, 0xA
	bne _08025D88
	movs r6, 0x8
	ldr r0, _08025D68
	bl sub_8011988
	ldr r5, _08025D6C
	ldr r0, [r5]
	ldr r0, [r0, 0x10]
	bl sub_80911F8
	bl sub_80910B4
	ldr r1, [r5]
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	beq _08025D24
	adds r0, r1, 0
	adds r0, 0x18
	bl sub_8091274
	movs r6, 0x9
_08025D24:
	add r4, sp, 0x10
	ldr r1, [r5]
	adds r1, 0x14
	adds r0, r4, 0
	bl sub_8090B64
	movs r1, 0
	str r1, [sp]
	mov r0, sp
	strb r1, [r0, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08025D70
	adds r1, r4, 0
	mov r2, sp
	bl sub_8090E14
	ldr r1, [r5]
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	bl sub_801A928
	bl nullsub_104
	adds r0, r6, 0
	bl sub_8025434
	b _08025D88
	.align 2, 0
_08025D68: .4byte 0x0000014d
_08025D6C: .4byte gUnknown_203B2B4
_08025D70: .4byte gUnknown_202DEA8
_08025D74:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xE
	bl sub_8025434
	b _08025D88
_08025D82:
	movs r0, 0xC
	bl sub_8025434
_08025D88:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8025CB4

	thumb_func_start sub_8025D90
sub_8025D90:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08025DA8
	cmp r0, 0x3
	bhi _08025DA8
	bl sub_801B450
	movs r0, 0xC
	bl sub_8025434
_08025DA8:
	pop {r0}
	bx r0
	thumb_func_end sub_8025D90

	thumb_func_start sub_8025DAC
sub_8025DAC:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x3
	beq _08025DC6
	cmp r0, 0x3
	bhi _08025DC2
	cmp r0, 0x2
	beq _08025DE4
	b _08025DFE
_08025DC2:
	cmp r0, 0x4
	bne _08025DFE
_08025DC6:
	bl sub_801F194
	ldr r1, _08025DE0
	ldr r1, [r1]
	str r0, [r1, 0x20]
	lsls r0, 3
	adds r0, r1, r0
	ldrh r0, [r0, 0x2A]
	strh r0, [r1, 0x24]
	movs r0, 0x11
	bl sub_8025434
	b _08025DFE
	.align 2, 0
_08025DE0: .4byte gUnknown_203B2B4
_08025DE4:
	bl sub_801F214
	ldr r0, _08025E04
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x1C]
	adds r1, 0x2C
	bl sub_8094060
	movs r0, 0x2
	bl sub_8025434
_08025DFE:
	pop {r0}
	bx r0
	.align 2, 0
_08025E04: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025DAC

	thumb_func_start sub_8025E08
sub_8025E08:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08025E20
	cmp r0, 0x3
	bhi _08025E20
	bl sub_801F8D0
	movs r0, 0x10
	bl sub_8025434
_08025E20:
	pop {r0}
	bx r0
	thumb_func_end sub_8025E08

	thumb_func_start sub_8025E24
sub_8025E24:
	push {lr}
	bl sub_8016080
	cmp r0, 0x3
	bhi _08025E40
	cmp r0, 0x2
	bcc _08025E40
	bl sub_80160D8
	bl nullsub_104
	movs r0, 0x2
	bl sub_8025434
_08025E40:
	pop {r0}
	bx r0
	thumb_func_end sub_8025E24

	thumb_func_start sub_8025E44
sub_8025E44:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08025E5C
	ldr r0, _08025E64
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_8025434
_08025E5C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08025E64: .4byte gUnknown_203B2B4
	thumb_func_end sub_8025E44

	thumb_func_start sub_8025E68
sub_8025E68:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8008C54
	adds r0, r6, 0
	bl sub_80073B8
	add r4, sp, 0x10
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8090B64
	movs r5, 0
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	strb r5, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08025EBC
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_8090E14
	ldr r2, _08025EC0
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x3
	adds r3, r6, 0
	bl sub_8014FF0
	adds r0, r6, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08025EBC: .4byte gUnknown_202DE58
_08025EC0: .4byte gUnknown_80DD2F8
	thumb_func_end sub_8025E68

	thumb_func_start sub_8025EC4
sub_8025EC4:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08025EE8
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08025ED8
	movs r2, 0x1
_08025ED8:
	cmp r2, 0
	beq _08025EEC
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08025EEC
_08025EE8:
	movs r0, 0
	b _08025EEE
_08025EEC:
	movs r0, 0x1
_08025EEE:
	pop {r1}
	bx r1
	thumb_func_end sub_8025EC4

	thumb_func_start sub_8025EF4
sub_8025EF4:
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r6, _08025F1C
	movs r0, 0xA0
	lsls r0, 2
	movs r1, 0x8
	bl MemoryAlloc
	adds r1, r0, 0
	str r1, [r6]
	str r4, [r1, 0x18]
	movs r5, 0
	ldr r0, _08025F20
	ldr r0, [r0]
	cmp r4, r0
	bne _08025F24
	strh r5, [r1, 0xA]
	adds r4, r6, 0
	b _08025F48
	.align 2, 0
_08025F1C: .4byte gUnknown_203B2B8
_08025F20: .4byte gUnknown_203B45C
_08025F24:
	adds r5, 0x1
	movs r0, 0xCE
	lsls r0, 1
	ldr r4, _08025F60
	cmp r5, r0
	bgt _08025F48
	ldr r3, [r4]
	ldr r2, _08025F64
	lsls r0, r5, 16
	asrs r0, 16
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	ldr r1, [r3, 0x18]
	cmp r1, r0
	bne _08025F24
	strh r5, [r3, 0xA]
_08025F48:
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0x70]
	str r0, [r1, 0x74]
	str r0, [r1, 0x78]
	strb r0, [r1, 0x8]
	bl sub_8026074
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08025F60: .4byte gUnknown_203B2B8
_08025F64: .4byte gUnknown_203B45C
	thumb_func_end sub_8025EF4

	thumb_func_start sub_8025F68
sub_8025F68:
	push {lr}
	ldr r0, _08025F80
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x19
	bhi _0802603A
	lsls r0, 2
	ldr r1, _08025F84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025F80: .4byte gUnknown_203B2B8
_08025F84: .4byte _08025F88
	.align 2, 0
_08025F88:
	.4byte _08025FF0
	.4byte _08025FF8
	.4byte _08025FF8
	.4byte _08025FFE
	.4byte _08026004
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802600A
	.4byte _08026010
	.4byte _08026016
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802603A
	.4byte _0802601C
	.4byte _0802601C
	.4byte _08026022
	.4byte _08026028
	.4byte _0802602E
	.4byte _0802602E
	.4byte _08026034
	.4byte _08026040
_08025FF0:
	movs r0, 0x1
	bl sub_8026074
	b _08026044
_08025FF8:
	bl sub_80268CC
	b _08026044
_08025FFE:
	bl sub_8026A78
	b _08026044
_08026004:
	bl sub_8026A94
	b _08026044
_0802600A:
	bl sub_8026AB0
	b _08026044
_08026010:
	bl sub_8026B10
	b _08026044
_08026016:
	bl sub_8026B48
	b _08026044
_0802601C:
	bl sub_8026B64
	b _08026044
_08026022:
	bl sub_8026C14
	b _08026044
_08026028:
	bl sub_8026CF0
	b _08026044
_0802602E:
	bl sub_8026D0C
	b _08026044
_08026034:
	bl sub_8026D6C
	b _08026044
_0802603A:
	bl sub_8026D88
	b _08026044
_08026040:
	movs r0, 0x3
	b _08026046
_08026044:
	movs r0, 0
_08026046:
	pop {r1}
	bx r1
	thumb_func_end sub_8025F68

	thumb_func_start sub_802604C
sub_802604C:
	ldr r0, _08026054
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bx lr
	.align 2, 0
_08026054: .4byte gUnknown_203B2B8
	thumb_func_end sub_802604C

	thumb_func_start sub_8026058
sub_8026058:
	push {r4,lr}
	ldr r4, _08026070
	ldr r0, [r4]
	cmp r0, 0
	beq _0802606A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802606A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026070: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026058

	thumb_func_start sub_8026074
sub_8026074:
	push {lr}
	ldr r1, _08026088
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802608C
	bl sub_80261D0
	pop {r0}
	bx r0
	.align 2, 0
_08026088: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026074

	thumb_func_start sub_802608C
sub_802608C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _080260B8
	ldr r0, [r4]
	movs r5, 0x88
	lsls r5, 2
	adds r0, r5
	bl sub_8006518
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0x1
	blt _08026178
	cmp r0, 0x2
	ble _080260BC
	cmp r0, 0x14
	beq _0802614C
	b _08026178
	.align 2, 0
_080260B8: .4byte gUnknown_203B2B8
_080260BC:
	ldr r0, _0802613C
	mov r12, r0
	ldr r1, _08026140
	mov r8, r1
	mov r9, r4
	mov r10, r5
	movs r3, 0
	movs r2, 0x3
_080260CC:
	mov r5, r9
	ldr r1, [r5]
	adds r1, r3
	add r1, r10
	ldr r0, _08026144
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _080260CC
	ldr r1, [r4]
	movs r6, 0x88
	lsls r6, 2
	adds r1, r6
	mov r0, r12
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldr r1, [r4]
	movs r0, 0x9A
	lsls r0, 2
	adds r1, r0
	mov r0, r8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r6,r7}
	stm r1!, {r2,r6,r7}
	bl sub_80264CC
	ldr r2, [r4]
	movs r0, 0x94
	lsls r0, 2
	adds r2, r0
	ldr r1, _08026148
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xB6
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	ldr r0, [r4]
	movs r7, 0x97
	lsls r7, 2
	adds r0, r7
	movs r1, 0x9
	strh r1, [r0]
	b _080261A2
	.align 2, 0
_0802613C: .4byte gUnknown_80DD358
_08026140: .4byte gUnknown_80DD370
_08026144: .4byte gUnknown_80DD310
_08026148: .4byte gUnknown_80DD328
_0802614C:
	bl sub_802678C
	ldr r2, [r4]
	movs r0, 0x94
	lsls r0, 2
	adds r2, r0
	ldr r1, _08026174
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0xB6
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	b _080261A2
	.align 2, 0
_08026174: .4byte gUnknown_80DD340
_08026178:
	ldr r7, _080261C8
	mov r8, r7
	movs r0, 0x88
	lsls r0, 2
	mov r9, r0
	ldr r4, _080261CC
	movs r3, 0
	movs r2, 0x3
_08026188:
	mov r5, r8
	ldr r1, [r5]
	adds r1, r3
	add r1, r9
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _08026188
_080261A2:
	bl ResetUnusedInputStruct
	ldr r0, _080261C8
	ldr r0, [r0]
	movs r6, 0x88
	lsls r6, 2
	adds r0, r6
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080261C8: .4byte gUnknown_203B2B8
_080261CC: .4byte gUnknown_80DD310
	thumb_func_end sub_802608C

	thumb_func_start sub_80261D0
sub_80261D0:
	push {r4,r5,lr}
	sub sp, 0x18
	ldr r1, _080261EC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x19
	bls _080261E2
	b _080264BA
_080261E2:
	lsls r0, 2
	ldr r1, _080261F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080261EC: .4byte gUnknown_203B2B8
_080261F0: .4byte _080261F4
	.align 2, 0
_080261F4:
	.4byte _080264BA
	.4byte _0802625C
	.4byte _080262A8
	.4byte _080262EC
	.4byte _080262FA
	.4byte _080263F8
	.4byte _0802640C
	.4byte _08026420
	.4byte _08026434
	.4byte _08026448
	.4byte _0802648A
	.4byte _080264A8
	.4byte _08026392
	.4byte _080263AC
	.4byte _08026306
	.4byte _08026464
	.4byte _08026474
	.4byte _08026484
	.4byte _08026310
	.4byte _0802631E
	.4byte _08026326
	.4byte _08026350
	.4byte _08026362
	.4byte _08026388
	.4byte _080263E0
	.4byte _080264BA
_0802625C:
	movs r0, 0x3
	bl sub_8026E08
	ldr r5, _080262A0
	ldr r1, [r5]
	adds r1, 0x14
	movs r0, 0
	bl sub_8026DAC
	ldr r4, _080262A4
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r2, [r5]
	adds r0, r2, 0
	adds r0, 0x7C
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0x83
	lsls r4, 2
	adds r3, r2, r4
	ldr r2, [r2, 0x70]
	b _0802633E
	.align 2, 0
_080262A0: .4byte gUnknown_203B2B8
_080262A4: .4byte gAvailablePokemonNames
_080262A8:
	movs r0, 0x3
	bl sub_8026E08
	ldr r5, _080262E4
	ldr r1, [r5]
	adds r1, 0x14
	movs r0, 0
	bl sub_8026DAC
	ldr r4, _080262E8
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x7
	bl sub_808D9AC
	adds r4, 0x50
	ldr r0, [r5]
	ldr r1, [r0, 0x18]
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r0, [r5]
	adds r0, 0x7C
	movs r1, 0x1
	bl sub_8012EA4
	b _080264BA
	.align 2, 0
_080262E4: .4byte gUnknown_203B2B8
_080262E8: .4byte gAvailablePokemonNames
_080262EC:
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _080264BA
_080262FA:
	ldr r0, [r4]
	movs r3, 0xA
	ldrsh r0, [r0, r3]
	bl sub_801BEEC
	b _080264BA
_08026306:
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_80227B8
	b _080264BA
_08026310:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _080264BA
_0802631E:
	movs r0, 0x1
	bl sub_801A8D0
	b _080264BA
_08026326:
	bl sub_801A9E0
	ldr r0, _0802634C
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0xCC
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r4, 0xA0
	adds r3, r2, r4
	ldr r2, [r2, 0x74]
_0802633E:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _080264BA
	.align 2, 0
_0802634C: .4byte gUnknown_203B2B8
_08026350:
	ldr r1, [r4]
	adds r1, 0x10
	add r0, sp, 0x14
	bl sub_8090B64
	add r0, sp, 0x14
	bl sub_801B3C0
	b _080264BA
_08026362:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x18]
	adds r1, 0x2C
	bl sub_809401C
	ldr r2, [r4]
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	adds r2, 0x28
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl sub_801EE10
	b _080264BA
_08026388:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _080264BA
_08026392:
	bl sub_8026878
	ldr r0, _080263A4
	ldr r1, _080263A8
	ldr r3, [r1]
	movs r1, 0xDE
	lsls r1, 1
	adds r3, r1
	b _080263BC
	.align 2, 0
_080263A4: .4byte gUnknown_80DD388
_080263A8: .4byte gUnknown_203B2B8
_080263AC:
	bl sub_8026878
	ldr r0, _080263D8
	ldr r1, _080263DC
	ldr r3, [r1]
	movs r4, 0xDE
	lsls r4, 1
	adds r3, r4
_080263BC:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _080264BA
	.align 2, 0
_080263D8: .4byte gUnknown_80DD420
_080263DC: .4byte gUnknown_203B2B8
_080263E0:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	adds r1, r2, 0
	adds r1, 0x28
	adds r2, 0x68
	bl sub_8093560
	ldr r0, [r4]
	adds r0, 0x68
	bl sub_801F808
	b _080264BA
_080263F8:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCF
	bl sub_8011988
	ldr r0, _08026408
	b _08026492
	.align 2, 0
_08026408: .4byte gUnknown_80DD4C4
_0802640C:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCF
	bl sub_8011988
	ldr r0, _0802641C
	b _08026492
	.align 2, 0
_0802641C: .4byte gUnknown_80DD4F4
_08026420:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	movs r0, 0xCC
	bl sub_8011988
	ldr r0, _08026430
	b _08026492
	.align 2, 0
_08026430: .4byte gUnknown_80DD534
_08026434:
	ldr r1, [r4]
	movs r0, 0x9
	str r0, [r1, 0x4]
	movs r0, 0xCA
	bl sub_8011988
	ldr r0, _08026444
	b _08026492
	.align 2, 0
_08026444: .4byte gUnknown_80DD564
_08026448:
	bl sub_8026FA4
	ldr r4, _08026460
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x8]
	b _080264BA
	.align 2, 0
_08026460: .4byte gUnknown_203B2B8
_08026464:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08026470
	b _08026492
	.align 2, 0
_08026470: .4byte gUnknown_80DD594
_08026474:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08026480
	b _08026492
	.align 2, 0
_08026480: .4byte gUnknown_80DD5B8
_08026484:
	ldr r1, [r4]
	movs r0, 0x2
	b _0802648E
_0802648A:
	ldr r1, [r4]
	movs r0, 0x19
_0802648E:
	str r0, [r1, 0x4]
	ldr r0, _080264A0
_08026492:
	ldr r3, _080264A4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _080264BA
	.align 2, 0
_080264A0: .4byte gUnknown_80DD60C
_080264A4: .4byte 0x00000101
_080264A8:
	ldr r1, [r4]
	movs r0, 0x19
	str r0, [r1, 0x4]
	ldr r0, _080264C4
	ldr r3, _080264C8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_080264BA:
	add sp, 0x18
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080264C4: .4byte gUnknown_80DD63C
_080264C8: .4byte 0x00000101
	thumb_func_end sub_80261D0

	thumb_func_start sub_80264CC
sub_80264CC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r3, _08026574
	ldr r4, _08026578
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	mov r8, r1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r1, [r4]
	ldr r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	adds r1, 0x14
	bl sub_808D7DC
	mov r1, r8
	ldrh r0, [r1]
	lsrs r0, 1
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	beq _08026584
	ldr r2, [r4]
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _0802657C
	str r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x7
	str r0, [r1]
	mov r0, r8
	bl sub_8026E88
	lsls r0, 24
	cmp r0, 0
	bne _08026542
	ldr r0, [r4]
	movs r1, 0x83
	lsls r1, 2
	adds r0, r1
	strh r5, [r0]
_08026542:
	movs r6, 0x1
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _080265B4
	mov r2, r8
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	bne _080265B4
	ldr r3, [r4]
	movs r2, 0x8
	movs r4, 0xBA
	lsls r4, 1
	adds r1, r3, r4
	ldr r0, _08026580
	str r0, [r1]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	movs r6, 0x2
	b _080265B4
	.align 2, 0
_08026574: .4byte gUnknown_203B45C
_08026578: .4byte gUnknown_203B2B8
_0802657C: .4byte gUnknown_80DD664
_08026580: .4byte gUnknown_80DD670
_08026584:
	ldr r2, [r4]
	movs r3, 0xB6
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _08026734
	str r0, [r1]
	movs r0, 0xB8
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0xA
	ldrsh r0, [r2, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	bne _080265B2
	ldr r0, [r4]
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	strh r5, [r0]
_080265B2:
	movs r6, 0x1
_080265B4:
	ldr r4, _08026738
	ldr r2, [r4]
	lsls r3, r6, 3
	movs r7, 0xB6
	lsls r7, 1
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _0802673C
	str r1, [r0]
	movs r5, 0xB8
	lsls r5, 1
	adds r2, r5
	adds r2, r3
	movs r0, 0xA
	str r0, [r2]
	bl sub_809177C
	lsls r0, 24
	cmp r0, 0
	bne _080265EC
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r3, 0x83
	lsls r3, 2
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_080265EC:
	adds r6, 0x1
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _08026740
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0
	bne _0802661A
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_0802661A:
	adds r6, 0x1
	ldr r2, [r4]
	lsls r3, r6, 3
	adds r0, r2, r7
	adds r0, r3
	ldr r1, _08026744
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xC
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08026640
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _08026650
_08026640:
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r3, 0x83
	lsls r3, 2
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08026650:
	adds r6, 0x1
	mov r4, r8
	ldrh r0, [r4]
	lsrs r0, 1
	movs r5, 0x1
	ands r0, r5
	cmp r0, 0
	bne _0802669A
	ldr r4, _08026738
	ldr r3, [r4]
	lsls r2, r6, 3
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r3, r1
	adds r0, r2
	ldr r1, _08026748
	str r1, [r0]
	movs r1, 0xB8
	lsls r1, 1
	adds r0, r3, r1
	adds r0, r2
	movs r1, 0x9
	str r1, [r0]
	mov r0, r8
	bl sub_8026EB8
	lsls r0, 24
	cmp r0, 0
	bne _08026698
	ldr r0, [r4]
	lsls r1, r6, 1
	movs r2, 0x83
	lsls r2, 2
	adds r0, r2
	adds r0, r1
	strh r5, [r0]
_08026698:
	adds r6, 0x1
_0802669A:
	ldr r4, _08026738
	ldr r5, [r4]
	lsls r1, r6, 3
	movs r0, 0xB6
	lsls r0, 1
	adds r3, r5, r0
	adds r2, r3, r1
	ldr r0, _0802674C
	str r0, [r2]
	movs r2, 0xB8
	lsls r2, 1
	adds r7, r5, r2
	adds r1, r7, r1
	movs r0, 0x4
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _08026750
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0xD
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r2, r3, r1
	ldr r0, _08026754
	str r0, [r2]
	adds r1, r7, r1
	movs r0, 0x5
	str r0, [r1]
	adds r6, 0x1
	lsls r1, r6, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r7, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r6
	bge _08026710
	adds r4, r7, 0
	movs r0, 0x83
	lsls r0, 2
	adds r2, r5, r0
_080266F8:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08026706
	ldr r1, [r4]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _08026780
_08026706:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _080266F8
_08026710:
	movs r3, 0
	cmp r3, r6
	bge _08026780
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0x83
	lsls r4, 2
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _08026758
	movs r2, 0xB8
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _08026780
	.align 2, 0
_08026734: .4byte gUnknown_80DD67C
_08026738: .4byte gUnknown_203B2B8
_0802673C: .4byte gUnknown_80DD688
_08026740: .4byte gUnknown_80DD694
_08026744: .4byte gUnknown_80DD69C
_08026748: .4byte gUnknown_80DD6A4
_0802674C: .4byte gUnknown_80DD6B4
_08026750: .4byte gUnknown_80DD6BC
_08026754: .4byte gUnknown_80DD6C4
_08026758:
	adds r3, 0x1
	cmp r3, r6
	bge _08026780
	mov r4, r12
	ldr r2, [r4]
	lsls r0, r3, 1
	movs r4, 0x83
	lsls r4, 2
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08026758
	lsls r0, r3, 3
	movs r3, 0xB8
	lsls r3, 1
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_08026780:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80264CC

	thumb_func_start sub_802678C
sub_802678C:
	push {r4-r7,lr}
	ldr r5, _08026840
	ldr r0, [r5]
	movs r7, 0x83
	lsls r7, 2
	adds r0, r7
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r2, [r5]
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _08026844
	str r0, [r1]
	movs r3, 0xB8
	lsls r3, 1
	adds r1, r2, r3
	movs r0, 0xB
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _080267C8
	ldr r0, [r5]
	adds r4, r7, 0
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_080267C8:
	ldr r4, [r5]
	movs r2, 0x1
	movs r0, 0xBA
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _08026848
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0xBC
	lsls r3, 1
	adds r1, r4, r3
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	movs r0, 0xBE
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r4, r1
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	movs r4, 0xB8
	lsls r4, 1
	add r4, r12
	mov r0, r12
	adds r2, r0, r7
_08026804:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08026814
	ldr r1, [r4]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _08026872
_08026814:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _08026804
	movs r3, 0
	cmp r3, r6
	bge _08026872
	ldr r1, [r5]
	movs r2, 0x83
	lsls r2, 2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _0802684C
	movs r3, 0xB8
	lsls r3, 1
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _08026872
	.align 2, 0
_08026840: .4byte gUnknown_203B2B8
_08026844: .4byte gUnknown_80DD694
_08026848: .4byte gUnknown_80D4970
_0802684C:
	adds r3, 0x1
	cmp r3, r6
	bge _08026872
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0x83
	lsls r4, 2
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _0802684C
	lsls r0, r3, 3
	movs r7, 0xB8
	lsls r7, 1
	adds r1, r2, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_08026872:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_802678C

	thumb_func_start sub_8026878
sub_8026878:
	ldr r0, _080268C0
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xDE
	lsls r1, 1
	add r1, r12
	ldr r0, _080268C4
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xE0
	lsls r1, 1
	add r1, r12
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xE2
	lsls r1, 1
	add r1, r12
	ldr r0, _080268C8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xE4
	lsls r1, 1
	add r1, r12
	movs r0, 0x3
	str r0, [r1]
	movs r0, 0xE6
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xE8
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_080268C0: .4byte gUnknown_203B2B8
_080268C4: .4byte gUnknown_80D4920
_080268C8: .4byte gUnknown_80D4928
	thumb_func_end sub_8026878

	thumb_func_start sub_80268CC
sub_80268CC:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	ldr r4, _0802690C
	ldr r0, [r4]
	adds r0, 0x7C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080268F8
	ldr r0, [r4]
	adds r0, 0x7C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080268F8
	ldr r0, [r4]
	str r1, [r0, 0x70]
_080268F8:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xC
	bls _08026902
	b _08026A6E
_08026902:
	lsls r0, 2
	ldr r1, _08026910
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802690C: .4byte gUnknown_203B2B8
_08026910: .4byte _08026914
	.align 2, 0
_08026914:
	.4byte _08026A68
	.4byte _08026A6E
	.4byte _08026A6E
	.4byte _08026A58
	.4byte _08026A60
	.4byte _08026948
	.4byte _0802698C
	.4byte _080269B4
	.4byte _080269F0
	.4byte _08026A00
	.4byte _08026A08
	.4byte _08026A10
	.4byte _080269F8
_08026948:
	ldr r4, _08026984
	ldr r0, [r4]
	movs r1, 0xA
	ldrsh r0, [r0, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	beq _08026976
	ldr r0, [r4]
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r1, r0
	ldr r0, _08026988
	ldr r0, [r0]
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x2
	orrs r0, r2
	strh r0, [r1]
	bl nullsub_104
_08026976:
	bl sub_808ED00
	movs r0, 0x5
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_08026984: .4byte gUnknown_203B2B8
_08026988: .4byte gUnknown_203B45C
_0802698C:
	ldr r0, _080269AC
	ldr r0, [r0]
	ldr r2, [r0, 0x18]
	ldrh r1, [r2]
	ldr r0, _080269B0
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	movs r0, 0x6
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_080269AC: .4byte gUnknown_203B2B8
_080269B0: .4byte 0x0000fffd
_080269B4:
	ldr r2, _080269E8
	ldr r0, _080269EC
	ldr r0, [r0]
	movs r3, 0xA
	ldrsh r1, [r0, r3]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	bl sub_808D33C
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	bne _080269DA
	strb r1, [r0, 0x2]
	movs r0, 0x1
	strb r0, [r4, 0x2]
	bl nullsub_104
_080269DA:
	bl sub_808ED00
	movs r0, 0x7
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_080269E8: .4byte gUnknown_203B45C
_080269EC: .4byte gUnknown_203B2B8
_080269F0:
	movs r0, 0xC
	bl sub_8026074
	b _08026A6E
_080269F8:
	movs r0, 0x16
	bl sub_8026074
	b _08026A6E
_08026A00:
	movs r0, 0xE
	bl sub_8026074
	b _08026A6E
_08026A08:
	movs r0, 0x12
	bl sub_8026074
	b _08026A6E
_08026A10:
	ldr r0, _08026A50
	bl sub_8011988
	ldr r4, _08026A54
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _08026A28
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
_08026A28:
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	bl nullsub_104
	movs r0, 0x11
	bl sub_8026074
	b _08026A6E
	.align 2, 0
_08026A50: .4byte 0x0000014d
_08026A54: .4byte gUnknown_203B2B8
_08026A58:
	movs r0, 0x3
	bl sub_8026074
	b _08026A6E
_08026A60:
	movs r0, 0x4
	bl sub_8026074
	b _08026A6E
_08026A68:
	movs r0, 0x19
	bl sub_8026074
_08026A6E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80268CC

	thumb_func_start sub_8026A78
sub_8026A78:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08026A90
	cmp r0, 0x3
	bhi _08026A90
	bl sub_802453C
	movs r0, 0x2
	bl sub_8026074
_08026A90:
	pop {r0}
	bx r0
	thumb_func_end sub_8026A78

	thumb_func_start sub_8026A94
sub_8026A94:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08026AAC
	cmp r0, 0x3
	bhi _08026AAC
	bl sub_801BF98
	movs r0, 0x2
	bl sub_8026074
_08026AAC:
	pop {r0}
	bx r0
	thumb_func_end sub_8026A94

	thumb_func_start sub_8026AB0
sub_8026AB0:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08026B08
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08026ADA
	cmp r0, 0x2
	bgt _08026ACE
	cmp r0, 0x1
	beq _08026AD2
	b _08026B08
_08026ACE:
	cmp r0, 0x3
	bne _08026B08
_08026AD2:
	movs r0, 0x2
	bl sub_8026074
	b _08026B08
_08026ADA:
	ldr r0, _08026AF0
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrb r0, [r0, 0x4]
	subs r0, 0x44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08026AF4
	movs r0, 0x1
	b _08026AF6
	.align 2, 0
_08026AF0: .4byte gUnknown_203B2B8
_08026AF4:
	movs r0, 0
_08026AF6:
	cmp r0, 0
	beq _08026B02
	movs r0, 0xD
	bl sub_8026074
	b _08026B08
_08026B02:
	movs r0, 0x8
	bl sub_8026074
_08026B08:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8026AB0

	thumb_func_start sub_8026B10
sub_8026B10:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08026B40
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08026B3A
	cmp r0, 0x2
	bgt _08026B2E
	cmp r0, 0x1
	beq _08026B32
	b _08026B40
_08026B2E:
	cmp r0, 0x3
	bne _08026B40
_08026B32:
	movs r0, 0x2
	bl sub_8026074
	b _08026B40
_08026B3A:
	movs r0, 0x8
	bl sub_8026074
_08026B40:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8026B10

	thumb_func_start sub_8026B48
sub_8026B48:
	push {lr}
	bl sub_8022860
	cmp r0, 0x1
	bls _08026B60
	cmp r0, 0x3
	bhi _08026B60
	bl sub_8022908
	movs r0, 0x2
	bl sub_8026074
_08026B60:
	pop {r0}
	bx r0
	thumb_func_end sub_8026B48

	thumb_func_start sub_8026B64
sub_8026B64:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08026C0E
	lsls r0, 2
	ldr r1, _08026B7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026B7C: .4byte _08026B80
	.align 2, 0
_08026B80:
	.4byte _08026C0E
	.4byte _08026C0E
	.4byte _08026C04
	.4byte _08026B94
	.4byte _08026BC8
_08026B94:
	bl sub_801A8AC
	ldr r4, _08026BC0
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08026BC4
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0x14
	bl sub_8026074
	b _08026C0E
	.align 2, 0
_08026BC0: .4byte gUnknown_203B2B8
_08026BC4: .4byte gUnknown_203B460
_08026BC8:
	bl sub_801A8AC
	ldr r4, _08026BFC
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08026C00
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0
	bl sub_8099690
	movs r0, 0x15
	bl sub_8026074
	b _08026C0E
	.align 2, 0
_08026BFC: .4byte gUnknown_203B2B8
_08026C00: .4byte gUnknown_203B460
_08026C04:
	bl sub_801A928
	movs r0, 0x2
	bl sub_8026074
_08026C0E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8026B64

	thumb_func_start sub_8026C14
sub_8026C14:
	push {r4-r6,lr}
	sub sp, 0x14
	movs r0, 0
	str r0, [sp, 0xC]
	bl sub_801A6E8
	ldr r4, _08026C54
	ldr r0, [r4]
	adds r0, 0xCC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08026C44
	ldr r0, [r4]
	adds r0, 0xCC
	add r1, sp, 0xC
	bl sub_8013114
	ldr r1, [sp, 0xC]
	cmp r1, 0x1
	beq _08026C44
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08026C44:
	ldr r0, [sp, 0xC]
	cmp r0, 0x4
	beq _08026CD4
	cmp r0, 0x4
	bgt _08026C58
	cmp r0, 0x1
	beq _08026CE2
	b _08026CE8
	.align 2, 0
_08026C54: .4byte gUnknown_203B2B8
_08026C58:
	cmp r0, 0xB
	bne _08026CE8
	movs r6, 0xF
	ldr r0, _08026CC8
	bl sub_8011988
	ldr r5, _08026CCC
	ldr r0, [r5]
	ldr r0, [r0, 0xC]
	bl sub_80911F8
	bl sub_80910B4
	ldr r1, [r5]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _08026C84
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
	movs r6, 0x10
_08026C84:
	add r4, sp, 0x10
	ldr r1, [r5]
	adds r1, 0x10
	adds r0, r4, 0
	bl sub_8090B64
	movs r1, 0
	str r1, [sp]
	mov r0, sp
	strb r1, [r0, 0x4]
	mov r1, sp
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08026CD0
	adds r1, r4, 0
	mov r2, sp
	bl sub_8090E14
	ldr r1, [r5]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x10
	bl sub_808D800
	bl sub_801A928
	bl nullsub_104
	adds r0, r6, 0
	bl sub_8026074
	b _08026CE8
	.align 2, 0
_08026CC8: .4byte 0x0000014d
_08026CCC: .4byte gUnknown_203B2B8
_08026CD0: .4byte gUnknown_202DEA8
_08026CD4:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x15
	bl sub_8026074
	b _08026CE8
_08026CE2:
	movs r0, 0x13
	bl sub_8026074
_08026CE8:
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8026C14

	thumb_func_start sub_8026CF0
sub_8026CF0:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08026D08
	cmp r0, 0x3
	bhi _08026D08
	bl sub_801B450
	movs r0, 0x13
	bl sub_8026074
_08026D08:
	pop {r0}
	bx r0
	thumb_func_end sub_8026CF0

	thumb_func_start sub_8026D0C
sub_8026D0C:
	push {lr}
	movs r0, 0x1
	bl sub_801EF38
	cmp r0, 0x4
	bhi _08026D66
	lsls r0, 2
	ldr r1, _08026D24
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026D24: .4byte _08026D28
	.align 2, 0
_08026D28:
	.4byte _08026D66
	.4byte _08026D66
	.4byte _08026D5C
	.4byte _08026D3C
	.4byte _08026D3C
_08026D3C:
	bl sub_801F194
	ldr r1, _08026D58
	ldr r1, [r1]
	str r0, [r1, 0x20]
	lsls r0, 3
	adds r0, r1, r0
	ldrh r0, [r0, 0x2A]
	strh r0, [r1, 0x24]
	movs r0, 0x18
	bl sub_8026074
	b _08026D66
	.align 2, 0
_08026D58: .4byte gUnknown_203B2B8
_08026D5C:
	bl sub_801F214
	movs r0, 0x2
	bl sub_8026074
_08026D66:
	pop {r0}
	bx r0
	thumb_func_end sub_8026D0C

	thumb_func_start sub_8026D6C
sub_8026D6C:
	push {lr}
	bl sub_801F890
	cmp r0, 0x1
	bls _08026D84
	cmp r0, 0x3
	bhi _08026D84
	bl sub_801F8D0
	movs r0, 0x17
	bl sub_8026074
_08026D84:
	pop {r0}
	bx r0
	thumb_func_end sub_8026D6C

	thumb_func_start sub_8026D88
sub_8026D88:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08026DA0
	ldr r0, _08026DA8
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	bl sub_8026074
_08026DA0:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08026DA8: .4byte gUnknown_203B2B8
	thumb_func_end sub_8026D88

	thumb_func_start sub_8026DAC
sub_8026DAC:
	push {r4-r6,lr}
	sub sp, 0x14
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_8008C54
	adds r0, r6, 0
	bl sub_80073B8
	add r4, sp, 0x10
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8090B64
	movs r5, 0
	str r5, [sp, 0x4]
	add r0, sp, 0x4
	strb r5, [r0, 0x4]
	adds r1, r0, 0
	movs r0, 0x1
	strb r0, [r1, 0x8]
	strb r0, [r4]
	ldr r0, _08026E00
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_8090E14
	ldr r2, _08026E04
	str r5, [sp]
	movs r0, 0x4
	movs r1, 0x3
	adds r3, r6, 0
	bl sub_8014FF0
	adds r0, r6, 0
	bl sub_80073E0
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026E00: .4byte gUnknown_202DE58
_08026E04: .4byte gUnknown_80DD6D0
	thumb_func_end sub_8026DAC

	thumb_func_start sub_8026E08
sub_8026E08:
	push {r4-r6,lr}
	sub sp, 0x40
	adds r5, r0, 0
	bl sub_8008C54
	adds r0, r5, 0
	bl sub_80073B8
	ldr r6, _08026E78
	ldr r4, _08026E7C
	ldr r0, [r4]
	ldr r1, [r0, 0x18]
	adds r1, 0x4C
	adds r0, r6, 0
	movs r2, 0xA
	bl sub_80922B4
	add r0, sp, 0x2C
	ldr r1, [r4]
	ldr r1, [r1, 0x18]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	bl sub_808D930
	ldr r1, _08026E80
	add r0, sp, 0x4
	adds r2, r6, 0
	bl sub_800D158
	add r0, sp, 0x4
	bl sub_8008ED0
	adds r1, r0, 0
	ldr r0, _08026E84
	movs r2, 0xC
	ldrsh r0, [r0, r2]
	lsls r0, 3
	subs r0, r1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0
	str r1, [sp]
	movs r1, 0x3
	add r2, sp, 0x4
	adds r3, r5, 0
	bl xxx_call_draw_string
	adds r0, r5, 0
	bl sub_80073E0
	add sp, 0x40
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026E78: .4byte gAvailablePokemonNames
_08026E7C: .4byte gUnknown_203B2B8
_08026E80: .4byte gUnknown_80DD6E0
_08026E84: .4byte gUnknown_80DD370
	thumb_func_end sub_8026E08

	thumb_func_start sub_8026E88
sub_8026E88:
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x2]
	cmp r0, 0
	bne _08026EAC
	movs r2, 0
	ldrb r0, [r1, 0x4]
	cmp r0, 0x41
	bne _08026E9C
	movs r2, 0x1
_08026E9C:
	cmp r2, 0
	beq _08026EB0
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	bne _08026EB0
_08026EAC:
	movs r0, 0
	b _08026EB2
_08026EB0:
	movs r0, 0x1
_08026EB2:
	pop {r1}
	bx r1
	thumb_func_end sub_8026E88

	thumb_func_start sub_8026EB8
sub_8026EB8:
	push {r4,lr}
	adds r4, r0, 0
	bl sub_808D3BC
	cmp r0, r4
	beq _08026EFA
	bl sub_808D3F8
	cmp r0, r4
	beq _08026EFA
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _08026EFA
	movs r1, 0
	ldrb r0, [r4, 0x4]
	cmp r0, 0x41
	bne _08026EDC
	movs r1, 0x1
_08026EDC:
	cmp r1, 0
	beq _08026EEC
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08026EFA
_08026EEC:
	adds r0, r4, 0
	bl sub_8026F04
	cmp r0, 0x3
	beq _08026EFA
	movs r0, 0x1
	b _08026EFC
_08026EFA:
	movs r0, 0
_08026EFC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026EB8

	thumb_func_start sub_8026F04
sub_8026F04:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x28
	ldrb r0, [r0]
	cmp r0, 0
	bne _08026F14
	movs r0, 0
	b _08026F32
_08026F14:
	bl sub_8090A34
	cmp r0, 0x13
	bgt _08026F20
	movs r0, 0x1
	b _08026F32
_08026F20:
	adds r0, r4, 0
	bl sub_8026F38
	lsls r0, 24
	cmp r0, 0
	bne _08026F30
	movs r0, 0x3
	b _08026F32
_08026F30:
	movs r0, 0x2
_08026F32:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8026F04

	thumb_func_start sub_8026F38
sub_8026F38:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r4, 0x28
	ldrb r0, [r4]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _08026F74
	ldrb r0, [r4]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08026F80
	ldr r0, _08026F78
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	adds r0, r5, 0
	adds r0, 0x29
	ldrb r0, [r0]
	adds r1, r0
	ldr r0, _08026F7C
	cmp r1, r0
	ble _08026F94
_08026F74:
	movs r0, 0
	b _08026F96
	.align 2, 0
_08026F78: .4byte gUnknown_203B460
_08026F7C: .4byte 0x000003e7
_08026F80:
	ldr r0, _08026F9C
	ldr r1, [r0]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	ldr r0, _08026FA0
	cmp r1, r0
	bhi _08026F74
_08026F94:
	movs r0, 0x1
_08026F96:
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08026F9C: .4byte gUnknown_203B460
_08026FA0: .4byte 0x000003e6
	thumb_func_end sub_8026F38

	thumb_func_start sub_8026FA4
sub_8026FA4:
	push {r4,lr}
	ldr r4, _08026FC0
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	bl sub_8026F04
	cmp r0, 0x1
	beq _08026FC4
	cmp r0, 0x1
	bcc _08027068
	cmp r0, 0x2
	beq _08026FF8
	b _08027068
	.align 2, 0
_08026FC0: .4byte gUnknown_203B2B8
_08026FC4:
	ldr r0, _08026FF4
	bl sub_8011988
	ldr r0, [r4]
	adds r0, 0x14
	bl sub_8091274
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0xA
	bl sub_8026074
	b _0802706E
	.align 2, 0
_08026FF4: .4byte 0x0000014d
_08026FF8:
	ldr r0, _08027024
	bl sub_8011988
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _0802702C
	ldr r0, _08027028
	ldr r1, [r0]
	ldr r2, [r4]
	ldrb r0, [r2, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	ldrb r2, [r2, 0x15]
	adds r0, r2
	b _0802703E
	.align 2, 0
_08027024: .4byte 0x0000014d
_08027028: .4byte gUnknown_203B460
_0802702C:
	ldr r0, _08027060
	ldr r1, [r0]
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
_0802703E:
	strh r0, [r1]
	ldr r1, _08027064
	ldr r0, [r1]
	movs r2, 0
	strb r2, [r0, 0x14]
	ldr r0, [r1]
	strb r2, [r0, 0x15]
	ldr r1, [r1]
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	movs r0, 0xB
	bl sub_8026074
	b _0802706E
	.align 2, 0
_08027060: .4byte gUnknown_203B460
_08027064: .4byte gUnknown_203B2B8
_08027068:
	movs r0, 0x19
	bl sub_8026074
_0802706E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8026FA4

	thumb_func_start sub_8027074
sub_8027074:
	push {r4,lr}
	movs r0, 0
	bl ResetSprites
	ldr r4, _080270A0
	movs r0, 0xF0
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0
	str r1, [r0, 0x70]
	str r1, [r0, 0x74]
	str r1, [r0, 0x78]
	movs r0, 0
	bl sub_8027184
	movs r0, 0x1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080270A0: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027074

	thumb_func_start sub_80270A4
sub_80270A4:
	push {lr}
	ldr r0, _080270BC
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x11
	bhi _08027156
	lsls r0, 2
	ldr r1, _080270C0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080270BC: .4byte gUnknown_203B2BC
_080270C0: .4byte _080270C4
	.align 2, 0
_080270C4:
	.4byte _0802710C
	.4byte _08027114
	.4byte _08027114
	.4byte _0802711A
	.4byte _08027120
	.4byte _08027126
	.4byte _08027156
	.4byte _08027156
	.4byte _0802712C
	.4byte _08027132
	.4byte _08027138
	.4byte _08027138
	.4byte _0802713E
	.4byte _08027144
	.4byte _0802714A
	.4byte _0802714A
	.4byte _08027150
	.4byte _0802715C
_0802710C:
	movs r0, 0x1
	bl sub_8027184
	b _08027160
_08027114:
	bl sub_80277FC
	b _08027160
_0802711A:
	bl sub_80278B4
	b _08027160
_08027120:
	bl sub_8027A40
	b _08027160
_08027126:
	bl sub_8027A5C
	b _08027160
_0802712C:
	bl sub_8027A78
	b _08027160
_08027132:
	bl sub_8027AE4
	b _08027160
_08027138:
	bl sub_8027B28
	b _08027160
_0802713E:
	bl sub_8027BD8
	b _08027160
_08027144:
	bl sub_8027C84
	b _08027160
_0802714A:
	bl sub_8027CA0
	b _08027160
_08027150:
	bl sub_8027D00
	b _08027160
_08027156:
	bl sub_8027D1C
	b _08027160
_0802715C:
	movs r0, 0x3
	b _08027162
_08027160:
	movs r0, 0
_08027162:
	pop {r1}
	bx r1
	thumb_func_end sub_80270A4

	thumb_func_start sub_8027168
sub_8027168:
	push {r4,lr}
	ldr r4, _08027180
	ldr r0, [r4]
	cmp r0, 0
	beq _0802717A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802717A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027180: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027168

	thumb_func_start sub_8027184
sub_8027184:
	push {lr}
	ldr r1, _08027198
	ldr r1, [r1]
	str r0, [r1]
	bl sub_802719C
	bl sub_8027274
	pop {r0}
	bx r0
	.align 2, 0
_08027198: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027184

	thumb_func_start sub_802719C
sub_802719C:
	push {r4-r7,lr}
	ldr r4, _080271C0
	ldr r0, [r4]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x3
	beq _080271C8
	cmp r0, 0xC
	beq _08027208
	movs r2, 0
	ldr r3, _080271C4
	b _08027234
	.align 2, 0
_080271C0: .4byte gUnknown_203B2BC
_080271C4: .4byte gUnknown_80DD6EC
_080271C8:
	movs r2, 0xE4
	lsls r2, 1
	adds r1, r2
	ldr r0, _08027200
	ldm r0!, {r3,r5,r6}
	stm r1!, {r3,r5,r6}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	bl CreateFriendActionMenu
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _08027204
	ldm r1!, {r5-r7}
	stm r2!, {r5-r7}
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r7, 0x8E
	lsls r7, 1
	adds r1, r7
	bl sub_8012CAC
	b _08027254
	.align 2, 0
_08027200: .4byte gUnknown_80DD74C
_08027204: .4byte gUnknown_80DD704
_08027208:
	bl sub_80276A8
	ldr r2, [r4]
	movs r0, 0xD8
	lsls r0, 1
	adds r2, r0
	ldr r1, _08027230
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0x8E
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	b _08027254
	.align 2, 0
_08027230: .4byte gUnknown_80DD71C
_08027234:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	movs r7, 0xC0
	lsls r7, 1
	adds r0, r7
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _08027234
_08027254:
	bl ResetUnusedInputStruct
	ldr r0, _08027270
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027270: .4byte gUnknown_203B2BC
	thumb_func_end sub_802719C

	thumb_func_start sub_8027274
sub_8027274:
	push {r4,lr}
	sub sp, 0x18
	ldr r1, _08027290
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x11
	bls _08027286
	b _0802744A
_08027286:
	lsls r0, 2
	ldr r1, _08027294
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027290: .4byte gUnknown_203B2BC
_08027294: .4byte _08027298
	.align 2, 0
_08027298:
	.4byte _0802744A
	.4byte _080272E0
	.4byte _080272EE
	.4byte _080272F6
	.4byte _0802731A
	.4byte _08027328
	.4byte _0802741C
	.4byte _08027438
	.4byte _080273B6
	.4byte _080273D0
	.4byte _08027334
	.4byte _08027342
	.4byte _0802734A
	.4byte _08027374
	.4byte _08027386
	.4byte _080273AC
	.4byte _08027404
	.4byte _0802744A
_080272E0:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x7
	bl sub_8023868
	b _0802744A
_080272EE:
	movs r0, 0x1
	bl sub_8023B7C
	b _0802744A
_080272F6:
	ldr r1, [r4]
	adds r1, 0x14
	movs r0, 0x3
	bl sub_8027D40
	bl sub_8023DA4
	ldr r2, [r4]
	adds r0, r2, 0
	adds r0, 0x7C
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	movs r4, 0xB6
	lsls r4, 1
	adds r3, r2, r4
	ldr r2, [r2, 0x70]
	b _08027362
_0802731A:
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	movs r1, 0x2
	bl sub_8024458
	b _0802744A
_08027328:
	ldr r0, [r4]
	movs r3, 0x8
	ldrsh r0, [r0, r3]
	bl sub_801BEEC
	b _0802744A
_08027334:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _0802744A
_08027342:
	movs r0, 0x1
	bl sub_801A8D0
	b _0802744A
_0802734A:
	bl sub_801A9E0
	ldr r0, _08027370
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x7C
	movs r4, 0x8E
	lsls r4, 1
	adds r1, r2, r4
	adds r4, 0x50
	adds r3, r2, r4
	ldr r2, [r2, 0x74]
_08027362:
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	bl sub_8012D60
	b _0802744A
	.align 2, 0
_08027370: .4byte gUnknown_203B2BC
_08027374:
	ldr r1, [r4]
	adds r1, 0x10
	add r0, sp, 0x14
	bl sub_8090B64
	add r0, sp, 0x14
	bl sub_801B3C0
	b _0802744A
_08027386:
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x28
	ldr r1, [r1, 0x18]
	adds r1, 0x2C
	bl sub_809401C
	ldr r2, [r4]
	movs r0, 0x8
	ldrsh r1, [r2, r0]
	adds r2, 0x28
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r3, 0
	bl sub_801EE10
	b _0802744A
_080273AC:
	movs r0, 0x1
	movs r1, 0
	bl sub_801F1B0
	b _0802744A
_080273B6:
	bl sub_8027794
	ldr r0, _080273C8
	ldr r1, _080273CC
	ldr r3, [r1]
	movs r1, 0x8E
	lsls r1, 1
	adds r3, r1
	b _080273E0
	.align 2, 0
_080273C8: .4byte gUnknown_80DD764
_080273CC: .4byte gUnknown_203B2BC
_080273D0:
	bl sub_8027794
	ldr r0, _080273FC
	ldr r1, _08027400
	ldr r3, [r1]
	movs r4, 0x8E
	lsls r4, 1
	adds r3, r4
_080273E0:
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	adds r1, 0xFD
	str r1, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0802744A
	.align 2, 0
_080273FC: .4byte gUnknown_80DD7FC
_08027400: .4byte gUnknown_203B2BC
_08027404:
	ldr r2, [r4]
	ldr r0, [r2, 0x20]
	adds r1, r2, 0
	adds r1, 0x28
	adds r2, 0x68
	bl sub_8093560
	ldr r0, [r4]
	adds r0, 0x68
	bl sub_801F808
	b _0802744A
_0802741C:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08027430
	ldr r3, _08027434
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0802744A
	.align 2, 0
_08027430: .4byte gUnknown_80DD8A0
_08027434: .4byte 0x00000101
_08027438:
	ldr r1, [r4]
	movs r0, 0x2
	str r0, [r1, 0x4]
	ldr r0, _08027454
	ldr r3, _08027458
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0802744A:
	add sp, 0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027454: .4byte gUnknown_80DD8D0
_08027458: .4byte 0x00000101
	thumb_func_end sub_8027274

        @ Menu that gets created when you talk to friend
	thumb_func_start CreateFriendActionMenu
CreateFriendActionMenu:
	push {r4-r7,lr}
	ldr r3, _080274E4
	ldr r4, _080274E8
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r2, [r0, r1]
	movs r1, 0x58
	muls r2, r1
	ldr r1, [r3]
	adds r5, r1, r2
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldrh r0, [r5]
	lsrs r0, 1
	movs r6, 0x1
	ands r0, r6
	cmp r0, 0
	beq _080274F4
	ldr r2, [r4]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _080274EC
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x7
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8027D9C
	lsls r0, 24
	cmp r0, 0
	bne _080274B6
	ldr r0, [r4]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	strh r6, [r0]
_080274B6:
	movs r7, 0x1
	movs r0, 0x8
	bl sub_80023E4
	lsls r0, 24
	cmp r0, 0
	beq _08027552
	ldrb r0, [r5, 0x2]
	cmp r0, 0
	bne _08027552
	ldr r3, [r4]
	movs r2, 0x8
	movs r4, 0x92
	lsls r4, 1
	adds r1, r3, r4
	ldr r0, _080274F0
	str r0, [r1]
	movs r1, 0x94
	lsls r1, 1
	adds r0, r3, r1
	str r2, [r0]
	b _08027550
	.align 2, 0
_080274E4: .4byte gUnknown_203B45C
_080274E8: .4byte gUnknown_203B2BC
_080274EC: .4byte gFriendActionStandby
_080274F0: .4byte gFriendActionMakeLeader
_080274F4:
	ldr r2, [r4]
	movs r3, 0x8E
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _08027658
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x6
	str r0, [r1]
	movs r1, 0x8
	ldrsh r0, [r2, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	bne _08027522
	ldr r0, [r4]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	strh r6, [r0]
_08027522:
	movs r7, 0x1
	ldr r2, [r4]
	movs r3, 0x92
	lsls r3, 1
	adds r1, r2, r3
	ldr r0, _0802765C
	str r0, [r1]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x9
	str r0, [r1]
	adds r0, r5, 0
	bl sub_8027DCC
	lsls r0, 24
	cmp r0, 0
	bne _08027550
	ldr r0, [r4]
	movs r1, 0xB7
	lsls r1, 1
	adds r0, r1
	strh r7, [r0]
_08027550:
	movs r7, 0x2
_08027552:
	ldr r4, _08027660
	ldr r2, [r4]
	lsls r3, r7, 3
	movs r6, 0x8E
	lsls r6, 1
	adds r0, r2, r6
	adds r0, r3
	ldr r1, _08027664
	str r1, [r0]
	movs r5, 0x90
	lsls r5, 1
	adds r2, r5
	adds r2, r3
	movs r0, 0xA
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0
	bne _08027588
	ldr r0, [r4]
	lsls r1, r7, 1
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r2
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_08027588:
	adds r7, 0x1
	ldr r2, [r4]
	lsls r3, r7, 3
	adds r0, r2, r6
	adds r0, r3
	ldr r1, _08027668
	str r1, [r0]
	adds r2, r5
	adds r2, r3
	movs r0, 0xB
	str r0, [r2]
	bl sub_8090A34
	cmp r0, 0x13
	bgt _080275AE
	ldr r0, [r4]
	ldrb r0, [r0, 0x14]
	cmp r0, 0
	bne _080275BE
_080275AE:
	ldr r0, [r4]
	lsls r1, r7, 1
	movs r3, 0xB6
	lsls r3, 1
	adds r0, r3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0]
_080275BE:
	adds r7, 0x1
	ldr r4, _08027660
	ldr r5, [r4]
	lsls r1, r7, 3
	movs r0, 0x8E
	lsls r0, 1
	adds r3, r5, r0
	adds r2, r3, r1
	ldr r0, _0802766C
	str r0, [r2]
	movs r2, 0x90
	lsls r2, 1
	adds r6, r5, r2
	adds r1, r6, r1
	movs r0, 0x4
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08027670
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0xC
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _08027674
	str r0, [r2]
	adds r1, r6, r1
	movs r0, 0x5
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r6, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r7
	bge _08027636
	adds r4, r6, 0
	movs r0, 0xB6
	lsls r0, 1
	adds r2, r5, r0
_0802761E:
	ldrh r0, [r2]
	cmp r0, 0
	bne _0802762C
	ldr r1, [r4]
	ldr r0, [r5, 0x70]
	cmp r1, r0
	beq _080276A0
_0802762C:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r7
	blt _0802761E
_08027636:
	movs r3, 0
	cmp r3, r7
	bge _080276A0
	mov r2, r12
	ldr r1, [r2]
	movs r4, 0xB6
	lsls r4, 1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, 0
	bne _08027678
	movs r2, 0x90
	lsls r2, 1
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r1, 0x70]
	b _080276A0
	.align 2, 0
_08027658: .4byte gFriendActionJoinTeam
_0802765C: .4byte gFriendActionSayFarewell
_08027660: .4byte gUnknown_203B2BC
_08027664: .4byte gFriendActionGive
_08027668: .4byte gFriendActionTake
_0802766C: .4byte gFriendActionSummary
_08027670: .4byte gFriendActionMoves
_08027674: .4byte gFriendActionCheckIQ
_08027678:
	adds r3, 0x1
	cmp r3, r7
	bge _080276A0
	mov r4, r12
	ldr r2, [r4]
	lsls r0, r3, 1
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08027678
	lsls r0, r3, 3
	movs r3, 0x90
	lsls r3, 1
	adds r1, r2, r3
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x70]
_080276A0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CreateFriendActionMenu

	thumb_func_start sub_80276A8
sub_80276A8:
	push {r4-r7,lr}
	ldr r5, _0802775C
	ldr r0, [r5]
	movs r7, 0xB6
	lsls r7, 1
	adds r0, r7
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r2, [r5]
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _08027760
	str r0, [r1]
	movs r3, 0x90
	lsls r3, 1
	adds r1, r2, r3
	movs r0, 0xA
	str r0, [r1]
	bl sub_8090A34
	cmp r0, 0
	bne _080276E4
	ldr r0, [r5]
	adds r4, r7, 0
	adds r0, r4
	movs r1, 0x1
	strh r1, [r0]
_080276E4:
	ldr r4, [r5]
	movs r2, 0x1
	movs r0, 0x92
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _08027764
	ldr r0, [r0]
	str r0, [r1]
	movs r3, 0x94
	lsls r3, 1
	adds r1, r4, r3
	movs r0, 0x4
	str r0, [r1]
	movs r6, 0x2
	movs r0, 0x96
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0
	str r0, [r1]
	movs r1, 0x98
	lsls r1, 1
	adds r0, r4, r1
	str r2, [r0]
	movs r3, 0
	mov r12, r4
	movs r4, 0x90
	lsls r4, 1
	add r4, r12
	mov r0, r12
	adds r2, r0, r7
_08027720:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08027730
	ldr r1, [r4]
	mov r7, r12
	ldr r0, [r7, 0x74]
	cmp r1, r0
	beq _0802778E
_08027730:
	adds r4, 0x8
	adds r2, 0x2
	adds r3, 0x1
	cmp r3, r6
	blt _08027720
	movs r3, 0
	cmp r3, r6
	bge _0802778E
	ldr r1, [r5]
	movs r2, 0xB6
	lsls r2, 1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, 0
	bne _08027768
	movs r3, 0x90
	lsls r3, 1
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r1, 0x74]
	b _0802778E
	.align 2, 0
_0802775C: .4byte gUnknown_203B2BC
_08027760: .4byte gFriendActionGive
_08027764: .4byte gUnknown_80D4970
_08027768:
	adds r3, 0x1
	cmp r3, r6
	bge _0802778E
	ldr r2, [r5]
	lsls r0, r3, 1
	movs r4, 0xB6
	lsls r4, 1
	adds r1, r2, r4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08027768
	lsls r0, r3, 3
	movs r7, 0x90
	lsls r7, 1
	adds r1, r2, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x74]
_0802778E:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80276A8

	thumb_func_start sub_8027794
sub_8027794:
	push {r4,lr}
	ldr r4, _080277F0
	ldr r0, [r4]
	movs r1, 0xB6
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill16
	ldr r4, [r4]
	movs r3, 0
	movs r0, 0x8E
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _080277F4
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	movs r0, 0x92
	lsls r0, 1
	adds r1, r4, r0
	ldr r0, _080277F8
	ldr r0, [r0]
	str r0, [r1]
	movs r0, 0x94
	lsls r0, 1
	adds r1, r4, r0
	movs r0, 0x3
	str r0, [r1]
	movs r1, 0x96
	lsls r1, 1
	adds r0, r4, r1
	str r3, [r0]
	adds r1, 0x4
	adds r0, r4, r1
	str r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080277F0: .4byte gUnknown_203B2BC
_080277F4: .4byte gUnknown_80D4920
_080277F8: .4byte gUnknown_80D4928
	thumb_func_end sub_8027794

	thumb_func_start sub_80277FC
sub_80277FC:
	push {r4,lr}
	movs r0, 0x1
	bl sub_8023A94
	cmp r0, 0x4
	bhi _080278AE
	lsls r0, 2
	ldr r1, _08027814
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027814: .4byte _08027818
	.align 2, 0
_08027818:
	.4byte _080278AE
	.4byte _080278AE
	.4byte _080278A4
	.4byte _0802782C
	.4byte _08027868
_0802782C:
	bl sub_8023B44
	ldr r4, _08027860
	ldr r1, [r4]
	strh r0, [r1, 0x8]
	ldr r3, _08027864
	movs r0, 0x8
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D7DC
	movs r0, 0x3
	bl sub_8027184
	b _080278AE
	.align 2, 0
_08027860: .4byte gUnknown_203B2BC
_08027864: .4byte gUnknown_203B45C
_08027868:
	bl sub_8023B44
	ldr r4, _0802789C
	ldr r1, [r4]
	strh r0, [r1, 0x8]
	ldr r3, _080278A0
	movs r0, 0x8
	ldrsh r2, [r1, r0]
	movs r0, 0x58
	muls r2, r0
	ldr r0, [r3]
	adds r0, r2
	str r0, [r1, 0x18]
	ldrb r0, [r0, 0x2]
	strb r0, [r1, 0x1C]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D7DC
	movs r0, 0x4
	bl sub_8027184
	b _080278AE
	.align 2, 0
_0802789C: .4byte gUnknown_203B2BC
_080278A0: .4byte gUnknown_203B45C
_080278A4:
	bl sub_8023C60
	movs r0, 0x11
	bl sub_8027184
_080278AE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80277FC

	thumb_func_start sub_80278B4
sub_80278B4:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_8023A94
	ldr r4, _080278F8
	ldr r0, [r4]
	adds r0, 0x7C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _080278E4
	ldr r0, [r4]
	adds r0, 0x7C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _080278E4
	ldr r0, [r4]
	str r1, [r0, 0x70]
_080278E4:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0xB
	bls _080278EE
	b _08027A36
_080278EE:
	lsls r0, 2
	ldr r1, _080278FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080278F8: .4byte gUnknown_203B2BC
_080278FC: .4byte _08027900
	.align 2, 0
_08027900:
	.4byte _08027A30
	.4byte _08027A36
	.4byte _08027A36
	.4byte _08027A20
	.4byte _08027A28
	.4byte _08027930
	.4byte _0802796C
	.4byte _0802798C
	.4byte _080279C0
	.4byte _080279D0
	.4byte _080279D8
	.4byte _080279C8
_08027930:
	ldr r4, _08027964
	ldr r0, [r4]
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	bl sub_808D750
	lsls r0, 24
	cmp r0, 0
	beq _0802795E
	ldr r0, [r4]
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	movs r0, 0x58
	muls r1, r0
	ldr r0, _08027968
	ldr r0, [r0]
	adds r1, r0
	ldrh r2, [r1]
	movs r0, 0x2
	orrs r0, r2
	strh r0, [r1]
	bl nullsub_104
_0802795E:
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_08027964: .4byte gUnknown_203B2BC
_08027968: .4byte gUnknown_203B45C
_0802796C:
	ldr r0, _08027984
	ldr r0, [r0]
	ldr r2, [r0, 0x18]
	ldrh r1, [r2]
	ldr r0, _08027988
	ands r0, r1
	strh r0, [r2]
	bl nullsub_104
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_08027984: .4byte gUnknown_203B2BC
_08027988: .4byte 0x0000fffd
_0802798C:
	ldr r2, _080279B8
	ldr r0, _080279BC
	ldr r0, [r0]
	movs r3, 0x8
	ldrsh r1, [r0, r3]
	movs r0, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r4, r0, r1
	bl sub_808D33C
	ldrb r1, [r4, 0x2]
	cmp r1, 0
	bne _080279B2
	strb r1, [r0, 0x2]
	movs r0, 0x1
	strb r0, [r4, 0x2]
	bl nullsub_104
_080279B2:
	bl sub_808ED00
	b _08027A0E
	.align 2, 0
_080279B8: .4byte gUnknown_203B45C
_080279BC: .4byte gUnknown_203B2BC
_080279C0:
	movs r0, 0x8
	bl sub_8027184
	b _08027A36
_080279C8:
	movs r0, 0xE
	bl sub_8027184
	b _08027A36
_080279D0:
	movs r0, 0xA
	bl sub_8027184
	b _08027A36
_080279D8:
	ldr r0, _08027A18
	bl sub_8011988
	ldr r4, _08027A1C
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _080279F0
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
_080279F0:
	bl sub_80910B4
	ldr r0, [r4]
	movs r1, 0
	strb r1, [r0, 0x14]
	ldr r0, [r4]
	strb r1, [r0, 0x15]
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x14
	bl sub_808D800
	bl nullsub_104
_08027A0E:
	movs r0, 0x2
	bl sub_8027184
	b _08027A36
	.align 2, 0
_08027A18: .4byte 0x0000014d
_08027A1C: .4byte gUnknown_203B2BC
_08027A20:
	movs r0, 0x4
	bl sub_8027184
	b _08027A36
_08027A28:
	movs r0, 0x5
	bl sub_8027184
	b _08027A36
_08027A30:
	movs r0, 0x2
	bl sub_8027184
_08027A36:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80278B4

	thumb_func_start sub_8027A40
sub_8027A40:
	push {lr}
	bl sub_80244E4
	cmp r0, 0x1
	bls _08027A58
	cmp r0, 0x3
	bhi _08027A58
	bl sub_802453C
	movs r0, 0x2
	bl sub_8027184
_08027A58:
	pop {r0}
	bx r0
	thumb_func_end sub_8027A40

	thumb_func_start sub_8027A5C
sub_8027A5C:
	push {lr}
	bl sub_801BF48
	cmp r0, 0x1
	bls _08027A74
	cmp r0, 0x3
	bhi _08027A74
	bl sub_801BF98
	movs r0, 0x2
	bl sub_8027184
_08027A74:
	pop {r0}
	bx r0
	thumb_func_end sub_8027A5C

	thumb_func_start sub_8027A78
sub_8027A78:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08027AD8
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08027AA2
	cmp r0, 0x2
	bgt _08027A96
	cmp r0, 0x1
	beq _08027A9A
	b _08027AD8
_08027A96:
	cmp r0, 0x3
	bne _08027AD8
_08027A9A:
	movs r0, 0x2
	bl sub_8027184
	b _08027AD8
_08027AA2:
	ldr r0, _08027AB8
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	ldrb r0, [r0, 0x4]
	subs r0, 0x44
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08027ABC
	movs r0, 0x1
	b _08027ABE
	.align 2, 0
_08027AB8: .4byte gUnknown_203B2BC
_08027ABC:
	movs r0, 0
_08027ABE:
	cmp r0, 0
	beq _08027ACA
	movs r0, 0x9
	bl sub_8027184
	b _08027AD8
_08027ACA:
	bl sub_8027EB8
	ldr r0, _08027AE0
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
_08027AD8:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08027AE0: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027A78

	thumb_func_start sub_8027AE4
sub_8027AE4:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08027B1C
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08027B0E
	cmp r0, 0x2
	bgt _08027B02
	cmp r0, 0x1
	beq _08027B06
	b _08027B1C
_08027B02:
	cmp r0, 0x3
	bne _08027B1C
_08027B06:
	movs r0, 0x2
	bl sub_8027184
	b _08027B1C
_08027B0E:
	bl sub_8027EB8
	ldr r0, _08027B24
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	bl sub_808D31C
_08027B1C:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08027B24: .4byte gUnknown_203B2BC
	thumb_func_end sub_8027AE4

	thumb_func_start sub_8027B28
sub_8027B28:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _08027BD2
	lsls r0, 2
	ldr r1, _08027B40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027B40: .4byte _08027B44
	.align 2, 0
_08027B44:
	.4byte _08027BD2
	.4byte _08027BD2
	.4byte _08027BC8
	.4byte _08027B58
	.4byte _08027B8C
_08027B58:
	bl sub_801A8AC
	ldr r4, _08027B84
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08027B88
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0xC
	bl sub_8027184
	b _08027BD2
	.align 2, 0
_08027B84: .4byte gUnknown_203B2BC
_08027B88: .4byte gUnknown_203B460
_08027B8C:
	bl sub_801A8AC
	ldr r4, _08027BC0
	ldr r2, [r4]
	str r0, [r2, 0xC]
	ldr r3, _08027BC4
	ldr r1, [r3]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	strb r0, [r2, 0x10]
	ldr r2, [r4]
	ldr r1, [r3]
	ldr r0, [r2, 0xC]
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	strb r0, [r2, 0x11]
	movs r0, 0
	bl sub_8099690
	movs r0, 0xD
	bl sub_8027184
	b _08027BD2
	.align 2, 0
_08027BC0: .4byte gUnknown_203B2BC
_08027BC4: .4byte gUnknown_203B460
_08027BC8:
	bl sub_801A928
	movs r0, 0x2
	bl sub_8027184
_08027BD2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027B28

	thumb_func_start sub_8027BD8
sub_8027BD8:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08027C18
	ldr r0, [r4]
	adds r0, 0x7C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08027C08
	ldr r0, [r4]
	adds r0, 0x7C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08027C08
	ldr r0, [r4]
	str r1, [r0, 0x74]
_08027C08:
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08027C68
	cmp r0, 0x4
	bgt _08027C1C
	cmp r0, 0x1
	beq _08027C76
	b _08027C7C
	.align 2, 0
_08027C18: .4byte gUnknown_203B2BC
_08027C1C:
	cmp r0, 0xA
	bne _08027C7C
	ldr r0, _08027C60
	bl sub_8011988
	ldr r4, _08027C64
	ldr r0, [r4]
	ldr r0, [r0, 0xC]
	bl sub_80911F8
	bl sub_80910B4
	ldr r1, [r4]
	ldrb r0, [r1, 0x14]
	cmp r0, 0
	beq _08027C44
	adds r0, r1, 0
	adds r0, 0x14
	bl sub_8091274
_08027C44:
	ldr r1, [r4]
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	adds r1, 0x10
	bl sub_808D800
	bl sub_801A928
	bl nullsub_104
	movs r0, 0x2
	bl sub_8027184
	b _08027C7C
	.align 2, 0
_08027C60: .4byte 0x0000014d
_08027C64: .4byte gUnknown_203B2BC
_08027C68:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xD
	bl sub_8027184
	b _08027C7C
_08027C76:
	movs r0, 0xB
	bl sub_8027184
_08027C7C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8027BD8

        .align 2,0
