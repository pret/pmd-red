	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8071518
sub_8071518:
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl ShouldAvoidEnemies
	lsls r0, 24
	cmp r0, 0
	bne _0807152E
	movs r0, 0
	b _08071538
_0807152E:
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_8071540
	movs r0, 0x1
_08071538:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8071518

	thumb_func_start sub_8071540
sub_8071540:
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	ldr r4, [r5, 0x70]
	adds r6, r4, 0
	ldrb r0, [r4, 0x7]
	cmp r0, 0
	bne _08071590
	adds r0, r5, 0
	movs r1, 0x2B
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _08071590
	movs r2, 0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	lsrs r1, r0, 31
	adds r0, r1
	movs r3, 0xE
	ldrsh r1, [r4, r3]
	asrs r0, 1
	cmp r1, r0
	bgt _08071576
	movs r2, 0x1
_08071576:
	adds r0, r6, 0
	movs r1, 0x4
	bl sub_8071ACC
	lsls r0, 24
	lsrs r0, 24
	cmp r7, 0
	beq _08071590
	cmp r0, 0
	beq _08071590
	adds r0, r5, 0
	bl sub_8042910
_08071590:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8071540

	thumb_func_start sub_8071598
sub_8071598:
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r5, [r6, 0x70]
	ldr r4, [r1, 0x70]
	cmp r6, r1
	bne _080715B0
	movs r0, 0
	b _08071670
_080715B0:
	ldrb r0, [r5, 0x8]
	cmp r0, 0x1
	beq _08071606
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1
	beq _08071606
	adds r0, r5, 0
	adds r0, 0xA4
	ldrb r1, [r0]
	cmp r1, 0x4
	beq _08071606
	adds r0, r4, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _08071606
	cmp r1, 0x1
	beq _08071606
	cmp r0, 0x1
	beq _08071606
	cmp r3, 0
	beq _080715EC
	ldrb r0, [r5, 0x6]
	cmp r0, 0
	bne _080715EC
	adds r0, r4, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _08071606
_080715EC:
	cmp r2, 0
	bne _0807160A
	adds r0, r4, 0
	adds r0, 0xE4
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0807160A
	adds r0, r6, 0
	bl sub_8071884
	lsls r0, 24
	cmp r0, 0
	bne _0807160A
_08071606:
	movs r0, 0x2
	b _08071670
_0807160A:
	movs r1, 0x80
	lsls r1, 1
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r6, 0
	cmp r0, 0
	beq _08071620
	movs r6, 0x2
	cmp r0, 0x1
	bne _08071620
	movs r6, 0x1
_08071620:
	ldrb r0, [r5, 0x8]
	cmp r0, 0
	beq _08071630
	movs r5, 0
	cmp r0, 0x3
	bne _08071638
	movs r5, 0x1
	b _08071638
_08071630:
	ldrb r1, [r5, 0x6]
	negs r0, r1
	orrs r0, r1
	lsrs r5, r0, 31
_08071638:
	ldrb r0, [r4, 0x8]
	cmp r0, 0
	beq _08071648
	movs r1, 0
	cmp r0, 0x3
	bne _08071650
	movs r1, 0x1
	b _08071650
_08071648:
	ldrb r1, [r4, 0x6]
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
_08071650:
	movs r3, 0
	adds r0, r4, 0
	adds r0, 0xC8
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _0807165E
	movs r3, 0x1
_0807165E:
	ldr r2, _08071678
	lsls r0, r1, 1
	adds r0, r3, r0
	lsls r1, r5, 2
	adds r0, r1
	lsls r1, r6, 3
	adds r0, r1
	adds r0, r2
	ldrb r0, [r0]
_08071670:
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08071678: .4byte gUnknown_8106FE5
	thumb_func_end sub_8071598

	thumb_func_start sub_807167C
sub_807167C:
	push {lr}
	ldr r2, [r0, 0x70]
	ldr r1, [r1, 0x70]
	adds r0, r2, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080716D2
	adds r0, r2, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _0807169A
	cmp r0, 0x47
	bne _0807169E
_0807169A:
	movs r0, 0x1
	b _080716A0
_0807169E:
	movs r0, 0
_080716A0:
	cmp r0, 0
	bne _080716D2
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	bne _080716D2
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080716D2
	adds r0, r1, 0
	adds r0, 0x40
	ldrb r0, [r0]
	cmp r0, 0x4A
	beq _080716C2
	cmp r0, 0x47
	bne _080716C6
_080716C2:
	movs r0, 0x1
	b _080716C8
_080716C6:
	movs r0, 0
_080716C8:
	cmp r0, 0
	bne _080716D2
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _080716D6
_080716D2:
	movs r0, 0x2
	b _080716E4
_080716D6:
	ldrb r0, [r2, 0x6]
	ldrb r1, [r1, 0x6]
	cmp r0, r1
	bne _080716E2
	movs r0, 0
	b _080716E4
_080716E2:
	movs r0, 0x1
_080716E4:
	pop {r1}
	bx r1
	thumb_func_end sub_807167C

	thumb_func_start sub_80716E8
sub_80716E8:
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, [r4, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08071720
	cmp r2, 0
	beq _08071714
	ldr r0, _08071718
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _0807171C
	ldr r2, [r0]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80522F4
_08071714:
	movs r0, 0x1
	b _08071722
	.align 2, 0
_08071718: .4byte gAvailablePokemonNames
_0807171C: .4byte gUnknown_80FC2FC
_08071720:
	movs r0, 0
_08071722:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80716E8

	thumb_func_start sub_8071728
sub_8071728:
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r1, 0
	lsls r2, 24
	lsrs r2, 24
	adds r5, r2, 0
	ldr r0, [r4, 0x70]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _08071758
	cmp r2, 0
	beq _0807178E
	ldr r0, _08071750
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08071754
	b _08071784
	.align 2, 0
_08071750: .4byte gAvailablePokemonNames
_08071754: .4byte gUnknown_80FC31C
_08071758:
	adds r0, r4, 0
	movs r1, 0xF
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _08071774
	adds r0, r4, 0
	movs r1, 0x18
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0807179C
_08071774:
	cmp r5, 0
	beq _0807178E
	ldr r0, _08071794
	adds r1, r4, 0
	movs r2, 0
	bl SetMessageArgument
	ldr r0, _08071798
_08071784:
	ldr r2, [r0]
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_80522F4
_0807178E:
	movs r0, 0x1
	b _0807179E
	.align 2, 0
_08071794: .4byte gAvailablePokemonNames
_08071798: .4byte gUnknown_80FCEFC
_0807179C:
	movs r0, 0
_0807179E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8071728

	thumb_func_start sub_80717A4
sub_80717A4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	mov r8, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldr r6, [r0, 0x70]
	adds r0, r6, 0
	adds r0, 0xA8
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080717CE
	cmp r0, 0x5
	beq _080717CE
	cmp r0, 0x3
	beq _080717CE
	b _08071816
_080717CA:
	movs r0, 0x1
	b _08071818
_080717CE:
	movs r7, 0
	movs r0, 0x8C
	lsls r0, 1
	adds r4, r6, r0
	adds r5, r4, 0
_080717D8:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0807180C
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _080717F0
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0807180C
_080717F0:
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0x1
	bl sub_805744C
	lsls r0, 24
	cmp r0, 0
	beq _0807180C
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _0807180C
	ldrh r0, [r4, 0x2]
	cmp r0, r9
	beq _080717CA
_0807180C:
	adds r4, 0x8
	adds r5, 0x8
	adds r7, 0x1
	cmp r7, 0x3
	ble _080717D8
_08071816:
	movs r0, 0
_08071818:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80717A4

	.align 2, 0