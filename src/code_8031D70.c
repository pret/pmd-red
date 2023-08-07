#include "global.h"
#include "constants/wonder_mail.h"
#include "constants/colors.h"
#include "input.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "dungeon_global_data.h"
#include "pokemon.h"
#include "code_8094F88.h"
#include "menu_input.h"

struct unkStruct_203B334
{
    // size: 0x7C
    u32 mailIndex;
    struct MenuInputStructSub unk4;
    u32 unk10;
    struct UnkTextStruct2 *unk14;
    struct UnkTextStruct2 unk18[4];
    u8 unk78[4];
};

EWRAM_DATA_2 struct unkStruct_203B334 *gUnknown_203B334 = {0};
extern struct unkStruct_203B480 *gUnknown_203B480;

const struct UnkTextStruct2 gUnknown_80E1FA8 = {
    0, 0, 0, 0,
    3, 
    0x0, 0x0,
    0x0, 0x0,
    0x0, 0,
    NULL
};

const u8 gUnkData_80E1FC0[4] = {0x01, 0x00, 0x0A, 0x00};

const struct UnkTextStruct2 gUnknown_80E1FC4 = {
    0, 0, 0, 0,
    6, 
    0x2, 0x2,
    0x1A, 0xA,
    0xA, 0,
    gUnkData_80E1FC0
};

ALIGNED(4) const u8 gUnknown_80E1FDC[] = "Password";
ALIGNED(4) static const u8 fill0[] = "pksdir0";

extern void sub_8008C54(u32);
extern void sub_80073E0(u32);
extern void sub_80078A4(u32, u32, u32, u32, u32);
extern void sub_803D2C0(u8 *, struct unkStruct_203B480 *);
extern void PlayMenuSoundEffect(u32);

void sub_8031E00(void);
void sub_8031E58(void);
void DrawSOSPasswordScreen(void);

bool8 sub_8031D70(u32 mailIndex, s32 param_2)
{
  gUnknown_203B334 = MemoryAlloc(sizeof(struct unkStruct_203B334),8);
  gUnknown_203B334->mailIndex = mailIndex;
  sub_801317C(&gUnknown_203B334->unk4);
  gUnknown_203B334->unk10 = param_2;
  gUnknown_203B334->unk14 = &gUnknown_203B334->unk18[param_2];
  sub_8006518(gUnknown_203B334->unk18);
  gUnknown_203B334->unk18[gUnknown_203B334->unk10] = gUnknown_80E1FC4;
  sub_8031E00();
  return TRUE;
}

u32 sub_8031DCC(void)
{
    switch(sub_8012A64(&gUnknown_203B334->unk4, gUnknown_203B334->unk10))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            return 0;
    }
}

void sub_8031E00(void)
{
    sub_8031E58();
    DrawSOSPasswordScreen();
}

void sub_8031E10(void)
{
    if(gUnknown_203B334)
    {
        gUnknown_203B334->unk18[gUnknown_203B334->unk10]  = gUnknown_80E1FA8;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B334->unk18, 1, 1);
        MemoryFree(gUnknown_203B334);
        gUnknown_203B334 = NULL;
    }
}

void sub_8031E58(void)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B334->unk18, 1, 1);
}

void DrawSOSPasswordScreen(void)
{
  int rowIndex;
  u32 x;
  u32 y;
  u32 color;
  s32 index;
  u8 buffer [PASSWORD_BUFFER_SIZE + 2];
  struct unkStruct_203B480 *mail;
  
  mail = &gUnknown_203B480[gUnknown_203B334->mailIndex];
  sub_80073B8(gUnknown_203B334->unk10);
  xxx_call_draw_string(0x14,0,gUnknown_80E1FDC,gUnknown_203B334->unk10,0); // Password
  sub_803D2C0(buffer, mail);
  for(index = 0; index < PASSWORD_BUFFER_SIZE; index++)
  {
    if (index < 5) {
        color = COLOR_WHITE_2;
        y = 0x15;
    }
    else if (index < 0xd) {
        color = COLOR_YELLOW;
        y = 0x16;
    }
    else if (index < 0x12)
    {
        color = COLOR_WHITE_2;
        y = 0x15;
    }
    else if (index < 0x17) {
        color = COLOR_WHITE_2;
        y = 0x24;
    }
    else if (index < 0x1f) {
        color = COLOR_YELLOW;
        y = 0x25;
    }
    else if (index < 0x24)
    {
        color = COLOR_WHITE_2;
        y = 0x24;
    }
    else
    {
        if(index > 0x28)
        {
            if(index < 0x31)
            {
                color = COLOR_YELLOW;
                y = 0x34;
            }
            else
            {
                color = COLOR_WHITE_2;
                y = 0x33;
            }
        }
        else
        {
            color = COLOR_WHITE_2;
            y = 0x33;
        }
    }
    rowIndex = index % 0x12;
    x = rowIndex * 0xb + 6;
    sub_8012C60(x,y,buffer[index],color,gUnknown_203B334->unk10); // Draw character
    sub_80078A4(gUnknown_203B334->unk10,x,y + 0xA,10,COLOR_CYAN); // Draw underscore beneath character
  }
  sub_80073E0(gUnknown_203B334->unk10);
}
