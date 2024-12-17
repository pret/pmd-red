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

EWRAM_INIT GameOptions *gGameOptionsRef = {NULL};
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
    if (gGameOptionsRef->windowColor != r0->windowColor)
        return FALSE;
    if (gGameOptionsRef->unk9 != r0->unk9)
        return FALSE;
    if (gGameOptionsRef->unkA != r0->unkA)
        return FALSE;
    if (gGameOptionsRef->playerGender != r0->playerGender)
        return FALSE;
    if (gGameOptionsRef->dungeonSpeed != r0->dungeonSpeed)
        return FALSE;
    if (gGameOptionsRef->FarOffPals != r0->FarOffPals)
        return FALSE;
    if (gGameOptionsRef->damageTurn != r0->damageTurn)
        return FALSE;
    if (gGameOptionsRef->gridEnable != r0->gridEnable)
        return FALSE;
    if (gGameOptionsRef->mapOption != r0->mapOption)
        return FALSE;
    if (gGameOptionsRef->unkC != r0->unkC)
        return FALSE;

    return TRUE;
}

void WriteGameOptionsBits(DataSerializer *param_1)
{
    u8 zero;
    u8 neg_1;
    u8 *puVar2;


    neg_1 = -1;
    zero = 0;

    WriteBits(param_1, &gGameOptionsRef->windowColor, 2);

    if(gGameOptionsRef->unk9 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    if(gGameOptionsRef->unkA != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    if(gGameOptionsRef->playerGender != MALE)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    if(gGameOptionsRef->dungeonSpeed != DUNGEON_SPEED_SLOW)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    if(gGameOptionsRef->FarOffPals != FAROFFPALS_SELF)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    if(gGameOptionsRef->damageTurn)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    if(gGameOptionsRef->gridEnable)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    WriteBits(param_1, &gGameOptionsRef->mapOption, NUM_GBA_MAP_OPTIONS);
    WriteBits(param_1, &gGameOptionsRef->unkC, 2);
}

void ReadGameOptionsBits(DataSerializer *param_1)
{
    u8 byteArray[4];
    ReadBits(param_1, byteArray, 2);
    gGameOptionsRef->windowColor  = byteArray[0] & NUM_WINDOW_COLORS;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->unk9  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->unkA  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->playerGender  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->dungeonSpeed  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->FarOffPals  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->damageTurn  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->gridEnable  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 3);
    gGameOptionsRef->mapOption  = byteArray[0] & NUM_DS_MAP_OPTIONS;

    ReadBits(param_1, byteArray, 2);
    gGameOptionsRef->unkC  = byteArray[0] & 3;

    SetWindowBGColor();
}

void SetWindowBGColor(void)
{
    struct RGB winColors[] = {
        {0x20, 0x48, 0x68}, // Blue
        {0x80, 0x38, 0x20}, // Red
        {0x28, 0x80, 0x48}, // Green
        {0x28, 0x80, 0x48} // Green
    };

    SetFontsBaseColor(winColors[gGameOptionsRef->windowColor & NUM_WINDOW_COLORS]);
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
    if (gGameOptionsRef->mapOption == 0 || gGameOptionsRef->mapOption == 1 || gGameOptionsRef->mapOption == 2)
        gGameOptionsRef->mapOption = 1;
    else if (gGameOptionsRef->mapOption == 3 || gGameOptionsRef->mapOption == 4 || gGameOptionsRef->mapOption == 5)
        gGameOptionsRef->mapOption = 4;
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

