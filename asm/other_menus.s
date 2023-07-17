        #include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8037810
sub_8037810:
	push {r4-r6,lr}
	ldr r6, _080378FC
	ldr r0, [r6]
	movs r5, 0xDE
	lsls r5, 1
	adds r0, r5
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	movs r4, 0xE2
	lsls r4, 1
	adds r0, r4
	movs r1, 0
	movs r2, 0x8
	bl MemoryFill8
	ldr r0, [r6]
	adds r5, r0, r5
	movs r1, 0
	movs r2, 0
	str r1, [r5]
	str r2, [r5, 0x4]
	adds r4, r0, r4
	str r1, [r4]
	str r2, [r4, 0x4]
	movs r2, 0xE6
	lsls r2, 1
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xFE
	lsls r3, 1
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0x8B
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x97
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xA3
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xC5
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0x30
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0xAF
	lsls r2, 2
	adds r0, r2
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r3, 0xD1
	lsls r3, 2
	adds r0, r3
	movs r1, 0
	movs r2, 0x58
	bl MemoryFill8
	ldr r0, [r6]
	movs r1, 0xE7
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r0, [r6]
	movs r2, 0x8A
	lsls r2, 3
	adds r0, r2
	movs r1, 0
	movs r2, 0xB4
	bl MemoryFill8
	ldr r2, [r6]
	movs r3, 0xB1
	lsls r3, 2
	adds r0, r2, r3
	movs r1, 0
	strh r1, [r0]
	adds r3, 0x88
	adds r0, r2, r3
	strh r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080378FC: .4byte gUnknown_203B35C
	thumb_func_end sub_8037810

	thumb_func_start sub_8037900
sub_8037900:
	push {r4,lr}
	sub sp, 0x10
	ldr r4, _08037928
	ldr r0, [r4]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	bl sub_8035CC0
	ldr r0, [r4]
	ldr r0, [r0]
	cmp r0, 0xA
	bls _0803791E
	b _08037A14
_0803791E:
	lsls r0, 2
	ldr r1, _0803792C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037928: .4byte gUnknown_203B35C
_0803792C: .4byte _08037930
	.align 2, 0
_08037930:
	.4byte _0803795C
	.4byte _0803795C
	.4byte _0803797C
	.4byte _0803797C
	.4byte _0803799C
	.4byte _0803799C
	.4byte _080379BC
	.4byte _080379BC
	.4byte _08037A14
	.4byte _080379F0
	.4byte _080379F0
_0803795C:
	ldr r0, _08037970
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037974
	ldr r2, _08037978
	b _080379CE
	.align 2, 0
_08037970: .4byte gUnknown_203B35C
_08037974: .4byte gUnknown_80E6554
_08037978: .4byte gUnknown_80E656C
_0803797C:
	ldr r0, _08037990
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037994
	ldr r2, _08037998
	b _080379CE
	.align 2, 0
_08037990: .4byte gUnknown_203B35C
_08037994: .4byte gUnknown_80E6554
_08037998: .4byte gUnknown_80E65D8
_0803799C:
	ldr r0, _080379B0
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379B4
	ldr r2, _080379B8
	b _080379CE
	.align 2, 0
_080379B0: .4byte gUnknown_203B35C
_080379B4: .4byte gUnknown_80E6554
_080379B8: .4byte gUnknown_80E661C
_080379BC:
	ldr r0, _080379E4
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _080379E8
	ldr r2, _080379EC
_080379CE:
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
	b _08037A14
	.align 2, 0
_080379E4: .4byte gUnknown_203B35C
_080379E8: .4byte gUnknown_80E6554
_080379EC: .4byte gUnknown_80E665C
_080379F0:
	ldr r0, _08037A38
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x1C
	movs r2, 0xAE
	lsls r2, 1
	adds r1, r2
	ldr r3, _08037A3C
	ldr r2, _08037A40
	str r2, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	movs r2, 0x6
	str r2, [sp, 0x8]
	str r4, [sp, 0xC]
	movs r2, 0
	bl SetMenuItems
_08037A14:
	ldr r4, _08037A38
	ldr r0, [r4]
	adds r0, 0x1C
	movs r1, 0
	movs r2, 0x1
	bl sub_8035CF4
	bl sub_80373C4
	ldr r0, [r4]
	adds r0, 0x1C
	bl sub_80130A8
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037A38: .4byte gUnknown_203B35C
_08037A3C: .4byte gUnknown_80E6554
_08037A40: .4byte gUnknown_80E667C
	thumb_func_end sub_8037900

	thumb_func_start nullsub_202
nullsub_202:
	bx lr
	thumb_func_end nullsub_202

	thumb_func_start sub_8037A48
sub_8037A48:
	push {r4-r6,lr}
	sub sp, 0x28
	movs r6, 0x1
	movs r0, 0
	mov r1, sp
	movs r2, 0x14
	bl sub_800D670
	add r4, sp, 0x14
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x14
	bl sub_800D670
	ldr r1, _08037AAC
	movs r3, 0x8
	adds r2, r1, 0
	adds r0, r2, 0x4
_08037A6C:
	str r3, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _08037A6C
	ldr r0, [sp, 0x10]
	str r0, [r2]
	ldr r0, [r4, 0x10]
	str r0, [r2, 0x4]
	ldr r5, _08037AB0
	mov r0, sp
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037A8C
	movs r0, 0x1
_08037A8C:
	lsls r0, 24
	cmp r0, 0
	bne _08037AA6
	adds r0, r4, 0
	adds r1, r5, 0
	bl strcmp
	cmp r0, 0
	beq _08037AA0
	movs r0, 0x1
_08037AA0:
	lsls r0, 24
	cmp r0, 0
	beq _08037AB4
_08037AA6:
	movs r0, 0
	b _08037B1E
	.align 2, 0
_08037AAC: .4byte gUnknown_202EC40
_08037AB0: .4byte gUnknown_80E6E50
_08037AB4:
	ldr r1, [sp, 0x10]
	cmp r1, 0
	bne _08037AC0
	ldr r0, [r4, 0x10]
	cmp r0, 0x1
	beq _08037B1C
_08037AC0:
	cmp r1, 0x1
	bne _08037ACA
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _08037B1C
_08037ACA:
	cmp r1, 0x2
	bne _08037AD4
	ldr r0, [r4, 0x10]
	cmp r0, 0x3
	beq _08037B1C
_08037AD4:
	cmp r1, 0x3
	bne _08037ADE
	ldr r0, [r4, 0x10]
	cmp r0, 0x2
	beq _08037B1C
_08037ADE:
	cmp r1, 0x9
	bne _08037AE8
	ldr r0, [r4, 0x10]
	cmp r0, 0xA
	beq _08037B1C
_08037AE8:
	cmp r1, 0xA
	bne _08037AF2
	ldr r0, [r4, 0x10]
	cmp r0, 0x9
	beq _08037B1C
_08037AF2:
	cmp r1, 0x4
	bne _08037AFC
	ldr r0, [r4, 0x10]
	cmp r0, 0x5
	beq _08037B1C
_08037AFC:
	cmp r1, 0x5
	bne _08037B06
	ldr r0, [r4, 0x10]
	cmp r0, 0x4
	beq _08037B1C
_08037B06:
	cmp r1, 0x6
	bne _08037B10
	ldr r0, [r4, 0x10]
	cmp r0, 0x7
	beq _08037B1C
_08037B10:
	cmp r1, 0x7
	bne _08037B1A
	ldr r0, [r4, 0x10]
	cmp r0, 0x6
	beq _08037B1C
_08037B1A:
	movs r6, 0
_08037B1C:
	adds r0, r6, 0
_08037B1E:
	add sp, 0x28
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8037A48

	thumb_func_start sub_8037B28
sub_8037B28:
	push {r4,r5,lr}
	sub sp, 0x14
	adds r4, r0, 0
	movs r5, 0
	bl sub_800D414
	ldr r0, _08037B58
	str r5, [r0]
	ldr r5, _08037B5C
	mov r0, sp
	movs r1, 0
	movs r2, 0x14
	bl MemoryFill8
	mov r0, sp
	adds r1, r5, 0
	bl strcpy
	str r4, [sp, 0x10]
	mov r0, sp
	movs r1, 0x14
	bl sub_800D59C
	b _08037B7A
	.align 2, 0
_08037B58: .4byte gUnknown_202EC38
_08037B5C: .4byte gUnknown_80E6E50
_08037B60:
	cmp r5, 0x3
	beq _08037BCC
	cmp r5, 0x4
	beq _08037BD8
	cmp r5, 0x5
	beq _08037BF0
	ldr r2, _08037BC0
	ldr r1, [r2]
	ldr r0, _08037BC4
	cmp r1, r0
	bgt _08037BE4
	adds r0, r1, 0x1
	str r0, [r2]
_08037B7A:
	movs r4, 0
_08037B7C:
	bl sub_80373C4
	bl sub_8012AE8
	cmp r0, 0x3
	bgt _08037B8C
	cmp r0, 0x2
	bge _08037BF0
_08037B8C:
	adds r4, 0x1
	cmp r4, 0
	ble _08037B7C
	bl sub_800D33C
	adds r5, r0, 0
	bl sub_800D570
	cmp r5, 0x2
	bne _08037B60
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08037BFC
	bl sub_8037A48
	lsls r0, 24
	cmp r0, 0
	bne _08037BC8
	movs r4, 0x4
	bl sub_800D520
	bl sub_800D510
	b _08037C06
	.align 2, 0
_08037BC0: .4byte gUnknown_202EC38
_08037BC4: .4byte 0x00000707
_08037BC8:
	movs r4, 0
	b _08037C06
_08037BCC:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x2
	b _08037C08
_08037BD8:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x3
	b _08037C08
_08037BE4:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08037C08
_08037BF0:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08037C08
_08037BFC:
	movs r4, 0x5
	bl sub_800D520
	bl sub_800D510
_08037C06:
	adds r0, r4, 0
_08037C08:
	add sp, 0x14
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8037B28

	thumb_func_start sub_8037C10
sub_8037C10:
	push {lr}
	lsls r0, 24
	cmp r0, 0
	beq _08037C24
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037C38
	b _08037C2E
_08037C24:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	beq _08037C38
_08037C2E:
	ldr r0, _08037C34
	ldr r0, [r0, 0x4]
	b _08037C3C
	.align 2, 0
_08037C34: .4byte gUnknown_202EC40
_08037C38:
	ldr r0, _08037C40
	ldr r0, [r0]
_08037C3C:
	pop {r1}
	bx r1
	.align 2, 0
_08037C40: .4byte gUnknown_202EC40
	thumb_func_end sub_8037C10

	thumb_func_start sub_8037C44
sub_8037C44:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	movs r4, 0
_08037C4C:
	adds r0, r4, 0
	bl sub_800D68C
	adds r4, 0x1
	cmp r4, 0x1
	ble _08037C4C
	cmp r6, 0xA
	bhi _08037CBE
	lsls r0, r6, 2
	ldr r1, _08037C68
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037C68: .4byte _08037C6C
	.align 2, 0
_08037C6C:
	.4byte _08037C98
	.4byte _08037C98
	.4byte _08037CA2
	.4byte _08037CA2
	.4byte _08037CAC
	.4byte _08037CAC
	.4byte _08037CA2
	.4byte _08037CA2
	.4byte _08037CBE
	.4byte _08037CB6
	.4byte _08037CB6
_08037C98:
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_800D59C
	b _08037CBE
_08037CA2:
	adds r0, r5, 0
	movs r1, 0x30
	bl sub_800D59C
	b _08037CBE
_08037CAC:
	adds r0, r5, 0
	movs r1, 0x88
	bl sub_800D59C
	b _08037CBE
_08037CB6:
	adds r0, r5, 0
	movs r1, 0xB4
	bl sub_800D59C
_08037CBE:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8037C44

	thumb_func_start sub_8037CC4
sub_8037CC4:
	push {r4,lr}
	adds r3, r1, 0
	adds r4, r2, 0
	cmp r0, 0xA
	bhi _08037D5E
	lsls r0, 2
	ldr r1, _08037CD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037CD8: .4byte _08037CDC
	.align 2, 0
_08037CDC:
	.4byte _08037D08
	.4byte _08037D08
	.4byte _08037D1E
	.4byte _08037D1E
	.4byte _08037D34
	.4byte _08037D34
	.4byte _08037D1E
	.4byte _08037D1E
	.4byte _08037D5E
	.4byte _08037D4A
	.4byte _08037D4A
_08037D08:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x8
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x8
	bl sub_800D670
	b _08037D5E
_08037D1E:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x30
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x30
	bl sub_800D670
	b _08037D5E
_08037D34:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0x88
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x88
	bl sub_800D670
	b _08037D5E
_08037D4A:
	movs r0, 0
	adds r1, r3, 0
	movs r2, 0xB4
	bl sub_800D670
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0xB4
	bl sub_800D670
_08037D5E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8037CC4

	thumb_func_start sub_8037D64
sub_8037D64:
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r4, 0
	ldr r0, _08037D80
	str r4, [r0]
	bl sub_800D494
	adds r0, r5, 0
	adds r1, r6, 0
	bl sub_8037C44
	b _08037D96
	.align 2, 0
_08037D80: .4byte gUnknown_202EC48
_08037D84:
	subs r0, r4, 0x3
	cmp r0, 0x2
	bls _08037DBC
	ldr r1, _08037DB8
	ldr r0, [r1]
	cmp r0, 0x63
	bgt _08037DC8
	adds r0, 0x1
	str r0, [r1]
_08037D96:
	bl sub_80373C4
	bl sub_800D33C
	adds r4, r0, 0
	bl sub_800D570
	cmp r4, 0x2
	bne _08037D84
	bl sub_800D600
	lsls r0, 24
	cmp r0, 0
	beq _08037DD4
	movs r4, 0
	b _08037DDE
	.align 2, 0
_08037DB8: .4byte gUnknown_202EC48
_08037DBC:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0x1
	b _08037DEA
_08037DC8:
	bl sub_800D520
	bl sub_800D510
	movs r0, 0xF
	b _08037DEA
_08037DD4:
	bl sub_800D520
	bl sub_800D510
	movs r4, 0x5
_08037DDE:
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_8037CC4
	adds r0, r4, 0
_08037DEA:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8037D64

	thumb_func_start sub_8037DF0
sub_8037DF0:
	push {r4,lr}
	sub sp, 0x8
	movs r4, 0
	movs r0, 0
	mov r1, sp
	movs r2, 0x4
	bl sub_800D670
	add r1, sp, 0x4
	movs r0, 0x1
	movs r2, 0x4
	bl sub_800D670
	ldr r0, [sp]
	cmp r0, 0
	bne _08037E16
	ldr r0, [sp, 0x4]
	cmp r0, 0
	beq _08037E2C
_08037E16:
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037E24
	ldr r4, [sp, 0x4]
	b _08037E26
_08037E24:
	ldr r4, [sp]
_08037E26:
	cmp r4, 0
	bne _08037E2C
	movs r4, 0xE
_08037E2C:
	adds r0, r4, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8037DF0

	thumb_func_start sub_8037E38
sub_8037E38:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r5, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r4, r6, 0
	cmp r0, 0
	bne _08037E4C
	adds r4, r5, 0
_08037E4C:
	bl sub_800D588
	lsls r0, 24
	adds r3, r5, 0
	cmp r0, 0
	bne _08037E5A
	adds r3, r6, 0
_08037E5A:
	ldrb r0, [r4]
	ldrb r1, [r3]
	cmp r0, r1
	bne _08037E70
	ldr r0, _08037E6C
	ldr r1, [r0]
	ldrb r0, [r4]
	b _08037E76
	.align 2, 0
_08037E6C: .4byte gTeamInventory_203B460
_08037E70:
	ldr r0, _08037E8C
	ldr r1, [r0]
	ldrb r0, [r3]
_08037E76:
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r2, [r1]
	ldr r0, [r3, 0x4]
	adds r2, r0
	strh r2, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037E8C: .4byte gTeamInventory_203B460
	thumb_func_end sub_8037E38

	thumb_func_start sub_8037E90
sub_8037E90:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037EA2
	adds r4, r5, 0
_08037EA2:
	movs r0, 0x2
	strb r0, [r4]
	adds r0, r4, 0
	bl sub_80951BC
	ldr r0, [r4, 0x10]
	bl sub_8095274
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8037E90

	thumb_func_start nullsub_53
nullsub_53:
	bx lr
	thumb_func_end nullsub_53

	thumb_func_start sub_8037EBC
sub_8037EBC:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	adds r5, r4, 0
	cmp r0, 0
	bne _08037ED0
	adds r5, r6, 0
_08037ED0:
	ldr r1, [r5, 0x10]
	movs r0, 0x1
	bl GetMailIndex
	lsls r0, 24
	lsrs r0, 24
	bl GetMailatIndex
	adds r4, r0, 0
	adds r1, r4, 0
	adds r0, r5, 0
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	ldm r0!, {r2,r3,r6}
	stm r1!, {r2,r3,r6}
	movs r0, 0x5
	strb r0, [r4]
	adds r0, r4, 0
	bl sub_80951FC
	movs r0, 0x7
	strb r0, [r4]
	movs r0, 0x38
	ldrsh r6, [r5, r0]
	cmp r6, 0
	beq _08037F30
	ldr r4, _08037F2C
	ldr r0, [r4]
	ldr r1, [r5, 0x10]
	stm r0!, {r1}
	adds r1, r5, 0
	adds r1, 0x30
	movs r2, 0x58
	bl memcpy
	ldr r1, [r4]
	movs r0, 0x42
	strb r0, [r1, 0x8]
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	b _08037F40
	.align 2, 0
_08037F2C: .4byte gUnknown_203B484
_08037F30:
	ldr r4, _08037F48
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x5C
	bl MemoryFill8
	ldr r0, [r4]
	strh r6, [r0, 0xC]
_08037F40:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037F48: .4byte gUnknown_203B484
	thumb_func_end sub_8037EBC

	thumb_func_start sub_8037F4C
sub_8037F4C:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl sub_800D588
	lsls r0, 24
	cmp r0, 0
	bne _08037F5E
	adds r4, r5, 0
_08037F5E:
	ldr r1, [r4, 0x10]
	movs r0, 0x4
	bl GetMailIndex
	lsls r0, 24
	lsrs r0, 24
	bl GetMailatIndex
	adds r2, r0, 0
	adds r1, r4, 0
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	ldm r1!, {r3-r5}
	stm r2!, {r3-r5}
	movs r1, 0x6
	strb r1, [r0]
	bl GetMainMenu
	cmp r0, 0
	beq _08037F96
	adds r1, r0, 0
	adds r1, 0x3A
	movs r0, 0x1
	strb r0, [r1]
_08037F96:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8037F4C

	thumb_func_start sub_8037F9C
sub_8037F9C:
	push {lr}
	adds r3, r1, 0
	cmp r0, 0xA
	bhi _08038010
	lsls r0, 2
	ldr r1, _08037FB0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037FB0: .4byte _08037FB4
	.align 2, 0
_08037FB4:
	.4byte _08037FE0
	.4byte _08037FE0
	.4byte _08038010
	.4byte _08037FF4
	.4byte _08038010
	.4byte _08037FFE
	.4byte _08038010
	.4byte _08037FEA
	.4byte _08038010
	.4byte _08038010
	.4byte _08038008
_08037FE0:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037E38
	b _08038010
_08037FEA:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037F4C
	b _08038010
_08037FF4:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037E90
	b _08038010
_08037FFE:
	adds r0, r3, 0
	adds r1, r2, 0
	bl sub_8037EBC
	b _08038010
_08038008:
	adds r0, r3, 0
	adds r1, r2, 0
	bl nullsub_53
_08038010:
	pop {r0}
	bx r0
	thumb_func_end sub_8037F9C

        .align 2,0
