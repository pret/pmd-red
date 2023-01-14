#ifndef GUARD_FRIEND_RESCUE_H
#define GUARD_FRIEND_RESCUE_H

#include "code_8094F88.h"
#include "item.h"
#include "pokemon.h"
#include "wonder_mail.h"

struct WonderMailStruct_203B33C
{
    // size: 0x568
    u32 state;
    u32 fallbackState;
    u8 passwordBuffer[0x36];
    u32 unk40;
    u32 status;
    struct unkStruct_203B480 unk48;
    struct unkStruct_203B480 unk78;
    struct WonderMailStruct_203B2C0_sub unkA8;
    struct WonderMailStruct_203B2C0_sub unk130;
    struct unkStruct_203B480 unk1B8;
    struct unkStruct_203B480 unk1E8;
    u8 unk218;
    u8 padding7[3];
    u32 unk21C;
    u8 padding[0x7C];
    u32 unk29C;
    u8 padding6[0x6C];
    u32 unk30C;
    u8 padding8[0x4C];
    struct UnkTextStruct2 unk35C[4];
    struct UnkTextStruct2 unk3BC[4];
    struct Item unk41C;
    u32 unk420; // Is this supposed to be a File like 203B2C4?
    u8 unk424[0x100];
    s32 unk524;
    u32 unk528;
    u8 unk52C;
    u8 unk52D;
    u8 fill52E;
    u32 unk530;
    u32 unk534;
    s16 speciesNum; // A7 << 3
    struct unkStruct_802F204 unk53C;
    s32 unk564;
};

u32 CreateFriendRescueMenu(void);
u32 UpdateFriendRescueMenu(void);
void CleanFriendRescueMenu(void);


#endif
