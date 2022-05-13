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
extern u8 sub_80A270C();
extern void sub_80015C0(u8, u8);

const u8 *sub_809747C(s16 r0)
{
    if(r0 == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(r0));
    }
}

const u8 *sub_80974A0(s16 r0)
{
    if(r0 == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(r0));
    }
}

const u8 *GetCurrentMissionText(s16 r0)
{
    if(r0 <= 0x1E)
    {
        return (r0)[gStoryMissionText].text;
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
