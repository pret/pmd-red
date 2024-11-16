#include "global.h"
#include "status_actions.h"

#include "charge_move.h"
#include "code_8045A00.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "code_808417C.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "move_util.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "status_checks_1.h"
#include "status.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "text_util.h"
#include "tile_types.h"
#include "trap.h"
#include "weather.h"
#include "called_move_data.h"

extern void sub_807F43C(Entity *, Entity *);
extern void sub_807DC68(Entity *, Entity *);
extern u32 sub_803D73C(u32);
extern void sub_8045C28(Item *, u8 , u8);
extern void sub_80464C8(Entity *, Position *, Item *);
extern void sub_8068FE0(Entity *, u32, Entity *r2);
extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void sub_807FC3C(Position *, u32, u32);
extern void sub_8042A64(Position *);
extern void sub_8040A84(void);
extern void sub_80498A8(s32, s32);
extern void sub_8042A54(Position *);
extern void sub_8049BB0(s32, s32);
extern s16 sub_8057600(Move*, u32);
extern u32 sub_8055864(Entity *pokemon, Entity *target, Move *param_3, s32 param_4, s32 param_5);
extern void sub_807DB74(Entity *);
extern void HandleLuminousOrbAction(Entity *pokemon);
extern void sub_807D510(Entity *, Entity *);
extern void sub_807DA14(Entity *, Entity *, s32);
extern s16 sub_803D970(u32);
extern bool8 sub_806AA0C(s32, u32);
extern void sub_806BB6C(Entity *, s32);
extern void sub_807E254(Entity *, Entity *, u32);
extern u32 HandleDamagingMove(Entity *, Entity *, Move *, u32, u32);
extern void sub_806A6E8(Entity *);
extern u8 sub_8069D18(Position *);
extern u8 sub_804AD34(Position *);

// TODO include dungeon_ai.h when SqueezedStatusTarget is figured out
extern void LowerDefenseStageTarget(Entity *, Entity *, s32, s32, u8, bool8);
extern void RaiseAttackStageTarget(Entity *, Entity *, s32, s32);
extern void PoisonedStatusTarget(Entity *, Entity *, bool8);
extern void RaiseDefenseStageTarget(Entity *, Entity *, s32, s32);
extern void InfatuateStatusTarget(Entity *, Entity *, bool8);
extern void LowerAttackStageTarget(Entity *, Entity *, s32, s32, u8, bool8);
extern void PetrifiedStatusTarget(Entity *, Entity *);
extern void WrapTarget(Entity *, Entity *);

// TODO having matching issues when this isn't s32..  (move_effects_target.h)
extern void SqueezedStatusTarget(Entity *, Entity *, s32, bool32);
extern void sub_8075C58(Entity *, Entity *, s32, s32);

extern void DealDamageToEntity(Entity *, s32, u32, u32);
extern bool8 MoveRequiresCharging(Entity* pokemon,u16 moveID);
extern void sub_80783C4(Entity *, Entity *, bool8);


// NOTE: Override pokemon.c types for these two funcs
// GetSize is ok
extern u8 GetBodySize(s32 index);
// TODO The parameters don't match the function definition in pokemon_mid.h (u8*, s16).
extern void CopyCyanMonsterNametoBuffer(u8 *buffer, s32 index);
extern u32 GetSize(s16 index);

extern s16 gUnknown_80F55EC[];
extern s16 gUnknown_80F4DCE;
extern u8 *gUnknown_80FDD00[];
extern u8 *gUnknown_80FDCE4[];
extern u32 gUnknown_8106A50;
extern u8 *gPtrSleepingTargetOnlyMessage[];
extern u8 *gUnknown_80FAFF0[];
extern u32 gUnknown_80F4F58;
extern u32 gUnknown_8106A4C;
extern s16 gUnknown_80F4E74[];
extern u8 *gUnknown_80FD450[];
extern u8 *gUnknown_80FD434[];
extern s16 gUnknown_80F4F80;
extern u8 *gUnknown_80FF678[];
extern u8 *gUnknown_80FD0B8[];
extern u8 *gUnknown_80FD0B4[];
extern u8 *gUnknown_80FD454[];
extern s16 gUnknown_80F4FC6;
extern u8 *gUnknown_81004F0[];
extern u8 *gUnknown_80FD1CC[];
extern u8 *gUnknown_80FD1B0[];
extern u8 *gUnknown_80FD1EC[];
extern u8 *gUnknown_80FD4C4[];
extern u8 *gUnknown_80FD4DC[];
extern u8 *gUnknown_80FC920[];
extern u8 *gUnknown_80FC8F0[];
extern u8 *gUnknown_80FC614[];
extern u8 *gUnknown_80FC678[];
extern u8 *gUnknown_80FC654[];
extern u8 *gUnknown_80FD574[];
extern u8 *gUnknown_80FD430[];
extern u8 *gUnknown_80FD40C[];
extern u8 *gUnknown_80FD3F0[];
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4DDC;
extern s16 gUnknown_80F4F7E;
extern u8 *gUnknown_80FDCA0[];
extern u8 *gUnknown_80FDC9C[];
extern s16 gUnknown_80F4DD8;
extern u32 gUnknown_202F224;
extern u32 gUnknown_8106A8C[];
extern s16 gUnknown_80F4F94[];
extern u8 *gUnknown_80FC5A8[];
extern u8 *gPtrForecastPreventsTypeSwitchMessage[];
extern u8 *gUnknown_80FEB08[];
extern s16 gUnknown_80F4E08;
extern u8 gDungeonCamouflageTypes[76];
extern u32 gMetronomeCalledArrayId;

extern s16 gUnknown_80F4DC6;
extern u8 *gUnknown_80FEFF4[];

extern u32 gUnknown_80F51C4[];

bool8 sub_805AFA4(Entity * pokemon, Entity * target, Move *move, u32 param_4)
{
    EntityInfo *entityInfo;
    s32 maxHp;
    s32 index;
    bool8 flag;
    SendThawedMessage(pokemon, target);

    entityInfo = GetEntInfo(pokemon);
    maxHp = entityInfo->maxHPStat;
    if (entityInfo->HP <= entityInfo->maxHPStat / 4) {
        index = 0;
    }
    else if (entityInfo->HP <= maxHp / 2) {
        index = 1;
    }
    else if (entityInfo->HP <= (maxHp * 3) / 4) {
        index = 2;
    }
    else {
        index = 3;
    }

    flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F51C4[index],param_4) ? TRUE : FALSE;
    return flag;
}

bool8 sub_805B028(Entity * pokemon,Entity * target,Move *move)
{
    ParalyzeStatusTarget(pokemon,target, TRUE);
    return TRUE;
}

bool8 TransformMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  if (IsBossFight()) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEFF4);
    return FALSE;
  }
  else {
    move->PP = 0;
    TransformStatusTarget(pokemon,target);
    return TRUE;
  }
}

bool8 sub_805B074(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DC6) != 0) {
            PoisonedStatusTarget(pokemon,target,FALSE);
        }
    }
    return flag;
}

bool8 sub_805B0BC(Entity * pokemon, Entity * target)
{
    sub_807CD9C(pokemon, target, GetEntInfo(pokemon)->action.direction);
    return TRUE;
}

bool8 HandleColorChange(Entity * pokemon, Entity * target)
{
    u8 newType;
    const char *typeString;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(target);
    newType = gDungeonCamouflageTypes[gDungeon->tileset];
    if (HasAbility(target, ABILITY_FORECAST)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gPtrForecastPreventsTypeSwitchMessage);
        return FALSE;
    }
    else {
        entityInfo->types[0] = newType;
        entityInfo->types[1] = TYPE_NONE;
        entityInfo->isColorChanged = TRUE;
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
        typeString = GetUnformattedTypeString(newType);
        strcpy(gFormatBuffer_Items[0], typeString);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEB08);
        return TRUE;
    }
}

bool8 sub_805B164(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    RaiseAttackStageTarget(pokemon,target,gUnknown_8106A50, 2);
    return TRUE;
}

bool8 sub_805B17C(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 uVar4;
    bool8 flag;

    flag = FALSE;
    if (move->id == MOVE_FIRE_SPIN) {
        SendThawedMessage(pokemon,target);
        uVar4 = 0x13c;
    }
    else {
        uVar4 = 0x75;
        if ((move->id != MOVE_CLAMP) && (uVar4 = 0xf1, move->id == MOVE_BIND)) {
            uVar4 = 0x7e;
        }
    }
    if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4E08) != 0) {
            SqueezedStatusTarget(pokemon,target,uVar4,0);
        }
    }
    return flag;
}

bool8 PerishSongMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    PerishSongTarget(pokemon, target);
    return TRUE;
}

bool8 WrapMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    WrapTarget(pokemon, target);
    return TRUE;
}

bool8 SpikesMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    bool8 trapLaid;
    u8 uVar2;
    bool8 isNotTeamMember;

    trapLaid = FALSE;
    isNotTeamMember = GetEntInfo(pokemon)->isNotTeamMember;
    uVar2 = 1;

    if (isNotTeamMember) {
        uVar2 = 2;
    }
    if (LayTrap(&pokemon->pos,TRAP_SPIKE_TRAP,uVar2) != 0) {
        trapLaid = TRUE;
    }
    else
    {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC5A8); // A trap can't be laid here!
    }
    sub_8049ED4();
    return trapLaid;
}

bool8 sub_805B264(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 r3;
    bool8 r6;
    s32 iVar5;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(target);
    r3 = gUnknown_202F224;
    r6 = FALSE;

    gDungeon->unk181e8.unk18200 = gUnknown_8106A8C[r3];
    gDungeon->unk181e8.unk18204 = 0;
    iVar5 = gUnknown_80F4F94[r3];
    if (entityInfo->bideClassStatus.status == STATUS_DIGGING) {
        iVar5 *= 2;
    }
    r6 = sub_8055864(pokemon,target,move,iVar5,param_4) ? TRUE : FALSE;
    return r6;
}

bool8 MagicCoatMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    MagicCoatStatusTarget(pokemon, target);
    return TRUE;
}

bool8 ProtectMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    ProtectStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B2FC(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    RaiseDefenseStageTarget(pokemon,target,gUnknown_8106A4C,1);
    return TRUE;
}

bool8 sub_805B314(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    sub_80783C4(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_805B324(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gUnknown_80F4DD8) != 0) {
            LowerAttackStageTarget(pokemon,target,gUnknown_8106A50,1,1,0);
        }
    }
    return flag;
}

bool8 DestinyBondMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    DestinyBondStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B388(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    return (HandleDamagingMove(pokemon,target,move,0x100,param_4)) ? TRUE : FALSE;
}

bool8 MirrorCoatMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    MirrorCoatStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B3B4(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    u32 stat = gUnknown_8106A50;
    RaiseAttackStageTarget(pokemon,target,stat,1);
    RaiseDefenseStageTarget(pokemon,target,stat,1);
    return TRUE;
}

bool8 sub_805B3E0(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    HandleDamagingMove(pokemon,target,move,0x100,param_4);
    return TRUE;
}

bool8 sub_805B3FC(Entity * pokemon,Entity * target,Move *move, s32 param_4, s32 param_5)
{
    EntityInfo *entityInfo;
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,0x100,param_5) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,pokemon,gUnknown_80F4DCE) != 0) {
            entityInfo = GetEntInfo(pokemon);
            RaiseAttackStageTarget(pokemon,pokemon,param_4,1);
            SetExpMultplier(entityInfo);
        }
    }
    return flag;
}

bool8 sub_805B454(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    InfatuateStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 MimicMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    EntityInfo *entityInfo;
    EntityInfo *targetEntityInfo;
    Move *movePtr;
    s32 moveCounter;
    s32 moveIndex;
    bool8 mimicSuccess;

    mimicSuccess = FALSE;
    entityInfo = GetEntInfo(pokemon);
    targetEntityInfo = GetEntInfo(target);
    moveCounter = 0;

    for(moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        movePtr = &targetEntityInfo->moves.moves[moveIndex];
        if (((movePtr->moveFlags & MOVE_FLAG_EXISTS)) && !MoveRequiresCharging(pokemon,movePtr->id)) {
            if ((movePtr->id != MOVE_MIMIC) && (movePtr->id != MOVE_ASSIST) && (movePtr->id != MOVE_SKETCH) && (movePtr->id != MOVE_MIRROR_MOVE) &&
                (movePtr->id != MOVE_ENCORE) && ((movePtr->moveFlags & MOVE_FLAG_LAST_USED))) {
                entityInfo->mimicMoveIDs[moveCounter] = movePtr->id;
                moveCounter++;
            }
        }
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
    if (moveCounter != 0) {
        SetExpMultplier(entityInfo);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FDCE4);
        mimicSuccess = TRUE;
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FDD00);
    }
    return mimicSuccess;
}

bool8 sub_805B53C(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s16 *r1;
    s32 index;
    s32 r5;
    s32 IQ;
    u8 local_24;
    EntityInfo *entityInfo;

    local_24 = 0;
    entityInfo = GetEntInfo(pokemon);
    r5 = 1;
    index = 0;
    if (0 <= gUnknown_80F55EC[0]) {
        IQ = entityInfo->IQ;
        for(r1 = &gUnknown_80F55EC[index]; (999 > index) && (*r1 >= 0); r1 = r1 + 2, index++)
            {
                if ((IQ < *r1)){
                    r5 = r1[1];
                    goto _0805B598;
                }
            }
    }
_0805B598:
    sub_806F370(pokemon,target,r5,1,&local_24, GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = local_24 == 0;
    return local_24;
}

bool8 LeechSeedMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandleLeechSeed(pokemon, target, TRUE);
    SetExpMultplier(GetEntInfo(pokemon));
    return TRUE;
}

bool8 sub_805B618(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  bool8 flag;
  Move natureMove;
  u32 index;

  index = gMetronomeCalledArrayId;

  InitPokemonMove(&natureMove, gMetronomeCalledMoves[index].moveID);
  flag = gMetronomeCalledMoves[index].callback(pokemon, target, &natureMove, param_4);
  return flag;
}

bool8 sub_805B668(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  bool8 hasLiquidOoze;
  s32 iVar3;
  s32 newHP;
  bool8 flag;

  flag = FALSE;
  hasLiquidOoze = HasAbility(target, ABILITY_LIQUID_OOZE);
  if (IsSleeping(target)) {
    iVar3 = HandleDamagingMove(pokemon,target,move,0x100,param_4);
    if (iVar3 != 0) {
      flag = TRUE;
      newHP = iVar3 / 2;
      if (newHP < 1) {
        newHP = 1;
      }
      if (RollSecondaryEffect(pokemon,0) != 0) {
        SetExpMultplier(GetEntInfo(pokemon));
        if (RollSecondaryEffect(pokemon,0) != 0) {
          if (hasLiquidOoze) {
            DealDamageToEntity(pokemon,newHP,0xd,0x1fa);
          }
          else {
            HealTargetHP(pokemon,pokemon,newHP,0,TRUE);
          }
        }
      }
    }
  }
  else {
    TryDisplayDungeonLoggableMessage3(pokemon,target,*gPtrSleepingTargetOnlyMessage);
  }
  return flag;
}

bool8 SnatchMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    SnatchStatusTarget(pokemon, target);
    return TRUE;
}

bool8 RecycleMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 i;
    EntityInfo *entityInfo = GetEntInfo(target);
    bool32 isTMRecycled = FALSE;

    if (!entityInfo->isNotTeamMember) {
        for(i = 0; i < INVENTORY_SIZE; i++)
        {
            if (ItemExists(&gTeamInventoryRef->teamItems[i]) && !ItemInShop(&gTeamInventoryRef->teamItems[i]))
            {
                Item *item = &gTeamInventoryRef->teamItems[i];
                if (item->id == ITEM_TM_USED_TM) {
                    xxx_init_itemslot_8090A8C(item, item->quantity + 0x7d,0);
                    isTMRecycled = TRUE;
                }
            }
        }
        if (ItemExists(&entityInfo->heldItem) && (entityInfo->heldItem.id == ITEM_TM_USED_TM)) {
            xxx_init_itemslot_8090A8C(&entityInfo->heldItem,entityInfo->heldItem.quantity + 0x7D,0);
            isTMRecycled = TRUE;
        }
    }

    if (isTMRecycled) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FDC9C); // The Used TM was recharged!
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FDCA0); // But nothing happened!
    }
    return isTMRecycled;
}

bool8 ReflectMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    ReflectStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805B808(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    u8 local_20;

    local_20 = 0;
    sub_806F370(pokemon,target,gUnknown_80F4F7E,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = (local_20 == 0);
    return local_20;
}

bool8 sub_805B884( Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
    return TRUE;
}

bool8 SkullBashMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
    bool8 flag;

    if (MoveMatchesBideClassStatus(pokemon,move)) {
        flag = HandleDamagingMove(pokemon,target,move,gUnknown_80F4F58,param_4) != 0 ? 1 : 0;
        sub_8079764(pokemon);
    }
    else {
        SetChargeStatusTarget(pokemon,target,STATUS_SKULL_BASH,move,*gUnknown_80FAFF0);
        flag = TRUE;
    }
    return flag;
}

bool8 sub_805B910(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if(sub_805727C(pokemon, target, gUnknown_80F4DDC))
        {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 1, 1, 0);
        }
    }
    return flag;
}

bool8 sub_805B968(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
    s32 entityHP;
    s32 newHP;
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if (RollSecondaryEffect(pokemon,0) != 0) {
            entityHP = GetEntInfo(pokemon)->maxHPStat;
            if (entityHP < 0) {
                entityHP = entityHP + 3;
            }
            newHP = entityHP >> 2;
            if (newHP < 1) {
                newHP = 1;
            }
            sub_806F370(pokemon,pokemon,newHP,0,0,0,sub_8057600(move,param_4),0,1,0);
        }
    }
    return flag;
}

bool8 RockSmashMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    Position pos;
    bool8 flag = FALSE;

    if (sub_8069D18(&pos) != 0) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD430); // Can't use that diagonally!
    }
    else {
        ASM_MATCH_TRICK(target);
        flag = sub_804AD34(&pos);
        if (flag) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD3F0); // It dug the wall in front!
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD40C); // Can't use that here!
        }
    }
    return flag;
}

bool8 sub_805BA44(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    sub_807D3CC(pokemon);
    return TRUE;
}

bool8 sub_805BA50(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    EntityInfo *iVar2;
    EntityInfo *iVar3;
    EntityInfo *iVar5;
    EntityInfo *iVar6;
    bool8 flag;
    Item *pokeItem;
    Item *targetItem;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,0x100,param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target, 0) != 0) {
            iVar2 = GetEntInfo(pokemon);
            iVar3 = GetEntInfo(pokemon);
            iVar5 = GetEntInfo(target);
            iVar6 = GetEntInfo(target);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], pokemon, 0);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
            if (HasAbility(target, ABILITY_STICKY_HOLD)) {
                return TRUE;
            }
            else if (HasHeldItem(target, ITEM_ALERT_SPECS)) {
                TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD574); // $m1 was protected by its Specs!
                return TRUE;
            }
            else {
                pokeItem = &iVar2->heldItem;
                targetItem = &iVar5->heldItem;
                if ((pokeItem->flags & ITEM_FLAG_EXISTS) != 0) {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC654); // $m0 has an item already!
                    return TRUE;
                }
                else if ((targetItem->flags & ITEM_FLAG_EXISTS) == 0) {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC678); // $m1 doesn't have anything
                    return TRUE;
                }
                else {
                    iVar3->heldItem = iVar6->heldItem;
                    ZeroOutItem(targetItem);
                    sub_806A6E8(pokemon);
                    sub_806A6E8(target);
                    SetExpMultplier(iVar3);
                    TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC614); // Got $m1's item!
                }
            }
        }
    }
    return flag;
}

bool8 ReboundOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    CounterStatusTarget(pokemon, target, STATUS_MINI_COUNTER);
    return TRUE;
}

bool8 sub_805BB74(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    SetExpMultplier(GetEntInfo(pokemon));
    sub_807E254(pokemon, target, 1);
    return TRUE;
}

bool8 sub_805BB98(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    sub_807D148(pokemon, target, 1, NULL);
    return TRUE;
}

bool8 CleanseOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 i;
    EntityInfo *entityInfo = GetEntInfo(target);
    bool32 isItemCleaned = FALSE;

    if (!entityInfo->isNotTeamMember) {
        for(i = 0; i < INVENTORY_SIZE; i++){
            if (ItemExists(&gTeamInventoryRef->teamItems[i])
                && !ItemInShop(&gTeamInventoryRef->teamItems[i])
                && ItemSticky(&gTeamInventoryRef->teamItems[i]))
            {
                gTeamInventoryRef->teamItems[i].flags &= ~(ITEM_FLAG_STICKY);
                isItemCleaned = TRUE;
            }
        }
        for(i = 0; i < MAX_TEAM_MEMBERS; i++)
        {
            Entity *entity = gDungeon->teamPokemon[i];
            if (EntityExists(entity)) {
                Item *item = &GetEntInfo(entity)->heldItem;
                if (ItemExists(item) && ItemSticky(item)) {
                    item->flags &= ~(ITEM_FLAG_STICKY);
                    isItemCleaned = TRUE;
                }
            }
        }
    }

    if (isItemCleaned) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC8F0);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FC920);
    }
    return isItemCleaned;
}

bool8 sub_805BC70(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    sub_8075C58(pokemon,target,CalculateStatusTurns(target, gUnknown_80F4E74, TRUE), TRUE);
    return TRUE;
}

bool8 sub_805BC98(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    EntityInfo *entityInfo;
    bool8 flag;
    s32 targetHP;
    s32 pokeHP;
    u8 local_28;
    u8 local_27;

    local_28 = 0;
    local_27 = 0;
    entityInfo = GetEntInfo(pokemon);
    targetHP = GetEntInfo(target)->HP - 1;
    if (targetHP < 0) {
        targetHP = 0;
    }
    sub_806F370(pokemon,target,targetHP,0,&local_28,0,sub_8057600(move,param_4),0,0,0);
    pokeHP = entityInfo->HP / 2;
    if (pokeHP < 0) {
        pokeHP = 0;
    }
    sub_806F370(pokemon,pokemon,pokeHP,0,&local_27,0,sub_8057600(move,param_4),0,0,0);

    local_28 = (local_28 == 0);
    local_27 = (local_27 == 0);

    flag = FALSE;
    if ((local_28 != 0) || (local_27 != 0)) {
        flag = TRUE;
    }
    return flag;
}

bool8 SilenceOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    MuzzleTarget(pokemon, target);
    return TRUE;
}

bool8 ScannerOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandleScannerOrb(pokemon, target);
    return TRUE;
}

bool8 RadarOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandleRadarOrb(pokemon, target);
    return TRUE;
}

bool8 TransferOrbAction(Entity *pokemon, Entity * target, Move *move, s32 param_4)
{
    EntityInfo *entityInfo;
    s32 oldID; //r8
    s32 targetID; // r5
    s32 r6; // r6
    bool8 didTransfer;

    didTransfer = FALSE;
    if (GetEntInfo(target)->isNotTeamMember) {
        entityInfo = GetEntInfo(target);
        targetID = entityInfo->id;
        oldID = entityInfo->id;
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        if (entityInfo->monsterBehavior != BEHAVIOR_FIXED_ENEMY) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD450);
            return FALSE;
        }
        else
        {
            for (r6 = 0; r6 < 0x1E; r6++) {
                targetID = sub_803D970(0);
                if ((sub_806AA0C(targetID,0)) && (oldID != targetID)) {
                    if (GetBodySize(oldID) == GetBodySize(targetID)) break;
                }
            }
            if ((r6 == 0x1e) || (entityInfo->id == targetID)) {
                TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD450);
            }
            else {
                CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[1], targetID);
                TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD434);
                sub_806BB6C(target, targetID);
                didTransfer = TRUE;
            }
        }
    }
    else {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD450);
    }
    return didTransfer;
}

bool8 sub_805BE90(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
  return TRUE;
}

bool8 LuminousOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandleLuminousOrbAction(pokemon);
    return TRUE;
}

bool8 PetrifyOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    PetrifiedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 sub_805BEB8(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    sub_807DA14(pokemon, target, 8);
    return TRUE;
}

bool8 sub_805BEC8(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    sub_807D510(pokemon, target);
    return TRUE;
}

bool8 EscapeOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
    if (gDungeon->unk644.unk2A != 0) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD4DC); // $m0 can't escape!
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD4C4); // $m0 escaped!
        gDungeon->unk4 = 1;
        gDungeon->unk11 = 1;
    }
    return FALSE;
}

bool8 sub_805BF34(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    sub_807DB74(pokemon);
    return TRUE;
}

bool8 TrapbustOrbAction(Entity * pokemon,Entity * target, Move *move, s32 param_4)
{
    struct Tile *tile;
    Entity *object;
    Trap *trapData;
    s32 bottomRightCornerX, bottomRightCornerY;
    s32 xCoord, yCoord;
    struct RoomData *room;
    s32 topLeftCornerX, topLeftCornerY;
    Position pos;
    bool8 foundTrap = FALSE;
    tile = GetTileAtEntitySafe(target);
    if (IsBossFight()) {
        LogMessageByIdWithPopupCheckUser(pokemon,*gUnknown_80FD1EC);
        return FALSE;
    }
    else
    {
        if (tile->room == CORRIDOR_ROOM) {
            bottomRightCornerX    =   target->pos.x - gDungeon->unk181e8.visibilityRange;
            bottomRightCornerY    =   target->pos.y - gDungeon->unk181e8.visibilityRange;
            topLeftCornerX      =   bottomRightCornerX + gDungeon->unk181e8.visibilityRange;
            topLeftCornerY      =   bottomRightCornerY + gDungeon->unk181e8.visibilityRange;
        }
        else {
            room       =   &gDungeon->roomData[tile->room];
            bottomRightCornerX     =   room->bottomRightCornerX - 1;
            bottomRightCornerY     =   room->bottomRightCornerY - 1;
            topLeftCornerX       =   room->topLeftCornerX + 1;
            topLeftCornerY       =   room->topLeftCornerY + 1;
        }
        ++topLeftCornerY; --topLeftCornerY;
        for (xCoord = bottomRightCornerX; xCoord <= topLeftCornerX; xCoord++) {
            for (yCoord = bottomRightCornerY; yCoord <= topLeftCornerY; yCoord++) {
                object = GetTileSafe(xCoord, yCoord)->object;
                if (((object != 0) && (GetEntityType(object) == ENTITY_TRAP)) &&
                    (trapData = GetTrapData(object), trapData->id != TRAP_WONDER_TILE)) {
                    pos.y = yCoord;
                    pos.x = xCoord;
                    sub_807FE04(&pos, 0);
                    foundTrap = TRUE;
                }
            }
        }
        if (foundTrap) {
            TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FD1B0);
            sub_8040A84();
            sub_8049ED4();
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FD1CC);
        }
    }
    return foundTrap;
}

bool8 sub_805C080(Entity * pokemon, Entity *target, Move *move, s32 param_4)
{
    Entity **possibleTargets;
    s32 numPossibleTargets;
    Entity *targetEntity;
    bool8 foundTarget;
    s32 index;

    foundTarget = FALSE;
    if (GetEntInfo(pokemon)->isNotTeamMember) {
        possibleTargets = gDungeon->wildPokemon;
        numPossibleTargets = DUNGEON_MAX_WILD_POKEMON;
    }
    else {
        possibleTargets = gDungeon->teamPokemon;
        numPossibleTargets = MAX_TEAM_MEMBERS;
    }
    for(index = 0; index < numPossibleTargets; index++){
        targetEntity = possibleTargets[index];
        if (((EntityExists(targetEntity)) && (pokemon != targetEntity)) &&
            (GetTreatmentBetweenMonsters(pokemon,targetEntity,TRUE,FALSE) == TREATMENT_TREAT_AS_ALLY)) {
            sub_807D148(pokemon,targetEntity,2,&pokemon->pos);
            foundTarget = TRUE;
        }
    }
    if (!foundTarget) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_81004F0);
    }
    return foundTarget;
}

bool8 InvisifyOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    InvisibleStatusTarget(pokemon, pokemon);
    return TRUE;
}

bool8 sub_805C138(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    u8 local_20;

    local_20 = 0;
    sub_806F370(pokemon,target,9999,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = (local_20 == 0);
    return local_20;
}

bool8 IdentifyOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    IdentityItemHolders(pokemon, target);
    return TRUE;
}

bool8 sub_805C1BC(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = sub_8055864(pokemon, target, move, gUnknown_80F4F80, param_4) != 0 ? TRUE : FALSE;
    return flag;
}

bool8 sub_805C1E4(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FD454);
    return FALSE;
}

bool8 ShockerOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    CowerStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

bool8 sub_805C208(Entity *pokemon, Entity *target, Move *move, u32 param_4)
{
    u32 targetSize;
    u8 local_24;

    local_24 = 0;
    targetSize = GetSize(GetEntInfo(target)->apparentID);
    sub_806F370(pokemon,target,targetSize,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);

    local_24 = local_24 == 0;
    return local_24;
}

bool8 sub_805C288(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_8078A58(pokemon, target, gUnknown_80F4FC6, 0);
    return TRUE;
}

bool8 sub_805C2A0(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_807DC68(pokemon, target);
    return TRUE;
}

bool8 FillInOrbAction(Entity *pokemon,Entity *target, Move *move, s32 param_4)
{
    struct Tile *tileToFill;
    EntityInfo *targetInfo;
    int y;
    bool8 filledInTile;
    int x;
    Position tileCoords;

    filledInTile = FALSE;
    targetInfo = GetEntInfo(target);
    if (IsBossFight()) {
        LogMessageByIdWithPopupCheckUser(pokemon,*gUnknown_80FD0B8);
        return FALSE;
    }
    else
    {
        // Calculate the coordinates of the tile in front of the user
        tileCoords.x = target->pos.x + gAdjacentTileOffsets[targetInfo->action.direction].x;
        tileCoords.y = target->pos.y + gAdjacentTileOffsets[targetInfo->action.direction].y;

        sub_8042A54(&tileCoords);
        tileToFill = GetTileSafe(tileCoords.x,tileCoords.y);
        if ((tileToFill->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY) {
            tileToFill->terrainType = (tileToFill->terrainType & ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) | TERRAIN_TYPE_NORMAL;

            for(y = -1; y < 2; y++)
                for(x = -1; x < 2; x++)
                    sub_80498A8(tileCoords.x + x, tileCoords.y + y);
            filledInTile = TRUE;
            sub_806CF60();
        }

        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
            for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
                sub_8049BB0(x,y);

        if (filledInTile) {
            sub_8042A64(&tileCoords);
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD0B4);
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FD0B8);
        }
        sub_8040A84();
        sub_8049ED4();
        return filledInTile;
    }
}

bool8 TrapperOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    u32 var;
    var = (GetEntInfo(target)->isNotTeamMember ? 2 : 1);
    sub_807FC3C(&target->pos, NUM_TRAPS, var);
    return TRUE;
}

bool8 sub_805C3F8(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    Item stack;
    Position posStruct = target->pos;

    if(GetEntInfo(target)->monsterBehavior != BEHAVIOR_FIXED_ENEMY)
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FF678);
        return FALSE;
    }
    else
    {
        target->isVisible = FALSE;
        sub_8045C28(&stack, sub_803D73C(0), 0);
        sub_80464C8(pokemon, &posStruct, &stack);
        sub_8068FE0(target, 0x218, pokemon);
        return TRUE;
    }
}

bool8 sub_805C45C(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_807F43C(pokemon, target);
    return TRUE;
}

bool8 MobileOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    MobileStatusTarget(pokemon, target);
    return TRUE;
}

bool8 StairsOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    HandleStairsOrb(pokemon, target);
    return TRUE;
}

bool8 LongtossOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    LongTossStatusTarget(pokemon, target);
    return TRUE;
}

bool8 PierceOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    PierceStatusTarget(pokemon, target);
    return TRUE;
}
