#include "menu.h"
struct unkStruct_203B2F4
{
    MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
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
    struct unkSubStruct_203B2F8 *mail;
    u8 jobSlotIndex;
    struct unkStruct_802C39C unk14;
    u32 menuAction1;
    u32 menuAction2;
    u32 menuAction3;
    MenuStruct unk78;
    MenuStruct unkC8;
    MenuItem unk118[8];
    MenuItem unk158[8];
    u16 unk198[8];
    UnkTextStruct2 unk1A8[4];
    u32 unk1E4;
};
extern struct unkStruct_203B2F8 *gUnknown_203B2F8;

enum WonderMailRescueStates
{
    INITIAL_WONDER_MAIL_CHECK,
    // 1 is ??
    WONDER_MAIL_EXIT = 2,
    DUPLICATE_WONDER_MAIL = 3,
    DUPLICATE_WONDER_MAIL_1,
    // 5 is ??
    // 6 is ??
    // 7 is ??
    RECEIVE_WONDER_MAIL = 8,
    // 9 is ??
    JOB_LIST_FULL = 0xA,
    DRAW_JOB_LIST = 0xB,
    DRAW_JOB_LIST_1 = 0xC,
    // 0xD is ??
    // 0xE is ??
    // 0xF is ??
    // 0x10 is ??
};
