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

struct unkStruct_802C39C
{
    /* 0x0 */ u32 unk0[2];
    /* 0x8 */ struct DungeonLocation *unk8;
    /* 0xC */ u8 *unkC;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 fill15[0x1B];
    /* 0x34 */ u8 fill34[2];
    /* 0x36 */ u8 fill36[0x3C - 0x36];
    /* 0x3C */ u8 unk3C[0xC];
    /* 0x48 */ u8 fill48[4];
    /* 0x4C */ u32 unk4C;
    /* 0x50 */ u8 *unk50[3];
};

struct unkStruct_803B344
{
    // size: 0xB4
    struct WonderMail unk0;
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
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    struct unkSubStruct_203B2F8 *unkC;
    u8 unk10;
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
    u8 unk78[0xC8 - 0x78];
    u8 unkC8[4];
    u8 fillCC[0x118 - 0xCC];
    struct MenuItem unk118[8];
    struct MenuItem unk158[8];
    u16 unk198[8];
    struct UnkTextStruct2 unk1A8[4];
    u32 unk1E4;
};
extern struct unkStruct_203B2F8 *gUnknown_203B2F8;
