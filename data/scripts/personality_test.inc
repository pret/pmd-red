    @ Personality Test
    PersonalityTestMainThread:
    .byte 0xf6, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte PersonalityTestScriptsFile_Text
    changeTileset 0xDF
    pushR14
    msgEnd 0x163

    PersonalityTestScriptsFile_Text:
    .string "../data/ground/ground_data_s01_station.c\0"
    .align 2,0

    .global gUnknown_826DFEC
    gUnknown_826DFEC:
    .byte 0x94, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte PersonalityTestMainThread

    PersonalityTest1MainThread:
    .global gUnknown_826DFF8
    gUnknown_826DFF8:
    .byte 0xf6, 0x00, 0x13, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte PersonalityTestScriptsFile_Text
    pushR14
    changeTileset 0xDF
    floatingText Welcome_826E1F4
    floatingText WorldOfPokemon_826E1B8
    floatingText SeveralQuestions_826E16C
    floatingText AnswerSincerely_826E144
    floatingText AreYouReady_826E130
    floatingText InterviewBegin_826E108
    closeTextBox
    StartSceneRunCall 0
    playMusic MUS_WELCOME_TO_THE_WORLD_OF_POKEMON
    .byte 0x22, 0x01, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x3c, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    fadeMusicOut 0x1E
    fadeOut 1 0x1E 0
    endFuncAndScript

    InterviewBegin_826E108:
    .string "{CENTER_ALIGN}OK...{WAIT_PRESS}\n"
    .string "{CENTER_ALIGN}Let the interview begin!\0"
    .align 2,0

    AreYouReady_826E130:
    .string "{CENTER_ALIGN}Are you ready?\0"
    .align 2,0

    AnswerSincerely_826E144:
    .string "{CENTER_ALIGN}I want you to answer them sincerely.\0"
    .align 2,0

    SeveralQuestions_826E16C:
    .string "{CENTER_ALIGN}But before I can let you through,\n"
    .string "{CENTER_ALIGN}I have several questions for you.\0"
    .align 2,0

    WorldOfPokemon_826E1B8:
    .string "{CENTER_ALIGN}This is the portal that leads\n"
    .string "{CENTER_ALIGN}to the world of Pokémon!\0"
    .align 2,0

    Welcome_826E1F4:
    .string "{CENTER_ALIGN}Welcome!\0"
    .align 2,0

    .global gUnknown_826E200
    gUnknown_826E200:
    .byte 0x90, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte gUnknown_826DFF8
    .global gUnknown_826E20C
    gUnknown_826E20C:
    .byte 0x00, 0x00, 0x01, 0x01, 0x1e, 0x13, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00
    .global gUnknown_826E218
    gUnknown_826E218:
    .4byte gUnknown_826DFEC
    .global gUnknown_826E21C
    gUnknown_826E21C:
    .4byte gUnknown_826E200
    .global gUnknown_826E220
    gUnknown_826E220:
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .4byte gUnknown_826E218
    .global gUnknown_826E248
    gUnknown_826E248:
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .4byte gUnknown_826E20C
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .4byte gUnknown_826E21C

    PersonalityTestScenes: @ 826E270
    .byte 0x01, 0x00, 0x00, 0x00
    .4byte gUnknown_826E220
    .byte 0x01, 0x00, 0x00, 0x00
    .4byte gUnknown_826E248

    PersonalityTestWaypoints: @ 826E280
    .byte 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00

    .global gGroundScript_gs223
    gGroundScript_gs223:
    .byte 0x02, 0x00, 0x00, 0x00
    .4byte PersonalityTestScenes
    .4byte PersonalityTestWaypoints
