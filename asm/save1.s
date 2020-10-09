	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text	

        thumb_func_start sub_8012468
sub_8012468:
	push {r4,lr}
	ldr r4, _08012480
	movs r0, 0x8
	movs r1, 0x5
	bl MemoryAlloc
	str r0, [r4]
	movs r1, 0x1
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012480: .4byte gUnknown_203B188
	thumb_func_end sub_8012468

	thumb_func_start sub_8012484
sub_8012484:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r1, _080124A0
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x6
	bhi _0801254C
	lsls r0, 2
	ldr r1, _080124A4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080124A0: .4byte gUnknown_203B188
_080124A4: .4byte _080124A8
	.align 2, 0
_080124A8:
	.4byte _080124C4
	.4byte _080124CC
	.4byte _080124E8
	.4byte _0801251C
	.4byte _08012534
	.4byte _0801254C
	.4byte _08012548
_080124C4:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
	b _0801254C
_080124CC:
	movs r0, 0
	str r0, [sp]
	mov r0, sp
	bl sub_8011DAC
	ldr r1, _080124E4
	ldr r1, [r1]
	str r0, [r1, 0x4]
	movs r0, 0x2
	str r0, [r1]
	b _0801254C
	.align 2, 0
_080124E4: .4byte gUnknown_203B188
_080124E8:
	adds r5, r4, 0
	ldr r1, [r5]
	ldr r0, [r1, 0x4]
	cmp r0, 0
	beq _0801253C
	bl sub_8011FF8
	lsls r0, 24
	cmp r0, 0
	beq _08012518
	ldr r0, _08012510
	ldr r3, _08012514
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1]
	b _0801254C
	.align 2, 0
_08012510: .4byte gUnknown_80D4354
_08012514: .4byte 0x00000301
_08012518:
	ldr r1, [r4]
	b _0801252A
_0801251C:
	add r0, sp, 0x4
	bl sub_80144A4
	cmp r0, 0
	bne _0801254C
	ldr r0, _08012530
	ldr r1, [r0]
_0801252A:
	movs r0, 0x4
	str r0, [r1]
	b _0801254C
	.align 2, 0
_08012530: .4byte gUnknown_203B188
_08012534:
	bl sub_8012298
	ldr r0, _08012544
	ldr r1, [r0]
_0801253C:
	movs r0, 0x6
	str r0, [r1]
	b _0801254C
	.align 2, 0
_08012544: .4byte gUnknown_203B188
_08012548:
	movs r0, 0
	b _0801254E
_0801254C:
	movs r0, 0x1
_0801254E:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8012484

	thumb_func_start sub_8012558
sub_8012558:
	push {r4,lr}
	ldr r4, _08012570
	ldr r0, [r4]
	cmp r0, 0
	beq _0801256A
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801256A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012570: .4byte gUnknown_203B188
	thumb_func_end sub_8012558

	thumb_func_start sub_8012574
sub_8012574:
	push {r4-r6,lr}
	lsls r0, 16
	asrs r4, r0, 16
	bl sub_80993D8
	ldr r5, _080125D4
	movs r0, 0x20
	movs r1, 0x5
	bl MemoryAlloc
	str r0, [r5]
	movs r6, 0
	movs r1, 0
	strh r4, [r0, 0x1C]
	str r1, [r0, 0xC]
	str r1, [r0, 0x10]
	cmp r4, 0
	beq _080125BA
	adds r0, r4, 0
	bl sub_808DDD0
	ldr r1, [r5]
	str r0, [r1, 0xC]
	ldr r0, [r0, 0x4]
	str r0, [r1, 0x10]
	strb r6, [r1, 0x18]
	ldr r0, [r5]
	strb r6, [r0, 0x19]
	ldr r0, [r5]
	strb r6, [r0, 0x1A]
	ldr r1, [r5]
	movs r0, 0x2
	strh r0, [r1, 0x14]
	movs r0, 0x8
	strh r0, [r1, 0x16]
_080125BA:
	ldr r1, [r5]
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _080125DC
	adds r2, r1, 0
	adds r2, 0xC
	ldr r0, _080125D8
	movs r1, 0
	movs r3, 0x20
	bl sub_80141B4
	b _080125E8
	.align 2, 0
_080125D4: .4byte gUnknown_203B18C
_080125D8: .4byte gUnknown_80D4398
_080125DC:
	ldr r0, _080125F8
	movs r1, 0
	movs r2, 0
	movs r3, 0x20
	bl sub_80141B4
_080125E8:
	ldr r0, _080125FC
	ldr r1, [r0]
	movs r0, 0x3
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080125F8: .4byte gUnknown_80D4398
_080125FC: .4byte gUnknown_203B18C
	thumb_func_end sub_8012574

	thumb_func_start sub_8012600
sub_8012600:
	push {r4,r5,lr}
	sub sp, 0x8
	movs r5, 0
	ldr r0, _08012628
	ldr r2, [r0]
	ldr r1, [r2, 0xC]
	adds r4, r0, 0
	cmp r1, 0
	beq _08012616
	adds r5, r2, 0
	adds r5, 0xC
_08012616:
	ldr r0, [r2]
	cmp r0, 0x7
	bls _0801261E
	b _08012738
_0801261E:
	lsls r0, 2
	ldr r1, _0801262C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08012628: .4byte gUnknown_203B18C
_0801262C: .4byte _08012630
	.align 2, 0
_08012630:
	.4byte _08012650
	.4byte _08012654
	.4byte _08012738
	.4byte _08012678
	.4byte _08012680
	.4byte _0801271C
	.4byte _08012738
	.4byte _08012734
_08012650:
	ldr r1, [r4]
	b _0801272A
_08012654:
	ldr r1, [r4]
	ldr r0, [r1, 0x4]
	adds r0, 0x1
	str r0, [r1, 0x4]
	cmp r0, 0x8
	ble _08012738
	ldr r0, _08012674
	movs r1, 0
	movs r2, 0
	movs r3, 0x20
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x3
	str r0, [r1]
	b _08012738
	.align 2, 0
_08012674: .4byte gUnknown_80D43D8
_08012678:
	ldr r1, [r4]
	movs r0, 0x4
	str r0, [r1]
	b _08012738
_08012680:
	movs r0, 0
	str r0, [sp]
	bl sub_80140DC
	bl sub_8011C1C
	adds r1, r0, 0
	mov r0, sp
	bl sub_801203C
	ldr r4, _080126B8
	ldr r1, [r4]
	str r0, [r1, 0x8]
	cmp r0, 0
	beq _080126C4
	cmp r0, 0x1
	beq _080126DC
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _080126F4
	ldr r0, _080126BC
_080126AA:
	ldr r3, _080126C0
	movs r1, 0
	adds r2, r5, 0
	bl sub_80141B4
	b _08012700
	.align 2, 0
_080126B8: .4byte gUnknown_203B18C
_080126BC: .4byte gUnknown_80D44B0
_080126C0: .4byte 0x00000101
_080126C4:
	ldr r0, [r1, 0xC]
	cmp r0, 0
	beq _080126D4
	ldr r0, _080126D0
	b _080126AA
	.align 2, 0
_080126D0: .4byte gUnknown_80D4438
_080126D4:
	ldr r0, _080126D8
	b _080126F6
	.align 2, 0
_080126D8: .4byte gUnknown_80D4438
_080126DC:
	ldr r0, _080126F0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x6
	b _08012706
	.align 2, 0
_080126F0: .4byte gUnknown_80D444C
_080126F4:
	ldr r0, _08012710
_080126F6:
	ldr r3, _08012714
	movs r1, 0
	adds r2, r5, 0
	bl sub_80141B4
_08012700:
	ldr r0, _08012718
	ldr r1, [r0]
	movs r0, 0x5
_08012706:
	str r0, [r1]
	bl sub_8014114
	b _08012738
	.align 2, 0
_08012710: .4byte gUnknown_80D44B0
_08012714: .4byte 0x00000101
_08012718: .4byte gUnknown_203B18C
_0801271C:
	add r0, sp, 0x4
	bl sub_80144A4
	cmp r0, 0
	bne _08012738
	ldr r0, _08012730
	ldr r1, [r0]
_0801272A:
	movs r0, 0x7
	str r0, [r1]
	b _08012738
	.align 2, 0
_08012730: .4byte gUnknown_203B18C
_08012734:
	movs r0, 0
	b _0801273A
_08012738:
	movs r0, 0x1
_0801273A:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8012600

	thumb_func_start sub_8012744
sub_8012744:
	ldr r0, _0801274C
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bx lr
	.align 2, 0
_0801274C: .4byte gUnknown_203B18C
	thumb_func_end sub_8012744

	thumb_func_start sub_8012750
sub_8012750:
	push {r4,lr}
	ldr r4, _08012778
	ldr r0, [r4]
	cmp r0, 0
	beq _0801276E
	ldr r0, [r0, 0xC]
	cmp r0, 0
	beq _08012764
	bl CloseFile
_08012764:
	ldr r0, [r4]
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_0801276E:
	bl sub_80993E4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012778: .4byte gUnknown_203B18C
	thumb_func_end sub_8012750

	thumb_func_start sub_801277C
sub_801277C:
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	ldr r4, _080127A4
	movs r0, 0x10
	movs r1, 0x5
	bl MemoryAlloc
	str r0, [r4]
	str r5, [r0, 0x4]
	str r6, [r0, 0x8]
	movs r1, 0
	strb r1, [r0, 0xC]
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080127A4: .4byte gUnknown_203B190
	thumb_func_end sub_801277C

	thumb_func_start sub_80127A8
sub_80127A8:
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, _080127C0
	ldr r2, [r5]
	ldr r4, [r2]
	cmp r4, 0x1
	beq _080127D4
	cmp r4, 0x1
	bgt _080127C4
	cmp r4, 0
	beq _080127CE
	b _0801281E
	.align 2, 0
_080127C0: .4byte gUnknown_203B190
_080127C4:
	cmp r4, 0x2
	beq _08012808
	cmp r4, 0x3
	beq _0801281A
	b _0801281E
_080127CE:
	movs r0, 0x1
	str r0, [r2]
	b _0801281E
_080127D4:
	movs r0, 0x10
	str r0, [sp]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	mov r0, sp
	bl sub_8011F9C
	cmp r0, 0
	bne _080127EC
	ldr r0, [r5]
	strb r4, [r0, 0xC]
	b _08012812
_080127EC:
	ldr r0, _08012800
	ldr r3, _08012804
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	ldr r1, [r5]
	movs r0, 0x2
	str r0, [r1]
	b _0801281E
	.align 2, 0
_08012800: .4byte gUnknown_80D44C8
_08012804: .4byte 0x00000301
_08012808:
	add r0, sp, 0x4
	bl sub_80144A4
	cmp r0, 0
	bne _0801281E
_08012812:
	ldr r1, [r5]
	movs r0, 0x3
	str r0, [r1]
	b _0801281E
_0801281A:
	movs r0, 0
	b _08012820
_0801281E:
	movs r0, 0x1
_08012820:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80127A8

	thumb_func_start sub_8012828
sub_8012828:
	ldr r0, _08012830
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bx lr
	.align 2, 0
_08012830: .4byte gUnknown_203B190
	thumb_func_end sub_8012828

	thumb_func_start sub_8012834
sub_8012834:
	push {r4,lr}
	ldr r4, _0801284C
	ldr r0, [r4]
	cmp r0, 0
	beq _08012846
	bl MemoryFree
	movs r0, 0
	str r0, [r4]
_08012846:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801284C: .4byte gUnknown_203B190
	thumb_func_end sub_8012834

	thumb_func_start sub_8012850
sub_8012850:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	mov r8, r1
	lsls r4, r2, 24
	lsrs r4, 24
	ldr r5, _0801288C
	movs r0, 0x14
	movs r1, 0x5
	bl MemoryAlloc
	str r0, [r5]
	str r6, [r0, 0x4]
	mov r1, r8
	str r1, [r0, 0x8]
	movs r1, 0
	strb r4, [r0, 0xC]
	ldr r0, [r5]
	str r1, [r0]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	beq _08012894
	ldr r0, _08012890
	movs r2, 0
	movs r3, 0x20
	bl sub_80141B4
	b _080128A0
	.align 2, 0
_0801288C: .4byte gUnknown_203B194
_08012890: .4byte gUnknown_80D45AC
_08012894:
	ldr r0, _080128AC
	movs r1, 0
	movs r2, 0
	movs r3, 0x20
	bl sub_80141B4
_080128A0:
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080128AC: .4byte gUnknown_80D45AC
	thumb_func_end sub_8012850

	thumb_func_start sub_80128B0
sub_80128B0:
	push {r4,lr}
	sub sp, 0x8
	ldr r1, _080128CC
	ldr r0, [r1]
	ldr r0, [r0]
	adds r4, r1, 0
	cmp r0, 0x5
	bls _080128C2
	b _080129F0
_080128C2:
	lsls r0, 2
	ldr r1, _080128D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080128CC: .4byte gUnknown_203B194
_080128D0: .4byte _080128D4
	.align 2, 0
_080128D4:
	.4byte _080128EC
	.4byte _080128F4
	.4byte _0801291C
	.4byte _080129C8
	.4byte _080129F0
	.4byte _080129E0
_080128EC:
	ldr r1, [r4]
	movs r0, 0x1
	str r0, [r1]
	b _080129F0
_080128F4:
	bl sub_80140DC
	movs r0, 0x10
	str r0, [sp]
	ldr r4, _08012918
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	ldr r2, [r0, 0x8]
	mov r0, sp
	bl sub_80121D4
	ldr r1, [r4]
	str r0, [r1, 0x10]
	movs r0, 0x2
	str r0, [r1]
	movs r0, 0x1
	b _080129F2
	.align 2, 0
_08012918: .4byte gUnknown_203B194
_0801291C:
	movs r0, 0
	str r0, [sp]
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	bne _08012934
	mov r0, sp
	movs r1, 0x2
	bl sub_801203C
	ldr r1, [r4]
	str r0, [r1, 0x10]
_08012934:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	beq _08012964
	cmp r0, 0x1
	beq _080129AC
	ldr r0, _08012958
	bl sub_80121E0
	ldr r0, _0801295C
	ldr r3, _08012960
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x3
	b _080129BC
	.align 2, 0
_08012958: .4byte 0x000f1209
_0801295C: .4byte gUnknown_80D47A0
_08012960: .4byte 0x00000301
_08012964:
	ldr r0, _08012980
	bl sub_80121E0
	ldr r0, [r4]
	ldrb r0, [r0, 0xC]
	cmp r0, 0
	beq _0801298C
	ldr r0, _08012984
	ldr r3, _08012988
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
	b _08012998
	.align 2, 0
_08012980: .4byte 0x000f1207
_08012984: .4byte gUnknown_80D45F4
_08012988: .4byte 0x00000301
_0801298C:
	ldr r0, _080129A0
	ldr r3, _080129A4
	movs r1, 0
	movs r2, 0
	bl sub_80141B4
_08012998:
	ldr r0, _080129A8
	ldr r1, [r0]
	movs r0, 0x3
	b _080129BC
	.align 2, 0
_080129A0: .4byte gUnknown_80D4668
_080129A4: .4byte 0x00000301
_080129A8: .4byte gUnknown_203B194
_080129AC:
	ldr r0, _080129C4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_80141B4
	ldr r1, [r4]
	movs r0, 0x4
_080129BC:
	str r0, [r1]
	bl sub_8014114
	b _080129F0
	.align 2, 0
_080129C4: .4byte gUnknown_80D473C
_080129C8:
	add r0, sp, 0x4
	bl sub_80144A4
	cmp r0, 0
	bne _080129F0
	ldr r0, _080129DC
	ldr r1, [r0]
	movs r0, 0x5
	str r0, [r1]
	b _080129F0
	.align 2, 0
_080129DC: .4byte gUnknown_203B194
_080129E0:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	cmp r0, 0
	bne _080129EC
	movs r0, 0x2
	b _080129F2
_080129EC:
	movs r0, 0x3
	b _080129F2
_080129F0:
	movs r0, 0
_080129F2:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80128B0

        .align 2,0
