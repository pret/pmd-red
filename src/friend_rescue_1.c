#include "global.h"
#include "friend_rescue.h"
#include "pokemon.h"

extern void sub_80338C4(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_802F2C0();
extern u8 sub_809539C(u32, u32);
extern void sub_8095240(u8);
extern u32 sub_802F298();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

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
    CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_PELIPPER);
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
