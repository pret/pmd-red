#include "global.h"

struct unkData
{
    u8 unk0[14];
    u16 unkD;
    u16 unk10;
    u16 unk12;
    u8 *unk14;
};

struct unkStruct_203B360
{
    // size: 0x1b4
    u32 currMenu;
    u32 unk4;
    u32 unk8;
    u8 fill8[0x148 - 0xC];
    struct unkData unk148[4];
    u16 unk1A8;
    u16 unk1AA;
    u16 unk1AC;
    u16 unk1AE;
    u32 unk1B0; // Sprite count?
};

extern struct unkStruct_203B360 *gUnknown_203B360;
extern void AddSprite(u16 *, u32, u32, u32);

void sub_80384D0(void)
{
  if ((gUnknown_203B360->unk1B0 & 8) != 0) {
    AddSprite(&gUnknown_203B360->unk1A8, 0x100, 0, 0);
  }
  gUnknown_203B360->unk1B0++;
}
