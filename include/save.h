#ifndef SAVE_H
#define SAVE_H

#include "time.h"

struct UnkStruct_203B184 {
    /* 0x0 */ u32 *unk0;
    /* 0x4 */ u32 *unk4;
    /* 0x8 */ u8 *unk8;
    /* 0xC */ u8 *unkC;
    /* 0x10 */ u32 *unk10;
    /* 0x14 */ u32 *unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 *unk24;
    /* 0x28 */ u8 *BoughtFriendAreas;
    /* 0x2C */ u32 unk2C;
    /* 0x30 */ struct PlayTimeStruct *playTime;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u8 *unk04C;
    u32 unk050;
    u32 unk054;
    u32 unk058;
};

void sub_8012468(void);
u8 sub_8012484(void);
void sub_8012558(void);
void sub_8012574(s16 PokemonID);
u8 sub_8012600(void);
u32 sub_8012744(void);
void sub_8012750(void);
u32 sub_80127A8(void);
u8 sub_8012828(void);
void sub_8012834(void);
void sub_8012850(u8 *r0, u32 r1, u8 r2);
u32 sub_80128B0(void);
void sub_80129FC(void);

#endif
