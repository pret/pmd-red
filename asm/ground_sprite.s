	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

        thumb_func_start sub_80A62F0
sub_80A62F0:
	push {r4-r7,lr}
	ldr r4, _080A6378
	movs r0, 0x88
	lsls r0, 1
	movs r1, 0x6
	bl MemoryAlloc
	str r0, [r4]
	ldr r0, _080A637C
	ldr r1, _080A6380
	bl OpenFileAndGetFileDataPtr
	ldr r1, _080A6384
	str r0, [r1]
	movs r0, 0x1
	bl sub_800DAC0
	ldr r4, [r4]
	ldr r1, _080A6388
	movs r0, 0x16
	str r0, [r1]
	ldr r1, _080A638C
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0
	movs r2, 0
	movs r1, 0x80
	lsls r1, 9
	adds r3, r1, 0
_080A632A:
	str r2, [r4]
	lsls r0, 4
	str r0, [r4, 0x4]
	str r2, [r4, 0x8]
	adds r0, r1, 0
	adds r1, r3
	asrs r0, 16
	adds r4, 0xC
	cmp r0, 0x15
	ble _080A632A
	ldr r0, _080A6378
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 1
	adds r4, r0, r1
	movs r6, 0
	movs r7, 0
	movs r5, 0xE8
	lsls r5, 13
_080A6350:
	strh r7, [r4]
	strh r7, [r4, 0x2]
	lsrs r0, r5, 16
	movs r1, 0
	bl sub_80997F4
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r6, 0x1
	adds r4, 0x4
	cmp r6, 0x1
	ble _080A6350
	movs r0, 0x1
	negs r0, r0
	bl GroundSprite_Reset
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6378: .4byte gUnknown_3001B7C
_080A637C: .4byte gUnknown_81177CC
_080A6380: .4byte gDungeonFileArchive
_080A6384: .4byte gUnknown_203B4B4
_080A6388: .4byte gUnknown_2039DD4
_080A638C: .4byte gUnknown_2039DD0
	thumb_func_end sub_80A62F0

	thumb_func_start GroundSprite_Reset
GroundSprite_Reset:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	asrs r0, 16
	mov r9, r0
	ldr r1, _080A641C
	movs r0, 0
	bl Log
	ldr r0, _080A6420
	movs r1, 0
	mov r8, r1
	strh r1, [r0]
	ldr r0, _080A6424
	strh r1, [r0]
	bl sub_80A6460
	mov r0, r9
	bl sub_80A4D48
	lsls r0, 24
	movs r1, 0x2
	cmp r0, 0
	beq _080A63C6
	movs r1, 0x3
_080A63C6:
	movs r0, 0xF8
	lsls r0, 1
	bl sub_808E53C
	ldr r5, _080A6428
	adds r0, r5, 0
	bl sub_8004E8C
	ldr r4, _080A642C
	adds r0, r4, 0
	bl sub_8004E8C
	ldrh r1, [r4, 0x4]
	ldr r6, _080A6430
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r4, 0x4]
	ldrh r1, [r4, 0xA]
	adds r0, r6, 0
	ands r0, r1
	movs r2, 0x80
	lsls r2, 4
	adds r7, r2, 0
	orrs r0, r7
	strh r0, [r4, 0xA]
	mov r0, r9
	bl sub_80A4D48
	lsls r0, 24
	cmp r0, 0
	beq _080A6434
	ldrh r1, [r5, 0x4]
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r5, 0x4]
	ldrh r1, [r5, 0xA]
	adds r0, r6, 0
	ands r0, r1
	movs r2, 0xC0
	lsls r2, 4
	adds r1, r2, 0
	orrs r0, r1
	b _080A6444
	.align 2, 0
_080A641C: .4byte gUnknown_81177D8
_080A6420: .4byte gUnknown_2039DCC
_080A6424: .4byte gUnknown_2039DCE
_080A6428: .4byte gUnknown_2039DB0
_080A642C: .4byte gUnknown_2039DC0
_080A6430: .4byte 0x0000f3ff
_080A6434:
	ldrh r1, [r5, 0x4]
	adds r0, r6, 0
	ands r0, r1
	strh r0, [r5, 0x4]
	ldrh r1, [r5, 0xA]
	adds r0, r6, 0
	ands r0, r1
	orrs r0, r7
_080A6444:
	strh r0, [r5, 0xA]
	movs r0, 0x1
	bl ResetSprites
	movs r0, 0x1
	bl nullsub_10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundSprite_Reset

	thumb_func_start sub_80A6460
sub_80A6460:
	push {r4-r7,lr}
	ldr r0, _080A649C
	ldr r1, _080A64A0
	bl OpenFileAndGetFileDataPtr
	adds r7, r0, 0
	movs r5, 0x80
	lsls r5, 1
	ldr r4, [r7, 0x4]
	movs r6, 0xC
_080A6474:
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0x10
	bl sub_809971C
	adds r0, r5, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x40
	subs r6, 0x1
	cmp r6, 0
	bge _080A6474
	adds r0, r7, 0
	bl CloseFile
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A649C: .4byte gUnknown_81177EC
_080A64A0: .4byte gMonsterFileArchive
	thumb_func_end sub_80A6460

	thumb_func_start sub_80A64A4
sub_80A64A4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, _080A6508
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 1
	adds r7, r0, r1
	bl sub_80A6460
	movs r0, 0
	mov r8, r0
_080A64C0:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	cmp r0, 0
	ble _080A6568
	ldrh r5, [r7]
	mov r0, r8
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	mov r1, r8
	lsls r0, r1, 20
	movs r1, 0xE8
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	mov r9, r0
	movs r0, 0x80
	lsls r0, 2
	adds r1, r0, 0
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080A6514
	ldr r0, _080A650C
	ldr r1, _080A6510
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 6
	ldr r1, [r6, 0x4]
	adds r2, r1, r0
	b _080A652A
	.align 2, 0
_080A6508: .4byte gUnknown_3001B7C
_080A650C: .4byte gUnknown_81177EC
_080A6510: .4byte gMonsterFileArchive
_080A6514:
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 2
	ldr r1, _080A6584
	adds r0, r1
	ldr r0, [r0]
	ldr r1, _080A6588
	bl OpenFileAndGetFileDataPtr
	adds r6, r0, 0
	ldr r2, [r6, 0x4]
_080A652A:
	movs r1, 0x80
	lsls r1, 5
	adds r0, r1, 0
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 16
	lsrs r1, 16
	negs r1, r1
	lsrs r4, r1, 31
	movs r1, 0x80
	lsls r1, 6
	adds r0, r1, 0
	ands r5, r0
	cmp r5, 0
	beq _080A654C
	movs r0, 0x2
	orrs r4, r0
_080A654C:
	mov r0, r9
	adds r1, r2, 0
	movs r2, 0x10
	bl sub_809971C
	mov r0, r10
	adds r1, r4, 0
	bl sub_80997F4
	cmp r6, 0
	beq _080A6568
	adds r0, r6, 0
	bl CloseFile
_080A6568:
	movs r0, 0x1
	add r8, r0
	adds r7, 0x4
	mov r1, r8
	cmp r1, 0x1
	ble _080A64C0
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6584: .4byte gUnknown_81178F4
_080A6588: .4byte gOrnamentFileArchive
	thumb_func_end sub_80A64A4

	thumb_func_start sub_80A658C
sub_80A658C:
	push {r4,lr}
	bl sub_800DB7C
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	bl sub_8005180
	bl nullsub_12
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	ldr r0, _080A65D0
	ldr r0, [r0]
	bl CloseFile
	ldr r4, _080A65D4
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A65D0: .4byte gUnknown_203B4B4
_080A65D4: .4byte gUnknown_3001B7C
	thumb_func_end sub_80A658C

	thumb_func_start sub_80A65D8
sub_80A65D8:
	adds r0, 0x50
	ldrh r0, [r0]
	bx lr
	thumb_func_end sub_80A65D8

	thumb_func_start sub_80A65E0
sub_80A65E0:
	lsrs r0, 16
	ldr r2, _080A65EC
	adds r1, r2, 0
	ands r0, r1
	bx lr
	.align 2, 0
_080A65EC: .4byte 0x0000337f
	thumb_func_end sub_80A65E0

	thumb_func_start sub_80A65F0
sub_80A65F0:
	push {r4-r6,lr}
	adds r3, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, 0x50
	strh r1, [r0]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	asrs r2, r0, 31
	movs r0, 0x40
	ands r2, r0
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080A6616
	subs r2, 0x40
_080A6616:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A6624
	adds r1, r2, 0
	adds r1, 0x48
	b _080A6628
_080A6624:
	adds r1, r2, 0
	adds r1, 0x40
_080A6628:
	adds r0, r3, 0
	adds r0, 0x6A
	strh r1, [r0]
	adds r2, r3, 0
	adds r2, 0x50
	ldrh r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080A6648
	adds r1, r3, 0
	adds r1, 0x3C
	ldr r0, _080A6644
	b _080A664E
	.align 2, 0
_080A6644: .4byte gUnknown_2039DC0
_080A6648:
	adds r1, r3, 0
	adds r1, 0x3C
	ldr r0, _080A6680
_080A664E:
	ldm r0!, {r4-r6}
	stm r1!, {r4-r6}
	ldrh r1, [r2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080A6678
	ldrh r2, [r3, 0x3C]
	ldr r1, _080A6684
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r3, 0x3C]
	adds r2, r3, 0
	adds r2, 0x42
	ldrh r0, [r2]
	ands r1, r0
	movs r3, 0x80
	lsls r3, 3
	adds r0, r3, 0
	orrs r1, r0
	strh r1, [r2]
_080A6678:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A6680: .4byte gUnknown_2039DB0
_080A6684: .4byte 0x0000f3ff
	thumb_func_end sub_80A65F0

	thumb_func_start sub_80A6688
sub_80A6688:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	bl sub_80A65E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_80A65F0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A6688

	thumb_func_start sub_80A66A4
sub_80A66A4:
	push {lr}
	movs r1, 0
	adds r0, 0x48
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _080A66B4
	movs r1, 0x1
_080A66B4:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80A66A4

	thumb_func_start sub_80A66BC
sub_80A66BC:
	push {lr}
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080A66CC
	movs r0, 0
	b _080A66CE
_080A66CC:
	movs r0, 0x1
_080A66CE:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66BC

	thumb_func_start sub_80A66D4
sub_80A66D4:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bge _080A66F2
	adds r0, r1, 0
	adds r0, 0x48
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _080A66F2
	movs r0, 0x1
	b _080A66F4
_080A66F2:
	movs r0, 0
_080A66F4:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66D4

	thumb_func_start sub_80A66F8
sub_80A66F8:
	push {lr}
	adds r1, r0, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	blt _080A6716
	ldrh r1, [r1]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	bne _080A6716
	lsrs r0, r1, 15
	b _080A6718
_080A6716:
	movs r0, 0
_080A6718:
	pop {r1}
	bx r1
	thumb_func_end sub_80A66F8

	thumb_func_start sub_80A671C
sub_80A671C:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r4, 0
	adds r6, 0x58
	movs r0, 0
	ldrsh r1, [r6, r0]
	cmp r1, 0
	beq _080A6752
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	beq _080A674A
	ldr r0, [r4, 0x5C]
	movs r5, 0x1
	negs r5, r5
	cmp r0, r5
	beq _080A674A
	bl sub_800E9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080A674E
_080A674A:
	movs r0, 0x1
	b _080A6754
_080A674E:
	str r5, [r4, 0x5C]
	strh r0, [r6]
_080A6752:
	movs r0, 0
_080A6754:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A671C

	thumb_func_start sub_80A675C
sub_80A675C:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r1, 0
	mov r0, sp
	bl sub_809D248
	lsls r0, 24
	cmp r0, 0
	beq _080A678C
	ldr r1, [r6]
	cmp r1, 0
	bge _080A6776
	adds r1, 0xFF
_080A6776:
	asrs r1, 8
	ldr r0, [sp]
	subs r4, r1, r0
	ldr r1, [r6, 0x4]
	cmp r1, 0
	bge _080A6784
	adds r1, 0xFF
_080A6784:
	asrs r1, 8
	ldr r0, [sp, 0x4]
	subs r5, r1, r0
	b _080A67A0
_080A678C:
	ldr r0, [r6]
	cmp r0, 0
	bge _080A6794
	adds r0, 0xFF
_080A6794:
	asrs r4, r0, 8
	ldr r1, [r6, 0x4]
	cmp r1, 0
	bge _080A679E
	adds r1, 0xFF
_080A679E:
	asrs r5, r1, 8
_080A67A0:
	adds r1, r4, 0
	adds r1, 0x40
	ldr r0, _080A67BC
	cmp r1, r0
	bhi _080A67C0
	movs r0, 0x10
	negs r0, r0
	cmp r5, r0
	blt _080A67C0
	cmp r5, 0xCF
	bgt _080A67C0
	movs r0, 0x1
	b _080A67C2
	.align 2, 0
_080A67BC: .4byte 0x0000016f
_080A67C0:
	movs r0, 0
_080A67C2:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80A675C

	thumb_func_start sub_80A67CC
sub_80A67CC:
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r7, 0
	cmp r5, 0
	beq _080A67E2
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	ble _080A67E2
	movs r7, 0x1
_080A67E2:
	adds r0, r2, 0
	bl sub_80A65E0
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_80A65F0
	movs r1, 0
	str r1, [r4, 0x74]
	str r1, [r4, 0x78]
	movs r6, 0x1
	negs r6, r6
	str r6, [r4, 0x7C]
	adds r0, r4, 0
	adds r0, 0x70
	strb r1, [r0]
	subs r0, 0x4
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	adds r2, r4, 0
	adds r2, 0x52
	ldr r0, _080A6884
	strh r0, [r2]
	str r1, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x64
	strh r1, [r0]
	adds r2, 0x14
	adds r0, r6, 0
	adds r3, r0, 0
	strh r0, [r2]
	adds r0, r4, 0
	adds r0, 0x68
	strh r1, [r0]
	subs r0, 0x10
	strh r1, [r0]
	adds r1, r4, 0
	adds r1, 0x5A
	movs r0, 0xFF
	strb r0, [r1]
	str r6, [r4, 0x5C]
	str r6, [r4, 0x60]
	cmp r7, 0
	beq _080A6888
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r4, 0x48]
	str r1, [r4, 0x4C]
	adds r5, r4, 0
	adds r5, 0x48
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	bne _080A689A
	adds r0, r4, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _080A689A
	adds r0, r5, 0
	bl sub_80A6CF4
	lsls r0, 24
	cmp r0, 0
	beq _080A689A
	adds r0, r4, 0
	adds r1, r5, 0
	adds r2, r6, 0
	bl sub_80A68F8
	b _080A689A
	.align 2, 0
_080A6884: .4byte 0x0000ffff
_080A6888:
	adds r1, r4, 0
	adds r1, 0x48
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r0, r4, 0
	adds r0, 0x4A
	strh r7, [r0]
	str r7, [r4, 0x4C]
_080A689A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A67CC

	thumb_func_start sub_80A68A0
sub_80A68A0:
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A68CE
	adds r0, r4, 0
	adds r0, 0x58
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080A68CE
	ldr r1, [r4, 0x5C]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A68CE
	adds r0, r1, 0
	bl sub_800DC14
_080A68CE:
	ldr r0, [r4, 0x54]
	cmp r0, 0
	beq _080A68DC
	bl CloseFile
	movs r0, 0
	str r0, [r4, 0x54]
_080A68DC:
	adds r0, r4, 0
	bl sub_80A69FC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80A68A0

	thumb_func_start sub_80A68E8
sub_80A68E8:
	push {lr}
	movs r0, 0x15
_080A68EC:
	subs r0, 0x1
	cmp r0, 0
	bge _080A68EC
	pop {r0}
	bx r0
	thumb_func_end sub_80A68E8

	thumb_func_start sub_80A68F8
sub_80A68F8:
	push {r4-r7,lr}
	mov r12, r0
	adds r5, r2, 0
	ldr r0, _080A6924
	ldr r4, [r0]
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, r5
	blt _080A6956
	adds r5, r0, 0
	movs r3, 0
	ldr r0, [r4]
	mov r6, r12
	adds r6, 0x52
	mov r7, r12
	adds r7, 0x64
	cmp r0, 0
	bne _080A6928
	movs r2, 0x1
	cmp r2, r5
	blt _080A692A
	b _080A6986
	.align 2, 0
_080A6924: .4byte gUnknown_3001B7C
_080A6928:
	movs r2, 0
_080A692A:
	adds r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	adds r4, 0xC
	cmp r3, 0x15
	bgt _080A6986
	ldr r0, [r4]
	cmp r0, 0
	bne _080A6928
	adds r2, 0x1
	cmp r2, r5
	blt _080A692A
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	subs r0, 0xC
	subs r4, r0
	adds r0, r3, 0x1
	subs r0, r2
	lsls r0, 16
	asrs r3, r0, 16
	b _080A6986
_080A6956:
	movs r3, 0x15
	adds r4, 0xFC
	ldr r0, [r4]
	mov r6, r12
	adds r6, 0x52
	mov r7, r12
	adds r7, 0x64
	cmp r0, 0
	bne _080A696C
	movs r2, 0x1
	b _080A6982
_080A696C:
	movs r2, 0
_080A696E:
	subs r0, r3, 0x1
	lsls r0, 16
	asrs r3, r0, 16
	subs r4, 0xC
	cmp r3, 0
	blt _080A6986
	ldr r0, [r4]
	cmp r0, 0
	bne _080A696C
	adds r2, 0x1
_080A6982:
	cmp r2, r5
	blt _080A696E
_080A6986:
	cmp r2, r5
	blt _080A69C4
	strh r3, [r6]
	strh r5, [r7]
	movs r0, 0x1
	str r0, [r4]
	mov r0, r12
	str r0, [r4, 0x8]
	ldrh r1, [r1, 0x2]
	bl GroundSprite_ExtendPaletteAdd
	cmp r5, 0x1
	ble _080A69B2
	movs r2, 0x2
	adds r0, r4, 0
	adds r0, 0xC
	subs r1, r5, 0x1
_080A69A8:
	str r2, [r0]
	adds r0, 0xC
	subs r1, 0x1
	cmp r1, 0
	bne _080A69A8
_080A69B2:
	ldr r1, _080A69C0
	ldr r0, [r1]
	subs r0, r5
	str r0, [r1]
	movs r0, 0x1
	b _080A69EC
	.align 2, 0
_080A69C0: .4byte gUnknown_2039DD4
_080A69C4:
	ldr r1, _080A69F4
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	mov r1, r12
	str r0, [r1, 0x7C]
	mov r0, r12
	adds r0, 0x70
	movs r1, 0
	strb r1, [r0]
	ldr r0, _080A69F8
	strh r0, [r6]
	strh r1, [r7]
	mov r0, r12
	adds r0, 0x6C
	strh r1, [r0]
	adds r0, 0x2
	strh r1, [r0]
	movs r0, 0
_080A69EC:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A69F4: .4byte gUnknown_2039DD0
_080A69F8: .4byte 0x0000ffff
	thumb_func_end sub_80A68F8

	thumb_func_start sub_80A69FC
sub_80A69FC:
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r6, 0
	adds r7, 0x52
	movs r0, 0
	ldrsh r4, [r7, r0]
	ldr r0, _080A6A80
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	ldr r0, [r0]
	adds r5, r0, r1
	cmp r4, 0
	blt _080A6A7A
	adds r0, r6, 0
	bl GroundSprite_ExtendPaletteDelete
	movs r0, 0
	str r0, [r5, 0x8]
	str r0, [r5]
	adds r5, 0xC
	ldr r1, _080A6A84
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	asrs r4, r0, 16
	adds r6, 0x64
	mov r12, r6
	cmp r4, 0x15
	bgt _080A6A6A
	ldr r0, [r5]
	cmp r0, 0x2
	bne _080A6A6A
	movs r6, 0
	adds r2, r1, 0
	lsls r1, r4, 16
	movs r0, 0x80
	lsls r0, 9
	adds r1, r0
	adds r3, r0, 0
_080A6A50:
	str r6, [r5]
	adds r5, 0xC
	ldr r0, [r2]
	adds r0, 0x1
	str r0, [r2]
	adds r0, r1, 0
	adds r1, r3
	asrs r4, r0, 16
	cmp r4, 0x15
	bgt _080A6A6A
	ldr r0, [r5]
	cmp r0, 0x2
	beq _080A6A50
_080A6A6A:
	ldr r0, _080A6A88
	strh r0, [r7]
	movs r0, 0
	mov r1, r12
	strh r0, [r1]
	ldr r1, _080A6A8C
	movs r0, 0x1
	strb r0, [r1]
_080A6A7A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6A80: .4byte gUnknown_3001B7C
_080A6A84: .4byte gUnknown_2039DD4
_080A6A88: .4byte 0x0000ffff
_080A6A8C: .4byte gUnknown_2039DD0
	thumb_func_end sub_80A69FC

	thumb_func_start GroundSprite_ExtendPaletteAdd
GroundSprite_ExtendPaletteAdd:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r10, r0
	lsls r1, 16
	lsrs r2, r1, 16
	adds r5, r2, 0
	movs r0, 0xC0
	lsls r0, 2
	ands r0, r2
	cmp r0, 0
	bne _080A6AB0
	b _080A6C6C
_080A6AB0:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r2
	cmp r0, 0
	beq _080A6AD8
	ldr r0, _080A6AD4
	ldr r1, [r0]
	movs r3, 0x86
	lsls r3, 1
	adds r4, r1, r3
	ldrh r1, [r4]
	adds r3, r0, 0
	cmp r1, r2
	bne _080A6B36
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	b _080A6C78
	.align 2, 0
_080A6AD4: .4byte gUnknown_3001B7C
_080A6AD8:
	movs r0, 0
	mov r8, r0
	ldr r1, _080A6B1C
	ldr r0, [r1]
	movs r2, 0x84
	lsls r2, 1
	adds r4, r0, r2
	adds r3, r1, 0
	movs r1, 0xE8
	lsls r1, 13
_080A6AEC:
	ldrh r0, [r4]
	cmp r0, r5
	bne _080A6B24
	lsrs r1, 16
	adds r3, r1, 0
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	mov r0, r10
	cmp r0, 0
	beq _080A6B08
	subs r1, 0x10
	adds r0, 0x68
	strh r1, [r0]
_080A6B08:
	adds r0, r3, 0
	subs r0, 0x10
	str r0, [sp]
	str r5, [sp, 0x4]
	movs r0, 0
	ldr r1, _080A6B20
	mov r2, r8
	bl Log
	b _080A6C78
	.align 2, 0
_080A6B1C: .4byte gUnknown_3001B7C
_080A6B20: .4byte gUnknown_81177F4
_080A6B24:
	movs r2, 0x80
	lsls r2, 9
	adds r1, r2
	movs r0, 0x1
	add r8, r0
	adds r4, 0x4
	mov r2, r8
	cmp r2, 0x1
	ble _080A6AEC
_080A6B36:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r5
	cmp r0, 0
	beq _080A6B68
	movs r0, 0x1
	mov r8, r0
	ldr r0, [r3]
	movs r1, 0x86
	lsls r1, 1
	adds r4, r0, r1
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080A6BA8
	ldr r0, _080A6B60
	ldr r1, _080A6B64
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A6B60: .4byte gUnknown_8117858
_080A6B64: .4byte gUnknown_8117864
_080A6B68:
	movs r0, 0
	mov r8, r0
	ldr r0, [r3]
	movs r1, 0x84
	lsls r1, 1
	adds r4, r0, r1
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _080A6B90
_080A6B7C:
	movs r3, 0x1
	add r8, r3
	adds r4, 0x4
	mov r0, r8
	cmp r0, 0x1
	bgt _080A6B96
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bgt _080A6B7C
_080A6B90:
	mov r2, r8
	cmp r2, 0x1
	ble _080A6BA8
_080A6B96:
	ldr r0, _080A6BA0
	ldr r1, _080A6BA4
	adds r2, r5, 0
	bl FatalError
	.align 2, 0
_080A6BA0: .4byte gUnknown_8117888
_080A6BA4: .4byte gUnknown_8117864
_080A6BA8:
	mov r0, r8
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	mov r3, r8
	lsls r0, r3, 20
	movs r1, 0xE8
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	str r0, [sp, 0x10]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r5
	cmp r0, 0
	beq _080A6BE8
	ldr r0, _080A6BE0
	ldr r1, _080A6BE4
	bl OpenFileAndGetFileDataPtr
	mov r9, r0
	ldr r7, [r0, 0x4]
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 6
	adds r7, r0
	b _080A6BFE
	.align 2, 0
_080A6BE0: .4byte gUnknown_81177EC
_080A6BE4: .4byte gMonsterFileArchive
_080A6BE8:
	movs r0, 0xFF
	ands r0, r5
	lsls r0, 2
	ldr r1, _080A6C60
	adds r0, r1
	ldr r0, [r0]
	ldr r1, _080A6C64
	bl OpenFileAndGetFileDataPtr
	mov r9, r0
	ldr r7, [r0, 0x4]
_080A6BFE:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r5
	lsls r0, 16
	lsrs r0, 16
	negs r0, r0
	lsrs r6, r0, 31
	movs r0, 0x80
	lsls r0, 6
	ands r0, r5
	cmp r0, 0
	beq _080A6C1A
	movs r0, 0x2
	orrs r6, r0
_080A6C1A:
	ldr r0, [sp, 0xC]
	adds r1, r6, 0
	bl sub_80997F4
	ldr r0, [sp, 0x10]
	adds r1, r7, 0
	movs r2, 0x10
	bl sub_809971C
	strh r5, [r4]
	movs r0, 0x1
	strh r0, [r4, 0x2]
	ldr r2, [sp, 0xC]
	subs r2, 0x10
	mov r3, r10
	cmp r3, 0
	beq _080A6C42
	mov r0, r10
	adds r0, 0x68
	strh r2, [r0]
_080A6C42:
	ldr r1, _080A6C68
	str r2, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r0, 0
	mov r2, r8
	ldr r3, [sp, 0xC]
	bl Log
	mov r0, r9
	cmp r0, 0
	beq _080A6C78
	bl CloseFile
	b _080A6C78
	.align 2, 0
_080A6C60: .4byte gUnknown_81178F4
_080A6C64: .4byte gOrnamentFileArchive
_080A6C68: .4byte gUnknown_8117894
_080A6C6C:
	mov r1, r10
	cmp r1, 0
	beq _080A6C78
	mov r0, r10
	adds r0, 0x68
	strh r5, [r0]
_080A6C78:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GroundSprite_ExtendPaletteAdd

	thumb_func_start GroundSprite_ExtendPaletteDelete
GroundSprite_ExtendPaletteDelete:
	push {r4-r6,lr}
	adds r2, r0, 0
	cmp r2, 0
	beq _080A6C9E
	adds r0, 0x68
	ldrh r0, [r0]
	adds r5, r0, 0
	subs r5, 0xD
	cmp r5, 0
	blt _080A6CE6
	b _080A6CA0
_080A6C9E:
	movs r5, 0x1
_080A6CA0:
	ldr r0, _080A6CEC
	lsls r1, r5, 2
	movs r3, 0x84
	lsls r3, 1
	adds r1, r3
	ldr r0, [r0]
	adds r4, r0, r1
	cmp r2, 0
	beq _080A6CBA
	adds r1, r2, 0
	adds r1, 0x68
	movs r0, 0
	strh r0, [r1]
_080A6CBA:
	ldrh r0, [r4, 0x2]
	subs r0, 0x1
	movs r6, 0
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bgt _080A6CE6
	ldr r1, _080A6CF0
	ldrh r3, [r4]
	movs r0, 0
	adds r2, r5, 0
	bl Log
	strh r6, [r4]
	strh r6, [r4, 0x2]
	adds r0, r5, 0
	adds r0, 0x1D
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl sub_80997F4
_080A6CE6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A6CEC: .4byte gUnknown_3001B7C
_080A6CF0: .4byte gUnknown_81178C0
	thumb_func_end GroundSprite_ExtendPaletteDelete

	thumb_func_start sub_80A6CF4
sub_80A6CF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x68
	movs r1, 0
	mov r8, r1
	movs r1, 0
	ldrsh r2, [r0, r1]
	mov r9, r2
	movs r2, 0
	mov r10, r2
	movs r0, 0x1
	negs r0, r0
	str r0, [sp, 0x60]
	str r0, [sp, 0x64]
	add r4, sp, 0x58
	adds r0, r4, 0
	bl sub_809D248
	movs r7, 0
	ldr r0, _080A6D70
	ldr r3, [r0]
	movs r1, 0x80
	lsls r1, 6
	mov r12, r1
	mov r4, sp
_080A6D2C:
	ldr r0, [r3]
	cmp r0, 0x1
	bne _080A6DB4
	ldr r2, [r3, 0x8]
	adds r0, r2, 0
	adds r0, 0x50
	ldrh r1, [r0]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	bne _080A6DB4
	ldr r0, [r2, 0x7C]
	cmp r0, 0
	blt _080A6DB4
	ldr r1, [r2, 0x74]
	cmp r1, 0
	bge _080A6D50
	adds r1, 0xFF
_080A6D50:
	asrs r1, 8
	ldr r0, [sp, 0x58]
	subs r5, r1, r0
	ldr r1, [r2, 0x78]
	cmp r1, 0
	bge _080A6D5E
	adds r1, 0xFF
_080A6D5E:
	asrs r1, 8
	ldr r0, [sp, 0x5C]
	subs r1, r0
	adds r6, r1, 0
	cmp r1, 0
	ble _080A6D74
	adds r0, r6, 0
	adds r0, 0x28
	b _080A6D78
	.align 2, 0
_080A6D70: .4byte gUnknown_3001B7C
_080A6D74:
	movs r0, 0x28
	subs r0, r6
_080A6D78:
	str r0, [r2, 0x7C]
	cmp r5, 0
	ble _080A6D88
	ldr r0, [r2, 0x7C]
	cmp r5, r0
	ble _080A6D92
	str r5, [r2, 0x7C]
	b _080A6D92
_080A6D88:
	negs r1, r5
	ldr r0, [r2, 0x7C]
	cmp r1, r0
	ble _080A6D92
	str r1, [r2, 0x7C]
_080A6D92:
	adds r0, r2, 0
	adds r0, 0x48
	movs r1, 0
	ldrsh r0, [r0, r1]
	add r10, r0
	cmp r0, r9
	blt _080A6DAE
	ldr r0, [r2, 0x7C]
	ldr r1, [sp, 0x64]
	cmp r1, r0
	bge _080A6DAE
	mov r1, r8
	str r1, [sp, 0x60]
	str r0, [sp, 0x64]
_080A6DAE:
	stm r4!, {r2}
	movs r2, 0x1
	add r8, r2
_080A6DB4:
	adds r0, r7, 0x1
	lsls r0, 16
	asrs r7, r0, 16
	adds r3, 0xC
	cmp r7, 0x15
	ble _080A6D2C
	cmp r10, r9
	blt _080A6E54
	ldr r0, [sp, 0x60]
	cmp r0, 0
	blt _080A6DD8
	lsls r0, 2
	add r0, sp
	ldr r0, [r0]
	bl sub_80A69FC
	movs r0, 0x1
	b _080A6E56
_080A6DD8:
	mov r1, r8
	cmp r1, 0
	ble _080A6E54
_080A6DDE:
	movs r5, 0x1
	negs r5, r5
	adds r3, r5, 0
	movs r6, 0
	mov r7, r8
	subs r7, 0x1
	mov r2, r8
	cmp r2, 0
	ble _080A6E08
	mov r2, sp
	mov r1, r8
_080A6DF4:
	ldr r0, [r2]
	ldr r0, [r0, 0x7C]
	cmp r3, r0
	bge _080A6E00
	mov r5, r8
	adds r3, r0, 0
_080A6E00:
	adds r2, 0x4
	subs r1, 0x1
	cmp r1, 0
	bne _080A6DF4
_080A6E08:
	lsls r0, r5, 2
	mov r1, sp
	adds r4, r1, r0
	ldr r0, [r4]
	bl sub_80A69FC
	mov r8, r7
	adds r1, r5, 0
	cmp r1, r8
	bge _080A6E28
	adds r2, r4, 0
_080A6E1E:
	ldr r0, [r2, 0x4]
	stm r2!, {r0}
	adds r1, 0x1
	cmp r1, r8
	blt _080A6E1E
_080A6E28:
	movs r1, 0
	ldr r0, _080A6E40
	ldr r3, [r0]
_080A6E2E:
	ldr r0, [r3]
	cmp r0, 0
	bne _080A6E44
	adds r6, 0x1
	cmp r6, r9
	blt _080A6E46
	movs r0, 0x1
	b _080A6E56
	.align 2, 0
_080A6E40: .4byte gUnknown_3001B7C
_080A6E44:
	movs r6, 0
_080A6E46:
	adds r1, 0x1
	adds r3, 0xC
	cmp r1, 0x15
	ble _080A6E2E
	mov r2, r8
	cmp r2, 0
	bgt _080A6DDE
_080A6E54:
	movs r0, 0
_080A6E56:
	add sp, 0x68
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A6CF4

	thumb_func_start sub_80A6E68
sub_80A6E68:
	push {lr}
	movs r0, 0
	bl ResetSprites
	movs r0, 0
	bl nullsub_10
	bl sub_800E970
	pop {r0}
	bx r0
	thumb_func_end sub_80A6E68

	thumb_func_start sub_80A6E80
sub_80A6E80:
	push {r4,lr}
	sub sp, 0x4
	ldr r4, _080A6EC4
	adds r0, r4, 0
	bl sub_809D248
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A6E98
	str r0, [r4]
	str r0, [r4, 0x4]
_080A6E98:
	bl sub_80ABA7C
	bl sub_80ACAD4
	bl sub_80AD7AC
	ldrh r1, [r4, 0x4]
	lsls r1, 16
	ldrh r0, [r4]
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	bl sub_800E90C
	bl sub_8005180
	bl nullsub_12
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A6EC4: .4byte gUnknown_2039DD8
	thumb_func_end sub_80A6E80

	thumb_func_start sub_80A6EC8
sub_80A6EC8:
	push {lr}
	adds r2, r0, 0
	adds r0, 0x52
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	ble _080A6EF6
	adds r0, r2, 0
	adds r0, 0x48
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bgt _080A6EE4
	adds r1, r0, 0
_080A6EE4:
	adds r0, r2, 0
	adds r0, 0x64
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, r1
	beq _080A6EF6
	adds r0, r2, 0
	adds r0, 0x66
	strh r1, [r0]
_080A6EF6:
	pop {r0}
	bx r0
	thumb_func_end sub_80A6EC8

	thumb_func_start sub_80A6EFC
sub_80A6EFC:
	push {r4-r7,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 24
	asrs r6, r2, 24
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080A6F48
	adds r5, r4, 0
	adds r5, 0x66
	movs r2, 0
	ldrsh r0, [r5, r2]
	cmp r0, 0
	blt _080A6F28
	adds r1, r4, 0
	adds r1, 0x48
	adds r2, r0, 0
	b _080A6F62
_080A6F28:
	adds r1, r4, 0
	adds r1, 0x48
	movs r2, 0
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bgt _080A6F36
	b _080A7038
_080A6F36:
	movs r2, 0x1
	negs r2, r2
	adds r0, r4, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	beq _080A7038
	b _080A6F72
_080A6F48:
	adds r5, r4, 0
	adds r5, 0x66
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080A6F72
	adds r0, r4, 0
	bl sub_80A69FC
	adds r1, r4, 0
	adds r1, 0x48
	movs r0, 0
	ldrsh r2, [r5, r0]
_080A6F62:
	adds r0, r4, 0
	bl sub_80A68F8
	lsls r0, 24
	cmp r0, 0
	beq _080A7038
	ldr r0, _080A6F8C
	strh r0, [r5]
_080A6F72:
	movs r0, 0x80
	lsls r0, 3
	ands r0, r7
	lsls r0, 16
	asrs r3, r0, 16
	cmp r3, 0
	beq _080A6F94
	ldrh r1, [r4]
	ldr r0, _080A6F90
	ands r0, r1
	strh r0, [r4]
	b _080A7038
	.align 2, 0
_080A6F8C: .4byte 0x0000ffff
_080A6F90: .4byte 0x0000efff
_080A6F94:
	ldr r2, _080A6FE0
	adds r0, r4, 0
	adds r0, 0x52
	movs r5, 0
	ldrsh r1, [r0, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, [r2]
	adds r1, r0
	mov r12, r1
	adds r1, r4, 0
	adds r1, 0x70
	movs r0, 0x1
	strb r0, [r1]
	subs r0, 0x2
	str r0, [r4, 0x7C]
	movs r1, 0xE0
	lsls r1, 3
	ands r1, r7
	movs r0, 0x80
	lsls r0, 1
	cmp r1, r0
	beq _080A6FE4
	cmp r1, r0
	ble _080A6FEE
	movs r0, 0x80
	lsls r0, 2
	cmp r1, r0
	beq _080A6FFA
	movs r0, 0xC0
	lsls r0, 2
	cmp r1, r0
	bne _080A6FEE
	adds r0, r4, 0
	adds r0, 0x6C
	strh r3, [r0]
	b _080A7000
	.align 2, 0
_080A6FE0: .4byte gUnknown_3001B7C
_080A6FE4:
	adds r1, r4, 0
	adds r1, 0x6C
	movs r0, 0x80
	strh r0, [r1]
	b _080A7000
_080A6FEE:
	adds r1, r4, 0
	adds r1, 0x6C
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r1]
	b _080A7000
_080A6FFA:
	adds r0, r4, 0
	adds r0, 0x6C
	strh r1, [r0]
_080A7000:
	adds r0, r4, 0
	adds r0, 0x6E
	movs r1, 0
	strh r1, [r0]
	ldr r5, [r4, 0x4C]
	movs r0, 0xFF
	ands r0, r7
	adds r2, r6, 0
	cmp r6, 0
	bge _080A7016
	adds r2, r6, 0x7
_080A7016:
	asrs r2, 3
	adds r2, r0, r2
	movs r3, 0x7
	ands r3, r6
	mov r6, r12
	ldr r0, [r6, 0x4]
	str r0, [sp]
	str r1, [sp, 0x4]
	lsls r0, r7, 16
	lsrs r0, 27
	movs r1, 0x1
	ands r0, r1
	str r0, [sp, 0x8]
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_80053D0
_080A7038:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A6EFC

	thumb_func_start sub_80A7040
sub_80A7040:
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r3, 0
	lsls r1, 16
	asrs r3, r1, 16
	lsls r2, 24
	asrs r2, 24
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A708C
	cmp r3, 0
	beq _080A7068
	movs r0, 0xE0
	lsls r0, 1
	cmp r3, r0
	bne _080A7080
_080A7068:
	adds r0, r4, 0
	bl sub_80A671C
	lsls r0, 24
	cmp r0, 0
	beq _080A708C
	adds r1, r4, 0
	adds r1, 0x58
	movs r0, 0xE0
	lsls r0, 1
	strh r0, [r1]
	b _080A708C
_080A7080:
	adds r0, r4, 0
	adds r0, 0x58
	strh r3, [r0]
	adds r0, 0x2
	strb r2, [r0]
	str r5, [r4, 0x60]
_080A708C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7040

	thumb_func_start sub_80A7094
sub_80A7094:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	adds r7, r0, 0
	mov r10, r1
	mov r8, r2
	str r3, [sp, 0x3C]
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [r7, 0x74]
	str r1, [r7, 0x78]
	movs r6, 0
	str r6, [r7, 0x7C]
	adds r0, r7, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A7172
	adds r4, r7, 0
	adds r4, 0x58
	movs r0, 0
	ldrsh r1, [r4, r0]
	cmp r1, 0
	beq _080A7172
	movs r0, 0xE0
	lsls r0, 1
	cmp r1, r0
	bne _080A70EC
	ldr r0, [r7, 0x5C]
	movs r5, 0x1
	negs r5, r5
	cmp r0, r5
	beq _080A70E8
	bl sub_800DC14
	str r5, [r7, 0x5C]
_080A70E8:
	strh r6, [r4]
	b _080A7172
_080A70EC:
	ldr r0, [r7, 0x5C]
	movs r1, 0x1
	negs r1, r1
	mov r9, r1
	cmp r0, r9
	bne _080A7160
	add r1, sp, 0x8
	ldr r0, _080A715C
	ldm r0!, {r2,r3,r5}
	stm r1!, {r2,r3,r5}
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl sub_800EE5C
	bl sub_800EF64
	add r2, sp, 0x14
	movs r3, 0
	ldrsh r0, [r4, r3]
	str r0, [sp, 0x14]
	str r6, [r2, 0x4]
	adds r0, r7, 0
	adds r0, 0x5A
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	str r0, [r2, 0x8]
	mov r4, r8
	ldr r0, [r4]
	cmp r0, 0
	bge _080A712C
	adds r0, 0xFF
_080A712C:
	asrs r0, 8
	strh r0, [r2, 0xC]
	mov r5, r8
	ldr r0, [r5, 0x4]
	cmp r0, 0
	bge _080A713A
	adds r0, 0xFF
_080A713A:
	asrs r0, 8
	strh r0, [r2, 0xE]
	strh r6, [r2, 0x10]
	strh r6, [r2, 0x12]
	mov r0, r9
	str r0, [r2, 0x14]
	str r6, [r2, 0x18]
	add r1, sp, 0x30
	add r0, sp, 0x8
	ldm r0!, {r3-r5}
	stm r1!, {r3-r5}
	adds r0, r2, 0
	bl sub_800E890
	str r0, [r7, 0x5C]
	b _080A7172
	.align 2, 0
_080A715C: .4byte gUnknown_81178E0
_080A7160:
	bl sub_800E9E4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _080A7172
	mov r1, r9
	str r1, [r7, 0x5C]
	strh r0, [r4]
_080A7172:
	adds r0, r7, 0
	adds r0, 0x52
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	blt _080A7222
	adds r0, r7, 0
	adds r0, 0x50
	ldrh r4, [r0]
	movs r0, 0x40
	ands r0, r4
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	cmp r0, 0
	bne _080A7222
	mov r3, r8
	ldr r1, [r3]
	cmp r1, 0
	bge _080A719C
	adds r1, 0xFF
_080A719C:
	asrs r1, 8
	ldr r2, _080A7228
	ldr r0, [r2]
	subs r5, r1, r0
	mov r1, r8
	ldr r0, [r1, 0x4]
	cmp r0, 0
	bge _080A71AE
	adds r0, 0xFF
_080A71AE:
	asrs r1, r0, 8
	ldr r0, [r2, 0x4]
	subs r6, r1, r0
	ldr r3, [sp, 0x3C]
	cmp r3, 0
	bge _080A71BC
	adds r3, 0xFF
_080A71BC:
	asrs r0, r3, 8
	subs r0, r6, r0
	mov r8, r0
	adds r1, r5, 0
	adds r1, 0x40
	ldr r0, _080A722C
	cmp r1, r0
	bhi _080A7274
	movs r0, 0x10
	negs r0, r0
	cmp r6, r0
	blt _080A7274
	cmp r6, 0xCF
	bgt _080A7274
	cmp r8, r0
	blt _080A7274
	mov r2, r8
	cmp r2, 0xCF
	bgt _080A7274
	movs r0, 0x10
	ands r0, r4
	cmp r0, 0
	beq _080A7234
	ldr r0, _080A7230
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080A7234
	adds r0, r7, 0
	movs r1, 0
	bl sub_80A72B8
	movs r1, 0x98
	lsls r1, 1
	adds r0, r7, 0
	adds r0, 0x68
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0xD0
	movs r3, 0
	bl sub_800558C
	adds r0, r7, 0
	adds r0, 0x70
	mov r3, r9
	strb r3, [r0]
_080A7222:
	movs r0, 0
	b _080A72A6
	.align 2, 0
_080A7228: .4byte gUnknown_2039DD8
_080A722C: .4byte 0x0000016f
_080A7230: .4byte gUnknown_2039DCC
_080A7234:
	adds r4, r7, 0
	adds r4, 0x70
	ldrb r1, [r4]
	adds r0, r7, 0
	bl sub_80A72B8
	adds r0, r7, 0
	adds r0, 0x6A
	movs r1, 0
	ldrsh r3, [r0, r1]
	adds r3, r6
	subs r0, 0x2
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	adds r1, r5, 0
	mov r2, r8
	bl sub_800558C
	movs r0, 0
	strb r0, [r4]
	mov r2, r10
	cmp r2, 0
	beq _080A7270
	mov r3, r10
	str r5, [r3]
	str r6, [r3, 0x4]
_080A7270:
	movs r0, 0x1
	b _080A72A6
_080A7274:
	adds r4, r7, 0
	adds r4, 0x70
	ldrb r0, [r4]
	cmp r0, 0
	beq _080A7222
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_80A72B8
	movs r1, 0x98
	lsls r1, 1
	adds r0, r7, 0
	adds r0, 0x68
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r7, 0
	adds r0, 0x3C
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0xD0
	movs r3, 0
	bl sub_800558C
	movs r0, 0
	strb r0, [r4]
_080A72A6:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7094

	thumb_func_start sub_80A72B8
sub_80A72B8:
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 24
	cmp r1, 0
	beq _080A72D2
	adds r1, r6, 0
	adds r1, 0x6E
	movs r0, 0
	strh r0, [r1]
	adds r0, r6, 0
	bl sub_80054BC
	b _080A7304
_080A72D2:
	adds r5, r6, 0
	adds r5, 0x6E
	adds r0, r6, 0
	adds r0, 0x6C
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r5]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _080A7304
	ldr r0, _080A730C
	adds r7, r0, 0
_080A72EE:
	adds r4, r5, 0
	ldrh r1, [r5]
	adds r0, r7, r1
	strh r0, [r5]
	adds r0, r6, 0
	bl sub_80054BC
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	bgt _080A72EE
_080A7304:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A730C: .4byte 0xffffff00
	thumb_func_end sub_80A72B8

	thumb_func_start sub_80A7310
sub_80A7310:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	mov r12, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	beq _080A73DC
	mov r0, r12
	ldr r0, [r0, 0x5C]
	mov r8, r0
	movs r0, 0x1
	negs r0, r0
	cmp r8, r0
	beq _080A73DC
	ldr r0, [r4]
	cmp r0, 0
	bge _080A7344
	adds r0, 0xFF
_080A7344:
	lsls r0, 8
	lsrs r0, 16
	ldr r1, _080A73D0
	mov r9, r1
	ldr r2, [sp, 0x4]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0x4]
	ldr r0, [r4, 0x4]
	cmp r0, 0
	bge _080A735C
	adds r0, 0xFF
_080A735C:
	lsls r0, 8
	lsrs r0, 16
	lsls r0, 16
	ldr r6, _080A73D4
	adds r4, r6, 0
	ands r4, r2
	orrs r4, r0
	str r4, [sp, 0x4]
	asrs r2, r4, 16
	ldr r0, _080A73D8
	ldr r0, [r0, 0x4]
	subs r0, r2, r0
	mov r1, r12
	adds r1, 0x6A
	movs r7, 0
	ldrsh r1, [r1, r7]
	adds r0, r1
	adds r7, r0, 0x2
	cmp r3, 0
	bge _080A7386
	adds r3, 0xFF
_080A7386:
	asrs r0, r3, 8
	subs r0, r2, r0
	lsls r0, 16
	adds r2, r6, 0
	ands r2, r4
	orrs r2, r0
	str r2, [sp, 0x4]
	cmp r5, 0
	beq _080A73B8
	ldr r1, [r5]
	add r0, sp, 0x4
	ldrh r0, [r0]
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	mov r0, r9
	ands r0, r2
	orrs r0, r1
	asrs r2, r0, 16
	ldr r1, [r5, 0x4]
	adds r1, r2
	lsls r1, 16
	ands r0, r6
	orrs r0, r1
	str r0, [sp, 0x4]
_080A73B8:
	mov r0, r12
	adds r0, 0x3C
	str r0, [sp]
	mov r0, r8
	add r1, sp, 0x4
	movs r2, 0
	adds r3, r7, 0
	bl sub_800E8AC
	movs r0, 0x1
	b _080A73DE
	.align 2, 0
_080A73D0: .4byte 0xffff0000
_080A73D4: .4byte 0x0000ffff
_080A73D8: .4byte gUnknown_2039DD8
_080A73DC:
	movs r0, 0
_080A73DE:
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80A7310

	thumb_func_start sub_80A73EC
sub_80A73EC:
	push {lr}
	bl CopySpritesToOam
	bl nullsub_13
	bl sub_8005304
	bl nullsub_14
	ldr r1, _080A7420
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	ldr r1, _080A7424
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB
	bls _080A741A
	movs r0, 0
	strh r0, [r1]
_080A741A:
	pop {r0}
	bx r0
	.align 2, 0
_080A7420: .4byte gUnknown_2039DCC
_080A7424: .4byte gUnknown_2039DCE
	thumb_func_end sub_80A73EC

	thumb_func_start sub_80A7428
sub_80A7428:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r6, r0, 0
	mov r8, r3
	lsls r1, 16
	asrs r7, r1, 16
	lsls r2, 16
	asrs r2, 16
	adds r4, r2, 0
	ldr r1, _080A7480
	mov r0, sp
	bl sprintf
	ldr r1, _080A7484
	mov r0, sp
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	adds r0, r4, 0
	bl GetPokemonSize
	lsls r0, 24
	lsrs r0, 24
	ldr r1, _080A7488
	ldr r2, [sp, 0xC]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, 0xC]
	movs r0, 0xD3
	lsls r0, 1
	cmp r4, r0
	bne _080A7490
	ldr r0, _080A748C
	ands r0, r2
	movs r1, 0x91
	lsls r1, 17
	orrs r0, r1
	str r0, [sp, 0xC]
	b _080A74AC
	.align 2, 0
_080A7480: .4byte gUnknown_8117EDC
_080A7484: .4byte gMonsterFileArchive
_080A7488: .4byte 0xffff0000
_080A748C: .4byte 0x0000ffff
_080A7490:
	movs r1, 0
	cmp r7, 0x47
	bne _080A7498
	movs r1, 0x1
_080A7498:
	adds r0, r4, 0
	bl GetPokemonOverworldPalette
	lsls r0, 24
	lsrs r0, 8
	ldr r2, _080A74E0
	ldr r1, [sp, 0xC]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, 0xC]
_080A74AC:
	ldr r0, [r5, 0x4]
	add r1, sp, 0xC
	str r0, [r1, 0x4]
	adds r0, r6, 0
	mov r2, r8
	bl sub_80A67CC
	str r5, [r6, 0x54]
	adds r0, r6, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A74D4
	movs r1, 0xC0
	lsls r1, 2
	adds r0, r6, 0
	movs r2, 0
	bl sub_80A6EFC
_080A74D4:
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A74E0: .4byte 0x0000ffff
	thumb_func_end sub_80A7428

	thumb_func_start sub_80A74E4
sub_80A74E4:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A74E4

	thumb_func_start sub_80A74F0
sub_80A74F0:
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	asrs r4, r1, 16
	lsls r2, 24
	asrs r5, r2, 24
	cmp r3, 0
	bge _080A7514
	movs r0, 0xE0
	lsls r0, 1
	cmp r4, r0
	beq _080A7512
	adds r0, r4, 0
	bl sub_800E700
	adds r3, r0, 0
	b _080A7514
_080A7512:
	movs r3, 0
_080A7514:
	adds r0, r6, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_80A7040
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A74F0

	thumb_func_start sub_80A7524
sub_80A7524:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	adds r5, r0, 0
	adds r6, r2, 0
	adds r7, r3, 0
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	mov r1, sp
	bl sub_80A7094
	lsls r0, 24
	cmp r0, 0
	beq _080A75C0
	ldr r1, [r5, 0x5C]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _080A758C
	ldr r2, [r5, 0x60]
	cmp r2, 0x3
	bgt _080A7580
	cmp r2, 0
	blt _080A7580
	add r4, sp, 0x8
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800569C
	movs r1, 0
	ldrsh r0, [r4, r1]
	str r0, [sp, 0xC]
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	add r2, sp, 0xC
	str r0, [r2, 0x4]
	adds r0, r5, 0
	adds r1, r6, 0
	adds r3, r7, 0
	bl sub_80A7310
	b _080A758C
_080A7580:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_80A7310
_080A758C:
	adds r0, r5, 0
	adds r0, 0x50
	ldrh r1, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	beq _080A75B4
	ldr r0, [sp]
	lsls r0, 16
	ldr r1, [sp, 0x4]
	lsls r1, 16
	lsrs r0, 16
	orrs r0, r1
	str r0, [sp, 0x14]
	add r1, sp, 0x14
	mov r0, r8
	adds r2, r5, 0
	bl sub_808E668
_080A75B4:
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	adds r3, r7, 0
	bl sub_80A7310
_080A75C0:
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7524

	thumb_func_start sub_80A75CC
sub_80A75CC:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 13
	ldr r0, _080A7618
	adds r2, r0
	movs r5, 0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _080A761C
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r3, [r2, 0x2]
	lsls r3, 16
	ldr r0, _080A7620
	ands r0, r1
	orrs r0, r3
	str r0, [sp]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _080A7628
	ldr r1, _080A7624
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	b _080A762A
	.align 2, 0
_080A7618: .4byte gUnknown_8117AE4
_080A761C: .4byte 0xffff0000
_080A7620: .4byte 0x0000ffff
_080A7624: .4byte gOrnamentFileArchive
_080A7628:
	str r5, [sp, 0x4]
_080A762A:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r6, 0
	bl sub_80A67CC
	str r5, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A764E
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A6EFC
_080A764E:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A75CC

	thumb_func_start sub_80A7658
sub_80A7658:
	push {lr}
	bl sub_80A68A0
	pop {r0}
	bx r0
	thumb_func_end sub_80A7658

	thumb_func_start sub_80A7664
sub_80A7664:
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	movs r1, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80A7094
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0
	adds r3, r6, 0
	bl sub_80A7310
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7664

	thumb_func_start sub_80A7688
sub_80A7688:
	push {r4-r6,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r6, r3, 0
	lsls r2, 16
	asrs r2, 13
	ldr r0, _080A76D4
	adds r2, r0
	movs r5, 0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r0, 16
	ldr r3, _080A76D8
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r3, [r2, 0x2]
	lsls r3, 16
	ldr r0, _080A76DC
	ands r0, r1
	orrs r0, r3
	str r0, [sp]
	ldr r0, [r2, 0x4]
	cmp r0, 0
	beq _080A76E4
	ldr r1, _080A76E0
	bl OpenFile
	adds r5, r0, 0
	movs r1, 0
	bl GetFileDataPtr
	ldr r0, [r5, 0x4]
	str r0, [sp, 0x4]
	b _080A76E6
	.align 2, 0
_080A76D4: .4byte gUnknown_8117E8C
_080A76D8: .4byte 0xffff0000
_080A76DC: .4byte 0x0000ffff
_080A76E0: .4byte gOrnamentFileArchive
_080A76E4:
	str r5, [sp, 0x4]
_080A76E6:
	adds r0, r4, 0
	mov r1, sp
	adds r2, r6, 0
	bl sub_80A67CC
	str r5, [r4, 0x54]
	adds r0, r4, 0
	adds r0, 0x52
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	blt _080A770A
	movs r1, 0x80
	lsls r1, 4
	adds r0, r4, 0
	movs r2, 0
	bl sub_80A6EFC
_080A770A:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80A7688

        .align 2,0
