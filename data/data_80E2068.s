	.section .rodata

        .global gUnknown_80E2068
gUnknown_80E2068: @ 80E2068
        .4byte GoRescue_80E20AC
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte GetHelp_80E20A0
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global Exit_80E2090
        Exit_80E2090:
        .string "Exit\0"
        .align 2,0

        .global Info_80E2098
        Info_80E2098:
        .string "Info\0"
        .align 2,0

        .global GetHelp_80E20A0
        GetHelp_80E20A0:
        .string "Get Help\0"
        .align 2,0

        .global GoRescue_80E20AC
        GoRescue_80E20AC:
        .string "Go Rescue\0"
        .align 2,0

	.global gUnknown_80E20B8
gUnknown_80E20B8: @ 80E20B8
        .4byte GoRescue_80E20AC
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte GetHelp_80E20A0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E20E0
gUnknown_80E20E0: @ 80E20E0
        .4byte GoRescue_80E20AC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte GetHelp_80E20A0
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2108
gUnknown_80E2108: @ 80E2108
        .4byte GoRescue_80E20AC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte GetHelp_80E20A0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2130
gUnknown_80E2130: @ 80E2130
        @ Friend Resuce Pelipper Menu
        .4byte ReceiveSOSMail_80E217C
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte SendAOKMail_80E216C
        .byte 0x04, 0x00, 0x00, 0x00
        .4byte GetThankYouMail_80E2158
        .byte 0x14, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global GetThankYouMail_80E2158
        GetThankYouMail_80E2158:
        .string "Get Thank-You Mail\0"
        .align 2,0

        .global SendAOKMail_80E216C
        SendAOKMail_80E216C:
        .string "Send A-OK Mail\0"
        .align 2,0

        .global ReceiveSOSMail_80E217C
        ReceiveSOSMail_80E217C:
        .string "Receive SOS Mail\0"
        .align 2,0

	.global gUnknown_80E2190
gUnknown_80E2190: @ 80E2190
        .4byte ReceiveSOSMail_80E217C
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte SendAOKMail_80E216C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte GetThankYouMail_80E2158
        .byte 0x14, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E21B8
gUnknown_80E21B8: @ 80E21B8
        .4byte SendSOS_80E2208
        .byte 0x11, 0x00, 0x00, 0x00
        .4byte ReceiveAOK_80E21F4
        .byte 0x12, 0x00, 0x00, 0x00
        .4byte SendThankYou_80E21E0
        .byte 0x13, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global SendThankYou_80E21E0
        SendThankYou_80E21E0:
        .string "Send Thank-You Mail\0"
        .align 2,0

        .global ReceiveAOK_80E21F4
        ReceiveAOK_80E21F4:
        .string "Receive A-OK Mail\0"
        .align 2,0

        .global SendSOS_80E2208
        SendSOS_80E2208:
        .string "Send SOS Mail\0"
        .align 2,0

	.global gUnknown_80E2218
gUnknown_80E2218: @ 80E2218
        .4byte SendSOS_80E2208
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte ReceiveAOK_80E21F4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte SendThankYou_80E21E0
        .byte 0x13, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2240
gUnknown_80E2240: @ 80E2240
        .4byte SendSOS_80E2208
        .byte 0x11, 0x00, 0x00, 0x00
        .4byte ReceiveAOK_80E21F4
        .byte 0x12, 0x00, 0x00, 0x00
        .4byte SendThankYou_80E21E0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2268
gUnknown_80E2268: @ 80E2268
        .4byte SendSOS_80E2208
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte ReceiveAOK_80E21F4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte SendThankYou_80E21E0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2290
gUnknown_80E2290: @ 80E2290
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global Cancel_80E22A8
        Cancel_80E22A8:
        .string "Cancel\0"
        .align 2,0

        .global Yes_80E22B0
        Yes_80E22B0:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80E22B4
gUnknown_80E22B4: @ 80E22B4
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte No_80E22CC
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global No_80E22CC
        No_80E22CC:
        .string "No\0"
        .align 2,0

	.global gUnknown_80E22D0
gUnknown_80E22D0: @ 80E22D0
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte No_80E22CC
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E22F0
gUnknown_80E22F0: @ 80E22F0
        .4byte SendPokemon_80E2308
        .byte 0x10, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global SendPokemon_80E2308
        SendPokemon_80E2308:
        .string "Send w/o Pokémon\0"
        .align 2,0

	.global gUnknown_80E231C
gUnknown_80E231C: @ 80E231C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x07, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E2334
gUnknown_80E2334: @ 80E2334
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E234C
gUnknown_80E234C: @ 80E234C
        .4byte Confirm_80E2364
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .global Confirm_80E2364
        Confirm_80E2364:
        .string "Confirm\0"
        .align 2,0

	.global gUnknown_80E236C
gUnknown_80E236C: @ 80E236C
        .4byte GameLinkCable_80E2398
        .byte 0x0b, 0x00, 0x00, 0x00
        .4byte Password_80E238C
        .byte 0x0d, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global Password_80E238C
        Password_80E238C:
        .string "Password\0"
        .align 2,0
        .global GameLinkCable_80E2398
        GameLinkCable_80E2398:
        .string "Game Link cable\0"
        .align 2,0

	.global gUnknown_80E23A8
gUnknown_80E23A8: @ 80E23A8
        .4byte SendPokemon_80E23E0
        .byte 0x0f, 0x00, 0x00, 0x00
        .4byte DontSendPokemon_80E23C8
        .byte 0x10, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global DontSendPokemon_80E23C8
        DontSendPokemon_80E23C8:
        .string "Don{APOSTROPHE}t Send Pokémon\0"
        .align 2,0

        .global SendPokemon_80E23E0
        SendPokemon_80E23E0:
        .string "Send Pokémon\0"
        .align 2,0

	.global gUnknown_80E23F0
gUnknown_80E23F0: @ 80E23F0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E2408
gUnknown_80E2408: @ 80E2408
        .4byte Confirm_80E2364
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x0a, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E2440
gUnknown_80E2440: @ 80E2440
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2458
gUnknown_80E2458: @ 80E2458
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte No_80E22CC
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2470
gUnknown_80E2470: @ 80E2470
        .4byte SendItem_80E24A4
        .byte 0x15, 0x00, 0x00, 0x00
        .4byte DontSendItem_80E2490
        .byte 0x16, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        DontSendItem_80E2490:
        .string "Don{APOSTROPHE}t Send Item\0"
        .align 2,0
        SendItem_80E24A4:
        .string "Send Item\0"
        .align 2,0


	.global gUnknown_80E24B0
gUnknown_80E24B0: @ 80E24B0
        .4byte SendwoItem_80E24C8
        .byte 0x16, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        SendwoItem_80E24C8:
        .string "Send w/o Item\0"
        .align 2,0

	.global gUnknown_80E24D8
gUnknown_80E24D8: @ 80E24D8
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte No_80E22CC
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E24F8
gUnknown_80E24F8: @ 80E24F8
        .4byte RescueInfo_80E2540
        .byte 0x1A, 0x00, 0x00, 0x00
        .4byte GoRescue_80E530
        .byte 0x1B, 0x00, 0x00, 0x00
        .4byte GetHelp_80E2520
        .byte 0x1C, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00

        GetHelp_80E2520:
        .string "{COLOR_1 YELLOW}Get help{END_COLOR_TEXT_1} \0"
        .align 2,0
        GoRescue_80E530:
        .string "{COLOR_1 YELLOW}Go rescue{END_COLOR_TEXT_1} \0"
        .align 2,0
        RescueInfo_80E2540:
        .string "Friend Rescue Info\0"
        .align 2,0

	.global gUnknown_80E2554
gUnknown_80E2554: @ 80E2554
        .4byte RescueProcedures_80E25A0
        .byte 0x1E, 0x00, 0x00, 0x00
        .4byte ReceiveSOSMail_80E217C
        .byte 0x1F, 0x00, 0x00, 0x00
        .4byte LeaveForRescue_80E258C
        .byte 0x20, 0x00, 0x00, 0x00
        .4byte SendAOKMail_80E216C
        .byte 0x21, 0x00, 0x00, 0x00
        .4byte GetThankYouMail_80E2158
        .byte 0x22, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00

        LeaveForRescue_80E258C:
        .string "Leave for Rescue\0"
        .align 2,0

        RescueProcedures_80E25A0:
        .string "Rescue Procedures\0"
        .align 2,0

	.global gUnknown_80E25B4
gUnknown_80E25B4: @ 80E25B4
        .4byte GettingHelp_80E25E4
        .byte 0x23, 0x00, 0x00, 0x00
        .4byte SendSOS_80E2208
        .byte 0x24, 0x00, 0x00, 0x00
        .4byte ReceiveAOK_80E21F4
        .byte 0x25, 0x00, 0x00, 0x00
        .4byte SendThankYou_80E21E0
        .byte 0x26, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00

        GettingHelp_80E25E4:
        .string "Getting Help\0"
        .align 2,0

	.global gUnknown_80E25F4
gUnknown_80E25F4: @ 80E25F4
        .string "What would you like to do?\0"
        .align 2,0

	.global gUnknown_80E2610
gUnknown_80E2610: @ 80E2610
        .string "How would you like to send your\n"
        .string "{COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E2640
gUnknown_80E2640: @ 80E2640
        .string "How would you like to receive your\n"
        .string "friend{APOSTROPHE}s {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E2680
gUnknown_80E2680: @ 80E2680
        .string "How would you like to send your\n"
        .string "{COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E26B0
gUnknown_80E26B0: @ 80E26B0
        .string "How would you like to receive your\n"
        .string "friend{APOSTROPHE}s {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E26F0
gUnknown_80E26F0: @ 80E26F0
        .string "How would you like to send your\n"
        .string "{COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E2728
gUnknown_80E2728: @ 80E2728
        .string "How would you like to receive your\n"
        .string "friend{APOSTROPHE}s {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E276C
gUnknown_80E276C: @ 80E276C
        .string "The GBA Game Pak does not have\n"
        .string "an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} on it.\0"
        .align 2,0

	.global gUnknown_80E27A4
gUnknown_80E27A4: @ 80E27A4
        .string "If you accept an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}{COMMA} the\n"
        .string "{COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} you received before\n"
        .string "will be overwritten. Is that OK?\0"
        .align 2,0

	.global gUnknown_80E2814
gUnknown_80E2814: @ 80E2814
        .string "Please enter the {COLOR_1 LIGHT_BLUE_2}A-OK Mail password{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E2840
gUnknown_80E2840: @ 80E2840
        .string "The {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} will be received and\n"
        .string "processed.\0"
        .align 2,0

	.global gUnknown_80E2874
gUnknown_80E2874: @ 80E2874
        .string "A {COLOR_1 LIGHT_BLUE_2}helper Pokémon{END_COLOR_TEXT_1} also arrived!\0"
        .align 2,0

	.global gUnknown_80E2898
gUnknown_80E2898: @ 80E2898
        .string "An {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} was received.\n"
        .string "Your adventure will be saved.\0"
        .align 2,0

	.global gUnknown_80E28D8
gUnknown_80E28D8: @ 80E28D8
        .string "Resume your game using {COLOR_1 LIGHT_BLUE_2}Revive Team{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E2904
gUnknown_80E2904: @ 80E2904
        .string "Your friend{APOSTROPHE}s Mailbox is full.\n"
        .string "This piece of mail cannot be sent.\n"
        .string "The recipient must delete old mail.\0"
        .align 2,0

	.global gUnknown_80E296C
gUnknown_80E296C: @ 80E296C
        .string "Please choose the {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} you want\n"
        .string "to send.\0"
        .align 2,0

	.global gUnknown_80E29A0
gUnknown_80E29A0: @ 80E29A0
        .string "This {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} will be sent.\n"
        .string "Is that OK?\0"
        .align 2,0

	.global gUnknown_80E29D0
gUnknown_80E29D0: @ 80E29D0
        .string "Your {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} was sent.\n"
        .string "Your adventure will be saved.\0"
        .align 2,0

	.global gUnknown_80E2A0C
gUnknown_80E2A0C: @ 80E2A0C
        .asciz "Save completed."
        .align 2,0

	.global gUnknown_80E2A1C
gUnknown_80E2A1C: @ 80E2A1C
        .string "Please give this password to the friend\n"
        .string "coming to your rescue.\0"
        .align 2,0

	.global gUnknown_80E2A5C
gUnknown_80E2A5C: @ 80E2A5C
        .string "Here is the {COLOR_1 LIGHT_BLUE_2}SOS Mail password{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E2A80
gUnknown_80E2A80: @ 80E2A80
        .string "Here is the {COLOR_1 LIGHT_BLUE_2}A-OK Mail password{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E2AA8
gUnknown_80E2AA8: @ 80E2AA8
.string "Please give this password to the friend\n"
.string "that you rescued.\0"
.align 2,0

	.global gUnknown_80E2AE4
gUnknown_80E2AE4: @ 80E2AE4
.string "Please connect a {COLOR_1 LIGHT_BLUE_2}Link Cable{END_COLOR_TEXT_1}.\n"
.string "When your friend{APOSTROPHE}s side is ready{COMMA} you may\n"
.string "communicate and exchange data.\0"
.align 2,0

	.global gUnknown_80E2B54
gUnknown_80E2B54: @ 80E2B54
.string "Your {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} was sent.\n"
.string "Your adventure will be saved.\0"
.align 2,0

	.global gUnknown_80E2B90
gUnknown_80E2B90: @ 80E2B90
.string "Using a {COLOR_1 LIGHT_BLUE_2}Game Link cable{END_COLOR_TEXT_1}{COMMA}\n"
.string "you can send a {COLOR_1 LIGHT_BLUE_2}helper Pokémon{END_COLOR_TEXT_1} to\n"
.string "a friend.\0"
.align 2,0

	.global gUnknown_80E2BE0
gUnknown_80E2BE0: @ 80E2BE0
.string "Your own Pokémon will not disappear\n"
.string "if you send it as a helper.\n"
.string "Will you send a helper to your friend?\0"
.align 2,0

	.global gUnknown_80E2C48
gUnknown_80E2C48: @ 80E2C48
.string "Pick the Pokémon to be sent as a helper.\n"
.string "(Any hold item will not be sent.)\0"
.align 2,0

	.global gUnknown_80E2C94
gUnknown_80E2C94: @ 80E2C94
.string "No Pokémon are in your Friend Areas.\n"
.string "What would you like to do?\0"
.align 2,0

	.global gUnknown_80E2CD4
gUnknown_80E2CD4: @ 80E2CD4
.string "Is this Pokémon OK?\0"
.align 2,0

	.global gUnknown_80E2CE8
gUnknown_80E2CE8: @ 80E2CE8
.string "Please choose the {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} that should\n"
.string "be sent to your friend.\0"
.align 2,0

	.global gUnknown_80E2D30
gUnknown_80E2D30: @ 80E2D30
.string "This {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} will be sent.\n"
.string "Is that OK?\0"
.align 2,0

	.global gUnknown_80E2D60
gUnknown_80E2D60: @ 80E2D60
        .string "There is no {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E2D7C
gUnknown_80E2D7C: @ 80E2D7C
.string "Connect the {COLOR_1 LIGHT_BLUE_2}Game Link cable{END_COLOR_TEXT_1}.\n"
.string "When your friend is ready{COMMA} begin\n"
.string "communication.\0"
.align 2,0

	.global gUnknown_80E2DD0
gUnknown_80E2DD0: @ 80E2DD0
.string "#+Communicating...\n"
.string "#+Please wait with the power on.\n"
.string "#+To cancel{COMMA} press {B_BUTTON}.\0"
.align 2,0

	.global gUnknown_80E2E20
gUnknown_80E2E20: @ 80E2E20
.string "The GBA Game Pak will be written to.\n"
.string "Is that OK?\0"
.align 2,0

	.global gUnknown_80E2E54
gUnknown_80E2E54: @ 80E2E54
.string "#+Reading from GBA Game Pak.\n"
.string "#+Do not remove the GBA Game Pak.\n"
.string "#+Please wait with the power on.\0"
.align 2,0

	.global gUnknown_80E2EB4
gUnknown_80E2EB4: @ 80E2EB4
.string "#+Writing to GBA Game Pak.\n"
.string "#+Do not remove the GBA Game Pak.\n"
.string "#+Please wait with the power on.\0"
.align 2,0

	.global gUnknown_80E2F14
gUnknown_80E2F14: @ 80E2F14
.string "There is no {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} on\n"
.string "the GBA Game Pak.\0"
.align 2,0

	.global gUnknown_80E2F44
gUnknown_80E2F44: @ 80E2F44
.string "Please choose an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}\n"
.string "on the GBA Game Pak.\0"
.align 2,0

	.global gUnknown_80E2F78
gUnknown_80E2F78: @ 80E2F78
.string "Is it OK to accept this {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}?\0"
.align 2,0

	.global gUnknown_80E2FA0
gUnknown_80E2FA0: @ 80E2FA0
.string "There is no more space for accepting\n"
.string "new mail.\n"
.string "You must delete old mail.\0"
.align 2,0

	.global gUnknown_80E2FEC
gUnknown_80E2FEC: @ 80E2FEC
.string "The {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} has been received.\n"
.string "Your adventure will be saved.\0"
.align 2,0

	.global gUnknown_80E3030
gUnknown_80E3030: @ 80E3030
.string "Please embark on your rescue mission\n"
.string "from the Pelipper Post Office. \0"
.align 2,0

	.global gUnknown_80E3078
gUnknown_80E3078: @ 80E3078
.string "Please enter the {COLOR_1 LIGHT_BLUE_2}SOS Mail password{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E30A4
gUnknown_80E30A4: @ 80E30A4
.string "Is it OK to send this {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}?\0"
.align 2,0

	.global gUnknown_80E30D0
gUnknown_80E30D0: @ 80E30D0
.string "Please choose the {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} that\n"
.string "should be sent to your friend.\0"
.align 2,0

	.global gUnknown_80E311C
gUnknown_80E311C: @ 80E311C
.string "Please enter the {COLOR_1 LIGHT_BLUE_2}Thank-You Mail password{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E314C
gUnknown_80E314C: @ 80E314C
.string "The {COLOR_1 LIGHT_BLUE_2}Thank-You Mail password{END_COLOR_TEXT_1} will be\n"
.string "shown.\0"
.align 2,0

	.global gUnknown_80E317C
gUnknown_80E317C: @ 80E317C
        .string "Your adventure will be saved.\0"
        .align 2,0

	.global gUnknown_80E319C
gUnknown_80E319C: @ 80E319C
        .string "Steps will now be taken to receive the\n"
        .string "{COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E31D8
gUnknown_80E31D8: @ 80E31D8
        .string "All preparations have been made.\0"
        .align 2,0

	.global gUnknown_80E31FC
gUnknown_80E31FC: @ 80E31FC
        .string "The {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} was sent.\0"
        .align 2,0

	.global gUnknown_80E3220
gUnknown_80E3220: @ 80E3220
        .string "You received the {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E3248
gUnknown_80E3248: @ 80E3248
        .string "The {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} was sent.\n"
        .string "Your adventure will be saved.\0"
        .align 2,0

	.global gUnknown_80E3288
gUnknown_80E3288: @ 80E3288
        .string "Steps will now be taken to send your\n"
        .string "{COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E32C4
gUnknown_80E32C4: @ 80E32C4
        .string "OK. You{APOSTROPHE}re good to go.\n"
        .string "{COLOR_1 YELLOW_5}%s{END_COLOR_TEXT_1}{COMMA} I hope your sense of\n"
        .string "gratitude reaches your friend.\0"
        .align 2,0

	.global gUnknown_80E331C
gUnknown_80E331C: @ 80E331C
        .string "The item chosen here can{APOSTROPHE}t be exchanged\n"
        .string "with anything else.\n"
        .string "Are you sure this item is OK?\0"
        .align 2,0

	.global gUnknown_80E3378
gUnknown_80E3378: @ 80E3378
        .string "Please choose the item to be sent.\0"
        .align 2,0

	.global gUnknown_80E339C
gUnknown_80E339C: @ 80E339C
.string "There are no items in storage.\n"
.string "What would you like to do?\0"
.align 2,0

	.global gUnknown_80E33D8
gUnknown_80E33D8: @ 80E33D8
.string "Would you like to choose\n"
.string "a {COLOR_1 LIGHT_BLUE_2}reward item{END_COLOR_TEXT_1} from storage and\n"
.string "send it with your mail?\0"
.align 2,0

	.global gUnknown_80E3430
gUnknown_80E3430: @ 80E3430
.string "This mail already has an attached\n"
.string "{COLOR_1 LIGHT_BLUE_2}reward item{END_COLOR_TEXT_1}.#POnce an item has been chosen{COMMA} it may not\n"
.string "be exchanged with another item.\0"
.align 2,0

	.global gUnknown_80E34B0
gUnknown_80E34B0: @ 80E34B0
.string "Would you like to resend the mail\n"
.string "with the same item attached?\0"
.align 2,0

	.global gUnknown_80E34F0
gUnknown_80E34F0: @ 80E34F0
.string "Please select a {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}\n"
.string "from the GBA Game Pak.\0"
.align 2,0

	.global gUnknown_80E352C
gUnknown_80E352C: @ 80E352C
        .string "Is it OK to accept this {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E355C
gUnknown_80E355C: @ 80E355C
        .string "Mail can{APOSTROPHE}t be sent to a GBA Game Pak\n"
        .string "with the game quicksaved in a dungeon.\0"
        .align 2,0

	.global gUnknown_80E35AC
gUnknown_80E35AC: @ 80E35AC
        .string "The GBA Game Pak does not have\n"
        .string "a {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} on it.\0"
        .align 2,0

	.global gUnknown_80E35E8
gUnknown_80E35E8: @ 80E35E8
        .string "There is no {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E360C
gUnknown_80E360C: @ 80E360C
        .string "How would you like to send\n"
        .string "your {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E3644
gUnknown_80E3644: @ 80E3644
        .string "How would you like to receive\n"
        .string "the {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}?\0"
        .align 2,0

	.global gUnknown_80E367C
gUnknown_80E367C: @ 80E367C
        .string "Read which Info?\0"
        .align 2,0

	.global gUnknown_80E3690
gUnknown_80E3690: @ 80E3690
.string "If your team is defeated and in need\n"
.string "of rescuing{COMMA} send an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}\n"
.string "to a friend.#POnce you send your mail{COMMA} you must wait\n"
.string "for your friend to send you\n"
.string "an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.#PIf the {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} arrives{COMMA} your\n"
.string "team can be revived to resume exploring\n"
.string "the dungeon it was in.#PWhen your team is revived{COMMA} don{APOSTROPHE}t forget\n"
.string "to send a {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} to the friend\n"
.string "who came to your rescue.\0"
.align 2,0

	.global gUnknown_80E3818
gUnknown_80E3818: @ 80E3818
.string "If your team is defeated in\n"
.string "a dungeon{COMMA} you may send a friend\n"
.string "an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} for help.#PHowever{COMMA} there are some places\n"
.string "where it is impossible for you to\n"
.string "call for a rescue.#PAlso{COMMA} if you send an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}{COMMA}\n"
.string "you may not continue with your\n"
.string "adventure while awaiting rescue.#PIf you cannot wait to be rescued{COMMA}\n"
.string "you will have to give up and return\n"
.string "to your rescue team base.\0"
.align 2,0

	.global gUnknown_80E3998
gUnknown_80E3998: @ 80E3998
.string "If your friend successfully rescues\n"
.string "your team{COMMA} accept your friend{APOSTROPHE}s\n"
.string "{COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.#POnce the {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} is received{COMMA}\n"
.string "you may revive your team and resume\n"
.string "exploring the dungeon you were in.#PUsing a {COLOR_1 LIGHT_BLUE_2}Game Link cable{END_COLOR_TEXT_1}{COMMA}\n"
.string "your friend can also send you\n"
.string "a {COLOR_1 LIGHT_BLUE_2}helper Pokémon{END_COLOR_TEXT_1}.#PHowever{COMMA} the {COLOR_1 LIGHT_BLUE_2}helper Pokémon{END_COLOR_TEXT_1} will not\n"
.string "be able to bring an item with it when\n"
.string "joining your team.\0"
.align 2,0

	.global gUnknown_80E3B1C
gUnknown_80E3B1C: @ 80E3B1C
.string "If your team has been rescued{COMMA} be sure\n"
.string "to send a {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} to the friend\n"
.string "that came to your help.#PYou may also attach a {COLOR_1 LIGHT_BLUE_2}reward item{END_COLOR_TEXT_1}\n"
.string "from storage to your {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}\n"
.string "and send it to your friend.\0"
.align 2,0

	.global gUnknown_80E3BF8
gUnknown_80E3BF8: @ 80E3BF8
.string "If your friend{APOSTROPHE}s team needs rescuing{COMMA}\n"
.string "you must first receive an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}\n"
.string "from your friend.#PWhen you get the mail{COMMA} you may embark\n"
.string "on your rescue mission from the\n"
.string "{COLOR_1 LIGHT_BLUE_2}Pelipper Post Office{END_COLOR_TEXT_1}.#PIf you rescue your friend{APOSTROPHE}s defeated\n"
.string "team{COMMA} send an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1} to your\n"
.string "friend.#PIf you rescue a friend{COMMA} you will be eligible\n"
.string "to receive a {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.#PIf you have quicksaved inside a dungeon{COMMA}\n"
.string "you may not choose {COLOR_1 LIGHT_BLUE_2}Go Rescue{END_COLOR_TEXT_1}.\n"
.string "Your last save must be out of a dungeon.\0"
.align 2,0

	.global gUnknown_80E3DE4
gUnknown_80E3DE4: @ 80E3DE4
.string "You may receive an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1} from\n"
.string "a friend{APOSTROPHE}s team that lies defeated in\n"
.string "a dungeon.#PIf there is no space for new mail{COMMA} delete\n"
.string "old mail at the {COLOR_1 LIGHT_BLUE_2}Pelipper Post Office{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E3E98
gUnknown_80E3E98: @ 80E3E98
.string "If you successfully rescue your friend{APOSTROPHE}s\n"
.string "team{COMMA} send your friend an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.#PUsing a {COLOR_1 LIGHT_BLUE_2}Game Link cable{END_COLOR_TEXT_1}{COMMA} you may\n"
.string "also send your friend a Pokémon from\n"
.string "your Friend Area as a helper.#PDon{APOSTROPHE}t worry--sending a Pokémon as\n"
.string "a helper will not make it disappear from\n"
.string "its Friend Area.#PIf there is no space for new mail{COMMA} delete\n"
.string "old mail at the {COLOR_1 LIGHT_BLUE_2}Pelipper Post Office{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E4014
gUnknown_80E4014: @ 80E4014
.string "When you receive an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}{COMMA}\n"
.string "you may embark on your rescue mission\n"
.string "from the {COLOR_1 LIGHT_BLUE_2}Pelipper Post Office{END_COLOR_TEXT_1}.#PBeware--if you do not have access to\n"
.string "the dungeon they are in{COMMA} you may not go\n"
.string "on a rescue mission there.#PAccept challenging rescues only\n"
.string "if you are ready and qualified!\0"
.align 2,0

	.global gUnknown_80E4130
gUnknown_80E4130: @ 80E4130
.string "If you send an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}{COMMA} you may\n"
.string "receive a {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} in return\n"
.string "from your friend.#PThe {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1} may also come\n"
.string "with a {COLOR_1 LIGHT_BLUE_2}reward item{END_COLOR_TEXT_1} attached.\0"
.align 2,0

	.global gUnknown_80E41DC
gUnknown_80E41DC: @ 80E41DC
.string "Using the {COLOR_1 LIGHT_BLUE_2}Dual Slot{END_COLOR_TEXT_1} function{COMMA}\n"
.string "you may perform rescue operations with\n"
.string "friends using the GBA Game Pak version.#PInsert the DS Game Card and the GBA\n"
.string "Game Pak in your Nintendo DS system{COMMA}\n"
.string "then turn on the power.#PFriend Rescue missions using\n"
.string "the {COLOR_1 LIGHT_BLUE_2}Dual Slot{END_COLOR_TEXT_1} function will be\n"
.string "available on the main menu. \0"
.align 2,0

	.global gUnknown_80E4314
gUnknown_80E4314: @ 80E4314
.string "Friends can rescue each other{APOSTROPHE}s defeated\n"
.string "teams using a {COLOR_1 LIGHT_BLUE_2}Game Link cable{END_COLOR_TEXT_1}{COMMA}\n"
.string "{COLOR_1 LIGHT_BLUE_2}passwords{END_COLOR_TEXT_1}{COMMA} and so on.#PYou may go on a rescue mission to save\n"
.string "your friend{APOSTROPHE}s team that has been defeated\n"
.string "in a dungeon.#POr{COMMA} you may call for help from a friend\n"
.string "to save your fallen team in a dungeon.#PUsing {COLOR_1 LIGHT_BLUE_2}passwords{END_COLOR_TEXT_1}{COMMA} you can even\n"
.string "exchange help with faraway friends.\0"
.align 2,0


	.global gUnknown_80E4480
gUnknown_80E4480: @ 80E4480
        .string "There was a communication error.\0"
        .align 2,0

	.global gUnknown_80E44A4
gUnknown_80E44A4: @ 80E44A4
.string "An incorrect number of GBA systems are\n"
.string "connected.\n"
.string "Please redo this process from the start.\0"
.align 2,0

	.global gUnknown_80E4500
gUnknown_80E4500: @ 80E4500
.string "There is no response from your friend.\n"
.string "Please redo this process from the start.\0"
.align 2,0

	.global gUnknown_80E4550
gUnknown_80E4550: @ 80E4550
.string "The sender and receiver appear to be\n"
.string "in different modes.\n"
.string "Please redo the process from the start.\0"
.align 2,0

	.global gUnknown_80E45B4
gUnknown_80E45B4: @ 80E45B4
.string "Your storage space is full.\n"
.string "Please make room{COMMA} then redo the\n"
.string "process from the start.\0"
.align 2,0

	.global gUnknown_80E460C
gUnknown_80E460C: @ 80E460C
.string "This mail has been received before.\n"
.string "It cannot be received again.\0"
.align 2,0

	.global gUnknown_80E4650
gUnknown_80E4650: @ 80E4650
.string "This mail has been sent already.\n"
.string "It cannot be sent again.\0"
.align 2,0

	.global gUnknown_80E468C
gUnknown_80E468C: @ 80E468C
.string "You do not appear eligible to receive\n"
.string "this {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E46C8
gUnknown_80E46C8: @ 80E46C8
.string "Your friend is not eligible to receive\n"
.string "this {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E4704
gUnknown_80E4704: @ 80E4704
.string "You do not appear eligible to receive\n"
.string "this {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E4744
gUnknown_80E4744: @ 80E4744
.string "Your friend is not eligible to receive\n"
.string "this {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E4788
gUnknown_80E4788: @ 80E4788
.string "Something went wrong.\n"
.string "Please turn off the power and\n"
.string "reinsert the GBA Game Pak.\0"
.align 2,0

	.global gUnknown_80E47D8
gUnknown_80E47D8: @ 80E47D8
.string "There is no space for receiving new\n"
.string "mail.\n"
.string "Please delete old mail{COMMA} then try again.\0"
.align 2,0

	.global gUnknown_80E482C
gUnknown_80E482C: @ 80E482C
.string "There is no response from your friend.\n"
.string "Please make sure the sender and receiver\n"
.string "are ready{COMMA} then redo this from the start.\0"
.align 2,0

	.global gUnknown_80E48A8
gUnknown_80E48A8: @ 80E48A8
.string "This password is incorrect.\n"
.string "Would you like to enter it again?\0"
.align 2,0

	.global gUnknown_80E48E8
gUnknown_80E48E8: @ 80E48E8
.string "This password does not appear to be\n"
.string "that of an {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E4928
gUnknown_80E4928: @ 80E4928
.string "Received the {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}.\n"
.string "Your adventure will be saved.\0"
.align 2,0

	.global gUnknown_80E4964
gUnknown_80E4964: @ 80E4964
.string "This password does not appear to be\n"
.string "an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.\0"
.align 2,0

	.global gUnknown_80E499C
gUnknown_80E499C: @ 80E499C
.string "This password can no longer be used.\0"
.align 2,0

	.global gUnknown_80E49C4
gUnknown_80E49C4: @ 80E49C4
.string "This password does not appear to be\n"
.string "that of a {COLOR_1 LIGHT_BLUE_2}Thank-You Mail{END_COLOR_TEXT_1}.\0"
.align 2,0
.string "pksdir0\0"
.align 2,0


	.global gUnknown_80E4A10
gUnknown_80E4A10: @ 80E4A10
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E4A28
gUnknown_80E4A28: @ 80E4A28
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E4A40
gUnknown_80E4A40: @ 80E4A40
        .byte 0x18, 0x18
        .byte 0x38, 0x00
        .byte 0x21, 0xff
        .byte 0x22, 0xff
        .byte 0x23, 0xff
        .byte 0x24, 0xff
        .byte 0x25, 0xff
        .byte 0x26, 0xff
        .byte 0x27, 0xff
        .byte 0x28, 0xff
        .byte 0x29, 0xff
        .byte 0x2a, 0xff
        .byte 0x2b, 0xff
        .byte 0x2c, 0xff
        .byte 0x2d, 0xff
        .byte 0x2e, 0xff
        .byte 0x2f, 0xff
        .byte 0x30, 0xff
        .byte 0x31, 0xff
        .byte 0x32, 0xff
        .byte 0x33, 0xff
        .byte 0x34, 0xff
        .byte 0x35, 0xff
        .byte 0x36, 0xff
        .byte 0x37, 0xff
        .byte 0x38, 0xff
        .byte 0x39, 0xff
        .byte 0x3a, 0xff
        .byte 0x41, 0xff
        .byte 0x42, 0xff
        .byte 0x43, 0xff
        .byte 0x44, 0xff
        .byte 0x45, 0xff
        .byte 0x46, 0xff
        .byte 0x47, 0xff
        .byte 0x48, 0xff
        .byte 0x49, 0xff
        .byte 0x4a, 0xff
        .byte 0x4b, 0xff
        .byte 0x4c, 0xff
        .byte 0x4d, 0xff
        .byte 0x4e, 0xff
        .byte 0x4f, 0xff
        .byte 0x50, 0xff
        .byte 0x51, 0xff
        .byte 0x52, 0xff
        .byte 0x53, 0xff
        .byte 0x54, 0xff
        .byte 0x55, 0xff
        .byte 0x56, 0xff
        .byte 0x57, 0xff
        .byte 0x58, 0xff
        .byte 0x59, 0xff
        .byte 0x5a, 0xff
        .byte 0x10, 0xff
        .byte 0x11, 0xff
        .byte 0x12, 0xff
        .byte 0x13, 0xff
        .byte 0x14, 0xff
        .byte 0x15, 0xff
        .byte 0x16, 0xff
        .byte 0x17, 0xff
        .byte 0x18, 0xff
        .byte 0x19, 0xff

        .include "data/text/credits.inc"

	.global gUnknown_80E5990
gUnknown_80E5990: @ 80E5990
        .byte 0x06, 0x02
        .byte 0x40, 0x00
        .byte 0x80, 0x00
        .byte 0x10, 0x00
        .byte 0x20, 0x00
        .byte 0x01, 0x00
        .byte 0x02, 0x00
        .byte 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

