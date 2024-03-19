#include "global.h"
#include "globaldata.h"
#include "code_8009804.h"
#include "code_8092334.h"
#include "game_options.h"

struct unkStruct_8094CB0
{
    u16 unk0;
    s16 unk2;
};

struct WindowBG
{
    // size: 0x10
    u32 hexBG[4];
};

const struct WindowBG gWindowBGColors = {
    RGB_U32(0x20, 0x48, 0x68), // Blue 
    RGB_U32(0x80, 0x38, 0x20), // Red 
    RGB_U32(0x28, 0x80, 0x48), // Green
    RGB_U32(0x28, 0x80, 0x48) // Green
};

EWRAM_DATA_2 GameOptions *gGameOptionsRef = {0};
EWRAM_DATA GameOptions gGameOptions = {0};

void LoadGameOptions(void)
{
    gGameOptionsRef = &gGameOptions;
}

GameOptions * GetGameOptions(void)
{
    return &gGameOptions;
}

void InitializeGameOptions(bool8 initializeGender)
{
    gGameOptionsRef->windowColor = WINDOW_COLOR_BLUE;
    if(initializeGender)
    {
        gGameOptionsRef->playerGender = MALE;
    }
    gGameOptionsRef->unk9 = 0;
    gGameOptionsRef->unkA = 0;
    gGameOptionsRef->dungeonSpeed = DUNGEON_SPEED_SLOW; 
    gGameOptionsRef->FarOffPals = FAROFFPALS_LOCK;
    gGameOptionsRef->damageTurn = TRUE;
    gGameOptionsRef->gridEnable = TRUE;
    gGameOptionsRef->mapOption = MAP_OPTION_CLEAR;
    gGameOptionsRef->unkC = 0;
    SetWindowBGColor();
}

bool8 GameOptionsNotChange(GameOptions *r0)
{
    // NOTE: had to nest to match
    if(gGameOptionsRef->windowColor == r0->windowColor)
        if(gGameOptionsRef->unk9 == r0->unk9)
            if(gGameOptionsRef->unkA == r0->unkA) 
                if(gGameOptionsRef->playerGender == r0->playerGender)
                    if(gGameOptionsRef->dungeonSpeed == r0->dungeonSpeed)
                        if(gGameOptionsRef->FarOffPals == r0->FarOffPals) 
                            if(gGameOptionsRef->damageTurn == r0->damageTurn)
                                if(gGameOptionsRef->gridEnable == r0->gridEnable)
                                    if(gGameOptionsRef->mapOption == r0->mapOption)
                                        if(gGameOptionsRef->unkC == r0->unkC)
                                            return TRUE;
    return FALSE;
}

void WriteGameOptions(struct unkStruct_8094924 *param_1)
{  
    u8 zero;
    u8 neg_1;
    u8 *puVar2;


    neg_1 = -1;
    zero = 0;

    SaveIntegerBits(param_1, &gGameOptionsRef->windowColor, 2);

    if(gGameOptionsRef->unk9 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptionsRef->unkA != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptionsRef->playerGender != MALE)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptionsRef->dungeonSpeed != DUNGEON_SPEED_SLOW)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptionsRef->FarOffPals != FAROFFPALS_SELF)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptionsRef->damageTurn)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptionsRef->gridEnable)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    SaveIntegerBits(param_1, &gGameOptionsRef->mapOption, NUM_GBA_MAP_OPTIONS);
    SaveIntegerBits(param_1, &gGameOptionsRef->unkC, 2);
}

void ReadGameOptions(struct unkStruct_8094924 *param_1)
{
    u8 byteArray[4];
    RestoreIntegerBits(param_1, byteArray, 2);
    gGameOptionsRef->windowColor  = byteArray[0] & NUM_WINDOW_COLORS;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptionsRef->unk9  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptionsRef->unkA  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptionsRef->playerGender  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptionsRef->dungeonSpeed  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptionsRef->FarOffPals  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptionsRef->damageTurn  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptionsRef->gridEnable  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 3);
    gGameOptionsRef->mapOption  = byteArray[0] & NUM_DS_MAP_OPTIONS;

    RestoreIntegerBits(param_1, byteArray, 2);
    gGameOptionsRef->unkC  = byteArray[0] & 3;

    SetWindowBGColor();
}

void SetWindowBGColor(void)
{
    struct WindowBG temp;

    temp = gWindowBGColors;

    sub_80099F0(temp.hexBG[gGameOptionsRef->windowColor & NUM_WINDOW_COLORS]);
}

bool8 sub_8094C48(void)
{
    switch(gGameOptionsRef->mapOption)
    {
        default:
            return TRUE;
        case TOP_TEAM_DATA_NO_BOTTOM:
        case TOP_MESSAGE_LOG_NO_BOTTOM:
            return FALSE;
    }
}

bool8 DoesNotHaveShadedMap(void)
{
    switch(gGameOptionsRef->mapOption)
    {
        default:
            return TRUE;
        case TOP_TEAM_DATA_SHADED_MAP_BOTTOM:
        case TOP_MESSAGE_LOG_SHADED_MAP_BOTTOM:
            return FALSE;
    }
}

void sub_8094C88(void)
{
    if(gGameOptionsRef->mapOption < 3)
        gGameOptionsRef->mapOption = 1;
    else
        {
            if((u8)(gGameOptionsRef->mapOption - 3) > 2)
                return;
            else
                gGameOptionsRef->mapOption = 4;
        }
}

void sub_8094CB0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CC0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CD0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CE0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CF0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094D00(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

u32 sub_8094D10(void)
{
    return 0;
}

u8 sub_8094D14(void)
{
    return 0;
}

u32 sub_8094D18(void)
{
    return 0;
}

u32 sub_8094D1C(void)
{
    return 0;
}

u32 sub_8094D20(void)
{
    return 0;
}

u32 sub_8094D24(void)
{
    return 0;
}

