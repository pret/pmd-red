#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H 

struct UnkTextStruct1 {
    u8 fill00[4];
    u16 unk04;
    u8 fill06[2];
    u16 unk08;
    u8 fill04[0x3c];
    u8 unk46;
};

struct UnkTextStruct2 {
    u8 fill00[0x0c];
    s16 unk0c;
    u8 fill0e[2];
    s16 unk10;
    u8 fill12[0x06];
};

void sub_8006218(void);
u32 xxx_update_some_bg_tiles(u32 a0);
void sub_8006438(const struct UnkTextStruct2 *a0, u8 a1, u8 a2, u32 *a3);
void sub_8006554(void *a0, void *a1, void *a2, void *a3, u32 a4, const struct UnkTextStruct2 *a5, u8 a6, u32 a7, u32 *a8, u32 a9);
void sub_800898C(void);
void sub_80089AC(const struct UnkTextStruct2 *a0, void *a1);
void sub_8009388(void);
#endif
