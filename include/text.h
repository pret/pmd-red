#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H 

// size: 0x48
struct UnkTextStruct1
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u8 *unk18;
    u8 *unk1C;
    s32 unk20;
    s32 unk24;
    void *unk28; // Somewhere in VRAM
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 fill3C[0x45 - 0x3C];
    bool8 unk45;
    u8 unk46;
};

// size: 0x4
struct UnkTextStruct2_sub
{
    u16 unk0;
    u16 unk2;
};

// size: 0x18
struct UnkTextStruct2
{
    u8 unk0;
    u8 fill1[0x4 - 0x1];
    s32 unk4;
    struct UnkTextStruct2_sub unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    const u8 *unk14;
};

void LoadCharmaps(void);
void SelectCharmap(u32);
u32 xxx_update_some_bg_tiles(u32 a0);
void sub_8006438(const struct UnkTextStruct2 *a0, u8 a1, u8 a2, u32 *a3);
void sub_8006554(void *a0, void *a1, void *a2, void *a3, u32 a4, const struct UnkTextStruct2 *a5, u8 a6, u32 a7, u32 *a8, u32 a9);
void sub_800898C(void);
void sub_80089AC(const struct UnkTextStruct2 *a0, void *a1);
void sub_8009388(void);
void sub_800641C(struct UnkTextStruct2 *a0, u8 a1, u8 a2);
void sub_8006518(struct UnkTextStruct2 *);
extern void xxx_call_draw_string(s32 x, u32 y, const u8 *str, u32 , u32);
#endif
