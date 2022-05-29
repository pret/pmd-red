        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

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
	bl sprintf_2
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

	thumb_func_start CountEmptyMailSlots
CountEmptyMailSlots:
	push {r4,r5,lr}
	movs r5, 0
	movs r4, 0
_0802C0BE:
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsMailSlotEmpty
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
	thumb_func_end CountEmptyMailSlots

	thumb_func_start HasNoMailinMailbox
HasNoMailinMailbox:
	push {r4,lr}
	movs r4, 0
_0802C0EC:
	lsls r0, r4, 24
	lsrs r0, 24
	bl IsMailSlotEmpty
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

        .align 2,0
