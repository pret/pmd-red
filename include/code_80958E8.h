struct subStruct_203B490
{
    // size: 0xC
    u8 dungeon;
    u8 unk1;
    u32 unk4;
    u32 unk8;
};
 

struct unkStruct_203B490
{
    // size: 0x330?
    struct WonderMail unk0[4];
    struct WonderMail unk50[8];
    struct WonderMail unkF0[8];
    u8 unk190[0x28];
    u8 unk1B8[0x78];
    struct subStruct_203B490 unk230[16];
    u8 unk2F0[0x38];
    u8 unk328;
};

extern struct unkStruct_203B490 *gUnknown_203B490;
