#include "global.h"
#include "input.h"

EWRAM_DATA struct Input gUnknown_2025600;
EWRAM_DATA struct UnkInputStruct1 gUnknown_20255F0;
EWRAM_DATA struct UnkInputStruct1 gUnknown_2025638;
EWRAM_DATA struct UnkInputStruct1 gUnknown_2025648;
EWRAM_DATA struct UnkInputStruct2 gUnknown_2025668;
EWRAM_DATA u32 gUnknown_202562C;

void InitInput(void)
{
    gUnknown_20255F0.unk0 = 0;
    gUnknown_20255F0.unk2 = 0;
    gUnknown_20255F0.unk4 = 0;
    gUnknown_20255F0.unk6 = 0;

    gUnknown_2025638.unk0 = 0;
    gUnknown_2025638.unk2 = 0;
    gUnknown_2025638.unk4 = 0;
    gUnknown_2025638.unk6 = 0;

    gUnknown_202562C = 4854977; // ????? (0x4a14c1)

    gUnknown_2025600.unk20 = 0;
    gUnknown_2025600.unk0 = 0xffff; // probably a mask
    gUnknown_2025600.unk2 = -1;
    gUnknown_2025600.unk4 = -1;
    gUnknown_2025600.unk6 = -1;
    gUnknown_2025600.unk1C = -1;
    gUnknown_2025600.unk1E = -1;
    gUnknown_2025600.unk8 = -1;
    gUnknown_2025600.unkA = -1;
    gUnknown_2025600.unkC = -1;
    gUnknown_2025600.unkE = -1;
    gUnknown_2025600.unk10 = -1;
    gUnknown_2025600.unk12 = -1;
    gUnknown_2025600.unk14 = -1;
    gUnknown_2025600.unk16 = -1;
    gUnknown_2025600.unk28 = 0;
    gUnknown_2025600.unk29 = 0;

    gUnknown_2025668.unk0 = 0;
    gUnknown_2025668.unk2 = 0;
}

void sub_800485C(void)
{
    gUnknown_20255F0 = gUnknown_2025638;

    gUnknown_2025638.unk0 = 0;
    gUnknown_2025638.unk2 = 0;
    gUnknown_2025638.unk4 = 0;
    gUnknown_2025638.unk6 = 0;

    gUnknown_2025600.unk0 = 0xffff;
    gUnknown_2025600.unk2 = -1;
    gUnknown_2025600.unk4 = -1;
    gUnknown_2025600.unk6 = -1;
    gUnknown_2025600.unk8 = -1;
    gUnknown_2025600.unkA = -1;
    gUnknown_2025600.unkC = -1;
    gUnknown_2025600.unkE = -1;
    gUnknown_2025600.unk10 = -1;
    gUnknown_2025600.unk12 = -1;
    gUnknown_2025600.unk14 = -1;
    gUnknown_2025600.unk16 = -1;

    gUnknown_2025600.unk28 = 0;
    gUnknown_2025600.unk29 = 0;
}

// Unused
u8 sub_80048B8(void)
{
    return 0;
}

u8 sub_80048BC(void)
{
    return 0;
}

// Unused
u8 sub_80048C0(void)
{
    return 0;
}

// Unused
u8 sub_80048C4(void)
{
    return 0;
}

u8 sub_80048C8(void)
{
    return 0;
}

// Unused
u8 sub_80048CC(void)
{
    return 0;
}

void sub_80048D0(void)
{
    gUnknown_20255F0.unk4 = 0;
    gUnknown_2025648.unkC = 0;
    gUnknown_2025648.unk8 = 0;
    gUnknown_2025668.unk0 = 0x3e7;
    gUnknown_2025668.unk2 = 0x3e7;

}

void sub_80048F8(void)
{
    gUnknown_20255F0.unk2 = 0;
    gUnknown_2025638.unk2 = 0;
    gUnknown_2025648.unk2 = 0;
}

void sub_8004914(void)
{
    gUnknown_2025600.unk20 = 0x5;
    gUnknown_2025600.unk24 = 0;
    gUnknown_2025600.unk0 = 0xffff;
    gUnknown_2025600.unk2 = -1;
    gUnknown_2025600.unk4 = -1;
    gUnknown_2025600.unk6 = -1;
    gUnknown_2025600.unk8 = -1;
    gUnknown_2025600.unkA = -1;
    gUnknown_2025600.unkC = -1;
    gUnknown_2025600.unkE = -1;
    gUnknown_2025600.unk10 = -1;
    gUnknown_2025600.unk12 = -1;
    gUnknown_2025600.unk14 = -1;
    gUnknown_2025600.unk16 = -1;

    gUnknown_2025600.unk28 = 0;
    gUnknown_2025600.unk29 = 0;

}
