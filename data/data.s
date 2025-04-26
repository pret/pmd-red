	.section .rodata

	.align 2, 0

    @ event_flag.c

    .global EventFlagFile_Text
    EventFlagFile_Text:
    .string "../main/event_flag.c\0"
    .align 2,0

    .global FlagCalc_Text
    FlagCalc_Text:
    .string "_FlagCalc\0"
    .align 2,0

    .global gUnknown_80B7318
    gUnknown_80B7318: @ 80B7318
    .4byte EventFlagFile_Text
    .byte 0x51, 0x05, 0x00, 0x00
    .4byte FlagCalc_Text

    .global gUnknown_80B7324
    gUnknown_80B7324: @ 80B7324
    .string "event flag expansion error %d\0"
    .align 2,0

    .global FlagJudge_Text
    FlagJudge_Text:
    .string "_FlagJudge\0"
    .align 2,0

	.global gUnknown_80B7350
gUnknown_80B7350: @ 80B7350
        .4byte EventFlagFile_Text
        .byte 0x7C, 0x05, 0x00, 0x00
        .4byte FlagJudge_Text

	.global gUnknown_80B735C
gUnknown_80B735C: @ 80B735C
        .string "event flag rule error %d\0"
        .align 2,0

	.global gUnknown_80B7378
gUnknown_80B7378: @ 80B7378
        .string "error number\0"
        .align 2,0

	.global gUnknown_80B7388
gUnknown_80B7388: @ 80B7388
        .string "1-1\0"

@ code.c
.string "pksdir0\0"

	.global gScriptVarInfo
gScriptVarInfo: @ 80B7394
    .2byte 6, 2, 0, 0, 1, 29; .4byte gUnknown_80B7DF8
    .2byte 6, 2, 4, 0, 1, 0; .4byte gUnknown_80B7DEC
    .2byte 2, 2, 110, 0, 2, 0; .4byte gUnknown_80B7DDC
    .2byte 2, 2, 112, 0, 2, 0; .4byte gUnknown_80B7DCC
    .2byte 2, 2, 114, 0, 2, 0; .4byte gUnknown_80B7DBC
    .2byte 2, 2, 116, 0, 2, 0; .4byte gUnknown_80B7DAC
    .2byte 2, 2, 118, 0, 2, 0; .4byte gUnknown_80B7D9C
    .2byte 2, 2, 120, 0, 2, 0; .4byte gUnknown_80B7D8C
    .2byte 2, 2, 122, 0, 2, 0; .4byte gUnknown_80B7D7C
    .2byte 2, 2, 124, 0, 2, 0; .4byte gUnknown_80B7D6C
    .2byte 2, 2, 126, 0, 2, 0; .4byte gUnknown_80B7D5C
    .2byte 2, 2, 128, 0, 2, 0; .4byte gUnknown_80B7D4C
    .2byte 2, 2, 130, 0, 2, 0; .4byte gUnknown_80B7D3C
    .2byte 5, 2, 44, 0, 1, 0; .4byte gUnknown_80B7D2C
    .2byte 2, 2, 132, 0, 1, 0; .4byte gUnknown_80B7D18
    .2byte 5, 2, 46, 0, 1, 0; .4byte gUnknown_80B7D08
    .2byte 5, 2, 48, 0, 1, 0; .4byte gUnknown_80B7CFC
    .2byte 5, 2, 50, 0, 1, 0; .4byte gUnknown_80B7CEC
    .2byte 5, 2, 52, 0, 1, 0; .4byte gUnknown_80B7CDC
    .2byte 5, 2, 54, 0, 1, 0; .4byte gUnknown_80B7CCC
    .2byte 5, 2, 56, 0, 1, 0; .4byte gUnknown_80B7CB8
    .2byte 4, 2, 94, 0, 1, 0; .4byte gUnknown_80B7CA0
    .2byte 2, 2, 133, 0, 1, 0; .4byte gUnknown_80B7C90
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7C84
    .2byte 2, 2, 134, 0, 1, 0; .4byte gUnknown_80B7C78
    .2byte 2, 2, 135, 0, 1, 0; .4byte gUnknown_80B7C6C
    .2byte 2, 2, 136, 0, 1, 0; .4byte gUnknown_80B7C5C
    .2byte 3, 2, 96, 0, 1, 0; .4byte gUnknown_80B7C4C
    .2byte 2, 2, 137, 0, 1, 0; .4byte gUnknown_80B7C40
    .2byte 2, 2, 138, 0, 1, 0; .4byte gUnknown_80B7C30
    .2byte 2, 2, 139, 0, 1, 0; .4byte gUnknown_80B7C20
    .2byte 5, 2, 58, 0, 1, 0; .4byte gUnknown_80B7C10
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7C04
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7BF8
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7BF0
    .2byte 8, 2, 0, 0, 1, 0; .4byte gUnknown_80B7BE4
    .2byte 1, 2, 140, 0, 16, 0; .4byte gUnknown_80B7BD8
    .2byte 3, 2, 97, 0, 1, 0; .4byte gUnknown_80B7BCC
    .2byte 3, 2, 98, 0, 1, 0; .4byte gUnknown_80B7BB8
    .2byte 3, 2, 99, 0, 1, 0; .4byte gUnknown_80B7BAC
    .2byte 3, 2, 100, 0, 1, 0; .4byte gUnknown_80B7BA0
    .2byte 3, 2, 101, 0, 1, 0; .4byte gUnknown_80B7B94
    .2byte 3, 2, 102, 0, 1, 0; .4byte gUnknown_80B7B78
    .2byte 1, 2, 142, 0, 64, 0; .4byte gUnknown_80B7B5C
    .2byte 1, 2, 150, 0, 64, 0; .4byte gUnknown_80B7B40
    .2byte 1, 2, 158, 0, 64, 0; .4byte gUnknown_80B7B20
    .2byte 1, 2, 166, 0, 32, 0; .4byte gUnknown_80B7B08
    .2byte 1, 2, 170, 0, 32, 0; .4byte gUnknown_80B7AF0
    .2byte 1, 2, 174, 0, 96, 0; .4byte gUnknown_80B7ADC
    .2byte 1, 2, 186, 0, 96, 0; .4byte gUnknown_80B7AC8
    .2byte 6, 2, 8, 0, 3, 0; .4byte gUnknown_80B7ABC
    .2byte 6, 2, 20, 0, 3, 0; .4byte gUnknown_80B7AB0
    .2byte 6, 2, 32, 0, 3, 0; .4byte gUnknown_80B7AA0
    .2byte 3, 2, 103, 0, 3, 0; .4byte gUnknown_80B7A8C
    .2byte 5, 5, 60, 0, 1, 0; .4byte gUnknown_80B7A7C
    .2byte 5, 5, 62, 0, 1, 0; .4byte gUnknown_80B7A70
    .2byte 1, 5, 198, 0, 8, 0; .4byte gUnknown_80B7A60
    .2byte 5, 5, 64, 0, 1, 0; .4byte gUnknown_80B7A54
    .2byte 1, 5, 199, 0, 32, 0; .4byte gUnknown_80B7A40
    .2byte 1, 5, 203, 0, 32, 0; .4byte gUnknown_80B7A2C
    .2byte 1, 5, 207, 0, 16, 0; .4byte gUnknown_80B7A18
    .2byte 1, 5, 209, 0, 16, 0; .4byte gUnknown_80B7A04
    .2byte 5, 5, 66, 0, 8, 0; .4byte gUnknown_80B79F8
    .2byte 1, 5, 211, 0, 16, 0; .4byte gUnknown_80B79EC
    .2byte 1, 6, 213, 0, 16, 0; .4byte gUnknown_80B79DC
    .2byte 5, 6, 82, 0, 2, 0; .4byte gUnknown_80B79CC
    .2byte 5, 6, 86, 0, 4, 0; .4byte gUnknown_80B79C0
    .2byte 3, 6, 106, 0, 1, 0; .4byte gUnknown_80B79AC
    .2byte 3, 6, 107, 0, 1, 0; .4byte gUnknown_80B7998
    .2byte 3, 6, 108, 0, 1, 0; .4byte gUnknown_80B7984
    .2byte 3, 6, 109, 0, 1, 0; .4byte gUnknown_80B7970
    .2byte 1, 6, 215, 0, 16, 0; .4byte gUnknown_80B7960
    .2byte 1, 6, 217, 0, 16, 0; .4byte gUnknown_80B7950
    .2byte 1, 6, 219, 0, 16, 0; .4byte gUnknown_80B7940
    .2byte 1, 6, 221, 0, 16, 0; .4byte gUnknown_80B7930
    .2byte 1, 6, 223, 0, 8, 0; .4byte gUnknown_80B791C
    .2byte 1, 6, 224, 0, 8, 0; .4byte gUnknown_80B7908
    .2byte 1, 6, 225, 0, 8, 0; .4byte gUnknown_80B78F4
    .2byte 1, 6, 226, 0, 8, 0; .4byte gUnknown_80B78E0
    .2byte 1, 6, 227, 0, 8, 0; .4byte gUnknown_80B78CC
    .2byte 1, 6, 228, 0, 8, 0; .4byte gUnknown_80B78B8
    .2byte 0, 0, 229, 0, 0, 0; .4byte gUnknown_80B78B4

gUnknown_80B78B4:
    .string "SUM\0"

gUnknown_80B78B8:
    .string "EVENT_M02E01A_2N\0"
    .align 2, 0

gUnknown_80B78CC:
    .string "EVENT_M01E10A_5N\0"
    .align 2, 0

gUnknown_80B78E0:
    .string "EVENT_M01E10A_3N\0"
    .align 2, 0

gUnknown_80B78F4:
    .string "EVENT_M01E10A_1N\0"
    .align 2, 0

gUnknown_80B7908:
    .string "EVENT_M01E09A_8N\0"
    .align 2, 0

gUnknown_80B791C:
    .string "EVENT_M01E09A_2N\0"
    .align 2, 0

gUnknown_80B7930:
    .string "EVENT_T01P03\0"
    .align 2, 0

gUnknown_80B7940:
    .string "EVENT_T01P02\0"
    .align 2, 0

gUnknown_80B7950:
    .string "EVENT_T01P01\0"
    .align 2, 0

gUnknown_80B7960:
    .string "EVENT_B01P01\0"
    .align 2, 0

gUnknown_80B7970:
    .string "EVENT_ORNAMENT_04\0"
    .align 2, 0

gUnknown_80B7984:
    .string "EVENT_ORNAMENT_03\0"
    .align 2, 0

gUnknown_80B7998:
    .string "EVENT_ORNAMENT_02\0"
    .align 2, 0

gUnknown_80B79AC:
    .string "EVENT_ORNAMENT_01\0"
    .align 2, 0

gUnknown_80B79C0:
    .string "EVENT_GONBE\0"
    .align 2, 0

gUnknown_80B79CC:
    .string "EVENT_S08E01\0"
    .align 2, 0

gUnknown_80B79DC:
    .string "EVENT_S07E01\0"
    .align 2, 0

gUnknown_80B79EC:
    .string "INN_TEMP\0"
    .align 2, 0

gUnknown_80B79F8:
    .string "SHOP_TEMP\0"
    .align 2, 0

gUnknown_80B7A04:
    .string "DELIVER_ITEM_TEMP\0"
    .align 2, 0

gUnknown_80B7A18:
    .string "DELIVER_ITEM_STATIC\0"
    .align 2, 0

gUnknown_80B7A2C:
    .string "STATION_ITEM_TEMP\0"
    .align 2, 0

gUnknown_80B7A40:
    .string "STATION_ITEM_STATIC\0"
    .align 2, 0

gUnknown_80B7A54:
    .string "EVENT_LOCAL\0"
    .align 2, 0

gUnknown_80B7A60:
    .string "MAP_LOCAL_DOOR\0"
    .align 2, 0

gUnknown_80B7A70:
    .string "MAP_LOCAL\0"
    .align 2, 0

gUnknown_80B7A7C:
    .string "GROUND_LOCAL\0"
    .align 2, 0

gUnknown_80B7A8C:
    .string "POSITION_DIRECTION\0"
    .align 2, 0

gUnknown_80B7AA0:
    .string "POSITION_HEIGHT\0"
    .align 2, 0

gUnknown_80B7AB0:
    .string "POSITION_Y\0"
    .align 2, 0

gUnknown_80B7ABC:
    .string "POSITION_X\0"
    .align 2, 0

gUnknown_80B7AC8:
    .string "DUNGEON_CLEAR_LIST\0"
    .align 2, 0

gUnknown_80B7ADC:
    .string "DUNGEON_ENTER_LIST\0"
    .align 2, 0

gUnknown_80B7AF0:
    .string "TRAINING_PRESENT_LIST\0"
    .align 2, 0

gUnknown_80B7B08:
    .string "TRAINING_CONQUEST_LIST\0"
    .align 2, 0

gUnknown_80B7B20:
    .string "RESCUE_SCENARIO_CONQUEST_LIST\0"
    .align 2, 0

gUnknown_80B7B40:
    .string "RESCUE_SCENARIO_JOB_LIST\0"
    .align 2, 0

gUnknown_80B7B5C:
    .string "RESCUE_SCENARIO_ORDER_LIST\0"
    .align 2, 0

gUnknown_80B7B78:
    .string "FLAG_KIND_CHANGE_REQUEST\0"
    .align 2, 0

gUnknown_80B7B94:
    .string "FLAG_KIND\0"
    .align 2, 0

gUnknown_80B7BA0:
    .string "BASE_LEVEL\0"
    .align 2, 0

gUnknown_80B7BAC:
    .string "BASE_KIND\0"
    .align 2, 0

gUnknown_80B7BB8:
    .string "PARTNER_TALK_KIND\0"
    .align 2, 0

gUnknown_80B7BCC:
    .string "WARP_LOCK\0"
    .align 2, 0

gUnknown_80B7BD8:
    .string "WARP_LIST\0"
    .align 2, 0

gUnknown_80B7BE4:
    .string "BANK_GOLD\0"
    .align 2, 0

gUnknown_80B7BF0:
    .string "GOLD\0"
    .align 2, 0

gUnknown_80B7BF8:
    .string "UNIT_SUM\0"
    .align 2, 0

gUnknown_80B7C04:
    .string "FRIEND_SUM\0"
    .align 2, 0

gUnknown_80B7C10:
    .string "NEW_FRIEND_KIND\0"
    .align 2, 0

gUnknown_80B7C20:
    .string "PARTNER2_KIND\0"
    .align 2, 0

gUnknown_80B7C30:
    .string "PARTNER1_KIND\0"
    .align 2, 0

gUnknown_80B7C40:
    .string "PLAYER_KIND\0"
    .align 2, 0

gUnknown_80B7C4C:
    .string "WEATHER_KIND\0"
    .align 2, 0

gUnknown_80B7C5C:
    .string "CONDITION_KIND\0"
    .align 2, 0

gUnknown_80B7C6C:
    .string "CLEAR_COUNT\0"
    .align 2, 0

gUnknown_80B7C78:
    .string "START_MODE\0"
    .align 2, 0

gUnknown_80B7C84:
    .string "SCRIPT_MODE\0"
    .align 2, 0

gUnknown_80B7C90:
    .string "DUNGEON_RESULT\0"
    .align 2, 0

gUnknown_80B7CA0:
    .string "DUNGEON_ENTER_FREQUENCY\0"
    .align 2, 0

gUnknown_80B7CB8:
    .string "DUNGEON_ENTER_INDEX\0"
    .align 2, 0

gUnknown_80B7CCC:
    .string "DUNGEON_ENTER\0"
    .align 2, 0

gUnknown_80B7CDC:
    .string "DUNGEON_SELECT\0"
    .align 2, 0

gUnknown_80B7CEC:
    .string "GROUND_PLACE\0"
    .align 2, 0

gUnknown_80B7CFC:
    .string "GROUND_MAP\0"
    .align 2, 0

gUnknown_80B7D08:
    .string "GROUND_GETOUT\0"
    .align 2, 0

gUnknown_80B7D18:
    .string "GROUND_ENTER_LINK\0"
    .align 2, 0

gUnknown_80B7D2C:
    .string "GROUND_ENTER\0"
    .align 2, 0

gUnknown_80B7D3C:
    .string "SCENARIO_SUB9\0"
    .align 2, 0

gUnknown_80B7D4C:
    .string "SCENARIO_SUB8\0"
    .align 2, 0

gUnknown_80B7D5C:
    .string "SCENARIO_SUB7\0"
    .align 2, 0

gUnknown_80B7D6C:
    .string "SCENARIO_SUB6\0"
    .align 2, 0

gUnknown_80B7D7C:
    .string "SCENARIO_SUB5\0"
    .align 2, 0

gUnknown_80B7D8C:
    .string "SCENARIO_SUB4\0"
    .align 2, 0

gUnknown_80B7D9C:
    .string "SCENARIO_SUB3\0"
    .align 2, 0

gUnknown_80B7DAC:
    .string "SCENARIO_SUB2\0"
    .align 2, 0

gUnknown_80B7DBC:
    .string "SCENARIO_SUB1\0"
    .align 2, 0

gUnknown_80B7DCC:
    .string "SCENARIO_MAIN\0"
    .align 2, 0

gUnknown_80B7DDC:
    .string "SCENARIO_SELECT\0"
    .align 2, 0

gUnknown_80B7DEC:
    .string "CONDITION\0"
    .align 2, 0

gUnknown_80B7DF8:
    .string "VERSION\0"
    .align 2, 0

@ ???
.string "pksdir0\0"

@ ???
.string "pksdir0\0"
    .fill 28, 1, 0
