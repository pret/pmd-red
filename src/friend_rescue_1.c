#include "global.h"
#include "text.h"
#include "pokemon.h"
#include "save.h"
#include "memory.h"
#include "input.h"
#include "team_inventory.h"
#include "friend_rescue.h"
#include "sub_8095228.h"

extern struct TeamInventory *gTeamInventory_203B460;

extern void sub_80338C4(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_802F2C0();
extern u8 sub_809539C(u32, u32);
extern void sub_8095240(u8);
extern u32 sub_802F298();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern struct WonderMailStruct_203B33C *gUnknown_203B33C;

u8 sub_80953D4(u32);
u8 sub_801CF14(u32);

extern u8 gUnknown_80E48A8[];
extern u32 gUnknown_80E2440;
extern u8 gUnknown_80E49C4[];
extern u8 gUnknown_80E4704[];

u8 sub_809539C(u32, u32);
u32 sub_8039068(u32, u8 *, u8 *);
extern u32 sub_80154F0();
extern void sub_80155F0();
struct unkStruct_8095228 *sub_8095228(u8);
extern void sub_80141B4(u8 *r0, u32, u32 *r1, u32);
extern void sub_8014248(const char *r0, u32, u32, u32 *r4, u32, u32, u32, u32 *r5, u32);

void sub_8034D54(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_80338C4(0x65);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034D74(void)
{
    u32 return_var;
    struct unkStruct_8095228 temp;
    struct unkStruct_8095228 *temp2;

    return_var = sub_80154F0();
    MemoryFill8((u8 *)&temp, 0, sizeof(struct unkStruct_8095228));
    switch(return_var)
    {
        case 3:
                switch(sub_8039068(0x20, (gUnknown_203B33C->unk8), &temp.unk0))
                {
                    case 17:
                        sub_8014248(gUnknown_80E48A8, 0, 6, &gUnknown_80E2440, 0, 4, 0, 0, 0x101);
                        sub_80338C4(0x74);
                        break;
                    case 20:
                        sub_80141B4(gUnknown_80E49C4, 0, 0, 0x101);
                        sub_80338C4(0x6B);
                        break;
                    case 11:
                        sub_80141B4(gUnknown_80E4704, 0, 0, 0x101);
                        sub_80338C4(0x6B);
                        break;
                    case 24:
                        temp2 = sub_8095228(sub_809539C(4, temp.unk10));
                        *temp2 = temp;
                        temp2->unk0 = 6; // Some sort of Ack?
                        gUnknown_203B33C->unk420 = temp.unk10;
                        sub_80338C4(0x6D);
                        break;
                    case 7:
                    default:
                        break;
                }
            sub_80155F0();
            break;
        case 2:
            sub_80155F0();
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B33C->unk3BC, 1, 1);
            sub_80338C4(1);
            break;
        default:
            break;
    }
}

void sub_8034EC8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            sub_80338C4(2);
        }
    }
}

void sub_8034EF0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            sub_80338C4(2);
        }
    }
}

void sub_8034F18(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        sub_80338C4(0x65);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034F38(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        sub_80338C4(0x71);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8034F58(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                sub_80338C4(0x62);
                break;
            case 8:
                sub_80338C4(0x1);
                break;
        }
    }
}

void sub_8034F88(void)
{
    s32 temp;
    struct unkStruct_8095228 *temp2;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                temp2 = sub_8095228(gUnknown_203B33C->unk218);
                if(gUnknown_203B33C->unk41C.itemIndex != 0)
                    temp2->unk20 = gUnknown_203B33C->unk41C;
                gTeamInventory_203B460->unk50[gUnknown_203B33C->unk41C.itemIndex]--;
                sub_80338C4(0x75);
                break;
            case 7:
                sub_80338C4(0x57);
                break;
            case 8:
                sub_80338C4(0x1);
                break;
        }
    }
}

void sub_8035018(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        sub_80338C4(0x76);
        PrepareSavePakWrite(SPECIES_NONE);
    }
}

void sub_8035038(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak()){
            FinishWriteSavePak();
            // Dumb cast to get unsigned switch
            switch((u32)gUnknown_203B33C->unk524)
            {
                default:
                    break;
                case 0xB:
                case 0xC:
                    sub_80338C4(0x69);
                    break;
                case 0xD:
                    sub_80338C4(0x66);
                    break;
                case 0xE:
                    sub_80338C4(0x4B);
                    break;
            }
        }
    }
}

void sub_8035094(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0x16:
                // Dumb cast to get unsigned switch
                switch((u32)gUnknown_203B33C->unk524)
                {
                    default:
                        break;
                    case 0xB:
                    case 0xC:
                        sub_80338C4(0x69);
                        break;
                    case 0xD:
                        sub_80338C4(0x66);
                        break;
                    case 0xE:
                        sub_80338C4(0x4B);
                        break;
                }
                break;
            case 8:
                sub_80338C4(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_80350F4(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0x15:
                if(sub_801CF14(0) != 0)
                    sub_80338C4(0x56);
                else
                    sub_80338C4(0x57);
                break;
            case 0x16:
                // Dumb cast to get unsigned switch
                switch((u32)gUnknown_203B33C->unk524)
                {
                    default:
                        break;
                    case 0xB:
                    case 0xC:
                        sub_80338C4(0x69);
                        break;
                    case 0xD:
                        sub_80338C4(0x66);
                        break;
                    case 0xE:
                        sub_80338C4(0x4B);
                        break;
                }
                break;
            case 8:
                sub_80338C4(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_803517C(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                // Dumb cast to get unsigned switch
                switch((u32)gUnknown_203B33C->unk524)
                {
                    default:
                        break;
                    case 0xB:
                    case 0xC:
                        sub_80338C4(0x69);
                        break;
                    case 0xD:
                        sub_80338C4(0x66);
                        break;
                    case 0xE:
                        sub_80338C4(0x4B);
                        break;
                }
                break;
            case 8:
                sub_80338C4(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_80351E0(void)
{
    s32 temp;

    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 6:
                sub_80338C4(0x72);
                break;
            case 8:
                sub_80338C4(0x1);
                break;
            default:
                break;
        }
    }
}

void sub_8035210(void)
{
    s32 temp;
    struct unkStruct_8095228 *temp2;

    if(sub_80144A4(&temp) == 0)
    {
        // NOTE: this is why unk524 can't be changed to u32..
        gUnknown_203B33C->unk524 = temp;
        switch(gUnknown_203B33C->unk524)
        {
            case 0xB:
            case 0xC:
            case 0xD:
                if(gUnknown_203B33C->unk528 == 0x13)
                {
                    temp2 = sub_8095228(sub_80953D4(5));
                    if(temp2->unk20.itemIndex != 0)
                        sub_80338C4(0x53);
                    else
                        sub_80338C4(0x55);
                }
                else if(gUnknown_203B33C->unk524 != 0xD)
                    sub_80338C4(0x69);
                else
                    sub_80338C4(0x72);
                break;
            case 8:
                sub_80338C4(1);
                break;
            case 0xE:
            default:
                break;
        }
    }
}

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
