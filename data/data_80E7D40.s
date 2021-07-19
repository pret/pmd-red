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
        .string "Punish bad #C6Mankey#R!\0"
        .align 2,0

	.global gSmeargleMission
gSmeargleMission: @ 80E87F4
        .string "#C6Smeargle#R~27s desperate plea!\0"
        .align 2,0

	.global gMedichamMission
gMedichamMission: @ 80E8818
        .string "#C6Medicham#R: Help me!\0"
        .align 2,0

	.global gUnknown_80E8830
gUnknown_80E8830: @ 80E8830
        .string "Deliver one #C4%s#R.\0"
        .align 2,0

	.global gUnknown_80E8848
gUnknown_80E8848: @ 80E8848
        .string "One #C4%s#R wanted!\0"
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
        .string "Please punish bad #C6Mankey#R~27s gang.\0"
        .align 2,0

	.global gSmeargleMissionDescription
gSmeargleMissionDescription: @ 80E88C8
        .string "I didn~27t want to become a grown-up~2c so I\n"
        .string "fled~2c but now I~27ve lost my way! Help!\0"
        .align 2,0

	.global gMedichamMissionDescription
gMedichamMissionDescription: @ 80E8920
        .string "This is #C6Medicham#R. Rescue me~2c please!\n"
        .string "The reward is a secret"
        .byte 0x81, 0x60
        .string "♪ "
        .align 2,0

	.global gUnknown_80E8968
gUnknown_80E8968: @ 80E8968
        .string "With the item #C4%s#R~2c I can\n"
        .string "evolve! I~27m yearning to evolve! Help!\0"
        .align 2,0

	.global gUnknown_80E89B0
gUnknown_80E89B0: @ 80E89B0
        .string "The #C4%s#R! What I love to eat\n"
        .string "and can~27t live without! Please get one!\0"
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
        .string "%s#C4"
        .byte 0x81
        .string "i%s"
        .byte 0x81
        .string "j#R\0"
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
        .string "Deliver #C4%s#R.\0"
        .align 2,0

	.global gUnknown_80E8B10
gUnknown_80E8B10: @ 80E8B10
        .string "Find #C4%s#R.\0"
        .align 2,0

	.global gUnknown_80E8B20
gUnknown_80E8B20: @ 80E8B20
        .string "Help me.\0"
        .align 2,0

	.global gUnknown_80E8B2C
gUnknown_80E8B2C: @ 80E8B2C
        .string "Escort to #C6%s#R.\0"
        .align 2,0

	.global gUnknown_80E8B40
gUnknown_80E8B40: @ 80E8B40
        .string "Find #C6%s#R.\0"
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
        .asciz "I want to see #C6%s#R."
        .align 2,0

        .global TakeMe_Text
        TakeMe_Text:
        .asciz "Take me!"
        .align 2,0

	.global gUnknown_80EAEB8
gUnknown_80EAEB8: @ 80EAEB8
@ replacing .incbin "baserom.gba", 0x000eaeb8, 0x2e0
        .byte 0x7c, 0xb1, 0x0e, 0x08
        .byte 0x58, 0xb1, 0x0e, 0x08
        .byte 0x38, 0xb1, 0x0e, 0x08
        .byte 0x18, 0xb1, 0x0e, 0x08
        .byte 0xfc, 0xb0, 0x0e, 0x08
        .byte 0xdc, 0xb0, 0x0e, 0x08
        .byte 0xb4, 0xb0, 0x0e, 0x08
        .byte 0x90, 0xb0, 0x0e, 0x08
        .byte 0x6c, 0xb0, 0x0e, 0x08
        .byte 0x48, 0xb0, 0x0e, 0x08
        .byte 0x30, 0xb0, 0x0e, 0x08
        .byte 0x14, 0xb0, 0x0e, 0x08
        .byte 0xf0, 0xaf, 0x0e, 0x08
        .byte 0xd4, 0xaf, 0x0e, 0x08
        .byte 0xa4, 0xaf, 0x0e, 0x08
        .byte 0x94, 0xaf, 0x0e, 0x08
        .byte 0x70, 0xaf, 0x0e, 0x08
        .byte 0x4c, 0xaf, 0x0e, 0x08
        .byte 0x2c, 0xaf, 0x0e, 0x08
        .byte 0x08, 0xaf, 0x0e, 0x08

        .asciz "I~27m close friends with #C6%s#R!"
        .align 2,0

        .asciz "I want to apologize to #C6%s#R."
        .align 2,0

        .asciz "I don~27t care how--we must meet!"
        .align 2,0

        .asciz "We have to meet--whatever it takes!"
        .align 2,0

        .asciz "I have to go!"
        .align 2,0

        .asciz "We haven~27t seen each other in a long time."
        .align 2,0

        .asciz "I~27m sick with worry..."
        .align 2,0

        .asciz "#C6%s#R may have fainted inside..."
        .align 2,0

        .asciz "#C6%s#R hasn~27t returned!"
        .align 2,0

        .asciz "I want to help #C6%s#R!"
        .align 2,0

        .asciz "Hurry~2c #C6%s#R is in trouble..."
        .align 2,0

        .asciz "#C6%s#R has been waiting forever..."
        .align 2,0

        .asciz "#C6%s#R is waiting in the dungeon."
        .align 2,0

        .asciz "I~27m too weak. It~27s not possible."
        .align 2,0

        .asciz "I can~27t go on my own power..."
        .align 2,0

        .asciz "I can~27t go by myself..."
        .align 2,0

        .asciz "I~27m worried about #C6%s#R..."
        .align 2,0

        .asciz "I want to meet with #C6%s#R."
        .align 2,0

        .asciz "We promised to meet in the dungeon!"
        .align 2,0

        .asciz "#C6%s#R is waiting for me!"
        .align 2,0


	.global gUnknown_80EB198
gUnknown_80EB198: @ 80EB198
        .4byte PleaseTakeMeToSee
        .4byte PleaseTakeMeThere
        .4byte PleaseEscortMe
        .4byte SomeonePleaseEscort

        .global SomeonePleaseEscort
        SomeonePleaseEscort:
        .asciz "Someone~2c please escort me!"
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
        .asciz "Please take me to see #C6%s#R!"
        .align 2,0

	.global gUnknown_80EB220
gUnknown_80EB220: @ 80EB220
@ replacing .incbin "baserom.gba", 0x000eb220, 0xd0
        .byte 0xcc, 0xb2, 0x0e, 0x08
        .byte 0xac, 0xb2, 0x0e, 0x08
        .byte 0x94, 0xb2, 0x0e, 0x08
        .byte 0x74, 0xb2, 0x0e, 0x08
        .byte 0x50, 0xb2, 0x0e, 0x08
        .byte 0x38, 0xb2, 0x0e, 0x08

        .asciz "Without #C6%s#R~2c I..."
        .align 2,0

        .asciz "I~27m so worried about #C6%s#R..."
        .align 2,0

        .asciz "I really want to meet #C6%s#R!"
        .align 2,0

        .asciz "Help me meet #C6%s#R!"
        .align 2,0

        .asciz "Please escort me to my #C6%s#R!"
        .align 2,0

        .asciz "Please! Take me to meet #C6%s#R!"
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
        .asciz "I~27m very lonely! Please take me with you!"
        .align 2,0

        .global NoGood_80EB334
        NoGood_80EB334:
        .asciz "It~27s no good if we~27re not together!"
        .align 2,0

        .global MeansEverything_80EB35C
        MeansEverything_80EB35C:
        .asciz "This means everything to me!"
        .align 2,0

        .global WePromised_80EB37C
        WePromised_80EB37C:
        .asciz "We~27ve promised our futures together."
        .align 2,0

        .global WeBelong_80EB3A4
        WeBelong_80EB3A4:
        .asciz "We belong together! Please escort me!"
        .align 2,0
        
        .global WeInLove_80EB3CC
        WeInLove_80EB3CC:
        .asciz "We~27re in love! Please~2c take me there!"
        .align 2,0

@ Item Delivery Mission Text
	.global gUnknown_80EB3F8
gUnknown_80EB3F8: @ 80EB3F8
	.incbin "baserom.gba", 0xEB3F8, 0x334

	.global gUnknown_80EB72C
gUnknown_80EB72C: @ 80EB72C
	.incbin "baserom.gba", 0xEB72C, 0x2EC

