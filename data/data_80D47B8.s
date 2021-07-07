	.section .rodata

        .global gUnknown_80D47B8
gUnknown_80D47B8: @ 80D47B8
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00

        .global UnkData_80D47C4
        UnkData_80D47C4:
        .byte 0x01, 0x00, 0x10, 0x00

	.global gUnknown_80D47C8
gUnknown_80D47C8: @ 80D47C8
@ replacing .incbin "baserom.gba", 0x000d47c8, 0x60
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x0c, 0x00
        .byte 0x0c, 0x00, 0x00, 0x00

        .4byte UnkData_80D47C4

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D4828
gUnknown_80D4828: @ 80D4828
        .string "#C%c%s\0"
        .align 2,0

	.global gUnknown_80D4830
gUnknown_80D4830: @ 80D4830
        .byte 0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0xe8, 0x03, 0x00, 0x00, 0x10, 0x27, 0x00, 0x00, 0xa0, 0x86, 0x01, 0x00, 0x40, 0x42, 0x0f, 0x00, 0x80, 0x96, 0x98, 0x00
        .byte 0x00, 0xe1, 0xf5, 0x05
        .asciz "pksdir0"


	.global gUnknown_80D485C
gUnknown_80D485C: @ 80D485C
        .4byte Yes_80D4878
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte No_80D4874
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte -1

        .global No_80D4874
        No_80D4874:
        .string "No\0"
        .align 2,0
        .global Yes_80D4878
        Yes_80D4878:
        .string "*Yes\0"
        .align 2,0

	.global gUnknown_80D4880
gUnknown_80D4880: @ 80D4880
        .4byte Yes_80D489C
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte No_80D4898
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00 @ End of table
        .4byte -1

        .global No_80D4898
        No_80D4898:
        .string "*No\0"
        .global Yes_80D489C
        Yes_80D489C:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80D48A0
gUnknown_80D48A0: @ 80D48A0
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00

	.global gUnknown_80D48AC
gUnknown_80D48AC: @ 80D48AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48C4
gUnknown_80D48C4: @ 80D48C4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0f, 0x00
        .byte 0x1a, 0x00, 0x05, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48DC
gUnknown_80D48DC: @ 80D48DC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x08, 0x00
        .byte 0x1a, 0x00, 0x05, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48F4
gUnknown_80D48F4: @ 80D48F4
        .byte 0x3A, 0x20, 0x00, 0x00 @ maybe just a colon and space

	.global gUnknown_80D48F8
gUnknown_80D48F8: @ 80D48F8
        .string "????\0"
        .align 2,0

	.global gUnknown_80D4900
gUnknown_80D4900: @ 80D4900
        .string "%d\0"
        .align 2,0

	.global gUnknown_80D4904
gUnknown_80D4904: @ 80D4904
        .string "%*d\0"
        .align 2,0

	.global gUnknown_80D4908
gUnknown_80D4908: @ 80D4908
        .string "%0*d\0"
        .align 2,0

	.global gUnknown_80D4910
gUnknown_80D4910: @ 80D4910
        .string "$\0"
        .align 2,0
        .string "pksdir0\0"

        .global Yes_80D491C
        Yes_80D491C:
        .string "Yes\0"

	.global gUnknown_80D4920
gUnknown_80D4920: @ 80D4920
        .4byte Yes_80D491C

        .global No_80D4924
        No_80D4924:
        .string "No\0"
        .align 2,0

	.global gUnknown_80D4928
gUnknown_80D4928: @ 80D4928
        .4byte No_80D4924

        .global CancelText
        CancelText:
        .string "Cancel\0"
        .align 2,0

	.global gUnknown_80D4934
gUnknown_80D4934: @ 80D4934
        .4byte CancelText

        .global TrashText
        TrashText:
        .string "Trash \0"
        .align 2,0

	.global gUnknown_80D4940
gUnknown_80D4940: @ 80D4940
        .4byte TrashText

        .global DeleteText
        DeleteText:
        .string "Delete\0"
        .align 2,0

	.global gUnknown_80D494C
gUnknown_80D494C: @ 80D494C
        .4byte DeleteText

        .global StoreText
        StoreText:
        .string "Store\0"
        .align 2,0

	.global gUnknown_80D4958
gUnknown_80D4958: @ 80D4958
        .4byte StoreText

        .global TakeText
        TakeText:
        .string "Take\0"
        .align 2,0

	.global gUnknown_80D4964
gUnknown_80D4964: @ 80D4964
        .4byte TakeText

        .global InfoText
        InfoText:
        .string "Info\0"
        .align 2,0

	.global gUnknown_80D4970
gUnknown_80D4970: @ 80D4970
        .4byte InfoText

        .global BuyText
        BuyText:
        .string "Buy\0"
        .align 2,0

	.global gUnknown_80D4978
gUnknown_80D4978: @ 80D4978
        .4byte BuyText

        .global SellText
        SellText:
        .string "Sell \0"
        .align 2,0

	.global gUnknown_80D4984
gUnknown_80D4984: @ 80D4984
        .4byte SellText

        .global AcceptText
        AcceptText:
        .string "Accept\0"
        .align 2,0

	.global gUnknown_80D4990
gUnknown_80D4990: @ 80D4990
        .4byte AcceptText

        .global WigglytuffCheck
        WigglytuffCheck:
        .string "Check\0"
        .align 2,0

	.global gWigglytuffCheck
gWigglytuffCheck: @ 80D499C
        .4byte WigglytuffCheck

        .global FriendText
        FriendText:
        .string "Friend\0"
        .align 2,0

	.global gUnknown_80D49A8
gUnknown_80D49A8: @ 80D49A8
        .4byte FriendText

        .global ExitText
        ExitText:
        .string "Exit\0"
        .align 2,0

	.global gUnknown_80D49B4
gUnknown_80D49B4: @ 80D49B4
        .4byte ExitText

        .global QuestionMarkText
        QuestionMarkText:
        .string "???\0"
        .align 2,0

	.global gUnknown_80D49BC
gUnknown_80D49BC: @ 80D49BC
        .4byte QuestionMarkText

        .global FelicityDeposit
        FelicityDeposit:
        .string "Deposit?\0"
        .align 2,0

	.global gFelicityDeposit
gFelicityDeposit: @ 80D49CC
        .4byte FelicityDeposit

        .global FelicityWithdraw
        FelicityWithdraw:
        .string "Withdraw?\0"
        .align 2,0

	.global gFelicityWithdraw
gFelicityWithdraw: @ 80D49DC
        .4byte FelicityWithdraw

	.global gFelicityDialogue
gFelicityDialogue: @ 80D49E0 (Felicity Bank Dialogue)
	.incbin "baserom.gba", 0xD49E0, 0xA24

	.global gUnknown_80D5404
gUnknown_80D5404: @ 80D5404
	.incbin "baserom.gba", 0xD5404, 0xAC4

	.global gKecleonShopDialogue
gKecleonShopDialogue: @ 80D5EC8 (Kecleon Wares Dialogue)
	.incbin "baserom.gba", 0xD5EC8, 0x1ADC

	.global gWigglytuffDialogue
gWigglytuffDialogue: @ 80D79A4 (Friend Area Shop)
	.incbin "baserom.gba", 0xD79A4, 0xEE4

	.global gGulpinDialogue
gGulpinDialogue: @ 80D8888 (Gulpin Link Shop)
	.incbin "baserom.gba", 0xD8888, 0x1740

	.global gMakuhitaDialogue
gMakuhitaDialogue: @ 80D9FC8 (Makuhita Dojo)
	.incbin "baserom.gba", 0xD9FC8, 0xAD0

	.global gUnknown_80DAA98
gUnknown_80DAA98: @ 80DAA98 (Help Menu?)
	.incbin "baserom.gba", 0xDAA98, 0x4D8

	.global gUnknown_80DAF70
gUnknown_80DAF70: @ 80DAF70
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DAF88
gUnknown_80DAF88: @ 80DAF88
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x0c, 0x00
        .byte 0x0c, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DAFA0
gUnknown_80DAFA0: @ 80DAFA0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DAFC0
gUnknown_80DAFC0: @ 80DAFC0
	.incbin "baserom.gba", 0xDAFC0, 0xD8

	.global gUnknown_80DB098
gUnknown_80DB098: @ 80DB098
	.incbin "baserom.gba", 0xDB098, 0x60

	.global gUnknown_80DB0F8
gUnknown_80DB0F8: @ 80DB0F8
	.incbin "baserom.gba", 0xDB0F8, 0x3FC

	.global gUnknown_80DB4F4
gUnknown_80DB4F4: @ 80DB4F4
	.incbin "baserom.gba", 0xDB4F4, 0x44

	.global gUnknown_80DB538
gUnknown_80DB538: @ 80DB538
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB550
gUnknown_80DB550: @ 80DB550
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x0a, 0x00
        .byte 0x1c, 0x00
        .byte 0x09, 0x00
        .byte 0x09, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DB568
gUnknown_80DB568: @ 80DB568
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x00, 0x00
        .byte 0x04, 0x00
        .byte 0x03, 0x00
        .byte 0x16, 0x00
        .byte 0x05, 0x00
        .byte 0x05, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DB580
gUnknown_80DB580: @ 80DB580
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x00, 0x00
        .byte 0x01, 0x00
        .byte 0x02, 0x00
        .byte 0x1c, 0x00
        .byte 0x07, 0x00
        .byte 0x07, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DB598
gUnknown_80DB598: @ 80DB598
        .string "#C4OVR#R\0"
        .align 2,0

	.global gUnknown_80DB5A4
gUnknown_80DB5A4: @ 80DB5A4
        .string "#C6INS#R\0"
        .align 2,0

	.global gUnknown_80DB5B0
gUnknown_80DB5B0: @ 80DB5B0
        .string "#C%c"
        .byte 0x81, 0x59
        .align 2,0

	.global gUnknown_80DB5B8
gUnknown_80DB5B8: @ 80DB5B8
        .string "#C%c%s\0"
        .align 2,0

	.global gUnknown_80DB5C0
gUnknown_80DB5C0: @ 80DB5C0
        .string "What is your name?\0"
        .align 2,0

	.global gUnknown_80DB5D4
gUnknown_80DB5D4: @ 80DB5D4
        .string "What is this Pokémon~27s nickname?\0"
        .align 2,0

	.global gUnknown_80DB5F8
gUnknown_80DB5F8: @ 80DB5F8
        .string "What is your partner~27s nickname?\0"
        .align 2,0

	.global gUnknown_80DB61C
gUnknown_80DB61C: @ 80DB61C
        .string "What is your team~27s name?\0"
        .align 2,0

	.global gUnknown_80DB638
gUnknown_80DB638: @ 80DB638
        .string "Please enter the password.\0"
        .align 2,0

	.global gUnknown_80DB654
gUnknown_80DB654: @ 80DB654
        .string "#C2%s#R\0"
        .align 2,0

	.global gUnknown_80DB65C
gUnknown_80DB65C: @ 80DB65C
        .string "#C5%s#R\0"
        .align 2,0

	.global gUnknown_80DB664
gUnknown_80DB664: @ 80DB664
        .string "%s\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB688
gUnknown_80DB688: @ 80DB688
        .string "Is the name #C5$m0#R OK?\0"
        .align 2,0

	.global gUnknown_80DB6A4
gUnknown_80DB6A4: @ 80DB6A4
        .string "This name is too long.\0"
        .align 2,0

	.global gUnknown_80DB6BC
gUnknown_80DB6BC: @ 80DB6BC
        .string "Please enter a name.\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB6DC
gUnknown_80DB6DC: @ 80DB6DC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB6F4
gUnknown_80DB6F4: @ 80DB6F4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x03, 0x00
        .byte 0x1a, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB70C
gUnknown_80DB70C: @ 80DB70C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x11, 0x00, 0x08, 0x00
        .byte 0x0b, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gFelicityMoney
gFelicityMoney: @ 80DB724
        .string "Money: \0"
        .align 2,0

	.global gFelicitySavings
gFelicitySavings: @ 80DB72C
        .string "Savings: \0"
        .align 2,0

	.global gUnknown_80DB738
gUnknown_80DB738: @ 80DB738
        .string "Money\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DB748
gUnknown_80DB748: @ 80DB748
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB760
gUnknown_80DB760: @ 80DB760
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB778
gUnknown_80DB778: @ 80DB778
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x09, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB790
gUnknown_80DB790: @ 80DB790
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB7A8
gUnknown_80DB7A8: @ 80DB7A8
        .string "Number?\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB7B8
gUnknown_80DB7B8: @ 80DB7B8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB7D0
gUnknown_80DB7D0: @ 80DB7D0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB7E8
gUnknown_80DB7E8: @ 80DB7E8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB800
gUnknown_80DB800: @ 80DB800
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x09, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB818
gUnknown_80DB818: @ 80DB818
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB830
gUnknown_80DB830: @ 80DB830
        .string "Number?\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB840
gUnknown_80DB840: @ 80DB840
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB858
gUnknown_80DB858: @ 80DB858
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB870
gUnknown_80DB870: @ 80DB870
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x09, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB888
gUnknown_80DB888: @ 80DB888
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB8A0
gUnknown_80DB8A0: @ 80DB8A0
        .string "Sell All\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB8B4
gUnknown_80DB8B4: @ 80DB8B4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB8CC
gUnknown_80DB8CC: @ 80DB8CC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x10, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB8E4
gUnknown_80DB8E4: @ 80DB8E4
        .string "Goods\0"
        .align 2,0

	.global gUnknown_80DB8EC
gUnknown_80DB8EC: @ 80DB8EC
        .string "#C2%s#R\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB8FC
gUnknown_80DB8FC: @ 80DB8FC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB914
gUnknown_80DB914: @ 80DB914
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x10, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DB92C
gUnknown_80DB92C: @ 80DB92C
        .string "Goods\0"
        .align 2,0

	.global gUnknown_80DB934
gUnknown_80DB934: @ 80DB934
        .string "#C2%s#R\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB944
gUnknown_80DB944: @ 80DB944
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.global gUnknown_80DB95C
gUnknown_80DB95C: @ 80DB95C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x10, 0x00, 0x11, 0x00
        .byte 0x13, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.global gTeamToolboxA
gTeamToolboxA: @ 80DB974
        .string "Team Toolbox A\0"
        .align 2,0

	.global gTeamToolboxB
gTeamToolboxB: @ 80DB984
        .string "Team Toolbox B\0"
        .align 2,0

	.global gUnknown_80DB994
gUnknown_80DB994: @ 80DB994
        .string "#C"
        .byte 0x02
        .string "$i0#R\0"
        .align 2,0

	.global gUnknown_80DB9A0
gUnknown_80DB9A0: @ 80DB9A0
        .string "#C2%s#R\0"
        .align 2,0

	.global gUnknown_80DB9A8
gUnknown_80DB9A8: @ 80DB9A8
        .string "Items\0"
        .align 2,0

	.global gUnknown_80DB9B0
gUnknown_80DB9B0: @ 80DB9B0
        .string "/\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DB9BC
gUnknown_80DB9BC: @ 80DB9BC
        .string "#+Who will learn the move\n"
        .string "#+#C5$m7#R?\0"
        .align 2,0

	.global gUnknown_80DB9E4
gUnknown_80DB9E4: @ 80DB9E4
        .string "#+#CM$m8#R learned\n"
        .string "#+the move #C5$m7#R!\0"
        .align 2,0

	.global gUnknown_80DBA0C
gUnknown_80DBA0C: @ 80DBA0C
        .string "#+No one in the current team\n"
        .string "#+can learn this move. \0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBA4C
gUnknown_80DBA4C: @ 80DBA4C
        .string "$m0\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBA58
gUnknown_80DBA58: @ 80DBA58
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBA70
gUnknown_80DBA70: @ 80DBA70
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBA88
gUnknown_80DBA88: @ 80DBA88
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0E, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBAA0
gUnknown_80DBAA0: @ 80DBAA0
        .string "#+#CN$m0#R received\n"
        .string "#+the promised #C4$i0#R. \0"
        .align 2,0

	.global gUnknown_80DBAD0
gUnknown_80DBAD0: @ 80DBAD0
        .string "#+#CN$m0#R~27s team received\n"
        .string "#+the promised #C4$i0#R.\0"
        .align 2,0

	.global gUnknown_80DBB08
gUnknown_80DBB08: @ 80DBB08
        .string "#+The team also received\n"
        .string "#+the item #C4$i0#R.\0"
        .align 2,0

	.global gUnknown_80DBB38
gUnknown_80DBB38: @ 80DBB38
        .string "#+Received the #C4$i0#R!#P#+A very rare statue. It has been placed\n"
        .string "#+outside your rescue team base.\0"
        .align 2,0

	.global gUnknown_80DBB9C
gUnknown_80DBB9C: @ 80DBB9C
        .string "#+The #C4$i0#R...\n"
        .string "#+You~27ve already acquired it.#P#+Sorry to see that...#P#+In its place~2c #CN$m0#R~2c\n"
        .string "#+you can have #CG1~2c000#R "
        .byte 0x83, 0xBF, 0x83, 0xC4, 0x2E
        .align 2,0

	.global gUnknown_80DBC28
gUnknown_80DBC28: @ 80DBC28
        .string "#+Your Toolbox is full.\n"
        .string "#+The item was sent to storage.\0"
        .align 2,0

	.global gUnknown_80DBC60
gUnknown_80DBC60: @ 80DBC60
        .string "#+Your Toolbox is full.\n"
        .string "#+What would you like to do?\0"
        .align 2,0

	.global gUnknown_80DBC98
gUnknown_80DBC98: @ 80DBC98
        .string "#+Is it OK to throw away\n"
        .string "#+this #C4$i0#R?\0"
        .align 2,0

	.global gUnknown_80DBCC4
gUnknown_80DBCC4: @ 80DBCC4
        .string "#+The #C4$i0#R\n"
        .string "#+was thrown away.\0"
        .align 2,0

	.global gUnknown_80DBCE8
gUnknown_80DBCE8: @ 80DBCE8
        .string "#+The #C4$i1#R was put in\n"
        .string "#+storage to get the #C4$i0#R.\0"
        .align 2,0

	.global gUnknown_80DBD24
gUnknown_80DBD24: @ 80DBD24
        .string "#+The #C4$i1#R was discarded\n"
        .string "#+to get the #C4$i0#R.\0"
        .align 2,0

	.global gKangaskhanTrashToolboxItem
gKangaskhanTrashToolboxItem: @ 80DBD58
        .string "Trash Toolbox Item\0"
        .align 2,0

	.global gKangaskhanTrashReceivedItem
gKangaskhanTrashReceivedItem: @ 80DBD6C
        .string "Trash Received Item\0"
        .align 2,0

	.global gKangaskhanStorage
gKangaskhanStorage: @ 80DBD80
        .string "Storage\0"
        .align 2,0

	.global gKangaskhanTrash
gKangaskhanTrash: @ 80DBD88
        .string "Trash\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBD98
gUnknown_80DBD98: @ 80DBD98
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.global gUnknown_80DBDB0
gUnknown_80DBDB0: @ 80DBDB0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBDC8
gUnknown_80DBDC8: @ 80DBDC8
        .string "Switch\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBDD8
gUnknown_80DBDD8: @ 80DBDD8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBDF0
gUnknown_80DBDF0: @ 80DBDF0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x10, 0x00, 0x11, 0x00
        .byte 0x13, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBE08
gUnknown_80DBE08: @ 80DBE08
        .string "IQ Skills\0"
        .align 2,0

	.global gUnknown_80DBE14
gUnknown_80DBE14: @ 80DBE14
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_80DBE18
gUnknown_80DBE18: @ 80DBE18
        .byte 0x87, 0x40, 0x00, 0x00

	.global gUnknown_80DBE1C
gUnknown_80DBE1C: @ 80DBE1C
        .string "$i0$i1\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBE2C
gUnknown_80DBE2C: @ 80DBE2C
        .string "$i0\0"
        .align 2,0

	.global gUnknown_80DBE30
gUnknown_80DBE30: @ 80DBE30
        .string "$m0\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBE3C
gUnknown_80DBE3C: @ 80DBE3C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBE54
gUnknown_80DBE54: @ 80DBE54
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x10, 0x00, 0x0E, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBE6C
gUnknown_80DBE6C: @ 80DBE6C
        .string "Storage\0"
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBE7C
gUnknown_80DBE7C: @ 80DBE7C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global UnkData_80DBE94
        UnkData_80DBE94:
        .byte 0x01, 0x00, 0x07, 0x00

	.global gUnknown_80DBE98
gUnknown_80DBE98: @ 80DBE98
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x09, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x00, 0x00

        .4byte UnkData_80DBE94

	.global gUnknown_80DBEB0
gUnknown_80DBEB0: @ 80DBEB0
        .byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x08, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
        .byte 0x0c, 0x00, 0x04, 0x00, 0x10, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0e, 0x00, 0x1a, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gMenuItems
gMenuItems: @ 80DBF10
        .string "Items\0"
        .align 2,0

	.global gMenuTeam
gMenuTeam: @ 80DBF18
        .string "Team\0"
        .align 2,0

	.global gMenuJobList
gMenuJobList: @ 80DBF20
        .string "Job List\0"
        .align 2,0

	.global gMenuOthers
gMenuOthers: @ 80DBF2C
        .string "Others\0"
        .align 2,0

	.global gUnknown_80DBF34
gUnknown_80DBF34: @ 80DBF34
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x00, 0x00

	.global gUnknown_80DBF3C
gUnknown_80DBF3C: @ 80DBF3C
        .string "%s #C5%d#R Pts.\0"
        .align 2,0

	.global gUnknown_80DBF4C
gUnknown_80DBF4C: @ 80DBF4C
        .string "Money: #C5%d#R "
        .byte 0x83, 0xBF, 0x83, 0xC4
        .align 2,0

	.global gTeamRankBadgeFileName
gTeamRankBadgeFileName: @ 80DBF60
        .string "tmrkpat\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBF70
gUnknown_80DBF70: @ 80DBF70
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBF88
gUnknown_80DBF88: @ 80DBF88
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x11, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DBFA0
gUnknown_80DBFA0: @ 80DBFA0
        .string "Field\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DBFB0
gUnknown_80DBFB0: @ 80DBFB0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global UnkData_80DBFC8
        UnkData_80DBFC8:
        .byte 0x01, 0x00, 0x07, 0x00

	.global gUnknown_80DBFCC
gUnknown_80DBFCC: @ 80DBFCC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0A, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        
        .4byte UnkData_80DBFC8

	.global gOthers_MenuOption
gOthers_MenuOption: @ 80DBFE4
        .string "Others\0"
        .align 2,0

	.global gUnknown_80DBFEC
gUnknown_80DBFEC: @ 80DBFEC
        .string "Change settings?\0"
        .align 2,0

	.global gOthers_GameOptions
gOthers_GameOptions: @ 80DC000
        .string "Game Options\0"
        .align 2,0

	.global gOthers_Hints
gOthers_Hints: @ 80DC010
        .string "Hints\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC020
gUnknown_80DC020: @ 80DC020
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global UnkData_80DC038
        UnkData_80DC038:
        .byte 0x01, 0x00, 0x0a, 0x00

	.global gUnknown_80DC03C
gUnknown_80DC03C: @ 80DC03C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x10, 0x00
        .byte 0x12, 0x00, 0x00, 0x00

        .4byte UnkData_80DC038

@ Window Settings

	.global gWindowBGTitle
gWindowBGTitle: @ 80DC054
        .string "Game Options\0"
        .align 2,0

	.global gUnknown_80DC064
gUnknown_80DC064: @ 80DC064
        .string "Windows#=P.Blue#=x.Red#="
        .byte 0xA0
        .string ".Green\0"
        .align 2,0

	.global gWindowBGBlueString
gWindowBGBlueString: @ 80DC084
        .string "Blue\0"
        .align 2,0

	.global gWindowBGRedString
gWindowBGRedString: @ 80DC08C
        .string "Red\0"
        .align 2,0

	.global gWindowBGGreenString
gWindowBGGreenString: @ 80DC090
        .string "Green\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC0A0
gUnknown_80DC0A0: @ 80DC0A0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global Data_80DC0B8
        Data_80DC0B8:
        .byte 0x01, 0x00, 0x08, 0x00

	.global gUnknown_80DC0BC
gUnknown_80DC0BC: @ 80DC0BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x0E, 0x00
        .byte 0x0E, 0x00, 0x00, 0x00

        .4byte Data_80DC0B8

	.global gUnknown_80DC0D4
gUnknown_80DC0D4: @ 80DC0D4
        .string "Hints\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC0E4
gUnknown_80DC0E4: @ 80DC0E4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC0FC
gUnknown_80DC0FC: @ 80DC0FC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC11C
gUnknown_80DC11C: @ 80DC11C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC134
gUnknown_80DC134: @ 80DC134
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC164
gUnknown_80DC164: @ 80DC164
        .string "Only four moves may be learned!\n"
        .string "Will a move be forgotten?\0"
        .align 2,0

	.global gUnknown_80DC1A0
gUnknown_80DC1A0: @ 80DC1A0
        .string "#+Forget the move #C4$m1#R and\n"
        .string "#+any moves linked to it~2c and learn the move\n"
        .string "#+#C5$m0#R?\0"
        .align 2,0

	.global gUnknown_80DC1FC
gUnknown_80DC1FC: @ 80DC1FC
        .string "#+Forget the move #C4$m1#R\n"
        .string "#+and learn #C5$m0#R?\0"
        .align 2,0

	.global gUnknown_80DC230
gUnknown_80DC230: @ 80DC230
        .string "Forget\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC240
gUnknown_80DC240: @ 80DC240
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global Data_80DC258
        Data_80DC258:
        .byte 0x01, 0x00, 0x0f, 0x00

	.global gUnknown_80DC25C
gUnknown_80DC25C: @ 80DC25C
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x12, 0x00
        .byte 0x08, 0x00
        .byte 0x08, 0x00
        .byte 0x00, 0x00

        .4byte Data_80DC258

	.global gUnknown_80DC274
gUnknown_80DC274: @ 80DC274
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0f, 0x00
        .byte 0x1a, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC28C
gUnknown_80DC28C: @ 80DC28C
        .string "Moves: #C6$m0#R \0"
        .align 2,0

	.global gUnknown_80DC2A0
gUnknown_80DC2A0: @ 80DC2A0
        .string "$i0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC2AC
gUnknown_80DC2AC: @ 80DC2AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC2C4
gUnknown_80DC2C4: @ 80DC2C4
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x0f, 0x00
        .byte 0x04, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DC2DC
gUnknown_80DC2DC: @ 80DC2DC
        .string "Moves Page: %d/%d \0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC2F8
gUnknown_80DC2F8: @ 80DC2F8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC310
gUnknown_80DC310: @ 80DC310
        .string "$m0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC31C
gUnknown_80DC31C: @ 80DC31C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC334
gUnknown_80DC334: @ 80DC334
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x04, 0x00
        .byte 0x08, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC34C
gUnknown_80DC34C: @ 80DC34C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC37C
gUnknown_80DC37C: @ 80DC37C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x03, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC394
gUnknown_80DC394: @ 80DC394
        .string "{R_BUTTON}+{DPAD}: Shift moves\n"
        .string "{R_BUTTON}+{A_BUTTON}: Switch link  {SELECT_BUTTON} Set\0"

	.global gGulpinProceed
gGulpinProceed: @ 80DC3C4
        .string "Proceed\0"
        .align 2,0

	.global gGulpinInfo
gGulpinInfo: @ 80DC3CC
        .string "#C6Info#R \0"
        .align 2,0

	.global gUnknown_80DC3D8
gUnknown_80DC3D8: @ 80DC3D8
        .string "Moves\0"
        .align 2,0

	.global gUnknown_80DC3E0
gUnknown_80DC3E0: @ 80DC3E0
        .string "Summary\0"
        .align 2,0

	.global gUnknown_80DC3E8
gUnknown_80DC3E8: @ 80DC3E8
        .string "Check IQ\0"
        .align 2,0

	.global gUnknown_80DC3F4
gUnknown_80DC3F4: @ 80DC3F4
        .string "Remember\0"
        .align 2,0

	.global gGulpinDeselect
gGulpinDeselect: @ 80DC400
        .string "Deselect\0"
        .align 2,0

	.global gGulpinSet
gGulpinSet: @ 80DC40C
        .string "Set\0"
        .align 2,0

	.global gGulpinLink
gGulpinLink: @ 80DC410
        .string "Link\0"
        .align 2,0

	.global gGulpinDelink
gGulpinDelink: @ 80DC418
        .string "Delink\0"
        .align 2,0

	.global gGulpinForget
gGulpinForget: @ 80DC420
        .string "Forget\0"
        .align 2,0

	.global gUnknown_80DC428
gUnknown_80DC428: @ 80DC428
        .string "Setting moves\0"
        .align 2,0

	.global gUnknown_80DC438
gUnknown_80DC438: @ 80DC438
        .string "Linking moves\0"
        .align 2,0

	.global gUnknown_80DC448
gUnknown_80DC448: @ 80DC448
        .string "Remembering moves\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC464
gUnknown_80DC464: @ 80DC464
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC47C
gUnknown_80DC47C: @ 80DC47C
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DC494
gUnknown_80DC494: @ 80DC494
        .string "Friend Areas\0"
        .align 2,0

	.global gUnknown_80DC4A4
gUnknown_80DC4A4: @ 80DC4A4
        .string "#C2%s#R\0"
        .align 2,0

	.global gUnknown_80DC4AC
gUnknown_80DC4AC: @ 80DC4AC
        .string "#C4%s#R\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC4BC
gUnknown_80DC4BC: @ 80DC4BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global gUnknown_80DC4D4
gUnknown_80DC4D4: @ 80DC4D4
        .byte 0x01, 0x00, 0x12, 0x00

	.global gUnknown_80DC4D8
gUnknown_80DC4D8: @ 80DC4D8
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x1a, 0x00
        .byte 0x11, 0x00
        .byte 0x11, 0x00
        .byte 0x00, 0x00

        .4byte gUnknown_80DC4D4

	.global gUnknown_80DC4F0
gUnknown_80DC4F0: @ 80DC4F0
        .string "Inhabitants (Friends: #c5Light blue#r)\0"
        .align 2,0

	.global gUnknown_80DC518
gUnknown_80DC518: @ 80DC518
        .string "Inhabitants\0"
        .align 2,0

	.global gUnknown_80DC524
gUnknown_80DC524: @ 80DC524
        .string "#c5%s#r\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC534
gUnknown_80DC534: @ 80DC534
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC54C
gUnknown_80DC54C: @ 80DC54C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC564
gUnknown_80DC564: @ 80DC564
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC584
gUnknown_80DC584: @ 80DC584
        .4byte Yes_80DC5A0
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte No_80DC59C
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00

        .global No_80DC59C
        No_80DC59C:
        .string "No\0"
        .align 2,0
        .global Yes_80DC5A0
        Yes_80DC5A0:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80DC5A4
gUnknown_80DC5A4: @ 80DC5A4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5BC
gUnknown_80DC5BC: @ 80DC5BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5D4
gUnknown_80DC5D4: @ 80DC5D4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0b, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC5EC
gUnknown_80DC5EC: @ 80DC5EC
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x00, 0x00

	.global gUnknown_80DC5F4
gUnknown_80DC5F4: @ 80DC5F4
        .string "It doesn~27t appear to be hungry.\0"
        .align 2,0

	.global gUnknown_80DC618
gUnknown_80DC618: @ 80DC618
        .string "$m1 took the Gummi and ate it.\n"
        .string "This Gummi looks like a big favorite!\n"
        .string "$m1~27s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC674
gUnknown_80DC674: @ 80DC674
        .string "$m1 took the Gummi and ate it.\n"
        .string "This Gummi looks like a favorite!\n"
        .string "$m1~27s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC6CC
gUnknown_80DC6CC: @ 80DC6CC
        .string "$m1 took the Gummi and ate it.\n"
        .string "It doesn~27t seem to dislike this Gummi.\n"
        .string "$m1~27s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC728
gUnknown_80DC728: @ 80DC728
        .string "$m1 took the Gummi and ate it.\n"
        .string "It appears to be just a little satisfied.\n"
        .string "$m1~27s IQ went up!\0"
        .align 2,0

	.global gUnknown_80DC788
gUnknown_80DC788: @ 80DC788
        .string "$m1~27s IQ helped it learn how to\n"
        .string "use $i1!\0"
        .align 2,0

	.global gUnknown_80DC7B4
gUnknown_80DC7B4: @ 80DC7B4
        .string "Yes! $m1 grew explosively!\n"
        .string "Attack~2c Defense~2c and so on rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC7FC
gUnknown_80DC7FC: @ 80DC7FC
@ replacing .incbin "baserom.gba", 0x000dc7fc, 0x20
        .string "Yes!\n"
        .string "$m1~27s Attack rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC81C
gUnknown_80DC81C: @ 80DC81C
@ replacing .incbin "baserom.gba", 0x000dc81c, 0x28
        .string "Yes!\n"
        .string "$m1~27s Special Attack rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC844
gUnknown_80DC844: @ 80DC844
@ replacing .incbin "baserom.gba", 0x000dc844, 0x20
        .string "Yes!\n"
        .string "$m1~27s Defense rose by 1!\0"
        .align 2,0


	.global gUnknown_80DC864
gUnknown_80DC864: @ 80DC864
@ replacing .incbin "baserom.gba", 0x000dc864, 0x28
        .string "Yes!\n"
        .string "$m1~27s Special Defense rose by 1!\0"
        .align 2,0

	.global gUnknown_80DC88C
gUnknown_80DC88C: @ 80DC88C
@ replacing .incbin "baserom.gba", 0x000dc88c, 0x20
        .string "You don~27t have any Gummis.\0"
        .align 2,0

	.global gUnknown_80DC8AC
gUnknown_80DC8AC: @ 80DC8AC
@ replacing .incbin "baserom.gba", 0x000dc8ac, 0x1c
        .string "You don~27t have an item.\0"
        .align 2,0

	.global gUnknown_80DC8C8
gUnknown_80DC8C8: @ 80DC8C8
@ replacing .incbin "baserom.gba", 0x000dc8c8, 0x14
        .string "The Gummi is gone!\0"
        .align 2,0

	.global gUnknown_80DC8DC
gUnknown_80DC8DC: @ 80DC8DC
        .string "The item is gone!\0"
        .align 2,0

	.global gUnknown_80DC8F0
gUnknown_80DC8F0: @ 80DC8F0
        .string "Give\0"
        .align 2,0

	.global gUnknown_80DC8F8
gUnknown_80DC8F8: @ 80DC8F8
@ replacing .incbin "baserom.gba", 0x000dc8f8, 0xc
        .string "Use\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC904
gUnknown_80DC904: @ 80DC904
@ replacing .incbin "baserom.gba", 0x000dc904, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC91C
gUnknown_80DC91C: @ 80DC91C
@ replacing .incbin "baserom.gba", 0x000dc91c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0f, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC934
gUnknown_80DC934: @ 80DC934
@ replacing .incbin "baserom.gba", 0x000dc934, 0x8
        .string "Pokémon\0"
        .align 2,0

	.global gUnknown_80DC93C
gUnknown_80DC93C: @ 80DC93C
@ replacing .incbin "baserom.gba", 0x000dc93c, 0x14
        .string "#c%c%s#r\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC950
gUnknown_80DC950: @ 80DC950
@ replacing .incbin "baserom.gba", 0x000dc950, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC968
gUnknown_80DC968: @ 80DC968
@ replacing .incbin "baserom.gba", 0x000dc968, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0f, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC980
gUnknown_80DC980: @ 80DC980
@ replacing .incbin "baserom.gba", 0x000dc980, 0x8
        .string "Friends\0"

	.global gUnknown_80DC988
gUnknown_80DC988: @ 80DC988
@ replacing .incbin "baserom.gba", 0x000dc988, 0x10
        .string "Pokémon Friends\0"

	.global gUnknown_80DC998
gUnknown_80DC998: @ 80DC998
@ replacing .incbin "baserom.gba", 0x000dc998, 0xc
        .string "#c%c%s#r\0"
        .align 2,0

	.global gUnknown_80DC9A4
gUnknown_80DC9A4: @ 80DC9A4
@ replacing .incbin "baserom.gba", 0x000dc9a4, 0xc
        .string "%s\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC9B0
gUnknown_80DC9B0: @ 80DC9B0
@ replacing .incbin "baserom.gba", 0x000dc9b0, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DC9C8
gUnknown_80DC9C8: @ 80DC9C8
@ replacing .incbin "baserom.gba", 0x000dc9c8, 0x20
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x12, 0x00, 0x0e, 0x00
        .byte 0x12, 0x00, 0x02, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80DC9E8
gUnknown_80DC9E8: @ 80DC9E8
@ replacing .incbin "baserom.gba", 0x000dc9e8, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DCA00
gUnknown_80DCA00: @ 80DCA00
@ replacing .incbin "baserom.gba", 0x000dca00, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DCA18
gUnknown_80DCA18: @ 80DCA18
        .string "Evolve\0"
        .align 2,0
        .4byte gUnknown_80DCA18

	.global gUnknown_80DCA24
gUnknown_80DCA24: @ 80DCA24
        .string "No\0"
        .align 2,0
        .4byte gUnknown_80DCA24

	.global gUnknown_80DCA2C
gUnknown_80DCA2C: @ 80DCA2C
@ replacing .incbin "baserom.gba", 0x000dca2c, 0x8
        .string "Yes\0"
        .align 2,0
        .4byte gUnknown_80DCA2C

	.include "data/text/luminous_cave.inc"

        .include "data/friend_area.inc"

	.include "data/text/party_menu.inc"

	.global gUnknown_80DD6EC
gUnknown_80DD6EC: @ 80DD6EC
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DD704
gUnknown_80DD704: @ 80DD704
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x04, 0x00
        .byte 0x09, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DD71C
gUnknown_80DD71C: @ 80DD71C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DD74C
gUnknown_80DD74C: @ 80DD74C
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x11, 0x00
        .byte 0x1A, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DD764
gUnknown_80DD764: @ 80DD764
        .string "You have chosen to say farewell\n"
        .string "to this Pokémon.#P"
        .string "The Pokémon will leave its Friend Area.\n"
        .string "It will no longer be available for\n"
        .string "adventures. Is that OK?\0"
        .align 2,0

	.global gUnknown_80DD7FC
gUnknown_80DD7FC: @ 80DD7FC
        .string "If you say farewell to this\n"
        .string "Pokémon~2c it will be gone forever.#P"
        .string "You will never be able to get another one\n"
        .string "like it to join your team.\n"
        .string "Will you release it anyway?\0"
        .align 2,0

	.global gUnknown_80DD8A0
gUnknown_80DD8A0: @ 80DD8A0
        .string "#+The #C4$i0#R was\n"
        .string "#+returned to the Toolbox.\0"
        .align 2,0

	.global gUnknown_80DD8D0
gUnknown_80DD8D0: @ 80DD8D0
        .string "#+The #C4$i0#R was\n#+sent to storage.\0"
        .align 2,0

	.global gFriendActionStandby
gFriendActionStandby: @ 80DD8F8
        .string "Stand By\0"
        .align 2,0

	.global gFriendActionMakeLeader
gFriendActionMakeLeader: @ 80DD904
        .string "Make Leader\0"

	.global gFriendActionJoinTeam
gFriendActionJoinTeam: @ 80DD910
        .string "Join Team\0"
        .align 2,0

	.global gFriendActionSayFarewell
gFriendActionSayFarewell: @ 80DD91C
        .string "Say Farewell\0"
        .align 2,0

	.global gFriendActionGive
gFriendActionGive: @ 80DD92C
        .string "Give\0"
        .align 2,0

	.global gFriendActionTake
gFriendActionTake: @ 80DD934
        .string "Take\0"
        .align 2,0

	.global gFriendActionSummary
gFriendActionSummary: @ 80DD93C
        .string "Summary\0"
        .align 2,0

	.global gFriendActionMoves
gFriendActionMoves: @ 80DD944
        .string "Moves\0"
        .align 2,0

	.global gFriendActionCheckIQ
gFriendActionCheckIQ: @ 80DD94C
        .string "Check IQ\0"
        .align 2,0

	.global gUnknown_80DD958
gUnknown_80DD958: @ 80DD958
        .string "Item: #C4$i0#R \0"
        .string "pksdir0\0"

	.global gUnknown_80DD970
gUnknown_80DD970: @ 80DD970
@ replacing .incbin "baserom.gba", 0x000dd970, 0x7c
        .4byte gWonderMailReceiveSOSMail
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte gWonderMailLeaveForRescue
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte gWonderMailSendAOKMail
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte gWonderMailDeleteMail
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailCancel @ 80DD9A0
        gWonderMailCancel:
        .string "Cancel\0"
        .align 2,0

        .global gWonderMailDeleteMail @ 80DD9A8
        gWonderMailDeleteMail:
        .string "Delete Mail\0"
        .align 2,0

        .global gWonderMailSendAOKMail @ 80DD9B4
        gWonderMailSendAOKMail:
        .string "Send A-OK Mail\0"
        .align 2,0

        .global gWonderMailLeaveForResuce @ 80DD9C4
        gWonderMailLeaveForRescue:
        .string "Leave for Rescue\0"
        .align 2,0

        .global gWonderMailReceiveSOSMail @ 80DD9D8
        gWonderMailReceiveSOSMail:
        .string "Receive SOS Mail\0"
        .align 2,0

	.global gUnknown_80DD9EC
gUnknown_80DD9EC: @ 80DD9EC
@ replacing .incbin "baserom.gba", 0x000dd9ec, 0x5c
        .4byte gWonderMailDeleteSOSMail
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte gWonderMailDeleteAOKMail
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte gWonderMailDeleteAllMail
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailDeleteAllMail @ 80DDA14
        gWonderMailDeleteAllMail:
        .string "Delete All Mail\0"
        .align 2,0

        .global gWonderMailDeleteAOKMail @ 80DDA24
        gWonderMailDeleteAOKMail:
        .string "Delete A-OK Mail\0"
        .align 2,0

        .global gWonderMailDeleteSOSMail @ 80DDA38
        gWonderMailDeleteSOSMail:
        .string "Delete SOS Mail\0"
        .align 2,0

	.global gUnknown_80DDA48
gUnknown_80DDA48: @ 80DDA48
@ Menu that shows up when you enter an incorrect Wonder Mail Password
@ replacing .incbin "baserom.gba", 0x000dda48, 0x1c
        .4byte gWonderMailYes
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailYes @ (80DDA60)
        gWonderMailYes:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80DDA64
gUnknown_80DDA64: @ 80DDA64
@ replacing .incbin "baserom.gba", 0x000dda64, 0x1c
        .4byte gWonderMailYes
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte gWonderMailNo
        .byte 0x09, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global gWonderMailNo @ (80DDA7C)
        gWonderMailNo:
        .string "No\0"
        .align 2,0

	.global gUnknown_80DDA80
gUnknown_80DDA80: @ 80DDA80
@ replacing .incbin "baserom.gba", 0x000dda80, 0x20
        .4byte gWonderMailYes
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte gWonderMailNo
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

	.global gUnknown_80DDAA0
gUnknown_80DDAA0: @ 80DDAA0
        .4byte SendWOPokemon
        .byte 0x12, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .global SendWOPokemon
        SendWOPokemon:
        .string "Send w/o Pokémon\0"
        .align 2,0

	.global gUnknown_80DDACC
gUnknown_80DDACC: @ 80DDACC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x07, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DDAE4
gUnknown_80DDAE4: @ 80DDAE4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DDAFC
gUnknown_80DDAFC: @ 80DDAFC
        .4byte Confirm_80DDB1C
        .byte 0xB, 0x00, 0x00, 0x00
        .4byte Info_80DDB14
        .byte 0xC, 0x00, 0x00, 0x00
        .byte 0x0, 0x00, 0x00, 0x00
        .byte 0xA, 0x00, 0x00, 0x00

       .global Info_80DDB14
       Info_80DDB14:
        .string "Info\0"
        .align 2,0

        .global Confirm_80DDB1C
        Confirm_80DDB1C:
        .string "Confirm\0"
        .align 2,0

	.global gUnknown_80DDB24
gUnknown_80DDB24: @ 80DDB24
        .4byte GameLinkCable_80DDB50
        .byte 0xD, 0x00, 0x00, 0x00
        .4byte Password_80DDB44
        .byte 0xF, 0x00, 0x00, 0x00
        .4byte gWonderMailCancel
        .byte 0xA, 0x00, 0x00, 0x00
        .byte 0x0, 0x00, 0x00, 0x00
        .byte 0xA, 0x00, 0x00, 0x00

        .global Password_80DDB44
        Password_80DDB44:
        .string "Password\0"
        .align 2,0

        .global GameLinkCable_80DDB50
        GameLinkCable_80DDB50:
        .string "Game Link cable\0"
        .align 2,0

	.global gUnknown_80DDB60
gUnknown_80DDB60: @ 80DDB60

    .4byte SendPokemon_80DDB98
    .byte 0x11, 0x00, 0x00, 0x00
    .4byte DontSendPokemon_80DDB80
    .byte 0x12, 0x00, 0x00, 0x00
    .4byte gWonderMailCancel
    .byte 0x0a, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00
    .byte 0x0a, 0x00, 0x00, 0x00

    .global DontSendPokemon_80DDB80
    DontSendPokemon_80DDB80:
    .string "Don~27t Send Pokémon\0"
    .align 2,0

    .global SendPokemon_80DDB98
    SendPokemon_80DDB98:
    .string "Send Pokémon\0"
    .align 2,0

