#include "global.h"
#include "globaldata.h"
#include "dungeon_item_action.h"
#include "dungeon_8041AD0.h"
#include "dungeon_message.h"
#include "dungeon_random.h"
#include "constants/dungeon_action.h"
#include "constants/dungeon.h"
#include "constants/dungeon_exit.h"
#include "constants/residual_damage.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_action.h"
#include "dungeon_items.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_vram.h"
#include "dungeon_util.h"
#include "move_orb_effects_1.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "structs/str_position.h"
#include "dungeon_config.h"
#include "dungeon_menu_team.h"
#include "dungeon_menu_moves.h"
#include "dungeon_misc.h"
#include "dungeon_tilemap.h"
#include "dungeon_data.h"
#include "dungeon_logic.h"
#include "dungeon_damage.h"
#include "dungeon_strings.h"
#include "dungeon_generation_fixed.h"
#include "dungeon_move.h"
#include "dungeon_leveling.h"
#include "warp_target.h"
#include "move_orb_actions_1.h"
#include "move_orb_effects_2.h"
#include "move_orb_effects_5.h"

static void StunSeedItemAction(Entity *, Entity *);
static void MaxElixirAction(Entity *, Entity *);
static void ProteinItemAction(Entity *, Entity *);
static void CalciumItemAction(Entity *, Entity *);
static void IronItemAction(Entity *, Entity *);
static void ZincItemAction(Entity *, Entity *);
static void sub_80487CC(Entity *, Entity *, u32, u32);
static void GrimyFoodItemAction(Entity *, Entity *);
static void HandleGummiItemAction(Entity *, Entity *, u8);
static void IcePartItemAction(Entity *, Entity *, u8);
static void SteelPartItemAction(Entity *, Entity *, u8);
static void RockPartItemAction(Entity *, Entity *, u8);
static void MusicBoxItemAction(Entity *, Entity *, u8);
static void nullsub_94(Entity *, Entity *, u8);
static void KeyItemAction(Entity *, Entity *, u8);
static void sub_8048340(Entity *, Entity *, u32);
static void HealSeedItemAction(Entity *, Entity *, u8);
static void WishStoneItemAction(Entity *, Entity *, u8);
static void OranBerryItemAction(Entity *, Entity *);
static void ChestoBerryItemAction(Entity *, Entity *);
static void JoySeedItemAction(Entity *, Entity *);
static void GinsengItemAction(Entity *, Entity *);
static void BlastSeedItemAction(Entity *, Entity *, u8);
static void SitrusBerryItemAction(Entity *, Entity *);
static void WarpSeedItemAction(Entity *, Entity *);
static void PlainSeedItemAction(Entity *, Entity *);
static void SleepSeedItemAction(Entity *, Entity *);
static void TotterSeedItemAction(Entity *, Entity *);
static void CheriBerryItemAction(Entity *, Entity *);
static void PechaBerryItemAction(Entity *, Entity *);
static void QuickSeedItemAction(Entity *, Entity *);
static void HungerSeedItemAction(Entity *, Entity *);
static void RawstBerryItemAction(Entity *, Entity *);
static void LifeSeedItemAction(Entity *, Entity *);
static void AllureSeedItemAction(Entity *, Entity *);
static void EyedropSeedItemAction(Entity *, Entity *);
static void BlinkerSeedItemAction(Entity *, Entity *);
static void DoomSeedItemAction(Entity *, Entity *);
static void sub_80482FC(Entity *, Entity *, u32, u8);

void sub_80479B8(bool8 param_1, bool8 param_2, u8 param_3, Entity *pokemon, Entity *target, Item *item)
{
    if (param_1) {
        if (!param_2) {
            bool8 flag = FALSE;
            EntityInfo *info = GetEntInfo(target);
            if (info->isNotTeamMember) {
                if (GetItemCategory(item->id) != CATEGORY_THROWN_LINE && GetItemCategory(item->id) != CATEGORY_BERRIES_SEEDS_VITAMINS) {
                    flag = (GetItemCategory(item->id) != CATEGORY_THROWN_ARC);
                }
            }
            else {
                if (GetItemCategory(item->id) != CATEGORY_BERRIES_SEEDS_VITAMINS) {
                    flag = IQSkillIsEnabled(target, IQ_ITEM_CATCHER);
                }
            }

            if (CheckVariousConditions(target)) {
                flag = FALSE;
            }

            if (flag && !ItemExists(&info->heldItem)) {
                if (info->shopkeeper == TRUE) {
                    SpawnDroppedItemWrapper(pokemon,&target->pos,item);
                }
                else {
                    PlaySoundEffect(0x14d);
                    sub_8045BF8(gFormatBuffer_Items[0],item);
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FDBB8); // $m0 caught the $i0
                    info->heldItem = *item;
                    sub_806A6E8(target);
                }
                return;
            }
        }
    }

    if (param_1) {
        sub_8042390(target,item);
        SetShopkeeperAggression(pokemon,target);
    }

    if (item->flags & ITEM_FLAG_STICKY) {
        sub_8045BF8(gFormatBuffer_Items[0],item);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gItemStickyDoesntWorkText);
        if (param_1) {
            u8 uStack_24;
            sub_806F370(pokemon,target,gUnknown_80F4FAE,1,&uStack_24,0,DUNGEON_EXIT_FELLED_BY_THROWN_ITEM,RESIDUAL_DAMAGE_REGULAR,0,0);
            EnemyEvolution(pokemon);
            return;
        }
    }

    if (!param_1)
        sub_804245C(target,item);

    if (GetItemCategory(item->id) == CATEGORY_BERRIES_SEEDS_VITAMINS) {
        sub_8078B5C(pokemon,target,5,0,0);
    }

    if (GetItemCategory(item->id) == CATEGORY_TMS_HMS || GetItemCategory(item->id) == CATEGORY_LINK_BOX) {
        if (param_1) {
            u8 uStack_23;
            sub_806F370(pokemon,target,gUnknown_80F4FAC,1,&uStack_23,0,DUNGEON_EXIT_FELLED_BY_THROWN_ITEM,RESIDUAL_DAMAGE_REGULAR,0,0);
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE458);
        }
    }
    else {
        switch (item->id) {
            case ITEM_STICK:
                sub_80482FC(pokemon,target,gStickPPValue,ITEM_STICK);
                break;
            case ITEM_IRON_THORN:
                sub_80482FC(pokemon,target,gIronThornPPValue,ITEM_IRON_THORN);
                break;
            case ITEM_SILVER_SPIKE:
                sub_80482FC(pokemon,target,gSilverSpikePPValue,ITEM_SILVER_SPIKE);
                break;
            case ITEM_GOLD_FANG:
                sub_80482FC(pokemon,target,gGoldFangPPValue,ITEM_GOLD_FANG);
                break;
            case ITEM_CACNEA_SPIKE:
                sub_80482FC(pokemon,target,gCacneaSpikePPValue,ITEM_CACNEA_SPIKE);
                break;
            case ITEM_CORSOLA_TWIG:
                sub_80482FC(pokemon,target,gCorsolaTwigPPValue,ITEM_CORSOLA_TWIG);
                break;
            case ITEM_GEO_PEBBLE:
                sub_8048340(pokemon,target,gGeoPebbleThrownDmgValue);
                break;
            case ITEM_GRAVELEROCK:
                sub_8048340(pokemon,target,gGravelerockThrownDmgValue);
                break;
            case ITEM_HEAL_SEED:
                HealSeedItemAction(pokemon,target,param_3);
                break;
            case ITEM_ORAN_BERRY:
                OranBerryItemAction(pokemon,target);
                break;
            case ITEM_SITRUS_BERRY:
                SitrusBerryItemAction(pokemon,target);
                break;
            case ITEM_LIFE_SEED:
                LifeSeedItemAction(pokemon,target);
                break;
            case ITEM_BLINKER_SEED:
                BlinkerSeedItemAction(pokemon,target);
                break;
            case ITEM_ALLURE_SEED:
                AllureSeedItemAction(pokemon,target);
                break;
            case ITEM_QUICK_SEED:
                QuickSeedItemAction(pokemon,target);
                break;
            case ITEM_EYEDROP_SEED:
                EyedropSeedItemAction(pokemon,target);
                break;
            case ITEM_TOTTER_SEED:
                TotterSeedItemAction(pokemon,target);
                break;
            case ITEM_CHERI_BERRY:
                CheriBerryItemAction(pokemon,target);
                break;
            case ITEM_PECHA_BERRY:
                PechaBerryItemAction(pokemon,target);
                break;
            case ITEM_WARP_SEED:
                WarpSeedItemAction(pokemon,target);
                break;
            case ITEM_SLEEP_SEED:
                SleepSeedItemAction(pokemon,target);
                break;
            case ITEM_CHESTO_BERRY:
                ChestoBerryItemAction(pokemon,target);
                break;
            case ITEM_JOY_SEED:
                JoySeedItemAction(pokemon,target);
                break;
            case ITEM_DOOM_SEED:
                DoomSeedItemAction(pokemon,target);
                break;
             case ITEM_STUN_SEED:
                StunSeedItemAction(pokemon,target);
                break;
            case ITEM_PLAIN_SEED:
                PlainSeedItemAction(pokemon,target);
                break;
            case ITEM_RAWST_BERRY:
                RawstBerryItemAction(pokemon,target);
                break;
            case ITEM_HUNGER_SEED:
                HungerSeedItemAction(pokemon,target);
                break;
            case ITEM_GINSENG:
                GinsengItemAction(pokemon,target);
                break;
            case ITEM_BLAST_SEED:
                BlastSeedItemAction(pokemon,target,param_1);
                break;
            case ITEM_MAX_ELIXIR:
                MaxElixirAction(pokemon,target);
                break;
            case ITEM_PROTEIN:
                ProteinItemAction(pokemon,target);
                break;
            case ITEM_CALCIUM:
                CalciumItemAction(pokemon,target);
                break;
            case ITEM_IRON:
                IronItemAction(pokemon,target);
                break;
            case ITEM_ZINC:
                ZincItemAction(pokemon,target);
                break;
            case ITEM_SWITCH_BOX:
                nullsub_94(pokemon,target,param_1);
                break;
            case ITEM_BIG_APPLE:
                sub_80487CC(pokemon,target,100,10);
                break;
            case ITEM_HUGE_APPLE:
                sub_80487CC(pokemon,target,999,10);
                break;
            case ITEM_GRIMY_FOOD:
                GrimyFoodItemAction(pokemon,target);
                break;
            case ITEM_WHITE_GUMMI:
                HandleGummiItemAction(pokemon,target,1);
                break;
            case ITEM_RED_GUMMI:
                HandleGummiItemAction(pokemon,target,2);
                break;
            case ITEM_BLUE_GUMMI:
                HandleGummiItemAction(pokemon,target,3);
                break;
            case ITEM_GRASS_GUMMI:
                HandleGummiItemAction(pokemon,target,4);
                break;
            case ITEM_YELLOW_GUMMI:
                HandleGummiItemAction(pokemon,target,5);
                break;
            case ITEM_CLEAR_GUMMI:
                HandleGummiItemAction(pokemon,target,6);
                break;
            case ITEM_ORANGE_GUMMI:
                HandleGummiItemAction(pokemon,target,7);
                break;
            case ITEM_PINK_GUMMI:
                HandleGummiItemAction(pokemon,target,8);
                break;
            case ITEM_BROWN_GUMMI:
                HandleGummiItemAction(pokemon,target,9);
                break;
            case ITEM_SKY_GUMMI:
                HandleGummiItemAction(pokemon,target,10);
                break;
            case ITEM_GOLD_GUMMI:
                HandleGummiItemAction(pokemon,target,0xb);
                break;
            case ITEM_GREEN_GUMMI:
                HandleGummiItemAction(pokemon,target,0xc);
                break;
            case ITEM_GRAY_GUMMI:
                HandleGummiItemAction(pokemon,target,0xd);
                break;
            case ITEM_PURPLE_GUMMI:
                HandleGummiItemAction(pokemon,target,0xe);
                break;
            case ITEM_ROYAL_GUMMI:
                HandleGummiItemAction(pokemon,target,0xf);
                break;
            case ITEM_BLACK_GUMMI:
                HandleGummiItemAction(pokemon,target,0x10);
                break;
            case ITEM_SILVER_GUMMI:
                HandleGummiItemAction(pokemon,target,0x11);
                break;
            case ITEM_APPLE:
            case ITEM_BANANA:
                sub_80487CC(pokemon,target,0x32,5);
                break;
            case ITEM_CHESTNUT:
                sub_80487CC(pokemon,target,10,0);
                break;
            case ITEM_KEY:
                KeyItemAction(pokemon,target,param_1);
                break;
            case ITEM_ICE_PART:
                IcePartItemAction(pokemon,target,param_1);
                break;
            case ITEM_ROCK_PART:
                RockPartItemAction(pokemon,target,param_1);
                break;
            case ITEM_STEEL_PART:
                SteelPartItemAction(pokemon,target,param_1);
                break;
            case ITEM_WISH_STONE:
                WishStoneItemAction(pokemon,target,param_1);
                break;
            case ITEM_MUSIC_BOX:
                MusicBoxItemAction(pokemon,target,param_1);
                break;
            default:
                if (param_1) {
                    u8 auStack_22;
                    sub_806F370(pokemon,target,gUnknown_80F4FAC,1,&auStack_22,0,DUNGEON_EXIT_FELLED_BY_THROWN_ITEM,RESIDUAL_DAMAGE_REGULAR,0,0);
                }
                else {
                    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE458);
                }
                break;
        }
    }

    EnemyEvolution(pokemon);
}

UNUSED static void nullsub_205(void) { }

static void SleepSeedItemAction(Entity *pokemon, Entity *target)
{
    SleepStatusTarget(pokemon, target, CalculateStatusTurns(target, gSleepTurnRange, TRUE), TRUE);
}

static void sub_80482FC(Entity *pokemon, Entity *target, u32 pp, u8 param_4)
{
    Move move;

    InitPokemonMove(&move, MOVE_PROJECTILE);
    move.PP = pp;
    HandleDamagingMove(pokemon, target, &move, IntToF248_2(1.0), param_4);
}

static void sub_8048340(Entity *pokemon, Entity *target, u32 r2)
{
    sub_806F370(pokemon, target, r2, 1, 0, 0, DUNGEON_EXIT_FELLED_BY_THROWN_ROCK, RESIDUAL_DAMAGE_REGULAR, 0, 0);
}

static void HealSeedItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    sub_8079F20(pokemon, target, 1, r2);
}

static void OranBerryItemAction(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, gOranBerryHealValue, gOranBerryMaxHpRiseValue, TRUE);
}

static void SitrusBerryItemAction(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, gSitrusBerryHealValue, gSitrusBerryMaxHpRiseValue, TRUE);
}

static void MaxElixirAction(Entity *pokemon, Entity *target)
{
    RestorePPTarget(pokemon, target, 999);
}

static void LifeSeedItemAction(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, 0, gLifeSeedMaxHpRiseValue, TRUE);
}

static void BlinkerSeedItemAction(Entity *pokemon, Entity *target)
{
    BlindTarget(pokemon, target);
}

static void AllureSeedItemAction(Entity *pokemon, Entity *target)
{
    CrossEyeVisionTarget(pokemon, target);
}

static void QuickSeedItemAction(Entity *pokemon, Entity *target)
{
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
}

static void EyedropSeedItemAction(Entity *pokemon, Entity *target)
{
    RestoreVisionTarget(pokemon, target);
}

static void CheriBerryItemAction(Entity *pokemon, Entity *target)
{
    if(GetEntInfo(target)->burnClassStatus.status == STATUS_PARALYSIS)
        EndBurnClassStatus(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F89F4);
}

static void PechaBerryItemAction(Entity *pokemon, Entity *target)
{
    EntityInfo *entInfo = GetEntInfo(target);
    if (ENTITY_POISONED(entInfo))
        EndBurnClassStatus(pokemon, target);
    else
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F89F4); // Pointer to "But nothing happened!"
}

static void WarpSeedItemAction(Entity *pokemon, Entity *target)
{
    WarpTarget(pokemon, target, 0, NULL);
}

static void ChestoBerryItemAction(Entity *pokemon, Entity *target)
{
    SleeplessStatusTarget(pokemon, target);
}

static void TotterSeedItemAction(Entity *pokemon, Entity *target)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
}

static void JoySeedItemAction(Entity *pokemon, Entity *target)
{
    LevelUpTarget(pokemon, target, 1, 1, 1);
}

static void StunSeedItemAction(Entity *pokemon, Entity *target)
{
    PetrifiedStatusTarget(pokemon, target);
}

static void PlainSeedItemAction(Entity *pokemon, Entity *target)
{
    // Pointer to "But nothing happened!"
    TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F89F4);
}

static void DoomSeedItemAction(Entity *pokemon, Entity *target)
{
    LevelDownTarget(pokemon, target, 1);
}

static void RawstBerryItemAction(Entity *pokemon, Entity *target)
{
    if(GetEntInfo(target)->burnClassStatus.status == STATUS_BURN)
        EndBurnClassStatus(pokemon, target);
    else
    {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
        // Pointer to "But nothing happened!"
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FB580);
    }
}

static void HungerSeedItemAction(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo = GetEntInfo(target);
  if (GetEntInfo(target)->isTeamLeader)
    sub_8078A58(pokemon, target, 0, 5);
  else
  {
    entityInfo = GetEntInfo(target);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
    if (IQSkillIsEnabled(target, IQ_SELF_CURER))
        TryDisplayDungeonLoggableMessage3(pokemon, target, gPtrSelfHealPreventedHungerMessage);
    else
    {
      if (FixedPointToInt(entityInfo->belly) != 0) {
        entityInfo->belly = IntToFixedPoint(0);
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F9740);
      }
      else
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80F9760);
    }
  }
}

static void GinsengItemAction(Entity *pokemon, Entity * target)
{
    s32 i;
    bool8 isMoveBoosted = FALSE;
    s32 moveBoost = 1;
    EntityInfo *entityInfo = GetEntInfo(target);

    if (DungeonRandInt(100) < gGinsengPlus3BoostChance) {
        moveBoost = 3;
    }

    if (entityInfo->isTeamLeader) {
        for (i = 0; i < MAX_MON_MOVES; i++) {
            Move *move = &entityInfo->moves.moves[i];
            if(MoveFlagExists(move) && (move->moveFlags & MOVE_FLAG_SET)) {
                if (GetMoveBasePower(move) != 0) {
                    s32 movePowerBoost = move->ginseng;
                    s32 maxPowerBoost = GetMoveMaxUpgradeLevel(move);

                    move->ginseng += moveBoost;
                    if (move->ginseng >= maxPowerBoost) {
                        move->ginseng = maxPowerBoost;
                    }
                    if (movePowerBoost != move->ginseng) {
                        isMoveBoosted = TRUE;
                    }
                }
            }
        }

        if (isMoveBoosted) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE454);
            if (moveBoost != 1) {
                sub_803E708(10,0x40);
                TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE434);
            }
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE40C);
        }
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FE40C);
    }
}

static void BlastSeedItemAction(Entity *pokemon, Entity * target, u8 param_3)
{
  s32 dmg;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo_1;
  Entity *entity;
  u8 auStack28 [4];

  if (param_3 != 0) {
    entityInfo = GetEntInfo(target);
    entityInfo_1 = entityInfo;
    if (gDungeon->unk644.unk31 != 0) {
        dmg = gBlastSeedThrownBossDmgValue;
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FEAE8); // It appears to be weak here...
    }
    else {
        dmg = gBlastSeedThrownDmgValue;
    }
    if (entityInfo_1->frozenClassStatus.status == STATUS_FROZEN) {
      EndFrozenClassStatus(pokemon, target);
    }
    sub_806F370(pokemon, target, dmg, 1, auStack28, 0, DUNGEON_EXIT_DEFEATED_BLAST_SEED, RESIDUAL_DAMAGE_REGULAR, 0, 0);
  }
  else
  {
    sub_8042520(pokemon);
    entity = sub_80696FC(pokemon);
    if (entity == NULL)
    {
      TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FDBA0);
    }
    else
    {
      entityInfo = GetEntInfo(entity);
      if (gDungeon->unk644.unk31 != 0) {
        dmg = gBlastSeedEatenBossDmgValue;
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FEAE8); // It appears to be weak here...
      }
      else {
        dmg = gBlastSeedEatenDmgValue;
      }
      if (entityInfo->frozenClassStatus.status == STATUS_FROZEN) {
        EndFrozenClassStatus(pokemon, entity);
      }
      sub_806F370(pokemon, entity, dmg, 1, auStack28, 0, DUNGEON_EXIT_DEFEATED_BLAST_SEED, RESIDUAL_DAMAGE_REGULAR, 0, 0);
    }
  }
}

static void sub_80487CC(Entity *pokemon, Entity * target, u32 param_3, u32 param_4)
{
    sub_8078B5C(pokemon, target, param_3, param_4, 1);
}

static void HandleGummiItemAction(Entity *pokemon, Entity *target, u8 gummiIndex)
{
  s32 iVar3;
  EntityInfo *targetInfo;
  s32 gummiBoost;
  s32 baseIQ;
  s32 iVar4;
  s32 iVar5;
  s32 currIQ;

  targetInfo = GetEntInfo(target);
  gummiBoost = gTypeGummiIQBoost[targetInfo->types[0]][gummiIndex];
  gummiBoost += gTypeGummiIQBoost[targetInfo->types[1]][gummiIndex];
  sub_8078B5C(pokemon,target,
             gUnknown_810A808[targetInfo->types[0]][gummiIndex] +
             gUnknown_810A808[targetInfo->types[1]][gummiIndex],0,1);
  if (!targetInfo->isNotTeamMember) {
    if (!IsExperienceLocked(targetInfo->joinedAt.id)) {
      baseIQ = targetInfo->IQ;
      targetInfo->IQ += gummiBoost;
      currIQ = baseIQ + gummiBoost;
      if (targetInfo->IQ <= 0) {
        targetInfo->IQ = 1;
      }
      if (999 < targetInfo->IQ) {
        targetInfo->IQ = 999;
      }
      if (baseIQ == targetInfo->IQ) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD644);
      }
      else {
        iVar5 = currIQ - baseIQ;
        iVar4 = 0;
        if (((iVar5 < 9) && (iVar4 = 1, iVar5 < 5)) && (iVar4 = 3, 2 < iVar5)) {
          iVar4 = 2;
        }
        iVar5 = targetInfo->IQ - baseIQ;
        iVar3 = 0;
        if (((iVar5 < 9) && (iVar3 = 1, iVar5 < 5)) && (iVar3 = 3, 2 < iVar5)) {
          iVar3 = 2;
        }
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD648[iVar4]);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD6E8[iVar3]);
        LoadIQSkills(target);
        DisplayMsgIfNewIqSkillLearned(targetInfo,baseIQ);
      }
    }
  }
}

static void ProteinItemAction(Entity *pokemon, Entity *target)
{
    RaiseAtkStatTarget(pokemon, target, 3);
}

static void CalciumItemAction(Entity *pokemon, Entity *target)
{
    RaiseSpAtkStatTarget(pokemon, target, 3);
}

static void IronItemAction(Entity *pokemon, Entity *target)
{
    RaiseDefStatTarget(pokemon, target, 3);
}

static void ZincItemAction(Entity *pokemon, Entity *target)
{
    RaiseSpDefStatTarget(pokemon, target, 3);
}

static void nullsub_94(Entity *pokemon, Entity *target, u8 r2)
{}

bool8 sub_8048950(Entity *param_1,Item *item)
{
    u8 flag;
    u16 moveID;
    Entity *entity2;
    Entity *entity;
    EntityInfo *entityInfo;
    int index;

    moveID = GetItemMoveID(item->id);
    if ((item->flags & ITEM_FLAG_STICKY)) {
        DisplayDungeonMessage(0,gItemStickyDoesntWorkText,1);
        return FALSE;
    }
    else if (IsHMItem(item->id)) {
        DisplayDungeonMessage(0,gPtrCantUseInDungeonMessage,1);
        return FALSE;
    }
    else
    {
        for(index = 0; index < MAX_TEAM_MEMBERS; index++)
        {
            entity = gDungeon->teamPokemon[index];
            if (EntityIsValid(entity)) {
                entityInfo = GetEntInfo(entity);
                flag = CanMonLearnMove(moveID, entityInfo->id);
                if (CheckVariousStatuses2(entity, FALSE)) {
                    flag = FALSE;
                }
                if (entityInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET) {
                    flag = FALSE;
                }
                if (IsExperienceLocked(entityInfo->joinedAt.id)) {
                    flag = FALSE;
                }
                entityInfo->unk157 = flag;
            }
        }
        entity2 = ShowDungeonToWhichMonMenu(NULL,WHICH_MENU_MOVES);
        if (!EntityIsValid(entity2)) {
            return FALSE;
        }
        sub_804245C(param_1,item);
        if (sub_8072938(entity2,moveID) == 0) {
            return FALSE;
        }
        sub_8044E24(param_1,0,0x141);
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8048A68(Entity *param_1,Item *item)
{
  u8 flag;
  Entity *entity2;
  Entity *entity;
  EntityInfo *pEVar6;
  s32 index;
  DungeonMon *pokemon;

  if ((item->flags & ITEM_FLAG_STICKY)) {
    DisplayDungeonMessage(0,gItemStickyDoesntWorkText,1);
    return FALSE;
  }
  else
  {
    if (gDungeon->unk644.unk18 == 0) {
        DisplayDungeonMessage(0,gUnknown_80F9BD8,1);
        return FALSE;
    }
    else
    {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeon->teamPokemon[index];
        if (EntityIsValid(entity)) {
          pEVar6 = GetEntInfo(entity);
          flag = TRUE;
          if(((MAX_TEAM_MEMBERS - 1) < pEVar6->teamIndex))
             flag =  FALSE;
          else
          {
             pokemon = &gRecruitedPokemonRef->dungeonTeam[pEVar6->teamIndex];
             if (sub_806A538(pokemon->recruitedPokemonId))
                 flag =  FALSE;
          }

          if (CheckVariousStatuses2(entity, FALSE)) {
            flag = FALSE;
          }
          if (pEVar6->monsterBehavior == BEHAVIOR_RESCUE_TARGET) {
            flag = FALSE;
          }
          if (IsExperienceLocked(pEVar6->joinedAt.id)) {
            flag = FALSE;
          }
          if (pEVar6->isTeamLeader) {
            flag = FALSE;
          }
          pEVar6->unk157 = flag;
        }
      }
      entity2 = ShowDungeonToWhichMonMenu(NULL,WHICH_MENU_MOVES);
      if (!EntityIsValid(entity2)) {
        return FALSE;
      }
      sub_804245C(param_1,item);
      gDungeon->unkBC = entity2;
      sub_8044E24(param_1,0,0x142);
      return TRUE;
    }
  }
  return FALSE;
}

bool8 HandleLinkBoxAction(Entity *entity, Item *item)
{
    s32 i;
    Entity *entity2;
    bool8 ret = FALSE;
    ActionContainer *entityActionPtr = &GetEntInfo(entity)->action;
    ActionContainer originalAction;

    if (ItemSticky(item)) {
        DisplayDungeonMessage(0,gItemStickyDoesntWorkText,1);
        return FALSE;
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityIsValid(teamMon)) {
            EntityInfo *teamMonInfo = GetEntInfo(teamMon);
            bool8 flag = TRUE;
            if (CheckVariousStatuses2(teamMon, FALSE)){
                flag = FALSE;
            }
            if (teamMonInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET) {
                flag = FALSE;
            }
            if (IsExperienceLocked(teamMonInfo->joinedAt.id)) {
                flag = FALSE;
            }
            teamMonInfo->unk157 = flag;
        }
    }

    entity2 = ShowDungeonToWhichMonMenu(NULL,WHICH_MENU_MOVES);
    if (!EntityIsValid(entity2)) {
        return FALSE;
    }

    originalAction = *entityActionPtr;
    while (1) {
        ClearMonsterActionFields(entityActionPtr);
        if (ShowDungeonMovesMenu(entity2,1,0,0,1)) {
            if (!ret)
                break;
            if (DisplayDungeonYesNoMessage(0,gUnknown_80FECA0,1) == 1)
                break;
        }

        if (entityActionPtr->action == ACTION_MOVE_INFO) {
            ActionShowMoveInfo(entityActionPtr);
        }
        else if (entityActionPtr->action == ACTION_LINK_MOVES) {
            sub_803EAF0(0, NULL);
            ActionLinkMoves(entityActionPtr);
            SetLeaderActionToNothing(TRUE);
            ret = TRUE;
        }
        else if (entityActionPtr->action == ACTION_DELINK_MOVES) {
            sub_803EAF0(0, NULL);
            ActionDelinkMoves(entityActionPtr,0);
            SetLeaderActionToNothing(TRUE);
        }
        else if ((entityActionPtr->action == ACTION_SET_MOVE) || (entityActionPtr->action == ACTION_UNSET_MOVE)) {
            sub_803EAF0(0, NULL);
            ActionSetOrUnsetMove(entityActionPtr, FALSE);
        }
        else if (entityActionPtr->action == ACTION_SWITCH_AI_MOVE) {
            sub_803EAF0(0, NULL);
            ActionToggleMoveUsableForAi(entityActionPtr);
        }
    }

    if (ret) {
        *entityActionPtr = originalAction;
        sub_8044DF0(entity,0,0x6e);
        SetMonsterActionFields(entityActionPtr,ACTION_USE_LINK_BOX);
    }
    else {
        SetLeaderActionToNothing(TRUE);
    }

    return ret;
}

bool8 sub_8048D50(Entity *pokemon, Item *item)
{
  EntityInfo *entityInfo = GetEntInfo(pokemon);

  if ((item->flags & ITEM_FLAG_STICKY) != 0) {
    sub_8045BF8(gFormatBuffer_Items[0], item);
    LogMessageByIdWithPopupCheckUser(pokemon,gItemStickyDoesntWorkText);
    return FALSE;
  }
  else
  {
    if ((entityInfo->muzzled.muzzled == TRUE) && (IsEdibleItem(item->id))) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],pokemon,0);
        LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FDCA4);
        return FALSE;
    }
  }
  return TRUE;
}

static void KeyItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    u8 temp;
    if(r2 != 0)
        sub_806F370(pokemon, target, gUnknown_80F4FAC, 1, &temp, 0, DUNGEON_EXIT_FELLED_BY_THROWN_ITEM, RESIDUAL_DAMAGE_REGULAR, 0, 0);
    else
        sub_8051E7C(pokemon);
}

static void GrimyFoodItemAction(Entity *pokemon, Entity * target)
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
            LowerAttackStageTarget(pokemon, target, gStatIndexAtkDef, 3, 1, TRUE);
            LowerAttackStageTarget(pokemon, target, gStatIndexSpecial, 3, 1, TRUE);
            break;
    }
}

static void IcePartItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    LogMessageByIdWithPopupCheckUser(pokemon, gPtrIcePartCrumbledMessage);
}

static void RockPartItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    LogMessageByIdWithPopupCheckUser(pokemon, gPtrRockPartCrumbledMessage);
}

static void SteelPartItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    LogMessageByIdWithPopupCheckUser(pokemon, gPtrSteelPartCrumbledMessage);
}

static void WishStoneItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    LogMessageByIdWithPopupCheckUser(pokemon, gPtrWishStoneCrumbledMessage);
}

static void MusicBoxItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    sub_80421C0(pokemon, 0xD6);
    LogMessageByIdWithPopupCheckUser(pokemon, gPtrMusicBoxPlayedCrumbledMessage);
    sub_803E708(0x3C, 0x46);
}
