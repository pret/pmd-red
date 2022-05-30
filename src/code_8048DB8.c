#include "global.h"
#include "constants/status.h"
#include "code_80521D0.h"
#include "dungeon_random.h"
#include "item.h"

extern void sub_803E708(u32, u32);
extern void sub_80421C0(struct DungeonEntity *r0, u16 r1);
extern void sub_8078B5C(struct DungeonEntity *, u32, u32, u32, u32);
extern void sub_80763F8(struct DungeonEntity *, u32, u32);
extern void sub_80769CC(struct DungeonEntity *, u32);
extern void sub_8076210(struct DungeonEntity *, u32, u32, u32);
extern void sub_8077780(struct DungeonEntity *, u32, u32);
extern void sub_8076E20(struct DungeonEntity *, u32, u32, u32, u32, u32);

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
extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_8051E7C(struct DungeonEntity *pokemon);
extern void sub_8045BF8(u8 *, struct ItemSlot *);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);

extern u8 *gUnknown_80FDCA4[];
extern u8 *gUnknown_80FE3E8[];

bool8 sub_8048D50(struct DungeonEntity * param_1,struct ItemSlot *param_2)
{
  struct DungeonEntityData *iVar2;

  iVar2 = param_1->entityData;
  
  if ((param_2->itemFlags & ITEM_FLAG_STICKY) != 0) {
    sub_8045BF8(gUnknown_202DE58,param_2);
    SendMessage(param_1,*gUnknown_80FE3E8);
    return FALSE;
  }
  else
  {
    if ((iVar2->muzzledStatus == MUZZLED_STATUS_MUZZLED) && (IsEdibleItem(param_2->itemIndex))) {
        SetMessageArgument(gAvailablePokemonNames,param_1,0);
        SendMessage(param_1,*gUnknown_80FDCA4);
        return FALSE;
    }
  }
  return TRUE;
}

void sub_8048DB8(struct DungeonEntity *pokemon, struct DungeonEntity *r1, u8 r2)
{
    u8 temp;
    if(r2 != 0)
        sub_806F370(pokemon, r1, gUnknown_80F4FAC, 1, &temp, 0, 0x217, 0, 0, 0);
    else
        sub_8051E7C(pokemon);
}

void sub_8048E04(struct DungeonEntity *pokemon, u32 r1)
{
    sub_8078B5C(pokemon, r1, 0x1E, 0, 1);
    switch(DungeonRandomCapped(5))
    {
        case 0:
            sub_80763F8(pokemon, r1, 1);
            break;
        case 1:
            sub_80769CC(pokemon, r1);
            break;
        case 2:
            sub_8076210(pokemon, r1, 1, 1);
            break;
        case 3:
            sub_8077780(pokemon, r1, 1);
            break;
        case 4:
            sub_8076E20(pokemon, r1, gUnknown_8106A4C, 3, 1, 1);
            sub_8076E20(pokemon, r1, gUnknown_8106A50, 3, 1, 1);
            break;
    } 
}

void sub_8048EB0(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrIcePartCrumbledMessage);
}

void sub_8048EC4(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrRockPartCrumbledMessage);
}

void sub_8048ED8(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrSteelPartCrumbledMessage);
}

void sub_8048EEC(struct DungeonEntity *pokemon)
{
    SendMessage(pokemon, *gPtrWishStoneCrumbledMessage);
}

void sub_8048F00(struct DungeonEntity *pokemon)
{
    sub_80421C0(pokemon, 0xD6);
    SendMessage(pokemon, *gPtrMusicBoxPlayedCrumbledMessage);
    sub_803E708(0x3C, 0x46);
}

