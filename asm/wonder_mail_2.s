        .include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_802BCC4
sub_802BCC4:
	push {r4,lr}
	ldr r4, _0802BCDC
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	bl GetPokemonMailText
	adds r3, r0, 0
	ldr r1, [r4]
	movs r0, 0
	str r0, [r1, 0xC]
	str r3, [r1, 0x10]
	b _0802BD08
	.align 2, 0
_0802BCDC: .4byte gUnknown_203B2D4
_0802BCE0:
	cmp r0, 0x23
	bne _0802BD06
	ldrb r2, [r3, 0x1]
	cmp r2, 0x50
	beq _0802BCF0
	adds r1, r3, 0x2
	cmp r2, 0x70
	bne _0802BD02
_0802BCF0:
	ldr r0, [r4]
	ldr r1, [r0, 0xC]
	adds r1, 0x1
	str r1, [r0, 0xC]
	lsls r1, 2
	adds r0, 0x10
	adds r0, r1
	adds r1, r3, 0x2
	str r1, [r0]
_0802BD02:
	adds r3, r1, 0
	b _0802BD08
_0802BD06:
	adds r3, 0x1
_0802BD08:
	ldrb r0, [r3]
	cmp r0, 0
	bne _0802BCE0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802BCC4

	thumb_func_start sub_802BD14
sub_802BD14:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	bl HasNoMailinMailbox
	lsls r0, 24
	cmp r0, 0
	beq _0802BD2E
	movs r0, 0
	b _0802BDD4
_0802BD2E:
	ldr r5, _0802BDE0
	ldr r0, [r5]
	cmp r0, 0
	bne _0802BD40
	movs r0, 0xA4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0802BD40:
	ldr r0, [r5]
	str r6, [r0, 0x38]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x40
	adds r1, r0, r1
	str r1, [r0, 0x3C]
	adds r0, 0x40
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x38]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x40
	ldr r0, _0802BDE4
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r5]
	ldr r1, [r2, 0x3C]
	adds r0, r2, 0
	adds r0, 0xA0
	str r0, [r1, 0x14]
	cmp r4, 0
	beq _0802BD8E
	ldr r1, [r2, 0x38]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x48
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0802BD8E:
	ldr r0, [r5]
	ldr r0, [r0, 0x3C]
	mov r1, r8
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x40
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x4
	bl sub_802C0B8
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013848
	ldr r0, [r5]
	ldr r1, _0802BDE8
	ldrh r1, [r1]
	strh r1, [r0, 0x1C]
	adds r0, 0x4
	bl sub_8013984
	bl sub_802BF30
	bl CreateMailMenu
	movs r0, 0x1
_0802BDD4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802BDE0: .4byte gUnknown_203B2D8
_0802BDE4: .4byte gUnknown_80DFC74
_0802BDE8: .4byte gUnknown_203B2DC
	thumb_func_end sub_802BD14

	thumb_func_start sub_802BDEC
sub_802BDEC:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802BE08
	ldr r0, _0802BE04
	ldr r0, [r0]
	adds r0, 0x4
	bl sub_8013660
	movs r0, 0
	b _0802BE6E
	.align 2, 0
_0802BE04: .4byte gUnknown_203B2D8
_0802BE08:
	ldr r0, _0802BE20
	ldr r0, [r0]
	adds r0, 0x4
	bl GetKeyPress
	cmp r0, 0x2
	beq _0802BE2A
	cmp r0, 0x2
	bgt _0802BE24
	cmp r0, 0x1
	beq _0802BE34
	b _0802BE48
	.align 2, 0
_0802BE20: .4byte gUnknown_203B2D8
_0802BE24:
	cmp r0, 0x4
	beq _0802BE3E
	b _0802BE48
_0802BE2A:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802BE6E
_0802BE34:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802BE6E
_0802BE3E:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0802BE6E
_0802BE48:
	ldr r0, _0802BE60
	ldr r0, [r0]
	adds r0, 0x4
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802BE64
	movs r0, 0
	b _0802BE6E
	.align 2, 0
_0802BE60: .4byte gUnknown_203B2D8
_0802BE64:
	bl sub_802BF30
	bl CreateMailMenu
	movs r0, 0x1
_0802BE6E:
	pop {r1}
	bx r1
	thumb_func_end sub_802BDEC

	thumb_func_start sub_802BE74
sub_802BE74:
	ldr r0, _0802BE90
	ldr r1, [r0]
	movs r0, 0x22
	ldrsh r2, [r1, r0]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r3, 0x1C
	ldrsh r2, [r1, r3]
	adds r0, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_0802BE90: .4byte gUnknown_203B2D8
	thumb_func_end sub_802BE74

	thumb_func_start sub_802BE94
sub_802BE94:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802BED8
	ldr r0, [r5]
	adds r0, 0x40
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_802C0B8
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x26]
	adds r0, 0x4
	bl sub_8013984
	bl sub_802BF30
	bl CreateMailMenu
	cmp r4, 0
	beq _0802BED2
	ldr r0, [r5]
	adds r0, 0x4
	bl AddMenuCursorSprite
_0802BED2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BED8: .4byte gUnknown_203B2D8
	thumb_func_end sub_802BE94

	thumb_func_start sub_802BEDC
sub_802BEDC:
	push {r4,r5,lr}
	ldr r4, _0802BF24
	ldr r2, [r4]
	cmp r2, 0
	beq _0802BF1C
	ldr r1, _0802BF28
	ldrh r0, [r2, 0x1C]
	strh r0, [r1]
	ldr r0, [r2, 0x38]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x40
	ldr r0, _0802BF2C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x40
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802BF1C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BF24: .4byte gUnknown_203B2D8
_0802BF28: .4byte gUnknown_203B2DC
_0802BF2C: .4byte gUnknown_80DFC5C
	thumb_func_end sub_802BEDC

	thumb_func_start sub_802BF30
sub_802BF30:
	push {r4,lr}
	ldr r4, _0802BF9C
	ldr r0, [r4]
	adds r0, 0xA0
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA1
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, 0xA2
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA3
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1E
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x38]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x4E
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x38]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x50
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x40
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BF9C: .4byte gUnknown_203B2D8
	thumb_func_end sub_802BF30

	thumb_func_start CreateMailMenu
CreateMailMenu:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0xDC
	ldr r4, _0802C060
	ldr r0, [r4]
	ldr r0, [r0, 0x38]
	bl sub_8008C54
	ldr r0, [r4]
	ldr r0, [r0, 0x38]
	bl sub_80073B8
	ldr r1, [r4]
	movs r2, 0x22
	ldrsh r0, [r1, r2]
	lsls r0, 3
	adds r0, 0xA
	ldr r2, _0802C064
	ldr r3, [r1, 0x38]
	movs r1, 0
	str r1, [sp]
	bl xxx_call_draw_string
	movs r6, 0
	ldr r0, [r4]
	movs r3, 0x1E
	ldrsh r0, [r0, r3]
	cmp r6, r0
	bge _0802C09A
	adds r7, r4, 0
	ldr r0, _0802C068
	mov r9, r0
	add r1, sp, 0x5C
	mov r8, r1
_0802BFE8:
	ldr r1, [r7]
	movs r3, 0x22
	ldrsh r2, [r1, r3]
	movs r3, 0x20
	ldrsh r0, [r1, r3]
	muls r0, r2
	adds r0, r6
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8095FE8
	adds r5, r0, 0
	ldr r0, [r7]
	ldr r1, [r0, 0x38]
	str r1, [sp, 0x4]
	adds r0, 0x4
	adds r1, r6, 0
	bl sub_8013800
	str r0, [sp, 0x4C]
	ldrb r0, [r5]
	cmp r0, 0x1
	bne _0802C06C
	ldr r0, [r7]
	adds r0, 0x4
	adds r1, r6, 0
	bl sub_8013800
	adds r4, r0, 0
	ldr r0, [r7]
	ldr r3, [r0, 0x38]
	movs r0, 0xA
	adds r1, r4, 0
	movs r2, 0x6
	bl sub_803B6B0
	bl GetPlayerPokemonStruct
	adds r1, r0, 0
	mov r0, r9
	bl PrintPokeNameToBuffer
	ldrb r0, [r5, 0x5]
	bl GetPokemonMailHeadline
	adds r1, r0, 0
	mov r0, r8
	mov r2, r9
	bl ExpandPlaceholdersBuffer
	ldr r0, [r7]
	ldr r3, [r0, 0x38]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x15
	adds r1, r4, 0
	mov r2, r8
	bl xxx_call_draw_string
	b _0802C08E
	.align 2, 0
_0802C060: .4byte gUnknown_203B2D8
_0802C064: .4byte gMailboxText
_0802C068: .4byte gAvailablePokemonNames
_0802C06C:
	adds r0, r5, 0
	add r1, sp, 0x4
	bl sub_803B35C
	adds r0, r5, 0
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	beq _0802C088
	mov r1, sp
	adds r1, 0x47
	movs r0, 0x2
	strb r0, [r1]
_0802C088:
	add r0, sp, 0x4
	bl sub_803B6D4
_0802C08E:
	adds r6, 0x1
	ldr r0, [r7]
	movs r1, 0x1E
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0802BFE8
_0802C09A:
	ldr r0, _0802C0B4
	ldr r0, [r0]
	ldr r0, [r0, 0x38]
	bl sub_80073E0
	add sp, 0xDC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C0B4: .4byte gUnknown_203B2D8
	thumb_func_end CreateMailMenu

	thumb_func_start sub_802C0B8
sub_802C0B8:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802C0BE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl CheckMailSlot
	lsls r0, 24
	cmp r0, 0
	bne _0802C0D6
	ldr r0, _0802C0E4
	ldr r0, [r0]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0802C0D6:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0802C0BE
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802C0E4: .4byte gUnknown_203B2D8
	thumb_func_end sub_802C0B8

	thumb_func_start HasNoMailinMailbox
HasNoMailinMailbox:
	push {r4,lr}
	movs r4, 0
_0802C0EC:
	lsls r0, r4, 24
	lsrs r0, 24
	bl CheckMailSlot
	lsls r0, 24
	cmp r0, 0
	bne _0802C0FE
	movs r0, 0
	b _0802C106
_0802C0FE:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0802C0EC
	movs r0, 0x1
_0802C106:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end HasNoMailinMailbox

	thumb_func_start sub_802C10C
sub_802C10C:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	bl sub_802C4A4
	lsls r0, 24
	cmp r0, 0
	beq _0802C126
	movs r0, 0
	b _0802C1CC
_0802C126:
	ldr r5, _0802C1D8
	ldr r0, [r5]
	cmp r0, 0
	bne _0802C138
	movs r0, 0xA8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0802C138:
	ldr r0, [r5]
	str r6, [r0, 0x3C]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x44
	adds r1, r0, r1
	str r1, [r0, 0x40]
	adds r0, 0x44
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x3C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x44
	ldr r0, _0802C1DC
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r5]
	ldr r1, [r2, 0x40]
	adds r0, r2, 0
	adds r0, 0xA4
	str r0, [r1, 0x14]
	cmp r4, 0
	beq _0802C186
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0802C186:
	ldr r0, [r5]
	ldr r0, [r0, 0x40]
	mov r1, r8
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x8
	bl sub_802C474
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013848
	ldr r0, [r5]
	ldr r1, _0802C1E0
	ldrh r1, [r1]
	strh r1, [r0, 0x20]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C328
	bl sub_802C39C
	movs r0, 0x1
_0802C1CC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802C1D8: .4byte gUnknown_203B2E0
_0802C1DC: .4byte gUnknown_80DFCB4
_0802C1E0: .4byte gUnknown_203B2E4
	thumb_func_end sub_802C10C

	thumb_func_start sub_802C1E4
sub_802C1E4:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802C200
	ldr r0, _0802C1FC
	ldr r0, [r0]
	adds r0, 0x8
	bl sub_8013660
	movs r0, 0
	b _0802C266
	.align 2, 0
_0802C1FC: .4byte gUnknown_203B2E0
_0802C200:
	ldr r0, _0802C218
	ldr r0, [r0]
	adds r0, 0x8
	bl GetKeyPress
	cmp r0, 0x2
	beq _0802C222
	cmp r0, 0x2
	bgt _0802C21C
	cmp r0, 0x1
	beq _0802C22C
	b _0802C240
	.align 2, 0
_0802C218: .4byte gUnknown_203B2E0
_0802C21C:
	cmp r0, 0x4
	beq _0802C236
	b _0802C240
_0802C222:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802C266
_0802C22C:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802C266
_0802C236:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0802C266
_0802C240:
	ldr r0, _0802C258
	ldr r0, [r0]
	adds r0, 0x8
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802C25C
	movs r0, 0
	b _0802C266
	.align 2, 0
_0802C258: .4byte gUnknown_203B2E0
_0802C25C:
	bl sub_802C328
	bl sub_802C39C
	movs r0, 0x1
_0802C266:
	pop {r1}
	bx r1
	thumb_func_end sub_802C1E4

	thumb_func_start sub_802C26C
sub_802C26C:
	ldr r0, _0802C288
	ldr r1, [r0]
	movs r0, 0x26
	ldrsh r2, [r1, r0]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r3, 0x20
	ldrsh r2, [r1, r3]
	adds r0, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_0802C288: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C26C

	thumb_func_start sub_802C28C
sub_802C28C:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802C2D0
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_802C474
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x2A]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C328
	bl sub_802C39C
	cmp r4, 0
	beq _0802C2CA
	ldr r0, [r5]
	adds r0, 0x8
	bl AddMenuCursorSprite
_0802C2CA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C2D0: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C28C

	thumb_func_start sub_802C2D4
sub_802C2D4:
	push {r4,r5,lr}
	ldr r4, _0802C31C
	ldr r2, [r4]
	cmp r2, 0
	beq _0802C314
	ldr r1, _0802C320
	ldrh r0, [r2, 0x20]
	strh r0, [r1]
	ldr r0, [r2, 0x3C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x44
	ldr r0, _0802C324
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802C314:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C31C: .4byte gUnknown_203B2E0
_0802C320: .4byte gUnknown_203B2E4
_0802C324: .4byte gUnknown_80DFC9C
	thumb_func_end sub_802C2D4

	thumb_func_start sub_802C328
sub_802C328:
	push {r4,lr}
	ldr r4, _0802C398
	ldr r0, [r4]
	ldrh r1, [r0, 0x28]
	adds r0, 0xA4
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x26]
	adds r0, 0xA5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA6
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA7
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x3C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x52
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x54
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C398: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C328

	thumb_func_start sub_802C39C
sub_802C39C:
	push {r4-r7,lr}
	sub sp, 0x60
	ldr r7, _0802C3F8
	ldr r0, [r7]
	ldr r0, [r0, 0x3C]
	bl sub_8008C54
	ldr r0, [r7]
	ldr r0, [r0, 0x3C]
	bl sub_80073B8
	ldr r0, [r7]
	movs r1, 0x26
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0802C3FC
	ldr r3, [r0, 0x3C]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0xA6
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x3C]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r6, 0
	b _0802C452
	.align 2, 0
_0802C3F8: .4byte gUnknown_203B2E0
_0802C3FC: .4byte gBulletinBoardText
_0802C400:
	ldr r1, [r7]
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	adds r0, r6
	adds r1, r0
	ldrb r5, [r1]
	adds r0, r5, 0
	bl sub_8096574
	adds r4, r0, 0
	ldr r0, [r7]
	ldr r1, [r0, 0x3C]
	str r1, [sp, 0x8]
	adds r0, 0x8
	adds r1, r6, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	adds r0, r4, 0
	add r1, sp, 0x8
	bl sub_803B35C
	adds r0, r5, 0
	bl sub_8096574
	bl sub_80968B0
	lsls r0, 24
	cmp r0, 0
	beq _0802C44A
	mov r1, sp
	adds r1, 0x4B
	movs r0, 0x2
	strb r0, [r1]
_0802C44A:
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r6, 0x1
_0802C452:
	ldr r0, [r7]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _0802C400
	ldr r0, _0802C470
	ldr r0, [r0]
	ldr r0, [r0, 0x3C]
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C470: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C39C

	thumb_func_start sub_802C474
sub_802C474:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802C47A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_809658C
	lsls r0, 24
	cmp r0, 0
	bne _0802C492
	ldr r0, _0802C4A0
	ldr r0, [r0]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0802C492:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C47A
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802C4A0: .4byte gUnknown_203B2E0
	thumb_func_end sub_802C474

	thumb_func_start sub_802C4A4
sub_802C4A4:
	push {r4,lr}
	movs r4, 0
_0802C4A8:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_809658C
	lsls r0, 24
	cmp r0, 0
	bne _0802C4BA
	movs r0, 0
	b _0802C4C2
_0802C4BA:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C4A8
	movs r0, 0x1
_0802C4C2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802C4A4

	thumb_func_start sub_802C4C8
sub_802C4C8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	mov r8, r2
	bl HasNoAcceptedJobs
	lsls r0, 24
	cmp r0, 0
	beq _0802C4E2
	movs r0, 0
	b _0802C580
_0802C4E2:
	ldr r5, _0802C58C
	movs r0, 0xA8
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x3C]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x44
	adds r1, r0, r1
	str r1, [r0, 0x40]
	adds r0, 0x44
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x3C]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x44
	ldr r0, _0802C590
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r2, [r5]
	ldr r1, [r2, 0x40]
	adds r0, r2, 0
	adds r0, 0xA4
	str r0, [r1, 0x14]
	cmp r4, 0
	beq _0802C53A
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldr r0, [r4]
	str r0, [r1]
_0802C53A:
	ldr r0, [r5]
	ldr r0, [r0, 0x40]
	mov r1, r8
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r4, [r5]
	adds r4, 0x8
	bl sub_802C80C
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	adds r3, r6, 0
	bl sub_8013848
	ldr r0, [r5]
	ldr r1, _0802C594
	ldrh r1, [r1]
	strh r1, [r0, 0x20]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C6DC
	bl sub_802C750
	movs r0, 0x1
_0802C580:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802C58C: .4byte gUnknown_203B2E8
_0802C590: .4byte gUnknown_80DFCFC
_0802C594: .4byte gUnknown_203B2EC
	thumb_func_end sub_802C4C8

	thumb_func_start sub_802C598
sub_802C598:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802C5B4
	ldr r0, _0802C5B0
	ldr r0, [r0]
	adds r0, 0x8
	bl sub_8013660
	movs r0, 0
	b _0802C61A
	.align 2, 0
_0802C5B0: .4byte gUnknown_203B2E8
_0802C5B4:
	ldr r0, _0802C5CC
	ldr r0, [r0]
	adds r0, 0x8
	bl GetKeyPress
	cmp r0, 0x2
	beq _0802C5D6
	cmp r0, 0x2
	bgt _0802C5D0
	cmp r0, 0x1
	beq _0802C5E0
	b _0802C5F4
	.align 2, 0
_0802C5CC: .4byte gUnknown_203B2E8
_0802C5D0:
	cmp r0, 0x4
	beq _0802C5EA
	b _0802C5F4
_0802C5D6:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802C61A
_0802C5E0:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0802C61A
_0802C5EA:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0802C61A
_0802C5F4:
	ldr r0, _0802C60C
	ldr r0, [r0]
	adds r0, 0x8
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802C610
	movs r0, 0
	b _0802C61A
	.align 2, 0
_0802C60C: .4byte gUnknown_203B2E8
_0802C610:
	bl sub_802C6DC
	bl sub_802C750
	movs r0, 0x1
_0802C61A:
	pop {r1}
	bx r1
	thumb_func_end sub_802C598

	thumb_func_start sub_802C620
sub_802C620:
	ldr r0, _0802C63C
	ldr r1, [r0]
	movs r0, 0x26
	ldrsh r2, [r1, r0]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	movs r3, 0x20
	ldrsh r2, [r1, r3]
	adds r0, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.align 2, 0
_0802C63C: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C620

	thumb_func_start sub_802C640
sub_802C640:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802C684
	ldr r0, [r5]
	adds r0, 0x44
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	bl sub_802C80C
	adds r1, r0, 0
	ldr r0, [r5]
	strh r1, [r0, 0x2A]
	adds r0, 0x8
	bl sub_8013984
	bl sub_802C6DC
	bl sub_802C750
	cmp r4, 0
	beq _0802C67E
	ldr r0, [r5]
	adds r0, 0x8
	bl AddMenuCursorSprite
_0802C67E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C684: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C640

	thumb_func_start sub_802C688
sub_802C688:
	push {r4,r5,lr}
	ldr r4, _0802C6D0
	ldr r2, [r4]
	cmp r2, 0
	beq _0802C6C8
	ldr r1, _0802C6D4
	ldrh r0, [r2, 0x20]
	strh r0, [r1]
	ldr r0, [r2, 0x3C]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x44
	ldr r0, _0802C6D8
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802C6C8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C6D0: .4byte gUnknown_203B2E8
_0802C6D4: .4byte gUnknown_203B2EC
_0802C6D8: .4byte gUnknown_80DFCE4
	thumb_func_end sub_802C688

	thumb_func_start sub_802C6DC
sub_802C6DC:
	push {r4,lr}
	ldr r4, _0802C74C
	ldr r0, [r4]
	ldrh r1, [r0, 0x28]
	adds r0, 0xA4
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	ldrh r1, [r0, 0x26]
	adds r0, 0xA5
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA6
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xA7
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
	adds r0, 0x2
	lsls r0, 16
	ldr r2, [r4]
	ldr r3, [r2, 0x3C]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x52
	asrs r3, r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r1, [r2, 0x3C]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r2, r0
	adds r3, 0x2
	adds r2, 0x54
	strh r3, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x44
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C74C: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C6DC

	thumb_func_start sub_802C750
sub_802C750:
	push {r4-r6,lr}
	sub sp, 0x60
	ldr r6, _0802C7AC
	ldr r0, [r6]
	ldr r0, [r0, 0x3C]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x3C]
	bl sub_80073B8
	ldr r0, [r6]
	movs r1, 0x26
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0802C7B0
	ldr r3, [r0, 0x3C]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xA6
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x3C]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r5, 0
	b _0802C7EC
	.align 2, 0
_0802C7AC: .4byte gUnknown_203B2E8
_0802C7B0: .4byte gUnknown_80DFD14
_0802C7B4:
	ldr r1, [r6]
	movs r3, 0x26
	ldrsh r2, [r1, r3]
	movs r3, 0x24
	ldrsh r0, [r1, r3]
	muls r0, r2
	adds r0, r5
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8096AB4
	adds r4, r0, 0
	ldr r0, [r6]
	ldr r1, [r0, 0x3C]
	str r1, [sp, 0x8]
	adds r0, 0x8
	adds r1, r5, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	adds r0, r4, 0
	add r1, sp, 0x8
	bl sub_803B35C
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r5, 0x1
_0802C7EC:
	ldr r0, [r6]
	movs r1, 0x22
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0802C7B4
	ldr r0, _0802C808
	ldr r0, [r0]
	ldr r0, [r0, 0x3C]
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802C808: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C750

	thumb_func_start sub_802C80C
sub_802C80C:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802C812:
	lsls r0, r4, 24
	lsrs r0, 24
	bl CheckJobSlot
	lsls r0, 24
	cmp r0, 0
	bne _0802C82A
	ldr r0, _0802C838
	ldr r0, [r0]
	adds r0, r5
	strb r4, [r0]
	adds r5, 0x1
_0802C82A:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C812
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802C838: .4byte gUnknown_203B2E8
	thumb_func_end sub_802C80C

	thumb_func_start HasNoAcceptedJobs
HasNoAcceptedJobs:
	push {r4,lr}
	movs r4, 0
_0802C840:
	lsls r0, r4, 24
	lsrs r0, 24
	bl CheckJobSlot
	lsls r0, 24
	cmp r0, 0
	bne _0802C852
	movs r0, 0
	b _0802C85A
_0802C852:
	adds r4, 0x1
	cmp r4, 0x7
	ble _0802C840
	movs r0, 0x1
_0802C85A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end HasNoAcceptedJobs

	thumb_func_start sub_802C860
sub_802C860:
	push {r4-r6,lr}
	adds r6, r0, 0
	bl HasNoAcceptedJobs
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0802C890
	ldr r4, _0802C88C
	movs r0, 0xFE
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0, 0x68]
	str r6, [r0]
	movs r0, 0
	bl sub_802C910
	movs r0, 0x1
	b _0802C892
	.align 2, 0
_0802C88C: .4byte gUnknown_203B2F0
_0802C890:
	movs r0, 0
_0802C892:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_802C860

	thumb_func_start sub_802C898
sub_802C898:
	push {lr}
	ldr r0, _0802C8B0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	cmp r0, 0x5
	bhi _0802C8E8
	lsls r0, 2
	ldr r1, _0802C8B4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C8B0: .4byte gUnknown_203B2F0
_0802C8B4: .4byte _0802C8B8
	.align 2, 0
_0802C8B8:
	.4byte _0802C8D0
	.4byte _0802C8D0
	.4byte _0802C8D6
	.4byte _0802C8DC
	.4byte _0802C8E2
	.4byte _0802C8E8
_0802C8D0:
	bl sub_802CC00
	b _0802C8EC
_0802C8D6:
	bl sub_802CC70
	b _0802C8EC
_0802C8DC:
	bl sub_802CD38
	b _0802C8EC
_0802C8E2:
	bl sub_802CDB8
	b _0802C8EC
_0802C8E8:
	movs r0, 0x3
	b _0802C8EE
_0802C8EC:
	movs r0, 0
_0802C8EE:
	pop {r1}
	bx r1
	thumb_func_end sub_802C898

	thumb_func_start sub_802C8F4
sub_802C8F4:
	push {r4,lr}
	ldr r4, _0802C90C
	ldr r0, [r4]
	cmp r0, 0
	beq _0802C906
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0802C906:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C90C: .4byte gUnknown_203B2F0
	thumb_func_end sub_802C8F4

	thumb_func_start sub_802C910
sub_802C910:
	push {lr}
	ldr r1, _0802C924
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_802C928
	bl sub_802C9D8
	pop {r0}
	bx r0
	.align 2, 0
_0802C924: .4byte gUnknown_203B2F0
	thumb_func_end sub_802C910

	thumb_func_start sub_802C928
sub_802C928:
	push {r4-r7,lr}
	ldr r4, _0802C94C
	ldr r0, [r4]
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	cmp r0, 0x2
	beq _0802C954
	cmp r0, 0x3
	beq _0802C980
	movs r2, 0
	ldr r3, _0802C950
	b _0802C998
	.align 2, 0
_0802C94C: .4byte gUnknown_203B2F0
_0802C950: .4byte gUnknown_80DFD28
_0802C954:
	bl sub_802CAA4
	ldr r2, [r4]
	movs r0, 0xE6
	lsls r0, 1
	adds r2, r0
	ldr r1, _0802C97C
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	movs r6, 0x86
	lsls r6, 1
	adds r1, r6
	bl sub_8012CAC
	b _0802C9B8
	.align 2, 0
_0802C97C: .4byte gUnknown_80DFD40
_0802C980:
	movs r7, 0xF2
	lsls r7, 1
	adds r1, r7
	ldr r0, _0802C994
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0802C9B8
	.align 2, 0
_0802C994: .4byte gUnknown_80DFD58
_0802C998:
	ldr r0, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 3
	adds r0, r1
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	adds r2, 0x1
	cmp r2, 0x3
	ble _0802C998
_0802C9B8:
	bl ResetUnusedInputStruct
	ldr r0, _0802C9D4
	ldr r0, [r0]
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C9D4: .4byte gUnknown_203B2F0
	thumb_func_end sub_802C928

	thumb_func_start sub_802C9D8
sub_802C9D8:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _0802C9F4
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x5
	bhi _0802CA9C
	lsls r0, 2
	ldr r1, _0802C9F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C9F4: .4byte gUnknown_203B2F0
_0802C9F8: .4byte _0802C9FC
	.align 2, 0
_0802C9FC:
	.4byte _0802CA14
	.4byte _0802CA20
	.4byte _0802CA28
	.4byte _0802CA48
	.4byte _0802CA80
	.4byte _0802CA9C
_0802CA14:
	movs r0, 0
	movs r1, 0
	movs r2, 0x4
	bl sub_802C4C8
	b _0802CA9C
_0802CA20:
	movs r0, 0x1
	bl sub_802C640
	b _0802CA9C
_0802CA28:
	bl sub_802C750
	ldr r0, _0802CA44
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x6C
	movs r3, 0x86
	lsls r3, 1
	adds r1, r2, r3
	ldr r2, [r2, 0x68]
	str r2, [sp]
	movs r2, 0x2
	b _0802CA6E
	.align 2, 0
_0802CA44: .4byte gUnknown_203B2F0
_0802CA48:
	bl sub_802CBAC
	bl sub_802C750
	ldr r4, _0802CA7C
	ldr r0, [r4]
	adds r0, 0x6C
	movs r1, 0
	bl sub_8012EA4
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xBC
	movs r2, 0xA6
	lsls r2, 1
	adds r1, r2
	movs r2, 0x6
	str r2, [sp]
	movs r2, 0x3
_0802CA6E:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0802CA9C
	.align 2, 0
_0802CA7C: .4byte gUnknown_203B2F0
_0802CA80:
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	ldr r1, [r4]
	adds r1, 0x10
	bl sub_803B35C
	ldr r0, [r4]
	movs r1, 0x3
	str r1, [r0, 0x10]
	adds r0, 0x10
	bl sub_802DE84
_0802CA9C:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802C9D8

	thumb_func_start sub_802CAA4
sub_802CAA4:
	push {r4-r7,lr}
	movs r7, 0
	ldr r5, _0802CAC8
	ldr r0, [r5]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	adds r4, r0, 0
	ldr r2, [r5]
	ldr r0, [r2]
	cmp r0, 0
	bne _0802CB26
	ldrb r0, [r4]
	cmp r0, 0x5
	beq _0802CACC
	cmp r0, 0x6
	beq _0802CB10
	b _0802CB26
	.align 2, 0
_0802CAC8: .4byte gUnknown_203B2F0
_0802CACC:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CAFC
	str r0, [r1]
	adds r0, r4, 0
	bl sub_809693C
	lsls r0, 24
	cmp r0, 0
	bne _0802CAEE
	ldrb r0, [r4, 0x4]
	bl sub_80A2824
	lsls r0, 24
	cmp r0, 0
	bne _0802CB00
_0802CAEE:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	b _0802CB0A
	.align 2, 0
_0802CAFC: .4byte gUnknown_80DFD70
_0802CB00:
	ldr r0, [r5]
	movs r1, 0x88
	lsls r1, 1
	adds r0, r1
	movs r1, 0x2
_0802CB0A:
	str r1, [r0]
	adds r7, 0x1
	b _0802CB26
_0802CB10:
	movs r0, 0x86
	lsls r0, 1
	adds r1, r2, r0
	ldr r0, _0802CB9C
	str r0, [r1]
	movs r0, 0x88
	lsls r0, 1
	adds r1, r2, r0
	movs r0, 0x3
	str r0, [r1]
	movs r7, 0x1
_0802CB26:
	ldr r4, _0802CBA0
	ldr r6, [r4]
	lsls r1, r7, 3
	movs r0, 0x86
	lsls r0, 1
	adds r3, r6, r0
	adds r2, r3, r1
	ldr r0, _0802CBA4
	ldr r0, [r0]
	str r0, [r2]
	movs r0, 0x88
	lsls r0, 1
	adds r5, r6, r0
	adds r1, r5, r1
	movs r0, 0x4
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r2, r3, r1
	ldr r0, _0802CBA8
	ldr r0, [r0]
	str r0, [r2]
	adds r1, r5, r1
	movs r0, 0x7
	str r0, [r1]
	adds r7, 0x1
	lsls r1, r7, 3
	adds r3, r1
	movs r0, 0
	str r0, [r3]
	adds r1, r5, r1
	movs r0, 0x1
	str r0, [r1]
	movs r3, 0
	mov r12, r4
	cmp r3, r7
	bge _0802CB8C
	adds r4, r6, 0
	adds r1, r5, 0
	movs r5, 0x1
	negs r5, r5
_0802CB78:
	ldr r2, [r1]
	cmp r2, r5
	beq _0802CB84
	ldr r0, [r4, 0x68]
	cmp r2, r0
	beq _0802CB94
_0802CB84:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r7
	blt _0802CB78
_0802CB8C:
	mov r0, r12
	ldr r1, [r0]
	movs r0, 0x7
	str r0, [r1, 0x68]
_0802CB94:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CB9C: .4byte gUnknown_80DFD7C
_0802CBA0: .4byte gUnknown_203B2F0
_0802CBA4: .4byte gUnknown_80D494C
_0802CBA8: .4byte gUnknown_80D4970
	thumb_func_end sub_802CAA4

	thumb_func_start sub_802CBAC
sub_802CBAC:
	ldr r0, _0802CBF4
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	movs r1, 0xA6
	lsls r1, 1
	add r1, r12
	ldr r0, _0802CBF8
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xA8
	lsls r1, 1
	add r1, r12
	movs r0, 0x5
	str r0, [r1]
	movs r2, 0x1
	movs r1, 0xAA
	lsls r1, 1
	add r1, r12
	ldr r0, _0802CBFC
	ldr r0, [r0]
	str r0, [r1]
	movs r1, 0xAC
	lsls r1, 1
	add r1, r12
	movs r0, 0x6
	str r0, [r1]
	movs r0, 0xAE
	lsls r0, 1
	add r0, r12
	str r3, [r0]
	movs r0, 0xB0
	lsls r0, 1
	add r0, r12
	str r2, [r0]
	bx lr
	.align 2, 0
_0802CBF4: .4byte gUnknown_203B2F0
_0802CBF8: .4byte gUnknown_80D4920
_0802CBFC: .4byte gUnknown_80D4928
	thumb_func_end sub_802CBAC

	thumb_func_start sub_802CC00
sub_802CC00:
	push {lr}
	movs r0, 0x1
	bl sub_802C598
	cmp r0, 0x4
	bhi _0802CC6A
	lsls r0, 2
	ldr r1, _0802CC18
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CC18: .4byte _0802CC1C
	.align 2, 0
_0802CC1C:
	.4byte _0802CC6A
	.4byte _0802CC6A
	.4byte _0802CC60
	.4byte _0802CC30
	.4byte _0802CC48
_0802CC30:
	bl sub_802C620
	ldr r1, _0802CC44
	ldr r1, [r1]
	strb r0, [r1, 0xC]
	movs r0, 0x2
	bl sub_802C910
	b _0802CC6A
	.align 2, 0
_0802CC44: .4byte gUnknown_203B2F0
_0802CC48:
	bl sub_802C620
	ldr r1, _0802CC5C
	ldr r1, [r1]
	strb r0, [r1, 0xC]
	movs r0, 0x4
	bl sub_802C910
	b _0802CC6A
	.align 2, 0
_0802CC5C: .4byte gUnknown_203B2F0
_0802CC60:
	bl sub_802C688
	movs r0, 0x5
	bl sub_802C910
_0802CC6A:
	pop {r0}
	bx r0
	thumb_func_end sub_802CC00

	thumb_func_start sub_802CC70
sub_802CC70:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802CCB4
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802CCA0
	ldr r0, [r4]
	adds r0, 0x6C
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0802CCA0
	ldr r0, [r4]
	str r1, [r0, 0x68]
_0802CCA0:
	ldr r0, [sp]
	subs r0, 0x1
	cmp r0, 0x6
	bhi _0802CD2E
	lsls r0, 2
	ldr r1, _0802CCB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CCB4: .4byte gUnknown_203B2F0
_0802CCB8: .4byte _0802CCBC
	.align 2, 0
_0802CCBC:
	.4byte _0802CD28
	.4byte _0802CCD8
	.4byte _0802CCF4
	.4byte _0802CD18
	.4byte _0802CD2E
	.4byte _0802CD2E
	.4byte _0802CD20
_0802CCD8:
	ldr r0, _0802CCEC
	bl PlaySound
	ldr r0, _0802CCF0
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	movs r1, 0x6
	b _0802CD06
	.align 2, 0
_0802CCEC: .4byte 0x00000133
_0802CCF0: .4byte gUnknown_203B2F0
_0802CCF4:
	ldr r0, _0802CD10
	bl PlaySound
	ldr r0, _0802CD14
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bl sub_8096AB4
	movs r1, 0x5
_0802CD06:
	strb r1, [r0]
	movs r0, 0x1
	bl sub_802C910
	b _0802CD2E
	.align 2, 0
_0802CD10: .4byte 0x00000133
_0802CD14: .4byte gUnknown_203B2F0
_0802CD18:
	movs r0, 0x3
	bl sub_802C910
	b _0802CD2E
_0802CD20:
	movs r0, 0x4
	bl sub_802C910
	b _0802CD2E
_0802CD28:
	movs r0, 0x1
	bl sub_802C910
_0802CD2E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802CC70

	thumb_func_start sub_802CD38
sub_802CD38:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_802C598
	ldr r4, _0802CD78
	ldr r0, [r4]
	adds r0, 0x6C
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xBC
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0802CD66
	ldr r0, [r4]
	adds r0, 0xBC
	mov r1, sp
	bl sub_8013114
_0802CD66:
	ldr r0, [sp]
	cmp r0, 0x5
	beq _0802CD88
	cmp r0, 0x5
	bgt _0802CD7C
	cmp r0, 0x1
	beq _0802CD80
	b _0802CDB0
	.align 2, 0
_0802CD78: .4byte gUnknown_203B2F0
_0802CD7C:
	cmp r0, 0x6
	bne _0802CDB0
_0802CD80:
	movs r0, 0x1
	bl sub_802C910
	b _0802CDB0
_0802CD88:
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	bl sub_8096C3C
	bl sub_8096C80
	bl HasNoAcceptedJobs
	lsls r0, 24
	cmp r0, 0
	beq _0802CDAA
	bl sub_802C688
	movs r0, 0x5
	bl sub_802C910
	b _0802CDB0
_0802CDAA:
	movs r0, 0x1
	bl sub_802C910
_0802CDB0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_802CD38

	thumb_func_start sub_802CDB8
sub_802CDB8:
	push {lr}
	bl sub_802DEE0
	cmp r0, 0x1
	bls _0802CDD0
	cmp r0, 0x3
	bhi _0802CDD0
	bl sub_802DF24
	movs r0, 0x1
	bl sub_802C910
_0802CDD0:
	pop {r0}
	bx r0
	thumb_func_end sub_802CDB8

	thumb_func_start sub_802CDD4
sub_802CDD4:
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r4, _0802CE54
	ldr r0, [r4]
	cmp r0, 0
	bne _0802CDEA
	movs r0, 0xA0
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
_0802CDEA:
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
	ldr r0, _0802CE58
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldr r1, [r4]
	ldr r0, [r1, 0x38]
	adds r1, 0x9C
	str r1, [r0, 0x14]
	movs r1, 0x4
	bl sub_8012D34
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x3C
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x5
	movs r2, 0x4
	adds r3, r5, 0
	bl sub_8013848
	bl sub_802CF5C
	bl sub_802CFD0
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802CE54: .4byte gUnknown_203B2F4
_0802CE58: .4byte gUnknown_80DFDA4
	thumb_func_end sub_802CDD4

	thumb_func_start sub_802CE5C
sub_802CE5C:
	push {r4,lr}
	lsls r0, 24
	cmp r0, 0
	bne _0802CE74
	ldr r0, _0802CE70
	ldr r0, [r0]
	bl sub_8013660
	movs r0, 0
	b _0802CEB4
	.align 2, 0
_0802CE70: .4byte gUnknown_203B2F4
_0802CE74:
	ldr r4, _0802CE90
	ldr r0, [r4]
	bl GetKeyPress
	cmp r0, 0x1
	beq _0802CE94
	cmp r0, 0x2
	bne _0802CE98
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0802CEB4
	.align 2, 0
_0802CE90: .4byte gUnknown_203B2F4
_0802CE94:
	movs r0, 0x3
	b _0802CEB4
_0802CE98:
	ldr r0, [r4]
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0802CEAA
	movs r0, 0
	b _0802CEB4
_0802CEAA:
	bl sub_802CF5C
	bl sub_802CFD0
	movs r0, 0x1
_0802CEB4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_802CE5C

	thumb_func_start sub_802CEBC
sub_802CEBC:
	ldr r0, _0802CED4
	ldr r1, [r0]
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	movs r3, 0x1C
	ldrsh r0, [r1, r3]
	muls r0, r2
	ldrb r1, [r1, 0x18]
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.align 2, 0
_0802CED4: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CEBC

	thumb_func_start sub_802CED8
sub_802CED8:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0802CF10
	ldr r0, [r5]
	adds r0, 0x3C
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	bl sub_8013984
	bl sub_802CF5C
	bl sub_802CFD0
	cmp r4, 0
	beq _0802CF0A
	ldr r0, [r5]
	bl AddMenuCursorSprite
_0802CF0A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CF10: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CED8

	thumb_func_start sub_802CF14
sub_802CF14:
	push {r4,r5,lr}
	ldr r4, _0802CF54
	ldr r2, [r4]
	cmp r2, 0
	beq _0802CF4E
	ldr r0, [r2, 0x34]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x3C
	ldr r0, _0802CF58
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
_0802CF4E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CF54: .4byte gUnknown_203B2F4
_0802CF58: .4byte gUnknown_80DFD8C
	thumb_func_end sub_802CF14

	thumb_func_start sub_802CF5C
sub_802CF5C:
	push {r4,lr}
	ldr r4, _0802CFCC
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
	movs r1, 0xC
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0x9F
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	movs r1, 0x18
	bl sub_8009614
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
_0802CFCC: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CF5C

	thumb_func_start sub_802CFD0
sub_802CFD0:
	push {r4-r6,lr}
	sub sp, 0x60
	ldr r6, _0802D02C
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x34]
	bl sub_80073B8
	ldr r0, [r6]
	movs r1, 0x1E
	ldrsh r4, [r0, r1]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0802D030
	ldr r3, [r0, 0x34]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0x9E
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	movs r0, 0x1E
	ldrsh r2, [r1, r0]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x34]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x2
	bl sub_8012BC4
	movs r5, 0
	b _0802D076
	.align 2, 0
_0802D02C: .4byte gUnknown_203B2F4
_0802D030: .4byte gUnknown_80DFDBC
_0802D034:
	ldr r0, [r6]
	movs r2, 0x1E
	ldrsh r1, [r0, r2]
	movs r2, 0x1C
	ldrsh r0, [r0, r2]
	muls r0, r1
	adds r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl sub_803B344
	adds r4, r0, 0
	ldr r0, [r6]
	ldr r1, [r0, 0x34]
	str r1, [sp, 0x8]
	adds r1, r5, 0
	bl sub_8013800
	str r0, [sp, 0x50]
	adds r0, r4, 0
	add r1, sp, 0x8
	bl sub_803B35C
	mov r1, sp
	adds r1, 0x4B
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, [r4, 0x14]
	str r0, [sp, 0x54]
	add r0, sp, 0x8
	bl sub_803B6D4
	adds r5, 0x1
_0802D076:
	ldr r0, [r6]
	movs r1, 0x1A
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0802D034
	ldr r0, _0802D094
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bl sub_80073E0
	add sp, 0x60
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802D094: .4byte gUnknown_203B2F4
	thumb_func_end sub_802CFD0

        .align 2,0
