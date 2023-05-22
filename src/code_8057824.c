#include "global.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "charge_move.h"
#include "dungeon_global_data.h"
#include "dungeon_entity.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "map.h"
#include "moves.h"
#include "move_effects_target.h"
#include "pokemon.h"
#include "status.h"
#include "status_checks_1.h"
#include "tile_types.h"
#include "weather.h"

typedef bool8 (*MoveCallback)(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4);
struct NaturePowerMove
{
    s16 moveID;
    u16 unk2;
    MoveCallback move;
};

struct NaturePowerMove gNaturePowerMoveTable[10];


extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DFE8[];

extern u8 *gUnknown_80FC888[];
extern u8 *gUnknown_80FC8C0[];
extern s16 gUnknown_80F4DEA;
extern u8 *gUnknown_80FEB88[];
extern s16 gUnknown_80F4DE8;
extern u8 *gUnknown_80FAD6C[];
extern s16 gUnknown_80F4DE4;
extern u8 *gUnknown_80FBD58[];
extern u32 gUnknown_80F51B4[];
extern s16 gUnknown_80F4DC0;
extern s16 gUnknown_80F4DF8;
extern s16 gUnknown_80F4DD0;
extern s16 gUnknown_80F4DBC;
extern u8 *gUnknown_80FACC4[];
extern s16 gUnknown_80F4DF4;
extern u32 gUnknown_80F4F4C;
extern s16 gUnknown_80F4EB8[];
extern u8 gUnknown_202F21A;
extern s16 gUnknown_80F500A[];
extern s16 gUnknown_80F4DD6;
extern u8 gUnknown_202F219;
extern u32 gUnknown_80F51A4[];
extern u8 *gUnknown_80FACA4[];
extern u32 gUnknown_80F4F54;
extern u8 *gUnknown_80FD104[];
extern s16 gUnknown_80F4DD4;
extern u32 gUnknown_80F4F6C;
extern u32 gUnknown_80F4DE6;
extern u32 gUnknown_80F4DEE;
extern u32 gUnknown_80F4DC2;
extern u8 *gUnknown_80FD294[];
extern u8 *gUnknown_80FD2B4[];
extern u8 *gUnknown_80FAC74[];
extern u8 *gUnknown_80FAC54[];
extern u32 gUnknown_80F4F50;
extern s16 gUnknown_80F4DB8; 
extern s16 gUnknown_80F4DBA; 
extern s16 gUnknown_80F55BC[];
extern u8 *gUnknown_80FAE00[];
extern u8 *gUnknown_80FADD8[];
extern s16 gUnknown_80F4E02;
extern s16 gUnknown_80F4E04;
extern s16 gUnknown_80F4DB6;
extern s16 gUnknown_80F4EDC[];
extern u16 gUnknown_80F4F42;
extern u8 *gUnknown_80FAC88;
extern u8 *gUnknown_80FD018[];
extern u8 *gUnknown_80FCFBC[];
extern u8 *gUnknown_80FCFE4[];
extern u32 gUnknown_8106A4C;
extern s16 gUnknown_80F4DF6;
extern s16 gUnknown_80F4E0A;
extern u8 gUnknown_80F51E4[];
extern u32 gUnknown_80F51EC[];
extern u8 *gUnknown_80FC734[];
extern u8 *gUnknown_80FC7EC[];
extern u8 *gUnknown_80FCF74[];
extern u8 *gUnknown_80FCF80[];
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4E08;
extern u8 *gUnknown_80FD14C[];
extern u8 *gUnknown_80FAD4C[];
extern u32 gUnknown_80F4F68;
extern s16 gUnknown_80F502A[];
extern s16 gUnknown_80F4E74[];
extern s16 gUnknown_80F4E78[];
extern s16 gUnknown_80F4F28[];
extern u32 gUnknown_202F21C;
extern bool8 gUnknown_202F220;
extern u32 gUnknown_8106A54[];

struct unkStruct_80928C0
{
    u32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

void sub_80928C0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *param_3);

extern void sub_806ABAC(struct Entity *, struct Entity *);
extern u8 sub_806F4A4(struct Entity *, u32);
extern void sub_807DF38(struct Entity *pokemon, struct Entity *target, struct Position *pos, u32, u8 moveType, s16);
extern void nullsub_92(struct Entity *);
extern u32 sub_8055864(struct Entity *pokemon, struct Entity *target, struct Move *param_3, s32 param_4, s32 param_5);
void sub_8079E34(struct Entity * pokemon, struct Entity * target, bool8 param_3);
extern u8 sub_807EAA0(u32, u32);
extern void sub_80522F4(struct Entity *r1, struct Entity *r2, const char[]);
extern s32 sub_80556BC(struct Entity *, struct Entity *, u8, struct Move *, u32, u32);
extern bool8 sub_805727C(struct Entity *, struct Entity *, s16);
extern void sub_806F370(struct Entity *r0, struct Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void SetMessageArgument(char[], struct Entity*, u32);
extern u32 sub_8055640(struct Entity *, struct Entity *, struct Move *, u32, u32);
u8 sub_8057620(u32 param_1);
extern s16 sub_8094828(u16, u8);
extern bool8 sub_8057308(struct Entity *, u32);
extern void sub_806F324(struct Entity *, s32, u32, u32);

extern s16 gUnknown_80F4DB4;
extern u32 gUnknown_8106A4C;

bool8 sub_805755C(struct Entity* pokemon, u16 moveID)
{
    if ((moveID == MOVE_SOLARBEAM) && (GetApparentWeather(pokemon) == WEATHER_SUNNY)) {
        return FALSE;
    }
    else {
        return DoesMoveCharge(moveID);
    }
}

void sub_8057588(struct Entity * pokemon, u8 param_2)
{
    struct Move *move;
    s32 index;
    s32 PPtoRemove;
    s32 PPCounter;
    struct EntityInfo *entityInfo;

    if (EntityExists(pokemon)) {
        entityInfo = pokemon->info;
        for(index = 0; index < MAX_MON_MOVES; index++)
        {
            move = &entityInfo->moves[index];
            if ((move->moveFlags & MOVE_FLAG_EXISTS)) {
                PPtoRemove = 1;
                if ((move->moveFlags2 & MOVE_FLAG_LAST_USED)) {
                    move->moveFlags2 &= ~(MOVE_FLAG_LAST_USED);
                    PPtoRemove = 2;
                }
                if (((move->moveFlags2 & MOVE_FLAG_SET)) && (move->moveFlags2 &= ~(MOVE_FLAG_SET), param_2 != 0))
                {
                    if(PPtoRemove != 0)
                    {
                        PPCounter = PPtoRemove;
                        for (; PPCounter != 0; PPCounter--) {
                            if (move->PP != 0) {
                                move->PP--;
                            }
                        }
                    }
                }
            }
        }
    }
}

s16 sub_8057600(struct Move *move, s32 itemID)
{
    return sub_8094828(move->id, sub_8057620(itemID));
}

u8 sub_8057620(u32 itemID)
{
    if(itemID == ITEM_NOTHING)
        return ITEM_NOTHING;
    else
        return itemID;
}

bool8 sub_8057634(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon, target, gUnknown_80F4DB4)) {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1, 1, FALSE);
        }
    }
    return flag;
}

bool8 sub_805768C(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;  
    gUnknown_202F21C++;

    if (sub_8055640(pokemon, target, move, gUnknown_8106A54[gUnknown_202F21C], param_4) == 0)
        gUnknown_202F220 = 1;
    else
        flag = TRUE;
    return flag;
}

bool8 YawnMoveAction(struct Entity * pokemon, struct Entity *target)
{
    YawnedStatusTarget(pokemon, target, CalculateStatusTurns(target,gUnknown_80F4F28,TRUE) + 1);
    return TRUE;
}

bool8 sub_80576F8(struct Entity * pokemon, struct Entity *target)
{
    sub_8075C58(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4E74, TRUE), TRUE);
    return TRUE;
}

bool8 NightmareMoveAction(struct Entity * pokemon, struct Entity *target)
{
    NightmareStatusTarget(pokemon, target, CalculateStatusTurns(target,gUnknown_80F4E78,TRUE));
    return TRUE;
}

bool8 sub_8057748(struct Entity * pokemon,struct Entity * target)
{
    HealTargetHP(pokemon, target, gUnknown_80F502A[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 VitalThrowMoveAction(struct Entity * pokemon, struct Entity * target)
{
    VitalThrowStatusTarget(pokemon, target);
    return TRUE;
}

bool8 DigMoveAction(struct Entity * pokemon, struct Entity * target, struct Move *move, s32 param_4)
{
    struct Tile *tile;
    bool8 flag;

    flag = FALSE;
    tile = GetTileAtEntitySafe(pokemon);
    if ((!IsTileGround(tile)) || ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != 1)) {
        sub_80522F4(pokemon,target,*gUnknown_80FD14C); // It can only be used on land!
    }
    else {
        if (MoveMatchesChargingStatus(pokemon,move)) {
            sub_8055640(pokemon,target,move,gUnknown_80F4F68,param_4);
            sub_8079764(pokemon);
        }
        else {
            SetChargeStatusTarget(pokemon,pokemon,STATUS_DIGGING,move,*gUnknown_80FAD4C); // $m0 burrowed underground!
        }
        flag = TRUE;
    }
    return flag;
}

bool32 sub_8057824(struct Entity *pokemon, struct Entity *target)
{
  LowerAccuracyStageTarget(pokemon,target,gUnknown_8106A50,TRUE);
  return TRUE;
}

bool32 sub_805783C(struct Entity *pokemon, struct Entity *target)
{
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A4C,0x80,TRUE);
  return TRUE;
}

bool32 sub_805785C(struct Entity *pokemon, struct Entity *target)
{
  gDungeon->unkE26B = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    sub_80522F4(pokemon,target,*gUnknown_80FCF74);
  }
  return TRUE;
}

bool32 sub_80578A4(struct Entity *pokemon, struct Entity *target)
{
  gDungeon->weatherTurns = gUnknown_80F4F42;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    sub_80522F4(pokemon,target,*gUnknown_80FCF80);
  }
  return TRUE;
}

bool32 sub_80578EC(struct Entity *pokemon, struct Entity *target)
{
    sub_8079F20(pokemon, target, 1, 0);
    return TRUE;
}

bool32 sub_80578FC(struct Entity *pokemon, struct Entity *target, struct Move * move, u32 param_4)
{
  bool32 flag;

  flag = FALSE;
  if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target, gUnknown_80F4DB6)) {
      LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool32 EncoreMoveAction(struct Entity *pokemon, struct Entity *target)
{
    EncoreStatusTarget(pokemon, target);
    return TRUE;
}

bool32 RageMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move)
{
  // {ARG_POKEMON_0} is enraged
  SetChargeStatusTarget(pokemon,target,STATUS_ENRAGED,move,gUnknown_80FAC88);
  return TRUE;
}

bool32 sub_8057974(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  s32 newHP;
  bool8 local_24;

  newHP = target->info->HP / 2;
  local_24 = FALSE;
  if (newHP != 0) {
    sub_806F370(pokemon,target,newHP,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = local_24 == 0;
  }
  else
  {
    // The target's HP can't be halved anymore
    sub_80522F4(pokemon,target,*gUnknown_80FD018);
  }
  return local_24;
}

bool8 PainSplitMoveAction(struct Entity *pokemon, struct Entity *target)
{
  s32 newHP;
  struct EntityInfo *iVar2;
  struct EntityInfo *iVar3;
  struct EntityInfo *iVar4;
  struct EntityInfo *iVar5;

  // Need copies for some reason to match..
  iVar3 = (pokemon->info);
  iVar4 = iVar3;
  iVar2 = (target->info);
  iVar5 = iVar2;

  newHP = ((iVar3->HP + iVar2->HP) / 2);
  iVar3->HP = newHP;
  iVar5->HP = newHP;
  if (iVar3->HP > iVar3->maxHPStat) {
    iVar3->HP = iVar3->maxHPStat;
  }
  if (iVar5->HP > iVar5->maxHPStat) {
    iVar5->HP = iVar5->maxHPStat;
  }
  SetMessageArgument(gAvailablePokemonNames,pokemon,0);
  SetMessageArgument(gAvailablePokemonNames + 0x50,target,0);
  if (iVar4->unkFB == 0) {
    iVar4->unkFB = 1;
  }
  // $m0 and $m1 shared their HP
  sub_80522F4(pokemon,target,*gUnknown_80FC7EC);
  return TRUE;
}

bool8 TormentMoveAction(struct Entity *pokemon, struct Entity *target)
{
  struct Move *movePtr;
  s32 iVar4;
  struct Move struggleMove;
  struct EntityInfo *entityInfo;
  bool8 isTormented;
  
  entityInfo = target->info;
  isTormented = FALSE;

  for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
  {
    movePtr = &entityInfo->moves[iVar4];
    if ((movePtr->moveFlags & MOVE_FLAG_EXISTS) != 0) {
      if ((movePtr->moveFlags & MOVE_FLAG_DISABLED) == 0) {
        if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) != 0) {
          sub_80928C0(gUnknown_202DE58,movePtr,0);
          // $i0 was tormented
          sub_80522F4(pokemon,target,*gUnknown_80FCFBC);
          movePtr->moveFlags |= MOVE_FLAG_DISABLED;
          isTormented = TRUE;
        }
      }
      else if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) == 0) {
        movePtr->moveFlags &= ~(MOVE_FLAG_DISABLED);
      }
    }
  };

  if ((entityInfo->struggleMoveFlags & MOVE_FLAG_DISABLED) == 0) {
    if ((entityInfo->struggleMoveFlags & MOVE_FLAG_LAST_USED) != 0) {
      InitPokemonMove(&struggleMove, MOVE_STRUGGLE);
      entityInfo->struggleMoveFlags |= MOVE_FLAG_DISABLED;
      isTormented = TRUE;
      sub_80928C0(gUnknown_202DE58,&struggleMove,0);
      // $i0 was tormented
      sub_80522F4(pokemon,target,*gUnknown_80FCFBC);
    }
  }
  else if ((entityInfo->struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) {
    entityInfo->struggleMoveFlags &= ~(MOVE_FLAG_DISABLED);
  }
  if (isTormented)
  {
    if(entityInfo->chargingStatus == STATUS_BIDE) {
        entityInfo->chargingStatus = STATUS_NONE;
    }
  }
  else
  {
    // The target couldn't be tormented
    sub_80522F4(pokemon,target,*gUnknown_80FCFE4);
  }
  return isTormented;
}

bool8 sub_8057BB4(struct Entity *pokemon, struct Entity *target)
{
    LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
    return TRUE;
}

bool8 sub_8057BC4(struct Entity *pokemon, struct Entity *target)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 2);
    return TRUE;
}

bool8 SnoreMoveAction(struct Entity *pokemon, struct Entity *target, struct Move * move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (IsSleeping(pokemon)) {
    if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
      flag = TRUE;
      if (sub_805727C(pokemon,target,gUnknown_80F4E0A)) {
        CringeStatusTarget(pokemon,target,FALSE);
      }
    }
  }
  else {
    sub_80522F4(pokemon,target,*gUnknown_80FC734);
  }
  return flag;
}

bool8 sub_8057C68(struct Entity *pokemon, struct Entity *target)
{
    ChangeDefenseMultiplierTarget(pokemon, target, gUnknown_8106A4C, 0x40, 1);
    return TRUE;
}

bool8 sub_8057C88(struct Entity *pokemon, struct Entity *target, struct Move * move, u32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (sub_8055640(pokemon, target, move, 0x100, param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4DF6)) {
      CringeStatusTarget(pokemon,target,FALSE);
    }
  }
  return flag;
}

s32 sub_8057CD0(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  u32 uVar1;
  s32 iVar2;
  
  uVar1 = GetApparentWeather(pokemon);
  iVar2 = sub_80556BC(pokemon,target,gUnknown_80F51E4[uVar1],move,
                      gUnknown_80F51EC[uVar1],param_4);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

bool8 WhirlpoolMoveAction(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  u32 uVar3;
  bool8 flag;
  u8 chargeStatus;

  flag = FALSE;
  chargeStatus = target->info->chargingStatus;
  uVar3 = 0x100;
  if (chargeStatus == STATUS_DIVING) {
    uVar3 = 0x200;
  }
  if (sub_8055640(pokemon,target,move,uVar3,param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gUnknown_80F4E08)) {
      SqueezedStatusTarget(pokemon,target,0x3b,FALSE);
    }
  }
  return flag;
}

bool8 sub_8057D7C(struct Entity * pokemon, struct Entity * target)
{
  LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 2, 1, TRUE);
  return TRUE;
}

NAKED bool8 sub_8057D9C(struct Entity * pokemon, struct Entity * target)
{
        asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tadds r6, r0, 0\n"
	"\tadds r4, r1, 0\n"
	"\tldr r0, [r4, 0x70]\n"
	"\tmovs r5, 0\n"
	"\tldr r1, _08057DF8\n"
	"\tmov r8, r1\n"
	"\tmovs r1, 0x8C\n"
	"\tlsls r1, 1\n"
	"\tadds r2, r0, r1\n"
	"\tmovs r0, 0x1\n"
	"\tmov r12, r0\n"
	"\tmovs r7, 0x10\n"
	"\tmovs r3, 0x3\n"
"_08057DBC:\n"
	"\tldrb r1, [r2]\n"
	"\tmov r0, r12\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _08057DD4\n"
	"\tadds r0, r7, 0\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _08057DD4\n"
	"\tmovs r0, 0\n"
	"\tstrb r0, [r2, 0x4]\n"
	"\tmovs r5, 0x1\n"
"_08057DD4:\n"
	"\tadds r2, 0x8\n"
	"\tsubs r3, 0x1\n"
	"\tcmp r3, 0\n"
	"\tbge _08057DBC\n"
	"\tmov r0, r8\n"
	"\tadds r1, r4, 0\n"
	"\tmovs r2, 0\n"
	"\tbl SetMessageArgument\n"
	"\tcmp r5, 0\n"
	"\tbeq _08057E00\n"
	"\tldr r0, _08057DFC\n"
	"\tldr r2, [r0]\n"
	"\tadds r0, r6, 0\n"
	"\tadds r1, r4, 0\n"
	"\tbl sub_80522F4\n"
	"\tb _08057E0C\n"
	"\t.align 2, 0\n"
"_08057DF8: .4byte gUnknown_202DFE8\n"
"_08057DFC: .4byte gUnknown_80FD350\n"
"_08057E00:\n"
	"\tldr r0, _08057E18\n"
	"\tldr r2, [r0]\n"
	"\tadds r0, r6, 0\n"
	"\tadds r1, r4, 0\n"
	"\tbl sub_80522F4\n"
"_08057E0C:\n"
	"\tadds r0, r5, 0\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_08057E18: .4byte gUnknown_80FD370");
}

bool8 FocusEnergyMoveAction(struct Entity * pokemon, struct Entity * target)
{
    FocusEnergyStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SmokescreenMoveAction(struct Entity *pokemon, struct Entity *target)
{
    WhifferStatusTarget(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4EDC, TRUE));
    return TRUE;
}

bool8 sub_8057E50(struct Entity *pokemon, struct Entity *target)
{
    SendThawedMessage(pokemon, target);
    MirrorMoveStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_8057E6C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  struct EntityInfo *entityInfo;
  bool8 flag;
  
  flag = FALSE;
  entityInfo = pokemon->info;
  SendThawedMessage(pokemon,target);
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if (sub_8057308(pokemon, 0)) {
      entityInfo->unk155 = 1;
    }
  }
  return flag;
}

bool8 sub_8057ED0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4E04))
    {
        ChangeAttackMultiplierTarget(pokemon, target, gUnknown_8106A4C, 0x80, FALSE);
    }
  }
  return flag;
}

bool8 sub_8057F24(struct Entity *pokemon, struct Entity *target)
{
  struct EntityInfo *entityInfo;
  
  entityInfo = pokemon->info;
  entityInfo->HP = 1;
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A4C,0x40,TRUE);
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A50,0x40,TRUE);
  entityInfo->unk154 = 1;
  return TRUE;
}

bool8 sub_8057F7C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4E02))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C, FALSE);
    }
  }
  return flag;
}

bool8 sub_8057FCC(struct Entity *pokemon, struct Entity *target)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A50, 1);
    return TRUE;
}

bool8 sub_8057FF4(struct Entity *pokemon, struct Entity *target)
{
  u8 flashFireStatus;
  
  flashFireStatus = GetFlashFireStatus(target);
  if (flashFireStatus != FLASH_FIRE_STATUS_NONE) {
    if (target->info->unk152 == 0) {
      target->info->unk152 = 1;
      SetMessageArgument(gUnknown_202DFE8,target,0);
      if (flashFireStatus == FLASH_FIRE_STATUS_MAXED) {
        sub_80522F4(pokemon,target,*gUnknown_80FAE00); // Fire moves won't become stronger
      }
      else {
        sub_80522F4(pokemon,target,*gUnknown_80FADD8); // $m0 used flash fire to absorb fire
      }
    }
  }
  else {
    BurnedStatusTarget(pokemon,target, 0, TRUE);
  }
  return TRUE;
}

bool8 sub_805805C(struct Entity * pokemon,struct Entity * target,struct Move * move,s32 param_4)
{
  s16 *psVar3;
  s32 index;
  s32 r6;
  bool8 local_24;
  struct EntityInfo *entityInfo;
  s32 IQ;

  entityInfo = pokemon->info;
  

  r6 = 1;
  index = 0;
  if (0 <= gUnknown_80F55BC[0]) {
    IQ = entityInfo->IQ;
    for(psVar3 = &gUnknown_80F55BC[index]; (999 > index) && (*psVar3 >= 0); psVar3 = psVar3 + 2, index++)
        {
            if ((IQ < *psVar3)){
                r6 = psVar3[1];
                goto _080580B0;
            }
        }
 }
_080580B0:
  sub_806F370(pokemon,target,r6,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
  local_24 = local_24 == 0;
  return local_24;
}

bool8 GrudgeMoveAction(struct Entity *pokemon, struct Entity * target)
{
  struct EntityInfo *entityInfo;
  bool8 hasGrudge;
  
  hasGrudge = FALSE;
  entityInfo = target->info;
  SetMessageArgument(gUnknown_202DFE8,target,0);
  if (entityInfo->grudge) {
    sub_80522F4(pokemon,target,*gUnknown_80FD2B4);
  }
  else {
    entityInfo->grudge = TRUE;
    hasGrudge = TRUE;
    sub_80522F4(pokemon,target,*gUnknown_80FD294);
  }
  return hasGrudge;
}

bool8 sub_805815C(struct Entity *pokemon, struct Entity *target)
{
    CounterStatusTarget(pokemon, target, STATUS_COUNTER);
    return TRUE;
}

bool8 sub_805816C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  SendThawedMessage(pokemon, target);
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DB8))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 sub_80581D0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  SendThawedMessage(pokemon, target);
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DBA))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058234(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    u16 uVar1;
    uVar1 = (move->id == MOVE_FORESIGHT) ? 0x7A : 0x51;
    ExposeStatusTarget(pokemon, target, uVar1);
    return TRUE;
}

bool8 sub_805825C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseAccuracyStageTarget(pokemon, target, gUnknown_8106A50);
    return TRUE;
}

bool8 sub_8058270(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  u32 r3;

  r3 = 1;
  if((u8)(target->info->chargingStatus - 7) <= 1)
    r3 = 2;
  flag =  sub_8055640(pokemon,target,move,r3 << 8,param_4) ? TRUE : FALSE;
  return flag;
}

bool8 sub_80582AC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    return TRUE;
}

bool8 sub_80582C4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_80582D4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    return TRUE;
}

bool8 RazorWindMoveAction(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  bool8 flag;
  
  if (MoveMatchesChargingStatus(pokemon,move)) {
    flag = sub_8055640(pokemon,target,move,gUnknown_80F4F50,param_4) ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_RAZOR_WIND,move,*gUnknown_80FAC54);
    flag = TRUE;
  }
  return flag;
}

bool8 BideMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
   SetChargeStatusTarget(pokemon, target, STATUS_BIDE, move, *gUnknown_80FAC74);
   return TRUE; 
}

bool8 sub_805836C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  s32 iVar2;
  bool8 local_18;
  
  local_18 = FALSE;
  iVar2 = pokemon->info->unkA0 * 2;
  if (999 < iVar2) {
    iVar2 = 999;
  }
  sub_806F370(pokemon,target,iVar2,1,&local_18, GetMoveType(move),0x1ff,0,1,0);

  local_18 = local_18 == 0;
  return local_18;
}

bool8 sub_80583D8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DC2))
    {
        LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 1, 1, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058430(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DEE))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058478(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE6))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_80584C0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  s32 diffHP;
  bool8 local_24;
  struct EntityInfo *entityInfo;
  struct EntityInfo *entityInfo1;


  local_24 = 0;
  entityInfo = pokemon->info;
  entityInfo1 = target->info;
  diffHP = entityInfo1->HP - entityInfo->HP;
  if (diffHP < 0) {
    diffHP = 0;
  }
  sub_806F370(pokemon,target,diffHP,0,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);

  local_24 = local_24 == 0;
  return local_24;
}

bool8 sub_8058548(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  u32 r5;

  r5 = 0x80 << 1;
  if((pokemon->info->nonVolatileStatus) != STATUS_NONE)
    r5 = gUnknown_80F4F6C;
  flag =  sub_8055640(pokemon,target,move,r5,param_4) ? TRUE : FALSE;
  return flag;
}

bool8 sub_8058580(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DD4))
    {
        LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool8 sub_80585CC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if ((target->info->protectionStatus == STATUS_REFLECT) || (target->info->protectionStatus == STATUS_LIGHT_SCREEN)) {
    sub_80522F4(pokemon,target,*gUnknown_80FD104);
    SendProtectionEndMessage(pokemon,target);
    flag = TRUE;
  }

  flag |= (sub_8055640(pokemon,target,move,0x100,param_4) != 0);
  return flag;
}

bool8 sub_8058638(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool8 FocusPunchMoveAction(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  bool8 flag;
  
  if (MoveMatchesChargingStatus(pokemon,move)) {
    flag = sub_8055640(pokemon,target,move,gUnknown_80F4F54,param_4) ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_FOCUS_PUNCH,move,*gUnknown_80FACA4);
    flag = TRUE;
  }
  return flag;
}

bool8 sub_80586DC(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  bool8 hasLiquidOoze;
  s32 uVar3;
  s32 newHP;
  bool8 flag;
  struct EntityInfo *entityInfo;
  
  hasLiquidOoze = HasAbility(target, ABILITY_LIQUID_OOZE);
  uVar3 = sub_8055640(pokemon,target,move,0x100,param_4);
  flag = uVar3 != 0 ? TRUE : FALSE;
  if (flag && sub_8057308(pokemon, 0)) {
    newHP = uVar3 / 2;
    entityInfo = pokemon->info;
    flag = TRUE;
    if (newHP < 1) {
      newHP = 1;
    }
    if (!entityInfo->unkFB) {
      entityInfo->unkFB = TRUE;
    }
    if (hasLiquidOoze) {
        sub_806F324(pokemon, newHP, 0xd, 0x1fa);
    }
    else {
        HealTargetHP(pokemon, pokemon, newHP, 0, TRUE);
    }
  }
  return flag;
}


// NOTE: copy of sub_805AFA4  in status_checker.c except for different reg for entityInfo
bool8 sub_8058770(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  s32 r0;
  s32 r2;
  s32 r1;
  bool8 flag;

#ifndef NONMATCHING
  register struct EntityInfo *entityInfo asm("r2");
#else
  struct EntityInfo *entityInfo;
#endif
 
  entityInfo = pokemon->info;
  r2 = entityInfo->maxHPStat;
  r0 = r2;
  if (r2 < 0) {
    r0 = r2 + 3;
  }
  if (entityInfo->HP <= r0 >> 2) {
    r2 = 0;
  }
  else if (r1 = entityInfo->HP, r1 <= r2 / 2) {
      r2 = 1;
  }
  else
  {
    r0 = r2 * 3;
    if (r0 < 0) {
        r0 = r0 + 3;
    }
    if (r0 >>= 2, r2 = 3, r1 <= r0) {
        r2 = 2;
    }
  }
  flag =  sub_8055640(pokemon,target,move,gUnknown_80F51A4[r2],param_4) ? TRUE : FALSE;
  return flag;
}

bool8 sub_80587E8(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  bool8 flag;
  
  if (target->info->nonVolatileStatus == STATUS_PARALYSIS) {
    flag = sub_8055640(pokemon,target,move,0x80 << 2,param_4) ? TRUE : FALSE;
    SendNonVolatileEndMessage(pokemon, target);
  }
  else {
    flag = sub_8055640(pokemon,target,move,0x80 << 1,param_4) ? TRUE : FALSE;
  }
  return flag;
}

bool8 sub_8058838(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 3, 1, TRUE);
    return TRUE;
}

bool8 sub_8058858(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    s32 index = gUnknown_8106A4C;
    LowerAttackStageTarget(pokemon, target, index, 1, 1, TRUE);
    LowerDefenseStageTarget(pokemon, target, index, 1, 1, TRUE);
    return TRUE;
}

bool8 sub_805889C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    ImmobilizedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_80588A8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    sub_8079E34(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_80588B8(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    if(sub_8055640(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, 0)) 
        {
            gUnknown_202F219 = 1;
        }
    }
    return flag;
}

bool8 sub_80588F4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    bool8 flag;
    struct EntityInfo *entityInfo = target->info;
    
    flag = sub_8055640(pokemon, target, move, GetWeight(entityInfo->apparentID), param_4) != 0 ? TRUE: FALSE;
    return flag;
}


bool8 sub_8058930(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    struct EntityInfo *entityInfo;
    s32 index1;
    s32 index2;
    if(sub_8055640(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, gUnknown_80F4DD6)) 
        {
            entityInfo = pokemon->info;
            RaiseMovementSpeedTarget(pokemon, pokemon, 0, TRUE);
            index1 = gUnknown_8106A4C;
            RaiseAttackStageTarget(pokemon, pokemon, index1, 1);
            index2 = gUnknown_8106A50;
            RaiseAttackStageTarget(pokemon, pokemon, index2, 1);
            RaiseDefenseStageTarget(pokemon, pokemon, index1, 1);
            RaiseDefenseStageTarget(pokemon, pokemon, index2, 1);
            if(entityInfo->unkFB == 0)
            {
                entityInfo->unkFB = 1;
            }
        }
    }
    return flag;
}

bool8 sub_80589D4(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    HealTargetHP(pokemon, target, gUnknown_80F500A[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 sub_8058A08(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
    return TRUE;
}

bool8 sub_8058A18(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    if(sub_8055640(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, 0)) 
        {
            gUnknown_202F21A = 1;
        }
    }
    return flag;
}

bool8 sub_8058A54(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    SureShotStatusTarget(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4EB8, FALSE));
    return TRUE;
}

bool8 sub_8058A7C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A50, 1);
    return TRUE;
}

bool8 SkyAttackMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    bool8 flag = FALSE;

    if(MoveMatchesChargingStatus(pokemon, move))
    {
        if (sub_8055640(pokemon, target, move, gUnknown_80F4F4C, param_4) != 0) {
           flag = TRUE;
            if(sub_805727C(pokemon, target, gUnknown_80F4DF4))
                CringeStatusTarget(pokemon, target, FALSE);
        }
        sub_8079764(pokemon);
    }
    else {
       SetChargeStatusTarget(pokemon, pokemon, STATUS_SKY_ATTACK, move, *gUnknown_80FACC4);
       flag = TRUE;
    }
    return flag;
}

bool8 sub_8058B3C(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DBC))
    {
        FrozenStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058B84(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  struct EntityInfo *entityInfo;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, pokemon, gUnknown_80F4DD0))
    {
        entityInfo = pokemon->info;
        RaiseAttackStageTarget(pokemon, pokemon, gUnknown_8106A4C, 1);
        if(entityInfo->unkFB == 0)
            entityInfo->unkFB = 1;
    }
  }
  return flag;
}

bool8 EndureMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    EndureStatusTarget(pokemon, pokemon);
    return TRUE;
}

bool8 sub_8058BF0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
    return TRUE;
}

bool8 sub_8058C00(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DF8))
    {
        ConfuseStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058C48(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  s32 rand;
  s32 iVar2;
  bool8 flag;
  
  rand = DungeonRandRange(128, 384); // 0x80 - 0x180
  iVar2 = rand * pokemon->info->level;

  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xFF;
  }
  rand = iVar2 >> 8;
  if (rand < 0) {
    rand = 1;
  }
  if (199 < rand) {
    rand = 199;
  }
  flag = sub_8055864(pokemon,target,move,rand,param_4) != 0 ? TRUE: FALSE;
  return flag;
}

bool8 sub_8058C98(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4, u32 param_5)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_5) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DC0))
    {
        LowerDefenseStageTarget(pokemon, target,  param_4, 1, 1, FALSE);
    }
  }
  return flag;
}

bool8 sub_8058CEC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    bool8 flag = FALSE;
    if(sub_8055640(pokemon, target, move, 0x80 << 1, param_4) != 0)
    {
        flag = TRUE;
        if(sub_8057308(pokemon, 0)) 
        {
            LowerAttackStageTarget(pokemon, pokemon, gUnknown_8106A50, 2, 0, FALSE);
        }
    }
    return flag;
}

bool8 sub_8058D38(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    SleeplessStatusTarget(pokemon, target);
    return TRUE;
}


// NOTE: same as sub_8058770
bool8 sub_8058D44(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  s32 r0;
  s32 r2;
  s32 r1;
  bool8 flag;

#ifndef NONMATCHING
  register struct EntityInfo *entityInfo asm("r2");
#else
  struct EntityInfo *entityInfo;
#endif
 
  entityInfo = pokemon->info;
  r2 = entityInfo->maxHPStat;
  r0 = r2;
  if (r2 < 0) {
    r0 = r2 + 3;
  }
  if (entityInfo->HP <= r0 >> 2) {
    r2 = 0;
  }
  else if (r1 = entityInfo->HP, r1 <= r2 / 2) {
      r2 = 1;
  }
  else
  {
    r0 = r2 * 3;
    if (r0 < 0) {
        r0 = r0 + 3;
    }
    if (r0 >>= 2, r2 = 3, r1 <= r0) {
        r2 = 2;
    }
  }
  flag =  sub_8055640(pokemon,target,move,gUnknown_80F51B4[r2],param_4) ? TRUE : FALSE;
  return flag;
}


bool8 PsychUpMoveAction(struct Entity * pokemon, struct Entity * target, struct Move * move, u32 param_4)
{
  s32 index;
  struct EntityInfo *iVar3;
  struct EntityInfo *iVar4;
  
  iVar4 = pokemon->info;
  iVar3 = target->info;
  nullsub_92(target);

  for(index = 0; index < 2; index++)
  {
    iVar4->offensiveStages[index] = iVar3->offensiveStages[index];
    iVar4->defensiveStages[index] = iVar3->defensiveStages[index];
    iVar4->hitChanceStages[index] = iVar3->hitChanceStages[index];
    iVar4->offensiveMultipliers[index] = iVar3->offensiveMultipliers[index];
    iVar4->defensiveMultipliers[index] = iVar3->defensiveMultipliers[index];
  }
  SetMessageArgument(gAvailablePokemonNames,target,0);
  sub_80522F4(pokemon,target,*gUnknown_80FBD58); // It psyched itself up!
  if (iVar4->unkFB == 0) {
    iVar4->unkFB  = 1;
  }
  return TRUE;
}

bool8 sub_8058E5C(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
  int iVar2;
  int iVar3;
  bool8 flag;
  
  flag = FALSE;
  if ((sub_8055640(pokemon, target, move, 0x80 << 1, param_4) != 0) && (EntityExists(pokemon))) {
    iVar2 = pokemon->info->maxHPStat;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    iVar3 = iVar2 >> 3;
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    flag = TRUE;
    if ((!HasAbility(pokemon, ABILITY_ROCK_HEAD)) && sub_8057308(pokemon, 0)) {
      sub_806F370(pokemon,pokemon,iVar3,0,0,0,0x1fd,0x14,1,0);
    }
  }
  return flag;
}

bool8 sub_8058EE0(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    HealTargetHP(pokemon, target, target->info->maxHPStat / 2, 0, TRUE);
    return TRUE;
}

bool32 sub_8058F04(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
  bool32 flag;
  struct EntityInfo *entityInfo;
  s32 iVar3;
  
  entityInfo = target->info;
  iVar3 = 1;
  gDungeon->unk18200 = 0xc;
  gDungeon->unk18204 = 0;
  if (entityInfo->chargingStatus == STATUS_DIGGING) {
    iVar3 = 2;
  }
  flag = sub_8055640(pokemon,target,move,iVar3 << 8,param_4);
  if (flag != 0) {
    flag = TRUE;
  }
  return flag;
}

bool8 NaturePowerMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
  bool8 flag;
  s32 tileset;
  struct Move natureMove;
  
  tileset = gDungeon->tileset;
  if (tileset < 0) {
    tileset = 0;
  }
  if (0x4a < tileset) {
    tileset = 0x4a;
  }
  InitPokemonMove(&natureMove, gNaturePowerMoveTable[tileset].moveID);
  flag = gNaturePowerMoveTable[tileset].move(pokemon,target,&natureMove,param_4);
  return flag;
}

bool8 sub_8058FBC(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE4))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 sub_8059004(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    sub_807DF38(pokemon, target, &target->pos, 1, GetMoveType(move), sub_8057600(move, param_4));
    return TRUE;
}

bool8 sub_8059050(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 ChargeMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    SetChargeStatusTarget(pokemon, target, STATUS_CHARGING, move, *gUnknown_80FAD6C);
    return TRUE;
}

bool8 sub_8059080(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DE8))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 MistMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    MistStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_80590D4(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
  u8 moveType;
  bool8 uVar5;
  bool8 flag;
  
  flag = FALSE;
  moveType = GetMoveType(move);

  uVar5 = sub_806F4A4(target, moveType) != 0 ? TRUE : FALSE;

  if (HasAbility(target, ABILITY_LEVITATE)) {
    uVar5 = FALSE;
  }
  if (!uVar5) {
    sub_80522F4(pokemon,target,*gUnknown_80FEB88);
  }
  else {
    sub_806F370(pokemon,target,9999,1,&flag,GetMoveType(move),sub_8057600(move,param_4),0,1,1);
    flag = flag == 0;
  }
  return flag;
}

bool8 sub_8059190(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
  bool8 flag;
  
  flag = FALSE;
  if (sub_8055640(pokemon,target,move,0x100,param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gUnknown_80F4DEA))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 SafeguardMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, u32 param_4)
{
    SafeguardStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_80591E4(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
  bool8 hasLiquidOoze;
  s32 iVar3;
  s32 iVar4;
  bool8 flag;
  struct EntityInfo *entityInfo;
  
  flag = FALSE;
  hasLiquidOoze = HasAbility(target, ABILITY_LIQUID_OOZE);
  iVar3 = sub_8055640(pokemon,target,move,0x100,param_4);
  if (iVar3 != 0) {
    iVar4 = iVar3 / 2;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    if (EntityExists(pokemon)) {
      entityInfo = pokemon->info;
      flag = TRUE;
      if (entityInfo->unkFB == 0) {
        entityInfo->unkFB = 1;
      }
      if (sub_8057308(pokemon,0)) {
        if (hasLiquidOoze) {
            sub_806F324(pokemon,iVar4,0xd,0x1fa);
        }
        else {
            HealTargetHP(pokemon,pokemon,iVar4,0,1);
        }
      }
    }
  }
  return flag;
}

bool8 SkillSwapMoveAction(struct Entity *pokemon, struct Entity *target, struct Move *move, s32 param_4)
{
  u8 ability_1;
  u8 ability_2;
  bool8 flag;
  u8 *puVar5;
  u8 *puVar6;
  struct EntityInfo * targetEntityInfo;
  struct EntityInfo * pokeEntityData;
  
  pokeEntityData = pokemon->info;
  targetEntityInfo = target->info;
  if ((HasAbility(target, ABILITY_WONDER_GUARD)) || (HasAbility(pokemon, ABILITY_WONDER_GUARD))) {
    sub_80522F4(pokemon,target,*gUnknown_80FC8C0);
    flag = FALSE;
  }
  else
  {
    puVar5 = &targetEntityInfo->abilities[0];
    ability_1 = *puVar5;
    puVar6 = &targetEntityInfo->abilities[1];
    ability_2 = *puVar6;
    *puVar5 = pokeEntityData->abilities[0];
    *puVar6 = pokeEntityData ->abilities[1];
    pokeEntityData->abilities[0] = ability_1;
    pokeEntityData->abilities[1] = ability_2;
    gDungeon->unkC = 1;
    sub_80522F4(pokemon,target,*gUnknown_80FC888);
    if (pokeEntityData->unkFB == 0) {
      pokeEntityData->unkFB = 1;
    }
    sub_806ABAC(pokemon,pokemon);
    sub_806ABAC(pokemon,target);
    flag = TRUE;
  }
  return flag;
}
