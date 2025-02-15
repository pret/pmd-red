	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_801560C
sub_801560C:
	push {r4-r6,lr}
	ldr r3, _08015640
	ldr r4, _08015644
	ldr r5, [r4]
	ldrb r0, [r5, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r5, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r3, 0x8
	adds r0, r3
	ldr r6, [r0]
	movs r0, 0x83
	lsls r0, 1
	cmp r6, r0
	beq _0801567A
	cmp r6, r0
	bgt _08015648
	subs r0, 0x1
	cmp r6, r0
	beq _0801566C
	b _080156BC
	.align 2, 0
_08015640: .4byte gUnknown_80DB0F8
_08015644: .4byte gUnknown_203B1FC
_08015648:
	ldr r0, _08015668
	cmp r6, r0
	bne _080156BC
	movs r1, 0
	ldrb r0, [r5, 0x18]
	cmp r0, 0
	bne _08015658
	movs r1, 0x1
_08015658:
	strb r1, [r5, 0x18]
	movs r0, 0x4
	bl PlayMenuSoundEffect
	movs r0, 0
	bl sub_8015A08
	b _0801573E
	.align 2, 0
_08015668: .4byte 0x00000107
_0801566C:
	bl sub_8015748
	lsls r0, 24
	cmp r0, 0
	beq _0801573E
	movs r0, 0x2
	b _08015740
_0801567A:
	bl sub_8015F44
	cmp r0, 0
	beq _080156D4
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08015696
	bl sub_8015F44
	ldr r1, [r4]
	ldrb r1, [r1, 0x1B]
	cmp r0, r1
	bne _080156D4
_08015696:
	movs r0, 0
	bl PlayMenuSoundEffect
	ldr r0, _080156B8
	ldr r2, [r0]
	movs r1, 0x9A
	lsls r1, 1
	adds r0, r2, r1
	ldr r0, [r0]
	adds r1, r2, 0
	adds r1, 0xF8
	ldr r1, [r1]
	ldrb r2, [r2, 0x1B]
	bl MemoryCopy8
	movs r0, 0x3
	b _08015740
	.align 2, 0
_080156B8: .4byte gUnknown_203B1FC
_080156BC:
	ldr r0, [r4]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _080156DC
	lsls r0, r6, 24
	lsrs r0, 24
	bl sub_803D0F0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080156DC
_080156D4:
	movs r0, 0x2
	bl PlayMenuSoundEffect
	b _0801573E
_080156DC:
	ldr r0, _08015728
	ldr r3, [r0]
	ldrb r1, [r3, 0x18]
	adds r4, r0, 0
	cmp r1, 0x1
	bne _0801570A
	ldrb r0, [r3, 0x1B]
	subs r2, r0, 0x2
	ldrb r3, [r3, 0x1C]
	cmp r2, r3
	blt _0801570A
	adds r3, r4, 0
_080156F4:
	ldr r0, [r3]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r2
	ldrb r1, [r0]
	strb r1, [r0, 0x1]
	subs r2, 0x1
	ldr r0, [r3]
	ldrb r0, [r0, 0x1C]
	cmp r2, r0
	bge _080156F4
_0801570A:
	ldr r0, [r4]
	ldrb r1, [r0, 0x1C]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r1
	strb r6, [r0]
	ldr r1, [r4]
	ldrb r2, [r1, 0x1C]
	ldrb r0, [r1, 0x1B]
	subs r0, 0x1
	cmp r2, r0
	bge _0801572C
	adds r0, r2, 0x1
	strb r0, [r1, 0x1C]
	b _08015730
	.align 2, 0
_08015728: .4byte gUnknown_203B1FC
_0801572C:
	movs r0, 0x5
	strb r0, [r1, 0x1A]
_08015730:
	movs r0, 0
	bl PlayMenuSoundEffect
	bl sub_8015C1C
	bl sub_8015F84
_0801573E:
	movs r0, 0
_08015740:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_801560C

	thumb_func_start sub_8015748
sub_8015748:
	push {r4,lr}
	ldr r4, _0801576C
	ldr r2, [r4]
	ldrb r1, [r2, 0x1C]
	adds r0, r2, 0
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _08015790
	cmp r1, 0
	bne _08015770
	movs r0, 0x2
	bl PlayMenuSoundEffect
	movs r0, 0x1
	b _080157CE
	.align 2, 0
_0801576C: .4byte gUnknown_203B1FC
_08015770:
	subs r0, r1, 0x1
	strb r0, [r2, 0x1C]
	ldr r0, [r4]
	ldrb r1, [r0, 0x1C]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r1
	strb r3, [r0]
	movs r0, 0x1
	bl PlayMenuSoundEffect
	bl sub_8015C1C
	bl sub_8015F84
	b _080157CC
_08015790:
	bl sub_8015F44
	subs r3, r0, 0x1
	ldr r0, [r4]
	ldrb r2, [r0, 0x1C]
	cmp r2, r3
	bge _080157B0
_0801579E:
	ldr r0, [r4]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r2
	ldrb r1, [r0, 0x1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r3
	blt _0801579E
_080157B0:
	ldr r0, _080157D4
	ldr r0, [r0]
	adds r0, 0xF8
	ldr r0, [r0]
	adds r0, r3
	movs r1, 0
	strb r1, [r0]
	movs r0, 0x1
	bl PlayMenuSoundEffect
	bl sub_8015C1C
	bl sub_8015F84
_080157CC:
	movs r0, 0
_080157CE:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080157D4: .4byte gUnknown_203B1FC
	thumb_func_end sub_8015748

	thumb_func_start sub_80157D8
sub_80157D8:
	push {r4,r5,lr}
	ldr r5, _080157EC
	ldr r0, _080157F0
	ldr r0, [r0]
	mov r12, r0
	ldr r0, [r0]
	cmp r0, 0x4
	bne _080157F8
	ldr r3, _080157F4
	b _080157FE
	.align 2, 0
_080157EC: .4byte gUnknown_2027370 + 0x48 @ gUnknown_2027370[1]
_080157F0: .4byte gUnknown_203B1FC
_080157F4: .4byte gUnknown_80DAFC0
_080157F8:
	cmp r0, 0x5
	bne _0801585C
	ldr r3, _08015850
_080157FE:
	mov r1, r12
	ldrb r0, [r1, 0x1C]
	lsls r0, 2
	adds r0, r3
	movs r2, 0
	ldrsh r1, [r0, r2]
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r1, r0
	ldr r0, _08015854
	ands r1, r0
	mov r4, r12
	adds r4, 0x6
	ldrh r2, [r4, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x2]
	mov r1, r12
	ldrb r0, [r1, 0x1C]
	lsls r0, 2
	adds r0, r3
	movs r2, 0x2
	ldrsh r1, [r0, r2]
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	lsls r0, 3
	adds r1, r0
	adds r1, 0x5
	ldr r0, _08015858
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r4, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, 0x6]
	b _080158B0
	.align 2, 0
_08015850: .4byte gUnknown_80DB098
_08015854: .4byte 0x000001ff
_08015858: .4byte 0x00000fff
_0801585C:
	mov r0, r12
	ldrb r1, [r0, 0x1C]
	lsls r1, 1
	mov r2, r12
	adds r2, 0x1E
	adds r2, r1
	adds r0, 0x8A
	adds r0, r1
	movs r3, 0
	ldrsh r1, [r0, r3]
	lsrs r0, r1, 31
	adds r1, r0
	asrs r1, 1
	ldrh r2, [r2]
	adds r1, r2
	movs r2, 0
	ldrsh r0, [r5, r2]
	lsls r0, 3
	adds r0, 0x1E
	adds r1, r0
	lsls r1, 23
	lsrs r1, 23
	mov r3, r12
	adds r3, 0x6
	ldrh r2, [r3, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x2]
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r1, 3
	adds r1, 0x22
	ldr r0, _080158B8
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r3, 0x6]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x6]
_080158B0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_080158B8: .4byte 0x00000fff
	thumb_func_end sub_80157D8

	thumb_func_start sub_80158BC
sub_80158BC:
	push {r4-r6,lr}
	ldr r6, _080158D4
	bl sub_8012AE8
	cmp r0, 0x8
	beq _08015908
	cmp r0, 0x8
	bgt _080158D8
	cmp r0, 0x7
	beq _080158E2
	b _08015980
	.align 2, 0
_080158D4: .4byte gUnknown_2027370
_080158D8:
	cmp r0, 0x9
	beq _08015930
	cmp r0, 0xA
	beq _08015958
	b _08015980
_080158E2:
	ldr r4, _08015900
	ldr r3, _08015904
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015900: .4byte gUnknown_80DB0F8
_08015904: .4byte gUnknown_203B1FC
_08015908:
	ldr r4, _08015928
	ldr r3, _0801592C
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x1]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015928: .4byte gUnknown_80DB0F8
_0801592C: .4byte gUnknown_203B1FC
_08015930:
	ldr r4, _08015950
	ldr r3, _08015954
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x2]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015950: .4byte gUnknown_80DB0F8
_08015954: .4byte gUnknown_203B1FC
_08015958:
	ldr r4, _08015978
	ldr r3, _0801597C
	ldr r2, [r3]
	ldrb r0, [r2, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r2, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	adds r5, r3, 0
	b _08015988
	.align 2, 0
_08015978: .4byte gUnknown_80DB0F8
_0801597C: .4byte gUnknown_203B1FC
_08015980:
	ldr r1, _080159F8
	ldr r0, [r1]
	ldrb r0, [r0, 0x1A]
	adds r5, r1, 0
_08015988:
	adds r4, r5, 0
	ldr r1, [r4]
	ldrb r2, [r1, 0x1A]
	cmp r0, r2
	beq _080159A0
	strb r0, [r1, 0x1A]
	movs r0, 0x3
	bl PlayMenuSoundEffect
	ldr r1, [r4]
	movs r0, 0x8
	strb r0, [r1, 0x17]
_080159A0:
	ldr r3, _080159FC
	ldr r4, [r5]
	ldrb r0, [r4, 0x1A]
	lsls r1, r0, 1
	adds r1, r0
	ldrb r2, [r4, 0x19]
	lsls r0, r2, 8
	subs r0, r2
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r3, 0
	ldrsh r1, [r6, r3]
	lsls r1, 3
	ldrb r2, [r0, 0x4]
	adds r1, r2
	subs r1, 0x5
	movs r3, 0x2
	ldrsh r2, [r6, r3]
	lsls r2, 3
	ldrb r0, [r0, 0x5]
	adds r2, r0
	adds r2, 0x1
	ldr r0, _08015A00
	ands r1, r0
	adds r4, 0xE
	ldrh r3, [r4, 0x2]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r3
	orrs r0, r1
	strh r0, [r4, 0x2]
	ldr r0, _08015A04
	ands r2, r0
	lsls r2, 4
	ldrh r1, [r4, 0x6]
	movs r0, 0xF
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, 0x6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
_080159F8: .4byte gUnknown_203B1FC
_080159FC: .4byte gUnknown_80DB0F8
_08015A00: .4byte 0x000001ff
_08015A04: .4byte 0x00000fff
	thumb_func_end sub_80158BC

	thumb_func_start sub_8015A08
sub_8015A08:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	movs r0, 0
	bl CallPrepareTextbox_8008C54
	movs r0, 0
	bl sub_80073B8
	ldr r3, _08015A68
	ldr r2, _08015A6C
	ldr r0, [r2]
	ldrb r1, [r0, 0x19]
	lsls r0, r1, 8
	subs r0, r1
	lsls r0, 2
	adds r1, r3, 0
	adds r1, 0x8
	adds r0, r1
	ldr r4, [r0]
	ldr r0, _08015A70
	cmp r4, r0
	bne _08015A3E
	b _08015BC0
_08015A3E:
	mov r8, r2
	adds r7, r3, 0
	add r0, sp, 0x14
	mov r10, r0
	movs r6, 0
	mov r9, r6
_08015A4A:
	ldr r0, [r2]
	ldrb r1, [r0, 0x19]
	lsls r0, r1, 8
	subs r0, r1
	lsls r0, 2
	adds r0, r6, r0
	adds r0, r3
	ldrb r0, [r0, 0x6]
	cmp r0, 0x2
	beq _08015AAA
	cmp r0, 0x2
	bgt _08015A74
	cmp r0, 0x1
	beq _08015A7A
	b _08015A82
	.align 2, 0
_08015A68: .4byte gUnknown_80DB0F8
_08015A6C: .4byte gUnknown_203B1FC
_08015A70: .4byte 0x00000109
_08015A74:
	cmp r0, 0x3
	beq _08015A7E
	b _08015A82
_08015A7A:
	movs r5, 0x5
	b _08015AAC
_08015A7E:
	movs r5, 0x7
	b _08015AAC
_08015A82:
	movs r5, 0x7
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08015AAC
	cmp r4, 0xFF
	bgt _08015AA4
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_803D0F0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08015AAC
	b _08015AAA
_08015AA4:
	ldr r0, _08015ADC
	cmp r4, r0
	bgt _08015AAC
_08015AAA:
	movs r5, 0x2
_08015AAC:
	movs r0, 0x84
	lsls r0, 1
	cmp r4, r0
	beq _08015B9E
	subs r0, 0x1
	cmp r4, r0
	bne _08015B04
	mov r2, r8
	ldr r0, [r2]
	ldrb r2, [r0, 0x18]
	cmp r2, 0
	bne _08015AE4
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x3
	ldrb r1, [r1, 0x5]
	str r2, [sp]
	ldr r2, _08015AE0
	b _08015B6A
	.align 2, 0
_08015ADC: .4byte 0x00000101
_08015AE0: .4byte gUnknown_80DB598
_08015AE4:
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x3
	ldrb r1, [r1, 0x5]
	mov r3, r9
	str r3, [sp]
	ldr r2, _08015B00
	b _08015B6A
	.align 2, 0
_08015B00: .4byte gUnknown_80DB5A4
_08015B04:
	cmp r4, 0x20
	bne _08015B34
	add r0, sp, 0x4
	ldr r1, _08015B30
	adds r2, r5, 0
	bl sprintfStatic
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x1
	ldrb r1, [r1, 0x5]
	mov r2, r9
	str r2, [sp]
	add r2, sp, 0x4
	b _08015B6A
	.align 2, 0
_08015B30: .4byte gUnknown_80DB5B0
_08015B34:
	cmp r4, 0xFF
	ble _08015B7C
	ldr r1, _08015B74
	movs r0, 0xFF
	ands r4, r0
	lsls r0, r4, 2
	adds r0, r1
	ldr r3, [r0]
	mov r0, r10
	ldr r1, _08015B78
	adds r2, r5, 0
	bl sprintfStatic
	mov r3, r8
	ldr r0, [r3]
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	adds r0, 0x3
	ldrb r1, [r1, 0x5]
	mov r2, r9
	str r2, [sp]
	mov r2, r10
_08015B6A:
	movs r3, 0
	bl PrintStringOnWindow
	b _08015B9E
	.align 2, 0
_08015B74: .4byte gUnknown_80DB4F4
_08015B78: .4byte gUnknown_80DB5B8
_08015B7C:
	mov r3, r8
	ldr r0, [r3]
	ldrb r0, [r0, 0x19]
	lsls r1, r0, 8
	subs r1, r0
	lsls r1, 2
	adds r1, r6, r1
	adds r1, r7
	ldrb r0, [r1, 0x4]
	ldrb r1, [r1, 0x5]
	lsls r2, r4, 24
	lsrs r2, 24
	mov r3, r9
	str r3, [sp]
	adds r3, r5, 0
	bl sub_8012C60
_08015B9E:
	adds r6, 0xC
	ldr r3, _08015C10
	ldr r2, _08015C14
	ldr r0, [r2]
	ldrb r1, [r0, 0x19]
	lsls r0, r1, 8
	subs r0, r1
	lsls r0, 2
	adds r0, r6, r0
	adds r1, r3, 0
	adds r1, 0x8
	adds r0, r1
	ldr r4, [r0]
	ldr r0, _08015C18
	cmp r4, r0
	beq _08015BC0
	b _08015A4A
_08015BC0:
	movs r4, 0xE
	str r4, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0x47
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x48
	bl sub_8007A78
	str r4, [sp]
	movs r0, 0
	movs r1, 0xDF
	movs r2, 0
	movs r3, 0x48
	bl sub_8007A78
	movs r0, 0
	bl sub_80073E0
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015C10: .4byte gUnknown_80DB0F8
_08015C14: .4byte gUnknown_203B1FC
_08015C18: .4byte 0x00000109
	thumb_func_end sub_8015A08

	thumb_func_start sub_8015C1C
sub_8015C1C:
	push {r4,r5,lr}
	sub sp, 0x54
	movs r0, 0x1
	bl CallPrepareTextbox_8008C54
	movs r0, 0x1
	bl sub_80073B8
	ldr r0, _08015C74
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08015C78
	movs r4, 0xE
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x37
	movs r3, 0xE0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x38
	bl sub_8007A78
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0xDF
	movs r2, 0
	movs r3, 0x38
	bl sub_8007A78
	b _08015CB2
	.align 2, 0
_08015C74: .4byte gUnknown_203B1FC
_08015C78:
	movs r4, 0xE
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xB0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x27
	movs r3, 0xB0
	bl sub_800792C
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x28
	bl sub_8007A78
	str r4, [sp]
	movs r0, 0x1
	movs r1, 0xAF
	movs r2, 0
	movs r3, 0x28
	bl sub_8007A78
_08015CB2:
	ldr r0, _08015CC8
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0x5
	bhi _08015D50
	lsls r0, 2
	ldr r1, _08015CCC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08015CC8: .4byte gUnknown_203B1FC
_08015CCC: .4byte _08015CD0
	.align 2, 0
_08015CD0:
	.4byte _08015CE8
	.4byte _08015D18
	.4byte _08015CF8
	.4byte _08015D08
	.4byte _08015D28
	.4byte _08015D40
_08015CE8:
	ldr r2, _08015CF4
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015CF4: .4byte gUnknown_80DB5C0
_08015CF8:
	ldr r2, _08015D04
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015D04: .4byte gUnknown_80DB5D4
_08015D08:
	ldr r2, _08015D14
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015D14: .4byte gUnknown_80DB5F8
_08015D18:
	ldr r2, _08015D24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r1, 0x5
	b _08015D32
	.align 2, 0
_08015D24: .4byte gUnknown_80DB61C
_08015D28:
	ldr r2, _08015D3C
	movs r0, 0
	str r0, [sp]
	movs r0, 0x36
	movs r1, 0x2
_08015D32:
	movs r3, 0x1
	bl PrintStringOnWindow
	b _08015D50
	.align 2, 0
_08015D3C: .4byte gUnknown_80DB638
_08015D40:
	ldr r2, _08015D64
	movs r0, 0
	str r0, [sp]
	movs r0, 0x30
	movs r1, 0x4
	movs r3, 0x1
	bl PrintStringOnWindow
_08015D50:
	ldr r5, _08015D68
	ldr r0, [r5]
	ldr r1, [r0]
	cmp r1, 0x4
	beq _08015D6C
	cmp r1, 0x4
	bcc _08015D88
	cmp r1, 0x5
	beq _08015D7A
	b _08015DFE
	.align 2, 0
_08015D64: .4byte gUnknown_80DB638
_08015D68: .4byte gUnknown_203B1FC
_08015D6C:
	adds r0, 0xF8
	ldr r0, [r0]
	movs r1, 0x1
	movs r2, 0
	bl sub_8015E10
	b _08015DFE
_08015D7A:
	adds r0, 0xF8
	ldr r0, [r0]
	movs r1, 0x1
	movs r2, 0
	bl sub_8015EB4
	b _08015DFE
_08015D88:
	bl sub_8016028
	adds r3, r0, 0
	movs r0, 0x4
	str r0, [sp]
	movs r0, 0x1
	movs r1, 0x26
	movs r2, 0x21
	bl sub_80078A4
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xF8
	ldr r0, [r0]
	ldrb r1, [r1, 0x1B]
	bl sub_8015FEC
	adds r4, r0, 0
	bl sub_8016028
	cmp r4, r0
	ble _08015DC0
	ldr r1, _08015DBC
	ldr r0, [r5]
	b _08015DD0
	.align 2, 0
_08015DBC: .4byte gUnknown_80DB654
_08015DC0:
	bl sub_8015F44
	ldr r2, [r5]
	ldrb r1, [r2, 0x1B]
	cmp r0, r1
	bne _08015DE0
	ldr r1, _08015DDC
	adds r0, r2, 0
_08015DD0:
	adds r0, 0xF8
	ldr r2, [r0]
	add r0, sp, 0x4
	bl sprintfStatic
	b _08015DEE
	.align 2, 0
_08015DDC: .4byte gUnknown_80DB65C
_08015DE0:
	ldr r1, _08015E0C
	adds r0, r2, 0
	adds r0, 0xF8
	ldr r2, [r0]
	add r0, sp, 0x4
	bl sprintfStatic
_08015DEE:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x26
	movs r1, 0x16
	add r2, sp, 0x4
	movs r3, 0x1
	bl PrintStringOnWindow
_08015DFE:
	movs r0, 0x1
	bl sub_80073E0
	add sp, 0x54
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
_08015E0C: .4byte gUnknown_80DB664
	thumb_func_end sub_8015C1C

	thumb_func_start sub_8015E10
sub_8015E10:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r7, r1, 0
	lsls r2, 16
	asrs r6, r2, 16
	ldr r5, _08015EB0
	movs r4, 0x35
_08015E24:
	movs r0, 0
	ldrsh r1, [r5, r0]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	adds r0, 0xB
	adds r2, r0
	movs r0, 0x5
	str r0, [sp]
	adds r0, r7, 0
	movs r3, 0xB
	bl sub_80078A4
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08015E24
	movs r4, 0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _08015EA4
	mov r5, r8
_08015E52:
	movs r3, 0x7
	cmp r4, 0x4
	ble _08015E7E
	movs r3, 0x6
	cmp r4, 0xC
	ble _08015E7E
	movs r3, 0x7
	cmp r4, 0x11
	ble _08015E7E
	cmp r4, 0x16
	ble _08015E7E
	movs r3, 0x6
	cmp r4, 0x1E
	ble _08015E7E
	movs r3, 0x7
	cmp r4, 0x23
	ble _08015E7E
	cmp r4, 0x28
	ble _08015E7E
	cmp r4, 0x30
	bgt _08015E7E
	movs r3, 0x6
_08015E7E:
	ldr r0, _08015EB0
	lsls r1, r4, 2
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	adds r1, r6
	ldrb r2, [r5]
	str r7, [sp]
	bl sub_8012C60
	adds r5, 0x1
	adds r4, 0x1
	cmp r4, 0x35
	bgt _08015EA4
	ldrb r0, [r5]
	cmp r0, 0
	bne _08015E52
_08015EA4:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015EB0: .4byte gUnknown_80DAFC0
	thumb_func_end sub_8015E10

	thumb_func_start sub_8015EB4
sub_8015EB4:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	mov r8, r0
	adds r7, r1, 0
	lsls r2, 16
	asrs r6, r2, 16
	ldr r5, _08015F40
	movs r4, 0x17
_08015EC8:
	movs r0, 0
	ldrsh r1, [r5, r0]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	adds r0, r6, 0
	adds r0, 0xB
	adds r2, r0
	movs r0, 0x5
	str r0, [sp]
	adds r0, r7, 0
	movs r3, 0xC
	bl sub_80078A4
	adds r5, 0x4
	subs r4, 0x1
	cmp r4, 0
	bge _08015EC8
	movs r4, 0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0
	beq _08015F34
	mov r5, r8
_08015EF6:
	movs r3, 0x7
	cmp r4, 0x3
	ble _08015F0E
	movs r3, 0x6
	cmp r4, 0x7
	ble _08015F0E
	movs r3, 0x7
	cmp r4, 0xF
	ble _08015F0E
	cmp r4, 0x13
	bgt _08015F0E
	movs r3, 0x6
_08015F0E:
	ldr r0, _08015F40
	lsls r1, r4, 2
	adds r1, r0
	movs r2, 0
	ldrsh r0, [r1, r2]
	movs r2, 0x2
	ldrsh r1, [r1, r2]
	adds r1, r6
	ldrb r2, [r5]
	str r7, [sp]
	bl sub_8012C60
	adds r5, 0x1
	adds r4, 0x1
	cmp r4, 0x17
	bgt _08015F34
	ldrb r0, [r5]
	cmp r0, 0
	bne _08015EF6
_08015F34:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015F40: .4byte gUnknown_80DB098
	thumb_func_end sub_8015EB4

    .align 2,0
