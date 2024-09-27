#include "global.h"
#include "code_803E46C.h"
#include "code_8045A00.h"
#include "code_80521D0.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "constants/ability.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_items.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_effects_target.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_mid.h"
#include "status_checks_1.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"

extern u8 gAvailablePokemonNames[0x58];
extern u8 gUnknown_202DFE8[0x58];
extern u8 *gUnknown_80FA8BC[];
extern u8 *gUnknown_80FA824[];
extern u8 *gUnknown_80FA81C[];
extern u8 *gPtrMonNoLongerPetrifiedMessage[];
extern u8 *gUnknown_80FA820[];
extern u8 *gUnknown_80FA800[];
extern u8 *gUnknown_80FAC38[];
extern u8 *gUnknown_80FA97C[];
extern u8 *gUnknown_80FA9DC[];
extern u8 *gUnknown_80FAAAC[];
extern u8 *gUnknown_80FAB90[];
extern u8 *gPtrMonNoLongerCringingMessage[];
extern u8 *gUnknown_80FA638[];
extern u8 *gUnknown_80FA69C[];
extern u8 *gUnknown_80FA658[];
extern u8 *gUnknown_80FA67C[];
extern u8 *gUnknown_80FA6BC[];
extern u8 *gUnknown_80FA6D4[];
extern u8 *gUnknown_80FA9C0[];
extern u8 *gUnknown_80FAA68[];
extern u8 *gPtrMonStoppedEnduringMessage[];
extern u8 *gPtrMonMirrorMoveFadedMessage[];
extern u8 *gPtrMonConversion2FailedMessage[];
extern u8 *gPtrMonGaveUpVitalThrowMessage[];
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
extern void sub_80522F4(Entity *pokemon, Entity *r1, const char[]);
extern void EntityUpdateStatusSprites(Entity *);
extern void sub_8042A74(Entity *r0);
extern void sub_807EC28(bool8);
extern s32 sub_8069F54(Entity *param_1, s16 param_2);
extern void sub_806A898(Entity *, u32, u32);
extern void HealTargetHP(Entity *pokemon, Entity *r1, s16, s16, u32);
extern void DealDamageToEntity(Entity *, s16, u32, u32);
extern void sub_806BFC0(EntityInfo *, u32);
extern void sub_80420C8(Entity *r0);
extern void nullsub_68(Entity *);
extern void nullsub_67(Entity *);
extern void nullsub_66(Entity *);
extern void nullsub_65(Entity *);
extern void nullsub_64(Entity *);
extern void nullsub_63(Entity *);
extern void nullsub_62(Entity *);
extern void nullsub_61(Entity *);
extern void nullsub_60(Entity *);
extern void nullsub_59(Entity *);
extern void nullsub_58(Entity *);
extern void nullsub_57(Entity *);
extern void sub_8041B34(Entity *);
void sub_8041BD0(Entity *r0, u8 r1);
void sub_8041EB4(Entity *);
void sub_8041EA4(Entity *);
extern void sub_8041E84(Entity *);
extern void sub_8041E94(Entity *);
extern void sub_8041E74(Entity *);
extern void sub_8041E60(Entity *);
extern void sub_8041E4C(Entity *);
extern void sub_8041E3C(Entity *);
extern void sub_803F580(u32);
extern void sub_8041E1C(Entity *);
extern void nullsub_89(Entity *);
extern void nullsub_88(Entity *);
extern void nullsub_87(Entity *);
extern void nullsub_86(Entity *);
extern void sub_8041E0C(Entity *);
extern void sub_8041DD8(Entity *r0, s32 r1); // NOTE: is s16 in another file
extern s32 sub_803D870(void *, u32);
extern bool8 sub_806AA0C(s32, u32);
u32 ExtractSpeciesIndex(PokemonStruct1 **r0); // TODO: look more into this and fix it.

void MuzzleTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->muzzled.muzzled != TRUE) {
        entityInfo->muzzled.muzzled = TRUE;
        entityInfo->muzzled.muzzledTurns = CalculateStatusTurns(target,gUnknown_80F4F1C, TRUE) + 1;
        nullsub_86(target);
        sub_80522F4(pokemon, target, *gUnknown_80FBF68);
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FBF84);
    }
    EntityUpdateStatusSprites(target);
  }
}

void TransformStatusTarget(Entity * pokemon, Entity * target)
{
    s16 species;
    s32 iVar5;
    s32 apparentID;
    s16 apparentID_s16;
    s32 index;
    EntityInfo *entityInfo;
    OpenedFile *sprite;
    PokemonStruct1 *auStack544[128];

    if (!EntityExists(target))
        return;

    entityInfo = target->axObj.info;

    if (entityInfo->transformStatus.transformStatus == STATUS_TRANSFORMED)
        sub_80522F4(pokemon, target, *gUnknown_80FBF04);
    else {
        SetMessageArgument(gAvailablePokemonNames, target, 0);
        iVar5 = sub_803D870(auStack544, 0);

        if (iVar5 == 0)
            sub_80522F4(pokemon, target, *gUnknown_80FBEE4);
        else {
            sprite = NULL;

            for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
                species = ExtractSpeciesIndex(&auStack544[DungeonRandInt(iVar5) * 2]);
                apparentID_s16 = sub_8069F54(target, species);
                apparentID = apparentID_s16;

                if (apparentID != entityInfo->apparentID && sub_806AA0C(apparentID, 1)) {
                    sprite = GetSpriteData(apparentID);
                    if (sprite != NULL)
                        break;
                }
            }

            if (index == DUNGEON_MAX_POKEMON || sprite == NULL)
                sub_80522F4(pokemon, target, *gUnknown_80FBEE4);
            else {
                entityInfo->apparentID = apparentID;
                target->axObj.spriteFile = sprite;
                entityInfo->transformStatus.transformStatus = STATUS_TRANSFORMED;
                entityInfo->transformStatus.transformStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EFC, TRUE) + 1;
                sub_806CF98(target);
                nullsub_87(target);
                sub_806CCB4(target, sub_806CEBC(target));
                CopyCyanMonsterNametoBuffer(gUnknown_202DFE8, entityInfo->apparentID);
                sub_80522F4(pokemon, target, *gUnknown_80FBEC0);
                EntityUpdateStatusSprites(target);
            }
        }
    }
}

void MobileStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo_1;
  EntityInfo *entityInfo;


  if (EntityExists(target)) {
    entityInfo_1 = target->axObj.info;
    entityInfo = entityInfo_1;

    if (entityInfo->transformStatus.transformStatus == STATUS_TRANSFORMED) {
        SendTransformEndMessage(pokemon,target);
    }
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->transformStatus.transformStatus != STATUS_MOBILE) {
        entityInfo->transformStatus.transformStatus = STATUS_MOBILE;
        entityInfo->transformStatus.transformStatusTurns = CalculateStatusTurns(target,gUnknown_80F4F04, FALSE) + 1;
        nullsub_88(target);
        sub_80522F4(pokemon,target,*gUnknown_80FBF28);
    }
    else {
        sub_80522F4(pokemon,target,*gUnknown_80FBF50);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ExposeStatusTarget(Entity * pokemon, Entity * target, s16 param_3)
{
  EntityInfo *entityInfo;
  s32 param_3_s16;
  s32 param_3_s16_2;
  bool32 flag;
  bool32 flag2;

  param_3_s16 = param_3;
  param_3_s16_2 = param_3_s16;
  flag = FALSE;
  flag2 = FALSE;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon,target,TRUE))) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->hitChanceStages[1] > 10) {
      entityInfo->hitChanceStages[1] = 10;
      flag = TRUE;
    }
    if(flag)
    {
        sub_8041DD8(target,param_3_s16);
        sub_80522F4(pokemon,target,*gUnknown_80FC000);
        flag2 = TRUE;
    }
    if (entityInfo->exposed) {
        sub_80522F4(pokemon,target,*gUnknown_80FBFB8);
    }
    else
    {
      if (!flag2) {
        sub_8041DD8(target,param_3_s16_2);
      }
      if (!MonsterIsType(target, TYPE_GHOST)) {
        sub_80522F4(pokemon,target,*gUnknown_80FBFD8);
      }
      else {
        entityInfo->exposed = TRUE;
        sub_80522F4(pokemon,target,*gUnknown_80FBF9C);
      }
      EntityUpdateStatusSprites(target);
    }
  }
}

void IdentityItemHolders(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityInfo = target->axObj.info;
    if (!gDungeon->itemHoldersIdentified) {
        nullsub_89(target);
        gDungeon->itemHoldersIdentified = TRUE;
        EntityUpdateStatusSprites(target);
        sub_80522F4(pokemon,target,*gUnknown_80FC028);
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FC054);
    }
  }
}

void BlindTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if ((EntityExists(target)) && (!HasSafeguardStatus(pokemon, target, TRUE))) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->eyesightStatus.eyesightStatus != STATUS_BLINKER) {
        entityInfo->eyesightStatus.eyesightStatus = STATUS_BLINKER;
        entityInfo->eyesightStatus.eyesightStatusTurns = CalculateStatusTurns(target,gUnknown_80F4F08, TRUE) + 1;
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
    EntityUpdateStatusSprites(target);
  }
}

void CrossEyeVisionTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;


  if (EntityExists(target)) {
    if(!HasSafeguardStatus(pokemon, target, TRUE))
    {
        entityInfo = target->axObj.info;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (entityInfo->eyesightStatus.eyesightStatus != STATUS_CROSS_EYED) {
            sub_8041E1C(target);
            sub_80522F4(pokemon,target,*gUnknown_80FB834);
            entityInfo->eyesightStatus.eyesightStatus = STATUS_CROSS_EYED;
            entityInfo->eyesightStatus.eyesightStatusTurns = CalculateStatusTurns(target,gUnknown_80F4F0C, TRUE) + 1;
            sub_803F580(0x1);
            sub_8049ED4();
            sub_8040A84();
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FB85C);
        }
        EntityUpdateStatusSprites(target);
    }
  }
}

void RestoreVisionTarget(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;


  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->eyesightStatus.eyesightStatus != STATUS_EYEDROPS) {
        entityInfo->eyesightStatus.eyesightStatus = STATUS_EYEDROPS;
        entityInfo->eyesightStatus.eyesightStatusTurns = CalculateStatusTurns(target,gUnknown_80F4F10, FALSE) + 1;
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
    EntityUpdateStatusSprites(target);
  }
}

void RestorePPTarget(Entity * pokemon,Entity * target, s32 param_3)
{
  volatile s32 PP;
  volatile s32 basePP;
  Move *movePtr;
  Move *movePtr1;
  s32 index;
  bool8 PPChanged;
  EntityInfo *entityInfo;

  PPChanged = FALSE;
  if (EntityExists(target)) {
    entityInfo = target->axObj.info;

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
      movePtr = &entityInfo->moves[index];
      movePtr1 = movePtr;
      if ((movePtr->moveFlags & MOVE_FLAG_EXISTS)) {
        PP = movePtr->PP;
        basePP = GetMoveBasePP(movePtr1);
        if (PP < basePP) {
          PP += param_3;
          if (PP > basePP) {
            PP = basePP;
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
    EntityUpdateStatusSprites(target);
  }
}

void RaiseAtkStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityInfo = target->axObj.info;
    entityInfo1 = entityInfo;
    oldStat = entityInfo->atk;
    oldStat1 = oldStat;

    newStat = entityInfo->atk + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo1->atk = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E60(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC33C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC360);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RaiseSpAtkStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityInfo = target->axObj.info;
    entityInfo1 = entityInfo;
    oldStat = entityInfo->spAtk;
    oldStat1 = oldStat;

    newStat = entityInfo->spAtk + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo1->spAtk = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E74(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC388);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC3B4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RaiseDefStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityInfo = target->axObj.info;
    entityInfo1 = entityInfo;
    oldStat = entityInfo->def;
    oldStat1 = oldStat;

    newStat = entityInfo->def + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo1->def = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E84(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC3D8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC3FC);
    }
    EntityUpdateStatusSprites(target);
  }
}

void RaiseSpDefStatTarget(Entity * pokemon, Entity *target, s32 increment)
{
  u32 oldStat;
  u32 oldStat1;
  s32 newStat;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo1;

  if (EntityExists(target)) {
    SetMessageArgument(gAvailablePokemonNames,target,0);

    // NOTE: had to have duplicates to match..
    entityInfo = target->axObj.info;
    entityInfo1 = entityInfo;
    oldStat = entityInfo->spDef;
    oldStat1 = oldStat;

    newStat = entityInfo->spDef + increment;
    if (0xfe < newStat) {
      newStat = 0xff;
    }
    entityInfo1->spDef = newStat;
    if (oldStat1 < (u8)newStat) {
      sub_8041E94(target);
      sub_80522F4(pokemon,target,*gUnknown_80FC428);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FC454);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LongTossStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

    entityInfo = target->axObj.info;
    SetMessageArgument(gUnknown_202DFE8,target,0);
    if (entityInfo->itemStatus.itemStatus != STATUS_LONG_TOSS) {
      entityInfo->itemStatus.itemStatus = STATUS_LONG_TOSS;
      sub_8041EA4(target);
      sub_80522F4(pokemon,target,*gUnknown_80FD20C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FD22C);
    }
    EntityUpdateStatusSprites(target);
}

void PierceStatusTarget(Entity * pokemon, Entity * target)
{
    EntityInfo *entityInfo;

    entityInfo = target->axObj.info;
    SetMessageArgument(gUnknown_202DFE8,target,0);
    if (entityInfo->itemStatus.itemStatus != STATUS_PIERCE) {
      entityInfo->itemStatus.itemStatus = STATUS_PIERCE;
      sub_8041EB4(target);
      sub_80522F4(pokemon,target,*gUnknown_80FD254);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FD27C);
    }
    EntityUpdateStatusSprites(target);
}

void SetChargeStatusTarget(Entity *pokemon, Entity *target, u8 newStatus, Move *move, u8 *message)
{
  bool8 bVar2;
  Move *movePtr;
  s32 index;
  bool8 uVar5;
  s32 iVar7;
  s32 iVar8;
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if ((entityInfo->charging.chargingStatus == newStatus) && (newStatus == STATUS_ENRAGED)) {
      sub_80522F4(pokemon,target,*gUnknown_80FC074);
    }
    else {
      entityInfo->charging.chargingStatus = newStatus;

      for(index = 0; index < MAX_MON_MOVES; index++)
      {
        movePtr = &entityInfo->moves[index];
        if(movePtr == move)
        {
            entityInfo->charging.chargingStatusMoveIndex = index;
            break;
        }
      }
      entityInfo->unk14A = 1;

      uVar5 = FALSE;
      if ((u8)(newStatus - 7) < 2) {
        entityInfo->unkFF = 1;
        uVar5 = TRUE;
      }
      else if ((u8)(newStatus - 9) < 2) {
        entityInfo->unkFF = 2;
      }
      if (newStatus == STATUS_BIDE) {
        entityInfo->charging.chargingStatusTurns = CalculateStatusTurns(target,gUnknown_80F4E9C, FALSE) + 1;
        entityInfo->unkA0 = 0;
      }
      if (newStatus == STATUS_ENRAGED) {
        entityInfo->charging.chargingStatusTurns = CalculateStatusTurns(target,gUnknown_80F4EA0, FALSE) + 1;
      }
      sub_8041BD0(target,uVar5);
      sub_80522F4(pokemon,target,message);
      EntityUpdateStatusSprites(target);

      // TODO: this could probably be cleaner..
      for (index = 0, iVar8 = 0xc7ff; index < 400; index++) {
        bVar2 = TRUE;
        if (entityInfo->unkFF == 1)
            if(iVar7 = entityInfo->unk174, bVar2 = FALSE, iVar7 > iVar8) // unk174 -> u32 to s32
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

void sub_8079764(Entity * pokemon)
{
    EntityInfo *entityInfo;

    if (EntityExists(pokemon)) {
        entityInfo = pokemon->axObj.info;
        if ((entityInfo->charging.chargingStatus != STATUS_BIDE) && (entityInfo->charging.chargingStatus != STATUS_ENRAGED)) {
            entityInfo->charging.chargingStatus = STATUS_NONE;
            entityInfo->unk14A = 0;
            entityInfo->unkFF = 0;
        }
        EntityUpdateStatusSprites(pokemon);
    }
}

void CounterStatusTarget(Entity * pokemon, Entity * target, u8 newStatus)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus == newStatus) {
      sub_80522F4(pokemon,target,*gUnknown_80FB10C);
    }
    else {
      nullsub_57(target);
      if ((entityInfo->protection.protectionStatus != STATUS_COUNTER) && (entityInfo->protection.protectionStatus != STATUS_MINI_COUNTER)) {
        entityInfo->protection.protectionStatusTurns =  CalculateStatusTurns(target,gUnknown_80F4E98, FALSE) + 1;
      }
      entityInfo->protection.protectionStatus = newStatus;
      sub_80522F4(pokemon,target,*gUnknown_80FB0E0);
      EntityUpdateStatusSprites(target);
    }
  }
}

void SafeguardStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_SAFEGUARD) {
      entityInfo->protection.protectionStatus = STATUS_SAFEGUARD;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E88, FALSE) + 1;
      nullsub_58(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB048);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB074);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MistStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_MIST) {
      entityInfo->protection.protectionStatus = STATUS_MIST;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E8C, FALSE) + 1;
      nullsub_59(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB09C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB0C4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void WishStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_WISH) {
      entityInfo->protection.protectionStatus = STATUS_WISH;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EB4, FALSE) + 1;
      sub_8041B34(target);
      sub_80522F4(pokemon,target,*gUnknown_80FAE1C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FAE3C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MagicCoatStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_MAGIC_COAT) {
      entityInfo->protection.protectionStatus = STATUS_MAGIC_COAT;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E90, FALSE) + 1;
      nullsub_60(target);
      sub_80522F4(pokemon,target,*gUnknown_80FAF5C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FAF8C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void LightScreenStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_LIGHT_SCREEN) {
      entityInfo->protection.protectionStatus = STATUS_LIGHT_SCREEN;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E84, FALSE) + 1;
      nullsub_61(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB130);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB160);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ReflectStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_REFLECT) {
      entityInfo->protection.protectionStatus = STATUS_REFLECT;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4E80, FALSE) + 1;
      nullsub_62(target);
      sub_80522F4(pokemon,target,*gUnknown_80FB17C);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FB1A8);
    }
    EntityUpdateStatusSprites(target);
  }
}

void ProtectStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    nullsub_63(target);
    entityInfo = target->axObj.info;
    if (entityInfo->protection.protectionStatus != STATUS_PROTECT) {
      entityInfo->protection.protectionStatus = STATUS_PROTECT;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4ED4, FALSE) + 1;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FB9B0);
    }
    else {
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FB9D8);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MirrorCoatStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_MIRROR_COAT) {
      entityInfo->protection.protectionStatus = STATUS_MIRROR_COAT;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EE8, FALSE) + 1;
      nullsub_64(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBAC0);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBAE4);
    }
    EntityUpdateStatusSprites(target);
  }
}

void EndureStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_ENDURING) {
      entityInfo->protection.protectionStatus = STATUS_ENDURING;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4EF8, FALSE) + 1;
      nullsub_65(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBBF0);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBC14);
    }
    EntityUpdateStatusSprites(target);
  }
}

void MirrorMoveStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_MIRROR_MOVE) {
      entityInfo->protection.protectionStatus = STATUS_MIRROR_MOVE;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4F18, FALSE) + 1;
      nullsub_66(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBC38);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBC5C);
    }
    EntityUpdateStatusSprites(target);
  }
}

void Conversion2StatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;

    if(HasAbility(target, ABILITY_FORECAST))
        sub_80522F4(pokemon,target,*gPtrForecastPreventsConversion2Message);
    else
    {
        SetMessageArgument(gAvailablePokemonNames,target,0);
        if (entityInfo->protection.protectionStatus != STATUS_CONVERSION2) {
            entityInfo->protection.protectionStatus = STATUS_CONVERSION2;
            entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4F20, FALSE) + 1;
            nullsub_67(target);
            sub_80522F4(pokemon,target,*gUnknown_80FBC7C);
        }
        else {
            sub_80522F4(pokemon,target,*gUnknown_80FBCA4);
        }
        EntityUpdateStatusSprites(target);
    }
  }
}

void VitalThrowStatusTarget(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    if (entityInfo->protection.protectionStatus != STATUS_VITAL_THROW) {
      entityInfo->protection.protectionStatus = STATUS_VITAL_THROW;
      entityInfo->protection.protectionStatusTurns = CalculateStatusTurns(target, gUnknown_80F4F24, FALSE) + 1;
      nullsub_68(target);
      sub_80522F4(pokemon,target,*gUnknown_80FBCC8);
    }
    else {
      sub_80522F4(pokemon,target,*gUnknown_80FBCF0);
    }
    EntityUpdateStatusSprites(target);
  }
}

void sub_8079E34(Entity * pokemon, Entity * target, bool8 param_3)
{
  bool8 statChanged;
  EntityInfo *entityInfo;
  s32 index;

  statChanged = FALSE;
  if (EntityExists(target)) {
    entityInfo = target->axObj.info;

    for(index = 0; index < 2; index++)
    {
      if (entityInfo->offensiveStages[index] != DEFAULT_STAT_STAGE) {
        entityInfo->offensiveStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (entityInfo->defensiveStages[index] != DEFAULT_STAT_STAGE) {
        entityInfo->defensiveStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (entityInfo->hitChanceStages[index] != DEFAULT_STAT_STAGE) {
        entityInfo->hitChanceStages[index] = DEFAULT_STAT_STAGE;
        statChanged = TRUE;
      }
      if (entityInfo->offensiveMultipliers[index] != DEFAULT_STAT_MULTIPLIER) {
        entityInfo->offensiveMultipliers[index] = DEFAULT_STAT_MULTIPLIER;
        statChanged = TRUE;
      }
      if (entityInfo->defensiveMultipliers[index] != DEFAULT_STAT_MULTIPLIER) {
        entityInfo->defensiveMultipliers[index] = DEFAULT_STAT_MULTIPLIER;
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
    EntityUpdateStatusSprites(target);
  }
}

void sub_8079F20(Entity * pokemon, Entity * target, u8 param_3, u8 param_4)
{
  bool8 moveUnsealed; // r9
  s32 moveSpeed;
  Move *move;
  EntityInfo *entityInfo; // r7
  bool8 bVar8; // r8
  s32 index;

  bVar8 = FALSE;
  moveUnsealed = FALSE;
  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
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
      if (entityInfo->perishSongTurns != 0) {
        entityInfo->perishSongTurns = 0;
        sub_80522F4(pokemon,target,*gUnknown_8100594);
      }
      if (entityInfo->exposed) {
        entityInfo->exposed = FALSE;
        sub_80522F4(pokemon,target,*gPtrExposedWoreOffMessage);
      }
    }

    moveSpeed = CalcSpeedStage(target);
    for(index = 0; index < NUM_SPEED_COUNTERS; index++)
    {
      entityInfo->speedDownCounters[index] = 0;
    }

    if (moveSpeed != CalcSpeedStage(target)) {
      bVar8 = TRUE;
      sub_80522F4(pokemon,target,gUnknown_80FA124[entityInfo->speedStage]);
    }

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &entityInfo->moves[index];
        if ((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags2 & MOVE_FLAG_EXISTS)) {
            bVar8 = TRUE;
            moveUnsealed = TRUE;
            move->moveFlags2 &= ~(MOVE_FLAG_EXISTS);
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
    EntityUpdateStatusSprites(target);
  }
}

void sub_807A0CC(Entity * pokemon, Entity * target)
{
  Move *move;
  EntityInfo *entityInfo;
  s32 index;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    sub_806BFC0(entityInfo,0);
    entityInfo->perishSongTurns = 0;
    entityInfo->exposed = FALSE;

    for(index = 0; index < MAX_MON_MOVES; index++)
    {
        move = &entityInfo->moves[index];
        if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
            move->moveFlags2 &= ~(MOVE_FLAG_EXISTS);
        }
    }
    EntityUpdateStatusSprites(target);
  };
}

void SendSleepEndMessage(Entity * pokemon, Entity * target, bool8 param_3, bool8 param_4)
{
  EntityInfo *entityInfo;
  bool8 isAsleep;

  isAsleep = FALSE;
  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->sleep.sleep) {
        case STATUS_NONE:
        case 6:
            break;
        case STATUS_SLEEP:
            isAsleep = TRUE;
            sub_80522F4(pokemon,target,*gUnknown_80FA6E8);
            break;
        case STATUS_SLEEPLESS:
            sub_80522F4(pokemon,target,*gUnknown_80FA708);
            break;
        case STATUS_NIGHTMARE:
            isAsleep = TRUE;
            sub_80522F4(pokemon,target,*gUnknown_80FA70C);
            if (param_4) {
                DealDamageToEntity(target,gUnknown_80F4F78,8,0x20f);
            }
            break;
        case STATUS_NAPPING:
            isAsleep = TRUE;
            sub_80522F4(pokemon,target,*gUnknown_80FA710);
            HealTargetHP(pokemon,target,gUnknown_80F4F7A, 0, FALSE);
            entityInfo->sleep.sleep = 0;
            sub_8079F20(pokemon,target,1,1);
            break;
        case STATUS_YAWNING:
            if (param_3) {
                entityInfo->sleep.sleep = STATUS_NONE;
                sub_8075C58(pokemon,target,CalculateStatusTurns(target, gUnknown_80F4F2C, TRUE) + 1, TRUE);
                return;
            }
            sub_80522F4(pokemon,target,*gUnknown_80FA734);
            break;
  }
  entityInfo->sleep.sleep = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (isAsleep) {
    sub_806CE68(target,8);
  }
}

void SendNonVolatileEndMessage(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->nonVolatile.nonVolatileStatus) {
    case STATUS_NONE:
    case 5:
        break;
    case STATUS_POISONED:
    case STATUS_BADLY_POISONED:
        sub_80522F4(pokemon,target,*gUnknown_80FA8A8);
        break;
    case STATUS_PARALYSIS:
        sub_80522F4(pokemon,target,*gUnknown_80FA868);
        break;
    case STATUS_BURN:
        sub_80522F4(pokemon,target,*gUnknown_80FA888);
        break;

  }
  entityInfo->nonVolatile.nonVolatileStatus = STATUS_NONE;
  EntityUpdateStatusSprites(target);
}

void SendImmobilizeEndMessage(Entity * pokemon, Entity *target)
{
  bool8 isFrozen;
  EntityInfo *entityInfo;

  isFrozen = FALSE;
  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->immobilize.immobilizeStatus) {
    case STATUS_NONE:
    case 8:
        break;
    case STATUS_FROZEN:
        sub_80522F4(pokemon,target,*gUnknown_80FA8BC);
        isFrozen = TRUE;
        break;
    case STATUS_CONSTRICTION:
        sub_80522F4(pokemon,target,*gUnknown_80FA820);
        break;
    case STATUS_SHADOW_HOLD:
    case STATUS_INGRAIN:
        sub_80522F4(pokemon,target,*gUnknown_80FA824);
        break;
    case STATUS_WRAP:
    case STATUS_WRAPPED:
        sub_80522F4(pokemon,target,*gUnknown_80FA81C);
        sub_8076CB4(entityInfo->unk9C);
        break;
    case STATUS_PETRIFIED:
        sub_80522F4(pokemon,target, *gPtrMonNoLongerPetrifiedMessage);
        break;
  }
  entityInfo->immobilize.immobilizeStatus = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (isFrozen) {
    sub_8042A74(target);
  }
}

void SendVolatileEndMessage(Entity * pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->volatileStatus.volatileStatus) {
    case STATUS_NONE:
    case 8:
        break;
    case STATUS_CONFUSED:
        sub_80522F4(pokemon,target,*gUnknown_80FA800);
        break;
    case STATUS_COWERING:
        sub_80522F4(pokemon,target,*gUnknown_80FA97C);
        break;
    case STATUS_TAUNTED:
        sub_80522F4(pokemon,target,*gUnknown_80FA9DC);
        break;
    case STATUS_PAUSED:
        sub_80522F4(pokemon,target,*gUnknown_80FAC38);
        break;
    case STATUS_INFATUATED:
        sub_80522F4(pokemon,target,*gUnknown_80FAB90);
        break;
    case STATUS_ENCORE:
        sub_80522F4(pokemon,target,*gUnknown_80FAAAC);
        break;
    case STATUS_CRINGE:
        sub_80522F4(pokemon,target, *gPtrMonNoLongerCringingMessage);
        break;
  }
  entityInfo->volatileStatus.volatileStatus = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  CalcSpeedStage(target);
}

void SendProtectionEndMessage(Entity * pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->protection.protectionStatus) {
    case STATUS_NONE:
    case 0xF:
        break;
    case STATUS_REFLECT:
        SendMessage(target,*gUnknown_80FA638);
        break;
    case STATUS_SAFEGUARD:
        SendMessage(target,*gUnknown_80FA69C);
        break;
    case STATUS_LIGHT_SCREEN:
        SendMessage(target,*gUnknown_80FA658);
        break;
    case STATUS_COUNTER:
    case STATUS_MINI_COUNTER:
        SendMessage(target,*gUnknown_80FA67C);
        break;
    case STATUS_MAGIC_COAT:
        SendMessage(target,*gUnknown_80FA6BC);
        break;
    case STATUS_WISH:
        SendMessage(target,*gUnknown_80FA6D4);
        break;
    case STATUS_PROTECT:
        SendMessage(target,*gUnknown_80FA9C0);
        break;
    case STATUS_MIRROR_COAT:
        SendMessage(target,*gUnknown_80FAA68);
        break;
    case STATUS_ENDURING:
        SendMessage(target, *gPtrMonStoppedEnduringMessage);
        break;
    case STATUS_MIRROR_MOVE:
        SendMessage(target,*gPtrMonMirrorMoveFadedMessage);
        break;
    case STATUS_CONVERSION2:
        SendMessage(target, *gPtrMonConversion2FailedMessage);
        break;
    case STATUS_VITAL_THROW:
        SendMessage(target, *gPtrMonGaveUpVitalThrowMessage);
        break;
    case STATUS_MIST:
        SendMessage(target,*gUnknown_80FAB40);
        break;
  }
  entityInfo->protection.protectionStatus = STATUS_NONE;
  EntityUpdateStatusSprites(target);
}

void SendWaitingEndMessage(Entity * pokemon, Entity * target, u8 waitingStatus)
{
  u32 uVar3;
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    switch(entityInfo->waitingStruct.waitingStatus) {
        case STATUS_NONE:
        case 4:
            break;
        case STATUS_CURSED:
            if (waitingStatus != STATUS_CURSED) {
                SendMessage(target,*gUnknown_80FA7BC);
            }
            break;
        case STATUS_SNATCH:
            if (waitingStatus != STATUS_SNATCH) {
                SendMessage(target,*gUnknown_80FA7DC);
            }
            gDungeon->snatchPokemon = NULL;
            gDungeon->unk17B3C = 0;
            break;
        case STATUS_DECOY:
            entityInfo->waitingStruct.waitingStatus = STATUS_NONE;
            uVar3 = sub_806CEBC(target);
            sub_806CCB4(target,uVar3);
            gDungeon->decoyActive = FALSE;
            if (waitingStatus != STATUS_DECOY) {
                SetMessageArgument(gAvailablePokemonNames,target,0);
                SendMessage(target,*gUnknown_80FA9A0);
            }
            break;
    }
    entityInfo->waitingStruct.waitingStatus = STATUS_NONE;
    EntityUpdateStatusSprites(target);
  }
}

void SendLinkedEndMessage(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    switch(entityInfo->linked.linkedStatus)
    {
        case STATUS_NONE:
            break;
        case STATUS_LEECH_SEED:
            SendMessage(target,*gUnknown_80FA79C);
            break;
        case STATUS_DESTINY_BOND:
            SendMessage(target,*gUnknown_80FAA8C);
            break;
    }
    entityInfo->linked.linkedStatus = STATUS_NONE;
    entityInfo->linked.unkD8 = 0xff;
    EntityUpdateStatusSprites(target);
  }
}

void SendMoveEndMessage(Entity * pokemon, Entity * target)
{
  EntityInfo * entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->moveStatus.moveStatus) {
        case STATUS_NONE:
        case 5:
            break;
        case STATUS_SURE_SHOT:
            SendMessage(target,*gUnknown_80FA8E0);
            break;
        case STATUS_WHIFFER:
            SendMessage(target,*gUnknown_80FA90C);
            break;
        case STATUS_SET_DAMAGE:
            SendMessage(target,*gUnknown_80FA934);
            break;
        case STATUS_FOCUS_ENERGY:
            SendMessage(target,*gUnknown_80FA95C);
            break;
  }
  entityInfo->moveStatus.moveStatus = STATUS_NONE;
  EntityUpdateStatusSprites(target);
}

void SendTransformEndMessage(Entity * pokemon, Entity *target)
{
  bool8 isInvisible;
  EntityInfo *entityInfo;
  u32 uVar3;

  isInvisible = FALSE;
  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->transformStatus.transformStatus) {
        case STATUS_NONE:
        case 4:
            break;
        case STATUS_INVISIBLE:
            isInvisible = TRUE;
            SendMessage(target,*gUnknown_80FA9F4);
            break;
        case STATUS_MOBILE:
            SendMessage(target,*gUnknown_80FABBC);
            break;
        case STATUS_TRANSFORMED:
            entityInfo->apparentID = sub_8069F54(target, entityInfo->id);
            target->axObj.spriteFile = GetSpriteData(entityInfo->apparentID);
            uVar3 = sub_806CEBC(target);
            sub_806CCB4(target,uVar3);
            SendMessage(target,*gUnknown_80FAB6C);
            break;
  }
  entityInfo->transformStatus.transformStatus = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (isInvisible) {
    sub_807EC28(TRUE);
  }
}

void SendEyesightEndMessage(Entity * pokemon,Entity * target)
{
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->eyesightStatus.eyesightStatus) {
        case STATUS_NONE:
        case 4:
            break;
        case STATUS_BLINKER:
            SendMessage(target,*gUnknown_80FAA0C);
            break;
        case STATUS_CROSS_EYED:
            SendMessage(target,*gUnknown_80FAA2C);
            break;
        case STATUS_EYEDROPS:
            SendMessage(target,*gUnknown_80FAA48);
            break;
  }
  entityInfo->eyesightStatus.eyesightStatus = STATUS_NONE;
  EntityUpdateStatusSprites(target);
  if (entityInfo->isTeamLeader) {
    sub_803E46C(0x31);
    sub_8049ED4();
    sub_8040A84();
  }
}

void SendMuzzledEndMessage(Entity * pokemon, Entity * target)
{
  EntityInfo *entityInfo;

  if (!EntityExists(target)) {
    return;
  }
  entityInfo = target->axObj.info;
  SetMessageArgument(gAvailablePokemonNames,target,0);
  switch(entityInfo->muzzled.muzzled) {
    case FALSE:
    case 2:
        break;
    case TRUE:
        SendMessage(target,*gUnknown_80FABC0);
        break;
  }
  entityInfo->muzzled.muzzled = FALSE;
  EntityUpdateStatusSprites(target);
}

bool8 TrySendImmobilizeSleepEndMsg(Entity * pokemon, Entity * target)
{
    EntityInfo *entityInfo = GetEntInfo(target);
    bool32 msg = FALSE;

    if (entityInfo->immobilize.immobilizeStatus == STATUS_PETRIFIED) {
        SendImmobilizeEndMessage(pokemon, target);
        msg = TRUE;
    }
    if (entityInfo->sleep.sleep == STATUS_SLEEP && entityInfo->sleep.sleepTurns == 0x7f) {
        SendSleepEndMessage(pokemon,target, FALSE, TRUE);
        msg = TRUE;
    }
    return msg;
}

void WakeUpPokemon(Entity * pokemon)
{
  EntityInfo *entityInfo;

  entityInfo = pokemon->axObj.info;
  entityInfo->sleep.sleep = STATUS_NONE;
  entityInfo->sleep.sleepTurns = 0;
  sub_806A898(pokemon, 1, 1);
  EntityUpdateStatusSprites(pokemon);
}

void SendThawedMessage(Entity *pokemon, Entity *target)
{
  EntityInfo *entityInfo;

  if (EntityExists(target)) {
    entityInfo = target->axObj.info;
    if (entityInfo->immobilize.immobilizeStatus == STATUS_FROZEN) {
      entityInfo->immobilize.immobilizeStatus = STATUS_NONE;
      entityInfo->immobilize.immobilizeStatusTurns = 0;
      entityInfo->immobilize.immobilizeStatusDamageCountdown = 0;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FA8BC); // $m0 thawed out!
      EntityUpdateStatusSprites(target);
    }
  }
}

void sub_807AA30(void)
{
  bool32 adjacentCheck;
  bool32 forceWakeup;
  u8 room;
  s32 xDiff;
  s32 wildIndex;
  s32 yDiff;
  Entity *teamEntity;
  Entity *wildEntity;
  EntityInfo *entityInfo;
  s32 teamIndex;

  for(wildIndex = 0; wildIndex < DUNGEON_MAX_WILD_POKEMON; wildIndex++)
  {
    wildEntity = gDungeon->wildPokemon[wildIndex];
    if (EntityExists(wildEntity) &&
        (entityInfo = wildEntity->axObj.info, entityInfo->sleep.sleep == STATUS_SLEEP) &&
        (entityInfo->sleep.sleepTurns == 0x7F)) {
      adjacentCheck = FALSE;
      forceWakeup = FALSE;
      room = GetEntityRoom(wildEntity);

      for(teamIndex = 0; teamIndex < MAX_TEAM_MEMBERS; teamIndex++)
      {
        teamEntity = gDungeon->teamPokemon[teamIndex];
        if (EntityExists(teamEntity) && !HasHeldItem(teamEntity, ITEM_SNEAK_SCARF)) {
          xDiff = teamEntity->pos.x - wildEntity->pos.x;
          if (xDiff < 0) {
            xDiff = -xDiff;
          }
          if (xDiff < 2) {
            yDiff = teamEntity->pos.y- wildEntity->pos.y;
            if (yDiff < 0) {
              yDiff = -yDiff;
            }
            if (yDiff < 2) {
              adjacentCheck = TRUE;
              break;
            }
          }
          if (HasHeldItem(teamEntity, ITEM_RACKET_BAND) && (room == GetEntityRoom(teamEntity)))
            goto _WakeUp;
        }
      }

      if(forceWakeup)
        goto _WakeUp;
      else if(adjacentCheck)
        forceWakeup = TRUE;

      if (forceWakeup) {
_WakeUp:
        WakeUpPokemon(wildEntity);
      }
    }
  }
}
