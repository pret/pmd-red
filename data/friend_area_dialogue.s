        .section .rodata

    .string "pksdir0\0"
    .align 2,0

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
    .string "{CENTER_ALIGN}It appears to be a little sleepy,\n"
    .string "{CENTER_ALIGN}but it's still full of energy.\0"
    .align 2,0

    .global FriendAreaGummi
    FriendAreaGummi:
    .string "{CENTER_ALIGN}It may want a Gummi.\0"
    .align 2,0

    .global FriendAreaAnxious
    FriendAreaAnxious:
    .string "{CENTER_ALIGN}It appears to be very anxious\n"
    .string "{CENTER_ALIGN}to go on an adventure.\0"
    .align 2,0

    .global FriendAreaPensive
    FriendAreaPensive:
    .string "{CENTER_ALIGN}It looked pensive for a moment,\n"
    .string "{CENTER_ALIGN}but it's grinning widely again.\0"
    .align 2,0

    .global FriendAreaGrin
    FriendAreaGrin:
    .string "{CENTER_ALIGN}It's looking this way with a grin.\0"
    .align 2,0

    .global FriendAreaEager
    FriendAreaEager:
    .string "{CENTER_ALIGN}It appears very eager\n"
    .string "{CENTER_ALIGN}to go to a dungeon.\0"
    .align 2,0

    .global FriendAreaWorried
    FriendAreaWorried:
    .string "{CENTER_ALIGN}It appeared to have been worried,\n"
    .string "{CENTER_ALIGN}but seems to have solved it.\0"
    .align 2,0

    .global FriendAreaDeep
    FriendAreaDeep:
    .string "{CENTER_ALIGN}It suddenly appears to be deep in thought.\0"
    .align 2,0

    .global FriendAreaFidge
    FriendAreaFidge:
    .string "{CENTER_ALIGN}It suddenly turned fidgety.\0"
    .align 2,0

    .global FriendAreaMood
    FriendAreaMood:
    .string "{CENTER_ALIGN}Its mood appears to have changed.\0"
    .align 2,0

    .global FriendAreaTense
    FriendAreaTense:
    .string "{CENTER_ALIGN}It appears to be a little tense.\0"
    .align 2,0

    .global FriendAreaRelax
    FriendAreaRelax:
    .string "{CENTER_ALIGN}It is relaxing at its favorite spot.\0"
    .align 2,0

    .global FriendAreaHappy
    FriendAreaHappy:
    .string "{CENTER_ALIGN}It is very happy!\0"
    .align 2,0

    .global FriendAreaStraight
    FriendAreaStraight:
    .string "{CENTER_ALIGN}It's trying to keep a straight face,\n"
    .string "{CENTER_ALIGN}but it can't stop laughing!\0"
    .align 2,0

    .global FriendAreaGrinning
    FriendAreaGrinning:
    .string "{CENTER_ALIGN}It is grinning happily.\0"
    .align 2,0

    .global FriendAreaVeryHappy
    FriendAreaVeryHappy:
    .string "{CENTER_ALIGN}It appears to be very happy!\0"
    .align 2,0

    .global FriendAreaLikesPlace
    FriendAreaLikesPlace:
    .string "{CENTER_ALIGN}It appears to like this place a lot!\0"
    .align 2,0

    .global FriendAreaFullEnergy
    FriendAreaFullEnergy:
    .string "{CENTER_ALIGN}It seems to be full of energy!\0"
    .align 2,0

