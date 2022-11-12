#include "global.h"
#include "constants/ability.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_items.h"
#include "dungeon_util.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "moves.h"
#include "pokemon.h"
#include "status_checks_1.h"

extern u8 gAvailablePokemonNames[0x58];
extern u8 gUnknown_202DFE8[0x58];
extern u8 *gUnknown_80FA8BC[];
extern u8 *gUnknown_80FA824[];
extern u8 *gUnknown_80FA81C[];
extern u8 *gUnknown_80FABF8[];
extern u8 *gUnknown_80FA820[];
extern u8 *gUnknown_80FA800[];
extern u8 *gUnknown_80FAC38[];
extern u8 *gUnknown_80FA97C[];
extern u8 *gUnknown_80FA9DC[];
extern u8 *gUnknown_80FAAAC[];
extern u8 *gUnknown_80FAB90[];
extern u8 *gUnknown_80FAC18[];
extern u8 *gUnknown_80FA638[];
extern u8 *gUnknown_80FA69C[];
extern u8 *gUnknown_80FA658[];
extern u8 *gUnknown_80FA67C[];
extern u8 *gUnknown_80FA6BC[];
extern u8 *gUnknown_80FA6D4[];
extern u8 *gUnknown_80FA9C0[];
extern u8 *gUnknown_80FAA68[];
extern u8 *gUnknown_80FAAC8[];
extern u8 *gUnknown_80FAAE8[];
extern u8 *gUnknown_80FAB08[];
extern u8 *gUnknown_80FAB28[];
extern u8 *gUnknown_80FAB40[];
extern u8 *gUnknown_80FA7BC[];
extern u8 *gUnknown_80FA9A0[];
extern u8 *gUnknown_80FA7DC[];
extern u8 *gUnknown_80FA79C[];
extern u8 *gUnknown_80FAA8C[];
extern u8 *gUnknown_80FA8E0[];
extern u8 *gUnknown_80FA90C[];
extern u8 *gUnknown_80FA934[];
extern u8 *gUnknown_80FA95C[];
extern u8 *gUnknown_80FABBC[];
extern u8 *gUnknown_80FAB6C[];
extern u8 *gUnknown_80FA9F4[];
extern u8 *gUnknown_80FAA0C[];
extern u8 *gUnknown_80FAA2C[];
extern u8 *gUnknown_80FAA48[];
extern u8 *gUnknown_80FABC0[];
extern u8 *gUnknown_80FA888[];
extern u8 *gUnknown_80FA8A8[];
extern u8 *gUnknown_80FA868[];
extern s16 gUnknown_80F4F78;
extern s16 gUnknown_80F4F2C[];
extern s32 gUnknown_80F4F7A;
extern u8 *gUnknown_80FA6E8[];
extern u8 *gUnknown_80FA708[];
extern u8 *gUnknown_80FA70C[];
extern u8 *gUnknown_80FA734[];
extern u8 *gUnknown_80FA710[];
extern u8 *gUnknown_80FA124[];
extern u8 *gPtrSealedMoveReleasedMessage[];
extern u8 *gUnknown_81004E8[];
extern u8 *gPtrExposedWoreOffMessage[];
extern u8 *gUnknown_8100594[];
extern u8 *gUnknown_80FBD18[];
extern u8 *gUnknown_80FBD3C[];
extern u8 *gUnknown_80FBCF0[];
extern u8 *gUnknown_80FBCC8[];
extern s16 gUnknown_80F4F24[];
extern u8 *gUnknown_80FBCA4[];
extern u8 *gUnknown_80FBC7C[];
extern u8 *gPtrForecastPreventsConversion2Message[];
extern s16 gUnknown_80F4F20[];
extern u8 *gUnknown_80FBC5C[];
extern u8 *gUnknown_80FBC38[];
extern s16 gUnknown_80F4F18[];
extern u8 *gUnknown_80FBC14[];
extern u8 *gUnknown_80FBBF0[];
extern s16 gUnknown_80F4EF8[];
extern u8 *gUnknown_80FBAE4[];
extern u8 *gUnknown_80FBAC0[];
extern s16 gUnknown_80F4EE8[];
extern u8 *gUnknown_80FB9B0[];
extern u8 *gUnknown_80FB9D8[];
extern s16 gUnknown_80F4ED4[];
extern s16 gUnknown_80F4E80[];
extern u8 *gUnknown_80FB17C[];
extern u8 *gUnknown_80FB1A8[];
extern s16 gUnknown_80F4E84[];
extern u8 *gUnknown_80FB130[];
extern u8 *gUnknown_80FB160[];
extern s16 gUnknown_80F4E90[];
extern u8 *gUnknown_80FAF5C[];
extern u8 *gUnknown_80FAF8C[];
extern s16 gUnknown_80F4EB4[];
extern u8 *gUnknown_80FAE1C[];
extern u8 *gUnknown_80FAE3C[];
extern s16 gUnknown_80F4E8C[];
extern u8 *gUnknown_80FB09C[];
extern u8 *gUnknown_80FB0C4[];
extern s16 gUnknown_80F4E88[];
extern u8 *gUnknown_80FB048[];
extern u8 *gUnknown_80FB074[];
extern s16 gUnknown_80F4E98[];
extern u8 *gUnknown_80FB10C[];
extern u8 *gUnknown_80FB0E0[];
extern u8 *gUnknown_80FC074[];
extern s16 gUnknown_80F4E9C[];
extern s16 gUnknown_80F4EA0[];
extern u8 *gUnknown_80FD254[];
extern u8 *gUnknown_80FD27C[];
extern u8 *gUnknown_80FD22C[];
extern u8 *gUnknown_80FD20C[];
extern u8 *gUnknown_80FC428[];
extern u8 *gUnknown_80FC454[];
extern u8 *gUnknown_80FC3D8[];
extern u8 *gUnknown_80FC3FC[];
extern u8 *gUnknown_80FC388[];
extern u8 *gUnknown_80FC3B4[];
extern u8 *gUnknown_80FC33C[];
extern u8 *gUnknown_80FC360[];
extern u8 *gUnknown_80FDBD0[];
extern u8 *gUnknown_80FDBF0[];
extern u8 *gUnknown_80FB880[];
extern u8 *gUnknown_80FB89C[];
extern s16 gUnknown_80F4F10[];
extern u8 *gUnknown_80FB834[];
extern u8 *gUnknown_80FB85C[];
extern s16 gUnknown_80F4F0C[];
extern s16 gUnknown_80F4F08[];
extern u8 *gUnknown_80FB810[];
extern u8 *gUnknown_80FB7F4[];
extern u8 *gUnknown_80FC028[];
extern u8 *gUnknown_80FC054[];
extern u8 *gUnknown_80FC000[];
extern u8 *gUnknown_80FBFD8[];
extern u8 *gUnknown_80FBF9C[];
extern u8 *gUnknown_80FBFB8[];
extern u8 *gUnknown_80FBF04[];
extern u8 *gUnknown_80FBEC0[];
extern s16 gUnknown_80F4EFC[];
extern u8 *gUnknown_80FBEE4[];
extern s16 gUnknown_80F4F04[];
extern u8 *gUnknown_80FBF50[];
extern u8 *gUnknown_80FBF28[];
extern s16 gUnknown_80F4F1C[]; 
extern u8 *gUnknown_80FBF68[]; 
extern u8 *gUnknown_80FBF84[]; 

extern void sub_8049ED4();
extern void sub_8040A84();
extern void sub_803E46C(u32);
extern u8 sub_806CEBC(struct DungeonEntity *);
extern void sub_806CCB4(struct DungeonEntity *, u8);
extern void SetMessageArgument(u8 *buffer, struct DungeonEntity *r1, u32);
extern void sub_80522F4(struct DungeonEntity *pokemon, struct DungeonEntity *r1, const char[]);
extern void DungeonEntityUpdateStatusSprites(struct DungeonEntity *);
extern void sub_8042A74(struct DungeonEntity *r0);
extern void sub_8076CB4(u32);
extern s32 GetMovementSpeed(struct DungeonEntity *);
extern void sub_807EC28(u32);
extern s32 sub_8069F54(struct DungeonEntity *param_1, s16 param_2);
extern u32 sub_80687D0(s16);
extern void sub_806A898(struct DungeonEntity *, u32, u32);
extern void HealTargetHP(struct DungeonEntity *pokemon, struct DungeonEntity *r1, s16, s16, u32);
extern void sub_806CE68(struct DungeonEntity *, s32);
extern void sub_806F324(struct DungeonEntity *, s16, u32, u32);
extern void sub_8075C58(struct DungeonEntity *, struct DungeonEntity *, s32, s32);
extern void sub_806BFC0(struct DungeonEntityData *, u32);
extern void sub_80420C8(struct DungeonEntity *r0);
extern void nullsub_68(struct DungeonEntity *);
extern void nullsub_67(struct DungeonEntity *);
extern void nullsub_66(struct DungeonEntity *);
extern void nullsub_65(struct DungeonEntity *);
extern void nullsub_64(struct DungeonEntity *);
extern void nullsub_63(struct DungeonEntity *);
extern void nullsub_62(struct DungeonEntity *);
extern void nullsub_61(struct DungeonEntity *);
extern void nullsub_60(struct DungeonEntity *);
extern void nullsub_59(struct DungeonEntity *);
extern void nullsub_58(struct DungeonEntity *);
extern void nullsub_57(struct DungeonEntity *);
extern void sub_8041B34(struct DungeonEntity *);
void sub_8041BD0(struct DungeonEntity *r0, u8 r1);
void sub_8041EB4(struct DungeonEntity *);
void sub_8041EA4(struct DungeonEntity *);
extern void sub_8041E84(struct DungeonEntity *);
extern void sub_8041E94(struct DungeonEntity *);
extern void sub_8041E74(struct DungeonEntity *);
extern void sub_8041E60(struct DungeonEntity *);
extern void sub_8041E4C(struct DungeonEntity *);
extern void sub_8041E3C(struct DungeonEntity *);
extern void sub_803F580(u32);
extern void sub_8041E1C(struct DungeonEntity *);
extern void nullsub_89(struct DungeonEntity *);
extern void nullsub_88(struct DungeonEntity *);
extern void nullsub_87(struct DungeonEntity *);
extern void nullsub_86(struct DungeonEntity *);
extern void sub_8041E0C(struct DungeonEntity *);
extern void sub_8041DD8(struct DungeonEntity *r0, s32 r1); // NOTE: is s16 in another file
extern s32 sub_803D870(void *, u32);
extern void sub_806CF98(struct DungeonEntity *);
extern bool8 sub_806AA0C(s32, u32);
u32 ExtractSpeciesIndex(struct PokemonStruct **r0); // TODO: look more into this and fix it.

void MuzzleTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *entityData;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->muzzledStatus != MUZZLED_STATUS_MUZZLED) {
        entityData->muzzledStatus = MUZZLED_STATUS_MUZZLED;
        entityData->muzzledTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4F1C, TRUE) + 1;
        nullsub_86(target);
        sub_80522F4(pokemon, target, *gUnknown_80FBF68);
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FBF84);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

// TODO: still gross but does match
void sub_8078E18(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  s16 species;
  s32 iVar5;
  s32 transformSpecies;
  s16 transformSpecies_s16;
  s32 index;
  struct DungeonEntityData *entityData;
  s32 iVar9;
  struct PokemonStruct *auStack544[128];
  

  if (EntityExists(target)) {
    entityData = target->entityData;
    if (entityData->transformStatus == TRANSFORM_STATUS_TRANSFORMED) {
      sub_80522F4(pokemon,target,*gUnknown_80FBF04);
    }
    else {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      iVar5 = sub_803D870(auStack544,0);
      if (iVar5 == 0) {
        goto print;
      }
      else
      {
        iVar9 = 0;

        for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
        {
          species = ExtractSpeciesIndex(&auStack544[DungeonRandomCapped(iVar5) << 1]);
          transformSpecies_s16 = sub_8069F54(target, species);
          transformSpecies = transformSpecies_s16;
          if (((transformSpecies != entityData->transformSpecies) && (sub_806AA0C(transformSpecies, 1))) &&
             (iVar9 = sub_80687D0(transformSpecies), iVar9 != 0)) break;
        }
        if ((index == DUNGEON_MAX_POKEMON) || (iVar9 == 0)) {
print:
            sub_80522F4(pokemon,target,*gUnknown_80FBEE4);
        }
        else
        {
          entityData->transformSpecies = transformSpecies;
          target->unk64 = iVar9;
          entityData->transformStatus = TRANSFORM_STATUS_TRANSFORMED;
          entityData->transformStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4EFC,TRUE) + 1;
          sub_806CF98(target);
          nullsub_87(target);
          sub_806CCB4(target, sub_806CEBC(target));
          CopyCyanSpeciesNametoBuffer(gUnknown_202DFE8, entityData->transformSpecies);
          sub_80522F4(pokemon,target,*gUnknown_80FBEC0);
          DungeonEntityUpdateStatusSprites(target);
        }
      }
    }
  }
}

void sub_8078F50(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData_1;
  struct DungeonEntityData *entityData;
  
 
  if (EntityExists(target)) {
    entityData_1 = target->entityData;
    entityData = entityData_1;

    if (entityData->transformStatus == TRANSFORM_STATUS_TRANSFORMED) {
        SendTransformEndMessage(pokemon,target);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->transformStatus != TRANSFORM_STATUS_MOBILE) {
        entityData->transformStatus = TRANSFORM_STATUS_MOBILE;
        entityData->transformStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4F04, FALSE) + 1;
        nullsub_88(target);
        sub_80522F4(pokemon,target,*gUnknown_80FBF28);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FBF50);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_8078FDC(struct DungeonEntity * pokemon, struct DungeonEntity * target, s16 param_3)
{
  struct DungeonEntityData *entityData;
  s32 param_3_s16;
  s32 param_3_s16_2;
  bool32 flag;
  bool32 flag2;

  param_3_s16 = param_3;
  param_3_s16_2 = param_3_s16;
  flag = FALSE;
  flag2 = FALSE;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->accuracyStages[1] > 10) {
      entityData->accuracyStages[1] = 10;
      flag = TRUE;
    }
    if(flag)
    {
        sub_8041DD8(target,param_3_s16);
        sub_80522F4(pokemon,target,*gUnknown_80FC000);
        flag2 = TRUE;
    }
    if (entityData->exposedStatus) {
        sub_80522F4(pokemon,target,*gUnknown_80FBFB8);
    }
    else
    {
      if (!flag2) {
        sub_8041DD8(target,param_3_s16_2);
      }
      if (!HasType(target, TYPE_GHOST)) {
        sub_80522F4(pokemon,target,*gUnknown_80FBFD8);
      }
      else {
        entityData->exposedStatus = TRUE;
        sub_80522F4(pokemon,target,*gUnknown_80FBF9C);
      }
      DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void IdentityItemHolders(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *entityData;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityData = target->entityData;
    if (!gDungeonGlobalData->itemHoldersIdentified) {
        nullsub_89(target);
        gDungeonGlobalData->itemHoldersIdentified = TRUE;
        DungeonEntityUpdateStatusSprites(target);
        sub_80522F4(pokemon,target,*gUnknown_80FC028);
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FC054);
    }
  }
}

void BlindTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *entityData;
  
  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->eyesightStatus != EYESIGHT_STATUS_BLINKER) {
        entityData->eyesightStatus = EYESIGHT_STATUS_BLINKER;
        entityData->eyesightStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4F08, TRUE) + 1;
        sub_8041E0C(target);
        sub_80522F4(pokemon,target,*gUnknown_80FB7F4);
        sub_803E46C(0x31);
        sub_8049ED4();
        sub_8040A84();
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FB810);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void CrossEyeVisionTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *entityData;
  

  if (EntityExists(target)) {
    if(!HasSafeguardStatus(pokemon, target, TRUE))
    {
        entityData = target->entityData;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (entityData->eyesightStatus != EYESIGHT_STATUS_CROSS_EYED) {
            sub_8041E1C(target);
            sub_80522F4(pokemon,target,*gUnknown_80FB834);
            entityData->eyesightStatus = EYESIGHT_STATUS_CROSS_EYED;
            entityData->eyesightStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4F0C, TRUE) + 1;
            sub_803F580(0x1);
            sub_8049ED4();
            sub_8040A84();
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FB85C);
        }
        DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void RestoreVisionTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *entityData;
  

  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->eyesightStatus != EYESIGHT_STATUS_EYEDROPS) {
        entityData->eyesightStatus = EYESIGHT_STATUS_EYEDROPS;
        entityData->eyesightStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4F10, FALSE) + 1;
        sub_8041E3C(target);
        sub_80522F4(pokemon,target,*gUnknown_80FB880);
        sub_803E46C(0x31);
        sub_8049ED4();
        sub_8040A84();
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FB89C);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void RestorePPTarget(struct DungeonEntity * pokemon,struct DungeonEntity * target, s32 param_3)
{
  volatile s32 PP;
  volatile s32 maxPP;
  struct PokemonMove *movePtr;
  struct PokemonMove *movePtr1;
  s32 index;
  bool8 PPChanged;
  struct DungeonEntityData *entityData;
  
  PPChanged = FALSE;
  if (EntityExists(target)) {
    entityData = target->entityData;

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &entityData->moves[index];
      movePtr1 = movePtr;
      if ((movePtr->moveFlags & MOVE_FLAG_EXISTS) != 0) {
        PP = movePtr->PP;
        maxPP = GetMoveMaxPP(movePtr1);
        if (PP < maxPP) {
          PP += param_3;
          if (PP > maxPP) {
            PP = maxPP;
          }
          movePtr->PP = PP;
          PPChanged = TRUE;
        }
      }
    }
    if (PPChanged) {
      sub_8041E4C(target);
      sub_80522F4(pokemon,target,*gUnknown_80FDBD0);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FDBF0);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_80793B0(struct DungeonEntity * pokemon, struct DungeonEntity *target, s32 param_3)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityData = target->entityData;
    entityData1 = entityData;
    oldStat = entityData->attack;
    oldStat1 = oldStat;

    newStat = entityData->attack + param_3;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityData1->attack = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E60(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC33C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC360);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_8079420(struct DungeonEntity * pokemon, struct DungeonEntity *target, s32 param_3)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityData = target->entityData;
    entityData1 = entityData;
    oldStat = entityData->specialAttack;
    oldStat1 = oldStat;

    newStat = entityData->specialAttack + param_3;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityData1->specialAttack = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E74(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC388);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC3B4);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_8079490(struct DungeonEntity * pokemon, struct DungeonEntity *target, s32 param_3)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityData = target->entityData;
    entityData1 = entityData;
    oldStat = entityData->defense;
    oldStat1 = oldStat;

    newStat = entityData->defense + param_3;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityData1->defense = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E84(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC3D8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC3FC);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_8079500(struct DungeonEntity * pokemon, struct DungeonEntity *target, s32 param_3)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  struct DungeonEntityData *entityData;
  struct DungeonEntityData *entityData1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityData = target->entityData;
    entityData1 = entityData;
    oldStat = entityData->specialDefense;
    oldStat1 = oldStat;

    newStat = entityData->specialDefense + param_3;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityData1->specialDefense = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E94(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC428);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC454);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void LongTossStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
    entityData = target->entityData;
    SetMessageArgument(gUnknown_202DFE8,target,0);
    if (entityData->itemStatus != ITEM_STATUS_LONG_TOSS) {
      entityData->itemStatus = ITEM_STATUS_LONG_TOSS;
      sub_8041EA4(target);
      sub_80522F4(pokemon,target,*gUnknown_80FD20C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FD22C);
    }
    DungeonEntityUpdateStatusSprites(target);
}

void PierceStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
    struct DungeonEntityData *entityData;
  
    entityData = target->entityData;
    SetMessageArgument(gUnknown_202DFE8,target,0);
    if (entityData->itemStatus != ITEM_STATUS_PIERCE) {
      entityData->itemStatus = ITEM_STATUS_PIERCE;
      sub_8041EB4(target);
      sub_80522F4(pokemon,target,*gUnknown_80FD254);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FD27C);
    }
    DungeonEntityUpdateStatusSprites(target);
}

void sub_8079618(struct DungeonEntity *pokemon, struct DungeonEntity *target, u8 newStatus, struct PokemonMove *move, u8 *message)
{
  bool8 bVar2;
  struct PokemonMove *movePtr;
  s32 index;
  bool8 uVar5;
  s32 iVar7;
  s32 iVar8;
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if ((entityData->chargingStatus == newStatus) && (newStatus == CHARGING_STATUS_RAGE)) {
      sub_80522F4(pokemon,target,*gUnknown_80FC074);
    }
    else {
      entityData->chargingStatus = newStatus;

      for(index = 0; index < MAX_MON_MOVES; index++)
      {
        movePtr = &entityData->moves[index];
        if(movePtr == move)
        {
            entityData->chargingStatusMoveIndex = index;
            break;
        }
      }
      entityData->unk14A = 1;

      uVar5 = FALSE;
      if ((u8)(newStatus - 7) < 2) {
        entityData->unkFF = 1;
        uVar5 = TRUE;
      }
      else if ((u8)(newStatus - 9) < 2) {
        entityData->unkFF = 2;
      }
      if (newStatus == 1) {
        entityData->chargingStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4E9C, FALSE) + 1;
        entityData->unkA0 = 0;
      }
      if (newStatus == CHARGING_STATUS_RAGE) {
        entityData->chargingStatusTurnsLeft = CalculateStatusTurns(target,gUnknown_80F4EA0, FALSE) + 1;
      }
      sub_8041BD0(target,uVar5);
      sub_80522F4(pokemon,target,message);
      DungeonEntityUpdateStatusSprites(target);

      // TODO: this could probably be cleaner..
      for (index = 0, iVar8 = 0xc7ff; index < 400; index++) {
        bVar2 = TRUE;
        if (entityData->unkFF == 1)
            if(iVar7 = entityData->unk174, bVar2 = FALSE, iVar7 > iVar8) // unk174 -> u32 to s32
            {
                bVar2 = TRUE;
            }
        if (bVar2) {
          break;
        }
        sub_803E46C(0x53);
      }
    }
  }
}

void sub_8079764(struct DungeonEntity * pokemon)
{
    struct DungeonEntityData *entityData;

    if (EntityExists(pokemon)) {
        entityData = pokemon->entityData;
        if ((entityData->chargingStatus != CHARGING_STATUS_BIDE) && (entityData->chargingStatus != CHARGING_STATUS_RAGE)) {
            entityData->chargingStatus = CHARGING_STATUS_NONE;
            entityData->unk14A = 0;
            entityData->unkFF = 0;
        }
        DungeonEntityUpdateStatusSprites(pokemon);
    }
}

void sub_80797A0(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 newStatus)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus == newStatus) {
      sub_80522F4(pokemon,target,*gUnknown_80FB10C);
    }
    else {
      nullsub_57(target);
      if ((entityData->protectionStatus != PROTECTION_STATUS_COUNTER) && (entityData->protectionStatus != PROTECTION_STATUS_MINI_COUNTER)) {
        entityData->protectionStatusTurnsLeft =  CalculateStatusTurns(target,gUnknown_80F4E98, FALSE) + 1;
      }
      entityData->protectionStatus = newStatus;
      sub_80522F4(pokemon,target,*gUnknown_80FB0E0);
      DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void SafeguardStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_SAFEGUARD) {
      entityData->protectionStatus = PROTECTION_STATUS_SAFEGUARD;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4E88, FALSE) + 1;
      nullsub_58(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB048);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB074);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void MistStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_MIST) {
      entityData->protectionStatus = PROTECTION_STATUS_MIST;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4E8C, FALSE) + 1;
      nullsub_59(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB09C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB0C4);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void WishStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_WISH) {
      entityData->protectionStatus = PROTECTION_STATUS_WISH;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4EB4, FALSE) + 1;
      sub_8041B34(target);
      sub_80522F4(pokemon,target,*gUnknown_80FAE1C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FAE3C);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void MagicCoatStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_MAGIC_COAT) {
      entityData->protectionStatus = PROTECTION_STATUS_MAGIC_COAT;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4E90, FALSE) + 1;
      nullsub_60(target);
      sub_80522F4(pokemon,target,*gUnknown_80FAF5C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FAF8C);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void LightScreenStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_LIGHT_SCREEN) {
      entityData->protectionStatus = PROTECTION_STATUS_LIGHT_SCREEN;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4E84, FALSE) + 1;
      nullsub_61(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB130);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB160);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void ReflectStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_REFLECT) {
      entityData->protectionStatus = PROTECTION_STATUS_REFLECT;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4E80, FALSE) + 1;
      nullsub_62(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB17C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB1A8);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void ProtectStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    nullsub_63(target);
    entityData = target->entityData;
    if (entityData->protectionStatus != PROTECTION_STATUS_PROTECT) {
      entityData->protectionStatus = PROTECTION_STATUS_PROTECT;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4ED4, FALSE) + 1;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FB9B0);
    }
    else {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FB9D8);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void MirrorCoatStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_MIRROR_COAT) {
      entityData->protectionStatus = PROTECTION_STATUS_MIRROR_COAT;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4EE8, FALSE) + 1;
      nullsub_64(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBAC0);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBAE4);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void EndureStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_ENDURE) {
      entityData->protectionStatus = PROTECTION_STATUS_ENDURE;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4EF8, FALSE) + 1;
      nullsub_65(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBBF0);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBC14);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void MirrorMoveStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_MIRROR_MOVE) {
      entityData->protectionStatus = PROTECTION_STATUS_MIRROR_MOVE;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4F18, FALSE) + 1;
      nullsub_66(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBC38);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBC5C);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void Conversion2StatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;

    if(HasAbility(target, ABILITY_FORECAST))
        sub_80522F4(pokemon,target,*gPtrForecastPreventsConversion2Message);
    else
    {
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (entityData->protectionStatus != PROTECTION_STATUS_CONVERSION_2) {
            entityData->protectionStatus = PROTECTION_STATUS_CONVERSION_2;
            entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4F20, FALSE) + 1;
            nullsub_67(target);
            sub_80522F4(pokemon,target,*gUnknown_80FBC7C);
        }
        else {
            sub_80522F4(pokemon,target,*gUnknown_80FBCA4);
        }
        DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void VitalThrowStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityData->protectionStatus != PROTECTION_STATUS_VITAL_THROW) {
      entityData->protectionStatus = PROTECTION_STATUS_VITAL_THROW;
      entityData->protectionStatusTurnsLeft = CalculateStatusTurns(target, gUnknown_80F4F24, FALSE) + 1;
      nullsub_68(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBCC8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBCF0);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_8079E34(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 param_3)
{
  bool8 statChanged;
  struct DungeonEntityData *iVar3;
  s32 index;
  
  statChanged = FALSE;
  if (EntityExists(target)) {
    iVar3 = target->entityData;

    for(index = 0; index < 2; index++)
    {
      if (iVar3->attackStages[index] != DEFAULT_STAT_STAGE) {
        iVar3->attackStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (iVar3->defenseStages[index] != DEFAULT_STAT_STAGE) {
        iVar3->defenseStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (iVar3->accuracyStages[index] != DEFAULT_STAT_STAGE) {
        iVar3->accuracyStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (iVar3->attackMultipliers[index] != DEFAULT_STAT_MULTIPLIER) {
        iVar3->attackMultipliers[index] = DEFAULT_STAT_MULTIPLIER;
        statChanged = TRUE;
      }
      if (iVar3->defenseMultipliers[index] != DEFAULT_STAT_MULTIPLIER) {
        iVar3->defenseMultipliers[index] = DEFAULT_STAT_MULTIPLIER;
        statChanged = TRUE;
      }
    }
    if (statChanged) {
      sub_80420C8(target);
    }
    else if (param_3 != 0) {
      sub_80420C8(target);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (statChanged) {
      sub_80522F4(pokemon,target,*gUnknown_80FBD18);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBD3C);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_8079F20(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, u8 param_4)
{
  bool8 moveUnsealed; // r9
  s32 moveSpeed;
  struct PokemonMove *move;
  struct DungeonEntityData *entityData; // r7
  bool8 bVar8; // r8
  s32 index;
  
  bVar8 = FALSE;
  moveUnsealed = FALSE;
  if (EntityExists(target)) {
    entityData = target->entityData;
    if (HasNegativeStatus(target)) {
      bVar8 = TRUE;
      SendSleepEndMessage(pokemon,target,0,0);
      if (!EntityExists(target)) {
        return;
      }
      SendNonVolatileEndMessage(pokemon,target);
      SendImmobilizeEndMessage(pokemon,target);
      SendVolatileEndMessage(pokemon,target);
      SendWaitingEndMessage(pokemon,target,0);
      SendLinkedEndMessage(pokemon,target);
      SendMoveEndMessage(pokemon,target);
      SendEyesightEndMessage(pokemon,target);
      SendMuzzledEndMessage(pokemon,target);
      if (entityData->perishSongTimer != 0) {
        entityData->perishSongTimer = 0;
        sub_80522F4(pokemon,target,*gUnknown_8100594);
      }
      if (entityData->exposedStatus) {
        entityData->exposedStatus = FALSE;
        sub_80522F4(pokemon,target,*gPtrExposedWoreOffMessage);
      }
    }

    moveSpeed = GetMovementSpeed(target);
    for(index = 0; index < NUM_SPEED_TURN_COUNTERS; index++)
    {
      entityData->slowTurnsLeft[index] = 0;
    }

    if (moveSpeed != GetMovementSpeed(target)) {
      bVar8 = TRUE;
      sub_80522F4(pokemon,target,gUnknown_80FA124[entityData->movementSpeed]);
    }

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &entityData->moves[index];
        if ((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags2 & MOVE_FLAG_EXISTS)) {
            bVar8 = TRUE;
            moveUnsealed = TRUE;
            move->moveFlags2 &= 0xfe;
        }
    }

    if (bVar8) {
      if (param_3 != 0) {
        sub_80420C8(target);
      }
      if (moveUnsealed) {
        sub_80522F4(pokemon,target,*gPtrSealedMoveReleasedMessage);
      }
    }
    else if (param_4 == 0) {
      sub_80522F4(pokemon,target,*gUnknown_81004E8);
    }
    DungeonEntityUpdateStatusSprites(target);
  }
}

void sub_807A0CC(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct PokemonMove *move;
  struct DungeonEntityData *entityData;
  s32 index;

  if (EntityExists(target)) {
    entityData = target->entityData;
    sub_806BFC0(entityData,0);
    entityData->perishSongTimer = 0;
    entityData->exposedStatus = FALSE;

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &entityData->moves[index];
        if ((move->moveFlags & MOVE_FLAG_EXISTS) != 0) {
            move->moveFlags2 = move->moveFlags2 & 0xfe;
        }
    }
    DungeonEntityUpdateStatusSprites(target);
  };
}

void SendSleepEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 param_3, bool8 param_4)
{
  struct DungeonEntityData *entityData;
  bool8 bVar4;
  
  bVar4 = FALSE;
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->sleepStatus) {
        case SLEEP_STATUS_NONE:
        case 6:
            break;
        case SLEEP_STATUS_SLEEP:
            bVar4 = TRUE;
            sub_80522F4(pokemon,target,*gUnknown_80FA6E8);
            break;
        case SLEEP_STATUS_SLEEPLESS:
            sub_80522F4(pokemon,target,*gUnknown_80FA708);
            break;
        case SLEEP_STATUS_NIGHTMARE:
            bVar4 = TRUE;
            sub_80522F4(pokemon,target,*gUnknown_80FA70C);
            if (param_4) {
                sub_806F324(target,gUnknown_80F4F78,8,0x20f);
            }
            break;
        case SLEEP_STATUS_NAPPING:
            bVar4 = TRUE;
            sub_80522F4(pokemon,target,*gUnknown_80FA710);
            HealTargetHP(pokemon,target,gUnknown_80F4F7A,0,0);
            entityData->sleepStatus = 0;
            sub_8079F20(pokemon,target,1,1);
            break;
        case SLEEP_STATUS_YAWNING:
            if (param_3) {
                entityData->sleepStatus = SLEEP_STATUS_NONE;
                sub_8075C58(pokemon,target,CalculateStatusTurns(target, gUnknown_80F4F2C, TRUE) + 1, 1);
                return;
            }
            sub_80522F4(pokemon,target,*gUnknown_80FA734);
            break;
  }
  entityData->sleepStatus = SLEEP_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
  if (bVar4) {
    sub_806CE68(target,8);
  }
}

void SendNonVolatileEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->nonVolatileStatus) {
    case NON_VOLATILE_STATUS_NONE:
    case 5:
        break;
    case NON_VOLATILE_STATUS_POISONED:
    case NON_VOLATILE_STATUS_BADLY_POISONED:
        sub_80522F4(pokemon,target,*gUnknown_80FA8A8);
        break;
    case NON_VOLATILE_STATUS_PARALYZED:
        sub_80522F4(pokemon,target,*gUnknown_80FA868);
        break;
    case NON_VOLATILE_STATUS_BURNED:
        sub_80522F4(pokemon,target,*gUnknown_80FA888);
        break;

  }
  entityData->nonVolatileStatus = NON_VOLATILE_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
}

void SendImmobilizeEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
  bool8 bVar1;
  struct DungeonEntityData *entityData;
  
  bVar1 = FALSE;
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->immobilizeStatus) {
    case IMMOBILIZE_STATUS_NONE:
    case 8:
        break;
    case IMMOBILIZE_STATUS_FROZEN:
        sub_80522F4(pokemon,target,*gUnknown_80FA8BC);
        bVar1 = TRUE;
        break;
    case IMMOBILIZE_STATUS_SQUEEZED:
        sub_80522F4(pokemon,target,*gUnknown_80FA820);
        break;
    case IMMOBILIZE_STATUS_IMMOBILIZED:
    case IMMOBILIZE_STATUS_INGRAIN:
        sub_80522F4(pokemon,target,*gUnknown_80FA824);
        break;
    case IMMOBILIZE_STATUS_WRAPPED_AROUND_FOE:
    case IMMOBILIZE_STATUS_WRAPPED_BY_FOE:
        sub_80522F4(pokemon,target,*gUnknown_80FA81C);
        sub_8076CB4(entityData->unk9C);
        break;
    case IMMOBILIZE_STATUS_PETRIFIED:
        sub_80522F4(pokemon,target,*gUnknown_80FABF8);
        break;
  }
  entityData->immobilizeStatus = IMMOBILIZE_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
  if (bVar1) {
    sub_8042A74(target);
  }
}

void SendVolatileEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->volatileStatus) {
    case VOLATILE_STATUS_NONE:
    case 8:
        break;
    case VOLATILE_STATUS_CONFUSED:
        sub_80522F4(pokemon,target,*gUnknown_80FA800);
        break;
    case VOLATILE_STATUS_COWERING:
        sub_80522F4(pokemon,target,*gUnknown_80FA97C);
        break;
    case VOLATILE_STATUS_TAUNTED:
        sub_80522F4(pokemon,target,*gUnknown_80FA9DC);
        break;
    case VOLATILE_STATUS_PAUSED:
        sub_80522F4(pokemon,target,*gUnknown_80FAC38);
        break;
    case VOLATILE_STATUS_INFATUATED:
        sub_80522F4(pokemon,target,*gUnknown_80FAB90);
        break;
    case VOLATILE_STATUS_ENCORE:
        sub_80522F4(pokemon,target,*gUnknown_80FAAAC);
        break;
    case VOLATILE_STATUS_CRINGING:
        sub_80522F4(pokemon,target,*gUnknown_80FAC18);
        break;
  }
  entityData->volatileStatus = VOLATILE_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
  GetMovementSpeed(target);
}

void SendProtectionEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->protectionStatus) {
    case PROTECTION_STATUS_NONE:
    case 0xF:
        break;
    case PROTECTION_STATUS_REFLECT:
        SendMessage(target,*gUnknown_80FA638);
        break;
    case PROTECTION_STATUS_SAFEGUARD:
        SendMessage(target,*gUnknown_80FA69C);
        break;
    case PROTECTION_STATUS_LIGHT_SCREEN:
        SendMessage(target,*gUnknown_80FA658);
        break;
    case PROTECTION_STATUS_COUNTER:
    case PROTECTION_STATUS_MINI_COUNTER:
        SendMessage(target,*gUnknown_80FA67C);
        break;
    case PROTECTION_STATUS_MAGIC_COAT:
        SendMessage(target,*gUnknown_80FA6BC);
        break;
    case PROTECTION_STATUS_WISH:
        SendMessage(target,*gUnknown_80FA6D4);
        break;
    case PROTECTION_STATUS_PROTECT:
        SendMessage(target,*gUnknown_80FA9C0);
        break;
    case PROTECTION_STATUS_MIRROR_COAT:
        SendMessage(target,*gUnknown_80FAA68);
        break;
    case PROTECTION_STATUS_ENDURE:
        SendMessage(target,*gUnknown_80FAAC8);
        break;
    case PROTECTION_STATUS_MIRROR_MOVE:
        SendMessage(target,*gUnknown_80FAAE8);
        break;
    case PROTECTION_STATUS_CONVERSION_2:
        SendMessage(target,*gUnknown_80FAB08);
        break;
    case PROTECTION_STATUS_VITAL_THROW:
        SendMessage(target,*gUnknown_80FAB28);
        break;
    case PROTECTION_STATUS_MIST:
        SendMessage(target,*gUnknown_80FAB40);
        break;
  }
  entityData->protectionStatus = PROTECTION_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
}

void SendWaitingEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 waitingStatus)
{
  u32 uVar3;
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    switch(entityData->waitingStatus) {
        case WAITING_STATUS_NONE:
        case 4:
            break;
        case WAITING_STATUS_CURSED:
            if (waitingStatus != WAITING_STATUS_CURSED) {
                SendMessage(target,*gUnknown_80FA7BC);
            }
            break;
        case WAITING_STATUS_SNATCH:
            if (waitingStatus != WAITING_STATUS_SNATCH) {
                SendMessage(target,*gUnknown_80FA7DC);
            }
            gDungeonGlobalData->snatchPokemon = NULL;
            gDungeonGlobalData->unk17B3C = 0;
            break;
        case WAITING_STATUS_DECOY:
            entityData->waitingStatus = WAITING_STATUS_NONE;
            uVar3 = sub_806CEBC(target);
            sub_806CCB4(target,uVar3);
            gDungeonGlobalData->decoyActive = FALSE;
            if (waitingStatus != WAITING_STATUS_DECOY) {
                SetMessageArgument(gAvailablePokemonNames,target,0);
                SendMessage(target,*gUnknown_80FA9A0);
            }
            break;
    }
    entityData->waitingStatus = WAITING_STATUS_NONE;
    DungeonEntityUpdateStatusSprites(target);
  }
}

void SendLinkedEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (EntityExists(target)) {
    entityData = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    switch(entityData->linkedStatus)
    {
        case LINKED_STATUS_NONE:
            break;
        case LINKED_STATUS_LEECH_SEED:
            SendMessage(target,*gUnknown_80FA79C);
            break;
        case LINKED_STATUS_DESTINY_BOND:
            SendMessage(target,*gUnknown_80FAA8C);
            break;
    }
    entityData->linkedStatus = LINKED_STATUS_NONE;
    entityData->unkD8 = 0xff;
    DungeonEntityUpdateStatusSprites(target);
  }
}

void SendMoveEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData * entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->moveStatus) {
        case MOVE_STATUS_NONE:
        case 5:
            break;
        case MOVE_STATUS_SURE_SHOT:
            SendMessage(target,*gUnknown_80FA8E0);
            break;
        case MOVE_STATUS_WHIFFER:
            SendMessage(target,*gUnknown_80FA90C);
            break;
        case MOVE_STATUS_SET_DAMAGE:
            SendMessage(target,*gUnknown_80FA934);
            break;
        case MOVE_STATUS_FOCUS_ENERGY:
            SendMessage(target,*gUnknown_80FA95C);
            break;
  }
  entityData->moveStatus = MOVE_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
}

void SendTransformEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target)
{
  bool8 isInvisible;
  struct DungeonEntityData *entityData;
  u32 uVar3;
  
  isInvisible = FALSE;
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->transformStatus) {
        case TRANSFORM_STATUS_NONE:
        case 4:
            break;
        case TRANSFORM_STATUS_INVISIBLE:
            isInvisible = TRUE;
            SendMessage(target,*gUnknown_80FA9F4);
            break;
        case TRANSFORM_STATUS_MOBILE:
            SendMessage(target,*gUnknown_80FABBC);
            break;
        case TRANSFORM_STATUS_TRANSFORMED:
            entityData->transformSpecies = sub_8069F54(target, entityData->entityID);
            target->unk64 = sub_80687D0(entityData->transformSpecies);
            uVar3 = sub_806CEBC(target);
            sub_806CCB4(target,uVar3);
            SendMessage(target,*gUnknown_80FAB6C);
            break;
  }
  entityData->transformStatus = TRANSFORM_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
  if (isInvisible) {
    sub_807EC28(1);
  }
}

void SendEyesightEndMessage(struct DungeonEntity * pokemon,struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->eyesightStatus) {
        case EYESIGHT_STATUS_NONE:
        case 4:
            break;
        case EYESIGHT_STATUS_BLINKER:
            SendMessage(target,*gUnknown_80FAA0C);
            break;
        case EYESIGHT_STATUS_CROSS_EYED:
            SendMessage(target,*gUnknown_80FAA2C);
            break;
        case EYESIGHT_STATUS_EYEDROPS:
            SendMessage(target,*gUnknown_80FAA48);
            break;
  }
  entityData->eyesightStatus = EYESIGHT_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
  if (entityData->isLeader) {
    sub_803E46C(0x31);
    sub_8049ED4();
    sub_8040A84();
  }
}

void SendMuzzledEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target)
{
  struct DungeonEntityData *entityData;
  
  if (!EntityExists(target)) {
    return;
  }
  entityData = target->entityData;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityData->muzzledStatus) {
    case MUZZLED_STATUS_NONE:
    case 2:
        break;
    case MUZZLED_STATUS_MUZZLED:
        SendMessage(target,*gUnknown_80FABC0);
        break;
  }
  entityData->muzzledStatus = MUZZLED_STATUS_NONE;
  DungeonEntityUpdateStatusSprites(target);
}

// TODO: this involves a union for sleepStatus/sleepStatusTurnsLeft that I don't want to deal with right now
/*
    bool32 sub_807A96C(struct DungeonEntity * pokemon, struct DungeonEntity * target)
    {
      struct DungeonEntityData *entityData;
      struct DungeonEntityData *entityData_1;
      register bool32 bVar3 asm("r2");
      
      entityData = target->entityData;
      entityData_1 = entityData;
      bVar3 = FALSE;
      if (entityData->immobilizeStatus == 6) {
        SendImmobilizeEndMessage(pokemon, target);
        bVar3 = TRUE;
      }
      TODO: this is where the union is needed..
      if ((entityData_1 + 0xa8) == 0x7f01) {
        SendSleepEndMessage(pokemon,target,0,1);
        bVar3 = TRUE;
      }
      return bVar3;
    } 
*/
NAKED
void sub_807A96C(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
    asm_unified(
	"\tpush {r4-r6,lr}\n"
	"\tadds r6, r0, 0\n"
	"\tadds r4, r1, 0\n"
	"\tldr r0, [r4, 0x70]\n"
	"\tadds r5, r0, 0\n"
	"\tmovs r2, 0\n"
	"\tadds r0, 0xB0\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0x6\n"
	"\tbne _0807A988\n"
	"\tadds r0, r6, 0\n"
	"\tbl SendImmobilizeEndMessage\n"
	"\tmovs r2, 0x1\n"
"_0807A988:\n"
	"\tadds r0, r5, 0\n"
	"\tadds r0, 0xA8\n"
	"\tldrh r1, [r0]\n"
	"\tldr r0, _0807A9AC\n"
	"\tcmp r1, r0\n"
	"\tbne _0807A9A2\n"
	"\tadds r0, r6, 0\n"
	"\tadds r1, r4, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
	"\tbl SendSleepEndMessage\n"
	"\tmovs r2, 0x1\n"
"_0807A9A2:\n"
	"\tadds r0, r2, 0\n"
	"\tpop {r4-r6}\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_0807A9AC: .4byte 0x00007f01");
}

void sub_807A9B0(struct DungeonEntity * pokemon)
{
  struct DungeonEntityData *entityData;
  
  entityData = pokemon->entityData;
  entityData->sleepStatus = SLEEP_STATUS_NONE;
  entityData->sleepStatusTurnsLeft = 0;
  sub_806A898(pokemon, 1, 1);
  DungeonEntityUpdateStatusSprites(pokemon);
}

void SendThawedMessage(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *iVar2;
  
  if (EntityExists(target)) {
    iVar2 = target->entityData;
    if (iVar2->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN) {
      iVar2->immobilizeStatus = IMMOBILIZE_STATUS_NONE;
      iVar2->immobilizeStatusTurnsLeft = 0;
      iVar2->immobilizeStatusDamageTimer = 0;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FA8BC); // $m0 thawed out!
      DungeonEntityUpdateStatusSprites(target);
    }
  }
}

void sub_807AA30(void)
{
  bool32 adjacentCheck;
  bool32 forceWakeup;
  u8 roomIndex;
  s32 xDiff;
  s32 wildIndex;
  s32 yDiff;
  struct DungeonEntity *teamEntity;
  struct DungeonEntity *wildEntity;
  struct DungeonEntityData *entityData;
  s32 teamIndex;
  
  for(wildIndex = 0; wildIndex < DUNGEON_MAX_WILD_POKEMON; wildIndex++)
  {
    wildEntity = gDungeonGlobalData->wildPokemon[wildIndex];
    if (EntityExists(wildEntity) && 
        (entityData = wildEntity->entityData, entityData->sleepStatus == SLEEP_STATUS_SLEEP) &&
        (entityData->sleepStatusTurnsLeft == 0x7F)) {
      adjacentCheck = FALSE;
      forceWakeup = FALSE;
      roomIndex = GetEntityRoomIndex(wildEntity);

      for(teamIndex = 0; teamIndex < MAX_TEAM_MEMBERS; teamIndex++)
      {
        teamEntity = gDungeonGlobalData->teamPokemon[teamIndex];
        if (EntityExists(teamEntity) && !HasItem(teamEntity, ITEM_ID_SNEAK_SCARF)) {
          xDiff = teamEntity->posWorld.x - wildEntity->posWorld.x;
          if (xDiff < 0) {
            xDiff = -xDiff;
          }
          if (xDiff < 2) {
            yDiff = teamEntity->posWorld.y- wildEntity->posWorld.y;
            if (yDiff < 0) {
              yDiff = -yDiff;
            }
            if (yDiff < 2) {
              adjacentCheck = TRUE;
              break;
            }
          }
          if (HasItem(teamEntity, ITEM_ID_RACKET_BAND) && (roomIndex == GetEntityRoomIndex(teamEntity)))
            goto _WakeUp;
        }
      }

      if(forceWakeup)
        goto _WakeUp;
      else if(adjacentCheck)
        forceWakeup = TRUE;

      if (forceWakeup) {
_WakeUp:
        sub_807A9B0(wildEntity);
      }
    }
  }
}
