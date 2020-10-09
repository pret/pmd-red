#include "global.h"


struct UnkOtherStructTemp
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
    /* 0xC */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u16 *unk20;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u16 unk28;
    /* 0x2A */ u16 unk2A;
};

struct UnkStructTemp
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
    /* 0xC */ u32 unkC;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ struct UnkOtherStructTemp *unk20;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u16 unk28;
    /* 0x2A */ u16 unk2A;
};


extern struct UnkStructTemp *gUnknown_203B2BC;
u32 sub_801B410();
void sub_801B450();
void sub_8027184(u8 r0);
u32 sub_801EF38(u8 r0);
struct UnkOtherStructTemp *sub_801F194();
void sub_8027184(u8 r0);
void sub_801F214();

void sub_8027C84()
{
    u32 temp = sub_801B410();
    if(temp <= 1)
        return;
    if(temp > 3)
        return;
    sub_801B450();
    sub_8027184(0xB);
}

//void sub_8027CA0()
//{
//    struct UnkOtherStructTemp *temp_store;
//    u32 temp = sub_801EF38(1);
//    if(temp > 4)
//        return;
//    switch(temp)
//    {
//        case 0:
//        case 1:
//            break;
//        case 2:
//            sub_801F214();
//            sub_8027184(0x2);
//            return;
//        case 3:
//        case 4:
//            temp_store = sub_801F194();
//            gUnknown_203B2BC->unk20 = temp_store;
//            // TODO missing
//            // lsls r0, 3
//            // adds r0, r1, r0
//            // Why are we shifting the pointer by 3?
//            gUnknown_203B2BC->unk24 = temp_store->unk2A;
//            sub_8027184(0x10);
//            break;
//    }
//}
