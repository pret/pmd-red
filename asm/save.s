	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8011F9C
sub_8011F9C:
	push {lr}
	bl ReadSaveSector
	pop {r1}
	bx r1
	thumb_func_end sub_8011F9C

	thumb_func_start sub_8011FA8
sub_8011FA8:
	push {r4,r5,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r5, r0, 0
	movs r0, 0x1F
	str r0, [sp]
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	bl ReadSaveSector
	adds r2, r0, 0
	cmp r2, 0
	bne _08011FD8
	ldr r1, [r5, 0x14]
	ldr r0, _08011FF0
	cmp r1, r0
	beq _08011FD8
	movs r2, 0x4
_08011FD8:
	ldr r4, _08011FF4
	cmp r2, 0
	bne _08011FE0
	ldr r4, [r5, 0x18]
_08011FE0:
	adds r0, r5, 0
	bl MemoryFree
	adds r0, r4, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08011FF0: .4byte 0x05071412
_08011FF4: .4byte 0x000f1209
	thumb_func_end sub_8011FA8

	thumb_func_start sub_8011FF8
sub_8011FF8:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r5, r0, 0
	movs r0, 0x1F
	str r0, [sp]
	movs r6, 0
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	bl ReadSaveSector
	cmp r0, 0
	bne _08012028
	ldr r1, [r5, 0x14]
	ldr r0, _08012038
	cmp r1, r0
	bne _08012028
	movs r6, 0x1
_08012028:
	adds r0, r5, 0
	bl MemoryFree
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08012038: .4byte 0x05071412
	thumb_func_end sub_8011FF8

	thumb_func_start sub_801203C
sub_801203C:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _08012078
	movs r1, 0x5
	bl MemoryAlloc
	adds r6, r0, 0
	movs r0, 0x89
	lsls r0, 3
	adds r5, r6, r0
	ldr r0, _0801207C
	ldr r2, [r0]
	cmp r2, 0
	bne _08012084
	ldr r1, _08012080
	adds r0, r6, r1
	str r4, [r0]
	bl sub_8011C34
	movs r2, 0x83
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	bl GetRngState
	movs r2, 0x84
	lsls r2, 3
	adds r1, r6, r2
	b _0801209E
	.align 2, 0
_08012078: .4byte 0x000057d4
_0801207C: .4byte gUnknown_203B184
_08012080: .4byte 0x0000041c
_08012084:
	ldr r0, _080120C8
	adds r1, r6, r0
	ldr r0, [r2, 0x54]
	str r0, [r1]
	movs r0, 0x83
	lsls r0, 3
	adds r1, r6, r0
	ldr r0, [r2, 0x50]
	str r0, [r1]
	movs r0, 0x84
	lsls r0, 3
	adds r1, r6, r0
	ldr r0, [r2, 0x58]
_0801209E:
	str r0, [r1]
	ldr r2, _080120CC
	adds r1, r6, r2
	ldr r0, _080120D0
	str r0, [r1]
	bl sub_8011C4C
	adds r1, r0, 0
	ldr r2, _080120D4
	adds r0, r6, r2
	movs r2, 0x10
	bl strncpy
	ldr r0, _080120D8
	ldr r1, [r0]
	cmp r1, 0
	bne _080120DC
	adds r0, r6, 0x4
	bl sub_8002700
	b _080120E8
	.align 2, 0
_080120C8: .4byte 0x0000041c
_080120CC: .4byte 0x00000414
_080120D0: .4byte 0x05071412
_080120D4: .4byte 0x00000404
_080120D8: .4byte gUnknown_203B184
_080120DC:
	adds r0, r6, 0x4
	ldr r1, [r1, 0x4C]
	movs r2, 0x80
	lsls r2, 3
	bl MemoryCopy8
_080120E8:
	ldr r4, _080121A4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808ED78
	ldr r2, _080121A8
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	movs r4, 0x96
	lsls r4, 2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808F154
	movs r2, 0x85
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	subs r4, 0x80
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8091C68
	movs r2, 0x86
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	adds r0, r5, 0
	movs r1, 0x10
	bl sub_80921C4
	ldr r2, _080121AC
	adds r1, r6, r2
	str r0, [r1]
	adds r5, 0x10
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_80927A8
	movs r2, 0x87
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, 0x8
	subs r4, 0xD8
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8097D60
	ldr r2, _080121B0
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	ldr r4, _080121B4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8095624
	movs r2, 0x88
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	ldr r1, _080121B8
	adds r0, r5, 0
	bl sub_80970D8
	ldr r2, _080121BC
	adds r1, r6, r2
	str r0, [r1]
	ldr r4, _080121C0
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl WriteSaveSector
	adds r5, r0, 0
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl WriteSaveSector
	adds r4, r0, 0
	adds r0, r6, 0
	bl MemoryFree
	cmp r5, 0
	beq _080121C4
	adds r0, r5, 0
	b _080121CE
	.align 2, 0
_080121A4: .4byte 0x00004650
_080121A8: .4byte 0x00000424
_080121AC: .4byte 0x00000434
_080121B0: .4byte 0x0000043c
_080121B4: .4byte 0x00000594
_080121B8: .4byte 0x00000221
_080121BC: .4byte 0x00000444
_080121C0: .4byte 0x000057d4
_080121C4:
	cmp r4, 0
	bne _080121CC
	movs r0, 0
	b _080121CE
_080121CC:
	adds r0, r4, 0
_080121CE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801203C

	thumb_func_start sub_80121D4
sub_80121D4:
	push {lr}
	bl WriteSaveSector
	pop {r1}
	bx r1
	thumb_func_end sub_80121D4

	thumb_func_start sub_80121E0
sub_80121E0:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0x80
	lsls r6, 4
	adds r0, r6, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r4, r0, 0
	movs r0, 0x1F
	str r0, [sp]
	str r5, [r4, 0x18]
	bl sub_809769C
	ldr r0, [r0]
	str r0, [r4, 0x1C]
	ldr r0, _0801223C
	str r0, [r4, 0x14]
	bl sub_8011C4C
	adds r1, r0, 0
	adds r0, r4, 0x4
	movs r2, 0x10
	bl strncpy
	adds r0, r4, 0
	adds r0, 0x20
	movs r1, 0
	bl sub_80958E4
	mov r0, sp
	adds r1, r4, 0
	adds r2, r6, 0
	bl WriteSaveSector
	adds r5, r0, 0
	adds r0, r4, 0
	bl MemoryFree
	adds r0, r5, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801223C: .4byte 0x05071412
	thumb_func_end sub_80121E0

	thumb_func_start sub_8012240
sub_8012240:
	push {r4,r5,lr}
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r5, r0, 0
	movs r1, 0xFF
	movs r2, 0x4
	bl MemoryFill8
	bl sub_8011830
	movs r0, 0x1F
	adds r1, r5, 0
	adds r2, r4, 0
	bl WriteFlashData
	adds r4, r0, 0
	bl sub_8011854
	adds r0, r5, 0
	bl MemoryFree
	cmp r4, 0
	bne _0801227A
	movs r0, 0
	b _0801227C
_0801227A:
	movs r0, 0x2
_0801227C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8012240

	thumb_func_start sub_8012284
sub_8012284:
	push {lr}
	bl sub_80122D0
	bl sub_80122F4
	bl sub_8012300
	pop {r0}
	bx r0
	thumb_func_end sub_8012284

	thumb_func_start sub_8012298
sub_8012298:
	push {lr}
	bl sub_80976A8
	bl sub_80122A8
	pop {r0}
	bx r0
	thumb_func_end sub_8012298

	thumb_func_start sub_80122A8
sub_80122A8:
	push {lr}
	bl sub_80122D0
	bl sub_80122F4
	bl sub_8012300
	bl sub_8012240
	pop {r0}
	bx r0
	thumb_func_end sub_80122A8

	thumb_func_start nullsub_33
nullsub_33:
	bx lr
	thumb_func_end nullsub_33

	thumb_func_start sub_80122C4
sub_80122C4:
	push {lr}
	bl sub_80122A8
	pop {r0}
	bx r0
	thumb_func_end sub_80122C4

	thumb_func_start sub_80122D0
sub_80122D0:
	push {lr}
	movs r0, 0
	bl sub_8011C28
	movs r0, 0x1
	negs r0, r0
	bl sub_8011C40
	bl sub_8097748
	ldr r0, _080122F0
	ldr r0, [r0]
	bl sub_8094FA8
	pop {r0}
	bx r0
	.align 2, 0
_080122F0: .4byte gUnknown_203B47C
	thumb_func_end sub_80122D0

	thumb_func_start sub_80122F4
sub_80122F4:
	push {lr}
	bl sub_800135C
	pop {r0}
	bx r0
	thumb_func_end sub_80122F4

	thumb_func_start sub_8012300
sub_8012300:
	push {lr}
	bl sub_80923B8
	bl sub_808CE08
	bl sub_80909D8
	bl sub_8092094
	bl sub_80972F4
	bl sub_8095118
	bl sub_8095900
	bl sub_80974E8
	movs r0, 0x1
	bl sub_8094998
	bl sub_8097F74
	pop {r0}
	bx r0
	thumb_func_end sub_8012300

	thumb_func_start nullsub_200
nullsub_200:
	bx lr
	thumb_func_end nullsub_200

	thumb_func_start sub_8012334
sub_8012334:
	push {lr}
	adds r2, r0, 0
	ldr r0, _08012390
	str r2, [r0]
	cmp r2, 0
	beq _080123C8
	ldr r1, _08012394
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, _08012398
	ldr r0, [r2, 0x4]
	str r0, [r1]
	ldr r1, _0801239C
	ldr r0, [r2, 0x8]
	str r0, [r1]
	ldr r1, _080123A0
	ldr r0, [r2, 0xC]
	str r0, [r1]
	ldr r1, _080123A4
	ldr r0, [r2, 0x10]
	str r0, [r1]
	ldr r1, _080123A8
	ldr r0, [r2, 0x14]
	str r0, [r1]
	ldr r1, _080123AC
	ldr r0, [r2, 0x18]
	str r0, [r1]
	ldr r1, _080123B0
	ldr r0, [r2, 0x1C]
	str r0, [r1]
	ldr r1, _080123B4
	ldr r0, [r2, 0x20]
	str r0, [r1]
	ldr r1, _080123B8
	ldr r0, [r2, 0x24]
	str r0, [r1]
	ldr r1, _080123BC
	ldr r0, [r2, 0x28]
	str r0, [r1]
	ldr r1, _080123C0
	ldr r0, [r2, 0x2C]
	str r0, [r1]
	ldr r1, _080123C4
	ldr r0, [r2, 0x30]
	b _0801242E
	.align 2, 0
_08012390: .4byte gUnknown_203B184
_08012394: .4byte gUnknown_203B460
_08012398: .4byte gUnknown_203B45C
_0801239C: .4byte gUnknown_203B480
_080123A0: .4byte gUnknown_203B484
_080123A4: .4byte gUnknown_203B488
_080123A8: .4byte gUnknown_203B48C
_080123AC: .4byte gUnknown_203B490
_080123B0: .4byte gUnknown_203B464
_080123B4: .4byte gUnknown_203B494
_080123B8: .4byte gUnknown_203B498
_080123BC: .4byte gUnknown_203B468
_080123C0: .4byte gUnknown_203B46C
_080123C4: .4byte gUnknown_203B47C
_080123C8:
	bl sub_80909D0
	ldr r1, _08012434
	str r0, [r1]
	bl sub_808CE00
	ldr r1, _08012438
	str r0, [r1]
	bl sub_80950F8
	ldr r1, _0801243C
	str r0, [r1]
	bl sub_8095100
	ldr r1, _08012440
	str r0, [r1]
	bl sub_8095108
	ldr r1, _08012444
	str r0, [r1]
	bl sub_8095110
	ldr r1, _08012448
	str r0, [r1]
	bl sub_80958F8
	ldr r1, _0801244C
	str r0, [r1]
	bl sub_809208C
	ldr r1, _08012450
	str r0, [r1]
	bl sub_8097680
	ldr r1, _08012454
	str r0, [r1]
	bl sub_8097F6C
	ldr r1, _08012458
	str r0, [r1]
	bl sub_80923B0
	ldr r1, _0801245C
	str r0, [r1]
	bl sub_8094990
	ldr r1, _08012460
	str r0, [r1]
	bl sub_8094FA0
	ldr r1, _08012464
_0801242E:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08012434: .4byte gUnknown_203B460
_08012438: .4byte gUnknown_203B45C
_0801243C: .4byte gUnknown_203B480
_08012440: .4byte gUnknown_203B484
_08012444: .4byte gUnknown_203B488
_08012448: .4byte gUnknown_203B48C
_0801244C: .4byte gUnknown_203B490
_08012450: .4byte gUnknown_203B464
_08012454: .4byte gUnknown_203B494
_08012458: .4byte gUnknown_203B498
_0801245C: .4byte gUnknown_203B468
_08012460: .4byte gUnknown_203B46C
_08012464: .4byte gUnknown_203B47C
	thumb_func_end sub_8012334

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

	.align 2, 0 @ Don't pad with nop.
