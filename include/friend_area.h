#ifndef GUARD_FRIEND_AREA_H
#define GUARD_FRIEND_AREA_H

// size: 0x8
typedef struct FriendAreaSettings
{
    /* 0x0 */ s16 num_pokemon;
    /* 0x2 */ u16 unlock_condition;
    /* 0x4 */ u32 price;
} FriendAreaSettings;

// size: 0xC
typedef struct unkStruct_8092638
{ 
    /* 0x0 */ s16 numPokemon;
    s16 unk2;
    /* 0x4 */ bool8 hasFriendArea;
    u8 fill5[3];
    s32 unk8;
} unkStruct_8092638;

extern bool8 *gFriendAreas;

void LoadFriendAreas(void);
bool8 *GetBoughtFriendAreas(void);
void InitializeFriendAreas(void);
u8 sub_80923D4(s32 target);
void sub_809249C(u8 friendArea, bool8 clear);
bool8 HasAllFriendAreas(void);
bool8 GetFriendAreaStatus(u8 index);
void UnlockFriendArea(u8 index);
u8 *GetFriendAreaDescription(u8 index);
u8 GetFriendAreaUnlockCondition(u8 index);
s32 GetFriendAreaPrice(u8 index);
void sub_8092578(u8 *buffer, u8 index, bool8 printPrice);
const char *GetFriendAreaName(u8 index);
void sub_809249C(u8 friendArea, u8 clear);
void sub_8092638(u8 friendArea, unkStruct_8092638 *param_2, bool8 checkLeader, bool8 checkDungeon);

u32 SaveFriendAreas(u8 *r0, u32 r1);
u32 ReadSavedFriendAreas(u8 *r0, s32 r1);

#endif // GUARD_FRIEND_AREA_H