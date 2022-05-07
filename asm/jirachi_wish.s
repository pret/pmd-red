	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start JirachiWish
JirachiWish:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x78
	movs r0, 0x1A
	bl GetEntityFromClientType
	adds r6, r0, 0
	ldr r0, _0808B82C
	ldr r1, _0808B830
	bl CopySpeciesNametoBuffer
	ldr r4, _0808B834
	adds r0, r4, 0
	bl sub_80855E4
	adds r0, r6, 0
	bl _call_via_r4
	movs r0, 0
	bl sub_8041888
	ldr r0, [r6, 0x70]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	movs r4, 0x1
	strb r4, [r0]
	ldr r0, [r6, 0x70]
	movs r2, 0xAF
	lsls r2, 1
	adds r0, r2
	strb r1, [r0]
	adds r0, r6, 0
	movs r1, 0xE
	movs r2, 0
	bl sub_80861B8
	ldr r0, _0808B838
	bl sub_80855E4
	ldr r0, _0808B83C
	ldr r0, [r0]
	ldr r1, _0808B840
	adds r0, r1
	strb r4, [r0]
	movs r0, 0x1E
	bl sub_8083ED8
	movs r0, 0x1E
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808B844
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808B848
	bl PlaySoundEffect
	movs r0, 0x96
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl sub_80862BC
	ldr r0, _0808B84C
	bl DisplayDungeonDialogue
	movs r0, 0x79
	bl sub_8083E88
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	movs r1, 0
	bl sub_80856E0
	movs r0, 0xB5
	lsls r0, 1
	bl PlaySoundEffect
	ldr r0, _0808B850
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl SpriteLookAroundEffect
	ldr r0, _0808B854
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
_0808B690:
	ldr r4, _0808B858
_0808B692:
	movs r0, 0
	ldr r1, [r4]
	ldr r2, _0808B85C
	ldr r3, _0808B860
	bl sub_8052C68
	mov r9, r0
	cmp r0, 0
	ble _0808B692
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	mov r2, r9
	cmp r2, 0x1
	bne _0808B754
	ldr r0, _0808B864
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl JirachiWishGrantDialogue
	movs r0, 0
	add r7, sp, 0x6C
_0808B6CA:
	adds r0, 0x1
	mov r8, r0
	mov r4, sp
	movs r5, 0x8
_0808B6D2:
	adds r0, r4, 0
	movs r1, 0x69
	movs r2, 0
	bl sub_8045C28
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _0808B6D2
	movs r0, 0x3
	bl DungeonRandomCapped
	ldrh r1, [r6, 0x4]
	adds r1, r0
	subs r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	ldr r2, _0808B868
	ldr r0, [sp, 0x6C]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x6C]
	movs r0, 0x3
	bl DungeonRandomCapped
	ldrh r2, [r6, 0x6]
	adds r2, r0
	subs r2, 0x1
	lsls r2, 16
	ldr r0, _0808B86C
	ldr r1, [sp, 0x6C]
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0x6C]
	movs r2, 0
	ldrsh r0, [r7, r2]
	asrs r1, 16
	bl GetMapTile_2
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0808B744
	movs r0, 0xA6
	lsls r0, 1
	bl PlaySoundEffect
	adds r0, r7, 0
	bl sub_808BB3C
	adds r0, r6, 0
	adds r1, r7, 0
	mov r2, sp
	movs r3, 0x9
	bl sub_8046860
_0808B744:
	mov r0, r8
	cmp r0, 0x5
	ble _0808B6CA
	ldr r0, [r6, 0x70]
	ldr r2, _0808B870
	adds r1, r0, r2
	movs r0, 0
	strb r0, [r1]
_0808B754:
	mov r0, r9
	cmp r0, 0x2
	bne _0808B80A
	ldr r0, _0808B874
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl JirachiWishGrantDialogue
	movs r0, 0
	add r1, sp, 0x24
	mov r8, r1
	add r7, sp, 0x70
_0808B776:
	adds r0, 0x1
	mov r10, r0
	mov r4, r8
	movs r5, 0x8
_0808B77E:
	movs r0, 0
	bl sub_803D73C
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	movs r2, 0
	bl sub_8045C28
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _0808B77E
	movs r0, 0x3
	bl DungeonRandomCapped
	ldrh r1, [r6, 0x4]
	adds r1, r0
	subs r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	ldr r2, _0808B868
	ldr r0, [sp, 0x70]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x70]
	movs r0, 0x3
	bl DungeonRandomCapped
	ldrh r2, [r6, 0x6]
	adds r2, r0
	subs r2, 0x1
	lsls r2, 16
	ldr r0, _0808B86C
	ldr r1, [sp, 0x70]
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0x70]
	movs r2, 0
	ldrsh r0, [r7, r2]
	asrs r1, 16
	bl GetMapTile_2
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0808B7FA
	movs r0, 0xC8
	lsls r0, 1
	bl PlaySoundEffect
	adds r0, r7, 0
	bl sub_808BB3C
	adds r0, r6, 0
	adds r1, r7, 0
	mov r2, r8
	movs r3, 0x9
	bl sub_8046860
_0808B7FA:
	mov r0, r10
	cmp r0, 0x5
	ble _0808B776
	ldr r0, [r6, 0x70]
	ldr r2, _0808B870
	adds r1, r0, r2
	movs r0, 0
	strb r0, [r1]
_0808B80A:
	mov r0, r9
	cmp r0, 0x3
	bne _0808B8CA
	bl JirachiFriendAreaSearch
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3A
	bne _0808B87C
	ldr r0, _0808B878
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	b _0808B690
	.align 2, 0
_0808B82C: .4byte gUnknown_202E038
_0808B830: .4byte 0x0000019d
_0808B834: .4byte sub_808BBA8
_0808B838: .4byte sub_80861A8
_0808B83C: .4byte gDungeonGlobalData
_0808B840: .4byte 0x0001356c
_0808B844: .4byte gUnknown_8105668
_0808B848: .4byte 0x000001a7
_0808B84C: .4byte gUnknown_8105674
_0808B850: .4byte gUnknown_81056B8
_0808B854: .4byte gUnknown_81056DC
_0808B858: .4byte gUnknown_8105798
_0808B85C: .4byte gUnknown_810579C
_0808B860: .4byte 0x00000705
_0808B864: .4byte gUnknown_810581C
_0808B868: .4byte 0xffff0000
_0808B86C: .4byte 0x0000ffff
_0808B870: .4byte 0x0000015d
_0808B874: .4byte gUnknown_8105974
_0808B878: .4byte gUnknown_8105A08
_0808B87C:
	ldr r0, _0808BA30
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl JirachiWishGrantDialogue
	ldr r0, [r6, 0x70]
	ldr r2, _0808BA34
	adds r1, r0, r2
	movs r0, 0
	strb r0, [r1]
	ldr r0, _0808BA38
	bl DisplayDungeonDialogue
	adds r0, r4, 0
	bl UnlockFriendArea
	movs r0, 0xD4
	bl PlaySoundEffect
	bl GetLeaderEntity
	adds r1, r0, 0
	ldr r0, _0808BA3C
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0808BA40
	adds r1, r4, 0
	movs r2, 0
	bl sub_8092578
	ldr r0, _0808BA44
	bl DisplayDungeonDialogue
_0808B8CA:
	mov r0, r9
	cmp r0, 0x4
	bne _0808B98E
	ldr r0, _0808BA48
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl JirachiWishGrantDialogue
	movs r0, 0
	add r1, sp, 0x48
	mov r8, r1
	add r7, sp, 0x74
_0808B8EC:
	adds r0, 0x1
	mov r10, r0
	mov r4, r8
	movs r5, 0x3
_0808B8F4:
	movs r0, 0x8
	bl DungeonRandomCapped
	ldr r2, _0808BA4C
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl sub_8045C28
	adds r4, 0x4
	subs r5, 0x1
	cmp r5, 0
	bge _0808B8F4
	movs r0, 0x3
	bl DungeonRandomCapped
	ldrh r1, [r6, 0x4]
	adds r1, r0
	subs r1, 0x1
	lsls r1, 16
	lsrs r1, 16
	ldr r2, _0808BA50
	ldr r0, [sp, 0x74]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x74]
	movs r0, 0x3
	bl DungeonRandomCapped
	ldrh r2, [r6, 0x6]
	adds r2, r0
	subs r2, 0x1
	lsls r2, 16
	ldr r0, _0808BA54
	ldr r1, [sp, 0x74]
	ands r1, r0
	orrs r1, r2
	str r1, [sp, 0x74]
	movs r2, 0
	ldrsh r0, [r7, r2]
	asrs r1, 16
	bl GetMapTile_2
	ldrh r1, [r0]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0808B970
	movs r0, 0xC8
	lsls r0, 1
	bl PlaySoundEffect
	adds r0, r7, 0
	bl sub_808BB3C
	adds r0, r6, 0
	adds r1, r7, 0
	mov r2, r8
	movs r3, 0x4
	bl sub_8046860
_0808B970:
	mov r0, r10
	cmp r0, 0x4
	ble _0808B8EC
	ldr r0, [r6, 0x70]
	ldr r2, _0808BA34
	adds r1, r0, r2
	movs r0, 0
	strb r0, [r1]
	ldr r0, _0808BA58
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
_0808B98E:
	mov r0, r9
	cmp r0, 0x5
	bne _0808B9F8
	ldr r0, _0808BA5C
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	adds r0, r6, 0
	bl JirachiWishGrantDialogue
	ldr r0, [r6, 0x70]
	ldr r2, _0808BA34
	adds r1, r0, r2
	movs r0, 0
	strb r0, [r1]
	ldr r0, _0808BA60
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	bl GetLeaderEntity
	adds r1, r0, 0
	adds r1, 0x4
	adds r0, r6, 0x4
	bl CalculateFacingDir
	adds r1, r0, 0
	adds r0, r6, 0
	bl SetFacingDirection
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808BA64
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808BA68
	ldr r0, [r0]
	ldr r1, _0808BA6C
	adds r0, r1
	movs r1, 0x1
	strb r1, [r0]
_0808B9F8:
	ldr r0, _0808BA70
	bl DisplayDungeonDialogue
	adds r0, r6, 0
	bl sub_808BC20
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	ldr r0, _0808BA74
	bl DisplayDungeonDialogue
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	bl sub_808BD38
	add sp, 0x78
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808BA30: .4byte gUnknown_8105AD4
_0808BA34: .4byte 0x0000015d
_0808BA38: .4byte gUnknown_8105B20
_0808BA3C: .4byte gAvailablePokemonNames
_0808BA40: .4byte gUnknown_202DE58
_0808BA44: .4byte gUnknown_8105B68
_0808BA48: .4byte gUnknown_8105BA8
_0808BA4C: .4byte gUnknown_81074FC
_0808BA50: .4byte 0xffff0000
_0808BA54: .4byte 0x0000ffff
_0808BA58: .4byte gUnknown_8105BF4
_0808BA5C: .4byte gUnknown_8105D2C
_0808BA60: .4byte gUnknown_8105D80
_0808BA64: .4byte gUnknown_8105D9C
_0808BA68: .4byte gDungeonGlobalData
_0808BA6C: .4byte 0x00000674
_0808BA70: .4byte gUnknown_81058E0
_0808BA74: .4byte gUnknown_810593C
	thumb_func_end JirachiWish

	thumb_func_start JirachiReFightDialogue
JirachiReFightDialogue:
	push {lr}
	ldr r0, _0808BA94
	bl HasRecruitedMon
	lsls r0, 24
	cmp r0, 0
	beq _0808BA9C
	bl sub_8086448
	ldr r0, _0808BA98
	bl sub_80866C4
	b _0808BAA0
	.align 2, 0
_0808BA94: .4byte 0x0000019d
_0808BA98: .4byte gJirachiReFightDialogue_1
_0808BA9C:
	bl JirachiPreFightDialogue
_0808BAA0:
	pop {r0}
	bx r0
	thumb_func_end JirachiReFightDialogue

	thumb_func_start JirachiWishGrantFlash
JirachiWishGrantFlash:
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, _0808BB34
	bl PlaySoundEffect
	ldr r1, _0808BB38
	movs r0, 0x1F
	str r0, [r1]
	movs r4, 0xFA
	movs r5, 0x1
_0808BAB8:
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl SetDungeonBGColorRGB
	movs r0, 0x46
	bl sub_803E46C
	subs r4, 0xA
	cmp r4, 0x95
	bgt _0808BAB8
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	movs r4, 0xFA
	movs r5, 0x1
_0808BADE:
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl SetDungeonBGColorRGB
	movs r0, 0x46
	bl sub_803E46C
	subs r4, 0xA
	cmp r4, 0xC7
	bgt _0808BADE
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	movs r4, 0xFA
	movs r5, 0x1
_0808BB04:
	str r5, [sp]
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl SetDungeonBGColorRGB
	movs r0, 0x46
	bl sub_803E46C
	subs r4, 0xA
	cmp r4, 0
	bge _0808BB04
	movs r0, 0xA
	movs r1, 0x46
	bl sub_803E708
	bl sub_8085EB0
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808BB34: .4byte 0x000002c1
_0808BB38: .4byte gUnknown_202EDC8
	thumb_func_end JirachiWishGrantFlash

	thumb_func_start sub_808BB3C
sub_808BB3C:
	push {lr}
	sub sp, 0x8
	adds r3, r0, 0
	movs r0, 0
	ldrsh r1, [r3, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0xC0
	lsls r1, 4
	adds r0, r1
	cmp r0, 0
	bge _0808BB58
	adds r0, 0xFF
_0808BB58:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _0808BBA0
	ldr r2, [sp, 0x4]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	movs r0, 0x2
	ldrsh r1, [r3, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 11
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1
	cmp r0, 0
	bge _0808BB7C
	adds r0, 0xFF
_0808BB7C:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r1, _0808BBA4
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x64
	movs r1, 0
	movs r2, 0
	add r3, sp, 0x4
	bl sub_8085EC8
	add sp, 0x8
	pop {r0}
	bx r0
	.align 2, 0
_0808BBA0: .4byte 0xffff0000
_0808BBA4: .4byte 0x0000ffff
	thumb_func_end sub_808BB3C

        .align 2,0
