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
typedef struct FriendAreaCapacity
{
    /* 0x0 */ s16 maxPokemon;
    /* 0x2 */ s16 currNoPokemon;
    /* 0x4 */ bool8 hasFriendArea;
    s32 unk8;
} FriendAreaCapacity;

extern bool8 *gFriendAreas;

bool8 *GetBoughtFriendAreas(void);
const u8 *GetFriendAreaDescription(u8 index);
const u8 *GetFriendAreaName(u8 index);
s32 GetFriendAreaPrice(u8 index);
bool8 GetFriendAreaStatus(u8 index);
u8 GetFriendAreaUnlockCondition(u8 index);
bool8 HasAllFriendAreas(void);
void InitializeFriendAreas(void);
void LoadFriendAreas(void);
u32 ReadSavedFriendAreas(u8 *, s32 size);
u32 SaveFriendAreas(u8 *, u32 size);
void UnlockFriendArea(u8 index);

u8 sub_80923D4(s32 target);
void sub_8092404(u8, u16 *, bool8, bool8);
void sub_809249C(u8 friendArea, bool8 clear);
void sub_8092558(u8 *buffer, u8 index);
void WriteFriendAreaName(u8 *buffer, u8 index, bool8 printPrice);
void GetFriendAreaCapacity2(u8 friendArea, FriendAreaCapacity *dst, bool8 checkLeader, bool8 checkPartner);
void GetFriendAreaCapacity(u8 areaId, FriendAreaCapacity *dst, bool8 checkPartner);

#endif // GUARD_FRIEND_AREA_H
