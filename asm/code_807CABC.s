	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text
  
	thumb_func_start sub_807CABC
sub_807CABC:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r6, 0
	b _0807CADC
_0807CAC6:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807CB0A
	ldr r1, _0807CB38
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0807CB0A
	adds r6, 0x1
_0807CADC:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8070828
	cmp r6, r0
	bge _0807CB0A
	ldr r5, [r4, 0x70]
	adds r0, r5, 0
	adds r0, 0x48
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8055A00
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	bne _0807CAC6
_0807CB0A:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_8057588
	adds r0, r4, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807CB2A
	ldr r0, [r4, 0x70]
	adds r0, 0x48
	ldrb r1, [r0]
	adds r0, r4, 0
	bl sub_806A9B4
_0807CB2A:
	adds r0, r4, 0
	bl sub_806A1B0
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807CB38: .4byte 0x00000159
	thumb_func_end sub_807CABC

	thumb_func_start sub_807CB3C
sub_807CB3C:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x30
	adds r6, r0, 0
	ldr r7, [r6, 0x70]
	movs r1, 0
	movs r2, 0x15
	bl sub_8044D90
	adds r2, r0, 0
	ldr r5, [r2]
	ldrb r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0807CB80
	ldr r0, _0807CB78
	adds r1, r2, 0
	bl sub_8045BF8
	ldr r0, _0807CB7C
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _0807CD54
	.align 2, 0
_0807CB78: .4byte gUnknown_202DE58
_0807CB7C: .4byte gUnknown_80FE3E8
_0807CB80:
	add r0, sp, 0x8
	adds r1, r7, 0
	adds r1, 0x44
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	ldm r1!, {r2-r4}
	stm r0!, {r2-r4}
	bl IsBossBattle
	lsls r0, 24
	cmp r0, 0
	beq _0807CBAC
	ldr r0, _0807CBA8
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	movs r4, 0x1
	b _0807CCDE
	.align 2, 0
_0807CBA8: .4byte gPtrMysteriousPowerPreventedUseMessage
_0807CBAC:
	movs r0, 0x1
	mov r8, r0
	add r4, sp, 0x20
	lsls r5, 8
	lsrs r0, r5, 24
	bl GetItemMove
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl InitPokemonMove
	ldrb r0, [r7, 0x7]
	mov r10, r4
	mov r9, r5
	cmp r0, 0
	bne _0807CC08
	ldr r1, _0807CC20
	ldr r0, [sp, 0x28]
	ands r0, r1
	mov r1, r8
	orrs r0, r1
	str r0, [sp, 0x28]
	movs r0, 0xA
	add r4, sp, 0x28
	str r0, [r4, 0x4]
	movs r3, 0x8C
	lsls r3, 1
	adds r2, r7, r3
	adds r0, r4, 0
	adds r1, r6, 0
	bl FindMoveTarget
	ldrb r0, [r4]
	cmp r0, 0
	beq _0807CC08
	ldrb r1, [r4, 0x1]
	movs r0, 0x7
	ands r0, r1
	adds r1, r7, 0
	adds r1, 0x46
	strb r0, [r1]
	adds r0, r6, 0
	bl TargetTileInFront
_0807CC08:
	adds r0, r7, 0
	adds r0, 0xBC
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807CC2C
	ldr r0, _0807CC24
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807CC28
	b _0807CC3C
	.align 2, 0
_0807CC20: .4byte 0xffffff00
_0807CC24: .4byte gAvailablePokemonNames
_0807CC28: .4byte gUnknown_80FC714
_0807CC2C:
	cmp r0, 0x7
	bne _0807CC50
	ldr r0, _0807CC48
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807CC4C
_0807CC3C:
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	b _0807CCDC
	.align 2, 0
_0807CC48: .4byte gAvailablePokemonNames
_0807CC4C: .4byte gUnknown_80FC718
_0807CC50:
	adds r0, r7, 0
	adds r0, 0xAC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0807CC72
	ldr r0, _0807CCB8
	adds r1, r6, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807CCBC
	ldr r1, [r0]
	adds r0, r6, 0
	bl SendMessage
	movs r4, 0
	mov r8, r4
_0807CC72:
	mov r0, r8
	cmp r0, 0
	beq _0807CCDC
	mov r5, r9
	lsrs r0, r5, 24
	cmp r0, 0xB6
	beq _0807CC84
	cmp r0, 0xBF
	bne _0807CCC0
_0807CC84:
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x7A
	bl sub_8044DF0
	mov r2, r10
	ldrb r1, [r2]
	movs r0, 0x8
	movs r4, 0
	orrs r0, r1
	add r3, sp, 0x20
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0xA
	strb r0, [r3, 0x4]
	lsrs r2, r5, 24
	str r4, [sp]
	str r3, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl sub_8055FA0
	b _0807CCDE
	.align 2, 0
_0807CCB8: .4byte gAvailablePokemonNames
_0807CCBC: .4byte gUnknown_80FC6A8
_0807CCC0:
	mov r3, r9
	lsrs r2, r3, 24
	movs r0, 0
	str r0, [sp]
	mov r4, r10
	str r4, [sp, 0x4]
	adds r0, r6, 0
	movs r1, 0
	movs r3, 0
	bl sub_8055FA0
	lsls r0, 24
	lsrs r4, r0, 24
	b _0807CCDE
_0807CCDC:
	movs r4, 0
_0807CCDE:
	adds r0, r6, 0
	bl EntityExists
	lsls r0, 24
	cmp r0, 0
	beq _0807CD38
	cmp r4, 0
	beq _0807CCF8
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x7A
	bl sub_8044DF0
_0807CCF8:
	adds r0, r6, 0
	bl sub_8071DA4
	adds r0, r6, 0
	movs r1, 0x8
	bl sub_806CE68
	ldrb r0, [r7, 0x7]
	cmp r0, 0
	beq _0807CD18
	adds r0, r6, 0x4
	bl sub_804AC20
	movs r0, 0
	bl sub_807EC28
_0807CD18:
	adds r0, r6, 0
	bl sub_806A5B8
	ldr r0, _0807CD30
	ldr r0, [r0]
	ldr r1, _0807CD34
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_8075900
	b _0807CD44
	.align 2, 0
_0807CD30: .4byte gDungeonGlobalData
_0807CD34: .4byte 0x00003a08
_0807CD38:
	cmp r4, 0
	beq _0807CD44
	add r0, sp, 0x8
	movs r1, 0
	bl sub_8044D40
_0807CD44:
	bl sub_8044B28
	lsls r0, 24
	cmp r0, 0
	bne _0807CD54
	adds r0, r6, 0
	bl sub_806A1B0
_0807CD54:
	add sp, 0x30
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_807CB3C

	.align 2, 0