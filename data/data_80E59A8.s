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

sUnknown_80E5CE4: @ 80E5CE4
    .string "  \0"
    .align 2,0

    .string "Start an entirely new adventure.\0"
    .align 2,0

	.global gUnknown_80E5D0C
gUnknown_80E5D0C: @ 80E5D0C
    .4byte sUnknown_80E5D24, 0xFFDE
    .4byte sUnknown_80E5CE4, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5D24: @ 80E5D24
    .string "Check your career as an adventurer.\0"
    .align 2, 0

	.global gUnknown_80E5D48
gUnknown_80E5D48: @ 80E5D48
    .4byte sUnknown_80E5D88, 0xFFDE
    .4byte sUnknown_80E5D60, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5D60: @ 80E5D60
    .string "It won~27t be in the release version.\0"
    .align 2, 0

sUnknown_80E5D88: @ 80E5D88
    .string "This is the Debug Mode.\0"
    .align 2, 0

	.global gUnknown_80E5DA0
gUnknown_80E5DA0: @ 80E5DA0
    .4byte sUnknown_80E5DCC, 0xFFDE
    .4byte sUnknown_80E5DB8, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5DB8:
    .string "you last saved.  \0"
    .align 2, 0

sUnknown_80E5DCC:
    .string "Resume your adventure from where\0"
    .align 2, 0

	.global gUnknown_80E5DF0
gUnknown_80E5DF0: @ 80E5DF0
    .4byte sUnknown_80E5E34, 0xFFDE
    .4byte sUnknown_80E5E08, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5E08:
    .string "#C2Beware#R! This will delete it forever!\0"
    .align 2, 0

sUnknown_80E5E34:
    .string "This will delete your saved game data.\0"
    .align 2, 0

	.global gUnknown_80E5E5C
gUnknown_80E5E5C: @ 80E5E5C
    .4byte sUnknown_80E5EA0, 0xFFDE
    .4byte sUnknown_80E5E74, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5E74:
    .string "passwords~2c friends may rescue each other.\0"
    .align 2, 0

sUnknown_80E5EA0:
    .string "Using a Game Link cable or\0"
    .align 2, 0

	.global gUnknown_80E5EBC
gUnknown_80E5EBC: @ 80E5EBC
    .4byte sUnknown_80E5EF8, 0xFFDE
    .4byte sUnknown_80E5ED4, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5ED4:
    .string "trade stored items with a friend.\0"
    .align 2, 0

sUnknown_80E5EF8:
    .string "Using a Game Link cable~2c you can\0"
    .align 2, 0

	.global gUnknown_80E5F1C
gUnknown_80E5F1C: @ 80E5F1C
    .4byte sUnknown_80E5F58, 0xFFDE
    .4byte sUnknown_80E5F34, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5F34:
    .string "You can give up waiting for rescue.\0"
    .align 2, 0

sUnknown_80E5F58:
    .string "You are awaiting rescue by a friend.\0"
    .align 2, 0

	.global gUnknown_80E5F80
gUnknown_80E5F80: @ 80E5F80
    .4byte sUnknown_80E5FB0, 0xFFDE
    .4byte sUnknown_80E5F98, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5F98:
    .string "receive Wonder Mail.\0"
    .align 2, 0

sUnknown_80E5FB0:
    .string "Using passwords~2c you can\0"
    .align 2, 0

	.global gUnknown_80E5FCC
gUnknown_80E5FCC: @ 80E5FCC
    .4byte sUnknown_80E6008, 0xFFDE
    .4byte sUnknown_80E5FE4, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E5FE4:
    .string "receive teams from your friends.\0"
    .align 2, 0

sUnknown_80E6008:
    .string "Using the Dual Slot function~2c you can\0"
    .align 2, 0

	.global gUnknown_80E6030
gUnknown_80E6030: @ 80E6030
    .4byte sUnknown_80E6070, 0xFFDE
    .4byte sUnknown_80E6048, 0xFFDE
    .4byte 0, 0xFFDD

sUnknown_80E6048:
    .string "go on an adventure to unknown worlds.\0"
    .align 2, 0

sUnknown_80E6070:
    .string "Using wireless communication~2c you can\0"
    .align 2, 0

    .string "pksdir0\0"

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
        .string "{COLOR_1 LIGHT_BLUE_2}$d0{END_COLOR_TEXT_1} {COLOR_1 GREEN_2}{ARG_MOVE_ITEM_0}(s){END_COLOR_TEXT_1}\n"
        .string "will be sent.\n"
        .string "Is that OK?\0"
        .align 2,0

	.global gUnknown_80E6214
gUnknown_80E6214: @ 80E6214
        .string "Your friend will send you an item.\n"
        .string "When you are both ready{COMMA} you\n"
        .string "may communicate.\0"
        .align 2,0

	.global gUnknown_80E6268
gUnknown_80E6268: @ 80E6268
        .string "Preparing to send an item to your\n"
        .string "friend. When you are both ready{COMMA}\n"
        .string "you may communicate.\0"
        .align 2,0

	.global gUnknown_80E62C4
gUnknown_80E62C4: @ 80E62C4
        .string "{CENTER_ALIGN}In communication...\n"
        .string "{CENTER_ALIGN}Please wait with the power on.\n"
        .string "{CENTER_ALIGN}To cancel{COMMA} press {B_BUTTON}.\0"
        .align 2,0

	.global gUnknown_80E6314
gUnknown_80E6314: @ 80E6314
        .string "You received\n"
        .string "{COLOR_1 LIGHT_BLUE_2}$d0{END_COLOR_TEXT_1} {COLOR_1 GREEN_2}{ARG_MOVE_ITEM_0}(s){END_COLOR_TEXT_1}.\n"
        .string "Your adventure will be saved.\0"
        .align 2,0

	.global gUnknown_80E6358
gUnknown_80E6358: @ 80E6358
        .string "You sent {COLOR_1 LIGHT_BLUE_2}$d0{END_COLOR_TEXT_1} {COLOR_1 GREEN_2}{ARG_MOVE_ITEM_0}(s){END_COLOR_TEXT_1}.\0"
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
        .string "are ready{COMMA} then redo this from the start.\0"
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
    .4byte sUnknown_80E65C4, 0x5
    .4byte sUnknown_80E65AC, 0x5
    .4byte sUnknown_80E658C, 0x5
    .4byte 0, 0x3

sUnknown_80E658C:
    .string "#+Don~27t turn the power off!\0"
    .align 2, 0

sUnknown_80E65AC:
    .string "#+Item transmitting!\0"
    .align 2, 0

sUnknown_80E65C4:
    .string "#+#C2Caution!#R \0"
    .align 2, 0

	.global gUnknown_80E65D8
gUnknown_80E65D8: @ 80E65D8
    .4byte sUnknown_80E65C4, 0x5
    .4byte sUnknown_80E65F8, 0x5
    .4byte sUnknown_80E658C, 0x5
    .4byte 0, 0x3

sUnknown_80E65F8:
    .string "#+Thank-You Mail in transmission!\0"
    .align 2, 0

	.global gUnknown_80E661C
gUnknown_80E661C: @ 80E661C
    .4byte sUnknown_80E65C4, 0x5
    .4byte sUnknown_80E663C, 0x5
    .4byte sUnknown_80E658C, 0x5
    .4byte 0, 0x3

sUnknown_80E663C:
    .string "#+A-OK Mail in transmission!\0"
    .align 2, 0

	.global gUnknown_80E665C
gUnknown_80E665C: @ 80E665C
    .4byte sUnknown_80E65C4, 0x5
    .4byte sUnknown_80E65F8, 0x5
    .4byte sUnknown_80E658C, 0x5
    .4byte 0, 0x3

	.global gUnknown_80E667C
gUnknown_80E667C: @ 80E667C
    .4byte sUnknown_80E65C4, 0x5
    .4byte sUnknown_80E669C, 0x5
    .4byte sUnknown_80E658C, 0x5
    .4byte 0, 0x3

sUnknown_80E669C:
    .string "#+Wonder Mail in transmission!\0"
    .align 2, 0

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
    .4byte sUnknown_80E6734, 0x5
    .4byte sUnknown_80E6710, 0x5
    .4byte sUnknown_80E66F4, 0x5
    .4byte 0, 0x3

sUnknown_80E66F4:
    .string "#+Please press any button.\0"
    .align 2, 0

sUnknown_80E6710:
    .string "#+Your adventure will be continued.\0"
    .align 2, 0

sUnknown_80E6734:
    .string "#+#CGSuccess!#R \0"
    .align 2, 0

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
    .4byte sUnknown_80E67B4, 0x5
    .4byte sUnknown_80E6794, 0x5
    .4byte sUnknown_80E6780, 0x5
    .4byte 0, 0x3

sUnknown_80E6780:
    .string "#+please try again.\0"
    .align 2, 0

sUnknown_80E6794:
    .string "#+Check the Game Link cable and\0"
    .align 2, 0

sUnknown_80E67B4:
    .string "#+#C2Communication error!#R \0"
    .align 2, 0

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
    .4byte sUnknown_80E67B4, 0x5
    .4byte sUnknown_80E680C, 0x5
    .4byte sUnknown_80E6780, 0x5
    .4byte 0, 0x3

sUnknown_80E680C:
    .string "#+Check your communication mode and\0"
    .align 2, 0

    .global gUnknown_80E6830
gUnknown_80E6830: @ 80E6830
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

    .global gUnknown_80E6848
gUnknown_80E6848: @ 80E6848
    .4byte sUnknown_80E67B4, 0x5
    .4byte sUnknown_80E6888, 0x5
    .4byte sUnknown_80E6868, 0x5
    .4byte 0, 0x3

sUnknown_80E6868:
    .string "#+Please inform the programmer.\0"
    .align 2, 0

sUnknown_80E6888:
    .string "#+Check sum error.\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E68FC, 0x5
    .4byte sUnknown_80E68D4, 0x5
    .4byte 0, 0x3

sUnknown_80E68D4:
    .string "#+someone~27s storage space was full.\0"
    .align 2, 0

sUnknown_80E68FC:
    .string "#+An item could not be transferred because\0"
    .align 2, 0

sUnknown_80E6928:
    .string "#+#C2Error!#R \0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6988, 0x5
    .4byte sUnknown_80E6970, 0x5
    .4byte 0, 0x3

sUnknown_80E6970:
    .string "#+Please check again.\0"
    .align 2, 0

sUnknown_80E6988:
    .string "#+This #CGSOS Mail#R can~27t be used.\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E69E8, 0x5
    .4byte sUnknown_80E6970, 0x5
    .4byte 0, 0x3

sUnknown_80E69E8:
    .string "#+This #CGA-OK Mail#R can~27t be used.\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6A48, 0x5
    .4byte sUnknown_80E6970, 0x5
    .4byte 0, 0x3

sUnknown_80E6A48:
    .string "#+This #CGThank-You Mail#R can~27t be used.\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6AC8, 0x5
    .4byte sUnknown_80E6AAC, 0x5
    .4byte 0, 0x3

sUnknown_80E6AAC:
    .string "#+It can~27t be received.\0"
    .align 2, 0

sUnknown_80E6AC8:
    .string "#+There is no space for new mail.\0"
    .align 2, 0

    .global gUnknown_80E6AEC
gUnknown_80E6AEC: @ 80E6AEC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

    .global gUnknown_80E6B04
gUnknown_80E6B04: @ 80E6B04
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6B4C, 0x5
    .4byte sUnknown_80E6B24, 0x5
    .4byte 0, 0x3

sUnknown_80E6B24:
    .string "#+You need to go further in the story.\0"
    .align 2, 0

sUnknown_80E6B4C:
    .string "#+You may not go to that #CGdungeon#R yet.\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6BC4, 0x5
    .4byte sUnknown_80E6BB0, 0x5
    .4byte 0, 0x3

sUnknown_80E6BB0:
    .string "#+Please try again.\0"
    .align 2, 0

sUnknown_80E6BC4:
    .string "#+There was a problem on your friend~27s end.\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6C2C, 0x5
    .4byte sUnknown_80E6BB0, 0x5
    .4byte 0, 0x3

sUnknown_80E6C2C:
    .string "#+Your friend is not responding.\0"
    .align 2, 0

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
    .4byte sUnknown_80E6734, 0x5
    .4byte sUnknown_80E6CA8, 0x5
    .4byte sUnknown_80E6C88, 0x5
    .4byte 0, 0x3

sUnknown_80E6C88:
    .string "#+went through successfully.\0"
    .align 2, 0

sUnknown_80E6CA8:
    .string "#+The item exchange with your friend\0"
    .align 2, 0

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
    .4byte sUnknown_80E65C4, 0x5
    .4byte sUnknown_80E6D2C, 0x5
    .4byte sUnknown_80E6D08, 0x5
    .4byte 0, 0x3

sUnknown_80E6D08:
    .string "#+you and your friend are ready.\0"
    .align 2, 0

sUnknown_80E6D2C:
    .string "#+Please communicate only after both\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6DB0, 0x5
    .4byte sUnknown_80E6D8C, 0x5
    .4byte 0, 0x3

sUnknown_80E6D8C:
    .string "#+connected. Please check again.\0"
    .align 2, 0

sUnknown_80E6DB0:
    .string "#+An incorrect number of GBA systems are\0"
    .align 2, 0

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
    .4byte sUnknown_80E6928, 0x5
    .4byte sUnknown_80E6E30, 0x5
    .4byte sUnknown_80E6E14, 0x5
    .4byte 0, 0x3

sUnknown_80E6E14:
    .string "#+Please check it again.\0"
    .align 2, 0

sUnknown_80E6E30:
    .string "#+Communication failed.\0"
    .align 2, 0

    .string "pksdir0\0"

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
        .string "{CENTER_ALIGN}Please check again.\0"
        .align 2,0

        .global StorageEmpty_80E6EE4
        StorageEmpty_80E6EE4:
        .string "{CENTER_ALIGN}The storage space is empty!\0"
        .align 2,0

        .global Caution_80E6F04
        Caution_80E6F04:
        .string "{CENTER_ALIGN}{COLOR_1 RED}Caution!{END_COLOR_TEXT_1} \0"
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
    .4byte sUnknown_80E6FAC, 0x4
    .4byte sUnknown_80E6F90, 0x4
    .4byte sUnknown_80E6F70, 0x4
    .4byte 0, 0x2

sUnknown_80E6F70:
    .string "#+Don~27t turn off the power.\0"
    .align 2, 0

sUnknown_80E6F90:
    .string "#+Saving your adventure!\0"
    .align 2, 0

sUnknown_80E6FAC:
    .string "#+#C2Beware!#R \0"
    .align 2, 0

	.global gUnknown_80E6FBC
gUnknown_80E6FBC: @ 80E6FBC
    .4byte sUnknown_80E7008, 0x4
    .4byte sUnknown_80E6FF0, 0x4
    .4byte sUnknown_80E6FDC, 0x4
    .4byte 0, 0x2

sUnknown_80E6FDC:
    .string "#+has been saved.\0"
    .align 2, 0

sUnknown_80E6FF0:
    .string "#+Your adventure so far\0"
    .align 2, 0

sUnknown_80E7008:
    .string "#+#CGSuccess!#R \0"
    .align 2, 0

	.global gUnknown_80E701C
gUnknown_80E701C: @ 80E701C
    .4byte sUnknown_80E7078, 0x4
    .4byte sUnknown_80E7050, 0x4
    .4byte sUnknown_80E703C, 0x4
    .4byte 0, 0x2

sUnknown_80E703C:
    .string "#+Please try again.\0"
    .align 2, 0

sUnknown_80E7050:
    .string "#+Your adventure could not be saved.\0"
    .align 2, 0

sUnknown_80E7078:
    .string "#+#C2Save failed!#R \0"
    .align 2, 0

	.global gUnknown_80E7090
gUnknown_80E7090: @ 80E7090
    .4byte sUnknown_80E6FAC, 0x4
    .4byte DeletingAdventure_80E70B0, 0x4
    .4byte sUnknown_80E6F70, 0x4
    .4byte 0, 0x2

DeletingAdventure_80E70B0:
    .string "{CENTER_ALIGN}Deleting your adventure!\0"
    .align 2, 0

	.global gUnknown_80E70CC
gUnknown_80E70CC: @ 80E70CC
    .4byte sUnknown_80E7008, 0x4
    .4byte AdventureDeleted_80E70F0, 0x4
    .4byte Data_80E70EC, 0x4
    .4byte 0, 0x2

Data_80E70EC:
    .string "  \0"
    .align 2, 0

AdventureDeleted_80E70F0:
    .string "{CENTER_ALIGN}Your adventure has been deleted.\0"
    .align 2, 0

	.global gUnknown_80E7114
gUnknown_80E7114: @ 80E7114
    .4byte sUnknown_80E715C, 0x4
    .4byte sUnknown_80E7134, 0x4
    .4byte sUnknown_80E703C, 0x4
    .4byte 0, 0x2

sUnknown_80E7134:
    .string "#+Your adventure could not be deleted.\0"
    .align 2, 0

sUnknown_80E715C:
    .string "#+#C2Deletion failed!#R \0"
    .align 2, 0

	.global gUnknown_80E7178
gUnknown_80E7178: @ 80E7178
    .string "#+The data could not be written.\n"
    .string "#+Please turn off the power and remove\n"
    .string "#+and reinsert the DS Card.\0"
    .align 2, 0

    .string "pksdir0\0"

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
    .4byte Error_80E7268, 0xC
    .4byte IncorrectPassword_80E7250, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

CheckAgain_80E7234:
    .string "{CENTER_ALIGN}Please check it again.\0"
    .align 2, 0

IncorrectPassword_80E7250:
    .string "{CENTER_ALIGN}Incorrect password!\0"
    .align 2, 0

Error_80E7268:
    .string "{CENTER_ALIGN}{COLOR_1 RED}Error!{END_COLOR_TEXT_1} \0"
    .align 2, 0

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
    .4byte Success_80E72D8, 0xC
    .4byte PasswordAccept_80E72B4, 0xC
    .4byte DATA_80E72B0, 0xC
    .4byte 0, 0xA

DATA_80E72B0:
    .string "  \0"
    .align 2, 0

PasswordAccept_80E72B4:
    .string "{CENTER_ALIGN}The password has been accepted.\0"
    .align 2, 0

Success_80E72D8:
    .string "{CENTER_ALIGN}{COLOR_1 LIGHT_BLUE_2}Success!{END_COLOR_TEXT_1} \0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte NotSOSMail_80E7324, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

NotSOSMail_80E7324:
    .string "{CENTER_ALIGN}This is not an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}.\0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte ReceiveSOSMail_80E737C, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

ReceiveSOSMail_80E737C:
    .string "{CENTER_ALIGN}This {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} has been received already.\0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E73E4, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E73E4:
    .string "#+This is not an #CGA-OK Mail#R.\0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E7440, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E7440:
    .string "#+This #CGA-OK Mail#R cannot be used.\0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E74A0, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E74A0:
    .string "#+This is not a #CGThank-You Mail#R.\0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E7500, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E7500:
    .string "#+This #CGThank-You Mail#R cannot be used.\0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E7564, 0xC
    .4byte CheckAgain_80E7234, 0xC
    .4byte 0, 0xA

sUnknown_80E7564:
    .string "#+This is not a #CGWonder Mail#R.\0"
    .align 2, 0

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
    .4byte Error_80E7268, 0xC
    .4byte sUnknown_80E75CC, 0xC
    .4byte sUnknown_80E75C0, 0xC
    .4byte 0, 0xA

sUnknown_80E75C0:
    .string "#+new mail.\0"
    .align 2, 0

sUnknown_80E75CC:
    .string "#+There is no space for receiving\0"
    .align 2, 0

    .string "pksdir0\0"

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
    .4byte ResumeQuicksave_80E7668, 0x5
    .4byte IsThatOK_80E765C, 0x5
    .4byte 0, 0x3

IsThatOK_80E765C:
    .string "Is that OK?\0"
    .align 2, 0

ResumeQuicksave_80E7668:
    .string "Resuming from quicksave.\0"
    .align 2, 0

	.global gResumeAdventureMenuItems
gResumeAdventureMenuItems: @ 80E7684
    .4byte ResumeAdventure_80E769C, 0x5
    .4byte IsThatOK_80E765C, 0x5
    .4byte 0, 0x3

ResumeAdventure_80E769C:
    .string "Resuming saved adventure.\0"
    .align 2, 0

	.global gQuitWaitingRescueMenuItems
gQuitWaitingRescueMenuItems: @ 80E76B8
    .4byte QuitAwaitingRescue_80E76D0, 0x5
    .4byte IsThatOK_80E765C, 0x5
    .4byte 0, 0x3

QuitAwaitingRescue_80E76D0:
    .string "Quit awaiting rescue?\0"
    .align 2, 0

	.global gDeleteSavePromptMenuItems
gDeleteSavePromptMenuItems: @ 80E76E8
        .4byte Deleted_80E7718, 0x5
        .4byte Deleted_80E7700, 0x5
        .4byte 0, 0x3

Deleted_80E7700:
    .string "deleted. Is that OK?\0"
    .align 2, 0

Deleted_80E7718:
    .string "Your saved data will be\0"
    .align 2, 0

	.global gDeleteSaveConfirmMenuItems
gDeleteSaveConfirmMenuItems: @ 80E7730
    .4byte Deleted_80E7768, 0x5
    .4byte Deleted_80E7748, 0x5
    .4byte 0, 0x3

Deleted_80E7748:
    .string "delete all of your saved data?\0"
    .align 2, 0

Deleted_80E7768:
    .string "Are you sure you want to\0"
    .align 2, 0

	.global gUnknown_80E7784
gUnknown_80E7784: @ 80E7784
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x17, 0x00, 0x0F, 0x00
        .byte 0x05, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

