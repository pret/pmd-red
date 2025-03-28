#include "constants/status.h"
.section .rodata

.align 2,0

.string "pksdir0\0"
.align 2, 0
@ Start of Boss Fight Dialogues?

.global gSkarmoryPreFightDialogue_1
gSkarmoryPreFightDialogue_1: @ 8100768
.byte 0x00, 0x00, 0x0C, 0x02, 0xAA, 0x01, 0x00, 0x00
.4byte gUnknown_8100774

.global gUnknown_8100774
gUnknown_8100774: @ 8100774
.string " Look, {POKEMON_0}!\n"
.string "{POKEMON_2}'s over there!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_2
gSkarmoryPreFightDialogue_2: @ 8100798
.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x07, 0x00
.4byte gUnknown_81007E8
.byte 0x00, 0x00, 0x04, 0x02, 0xAA, 0x01, 0x00, 0x00
.4byte gUnknown_81007B0

.global gUnknown_81007B0
gUnknown_81007B0: @ 81007B0
.string " Hey! Are you all right?\n"
.string "We've come to rescue you!\0"
.align 2, 0

.global gUnknown_81007E8
gUnknown_81007E8: @ 81007E8
.string " Hey! Are you all right?\n"
.string "We're here to rescue you!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_3
gSkarmoryPreFightDialogue_3: @ 8100820
.byte 0x00, 0x00, 0x01, 0x0D, 0x32, 0x00, 0x00, 0x00
.4byte gUnknown_810082C

.global gUnknown_810082C
gUnknown_810082C: @ 810082C
.string " ...I...\n"
.string "I'm scared.\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_4
gSkarmoryPreFightDialogue_4: @ 8100844
@ replacing .incbin "baserom.gba", 0x100844, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0xfc, 0x00, 0x00, 0x00
.4byte gUnknown_8100850

.global gUnknown_8100850
gUnknown_8100850: @ 8100850
.string " You!\n"
.string "What do you think you're doing here?!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_5
gSkarmoryPreFightDialogue_5: @ 8100880
@ replacing .incbin "baserom.gba", 0x100880, 0xA8
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81008DC
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100898

.global gUnknown_8100898
gUnknown_8100898: @ 8100898
.string " We're here to rescue\n"
.string "{POKEMON_2}!{EXTRA_MSG}"
.string " {POKEMON_3}!\n"
.string "Don't do this! Release {POKEMON_2}!\0"
.align 2, 0

.global gUnknown_81008DC
gUnknown_81008DC: @ 81008DC
.string " We came to rescue\n"
.string "{POKEMON_2}!{EXTRA_MSG}"
.string " Hey, {POKEMON_3}!\n"
.string "Quit doing this, and release {POKEMON_2}!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_6
gSkarmoryPreFightDialogue_6: @ 8100928
.byte 0x00, 0x00, 0x00, 0x0D, 0xFC, 0x00, 0x00, 0x00
.4byte gUnknown_8100934

.global gUnknown_8100934
gUnknown_8100934: @ 8100934
.string " How dare you!{WAIT_PRESS}\n"
.string "It's their fault!{EXTRA_MSG}"
.string " I haven't slept in days\n"
.string "because the earthquakes frighten me so!\n"
.string "Every night we had them!{EXTRA_MSG}"
.string " Those earthquakes are\n"
.string "caused by this brat's ilk running wild\n"
.string "underground!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_7
gSkarmoryPreFightDialogue_7: @ 8100A04
@ replacing .incbin "baserom.gba", 0x100A04, 0x17C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100AD4
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100A1C

.global gUnknown_8100A1C
gUnknown_8100A1C: @ 8100A1C
.string " That's not true.{EXTRA_MSG}"
.string "Well, it's true there have\n"
.string "been many earthquakes lately, but...{EXTRA_MSG}"
.string " It would take more than\n"
.string "{POKEMON_2}'s family going wild under\n"
.string "the ground to cause earthquakes.\0"
.align 2, 0

.global gUnknown_8100AD4
gUnknown_8100AD4: @ 8100AD4
.string " Whoa, that's not true.{EXTRA_MSG}"
.string " Sure there've been quakes\n"
.string "galore lately...{EXTRA_MSG}"
.string " But it would take more than\n"
.string "{POKEMON_2}'s family running wild under\n"
.string "the ground to set off a quake.\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_8
gSkarmoryPreFightDialogue_8: @ 8100B80
@ replacing .incbin "baserom.gba", 0x100B80, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0xfc, 0x00, 0x00, 0x00
.4byte gUnknown_8100B8C

.global gUnknown_8100B8C
gUnknown_8100B8C: @ 8100B8C
.string " You be quiet!{EXTRA_MSG}"
.string "We'll fight if you keep that up!\0"
.align 2, 0

.global gSkarmoryPreFightDialogue_9
gSkarmoryPreFightDialogue_9: @ 8100BC0
@ replacing .incbin "baserom.gba", 0x100BC0, 0xD0
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100C34
.byte 0x00, 0x00, 0x04, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100BD8

.global gUnknown_8100BD8
gUnknown_8100BD8: @ 8100BD8
.string " It's no good.\n"
.string "{POKEMON_3} is too agitated to listen to\n"
.string "reason.{EXTRA_MSG}"
.string " We'll have to fight it out!\0"
.align 2, 0

.global gUnknown_8100C34
gUnknown_8100C34: @ 8100C34
.string " It's useless.\n"
.string "{POKEMON_3} is too steamed to talk\n"
.string "reasonably.{EXTRA_MSG}"
.string " We're going to have to\n"
.string "fight!\0"
.align 2, 0
@ Skarmory Re-Fight?

.global gSkarmoryReFightDialogue_1
gSkarmoryReFightDialogue_1: @ 8100C90
.byte 0x00, 0x00, 0x00, 0x0D
.byte 0xFC, 0x00, 0x00, 0x00
.4byte _08100C9C

.global _08100C9C
_08100C9C: @ 08100C9C
.string " You again?!\n"
.asciz "Persistent pests!\0"
.align 2,0

.global gSkarmoryReFightDialogue_2
gSkarmoryReFightDialogue_2: @ 8100CBC
@ replacing .incbin "baserom.gba", 0x100CBC, 0x20
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100CC8

.global gUnknown_8100CC8
gUnknown_8100CC8: @ 8100CC8
.string " Let {POKEMON_2} go!\n"
.string "{POKEMON_3}!\0"
.align 2, 0

.global gSkarmoryReFightDialogue_3
gSkarmoryReFightDialogue_3: @ 8100CDC
@ replacing .incbin "baserom.gba", 0x100CDC, 0x60
.byte 0x00, 0x00, 0x00, 0x0d, 0xfc, 0x00, 0x00, 0x00
.4byte gUnknown_8100CE8

.global gUnknown_8100CE8
gUnknown_8100CE8: @ 8100CE8
.string " I absolutely refuse!{EXTRA_MSG}"
.string " If you want to complain so\n"
.string "much, I'll give you a fight!\0"
.align 2, 0

.global gUnknown_8100D3C
gUnknown_8100D3C: @ 8100D3C
@ replacing .incbin "baserom.gba", 0x100D3C, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8100D48

.global gUnknown_8100D48
gUnknown_8100D48: @ 8100D48
.string "{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go any farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_1
gTeamMeaniesPreFightDialogue_1: @ 8100DB0
@ replacing .incbin "baserom.gba", 0x100DB0, 0xB4
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100E18
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100DC8

.global gUnknown_8100DC8
gUnknown_8100DC8: @ 8100DC8
.string " Wow, we came quite a ways\n"
.string "into this forest.{EXTRA_MSG}"
.string " I wonder if {POKEMON_2} is\n"
.string "ahead...\0"
.align 2, 0

.global gUnknown_8100E18
gUnknown_8100E18: @ 8100E18
.string " We've come pretty far\n"
.string "into this forest.{EXTRA_MSG}"
.string " I wonder if {POKEMON_2} is\n"
.string "ahead...\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_2
gTeamMeaniesPreFightDialogue_2: @ 8100E64
@ replacing .incbin "baserom.gba", 0x100E64, 0x24
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8100E70

.global gUnknown_8100E70
gUnknown_8100E70: @ 8100E70
.string " Hold it right there!\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_3
gTeamMeaniesPreFightDialogue_3: @ 8100E88
@ replacing .incbin "baserom.gba", 0x100E88, 0x8C
.byte 0x00, 0x00, 0x00, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_8100E94

.global gUnknown_8100E94
gUnknown_8100E94: @ 8100E94
.string " Keke!\n"
.string "You know who's going to get to\n"
.string "{POKEMON_2} first? We are!{EXTRA_MSG}"
.string " So, for you to go ahead...{WAIT_PRESS}\n"
.string "Well, we can't let that happen.\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_4
gTeamMeaniesPreFightDialogue_4: @ 8100F14
@ replacing .incbin "baserom.gba", 0x100F14, 0xF0
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8100FC0
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8100F84
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8100F38

.global gUnknown_8100F38
gUnknown_8100F38: @ 8100F38
.string " Wh-what?!{EXTRA_MSG}"
.string " Now, hold on, {POKEMON_3}!{WAIT_PRESS}\n"
.string "Why do you always interfere with us?\0"
.align 2, 0

.global gUnknown_8100F84
gUnknown_8100F84: @ 8100F84
.string " Wh-what!{EXTRA_MSG}"
.string " Hey, {POKEMON_3}!{WAIT_PRESS}\n"
.string "Why do you always mess with us?\0"
.align 2, 0

.global gUnknown_8100FC0
gUnknown_8100FC0: @ 8100FC0
.string " Wh-what...?{EXTRA_MSG}"
.string " Hey, {POKEMON_3}!{WAIT_PRESS}\n"
.string "Why do you always try to mess with us?\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_5
gTeamMeaniesPreFightDialogue_5: @ 8101004
@ replacing .incbin "baserom.gba", 0x101004, 0x4C
.byte 0x00, 0x00, 0x03, 0x0c, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_8101010

.global gUnknown_8101010
gUnknown_8101010: @ 8101010
.string " Oh? Didn't we tell you?{WAIT_PRESS}\n"
.string "Our aim is world domination〜♪ \0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_6
gTeamMeaniesPreFightDialogue_6: @ 8101050
@ replacing .incbin "baserom.gba", 0x101050, 0x80
.byte 0x00, 0x00, 0x02, 0x0d, 0x17, 0x00, 0x00, 0x00
.4byte gUnknown_810105C

.global gUnknown_810105C
gUnknown_810105C: @ 810105C
.string " {POKEMON_4}'s mama will\n"
.string "give us a generous reward...{EXTRA_MSG}"
.string " And {POKEMON_4} will join\n"
.string "us too...{WAIT_PRESS}\n"
.string "That brings us closer to our goal.\0"
.align 2, 0

.global gTeamMeaniesPreFightDialogue_7
gTeamMeaniesPreFightDialogue_7: @ 81010D0
@ replacing .incbin "baserom.gba", 0x1010D0, 0x94
.byte 0x00, 0x00, 0x00, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_81010DC

.global gUnknown_81010DC
gUnknown_81010DC: @ 81010DC
.string " Keke!\n"
.string "And for that, your lot is in the way!{EXTRA_MSG}"
.string " So sorry to say, but your\n"
.string "party's over right here and now!{EXTRA_MSG}"
.string " Say good-bye, {POKEMON_1}!\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_1
gTeamMeaniesReFightDialogue_1: @ 8101164
@ replacing .incbin "baserom.gba", 0x101164, 0xDC
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81011E4
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810117C

.global gUnknown_810117C
gUnknown_810117C: @ 810117C
.string " This is where the {COLOR CYAN}Meanies{RESET}\n"
.string "showed up last time.{EXTRA_MSG}"
.string " I wonder if {POKEMON_3}'s\n"
.string "bunch already found {POKEMON_2}...\0"
.align 2, 0

.global gUnknown_81011E4
gUnknown_81011E4: @ 81011E4
.string " Last time, this is where\n"
.string "{POKEMON_3}'s gang appeared.{EXTRA_MSG}"
.string " Did they find {POKEMON_2}\n"
.string "already, I wonder?\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_2
gTeamMeaniesReFightDialogue_2: @ 8101240
@ replacing .incbin "baserom.gba", 0x101240, 0xD0
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81012D4
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_810129C
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101264

.global gUnknown_8101264
gUnknown_8101264: @ 8101264
.string " Huh? It's {POKEMON_3}!{EXTRA_MSG}"
.string " Why is {POKEMON_3}'s gang\n"
.string "following us?\0"
.align 2, 0

.global gUnknown_810129C
gUnknown_810129C: @ 810129C
.string " Huh? It's {POKEMON_3}!{EXTRA_MSG}"
.string " Why is the {POKEMON_3}\n"
.string "gang following us?\0"
.align 2, 0

.global gUnknown_81012D4
gUnknown_81012D4: @ 81012D4
.string " Hah? It's {POKEMON_3}!{EXTRA_MSG}"
.string " Why is {POKEMON_3}'s\n"
.string "crew coming after us?\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_3
gTeamMeaniesReFightDialogue_3: @ 8101310
@ replacing .incbin "baserom.gba", 0x101310, 0x6C
.byte 0x00, 0x00, 0x03, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_810131C

.global gUnknown_810131C
gUnknown_810131C: @ 810131C
.string " Y-you be quiet!{EXTRA_MSG}"
.string " Right after we beat you last\n"
.string "time...{EXTRA_MSG}"
.string " We got careless and wiped\n"
.string "out too!\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_4
gTeamMeaniesReFightDialogue_4: @ 810137C
@ replacing .incbin "baserom.gba", 0x10137C, 0x8C
.byte 0x01, 0x00, 0x03, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_8101388

.global gUnknown_8101388
gUnknown_8101388: @ 8101388
.string " Don't you laugh at me!{WAIT_PRESS}\n"
.string "What makes you so high-and-mighty?{EXTRA_MSG}"
.string " Whatever happens, we're\n"
.string "not going to lose to you amateurs!\0"
.align 2, 0

.global gTeamMeaniesReFightDialogue_5
gTeamMeaniesReFightDialogue_5: @ 8101408
@ replacing .incbin "baserom.gba", 0x101408, 0x38
.byte 0x00, 0x00, 0x02, 0x0d, 0x5e, 0x00, 0x00, 0x00
.4byte gUnknown_8101414

.global gUnknown_8101414
gUnknown_8101414: @ 8101414
.string " This is it, {POKEMON_1}!\n"
.string "You're going down!\0"
.align 2, 0

.global gUnknown_8101440
gUnknown_8101440: @ 8101440
@ replacing .incbin "baserom.gba", 0x101440, 0x70
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810144C

.global gUnknown_810144C
gUnknown_810144C: @ 810144C
.string "{CENTER_ALIGN}It's impossible to go any farther...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}But there is nothing here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gUnknown_81014B0
gUnknown_81014B0: @ 81014B0
@ replacing .incbin "baserom.gba", 0x1014B0, 0x54
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81014E0
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81014C8

.global gUnknown_81014C8
gUnknown_81014C8: @ 81014C8
.string " This is the summit...\0"
.align 2, 0

.global gUnknown_81014E0
gUnknown_81014E0: @ 81014E0
.string " This is the mountain's peak...\0"
.align 2, 0

.global gUnknown_8101504
gUnknown_8101504: @ 8101504
@ replacing .incbin "baserom.gba", 0x101504, 0x9C
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_810155C
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810151C

.global gUnknown_810151C
gUnknown_810151C: @ 810151C
.string " Hey! {POKEMON_3}!\n"
.string "Where are you?!{EXTRA_MSG}"
.string " We came to rescue\n"
.string "{POKEMON_2}!\n"
.string "Come out!\0"
.align 2, 0

.global gUnknown_810155C
gUnknown_810155C: @ 810155C
.string " Hey! {POKEMON_3}!\n"
.string "Where are you?!{EXTRA_MSG}"
.string " We came to rescue\n"
.string "{POKEMON_2}!\n"
.string "Show yourself!\0"
.align 2, 0

.global gUnknown_81015A0
gUnknown_81015A0: @ 81015A0
@ replacing .incbin "baserom.gba", 0x1015A0, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81015AC

.global gUnknown_81015AC
gUnknown_81015AC: @ 81015AC
.string "Gyaoooooooooh!\n"
.string "                     \0"
.align 2, 0

.global gUnknown_81015D4
gUnknown_81015D4: @ 81015D4
@ replacing .incbin "baserom.gba", 0x1015D4, 0x14
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81015E0

.global gUnknown_81015E0
gUnknown_81015E0: @ 81015E0
.string " Waah!\0"
.align 2, 0

.global gUnknown_81015E8
gUnknown_81015E8: @ 81015E8
@ replacing .incbin "baserom.gba", 0x1015E8, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81015F4

.global gUnknown_81015F4
gUnknown_81015F4: @ 81015F4
.string " I warned you!\n"
.string "I have no mercy for meddlers!\0"
.align 2, 0

.global gUnknown_8101624
gUnknown_8101624: @ 8101624
@ replacing .incbin "baserom.gba", 0x101624, 0x38
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101630

.global gUnknown_8101630
gUnknown_8101630: @ 8101630
.string " Not scared...{WAIT_PRESS}\n"
.string "You don't frighten me!\0"
.align 2, 0

.global gUnknown_810165C
gUnknown_810165C: @ 810165C
@ replacing .incbin "baserom.gba", 0x10165C, 0xF4
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101708
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_81016CC
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101680

.global gUnknown_8101680
gUnknown_8101680: @ 8101680
.string " Hey, {POKEMON_3}!\n"
.string "We demand you release {POKEMON_2}!{EXTRA_MSG}"
.string " We're a Pokémon rescue\n"
.string "team!\0"
.align 2, 0

.global gUnknown_81016CC
gUnknown_81016CC: @ 81016CC
.string " Hey, {POKEMON_3}!\n"
.string "Release {POKEMON_2}!{EXTRA_MSG}"
.string " We're a Pokémon rescue\n"
.string "team!\0"
.align 2, 0

.global gUnknown_8101708
gUnknown_8101708: @ 8101708
.string " Hey, {POKEMON_3}!\n"
.string "Let {POKEMON_2} go!{EXTRA_MSG}"
.string " A Pokémon rescue team!\n"
.string "That's what we are!\0"
.align 2, 0

.global gUnknown_8101750
gUnknown_8101750: @ 8101750
@ replacing .incbin "baserom.gba", 0x101750, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_810175C

.global gUnknown_810175C
gUnknown_810175C: @ 810175C
.string " You must be determined,\n"
.string "to utter such words.\0"
.align 2, 0

.global gUnknown_810178C
gUnknown_810178C: @ 810178C
@ replacing .incbin "baserom.gba", 0x10178C, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_8101798

.global gUnknown_8101798
gUnknown_8101798: @ 8101798
.string " Then you shall answer...\0"
.align 2, 0

.global gUnknown_81017B4
gUnknown_81017B4: @ 81017B4
@ replacing .incbin "baserom.gba", 0x1017B4, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81017C0

.global gUnknown_81017C0
gUnknown_81017C0: @ 81017C0
.string " To my great and righteous\n"
.string "fury!\0"
.align 2, 0

.global gZapdosReFightDialogue_1
gZapdosReFightDialogue_1: @ 81017E4
@ replacing .incbin "baserom.gba", 0x1017E4, 0xB4
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101864
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_810183C
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101808

.global gUnknown_8101808
gUnknown_8101808: @ 8101808
.string " Hey, {POKEMON_3}!\n"
.string "We're here again!{EXTRA_MSG}"
.string " Show yourself!\0"
.align 2, 0

.global gUnknown_810183C
gUnknown_810183C: @ 810183C
.string " Hey, {POKEMON_3}!\n"
.string "We're back!{EXTRA_MSG}"
.string " Come out!\0"
.align 2, 0

.global gUnknown_8101864
gUnknown_8101864: @ 8101864
.string " Hey, {POKEMON_3}!\n"
.string "Guess who's back?!{EXTRA_MSG}"
.string " Show yourself!\0"
.align 2, 0

.global gZapdosReFightDialogue_2
gZapdosReFightDialogue_2: @ 8101898
@ replacing .incbin "baserom.gba", 0x101898, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81018A4

.global gUnknown_81018A4
gUnknown_81018A4: @ 81018A4
.string " However often you may\n"
.string "return...\n"
.string "The result will always be the same!\0"
.align 2, 0

.global gZapdosReFightDialogue_3
gZapdosReFightDialogue_3: @ 81018EC
@ replacing .incbin "baserom.gba", 0x1018EC, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81018F8

.global gUnknown_81018F8
gUnknown_81018F8: @ 81018F8
.string " You have no hope of\n"
.string "winning!\0"
.align 2, 0

.global gZapdosReFightDialogue_4
gZapdosReFightDialogue_4: @ 8101918
@ replacing .incbin "baserom.gba", 0x101918, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_8101924

.global gUnknown_8101924
gUnknown_8101924: @ 8101924
.string " Prepare yourselves!\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_1
gZapdosPostStoryPreFightDialogue_1: @ 810193C
@ replacing .incbin "baserom.gba", 0x10193C, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101948

.global gUnknown_8101948
gUnknown_8101948: @ 8101948
.string "Gyaoooooooooooh!\n"
.string "                     \0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_2
gZapdosPostStoryPreFightDialogue_2: @ 8101970
@ replacing .incbin "baserom.gba", 0x101970, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_810197C

.global gUnknown_810197C
gUnknown_810197C: @ 810197C
.string " So, you're back!\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_3
gZapdosPostStoryPreFightDialogue_3: @ 8101994
@ replacing .incbin "baserom.gba", 0x101994, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81019A0

.global gUnknown_81019A0
gUnknown_81019A0: @ 81019A0
.string " Since we last met, how\n"
.string "much more have you furthered your team?\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_4
gZapdosPostStoryPreFightDialogue_4: @ 81019E4
@ replacing .incbin "baserom.gba", 0x1019E4, 0x20
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_81019F0

.global gUnknown_81019F0
gUnknown_81019F0: @ 81019F0
.string " How much stronger?\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_5
gZapdosPostStoryPreFightDialogue_5: @ 8101A04
@ replacing .incbin "baserom.gba", 0x101A04, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x91, 0x00, 0x00, 0x00
.4byte gUnknown_8101A10

.global gUnknown_8101A10
gUnknown_8101A10: @ 8101A10
.string " Your power...{WAIT_PRESS}\n"
.string "Demonstrate it for me!\0"
.align 2, 0

.global gZapdosPostStoryPreFightDialogue_6
gZapdosPostStoryPreFightDialogue_6: @ 8101A38
@ replacing .incbin "baserom.gba", 0x101A38, 0x64
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101A44

.global gUnknown_8101A44
gUnknown_8101A44: @ 8101A44
.string "{CENTER_ALIGN}The mountain's summit...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gMoltresPreFightDialogue_1
gMoltresPreFightDialogue_1: @ 8101A9C
@ replacing .incbin "baserom.gba", 0x101A9C, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101AA8

.global gUnknown_8101AA8
gUnknown_8101AA8: @ 8101AA8
.string " Is this it?\n"
.string "Is this Mt. Blaze's summit?\0"
.align 2, 0

.global gMoltresPreFightDialogue_2
gMoltresPreFightDialogue_2: @ 8101AD4
@ replacing .incbin "baserom.gba", 0x101AD4, 0x15C
.byte 0x00, 0x00, 0x02, 0x0d, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101B8C
.byte 0x00, 0x00, 0x02, 0x0d
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101AEC

.global gUnknown_8101AEC
gUnknown_8101AEC: @ 8101AEC
.string " Wow. This is incredible.{WAIT_PRESS}\n"
.string "I know it's a volcano, but the lava flow\n"
.string "is much higher than normal.{EXTRA_MSG}"
.string " This might also have a link\n"
.string "to the natural calamities...\0"
.align 2, 0

.global gUnknown_8101B8C
gUnknown_8101B8C: @ 8101B8C
.string " This is one incredible place.{WAIT_PRESS}\n"
.string "I know this is a volcano, but the amount\n"
.string "of lava is way more than usual.{EXTRA_MSG}"
.string " This might also be a part of\n"
.string "the natural disasters...\0"
.align 2, 0

.global gMoltresPreFightDialogue_3
gMoltresPreFightDialogue_3: @ 8101C30
@ replacing .incbin "baserom.gba", 0x101C30, 0x8C
.byte 0x00, 0x00, 0x0c, 0x0d, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101C80
.byte 0x00, 0x00, 0x0c, 0x0d
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101C48

.global gUnknown_8101C48
gUnknown_8101C48: @ 8101C48
.string " Oogh! It's like a furnace!{WAIT_PRESS}\n"
.string "I'm getting roasted!\0"
.align 2, 0

.global gUnknown_8101C80
gUnknown_8101C80: @ 8101C80
.string " Yowch! It's wicked hot!{WAIT_PRESS}\n"
.string "I feel like I'm burning up.\0"
.align 2, 0

.global gMoltresPreFightDialogue_4
gMoltresPreFightDialogue_4: @ 8101CBC
@ replacing .incbin "baserom.gba", 0x101CBC, 0xD0
.byte 0x00, 0x00, 0x04, 0x12, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101D34
.byte 0x00, 0x00, 0x04, 0x12
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101CD4

.global gUnknown_8101CD4
gUnknown_8101CD4: @ 8101CD4
.string " I don't want to spend any\n"
.string "time in a place this dangerous.{EXTRA_MSG}"
.string " Let's get through this quick.\0"
.align 2, 0

.global gUnknown_8101D34
gUnknown_8101D34: @ 8101D34
.string " I don't want to be in a place\n"
.string "this wickedly bad.{EXTRA_MSG}"
.string " Let's get through here quick.\0"
.align 2, 0

.global gMoltresPreFightDialogue_5
gMoltresPreFightDialogue_5: @ 8101D8C
@ replacing .incbin "baserom.gba", 0x101D8C, 0x14
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8101D98

.global gUnknown_8101D98
gUnknown_8101D98: @ 8101D98
.string " Halt!\0"
.align 2, 0

.global gMoltresPreFightDialogue_6
gMoltresPreFightDialogue_6: @ 8101DA0
@ replacing .incbin "baserom.gba", 0x101DA0, 0x7C
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101DE4
.byte 0x00, 0x00, 0x04, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101DB8

.global gUnknown_8101DB8
gUnknown_8101DB8: @ 8101DB8
.string " Huh, what?!{EXTRA_MSG}"
.string " It suddenly turned dark!\0"
.align 2, 0

.global gUnknown_8101DE4
gUnknown_8101DE4: @ 8101DE4
.string " Wh-what the...?!{EXTRA_MSG}"
.string " Why did it turn dark like\n"
.string "that?!\0"
.align 2, 0

.global gMoltresPreFightDialogue_7
gMoltresPreFightDialogue_7: @ 8101E1C
@ replacing .incbin "baserom.gba", 0x101E1C, 0x90
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8101E28

.global gUnknown_8101E28
gUnknown_8101E28: @ 8101E28
.string " I can hear the mountain's screams...{EXTRA_MSG}"
.string " It is shrieking in pain...{EXTRA_MSG}"
.string " Someone is causing Mt. Blaze to\n"
.string "writhe in agony!\n"
.string "Is it you?!\0"
.align 2, 0

.global gMoltresPreFightDialogue_8
gMoltresPreFightDialogue_8: @ 8101EAC
@ replacing .incbin "baserom.gba", 0x101EAC, 0x1C4
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8101FD4
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8101F48
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8101ED0

.global gUnknown_8101ED0
gUnknown_8101ED0: @ 8101ED0
.string " Huh?!{WAIT_PRESS}\n"
.string "That's wrong!\n"
.string "We're innocent!{EXTRA_MSG}"
.string " We were just passing\n"
.string "through!{EXTRA_MSG}"
.string " Who are you, anyway?{WAIT_PRESS}\n"
.string "Show yourself!\0"
.align 2, 0

.global gUnknown_8101F48
gUnknown_8101F48: @ 8101F48
.string " Huh?!{WAIT_PRESS}\n"
.string "You've got it wrong!\n"
.string "It's not us!{EXTRA_MSG}"
.string " We just happened to be\n"
.string "passing through here!{EXTRA_MSG}"
.string " Who are you, anyway?{WAIT_PRESS}\n"
.string "Show yourself!\n"
.string " \0"
.align 2, 0

.global gUnknown_8101FD4
gUnknown_8101FD4: @ 8101FD4
.string " Hah?!{WAIT_PRESS}\n"
.string "We don't know what you mean!\n"
.string "We're not doing anything!{EXTRA_MSG}"
.string " We just happened to be\n"
.string "traveling through here!{EXTRA_MSG}"
.string " Who are you, anyway?{WAIT_PRESS}\n"
.string "Come out!\0"
.align 2, 0

.global gMoltresPreFightDialogue_9
gMoltresPreFightDialogue_9: @ 8102070
@ replacing .incbin "baserom.gba", 0x102070, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810207C

.global gUnknown_810207C
gUnknown_810207C: @ 810207C
.string "Gyaaaaaaaaaaaa!\n"
.string "                     \0"
.align 2, 0

.global gMoltresPreFightDialogue_10
gMoltresPreFightDialogue_10: @ 81020A4
@ replacing .incbin "baserom.gba", 0x1020A4, 0x30
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81020B0

.global gUnknown_81020B0
gUnknown_81020B0: @ 81020B0
.string " The mountain's rage is my rage!\0"
.align 2, 0

.global gMoltresPreFightDialogue_11
gMoltresPreFightDialogue_11: @ 81020D4
@ replacing .incbin "baserom.gba", 0x1020D4, 0x34
.byte 0x02, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_81020E0

.global gUnknown_81020E0
gUnknown_81020E0: @ 81020E0
.string " I am {POKEMON_2}!\n"
.string "The warrior of fire am I!\0"
.align 2, 0

.global gMoltresPreFightDialogue_12
gMoltresPreFightDialogue_12: @ 8102108
@ replacing .incbin "baserom.gba", 0x102108, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102114

.global gUnknown_8102114
gUnknown_8102114: @ 8102114
.string " There is no forgiving \n"
.string "those who befoul the mountain!\n"
.string "En garde!\0"
.align 2, 0

.global gMoltresReFightDialogue_1
gMoltresReFightDialogue_1: @ 8102158
@ replacing .incbin "baserom.gba", 0x102158, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102164

.global gUnknown_8102164
gUnknown_8102164: @ 8102164
.string " ............{WAIT_PRESS}\n"
.string "Maybe {POKEMON_2} isn't around...\0"
.align 2, 0

.global gMoltresReFightDialogue_2
gMoltresReFightDialogue_2: @ 8102190
@ replacing .incbin "baserom.gba", 0x102190, 0x70
.byte 0x00, 0x00, 0x01, 0x12, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81021D8
.byte 0x00, 0x00, 0x01, 0x12
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81021A8

.global gUnknown_81021A8
gUnknown_81021A8: @ 81021A8
.string " Let's slip by here while\n"
.string "we have the chance.\0"
.align 2, 0

.global gUnknown_81021D8
gUnknown_81021D8: @ 81021D8
.string " Let's sneak through while\n"
.string "we can.\0"
.align 2, 0

.global gMoltresReFightDialogue_3
gMoltresReFightDialogue_3: @ 8102200
@ replacing .incbin "baserom.gba", 0x102200, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_810220C

.global gUnknown_810220C
gUnknown_810220C: @ 810220C
.string " You again!{EXTRA_MSG}"
.string " There is no forgiving \n"
.string "those who torment the mountain!\0"
.align 2, 0

.global gMoltresReFightDialogue_4
gMoltresReFightDialogue_4: @ 8102254
@ replacing .incbin "baserom.gba", 0x102254, 0xA4
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81022CC
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_81022A0
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102278

.global gUnknown_8102278
gUnknown_8102278: @ 8102278
.string " Won't you listen?!{WAIT_PRESS}\n"
.string "We're only...\0"
.align 2, 0

.global gUnknown_81022A0
gUnknown_81022A0: @ 81022A0
.string " You don't understand!{WAIT_PRESS}\n"
.string "We're only...\0"
.align 2, 0

.global gUnknown_81022CC
gUnknown_81022CC: @ 81022CC
.string " You've got us wrong!{WAIT_PRESS}\n"
.string "We're just...\0"
.align 2, 0

.global gMoltresReFightDialogue_5
gMoltresReFightDialogue_5: @ 81022F8
@ replacing .incbin "baserom.gba", 0x1022F8, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102304

.global gUnknown_8102304
gUnknown_8102304: @ 8102304
.string " Your words are\n"
.string "meaningless!\n"
.string "En garde!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_1
gMoltresPostStoryPreFightDialogue_1: @ 810232C
@ replacing .incbin "baserom.gba", 0x10232C, 0x6C
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102338

.global gUnknown_8102338
gUnknown_8102338: @ 8102338
.string " Halt!{EXTRA_MSG}"
.string " This is Mt. Blaze!{EXTRA_MSG}"
.string " For you to venture to its\n"
.string "peak, there can be but one reason!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_2
gMoltresPostStoryPreFightDialogue_2: @ 8102398
@ replacing .incbin "baserom.gba", 0x102398, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_81023A4

.global gUnknown_81023A4
gUnknown_81023A4: @ 81023A4
.string " You've come to challenge\n"
.string "me!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_3
gMoltresPostStoryPreFightDialogue_3: @ 81023C4
@ replacing .incbin "baserom.gba", 0x1023C4, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_81023D0

.global gUnknown_81023D0
gUnknown_81023D0: @ 81023D0
.string " So be it!{WAIT_PRESS}\n"
.string "I am the warrior of fire, {POKEMON_2}!\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_4
gMoltresPostStoryPreFightDialogue_4: @ 8102400
@ replacing .incbin "baserom.gba", 0x102400, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_810240C

.global gUnknown_810240C
gUnknown_810240C: @ 810240C
.string " Have you what it takes to\n"
.string "defeat me when I am holding back nothing?\0"
.align 2, 0

.global gMoltresPostStoryPreFightDialogue_5
gMoltresPostStoryPreFightDialogue_5: @ 8102454
@ replacing .incbin "baserom.gba", 0x102454, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x92, 0x00, 0x00, 0x00
.4byte gUnknown_8102460

.global gUnknown_8102460
gUnknown_8102460: @ 8102460
.string " Show me!\0"
.align 2, 0

.global gUnknown_810246C
gUnknown_810246C: @ 810246C
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101A44

.global gArticunoPreFightDialogue_1
gArticunoPreFightDialogue_1: @ 8102478
@ replacing .incbin "baserom.gba", 0x102478, 0x13C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102524
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102490

.global gUnknown_8102490
gUnknown_8102490: @ 8102490
.string " We sure have traveled far\n"
.string "into this forest.{EXTRA_MSG}"
.string " I think we'll be out if we\n"
.string "can get through this part.{WAIT_PRESS}\n"
.string "It shouldn't be far. Let's keep going.\0"
.align 2, 0

.global gUnknown_8102524
gUnknown_8102524: @ 8102524
.string " We've come pretty far into\n"
.string "the forest.{EXTRA_MSG}"
.string " I think we'll be out if we\n"
.string "can get through this part.{WAIT_PRESS}\n"
.string "It shouldn't be long. Hang in there.\0"
.align 2, 0

.global gArticunoPreFightDialogue_2
gArticunoPreFightDialogue_2: @ 81025B4
@ replacing .incbin "baserom.gba", 0x1025B4, 0x20
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81025C0

.global gUnknown_81025C0
gUnknown_81025C0: @ 81025C0
.string " ...............\0"
.align 2, 0

.global gArticunoPreFightDialogue_3
gArticunoPreFightDialogue_3: @ 81025D4
@ replacing .incbin "baserom.gba", 0x1025D4, 0x3C
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81025E0

.global gUnknown_81025E0
gUnknown_81025E0: @ 81025E0
.string " ...Huh?{WAIT_PRESS}\n"
.string "{POKEMON_0}, did you just say something?\0"
.align 2, 0

.global gArticunoPreFightDialogue_4
gArticunoPreFightDialogue_4: @ 8102610
@ replacing .incbin "baserom.gba", 0x102610, 0xB4
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102680
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102628

.global gUnknown_8102628
gUnknown_8102628: @ 8102628
.string " ...I didn't think so...{EXTRA_MSG}"
.string " I thought I heard a voice...{WAIT_PRESS}\n"
.string "I must have imagined it.\0"
.align 2, 0

.global gUnknown_8102680
gUnknown_8102680: @ 8102680
.string " ...I didn't think so.{EXTRA_MSG}"
.string " A voice...?{WAIT_PRESS}\n"
.string "I must've imagined it.\0"
.align 2, 0

.global gArticunoPreFightDialogue_5
gArticunoPreFightDialogue_5: @ 81026C4
@ replacing .incbin "baserom.gba", 0x1026C4, 0x48
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81026D0

.global gUnknown_81026D0
gUnknown_81026D0: @ 81026D0
.string " ..................{EXTRA_MSG}"
.string " ...Turn back.{EXTRA_MSG}"
.string "You may not pass...\0"
.align 2, 0

.global gArticunoPreFightDialogue_6
gArticunoPreFightDialogue_6: @ 810270C
@ replacing .incbin "baserom.gba", 0x10270C, 0x20
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102718

.global gUnknown_8102718
gUnknown_8102718: @ 8102718
.string " Who's there?!\0"
.align 2, 0

.global gArticunoPreFightDialogue_7
gArticunoPreFightDialogue_7: @ 810272C
@ replacing .incbin "baserom.gba", 0x10272C, 0x90
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8102738

.global gUnknown_8102738
gUnknown_8102738: @ 8102738
.string " You are forbidden to pass...{EXTRA_MSG}"
.string " ...If you persist in trying to pass...{EXTRA_MSG}"
.string " Then, so be it...{EXTRA_MSG}"
.string " But only after you have defeated me!\0"
.align 2, 0

.global gArticunoPreFightDialogue_8
gArticunoPreFightDialogue_8: @ 81027BC
@ replacing .incbin "baserom.gba", 0x1027BC, 0x54
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81027C8

.global gUnknown_81027C8
gUnknown_81027C8: @ 81027C8
.string " Ow! It's too bright!{EXTRA_MSG}"
.string " The ice around us is\n"
.string "reflecting this light!\0"
.align 2, 0

.global gArticunoPreFightDialogue_9
gArticunoPreFightDialogue_9: @ 8102810
@ replacing .incbin "baserom.gba", 0x102810, 0x30
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810281C

.global gUnknown_810281C
gUnknown_810281C: @ 810281C
.string "Gyaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gArticunoPreFightDialogue_10
gArticunoPreFightDialogue_10: @ 8102840
.4byte 0x0d000000
.4byte 0x000001ab
.4byte gUnknown_810284C

.global gUnknown_810284C
gUnknown_810284C: @ 810284C

.global gUnknown_810284C
gUnknown_810284C: @ 810284C
.string " I am {POKEMON_2}!{WAIT_PRESS}\n"
.string "The warder of ice!\0"

.global gArticunoPreFightDialogue_11
gArticunoPreFightDialogue_11: @ 810286C
@ replacing .incbin "baserom.gba", 0x0010286c, 0x4c
.4byte 0x0d000000
.4byte 0x00000090
.4byte gUnknown_8102878

.global gUnknown_8102878
gUnknown_8102878: @ 8102878
.string " Those that enter the forest\n"
.string "I shall destroy with all my might!\0"

.global gArticunoPreFightDialogue_12
gArticunoPreFightDialogue_12: @ 81028B8
.4byte 0x0d000000
.4byte 0x00000090
.4byte gUnknown_81028C4

.global gUnknown_81028C4
gUnknown_81028C4: @ 81028C4
.string " Let us begin!\0"
.align 2, 0

.global gArticunoReFightDialogue_1
gArticunoReFightDialogue_1: @ 81028D4
@ replacing .incbin "baserom.gba", 0x1028D4, 0x44
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_81028E0

.global gUnknown_81028E0
gUnknown_81028E0: @ 81028E0
.string " You may try all you like.\n"
.string "But you shall never pass!\0"
.align 2, 0

.global gArticunoReFightDialogue_2
gArticunoReFightDialogue_2: @ 8102918
@ replacing .incbin "baserom.gba", 0x102918, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102924

.global gUnknown_8102924
gUnknown_8102924: @ 8102924
.string " If you so badly hope to\n"
.string "pass...\0"
.align 2, 0

.global gArticunoReFightDialogue_3
gArticunoReFightDialogue_3: @ 8102948
@ replacing .incbin "baserom.gba", 0x102948, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102954

.global gUnknown_8102954
gUnknown_8102954: @ 8102954
.string " Do so only if you can snatch\n"
.string "victory from me!\0"
.align 2, 0

.global gArticunoPostStoryPreFightDialogue_1
gArticunoPostStoryPreFightDialogue_1: @ 8102984
@ replacing .incbin "baserom.gba", 0x102984, 0x30
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8102990

.global gUnknown_8102990
gUnknown_8102990: @ 8102990
.string "Gyaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gArticunoPostStoryPreFightDialogue_2
gArticunoPostStoryPreFightDialogue_2: @ 81029B4
@ replacing .incbin "baserom.gba", 0x001029b4, 0x64
.4byte 0x0d000000
.4byte 0x00000090
.4byte gUnknown_81029C0

.global gUnknown_81029C0
gUnknown_81029C0: @ 81029C0
.string " Your arrival in this frozen\n"
.string "forest means only one thing...{EXTRA_MSG}"
.string " You mean to challenge me!\0"

.global gArticunoPostStoryPreFightDialogue_3
gArticunoPostStoryPreFightDialogue_3: @ 8102A18
@ replacing .incbin "baserom.gba", 0x102A18, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_810284C

.global gArticunoPostStoryPreFightDialogue_4
gArticunoPostStoryPreFightDialogue_4: @ 8102A24
@ replacing .incbin "baserom.gba", 0x102A24, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102A30

.global gUnknown_8102A30
gUnknown_8102A30: @ 8102A30
.string " Those that enter\n"
.string "the forest...\n"
.string "I shall destroy with all my might!\0"
.align 2, 0

.global gArticunoPostStoryPreFightDialogue_5
gArticunoPostStoryPreFightDialogue_5: @ 8102A74
@ replacing .incbin "baserom.gba", 0x102A74, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x90, 0x00, 0x00, 0x00
.4byte gUnknown_8102A80

.global gUnknown_8102A80
gUnknown_8102A80: @ 8102A80
.string " No matter who it may be!\0"
.align 2, 0

.global gUnknown_8102A9C
gUnknown_8102A9C: @ 8102A9C
@ replacing .incbin "baserom.gba", 0x102A9C, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8102AA8

.global gUnknown_8102AA8
gUnknown_8102AA8: @ 8102AA8
.string "{CENTER_ALIGN}This is the deepest part of the forest...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}But there is no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gUnknown_8102B10
gUnknown_8102B10: @ 8102B10
@ replacing .incbin "baserom.gba", 0x102B10, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8101A44

.global MagmaCavernMidDialogue_1
MagmaCavernMidDialogue_1: @ 8102B1C
@ replacing .incbin "baserom.gba", 0x00102b1c, 0x38
.4byte 0x02040000
.4byte 0x000001aa
.4byte gUnknown_8102B28

.global gUnknown_8102B28
gUnknown_8102B28: @ 8102B28
.string " Let's see...{WAIT_PRESS}\n"
.string "...I wonder where we are?\0"

.global MagmaCavernMidDialogue_2
MagmaCavernMidDialogue_2: @ 8102B54
@ replacing .incbin "baserom.gba", 0x102B54, 0x70
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102BA0
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102B6C

.global gUnknown_8102B6C
gUnknown_8102B6C: @ 8102B6C
.string " I'm certain we've come quite\n"
.string "far already...\0"
.align 2, 0

.global gUnknown_8102BA0
gUnknown_8102BA0: @ 8102BA0
.string " I know we've come pretty\n"
.string "far...\0"
.align 2, 0

.global MagmaCavernMidDialogue_3
MagmaCavernMidDialogue_3: @ 8102BC4
@ replacing .incbin "baserom.gba", 0x102BC4, 0x20
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102BD0

.global gUnknown_8102BD0
gUnknown_8102BD0: @ 8102BD0
.string " Waaah!\n"
.string "Qu-quake!\0"
.align 2, 0

.global MagmaCavernMidDialogue_4
MagmaCavernMidDialogue_4: @ 8102BE4
@ replacing .incbin "baserom.gba", 0x102BE4, 0x4C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102C14
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102BFC

.global gUnknown_8102BFC
gUnknown_8102BFC: @ 8102BFC
.string " ...Whew!\n"
.string "It's over.\0"
.align 2, 0

.global gUnknown_8102C14
gUnknown_8102C14: @ 8102C14
.string " ...Whew!\n"
.string "It settled down.\0"
.align 2, 0

.global MagmaCavernMidDialogue_5
MagmaCavernMidDialogue_5: @ 8102C30
@ replacing .incbin "baserom.gba", 0x102C30, 0x24
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102C3C

.global gUnknown_8102C3C
gUnknown_8102C3C: @ 8102C3C
.string " Hey! {POKEMON_0}!\n"
.string "Over there!\0"
.align 2, 0

.global MagmaCavernMidDialogue_6
MagmaCavernMidDialogue_6: @ 8102C54
@ replacing .incbin "baserom.gba", 0x102C54, 0x44
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102C80
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102C6C

.global gUnknown_8102C6C
gUnknown_8102C6C: @ 8102C6C
.string " Hey!\n"
.string "Are you OK?!\0"
.align 2, 0

.global gUnknown_8102C80
gUnknown_8102C80: @ 8102C80
.string " Hey!\n"
.string "Snap out of it!\0"
.align 2, 0

.global MagmaCavernMidDialogue_7
MagmaCavernMidDialogue_7: @ 8102C98
@ replacing .incbin "baserom.gba", 0x00102c98, 0x18
.4byte 0x0e030000
.4byte 0x00000006
.4byte gUnknown_8102CA4

.global gUnknown_8102CA4
gUnknown_8102CA4: @ 8102CA4
.string " Urrrrgh...\0"

.global MagmaCavernMidDialogue_8
MagmaCavernMidDialogue_8: @ 8102CB0
@ replacing .incbin "baserom.gba", 0x102CB0, 0x48
.byte 0x00, 0x00, 0x05, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102CE0
.byte 0x00, 0x00, 0x05, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102CC8

.global gUnknown_8102CC8
gUnknown_8102CC8: @ 8102CC8
.string " What happened to you?\0"
.align 2, 0

.global gUnknown_8102CE0
gUnknown_8102CE0: @ 8102CE0
.string " What happened here?\0"
.align 2, 0

.global MagmaCavernMidDialogue_9
MagmaCavernMidDialogue_9: @ 8102CF8
@ replacing .incbin "baserom.gba", 0x102CF8, 0x3C
.byte 0x00, 0x00, 0x03, 0x0e, 0x06, 0x00, 0x00, 0x00
.4byte gUnknown_8102D04

.global gUnknown_8102D04
gUnknown_8102D04: @ 8102D04
.string " We challenged...\n"
.string "{POKEMON_2}...{WAIT_PRESS}\n"
.string "And wiped out...\n\0"
.align 2, 0

.global MagmaCavernMidDialogue_10
MagmaCavernMidDialogue_10: @ 8102D34
@ replacing .incbin "baserom.gba", 0x102D34, 0x18
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102D40

.global gUnknown_8102D40
gUnknown_8102D40: @ 8102D40
.string " G-{POKEMON_2}?!\0"
.align 2, 0

.global MagmaCavernMidDialogue_11
MagmaCavernMidDialogue_11: @ 8102D4C
@ replacing .incbin "baserom.gba", 0x102D4C, 0x30
.byte 0x00, 0x00, 0x00, 0x0f, 0x11, 0x01, 0x00, 0x00
.4byte gUnknown_8102D58

.global gUnknown_8102D58
gUnknown_8102D58: @ 8102D58
.string " Grrgh...{WAIT_PRESS}\n"
.string "We... It crushed us...\0"
.align 2, 0

.global MagmaCavernMidDialogue_12
MagmaCavernMidDialogue_12: @ 8102D7C
@ replacing .incbin "baserom.gba", 0x102D7C, 0x80
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102DCC
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102D94

.global gUnknown_8102D94
gUnknown_8102D94: @ 8102D94
.string " That's right.{WAIT_PRESS}\n"
.string "What happened to {POKEMON_3}?\n"
.string "Where is {POKEMON_3}?\0"
.align 2, 0

.global gUnknown_8102DCC
gUnknown_8102DCC: @ 8102DCC
.string " Wait...{WAIT_PRESS}\n"
.string "What about {POKEMON_3}?\n"
.string "Where did {POKEMON_3} go?\0"
.align 2, 0

.global MagmaCavernMidDialogue_13
MagmaCavernMidDialogue_13: @ 8102DFC
@ replacing .incbin "baserom.gba", 0x102DFC, 0x30
.byte 0x00, 0x00, 0x00, 0x0f, 0x11, 0x01, 0x00, 0x00
.4byte gUnknown_8102E08

.global gUnknown_8102E08
gUnknown_8102E08: @ 8102E08
.string " {POKEMON_3} is...{WAIT_PRESS}\n"
.string "Still battling {POKEMON_2}...\0"
.align 2, 0

.global MagmaCavernMidDialogue_14
MagmaCavernMidDialogue_14: @ 8102E2C
@ replacing .incbin "baserom.gba", 0x00102e2c, 0x28
.4byte 0x020c0000
.4byte 0x000001aa
.4byte gUnknown_8102E38

.global gUnknown_8102E38
gUnknown_8102E38: @ 8102E38
.string " {POKEMON_0}!\n"
.string "We've got to hurry!\0"

.global MagmaCavernMidDialogue_15
MagmaCavernMidDialogue_15: @ 8102E54
@ replacing .incbin "baserom.gba", 0x00102e54, 0x1c
.4byte 0x0e030000
.4byte 0x00000006
.4byte gUnknown_8102E60

.global gUnknown_8102E60
gUnknown_8102E60: @ 8102E60
.string " ...Be careful!\0"

.global GroudonPreFightDialogue_1
GroudonPreFightDialogue_1: @ 8102E70
@ replacing .incbin "baserom.gba", 0x102E70, 0x4C
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8102EA4
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102E88

.global gUnknown_8102E88
gUnknown_8102E88: @ 8102E88
.string " It's {POKEMON_3}!\n"
.string "Are you OK?!\0"
.align 2, 0

.global gUnknown_8102EA4
gUnknown_8102EA4: @ 8102EA4
.string " Oh! {POKEMON_3}!\n"
.string "Are you OK?!\0"
.align 2, 0

.global GroudonPreFightDialogue_2
GroudonPreFightDialogue_2: @ 8102EBC
@ replacing .incbin "baserom.gba", 0x102EBC, 0x24
.byte 0x00, 0x00, 0x00, 0x0f, 0x41, 0x00, 0x00, 0x00
.4byte gUnknown_8102EC8

.global gUnknown_8102EC8
gUnknown_8102EC8: @ 8102EC8
.string " Hm!{WAIT_PRESS}\n"
.string "So it's you!\0"
.align 2, 0

.global GroudonPreFightDialogue_3
GroudonPreFightDialogue_3: @ 8102EE0
@ replacing .incbin "baserom.gba", 0x00102ee0, 0x18
.4byte 0x0f000000
.4byte 0x00000041
.4byte gUnknown_8102EEC

.global gUnknown_8102EEC
gUnknown_8102EEC: @ 8102EEC
.string " Stay back!\0"

.global GroudonPreFightDialogue_4
GroudonPreFightDialogue_4: @ 8102EF8
@ replacing .incbin "baserom.gba", 0x102EF8, 0x38
.byte 0x00, 0x00, 0x00, 0x0f, 0x41, 0x00, 0x00, 0x00
.4byte gUnknown_8102F04

.global gUnknown_8102F04
gUnknown_8102F04: @ 8102F04
.string " This opponent...{WAIT_PRESS}\n"
.string "is no laughing matter!\0"
.align 2, 0

.global GroudonPreFightDialogue_5
GroudonPreFightDialogue_5: @ 8102F30
@ replacing .incbin "baserom.gba", 0x102F30, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8102F3C

.global gUnknown_8102F3C
gUnknown_8102F3C: @ 8102F3C
.string "Grgaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global GroudonPreFightDialogue_6
GroudonPreFightDialogue_6: @ 8102F64
@ replacing .incbin "baserom.gba", 0x102F64, 0x20
.byte 0x00, 0x00, 0x00, 0x0f, 0x41, 0x00, 0x00, 0x00
.4byte gUnknown_8102F70

.global gUnknown_8102F70
gUnknown_8102F70: @ 8102F70
.string " H-here it comes!\0"
.align 2, 0

.global GroudonPreFightDialogue_7
GroudonPreFightDialogue_7: @ 8102F84
@ replacing .incbin "baserom.gba", 0x102F84, 0x28
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102F90

.global gUnknown_8102F90
gUnknown_8102F90: @ 8102F90
.string " Coming...?{WAIT_PRESS}\n"
.string "Wh-where?!\0"
.align 2, 0

.global GroudonPreFightDialogue_8
GroudonPreFightDialogue_8: @ 8102FAC
@ replacing .incbin "baserom.gba", 0x00102fac, 0x18
.4byte 0x0f010000
.4byte 0x00000041
.4byte gUnknown_8102FB8

.global gUnknown_8102FB8
gUnknown_8102FB8: @ 8102FB8
.string " Wraaaaaah!\0"

.global GroudonPreFightDialogue_9
GroudonPreFightDialogue_9: @ 8102FC4
@ replacing .incbin "baserom.gba", 0x00102fc4, 0x14
.4byte 0x020c0000
.4byte 0x000001aa
.4byte gUnknown_8102FD0

.global gUnknown_8102FD0
gUnknown_8102FD0: @ 8102FD0
@ The "A-" only makes sense when POKEMON_3 is "Alakazam" (which it is when this is used). Kinda funny.
.string " A-{POKEMON_3}!\0"

.global GroudonPreFightDialogue_10
GroudonPreFightDialogue_10: @ 8102FD8
@ replacing .incbin "baserom.gba", 0x102FD8, 0x7C
.byte 0x00, 0x00, 0x0c, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8103020
.byte 0x00, 0x00, 0x0c, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8102FF0

.global gUnknown_8102FF0
gUnknown_8102FF0: @ 8102FF0
.string " {POKEMON_3} is gone!{EXTRA_MSG}"
.string " Maybe...{WAIT_PRESS}\n"
.string "Was he defeated?!\0"
.align 2, 0

.global gUnknown_8103020
gUnknown_8103020: @ 8103020
.string " {POKEMON_3}'s gone!{EXTRA_MSG}"
.string " Was he maybe...{WAIT_PRESS}\n"
.string "knocked out?!\0"
.align 2, 0

.global GroudonPreFightDialogue_11
GroudonPreFightDialogue_11: @ 8103054
@ replacing .incbin "baserom.gba", 0x00103054, 0x84
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81030B8
.byte 0x00, 0x00, 0x02, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8103098
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103078

.global gUnknown_8103078
gUnknown_8103078: @ 8103078
.string " Ohh...\n"
.string "It's our turn next.\0"
.align 2, 0

.global gUnknown_8103098
gUnknown_8103098: @ 8103098
.string " Urgh...\n"
.string "It's our turn next.\0"
.align 2, 0

.global gUnknown_81030B8
gUnknown_81030B8: @ 81030B8
.string " Darn it!\n"
.string "It's our turn next.\0"
.align 2, 0

.global GroudonPreFightDialogue_12
GroudonPreFightDialogue_12: @ 81030D8
@ replacing .incbin "baserom.gba", 0x1030D8, 0x38
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81030E4

.global gUnknown_81030E4
gUnknown_81030E4: @ 81030E4
.string " But I'm not going down\n"
.string "without a fight!\0"
.align 2, 0

.global GroudonPreFightDialogue_13
GroudonPreFightDialogue_13: @ 8103110
@ replacing .incbin "baserom.gba", 0x103110, 0x30
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810311C

.global gUnknown_810311C
gUnknown_810311C: @ 810311C
.string "Grgaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global GroudonPreFightDialogue_14
GroudonPreFightDialogue_14: @ 8103140
@ replacing .incbin "baserom.gba", 0x103140, 0x48
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8103174
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103158

.global gUnknown_8103158
gUnknown_8103158: @ 8103158
.string " {POKEMON_0}!\n"
.string "Let's do our best!\0"
.align 2, 0

.global gUnknown_8103174
gUnknown_8103174: @ 8103174
.string " {POKEMON_0}!\n"
.string "Hang tough!\0"
.align 2, 0

.global gGroudonReFightDialogue_1
gGroudonReFightDialogue_1: @ 8103188
@ replacing .incbin "baserom.gba", 0x103188, 0xA0
.byte 0x00, 0x00, 0x02, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81031E4
.byte 0x00, 0x00, 0x02, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_81031A0

.global gUnknown_81031A0
gUnknown_81031A0: @ 81031A0
.string " Here it comes!\n"
.string "{POKEMON_0}!{EXTRA_MSG}"
.string " Let's make sure we subdue\n"
.string "{POKEMON_2} this time!\0"
.align 2, 0

.global gUnknown_81031E4
gUnknown_81031E4: @ 81031E4
.string " Here it comes!\n"
.string "{POKEMON_0}!{EXTRA_MSG}"
.string " We've got to settle\n"
.string "{POKEMON_2} down this time!\0"
.align 2, 0

.global gGroudonReFightDialogue_2
gGroudonReFightDialogue_2: @ 8103228
@ replacing .incbin "baserom.gba", 0x00103228, 0xe8
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81032D8
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x01, 0x00
.4byte gUnknown_8103294
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810324C

.global gUnknown_810324C
gUnknown_810324C: @ 810324C
.string " Don't be intimidated!{EXTRA_MSG}"
.string " We have to fight it with\n"
.string "all our courage!\0"
.align 2, 0

.global gUnknown_8103294
gUnknown_8103294: @ 8103294
.string " Don't be intimidated!{EXTRA_MSG}"
.string " We need to be brave to\n"
.string "face this thing!\0"
.align 2, 0

.global gUnknown_81032D8
gUnknown_81032D8: @ 81032D8
.string " Don't get psyched out!{EXTRA_MSG}"
.string " Be brave and keep slugging!\0"
.align 2, 0

.global gGroudonReFightDialogue_3
gGroudonReFightDialogue_3: @ 8103310
@ replacing .incbin "baserom.gba", 0x00103310, 0x30
.4byte 0x00000005
.4byte 0x00000000
.4byte gUnknown_810331C

.global gUnknown_810331C
gUnknown_810331C: @ 810331C
.string "Grgaaaaaaaah!\n"
.string "                     \0"

.global gGroudonReFightDialogue_4
gGroudonReFightDialogue_4: @ 8103340
@ replacing .incbin "baserom.gba", 0x00103340, 0x60
.byte 0x00, 0x00, 0x03, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_8103378
.byte 0x00, 0x00, 0x03, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103358

.global gUnknown_8103358
gUnknown_8103358: @ 8103358
.string " {POKEMON_0}!\n"
.string "Let's give it our all!\0"
.align 2, 0

.global gUnknown_8103378
gUnknown_8103378: @ 8103378
.string " {POKEMON_0}!\n"
.string "Let's give it what we've got!\0"
.align 2, 0

.global gGroudonPostStoryPreFightDialogue_1
gGroudonPostStoryPreFightDialogue_1: @ 81033A0
@ replacing .incbin "baserom.gba", 0x1033A0, 0xC
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810311C

.global gGroudonPostStoryPreFightDialogue_2
gGroudonPostStoryPreFightDialogue_2: @ 81033AC
@ replacing .incbin "baserom.gba", 0x1033AC, 0x90
.byte 0x00, 0x00, 0x00, 0x0d, 0x9b, 0x01, 0x00, 0x00
.4byte gUnknown_81033B8

.global gUnknown_81033B8
gUnknown_81033B8: @ 81033B8
.string " Why have you returned?!{WAIT_PRESS}\n"
.string "How dare you disturb me in my sleep?!{EXTRA_MSG}"
.string " I let rage run wild before...{WAIT_PRESS}\n"
.string "But I won't allow that again!\0"
.align 2, 0

.global gGroudonPostStoryPreFightDialogue_3
gGroudonPostStoryPreFightDialogue_3: @ 810343C
@ replacing .incbin "baserom.gba", 0x0010343c, 0x40
.4byte 0x0d000000
.4byte 0x0000019b
.4byte gUnknown_8103448

.global gUnknown_8103448
gUnknown_8103448: @ 8103448
.string " Those that disturb my\n"
.string "sleep...{WAIT_PRESS}\n"
.string "Shall be crushed!\0"

.global gGroudonPostStoryPreFightDialogue_4
gGroudonPostStoryPreFightDialogue_4: @ 810347C
@ replacing .incbin "baserom.gba", 0x10347C, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9b, 0x01, 0x00, 0x00
.4byte gUnknown_8102A80

.global gUnknown_8103488
gUnknown_8103488: @ 8103488
@ replacing .incbin "baserom.gba", 0x00103488, 0x78
.4byte 0x00000004
.4byte 0x00000000
.4byte gUnknown_8103494

.global gUnknown_8103494
gUnknown_8103494: @ 8103494
.string "{CENTER_ALIGN}This appears to be the deepest level.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go any farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"

.global gRayquazaPreFightDialogue_1
gRayquazaPreFightDialogue_1: @ 8103500
@ replacing .incbin "baserom.gba", 0x103500, 0x2C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_810350C

.global gUnknown_810350C
gUnknown_810350C: @ 810350C
.string " Is this...{WAIT_PRESS}\n"
.string "The top floor?\0"
.align 2, 0

.global gRayquazaPreFightDialogue_2
gRayquazaPreFightDialogue_2: @ 810352C
@ replacing .incbin "baserom.gba", 0x10352C, 0x4C
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8103538

.global gUnknown_8103538
gUnknown_8103538: @ 8103538
.string " Who goes there?!{WAIT_PRESS}\n"
.string "Who dares to trespass upon my\n"
.string "airspace?!\0"
.align 2, 0

.global gRayquazaPreFightDialogue_3
gRayquazaPreFightDialogue_3: @ 8103578
@ replacing .incbin "baserom.gba", 0x103578, 0x5C
.byte 0x00, 0x00, 0x00, 0x02, 0xaa, 0x01, 0x07, 0x00
.4byte gUnknown_81035B4
.byte 0x00, 0x00, 0x00, 0x02
.byte 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103590

.global gUnknown_8103590
gUnknown_8103590: @ 8103590
.string " That voice...{WAIT_PRESS}\n"
.string "Could it be {POKEMON_2}?\0"
.align 2, 0

.global gUnknown_81035B4
gUnknown_81035B4: @ 81035B4
.string " That voice...{WAIT_PRESS}\n"
.string "Is that {POKEMON_2}?\0"
.align 2, 0

.global gRayquazaPreFightDialogue_4
gRayquazaPreFightDialogue_4: @ 81035D4
@ replacing .incbin "baserom.gba", 0x001035d4, 0x44
.4byte 0x0d800000
.4byte 0x0000019c
.4byte gUnknown_81035E0

.global gUnknown_81035E0
gUnknown_81035E0: @ 81035E0
.string " Indeed I am.{WAIT_PRESS}\n"
.string "The sky is my domain.{EXTRA_MSG}"
.string " Depart at once!\0"
.align 2,0

.global gRayquazaPreFightDialogue_5
gRayquazaPreFightDialogue_5: @ 8103618
@ replacing .incbin "baserom.gba", 0x103618, 0x64
.byte 0x00, 0x00, 0x04, 0x02, 0xaa, 0x01, 0x00, 0x00
.4byte gUnknown_8103624

.global gUnknown_8103624
gUnknown_8103624: @ 8103624
.string " But...\n"
.string "We don't have the time to argue.{EXTRA_MSG}"
.string " We came here because we\n"
.string "need your help...\0"
.align 2, 0

.global gRayquazaPreFightDialogue_6
gRayquazaPreFightDialogue_6: @ 810367C
@ replacing .incbin "baserom.gba", 0x0010367c, 0x14
.4byte 0x0d800000
.4byte 0x0000019c
.4byte gUnknown_8103688

.global gUnknown_8103688
gUnknown_8103688: @ 8103688
.string " Never!\0"
.align 2,0

.global gRayquazaPreFightDialogue_7
gRayquazaPreFightDialogue_7: @ 8103690
@ replacing .incbin "baserom.gba", 0x103690, 0x38
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810369C

.global gUnknown_810369C
gUnknown_810369C: @ 810369C
.string "Gyaaaaaaaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gRayquazaPreFightDialogue_8
gRayquazaPreFightDialogue_8: @ 81036C8
@ replacing .incbin "baserom.gba", 0x1036C8, 0xD8
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_81036D4

.global gUnknown_81036D4
gUnknown_81036D4: @ 81036D4
.string " I am a being of the sky,\n"
.string "and you are but denizens of the ground.{EXTRA_MSG}"
.string " To each, there is a world\n"
.string "destined as their own!{EXTRA_MSG}"
.string " For hundreds of millions of\n"
.string "years, never once have I descended to\n"
.string "the ground!\0"
.align 2, 0

.global gRayquazaPreFightDialogue_9
gRayquazaPreFightDialogue_9: @ 81037A0
@ replacing .incbin "baserom.gba", 0x001037a0, 0x34
.4byte 0x0d000000
.4byte 0x0000019c
.4byte gUnknown_81037AC

.global gUnknown_81037AC
gUnknown_81037AC: @ 81037AC
.string " And the opposite shall also\n"
.string "hold true!\0"
.align 2,0

.global gRayquazaPreFightDialogue_10
gRayquazaPreFightDialogue_10: @ 81037D4
@ replacing .incbin "baserom.gba", 0x1037D4, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_81037E0

.global gUnknown_81037E0
gUnknown_81037E0: @ 81037E0
.string " Let there be no mercy for\n"
.string "those that defy the laws of nature!\0"
.align 2, 0

.global gRayquazaPreFightDialogue_11
gRayquazaPreFightDialogue_11: @ 8103820
@ replacing .incbin "baserom.gba", 0x103820, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_810382C

.global gUnknown_810382C
gUnknown_810382C: @ 810382C
.string " Prepare for the end!\0"
.align 2, 0

.global gRayquazaReFightDialogue_1
gRayquazaReFightDialogue_1: @ 8103844
@ replacing .incbin "baserom.gba", 0x103844, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103850

.global gUnknown_8103850
gUnknown_8103850: @ 8103850
.string " You return, but for no\n"
.string "purpose!\0"
.align 2, 0

.global gRayquazaReFightDialogue_2
gRayquazaReFightDialogue_2: @ 8103874
@ replacing .incbin "baserom.gba", 0x00103874, 0x34
.4byte 0x0d000000
.4byte 0x0000019c
.4byte gUnknown_8103880

.global gUnknown_8103880
gUnknown_8103880: @ 8103880
.string " This is no place for the\n"
.string "likes of you!\0"
.align 2,0

.global gRayquazaReFightDialogue_3
gRayquazaReFightDialogue_3: @ 81038A8
@ replacing .incbin "baserom.gba", 0x1038A8, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_81038B4

.global gUnknown_81038B4
gUnknown_81038B4: @ 81038B4
.string " Let there be no mercy for\n"
.string "those that trespass upon my airspace!\0"
.align 2, 0

.global gRayquazaReFightDialogue_4
gRayquazaReFightDialogue_4: @ 81038F8
@ replacing .incbin "baserom.gba", 0x1038F8, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_810382C

.global gRayquazaPostStoryPreFightDialogue_1
gRayquazaPostStoryPreFightDialogue_1: @ 8103904
@ replacing .incbin "baserom.gba", 0x103904, 0x34
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103910

.global gUnknown_8103910
gUnknown_8103910: @ 8103910
.string "Gyaaaaaaaaaaaah!\n"
.string "                     \0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_2
gRayquazaPostStoryPreFightDialogue_2: @ 8103938
@ replacing .incbin "baserom.gba", 0x103938, 0x16C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103944

.global gUnknown_8103944
gUnknown_8103944: @ 8103944
.string " So it is you who dares to\n"
.string "trespass upon my airspace!{EXTRA_MSG}"
.string " You scaled the Sky Tower...{EXTRA_MSG}"
.string " Now, you wish to challenge\n"
.string "me to a battle?!{EXTRA_MSG}"
.string " ............{WAIT_PRESS}\n"
.string "In destroying the falling star, I sustained\n"
.string "injuries upon my body and my pride...{EXTRA_MSG}"
.string " To better protect my\n"
.string "domain, I have made myself stronger.{EXTRA_MSG}"
.string " And so that I may draw\n"
.string "out my newly gained power...\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_3
gRayquazaPostStoryPreFightDialogue_3: @ 8103AA4
@ replacing .incbin "baserom.gba", 0x103AA4, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103AB0

.global gUnknown_8103AB0
gUnknown_8103AB0: @ 8103AB0
.string " I am now...{WAIT_PRESS}\n"
.string "Unleashing every bit of my might!\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_4
gRayquazaPostStoryPreFightDialogue_4: @ 8103AE4
@ replacing .incbin "baserom.gba", 0x103AE4, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103AF0

.global gUnknown_8103AF0
gUnknown_8103AF0: @ 8103AF0
.string " My power shall overwhelm...{WAIT_PRESS}\n"
.string "But you dare to stand up to it?\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_5
gRayquazaPostStoryPreFightDialogue_5: @ 8103B30
@ replacing .incbin "baserom.gba", 0x103B30, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x9c, 0x01, 0x00, 0x00
.4byte gUnknown_8103B3C

.global gUnknown_8103B3C
gUnknown_8103B3C: @ 8103B3C
.string " I commend your courage!\0"
.align 2, 0

.global gRayquazaPostStoryPreFightDialogue_6
gRayquazaPostStoryPreFightDialogue_6: @ 8103B58
@ replacing .incbin "baserom.gba", 0x103B58, 0x80
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103B64

.global gUnknown_8103B64
gUnknown_8103B64: @ 8103B64
.string "{CENTER_ALIGN}This appears to be\n"
.string "{CENTER_ALIGN}the top of the Sky Tower...{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gUnknown_8103BD8
gUnknown_8103BD8: @ 8103BD8
@ replacing .incbin "baserom.gba", 0x103BD8, 0x28
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103BE4

.global gUnknown_8103BE4
gUnknown_8103BE4: @ 8103BE4
.string " Hunh? What is it, you?\0"
.align 2, 0

.global gUnknown_8103C00
gUnknown_8103C00: @ 8103C00
@ replacing .incbin "baserom.gba", 0x103C00, 0x3C
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103C0C

.global gUnknown_8103C0C
gUnknown_8103C0C: @ 8103C0C
.string " We don't like to brag or\n"
.string "nothing, but...\0"
.align 2, 0

.global gUnknown_8103C3C
gUnknown_8103C3C: @ 8103C3C
@ replacing .incbin "baserom.gba", 0x103C3C, 0x38
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103C48

.global gUnknown_8103C48
gUnknown_8103C48: @ 8103C48
.string " We get furious real easy.\n"
.string "You know that?!\0"
.align 2, 0

.global gUnknown_8103C74
gUnknown_8103C74: @ 8103C74
@ replacing .incbin "baserom.gba", 0x103C74, 0x50
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103C80

.global gUnknown_8103C80
gUnknown_8103C80: @ 8103C80
.string " What really irritates us is\n"
.string "when we see some dim-witted face...\0"
.align 2, 0

.global gUnknown_8103CC4
gUnknown_8103CC4: @ 8103CC4
@ replacing .incbin "baserom.gba", 0x103CC4, 0x48
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103CD0

.global gUnknown_8103CD0
gUnknown_8103CD0: @ 8103CD0
.string " ............{WAIT_PRESS}\n"
.string "Wroooooooar!{WAIT_PRESS}\n"
.string "That vacant expression...\0"
.align 2, 0

.global gUnknown_8103D0C
gUnknown_8103D0C: @ 8103D0C
@ replacing .incbin "baserom.gba", 0x103D0C, 0x44
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103D18

.global gUnknown_8103D18
gUnknown_8103D18: @ 8103D18
.string " Gwooooh!\n"
.string "It's ticking me off!{WAIT_PRESS}\n"
.string "I'm seeing red!\0"
.align 2, 0

.global gUnknown_8103D50
gUnknown_8103D50: @ 8103D50
@ replacing .incbin "baserom.gba", 0x103D50, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103D5C

.global gUnknown_8103D5C
gUnknown_8103D5C: @ 8103D5C
.string " Mukkkeeeeeh!\n"
.string "Get 'em! It's frenzy time!\0"
.align 2, 0

.global gUnknown_8103D8C
gUnknown_8103D8C: @ 8103D8C
@ replacing .incbin "baserom.gba", 0x103D8C, 0xC
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103BE4

.global gUnknown_8103D98
gUnknown_8103D98: @ 8103D98
@ replacing .incbin "baserom.gba", 0x103D98, 0x40
.byte 0x01, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103DA4

.global gUnknown_8103DA4
gUnknown_8103DA4: @ 8103DA4
.string " Are you looking at me...?{WAIT_PRESS}\n"
.string "Are you mocking me?\0"
.align 2, 0

.global gUnknown_8103DD8
gUnknown_8103DD8: @ 8103DD8
@ replacing .incbin "baserom.gba", 0x103DD8, 0x50
.byte 0x01, 0x00, 0x00, 0x0d, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103DE4

.global gUnknown_8103DE4
gUnknown_8103DE4: @ 8103DE4
.string " Gwoooooh!\n"
.string "It's ticking me off!{WAIT_PRESS}\n"
.string "I'm about to blow my fuse!\0"
.align 2, 0

.global gUnknown_8103E28
gUnknown_8103E28: @ 8103E28
@ replacing .incbin "baserom.gba", 0x103E28, 0xC
.byte 0x00, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00
.4byte gUnknown_8103D5C

.global gUnknown_8103E34
gUnknown_8103E34: @ 8103E34
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40

.global gUnknown_8103E40
gUnknown_8103E40: @ 8103E40

.global gUnknown_8103E40
gUnknown_8103E40: @ 8103E40
.string "{CENTER_ALIGN}There appears to be no one here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gMewtwoPreFightDialogue_1
gMewtwoPreFightDialogue_1: @ 8103EA4
@ replacing .incbin "baserom.gba", 0x103EA4, 0x68
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8103EB0

.global gUnknown_8103EB0
gUnknown_8103EB0: @ 8103EB0
.string " ............{WAIT_PRESS}\n"
.string "Was it you...?{EXTRA_MSG}"
.string " ...Who...disturbed...me...in my...\n"
.string "sleep...?{WAIT_PRESS}\n"
.string "Was it you?\0"
.align 2, 0

.global gMewtwoPreFightDialogue_2
gMewtwoPreFightDialogue_2: @ 8103F0C
@ replacing .incbin "baserom.gba", 0x103F0C, 0x40
.byte 0x03, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8103F18

.global gUnknown_8103F18
gUnknown_8103F18: @ 8103F18
.string " My name is {POKEMON_2}.{WAIT_PRESS}\n"
.string "I came into being only to fight.\0"
.align 2, 0

.global gMewtwoPreFightDialogue_3
gMewtwoPreFightDialogue_3: @ 8103F4C
@ replacing .incbin "baserom.gba", 0x103F4C, 0x80
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8103F58

.global gUnknown_8103F58
gUnknown_8103F58: @ 8103F58
.string " I...{WAIT_PRESS}\n"
.string "have secluded myself here in suspended\n"
.string "animation.{EXTRA_MSG}"
.string " Would you like to know\n"
.string "why?{WAIT_PRESS}\n"
.string "It's quite simple...\0"
.align 2, 0

.global gMewtwoPreFightDialogue_4
gMewtwoPreFightDialogue_4: @ 8103FCC
@ replacing .incbin "baserom.gba", 0x103FCC, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8103FD8

.global gUnknown_8103FD8
gUnknown_8103FD8: @ 8103FD8
.string " If anyone--such as you--\n"
.string "were to come along...\0"
.align 2, 0

.global gMewtwoPreFightDialogue_5
gMewtwoPreFightDialogue_5: @ 8104008
@ replacing .incbin "baserom.gba", 0x104008, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8104014

.global gUnknown_8104014
gUnknown_8104014: @ 8104014
.string " I could defeat them at full\n"
.string "power!\n"
.string "Come on!\0"
.align 2, 0

.global gMewtwoReFightDialogue_1
gMewtwoReFightDialogue_1: @ 8104044
@ replacing .incbin "baserom.gba", 0x104044, 0xC
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8103EB0

.global gMewtwoReFightDialogue_2
gMewtwoReFightDialogue_2: @ 8104050
@ replacing .incbin "baserom.gba", 0x104050, 0x7C
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_810405C

.global gUnknown_810405C
gUnknown_810405C: @ 810405C
.string " I...{WAIT_PRESS}\n"
.string "have secluded myself here in suspended\n"
.string "animation...{EXTRA_MSG}"
.string " Lying in wait...{WAIT_PRESS}\n"
.string "For someone like you to come.\0"
.align 2, 0

.global gMewtwoReFightDialogue_3
gMewtwoReFightDialogue_3: @ 81040CC
@ replacing .incbin "baserom.gba", 0x1040CC, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_81040D8

.global gUnknown_81040D8
gUnknown_81040D8: @ 81040D8
.string " I am {POKEMON_2}.{WAIT_PRESS}\n"
.string "A Pokémon created only to fight...{WAIT_PRESS}\n"
.string "And...\0"
.align 2, 0

.global gMewtwoReFightDialogue_4
gMewtwoReFightDialogue_4: @ 8104114
@ replacing .incbin "baserom.gba", 0x104114, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x96, 0x00, 0x00, 0x00
.4byte gUnknown_8104120

.global gUnknown_8104120
gUnknown_8104120: @ 8104120
.string " The most powerful Pokémon\n"
.string "of all!\0"
.align 2, 0

.global gMewtwoReFightDialogue_5
gMewtwoReFightDialogue_5: @ 8104144
@ replacing .incbin "baserom.gba", 0x104144, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40

.global gEnteiPreFightDialogue_1
gEnteiPreFightDialogue_1: @ 8104150
@ replacing .incbin "baserom.gba", 0x104150, 0x5C
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810415C

.global gUnknown_810415C
gUnknown_810415C: @ 810415C
.string " What compelled you to come?{EXTRA_MSG}"
.string " The likes of you have no business\n"
.string "being here!\0"
.align 2, 0

.global gEnteiPreFightDialogue_2
gEnteiPreFightDialogue_2: @ 81041AC
@ replacing .incbin "baserom.gba", 0x1041AC, 0x4C
.byte 0x02, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81041B8

.global gUnknown_81041B8
gUnknown_81041B8: @ 81041B8
.string " I am {POKEMON_2}!{WAIT_PRESS}\n"
.string "I live surrounded by the fiery lava of\n"
.string "volcanoes!\0"
.align 2, 0

.global gEnteiPreFightDialogue_3
gEnteiPreFightDialogue_3: @ 81041F8
@ replacing .incbin "baserom.gba", 0x1041F8, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_8104204

.global gUnknown_8104204
gUnknown_8104204: @ 8104204
.string " If you refuse to leave...{WAIT_PRESS}\n"
.string "I shall forcefully expel you!\0"
.align 2, 0

.global gEnteiReFightDialogue_1
gEnteiReFightDialogue_1: @ 8104240
@ replacing .incbin "baserom.gba", 0x104240, 0x6C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_810424C

.global gUnknown_810424C
gUnknown_810424C: @ 810424C
.string " Did I not say to never\n"
.string "return?{EXTRA_MSG}"
.string " This is the {COLOR YELLOW_D}Fiery Field{RESET}!{WAIT_PRESS}\n"
.string "It is no place for your kind!\0"
.align 2, 0

.global gEnteiReFightDialogue_2
gEnteiReFightDialogue_2: @ 81042AC
@ replacing .incbin "baserom.gba", 0x1042AC, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81041B8

.global gEnteiReFightDialogue_3
gEnteiReFightDialogue_3: @ 81042B8
@ replacing .incbin "baserom.gba", 0x1042B8, 0x58
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81042C4

.global gUnknown_81042C4
gUnknown_81042C4: @ 81042C4
.string " Since you fail to heed my\n"
.string "words...{WAIT_PRESS}\n"
.string "I've no choice but to defeat you!\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_1
gEnteiPostStoryPreFightDialogue_1: @ 8104310
@ replacing .incbin "baserom.gba", 0x104310, 0x8C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_810431C

.global gUnknown_810431C
gUnknown_810431C: @ 810431C
.string " This is the {COLOR YELLOW_D}Fiery Field{RESET}!{WAIT_PRESS}\n"
.string "It is no place for your kind!{EXTRA_MSG}"
.string " I am {POKEMON_2}!{WAIT_PRESS}\n"
.string "I live surrounded by the fiery lava of\n"
.string "volcanoes!\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_2
gEnteiPostStoryPreFightDialogue_2: @ 810439C
@ replacing .incbin "baserom.gba", 0x10439C, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81043A8

.global gUnknown_81043A8
gUnknown_81043A8: @ 81043A8
.string " Depart from here...\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_3
gEnteiPostStoryPreFightDialogue_3: @ 81043C0
@ replacing .incbin "baserom.gba", 0x1043C0, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x01, 0x00, 0x00
.4byte gUnknown_81043CC

.global gUnknown_81043CC
gUnknown_81043CC: @ 81043CC
.string " Immediately!\0"
.align 2, 0

.global gEnteiPostStoryPreFightDialogue_4
gEnteiPostStoryPreFightDialogue_4: @ 81043DC
@ replacing .incbin "baserom.gba", 0x1043DC, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gUnknown_81043E8
gUnknown_81043E8: @ 81043E8
.string "{CENTER_ALIGN}The lord of this area isn't here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0

.global gRaikouPreFightDialogue_1
gRaikouPreFightDialogue_1: @ 8104450
@ replacing .incbin "baserom.gba", 0x104450, 0x64
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810445C

.global gUnknown_810445C
gUnknown_810445C: @ 810445C
.string " Why...{WAIT_PRESS}\n"
.string "Why have you come...?{EXTRA_MSG}"
.string " This is {COLOR YELLOW_D}Lightning Field{RESET}.{WAIT_PRESS}\n"
.string "It is my...{WAIT_PRESS}"
.string "domain!\0"
.align 2, 0

.global gRaikouPreFightDialogue_2
gRaikouPreFightDialogue_2: @ 81044B4
@ replacing .incbin "baserom.gba", 0x1044B4, 0x5C
.byte 0x02, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81044C0

.global gUnknown_81044C0
gUnknown_81044C0: @ 81044C0
.string " I am {POKEMON_2}!{WAIT_PRESS}\n"
.string "One who races with lightning!{EXTRA_MSG}"
.string " A body like roiling rain\n"
.string "clouds!\0"
.align 2, 0

.global gRaikouPreFightDialogue_3
gRaikouPreFightDialogue_3: @ 8104510
@ replacing .incbin "baserom.gba", 0x104510, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_810451C

.global gUnknown_810451C
gUnknown_810451C: @ 810451C
.string " A roar that echoes thunder!\0"
.align 2, 0

.global gRaikouPreFightDialogue_4
gRaikouPreFightDialogue_4: @ 810453C
@ replacing .incbin "baserom.gba", 0x10453C, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104548

.global gUnknown_8104548
gUnknown_8104548: @ 8104548
.string " Many have trespassed upon\n"
.string "my domain...\0"
.align 2, 0

.global gRaikouPreFightDialogue_5
gRaikouPreFightDialogue_5: @ 8104570
@ replacing .incbin "baserom.gba", 0x104570, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_810457C

.global gUnknown_810457C
gUnknown_810457C: @ 810457C
.string " But what became of them?{WAIT_PRESS}\n"
.string "Let me demonstrate...\0"
.align 2, 0

.global gRaikouPreFightDialogue_6
gRaikouPreFightDialogue_6: @ 81045B0
@ replacing .incbin "baserom.gba", 0x1045B0, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81045BC

.global gUnknown_81045BC
gUnknown_81045BC: @ 81045BC
.string " And you, too, shall\n"
.string "experience the pain they suffered!\0"
.align 2, 0

.global gRaikouReFightDialogue_1
gRaikouReFightDialogue_1: @ 81045F8
@ replacing .incbin "baserom.gba", 0x1045F8, 0x7C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104604

.global gUnknown_8104604
gUnknown_8104604: @ 8104604
.string " Snicker... You again.{WAIT_PRESS}\n"
.string "You don't give up easily.{EXTRA_MSG}"
.string " If you so wish to taste\n"
.string "defeat again, I shall oblige!\0"
.align 2, 0

.global gRaikouReFightDialogue_2
gRaikouReFightDialogue_2: @ 8104674
@ replacing .incbin "baserom.gba", 0x104674, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104680

.global gUnknown_8104680
gUnknown_8104680: @ 8104680
.string " With my electric bolts...{WAIT_PRESS}\0"
.align 2, 0

.global gRaikouReFightDialogue_3
gRaikouReFightDialogue_3: @ 81046A0
@ replacing .incbin "baserom.gba", 0x1046A0, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81046AC

.global gUnknown_81046AC
gUnknown_81046AC: @ 81046AC
.string " I will devastate you again!\0"
.align 2, 0

.global gRaikouPostStoryPreFightDialogue_1
gRaikouPostStoryPreFightDialogue_1: @ 81046CC
@ replacing .incbin "baserom.gba", 0x1046CC, 0x78
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81046D8

.global gUnknown_81046D8
gUnknown_81046D8: @ 81046D8
.string " This is {COLOR YELLOW_D}Lightning Field{RESET}!{WAIT_PRESS}\n"
.string "My domain!{EXTRA_MSG}"
.string " All those who enter...{WAIT_PRESS}\n"
.string "I show no mercy, no matter what!\0"
.align 2, 0

.global gRaikouPostStoryPreFightDialogue_2
gRaikouPostStoryPreFightDialogue_2: @ 8104744
@ replacing .incbin "baserom.gba", 0x104744, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_8104750

.global gUnknown_8104750
gUnknown_8104750: @ 8104750
.string " With my electric bolts...\0"
.align 2, 0

.global gRaikouPostStoryPreFightDialogue_3
gRaikouPostStoryPreFightDialogue_3: @ 810476C
@ replacing .incbin "baserom.gba", 0x10476C, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x0c, 0x01, 0x00, 0x00
.4byte gUnknown_81046AC

.global gRaikouPostStoryPreFightDialogue_4
gRaikouPostStoryPreFightDialogue_4: @ 8104778
@ replacing .incbin "baserom.gba", 0x104778, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gSuicunePreFightDialogue_1
gSuicunePreFightDialogue_1: @ 8104784
@ replacing .incbin "baserom.gba", 0x104784, 0xC
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8101D98

.global gSuicunePreFightDialogue_2
gSuicunePreFightDialogue_2: @ 8104790
@ replacing .incbin "baserom.gba", 0x104790, 0x20
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810479C

.global gUnknown_810479C
gUnknown_810479C: @ 810479C
.string " Why are you here?!\0"
.align 2, 0

.global gSuicunePreFightDialogue_3
gSuicunePreFightDialogue_3: @ 81047B0
@ replacing .incbin "baserom.gba", 0x1047B0, 0x9C
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81047BC

.global gUnknown_81047BC
gUnknown_81047BC: @ 81047BC
.string " Clear and bracing air...{WAIT_PRESS}\n"
.string "Crystalline, pure water...{EXTRA_MSG}"
.string " To stand guard over this beautiful and\n"
.string "untainted land...{WAIT_PRESS}\n"
.string "That is why I am here.\0"
.align 2, 0

.global gSuicunePreFightDialogue_4
gSuicunePreFightDialogue_4: @ 810484C
@ replacing .incbin "baserom.gba", 0x10484C, 0x3C
.byte 0x03, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104858

.global gUnknown_8104858
gUnknown_8104858: @ 8104858
.string " I am {POKEMON_2}!{WAIT_PRESS}\n"
.string "One who runs with the north wind!\0"
.align 2, 0

.global gSuicunePreFightDialogue_5
gSuicunePreFightDialogue_5: @ 8104888
@ replacing .incbin "baserom.gba", 0x104888, 0x40
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104894

.global gUnknown_8104894
gUnknown_8104894: @ 8104894
.string " Intruders foul the air\n"
.string "with their outside ills.\0"
.align 2, 0

.global gSuicunePreFightDialogue_6
gSuicunePreFightDialogue_6: @ 81048C8
@ replacing .incbin "baserom.gba", 0x1048C8, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_81048D4

.global gUnknown_81048D4
gUnknown_81048D4: @ 81048D4
.string " There is but one solution\n"
.string "for invaders: expulsion by force!\0"
.align 2, 0

.global gSuicunePreFightDialogue_7
gSuicunePreFightDialogue_7: @ 8104914
@ replacing .incbin "baserom.gba", 0x104914, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104920

.global gUnknown_8104920
gUnknown_8104920: @ 8104920
.string " Here I come!\0"
.align 2, 0

.global gSuicuneReFightDialogue_1
gSuicuneReFightDialogue_1: @ 8104930
@ replacing .incbin "baserom.gba", 0x104930, 0x50
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_810493C

.global gUnknown_810493C
gUnknown_810493C: @ 810493C
.string " This is no place for you!{EXTRA_MSG}"
.string " Leave immediately!{EXTRA_MSG}"
.string " If you refuse...\0"
.align 2, 0

.global gSuicuneReFightDialogue_2
gSuicuneReFightDialogue_2: @ 8104980
@ replacing .incbin "baserom.gba", 0x104980, 0x18
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_810498C

.global gUnknown_810498C
gUnknown_810498C: @ 810498C
.string " I will...\0"
.align 2, 0

.global gSuicuneReFightDialogue_3
gSuicuneReFightDialogue_3: @ 8104998
@ replacing .incbin "baserom.gba", 0x104998, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_81049A4

.global gUnknown_81049A4
gUnknown_81049A4: @ 81049A4
.string " With all my furious power...{WAIT_PRESS}\n"
.string "Destroy you!\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_1
gSuicunePostStoryPreFightDialogue_1: @ 81049D4
@ replacing .incbin "baserom.gba", 0x1049D4, 0xAC
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_81049E0

.global gUnknown_81049E0
gUnknown_81049E0: @ 81049E0
.string " You mean to challenge me?{EXTRA_MSG}"
.string " I find little satisfaction in\n"
.string "fighting...{WAIT_PRESS}\n"
.string "However!{EXTRA_MSG}"
.string " If you refuse my\n"
.string "demands that you leave...{EXTRA_MSG}"
.string " I will accept your challenge.\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_2
gSuicunePostStoryPreFightDialogue_2: @ 8104A80
@ replacing .incbin "baserom.gba", 0x104A80, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104A8C

.global gUnknown_8104A8C
gUnknown_8104A8C: @ 8104A8C
.string " Experience it.\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_3
gSuicunePostStoryPreFightDialogue_3: @ 8104A9C
@ replacing .incbin "baserom.gba", 0x104A9C, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x0e, 0x01, 0x00, 0x00
.4byte gUnknown_8104AA8

.global gUnknown_8104AA8
gUnknown_8104AA8: @ 8104AA8
.string " My true power...{WAIT_PRESS}\n"
.string "Unleashed!\0"
.align 2, 0

.global gSuicunePostStoryPreFightDialogue_4
gSuicunePostStoryPreFightDialogue_4: @ 8104AC8
@ replacing .incbin "baserom.gba", 0x104AC8, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gHoOhPreFightDialogue_1
gHoOhPreFightDialogue_1: @ 8104AD4
@ replacing .incbin "baserom.gba", 0x104AD4, 0x118
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8104AE0

.global gUnknown_8104AE0
gUnknown_8104AE0: @ 8104AE0
.string " Excellent!{EXTRA_MSG}"
.string " You have done well to come this far.{EXTRA_MSG}"
.string " You have overcome countless\n"
.string "challenges...{EXTRA_MSG}"
.string " Fought through many dangerous\n"
.string "situations...{EXTRA_MSG}"
.string " and finally ascended to the very peak\n"
.string "of {COLOR YELLOW_D}Mt. Faraway{RESET}!{EXTRA_MSG}"
.string " Truly, only the chosen have reached\n"
.string "the summit.{EXTRA_MSG}"
.string " However!\0"
.align 2, 0

.global gHoOhPreFightDialogue_2
gHoOhPreFightDialogue_2: @ 8104BEC
@ replacing .incbin "baserom.gba", 0x104BEC, 0x24
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8104BF8

.global gUnknown_8104BF8
gUnknown_8104BF8: @ 8104BF8
.string " This is not the end!\0"
.align 2, 0

.global gHoOhPreFightDialogue_3
gHoOhPreFightDialogue_3: @ 8104C10
@ replacing .incbin "baserom.gba", 0x104C10, 0x44
.byte 0x03, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104C1C

.global gUnknown_8104C1C
gUnknown_8104C1C: @ 8104C1C
.string " I am {POKEMON_2}!{WAIT_PRESS}\n"
.string "The builder of rainbows across the sky!\0"
.align 2, 0

.global gHoOhPreFightDialogue_4
gHoOhPreFightDialogue_4: @ 8104C54
@ replacing .incbin "baserom.gba", 0x104C54, 0x60
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104C60

.global gUnknown_8104C60
gUnknown_8104C60: @ 8104C60
.string " Only when you overcome\n"
.string "me in battle...{WAIT_PRESS}\n"
.string "That is when this mountain is conquered!\0"
.align 2, 0

.global gHoOhPreFightDialogue_5
gHoOhPreFightDialogue_5: @ 8104CB4
@ replacing .incbin "baserom.gba", 0x104CB4, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104CC0

.global gUnknown_8104CC0
gUnknown_8104CC0: @ 8104CC0
.string " This is the final challenge!\0"
.align 2, 0

.global gHoOhPreFightDialogue_6
gHoOhPreFightDialogue_6: @ 8104CE0
@ replacing .incbin "baserom.gba", 0x104CE0, 0xC
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104920

.global HoOhReFightDialogue_1
HoOhReFightDialogue_1: @ 8104CEC
@ replacing .incbin "baserom.gba", 0x104CEC, 0x74
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8104CF8

.global gUnknown_8104CF8
gUnknown_8104CF8: @ 8104CF8
.string " Very good!{EXTRA_MSG}"
.string " You have done well to come this far.{EXTRA_MSG}"
.string " Truly, only the chosen have reached\n"
.string "the summit.\0"
.align 2, 0

.global HoOhReFightDialogue_2
HoOhReFightDialogue_2: @ 8104D60
@ replacing .incbin "baserom.gba", 0x104D60, 0x7C
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104D6C

.global gUnknown_8104D6C
gUnknown_8104D6C: @ 8104D6C
.string " Your very arrival is\n"
.string "evidence of a truly powerful warrior!{WAIT_PRESS}\n"
.string "And...{EXTRA_MSG}"
.string " It is also your right to\n"
.string "challenge me!\0"
.align 2, 0

.global HoOhReFightDialogue_3
HoOhReFightDialogue_3: @ 8104DDC
@ replacing .incbin "baserom.gba", 0x104DDC, 0x30
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104DE8

.global gUnknown_8104DE8
gUnknown_8104DE8: @ 8104DE8
.string " Surpass your own\n"
.string "limitations...\0"
.align 2, 0

.global HoOhReFightDialogue_4
HoOhReFightDialogue_4: @ 8104E0C
@ replacing .incbin "baserom.gba", 0x104E0C, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0x00
.4byte gUnknown_8104E18

.global gUnknown_8104E18
gUnknown_8104E18: @ 8104E18
.string " And show me your power in\n"
.string "its unbridled entirety!\n"
.string "Come on!\0"
.align 2, 0

.global HoOhReFightDialogue_5
HoOhReFightDialogue_5: @ 8104E54
@ replacing .incbin "baserom.gba", 0x104E54, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gLatiosPreFightDialogue_1
gLatiosPreFightDialogue_1: @ 8104E60
@ replacing .incbin "baserom.gba", 0x104E60, 0x9C
.byte 0x02, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104E6C

.global gUnknown_8104E6C
gUnknown_8104E6C: @ 8104E6C
.string " Oh!{WAIT_PRESS}\n"
.string "Who are you?!{EXTRA_MSG}"
.string " ............{WAIT_PRESS}\n"
.string "I see. You're trying to get your TMs back.{EXTRA_MSG}"
.string " But!{EXTRA_MSG}"
.string " Nobody can stop me!{EXTRA_MSG}"
.string " I'm the Eon Pokémon {POKEMON_2}!\0"
.align 2, 0

.global gLatiosPreFightDialogue_2
gLatiosPreFightDialogue_2: @ 8104EFC
@ replacing .incbin "baserom.gba", 0x104EFC, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104F08

.global gUnknown_8104F08
gUnknown_8104F08: @ 8104F08
.string " If you really want your\n"
.string "TMs back...\0"
.align 2, 0

.global gLatiosPreFightDialogue_3
gLatiosPreFightDialogue_3: @ 8104F30
@ replacing .incbin "baserom.gba", 0x104F30, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104F3C

.global gUnknown_8104F3C
gUnknown_8104F3C: @ 8104F3C
.string " You'll have to take them\n"
.string "from me!\0"
.align 2, 0

.global gLatiosReFightDialogue_1
gLatiosReFightDialogue_1: @ 8104F64
@ replacing .incbin "baserom.gba", 0x104F64, 0x64
.byte 0x00, 0x00, 0x00, 0x0d, 0x99, 0x01, 0x00, 0x00
.4byte gUnknown_8104F70

.global gUnknown_8104F70
gUnknown_8104F70: @ 8104F70
.string " You're back?{EXTRA_MSG}"
.string " But!{EXTRA_MSG}"
.string " It doesn't matter how often\n"
.string "you come!{WAIT_PRESS}\n"
.string "Nobody can stop me!\0"
.align 2, 0

.global gUnknown_8104FC8
gUnknown_8104FC8: @ 8104FC8
@ replacing .incbin "baserom.gba", 0x104FC8, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8100D48

.global gRegirockPreFightDialogue_1
gRegirockPreFightDialogue_1: @ 8104FD4
@ replacing .incbin "baserom.gba", 0x104FD4, 0x54
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8104FE0

.global gUnknown_8104FE0
gUnknown_8104FE0: @ 8104FE0
.string "{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}"
.string "{CENTER_ALIGN}EXTERMINATE!{EXTRA_MSG}"
.string "{CENTER_ALIGN}INTRUDER ALERT!{EXTRA_MSG}"
.string "{CENTER_ALIGN}EXTERMINATE!\0"
.align 2, 0

.global gRegicePreFightDialogue_1
gRegicePreFightDialogue_1: @ 8105028
@ replacing .incbin "baserom.gba", 0x105028, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8104FE0

.global gRegisteelPreFightDialogue_1
gRegisteelPreFightDialogue_1: @ 8105034
@ replacing .incbin "baserom.gba", 0x105034, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8104FE0

.global gRegirockPostFightDialogue_1
gRegirockPostFightDialogue_1: @ 8105040
@ replacing .incbin "baserom.gba", 0x105040, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810504C

.global gUnknown_810504C
gUnknown_810504C: @ 810504C
.string "{CENTER_ALIGN}Something fell from\n"
.string "{CENTER_ALIGN}{COLOR CYAN_M}Regirock{RESET}'s body.{EXTRA_MSG}"
.string "{CENTER_ALIGN}{COLOR CYAN_M}Regirock{RESET} was apparently\n"
.string "{CENTER_ALIGN}guarding this item.\0"
.align 2, 0

.global gRegirockPostFightDialogue_2
gRegirockPostFightDialogue_2: @ 81050B4
@ replacing .incbin "baserom.gba", 0x1050B4, 0x58
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81050C0

.global gUnknown_81050C0
gUnknown_81050C0: @ 81050C0
.string "{CENTER_ALIGN}{POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR GREEN_I}Rock Part{RESET}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}that {COLOR CYAN_M}Regirock{RESET} was guarding!\0"
.align 2, 0

.global gRegicePostFightDialogue_1
gRegicePostFightDialogue_1: @ 810510C
@ replacing .incbin "baserom.gba", 0x10510C, 0x70
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105118

.global gUnknown_8105118
gUnknown_8105118: @ 8105118
.string "{CENTER_ALIGN}Something fell from\n"
.string "{CENTER_ALIGN}{COLOR CYAN_M}Regice{RESET}'s body.{EXTRA_MSG}"
.string "{CENTER_ALIGN}{COLOR CYAN_M}Regice{RESET} was apparently\n"
.string "{CENTER_ALIGN}guarding this item.\0"
.align 2, 0

.global gRegicePostFightDialogue_2
gRegicePostFightDialogue_2: @ 810517C
@ replacing .incbin "baserom.gba", 0x10517C, 0x54
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105188

.global gUnknown_8105188
gUnknown_8105188: @ 8105188
.string "{CENTER_ALIGN}{POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR GREEN_I}Ice Part{RESET}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}that {COLOR CYAN_M}Regice{RESET} was guarding!\0"
.align 2, 0

.global gRegisteelPostFightDialogue_1
gRegisteelPostFightDialogue_1: @ 81051D0
@ replacing .incbin "baserom.gba", 0x1051D0, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81051DC

.global gUnknown_81051DC
gUnknown_81051DC: @ 81051DC
.string "{CENTER_ALIGN}Something fell from\n"
.string "{CENTER_ALIGN}{COLOR CYAN_M}Registeel{RESET}'s body.{EXTRA_MSG}"
.string "{CENTER_ALIGN}{COLOR CYAN_M}Registeel{RESET} was apparently\n"
.string "{CENTER_ALIGN}guarding this item.\0"
.align 2, 0

.global gRegisteelPostFightDialogue_2
gRegisteelPostFightDialogue_2: @ 8105244
@ replacing .incbin "baserom.gba", 0x105244, 0xD8
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105250

.global gUnknown_8105250
gUnknown_8105250: @ 8105250
.string "{CENTER_ALIGN}{POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR GREEN_I}Steel Part{RESET}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}that {COLOR CYAN_M}Registeel{RESET} was guarding!\0"
.align 2, 0

.global gUnknown_81052A0
gUnknown_81052A0: @ 81052A0
.string "{CENTER_ALIGN}That means...{EXTRA_MSG}"
.string "{CENTER_ALIGN}By finding the {COLOR GREEN_I}Rock Part{RESET},\n"
.string "{CENTER_ALIGN}{COLOR GREEN_I}Ice Part{RESET}, and {COLOR GREEN_I}Steel Part{RESET}...{EXTRA_MSG}"
.string "{CENTER_ALIGN}All three parts are yours!\0"
.align 2, 0

.global gUnknown_810531C
gUnknown_810531C: @ 810531C
@ replacing .incbin "baserom.gba", 0x10531C, 0x44
.4byte gUnknown_81052A0

.global gUnknown_8105320
gUnknown_8105320: @ 8105320
.string "{CENTER_ALIGN}Oh? The three parts...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}They're reacting to each other?\0"
.align 2, 0

.global gUnknown_8105360
gUnknown_8105360: @ 8105360
@ replacing .incbin "baserom.gba", 0x105360, 0x48
.4byte gUnknown_8105320

.global gUnknown_8105364
gUnknown_8105364: @ 8105364
.string "{CENTER_ALIGN}The three parts\n"
.string "{CENTER_ALIGN}fit together...{EXTRA_MSG}"
.string "{CENTER_ALIGN}and became a {COLOR GREEN_I}Music Box{RESET}!\0"
.align 2, 0

.global gUnknown_81053A8
gUnknown_81053A8: @ 81053A8
@ replacing .incbin "baserom.gba", 0x1053A8, 0x8C
.4byte gUnknown_8105364

.global gUnknown_81053AC
gUnknown_81053AC: @ 81053AC
.string "{CENTER_ALIGN}{POKEMON_0} obtained\n"
.string "{CENTER_ALIGN}the {COLOR GREEN_I}Music Box{RESET}!{EXTRA_MSG}"
.string "{CENTER_ALIGN}The {COLOR GREEN_I}Music Box{RESET} only needs\n"
.string "{CENTER_ALIGN}to be in the Toolbox for it to\n"
.string "{CENTER_ALIGN}attract a special something!\0"
.align 2, 0

.global gUnknown_8105434
gUnknown_8105434: @ 8105434
@ replacing .incbin "baserom.gba", 0x105434, 0x4
.4byte gUnknown_81053AC

.global gJirachiPreFightDialogue_1
gJirachiPreFightDialogue_1: @ 8105438
@ replacing .incbin "baserom.gba", 0x105438, 0x68
.byte 0x00, 0x00, 0x01, 0x0d, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8105444

.global gUnknown_8105444
gUnknown_8105444: @ 8105444
.string " ........................{EXTRA_MSG}"
.string " ......Fwaaaaaaaahhh......{EXTRA_MSG}"
.string " I'm still sleepy...\n"
.string "Fnyumnyum...\0"
.align 2, 0

.global gJirachiPreFightDialogue_2
gJirachiPreFightDialogue_2: @ 81054A0
@ replacing .incbin "baserom.gba", 0x1054A0, 0x44
.byte 0x00, 0x00, 0x01, 0x0d, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81054AC

.global gUnknown_81054AC
gUnknown_81054AC: @ 81054AC
.string " ...Who is it?{EXTRA_MSG}"
.string " Who is that over there?\n"
.string "Fnyumnyum...\0"
.align 2, 0

.global gJirachiPreFightDialogue_3
gJirachiPreFightDialogue_3: @ 81054E4
@ replacing .incbin "baserom.gba", 0x1054E4, 0x28
.byte 0x02, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81054F0

.global gUnknown_81054F0
gUnknown_81054F0: @ 81054F0
.string " I'm {POKEMON_2}.\n"
.string "Who are you?\0"
.align 2, 0

.global gJirachiPreFightDialogue_4
gJirachiPreFightDialogue_4: @ 810550C
@ replacing .incbin "baserom.gba", 0x10550C, 0x40
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105518

.global gUnknown_8105518
gUnknown_8105518: @ 8105518
.string " ......Fwaaaaahhhh......\n"
.string "I'm still...sleepy...\0"
.align 2, 0

.global gUnknown_810554C
gUnknown_810554C: @ 810554C
@ replacing .incbin "baserom.gba", 0x10554C, 0xC
.byte 0x01, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105518

.global gUnknown_8105558
gUnknown_8105558: @ 8105558
@ replacing .incbin "baserom.gba", 0x105558, 0x9C
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105564

.global gUnknown_8105564
gUnknown_8105564: @ 8105564
.string " ...I think I had a dream,\n"
.string "and I was fighting in it...{WAIT_PRESS}\n"
.string "Did I imagine it?{EXTRA_MSG}"
.string " ...I'm sleepy, so I'm going\n"
.string "back to sleep...\n"
.string "Good night...\0"
.align 2, 0

.global gUnknown_81055F4
gUnknown_81055F4: @ 81055F4
@ replacing .incbin "baserom.gba", 0x1055F4, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105600

.global gUnknown_8105600
gUnknown_8105600: @ 8105600
.string "{CENTER_ALIGN}{COLOR CYAN_M}{POKEMON_2}{RESET} fell\n"
.string "{CENTER_ALIGN}back into a deep sleep...{EXTRA_MSG}"
.string "{CENTER_ALIGN}Apparently, {COLOR CYAN_M}{POKEMON_2}{RESET}\n"
.string "{CENTER_ALIGN}was fighting in its sleep...\0"
.align 2, 0

.global gUnknown_8105668
gUnknown_8105668: @ 8105668
@ replacing .incbin "baserom.gba", 0x105668, 0xC
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105518

.global gUnknown_8105674
gUnknown_8105674: @ 8105674
@ replacing .incbin "baserom.gba", 0x105674, 0x44
.byte 0x00, 0x00, 0x01, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105680

.global gUnknown_8105680
gUnknown_8105680: @ 8105680
.string " ...Oh, oh?!\n"
.string "I hear singing...{EXTRA_MSG}"
.string " A song of purity...\0"
.align 2, 0

.global gUnknown_81056B8
gUnknown_81056B8: @ 81056B8
@ replacing .incbin "baserom.gba", 0x1056B8, 0x24
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81056C4

.global gUnknown_81056C4
gUnknown_81056C4: @ 81056C4
.string " Ha!{WAIT_PRESS}\n"
.string "Eyes wide open!\0"
.align 2, 0

.global gUnknown_81056DC
gUnknown_81056DC: @ 81056DC
@ replacing .incbin "baserom.gba", 0x1056DC, 0xBC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81056E8

.global gUnknown_81056E8
gUnknown_81056E8: @ 81056E8
.string " I don't know why, but I'm\n"
.string "wide awake!{EXTRA_MSG}"
.string " I'm {POKEMON_2}.{EXTRA_MSG}"
.string " When I awaken, I grant\n"
.string "a wish.\n"
.string "I have to.{EXTRA_MSG}"
.string " Er-hem...{WAIT_PRESS}\n"
.string "Then...{WAIT_PRESS}"
.string " I ask you this.\0"
.align 2, 0

.global gUnknown_8105778
gUnknown_8105778: @ 8105778
.string "{COLOR YELLOW_N}{POKEMON_2}{RESET}: What is your \n"
.string "wish?\0"
.align 2, 0

.global gUnknown_8105798
gUnknown_8105798: @ 8105798
@ replacing .incbin "baserom.gba", 0x105798, 0x4
.4byte gUnknown_8105778

.global gUnknown_810579C
gUnknown_810579C: @ 810579C
@ replacing .incbin "baserom.gba", 0x10579C, 0x80
.4byte gUnknown_810580C
.byte 0x01, 0x00, 0x00, 0x00
.4byte gUnknown_81057FC
.byte 0x02, 0x00, 0x00, 0x00
.4byte gUnknown_81057EC
.byte 0x03, 0x00, 0x00, 0x00
.4byte gUnknown_81057DC
.byte 0x04, 0x00, 0x00, 0x00
.4byte gUnknown_81057CC
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff

.global gUnknown_81057CC
gUnknown_81057CC: @ 81057CC
.string "Something good!\0"
.align 2, 0

.global gUnknown_81057DC
gUnknown_81057DC: @ 81057DC
.string "More strength.\0"
.align 2, 0

.global gUnknown_81057EC
gUnknown_81057EC: @ 81057EC
.string "A Friend Area.\0"
.align 2, 0

.global gUnknown_81057FC
gUnknown_81057FC: @ 81057FC
.string "Lots of items.\0"
.align 2, 0

.global gUnknown_810580C
gUnknown_810580C: @ 810580C
.string "Lots of money.\0"
.align 2, 0

.global gUnknown_810581C
gUnknown_810581C: @ 810581C
@ replacing .incbin "baserom.gba", 0x10581C, 0x8C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105828

.global gUnknown_8105828
gUnknown_8105828: @ 8105828
.string " You want lots of money?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "I'll gather all the money in the dungeon and\n"
.string "bring it here.{EXTRA_MSG}"
.string " Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_81058A8
gUnknown_81058A8: @ 81058A8
@ replacing .incbin "baserom.gba", 0x1058A8, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81058B4

.global gUnknown_81058B4
gUnknown_81058B4: @ 81058B4
.string " Nnnnnnnnnn!\0"
.align 2, 0

.global gUnknown_81058C4
gUnknown_81058C4: @ 81058C4
@ replacing .incbin "baserom.gba", 0x1058C4, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81058D0

.global gUnknown_81058D0
gUnknown_81058D0: @ 81058D0
.string " Taaaaaaaah!\0"
.align 2, 0

.global gUnknown_81058E0
gUnknown_81058E0: @ 81058E0
@ replacing .incbin "baserom.gba", 0x1058E0, 0x5C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_81058EC

.global gUnknown_81058EC
gUnknown_81058EC: @ 81058EC
.string " ...Fwaaaaaaaahhh...{EXTRA_MSG}"
.string " Using that power...\n"
.string "Made me sleepy...{WAIT_PRESS}\n"
.string "Good night...\0"
.align 2, 0

.global gUnknown_810593C
gUnknown_810593C: @ 810593C
@ replacing .incbin "baserom.gba", 0x10593C, 0x38
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105948

.global gUnknown_8105948
gUnknown_8105948: @ 8105948
.string "{CENTER_ALIGN}{COLOR CYAN_M}{POKEMON_2}{RESET} fell\n"
.string "{CENTER_ALIGN}back into a deep sleep...\0"
.align 2, 0

.global gUnknown_8105974
gUnknown_8105974: @ 8105974
@ replacing .incbin "baserom.gba", 0x105974, 0x94
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105980

.global gUnknown_8105980
gUnknown_8105980: @ 8105980
.string " You want lots of items?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "I'll gather all the good items in the dungeon\n"
.string "and bring them here.{EXTRA_MSG}"
.string " Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_8105A08
gUnknown_8105A08: @ 8105A08
@ replacing .incbin "baserom.gba", 0x105A08, 0xCC
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105A14

.global gUnknown_8105A14
gUnknown_8105A14: @ 8105A14
.string " You want a Friend Area?{EXTRA_MSG}"
.string " ...But...{WAIT_PRESS}\n"
.string "Don't you already have many Friend\n"
.string "Areas?{EXTRA_MSG}"
.string " I can't grant you that wish,\n"
.string "so can you choose another one?{EXTRA_MSG}"
.string " Er-hem...{WAIT_PRESS}\n"
.string "Then...{WAIT_PRESS}"
.string " I ask you again.\0"
.align 2, 0

.global gUnknown_8105AD4
gUnknown_8105AD4: @ 8105AD4
@ replacing .incbin "baserom.gba", 0x105AD4, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105AE0

.global gUnknown_8105AE0
gUnknown_8105AE0: @ 8105AE0
.string " You want a Friend Area?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_8105B20
gUnknown_8105B20: @ 8105B20
@ replacing .incbin "baserom.gba", 0x105B20, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105B2C

.global gUnknown_8105B2C
gUnknown_8105B2C: @ 8105B2C
.string " I opened a new Friend Area\n"
.string "for you. It's yours to use!\0"
.align 2, 0

.global gUnknown_8105B68
gUnknown_8105B68: @ 8105B68
@ replacing .incbin "baserom.gba", 0x105B68, 0x40
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105B74

.global gUnknown_8105B74
gUnknown_8105B74: @ 8105B74
.string "{CENTER_ALIGN}{COLOR CYAN_M}{POKEMON_0}{RESET} obtained\n"
.string "{CENTER_ALIGN}the Friend Area\n"
.string "{CENTER_ALIGN}{COLOR GREEN_H}{MOVE_ITEM_0}{RESET}!\0"
.align 2, 0

.global gUnknown_8105BA8
gUnknown_8105BA8: @ 8105BA8
@ replacing .incbin "baserom.gba", 0x105BA8, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105BB4

.global gUnknown_8105BB4
gUnknown_8105BB4: @ 8105BB4
.string " You want to be stronger?{EXTRA_MSG}"
.string " As you wish.{WAIT_PRESS}\n"
.string "Now...{WAIT_PRESS}\n"
.string "Here goes!\0"
.align 2, 0

.global gUnknown_8105BF4
gUnknown_8105BF4: @ 8105BF4
@ replacing .incbin "baserom.gba", 0x105BF4, 0x138
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105C00

.global gUnknown_8105C00
gUnknown_8105C00: @ 8105C00
.string " I gathered up items from\n"
.string "all over the dungeon that may make you \n"
.string "stronger.{EXTRA_MSG}"
.string " But don't use them now.{WAIT_PRESS}\n"
.string "When you leave the {COLOR YELLOW_D}Wish Cave{RESET}, your\n"
.string "powers go back to their original state.{EXTRA_MSG}"
.string " So, you should only use\n"
.string "those items after you take them back.{EXTRA_MSG}"
.string " I hope you keep working to\n"
.string "become stronger!\0"
.align 2, 0

.global gUnknown_8105D2C
gUnknown_8105D2C: @ 8105D2C
@ replacing .incbin "baserom.gba", 0x105D2C, 0x54
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105D38

.global gUnknown_8105D38
gUnknown_8105D38: @ 8105D38
.string " Something good?{WAIT_PRESS}\n"
.string "That's not very easy...{EXTRA_MSG}"
.string " But I'll do my best!\0"
.align 2, 0

.global gUnknown_8105D80
gUnknown_8105D80: @ 8105D80
@ replacing .incbin "baserom.gba", 0x105D80, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105D8C

.global gUnknown_8105D8C
gUnknown_8105D8C: @ 8105D8C
.string " It's done...\0"
.align 2, 0

.global gUnknown_8105D9C
gUnknown_8105D9C: @ 8105D9C
@ replacing .incbin "baserom.gba", 0x105D9C, 0x78
.byte 0x00, 0x00, 0x00, 0x0d, 0x9d, 0x01, 0x00, 0x00
.4byte gUnknown_8105DA8

.global gUnknown_8105DA8
gUnknown_8105DA8: @ 8105DA8
.string " If you can get home safely,\n"
.string "I think there will be something good\n"
.string "waiting for you.{WAIT_PRESS}"
.string " Maybe.{WAIT_PRESS}"
.string " Definitely.\0"
.align 2, 0

.global gJirachiReFightDialogue_1
gJirachiReFightDialogue_1: @ 8105E14
@ replacing .incbin "baserom.gba", 0x105E14, 0x74
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8105E20

.global gUnknown_8105E20
gUnknown_8105E20: @ 8105E20
.string "{CENTER_ALIGN}The master of this area isn't here.{EXTRA_MSG}"
.string "{CENTER_ALIGN}It's impossible to go farther.{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}It's time to go back.\0"
.align 2, 0
@ Lugia Fight Dialogue

.global gLugiaPreFightDialogue_1
gLugiaPreFightDialogue_1: @ 8105E88
@ replacing .incbin "baserom.gba", 0x105E88, 0x70
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_8105E94

.global gUnknown_8105E94
gUnknown_8105E94: @ 8105E94
.string " Why...{WAIT_PRESS}\n"
.string "Why have you come here...?{EXTRA_MSG}"
.string " This is...{WAIT_PRESS}"
.string "the {COLOR YELLOW_D}Silver Trench{RESET}.{WAIT_PRESS}\n"
.string "This is my territory!\0"
.align 2, 0

.global gLugiaPreFightDialogue_2
gLugiaPreFightDialogue_2: @ 8105EF8
@ replacing .incbin "baserom.gba", 0x105EF8, 0x40
.byte 0x02, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105F04

.global gUnknown_8105F04
gUnknown_8105F04: @ 8105F04
.string " My name is {POKEMON_2}!{WAIT_PRESS}\n"
.string "I am the guardian of the seas!\0"
.align 2, 0

.global gLugiaPreFightDialogue_3
gLugiaPreFightDialogue_3: @ 8105F38
@ replacing .incbin "baserom.gba", 0x105F38, 0x3C
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105F44

.global gUnknown_8105F44
gUnknown_8105F44: @ 8105F44
.string " To protect this sea,\n"
.string "I have settled here...\0"
.align 2, 0

.global gLugiaPreFightDialogue_4
gLugiaPreFightDialogue_4: @ 8105F74
@ replacing .incbin "baserom.gba", 0x105F74, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105F80

.global gUnknown_8105F80
gUnknown_8105F80: @ 8105F80
.string " If you dare to challenge\n"
.string "me...\0"
.align 2, 0

.global gLugiaPreFightDialogue_5
gLugiaPreFightDialogue_5: @ 8105FA0
@ replacing .incbin "baserom.gba", 0x105FA0, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105FAC

.global gUnknown_8105FAC
gUnknown_8105FAC: @ 8105FAC
.string " So be it!\n"
.string "I will rise to your challenge!\0"
.align 2, 0

.global gLugiaPreFightDialogue_6
gLugiaPreFightDialogue_6: @ 8105FD8
@ replacing .incbin "baserom.gba", 0x105FD8, 0x4C
.byte 0x00, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x00
.4byte gUnknown_8105FE4

.global gUnknown_8105FE4
gUnknown_8105FE4: @ 8105FE4
.string " Cast aside all thoughts!{WAIT_PRESS}\n"
.string "Unleash every bit of your power!\0"
.align 2, 0

.global gLugiaPreFightDialogue_7
gLugiaPreFightDialogue_7: @ 8106024
@ replacing .incbin "baserom.gba", 0x106024, 0x44
.byte 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106030

.global gUnknown_8106030
gUnknown_8106030: @ 8106030
.string "{CENTER_ALIGN}With your life at stake...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}Bring it on!{WAIT_PRESS}\n"
.string "{CENTER_ALIGN} {WAIT_PRESS}"
.string "  \0"
.align 2, 0

.global gLugiaPreFightDialogue_8
gLugiaPreFightDialogue_8: @ 8106068
@ replacing .incbin "baserom.gba", 0x106068, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8
@ Kyogre Fight Dialogue

.global gKyogrePreFightDialogue_1
gKyogrePreFightDialogue_1: @ 8106074
@ replacing .incbin "baserom.gba", 0x106074, 0x48
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106080

.global gUnknown_8106080
gUnknown_8106080: @ 8106080
.string "Gwoooooooooooh..................\n"
.string "                         \0"
.align 2, 0

.global gKyogrePreFightDialogue_2
gKyogrePreFightDialogue_2: @ 81060BC
@ replacing .incbin "baserom.gba", 0x1060BC, 0x48
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81060C8

.global gUnknown_81060C8
gUnknown_81060C8: @ 81060C8
.string " ...My power...{WAIT_PRESS}\n"
.string "is bursting...{EXTRA_MSG}"
.string " My infinite...{WAIT_PRESS}\n"
.string "power!\0"
.align 2, 0

.global gKyogrePreFightDialogue_3
gKyogrePreFightDialogue_3: @ 8106104
@ replacing .incbin "baserom.gba", 0x106104, 0x3C
.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106110

.global gUnknown_8106110
gUnknown_8106110: @ 8106110
.string "Gwwwwwoooooooooooh!\n"
.string "                         \0"
.align 2, 0

.global gKyogrePreFightDialogue_4
gKyogrePreFightDialogue_4: @ 8106140
@ replacing .incbin "baserom.gba", 0x106140, 0xD4
.byte 0x00, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_810614C

.global gUnknown_810614C
gUnknown_810614C: @ 810614C
.string " My duels against {POKEMON_3} left\n"
.string "us both exhausted...{WAIT_PRESS}\n"
.string "I took to a long and deep sleep...{EXTRA_MSG}"
.string " All the time, I waited.\n"
.string "Waited for my power to recover.{EXTRA_MSG}"
.string " And now!{WAIT_PRESS}\n"
.string "I am on the verge of regaining my power!\0"
.align 2, 0

.global gKyogrePreFightDialogue_5
gKyogrePreFightDialogue_5: @ 8106214
@ replacing .incbin "baserom.gba", 0x106214, 0x30
.byte 0x02, 0x00, 0x00, 0x0d, 0x9a, 0x01, 0x00, 0x00
.4byte gUnknown_8106220

.global gUnknown_8106220
gUnknown_8106220: @ 8106220
.string " I am {POKEMON_2}!{WAIT_PRESS}\n"
.string "The lord of the sea!\0"
.align 2, 0

.global gKyogrePreFightDialogue_6
gKyogrePreFightDialogue_6: @ 8106244
@ replacing .incbin "baserom.gba", 0x106244, 0x38
.byte 0x00, 0x00, 0x00, 0x0d, 0x9a, 0x01, 0x00, 0x00
.4byte gUnknown_8106250

.global gUnknown_8106250
gUnknown_8106250: @ 8106250
.string " Witness the destructive\n"
.string "force of my waves!\0"
.align 2, 0

.global gKyogrePreFightDialogue_7
gKyogrePreFightDialogue_7: @ 810627C
@ replacing .incbin "baserom.gba", 0x10627C, 0x2C
.byte 0x00, 0x00, 0x00, 0x0d, 0x9a, 0x01, 0x00, 0x00
.4byte gUnknown_8106288

.global gUnknown_8106288
gUnknown_8106288: @ 8106288
.string " Marvel at my awesome\n"
.string "power!\0"
.align 2, 0

.global gKyogrePreFightDialogue_8
gKyogrePreFightDialogue_8: @ 81062A8
@ replacing .incbin "baserom.gba", 0x1062A8, 0xC
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_81043E8

.global gDeoxysPreFightDialogue_1
gDeoxysPreFightDialogue_1: @ 81062B4
@ replacing .incbin "baserom.gba", 0x1062B4, 0x34
.byte 0x02, 0x00, 0x00, 0x00, 0xab, 0x01, 0x00, 0x00
.4byte gUnknown_81062C0

.global gUnknown_81062C0
gUnknown_81062C0: @ 81062C0
.string " ............{EXTRA_MSG}"
.string " Where...{WAIT_PRESS}\n"
.string "Where am I?\0"
.align 2, 0

.global gDeoxysPreFightDialogue_2
gDeoxysPreFightDialogue_2: @ 81062E8
@ replacing .incbin "baserom.gba", 0x1062E8, 0x80
.byte 0x02, 0x00, 0x00, 0x0d, 0x9e, 0x01, 0x00, 0x00
.4byte gUnknown_81062F4

.global gUnknown_81062F4
gUnknown_81062F4: @ 81062F4
.string " There was a sudden explosion...{WAIT_PRESS}\n"
.string "And I awakened to this...{EXTRA_MSG}"
.string " What is this place?{EXTRA_MSG}"
.string " I am {POKEMON_2}.{WAIT_PRESS}\n"
.string "I came from space.\0"
.align 2, 0

.global gDeoxysPreFightDialogue_3
gDeoxysPreFightDialogue_3: @ 8106368
@ replacing .incbin "baserom.gba", 0x106368, 0x28
.byte 0x00, 0x00, 0x00, 0x0d, 0x9e, 0x01, 0x00, 0x00
.4byte gUnknown_8106374

.global gUnknown_8106374
gUnknown_8106374: @ 8106374
.string " If you know, tell me.\0"
.align 2, 0

.global gDeoxysPreFightDialogue_4
gDeoxysPreFightDialogue_4: @ 8106390
@ replacing .incbin "baserom.gba", 0x106390, 0x34
.byte 0x00, 0x00, 0x00, 0x0d, 0x9e, 0x01, 0x00, 0x00
.4byte gUnknown_810639C

.global gUnknown_810639C
gUnknown_810639C: @ 810639C
.string " I must know...{WAIT_PRESS}\n"
.string "what happened here!\0"
.align 2, 0

.global gDeoxysPreFightDialogue_5
gDeoxysPreFightDialogue_5: @ 81063C4
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40
@ Dialogue for Purity Forest

.global gCelebiJoinDialogue_1
gCelebiJoinDialogue_1: @ 81063D0
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestSomeoneThereText

.global gPurityForestSomeoneThereText
gPurityForestSomeoneThereText: @ 81063DC
.string "{CENTER_ALIGN}Oh?{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}There's someone there.\0"
.align 2, 0

.global gCelebiJoinDialogue_2
gCelebiJoinDialogue_2: @ 8106400
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiIntroText

.global gPurityForestCelebiIntroText
gPurityForestCelebiIntroText: @ 810640C
.string "{CENTER_ALIGN}It's...{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}The Time Travel Pokémon {POKEMON_2}!\0"
.align 2, 0

.global gCelebiJoinDialogue_3
gCelebiJoinDialogue_3: @ 810643C
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiWantsToJoinText

.global gPurityForestCelebiWantsToJoinText
gPurityForestCelebiWantsToJoinText: @ 8106448
.string "{CENTER_ALIGN}{POKEMON_2} wants to join the team.\0"
.align 2, 0

.global gCelebiJoinDialogue_4
gCelebiJoinDialogue_4: @ 8106468
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiJoinedText

.global gPurityForestCelebiJoinedText
gPurityForestCelebiJoinedText: @ 8106474
.string "{CENTER_ALIGN}{POKEMON_2} joined the team! \0"
.align 2, 0

.global gCelebiJoinDialogue_5
gCelebiJoinDialogue_5: @ 810648C
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiVeryHappyText

.global gPurityForestCelebiVeryHappyText
gPurityForestCelebiVeryHappyText: @ 8106498
.string "{CENTER_ALIGN}{POKEMON_3} appears to\n"
.string "{CENTER_ALIGN}be very happy!\0"
.align 2, 0

.global gCelebiJoinDialogue_6
gCelebiJoinDialogue_6: @ 81064BC
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiDelightedToJoinText

.global gPurityForestCelebiDelightedToJoinText
gPurityForestCelebiDelightedToJoinText: @ 81064C8
.string "{CENTER_ALIGN}It's delighted to have\n"
.string "{CENTER_ALIGN}joined the rescue team!\0"
.align 2, 0

.global gCelebiJoinDialogue_7
gCelebiJoinDialogue_7: @ 8106500
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestTurnedDownOfferText

.global gPurityForestTurnedDownOfferText
gPurityForestTurnedDownOfferText: @ 810650C
.string "{CENTER_ALIGN}{POKEMON_0} turned down\n"
.string "{CENTER_ALIGN}the offer to join.\0"
.align 2, 0

.global gCelebiJoinDialogue_8
gCelebiJoinDialogue_8: @ 8106534
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiDisappointedText

.global gPurityForestCelebiDisappointedText
gPurityForestCelebiDisappointedText: @ 8106540
.string "{CENTER_ALIGN}Celebi is very disappointed.\0"
.align 2, 0

.global gCelebiJoinDialogue_9
gCelebiJoinDialogue_9: @ 8106560
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gPurityForestCelebiLeftDejectedlyText

.global gPurityForestCelebiLeftDejectedlyText
gPurityForestCelebiLeftDejectedlyText: @ 810656C
.string "{CENTER_ALIGN}{POKEMON_2} left\n"
.string "{CENTER_ALIGN}dejectedly...\0"
.align 2, 0

.global gPurityForestAllowCelebiToJoinText
gPurityForestAllowCelebiToJoinText: @ 8106588
.string "{CENTER_ALIGN}Allow {POKEMON_2}\n"
.string "{CENTER_ALIGN}to join the team?\0"
.align 2, 0

.global gPtrPurityForestAllowCelebiToJoinText
gPtrPurityForestAllowCelebiToJoinText: @ 81065A8
.4byte gPurityForestAllowCelebiToJoinText

.global gPurityForestAllowCelebiToJoinPrompt
gPurityForestAllowCelebiToJoinPrompt: @ 81065AC
.4byte gPurityForestAllowCelebiToJoinYesText
.4byte 0x00000001
.4byte gPurityForestAllowCelebiToJoinNoText
.4byte 0x00000002
.4byte 0x00000000
.4byte 0xFFFFFFFF

.global gPurityForestAllowCelebiToJoinNoText
gPurityForestAllowCelebiToJoinNoText: @ 81065C4
.string "No.\0"
.align 2, 0

.global gPurityForestAllowCelebiToJoinYesText
gPurityForestAllowCelebiToJoinYesText: @ 81065C8
.string "Yes.\0"
.align 2, 0

.global gPurityForestRefuseCelebiConfirmText
gPurityForestRefuseCelebiConfirmText: @ 81065D0
.string "{CENTER_ALIGN}Are you sure?{WAIT_PRESS}\n"
.string "{CENTER_ALIGN}You're sure you won't accept it?\0"
.align 2, 0

.global gPtrPurityForestRefuseCelebiConfirmText
gPtrPurityForestRefuseCelebiConfirmText: @ 810660C
.4byte gPurityForestRefuseCelebiConfirmText

.global gPurityForestRefuseCelebiConfirmPrompt
gPurityForestRefuseCelebiConfirmPrompt: @ 8106610
.4byte gPurityForestRefuseCelebiReconsiderText
.4byte 0x00000001
.4byte gPurityForestRefuseCelebiRefuseText
.4byte 0x00000002
.4byte 0x00000000
.4byte 0xFFFFFFFF

.global gPurityForestRefuseCelebiRefuseText
gPurityForestRefuseCelebiRefuseText: @ 8106628
.string "Refuse.\0"
.align 2, 0

.global gPurityForestRefuseCelebiReconsiderText
gPurityForestRefuseCelebiReconsiderText: @ 8106630
.string "Reconsider.\0"
.align 2, 0

.global gCelebiJoinDialogue_10
gCelebiJoinDialogue_10: @ 810663C
@ replacing .incbin "baserom.gba", 0x10663C, 0x20
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40

.global gUnknown_8106648
gUnknown_8106648: @ 8106648
.string "{CENTER_ALIGN}...............\0"
.align 2, 0

.global gUnknown_810665C
gUnknown_810665C: @ 810665C
@ replacing .incbin "baserom.gba", 0x10665C, 0x30
.4byte gUnknown_8106648

.global gUnknown_8106660
gUnknown_8106660: @ 8106660
.string "{CENTER_ALIGN}Someone has intruded\n"
.string "{CENTER_ALIGN}upon the forest...\0"
.align 2, 0

.global gUnknown_810668C
gUnknown_810668C: @ 810668C
@ replacing .incbin "baserom.gba", 0x10668C, 0x48
.4byte gUnknown_8106660

.global gUnknown_8106690
gUnknown_8106690: @ 8106690
.string "{CENTER_ALIGN}The enfeebled flow of icy winds...\n"
.string "{CENTER_ALIGN}Is the intrusion to blame?\0"
.align 2, 0

.global gUnknown_81066D4
gUnknown_81066D4: @ 81066D4
@ replacing .incbin "baserom.gba", 0x1066D4, 0x1C
.4byte gUnknown_8106690

.global gUnknown_81066D8
gUnknown_81066D8: @ 81066D8
.string "{CENTER_ALIGN}It must be stopped.\0"
.align 2, 0

.global gUnknown_81066F0
gUnknown_81066F0: @ 81066F0
@ replacing .incbin "baserom.gba", 0x1066F0, 0x2C
.4byte gUnknown_81066D8

.global gUnknown_81066F4
gUnknown_81066F4: @ 81066F4
.string "{CENTER_ALIGN}For it is to protect the forest...\0"
.align 2, 0

.global gUnknown_810671C
gUnknown_810671C: @ 810671C
@ replacing .incbin "baserom.gba", 0x10671C, 0x4
.4byte gUnknown_81066F4

.global gUnknown_8106720
gUnknown_8106720: @ 8106720
@ replacing .incbin "baserom.gba", 0x106720, 0x58
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_810672C

.global gUnknown_810672C
gUnknown_810672C: @ 810672C
.string "{CENTER_ALIGN}Defeat the opposing team to win!\n"
.string "{CENTER_ALIGN}Be careful--your opponents are tough!\0"
.align 2, 0

.global gMedichamRescueDialogue_1
gMedichamRescueDialogue_1: @ 8106778
@ replacing .incbin "baserom.gba", 0x106778, 0x44
.byte 0x00, 0x00, 0x04, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_8106784

.global gUnknown_8106784
gUnknown_8106784: @ 8106784
.string " Oh, my, my...\n"
.string "I can't seem to find a way out...\0"
.align 2, 0

.global gMedichamRescueDialogue_2
gMedichamRescueDialogue_2: @ 81067BC
@ replacing .incbin "baserom.gba", 0x1067BC, 0x24
.byte 0x00, 0x00, 0x04, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_81067C8

.global gUnknown_81067C8
gUnknown_81067C8: @ 81067C8
.string " What am I to do...?\0"
.align 2, 0

.global gMedichamRescueDialogue_3
gMedichamRescueDialogue_3: @ 81067E0
@ replacing .incbin "baserom.gba", 0x1067E0, 0x54
.byte 0x00, 0x00, 0x02, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_81067EC

.global gUnknown_81067EC
gUnknown_81067EC: @ 81067EC
.string " Oh!\n"
.string "You?!{EXTRA_MSG}"
.string " ............{WAIT_PRESS}\n"
.string "Perhaps...{EXTRA_MSG}"
.string " You have come to rescue\n"
.string "me?\0"
.align 2, 0

.global gMedichamRescueDialogue_4
gMedichamRescueDialogue_4: @ 8106834
@ replacing .incbin "baserom.gba", 0x106834, 0x58
.byte 0x00, 0x00, 0x01, 0x0d, 0x4d, 0x01, 0x00, 0x00
.4byte gUnknown_8106840

.global gUnknown_8106840
gUnknown_8106840: @ 8106840
.string " Yes, yes!\n"
.string "I am so lucky!\0"
.align 2, 0

.global gUnknown_810685C
gUnknown_810685C: @ 810685C
.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8106868

.global gUnknown_8106868
gUnknown_8106868: @ 8106868
.string "{CENTER_ALIGN}There appears to be no one here.\0"
.align 2, 0

.global gSmeargleRescueDialogue_1
gSmeargleRescueDialogue_1: @ 810688C
@ replacing .incbin "baserom.gba", 0x10688C, 0x44
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_8106898

.global gUnknown_8106898
gUnknown_8106898: @ 8106898
.string " Ohhh...\n"
.string "I've lost my bearings...{WAIT_PRESS}\n"
.string "Where is this?\0"
.align 2, 0

.global gSmeargleRescueDialogue_2
gSmeargleRescueDialogue_2: @ 81068D0
@ replacing .incbin "baserom.gba", 0x1068D0, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_81068DC

.global gUnknown_81068DC
gUnknown_81068DC: @ 81068DC
.string " I can't get out...\n"
.string "I'm hungry...{WAIT_PRESS}\n"
.string "I'm in trouble...\0"
.align 2, 0

.global gSmeargleRescueDialogue_3
gSmeargleRescueDialogue_3: @ 8106918
@ replacing .incbin "baserom.gba", 0x106918, 0x1C
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_8106924

.global gUnknown_8106924
gUnknown_8106924: @ 8106924
.string " Oh!\n"
.string "You are?!\0"
.align 2, 0

.global gSmeargleRescueDialogue_4
gSmeargleRescueDialogue_4: @ 8106934
@ replacing .incbin "baserom.gba", 0x106934, 0x48
.byte 0x00, 0x00, 0x00, 0x0d, 0x04, 0x01, 0x00, 0x00
.4byte gUnknown_8106940

.global gUnknown_8106940
gUnknown_8106940: @ 8106940
.string " Did you maybe come to\n"
.string "rescue me?{WAIT_PRESS}\n"
.string "Am I glad to see you!\0"
.align 2, 0

.global gUnknown_810697C
gUnknown_810697C: @ 810697C
.byte 0x04, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00
.4byte gUnknown_8103E40
