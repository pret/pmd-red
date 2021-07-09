	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_801B60C
sub_801B60C:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, 24
	lsrs r7, r2, 24
	ldr r6, _0801B650
	movs r0, 0xAA
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r6]
	adds r2, r0, 0
	adds r2, 0xC8
	movs r1, 0
	str r1, [r2]
	str r5, [r0]
	strb r4, [r0, 0x12]
	ldr r0, [r6]
	ldrb r0, [r0, 0x12]
	bl sub_8090A60
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0801B654
	ldr r0, [r6]
	strb r7, [r0, 0x11]
	ldr r0, [r6]
	strb r7, [r0, 0xC]
	b _0801B65E
	.align 2, 0
_0801B650: .4byte gUnknown_203B234
_0801B654:
	ldr r0, [r6]
	strb r1, [r0, 0x11]
	ldr r1, [r6]
	movs r0, 0x1
	strb r0, [r1, 0xC]
_0801B65E:
	ldr r5, _0801B6A0
	ldr r0, [r5]
	movs r1, 0
	movs r2, 0x1
	strb r2, [r0, 0x10]
	ldr r0, [r5]
	str r1, [r0, 0x14]
	strb r1, [r0, 0x18]
	ldr r0, [r5]
	strb r2, [r0, 0x1C]
	ldr r4, _0801B6A4
	bl sub_808D33C
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x6
	bl sub_808D9AC
	ldr r0, _0801B6A8
	ldr r2, [r5]
	adds r1, r2, 0
	adds r1, 0x10
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0
	bl sub_801B748
	movs r0, 0x1
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B6A0: .4byte gUnknown_203B234
_0801B6A4: .4byte gAvailablePokemonNames
_0801B6A8: .4byte gUnknown_202DE58
	thumb_func_end sub_801B60C

	thumb_func_start sub_801B6AC
sub_801B6AC:
	push {lr}
	ldr r0, _0801B6C4
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	subs r0, 0x6
	cmp r0, 0xA
	bhi _0801B720
	lsls r0, 2
	ldr r1, _0801B6C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B6C4: .4byte gUnknown_203B234
_0801B6C8: .4byte _0801B6CC
	.align 2, 0
_0801B6CC:
	.4byte _0801B6FC
	.4byte _0801B702
	.4byte _0801B708
	.4byte _0801B708
	.4byte _0801B70E
	.4byte _0801B714
	.4byte _0801B71A
	.4byte _0801B720
	.4byte _0801B720
	.4byte _0801B720
	.4byte _0801B6F8
_0801B6F8:
	movs r0, 0x3
	b _0801B726
_0801B6FC:
	bl sub_801BC64
	b _0801B724
_0801B702:
	bl sub_801BC94
	b _0801B724
_0801B708:
	bl sub_801BCCC
	b _0801B724
_0801B70E:
	bl sub_801BD80
	b _0801B724
_0801B714:
	bl sub_801BEAC
	b _0801B724
_0801B71A:
	bl sub_801BE30
	b _0801B724
_0801B720:
	bl sub_801BEC8
_0801B724:
	movs r0, 0
_0801B726:
	pop {r1}
	bx r1
	thumb_func_end sub_801B6AC

	thumb_func_start sub_801B72C
sub_801B72C:
	push {r4,lr}
	ldr r4, _0801B744
	ldr r0, [r4]
	cmp r0, 0
	beq _0801B73E
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801B73E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801B744: .4byte gUnknown_203B234
	thumb_func_end sub_801B72C

	thumb_func_start sub_801B748
sub_801B748:
	push {lr}
	ldr r1, _0801B75C
	ldr r1, [r1]
	str r0, [r1, 0x4]
	bl sub_801B760
	bl sub_801B874
	pop {r0}
	bx r0
	.align 2, 0
_0801B75C: .4byte gUnknown_203B234
	thumb_func_end sub_801B748

	thumb_func_start sub_801B760
sub_801B760:
	push {r4-r7,lr}
	ldr r0, _0801B77C
	ldr r1, [r0]
	ldr r1, [r1, 0x4]
	subs r1, 0x1
	adds r4, r0, 0
	cmp r1, 0xE
	bls _0801B772
	b _0801B86A
_0801B772:
	lsls r0, r1, 2
	ldr r1, _0801B780
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B77C: .4byte gUnknown_203B234
_0801B780: .4byte _0801B784
	.align 2, 0
_0801B784:
	.4byte _0801B7C0
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B86A
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B800
	.4byte _0801B7C0
	.4byte _0801B840
	.4byte _0801B7C0
	.4byte _0801B7C0
	.4byte _0801B7C0
_0801B7C0:
	ldr r4, _0801B7F8
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	mov r12, r4
	ldr r4, _0801B7FC
	movs r3, 0
	movs r2, 0x3
_0801B7D2:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xF4
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801B7D2
	bl ResetUnusedInputStruct
	ldr r0, _0801B7F8
	ldr r0, [r0]
	b _0801B82E
	.align 2, 0
_0801B7F8: .4byte gUnknown_203B234
_0801B7FC: .4byte gUnknown_80DBA58
_0801B800:
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	bl sub_801BB5C
	ldr r2, [r4]
	movs r0, 0x92
	lsls r0, 1
	adds r2, r0
	ldr r1, _0801B83C
	ldm r1!, {r3,r5,r6}
	stm r2!, {r3,r5,r6}
	ldm r1!, {r3,r5,r7}
	stm r2!, {r3,r5,r7}
	ldr r1, [r4]
	adds r0, r1, r0
	adds r1, 0xCC
	bl sub_8012CAC
	bl ResetUnusedInputStruct
	ldr r0, [r4]
_0801B82E:
	adds r0, 0xF4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	b _0801B86A
	.align 2, 0
_0801B83C: .4byte gUnknown_80DBA70
_0801B840:
	ldr r0, [r4]
	adds r0, 0xF4
	bl sub_8006518
	ldr r1, [r4]
	movs r6, 0x86
	lsls r6, 1
	adds r1, r6
	ldr r0, _0801B870
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0xF4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
_0801B86A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B870: .4byte gUnknown_80DBA88
	thumb_func_end sub_801B760

	thumb_func_start sub_801B874
sub_801B874:
	push {r4,lr}
	sub sp, 0x14
	ldr r1, _0801B890
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r4, r1, 0
	cmp r0, 0x10
	bls _0801B886
	b _0801BB0E
_0801B886:
	lsls r0, 2
	ldr r1, _0801B894
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801B890: .4byte gUnknown_203B234
_0801B894: .4byte _0801B898
	.align 2, 0
_0801B898:
	.4byte _0801B8DC
	.4byte _0801B9BC
	.4byte _0801B9D8
	.4byte _0801B9E0
	.4byte _0801B9F0
	.4byte _0801B9F8
	.4byte _0801BA08
	.4byte _0801BA34
	.4byte _0801BA60
	.4byte _0801BA6E
	.4byte _0801BA76
	.4byte _0801BA94
	.4byte _0801BA9E
	.4byte _0801BAD0
	.4byte _0801BAE0
	.4byte _0801BAFC
	.4byte _0801BB0E
_0801B8DC:
	ldr r1, [r4]
	ldrb r0, [r1, 0x12]
	cmp r0, 0xEA
	bne _0801B8FE
	movs r0, 0x10
	str r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x47
	movs r2, 0x1
	bl sub_8001784
	cmp r0, 0
	bne _0801B914
	movs r0, 0
	movs r1, 0x47
	movs r2, 0x1
	b _0801B92A
_0801B8FE:
	cmp r0, 0xEB
	bne _0801B938
	movs r0, 0x10
	str r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x47
	movs r2, 0
	bl sub_8001784
	cmp r0, 0
	beq _0801B924
_0801B914:
	movs r0, 0xFA
	lsls r0, 2
	bl AddToTeamMoney
	movs r0, 0x4
	bl sub_801B748
	b _0801BB0E
_0801B924:
	movs r0, 0
	movs r1, 0x47
	movs r2, 0
_0801B92A:
	movs r3, 0x1
	bl sub_800199C
	movs r0, 0x3
	bl sub_801B748
	b _0801BB0E
_0801B938:
	bl sub_8090A34
	cmp r0, 0x13
	ble _0801B986
	ldr r0, [r4]
	ldrb r0, [r0, 0x12]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	beq _0801B968
	ldr r0, _0801B970
	ldr r1, [r0]
	ldr r2, [r4]
	ldrb r0, [r2, 0x12]
	lsls r0, 1
	adds r1, 0x50
	adds r3, r1, r0
	ldrh r1, [r3]
	ldrb r0, [r2, 0xC]
	adds r1, r0
	ldr r0, _0801B974
	cmp r1, r0
	ble _0801B978
_0801B968:
	ldr r1, [r4]
	movs r0, 0x6
	b _0801B99C
	.align 2, 0
_0801B970: .4byte gUnknown_203B460
_0801B974: .4byte 0x000003e7
_0801B978:
	strh r1, [r3]
	movs r0, 0xCB
	bl PlaySound
	ldr r1, [r4]
	movs r0, 0x5
	b _0801B99C
_0801B986:
	ldr r0, [r4]
	adds r0, 0x10
	bl AddItemToInventory
	bl sub_80910B4
	movs r0, 0xCB
	bl PlaySound
	ldr r1, [r4]
	movs r0, 0x10
_0801B99C:
	str r0, [r1, 0x8]
	ldr r0, _0801B9B0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x1
	bne _0801B9B4
	movs r0, 0x2
	bl sub_801B748
	b _0801BB0E
	.align 2, 0
_0801B9B0: .4byte gUnknown_203B234
_0801B9B4:
	movs r0, 0x1
	bl sub_801B748
	b _0801BB0E
_0801B9BC:
	movs r0, 0
	bl sub_808D544
	cmp r0, 0x1
	bgt _0801B9D0
	ldr r0, _0801B9CC
	b _0801BAE8
	.align 2, 0
_0801B9CC: .4byte gUnknown_80DBAA0
_0801B9D0:
	ldr r0, _0801B9D4
	b _0801BAE8
	.align 2, 0
_0801B9D4: .4byte gUnknown_80DBAD0
_0801B9D8:
	ldr r0, _0801B9DC
	b _0801BAE8
	.align 2, 0
_0801B9DC: .4byte gUnknown_80DBB08
_0801B9E0:
	movs r0, 0xD4
	bl PlaySound
	ldr r0, _0801B9EC
	b _0801BAE8
	.align 2, 0
_0801B9EC: .4byte gUnknown_80DBB38
_0801B9F0:
	ldr r0, _0801B9F4
	b _0801BAE8
	.align 2, 0
_0801B9F4: .4byte gUnknown_80DBB9C
_0801B9F8:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BA04
	b _0801BAE8
	.align 2, 0
_0801BA04: .4byte gUnknown_80DBC28
_0801BA08:
	bl sub_801BB20
	ldr r0, _0801BA2C
	ldr r1, _0801BA30
	ldr r3, [r1]
	adds r3, 0xCC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	str r2, [sp, 0x10]
	movs r1, 0
	movs r2, 0x4
	bl sub_8014248
	b _0801BB0E
	.align 2, 0
_0801BA2C: .4byte gUnknown_80DBC60
_0801BA30: .4byte gUnknown_203B234
_0801BA34:
	bl sub_801BC24
	ldr r0, _0801BA58
	ldr r1, _0801BA5C
	ldr r3, [r1]
	adds r3, 0xCC
	movs r2, 0
	str r2, [sp]
	movs r1, 0x4
	str r1, [sp, 0x4]
	str r2, [sp, 0x8]
	str r2, [sp, 0xC]
	str r2, [sp, 0x10]
	movs r1, 0
	movs r2, 0x3
	bl sub_8014248
	b _0801BB0E
	.align 2, 0
_0801BA58: .4byte gUnknown_80DBC98
_0801BA5C: .4byte gUnknown_203B234
_0801BA60:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	movs r3, 0xA
	bl sub_801A5D8
	b _0801BB0E
_0801BA6E:
	movs r0, 0x1
	bl sub_801A8D0
	b _0801BB0E
_0801BA76:
	bl sub_801A9E0
	ldr r0, _0801BA90
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x28
	adds r1, r2, 0
	adds r1, 0xCC
	adds r2, 0xC8
	ldr r2, [r2]
	str r2, [sp]
	movs r2, 0x2
	b _0801BAC0
	.align 2, 0
_0801BA90: .4byte gUnknown_203B234
_0801BA94:
	ldr r0, [r4]
	adds r0, 0x20
	bl sub_801B3C0
	b _0801BB0E
_0801BA9E:
	bl sub_801A9E0
	ldr r4, _0801BACC
	ldr r0, [r4]
	adds r0, 0x28
	movs r1, 0
	bl sub_8012EA4
	bl sub_801BC24
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x78
	adds r1, 0xCC
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
_0801BAC0:
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0801BB0E
	.align 2, 0
_0801BACC: .4byte gUnknown_203B234
_0801BAD0:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BADC
	b _0801BAE8
	.align 2, 0
_0801BADC: .4byte gUnknown_80DBCC4
_0801BAE0:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BAF4
_0801BAE8:
	ldr r3, _0801BAF8
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _0801BB0E
	.align 2, 0
_0801BAF4: .4byte gUnknown_80DBCE8
_0801BAF8: .4byte 0x00000101
_0801BAFC:
	ldr r1, [r4]
	movs r0, 0x10
	str r0, [r1, 0x8]
	ldr r0, _0801BB18
	ldr r3, _0801BB1C
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_0801BB0E:
	add sp, 0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801BB18: .4byte gUnknown_80DBD24
_0801BB1C: .4byte 0x00000101
	thumb_func_end sub_801B874

	thumb_func_start sub_801BB20
sub_801BB20:
	ldr r0, _0801BB50
	ldr r3, [r0]
	movs r2, 0
	adds r1, r3, 0
	adds r1, 0xCC
	ldr r0, _0801BB54
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x4
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0801BB58
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x5
	str r0, [r1]
	adds r0, r3, 0
	adds r0, 0xDC
	str r2, [r0]
	adds r1, 0x8
	movs r0, 0x1
	negs r0, r0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801BB50: .4byte gUnknown_203B234
_0801BB54: .4byte gKangaskhanTrashToolboxItem
_0801BB58: .4byte gKangaskhanTrashReceivedItem
	thumb_func_end sub_801BB20

	thumb_func_start sub_801BB5C
sub_801BB5C:
	push {r4-r7,lr}
	ldr r4, _0801BBEC
	ldr r2, [r4]
	adds r1, r2, 0
	adds r1, 0xCC
	ldr r0, _0801BBF0
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x6
	str r0, [r1]
	ldr r0, [r2, 0x24]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _0801BB86
	ldr r0, [r4]
	adds r0, 0xD0
	movs r1, 0x1
	negs r1, r1
	str r1, [r0]
_0801BB86:
	ldr r0, [r4]
	mov r12, r0
	movs r3, 0x1
	movs r2, 0x8
	mov r1, r12
	adds r1, 0xD4
	ldr r0, _0801BBF4
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x7
	str r0, [r1]
	adds r1, 0x4
	ldr r0, _0801BBF8
	ldr r0, [r0]
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE0
	str r2, [r0]
	movs r5, 0x3
	adds r1, 0x8
	movs r0, 0
	str r0, [r1]
	mov r0, r12
	adds r0, 0xE8
	str r3, [r0]
	movs r3, 0
	adds r6, r4, 0
	movs r7, 0x1
	negs r7, r7
	mov r4, r12
	adds r4, 0xC8
	subs r1, 0x14
_0801BBC6:
	ldr r2, [r1]
	cmp r2, r7
	beq _0801BBD2
	ldr r0, [r4]
	cmp r2, r0
	beq _0801BC1C
_0801BBD2:
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, r5
	blt _0801BBC6
	movs r3, 0
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0xD0
	ldr r1, [r0]
	b _0801BC0E
	.align 2, 0
_0801BBEC: .4byte gUnknown_203B234
_0801BBF0: .4byte gKangaskhanStorage
_0801BBF4: .4byte gKangaskhanTrash
_0801BBF8: .4byte gUnknown_80D4970
_0801BBFC:
	adds r3, 0x1
	cmp r3, r5
	bge _0801BC1C
	ldr r2, [r6]
	lsls r0, r3, 3
	adds r1, r2, 0
	adds r1, 0xD0
	adds r1, r0
	ldr r1, [r1]
_0801BC0E:
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0801BBFC
	adds r0, r2, 0
	adds r0, 0xC8
	str r1, [r0]
_0801BC1C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_801BB5C

	thumb_func_start sub_801BC24
sub_801BC24:
	ldr r0, _0801BC58
	ldr r0, [r0]
	mov r12, r0
	movs r3, 0
	mov r1, r12
	adds r1, 0xCC
	ldr r0, _0801BC5C
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x2
	str r0, [r1]
	movs r2, 0x1
	adds r1, 0x4
	ldr r0, _0801BC60
	ldr r0, [r0]
	str r0, [r1]
	adds r1, 0x4
	movs r0, 0x3
	str r0, [r1]
	mov r0, r12
	adds r0, 0xDC
	str r3, [r0]
	adds r0, 0x4
	str r2, [r0]
	bx lr
	.align 2, 0
_0801BC58: .4byte gUnknown_203B234
_0801BC5C: .4byte gUnknown_80D4920
_0801BC60: .4byte gUnknown_80D4928
	thumb_func_end sub_801BC24

	thumb_func_start sub_801BC64
sub_801BC64:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BC8C
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801BC7E
	cmp r0, 0x5
	beq _0801BC86
	b _0801BC8C
_0801BC7E:
	movs r0, 0x8
	bl sub_801B748
	b _0801BC8C
_0801BC86:
	movs r0, 0x7
	bl sub_801B748
_0801BC8C:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801BC64

	thumb_func_start sub_801BC94
sub_801BC94:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BCC6
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801BCB8
	cmp r0, 0x2
	bgt _0801BCB2
	cmp r0, 0x1
	beq _0801BCC0
	b _0801BCC6
_0801BCB2:
	cmp r0, 0x3
	beq _0801BCC0
	b _0801BCC6
_0801BCB8:
	movs r0, 0xD
	bl sub_801B748
	b _0801BCC6
_0801BCC0:
	movs r0, 0x6
	bl sub_801B748
_0801BCC6:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_801BC94

	thumb_func_start sub_801BCCC
sub_801BCCC:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x4
	bhi _0801BD7A
	lsls r0, 2
	ldr r1, _0801BCE4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801BCE4: .4byte _0801BCE8
	.align 2, 0
_0801BCE8:
	.4byte _0801BD7A
	.4byte _0801BD7A
	.4byte _0801BD70
	.4byte _0801BCFC
	.4byte _0801BD34
_0801BCFC:
	bl sub_801A8AC
	ldr r1, _0801BD28
	ldr r2, [r1]
	str r0, [r2, 0x24]
	ldr r1, _0801BD2C
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
	ldr r0, _0801BD30
	adds r1, r2, 0
	adds r1, 0x20
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0xA
	bl sub_801B748
	b _0801BD7A
	.align 2, 0
_0801BD28: .4byte gUnknown_203B234
_0801BD2C: .4byte gUnknown_203B460
_0801BD30: .4byte gUnknown_202DEA8
_0801BD34:
	bl sub_801A8AC
	ldr r1, _0801BD64
	ldr r2, [r1]
	str r0, [r2, 0x24]
	ldr r1, _0801BD68
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
	ldr r0, _0801BD6C
	adds r1, r2, 0
	adds r1, 0x20
	adds r2, 0x14
	bl sub_8090E14
	movs r0, 0
	bl sub_8099690
	movs r0, 0xB
	bl sub_801B748
	b _0801BD7A
	.align 2, 0
_0801BD64: .4byte gUnknown_203B234
_0801BD68: .4byte gUnknown_203B460
_0801BD6C: .4byte gUnknown_202DEA8
_0801BD70:
	bl sub_801A928
	movs r0, 0x6
	bl sub_801B748
_0801BD7A:
	pop {r0}
	bx r0
	thumb_func_end sub_801BCCC

	thumb_func_start sub_801BD80
sub_801BD80:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0801BDC4
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801BDB2
	ldr r0, [r4]
	adds r0, 0x28
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801BDB2
	ldr r0, [r4]
	adds r0, 0xC8
	str r1, [r0]
_0801BDB2:
	ldr r0, [sp]
	cmp r0, 0x6
	beq _0801BDD2
	cmp r0, 0x6
	bgt _0801BDC8
	cmp r0, 0x1
	beq _0801BE22
	b _0801BE28
	.align 2, 0
_0801BDC4: .4byte gUnknown_203B234
_0801BDC8:
	cmp r0, 0x7
	beq _0801BE0C
	cmp r0, 0x8
	beq _0801BE14
	b _0801BE28
_0801BDD2:
	ldr r4, _0801BE08
	ldr r0, [r4]
	adds r0, 0x20
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	ldr r0, [r4]
	adds r0, 0x10
	bl AddItemToInventory
	bl sub_80910B4
	movs r0, 0xCB
	bl PlaySound
	movs r0, 0
	bl sub_8099690
	bl sub_801A928
	movs r0, 0xE
	bl sub_801B748
	b _0801BE28
	.align 2, 0
_0801BE08: .4byte gUnknown_203B234
_0801BE0C:
	movs r0, 0xC
	bl sub_801B748
	b _0801BE28
_0801BE14:
	movs r0, 0
	bl sub_8099690
	movs r0, 0xB
	bl sub_801B748
	b _0801BE28
_0801BE22:
	movs r0, 0x9
	bl sub_801B748
_0801BE28:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BD80

	thumb_func_start sub_801BE30
sub_801BE30:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _0801BE70
	ldr r0, [r4]
	adds r0, 0x28
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0x78
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801BE5E
	ldr r0, [r4]
	adds r0, 0x78
	mov r1, sp
	bl sub_8013114
_0801BE5E:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801BE80
	cmp r0, 0x2
	bgt _0801BE74
	cmp r0, 0x1
	beq _0801BE78
	b _0801BEA4
	.align 2, 0
_0801BE70: .4byte gUnknown_203B234
_0801BE74:
	cmp r0, 0x3
	bne _0801BEA4
_0801BE78:
	movs r0, 0x9
	bl sub_801B748
	b _0801BEA4
_0801BE80:
	ldr r0, [r4]
	ldr r0, [r0, 0x24]
	bl sub_80911F8
	ldr r0, [r4]
	adds r0, 0x10
	bl AddItemToInventory
	bl sub_80910B4
	movs r0, 0xCB
	bl PlaySound
	bl sub_801A928
	movs r0, 0xF
	bl sub_801B748
_0801BEA4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801BE30

	thumb_func_start sub_801BEAC
sub_801BEAC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _0801BEC4
	cmp r0, 0x3
	bhi _0801BEC4
	bl sub_801B450
	movs r0, 0x9
	bl sub_801B748
_0801BEC4:
	pop {r0}
	bx r0
	thumb_func_end sub_801BEAC

	thumb_func_start sub_801BEC8
sub_801BEC8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801BEE0
	ldr r0, _0801BEE8
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl sub_801B748
_0801BEE0:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_0801BEE8: .4byte gUnknown_203B234
	thumb_func_end sub_801BEC8

	thumb_func_start sub_801BEEC
sub_801BEEC:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r5, r0, 16
	adds r0, r5, 0
	bl sub_801C5F0
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0
	bne _0801BF40
	ldr r4, _0801BF38
	movs r0, 0x92
	lsls r0, 1
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r4]
	str r6, [r0, 0x30]
	strh r5, [r0, 0x4]
	ldr r3, _0801BF3C
	movs r1, 0x58
	adds r2, r5, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0, 0x8]
	adds r0, 0xC
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	ldr r1, [r4]
	str r0, [r1, 0x2C]
	movs r0, 0
	bl sub_801BFB4
	movs r0, 0x1
	b _0801BF42
	.align 2, 0
_0801BF38: .4byte gUnknown_203B238
_0801BF3C: .4byte gRecruitedPokemonRef
_0801BF40:
	movs r0, 0
_0801BF42:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801BEEC

	thumb_func_start sub_801BF48
sub_801BF48:
	push {lr}
	ldr r0, _0801BF60
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x4
	bhi _0801BF90
	lsls r0, 2
	ldr r1, _0801BF64
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801BF60: .4byte gUnknown_203B238
_0801BF64: .4byte _0801BF68
	.align 2, 0
_0801BF68:
	.4byte _0801BF80
	.4byte _0801BF80
	.4byte _0801BF86
	.4byte _0801BF8C
	.4byte _0801BF7C
_0801BF7C:
	movs r0, 0x3
	b _0801BF92
_0801BF80:
	bl sub_801C118
	b _0801BF90
_0801BF86:
	bl sub_801C1A0
	b _0801BF90
_0801BF8C:
	bl sub_801C228
_0801BF90:
	movs r0, 0
_0801BF92:
	pop {r1}
	bx r1
	thumb_func_end sub_801BF48

	thumb_func_start sub_801BF98
sub_801BF98:
	push {r4,lr}
	ldr r4, _0801BFB0
	ldr r0, [r4]
	cmp r0, 0
	beq _0801BFAA
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801BFAA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801BFB0: .4byte gUnknown_203B238
	thumb_func_end sub_801BF98

	thumb_func_start sub_801BFB4
sub_801BFB4:
	push {lr}
	ldr r1, _0801BFC8
	ldr r1, [r1]
	str r0, [r1]
	bl sub_801BFCC
	bl sub_801C03C
	pop {r0}
	bx r0
	.align 2, 0
_0801BFC8: .4byte gUnknown_203B238
	thumb_func_end sub_801BFB4

	thumb_func_start sub_801BFCC
sub_801BFCC:
	push {r4-r7,lr}
	ldr r4, _0801BFF0
	ldr r0, [r4]
	adds r0, 0xC4
	bl sub_8006518
	ldr r1, [r4]
	ldr r0, [r1]
	cmp r0, 0x2
	bne _0801BFF8
	adds r1, 0xF4
	ldr r0, _0801BFF4
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	b _0801C01A
	.align 2, 0
_0801BFF0: .4byte gUnknown_203B238
_0801BFF4: .4byte gUnknown_80DBDB0
_0801BFF8:
	mov r12, r4
	ldr r4, _0801C034
	movs r3, 0
	movs r2, 0x3
_0801C000:
	mov r0, r12
	ldr r1, [r0]
	adds r1, r3
	adds r1, 0xC4
	adds r0, r4, 0
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	adds r3, 0x18
	subs r2, 0x1
	cmp r2, 0
	bge _0801C000
_0801C01A:
	bl ResetUnusedInputStruct
	ldr r0, _0801C038
	ldr r0, [r0]
	adds r0, 0xC4
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C034: .4byte gUnknown_80DBD98
_0801C038: .4byte gUnknown_203B238
	thumb_func_end sub_801BFCC

	thumb_func_start sub_801C03C
sub_801C03C:
	push {lr}
	sub sp, 0x8
	ldr r1, _0801C058
	ldr r0, [r1]
	ldr r0, [r0]
	adds r2, r1, 0
	cmp r0, 0x4
	bhi _0801C0C2
	lsls r0, 2
	ldr r1, _0801C05C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C058: .4byte gUnknown_203B238
_0801C05C: .4byte _0801C060
	.align 2, 0
_0801C060:
	.4byte _0801C074
	.4byte _0801C084
	.4byte _0801C08C
	.4byte _0801C0B8
	.4byte _0801C0C2
_0801C074:
	ldr r0, [r2]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	movs r1, 0
	movs r2, 0x8
	bl sub_801C244
	b _0801C0C2
_0801C084:
	movs r0, 0x1
	bl sub_801C3B0
	b _0801C0C2
_0801C08C:
	bl sub_801C4C8
	bl sub_801C0C8
	ldr r0, _0801C0B4
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x74
	adds r1, r2, 0
	adds r1, 0x34
	ldr r2, [r2, 0x30]
	str r2, [sp]
	movs r2, 0x2
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0
	bl sub_8012D60
	b _0801C0C2
	.align 2, 0
_0801C0B4: .4byte gUnknown_203B238
_0801C0B8:
	ldr r0, [r2]
	adds r0, 0x28
	ldrb r0, [r0]
	bl sub_801C620
_0801C0C2:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_801C03C

	thumb_func_start sub_801C0C8
sub_801C0C8:
	push {r4,r5,lr}
	ldr r3, _0801C10C
	ldr r1, [r3]
	movs r4, 0
	ldr r0, _0801C110
	str r0, [r1, 0x34]
	movs r0, 0x2
	str r0, [r1, 0x38]
	movs r2, 0x1
	ldr r0, _0801C114
	ldr r0, [r0]
	str r0, [r1, 0x3C]
	movs r0, 0x3
	str r0, [r1, 0x40]
	movs r5, 0x2
	str r4, [r1, 0x44]
	str r2, [r1, 0x48]
	movs r2, 0
	ldr r4, [r1, 0x30]
	adds r1, 0x38
_0801C0F0:
	ldr r0, [r1]
	cmp r0, r4
	beq _0801C104
	adds r1, 0x8
	adds r2, 0x1
	cmp r2, r5
	blt _0801C0F0
	ldr r1, [r3]
	movs r0, 0x2
	str r0, [r1, 0x30]
_0801C104:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C10C: .4byte gUnknown_203B238
_0801C110: .4byte gUnknown_80DBDC8
_0801C114: .4byte gUnknown_80D4970
	thumb_func_end sub_801C0C8

	thumb_func_start sub_801C118
sub_801C118:
	push {lr}
	movs r0, 0x1
	bl sub_801C308
	cmp r0, 0x4
	bhi _0801C19A
	lsls r0, 2
	ldr r1, _0801C130
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C130: .4byte _0801C134
	.align 2, 0
_0801C134:
	.4byte _0801C19A
	.4byte _0801C19A
	.4byte _0801C190
	.4byte _0801C148
	.4byte _0801C16C
_0801C148:
	bl sub_801C390
	ldr r1, _0801C168
	ldr r2, [r1]
	str r0, [r2, 0x24]
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r0
	ldrb r0, [r1]
	adds r2, 0x28
	strb r0, [r2]
	movs r0, 0x2
	bl sub_801BFB4
	b _0801C19A
	.align 2, 0
_0801C168: .4byte gUnknown_203B238
_0801C16C:
	bl sub_801C390
	ldr r1, _0801C18C
	ldr r2, [r1]
	str r0, [r2, 0x24]
	adds r1, r2, 0
	adds r1, 0xC
	adds r1, r0
	ldrb r0, [r1]
	adds r2, 0x28
	strb r0, [r2]
	movs r0, 0x3
	bl sub_801BFB4
	b _0801C19A
	.align 2, 0
_0801C18C: .4byte gUnknown_203B238
_0801C190:
	bl sub_801C3F8
	movs r0, 0x4
	bl sub_801BFB4
_0801C19A:
	pop {r0}
	bx r0
	thumb_func_end sub_801C118

	thumb_func_start sub_801C1A0
sub_801C1A0:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801C308
	ldr r4, _0801C1E0
	ldr r0, [r4]
	adds r0, 0x74
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _0801C1D0
	ldr r0, [r4]
	adds r0, 0x74
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _0801C1D0
	ldr r0, [r4]
	str r1, [r0, 0x30]
_0801C1D0:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _0801C1EA
	cmp r0, 0x2
	bgt _0801C1E4
	cmp r0, 0x1
	beq _0801C218
	b _0801C21E
	.align 2, 0
_0801C1E0: .4byte gUnknown_203B238
_0801C1E4:
	cmp r0, 0x3
	beq _0801C210
	b _0801C21E
_0801C1EA:
	ldr r0, _0801C208
	bl PlaySound
	ldr r0, _0801C20C
	ldr r1, [r0]
	ldr r0, [r1, 0x8]
	adds r0, 0x20
	adds r1, 0x28
	ldrb r1, [r1]
	bl sub_808EBF4
	movs r0, 0x1
	bl sub_801BFB4
	b _0801C21E
	.align 2, 0
_0801C208: .4byte 0x00000133
_0801C20C: .4byte gUnknown_203B238
_0801C210:
	movs r0, 0x3
	bl sub_801BFB4
	b _0801C21E
_0801C218:
	movs r0, 0x1
	bl sub_801BFB4
_0801C21E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_801C1A0

	thumb_func_start sub_801C228
sub_801C228:
	push {lr}
	bl sub_801C674
	cmp r0, 0x1
	bls _0801C240
	cmp r0, 0x3
	bhi _0801C240
	bl sub_801C6B4
	movs r0, 0x1
	bl sub_801BFB4
_0801C240:
	pop {r0}
	bx r0
	thumb_func_end sub_801C228

	thumb_func_start sub_801C244
sub_801C244:
	push {r4-r7,lr}
	adds r6, r1, 0
	adds r7, r2, 0
	lsls r0, 16
	asrs r0, 16
	adds r4, r0, 0
	bl sub_801C5F0
	lsls r0, 24
	cmp r0, 0
	beq _0801C25E
	movs r0, 0
	b _0801C2F6
_0801C25E:
	ldr r5, _0801C2FC
	ldr r0, [r5]
	cmp r0, 0
	bne _0801C270
	movs r0, 0xC4
	movs r1, 0x8
	bl MemoryAlloc
	str r0, [r5]
_0801C270:
	ldr r0, [r5]
	strh r4, [r0]
	ldr r3, _0801C300
	movs r1, 0x58
	adds r2, r4, 0
	muls r2, r1
	ldr r1, [r3]
	adds r1, r2
	str r1, [r0, 0x4]
	adds r0, 0x8
	movs r2, 0x14
	ldrsh r1, [r1, r2]
	bl sub_808EBA8
	adds r1, r0, 0
	ldr r0, [r5]
	str r1, [r0, 0x20]
	str r6, [r0, 0x58]
	lsls r1, r6, 1
	adds r1, r6
	lsls r1, 3
	adds r1, 0x60
	adds r1, r0, r1
	str r1, [r0, 0x5C]
	adds r0, 0x60
	bl sub_8006518
	ldr r1, [r5]
	ldr r2, [r1, 0x58]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r1, r0
	adds r1, 0x60
	ldr r0, _0801C304
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldr r1, [r5]
	ldr r0, [r1, 0x5C]
	adds r1, 0xC0
	str r1, [r0, 0x14]
	adds r1, r7, 0
	bl sub_8012D08
	bl ResetUnusedInputStruct
	ldr r0, [r5]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0x24
	ldr r1, [r1, 0x20]
	adds r2, r7, 0
	adds r3, r6, 0
	bl sub_8013818
	bl sub_801C440
	bl sub_801C4C8
	movs r0, 0x1
_0801C2F6:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C2FC: .4byte gUnknown_203B23C
_0801C300: .4byte gRecruitedPokemonRef
_0801C304: .4byte gUnknown_80DBDF0
	thumb_func_end sub_801C244

	thumb_func_start sub_801C308
sub_801C308:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0801C324
	ldr r0, _0801C320
	ldr r0, [r0]
	adds r0, 0x24
	bl sub_8013660
	movs r0, 0
	b _0801C38A
	.align 2, 0
_0801C320: .4byte gUnknown_203B23C
_0801C324:
	ldr r0, _0801C33C
	ldr r0, [r0]
	adds r0, 0x24
	bl GetKeyPress
	cmp r0, 0x2
	beq _0801C346
	cmp r0, 0x2
	bgt _0801C340
	cmp r0, 0x1
	beq _0801C350
	b _0801C364
	.align 2, 0
_0801C33C: .4byte gUnknown_203B23C
_0801C340:
	cmp r0, 0x4
	beq _0801C35A
	b _0801C364
_0801C346:
	movs r0, 0x1
	bl PlayMenuSoundEffect
	movs r0, 0x2
	b _0801C38A
_0801C350:
	movs r0, 0
	bl PlayMenuSoundEffect
	movs r0, 0x3
	b _0801C38A
_0801C35A:
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0x4
	b _0801C38A
_0801C364:
	ldr r0, _0801C37C
	ldr r0, [r0]
	adds r0, 0x24
	movs r1, 0x1
	bl sub_80138B8
	lsls r0, 24
	cmp r0, 0
	bne _0801C380
	movs r0, 0
	b _0801C38A
	.align 2, 0
_0801C37C: .4byte gUnknown_203B23C
_0801C380:
	bl sub_801C440
	bl sub_801C4C8
	movs r0, 0x1
_0801C38A:
	pop {r1}
	bx r1
	thumb_func_end sub_801C308

	thumb_func_start sub_801C390
sub_801C390:
	ldr r0, _0801C3AC
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r0, r1
	movs r3, 0x3C
	ldrsh r1, [r2, r3]
	adds r0, r1
	bx lr
	.align 2, 0
_0801C3AC: .4byte gUnknown_203B23C
	thumb_func_end sub_801C390

	thumb_func_start sub_801C3B0
sub_801C3B0:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl ResetUnusedInputStruct
	ldr r5, _0801C3F4
	ldr r0, [r5]
	adds r0, 0x60
	movs r1, 0
	movs r2, 0
	bl sub_800641C
	ldr r0, [r5]
	ldr r1, [r0, 0x20]
	adds r2, r0, 0
	adds r2, 0x46
	strh r1, [r2]
	adds r0, 0x24
	bl sub_8013984
	bl sub_801C440
	bl sub_801C4C8
	cmp r4, 0
	beq _0801C3EE
	ldr r0, [r5]
	adds r0, 0x24
	bl AddMenuCursorSprite
_0801C3EE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C3F4: .4byte gUnknown_203B23C
	thumb_func_end sub_801C3B0

	thumb_func_start sub_801C3F8
sub_801C3F8:
	push {r4,r5,lr}
	ldr r4, _0801C438
	ldr r2, [r4]
	cmp r2, 0
	beq _0801C432
	ldr r0, [r2, 0x58]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x60
	ldr r0, _0801C43C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801C432:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C438: .4byte gUnknown_203B23C
_0801C43C: .4byte gUnknown_80DBDD8
	thumb_func_end sub_801C3F8

	thumb_func_start sub_801C440
sub_801C440:
	push {r4,lr}
	ldr r4, _0801C4C4
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x44
	ldrh r1, [r1]
	adds r0, 0xC0
	movs r2, 0
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0x42
	ldrh r1, [r1]
	adds r0, 0xC1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC2
	movs r1, 0xA
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, 0xC3
	strb r2, [r0]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	ldr r0, [r4]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	movs r1, 0xC
	bl sub_80095E4
	adds r0, 0x2
	ldr r2, [r4]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r1, r2, r1
	adds r1, 0x6E
	lsls r0, 16
	lsrs r0, 16
	strh r0, [r1]
	ldr r3, [r2, 0x58]
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 3
	adds r2, r1
	adds r2, 0x70
	strh r0, [r2]
	bl ResetUnusedInputStruct
	ldr r0, [r4]
	adds r0, 0x60
	movs r1, 0x1
	movs r2, 0x1
	bl sub_800641C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C4C4: .4byte gUnknown_203B23C
	thumb_func_end sub_801C440

	thumb_func_start sub_801C4C8
sub_801C4C8:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r6, _0801C594
	ldr r0, [r6]
	ldr r0, [r0, 0x58]
	bl sub_8008C54
	ldr r0, [r6]
	ldr r0, [r0, 0x58]
	bl sub_80073B8
	ldr r0, [r6]
	adds r1, r0, 0
	adds r1, 0x42
	movs r2, 0
	ldrsh r4, [r1, r2]
	lsls r4, 3
	adds r5, r4, 0
	adds r5, 0xA
	ldr r2, _0801C598
	ldr r3, [r0, 0x58]
	movs r0, 0
	str r0, [sp]
	adds r0, r5, 0
	movs r1, 0
	bl xxx_call_draw_string
	adds r4, 0x4
	ldr r1, [r6]
	adds r0, r1, 0
	adds r0, 0xC2
	ldrb r0, [r0]
	lsls r0, 3
	adds r5, r4, r0
	adds r0, r1, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r2, [r0, r3]
	adds r2, 0x1
	movs r0, 0x7
	str r0, [sp]
	ldr r0, [r1, 0x58]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r3, 0x1
	bl sub_8012BC4
	movs r5, 0
	ldr r0, [r6]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _0801C5CC
	ldr r2, _0801C59C
	mov r8, r2
_0801C53C:
	ldr r2, [r6]
	adds r0, r2, 0
	adds r0, 0x42
	movs r3, 0
	ldrsh r1, [r0, r3]
	subs r0, 0x2
	movs r3, 0
	ldrsh r0, [r0, r3]
	muls r1, r0
	adds r1, r5
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1
	ldrb r4, [r0]
	adds r0, r2, 0
	adds r0, 0x24
	adds r1, r5, 0
	bl sub_8013800
	adds r7, r0, 0
	adds r0, r4, 0
	bl GetIQSkillName
	adds r1, r0, 0
	mov r0, r8
	movs r2, 0x50
	bl strncpy
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, 0x20
	movs r1, 0x1
	lsls r1, r4
	bl sub_808ECD0
	lsls r0, 24
	cmp r0, 0
	beq _0801C5A4
	mov r0, r8
	subs r0, 0x50
	ldr r1, _0801C5A0
	bl strcpy
	b _0801C5AE
	.align 2, 0
_0801C594: .4byte gUnknown_203B23C
_0801C598: .4byte gUnknown_80DBE08
_0801C59C: .4byte gUnknown_202DEA8
_0801C5A0: .4byte gUnknown_80DBE14
_0801C5A4:
	mov r0, r8
	subs r0, 0x50
	ldr r1, _0801C5E4
	bl strcpy
_0801C5AE:
	ldr r0, [r6]
	ldr r3, [r0, 0x58]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	adds r1, r7, 0
	ldr r2, _0801C5E8
	bl sub_8014FF0
	adds r5, 0x1
	ldr r0, [r6]
	movs r1, 0x3E
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0801C53C
_0801C5CC:
	ldr r0, _0801C5EC
	ldr r0, [r0]
	ldr r0, [r0, 0x58]
	bl sub_80073E0
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C5E4: .4byte gUnknown_80DBE18
_0801C5E8: .4byte gUnknown_80DBE1C
_0801C5EC: .4byte gUnknown_203B23C
	thumb_func_end sub_801C4C8

	thumb_func_start sub_801C5F0
sub_801C5F0:
	push {lr}
	sub sp, 0x18
	lsls r0, 16
	asrs r0, 16
	ldr r2, _0801C614
	movs r1, 0x58
	muls r1, r0
	ldr r0, [r2]
	adds r0, r1
	movs r2, 0x14
	ldrsh r1, [r0, r2]
	mov r0, sp
	bl sub_808EBA8
	cmp r0, 0
	beq _0801C618
	movs r0, 0
	b _0801C61A
	.align 2, 0
_0801C614: .4byte gRecruitedPokemonRef
_0801C618:
	movs r0, 0x1
_0801C61A:
	add sp, 0x18
	pop {r1}
	bx r1
	thumb_func_end sub_801C5F0

        .align 2,0
