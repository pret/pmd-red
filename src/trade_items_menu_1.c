#include "global.h"
#include "input.h"
#include "trade_items_menu.h"

extern struct TradeItemsMenu *gUnknown_203B358;

struct unkStruct_203B460
{
    u8 unk0[0x50];
    u16 unk50[10];
};

extern struct unkStruct_203B460 *gUnknown_203B460; // TODO unify this
extern u32 gTradeItemsHowManyText;
extern struct unkData gUnknown_80E6174;

// Trade Items Menu Link Error Messages
extern u32 gTradeItemsCommunicationError;
extern u32 gUnknown_80E639C;
extern u32 gUnknown_80E63F8;
extern u32 gUnknown_80E6448;
extern u32 gUnknown_80E64AC;

extern void sub_80141B4(u32 *, u32, u32, u32);

extern void nullsub_52();
extern void sub_8036B28();
extern void sub_8006518(struct unkData *);
extern void sub_8036ECC(u32, u32);
extern void sub_801CCD8();
void sub_8036F30();
extern void sub_8035CF4(u32 *, u32, u32);


extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);
extern void xxx_call_draw_string(u32, u32, u32 *, u32, u32);
extern void sub_8013AA0(u32 *);
extern void sub_800641C(struct unkData *, u32, u32);

void PrintTradeItemsLinkError(u32 errorNum)
{
  switch(errorNum) {
    case 0:
        break;
    case 1:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case 3:
        sub_80141B4(&gUnknown_80E639C, 0, 0, 0x101);
        break;
    case 2:
        sub_80141B4(&gUnknown_80E63F8, 0, 0, 0x101);
        break;
    case 4:
        sub_80141B4(&gUnknown_80E6448, 0, 0, 0x101);
        break;
    case 5:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case 0xe:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case 0xf:
        sub_80141B4(&gUnknown_80E64AC, 0, 0, 0x101);
        break;
    default:
    case 0x6:
    case 0x7:
    case 0x8:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
  }
}

void sub_8036ECC(u32 index, u32 r1)
{
  gUnknown_203B358->unk24 = 3;
  gUnknown_203B358->unk18 = 1;
  gUnknown_203B358->unk1C = 1;
  gUnknown_203B358->unk20 = r1;
  gUnknown_203B358->unk30 = 0x2c;
  gUnknown_203B358->unk34 = 0x12;
  gUnknown_203B358->unk28 = index;
  gUnknown_203B358->unk2C = &gUnknown_203B358->unk184[index];
  sub_8013AA0(&gUnknown_203B358->unk14);
  gUnknown_203B358->unk184[index] = gUnknown_80E6174;
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B358->unk184, 1, 1);
}

void sub_8036F30(void)
{
  u32 uVar1;

  uVar1 = gUnknown_203B358->unk28;
  sub_8008C54(uVar1);
  sub_80073B8(uVar1);
  // Draw "How many?"
  xxx_call_draw_string(2, 0, &gTradeItemsHowManyText, uVar1, 0);
  sub_8013C68(&gUnknown_203B358->unk14);
  sub_80073E0(uVar1);
}

void sub_8036F74(void)
{
  sub_8006518(gUnknown_203B358->unk184);
  sub_8036ECC(2, gUnknown_203B460->unk50[gUnknown_203B358->unk25E]);
  sub_801CCD8();
  sub_8035CF4(&gUnknown_203B358->unk44, 3, 0);
  sub_8036F30();
}

void SetTradeItemMenu(u32 newMenu)
{
    gUnknown_203B358->currMenu = newMenu;
    nullsub_52();
    sub_8036B28();
}
