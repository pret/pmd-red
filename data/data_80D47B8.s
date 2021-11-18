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
    .string "Ah~2c you wish to know how the bank\n"
    .string "operates... Very well...#P"
    .string " Zzz...\n"
    .string "If you~27re defeated in a dungeon~2c\n"
    .string "you~27ll lose all your money. Did you know?#P"
    .string " Purr...\n"
    .string "But~2c you~27ve nothing to fear if you leave\n"
    .string "your money with Felicity Bank...#P"
    .string " Meow... Even if you\n"
    .string "return defeated from a dungeon~2c your\n"
    .string "money will be safe with me...#P"
    .string " Sssnore...\n"
    .string "I assure you~2c my bank will keep your\n"
    .string "money safe...#P"
    .string " Zzz...\n"
    .string "Simple~2c isn~27t it...?\0"
    .align 2, 0

    .global gUnknown_80D4C14
gUnknown_80D4C14:
    .string " {POKE}... Purr...\n"
    .string "Very well~2c #C5$d0#R {POKE}.\n"
    .string "Here you are.\0"
    .align 2, 0

    .global gUnknown_80D4C50
gUnknown_80D4C50:
    .string " Fnarf? Hunh...?#P"
    .string " Purr... I so do apologize~2c\n"
    .string "but you couldn~27t possibly carry any more\n"
    .string "money with you...\0"
    .align 2, 0

    .global gUnknown_80D4CC0
gUnknown_80D4CC0:
    .string " Fnarf? Meow...?#P"
    .string " Purr...\n"
    .string "I so hate to disappoint~2c but you have no\n"
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
    .string "#C5$d0#R {POKE}... Very well...#W\n"
    .string "I will guard it jealously...\0"
    .align 2, 0

    .global gUnknown_80D4D8C
gUnknown_80D4D8C:
    .string " Fnarf? Purr...\n"
    .string "Meow! All this money...#W\n"
    .string "Our safe is about to burst...#P"
    .string " Purr...\n"
    .string "I am so sorry to say~2c but I can~27t accept\n"
    .string "any more of your money...\0"
    .align 2, 0

    .global gUnknown_80D4E28
gUnknown_80D4E28:
    .string " Sssnore... Hmm?#P"
    .string " Zzz...\n"
    .string "I~27m so sorry to say~2c but you appear not\n"
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
    .string "Your account contains #C5$d0#R {POKE}...\n"
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
    .string " Ah~2c you wish to know how\n"
    .string "the bank operates. Very well.#P"
    .string " If you are defeated\n"
    .string "in a dungeon~2c you~27ll lose all your money.\n"
    .string "Did you know that?#P"
    .string " But you can avoid that!#W\n"
    .string "You~27ve nothing to fear if you leave your\n"
    .string "money with Felicity Bank.#P"
    .string " Even if you return\n"
    .string "defeated from a dungeon~2c your money will\n"
    .string "be safe with me!#P"
    .string " I assure you~2c my bank\n"
    .string "will keep your money safe.#P"
    .string " Simple~2c isn~27t it?\0"
    .align 2, 0

    .global gUnknown_80D5158
gUnknown_80D5158:
    .string " Very well~2c #C5$d0#R {POKE}.\n"
    .string "Here you are.\0"
    .align 2, 0

    .global gUnknown_80D5184
gUnknown_80D5184:
    .string " Oh?#W I do so apologize~2c\n"
    .string "but you couldn~27t possibly carry any more\n"
    .string "money with you.\0"
    .align 2, 0

    .global gUnknown_80D51DC
gUnknown_80D51DC:
    .string " Oh?#W I so hate to disappoint~2c\n"
    .string "but you have no money saved with me.\0"
    .align 2, 0

    .global gUnknown_80D5224
gUnknown_80D5224:
    .string " How much will you\n"
    .string "withdraw?\0"
    .align 2, 0

    .global gUnknown_80D5244
gUnknown_80D5244:
    .string " #C5$d0#R {POKE}. Very well.#W\n"
    .string "I will guard it jealously.\0"
    .align 2, 0

    .global gUnknown_80D527C
gUnknown_80D527C:
    .string " Meow! All this money!#W\n"
    .string "Our safe is about to burst!#P"
    .string " I am so sorry to say~2c but\n"
    .string "I can~27t accept any more of your money!\0"
    .align 2, 0

    .global gUnknown_80D52F8
gUnknown_80D52F8:
    .string " Oh?#W I~27m so sorry to say~2c\n"
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
    .string "#C5$d0#R {POKE}.\n"
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
    .string "found in dungeons...#P"
    .string " Snarfle...\n"
    .string "Things in storage don~27t get lost...#P"
    .string " Zzz... Zzz...\n"
    .string "That~27s why...\n"
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
    .string "Can~27t store any more of that...\0"
    .align 2, 0

    .global gUnknown_80D55C0
gUnknown_80D55C0:
    .string " Zzz... Zzz...\n"
    .string "That #C4$i0#R...\n"
    .string "Can~27t store it...\0"
    .align 2, 0

    .global gUnknown_80D55F4
gUnknown_80D55F4:
    .string " Snarfle? Hunh...?#W\n"
    .string "Zzz... Your storage space... Empty...\0"
    .align 2, 0

    .global gUnknown_80D5630
gUnknown_80D5630:
    .string " Snarfle? Hunh...?#W\n"
    .string "Zzz...\n"
    .string "You don~27t have enough space...\0"
    .align 2, 0

    .global gUnknown_80D5670
gUnknown_80D5670:
    .string " Snarfle? Hunh...?#W\n"
    .string "Zzz...\n"
    .string "You don~27t have anything...?\0"
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
    .string "Oh... You want your #C4$i0#R...\n"
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
    .string "Yup~2c I did... Stored away...\0"
    .align 2, 0

    .global gUnknown_80D57F4
gUnknown_80D57F4:
    .string " Hunh~2c wha--? Storage...?\n"
    .string "I~27ll put away the things you chose...\n"
    .string "That OK?\0"
    .align 2, 0

    .global gUnknown_80D5844
gUnknown_80D5844:
    .string " Zzz... Store something?\n"
    .string "Gonna put #C4$i0#R in storage...\n"
    .string "OK?\0"
    .align 2, 0

    .global gUnknown_80D5884
gUnknown_80D5884:
    .string " Do you... Snork...\n"
    .string "Store anything else?\0"
    .align 2, 0

    .global gUnknown_80D58B0
gUnknown_80D58B0:
    .string " Hunh~2c wha--? Store what...?\n"
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
    .string "Hello~2c there...\n"
    .string "$m6 Storage...\0"
    .align 2, 0

    .global gUnknown_80D5984
gUnknown_80D5984:
    .string " I can store items that you\n"
    .string "found in dungeons~2c or that you\n"
    .string "bought from shops.#P"
    .string " If you faint in\n"
    .string "a dungeon~2c your items will be lost...#W\n"
    .string "But what~27s in storage will be safe.#P"
    .string " I keep guard over the\n"
    .string "storage space~2c so anything you leave\n"
    .string "with me won~27t ever disappear!#P"
    .string " If you have any items that\n"
    .string "you can~27t bear to lose~2c be sure to leave\n"
    .string "them with me!\0"
    .align 2, 0

    .global gUnknown_80D5AF0
gUnknown_80D5AF0:
    .string " Sorry~2c dear.\n"
    .string "I~27ve run out of storage space.\0"
    .align 2, 0

    .global gUnknown_80D5B24
gUnknown_80D5B24:
    .string " Sorry~2c dear.\n"
    .string "I can~27t take any more of that item.\0"
    .align 2, 0

    .global gUnknown_80D5B5C
gUnknown_80D5B5C:
    .string " Oh~2c dear~2c sorry.#W\n"
    .string "That #C4$i0#R is an item you\n"
    .string "can~27t put in storage.\0"
    .align 2, 0

    .global gUnknown_80D5BAC
gUnknown_80D5BAC:
    .string " Oh?\n"
    .string "You don~27t have anything stored~2c dear.\0"
    .align 2, 0

    .global gUnknown_80D5BDC
gUnknown_80D5BDC:
    .string " Oh? You don~27t have the room\n"
    .string "to carry any more items~2c dear.\0"
    .align 2, 0

    .global gUnknown_80D5C1C
gUnknown_80D5C1C:
    .string " Oh?\n"
    .string "You don~27t seem to have anything?\0"
    .align 2, 0

    .global gUnknown_80D5C44
gUnknown_80D5C44:
    .string " There you go!\n"
    .string "Just like you asked~2c sweetie!\0"
    .align 2, 0

    .global gUnknown_80D5C74
gUnknown_80D5C74:
    .string " I~27ll take the items you\n"
    .string "chose out of storage. OK?\0"
    .align 2, 0

    .global gUnknown_80D5CAC
gUnknown_80D5CAC:
    .string " Fine~2c I~27ll take your\n"
    .string "#C4$i0#R out of storage. OK?\0"
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
    .string " OK~2c stored away!\n"
    .string "You can count on me~2c honey.\0"
    .align 2, 0

    .global gUnknown_80D5D8C
gUnknown_80D5D8C:
    .string " I~27ll put the items you chose\n"
    .string "in storage. OK?\0"
    .align 2, 0

    .global gUnknown_80D5DBC
gUnknown_80D5DBC:
    .string " I~27ll put your\n"
    .string "#C4$i0#R in storage. OK?\0"
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
    .string " Thank you~2c sweetie.\n"
    .string "Come again!\0"
    .align 2, 0

    .global gUnknown_80D5E84
gUnknown_80D5E84:
    .string " Anything else~2c dear?\0"
    .align 2, 0

    .global gUnknown_80D5E9C
gUnknown_80D5E9C:
    .string " Hello~2c there!\n"
    .string "Welcome to $m6 Storage.\0"
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
    .string "Wonder Orbs are convenient...#P"
    .string " Zzzzzz...\n"
    .string "They disappear after one use...#P"
    .string " Zzz... And moves...\n"
    .string "They are ultimate...#P"
    .string " Zzz... Eep...\n"
    .string "Learn moves with Technical Machines...#P"
    .string " Zzz...\n"
    .string "My good wares...\n"
    .string "Come buy... Reep...\0"
    .align 2, 0

    .global gUnknown_80D6128
gUnknown_80D6128:
    .string " Zzz... Eep? No~2c no...#W\n"
    .string "You cannot hold any more money...\0"
    .align 2, 0

    .global gUnknown_80D6168
gUnknown_80D6168:
    .string " Zzz... Hunh? Wha--? Whoa!#W\n"
    .string "I... I can~27t accept anything like that!\0"
    .align 2, 0

    .global gUnknown_80D61B0
gUnknown_80D61B0:
    .string " Reep...? Eep!#W\n"
    .string "Not enough money!\0"
    .align 2, 0

    .global gUnknown_80D61D4
gUnknown_80D61D4:
    .string " Zzz... Uh-oh...#W\n"
    .string "All gone!\n"
    .string "I am sold out...\0"
    .align 2, 0

    .global gUnknown_80D6204
gUnknown_80D6204:
    .string " Zzz... Hunh? Oh...#W\n"
    .string "Reep... No room... Reep...\n"
    .string "No room for my wares...\0"
    .align 2, 0

    .global gUnknown_80D6250
gUnknown_80D6250:
    .string " Zzzzzz... Oh?#W\n"
    .string "You~27ve got nothing...\0"
    .align 2, 0

    .global gUnknown_80D627C
gUnknown_80D627C:
    .string " Zzz... Oh...?#W\n"
    .string "You have nothing to sell...\n"
    .string "Hunh?\0"
    .align 2, 0

    .global gUnknown_80D62B0
gUnknown_80D62B0:
    .string " Eep...? Zzz...\n"
    .string "You have too much money!#P"
    .string " Zzz... Eh?\n"
    .string "You can~27t hold any more money...\0"
    .align 2, 0

    .global gUnknown_80D630C
gUnknown_80D630C:
    .string " Reep eep! Oh?#W\n"
    .string "Eep...?\n"
    .string "You have no money?\0"
    .align 2, 0

    .global gUnknown_80D6338
gUnknown_80D6338:
    .string " ...#WZzz...\n"
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
    .string " Zzz... Reep~2c what...?\n"
    .string "For all that I can buy~2c I will pay\n"
    .string "#C5$d0#R {POKE}... OK?\0"
    .align 2, 0

    .global gUnknown_80D63E8
gUnknown_80D63E8:
    .string " Zzzzzz... Zzzzzz...?\n"
    .string "#C4$i0#R?\n"
    .string "Is #C5$d0#R {POKE} OK?\0"
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
    .string "#C4$i0#R is #C5$d0#R {POKE}...\n"
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
    .string " Wonder Orbs are very~2c\n"
    .string "very convenient〜♪#P"
    .string " However~2c they disappear\n"
    .string "after one use...#W\n"
    .string "But they are useful in a pinch!#P"
    .string " Use them cleverly~2c and your\n"
    .string "adventures will be made much easier〜♪#P"
    .string " And moves...#W\n"
    .string "They are the ultimate power!#P"
    .string " Smash rocks!#W Fly!#W\n"
    .string "There are many kinds of moves~2c all of\n"
    .string "them dynamic~2c yet elegant!#P"
    .string " There are even moves of\n"
    .string "obscure rarity...#W\n"
    .string "Simply gorgeous~2c they are!#P"
    .string " Now~2c we have these moves!#W\n"
    .string "They can be learned using our Technical\n"
    .string "Machines~2c or TMs for short!#P"
    .string " You see?\n"
    .string "Isn~27t it exciting? Even dreamy?#P"
    .string " Why~2c it gets me so excited~2c\n"
    .string "my color has turned a rosy tint!#P"
    .string " I do hope you will shop\n"
    .string "with us--me and my brother next to\n"
    .string "me!\0"
    .align 2, 0

    .global gUnknown_80D6818
gUnknown_80D6818:
    .string " Oh~2c no~2c no!#W\n"
    .string "My friend~2c you cannot add to your money!\n"
    .string "I cannot do this.\0"
    .align 2, 0

    .global gUnknown_80D6868
gUnknown_80D6868:
    .string " Whoa~2c whoa!#W\n"
    .string "I... I can~27t accept anything like that!\0"
    .align 2, 0

    .global gUnknown_80D68A4
gUnknown_80D68A4:
    .string " Eep! Oh~2c dear!#W\n"
    .string "You~27re short on money~2c my friend!\0"
    .align 2, 0

    .global gUnknown_80D68E0
gUnknown_80D68E0:
    .string " Oh? Uh-oh!#W\n"
    .string "My shelves are bare of wares!#P"
    .string " I am completely sold out~2c\n"
    .string "my friend!\0"
    .align 2, 0

    .global gUnknown_80D6938
gUnknown_80D6938:
    .string " Oh~2c dear me!#W\n"
    .string "My friend~2c you~27ve run out of space for\n"
    .string "my wares!\0"
    .align 2, 0

    .global gUnknown_80D6980
gUnknown_80D6980:
    .string " Oh?#W\n"
    .string "My friend~2c you seem to have nothing?\0"
    .align 2, 0

    .global gUnknown_80D69B0
gUnknown_80D69B0:
    .string " Oh~2c oh~2c oh?#W\n"
    .string "My friend~2c you seem to not have anything\n"
    .string "that you can sell?\0"
    .align 2, 0

    .global gUnknown_80D6A04
gUnknown_80D6A04:
    .string " Oh~2c my~2c my!\n"
    .string "My friend~2c you have too much money!#P"
    .string " You can~27t carry any more\n"
    .string "money than you have now.\0"
    .align 2, 0

    .global gUnknown_80D6A74
gUnknown_80D6A74:
    .string " Oh?#W\n"
    .string "My friend~2c you seem not to have\n"
    .string "enough money?\0"
    .align 2, 0

    .global gUnknown_80D6AAC
gUnknown_80D6AAC:
    .string " ...#WI am all out of wares...\n"
    .string "I am so sorry~2c my friend...#P"
    .string " Tomorrow!\n"
    .string "Tomorrow I shall have more wares!\0"
    .align 2, 0

    .global gUnknown_80D6B18
gUnknown_80D6B18:
    .string " Fine~2c fine~2c we have a deal!\n"
    .string "Thank you so much〜♪ \0"
    .align 2, 0

    .global gUnknown_80D6B50
gUnknown_80D6B50:
    .string " For all that I can buy~2c I can\n"
    .string "offer you #C5$d0#R {POKE}.\n"
    .string "Is that acceptable?\0"
    .align 2, 0

    .global gUnknown_80D6BA0
gUnknown_80D6BA0:
    .string " #C4$i0#R~2c you say?\n"
    .string "For that~2c I can offer #C5$d0#R {POKE}.\n"
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
    .string " #C4$i0#R~2c you say?\n"
    .string "That will be #C5$d0#R {POKE}.\n"
    .string "Is that acceptable?\0"
    .align 2, 0

    .global gUnknown_80D6C90
gUnknown_80D6C90:
    .string " Do you wish to purchase\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D6CB8
gUnknown_80D6CB8:
    .string " Ah~2c very well!\n"
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
    .string "I sell items...#P"
    .string " Items... Meep meep...\n"
    .string "Are useful in dungeons...#P"
    .string " Use... Zzz... Huh...?\n"
    .string "Your imagination...and be clever...\n"
    .string "With them...\0"
    .align 2, 0

    .global gUnknown_80D6E30
gUnknown_80D6E30:
    .string " Zzz... Hunh~2c what...?#W\n"
    .string "Zzz... You can~27t hold any more money...\0"
    .align 2, 0

    .global gUnknown_80D6E78
gUnknown_80D6E78:
    .string " Zzz... Whoa...#W\n"
    .string "I... I can~27t take that!\0"
    .align 2, 0

    .global gUnknown_80D6EA4
gUnknown_80D6EA4:
    .string " Zzz... Huh~2c my...!#W\n"
    .string "Meep... Meep...\n"
    .string "You don~27t have enough money!\0"
    .align 2, 0

    .global gUnknown_80D6EEC
gUnknown_80D6EEC:
    .string " Zzz... Uh-oh?!#W\n"
    .string "Eep!\n"
    .string "Sold out! All gone!\0"
    .align 2, 0

    .global gUnknown_80D6F18
gUnknown_80D6F18:
    .string " Zzz... Oh~2c my!#W\n"
    .string "Meep... You have no space...\0"
    .align 2, 0

    .global gUnknown_80D6F4C
gUnknown_80D6F4C:
    .string " Zzz... Eep...?#W\n"
    .string "Meep... You don~27t seem to have\n"
    .string "anything...?\0"
    .align 2, 0

    .global gUnknown_80D6F8C
gUnknown_80D6F8C:
    .string " Zzz... Huh?#W\n"
    .string "Meep meep...\n"
    .string "You don~27t seem to have anything to sell?\0"
    .align 2, 0

    .global gUnknown_80D6FD4
gUnknown_80D6FD4:
    .string " Zzz... Oh~2c my!\n"
    .string "You have so much money...!#P"
    .string " Zzz... Meep...\n"
    .string "You can~27t carry any more money...\0"
    .align 2, 0

    .global gUnknown_80D7038
gUnknown_80D7038:
    .string " Hunh?#W\n"
    .string "Eep...?\n"
    .string "You don~27t have money?\0"
    .align 2, 0

    .global gUnknown_80D7064
gUnknown_80D7064:
    .string " ...#W ZZZ!\n"
    .string "I~27m sold out... Forgive me...\0"
    .align 2, 0

    .global gUnknown_80D7090
gUnknown_80D7090:
    .string " Done... Meep! Deal!\n"
    .string "Thank you...\0"
    .align 2, 0

    .global gUnknown_80D70B4
gUnknown_80D70B4:
    .string " Zzzzzz... Zzzzzz...?\n"
    .string "I can pay you #C5$d0#R {POKE}\n"
    .string "for everything I can buy... OK?\0"
    .align 2, 0

    .global gUnknown_80D7108
gUnknown_80D7108:
    .string " Zzzzzz... Zzzzzz...?\n"
    .string "Selling that #C4$i0#R...?\n"
    .string "How about #C5$d0#R {POKE}?\0"
    .align 2, 0

    .global gUnknown_80D7154
gUnknown_80D7154:
    .string " Zzz... Meep...\n"
    .string "Going to sell anything else?\0"
    .align 2, 0

    .global gUnknown_80D7184
gUnknown_80D7184:
    .string " Zzz... Zzz...?\n"
    .string "You~27re selling what...?\0"
    .align 2, 0

    .global gUnknown_80D71B0
gUnknown_80D71B0:
    .string " Eep! Wah...?\n"
    .string "Thank you...\0"
    .align 2, 0

    .global gUnknown_80D71CC
gUnknown_80D71CC:
    .string " Zzz... Meep meep...\n"
    .string "#C4$i0#R...?\n"
    .string "#C5$d0#R {POKE}~2c OK?\0"
    .align 2, 0

    .global gUnknown_80D7204
gUnknown_80D7204:
    .string " Buy? Huh~2c eep?\n"
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
    .string " We~2c the $m6\n"
    .string "Brothers~2c have a passion for selling\n"
    .string "items.#P"
    .string " Items are useful for your\n"
    .string "dungeon adventures.#P"
    .string " Use your imagination and\n"
    .string "discover innovative uses~2c please.#P"
    .string " Ah~2c yes.\n"
    .string "If my shop sells out...#P"
    .string " New merchandise will\n"
    .string "arrive the following day.#P"
    .string " Until then~2c please go to\n"
    .string "a dungeon and spend some time.\n"
    .string "Please visit on your return〜♪#P"
    .string " Ah~2c yes. The $m6\n"
    .string "Shop is a nationwide chain.#P"
    .string " There are shops even in\n"
    .string "dungeons.\n"
    .string "Please do visit〜♪ \0"
    .align 2, 0

    .global gUnknown_80D7480
gUnknown_80D7480:
    .string " Oh~2c my!#W\n"
    .string "You can~27t add any more to your money.\n"
    .string "I can~27t complete this deal~2c sorry.\0"
    .align 2, 0

    .global gUnknown_80D74DC
gUnknown_80D74DC:
    .string " Oh~2c whoa~2c whoa!#W\n"
    .string "I... I couldn~27t possibly take that from you!\0"
    .align 2, 0

    .global gUnknown_80D7524
gUnknown_80D7524:
    .string " Oh~2c my!#W\n"
    .string "Sorry~2c but you don~27t have enough money!\0"
    .align 2, 0

    .global gUnknown_80D7560
gUnknown_80D7560:
    .string " Uh-oh?!#W\n"
    .string "That~27s it! No more merchandise!#P"
    .string " I~27m completely sold out!\0"
    .align 2, 0

    .global gUnknown_80D75AC
gUnknown_80D75AC:
    .string " Oh~2c my!#W\n"
    .string "You have no space for any more items!\0"
    .align 2, 0

    .global gUnknown_80D75E0
gUnknown_80D75E0:
    .string " Oh? Oh?#W\n"
    .string "You don~27t seem to have anything?\0"
    .align 2, 0

    .global gUnknown_80D7610
gUnknown_80D7610:
    .string " Oh? Oh?#W\n"
    .string "You seem to have nothing to sell?\0"
    .align 2, 0

    .global gUnknown_80D7640
gUnknown_80D7640:
    .string " Oh~2c my goodness!\n"
    .string "You~27re overflowing with money!#P"
    .string " You couldn~27t possibly carry\n"
    .string "any more money! \0"
    .align 2, 0

    .global gUnknown_80D76A8
gUnknown_80D76A8:
    .string " Huh?#W\n"
    .string "You don~27t seem to have the money?\0"
    .align 2, 0

    .global gUnknown_80D76D4
gUnknown_80D76D4:
    .string " ...#WI~27m sold out...\n"
    .string "Please~2c forgive me.#P"
    .string " I will have new merchandise\n"
    .string "for you tomorrow~2c I swear!\0"
    .align 2, 0

    .global gUnknown_80D7740
gUnknown_80D7740:
    .string " Good! Done deal!\n"
    .string "Thank you so much〜♪ \0"
    .align 2, 0

    .global gUnknown_80D776C
gUnknown_80D776C:
    .string " For everything I can buy~2c\n"
    .string "I can offer #C5$d0#R {POKE}.\n"
    .string "Is that acceptable to you?\0"
    .align 2, 0

    .global gUnknown_80D77C0
gUnknown_80D77C0:
    .string " #C4$i0#R?\n"
    .string "I can offer you #C5$d0#R {POKE}.\n"
    .string "Will you sell it for that price?\0"
    .align 2, 0

    .global gUnknown_80D780C
gUnknown_80D780C:
    .string " Do you wish to sell\n"
    .string "anything else?\0"
    .align 2, 0

    .global gUnknown_80D7830
gUnknown_80D7830:
    .string " Ah~2c very well!\n"
    .string "What do you wish to sell?\0"
    .align 2, 0

    .global gUnknown_80D785C
gUnknown_80D785C:
    .string " Very well! Thank you〜♪\n"
    .string "It is yours to take!\0"
    .align 2, 0

    .global gUnknown_80D788C
gUnknown_80D788C:
    .string " #C4$i0#R?\n"
    .string "That will be #C5$d0#R {POKE}.\n"
    .string "Is that to your liking?\0"
    .align 2, 0

    .global gUnknown_80D78CC
gUnknown_80D78CC:
    .string " Do you wish to buy\n"
    .string "anything else today?\0"
    .align 2, 0

    .global gUnknown_80D78F8
gUnknown_80D78F8:
    .string " Ah~2c very well!\n"
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
    .string "Welcome to the $m6 Shop〜♪ \0"
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
    .string "Want more friends?#P"
    .string " Zzz... Kwoo...\n"
    .string "You need Friend Areas for friends...#P"
    .string " Zzz... Zzz...\n"
    .string "A Pokémon becomes your pal when it~27s in\n"
    .string "the right Friend Area...#P"
    .string " Zzz... Dwee...\n"
    .string "That~27s why you should get more Friend\n"
    .string "Areas...#P"
    .string " Zzz... Pokémon can only\n"
    .string "live in the right Friend Area for\n"
    .string "their species...#P"
    .string " Kwoo... Sssnore...\n"
    .string "See what Pokémon can live there by\n"
    .string "checking #C6Info#R...#P"
    .string " Zzz...\n"
    .string "I don~27t sell some Friend Areas...#P"
    .string " Kwoo...\n"
    .string "Some rescue missions reward you with\n"
    .string "Friend Areas...#P"
    .string " Zzz... Dwee...\n"
    .string "Check the Pelipper Post Office~27s Bulletin\n"
    .string "Board or your Mailbox for missions...\0"
    .align 2, 0

    .global gUnknown_80D7C94
gUnknown_80D7C94:
    .string " Sssnore...\n"
    .string "#C4$h#R...?\n"
    .string "I can~27t get that Friend Area...#P"
    .string " Zzz... Zzz...\n"
    .string "Sorry...\0"
    .align 2, 0

    .global gUnknown_80D7CE8
gUnknown_80D7CE8:
    .string " Zzz... Hunh...?\n"
    .string "#C4$h#R...?\n"
    .string "I don~27t know... I~27ll check...#P"
    .string " Sssnore...\n"
    .string "I~27ll have it for sale...\n"
    .string "When I find out...\0"
    .align 2, 0

    .global gUnknown_80D7D64
gUnknown_80D7D64:
    .string " Sssnore...\n"
    .string "You can already go...\n"
    .string "Friend Area #C4$h#R...\0"
    .align 2, 0

    .global gUnknown_80D7DA0
gUnknown_80D7DA0:
    .string " Dwee... Kwoo...\n"
    .string "#C5$m0#R~27s Friend Area...\n"
    .string "Zzz... #C4$h#R...\0"
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
    .string " Zzz... Dwee...? Oops?#W\n"
    .string "Not enough money?\0"
    .align 2, 0

    .global gUnknown_80D7E58
gUnknown_80D7E58:
    .string " Zzz... Hunh?#W\n"
    .string "Sssnore... Sorry...\n"
    .string "Fresh out of Friend Areas...\0"
    .align 2, 0

    .global gUnknown_80D7E9C
gUnknown_80D7E9C:
    .string " Hunh...?#W\n"
    .string "You don~27t have any money...\n"
    .string "Zzzzzz...\0"
    .align 2, 0

    .global gUnknown_80D7ED0
gUnknown_80D7ED0:
    .string " Zzz... Zzz?#W\n"
    .string "Hunh...?\n"
    .string "You can~27t add to your Friend Areas...\0"
    .align 2, 0

    .global gUnknown_80D7F10
gUnknown_80D7F10:
    .string " Grats... Zzz...#W\n"
    .string "You can go to #C4$h#R...#P"
    .string " Dwee... Sssnore...\n"
    .string "Make friends with Pokémon in...\n"
    .string "#C4$h#R...\0"
    .align 2, 0

    .global gUnknown_80D7F7C
gUnknown_80D7F7C:
    .string " Zzz... Dwee... Gotcha...#W\n"
    .string "Zzz... Let~27s do it...#P"
    .string " Sssnore♪ Sssnore♪\n"
    .string "$m6〜♪ $m6〜♪\n"
    .string "Let~27s be friends...#P"
    .string " Kwoo!\n"
    .string "Taaaaaaah!\0"
    .align 2, 0

    .global gUnknown_80D8000
gUnknown_80D8000:
    .string " Kwoo? #C4$h#R?\n"
    .string "That~27s #C5$d0#R {POKE}...\n"
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
    .string "Friends~2c friend...\0"
    .align 2, 0

    .global gUnknown_80D80B0
gUnknown_80D80B0:
    .string " Anything? Kwoo...\n"
    .string "Anything else?\0"
    .align 2, 0

    .global gUnknown_80D80D4
gUnknown_80D80D4:
    .string " Friends... Zzz...\n"
    .string "Welcome to the $m6 Club...\0"
    .align 2, 0

    .global gUnknown_80D8104
gUnknown_80D8104:
    .string " Would you like to get more\n"
    .string "friends...#W\n"
    .string "...More members for your team?#P"
    .string " To add new friends~2c what\n"
    .string "you need are Friend Areas.#P"
    .string " A Pokémon can join your\n"
    .string "rescue team only after it settles in\n"
    .string "the right Friend Area.#P"
    .string " So~2c if you want to recruit\n"
    .string "new members~2c you should add to your\n"
    .string "Friend Areas.#P"
    .string " Oh~2c yes~2c Pokémon can\n"
    .string "only live in the right Friend Area for\n"
    .string "their species.#P"
    .string " If you~27re buying a Friend\n"
    .string "Area~2c you should confirm what Pokémon\n"
    .string "can live there by checking #C6Info#R.#P"
    .string " Also~2c there are some Friend\n"
    .string "Areas that I don~27t sell.#P"
    .string " I think there are some\n"
    .string "rescue missions that give you access\n"
    .string "to Friend Areas~2c too.#P"
    .string " You should check the\n"
    .string "Pelipper Post Office~27s Bulletin Board or\n"
    .string "your Mailbox for rescue requests.#P"
    .string " You know~2c it makes me\n"
    .string "delighted when you make new friends!\0"
    .align 2, 0

    .global gUnknown_80D8420
gUnknown_80D8420:
    .string " #C4$h#R?\n"
    .string "I can~27t get that Friend Area for you.#W\n"
    .string "I~27m really sorry.\0"
    .align 2, 0

    .global gUnknown_80D8468
gUnknown_80D8468:
    .string " #C4$h#R?\n"
    .string "I don~27t know much about it at all.#W\n"
    .string "I~27ll check up on it.#P"
    .string " I~27ll add it to the Friend\n"
    .string "Areas you can buy when I find out more.\0"
    .align 2, 0

    .global gUnknown_80D84F8
gUnknown_80D84F8:
    .string " You can already go to the\n"
    .string "Friend Area #C4$h#R.\0"
    .align 2, 0

    .global gUnknown_80D8528
gUnknown_80D8528:
    .string " #C5$m0#R~27s Friend Area\n"
    .string "is #C4$h#R.\0"
    .align 2, 0

    .global gUnknown_80D8550
gUnknown_80D8550:
    .string " Is there another Pokémon\n"
    .string "you~27d like to check?\0"
    .align 2, 0

    .global gUnknown_80D8584
gUnknown_80D8584:
    .string " Which Pokémon would you\n"
    .string "like to check?\0"
    .align 2, 0

    .global gUnknown_80D85AC
gUnknown_80D85AC:
    .string " Oops?#W\n"
    .string "It doesn~27t look like you have enough\n"
    .string "money!\0"
    .align 2, 0

    .global gUnknown_80D85E4
gUnknown_80D85E4:
    .string " Oops?#W\n"
    .string "Oh~2c too bad.#W\n"
    .string "I~27m fresh out of Friend Areas.\0"
    .align 2, 0

    .global gUnknown_80D8620
gUnknown_80D8620:
    .string " Um?#W\n"
    .string "You don~27t have any money.\0"
    .align 2, 0

    .global gUnknown_80D8644
gUnknown_80D8644:
    .string " Oops!#W\n"
    .string "You can~27t add to your Friend Areas.\0"
    .align 2, 0

    .global gUnknown_80D8674
gUnknown_80D8674:
    .string " Congratulations!#W\n"
    .string "You can go to #C4$h#R now!#P"
    .string " You can recruit\n"
    .string "Pokémon that live in the Friend Area\n"
    .string "#C4$h#R.\0"
    .align 2, 0

    .global gUnknown_80D86E4
gUnknown_80D86E4:
    .string " Gotcha! Let~27s do it!#W\n"
    .string "$m6〜♪ $m6〜♪#W\n"
    .string "Let~27s be friends... Yoomtaaaaaaah!\0"
    .align 2, 0

    .global gUnknown_80D8738
gUnknown_80D8738:
    .string " #C4$h#R?\n"
    .string "That will be #C5$d0#R {POKE}.\n"
    .string "Is that OK?\0"
    .align 2, 0

    .global gUnknown_80D876C
gUnknown_80D876C:
    .string " Would you like to add\n"
    .string "other Friend Areas?\0"
    .align 2, 0

    .global gUnknown_80D8798
gUnknown_80D8798:
    .string " You~27d like to add to your\n"
    .string "Friend Areas?\n"
    .string "Which one would you like?\0"
    .align 2, 0

    .global gUnknown_80D87E0
gUnknown_80D87E0:
    .string " Thank you! Come again!\n"
    .string "We~27re all friends~2c friend!\0"
    .align 2, 0

    .global gUnknown_80D8818
gUnknown_80D8818:
    .string " Anything else I can do for\n"
    .string "you?\0"
    .align 2, 0

    .global gUnknown_80D883C
gUnknown_80D883C:
    .string " Friends are my treasures!\n"
    .string "Welcome to the $m6 Club--\n"
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
    .string "I~27d go broke if it weren~27t for those\n"
    .string "forgetful Pokémon...#P"
    .string " Zzz... Gwaaah...\n"
    .string "Especially that #C5$m4#R...\n"
    .string "It seems to be forgetful...#P"
    .string " Sssnore...\n"
    .string "I hope it forgets more moves...\n"
    .string "So it needs to see me...#P"
    .string " Zzz... Mumble...\n"
    .string "But we decided to get rid of that\n"
    .string "#C5$m4#R...#P"
    .string " Gwaaaah... Gweh...\n"
    .string "#C5$m4#R won~27t be coming around\n"
    .string "anymore... \0"
    .align 2, 0

    .global gUnknown_80D8AB8
gUnknown_80D8AB8:
    .string " Zzznork...#W\n"
    .string "Link moves to use them all in\n"
    .string "one turn...#P"
    .string " Zzz... Fnurf...?\n"
    .string "Linked moves...\n"
    .string "Top one goes first...#P"
    .string " Zzz... Hah...?\n"
    .string "Delink moves to break links...#P"
    .string " Zzzzz... Fwaaah...\n"
    .string "Change order of moves with {R_BUTTON}...\n"
    .string "And up and down on {DPAD}...#P"
    .string " Gwaaah... Gweh...\n"
    .string "Make your own links...\0"
    .align 2, 0

    .global gUnknown_80D8BD4
gUnknown_80D8BD4:
    .string " Zzz... Zzz...\n"
    .string "A set move can be used...\n"
    .string "Press {L_BUTTON} and {A_BUTTON}...#P"
    .string " Sssnort... Set the move...#W\n"
    .string "Press {L_BUTTON} and {A_BUTTON}...#W Use move!#W\n"
    .string "Convenient...#P"
    .string " Sssnore...\n"
    .string "Switch the set move in a dungeon~2c too...\0"
    .align 2, 0

    .global gUnknown_80D8C98
gUnknown_80D8C98:
    .string " Zzznork... Fnurfle?\n"
    .string "What do you want to know?\0"
    .align 2, 0

    .global gUnknown_80D8CC8
gUnknown_80D8CC8:
    .string " Fgwaaah...\n"
    .string "Here goes...#P"
    .string " Zzznort...\n"
    .string "Gggggggg...#W Pwah!#P"
    .string " Fwaaah hah!\n"
    .string "There...#P"
    .string " Zzz... Mutter...\n"
    .string "#C5$m5#R forgot...\n"
    .string "#C4$m1#R and moves linked to it...\0"
    .align 2, 0

    .global gUnknown_80D8D64
gUnknown_80D8D64:
    .string " Fgwaaah...\n"
    .string "Here goes...#P"
    .string " Zzznort...\n"
    .string "Gggggggg...#W Pwah!#P"
    .string " Fwaaah hah!\n"
    .string "There...#P"
    .string " Zzz... Mumble...\n"
    .string "#C5$m5#R forgot...\n"
    .string "#C4$m1#R...\0"
    .align 2, 0

    .global gUnknown_80D8DE8
gUnknown_80D8DE8:
    .string " Zzz... Fwaah? Forget...?\n"
    .string "#C4$m1#R and any moves\n"
    .string "linked to it?\0"
    .align 2, 0

    .global gUnknown_80D8E28
gUnknown_80D8E28:
    .string " Zzz... Forget...?\n"
    .string "#C4$m1#R?\0"
    .align 2, 0

    .global gUnknown_80D8E48
gUnknown_80D8E48:
    .string " Zzznork...? Hunh?\n"
    .string "You~27re a special Pokémon...#P"
    .string " Mumble...\n"
    .string "I can~27t help you...\0"
    .align 2, 0

    .global gUnknown_80D8E9C
gUnknown_80D8E9C:
    .string " Zzz... Fwaah?\n"
    .string "No moves to remember...\0"
    .align 2, 0

    .global gUnknown_80D8EC4
gUnknown_80D8EC4:
    .string " Fgwaaah...\n"
    .string "Here goes...#P"
    .string " Zzznort...\n"
    .string "Gggggggg...#W Pwah! Gulpin!#P"
    .string " Fwaaah hah!\n"
    .string "There...#P"
    .string " Zzz... Mumble...\n"
    .string "#CM$m5#R~27s OK...#P"
    .string " Sssnork... Forgotten...\n"
    .string "#C4$m1#R and moves linked to it...\n"
    .string "Remembered #C5$m0#R...\0"
    .align 2, 0

    .global gUnknown_80D8F98
gUnknown_80D8F98:
    .string " Fgwaah...\n"
    .string "Here goes...#P"
    .string " Zzznort...\n"
    .string "Gggggggg...#W Pwah! Gulpin!#P"
    .string " Fwaah hah!\n"
    .string "There...#P"
    .string " Zzz... Zzz... #CM$m5#R\n"
    .string "forgot #C4$m1#R...\n"
    .string "Remembered #C5$m0#R...\0"
    .align 2, 0

    .global gUnknown_80D9034
gUnknown_80D9034:
    .string " Zzz? Fnurf? \n"
    .string "Forget #C4$m1#R...and moves linked\n"
    .string "to it? Remember #C5$m0#R?\0"
    .align 2, 0

    .global gUnknown_80D9080
gUnknown_80D9080:
    .string " Zzznort... Grumble...\n"
    .string "Forget #C4$m1#R?\n"
    .string "Remember #C5$m0#R?\0"
    .align 2, 0

    .global gUnknown_80D90BC
gUnknown_80D90BC:
    .string " Zzzznort... Move...?\n"
    .string "Remember #C5$m0#R?#P"
    .string " Fwaah...\n"
    .string "Gggggggggggg...#W Gulpin!#P"
    .string " Fgwaah...\n"
    .string "There...#P"
    .string " Zzz... Zzz...\n"
    .string "#CM$m5#R remembered...\n"
    .string "Hunh? That move~2c #C5$m0#R...\0"
    .align 2, 0

    .global gUnknown_80D9168
gUnknown_80D9168:
    .string " Zzz... Fgwah...?\n"
    .string "Remember what? What move?\0"
    .align 2, 0

    .global gUnknown_80D9194
gUnknown_80D9194:
    .string " Gwaah... Gwaah...\n"
    .string "Who~27s gonna link moves?\0"
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
    .string "Can~27t forget that...\0"
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
    .string "a move~2c but you wanted it back?#W\n"
    .string "Ever face that situation?#P"
    .string " I can help!#W\n"
    .string "Come to me~2c and I can make you instantly\n"
    .string "remember forgotten moves!#P"
    .string " I...#W\n"
    .string "Well~2c when Pokémon remember...#W\n"
    .string "I love seeing that instant!#P"
    .string " That look of enlightenment!#W\n"
    .string "That amazed look of pleasure!#P"
    .string " I run this business because\n"
    .string "I live to see that moment!\0"
    .align 2, 0

    .global gUnknown_80D9498
gUnknown_80D9498:
    .string " When moves are linked...#W\n"
    .string "Two or more moves can be used one after\n"
    .string "another in one turn!#P"
    .string " For example~2c if the moves\n"
    .string "#C5Scratch#R and #C5Growl#R are\n"
    .string "linked...#P"
    .string " Both #C5Scratch#R and #C5Growl#R are\n"
    .string "used in one turn!#W\n"
    .string "See? Amazing~2c huh?#P"
    .string " Using links~2c heheh...#W\n"
    .string "Well~2c depending on the moves you link~2c\n"
    .string "you can get incredible results!#P"
    .string " Oh~2c yes.\n"
    .string "When moves are linked~2c they are used in\n"
    .string "sequence from the top one first.#P"
    .string " You can also separate linked\n"
    .string "moves by selecting the Delink command.#P"
    .string " The sequence of moves can\n"
    .string "be changed by pressing {R_BUTTON}~2c\n"
    .string "then pressing up or down on {DPAD}.#P"
    .string " Try to innovate with links.#W\n"
    .string "Try creating links of your very own!\0"
    .align 2, 0

    .global gUnknown_80D972C
gUnknown_80D972C:
    .string " When you~27re in a dungeon\n"
    .string "and you~27re about to use a move...#W\n"
    .string "Isn~27t it a pain to open a window each time?#P"
    .string " You can avoid that!#W\n"
    .string "You can just conveniently ~93Set~94\n"
    .string "a move for instant use!#P"
    .string " A set move can be instantly\n"
    .string "used with {L_BUTTON} and {A_BUTTON}!#W\n"
    .string "See? Isn~27t it easy?#P"
    .string " Just set the move...#W\n"
    .string "Hold {L_BUTTON} and then press {A_BUTTON} to use it!#W\n"
    .string "It~27s very convenient!#P"
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
    .string " OK~2c here goes!#P"
    .string " Gggggggg...#W Poof!#P"
    .string " There!\n"
    .string "Success!#P"
    .string " #C5$m5#R has forgotten\n"
    .string "the move #C4$m1#R and any moves\n"
    .string "linked to it!\0"
    .align 2, 0

    .global gUnknown_80D9988
gUnknown_80D9988:
    .string " OK~2c here goes!#P"
    .string " Gggggggg...#W Poof!#P"
    .string " There!\n"
    .string "Success!#P"
    .string " #C5$m5#R has forgotten\n"
    .string "the move #C4$m1#R!\0"
    .align 2, 0

    .global gUnknown_80D99F0
gUnknown_80D99F0:
    .string " So~2c forget the move\n"
    .string "#C4$m1#R and any moves linked to it?\0"
    .align 2, 0

    .global gUnknown_80D9A2C
gUnknown_80D9A2C:
    .string " So~2c forget the move\n"
    .string "#C4$m1#R?\0"
    .align 2, 0

    .global gUnknown_80D9A50
gUnknown_80D9A50:
    .string " Uh... Huh?#W\n"
    .string "You appear to be a special Pokémon.#P"
    .string " I can~27t help you remember\n"
    .string "any moves~2c I don~27t think.\n"
    .string "I~27m sorry.\0"
    .align 2, 0

    .global gUnknown_80D9ACC
gUnknown_80D9ACC:
    .string " Uh... Hello?#W\n"
    .string "There don~27t appear to be any moves that\n"
    .string "can be remembered.\0"
    .align 2, 0

    .global gUnknown_80D9B1C
gUnknown_80D9B1C:
    .string " OK~2c here goes!#P"
    .string " Gggggggg...#W Pwah! Gulpin!#P"
    .string " There!\n"
    .string "Success!#P"
    .string " #CM$m5#R is done!#P"
    .string " It~27s forgotten the move\n"
    .string "#C4$m1#R and any moves linked to it~2c\n"
    .string "and #C5$m0#R has been remembered!\0"
    .align 2, 0

    .global gUnknown_80D9BD8
gUnknown_80D9BD8:
    .string " OK~2c here goes!#P"
    .string " Gggggggg...#W Pwah! Gulpin!#P"
    .string " There!\n"
    .string "Success!#P"
    .string " #CM$m5#R has forgotten\n"
    .string "the move #C4$m1#R and remembered\n"
    .string "the move #C5$m0#R!\0"
    .align 2, 0

    .global gUnknown_80D9C68
gUnknown_80D9C68:
    .string " So~2c forget #C4$m1#R\n"
    .string "and any moves linked to it~2c and remember\n"
    .string "the move #C5$m0#R?\0"
    .align 2, 0

    .global gUnknown_80D9CC0
gUnknown_80D9CC0:
    .string " So~2c forget the move\n"
    .string "#C4$m1#R and remember the move\n"
    .string "#C5$m0#R?\0"
    .align 2, 0

    .global gUnknown_80D9D00
gUnknown_80D9D00:
    .string " So~2c the move #C5$m0#R\n"
    .string "is the one to be remembered?#W\n"
    .string "OK~2c here goes!#P"
    .string " Gggggggggggg...#W Gulpin!#P"
    .string " There!\n"
    .string "Success!#P"
    .string " #CM$m5#R has\n"
    .string "remembered the move #C5$m0#R!\0"
    .align 2, 0

    .global gUnknown_80D9DA4
gUnknown_80D9DA4:
    .string " Which move would you like\n"
    .string "to recall?\0"
    .align 2, 0

    .global gUnknown_80D9DCC
gUnknown_80D9DCC:
    .string " Good!\n"
    .string "Now~2c who wants to link moves?\0"
    .align 2, 0

    .global gUnknown_80D9DF4
gUnknown_80D9DF4:
    .string " Whenever you get the urge\n"
    .string "to link moves~2c please come see me!\0"
    .align 2, 0

    .global gUnknown_80D9E34
gUnknown_80D9E34:
    .string " Shall we go on?\0"
    .align 2, 0

    .global gUnknown_80D9E48
gUnknown_80D9E48:
    .string " If you forget that move~2c\n"
    .string "you won~27t have any moves at all.\0"
    .align 2, 0

    .global gUnknown_80D9E88
gUnknown_80D9E88:
    .string " That move isn~27t linked~2c\n"
    .string "so it can~27t be delinked.\0"
    .align 2, 0

    .global gUnknown_80D9EC0
gUnknown_80D9EC0:
    .string " Too bad.\n"
    .string "There are no moves that can be linked.\0"
    .align 2, 0

    .global gUnknown_80D9EF4
gUnknown_80D9EF4:
    .string " Uh... Hello?\n"
    .string "You don~27t have enough money?\0"
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
    .string "Help rescue teams...#P"
    .string " Zzznarr... Urr...\n"
    .string "Train in different rooms to level up...#P"
    .string " Zzznarr... Urr!\n"
    .string "Make stronger rescue team...#P"
    .string " Urr... Zzznarr!\n"
    .string "Don~27t let up!\0"
    .align 2, 0

    .global gUnknown_80DA0DC
gUnknown_80DA0DC:
    .string " Zzznarr... Zzz...!\n"
    .string "Keep working...\0"
    .align 2, 0

    .global gUnknown_80DA100
gUnknown_80DA100:
    .string " Ah... Zzznarr...\n"
    .string "Cleared it...#P"
    .string " Zzzznarr... Urr...\n"
    .string "Good going... Keep going...#W\n"
    .string "Hunh...#W ...#P"
    .string " Gwoh?#W\n"
    .string "Gwogwogwoh?#P"
    .string " Mugawah?\n"
    .string "Cleared everything?#P"
    .string " Zzznarr!\n"
    .string "Congrazzz...#P"
    .string " Zzznarr... Zzznarr...\n"
    .string "Your reward...\n"
    .string "Promised...#P"
    .string " Zzz... Urr!\n"
    .string "#CIBonsly Doll#R...\0"
    .align 2, 0

    .global gUnknown_80DA204
gUnknown_80DA204:
    .string " Ah... Zzznarr...\n"
    .string "Cleared it...#P"
    .string " Congrazzz...\n"
    .string "Keep going... Zzz...\0"
    .align 2, 0

    .global gUnknown_80DA248
gUnknown_80DA248:
    .string " Aiyah... Zzznarr...\n"
    .string "Didn~27t finish...#P"
    .string " Zzz... Urr?\n"
    .string "No giving up...\0"
    .align 2, 0

    .global gUnknown_80DA290
gUnknown_80DA290:
    .string " Zzz... Narr...\n"
    .string "$m0? ~27K~2c go...\0"
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
    .string "support the efforts of rescue teams.#P"
    .string " Train in different rooms to\n"
    .string "level up...#W\n"
    .string "And toughen up your rescue team.#P"
    .string " Also...#W\n"
    .string "In the #CDFire Maze#R you will find only\n"
    .string "Fire-type Pokémon.#P"
    .string " In the #CDWater Maze#R there\n"
    .string "will only be Water-type Pokémon.#P"
    .string " In such ways~2c only one type\n"
    .string "of Pokémon will be in a given room.\n"
    .string "Study how types match up in battle.#P"
    .string " The Pokémon in this dojo~2c\n"
    .string "by the way~2c are all volunteers.#P"
    .string " They are participating\n"
    .string "because they want to see rescue teams\n"
    .string "succeed.#P"
    .string " The only thanks they expect\n"
    .string "is to see you become stronger.\n"
    .string "Don~27t let them down!#P"
    .string " There~27s more.#W\n"
    .string "For a rescue team that successfully\n"
    .string "completes all training courses...#P"
    .string " I have a special reward!#P"
    .string " Let that compel you to train\n"
    .string "harder!\0"
    .align 2, 0

    .global gUnknown_80DA62C
gUnknown_80DA62C:
    .string " Don~27t let up on your training!\n"
    .string "Keep bettering yourself!#P"
    .string " May you never lose your\n"
    .string "drive!\0"
    .align 2, 0

    .global gUnknown_80DA688
gUnknown_80DA688:
    .string " Ah...\n"
    .string "You have succeeded in your training!#P"
    .string " You~27ve shown your worth!#W\n"
    .string "Without a doubt~2c you have grown more\n"
    .string "powerful from your training!#W Wait...#W ...#P"
    .string " Wuh?#W\n"
    .string "What~2c what~2c what?!#P"
    .string " Did you maybe...#W\n"
    .string "Conquer all the training courses?#P"
    .string " That~27s...#W Amazing! You!#W\n"
    .string "Congratulations!#P"
    .string " I promised!#W\n"
    .string "I promised you a reward for completing\n"
    .string "the training courses!#P"
    .string " So... Here it is!#W\n"
    .string "My #CIBonsly Doll#R!#P"
    .string " Isn~27t it smashing? Hey?!\0"
    .align 2, 0

    .global gUnknown_80DA844
gUnknown_80DA844:
    .string " Ah...\n"
    .string "You have succeeded in your training!#P"
    .string " You~27ve shown your worth!#W\n"
    .string "Without a doubt~2c you have grown more\n"
    .string "powerful from your training!#P"
    .string " May this success drive\n"
    .string "you to train even harder!\0"
    .align 2, 0

    .global gUnknown_80DA908
gUnknown_80DA908:
    .string " Aiyah...#W\n"
    .string "You failed to reach the end...#W\n"
    .string "More training is what you need.#P"
    .string " But effort is never wasted!#P"
    .string " Learn from this and move\n"
    .string "forward!\0"
    .align 2, 0

    .global gUnknown_80DA998
gUnknown_80DA998:
    .string " The $m0?#W\n"
    .string "Your decision stands!#W\n"
    .string "Let the training begin!\0"
    .align 2, 0

    .global gUnknown_80DA9D4
gUnknown_80DA9D4:
    .string " Where do you wish to train?\0"
    .align 2, 0

    .global gUnknown_80DA9F4
gUnknown_80DA9F4:
    .string " Fine~2c farewell.\n"
    .string "Return if you seek more training.\0"
    .align 2, 0

    .global gUnknown_80DAA2C
gUnknown_80DAA2C:
    .string " What else do you seek?\0"
    .align 2, 0

    .global gUnknown_80DAA44
gUnknown_80DAA44:
    .string " This is the Makuhita Dojo!#W\n"
    .string "Through rigorous training~2c one begets\n"
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
    .string "Before leaving on an adventure~2c go visit\n"
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
    .string "If new recruits join you~2c try to return to\n"
    .string "your base without letting them faint.\n"
    .string "If you get them out safely~2c they~27ll wait\n"
    .string "for you in their Friend Areas.\n"
    .string "Once you get them out~2c they~27ll always\n"
    .string "return home if they faint in a dungeon.\n"
    .string "If you faint in a dungeon~2c you lose all your\n"
    .string "money and some items~2c too.\0"
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
    .string "  Select an item~2c then press {L_BUTTON} or {R_BUTTON}.\n"
    .string "Moving to the Friend Area Map:\n"
    .string "  Move out from the town~27s west side\n"
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
    .string "Description: Choose item or move~2c {START_BUTTON}\0"
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
        .string "#+you can have #CG1~2c000#R {POKE}."
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
        .string "Money: #C5%d#R {POKE}"
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

