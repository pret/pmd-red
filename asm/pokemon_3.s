	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_808F798
sub_808F798:
	push {r4-r6,lr}
	sub sp, 0xA4
	adds r4, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x58
	bl memcpy
	mov r0, sp
	movs r1, 0x8
	ldrsh r6, [r0, r1]
	add r0, sp, 0x58
	mov r1, sp
	ldrb r2, [r1, 0x3]
	adds r1, r5, 0
	bl GetPokemonLevelData
	ldr r0, [sp, 0x58]
	str r0, [sp, 0x1C]
	movs r0, 0
	strh r0, [r4]
	mov r0, sp
	strh r5, [r0, 0x8]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	bne _0808F7DA
	mov r0, sp
	mov r1, sp
	ldrb r1, [r1, 0x3]
	strb r1, [r0, 0xC]
	b _0808F7EA
_0808F7DA:
	mov r0, sp
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _0808F7EA
	mov r0, sp
	mov r1, sp
	ldrb r1, [r1, 0x3]
	strb r1, [r0, 0x10]
_0808F7EA:
	add r4, sp, 0x64
	adds r0, r6, 0
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	bl CopyStringtoBuffer
	movs r2, 0
	b _0808F800
_0808F7FE:
	adds r2, 0x1
_0808F800:
	cmp r2, 0x9
	bgt _0808F816
	adds r1, r4, r2
	add r0, sp, 0x4C
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _0808F82E
	cmp r1, 0
	bne _0808F7FE
_0808F816:
	movs r0, 0x1
	cmp r0, 0
	beq _0808F82E
	add r4, sp, 0x4C
	adds r0, r5, 0
	bl GetMonSpecies
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0xA
	bl BoundedCopyStringtoBuffer
_0808F82E:
	mov r0, sp
	bl sub_808D1DC
	add sp, 0xA4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_808F798

	thumb_func_start sub_808F83C
sub_808F83C:
	movs r0, 0
	strb r0, [r2]
	bx lr
	thumb_func_end sub_808F83C

	thumb_func_start CreatePokemonInfoTabScreen
CreatePokemonInfoTabScreen:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r5, r0, 0
	adds r4, r1, 0
	mov r10, r2
	str r3, [sp, 0x2C]
	ldr r0, [sp, 0x50]
	bl sub_80073B8
	ldr r0, _0808F880
	mov r1, r10
	adds r1, 0x2
	movs r2, 0x14
	bl strncpy
	movs r0, 0x20
	mov r9, r0
	cmp r5, 0x5
	bls _0808F874
	b _0808FED6
_0808F874:
	lsls r0, r5, 2
	ldr r1, _0808F884
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808F880: .4byte gAvailablePokemonNames
_0808F884: .4byte _0808F888
	.align 2, 0
_0808F888:
	.4byte _0808FED6
	.4byte _0808FBF4
	.4byte _0808F8A0
	.4byte _0808FB44
	.4byte _0808FCB0
	.4byte _0808FDB0
_0808F8A0:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r2, _0808F998
	movs r5, 0
	str r5, [sp]
	movs r1, 0
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	ldr r4, _0808F99C
	mov r1, r10
	ldr r0, [r1, 0x2C]
	str r0, [r4]
	ldr r0, [r1, 0x30]
	str r0, [r4, 0x4]
	ldr r0, _0808F9A0
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r2, 0xA
	add r9, r2
	ldr r0, _0808F9A4
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r3, 0xA
	add r9, r3
	mov r0, r10
	ldr r2, [r0, 0x2C]
	cmp r2, 0x63
	bgt _0808F914
	movs r3, 0
	ldrsh r1, [r0, r3]
	adds r2, 0x1
	add r0, sp, 0x8
	bl GetPokemonLevelData
	ldr r0, [sp, 0x8]
	mov r2, r10
	ldr r1, [r2, 0x30]
	subs r0, r1
	str r0, [r4]
	ldr r0, _0808F9A8
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
_0808F914:
	movs r3, 0xC
	add r9, r3
	mov r1, r10
	ldr r0, [r1, 0x24]
	str r0, [r4]
	ldr r0, [r1, 0x28]
	str r0, [r4, 0x4]
	ldr r0, _0808F9AC
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r2, 0xA
	add r9, r2
	ldr r0, _0808F9B0
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	ldr r0, _0808F9B4
	ldr r2, [r0]
	mov r0, r10
	adds r0, 0x34
	ldrb r3, [r0]
	str r3, [r4]
	mov r1, r10
	adds r1, 0x39
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808F964
	adds r0, r3, r0
	str r0, [r4]
	ldr r0, _0808F9B8
	ldr r2, [r0]
_0808F964:
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	mov r1, r10
	adds r1, 0x3B
	ldrb r3, [r1]
	cmp r3, 0
	beq _0808F9C0
	mov r0, r10
	adds r0, 0x36
	ldrb r0, [r0]
	adds r1, r3, 0
	adds r0, r1
	str r0, [r4]
	ldr r0, _0808F9BC
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	b _0808F9D8
	.align 2, 0
_0808F998: .4byte gUnknown_8107754
_0808F99C: .4byte gFormatData_202DE30
_0808F9A0: .4byte gLevel810DD6C_Ptr
_0808F9A4: .4byte gExpPts810DD9C_Ptr
_0808F9A8: .4byte gUnknown_810DDB8
_0808F9AC: .4byte gUnknown_810DDD0
_0808F9B0: .4byte gUnknown_810DDE4
_0808F9B4: .4byte gUnknown_810DE0C
_0808F9B8: .4byte gUnknown_810DE20
_0808F9BC: .4byte gUnknown_810DE4C
_0808F9C0:
	mov r0, r10
	adds r0, 0x36
	ldrb r0, [r0]
	str r0, [r4]
	ldr r0, _0808FA44
	ldr r2, [r0]
	str r3, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
_0808F9D8:
	movs r3, 0xA
	add r9, r3
	ldr r0, _0808FA48
	ldr r2, [r0]
	movs r5, 0
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	ldr r0, _0808FA4C
	ldr r2, [r0]
	ldr r4, _0808FA50
	mov r0, r10
	adds r0, 0x35
	ldrb r3, [r0]
	str r3, [r4]
	mov r1, r10
	adds r1, 0x3A
	ldrb r0, [r1]
	cmp r0, 0
	beq _0808FA0E
	adds r0, r3, r0
	str r0, [r4]
	ldr r0, _0808FA54
	ldr r2, [r0]
_0808FA0E:
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	mov r1, r10
	adds r1, 0x3C
	ldrb r3, [r1]
	cmp r3, 0
	beq _0808FA5C
	mov r0, r10
	adds r0, 0x37
	ldrb r0, [r0]
	adds r1, r3, 0
	adds r0, r1
	str r0, [r4]
	ldr r0, _0808FA58
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	b _0808FA74
	.align 2, 0
_0808FA44: .4byte gUnknown_810DE38
_0808FA48: .4byte gUnknown_810DDFC
_0808FA4C: .4byte gUnknown_810DE24
_0808FA50: .4byte gFormatData_202DE30
_0808FA54: .4byte gUnknown_810DE28
_0808FA58: .4byte gUnknown_810DE54
_0808FA5C:
	mov r0, r10
	adds r0, 0x37
	ldrb r0, [r0]
	str r0, [r4]
	ldr r0, _0808FA94
	ldr r2, [r0]
	str r3, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
_0808FA74:
	movs r0, 0xA
	add r9, r0
	mov r2, r10
	adds r2, 0x20
	ldrb r1, [r2]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0808FA9C
	ldr r0, _0808FA98
	adds r1, r2, 0
	movs r2, 0
	bl sub_8090E14
	b _0808FAA6
	.align 2, 0
_0808FA94: .4byte gUnknown_810DE50
_0808FA98: .4byte gFormatItems
_0808FA9C:
	ldr r0, _0808FB24
	ldr r1, _0808FB28
	ldr r1, [r1]
	bl strcpy
_0808FAA6:
	ldr r0, _0808FB2C
	ldr r2, [r0]
	movs r4, 0
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r1, 0xC
	add r9, r1
	ldr r1, _0808FB30
	mov r2, r10
	movs r3, 0x3E
	ldrsh r0, [r2, r3]
	str r0, [r1]
	movs r1, 0x3E
	ldrsh r0, [r2, r1]
	movs r1, 0xA
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0808FADA
	movs r0, 0
_0808FADA:
	cmp r0, 0x62
	ble _0808FAE0
	movs r0, 0x63
_0808FAE0:
	ldr r1, _0808FB34
	lsls r0, 2
	adds r0, r1
	ldr r5, _0808FB38
	ldr r1, [r0]
	adds r0, r5, 0
	bl strcpy
	ldr r0, _0808FB3C
	ldr r2, [r0]
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r2, 0xA
	add r9, r2
	mov r0, r10
	adds r0, 0x38
	ldrb r4, [r0]
	cmp r4, 0
	beq _0808FB10
	b _0808FED6
_0808FB10:
	adds r0, 0x1C
	ldrb r1, [r0]
	adds r0, r5, 0
	bl CopyTacticsNameToBuffer
	ldr r0, _0808FB40
	ldr r2, [r0]
	str r4, [sp]
	b _0808FECC
	.align 2, 0
_0808FB24: .4byte gFormatItems
_0808FB28: .4byte gUnknown_810DE58
_0808FB2C: .4byte gUnknown_810DE6C
_0808FB30: .4byte gFormatData_202DE30
_0808FB34: .4byte gUnknown_8115718
_0808FB38: .4byte gAvailablePokemonNames
_0808FB3C: .4byte gUnknown_810DE80
_0808FB40: .4byte gUnknown_810DE98
_0808FB44:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r2, _0808FBE8
	movs r4, 0
	str r4, [sp]
	movs r1, 0
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	ldr r2, _0808FBEC
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	mov r3, r10
	ldrb r0, [r3, 0x16]
	bl GetFormattedTypeString
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x38
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	mov r1, r10
	ldrb r0, [r1, 0x17]
	cmp r0, 0
	beq _0808FB94
	bl GetFormattedTypeString
	adds r2, r0, 0
	str r4, [sp]
	movs r0, 0x60
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
_0808FB94:
	movs r2, 0xC
	add r9, r2
	ldr r2, _0808FBF0
	str r4, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r3, 0xC
	add r9, r3
	mov r1, r10
	ldrb r0, [r1, 0x18]
	bl GetAbilityDescription
	adds r2, r0, 0
	str r4, [sp]
	movs r5, 0xB
	str r5, [sp, 0x4]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8015034
	movs r2, 0x21
	add r9, r2
	mov r3, r10
	ldrb r0, [r3, 0x19]
	cmp r0, 0
	bne _0808FBD2
	b _0808FED6
_0808FBD2:
	bl GetAbilityDescription
	adds r2, r0, 0
	str r4, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl sub_8015034
	b _0808FED6
	.align 2, 0
_0808FBE8: .4byte gUnknown_810775C
_0808FBEC: .4byte gUnknown_8107768
_0808FBF0: .4byte gUnknown_8107770
_0808FBF4:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r1, _0808FC34
	ldr r2, [r1]
	movs r1, 0
	str r1, [sp]
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	mov r0, r10
	adds r0, 0x56
	movs r1, 0
	ldrsh r0, [r0, r1]
	subs r5, r0, 0x1
	movs r2, 0xC
	negs r2, r2
	add r9, r2
	movs r7, 0
	ldr r6, [sp, 0x2C]
	adds r6, 0xC
	adds r1, r6, 0
	movs r2, 0
	ldr r0, [sp, 0x2C]
	adds r0, 0x2C
_0808FC24:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge _0808FC24
	movs r3, 0
	mov r8, r3
	b _0808FC88
	.align 2, 0
_0808FC34: .4byte gUnknown_810DD58
_0808FC38:
	mov r0, r10
	adds r0, 0x58
	adds r4, r0, r5
	ldrb r0, [r4]
	cmp r0, 0
	beq _0808FC78
	movs r7, 0x1
	ldr r0, _0808FCA0
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, _0808FCA4
	ldr r1, [r1]
	movs r2, 0x50
	bl strncpy
	ldr r2, _0808FCA8
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	mov r0, r8
	cmp r0, 0
	ble _0808FC78
	subs r0, 0x1
	lsls r0, 2
	adds r0, r6, r0
	ldrb r1, [r4]
	str r1, [r0]
_0808FC78:
	movs r1, 0x1
	add r8, r1
	adds r5, 0x1
	movs r2, 0xC
	add r9, r2
	mov r3, r8
	cmp r3, 0x9
	bgt _0808FC90
_0808FC88:
	cmp r5, 0
	blt _0808FC78
	cmp r5, 0xB
	ble _0808FC38
_0808FC90:
	cmp r7, 0
	beq _0808FC96
	b _0808FED6
_0808FC96:
	ldr r0, _0808FCAC
	ldr r2, [r0]
	str r7, [sp]
	b _0808FD98
	.align 2, 0
_0808FCA0: .4byte gStatusNames
_0808FCA4: .4byte gUnknown_202DEA8
_0808FCA8: .4byte gUnknown_8107784
_0808FCAC: .4byte gUnknown_810DF78
_0808FCB0:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r1, _0808FCF8
	ldr r2, [r1]
	movs r1, 0
	str r1, [sp]
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	add r4, sp, 0x14
	mov r0, r10
	movs r2, 0x3E
	ldrsh r1, [r0, r2]
	adds r0, r4, 0
	bl GetNumAvailableIQSkills
	mov r0, r10
	adds r0, 0x40
	movs r3, 0
	ldrsh r0, [r0, r3]
	subs r7, r0, 0x1
	mov r1, r9
	subs r1, 0xC
	movs r2, 0
	ldr r0, [sp, 0x2C]
	adds r0, 0x8
_0808FCE4:
	strb r2, [r0]
	subs r0, 0x1
	ldr r3, [sp, 0x2C]
	cmp r0, r3
	bge _0808FCE4
	mov r9, r1
	movs r4, 0
	mov r8, r4
	b _0808FD84
	.align 2, 0
_0808FCF8: .4byte gIQSkill810DD68_Ptr
_0808FCFC:
	mov r5, sp
	adds r5, r7
	adds r5, 0x14
	ldrb r0, [r5]
	cmp r0, 0
	beq _0808FD74
	movs r4, 0x1
	bl GetIQSkillName
	adds r1, r0, 0
	ldr r6, _0808FD3C
	adds r0, r6, 0
	movs r2, 0x50
	bl strncpy
	mov r0, r10
	adds r0, 0x50
	adds r1, r4, 0
	ldrb r5, [r5]
	lsls r1, r5
	bl IsIQSkillSet
	lsls r0, 24
	cmp r0, 0
	beq _0808FD44
	adds r0, r6, 0
	subs r0, 0x50
	ldr r1, _0808FD40
	bl strcpy
	b _0808FD4E
	.align 2, 0
_0808FD3C: .4byte gUnknown_202DEA8
_0808FD40: .4byte gUnknown_8107788
_0808FD44:
	adds r0, r6, 0
	subs r0, 0x50
	ldr r1, _0808FDA4
	bl strcpy
_0808FD4E:
	mov r0, r8
	cmp r0, 0
	ble _0808FD64
	subs r0, 0x1
	ldr r1, [sp, 0x2C]
	adds r0, r1, r0
	mov r1, sp
	adds r1, r7
	adds r1, 0x14
	ldrb r1, [r1]
	strb r1, [r0]
_0808FD64:
	ldr r2, _0808FDA8
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
_0808FD74:
	movs r2, 0x1
	add r8, r2
	adds r7, 0x1
	movs r3, 0xC
	add r9, r3
	mov r0, r8
	cmp r0, 0x9
	bgt _0808FD8C
_0808FD84:
	cmp r7, 0
	blt _0808FD74
	cmp r7, 0x17
	ble _0808FCFC
_0808FD8C:
	cmp r4, 0
	beq _0808FD92
	b _0808FED6
_0808FD92:
	ldr r0, _0808FDAC
	ldr r2, [r0]
	str r4, [sp]
_0808FD98:
	movs r0, 0xC
	movs r1, 0x20
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	b _0808FED6
	.align 2, 0
_0808FDA4: .4byte gUnknown_810778C
_0808FDA8: .4byte gUnknown_8107790
_0808FDAC: .4byte gUnknown_810DF84
_0808FDB0:
	lsls r0, r4, 3
	adds r0, 0x10
	ldr r2, _0808FEEC
	movs r5, 0
	str r5, [sp]
	movs r1, 0
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	ldr r6, _0808FEF0
	mov r2, r10
	movs r3, 0
	ldrsh r1, [r2, r3]
	adds r0, r6, 0
	bl CopyMonsterNametoBuffer
	ldr r1, _0808FEF4
	mov r2, r10
	movs r3, 0
	ldrsh r0, [r2, r3]
	str r0, [r1]
	ldr r0, _0808FEF8
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r0, 0xA
	add r9, r0
	mov r1, r10
	movs r2, 0
	ldrsh r0, [r1, r2]
	bl GetFriendArea
	lsls r0, 24
	lsrs r0, 24
	bl GetFriendAreaName
	adds r1, r0, 0
	ldr r4, _0808FEFC
	adds r0, r4, 0
	movs r2, 0x50
	bl strncpy
	ldr r0, _0808FF00
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r3, 0xA
	add r9, r3
	ldr r0, _0808FF04
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r0, 0xD
	add r9, r0
	ldr r0, _0808FF08
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r1, 0xA
	add r9, r1
	mov r1, r10
	adds r1, 0x1C
	adds r0, r4, 0
	bl PrintYellowDungeonNametoBuffer
	ldr r0, _0808FF0C
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r2, 0xD
	add r9, r2
	mov r3, r10
	movs r1, 0
	ldrsh r0, [r3, r1]
	bl GetCategoryString
	adds r1, r0, 0
	adds r0, r6, 0
	movs r2, 0x14
	bl strncpy
	ldr r0, _0808FF10
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r2, 0xD
	add r9, r2
	ldr r4, _0808FF14
	mov r3, r10
	movs r1, 0
	ldrsh r0, [r3, r1]
	bl GetBodySize
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4
	ldr r1, [r0]
	adds r0, r6, 0
	bl strcpy
	ldr r0, _0808FF18
	ldr r2, [r0]
	str r5, [sp]
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
	movs r2, 0xD
	add r9, r2
	ldr r1, _0808FF1C
	mov r0, r10
	adds r0, 0x4C
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	str r5, [sp]
_0808FECC:
	movs r0, 0x4
	mov r1, r9
	ldr r3, [sp, 0x50]
	bl PrintFormatStringOnWindow
_0808FED6:
	ldr r0, [sp, 0x50]
	bl sub_80073E0
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FEEC: .4byte gUnknown_8107798
_0808FEF0: .4byte gAvailablePokemonNames
_0808FEF4: .4byte gFormatData_202DE30
_0808FEF8: .4byte gUnknown_810DEB4
_0808FEFC: .4byte gFormatItems
_0808FF00: .4byte gUnknown_810DEC8
_0808FF04: .4byte gUnknown_810DEDC
_0808FF08: .4byte gUnknown_810DFB4
_0808FF0C: .4byte gUnknown_810DFC8
_0808FF10: .4byte gUnknown_810DEF4
_0808FF14: .4byte gUnknown_810E02C
_0808FF18: .4byte gUnknown_810DF98
_0808FF1C: .4byte gEvolutionStrings
	thumb_func_end CreatePokemonInfoTabScreen

	thumb_func_start sub_808FF20
sub_808FF20:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	adds r0, r5, 0x2
	movs r2, 0
	bl PrintColoredPokeNameToBuffer
	ldrh r0, [r6, 0x8]
	strh r0, [r5]
	movs r1, 0x16
	ldrsh r0, [r6, r1]
	str r0, [r5, 0x24]
	str r0, [r5, 0x28]
	ldrb r0, [r6, 0x3]
	str r0, [r5, 0x2C]
	ldr r0, [r6, 0x1C]
	str r0, [r5, 0x30]
	movs r4, 0
_0808FF50:
	adds r1, r5, 0
	adds r1, 0x34
	adds r1, r4
	adds r0, r6, 0
	adds r0, 0x18
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, 0
	adds r1, 0x36
	adds r1, r4
	adds r0, r6, 0
	adds r0, 0x1A
	adds r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	movs r7, 0x8
	ldrsh r0, [r6, r7]
	adds r1, r4, 0
	bl GetPokemonType
	adds r1, r5, 0
	adds r1, 0x16
	adds r1, r4
	strb r0, [r1]
	movs r1, 0x8
	ldrsh r0, [r6, r1]
	adds r1, r4, 0
	bl GetPokemonAbility
	adds r1, r5, 0
	adds r1, 0x18
	adds r1, r4
	strb r0, [r1]
	adds r4, 0x1
	cmp r4, 0x1
	ble _0808FF50
	ldrb r2, [r6, 0x2]
	adds r1, r5, 0
	adds r1, 0x38
	movs r0, 0
	strb r2, [r1]
	adds r2, r5, 0
	adds r2, 0x39
	strb r0, [r2]
	adds r3, r5, 0
	adds r3, 0x3A
	strb r0, [r3]
	movs r7, 0x3B
	adds r7, r5
	mov r12, r7
	strb r0, [r7]
	movs r1, 0x3C
	adds r1, r5
	mov r9, r1
	strb r0, [r1]
	adds r0, r6, 0
	adds r0, 0x28
	ldrb r1, [r0]
	adds r4, r0, 0
	cmp r1, 0
	beq _08090026
	cmp r1, 0x13
	bne _0808FFDA
	ldr r0, _08090060
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r0, r7
	strb r0, [r2]
_0808FFDA:
	ldrb r1, [r4]
	cmp r1, 0x21
	bne _0808FFEA
	ldr r0, _08090064
	ldrb r0, [r0]
	ldrb r7, [r3]
	adds r0, r7
	strb r0, [r3]
_0808FFEA:
	cmp r1, 0x2B
	bne _0808FFFE
	ldr r0, _08090068
	ldrb r0, [r0]
	ldrb r7, [r2]
	adds r1, r0, r7
	strb r1, [r2]
	ldrb r1, [r3]
	adds r0, r1
	strb r0, [r3]
_0808FFFE:
	ldrb r0, [r4]
	cmp r0, 0x1E
	bne _08090012
	ldr r0, _0809006C
	ldrb r0, [r0]
	mov r2, r12
	ldrb r2, [r2]
	adds r0, r2
	mov r7, r12
	strb r0, [r7]
_08090012:
	ldrb r0, [r4]
	cmp r0, 0x22
	bne _08090026
	ldr r0, _08090070
	ldrb r0, [r0]
	mov r1, r9
	ldrb r1, [r1]
	adds r0, r1
	mov r2, r9
	strb r0, [r2]
_08090026:
	adds r0, r6, 0
	adds r0, 0x24
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x54
	strb r1, [r0]
	subs r0, 0x34
	adds r1, r4, 0
	bl HeldItemToSlot
	ldrh r0, [r6, 0x14]
	strh r0, [r5, 0x3E]
	ldr r0, [r6, 0x4]
	str r0, [r5, 0x1C]
	ldr r0, [r6, 0xC]
	str r0, [r5, 0x44]
	ldr r0, [r6, 0x10]
	str r0, [r5, 0x48]
	ldr r0, [r6, 0x20]
	str r0, [r5, 0x50]
	mov r7, r8
	cmp r7, 0
	beq _08090074
	adds r0, r6, 0
	bl sub_808F700
	adds r1, r5, 0
	adds r1, 0x4C
	b _0809007A
	.align 2, 0
_08090060: .4byte gUnknown_810AC60
_08090064: .4byte gUnknown_810AC62
_08090068: .4byte gUnknown_810AC68
_0809006C: .4byte gUnknown_810AC64
_08090070: .4byte gUnknown_810AC66
_08090074:
	adds r1, r5, 0
	adds r1, 0x4C
	movs r0, 0x3
_0809007A:
	strb r0, [r1]
	adds r1, r5, 0
	adds r1, 0x58
	movs r2, 0
	adds r0, r5, 0
	adds r0, 0x63
_08090086:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _08090086
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_808FF20

        .align 2,0
