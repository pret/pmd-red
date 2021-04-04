        .section .rodata

	.global gUnknown_80DED48
gUnknown_80DED48: @ 80DED48
        @ replacing .incbin "baserom.gba", 0x000ded48, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DED60
gUnknown_80DED60: @ 80DED60
        @ replacing .incbin "baserom.gba", 0x000ded60, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x07, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DED78
gUnknown_80DED78: @ 80DED78
        @ replacing .incbin "baserom.gba", 0x000ded78, 0x40
        .4byte Confirm_80DED98
        .byte 0x0b, 0x00, 0x00, 0x00
        .4byte Info_80DED90
        .byte 0x0c, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global Info_80DED90
        Info_80DED90:
        .string "Info\0"
        .align 2,0

        .global Confirm_80DED98
        Confirm_80DED98:
        .string "Confirm\0"

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DEDB8
gUnknown_80DEDB8: @ 80DEDB8
        @ replacing .incbin "baserom.gba", 0x000dedb8, 0x50
        .4byte SendThankYou_Text
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte GetThankYou_Text
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte Cancel_80DEDD8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global Cancel_80DEDD8
        Cancel_80DEDD8:
        .string "Cancel\0"
        .align 2,0

        .global GetThankYou_Text
        GetThankYou_Text:
        .string "Get Thank-You Mail\0"
        .align 2,0

        .global SendThankYou_Text
        SendThankYou_Text:
        .string "Send Thank-You Mail\0"
        .align 2,0

	.global gUnknown_80DEE08
gUnknown_80DEE08: @ 80DEE08
        @ Thank You Mail Pelipper Menu
        @ replacing .incbin "baserom.gba", 0x000dee08, 0x3c
        .4byte GameLinkCable_Text
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte Password_Text
        .byte 0x05, 0x00, 0x00, 0x00
        .4byte Cancel_80DEDD8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global Password_Text
        Password_Text:
        .string "Password\0"
        .align 2,0

        .global GameLinkCable_Text
        GameLinkCable_Text:
        .string "Game Link cable\0"
        .align 2,0

	.global gUnknown_80DEE44
gUnknown_80DEE44: @ 80DEE44
        @ Game Link Cable Thank-You Mail Menu
        @ replacing .incbin "baserom.gba", 0x000dee44, 0x1c
        .4byte Yes_80DEE5C
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte Cancel_80DEDD8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global Yes_80DEE5C
        Yes_80DEE5C:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80DEE60
gUnknown_80DEE60: @ 80DEE60
        @ replacing .incbin "baserom.gba", 0x000dee60, 0x1c
        .4byte Yes_80DEE5C
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte No_80DEE78
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global No_80DEE78
        No_80DEE78:
        .string "No\0"
        .align 2,0

	.global gUnknown_80DEE7C
gUnknown_80DEE7C: @ 80DEE7C
        @ replacing .incbin "baserom.gba", 0x000dee7c, 0x40
        .4byte SendItem_Text
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte DontSendItemText
        .byte 0x0a, 0x00, 0x00, 0x00
        .4byte Cancel_80DEDD8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global DontSendItem_Text
        DontSendItemText:
        .string "Don~27t Send Item\0"
        .align 2,0

        .global SendItem_Text
        SendItem_Text:
        .string "Send Item\0"
        .align 2,0

	.global gUnknown_80DEEBC
gUnknown_80DEEBC: @ 80DEEBC
        @ replacing .incbin "baserom.gba", 0x000deebc, 0x28
        .4byte SendWOItem_Text
        .byte 0x0a, 0x00, 0x00, 0x00
        .4byte Cancel_80DEDD8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global SendWOItem_Text
        SendWOItem_Text:
        .string "Send w/o Item\0"
        .align 2,0

	.global gUnknown_80DEEE4
gUnknown_80DEEE4: @ 80DEEE4
        @ replacing .incbin "baserom.gba", 0x000deee4, 0x20
        .4byte Yes_80DEE5C
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte No_80DEE78
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte Cancel_80DEDD8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.include "data/text/wonder_mail_2.inc"

	.global gUnknown_80DFBD0
gUnknown_80DFBD0: @ 80DFBD0
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00


	.global gUnknown_80DFBE8
gUnknown_80DFBE8: @ 80DFBE8
@ replacing .incbin "baserom.gba", 0x000dfbe8, 0x4
        .byte 0x01, 0x00, 0x0c, 0x00

	.global gUnknown_80DFBEC
gUnknown_80DFBEC: @ 80DFBEC
@ replacing .incbin "baserom.gba", 0x000dfbec, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0xe8, 0xfb, 0x0d, 0x08


	.global gUnknown_80DFC04
gUnknown_80DFC04: @ 80DFC04
        .string "News List\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFC18
gUnknown_80DFC18: @ 80DFC18
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00

        .global gUnkData_80DFC30
        gUnkData_80DFC30:
        .byte 0x01, 0x00, 0x16, 0x00

	.global gUnknown_80DFC34
gUnknown_80DFC34: @ 80DFC34
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1A, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00

        .4byte gUnkData_80DFC30

	.global gUnknown_80DFC4C
gUnknown_80DFC4C: @ 80DFC4C
        .string "She\0"

	.global gUnknown_80DFC50
gUnknown_80DFC50: @ 80DFC50
        .string "He\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFC5C
gUnknown_80DFC5C: @ 80DFC5C
@ replacing .incbin "baserom.gba", 0x000dfc5c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFC74
gUnknown_80DFC74: @ 80DFC74
@ replacing .incbin "baserom.gba", 0x000dfc74, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gMailboxText
gMailboxText: @ 80DFC8C
        .string "Mailbox\0"
        .string "pksdir0\0"

	.global gUnknown_80DFC9C
gUnknown_80DFC9C: @ 80DFC9C
@ replacing .incbin "baserom.gba", 0x000dfc9c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFCB4
gUnknown_80DFCB4: @ 80DFCB4
@ replacing .incbin "baserom.gba", 0x000dfcb4, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gBulletinBoardText
gBulletinBoardText: @ 80DFCCC
        .string "Bulletin Board\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFCE4
gUnknown_80DFCE4: @ 80DFCE4
@ replacing .incbin "baserom.gba", 0x000dfce4, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFCFC
gUnknown_80DFCFC: @ 80DFCFC
@ replacing .incbin "baserom.gba", 0x000dfcfc, 0x18
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x06, 0x00
        .byte 0x00, 0x00
        .byte 0x02, 0x00
        .byte 0x02, 0x00
        .byte 0x18, 0x00
        .byte 0x0e, 0x00
        .byte 0x0e, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DFD14
gUnknown_80DFD14: @ 80DFD14
        .string "Job List\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFD28
gUnknown_80DFD28: @ 80DFD28
@ replacing .incbin "baserom.gba", 0x000dfd28, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFD40
gUnknown_80DFD40: @ 80DFD40
@ replacing .incbin "baserom.gba", 0x000dfd40, 0x18
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x04, 0x00
        .byte 0x00, 0x00
        .byte 0x15, 0x00
        .byte 0x06, 0x00
        .byte 0x07, 0x00
        .byte 0x03, 0x00
        .byte 0x03, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DFD58
gUnknown_80DFD58: @ 80DFD58
@ replacing .incbin "baserom.gba", 0x000dfd58, 0x18
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x04, 0x00
        .byte 0x00, 0x00
        .byte 0x15, 0x00
        .byte 0x0f, 0x00
        .byte 0x06, 0x00
        .byte 0x03, 0x00
        .byte 0x03, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00
        .byte 0x00, 0x00

	.global gUnknown_80DFD70
gUnknown_80DFD70: @ 80DFD70
        .string "Take Job\0"
        .align 2,0

	.global gUnknown_80DFD7C
gUnknown_80DFD7C: @ 80DFD7C
        .string "Suspend\0"
        .string "pksdir0\0"

	.global gUnknown_80DFD8C
gUnknown_80DFD8C: @ 80DFD8C
@ replacing .incbin "baserom.gba", 0x000dfd8c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFDA4
gUnknown_80DFDA4: @ 80DFDA4
@ replacing .incbin "baserom.gba", 0x000dfda4, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x0
        .byte 0x18, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFDBC
gUnknown_80DFDBC: @ 80DFDBC
	.string "RESCUE EVENT\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80DFDD4
gUnknown_80DFDD4: @ 80DFDD4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFE04
gUnknown_80DFE04: @ 80DFE04
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x06, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80DFE1C
gUnknown_80DFE1C: @ 80DFE1C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.include "data/text/wonder_mail_3.inc"

	.global gUnknown_80E016C
gUnknown_80E016C: @ 80E016C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.include "data/text/wonder_mail_complete.inc"

	.global gUnknown_80E0248
gUnknown_80E0248: @ 80E0248
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x12, 0x00

	.global gUnknown_80E0264
gUnknown_80E0264: @ 80E0264
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x60, 0x02, 0x0e, 0x08
        .byte 0x70, 0x6b, 0x73, 0x64
        .byte 0x69, 0x72, 0x30, 0x00

	.global gUnknown_80E0284
gUnknown_80E0284: @ 80E0284
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E029C
gUnknown_80E029C: @ 80E029C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E02B4
gUnknown_80E02B4: @ 80E02B4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x06, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E02CC
gUnknown_80E02CC: @ 80E02CC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gMailboxCheckMail
gMailboxCheckMail: @ 80E02E4
        .string "Check Mail\0"
        .align 2,0

	.global gMailboxJobList
gMailboxJobList: @ 80E02F0
        .string "Job List\0"
        .align 2,0

	.global gMailboxPKMNNews
gMailboxPKMNNews: @ 80E02FC
        .string "PKMN News\0"
        .align 2,0

	.global gMailActionStore
gMailActionStore: @ 80E0308
        .string "Store\0"
        .align 2,0

	.global gMailActionRead
gMailActionRead: @ 80E0310
        .string "Read\0"
        .align 2,0

	.global gMailAccepted
gMailAccepted: @ 80E0318
        .string "Accepted\0"
        .align 2,0

	.global gUnknown_80E0324
gUnknown_80E0324: @ 80E0324
        .string "/\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E0330
gUnknown_80E0330: @ 80E0330
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0348
gUnknown_80E0348: @ 80E0348
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x03, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0360
gUnknown_80E0360: @ 80E0360
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x06, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0378
gUnknown_80E0378: @ 80E0378
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0f, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gPelliperBoard_BulletinBoard
gPelliperBoard_BulletinBoard: @ 80E0390
        .string "Bulletin Board\0"
        .align 2,0

	.global gPelliperBoard_JobList
gPelliperBoard_JobList: @ 80E03A0
        .string "Job List\0"
        .align 2,0

	.global gUnknown_80E03AC
gUnknown_80E03AC: @ 80E03AC
        .string "Accepted\0"
        .align 2,0

	.global gUnknown_80E03B8
gUnknown_80E03B8: @ 80E03B8
        .string "/\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E03C4
gUnknown_80E03C4: @ 80E03C4
	.incbin "baserom.gba", 0xE03C4, 0x30

	.global gUnknown_80E03F4
gUnknown_80E03F4: @ 80E03F4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x06, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E040C
gUnknown_80E040C: @ 80E040C
        .string "Send\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E041C
gUnknown_80E041C: @ 80E041C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0434
gUnknown_80E0434: @ 80E0434
        .string " Here~27s your reward!\n"
        .string "#C5$d0#R "
        .byte 0x83, 0xBF, 0x83, 0xC4
        .string "!\0"
        .align 2,0

	.global gUnknown_80E045C
gUnknown_80E045C: @ 80E045C
	.incbin "baserom.gba", 0xE045C, 0x28

	.global gUnknown_80E0484
gUnknown_80E0484: @ 80E0484
        .string "#+#CN$m0#R~27s team received\n"
        .string "#+#C5$d0#R "
        .byte 0x83, 0xBF, 0x83, 0xC4
        .byte 0x2E, 0x00, 0x00, 0x00

	.global gUnknown_80E04B4
gUnknown_80E04B4: @ 80E04B4
        .string " As your reward~2c you can\n"
        .string "now go to the Friend Area\n"
        .string "#C4$h#R!\0"
        .align 2,0

	.global gUnknown_80E04F4
gUnknown_80E04F4: @ 80E04F4
	.incbin "baserom.gba", 0xE04F4, 0xCC

	.global gUnknown_80E05C0
gUnknown_80E05C0: @ 80E05C0
        .string "#+#CN$m0#R gained access\n"
        .string "#+to the Friend Area\n"
        .string "#+#C4$h#R.\0"
        .align 2,0

	.global gUnknown_80E05FC
gUnknown_80E05FC: @ 80E05FC
        .string "#+#CN$m0#R~27s team gained access\n"
        .string "#+to the Friend Area\n"
        .string "#+#C4$h#R.\0"
        .align 2,0

	.global gUnknown_80E0640
gUnknown_80E0640: @ 80E0640
        .string " Here~27s your reward!\n"
        .string "The promised #C4$i1#R!\0"
        .align 2,0

	.global gUnknown_80E0670
gUnknown_80E0670: @ 80E0670
        .string "#+Rescue Team #CG$t#R\n"
        .string "#+gained #C5$d0#R rescue points.\0"
        .align 2,0

	.global gUnknown_80E06A8
gUnknown_80E06A8: @ 80E06A8
        .string "#+Congratulations!#P"
        .string "#+#CG$t#R went up in rank\n"
        .string "#+from the $m2\n"
        .string "#+to the $m3!\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E06FC
gUnknown_80E06FC: @ 80E06FC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0714
gUnknown_80E0714: @ 80E0714
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0e, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E072C
gUnknown_80E072C: @ 80E072C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x10, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0744
gUnknown_80E0744: @ 80E0744
        .string "Dungeons\0"
        .align 2,0

	.global gUnknown_80E0750
gUnknown_80E0750: @ 80E0750
        .byte 0x83, 0xC2, 0x00, 0x00

	.global gUnknown_80E0754
gUnknown_80E0754: @ 80E0754
        .byte 0x83, 0xC0, 0x00, 0x00
        .string "pksdir0\0"

	.global gUnknown_80E0760
gUnknown_80E0760: @ 80E0760
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0778
gUnknown_80E0778: @ 80E0778
        .string "#+#CN$n0#R received the #CIBonsly Doll#R!\n"
        .string "#+It has been placed outside your\n"
        .string "#+rescue team base.\0"
        .align 2,0

	.global gUnknown_80E07D8
gUnknown_80E07D8: @ 80E07D8
        .string "Go Train\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E07EC
gUnknown_80E07EC: @ 80E07EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0804
gUnknown_80E0804: @ 80E0804
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0e, 0x00, 0x0e, 0x00
        .byte 0x0e, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E081C
gUnknown_80E081C: @ 80E081C
        .string "Courses\0"
        .align 2,0

	.global gUnknown_80E0824
gUnknown_80E0824: @ 80E0824
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_80E0828
gUnknown_80E0828: @ 80E0828
        .string "#c%c%s#r\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E083C
gUnknown_80E083C: @ 80E083C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0854
gUnknown_80E0854: @ 80E0854
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x11, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E086C
gUnknown_80E086C: @ 80E086C
        
        .4byte SOSList
        .4byte RequestList
        .4byte SOSMail
        .4byte ToDoList
        .4byte AOKMail
        .4byte ThanksList
        .4byte CompletedJobs
        .4byte OkdRescue
       
        .global OkdRescue
        OkdRescue:
        .string "OK~27d Rescues\0"
        .align 2,0

        .global CompletedJobs
        CompletedJobs:
        .string "Completed Jobs\0"
        .align 2,0

        .global ThanksList
        ThanksList:
        .string "Thanks List\0"
        .align 2,0

        .global AOKMail
        AOKMail:
        .string "A-OK Mail\0"
        .align 2,0

        .global ToDoList
        ToDoList:
        .string "To-Do List\0"
        .align 2,0

        .global SOSMail
        SOSMail:
        .string "SOS Mail\0"
        .align 2,0

        .global RequestList
        RequestList:
        .string "Request List\0"
        .align 2,0

        .global SOSList
        SOSList:
        .string "SOS List\0"
        .align 2,0

        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E0900
gUnknown_80E0900: @ 80E0900
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global DATA_80E0918
        DATA_80E0918:
        .byte 0x01, 0x00, 0x12, 0x00

	.global gUnknown_80E091C
gUnknown_80E091C: @ 80E091C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00

        .4byte DATA_80E0918

	.global gUnknown_80E0934
gUnknown_80E0934: @ 80E0934
        .string "ID:\0"

	.global gUnknown_80E0938
gUnknown_80E0938: @ 80E0938
        .string "%-4d\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E0948
gUnknown_80E0948: @ 80E0948
        .4byte Yes_80E0964
        .byte 0x02, 0x00, 0x00, 0x00
        .4byte No_80E0960
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00

        .global No_80E0960
        No_80E0960:
        .string "No\0"
        .align 2,0

        .global Yes_80E0964
        Yes_80E0964:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80E0968
gUnknown_80E0968: @ 80E0968
        .4byte Delete_80E0988
        .byte 0x04, 0x00, 0x00, 0x00
        .4byte Info_80E0980
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x01, 0x00, 0x00, 0x00

        .global Info_80E0980
        Info_80E0980:
        .string "Info\0"
        .align 2,0
       
       .global Delete_80E0988
       Delete_80E0988:
        .string "Delete\0"
        .align 2,0

	.global gUnknown_80E0990
gUnknown_80E0990: @ 80E0990
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E09A8
gUnknown_80E09A8: @ 80E09A8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x0B, 0x00
        .byte 0x08, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E09C0
gUnknown_80E09C0: @ 80E09C0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x11, 0x00, 0x0F, 0x00
        .byte 0x07, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E09D8
gUnknown_80E09D8: @ 80E09D8
	.incbin "baserom.gba", 0xE09D8, 0x34

	.global gUnknown_80E0A0C
gUnknown_80E0A0C: @ 80E0A0C
	.incbin "baserom.gba", 0xE0A0C, 0x3C

	.global gUnknown_80E0A48
gUnknown_80E0A48: @ 80E0A48
        @ Pelipper help menu (one not at the counter on the right)
	.incbin "baserom.gba", 0xE0A48, 0x74

	.global gUnknown_80E0ABC
gUnknown_80E0ABC: @ 80E0ABC
        @ Friend Rescue menu from help menu
        @ replacing .incbin "baserom.gba", 0x000e0abc, 0x80
        .4byte FriendRescueInfo_Text
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte GoRescue_Text
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte GetHelp_Text
        .byte 0x08, 0x00, 0x00, 0x00
        .4byte DeletingMailInfo_Text
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte Exit_80EA0EC
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00

        .global Exit_80E0AEC
        Exit_80EA0EC:
        .string "Exit\0"
        .align 2,0

        .global DeletingMailInfo_Text
        DeletingMailInfo_Text:
        .string "Deleting Mail Info\0"
        .align 2,0

        .global GetHelp_Text
        GetHelp_Text:
        .string "#C6Get help#R \0"
        .align 2,0

        .global GoRescue_Text
        GoRescue_Text:
        .string "#C6Go rescue#R \0"
        .align 2,0

        .global FriendRescueInfo_Text
        FriendRescueInfo_Text:
        .string "Friend Rescue Info\0"
        .align 2,0

	.global gUnknown_80E0B3C
gUnknown_80E0B3C: @ 80E0B3C
        @ Go Resuce menu from Peilipper help menu
        @ replacing .incbin "baserom.gba", 0x000e0b3c, 0x98
        .4byte RescueProcedures_Text
        .byte 0x0a, 0x00, 0x00, 0x00
        .4byte ReceiveSOSMail_Text
        .byte 0x0b, 0x00, 0x00, 0x00
        .4byte LeaveForRescue_Text
        .byte 0x0c, 0x00, 0x00, 0x00
        .4byte SendAOKMail_Text
        .byte 0x0d, 0x00, 0x00, 0x00
        .4byte GetThankYouMail_Text
        .byte 0x0e, 0x00, 0x00, 0x00
        .4byte Exit_80EA0EC
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00

        .global GetThankYouMail_Text
        GetThankYouMail_Text:
        .string "Get Thank-You Mail\0"
        .align 2,0

        .global SendAOKMail_Text
        SendAOKMail_Text:
        .string "Send A-OK Mail\0"
        .align 2,0

        .global LeaveForResuce_Text
        LeaveForRescue_Text:
        .string "Leave for Rescue\0"
        .align 2,0

        .global ReceiveSOSMail_Text
        ReceiveSOSMail_Text:
        .string "Receive SOS Mail\0"
        .align 2,0

        .global RescueProcedures_Text
        RescueProcedures_Text:
        .string "Rescue Procedures\0"
        .align 2,0

	.global gUnknown_80E0BD4
gUnknown_80E0BD4: @ 80E0BD4
        @ Get help menu from Pelipper help menu
        @ replacing .incbin "baserom.gba", 0x000e0bd4, 0x78
        .4byte GettingHelp_Text
        .byte 0x0f, 0x00, 0x00, 0x00
        .4byte SendSOSMail_Text
        .byte 0x10, 0x00, 0x00, 0x00
        .4byte RecieveAOKMail_Text
        .byte 0x11, 0x00, 0x00, 0x00
        .4byte SentThankYouMail_Text
        .byte 0x12, 0x00, 0x00, 0x00
        .4byte Exit_80EA0EC
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00

        .global SendThankYouMail_Text
        SentThankYouMail_Text:
        .string "Send Thank-You Mail\0"
        .align 2,0

        .global ReceiveAOKMail_Text
        RecieveAOKMail_Text:
        .string "Receive A-OK Mail\0"
        .align 2,0

        .global SendSOSMail_Text
        SendSOSMail_Text:
        .string "Send SOS Mail\0"
        .align 2,0

        .global GettingHelp_Text
        GettingHelp_Text:
        .string "Getting Help\0"
        .align 2,0


	.include "data/text/wonder_mail_4.inc"

	.global gUnknown_80E1EFC
gUnknown_80E1EFC: @ 80E1EFC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global gUnkData_80E1F14
        gUnkData_80E1F14:
        .byte 0x01, 0x00, 0x08, 0x00

	.global gUnknown_80E1F18
gUnknown_80E1F18: @ 80E1F18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00

        .4byte gUnkData_80E1F14

	.global gUnknown_80E1F30
gUnknown_80E1F30: @ 80E1F30
        .string "Objectives\0"
        .align 2,0

	.global gUnknown_80E1F3C
gUnknown_80E1F3C: @ 80E1F3C
        .string "%dF\0"

	.global gUnknown_80E1F40
gUnknown_80E1F40: @ 80E1F40
        .string "  Rescue #C6%s#R\0"
        .align 2,0

	.global gUnknown_80E1F54
gUnknown_80E1F54: @ 80E1F54
        .string "Just go!\0"
        .align 2,0

	.global gUnknown_80E1F60
gUnknown_80E1F60: @ 80E1F60
        .string "  Bring #C4%s#R\0"
        .align 2,0

	.global gUnknown_80E1F70
gUnknown_80E1F70: @ 80E1F70
        .string "  Find #C4%s#R\0"
        .align 2,0

	.global gUnknown_80E1F80
gUnknown_80E1F80: @ 80E1F80
        .string "  Escort to #C6%s#R\0"
        .align 2,0

	.global gUnknown_80E1F94
gUnknown_80E1F94: @ 80E1F94
        .string "#CW???#R\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E1FA8
gUnknown_80E1FA8: @ 80E1FA8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global gUnkData_80E1FC0
        gUnkData_80E1FC0:
        .byte 0x01, 0x00, 0x0A, 0x00

	.global gUnknown_80E1FC4
gUnknown_80E1FC4: @ 80E1FC4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x0a, 0x00
        .byte 0x0a, 0x00, 0x00, 0x00

        .4byte gUnkData_80E1FC0

	.global gUnknown_80E1FDC
gUnknown_80E1FDC: @ 80E1FDC
        .string "Password\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
