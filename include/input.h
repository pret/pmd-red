struct test
{
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk1;
    /* 0x4 */ u16 unk2;
    /* 0x6 */ u16 unk3;
    /* 0x8 */ u16 unk4;
};

struct test3
{
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk1;
    /* 0x4 */ u16 unk2;
    /* 0x6 */ u16 unk3;
};

struct Input
{
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk1;
    /* 0x4 */ u16 unk2;
    /* 0x6 */ u16 unk3;
    /* 0x8 */ u16 unk4;
    /* 0xA */ u16 unk5;
    /* 0xC */ u16 unk6;
    /* 0xE */ u16 unk7;
    /* 0x10 */ u16 unk8;
    /* 0x12 */ u16 unk9;
    /* 0x14 */ u16 unk10;
    /* 0x16 */ u16 unk11;
    /* 0x18 */ u16 unk12;
    /* 0x1A */ u16 unk13;
    /* 0x1C */ u16 unk14;
    /* 0x1E */ u16 unk15;
    /* 0x20 */ u16 unk16;
    /* 0x22 */ u16 unk17[3]; // padding
    /* 0x28 */ u8 unk18;
    /* 0x29 */ u8 unk19;
    /* 0x2A */ u8 unk20;
};

void InitInput(void);
void sub_800485C(void);
