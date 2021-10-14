	.section .rodata

	.global gUnknown_80E5CB4
gUnknown_80E5CB4: @ 80E5CB4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0F, 0x00
        .byte 0x1A, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E5CCC
gUnknown_80E5CCC: @ 80E5CCC
        .byte 0xe8, 0x5c, 0x0e, 0x08
        .byte 0xde, 0xff, 0x00, 0x00
        .byte 0xe4, 0x5c, 0x0e, 0x08
        .byte 0xde, 0xff, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0xdd, 0xff, 0x00, 0x00

        .string "  \0"
        .align 2,0
        .string "Start an entirely new adventure.\0"
        .align 2,0

	.global gUnknown_80E5D0C
gUnknown_80E5D0C: @ 80E5D0C
	.incbin "baserom.gba", 0xE5D0C, 0x3C

	.global gUnknown_80E5D48
gUnknown_80E5D48: @ 80E5D48
	.incbin "baserom.gba", 0xE5D48, 0x58

	.global gUnknown_80E5DA0
gUnknown_80E5DA0: @ 80E5DA0
	.incbin "baserom.gba", 0xE5DA0, 0x50

	.global gUnknown_80E5DF0
gUnknown_80E5DF0: @ 80E5DF0
	.incbin "baserom.gba", 0xE5DF0, 0x6C

	.global gUnknown_80E5E5C
gUnknown_80E5E5C: @ 80E5E5C
	.incbin "baserom.gba", 0xE5E5C, 0x60

	.global gUnknown_80E5EBC
gUnknown_80E5EBC: @ 80E5EBC
	.incbin "baserom.gba", 0xE5EBC, 0x60

	.global gUnknown_80E5F1C
gUnknown_80E5F1C: @ 80E5F1C
	.incbin "baserom.gba", 0xE5F1C, 0x64

	.global gUnknown_80E5F80
gUnknown_80E5F80: @ 80E5F80
	.incbin "baserom.gba", 0xE5F80, 0x4C

	.global gUnknown_80E5FCC
gUnknown_80E5FCC: @ 80E5FCC
	.incbin "baserom.gba", 0xE5FCC, 0x64

	.global gUnknown_80E6030
gUnknown_80E6030: @ 80E6030
	.incbin "baserom.gba", 0xE6030, 0x70

@ Start of Trade Items Data

	.global gUnknown_80E60A0
gUnknown_80E60A0: @ 80E60A0
        .4byte SendItem_80E60C8
        .4byte 1
        .4byte ReceiveItem_80E60B8
        .4byte 2
        .4byte 0
        .4byte 0

        .global ReceiveItem_80E60B8
        ReceiveItem_80E60B8:
        .asciz "Receive item"
        .align 2,0

        .global SendItem_80E60C8
        SendItem_80E60C8:
        .asciz "Send item"
        .align 2,0

	.global gUnknown_80E60D4
gUnknown_80E60D4: @ 80E60D4
        .4byte SendItem_80E60C8
        .4byte -1
        .4byte ReceiveItem_80E60B8
        .4byte 2
        .4byte 0
        .4byte 0

	.global gUnknown_80E60EC
gUnknown_80E60EC: @ 80E60EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6104
gUnknown_80E6104: @ 80E6104
        .4byte Confirm_80E6134
        .4byte 3
        .4byte Info_80E612C
        .4byte 4
        .4byte Cancel_80E6124
        .4byte 7
        .4byte 0
        .4byte 0

        .global Cancel_80E6124
        Cancel_80E6124:
        .asciz "Cancel"
        .align 2,0


        .global Info_80E612C
        Info_80E612C:
        .asciz "Info"
        .align 2,0

        .global Confirm_80E6134
        Confirm_80E6134:
        .asciz "Confirm"
        .align 2,0

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x09, 0x00
        .byte 0x05, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6154
gUnknown_80E6154: @ 80E6154
        .4byte Yes_80E6170
        .4byte 5
        .4byte No_80E616C
        .4byte 6
        .4byte 0
        .4byte 0

        .global No_80E616C
        No_80E616C:
        .asciz "No"
        .align 2,0

        .global Yes_80E6170
        Yes_80E6170:
        .asciz "Yes"
        .align 2,0

	.global gUnknown_80E6174
gUnknown_80E6174: @ 80E6174
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0D, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E618C
gUnknown_80E618C: @ 80E618C
        .4byte Yes_80E6170
        .4byte 5
        .4byte Cancel_80E6124
        .4byte 0
        .4byte 0
        .4byte 0

	.global gUnknown_80E61A4
gUnknown_80E61A4: @ 80E61A4
        .asciz "What would you like to do? "
        .align 2,0

	.global gUnknown_80E61C0
gUnknown_80E61C0: @ 80E61C0
        .asciz "Please choose the item to be sent."
        .align 2,0

	.global gUnknown_80E61E4
gUnknown_80E61E4: @ 80E61E4
        .string "#CG$d0#R #CI$i0(s)#R\n"
        .string "will be sent.\n"
        .string "Is that OK?\0"
        .align 2,0

	.global gUnknown_80E6214
gUnknown_80E6214: @ 80E6214
        .string "Your friend will send you an item.\n"
        .string "When you are both ready~2c you\n"
        .string "may communicate.\0"
        .align 2,0

	.global gUnknown_80E6268
gUnknown_80E6268: @ 80E6268
        .string "Preparing to send an item to your\n"
        .string "friend. When you are both ready~2c\n"
        .string "you may communicate.\0"
        .align 2,0

	.global gUnknown_80E62C4
gUnknown_80E62C4: @ 80E62C4
        .string "#+In communication...\n"
        .string "#+Please wait with the power on.\n"
        .string "#+To cancel~2c press {B_BUTTON}.\0"
        .align 2,0

	.global gUnknown_80E6314
gUnknown_80E6314: @ 80E6314
        .string "You received\n"
        .string "#CG$d0#R #CI$i0(s)#R.\n"
        .string "Your adventure will be saved.\0"
        .align 2,0

	.global gUnknown_80E6358
gUnknown_80E6358: @ 80E6358
        .string "You sent #CG$d0#R #CI$i0(s)#R.\0"
        .align 2,0

@ Trade Items Link Errors
	.global gTradeItemsCommunicationError
gTradeItemsCommunicationError: @ 80E6378
        .asciz "There was a communication error."
        .align 2,0

	.global gUnknown_80E639C
gUnknown_80E639C: @ 80E639C
        .string "An incorrect number of GBA systems are\n"
        .string "connected.\n"
        .string "Please redo this process from the start.\0"
        .align 2,0

	.global gUnknown_80E63F8
gUnknown_80E63F8: @ 80E63F8
        .string "There is no response from your friend.\n"
        .string "Please redo this process from the start.\0"
        .align 2,0

	.global gUnknown_80E6448
gUnknown_80E6448: @ 80E6448
        .string "The sender and receiver appear to be\n"
        .string "in different modes.\n"
        .string "Please redo the process from the start.\0"
        .align 2,0

	.global gUnknown_80E64AC
gUnknown_80E64AC: @ 80E64AC
        .string "There is no response from your friend.\n"
        .string "Please make sure the sender and receiver\n"
        .string "are ready~2c then redo this from the start.\0"
        .align 2,0

	.global gTradeItemsHowManyText
gTradeItemsHowManyText: @ 80E6528
        .asciz "How many?"
        .align 2,0
        .asciz "pksdir0"

@ End of Trade Menu Data

	.global gUnknown_80E653C
gUnknown_80E653C: @ 80E653C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6554
gUnknown_80E6554: @ 80E6554
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.global gUnknown_80E656C
gUnknown_80E656C: @ 80E656C
	.incbin "baserom.gba", 0xE656C, 0x6C

	.global gUnknown_80E65D8
gUnknown_80E65D8: @ 80E65D8
	.incbin "baserom.gba", 0xE65D8, 0x44

	.global gUnknown_80E661C
gUnknown_80E661C: @ 80E661C
	.incbin "baserom.gba", 0xE661C, 0x40

	.global gUnknown_80E665C
gUnknown_80E665C: @ 80E665C
	.incbin "baserom.gba", 0xE665C, 0x20

	.global gUnknown_80E667C
gUnknown_80E667C: @ 80E667C
	.incbin "baserom.gba", 0xE667C, 0x40

	.global gUnknown_80E66BC
gUnknown_80E66BC: @ 80E66BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E66D4
gUnknown_80E66D4: @ 80E66D4
	.incbin "baserom.gba", 0xE66D4, 0x74

	.global gUnknown_80E6748
gUnknown_80E6748: @ 80E6748
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6760
gUnknown_80E6760: @ 80E6760
	.incbin "baserom.gba", 0xE6760, 0x74

	.global gUnknown_80E67D4
gUnknown_80E67D4: @ 80E67D4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E67EC
gUnknown_80E67EC: @ 80E67EC
	.incbin "baserom.gba", 0xE67EC, 0xB0

	.global gUnknown_80E689C
gUnknown_80E689C: @ 80E689C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E68B4
gUnknown_80E68B4: @ 80E68B4
	.incbin "baserom.gba", 0xE68B4, 0x84

	.global gUnknown_80E6938
gUnknown_80E6938: @ 80E6938
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6950
gUnknown_80E6950: @ 80E6950
	.incbin "baserom.gba", 0xE6950, 0x60

	.global gUnknown_80E69B0
gUnknown_80E69B0: @ 80E69B0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E69C8
gUnknown_80E69C8: @ 80E69C8
	.incbin "baserom.gba", 0xE69C8, 0x48

	.global gUnknown_80E6A10
gUnknown_80E6A10: @ 80E6A10
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6A28
gUnknown_80E6A28: @ 80E6A28
	.incbin "baserom.gba", 0xE6A28, 0x4C

	.global gUnknown_80E6A74
gUnknown_80E6A74: @ 80E6A74
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6A8C
gUnknown_80E6A8C: @ 80E6A8C
	.incbin "baserom.gba", 0xE6A8C, 0xEC

	.global gUnknown_80E6B78
gUnknown_80E6B78: @ 80E6B78
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6B90
gUnknown_80E6B90: @ 80E6B90
	.incbin "baserom.gba", 0xE6B90, 0x64

	.global gUnknown_80E6BF4
gUnknown_80E6BF4: @ 80E6BF4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6C0C
gUnknown_80E6C0C: @ 80E6C0C
	.incbin "baserom.gba", 0xE6C0C, 0x44

	.global gUnknown_80E6C50
gUnknown_80E6C50: @ 80E6C50
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6C68
gUnknown_80E6C68: @ 80E6C68
	.incbin "baserom.gba", 0xE6C68, 0x68

	.global gUnknown_80E6CD0
gUnknown_80E6CD0: @ 80E6CD0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6CE8
gUnknown_80E6CE8: @ 80E6CE8
	.incbin "baserom.gba", 0xE6CE8, 0x6C

	.global gUnknown_80E6D54
gUnknown_80E6D54: @ 80E6D54
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6D6C
gUnknown_80E6D6C: @ 80E6D6C
	.incbin "baserom.gba", 0xE6D6C, 0x70

	.global gUnknown_80E6DDC
gUnknown_80E6DDC: @ 80E6DDC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6DF4
gUnknown_80E6DF4: @ 80E6DF4
	.incbin "baserom.gba", 0xE6DF4, 0x5C

        .global gUnknown_80E6E50
gUnknown_80E6E50:: @ 80E6E50
        .string "CHUNSOFT\0"
        .align 2,0

        .string "pksdir0\0"

        .string "pksdir0\0"

        .string "pksdir0\0"

        .string "pksdir0\0"


	.global gUnknown_80E6E7C
gUnknown_80E6E7C: @ 80E6E7C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6E94
gUnknown_80E6E94: @ 80E6E94
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x09, 0x00
        .byte 0x13, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6EAC
gUnknown_80E6EAC: @ 80E6EAC
        .4byte Caution_80E6F04
        .4byte 3
        .4byte StorageEmpty_80E6EE4
        .4byte 3
        .4byte CheckAgain_80E6ECC
        .4byte 3
        .4byte 0
        .4byte 1

        .global CheckAgain_80E6ECC
        CheckAgain_80E6ECC:
        .asciz "#+Please check again."
        .align 2,0

        .global StorageEmpty_80E6EE4
        StorageEmpty_80E6EE4:
        .asciz "#+The storage space is empty!"
        .align 2,0

        .global Caution_80E6F04
        Caution_80E6F04:
        .asciz "#+#C2Caution!#R "
        .align 2,0

        .asciz "pksdir0"

	.global gUnknown_80E6F20
gUnknown_80E6F20: @ 80E6F20
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6F38
gUnknown_80E6F38: @ 80E6F38
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x08, 0x00
        .byte 0x15, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6F50
gUnknown_80E6F50: @ 80E6F50
	.incbin "baserom.gba", 0xE6F50, 0x6C

	.global gUnknown_80E6FBC
gUnknown_80E6FBC: @ 80E6FBC
	.incbin "baserom.gba", 0xE6FBC, 0x60

	.global gUnknown_80E701C
gUnknown_80E701C: @ 80E701C
	.incbin "baserom.gba", 0xE701C, 0x74

	.global gUnknown_80E7090
gUnknown_80E7090: @ 80E7090
        .4byte 0x80e6fac
        .4byte 4
        .4byte DeletingAdventure_80E70B0
        .4byte 4
        .4byte 0x80e6f70
        .4byte 4
        .4byte 0
        .4byte 2

        .global DeletingAdventure_80E70B0
        DeletingAdventure_80E70B0:
        .string "#+Deleting your adventure!"
        .align 2,0

	.global gUnknown_80E70CC
gUnknown_80E70CC: @ 80E70CC
        .4byte 0x80e7008
        .4byte 4
        .4byte AdventureDeleted_80E70F0
        .4byte 4
        .4byte Data_80E70EC
        .4byte 4
        .4byte 0
        .4byte 2

        .global Data_80E70EC
        Data_80E70EC:
        .string "  "
        .align 2,0

        .global AdventureDeleted_80E70F0
        AdventureDeleted_80E70F0:
        .string "#+Your adventure has been deleted."
        .align 2,0

	.global gUnknown_80E7114
gUnknown_80E7114: @ 80E7114
	.incbin "baserom.gba", 0xE7114, 0x64

	.global gUnknown_80E7178
gUnknown_80E7178: @ 80E7178
	.incbin "baserom.gba", 0xE7178, 0x6C

	.global gUnknown_80E71E4
gUnknown_80E71E4: @ 80E71E4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E71FC
gUnknown_80E71FC: @ 80E71FC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7214
gUnknown_80E7214: @ 80E7214
        .4byte Error_80E7268
        .4byte 0xC
        .4byte IncorrectPassword_80E7250
        .4byte 0xC
        .4byte CheckAgain_80E7234
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global CheckAgain_80E7234
        CheckAgain_80E7234:
        .asciz "#+Please check it again."
        .align 2,0

        .global IncorrectPassword_80E7250
        IncorrectPassword_80E7250:
        .asciz "#+Incorrect password!"
        .align 2,0

        .global Error_80E7268
        Error_80E7268:
        .asciz "#+#C2Error!#R "
        .align 2,0

	.global gUnknown_80E7278
gUnknown_80E7278: @ 80E7278
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7290
gUnknown_80E7290: @ 80E7290
        .4byte Success_80E72D8
        .4byte 0xC
        .4byte PasswordAccept_80E72B4
        .4byte 0xC
        .4byte DATA_80E72B0
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global DATA_80E72B0
        DATA_80E72B0:
        .byte 0x20, 0x20, 0x00, 0x00 @ 2 spaces??

        .global PasswordAccept_80E72B4
        PasswordAccept_80E72B4:
        .asciz "#+The password has been accepted."
        .align 2,0
        
        .global Success_80E72D8
        Success_80E72D8:
        .asciz "#+#CGSuccess!#R "
        .align 2,0

	.global gUnknown_80E72EC
gUnknown_80E72EC: @ 80E72EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7304
gUnknown_80E7304: @ 80E7304
        .4byte Error_80E7268
        .4byte 0xC
        .4byte NotSOSMail_80E7324
        .4byte 0xC
        .4byte CheckAgain_80E7234
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global NotSOSMail_80E7324
        NotSOSMail_80E7324:
        .asciz "#+This is not an #CGSOS Mail#R."
        .align 2,0

	.global gUnknown_80E7344
gUnknown_80E7344: @ 80E7344
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E735C
gUnknown_80E735C: @ 80E735C
        .4byte Error_80E7268
        .4byte 0xC
        .4byte ReceiveSOSMail_80E737C
        .4byte 0xC
        .4byte CheckAgain_80E7234
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global ReceiveSOSMail_80E737C
        ReceiveSOSMail_80E737C:
        .asciz "#+This #CGSOS Mail#R has been received already."
        .align 2,0

	.global gUnknown_80E73AC
gUnknown_80E73AC: @ 80E73AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E73C4
gUnknown_80E73C4: @ 80E73C4
	.incbin "baserom.gba", 0xE73C4, 0x44

	.global gUnknown_80E7408
gUnknown_80E7408: @ 80E7408
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7420
gUnknown_80E7420: @ 80E7420
	.incbin "baserom.gba", 0xE7420, 0x48

	.global gUnknown_80E7468
gUnknown_80E7468: @ 80E7468
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7480
gUnknown_80E7480: @ 80E7480
	.incbin "baserom.gba", 0xE7480, 0x48

	.global gUnknown_80E74C8
gUnknown_80E74C8: @ 80E74C8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E74E0
gUnknown_80E74E0: @ 80E74E0
	.incbin "baserom.gba", 0xE74E0, 0x4C

	.global gUnknown_80E752C
gUnknown_80E752C: @ 80E752C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7544
gUnknown_80E7544: @ 80E7544
	.incbin "baserom.gba", 0xE7544, 0x44

	.global gUnknown_80E7588
gUnknown_80E7588: @ 80E7588
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E75A0
gUnknown_80E75A0: @ 80E75A0
	.incbin "baserom.gba", 0xE75A0, 0x58

	.global gUnknown_80E75F8
gUnknown_80E75F8: @ 80E75F8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7610
gUnknown_80E7610: @ 80E7610
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1A, 0x00, 0x0B, 0x00
        .byte 0x0B, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x20, 0x00, 0x00, 0x00

	.global gUnknown_80E762C
gUnknown_80E762C: @ 80E762C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0F, 0x00
        .byte 0x13, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gResumeQuicksaveMenuItems
gResumeQuicksaveMenuItems: @ 80E7644
        .4byte ResumeQuicksave_80E7668
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte IsThatOK_80E765C
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

        IsThatOK_80E765C:
        .string "Is that OK?\0"
        .align 2,0

        ResumeQuicksave_80E7668:
        .string "Resuming from quicksave.\0"
        .align 2,0

	.global gResumeAdventureMenuItems
gResumeAdventureMenuItems: @ 80E7684
        .4byte ResumeAdventure_80E769C
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte IsThatOK_80E765C
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

        ResumeAdventure_80E769C:
        .string "Resuming saved adventure.\0"
        .align 2,0

	.global gQuitWaitingRescueMenuItems
gQuitWaitingRescueMenuItems: @ 80E76B8
        .4byte QuitAwaitingRescue_80E76D0
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte IsThatOK_80E765C
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

        QuitAwaitingRescue_80E76D0:
        .string "Quit awaiting rescue?\0"
        .align 2,0

	.global gDeleteSavePromptMenuItems
gDeleteSavePromptMenuItems: @ 80E76E8
        .4byte Deleted_80E7718
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte Deleted_80E7700
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

        Deleted_80E7700:
        .string "deleted. Is that OK?\0"
        .align 2,0

        Deleted_80E7718:
        .string "Your saved data will be\0"
        .align 2,0

	.global gDeleteSaveConfirmMenuItems
gDeleteSaveConfirmMenuItems: @ 80E7730
        .4byte Deleted_80E7768
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte Deleted_80E7748
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

        Deleted_80E7748:
        .string "delete all of your saved data?\0"
        .align 2,0

        Deleted_80E7768:
        .string "Are you sure you want to\0"
        .align 2,0


	.global gUnknown_80E7784
gUnknown_80E7784: @ 80E7784
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x17, 0x00, 0x0F, 0x00
        .byte 0x05, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

