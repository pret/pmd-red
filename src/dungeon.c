#include "global.h"
#include "dungeon.h"

const u8 *GetDungeonName1(u8 dungeon)
{
    return gDungeonNames[dungeon].name1;
}

const u8 *GetDungeonName2(u8 dungeon)
{
    return gDungeonNames[dungeon].name2;
}

u8 GetStairDirection(u8 dungeon)
{
    return gDungeons[dungeon].stairDirection;
}

s16 GetUnkC(u8 dungeon)
{
    return gDungeons[dungeon].unkC;
}

u8 GetSaveBeforeEntering(u8 dungeon)
{
    return gDungeons[dungeon].saveBeforeEntering;
}

u8 GetUnk9(u8 dungeon)
{
    return gDungeons[dungeon].unk9;
}

u8 GetLevelCondition(u8 dungeon)
{
    return gDungeons[dungeon].levelCondition;
}

u8 GetMaxItemCount(u8 dungeon)
{
    return gDungeons[dungeon].maxItemCount;
}

u8 GetMoneyCondition(u8 dungeon)
{
    return gDungeons[dungeon].moneyCondition;
}

s8 GetUnk3(u8 dungeon)
{
    return gDungeons[dungeon].unk3;
}

u8 sub_8090148(u8 dungeon)
{
    return gDungeons[dungeon].unk2;
}

u8 sub_8090158(u8 dungeon)
{
    return gDungeons[dungeon].unk8;
}

s16 sub_8090168(u8 dungeon)
{
    return gDungeons[dungeon].unkE;
}
