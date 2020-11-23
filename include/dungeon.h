#ifndef GUARD_DUNGEON_H
#define GUARD_DUNGEON_H

struct DungeonName
{
    const u8 *name1;
    const u8 *name2;
};

struct Dungeon
{
    u8 stairDirection;
    u8 unk1;
    bool8 isRecruitable;
    s8 unk3;
    u8 maxItemCount;
    u8 maxPartySize;
    u8 levelCondition;
    u8 moneyCondition;
    u8 unk8;
    u8 unk9;
    bool8 saveBeforeEntering;  //whether to quicksave or not before entering
    u8 unkB; // Apparently is a HM mask (Fly, Dive, Waterfall, Surf, Water)
    s16 timer;
    s16 unkE;
};

extern struct Dungeon gDungeons[];
extern struct DungeonName gDungeonNames[];
const u8 *GetDungeonName1(u8 dungeon);

#endif //GUARD_DUNGEON_H
