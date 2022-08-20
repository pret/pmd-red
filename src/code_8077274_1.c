#include "global.h"
#include "constants/item.h"
#include "constants/status.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_util.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "status_checks_1.h"

extern u8 gAvailablePokemonNames[0x58];
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

void sub_8079F20(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, u8 param_4)
{
  bool8 bVar1; // r9
  s32 moveSpeed;
  struct PokemonMove *move;
  struct DungeonEntityData *entityData; // r7
  bool8 bVar8; // r8
  s32 index;
  
  bVar8 = FALSE;
  bVar1 = FALSE;
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
      if (entityData->exposedStatus != 0) {
        entityData->exposedStatus = 0;
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
            bVar1 = TRUE;
            move->moveFlags2 &= 0xfe;
        }
    }

    if (bVar8) {
      if (param_3 != 0) {
        sub_80420C8(target);
      }
      if (bVar1) {
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
    entityData->exposedStatus = 0;

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
                sub_8075C58(pokemon,target,CalculateStatusTurns(target,gUnknown_80F4F2C,1) + 1,1);
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
            gDungeonGlobalData->unk17B30 = 0;
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
  struct DungeonEntityData *iVar3;
  
  if (EntityExists(target)) {
    iVar3 = target->entityData;
    SetMessageArgument(gAvailablePokemonNames,target,0);
    switch(iVar3->linkedStatus)
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
    iVar3->linkedStatus = LINKED_STATUS_NONE;
    iVar3->unkD8 = 0xff;
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
  bool8 bVar1;
  struct DungeonEntityData *entityData;
  u32 uVar3;
  
  bVar1 = FALSE;
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
            bVar1 = TRUE;
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
  if (bVar1) {
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

void sub_807A9D8(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  struct DungeonEntityData *iVar2;
  
  if (EntityExists(target)) {
    iVar2 = target->entityData;
    if (iVar2->immobilizeStatus == IMMOBILIZE_STATUS_FROZEN) {
      iVar2->immobilizeStatus = IMMOBILIZE_STATUS_NONE;
      iVar2->immobilizeStatusTurnsLeft = 0;
      iVar2->immobilizeStatusDamageTimer = 0;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FA8BC);
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
