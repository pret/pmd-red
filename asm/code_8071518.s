	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start CheckRunAwayVisualFlag
CheckRunAwayVisualFlag:
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
	bl SetVisualFlags
	lsls r0, 24
	lsrs r0, 24
	cmp r7, 0
	beq _08071590
	cmp r0, 0
	beq _08071590
	adds r0, r5, 0
	bl ShowVisualFlags
_08071590:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CheckRunAwayVisualFlag

	thumb_func_start CanTarget
CanTarget:
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
	bl CanSeeInvisible
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
	thumb_func_end CanTarget

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

	.align 2, 0
