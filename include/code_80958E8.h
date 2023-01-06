struct subStruct_203B490
{
    // size: 0xC
    struct DungeonLocation dungeon;
    u32 unk4;
    u32 unk8;
};
 

struct unkStruct_203B490
{
    // size: 0x330?
    struct WonderMail mailboxSlots[4];
    struct WonderMail pelliperBoardJobs[8];
    /* 0xF0 */ struct WonderMail jobSlots[8];
    u8 unk190[0x28];
    u8 unk1B8[0x78];
    struct subStruct_203B490 unk230[16];
    u8 PKMNNewsReceived[56];
    bool8 unk328;
};

extern struct unkStruct_203B490 *gUnknown_203B490;
