#include "global.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "pokemon.h"

extern struct DungeonGlobalData *gDungeonGlobalData;
extern void sub_807191C(struct DungeonEntity *);
extern struct DungeonEntity *sub_8085480(void);
extern struct DungeonEntity *sub_8085680(u32);
extern void sub_808EC94(u8 *param_1, u8 param_2);
extern void sub_8097FF8(void);
extern u8 sub_8044B28(void);
extern u8 HasRecruitedMon(u32);
extern u8 gUnknown_202E038[];
extern void sub_8083E88(u32);
extern void sub_8085374();
extern void sub_80854D4();
extern void sub_8085930(u32);
extern void sub_80855E4(void *);
extern void sub_8085860(s32 r0, u32 r1);
extern void sub_8068FE0(struct DungeonEntity *, u32, u32);
extern void sub_8097FA8(u32);

void sub_8086A3C(struct DungeonEntity *param_1)
{
    param_1->entityData->unk15C = 1;
    param_1->entityData->unk15E = 1;
}

void sub_8086A54(struct DungeonEntity *param_1)
{
    param_1->entityData->unk15C = 1;
    param_1->entityData->unk15E = 0;
}

void SetupBossFightHP(struct DungeonEntity *param_1, s32 newHP, u16 param_3)
{

  // NOTE: needed two of these to match.. very dumb
  struct DungeonEntityData *iVar1;
  struct DungeonEntityData *iVar2;

  iVar1 = param_1->entityData;
  iVar2 = param_1->entityData;

  iVar1->isBoss = TRUE;

  // BUG: Source of the Reviver Seed Boss Glitch
  //
  // Video to demonstration:
  // https://www.youtube.com/watch?v=rHu7EehrZ68
  iVar1->originalHP = iVar1->maxHP;
  if (newHP != 0) {
    iVar1->maxHP = newHP;
    iVar1->HP = newHP;
  }

  gDungeonGlobalData->unk66A = param_3;
  sub_808EC94(iVar2->IQSkillsSelected,iVar2->isBoss);
  sub_807191C(param_1);
}

void sub_8086AC0(void)
{
    if(!sub_8044B28())
        if(gDungeonGlobalData->unk2 == 0)
            sub_8097FF8();
}

u8 sub_8086AE4(s16 _index)
{
    s32 pokeIndex = _index;

    if(gDungeonGlobalData->unk65C == 0)
        return 1;
    else
        return HasRecruitedMon(pokeIndex);
}

void sub_8086B14(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar1 = sub_8085480();
  iVar2 = sub_8085680(4);
  uVar3 = sub_8085680(3);
  sub_8083E88(0x72);
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(uVar3);
  iVar2->entityData->unk15C = 1;
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY + -2);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_DIGLETT);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_SKARMORY);
}

void sub_8086B94(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar1 = sub_8085480();
  iVar2 = sub_8085680(4);
  uVar3 = sub_8085680(3);

  sub_8068FE0(uVar3,0x21c,0);
  sub_8068FE0(iVar2,0x21c,0);
  sub_80854D4();
  sub_8085930(4);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY);
}

void sub_8086BDC(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) - 0x1000000U) >> 0x18 < 2) && (param_1 == 3)) {
    sub_8097FA8(1);
    gDungeonGlobalData->unk2 = 1;
  }
}
