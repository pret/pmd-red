    @ Title Screen
    TitleScreenMainThread:
    .byte 0xf6, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    changeTileset 0xE0
    pushR14
    msgEnd 0x163

    .global GroundDataS02StationFile_Text @ 0x826E2DC
    GroundDataS02StationFile_Text:
    .string "../data/ground/ground_data_s02_station.c\0"
    .align 2,0

    .byte 0x94, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte TitleScreenMainThread

    .byte 0xf6, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    setAnimation 7
    waitFlag 4

    @ Blink "Press Start"
    label 0
    warpToLoc 1
    pause 10
    warpToLoc 0
    pause 10
    loopLabel 0

    TitleScreen2MainThread:
    .byte 0xf6, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    changeTileset 0xE0
    .byte 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    StartSceneRunCall 0
    PlayMusic MUS_OPENING_TITLE
    pause 0x3C
    .byte 0x22, 0x01, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    pause 0x1E0
    fadeMusicOut 0x1E
    fadeOut 1 0x1E 0
    endFuncAndScript

    .byte 0x90, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte TitleScreen2MainThread

    TitleScreen3MainThread:
    .byte 0xf6, 0x00, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    changeTileset 0xE0
    .byte 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    StartSceneRunCall 0
    PlayMusic MUS_TITLE_SCREEN
    fadeColorOut 1 1 0x3C 0x00ffffff
    StartSceneRunCall 1
    StartSceneRunCall 2
    waitFlag 3
    .byte 0xa6, 0x00, 0x39, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x3b, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    pause 0x78
    setFlag 4
    .byte 0xe0, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    pause 0x3C
    fadeOut 1 0x1E 0
    endFuncAndScript

    .byte 0x90, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte TitleScreen3MainThread

    .byte 0xf6, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    .byte 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    waitFlag 4
    label 0
    warpToLoc 3
    pause 0xA
    warpToLoc 2
    pause 0xA
    loopLabel 0

    .byte 0xf6, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    .byte 0x53, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setAnimation 5
    .byte 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    waitFlag 5
    .byte 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x8b, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x80, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setFlag 6
    closeThreadRemoveObject

    .byte 0xf6, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    .byte 0x53, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setAnimation 7
    .byte 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    waitFlag 6
    pause 0x20
    .byte 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setAnimation 0xA
    .byte 0x80, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setAnimation 0xB
    .byte 0x80, 0x00, 0x00, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setAnimation 0xC
    .byte 0x80, 0x00, 0x00, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setAnimation 0xD
    .byte 0x80, 0x00, 0x00, 0x07, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setFlag 3
    closeThreadRemoveObject

    .byte 0xf6, 0x00, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    .byte 0x53, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setAnimation 0x8
    .byte 0x80, 0x00, 0x33, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    setFlag 5
    .byte 0x80, 0x00, 0x33, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    closeThreadRemoveObject

    TitleScreen4MainThread:
    .byte 0xf6, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    changeTileSet 0xE0
    .byte 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x0c, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    PlayMusic MUS_TITLE_SCREEN
    .byte 0x22, 0x01, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    pause 0x78
    setFlag 4
    .byte 0xe0, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    pause 0x3C
    fadeOut 1 0x1E 0
    endFuncAndScript

    .byte 0x90, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte TitleScreen4MainThread

    .byte 0xf6, 0x00, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .4byte GroundDataS02StationFile_Text
    .byte 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    waitFlag 4
    label 0
    warpToLoc 3
    pause 0xA
    warpToLoc 2
    pause 0xA
    loopLabel 0

    .byte 0x37, 0x06, 0x00, 0x00
    .byte 0x23, 0x06, 0x00, 0x02
    .byte 0x0c, 0xe6, 0x26, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x02, 0x01, 0x12, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x14, 0xe3, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x06, 0x02, 0x01, 0x01, 0x16, 0x00, 0x02, 0xdc, 0xe6, 0x26, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x02, 0x01, 0x1a, 0x00, 0x00, 0x02
    .byte 0x1c, 0xe8, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01
    .byte 0x12, 0x0e, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x12, 0x0e, 0x00, 0x02, 0x7c, 0xe5, 0x26, 0x08, 0x00, 0x00, 0x01, 0x01, 0x12, 0x0e, 0x00, 0x02
    .byte 0x88, 0xe9, 0x26, 0x08
    .byte 0x08, 0xe3, 0x26, 0x08
    .byte 0x54, 0xe4, 0x26, 0x08
    .byte 0x70, 0xe5, 0x26, 0x08
    .byte 0x7c, 0xe9, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .byte 0x9c, 0xea, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0x30, 0xea, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .byte 0x78, 0xea, 0x26, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0xa0, 0xea, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x84, 0xea, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .byte 0xa4, 0xea, 0x26, 0x08
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0x18, 0xea, 0x26, 0x08
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0x48, 0xea, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0x60, 0xea, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .byte 0x90, 0xea, 0x26, 0x08
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0xa8, 0xea, 0x26, 0x08
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0xac, 0xea, 0x26, 0x08
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0xd4, 0xea, 0x26, 0x08
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0xfc, 0xea, 0x26, 0x08
    .byte 0x03, 0x00, 0x00, 0x00
    .byte 0x24, 0xeb, 0x26, 0x08
    .byte 0x01, 0x00, 0x00, 0x00
    .byte 0x9c, 0xeb, 0x26, 0x08

    TitleWaypoints:
    .byte 0x12, 0x15, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00
    .byte 0x12, 0x30, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00
    .byte 0x12, 0x0e, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x12, 0x29, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x01, 0x06, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x0a, 0x14, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x13, 0x10, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x1c, 0x0a, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x23, 0x04, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x1a, 0x06, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01
    .byte 0x1a, 0x0c, 0x00, 0x00, 0x01, 0x01, 0x02, 0x01

    .byte 0x05, 0x00, 0x00, 0x00
    .byte 0xc4, 0xeb, 0x26, 0x08
    .4byte TitleWaypoints
