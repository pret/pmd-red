struct unkStruct_203B2E8
{
    // size: 0xA8
    u8 pelipperBoardSlots[MAX_ACCEPTED_JOBS];
    struct MenuInputStruct input;
    u32 unk3C;
    struct UnkTextStruct2 *unk40;
    struct UnkTextStruct2 unk44[4];
    u8 unkA4[4];
};

struct unkStruct_203B2F0
{
    // size: 0x1FC
    u32 unk0;
    u32 state;
    u8 unk8[0xC - 0x8];
    u8 unkC;
    struct unkStruct_802C39C unk10;
    u32 menuAction;
    struct MenuStruct unk6C;
    struct MenuStruct unkBC;
    struct MenuItem unk10C[8];
    struct MenuItem unk14C[8];
    u8 fill18C[0x19C - 0x18C];
    struct UnkTextStruct2 unk19C[4];
};
