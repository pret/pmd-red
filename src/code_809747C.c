#include "global.h"
#include "dungeon.h"


struct MissionText
{
    u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

extern struct MissionText gStoryMissionText[];
extern const u8 gUnknown_8109CC0[];
extern const u8 gDummyScenarioText[];
extern const char gFinalScenarioText[];
extern const char gMeetNinetalesText[];
extern const char gAvoidCaptureText[];

extern u8 sub_80A270C();
extern void sub_80015C0(u8, u8);
extern u8 sub_80A2728(s16);
extern bool8 sub_8001D08(u32, u32 ,s32);
extern u32 sub_8001784(u32, u32, u16);
extern void sub_800199C(u32, u32, u32, u32);
extern bool8 sub_80023E4(u32);

const u8 *sub_809747C(s16 index)
{
    if(index == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(index));
    }
}

const u8 *sub_80974A0(s16 index)
{
    if(index == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(index));
    }
}

const u8 *GetCurrentMissionText(s16 index)
{
    if(index < 0x1F)
    {
        struct MissionText *mt = &gStoryMissionText[index];
        return mt->text;
    }
    else
    {
        return gUnknown_8109CC0;
    }
}

void sub_80974E8(void)
{
    sub_80015C0(0, 0x2E);
    sub_80015C0(0, 0x2F);
}

void nullsub_208(void)
{
}

bool8 sub_8097504(s16 mazeIndex)
{
    s32 mazeIndex_s32;

#ifndef NONMATCHING
    register s32 mazeIndex_s32_1 asm("r1");
#else
    s32 mazeIndex_s32_1;    
#endif
    s32 uVar3;

    mazeIndex_s32 = mazeIndex;
    mazeIndex_s32_1 = mazeIndex_s32;

    if(mazeIndex_s32 < 17)
    {
        switch(mazeIndex_s32) {
            case 2:
            case 10:
            case 11:
            case 12:
                uVar3 = 14;
                break;
            case 0:
            case 1:
            case 5:
            case 7:
            case 9:
            case 14:
                uVar3 = 15;
                break;
            case 3:
            case 4:
            case 6:
            case 8:
                return TRUE;
            case 13:
                uVar3 = 6;
                break;
            default:
                return TRUE;
        }
    }
    else
    {
        if (mazeIndex_s32_1 > 22)  return FALSE;
        if (mazeIndex_s32_1 == 22) return FALSE;
        if (mazeIndex_s32_1 == 21) return FALSE;
        uVar3 = 6;
    }

    if (!sub_80023E4(uVar3)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

// TODO: this should probably be bool8 but can't get a match just yet
bool32 IsMazeCompleted(s16 mazeIndex)
{
    bool32 mazeCompletion;

    mazeCompletion = sub_8001784(0, 0x2e, mazeIndex);
    if (mazeCompletion) {
        mazeCompletion = TRUE;
    }
    return mazeCompletion;
}

void sub_80975A8(s16 param_1,u8 param_2)
{ 
    u16 param_1_u16 = param_1;
    sub_800199C(0,0x2e,param_1_u16,param_2);
}

const u8 *sub_80975C4(s16 index)
{
    return GetDungeonName1(sub_80A2728(index));
}

const char *sub_80975DC(u32 r0)
{
    // TODO: slight hack but matches
    r0 <<= 16;
    if((0xffe90000 + r0) >> 16 < 2)
        if(sub_8001D08(0x3, 0xE, -1))
            return gMeetNinetalesText;
        else
            return gAvoidCaptureText;
    else
        return gFinalScenarioText;
}

bool8 HasCompletedAllMazes(void)
{
    s32 index;
    for(index = 0; index < 17; index++)
    {
        if(!(bool8)IsMazeCompleted(index))
            return FALSE;
    }
    return TRUE;
}

bool8 sub_8097640(void)
{
    if(sub_8001784(0, 0x2E, 0x1F) == 0 && HasCompletedAllMazes())
    {
        sub_800199C(0, 0x2E, 0x1F, 1);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
