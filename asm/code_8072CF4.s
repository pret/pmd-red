	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_8072CF4
sub_8072CF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	movs r0, 0x1
	bl sub_804178C
	ldr r1, _08072D4C
	movs r0, 0x1
	strb r0, [r1]
	ldr r6, [r4, 0x70]
	adds r0, r6, 0
	adds r0, 0xFC
	movs r1, 0
	strb r1, [r0]
	subs r0, 0x9
	strb r1, [r0]
	ldr r0, _08072D50
	ldr r0, [r0]
	adds r0, 0xB8
	str r4, [r0]
	ldr r2, _08072D54
	adds r0, r6, 0
	adds r0, 0x44
	ldrh r0, [r0]
	lsls r1, r0, 1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _08072D64
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	beq _08072D58
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_805EFB4
	b _08072D64
	.align 2, 0
_08072D4C: .4byte gUnknown_203B434
_08072D50: .4byte gDungeon
_08072D54: .4byte gUnknown_80F58F4
_08072D58:
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_8075BA4
_08072D64:
	adds r0, r4, 0
	movs r1, 0
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	beq _08072D86
	adds r0, r4, 0
	movs r1, 0x1
	bl IsCharging
	lsls r0, 24
	cmp r0, 0
	beq _08072D86
	adds r0, r4, 0
	bl sub_8079764
_08072D86:
	movs r7, 0x1
	movs r5, 0xFB
	movs r0, 0x8C
	lsls r0, 1
	adds r2, r6, r0
	movs r3, 0x3
_08072D92:
	ldrb r1, [r2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08072DA4
	ldrb r1, [r2, 0x1]
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r2, 0x1]
_08072DA4:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08072D92
	adds r0, r4, 0
	movs r1, 0
	bl IsNotAttacking
	lsls r0, 24
	cmp r0, 0
	bne _08072E08
	adds r0, r4, 0
	bl UseAttack
	lsls r0, 24
	cmp r0, 0
	beq _08072DF0
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	beq _08072DD2
	b _080732D4
_08072DD2:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _08072DE0
	b _080732D4
_08072DE0:
	ldr r0, _08072DEC
	ldrb r0, [r0]
	cmp r0, 0
	beq _08072DF0
	movs r0, 0x1
	b _080732D6
	.align 2, 0
_08072DEC: .4byte gUnknown_202F32D
_08072DF0:
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _08072DFC
	movs r0, 0xA
	bl sub_8052740
_08072DFC:
	adds r0, r4, 0
	bl sub_806A1E8
	movs r0, 0xA
	bl sub_803E46C
_08072E08:
	adds r0, r6, 0
	adds r0, 0x44
	ldrh r1, [r0]
	adds r5, r0, 0
	cmp r1, 0x1
	bls _08072E26
	cmp r1, 0x4
	beq _08072E26
	cmp r1, 0x2
	beq _08072E26
	movs r2, 0xA4
	lsls r2, 1
	adds r1, r6, r2
	movs r0, 0x1
	strb r0, [r1]
_08072E26:
	movs r3, 0
	mov r10, r3
	movs r7, 0xA5
	lsls r7, 1
	adds r0, r6, r7
	mov r1, r10
	strb r1, [r0]
	ldr r0, _08072E50
	strb r1, [r0]
	ldr r0, _08072E54
	strb r1, [r0]
	ldrh r0, [r5]
	subs r0, 0x2
	cmp r0, 0x3F
	bls _08072E46
	b _080731B4
_08072E46:
	lsls r0, 2
	ldr r1, _08072E58
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072E50: .4byte gUnknown_202F221
_08072E54: .4byte gUnknown_202F222
_08072E58: .4byte _08072E5C
	.align 2, 0
_08072E5C:
	.4byte _08072F5C
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _08073104
	.4byte _080730A4
	.4byte _0807310C
	.4byte _0807311C
	.4byte _080731B4
	.4byte _08073094
	.4byte _08073094
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _08073094
	.4byte _0807314C
	.4byte _08073154
	.4byte _0807303E
	.4byte _080731B4
	.4byte _0807315C
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _08073186
	.4byte _0807318E
	.4byte _08073170
	.4byte _08073046
	.4byte _0807311C
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _0807309C
	.4byte _08073162
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080731B4
	.4byte _080730AC
	.4byte _080730B4
	.4byte _080730C4
	.4byte _08073196
	.4byte _08073114
	.4byte _080730E0
	.4byte _080730CC
	.4byte _080730D6
	.4byte _080730BC
	.4byte _0807317E
	.4byte _080731B4
	.4byte _0807311C
_08072F5C:
	adds r0, r6, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _08072F76
	cmp r0, 0x7
	beq _08072F76
	cmp r0, 0x5
	beq _08072F76
	cmp r0, 0x3
	beq _08072F76
	cmp r0, 0x4
	bne _08072F84
_08072F76:
	movs r0, 0
	strh r0, [r5]
	ldr r2, _08072F80
	adds r1, r6, r2
	b _08072FDA
	.align 2, 0
_08072F80: .4byte 0x00000147
_08072F84:
	movs r3, 0
	mov r9, r3
	ldr r1, _08072FE0
	adds r2, r6, 0
	adds r2, 0x46
	ldrb r3, [r2]
	lsls r0, r3, 2
	adds r0, r1
	ldrh r1, [r0]
	ldrh r7, [r4, 0x4]
	adds r1, r7
	lsls r1, 16
	ldrh r0, [r0, 0x2]
	ldrh r7, [r4, 0x6]
	adds r0, r7
	lsls r0, 16
	lsrs r1, 16
	mov r8, r1
	orrs r1, r0
	mov r8, r1
	ldrh r1, [r6]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	adds r7, r2, 0
	cmp r0, 0
	bne _08072FCC
	adds r0, r4, 0
	adds r1, r3, 0
	bl CanMoveInDirection
	lsls r0, 24
	cmp r0, 0
	bne _08072FCC
	movs r2, 0x1
	mov r9, r2
_08072FCC:
	mov r3, r9
	cmp r3, 0
	beq _08072FE8
	movs r0, 0
	strh r0, [r5]
	ldr r7, _08072FE4
	adds r1, r6, r7
_08072FDA:
	movs r0, 0x1
	strb r0, [r1]
	b _080731B8
	.align 2, 0
_08072FE0: .4byte gAdjacentTileOffsets
_08072FE4: .4byte 0x00000147
_08072FE8:
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	ldrh r0, [r4, 0x4]
	orrs r0, r1
	str r0, [sp]
	mov r0, r8
	lsls r1, r0, 16
	asrs r1, 16
	asrs r2, r0, 16
	adds r0, r4, 0
	movs r3, 0
	bl sub_80694C0
	ldrb r1, [r7]
	adds r0, r4, 0
	mov r2, sp
	bl sub_8074FB0
	adds r0, r4, 0
	movs r1, 0xD
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08073038
	adds r0, r6, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08073038
	adds r0, r4, 0
	movs r1, 0x9
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	bne _08073038
	adds r0, r4, 0x4
	bl sub_804AE08
_08073038:
	movs r1, 0x1
	mov r10, r1
	b _080731B8
_0807303E:
	adds r0, r4, 0
	bl sub_807CABC
	b _080731B8
_08073046:
	ldr r0, _08073064
	ldr r1, [r0]
	ldr r2, _08073068
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x15
	bne _08073074
	ldr r3, _0807306C
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _08073074
	ldr r0, _08073070
	b _080731A2
	.align 2, 0
_08073064: .4byte gDungeon
_08073068: .4byte 0x00000644
_0807306C: .4byte 0x000037fe
_08073070: .4byte gUnknown_80FA5B4
_08073074:
	bl sub_804267C
	ldr r0, _0807308C
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x2]
	ldr r1, _08073090
	adds r0, r6, 0
	adds r0, 0x46
	ldrb r0, [r0]
	strb r0, [r1]
	b _080731B8
	.align 2, 0
_0807308C: .4byte gDungeon
_08073090: .4byte gUnknown_202F32C
_08073094:
	adds r0, r4, 0
	bl sub_8067110
	b _080731B8
_0807309C:
	adds r0, r4, 0
	bl sub_807CB3C
	b _080731B8
_080730A4:
	adds r0, r4, 0
	bl sub_8066744
	b _080731B8
_080730AC:
	adds r0, r4, 0
	bl sub_80668D0
	b _080731B8
_080730B4:
	adds r0, r4, 0
	bl sub_8066AC0
	b _080731B8
_080730BC:
	adds r0, r4, 0
	bl sub_8066BD4
	b _080731B8
_080730C4:
	adds r0, r4, 0
	bl sub_8066CF0
	b _080731B8
_080730CC:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806675C
	b _080731B8
_080730D6:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_806684C
	b _080731B8
_080730E0:
	ldr r0, _080730FC
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0xBC
	adds r0, r6, 0
	adds r0, 0x48
	ldrb r0, [r0]
	lsls r0, 2
	ldr r7, _08073100
	adds r1, r7
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _080731B8
	.align 2, 0
_080730FC: .4byte gDungeon
_08073100: .4byte 0x0001357c
_08073104:
	adds r0, r4, 0
	bl sub_8066D04
	b _080731B8
_0807310C:
	adds r0, r4, 0
	bl sub_8066E14
	b _080731B8
_08073114:
	adds r0, r4, 0
	bl sub_8066FA4
	b _080731B8
_0807311C:
	adds r0, r6, 0
	bl ToolboxEnabled
	lsls r0, 24
	cmp r0, 0
	beq _08073136
	adds r0, r4, 0
	bl nullsub_95
	adds r0, r4, 0
	bl sub_80671A0
	b _080731B8
_08073136:
	ldr r0, _08073144
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08073148
	b _080731A2
	.align 2, 0
_08073144: .4byte gAvailablePokemonNames
_08073148: .4byte gUnknown_80FE6D4
_0807314C:
	adds r0, r4, 0
	bl sub_8067510
	b _080731B8
_08073154:
	adds r0, r4, 0
	bl sub_8067884
	b _080731B8
_0807315C:
	movs r1, 0xB0
	lsls r1, 1
	b _08073164
_08073162:
	ldr r1, _0807316C
_08073164:
	adds r0, r4, 0
	bl sub_8067904
	b _080731B8
	.align 2, 0
_0807316C: .4byte 0x00000163
_08073170:
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807FE9C
	b _080731B8
_0807317E:
	adds r0, r4, 0
	bl sub_8073D08
	b _080731B8
_08073186:
	adds r0, r4, 0
	bl sub_8073CF0
	b _080731B8
_0807318E:
	adds r0, r4, 0
	bl sub_8073CFC
	b _080731B8
_08073196:
	ldr r0, _080731AC
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _080731B0
_080731A2:
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
	b _080731B8
	.align 2, 0
_080731AC: .4byte gAvailablePokemonNames
_080731B0: .4byte gUnknown_80FE478
_080731B4:
	movs r0, 0x1
	strh r0, [r5]
_080731B8:
	adds r0, r4, 0
	bl sub_807FD84
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _080731CC
	b _080732D4
_080731CC:
	ldr r0, [r4, 0x70]
	movs r2, 0xA5
	lsls r2, 1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	bne _080731E2
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_8079764
_080731E2:
	movs r0, 0
	bl sub_8041888
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
	bl sub_8085140
	ldr r3, _080732E8
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, 0
	beq _08073242
	movs r5, 0
	strb r5, [r1]
	movs r7, 0x8C
	lsls r7, 1
	adds r2, r6, r7
	movs r0, 0x1
	mov r12, r0
	movs r7, 0x10
	movs r3, 0x3
_08073214:
	ldrb r1, [r2]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	beq _0807322C
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0807322C
	movs r0, 0
	strb r0, [r2, 0x4]
	movs r5, 0x1
_0807322C:
	adds r2, 0x8
	subs r3, 0x1
	cmp r3, 0
	bge _08073214
	cmp r5, 0
	beq _08073242
	ldr r0, _080732EC
	ldr r1, [r0]
	adds r0, r4, 0
	bl SendMessage
_08073242:
	bl sub_807360C
	bl sub_8044B84
	lsls r0, 24
	cmp r0, 0
	bne _08073264
	bl sub_807348C
	bl sub_80732F0
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
_08073264:
	mov r1, r10
	cmp r1, 0
	beq _08073270
	adds r0, r4, 0
	bl sub_8075818
_08073270:
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
	bl sub_8044B84
	lsls r0, 24
	cmp r0, 0
	bne _0807328A
	bl sub_8046D20
_0807328A:
	movs r0, 0
	bl sub_8041888
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _080732D4
	movs r2, 0xA2
	lsls r2, 1
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080732D4
	mov r3, r10
	cmp r3, 0
	bne _080732D4
	adds r1, r4, 0x4
	adds r0, r4, 0
	bl sub_80706A4
	lsls r0, 24
	cmp r0, 0
	beq _080732C8
	adds r0, r4, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0
	bl sub_807D148
_080732C8:
	adds r0, r4, 0
	bl sub_8074094
	adds r0, r4, 0
	bl sub_8071DA4
_080732D4:
	movs r0, 0
_080732D6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080732E8: .4byte 0x0000014b
_080732EC: .4byte gUnknown_80FD2CC
	thumb_func_end sub_8072CF4

	thumb_func_start sub_80732F0
sub_80732F0:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	movs r4, 0
_080732FE:
	movs r5, 0
	ldr r0, _0807335C
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _08073360
	adds r0, r2
	adds r0, r1
	ldr r0, [r0]
	mov r8, r0
	bl EntityExists
	lsls r0, 24
	adds r4, 0x1
	str r4, [sp, 0x10]
	cmp r0, 0
	bne _08073320
	b _08073472
_08073320:
	mov r0, r8
	ldr r7, [r0, 0x70]
	movs r1, 0xB2
	lsls r1, 1
	adds r4, r7, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _08073332
	b _08073472
_08073332:
	adds r2, r0, 0
	mov r9, r2
	mov r0, r8
	movs r1, 0x1
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	bne _0807336E
	mov r0, r8
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _08073364
	ldrb r0, [r4]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r4]
	b _08073472
	.align 2, 0
_0807335C: .4byte gDungeon
_08073360: .4byte 0x000135cc
_08073364:
	adds r0, r7, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08073378
_0807336E:
	ldrb r0, [r4]
	movs r1, 0xFF
	orrs r0, r1
	strb r0, [r4]
	b _08073472
_08073378:
	movs r0, 0x4
	bl DungeonRandInt
	adds r3, r0, 0
	movs r4, 0
_08073382:
	lsls r0, r3, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r2, r7, r0
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073448
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	ldr r1, [sp, 0x8]
	lsrs r0, r1, 16
	cmp r0, 0x8A
	beq _08073448
	adds r1, r0, 0
	ldr r0, _08073434
	cmp r1, r0
	beq _08073448
	movs r6, 0
	movs r0, 0x46
	adds r0, r7
	mov r10, r0
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r7, r1
_080733BC:
	lsls r0, r6, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r5, r7, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080733F4
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	bne _080733DE
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080733F4
_080733DE:
	ldrh r0, [r4, 0x2]
	cmp r0, 0xE3
	bne _080733F4
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x1
	bl CanMonsterUseMove
	lsls r0, 24
	cmp r0, 0
	bne _08073440
_080733F4:
	adds r4, 0x8
	adds r6, 0x1
	cmp r6, 0x3
	ble _080733BC
_080733FC:
	ldr r0, _08073438
	mov r1, r8
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807343C
	ldr r1, [r0]
	mov r0, r8
	bl SendMessage
	movs r0, 0x7
	mov r1, r9
	ands r1, r0
	movs r0, 0
	mov r2, r10
	strb r1, [r2]
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	mov r0, r8
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8055FA0
	movs r5, 0x1
	b _08073456
	.align 2, 0
_08073434: .4byte 0x00000147
_08073438: .4byte gAvailablePokemonNames
_0807343C: .4byte gUnknown_80FCF38
_08073440:
	adds r0, r5, 0x4
	bl sub_80838EC
	b _080733FC
_08073448:
	adds r3, 0x1
	cmp r3, 0x4
	bne _08073450
	movs r3, 0
_08073450:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08073382
_08073456:
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r7, r2
	ldrb r0, [r1]
	movs r2, 0xFF
	orrs r0, r2
	strb r0, [r1]
	cmp r5, 0
	beq _08073472
	mov r0, r8
	movs r1, 0xB8
	lsls r1, 2
	bl sub_80421C0
_08073472:
	ldr r4, [sp, 0x10]
	cmp r4, 0x13
	bgt _0807347A
	b _080732FE
_0807347A:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80732F0

	thumb_func_start sub_807348C
sub_807348C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	movs r4, 0
	movs r0, 0xFF
	mov r9, r0
_0807349E:
	ldr r0, _080734E8
	ldr r0, [r0]
	lsls r1, r4, 2
	ldr r2, _080734EC
	adds r0, r2
	adds r0, r1
	ldr r7, [r0]
	adds r0, r7, 0
	bl EntityExists
	lsls r0, 24
	adds r4, 0x1
	str r4, [sp, 0x10]
	cmp r0, 0
	bne _080734BE
	b _080735E6
_080734BE:
	ldr r6, [r7, 0x70]
	ldr r0, _080734F0
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _080734CC
	b _080735E6
_080734CC:
	adds r1, r0, 0
	mov r8, r1
	adds r0, r7, 0
	movs r1, 0x1
	bl CannotAttack
	lsls r0, 24
	cmp r0, 0
	beq _080734F4
	ldrb r0, [r4]
	mov r2, r9
	orrs r0, r2
	strb r0, [r4]
	b _080735DA
	.align 2, 0
_080734E8: .4byte gDungeon
_080734EC: .4byte 0x000135cc
_080734F0: .4byte 0x00000165
_080734F4:
	adds r0, r7, 0
	bl IsSleeping
	lsls r0, 24
	cmp r0, 0
	bne _08073514
	ldrb r0, [r4]
	mov r1, r9
	orrs r0, r1
	strb r0, [r4]
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r6, r2
	ldrb r0, [r1]
	mov r2, r9
	b _080735E2
_08073514:
	adds r0, r6, 0
	adds r0, 0xEC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807354A
	ldrb r0, [r4]
	mov r1, r9
	orrs r0, r1
	strb r0, [r4]
	movs r2, 0xB2
	lsls r2, 1
	adds r1, r6, r2
	ldrb r0, [r1]
	mov r2, r9
	b _080735E2
_08073532:
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r0, r5, 0x4
	bl sub_80838EC
	adds r0, r7, 0
	adds r1, r5, 0
	bl sub_806ACE8
	b _0807359C
_0807354A:
	movs r3, 0
	movs r0, 0x46
	adds r0, r6
	mov r10, r0
	movs r1, 0x8C
	lsls r1, 1
	adds r4, r6, r1
_08073558:
	lsls r0, r3, 3
	movs r2, 0x8C
	lsls r2, 1
	adds r0, r2
	adds r5, r6, r0
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08073594
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0807357A
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08073594
_0807357A:
	ldrh r0, [r4, 0x2]
	cmp r0, 0x19
	bne _08073594
	adds r0, r7, 0
	adds r1, r5, 0
	movs r2, 0x1
	str r3, [sp, 0x14]
	bl CanMonsterUseMove
	lsls r0, 24
	ldr r3, [sp, 0x14]
	cmp r0, 0
	bne _08073532
_08073594:
	adds r4, 0x8
	adds r3, 0x1
	cmp r3, 0x3
	ble _08073558
_0807359C:
	ldr r0, _08073600
	adds r1, r7, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08073604
	ldr r1, [r0]
	adds r0, r7, 0
	bl SendMessage
	movs r0, 0x7
	mov r1, r8
	ands r1, r0
	movs r0, 0
	mov r2, r10
	strb r1, [r2]
	str r0, [sp]
	add r0, sp, 0x8
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8055FA0
	ldr r2, _08073608
	adds r1, r6, r2
	ldrb r0, [r1]
	mov r2, r9
	orrs r0, r2
	strb r0, [r1]
_080735DA:
	movs r0, 0xB2
	lsls r0, 1
	adds r1, r6, r0
	ldrb r0, [r1]
_080735E2:
	orrs r0, r2
	strb r0, [r1]
_080735E6:
	ldr r4, [sp, 0x10]
	cmp r4, 0x13
	bgt _080735EE
	b _0807349E
_080735EE:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073600: .4byte gAvailablePokemonNames
_08073604: .4byte gUnknown_80FCF50
_08073608: .4byte 0x00000165
	thumb_func_end sub_807348C

	.align 2, 0
