#ifndef GUARD_FRIEND_LIST_H
#define GUARD_FRIEND_LIST_H

#include "structs/str_position.h"
#include "structs/menu.h"

struct unkStruct_3001B60
{
    u32 unk0;
    u32 sortMethod;
    s32 unk8;
    u32 unkC;
    u32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    s16 unk1A[NUM_MONSTERS];
    u8 unk354;
    MenuHeaderWindow unk358;
};

bool8 FriendList_Init(u32 r5, u32 windowId, DungeonPos *pos, u32 r10);
u32 FriendList_HandleInput(bool8);
s32 FriendList_GetCurrId(void);
void sub_8023B7C(bool8 addCursor);
void FriendList_Free(void);
struct unkStruct_3001B60 *FriendList_GetPtr(void);
void FriendList_ShowWindow(void);
bool8 sub_8024108(s32);

#endif // GUARD_FRIEND_LIST_H
