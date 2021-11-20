        .section .rodata

	.global gFriendAreaDialogue
gFriendAreaDialogue: @ 813237C
@ replacing .incbin "baserom.gba", 0x0013237c, 0x13d610
    .4byte FriendAreaFullEnergy
    .4byte FriendAreaLikesPlace
    .4byte FriendAreaVeryHappy
    .4byte FriendAreaGrinning
    .4byte FriendAreaStraight
    .4byte FriendAreaHappy
    .4byte FriendAreaRelax
    .4byte FriendAreaTense
    .4byte FriendAreaMood
    .4byte FriendAreaFidge
    .4byte FriendAreaDeep
    .4byte FriendAreaWorried
    .4byte FriendAreaEager
    .4byte FriendAreaGrin
    .4byte FriendAreaPensive
    .4byte FriendAreaAnxious
    .4byte FriendAreaGummi
    .4byte FriendAreaSleepyEnergy

    .global FriendAreaSleepyEnergy
    FriendAreaSleepyEnergy:
    .string "#+It appears to be a little sleepy{COMMA}\n"
    .string "#+but it{APOSTROPHE}s still full of energy.\0"
    .align 2,0

    .global FriendAreaGummi
    FriendAreaGummi:
    .string "#+It may want a Gummi.\0"
    .align 2,0

    .global FriendAreaAnxious
    FriendAreaAnxious:
    .string "#+It appears to be very anxious\n"
    .string "#+to go on an adventure.\0"
    .align 2,0

    .global FriendAreaPensive
    FriendAreaPensive:
    .string "#+It looked pensive for a moment{COMMA}\n"
    .string "#+but it{APOSTROPHE}s grinning widely again.\0"
    .align 2,0

    .global FriendAreaGrin
    FriendAreaGrin:
    .string "#+It{APOSTROPHE}s looking this way with a grin.\0"
    .align 2,0

    .global FriendAreaEager
    FriendAreaEager:
    .string "#+It appears very eager\n"
    .string "#+to go to a dungeon.\0"
    .align 2,0

    .global FriendAreaWorried
    FriendAreaWorried:
    .string "#+It appeared to have been worried{COMMA}\n"
    .string "#+but seems to have solved it.\0"
    .align 2,0

    .global FriendAreaDeep
    FriendAreaDeep:
    .string "#+It suddenly appears to be deep in thought.\0"
    .align 2,0

    .global FriendAreaFidge
    FriendAreaFidge:
    .string "#+It suddenly turned fidgety.\0"
    .align 2,0

    .global FriendAreaMood
    FriendAreaMood:
    .string "#+Its mood appears to have changed.\0"
    .align 2,0

    .global FriendAreaTense
    FriendAreaTense:
    .string "#+It appears to be a little tense.\0"
    .align 2,0

    .global FriendAreaRelax
    FriendAreaRelax:
    .string "#+It is relaxing at its favorite spot.\0"
    .align 2,0

    .global FriendAreaHappy
    FriendAreaHappy:
    .string "#+It is very happy!\0"
    .align 2,0

    .global FriendAreaStraight
    FriendAreaStraight:
    .string "#+It{APOSTROPHE}s trying to keep a straight face{COMMA}\n"
    .string "#+but it can{APOSTROPHE}t stop laughing!\0"
    .align 2,0

    .global FriendAreaGrinning
    FriendAreaGrinning:
    .string "#+It is grinning happily.\0"
    .align 2,0

    .global FriendAreaVeryHappy
    FriendAreaVeryHappy:
    .string "#+It appears to be very happy!\0"
    .align 2,0

    .global FriendAreaLikesPlace
    FriendAreaLikesPlace:
    .string "#+It appears to like this place a lot!\0"
    .align 2,0

    .global FriendAreaFullEnergy
    FriendAreaFullEnergy:
    .string "#+It seems to be full of energy!\0"
    .align 2,0

    .string "pksdir0\0"
    .align 2,0

