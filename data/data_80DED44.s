        .section .rodata

	.global gPelipperBoard_BulletinBoard
gPelipperBoard_BulletinBoard: @ 80E0390
        .string "Bulletin Board\0"
        .align 2,0

	.global gPelipperBoard_JobList
gPelipperBoard_JobList: @ 80E03A0
        .string "Job List\0"
        .align 2,0

	.global gPelipperBoard_Accepted
gPelipperBoard_Accepted: @ 80E03AC
        .string "Accepted\0"
        .align 2,0

	.global gUnknown_80E03B8
gUnknown_80E03B8: @ 80E03B8
        .string "/\0"
        .align 2,0
        .string "pksdir0\0"

	.global gUnknown_80E03C4
gUnknown_80E03C4: @ 80E03C4
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
        .string " Here{APOSTROPHE}s your reward!\n"
        .string "{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}!\0"
        .align 2,0

	.global gUnknown_80E045C
gUnknown_80E045C: @ 80E045C
@ replacing .incbin "baserom.gba", 0x000e045c, 0x28
        .string "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1} received\n"
        .string "{CENTER_ALIGN}{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1}"
        .byte 0x20, 0x83
        .byte 0xbf, 0x83, 0xc4, 0x2e, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E0484
gUnknown_80E0484: @ 80E0484
        .string "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s team received\n"
        .string "{CENTER_ALIGN}{COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} {POKE}"
        .byte 0x2E, 0x00, 0x00, 0x00

	.global gUnknown_80E04B4
gUnknown_80E04B4: @ 80E04B4
        .string " As your reward{COMMA} you can\n"
        .string "now go to the Friend Area\n"
        .string "{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gUnknown_80E04F4
gUnknown_80E04F4: @ 80E04F4
        .string "{CENTER_ALIGN}...Oh{COMMA} wait{COMMA} sorry.{EXTRA_MSG}"
        .string "{CENTER_ALIGN}You already have the \n"
        .string "{CENTER_ALIGN}{COLOR_1 GREEN}{ARG_FRIEND_AREA} Friend Area{END_COLOR_TEXT_1}.{EXTRA_MSG}"
        .string "{CENTER_ALIGN}I{APOSTROPHE}m sorry that my reward is\n"
        .string "{CENTER_ALIGN}something you already have.{EXTRA_MSG}"
        .string "{CENTER_ALIGN}In its place{COMMA} {COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{COMMA}\n"
        .string "{CENTER_ALIGN}you can have {COLOR_1 LIGHT_BLUE_2}1{COMMA}000{END_COLOR_TEXT_1} {POKE}.\0"
        .align 2, 0

	.global gUnknown_80E05C0
gUnknown_80E05C0: @ 80E05C0
        .string "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1} gained access\n"
        .string "{CENTER_ALIGN}to the Friend Area\n"
        .string "{CENTER_ALIGN}{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E05FC
gUnknown_80E05FC: @ 80E05FC
        .string "{CENTER_ALIGN}{COLOR_1 YELLOW_5}{ARG_POKEMON_0}{END_COLOR_TEXT_1}{APOSTROPHE}s team gained access\n"
        .string "{CENTER_ALIGN}to the Friend Area\n"
        .string "{CENTER_ALIGN}{COLOR_1 GREEN}{ARG_FRIEND_AREA}{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E0640
gUnknown_80E0640: @ 80E0640
        .string " Here{APOSTROPHE}s your reward!\n"
        .string "The promised {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gUnknown_80E0670
gUnknown_80E0670: @ 80E0670
        .string "{CENTER_ALIGN}Rescue Team {COLOR_1 LIGHT_BLUE_2}$t{END_COLOR_TEXT_1}\n"
        .string "{CENTER_ALIGN}gained {COLOR_1 CYAN}$d0{END_COLOR_TEXT_1} rescue points.\0"
        .align 2,0

	.global gUnknown_80E06A8
gUnknown_80E06A8: @ 80E06A8
        .string "{CENTER_ALIGN}Congratulations!{EXTRA_MSG}"
        .string "{CENTER_ALIGN}{COLOR_1 LIGHT_BLUE_2}$t{END_COLOR_TEXT_1} went up in rank\n"
        .string "{CENTER_ALIGN}from the {ARG_POKEMON_2}\n"
        .string "{CENTER_ALIGN}to the {ARG_POKEMON_3}!\0"
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
        .string "{CENTER_ALIGN}{COLOR_1 YELLOW_5}$n0{END_COLOR_TEXT_1} received the {COLOR_1 GREEN_2}Bonsly Doll{END_COLOR_TEXT_1}!\n"
        .string "{CENTER_ALIGN}It has been placed outside your\n"
        .string "{CENTER_ALIGN}rescue team base.\0"
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
        .string "{COLOR_2}%c%s{END_COLOR_TEXT_2}\0"
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
        .string "OK{APOSTROPHE}d Rescues\0"
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
        .string " ...Uh{COMMA} no?\n"
        .string "You don{APOSTROPHE}t have any {COLOR_1 LIGHT_BLUE_2}SOS Mail{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E0A0C
gUnknown_80E0A0C: @ 80E0A0C
        .string " ...Uh{COMMA} no?\n"
        .string "You don{APOSTROPHE}t have any {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.\0"
        .align 2,0
        .asciz "pksdir0"
