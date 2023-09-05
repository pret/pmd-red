	.section .rodata


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
        .string "{COLOR_1}%c%s\0"
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
    .4byte gUnknown_80D53E0
    .4byte gUnknown_80D53C8
    .4byte gUnknown_80D538C
    .4byte gUnknown_80D5380
    .4byte gUnknown_80D5364
    .4byte gUnknown_80D5364
    .4byte gUnknown_80D5340
    .4byte gUnknown_80D52F8
    .4byte gUnknown_80D527C
    .4byte gUnknown_80D5244
    .4byte gUnknown_80D5224
    .4byte gUnknown_80D51DC
    .4byte gUnknown_80D5184
    .4byte gUnknown_80D5158
    .4byte gUnknown_80D4FC8
    .4byte gUnknown_80D4F94
    .4byte gUnknown_80D4F74
    .4byte gUnknown_80D4F24
    .4byte gUnknown_80D4F08
    .4byte gUnknown_80D4EDC
    .4byte gUnknown_80D4EB0
    .4byte gUnknown_80D4E84
    .4byte gUnknown_80D4E28
    .4byte gUnknown_80D4D8C
    .4byte gUnknown_80D4D44
    .4byte gUnknown_80D4D20
    .4byte gUnknown_80D4CC0
    .4byte gUnknown_80D4C50
    .4byte gUnknown_80D4C14
    .4byte gUnknown_80D4A58

    .global gUnknown_80D4A58
gUnknown_80D4A58:
    .string " Sssnore...\n"
    .string "Ah{COMMA} you wish to know how the bank\n"
    .string "operates... Very well...{EXTRA_MSG}"
    .string " Zzz...\n"
    .string "If you{APOSTROPHE}re defeated in a dungeon{COMMA}\n"
    .string "you{APOSTROPHE}ll lose all your money. Did you know?{EXTRA_MSG}"
    .string " Purr...\n"
    .string "But{COMMA} you{APOSTROPHE}ve nothing to fear if you leave\n"
    .string "your money with Felicity Bank...{EXTRA_MSG}"
    .string " Meow... Even if you\n"
    .string "return defeated from a dungeon{COMMA} your\n"
    .string "money will be safe with me...{EXTRA_MSG}"
    .string " Sssnore...\n"
    .string "I assure you{COMMA} my bank will keep your\n"
    .string "money safe...{EXTRA_MSG}"
    .string " Zzz...\n"
    .string "Simple{COMMA} isn{APOSTROPHE}t it...?\0"
    .align 2, 0

    .global gUnknown_80D4C14
gUnknown_80D4C14:
    .string " {POKE}... Purr...\n"
    .string "Very well{COMMA} {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Here you are.\0"
    .align 2, 0

    .global gUnknown_80D4C50
gUnknown_80D4C50:
    .string " Fnarf? Hunh...?{EXTRA_MSG}"
    .string " Purr... I so do apologize{COMMA}\n"
    .string "but you couldn{APOSTROPHE}t possibly carry any more\n"
    .string "money with you...\0"
    .align 2, 0

    .global gUnknown_80D4CC0
gUnknown_80D4CC0:
    .string " Fnarf? Meow...?{EXTRA_MSG}"
    .string " Purr...\n"
    .string "I so hate to disappoint{COMMA} but you have no\n"
    .string "money saved with me...\0"
    .align 2, 0

    .global gUnknown_80D4D20
gUnknown_80D4D20:
    .string " Zzz...\n"
    .string "How much will you withdraw?\0"
    .align 2, 0

    .global gUnknown_80D4D44
gUnknown_80D4D44:
    .string " Zzz...\n"
    .string "{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}... Very well...{WAIT_PRESS}\n"
    .string "I will guard it jealously...\0"
    .align 2, 0

    .global gUnknown_80D4D8C
gUnknown_80D4D8C:
    .string " Fnarf? Purr...\n"
    .string "Meow! All this money...{WAIT_PRESS}\n"
    .string "Our safe is about to burst...{EXTRA_MSG}"
    .string " Purr...\n"
    .string "I am so sorry to say{COMMA} but I can{APOSTROPHE}t accept\n"
    .string "any more of your money...\0"
    .align 2, 0

    .global gUnknown_80D4E28
gUnknown_80D4E28:
    .string " Sssnore... Hmm?{EXTRA_MSG}"
    .string " Zzz...\n"
    .string "I{APOSTROPHE}m so sorry to say{COMMA} but you appear not\n"
    .string "to have any money...\0"
    .align 2, 0

    .global gUnknown_80D4E84
gUnknown_80D4E84:
    .string " Purr...\n"
    .string "How much do you wish to deposit?\0"
    .align 2, 0

    .global gUnknown_80D4EB0
gUnknown_80D4EB0:
    .string " Zzz... Meow...\n"
    .string "I await your next visit...\0"
    .align 2, 0

    .global gUnknown_80D4EDC
gUnknown_80D4EDC:
    .string " Zzz... Purr...\n"
    .string "I await your next visit...\0"
    .align 2, 0

    .global gUnknown_80D4F08
gUnknown_80D4F08:
    .string " Sssnore...\n"
    .string "Very well...\0"
    .align 2, 0

    .global gUnknown_80D4F24
gUnknown_80D4F24:
    .string " Sssnore... Purr...\n"
    .string "Your account contains {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}...\n"
    .string "How may I serve you?\0"
    .align 2, 0

    .global gUnknown_80D4F74
gUnknown_80D4F74:
    .string " Zzz...\n"
    .string "How may I serve you?\0"
    .align 2, 0

    .global gUnknown_80D4F94
gUnknown_80D4F94:
    .string " Ssssnore... Welcome...\n"
    .string "This is Felicity Bank...\0"
    .align 2, 0

    .global gUnknown_80D4FC8
gUnknown_80D4FC8:
    .string " Ah{COMMA} you wish to know how\n"
    .string "the bank operates. Very well.{EXTRA_MSG}"
    .string " If you are defeated\n"
    .string "in a dungeon{COMMA} you{APOSTROPHE}ll lose all your money.\n"
    .string "Did you know that?{EXTRA_MSG}"
    .string " But you can avoid that!{WAIT_PRESS}\n"
    .string "You{APOSTROPHE}ve nothing to fear if you leave your\n"
    .string "money with Felicity Bank.{EXTRA_MSG}"
    .string " Even if you return\n"
    .string "defeated from a dungeon{COMMA} your money will\n"
    .string "be safe with me!{EXTRA_MSG}"
    .string " I assure you{COMMA} my bank\n"
    .string "will keep your money safe.{EXTRA_MSG}"
    .string " Simple{COMMA} isn{APOSTROPHE}t it?\0"
    .align 2, 0

    .global gUnknown_80D5158
gUnknown_80D5158:
    .string " Very well{COMMA} {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Here you are.\0"
    .align 2, 0

    .global gUnknown_80D5184
gUnknown_80D5184:
    .string " Oh?{WAIT_PRESS} I do so apologize{COMMA}\n"
    .string "but you couldn{APOSTROPHE}t possibly carry any more\n"
    .string "money with you.\0"
    .align 2, 0

    .global gUnknown_80D51DC
gUnknown_80D51DC:
    .string " Oh?{WAIT_PRESS} I so hate to disappoint{COMMA}\n"
    .string "but you have no money saved with me.\0"
    .align 2, 0

    .global gUnknown_80D5224
gUnknown_80D5224:
    .string " How much will you\n"
    .string "withdraw?\0"
    .align 2, 0

    .global gUnknown_80D5244
gUnknown_80D5244:
    .string " {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}. Very well.{WAIT_PRESS}\n"
    .string "I will guard it jealously.\0"
    .align 2, 0

    .global gUnknown_80D527C
gUnknown_80D527C:
    .string " Meow! All this money!{WAIT_PRESS}\n"
    .string "Our safe is about to burst!{EXTRA_MSG}"
    .string " I am so sorry to say{COMMA} but\n"
    .string "I can{APOSTROPHE}t accept any more of your money!\0"
    .align 2, 0

    .global gUnknown_80D52F8
gUnknown_80D52F8:
    .string " Oh?{WAIT_PRESS} I{APOSTROPHE}m so sorry to say{COMMA}\n"
    .string "but you appear not to have any money.\0"
    .align 2, 0

    .global gUnknown_80D5340
gUnknown_80D5340:
    .string " How much do you wish to\n"
    .string "deposit?\0"
    .align 2, 0

    .global gUnknown_80D5364
gUnknown_80D5364:
    .string " I await your next visit.\0"
    .align 2, 0

    .global gUnknown_80D5380
gUnknown_80D5380:
    .string " Very well.\0"
    .align 2, 0

    .global gUnknown_80D538C
gUnknown_80D538C:
    .string " Your account contains\n"
    .string "{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "How may I serve you?\0"
    .align 2, 0

    .global gUnknown_80D53C8
gUnknown_80D53C8:
    .string " How may I serve you?\0"
    .align 2, 0

    .global gUnknown_80D53E0
gUnknown_80D53E0:
    .string " Welcome.\n"
    .string "This is Felicity Bank.\0"
    .align 2, 0

	.global gKangaskhanStorageDialogue
gKangaskhanStorageDialogue: @ 80D5404 (Kangaskhan Storage Dialogue)
    .4byte gUnknown_80D5E9C
    .4byte gUnknown_80D5E84
    .4byte gUnknown_80D5E60
    .4byte gUnknown_80D5E10
    .4byte gUnknown_80D5DE8
    .4byte gUnknown_80D5DBC
    .4byte gUnknown_80D5D8C
    .4byte gUnknown_80D5D58
    .4byte gUnknown_80D5D0C
    .4byte gUnknown_80D5CE4
    .4byte gUnknown_80D5CAC
    .4byte gUnknown_80D5C74
    .4byte gUnknown_80D5C44
    .4byte gUnknown_80D5C1C
    .4byte gUnknown_80D5BDC
    .4byte gUnknown_80D5BAC
    .4byte gUnknown_80D5B5C
    .4byte gUnknown_80D5B24
    .4byte gUnknown_80D5AF0
    .4byte gUnknown_80D5984
    .4byte gUnknown_80D5954
    .4byte gUnknown_80D5934
    .4byte gUnknown_80D5900
    .4byte gUnknown_80D58B0
    .4byte gUnknown_80D5884
    .4byte gUnknown_80D5844
    .4byte gUnknown_80D57F4
    .4byte gUnknown_80D57C4
    .4byte gUnknown_80D5774
    .4byte gUnknown_80D574C
    .4byte gUnknown_80D5710
    .4byte gUnknown_80D56CC
    .4byte gUnknown_80D56AC
    .4byte gUnknown_80D5670
    .4byte gUnknown_80D5630
    .4byte gUnknown_80D55F4
    .4byte gUnknown_80D55C0
    .4byte gUnknown_80D5590
    .4byte gUnknown_80D555C
    .4byte gUnknown_80D54A4

    .global gUnknown_80D54A4
gUnknown_80D54A4:
    .string " Zzz... Snork!\n"
    .string "I can store items that you\n"
    .string "found in dungeons...{EXTRA_MSG}"
    .string " Snarfle...\n"
    .string "Things in storage don{APOSTROPHE}t get lost...{EXTRA_MSG}"
    .string " Zzz... Zzz...\n"
    .string "That{APOSTROPHE}s why...\n"
    .string "Keep important items in storage...\0"
    .align 2, 0

    .global gUnknown_80D555C
gUnknown_80D555C:
    .string " Zzz... Zzz... No...\n"
    .string "The storage space is full...\0"
    .align 2, 0

    .global gUnknown_80D5590
gUnknown_80D5590:
    .string " Zzz... No...\n"
    .string "Can{APOSTROPHE}t store any more of that...\0"
    .align 2, 0

    .global gUnknown_80D55C0
gUnknown_80D55C0:
    .string " Zzz... Zzz...\n"
    .string "That {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}...\n"
    .string "Can{APOSTROPHE}t store it...\0"
    .align 2, 0

    .global gUnknown_80D55F4
gUnknown_80D55F4:
    .string " Snarfle? Hunh...?{WAIT_PRESS}\n"
    .string "Zzz... Your storage space... Empty...\0"
    .align 2, 0

    .global gUnknown_80D5630
gUnknown_80D5630:
    .string " Snarfle? Hunh...?{WAIT_PRESS}\n"
    .string "Zzz...\n"
    .string "You don{APOSTROPHE}t have enough space...\0"
    .align 2, 0

    .global gUnknown_80D5670
gUnknown_80D5670:
    .string " Snarfle? Hunh...?{WAIT_PRESS}\n"
    .string "Zzz...\n"
    .string "You don{APOSTROPHE}t have anything...?\0"
    .align 2, 0

    .global gUnknown_80D56AC
gUnknown_80D56AC:
    .string " Zzz... Snork!\n"
    .string "There you go...\0"
    .align 2, 0

    .global gUnknown_80D56CC
gUnknown_80D56CC:
    .string " Zzz... Zzz... Hunh...?\n"
    .string "You want those things from storage...\n"
    .string "OK?\0"
    .align 2, 0

    .global gUnknown_80D5710
gUnknown_80D5710:
    .string " Hunh...? Taking...?\n"
    .string "Oh... You want your {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}...\n"
    .string "OK?\0"
    .align 2, 0

    .global gUnknown_80D574C
gUnknown_80D574C:
    .string " Snork! Zzz...\n"
    .string "Taking anything else?\0"
    .align 2, 0

    .global gUnknown_80D5774
gUnknown_80D5774:
    .string " What...? Take out...?\n"
    .string "Uh-huh... Choose more than one using\n"
    .string "{L_BUTTON} or {R_BUTTON}... Zzz...\0"
    .align 2, 0

    .global gUnknown_80D57C4
gUnknown_80D57C4:
    .string " Zzz... Zzz...\n"
    .string "Yup{COMMA} I did... Stored away...\0"
    .align 2, 0

    .global gUnknown_80D57F4
gUnknown_80D57F4:
    .string " Hunh{COMMA} wha--? Storage...?\n"
    .string "I{APOSTROPHE}ll put away the things you chose...\n"
    .string "That OK?\0"
    .align 2, 0

    .global gUnknown_80D5844
gUnknown_80D5844:
    .string " Zzz... Store something?\n"
    .string "Gonna put {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} in storage...\n"
    .string "OK?\0"
    .align 2, 0

    .global gUnknown_80D5884
gUnknown_80D5884:
    .string " Do you... Snork...\n"
    .string "Store anything else?\0"
    .align 2, 0

    .global gUnknown_80D58B0
gUnknown_80D58B0:
    .string " Hunh{COMMA} wha--? Store what...?\n"
    .string "You can choose more than one using\n"
    .string "{L_BUTTON} or {R_BUTTON}...\0"
    .align 2, 0

    .global gUnknown_80D5900
gUnknown_80D5900:
    .string " Snuffle... Mutter...\n"
    .string "Thank you...\n"
    .string "Come again...\0"
    .align 2, 0

    .global gUnknown_80D5934
gUnknown_80D5934:
    .string " Zzz... Snork...\n"
    .string "Anything else?\0"
    .align 2, 0

    .global gUnknown_80D5954
gUnknown_80D5954:
    .string " Zzz... Zzz...\n"
    .string "Hello{COMMA} there...\n"
    .string "{ARG_POKEMON_6} Storage...\0"
    .align 2, 0

    .global gUnknown_80D5984
gUnknown_80D5984:
    .string " I can store items that you\n"
    .string "found in dungeons{COMMA} or that you\n"
    .string "bought from shops.{EXTRA_MSG}"
    .string " If you faint in\n"
    .string "a dungeon{COMMA} your items will be lost...{WAIT_PRESS}\n"
    .string "But what{APOSTROPHE}s in storage will be safe.{EXTRA_MSG}"
    .string " I keep guard over the\n"
    .string "storage space{COMMA} so anything you leave\n"
    .string "with me won{APOSTROPHE}t ever disappear!{EXTRA_MSG}"
    .string " If you have any items that\n"
    .string "you can{APOSTROPHE}t bear to lose{COMMA} be sure to leave\n"
    .string "them with me!\0"
    .align 2, 0

    .global gUnknown_80D5AF0
gUnknown_80D5AF0:
    .string " Sorry{COMMA} dear.\n"
    .string "I{APOSTROPHE}ve run out of storage space.\0"
    .align 2, 0

    .global gUnknown_80D5B24
gUnknown_80D5B24:
    .string " Sorry{COMMA} dear.\n"
    .string "I can{APOSTROPHE}t take any more of that item.\0"
    .align 2, 0

    .global gUnknown_80D5B5C
gUnknown_80D5B5C:
    .string " Oh{COMMA} dear{COMMA} sorry.{WAIT_PRESS}\n"
    .string "That {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} is an item you\n"
    .string "can{APOSTROPHE}t put in storage.\0"
    .align 2, 0

    .global gUnknown_80D5BAC
gUnknown_80D5BAC:
    .string " Oh?\n"
    .string "You don{APOSTROPHE}t have anything stored{COMMA} dear.\0"
    .align 2, 0

    .global gUnknown_80D5BDC
gUnknown_80D5BDC:
    .string " Oh? You don{APOSTROPHE}t have the room\n"
    .string "to carry any more items{COMMA} dear.\0"
    .align 2, 0

    .global gUnknown_80D5C1C
gUnknown_80D5C1C:
    .string " Oh?\n"
    .string "You don{APOSTROPHE}t seem to have anything?\0"
    .align 2, 0

    .global gUnknown_80D5C44
gUnknown_80D5C44:
    .string " There you go!\n"
    .string "Just like you asked{COMMA} sweetie!\0"
    .align 2, 0

    .global gUnknown_80D5C74
gUnknown_80D5C74:
    .string " I{APOSTROPHE}ll take the items you\n"
    .string "chose out of storage. OK?\0"
    .align 2, 0

    .global gUnknown_80D5CAC
gUnknown_80D5CAC:
    .string " Fine{COMMA} I{APOSTROPHE}ll take your\n"
    .string "{COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} out of storage. OK?\0"
    .align 2, 0

    .global gUnknown_80D5CE4
gUnknown_80D5CE4:
    .string " Would you like to take\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D5D0C
gUnknown_80D5D0C:
    .string " What will you take out?\n"
    .string "You can choose more than one item using\n"
    .string "{L_BUTTON} or {R_BUTTON}.\0"
    .align 2, 0

    .global gUnknown_80D5D58
gUnknown_80D5D58:
    .string " OK{COMMA} stored away!\n"
    .string "You can count on me{COMMA} honey.\0"
    .align 2, 0

    .global gUnknown_80D5D8C
gUnknown_80D5D8C:
    .string " I{APOSTROPHE}ll put the items you chose\n"
    .string "in storage. OK?\0"
    .align 2, 0

    .global gUnknown_80D5DBC
gUnknown_80D5DBC:
    .string " I{APOSTROPHE}ll put your\n"
    .string "{COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} in storage. OK?\0"
    .align 2, 0

    .global gUnknown_80D5DE8
gUnknown_80D5DE8:
    .string " Do you want to store\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D5E10
gUnknown_80D5E10:
    .string " What do you want to store?\n"
    .string "You can choose more than one item using\n"
    .string "{L_BUTTON} or {R_BUTTON}.\0"
    .align 2, 0

    .global gUnknown_80D5E60
gUnknown_80D5E60:
    .string " Thank you{COMMA} sweetie.\n"
    .string "Come again!\0"
    .align 2, 0

    .global gUnknown_80D5E84
gUnknown_80D5E84:
    .string " Anything else{COMMA} dear?\0"
    .align 2, 0

    .global gUnknown_80D5E9C
gUnknown_80D5E9C:
    .string " Hello{COMMA} there!\n"
    .string "Welcome to {ARG_POKEMON_6} Storage.\0"
    .align 2, 0

	.global gKecleonShopDialogue
gKecleonShopDialogue: @ 80D5EC8 (Kecleon Wares Dialogue)
    .4byte gUnknown_80D797C
    .4byte gUnknown_80D7958
    .4byte gUnknown_80D7934
    .4byte gUnknown_80D78F8
    .4byte gUnknown_80D78CC
    .4byte gUnknown_80D788C
    .4byte gUnknown_80D785C
    .4byte gUnknown_80D7830
    .4byte gUnknown_80D780C
    .4byte gUnknown_80D77C0
    .4byte gUnknown_80D776C
    .4byte gUnknown_80D7740
    .4byte gUnknown_80D76D4
    .4byte gUnknown_80D76A8
    .4byte gUnknown_80D7640
    .4byte gUnknown_80D7610
    .4byte gUnknown_80D75E0
    .4byte gUnknown_80D75AC
    .4byte gUnknown_80D7560
    .4byte gUnknown_80D7524
    .4byte gUnknown_80D74DC
    .4byte gUnknown_80D7480
    .4byte gUnknown_80D72B8
    .4byte gUnknown_80D72A0
    .4byte gUnknown_80D7270
    .4byte gUnknown_80D7250
    .4byte gUnknown_80D7228
    .4byte gUnknown_80D7204
    .4byte gUnknown_80D71CC
    .4byte gUnknown_80D71B0
    .4byte gUnknown_80D7184
    .4byte gUnknown_80D7154
    .4byte gUnknown_80D7108
    .4byte gUnknown_80D70B4
    .4byte gUnknown_80D7090
    .4byte gUnknown_80D7064
    .4byte gUnknown_80D7038
    .4byte gUnknown_80D6FD4
    .4byte gUnknown_80D6F8C
    .4byte gUnknown_80D6F4C
    .4byte gUnknown_80D6F18
    .4byte gUnknown_80D6EEC
    .4byte gUnknown_80D6EA4
    .4byte gUnknown_80D6E78
    .4byte gUnknown_80D6E30
    .4byte gUnknown_80D6D98
    .4byte gUnknown_80D6D5C
    .4byte gUnknown_80D6D38
    .4byte gUnknown_80D6D08
    .4byte gUnknown_80D6CB8
    .4byte gUnknown_80D6C90
    .4byte gUnknown_80D6C48
    .4byte gUnknown_80D6C1C
    .4byte gUnknown_80D7830
    .4byte gUnknown_80D6BF4
    .4byte gUnknown_80D6BA0
    .4byte gUnknown_80D6B50
    .4byte gUnknown_80D6B18
    .4byte gUnknown_80D6AAC
    .4byte gUnknown_80D6A74
    .4byte gUnknown_80D6A04
    .4byte gUnknown_80D69B0
    .4byte gUnknown_80D6980
    .4byte gUnknown_80D6938
    .4byte gUnknown_80D68E0
    .4byte gUnknown_80D68A4
    .4byte gUnknown_80D6868
    .4byte gUnknown_80D6818
    .4byte gUnknown_80D6564
    .4byte gUnknown_80D6544
    .4byte gUnknown_80D652C
    .4byte gUnknown_80D6508
    .4byte gUnknown_80D64E8
    .4byte gUnknown_80D64C0
    .4byte gUnknown_80D6494
    .4byte gUnknown_80D6478
    .4byte gUnknown_80D6450
    .4byte gUnknown_80D6420
    .4byte gUnknown_80D63E8
    .4byte gUnknown_80D6394
    .4byte gUnknown_80D6364
    .4byte gUnknown_80D6338
    .4byte gUnknown_80D630C
    .4byte gUnknown_80D62B0
    .4byte gUnknown_80D627C
    .4byte gUnknown_80D6250
    .4byte gUnknown_80D6204
    .4byte gUnknown_80D61D4
    .4byte gUnknown_80D61B0
    .4byte gUnknown_80D6168
    .4byte gUnknown_80D6128
    .4byte gUnknown_80D6038

    .global gUnknown_80D6038
gUnknown_80D6038:
    .string " Zzz... Reep reep...\n"
    .string "Wonder Orbs are convenient...{EXTRA_MSG}"
    .string " Zzzzzz...\n"
    .string "They disappear after one use...{EXTRA_MSG}"
    .string " Zzz... And moves...\n"
    .string "They are ultimate...{EXTRA_MSG}"
    .string " Zzz... Eep...\n"
    .string "Learn moves with Technical Machines...{EXTRA_MSG}"
    .string " Zzz...\n"
    .string "My good wares...\n"
    .string "Come buy... Reep...\0"
    .align 2, 0

    .global gUnknown_80D6128
gUnknown_80D6128:
    .string " Zzz... Eep? No{COMMA} no...{WAIT_PRESS}\n"
    .string "You cannot hold any more money...\0"
    .align 2, 0

    .global gUnknown_80D6168
gUnknown_80D6168:
    .string " Zzz... Hunh? Wha--? Whoa!{WAIT_PRESS}\n"
    .string "I... I can{APOSTROPHE}t accept anything like that!\0"
    .align 2, 0

    .global gUnknown_80D61B0
gUnknown_80D61B0:
    .string " Reep...? Eep!{WAIT_PRESS}\n"
    .string "Not enough money!\0"
    .align 2, 0

    .global gUnknown_80D61D4
gUnknown_80D61D4:
    .string " Zzz... Uh-oh...{WAIT_PRESS}\n"
    .string "All gone!\n"
    .string "I am sold out...\0"
    .align 2, 0

    .global gUnknown_80D6204
gUnknown_80D6204:
    .string " Zzz... Hunh? Oh...{WAIT_PRESS}\n"
    .string "Reep... No room... Reep...\n"
    .string "No room for my wares...\0"
    .align 2, 0

    .global gUnknown_80D6250
gUnknown_80D6250:
    .string " Zzzzzz... Oh?{WAIT_PRESS}\n"
    .string "You{APOSTROPHE}ve got nothing...\0"
    .align 2, 0

    .global gUnknown_80D627C
gUnknown_80D627C:
    .string " Zzz... Oh...?{WAIT_PRESS}\n"
    .string "You have nothing to sell...\n"
    .string "Hunh?\0"
    .align 2, 0

    .global gUnknown_80D62B0
gUnknown_80D62B0:
    .string " Eep...? Zzz...\n"
    .string "You have too much money!{EXTRA_MSG}"
    .string " Zzz... Eh?\n"
    .string "You can{APOSTROPHE}t hold any more money...\0"
    .align 2, 0

    .global gUnknown_80D630C
gUnknown_80D630C:
    .string " Reep eep! Oh?{WAIT_PRESS}\n"
    .string "Eep...?\n"
    .string "You have no money?\0"
    .align 2, 0

    .global gUnknown_80D6338
gUnknown_80D6338:
    .string " ...{WAIT_PRESS}Zzz...\n"
    .string "I am all sold out... Sorry...\0"
    .align 2, 0

    .global gUnknown_80D6364
gUnknown_80D6364:
    .string " Fine... Reep reep...\n"
    .string "Done deal!\n"
    .string "Thank you...\0"
    .align 2, 0

    .global gUnknown_80D6394
gUnknown_80D6394:
    .string " Zzz... Reep{COMMA} what...?\n"
    .string "For all that I can buy{COMMA} I will pay\n"
    .string "{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}... OK?\0"
    .align 2, 0

    .global gUnknown_80D63E8
gUnknown_80D63E8:
    .string " Zzzzzz... Zzzzzz...?\n"
    .string "{COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}?\n"
    .string "Is {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE} OK?\0"
    .align 2, 0

    .global gUnknown_80D6420
gUnknown_80D6420:
    .string " Reep reep... Eep...\n"
    .string "Anything else for sale?\0"
    .align 2, 0

    .global gUnknown_80D6450
gUnknown_80D6450:
    .string " Zzz... Eep...?\n"
    .string "What will you sell...?\0"
    .align 2, 0

    .global gUnknown_80D6478
gUnknown_80D6478:
    .string " Zzz... Reep!\n"
    .string "Thank you...\0"
    .align 2, 0

    .global gUnknown_80D6494
gUnknown_80D6494:
    .string " Zzzzzz...\n"
    .string "{COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} is {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}...\n"
    .string "OK?\0"
    .align 2, 0

    .global gUnknown_80D64C0
gUnknown_80D64C0:
    .string " Anything? Zzz...\n"
    .string "Buying anything else?\0"
    .align 2, 0

    .global gUnknown_80D64E8
gUnknown_80D64E8:
    .string " Ah... Zzz...\n"
    .string "My merchandise...\0"
    .align 2, 0

    .global gUnknown_80D6508
gUnknown_80D6508:
    .string " Thank... Reep eep...\n"
    .string "Come again...\0"
    .align 2, 0

    .global gUnknown_80D652C
gUnknown_80D652C:
    .string " Reep...\n"
    .string "Anything else?\0"
    .align 2, 0

    .global gUnknown_80D6544
gUnknown_80D6544:
    .string " Zzzzzz...\n"
    .string "This is...my shop...\0"
    .align 2, 0

    .global gUnknown_80D6564
gUnknown_80D6564:
    .string " Wonder Orbs are very{COMMA}\n"
    .string "very convenient〜♪{EXTRA_MSG}"
    .string " However{COMMA} they disappear\n"
    .string "after one use...{WAIT_PRESS}\n"
    .string "But they are useful in a pinch!{EXTRA_MSG}"
    .string " Use them cleverly{COMMA} and your\n"
    .string "adventures will be made much easier〜♪{EXTRA_MSG}"
    .string " And moves...{WAIT_PRESS}\n"
    .string "They are the ultimate power!{EXTRA_MSG}"
    .string " Smash rocks!{WAIT_PRESS} Fly!{WAIT_PRESS}\n"
    .string "There are many kinds of moves{COMMA} all of\n"
    .string "them dynamic{COMMA} yet elegant!{EXTRA_MSG}"
    .string " There are even moves of\n"
    .string "obscure rarity...{WAIT_PRESS}\n"
    .string "Simply gorgeous{COMMA} they are!{EXTRA_MSG}"
    .string " Now{COMMA} we have these moves!{WAIT_PRESS}\n"
    .string "They can be learned using our Technical\n"
    .string "Machines{COMMA} or TMs for short!{EXTRA_MSG}"
    .string " You see?\n"
    .string "Isn{APOSTROPHE}t it exciting? Even dreamy?{EXTRA_MSG}"
    .string " Why{COMMA} it gets me so excited{COMMA}\n"
    .string "my color has turned a rosy tint!{EXTRA_MSG}"
    .string " I do hope you will shop\n"
    .string "with us--me and my brother next to\n"
    .string "me!\0"
    .align 2, 0

    .global gUnknown_80D6818
gUnknown_80D6818:
    .string " Oh{COMMA} no{COMMA} no!{WAIT_PRESS}\n"
    .string "My friend{COMMA} you cannot add to your money!\n"
    .string "I cannot do this.\0"
    .align 2, 0

    .global gUnknown_80D6868
gUnknown_80D6868:
    .string " Whoa{COMMA} whoa!{WAIT_PRESS}\n"
    .string "I... I can{APOSTROPHE}t accept anything like that!\0"
    .align 2, 0

    .global gUnknown_80D68A4
gUnknown_80D68A4:
    .string " Eep! Oh{COMMA} dear!{WAIT_PRESS}\n"
    .string "You{APOSTROPHE}re short on money{COMMA} my friend!\0"
    .align 2, 0

    .global gUnknown_80D68E0
gUnknown_80D68E0:
    .string " Oh? Uh-oh!{WAIT_PRESS}\n"
    .string "My shelves are bare of wares!{EXTRA_MSG}"
    .string " I am completely sold out{COMMA}\n"
    .string "my friend!\0"
    .align 2, 0

    .global gUnknown_80D6938
gUnknown_80D6938:
    .string " Oh{COMMA} dear me!{WAIT_PRESS}\n"
    .string "My friend{COMMA} you{APOSTROPHE}ve run out of space for\n"
    .string "my wares!\0"
    .align 2, 0

    .global gUnknown_80D6980
gUnknown_80D6980:
    .string " Oh?{WAIT_PRESS}\n"
    .string "My friend{COMMA} you seem to have nothing?\0"
    .align 2, 0

    .global gUnknown_80D69B0
gUnknown_80D69B0:
    .string " Oh{COMMA} oh{COMMA} oh?{WAIT_PRESS}\n"
    .string "My friend{COMMA} you seem to not have anything\n"
    .string "that you can sell?\0"
    .align 2, 0

    .global gUnknown_80D6A04
gUnknown_80D6A04:
    .string " Oh{COMMA} my{COMMA} my!\n"
    .string "My friend{COMMA} you have too much money!{EXTRA_MSG}"
    .string " You can{APOSTROPHE}t carry any more\n"
    .string "money than you have now.\0"
    .align 2, 0

    .global gUnknown_80D6A74
gUnknown_80D6A74:
    .string " Oh?{WAIT_PRESS}\n"
    .string "My friend{COMMA} you seem not to have\n"
    .string "enough money?\0"
    .align 2, 0

    .global gUnknown_80D6AAC
gUnknown_80D6AAC:
    .string " ...{WAIT_PRESS}I am all out of wares...\n"
    .string "I am so sorry{COMMA} my friend...{EXTRA_MSG}"
    .string " Tomorrow!\n"
    .string "Tomorrow I shall have more wares!\0"
    .align 2, 0

    .global gUnknown_80D6B18
gUnknown_80D6B18:
    .string " Fine{COMMA} fine{COMMA} we have a deal!\n"
    .string "Thank you so much〜♪ \0"
    .align 2, 0

    .global gUnknown_80D6B50
gUnknown_80D6B50:
    .string " For all that I can buy{COMMA} I can\n"
    .string "offer you {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Is that acceptable?\0"
    .align 2, 0

    .global gUnknown_80D6BA0
gUnknown_80D6BA0:
    .string " {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}{COMMA} you say?\n"
    .string "For that{COMMA} I can offer {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Is that acceptable?\0"
    .align 2, 0

    .global gUnknown_80D6BF4
gUnknown_80D6BF4:
    .string " Do you wish to sell me\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D6C1C
gUnknown_80D6C1C:
    .string " Thank you so much〜♪\n"
    .string "A very good choice!\0"
    .align 2, 0

    .global gUnknown_80D6C48
gUnknown_80D6C48:
    .string " {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}{COMMA} you say?\n"
    .string "That will be {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Is that acceptable?\0"
    .align 2, 0

    .global gUnknown_80D6C90
gUnknown_80D6C90:
    .string " Do you wish to purchase\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D6CB8
gUnknown_80D6CB8:
    .string " Ah{COMMA} very well!\n"
    .string "Do examine my merchandise.\n"
    .string "I have chosen it with pride〜♪ \0"
    .align 2, 0

    .global gUnknown_80D6D08
gUnknown_80D6D08:
    .string " Thank you so much!\n"
    .string "Please do visit again〜♪ \0"
    .align 2, 0

    .global gUnknown_80D6D38
gUnknown_80D6D38:
    .string " May I assist you in any\n"
    .string "other way?\0"
    .align 2, 0

    .global gUnknown_80D6D5C
gUnknown_80D6D5C:
    .string " Welcome to Kecleon Wares!\n"
    .string "The shop for Orbs and TMs〜♪ \0"
    .align 2, 0

    .global gUnknown_80D6D98
gUnknown_80D6D98:
    .string " Zzzzzz...\n"
    .string "I sell items...{EXTRA_MSG}"
    .string " Items... Meep meep...\n"
    .string "Are useful in dungeons...{EXTRA_MSG}"
    .string " Use... Zzz... Huh...?\n"
    .string "Your imagination...and be clever...\n"
    .string "With them...\0"
    .align 2, 0

    .global gUnknown_80D6E30
gUnknown_80D6E30:
    .string " Zzz... Hunh{COMMA} what...?{WAIT_PRESS}\n"
    .string "Zzz... You can{APOSTROPHE}t hold any more money...\0"
    .align 2, 0

    .global gUnknown_80D6E78
gUnknown_80D6E78:
    .string " Zzz... Whoa...{WAIT_PRESS}\n"
    .string "I... I can{APOSTROPHE}t take that!\0"
    .align 2, 0

    .global gUnknown_80D6EA4
gUnknown_80D6EA4:
    .string " Zzz... Huh{COMMA} my...!{WAIT_PRESS}\n"
    .string "Meep... Meep...\n"
    .string "You don{APOSTROPHE}t have enough money!\0"
    .align 2, 0

    .global gUnknown_80D6EEC
gUnknown_80D6EEC:
    .string " Zzz... Uh-oh?!{WAIT_PRESS}\n"
    .string "Eep!\n"
    .string "Sold out! All gone!\0"
    .align 2, 0

    .global gUnknown_80D6F18
gUnknown_80D6F18:
    .string " Zzz... Oh{COMMA} my!{WAIT_PRESS}\n"
    .string "Meep... You have no space...\0"
    .align 2, 0

    .global gUnknown_80D6F4C
gUnknown_80D6F4C:
    .string " Zzz... Eep...?{WAIT_PRESS}\n"
    .string "Meep... You don{APOSTROPHE}t seem to have\n"
    .string "anything...?\0"
    .align 2, 0

    .global gUnknown_80D6F8C
gUnknown_80D6F8C:
    .string " Zzz... Huh?{WAIT_PRESS}\n"
    .string "Meep meep...\n"
    .string "You don{APOSTROPHE}t seem to have anything to sell?\0"
    .align 2, 0

    .global gUnknown_80D6FD4
gUnknown_80D6FD4:
    .string " Zzz... Oh{COMMA} my!\n"
    .string "You have so much money...!{EXTRA_MSG}"
    .string " Zzz... Meep...\n"
    .string "You can{APOSTROPHE}t carry any more money...\0"
    .align 2, 0

    .global gUnknown_80D7038
gUnknown_80D7038:
    .string " Hunh?{WAIT_PRESS}\n"
    .string "Eep...?\n"
    .string "You don{APOSTROPHE}t have money?\0"
    .align 2, 0

    .global gUnknown_80D7064
gUnknown_80D7064:
    .string " ...{WAIT_PRESS} ZZZ!\n"
    .string "I{APOSTROPHE}m sold out... Forgive me...\0"
    .align 2, 0

    .global gUnknown_80D7090
gUnknown_80D7090:
    .string " Done... Meep! Deal!\n"
    .string "Thank you...\0"
    .align 2, 0

    .global gUnknown_80D70B4
gUnknown_80D70B4:
    .string " Zzzzzz... Zzzzzz...?\n"
    .string "I can pay you {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}\n"
    .string "for everything I can buy... OK?\0"
    .align 2, 0

    .global gUnknown_80D7108
gUnknown_80D7108:
    .string " Zzzzzz... Zzzzzz...?\n"
    .string "Selling that {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}...?\n"
    .string "How about {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}?\0"
    .align 2, 0

    .global gUnknown_80D7154
gUnknown_80D7154:
    .string " Zzz... Meep...\n"
    .string "Going to sell anything else?\0"
    .align 2, 0

    .global gUnknown_80D7184
gUnknown_80D7184:
    .string " Zzz... Zzz...?\n"
    .string "You{APOSTROPHE}re selling what...?\0"
    .align 2, 0

    .global gUnknown_80D71B0
gUnknown_80D71B0:
    .string " Eep! Wah...?\n"
    .string "Thank you...\0"
    .align 2, 0

    .global gUnknown_80D71CC
gUnknown_80D71CC:
    .string " Zzz... Meep meep...\n"
    .string "{COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}...?\n"
    .string "{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}{COMMA} OK?\0"
    .align 2, 0

    .global gUnknown_80D7204
gUnknown_80D7204:
    .string " Buy? Huh{COMMA} eep?\n"
    .string "Anything else?\0"
    .align 2, 0

    .global gUnknown_80D7228
gUnknown_80D7228:
    .string " Zzz... Meep... Eep...\n"
    .string "Look around...\0"
    .align 2, 0

    .global gUnknown_80D7250
gUnknown_80D7250:
    .string " Thank... Zzz...\n"
    .string "Thank you...\0"
    .align 2, 0

    .global gUnknown_80D7270
gUnknown_80D7270:
    .string " Zzz... Meep...\n"
    .string "Help you with anything else?\0"
    .align 2, 0

    .global gUnknown_80D72A0
gUnknown_80D72A0:
    .string " Zzzzzz...\n"
    .string "Welcome...\0"
    .align 2, 0

    .global gUnknown_80D72B8
gUnknown_80D72B8:
    .string " We{COMMA} the {ARG_POKEMON_6}\n"
    .string "Brothers{COMMA} have a passion for selling\n"
    .string "items.{EXTRA_MSG}"
    .string " Items are useful for your\n"
    .string "dungeon adventures.{EXTRA_MSG}"
    .string " Use your imagination and\n"
    .string "discover innovative uses{COMMA} please.{EXTRA_MSG}"
    .string " Ah{COMMA} yes.\n"
    .string "If my shop sells out...{EXTRA_MSG}"
    .string " New merchandise will\n"
    .string "arrive the following day.{EXTRA_MSG}"
    .string " Until then{COMMA} please go to\n"
    .string "a dungeon and spend some time.\n"
    .string "Please visit on your return〜♪{EXTRA_MSG}"
    .string " Ah{COMMA} yes. The {ARG_POKEMON_6}\n"
    .string "Shop is a nationwide chain.{EXTRA_MSG}"
    .string " There are shops even in\n"
    .string "dungeons.\n"
    .string "Please do visit〜♪ \0"
    .align 2, 0

    .global gUnknown_80D7480
gUnknown_80D7480:
    .string " Oh{COMMA} my!{WAIT_PRESS}\n"
    .string "You can{APOSTROPHE}t add any more to your money.\n"
    .string "I can{APOSTROPHE}t complete this deal{COMMA} sorry.\0"
    .align 2, 0

    .global gUnknown_80D74DC
gUnknown_80D74DC:
    .string " Oh{COMMA} whoa{COMMA} whoa!{WAIT_PRESS}\n"
    .string "I... I couldn{APOSTROPHE}t possibly take that from you!\0"
    .align 2, 0

    .global gUnknown_80D7524
gUnknown_80D7524:
    .string " Oh{COMMA} my!{WAIT_PRESS}\n"
    .string "Sorry{COMMA} but you don{APOSTROPHE}t have enough money!\0"
    .align 2, 0

    .global gUnknown_80D7560
gUnknown_80D7560:
    .string " Uh-oh?!{WAIT_PRESS}\n"
    .string "That{APOSTROPHE}s it! No more merchandise!{EXTRA_MSG}"
    .string " I{APOSTROPHE}m completely sold out!\0"
    .align 2, 0

    .global gUnknown_80D75AC
gUnknown_80D75AC:
    .string " Oh{COMMA} my!{WAIT_PRESS}\n"
    .string "You have no space for any more items!\0"
    .align 2, 0

    .global gUnknown_80D75E0
gUnknown_80D75E0:
    .string " Oh? Oh?{WAIT_PRESS}\n"
    .string "You don{APOSTROPHE}t seem to have anything?\0"
    .align 2, 0

    .global gUnknown_80D7610
gUnknown_80D7610:
    .string " Oh? Oh?{WAIT_PRESS}\n"
    .string "You seem to have nothing to sell?\0"
    .align 2, 0

    .global gUnknown_80D7640
gUnknown_80D7640:
    .string " Oh{COMMA} my goodness!\n"
    .string "You{APOSTROPHE}re overflowing with money!{EXTRA_MSG}"
    .string " You couldn{APOSTROPHE}t possibly carry\n"
    .string "any more money! \0"
    .align 2, 0

    .global gUnknown_80D76A8
gUnknown_80D76A8:
    .string " Huh?{WAIT_PRESS}\n"
    .string "You don{APOSTROPHE}t seem to have the money?\0"
    .align 2, 0

    .global gUnknown_80D76D4
gUnknown_80D76D4:
    .string " ...{WAIT_PRESS}I{APOSTROPHE}m sold out...\n"
    .string "Please{COMMA} forgive me.{EXTRA_MSG}"
    .string " I will have new merchandise\n"
    .string "for you tomorrow{COMMA} I swear!\0"
    .align 2, 0

    .global gUnknown_80D7740
gUnknown_80D7740:
    .string " Good! Done deal!\n"
    .string "Thank you so much〜♪ \0"
    .align 2, 0

    .global gUnknown_80D776C
gUnknown_80D776C:
    .string " For everything I can buy{COMMA}\n"
    .string "I can offer {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Is that acceptable to you?\0"
    .align 2, 0

    .global gUnknown_80D77C0
gUnknown_80D77C0:
    .string " {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}?\n"
    .string "I can offer you {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Will you sell it for that price?\0"
    .align 2, 0

    .global gUnknown_80D780C
gUnknown_80D780C:
    .string " Do you wish to sell\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D7830
gUnknown_80D7830:
    .string " Ah{COMMA} very well!\n"
    .string "What do you wish to sell?\0"
    .align 2, 0

    .global gUnknown_80D785C
gUnknown_80D785C:
    .string " Very well! Thank you〜♪\n"
    .string "It is yours to take!\0"
    .align 2, 0

    .global gUnknown_80D788C
gUnknown_80D788C:
    .string " {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}?\n"
    .string "That will be {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Is that to your liking?\0"
    .align 2, 0

    .global gUnknown_80D78CC
gUnknown_80D78CC:
    .string " Do you wish to buy\n"
    .string "anything else today?\0"
    .align 2, 0

    .global gUnknown_80D78F8
gUnknown_80D78F8:
    .string " Ah{COMMA} very well!\n"
    .string "Feel free to examine my merchandise〜♪\0"
    .align 2, 0

    .global gUnknown_80D7934
gUnknown_80D7934:
    .string " Thank you!\n"
    .string "Please call again〜♪ \0"
    .align 2, 0

    .global gUnknown_80D7958
gUnknown_80D7958:
    .string " May I help you with\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D797C
gUnknown_80D797C:
    .string " Hello〜♪\n"
    .string "Welcome to the {ARG_POKEMON_6} Shop〜♪ \0"
    .align 2, 0

	.global gWigglytuffDialogue
gWigglytuffDialogue: @ 80D79A4 (Friend Area Shop)
    .4byte gUnknown_80D883C
    .4byte gUnknown_80D8818
    .4byte gUnknown_80D87E0
    .4byte gUnknown_80D8798
    .4byte gUnknown_80D876C
    .4byte gUnknown_80D8738
    .4byte gUnknown_80D86E4
    .4byte gUnknown_80D8674
    .4byte gUnknown_80D8644
    .4byte gUnknown_80D8620
    .4byte gUnknown_80D85E4
    .4byte gUnknown_80D85AC
    .4byte gUnknown_80D8584
    .4byte gUnknown_80D8550
    .4byte gUnknown_80D8528
    .4byte gUnknown_80D84F8
    .4byte gUnknown_80D8468
    .4byte gUnknown_80D8420
    .4byte gUnknown_80D8420
    .4byte gUnknown_80D8104
    .4byte gUnknown_80D80D4
    .4byte gUnknown_80D80B0
    .4byte gUnknown_80D8080
    .4byte gUnknown_80D8054
    .4byte gUnknown_80D8030
    .4byte gUnknown_80D8000
    .4byte gUnknown_80D7F7C
    .4byte gUnknown_80D7F10
    .4byte gUnknown_80D7ED0
    .4byte gUnknown_80D7E9C
    .4byte gUnknown_80D7E58
    .4byte gUnknown_80D7E2C
    .4byte gUnknown_80D7E04
    .4byte gUnknown_80D7DE0
    .4byte gUnknown_80D7DA0
    .4byte gUnknown_80D7D64
    .4byte gUnknown_80D7CE8
    .4byte gUnknown_80D7C94
    .4byte gUnknown_80D7C94
    .4byte gUnknown_80D7A44

    .global gUnknown_80D7A44
gUnknown_80D7A44:
    .string " Zzz...\n"
    .string "Want more friends?{EXTRA_MSG}"
    .string " Zzz... Kwoo...\n"
    .string "You need Friend Areas for friends...{EXTRA_MSG}"
    .string " Zzz... Zzz...\n"
    .string "A Pokémon becomes your pal when it{APOSTROPHE}s in\n"
    .string "the right Friend Area...{EXTRA_MSG}"
    .string " Zzz... Dwee...\n"
    .string "That{APOSTROPHE}s why you should get more Friend\n"
    .string "Areas...{EXTRA_MSG}"
    .string " Zzz... Pokémon can only\n"
    .string "live in the right Friend Area for\n"
    .string "their species...{EXTRA_MSG}"
    .string " Kwoo... Sssnore...\n"
    .string "See what Pokémon can live there by\n"
    .string "checking {COLOR_1 YELLOW}Info{END_COLOR_TEXT_1}...{EXTRA_MSG}"
    .string " Zzz...\n"
    .string "I don{APOSTROPHE}t sell some Friend Areas...{EXTRA_MSG}"
    .string " Kwoo...\n"
    .string "Some rescue missions reward you with\n"
    .string "Friend Areas...{EXTRA_MSG}"
    .string " Zzz... Dwee...\n"
    .string "Check the Pelipper Post Office{APOSTROPHE}s Bulletin\n"
    .string "Board or your Mailbox for missions...\0"
    .align 2, 0

    .global gUnknown_80D7C94
gUnknown_80D7C94:
    .string " Sssnore...\n"
    .string "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...?\n"
    .string "I can{APOSTROPHE}t get that Friend Area...{EXTRA_MSG}"
    .string " Zzz... Zzz...\n"
    .string "Sorry...\0"
    .align 2, 0

    .global gUnknown_80D7CE8
gUnknown_80D7CE8:
    .string " Zzz... Hunh...?\n"
    .string "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...?\n"
    .string "I don{APOSTROPHE}t know... I{APOSTROPHE}ll check...{EXTRA_MSG}"
    .string " Sssnore...\n"
    .string "I{APOSTROPHE}ll have it for sale...\n"
    .string "When I find out...\0"
    .align 2, 0

    .global gUnknown_80D7D64
gUnknown_80D7D64:
    .string " Sssnore...\n"
    .string "You can already go...\n"
    .string "Friend Area {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80D7DA0
gUnknown_80D7DA0:
    .string " Dwee... Kwoo...\n"
    .string "{COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s Friend Area...\n"
    .string "Zzz... {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80D7DE0
gUnknown_80D7DE0:
    .string " Another Pokémon...\n"
    .string "Zzz... Check?\0"
    .align 2, 0

    .global gUnknown_80D7E04
gUnknown_80D7E04:
    .string " Zzz... Kwoo...\n"
    .string "Check which Pokémon?\0"
    .align 2, 0

    .global gUnknown_80D7E2C
gUnknown_80D7E2C:
    .string " Zzz... Dwee...? Oops?{WAIT_PRESS}\n"
    .string "Not enough money?\0"
    .align 2, 0

    .global gUnknown_80D7E58
gUnknown_80D7E58:
    .string " Zzz... Hunh?{WAIT_PRESS}\n"
    .string "Sssnore... Sorry...\n"
    .string "Fresh out of Friend Areas...\0"
    .align 2, 0

    .global gUnknown_80D7E9C
gUnknown_80D7E9C:
    .string " Hunh...?{WAIT_PRESS}\n"
    .string "You don{APOSTROPHE}t have any money...\n"
    .string "Zzzzzz...\0"
    .align 2, 0

    .global gUnknown_80D7ED0
gUnknown_80D7ED0:
    .string " Zzz... Zzz?{WAIT_PRESS}\n"
    .string "Hunh...?\n"
    .string "You can{APOSTROPHE}t add to your Friend Areas...\0"
    .align 2, 0

    .global gUnknown_80D7F10
gUnknown_80D7F10:
    .string " Grats... Zzz...{WAIT_PRESS}\n"
    .string "You can go to {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...{EXTRA_MSG}"
    .string " Dwee... Sssnore...\n"
    .string "Make friends with Pokémon in...\n"
    .string "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80D7F7C
gUnknown_80D7F7C:
    .string " Zzz... Dwee... Gotcha...{WAIT_PRESS}\n"
    .string "Zzz... Let{APOSTROPHE}s do it...{EXTRA_MSG}"
    .string " Sssnore♪ Sssnore♪\n"
    .string "{ARG_POKEMON_6}〜♪ {ARG_POKEMON_6}〜♪\n"
    .string "Let{APOSTROPHE}s be friends...{EXTRA_MSG}"
    .string " Kwoo!\n"
    .string "Taaaaaaah!\0"
    .align 2, 0

    .global gUnknown_80D8000
gUnknown_80D8000:
    .string " Kwoo? {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    .string "That{APOSTROPHE}s {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}...\n"
    .string "OK?\0"
    .align 2, 0

    .global gUnknown_80D8030
gUnknown_80D8030:
    .string " Zzz... Wha--?\n"
    .string "More Friend Areas?\0"
    .align 2, 0

    .global gUnknown_80D8054
gUnknown_80D8054:
    .string " Dwee... Hunh?\n"
    .string "Friend Areas...?\n"
    .string "Which one?\0"
    .align 2, 0

    .global gUnknown_80D8080
gUnknown_80D8080:
    .string " Thank... Zzz... You...\n"
    .string "Friends{COMMA} friend...\0"
    .align 2, 0

    .global gUnknown_80D80B0
gUnknown_80D80B0:
    .string " Anything? Kwoo...\n"
    .string "Anything else?\0"
    .align 2, 0

    .global gUnknown_80D80D4
gUnknown_80D80D4:
    .string " Friends... Zzz...\n"
    .string "Welcome to the {ARG_POKEMON_6} Club...\0"
    .align 2, 0

    .global gUnknown_80D8104
gUnknown_80D8104:
    .string " Would you like to get more\n"
    .string "friends...{WAIT_PRESS}\n"
    .string "...More members for your team?{EXTRA_MSG}"
    .string " To add new friends{COMMA} what\n"
    .string "you need are Friend Areas.{EXTRA_MSG}"
    .string " A Pokémon can join your\n"
    .string "rescue team only after it settles in\n"
    .string "the right Friend Area.{EXTRA_MSG}"
    .string " So{COMMA} if you want to recruit\n"
    .string "new members{COMMA} you should add to your\n"
    .string "Friend Areas.{EXTRA_MSG}"
    .string " Oh{COMMA} yes{COMMA} Pokémon can\n"
    .string "only live in the right Friend Area for\n"
    .string "their species.{EXTRA_MSG}"
    .string " If you{APOSTROPHE}re buying a Friend\n"
    .string "Area{COMMA} you should confirm what Pokémon\n"
    .string "can live there by checking {COLOR_1 YELLOW}Info{END_COLOR_TEXT_1}.{EXTRA_MSG}"
    .string " Also{COMMA} there are some Friend\n"
    .string "Areas that I don{APOSTROPHE}t sell.{EXTRA_MSG}"
    .string " I think there are some\n"
    .string "rescue missions that give you access\n"
    .string "to Friend Areas{COMMA} too.{EXTRA_MSG}"
    .string " You should check the\n"
    .string "Pelipper Post Office{APOSTROPHE}s Bulletin Board or\n"
    .string "your Mailbox for rescue requests.{EXTRA_MSG}"
    .string " You know{COMMA} it makes me\n"
    .string "delighted when you make new friends!\0"
    .align 2, 0

    .global gUnknown_80D8420
gUnknown_80D8420:
    .string " {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    .string "I can{APOSTROPHE}t get that Friend Area for you.{WAIT_PRESS}\n"
    .string "I{APOSTROPHE}m really sorry.\0"
    .align 2, 0

    .global gUnknown_80D8468
gUnknown_80D8468:
    .string " {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    .string "I don{APOSTROPHE}t know much about it at all.{WAIT_PRESS}\n"
    .string "I{APOSTROPHE}ll check up on it.{EXTRA_MSG}"
    .string " I{APOSTROPHE}ll add it to the Friend\n"
    .string "Areas you can buy when I find out more.\0"
    .align 2, 0

    .global gUnknown_80D84F8
gUnknown_80D84F8:
    .string " You can already go to the\n"
    .string "Friend Area {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.\0"
    .align 2, 0

    .global gUnknown_80D8528
gUnknown_80D8528:
    .string " {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s Friend Area\n"
    .string "is {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.\0"
    .align 2, 0

    .global gUnknown_80D8550
gUnknown_80D8550:
    .string " Is there another Pokémon\n"
    .string "you{APOSTROPHE}d like to check?\0"
    .align 2, 0

    .global gUnknown_80D8584
gUnknown_80D8584:
    .string " Which Pokémon would you\n"
    .string "like to check?\0"
    .align 2, 0

    .global gUnknown_80D85AC
gUnknown_80D85AC:
    .string " Oops?{WAIT_PRESS}\n"
    .string "It doesn{APOSTROPHE}t look like you have enough\n"
    .string "money!\0"
    .align 2, 0

    .global gUnknown_80D85E4
gUnknown_80D85E4:
    .string " Oops?{WAIT_PRESS}\n"
    .string "Oh{COMMA} too bad.{WAIT_PRESS}\n"
    .string "I{APOSTROPHE}m fresh out of Friend Areas.\0"
    .align 2, 0

    .global gUnknown_80D8620
gUnknown_80D8620:
    .string " Um?{WAIT_PRESS}\n"
    .string "You don{APOSTROPHE}t have any money.\0"
    .align 2, 0

    .global gUnknown_80D8644
gUnknown_80D8644:
    .string " Oops!{WAIT_PRESS}\n"
    .string "You can{APOSTROPHE}t add to your Friend Areas.\0"
    .align 2, 0

    .global gUnknown_80D8674
gUnknown_80D8674:
    .string " Congratulations!{WAIT_PRESS}\n"
    .string "You can go to {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1} now!{EXTRA_MSG}"
    .string " You can recruit\n"
    .string "Pokémon that live in the Friend Area\n"
    .string "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.\0"
    .align 2, 0

    .global gUnknown_80D86E4
gUnknown_80D86E4:
    .string " Gotcha! Let{APOSTROPHE}s do it!{WAIT_PRESS}\n"
    .string "{ARG_POKEMON_6}〜♪ {ARG_POKEMON_6}〜♪{WAIT_PRESS}\n"
    .string "Let{APOSTROPHE}s be friends... Yoomtaaaaaaah!\0"
    .align 2, 0

    .global gUnknown_80D8738
gUnknown_80D8738:
    .string " {COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}?\n"
    .string "That will be {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}.\n"
    .string "Is that OK?\0"
    .align 2, 0

    .global gUnknown_80D876C
gUnknown_80D876C:
    .string " Would you like to add\n"
    .string "other Friend Areas?\0"
    .align 2, 0

    .global gUnknown_80D8798
gUnknown_80D8798:
    .string " You{APOSTROPHE}d like to add to your\n"
    .string "Friend Areas?\n"
    .string "Which one would you like?\0"
    .align 2, 0

    .global gUnknown_80D87E0
gUnknown_80D87E0:
    .string " Thank you! Come again!\n"
    .string "We{APOSTROPHE}re all friends{COMMA} friend!\0"
    .align 2, 0

    .global gUnknown_80D8818
gUnknown_80D8818:
    .string " Anything else I can do for\n"
    .string "you?\0"
    .align 2, 0

    .global gUnknown_80D883C
gUnknown_80D883C:
    .string " Friends are my treasures!\n"
    .string "Welcome to the {ARG_POKEMON_6} Club--\n"
    .string "a circle of friends! \0"
    .align 2, 0

	.global gGulpinDialogue
gGulpinDialogue: @ 80D8888 (Gulpin Link Shop)
    .4byte gUnknown_80D9F74
    .4byte gUnknown_80D9F24
    .4byte gUnknown_80D9EF4
    .4byte gUnknown_80D9EC0
    .4byte gUnknown_80D9E88
    .4byte gUnknown_80D9E48
    .4byte gUnknown_80D9E34
    .4byte gUnknown_80D9DF4
    .4byte gUnknown_80D9DCC
    .4byte gUnknown_80D9DA4
    .4byte gUnknown_80D9D00
    .4byte gUnknown_80D9CC0
    .4byte gUnknown_80D9C68
    .4byte gUnknown_80D9BD8
    .4byte gUnknown_80D9B1C
    .4byte gUnknown_80D9ACC
    .4byte gUnknown_80D9A50
    .4byte gUnknown_80D9A2C
    .4byte gUnknown_80D99F0
    .4byte gUnknown_80D9988
    .4byte gUnknown_80D9904
    .4byte gUnknown_80D98D4
    .4byte gUnknown_80D972C
    .4byte gUnknown_80D9498
    .4byte gUnknown_80D9328
    .4byte gUnknown_80D92EC
    .4byte gUnknown_80D92B4
    .4byte gUnknown_80D9290
    .4byte gUnknown_80D9268
    .4byte gUnknown_80D9234
    .4byte gUnknown_80D9204
    .4byte gUnknown_80D91E4
    .4byte gUnknown_80D91C4
    .4byte gUnknown_80D9194
    .4byte gUnknown_80D9168
    .4byte gUnknown_80D90BC
    .4byte gUnknown_80D9080
    .4byte gUnknown_80D9034
    .4byte gUnknown_80D8F98
    .4byte gUnknown_80D8EC4
    .4byte gUnknown_80D8E9C
    .4byte gUnknown_80D8E48
    .4byte gUnknown_80D8E28
    .4byte gUnknown_80D8DE8
    .4byte gUnknown_80D8D64
    .4byte gUnknown_80D8CC8
    .4byte gUnknown_80D8C98
    .4byte gUnknown_80D8BD4
    .4byte gUnknown_80D8AB8
    .4byte gUnknown_80D8950

    .global gUnknown_80D8950
gUnknown_80D8950:
    .string " Zzz... Snuffle...\n"
    .string "I{APOSTROPHE}d go broke if it weren{APOSTROPHE}t for those\n"
    .string "forgetful Pokémon...{EXTRA_MSG}"
    .string " Zzz... Gwaaah...\n"
    .string "Especially that {COLOR_1 CYAN}{ARG_POKEMON_4}{END_COLOR_TEXT_1}...\n"
    .string "It seems to be forgetful...{EXTRA_MSG}"
    .string " Sssnore...\n"
    .string "I hope it forgets more moves...\n"
    .string "So it needs to see me...{EXTRA_MSG}"
    .string " Zzz... Mumble...\n"
    .string "But we decided to get rid of that\n"
    .string "{COLOR_1 CYAN}{ARG_POKEMON_4}{END_COLOR_TEXT_1}...{EXTRA_MSG}"
    .string " Gwaaaah... Gweh...\n"
    .string "{COLOR_1 CYAN}{ARG_POKEMON_4}{END_COLOR_TEXT_1} won{APOSTROPHE}t be coming around\n"
    .string "anymore... \0"
    .align 2, 0

    .global gUnknown_80D8AB8
gUnknown_80D8AB8:
    .string " Zzznork...{WAIT_PRESS}\n"
    .string "Link moves to use them all in\n"
    .string "one turn...{EXTRA_MSG}"
    .string " Zzz... Fnurf...?\n"
    .string "Linked moves...\n"
    .string "Top one goes first...{EXTRA_MSG}"
    .string " Zzz... Hah...?\n"
    .string "Delink moves to break links...{EXTRA_MSG}"
    .string " Zzzzz... Fwaaah...\n"
    .string "Change order of moves with {R_BUTTON}...\n"
    .string "And up and down on {DPAD}...{EXTRA_MSG}"
    .string " Gwaaah... Gweh...\n"
    .string "Make your own links...\0"
    .align 2, 0

    .global gUnknown_80D8BD4
gUnknown_80D8BD4:
    .string " Zzz... Zzz...\n"
    .string "A set move can be used...\n"
    .string "Press {L_BUTTON} and {A_BUTTON}...{EXTRA_MSG}"
    .string " Sssnort... Set the move...{WAIT_PRESS}\n"
    .string "Press {L_BUTTON} and {A_BUTTON}...{WAIT_PRESS} Use move!{WAIT_PRESS}\n"
    .string "Convenient...{EXTRA_MSG}"
    .string " Sssnore...\n"
    .string "Switch the set move in a dungeon{COMMA} too...\0"
    .align 2, 0

    .global gUnknown_80D8C98
gUnknown_80D8C98:
    .string " Zzznork... Fnurfle?\n"
    .string "What do you want to know?\0"
    .align 2, 0

    .global gUnknown_80D8CC8
gUnknown_80D8CC8:
    .string " Fgwaaah...\n"
    .string "Here goes...{EXTRA_MSG}"
    .string " Zzznort...\n"
    .string "Gggggggg...{WAIT_PRESS} Pwah!{EXTRA_MSG}"
    .string " Fwaaah hah!\n"
    .string "There...{EXTRA_MSG}"
    .string " Zzz... Mutter...\n"
    .string "{COLOR_1 CYAN}{ARG_POKEMON_5}{END_COLOR_TEXT_1} forgot...\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and moves linked to it...\0"
    .align 2, 0

    .global gUnknown_80D8D64
gUnknown_80D8D64:
    .string " Fgwaaah...\n"
    .string "Here goes...{EXTRA_MSG}"
    .string " Zzznort...\n"
    .string "Gggggggg...{WAIT_PRESS} Pwah!{EXTRA_MSG}"
    .string " Fwaaah hah!\n"
    .string "There...{EXTRA_MSG}"
    .string " Zzz... Mumble...\n"
    .string "{COLOR_1 CYAN}{ARG_POKEMON_5}{END_COLOR_TEXT_1} forgot...\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80D8DE8
gUnknown_80D8DE8:
    .string " Zzz... Fwaah? Forget...?\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and any moves\n"
    .string "linked to it?\0"
    .align 2, 0

    .global gUnknown_80D8E28
gUnknown_80D8E28:
    .string " Zzz... Forget...?\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}?\0"
    .align 2, 0

    .global gUnknown_80D8E48
gUnknown_80D8E48:
    .string " Zzznork...? Hunh?\n"
    .string "You{APOSTROPHE}re a special Pokémon...{EXTRA_MSG}"
    .string " Mumble...\n"
    .string "I can{APOSTROPHE}t help you...\0"
    .align 2, 0

    .global gUnknown_80D8E9C
gUnknown_80D8E9C:
    .string " Zzz... Fwaah?\n"
    .string "No moves to remember...\0"
    .align 2, 0

    .global gUnknown_80D8EC4
gUnknown_80D8EC4:
    .string " Fgwaaah...\n"
    .string "Here goes...{EXTRA_MSG}"
    .string " Zzznort...\n"
    .string "Gggggggg...{WAIT_PRESS} Pwah! Gulpin!{EXTRA_MSG}"
    .string " Fwaaah hah!\n"
    .string "There...{EXTRA_MSG}"
    .string " Zzz... Mumble...\n"
    .string "{COLOR_1 CYAN_3}{ARG_POKEMON_5}{END_COLOR_TEXT_1}{APOSTROPHE}s OK...{EXTRA_MSG}"
    .string " Sssnork... Forgotten...\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and moves linked to it...\n"
    .string "Remembered {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80D8F98
gUnknown_80D8F98:
    .string " Fgwaah...\n"
    .string "Here goes...{EXTRA_MSG}"
    .string " Zzznort...\n"
    .string "Gggggggg...{WAIT_PRESS} Pwah! Gulpin!{EXTRA_MSG}"
    .string " Fwaah hah!\n"
    .string "There...{EXTRA_MSG}"
    .string " Zzz... Zzz... {COLOR_1 CYAN_3}{ARG_POKEMON_5}{END_COLOR_TEXT_1}\n"
    .string "forgot {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}...\n"
    .string "Remembered {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80D9034
gUnknown_80D9034:
    .string " Zzz? Fnurf? \n"
    .string "Forget {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}...and moves linked\n"
    .string "to it? Remember {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}?\0"
    .align 2, 0

    .global gUnknown_80D9080
gUnknown_80D9080:
    .string " Zzznort... Grumble...\n"
    .string "Forget {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}?\n"
    .string "Remember {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}?\0"
    .align 2, 0

    .global gUnknown_80D90BC
gUnknown_80D90BC:
    .string " Zzzznort... Move...?\n"
    .string "Remember {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}?{EXTRA_MSG}"
    .string " Fwaah...\n"
    .string "Gggggggggggg...{WAIT_PRESS} Gulpin!{EXTRA_MSG}"
    .string " Fgwaah...\n"
    .string "There...{EXTRA_MSG}"
    .string " Zzz... Zzz...\n"
    .string "{COLOR_1 CYAN_3}{ARG_POKEMON_5}{END_COLOR_TEXT_1} remembered...\n"
    .string "Hunh? That move{COMMA} {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80D9168
gUnknown_80D9168:
    .string " Zzz... Fgwah...?\n"
    .string "Remember what? What move?\0"
    .align 2, 0

    .global gUnknown_80D9194
gUnknown_80D9194:
    .string " Gwaah... Gwaah...\n"
    .string "Who{APOSTROPHE}s gonna link moves?\0"
    .align 2, 0

    .global gUnknown_80D91C4
gUnknown_80D91C4:
    .string " Zzz... Zzz...\n"
    .string "Come again...\0"
    .align 2, 0

    .global gUnknown_80D91E4
gUnknown_80D91E4:
    .string " Zzz... Zzz...\n"
    .string "Keep going...?\0"
    .align 2, 0

    .global gUnknown_80D9204
gUnknown_80D9204:
    .string " Zzznort... Zzznnort...\n"
    .string "Can{APOSTROPHE}t forget that...\0"
    .align 2, 0

    .global gUnknown_80D9234
gUnknown_80D9234:
    .string " Sssnork... Sssnork...\n"
    .string "Nothing to be delinked...\0"
    .align 2, 0

    .global gUnknown_80D9268
gUnknown_80D9268:
    .string " Zzz... Grumph...\n"
    .string "Nothing to link...\0"
    .align 2, 0

    .global gUnknown_80D9290
gUnknown_80D9290:
    .string " Zzz... Grunt?\n"
    .string "Not enough money...\0"
    .align 2, 0

    .global gUnknown_80D92B4
gUnknown_80D92B4:
    .string " Zzz... Gulpin Link Shop...\n"
    .string "Link for just 150 {POKE}...\0"
    .align 2, 0

    .global gUnknown_80D92EC
gUnknown_80D92EC:
    .string " Zzz... Hello...\n"
    .string "Gulpin Link Shop...\n"
    .string "Link for 150 {POKE}...\0"
    .align 2, 0

    .global gUnknown_80D9328
gUnknown_80D9328:
    .string " What if you had to forget\n"
    .string "a move{COMMA} but you wanted it back?{WAIT_PRESS}\n"
    .string "Ever face that situation?{EXTRA_MSG}"
    .string " I can help!{WAIT_PRESS}\n"
    .string "Come to me{COMMA} and I can make you instantly\n"
    .string "remember forgotten moves!{EXTRA_MSG}"
    .string " I...{WAIT_PRESS}\n"
    .string "Well{COMMA} when Pokémon remember...{WAIT_PRESS}\n"
    .string "I love seeing that instant!{EXTRA_MSG}"
    .string " That look of enlightenment!{WAIT_PRESS}\n"
    .string "That amazed look of pleasure!{EXTRA_MSG}"
    .string " I run this business because\n"
    .string "I live to see that moment!\0"
    .align 2, 0

    .global gUnknown_80D9498
gUnknown_80D9498:
    .string " When moves are linked...{WAIT_PRESS}\n"
    .string "Two or more moves can be used one after\n"
    .string "another in one turn!{EXTRA_MSG}"
    .string " For example{COMMA} if the moves\n"
    .string "{COLOR_1 CYAN}Scratch{END_COLOR_TEXT_1} and {COLOR_1 CYAN}Growl{END_COLOR_TEXT_1} are\n"
    .string "linked...{EXTRA_MSG}"
    .string " Both {COLOR_1 CYAN}Scratch{END_COLOR_TEXT_1} and {COLOR_1 CYAN}Growl{END_COLOR_TEXT_1} are\n"
    .string "used in one turn!{WAIT_PRESS}\n"
    .string "See? Amazing{COMMA} huh?{EXTRA_MSG}"
    .string " Using links{COMMA} heheh...{WAIT_PRESS}\n"
    .string "Well{COMMA} depending on the moves you link{COMMA}\n"
    .string "you can get incredible results!{EXTRA_MSG}"
    .string " Oh{COMMA} yes.\n"
    .string "When moves are linked{COMMA} they are used in\n"
    .string "sequence from the top one first.{EXTRA_MSG}"
    .string " You can also separate linked\n"
    .string "moves by selecting the Delink command.{EXTRA_MSG}"
    .string " The sequence of moves can\n"
    .string "be changed by pressing {R_BUTTON}{COMMA}\n"
    .string "then pressing up or down on {DPAD}.{EXTRA_MSG}"
    .string " Try to innovate with links.{WAIT_PRESS}\n"
    .string "Try creating links of your very own!\0"
    .align 2, 0

    .global gUnknown_80D972C
gUnknown_80D972C:
    .string " When you{APOSTROPHE}re in a dungeon\n"
    .string "and you{APOSTROPHE}re about to use a move...{WAIT_PRESS}\n"
    .string "Isn{APOSTROPHE}t it a pain to open a window each time?{EXTRA_MSG}"
    .string " You can avoid that!{WAIT_PRESS}\n"
    .string "You can just conveniently {QUOTE_START}Set{QUOTE_END}\n"
    .string "a move for instant use!{EXTRA_MSG}"
    .string " A set move can be instantly\n"
    .string "used with {L_BUTTON} and {A_BUTTON}!{WAIT_PRESS}\n"
    .string "See? Isn{APOSTROPHE}t it easy?{EXTRA_MSG}"
    .string " Just set the move...{WAIT_PRESS}\n"
    .string "Hold {L_BUTTON} and then press {A_BUTTON} to use it!{WAIT_PRESS}\n"
    .string "It{APOSTROPHE}s very convenient!{EXTRA_MSG}"
    .string " You can also switch the set\n"
    .string "move in a dungeon.\n"
    .string "Do try it out!\n"
    .string "\0"
    .align 2, 0

    .global gUnknown_80D98D4
gUnknown_80D98D4:
    .string " Sure thing!\n"
    .string "What do you need information on?\0"
    .align 2, 0

    .global gUnknown_80D9904
gUnknown_80D9904:
    .string " OK{COMMA} here goes!{EXTRA_MSG}"
    .string " Gggggggg...{WAIT_PRESS} Poof!{EXTRA_MSG}"
    .string " There!\n"
    .string "Success!{EXTRA_MSG}"
    .string " {COLOR_1 CYAN}{ARG_POKEMON_5}{END_COLOR_TEXT_1} has forgotten\n"
    .string "the move {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and any moves\n"
    .string "linked to it!\0"
    .align 2, 0

    .global gUnknown_80D9988
gUnknown_80D9988:
    .string " OK{COMMA} here goes!{EXTRA_MSG}"
    .string " Gggggggg...{WAIT_PRESS} Poof!{EXTRA_MSG}"
    .string " There!\n"
    .string "Success!{EXTRA_MSG}"
    .string " {COLOR_1 CYAN}{ARG_POKEMON_5}{END_COLOR_TEXT_1} has forgotten\n"
    .string "the move {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}!\0"
    .align 2, 0

    .global gUnknown_80D99F0
gUnknown_80D99F0:
    .string " So{COMMA} forget the move\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and any moves linked to it?\0"
    .align 2, 0

    .global gUnknown_80D9A2C
gUnknown_80D9A2C:
    .string " So{COMMA} forget the move\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}?\0"
    .align 2, 0

    .global gUnknown_80D9A50
gUnknown_80D9A50:
    .string " Uh... Huh?{WAIT_PRESS}\n"
    .string "You appear to be a special Pokémon.{EXTRA_MSG}"
    .string " I can{APOSTROPHE}t help you remember\n"
    .string "any moves{COMMA} I don{APOSTROPHE}t think.\n"
    .string "I{APOSTROPHE}m sorry.\0"
    .align 2, 0

    .global gUnknown_80D9ACC
gUnknown_80D9ACC:
    .string " Uh... Hello?{WAIT_PRESS}\n"
    .string "There don{APOSTROPHE}t appear to be any moves that\n"
    .string "can be remembered.\0"
    .align 2, 0

    .global gUnknown_80D9B1C
gUnknown_80D9B1C:
    .string " OK{COMMA} here goes!{EXTRA_MSG}"
    .string " Gggggggg...{WAIT_PRESS} Pwah! Gulpin!{EXTRA_MSG}"
    .string " There!\n"
    .string "Success!{EXTRA_MSG}"
    .string " {COLOR_1 CYAN_3}{ARG_POKEMON_5}{END_COLOR_TEXT_1} is done!{EXTRA_MSG}"
    .string " It{APOSTROPHE}s forgotten the move\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and any moves linked to it{COMMA}\n"
    .string "and {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1} has been remembered!\0"
    .align 2, 0

    .global gUnknown_80D9BD8
gUnknown_80D9BD8:
    .string " OK{COMMA} here goes!{EXTRA_MSG}"
    .string " Gggggggg...{WAIT_PRESS} Pwah! Gulpin!{EXTRA_MSG}"
    .string " There!\n"
    .string "Success!{EXTRA_MSG}"
    .string " {COLOR_1 CYAN_3}{ARG_POKEMON_5}{END_COLOR_TEXT_1} has forgotten\n"
    .string "the move {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and remembered\n"
    .string "the move {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}!\0"
    .align 2, 0

    .global gUnknown_80D9C68
gUnknown_80D9C68:
    .string " So{COMMA} forget {COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1}\n"
    .string "and any moves linked to it{COMMA} and remember\n"
    .string "the move {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}?\0"
    .align 2, 0

    .global gUnknown_80D9CC0
gUnknown_80D9CC0:
    .string " So{COMMA} forget the move\n"
    .string "{COLOR_1 GREEN}{ARG_POKEMON_1}{END_COLOR_TEXT_1} and remember the move\n"
    .string "{COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}?\0"
    .align 2, 0

    .global gUnknown_80D9D00
gUnknown_80D9D00:
    .string " So{COMMA} the move {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}\n"
    .string "is the one to be remembered?{WAIT_PRESS}\n"
    .string "OK{COMMA} here goes!{EXTRA_MSG}"
    .string " Gggggggggggg...{WAIT_PRESS} Gulpin!{EXTRA_MSG}"
    .string " There!\n"
    .string "Success!{EXTRA_MSG}"
    .string " {COLOR_1 CYAN_3}{ARG_POKEMON_5}{END_COLOR_TEXT_1} has\n"
    .string "remembered the move {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}!\0"
    .align 2, 0

    .global gUnknown_80D9DA4
gUnknown_80D9DA4:
    .string " Which move would you like\n"
    .string "to recall?\0"
    .align 2, 0

    .global gUnknown_80D9DCC
gUnknown_80D9DCC:
    .string " Good!\n"
    .string "Now{COMMA} who wants to link moves?\0"
    .align 2, 0

    .global gUnknown_80D9DF4
gUnknown_80D9DF4:
    .string " Whenever you get the urge\n"
    .string "to link moves{COMMA} please come see me!\0"
    .align 2, 0

    .global gUnknown_80D9E34
gUnknown_80D9E34:
    .string " Shall we go on?\0"
    .align 2, 0

    .global gUnknown_80D9E48
gUnknown_80D9E48:
    .string " If you forget that move{COMMA}\n"
    .string "you won{APOSTROPHE}t have any moves at all.\0"
    .align 2, 0

    .global gUnknown_80D9E88
gUnknown_80D9E88:
    .string " That move isn{APOSTROPHE}t linked{COMMA}\n"
    .string "so it can{APOSTROPHE}t be delinked.\0"
    .align 2, 0

    .global gUnknown_80D9EC0
gUnknown_80D9EC0:
    .string " Too bad.\n"
    .string "There are no moves that can be linked.\0"
    .align 2, 0

    .global gUnknown_80D9EF4
gUnknown_80D9EF4:
    .string " Uh... Hello?\n"
    .string "You don{APOSTROPHE}t have enough money?\0"
    .align 2, 0

    .global gUnknown_80D9F24
gUnknown_80D9F24:
    .string " Welcome to the Gulpin\n"
    .string "Link Shop!\n"
    .string "Link moves all you like for just 150 {POKE}!\0"
    .align 2, 0

    .global gUnknown_80D9F74
gUnknown_80D9F74:
    .string " Hello!\n"
    .string "Welcome to the Gulpin Link Shop!\n"
    .string "Link moves all you like for just 150 {POKE}!\0"
    .align 2, 0

	.global gMakuhitaDialogue
gMakuhitaDialogue: @ 80D9FC8 (Makuhita Dojo)
    .4byte gUnknown_80DAA44
    .4byte gUnknown_80DAA2C
    .4byte gUnknown_80DA9F4
    .4byte gUnknown_80DA9D4
    .4byte gUnknown_80DA998
    .4byte gUnknown_80DA908
    .4byte gUnknown_80DA844
    .4byte gUnknown_80DA688
    .4byte gUnknown_80DA62C
    .4byte gUnknown_80DA338
    .4byte gUnknown_80DA30C
    .4byte gUnknown_80DA2F0
    .4byte gUnknown_80DA2D4
    .4byte gUnknown_80DA2B4
    .4byte gUnknown_80DA290
    .4byte gUnknown_80DA248
    .4byte gUnknown_80DA204
    .4byte gUnknown_80DA100
    .4byte gUnknown_80DA0DC
    .4byte gUnknown_80DA018

    .global gUnknown_80DA018
gUnknown_80DA018:
    .string " Zzznarr... Zzz...\n"
    .string "This dojo...\n"
    .string "Help rescue teams...{EXTRA_MSG}"
    .string " Zzznarr... Urr...\n"
    .string "Train in different rooms to level up...{EXTRA_MSG}"
    .string " Zzznarr... Urr!\n"
    .string "Make stronger rescue team...{EXTRA_MSG}"
    .string " Urr... Zzznarr!\n"
    .string "Don{APOSTROPHE}t let up!\0"
    .align 2, 0

    .global gUnknown_80DA0DC
gUnknown_80DA0DC:
    .string " Zzznarr... Zzz...!\n"
    .string "Keep working...\0"
    .align 2, 0

    .global gUnknown_80DA100
gUnknown_80DA100:
    .string " Ah... Zzznarr...\n"
    .string "Cleared it...{EXTRA_MSG}"
    .string " Zzzznarr... Urr...\n"
    .string "Good going... Keep going...{WAIT_PRESS}\n"
    .string "Hunh...{WAIT_PRESS} ...{EXTRA_MSG}"
    .string " Gwoh?{WAIT_PRESS}\n"
    .string "Gwogwogwoh?{EXTRA_MSG}"
    .string " Mugawah?\n"
    .string "Cleared everything?{EXTRA_MSG}"
    .string " Zzznarr!\n"
    .string "Congrazzz...{EXTRA_MSG}"
    .string " Zzznarr... Zzznarr...\n"
    .string "Your reward...\n"
    .string "Promised...{EXTRA_MSG}"
    .string " Zzz... Urr!\n"
    .string "{COLOR_1 GREEN_2}Bonsly Doll{END_COLOR_TEXT_1}...\0"
    .align 2, 0

    .global gUnknown_80DA204
gUnknown_80DA204:
    .string " Ah... Zzznarr...\n"
    .string "Cleared it...{EXTRA_MSG}"
    .string " Congrazzz...\n"
    .string "Keep going... Zzz...\0"
    .align 2, 0

    .global gUnknown_80DA248
gUnknown_80DA248:
    .string " Aiyah... Zzznarr...\n"
    .string "Didn{APOSTROPHE}t finish...{EXTRA_MSG}"
    .string " Zzz... Urr?\n"
    .string "No giving up...\0"
    .align 2, 0

    .global gUnknown_80DA290
gUnknown_80DA290:
    .string " Zzz... Narr...\n"
    .string "{ARG_POKEMON_0}? {APOSTROPHE}K{COMMA} go...\0"
    .align 2, 0

    .global gUnknown_80DA2B4
gUnknown_80DA2B4:
    .string " Zzznarr... Zzz...\n"
    .string "Train where?\0"
    .align 2, 0

    .global gUnknown_80DA2D4
gUnknown_80DA2D4:
    .string " Urr... Narr...\n"
    .string "See you...\0"
    .align 2, 0

    .global gUnknown_80DA2F0
gUnknown_80DA2F0:
    .string " Zzznarr... Urr?\n"
    .string "What else?\0"
    .align 2, 0

    .global gUnknown_80DA30C
gUnknown_80DA30C:
    .string " Zzznarr... Zzznarr...\n"
    .string "Makuhita... Dojo...\0"
    .align 2, 0

    .global gUnknown_80DA338
gUnknown_80DA338:
    .string " This dojo was founded to\n"
    .string "support the efforts of rescue teams.{EXTRA_MSG}"
    .string " Train in different rooms to\n"
    .string "level up...{WAIT_PRESS}\n"
    .string "And toughen up your rescue team.{EXTRA_MSG}"
    .string " Also...{WAIT_PRESS}\n"
    .string "In the {COLOR_1 YELLOW_4}Fire Maze{END_COLOR_TEXT_1} you will find only\n"
    .string "Fire-type Pokémon.{EXTRA_MSG}"
    .string " In the {COLOR_1 YELLOW_4}Water Maze{END_COLOR_TEXT_1} there\n"
    .string "will only be Water-type Pokémon.{EXTRA_MSG}"
    .string " In such ways{COMMA} only one type\n"
    .string "of Pokémon will be in a given room.\n"
    .string "Study how types match up in battle.{EXTRA_MSG}"
    .string " The Pokémon in this dojo{COMMA}\n"
    .string "by the way{COMMA} are all volunteers.{EXTRA_MSG}"
    .string " They are participating\n"
    .string "because they want to see rescue teams\n"
    .string "succeed.{EXTRA_MSG}"
    .string " The only thanks they expect\n"
    .string "is to see you become stronger.\n"
    .string "Don{APOSTROPHE}t let them down!{EXTRA_MSG}"
    .string " There{APOSTROPHE}s more.{WAIT_PRESS}\n"
    .string "For a rescue team that successfully\n"
    .string "completes all training courses...{EXTRA_MSG}"
    .string " I have a special reward!{EXTRA_MSG}"
    .string " Let that compel you to train\n"
    .string "harder!\0"
    .align 2, 0

    .global gUnknown_80DA62C
gUnknown_80DA62C:
    .string " Don{APOSTROPHE}t let up on your training!\n"
    .string "Keep bettering yourself!{EXTRA_MSG}"
    .string " May you never lose your\n"
    .string "drive!\0"
    .align 2, 0

    .global gUnknown_80DA688
gUnknown_80DA688:
    .string " Ah...\n"
    .string "You have succeeded in your training!{EXTRA_MSG}"
    .string " You{APOSTROPHE}ve shown your worth!{WAIT_PRESS}\n"
    .string "Without a doubt{COMMA} you have grown more\n"
    .string "powerful from your training!{WAIT_PRESS} Wait...{WAIT_PRESS} ...{EXTRA_MSG}"
    .string " Wuh?{WAIT_PRESS}\n"
    .string "What{COMMA} what{COMMA} what?!{EXTRA_MSG}"
    .string " Did you maybe...{WAIT_PRESS}\n"
    .string "Conquer all the training courses?{EXTRA_MSG}"
    .string " That{APOSTROPHE}s...{WAIT_PRESS} Amazing! You!{WAIT_PRESS}\n"
    .string "Congratulations!{EXTRA_MSG}"
    .string " I promised!{WAIT_PRESS}\n"
    .string "I promised you a reward for completing\n"
    .string "the training courses!{EXTRA_MSG}"
    .string " So... Here it is!{WAIT_PRESS}\n"
    .string "My {COLOR_1 GREEN_2}Bonsly Doll{END_COLOR_TEXT_1}!{EXTRA_MSG}"
    .string " Isn{APOSTROPHE}t it smashing? Hey?!\0"
    .align 2, 0

    .global gUnknown_80DA844
gUnknown_80DA844:
    .string " Ah...\n"
    .string "You have succeeded in your training!{EXTRA_MSG}"
    .string " You{APOSTROPHE}ve shown your worth!{WAIT_PRESS}\n"
    .string "Without a doubt{COMMA} you have grown more\n"
    .string "powerful from your training!{EXTRA_MSG}"
    .string " May this success drive\n"
    .string "you to train even harder!\0"
    .align 2, 0

    .global gUnknown_80DA908
gUnknown_80DA908:
    .string " Aiyah...{WAIT_PRESS}\n"
    .string "You failed to reach the end...{WAIT_PRESS}\n"
    .string "More training is what you need.{EXTRA_MSG}"
    .string " But effort is never wasted!{EXTRA_MSG}"
    .string " Learn from this and move\n"
    .string "forward!\0"
    .align 2, 0

    .global gUnknown_80DA998
gUnknown_80DA998:
    .string " The {ARG_POKEMON_0}?{WAIT_PRESS}\n"
    .string "Your decision stands!{WAIT_PRESS}\n"
    .string "Let the training begin!\0"
    .align 2, 0

    .global gUnknown_80DA9D4
gUnknown_80DA9D4:
    .string " Where do you wish to train?\0"
    .align 2, 0

    .global gUnknown_80DA9F4
gUnknown_80DA9F4:
    .string " Fine{COMMA} farewell.\n"
    .string "Return if you seek more training.\0"
    .align 2, 0

    .global gUnknown_80DAA2C
gUnknown_80DAA2C:
    .string " What else do you seek?\0"
    .align 2, 0

    .global gUnknown_80DAA44
gUnknown_80DAA44:
    .string " This is the Makuhita Dojo!{WAIT_PRESS}\n"
    .string "Through rigorous training{COMMA} one begets\n"
    .string "true power.\0"
    .align 2, 0

	.global gGameHints
gGameHints: @ 80DAA98 (Help Menu?)
    .4byte gUnknown_80DAF54
    .4byte gUnknown_80DAEE0
    .4byte gUnknown_80DAECC
    .4byte gUnknown_80DADD4
    .4byte gUnknown_80DADCC
    .4byte gUnknown_80DAD40
    .4byte gUnknown_80DAD28
    .4byte gUnknown_80DABE8
    .4byte gUnknown_80DABD8
    .4byte gUnknown_80DAAC0

    .global gUnknown_80DAAC0
gUnknown_80DAAC0:
    .string "Before leaving on an adventure{COMMA} go visit\n"
    .string "friends in their Friend Areas and pick\n"
    .string "your mission members.\n"
    .string "The team can include members up to\n"
    .string "a total body size of 6{STAR_BULLET}. The body size\n"
    .string "data is under the Info section.\n"
    .string "Dungeons may also limit how many\n"
    .string "members are allowed to go inside.\0"
    .align 2, 0

    .global gUnknown_80DABD8
gUnknown_80DABD8:
    .string "Building a Team\0"
    .align 2, 0

    .global gUnknown_80DABE8
gUnknown_80DABE8:
    .string "If new recruits join you{COMMA} try to return to\n"
    .string "your base without letting them faint.\n"
    .string "If you get them out safely{COMMA} they{APOSTROPHE}ll wait\n"
    .string "for you in their Friend Areas.\n"
    .string "Once you get them out{COMMA} they{APOSTROPHE}ll always\n"
    .string "return home if they faint in a dungeon.\n"
    .string "If you faint in a dungeon{COMMA} you lose all your\n"
    .string "money and some items{COMMA} too.\0"
    .align 2, 0

    .global gUnknown_80DAD28
gUnknown_80DAD28:
    .string "Adventures with Friends\0"
    .align 2, 0

    .global gUnknown_80DAD40
gUnknown_80DAD40:
    .string "You can save your adventure by\n"
    .string "hopping onto your bed in your base.\n"
    .string "Get in the habit of saving regularly as\n"
    .string "you progress in your adventure.\0"
    .align 2, 0

    .global gUnknown_80DADCC
gUnknown_80DADCC:
    .string "Saving\0"
    .align 2, 0

    .global gUnknown_80DADD4
gUnknown_80DADD4:
    .string "Selecting multiple items in storage:\n"
    .string "  Select an item{COMMA} then press {L_BUTTON} or {R_BUTTON}.\n"
    .string "Moving to the Friend Area Map:\n"
    .string "  Move out from the town{APOSTROPHE}s west side\n"
    .string "  while pressing {L_BUTTON} or {R_BUTTON}.\n"
    .string "Moving diagonally on the Friend Area Map:\n"
    .string "  {DPAD} while keeping {R_BUTTON} pressed.\0"
    .align 2, 0

    .global gUnknown_80DAECC
gUnknown_80DAECC:
    .string "Controls in Town 2\0"
    .align 2, 0

    .global gUnknown_80DAEE0
gUnknown_80DAEE0:
    .string "Talk: {A_BUTTON}\n"
    .string "Move: {DPAD}\n"
    .string "Window: {B_BUTTON} lightly\n"
    .string "Message scroll: {A_BUTTON} or {B_BUTTON}\n"
    .string "Cancel: {B_BUTTON}\n"
    .string "Description: Choose item or move{COMMA} {START_BUTTON}\0"
    .align 2, 0

    .global gUnknown_80DAF54
gUnknown_80DAF54:
    .string "Controls in Town 1\0"
    .align 2, 0

    .string "pksdir0\0"

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
	.global gUnknown_80DAFC0
gUnknown_80DAFC0: @ 80DAFC0
    .2byte 3, 0xD
    .2byte 0xF, 0xD
    .2byte 0x1B, 0xD
    .2byte 0x27, 0xD
    .2byte 0x33, 0xD
    .2byte 0x40, 0xF
    .2byte 0x4C, 0xF
    .2byte 0x58, 0xF
    .2byte 0x64, 0xF
    .2byte 0x70, 0xF
    .2byte 0x7C, 0xF
    .2byte 0x88, 0xF
    .2byte 0x94, 0xF
    .2byte 0xA1, 0xD
    .2byte 0xAD, 0xD
    .2byte 0xB9, 0xD
    .2byte 0xC5, 0xD
    .2byte 0xD1, 0xD
    .2byte 3, 0x1A
    .2byte 0xF, 0x1A
    .2byte 0x1B, 0x1A
    .2byte 0x27, 0x1A
    .2byte 0x33, 0x1A
    .2byte 0x40, 0x1C
    .2byte 0x4C, 0x1C
    .2byte 0x58, 0x1C
    .2byte 0x64, 0x1C
    .2byte 0x70, 0x1C
    .2byte 0x7C, 0x1C
    .2byte 0x88, 0x1C
    .2byte 0x94, 0x1C
    .2byte 0xA1, 0x1A
    .2byte 0xAD, 0x1A
    .2byte 0xB9, 0x1A
    .2byte 0xC5, 0x1A
    .2byte 0xD1, 0x1A
    .2byte 3, 0x28
    .2byte 0xF, 0x28
    .2byte 0x1B, 0x28
    .2byte 0x27, 0x28
    .2byte 0x33, 0x28
    .2byte 0x40, 0x2A
    .2byte 0x4C, 0x2A
    .2byte 0x58, 0x2A
    .2byte 0x64, 0x2A
    .2byte 0x70, 0x2A
    .2byte 0x7C, 0x2A
    .2byte 0x88, 0x2A
    .2byte 0x94, 0x2A
    .2byte 0xA1, 0x28
    .2byte 0xAD, 0x28
    .2byte 0xB9, 0x28
    .2byte 0xC5, 0x28
    .2byte 0xD1, 0x28

	.global gUnknown_80DB098
gUnknown_80DB098: @ 80DB098
    .2byte 0x20, 0x12
    .2byte 0x2E, 0x12
    .2byte 0x3C, 0x12
    .2byte 0x4A, 0x12
    .2byte 0x58, 0x14
    .2byte 0x66, 0x14
    .2byte 0x74, 0x14
    .2byte 0x82, 0x14
    .2byte 0x90, 0x12
    .2byte 0x9E, 0x12
    .2byte 0xAC, 0x12
    .2byte 0xBA, 0x12
    .2byte 0x20, 0x24
    .2byte 0x2E, 0x24
    .2byte 0x3C, 0x24
    .2byte 0x4A, 0x24
    .2byte 0x58, 0x26
    .2byte 0x66, 0x26
    .2byte 0x74, 0x26
    .2byte 0x82, 0x26
    .2byte 0x90, 0x24
    .2byte 0x9E, 0x24
    .2byte 0xAC, 0x24
    .2byte 0xBA, 0x24

	.global gUnknown_80DB0F8
gUnknown_80DB0F8: @ 80DB0F8
.macro st_80DB0F8, a, b, c, d, e, f, g, h
    .byte \a, \b, \c, \d, \e, \f, \g
    .align 2, 0
    .4byte \h
.endm
    st_80DB0F8 0,  0,  0,  0,  8,   3,  0, 264
    st_80DB0F8 0,  0,  0,  0,  8,   14, 0, 264
    st_80DB0F8 0,  0,  0,  0,  8,   25, 0, 264
    st_80DB0F8 5,  4,  81, 9,  8,   36, 3, 263
    st_80DB0F8 3,  5,  82, 10, 8,   47, 3, 261
    st_80DB0F8 4,  3,  83, 11, 8,   58, 3, 262
    st_80DB0F8 11, 7,  78, 12, 36,  3,  0, 97
    st_80DB0F8 6,  8,  79, 13, 36,  14, 0, 110
    st_80DB0F8 7,  9,  80, 14, 36,  25, 0, 65
    st_80DB0F8 8,  10, 3,  15, 36,  36, 0, 78
    st_80DB0F8 9,  11, 4,  16, 36,  47, 0, 233
    st_80DB0F8 10, 6,  5,  17, 36,  58, 0, 43
    st_80DB0F8 17, 13, 6,  18, 50,  3,  0, 98
    st_80DB0F8 12, 14, 7,  19, 50,  14, 0, 111
    st_80DB0F8 13, 15, 8,  20, 50,  25, 0, 66
    st_80DB0F8 14, 16, 9,  21, 50,  36, 0, 79
    st_80DB0F8 15, 17, 10, 22, 50,  47, 0, 49
    st_80DB0F8 16, 12, 11, 23, 50,  58, 0, 45
    st_80DB0F8 23, 19, 12, 24, 64,  3,  0, 99
    st_80DB0F8 18, 20, 13, 25, 64,  14, 0, 112
    st_80DB0F8 19, 21, 14, 26, 64,  25, 0, 67
    st_80DB0F8 20, 22, 15, 27, 64,  36, 0, 80
    st_80DB0F8 21, 23, 16, 28, 64,  47, 0, 50
    st_80DB0F8 22, 18, 17, 29, 64,  58, 0, 44
    st_80DB0F8 29, 25, 18, 30, 78,  3,  0, 100
    st_80DB0F8 24, 26, 19, 31, 78,  14, 0, 113
    st_80DB0F8 25, 27, 20, 32, 78,  25, 0, 68
    st_80DB0F8 26, 28, 21, 33, 78,  36, 0, 81
    st_80DB0F8 27, 29, 22, 34, 78,  47, 0, 51
    st_80DB0F8 28, 24, 23, 35, 78,  58, 0, 46
    st_80DB0F8 35, 31, 24, 36, 92,  3,  0, 101
    st_80DB0F8 30, 32, 25, 37, 92,  14, 0, 114
    st_80DB0F8 31, 33, 26, 38, 92,  25, 0, 69
    st_80DB0F8 32, 34, 27, 39, 92,  36, 0, 82
    st_80DB0F8 33, 35, 28, 40, 92,  47, 0, 52
    st_80DB0F8 34, 30, 29, 41, 92,  58, 0, 33
    st_80DB0F8 41, 37, 30, 42, 106, 3,  0, 102
    st_80DB0F8 36, 38, 31, 43, 106, 14, 0, 115
    st_80DB0F8 37, 39, 32, 44, 106, 25, 0, 70
    st_80DB0F8 38, 40, 33, 45, 106, 36, 0, 83
    st_80DB0F8 39, 41, 34, 46, 106, 47, 0, 53
    st_80DB0F8 40, 36, 35, 47, 106, 58, 0, 63
    st_80DB0F8 47, 43, 36, 48, 120, 3,  0, 103
    st_80DB0F8 42, 44, 37, 49, 120, 14, 0, 116
    st_80DB0F8 43, 45, 38, 50, 120, 25, 0, 71
    st_80DB0F8 44, 46, 39, 51, 120, 36, 0, 84
    st_80DB0F8 45, 47, 40, 52, 120, 47, 0, 54
    st_80DB0F8 46, 42, 41, 53, 120, 58, 0, 145
    st_80DB0F8 53, 49, 42, 54, 134, 3,  0, 104
    st_80DB0F8 48, 50, 43, 55, 134, 14, 0, 117
    st_80DB0F8 49, 51, 44, 56, 134, 25, 0, 72
    st_80DB0F8 50, 52, 45, 57, 134, 36, 0, 85
    st_80DB0F8 51, 53, 46, 58, 134, 47, 0, 55
    st_80DB0F8 52, 48, 47, 59, 134, 58, 0, 146
    st_80DB0F8 59, 55, 48, 60, 148, 3,  0, 105
    st_80DB0F8 54, 56, 49, 61, 148, 14, 0, 118
    st_80DB0F8 55, 57, 50, 62, 148, 25, 0, 73
    st_80DB0F8 56, 58, 51, 63, 148, 36, 0, 86
    st_80DB0F8 57, 59, 52, 64, 148, 47, 0, 56
    st_80DB0F8 58, 54, 53, 65, 148, 58, 0, 147
    st_80DB0F8 65, 61, 54, 66, 162, 3,  0, 106
    st_80DB0F8 60, 62, 55, 67, 162, 14, 0, 119
    st_80DB0F8 61, 63, 56, 68, 162, 25, 0, 74
    st_80DB0F8 62, 64, 57, 69, 162, 36, 0, 87
    st_80DB0F8 63, 65, 58, 70, 162, 47, 0, 57
    st_80DB0F8 64, 60, 59, 71, 162, 58, 0, 148
    st_80DB0F8 71, 67, 60, 72, 176, 3,  0, 107
    st_80DB0F8 66, 68, 61, 73, 176, 14, 0, 120
    st_80DB0F8 67, 69, 62, 74, 176, 25, 0, 75
    st_80DB0F8 68, 70, 63, 75, 176, 36, 0, 88
    st_80DB0F8 69, 71, 64, 76, 176, 47, 0, 48
    st_80DB0F8 70, 66, 65, 77, 176, 58, 0, 189
    st_80DB0F8 77, 73, 66, 78, 190, 3,  0, 108
    st_80DB0F8 72, 74, 67, 79, 190, 14, 0, 121
    st_80DB0F8 73, 75, 68, 80, 190, 25, 0, 76
    st_80DB0F8 74, 76, 69, 81, 190, 36, 0, 89
    st_80DB0F8 75, 77, 70, 82, 190, 47, 0, 58
    st_80DB0F8 76, 72, 71, 83, 190, 58, 0, 190
    st_80DB0F8 83, 79, 72, 6,  204, 3,  0, 109
    st_80DB0F8 78, 80, 73, 7,  204, 14, 0, 122
    st_80DB0F8 79, 81, 74, 8,  204, 25, 0, 77
    st_80DB0F8 80, 82, 75, 3,  204, 36, 0, 90
    st_80DB0F8 81, 83, 76, 4,  204, 47, 0, 133
    st_80DB0F8 82, 78, 77, 5,  204, 58, 0, 32
    st_80DB0F8 0,  0,  0,  0,  8,   3,  2, 265

	.global gUnknown_80DB4F4
gUnknown_80DB4F4: @ 80DB4F4
    .4byte sUnknown_80DB534
    .4byte sUnknown_80DB530
    .4byte sUnknown_80DB528
    .4byte sUnknown_80DB520
    .4byte sUnknown_80DB518
    .4byte sUnknown_80DB514
    .4byte sUnknown_80DB510

sUnknown_80DB510:
    .string "END\0"
    .align 2, 0

sUnknown_80DB514:
    .string "DEL\0"
    .align 2, 0

sUnknown_80DB518:
    .string "ＡＢＣ\0"
    .align 2, 0

sUnknown_80DB520:
    .string "カナ\0"
    .align 2, 0

sUnknown_80DB528:
    .string "かな\0"
    .align 2, 0

sUnknown_80DB530:
    .string "゜\0"
    .align 2, 0

sUnknown_80DB534:
    .string "゛\0"
    .align 2, 0

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
        .string "{COLOR_1 GREEN}OVR{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB5A4
gUnknown_80DB5A4: @ 80DB5A4
        .string "{COLOR_1 YELLOW}INS{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB5B0
gUnknown_80DB5B0: @ 80DB5B0
        .string "{COLOR_1}%c"
        .byte 0x81, 0x59
        .align 2,0

	.global gUnknown_80DB5B8
gUnknown_80DB5B8: @ 80DB5B8
        .string "{COLOR_1}%c%s\0"
        .align 2,0

	.global gUnknown_80DB5C0
gUnknown_80DB5C0: @ 80DB5C0
        .string "What is your name?\0"
        .align 2,0

	.global gUnknown_80DB5D4
gUnknown_80DB5D4: @ 80DB5D4
        .string "What is this Pokémon{APOSTROPHE}s nickname?\0"
        .align 2,0

	.global gUnknown_80DB5F8
gUnknown_80DB5F8: @ 80DB5F8
        .string "What is your partner{APOSTROPHE}s nickname?\0"
        .align 2,0

	.global gUnknown_80DB61C
gUnknown_80DB61C: @ 80DB61C
        .string "What is your team{APOSTROPHE}s name?\0"
        .align 2,0

	.global gUnknown_80DB638
gUnknown_80DB638: @ 80DB638
        .string "Please enter the password.\0"
        .align 2,0

	.global gUnknown_80DB654
gUnknown_80DB654: @ 80DB654
        .string "{COLOR_1 RED}%s{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB65C
gUnknown_80DB65C: @ 80DB65C
        .string "{COLOR_1 CYAN}%s{END_COLOR_TEXT_1}\0"
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
        .string "Is the name {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1} OK?\0"
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
        .string "{COLOR_1 RED}%s{END_COLOR_TEXT_1}\0"
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
        .string "{COLOR_1 RED}%s{END_COLOR_TEXT_1}\0"
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
        .string "{COLOR_1}"
        .byte 0x02
        .string "{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80DB9A0
gUnknown_80DB9A0: @ 80DB9A0
        .string "{COLOR_1 RED}%s{END_COLOR_TEXT_1}\0"
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
        .string "{CENTER_ALIGN}Who will learn the move\n"
        .string "{CENTER_ALIGN}{COLOR_1 CYAN}{ARG_POKEMON_7}{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80DB9E4
gUnknown_80DB9E4: @ 80DB9E4
        .string "{CENTER_ALIGN}{COLOR_1 CYAN_3}{ARG_POKEMON_8}{END_COLOR_TEXT_1} learned\n"
        .string "{CENTER_ALIGN}the move {COLOR_1 CYAN}{ARG_POKEMON_7}{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gUnknown_80DBA0C
gUnknown_80DBA0C: @ 80DBA0C
        .string "{CENTER_ALIGN}No one in the current team\n"
        .string "{CENTER_ALIGN}can learn this move. \0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0