#include "global.h"
#include "game_options.h"
#include "code_8092334.h"

struct WindowBG
{
    // size: 0x10
    u32 hexBG[4];
};

struct unkStruct_8094CB0
{
    u16 unk0;
    s16 unk2;
};

extern struct WindowBG gWindowBGColors;

extern struct GameOptions *gGameOptions;
extern struct GameOptions gUnknown_2038C70;
extern void SetWindowBGColor(void);
extern void sub_80099F0(u32);

void LoadGameOptions(void)
{
    gGameOptions = &gUnknown_2038C70;
}

struct GameOptions * GetGameOptions(void)
{
    return &gUnknown_2038C70;
}

void InitializeGameOptions(bool8 initializeGender)
{
    gGameOptions->windowColor = WINDOW_COLOR_BLUE;
    if(initializeGender)
    {
        gGameOptions->playerGender = MALE;
    }
    gGameOptions->unk9 = 0;
    gGameOptions->unkA = 0;
    gGameOptions->dungeonSpeed = DUNGEON_SPEED_SLOW; 
    gGameOptions->FarOffPals = FAROFFPALS_LOCK;
    gGameOptions->damageTurn = TRUE;
    gGameOptions->gridEnable = TRUE;
    gGameOptions->mapOption = MAP_OPTION_CLEAR;
    gGameOptions->unkC = 0;
    SetWindowBGColor();
}

bool8 GameOptionsNotChange(struct GameOptions *r0)
{
    // NOTE: had to nest to match
    if(gGameOptions->windowColor == r0->windowColor)
        if(gGameOptions->unk9 == r0->unk9)
            if(gGameOptions->unkA == r0->unkA) 
                if(gGameOptions->playerGender == r0->playerGender)
                    if(gGameOptions->dungeonSpeed == r0->dungeonSpeed)
                        if(gGameOptions->FarOffPals == r0->FarOffPals) 
                            if(gGameOptions->damageTurn == r0->damageTurn)
                                if(gGameOptions->gridEnable == r0->gridEnable)
                                    if(gGameOptions->mapOption == r0->mapOption)
                                        if(gGameOptions->unkC == r0->unkC)
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

    SaveIntegerBits(param_1, &gGameOptions->windowColor, 2);

    if(gGameOptions->unk9 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptions->unkA != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptions->playerGender != MALE)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptions->dungeonSpeed != DUNGEON_SPEED_SLOW)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptions->FarOffPals != FAROFFPALS_SELF)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptions->damageTurn)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gGameOptions->gridEnable)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    SaveIntegerBits(param_1, &gGameOptions->mapOption, NUM_GBA_MAP_OPTIONS);
    SaveIntegerBits(param_1, &gGameOptions->unkC, 2);
}

void ReadGameOptions(struct unkStruct_8094924 *param_1)
{
    u8 byteArray[4];
    RestoreIntegerBits(param_1, byteArray, 2);
    gGameOptions->windowColor  = byteArray[0] & NUM_WINDOW_COLORS;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptions->unk9  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptions->unkA  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptions->playerGender  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptions->dungeonSpeed  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptions->FarOffPals  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptions->damageTurn  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gGameOptions->gridEnable  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 3);
    gGameOptions->mapOption  = byteArray[0] & NUM_DS_MAP_OPTIONS;

    RestoreIntegerBits(param_1, byteArray, 2);
    gGameOptions->unkC  = byteArray[0] & 3;

    SetWindowBGColor();
}

void SetWindowBGColor(void)
{
    struct WindowBG temp;

    temp = gWindowBGColors;

    sub_80099F0(temp.hexBG[gGameOptions->windowColor & NUM_WINDOW_COLORS]);
}

bool8 sub_8094C48(void)
{
    switch(gGameOptions->mapOption)
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
    switch(gGameOptions->mapOption)
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
    if(gGameOptions->mapOption < 3)
        gGameOptions->mapOption = 1;
    else
        {
            if((u8)(gGameOptions->mapOption - 3) > 2)
                return;
            else
                gGameOptions->mapOption = 4;
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

