#include "menu.h"
struct unkStruct_203B2F4
{
    u8 fill0[0x1A];
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    u8 fill20[0x34 - 0x20];
    u32 unk34;
    u32 unk38;
    struct UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};
extern struct unkStruct_203B2F4 *gUnknown_203B2F4;

struct unkStruct_803B344
{
    // size: 0xB4
    struct WonderMail mail;
    u8* unk14;
    u8* unk18;
    u8 fill1C[0x3C - 0x1C];
    u8 unk3C[0x78];
};

struct unkSubStruct_203B2F8
{
    struct WonderMail wonderMail;
    u8 *unk14;
    u8 *unk18;
};

struct unkStruct_203B2F8
{
    // size: 0x208
    s32 state; // state
    s32 fallbackState;
    u8 wonderMailAccepted;
    bool8 unk9;
    u8 dungeonID;
    u8 unkB;
    struct unkSubStruct_203B2F8 *unkC;
    u8 jobSlotIndex;
    u8 fill11[0x14 - 0x11];
    u32 unk14;
    u8 fill18[0x58 - 0x18];
    u8 unk58;
    u8 fill59[0x64 - 0x59];
    u8 *unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    struct MenuStruct unk78;
    struct MenuStruct unkC8;
    struct MenuItem unk118[8];
    struct MenuItem unk158[8];
    u16 unk198[8];
    struct UnkTextStruct2 unk1A8[4];
    u32 unk1E4;
};
extern struct unkStruct_203B2F8 *gUnknown_203B2F8;
