	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_807FCD4
sub_807FCD4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	movs r1, 0
	ldrsh r0, [r7, r1]
	movs r2, 0x2
	ldrsh r1, [r7, r2]
	bl GetMapTile_2
	adds r6, r0, 0
	cmp r5, 0x13
	bls _0807FD12
	movs r4, 0
	b _0807FCFE
_0807FCFC:
	adds r4, 0x1
_0807FCFE:
	cmp r4, 0x1D
	bgt _0807FD0C
	bl sub_803D6FC
	adds r5, r0, 0
	cmp r5, 0x11
	beq _0807FCFC
_0807FD0C:
	cmp r4, 0x1E
	bne _0807FD12
	movs r5, 0x10
_0807FD12:
	ldrh r1, [r6]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _0807FD6E
	ldrb r0, [r6, 0x9]
	cmp r0, 0xFF
	beq _0807FD6E
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0807FD6E
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0807FD6E
	movs r4, 0x3
	ands r4, r1
	cmp r4, 0x1
	bne _0807FD6E
	ldr r0, [r6, 0x14]
	cmp r0, 0
	beq _0807FD60
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FD6E
	ldr r0, [r6, 0x14]
	bl GetTrapData
	strb r5, [r0]
	ldr r0, [r6, 0x14]
	bl GetTrapData
	mov r1, r8
	strb r1, [r0, 0x1]
	ldr r0, [r6, 0x14]
	b _0807FD74
_0807FD60:
	adds r0, r5, 0
	adds r1, r7, 0
	mov r2, r8
	bl sub_8045684
	cmp r0, 0
	bne _0807FD72
_0807FD6E:
	movs r0, 0
	b _0807FD7A
_0807FD72:
	str r0, [r6, 0x14]
_0807FD74:
	adds r0, 0x20
	strb r4, [r0]
	movs r0, 0x1
_0807FD7A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_807FCD4

	thumb_func_start sub_807FD84
sub_807FD84:
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, _0807FD9C
	ldr r0, [r4]
	ldr r2, _0807FDA0
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _0807FDA4
	movs r0, 0
	b _0807FDF6
	.align 2, 0
_0807FD9C: .4byte gDungeonGlobalData
_0807FDA0: .4byte 0x00013570
_0807FDA4:
	strb r5, [r1]
	ldr r2, [r4]
	ldr r3, _0807FDD8
	adds r0, r2, r3
	adds r3, 0x4
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r3, 0x1
	adds r2, r3
	ldrb r2, [r2]
	bl sub_807FCD4
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	beq _0807FDE0
	ldr r1, [r4]
	ldr r0, _0807FDD8
	adds r1, r0
	ldr r0, _0807FDDC
	ldr r2, [r0]
	adds r0, r6, 0
	bl sub_8052364
	b _0807FDF0
	.align 2, 0
_0807FDD8: .4byte 0x00013574
_0807FDDC: .4byte gUnknown_80FC5F8
_0807FDE0:
	ldr r1, [r4]
	ldr r2, _0807FDFC
	adds r1, r2
	ldr r0, _0807FE00
	ldr r2, [r0]
	adds r0, r6, 0
	bl sub_8052364
_0807FDF0:
	bl sub_8049ED4
	adds r0, r5, 0
_0807FDF6:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807FDFC: .4byte 0x00013574
_0807FE00: .4byte gUnknown_80FC5FC
	thumb_func_end sub_807FD84

	thumb_func_start sub_807FE04
sub_807FE04:
	push {r4,r5,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl GetMapTile_2
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FE3C
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FE3C
	ldr r1, [r4, 0x14]
	movs r0, 0
	str r0, [r1]
	str r0, [r4, 0x14]
	cmp r5, 0
	beq _0807FE38
	bl sub_8049ED4
_0807FE38:
	movs r0, 0x1
	b _0807FE3E
_0807FE3C:
	movs r0, 0
_0807FE3E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_807FE04

	thumb_func_start sub_807FE44
sub_807FE44:
	push {r4,r5,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r1, 0
	ldrsh r0, [r2, r1]
	movs r3, 0x2
	ldrsh r1, [r2, r3]
	bl GetMapTile_1
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _0807FE7C
	bl GetEntityType
	cmp r0, 0x2
	bne _0807FE7C
	ldr r0, [r4, 0x14]
	adds r0, 0x20
	movs r1, 0x1
	strb r1, [r0]
	cmp r5, 0
	beq _0807FE78
	bl sub_8049ED4
_0807FE78:
	movs r0, 0x1
	b _0807FE7E
_0807FE7C:
	movs r0, 0
_0807FE7E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_807FE44

	thumb_func_start GetTrapName
GetTrapName:
	push {lr}
	lsls r1, 24
	ldr r2, _0807FE98
	lsrs r1, 22
	adds r1, r2
	ldr r1, [r1]
	bl strcpy
	pop {r0}
	bx r0
	.align 2, 0
_0807FE98: .4byte gTrapNames
	thumb_func_end GetTrapName

	thumb_func_start sub_807FE9C
sub_807FE9C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r5, r0, 0
	mov r9, r1
	str r2, [sp]
	lsls r3, 24
	lsrs r6, r3, 24
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r3, 0x2
	ldrsh r1, [r1, r3]
	bl GetMapTile_2
	str r0, [sp, 0x4]
	ldr r0, [r0, 0x14]
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0x8]
	cmp r0, 0
	bne _0807FECE
	b _080801B4
_0807FECE:
	bl GetEntityType
	cmp r0, 0x2
	beq _0807FED8
	b _080801B4
_0807FED8:
	mov r0, r10
	bl GetTrapData
	mov r8, r0
	ldr r0, _0807FF58
	mov r2, r8
	ldrb r1, [r2]
	bl GetTrapName
	ldr r3, [sp, 0x4]
	ldr r4, [r3, 0x10]
	cmp r4, 0
	beq _0807FEFE
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x1
	beq _0807FEFE
	movs r4, 0
_0807FEFE:
	mov r1, r10
	adds r1, 0x20
	ldrb r0, [r1]
	str r0, [sp, 0xC]
	movs r0, 0x1
	strb r0, [r1]
	cmp r4, 0
	beq _0807FF96
	adds r0, r4, 0
	bl sub_806A1E8
	cmp r6, 0
	beq _0807FF96
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x11
	beq _0807FF96
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r7, r0, 0
	movs r6, 0
	adds r0, r4, 0
	movs r1, 0x1C
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _0807FF3C
	ldr r0, _0807FF5C
	ldr r6, [r0]
_0807FF3C:
	ldr r2, [sp, 0xC]
	cmp r2, 0x1
	beq _0807FF50
	ldr r0, _0807FF60
	ldr r0, [r0]
	ldr r3, _0807FF64
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807FF68
_0807FF50:
	cmp r7, 0
	bge _0807FF70
	b _0807FF6C
	.align 2, 0
_0807FF58: .4byte gAvailablePokemonNames
_0807FF5C: .4byte gUnknown_80FDB5C
_0807FF60: .4byte gDungeonGlobalData
_0807FF64: .4byte 0x0001820f
_0807FF68:
	cmp r7, 0xE
	bgt _0807FF70
_0807FF6C:
	ldr r0, _0807FFD8
	ldr r6, [r0]
_0807FF70:
	cmp r6, 0
	beq _0807FF96
	mov r0, r9
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0807FF84
	bl sub_8049ED4
_0807FF84:
	adds r0, r5, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_80522F4
	ldr r0, [sp]
	cmp r0, 0
	bne _0807FF96
	b _080801B4
_0807FF96:
	mov r0, r9
	bl sub_803F428
	lsls r0, 24
	cmp r0, 0
	beq _0807FFFA
	movs r1, 0xAE
	lsls r1, 1
	movs r0, 0
	bl sub_80421C0
	bl sub_8049ED4
	mov r1, r8
	ldrb r2, [r1]
	adds r0, r5, 0
	mov r1, r9
	bl sub_804225C
	ldr r0, _0807FFDC
	ldr r0, [r0]
	ldr r2, _0807FFE0
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0807FFE8
	ldr r0, _0807FFE4
	ldr r1, [r0]
	adds r0, r5, 0
	bl SendMessage
	b _0807FFFA
	.align 2, 0
_0807FFD8: .4byte gUnknown_80FDB7C
_0807FFDC: .4byte gDungeonGlobalData
_0807FFE0: .4byte 0x0001820a
_0807FFE4: .4byte gUnknown_80FD7F4
_0807FFE8:
	ldr r0, _08080010
	mov r3, r8
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r5, 0
	bl SendMessage
_0807FFFA:
	cmp r4, 0
	beq _08080020
	mov r1, r8
	ldrb r0, [r1, 0x1]
	cmp r0, 0x2
	bne _08080014
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806F480
	b _08080020
	.align 2, 0
_08080010: .4byte gUnknown_80FD7F8
_08080014:
	cmp r0, 0x1
	bne _08080020
	adds r0, r4, 0
	movs r1, 0
	bl sub_806F480
_08080020:
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0x1B
	bls _0808002A
	b _08080194
_0808002A:
	lsls r0, 2
	ldr r1, _08080034
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08080034: .4byte _08080038
	.align 2, 0
_08080038:
	.4byte _080800A8
	.4byte _080800B2
	.4byte _080800BC
	.4byte _080800C6
	.4byte _080800D0
	.4byte _080800DA
	.4byte _080800E6
	.4byte _080800F0
	.4byte _080800FA
	.4byte _08080104
	.4byte _0808010E
	.4byte _08080118
	.4byte _08080122
	.4byte _0808012C
	.4byte _08080136
	.4byte _08080140
	.4byte _0808014A
	.4byte _08080168
	.4byte _08080172
	.4byte _08080180
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _08080194
	.4byte _080800DA
_080800A8:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080A5C
	b _08080194
_080800B2:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80801CC
	b _08080194
_080800BC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808024C
	b _08080194
_080800C6:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080418
	b _08080194
_080800D0:
	adds r0, r5, 0
	mov r1, r9
	bl sub_8080620
	b _0808017A
_080800DA:
	adds r0, r5, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x4]
	bl sub_8080504
	b _08080194
_080800E6:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080374
	b _08080194
_080800F0:
	mov r0, r10
	adds r1, r4, 0
	bl sub_8080884
	b _08080194
_080800FA:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080364
	b _08080194
_08080104:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080388
	b _08080194
_0808010E:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803B4
	b _08080194
_08080118:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80807C0
	b _08080194
_08080122:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803C8
	b _08080194
_0808012C:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803D8
	b _08080194
_08080136:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80803F8
	b _08080194
_08080140:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8080700
	b _08080194
_0808014A:
	cmp r4, 0
	beq _08080194
	ldr r0, _08080160
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _08080164
	adds r0, r4, 0
	movs r2, 0xF
	bl sub_806F324
	b _08080194
	.align 2, 0
_08080160: .4byte gUnknown_80F4F86
_08080164: .4byte 0x00000213
_08080168:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80807B4
	b _08080194
_08080172:
	adds r0, r5, 0
	mov r1, r9
	bl sub_80808A4
_0808017A:
	movs r3, 0x1
	str r3, [sp, 0x8]
	b _08080194
_08080180:
	cmp r4, 0
	beq _08080194
	ldr r0, _080801C4
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _080801C8
	adds r0, r4, 0
	movs r2, 0xA
	bl sub_806F324
_08080194:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080801A6
	adds r0, r4, 0
	bl sub_8071DA4
_080801A6:
	ldr r3, [sp, 0x8]
	cmp r3, 0
	beq _080801B4
	mov r0, r9
	movs r1, 0x1
	bl sub_807FE04
_080801B4:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080801C4: .4byte gUnknown_80F4F84
_080801C8: .4byte 0x00000206
	thumb_func_end sub_807FE9C

	thumb_func_start sub_80801CC
sub_80801CC:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _08080240
	movs r0, 0x64
	bl DungeonRandomCapped
	adds r1, r0, 0
	cmp r0, 0x18
	bgt _080801EC
	ldr r0, _080801E8
	b _080801F2
	.align 2, 0
_080801E8: .4byte gUnknown_8106A4C
_080801EC:
	cmp r0, 0x31
	bgt _0808020C
	ldr r0, _08080208
_080801F2:
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl LowerAttackStageTarget
	b _08080240
	.align 2, 0
_08080208: .4byte gUnknown_8106A50
_0808020C:
	cmp r1, 0x4A
	bgt _0808022C
	ldr r0, _08080228
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl LowerDefenseStageTarget
	b _08080240
	.align 2, 0
_08080228: .4byte gUnknown_8106A4C
_0808022C:
	ldr r0, _08080248
	ldr r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl LowerDefenseStageTarget
_08080240:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08080248: .4byte gUnknown_8106A50
	thumb_func_end sub_80801CC

	thumb_func_start sub_808024C
sub_808024C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x5C
	str r0, [sp, 0x54]
	mov r10, r1
	ldr r0, [r1, 0x70]
	mov r8, r0
	mov r0, r10
	movs r1, 0xE
	bl HasItem
	lsls r0, 24
	cmp r0, 0
	beq _08080278
	ldr r0, _08080274
	b _08080300
	.align 2, 0
_08080274: .4byte gUnknown_80FDC7C
_08080278:
	movs r6, 0
	mov r1, r8
	ldrb r0, [r1, 0x7]
	movs r1, 0x60
	add r1, r8
	mov r9, r1
	cmp r0, 0
	beq _080802C8
	movs r5, 0
	ldr r7, _0808030C
	mov r0, sp
	str r0, [sp, 0x58]
_08080290:
	lsls r4, r5, 2
	ldr r0, [r7]
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080802C2
	ldrb r0, [r2, 0x2]
	bl IsNotSpecialItem
	lsls r0, 24
	cmp r0, 0
	beq _080802C2
	ldr r0, [r7]
	adds r2, r0, r4
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080802C2
	ldr r1, [sp, 0x58]
	stm r1!, {r2}
	str r1, [sp, 0x58]
	adds r6, 0x1
_080802C2:
	adds r5, 0x1
	cmp r5, 0x13
	ble _08080290
_080802C8:
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080802FA
	mov r0, r8
	adds r0, 0x62
	ldrb r0, [r0]
	bl IsNotSpecialItem
	lsls r0, 24
	cmp r0, 0
	beq _080802FA
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080802FA
	lsls r0, r6, 2
	add r0, sp
	mov r1, r9
	str r1, [r0]
	adds r6, 0x1
_080802FA:
	cmp r6, 0
	bne _08080314
	ldr r0, _08080310
_08080300:
	ldr r2, [r0]
	ldr r0, [sp, 0x54]
	mov r1, r10
	bl sub_80522F4
	b _0808034A
	.align 2, 0
_0808030C: .4byte gTeamInventory_203B460
_08080310: .4byte gUnknown_80FDC40
_08080314:
	adds r0, r6, 0
	bl DungeonRandomCapped
	ldr r2, _0808035C
	lsls r0, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r1, [r4]
	adds r0, r2, 0
	bl sub_8045BF8
	ldr r2, [r4]
	ldrb r1, [r2]
	movs r0, 0x8
	orrs r0, r1
	strb r0, [r2]
	movs r1, 0xC9
	lsls r1, 1
	mov r0, r10
	bl sub_80421C0
	ldr r0, _08080360
	ldr r2, [r0]
	ldr r0, [sp, 0x54]
	mov r1, r10
	bl sub_80522F4
_0808034A:
	add sp, 0x5C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808035C: .4byte gUnknown_202DE58
_08080360: .4byte gUnknown_80FDC18
	thumb_func_end sub_808024C

	thumb_func_start sub_8080364
sub_8080364:
	push {lr}
	cmp r1, 0
	beq _08080370
	movs r2, 0x1
	bl ConfuseStatusTarget
_08080370:
	pop {r0}
	bx r0
	thumb_func_end sub_8080364

	thumb_func_start sub_8080374
sub_8080374:
	push {lr}
	cmp r1, 0
	beq _08080382
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_08080382:
	pop {r0}
	bx r0
	thumb_func_end sub_8080374

	thumb_func_start sub_8080388
sub_8080388:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _080803A8
	ldr r1, _080803B0
	adds r0, r4, 0
	movs r2, 0x1
	bl CalculateStatusTurns
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_8075C58
_080803A8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080803B0: .4byte gUnknown_80F4E74
	thumb_func_end sub_8080388

	thumb_func_start sub_80803B4
sub_80803B4:
	push {lr}
	cmp r1, 0
	beq _080803C2
	movs r2, 0x1
	movs r3, 0x1
	bl sub_80779F0
_080803C2:
	pop {r0}
	bx r0
	thumb_func_end sub_80803B4

	thumb_func_start sub_80803C8
sub_80803C8:
	push {lr}
	cmp r1, 0
	beq _080803D4
	movs r2, 0x1
	bl PoisonedStatusTarget
_080803D4:
	pop {r0}
	bx r0
	thumb_func_end sub_80803C8

	thumb_func_start sub_80803D8
sub_80803D8:
	push {lr}
	sub sp, 0x8
	adds r2, r1, 0x4
	movs r3, 0
	str r3, [sp]
	ldr r3, _080803F4
	str r3, [sp, 0x4]
	movs r3, 0x1
	bl sub_807DF38
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_080803F4: .4byte 0x00000212
	thumb_func_end sub_80803D8

	thumb_func_start sub_80803F8
sub_80803F8:
	push {lr}
	sub sp, 0x8
	adds r2, r1, 0x4
	movs r3, 0
	str r3, [sp]
	ldr r3, _08080414
	str r3, [sp, 0x4]
	movs r3, 0x2
	bl sub_807DF38
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_08080414: .4byte 0x00000212
	thumb_func_end sub_80803F8

	thumb_func_start sub_8080418
sub_8080418:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x58
	mov r8, r0
	adds r6, r1, 0
	movs r0, 0
	mov r9, r0
	cmp r6, 0
	beq _080804F0
	ldr r7, [r6, 0x70]
	movs r3, 0
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0808045A
	ldr r0, _080804C0
	movs r1, 0x1
	mov r12, r1
	ldr r2, [r0]
	mov r4, sp
	movs r5, 0x13
_08080444:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _08080452
	stm r4!, {r2}
	adds r3, 0x1
_08080452:
	adds r2, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08080444
_0808045A:
	adds r2, r7, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08080470
	lsls r0, r3, 2
	add r0, sp
	str r2, [r0]
	adds r3, 0x1
_08080470:
	cmp r3, 0
	ble _080804B6
	mov r4, sp
	adds r5, r3, 0
_08080478:
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	bl GetItemType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _080804AE
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x54
	beq _080804AE
	movs r0, 0x64
	bl DungeonRandomCapped
	ldr r1, _080804C4
	movs r2, 0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	bge _080804AE
	movs r0, 0x1
	add r9, r0
	ldr r0, [r4]
	movs r1, 0x54
	movs r2, 0x2
	bl sub_8045C28
_080804AE:
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bne _08080478
_080804B6:
	mov r1, r9
	cmp r1, 0x1
	bne _080804CC
	ldr r0, _080804C8
	b _080804D4
	.align 2, 0
_080804C0: .4byte gTeamInventory_203B460
_080804C4: .4byte gUnknown_80F4E0E
_080804C8: .4byte gUnknown_80FD788
_080804CC:
	mov r2, r9
	cmp r2, 0
	bne _080804E4
	ldr r0, _080804E0
_080804D4:
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
	b _080804F0
	.align 2, 0
_080804E0: .4byte gUnknown_80FD7D4
_080804E4:
	ldr r0, _08080500
	ldr r2, [r0]
	mov r0, r8
	adds r1, r6, 0
	bl sub_80522F4
_080804F0:
	add sp, 0x58
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080500: .4byte gUnknown_80FD7AC
	thumb_func_end sub_8080418

	thumb_func_start sub_8080504
sub_8080504:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r7, r2, 0
	movs r0, 0
	mov r8, r0
	cmp r4, 0
	bne _0808051A
	b _0808060E
_0808051A:
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _08080534
	ldr r0, _08080530
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _0808060E
	.align 2, 0
_08080530: .4byte gUnknown_80FED0C
_08080534:
	ldr r5, [r4, 0x70]
	adds r0, r4, 0
	bl sub_8045888
	lsls r0, 24
	cmp r0, 0
	beq _0808055E
	adds r0, r7, 0
	movs r1, 0x1B
	bl sub_8080B00
	movs r1, 0x1
	mov r8, r1
	ldr r1, _080805A4
	adds r0, r4, 0
	bl sub_80421C0
	movs r0, 0x1E
	movs r1, 0x48
	bl sub_803E708
_0808055E:
	ldrb r0, [r5, 0x7]
	cmp r0, 0
	beq _080805C4
	bl sub_8043D10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _080805B4
	movs r2, 0xAE
	lsls r2, 1
	adds r0, r5, r2
	movs r1, 0x1
	strb r1, [r0]
	adds r2, 0x2
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, 0x28
	movs r1, 0x4B
	bl sub_803E708
	ldr r0, _080805A8
	movs r2, 0
	ldrsh r1, [r0, r2]
	ldr r3, _080805AC
	adds r0, r4, 0
	movs r2, 0x11
	bl sub_806F324
	ldr r0, _080805B0
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	b _0808060E
	.align 2, 0
_080805A4: .4byte 0x00000193
_080805A8: .4byte gUnknown_80F4F8A
_080805AC: .4byte 0x00000215
_080805B0: .4byte gDungeonGlobalData
_080805B4:
	ldr r0, _080805C0
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _08080600
	.align 2, 0
_080805C0: .4byte gUnknown_80F9728
_080805C4:
	ldr r0, _080805E4
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	beq _080805EC
	ldr r0, _080805E8
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
	b _080805F6
	.align 2, 0
_080805E4: .4byte gAvailablePokemonNames
_080805E8: .4byte gUnknown_80F970C
_080805EC:
	ldr r0, _08080618
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_805239C
_080805F6:
	ldr r1, _0808061C
	adds r0, r4, 0
	adds r2, r6, 0
	bl sub_8068FE0
_08080600:
	mov r0, r8
	cmp r0, 0
	beq _0808060E
	adds r0, r7, 0
	movs r1, 0x5
	bl sub_8080B00
_0808060E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080618: .4byte gUnknown_80F970C
_0808061C: .4byte 0x00000215
	thumb_func_end sub_8080504

	thumb_func_start sub_8080620
sub_8080620:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	str r0, [sp, 0x14]
	adds r7, r1, 0
	movs r0, 0x3
	bl DungeonRandomCapped
	adds r6, r0, 0
	adds r4, r6, 0x2
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r5, r0, 0
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	bne _080806CA
	movs r0, 0
	mov r8, r0
	cmp r8, r4
	bge _080806BA
	mov r4, sp
	movs r1, 0
	mov r10, r1
	movs r2, 0
	mov r9, r2
	adds r6, 0x2
_08080660:
	movs r0, 0
	bl sub_803D970
	movs r1, 0x7
	ands r5, r1
	strh r0, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0
	bl sub_806AA0C
	lsls r0, 24
	cmp r0, 0
	beq _080806B2
	mov r2, r9
	strh r2, [r4, 0x8]
	mov r0, r10
	strb r0, [r4, 0x2]
	ldr r0, _080806D8
	lsls r1, r5, 2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r2, [r7]
	adds r0, r2
	strh r0, [r4, 0xC]
	ldrh r0, [r1, 0x2]
	ldrh r1, [r7, 0x2]
	adds r0, r1
	strh r0, [r4, 0xE]
	mov r2, r9
	str r2, [sp, 0x4]
	mov r0, r10
	strb r0, [r4, 0x10]
	mov r0, sp
	movs r1, 0x1
	bl sub_806B7F8
	cmp r0, 0
	beq _080806B2
	movs r1, 0x1
	add r8, r1
_080806B2:
	adds r5, 0x1
	subs r6, 0x1
	cmp r6, 0
	bne _08080660
_080806BA:
	movs r1, 0xCA
	lsls r1, 1
	adds r0, r7, 0
	bl sub_80421EC
	mov r2, r8
	cmp r2, 0
	bne _080806E0
_080806CA:
	ldr r0, _080806DC
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
	b _080806EA
	.align 2, 0
_080806D8: .4byte gAdjacentTileOffsets
_080806DC: .4byte gUnknown_80FED04
_080806E0:
	ldr r0, _080806FC
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
_080806EA:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080806FC: .4byte gUnknown_80FED00
	thumb_func_end sub_8080620

	thumb_func_start sub_8080700
sub_8080700:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x20
	mov r8, r0
	adds r5, r1, 0
	movs r0, 0
	mov r12, r0
	cmp r5, 0
	beq _080807A4
	ldr r7, [r5, 0x70]
	movs r4, 0
	movs r3, 0
	mov r6, sp
_0808071C:
	lsls r0, r3, 3
	movs r1, 0x8C
	lsls r1, 1
	adds r0, r1
	adds r2, r7, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08080742
	ldrb r0, [r2, 0x4]
	cmp r0, 0
	beq _08080742
	lsls r1, r4, 2
	stm r6!, {r2}
	add r0, sp, 0x10
	adds r0, r1
	str r3, [r0]
	adds r4, 0x1
_08080742:
	adds r3, 0x1
	cmp r3, 0x3
	ble _0808071C
	cmp r4, 0
	beq _0808077A
	adds r0, r4, 0
	bl DungeonRandomCapped
	adds r4, r0, 0
	lsls r4, 2
	mov r0, sp
	adds r2, r0, r4
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x4]
	ldr r0, _08080790
	ldr r1, [r2]
	movs r2, 0
	bl sub_80928C0
	add r0, sp, 0x10
	adds r0, r4
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_806A9B4
	movs r1, 0x1
	mov r12, r1
_0808077A:
	mov r0, r12
	cmp r0, 0
	beq _08080798
	ldr r0, _08080794
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
	b _080807A4
	.align 2, 0
_08080790: .4byte gUnknown_202DE58
_08080794: .4byte gUnknown_80FDA80
_08080798:
	ldr r0, _080807B0
	ldr r2, [r0]
	mov r0, r8
	adds r1, r5, 0
	bl sub_80522F4
_080807A4:
	add sp, 0x20
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080807B0: .4byte gUnknown_80FDAA0
	thumb_func_end sub_8080700

	thumb_func_start sub_80807B4
sub_80807B4:
	push {lr}
	movs r2, 0
	bl sub_8079E34
	pop {r0}
	bx r0
	thumb_func_end sub_80807B4

	thumb_func_start sub_80807C0
sub_80807C0:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	mov r8, r0
	adds r7, r1, 0
	movs r0, 0
	mov r9, r0
	cmp r7, 0
	beq _08080870
	mov r0, r8
	movs r2, 0x1
	bl HasSafeguardStatus
	lsls r0, 24
	cmp r0, 0
	bne _08080870
	ldr r0, [r7, 0x70]
	movs r5, 0
	movs r6, 0x1
	movs r1, 0x8C
	lsls r1, 1
	adds r2, r0, r1
	adds r3, r2, 0
	mov r12, sp
	movs r4, 0x3
_080807F6:
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08080816
	ldrb r1, [r2, 0x1]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08080816
	mov r0, r12
	adds r0, 0x4
	mov r12, r0
	subs r0, 0x4
	stm r0!, {r3}
	adds r5, 0x1
_08080816:
	adds r2, 0x8
	adds r3, 0x8
	subs r4, 0x1
	cmp r4, 0
	bge _080807F6
	cmp r5, 0
	beq _08080848
	adds r0, r5, 0
	bl DungeonRandomCapped
	lsls r0, 2
	mov r1, sp
	adds r3, r1, r0
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r0, _0808085C
	ldr r1, [r3]
	movs r2, 0
	bl sub_80928C0
	movs r0, 0x1
	mov r9, r0
_08080848:
	mov r1, r9
	cmp r1, 0
	beq _08080864
	ldr r0, _08080860
	ldr r2, [r0]
	mov r0, r8
	adds r1, r7, 0
	bl sub_80522F4
	b _08080870
	.align 2, 0
_0808085C: .4byte gUnknown_202DE58
_08080860: .4byte gUnknown_80FDB04
_08080864:
	ldr r0, _08080880
	ldr r2, [r0]
	mov r0, r8
	adds r1, r7, 0
	bl sub_80522F4
_08080870:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080880: .4byte gUnknown_80FDB2C
	thumb_func_end sub_80807C0

	thumb_func_start sub_8080884
sub_8080884:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _0808089E
	movs r0, 0x8
	bl DungeonRandomCapped
	adds r2, r0, 0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_807CD9C
_0808089E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8080884

	thumb_func_start sub_80808A4
sub_80808A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	str r0, [sp, 0x14]
	adds r5, r1, 0
	movs r0, 0
	str r0, [sp, 0x20]
	ldr r6, _080808D0
	ldr r0, [r6]
	ldr r1, _080808D4
	adds r0, r1
	ldrb r4, [r0]
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _080808DC
	ldr r0, _080808D8
	b _08080A2E
	.align 2, 0
_080808D0: .4byte gDungeonGlobalData
_080808D4: .4byte 0x00018209
_080808D8: .4byte gUnknown_80FED08
_080808DC:
	cmp r4, 0
	bne _080808E2
	movs r4, 0x2
_080808E2:
	movs r2, 0
	ldrsh r0, [r5, r2]
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	bl GetMapTile_1
	ldrb r1, [r0, 0x9]
	cmp r1, 0xFF
	bne _0808090A
	movs r0, 0
	ldrsh r1, [r5, r0]
	subs r2, r1, r4
	str r2, [sp, 0x18]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	subs r2, r0, r4
	adds r1, r4
	mov r10, r1
	adds r0, r4
	b _08080934
_0808090A:
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, _08080994
	adds r0, r1
	ldr r1, [r6]
	adds r1, r0
	movs r2, 0x2
	ldrsh r0, [r1, r2]
	subs r0, 0x1
	str r0, [sp, 0x18]
	movs r3, 0x4
	ldrsh r0, [r1, r3]
	subs r2, r0, 0x1
	movs r3, 0x6
	ldrsh r0, [r1, r3]
	adds r0, 0x1
	mov r10, r0
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	adds r0, 0x1
_08080934:
	str r0, [sp, 0x1C]
	adds r7, r2, 0
	ldr r0, [sp, 0x1C]
	cmp r7, r0
	bgt _08080A26
_0808093E:
	ldr r6, [sp, 0x18]
	adds r1, r7, 0x1
	str r1, [sp, 0x24]
	cmp r6, r10
	bgt _08080A1E
	mov r5, sp
_0808094A:
	adds r0, r6, 0
	adds r1, r7, 0
	bl GetMapTile_1
	adds r4, r0, 0
	ldr r0, [r4, 0x14]
	adds r2, r6, 0x1
	mov r9, r2
	cmp r0, 0
	beq _08080A18
	bl GetEntityType
	cmp r0, 0x3
	bne _08080A18
	ldr r0, [r4, 0x14]
	bl GetItemData
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08080A18
	movs r0, 0xBE
	lsls r0, 1
	strh r0, [r5]
	movs r2, 0
	mov r4, sp
_08080980:
	ldr r0, _08080998
	ldr r0, [r0]
	ldr r3, _0808099C
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080809A0
	movs r0, 0xBE
	lsls r0, 1
	b _080809AE
	.align 2, 0
_08080994: .4byte 0x000104c4
_08080998: .4byte gDungeonGlobalData
_0808099C: .4byte 0x0000066e
_080809A0:
	movs r0, 0
	str r2, [sp, 0x28]
	bl sub_803D970
	lsls r0, 16
	asrs r0, 16
	ldr r2, [sp, 0x28]
_080809AE:
	movs r1, 0
	mov r8, r1
	movs r3, 0
	strh r0, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0
	str r2, [sp, 0x28]
	str r3, [sp, 0x2C]
	bl sub_806AA0C
	lsls r0, 24
	ldr r2, [sp, 0x28]
	ldr r3, [sp, 0x2C]
	cmp r0, 0
	bne _080809D4
	adds r2, 0x1
	cmp r2, 0x63
	ble _08080980
_080809D4:
	movs r2, 0
	ldrsh r0, [r5, r2]
	movs r1, 0
	str r3, [sp, 0x2C]
	bl sub_806AA0C
	lsls r0, 24
	ldr r3, [sp, 0x2C]
	cmp r0, 0
	beq _08080A10
	strh r3, [r5, 0x8]
	mov r0, r8
	strb r0, [r5, 0x2]
	strh r6, [r5, 0xC]
	strh r7, [r5, 0xE]
	str r3, [sp, 0x4]
	strb r0, [r5, 0x10]
	mov r0, sp
	movs r1, 0x1
	bl sub_806B7F8
	cmp r0, 0
	beq _08080A10
	add r0, sp, 0xC
	movs r1, 0
	bl sub_80461C8
	ldr r1, [sp, 0x20]
	adds r1, 0x1
	str r1, [sp, 0x20]
_08080A10:
	adds r0, r6, 0
	adds r1, r7, 0
	bl sub_80402AC
_08080A18:
	mov r6, r9
	cmp r6, r10
	ble _0808094A
_08080A1E:
	ldr r7, [sp, 0x24]
	ldr r2, [sp, 0x1C]
	cmp r7, r2
	ble _0808093E
_08080A26:
	ldr r3, [sp, 0x20]
	cmp r3, 0
	beq _08080A3C
	ldr r0, _08080A38
_08080A2E:
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
	b _08080A46
	.align 2, 0
_08080A38: .4byte gUnknown_80FDACC
_08080A3C:
	ldr r0, _08080A58
	ldr r1, [r0]
	ldr r0, [sp, 0x14]
	bl SendMessage
_08080A46:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080A58: .4byte gUnknown_80FDAE4
	thumb_func_end sub_80808A4

	thumb_func_start sub_8080A5C
sub_8080A5C:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r7, r0, 0
	adds r4, r1, 0
	cmp r4, 0
	beq _08080AEC
	adds r0, r4, 0
	movs r1, 0x6
	movs r2, 0x8
	bl sub_806CDD4
	movs r0, 0x10
	movs r1, 0x55
	bl sub_803E708
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_806CE68
	ldr r5, [r4, 0x70]
	adds r2, r5, 0
	adds r2, 0x60
	ldrb r1, [r2]
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08080AEC
	ldr r0, [r5, 0x60]
	str r0, [sp, 0x8]
	movs r0, 0
	strb r0, [r2]
	bl FillInventoryGaps
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, 0
	bl sub_80421C0
	adds r0, r5, 0
	adds r0, 0x46
	ldrb r0, [r0]
	movs r2, 0x7
	ands r2, r0
	ldr r0, _08080AF4
	lsls r2, 2
	adds r2, r0
	ldrh r0, [r2]
	ldrh r1, [r4, 0x4]
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _08080AF8
	ldr r1, [sp, 0x4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, 0x4]
	ldrh r0, [r2, 0x2]
	ldrh r2, [r4, 0x6]
	adds r0, r2
	lsls r0, 16
	ldr r2, _08080AFC
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0x4]
	adds r1, r4, 0x4
	add r3, sp, 0x8
	str r6, [sp]
	adds r0, r7, 0
	add r2, sp, 0x4
	bl sub_804687C
_08080AEC:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080AF4: .4byte gAdjacentTileOffsets
_08080AF8: .4byte 0xffff0000
_08080AFC: .4byte 0x0000ffff
	thumb_func_end sub_8080A5C

	thumb_func_start sub_8080B00
sub_8080B00:
	push {r4,r5,lr}
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r4, [r0, 0x14]
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08080B2A
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _08080B26
	adds r0, r4, 0
	bl GetTrapData
	strb r5, [r0]
_08080B26:
	bl sub_8049ED4
_08080B2A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8080B00

	thumb_func_start sub_8080B30
sub_8080B30:
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	adds r2, r1, 0
	mov r0, sp
	adds r1, r3, 0
	bl sub_8082F9C
	movs r0, 0
	str r0, [sp, 0xC]
	add r1, sp, 0xC
	mov r0, sp
	movs r2, 0x4
	bl sub_8082FA8
	mov r0, sp
	bl sub_8080B90
	mov r0, sp
	bl sub_8081454
	mov r0, sp
	bl sub_808165C
	mov r0, sp
	bl sub_808173C
	mov r0, sp
	bl sub_8080BBC
	mov r0, sp
	bl sub_8080C44
	mov r0, sp
	bl sub_8080CF0
	ldr r1, _08080B8C
	mov r0, sp
	bl sub_808300C
	mov r0, sp
	bl nullsub_98
	add sp, 0x10
	pop {r0}
	bx r0
	.align 2, 0
_08080B8C: .4byte gUnknown_81071D4
	thumb_func_end sub_8080B30

	thumb_func_start sub_8080B90
sub_8080B90:
	push {r4,lr}
	adds r4, r0, 0
	ldr r1, _08080BB0
	bl sub_808300C
	ldr r0, _08080BB4
	ldr r1, [r0]
	ldr r0, _08080BB8
	adds r1, r0
	adds r0, r4, 0
	movs r2, 0x58
	bl sub_8082FA8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080BB0: .4byte gUnknown_81071E0
_08080BB4: .4byte gDungeonGlobalData
_08080BB8: .4byte 0x00000644
	thumb_func_end sub_8080B90

	thumb_func_start sub_8080BBC
sub_8080BBC:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	ldr r1, _08080C38
	movs r2, 0
	add r0, sp, 0x4
_08080BC8:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, sp
	bge _08080BC8
	adds r0, r6, 0
	bl sub_808300C
	movs r7, 0
_08080BD8:
	ldr r0, _08080C3C
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08080C40
	adds r0, r2
	adds r0, r1
	ldr r4, [r0]
	movs r5, 0
	cmp r4, 0
	beq _08080C1A
	adds r0, r4, 0
	bl GetEntityType
	cmp r0, 0x3
	bne _08080C1A
	adds r0, r4, 0
	bl GetItemData
	adds r1, r0, 0
	adds r0, r6, 0
	bl sub_8081788
	adds r1, r4, 0x4
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x6
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	movs r5, 0x1
_08080C1A:
	cmp r5, 0
	bne _08080C28
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x5
	bl sub_8082FA8
_08080C28:
	adds r7, 0x1
	cmp r7, 0x3F
	ble _08080BD8
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080C38: .4byte gUnknown_81071E0
_08080C3C: .4byte gDungeonGlobalData
_08080C40: .4byte 0x0001361c
	thumb_func_end sub_8080BBC

	thumb_func_start sub_8080C44
sub_8080C44:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r7, 0
	ldr r3, _08080CE4
	movs r2, 0xFF
_08080C50:
	mov r0, sp
	adds r1, r0, r7
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r7, 0x1
	cmp r7, 0x4
	ble _08080C50
	adds r0, r6, 0
	adds r1, r3, 0
	bl sub_808300C
	movs r7, 0
_08080C6A:
	ldr r0, _08080CE8
	ldr r0, [r0]
	lsls r1, r7, 2
	ldr r2, _08080CEC
	adds r0, r2
	adds r0, r1
	ldr r5, [r0]
	movs r4, 0
	cmp r5, 0
	beq _08080CC8
	adds r0, r5, 0
	bl GetEntityType
	cmp r0, 0x2
	bne _08080CC8
	adds r0, r5, 0
	bl GetTrapData
	adds r4, r0, 0
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x1
	adds r0, r6, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0
	adds r1, 0x20
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x4
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x6
	adds r0, r6, 0
	movs r2, 0x1
	bl sub_8082FA8
	movs r4, 0x1
_08080CC8:
	cmp r4, 0
	bne _08080CD6
	adds r0, r6, 0
	mov r1, sp
	movs r2, 0x5
	bl sub_8082FA8
_08080CD6:
	adds r7, 0x1
	cmp r7, 0x3F
	ble _08080C6A
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080CE4: .4byte gUnknown_81071E0
_08080CE8: .4byte gDungeonGlobalData
_08080CEC: .4byte 0x0001371c
	thumb_func_end sub_8080C44

	thumb_func_start sub_8080CF0
sub_8080CF0:
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r1, _08080DD4
	bl sub_808300C
	ldr r4, _08080DD8
	ldr r0, [r4]
	ldr r1, _08080DDC
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8083078
	ldr r0, [r4]
	ldr r2, _08080DE0
	adds r0, r2
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8083078
	ldr r0, [r4]
	ldr r1, _08080DE4
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080DE8
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08080DEC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080DF0
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08080DF4
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080DF8
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08080DFC
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08080E00
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_80830B4
	ldr r0, [r4]
	movs r1, 0xE0
	lsls r1, 6
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r6, 0
	bl sub_8083030
	movs r5, 0
_08080D9A:
	ldr r0, [r4]
	lsls r1, r5, 2
	ldr r2, _08080E04
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8080E0C
	adds r5, 0x1
	cmp r5, 0x3
	ble _08080D9A
	movs r5, 0
	ldr r4, _08080DD8
_08080DB6:
	ldr r0, [r4]
	lsls r1, r5, 2
	ldr r2, _08080E08
	adds r0, r2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r6, 0
	bl sub_8080E0C
	adds r5, 0x1
	cmp r5, 0xF
	ble _08080DB6
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08080DD4: .4byte gUnknown_81071E0
_08080DD8: .4byte gDungeonGlobalData
_08080DDC: .4byte 0x000037f0
_08080DE0: .4byte 0x000037f4
_08080DE4: .4byte 0x000037f8
_08080DE8: .4byte 0x000037f9
_08080DEC: .4byte 0x000037fa
_08080DF0: .4byte 0x000037fb
_08080DF4: .4byte 0x000037fc
_08080DF8: .4byte 0x000037fd
_08080DFC: .4byte 0x000037fe
_08080E00: .4byte 0x000037ff
_08080E04: .4byte 0x0001357c
_08080E08: .4byte 0x0001358c
	thumb_func_end sub_8080CF0

	thumb_func_start sub_8080E0C
sub_8080E0C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, _08080E88
	add sp, r4
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0
	add r0, sp, 0x20C
	str r1, [r0]
	movs r1, 0x1
	movs r6, 0x82
	lsls r6, 2
	mov r2, sp
	adds r0, r2, r6
	str r1, [r0]
	adds r0, r5, 0
	movs r1, 0xAA
	bl sub_8083060
	adds r0, r5, 0
	movs r1, 0x55
	bl sub_8083060
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _08080E8C
	ldr r6, [r4, 0x70]
	add r1, sp, 0x208
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x6
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x20
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x26
	adds r0, r5, 0
	movs r2, 0x2
	bl sub_8082FA8
	b _08080ECC
	.align 2, 0
_08080E88: .4byte 0xfffffd6c
_08080E8C:
	mov r0, sp
	movs r1, 0
	adds r2, r6, 0
	bl memset
	mov r6, sp
	add r4, sp, 0x20C
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x2
	bl sub_8082FA8
_08080ECC:
	ldrh r1, [r6]
	adds r0, r5, 0
	bl sub_8083030
	movs r0, 0x4
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_80817F4
	movs r2, 0x2
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_80817F4
	ldrb r1, [r6, 0x6]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r6, 0x7]
	adds r0, r5, 0
	bl sub_80830B4
	ldrb r1, [r6, 0x8]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x9]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0xA]
	adds r0, r5, 0
	bl sub_8083060
	adds r1, r6, 0
	adds r1, 0x40
	adds r0, r5, 0
	bl sub_80818C8
	movs r0, 0xC
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0xE
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x10
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x12
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	ldrb r1, [r6, 0x14]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x15]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x16]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r6, 0x17]
	adds r0, r5, 0
	bl sub_8083060
	ldr r1, [r6, 0x18]
	adds r0, r5, 0
	bl sub_8083078
	movs r0, 0x1C
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x1E
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x20
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x22
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x24
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	movs r2, 0x26
	ldrsh r1, [r6, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r0, 0x28
	ldrsh r1, [r6, r0]
	adds r0, r5, 0
	bl sub_8083048
	ldr r1, [r6, 0x2C]
	adds r0, r5, 0
	bl sub_80830A0
	ldr r1, [r6, 0x30]
	adds r0, r5, 0
	bl sub_80830A0
	ldr r1, [r6, 0x34]
	adds r0, r5, 0
	bl sub_80830A0
	ldr r1, [r6, 0x38]
	adds r0, r5, 0
	bl sub_80830A0
	adds r1, r6, 0
	adds r1, 0x44
	adds r0, r5, 0
	bl sub_80817C8
	adds r0, r6, 0
	adds r0, 0x5C
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_808180C
	adds r0, r6, 0
	adds r0, 0x5D
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_808180C
	adds r0, r6, 0
	adds r0, 0x5E
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8081824
	adds r0, r6, 0
	adds r0, 0x5F
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8081824
	adds r1, r6, 0
	adds r1, 0x60
	adds r0, r5, 0
	bl sub_8081788
	adds r0, r6, 0
	adds r0, 0x64
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80817B0
	movs r1, 0x78
	adds r1, r6
	mov r8, r1
	movs r2, 0x8C
	adds r2, r6
	mov r9, r2
	movs r0, 0x90
	adds r0, r6
	mov r10, r0
	adds r1, r6, 0
	adds r1, 0x94
	str r1, [sp, 0x214]
	adds r2, r6, 0
	adds r2, 0x3C
	str r2, [sp, 0x210]
	adds r0, r6, 0
	adds r0, 0x98
	str r0, [sp, 0x218]
	adds r1, 0x8
	str r1, [sp, 0x21C]
	adds r2, 0x64
	str r2, [sp, 0x220]
	adds r0, 0x10
	str r0, [sp, 0x228]
	adds r1, 0x10
	str r1, [sp, 0x22C]
	adds r2, 0x10
	str r2, [sp, 0x230]
	adds r0, 0x14
	str r0, [sp, 0x234]
	adds r1, 0x14
	str r1, [sp, 0x238]
	adds r2, 0x14
	str r2, [sp, 0x23C]
	adds r0, 0xC
	str r0, [sp, 0x240]
	adds r1, 0x10
	str r1, [sp, 0x244]
	adds r2, 0x18
	str r2, [sp, 0x248]
	adds r0, 0x18
	str r0, [sp, 0x24C]
	adds r1, 0x14
	str r1, [sp, 0x250]
	adds r2, 0xC
	str r2, [sp, 0x254]
	adds r0, 0xC
	str r0, [sp, 0x258]
	adds r1, 0xC
	str r1, [sp, 0x25C]
	adds r2, 0x9
	str r2, [sp, 0x260]
	adds r0, 0x6
	str r0, [sp, 0x264]
	adds r1, 0x3
	str r1, [sp, 0x268]
	adds r2, 0x3
	str r2, [sp, 0x26C]
	adds r0, 0x9
	str r0, [sp, 0x280]
	adds r1, 0x2
	str r1, [sp, 0x270]
	adds r2, 0x2
	str r2, [sp, 0x274]
	subs r0, 0x4
	str r0, [sp, 0x278]
	adds r1, 0x5
	str r1, [sp, 0x27C]
	adds r2, 0x6
	str r2, [sp, 0x284]
	adds r0, 0x6
	str r0, [sp, 0x288]
	adds r1, 0x4
	str r1, [sp, 0x28C]
	adds r2, 0x3
	str r2, [sp, 0x290]
	subs r0, 0x59
	str r0, [sp, 0x224]
	adds r4, r6, 0
	adds r4, 0x68
	movs r7, 0x3
_080810C2:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80830D8
	adds r4, 0x4
	subs r7, 0x1
	cmp r7, 0
	bge _080810C2
	adds r0, r5, 0
	mov r1, r8
	bl sub_80818E4
	adds r0, r5, 0
	mov r1, r9
	bl sub_8081B54
	adds r0, r5, 0
	mov r1, r10
	bl sub_8081B54
	ldr r2, [sp, 0x214]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_8081880
	adds r0, r5, 0
	ldr r1, [sp, 0x210]
	bl sub_8081898
	ldr r0, [sp, 0x218]
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8083078
	ldr r2, [sp, 0x21C]
	ldr r1, [r2]
	adds r0, r5, 0
	bl sub_8083078
	ldr r0, [sp, 0x220]
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8083078
	adds r0, r5, 0
	ldr r1, [sp, 0x228]
	bl sub_8081920
	adds r0, r5, 0
	ldr r1, [sp, 0x22C]
	bl sub_808193C
	adds r0, r5, 0
	ldr r1, [sp, 0x230]
	bl sub_8081968
	adds r0, r5, 0
	ldr r1, [sp, 0x234]
	bl sub_8081994
	adds r0, r5, 0
	ldr r1, [sp, 0x238]
	bl sub_80819B0
	adds r0, r5, 0
	ldr r1, [sp, 0x23C]
	bl sub_80819D4
	adds r0, r5, 0
	ldr r1, [sp, 0x240]
	bl sub_80819F0
	adds r0, r5, 0
	ldr r1, [sp, 0x244]
	bl sub_8081A24
	adds r0, r5, 0
	ldr r1, [sp, 0x248]
	bl sub_8081A58
	adds r0, r5, 0
	ldr r1, [sp, 0x24C]
	bl sub_8081A74
	adds r0, r5, 0
	ldr r1, [sp, 0x250]
	bl sub_8081A80
	adds r0, r5, 0
	ldr r1, [sp, 0x254]
	bl sub_8081A9C
	adds r0, r5, 0
	ldr r1, [sp, 0x258]
	bl sub_8081AB8
	ldr r2, [sp, 0x25C]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x260]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, [sp, 0x264]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x268]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, [sp, 0x26C]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x280]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, [sp, 0x270]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x274]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, [sp, 0x278]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x27C]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, [sp, 0x284]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [sp, 0x288]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, [sp, 0x28C]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_8083060
	ldr r0, [sp, 0x290]
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_808183C
	movs r1, 0x80
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8081854
	movs r2, 0x82
	lsls r2, 1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_808186C
	movs r0, 0x84
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_808314C
	ldr r2, _08081428
	adds r1, r6, r2
	adds r0, r5, 0
	movs r2, 0x5
	bl sub_808314C
	movs r1, 0x89
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _0808142C
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r1, 0x8A
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r2, 0x8C
	lsls r2, 1
	adds r1, r6, r2
	adds r0, r5, 0
	bl sub_8081B08
	movs r0, 0x9E
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r5, 0
	bl sub_8081B34
	movs r2, 0xA0
	lsls r2, 1
	adds r1, r6, r2
	adds r0, r5, 0
	bl sub_8081B34
	movs r1, 0xA2
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, _08081430
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r1, _08081434
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r2, 0xA3
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xA4
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, _08081438
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xA5
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r2, _0808143C
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xA6
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r2, 0xA7
	lsls r2, 1
	adds r0, r6, r2
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_8083030
	movs r1, 0xA8
	lsls r1, 1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_8083030
	movs r2, 0xA9
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r1, _08081440
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r2, 0xAA
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r1, _08081444
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r2, 0xAB
	lsls r2, 1
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	movs r1, 0xB2
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _08081448
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r1, 0xB3
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _0808144C
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r1, 0xB4
	lsls r1, 1
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r2, _08081450
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	movs r0, 0xB6
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r5, 0
	bl sub_80830D8
	movs r1, 0xBA
	lsls r1, 1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_80830A0
	movs r2, 0xBC
	lsls r2, 1
	adds r0, r6, r2
	ldrh r1, [r0]
	adds r0, r5, 0
	bl sub_8083030
	movs r1, 0xFC
	lsls r1, 1
	adds r0, r6, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r1, 0xFD
	lsls r1, 1
	adds r0, r6, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	movs r1, 0xFE
	lsls r1, 1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r5, 0
	bl sub_8083078
	ldr r2, [sp, 0x224]
	ldrb r1, [r2]
	adds r0, r5, 0
	bl sub_80818B8
	movs r3, 0xA5
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
_08081428: .4byte 0x0000010d
_0808142C: .4byte 0x00000113
_08081430: .4byte 0x00000145
_08081434: .4byte 0x00000147
_08081438: .4byte 0x00000149
_0808143C: .4byte 0x0000014b
_08081440: .4byte 0x00000153
_08081444: .4byte 0x00000155
_08081448: .4byte 0x00000165
_0808144C: .4byte 0x00000167
_08081450: .4byte 0x00000169
	thumb_func_end sub_8080E0C

	thumb_func_start sub_8081454
sub_8081454:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	ldr r1, _08081600
	bl sub_808300C
	ldr r4, _08081604
	ldr r0, [r4]
	ldr r1, _08081608
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _0808160C
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081610
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r2, _08081614
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081618
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r2, _0808161C
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r1, _08081620
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081624
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081628
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _0808162C
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081630
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r7, 0
	bl sub_8083048
	movs r1, 0
	mov r9, r4
_08081510:
	lsls r0, r1, 2
	adds r2, r1, 0x1
	mov r8, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081634
	adds r6, r0, r1
	movs r5, 0
	movs r4, 0x37
_08081526:
	mov r2, r9
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081B60
	adds r5, 0x18
	subs r4, 0x1
	cmp r4, 0
	bge _08081526
	mov r1, r8
	cmp r1, 0x1F
	ble _08081510
	ldr r4, _08081604
	ldr r1, [r4]
	ldr r0, _08081638
	adds r1, r0
	adds r0, r7, 0
	bl sub_80830D8
	ldr r1, [r4]
	ldr r2, _0808163C
	adds r1, r2
	adds r0, r7, 0
	bl sub_80830D8
	ldr r6, _08081640
	movs r5, 0x7
_08081560:
	ldr r1, [r4]
	adds r1, r6
	adds r0, r7, 0
	bl sub_80830D8
	adds r6, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _08081560
	ldr r4, _08081604
	ldr r1, [r4]
	ldr r0, _08081644
	adds r1, r0
	adds r0, r7, 0
	bl sub_80830F8
	ldr r1, [r4]
	ldr r2, _08081648
	adds r1, r2
	adds r0, r7, 0
	bl sub_80830F8
	ldr r1, [r4]
	ldr r0, _0808164C
	adds r1, r0
	adds r0, r7, 0
	bl sub_808312C
	movs r1, 0
	mov r10, r4
_0808159C:
	movs r4, 0
	adds r2, r1, 0x1
	mov r8, r2
	lsls r0, r1, 1
	lsls r2, r1, 3
	mov r9, r2
	adds r0, r1
	lsls r0, 6
	ldr r1, _08081650
	adds r6, r0, r1
	movs r5, 0
_080815B2:
	mov r2, r10
	ldr r1, [r2]
	adds r1, r6
	adds r1, r5
	adds r0, r7, 0
	bl sub_8081B60
	mov r1, r10
	ldr r0, [r1]
	mov r2, r9
	adds r1, r4, r2
	ldr r2, _08081654
	adds r0, r2
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	bl sub_8083060
	adds r5, 0x18
	adds r4, 0x1
	cmp r4, 0x7
	ble _080815B2
	mov r1, r8
	cmp r1, 0x7
	ble _0808159C
	ldr r0, _08081604
	ldr r1, [r0]
	ldr r0, _08081658
	adds r1, r0
	adds r0, r7, 0
	bl sub_8081B94
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081600: .4byte gUnknown_81071E0
_08081604: .4byte gDungeonGlobalData
_08081608: .4byte 0x00003a08
_0808160C: .4byte 0x00003a09
_08081610: .4byte 0x00003a0a
_08081614: .4byte 0x00003a0b
_08081618: .4byte 0x00003a0c
_0808161C: .4byte 0x00003a0d
_08081620: .4byte 0x00003a0e
_08081624: .4byte 0x00003a10
_08081628: .4byte 0x00003a12
_0808162C: .4byte 0x00003a14
_08081630: .4byte 0x00003a16
_08081634: .4byte 0x00003a18
_08081638: .4byte 0x0000e218
_0808163C: .4byte 0x0000e21c
_08081640: .4byte 0x0000e220
_08081644: .4byte 0x0000e240
_08081648: .4byte 0x0000e250
_0808164C: .4byte 0x0000e260
_08081650: .4byte 0x0000e27c
_08081654: .4byte 0x0000e87c
_08081658: .4byte 0x0000e264
	thumb_func_end sub_8081454

	thumb_func_start sub_808165C
sub_808165C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r1, _08081708
	bl sub_808300C
	ldr r4, _0808170C
	ldr r0, [r4]
	ldr r1, _08081710
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r1, _08081714
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_8083060
	ldr r0, [r4]
	ldr r1, _08081718
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _0808171C
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081720
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081724
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081728
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _0808172C
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081730
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081734
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	ldr r0, [r4]
	ldr r1, _08081738
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_80830B4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081708: .4byte gUnknown_81071E0
_0808170C: .4byte gDungeonGlobalData
_08081710: .4byte 0x00018208
_08081714: .4byte 0x00018209
_08081718: .4byte 0x0001820a
_0808171C: .4byte 0x0001820b
_08081720: .4byte 0x0001820c
_08081724: .4byte 0x0001820d
_08081728: .4byte 0x0001820e
_0808172C: .4byte 0x0001820f
_08081730: .4byte 0x00018210
_08081734: .4byte 0x00018211
_08081738: .4byte 0x00018213
	thumb_func_end sub_808165C

	thumb_func_start sub_808173C
sub_808173C:
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r4, _08081778
	ldr r0, [r4]
	ldr r1, _0808177C
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081780
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	ldr r0, [r4]
	ldr r1, _08081784
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	adds r0, r5, 0
	bl sub_8083048
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08081778: .4byte gDungeonGlobalData
_0808177C: .4byte 0x0001ced6
_08081780: .4byte 0x0001ced8
_08081784: .4byte 0x0001ceda
	thumb_func_end sub_808173C

	thumb_func_start sub_8081788
sub_8081788:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r5, 0x1
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r5, 0x2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081788

	thumb_func_start sub_80817B0
sub_80817B0:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80817B0

	thumb_func_start sub_80817C8
sub_80817C8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r1, r4, 0x2
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x14
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x16
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80817C8

	thumb_func_start sub_80817F4
sub_80817F4:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80817F4

	thumb_func_start sub_808180C
sub_808180C:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808180C

	thumb_func_start sub_8081824
sub_8081824:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8081824

	thumb_func_start sub_808183C
sub_808183C:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808183C

	thumb_func_start sub_8081854
sub_8081854:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8081854

	thumb_func_start sub_808186C
sub_808186C:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808186C

	thumb_func_start sub_8081880
sub_8081880:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8081880

	thumb_func_start sub_8081898
sub_8081898:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	ldrsh r1, [r4, r0]
	adds r0, r5, 0
	bl sub_8083048
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_808180C
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081898

	thumb_func_start sub_80818B8
sub_80818B8:
	push {lr}
	lsls r1, 24
	lsrs r1, 24
	bl sub_8083060
	pop {r0}
	bx r0
	thumb_func_end sub_80818B8

	thumb_func_start sub_80818C8
sub_80818C8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	ldrb r1, [r4]
	bl sub_8083060
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80818C8

	thumb_func_start sub_80818E4
sub_80818E4:
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
	bl sub_80830B4
	ldrh r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083030
	adds r4, 0x10
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80830D8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80818E4

	thumb_func_start sub_8081920
sub_8081920:
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
	thumb_func_end sub_8081920

	thumb_func_start sub_808193C
sub_808193C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x3]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808193C

	thumb_func_start sub_8081968
sub_8081968:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x8]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x9]
	adds r0, r5, 0
	bl sub_8083060
	ldr r1, [r4, 0x4]
	adds r0, r5, 0
	bl sub_8083078
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8081968

	thumb_func_start sub_8081994
sub_8081994:
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
	thumb_func_end sub_8081994

	thumb_func_start sub_80819B0
sub_80819B0:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	ldrb r1, [r4, 0x1]
	adds r0, r5, 0
	bl sub_8083060
	ldrb r1, [r4, 0x2]
	adds r0, r5, 0
	bl sub_8083060
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80819B0

	thumb_func_start sub_80819D4
sub_80819D4:
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
	thumb_func_end sub_80819D4

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
_08081C74: .4byte gDungeonGlobalData
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
_08081E24: .4byte gDungeonGlobalData
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
_08081FE8: .4byte gDungeonGlobalData
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
_08082050: .4byte gDungeonGlobalData
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
	bl GetMapTile_2
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
_08082254: .4byte gDungeonGlobalData
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
_08082670: .4byte gLeaderPokemon
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
_08082840: .4byte gLeaderPokemon
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
	bl GetMapTile_2
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
_080828D8: .4byte gLeaderPokemon
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
	bl GetPokemonSize
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
_080829F4: .4byte gDungeonGlobalData
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
	bl GetPokemonSize
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
_08082B2C: .4byte gDungeonGlobalData
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
	bl GetMapTile_2
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
_08082BB8: .4byte gDungeonGlobalData
_08082BBC: .4byte 0x000135cc
	thumb_func_end sub_8082B40

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

	thumb_func_start nullsub_98
nullsub_98:
	bx lr
	thumb_func_end nullsub_98

	thumb_func_start sub_808300C
sub_808300C:
	push {lr}
	movs r2, 0x8
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_808300C

	thumb_func_start sub_8083018
sub_8083018:
	push {lr}
	sub sp, 0xC
	mov r1, sp
	movs r2, 0x8
	bl sub_8082FE0
	mov r1, sp
	movs r0, 0
	strb r0, [r1, 0x8]
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_8083018

	thumb_func_start sub_8083030
sub_8083030:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083030

	thumb_func_start sub_8083048
sub_8083048:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strh r1, [r2]
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083048

	thumb_func_start sub_8083060
sub_8083060:
	push {lr}
	sub sp, 0x4
	mov r2, sp
	strb r1, [r2]
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083060

	thumb_func_start sub_8083078
sub_8083078:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8083078

	thumb_func_start sub_808308C
sub_808308C:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_808308C

	thumb_func_start sub_80830A0
sub_80830A0:
	push {lr}
	sub sp, 0x4
	str r1, [sp]
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80830A0

	thumb_func_start sub_80830B4
sub_80830B4:
	push {lr}
	sub sp, 0x4
	adds r3, r0, 0
	lsls r1, 24
	movs r2, 0
	cmp r1, 0
	beq _080830C4
	movs r2, 0xFF
_080830C4:
	mov r0, sp
	strb r2, [r0]
	adds r0, r3, 0
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FA8
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_80830B4

	thumb_func_start sub_80830D8
sub_80830D8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80830D8

	thumb_func_start sub_80830F8
sub_80830F8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0xC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80830F8

	thumb_func_start sub_808312C
sub_808312C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r2, 0x1
	bl sub_8082FA8
	adds r4, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FA8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_808312C

	thumb_func_start sub_808314C
sub_808314C:
	push {lr}
	bl sub_8082FA8
	pop {r0}
	bx r0
	thumb_func_end sub_808314C

	thumb_func_start sub_8083158
sub_8083158:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FE0
	mov r0, sp
	ldrh r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8083158

	thumb_func_start sub_8083170
sub_8083170:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x2
	bl sub_8082FE0
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8083170

	thumb_func_start sub_8083188
sub_8083188:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r0, [r0]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_8083188

	thumb_func_start sub_80831A0
sub_80831A0:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831A0

	thumb_func_start sub_80831B4
sub_80831B4:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831B4

	thumb_func_start sub_80831C8
sub_80831C8:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x4
	bl sub_8082FE0
	ldr r0, [sp]
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831C8

	thumb_func_start sub_80831DC
sub_80831DC:
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r2, 0x1
	bl sub_8082FE0
	mov r0, sp
	ldrb r1, [r0]
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_80831DC

	thumb_func_start sub_80831F8
sub_80831F8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
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
	thumb_func_end sub_80831F8

	thumb_func_start sub_8083220
sub_8083220:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	str r0, [r4]
	str r0, [r4, 0x4]
	str r0, [r4, 0x8]
	str r0, [r4, 0xC]
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0x4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_8082FE0
	adds r4, 0xC
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_8082FE0
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8083220

	thumb_func_start sub_8083260
sub_8083260:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
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
	thumb_func_end sub_8083260

	.align 2, 0
