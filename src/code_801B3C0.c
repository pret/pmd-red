#include "global.h"
#include "text.h"
#include "input.h"
#include "memory.h"
#include "item.h"
#include "team_inventory.h"

struct subStruct_203B240
{
    char * pokeName;
    char * unk4;
};

// based off of 203B240..
struct unkStruct_203B230
{
    // size: 0x94
    s32 state;
    struct ItemSlot unk4;
    s32 unk8;
    s32 unkC;
    struct subStruct_203B240 *unk10[2];
    u8 fill14[0x20 - 0x18];
    u32 unk20;
    u32 unk24;
    struct UnkTextStruct2 unk28[4];
    u32 unk88;
    u32 unk8C;
    u32 unk90;
};
extern struct unkStruct_203B230 *gUnknown_203B230;

extern u8 gAvailablePokemonNames[0x58];
extern u8 gUnknown_80DBA4C[];

extern void sub_8008C54(u32);
extern void sub_80073E0(u32);
extern void sub_80073B8(u32);
extern void xxx_format_and_draw(u32, u32, u8 *, u32, u32);
extern void PlayMenuSoundEffect(u32);
extern void sub_8013F84(void);
extern u32 sub_8012A64(u32 *, u32);
extern s32 sub_80913E0(struct ItemSlot *, u32, struct subStruct_203B240 **);

extern void sub_801317C(u32 *);
extern void sub_80140B4(struct UnkTextStruct2 *);
extern void sub_801B46C(u32);
extern void ResetSprites(u32);

void sub_801B51C();
void sub_801B590();
void sub_801B480();


u32 sub_801B3C0(struct ItemSlot *param_1)
{
  ResetSprites(1);
  gUnknown_203B230 = MemoryAlloc(sizeof(struct unkStruct_203B230),8);
  gUnknown_203B230->unk4 = *param_1;
  sub_801317C(&gUnknown_203B230->unk88);
  gUnknown_203B230->unk24 = 0;
  sub_80140B4(gUnknown_203B230->unk28);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B230->unk28,1,1);
  sub_801B46C(0);
  return 1;
}

u32 sub_801B410(void)
{
    switch(gUnknown_203B230->state)
    {
        case 0:
            sub_801B51C();
            break;
        case 1:
            sub_801B590();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;
    }
    return 0;
}

void sub_801B450(void)
{
    if(gUnknown_203B230 != NULL)
    {
        MemoryFree(gUnknown_203B230);
        gUnknown_203B230 = NULL;
    }
}

void sub_801B46C(u32 newState)
{
    gUnknown_203B230->state = newState;
    sub_801B480();
}

void sub_801B480(void)
{
    struct subStruct_203B240 *preload;
    switch(gUnknown_203B230->state)
    {
        case 0:
            sub_8008C54(gUnknown_203B230->unk24);
            gUnknown_203B230->unkC = sub_80913E0(&gUnknown_203B230->unk4, gUnknown_203B230->unk24, gUnknown_203B230->unk10);
            gUnknown_203B230->unk20 = 0;
            break;
        case 1:
            sub_8008C54(gUnknown_203B230->unk24);
            sub_80073B8(gUnknown_203B230->unk24);
            preload = gUnknown_203B230->unk10[gUnknown_203B230->unk8];
            strcpy(gAvailablePokemonNames, preload->pokeName);
            xxx_format_and_draw(16, 0, gUnknown_80DBA4C, gUnknown_203B230->unk24, 0); // $m0
            xxx_format_and_draw(4, 16, gUnknown_203B230->unk10[gUnknown_203B230->unk8]->unk4, gUnknown_203B230->unk24, 0);
            sub_80073E0(gUnknown_203B230->unk24);
            break;
        case 2:
        default:
            break;
    }
}

void sub_801B51C(void)
{
    if(gUnknown_203B230->unkC != 0)
    {
        if(gUnknown_203B230->unk20 & 8)
            sub_8013F84();
        gUnknown_203B230->unk20++;
    }
    switch(sub_8012A64(&gUnknown_203B230->unk88, gUnknown_203B230->unk24))
    {
        case 1:
            PlayMenuSoundEffect(0);
            if(gUnknown_203B230->unkC != 0)
            {
                gUnknown_203B230->unk8 = 0;
                sub_801B46C(1);
            }
            else
                sub_801B46C(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801B46C(2);
            break;
        default:
            break;
    }
}

void sub_801B590(void)
{
  
  if (gUnknown_203B230->unk8 < (gUnknown_203B230->unkC - 1)) {
    if ((gUnknown_203B230->unk20 & 8)) {
      sub_8013F84();
    }
    gUnknown_203B230->unk20++;
  }
  switch(sub_8012A64(&gUnknown_203B230->unk88,gUnknown_203B230->unk24))
  {
    case 1:
        PlayMenuSoundEffect(0);
        gUnknown_203B230->unk8++;
        if (gUnknown_203B230->unk8 < gUnknown_203B230->unkC) {
            sub_801B46C(1);
        }
        else {
            sub_801B46C(0);
        }
        break;
    case 2:
        PlayMenuSoundEffect(1);
        sub_801B46C(2);
        break;
  }
}
