#include "global.h"
#include "globaldata.h"
#include "move_orb_actions_4.h"
#include "move_orb_actions_2.h"
#include "dungeon_ai.h"
#include "dungeon_move_util.h"
#include "dungeon_message.h"
#include "dungeon_move.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_logic.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_misc.h"
#include "dungeon_util.h"
#include "move_effects_target.h"
#include "move_util.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "status.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "text_util.h"
#include "trap.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"

extern void sub_807F43C(Entity *, Entity *);
extern void HandleOneRoomOrb(Entity *, Entity *);
extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void UpdateMinimap(void);
extern void HandleDroughtOrbAction(Entity *);
extern void HandleLuminousOrbAction(Entity *pokemon);
extern void HandleTrawlOrbAction(Entity *, Entity *);
extern void HandlePounceOrbAction(Entity *, Entity *, s32);
extern s16 GetRandomFloorMonsterId(u32);
extern bool8 sub_806AA0C(s32, u32);
extern void sub_806BB6C(Entity *, s32);
extern void HandleSwitcherOrb(Entity *, Entity *, u32);

extern void DealDamageToEntity(Entity *, s32, u32, u32);

extern u32 gUnknown_8106A50;
extern u32 gUnknown_8106A4C;

bool8 ProtectMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    ProtectStatusTarget(pokemon, target);
    return TRUE;
}

bool8 DefenseCurlMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    RaiseDefenseStageTarget(pokemon,target,gUnknown_8106A4C,1);
    return TRUE;
}

bool8 sub_805B314(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    sub_80783C4(pokemon, target, TRUE);
    return TRUE;
}

bool8 MistBallMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target,gMistBallSecondaryChance) != 0) {
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

bool8 FalseSwipeMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    return (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4)) ? TRUE : FALSE;
}

bool8 MirrorCoatMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    MirrorCoatStatusTarget(pokemon, target);
    return TRUE;
}

bool8 CalmMindMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    u32 stat = gUnknown_8106A50;
    RaiseAttackStageTarget(pokemon,target,stat,1);
    RaiseDefenseStageTarget(pokemon,target,stat,1);
    return TRUE;
}

bool8 HiddenPowerMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4)
{
    HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4);
    return TRUE;
}

bool8 MetalClawMoveAction(Entity * pokemon,Entity * target,Move *move, s32 param_4, s32 param_5)
{
    EntityInfo *entityInfo;
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_5) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,pokemon,gMetalClawSecondaryChance) != 0) {
            entityInfo = GetEntInfo(pokemon);
            RaiseAttackStageTarget(pokemon,pokemon,param_4,1);
            SetExpMultplier(entityInfo);
        }
    }
    return flag;
}

bool8 AttractMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
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
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDCE4);
        mimicSuccess = TRUE;
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDD00);
    }
    return mimicSuccess;
}

bool8 FrustrationMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 i;
    bool8 local_24 = FALSE;
    EntityInfo *entityInfo = GetEntInfo(pokemon);
    s32 dmg = 1;

    for (i = 0; i < 999 && gFrustrationDmgData[i].minIq >= 0; i++) {
        if (entityInfo->IQ < gFrustrationDmgData[i].minIq) {
            dmg = gFrustrationDmgData[i].dmgVal;
            break;
        }
    }

    sub_806F370(pokemon,target,dmg,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = (local_24 == 0);
    return local_24;
}

bool8 LeechSeedMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandleLeechSeed(pokemon, target, TRUE);
    SetExpMultplier(GetEntInfo(pokemon));
    return TRUE;
}

bool8 MetronomeMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  bool8 flag;
  Move natureMove;
  u32 index;

  index = gMetronomeCalledArrayId;

  InitPokemonMove(&natureMove, gMetronomeCalledMoves[index].moveID);
  flag = gMetronomeCalledMoves[index].callback(pokemon, target, &natureMove, param_4);
  return flag;
}

bool8 DreamEaterMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  bool8 hasLiquidOoze;
  s32 iVar3;
  s32 newHP;
  bool8 flag;

  flag = FALSE;
  hasLiquidOoze = AbilityIsActive(target, ABILITY_LIQUID_OOZE);
  if (IsSleeping(target)) {
    iVar3 = HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4);
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
    TryDisplayDungeonLoggableMessage3(pokemon,target,gPtrSleepingTargetOnlyMessage);
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
                    ItemIdToItem(item, item->quantity + 0x7d,0);
                    isTMRecycled = TRUE;
                }
            }
        }
        if (ItemExists(&entityInfo->heldItem) && (entityInfo->heldItem.id == ITEM_TM_USED_TM)) {
            ItemIdToItem(&entityInfo->heldItem,entityInfo->heldItem.quantity + 0x7D,0);
            isTMRecycled = TRUE;
        }
    }

    if (isTMRecycled) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDC9C); // The Used TM was recharged!
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDCA0); // But nothing happened!
    }
    return isTMRecycled;
}

bool8 ReflectMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    ReflectStatusTarget(pokemon, target);
    return TRUE;
}

bool8 DragonRageMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    u8 local_20;

    local_20 = 0;
    sub_806F370(pokemon,target,gDragonRageDmgValue,1,&local_20,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_20 = (local_20 == 0);
    return local_20;
}

bool8 DragonDanceMoveAction( Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C, 1);
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
    return TRUE;
}

bool8 SkullBashMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
    bool8 flag;

    if (MoveMatchesBideClassStatus(pokemon,move)) {
        flag = HandleDamagingMove(pokemon,target,move,gSkullBashModifier,param_4) != 0 ? 1 : 0;
        sub_8079764(pokemon);
    }
    else {
        SetChargeStatusTarget(pokemon,target,STATUS_SKULL_BASH,move,gUnknown_80FAFF0);
        flag = TRUE;
    }
    return flag;
}

bool8 LusterPurgeMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
        flag = TRUE;
        if(sub_805727C(pokemon, target, gLusterPurgeSecondaryChance))
        {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50, 1, 1, 0);
        }
    }
    return flag;
}

bool8 StruggleMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
    s32 entityHP;
    s32 newHP;
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
        flag = TRUE;
        if (RollSecondaryEffect(pokemon, 0) != 0) {
            entityHP = GetEntInfo(pokemon)->maxHPStat;
            if (entityHP < 0) {
                entityHP = entityHP + 3;
            }
            newHP = entityHP >> 2;
            if (newHP < 1) {
                newHP = 1;
            }
            sub_806F370(pokemon, pokemon, newHP, 0, 0, 0, sub_8057600(move, param_4), 0, 1, 0);
        }
    }
    return flag;
}

// overlay_0005.bin::0216AF44
bool8 RockSmashMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    DungeonPos pos;
    bool8 flag = FALSE;

    if (sub_8069D18(&pos, target)) {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD430); // Can't use that diagonally!
    }
    else {
        flag = sub_804AD34(&pos);
        if (flag)
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD3F0); // It dug the wall in front!
        else
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD40C); // Can't use that here!
    }

    return flag;
}

bool8 sub_805BA44(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_807D3CC(pokemon);
    return TRUE;
}

bool8 ThiefAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    EntityInfo *pokemonInfo1;
    EntityInfo *pokemonInfo2;
    EntityInfo *targetInfo1;
    EntityInfo *targetInfo2;
    bool8 flag;
    Item *pokeItem;
    Item *targetItem;

    flag = FALSE;
    if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon,target, 0) != 0) {
            pokemonInfo1 = GetEntInfo(pokemon);
            pokemonInfo2 = GetEntInfo(pokemon);
            targetInfo1 = GetEntInfo(target);
            targetInfo2 = GetEntInfo(target);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], pokemon, 0);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
            if (AbilityIsActive(target, ABILITY_STICKY_HOLD)) {
                return TRUE;
            }
            else if (HasHeldItem(target, ITEM_ALERT_SPECS)) {
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD574); // $m1 was protected by its Specs!
                return TRUE;
            }
            else {
                pokeItem = &pokemonInfo1->heldItem;
                targetItem = &targetInfo1->heldItem;
                if ((pokeItem->flags & ITEM_FLAG_EXISTS) != 0) {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC654); // $m0 has an item already!
                    return TRUE;
                }
                else if ((targetItem->flags & ITEM_FLAG_EXISTS) == 0) {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC678); // $m1 doesn't have anything
                    return TRUE;
                }
                else {
                    pokemonInfo2->heldItem = targetInfo2->heldItem;
                    ZeroOutItem(targetItem);
                    sub_806A6E8(pokemon);
                    sub_806A6E8(target);
                    SetExpMultplier(pokemonInfo2);
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC614); // Got $m1's item!
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

bool8 SwitcherOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    SetExpMultplier(GetEntInfo(pokemon));
    HandleSwitcherOrb(pokemon, target, 1);
    return TRUE;
}

bool8 StayawayOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    WarpTarget(pokemon, target, 1, NULL);
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
            if (EntityIsValid(entity)) {
                Item *item = &GetEntInfo(entity)->heldItem;
                if (ItemExists(item) && ItemSticky(item)) {
                    item->flags &= ~(ITEM_FLAG_STICKY);
                    isItemCleaned = TRUE;
                }
            }
        }
    }

    if (isItemCleaned) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC8F0);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC920);
    }
    return isItemCleaned;
}

bool8 SlumberOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    SleepStatusTarget(pokemon,target,CalculateStatusTurns(target, gSleepTurnRange, TRUE), TRUE);
    return TRUE;
}

bool8 TwoEdgeMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
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
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD450);
            return FALSE;
        }
        else
        {
            for (r6 = 0; r6 < 0x1E; r6++) {
                targetID = GetRandomFloorMonsterId(0);
                if ((sub_806AA0C(targetID,0)) && (oldID != targetID)) {
                    if (GetBodySize(oldID) == GetBodySize(targetID)) break;
                }
            }
            if ((r6 == 0x1e) || (entityInfo->id == targetID)) {
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD450);
            }
            else {
                CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[1], targetID);
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD434);
                sub_806BB6C(target, targetID);
                didTransfer = TRUE;
            }
        }
    }
    else {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD450);
    }
    return didTransfer;
}

bool8 SlowDownMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
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

bool8 PounceOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandlePounceOrbAction(pokemon, target, 8);
    return TRUE;
}

bool8 TrawlOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandleTrawlOrbAction(pokemon, target);
    return TRUE;
}

bool8 EscapeOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
    if (gDungeon->unk644.unk2A != 0) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD4DC); // $m0 can't escape!
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD4C4); // $m0 escaped!
        gDungeon->unk4 = 1;
        gDungeon->unk11 = 1;
    }
    return FALSE;
}

bool8 DroughtOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    HandleDroughtOrbAction(pokemon);
    return TRUE;
}

bool8 TrapbustOrbAction(Entity * pokemon,Entity * target, Move *move, s32 param_4)
{
    const Tile *tile;
    Entity *object;
    Trap *trapData;
    s32 bottomRightCornerX, bottomRightCornerY;
    s32 xCoord, yCoord;
    struct RoomData *room;
    s32 topLeftCornerX, topLeftCornerY;
    DungeonPos pos;
    bool8 foundTrap = FALSE;
    tile = GetTileAtEntitySafe(target);
    if (IsBossFight()) {
        LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FD1EC);
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
                object = GetTileMut(xCoord, yCoord)->object;
                if (((object != 0) && (GetEntityType(object) == ENTITY_TRAP)) &&
                    (trapData = GetTrapInfo(object), trapData->id != TRAP_WONDER_TILE)) {
                    pos.y = yCoord;
                    pos.x = xCoord;
                    sub_807FE04(&pos, 0);
                    foundTrap = TRUE;
                }
            }
        }
        if (foundTrap) {
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD1B0);
            UpdateMinimap();
            UpdateTrapsVisibility();
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD1CC);
        }
    }
    return foundTrap;
}

bool8 RollcallOrbAction(Entity * pokemon, Entity *target, Move *move, s32 param_4)
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
        if (((EntityIsValid(targetEntity)) && (pokemon != targetEntity)) &&
            (GetTreatmentBetweenMonsters(pokemon,targetEntity,TRUE,FALSE) == TREATMENT_TREAT_AS_ALLY)) {
            WarpTarget(pokemon,targetEntity,2,&pokemon->pos);
            foundTarget = TRUE;
        }
    }
    if (!foundTarget) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_81004F0);
    }
    return foundTarget;
}

bool8 InvisifyOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    InvisibleStatusTarget(pokemon, pokemon);
    return TRUE;
}

bool8 OneShotOrbAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
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

bool8 VacuumCutMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = sub_8055864(pokemon, target, move, gVacuumCutDmgValue, param_4) != 0 ? TRUE : FALSE;
    return flag;
}

bool8 ReviverOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD454);
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
    sub_8078A58(pokemon, target, gFamishBellyDownValue, 0);
    return TRUE;
}

bool8 OneRoomOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    HandleOneRoomOrb(pokemon, target);
    return TRUE;
}
