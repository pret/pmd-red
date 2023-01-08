#include "global.h"
#include "constants/status.h"
#include "code_80521D0.h"
#include "move_effects_target.h"
#include "dungeon_random.h"
#include "item.h"
#include "status.h"

extern void sub_803E708(u32, u32);
extern void sub_80421C0(struct Entity *r0, u16 r1);
extern void sub_8078B5C(struct Entity *, struct Entity *, u32, u32, u32);

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];

extern u8 *gPtrMusicBoxPlayedCrumbledMessage[];
extern u8 *gPtrWishStoneCrumbledMessage[];
extern u8 *gPtrIcePartCrumbledMessage[];
extern u8 *gPtrRockPartCrumbledMessage[];
extern u8 *gPtrSteelPartCrumbledMessage[];
extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4FAC;
extern void sub_806F370(struct Entity *r0, struct Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8051E7C(struct Entity *pokemon);
extern void sub_8045BF8(u8 *, struct Item *);
extern void SetMessageArgument(char[], struct Entity*, u32);

extern u8 *gUnknown_80FDCA4[];
extern u8 *gUnknown_80FE3E8[];

bool8 sub_8048D50(struct Entity * pokemon, struct Item *item)
{
  struct EntityInfo *entityData;

  entityData = pokemon->info;
  
  if ((item->flags & ITEM_FLAG_STICKY) != 0) {
    sub_8045BF8(gUnknown_202DE58, item);
    SendMessage(pokemon,*gUnknown_80FE3E8);
    return FALSE;
  }
  else
  {
    if ((entityData->muzzled == TRUE) && (IsEdibleItem(item->id))) {
        SetMessageArgument(gAvailablePokemonNames,pokemon,0);
        SendMessage(pokemon,*gUnknown_80FDCA4);
        return FALSE;
    }
  }
  return TRUE;
}

void sub_8048DB8(struct Entity *pokemon, struct Entity *target, u8 r2)
{
    u8 temp;
    if(r2 != 0)
        sub_806F370(pokemon, target, gUnknown_80F4FAC, 1, &temp, 0, 0x217, 0, 0, 0);
    else
        sub_8051E7C(pokemon);
}

void sub_8048E04(struct Entity *pokemon, struct Entity * target)
{
    sub_8078B5C(pokemon, target, 0x1E, 0, 1);
    switch(DungeonRandInt(5))
    {
        case 0:
            PoisonedStatusTarget(pokemon, target, TRUE);
            break;
        case 1:
            ImmobilizedStatusTarget(pokemon, target);
            break;
        case 2:
            BurnedStatusTarget(pokemon, target, 1, TRUE);
            break;
        case 3:
            ParalyzeStatusTarget(pokemon, target, TRUE);
            break;
        case 4:
            LowerAttackStageTarget(pokemon, target, gUnknown_8106A4C, 3, 1, TRUE);
            LowerAttackStageTarget(pokemon, target, gUnknown_8106A50, 3, 1, TRUE);
            break;
    } 
}

void sub_8048EB0(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrIcePartCrumbledMessage);
}

void sub_8048EC4(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrRockPartCrumbledMessage);
}

void sub_8048ED8(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrSteelPartCrumbledMessage);
}

void sub_8048EEC(struct Entity *pokemon)
{
    SendMessage(pokemon, *gPtrWishStoneCrumbledMessage);
}

void sub_8048F00(struct Entity *pokemon)
{
    sub_80421C0(pokemon, 0xD6);
    SendMessage(pokemon, *gPtrMusicBoxPlayedCrumbledMessage);
    sub_803E708(0x3C, 0x46);
}

