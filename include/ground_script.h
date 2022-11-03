struct GroundScript_ExecutePP_3
{
    // size: 0xC
    u32 unk0;
    s16 scriptType;
    s16 unk6;
    u8 unk8;
};

struct GroundScript_ExecutePP_1_sub
{
    // size: 0x60
    /* 0x0 */ s16 scriptType;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
    /* 0xC */ u16 unkC;
    /* 0xE */ u8 unkE;
    /* 0xF */ u8 fillF;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 fill18[0x22 - 0x18];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u32 unk26;
    u8 fill50[0x60 - 0x2A];
} __attribute__((packed));

typedef void (*Callback)(u32, void *);
struct GroundScript_ExecutePP_1_sub2
{
    Callback callbacks[10]; // IDK the size..
};

struct GroundScript_ExecutePP_1
{
    struct GroundScript_ExecutePP_1_sub2 *unk0;
    u32 unk4;
    u32 fill8;
    u32 unkC;
    u32 fill10;
    u8 fill18[0x24 - 0x14];
    struct GroundScript_ExecutePP_1_sub unk24;
    struct GroundScript_ExecutePP_1_sub unk84;
    u16 unkE4;
};
