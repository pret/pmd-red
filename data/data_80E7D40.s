        .section .rodata

	.global gUnknown_80E7E34
gUnknown_80E7E34: @ 80E7E34
@ replacing .incbin "baserom.gba", 0x000e7e34, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7E4C
gUnknown_80E7E4C: @ 80E7E4C
@ replacing .incbin "baserom.gba", 0x000e7e4c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7E64
gUnknown_80E7E64: @ 80E7E64
@ replacing .incbin "baserom.gba", 0x000e7e64, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x14, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gDebug_NumberText
gDebug_NumberText: @ 80E7E7C
        .string "Number?\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7E8C
gUnknown_80E7E8C: @ 80E7E8C
@ replacing .incbin "baserom.gba", 0x000e7e8c, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7EA4
gUnknown_80E7EA4: @ 80E7EA4
@ replacing .incbin "baserom.gba", 0x000e7ea4, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.global gDebug_CloseText
gDebug_CloseText: @ 80E7EBC
        .string "CLOSE\0"
        .align 2,0

	.global gDebug_OpenText
gDebug_OpenText: @ 80E7EC4
        .string "OPEN\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7ED4
gUnknown_80E7ED4: @ 80E7ED4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7EEC
gUnknown_80E7EEC: @ 80E7EEC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x04, 0x00
        .byte 0x09, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7F04
gUnknown_80E7F04: @ 80E7F04
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x13, 0x00, 0x0e, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gDebug_NumberText2
gDebug_NumberText2: @ 80E7F1C
        .string "Number?\0"
        .align 2,0

	.global gDebug_LevelText
gDebug_LevelText: @ 80E7F24
        .string "LEVEL\0"
        .align 2,0

	.global gUnknown_80E7F2C
gUnknown_80E7F2C: @ 80E7F2C
        .string "Name\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7F3C
gUnknown_80E7F3C: @ 80E7F3C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7F54
gUnknown_80E7F54: @ 80E7F54
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x11, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7F6C
gUnknown_80E7F6C: @ 80E7F6C
        .string "Script\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E7F94
gUnknown_80E7F94: @ 80E7F94
	.incbin "baserom.gba", 0xE7F94, 0x10C

	.global gUnknown_80E80A0
gUnknown_80E80A0: @ 80E80A0
	.incbin "baserom.gba", 0xE80A0, 0x40

	.global gUnknown_80E80E0
gUnknown_80E80E0: @ 80E80E0
	.incbin "baserom.gba", 0xE80E0, 0x46

	.global gUnknown_80E8126
gUnknown_80E8126: @ 80E8126
	.incbin "baserom.gba", 0xE8126, 0x42

	.global gUnknown_80E8168
gUnknown_80E8168: @ 80E8168
	.incbin "baserom.gba", 0xE8168, 0x18

	.global gUnknown_80E8180
gUnknown_80E8180: @ 80E8180
	.incbin "baserom.gba", 0xE8180, 0x54

	.global gUnknown_80E81D4
gUnknown_80E81D4: @ 80E81D4
	.incbin "baserom.gba", 0xE81D4, 0x608

	.global gMankeyMission
gMankeyMission: @ 80E87DC
        .string "Punish bad {COLOR_1 YELLOW}Mankey{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gSmeargleMission
gSmeargleMission: @ 80E87F4
        .string "{COLOR_1 YELLOW}Smeargle{END_COLOR_TEXT_1}{APOSTROPHE}s desperate plea!\0"
        .align 2,0

	.global gMedichamMission
gMedichamMission: @ 80E8818
        .string "{COLOR_1 YELLOW}Medicham{END_COLOR_TEXT_1}: Help me!\0"
        .align 2,0

	.global gUnknown_80E8830
gUnknown_80E8830: @ 80E8830
        .string "Deliver one {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8848
gUnknown_80E8848: @ 80E8848
        .string "One {COLOR_1 GREEN}%s{END_COLOR_TEXT_1} wanted!\0"
        .align 2,0

	.global gUnknown_80E885C
gUnknown_80E885C: @ 80E885C
        .string "Save my child!\0"
        .align 2,0

	.global gUnknown_80E886C
gUnknown_80E886C: @ 80E886C
        .string "Escort me to my love!\0"
        .align 2,0

	.global gUnknown_80E8884
gUnknown_80E8884: @ 80E8884
        .string "Near %s\0"
        .align 2,0

	.global gUnknown_80E888C
gUnknown_80E888C: @ 80E888C
        .string "Rescue Description\0"
        .align 2,0

	.global gMankeyMissionDescription
gMankeyMissionDescription: @ 80E88A0
        .string "Please punish bad {COLOR_1 YELLOW}Mankey{END_COLOR_TEXT_1}{APOSTROPHE}s gang.\0"
        .align 2,0

	.global gSmeargleMissionDescription
gSmeargleMissionDescription: @ 80E88C8
        .string "I didn{APOSTROPHE}t want to become a grown-up{COMMA} so I\n"
        .string "fled{COMMA} but now I{APOSTROPHE}ve lost my way! Help!\0"
        .align 2,0

	.global gMedichamMissionDescription
gMedichamMissionDescription: @ 80E8920
        .string "This is {COLOR_1 YELLOW}Medicham{END_COLOR_TEXT_1}. Rescue me{COMMA} please!\n"
        .string "The reward is a secret"
        .byte 0x81, 0x60
        .string "♪ "
        .align 2,0

	.global gUnknown_80E8968
gUnknown_80E8968: @ 80E8968
        .string "With the item {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}{COMMA} I can\n"
        .string "evolve! I{APOSTROPHE}m yearning to evolve! Help!\0"
        .align 2,0

	.global gUnknown_80E89B0
gUnknown_80E89B0: @ 80E89B0
        .string "The {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}! What I love to eat\n"
        .string "and can{APOSTROPHE}t live without! Please get one!\0"
        .align 2,0

	.global gUnknown_80E89FC
gUnknown_80E89FC: @ 80E89FC
        .string "This is a rescue through communication.\n"
        .string "Get a friend to help you!\0"
        .align 2,0

	.global gUnknown_80E8A40
gUnknown_80E8A40: @ 80E8A40
        .string "This is a rescue through communication.\n"
        .string "Rescue a friend!\0"
        .align 2,0

	.global gUnknown_80E8A7C
gUnknown_80E8A7C: @ 80E8A7C
        .string "This is a rescue through communication.\n"
        .string "Send your thanks to your friend!\0"
        .align 2,0

	.global gUnknown_80E8AC8
gUnknown_80E8AC8: @ 80E8AC8
        .string "Client:\0"
        .align 2,0

	.global gUnknown_80E8AD0
gUnknown_80E8AD0: @ 80E8AD0
        .string "%s{COLOR_1 GREEN}"
        .byte 0x81
        .string "i%s"
        .byte 0x81
        .string "j{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80E8AE0
gUnknown_80E8AE0: @ 80E8AE0
        .string "Objective:\0"
        .align 2,0

	.global gUnknown_80E8AEC
gUnknown_80E8AEC: @ 80E8AEC
        .string "Friend Rescue\0"
        .align 2,0

	.global gUnknown_80E8AFC
gUnknown_80E8AFC: @ 80E8AFC
        .string "Deliver {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8B10
gUnknown_80E8B10: @ 80E8B10
        .string "Find {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8B20
gUnknown_80E8B20: @ 80E8B20
        .string "Help me.\0"
        .align 2,0

	.global gUnknown_80E8B2C
gUnknown_80E8B2C: @ 80E8B2C
        .string "Escort to {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8B40
gUnknown_80E8B40: @ 80E8B40
        .string "Find {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gSpecialMissionText
gSpecialMissionText: @ 80E8B50
        .string "Special mission\0"
        .align 2,0

	.global gPlaceText
gPlaceText: @ 80E8B60
        .string "Place:\0"
        .align 2,0

	.global gDifficultyText
gDifficultyText: @ 80E8B68
        .string "Difficulty:\0"
        .align 2,0

	.global gRewardText
gRewardText: @ 80E8B74
        .string "Reward:\0"
        .align 2,0

	.global gUnknown_80E8B7C
gUnknown_80E8B7C: @ 80E8B7C
        .string "Wonder Mail:\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E8B94
gUnknown_80E8B94: @ 80E8B94
@ replacing .incbin "baserom.gba", 0x000e8b94, 0x38
        .4byte UnkData_80E8BC8
        .4byte UnkData_80E8BC4
        .4byte UnkData_80E8BC0
        .4byte UnkData_80E8BBC
        .4byte UnkData_80E8BB8
        .4byte UnkData_80E8BB4
        .4byte UnkData_80E8BB0

        .global UnkData_80E8BB0
        UnkData_80E8BB0:
        .byte 0x83, 0xc3, 0x00, 0x00

        .global UnkData_80E8BB4
        UnkData_80E8BB4:
        .byte 0x83, 0xc2, 0x00, 0x00

        .global UnkData_80E8BB8
        UnkData_80E8BB8:
        .byte 0x83, 0xc1, 0x00, 0x00

        .global UnkData_80E8BBC
        UnkData_80E8BBC:
        .byte 0x83, 0xc0, 0x00, 0x00

        .global UnkData_80E8BC0
        UnkData_80E8BC0:
        .byte 0x87, 0x40, 0x00, 0x00

        .global UnkData_80E8BC4
        UnkData_80E8BC4:
        .byte 0x84, 0x87, 0x00, 0x00

        .global UnkData_80E8BC8
        UnkData_80E8BC8:
        .byte 0x81, 0x40, 0x00, 0x00


	.global gUnknown_80E8BCC
gUnknown_80E8BCC: @ 80E8BCC
        .4byte UnkData_80E8BC8
        .4byte SuspendText
        .4byte TakeJobText
        .4byte DoneText

        .global DoneText
        DoneText:
        .string "Done\0"
        .align 2,0

        .global TakeJobText
        TakeJobText:
        .string "Take Job\0"
        .align 2,0

        .global SuspendText
        SuspendText:
        .string "Suspend\0"
        .align 2,0

	.global gUnknown_80E8BF8
gUnknown_80E8BF8: @ 80E8BF8
	.incbin "baserom.gba", 0xE8BF8, 0x50

	.global gMissionRewardText
gMissionRewardText: @ 80E8C48
	.incbin "baserom.gba", 0xE8C48, 0x50

	.global gUnknown_80E8C98
gUnknown_80E8C98: @ 80E8C98
	.incbin "baserom.gba", 0xE8C98, 0x14C

	.global gUnknown_80E8DE4
gUnknown_80E8DE4: @ 80E8DE4
	.incbin "baserom.gba", 0xE8DE4, 0x1CC

	.global gUnknown_80E8FB0
gUnknown_80E8FB0: @ 80E8FB0
	.incbin "baserom.gba", 0xE8FB0, 0x15C

	.global gUnknown_80E910C
gUnknown_80E910C: @ 80E910C
	.incbin "baserom.gba", 0xE910C, 0xC8

	.global gUnknown_80E91D4
gUnknown_80E91D4: @ 80E91D4
	.incbin "baserom.gba", 0xE91D4, 0x64C

	.global gUnknown_80E9820
gUnknown_80E9820: @ 80E9820
	.incbin "baserom.gba", 0xE9820, 0x100

	.global gUnknown_80E9920
gUnknown_80E9920: @ 80E9920
	.incbin "baserom.gba", 0xE9920, 0x66C

	.global gUnknown_80E9F8C
gUnknown_80E9F8C: @ 80E9F8C
	.incbin "baserom.gba", 0xE9F8C, 0xED0

@ Escort Mission Text
	.global gUnknown_80EAE5C
gUnknown_80EAE5C: @ 80EAE5C
        .4byte TakeMe_Text
        .4byte WantToSee_Text
        .4byte TakeMeWith_Text
        .4byte EscortMe_Text


        .global EscortMe_Text
        EscortMe_Text:
        .asciz "Escort me!"
        .align 2,0

        .global TakeMeWith_Text
        TakeMeWith_Text:
        .asciz "Please take me with you!"
        .align 2,0

        .global WantToSee_Text
        WantToSee_Text:
        .string "I want to see {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}."
        .align 2,0

        .global TakeMe_Text
        TakeMe_Text:
        .asciz "Take me!"
        .align 2,0

	.global gUnknown_80EAEB8
gUnknown_80EAEB8: @ 80EAEB8
@ replacing .incbin "baserom.gba", 0x000eaeb8, 0x2e0
        .4byte WaitingForMe_80EB17C
        .4byte PromisedMeet_80EB158
        .4byte WantMeet_80EB138
        .4byte WorriedAbout_80EB118
        .4byte GoMyself_80EB0FC
        .4byte OwnPower_80EB0DC
        .4byte TooWeak_80EB0B4
        .4byte WaitingInDungeon_80EB090
        .4byte WaitingForever_80EB06C
        .4byte InTrouble_80EB048
        .4byte WantToHelp_80EB030
        .4byte HasntReturned_80EB014
        .4byte FaintedInside_80EAFF0
        .4byte SickWorry_80EAFD4
        .4byte LongTime_80EAFA4
        .4byte HaveToGo_80EAF94
        .4byte HaveToMeet_80EAF70
        .4byte MustMeet_80EAF4C
        .4byte Apologize_80EAF2C
        .4byte CloseFriends_80EAF08

        .global CloseFriends_80EAF08
	CloseFriends_80EAF08:
        .string "I{APOSTROPHE}m close friends with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!"
        .align 2,0

        .global Apologize_80EAF2C
	Apologize_80EAF2C:
        .string "I want to apologize to {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}."
        .align 2,0

        .global MustMeet_80EAF4C
	MustMeet_80EAF4C:
        .string "I don{APOSTROPHE}t care how--we must meet!\0"
        .align 2,0

        .global HaveToMeet_80EAF70
	HaveToMeet_80EAF70:
        .asciz "We have to meet--whatever it takes!"
        .align 2,0

        .global HaveToGo_80EAF94
	HaveToGo_80EAF94:
        .asciz "I have to go!"
        .align 2,0

        .global LongTime_80EAFA4
	LongTime_80EAFA4:
        .string "We haven{APOSTROPHE}t seen each other in a long time.\0"
        .align 2,0

        .global SickWorry_80EAFD4
	SickWorry_80EAFD4:
        .string "I{APOSTROPHE}m sick with worry...\0"
        .align 2,0

        .global FaintedInside_80EAFF0
	FaintedInside_80EAFF0:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} may have fainted inside..."
        .align 2,0

        .global HasntReturned_80EB014
	HasntReturned_80EB014:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} hasn{APOSTROPHE}t returned!\0"
        .align 2,0

        .global WantToHelp_80EB030
	WantToHelp_80EB030:
        .string "I want to help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global InTrouble_80EB048
	InTrouble_80EB048:
        .string "Hurry{COMMA} {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is in trouble...\0"
        .align 2,0

        .global WaitingForever_80EB06C
	WaitingForever_80EB06C:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} has been waiting forever...\0"
        .align 2,0

        .global WaitingInDungeon_80EB090
	WaitingInDungeon_80EB090:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is waiting in the dungeon.\0"
        .align 2,0

        .global TooWeak_80EB0B4
	TooWeak_80EB0B4:
        .string "I{APOSTROPHE}m too weak. It{APOSTROPHE}s not possible.\0"
        .align 2,0

        .global OwnPower_80EB0DC
	OwnPower_80EB0DC:
        .string "I can{APOSTROPHE}t go on my own power...\0"
        .align 2,0

        .global GoMyself_80EB0FC
	GoMyself_80EB0FC:
        .string "I can{APOSTROPHE}t go by myself...\0"
        .align 2,0

        .global WorriedAbout_80EB118
	WorriedAbout_80EB118:
        .string "I{APOSTROPHE}m worried about {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}...\0"
        .align 2,0

        .global WantMeet_80EB138
	WantMeet_80EB138:
        .string "I want to meet with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

        .global PromisedMeet_80EB158
	PromisedMeet_80EB158:
        .asciz "We promised to meet in the dungeon!"
        .align 2,0

        .global WaitingForMe_80EB17C
	WaitingForMe_80EB17C:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is waiting for me!\0"
        .align 2,0


	.global gUnknown_80EB198
gUnknown_80EB198: @ 80EB198
        .4byte PleaseTakeMeToSee
        .4byte PleaseTakeMeThere
        .4byte PleaseEscortMe
        .4byte SomeonePleaseEscort

        .global SomeonePleaseEscort
        SomeonePleaseEscort:
        .string "Someone{COMMA} please escort me!\0"
        .align 2,0

        .global PleaseEscortMe
        PleaseEscortMe:
        .asciz "Please escort me there!"
        .align 2,0

        .global PleaseTakeMeThere
        PleaseTakeMeThere:
        .asciz "Please take me there with you!"
        .align 2,0

        .global PleaseTakeMeToSee
        PleaseTakeMeToSee:
        .string "Please take me to see {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gUnknown_80EB220
gUnknown_80EB220: @ 80EB220
@ replacing .incbin "baserom.gba", 0x000eb220, 0xd0
        .4byte TakeMeet_80EB2CC
        .4byte Escort_80EB2AC
        .4byte HelpMeet_80EB294
        .4byte WantMeet_80EB274
        .4byte Worried_80EB250
        .4byte Without_80EB238

        .global Without_80EB238
	Without_80EB238:
        .string "Without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{COMMA} I...\0"
        .align 2,0

        .global Worried_80EB250
	Worried_80EB250:
        .string "I{APOSTROPHE}m so worried about {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}...\0"
        .align 2,0

        .global WantMeet_80EB274
	WantMeet_80EB274:
        .string "I really want to meet {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global HelpMeet_80EB294
	HelpMeet_80EB294:
        .string "Help me meet {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global Escort_80EB2AC
	Escort_80EB2AC:
        .string "Please escort me to my {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global TakeMeet_80EB2CC
	TakeMeet_80EB2CC:
        .string "Please! Take me to meet {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gUnknown_80EB2F0
gUnknown_80EB2F0: @ 80EB2F0
@ replacing .incbin "baserom.gba", 0x000eb2f0, 0x108
        .4byte WeInLove_80EB3CC
        .4byte WeBelong_80EB3A4
        .4byte WePromised_80EB37C
        .4byte MeansEverything_80EB35C
        .4byte NoGood_80EB334
        .4byte Lonely_80EB308

        .global Lonely_80EB308
        Lonely_80EB308:
        .string "I{APOSTROPHE}m very lonely! Please take me with you!\0"
        .align 2,0

        .global NoGood_80EB334
        NoGood_80EB334:
        .string "It{APOSTROPHE}s no good if we{APOSTROPHE}re not together!\0"
        .align 2,0

        .global MeansEverything_80EB35C
        MeansEverything_80EB35C:
        .asciz "This means everything to me!"
        .align 2,0

        .global WePromised_80EB37C
        WePromised_80EB37C:
        .string "We{APOSTROPHE}ve promised our futures together.\0"
        .align 2,0

        .global WeBelong_80EB3A4
        WeBelong_80EB3A4:
        .string "We belong together! Please escort me!\0"
        .align 2,0

        .global WeInLove_80EB3CC
        WeInLove_80EB3CC:
        .string "We{APOSTROPHE}re in love! Please{COMMA} take me there!\0"
        .align 2,0

@ Item Delivery Mission Text
	.global gUnknown_80EB3F8
gUnknown_80EB3F8: @ 80EB3F8
	.incbin "baserom.gba", 0xEB3F8, 0x334

	.global gUnknown_80EB72C
gUnknown_80EB72C: @ 80EB72C
	.incbin "baserom.gba", 0xEB72C, 0x2EC
