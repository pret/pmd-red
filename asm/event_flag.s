	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start ResetScriptVarArray
ResetScriptVarArray:
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _08001584
	cmp r6, r0
	bgt _0800158C
	lsls r1, r6, 4
	ldr r0, _08001588
	b _08001590
	.align 2, 0
_08001584: .4byte 0x000003ff
_08001588: .4byte gScriptVarInfo
_0800158C:
	lsls r1, r6, 4
	ldr r0, _08001598
_08001590:
	adds r5, r1, r0
	movs r4, 0
	b _080015B0
	.align 2, 0
_08001598: .4byte 0x080b2d30
_0800159C:
	movs r0, 0xA
	ldrsh r3, [r5, r0]
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl SetScriptVarArrayValue
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080015B0:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _0800159C
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ResetScriptVarArray

	thumb_func_start ClearScriptVarArray
ClearScriptVarArray:
	push {r4-r7,lr}
	adds r7, r0, 0
	lsls r1, 16
	asrs r6, r1, 16
	ldr r0, _080015D4
	cmp r6, r0
	bgt _080015DC
	lsls r1, r6, 4
	ldr r0, _080015D8
	b _080015E0
	.align 2, 0
_080015D4: .4byte 0x000003ff
_080015D8: .4byte gScriptVarInfo
_080015DC:
	lsls r1, r6, 4
	ldr r0, _080015E8
_080015E0:
	adds r5, r1, r0
	movs r4, 0
	b _080015FE
	.align 2, 0
_080015E8: .4byte 0x080b2d30
_080015EC:
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	movs r3, 0
	bl SetScriptVarArrayValue
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080015FE:
	movs r1, 0x8
	ldrsh r0, [r5, r1]
	cmp r4, r0
	blt _080015EC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ClearScriptVarArray

	thumb_func_start GetScriptVarRef
GetScriptVarRef:
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	lsls r2, 16
	asrs r1, r2, 16
	ldr r0, _08001630
	cmp r1, r0
	bgt _0800163C
	lsls r1, 4
	ldr r0, _08001634
	adds r1, r0
	str r1, [r3]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	ldr r1, _08001638
	adds r0, r1
	b _0800164C
	.align 2, 0
_08001630: .4byte 0x000003ff
_08001634: .4byte gScriptVarInfo
_08001638: .4byte gScriptVarBuffer
_0800163C:
	lsls r1, 4
	ldr r0, _08001654
	adds r1, r0
	str r1, [r3]
	movs r2, 0x4
	ldrsh r0, [r1, r2]
	lsls r0, 2
	adds r0, r4, r0
_0800164C:
	str r0, [r3, 0x4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001654: .4byte 0x080b2d30
	thumb_func_end GetScriptVarRef

	thumb_func_start GetScriptVarValue
GetScriptVarValue:
	push {r4,lr}
	sub sp, 0x8
	adds r2, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	mov r0, sp
	adds r1, r2, 0
	adds r2, r4, 0
	bl GetScriptVarRef
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _0800167C
	b _08001778
_0800167C:
	lsls r0, 2
	ldr r1, _08001688
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001688: .4byte _0800168C
	.align 2, 0
_0800168C:
	.4byte _080016AC
	.4byte _080016C2
	.4byte _080016C8
	.4byte _080016D2
	.4byte _080016D8
	.4byte _080016E0
	.4byte _080016C2
	.4byte _080016E6
_080016AC:
	ldr r0, [sp]
	movs r1, 0x6
	ldrsh r0, [r0, r1]
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	ands r1, r0
	b _0800173E
_080016C2:
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	b _0800177A
_080016C8:
	ldr r0, [sp, 0x4]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	b _0800177A
_080016D2:
	ldr r0, [sp, 0x4]
	ldrh r0, [r0]
	b _0800177A
_080016D8:
	ldr r0, [sp, 0x4]
	movs r1, 0
	ldrsh r0, [r0, r1]
	b _0800177A
_080016E0:
	ldr r0, [sp, 0x4]
	ldr r0, [r0]
	b _0800177A
_080016E6:
	adds r0, r4, 0
	subs r0, 0x17
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _08001778
	lsls r0, 2
	ldr r1, _080016FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080016FC: .4byte _08001700
	.align 2, 0
_08001700:
	.4byte _08001734
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001778
	.4byte _08001746
	.4byte _0800174C
	.4byte _08001754
	.4byte _08001764
_08001734:
	bl GetScriptMode
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
_0800173E:
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _0800177A
_08001746:
	bl GetFriendSum_808D480
	b _0800177A
_0800174C:
	movs r0, 0
	bl GetUnitSum_808D544
	b _0800177A
_08001754:
	ldr r0, _08001760
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	b _0800176C
	.align 2, 0
_08001760: .4byte gTeamInventoryRef
_08001764:
	ldr r0, _08001774
	ldr r0, [r0]
	movs r1, 0x99
	lsls r1, 2
_0800176C:
	adds r0, r1
	ldr r0, [r0]
	b _0800177A
	.align 2, 0
_08001774: .4byte gTeamInventoryRef
_08001778:
	movs r0, 0
_0800177A:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetScriptVarValue

@ https://decomp.me/scratch/5F0gW [100% - DizzyEggg]
	thumb_func_start GetScriptVarArrayValue
GetScriptVarArrayValue:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	lsls r1, 16
	asrs r5, r1, 16
	lsls r2, 16
	lsrs r4, r2, 16
	mov r0, sp
	adds r1, r3, 0
	adds r2, r5, 0
	bl GetScriptVarRef
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bls _080017AC
	b _080018CC
_080017AC:
	lsls r0, 2
	ldr r1, _080017B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080017B8: .4byte _080017BC
	.align 2, 0
_080017BC:
	.4byte _080017DC
	.4byte _08001800
	.4byte _08001808
	.4byte _08001814
	.4byte _0800181E
	.4byte _0800182A
	.4byte _08001800
	.4byte _08001834
_080017DC:
	ldr r0, [sp]
	ldrh r1, [r0, 0x6]
	adds r1, r4, r1
	lsls r1, 16
	lsrs r0, r1, 19
	ldr r2, [sp, 0x4]
	adds r2, r0
	movs r0, 0xE0
	lsls r0, 11
	ands r0, r1
	lsrs r0, 16
	movs r1, 0x80
	lsls r1, 17
	lsls r1, r0
	lsrs r1, 24
	ldrb r0, [r2]
	ands r1, r0
	b _0800188E
_08001800:
	ldr r0, [sp, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	b _080018CE
_08001808:
	ldr r0, [sp, 0x4]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	b _080018CE
_08001814:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 1
	adds r1, r0
	ldrh r0, [r1]
	b _080018CE
_0800181E:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 1
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	b _080018CE
_0800182A:
	ldr r0, [sp, 0x4]
	lsls r1, r4, 2
	adds r1, r0
	ldr r0, [r1]
	b _080018CE
_08001834:
	adds r0, r5, 0
	subs r0, 0x17
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xC
	bhi _080018CC
	lsls r0, 2
	ldr r1, _0800184C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800184C: .4byte _08001850
	.align 2, 0
_08001850:
	.4byte _08001884
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _080018CC
	.4byte _08001896
	.4byte _0800189C
	.4byte _080018A4
	.4byte _080018B8
_08001884:
	bl GetScriptMode
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
_0800188E:
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _080018CE
_08001896:
	bl GetFriendSum_808D480
	b _080018CE
_0800189C:
	movs r0, 0
	bl GetUnitSum_808D544
	b _080018CE
_080018A4:
	ldr r0, _080018B4
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	b _080018CE
	.align 2, 0
_080018B4: .4byte gTeamInventoryRef
_080018B8:
	ldr r0, _080018C8
	ldr r0, [r0]
	movs r2, 0x99
	lsls r2, 2
	adds r0, r2
	ldr r0, [r0]
	b _080018CE
	.align 2, 0
_080018C8: .4byte gTeamInventoryRef
_080018CC:
	movs r0, 0
_080018CE:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetScriptVarArrayValue

	thumb_func_start SetScriptVarValue
SetScriptVarValue:
	push {r4,r5,lr}
	sub sp, 0x8
	adds r3, r0, 0
	adds r4, r2, 0
	lsls r1, 16
	asrs r5, r1, 16
	mov r0, sp
	adds r1, r3, 0
	adds r2, r5, 0
	bl GetScriptVarRef
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _08001990
	lsls r0, 2
	ldr r1, _08001908
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001908: .4byte _0800190C
	.align 2, 0
_0800190C:
	.4byte _0800192C
	.4byte _08001958
	.4byte _08001958
	.4byte _0800195E
	.4byte _0800195E
	.4byte _08001964
	.4byte _08001958
	.4byte _08001968
_0800192C:
	ldr r0, [sp]
	movs r2, 0x6
	ldrsh r1, [r0, r2]
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r3, r0, 24
	cmp r4, 0
	beq _0800194A
	ldr r2, [sp, 0x4]
	ldrb r1, [r2]
	adds r0, r3, 0
	orrs r0, r1
	strb r0, [r2]
	b _08001990
_0800194A:
	ldr r2, [sp, 0x4]
	ldrb r1, [r2]
	adds r0, r3, 0
	orrs r0, r1
	eors r0, r3
	strb r0, [r2]
	b _08001990
_08001958:
	ldr r0, [sp, 0x4]
	strb r4, [r0]
	b _08001990
_0800195E:
	ldr r0, [sp, 0x4]
	strh r4, [r0]
	b _08001990
_08001964:
	ldr r0, [sp, 0x4]
	b _0800198E
_08001968:
	cmp r5, 0x22
	beq _08001972
	cmp r5, 0x23
	beq _08001984
	b _08001990
_08001972:
	ldr r0, _08001980
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	adds r0, r1
	b _0800198E
	.align 2, 0
_08001980: .4byte gTeamInventoryRef
_08001984:
	ldr r0, _08001998
	ldr r0, [r0]
	movs r2, 0x99
	lsls r2, 2
	adds r0, r2
_0800198E:
	str r4, [r0]
_08001990:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001998: .4byte gTeamInventoryRef
	thumb_func_end SetScriptVarValue

	thumb_func_start SetScriptVarArrayValue
SetScriptVarArrayValue:
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	mov r0, sp
	adds r1, r4, 0
	adds r2, r7, 0
	bl GetScriptVarRef
	ldr r0, [sp]
	ldrh r0, [r0]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _08001A68
	lsls r0, 2
	ldr r1, _080019D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080019D0: .4byte _080019D4
	.align 2, 0
_080019D4:
	.4byte _080019F4
	.4byte _08001A2C
	.4byte _08001A2C
	.4byte _08001A34
	.4byte _08001A34
	.4byte _08001A3E
	.4byte _08001A2C
	.4byte _08001A44
_080019F4:
	ldr r0, [sp]
	ldrh r0, [r0, 0x6]
	adds r0, r5, r0
	lsls r0, 16
	lsrs r2, r0, 19
	ldr r1, [sp, 0x4]
	adds r3, r1, r2
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	lsrs r1, 16
	movs r0, 0x80
	lsls r0, 17
	lsls r0, r1
	lsrs r2, r0, 24
	cmp r6, 0
	beq _08001A20
	ldrb r1, [r3]
	adds r0, r2, 0
	orrs r0, r1
	strb r0, [r3]
	b _08001A68
_08001A20:
	ldrb r1, [r3]
	adds r0, r2, 0
	orrs r0, r1
	eors r0, r2
	strb r0, [r3]
	b _08001A68
_08001A2C:
	ldr r0, [sp, 0x4]
	adds r0, r5
	strb r6, [r0]
	b _08001A68
_08001A34:
	ldr r1, [sp, 0x4]
	lsls r0, r5, 1
	adds r0, r1
	strh r6, [r0]
	b _08001A68
_08001A3E:
	ldr r1, [sp, 0x4]
	lsls r0, r5, 2
	b _08001A64
_08001A44:
	cmp r7, 0x22
	beq _08001A4E
	cmp r7, 0x23
	beq _08001A5C
	b _08001A68
_08001A4E:
	ldr r0, _08001A58
	ldr r0, [r0]
	movs r1, 0x98
	lsls r1, 2
	b _08001A64
	.align 2, 0
_08001A58: .4byte gTeamInventoryRef
_08001A5C:
	ldr r0, _08001A70
	ldr r0, [r0]
	movs r1, 0x99
	lsls r1, 2
_08001A64:
	adds r0, r1
	str r6, [r0]
_08001A68:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001A70: .4byte gTeamInventoryRef
	thumb_func_end SetScriptVarArrayValue

	.align 2, 0 @ Don't pad with nop.
