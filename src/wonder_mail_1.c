#include "global.h"
#include "constants/species.h"

extern void sub_80338C4(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_802F2C0();
extern void sub_808D8E0(u8 *, u32);
extern char * GetMonSpecies(u32);
extern u8 sub_809539C(u32, u32);
extern void sub_8095240(u8);
extern u32 sub_802F298();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

struct WonderMailStruct_203B33C
{
    // size: 0x568
    u32 unk0;
    u32 unk4;
    u8 unk8[0x38];
    u32 unk40;
    u32 unk44;
    u16 unk48[232];
    u8 unk218;
    u8 padding7[3];
    u32 unk21C;
    u8 padding[0x7C];
    u32 unk29C;
    u8 padding6[0x6C];
    u32 unk30C;
    u8 padding8[0x4C];
    u32 unk35C;
    u8 padding5[0x5C];
    u32 unk3BC;
    u8 padding4[0x60];
    u32 unk420; // Is this supposed to be a File like 203B2C4?
    u8 padding3[0x110];
    u32 unk534;
    s32 unk538; // A7 << 3
    u32 unk53C;
    u32 unk540; // A8 << 4
    s16 unk544;
    u8 filler546[0x564 - 0x546];
    s32 unk564;
};
extern struct WonderMailStruct_203B33C *gUnknown_203B33C;

void nullsub_46(void)
{
}

void nullsub_47(void)
{
}

void nullsub_48(void)
{
}

void nullsub_49(void)
{
}

void sub_80352A4(void)
{
  u8 uVar1;
  char *monName;

  if ( sub_802F298() == 3) {
    sub_802F2C0();
    sub_808D8E0(gUnknown_202E5D8, SPECIES_PELIPPER);
    monName = GetMonSpecies(SPECIES_PELIPPER);
    strcpy(gAvailablePokemonNames, monName);
    uVar1 = sub_809539C(6, gUnknown_203B33C->unk420);
    sub_8095240(uVar1);
    sub_80338C4(0x70);
  }
}

void sub_8035300(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            sub_80338C4(1);
            break;
        case 0x1B:
            sub_80338C4(0x7A);
            break;
        case 0x1C:
            sub_80338C4(0x7C);
            break;
        case 0x1A:
        case 0x1D:
            gUnknown_203B33C->unk564 = temp;
            sub_80338C4(0x79);
            break;
    }
}

void sub_8035374(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            sub_80338C4(0x78);
            break;
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
            gUnknown_203B33C->unk564 = temp;
            sub_80338C4(0x7B);
            break;
    }
}

void sub_80353BC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
        return;
    switch(temp)
    {
        case 0x19:
            sub_80338C4(0x78);
            break;
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
            gUnknown_203B33C->unk564 = temp;
            sub_80338C4(0x7D);
            break;
    }
}

void sub_8035404(u32 param_1)
{
  s32 iVar1;

  if(sub_80144A4(&iVar1) == 0){
    sub_80338C4(param_1);
  }
}

void sub_8035424(void)
{
    sub_80338C4(6);
}

void sub_8035430(void)
{
    sub_80338C4(0x4F);
}

void nullsub_50(void)
{
}

void nullsub_51(void)
{
}
