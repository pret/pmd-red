#ifndef GUARD_FRIEND_AREA_H
#define GUARD_FRIEND_AREA_H

struct FriendAreaSettings
{
    s16 num_pokemon;
    u8 unlock_condition;
    // 0 - Shop (Story)
    // 1 - Shop (Story Post-game)
    // 2 - Wonder Mail
    // 3 - Legendary Request (unlocks when lengendary joins)
    u32 price;
};

void LoadFriendAreas(void);
u8 *GetBoughtFriendAreas(void);
void InitializeFriendAreas(void);
u8 sub_80923D4(s32 target);
bool8 HasAllFriendAreas(void);
bool8 GetFriendAreaStatus(u8 index);
void UnlockFriendArea(u8 index);
u32 GetFriendAreaDescription(u8 index);
u8 GetFriendAreaUnlockCondition(u8 index);
u32 GetFriendAreaPrice(u8 index);
const char *GetFriendAreaName(u8 index);


#endif
