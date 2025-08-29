#include "global.h"
#include "globaldata.h"
#include "game_options.h"
#include "graphics_memory.h"
#include "data_serializer.h"

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
    gGameOptionsRef->controls = CONTROLS_GBA;
    gGameOptionsRef->touchScreen = 0;
    gGameOptionsRef->dungeonSpeed = DUNGEON_SPEED_SLOW;
    gGameOptionsRef->FarOffPals = FAROFFPALS_LOCK;
    gGameOptionsRef->damageTurn = TRUE;
    gGameOptionsRef->gridEnable = TRUE;
    gGameOptionsRef->mapOption = MAP_OPTION_CLEAR;
    gGameOptionsRef->unkC = 0;
    SetWindowBGColor();
}

bool8 GameOptionsNotChange(GameOptions *newOptions)
{
    if (gGameOptionsRef->windowColor != newOptions->windowColor)
        return FALSE;
    if (gGameOptionsRef->controls != newOptions->controls)
        return FALSE;
    if (gGameOptionsRef->touchScreen != newOptions->touchScreen)
        return FALSE;
    if (gGameOptionsRef->playerGender != newOptions->playerGender)
        return FALSE;
    if (gGameOptionsRef->dungeonSpeed != newOptions->dungeonSpeed)
        return FALSE;
    if (gGameOptionsRef->FarOffPals != newOptions->FarOffPals)
        return FALSE;
    if (gGameOptionsRef->damageTurn != newOptions->damageTurn)
        return FALSE;
    if (gGameOptionsRef->gridEnable != newOptions->gridEnable)
        return FALSE;
    if (gGameOptionsRef->mapOption != newOptions->mapOption)
        return FALSE;
    if (gGameOptionsRef->unkC != newOptions->unkC)
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

    if (gGameOptionsRef->controls != CONTROLS_GBA)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(param_1, puVar2, 1);

    if(gGameOptionsRef->touchScreen)
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
    gGameOptionsRef->controls  = byteArray[0] & 1;

    ReadBits(param_1, byteArray, 1);
    gGameOptionsRef->touchScreen  = byteArray[0] & 1;

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

bool8 GameOptions_ShowMiniMap(void)
{
    switch (gGameOptionsRef->mapOption) {
        default:
            return TRUE;
        case TOP_TEAM_DATA_NO_BOTTOM: // MAP_OPTION_OFF
        case TOP_MESSAGE_LOG_NO_BOTTOM:
            return FALSE;
    }
}

bool8 GameOptions_IsTransparentMiniMap(void)
{
    switch (gGameOptionsRef->mapOption) {
        default:
            return TRUE;
        case TOP_TEAM_DATA_SHADED_MAP_BOTTOM:
        case TOP_MESSAGE_LOG_SHADED_MAP_BOTTOM: // MAP_OPTION_SHADE
            return FALSE;
    }
}

void GameOptions_SetTransparentMiniMap(void)
{
    if (gGameOptionsRef->mapOption == MAP_OPTION_OFF || gGameOptionsRef->mapOption == MAP_OPTION_CLEAR || gGameOptionsRef->mapOption == MAP_OPTION_SHADE)
        gGameOptionsRef->mapOption = MAP_OPTION_CLEAR;
    else if (gGameOptionsRef->mapOption == TOP_MESSAGE_LOG_NO_BOTTOM || gGameOptionsRef->mapOption == TOP_MESSAGE_LOG_CLEAR_MAP_BOTTOM || gGameOptionsRef->mapOption == TOP_MESSAGE_LOG_SHADED_MAP_BOTTOM)
        gGameOptionsRef->mapOption = TOP_MESSAGE_LOG_CLEAR_MAP_BOTTOM;
}

// DS Stuff below?
struct unkStruct_8094CB0
{
    s16 unk0;
    s16 unk2;
};

UNUSED static void sub_8094CB0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

UNUSED static void sub_8094CC0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

UNUSED static void sub_8094CD0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

UNUSED static void sub_8094CE0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

UNUSED static void sub_8094CF0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

UNUSED static void sub_8094D00(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

UNUSED static u32 sub_8094D10(void)
{
    return 0;
}

bool8 sub_8094D14(void)
{
    return FALSE;
}

UNUSED static u32 sub_8094D18(void)
{
    return 0;
}

UNUSED static u32 sub_8094D1C(void)
{
    return 0;
}

UNUSED static u32 sub_8094D20(void)
{
    return 0;
}

UNUSED static u32 sub_8094D24(void)
{
    return 0;
}

